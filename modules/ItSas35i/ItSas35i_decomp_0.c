
===== AllocateDefaultHTB @ 140001000 =====

ulonglong AllocateDefaultHTB(longlong param_1,byte param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  ulonglong in_RAX;
  longlong lVar3;
  ulonglong uVar4;
  ushort uVar5;
  ushort uVar6;
  byte bVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  longlong *plVar12;
  undefined1 local_58 [8];
  longlong local_50;
  longlong local_48;
  
  uVar5 = *(ushort *)(param_1 + 0xb9ec);
  local_50 = 0;
  if (uVar5 != 0) {
    bVar7 = *(byte *)(param_1 + 0xb9e9);
    uVar6 = 0;
    if (*(ushort *)(param_1 + 0xb9ee) <= uVar5) {
      uVar6 = *(ushort *)(param_1 + 0xb9ee);
    }
    if (bVar7 == 0) {
      bVar7 = (char)uVar5 - (char)uVar6;
    }
    while( true ) {
      plVar12 = &local_50;
      uVar11 = 0x80000000;
      local_48 = (ulonglong)uVar5 << 10;
      uVar10 = 1;
      uVar1 = (undefined4)local_48;
      uVar9 = 0x100000000;
      uVar8 = 0xffffffff;
      iVar2 = StorPortExtendedFunction
                        (0x18,param_1,local_48,0,0xffffffffffffffff,0x100000000,1,0x80000000,plVar12
                        );
      if ((iVar2 == 0) && (local_50 != 0)) goto LAB_14000110e;
      if ((uVar6 == 0) || ((int)((uint)uVar5 - (uint)bVar7) < (int)(uint)uVar6)) break;
      uVar5 = uVar5 - bVar7;
    }
    if ((iVar2 == 0) && (local_50 != 0)) {
LAB_14000110e:
      lVar3 = StorPortGetPhysicalAddress(param_1,0,local_50,local_58);
      if (lVar3 != 0) {
        *(longlong *)(param_1 + 0x16e0) = local_50;
        *(undefined2 *)(param_1 + 0x16ef) = 0x101;
        *(undefined1 *)(param_1 + 0x16ec) = 0;
        *(undefined4 *)(param_1 + 0x16e8) = uVar1;
        *(undefined4 *)(param_1 + 0x16f4) = 0x4252434d;
        LogSystemEvent(param_1,uVar1,0x4004af00,
                       (byte *)"Default HTB allocation succeeded,allocated buffer size logged.",
                       param_2,param_3);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x11b) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x11b,
                      (undefined1 *)0x0,0,param_2,param_3);
        }
        *(undefined1 *)(param_1 + 0xbbc6) = 1;
        uVar4 = FwDiagPostImmediateBuffers(param_1,param_2,param_3);
        if ((char)uVar4 == '\0') {
          uVar9 = LogSystemEvent(param_1,0xad01002a,0x8004af01,
                                 (byte *)
                                 "Diag buffer post to FW failed or not posted during Driver Init.",
                                 param_2,param_3);
          return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
        }
        uVar9 = LogSystemEvent(param_1,*(undefined4 *)(param_1 + 0x16e8),0x4004af00,
                               (byte *)
                               "HTB post to FW is successful during Driver Init,buffer size logged."
                               ,param_2,param_3);
        *(uint *)(param_1 + 0xb69c) = *(uint *)(param_1 + 0xb69c) | 3;
        *(undefined1 *)(param_1 + 0xb698) = 1;
        return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
      }
      in_RAX = StorPortExtendedFunction
                         (0x19,param_1,local_50,local_48,CONCAT44(uVar8,1),uVar9,uVar10,uVar11,
                          plVar12);
      if ((((int)in_RAX != 0) &&
          (in_RAX = LogSystemEvent(param_1,0,0x8004af01,
                                   (byte *)
                                   "Error in freeing allocated default HTB in AllocateDefaultHTB",
                                   param_2,param_3), *(char *)(param_1 + 0x608) != '\0')) &&
         ((*(uint *)(param_1 + 0x60c) & 0x279) != 0)) {
        in_RAX = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x279
                             ,(undefined1 *)0x0,0,param_2,param_3);
      }
    }
    else {
      in_RAX = LogSystemEvent(param_1,0,0x4004af00,(byte *)"Default HTB allocation fails",param_2,
                              param_3);
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x277) != 0)) {
        in_RAX = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x277
                             ,(undefined1 *)0x0,0,param_2,param_3);
      }
      *(undefined1 *)(param_1 + 0xbbc6) = 0;
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== BuildIeeeScatterGather @ 140001350 =====

void BuildIeeeScatterGather
               (longlong param_1,longlong param_2,int param_3,longlong param_4,int param_5)

{
  uint *puVar1;
  undefined1 uVar2;
  ushort uVar3;
  longlong lVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  uint *puVar19;
  uint uVar20;
  int iVar21;
  int local_res8;
  
  lVar4 = *(longlong *)(param_2 + 0x68);
  iVar21 = 0;
  uVar10 = 0;
  local_res8 = 0;
  uVar20 = param_5 + (uint)*(ushort *)(param_1 + 0x534);
  puVar18 = (uint *)(param_4 + (ulonglong)*(ushort *)(param_1 + 0x534));
  uVar17 = 0x1000000;
  if ((*(uint *)(param_2 + 0x18) & 0x80) == 0) {
    uVar17 = 0x2000000;
  }
  *(uint *)(param_4 + 0x3c) = *(uint *)(param_4 + 0x3c) | uVar17;
  uVar2 = *(undefined1 *)(param_1 + 0x220);
  puVar19 = *(uint **)(lVar4 + 0x30);
  uVar13 = param_3 - *(int *)(param_2 + 0x40);
  uVar3 = *(ushort *)(param_1 + 0x52c);
  uVar11 = (uint)uVar3;
  puVar1 = (uint *)(param_4 + 0x60);
  uVar17 = *puVar19;
  puVar14 = puVar19 + 4;
  if (uVar13 != 0) {
    uVar16 = puVar19[6];
    if (uVar16 <= uVar13) {
      do {
        puVar19 = puVar14 + 6;
        uVar13 = uVar13 - uVar16;
        uVar17 = uVar17 - 1;
        uVar16 = puVar14[8];
        puVar14 = puVar19;
      } while (uVar16 <= uVar13);
    }
    uVar16 = *(uint *)(param_2 + 0x3c);
    uVar15 = 0;
    puVar19 = puVar14;
    if (uVar17 != 0) {
      do {
        uVar8 = puVar19[2] - uVar13;
        if (puVar19 != puVar14) {
          uVar8 = puVar19[2];
        }
        uVar7 = uVar16;
        iVar5 = uVar8 - uVar16;
        if (uVar8 <= uVar16) {
          uVar7 = uVar8;
          iVar5 = iVar21;
        }
        iVar21 = iVar5;
        uVar16 = uVar16 - uVar7;
        if (uVar16 == 0) break;
        uVar15 = uVar15 + 1;
        puVar19 = puVar19 + 6;
      } while (uVar15 < uVar17);
      local_res8 = iVar21;
    }
    uVar17 = uVar15 + 1;
  }
  puVar19 = puVar1;
  puVar12 = (uint *)0x0;
  uVar16 = (uint)uVar3;
  if (uVar17 <= uVar3 + 1) {
    uVar16 = uVar17;
  }
  while( true ) {
    puVar6 = puVar19;
    uVar15 = 0;
    if (uVar16 != 0) {
      uVar9 = (ulonglong)uVar16;
      do {
        *puVar6 = *puVar14;
        puVar6[1] = puVar14[1];
        puVar19 = puVar14 + 2;
        puVar14 = puVar14 + 6;
        puVar6[2] = *puVar19;
        puVar6[3] = 0;
        puVar6 = puVar6 + 4;
        uVar9 = uVar9 - 1;
        uVar15 = uVar16;
      } while (uVar9 != 0);
    }
    uVar10 = uVar10 + uVar15;
    if (uVar17 <= uVar10) break;
    if (uVar10 == uVar11) {
      *(undefined1 *)(param_4 + 2) = uVar2;
      uVar11 = (uint)*(ushort *)(param_1 + 0x52e);
    }
    puVar19 = puVar18;
    if (puVar12 != (uint *)0x0) {
      *(char *)((longlong)puVar12 + 0xe) = (char)uVar15;
      puVar12[2] = (uVar15 + 1) * 0x10;
      puVar19 = (uint *)((longlong)puVar18 + (ulonglong)*(ushort *)(param_1 + 0x530));
      uVar20 = uVar20 + *(ushort *)(param_1 + 0x530);
    }
    *puVar6 = uVar20;
    puVar6[1] = *(uint *)(param_1 + 500);
    puVar6[3] = 0x80000000;
    puVar12 = puVar6;
    puVar18 = puVar19;
    uVar16 = uVar17 - uVar10;
    if (uVar11 + 1 < uVar17 - uVar10) {
      uVar16 = uVar11;
    }
  }
  puVar6[-1] = puVar6[-1] | 0x40000000;
  if (local_res8 != 0) {
    puVar6[-2] = puVar6[-2] - local_res8;
  }
  if (puVar12 != (uint *)0x0) {
    puVar12[2] = (uint)(byte)((char)uVar15 << 4);
    *(undefined1 *)((longlong)puVar12 + 0xe) = 0;
  }
  if (uVar13 != 0) {
    *puVar1 = *puVar1 + uVar13;
    *(int *)(param_4 + 0x68) = *(int *)(param_4 + 0x68) - uVar13;
  }
  return;
}



===== BuildScatterGather @ 140001580 =====

void BuildScatterGather(longlong param_1,longlong param_2,uint *param_3,int param_4,longlong param_5
                       ,int param_6)

{
  undefined1 uVar1;
  ushort uVar2;
  longlong lVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte bVar14;
  uint *puVar15;
  uint uVar16;
  ulonglong uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint *puVar21;
  int local_68;
  uint *local_60;
  
  uVar11 = 0;
  uVar13 = param_6 + (uint)*(ushort *)(param_1 + 0x534);
  lVar3 = *(longlong *)(param_2 + 0x68);
  local_68 = 0;
  local_60 = (uint *)(param_5 + (ulonglong)*(ushort *)(param_1 + 0x534));
  bVar14 = *(byte *)(param_1 + 0x542);
  uVar7 = *(uint *)(param_2 + 0x18) & 0x80;
  uVar19 = 0x14;
  if (uVar7 == 0) {
    uVar19 = 0x10;
  }
  uVar10 = 0x1000000;
  if (uVar7 == 0) {
    uVar10 = 0x2000000;
  }
  *(uint *)(param_5 + 0x3c) = *(uint *)(param_5 + 0x3c) | uVar10;
  uVar2 = *(ushort *)(param_1 + 0x528);
  uVar7 = (uint)uVar2;
  bVar14 = bVar14 & 1;
  if (bVar14 != 0) {
    uVar19 = uVar19 | 2;
  }
  uVar20 = bVar14 + 2;
  uVar1 = *(undefined1 *)(param_1 + 0x21c);
  puVar5 = *(uint **)(lVar3 + 0x30);
  uVar10 = *puVar5;
  puVar6 = puVar5 + 4;
  uVar12 = param_4 - *(int *)(param_2 + 0x40);
  if (uVar12 != 0) {
    uVar18 = puVar5[6];
    if (uVar18 <= uVar12) {
      do {
        puVar5 = puVar6 + 6;
        uVar12 = uVar12 - uVar18;
        uVar10 = uVar10 - 1;
        uVar18 = puVar6[8];
        puVar6 = puVar5;
      } while (uVar18 <= uVar12);
    }
    uVar18 = *(uint *)(param_2 + 0x3c);
    uVar16 = 0;
    if (uVar10 != 0) {
      local_68 = 0;
      puVar5 = puVar6;
      do {
        uVar9 = puVar5[2] - uVar12;
        if (puVar5 != puVar6) {
          uVar9 = puVar5[2];
        }
        uVar8 = uVar18;
        iVar4 = uVar9 - uVar18;
        if (uVar9 <= uVar18) {
          uVar8 = uVar9;
          iVar4 = local_68;
        }
        local_68 = iVar4;
        uVar18 = uVar18 - uVar8;
        if (uVar18 == 0) break;
        puVar5 = puVar5 + 6;
        uVar16 = uVar16 + 1;
      } while (uVar16 < uVar10);
    }
    uVar10 = uVar16 + 1;
  }
  puVar5 = param_3;
  puVar21 = (uint *)0x0;
  uVar18 = (uint)uVar2;
  if (uVar10 <= uVar2 + 1) {
    uVar18 = uVar10;
  }
  while( true ) {
    puVar15 = puVar5;
    uVar16 = 0;
    if (uVar18 != 0) {
      uVar17 = (ulonglong)uVar18;
      do {
        *puVar15 = puVar6[2] | uVar19 << 0x18;
        puVar15[1] = *puVar6;
        if (bVar14 != 0) {
          puVar15[2] = puVar6[1];
        }
        puVar15 = puVar15 + uVar20;
        puVar6 = puVar6 + 6;
        uVar17 = uVar17 - 1;
        uVar16 = uVar18;
      } while (uVar17 != 0);
    }
    uVar11 = uVar11 + uVar16;
    puVar5 = puVar15 + -(ulonglong)uVar20;
    if (uVar10 <= uVar11) break;
    *puVar5 = *puVar5 | 0x80000000;
    if (uVar11 == uVar7) {
      *(undefined1 *)(param_5 + 2) = uVar1;
      uVar7 = (uint)*(ushort *)(param_1 + 0x52a);
    }
    if (puVar21 != (uint *)0x0) {
      *(char *)((longlong)puVar21 + 2) = (char)uVar20 * (char)uVar16;
      *(ushort *)puVar21 = (ushort)(byte)(((char)uVar16 + '\x01') * (char)uVar20 * '\x04');
      local_60 = (uint *)((longlong)local_60 + (ulonglong)*(ushort *)(param_1 + 0x530));
      uVar13 = uVar13 + *(ushort *)(param_1 + 0x530);
    }
    *puVar15 = (bVar14 + 0x18) * 0x2000000;
    puVar15[1] = uVar13;
    if (bVar14 != 0) {
      puVar15[2] = *(uint *)(param_1 + 500);
    }
    puVar5 = local_60;
    puVar21 = puVar15;
    uVar18 = uVar10 - uVar11;
    if (uVar7 + 1 < uVar10 - uVar11) {
      uVar18 = uVar7;
    }
  }
  uVar13 = *puVar5;
  *puVar5 = uVar13 | 0xc1000000;
  if (local_68 != 0) {
    *puVar5 = (uVar13 | 0xc1000000) - local_68;
  }
  if (puVar21 != (uint *)0x0) {
    *(undefined1 *)((longlong)puVar21 + 2) = 0;
    *(ushort *)puVar21 = (short)uVar20 * (short)uVar16 * 4 & 0xff;
  }
  if ((uVar12 != 0) && (param_3 != (uint *)0x0)) {
    *param_3 = *param_3 - uVar12;
    param_3[1] = param_3[1] + uVar12;
  }
  return;
}



===== BuildZeroLenSGE @ 140001850 =====

void BuildZeroLenSGE(longlong param_1,longlong param_2,int param_3,char param_4)

{
  if (param_4 == '\0') {
    *(undefined4 *)(param_2 + 0x60) = 0xd3000000;
    *(int *)(param_2 + 100) = param_3 + 0x70;
    *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_1 + 500);
    return;
  }
  *(undefined4 *)(param_2 + 0x68) = 0;
  *(undefined1 *)(param_2 + 0x6f) = 0x40;
  *(int *)(param_2 + 0x60) = param_3 + 0x70;
  *(undefined4 *)(param_2 + 100) = *(undefined4 *)(param_1 + 500);
  return;
}



===== CheckForNativeSGList @ 140001890 =====

ulonglong CheckForNativeSGList
                    (longlong param_1,longlong param_2,undefined8 param_3,longlong param_4,
                    int param_5,int param_6,ulonglong param_7)

{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  uint *puVar12;
  uint uStackX_14;
  
  puVar5 = *(uint **)(*(longlong *)(param_2 + 0x68) + 0x30);
  uVar4 = *puVar5;
  uVar10 = (ulonglong)uVar4;
  puVar5 = puVar5 + 4;
  uVar9 = *(uint *)(param_2 + 0x3c);
  if ((((param_6 == 3) && (*(uint *)(param_7 + 0x10) != 0)) && (*(uint *)(param_7 + 0x10) < uVar9))
     || ((uVar2 = *(ushort *)(param_1 + 0x52c) + 1, param_7 = (ulonglong)uVar2, uVar4 <= uVar2 &&
         ((param_6 != 3 ||
          ((uVar9 < 0x5001 &&
           ((uVar9 < 0x4001 ||
            (param_7 = (ulonglong)(*puVar5 & 0xfff), (uVar9 & 0xfff) <= 0x1000 - (*puVar5 & 0xfff)))
           )))))))) {
    return param_7 & 0xffffffffffffff00;
  }
  lVar11 = 0x70;
  if (param_6 != 3) {
    lVar11 = 0x60;
  }
  uVar2 = param_5 + (uint)*(ushort *)(param_1 + 0x534);
  puVar12 = (uint *)(lVar11 + param_4);
  puVar8 = (uint *)(param_4 + (ulonglong)*(ushort *)(param_1 + 0x534));
  puVar3 = puVar8 + 2;
  uVar9 = uVar2 + 8;
  if (((ulonglong)puVar3 & 0xfff) != 0) {
    puVar3 = puVar8;
    uVar9 = uVar2;
  }
  *puVar12 = uVar9;
  uVar2 = *(uint *)(param_1 + 500);
  puVar12[1] = uVar2;
  *(undefined2 *)((longlong)puVar12 + 0xe) = 0x8000;
  if (param_6 == 3) {
    bVar1 = true;
    *(undefined1 *)((longlong)puVar12 + 0xf) = 0x88;
    iVar7 = 0;
    if (uVar4 != 0) {
      do {
        lVar11 = *(longlong *)puVar5;
        for (uVar4 = puVar5[2]; uVar4 != 0; uVar4 = uVar4 - uVar6) {
          if (((ulonglong)(puVar3 + 2) & 0xfff) == 0) {
            uVar9 = uVar9 + 8;
            *puVar3 = uVar9;
            iVar7 = iVar7 + 1;
            puVar3[1] = *(uint *)(param_1 + 500);
            puVar3 = puVar3 + 2;
          }
          uVar2 = (uint)lVar11;
          uVar6 = 0x1000 - (uVar2 & 0xfff);
          uStackX_14 = (uint)((ulonglong)lVar11 >> 0x20);
          if (bVar1) {
            *(uint *)(param_4 + 0x60) = uVar2;
            bVar1 = false;
            *(uint *)(param_4 + 100) = uStackX_14;
            *(uint *)(param_4 + 0x68) = uVar6;
            *(undefined4 *)(param_4 + 0x6c) = 0;
          }
          else {
            *puVar3 = uVar2;
            uVar9 = uVar9 + 8;
            puVar3[1] = uStackX_14;
            puVar3 = puVar3 + 2;
            iVar7 = iVar7 + 1;
          }
          lVar11 = lVar11 + (ulonglong)uVar6;
          if (uVar4 < uVar6) break;
        }
        puVar5 = puVar5 + 6;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    uVar2 = iVar7 * 8;
    puVar12[2] = uVar2;
  }
  return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);
}



===== DriverEntry @ 140001a60 =====

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_d8;
  code *pcStack_d0;
  code *local_c8;
  code *pcStack_c0;
  code *local_b8;
  code *pcStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  code *pcStack_60;
  code *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_a8 = 0;
  uStack_a0 = 0;
  local_88 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_10 = 0;
  pcStack_d0 = LSImpiHWInitialize;
  local_c8 = LSImpiStartIo;
  pcStack_c0 = LSImpiIsr;
  local_b8 = LSImpiFindAdapter;
  pcStack_b0 = LSImpiOSReset;
  pcStack_60 = LSImpiAdapterControl;
  local_58 = LSImpiBuildIo;
  local_d8 = 0x5000000d0;
  uStack_80 = 0x101010102;
  uStack_90 = 0x200000428;
  local_98 = 0x340000bbe0;
  local_18 = 1;
  uStack_20 = 0x200000022;
  StorPortInitialize(0,param_2,&local_d8,0);
  return;
}



===== InternalLSImpiHWInitialize @ 140001b70 =====

longlong InternalLSImpiHWInitialize(longlong param_1,byte param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined4 uVar6;
  longlong lVar7;
  undefined4 uVar8;
  longlong *plVar9;
  longlong lVar10;
  char *pcVar11;
  bool bVar12;
  
  iVar1 = StorPortExtendedFunction(0xd,param_1,0,param_1 + 0x110);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x131) = 1;
    if ((((*(char *)(param_1 + 0x132) != '\0') && (*(char *)(param_1 + 0x11ee) == '\0')) &&
        ((*(undefined1 *)(param_1 + 0x132) = 0, *(char *)(param_1 + 0xba00) == '\0' ||
         (uVar3 = SetUpIntCoalPerfParameters(param_1), (char)uVar3 == '\0')))) &&
       (iVar1 = StorPortExtendedFunction(0xe,param_1,1,param_1 + 0x138), iVar1 == 0)) {
      *(undefined4 *)(param_1 + 0x13c) = 0x28;
      *(undefined4 *)(param_1 + 0x138) = 6;
      if ((*(uint *)(param_1 + 0x140) & 1) != 0) {
        *(undefined4 *)(param_1 + 0x140) = 1;
        iVar1 = StorPortExtendedFunction(0xe,param_1,0,param_1 + 0x138);
        if (iVar1 == 0) {
          *(undefined1 *)(param_1 + 0x132) = 1;
        }
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x132) = 0;
  }
  if ((*(char *)(param_1 + 0x132) != '\0') && (0x10 < *(byte *)(param_1 + 0x133))) {
    lVar7 = 0;
    lVar10 = 0x10;
    plVar9 = (longlong *)(param_1 + 0x60);
    do {
      lVar5 = *(longlong *)(param_1 + 0x10) + 0x30c + lVar7;
      lVar7 = lVar7 + 0x10;
      *plVar9 = lVar5;
      lVar10 = lVar10 + -1;
      plVar9 = plVar9 + 1;
    } while (lVar10 != 0);
  }
  uVar2 = ReadRegisterUlong(param_1,*(int **)(param_1 + 0x18));
  if ((uVar2 & 0xf0000000) != 0x20000000) {
    return (ulonglong)(uint3)((uVar2 & 0xf0000000) >> 8) << 8;
  }
  ClearResetHistoryBit(param_1,param_2,param_3);
  uVar2 = ReadRegisterUlong(param_1,*(int **)(param_1 + 0x50));
  **(uint **)(param_1 + 0x50) = uVar2 | 0x40000009;
  LOCK();
  UNLOCK();
  if (*(char *)(param_1 + 0xbbc6) == '\0') {
    uVar4 = FwDiagPostImmediateBuffers(param_1,param_2,param_3);
    if ((char)uVar4 == '\0') {
      bVar12 = *(char *)(param_1 + 0x11ee) != '\0';
      pcVar11 = "Diag buffer post to FW failed or not posted during Driver Init.";
      uVar6 = 0xad01002a;
      if (bVar12) {
        pcVar11 = "Diag buffer post to FW failed or not posted during Controller Reset.";
      }
      uVar8 = 0x8004af01;
      if (bVar12) {
        uVar8 = 0x4004af00;
      }
    }
    else {
      uVar6 = *(undefined4 *)(param_1 + 0x16e8);
      pcVar11 = "HTB post to FW is successful during Driver Init,buffer size logged.";
      *(undefined4 *)(param_1 + 0x16f4) = 0x4252434d;
      uVar8 = 0x4004af00;
      if (*(char *)(param_1 + 0x11ee) != '\0') {
        pcVar11 = "HTB post to FW is successful during HBA Reset,buffer size logged.";
      }
    }
    LogSystemEvent(param_1,uVar6,uVar8,(byte *)pcVar11,param_2,param_3);
  }
  uVar2 = ReadRegisterUlong(param_1,*(int **)(param_1 + 0x50));
  uVar4 = (ulonglong)(uVar2 & 0xfffffff7);
  **(uint **)(param_1 + 0x50) = uVar2 & 0xfffffff7;
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1 + 0x1970) = 1;
  if ((*(int *)(param_1 + 0x970) == 0) && (*(char *)(param_1 + 0xb930) != '\0')) {
    uVar4 = GtfStartTimer(param_1,1,300,DetectSataPfa,0,param_2,param_3);
    *(char *)(param_1 + 0xb933) = (char)uVar4;
    if (((char)uVar4 == -2) &&
       ((*(char *)(param_1 + 0x608) != '\0' && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)))) {
      uVar4 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                          (undefined1 *)0x0,0,param_2,param_3);
    }
  }
  if (*(char *)(param_1 + 0x11ee) == '\0') {
    *(char *)(param_1 + 0x11d7) = *(char *)(param_1 + 0x11d7) + -1;
    *(undefined1 *)(param_1 + 0x11ee) = 1;
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== LSImpiBuildIo @ 140001e70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 LSImpiBuildIo(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  short sVar11;
  uint *puVar12;
  int iVar13;
  uint uVar14;
  ulonglong uVar15;
  uint *puVar16;
  longlong lVar17;
  undefined8 uVar18;
  ushort uVar19;
  int *piVar20;
  ushort uVar21;
  int iVar22;
  short *psVar23;
  ulonglong uVar24;
  uint uVar25;
  undefined1 auStackY_d8 [32];
  uint local_78;
  undefined1 local_68 [8];
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  ushort local_50;
  byte local_4e;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  cVar3 = *(char *)(param_1 + 0x120a);
  uVar24 = 0;
  local_78 = 0;
  puVar12 = *(uint **)(param_2 + 0x68);
  if (*(char *)(param_2 + 2) == '(') {
    if (*(int *)(param_1 + 0x1218) != 0) {
      *(undefined1 *)(param_2 + 3) = 5;
      goto LAB_1400024e0;
    }
    psVar23 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2);
    if (*psVar23 != 1) {
LAB_140001ee5:
      *(undefined1 *)(param_2 + 3) = 4;
      goto LAB_1400024e0;
    }
    bVar4 = *(byte *)(psVar23 + 4);
    *(byte *)((longlong)puVar12 + 0x62) = bVar4;
    bVar5 = *(byte *)((longlong)psVar23 + 9);
    *(byte *)((longlong)puVar12 + 99) = bVar5;
    uVar6 = (undefined1)psVar23[5];
    *(undefined1 *)(puVar12 + 0x19) = uVar6;
    switch(*(undefined4 *)(param_2 + 0x14)) {
    case 0:
      uVar25 = 0;
      if (*(uint *)(param_2 + 0x38) == 0) {
        return 1;
      }
      while( true ) {
        piVar20 = (int *)((ulonglong)*(uint *)(param_2 + 0x78 + (ulonglong)uVar25 * 4) + param_2);
        iVar13 = *piVar20;
        if (iVar13 - 0x40U < 2) break;
        uVar25 = uVar25 + 1;
        if (*(uint *)(param_2 + 0x38) <= uVar25) {
          return 1;
        }
      }
      *(int **)(puVar12 + 0x10) = piVar20;
      uVar21 = (ushort)bVar4 * 0x80 + (ushort)bVar5;
      if ((uint)uVar21 < *(uint *)(param_1 + 0x9bc)) {
        uVar24 = (ulonglong)uVar21 * 0x2c + *(longlong *)(param_1 + 0x5c0);
        sVar11 = *(short *)(uVar24 + 0x1a);
        cVar7 = *(char *)(uVar24 + 0x24);
        if (sVar11 != 0) {
          bVar8 = *(byte *)(piVar20 + 6);
          *(byte *)(puVar12 + 0x18) = bVar8;
          bVar9 = *(byte *)((longlong)piVar20 + 0x19);
          *(byte *)((longlong)puVar12 + 0x61) = bVar9;
          *(int **)(puVar12 + 0x16) = piVar20 + 6;
          if (cVar7 != '\0') {
            local_78 = *(uint *)(uVar24 + 0x14) & 0xf;
          }
          if ((bVar8 == 0x42) && (local_78 == 3)) {
            if (CONCAT11(*(undefined1 *)((longlong)piVar20 + 0x1f),(char)piVar20[8]) == 0) {
              *(undefined1 *)(piVar20 + 2) = 0;
              *(undefined1 *)(param_2 + 3) = 1;
              goto LAB_1400024e0;
            }
            if (*(longlong *)(param_2 + 0x40) == 0) goto LAB_140001ee5;
            uVar15 = BuildNvmeEncapXlatedUnmapCommand(param_1,param_2,uVar24,0,3);
            if ((char)uVar15 == '\0') goto LAB_14000205f;
          }
          else {
LAB_14000205f:
            uVar25 = *(uint *)(param_2 + 0x18);
            puVar1 = puVar12 + 0x5a;
            *puVar12 = (uint)*(byte *)(uVar24 + 0x23);
            ZeroMemory(puVar1,0x60);
            *(short *)puVar1 = sVar11;
            *(undefined1 *)((longlong)puVar12 + 0x16b) = 0;
            *(undefined1 *)(puVar12 + 0x5f) = 0x18;
            bVar10 = *(byte *)((longlong)piVar20 + 10);
            *(ushort *)(puVar12 + 99) = (ushort)bVar10;
            *(undefined1 *)((longlong)puVar12 + 0x19d) = uVar6;
            if (iVar13 == 0x41) {
              iVar13 = *(byte *)((longlong)piVar20 + 10) - 0x10;
              puVar12[0x69] =
                   ((int)(iVar13 + (iVar13 >> 0x1f & 3U)) >> 2) << 0x1a | puVar12[0x69] & 0x3ffffff;
            }
            if (*puVar12 != 0) {
              *(ushort *)(puVar12 + 99) = bVar10 | 0x4000;
            }
            if ((uVar25 & 2) == 0) {
              uVar14 = 0;
            }
            else {
              uVar14 = (*(ushort *)(param_2 + 0x26) & 3) << 8;
            }
            uVar14 = puVar12[0x69] & 0xfffff8ff | uVar14;
            puVar12[0x69] = uVar14;
            puVar12[0x69] = (*(byte *)(uVar24 + 0x22) ^ uVar14) & 0xc0 ^ uVar14;
            memmove(puVar12 + 0x6a,piVar20 + 6,(ulonglong)*(byte *)((longlong)piVar20 + 10));
            if (((*(char *)(param_1 + 0x11ef) != '\0') && (bVar8 = (&OpCodeProt)[bVar8], bVar8 != 0)
                ) && (puVar16 = (uint *)StorPortGetLogicalUnit(param_1,bVar4,bVar5,uVar6),
                     (char)puVar16[1] != '\0')) {
              if (*(char *)(param_1 + 0x120a) == '\0') {
                puVar12[100] = *puVar16;
              }
              else {
                *(short *)(puVar12 + 100) = (short)*puVar16;
              }
              uVar19 = (ushort)puVar12[99] & 0x1ff;
              *(ushort *)((longlong)puVar12 + 0x18e) = bVar8 | 0x85c0;
              if (uVar19 == 0x20) {
                *(ushort *)((longlong)puVar12 + 0x18e) = bVar8 | 0xa5c0;
                *(byte *)((longlong)puVar12 + 0x1b2) =
                     *(byte *)((longlong)piVar20 + 0x22) & 0x1f | 0x20;
              }
              else {
                lVar17 = 0x1aa;
                if (uVar19 == 0x10) {
                  lVar17 = 0x1ae;
                }
                puVar12[0x6f] = *(uint *)(lVar17 + (longlong)puVar12);
                *(undefined2 *)((longlong)puVar12 + 0x1c2) = 0xffff;
                *(byte *)((longlong)puVar12 + 0x1a9) = bVar9 & 0x1f | 0x20;
              }
            }
            puVar12[0x61] = *(uint *)(param_2 + 0x3c);
            iVar13 = StorPortGetPhysicalAddress(param_1,param_2,puVar1,local_68);
            *(undefined1 *)((longlong)puVar12 + 0x17a) = 0xff;
            puVar12[0x5d] = iVar13 - 0x100;
            if ((uVar25 & 0xc0) == 0) {
              if (cVar3 == '\0') {
                puVar12[0x72] = 0xd3000000;
                puVar12[0x73] = iVar13 + 0x70U;
                puVar12[0x74] = *(uint *)(param_1 + 500);
              }
              else {
                puVar12[0x74] = 0;
                *(undefined1 *)((longlong)puVar12 + 0x1d7) = 0x40;
                puVar12[0x72] = iVar13 + 0x70U;
                puVar12[0x73] = *(uint *)(param_1 + 500);
              }
            }
            else {
              uVar18 = StorPortGetScatterGatherList(param_1,param_2);
              *(undefined8 *)(puVar12 + 0xc) = uVar18;
              if (((cVar7 == '\0') || ((local_78 & 4) != 0)) ||
                 (uVar24 = CheckForNativeSGList
                                     (param_1,param_2,*(undefined8 *)(param_2 + 0x40),
                                      (longlong)puVar1,iVar13,local_78,uVar24), (char)uVar24 == '\0'
                 )) {
                iVar22 = (int)*(undefined8 *)(param_2 + 0x40);
                if (cVar3 == '\0') {
                  BuildScatterGather(param_1,param_2,puVar12 + 0x72,iVar22,(longlong)puVar1,iVar13);
                }
                else {
                  BuildIeeeScatterGather(param_1,param_2,iVar22,(longlong)puVar1,iVar13);
                }
              }
            }
          }
          if (*(char *)(param_1 + 0x132) != '\0') {
            local_5c = 0x14;
            local_60 = 2;
            iVar13 = StorPortExtendedFunction(0xf,param_1,param_2,&local_60);
            if (iVar13 == 0) {
              if (*(char *)(param_1 + 0xba00) != '\0') {
                uVar24 = (ulonglong)
                         *(byte *)(*(longlong *)(param_1 + 0xba78 + (ulonglong)local_50 * 8) +
                                  (ulonglong)local_4e);
                lVar17 = *(longlong *)(param_1 + 0xba38 + uVar24 * 8);
                if (*(int *)(*(longlong *)(param_1 + 0xba30) + (ulonglong)uVar21 * 4) < 9) {
                  if (local_58 < *(uint *)(param_1 + 0xba10)) {
                    lVar2 = uVar24 + param_1;
                    uVar25 = (uint)*(byte *)(lVar2 + 0xbb20) - (uint)*(byte *)(lVar2 + 0xbad8);
                    if (uVar25 != 0) {
                      LOCK();
                      piVar20 = (int *)(param_1 + 0xbae0 + uVar24 * 8);
                      iVar13 = *piVar20;
                      *piVar20 = *piVar20 + 1;
                      UNLOCK();
                      *puVar12 = *puVar12 |
                                 (uint)*(byte *)(lVar17 + (ulonglong)
                                                          (byte)((char)((iVar13 + 1U >> 2) % uVar25)
                                                                + *(char *)(lVar2 + 0xbad8)) * 4) <<
                                 8;
                      goto LAB_140002488;
                    }
                  }
                }
                else if (*(char *)(uVar24 + 0xbad8 + param_1) != '\0') {
                  LOCK();
                  piVar20 = (int *)(param_1 + 0xba98 + uVar24 * 8);
                  iVar13 = *piVar20;
                  *piVar20 = *piVar20 + 1;
                  UNLOCK();
                  *puVar12 = *puVar12 |
                             (uint)*(byte *)(lVar17 + ((ulonglong)(iVar13 + 1U >> 2) %
                                                      (ulonglong)
                                                      *(byte *)(uVar24 + 0xbad8 + param_1)) * 4) <<
                             8;
                  goto LAB_140002488;
                }
              }
              *puVar12 = *puVar12 | (local_58 & 0xff) << 8;
            }
          }
LAB_140002488:
          if (*(char *)(param_1 + 0xbbd0) == '\0') {
            uVar18 = ProcessIncomingIOs(param_1,param_2);
            return (char)uVar18;
          }
          return 1;
        }
      }
      *(undefined1 *)(param_2 + 3) = 10;
      goto LAB_1400024e0;
    case 2:
    case 0x12:
    case 0x13:
    case 0x17:
    case 0x20:
    case 0x25:
      return 1;
    case 0x10:
    case 0x14:
      *(undefined1 *)(param_2 + 3) = 3;
      goto LAB_1400024e0;
    case 0x24:
      if (*(int *)(param_2 + 0x38) == 0) {
        return 1;
      }
      do {
        piVar20 = (int *)((ulonglong)*(uint *)(param_2 + 0x78 + uVar24 * 4) + param_2);
        if (*piVar20 == 0x61) {
          *(int **)(puVar12 + 0x12) = piVar20;
        }
        uVar25 = (int)uVar24 + 1;
        uVar24 = (ulonglong)uVar25;
      } while (uVar25 < *(uint *)(param_2 + 0x38));
      return 1;
    }
  }
  *(undefined1 *)(param_2 + 3) = 0x22;
LAB_1400024e0:
  StorPortNotification(0,param_1,param_2);
  return 0;
}



===== LSImpiFindAdapter @ 140002560 =====

undefined8
LSImpiFindAdapter(longlong *param_1,undefined8 param_2,undefined8 param_3,byte *param_4,
                 longlong param_5)

{
  longlong *plVar1;
  ulonglong *puVar2;
  byte bVar3;
  int *piVar4;
  char cVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  undefined8 *puVar11;
  longlong lVar12;
  longlong *plVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  undefined2 uVar16;
  ushort uVar17;
  ushort uVar18;
  int iVar19;
  uint uVar20;
  undefined4 uVar21;
  longlong *plVar22;
  ulonglong uVar23;
  undefined8 *puVar24;
  uint *puVar25;
  undefined8 *puVar26;
  char *pcVar27;
  int iVar28;
  ushort uVar29;
  ushort local_res8;
  undefined8 in_stack_ffffffffffffff88;
  uint local_58;
  uint local_54;
  undefined3 local_50;
  char cStack_4d;
  ushort local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34 [3];
  
  uVar21 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  local_50 = 0x535054;
  cStack_4d = '0';
  local_44 = local_44 & 0xffff0000;
  local_54 = 0;
  local_38 = 0;
  local_40 = 0;
  if (*param_1 != 0) {
    ZeroMemory(param_1,0xbbe0);
  }
  *(undefined1 *)(param_1 + 0x26) = 0;
  *(undefined1 *)((longlong)param_1 + 0x11be) = 0;
  *(undefined1 *)((longlong)param_1 + 0xb92d) = 1;
  GtfInitialize((longlong)param_1);
  *(undefined1 *)((longlong)param_1 + 0x11d7) = 1;
  puVar11 = *(undefined8 **)(param_5 + 0x38);
  if (*(int *)(puVar11 + 1) != 0) {
    puVar26 = puVar11;
    puVar24 = (undefined8 *)0x0;
    if (*(char *)((longlong)puVar11 + 0xc) == '\0') {
      puVar26 = (undefined8 *)0x0;
      puVar24 = puVar11;
    }
    if (*(int *)(puVar11 + 3) != 0) {
      if (*(char *)((longlong)puVar11 + 0x1c) == '\0') {
        puVar24 = puVar11 + 2;
      }
      else {
        puVar11 = puVar11 + 2;
        if (puVar26 != (undefined8 *)0x0) {
          puVar11 = puVar26;
        }
        puVar26 = puVar11;
      }
    }
    if (puVar26 != (undefined8 *)0x0) {
      if (puVar24 != (undefined8 *)0x0) {
        *(undefined4 *)((longlong)param_1 + 0x1964) = *(undefined4 *)puVar24;
      }
      *(undefined4 *)(param_1 + 0x32d) = *(undefined4 *)puVar26;
      *(undefined4 *)((longlong)param_1 + 0x196c) = *(undefined4 *)((longlong)puVar26 + 4);
      *(undefined4 *)(param_1 + 0x32e) = 3;
      *(undefined4 *)(param_1 + 0x343) = 1;
      lVar12 = StorPortGetDeviceBase
                         (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),*puVar26
                          ,CONCAT44(uVar21,*(undefined4 *)(puVar26 + 1)),
                          *(char *)((longlong)puVar26 + 0xc) == '\0');
      param_1[2] = lVar12;
      if (puVar24 != (undefined8 *)0x0) {
        lVar12 = StorPortGetDeviceBase
                           (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),
                            *puVar24,*(undefined4 *)(puVar24 + 1),
                            *(char *)((longlong)puVar24 + 0xc) == '\0');
        param_1[0x20] = lVar12;
      }
      if (param_1[2] == 0) {
        pcVar27 = "could not get the chips IO address space correctly";
        uVar21 = 0xad010002;
        goto LAB_140003e4e;
      }
      *(undefined1 *)(param_1 + 0x177a) = 0;
      *(undefined4 *)((longlong)param_1 + 0xbbd4) = 2;
      plVar1 = param_1 + 0x2eb;
      *(undefined2 *)(param_1 + 0x177b) = 6;
      local_3c = StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),
                                    *(undefined4 *)(param_5 + 100),plVar1,0x100);
      if ((*(short *)((longlong)param_1 + 0x175a) - 0xe1U & 0xfffa) == 0) {
        *(undefined1 *)((longlong)param_1 + 0xbbc4) = 1;
LAB_140002748:
        plVar13 = (longlong *)((ulonglong)*(byte *)((longlong)param_1 + 0x178c) + (longlong)plVar1);
        bVar3 = *(byte *)((longlong)plVar13 + 1);
        while (plVar22 = plVar1, bVar3 != 0) {
          if ((char)*plVar13 == '\x10') {
            plVar22 = plVar13;
            break;
          }
          plVar13 = (longlong *)((ulonglong)bVar3 + (longlong)plVar1);
          bVar3 = *(byte *)((longlong)plVar13 + 1);
        }
        uVar9 = *(uint *)((longlong)plVar22 + 0xc);
        *(uint *)(param_1 + 0x1779) = uVar9;
        uVar20 = *(uint *)((longlong)plVar22 + 0x12);
        *(uint *)((longlong)param_1 + 0xbbcc) = uVar20;
        uVar20 = uVar20 & 0xf;
        if (uVar20 < (uVar9 & 0xf)) {
          LogSystemEvent((longlong)param_1,uVar20,0x4004af00,
                         (byte *)"Less Pcie speed is detected than link capability,PerfMode is off",
                         0,1);
        }
        else {
          *(undefined4 *)((longlong)param_1 + 0xbbd4) = 0;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"PerfMode",(int *)&local_58);
        if ((char)uVar14 != '\0') {
          if (local_58 < 2) {
            *(undefined1 *)(param_1 + 0x177a) = 0;
            *(uint *)((longlong)param_1 + 0xbbd4) = local_58;
          }
          else if (local_58 == 2) {
            *(undefined1 *)(param_1 + 0x177a) = 1;
            *(undefined4 *)((longlong)param_1 + 0xbbd4) = 2;
          }
        }
      }
      else if (*(char *)((longlong)param_1 + 0xbbc4) != '\0') goto LAB_140002748;
      piVar4 = (int *)param_1[2];
      param_1[3] = (longlong)piVar4;
      param_1[4] = (longlong)(piVar4 + 1);
      param_1[5] = (longlong)(piVar4 + 2);
      param_1[6] = (longlong)(piVar4 + 4);
      param_1[7] = (longlong)(piVar4 + 5);
      param_1[8] = (longlong)(piVar4 + 6);
      param_1[9] = (longlong)(piVar4 + 0xc);
      param_1[10] = (longlong)(piVar4 + 0xd);
      param_1[0xb] = (longlong)(piVar4 + 0x12);
      param_1[0xc] = (longlong)(piVar4 + 0x1b);
      param_1[0x1c] = (longlong)(piVar4 + 0x1d);
      param_1[0x1d] = (longlong)(piVar4 + 0x30);
      param_1[0x1e] = (longlong)(piVar4 + 0x31);
      param_1[0x1f] = (longlong)(piVar4 + 0x32);
      uVar9 = ReadRegisterUlong((longlong)param_1,piVar4);
      if ((uVar9 & 0x7000000) == 0x3000000) {
        pcVar27 = "PCI Peer device controls this IOC";
        uVar21 = 0xad010018;
        goto LAB_140003e4e;
      }
      if (param_4 != (byte *)0x0) {
        ProcessParseArgumentString(param_4,(byte *)"dump",(int *)&local_54);
        ProcessParseArgumentString(param_4,(byte *)"ntldr",(int *)&local_38);
        local_54 = local_54 | local_38;
        if (local_54 != 0) {
          *(uint *)(param_1 + 0x12e) = local_54;
        }
      }
      if (2 < local_3c) {
        *(uint *)(param_1 + 0x12a) = (uint)*(ushort *)((longlong)param_1 + 0x175a);
        local_40 = *(int *)(param_5 + 4) << 8 | *(uint *)(param_5 + 100);
        GetCimData((longlong)param_1,(longlong)plVar1,local_40);
      }
      if (((int)param_1[0x12e] == 0) && (*(int *)((longlong)param_1 + 0xbbd4) == 0)) {
        *(undefined1 *)(param_1 + 0x1740) = 1;
        iVar10 = StorPortExtendedFunction(0x14,param_1,(uint *)((longlong)param_1 + 0xba04));
        if (iVar10 != 0) {
          *(undefined1 *)(param_1 + 0x1740) = 0;
        }
        iVar10 = StorPortExtendedFunction(0x12,param_1);
        if (iVar10 != 0) {
          *(undefined1 *)(param_1 + 0x1740) = 0;
        }
        if (4 < *(ushort *)(param_1 + 0x1741)) {
          *(undefined1 *)(param_1 + 0x1740) = 0;
        }
        uVar9 = *(uint *)((longlong)param_1 + 0xba04);
        if (8 < uVar9) {
          *(undefined1 *)(param_1 + 0x1740) = 0;
        }
        if ((char)param_1[0x1740] != '\0') {
          *(uint *)(param_1 + 0x1742) = uVar9 * 8;
        }
      }
      uVar9 = ReadRegisterUlong((longlong)param_1,(int *)param_1[3]);
      if ((uVar9 >> 0x1b & 1) != 0) {
        LogOperationalEvent((longlong)param_1,(int *)0x0,0,0x4004af00,
                            "Diag Reset(miniport)-Doorbell register is active and in use",0,1);
        KickStart((longlong)param_1,0,1);
      }
      local_34[0] = ReadRegisterUlong((longlong)param_1,(int *)param_1[3]);
      uVar9 = 0;
      while (local_34[0] = local_34[0] & 0xf0000000, local_34[0] != 0x10000000) {
        if (local_34[0] == 0x20000000) {
          IssueIOCFacts((longlong)param_1,0,1);
          if ((*(uint *)((longlong)param_1 + 0x120c) & 0x2000) == 0) {
            LogOperationalEvent((longlong)param_1,(int *)((longlong)param_1 + 0x120c),4,0x4004af00,
                                "Diag Reset(miniport)-FW doesn\'t support event replay,IOC capability logged"
                                ,0,1);
            KickStart((longlong)param_1,0,1);
          }
          else {
            IssueReset((longlong)param_1,0x40);
          }
        }
        else if (local_34[0] != 0) {
          LogOperationalEvent((longlong)param_1,(int *)local_34,4,0x4004af00,
                              "Diag Reset(miniport)-Doorbell isn\'t in a known state ,it\'s Status logged"
                              ,0,1);
          uVar15 = KickStart((longlong)param_1,0,1);
          if ((char)uVar15 == '\0') {
            return 2;
          }
        }
        lVar12 = 100;
        do {
          StorPortStallExecution(1000);
          lVar12 = lVar12 + -1;
        } while (lVar12 != 0);
        if (3000 < uVar9) {
          LogSystemEvent((longlong)param_1,0xad010003,0xc004af02,
                         (byte *)"IOC would not come to the READY state",0,1);
          return 2;
        }
        local_34[0] = ReadRegisterUlong((longlong)param_1,(int *)param_1[3]);
        uVar9 = uVar9 + 1;
      }
      uVar14 = IssueIOCFacts((longlong)param_1,0,1);
      if ((char)uVar14 == '\0') {
        return 2;
      }
      if ((*(uint *)((longlong)param_1 + 0x120c) & 0x80000) == 0) {
        LogSystemEvent((longlong)param_1,0xad010077,0x4004af00,
                       (byte *)"Atomic Request Descriptor not supported by IOC",0,1);
      }
      else if (*(char *)((longlong)param_1 + 0xbbc4) != '\0') {
        *(undefined1 *)((longlong)param_1 + 0xbbc5) = 1;
      }
      if (*(short *)((longlong)param_1 + 0x9ac) != 0x206) {
        pcVar27 = "Unsupported MPI message version reported";
        uVar21 = 0xad010091;
        goto LAB_140002bb2;
      }
      local_res8 = *(ushort *)((longlong)param_1 + 0x532);
      lVar12 = 10;
      local_4c = *(ushort *)((longlong)param_1 + 0x534);
      uVar17 = *(ushort *)(param_1 + 0xa8);
      *(undefined4 *)((longlong)param_1 + 0x984) = 0x40;
      uVar9 = 0;
      *(undefined4 *)(param_1 + 0x229) = 7;
      *(undefined1 *)((longlong)param_1 + 0x120a) = 1;
      local_48 = (uint)uVar17;
      *(undefined4 *)(param_1 + 0x131) = 0x20;
      *(undefined4 *)((longlong)param_1 + 0x98c) = 0x80;
      *(undefined4 *)(param_1 + 0x130) = 10;
      if (*(short *)((longlong)param_1 + 0x99a) != 0) {
        do {
          uVar15 = IssuePortFacts((longlong)param_1,(char)uVar9,0,1);
          if ((char)uVar15 == '\0') {
            return 2;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(ushort *)((longlong)param_1 + 0x99a));
      }
      puVar2 = (ulonglong *)(param_1 + 0xbb);
      *(undefined4 *)(param_1 + 0x120) = 5;
      RttSetTraceParameters((longlong)puVar2,0x32000,1);
      *(undefined2 *)((longlong)param_1 + 0x5c9) = 0x40c;
      if (param_4 != (byte *)0x0) {
        uVar14 = ProcessParseArgumentString
                           (param_4,(byte *)"LogFullPersistentTableEvent",(int *)&local_58);
        if ((char)uVar14 != '\0') {
          *(bool *)((longlong)param_1 + 0xb92d) = local_58 != 0;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"RTTraceBufferSize",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          if ((local_58 & 3) != 0) {
            local_58 = local_58 + (4 - (local_58 & 3));
          }
          RttSetTraceParameters((longlong)puVar2,local_58,2);
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"SizeOfReplyBuffer",(int *)&local_58);
        if (((char)uVar14 != '\0') && (0x44 < local_58)) {
          if ((local_58 & 3) != 0) {
            local_58 = local_58 + (4 - (local_58 & 3));
          }
          local_res8 = (ushort)local_58;
        }
        uVar14 = ProcessParseArgumentString
                           (param_4,(byte *)"NumSasTopoEventsPerExpander",(int *)&local_58);
        if (((char)uVar14 != '\0') && (0xc < local_58)) {
          *(char *)((longlong)param_1 + 0x5c9) = (char)local_58;
        }
        uVar14 = ProcessParseArgumentString
                           (param_4,(byte *)"NumPcieTopoEventsPerExpander",(int *)&local_58);
        if (((char)uVar14 != '\0') && (4 < local_58)) {
          *(char *)((longlong)param_1 + 0x5ca) = (char)local_58;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"SSU_Enables",(int *)&local_58);
        if ((char)uVar14 == '\0') {
          *(undefined2 *)((longlong)param_1 + 0xb664) = 5;
          uVar16 = 5;
          if (((char)param_1[0xc1] != '\0') && ((*(uint *)((longlong)param_1 + 0x60c) & 0x110) != 0)
             ) {
            RttLogEvent((longlong)param_1,(char *)((longlong)param_1 + 0x11d7),puVar2,0x110,
                        (undefined1 *)0x0,0,0,1);
            uVar16 = *(undefined2 *)((longlong)param_1 + 0xb664);
          }
        }
        else {
          if (((7 < local_58) && (local_58 = 5, (char)param_1[0xc1] != '\0')) &&
             ((*(uint *)((longlong)param_1 + 0x60c) & 0x110) != 0)) {
            RttLogEvent((longlong)param_1,(char *)((longlong)param_1 + 0x11d7),puVar2,0x110,
                        (undefined1 *)&local_58,4,0,1);
          }
          uVar16 = (undefined2)local_58;
          *(undefined2 *)((longlong)param_1 + 0xb664) = uVar16;
        }
        *(undefined2 *)(param_1 + 0x16cd) = uVar16;
        uVar14 = ProcessParseArgumentString
                           (param_4,(byte *)"NumberOfRequestMessageBuffers",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_44 = 0x10, 0x10 < local_58)) {
          local_44 = local_58 & 0xffff;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"LogExceptionEvents",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined2 *)(param_1 + 300) = 1;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"DisableRescan",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined2 *)((longlong)param_1 + 0x9aa) = 1;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"StopOnBusReset",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)(param_1 + 0x237) = 1;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"StopOnDiagReset",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x11b9) = 1;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"StopOnOrphanedReset",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x11ba) = 1;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"StopOnLostSrb",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x11bb) = 1;
        }
        uVar14 = ProcessParseArgumentString
                           (param_4,(byte *)"StopOnMismatchReqReply",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x11bc) = 1;
        }
        uVar14 = ProcessParseArgumentString
                           (param_4,(byte *)"DisableFwQueueFullHandling",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x120b) = 0;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"EEDP_Enable",(int *)&local_58);
        if ((((char)uVar14 != '\0') && (local_58 != 0)) &&
           ((*(uint *)((longlong)param_1 + 0x120c) & 0x40) != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x11ef) = 1;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"DisableHashSASAddr",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x11e6) = 1;
        }
        uVar14 = ProcessParseArgumentString
                           (param_4,(byte *)"EnableSataSmartErrPolling",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)(param_1 + 0x1726) = 1;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"MaxSGList",(int *)&local_58);
        if (((char)uVar14 != '\0') && (0x10 < local_58)) {
          *(uint *)(param_1 + 0x132) = local_58;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"MaxSASQueueDepth",(int *)&local_58);
        if ((char)uVar14 != '\0') {
          uVar9 = local_58;
          if (local_58 == 0) {
            uVar9 = 1;
          }
          *(uint *)((longlong)param_1 + 0x984) = uVar9;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"MaxSATAQueueDepth",(int *)&local_58);
        if ((char)uVar14 != '\0') {
          uVar9 = local_58;
          if (local_58 == 0) {
            uVar9 = 1;
          }
          *(uint *)(param_1 + 0x131) = uVar9;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"MaxNVMeQueueDepth",(int *)&local_58);
        if ((char)uVar14 != '\0') {
          uVar9 = local_58;
          if (local_58 == 0) {
            uVar9 = 1;
          }
          *(uint *)((longlong)param_1 + 0x98c) = uVar9;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"ResumeDelay",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(uint *)(param_1 + 0x130) = local_58;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"FastPathToggleLimit",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(char *)((longlong)param_1 + 0x121e) = (char)local_58;
        }
        uVar14 = ProcessParseArgumentString(param_4,&s_PSuite,(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x11b2) = 1;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"DisableDefaultHTB",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)(param_1 + 0x173d) = 1;
        }
        uVar14 = ProcessParseArgumentString
                           (param_4,(byte *)"VenturaDisableCombinedIOPath",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          *(undefined1 *)(param_1 + 0x177a) = 1;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"MaxPersistentEntries",(int *)&local_58)
        ;
        if ((char)uVar14 != '\0') {
          uVar6 = (ushort)local_58;
          if (*(ushort *)((longlong)param_1 + 0x99c) < (ushort)local_58) {
            uVar6 = *(ushort *)((longlong)param_1 + 0x99c);
          }
          *(ushort *)((longlong)param_1 + 0x18bc) = uVar6;
        }
        uVar14 = ProcessParseArgumentString(param_4,(byte *)"EnaDiag",(int *)&local_58);
        if (((char)uVar14 != '\0') && (local_58 != 0)) {
          uVar14 = ProcessParseArgumentString(param_4,&s_SSBuffSize,(int *)&local_58);
          if (((char)uVar14 != '\0') && ((local_58 != 0 && ((char)param_1[0x2e1] != '\0')))) {
            *(uint *)(param_1 + 0x2e0) = local_58;
          }
          uVar14 = ProcessParseArgumentString(param_4,&s_SSImmed,(int *)&local_58);
          if ((((char)uVar14 != '\0') && (local_58 != 0)) && ((char)param_1[0x2e1] != '\0')) {
            *(undefined1 *)((longlong)param_1 + 0x1707) = 1;
          }
          uVar14 = ProcessParseArgumentString(param_4,&s_TBuffSize,(int *)&local_58);
          if ((((char)uVar14 != '\0') && (local_58 != 0)) && ((char)param_1[0x2de] != '\0')) {
            *(uint *)(param_1 + 0x2dd) = local_58;
          }
          uVar14 = ProcessParseArgumentString(param_4,&s_TImmed,(int *)&local_58);
          if ((((char)uVar14 != '\0') && (local_58 != 0)) && ((char)param_1[0x2de] != '\0')) {
            *(undefined1 *)((longlong)param_1 + 0x16ef) = 1;
          }
          puVar25 = (uint *)(param_1 + 0x2e5);
          do {
            uVar14 = ProcessParseArgumentString(param_4,(byte *)&local_50,(int *)&local_58);
            if ((((char)uVar14 != '\0') && (local_58 != 0)) && ((char)param_1[0x2de] != '\0')) {
              *puVar25 = local_58;
            }
            cStack_4d = cStack_4d + '\x01';
            puVar25 = puVar25 + 1;
            lVar12 = lVar12 + -1;
          } while (lVar12 != 0);
          uVar14 = ProcessParseArgumentString(param_4,&s_EXBuffSize,(int *)&local_58);
          if ((((char)uVar14 != '\0') && (local_58 != 0)) && ((char)param_1[0x2e4] != '\0')) {
            *(uint *)(param_1 + 0x2e3) = local_58;
          }
          uVar14 = ProcessParseArgumentString(param_4,&s_EXImmed,(int *)&local_58);
          if ((((char)uVar14 != '\0') && (local_58 != 0)) && ((char)param_1[0x2e4] != '\0')) {
            *(undefined1 *)((longlong)param_1 + 0x171f) = 1;
          }
          uVar14 = ProcessParseArgumentString(param_4,(byte *)"EXType",(int *)&local_58);
          if ((((char)uVar14 != '\0') && (local_58 != 0)) && ((char)param_1[0x2e4] != '\0')) {
            *(char *)((longlong)param_1 + 0x171d) = (char)local_58;
          }
        }
        uVar14 = ProcessParseArgumentString
                           (param_4,(byte *)"AutoFWDiagBufferUpload",(int *)&local_58);
        if ((char)uVar14 != '\0') {
          if ((local_58 == 0) || ((char)param_1[0x2de] == '\0')) {
            if (((char)param_1[0xc1] != '\0') &&
               ((*(uint *)((longlong)param_1 + 0x60c) & 0x241) != 0)) {
              uVar21 = 0x241;
              goto LAB_140003460;
            }
          }
          else {
            *(uint *)(param_1 + 0x235) = *(uint *)(param_1 + 0x235) | 0x4000;
            *(undefined1 *)(param_1 + 0x16d3) = 1;
            if (((*(uint *)(param_1 + 0x2dd) < 4000000) &&
                (*(undefined4 *)(param_1 + 0x2dd) = 4000000, (char)param_1[0xc1] != '\0')) &&
               ((*(uint *)((longlong)param_1 + 0x60c) & 0x10f) != 0)) {
              RttLogEvent((longlong)param_1,(char *)((longlong)param_1 + 0x11d7),puVar2,0x10f,
                          (undefined1 *)0x0,0,0,1);
            }
            if (((*(char *)((longlong)param_1 + 0x16ef) == '\0') &&
                (*(undefined1 *)((longlong)param_1 + 0x16ef) = 1, (char)param_1[0xc1] != '\0')) &&
               ((*(uint *)((longlong)param_1 + 0x60c) & 0x10f) != 0)) {
              uVar21 = 0x10f;
LAB_140003460:
              RttLogEvent((longlong)param_1,(char *)((longlong)param_1 + 0x11d7),puVar2,uVar21,
                          (undefined1 *)0x0,0,0,1);
            }
          }
        }
        if (local_54 != 0) {
          uVar14 = ProcessParseArgumentString
                             (param_4,(byte *)"CrashModeMaxDevices",(int *)&local_58);
          if ((char)uVar14 == '\0') {
            *(undefined2 *)((longlong)param_1 + 0x99c) = 0x40;
          }
          else if (local_58 == 0) {
            *(undefined2 *)((longlong)param_1 + 0x99c) = 0x40;
          }
          else {
            *(short *)((longlong)param_1 + 0x99c) = (short)local_58;
          }
        }
      }
      uVar6 = local_4c;
      *(undefined2 *)((longlong)param_1 + 0x9a4) = 1;
      if (0x80 < *(ushort *)((longlong)param_1 + 0x99c)) {
        uVar7 = 1;
        uVar14 = (ulonglong)
                 (ushort)(((ushort)(*(ushort *)((longlong)param_1 + 0x99c) - 0x81) >> 7) + 1);
        do {
          uVar7 = uVar7 + 1;
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
        *(ushort *)((longlong)param_1 + 0x9a4) = uVar7;
        if (0xff < uVar7) {
          *(undefined2 *)((longlong)param_1 + 0x9a4) = 0xff;
        }
      }
      *(undefined1 *)(param_5 + 0x92) = 0xff;
      if (*(char *)(param_5 + 0x90) == -0x80) {
        *(undefined1 *)(param_5 + 0x90) = 4;
        *(uint *)(param_5 + 0xcc) = (uint)*(ushort *)(param_1 + 0x133);
        *(undefined4 *)(param_5 + 0xd8) = 0;
        *(ushort *)((longlong)param_1 + 0x542) = *(ushort *)((longlong)param_1 + 0x542) | 1;
      }
      uVar7 = *(ushort *)((longlong)param_1 + 0x542) & 1 | 2;
      uVar8 = uVar7 * 4;
      uVar9 = (uint)(ushort)((local_4c + uVar7 * -4) - 0x60) / (uint)uVar8;
      uVar7 = (ushort)((short)param_1[0xa6] + uVar7 * -4) / uVar8;
      *(ushort *)((longlong)param_1 + 0x52a) = uVar7;
      *(short *)(param_1 + 0xa5) = (short)uVar9;
      *(uint *)((longlong)param_1 + 0x21c) = uVar8 * uVar9 + 0x60 >> 2;
      if (*(char *)((longlong)param_1 + 0x120a) != '\0') {
        uVar8 = (ushort)(local_4c - 0x70) >> 4;
        uVar9 = (uint)uVar8;
        uVar7 = (ushort)((short)param_1[0xa6] - 0x10U) >> 4;
        *(ushort *)((longlong)param_1 + 0x52c) = uVar8;
        *(ushort *)((longlong)param_1 + 0x52e) = uVar7;
        *(uint *)(param_1 + 0x44) = uVar8 + 6;
      }
      uVar20 = 0x101;
      if (*(uint *)(param_1 + 0x132) != 0) {
        uVar20 = *(uint *)(param_1 + 0x132);
      }
      *(uint *)(param_5 + 0x1c) = uVar20;
      uVar8 = (short)((int)((uVar20 & 0xffff) - uVar9) / (int)(uint)uVar7) + 1;
      if (uVar17 < uVar8) {
        *(uint *)(param_5 + 0x1c) = (uint)uVar17 * (uint)uVar7 + uVar9;
      }
      else {
        local_48 = CONCAT22(local_48._2_2_,uVar8);
      }
      if (local_54 == 0) {
        uVar17 = (ushort)local_44;
        if ((uVar17 != 0) && (uVar17 < *(ushort *)(param_1 + 0x133))) {
          *(ushort *)(param_1 + 0x133) = uVar17;
        }
      }
      else {
        local_48 = 3;
        *(undefined2 *)(param_1 + 0x133) = 4;
        *(undefined4 *)(param_5 + 0x1c) = 0x11;
        *(undefined2 *)((longlong)param_1 + 0x5c9) = 0x101;
        *(undefined4 *)((longlong)param_1 + 0x99e) = 0x80008;
        RttSetTraceParameters((longlong)puVar2,0,0);
        *(undefined1 *)((longlong)param_1 + 0x132) = 0;
      }
      uVar7 = *(ushort *)(param_1 + 0x133);
      *(undefined4 *)((longlong)param_1 + 0x994) = *(undefined4 *)(param_5 + 0x1c);
      uVar17 = uVar7 + 0x20;
      if (local_54 != 0) {
        uVar17 = 0xc;
      }
      uVar8 = uVar17 - 1;
      if ((uVar17 & 0xf) != 0) {
        uVar8 = uVar17;
      }
      *(ushort *)((longlong)param_1 + 0x53c) = uVar8;
      uVar29 = (uVar8 & 0xfff0) + 0x10;
      *(ushort *)(param_1 + 0xa7) = uVar29;
      uVar17 = uVar8 + 1 + uVar7;
      if ((uVar17 & 0xf) != 0) {
        uVar17 = uVar17 + (0x10 - (uVar17 & 0xf));
      }
      uVar18 = *(ushort *)((longlong)param_1 + 0x53e);
      if (uVar18 < uVar17) {
        uVar17 = (ushort)(uVar17 - uVar18) >> 1;
        if ((uVar17 & 0xf) != 0) {
          uVar17 = uVar17 + (0x10 - (uVar17 & 0xf));
        }
        uVar7 = uVar7 - uVar17;
        uVar8 = uVar8 - uVar17;
        *(ushort *)(param_1 + 0x133) = uVar7;
        uVar29 = uVar29 - uVar17;
        *(ushort *)((longlong)param_1 + 0x53c) = uVar8;
        *(ushort *)(param_1 + 0xa7) = uVar29;
        uVar17 = uVar18;
      }
      *(ushort *)((longlong)param_1 + 0x53a) = uVar17;
      local_44 = (uint)uVar17;
      if (*(char *)((longlong)param_1 + 0x132) != '\0') {
        local_44 = local_44 * *(byte *)((longlong)param_1 + 0x133);
      }
      *(ushort *)((longlong)param_1 + 0x534) = uVar6;
      if (local_res8 < *(ushort *)((longlong)param_1 + 0x532)) {
        local_res8 = *(ushort *)((longlong)param_1 + 0x532);
      }
      else {
        *(ushort *)((longlong)param_1 + 0x532) = local_res8;
      }
      uVar17 = *(ushort *)((longlong)param_1 + 0x99c);
      *(uint *)((longlong)param_1 + 0x9bc) = (uint)uVar17;
      LogSystemEvent((longlong)param_1,(uint)uVar17,0x4004af00,
                     (byte *)"Mapping table size has been set and its size is logged",0,1);
      if (((char)param_1[0xc1] != '\0') && ((*(uint *)((longlong)param_1 + 0x60c) & 0x100008) != 0))
      {
        RttLogEvent((longlong)param_1,(char *)((longlong)param_1 + 0x11d7),puVar2,0x100008,
                    (undefined1 *)((longlong)param_1 + 0x9bc),4,0,1);
      }
      uVar6 = *(ushort *)((longlong)param_1 + 0x18bc);
      *(undefined4 *)(param_5 + 0x18) = 0xffffff;
      *(undefined1 *)(param_5 + 0x61) = 0x80;
      *(undefined1 *)(param_5 + 0x51) = 1;
      *(undefined1 *)(param_5 + 0x54) = 0;
      *(undefined1 *)(param_5 + 0x48) = *(undefined1 *)((longlong)param_1 + 0x9a4);
      *(code **)(param_5 + 0x98) = LSImpiMSIIsr;
      *(undefined1 *)(param_5 + 0x91) = 1;
      *(undefined4 *)(param_5 + 0x94) = 1;
      *(undefined4 *)(param_5 + 0xa0) = 2;
      if (local_54 == 0) {
        LSImpiWmiInitialize((longlong)param_1);
        *(uint *)(param_1 + 0x3c) = local_40;
      }
      *(uint *)(param_5 + 0x8c) =
           local_4c + 0x168 + (local_48 & 0xffff) * (uint)*(ushort *)(param_1 + 0xa6);
      uVar14 = (ulonglong)*(ushort *)((longlong)param_1 + 0x532) - 0x28;
      uVar18 = (short)(uVar14 >> 2) * 0x1c + 0xc;
      *(ushort *)((longlong)param_1 + 0x5d4) = uVar18;
      uVar9 = (uint)uVar18;
      iVar28 = *(byte *)((longlong)param_1 + 0x5c9) * uVar9 * (uint)*(ushort *)(param_1 + 0x134);
      uVar18 = (short)(uVar14 >> 3) * 0x1c + 0xc;
      *(int *)((longlong)param_1 + 0x5cc) = iVar28;
      *(ushort *)((longlong)param_1 + 0x5d6) = uVar18;
      uVar20 = (uint)uVar18;
      iVar10 = *(byte *)((longlong)param_1 + 0x5ca) * uVar20 * (uint)*(ushort *)(param_1 + 0x134);
      *(int *)(param_1 + 0xba) = iVar10;
      iVar28 = ((uint)local_4c + (uint)*(ushort *)((longlong)param_1 + 0x99e) * 4) * 7 +
               ((uint)uVar17 * 0x1b + ((uint)uVar29 + (local_44 + 0x1cd) * 2) * 2 +
               (uint)*(ushort *)((longlong)param_1 + 0x18bc)) * 2 + (uint)uVar8 * (uint)local_res8 +
               (local_4c + 0x28) * (uint)uVar7 + (int)param_1[0xc0] + iVar10 + (uint)uVar6 * 0x14 +
               iVar28;
      iVar10 = iVar28 + 0x80;
      if ((int)param_1[0x12e] != 0) {
        iVar10 = iVar28;
      }
      iVar28 = iVar10 + 0x100;
      if ((char)param_1[0x1726] == '\0') {
        iVar28 = iVar10;
      }
      iVar10 = iVar28 + 0x1a8 + (uint)(uVar7 >> 5) * 4;
      if ((char)param_1[0x1740] != '\0') {
        iVar10 = iVar10 + (*(ushort *)((longlong)param_1 + 0x99c) + 0x664 +
                          (*(int *)((longlong)param_1 + 0xba04) * 7 +
                          (uint)*(ushort *)(param_1 + 0x1741)) * 2) * 4;
      }
      iVar28 = (int)param_1[0x2e3] + (int)param_1[0x2e0] + (int)param_1[0x2dd];
      iVar10 = iVar28 + 0x1400 + iVar10;
      local_48 = uVar20;
      local_40 = uVar9;
      while( true ) {
        lVar12 = StorPortGetUncachedExtension(param_1,param_5,iVar10);
        *param_1 = lVar12;
        if (lVar12 != 0) break;
        if (iVar28 == 0) {
          if (*(byte *)((longlong)param_1 + 0x5ca) < 5) {
            if (*(byte *)((longlong)param_1 + 0x5c9) < 0xd) {
              LogSystemEvent((longlong)param_1,0xad010004,0xc004af02,
                             (byte *)"System did not give miniport the non cached memory",0,1);
              return 2;
            }
            LogSystemEvent((longlong)param_1,0xad010004,0xc004af02,
                           (byte *)
                           "SAS Topo Event Que forced to default & non-cached extn alloc retried",0,
                           1);
            bVar3 = *(byte *)((longlong)param_1 + 0x5c9);
            *(undefined1 *)((longlong)param_1 + 0x5c9) = 0xc;
            iVar19 = (bVar3 - 0xc) * (uint)*(ushort *)(param_1 + 0x134) * uVar9;
            *(int *)((longlong)param_1 + 0x5cc) = *(int *)((longlong)param_1 + 0x5cc) - iVar19;
            iVar10 = iVar10 - iVar19;
          }
          else {
            LogSystemEvent((longlong)param_1,0xad010004,0xc004af02,
                           (byte *)
                           "PCIe Topo Event Que forced to default & non-cached extn alloc retried",0
                           ,1);
            bVar3 = *(byte *)((longlong)param_1 + 0x5ca);
            *(undefined1 *)((longlong)param_1 + 0x5ca) = 4;
            iVar19 = (bVar3 - 4) * (uint)*(ushort *)(param_1 + 0x134) * uVar20;
            *(int *)(param_1 + 0xba) = (int)param_1[0xba] - iVar19;
            iVar10 = iVar10 - iVar19;
          }
        }
        else {
          LogSystemEvent((longlong)param_1,0xad010004,0xc004af02,
                         (byte *)
                         "FW Diag Buffer support disabled and non-cached extn allocation retried",0,
                         1);
          iVar10 = iVar10 - iVar28;
          iVar28 = 0;
          *(undefined1 *)(param_1 + 0x2de) = 0;
          *(undefined1 *)(param_1 + 0x2e1) = 0;
          *(undefined1 *)(param_1 + 0x2e4) = 0;
        }
      }
      uVar14 = StorPortGetPhysicalAddress(param_1,0,lVar12,&local_3c);
      *(int *)((longlong)param_1 + 500) = (int)(uVar14 >> 0x20);
      local_3c = (uint)uVar14 & 0x7f;
      uVar23 = (ulonglong)(0x80 - local_3c);
      if ((uVar14 & 0x7f) == 0) {
        uVar23 = 0;
      }
      param_1[1] = *param_1 + uVar23;
      uVar9 = (uint)uVar14 + (int)uVar23;
      *(uint *)(param_1 + 0x3e) = uVar9;
      param_1[0x21] = (*param_1 + uVar23) - (ulonglong)uVar9;
      *(undefined1 *)((longlong)param_1 + 0x11e5) = 0;
      LsiMpiPartitionMemory((longlong)param_1,0,1);
      RttInitTrace(param_1 + 0xbb,1);
      InitSysLogErrorFIFO((longlong)param_1);
      uVar15 = BringIOCToOperationalState((longlong)param_1,0,1);
      cVar5 = (char)uVar15;
      while (cVar5 != '\0') {
        LitInit((longlong)param_1);
        if (((((char)param_1[0x2de] == '\0') && ((int)param_1[0x2dd] == 0)) &&
            ((char)param_1[0x173d] == '\0')) && (*(short *)((longlong)param_1 + 0xb9ec) != 0)) {
          AllocateDefaultHTB((longlong)param_1,0,1);
        }
        ZeroMemory((void *)((longlong)param_1 + 0xbbb4),0x10);
        if ((char)param_1[0x1740] != '\0') {
          SetUpInterruptCoalescing((longlong)param_1,0,1);
        }
        uVar9 = 0;
        while ((*(char *)((longlong)param_1 + 0x11dc) != '\0' ||
               (*(char *)((longlong)param_1 + 0x11dd) != '\0'))) {
          PollLSImpiIsr((longlong)param_1,0,1);
          StorPortStallExecution(500);
          uVar9 = uVar9 + 1;
          if (239999 < uVar9) {
            *(undefined2 *)((longlong)param_1 + 0x11dc) = 0;
            if (((char)param_1[0xc1] != '\0') &&
               ((*(uint *)((longlong)param_1 + 0x60c) & 0x276) != 0)) {
              RttLogEvent((longlong)param_1,(char *)((longlong)param_1 + 0x11d7),
                          (ulonglong *)(param_1 + 0xbb),0x276,(undefined1 *)0x0,0,0,1);
            }
            LogSystemEvent((longlong)param_1,0xad01004e,0xc004af02,
                           (byte *)"Device Mapping Aborted, Device Map Timeout during HBA Init",0,1)
            ;
            goto LAB_140003cc8;
          }
        }
        MapSODChecks((longlong)param_1,0,1);
        CompressEnclosureTable((longlong)param_1);
        if ((*(char *)((longlong)param_1 + 0x11e5) != '\0') ||
           (*(char *)((longlong)param_1 + 0x11e4) == '\0')) {
LAB_140003cc8:
          *(undefined1 *)((longlong)param_1 + 0x11e5) = 1;
          *(undefined1 *)((longlong)param_1 + 0x118d) = *(undefined1 *)(param_5 + 0x49);
          if (((char)param_1[0xc1] != '\0') && ((*(uint *)((longlong)param_1 + 0x60c) & 0x400) != 0)
             ) {
            RttLogEvent((longlong)param_1,(char *)((longlong)param_1 + 0x11d7),
                        (ulonglong *)(param_1 + 0xbb),0x400,(undefined1 *)0x0,0,0,1);
          }
          *(undefined1 *)((longlong)param_1 + 0x1211) = 0;
          StorPortNotification(6,param_1,WatchdogTimer,1000000);
          return 1;
        }
        *(undefined2 *)((longlong)param_1 + 0x11e4) = 0x100;
        FlushAllDPMPage0((longlong)param_1,0,1);
        if ((*(uint *)((longlong)param_1 + 0x120c) & 0x2000) == 0) {
          LogOperationalEvent((longlong)param_1,(int *)((longlong)param_1 + 0x120c),4,0x4004af00,
                              "Diag Reset(miniport)-FW doesn\'t support event replay,IOC capability logged"
                              ,0,1);
          KickStart((longlong)param_1,0,1);
        }
        else {
          IssueReset((longlong)param_1,0x40);
        }
        LsiMpiPartitionMemory((longlong)param_1,0,1);
        RttInitTrace(param_1 + 0xbb,1);
        InitSysLogErrorFIFO((longlong)param_1);
        uVar15 = BringIOCToOperationalState((longlong)param_1,0,1);
        cVar5 = (char)uVar15;
      }
      pcVar27 = "IOC would not come to the Operational state";
      uVar21 = 0xad010006;
LAB_140002bb2:
      LogSystemEvent((longlong)param_1,uVar21,0xc004af02,(byte *)pcVar27,0,1);
      return 2;
    }
  }
  pcVar27 = "could not get the chips BARs correctly";
  uVar21 = 0xad010001;
LAB_140003e4e:
  LogSystemEvent((longlong)param_1,uVar21,0xc004af02,(byte *)pcVar27,0,1);
  return 0;
}



===== LSImpiHWInitialize @ 140003e90 =====

ulonglong LSImpiHWInitialize(longlong param_1)

{
  ulonglong uVar1;
  undefined4 local_res10 [6];
  
  uVar1 = InternalLSImpiHWInitialize(param_1,0,2);
  local_res10[0] = 0;
  StorPortNotification(0x1000,param_1,LSImpiPassiveInitialize,local_res10);
  return uVar1 & 0xff;
}



===== LSImpiOSReset @ 140003ee0 =====

ulonglong LSImpiOSReset(longlong param_1,uint param_2)

{
  byte bVar1;
  uint local_res10 [6];
  int local_18;
  undefined1 local_14;
  uint *local_10;
  
  local_18 = 6;
  local_14 = 0;
  if (param_2 < *(ushort *)(param_1 + 0x9a4)) {
    local_10 = local_res10;
    local_res10[0] = param_2;
    AcquireIsrLocks(param_1,0,6);
    bVar1 = SynchronizeReset(param_1,&local_18);
    ReleaseIsrLocks(param_1,0,6);
    return (ulonglong)bVar1;
  }
  return (ulonglong)(byte)(*(ushort *)(param_1 + 0x9a4) >> 8) << 8;
}



===== LSImpiStartIo @ 140003f60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 LSImpiStartIo(longlong param_1,ushort *param_2)

{
  byte *pbVar1;
  ushort uVar2;
  int *piVar3;
  longlong *plVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 uVar8;
  byte bVar9;
  longlong *plVar10;
  ushort uVar11;
  uint uVar12;
  undefined8 *puVar13;
  undefined4 uVar14;
  bool bVar15;
  undefined1 local_a8 [32];
  byte local_68;
  undefined1 local_67;
  char local_66;
  byte local_65;
  ushort local_64 [2];
  int local_60;
  undefined1 local_5c;
  ushort *local_58;
  byte local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  ushort local_4c;
  ushort local_4a;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_a8;
  piVar3 = *(int **)(param_2 + 0x34);
  local_64[0] = 0;
  local_60 = 4;
  local_5c = 0;
  if ((char)param_2[1] != '(') {
    *(undefined1 *)((longlong)param_2 + 3) = 0x22;
    StorPortNotification(0,param_1,param_2);
    return 0;
  }
  local_68 = *(byte *)((longlong)piVar3 + 0x62);
  uVar11 = (ushort)local_68;
  local_67 = (undefined1)piVar3[0x19];
  local_66 = (char)piVar3[0x18];
  local_65 = *(byte *)((longlong)piVar3 + 0x61);
  pbVar1 = (byte *)((longlong)piVar3 + 0x62);
  local_58 = param_2;
  switch(*(undefined4 *)(param_2 + 10)) {
  case 0:
    if ((*(char *)(param_1 + 0x11f0) != '\0') &&
       (*(undefined1 *)(param_1 + 0x11f0) = 0, local_66 == '\x03')) {
      memmove(*(void **)(param_2 + 0x20),*(void **)(param_1 + 0x11f8),
              (ulonglong)*(uint *)(param_2 + 0x1e));
      *(undefined1 *)((longlong)param_2 + 3) = 1;
      *(undefined1 *)(*(longlong *)(piVar3 + 0x10) + 8) = 0;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x409) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x409,pbVar1,3
                    ,0,4);
      }
      goto LAB_1400048c3;
    }
    if (*(char *)(param_1 + 0x11d2) != '\0') {
      *(undefined1 *)((longlong)param_2 + 3) = 0x11;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x213) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x213,pbVar1,3
                    ,0,4);
      }
      goto LAB_1400048c3;
    }
    if ((*(int *)(param_1 + 0x968) != 0) || (*(int *)(param_1 + 0x1218) != 0)) {
      *(undefined1 *)((longlong)param_2 + 3) = 5;
      if (((*(char *)(param_1 + 0x96c) == '\0') &&
          (*(undefined1 *)(param_1 + 0x96c) = 1, *(char *)(param_1 + 0x608) != '\0')) &&
         ((*(uint *)(param_1 + 0x60c) & 0x214) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x214,pbVar1,3
                    ,0,4);
      }
      goto LAB_1400048c3;
    }
    if (*(char *)(param_1 + 0xbbd0) == '\0') {
      uVar6 = GetHostReqTag(param_1,local_64);
      if ((char)uVar6 == '\0') {
        *(undefined1 *)((longlong)param_2 + 3) = 5;
        StorPortBusy(param_1,10);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x215) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x215,pbVar1
                      ,3,0,4);
        }
        if (*(short *)(param_1 + 0x960) != 0) {
          LogSystemEvent(param_1,0xad010012,0x8004af01,
                         (byte *)"IO returned for lack of Host Request Tag",0,4);
        }
        goto LAB_1400048c3;
      }
      puVar13 = (undefined8 *)((ulonglong)local_64[0] * 0x20 + *(longlong *)(param_1 + 0x598));
    }
    else {
      do {
        plVar4 = *(longlong **)(param_1 + 0x910);
        if (*(longlong *)(*plVar4 + 8) != 0) {
          *(undefined1 *)((longlong)param_2 + 3) = 5;
          StorPortBusy(param_1,10);
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x215) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x215,
                        pbVar1,3,0,4);
          }
          if (*(short *)(param_1 + 0x960) != 0) {
            LogSystemEvent(param_1,0xad010012,0x8004af01,
                           (byte *)"IO returned with BUSY (Saved_SRB not NULL)",0,4);
          }
          StorPortNotification(0,param_1,param_2);
          break;
        }
        plVar10 = plVar4 + 1;
        if (plVar10 == *(longlong **)(param_1 + 0x920)) {
          plVar10 = *(longlong **)(param_1 + 0x908);
        }
        LOCK();
        bVar15 = plVar4 == *(longlong **)(param_1 + 0x910);
        if (bVar15) {
          *(longlong **)(param_1 + 0x910) = plVar10;
        }
        UNLOCK();
      } while (!bVar15);
      puVar13 = (undefined8 *)*plVar4;
    }
    puVar13[1] = param_2;
    *(undefined1 *)((longlong)puVar13 + 0x13) = 0;
    *(byte *)((longlong)puVar13 + 0x12) = local_68;
    uVar11 = *(ushort *)(puVar13 + 2);
    uVar2 = *(ushort *)(piVar3 + 0x5a);
    *(undefined1 *)((longlong)puVar13 + 0x16) = local_67;
    *(ushort *)((longlong)puVar13 + 0x14) = uVar2;
    *(char *)((longlong)puVar13 + 0x17) = (char)param_2[0x10];
    if (local_66 == '\x12') {
      if ((local_65 & 1) != 0) goto LAB_1400043e9;
      *(undefined4 *)(puVar13 + 3) = 4;
      local_50 = *pbVar1;
      local_4f = *(undefined1 *)((longlong)piVar3 + 99);
      local_4e = (undefined1)piVar3[0x19];
      local_4c = uVar11;
      local_4a = uVar2;
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x2000) == 0))
      goto LAB_1400043e9;
      uVar14 = 0x2000;
    }
    else {
      if (local_66 != -0x60) goto LAB_1400043e9;
      local_50 = *pbVar1;
      local_4f = *(undefined1 *)((longlong)piVar3 + 99);
      local_4e = (undefined1)piVar3[0x19];
      local_4c = uVar11;
      local_4a = uVar2;
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x2002) == 0))
      goto LAB_1400043e9;
      uVar14 = 0x2002;
    }
    local_4c = uVar11;
    local_4a = uVar2;
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar14,&local_50,8
                ,0,4);
LAB_1400043e9:
    memmove((void *)*puVar13,piVar3 + 0x5a,(ulonglong)*(ushort *)(param_1 + 0x534));
    uVar12 = (uint)uVar11 * 0x10000 + *piVar3;
    if (*(char *)(param_1 + 0xbbc5) == '\0') {
      **(ulonglong **)(param_1 + 0xe8) = (ulonglong)uVar2 << 0x30 | (ulonglong)uVar12;
    }
    else {
      **(uint **)(param_1 + 0xf8) = uVar12;
    }
    LOCK();
    UNLOCK();
    if (*(char *)(param_1 + 0xba00) != '\0') {
      LOCK();
      piVar3 = (int *)(*(longlong *)(param_1 + 0xba30) +
                      ((ulonglong)*pbVar1 * 0x80 + (ulonglong)*(byte *)((longlong)piVar3 + 99)) * 4)
      ;
      *piVar3 = *piVar3 + 1;
      UNLOCK();
    }
    *(undefined1 *)(param_1 + 0x96c) = 0;
    return 1;
  case 2:
    AcquireIsrLocks(param_1,0,4);
    SynchronizeStartIoctl(param_1,&local_60);
    ReleaseIsrLocks(param_1,0,4);
    return 1;
  case 7:
    if (*(int *)(param_1 + 0x970) != 0) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x80006) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80006,
                    (undefined1 *)param_2,*(uint *)(param_2 + 8),0,4);
      }
      *(ushort **)(param_1 + 0x928) = param_2;
      CheckForNvmeShutdown(param_1,'\x01',0,4);
      *(undefined2 *)(param_1 + 0xb664) = 7;
      SendAndProcessSSUCommands(param_1,0,4);
      *(undefined2 *)(param_1 + 0xb664) = *(undefined2 *)(param_1 + 0xb668);
      return 1;
    }
    break;
  case 0x12:
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x406) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x406,
                  (undefined1 *)0x0,0,0,4);
      uVar11 = (ushort)local_68;
    }
    if (*(ushort *)(param_1 + 0x9a4) <= uVar11) {
      *(undefined1 *)((longlong)param_2 + 3) = 7;
      StorPortNotification(0,param_1,param_2);
      return 0;
    }
    *(ushort **)(param_1 + 0x930) = param_2;
    local_58 = (ushort *)&local_68;
    AcquireIsrLocks(param_1,0,4);
    uVar5 = SynchronizeReset(param_1,&local_60);
    goto LAB_1400045a3;
  case 0x13:
  case 0x20:
    AcquireIsrLocks(param_1,0,4);
    uVar8 = SynchronizeLunTargetReset(param_1,&local_60);
    uVar5 = (undefined1)uVar8;
LAB_1400045a3:
    ReleaseIsrLocks(param_1,0,4);
    return uVar5;
  case 0x17:
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x403) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x403,
                  (undefined1 *)param_2,0x80,0,4);
    }
    uVar8 = LSImpiWmiSrb(param_1,param_2,0,4);
    return (char)uVar8;
  case 0x24:
    if (*(int *)(*(longlong *)(piVar3 + 0x12) + 0xc) == 4) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x80001) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80001,
                    (undefined1 *)param_2,*(uint *)(param_2 + 8),0,4);
      }
      *(ushort **)(param_1 + 0x928) = param_2;
      if ((*(int *)(param_1 + 0x970) != 0) &&
         (uVar8 = CheckForNvmeShutdown(param_1,'\0',0,4), (char)uVar8 != '\0')) {
        return 1;
      }
      uVar14 = 0xd;
      if (*(short *)(param_1 + 0xb664) != 0) {
        uVar14 = 8;
      }
      *(undefined4 *)(param_1 + 0x1218) = uVar14;
      return 1;
    }
  default:
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x217) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x217,
                  (undefined1 *)param_2,*(uint *)(param_2 + 8),0,4);
    }
    break;
  case 0x25:
    if (*(uint *)(param_2 + 0x1c) != 0) {
      uVar6 = 0;
      do {
        uVar12 = *(uint *)(param_2 + uVar6 * 2 + 0x3c);
        if (((0x7f < uVar12) && (uVar12 < *(uint *)(param_2 + 8))) &&
           (lVar7 = (longlong)param_2 + (ulonglong)uVar12,
           *(int *)((longlong)param_2 + (ulonglong)uVar12) == 0x62)) goto LAB_14000472b;
        bVar9 = (char)uVar6 + 1;
        uVar6 = (ulonglong)bVar9;
      } while ((uint)bVar9 < *(uint *)(param_2 + 0x1c));
    }
    lVar7 = 0;
LAB_14000472b:
    if (*(int *)(lVar7 + 0xc) == 4) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x80007) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80007,
                    (undefined1 *)0x0,0,0,4);
      }
      *(undefined1 *)((longlong)param_2 + 3) = 1;
    }
    else {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x285) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x285,
                    (undefined1 *)(lVar7 + 0xc),4,0,4);
      }
      *(undefined1 *)((longlong)param_2 + 3) = 0x22;
    }
    goto LAB_1400048c3;
  }
  *(undefined1 *)((longlong)param_2 + 3) = 0x22;
LAB_1400048c3:
  StorPortNotification(0,param_1,param_2);
  return 1;
}



===== ProcessIncomingIOs @ 140004950 =====

ulonglong ProcessIncomingIOs(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  ulonglong *puVar9;
  undefined8 *puVar10;
  uint uVar11;
  ushort local_res8 [4];
  
  piVar5 = *(int **)(param_2 + 0x68);
  local_res8[0] = 0;
  uVar1 = *(undefined1 *)((longlong)piVar5 + 0x62);
  iVar6 = piVar5[0x19];
  iVar7 = piVar5[0x18];
  bVar2 = *(byte *)((longlong)piVar5 + 0x61);
  if ((*(char *)(param_1 + 0x11f0) == '\0') ||
     (*(undefined1 *)(param_1 + 0x11f0) = 0, (char)iVar7 != '\x03')) {
    if (*(char *)(param_1 + 0x11d2) == '\0') {
      if ((*(int *)(param_1 + 0x968) == 0) && (*(int *)(param_1 + 0x1218) == 0)) {
        uVar8 = GetHostReqTag(param_1,local_res8);
        if ((char)uVar8 == '\0') {
LAB_140004a41:
          return CONCAT71((int7)(uVar8 >> 8),1);
        }
        puVar10 = (undefined8 *)((ulonglong)local_res8[0] * 0x20 + *(longlong *)(param_1 + 0x598));
        if (puVar10[1] != 0) {
          uVar8 = LogSystemEvent(param_1,0xad010012,0x8004af01,
                                 (byte *)"ItSas35:Saved_SRB is not NULL in ProcessIncomingIOs \n",0,
                                 3);
          goto LAB_140004a41;
        }
        puVar10[1] = param_2;
        *(undefined1 *)((longlong)puVar10 + 0x13) = 0;
        *(undefined1 *)((longlong)puVar10 + 0x12) = uVar1;
        uVar3 = *(ushort *)(piVar5 + 0x5a);
        *(ushort *)((longlong)puVar10 + 0x14) = uVar3;
        *(char *)((longlong)puVar10 + 0x16) = (char)iVar6;
        uVar4 = *(ushort *)(puVar10 + 2);
        *(undefined1 *)((longlong)puVar10 + 0x17) = *(undefined1 *)(param_2 + 0x20);
        if (((char)iVar7 == '\x12') && ((bVar2 & 1) == 0)) {
          *(undefined4 *)(puVar10 + 3) = 4;
        }
        memmove((void *)*puVar10,piVar5 + 0x5a,(ulonglong)*(ushort *)(param_1 + 0x534));
        uVar11 = (uint)uVar4 * 0x10000 + *piVar5;
        if (*(char *)(param_1 + 0xbbc5) == '\0') {
          puVar9 = *(ulonglong **)(param_1 + 0xe8);
          *puVar9 = (ulonglong)uVar3 << 0x30 | (ulonglong)uVar11;
        }
        else {
          puVar9 = *(ulonglong **)(param_1 + 0xf8);
          *(uint *)puVar9 = uVar11;
        }
        LOCK();
        UNLOCK();
        if (*(char *)(param_1 + 0xba00) != '\0') {
          puVar9 = *(ulonglong **)(param_1 + 0xba30);
          LOCK();
          piVar5 = (int *)((longlong)puVar9 +
                          ((ulonglong)*(byte *)((longlong)piVar5 + 0x62) * 0x80 +
                          (ulonglong)*(byte *)((longlong)piVar5 + 99)) * 4);
          *piVar5 = *piVar5 + 1;
          UNLOCK();
        }
        *(undefined1 *)(param_1 + 0x96c) = 0;
        goto LAB_140004b22;
      }
      *(undefined1 *)(param_2 + 3) = 5;
      if (*(char *)(param_1 + 0x96c) == '\0') {
        *(undefined1 *)(param_1 + 0x96c) = 1;
      }
    }
    else {
      *(undefined1 *)(param_2 + 3) = 0x11;
    }
  }
  else {
    memmove(*(void **)(param_2 + 0x40),*(void **)(param_1 + 0x11f8),
            (ulonglong)*(uint *)(param_2 + 0x3c));
    *(undefined1 *)(param_2 + 3) = 1;
    *(undefined1 *)(*(longlong *)(piVar5 + 0x10) + 8) = 0;
  }
  puVar9 = (ulonglong *)StorPortNotification(0,param_1,param_2);
LAB_140004b22:
  return (ulonglong)puVar9 & 0xffffffffffffff00;
}



===== SetUpIntCoalPerfParameters @ 140004b40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SetUpIntCoalPerfParameters(longlong param_1)

{
  int iVar1;
  int *piVar2;
  ulonglong uVar3;
  byte bVar4;
  ulonglong uVar5;
  ushort uVar6;
  longlong lVar7;
  uint uVar8;
  bool bVar9;
  undefined1 auStack_48 [32];
  ushort local_28 [8];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  ZeroMemory(local_28,0x10);
  *(undefined4 *)(param_1 + 0x13c) = 0x28;
  *(undefined4 *)(param_1 + 0x138) = 6;
  uVar3 = StorPortExtendedFunction(0xe,param_1,1,param_1 + 0x138);
  if ((int)uVar3 == 0) {
    bVar9 = (*(uint *)(param_1 + 0x140) & 1) != 0;
    if (bVar9) {
      *(undefined1 *)(param_1 + 0x132) = 1;
    }
    uVar3 = StorPortExtendedFunction(0xd,param_1,0x7f,param_1 + 0x110);
    if (((((*(uint *)(param_1 + 0x140) & 0xc) != 0) && (*(char *)(param_1 + 0xba00) != '\0')) &&
        (*(void **)(param_1 + 0xba18) != (void *)0x0)) && ((int)uVar3 == 0)) {
      *(undefined4 *)(param_1 + 0x148) = 0;
      *(undefined4 *)(param_1 + 0x14c) = 0x7f;
      ZeroMemory(*(void **)(param_1 + 0xba18),0x800);
      *(undefined8 *)(param_1 + 0x158) = *(undefined8 *)(param_1 + 0xba18);
      *(uint *)(param_1 + 0x140) = bVar9 | 0xc;
      uVar3 = StorPortExtendedFunction(0xe,param_1,0,param_1 + 0x138);
      if ((int)uVar3 == 0) {
        if (*(char *)(param_1 + 0xba00) != '\0') {
          uVar8 = 0;
          lVar7 = 0;
          do {
            if (*(uint *)(param_1 + 0xba04) != 0) {
              uVar5 = 0;
              do {
                if ((*(short *)(uVar5 * 0x38 + 0x10 + *(longlong *)(param_1 + 0xba20)) ==
                     *(short *)(*(longlong *)(param_1 + 0xba18) + 8 + lVar7)) &&
                   ((*(ulonglong *)(*(longlong *)(param_1 + 0xba18) + lVar7) &
                    *(ulonglong *)(uVar5 * 0x38 + 8 + *(longlong *)(param_1 + 0xba20))) != 0)) {
                  uVar3 = *(ulonglong *)(param_1 + 0xba38 + uVar5 * 8);
                  *(uint *)(uVar3 + (ulonglong)local_28[uVar5] * 4) = uVar8;
                  local_28[uVar5] = local_28[uVar5] + 1;
                  break;
                }
                bVar4 = (char)uVar5 + 1;
                uVar3 = (ulonglong)bVar4;
                uVar5 = uVar3;
              } while ((uint)bVar4 < *(uint *)(param_1 + 0xba04));
            }
            bVar4 = (char)uVar8 + 1;
            uVar8 = (uint)bVar4;
            lVar7 = lVar7 + 0x10;
          } while (bVar4 < 0x80);
          uVar5 = 0;
          if (*(int *)(param_1 + 0xba04) != 0) {
            do {
              bVar9 = false;
              piVar2 = *(int **)(param_1 + 0xba38 + uVar5 * 8);
              iVar1 = *piVar2;
              for (uVar3 = uVar3 & 0xffffffffffffff00;
                  (bVar4 = (byte)uVar3, iVar1 != -0x21524111 && (bVar4 < 0x80));
                  uVar3 = CONCAT71((int7)(uVar3 >> 8),bVar4 + 1)) {
                if ((*(int *)(param_1 + 0xba10) - 1U < (uint)piVar2[uVar3 & 0xff]) && (!bVar9)) {
                  *(byte *)(uVar5 + 0xbad8 + param_1) = bVar4;
                  bVar9 = true;
                  if (bVar4 < 7) {
                    *(undefined1 *)(param_1 + 0xba00) = 0;
                    goto LAB_140004d72;
                  }
                }
                iVar1 = piVar2[(byte)(bVar4 + 1)];
              }
              uVar6 = (short)uVar5 + 1;
              uVar3 = (ulonglong)uVar6;
              *(byte *)(uVar5 + 0xbb20 + param_1) = bVar4;
              uVar5 = uVar3;
            } while ((uint)uVar6 < *(uint *)(param_1 + 0xba04));
          }
        }
        return CONCAT71((int7)(uVar3 >> 8),1);
      }
    }
    *(undefined1 *)(param_1 + 0xba00) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0xba00) = 0;
  }
LAB_140004d72:
  return uVar3 & 0xffffffffffffff00;
}



===== SetUpInterruptCoalescing @ 140004da0 =====

void SetUpInterruptCoalescing(longlong param_1,byte param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  byte bVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  ushort uVar9;
  char *pcVar10;
  ushort uVar11;
  int local_res8 [2];
  
  uVar9 = 0;
  if (*(short *)(param_1 + 0xba08) != 0) {
    do {
      iVar2 = StorPortExtendedFunction
                        (0x13,param_1,uVar9,*(longlong *)(param_1 + 0xba28) + (ulonglong)uVar9 * 8);
      if (iVar2 != 0) goto LAB_14000506f;
      cVar1 = RtlFindMostSignificantBit
                        (*(undefined8 *)((ulonglong)uVar9 * 8 + *(longlong *)(param_1 + 0xba28)));
      uVar9 = uVar9 + 1;
      *(short *)(param_1 + 0xba0a) = *(short *)(param_1 + 0xba0a) + cVar1 + 1;
    } while (uVar9 < *(ushort *)(param_1 + 0xba08));
  }
  uVar9 = 0;
  uVar3 = 0;
  if (*(int *)(param_1 + 0xba04) != 0) {
    uVar8 = 0;
    do {
      pcVar10 = (char *)(*(longlong *)(param_1 + 0xba20) + (ulonglong)uVar9 * 0x38);
      iVar2 = StorPortExtendedFunction(0x15,param_1,uVar8,pcVar10 + 8);
      if (iVar2 != 0) {
LAB_14000506f:
        *(undefined1 *)(param_1 + 0xba00) = 0;
        return;
      }
      cVar1 = RtlFindLeastSignificantBit(*(undefined8 *)(pcVar10 + 8));
      pcVar10[1] = cVar1;
      cVar1 = RtlFindMostSignificantBit(*(undefined8 *)(pcVar10 + 8));
      pcVar10[2] = cVar1;
      local_res8[0] = (uint)(*(ushort *)(param_1 + 0xba0a) >> 6) * 8 + 0x50;
      *(char *)(param_1 + 0xbb32) = pcVar10[2];
      *(undefined2 *)(param_1 + 0xbb30) = *(undefined2 *)(pcVar10 + 0x10);
      iVar2 = StorPortExtendedFunction
                        (0x17,param_1,(undefined2 *)(param_1 + 0xbb30),3,
                         *(undefined8 *)(param_1 + 0xbb28),local_res8);
      if (iVar2 != 0) goto LAB_14000506f;
      uVar11 = 0;
      if (*(short *)(*(longlong *)(param_1 + 0xbb28) + 0x1e) != 0) {
        do {
          uVar6 = (ulonglong)uVar11;
          uVar11 = uVar11 + 1;
          *(undefined8 *)
           (pcVar10 +
           (ulonglong)*(ushort *)(*(longlong *)(param_1 + 0xbb28) + 0x28 + uVar6 * 0x10) * 8 + 0x18)
               = *(undefined8 *)(*(longlong *)(param_1 + 0xbb28) + 0x20 + uVar6 * 0x10);
        } while (uVar11 < *(ushort *)(*(longlong *)(param_1 + 0xbb28) + 0x1e));
      }
      cVar1 = *(char *)(param_1 + 0xba0c);
      if ((uVar9 != 0) &&
         (iVar2 = memcmp(pcVar10 + 0x18,
                         (void *)(*(longlong *)(param_1 + 0xba20) + -0x20 + (ulonglong)uVar9 * 0x38)
                         ,0x20), iVar2 != 0)) {
        cVar1 = cVar1 + '\x01';
        *(char *)(param_1 + 0xba0c) = cVar1;
      }
      *pcVar10 = cVar1;
      lVar7 = *(longlong *)(param_1 + 0xba78 + (ulonglong)*(ushort *)(pcVar10 + 0x10) * 8);
      uVar6 = (ulonglong)(byte)pcVar10[1];
      if ((byte)pcVar10[1] <= (byte)pcVar10[2]) {
        do {
          uVar11 = (short)uVar6 + 1;
          *(char *)(uVar6 + lVar7) = (char)uVar9;
          uVar6 = (ulonglong)uVar11;
        } while (uVar11 <= (byte)pcVar10[2]);
      }
      uVar3 = *(uint *)(param_1 + 0xba04);
      uVar9 = uVar9 + 1;
      uVar8 = (uint)uVar9;
    } while (uVar8 < uVar3);
  }
  *(char *)(param_1 + 0xba0c) = *(char *)(param_1 + 0xba0c) + '\x01';
  uVar9 = 0;
  bVar5 = *(byte *)(param_1 + 0xba0c);
  if (uVar3 != 0) {
    do {
      lVar7 = 4;
      puVar4 = *(undefined8 **)(param_1 + 0xba38 + (ulonglong)uVar9 * 8);
      do {
        *puVar4 = 0xdeadbeefdeadbeef;
        puVar4[1] = 0xdeadbeefdeadbeef;
        puVar4[2] = 0xdeadbeefdeadbeef;
        puVar4[3] = 0xdeadbeefdeadbeef;
        puVar4[4] = 0xdeadbeefdeadbeef;
        puVar4[5] = 0xdeadbeefdeadbeef;
        puVar4[6] = 0xdeadbeefdeadbeef;
        puVar4[7] = 0xdeadbeefdeadbeef;
        puVar4[8] = 0xdeadbeefdeadbeef;
        puVar4[9] = 0xdeadbeefdeadbeef;
        puVar4[10] = 0xdeadbeefdeadbeef;
        puVar4[0xb] = 0xdeadbeefdeadbeef;
        puVar4[0xc] = 0xdeadbeefdeadbeef;
        puVar4[0xd] = 0xdeadbeefdeadbeef;
        puVar4[0xe] = 0xdeadbeefdeadbeef;
        puVar4[0xf] = 0xdeadbeefdeadbeef;
        lVar7 = lVar7 + -1;
        puVar4 = puVar4 + 0x10;
      } while (lVar7 != 0);
      uVar9 = uVar9 + 1;
    } while ((uint)uVar9 < *(uint *)(param_1 + 0xba04));
    bVar5 = *(byte *)(param_1 + 0xba0c);
  }
  if (bVar5 < 5) {
    if (*(char *)(param_1 + 0xba00) != '\0') {
      return;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xba00) = 0;
  }
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x116) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x116,
                (undefined1 *)0x0,0,param_2,param_3);
  }
  LogSystemEvent(param_1,0xad01009f,0x4004af00,
                 (byte *)"Int Coalescing is disabled for Aero HBAs ,perf mode is latency",param_2,
                 param_3);
  *(undefined4 *)(param_1 + 0xbbd4) = 2;
  return;
}



===== SynchronizeLunTargetReset @ 140005120 =====

undefined8 SynchronizeLunTargetReset(longlong param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  ushort *puVar6;
  ulonglong uVar7;
  ulonglong in_RAX;
  ulonglong uVar8;
  char cVar9;
  ushort uVar10;
  undefined4 uVar11;
  longlong lVar12;
  uint local_res8 [2];
  
  lVar4 = *(longlong *)(param_2 + 2);
  iVar2 = *param_2;
  local_res8[0] = 0;
  if ((lVar4 == 0) || (lVar5 = *(longlong *)(lVar4 + 0x68), lVar5 == 0)) {
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x23c) != 0)) {
      in_RAX = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x23c,
                           (undefined1 *)0x0,0,0,iVar2);
    }
    return in_RAX & 0xffffffffffffff00;
  }
  uVar8 = 0;
  if (*(int *)(lVar4 + 0x14) == 0x20) {
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x404) != 0)) {
      uVar8 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x404,
                          (undefined1 *)(lVar5 + 0x62),3,0,iVar2);
    }
  }
  else {
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x405) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x405,
                  (undefined1 *)(lVar5 + 0x62),3,0,iVar2);
    }
    uVar8 = 0;
    local_res8[0] =
         (uint)CONCAT21(CONCAT11(*(undefined1 *)(lVar5 + 0x62),*(undefined1 *)(lVar5 + 99)),
                        *(undefined1 *)(lVar5 + 100));
  }
  if (*(int *)(param_1 + 0x1218) == 0) {
    if ((*(int *)(param_1 + 0x968) == 0) && (*(longlong *)(param_1 + 0x928) == 0)) {
      uVar10 = (ushort)*(byte *)(lVar5 + 0x62) * 0x80 + (ushort)*(byte *)(lVar5 + 99);
      if ((uint)uVar10 < *(uint *)(param_1 + 0x9bc)) {
        lVar12 = (ulonglong)uVar10 * 0x2c;
        uVar10 = *(ushort *)(lVar12 + 0x1a + *(longlong *)(param_1 + 0x5c0));
        if (uVar10 != 0) {
          if (*(int *)(param_1 + 0x970) == 0) {
            PauseAdapterQueue(param_1,1,0,iVar2);
          }
          *(longlong *)(param_1 + 0x928) = lVar4;
          ResetActive(param_1,10,0,iVar2);
          uVar3 = *(uint *)(lVar4 + 0x14);
          uVar8 = (ulonglong)uVar3;
          if (uVar3 == 0x13) {
            if ((*(char *)(param_1 + 0x608) != '\0') &&
               ((*(uint *)(param_1 + 0x60c) & 0x20006) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20006,
                          (byte *)(lVar5 + 0x62),3,0,iVar2);
            }
            puVar6 = *(ushort **)(param_1 + 0x568);
            ZeroMemory(puVar6,0x34);
            *puVar6 = uVar10;
            *(undefined1 *)((longlong)puVar6 + 3) = 1;
            *(undefined1 *)((longlong)puVar6 + 5) = 3;
            if (((*(char *)(lVar12 + 0x24 + *(longlong *)(param_1 + 0x5c0)) != '\0') &&
                (*(char *)(param_1 + 0x18b0) == '\0')) &&
               ((*(uint *)(lVar12 + 0x14 + *(longlong *)(param_1 + 0x5c0)) & 4) == 0)) {
              *(undefined1 *)((longlong)puVar6 + 7) = 0x18;
            }
            uVar10 = *(ushort *)(param_1 + 0x9b2);
            LogOperationalEvent(param_1,(int *)local_res8,4,0x4004af00,
                                "Issuing OS initiated Target Reset,Adapter Queue paused,BTL logged",
                                0,iVar2);
            uVar8 = QueueRequestDescriptor(param_1,(uint)uVar10 * 0x10000 + 6,0,0,iVar2);
          }
          else if (uVar3 == 0x20) {
            uVar8 = SendLunResetTur(param_1,uVar10,0,iVar2);
          }
          goto LAB_140005458;
        }
      }
      *(undefined1 *)(lVar4 + 3) = 10;
      uVar8 = StorPortNotification(0,param_1,lVar4);
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x20012) == 0))
      goto LAB_140005458;
      uVar11 = 0x20012;
    }
    else if (lVar4 == *(longlong *)(param_1 + 0x928)) {
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x20003) == 0))
      goto LAB_140005458;
      uVar11 = 0x20003;
    }
    else {
      uVar10 = 0;
      do {
        uVar8 = (ulonglong)uVar10;
        if (*(longlong *)(param_1 + 0x13b8 + uVar8 * 8) == lVar4) {
          if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x20004) == 0))
          goto LAB_140005458;
          uVar11 = 0x20004;
          goto LAB_140005450;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < 100);
      bVar1 = *(byte *)(param_1 + 0x12af);
      if (*(longlong *)(param_1 + 0x13b8 + (ulonglong)bVar1 * 8) != 0) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x216) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x216,
                      (undefined1 *)0x0,0,0,iVar2);
        }
        LogSystemEvent(param_1,0xad01003a,0x8004af01,(byte *)"LUN/Target reset queue is full",0,
                       iVar2);
        goto LAB_140005597;
      }
      *(longlong *)(param_1 + 0x13b8 + (ulonglong)bVar1 * 8) = lVar4;
      uVar8 = 0;
      cVar9 = '\0';
      if (bVar1 != 99) {
        cVar9 = bVar1 + 1;
      }
      *(char *)(param_1 + 0x12af) = cVar9;
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x20000) == 0))
      goto LAB_140005458;
      uVar11 = 0x20000;
    }
  }
  else {
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20002) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20002,
                  (undefined1 *)0x0,0,0,iVar2);
    }
LAB_140005597:
    uVar7 = 0;
    do {
      uVar8 = uVar7;
      if (*(longlong *)(param_1 + 0x13b8 + uVar8 * 8) == lVar4) goto LAB_1400055f3;
      uVar10 = (short)uVar8 + 1;
      uVar7 = (ulonglong)uVar10;
    } while (uVar10 < 100);
    if (lVar4 == *(longlong *)(param_1 + 0x928)) {
LAB_1400055f3:
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x23b) == 0))
      goto LAB_140005458;
      uVar11 = 0x23b;
    }
    else {
      *(undefined1 *)(lVar4 + 3) = 4;
      uVar8 = StorPortNotification(0,param_1,lVar4);
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x20012) == 0))
      goto LAB_140005458;
      uVar11 = 0x20012;
    }
  }
LAB_140005450:
  uVar8 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar11,
                      (undefined1 *)0x0,0,0,iVar2);
LAB_140005458:
  return CONCAT71((int7)(uVar8 >> 8),1);
}



===== SynchronizeStartIoctl @ 1400056e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SynchronizeStartIoctl(longlong param_1,int *param_2)

{
  byte bVar1;
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
  bVar1 = *(byte *)(param_2 + 1);
  local_28 = 0;
  local_2c = 0;
  local_30 = *(undefined4 *)(*(longlong *)((longlong)pvVar4 + 0x40) + 0x10);
  local_38 = pvVar4;
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400000) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400000,
                (undefined1 *)&local_38,0x11,bVar1,iVar3);
  }
  if ((*(char *)(param_1 + 0x11b6) == '\0') && (*(char *)(param_1 + 0x11d4) == '\0')) {
    if ((((*(char *)(param_1 + 0x1220) == '\0') && (*(int *)(param_1 + 0x968) == 0)) &&
        (*(int *)(param_1 + 0x1218) == 0)) && (*(char *)(param_1 + 0x18f4) == '\0')) {
      uVar5 = LsiHandleAppRequest(param_1,pvVar4,bVar1,iVar3);
      return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
    }
    bVar2 = *(byte *)(param_1 + 0x12ad);
    if ((*(int *)(param_1 + 0x1218) == 0) &&
       (*(longlong *)(param_1 + 0x12b8 + (ulonglong)bVar2 * 8) == 0)) {
      *(void **)(param_1 + 0x12b8 + (ulonglong)bVar2 * 8) = pvVar4;
      uVar6 = 0;
      cVar8 = '\0';
      if (bVar2 != 0x1f) {
        cVar8 = bVar2 + 1;
      }
      *(char *)(param_1 + 0x12ad) = cVar8;
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x400007) == 0))
      goto LAB_1400058be;
      uVar7 = 0x400007;
    }
    else {
      local_28 = 5;
      *(undefined1 *)((longlong)pvVar4 + 3) = 5;
      uVar6 = StorPortNotification(0,param_1,pvVar4);
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x40001b) == 0))
      goto LAB_1400058be;
      uVar7 = 0x40001b;
    }
  }
  else {
    local_28 = 5;
    *(undefined1 *)((longlong)pvVar4 + 3) = 5;
    uVar6 = StorPortNotification(0,param_1,pvVar4);
    if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x40001a) == 0))
    goto LAB_1400058be;
    uVar7 = 0x40001a;
  }
  uVar6 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar7,
                      (undefined1 *)&local_38,0x11,bVar1,iVar3);
LAB_1400058be:
  return uVar6 & 0xffffffffffffff00;
}



===== AcquireIsrLocks @ 1400058f0 =====

void AcquireIsrLocks(longlong param_1,byte param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  longlong lVar3;
  byte bVar4;
  ulonglong uVar5;
  bool bVar6;
  
  if ((*(int *)(param_1 + 0x970) == 0) && (*(char *)(param_1 + 0x11ee) != '\0')) {
    if (param_3 == 5) {
      lVar3 = *(longlong *)(param_1 + 0x11c8);
      if (*(char *)(lVar3 + (ulonglong)param_2) == '\0') {
        do {
          LOCK();
          bVar6 = *(int *)(param_1 + 0x11c0) == 0;
          if (bVar6) {
            *(int *)(param_1 + 0x11c0) = 1;
          }
          UNLOCK();
        } while (!bVar6);
        lVar3 = *(longlong *)(param_1 + 0x11c8);
      }
      pcVar1 = (char *)((ulonglong)param_2 + lVar3);
      *pcVar1 = *pcVar1 + '\x01';
      return;
    }
    cVar2 = *(char *)(param_1 + 0x11d7);
    *(char *)(param_1 + 0x11d7) = cVar2 + '\x01';
    if ((cVar2 == '\0') && (uVar5 = 0, *(char *)(param_1 + 0x133) != '\0')) {
      do {
        StorPortExtendedFunction(0xb,param_1,uVar5,param_1 + (uVar5 + 0x8a) * 4);
        bVar4 = (char)uVar5 + 1;
        uVar5 = (ulonglong)bVar4;
      } while (bVar4 < *(byte *)(param_1 + 0x133));
    }
  }
  return;
}



===== FindMappingTableEntry @ 1400059b0 =====

longlong FindMappingTableEntry(longlong param_1,short param_2,short param_3,uint param_4)

{
  longlong lVar1;
  ushort uVar2;
  
  uVar2 = param_2 * 0x80 + param_3;
  if ((((uint)uVar2 < *(uint *)(param_1 + 0x9bc)) &&
      (lVar1 = (ulonglong)uVar2 * 0x2c + *(longlong *)(param_1 + 0x5c0),
      *(short *)(lVar1 + 0x1a) != 0)) && ((*(uint *)(lVar1 + 0x14) & param_4) != 0)) {
    return lVar1;
  }
  return 0;
}



===== HandleFwDiagReply @ 140005a00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HandleFwDiagReply(longlong param_1,longlong param_2,byte param_3,int param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  char *pcVar4;
  ushort uVar5;
  undefined1 auStackY_98 [32];
  longlong local_58;
  int local_50;
  uint local_4c;
  undefined1 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  if (*(char *)(param_2 + 3) == '\x1d') {
    *(undefined1 *)(param_1 + 0x11db) = 0;
    uVar5 = *(ushort *)(param_2 + 0xe) & 0x7fff;
    lVar1 = param_1 + ((ulonglong)*(byte *)(param_2 + 1) + 0xf4) * 0x18;
    if (uVar5 == 0xa0) {
      *(undefined1 *)(lVar1 + 0xf) = 0;
      *(undefined2 *)(lVar1 + 0x11) = 1;
    }
    else {
      *(undefined2 *)(lVar1 + 0x11) = 0x101;
      if (uVar5 != 0) {
        *(undefined2 *)(lVar1 + 0x11) = 0;
        LogSystemEvent(param_1,0xad01002a,0xc004af02,
                       (byte *)"FW diagnostic buffer post failed (HandleFwDiagReply)",param_3,
                       param_4);
      }
    }
    if (((*(char *)(lVar1 + 0xf) == '\0') && (uVar5 != 0xa0)) &&
       (local_58 = *(longlong *)(param_1 + 0x1750), local_58 != 0)) {
      lVar1 = *(longlong *)(local_58 + 0x40);
      local_50 = *(int *)(lVar1 + 0x10);
      if (local_50 == -0x7f9b969f) {
        local_4c = -(uint)(uVar5 != 0) & 0x10;
        *(uint *)(lVar1 + 0x14) = -(uint)(uVar5 != 0) & 0x10;
        local_48 = 1;
        *(undefined1 *)(local_58 + 3) = 1;
        StorPortNotification(0,param_1);
        *(undefined8 *)(param_1 + 0x1750) = 0;
        local_50 = *(int *)(lVar1 + 0x10);
      }
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400021) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400021,
                    (undefined1 *)&local_58,0x11,param_3,param_4);
      }
      *(undefined1 *)(param_1 + 0x1220) = 0;
      CheckIoctlQueue(param_1,param_3,param_4);
    }
  }
  else if (*(char *)(param_2 + 3) == '\x1e') {
    local_58 = *(longlong *)(param_1 + 0x1750);
    lVar1 = param_1 + ((ulonglong)*(byte *)(param_2 + 1) + 0xf4) * 0x18;
    uVar5 = *(ushort *)(param_2 + 0xe) & 0x7fff;
    if (local_58 == 0) {
      if (uVar5 == 0) {
        *(undefined1 *)(lVar1 + 0x12) = 0;
        pcVar4 = "HTB release cmd sent by driver is successful (HandleFwDiagReply)";
        uVar3 = 0x4004af00;
      }
      else {
        uVar3 = 0x8004af01;
        pcVar4 = "HTB release cmd sent by driver is unsuccessful (HandleFwDiagReply)";
      }
      LogSystemEvent(param_1,0,uVar3,(byte *)pcVar4,param_3,param_4);
    }
    else {
      lVar2 = *(longlong *)(local_58 + 0x40);
      if ((uVar5 == 0) && (*(char *)(lVar1 + 0x12) != '\0')) {
        local_4c = 0;
        *(undefined4 *)(lVar2 + 0x14) = 0;
        *(undefined1 *)(lVar1 + 0x12) = 0;
      }
      else {
        local_4c = 0x12;
        *(undefined4 *)(lVar2 + 0x14) = 0x12;
      }
      if (*(int *)(lVar2 + 0x1c) == 2) {
        *(undefined4 *)(lVar1 + 0x14) = 0;
      }
      local_48 = 1;
      *(undefined1 *)(local_58 + 3) = 1;
      StorPortNotification(0,param_1);
      *(undefined8 *)(param_1 + 0x1750) = 0;
      local_50 = *(undefined4 *)(lVar2 + 0x10);
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400022) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400022,
                    (undefined1 *)&local_58,0x11,param_3,param_4);
      }
      *(undefined1 *)(param_1 + 0x1220) = 0;
      CheckIoctlQueue(param_1,param_3,param_4);
    }
  }
  return;
}



===== LSImpiIsr @ 140005cf0 =====

void LSImpiIsr(longlong param_1)

{
  LSImpiMSIIsr(param_1,0);
  return;
}



===== LSImpiMSIIsr @ 140005d00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong LSImpiMSIIsr(longlong param_1,byte param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint *puVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  uint uVar10;
  longlong *plVar11;
  uint *puVar12;
  byte bVar13;
  ushort uVar14;
  uint uVar15;
  ulonglong uVar16;
  longlong lVar17;
  ulonglong uVar18;
  undefined1 local_f8 [32];
  ushort local_a8 [2];
  char local_a4;
  ushort local_a2;
  char local_a0 [2];
  ushort local_9e;
  longlong local_98;
  uint local_90;
  longlong *local_88;
  uint *local_80;
  longlong local_78;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  ushort local_6c;
  undefined1 local_68;
  undefined1 local_67;
  ushort local_66;
  undefined1 local_64 [36];
  uint *local_40;
  
  puVar5 = (uint *)(__security_cookie ^ (ulonglong)local_f8);
  uVar2 = *(uint *)(param_1 + 0x900);
  local_98 = 0;
  local_9e = *(ushort *)(param_1 + 0x53a);
  local_a4 = '\0';
  lVar17 = 0;
  local_88 = (longlong *)0x0;
  if ((*(char *)(param_1 + 0x11d5) != '\0') ||
     ((*(int *)(param_1 + 0x1218) != 0 && (*(char *)(param_1 + 0x11d7) == '\0')))) {
LAB_140006a58:
    return (ulonglong)puVar5 & 0xffffffffffffff00;
  }
  if (*(char *)(param_1 + 0x132) == '\0') {
    param_2 = 0;
  }
  uVar18 = (ulonglong)param_2;
  uVar4 = *(ushort *)(param_1 + 0x428 + uVar18 * 2);
  local_a2 = 0;
  local_78 = *(longlong *)(param_1 + 0x550) + local_9e * uVar18 * 8;
  local_40 = puVar5;
  do {
    uVar16 = (ulonglong)uVar4;
    plVar11 = local_88;
    lVar7 = local_98;
    while( true ) {
      lVar9 = local_78;
      uVar15 = (uint)uVar16;
      uVar8 = (uint)param_2;
      local_90 = uVar15;
      if (*(ushort *)(param_1 + 0x998) / 3 < (uint)local_a2) {
        if (*(byte *)(param_1 + 0x133) < 0x11) {
          puVar5 = *(uint **)(param_1 + 0x60);
          uVar3 = uVar8;
        }
        else {
          puVar5 = *(uint **)(param_1 + 0x60 + (ulonglong)(param_2 >> 3) * 8);
          uVar3 = uVar8 & 7;
        }
        *puVar5 = uVar3 << 0x18 | uVar15;
        LOCK();
        UNLOCK();
        if (*(char *)(param_1 + 0x131) == '\0') {
          ReadRegisterUlong(param_1,*(int **)(param_1 + 0x60));
          lVar7 = local_98;
        }
      }
      puVar12 = (uint *)(lVar9 + uVar16 * 8);
      uVar3 = *puVar12;
      puVar5 = (uint *)(ulonglong)uVar3;
      uVar10 = uVar3 >> 0x10;
      local_80 = puVar12;
      if ((uVar3 == 0xffffffff) || (puVar12[1] == 0xffffffff)) {
        if (local_a2 != 0) {
          *(short *)(param_1 + 0x428 + uVar18 * 2) = (short)uVar16;
          if (*(byte *)(param_1 + 0x133) < 0x11) {
            puVar5 = *(uint **)(param_1 + 0x60);
          }
          else {
            uVar8 = param_2 & 7;
            puVar5 = *(uint **)(param_1 + 0x60 + (ulonglong)(param_2 >> 3) * 8);
          }
          *puVar5 = uVar8 << 0x18 | uVar15;
          LOCK();
          UNLOCK();
          if (*(char *)(param_1 + 0x131) == '\0') {
            puVar5 = (uint *)ReadRegisterUlong(param_1,*(int **)(param_1 + 0x60));
          }
        }
        if (local_a4 != '\0') {
          puVar5 = (uint *)ReleaseIsrLocks(param_1,param_2,uVar2);
        }
        if (local_a2 != 0) {
          return CONCAT71((int7)((ulonglong)puVar5 >> 8),1);
        }
        goto LAB_140006a58;
      }
      local_a8[0] = (ushort)(uVar3 >> 0x10);
      if (local_a8[0] != 0) {
        plVar11 = (longlong *)((ulonglong)local_a8[0] * 0x20 + *(longlong *)(param_1 + 0x598));
        local_88 = plVar11;
        if (*(char *)((longlong)plVar11 + 0x13) != '\x02') {
          lVar7 = plVar11[1];
          local_98 = lVar7;
        }
      }
      bVar13 = (byte)*puVar12 & 0xf;
      if (((8 < bVar13) || ((0x141U >> bVar13 & 1) == 0)) ||
         ((plVar11 != (longlong *)0x0 && ((int)plVar11[3] != 0)))) break;
      if (lVar7 == 0) {
        if (local_a8[0] < *(ushort *)(param_1 + 0x9ae)) {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x219) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x219,
                        (undefined1 *)local_a8,2,param_2,uVar2);
          }
          LogSystemEvent(param_1,0xad010024,0xc004af02,
                         (byte *)"NULL Srb pointer (ISR) returned by IOC",param_2,uVar2);
          goto LAB_140006028;
        }
      }
      else {
        lVar17 = *(longlong *)(lVar7 + 0x68);
        *(undefined1 *)(*(longlong *)(lVar17 + 0x40) + 8) = 0;
        *(undefined1 *)(lVar7 + 3) = 1;
        if (*(char *)(lVar17 + 0x60) == -0x60) {
          local_70 = *(undefined1 *)(lVar17 + 0x62);
          local_6f = *(undefined1 *)(lVar17 + 99);
          local_6e = *(undefined1 *)(lVar17 + 100);
          local_6c = local_a8[0];
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2003) != 0))
          {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2003,
                        &local_70,6,param_2,uVar2);
            lVar7 = local_98;
          }
        }
        if ((*(char *)(param_1 + 0xba00) != '\0') &&
           (lVar9 = (ulonglong)*(byte *)(lVar17 + 0x62) * 0x80 + (ulonglong)*(byte *)(lVar17 + 99),
           0 < *(int *)(*(longlong *)(param_1 + 0xba30) + lVar9 * 4))) {
          LOCK();
          piVar1 = (int *)(*(longlong *)(param_1 + 0xba30) + lVar9 * 4);
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        StorPortNotification(0,param_1,lVar7);
        *(byte *)((longlong)plVar11 + 0x13) = *(byte *)((longlong)plVar11 + 0x13) | 1;
        ReturnFreeTrackingArrayEntry(param_1,(longlong)plVar11,param_2,uVar2);
LAB_140006028:
        lVar7 = local_98;
      }
      local_a2 = local_a2 + 1;
      uVar4 = (short)local_90 + 1;
      uVar16 = 0;
      puVar12[0] = 0xffffffff;
      puVar12[1] = 0xffffffff;
      if (uVar4 != local_9e) {
        uVar16 = (ulonglong)uVar4;
      }
    }
    if (local_a4 == '\0') {
      AcquireIsrLocks(param_1,param_2,uVar2);
      uVar10 = (uint)local_a8[0];
      local_a4 = '\x01';
    }
    puVar5 = (uint *)0x0;
    if (bVar13 == 1) {
      puVar5 = (uint *)((ulonglong)puVar12[1] + *(longlong *)(param_1 + 0x108));
    }
    if ((short)uVar10 != 0) {
      if (puVar5 != (uint *)0x0) {
        if (local_88 != (longlong *)0x0) {
          if (*(char *)(*local_88 + 3) != *(char *)((longlong)puVar5 + 3)) {
            lVar7 = *(longlong *)(param_1 + 0x928);
            if (lVar7 != 0) {
              lVar17 = *(longlong *)(lVar7 + 0x68);
              local_98 = lVar7;
              if ((lVar17 != 0) && (*(char *)(lVar17 + 0x65) != '\0')) goto LAB_1400061d6;
            }
            ZeroMemory(&local_68,0x24);
            uVar4 = local_a8[0];
            local_68 = *(undefined1 *)(*local_88 + 3);
            local_67 = *(undefined1 *)((longlong)puVar5 + 3);
            local_66 = local_a8[0];
            if ((local_98 != 0) && (lVar17 = *(longlong *)(local_98 + 0x68), lVar17 != 0)) {
              memmove(local_64,*(void **)(lVar17 + 0x58),0x20);
            }
            if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x271) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x271,
                          &local_68,0x24,param_2,uVar2);
              uVar4 = local_a8[0];
            }
            LogSystemEvent(param_1,CONCAT31(CONCAT21(uVar4,*(undefined1 *)((longlong)puVar5 + 3)),
                                            local_68),0xc004af02,
                           (byte *)
                           "MPI Protocol Violation:Function Mismatch between Request and Reply",
                           param_2,uVar2);
            puVar12 = local_80;
            if (*(char *)(param_1 + 0x11bc) != '\0') {
              *(undefined4 *)(param_1 + 0x187c) = _DAT_0000badd;
            }
          }
        }
      }
LAB_1400061d6:
      uVar6 = CheckHbaFwReply(param_1,(longlong)puVar12,param_2,uVar2);
      if ((char)uVar6 == '\0') {
        uVar6 = CheckMpiIoctlReply(param_1,(byte *)puVar12,param_2,uVar2);
        if ((char)uVar6 == '\0') {
          uVar6 = CheckInqFlagReplies(param_1,local_a0,(byte *)puVar12,param_2,uVar2);
          if ((char)uVar6 == '\0') {
            lVar7 = CheckSsuReplies(param_1,(longlong)puVar12);
            if ((char)lVar7 == '\0') {
              lVar7 = CheckSsuTmrReplies(param_1,(longlong)puVar12);
              if ((char)lVar7 == '\0') {
                uVar6 = CheckTurReplies(param_1,(byte *)puVar12,param_2,uVar2);
                if ((char)uVar6 == '\0') {
                  uVar6 = CheckPfaSataReplies(param_1,puVar12,param_2,uVar2);
                  if ((char)uVar6 == '\0') {
                    uVar10 = (uint)local_a8[0];
                    goto LAB_14000649f;
                  }
                  goto LAB_1400068d3;
                }
                if ((*(char *)(param_1 + 0x608) != '\0') &&
                   ((*(uint *)(param_1 + 0x60c) & 0x10c) != 0)) {
                  RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                              0x10c,(undefined1 *)local_a8,2,param_2,uVar2);
                }
              }
              else if ((*(char *)(param_1 + 0x608) != '\0') &&
                      ((*(uint *)(param_1 + 0x60c) & 0x10b) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x10b,
                            (undefined1 *)local_a8,2,param_2,uVar2);
              }
            }
            else if ((*(char *)(param_1 + 0x608) != '\0') &&
                    ((*(uint *)(param_1 + 0x60c) & 0x10a) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x10a,
                          (undefined1 *)local_a8,2,param_2,uVar2);
            }
          }
          else {
            if (local_a0[0] == '\0') {
              if ((*(char *)(param_1 + 0x608) != '\0') &&
                 ((*(uint *)(param_1 + 0x60c) & 0x109) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x109,
                            (undefined1 *)local_a8,2,param_2,uVar2);
              }
              goto LAB_1400068d3;
            }
            if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x108) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x108,
                          (undefined1 *)local_a8,2,param_2,uVar2);
            }
          }
        }
      }
      else if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x113) != 0))
      {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x113,
                    (undefined1 *)local_a8,2,param_2,uVar2);
      }
      goto LAB_1400068a0;
    }
LAB_14000649f:
    if (puVar5 == (uint *)0x0) {
      LogSystemEvent(param_1,0xad010022,0x8004af01,(byte *)"Unexpected reply from FW",param_2,uVar2)
      ;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x239) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x239,
                    (undefined1 *)0x0,0,param_2,uVar2);
      }
    }
    else {
      if (local_98 != 0) {
        lVar17 = *(longlong *)(local_98 + 0x68);
      }
      uVar8 = puVar5[4];
      if (((((uVar8 == 0) || (-1 < (short)*(ushort *)((longlong)puVar5 + 0xe))) ||
           (uVar8 == 0x30030501)) || ((uVar8 == 0x30030101 || (uVar8 == 0x31180000)))) ||
         ((uVar8 == 0x30070001 || ((uVar8 & 0xffff0000) == 0x31170000)))) {
        if (lVar17 != 0) goto LAB_140006553;
      }
      else {
        AfdMpiLogInfoTrigger(param_1,uVar8,*(ushort *)((longlong)puVar5 + 0xe),param_2,uVar2);
        if (lVar17 == 0) {
LAB_1400065c2:
          uVar10 = (uint)local_a8[0];
        }
        else {
          LitLogInfoReceived(param_1,uVar8,(short)*puVar5,*(undefined1 *)(lVar17 + 0x62),
                             *(undefined1 *)(lVar17 + 99),*(undefined1 *)(lVar17 + 100),param_2,
                             uVar2);
          uVar10 = (uint)local_a8[0];
LAB_140006553:
          if (*(char *)(lVar17 + 0x60) == -0x60) {
            local_70 = *(undefined1 *)(lVar17 + 0x62);
            local_6f = *(undefined1 *)(lVar17 + 99);
            local_6e = *(undefined1 *)(lVar17 + 100);
            local_6c = (ushort)uVar10;
            if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2004) != 0)
               ) {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2004,
                          &local_70,6,param_2,uVar2);
              goto LAB_1400065c2;
            }
          }
        }
      }
      uVar4 = (ushort)uVar10;
      switch(*(undefined1 *)((longlong)puVar5 + 3)) {
      case 1:
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x806) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x806,
                      (undefined1 *)local_a8,2,param_2,uVar2);
          uVar10 = (uint)local_a8[0];
        }
        uVar4 = (ushort)uVar10;
        if (((*(char *)((longlong)puVar5 + 5) != '\x02') || (uVar4 == 0)) ||
           (-1 < (char)*(undefined4 *)
                        ((ulonglong)uVar10 * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598))))
        goto LAB_140006672;
        lVar17 = *(longlong *)(local_98 + 0x68);
        uVar6 = HandleUnitAttenReset
                          (param_1,uVar4,(undefined8 *)puVar5,*(byte *)(lVar17 + 0x62),
                           *(byte *)(lVar17 + 99),*(char *)(lVar17 + 100),'\0',param_2,uVar2);
        if ((char)uVar6 != '\0') goto LAB_1400068d3;
        break;
      default:
        uVar6 = LsiCompleteIO(param_1,(short *)puVar5,uVar4,param_2,uVar2);
        if ((char)uVar6 != '\0') break;
        goto LAB_1400068d3;
      case 4:
        if ((*(uint *)((ulonglong)uVar10 * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) & 8) == 0)
        goto LAB_140006672;
        uVar6 = HbaApiWmiCompletion(param_1,(longlong)puVar5,uVar4,param_2,uVar2);
        if ((char)uVar6 == '\0') {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x80a) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80a,
                        (undefined1 *)local_a8,2,param_2,uVar2);
          }
          goto LAB_1400068d3;
        }
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x809) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x809,
                      (undefined1 *)local_a8,2,param_2,uVar2);
        }
        break;
      case 7:
        HandleEventNotification(param_1,puVar5,param_2,uVar2);
        break;
      case 0x1b:
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x805) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x805,
                      (undefined1 *)local_a8,2,param_2,uVar2);
          uVar4 = local_a8[0];
        }
LAB_140006672:
        NonSCB_Func_handler(param_1,(short *)puVar5,uVar4,param_2,uVar2);
        break;
      case 0x1d:
      case 0x1e:
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x807) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x807,
                      (undefined1 *)local_a8,2,param_2,uVar2);
          uVar4 = local_a8[0];
        }
        if (uVar4 == 0) goto LAB_1400068d3;
        HandleFwDiagReply(param_1,(longlong)puVar5,param_2,uVar2);
      }
LAB_1400068a0:
      if ((local_a8[0] != 0) && (local_a8[0] <= *(ushort *)(param_1 + 0x998))) {
        local_88 = (longlong *)((ulonglong)local_a8[0] * 0x20 + *(longlong *)(param_1 + 0x598));
        ReturnFreeTrackingArrayEntry(param_1,(longlong)local_88,param_2,uVar2);
      }
LAB_1400068d3:
      puVar12 = local_80;
      if (bVar13 == 1) {
        uVar4 = *(ushort *)(param_1 + 0x224);
        *(uint *)(*(longlong *)(param_1 + 0x548) + (ulonglong)uVar4 * 4) = local_80[1];
        uVar4 = uVar4 + 1;
        uVar14 = 0;
        if (uVar4 != *(ushort *)(param_1 + 0x538)) {
          uVar14 = uVar4;
        }
        **(uint **)(param_1 + 0x58) = (uint)uVar14;
        LOCK();
        UNLOCK();
        *(ushort *)(param_1 + 0x224) = uVar14;
      }
    }
    local_a2 = local_a2 + 1;
    uVar14 = (short)local_90 + 1;
    uVar4 = 0;
    if (uVar14 != local_9e) {
      uVar4 = uVar14;
    }
    puVar12[0] = 0xffffffff;
    puVar12[1] = 0xffffffff;
  } while( true );
}



===== LsiCompleteIO @ 140006ab0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 LsiCompleteIO(longlong param_1,short *param_2,ushort param_3,byte param_4,int param_5)

{
  int *piVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  longlong lVar4;
  char *pcVar5;
  byte bVar6;
  uint uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  short sVar10;
  undefined4 *puVar11;
  longlong lVar12;
  ushort uVar13;
  longlong lVar14;
  char cVar15;
  longlong lVar16;
  undefined4 uVar17;
  undefined1 auStackY_118 [32];
  ushort *puVar18;
  uint uVar19;
  byte local_c8;
  byte local_c7;
  byte local_c6;
  char local_c5;
  ushort local_c4 [2];
  longlong local_c0;
  char local_b8;
  ushort local_b0 [4];
  uint local_a8;
  undefined8 *local_a0;
  byte local_98;
  byte local_97;
  char local_96;
  byte local_95;
  undefined1 local_94;
  undefined1 local_93;
  ushort local_92;
  undefined2 local_90;
  undefined4 local_88;
  undefined4 local_84;
  short local_80;
  ushort local_7e;
  undefined2 local_78;
  undefined1 local_76;
  undefined1 local_74;
  char local_73;
  undefined2 local_72;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_63;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c4[0] = param_2[7] & 0x7fff;
  local_b0[0] = param_3;
  if (*(char *)((longlong)param_2 + 3) == '3') {
    uVar8 = CompleteNvmeEncapCommand(param_1,(longlong)param_2,param_3,param_4,param_5);
    return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  if (*(char *)((longlong)param_2 + 3) != '\0') {
    uVar8 = NonSCB_Func_handler(param_1,param_2,param_3,param_4,param_5);
    return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  local_a0 = (undefined8 *)((ulonglong)param_3 * 0x20 + *(longlong *)(param_1 + 0x598));
  lVar4 = local_a0[1];
  if (lVar4 == 0) {
    if (param_3 < *(ushort *)(param_1 + 0x9ae)) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x219) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x219,
                    (undefined1 *)local_b0,2,param_4,param_5);
      }
      local_a0 = (undefined8 *)
                 LogSystemEvent(param_1,0xad010024,0xc004af02,
                                (byte *)"NULL Srb pointer in CompleteIO",param_4,param_5);
    }
    return CONCAT71((int7)((ulonglong)local_a0 >> 8),1);
  }
  local_c8 = *(byte *)(param_2 + 6);
  lVar12 = *(longlong *)(lVar4 + 0x68);
  local_c6 = *(byte *)(lVar12 + 0x62);
  local_c7 = *(byte *)(lVar12 + 99);
  local_c5 = *(char *)(lVar12 + 100);
  uVar17 = *(undefined4 *)(lVar4 + 0x3c);
  local_b8 = *(char *)(lVar12 + 0x60);
  local_a8 = *(uint *)(lVar4 + 0x18);
  local_c0 = *(longlong *)(lVar12 + 0x40);
  switch(local_c4[0]) {
  case 0:
  case 0x40:
    *(undefined1 *)(lVar4 + 3) = 1;
    break;
  case 1:
    *(undefined1 *)(lVar4 + 3) = 6;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x225) != 0)) {
      uVar17 = 0x225;
      uVar19 = 0;
      puVar18 = (ushort *)0x0;
LAB_14000702f:
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar17,
                  (undefined1 *)puVar18,uVar19,param_4,param_5);
    }
    break;
  case 3:
  case 6:
  case 7:
  case 0x46:
  case 0x47:
  case 0x4a:
    *(undefined1 *)(lVar4 + 3) = 4;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x227) != 0)) {
      uVar17 = 0x227;
LAB_140007014:
      puVar18 = local_c4;
      uVar19 = 2;
      goto LAB_14000702f;
    }
    break;
  default:
    *(undefined1 *)(lVar4 + 3) = 4;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x228) != 0)) {
      uVar17 = 0x228;
      goto LAB_140007014;
    }
    break;
  case 0x42:
    *(undefined1 *)(lVar4 + 3) = 0x21;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x21e) != 0)) {
      puVar18 = (ushort *)&local_c7;
      uVar17 = 0x21e;
      uVar19 = 1;
      goto LAB_14000702f;
    }
    break;
  case 0x43:
    *(undefined1 *)(lVar4 + 3) = 10;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x21a) != 0)) {
      uVar17 = 0x21a;
      uVar19 = 0;
      puVar18 = (ushort *)0x0;
      goto LAB_14000702f;
    }
    break;
  case 0x44:
    *(undefined1 *)(lVar4 + 3) = 0x12;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x21b) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x21b,
                  (undefined1 *)0x0,0,param_4,param_5);
    }
    if ((*(byte *)((longlong)param_2 + 0xd) & 8) != 0) {
      *(undefined1 *)(lVar4 + 3) = 4;
      sVar10 = *param_2;
      local_84 = *(undefined4 *)(param_2 + 10);
      local_7e = local_c4[0];
      local_88 = uVar17;
      local_80 = sVar10;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x272) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x272,
                    (undefined1 *)&local_88,0xc,param_4,param_5);
        sVar10 = *param_2;
      }
      LogSystemEvent(param_1,CONCAT22(sVar10,local_c4[0]),0x8004af01,
                     (byte *)"LsiCompleteIO:Scsi State Terminated(DevHandle and IOC status logged)",
                     param_4,param_5);
    }
    break;
  case 0x45:
    if ((local_c8 - 8 & 0xdf) != 0) {
      *(undefined1 *)(lVar4 + 3) = 0x12;
      *(undefined4 *)(lVar4 + 0x3c) = *(undefined4 *)(param_2 + 10);
    }
    break;
  case 0x48:
    cVar15 = *(char *)(param_1 + 0x1984);
    if ((((cVar15 - 3U & 0xfd) == 0) || ((cVar15 - 1U & 0xfa) != 0)) || (cVar15 == '\x05')) {
LAB_140006f0a:
      *(undefined1 *)(lVar4 + 3) = 0xe;
    }
    else {
      *(undefined1 *)(lVar4 + 3) = 2;
      if ((*(char *)(param_1 + 0x18f6) != '\0') && (*(int *)(lVar4 + 0x28) == 36000)) {
        *(undefined4 *)(lVar4 + 0x28) = 0x8c96;
      }
    }
    break;
  case 0x49:
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x21d) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x21d,
                  (undefined1 *)0x0,0,param_4,param_5);
    }
  case 2:
    *(undefined1 *)(lVar4 + 3) = 5;
    if (((*(uint *)(param_2 + 8) & 0xffff0000) != 0x31160000) && (local_c8 != 0x18)) {
      local_c8 = 8;
    }
    if (*(int *)(lVar4 + 0x28) == 36000) {
      *(undefined4 *)(lVar4 + 0x28) = 35999;
    }
    break;
  case 0x4b:
    if (-1 < param_2[7]) goto LAB_140006f0a;
    if ((*(uint *)(param_2 + 8) & 0xffff0000) == 0x31120000) {
      if (*(char *)(param_1 + 0x11b2) == '\0') goto LAB_140006f0a;
      *(undefined1 *)(lVar4 + 3) = 4;
      *(undefined4 *)(lVar4 + 0x28) = *(undefined4 *)(param_2 + 8);
    }
    else {
      if ((*(uint *)(param_2 + 8) & 0xffff0000) != 0x31170000) goto LAB_140006f0a;
      *(undefined1 *)(lVar4 + 3) = 5;
      local_c8 = 8;
    }
    break;
  case 0x4c:
    *(undefined1 *)(lVar4 + 3) = 0xe;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x21f) != 0)) {
      uVar17 = 0x21f;
      uVar19 = 0;
      puVar18 = (ushort *)0x0;
      goto LAB_14000702f;
    }
    break;
  case 0x4d:
  case 0x4e:
  case 0x4f:
    *(undefined1 *)(lVar4 + 3) = 0xf;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x226) != 0)) {
      uVar17 = 0x226;
      uVar19 = 0;
      puVar18 = (ushort *)0x0;
      goto LAB_14000702f;
    }
  }
  cVar15 = local_b8;
  lVar14 = local_c0;
  bVar6 = *(byte *)((longlong)param_2 + 0xd);
  if (((bVar6 & 0x10) != 0) && ((char)*(undefined4 *)(param_2 + 0xe) == '\x02')) {
    *(undefined1 *)
     ((ulonglong)(ushort)((ushort)local_c6 * 0x80 + (ushort)local_c7) * 0x2c + 0x22 +
     *(longlong *)(param_1 + 0x5c0)) = 0;
    bVar6 = *(byte *)((longlong)param_2 + 0xd);
  }
  if ((bVar6 & 1) == 0) {
    if ((bVar6 & 2) == 0) {
      if ((((bVar6 & 0x10) != 0) && (*(char *)(lVar4 + 3) == '\x01')) &&
         (*(int *)(param_2 + 0xe) != 0)) {
        local_c8 = 0;
        *(undefined1 *)(lVar4 + 3) = 4;
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x22a) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x22a,
                      (undefined1 *)(param_2 + 0xe),4,param_4,param_5);
        }
        lVar14 = local_c0;
        goto LAB_1400074ee;
      }
    }
    else {
      *(undefined1 *)(lVar4 + 3) = 4;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x229) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x229,
                    (undefined1 *)0x0,0,param_4,param_5);
      }
    }
LAB_1400073f4:
    lVar14 = local_c0;
  }
  else {
    if ((local_a8 & 0x20) != 0) {
      memmove(*(void **)(param_1 + 0x11f8),(void *)(lVar12 + 0x68),0xff);
      *(undefined1 *)(param_1 + 0x11f0) = 1;
      *(undefined1 *)(lVar4 + 3) = 4;
      goto LAB_1400073f4;
    }
    *(undefined1 *)(lVar4 + 3) = 0x84;
    if ((local_b8 == -0x7b) || (local_b8 == -0x5f)) {
      uVar19 = *(uint *)(param_2 + 0xc);
    }
    else {
      uVar19 = *(uint *)(param_2 + 0xc);
      if (1 < (byte)(*(char *)(lVar12 + 0x68) + 0x8eU)) {
        bVar6 = *(byte *)(lVar12 + 0x6f);
        if (0xf4 < bVar6) {
          *(undefined1 *)(lVar12 + 0x6f) = 0xf4;
          bVar6 = 0xf4;
        }
        uVar19 = bVar6 + 8;
      }
    }
    uVar7 = (uint)*(byte *)(local_c0 + 9);
    if (uVar19 < *(byte *)(local_c0 + 9)) {
      *(char *)(local_c0 + 9) = (char)uVar19;
      uVar7 = uVar19 & 0xff;
    }
    memmove(*(void **)(local_c0 + 0x10),(void *)(lVar12 + 0x68),(ulonglong)uVar7);
    pcVar5 = *(char **)(lVar14 + 0x10);
    if ((cVar15 == -0x7b) || (cVar15 == -0x5f)) goto LAB_1400073f4;
    uVar3 = *(undefined2 *)((longlong)local_a0 + 0x14);
    lVar14 = *(longlong *)(lVar4 + 0x68);
    uVar2 = *(undefined1 *)(lVar14 + 100);
    if ((byte)(*pcVar5 + 0x8eU) < 2) {
      if (pcVar5[2] == ']') {
        cVar15 = pcVar5[3];
        goto LAB_140007154;
      }
    }
    else if (pcVar5[0xc] == ']') {
      cVar15 = pcVar5[0xd];
LAB_140007154:
      uVar13 = (ushort)*(byte *)(lVar14 + 0x62) * 0x80 + (ushort)*(byte *)(lVar14 + 99);
      if ((((uint)uVar13 < *(uint *)(param_1 + 0x9bc)) &&
          (puVar11 = (undefined4 *)((ulonglong)uVar13 * 0x2c + *(longlong *)(param_1 + 0x5c0)),
          *(short *)((longlong)puVar11 + 0x1a) != 0)) && ((puVar11[5] & 0x680) != 0)) {
        if (*(char *)(param_1 + 0x11b3) != '\0') {
          puVar11[5] = puVar11[5] | 0x80000000;
        }
        local_78 = 0xffff;
        local_76 = 5;
        local_74 = 0x5d;
        local_6c = *puVar11;
        local_68 = puVar11[1];
        local_73 = cVar15;
        local_72 = uVar3;
        local_63 = uVar2;
        SendMpiEventToApplication(param_1,0xf,&local_78,0x1c);
        if (*(char *)(param_1 + 0x11b3) != '\0') {
          SendSEPMessage(param_1,0x40,uVar3,param_4,param_5);
        }
      }
      else {
        LogSystemEvent(param_1,0xad01003f,0xc004af02,(byte *)"Device not mapped (CheckSmartInfo)",
                       param_4,param_5);
      }
    }
    if ((byte)(*pcVar5 + 0x8eU) < 2) {
      AfdScsiSenseTrigger(param_1,pcVar5[1] & 0xf,pcVar5[2],pcVar5[3],param_4,param_5);
      local_95 = *(byte *)(lVar12 + 0x69);
      local_94 = *(undefined1 *)(lVar12 + 0x6a);
      local_93 = *(undefined1 *)(lVar12 + 0x6b);
    }
    else {
      AfdScsiSenseTrigger(param_1,pcVar5[2] & 0xf,pcVar5[0xc],pcVar5[0xd],param_4,param_5);
      local_95 = *(byte *)(lVar12 + 0x6a);
      local_94 = *(undefined1 *)(lVar12 + 0x74);
      local_93 = *(undefined1 *)(lVar12 + 0x75);
    }
    lVar14 = local_c0;
    local_95 = local_95 & 0xf;
    if ((((pcVar5[2] & 0xfU) != 6) || (pcVar5[0xc] != ')')) &&
       (((pcVar5[1] & 0xfU) != 6 || (pcVar5[2] != 0x29)))) goto LAB_1400073f4;
    if (*(char *)(param_1 + 0x11ee) != '\0') {
      lVar16 = (ulonglong)(ushort)((ushort)local_c6 * 0x80 + (ushort)local_c7) * 0x2c +
               *(longlong *)(param_1 + 0x5c0);
      if ((*(uint *)(lVar16 + 0x14) & 0x400) != 0) {
        *(byte *)(local_c0 + 8) = local_c8;
        local_97 = local_c7;
        local_92 = local_b0[0];
        local_98 = local_c6;
        local_96 = local_c5;
        local_90 = *(undefined2 *)(lVar16 + 0x1a);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2000b) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2000b,
                      &local_98,10,param_4,param_5);
        }
        uVar9 = HandleUnitAttenReset
                          (param_1,local_b0[0],(undefined8 *)*local_a0,local_c6,local_c7,local_c5,
                           '\x01',param_4,param_5);
        if ((char)uVar9 != '\0') {
          return uVar9 & 0xffffffffffffff00;
        }
      }
    }
  }
  uVar19 = local_c8 - 0x18;
  if (((byte)uVar19 < 0x29) && ((0x10000000401U >> ((ulonglong)uVar19 & 0x3f) & 1) != 0)) {
    *(undefined1 *)(lVar4 + 3) = 4;
  }
  else if ((local_c8 - 8 & 0xdf) == 0) {
    *(undefined1 *)(lVar4 + 3) = 5;
  }
LAB_1400074ee:
  *(byte *)(lVar14 + 8) = local_c8;
  if ((*(char *)(param_1 + 0xba00) != '\0') &&
     (lVar12 = (ulonglong)*(byte *)(lVar12 + 0x62) * 0x80 + (ulonglong)*(byte *)(lVar12 + 99),
     0 < *(int *)(*(longlong *)(param_1 + 0xba30) + lVar12 * 4))) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0xba30) + lVar12 * 4);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
  }
  StorPortNotification(0,param_1,lVar4);
  *(byte *)((longlong)local_a0 + 0x13) = *(byte *)((longlong)local_a0 + 0x13) | 1;
  return CONCAT71((int7)((ulonglong)local_a0 >> 8),1);
}



===== PollLSImpiIsr @ 140007630 =====

void PollLSImpiIsr(longlong param_1,undefined1 param_2,int param_3)

{
  int local_18;
  undefined1 local_14;
  undefined8 local_10;
  
  *(int *)(param_1 + 0x900) = param_3;
  local_10 = 0;
  local_18 = param_3;
  local_14 = param_2;
  GtfProcessTimers(param_1,&local_18);
  LSImpiMSIIsr(param_1,0);
  *(undefined4 *)(param_1 + 0x900) = 5;
  return;
}



===== ReleaseIsrLocks @ 140007680 =====

void ReleaseIsrLocks(longlong param_1,byte param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char cVar5;
  
  if ((*(int *)(param_1 + 0x970) == 0) && (*(char *)(param_1 + 0x11ee) != '\0')) {
    if (param_3 == 5) {
      pcVar1 = (char *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x11c8));
      *pcVar1 = *pcVar1 + -1;
      if (*(char *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x11c8)) == '\0') {
        iVar3 = 1;
        LOCK();
        iVar2 = *(int *)(param_1 + 0x11c0);
        if (iVar2 == 1) {
          *(int *)(param_1 + 0x11c0) = 0;
        }
        else {
          iVar3 = iVar2;
        }
        UNLOCK();
        if (iVar3 == 0) {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x24e) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x24e,
                        (undefined1 *)0x0,0,param_2,5);
          }
          LogSystemEvent(param_1,0xad010099,0xc004af02,&s_ISR_Lock_violation_detected,param_2,5);
          return;
        }
      }
    }
    else {
      pcVar1 = (char *)(param_1 + 0x11d7);
      *pcVar1 = *pcVar1 + -1;
      if ((*pcVar1 == '\0') && (cVar5 = *(char *)(param_1 + 0x133) + -1, -1 < cVar5)) {
        puVar4 = (undefined4 *)(param_1 + ((longlong)cVar5 + 0x8a) * 4);
        do {
          StorPortExtendedFunction(0xc,param_1,cVar5,*puVar4);
          cVar5 = cVar5 + -1;
          puVar4 = puVar4 + -1;
        } while (-1 < cVar5);
      }
    }
  }
  return;
}



===== ReturnFreeTrackingArrayEntry @ 1400077d0 =====

longlong * ReturnFreeTrackingArrayEntry(longlong param_1,longlong param_2,byte param_3,int param_4)

{
  longlong *plVar1;
  ushort uVar2;
  longlong *plVar3;
  byte *pbVar4;
  longlong *plVar5;
  
  uVar2 = *(ushort *)(param_2 + 0x10);
  *(undefined4 *)(param_2 + 0x18) = 0;
  DetectLostSrb(param_1,param_2,param_3,param_4);
  *(undefined8 *)(param_2 + 8) = 0;
  if (*(char *)(param_1 + 0xbbd0) == '\0') {
    plVar3 = *(longlong **)(param_1 + 0xaa8);
    LOCK();
    pbVar4 = (byte *)((longlong)plVar3 +
                     ((longlong)(int)(uVar2 & 0x1f) >> 3) + (ulonglong)(uVar2 >> 5) * 4);
    *pbVar4 = *pbVar4 | '\x01' << (uVar2 & 7);
    UNLOCK();
    return plVar3;
  }
  do {
    plVar3 = *(longlong **)(param_1 + 0x918);
    plVar5 = plVar3 + 1;
    if (plVar5 == *(longlong **)(param_1 + 0x920)) {
      plVar5 = *(longlong **)(param_1 + 0x908);
    }
    LOCK();
    plVar1 = *(longlong **)(param_1 + 0x918);
    if (plVar3 == plVar1) {
      *(longlong **)(param_1 + 0x918) = plVar5;
      plVar5 = plVar3;
    }
    else {
      plVar5 = plVar1;
    }
    UNLOCK();
  } while (plVar3 != plVar1);
  *plVar3 = param_2;
  return plVar5;
}



===== SynchronizeAccess @ 140007870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
SynchronizeAccess(longlong param_1,undefined *param_2,undefined8 param_3,byte param_4,int param_5)

{
  undefined1 uVar1;
  
  AcquireIsrLocks(param_1,param_4,param_5);
  uVar1 = (*(code *)param_2)(param_1,param_3);
  ReleaseIsrLocks(param_1,param_4,param_5);
  return uVar1;
}



===== AddDevice @ 1400078e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AddDevice(longlong param_1,byte param_2,int param_3)

{
  short *psVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  char *pcVar10;
  int *piVar11;
  uint *puVar12;
  byte bVar13;
  uint uVar14;
  undefined8 *puVar15;
  uint uVar16;
  ulonglong uVar17;
  byte *pbVar18;
  short *psVar19;
  undefined8 *puVar20;
  int *piVar21;
  int iVar22;
  undefined1 auStackY_a8 [32];
  uint local_68;
  int iStack_54;
  short local_50;
  short local_4e;
  short local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = 0;
  psVar19 = (short *)((ulonglong)((uint)*(ushort *)(param_1 + 0x5d4) * *(int *)(param_1 + 0x18e4)) +
                     *(longlong *)(param_1 + 0x5a8));
  if ((char)psVar19[2] == '\0') {
LAB_140008042:
    if (*(char *)(param_1 + 0x11e2) == '\0') {
      *(undefined1 *)(psVar19 + 2) = 0;
      *(undefined1 *)(param_1 + 0x11e3) = 1;
      *(undefined1 *)(param_1 + 0x9ba) = 1;
      iVar22 = 0;
      if ((*(int *)(param_1 + 0x18e4) + 2) * (uint)*(ushort *)(param_1 + 0x5d4) <=
          *(uint *)(param_1 + 0x5cc)) {
        iVar22 = *(int *)(param_1 + 0x18e4) + 1;
      }
      *(int *)(param_1 + 0x18e4) = iVar22;
      SendExtendedConfigPageMessage
                (param_1,'\x01',(char *)(param_1 + 0x1920),0x20000000,
                 (int)*(undefined8 *)(param_1 + 0x1928),param_2,param_3);
    }
    else {
      *(undefined1 *)(param_1 + 0x11e2) = 0;
      RemoveDevice(param_1,param_2,param_3);
    }
    return;
  }
LAB_140007953:
  if (*(char *)((longlong)psVar19 + (ulonglong)local_68 * 0x1c + 0x25) == '\x01') {
    uVar9 = *(ushort *)(param_1 + 0x18c0) & 0xe;
    if (uVar9 == 2) {
      pcVar10 = (char *)(*(longlong *)(param_1 + 0x5a0) + 0x18);
      for (uVar9 = 0; uVar9 < *(byte *)(param_1 + 0x18cc); uVar9 = uVar9 + 1) {
        if ((*(short *)(pcVar10 + -6) == *psVar19) && (*pcVar10 == '\0')) {
          if (uVar9 != 0xffff) {
            puVar15 = (undefined8 *)((ulonglong)uVar9 * 0x1c + *(longlong *)(param_1 + 0x5a0));
            if (*(int *)(puVar15 + 1) == -1) {
              if (*(char *)(param_1 + 0x11e5) == '\0') goto LAB_140007ff6;
              pcVar10 = "Driver encl-slot mapping table is full (AddDevice)";
              goto LAB_1400079e3;
            }
            uVar9 = *(ushort *)((longlong)puVar15 + 0x16);
            uVar5 = psVar19[(ulonglong)local_68 * 0xe + 0x11];
            if (uVar9 <= uVar5) {
              if ((int)(uint)uVar5 <=
                  (int)((uVar9 - 1) + (uint)*(ushort *)((longlong)puVar15 + 0x14))) {
                uVar14 = *(int *)(puVar15 + 1) + ((uint)uVar5 - (uint)uVar9);
                puVar20 = (undefined8 *)((ulonglong)uVar14 * 0x2c + *(longlong *)(param_1 + 0x5c0));
                *puVar20 = *(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 6);
                puVar20[1] = *(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 10);
                *(short *)((longlong)puVar20 + 0x1c) = (short)(uVar14 >> 7);
                *(ushort *)((longlong)puVar20 + 0x1e) = (ushort)uVar14 & 0x7f;
                *(short *)((longlong)puVar20 + 0x1a) = psVar19[(ulonglong)local_68 * 0xe + 0x10];
                *(undefined1 *)(puVar20 + 4) = 0;
                *(undefined2 *)(puVar20 + 3) = *(undefined2 *)(puVar15 + 2);
                *(uint *)((longlong)puVar20 + 0x14) =
                     *(uint *)(psVar19 + (ulonglong)local_68 * 0xe + 0xe) | 0x30000000;
                *(byte *)((longlong)puVar20 + 0x26) =
                     *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x12) >> 2 & 1;
                if ((char)psVar19[(ulonglong)local_68 * 0xe + 0x13] == -4) {
                  if ((*(char *)(param_1 + 0x121e) == '\0') ||
                     (cVar3 = *(char *)(param_1 + 0x121f),
                     *(char *)(param_1 + 0x121f) = cVar3 + '\x01',
                     cVar3 != *(char *)(param_1 + 0x121e))) {
                    *(undefined1 *)((longlong)puVar20 + 0x23) = 0xc;
                  }
                  else {
                    *(undefined1 *)(param_1 + 0x121f) = 0;
                  }
                }
                *(undefined1 *)(param_1 + 0x5c8) = 1;
                if ((*(byte *)(param_1 + 0x18c0) & 1) != 0) goto LAB_140007bff;
                uVar9 = *(ushort *)(puVar15 + 2);
                if ((uVar9 != 0xffff) ||
                   (uVar9 = GetDPMPage0IndexFromID
                                      (param_1,*puVar15,*(uint *)((longlong)puVar15 + 0xc)),
                   uVar9 != 0xffff)) {
                  *(ushort *)(puVar20 + 3) = uVar9;
                  *(ushort *)(puVar15 + 2) = uVar9;
                  goto LAB_140007bff;
                }
                uVar9 = 0;
                goto LAB_140007b20;
              }
            }
            LogSystemEvent(param_1,CONCAT22(psVar19[(ulonglong)local_68 * 0xe + 0x10],*psVar19),
                           0xc004af02,
                           (byte *)
                           "Dev slot num is outside Encl range(AddDevice),Dev & Encl Handle logged",
                           param_2,param_3);
            LogSystemEvent(param_1,((uint)(ushort)psVar19[(ulonglong)local_68 * 0xe + 0x11] << 8 |
                                   (uint)*(ushort *)((longlong)puVar15 + 0x16)) << 0x10 |
                                   (uint)*(ushort *)((longlong)puVar15 + 0x14),0x4004af00,
                           (byte *)"Dev slot num, Encl start and num of slots logged",param_2,
                           param_3);
            local_50 = psVar19[(ulonglong)local_68 * 0xe + 0x10];
            local_4e = *psVar19;
            local_4c = psVar19[(ulonglong)local_68 * 0xe + 0x11];
            local_4a = *(undefined2 *)((longlong)puVar15 + 0x16);
            local_48 = *(undefined2 *)((longlong)puVar15 + 0x14);
            if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x246) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x246,
                          (undefined1 *)&local_50,10,param_2,param_3);
            }
            goto LAB_140007ffd;
          }
          break;
        }
        pcVar10 = pcVar10 + 0x1c;
      }
      LogSystemEvent(param_1,0xad010040,0xc004af02,(byte *)"Enclosure not found (AddDevice)",param_2
                     ,param_3);
    }
    else if (uVar9 == 0) {
      piVar21 = *(int **)(param_1 + 0x5c0);
      iStack_54 = (int)((ulonglong)*(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 6) >> 0x20)
      ;
      piVar11 = piVar21;
      for (uVar14 = 0; uVar14 < *(uint *)(param_1 + 0x9bc); uVar14 = uVar14 + 1) {
        if ((*piVar11 == (int)*(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 6)) &&
           (piVar11[1] == iStack_54)) {
          if (uVar14 != 0xffffffff) goto LAB_140007e20;
          break;
        }
        piVar11 = piVar11 + 0xb;
      }
      uVar7 = *(uint *)(param_1 + 0x9bc);
      uVar14 = 0;
      if (uVar7 == 0) {
LAB_140007da2:
        uVar14 = 0xffffffff;
        if (uVar7 != 0) goto LAB_140007db4;
      }
      else {
        puVar12 = (uint *)(piVar21 + 5);
        do {
          if ((*puVar12 & 0x30000000) == 0) {
            if (uVar14 == 0xffffffff) goto LAB_140007da2;
            goto LAB_140007e20;
          }
          uVar14 = uVar14 + 1;
          puVar12 = puVar12 + 0xb;
        } while (uVar14 < uVar7);
LAB_140007db4:
        uVar16 = 0;
        uVar14 = 0xffffffff;
        bVar13 = 0;
        pbVar18 = (byte *)(piVar21 + 8);
        do {
          bVar4 = *pbVar18;
          pbVar18 = pbVar18 + 0x2c;
          uVar8 = uVar16;
          if (bVar4 <= bVar13) {
            bVar4 = bVar13;
            uVar8 = uVar14;
          }
          uVar14 = uVar8;
          bVar13 = bVar4;
          uVar16 = uVar16 + 1;
        } while (uVar16 < uVar7);
      }
      if (uVar14 == 0xffffffff) {
        if (*(char *)(param_1 + 0x11e5) == '\0') {
LAB_140007ff6:
          *(undefined1 *)(param_1 + 0x11e4) = 1;
        }
        else {
          pcVar10 = "Driver address mapping table is full (AddDevice)";
LAB_1400079e3:
          LogSystemEvent(param_1,0xad010027,0xc004af02,(byte *)pcVar10,param_2,param_3);
        }
      }
      else {
        sVar6 = *(short *)((longlong)piVar21 + (ulonglong)uVar14 * 0x2c + 0x1a);
        if (sVar6 != 0) {
          AddToRemovalTable(param_1,sVar6,0,param_2,param_3);
          *(undefined1 *)(param_1 + 0x11e2) = 1;
        }
        *(undefined1 *)((longlong)piVar21 + (ulonglong)uVar14 * 0x2c + 0x21) = 0;
LAB_140007e20:
        piVar21 = (int *)((ulonglong)uVar14 * 0x2c + *(longlong *)(param_1 + 0x5c0));
        *(undefined8 *)piVar21 = *(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 6);
        *(undefined8 *)(piVar21 + 2) = *(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 10);
        *(short *)(piVar21 + 7) = (short)(uVar14 >> 7);
        *(ushort *)((longlong)piVar21 + 0x1e) = (ushort)uVar14 & 0x7f;
        *(short *)((longlong)piVar21 + 0x1a) = psVar19[(ulonglong)local_68 * 0xe + 0x10];
        *(undefined1 *)(piVar21 + 8) = 0;
        piVar21[5] = *(uint *)(psVar19 + (ulonglong)local_68 * 0xe + 0xe) | 0x30000000;
        *(byte *)((longlong)piVar21 + 0x26) =
             *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x12) >> 2 & 1;
        if ((char)psVar19[(ulonglong)local_68 * 0xe + 0x13] == -4) {
          if ((*(char *)(param_1 + 0x121e) == '\0') ||
             (cVar3 = *(char *)(param_1 + 0x121f), *(char *)(param_1 + 0x121f) = cVar3 + '\x01',
             cVar3 != *(char *)(param_1 + 0x121e))) {
            *(undefined1 *)((longlong)piVar21 + 0x23) = 0xc;
          }
          else {
            *(undefined1 *)(param_1 + 0x121f) = 0;
          }
        }
        *(undefined1 *)(param_1 + 0x5c8) = 1;
        if ((*(byte *)(param_1 + 0x18c0) & 1) == 0) {
          uVar9 = *(ushort *)(piVar21 + 6);
          if (uVar9 == 0xffff) {
            for (uVar9 = 0; uVar9 < *(ushort *)(param_1 + 0x18bc); uVar9 = uVar9 + 1) {
              if (*(char *)((ulonglong)uVar9 + *(longlong *)(param_1 + 0x18d0)) == '\0')
              goto LAB_140007f2f;
            }
            uVar9 = 0xffff;
LAB_140007f2f:
            *(undefined1 *)((longlong)piVar21 + 0x21) = 0;
            if (uVar9 == 0xffff) {
              if ((*(char *)(param_1 + 0xb92d) != '\0') && (*(char *)(param_1 + 0xb92c) == '\0')) {
                LogSystemEvent(param_1,0xad010045,0xc004af02,
                               (byte *)
                               "persistent mapping config page is full (AddDevice addr mapping)",
                               param_2,param_3);
                *(undefined1 *)(param_1 + 0xb92c) = 1;
              }
              goto LAB_140007fd5;
            }
          }
          else {
            lVar2 = *(longlong *)(param_1 + 0x1910) + (ulonglong)uVar9 * 0x14;
            if (((*(int *)(lVar2 + 8) == *piVar21) && (*(int *)(lVar2 + 0xc) == piVar21[1])) &&
               ((*(byte *)(lVar2 + 0x10) & 0xf) == 0)) {
              *(undefined1 *)((longlong)piVar21 + 0x21) = 1;
            }
          }
          if (*(char *)((longlong)piVar21 + 0x21) == '\0') {
            *(undefined1 *)((longlong)piVar21 + 0x21) = 1;
            *(ushort *)(piVar21 + 6) = uVar9;
            uVar17 = (ulonglong)uVar9;
            lVar2 = *(longlong *)(param_1 + 0x1910) + uVar17 * 0x14;
            *(undefined8 *)(lVar2 + 8) = *(undefined8 *)piVar21;
            *(undefined2 *)(lVar2 + 0x10) = 0;
            *(ushort *)(lVar2 + 0x12) = (ushort)uVar14;
            *(undefined4 *)(lVar2 + 0x14) = 0;
            *(undefined1 *)(uVar17 + *(longlong *)(param_1 + 0x18d8)) = 1;
            *(undefined1 *)(uVar17 + *(longlong *)(param_1 + 0x18d0)) = 1;
            *(undefined1 *)((longlong)piVar21 + 0x21) = 1;
            goto LAB_140007ffd;
          }
        }
LAB_140007fd5:
        *(undefined1 *)((longlong)piVar21 + 0x21) = 1;
      }
    }
  }
  goto LAB_140007ffd;
LAB_140007b20:
  if (*(ushort *)(param_1 + 0x18bc) <= uVar9) goto LAB_140007bab;
  uVar17 = (ulonglong)uVar9;
  if (*(char *)(uVar17 + *(longlong *)(param_1 + 0x18d0)) == '\0') {
    if (uVar9 != 0xffff) {
      lVar2 = *(longlong *)(param_1 + 0x1910) + uVar17 * 0x14;
      *(undefined8 *)(lVar2 + 8) = *puVar15;
      *(undefined2 *)(lVar2 + 0x12) = *(undefined2 *)(puVar15 + 1);
      *(short *)(lVar2 + 0x10) = *(short *)((longlong)puVar15 + 0x14) << 4;
      *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)((longlong)puVar15 + 0xc);
      *(undefined1 *)(uVar17 + *(longlong *)(param_1 + 0x18d8)) = 1;
      *(ushort *)(puVar15 + 2) = uVar9;
      *(ushort *)(puVar20 + 3) = uVar9;
      *(undefined1 *)(uVar17 + *(longlong *)(param_1 + 0x18d0)) = 1;
      *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x12) =
           *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x12) & 0xf8;
      *(undefined1 *)((longlong)puVar15 + 0x1b) = 1;
      goto LAB_140007ffd;
    }
    goto LAB_140007bab;
  }
  uVar9 = uVar9 + 1;
  goto LAB_140007b20;
LAB_140007bab:
  if ((*(char *)(param_1 + 0xb92d) == '\0') || (*(char *)(param_1 + 0xb92c) != '\0')) {
LAB_140007bff:
    *(undefined1 *)((longlong)puVar15 + 0x1b) = 1;
  }
  else {
    LogSystemEvent(param_1,0xad010045,0xc004af02,
                   (byte *)"persistent mapping config page is full (AddDevice Encl-slot mapping)",
                   param_2,param_3);
    *(undefined1 *)(param_1 + 0xb92c) = 1;
    *(undefined1 *)((longlong)puVar15 + 0x1b) = 1;
  }
LAB_140007ffd:
  *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x12) =
       *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x12) & 0xfe;
  uVar14 = local_68 + 1;
  bVar13 = *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x12);
  psVar1 = psVar19 + (ulonglong)local_68 * 0xe + 6;
  psVar1[0] = 0;
  psVar1[1] = 0;
  psVar1[2] = 0;
  psVar1[3] = 0;
  psVar1 = psVar19 + (ulonglong)local_68 * 0xe + 10;
  psVar1[0] = 0;
  psVar1[1] = 0;
  psVar1[2] = 0;
  psVar1[3] = 0;
  psVar1 = psVar19 + (ulonglong)local_68 * 0xe + 0xe;
  psVar1[0] = 0;
  psVar1[1] = 0;
  psVar1[2] = 0;
  psVar1[3] = 0;
  *(undefined2 *)((longlong)psVar19 + (ulonglong)local_68 * 0x1c + 0x25) = 0;
  *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x12) = bVar13 & 0xf9;
  local_68 = uVar14;
  if (*(byte *)(psVar19 + 2) <= uVar14) goto LAB_140008042;
  goto LAB_140007953;
}



===== AddPcieDevice @ 1400080f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AddPcieDevice(longlong param_1,byte param_2,int param_3)

{
  short *psVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  char *pcVar10;
  int *piVar11;
  uint *puVar12;
  byte bVar13;
  uint uVar14;
  undefined8 *puVar15;
  uint uVar16;
  ulonglong uVar17;
  byte *pbVar18;
  short *psVar19;
  undefined8 *puVar20;
  int *piVar21;
  int iVar22;
  undefined1 auStackY_a8 [32];
  uint local_68;
  int iStack_54;
  short local_50;
  short local_4e;
  short local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = 0;
  psVar19 = (short *)((ulonglong)((uint)*(ushort *)(param_1 + 0x5d6) * *(int *)(param_1 + 0x18ec)) +
                     *(longlong *)(param_1 + 0x5b0));
  if ((char)psVar19[2] == '\0') {
LAB_140008887:
    if (*(char *)(param_1 + 0x11e2) == '\0') {
      *(undefined1 *)(psVar19 + 2) = 0;
      *(undefined1 *)(param_1 + 0x11e3) = 1;
      *(undefined1 *)(param_1 + 0x9ba) = 1;
      iVar22 = 0;
      if ((*(int *)(param_1 + 0x18ec) + 2) * (uint)*(ushort *)(param_1 + 0x5d6) <=
          *(uint *)(param_1 + 0x5d0)) {
        iVar22 = *(int *)(param_1 + 0x18ec) + 1;
      }
      *(int *)(param_1 + 0x18ec) = iVar22;
      SendExtendedConfigPageMessage
                (param_1,'\x01',(char *)(param_1 + 0x1920),0x20000000,
                 (int)*(undefined8 *)(param_1 + 0x1928),param_2,param_3);
    }
    else {
      *(undefined1 *)(param_1 + 0x11e2) = 0;
      RemoveDevice(param_1,param_2,param_3);
    }
    return;
  }
LAB_140008163:
  if (*(char *)((longlong)psVar19 + (ulonglong)local_68 * 0x1c + 0x21) == '\x01') {
    uVar9 = *(ushort *)(param_1 + 0x18c0) & 0xe;
    if (uVar9 == 2) {
      pcVar10 = (char *)(*(longlong *)(param_1 + 0x5a0) + 0x18);
      for (uVar9 = 0; uVar9 < *(byte *)(param_1 + 0x18cc); uVar9 = uVar9 + 1) {
        if ((*(short *)(pcVar10 + -6) == *psVar19) && (*pcVar10 == '\0')) {
          if (uVar9 != 0xffff) {
            puVar15 = (undefined8 *)((ulonglong)uVar9 * 0x1c + *(longlong *)(param_1 + 0x5a0));
            if (*(int *)(puVar15 + 1) == -1) {
              if (*(char *)(param_1 + 0x11e5) == '\0') goto LAB_14000883f;
              pcVar10 = "Driver encl-slot mapping table is full (AddPcieDevice)";
              goto LAB_1400081f3;
            }
            uVar9 = *(ushort *)((longlong)puVar15 + 0x16);
            uVar5 = psVar19[(ulonglong)local_68 * 0xe + 0xf];
            if (uVar9 <= uVar5) {
              if ((int)(uint)uVar5 <=
                  (int)((uVar9 - 1) + (uint)*(ushort *)((longlong)puVar15 + 0x14))) {
                uVar14 = *(int *)(puVar15 + 1) + ((uint)uVar5 - (uint)uVar9);
                puVar20 = (undefined8 *)((ulonglong)uVar14 * 0x2c + *(longlong *)(param_1 + 0x5c0));
                *puVar20 = *(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 6);
                *(undefined4 *)(puVar20 + 2) =
                     *(undefined4 *)(psVar19 + (ulonglong)local_68 * 0xe + 0xc);
                *(undefined1 *)((longlong)puVar20 + 0x27) =
                     *(undefined1 *)((longlong)psVar19 + (ulonglong)local_68 * 0x1c + 0x23);
                uVar9 = psVar19[(ulonglong)local_68 * 0xe + 0x12];
                *(ushort *)(puVar20 + 5) = uVar9;
                if (*(ushort *)(param_1 + 0xbbd8) < uVar9) {
                  *(ushort *)(param_1 + 0xbbd8) = uVar9;
                }
                *(short *)((longlong)puVar20 + 0x1c) = (short)(uVar14 >> 7);
                *(ushort *)((longlong)puVar20 + 0x1e) = (ushort)uVar14 & 0x7f;
                *(short *)((longlong)puVar20 + 0x1a) = psVar19[(ulonglong)local_68 * 0xe + 0xe];
                *(undefined1 *)(puVar20 + 4) = 0;
                *(undefined2 *)(puVar20 + 3) = *(undefined2 *)(puVar15 + 2);
                uVar14 = *(uint *)(psVar19 + (ulonglong)local_68 * 0xe + 10);
                *(undefined1 *)((longlong)puVar20 + 0x24) = 1;
                *(uint *)((longlong)puVar20 + 0x14) = uVar14 | 0x30000000;
                if ((char)psVar19[(ulonglong)local_68 * 0xe + 0x11] == -4) {
                  if ((*(char *)(param_1 + 0x121e) == '\0') ||
                     (cVar3 = *(char *)(param_1 + 0x121f),
                     *(char *)(param_1 + 0x121f) = cVar3 + '\x01',
                     cVar3 != *(char *)(param_1 + 0x121e))) {
                    *(undefined1 *)((longlong)puVar20 + 0x23) = 0xc;
                  }
                  else {
                    *(undefined1 *)(param_1 + 0x121f) = 0;
                  }
                }
                *(undefined1 *)(param_1 + 0x5c8) = 1;
                if ((*(byte *)(param_1 + 0x18c0) & 1) != 0) goto LAB_140008422;
                uVar9 = *(ushort *)(puVar15 + 2);
                if ((uVar9 != 0xffff) ||
                   (uVar9 = GetDPMPage0IndexFromID
                                      (param_1,*puVar15,*(uint *)((longlong)puVar15 + 0xc)),
                   uVar9 != 0xffff)) {
                  *(ushort *)(puVar20 + 3) = uVar9;
                  *(ushort *)(puVar15 + 2) = uVar9;
                  goto LAB_140008422;
                }
                uVar9 = 0;
                goto LAB_140008343;
              }
            }
            LogSystemEvent(param_1,CONCAT22(psVar19[(ulonglong)local_68 * 0xe + 0xe],*psVar19),
                           0xc004af02,
                           (byte *)
                           "Dev slot num is outside Encl range(AddPcieDevice),Dev & Encl Handle logged"
                           ,param_2,param_3);
            LogSystemEvent(param_1,((uint)(ushort)psVar19[(ulonglong)local_68 * 0xe + 0xf] << 8 |
                                   (uint)*(ushort *)((longlong)puVar15 + 0x16)) << 0x10 |
                                   (uint)*(ushort *)((longlong)puVar15 + 0x14),0x4004af00,
                           (byte *)"Dev slot num, Encl start and num of slots logged",param_2,
                           param_3);
            local_50 = psVar19[(ulonglong)local_68 * 0xe + 0xe];
            local_4e = *psVar19;
            local_4c = psVar19[(ulonglong)local_68 * 0xe + 0xf];
            local_4a = *(undefined2 *)((longlong)puVar15 + 0x16);
            local_48 = *(undefined2 *)((longlong)puVar15 + 0x14);
            if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x246) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x246,
                          (undefined1 *)&local_50,10,param_2,param_3);
            }
            goto LAB_140008846;
          }
          break;
        }
        pcVar10 = pcVar10 + 0x1c;
      }
      LogSystemEvent(param_1,0xad010040,0xc004af02,(byte *)"Enclosure not found (AddPcieDevice)",
                     param_2,param_3);
    }
    else if (uVar9 == 0) {
      piVar21 = *(int **)(param_1 + 0x5c0);
      iStack_54 = (int)((ulonglong)*(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 6) >> 0x20)
      ;
      piVar11 = piVar21;
      for (uVar14 = 0; uVar14 < *(uint *)(param_1 + 0x9bc); uVar14 = uVar14 + 1) {
        if ((*piVar11 == (int)*(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 6)) &&
           (piVar11[1] == iStack_54)) {
          if (uVar14 != 0xffffffff) goto LAB_140008650;
          break;
        }
        piVar11 = piVar11 + 0xb;
      }
      uVar7 = *(uint *)(param_1 + 0x9bc);
      uVar14 = 0;
      if (uVar7 == 0) {
LAB_1400085cb:
        uVar14 = 0xffffffff;
        if (uVar7 != 0) goto LAB_1400085dd;
      }
      else {
        puVar12 = (uint *)(piVar21 + 5);
        do {
          if ((*puVar12 & 0x30000000) == 0) {
            if (uVar14 == 0xffffffff) goto LAB_1400085cb;
            goto LAB_140008650;
          }
          uVar14 = uVar14 + 1;
          puVar12 = puVar12 + 0xb;
        } while (uVar14 < uVar7);
LAB_1400085dd:
        uVar16 = 0;
        uVar14 = 0xffffffff;
        bVar13 = 0;
        pbVar18 = (byte *)(piVar21 + 8);
        do {
          bVar4 = *pbVar18;
          pbVar18 = pbVar18 + 0x2c;
          uVar8 = uVar16;
          if (bVar4 <= bVar13) {
            bVar4 = bVar13;
            uVar8 = uVar14;
          }
          uVar14 = uVar8;
          bVar13 = bVar4;
          uVar16 = uVar16 + 1;
        } while (uVar16 < uVar7);
      }
      if (uVar14 == 0xffffffff) {
        if (*(char *)(param_1 + 0x11e5) == '\0') {
LAB_14000883f:
          *(undefined1 *)(param_1 + 0x11e4) = 1;
        }
        else {
          pcVar10 = "Driver address mapping table is full (AddPcieDevice)";
LAB_1400081f3:
          LogSystemEvent(param_1,0xad010027,0xc004af02,(byte *)pcVar10,param_2,param_3);
        }
      }
      else {
        sVar6 = *(short *)((longlong)piVar21 + (ulonglong)uVar14 * 0x2c + 0x1a);
        if (sVar6 != 0) {
          AddToRemovalTable(param_1,sVar6,0,param_2,param_3);
          *(undefined1 *)(param_1 + 0x11e2) = 1;
        }
        *(undefined1 *)((longlong)piVar21 + (ulonglong)uVar14 * 0x2c + 0x21) = 0;
LAB_140008650:
        piVar21 = (int *)((ulonglong)uVar14 * 0x2c + *(longlong *)(param_1 + 0x5c0));
        *(undefined8 *)piVar21 = *(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 6);
        *(undefined8 *)(piVar21 + 2) = *(undefined8 *)(psVar19 + (ulonglong)local_68 * 0xe + 6);
        piVar21[4] = *(int *)(psVar19 + (ulonglong)local_68 * 0xe + 0xc);
        *(undefined1 *)((longlong)piVar21 + 0x27) =
             *(undefined1 *)((longlong)psVar19 + (ulonglong)local_68 * 0x1c + 0x23);
        uVar9 = psVar19[(ulonglong)local_68 * 0xe + 0x12];
        *(ushort *)(piVar21 + 10) = uVar9;
        if (*(ushort *)(param_1 + 0xbbd8) < uVar9) {
          *(ushort *)(param_1 + 0xbbd8) = uVar9;
        }
        *(short *)(piVar21 + 7) = (short)(uVar14 >> 7);
        *(ushort *)((longlong)piVar21 + 0x1e) = (ushort)uVar14 & 0x7f;
        *(short *)((longlong)piVar21 + 0x1a) = psVar19[(ulonglong)local_68 * 0xe + 0xe];
        *(undefined1 *)(piVar21 + 8) = 0;
        uVar7 = *(uint *)(psVar19 + (ulonglong)local_68 * 0xe + 10);
        *(undefined1 *)(piVar21 + 9) = 1;
        piVar21[5] = uVar7 | 0x30000000;
        if ((char)psVar19[(ulonglong)local_68 * 0xe + 0x11] == -4) {
          if ((*(char *)(param_1 + 0x121e) == '\0') ||
             (cVar3 = *(char *)(param_1 + 0x121f), *(char *)(param_1 + 0x121f) = cVar3 + '\x01',
             cVar3 != *(char *)(param_1 + 0x121e))) {
            *(undefined1 *)((longlong)piVar21 + 0x23) = 0xc;
          }
          else {
            *(undefined1 *)(param_1 + 0x121f) = 0;
          }
        }
        *(undefined1 *)(param_1 + 0x5c8) = 1;
        if ((*(byte *)(param_1 + 0x18c0) & 1) == 0) {
          uVar9 = *(ushort *)(piVar21 + 6);
          if (uVar9 == 0xffff) {
            for (uVar9 = 0; uVar9 < *(ushort *)(param_1 + 0x18bc); uVar9 = uVar9 + 1) {
              if (*(char *)((ulonglong)uVar9 + *(longlong *)(param_1 + 0x18d0)) == '\0')
              goto LAB_14000877f;
            }
            uVar9 = 0xffff;
LAB_14000877f:
            *(undefined1 *)((longlong)piVar21 + 0x21) = 0;
            if (uVar9 == 0xffff) {
              if ((*(char *)(param_1 + 0xb92d) != '\0') && (*(char *)(param_1 + 0xb92c) == '\0')) {
                LogSystemEvent(param_1,0xad010045,0xc004af02,
                               (byte *)
                               "Persistent mapping config page is full (AddPcieDevice addr mapping)"
                               ,param_2,param_3);
              }
              goto LAB_14000881e;
            }
          }
          else {
            lVar2 = *(longlong *)(param_1 + 0x1910) + (ulonglong)uVar9 * 0x14;
            if (((*(int *)(lVar2 + 8) == *piVar21) && (*(int *)(lVar2 + 0xc) == piVar21[1])) &&
               ((*(byte *)(lVar2 + 0x10) & 0xf) == 0)) {
              *(undefined1 *)((longlong)piVar21 + 0x21) = 1;
            }
          }
          if (*(char *)((longlong)piVar21 + 0x21) == '\0') {
            *(undefined1 *)((longlong)piVar21 + 0x21) = 1;
            *(ushort *)(piVar21 + 6) = uVar9;
            uVar17 = (ulonglong)uVar9;
            lVar2 = *(longlong *)(param_1 + 0x1910) + uVar17 * 0x14;
            *(undefined8 *)(lVar2 + 8) = *(undefined8 *)piVar21;
            *(undefined2 *)(lVar2 + 0x10) = 0;
            *(ushort *)(lVar2 + 0x12) = (ushort)uVar14;
            *(undefined4 *)(lVar2 + 0x14) = 0;
            *(undefined1 *)(uVar17 + *(longlong *)(param_1 + 0x18d8)) = 1;
            *(undefined1 *)(uVar17 + *(longlong *)(param_1 + 0x18d0)) = 1;
            *(undefined1 *)((longlong)piVar21 + 0x21) = 1;
            goto LAB_140008846;
          }
        }
LAB_14000881e:
        *(undefined1 *)((longlong)piVar21 + 0x21) = 1;
      }
    }
  }
  goto LAB_140008846;
LAB_140008343:
  if (*(ushort *)(param_1 + 0x18bc) <= uVar9) goto LAB_1400083ce;
  uVar17 = (ulonglong)uVar9;
  if (*(char *)(uVar17 + *(longlong *)(param_1 + 0x18d0)) == '\0') {
    if (uVar9 != 0xffff) {
      lVar2 = *(longlong *)(param_1 + 0x1910) + uVar17 * 0x14;
      *(undefined8 *)(lVar2 + 8) = *puVar15;
      *(undefined2 *)(lVar2 + 0x12) = *(undefined2 *)(puVar15 + 1);
      *(short *)(lVar2 + 0x10) = *(short *)((longlong)puVar15 + 0x14) << 4;
      *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)((longlong)puVar15 + 0xc);
      *(undefined1 *)(uVar17 + *(longlong *)(param_1 + 0x18d8)) = 1;
      *(ushort *)(puVar15 + 2) = uVar9;
      *(ushort *)(puVar20 + 3) = uVar9;
      *(undefined1 *)(uVar17 + *(longlong *)(param_1 + 0x18d0)) = 1;
      *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x10) =
           *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x10) & 0xfc;
      *(undefined1 *)((longlong)puVar15 + 0x1b) = 1;
      goto LAB_140008846;
    }
    goto LAB_1400083ce;
  }
  uVar9 = uVar9 + 1;
  goto LAB_140008343;
LAB_1400083ce:
  if ((*(char *)(param_1 + 0xb92d) == '\0') || (*(char *)(param_1 + 0xb92c) != '\0')) {
LAB_140008422:
    *(undefined1 *)((longlong)puVar15 + 0x1b) = 1;
  }
  else {
    LogSystemEvent(param_1,0xad010045,0xc004af02,
                   (byte *)"persistent mapping config page is full (AddPcieDevice encl-slot)",
                   param_2,param_3);
    *(undefined1 *)(param_1 + 0xb92c) = 1;
    *(undefined1 *)((longlong)puVar15 + 0x1b) = 1;
  }
LAB_140008846:
  *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x10) =
       *(byte *)(psVar19 + (ulonglong)local_68 * 0xe + 0x10) & 0xfc;
  uVar14 = local_68 + 1;
  psVar1 = psVar19 + (ulonglong)local_68 * 0xe + 6;
  psVar1[0] = 0;
  psVar1[1] = 0;
  psVar1[2] = 0;
  psVar1[3] = 0;
  psVar1 = psVar19 + (ulonglong)local_68 * 0xe + 10;
  psVar1[0] = 0;
  psVar1[1] = 0;
  psVar1[2] = 0;
  psVar1[3] = 0;
  (psVar19 + (ulonglong)local_68 * 0xe + 0xe)[0] = 0;
  (psVar19 + (ulonglong)local_68 * 0xe + 0xe)[1] = 0;
  *(undefined2 *)((longlong)psVar19 + (ulonglong)local_68 * 0x1c + 0x21) = 0;
  *(undefined1 *)((longlong)psVar19 + (ulonglong)local_68 * 0x1c + 0x23) = 0;
  psVar19[(ulonglong)local_68 * 0xe + 0x12] = 0;
  local_68 = uVar14;
  if (*(byte *)(psVar19 + 2) <= uVar14) goto LAB_140008887;
  goto LAB_140008163;
}



===== AddToRemovalTable @ 140008940 =====

void AddToRemovalTable(longlong param_1,short param_2,short param_3,byte param_4,int param_5)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  short *psVar4;
  longlong lVar5;
  uint uVar6;
  short *psVar7;
  short local_res10 [4];
  
  psVar4 = *(short **)(param_1 + 0x5b8);
  uVar6 = 0;
  lVar5 = 0;
  psVar7 = (short *)(*(longlong *)(param_1 + 0x5c0) + 0x1a);
  uVar3 = 0;
  while (uVar2 = (uint)uVar3, local_res10[0] = param_2, uVar2 < *(uint *)(param_1 + 0x9bc)) {
    if (*psVar7 == param_2) {
      if (uVar2 != 0xffffffff) {
        lVar5 = uVar3 * 0x2c + *(longlong *)(param_1 + 0x5c0);
        *(undefined2 *)(lVar5 + 0x25) = 0;
        *(undefined2 *)(lVar5 + 0x1a) = 0;
        ResumeDevice(param_1,*(undefined1 *)(lVar5 + 0x1c),*(undefined1 *)(lVar5 + 0x1e),0,param_2,
                     0xff,3,param_4,param_5);
        if (*(int *)(lVar5 + 0x14) < 0) {
          SendSEPMessage(param_1,0,local_res10[0],param_4,param_5);
          *(uint *)(lVar5 + 0x14) = *(uint *)(lVar5 + 0x14) & 0x7fffffff;
        }
        goto LAB_140008ab2;
      }
      break;
    }
    psVar7 = psVar7 + 0x16;
    uVar3 = (ulonglong)(uVar2 + 1);
  }
  if (((param_2 != 0) &&
      (LogSystemEvent(param_1,0xad01003f,0xc004af02,(byte *)"Device not mapped (AddToRemovalTable)",
                      param_4,param_5), *(char *)(param_1 + 0x608) != '\0')) &&
     ((*(uint *)(param_1 + 0x60c) & 0x230) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x230,
                (undefined1 *)local_res10,2,param_4,param_5);
  }
LAB_140008ab2:
  if (*(uint *)(param_1 + 0x9bc) == 0) {
    return;
  }
  while ((psVar4[1] != 0 || (*psVar4 != -1))) {
    uVar6 = uVar6 + 1;
    psVar4 = psVar4 + 5;
    if (*(uint *)(param_1 + 0x9bc) <= uVar6) {
      return;
    }
  }
  uVar1 = *(ushort *)(param_1 + 0x18c0) & 0xe;
  if (uVar1 == 2) {
    if ((param_3 != 0) && (*psVar4 = param_3, param_3 != -1)) goto LAB_140008b2b;
  }
  else if (uVar1 != 0) goto LAB_140008b2b;
  psVar4[1] = local_res10[0];
LAB_140008b2b:
  if (lVar5 != 0) {
    *(undefined1 *)((longlong)psVar4 + 5) = *(undefined1 *)(lVar5 + 0x24);
    *(undefined1 *)(psVar4 + 3) = *(undefined1 *)(lVar5 + 0x27);
    psVar4[4] = *(short *)(lVar5 + 0x28);
    *(byte *)((longlong)psVar4 + 7) = *(byte *)(lVar5 + 0x14) & 4;
    *(undefined1 *)(lVar5 + 0x24) = 0;
  }
  return;
}



===== AtaIdentifyTimeout @ 140008b60 =====

ulonglong AtaIdentifyTimeout(longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,
                            int param_5)

{
  byte bVar1;
  undefined2 *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x243) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x243,
                (undefined1 *)0x0,0,param_4,param_5);
  }
  puVar2 = *(undefined2 **)(param_1 + 0x578);
  lVar4 = (ulonglong)((uint)*(ushort *)(param_1 + 0x5d4) * *(int *)(param_1 + 0x18e4)) +
          *(longlong *)(param_1 + 0x5a8);
  bVar1 = *(byte *)(lVar4 + 7);
  *(undefined1 *)(param_1 + 0x1209) = 1;
  ZeroMemory(puVar2,0x34);
  *puVar2 = *(undefined2 *)((ulonglong)bVar1 * 0x1c + 0x20 + lVar4);
  *(undefined1 *)((longlong)puVar2 + 3) = 1;
  *(undefined1 *)((longlong)puVar2 + 5) = 1;
  uVar3 = QueueRequestDescriptor
                    (param_1,(uint)*(ushort *)(param_1 + 0x9b6) * 0x10000 + 6,0,param_4,param_5);
  return uVar3 & 0xffffffffffffff00;
}



===== BusTargetDevHandleMapping @ 140008c50 =====

undefined8 BusTargetDevHandleMapping(longlong param_1,longlong param_2)

{
  short sVar1;
  short sVar2;
  longlong lVar3;
  longlong lVar4;
  ushort uVar5;
  
  lVar3 = *(longlong *)(param_2 + 0x40);
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
    lVar4 = *(longlong *)(param_1 + 0x5c0);
    uVar5 = 0;
    if (*(uint *)(param_1 + 0x9bc) != 0) {
      do {
        if (*(short *)(lVar4 + 0x1a) == sVar2) {
          uVar5 = *(ushort *)(lVar4 + 0x1e);
          *(uint *)(lVar3 + 0x20) = (uint)*(ushort *)(lVar4 + 0x1c);
          *(uint *)(lVar3 + 0x1c) = (uint)uVar5;
          return 0x28;
        }
        uVar5 = uVar5 + 1;
        lVar4 = lVar4 + 0x2c;
      } while ((uint)uVar5 < *(uint *)(param_1 + 0x9bc));
      return 0x28;
    }
  }
  else {
    if (sVar2 != -1) {
      return 0;
    }
    if (sVar1 == -1) {
      return 0;
    }
    if (uVar5 == 0xffff) {
      return 0;
    }
    if (((uVar5 < 0x80) && (uVar5 = sVar1 * 0x80 + uVar5, (uint)uVar5 < *(uint *)(param_1 + 0x9bc)))
       && (sVar1 = *(short *)((ulonglong)uVar5 * 0x2c + 0x1a + *(longlong *)(param_1 + 0x5c0)),
          sVar1 != 0)) {
      *(short *)(lVar3 + 0x24) = sVar1;
    }
  }
  return 0x28;
}



===== ClearEnclosureEntry @ 140008d30 =====

void ClearEnclosureEntry(undefined8 *param_1)

{
  *(undefined4 *)(param_1 + 1) = 0xffffffff;
  *param_1 = 0;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 3) = 0;
  param_1[2] = 0xffff;
  return;
}



===== ClearMapEntry @ 140008d50 =====

void ClearMapEntry(longlong param_1,undefined8 *param_2)

{
  param_2[3] = 0xffff;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  *(undefined2 *)(param_2 + 4) = 0;
  *(undefined1 *)((longlong)param_2 + 0x22) = *(undefined1 *)(param_1 + 0x9a2);
  *(undefined2 *)((longlong)param_2 + 0x23) = 0;
  *(undefined1 *)((longlong)param_2 + 0x27) = 0;
  *(undefined2 *)(param_2 + 5) = 0;
  return;
}



===== CompressEnclosureTable @ 140008d90 =====

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
  
  if ((*(byte *)(param_1 + 0x18c0) & 0xe) == 2) {
    uVar4 = (ushort)*(byte *)(param_1 + 0x18cc);
    do {
      piVar8 = *(int **)(param_1 + 0x5a0);
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
            puVar5 = (undefined8 *)((ulonglong)uVar9 * 0x1c + *(longlong *)(param_1 + 0x5a0));
            puVar3 = (undefined8 *)((ulonglong)(uVar9 + 1) * 0x1c + *(longlong *)(param_1 + 0x5a0));
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
          *(char *)(param_1 + 0x18cc) = *(char *)(param_1 + 0x18cc) + -1;
          uVar4 = (ushort)*(byte *)(param_1 + 0x18cc);
        }
        uVar9 = uVar9 + 1;
        piVar8 = piVar8 + 7;
      } while (uVar9 < uVar4);
    } while (!bVar1);
  }
  return;
}



===== ContinueHashedSASAddress @ 140008ee0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ContinueHashedSASAddress(longlong param_1,longlong param_2,byte param_3,int param_4)

{
  undefined1 uVar1;
  longlong lVar2;
  int *piVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  byte bVar10;
  int iVar11;
  ulonglong uVar12;
  undefined8 uStackY_b0;
  undefined1 auStackY_a8 [32];
  int local_78 [10];
  undefined1 local_50 [24];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  uStackY_b0 = 0x140008f16;
  GtfStopTimer(param_1,*(byte *)(param_1 + 0x1208),param_3,param_4);
  lVar8 = (ulonglong)((uint)*(ushort *)(param_1 + 0x5d4) * *(int *)(param_1 + 0x18e4)) +
          *(longlong *)(param_1 + 0x5a8);
  lVar8 = (ulonglong)*(byte *)(lVar8 + 7) * 0x1c + lVar8;
  if (((*(ushort *)(param_2 + 0xe) & 0x7fff) == 0) && (*(char *)(param_2 + 0xd) == '\0')) {
    lVar2 = *(longlong *)(param_1 + 0x1200);
    lVar9 = 0x14;
    puVar6 = (undefined1 *)(lVar2 + 0x36);
    do {
      puVar6[(longlong)(auStackY_a8 + (-6 - lVar2))] = puVar6[1];
      puVar6[(longlong)(auStackY_a8 + (-5 - lVar2))] = *puVar6;
      puVar6 = puVar6 + 2;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    puVar6 = local_50;
    uVar12 = 0;
    do {
      bVar10 = (char)uVar12 + 2;
      uVar1 = *(undefined1 *)(uVar12 + 0x15 + lVar2);
      puVar6[1] = (puVar6 + 2)[(lVar2 - (longlong)local_50) + 0x12];
      *puVar6 = uVar1;
      puVar6 = puVar6 + 2;
      uVar12 = (ulonglong)bVar10;
    } while (bVar10 < 0x14);
    iVar11 = 0;
    piVar3 = local_78;
    uVar7 = 0;
    lVar9 = 7;
    do {
      iVar11 = iVar11 + *piVar3;
      uVar7 = uVar7 + piVar3[1];
      piVar3 = piVar3 + 2;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    *(int *)(lVar8 + 0xc) = *piVar3 + iVar11;
    uVar5 = uVar7 | 0x80;
    if (((byte)uVar7 & 0xf0) != 0x50) {
      uVar5 = uVar7;
    }
    *(uint *)(lVar8 + 0x10) = uVar5;
    if (*(short *)(lVar2 + 0x1b2) == 1) {
      *(byte *)(lVar8 + 0x24) = *(byte *)(lVar8 + 0x24) | 4;
    }
  }
  else {
    if (*(char *)(lVar8 + 0x26) != '\x05') {
      *(char *)(lVar8 + 0x26) = *(char *)(lVar8 + 0x26) + '\x01';
      uStackY_b0 = 0x1400090a4;
      SendSTPIdentifyCommand
                (param_1,*(uint *)(lVar8 + 0x1c),*(undefined2 *)(lVar8 + 0x20),param_3,param_4);
      return;
    }
    uStackY_b0 = 0x14000904d;
    LogSystemEvent(param_1,0xad010051,0xc004af02,
                   (byte *)"An ATA Identify command failed on a SATA target",param_3,param_4);
  }
  if ((*(ushort *)(*(longlong *)(param_1 + 0x1928) + 0x20) >> 0xd & 1) != 0) {
    *(undefined1 *)(lVar8 + 0x26) = 0xfc;
  }
  uStackY_b0 = 0x14000906f;
  uVar4 = ReadIDs(param_1,param_3,param_4);
  if ((char)uVar4 == '\0') {
    *(undefined1 *)(param_1 + 0x11de) = 0;
    uStackY_b0 = 0x140009088;
    RemoveDevice(param_1,param_3,param_4);
  }
  return;
}



===== ContinueIDReadsForPhyEvents @ 1400090c0 =====

void ContinueIDReadsForPhyEvents(longlong param_1,byte param_2,int param_3)

{
  undefined1 *puVar1;
  byte bVar2;
  uint uVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 *puVar6;
  byte bVar7;
  ushort uVar8;
  uint uVar9;
  ulonglong uVar10;
  short *psVar11;
  int *piVar12;
  short *psVar13;
  
  psVar13 = (short *)((ulonglong)((uint)*(ushort *)(param_1 + 0x5d4) * *(int *)(param_1 + 0x18e4)) +
                     *(longlong *)(param_1 + 0x5a8));
  psVar11 = psVar13 + (ulonglong)*(byte *)((longlong)psVar13 + 7) * 0xe + 6;
  if (*(short *)(param_1 + 0x185a) == 0) {
    puVar1 = *(undefined1 **)(param_1 + 0x1928);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x100003) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x100003,puVar1,
                  0x38,param_2,param_3);
    }
    *(byte *)(psVar11 + 0xc) = *(byte *)(psVar11 + 0xc) | 1;
    *(undefined8 *)psVar11 = *(undefined8 *)(puVar1 + 0xc);
    *(undefined8 *)(psVar11 + 4) = *(undefined8 *)(puVar1 + 0xc);
    psVar11[0xb] = *(short *)(puVar1 + 8);
    *(undefined4 *)(psVar11 + 8) = *(undefined4 *)(puVar1 + 0x1c);
    if ((*(ushort *)(puVar1 + 0x20) >> 0xd & 1) != 0) {
      *(undefined1 *)(psVar11 + 0xd) = 0xfc;
    }
    if ((*(byte *)(param_1 + 0x18c0) & 0xe) == 2) {
      pcVar5 = (char *)(*(longlong *)(param_1 + 0x5a0) + 0x18);
      for (uVar8 = 0; uVar8 < *(byte *)(param_1 + 0x18cc); uVar8 = uVar8 + 1) {
        if ((*(short *)(pcVar5 + -6) == *psVar13) && (*pcVar5 == '\0')) {
          if (uVar8 != 0xffff) {
            if ((((byte)*(uint *)(psVar11 + 8) & 7) == 1) && ((*(uint *)(psVar11 + 8) & 0x680) != 0)
               ) {
              piVar12 = (int *)((ulonglong)uVar8 * 0x1c + *(longlong *)(param_1 + 0x5a0));
              if (piVar12[2] == -1) {
                uVar3 = FindEnclosureMappingSpace(param_1,piVar12,param_2,param_3);
                piVar12[2] = uVar3;
                if (uVar3 == 0xffffffff) {
                  if (*(char *)(param_1 + 0x11e5) == '\0') {
                    *(undefined1 *)(param_1 + 0x11e4) = 1;
                  }
                  else {
                    LogSystemEvent(param_1,0xad010044,0xc004af02,
                                   (byte *)
                                   "No space in mapping table for enclosure(ContinueIDReadsForPhyEvents)"
                                   ,param_2,param_3);
                  }
                  *(byte *)(psVar11 + 0xc) = *(byte *)(psVar11 + 0xc) & 0xf8;
                  uVar10 = 0;
                  psVar11[0] = 0;
                  psVar11[1] = 0;
                  psVar11[2] = 0;
                  psVar11[3] = 0;
                  psVar11[4] = 0;
                  psVar11[5] = 0;
                  psVar11[6] = 0;
                  psVar11[7] = 0;
                  psVar11[8] = 0;
                  psVar11[9] = 0;
                  psVar11[10] = 0;
                  psVar11[0xb] = 0;
                  *(undefined2 *)((longlong)psVar11 + 0x19) = 0;
                  bVar2 = 0;
                  if ((char)psVar13[2] != '\0') {
                    do {
                      psVar11 = psVar13 + uVar10 * 0xe + 6;
                      if (*(char *)((longlong)psVar11 + 0x19) == '\x01') {
                        *(byte *)(psVar11 + 0xc) = *(byte *)(psVar11 + 0xc) & 0xf8;
                        psVar11[0] = 0;
                        psVar11[1] = 0;
                        psVar11[2] = 0;
                        psVar11[3] = 0;
                        psVar11[4] = 0;
                        psVar11[5] = 0;
                        psVar11[6] = 0;
                        psVar11[7] = 0;
                        psVar11[8] = 0;
                        psVar11[9] = 0;
                        psVar11[10] = 0;
                        psVar11[0xb] = 0;
                        *(undefined2 *)((longlong)psVar11 + 0x19) = 0;
                      }
                      bVar2 = *(byte *)(psVar13 + 2);
                      bVar7 = (char)uVar10 + 1;
                      uVar10 = (ulonglong)bVar7;
                    } while (bVar7 < bVar2);
                  }
                  *(byte *)((longlong)psVar13 + 7) = bVar2;
                }
                else {
                  puVar6 = (undefined8 *)((ulonglong)uVar3 * 0x2c + *(longlong *)(param_1 + 0x5c0));
                  uVar9 = uVar3;
                  if (uVar3 < *(ushort *)(piVar12 + 5) + uVar3) {
                    do {
                      *(undefined4 *)((longlong)puVar6 + 0x14) = 0x20000000;
                      uVar9 = uVar9 + 1;
                      *puVar6 = *(undefined8 *)piVar12;
                      *(int *)(puVar6 + 2) = piVar12[3];
                      *(undefined1 *)(puVar6 + 4) = 0;
                      puVar6 = (undefined8 *)((longlong)puVar6 + 0x2c);
                    } while (uVar9 < *(ushort *)(piVar12 + 5) + uVar3);
                  }
                }
              }
              goto LAB_1400093ed;
            }
            *(byte *)(psVar11 + 0xc) = *(byte *)(psVar11 + 0xc) & 0xf8;
            goto LAB_1400093de;
          }
          break;
        }
        pcVar5 = pcVar5 + 0x1c;
      }
      LogSystemEvent(param_1,0xad010040,0xc004af02,
                     (byte *)"Enclosure not found (ContinueIDReadsForPhyEvents)",param_2,param_3);
      *(byte *)(psVar11 + 0xc) = *(byte *)(psVar11 + 0xc) & 0xf8;
LAB_1400093de:
      *(undefined2 *)((longlong)psVar11 + 0x19) = 0;
      psVar11[8] = 0;
      psVar11[9] = 0;
      psVar11[10] = 0;
      psVar11[0xb] = 0;
      psVar11[4] = 0;
      psVar11[5] = 0;
      psVar11[6] = 0;
      psVar11[7] = 0;
      psVar11[0] = 0;
      psVar11[1] = 0;
      psVar11[2] = 0;
      psVar11[3] = 0;
    }
LAB_1400093ed:
    if ((((byte)*(undefined4 *)(puVar1 + 0x1c) & 0x81) == 0x81) &&
       (*(char *)(param_1 + 0x11e6) == '\0')) {
      *(undefined1 *)(psVar11 + 0xd) = 0;
      SendSTPIdentifyCommand(param_1,*(uint *)(puVar1 + 0x1c),psVar11[10],param_2,param_3);
      return;
    }
  }
  else {
    LogSystemEvent(param_1,0xad010041,0xc004af02,
                   (byte *)"Read of SAS Dev Page0 failed (ContinueIDReadsForPhyEvents)",param_2,
                   param_3);
    *(byte *)(psVar11 + 0xc) = *(byte *)(psVar11 + 0xc) & 0xf8;
    psVar11[0] = 0;
    psVar11[1] = 0;
    psVar11[2] = 0;
    psVar11[3] = 0;
    psVar11[4] = 0;
    psVar11[5] = 0;
    psVar11[6] = 0;
    psVar11[7] = 0;
    psVar11[8] = 0;
    psVar11[9] = 0;
    psVar11[10] = 0;
    psVar11[0xb] = 0;
    *(undefined2 *)((longlong)psVar11 + 0x19) = 0;
  }
  uVar4 = ReadIDs(param_1,param_2,param_3);
  if ((char)uVar4 == '\0') {
    *(undefined1 *)(param_1 + 0x11de) = 0;
    RemoveDevice(param_1,param_2,param_3);
  }
  return;
}



===== ContinueIDReadsForPortEvents @ 140009440 =====

void ContinueIDReadsForPortEvents(longlong param_1,byte param_2,int param_3)

{
  undefined1 *puVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined8 *puVar8;
  byte bVar9;
  ushort uVar10;
  uint uVar11;
  ulonglong uVar12;
  short *psVar13;
  int *piVar14;
  short *psVar15;
  
  bVar2 = false;
  psVar15 = (short *)((ulonglong)((uint)*(ushort *)(param_1 + 0x5d6) * *(int *)(param_1 + 0x18ec)) +
                     *(longlong *)(param_1 + 0x5b0));
  psVar13 = psVar15 + (ulonglong)*(byte *)((longlong)psVar15 + 7) * 0xe + 6;
  if (*(short *)(param_1 + 0x185a) == 0) {
    puVar1 = *(undefined1 **)(param_1 + 0x1948);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x100004) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x100004,puVar1,
                  0x38,param_2,param_3);
    }
    bVar3 = *(byte *)(psVar13 + 10);
    uVar4 = *(uint *)(puVar1 + 0x1c) & 0xf;
    if (uVar4 == 1) {
      bVar2 = true;
    }
    else if ((uVar4 - 3 < 2) && (*(char *)(param_1 + 0x11e7) != '\0')) {
      *(byte *)(psVar13 + 10) = bVar3 | 1;
      *(undefined8 *)psVar13 = *(undefined8 *)(puVar1 + 0xc);
      psVar13[9] = *(short *)(puVar1 + 8);
      *(undefined4 *)(psVar13 + 4) = *(undefined4 *)(puVar1 + 0x1c);
      if ((*(uint *)(puVar1 + 0x20) & 0x2000) != 0) {
        *(undefined1 *)(psVar13 + 0xb) = 0xfc;
      }
      if ((*(byte *)(param_1 + 0x18c0) & 0xe) == 2) {
        pcVar7 = (char *)(*(longlong *)(param_1 + 0x5a0) + 0x18);
        for (uVar10 = 0; uVar10 < *(byte *)(param_1 + 0x18cc); uVar10 = uVar10 + 1) {
          if ((*(short *)(pcVar7 + -6) == *psVar15) && (*pcVar7 == '\0')) {
            if (uVar10 != 0xffff) {
              if ((*(uint *)(psVar13 + 4) & 7) == 0) {
                *(byte *)(psVar13 + 10) = bVar3 & 0xfc;
                goto LAB_140009745;
              }
              piVar14 = (int *)((ulonglong)uVar10 * 0x1c + *(longlong *)(param_1 + 0x5a0));
              if (piVar14[2] == -1) {
                uVar5 = FindEnclosureMappingSpace(param_1,piVar14,param_2,param_3);
                piVar14[2] = uVar5;
                if (uVar5 == 0xffffffff) {
                  if (*(char *)(param_1 + 0x11e5) == '\0') {
                    *(undefined1 *)(param_1 + 0x11e4) = 1;
                  }
                  else {
                    LogSystemEvent(param_1,0xad010044,0xc004af02,
                                   (byte *)
                                   "No space in mapping table for enclosure(ContinueIDReadsForPortEvents)"
                                   ,param_2,param_3);
                  }
                  *(byte *)(psVar13 + 10) = *(byte *)(psVar13 + 10) & 0xfc;
                  uVar12 = 0;
                  psVar13[0] = 0;
                  psVar13[1] = 0;
                  psVar13[2] = 0;
                  psVar13[3] = 0;
                  psVar13[4] = 0;
                  psVar13[5] = 0;
                  psVar13[6] = 0;
                  psVar13[7] = 0;
                  psVar13[8] = 0;
                  psVar13[9] = 0;
                  *(undefined2 *)((longlong)psVar13 + 0x15) = 0;
                  *(undefined1 *)((longlong)psVar13 + 0x17) = 0;
                  psVar13[0xc] = 0;
                  bVar3 = 0;
                  if ((char)psVar15[2] != '\0') {
                    do {
                      psVar13 = psVar15 + uVar12 * 0xe + 6;
                      if (*(char *)((longlong)psVar13 + 0x15) == '\x01') {
                        *(byte *)(psVar13 + 10) = *(byte *)(psVar13 + 10) & 0xfc;
                        psVar13[0] = 0;
                        psVar13[1] = 0;
                        psVar13[2] = 0;
                        psVar13[3] = 0;
                        psVar13[4] = 0;
                        psVar13[5] = 0;
                        psVar13[6] = 0;
                        psVar13[7] = 0;
                        psVar13[8] = 0;
                        psVar13[9] = 0;
                        *(undefined2 *)((longlong)psVar13 + 0x15) = 0;
                        *(undefined1 *)((longlong)psVar13 + 0x17) = 0;
                        psVar13[0xc] = 0;
                      }
                      bVar3 = *(byte *)(psVar15 + 2);
                      bVar9 = (char)uVar12 + 1;
                      uVar12 = (ulonglong)bVar9;
                    } while (bVar9 < bVar3);
                  }
                  *(byte *)((longlong)psVar15 + 7) = bVar3;
                }
                else {
                  puVar8 = (undefined8 *)((ulonglong)uVar5 * 0x2c + *(longlong *)(param_1 + 0x5c0));
                  uVar11 = uVar5;
                  if (uVar5 < *(ushort *)(piVar14 + 5) + uVar5) {
                    do {
                      *(undefined4 *)((longlong)puVar8 + 0x14) = 0x20000000;
                      uVar11 = uVar11 + 1;
                      *puVar8 = *(undefined8 *)piVar14;
                      *(int *)(puVar8 + 2) = piVar14[3];
                      *(undefined1 *)(puVar8 + 4) = 0;
                      puVar8 = (undefined8 *)((longlong)puVar8 + 0x2c);
                    } while (uVar11 < *(ushort *)(piVar14 + 5) + uVar5);
                  }
                }
              }
              goto LAB_14000975b;
            }
            break;
          }
          pcVar7 = pcVar7 + 0x1c;
        }
        LogSystemEvent(param_1,0xad010040,0xc004af02,
                       (byte *)"Enclosure not found (ContinueIDReadsForPortEvents)",param_2,param_3)
        ;
        *(byte *)(psVar13 + 10) = *(byte *)(psVar13 + 10) & 0xfc;
LAB_140009745:
        psVar13[0xc] = 0;
        *(undefined1 *)((longlong)psVar13 + 0x17) = 0;
        *(undefined2 *)((longlong)psVar13 + 0x15) = 0;
        psVar13[8] = 0;
        psVar13[9] = 0;
        psVar13[4] = 0;
        psVar13[5] = 0;
        psVar13[6] = 0;
        psVar13[7] = 0;
        psVar13[0] = 0;
        psVar13[1] = 0;
        psVar13[2] = 0;
        psVar13[3] = 0;
      }
LAB_14000975b:
      if (uVar4 == 3) {
        *(undefined1 *)(param_1 + 0x11e0) = 1;
        *(undefined1 *)(param_1 + 0x9ba) = 1;
        SendExtendedConfigPageMessage
                  (param_1,'\x01',(char *)(param_1 + 0x1950),(ushort)psVar13[8] | 0x20000000,
                   (int)*(undefined8 *)(param_1 + 0x1958),param_2,param_3);
        return;
      }
      goto LAB_1400097f8;
    }
    psVar13[0] = 0;
    psVar13[1] = 0;
    psVar13[2] = 0;
    psVar13[3] = 0;
    psVar13[4] = 0;
    psVar13[5] = 0;
    psVar13[6] = 0;
    psVar13[7] = 0;
    psVar13[8] = 0;
    psVar13[9] = 0;
    *(byte *)(psVar13 + 10) = bVar3 & 0xfc;
    *(undefined2 *)((longlong)psVar13 + 0x15) = 0;
    *(undefined1 *)((longlong)psVar13 + 0x17) = 0;
    psVar13[0xc] = 0;
    if (!bVar2) {
      LogSystemEvent(param_1,0xad010092,0xc004af02,(byte *)"Unsupported Pcie device protocol",
                     param_2,param_3);
    }
  }
  else {
    LogSystemEvent(param_1,0xad010041,0xc004af02,
                   (byte *)"Read of PCIe Dev Page0 failed (ContinueIDReadsForPortEvents)",param_2,
                   param_3);
    *(byte *)(psVar13 + 10) = *(byte *)(psVar13 + 10) & 0xfc;
    psVar13[0] = 0;
    psVar13[1] = 0;
    psVar13[2] = 0;
    psVar13[3] = 0;
    psVar13[4] = 0;
    psVar13[5] = 0;
    psVar13[6] = 0;
    psVar13[7] = 0;
    psVar13[8] = 0;
    psVar13[9] = 0;
    *(undefined2 *)((longlong)psVar13 + 0x15) = 0;
    *(undefined1 *)((longlong)psVar13 + 0x17) = 0;
    psVar13[0xc] = 0;
  }
LAB_1400097f8:
  uVar6 = ReadPcieIDs(param_1,param_2,param_3);
  if ((char)uVar6 == '\0') {
    *(undefined1 *)(param_1 + 0x11df) = 0;
    RemoveDevice(param_1,param_2,param_3);
  }
  return;
}



===== ContinueMDTSReadsForPortEvents @ 140009840 =====

void ContinueMDTSReadsForPortEvents(longlong param_1,byte param_2,int param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  
  *(undefined1 *)(param_1 + 0x11e0) = 0;
  lVar3 = (ulonglong)((uint)*(ushort *)(param_1 + 0x5d6) * *(int *)(param_1 + 0x18ec)) +
          *(longlong *)(param_1 + 0x5b0);
  lVar2 = (ulonglong)*(byte *)(lVar3 + 7) * 0x1c;
  if (*(short *)(param_1 + 0x185a) == 0) {
    *(undefined4 *)(lVar2 + 0x18 + lVar3) = *(undefined4 *)(*(longlong *)(param_1 + 0x1958) + 0xc);
    *(undefined1 *)(lVar2 + 0x23 + lVar3) = *(undefined1 *)(*(longlong *)(param_1 + 0x1958) + 10);
    *(undefined2 *)(lVar2 + 0x24 + lVar3) = *(undefined2 *)(*(longlong *)(param_1 + 0x1958) + 0x16);
  }
  else {
    LogSystemEvent(param_1,0xad010093,0xc004af02,
                   (byte *)"Pcie Device Page 2 config page read failed",param_2,param_3);
  }
  uVar1 = ReadPcieIDs(param_1,param_2,param_3);
  if ((char)uVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x11df) = 0;
    RemoveDevice(param_1,param_2,param_3);
  }
  return;
}



===== FindEnclosureMappingSpace @ 140009920 =====

uint FindEnclosureMappingSpace(longlong param_1,int *param_2,byte param_3,int param_4)

{
  byte bVar1;
  longlong lVar2;
  uint *puVar3;
  ushort uVar4;
  ulonglong uVar5;
  char *pcVar6;
  uint uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  uint uVar10;
  ushort uVar11;
  
  uVar7 = *(uint *)(param_1 + 0x9bc);
  uVar4 = 0;
  uVar5 = 0;
  if (uVar7 != 0) {
    lVar9 = *(longlong *)(param_1 + 0x5c0);
    do {
      lVar2 = uVar5 * 0x2c;
      if (((*(int *)(lVar2 + lVar9) == *param_2) && (*(int *)(lVar2 + 4 + lVar9) == param_2[1])) &&
         ((uVar10 = *(uint *)(lVar2 + 0x10 + lVar9), uVar10 == 0 || ((param_2[3] & uVar10) != 0))))
      {
        uVar4 = uVar4 + 1;
        if (uVar4 == *(ushort *)(param_2 + 5)) {
          return ((int)uVar5 - (uint)uVar4) + 1;
        }
      }
      else {
        uVar4 = 0;
      }
      uVar10 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar10;
    } while (uVar10 < uVar7);
    uVar4 = 0;
    uVar10 = 0;
    do {
      if ((*(uint *)((ulonglong)uVar10 * 0x2c + 0x14 + lVar9) & 0x20000000) == 0) {
        uVar4 = uVar4 + 1;
        if (uVar4 == *(ushort *)(param_2 + 5)) {
          return (uVar10 - uVar4) + 1;
        }
      }
      else {
        uVar4 = 0;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar7);
  }
  do {
    do {
      uVar4 = GetHighMissingEncTableIndex(param_1);
      if (uVar4 == 0xffff) {
        return 0xffffffff;
      }
      lVar9 = (ulonglong)uVar4 * 0x1c + *(longlong *)(param_1 + 0x5a0);
      uVar10 = *(uint *)(lVar9 + 8);
      uVar5 = (ulonglong)uVar10;
      *(undefined1 *)(lVar9 + 0x1a) = 1;
      if (uVar10 < *(ushort *)(lVar9 + 0x14) + uVar10) {
        puVar3 = (uint *)(uVar5 * 0x2c + 0x14 + *(longlong *)(param_1 + 0x5c0));
        do {
          *puVar3 = *puVar3 & 0xdfffffff;
          puVar3 = puVar3 + 0xb;
          uVar10 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar10;
        } while (uVar10 < (uint)*(ushort *)(lVar9 + 0x14) + *(int *)(lVar9 + 8));
      }
      uVar4 = 0;
      uVar10 = 0;
    } while (uVar7 == 0);
    do {
      if ((*(uint *)((ulonglong)uVar10 * 0x2c + 0x14 + *(longlong *)(param_1 + 0x5c0)) & 0x20000000)
          == 0) {
        uVar4 = uVar4 + 1;
        if (uVar4 == *(ushort *)(param_2 + 5)) {
          uVar7 = (uVar10 - uVar4) + 1;
          if (uVar7 < uVar4 + uVar7) {
            lVar9 = (ulonglong)uVar7 * 0x2c;
            uVar10 = uVar7;
            do {
              uVar11 = 0;
              bVar1 = 0;
              if (*(char *)(param_1 + 0x18cc) != '\0') {
                pcVar6 = (char *)(*(longlong *)(param_1 + 0x5a0) + 0x19);
                do {
                  if ((*(uint *)(pcVar6 + -0x11) <= uVar10) &&
                     (uVar10 < (uint)*(ushort *)(pcVar6 + -5) + *(uint *)(pcVar6 + -0x11))) {
                    if (*pcVar6 == '\0') {
                      *pcVar6 = '\x01';
                      AddToRemovalTable(param_1,0,*(short *)(pcVar6 + -9),param_3,param_4);
                    }
                    puVar8 = (undefined8 *)(*(longlong *)(param_1 + 0x5c0) + lVar9);
                    if ((*(uint *)((longlong)puVar8 + 0x14) & 0x10000000) != 0) {
                      AddToRemovalTable(param_1,*(short *)((longlong)puVar8 + 0x1a),0,param_3,
                                        param_4);
                      puVar8[3] = 0xffff;
                      *puVar8 = 0;
                      puVar8[1] = 0;
                      puVar8[2] = 0;
                      *(undefined2 *)(puVar8 + 4) = 0;
                      *(undefined1 *)((longlong)puVar8 + 0x22) = *(undefined1 *)(param_1 + 0x9a2);
                      *(undefined2 *)((longlong)puVar8 + 0x23) = 0;
                      *(undefined1 *)((longlong)puVar8 + 0x27) = 0;
                      *(undefined2 *)(puVar8 + 5) = 0;
                    }
                  }
                  bVar1 = *(byte *)(param_1 + 0x18cc);
                  uVar11 = uVar11 + 1;
                  pcVar6 = pcVar6 + 0x1c;
                } while (uVar11 < bVar1);
              }
              uVar10 = uVar10 + 1;
              lVar9 = lVar9 + 0x2c;
            } while (uVar10 < uVar4 + uVar7);
          }
          else {
            bVar1 = *(byte *)(param_1 + 0x18cc);
          }
          puVar8 = *(undefined8 **)(param_1 + 0x5a0);
          uVar4 = 0;
          if (bVar1 != 0) {
            do {
              if (*(char *)((longlong)puVar8 + 0x19) == '\0') {
                uVar10 = *(uint *)(puVar8 + 1);
                uVar5 = (ulonglong)uVar10;
                if (uVar10 < *(ushort *)((longlong)puVar8 + 0x14) + uVar10) {
                  puVar3 = (uint *)(uVar5 * 0x2c + 0x14 + *(longlong *)(param_1 + 0x5c0));
                  do {
                    *puVar3 = *puVar3 | 0x20000000;
                    puVar3 = puVar3 + 0xb;
                    uVar10 = (int)uVar5 + 1;
                    uVar5 = (ulonglong)uVar10;
                  } while (uVar10 < (uint)*(ushort *)((longlong)puVar8 + 0x14) +
                                    *(int *)(puVar8 + 1));
                }
              }
              else {
                *puVar8 = 0;
                *(undefined4 *)(puVar8 + 1) = 0xffffffff;
                *(undefined4 *)((longlong)puVar8 + 0xc) = 0;
                puVar8[2] = 0xffff;
                *(undefined2 *)(puVar8 + 3) = 0;
                *(undefined1 *)((longlong)puVar8 + 0x1b) = 0;
              }
              *(undefined1 *)((longlong)puVar8 + 0x1a) = 0;
              uVar4 = uVar4 + 1;
              puVar8 = (undefined8 *)((longlong)puVar8 + 0x1c);
            } while (uVar4 < *(byte *)(param_1 + 0x18cc));
          }
          return uVar7;
        }
      }
      else {
        uVar4 = 0;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar7);
  } while( true );
}



===== FlushAllDPMPage0 @ 140009d20 =====

void FlushAllDPMPage0(longlong param_1,byte param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = 0;
  if ((*(byte *)(param_1 + 0x18c0) & 1) == 0) {
    uVar2 = 0;
    if (*(ushort *)(param_1 + 0x18bc) != 0) {
      do {
        uVar4 = (ulonglong)uVar2;
        if (*(char *)(uVar4 + *(longlong *)(param_1 + 0x18d8)) != '\0') {
          lVar1 = *(longlong *)(param_1 + 0x1910);
          *(undefined4 *)(lVar1 + 0x18 + uVar4 * 0x14) = 0;
          ZeroMemory(*(void **)(param_1 + 0x1918),8);
          memmove((void *)(*(longlong *)(param_1 + 0x1918) + 8),(void *)(lVar1 + uVar4 * 0x14 + 8),
                  0x14);
          *(undefined1 *)(param_1 + 0x11da) = 1;
          SendExtendedConfigPageMessage
                    (param_1,'\x04',(char *)(param_1 + 0x1908),uVar2 | 0x10000,
                     (int)*(undefined8 *)(param_1 + 0x1918),param_2,param_3);
          *(undefined1 *)(uVar4 + *(longlong *)(param_1 + 0x18d8)) = 0;
          break;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(ushort *)(param_1 + 0x18bc));
    }
  }
  do {
    if (*(char *)(param_1 + 0x11da) == '\0') {
      return;
    }
    PollLSImpiIsr(param_1,param_2,param_3);
    StorPortStallExecution(1000);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 60000);
  return;
}



===== FlushDPMPage0Entry @ 140009e60 =====

void FlushDPMPage0Entry(longlong param_1,byte param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if ((*(byte *)(param_1 + 0x18c0) & 1) == 0) {
    uVar3 = 0;
    if (*(ushort *)(param_1 + 0x18bc) != 0) {
      do {
        if (*(char *)(uVar3 + *(longlong *)(param_1 + 0x18d8)) != '\0') {
          lVar1 = *(longlong *)(param_1 + 0x1910);
          *(undefined4 *)(lVar1 + 0x18 + uVar3 * 0x14) = 0;
          ZeroMemory(*(void **)(param_1 + 0x1918),8);
          memmove((void *)(*(longlong *)(param_1 + 0x1918) + 8),(void *)(lVar1 + uVar3 * 0x14 + 8),
                  0x14);
          *(undefined1 *)(param_1 + 0x11da) = 1;
          SendExtendedConfigPageMessage
                    (param_1,'\x04',(char *)(param_1 + 0x1908),(uint)uVar3 | 0x10000,
                     (int)*(undefined8 *)(param_1 + 0x1918),param_2,param_3);
          *(undefined1 *)(uVar3 + *(longlong *)(param_1 + 0x18d8)) = 0;
          return;
        }
        uVar2 = (uint)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(ushort *)(param_1 + 0x18bc));
    }
  }
  return;
}



===== GetBusTargetFromDevHandle @ 140009f60 =====

ulonglong GetBusTargetFromDevHandle
                    (longlong param_1,short param_2,undefined2 *param_3,undefined2 *param_4)

{
  ulonglong uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  uVar1 = *(ulonglong *)(param_1 + 0x5c0);
  if (*(uint *)(param_1 + 0x9bc) != 0) {
    do {
      if (*(short *)(uVar1 + 0x1a) == param_2) {
        *param_3 = *(undefined2 *)(uVar1 + 0x1c);
        *param_4 = *(undefined2 *)(uVar1 + 0x1e);
        return CONCAT71((int7)(uVar1 >> 8),1);
      }
      uVar2 = uVar2 + 1;
      uVar1 = uVar1 + 0x2c;
    } while ((uint)uVar2 < *(uint *)(param_1 + 0x9bc));
  }
  return uVar1 & 0xffffffffffffff00;
}



===== GetDPMPage0IndexFromID @ 140009fb0 =====

ushort GetDPMPage0IndexFromID(longlong param_1,undefined8 param_2,uint param_3)

{
  int *piVar1;
  ushort uVar2;
  int iStackX_14;
  
  uVar2 = 0;
  piVar1 = (int *)(*(longlong *)(param_1 + 0x1910) + 8);
  if (*(ushort *)(param_1 + 0x18bc) != 0) {
    iStackX_14 = (int)((ulonglong)param_2 >> 0x20);
    do {
      if ((((*(char *)((ulonglong)uVar2 + *(longlong *)(param_1 + 0x18d0)) != '\0') &&
           (*piVar1 == (int)param_2)) && (piVar1[1] == iStackX_14)) &&
         (((param_3 == 0 || (piVar1[3] == 0)) || ((param_3 & piVar1[3]) != 0)))) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 5;
    } while (uVar2 < *(ushort *)(param_1 + 0x18bc));
  }
  return 0xffff;
}



===== GetHighMissingEncTableIndex @ 14000a030 =====

ushort GetHighMissingEncTableIndex(longlong param_1)

{
  char *pcVar1;
  ushort uVar2;
  byte bVar3;
  ushort uVar4;
  
  bVar3 = 0;
  uVar2 = 0;
  uVar4 = 0xffff;
  if (*(byte *)(param_1 + 0x18cc) != 0) {
    pcVar1 = (char *)(*(longlong *)(param_1 + 0x5a0) + 0x1a);
    do {
      if ((bVar3 < (byte)pcVar1[-2]) && (*pcVar1 == '\0')) {
        bVar3 = pcVar1[-2];
        uVar4 = uVar2;
      }
      uVar2 = uVar2 + 1;
      pcVar1 = pcVar1 + 0x1c;
    } while (uVar2 < *(byte *)(param_1 + 0x18cc));
  }
  return uVar4;
}



===== GetMapTableIndexFromHandle @ 14000a080 =====

uint GetMapTableIndexFromHandle(longlong param_1,short param_2)

{
  uint uVar1;
  short *psVar2;
  
  uVar1 = 0;
  psVar2 = (short *)(*(longlong *)(param_1 + 0x5c0) + 0x1a);
  while( true ) {
    if (*(uint *)(param_1 + 0x9bc) <= uVar1) {
      return 0xffffffff;
    }
    if (*psVar2 == param_2) break;
    uVar1 = uVar1 + 1;
    psVar2 = psVar2 + 0x16;
  }
  return uVar1;
}



===== MapSODChecks @ 14000a0c0 =====

void MapSODChecks(longlong param_1,byte param_2,int param_3)

{
  longlong lVar1;
  short sVar2;
  ushort uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = *(ushort *)(param_1 + 0x18c0) & 0xe;
  if (uVar3 == 2) {
    puVar5 = *(undefined4 **)(param_1 + 0x5a0);
    uVar7 = 0;
    if (*(char *)(param_1 + 0x18cc) != '\0') {
      do {
        if (*(char *)((longlong)puVar5 + 0x1b) == '\0') {
          if (((*(byte *)(puVar5 + 6) < 0xf) &&
              (*(byte *)(puVar5 + 6) = *(byte *)(puVar5 + 6) + 1,
              (*(byte *)(param_1 + 0x18c0) & 1) == 0)) && (*(ushort *)(puVar5 + 4) != 0xffff)) {
            lVar1 = *(longlong *)(param_1 + 0x1910) + (ulonglong)*(ushort *)(puVar5 + 4) * 0x14;
            *(undefined4 *)(lVar1 + 8) = *puVar5;
            *(undefined4 *)(lVar1 + 0xc) = puVar5[1];
            lVar4 = (ulonglong)(uint)puVar5[2] * 0x2c + *(longlong *)(param_1 + 0x5c0);
            sVar2 = *(short *)(lVar4 + 0x1c) * 0x80;
            *(short *)(lVar1 + 0x12) = sVar2;
            *(short *)(lVar1 + 0x12) = *(short *)(lVar4 + 0x1e) + sVar2;
            sVar2 = *(short *)(puVar5 + 5);
            *(short *)(lVar1 + 0x10) = sVar2 << 4;
            *(ushort *)(lVar1 + 0x10) = (ushort)*(byte *)(puVar5 + 6) | sVar2 << 4;
            *(undefined4 *)(lVar1 + 0x14) = puVar5[3];
            *(undefined4 *)(lVar1 + 0x18) = 0;
            ZeroMemory(*(void **)(param_1 + 0x1918),8);
            memmove((void *)(*(longlong *)(param_1 + 0x1918) + 8),(void *)(lVar1 + 8),0x14);
            uVar3 = *(ushort *)(puVar5 + 4);
            *(undefined1 *)(param_1 + 0x9ba) = 1;
            *(undefined1 *)(param_1 + 0x11e1) = 1;
            SendExtendedConfigPageMessage
                      (param_1,'\x04',(char *)(param_1 + 0x1908),uVar3 | 0x10000,
                       (int)*(undefined8 *)(param_1 + 0x1918),param_2,param_3);
            uVar6 = 0;
            do {
              PollLSImpiIsr(param_1,param_2,param_3);
              if (*(char *)(param_1 + 0x11e1) == '\0') goto LAB_14000a299;
              StorPortStallExecution(500);
              uVar6 = uVar6 + 1;
            } while (uVar6 < 120000);
            if (*(char *)(param_1 + 0x11e1) != '\0') {
              LogSystemEvent(param_1,0xad01004b,0xc004af02,
                             (byte *)"Start-of-Day Check Failed (MapSODChecks)",param_2,param_3);
            }
          }
LAB_14000a299:
          *(undefined1 *)((longlong)puVar5 + 0x1b) = 1;
        }
        uVar7 = uVar7 + 1;
        puVar5 = puVar5 + 7;
      } while (uVar7 < *(byte *)(param_1 + 0x18cc));
    }
  }
  else if (uVar3 == 0) {
    SODCheckMapEntry(param_1,*(longlong *)(param_1 + 0x5c0),0,*(uint *)(param_1 + 0x9bc),param_2,
                     param_3);
    return;
  }
  return;
}



===== ProcessDPMPage0 @ 14000a310 =====

void ProcessDPMPage0(longlong param_1,byte param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  undefined8 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  int *piVar8;
  ushort uVar9;
  byte bVar10;
  ushort uVar11;
  uint uVar12;
  char *pcVar13;
  
  if ((*(byte *)(param_1 + 0x18c0) & 1) == 0) {
    piVar8 = (int *)(*(longlong *)(param_1 + 0x1910) + 8);
    uVar9 = 0;
    if (*(short *)(param_1 + 0x18bc) != 0) {
      do {
        if ((*piVar8 == 0) && (piVar8[1] == 0)) {
          *(undefined1 *)((ulonglong)uVar9 + *(longlong *)(param_1 + 0x18d0)) = 0;
        }
        else {
          *(undefined1 *)((ulonglong)uVar9 + *(longlong *)(param_1 + 0x18d0)) = 1;
          bVar10 = *(byte *)(piVar8 + 2) & 0xf;
          uVar11 = *(ushort *)((longlong)piVar8 + 10);
          uVar7 = (ulonglong)uVar11;
          uVar3 = *(ushort *)(param_1 + 0x18c0) & 0xe;
          uVar5 = (uint)uVar11;
          if (uVar3 == 2) {
            bVar1 = *(byte *)(param_1 + 0x18cc);
            uVar11 = *(ushort *)(piVar8 + 2) >> 4 & 0x7f;
            if (*(ushort *)(param_1 + 0x99e) <= (ushort)bVar1) {
              pcVar13 = "Enclosure Table Full (ProcessDPMPage0)";
              uVar6 = 0xad010046;
LAB_14000a515:
              LogSystemEvent(param_1,uVar6,0xc004af02,(byte *)pcVar13,param_2,param_3);
              return;
            }
            *(byte *)(param_1 + 0x18cc) = bVar1 + 1;
            puVar4 = (undefined8 *)((ulonglong)bVar1 * 0x1c + *(longlong *)(param_1 + 0x5a0));
            *puVar4 = *(undefined8 *)piVar8;
            *(uint *)(puVar4 + 1) = uVar5;
            iVar2 = piVar8[3];
            *(ushort *)((longlong)puVar4 + 0x14) = uVar11;
            *(int *)((longlong)puVar4 + 0xc) = iVar2;
            *(ushort *)(puVar4 + 2) = uVar9;
            uVar12 = uVar11 + uVar5;
            *(undefined2 *)((longlong)puVar4 + 0x16) = 0;
            *(byte *)(puVar4 + 3) = bVar10;
            *(undefined2 *)((longlong)puVar4 + 0x19) = 0;
            *(undefined1 *)((longlong)puVar4 + 0x1b) = 0;
            puVar4 = (undefined8 *)(uVar7 * 0x2c + *(longlong *)(param_1 + 0x5c0));
            while (uVar5 < uVar12) {
              if (*(short *)(puVar4 + 3) != -1) {
                LogSystemEvent(param_1,0xad010042,0xc004af02,
                               (byte *)
                               "encl-slot mapping of a new device conflicts with an existing entry",
                               param_2,param_3);
                break;
              }
              *puVar4 = *(undefined8 *)piVar8;
              *(int *)(puVar4 + 2) = piVar8[3];
              *(short *)((longlong)puVar4 + 0x1c) = (short)((uint)uVar7 >> 7);
              *(ushort *)(puVar4 + 3) = uVar9;
              *(ushort *)((longlong)puVar4 + 0x1e) = (ushort)uVar7 & 0x7f;
              uVar5 = (uint)uVar7 + 1;
              uVar7 = (ulonglong)uVar5;
              *(byte *)(puVar4 + 4) = bVar10;
              *(undefined4 *)((longlong)puVar4 + 0x14) = 0x20000000;
              puVar4 = (undefined8 *)((longlong)puVar4 + 0x2c);
            }
          }
          else if (uVar3 == 0) {
            puVar4 = (undefined8 *)(uVar7 * 0x2c + *(longlong *)(param_1 + 0x5c0));
            if (*(short *)(puVar4 + 3) != -1) {
              pcVar13 = "addr mapping of a new device conflicts with an existing entry";
              uVar6 = 0xad010042;
              goto LAB_14000a515;
            }
            *puVar4 = *(undefined8 *)piVar8;
            *(ushort *)((longlong)puVar4 + 0x1c) = uVar11 >> 7;
            *(ushort *)((longlong)puVar4 + 0x1e) = uVar11 & 0x7f;
            *(ushort *)(puVar4 + 3) = uVar9;
            *(byte *)(puVar4 + 4) = bVar10;
            *(undefined4 *)((longlong)puVar4 + 0x14) = 0x20000000;
          }
        }
        uVar9 = uVar9 + 1;
        piVar8 = piVar8 + 5;
      } while (uVar9 < *(ushort *)(param_1 + 0x18bc));
    }
  }
  return;
}



===== ProcessPcieTopologyChangeList @ 14000a550 =====

void ProcessPcieTopologyChangeList(longlong param_1,ushort *param_2,byte param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  byte bVar4;
  ushort *puVar5;
  ushort *puVar6;
  byte bVar7;
  ushort uVar8;
  ushort *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  int iVar12;
  
  *(undefined4 *)(param_1 + 0x11e8) = 0x1e;
  bVar7 = (byte)param_2[0x12];
  uVar2 = (uint)(ushort)((ushort)bVar7 * 8 + 0xc);
  if (((uVar2 + 0x1c == (uint)(byte)param_2[1] << 2) && (uVar2 == (uint)*param_2 << 2)) &&
     (bVar7 != 0)) {
    puVar6 = param_2 + 0x14;
    uVar8 = 0;
    if (bVar7 != 0) {
      puVar9 = param_2 + 0x15;
      do {
        bVar4 = (byte)*puVar9 & 0xf;
        if (((bVar4 - 1 & 0xfa) == 0) && (bVar4 != 6)) {
          iVar1 = *(int *)(param_1 + 0x18e8);
          puVar9 = (ushort *)
                   ((ulonglong)((uint)*(ushort *)(param_1 + 0x5d6) * iVar1) +
                   *(longlong *)(param_1 + 0x5b0));
          if ((char)puVar9[2] != '\0') {
            LogSystemEvent(param_1,0xad010078,0xc004af02,(byte *)"Pcie Event List is full",param_3,
                           param_4);
            return;
          }
          puVar5 = puVar9 + 0x10;
          *puVar9 = param_2[0xe];
          puVar9[1] = param_2[0xf];
          *(char *)(puVar9 + 2) = (char)param_2[0x12];
          *(char *)((longlong)puVar9 + 5) = (char)param_2[0x10];
          *(undefined1 *)(puVar9 + 3) = *(undefined1 *)((longlong)param_2 + 0x25);
          *(undefined1 *)((longlong)puVar9 + 7) = 0;
          *(char *)(puVar9 + 4) = (char)param_2[0x13];
          uVar11 = (ulonglong)bVar7;
          do {
            uVar10 = uVar11;
            bVar7 = (byte)puVar6[1] & 0xf;
            if (((bVar7 - 1 & 0xfa) == 0) && (bVar7 != 6)) {
              puVar5[-2] = *puVar6;
              uVar8 = puVar6[1];
              *(byte *)puVar5 = (byte)*puVar5 & 0xfe;
              *(byte *)((longlong)puVar5 + 1) = (byte)uVar8;
              puVar5 = puVar5 + 0xe;
            }
            else {
              *(char *)(puVar9 + 2) = (char)puVar9[2] + -1;
            }
            puVar6 = puVar6 + 4;
            uVar11 = uVar10 - 1;
          } while (uVar11 != 0);
          iVar12 = 0;
          if (((uint)*(ushort *)(param_1 + 0x5d6) * 2 - *(int *)(param_1 + 0x5b0)) + (int)puVar9 <=
              *(uint *)(param_1 + 0x5d0)) {
            iVar12 = iVar1 + 1;
          }
          *(int *)(param_1 + 0x18e8) = iVar12;
          if (*(char *)(param_1 + 0x11dc) != '\0') {
            return;
          }
          if (*(char *)(param_1 + 0x11dd) != '\0') {
            return;
          }
          if ((*(int *)(param_1 + 0x970) == 0) && (*(int *)(param_1 + 0x1218) == 0)) {
            PauseAdapterQueue(param_1,(char)uVar10 + '\x04',param_3,param_4);
            ResetActive(param_1,0x13,param_3,param_4);
          }
          *(undefined1 *)(param_1 + 0x11dd) = 1;
          UpdatePcieMissingCount(param_1,param_3,param_4);
          uVar3 = ReadPcieIDs(param_1,param_3,param_4);
          if ((char)uVar3 == '\0') {
            *(undefined1 *)(param_1 + 0x11df) = 0;
            RemoveDevice(param_1,param_3,param_4);
            return;
          }
          return;
        }
        uVar8 = uVar8 + 1;
        puVar9 = puVar9 + 4;
      } while (uVar8 < bVar7);
    }
  }
  else {
    LogSystemEvent(param_1,0xad01003d,0xc004af02,
                   (byte *)"Wrong Event Data Length (PcieTopologyChangeList)",param_3,param_4);
  }
  return;
}



===== ProcessSasEnclosureStatusChange @ 14000a7d0 =====

void ProcessSasEnclosureStatusChange(longlong param_1,longlong param_2,byte param_3,int param_4)

{
  longlong lVar1;
  byte bVar2;
  undefined8 uVar3;
  bool bVar4;
  char cVar5;
  ushort uVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 uVar10;
  longlong lVar11;
  char *pcVar12;
  undefined8 *puVar13;
  uint uVar14;
  ulonglong uVar15;
  undefined8 local_res8;
  longlong local_res10;
  
  *(undefined4 *)(param_1 + 0x11e8) = 0x1e;
  bVar4 = false;
  if ((*(byte *)(param_1 + 0x18c0) & 0xe) == 2) {
    local_res10 = param_2;
    if (*(char *)(param_2 + 0x1e) == '\x01') {
      if (*(short *)(param_2 + 0x28) == 0) {
        LogSystemEvent(param_1,0xad010052,0x8004af01,
                       (byte *)"An enclosure was not attached that had 0 number of slots",param_3,
                       param_4);
        return;
      }
      uVar3 = *(undefined8 *)(param_2 + 0x20);
      uVar6 = 0;
      if (*(byte *)(param_1 + 0x18cc) != 0) {
        local_res8._4_4_ = (int)((ulonglong)uVar3 >> 0x20);
        piVar9 = *(int **)(param_1 + 0x5a0);
LAB_14000a8a0:
        if (((*piVar9 != (int)uVar3) || (piVar9[1] != local_res8._4_4_)) ||
           ((piVar9[3] != 0 && ((*(uint *)(param_2 + 0x2c) & piVar9[3]) == 0)))) goto LAB_14000a8b9;
        if (uVar6 != 0xffff) {
          piVar9 = *(int **)(param_1 + 0x5a0) + (ulonglong)uVar6 * 7;
          if ((*(char *)((longlong)piVar9 + 0x1b) != '\0') && ((char)piVar9[6] == '\0')) {
            pcVar12 = "Received an add enclosure event for an enclosure that is already active";
            uVar7 = 0xad01004c;
            uVar10 = 0x8004af01;
            local_res8 = uVar3;
            goto LAB_14000a8f6;
          }
          *(undefined2 *)((longlong)piVar9 + 0x12) = *(undefined2 *)(param_2 + 0x1c);
          *(undefined2 *)((longlong)piVar9 + 0x16) = *(undefined2 *)(param_2 + 0x2a);
          uVar6 = *(ushort *)(param_2 + 0x28);
          uVar7 = CONCAT22((short)piVar9[5],uVar6);
          local_res8._6_2_ = (undefined2)((ulonglong)uVar3 >> 0x30);
          local_res8._0_6_ =
               CONCAT24(uVar6,CONCAT22((short)piVar9[5],*(undefined2 *)(param_2 + 0x1c)));
          if (*(ushort *)(piVar9 + 5) < uVar6) {
            LogSystemEvent(param_1,uVar7,0x4004af00,
                           (byte *)"Existing encl came with more num of slots than it had before",
                           param_3,param_4);
            if ((*(char *)(param_1 + 0x608) != '\0') &&
               ((*(uint *)(param_1 + 0x60c) & 0x100009) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x100009
                          ,(undefined1 *)&local_res8,6,param_3,param_4);
            }
            AddToRemovalTable(param_1,0,(short)piVar9[4],param_3,param_4);
            uVar14 = piVar9[2];
            uVar15 = (ulonglong)uVar14;
            puVar13 = (undefined8 *)(uVar15 * 0x2c + *(longlong *)(param_1 + 0x5c0));
            if (uVar14 < *(ushort *)(piVar9 + 5) + uVar14) {
              do {
                if (*(short *)((longlong)puVar13 + 0x1a) != 0) {
                  AddToRemovalTable(param_1,*(short *)((longlong)puVar13 + 0x1a),0,param_3,param_4);
                  *puVar13 = 0;
                  puVar13[1] = 0;
                  puVar13[2] = 0;
                  puVar13[3] = 0xffff;
                  *(undefined2 *)(puVar13 + 4) = 0;
                  *(undefined1 *)((longlong)puVar13 + 0x22) = *(undefined1 *)(param_1 + 0x9a2);
                  *(undefined2 *)((longlong)puVar13 + 0x23) = 0;
                  *(undefined1 *)((longlong)puVar13 + 0x27) = 0;
                  *(undefined2 *)(puVar13 + 5) = 0;
                }
                uVar14 = (int)uVar15 + 1;
                uVar15 = (ulonglong)uVar14;
                puVar13 = (undefined8 *)((longlong)puVar13 + 0x2c);
              } while (uVar14 < (uint)*(ushort *)(piVar9 + 5) + piVar9[2]);
              param_2 = local_res10;
            }
            piVar9[0] = 0;
            piVar9[1] = 0;
            piVar9[4] = 0xffff;
            piVar9[5] = 0;
            piVar9[2] = -1;
            piVar9[3] = 0;
            piVar9[6] = 0;
            uVar3 = local_res8;
            goto LAB_14000a8c6;
          }
          if (uVar6 < *(ushort *)(piVar9 + 5)) {
            LogSystemEvent(param_1,uVar7,0x4004af00,
                           (byte *)"Existing encl came with less num of slots than it had before",
                           param_3,param_4);
            if ((*(char *)(param_1 + 0x608) != '\0') &&
               ((*(uint *)(param_1 + 0x60c) & 0x100009) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x100009
                          ,(undefined1 *)&local_res8,6,param_3,param_4);
            }
            if (((*(byte *)(param_1 + 0x18c0) & 1) == 0) && (*(ushort *)(piVar9 + 4) != 0xffff)) {
              bVar4 = true;
              *(short *)(*(longlong *)(param_1 + 0x1910) + 0x10 +
                        (ulonglong)*(ushort *)(piVar9 + 4) * 0x14) = *(short *)(param_2 + 0x28) << 4
              ;
              *(undefined1 *)((ulonglong)*(ushort *)(piVar9 + 4) + *(longlong *)(param_1 + 0x18d8))
                   = 1;
            }
          }
          uVar14 = piVar9[3];
          uVar8 = uVar14 | *(uint *)(param_2 + 0x2c);
          piVar9[3] = uVar8;
          if ((((((char)piVar9[6] != '\0') || (uVar14 != uVar8)) &&
               (*(undefined1 *)(piVar9 + 6) = 0, (*(byte *)(param_1 + 0x18c0) & 1) == 0)) &&
              ((*(ushort *)(piVar9 + 4) != 0xffff &&
               (lVar11 = *(longlong *)(param_1 + 0x1910) + (ulonglong)*(ushort *)(piVar9 + 4) * 0x14
               , *(char *)((longlong)piVar9 + 0x1b) == '\0')))) &&
             (((*(byte *)(lVar11 + 0x10) & 0xf) != 0 || (uVar14 != uVar8)))) {
            if (!bVar4) {
              *(short *)(lVar11 + 0x10) = (short)piVar9[5] << 4;
              uVar8 = piVar9[3];
            }
            *(uint *)(lVar11 + 0x14) = uVar8;
            *(undefined1 *)((ulonglong)*(ushort *)(piVar9 + 4) + *(longlong *)(param_1 + 0x18d8)) =
                 1;
            *(undefined1 *)((longlong)piVar9 + 0x1b) = 1;
            return;
          }
          goto LAB_14000ac52;
        }
      }
LAB_14000a8c6:
      local_res8 = uVar3;
      bVar2 = *(byte *)(param_1 + 0x18cc);
      if ((ushort)bVar2 < *(ushort *)(param_1 + 0x99e)) {
        *(byte *)(param_1 + 0x18cc) = bVar2 + 1;
        piVar9 = (int *)((ulonglong)bVar2 * 0x1c + *(longlong *)(param_1 + 0x5a0));
        *(undefined2 *)((longlong)piVar9 + 0x12) = *(undefined2 *)(param_2 + 0x1c);
        *(undefined8 *)piVar9 = *(undefined8 *)(param_2 + 0x20);
        piVar9[2] = -1;
        *(undefined2 *)((longlong)piVar9 + 0x16) = *(undefined2 *)(param_2 + 0x2a);
        piVar9[3] = *(int *)(param_2 + 0x2c);
        *(undefined2 *)(piVar9 + 4) = 0xffff;
        *(undefined2 *)(piVar9 + 5) = *(undefined2 *)(param_2 + 0x28);
LAB_14000ac52:
        *(undefined1 *)((longlong)piVar9 + 0x1b) = 1;
      }
      else {
        pcVar12 = "Enclosure Table Full (ProcessSasEnclosureStatusChange)";
        uVar7 = 0xad010046;
        uVar10 = 0xc004af02;
LAB_14000a8f6:
        LogSystemEvent(param_1,uVar7,uVar10,(byte *)pcVar12,param_3,param_4);
      }
    }
    else if (*(char *)(param_2 + 0x1e) == '\x02') {
      uVar6 = 0;
      pcVar12 = (char *)(*(longlong *)(param_1 + 0x5a0) + 0x18);
      do {
        if (*(byte *)(param_1 + 0x18cc) <= uVar6) {
LAB_14000ad43:
          LogSystemEvent(param_1,0xad01004d,0xc004af02,(byte *)"Removing Non-Existing Enclosure",
                         param_3,param_4);
          return;
        }
        if ((*(short *)(pcVar12 + -6) == *(short *)(param_2 + 0x1c)) && (*pcVar12 == '\0')) {
          if (uVar6 != 0xffff) {
            lVar11 = (ulonglong)uVar6 * 0x1c + *(longlong *)(param_1 + 0x5a0);
            cVar5 = *(char *)(lVar11 + 0x1b);
            if (cVar5 == '\0') {
              if (*(byte *)(lVar11 + 0x18) < 0xf) {
                *(byte *)(lVar11 + 0x18) = *(byte *)(lVar11 + 0x18) + 1;
              }
              else {
                *(undefined1 *)(lVar11 + 0x1b) = 1;
                cVar5 = '\x01';
              }
            }
            if (*(char *)(lVar11 + 0x18) == '\0') {
              *(undefined1 *)(lVar11 + 0x18) = 1;
            }
            if ((((*(byte *)(param_1 + 0x18c0) & 1) == 0) && (cVar5 == '\0')) &&
               (*(ushort *)(lVar11 + 0x10) != 0xffff)) {
              lVar1 = *(longlong *)(param_1 + 0x1910) + (ulonglong)*(ushort *)(lVar11 + 0x10) * 0x14
              ;
              uVar6 = *(short *)(lVar11 + 0x14) << 4;
              *(ushort *)(lVar1 + 0x10) = uVar6;
              *(ushort *)(lVar1 + 0x10) = *(byte *)(lVar11 + 0x18) | uVar6;
              *(undefined1 *)
               ((ulonglong)*(ushort *)(lVar11 + 0x10) + *(longlong *)(param_1 + 0x18d8)) = 1;
            }
            *(undefined1 *)(lVar11 + 0x1b) = 1;
            return;
          }
          goto LAB_14000ad43;
        }
        uVar6 = uVar6 + 1;
        pcVar12 = pcVar12 + 0x1c;
      } while( true );
    }
  }
  return;
LAB_14000a8b9:
  uVar6 = uVar6 + 1;
  piVar9 = piVar9 + 7;
  if (*(byte *)(param_1 + 0x18cc) <= uVar6) goto LAB_14000a8c6;
  goto LAB_14000a8a0;
}



===== ProcessSasTopologyChangeList @ 14000ad80 =====

void ProcessSasTopologyChangeList(longlong param_1,ushort *param_2,byte param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  ushort *puVar4;
  ushort *puVar5;
  byte bVar6;
  ushort uVar7;
  byte *pbVar8;
  ushort *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  int iVar12;
  
  *(undefined4 *)(param_1 + 0x11e8) = 0x1e;
  bVar6 = (byte)param_2[0x12];
  uVar2 = (uint)(ushort)((bVar6 + 3) * 4);
  if (((uVar2 + 0x1c == (uint)(byte)param_2[1] << 2) && (uVar2 == (uint)*param_2 << 2)) &&
     (bVar6 != 0)) {
    puVar5 = param_2 + 0x14;
    uVar7 = 0;
    if (bVar6 != 0) {
      pbVar8 = (byte *)((longlong)param_2 + 0x2b);
      do {
        if ((((*pbVar8 & 0xf) - 1 & 0xfa) == 0) && ((*pbVar8 & 0xf) != 6)) {
          iVar1 = *(int *)(param_1 + 0x18e0);
          puVar9 = (ushort *)
                   ((ulonglong)((uint)*(ushort *)(param_1 + 0x5d4) * iVar1) +
                   *(longlong *)(param_1 + 0x5a8));
          if ((char)puVar9[2] != '\0') {
            LogSystemEvent(param_1,0xad010043,0xc004af02,
                           (byte *)"Event List Full (SasTopologyChangeList)",param_3,param_4);
            return;
          }
          puVar4 = puVar9 + 0x12;
          *puVar9 = param_2[0xe];
          puVar9[1] = param_2[0xf];
          *(char *)(puVar9 + 2) = (char)param_2[0x12];
          *(char *)((longlong)puVar9 + 5) = (char)param_2[0x10];
          *(undefined1 *)(puVar9 + 3) = *(undefined1 *)((longlong)param_2 + 0x25);
          *(undefined1 *)((longlong)puVar9 + 7) = 0;
          *(char *)(puVar9 + 4) = (char)param_2[0x13];
          uVar11 = (ulonglong)bVar6;
          do {
            uVar10 = uVar11;
            bVar6 = *(byte *)((longlong)puVar5 + 3) & 0xf;
            if (((bVar6 - 1 & 0xfa) == 0) && (bVar6 != 6)) {
              puVar4[-2] = *puVar5;
              bVar6 = *(byte *)((longlong)puVar5 + 3);
              *(byte *)puVar4 = (byte)*puVar4 & 0xfe;
              *(byte *)((longlong)puVar4 + 1) = bVar6 & 0xf;
              puVar4 = puVar4 + 0xe;
            }
            else {
              *(char *)(puVar9 + 2) = (char)puVar9[2] + -1;
            }
            puVar5 = puVar5 + 2;
            uVar11 = uVar10 - 1;
          } while (uVar11 != 0);
          iVar12 = 0;
          if (((uint)*(ushort *)(param_1 + 0x5d4) * 2 - *(int *)(param_1 + 0x5a8)) + (int)puVar9 <=
              *(uint *)(param_1 + 0x5cc)) {
            iVar12 = iVar1 + 1;
          }
          *(int *)(param_1 + 0x18e0) = iVar12;
          if (*(char *)(param_1 + 0x11dc) != '\0') {
            return;
          }
          if (*(char *)(param_1 + 0x11dd) != '\0') {
            return;
          }
          if ((*(int *)(param_1 + 0x970) == 0) && (*(int *)(param_1 + 0x1218) == 0)) {
            PauseAdapterQueue(param_1,(char)uVar10 + '\x03',param_3,param_4);
            ResetActive(param_1,7,param_3,param_4);
          }
          *(undefined1 *)(param_1 + 0x11dc) = 1;
          UpdateMissingCount(param_1,param_3,param_4);
          uVar3 = ReadIDs(param_1,param_3,param_4);
          if ((char)uVar3 == '\0') {
            *(undefined1 *)(param_1 + 0x11de) = 0;
            RemoveDevice(param_1,param_3,param_4);
            return;
          }
          return;
        }
        uVar7 = uVar7 + 1;
        pbVar8 = pbVar8 + 4;
      } while (uVar7 < bVar6);
    }
  }
  else {
    LogSystemEvent(param_1,0xad01003d,0xc004af02,
                   (byte *)"Wrong Event Data Length (SasTopologyChangeList)",param_3,param_4);
  }
  return;
}



===== ReadIDs @ 14000b000 =====

ulonglong ReadIDs(longlong param_1,byte param_2,int param_3)

{
  ulonglong in_RAX;
  undefined8 uVar1;
  longlong lVar2;
  byte bVar3;
  longlong lVar4;
  
  lVar4 = (ulonglong)((uint)*(ushort *)(param_1 + 0x5d4) * *(int *)(param_1 + 0x18e4)) +
          *(longlong *)(param_1 + 0x5a8);
  bVar3 = *(byte *)(lVar4 + 7);
  while( true ) {
    if (*(byte *)(lVar4 + 4) <= bVar3) {
      return in_RAX & 0xffffffffffffff00;
    }
    in_RAX = (ulonglong)bVar3;
    lVar2 = in_RAX * 0x1c + lVar4;
    if (((*(short *)(lVar2 + 0x20) != 0) && (*(char *)(lVar2 + 0x25) == '\x01')) &&
       ((*(byte *)(lVar2 + 0x24) & 1) == 0)) break;
    bVar3 = bVar3 + 1;
  }
  *(byte *)(lVar4 + 7) = bVar3;
  *(undefined1 *)(param_1 + 0x11de) = 1;
  *(undefined1 *)(param_1 + 0x9ba) = 1;
  uVar1 = SendExtendedConfigPageMessage
                    (param_1,'\x01',(char *)(param_1 + 0x1920),
                     *(ushort *)(lVar2 + 0x20) | 0x20000000,(int)*(undefined8 *)(param_1 + 0x1928),
                     param_2,param_3);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== ReadPcieIDs @ 14000b0d0 =====

ulonglong ReadPcieIDs(longlong param_1,byte param_2,int param_3)

{
  ulonglong in_RAX;
  undefined8 uVar1;
  longlong lVar2;
  byte bVar3;
  longlong lVar4;
  
  lVar4 = (ulonglong)((uint)*(ushort *)(param_1 + 0x5d6) * *(int *)(param_1 + 0x18ec)) +
          *(longlong *)(param_1 + 0x5b0);
  bVar3 = *(byte *)(lVar4 + 7);
  while( true ) {
    if (*(byte *)(lVar4 + 4) <= bVar3) {
      return in_RAX & 0xffffffffffffff00;
    }
    in_RAX = (ulonglong)bVar3;
    lVar2 = in_RAX * 0x1c + lVar4;
    if (((*(short *)(lVar2 + 0x1c) != 0) && (*(char *)(lVar2 + 0x21) == '\x01')) &&
       ((*(byte *)(lVar2 + 0x20) & 1) == 0)) break;
    bVar3 = bVar3 + 1;
  }
  *(byte *)(lVar4 + 7) = bVar3;
  *(undefined1 *)(param_1 + 0x11df) = 1;
  *(undefined1 *)(param_1 + 0x9ba) = 1;
  uVar1 = SendExtendedConfigPageMessage
                    (param_1,'\x01',(char *)(param_1 + 0x1940),
                     *(ushort *)(lVar2 + 0x1c) | 0x20000000,(int)*(undefined8 *)(param_1 + 0x1948),
                     param_2,param_3);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== RemoveDevice @ 14000b1a0 =====

void RemoveDevice(longlong param_1,byte param_2,int param_3)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  undefined8 *puVar7;
  uint uVar8;
  longlong lVar9;
  ushort uVar10;
  ulonglong uVar11;
  ushort *puVar12;
  int *piVar13;
  ushort *puVar14;
  ushort uVar15;
  int local_res8 [2];
  
  uVar5 = 0;
  uVar8 = *(uint *)(param_1 + 0x9bc);
  uVar11 = (ulonglong)uVar8;
  local_res8[0] = 0;
  uVar6 = 0;
  puVar14 = *(ushort **)(param_1 + 0x5b8);
  puVar12 = puVar14;
  if (uVar8 != 0) {
    do {
      if (puVar12[1] != 0) {
        puVar14 = *(ushort **)(param_1 + 0x570);
        if ((char)puVar12[2] != '\0') {
          ZeroMemory(puVar14,0x2c);
          *(undefined1 *)((longlong)puVar14 + 3) = 0x1b;
          *(undefined1 *)puVar14 = 0xd;
          puVar14[2] = puVar12[1];
          QueueRequestDescriptor
                    (param_1,(uint)*(ushort *)(param_1 + 0x9b4) * 0x10000 + 8,0,param_2,param_3);
          if (((*(char *)((longlong)puVar12 + 5) != '\0') &&
              (*(char *)((longlong)puVar12 + 7) == '\0')) &&
             (puVar12[4] == *(ushort *)(param_1 + 0xbbd8))) {
            SetNvmeMaxShutdownTime(param_1);
          }
          puVar12[1] = 0;
          puVar12[2] = 0;
          *(undefined1 *)((longlong)puVar12 + 7) = 0;
          puVar12[4] = 0;
          *(undefined1 *)(param_1 + 0x5c8) = 1;
          return;
        }
        *(undefined1 *)(param_1 + 0x11d9) = 1;
        ZeroMemory(puVar14,0x34);
        uVar15 = puVar12[1];
        *puVar14 = uVar15;
        *(undefined1 *)((longlong)puVar14 + 3) = 1;
        *(undefined1 *)((longlong)puVar14 + 5) = 3;
        if (((*(char *)((longlong)puVar12 + 5) == '\0') || (*(char *)(param_1 + 0x18b0) != '\0')) ||
           (*(char *)((longlong)puVar12 + 7) != '\0')) {
          uVar8 = 0xf;
        }
        else {
          *(undefined1 *)((longlong)puVar14 + 7) = 0x18;
          uVar8 = (uint)(byte)puVar12[3];
        }
        uVar10 = *(ushort *)(param_1 + 0x9b4);
        lVar9 = *(longlong *)(param_1 + 0x5c0);
        if (*(uint *)(param_1 + 0x9bc) != 0) goto LAB_14000b421;
        goto LAB_14000b478;
      }
      uVar6 = uVar6 + 1;
      puVar12 = puVar12 + 5;
    } while (uVar6 < uVar8);
  }
  bVar4 = (byte)*(ushort *)(param_1 + 0x18c0);
  if (((*(ushort *)(param_1 + 0x18c0) & 1) == 0) && (uVar8 != 0)) {
    do {
      uVar5 = *puVar14;
      if (uVar5 != 0xffff) {
        lVar9 = *(longlong *)(param_1 + 0x1910);
        *(undefined8 *)(lVar9 + 8 + (ulonglong)uVar5 * 0x14) = 0;
        *(undefined8 *)(lVar9 + 0x10 + (ulonglong)uVar5 * 0x14) = 0;
        *(undefined1 *)((ulonglong)*puVar14 + *(longlong *)(param_1 + 0x18d8)) = 1;
        *(undefined1 *)((ulonglong)*puVar14 + *(longlong *)(param_1 + 0x18d0)) = 0;
        *puVar14 = 0xffff;
      }
      puVar14 = puVar14 + 5;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
    bVar4 = (byte)*(undefined2 *)(param_1 + 0x18c0);
  }
  if ((bVar4 & 0xe) == 2) {
    uVar5 = (ushort)*(byte *)(param_1 + 0x18cc);
    do {
      piVar13 = *(int **)(param_1 + 0x5a0);
      bVar1 = true;
      uVar15 = 0;
      if (uVar5 == 0) break;
      do {
        if (((*piVar13 == 0) && (piVar13[1] == 0)) && (*(char *)((longlong)piVar13 + 0x1b) != '\0'))
        {
          bVar1 = false;
          uVar8 = (uint)uVar15;
          if (uVar8 == uVar5 - 1) {
            piVar13[0] = 0;
            piVar13[1] = 0;
            piVar13[2] = -1;
            piVar13[3] = 0;
            piVar13[4] = 0xffff;
            piVar13[5] = 0;
            piVar13[6] = 0;
          }
          else {
            puVar7 = (undefined8 *)((ulonglong)uVar15 * 0x1c + *(longlong *)(param_1 + 0x5a0));
            puVar3 = (undefined8 *)((ulonglong)(uVar15 + 1) * 0x1c + *(longlong *)(param_1 + 0x5a0))
            ;
            uVar10 = uVar15;
            while ((int)uVar8 < (int)(uVar5 - 1)) {
              uVar2 = puVar3[1];
              uVar10 = uVar10 + 1;
              *puVar7 = *puVar3;
              puVar7[1] = uVar2;
              puVar7[2] = puVar3[2];
              *(undefined4 *)(puVar7 + 3) = *(undefined4 *)(puVar3 + 3);
              puVar7 = (undefined8 *)((longlong)puVar7 + 0x1c);
              puVar3 = (undefined8 *)((longlong)puVar3 + 0x1c);
              uVar8 = (uint)uVar10;
            }
            *puVar7 = 0;
            *(undefined4 *)(puVar7 + 1) = 0xffffffff;
            *(undefined4 *)((longlong)puVar7 + 0xc) = 0;
            puVar7[2] = 0xffff;
            *(undefined4 *)(puVar7 + 3) = 0;
          }
          *(char *)(param_1 + 0x18cc) = *(char *)(param_1 + 0x18cc) + -1;
          uVar5 = (ushort)*(byte *)(param_1 + 0x18cc);
        }
        uVar15 = uVar15 + 1;
        piVar13 = piVar13 + 7;
      } while (uVar15 < uVar5);
    } while (!bVar1);
  }
  if (*(char *)(param_1 + 0x11dc) == '\0') {
    AddPcieDevice(param_1,param_2,param_3);
  }
  else {
    AddDevice(param_1,param_2,param_3);
  }
  return;
  while( true ) {
    uVar5 = uVar5 + 1;
    lVar9 = lVar9 + 0x2c;
    if (*(uint *)(param_1 + 0x9bc) <= (uint)uVar5) break;
LAB_14000b421:
    if (*(ushort *)(lVar9 + 0x1a) == uVar15) {
      local_res8[0] = CONCAT22(*(undefined2 *)(lVar9 + 0x1c),*(undefined2 *)(lVar9 + 0x1e));
      LogOperationalEvent(param_1,local_res8,4,0x4004af00,
                          "Target reset issued to the device being removed(Bus & Target ID logged)",
                          param_2,param_3);
      break;
    }
  }
LAB_14000b478:
  QueueRequestDescriptor(param_1,(uint)uVar10 * 0x10000 + 6,0,param_2,param_3);
  *(uint *)(param_1 + 0x974) = uVar8;
  *(undefined1 *)(puVar12 + 2) = 1;
  return;
}



===== SODCheckMapEntry @ 14000b520 =====

void SODCheckMapEntry(longlong param_1,longlong param_2,uint param_3,uint param_4,byte param_5,
                     int param_6)

{
  ushort uVar1;
  longlong lVar2;
  short sVar3;
  int *piVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (param_3 < param_4) {
    piVar4 = (int *)(param_2 + 4);
    uVar6 = (ulonglong)(param_4 - param_3);
    do {
      if ((piVar4[4] & 0x20000000U) != 0) {
        if ((piVar4[-1] != 0) || (*piVar4 != 0)) {
          if (*(char *)((longlong)piVar4 + 0x1d) != '\0') goto LAB_14000b6ed;
          if (((*(byte *)(piVar4 + 7) < 0xf) &&
              (*(byte *)(piVar4 + 7) = *(byte *)(piVar4 + 7) + 1,
              (*(byte *)(param_1 + 0x18c0) & 1) == 0)) &&
             (uVar1 = *(ushort *)(piVar4 + 5), uVar1 != 0xffff)) {
            lVar2 = *(longlong *)(param_1 + 0x1910);
            *(int *)(lVar2 + 8 + (ulonglong)uVar1 * 0x14) = piVar4[-1];
            lVar2 = lVar2 + (ulonglong)uVar1 * 0x14;
            *(int *)(lVar2 + 0xc) = *piVar4;
            sVar3 = (short)piVar4[6] * 0x80;
            *(short *)(lVar2 + 0x12) = sVar3;
            *(short *)(lVar2 + 0x12) = *(short *)((longlong)piVar4 + 0x1a) + sVar3;
            *(ushort *)(lVar2 + 0x10) = (ushort)*(byte *)(piVar4 + 7);
            *(undefined8 *)(lVar2 + 0x14) = 0;
            ZeroMemory(*(void **)(param_1 + 0x1918),8);
            memmove((void *)(*(longlong *)(param_1 + 0x1918) + 8),(void *)(lVar2 + 8),0x14);
            uVar1 = *(ushort *)(piVar4 + 5);
            *(undefined1 *)(param_1 + 0x9ba) = 1;
            *(undefined1 *)(param_1 + 0x11e1) = 1;
            SendExtendedConfigPageMessage
                      (param_1,'\x04',(char *)(param_1 + 0x1908),uVar1 | 0x10000,
                       (int)*(undefined8 *)(param_1 + 0x1918),param_5,param_6);
            uVar5 = 0;
            do {
              PollLSImpiIsr(param_1,param_5,param_6);
              if (*(char *)(param_1 + 0x11e1) == '\0') goto LAB_14000b6e9;
              StorPortStallExecution(500);
              uVar5 = uVar5 + 1;
            } while (uVar5 < 120000);
            if (*(char *)(param_1 + 0x11e1) != '\0') {
              LogSystemEvent(param_1,0xad01004b,0xc004af02,
                             (byte *)"Start-of-Day Check Failed (SODCheckMapEntry)",param_5,param_6)
              ;
            }
          }
        }
LAB_14000b6e9:
        *(undefined1 *)((longlong)piVar4 + 0x1d) = 1;
      }
LAB_14000b6ed:
      piVar4 = piVar4 + 0xb;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return;
}



===== SendSTPIdentifyCommand @ 14000b730 =====

void SendSTPIdentifyCommand
               (longlong param_1,uint param_2,undefined2 param_3,byte param_4,int param_5)

{
  char cVar1;
  ushort uVar2;
  undefined2 *puVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  int iVar6;
  
  puVar3 = *(undefined2 **)(param_1 + 0x570);
  cVar1 = *(char *)(param_1 + 0x120a);
  uVar2 = *(ushort *)(param_1 + 0x9b4);
  ZeroMemory(puVar3,0x40);
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
  iVar6 = *(int *)(param_1 + 0x1200) - *(int *)(param_1 + 0x108);
  if (cVar1 == '\0') {
    *(undefined4 *)(puVar3 + 0x18) = 0xd3000200;
    *(int *)(puVar3 + 0x1a) = iVar6;
    *(undefined4 *)(puVar3 + 0x1c) = *(undefined4 *)(param_1 + 500);
  }
  else {
    *(undefined4 *)(puVar3 + 0x1c) = 0x200;
    *(undefined1 *)((longlong)puVar3 + 0x3f) = 0x40;
    *(int *)(puVar3 + 0x18) = iVar6;
    *(undefined4 *)(puVar3 + 0x1a) = *(undefined4 *)(param_1 + 500);
  }
  QueueRequestDescriptor(param_1,(uint)uVar2 * 0x10000 + 8,0,param_4,param_5);
  uVar5 = GtfStartTimer(param_1,1,5,AtaIdentifyTimeout,0,param_4,param_5);
  *(char *)(param_1 + 0x1208) = (char)uVar5;
  if ((((char)uVar5 == -2) && (*(char *)(param_1 + 0x608) != '\0')) &&
     ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                (undefined1 *)0x0,0,param_4,param_5);
  }
  return;
}



===== StartIDReadsForPhyEvents @ 14000b8c0 =====

void StartIDReadsForPhyEvents(longlong param_1,byte param_2,int param_3)

{
  undefined8 uVar1;
  
  uVar1 = ReadIDs(param_1,param_2,param_3);
  if ((char)uVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x11de) = 0;
    RemoveDevice(param_1,param_2,param_3);
  }
  return;
}



===== StartIDReadsForPortEvents @ 14000b910 =====

void StartIDReadsForPortEvents(longlong param_1,byte param_2,int param_3)

{
  undefined8 uVar1;
  
  uVar1 = ReadPcieIDs(param_1,param_2,param_3);
  if ((char)uVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x11df) = 0;
    RemoveDevice(param_1,param_2,param_3);
  }
  return;
}



===== UpdateMissingCount @ 14000b960 =====

ulonglong UpdateMissingCount(longlong param_1,byte param_2,int param_3)

{
  short *psVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong in_RAX;
  ulonglong uVar4;
  uint uVar5;
  undefined1 *puVar6;
  longlong lVar7;
  short *psVar8;
  longlong lVar9;
  byte bVar10;
  
  lVar7 = (ulonglong)((uint)*(ushort *)(param_1 + 0x5d4) * *(int *)(param_1 + 0x18e4)) +
          *(longlong *)(param_1 + 0x5a8);
  bVar10 = *(byte *)(lVar7 + 7);
  if (*(byte *)(lVar7 + 4) <= bVar10) {
    *(undefined1 *)(lVar7 + 7) = 0;
    return in_RAX & 0xffffffffffffff00;
  }
  do {
    uVar4 = (ulonglong)bVar10;
    lVar9 = uVar4 * 0x1c + lVar7;
    psVar1 = (short *)(lVar9 + 0x20);
    if (*(short *)(lVar9 + 0x20) != 0) {
      if (*(char *)(lVar9 + 0x25) == '\x05') {
        lVar3 = *(longlong *)(param_1 + 0x5c0);
        uVar5 = 0;
        psVar8 = (short *)(lVar3 + 0x1a);
        while (uVar5 < *(uint *)(param_1 + 0x9bc)) {
          if (*psVar8 == *(short *)(lVar9 + 0x20)) {
            if (uVar5 != 0xffffffff) {
              uVar2 = *(uint *)((ulonglong)uVar5 * 0x2c + 0x14 + lVar3);
              uVar4 = (ulonglong)uVar2;
              if ((int)uVar2 < 0) {
                uVar4 = (ulonglong)(uVar2 & 0x7fffffff);
                *(uint *)((ulonglong)uVar5 * 0x2c + 0x14 + lVar3) = uVar2 & 0x7fffffff;
              }
              goto LAB_14000ba2a;
            }
            break;
          }
          uVar5 = uVar5 + 1;
          uVar4 = (ulonglong)uVar5;
          psVar8 = psVar8 + 0x16;
        }
      }
      else {
LAB_14000ba2a:
        if ((*(char *)(lVar9 + 0x25) == '\x02') && ((*(byte *)(lVar9 + 0x24) & 2) == 0)) {
          psVar8 = (short *)(*(longlong *)(param_1 + 0x5c0) + 0x1a);
          for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x9bc); uVar5 = uVar5 + 1) {
            if (*psVar8 == *psVar1) {
              if (uVar5 != 0xffffffff) {
                *(undefined8 *)(lVar9 + 0xc) = 0;
                *(byte *)(lVar9 + 0x24) = *(byte *)(lVar9 + 0x24) & 0xf8;
                *(undefined8 *)(lVar9 + 0x14) = 0;
                *(undefined4 *)(lVar9 + 0x1c) = 0;
                *psVar1 = 0;
                *(undefined2 *)(lVar9 + 0x22) = 0;
                *(undefined2 *)(lVar9 + 0x25) = 0;
                puVar6 = (undefined1 *)((ulonglong)uVar5 * 0x2c + *(longlong *)(param_1 + 0x5c0));
                if (puVar6[0x21] == '\0') {
                  if ((byte)puVar6[0x20] < 0xf) {
                    puVar6[0x20] = puVar6[0x20] + 1;
                  }
                  else {
                    puVar6[0x21] = 1;
                  }
                }
                if (puVar6[0x20] == '\0') {
                  puVar6[0x20] = 1;
                  *(undefined1 *)(param_1 + 0x5c8) = 1;
                }
                if ((*(char *)(param_1 + 0x608) != '\0') &&
                   ((*(uint *)(param_1 + 0x60c) & 0x100006) != 0)) {
                  RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                              0x100006,puVar6,0x2c,param_2,param_3);
                }
                AddToRemovalTable(param_1,*(short *)(puVar6 + 0x1a),0,param_2,param_3);
                uVar4 = AfdMasterTrigger(param_1,8,param_2,param_3);
                if ((((*(byte *)(param_1 + 0x18c0) & 0xf) == 0) && (puVar6[0x21] == '\0')) &&
                   (uVar4 = (ulonglong)*(ushort *)(puVar6 + 0x18),
                   *(ushort *)(puVar6 + 0x18) != 0xffff)) {
                  *(ushort *)(*(longlong *)(param_1 + 0x1910) + 0x10 + uVar4 * 0x14) =
                       (ushort)(byte)puVar6[0x20];
                  uVar4 = *(ulonglong *)(param_1 + 0x18d8);
                  *(undefined1 *)(*(ushort *)(puVar6 + 0x18) + uVar4) = 1;
                }
                *(byte *)(lVar7 + 7) = bVar10;
                puVar6[0x21] = 1;
                goto LAB_14000bc23;
              }
              break;
            }
            psVar8 = psVar8 + 0x16;
          }
          LogSystemEvent(param_1,0xad01004a,0xc004af02,
                         (byte *)"Removing unmapped device(UpdateMissingCount)",param_2,param_3);
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x247) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x247,
                        (undefined1 *)psVar1,2,param_2,param_3);
          }
          uVar4 = AddToRemovalTable(param_1,*psVar1,0,param_2,param_3);
        }
      }
    }
LAB_14000bc23:
    bVar10 = bVar10 + 1;
    if (*(byte *)(lVar7 + 4) <= bVar10) {
      *(undefined1 *)(lVar7 + 7) = 0;
      return uVar4 & 0xffffffffffffff00;
    }
  } while( true );
}



===== UpdatePcieMissingCount @ 14000bc70 =====

void UpdatePcieMissingCount(longlong param_1,byte param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  byte bVar3;
  longlong lVar4;
  short *psVar5;
  
  lVar2 = (ulonglong)((uint)*(ushort *)(param_1 + 0x5d6) * *(int *)(param_1 + 0x18ec)) +
          *(longlong *)(param_1 + 0x5b0);
  bVar3 = *(byte *)(lVar2 + 7);
  if (*(byte *)(lVar2 + 4) <= bVar3) {
    *(undefined1 *)(lVar2 + 7) = 0;
    return;
  }
  do {
    lVar4 = (ulonglong)bVar3 * 0x1c + lVar2;
    if (((*(short *)(lVar4 + 0x1c) != 0) && (*(char *)(lVar4 + 0x21) == '\x02')) &&
       ((*(byte *)(lVar4 + 0x20) & 2) == 0)) {
      psVar5 = (short *)(*(longlong *)(param_1 + 0x5c0) + 0x1a);
      for (uVar1 = 0; uVar1 < *(uint *)(param_1 + 0x9bc); uVar1 = uVar1 + 1) {
        if (*psVar5 == *(short *)(lVar4 + 0x1c)) {
          if (uVar1 != 0xffffffff) {
            *(undefined8 *)(lVar4 + 0xc) = 0;
            *(byte *)(lVar4 + 0x20) = *(byte *)(lVar4 + 0x20) & 0xfc;
            *(undefined8 *)(lVar4 + 0x14) = 0;
            *(undefined4 *)(lVar4 + 0x1c) = 0;
            *(undefined2 *)(lVar4 + 0x21) = 0;
            *(undefined1 *)(lVar4 + 0x23) = 0;
            *(undefined2 *)(lVar4 + 0x24) = 0;
            lVar4 = (ulonglong)uVar1 * 0x2c + *(longlong *)(param_1 + 0x5c0);
            if (*(char *)(lVar4 + 0x21) == '\0') {
              if (*(byte *)(lVar4 + 0x20) < 0xf) {
                *(byte *)(lVar4 + 0x20) = *(byte *)(lVar4 + 0x20) + 1;
              }
              else {
                *(undefined1 *)(lVar4 + 0x21) = 1;
              }
            }
            if (*(char *)(lVar4 + 0x20) == '\0') {
              *(undefined1 *)(lVar4 + 0x20) = 1;
              *(undefined1 *)(param_1 + 0x5c8) = 1;
            }
            AddToRemovalTable(param_1,*(short *)(lVar4 + 0x1a),0,param_2,param_3);
            if ((((*(byte *)(param_1 + 0x18c0) & 0xf) == 0) && (*(char *)(lVar4 + 0x21) == '\0')) &&
               (*(ushort *)(lVar4 + 0x18) != 0xffff)) {
              *(ushort *)
               (*(longlong *)(param_1 + 0x1910) + 0x10 + (ulonglong)*(ushort *)(lVar4 + 0x18) * 0x14
               ) = (ushort)*(byte *)(lVar4 + 0x20);
              *(undefined1 *)
               ((ulonglong)*(ushort *)(lVar4 + 0x18) + *(longlong *)(param_1 + 0x18d8)) = 1;
            }
            *(byte *)(lVar2 + 7) = bVar3;
            *(undefined1 *)(lVar4 + 0x21) = 1;
            goto LAB_14000be1e;
          }
          break;
        }
        psVar5 = psVar5 + 0x16;
      }
      LogSystemEvent(param_1,0xad01004a,0xc004af02,
                     (byte *)"Removing unmapped device(UpdatePcieMissingCount)",param_2,param_3);
    }
LAB_14000be1e:
    bVar3 = bVar3 + 1;
    if (*(byte *)(lVar2 + 4) <= bVar3) {
      *(undefined1 *)(lVar2 + 7) = 0;
      return;
    }
  } while( true );
}



===== BaeStuckIoTimerCallback @ 14000be60 =====

undefined1
BaeStuckIoTimerCallback
          (longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,int param_5)

{
  SasBcAsyncEvent(param_1,param_4,param_5);
  return 0;
}



===== BringIOCToOperationalState @ 14000be80 =====

ulonglong BringIOCToOperationalState(longlong param_1,byte param_2,int param_3)

{
  ushort uVar1;
  undefined8 *puVar2;
  int iVar3;
  ulonglong uVar4;
  int *piVar5;
  uint uVar6;
  ushort uVar7;
  
  uVar4 = SendIOCInitMessage(param_1,param_2,param_3);
  if ((char)uVar4 != '\0') {
    uVar7 = *(ushort *)(param_1 + 0x53c);
    uVar1 = *(ushort *)(param_1 + 0x532);
    iVar3 = *(int *)(param_1 + 0x218);
    piVar5 = *(int **)(param_1 + 0x548);
    if (uVar7 != 0) {
      uVar4 = (ulonglong)(uint)uVar7;
      do {
        *piVar5 = iVar3;
        piVar5 = piVar5 + 1;
        iVar3 = iVar3 + (uint)uVar1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    **(uint **)(param_1 + 0x58) = (uint)uVar7;
    LOCK();
    UNLOCK();
    *(ushort *)(param_1 + 0x224) = uVar7;
    ReadAndSetSASPages(param_1,param_2,param_3);
    if (*(char *)(param_1 + 0xb7ed) != '\0') {
      GetDriverTriggerValues(param_1,param_2,param_3);
    }
    ProcessDPMPage0(param_1,param_2,param_3);
    uVar4 = EnableDisableEvents(param_1,'\x01',param_2,param_3);
    if ((char)uVar4 != '\0') {
      uVar7 = 0;
      if (*(short *)(param_1 + 0x99a) != 0) {
        do {
          puVar2 = *(undefined8 **)(param_1 + 0x568);
          *(undefined1 *)(param_1 + 0x11d8) = 1;
          *puVar2 = 0;
          *(undefined4 *)(puVar2 + 1) = 0;
          *(undefined1 *)((longlong)puVar2 + 3) = 6;
          uVar4 = QueueRequestDescriptor
                            (param_1,(uint)*(ushort *)(param_1 + 0x9b2) * 0x10000 + 8,0,param_2,
                             param_3);
          uVar6 = 0;
          if (*(int *)(param_1 + 0x958) == 0) goto LAB_14000c00b;
          do {
            uVar4 = PollLSImpiIsr(param_1,param_2,param_3);
            if (*(char *)(param_1 + 0x11d8) == '\0') break;
            uVar4 = StorPortStallExecution(500);
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(param_1 + 0x958));
          if ((*(uint *)(param_1 + 0x958) <= uVar6) || (*(short *)(param_1 + 0x966) != 0))
          goto LAB_14000c00b;
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(param_1 + 0x99a));
      }
      return CONCAT71((int7)(uVar4 >> 8),1);
    }
  }
LAB_14000c00b:
  return uVar4 & 0xffffffffffffff00;
}



===== BuildIoctlScatterGather @ 14000c030 =====

int BuildIoctlScatterGather
              (longlong param_1,longlong param_2,uint *param_3,uint param_4,short *param_5,
              uint param_6,char param_7)

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
  int iVar15;
  uint uVar16;
  ulonglong uVar17;
  longlong lVar18;
  uint uVar19;
  uint uVar20;
  char cVar21;
  uint uVar22;
  uint uVar23;
  uint *puVar24;
  uint *puVar25;
  int local_78;
  int iVar26;
  uint local_70;
  uint local_6c;
  ulonglong local_68;
  short local_60;
  
  cVar3 = param_7;
  psVar2 = param_5;
  local_70 = 0;
  iVar26 = 0;
  local_78 = 0;
  bVar8 = *(byte *)(param_1 + 0x542) & 1;
  if (param_7 == '\0') {
    uVar5 = *(ushort *)(param_1 + 0x52a);
    uVar23 = 0x14;
    if (*param_5 != 1) {
      uVar23 = 0x10;
    }
    if (bVar8 == 0) {
      local_68 = 8;
      param_7 = '\x02';
      param_5._0_4_ = 0x30000000;
    }
    else {
      uVar23 = uVar23 | 2;
      param_7 = '\x03';
      local_68 = 0xc;
      param_5._0_4_ = 0x32000000;
    }
  }
  else {
    uVar5 = *(ushort *)(param_1 + 0x52e);
    local_68 = 0x10;
    uVar23 = 0;
    param_7 = '\x04';
    param_5._0_4_ = 0x80000000;
  }
  uVar1 = psVar2[1];
  puVar12 = param_3 + uVar1;
  iVar15 = (int)local_68;
  local_6c = (uint)((((uint)*(ushort *)(param_1 + 0x534) + (uint)uVar1 * -4) - iVar15) / local_68);
  puVar7 = (uint *)StorPortGetScatterGatherList(param_1,param_2);
  uVar20 = param_6 - *(int *)(param_2 + 0x40);
  uVar22 = puVar7[6];
  uVar19 = *puVar7;
  puVar7 = puVar7 + 4;
  puVar11 = puVar7;
  if (uVar22 <= uVar20) {
    do {
      puVar7 = puVar11 + 6;
      uVar20 = uVar20 - uVar22;
      uVar19 = uVar19 - 1;
      uVar22 = puVar11[8];
      puVar11 = puVar7;
    } while (uVar22 <= uVar20);
  }
  uVar22 = *(uint *)(psVar2 + 2);
  uVar16 = 0;
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
      puVar11 = puVar11 + 6;
      uVar16 = uVar16 + 1;
    } while (uVar16 < uVar19);
    local_78 = iVar14;
  }
  param_6 = uVar16 + 1;
  uVar22 = *(uint *)(param_1 + 0x994);
  if (uVar22 < param_6) {
    if (param_6 - uVar22 == 0) {
      iVar26 = 0;
    }
    else {
      iVar26 = puVar7[(ulonglong)uVar22 * 6 + 2] * (param_6 - uVar22);
    }
    iVar26 = iVar26 - local_78;
    param_6 = uVar22;
  }
  puVar11 = puVar7;
  puVar24 = (uint *)0x0;
  puVar25 = param_3;
  uVar22 = local_6c;
  if (param_6 <= local_6c + 1) {
    uVar22 = param_6;
  }
  do {
    puVar13 = puVar12;
    uVar19 = 0;
    if (uVar22 != 0) {
      uVar17 = (ulonglong)uVar22;
      do {
        if (cVar3 == '\0') {
          uVar16 = puVar11[2] | uVar23 << 0x18;
          *puVar12 = uVar16;
          uVar19 = *puVar11;
          puVar12[1] = uVar19;
          if (bVar8 != 0) {
            puVar12[2] = puVar11[1];
          }
          if ((puVar11 == puVar7) && (uVar20 != 0)) {
            *puVar12 = uVar16 - uVar20;
            puVar12[1] = uVar19 + uVar20;
          }
        }
        else {
          uVar19 = *puVar11;
          *puVar12 = uVar19;
          puVar12[1] = puVar11[1];
          uVar16 = puVar11[2];
          puVar12[2] = uVar16;
          puVar12[3] = uVar23 << 0x18;
          if ((puVar11 == puVar7) && (uVar20 != 0)) {
            puVar12[2] = uVar16 - uVar20;
            *puVar12 = uVar19 + uVar20;
          }
        }
        puVar12 = (uint *)((longlong)puVar12 + local_68);
        puVar11 = puVar11 + 6;
        uVar17 = uVar17 - 1;
        puVar13 = puVar12;
        uVar19 = uVar22;
      } while (uVar17 != 0);
    }
    local_70 = local_70 + uVar19;
    if (param_6 <= local_70) {
      puVar13 = (uint *)((longlong)puVar13 - local_68);
      if (cVar3 == '\0') {
        uVar23 = *puVar13;
        *puVar13 = uVar23 | 0xc1000000;
        if (local_78 != 0) {
          *puVar13 = (uVar23 | 0xc1000000) - local_78;
        }
        if (puVar24 != (uint *)0x0) {
          local_60 = (short)local_68;
          *(undefined1 *)((longlong)puVar24 + 2) = 0;
          *(ushort *)puVar24 = local_60 * (short)uVar19 & 0xff;
        }
      }
      else {
        puVar13[3] = 0x40000000;
        if (local_78 != 0) {
          puVar13[2] = puVar13[2] - local_78;
        }
        if (puVar24 != (uint *)0x0) {
          *(undefined1 *)((longlong)puVar24 + 0xe) = 0;
          puVar24[2] = uVar19 * iVar15;
        }
      }
      return iVar26;
    }
    if (cVar3 == '\0') {
      *(uint *)((longlong)puVar13 - local_68) = *(uint *)((longlong)puVar13 - local_68) | 0x80000000
      ;
    }
    if (local_70 == local_6c) {
      lVar18 = (longlong)puVar13 - (longlong)puVar25 >> 2;
      uVar9 = (char)((longlong)
                     (lVar18 + (ulonglong)
                               ((uint)((longlong)puVar13 - (longlong)puVar25 >> 0x3f) & 3)) >> 2);
      if (cVar3 == '\0') {
        uVar9 = (char)lVar18;
      }
      *(undefined1 *)((longlong)param_3 + 2) = uVar9;
      local_6c = (uint)uVar5;
    }
    if (puVar24 == (uint *)0x0) {
      puVar12 = (uint *)((longlong)puVar25 + (ulonglong)*(ushort *)(param_1 + 0x534));
      param_4 = param_4 + *(ushort *)(param_1 + 0x534);
      if (cVar3 != '\0') goto LAB_14000c443;
LAB_14000c3f9:
      *puVar13 = (uint)param_5;
      puVar13[1] = param_4;
      if (bVar8 != 0) {
        puVar13[2] = *(uint *)(param_1 + 500);
      }
    }
    else {
      cVar21 = (char)uVar19;
      if (cVar3 == '\0') {
        local_60._0_1_ = (char)local_68;
        *(char *)((longlong)puVar24 + 2) = param_7 * cVar21;
        *(ushort *)puVar24 = (ushort)(byte)((cVar21 + '\x01') * (char)local_60);
        puVar12 = (uint *)((ulonglong)(uint)*(ushort *)(param_1 + 0x534) + (longlong)puVar25);
        param_4 = param_4 + *(ushort *)(param_1 + 0x534);
        goto LAB_14000c3f9;
      }
      *(char *)((longlong)puVar24 + 0xe) = cVar21;
      puVar24[2] = (uVar19 + 1) * iVar15;
      puVar12 = (uint *)((ulonglong)(uint)*(ushort *)(param_1 + 0x534) + (longlong)puVar25);
      param_4 = *(ushort *)(param_1 + 0x534) + param_4;
LAB_14000c443:
      *puVar13 = param_4;
      puVar13[1] = *(uint *)(param_1 + 500);
      puVar13[3] = (uint)param_5;
    }
    uVar22 = param_6 - local_70;
    puVar24 = puVar13;
    puVar25 = puVar12;
    if (local_6c + 1 < uVar22) {
      uVar22 = local_6c;
    }
  } while( true );
}



===== BuildNVMePRP @ 14000c4e0 =====

ulonglong BuildNVMePRP(longlong param_1,longlong param_2,uint param_3,longlong param_4,int param_5,
                      longlong param_6,byte param_7,int param_8)

{
  uint *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint *puVar4;
  char cVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  bool bVar13;
  uint local_res10;
  uint local_res14;
  ulonglong local_38;
  
  lVar3 = *(longlong *)(param_2 + 0x68);
  puVar1 = (uint *)StorPortGetScatterGatherList();
  *(uint **)(lVar3 + 0x30) = puVar1;
  local_res10 = *(uint *)(param_2 + 0x3c);
  uVar10 = *puVar1;
  puVar12 = puVar1 + 4;
  if ((*(uint *)(param_6 + 0x10) == 0) || (local_res10 <= *(uint *)(param_6 + 0x10))) {
    bVar13 = false;
    if (local_res10 < 0x2001) {
      if (0x1000 < local_res10) {
        bVar13 = 0x1000 - (param_3 & 0xfff) < (local_res10 & 0xfff);
      }
    }
    else {
      bVar13 = true;
    }
    uVar11 = param_3 - *(int *)(param_2 + 0x40);
    uVar7 = puVar1[6];
    puVar1 = puVar12;
    if (uVar7 <= uVar11) {
      do {
        puVar12 = puVar1 + 6;
        uVar11 = uVar11 - uVar7;
        uVar10 = uVar10 - 1;
        uVar7 = puVar1[8];
        puVar1 = puVar12;
      } while (uVar7 <= uVar11);
    }
    cVar5 = '\x01';
    uVar7 = param_5 + (uint)*(ushort *)(param_1 + 0x534);
    puVar6 = (uint *)((ulonglong)*(ushort *)(param_1 + 0x534) + param_4);
    puVar1 = puVar6 + 2;
    puVar4 = (uint *)(param_4 + 0x38);
    if (uVar10 == 0) {
      uVar2 = 1;
    }
    else {
      uVar9 = uVar7 + 8;
      if (((ulonglong)puVar1 & 0xfff) != 0) {
        uVar9 = uVar7;
        puVar1 = puVar6;
      }
      local_38 = (ulonglong)uVar10;
      do {
        lVar3 = (ulonglong)uVar11 + *(longlong *)puVar12;
        uVar10 = puVar12[2] - uVar11;
        uVar11 = 0;
        if (uVar10 != 0) {
          param_6._4_4_ = (uint)((ulonglong)lVar3 >> 0x20);
          puVar6 = puVar1 + 2;
          do {
            if (((ulonglong)puVar6 & 0xfff) == 0) {
              uVar9 = uVar9 + 8;
              *puVar1 = uVar9;
              puVar1[1] = *(uint *)(param_1 + 500);
              puVar1 = puVar1 + 2;
              puVar6 = puVar6 + 2;
            }
            uVar7 = (uint)lVar3;
            uVar8 = 0x1000 - (uVar7 & 0xfff);
            if (cVar5 == '\x01') {
              *puVar4 = uVar7;
              cVar5 = '\x02';
              puVar4[1] = param_6._4_4_;
              puVar4 = puVar4 + 2;
LAB_14000c76b:
              lVar3 = lVar3 + (ulonglong)uVar8;
              if (uVar10 < uVar8) break;
              param_6._4_4_ = (uint)((ulonglong)lVar3 >> 0x20);
              uVar10 = uVar10 - uVar8;
            }
            else {
              if (cVar5 != '\x02') {
                *puVar1 = uVar7;
                puVar6 = puVar6 + 2;
                puVar1[1] = param_6._4_4_;
                puVar1 = puVar1 + 2;
                uVar9 = uVar9 + 8;
                goto LAB_14000c76b;
              }
              if (!bVar13) {
                *puVar4 = uVar7;
                puVar4[1] = param_6._4_4_;
              }
              else {
                *puVar4 = uVar9;
                puVar4[1] = *(uint *)(param_1 + 500);
              }
              cVar5 = '\x03';
              if (!bVar13) goto LAB_14000c76b;
            }
          } while (uVar10 != 0);
        }
        puVar12 = puVar12 + 6;
        local_38 = local_38 - 1;
      } while (local_38 != 0);
      uVar2 = CONCAT71((int7)((ulonglong)lVar3 >> 8),1);
    }
  }
  else {
    LogSystemEvent(param_1,local_res10,0x8004af01,
                   (byte *)"Nvme-Data transfer length exceeds MDTS, data transfer length logged",
                   param_7,param_8);
    local_res14 = *(uint *)(param_6 + 0x10);
    uVar2 = (ulonglong)local_res14;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x27f) != 0)) {
      uVar2 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x27f,
                          (undefined1 *)&local_res10,8,param_7,param_8);
    }
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  return uVar2;
}



===== CheckForNvmeShutdown @ 14000c7d0 =====

undefined8 CheckForNvmeShutdown(longlong param_1,char param_2,byte param_3,int param_4)

{
  ushort uVar1;
  undefined8 *puVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  
  if (*(uint *)(param_1 + 0x9bc) != 0) {
    uVar3 = 0;
    do {
      in_RAX = uVar3;
      iVar6 = (int)in_RAX;
      lVar5 = in_RAX * 0x2c;
      if ((*(char *)(lVar5 + 0x24 + *(longlong *)(param_1 + 0x5c0)) != '\0') &&
         (in_RAX = 0,
         ((byte)*(undefined4 *)(lVar5 + 0x14 + *(longlong *)(param_1 + 0x5c0)) & 0xf) == 3)) {
        puVar2 = *(undefined8 **)(param_1 + 0x570);
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        puVar2[4] = 0;
        *(undefined4 *)(puVar2 + 5) = 0;
        *(undefined1 *)((longlong)puVar2 + 3) = 0x1b;
        *(undefined1 *)puVar2 = 0x16;
        *(undefined1 *)(param_1 + 0x11b6) = 1;
        QueueRequestDescriptor
                  (param_1,(uint)*(ushort *)(param_1 + 0x9b4) * 0x10000 + 8,0,param_3,param_4);
        LogSystemEvent(param_1,(uint)*(ushort *)(param_1 + 0xbbd8),0x4004af00,
                       (byte *)"Nvme IO unit ctrl shutdown msg sent (max shut down time logged)",
                       param_3,param_4);
        uVar1 = *(ushort *)(param_1 + 0xbbd8);
        uVar3 = (ulonglong)uVar1;
        if (param_2 != '\0') {
          uVar7 = 0;
          if ((uint)uVar1 * 2000 == 0) goto LAB_14000c91c;
          goto LAB_14000c8e0;
        }
        *(uint *)(param_1 + 0x974) = (uint)uVar1;
        goto LAB_14000c8ca;
      }
      uVar7 = iVar6 + 1;
      uVar3 = (ulonglong)uVar7;
    } while (uVar7 < *(uint *)(param_1 + 0x9bc));
  }
  return in_RAX & 0xffffffffffffff00;
  while( true ) {
    StorPortStallExecution(500);
    uVar7 = uVar7 + 1;
    if ((uint)*(ushort *)(param_1 + 0xbbd8) * 2000 <= uVar7) break;
LAB_14000c8e0:
    PollLSImpiIsr(param_1,param_3,param_4);
    if (*(char *)(param_1 + 0x11b6) == '\0') break;
  }
LAB_14000c91c:
  uVar3 = (ulonglong)*(ushort *)(param_1 + 0xbbd8);
  if (((uVar7 == (uint)*(ushort *)(param_1 + 0xbbd8) * 2000) &&
      (uVar3 = LogSystemEvent(param_1,0,0x8004af01,
                              (byte *)"Nvme IO unit ctrl shutdown msg timed out",param_3,param_4),
      *(char *)(param_1 + 0x608) != '\0')) && ((*(uint *)(param_1 + 0x60c) & 0x254) != 0)) {
    uVar4 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x254,
                        (undefined1 *)0x0,0,param_3,param_4);
    return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  }
LAB_14000c8ca:
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== CheckInqFlagReplies @ 14000c9b0 =====

ulonglong CheckInqFlagReplies(longlong param_1,undefined1 *param_2,byte *param_3,byte param_4,
                             int param_5)

{
  char cVar1;
  longlong lVar2;
  ushort *puVar3;
  char *pcVar4;
  char cVar5;
  ushort uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int *piVar10;
  ulonglong uVar11;
  byte bVar12;
  undefined1 uVar13;
  byte bVar14;
  size_t _Size;
  undefined8 *puVar15;
  ushort *puVar16;
  longlong lVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool local_res18;
  int iVar21;
  char local_77;
  byte local_76;
  int *local_70;
  ushort local_68;
  uint local_64;
  uint local_60;
  undefined1 *local_58;
  longlong local_50;
  
  local_68 = *(ushort *)(param_3 + 2);
  cVar1 = *(char *)(param_1 + 0x120a);
  puVar15 = (undefined8 *)((ulonglong)local_68 * 0x20 + *(longlong *)(param_1 + 0x598));
  lVar17 = 0;
  if ((*(uint *)(puVar15 + 3) & 4) == 0) {
    return (ulonglong)(*(uint *)(puVar15 + 3) & 0xffffff00);
  }
  bVar18 = (*param_3 & 0xf) != 1;
  if (!bVar18) {
    lVar17 = (ulonglong)*(uint *)(param_3 + 4) + *(longlong *)(param_1 + 0x108);
  }
  *param_2 = 1;
  lVar2 = puVar15[1];
  if (lVar2 == 0) {
    uVar9 = LogSystemEvent(param_1,0xad010024,0xc004af02,
                           (byte *)"NULL Srb when Inquiry reply processed",param_4,param_5);
    return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
  }
  local_60 = *(uint *)(lVar2 + 0x3c);
  local_70 = *(int **)(lVar2 + 0x68);
  puVar3 = (ushort *)*puVar15;
  local_77 = (char)puVar3[0x20];
  puVar16 = puVar3;
  if (cVar1 == '\0') {
    puVar16 = (ushort *)0x0;
  }
  local_76 = *(byte *)((longlong)puVar3 + 0x41);
  if (*(char *)(lVar2 + 3) == '\0') {
    *(undefined1 *)(*(longlong *)(local_70 + 0x10) + 8) = 0;
    *(undefined1 *)(lVar2 + 3) = 1;
  }
  local_58 = (undefined1 *)((longlong)local_70 + 0x62);
  piVar10 = (int *)StorPortGetLogicalUnit
                             (param_1,*local_58,*(undefined1 *)((longlong)local_70 + 99),
                              (char)local_70[0x19]);
  iVar21 = param_5;
  local_50 = FindMappingTableEntry
                       (param_1,(ushort)*(byte *)((longlong)local_70 + 0x62),
                        (ushort)*(byte *)((longlong)local_70 + 99),0xffffffff);
  if (local_50 == 0) {
    *(undefined1 *)(lVar2 + 3) = 10;
  }
  else {
    pcVar4 = *(char **)(lVar2 + 0x40);
    local_64 = CONCAT31((uint3)(*(uint *)(param_1 + 0x120c) >> 0x13),
                        (char)(*(uint *)(param_1 + 0x120c) >> 0xb)) & 0xffffff01;
    bVar19 = *(char *)(param_1 + 0x11ef) != '\0';
    if (local_77 == '\x12') {
      if ((local_76 & 1) == 0) {
        if (bVar18) {
          bVar14 = 0;
          uVar13 = 1;
        }
        else {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2001) != 0))
          {
            iVar21 = 3;
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2001,
                        local_58,3,param_4,param_5);
          }
          bVar14 = *(byte *)(lVar17 + 0xc);
          uVar7 = bVar14 - 8;
          if ((uVar7 & 0xdf) == 0) {
            *(byte *)(*(longlong *)(local_70 + 0x10) + 8) = bVar14;
            *(undefined1 *)(lVar2 + 3) = 5;
            goto LAB_14000d0b9;
          }
          if (((*(byte *)(lVar17 + 0xd) & 0x10) != 0) &&
             (uVar7 = *(uint *)(lVar17 + 0x1c), (char)uVar7 == '\x02')) {
            *(undefined1 *)(local_50 + 0x22) = 0;
            *(undefined4 *)(puVar15 + 3) = 0;
            return (ulonglong)(uVar7 & 0xffffff00);
          }
          uVar11 = (ulonglong)uVar7;
          if ((*(ushort *)(lVar17 + 0xe) & 0x7fff) == 0x45) {
            if ((*(byte *)(lVar17 + 0xd) & 1) != 0) goto LAB_14000ce7d;
            uVar13 = 0x12;
            *(undefined4 *)(lVar2 + 0x3c) = *(undefined4 *)(lVar17 + 0x14);
          }
          else {
            uVar11 = 0xffbf;
            if (((*(ushort *)(lVar17 + 0xe) & 0x7fbf) != 0) || (bVar14 != 0)) goto LAB_14000ce7d;
            uVar13 = 1;
          }
        }
        if (pcVar4 == (char *)0x0) {
          bVar20 = false;
          local_res18 = false;
          uVar7 = 0;
        }
        else {
          cVar5 = *pcVar4;
          bVar20 = cVar5 == '\0';
          if (bVar20) {
            *(undefined1 *)(local_50 + 0x25) = 1;
            cVar5 = *pcVar4;
          }
          local_res18 = bVar20 && bVar19;
          bVar20 = bVar20 && bVar19;
          if ((cVar5 == '\x01') && ((*(uint *)(local_50 + 0x14) & 0x400) != 0)) {
            uVar7 = local_64;
          }
          else {
            uVar7 = 0;
          }
        }
        if (piVar10 != (int *)0x0) {
          if (bVar20) {
            *(undefined1 *)(piVar10 + 1) = 0;
          }
          *(undefined1 *)((longlong)piVar10 + 5) = 0;
        }
        *(byte *)(*(longlong *)(local_70 + 0x10) + 8) = bVar14;
        *(undefined1 *)(lVar2 + 3) = uVar13;
        bVar14 = (byte)*(undefined4 *)(local_50 + 0x14);
        if (*(char *)(local_50 + 0x24) == '\0') {
          if (-1 < (char)bVar14) goto LAB_14000cd1c;
          uVar8 = *(undefined4 *)(param_1 + 0x988);
        }
        else if ((bVar14 & 0xf) == 3) {
          uVar8 = *(undefined4 *)(param_1 + 0x98c);
        }
        else {
LAB_14000cd1c:
          uVar8 = *(undefined4 *)(param_1 + 0x984);
        }
        uVar11 = StorPortSetDeviceQueueDepth
                           (param_1,*(undefined1 *)((longlong)local_70 + 0x62),
                            *(undefined1 *)((longlong)local_70 + 99),(char)local_70[0x19],uVar8,
                            iVar21);
        if (piVar10 == (int *)0x0) {
LAB_14000ce6f:
          if (!bVar18) {
LAB_14000ce7d:
            *(undefined4 *)(puVar15 + 3) = 0;
            return uVar11 & 0xffffffffffffff00;
          }
          goto LAB_14000d0b9;
        }
        uVar11 = 0;
        if (((!local_res18) && ((char)uVar7 == '\0')) || (local_60 < 0x1a)) goto LAB_14000ce6f;
        if ((!local_res18) || ((pcVar4[5] & 1U) == 0)) {
          if ((char)uVar7 == '\0') goto LAB_14000d0b9;
          *(undefined1 *)((longlong)puVar3 + 0x41) = 1;
          *(undefined2 *)((longlong)puVar3 + 0x43) = 0x1a00;
          uVar7 = 0x1a;
          memmove((void *)((longlong)piVar10 + 6),*(void **)(lVar2 + 0x40),0x1a);
          puVar3[0xe] = 0x1a;
          puVar3[0xf] = 0;
          if (cVar1 != '\0') goto LAB_14000cdb5;
          if ((*(uint *)(puVar3 + 0x30) & 0xffffff) < 0x1a) goto LAB_14000cdef;
          *(uint *)(puVar3 + 0x30) = *(uint *)(puVar3 + 0x30) & 0xff00001a | 0x1a;
        }
        else {
          puVar3[0x20] = 0;
          puVar3[0x21] = 0;
          puVar3[0x22] = 0;
          puVar3[0x23] = 0;
          puVar3[0x24] = 0;
          puVar3[0x25] = 0;
          puVar3[0x26] = 0;
          puVar3[0x27] = 0;
          puVar3[0x20] = 0x109e;
          uVar7 = 0xe;
          *(undefined1 *)((longlong)puVar3 + 0x4d) = 0xe;
          memmove((void *)((longlong)piVar10 + 6),*(void **)(lVar2 + 0x40),0xe);
          puVar3[0xe] = 0xe;
          puVar3[0xf] = 0;
          puVar3[0x12] = puVar3[0x12] & 0xfe10 | 0x10;
          if (cVar1 == '\0') {
            if ((*(uint *)(puVar3 + 0x30) & 0xffffff) < 0xe) {
LAB_14000cdef:
              uVar11 = (ulonglong)(*(ushort *)(param_1 + 0x542) & 1) | 2;
              *(uint *)(puVar3 + uVar11 * 2 + 0x30) =
                   *(uint *)(puVar3 + uVar11 * 2 + 0x30) & 0xff000000;
              *(uint *)(puVar3 + uVar11 * 2 + 0x30) =
                   *(uint *)(puVar3 + uVar11 * 2 + 0x30) |
                   uVar7 - (*(uint *)(puVar3 + 0x30) & 0xffffff);
            }
            else {
              *(uint *)(puVar3 + 0x30) = *(uint *)(puVar3 + 0x30) & 0xff00000e | 0xe;
            }
          }
          else {
LAB_14000cdb5:
            if (*(uint *)(puVar16 + 0x34) < uVar7) {
              *(uint *)(puVar16 + 0x3c) = uVar7 - *(uint *)(puVar16 + 0x34);
            }
            else {
              *(uint *)(puVar16 + 0x34) = uVar7;
            }
          }
        }
LAB_14000d026:
        QueueRequestDescriptor
                  (param_1,(uint)local_68 * 0x10000 + *local_70,(uint)*puVar3 << 0x10,param_4,
                   param_5);
        *param_2 = 0;
        goto LAB_14000d172;
      }
      if (bVar18) {
LAB_14000cf14:
        bVar14 = pcVar4[3];
        if (bVar14 < 0x17) {
          if (bVar14 == 0) goto LAB_14000cf45;
        }
        else {
          bVar14 = 0x16;
        }
        bVar12 = 0;
        do {
          if (pcVar4[(ulonglong)bVar12 + 4] == -0x70) goto LAB_14000d09c;
          bVar12 = bVar12 + 1;
        } while (bVar12 < bVar14);
      }
      else {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2001) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2001,
                      local_58,3,param_4,param_5);
        }
        uVar6 = *(ushort *)(lVar17 + 0xe) & 0x7fff;
        if (((uVar6 == 0) || (uVar6 == 0x45)) && (*(char *)(lVar17 + 0xc) == '\0'))
        goto LAB_14000cf14;
      }
LAB_14000cf45:
      if ((*(uint *)(local_50 + 0x14) >> 0x1e & 1) == 0) {
        uVar11 = 0;
        do {
          if (*(char *)(uVar11 + 0xe + (longlong)piVar10) != (&vendorHP)[uVar11])
          goto LAB_14000d0a1;
          bVar14 = (char)uVar11 + 1;
          uVar11 = (ulonglong)bVar14;
        } while (bVar14 < 8);
        if (bVar14 == 8) {
          *(uint *)(local_50 + 0x14) = *(uint *)(local_50 + 0x14) | 0x40000000;
          puVar3[0x12] = 6;
          puVar3[0x20] = 0;
          puVar3[0x21] = 0;
          puVar3[0x22] = 0;
          puVar3[0x23] = 0;
          puVar3[0x24] = 0;
          puVar3[0x25] = 0;
          puVar3[0x26] = 0;
          puVar3[0x27] = 0;
          *(uint *)(puVar3 + 0x30) = *(uint *)(puVar3 + 0x30) & 0xff000000;
          puVar3[0x20] = 0x1c2;
          puVar3[0xe] = 0;
          puVar3[0xf] = 0;
          goto LAB_14000d026;
        }
      }
LAB_14000d0a1:
      _Size = 0x1a;
    }
    else {
      if (local_77 != -0x62) {
        if (local_77 != -0x3e) {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x205) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x205,
                        &local_77,1,param_4,param_5);
          }
          *param_2 = 1;
          goto LAB_14000d172;
        }
        if (bVar18) {
LAB_14000d09c:
          *(undefined1 *)(local_50 + 0x22) = 0x40;
        }
        else {
          *(char *)((longlong)piVar10 + 5) = *(char *)((longlong)piVar10 + 5) + '\x01';
          if (*(byte *)((longlong)piVar10 + 5) < 2) goto LAB_14000d026;
          LogSystemEvent(param_1,0xad010033,0xc004af02,(byte *)"SAS tape drive TLR enable failed",
                         param_4,param_5);
        }
        goto LAB_14000d0a1;
      }
      if (bVar18) {
        if ((pcVar4[0xc] & 1U) != 0) {
          *(undefined1 *)(piVar10 + 1) = 1;
          *piVar10 = (uint)(byte)pcVar4[8] * 0x1000000 + (uint)(byte)pcVar4[9] * 0x10000 +
                     (uint)(byte)pcVar4[10] * 0x100 + (uint)(byte)pcVar4[0xb];
        }
        _Size = 0xe;
      }
      else {
        *(char *)((longlong)piVar10 + 5) = *(char *)((longlong)piVar10 + 5) + '\x01';
        if (*(byte *)((longlong)piVar10 + 5) < 4) goto LAB_14000d026;
        _Size = 0xe;
      }
    }
    memmove(*(void **)(lVar2 + 0x40),(void *)((longlong)piVar10 + 6),_Size);
  }
LAB_14000d0b9:
  if ((*(char *)(param_1 + 0xba00) != '\0') &&
     (lVar17 = (ulonglong)*(byte *)((longlong)local_70 + 0x62) * 0x80 +
               (ulonglong)*(byte *)((longlong)local_70 + 99),
     0 < *(int *)(*(longlong *)(param_1 + 0xba30) + lVar17 * 4))) {
    LOCK();
    piVar10 = (int *)(*(longlong *)(param_1 + 0xba30) + lVar17 * 4);
    *piVar10 = *piVar10 + -1;
    UNLOCK();
  }
  param_2 = (undefined1 *)StorPortNotification(0,param_1,lVar2);
  *(byte *)((longlong)puVar15 + 0x13) = *(byte *)((longlong)puVar15 + 0x13) | 1;
LAB_14000d172:
  return CONCAT71((int7)((ulonglong)param_2 >> 8),1);
}



===== CheckIoctlQueue @ 14000d1b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CheckIoctlQueue(longlong param_1,byte param_2,int param_3)

{
  byte bVar1;
  void *pvVar2;
  char cVar3;
  undefined8 uVar4;
  undefined1 auStackY_88 [32];
  void *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar4 = 0;
  if ((((*(char *)(param_1 + 0x18f4) == '\0') && (*(int *)(param_1 + 0x968) == 0)) &&
      (*(char *)(param_1 + 0x11b6) == '\0')) && (*(int *)(param_1 + 0x1218) == 0)) {
    if (*(char *)(param_1 + 0x18f5) == '\0') {
      do {
        bVar1 = *(byte *)(param_1 + 0x12ae);
        pvVar2 = *(void **)(param_1 + 0x12b8 + (ulonglong)bVar1 * 8);
        if (pvVar2 == (void *)0x0) {
          return uVar4;
        }
        *(undefined8 *)(param_1 + 0x12b8 + (ulonglong)bVar1 * 8) = 0;
        cVar3 = '\0';
        if (bVar1 != 0x1f) {
          cVar3 = bVar1 + 1;
        }
        *(char *)(param_1 + 0x12ae) = cVar3;
        local_38 = *(undefined1 *)((longlong)pvVar2 + 3);
        local_40 = *(undefined4 *)(*(longlong *)((longlong)pvVar2 + 0x40) + 0x10);
        local_3c = *(undefined4 *)(*(longlong *)((longlong)pvVar2 + 0x40) + 0x14);
        local_48 = pvVar2;
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400008) != 0))
        {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400008,
                      (undefined1 *)&local_48,0x11,param_2,param_3);
        }
        LsiHandleAppRequest(param_1,pvVar2,param_2,param_3);
        uVar4 = 1;
      } while (*(char *)(param_1 + 0x1220) == '\0');
    }
    else {
      *(undefined1 *)(param_1 + 0x18f5) = 0;
      if (*(int *)(param_1 + 0x970) == 0) {
        PauseAdapterQueue(param_1,0xd,param_2,param_3);
      }
      ResetActive(param_1,0xf,param_2,param_3);
      *(undefined1 *)(param_1 + 0x18f4) = 1;
      *(undefined1 *)(param_1 + 0x18f8) = 1;
      SasBcAsyncEvent(param_1,param_2,param_3);
    }
  }
  return uVar4;
}



===== CheckMpiIoctlReply @ 14000d370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CheckMpiIoctlReply(longlong param_1,byte *param_2,byte param_3,int param_4)

{
  longlong *plVar1;
  int *piVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  bool bVar6;
  undefined8 uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  int *piVar12;
  size_t _Size;
  undefined4 uVar13;
  longlong lVar14;
  undefined1 auStackY_b8 [32];
  longlong local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar10 = 0;
  lVar11 = (ulonglong)*(ushort *)(param_2 + 2) * 0x20 + *(longlong *)(param_1 + 0x598);
  local_68 = 0;
  local_6c = 0;
  uVar8 = *(uint *)(lVar11 + 0x18);
  if ((uVar8 & 1) == 0) {
    return (ulonglong)(uVar8 & 0xffffff00);
  }
  *(undefined4 *)(lVar11 + 0x18) = 0;
  if ((*param_2 & 0xf) == 1) {
    lVar11 = (ulonglong)*(uint *)(param_2 + 4) + *(longlong *)(param_1 + 0x108);
    if ((*(int *)(lVar11 + 0x10) != 0) && ((short)*(ushort *)(lVar11 + 0xe) < 0)) {
      AfdMpiLogInfoTrigger
                (param_1,*(int *)(lVar11 + 0x10),*(ushort *)(lVar11 + 0xe),param_3,param_4);
    }
    bVar6 = false;
  }
  else {
    bVar6 = true;
    lVar11 = 0;
  }
  plVar1 = (longlong *)(param_1 + 0x1228);
  if ((*(char *)(param_1 + 0x1220) == '\0') && (*plVar1 == 0)) {
LAB_14000d5a9:
    lVar14 = 0;
    if (bVar6) goto LAB_14000d694;
    goto LAB_14000d5b5;
  }
  lVar10 = *plVar1;
  piVar12 = (int *)(param_1 + 0x1230);
  uVar8 = 0;
  lVar14 = lVar10 - (longlong)piVar12;
  local_70 = *(undefined4 *)(*(longlong *)(lVar10 + 0x40) + 0x10);
  lVar5 = *(longlong *)(lVar10 + 0x68);
  do {
    iVar4 = *piVar12;
    piVar2 = (int *)(lVar14 + (longlong)piVar12);
    piVar12 = piVar12 + 1;
    local_78 = lVar10;
    if (iVar4 != *piVar2) {
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x40000c) == 0))
      goto LAB_14000d5a2;
      uVar13 = 0x40000c;
      goto LAB_14000d570;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x10);
  uVar8 = 0;
  piVar12 = *(int **)(param_1 + 0x1270);
  if (*(ushort *)(param_1 + 0x536) != 0) {
    lVar14 = lVar5 - (longlong)piVar12;
LAB_14000d4a0:
    iVar4 = *piVar12;
    piVar2 = (int *)(lVar14 + 0x168 + (longlong)piVar12);
    piVar12 = piVar12 + 1;
    if (iVar4 == *piVar2) goto code_r0x00014000d4b3;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40000d) != 0)) {
      uVar13 = 0x40000d;
LAB_14000d570:
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar13,
                  (undefined1 *)&local_78,0x11,param_3,param_4);
    }
LAB_14000d5a2:
    *(undefined1 *)(param_1 + 0x1220) = 0;
    goto LAB_14000d5a9;
  }
LAB_14000d4ba:
  lVar14 = *(longlong *)(lVar10 + 0x40);
  *(undefined4 *)(lVar14 + 0x14) = 0;
  if (bVar6) {
    *(undefined4 *)(lVar14 + 0x1c) = 0;
    goto LAB_14000d694;
  }
  uVar9 = 0;
  if (*(char *)(lVar11 + 2) != '\0') {
    do {
      lVar3 = uVar9 * 4;
      uVar8 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar8;
      *(undefined4 *)(lVar3 + 0x1c + lVar14) = *(undefined4 *)(lVar3 + lVar11);
    } while (uVar8 < *(byte *)(lVar11 + 2));
  }
  if (*(char *)(lVar11 + 3) == '\0') {
    if ((*(byte *)(lVar11 + 0xd) & 1) != 0) {
      _Size = (size_t)*(uint *)(lVar11 + 0x18);
      goto LAB_14000d536;
    }
  }
  else if (*(char *)(lVar11 + 3) == '3') {
    _Size = (size_t)*(ushort *)(lVar11 + 0x14);
LAB_14000d536:
    memmove(*(void **)(param_1 + 0x1278),(void *)(lVar5 + 0x68),_Size);
  }
LAB_14000d5b5:
  if ((*(char *)(lVar11 + 3) == '\x01') &&
     (((*(longlong *)(param_1 + 0x928) != 0 || (*(int *)(param_1 + 0x1218) != 0)) ||
      (uVar7 = CheckResetQueue(param_1,param_3,param_4), (char)uVar7 == '\0')))) {
    local_60 = *(undefined4 *)(param_1 + 0x968);
    local_5c = 0x40000005;
    if ((((*(longlong *)(param_1 + 0x928) == 0) && (*(char *)(param_1 + 0x18f4) == '\0')) &&
        (*(char *)(param_1 + 0x1210) == '\0')) && (*(int *)(param_1 + 0x1288) == 0)) {
      *(undefined4 *)(param_1 + 0x968) = 0;
      local_5c = 0xffffffff40000005;
    }
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20020) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20020,
                  (undefined1 *)&local_60,0xc,param_3,param_4);
    }
    ResumeAdapterQueue(param_1,4,param_3,param_4);
  }
LAB_14000d694:
  if ((*(char *)(param_1 + 0x1220) == '\0') && (*plVar1 == 0)) {
    CleanUpIoctl(param_1,param_3,param_4);
  }
  else {
    *(undefined1 *)(lVar10 + 3) = 1;
    local_68 = 1;
    if (lVar14 != 0) {
      local_6c = *(undefined4 *)(lVar14 + 0x14);
    }
    StorPortNotification(0,param_1,lVar10);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400023) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400023,
                  (undefined1 *)&local_78,0x11,param_3,param_4);
    }
    *(undefined1 *)(param_1 + 0x1220) = 0;
    *plVar1 = 0;
  }
  uVar7 = CheckIoctlQueue(param_1,param_3,param_4);
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
code_r0x00014000d4b3:
  uVar8 = uVar8 + 1;
  if (*(ushort *)(param_1 + 0x536) <= uVar8) goto LAB_14000d4ba;
  goto LAB_14000d4a0;
}



===== CheckPfaSataReplies @ 14000d790 =====

longlong CheckPfaSataReplies(longlong param_1,undefined4 *param_2,byte param_3,int param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  lVar3 = (ulonglong)*(ushort *)((longlong)param_2 + 2) * 0x20 + *(longlong *)(param_1 + 0x598);
  uVar1 = *(uint *)(lVar3 + 0x18);
  uVar2 = (ulonglong)uVar1;
  if ((uVar1 >> 8 & 1) == 0) {
    lVar3 = (ulonglong)(uint3)(uVar1 >> 8) << 8;
  }
  else {
    if (uVar1 == 0x100) {
      GtfStopTimer(param_1,*(byte *)(param_1 + 0xb932),param_3,param_4);
      *(undefined4 *)(param_1 + 0xb93c) = *param_2;
      *(undefined4 *)(param_1 + 0xb940) = param_2[1];
      *(undefined4 *)(lVar3 + 0x18) = 0;
      uVar2 = DetectSataPfa(param_1,0,0,param_3,param_4);
    }
    lVar3 = CONCAT71((int7)(uVar2 >> 8),1);
  }
  return lVar3;
}



===== CheckResetQueue @ 14000d840 =====

ulonglong CheckResetQueue(longlong param_1,byte param_2,int param_3)

{
  undefined8 *puVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  ushort *puVar5;
  undefined4 uVar6;
  ulonglong in_RAX;
  ulonglong uVar7;
  undefined8 uVar8;
  char cVar9;
  longlong lVar10;
  ushort uVar11;
  uint local_res8 [2];
  undefined1 local_res20 [8];
  
  local_res8[0] = 0;
  if (*(longlong *)(param_1 + 0x928) == 0) {
    uVar7 = (ulonglong)*(byte *)(param_1 + 0x12b0);
    puVar1 = (undefined8 *)(param_1 + (uVar7 + 0x277) * 8);
    lVar10 = *(longlong *)(param_1 + (uVar7 + 0x277) * 8);
    while (lVar10 != 0) {
      *puVar1 = 0;
      in_RAX = 0;
      cVar9 = '\0';
      if ((char)uVar7 != 'c') {
        cVar9 = (char)uVar7 + '\x01';
      }
      *(char *)(param_1 + 0x12b0) = cVar9;
      if (lVar10 == -1) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2001d) != 0)) {
          in_RAX = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                               0x2001d,(undefined1 *)0x0,0,param_2,param_3);
        }
      }
      else {
        lVar4 = *(longlong *)(lVar10 + 0x68);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20001) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20001,
                      (undefined1 *)(lVar4 + 0x62),3,param_2,param_3);
        }
        local_res8[0] =
             (uint)CONCAT21(CONCAT11(*(byte *)(lVar4 + 0x62),*(byte *)(lVar4 + 99)),
                            *(undefined1 *)(lVar4 + 100));
        uVar11 = (ushort)*(byte *)(lVar4 + 0x62) * 0x80 + (ushort)*(byte *)(lVar4 + 99);
        if ((uint)uVar11 < *(uint *)(param_1 + 0x9bc)) {
          uVar2 = *(ushort *)((ulonglong)uVar11 * 0x2c + 0x1a + *(longlong *)(param_1 + 0x5c0));
          if (uVar2 != 0) {
            ResetActive(param_1,0x10,param_2,param_3);
            *(longlong *)(param_1 + 0x928) = lVar10;
            uVar3 = *(uint *)(lVar10 + 0x14);
            uVar7 = (ulonglong)uVar3;
            if (uVar3 == 0x13) {
              puVar5 = *(ushort **)(param_1 + 0x568);
              lVar10 = (ulonglong)uVar11 * 0x2c;
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
              *puVar5 = uVar2;
              *(undefined1 *)((longlong)puVar5 + 3) = 1;
              *(undefined1 *)((longlong)puVar5 + 5) = 3;
              if (((*(char *)(lVar10 + 0x24 + *(longlong *)(param_1 + 0x5c0)) != '\0') &&
                  (*(char *)(param_1 + 0x18b0) == '\0')) &&
                 ((*(uint *)(lVar10 + 0x14 + *(longlong *)(param_1 + 0x5c0)) & 4) == 0)) {
                *(undefined1 *)((longlong)puVar5 + 7) = 0x18;
              }
              QueueRequestDescriptor
                        (param_1,(uint)*(ushort *)(param_1 + 0x9b2) * 0x10000 + 6,0,param_2,param_3)
              ;
              if ((*(char *)(param_1 + 0x608) != '\0') &&
                 ((*(uint *)(param_1 + 0x60c) & 0x20006) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                            0x20006,(undefined1 *)(lVar4 + 0x62),3,param_2,param_3);
              }
              LogOperationalEvent(param_1,(int *)local_res8,4,0x4004af00,
                                  "Issuing OS initiated Target Reset, Adapter Queue paused,BTL logged"
                                  ,param_2,param_3);
              uVar7 = AfdMasterTrigger(param_1,4,param_2,param_3);
            }
            else if (uVar3 == 0x20) {
              lVar10 = *(longlong *)(lVar10 + 0x68);
              uVar7 = GtfStartTimer(param_1,1,2,LunResetTurTimeout,0,param_2,param_3);
              *(char *)(param_1 + 0xab0) = (char)uVar7;
              if ((((char)uVar7 == -2) && (*(char *)(param_1 + 0x608) != '\0')) &&
                 ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                            (undefined1 *)0x0,0,param_2,param_3);
              }
              *(undefined4 *)
               ((ulonglong)*(ushort *)(param_1 + 0x9b2) * 0x20 + 0x18 +
               *(longlong *)(param_1 + 0x598)) = 0x40;
              *(undefined1 *)(lVar10 + 0x65) = 0;
              puVar5 = *(ushort **)(param_1 + 0x568);
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
              puVar5[0x1a] = 0;
              puVar5[0x1b] = 0;
              puVar5[0x1c] = 0;
              puVar5[0x1d] = 0;
              puVar5[0x1e] = 0;
              puVar5[0x1f] = 0;
              puVar5[0x20] = 0;
              puVar5[0x21] = 0;
              puVar5[0x22] = 0;
              puVar5[0x23] = 0;
              puVar5[0x24] = 0;
              puVar5[0x25] = 0;
              puVar5[0x26] = 0;
              puVar5[0x27] = 0;
              puVar5[0x28] = 0;
              puVar5[0x29] = 0;
              puVar5[0x2a] = 0;
              puVar5[0x2b] = 0;
              puVar5[0x2c] = 0;
              puVar5[0x2d] = 0;
              puVar5[0x2e] = 0;
              puVar5[0x2f] = 0;
              puVar5[0x30] = 0;
              puVar5[0x31] = 0;
              puVar5[0x32] = 0;
              puVar5[0x33] = 0;
              puVar5[0x34] = 0;
              puVar5[0x35] = 0;
              puVar5[0x36] = 0;
              puVar5[0x37] = 0;
              *(undefined1 *)(puVar5 + 10) = 0x18;
              *puVar5 = uVar2;
              uVar6 = StorPortGetPhysicalAddress
                                (param_1,*(undefined8 *)(param_1 + 0x928),lVar10 + 0x68,local_res20)
              ;
              *(undefined1 *)(puVar5 + 9) = 0xff;
              *(undefined4 *)(puVar5 + 6) = uVar6;
              puVar5[0x12] = 6;
              BuildZeroLenSGE(param_1,(longlong)puVar5,*(int *)(param_1 + 0x208),
                              *(char *)(param_1 + 0x120a));
              uVar7 = QueueRequestDescriptor
                                (param_1,(uint)*(ushort *)(param_1 + 0x9b2) << 0x10,
                                 (uint)*puVar5 << 0x10,param_2,param_3);
              if ((*(char *)(param_1 + 0x608) != '\0') &&
                 ((*(uint *)(param_1 + 0x60c) & 0x20008) != 0)) {
                uVar8 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),
                                    (ulonglong *)(param_1 + 0x5d8),0x20008,
                                    (undefined1 *)(lVar10 + 0x62),3,param_2,param_3);
                return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
              }
            }
            return CONCAT71((int7)(uVar7 >> 8),1);
          }
        }
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2001b) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2001b,
                      (undefined1 *)(lVar4 + 0x62),3,param_2,param_3);
        }
        *(undefined1 *)(lVar10 + 3) = 4;
        in_RAX = StorPortNotification(0,param_1,lVar10);
      }
      uVar7 = (ulonglong)*(byte *)(param_1 + 0x12b0);
      puVar1 = (undefined8 *)(param_1 + 0x13b8 + uVar7 * 8);
      lVar10 = *(longlong *)(param_1 + 0x13b8 + uVar7 * 8);
    }
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2001a) != 0)) {
      in_RAX = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2001a
                           ,(undefined1 *)0x0,0,param_2,param_3);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== CheckSsuReplies @ 14000dd90 =====

longlong CheckSsuReplies(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint7 uVar2;
  
  uVar1 = *(uint *)((ulonglong)*(ushort *)(param_2 + 2) * 0x20 + 0x18 +
                   *(longlong *)(param_1 + 0x598));
  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 0x598) >> 8);
  if ((uVar1 & 0x10) == 0) {
    return (ulonglong)uVar2 << 8;
  }
  if (uVar1 == 0x10) {
    *(int *)(param_1 + 0xb65c) = *(int *)(param_1 + 0xb65c) + -1;
  }
  return CONCAT71(uVar2,1);
}



===== CheckSsuTmrReplies @ 14000ddc0 =====

longlong CheckSsuTmrReplies(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint7 uVar2;
  
  uVar1 = *(uint *)((ulonglong)*(ushort *)(param_2 + 2) * 0x20 + 0x18 +
                   *(longlong *)(param_1 + 0x598));
  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 0x598) >> 8);
  if ((uVar1 & 0x20) == 0) {
    return (ulonglong)uVar2 << 8;
  }
  if (uVar1 == 0x20) {
    *(int *)(param_1 + 0xb65c) = *(int *)(param_1 + 0xb65c) + -1;
  }
  return CONCAT71(uVar2,1);
}



===== CheckTurReplies @ 14000ddf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CheckTurReplies(longlong param_1,byte *param_2,byte param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ushort uVar10;
  undefined1 uVar11;
  longlong lVar12;
  longlong lVar13;
  undefined1 auStackY_d8 [32];
  uint local_78 [2];
  longlong local_70;
  byte local_68;
  byte local_67;
  char local_66;
  byte local_65;
  undefined1 local_64;
  undefined1 local_63;
  ushort local_62;
  short local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_62 = *(ushort *)(param_2 + 2);
  lVar13 = (ulonglong)local_62 * 0x20 + *(longlong *)(param_1 + 0x598);
  if ((*(uint *)(lVar13 + 0x18) & 0x40) == 0) {
    return (ulonglong)(*(uint *)(lVar13 + 0x18) & 0xffffff00);
  }
  *(undefined4 *)(lVar13 + 0x18) = 0;
  lVar5 = *(longlong *)(param_1 + 0x928);
  lVar6 = *(longlong *)(lVar5 + 0x68);
  bVar1 = *(byte *)(lVar6 + 0x62);
  bVar2 = *(byte *)(lVar6 + 99);
  cVar3 = *(char *)(lVar6 + 100);
  local_78[0] = (uint)CONCAT21(CONCAT11(bVar1,bVar2),cVar3);
  local_68 = bVar1;
  local_67 = bVar2;
  local_66 = cVar3;
  GtfStopTimer(param_1,*(byte *)(param_1 + 0xab0),param_3,param_4);
  local_70 = ((ulonglong)*(byte *)(lVar6 + 0x62) * 0x80 + (ulonglong)*(byte *)(lVar6 + 99)) * 0x2c;
  sVar4 = *(short *)(*(longlong *)(param_1 + 0x5c0) + 0x1a + local_70);
  local_60 = sVar4;
  if ((*param_2 & 0xf) == 1) {
    lVar12 = (ulonglong)*(uint *)(param_2 + 4) + *(longlong *)(param_1 + 0x108);
    uVar7 = *(ushort *)(lVar12 + 0xe) & 0x7fff;
    uVar8 = (ulonglong)uVar7;
    if (*(char *)(lVar6 + 0x65) != '\0') {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20022) != 0)) {
        uVar8 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                            0x20022,&local_68,10,param_3,param_4);
      }
      *(undefined1 *)(lVar6 + 0x65) = 0;
      return uVar8 & 0xffffffffffffff00;
    }
    if ((uVar7 != 0x48) && (uVar7 != 0x4b)) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20009) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20009,
                    &local_68,10,param_3,param_4);
      }
      if ((*(byte *)(lVar12 + 0xd) & 1) != 0) {
        if ((byte)(*(char *)(lVar6 + 0x68) + 0x8eU) < 2) {
          local_65 = *(byte *)(lVar6 + 0x69);
          local_64 = *(undefined1 *)(lVar6 + 0x6a);
          local_63 = *(undefined1 *)(lVar6 + 0x6b);
        }
        else {
          local_65 = *(byte *)(lVar6 + 0x6a);
          local_64 = *(undefined1 *)(lVar6 + 0x74);
          local_63 = *(undefined1 *)(lVar6 + 0x75);
        }
        local_65 = local_65 & 0xf;
        if (((((*(byte *)(lVar6 + 0x6a) & 0xf) == 6) && (*(char *)(lVar6 + 0x74) == ')')) ||
            (((*(byte *)(lVar6 + 0x69) & 0xf) == 6 && (*(byte *)(lVar6 + 0x6a) == 0x29)))) &&
           ((*(char *)(param_1 + 0x11ee) != '\0' &&
            ((*(uint *)(*(longlong *)(param_1 + 0x5c0) + 0x14 + local_70) & 0x400) != 0)))) {
          *(undefined1 *)(lVar5 + 3) = 1;
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2000a) != 0))
          {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2000a,
                        &local_68,10,param_3,param_4);
          }
          *(undefined8 *)(lVar13 + 8) = *(undefined8 *)(param_1 + 0x928);
          *(undefined1 *)(lVar13 + 0x13) = 0;
          uVar9 = HandleUnitAttenReset
                            (param_1,*(ushort *)(param_1 + 0x9b2),*(undefined8 **)(param_1 + 0x568),
                             bVar1,bVar2,cVar3,'\x01',param_3,param_4);
          goto LAB_14000e311;
        }
      }
      goto LAB_14000e20f;
    }
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20021) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20021,
                  &local_68,10,param_3,param_4);
    }
    *(undefined1 *)(lVar5 + 3) = 4;
    StorPortNotification(0,param_1,lVar5);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20010) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20010,
                  (undefined1 *)(lVar6 + 0x62),3,param_3,param_4);
    }
    *(undefined8 *)(param_1 + 0x928) = 0;
    uVar9 = CheckResetQueue(param_1,param_3,param_4);
    if ((char)uVar9 != '\0') goto LAB_14000e311;
    ResetActive(param_1,0x4000001e,param_3,param_4);
    uVar11 = 0xc;
  }
  else {
LAB_14000e20f:
    uVar7 = *(ushort *)(param_1 + 0x998);
    uVar8 = 1;
    if (uVar7 != 0) {
      do {
        if ((*(longlong *)(uVar8 * 0x20 + 8 + *(longlong *)(param_1 + 0x598)) != 0) &&
           (sVar4 == *(short *)(uVar8 * 0x20 + 0x14 + *(longlong *)(param_1 + 0x598)))) {
          if ((ushort)uVar8 <= uVar7) {
            LogOperationalEvent(param_1,(int *)local_78,4,0x4004af00,
                                "Issuing OS initiated Lun Reset,Adapter Queue paused(Active IO found on LUN)"
                                ,param_3,param_4);
            uVar9 = IssueLunReset(param_1,param_3,param_4);
            goto LAB_14000e311;
          }
          break;
        }
        uVar10 = (ushort)uVar8 + 1;
        uVar8 = (ulonglong)uVar10;
      } while (uVar10 <= uVar7);
    }
    *(undefined1 *)(lVar5 + 3) = 1;
    StorPortNotification(0,param_1,lVar5);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2000c) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2000c,
                  (byte *)(lVar6 + 0x62),3,param_3,param_4);
    }
    *(undefined8 *)(param_1 + 0x928) = 0;
    uVar9 = CheckResetQueue(param_1,param_3,param_4);
    if ((char)uVar9 != '\0') goto LAB_14000e311;
    ResetActive(param_1,0x40000006,param_3,param_4);
    uVar11 = 5;
  }
  uVar9 = ResumeAdapterQueue(param_1,uVar11,param_3,param_4);
  if (*(char *)(param_1 + 0x1220) == '\0') {
    uVar9 = CheckIoctlQueue(param_1,param_3,param_4);
  }
LAB_14000e311:
  return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
}



===== CleanUpIoctl @ 14000e3a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CleanUpIoctl(longlong param_1,byte param_2,int param_3)

{
  undefined1 auStackY_88 [32];
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  int local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = *(longlong *)(param_1 + 0x1228);
  if (local_48 != 0) {
    local_40 = *(undefined4 *)(*(longlong *)(local_48 + 0x40) + 0x10);
    local_3c = *(undefined4 *)(*(longlong *)(local_48 + 0x40) + 0x14);
    local_38 = 4;
    *(undefined1 *)(local_48 + 3) = 4;
    local_30 = param_3;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0x1228) = 0;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400024) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400024,
                  (undefined1 *)&local_48,0x20,param_2,param_3);
    }
  }
  return;
}



===== ClearResetHistoryBit @ 14000e480 =====

void ClearResetHistoryBit(longlong param_1,byte param_2,int param_3)

{
  byte bVar1;
  
  EnableDiagnosticRegister(param_1,param_2,param_3);
  bVar1 = 0;
  if (*(char *)(param_1 + 0xbbc4) == '\0') {
    bVar1 = 2;
  }
  do {
    bVar1 = bVar1 + 1;
    if (**(uint **)(param_1 + 0x28) != 0) break;
  } while (bVar1 < 3);
  **(uint **)(param_1 + 0x28) = **(uint **)(param_1 + 0x28) & 0xffffffdf;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x20) = 0;
  LOCK();
  UNLOCK();
  return;
}



===== CompleteAllSrbs @ 14000e4e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CompleteAllSrbs(longlong param_1,byte param_2,int param_3)

{
  ushort uVar1;
  byte *pbVar2;
  int *piVar3;
  longlong lVar4;
  undefined1 uVar5;
  uint uVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined1 uVar9;
  bool bVar10;
  undefined1 auStackY_98 [32];
  longlong local_58;
  undefined4 local_50;
  undefined1 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar10 = *(char *)(param_1 + 0x11d2) == '\0';
  uVar5 = 0x11;
  if (bVar10) {
    uVar5 = 4;
  }
  uVar6 = 1;
  uVar9 = 0x11;
  if (bVar10) {
    uVar9 = 0xe;
  }
  lVar7 = *(longlong *)(param_1 + 0x598);
  if (*(short *)(param_1 + 0x998) != 0) {
    do {
      lVar4 = *(longlong *)(lVar7 + 0x28);
      if (lVar4 != 0) {
        *(undefined1 *)(lVar4 + 3) = uVar9;
        if ((*(char *)(param_1 + 0xba00) != '\0') &&
           (lVar4 = (ulonglong)*(byte *)(*(longlong *)(lVar4 + 0x68) + 0x62) * 0x80 +
                    (ulonglong)*(byte *)(*(longlong *)(lVar4 + 0x68) + 99),
           0 < *(int *)(*(longlong *)(param_1 + 0xba30) + lVar4 * 4))) {
          piVar3 = (int *)(*(longlong *)(param_1 + 0xba30) + lVar4 * 4);
          LOCK();
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        StorPortNotification(0,param_1);
        if (*(char *)(param_1 + 0xbbd0) == '\0') {
          uVar1 = *(ushort *)(lVar7 + 0x30);
          LOCK();
          pbVar2 = (byte *)(*(longlong *)(param_1 + 0xaa8) + (ulonglong)(uVar1 >> 5) * 4 +
                           ((longlong)(int)(uVar1 & 0x1f) >> 3));
          *pbVar2 = *pbVar2 | '\x01' << (uVar1 & 7);
          UNLOCK();
        }
        *(byte *)(lVar7 + 0x33) = *(byte *)(lVar7 + 0x33) | 1;
        DetectLostSrb(param_1,lVar7 + 0x20,param_2,param_3);
        *(undefined8 *)(lVar7 + 0x28) = 0;
      }
      uVar6 = uVar6 + 1;
      lVar7 = lVar7 + 0x20;
    } while (uVar6 <= *(ushort *)(param_1 + 0x998));
  }
  plVar8 = (longlong *)(param_1 + 0x12b8);
  lVar7 = 0x20;
  do {
    lVar4 = *plVar8;
    if (lVar4 != 0) {
      *(undefined1 *)(lVar4 + 3) = uVar5;
      local_50 = *(undefined4 *)(*(longlong *)(lVar4 + 0x40) + 0x10);
      local_58 = lVar4;
      local_48 = uVar5;
      StorPortNotification(0,param_1);
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400026) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400026,
                    (undefined1 *)&local_58,0x11,param_2,param_3);
      }
      *plVar8 = 0;
    }
    plVar8 = plVar8 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  plVar8 = (longlong *)(param_1 + 0x13b8);
  lVar7 = 100;
  do {
    lVar4 = *plVar8;
    if (lVar4 != 0) {
      if (*(longlong *)(param_1 + 0x928) == lVar4) {
        *(undefined8 *)(param_1 + 0x928) = 0;
      }
      if ((((*(int *)(lVar4 + 0x14) == 0x20) || (*(int *)(lVar4 + 0x14) == 0x13)) &&
          (*(int *)(lVar4 + 0x3c) == 0)) && (*(longlong *)(lVar4 + 0x40) == 0)) {
        *(undefined1 *)(lVar4 + 3) = uVar5;
        StorPortNotification(0,param_1);
      }
      *plVar8 = 0;
    }
    plVar8 = plVar8 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  lVar7 = *(longlong *)(param_1 + 0x928);
  if (lVar7 != 0) {
    if (((*(int *)(lVar7 + 0x14) == 0x20) || (*(int *)(lVar7 + 0x14) == 0x13)) &&
       ((*(int *)(lVar7 + 0x3c) == 0 && (*(longlong *)(lVar7 + 0x40) == 0)))) {
      *(undefined1 *)(lVar7 + 3) = uVar5;
      StorPortNotification(0,param_1);
    }
    *(undefined8 *)(param_1 + 0x928) = 0;
  }
  return;
}



===== DelayedIoctlTimeout @ 14000e770 =====

ulonglong DelayedIoctlTimeout(longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,
                             int param_5)

{
  ulonglong uVar1;
  
  *(undefined4 *)(param_1 + 0x1218) = 1;
  LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,"Diag Reset(miniport) - IOCTL timed Out",
                      param_4,param_5);
  KickStart(param_1,param_4,param_5);
  *(undefined1 *)(param_1 + 0x1211) = 0;
  uVar1 = StorPortNotification(6,param_1,WatchdogTimer,1000000);
  return uVar1 & 0xffffffffffffff00;
}



===== DetectLostSrb @ 14000e810 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DetectLostSrb(longlong param_1,longlong param_2,byte param_3,int param_4)

{
  longlong lVar1;
  ushort uVar2;
  byte *pbVar3;
  ushort uVar4;
  ulonglong uVar5;
  undefined1 auStackY_f8 [32];
  short local_b8;
  undefined1 local_b6;
  undefined8 local_b0;
  undefined1 local_a8 [128];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  if (*(char *)(param_2 + 0x13) == '\0') {
    local_b0 = *(undefined8 *)(param_2 + 8);
    local_b8 = *(short *)(param_2 + 0x10);
    uVar5 = (ulonglong)*(ushort *)(param_1 + 0x428 + (ulonglong)param_3 * 2);
    local_b6 = 0;
    lVar1 = *(longlong *)(param_1 + 0x550) +
            (ulonglong)((uint)*(ushort *)(param_1 + 0x53a) * (uint)param_3) * 8;
    if (*(int *)(lVar1 + uVar5 * 8) != -1) {
      while( true ) {
        pbVar3 = (byte *)(lVar1 + uVar5 * 8);
        if (*(uint *)(pbVar3 + 4) == 0xffffffff) break;
        if (*(short *)(pbVar3 + 2) == local_b8) {
          if ((*pbVar3 & 0xf) == 1) {
            memmove(local_a8,(void *)((ulonglong)*(uint *)(pbVar3 + 4) +
                                     *(longlong *)(param_1 + 0x108)),0x80);
            local_b6 = 0xff;
          }
          break;
        }
        uVar4 = (short)uVar5 + 1;
        uVar2 = 0;
        if (uVar4 != *(ushort *)(param_1 + 0x53a)) {
          uVar2 = uVar4;
        }
        uVar5 = (ulonglong)uVar2;
        if (*(int *)(lVar1 + uVar5 * 8) == -1) break;
      }
    }
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x270) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x270,
                  (undefined1 *)&local_b8,0x90,param_3,param_4);
    }
    LogSystemEvent(param_1,0xad01009e,0xc004af02,(byte *)"Driver has detected a Lost SRB",param_3,
                   param_4);
    if (*(char *)(param_1 + 0x11bb) != '\0') {
      *(undefined4 *)(param_1 + 0x187c) = _DAT_0000badd;
    }
  }
  return;
}



===== DetectSataPfa @ 14000e980 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DetectSataPfa(longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,
                       int param_5)

{
  uint *puVar1;
  undefined2 uVar2;
  undefined8 *puVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  ushort uVar10;
  undefined4 *puVar11;
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
  
  uVar5 = __security_cookie ^ (ulonglong)auStackY_98;
  iVar7 = *(int *)(param_1 + 0xb934);
  local_38 = uVar5;
LAB_14000e9d0:
  do {
    if (iVar7 == 0) break;
    if (iVar7 == 1) goto LAB_14000ebfc;
    if (iVar7 == 2) {
      uVar12 = *(ushort *)(param_1 + 0xb938);
      lVar9 = (ulonglong)uVar12 * 0x2c + *(longlong *)(param_1 + 0x5c0);
      bVar4 = *(byte *)(param_1 + 0xb93c) & 0xf;
      if (bVar4 == 0) {
LAB_14000eabd:
        uVar5 = *(ulonglong *)(param_1 + 0xb948);
        if (*(char *)(uVar5 + 8) == ']') {
          puVar1 = (uint *)(lVar9 + 0x14);
          *puVar1 = *puVar1 | 0x80000000;
          iVar7 = 3;
          *(undefined4 *)(param_1 + 0xb934) = 3;
          goto LAB_14000e9d0;
        }
      }
      else {
        if (bVar4 == 1) {
          uVar5 = (ulonglong)*(uint *)(param_1 + 0xb940) + *(longlong *)(param_1 + 0x108);
          uVar10 = *(ushort *)(uVar5 + 0xe) & 0x7fff;
          if (((uVar10 == 0) || (uVar10 == 0x45)) && (*(char *)(uVar5 + 0xc) == '\0'))
          goto LAB_14000eabd;
        }
        else {
          uVar5 = LogSystemEvent(param_1,0xad010074,0xc004af02,(byte *)"Log Sense has failed",
                                 param_4,param_5);
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x244) != 0)) {
            uVar5 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                                0x244,(undefined1 *)(lVar9 + 0x1a),2,param_4,param_5);
          }
        }
        uVar12 = *(ushort *)(param_1 + 0xb938);
      }
      *(ushort *)(param_1 + 0xb938) = uVar12 + 1;
      iVar7 = 1;
      *(undefined4 *)(param_1 + 0xb934) = 1;
      goto LAB_14000e9d0;
    }
    if (iVar7 != 3) {
      if (iVar7 != 4) goto LAB_14000ed18;
      uVar2 = *(undefined2 *)
               ((ulonglong)*(ushort *)(param_1 + 0xb938) * 0x2c + 0x1a +
               *(longlong *)(param_1 + 0x5c0));
      puVar3 = *(undefined8 **)(param_1 + 0x560);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      *(undefined2 *)puVar3 = uVar2;
      *(undefined1 *)((longlong)puVar3 + 3) = 0x18;
      *(undefined4 *)((longlong)puVar3 + 0xc) = 0x40;
      QueueRequestDescriptor
                (param_1,(uint)*(ushort *)(param_1 + 0x9b0) * 0x10000 + 8,0,param_4,param_5);
      *(short *)(param_1 + 0xb938) = *(short *)(param_1 + 0xb938) + 1;
      goto LAB_14000ebf2;
    }
    local_54 = *(undefined1 *)(*(longlong *)(param_1 + 0xb948) + 8);
    puVar11 = (undefined4 *)
              ((ulonglong)*(ushort *)(param_1 + 0xb938) * 0x2c + *(longlong *)(param_1 + 0x5c0));
    local_53 = *(undefined1 *)(*(longlong *)(param_1 + 0xb948) + 9);
    local_52 = *(undefined2 *)((longlong)puVar11 + 0x1a);
    local_4c = *puVar11;
    local_48 = puVar11[1];
    local_58 = 0xffff;
    local_56 = 5;
    uVar5 = SendMpiEventToApplication(param_1,0xf,&local_58,0x1c);
    iVar7 = 4;
    *(undefined4 *)(param_1 + 0xb934) = 4;
  } while( true );
  *(undefined2 *)(param_1 + 0xb938) = 0;
  *(undefined8 *)(param_1 + 0xb93c) = 0;
  *(undefined8 *)(param_1 + 0xb950) = 0;
LAB_14000ebf2:
  *(undefined4 *)(param_1 + 0xb934) = 1;
LAB_14000ebfc:
  uVar5 = (ulonglong)*(ushort *)(param_1 + 0xb938);
  uVar8 = *(uint *)(param_1 + 0x9bc);
  if (*(ushort *)(param_1 + 0xb938) < uVar8) {
    do {
      lVar9 = uVar5 * 0x2c + *(longlong *)(param_1 + 0x5c0);
      uVar12 = *(ushort *)(lVar9 + 0x1a);
      if ((((uVar12 != 0) && (iVar7 = *(int *)(lVar9 + 0x14), -1 < iVar7)) &&
          (bVar4 = (byte)iVar7, (char)bVar4 < '\0')) &&
         (((bVar4 & 7) == 1 &&
          (uVar6 = IssueLogSenseToSataDevice(param_1,uVar12,param_4,param_5), (char)uVar6 != '\0')))
         ) {
        *(short *)(param_1 + 0xb938) = (short)uVar5;
        *(undefined4 *)(param_1 + 0xb934) = 2;
        uVar8 = *(uint *)(param_1 + 0x9bc);
        break;
      }
      uVar8 = *(uint *)(param_1 + 0x9bc);
      uVar12 = (short)uVar5 + 1;
      uVar5 = (ulonglong)uVar12;
    } while (uVar12 < uVar8);
  }
  if (uVar8 <= (uint)uVar5) {
    *(undefined4 *)(param_1 + 0xb934) = 0;
    if (*(longlong *)(param_1 + 0xb950) != 0) {
      ReturnFreeTrackingArrayEntry(param_1,*(longlong *)(param_1 + 0xb950),param_4,param_5);
    }
    uVar5 = GtfStartTimer(param_1,1,300,DetectSataPfa,0,param_4,param_5);
    *(char *)(param_1 + 0xb933) = (char)uVar5;
    if ((((char)uVar5 == -2) && (*(char *)(param_1 + 0x608) != '\0')) &&
       ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
      uVar5 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                          (undefined1 *)0x0,0,param_4,param_5);
    }
  }
LAB_14000ed18:
  return uVar5 & 0xffffffffffffff00;
}



===== EnableDiagnosticRegister @ 14000ed50 =====

void EnableDiagnosticRegister(longlong param_1,byte param_2,int param_3)

{
  bool bVar1;
  byte bVar2;
  
  bVar1 = true;
  do {
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
    bVar2 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar2 = 2;
    }
    do {
      bVar2 = bVar2 + 1;
      if (**(int **)(param_1 + 0x28) != 0) break;
    } while (bVar2 < 3);
    if ((char)**(int **)(param_1 + 0x28) < '\0') {
      return;
    }
    LogSystemEvent(param_1,0xad010029,0xc004af02,
                   (byte *)"Write Sequence to enable Diag Register access failed",param_2,param_3);
    if (!bVar1) {
      return;
    }
    bVar1 = false;
  } while( true );
}



===== EnableDisableEvents @ 14000ee60 =====

ulonglong EnableDisableEvents(longlong param_1,char param_2,byte param_3,int param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  
  puVar1 = *(undefined8 **)(param_1 + 0x948);
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
  *(undefined1 *)(param_1 + 0x11b1) = 1;
  uVar2 = QueueRequestDescriptor
                    (param_1,(uint)*(ushort *)(param_1 + 0x9ae) * 0x10000 + 8,0,param_3,param_4);
  if (param_2 == '\0') {
LAB_14000ef3a:
    uVar3 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  else {
    uVar4 = 0;
    do {
      uVar2 = PollLSImpiIsr(param_1,param_3,param_4);
      if (*(char *)(param_1 + 0x11b1) == '\0') goto LAB_14000ef3a;
      StorPortStallExecution(500);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 10000);
    uVar3 = LogSystemEvent(param_1,0xad01003e,0xc004af02,(byte *)"No Event Enable Reply Received",
                           param_3,param_4);
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  return uVar3;
}



===== FwDiagPostImmediateBuffers @ 14000ef60 =====

ulonglong FwDiagPostImmediateBuffers(longlong param_1,byte param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ushort uVar5;
  byte bVar6;
  ulonglong uVar7;
  
  uVar4 = 0;
  uVar7 = 0;
  do {
    piVar1 = (int *)(param_1 + (uVar7 + 0xf4) * 0x18);
    if (((*(char *)(param_1 + 0x10 + (uVar7 + 0xf4) * 0x18) != '\0') &&
        (*(char *)((longlong)piVar1 + 0xf) != '\0')) && (*(char *)((longlong)piVar1 + 0x12) == '\0')
       ) {
      *(undefined1 *)(param_1 + 0x11db) = 1;
      uVar3 = PostFwDiagBuffer(param_1,piVar1,*(char *)(param_1 + 0xbbc6),param_2,param_3);
      if ((char)uVar3 == '\0') {
        uVar4 = uVar3 & 0xffffffffffffff00;
        break;
      }
      uVar5 = 0;
      do {
        cVar2 = PollLSImpiIsr(param_1,param_2,param_3);
        if (cVar2 == '\0') {
          StorPortStallExecution(500);
        }
        else if (*(char *)(param_1 + 0x11db) == '\0') {
          uVar4 = 1;
          break;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 4000);
    }
    bVar6 = (char)uVar7 + 1;
    uVar7 = (ulonglong)bVar6;
  } while (bVar6 < 3);
  *(undefined1 *)(param_1 + 0x11db) = 0;
  return uVar4;
}



===== GetCimData @ 14000f070 =====

void GetCimData(longlong param_1,longlong param_2,uint param_3)

{
  *(undefined4 *)(param_1 + 0x114c) = 0;
  *(uint *)(param_1 + 0x1150) = (uint)*(ushort *)(param_2 + 2);
  *(uint *)(param_1 + 0x1154) = (uint)*(byte *)(param_2 + 8);
  *(uint *)(param_1 + 0x1158) = (uint)*(ushort *)(param_2 + 0x2e);
  *(uint *)(param_1 + 0x115c) = (uint)*(ushort *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x1148) = 7;
  memmove((void *)(param_1 + 0x116c),&driver_version,0x14);
  *(uint *)(param_1 + 0x1194) = param_3 >> 0x10 & 0xff;
  *(uint *)(param_1 + 0x1190) = param_3 & 0xffff;
  if (*(int *)(param_1 + 0x115c) == 0x1014) {
    *(undefined1 *)(param_1 + 0x11b3) = 1;
  }
  return;
}



===== GetHostReqTag @ 14000f110 =====

ulonglong GetHostReqTag(longlong param_1,ushort *param_2)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  byte *pbVar4;
  byte bVar5;
  ushort uVar6;
  ulonglong uVar7;
  short local_res8;
  
  uVar7 = 0;
  do {
    while( true ) {
      uVar1 = *(uint *)(*(longlong *)(param_1 + 0xaa8) + uVar7 * 4);
      uVar3 = 0;
      if (uVar1 != 0) {
        for (; (uVar1 >> uVar3 & 1) == 0; uVar3 = uVar3 + 1) {
        }
      }
      if (uVar1 == 0) break;
      LOCK();
      pbVar4 = (byte *)(*(longlong *)(param_1 + 0xaa8) + uVar7 * 4 + ((longlong)(int)uVar3 >> 3));
      bVar5 = *pbVar4;
      *pbVar4 = *pbVar4 & ~('\x01' << (uVar3 & 7));
      UNLOCK();
      if ((bVar5 >> (uVar3 & 7) & 1) != 0) {
        local_res8 = (short)uVar3;
        uVar6 = (short)uVar7 * 0x20 + local_res8;
        *param_2 = uVar6;
        bVar2 = uVar6 <= *(ushort *)(param_1 + 0x998);
        if (!bVar2) {
          LOCK();
          pbVar4 = (byte *)(*(longlong *)(param_1 + 0xaa8) + (ulonglong)(uVar6 >> 5) * 4 +
                           ((longlong)(int)(uVar6 & 0x1f) >> 3));
          *pbVar4 = *pbVar4 | '\x01' << (uVar6 & 7);
          UNLOCK();
        }
        return (ulonglong)bVar2;
      }
    }
    uVar6 = (short)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while (uVar6 <= (ushort)((*(ushort *)(param_1 + 0x998) >> 5) + 1));
  return (ulonglong)(byte)(uVar6 >> 8) << 8;
}



===== HandleEventNotification @ 14000f1c0 =====

void HandleEventNotification(longlong param_1,uint *param_2,byte param_3,uint param_4)

{
  byte bVar1;
  ushort uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 uVar5;
  ushort uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined1 uVar9;
  ushort uVar10;
  char *pcVar11;
  char cVar12;
  ushort local_res10 [4];
  uint *puVar13;
  uint uVar14;
  undefined4 uVar15;
  uint local_38 [4];
  
  uVar2 = (ushort)param_2[5];
  puVar13 = (uint *)(ulonglong)param_4;
  local_res10[0] = 0;
  AfdMpiEventTrigger(param_1,uVar2,*(ushort *)((longlong)param_2 + 0x2a),param_3,param_4);
  if ((uVar2 == 0x21) && (*(char *)(param_1 + 0x18b1) != '\0')) {
    puVar13 = (uint *)&MegaSASWmiMpiEventGuid;
    ScsiPortWmiFireLogicalUnitEvent
              (param_1,-1,0,0,(int *)&MegaSASWmiMpiEventGuid,0,0x10,(int *)(param_1 + 0x1a0));
  }
  if ((ushort)*param_2 != 0) {
    puVar13 = (uint *)(ulonglong)param_3;
    SendMpiEventToApplication(param_1,(uint)uVar2,param_2 + 7,(uint)(ushort)*param_2 << 2);
  }
  switch(uVar2) {
  case 1:
    if ((short)*param_2 != 0) {
      puVar13 = (uint *)(ulonglong)param_3;
      LogSystemEvent(param_1,param_2[7],0x4004af00,(byte *)"Event Data logged",param_3,param_4);
    }
    break;
  case 5:
    *(undefined1 *)(param_1 + 0x118c) = 1;
    if (*(short *)(param_1 + 0x960) != 0) {
      puVar13 = (uint *)(ulonglong)param_3;
      LogSystemEvent(param_1,0xad01000e,0x4004af00,(byte *)"External Hard Reset Event Received",
                     param_3,param_4);
    }
    break;
  case 10:
    *(undefined1 *)(param_1 + 0x11b1) = 0;
    break;
  case 0xf:
    uVar14 = 0;
    uVar10 = *(ushort *)((longlong)param_2 + 0x22);
    if (*(uint *)(param_1 + 0x9bc) != 0) {
      lVar7 = *(longlong *)(param_1 + 0x5c0);
      do {
        lVar4 = (ulonglong)uVar14 * 0x2c;
        if (*(ushort *)(lVar4 + 0x1a + lVar7) == uVar10) {
          uVar5 = (undefined1)*(undefined2 *)(lVar4 + 0x1c + lVar7);
          uVar9 = (undefined1)*(undefined2 *)(lVar4 + 0x1e + lVar7);
          if (*(char *)((longlong)param_2 + 0x1e) == '\b') {
            if (*(int *)(param_1 + 0x970) == 0) {
              uVar15 = 1;
LAB_14000f45d:
              puVar13 = (uint *)(ulonglong)uVar10;
              PauseDevice(param_1,uVar5,uVar9,0,uVar10,300,uVar15,1,param_3,param_4);
            }
          }
          else if (*(char *)((longlong)param_2 + 0x1e) == '\x0e') {
            uVar15 = 1;
LAB_14000f499:
            puVar13 = (uint *)(ulonglong)uVar10;
            ResumeDevice(param_1,uVar5,uVar9,0,uVar10,uVar15,1,param_3,param_4);
          }
          break;
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < *(uint *)(param_1 + 0x9bc));
    }
    break;
  case 0x17:
    if ((*(char *)((longlong)param_2 + 0x1f) == '\x04') && (*(int *)(param_1 + 0x1218) == 0)) {
      if (*(char *)(param_1 + 0xbbd0) == '\0') {
        uVar10 = *(ushort *)(param_1 + 0x998);
        uVar6 = 1;
        if (uVar10 != 0) {
          do {
            if (*(longlong *)((ulonglong)uVar6 * 0x20 + 8 + *(longlong *)(param_1 + 0x598)) != 0) {
              if (uVar6 <= uVar10) goto LAB_14000f64d;
              break;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 <= uVar10);
        }
      }
      else if ((*(longlong *)(param_1 + 0x910) != *(longlong *)(param_1 + 0x918)) ||
              (*(longlong *)(**(longlong **)(param_1 + 0x910) + 8) != 0)) {
LAB_14000f64d:
        if ((*(char *)(param_1 + 0x18f4) == '\0') && (*(char *)(param_1 + 0x1220) == '\0')) {
          if (*(int *)(param_1 + 0x970) == 0) {
            PauseAdapterQueue(param_1,8,param_3,param_4);
          }
          ResetActive(param_1,0xe,param_3,param_4);
          *(undefined1 *)(param_1 + 0x18f4) = 1;
          *(undefined1 *)(param_1 + 0x18f8) = 1;
          SasBcAsyncEvent(param_1,param_3,param_4);
        }
        else {
          *(undefined1 *)(param_1 + 0x18f5) = 1;
        }
      }
    }
    break;
  case 0x1c:
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x100001) != 0)) {
      puVar13 = param_2;
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x100001,
                  (undefined1 *)param_2,(uint)*(byte *)((longlong)param_2 + 2) << 2,param_3,param_4)
      ;
    }
    ProcessSasTopologyChangeList(param_1,(ushort *)param_2,param_3,param_4);
    break;
  case 0x1d:
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x100000) != 0)) {
      puVar13 = param_2;
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x100000,
                  (undefined1 *)param_2,(uint)*(byte *)((longlong)param_2 + 2) << 2,param_3,param_4)
      ;
    }
    ProcessSasEnclosureStatusChange(param_1,(longlong)param_2,param_3,param_4);
    break;
  case 0x27:
    local_38[0] = ((ushort)param_2[8] | 0xf0000) << 8 | (uint)(byte)param_2[7];
    puVar13 = (uint *)(ulonglong)param_3;
    LogSystemEvent(param_1,local_38[0],0xc004af02,(byte *)"IOC temperature exceeded the threshold",
                   param_3,param_4);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x24a) != 0)) {
      uVar14 = 2;
      uVar15 = 0x24a;
      puVar13 = param_2 + 8;
LAB_14000f73b:
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar15,
                  (undefined1 *)puVar13,uVar14,param_3,param_4);
    }
    break;
  case 0x30:
    uVar14 = 0;
    uVar10 = *(ushort *)((longlong)param_2 + 0x22);
    if (*(uint *)(param_1 + 0x9bc) != 0) {
      lVar7 = *(longlong *)(param_1 + 0x5c0);
      do {
        lVar4 = (ulonglong)uVar14 * 0x2c;
        if (*(ushort *)(lVar4 + 0x1a + lVar7) == uVar10) {
          uVar5 = (undefined1)*(undefined2 *)(lVar4 + 0x1c + lVar7);
          uVar9 = (undefined1)*(undefined2 *)(lVar4 + 0x1e + lVar7);
          if (*(char *)((longlong)param_2 + 0x1e) == '\b') {
            if (*(int *)(param_1 + 0x970) == 0) {
              uVar15 = 3;
              goto LAB_14000f45d;
            }
          }
          else if (*(char *)((longlong)param_2 + 0x1e) == '\x0e') {
            uVar15 = 3;
            goto LAB_14000f499;
          }
          break;
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < *(uint *)(param_1 + 0x9bc));
    }
    break;
  case 0x32:
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x100002) != 0)) {
      puVar13 = param_2;
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x100002,
                  (undefined1 *)param_2,(uint)*(byte *)((longlong)param_2 + 2) << 2,param_3,param_4)
      ;
    }
    ProcessPcieTopologyChangeList(param_1,(ushort *)param_2,param_3,param_4);
    break;
  case 0x34:
    if ((char)param_2[8] == '\0') {
      local_38[0] = (param_2[7] & 0xffff | 0xe0000) << 8 | (uint)*(byte *)((longlong)param_2 + 0x21)
      ;
      puVar13 = (uint *)(ulonglong)param_3;
      LogSystemEvent(param_1,local_38[0],0xc004af02,(byte *)"Insufficient Power for active cable",
                     param_3,param_4);
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x24b) != 0)) {
        uVar14 = 4;
        uVar15 = 0x24b;
        puVar13 = param_2 + 7;
        goto LAB_14000f73b;
      }
    }
    else if (((char)param_2[8] == '\x02') &&
            ((local_38[0] = 0xe000002, *(short *)(param_1 + 0x960) != 0 ||
             (uVar10 = *(ushort *)(param_1 + 0x962), *(ushort *)(param_1 + 0x962) = uVar10 + 1,
             uVar10 < 0x14)))) {
      puVar13 = (uint *)(ulonglong)param_3;
      LogSystemEvent(param_1,0xe000002,0xc004af02,
                     (byte *)"an active cable is present but is running at a degraded speed",param_3
                     ,param_4);
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x253) != 0)) {
        uVar14 = 1;
        uVar15 = 0x253;
        puVar13 = param_2 + 8;
        goto LAB_14000f73b;
      }
    }
    break;
  case 0x35:
    local_38[0] = ((ushort)param_2[7] | 0xd0000) << 8 | (uint)*(byte *)((longlong)param_2 + 0x1e);
    puVar13 = (uint *)(ulonglong)param_3;
    LogSystemEvent(param_1,local_38[0],0x8004af01,
                   (byte *)"SMP command sent to the expander by FW failed/timed out",param_3,param_4
                  );
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x26f) != 0)) {
      puVar13 = local_38;
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x26f,
                  (undefined1 *)puVar13,4,param_3,param_4);
    }
  }
  if (*(char *)((longlong)param_2 + 6) == '\0') {
    return;
  }
  if (*(char *)(param_1 + 0x11d7) == '\0') {
    bVar1 = *(byte *)(param_1 + 0x10f6);
    lVar7 = param_1 + (ulonglong)bVar1 * 8;
    if (*(short *)(lVar7 + 0x10f8) == 0) {
      *(ushort *)(lVar7 + 0x10f8) = uVar2;
      *(uint *)(lVar7 + 0x10fc) = param_2[6];
      cVar12 = '\0';
      if (bVar1 != 9) {
        cVar12 = bVar1 + 1;
      }
      *(uint *)(param_1 + 0x9c0) = *(uint *)(param_1 + 0x9c0) | 2;
      *(char *)(param_1 + 0x10f6) = cVar12;
      if (*(char *)(param_1 + 0x1211) == '\0') {
        StorPortNotification(6,param_1,WatchdogTimer,10000,puVar13);
        return;
      }
      return;
    }
    uVar15 = 0xad01003c;
    pcVar11 = "queue to issue Event Ack message is full";
  }
  else if (*(char *)(param_1 + 0xbbd0) == '\0') {
    uVar3 = GetHostReqTag(param_1,local_res10);
    if ((char)uVar3 != '\0') {
      lVar7 = (ulonglong)local_res10[0] * 0x20 + *(longlong *)(param_1 + 0x598);
LAB_14000f9d0:
      uVar10 = *(ushort *)(lVar7 + 0x10);
      *(undefined8 *)(lVar7 + 8) = 0xdeadbeef;
      *(undefined1 *)(lVar7 + 0x13) = 2;
      puVar8 = (undefined8 *)
               ((longlong)(int)((uint)*(ushort *)(param_1 + 0x534) * (uint)uVar10) +
               *(longlong *)(param_1 + 0x558));
      *puVar8 = 0;
      puVar8[1] = 0;
      *(undefined4 *)(puVar8 + 2) = 0;
      *(undefined1 *)((longlong)puVar8 + 3) = 8;
      *(ushort *)((longlong)puVar8 + 0xc) = uVar2;
      *(uint *)(puVar8 + 2) = param_2[6];
      QueueRequestDescriptor(param_1,(uint)uVar10 * 0x10000 + 8,0,param_3,param_4);
      return;
    }
    uVar15 = 0xad01003b;
    pcVar11 = "need to send an Event Ack for an Event, but FW Credits are exhausted";
  }
  else {
    lVar7 = **(longlong **)(param_1 + 0x910);
    if (*(longlong *)(lVar7 + 8) == 0) {
      lVar4 = *(longlong *)(param_1 + 0x910) + 8;
      *(longlong *)(param_1 + 0x910) = lVar4;
      if (lVar4 == *(longlong *)(param_1 + 0x920)) {
        *(undefined8 *)(param_1 + 0x910) = *(undefined8 *)(param_1 + 0x908);
      }
      goto LAB_14000f9d0;
    }
    uVar15 = 0xad01003b;
    pcVar11 = "need to send an Event Ack for an Event, but FW Credits are exhausted";
  }
  LogSystemEvent(param_1,uVar15,0x8004af01,(byte *)pcVar11,param_3,param_4);
  *(undefined4 *)(param_1 + 0x1218) = 1;
  if (*(int *)(param_1 + 0x970) == 0) {
    PauseAdapterQueue(param_1,9,param_3,param_4);
  }
  *(undefined2 *)(param_1 + 0x1214) = 0;
  LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                      "Diag Reset(miniport)-Event acknowledgment failed from FW",param_3,param_4);
  KickStart(param_1,param_3,param_4);
  return;
}



===== HandleFWDowngrade @ 14000fbb0 =====

ulonglong HandleFWDowngrade(longlong param_1,char param_2,byte param_3,int param_4)

{
  ushort uVar1;
  undefined8 in_RAX;
  ulonglong uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined1 local_res8 [8];
  
  if (param_2 == '\0') {
    iVar4 = *(int *)(param_1 + 0xb674);
  }
  else {
    iVar4 = 1;
    *(undefined4 *)(param_1 + 0xb674) = 1;
  }
  if (iVar4 == 1) {
    *(undefined1 *)(param_1 + 0xb670) = 1;
    *(undefined4 *)(param_1 + 0xb674) = 2;
  }
  else if (iVar4 != 2) {
    if (iVar4 == 3) {
      if (*(short *)(param_1 + 0x185a) == 0) {
        *(undefined2 *)(param_1 + 0xb678) = *(undefined2 *)(param_1 + 0x190c);
        *(undefined1 *)(param_1 + 0x9ba) = 0;
        *(ushort *)(param_1 + 0x190c) = (ushort)(*(ushort *)(param_1 + 0x18bc) * 0x14 + 8) >> 2;
        uVar3 = SendExtendedConfigPageMessage
                          (param_1,'\x06',(char *)(param_1 + 0x1908),
                           (uint)*(ushort *)(param_1 + 0x18bc) << 0x10,
                           (int)*(undefined8 *)(param_1 + 0x1910),param_3,param_4);
        *(undefined4 *)(param_1 + 0xb674) = 4;
        return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
      }
      uVar3 = LogSystemEvent(param_1,0xad010047,0xc004af02,
                             (byte *)"Read of DPM0 header returned an error (HandleFWDowngrade)",
                             param_3,param_4);
      *(undefined1 *)(param_1 + 0xb670) = 0;
      *(undefined4 *)(param_1 + 0xb674) = 0;
      return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
    if (iVar4 == 4) {
      if (*(short *)(param_1 + 0x185a) == 0) {
        *(short *)(param_1 + 0x190c) = *(short *)(param_1 + 0xb678) + 5;
        *(undefined4 *)(param_1 + 0xb674) = 5;
        goto LAB_14000fc4c;
      }
      in_RAX = LogSystemEvent(param_1,0xad010047,0xc004af02,
                              (byte *)"Read of DPM0 returned an error (HandleFWDowngrade)",param_3,
                              param_4);
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x23e) != 0)) {
        in_RAX = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x23e
                             ,(undefined1 *)(param_1 + 0x185a),2,param_3,param_4);
      }
      *(undefined1 *)(param_1 + 0xb670) = 0;
      *(undefined4 *)(param_1 + 0xb674) = 0;
    }
    else if (iVar4 == 5) {
LAB_14000fc4c:
      uVar2 = SendIOCTLMessage(param_1,*(ushort **)(param_1 + 0xb680),*(void **)(param_1 + 0xb688),
                               param_3,param_4);
      *(undefined1 *)(param_1 + 0xb690) = 0;
      *(undefined4 *)(param_1 + 0xb674) = 0;
      return uVar2;
    }
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  if ((((local_res8 == (undefined1 *)(param_1 + 0x1920)) ||
       (local_res8 == (undefined1 *)(param_1 + 0x1940))) ||
      (local_res8 == (undefined1 *)(param_1 + 0x1950))) ||
     ((local_res8 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01')))) {
    puVar5 = *(undefined8 **)(param_1 + 0x570);
    uVar1 = *(ushort *)(param_1 + 0x9b4);
    iVar4 = *(int *)(param_1 + 0x20c);
  }
  else {
    puVar5 = *(undefined8 **)(param_1 + 0x560);
    uVar1 = *(ushort *)(param_1 + 0x9b0);
    iVar4 = *(int *)(param_1 + 0x204);
  }
  *(undefined1 *)(param_1 + 0x9ba) = 0;
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = 0;
  puVar5[3] = 0;
  puVar5[4] = 0;
  *(undefined4 *)(puVar5 + 5) = 0;
  *(undefined4 *)(puVar5 + 3) = 0;
  *(undefined1 *)((longlong)puVar5 + 3) = 4;
  *(undefined1 *)((longlong)puVar5 + 0x17) = 0xf;
  *(undefined1 *)((longlong)puVar5 + 6) = 0x17;
  *(undefined4 *)((longlong)puVar5 + 0x1c) = 0xd3000000;
  *(int *)(puVar5 + 4) = iVar4 + 0x2c;
  *(undefined4 *)((longlong)puVar5 + 0x24) = *(undefined4 *)(param_1 + 500);
  uVar3 = QueueRequestDescriptor(param_1,(uint)uVar1 * 0x10000 + 8,0,param_3,param_4);
  *(undefined4 *)(param_1 + 0xb674) = 3;
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== HandleIoctlTimeout @ 14000fed0 =====

undefined8 HandleIoctlTimeout(longlong param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  int local_res8 [2];
  
  iVar2 = *param_2;
  bVar1 = *(byte *)(param_2 + 1);
  psVar3 = *(short **)(param_1 + 0x1270);
  local_res8[0] = 0;
  if (((*(char *)((longlong)psVar3 + 3) != '\0') || (*(int *)(param_1 + 0x968) != 0)) ||
     (*(char *)(param_1 + 0x1211) != '\0')) {
    puVar5 = *(undefined8 **)(param_1 + 0x948);
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    *(undefined4 *)(puVar5 + 5) = 0;
    *(undefined1 *)((longlong)puVar5 + 3) = 7;
    *(undefined8 *)((longlong)puVar5 + 0x14) = 0xffffffffffffffff;
    *(undefined8 *)((longlong)puVar5 + 0x1c) = 0xffffffffffffffff;
    *(undefined1 *)(param_1 + 0x11b1) = 1;
    QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x9ae) * 0x10000 + 8,0,bVar1,iVar2);
    ResetActive(param_1,2,bVar1,iVar2);
    uVar8 = GtfStartTimer(param_1,1,3,DelayedIoctlTimeout,0,bVar1,iVar2);
    if ((char)uVar8 == -2) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                    (undefined1 *)0x0,0,bVar1,iVar2);
      }
      LogSystemEvent(param_1,0xad01007c,0x8004af01,
                     (byte *)"No Timer available for DelayedIoctlTimeout",bVar1,iVar2);
      uVar8 = DelayedIoctlTimeout(param_1,0,0,bVar1,iVar2);
    }
    return CONCAT71((int7)(uVar8 >> 8),1);
  }
  psVar4 = *(short **)(param_1 + 0x568);
  psVar4[0] = 0;
  psVar4[1] = 0;
  psVar4[2] = 0;
  psVar4[3] = 0;
  psVar4[4] = 0;
  psVar4[5] = 0;
  psVar4[6] = 0;
  psVar4[7] = 0;
  psVar4[8] = 0;
  psVar4[9] = 0;
  psVar4[10] = 0;
  psVar4[0xb] = 0;
  psVar4[0xc] = 0;
  psVar4[0xd] = 0;
  psVar4[0xe] = 0;
  psVar4[0xf] = 0;
  psVar4[0x10] = 0;
  psVar4[0x11] = 0;
  psVar4[0x12] = 0;
  psVar4[0x13] = 0;
  psVar4[0x14] = 0;
  psVar4[0x15] = 0;
  psVar4[0x16] = 0;
  psVar4[0x17] = 0;
  psVar4[0x18] = 0;
  psVar4[0x19] = 0;
  *psVar4 = *psVar3;
  *(undefined1 *)((longlong)psVar4 + 3) = 1;
  *(undefined1 *)((longlong)psVar4 + 5) = 3;
  uVar6 = GetMapTableIndexFromHandle(param_1,*psVar3);
  if (uVar6 != 0xffffffff) {
    lVar10 = (ulonglong)uVar6 * 0x2c;
    lVar9 = *(longlong *)(param_1 + 0x5c0);
    if (((*(char *)(lVar9 + 0x24 + lVar10) != '\0') && (*(char *)(param_1 + 0x18b0) == '\0')) &&
       ((*(uint *)(lVar9 + 0x14 + lVar10) & 4) == 0)) {
      *(undefined1 *)((longlong)psVar4 + 7) = 0x18;
      lVar9 = *(longlong *)(param_1 + 0x5c0);
    }
    local_res8[0] =
         CONCAT22(*(undefined2 *)(lVar10 + 0x1c + lVar9),*(undefined2 *)(lVar10 + 0x1e + lVar9));
    LogOperationalEvent(param_1,local_res8,4,0x4004af00,
                        "Target reset issued to clean a stuck IO msg Ioctl(Bus&Target ID logged)",
                        bVar1,iVar2);
  }
  ResetActive(param_1,1,bVar1,iVar2);
  QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x9b2) * 0x10000 + 6,0,bVar1,iVar2);
  AfdMasterTrigger(param_1,4,bVar1,iVar2);
  *(undefined4 *)(param_1 + 0x974) = 0xf;
  *(undefined1 *)(param_1 + 0x1211) = 0;
  uVar7 = StorPortNotification(6,param_1,WatchdogTimer,1000000);
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
}



===== HandleRttIoctl @ 140010190 =====

undefined8 HandleRttIoctl(longlong param_1,longlong param_2,undefined1 *param_3,int param_4)

{
  uint uVar1;
  uint7 uVar4;
  void *pvVar2;
  undefined8 uVar3;
  uint uVar5;
  ulonglong uVar6;
  int iVar7;
  int *_Src;
  undefined4 uVar8;
  void *_Dst;
  undefined4 local_res10;
  undefined4 local_res14;
  
  *param_3 = 1;
  *(undefined4 *)(param_2 + 0x14) = 0;
  uVar8 = RttraceRecordVersion;
  *(undefined4 *)(param_2 + 0x1c) = RttraceRecordVersion;
  iVar7 = *(int *)(param_2 + 0x20);
  uVar4 = (uint7)(uint3)((uint)uVar8 >> 8);
  if (iVar7 == 1) {
    if (*(uint *)(param_2 + 0x18) < 0x48) {
      *(undefined4 *)(param_2 + 0x14) = 2;
      *(undefined4 *)(param_2 + 0x28) = 2;
      return (ulonglong)uVar4 << 8;
    }
    *(undefined1 *)(param_2 + 0x3c) = *(undefined1 *)(param_1 + 0x608);
    *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 0x60c);
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_1 + 0x604);
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0x600);
    *(undefined4 *)(param_2 + 0x60) = 0x603cbea7;
    memmove((void *)(param_2 + 0x3d),&s_2_61_29_80,0x10);
    uVar3 = HexVersionToString(*(uint *)(param_1 + 0x1164),(char *)(param_2 + 0x4d));
    *(undefined4 *)(param_2 + 0x2c) = 0x7f;
    *(undefined4 *)(param_2 + 0x28) = 0;
    return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  if (iVar7 == 2) {
    if (*(uint *)(param_2 + 0x18) < 0x48) {
      *(undefined4 *)(param_2 + 0x14) = 2;
      *(undefined4 *)(param_2 + 0x28) = 2;
      return (ulonglong)uVar4 << 8;
    }
    uVar5 = *(uint *)(param_2 + 0x2c);
    if ((uVar5 & 4) != 0) {
      if ((*(uint *)(param_2 + 0x24) & 4) == 0) {
        uVar5 = uVar5 & 0xfffffffb;
        *(uint *)(param_2 + 0x2c) = uVar5;
      }
      else {
        if (*(char *)(param_1 + 0x11d7) == '\0') {
          AcquireIsrLocks(param_1,0,param_4);
          RttFormatBuffer((undefined8 *)(param_1 + 0x5d8),param_4);
          ReleaseIsrLocks(param_1,0,param_4);
        }
        else {
          RttFormatBuffer((undefined8 *)(param_1 + 0x5d8),param_4);
        }
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x121,
                    (undefined1 *)0x0,0,0,param_4);
        uVar5 = *(uint *)(param_2 + 0x2c);
      }
    }
    if ((uVar5 & 1) != 0) {
      if (*(char *)(param_1 + 0x11d7) == '\0') {
        AcquireIsrLocks(param_1,0,param_4);
        *(undefined1 *)(param_1 + 0x608) = *(undefined1 *)(param_2 + 0x3c);
        ReleaseIsrLocks(param_1,0,param_4);
      }
      else {
        *(undefined1 *)(param_1 + 0x608) = *(undefined1 *)(param_2 + 0x3c);
      }
      if ((*(uint *)(param_2 + 0x24) & 4) != 0) {
        uVar8 = 0x120;
        if (*(char *)(param_2 + 0x3c) == '\0') {
          uVar8 = 0x11f;
        }
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar8,
                    (undefined1 *)0x0,0,0,param_4);
      }
    }
    pvVar2 = (void *)(ulonglong)*(uint *)(param_2 + 0x2c);
    if ((*(uint *)(param_2 + 0x2c) & 2) != 0) {
      local_res10 = *(undefined4 *)(param_1 + 0x60c);
      local_res14 = *(undefined4 *)(param_2 + 0x38);
      if (*(char *)(param_1 + 0x11d7) == '\0') {
        AcquireIsrLocks(param_1,0,param_4);
        *(undefined4 *)(param_1 + 0x60c) = *(undefined4 *)(param_2 + 0x38);
        ReleaseIsrLocks(param_1,0,param_4);
      }
      else {
        *(undefined4 *)(param_1 + 0x60c) = local_res14;
      }
      pvVar2 = (void *)(ulonglong)*(uint *)(param_2 + 0x24);
      if ((*(uint *)(param_2 + 0x24) & 4) != 0) {
        pvVar2 = (void *)RttLogEvent(param_1,(char *)(param_1 + 0x11d7),
                                     (ulonglong *)(param_1 + 0x5d8),0x122,(undefined1 *)&local_res10
                                     ,8,0,param_4);
      }
    }
  }
  else {
    if (iVar7 != 3) {
      *(undefined4 *)(param_2 + 0x14) = 1;
      return (ulonglong)uVar4 << 8;
    }
    uVar6 = (ulonglong)*(uint *)(param_2 + 0x2c);
    if ((ulonglong)*(uint *)(param_2 + 0x18) < uVar6 + 0x14) {
      *(undefined4 *)(param_2 + 0x14) = 3;
      *(undefined4 *)(param_2 + 0x28) = 2;
      return (ulonglong)(uint3)(*(uint *)(param_2 + 0x18) >> 8) << 8;
    }
    if ((*(uint *)(param_2 + 0x24) & 1) == 0) {
      _Src = *(int **)(param_1 + 0x5f8);
    }
    else {
      _Src = *(int **)(param_1 + 0x5e8);
      *(int **)(param_1 + 0x5f8) = _Src;
      uVar6 = (ulonglong)*(uint *)(param_2 + 0x2c);
    }
    _Dst = (void *)(param_2 + 0x30);
    iVar7 = 0;
    uVar5 = (uint)uVar6;
    if ((uint)_Src[1] < uVar5) {
      do {
        uVar5 = (uint)uVar6;
        if (*_Src == 0) break;
        if (*_Src == 1) {
          _Src = *(int **)(param_1 + 0x5d8);
        }
        else {
          iVar7 = iVar7 + _Src[1];
          memmove(_Dst,_Src,(ulonglong)(uint)_Src[1]);
          _Dst = (void *)((longlong)_Dst + (ulonglong)(uint)_Src[1]);
          _Src = (int *)((longlong)_Src + (ulonglong)(uint)_Src[1]);
        }
        uVar5 = *(uint *)(param_2 + 0x2c);
        uVar6 = (ulonglong)uVar5;
      } while ((uint)_Src[1] < uVar5 - iVar7);
    }
    uVar1 = _Src[1];
    pvVar2 = (void *)(ulonglong)uVar1;
    if ((uVar1 < uVar5 - iVar7) && (*_Src == 0)) {
      iVar7 = iVar7 + uVar1;
      pvVar2 = memmove(_Dst,_Src,(ulonglong)uVar1);
      *(undefined4 *)(param_2 + 0x24) = 2;
      *(undefined8 *)(param_1 + 0x5f8) = 0;
    }
    else {
      *(int **)(param_1 + 0x5f8) = _Src;
      *(undefined4 *)(param_2 + 0x24) = 0;
    }
    *(int *)(param_2 + 0x2c) = iVar7;
  }
  *(undefined4 *)(param_2 + 0x28) = 0;
  return CONCAT71((int7)((ulonglong)pvVar2 >> 8),1);
}



===== HandleUnitAttenReset @ 140010530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
HandleUnitAttenReset
          (longlong param_1,ushort param_2,undefined8 *param_3,byte param_4,byte param_5,
          char param_6,char param_7,byte param_8,int param_9)

{
  uint *puVar1;
  char *pcVar2;
  longlong *plVar3;
  int *piVar4;
  undefined2 uVar5;
  longlong lVar6;
  bool bVar7;
  bool bVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  byte bVar13;
  ushort uVar14;
  longlong lVar15;
  undefined1 auStackY_b8 [32];
  byte local_58;
  byte local_57;
  char local_56;
  ushort local_54;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar11 = (ulonglong)param_2;
  bVar8 = false;
  local_57 = param_5;
  local_56 = param_6;
  local_58 = param_4;
  local_54 = param_2;
  lVar9 = StorPortGetLogicalUnit(param_1,param_4,param_5);
  if (lVar9 == 0) {
    LogSystemEvent(param_1,0xad010057,0xc004af02,
                   (byte *)"call to get LU Extension failed in UAR state machine",param_8,param_9);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x232) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x232,&local_58,
                  6,param_8,param_9);
    }
  }
  else {
    puVar1 = (uint *)(lVar9 + 0x20);
    if ((param_7 == '\0') || (*puVar1 == 0)) {
LAB_140010690:
      if (9 < *puVar1) {
        *puVar1 = 0;
        return 1;
      }
      switch(*puVar1) {
      case 0:
        if (param_7 == '\0') {
          return 1;
        }
        lVar15 = *(longlong *)(param_1 + 0x928);
        if ((((lVar15 != 0) &&
             (*(longlong *)(uVar11 * 0x20 + 8 + *(longlong *)(param_1 + 0x598)) != lVar15)) &&
            (lVar15 = *(longlong *)(lVar15 + 0x68), *(byte *)(lVar15 + 0x62) == param_4)) &&
           ((*(byte *)(lVar15 + 99) == param_5 && (*(char *)(lVar15 + 100) == param_6)))) {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2001f) != 0))
          {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2001f,
                        &local_58,6,param_8,param_9);
          }
          return 0;
        }
        *(byte *)(lVar9 + 0x25) = param_4;
        *(byte *)(lVar9 + 0x26) = param_5;
        *(char *)(lVar9 + 0x27) = param_6;
        *(ushort *)(lVar9 + 0x2a) = param_2;
        *puVar1 = 1;
        goto LAB_140010690;
      case 1:
        *(int *)(param_1 + 0x1288) = *(int *)(param_1 + 0x1288) + 1;
        uVar5 = *(undefined2 *)
                 ((ulonglong)(ushort)((ushort)param_4 * 0x80 + (ushort)param_5) * 0x2c + 0x1a +
                 *(longlong *)(param_1 + 0x5c0));
        *(undefined2 *)(lVar9 + 0x28) = uVar5;
        PauseDevice(param_1,param_4,param_5,param_6,uVar5,300,2,2,param_8,param_9);
        ResetActive(param_1,*(uint *)(param_1 + 0x968) | 0x80000000,param_8,param_9);
        *puVar1 = 2;
        goto LAB_140010690;
      case 2:
        *param_3 = 0;
        param_3[1] = 0;
        param_3[2] = 0;
        param_3[3] = 0;
        param_3[4] = 0;
        param_3[5] = 0;
        *(undefined4 *)(param_3 + 6) = 0;
        *(undefined2 *)param_3 = *(undefined2 *)(lVar9 + 0x28);
        *(undefined1 *)((longlong)param_3 + 3) = 1;
        *(undefined1 *)((longlong)param_3 + 5) = 2;
        *(char *)((longlong)param_3 + 0xd) = param_6;
        lVar15 = (ulonglong)(ushort)((ushort)param_4 * 0x80 + (ushort)param_5) * 0x2c;
        if (((*(char *)(*(longlong *)(param_1 + 0x5c0) + 0x24 + lVar15) == '\0') ||
            (*(char *)(param_1 + 0x18b0) != '\0')) ||
           ((*(uint *)(*(longlong *)(param_1 + 0x5c0) + 0x14 + lVar15) & 4) != 0)) {
          bVar13 = 8;
        }
        else {
          *(undefined1 *)((longlong)param_3 + 7) = 0x18;
          bVar13 = *(byte *)(*(longlong *)(param_1 + 0x5c0) + 0x27 + lVar15);
        }
        *(undefined4 *)(uVar11 * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0x80;
        QueueRequestDescriptor(param_1,(uint)param_2 * 0x10000 + 6,0,param_8,param_9);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20016) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20016,
                      &local_58,6,param_8,param_9);
        }
        uVar11 = GtfStartTimer(param_1,1,(ushort)bVar13,UarStuckAtsTimerCallback,puVar1,param_8,
                               param_9);
        *(char *)(lVar9 + 0x2c) = (char)uVar11;
        if ((char)uVar11 == -2) {
          if (*(short *)(param_1 + 0x960) != 0) {
            LogSystemEvent(param_1,0xad01007d,0x8004af01,
                           (byte *)"No timer available to time ATS in UAR state machine",param_8,
                           param_9);
          }
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                        (undefined1 *)0x0,0,param_8,param_9);
          }
        }
        *puVar1 = 4;
        break;
      case 3:
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x252) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x252,
                      (undefined1 *)0x0,0,param_8,param_9);
        }
        ResumeDevice(param_1,param_4,param_5,param_6,*(undefined2 *)(lVar9 + 0x28),2,2,param_8,
                     param_9);
        lVar15 = uVar11 * 0x20 + *(longlong *)(param_1 + 0x598);
        *(undefined2 *)(lVar9 + 0x28) = 0;
        piVar4 = (int *)(param_1 + 0x1288);
        *piVar4 = *piVar4 + -1;
        if (*piVar4 == 0) {
          ResetActive(param_1,*(uint *)(param_1 + 0x968) & 0x7fffffff,param_8,param_9);
        }
        lVar9 = *(longlong *)(param_1 + 0x928);
        plVar3 = (longlong *)(lVar15 + 8);
        if ((lVar9 == 0) || (lVar9 == *plVar3)) {
          if (lVar9 == *plVar3) {
            bVar8 = true;
            if (lVar9 != 0) {
              *(undefined1 *)(lVar9 + 3) = 4;
            }
            StorPortNotification(0,param_1);
            if ((*(char *)(param_1 + 0x608) != '\0') &&
               ((*(uint *)(param_1 + 0x60c) & 0x20010) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20010,
                          &local_58,6,param_8,param_9);
            }
          }
          *(undefined8 *)(param_1 + 0x928) = 0;
          uVar12 = CheckResetQueue(param_1,param_8,param_9);
          if (((char)uVar12 == '\0') && (ResetActive(param_1,0x40000008,param_8,param_9), bVar8)) {
            ResumeAdapterQueue(param_1,0xb,param_8,param_9);
          }
        }
        if ((param_2 == 0) || (*(ushort *)(param_1 + 0x998) < param_2)) {
          DetectLostSrb(param_1,lVar15,param_8,param_9);
          *plVar3 = 0;
        }
        else {
          if ((*(char *)(param_1 + 0xba00) != '\0') &&
             (lVar9 = (ulonglong)(ushort)((ushort)param_4 * 0x80 + (ushort)param_5) * 4,
             0 < *(int *)(*(longlong *)(param_1 + 0xba30) + lVar9))) {
            LOCK();
            piVar4 = (int *)(*(longlong *)(param_1 + 0xba30) + lVar9);
            *piVar4 = *piVar4 + -1;
            UNLOCK();
          }
          StorPortNotification(0,param_1,*plVar3);
          *(byte *)(lVar15 + 0x13) = *(byte *)(lVar15 + 0x13) | 1;
          ReturnFreeTrackingArrayEntry(param_1,lVar15,param_8,param_9);
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20018) != 0))
          {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20018,
                        &local_58,6,param_8,param_9);
          }
        }
        if (*(char *)(param_1 + 0x1220) == '\0') {
          CheckIoctlQueue(param_1,param_8,param_9);
        }
        *puVar1 = 0;
        break;
      case 4:
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20017) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20017,
                      &local_58,6,param_8,param_9);
        }
        uVar10 = GtfStopTimer(param_1,*(byte *)(lVar9 + 0x2c),param_8,param_9);
        if ((((char)uVar10 == '\0') && (*(char *)(param_1 + 0x608) != '\0')) &&
           ((*(uint *)(param_1 + 0x60c) & 0x251) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x251,
                      (undefined1 *)0x0,0,param_8,param_9);
        }
        *(undefined4 *)(uVar11 * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0;
        if (*(short *)((longlong)param_3 + 0xe) != 0) {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x235) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x235,
                        &local_58,6,param_8,param_9);
          }
          LogSystemEvent(param_1,0xad010059,0x8004af01,
                         (byte *)"NO ATS TM reply in UAR state machine",param_8,param_9);
        }
        *(undefined1 *)(lVar9 + 0x24) = 5;
        *puVar1 = 5;
        goto LAB_140010690;
      case 5:
        bVar7 = false;
        uVar10 = 1;
        if (*(short *)(param_1 + 0x998) != 0) {
          do {
            lVar15 = uVar10 * 0x20 + *(longlong *)(param_1 + 0x598);
            if ((((*(longlong *)(lVar15 + 8) != 0) &&
                 (*(short *)(lVar9 + 0x28) == *(short *)(lVar15 + 0x14))) &&
                (param_6 == *(char *)(lVar15 + 0x16))) && ((ushort)uVar10 != param_2)) {
              pcVar2 = (char *)(lVar9 + 0x24);
              *pcVar2 = *pcVar2 + -1;
              bVar7 = true;
              if (*pcVar2 == '\0') {
                *puVar1 = 9;
                if ((*(char *)(param_1 + 0x608) != '\0') &&
                   ((*(uint *)(param_1 + 0x60c) & 0x236) != 0)) {
                  RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                              0x236,&local_58,6,param_8,param_9);
                }
              }
              else {
                *puVar1 = 6;
              }
            }
            uVar14 = (ushort)uVar10 + 1;
            uVar10 = (ulonglong)uVar14;
          } while (uVar14 <= *(ushort *)(param_1 + 0x998));
          if (bVar7) goto LAB_140010690;
        }
        *puVar1 = 8;
        goto LAB_140010690;
      case 6:
        goto switchD_1400106a7_caseD_6;
      case 7:
        *puVar1 = 5;
        goto LAB_140010690;
      case 8:
        ResumeDevice(param_1,param_4,param_5,param_6,*(undefined2 *)(lVar9 + 0x28),2,2,param_8,
                     param_9);
        lVar15 = uVar11 * 0x20 + *(longlong *)(param_1 + 0x598);
        StorPortNotification(0,param_1,*(undefined8 *)(lVar15 + 8));
        *(byte *)(lVar15 + 0x13) = *(byte *)(lVar15 + 0x13) | 1;
        if (*(char *)(param_1 + 0xba00) != '\0') {
          if (*(longlong *)(param_1 + 0x928) == *(longlong *)(lVar15 + 8)) {
            bVar8 = true;
            goto LAB_140011010;
          }
          lVar6 = (ulonglong)(ushort)((ushort)param_4 * 0x80 + (ushort)param_5) * 4;
          if (0 < *(int *)(*(longlong *)(param_1 + 0xba30) + lVar6)) {
            LOCK();
            piVar4 = (int *)(*(longlong *)(param_1 + 0xba30) + lVar6);
            *piVar4 = *piVar4 + -1;
            UNLOCK();
          }
        }
        bVar8 = false;
LAB_140011010:
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20018) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20018,
                      &local_58,6,param_8,param_9);
        }
        *(undefined2 *)(lVar9 + 0x28) = 0;
        piVar4 = (int *)(param_1 + 0x1288);
        *piVar4 = *piVar4 + -1;
        if (*piVar4 == 0) {
          ResetActive(param_1,*(uint *)(param_1 + 0x968) & 0x7fffffff,param_8,param_9);
        }
        lVar9 = *(longlong *)(param_1 + 0x928);
        if ((lVar9 == 0) || (lVar9 == *(longlong *)(lVar15 + 8))) {
          lVar6 = *(longlong *)(lVar15 + 8);
          *(undefined8 *)(param_1 + 0x928) = 0;
          if (lVar9 == lVar6) {
            bVar8 = true;
          }
          uVar12 = CheckResetQueue(param_1,param_8,param_9);
          if (((char)uVar12 == '\0') && (ResetActive(param_1,0x40000008,param_8,param_9), bVar8)) {
            ResumeAdapterQueue(param_1,7,param_8,param_9);
          }
        }
        DetectLostSrb(param_1,lVar15,param_8,param_9);
        *(undefined8 *)(lVar15 + 8) = 0;
        if (*(char *)(param_1 + 0x1220) == '\0') {
          CheckIoctlQueue(param_1,param_8,param_9);
        }
        *puVar1 = 0;
        return 0;
      case 9:
        LogSystemEvent(param_1,0xad010035,0xc004af02,
                       (byte *)"IOs still active on bus when TM reply was received(UAR)",param_8,
                       param_9);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20019) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20019,
                      &local_58,6,param_8,param_9);
        }
        *(undefined4 *)(param_1 + 0x1218) = 1;
        LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                            "Diag Reset(miniport)-IOs still active on bus when TM reply received(UAR)"
                            ,param_8,param_9);
        KickStart(param_1,param_8,param_9);
        *puVar1 = 0;
      }
      return 1;
    }
  }
  return 0;
switchD_1400106a7_caseD_6:
  uVar10 = GtfStartTimer(param_1,1,1,UarStuckIoTimerCallback,puVar1,param_8,param_9);
  if ((char)uVar10 == -2) {
    if (*(short *)(param_1 + 0x960) != 0) {
      LogSystemEvent(param_1,0xad01007e,0x8004af01,
                     (byte *)"No timer available for stuck IO scan in UAR state machine",param_8,
                     param_9);
    }
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                  (undefined1 *)0x0,0,param_8,param_9);
    }
    bVar7 = true;
  }
  else {
    bVar7 = false;
  }
  *puVar1 = 7;
  if (!bVar7) {
    return 1;
  }
  goto LAB_140010690;
}



===== HexVersionToString @ 140011240 =====

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
      goto LAB_14001129a;
    }
  }
  else {
    *param_2 = (char)((ulonglong)(uVar2 & 0xff) / 10) + '0';
LAB_14001129a:
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
      goto LAB_140011317;
    }
  }
  else {
    *pcVar3 = bStackX_a / 10 + 0x30;
LAB_140011317:
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
      goto LAB_14001138c;
    }
  }
  else {
    *pcVar4 = bStackX_11 / 10 + 0x30;
LAB_14001138c:
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
    if (bVar1) goto LAB_140011407;
    *pcVar3 = '0';
  }
  else {
    *pcVar3 = local_res10 / 10 + 0x30;
  }
  pcVar3 = pcVar3 + 1;
LAB_140011407:
  *pcVar3 = local_res10 % 10 + 0x30;
  pcVar3[1] = '\0';
  return;
}



===== InitReplyFreeQueue @ 140011430 =====

void InitReplyFreeQueue(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  ulonglong uVar5;
  
  uVar1 = *(ushort *)(param_1 + 0x53c);
  uVar2 = *(ushort *)(param_1 + 0x532);
  iVar4 = *(int *)(param_1 + 0x218);
  piVar3 = *(int **)(param_1 + 0x548);
  if (uVar1 != 0) {
    uVar5 = (ulonglong)(uint)uVar1;
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
  *(ushort *)(param_1 + 0x224) = uVar1;
  return;
}



===== IoUnitCtrlTimeSyncTimerCallback @ 140011490 =====

ulonglong IoUnitCtrlTimeSyncTimerCallback
                    (longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,int param_5
                    )

{
  ulonglong uVar1;
  
  *(undefined1 *)(param_1 + 0xb9f9) = 0;
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x282) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x282,
                (undefined1 *)0x0,0,param_4,param_5);
  }
  LogOperationalEvent(param_1,(int *)0x0,0,0x8004af01,
                      "Diag Reset(miniport)-IO Unit Ctrl cmd sent for TimeSync timed out",param_4,
                      param_5);
  *(undefined4 *)(param_1 + 0x1218) = 1;
  uVar1 = KickStart(param_1,param_4,param_5);
  return uVar1 & 0xffffffffffffff00;
}



===== IssueIOCFacts @ 140011550 =====

ulonglong IssueIOCFacts(longlong param_1,byte param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  short sVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  char *pcVar8;
  
  iVar1 = *(int *)(param_1 + 0x970);
  *(undefined8 *)(param_1 + 0x9c4) = 0;
  *(undefined4 *)(param_1 + 0x9cc) = 0;
  *(undefined8 *)(param_1 + 0xa64) = 0;
  *(undefined8 *)(param_1 + 0xa6c) = 0;
  *(undefined8 *)(param_1 + 0xa74) = 0;
  *(undefined8 *)(param_1 + 0xa7c) = 0;
  *(undefined8 *)(param_1 + 0xa84) = 0;
  *(undefined8 *)(param_1 + 0xa8c) = 0;
  *(undefined8 *)(param_1 + 0xa94) = 0;
  *(undefined8 *)(param_1 + 0xa9c) = 0;
  *(undefined4 *)(param_1 + 0xaa4) = 0;
  *(undefined1 *)(param_1 + 0x9c7) = 3;
  bVar3 = SendMessageViaHandShake(param_1,0,3);
  if ((bVar3) && (uVar5 = ReceiveDataViaHandshake(param_1,0x22), (char)uVar5 != '\0')) {
    *(undefined2 *)(param_1 + 0x9ac) = *(undefined2 *)(param_1 + 0xa64);
    *(short *)(param_1 + 0x536) = *(short *)(param_1 + 0xa88);
    *(short *)(param_1 + 0x534) = *(short *)(param_1 + 0xa88) << 2;
    *(undefined2 *)(param_1 + 0x53e) = *(undefined2 *)(param_1 + 0xa98);
    *(ushort *)(param_1 + 0x540) = (ushort)*(byte *)(param_1 + 0xa78);
    sVar4 = *(short *)(param_1 + 0xa8a) << 4;
    *(short *)(param_1 + 0x530) = sVar4;
    if (sVar4 == 0) {
      *(undefined2 *)(param_1 + 0x530) = 0x80;
    }
    *(short *)(param_1 + 0x998) = *(short *)(param_1 + 0xa7c) + -7;
    *(ushort *)(param_1 + 0x99c) = *(ushort *)(param_1 + 0xa8e);
    *(short *)(param_1 + 0x99e) = (*(short *)(param_1 + 0xa92) + 1) * 2;
    *(ushort *)(param_1 + 0x9a0) = *(ushort *)(param_1 + 0xa90);
    if (*(ushort *)(param_1 + 0xa90) < 0xe) {
      *(undefined2 *)(param_1 + 0x9a0) = 0xe;
    }
    sVar4 = 0x40;
    if (*(short *)(param_1 + 0xa9e) != 0) {
      sVar4 = *(short *)(param_1 + 0xa9e);
    }
    *(short *)(param_1 + 0x18bc) = sVar4 + -1;
    *(undefined2 *)(param_1 + 0x9a6) = *(undefined2 *)(param_1 + 0xa96);
    *(undefined2 *)(param_1 + 0x9a8) = *(undefined2 *)(param_1 + 0xa9c);
    *(ushort *)(param_1 + 0x99a) = (ushort)*(byte *)(param_1 + 0xa7a);
    *(ushort *)(param_1 + 0x532) = (ushort)*(byte *)(param_1 + 0xa9a) << 2;
    if (0x7f80 < *(ushort *)(param_1 + 0xa8e)) {
      *(undefined2 *)(param_1 + 0x99c) = 0x7f80;
    }
    uVar2 = *(uint *)(param_1 + 0xa80);
    *(uint *)(param_1 + 0x120c) = uVar2;
    if ((uVar2 & 4) != 0) {
      *(undefined1 *)(param_1 + 0x120b) = 1;
    }
    *(undefined1 *)(param_1 + 0x9a2) = 0;
    *(undefined4 *)(param_1 + 0x1164) = *(undefined4 *)(param_1 + 0xa84);
    if (((uVar2 >> 0xf & 1) != 0) && (1 < *(byte *)(param_1 + 0xa7b))) {
      *(byte *)(param_1 + 0x133) = *(byte *)(param_1 + 0xa7b);
      *(undefined1 *)(param_1 + 0x132) = 1;
    }
    if (iVar1 == 0) {
      if ((uVar2 & 8) != 0) {
        *(undefined1 *)(param_1 + 0x16f0) = 1;
      }
      if ((uVar2 & 0x10) != 0) {
        *(undefined1 *)(param_1 + 0x1708) = 1;
      }
      if ((uVar2 & 0x20) != 0) {
        *(undefined1 *)(param_1 + 0x1720) = 1;
      }
    }
    *(undefined4 *)(param_1 + 0x958) = 600000;
    if ((*(ushort *)(param_1 + 0xa94) & 8) != 0) {
      *(undefined1 *)(param_1 + 0x11e7) = 1;
    }
    if ((*(ushort *)(param_1 + 0xa94) & 2) != 0) {
      if (*(ushort *)(param_1 + 0x534) < 0x2c1) {
        return 0x201;
      }
      pcVar8 = "Max MPI message frame size is exceeded";
      uVar7 = 0xad01007a;
      goto LAB_1400117c0;
    }
  }
  pcVar8 = "Handshake of a IOCFacts message failed";
  uVar7 = 0xad01000d;
LAB_1400117c0:
  uVar6 = LogSystemEvent(param_1,uVar7,0xc004af02,(byte *)pcVar8,param_2,param_3);
  return uVar6 & 0xffffffffffffff00;
}



===== IssueLogSenseToSataDevice @ 1400117f0 =====

ulonglong IssueLogSenseToSataDevice(longlong param_1,ushort param_2,byte param_3,int param_4)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  ushort *puVar5;
  longlong lVar6;
  ushort local_res8 [4];
  
  lVar6 = *(longlong *)(param_1 + 0xb950);
  local_res8[0] = 0;
  if (lVar6 == 0) {
    if (*(char *)(param_1 + 0xbbd0) == '\0') {
      plVar1 = (longlong *)GetHostReqTag(param_1,local_res8);
      if ((char)plVar1 != '\0') {
        lVar6 = (ulonglong)local_res8[0] * 0x20 + *(longlong *)(param_1 + 0x598);
LAB_14001188e:
        *(longlong *)(param_1 + 0xb950) = lVar6;
        goto LAB_140011895;
      }
    }
    else {
      plVar1 = *(longlong **)(param_1 + 0x910);
      lVar6 = *plVar1;
      if (*(longlong *)(lVar6 + 8) == 0) {
        lVar2 = *(longlong *)(param_1 + 0x910) + 8;
        *(longlong *)(param_1 + 0x910) = lVar2;
        if (lVar2 == *(longlong *)(param_1 + 0x920)) {
          *(undefined8 *)(param_1 + 0x910) = *(undefined8 *)(param_1 + 0x908);
        }
        goto LAB_14001188e;
      }
    }
    uVar3 = (ulonglong)plVar1 & 0xffffffffffffff00;
  }
  else {
LAB_140011895:
    *(uint *)(lVar6 + 0x18) = *(uint *)(lVar6 + 0x18) | 0x100;
    puVar5 = (ushort *)
             ((longlong)(int)((uint)*(ushort *)(param_1 + 0x534) * (uint)*(ushort *)(lVar6 + 0x10))
             + *(longlong *)(param_1 + 0x558));
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
    puVar5[0x1a] = 0;
    puVar5[0x1b] = 0;
    puVar5[0x1c] = 0;
    puVar5[0x1d] = 0;
    puVar5[0x1e] = 0;
    puVar5[0x1f] = 0;
    puVar5[0x20] = 0;
    puVar5[0x21] = 0;
    puVar5[0x22] = 0;
    puVar5[0x23] = 0;
    puVar5[0x24] = 0;
    puVar5[0x25] = 0;
    puVar5[0x26] = 0;
    puVar5[0x27] = 0;
    puVar5[0x28] = 0;
    puVar5[0x29] = 0;
    puVar5[0x2a] = 0;
    puVar5[0x2b] = 0;
    puVar5[0x2c] = 0;
    puVar5[0x2d] = 0;
    puVar5[0x2e] = 0;
    puVar5[0x2f] = 0;
    puVar5[0x30] = 0;
    puVar5[0x31] = 0;
    puVar5[0x32] = 0;
    puVar5[0x33] = 0;
    puVar5[0x34] = 0;
    puVar5[0x35] = 0;
    puVar5[0x36] = 0;
    puVar5[0x37] = 0;
    *puVar5 = param_2;
    *(undefined1 *)(puVar5 + 10) = 0x18;
    puVar5[0x12] = 10;
    puVar5[0x1e] = 0;
    puVar5[0x1f] = 0x200;
    puVar5[0xe] = 0x100;
    puVar5[0xf] = 0;
    *(int *)(puVar5 + 6) = *(int *)(param_1 + 0x11f8) - *(int *)(param_1 + 0x108);
    *(undefined1 *)(puVar5 + 9) = 0xff;
    *(undefined1 *)(puVar5 + 0x20) = 0x4d;
    *(undefined1 *)(puVar5 + 0x21) = 0x6f;
    *(undefined2 *)((longlong)puVar5 + 0x47) = 1;
    iVar4 = *(int *)(param_1 + 0xb948) - *(int *)(param_1 + 0x108);
    if (*(char *)(param_1 + 0x120a) == '\0') {
      puVar5[0x30] = 0x100;
      puVar5[0x31] = 0xd300;
      *(int *)(puVar5 + 0x32) = iVar4;
      *(undefined4 *)(puVar5 + 0x34) = *(undefined4 *)(param_1 + 500);
    }
    else {
      puVar5[0x34] = 0x100;
      puVar5[0x35] = 0;
      *(undefined1 *)((longlong)puVar5 + 0x6f) = 0x40;
      *(int *)(puVar5 + 0x30) = iVar4;
      *(undefined4 *)(puVar5 + 0x32) = *(undefined4 *)(param_1 + 500);
    }
    QueueRequestDescriptor
              (param_1,(uint)*(ushort *)(lVar6 + 0x10) << 0x10,(uint)param_2 << 0x10,param_3,param_4
              );
    uVar3 = GtfStartTimer(param_1,1,5,LogSenseSataTimeout,0,param_3,param_4);
    *(char *)(param_1 + 0xb932) = (char)uVar3;
    if ((((char)uVar3 == -2) && (*(char *)(param_1 + 0x608) != '\0')) &&
       ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
      uVar3 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                          (undefined1 *)0x0,0,param_3,param_4);
    }
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}



===== IssueLunReset @ 140011a00 =====

void IssueLunReset(longlong param_1,byte param_2,int param_3)

{
  undefined2 uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x928) + 0x68);
  puVar3 = *(undefined8 **)(param_1 + 0x568);
  lVar4 = ((ulonglong)*(byte *)(lVar2 + 0x62) * 0x80 + (ulonglong)*(byte *)(lVar2 + 99)) * 0x2c;
  uVar1 = *(undefined2 *)(lVar4 + 0x1a + *(longlong *)(param_1 + 0x5c0));
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  *(undefined4 *)(puVar3 + 6) = 0;
  *(undefined2 *)puVar3 = uVar1;
  *(undefined1 *)((longlong)puVar3 + 3) = 1;
  *(undefined1 *)((longlong)puVar3 + 5) = 5;
  *(undefined1 *)((longlong)puVar3 + 0xd) = *(undefined1 *)(lVar2 + 100);
  if (((*(char *)(lVar4 + 0x24 + *(longlong *)(param_1 + 0x5c0)) != '\0') &&
      (*(char *)(param_1 + 0x18b0) == '\0')) &&
     ((*(uint *)(lVar4 + 0x14 + *(longlong *)(param_1 + 0x5c0)) & 4) == 0)) {
    *(undefined1 *)((longlong)puVar3 + 7) = 0x18;
  }
  QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x9b2) * 0x10000 + 6,0,param_2,param_3)
  ;
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20007) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20007,
                (undefined1 *)(lVar2 + 0x62),3,param_2,param_3);
  }
  AfdMasterTrigger(param_1,4,param_2,param_3);
  return;
}



===== IssuePortFacts @ 140011b30 =====

undefined8 IssuePortFacts(longlong param_1,undefined1 param_2,byte param_3,int param_4)

{
  bool bVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  *(undefined8 *)(param_1 + 0x9c4) = 0;
  *(undefined4 *)(param_1 + 0x9cc) = 0;
  *(undefined8 *)(param_1 + 0xa64) = 0;
  *(undefined8 *)(param_1 + 0xa6c) = 0;
  *(undefined8 *)(param_1 + 0xa74) = 0;
  *(undefined4 *)(param_1 + 0xa7c) = 0;
  *(undefined1 *)(param_1 + 0x9ca) = param_2;
  *(undefined1 *)(param_1 + 0x9c7) = 5;
  bVar1 = SendMessageViaHandShake(param_1,0,3);
  if (bVar1) {
    uVar2 = ReceiveDataViaHandshake(param_1,0xe);
    if ((char)uVar2 != '\0') {
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
  }
  uVar3 = LogSystemEvent(param_1,0xad01000f,0xc004af02,
                         (byte *)"Handshake of PortFacts message failed",param_3,param_4);
  return uVar3 & 0xffffffffffffff00;
}



===== IssueReset @ 140011bf0 =====

void IssueReset(longlong param_1,int param_2)

{
  **(int **)(param_1 + 0x18) = param_2 << 0x18;
  LOCK();
  UNLOCK();
  SymWaitForResponse(param_1);
  return;
}



===== KickStart @ 140011c10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong KickStart(longlong param_1,byte param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  uint7 extraout_var;
  uint7 extraout_var_00;
  uint7 extraout_var_01;
  uint7 extraout_var_02;
  undefined8 uVar3;
  uint7 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  char *pcVar10;
  uint local_res8 [2];
  
  bVar1 = 0;
  if (*(char *)(param_1 + 0xbbc4) == '\0') {
    bVar1 = 2;
  }
  uVar4 = 0;
  do {
    local_res8[0] = **(uint **)(param_1 + 0x18);
    bVar1 = bVar1 + 1;
    if (local_res8[0] != 0) break;
  } while (bVar1 < 3);
  if (local_res8[0] == 0xffffffff) goto LAB_140011f08;
  if ((local_res8[0] & 0xf0000000) == 0x40000000) {
LAB_140011cee:
    uVar8 = local_res8[0] & 0xffff;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x240) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x240,
                  (undefined1 *)local_res8,4,param_2,param_3);
    }
    LogSystemEvent(param_1,uVar8 + 0xad0f0000,0xc004af02,(byte *)"FW Fault code logged",param_2,
                   param_3);
    if ((short)local_res8[0] == 0x2810) {
      *(undefined2 *)(param_1 + 0x11d2) = 0x101;
      CompleteAllSrbs(param_1,param_2,param_3);
      uVar4 = extraout_var_00;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x242) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x242,
                    (undefined1 *)0x0,0,param_2,param_3);
        uVar4 = extraout_var_01;
      }
      goto LAB_140011f08;
    }
    if (*(char *)(param_1 + 0x11b9) != '\0') {
      *(undefined4 *)(param_1 + 0x187c) = _DAT_0000face;
    }
    uVar8 = 1;
  }
  else {
    if ((local_res8[0] & 0xf0000000) == 0x50000000) {
      LogSystemEvent(param_1,0x50000000,0xc004af02,(byte *)"KickStart detected FW coredump state",
                     param_2,param_3);
      if (*(char *)(param_1 + 0xbbdc) == '\0') {
        *(undefined1 *)(param_1 + 0x1211) = 0;
        *(undefined1 *)(param_1 + 0xbbdc) = 1;
        StorPortNotification(6,param_1,WatchdogTimer,1000000);
        uVar4 = extraout_var;
        goto LAB_140011f08;
      }
      goto LAB_140011cee;
    }
    uVar8 = 2;
  }
  AfdMasterTrigger(param_1,uVar8,param_2,param_3);
  if (*(char *)(param_1 + 0x11b9) != '\0') {
    *(undefined4 *)(param_1 + 0x187c) = _DAT_0000dead;
  }
  *(undefined1 *)(param_1 + 0x1212) = 1;
  EnableDiagnosticRegister(param_1,param_2,param_3);
  bVar1 = 0;
  if (*(char *)(param_1 + 0xbbc4) == '\0') {
    bVar1 = 2;
  }
  do {
    uVar8 = **(uint **)(param_1 + 0xe0);
    bVar1 = bVar1 + 1;
    if (uVar8 != 0) break;
  } while (bVar1 < 3);
  bVar1 = 0;
  if (*(char *)(param_1 + 0xbbc4) == '\0') {
    bVar1 = 2;
  }
  do {
    bVar1 = bVar1 + 1;
    if (**(uint **)(param_1 + 0x28) != 0) break;
  } while (bVar1 < 3);
  **(uint **)(param_1 + 0x28) = **(uint **)(param_1 + 0x28) | 4;
  LOCK();
  UNLOCK();
  lVar9 = 0x32;
  do {
    StorPortStallExecution(1000);
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  uVar6 = 0;
  do {
    bVar1 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar1 = 2;
    }
    do {
      uVar4 = 0;
      uVar7 = **(uint **)(param_1 + 0x28);
      bVar1 = bVar1 + 1;
      if (uVar7 != 0) break;
    } while (bVar1 < 3);
    if (uVar7 == 0xffffffff) goto LAB_140011f08;
    if ((uVar7 & 4) == 0) goto LAB_140011f29;
    StorPortStallExecution(500);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 600000);
  if (uVar6 == 600000) {
    pcVar10 = "Reset of IOC failed";
    uVar5 = 0xad010023;
  }
  else {
LAB_140011f29:
    if ((uVar7 >> 8 & 1) != 0) {
      uVar7 = uVar7 & 0xffffefff | 0x800;
      **(uint **)(param_1 + 0x28) = uVar7;
      LOCK();
      UNLOCK();
      **(uint **)(param_1 + 0xe0) = uVar8 | 1;
      LOCK();
      UNLOCK();
    }
    **(uint **)(param_1 + 0x28) = uVar7 & 0xfffffffd;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x20) = 0;
    LOCK();
    UNLOCK();
    uVar3 = GtfInitialize(param_1);
    pcVar10 = (char *)(param_1 + 0x16f2);
    lVar9 = 3;
    do {
      if ((((pcVar10[-2] != '\0') && (pcVar10[-1] != '\0')) && (*pcVar10 != '\0')) &&
         (uVar3 = ReleaseFwDiagBuffer(param_1,(longlong)(pcVar10 + -0x12),param_2,param_3),
         (char)uVar3 != '\0')) {
        *pcVar10 = '\0';
        pcVar10[-4] = '\x01';
      }
      pcVar10 = pcVar10 + 0x18;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    if ((*(char *)(param_1 + 0x11d4) != '\0') || (*(int *)(param_1 + 0x1218) != 0)) {
LAB_14001210b:
      return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
    uVar8 = 0;
    do {
      bVar1 = 0;
      if (*(char *)(param_1 + 0xbbc4) == '\0') {
        bVar1 = 2;
      }
      do {
        uVar4 = 0;
        local_res8[0] = **(uint **)(param_1 + 0x18);
        bVar1 = bVar1 + 1;
        if (local_res8[0] != 0) break;
      } while (bVar1 < 3);
      if (local_res8[0] == 0xffffffff) goto LAB_140011f08;
      if ((local_res8[0] & 0xf0000000) == 0x10000000) {
        cVar2 = *(char *)(param_1 + 0x608);
        uVar3 = 0;
        if (59999 < uVar8) goto LAB_14001204d;
        if ((cVar2 != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40000) != 0)) {
          uVar3 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                              0x40000,(undefined1 *)(param_1 + 0x1190),4,param_2,param_3);
        }
        goto LAB_14001210b;
      }
      StorPortStallExecution(1000);
      uVar8 = uVar8 + 1;
    } while (uVar8 < 300000);
    cVar2 = *(char *)(param_1 + 0x608);
LAB_14001204d:
    if ((cVar2 != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x200) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x200,
                  (undefined1 *)(param_1 + 0x1190),4,param_2,param_3);
    }
    pcVar10 = s_IOC_wouldn_t_come_READY_after_k;
    uVar5 = 0xad01000b;
  }
  LogSystemEvent(param_1,uVar5,0xc004af02,(byte *)pcVar10,param_2,param_3);
  uVar4 = extraout_var_02;
LAB_140011f08:
  return (ulonglong)uVar4 << 8;
}



===== LSImpiAdapterControl @ 140012120 =====

undefined8 LSImpiAdapterControl(longlong param_1,int param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  byte bVar4;
  
  if (param_2 == 0) {
    *(undefined2 *)((longlong)param_3 + 4) = 0x101;
    *(undefined1 *)((longlong)param_3 + 6) = 1;
    *(undefined1 *)((longlong)param_3 + 0x15) = 1;
    return 0;
  }
  if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0x11d7) = 1;
    if (*(char *)(param_1 + 0x11d4) != '\0') {
      *(undefined1 *)(param_1 + 0x11d5) = 1;
      return 0;
    }
    bVar4 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar4 = 2;
    }
    do {
      bVar4 = bVar4 + 1;
      if (**(uint **)(param_1 + 0x50) != 0) break;
    } while (bVar4 < 3);
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    if (*(short *)(param_1 + 0xb664) != 0) {
      SendAndProcessSSUCommands(param_1,0,7);
    }
    FlushAllDPMPage0(param_1,0,7);
    *(undefined1 *)(param_1 + 0x11d5) = 1;
    if ((*(uint *)(param_1 + 0x120c) & 0x2000) == 0) {
      LogOperationalEvent(param_1,(int *)(param_1 + 0x120c),4,0x4004af00,
                          "Diag Reset(miniport)-FW doesn\'t support event replay during StopAdapter"
                          ,0,7);
      KickStart(param_1,0,7);
      *(undefined1 *)(param_1 + 0x11d4) = 1;
    }
    else {
      **(undefined4 **)(param_1 + 0x18) = 0x40000000;
      LOCK();
      UNLOCK();
      SymWaitForResponse(param_1);
      *(undefined1 *)(param_1 + 0x11d4) = 1;
    }
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 0x11) {
        return 0;
      }
      lVar3 = 2;
      puVar1 = param_3;
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
        puVar2[8] = 0;
        puVar2[9] = 0;
        puVar2[10] = 0;
        puVar2[0xb] = 0;
        puVar2[0xc] = 0;
        puVar2[0xd] = 0;
        puVar2[0xe] = 0;
        puVar2[0xf] = 0;
        lVar3 = lVar3 + -1;
        puVar1 = puVar2 + 0x10;
      } while (lVar3 != 0);
      puVar2[0x10] = 0;
      *(undefined4 *)(puVar2 + 0x11) = 0;
      *(undefined4 *)param_3 = 1;
      *(undefined4 *)((longlong)param_3 + 4) = 0x10c;
      memmove((void *)((longlong)param_3 + 9),(void *)(param_1 + 0x1974),0x10);
      return 0;
    }
    *(undefined1 *)(param_1 + 0x11d7) = 1;
    LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,"Restart adapter request received",0,7);
    *(undefined4 *)(param_1 + 0x1218) = 1;
    *(undefined2 *)(param_1 + 0x1214) = 0;
    *(undefined1 *)(param_1 + 0x11d5) = 0;
    PauseAdapterQueue(param_1,10,0,7);
    bVar4 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar4 = 2;
    }
    do {
      bVar4 = bVar4 + 1;
      if (**(int **)(param_1 + 0x18) != 0) break;
    } while (bVar4 < 3);
    if (((*(uint *)(param_1 + 0x120c) & 0x2000) == 0) || (**(int **)(param_1 + 0x18) == 0)) {
      *(undefined4 *)(param_1 + 0x97c) = *(undefined4 *)(param_1 + 0x980);
    }
    else {
      **(undefined4 **)(param_1 + 0x18) = 0x40000000;
      LOCK();
      UNLOCK();
      SymWaitForResponse(param_1);
    }
  }
  *(undefined1 *)(param_1 + 0x11d7) = 0;
  return 0;
}



===== LogSenseSataTimeout @ 1400123b0 =====

ulonglong LogSenseSataTimeout(longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,
                             int param_5)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  uVar1 = *(ushort *)(param_1 + 0xb938);
  lVar2 = *(longlong *)(param_1 + 0x5c0);
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x245) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x245,
                (undefined1 *)0x0,0,param_4,param_5);
  }
  puVar3 = *(undefined8 **)(param_1 + 0x578);
  *(undefined1 *)(param_1 + 0xb931) = 1;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  *(undefined4 *)(puVar3 + 6) = 0;
  *(undefined2 *)puVar3 = *(undefined2 *)((ulonglong)uVar1 * 0x2c + lVar2 + 0x1a);
  *(undefined1 *)((longlong)puVar3 + 3) = 1;
  *(undefined1 *)((longlong)puVar3 + 5) = 1;
  uVar4 = QueueRequestDescriptor
                    (param_1,(uint)*(ushort *)(param_1 + 0x9b6) * 0x10000 + 6,0,param_4,param_5);
  return uVar4 & 0xffffffffffffff00;
}



===== LsiHandleAppRequest @ 140012490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LsiHandleAppRequest(longlong param_1,void *param_2,byte param_3,int param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  int *piVar9;
  byte bVar10;
  undefined4 uVar11;
  short sVar12;
  undefined1 local_b8 [32];
  void **ppvVar13;
  uint uVar14;
  char local_78 [8];
  void *local_70;
  undefined4 local_68;
  undefined4 local_64;
  char local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)local_b8;
  lVar2 = *(longlong *)((longlong)param_2 + 0x40);
  local_68 = *(undefined4 *)(lVar2 + 0x10);
  local_60 = 0;
  local_64 = 0;
  *(void **)(param_1 + 0x1228) = param_2;
  *(undefined4 *)(param_1 + 0x1284) = 0;
  uVar14 = *(uint *)(lVar2 + 0x10);
  local_70 = param_2;
  if (uVar14 < 0x806d706a) {
    if (uVar14 == 0x806d7069) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400012) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400012,
                    (undefined1 *)&local_70,0x11,param_3,param_4);
      }
      if (*(int *)(param_1 + 0x968) == 0) {
        uVar8 = SendIOCTLMessage(param_1,(ushort *)(lVar2 + 0x1c),param_2,param_3,param_4);
        if ((char)uVar8 != '\0') {
          return;
        }
        *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
      }
      else {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400009) != 0))
        {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400009,
                      (undefined1 *)&local_70,0x11,param_3,param_4);
        }
        *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
      }
      goto LAB_140013006;
    }
    if (uVar14 == 0x1b0780) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40000f) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40000f,
                    (undefined1 *)&local_70,0x11,param_3,param_4);
      }
      uVar8 = 0;
      do {
        if ((uint)*(byte *)(uVar8 + 4 + lVar2) != (int)"FIRMWARE"[uVar8]) {
          *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x25c) == 0))
          goto LAB_140013006;
          uVar14 = 0;
          uVar11 = 0x25c;
          ppvVar13 = (void **)0x0;
          goto LAB_140013001;
        }
        bVar10 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar10;
      } while (bVar10 < 8);
      if (bVar10 == 8) {
        HbaFwReloadFsm(param_1,'\0',0,param_3,param_4);
        return;
      }
      goto LAB_140013006;
    }
    if (uVar14 == 0x800000ff) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400010) != 0)) {
        uVar11 = 0x400010;
LAB_140012fe6:
        ppvVar13 = &local_70;
        uVar14 = 0x11;
LAB_140013001:
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar11,
                    (undefined1 *)ppvVar13,uVar14,param_3,param_4);
      }
      goto LAB_140013006;
    }
    if (uVar14 == 0x8043494d) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400011) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400011,
                    (undefined1 *)&local_70,0x11,param_3,param_4);
      }
      uVar8 = 0;
      do {
        if (*(char *)(uVar8 + 4 + lVar2) != (&CIM_IOCTLVER)[uVar8]) {
          *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x25d) == 0))
          goto LAB_140013006;
          uVar11 = 0x25d;
          goto LAB_140012fe6;
        }
        bVar10 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar10;
      } while (bVar10 < 4);
      if (bVar10 == 4) {
        lVar3 = *(longlong *)((longlong)param_2 + 0x40);
        *(undefined4 *)(lVar3 + 0x20) = AdapPageVersion;
        iVar6 = *(int *)(lVar3 + 0x1c);
        if (iVar6 == 1) {
          lVar3 = *(longlong *)((longlong)param_2 + 0x40);
          if (*(uint *)(lVar3 + 0x18) < 0x58) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          }
          else {
            memmove((void *)(lVar3 + 0x24),(void *)(param_1 + 0x1148),0x50);
            *(undefined4 *)(lVar3 + 0x3c) = 0;
            *(undefined1 *)(param_1 + 0x118c) = 0;
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x74;
          }
        }
        else if (iVar6 == 3) {
          if (*(uint *)(*(longlong *)((longlong)param_2 + 0x40) + 0x18) < 0x114) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          }
          else {
            memmove((void *)(*(longlong *)((longlong)param_2 + 0x40) + 0x30),
                    (void *)(param_1 + 0x1758),0x100);
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x130;
          }
        }
        else if (iVar6 == 10) {
          if (*(uint *)(lVar3 + 0x18) < 0x1c) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          }
          else {
            *(undefined4 *)(lVar3 + 0x24) = 200;
            memmove((void *)(lVar3 + 0x28),(void *)(param_1 + 0x119c),0x10);
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x38;
          }
        }
        else if (iVar6 == 0xb) {
          if (*(uint *)(lVar3 + 0x18) < 0x18) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          }
          else {
            memmove((void *)(param_1 + 0x119c),(void *)(lVar3 + 0x24),0x10);
            *(uint *)(param_1 + 0x11a8) = *(uint *)(param_1 + 0x11a8) | 0x4000;
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x34;
          }
        }
        else if (iVar6 == 0xc) {
          if (*(uint *)(lVar3 + 0x18) < 0x9c48) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          }
          else {
            memmove((void *)(lVar3 + 0x24),(void *)(param_1 + 0x1a1c),40000);
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x9c64;
          }
        }
        else {
          *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
        }
      }
      goto LAB_140013006;
    }
    if (uVar14 == 0x804d4150) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400018) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400018,
                    (undefined1 *)&local_70,0x11,param_3,param_4);
      }
      uVar7 = BusTargetDevHandleMapping(param_1,(longlong)param_2);
      *(int *)((longlong)param_2 + 0x3c) = (int)uVar7;
      goto LAB_140013006;
    }
    if (uVar14 == 0x80646961) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400016) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400016,
                    (undefined1 *)&local_70,0x11,param_3,param_4);
      }
      uVar8 = 0;
      do {
        if (*(char *)(uVar8 + 4 + lVar2) != (&FW_DIAG_IOCTLSIG)[uVar8]) {
          *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x262) == 0))
          goto LAB_140013006;
          uVar11 = 0x262;
          goto LAB_140012fe6;
        }
        bVar10 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar10;
      } while (bVar10 < 8);
      if (bVar10 != 8) goto LAB_140013006;
      *(void **)(param_1 + 0x1750) = param_2;
      uVar7 = PerformFwDiagOperation(param_1,lVar2,local_78,param_3,param_4);
      if ((char)uVar7 != '\0') {
        if (local_78[0] == '\0') {
          *(undefined1 *)(param_1 + 0x1220) = 1;
          return;
        }
        goto LAB_140013006;
      }
      goto LAB_140012e68;
    }
LAB_140012ac3:
    *(undefined1 *)((longlong)param_2 + 3) = 6;
    *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
  }
  else {
    if (uVar14 == 0x80727374) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400013) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400013,
                    (undefined1 *)&local_70,0x11,param_3,param_4);
      }
      uVar8 = 0;
      do {
        if (*(char *)(uVar8 + 4 + lVar2) != (&RST_IOCTLSIG)[uVar8]) {
          *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x25e) == 0))
          goto LAB_140013006;
          uVar11 = 0x25e;
          goto LAB_140012fe6;
        }
        bVar10 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar10;
      } while (bVar10 < 8);
      if (bVar10 == 8) {
        if (*(uint *)((longlong)param_2 + 0x28) < 0x1e) {
          *(undefined4 *)((longlong)param_2 + 0x28) = 0x1e;
        }
        *(undefined1 *)(param_1 + 0x1220) = 1;
        PauseAdapterQueue(param_1,6,param_3,param_4);
        ResetActive(param_1,0xb,param_3,param_4);
        puVar5 = *(undefined8 **)(param_1 + 0x948);
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5[3] = 0;
        puVar5[4] = 0;
        *(undefined4 *)(puVar5 + 5) = 0;
        *(undefined1 *)((longlong)puVar5 + 3) = 7;
        *(undefined8 *)((longlong)puVar5 + 0x14) = 0xffffffffffffffff;
        *(undefined8 *)((longlong)puVar5 + 0x1c) = 0xffffffffffffffff;
        *(undefined1 *)(param_1 + 0x11b1) = 1;
        QueueRequestDescriptor
                  (param_1,(uint)*(ushort *)(param_1 + 0x9ae) * 0x10000 + 8,0,param_3,param_4);
        *(undefined4 *)(param_1 + 0x978) = 4;
        return;
      }
      goto LAB_140013006;
    }
    if (uVar14 == 0x80727474) {
      bVar10 = 0;
      do {
        if (*(char *)((ulonglong)bVar10 + 4 + lVar2) != RTTRACE_IOCTL_SIG[bVar10]) {
          *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x260) == 0))
          goto LAB_140013006;
          uVar11 = 0x260;
          goto LAB_140012fe6;
        }
        bVar10 = bVar10 + 1;
      } while (bVar10 < 8);
      if (bVar10 != 8) goto LAB_140013006;
      uVar7 = HandleRttIoctl(param_1,lVar2,local_78,param_4);
      if ((char)uVar7 == '\0') {
LAB_140012e68:
        *(undefined1 *)((longlong)param_2 + 3) = 1;
        goto LAB_140013006;
      }
    }
    else {
      if (uVar14 != 0x80727574) {
        if (uVar14 == 0x80727676) {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400014) != 0)
             ) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400014,
                        (undefined1 *)&local_70,0x11,param_3,param_4);
          }
          uVar8 = 0;
          do {
            if (*(char *)(uVar8 + 4 + lVar2) != RS_IOCTL_SIGNATURE[uVar8]) {
              *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
              if ((*(char *)(param_1 + 0x608) == '\0') ||
                 ((*(uint *)(param_1 + 0x60c) & 0x25f) == 0)) goto LAB_140013006;
              uVar11 = 0x25f;
              goto LAB_140012fe6;
            }
            bVar10 = (char)uVar8 + 1;
            uVar8 = (ulonglong)bVar10;
          } while (bVar10 < 8);
          if (bVar10 == 8) {
            uVar7 = RsIoctl_sm(param_1,(longlong)param_2,0,param_3,param_4);
            if ((char)uVar7 != '\0') {
              return;
            }
            *(undefined1 *)((longlong)param_2 + 3) = 1;
          }
          goto LAB_140013006;
        }
        if (uVar14 == 0x80771959) {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400017) != 0)
             ) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400017,
                        (undefined1 *)&local_70,0x11,param_3,param_4);
          }
          uVar8 = 0;
          do {
            if (*(char *)(uVar8 + 4 + lVar2) != (&MPI_IOCTLVER)[uVar8]) {
              *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
              if ((*(char *)(param_1 + 0x608) == '\0') ||
                 ((*(uint *)(param_1 + 0x60c) & 0x263) == 0)) goto LAB_140013006;
              uVar11 = 0x263;
              goto LAB_140012fe6;
            }
            bVar10 = (char)uVar8 + 1;
            uVar8 = (ulonglong)bVar10;
          } while (bVar10 < 4);
          if (bVar10 == 4) {
            lVar3 = *(longlong *)((longlong)param_2 + 0x40);
            lVar4 = *(longlong *)(param_1 + 0x100);
            iVar6 = *(int *)(lVar3 + 0x24);
            piVar9 = (int *)(*(longlong *)(param_1 + 0x10) + (ulonglong)*(uint *)(lVar3 + 0x20));
            sVar12 = (short)lVar4 + (short)*(uint *)(lVar3 + 0x20);
            iVar1 = *(int *)(lVar3 + 0x1c);
            if (iVar1 == 1) {
              if (lVar4 == 0) {
                *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
                *(int *)(lVar3 + 0x24) = iVar6;
              }
              else {
                iVar6 = in(sVar12);
LAB_140012c14:
                *(int *)(lVar3 + 0x24) = iVar6;
              }
            }
            else if (iVar1 == 2) {
              if (lVar4 == 0) {
                *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
                *(int *)(lVar3 + 0x24) = iVar6;
              }
              else {
                out(sVar12,iVar6);
                *(int *)(lVar3 + 0x24) = iVar6;
              }
            }
            else if (iVar1 == 3) {
              bVar10 = 0;
              if (*(char *)(param_1 + 0xbbc4) == '\0') {
                bVar10 = 2;
              }
              do {
                iVar6 = *piVar9;
                bVar10 = bVar10 + 1;
                if (iVar6 != 0) goto LAB_140012c14;
              } while (bVar10 < 3);
              *(undefined4 *)(lVar3 + 0x24) = 0;
            }
            else if (iVar1 == 4) {
              *piVar9 = iVar6;
              LOCK();
              UNLOCK();
              *(int *)(lVar3 + 0x24) = iVar6;
            }
            else {
              *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
              *(int *)(lVar3 + 0x24) = iVar6;
            }
          }
          goto LAB_140013006;
        }
        goto LAB_140012ac3;
      }
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400015) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400015,
                    (undefined1 *)&local_70,0x11,param_3,param_4);
      }
      uVar8 = 0;
      do {
        if (*(char *)(uVar8 + 4 + lVar2) != (&AUTO_FW_DIAG_IOCTL_SIG)[uVar8]) {
          *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x261) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x261,
                        (undefined1 *)&local_70,0x11,param_3,param_4);
          }
          goto LAB_140012e0c;
        }
        bVar10 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar10;
      } while (bVar10 < 8);
      if (bVar10 != 8) {
LAB_140012e0c:
        *(undefined4 *)(lVar2 + 0x14) = 5;
        goto LAB_140013006;
      }
      uVar7 = HandleAfdTriggerIoctl(param_1,lVar2,local_78,param_3,param_4);
      if ((char)uVar7 == '\0') {
        *(undefined1 *)((longlong)param_2 + 3) = 1;
      }
    }
    if (local_78[0] == '\0') {
      return;
    }
  }
LAB_140013006:
  local_60 = *(char *)((longlong)param_2 + 3);
  if (((local_60 != '\x03') && (local_60 != '\x05')) && (local_60 != '\x06')) {
    if (*(int *)((longlong)param_2 + 0x3c) == 0) {
      *(undefined1 *)((longlong)param_2 + 3) = 4;
      local_60 = '\x04';
    }
    else {
      *(undefined1 *)((longlong)param_2 + 3) = 1;
      local_60 = '\x01';
    }
  }
  local_64 = *(undefined4 *)(lVar2 + 0x14);
  StorPortNotification(0,param_1,param_2);
  *(undefined8 *)(param_1 + 0x1228) = 0;
  *(undefined8 *)(param_1 + 0x1750) = 0;
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40001c) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40001c,
                (undefined1 *)&local_70,0x11,param_3,param_4);
  }
  return;
}



===== LsiMpiPartitionMemory @ 1400130d0 =====

void LsiMpiPartitionMemory(longlong param_1,byte param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  char cVar4;
  size_t _Size;
  undefined4 *puVar5;
  ulonglong uVar6;
  ushort uVar7;
  longlong lVar8;
  longlong *plVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  void *pvVar13;
  void *pvVar14;
  longlong *plVar15;
  uint uVar16;
  undefined8 *puVar17;
  undefined8 *puVar18;
  undefined2 *puVar19;
  uint uVar20;
  int iVar21;
  
  uVar7 = *(ushort *)(param_1 + 0x998);
  uVar1 = *(ushort *)(param_1 + 0x534);
  uVar6 = (ulonglong)uVar1;
  uVar2 = *(ushort *)(param_1 + 0x532);
  uVar3 = *(ushort *)(param_1 + 0x53c);
  *(undefined2 *)(param_1 + 0x964) = 0;
  *(undefined4 *)(param_1 + 0x968) = 0;
  *(undefined4 *)(param_1 + 0x1288) = 0;
  *(undefined8 *)(param_1 + 0x974) = 0;
  *(undefined8 *)(param_1 + 0x928) = 0;
  *(undefined8 *)(param_1 + 0x930) = 0;
  *(undefined2 *)(param_1 + 0x1210) = 0;
  *(undefined1 *)(param_1 + 0x11d6) = 0;
  *(undefined1 *)(param_1 + 0xb699) = 0;
  *(undefined2 *)(param_1 + 0x11d9) = 0;
  *(undefined2 *)(param_1 + 0x1208) = 0xfe;
  *(undefined2 *)(param_1 + 0xb932) = 0xfefe;
  *(undefined2 *)(param_1 + 0x11de) = 0;
  *(undefined2 *)(param_1 + 0x11e1) = 0;
  *(undefined2 *)(param_1 + 0x11dc) = 0;
  *(undefined1 *)(param_1 + 0x11e3) = 0;
  *(undefined8 *)(param_1 + 0x18e0) = 0;
  *(undefined8 *)(param_1 + 0x18e8) = 0;
  *(undefined1 *)(param_1 + 0x18cc) = 0;
  *(undefined1 *)(param_1 + 0x5c8) = 0;
  *(undefined1 *)(param_1 + 0x9ba) = 0;
  *(undefined2 *)(param_1 + 0xbbdb) = 0;
  *(undefined4 *)(param_1 + 0xb9f4) = 0;
  *(undefined4 *)(param_1 + 0x11c0) = 0;
  if ((((*(char *)(param_1 + 0x1220) != '\0') || (*(longlong *)(param_1 + 0x1228) != 0)) &&
      (*(char *)(param_1 + 0x11bd) == '\0')) && (*(char *)(param_1 + 0x11be) == '\0')) {
    CleanUpIoctl(param_1,param_2,param_3);
  }
  uVar10 = (uint)uVar1;
  *(longlong *)(param_1 + 0x558) = *(longlong *)(param_1 + 8);
  *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x1f0);
  *(undefined1 *)(param_1 + 0x1220) = 0;
  *(undefined1 *)(param_1 + 0x18f8) = 0;
  lVar12 = *(longlong *)(param_1 + 8) + (ulonglong)((uVar7 + 1) * uVar10);
  *(undefined2 *)(param_1 + 0x18f4) = 0;
  *(longlong *)(param_1 + 0x948) = lVar12;
  lVar12 = lVar12 + uVar6;
  *(longlong *)(param_1 + 0x560) = lVar12;
  *(undefined1 *)(param_1 + 0x18b0) = 0;
  iVar21 = *(int *)(param_1 + 0x1f0) + (uVar7 + 2) * uVar10;
  *(ushort *)(param_1 + 0x9ae) = uVar7 + 1;
  *(ulonglong *)(param_1 + 0x568) = uVar6 + lVar12;
  *(int *)(param_1 + 0x204) = iVar21;
  *(ulonglong *)(param_1 + 0x570) = (ulonglong)((uint)uVar1 * 2) + lVar12;
  *(ulonglong *)(param_1 + 0x578) = (ulonglong)((uint)uVar1 * 3) + lVar12;
  *(ulonglong *)(param_1 + 0x580) = (ulonglong)((uint)uVar1 * 4) + lVar12;
  *(uint *)(param_1 + 0x208) = iVar21 + (uint)uVar1;
  *(uint *)(param_1 + 0x20c) = (uint)uVar1 * 2 + iVar21;
  *(uint *)(param_1 + 0x210) = (uint)uVar1 * 3 + iVar21;
  *(uint *)(param_1 + 0x214) = (uint)uVar1 * 4 + iVar21;
  iVar21 = iVar21 + (uint)uVar1 * 5;
  pvVar13 = (void *)(lVar12 + (ulonglong)((uint)uVar1 * 5));
  *(int *)(param_1 + 0x1f8) = iVar21;
  *(void **)(param_1 + 0x548) = pvVar13;
  *(ushort *)(param_1 + 0x9b0) = uVar7 + 2;
  *(ushort *)(param_1 + 0x9b2) = uVar7 + 3;
  *(ushort *)(param_1 + 0x9b4) = uVar7 + 4;
  *(ushort *)(param_1 + 0x9b6) = uVar7 + 5;
  *(ushort *)(param_1 + 0x9b8) = uVar7 + 6;
  _Size = (ulonglong)*(ushort *)(param_1 + 0x538) * 4;
  iVar21 = iVar21 + (int)_Size;
  pvVar14 = (void *)((longlong)pvVar13 + _Size);
  if ((int)_Size != 0) {
    memset(pvVar13,0,_Size);
  }
  uVar16 = (uint)*(ushort *)(param_1 + 0x53a);
  *(void **)(param_1 + 0x550) = pvVar14;
  *(int *)(param_1 + 0x1fc) = iVar21;
  if (*(char *)(param_1 + 0x132) != '\0') {
    uVar16 = (uint)*(ushort *)(param_1 + 0x53a) * (uint)*(byte *)(param_1 + 0x133);
  }
  lVar12 = (longlong)pvVar14 + (ulonglong)(uVar16 * 8);
  if (uVar16 != 0) {
    memset(pvVar14,-1,(ulonglong)(uVar16 * 2) << 2);
  }
  uVar20 = uVar7 + 6;
  puVar19 = (undefined2 *)(param_1 + 0x428);
  for (lVar8 = 0x80; lVar8 != 0; lVar8 = lVar8 + -1) {
    *puVar19 = 0;
    puVar19 = puVar19 + 1;
  }
  *(longlong *)(param_1 + 0x588) = lVar12;
  *(uint *)(param_1 + 0x218) = iVar21 + uVar16 * 8;
  uVar11 = 1;
  plVar15 = (longlong *)(lVar12 + (ulonglong)uVar3 * (ulonglong)uVar2);
  *(longlong **)(param_1 + 0x590) = plVar15;
  uVar16 = 1;
  *(longlong **)(param_1 + 0x908) = plVar15;
  *(longlong **)(param_1 + 0x598) = plVar15 + ((ulonglong)uVar7 - 4);
  *(longlong **)(param_1 + 0x910) = plVar15;
  *(longlong **)(param_1 + 0x918) = plVar15;
  plVar9 = plVar15;
  if (uVar20 != 0) {
    do {
      lVar12 = (ulonglong)uVar16 * 0x20;
      *(ulonglong *)(lVar12 + *(longlong *)(param_1 + 0x598)) =
           (ulonglong)(uVar16 * uVar10) + *(longlong *)(param_1 + 0x558);
      *(undefined8 *)(lVar12 + 8 + *(longlong *)(param_1 + 0x598)) = 0;
      *(short *)(lVar12 + 0x10 + *(longlong *)(param_1 + 0x598)) = (short)uVar16;
      *(undefined4 *)(lVar12 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0;
      *(undefined1 *)(lVar12 + 0x12 + *(longlong *)(param_1 + 0x598)) = 0;
      if (uVar16 <= uVar7) {
        *plVar9 = *(longlong *)(param_1 + 0x598) + lVar12;
        plVar9 = plVar9 + 1;
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 <= uVar20);
  }
  plVar15 = plVar15 + (ulonglong)uVar7 + (ulonglong)uVar20 * 4;
  *(longlong **)(param_1 + 0x920) = plVar9;
  *(longlong **)(param_1 + 0x11f8) = plVar15;
  *(longlong **)(param_1 + 0x1200) = plVar15 + 0x20;
  *(longlong **)(param_1 + 0xb978) = plVar15 + 0x60;
  if (*(char *)(param_1 + 0x11ee) == '\0') {
    memset(plVar15 + 0x60,0,0x1400);
  }
  plVar9 = plVar15 + 0x2e0;
  if (*(char *)(param_1 + 0xb930) != '\0') {
    *(longlong **)(param_1 + 0xb948) = plVar9;
    plVar9 = plVar15 + 0x300;
  }
  *(longlong **)(param_1 + 0xaa8) = plVar9;
  *(undefined4 *)plVar9 = 0xfffffffe;
  uVar7 = *(ushort *)(param_1 + 0x998);
  if (1 < (ushort)((uVar7 >> 5) + 2)) {
    do {
      uVar10 = (int)uVar11 + 1;
      *(undefined4 *)(*(longlong *)(param_1 + 0xaa8) + uVar11 * 4) = 0xffffffff;
      uVar7 = *(ushort *)(param_1 + 0x998);
      uVar11 = (ulonglong)uVar10;
    } while (uVar10 < (uVar7 >> 5) + 2);
  }
  puVar5 = (undefined4 *)((longlong)plVar9 + ((ulonglong)(uVar7 >> 5) + 2) * 4);
  if (*(char *)(param_1 + 0xba00) != '\0') {
    if (*(char *)(param_1 + 0x11ee) == '\0') {
      *(undefined4 **)(param_1 + 0xba28) = puVar5;
      *(undefined4 **)(param_1 + 0xba20) = puVar5 + (ulonglong)*(ushort *)(param_1 + 0xba08) * 2;
      puVar17 = (undefined8 *)(param_1 + 0xba38);
      puVar5 = puVar5 + (ulonglong)*(ushort *)(param_1 + 0xba08) * 2 +
               (ulonglong)*(uint *)(param_1 + 0xba04) * 0xe;
      lVar12 = 8;
      *(undefined4 **)(param_1 + 0xbb28) = puVar5;
      *(undefined4 **)(param_1 + 0xba18) = puVar5 + 0x24;
      puVar5 = puVar5 + 0x224;
      do {
        *puVar17 = puVar5;
        puVar17 = puVar17 + 1;
        puVar5 = puVar5 + 0x80;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      puVar17 = (undefined8 *)(param_1 + 0xba78);
      lVar12 = 4;
      do {
        *puVar17 = puVar5;
        puVar17 = puVar17 + 1;
        puVar5 = puVar5 + 0x10;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      *(undefined4 **)(param_1 + 0xba30) = puVar5;
      puVar5 = puVar5 + *(ushort *)(param_1 + 0x99c);
    }
    else {
      puVar5 = puVar5 + (ulonglong)*(ushort *)(param_1 + 0x99c) + 0x664 +
                        ((ulonglong)*(uint *)(param_1 + 0xba04) * 7 +
                        (ulonglong)*(ushort *)(param_1 + 0xba08)) * 2;
    }
  }
  *(undefined4 **)(param_1 + 0x1270) = puVar5;
  uVar16 = 0;
  puVar17 = (undefined8 *)((longlong)puVar5 + uVar6);
  *(undefined8 **)(param_1 + 0x5c0) = puVar17;
  puVar18 = (undefined8 *)((longlong)puVar17 + (ulonglong)(uint)(*(int *)(param_1 + 0x9bc) * 0x2c));
  uVar10 = 0;
  if (*(int *)(param_1 + 0x9bc) != 0) {
    do {
      ClearMapEntry(param_1,puVar17);
      uVar10 = *(uint *)(param_1 + 0x9bc);
      uVar16 = uVar16 + 1;
      puVar17 = (undefined8 *)((longlong)puVar17 + 0x2c);
    } while (uVar16 < uVar10);
  }
  *(undefined8 **)(param_1 + 0x5a0) = puVar18;
  uVar16 = 0;
  puVar19 = (undefined2 *)
            ((longlong)puVar18 + (ulonglong)((uint)*(ushort *)(param_1 + 0x99e) * 0x1c));
  if (*(ushort *)(param_1 + 0x99e) != 0) {
    do {
      ClearEnclosureEntry(puVar18);
      uVar16 = uVar16 + 1;
      puVar18 = (undefined8 *)((longlong)puVar18 + 0x1c);
    } while (uVar16 < *(ushort *)(param_1 + 0x99e));
    uVar10 = *(uint *)(param_1 + 0x9bc);
  }
  *(undefined2 **)(param_1 + 0x5b8) = puVar19;
  uVar16 = uVar10 * 10;
  pvVar13 = (void *)((longlong)puVar19 + (ulonglong)uVar16);
  if (uVar16 != 0) {
    memset(puVar19,0,(ulonglong)uVar16);
    uVar10 = *(uint *)(param_1 + 0x9bc);
    puVar19 = *(undefined2 **)(param_1 + 0x5b8);
  }
  uVar16 = 0;
  if (uVar10 != 0) {
    do {
      *puVar19 = 0xffff;
      puVar19 = puVar19 + 5;
      uVar16 = uVar16 + 1;
    } while (uVar16 < *(uint *)(param_1 + 0x9bc));
  }
  *(void **)(param_1 + 0x5a8) = pvVar13;
  uVar10 = *(uint *)(param_1 + 0x5cc);
  pvVar14 = (void *)((longlong)pvVar13 + (ulonglong)uVar10);
  if (uVar10 != 0) {
    memset(pvVar13,0,(ulonglong)uVar10);
  }
  *(void **)(param_1 + 0x5b0) = pvVar14;
  uVar10 = *(uint *)(param_1 + 0x5d0);
  pvVar13 = (void *)((longlong)pvVar14 + (ulonglong)uVar10);
  if (uVar10 != 0) {
    memset(pvVar14,0,(ulonglong)uVar10);
  }
  uVar10 = *(uint *)(param_1 + 0x600);
  if ((*(char *)(param_1 + 0x11ee) == '\0') && (*(void **)(param_1 + 0x5d8) = pvVar13, uVar10 != 0))
  {
    memset(pvVar13,0,(ulonglong)uVar10);
  }
  pvVar13 = (void *)((longlong)pvVar13 + (ulonglong)uVar10);
  if (*(int *)(param_1 + 0x970) == 0) {
    *(void **)(param_1 + 0x11c8) = pvVar13;
    pvVar13 = (void *)((longlong)pvVar13 + 0x80);
    lVar8 = 0x80;
    lVar12 = 0;
    do {
      *(undefined1 *)(lVar12 + *(longlong *)(param_1 + 0x11c8)) = 0;
      lVar8 = lVar8 + -1;
      lVar12 = lVar12 + 1;
    } while (lVar8 != 0);
  }
  *(void **)(param_1 + 0x18d0) = pvVar13;
  uVar7 = *(ushort *)(param_1 + 0x18bc);
  uVar10 = (uint)uVar7;
  if ((uVar7 & 3) != 0) {
    uVar10 = uVar10 + (4 - (uVar7 & 3));
  }
  lVar12 = (longlong)pvVar13 + (ulonglong)uVar10;
  if (uVar10 != 0) {
    memset(pvVar13,0,(ulonglong)uVar10);
    uVar7 = *(ushort *)(param_1 + 0x18bc);
  }
  uVar10 = (uint)uVar7;
  *(longlong *)(param_1 + 0x18d8) = lVar12;
  if ((uVar7 & 3) != 0) {
    uVar10 = uVar10 + (4 - (uVar10 & 3));
  }
  lVar12 = lVar12 + (ulonglong)uVar10;
  if (((*(char *)(param_1 + 0xb670) == '\0') &&
      (cVar4 = IsHbaFwDowngradeInProgress(param_1), cVar4 == '\0')) && (uVar10 != 0)) {
    memset(*(void **)(param_1 + 0x18d8),0,(ulonglong)uVar10);
  }
  *(longlong *)(param_1 + 0x1910) = lVar12;
  uVar10 = (uint)*(ushort *)(param_1 + 0x18bc) * 0x14 + 8;
  puVar17 = (undefined8 *)(lVar12 + (ulonglong)uVar10);
  if (((*(char *)(param_1 + 0xb670) == '\0') &&
      (cVar4 = IsHbaFwDowngradeInProgress(param_1), cVar4 == '\0')) && (uVar10 != 0)) {
    memset(*(void **)(param_1 + 0x1910),0,(ulonglong)uVar10);
  }
  *(undefined8 **)(param_1 + 0x1918) = puVar17;
  lVar12 = (longlong)puVar17 + 0x1c;
  *puVar17 = 0;
  puVar17[1] = 0;
  puVar17[2] = 0;
  *(undefined4 *)(puVar17 + 3) = 0;
  if (*(char *)(param_1 + 0xbbc6) == '\0') {
    uVar10 = 0;
    plVar9 = (longlong *)(param_1 + 0x16e0);
    do {
      if (((char)plVar9[2] == '\0') || (*(uint *)(plVar9 + 1) == 0)) {
        *(undefined1 *)(plVar9 + 2) = 0;
      }
      else {
        *plVar9 = lVar12;
        lVar12 = lVar12 + (ulonglong)*(uint *)(plVar9 + 1);
        *(char *)((longlong)plVar9 + 0xc) = (char)uVar10;
      }
      uVar10 = uVar10 + 1;
      plVar9 = plVar9 + 3;
    } while (uVar10 < 3);
  }
  *(undefined4 *)(param_1 + 0x1998) = 0;
  *(undefined8 *)(param_1 + 0x1990) = 0;
  *(longlong *)(param_1 + 0x1988) = lVar12;
  *(undefined2 *)(param_1 + 0x199c) = 0;
  if (*(char *)(param_1 + 0x11ee) == '\0') {
    *(ulonglong *)(param_1 + 0x1860) = (lVar12 + 0x34U & 0xfffffffffffffffc) + 4;
    *(undefined4 *)(param_1 + 0x185c) = 0xa00;
  }
  *(undefined2 *)(param_1 + 0x10f4) = 0;
  puVar5 = (undefined4 *)(param_1 + 0xdd4);
  lVar12 = 200;
  do {
    puVar5[-200] = 0;
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  *(undefined2 *)(param_1 + 0x10f6) = 0;
  puVar19 = (undefined2 *)(param_1 + 0x10f8);
  lVar12 = 10;
  do {
    *puVar19 = 0;
    puVar19 = puVar19 + 4;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  *(undefined2 *)(param_1 + 0x12ad) = 0;
  puVar17 = (undefined8 *)(param_1 + 0x12b8);
  lVar12 = 2;
  do {
    lVar8 = lVar12;
    *puVar17 = 0;
    puVar17[1] = 0;
    puVar17[2] = 0;
    puVar17[3] = 0;
    puVar17[4] = 0;
    puVar17[5] = 0;
    puVar17[6] = 0;
    puVar17[7] = 0;
    puVar17[8] = 0;
    puVar17[9] = 0;
    puVar17[10] = 0;
    puVar17[0xb] = 0;
    puVar17[0xc] = 0;
    puVar17[0xd] = 0;
    puVar17[0xe] = 0;
    puVar17[0xf] = 0;
    lVar12 = lVar8 + -1;
    puVar17 = puVar17 + 0x10;
  } while (lVar12 != 0);
  *(undefined2 *)(param_1 + 0x12af) = 0;
  uVar6 = (ulonglong)((int)lVar8 + 5);
  puVar17 = (undefined8 *)(param_1 + 0x13b8);
  do {
    puVar18 = puVar17;
    *puVar18 = 0;
    puVar18[1] = 0;
    puVar18[2] = 0;
    puVar18[3] = 0;
    puVar18[4] = 0;
    puVar18[5] = 0;
    puVar18[6] = 0;
    puVar18[7] = 0;
    puVar18[8] = 0;
    puVar18[9] = 0;
    puVar18[10] = 0;
    puVar18[0xb] = 0;
    puVar18[0xc] = 0;
    puVar18[0xd] = 0;
    puVar18[0xe] = 0;
    puVar18[0xf] = 0;
    uVar6 = uVar6 - 1;
    puVar17 = puVar18 + 0x10;
  } while (uVar6 != 0);
  puVar18[0x10] = 0;
  puVar18[0x11] = 0;
  puVar18[0x12] = 0;
  puVar18[0x13] = 0;
  return;
}



===== LunResetTurTimeout @ 140013a00 =====

ulonglong LunResetTurTimeout(longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,
                            int param_5)

{
  longlong lVar1;
  ulonglong uVar2;
  uint local_res8 [2];
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x928) + 0x68);
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x2001c) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2001c,
                (undefined1 *)(lVar1 + 0x62),3,param_4,param_5);
  }
  local_res8[0] =
       (uint)CONCAT21(CONCAT11(*(undefined1 *)(lVar1 + 0x62),*(undefined1 *)(lVar1 + 99)),
                      *(undefined1 *)(lVar1 + 100));
  *(undefined4 *)(param_1 + 0x580) = 0;
  *(undefined1 *)(lVar1 + 0x65) = 1;
  LogOperationalEvent(param_1,(int *)local_res8,4,0x4004af00,
                      "Issuing OS initiated Lun Reset,AdapterQueue paused(TUR timed out,BTL logged)"
                      ,param_4,param_5);
  uVar2 = IssueLunReset(param_1,param_4,param_5);
  return uVar2 & 0xffffffffffffff00;
}



===== NonSCB_Func_handler @ 140013af0 =====

void NonSCB_Func_handler(longlong param_1,short *param_2,short param_3,byte param_4,int param_5)

{
  undefined8 *puVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  char cVar7;
  longlong lVar8;
  undefined1 uVar9;
  uint uVar10;
  longlong lVar11;
  byte bVar12;
  undefined1 *puVar13;
  undefined4 local_res8;
  byte *pbVar14;
  uint uVar15;
  
  pbVar14 = (byte *)((longlong)param_2 + 3);
  puVar13 = (undefined1 *)0x0;
  switch(*pbVar14) {
  case 1:
    *(undefined4 *)(param_1 + 0x974) = 0;
    cVar2 = *(char *)((longlong)param_2 + 5);
    if (((*(char *)(param_1 + 0x18f4) != '\0') && (param_3 == *(short *)(param_1 + 0x9ae))) &&
       ((cVar2 == '\x02' || (cVar2 == '\a')))) {
      *(short **)(param_1 + 0x940) = param_2;
      SasBcAsyncEvent(param_1,param_4,param_5);
      break;
    }
    if (((*(uint *)(param_1 + 0x1998) & 1) != 0) && (*(short *)(param_1 + 0x199c) == param_3)) {
      lVar8 = *(longlong *)(param_1 + 0x1990);
      lVar11 = *(longlong *)(lVar8 + 0x68);
      *(undefined4 *)(param_1 + 0x1998) = 0;
      *(undefined2 *)(param_1 + 0x199c) = 0;
      *(undefined8 *)(param_1 + 0x1990) = 0;
      *(undefined1 *)(param_1 + 0x1984) = 0;
      *(undefined1 *)(*(longlong *)(lVar11 + 0x40) + 8) = 0;
      lVar11 = *(longlong *)(lVar8 + 0x40);
      *(undefined1 *)(lVar8 + 3) = 1;
      *(undefined1 *)(lVar11 + 0x3c) = 0;
      if (param_2[7] == 0) {
        *(undefined4 *)(lVar11 + 0x14) = 0;
        *(undefined1 *)(lVar11 + 0x39) = 2;
        if (cVar2 == '\a') {
          *(undefined1 *)(lVar11 + 0x3c) = 1;
          *(undefined1 *)(lVar11 + 0x3e) = 1;
          *(char *)(lVar11 + 0x40) = (char)param_2[2];
        }
      }
      else if (param_2[7] == 6) {
        *(undefined4 *)(lVar11 + 0x14) = 0;
        *(undefined1 *)(lVar11 + 0x39) = 4;
      }
      else {
        *(undefined4 *)(lVar11 + 0x14) = 1;
        *(undefined1 *)(lVar11 + 0x39) = 3;
      }
      StorPortNotification();
      *(undefined1 *)(param_1 + 0x1220) = 0;
    }
    if (((*(char *)(param_1 + 0x11d9) != '\0') && (cVar2 == '\x03')) &&
       (param_3 == *(short *)(param_1 + 0x9b4))) {
      if ((param_2[7] & 0x7fffU) != 0) {
        local_res8 = CONCAT22(*param_2,param_2[7]) & 0xffff7fff;
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x273) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x273,
                      (undefined1 *)&local_res8,4,param_4,param_5);
        }
        LogSystemEvent(param_1,local_res8,0xc004af02,
                       (byte *)
                       "Target Reset Failed during Device Removal (IOCStatus & DevHandle logged)",
                       param_4,param_5);
      }
      RemoveDevice(param_1,param_4,param_5);
      break;
    }
    if (((*(char *)(param_1 + 0x1209) != '\0') && (cVar2 == '\x01')) &&
       (param_3 == *(short *)(param_1 + 0x9b6))) {
      *(undefined1 *)(param_1 + 0x1209) = 0;
      uVar6 = ReadIDs(param_1,param_4,param_5);
      if ((char)uVar6 == '\0') {
        *(undefined1 *)(param_1 + 0x11de) = 0;
        RemoveDevice(param_1,param_4,param_5);
      }
      break;
    }
    if (((*(char *)(param_1 + 0xb931) != '\0') && (cVar2 == '\x01')) &&
       (param_3 == *(short *)(param_1 + 0x9b6))) {
      *(short *)(param_1 + 0xb938) = *(short *)(param_1 + 0xb938) + 1;
      *(undefined1 *)(param_1 + 0xb931) = 0;
      *(undefined4 *)(param_1 + 0xb934) = 1;
      DetectSataPfa(param_1,0,0,param_4,param_5);
      break;
    }
    if (*(char *)(param_1 + 0x1210) != '\0') {
      ProcessBusReset(param_1,param_4,param_5);
      break;
    }
    if (cVar2 == '\x05') {
LAB_140013f05:
      if (*(longlong *)(param_1 + 0x928) != 0) {
        ProcessLunTargetReset(param_1,param_2,param_4,param_5);
        break;
      }
    }
    else if (cVar2 == '\x03') {
      if ((*(char *)(param_1 + 0x1220) != '\0') && (*(int *)(param_1 + 0x1284) == -0x21524111)) {
        puVar1 = *(undefined8 **)(param_1 + 0x948);
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = 0;
        puVar1[4] = 0;
        *(undefined4 *)(puVar1 + 5) = 0;
        *(undefined1 *)((longlong)puVar1 + 3) = 7;
        *(undefined8 *)((longlong)puVar1 + 0x14) = 0xffffffffffffffff;
        *(undefined8 *)((longlong)puVar1 + 0x1c) = 0xffffffffffffffff;
        *(undefined1 *)(param_1 + 0x11b1) = 1;
        QueueRequestDescriptor
                  (param_1,(uint)*(ushort *)(param_1 + 0x9ae) * 0x10000 + 8,0,param_4,param_5);
        uVar5 = GtfStartTimer(param_1,1,3,DelayedIoctlTimeout,0,param_4,param_5);
        if ((char)uVar5 == -2) {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                        (undefined1 *)0x0,0,param_4,param_5);
          }
          LogSystemEvent(param_1,0xad01007c,0x8004af01,
                         (byte *)"No Timer available for DelayedIoctlTimeout",param_4,param_5);
          DelayedIoctlTimeout(param_1,0,0,param_4,param_5);
        }
        break;
      }
      goto LAB_140013f05;
    }
    ResetActive(param_1,0x40000002,param_4,param_5);
    ResumeAdapterQueue(param_1,2,param_4,param_5);
    do {
      uVar3 = 1 << ((byte)puVar13 & 0x1f);
      if ((uVar3 & *(ushort *)(param_1 + 0x964)) != 0) {
        *(ushort *)(param_1 + 0x964) = ~uVar3 & *(ushort *)(param_1 + 0x964);
        LSImpiReset(param_1,(uint)puVar13,param_4,param_5);
        break;
      }
      uVar15 = (uint)puVar13 + 1;
      puVar13 = (undefined1 *)(ulonglong)uVar15;
    } while (uVar15 < 8);
    break;
  default:
    if (*(short *)(param_1 + 0x960) != 0) {
      LogSystemEvent(param_1,(uint)*pbVar14,0xc004af02,
                     (byte *)"Received Invalid Function ID in MPI Reply",param_4,param_5);
    }
    if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x202) == 0)) break;
    uVar4 = 0x202;
    uVar15 = 1;
    goto LAB_1400147e1;
  case 4:
    *(ushort *)(param_1 + 0x185a) = param_2[7] & 0x7fff;
    if (param_3 == *(short *)(param_1 + 0x9b4)) {
      if (*(char *)(param_1 + 0x11e1) != '\0') {
        *(undefined1 *)(param_1 + 0x11e1) = 0;
      }
      if (*(char *)(param_1 + 0x11de) != '\0') {
        ContinueIDReadsForPhyEvents(param_1,param_4,param_5);
        break;
      }
      if (*(char *)(param_1 + 0x11e0) != '\0') {
        ContinueMDTSReadsForPortEvents(param_1,param_4,param_5);
        break;
      }
      if (*(char *)(param_1 + 0x11df) != '\0') {
        ContinueIDReadsForPortEvents(param_1,param_4,param_5);
        break;
      }
      if (*(char *)(param_1 + 0x11e3) != '\0') {
        *(undefined1 *)(param_1 + 0x11e3) = 0;
        lVar11 = (ulonglong)((uint)*(ushort *)(param_1 + 0x5d4) * *(int *)(param_1 + 0x18e4)) +
                 *(longlong *)(param_1 + 0x5a8);
        lVar8 = (ulonglong)((uint)*(ushort *)(param_1 + 0x5d6) * *(int *)(param_1 + 0x18ec)) +
                *(longlong *)(param_1 + 0x5b0);
        if (*(char *)(param_1 + 0x11dc) == '\0') {
          if (*(char *)(param_1 + 0x11dd) != '\0') {
            if (*(char *)(lVar8 + 4) != '\0') goto LAB_1400141d2;
            *(undefined1 *)(param_1 + 0x11dd) = 0;
            if (*(char *)(lVar11 + 4) != '\0') goto LAB_14001420d;
          }
        }
        else {
          if (*(char *)(lVar11 + 4) != '\0') {
LAB_14001420d:
            *(undefined1 *)(param_1 + 0x11dc) = 1;
            UpdateMissingCount(param_1,param_4,param_5);
            StartIDReadsForPhyEvents(param_1,param_4,param_5);
            break;
          }
          *(undefined1 *)(param_1 + 0x11dc) = 0;
          if (*(char *)(lVar8 + 4) != '\0') {
LAB_1400141d2:
            *(undefined1 *)(param_1 + 0x11dd) = 1;
            UpdatePcieMissingCount(param_1,param_4,param_5);
            StartIDReadsForPortEvents(param_1,param_4,param_5);
            break;
          }
        }
        cVar2 = '\0';
        if ((*(longlong *)(param_1 + 0x928) == 0) && (*(int *)(param_1 + 0x1218) == 0)) {
          uVar6 = CheckResetQueue(param_1,param_4,param_5);
          cVar2 = (char)uVar6;
        }
        ResumeAdapterQueue(param_1,3,param_4,param_5);
        if (((*(int *)(param_1 + 0x1218) == 0) && (cVar2 == '\0')) &&
           (*(longlong *)(param_1 + 0x928) == 0)) {
          ResetActive(param_1,0x40000003,param_4,param_5);
        }
        if (*(char *)(param_1 + 0x5c8) != '\0') {
          *(undefined1 *)(param_1 + 0x5c8) = 0;
          *(undefined1 *)(param_1 + 0x118c) = 1;
          if ((*(int *)(param_1 + 0x1218) == 0) && (bVar12 = 0, *(short *)(param_1 + 0x9a4) != 0)) {
            do {
              if ((*(char *)(param_1 + 0x608) != '\0') &&
                 ((*(uint *)(param_1 + 0x60c) & 0x100005) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                            0x100005,(undefined1 *)0x0,0,param_4,param_5);
              }
              StorPortNotification(7,param_1,bVar12);
              bVar12 = bVar12 + 1;
            } while ((ushort)bVar12 < *(ushort *)(param_1 + 0x9a4));
          }
        }
      }
    }
    else if (*(char *)(param_1 + 0x11da) != '\0') {
      *(undefined1 *)(param_1 + 0x11da) = 0;
      if ((*(char *)(param_1 + 0xb670) != '\0') ||
         (cVar2 = IsHbaFwDowngradeInProgress(param_1), cVar2 != '\0')) break;
      FlushDPMPage0Entry(param_1,param_4,param_5);
    }
    uVar15 = *(uint *)(param_2 + 10);
    if ((((byte)(uVar15 >> 0x18) & 0xf) == 0xf) && ((char)*param_2 == '\0')) {
      cVar2 = (char)param_2[3];
      cVar7 = (char)(uVar15 >> 0x10);
      if (cVar2 == '\x10') {
        if (cVar7 == '\0') {
          puVar13 = (undefined1 *)(param_1 + 0x19a0);
        }
        else {
          lVar8 = 0x186c;
          if (cVar7 == '\x01') {
            lVar8 = 0x19a8;
          }
          puVar13 = (undefined1 *)(lVar8 + param_1);
        }
LAB_14001440d:
        uVar9 = (undefined1)uVar15;
      }
      else {
        if (cVar2 == '\x12') {
          if (cVar7 == '\0') {
            puVar13 = (undefined1 *)(param_1 + 0x1920);
          }
          else {
            lVar8 = 0x186c;
            if (cVar7 == '\x01') {
              lVar8 = 0x19b0;
            }
            puVar13 = (undefined1 *)(lVar8 + param_1);
          }
          goto LAB_14001440d;
        }
        if (cVar2 == '\x13') {
          if (cVar7 == '\0') {
            puVar13 = (undefined1 *)(param_1 + 0x19b8);
          }
          else {
            lVar8 = 0x186c;
            if (cVar7 == '\x01') {
              lVar8 = 0x19c0;
            }
            puVar13 = (undefined1 *)(lVar8 + param_1);
          }
          goto LAB_14001440d;
        }
        if (cVar2 == '\x15') {
          puVar13 = (undefined1 *)(param_1 + 0x1930);
          goto LAB_14001440d;
        }
        if (cVar2 == '\x1d') {
          lVar8 = 0x1940;
          if (cVar7 != '\0') {
            lVar8 = 0x1950;
          }
          puVar13 = (undefined1 *)(lVar8 + param_1);
          goto LAB_14001440d;
        }
        if (cVar2 == '\x17') {
          puVar13 = (undefined1 *)(param_1 + 0x1908);
          goto LAB_14001440d;
        }
        if ((cVar2 != -0x20) || (*(short *)(param_1 + 0x185a) != 0)) {
          puVar13 = (undefined1 *)(param_1 + 0x186c);
          goto LAB_14001440d;
        }
        uVar10 = uVar15 >> 0x10 & 0xff;
        if (uVar10 == 0) {
          uVar9 = (undefined1)param_2[10];
          puVar13 = (undefined1 *)(param_1 + 0xb904);
        }
        else if (uVar10 == 1) {
          uVar9 = (undefined1)param_2[10];
          puVar13 = (undefined1 *)(param_1 + 0xb90c);
        }
        else if (uVar10 == 2) {
          uVar9 = (undefined1)param_2[10];
          puVar13 = (undefined1 *)(param_1 + 0xb914);
        }
        else if (uVar10 == 3) {
          uVar9 = (undefined1)param_2[10];
          puVar13 = (undefined1 *)(param_1 + 0xb91c);
        }
        else if (uVar10 == 4) {
          uVar9 = (undefined1)param_2[10];
          puVar13 = (undefined1 *)(param_1 + 0xb924);
        }
        else {
          LogSystemEvent(param_1,uVar10,0xc004af02,
                         (byte *)"Drv trigger page reply has invalid page num (page num is logged)",
                         param_4,param_5);
          uVar9 = (undefined1)param_2[10];
        }
      }
      *puVar13 = uVar9;
      puVar13[2] = (char)param_2[0xb];
      puVar13[3] = *(undefined1 *)((longlong)param_2 + 0x17);
      *(short *)(puVar13 + 4) = param_2[2];
      puVar13[6] = (char)param_2[3];
    }
    else {
      *(uint *)(param_1 + 0x1868) = uVar15;
    }
    if (((*(char *)(param_1 + 0x121d) != '\0') ||
        (RsIoctl_sm(param_1,0,(longlong)param_2,param_4,param_5),
        *(char *)(param_1 + 0x121d) != '\0')) && ((char)*param_2 == '\0')) {
      *(uint *)(param_1 + 0x1868) = uVar15;
    }
    cVar2 = (char)param_2[3];
    if (cVar2 == '\x17') {
      if (*(char *)(param_1 + 0xb670) == '\0') break;
      HandleFWDowngrade(param_1,'\0',param_4,param_5);
      cVar2 = (char)param_2[3];
    }
    if ((cVar2 == -0x20) && ((char)*param_2 == '\x04')) {
      if (*(short *)(param_1 + 0x185a) == 0) {
        if (*(char *)(param_1 + 0xb7ee) != '\0') {
          ProcessDTPUpdateReplies(param_1,(longlong)param_2,param_4,param_5);
        }
      }
      else {
        LogSystemEvent(param_1,(uint)*(byte *)(param_2 + 0xb),0xc004af02,
                       (byte *)"Driver trigger page write failed (page num logged)",param_4,param_5)
        ;
      }
    }
    break;
  case 6:
    uVar3 = param_2[7];
    *(undefined1 *)(param_1 + 0x11d8) = 0;
    *(ushort *)(param_1 + 0x966) = uVar3 & 0x7fff;
    break;
  case 8:
    break;
  case 0x18:
    pbVar14 = (byte *)(param_2 + 7);
    if (((*(short *)pbVar14 == 0) || (*(char *)(param_1 + 0x608) == '\0')) ||
       ((*(uint *)(param_1 + 0x60c) & 0x201) == 0)) break;
    uVar4 = 0x201;
    uVar15 = 2;
LAB_1400147e1:
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar4,pbVar14,
                uVar15,param_4,param_5);
    break;
  case 0x1b:
    local_res8 = CONCAT22(local_res8._2_2_,param_2[7]) & 0xffff7fff;
    if ((*(char *)(param_1 + 0x11d9) == '\0') || (param_3 != *(short *)(param_1 + 0x9b4))) {
      if ((*(char *)(param_1 + 0x11b6) == '\0') || (param_3 != *(short *)(param_1 + 0x9b4))) {
        if ((*(char *)(param_1 + 0xb9f9) != '\0') && (param_3 == *(short *)(param_1 + 0x9b6))) {
          *(undefined1 *)(param_1 + 0xb9f9) = 0;
          if (*(byte *)(param_1 + 0xb9f8) != 0xfe) {
            GtfStopTimer(param_1,*(byte *)(param_1 + 0xb9f8),param_4,param_5);
          }
          if ((param_2[7] & 0x7fffU) != 0) {
            local_res8 = local_res8 & 0xffff;
            if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x283) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x283,
                          (undefined1 *)&local_res8,4,param_4,param_5);
            }
            LogSystemEvent(param_1,local_res8,0xc004af02,
                           (byte *)"SAS IO UNIT Ctrl sent for TimeSync Failed(IOCStatus logged)",
                           param_4,param_5);
          }
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x11b6) = 0;
        LogSystemEvent(param_1,0,0x4004af00,(byte *)"Nvme IO unit ctrl shutdown reply msg received",
                       param_4,param_5);
        if ((*(longlong *)(param_1 + 0x928) != 0) &&
           ((*(int *)(*(longlong *)(param_1 + 0x928) + 0x14) != 7 ||
            (*(int *)(param_1 + 0x970) == 0)))) {
          uVar4 = 0xd;
          if (*(short *)(param_1 + 0xb664) != 0) {
            uVar4 = 8;
          }
          *(undefined4 *)(param_1 + 0x1218) = uVar4;
        }
      }
    }
    else {
      if ((param_2[7] & 0x7fffU) != 0) {
        local_res8 = CONCAT22(param_2[2],(undefined2)local_res8);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x274) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x274,
                      (undefined1 *)&local_res8,4,param_4,param_5);
        }
        LogSystemEvent(param_1,local_res8,0xc004af02,
                       (byte *)
                       "SAS IO UNIT Control Failed Device Removal (IOCStatus & DevHandle logged)",
                       param_4,param_5);
      }
      *(undefined1 *)(param_1 + 0x11d9) = 0;
      RemoveDevice(param_1,param_4,param_5);
    }
    break;
  case 0x1c:
    if ((param_3 == *(short *)(param_1 + 0x9b4)) && (*(char *)(param_1 + 0x1209) == '\0')) {
      ContinueHashedSASAddress(param_1,(longlong)param_2,param_4,param_5);
    }
  }
  if (*(char *)(param_1 + 0x1220) == '\0') {
    CheckIoctlQueue(param_1,param_4,param_5);
  }
  return;
}



===== PauseAdapterQueue @ 140014870 =====

void PauseAdapterQueue(longlong param_1,undefined1 param_2,byte param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 local_res10;
  char local_res11;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xb9fc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  cVar3 = (char)iVar2 + '\x01';
  if (cVar3 == '\x01') {
    StorPortPause(param_1,400);
  }
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40c) != 0)) {
    local_res10 = param_2;
    local_res11 = cVar3;
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40c,&local_res10
                ,2,param_3,param_4);
  }
  return;
}



===== PauseDevice @ 140014920 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PauseDevice(longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                undefined2 param_5,undefined2 param_6,undefined4 param_7,undefined4 param_8,
                byte param_9,int param_10)

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
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x232) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x232,
                  (undefined1 *)&local_48,0x10,param_9,param_10);
    }
  }
  else {
    *(char *)(lVar1 + 0x30) = *(char *)(lVar1 + 0x30) + '\x01';
    local_39 = *(undefined1 *)(lVar1 + 0x30);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x111) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x111,
                  (undefined1 *)&local_48,0x10,param_9,param_10);
    }
    StorPortPauseDevice(param_1,param_2,param_3,param_4);
  }
  return;
}



===== PerformFwDiagOperation @ 140014aa0 =====

ulonglong PerformFwDiagOperation
                    (longlong param_1,longlong param_2,undefined1 *param_3,byte param_4,int param_5)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  void *pvVar8;
  uint uVar9;
  longlong lVar10;
  void *pvVar11;
  ushort uVar12;
  byte bVar13;
  ulonglong uVar14;
  ushort uVar15;
  
  *param_3 = 1;
  uVar15 = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined4 *)(param_2 + 0x20) = FwDiagPageVersion;
  iVar5 = *(int *)(param_2 + 0x1c);
  pvVar11 = (void *)(ulonglong)(iVar5 - 1);
  switch(pvVar11) {
  case (void *)0x0:
    if (0x73 < *(uint *)(param_2 + 0x18)) {
      bVar13 = *(byte *)(param_2 + 0x25);
      if (bVar13 < 3) {
        lVar2 = (ulonglong)bVar13 + 0xf4;
        pvVar11 = (void *)(lVar2 * 3);
        piVar1 = (int *)(param_1 + lVar2 * 0x18);
        if ((*(char *)(param_1 + 0xf + lVar2 * 0x18) == '\0') ||
           (*(char *)((longlong)piVar1 + 0x12) == '\0')) {
          if ((char)piVar1[4] == '\0') {
            *(undefined4 *)(param_2 + 0x14) = 0x13;
            goto LAB_140014f22;
          }
          if (((*(char *)((longlong)piVar1 + 0x12) == '\0') && (*(byte *)(piVar1 + 3) == bVar13)) &&
             (pvVar11 = (void *)(ulonglong)*(uint *)(param_2 + 0x88),
             piVar1[2] == *(uint *)(param_2 + 0x88))) {
            *(undefined1 *)((longlong)piVar1 + 0xf) = 0;
            if (*(char *)(param_2 + 0x25) == '\0') {
              memmove((void *)(param_1 + 0x1728),(void *)(param_2 + 0x2c),0x28);
            }
            *(undefined1 *)((longlong)piVar1 + 0xd) = *(undefined1 *)(param_2 + 0x24);
            piVar1[5] = *(int *)(param_2 + 0x8c);
            pvVar11 = (void *)PostFwDiagBuffer(param_1,piVar1,*(char *)(param_1 + 0xbbc6),param_4,
                                               param_5);
            if ((char)pvVar11 != '\0') {
              *param_3 = 0;
              return CONCAT71((int7)((ulonglong)pvVar11 >> 8),1);
            }
LAB_140014ebb:
            *(undefined4 *)(param_2 + 0x14) = 0x10;
            goto LAB_140014f22;
          }
        }
        else if ((*(byte *)(piVar1 + 3) == bVar13) &&
                (pvVar11 = (void *)(ulonglong)*(uint *)(param_2 + 0x88),
                piVar1[2] == *(uint *)(param_2 + 0x88))) {
          *(undefined1 *)((longlong)piVar1 + 0xf) = 0;
          iVar5 = *(int *)(param_2 + 0x8c);
          piVar1[5] = iVar5;
          return CONCAT71((uint7)(uint3)((uint)iVar5 >> 8),1);
        }
      }
    }
    break;
  case (void *)0x1:
  case (void *)0x4:
    uVar6 = *(uint *)(param_2 + 0x18);
    pvVar11 = (void *)(ulonglong)uVar6;
    if (iVar5 == 2) {
      if (0xb < uVar6) {
        pvVar8 = (void *)0x0;
        do {
          pvVar11 = pvVar8;
          if (*(int *)(param_1 + 0x16f4 + (longlong)pvVar11 * 0x18) == *(int *)(param_2 + 0x24))
          goto LAB_140014c74;
          bVar13 = (char)pvVar11 + 1;
          pvVar8 = (void *)(ulonglong)bVar13;
        } while (bVar13 < 3);
        *(undefined4 *)(param_2 + 0x14) = 0x11;
        goto LAB_140014f22;
      }
    }
    else if (0xb < uVar6) {
      pvVar8 = (void *)0x0;
      do {
        pvVar11 = pvVar8;
        if (*(int *)(param_1 + 0x16f4 + (longlong)pvVar11 * 0x18) == *(int *)(param_2 + 0x24))
        goto LAB_140014c74;
        bVar13 = (char)pvVar11 + 1;
        pvVar8 = (void *)(ulonglong)bVar13;
      } while (bVar13 < 3);
      *(undefined4 *)(param_2 + 0x14) = 0x11;
      goto LAB_140014f22;
    }
    break;
  case (void *)0x2:
    if (0x77 < *(uint *)(param_2 + 0x18)) {
      if (*(int *)(param_2 + 0x90) == 0) {
        bVar13 = *(byte *)(param_2 + 0x25);
        if (bVar13 < 3) {
LAB_140014d19:
          cVar4 = *(char *)(param_1 + 0xc + ((ulonglong)bVar13 + 0xf4) * 0x18);
          lVar2 = param_1 + ((ulonglong)bVar13 + 0xf4) * 0x18;
          *(char *)(param_2 + 0x25) = cVar4;
          *(undefined1 *)(param_2 + 0x24) = *(undefined1 *)(lVar2 + 0xd);
          if (cVar4 == '\0') {
            memmove((void *)(param_2 + 0x2c),(void *)(param_1 + 0x1728),0x28);
          }
          *(undefined4 *)(param_2 + 0x88) = *(undefined4 *)(lVar2 + 8);
          *(undefined4 *)(param_2 + 0x8c) = 0;
          uVar7 = *(undefined4 *)(lVar2 + 0x14);
          *(undefined4 *)(param_2 + 0x90) = uVar7;
          *(undefined2 *)(param_2 + 0x26) = 0;
          if ((*(char *)(lVar2 + 0xf) == '\0') && (*(int *)(lVar2 + 8) != 0)) {
            uVar15 = 1;
            *(undefined2 *)(param_2 + 0x26) = 1;
          }
          if ((*(char *)(lVar2 + 0x11) != '\0') || (*(char *)(lVar2 + 0x12) != '\0')) {
            uVar15 = uVar15 | 2;
          }
          *(ushort *)(param_2 + 0x26) = uVar15;
          uVar12 = uVar15 | 4;
          if (*(char *)(lVar2 + 0x12) == '\0') {
            uVar12 = uVar15;
          }
          *(ushort *)(param_2 + 0x26) = uVar12;
          return CONCAT71((uint7)(uint3)((uint)uVar7 >> 8),1);
        }
      }
      else {
        bVar13 = 0;
        do {
          pvVar11 = (void *)(ulonglong)bVar13;
          if (*(int *)(param_1 + 0x16f4 + (longlong)pvVar11 * 0x18) == *(int *)(param_2 + 0x90))
          goto LAB_140014d19;
          bVar13 = bVar13 + 1;
        } while (bVar13 < 3);
        *(undefined4 *)(param_2 + 0x14) = 0x11;
      }
      goto LAB_140014f22;
    }
    break;
  case (void *)0x3:
    uVar6 = *(uint *)(param_2 + 0x2c);
    pvVar11 = (void *)((ulonglong)uVar6 + 0xc);
    if (pvVar11 <= (void *)(ulonglong)*(uint *)(param_2 + 0x18)) {
      bVar13 = 0;
      do {
        uVar14 = (ulonglong)bVar13;
        pvVar11 = (void *)(uVar14 * 3);
        if (*(int *)(param_1 + 0x16f4 + uVar14 * 0x18) == *(int *)(param_2 + 0x30)) {
          plVar3 = (longlong *)(param_1 + (uVar14 + 0xf4) * 0x18);
          uVar9 = *(uint *)(param_2 + 0x28) + uVar6;
          pvVar11 = (void *)(ulonglong)uVar9;
          if (*(uint *)(plVar3 + 1) < uVar9) goto switchD_140014afb_default;
          pvVar11 = memmove((void *)(param_2 + 0x34),
                            (void *)((ulonglong)*(uint *)(param_2 + 0x28) + *plVar3),
                            (ulonglong)uVar6);
          uVar15 = *(ushort *)(param_2 + 0x26) | 2;
          if (*(char *)((longlong)plVar3 + 0xe) == '\0') {
            uVar15 = *(ushort *)(param_2 + 0x26) & 0xfffd;
          }
          *(ushort *)(param_2 + 0x26) = uVar15;
          if (((*(char *)((longlong)plVar3 + 0x12) != '\0') || ((uVar15 & 1) == 0)) ||
             (pvVar11 = (void *)PostFwDiagBuffer(param_1,(int *)plVar3,*(char *)(param_1 + 0xbbc6),
                                                 param_4,param_5), (char)pvVar11 != '\0')) {
LAB_140014f17:
            return CONCAT71((int7)((ulonglong)pvVar11 >> 8),1);
          }
          goto LAB_140014ebb;
        }
        bVar13 = bVar13 + 1;
      } while (bVar13 < 3);
      *(undefined4 *)(param_2 + 0x14) = 0x11;
      goto LAB_140014f22;
    }
    break;
  case (void *)0x5:
    if (0x23 < *(uint *)(param_2 + 0x18)) {
      pvVar8 = (void *)0x0;
      do {
        pvVar11 = pvVar8;
        if (*(int *)(param_1 + 0x16f4 + (longlong)pvVar11 * 0x18) == *(int *)(param_2 + 0x24)) {
          *(undefined2 *)(param_2 + 0x28) = *(undefined2 *)(param_1 + 0xbbb4);
          *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_1 + 0xbbb8);
          *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0xbbbc);
          pvVar11 = (void *)(ulonglong)*(uint *)(param_1 + 0xbbc0);
          *(uint *)(param_2 + 0x34) = *(uint *)(param_1 + 0xbbc0);
          goto LAB_140014f17;
        }
        bVar13 = (char)pvVar11 + 1;
        pvVar8 = (void *)(ulonglong)bVar13;
      } while (bVar13 < 3);
      *(undefined4 *)(param_2 + 0x14) = 0x11;
      goto LAB_140014f22;
    }
  }
  goto switchD_140014afb_default;
LAB_140014c74:
  lVar10 = (longlong)pvVar11 + 0xf4;
  pvVar11 = (void *)(lVar10 * 3);
  lVar2 = param_1 + lVar10 * 0x18;
  if (*(char *)(param_1 + 0x12 + lVar10 * 0x18) == '\0') {
    if (iVar5 == 2) {
      *(undefined4 *)(lVar2 + 0x14) = 0;
      *(undefined4 *)(param_2 + 0x14) = 0;
      return CONCAT71((int7)((ulonglong)pvVar11 >> 8),1);
    }
    *(undefined4 *)(param_2 + 0x14) = 0x14;
    goto LAB_140014f22;
  }
  if (iVar5 != 2) {
    pvVar11 = (void *)ReleaseFwDiagBuffer(param_1,lVar2,param_4,param_5);
    if ((char)pvVar11 != '\0') {
      *(undefined8 *)(param_1 + 0xbbb4) = 0;
      *(undefined8 *)(param_1 + 0xbbbc) = 0;
      *(ushort *)(param_1 + 0xbbb4) = *(ushort *)(param_1 + 0xbbb4) | 3;
      *param_3 = 0;
      return CONCAT71((int7)((ulonglong)pvVar11 >> 8),1);
    }
    *(undefined4 *)(param_2 + 0x14) = 0x12;
    goto LAB_140014f22;
  }
switchD_140014afb_default:
  *(undefined4 *)(param_2 + 0x14) = 3;
LAB_140014f22:
  return (ulonglong)pvVar11 & 0xffffffffffffff00;
}



===== PostFwDiagBuffer @ 140014f60 =====

ulonglong PostFwDiagBuffer(longlong param_1,int *param_2,char param_3,byte param_4,int param_5)

{
  undefined1 *_Dst;
  ulonglong in_RAX;
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined1 local_res10 [8];
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar4;
  undefined4 uStack_24;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  if ((char)param_2[4] == '\0') {
    return in_RAX & 0xffffffffffffff00;
  }
  _Dst = *(undefined1 **)(param_1 + 0x948);
  *(undefined1 *)((longlong)param_2 + 0xe) = 0;
  if (*(ushort *)(param_1 + 0x534) != 0) {
    memset(_Dst,0,(ulonglong)*(ushort *)(param_1 + 0x534));
  }
  _Dst[1] = (char)param_2[3];
  _Dst[3] = 0x1d;
  *_Dst = *(undefined1 *)((longlong)param_2 + 0xd);
  *(int *)(_Dst + 0x14) = param_2[2];
  memmove(_Dst + 0x24,(void *)(param_1 + 0x1728),0x28);
  if (param_3 == '\0') {
    *(undefined4 *)(_Dst + 0x10) = *(undefined4 *)(param_1 + 500);
    *(int *)(_Dst + 0xc) = *param_2 - *(int *)(param_1 + 0x108);
  }
  else {
    uVar3 = *(undefined8 *)param_2;
    lVar1 = StorPortGetPhysicalAddress(param_1,0,uVar3,local_res10);
    if (lVar1 == 0) {
      uVar2 = StorPortExtendedFunction(0x19,param_1,uVar3,param_2[2],CONCAT44(uVar4,1));
      if ((((int)uVar2 != 0) &&
          (uVar2 = LogSystemEvent(param_1,0,0x8004af01,
                                  (byte *)
                                  "Error in freeing allocated default HTB in PostFwDiagBuffer",
                                  param_4,param_5), *(char *)(param_1 + 0x608) != '\0')) &&
         ((*(uint *)(param_1 + 0x60c) & 0x279) != 0)) {
        uVar2 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x279,
                            (undefined1 *)0x0,0,param_4,param_5);
      }
      *(undefined2 *)((longlong)param_2 + 0xf) = 0;
      param_2[2] = 0;
      param_2[0] = 0;
      param_2[1] = 0;
      *(undefined1 *)(param_1 + 0xbbc6) = 0;
      return uVar2 & 0xffffffffffffff00;
    }
    uStack_24 = (undefined4)((ulonglong)lVar1 >> 0x20);
    *(undefined4 *)(_Dst + 0x10) = uStack_24;
    *(int *)(_Dst + 0xc) = (int)lVar1;
  }
  QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x9ae) * 0x10000 + 8,0,param_4,param_5)
  ;
  uVar3 = LogSystemEvent(param_1,0,0x4004af00,(byte *)"Diag Buffer post command sent to FW",param_4,
                         param_5);
  *(undefined8 *)(param_1 + 0xbbb4) = 0;
  *(undefined8 *)(param_1 + 0xbbbc) = 0;
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== ProcessParseArgumentString @ 140015170 =====

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
  ulonglong uVar9;
  
  uVar9 = 0;
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
LAB_140015345:
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
        if (bVar2 == 0) goto LAB_140015345;
        bVar5 = bVar1;
        if (bVar2 == bVar1) {
          pbVar3 = param_2 + -(longlong)param_1;
          pbVar4 = param_1;
          do {
            param_1 = pbVar4 + 1;
            if (*pbVar4 == 0) goto LAB_140015345;
            bVar5 = pbVar3[(longlong)param_1];
            pbVar4 = param_1;
          } while (*param_1 == bVar5);
        }
        if (bVar5 == 0) break;
        do {
          bVar2 = *param_1;
          pbVar3 = (byte *)0x0;
          if (bVar2 == 0) goto LAB_140015345;
          param_1 = param_1 + 1;
        } while (bVar2 != 0x3b);
      }
      for (; (bVar2 = *param_1, bVar2 == 0x20 || (bVar2 == 9)); param_1 = param_1 + 1) {
      }
      if (bVar2 == 0x3d) break;
      do {
        bVar2 = *param_1;
        pbVar3 = (byte *)0x0;
        if (bVar2 == 0) goto LAB_140015345;
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
    if (bVar2 == 0) goto LAB_140015345;
    if (bVar2 != 0x3b) break;
    param_1 = pbVar4 + 2;
  }
  *param_3 = 0;
  bVar1 = *param_1;
  if ((bVar1 == 0x30) && (pbVar4[2] == 0x78)) {
    bVar1 = pbVar4[3];
    if (bVar1 != 0) {
      iVar6 = 0;
      while ((0x3b < bVar1 || ((0x800000100000200U >> ((ulonglong)bVar1 & 0x3f) & 1) == 0))) {
        if ((byte)(bVar1 - 0x30) < 10) {
          iVar6 = iVar6 * 0x10 + -0x30;
        }
        else {
          pbVar3 = (byte *)(ulonglong)(bVar1 - 0x61);
          if (5 < (byte)(bVar1 - 0x61)) goto LAB_140015345;
          iVar6 = iVar6 * 0x10 + -0x57;
        }
        uVar7 = (uint)(char)bVar1;
        pbVar3 = (byte *)(ulonglong)uVar7;
        uVar9 = (ulonglong)((int)uVar9 + 1);
        iVar6 = iVar6 + uVar7;
        *param_3 = iVar6;
        bVar1 = param_1[uVar9 + 2];
        if (bVar1 == 0) {
          return CONCAT71((uint7)(uint3)(uVar7 >> 8),1);
        }
      }
    }
  }
  else {
    while ((bVar1 != 0 &&
           ((0x3b < bVar1 || ((0x800000100000200U >> ((ulonglong)bVar1 & 0x3f) & 1) == 0))))) {
      pbVar3 = (byte *)(ulonglong)(bVar1 - 0x30);
      if (9 < (byte)(bVar1 - 0x30)) goto LAB_140015345;
      uVar9 = (ulonglong)((int)uVar9 + 1);
      pbVar3 = (byte *)(ulonglong)(uint)(int)(char)bVar1;
      *param_3 = (int)(char)bVar1 + (*param_3 * 5 + -0x18) * 2;
      bVar1 = param_1[uVar9];
    }
  }
  return CONCAT71((int7)((ulonglong)pbVar3 >> 8),1);
}



===== ProcessSsuReplies @ 140015360 =====

undefined8 ProcessSsuReplies(longlong param_1,byte param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  undefined8 uVar3;
  
  do {
    cVar2 = PollLSImpiIsr(param_1,param_2,param_3);
    StorPortStallExecution(500);
  } while (cVar2 != '\0');
  if ((uint)*(ushort *)(param_1 + 0xb666) < *(uint *)(param_1 + 0x9bc)) {
    uVar3 = 2;
  }
  else if (*(int *)(param_1 + 0xb65c) == 0) {
    uVar3 = 1;
  }
  else {
    piVar1 = (int *)(param_1 + 0xb660);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x80003) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80003,
                    (undefined1 *)(param_1 + 0xb65c),4,param_2,param_3);
      }
      uVar3 = 3;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== ProcessSynchronousAction @ 140015440 =====

undefined8 ProcessSynchronousAction(longlong param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  longlong *in_RAX;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  undefined8 *puVar9;
  ushort uVar10;
  int iVar11;
  ulonglong uVar12;
  longlong lVar13;
  short sVar14;
  short local_res8;
  
  uVar8 = *(uint *)(param_1 + 0x9c0);
  iVar2 = *param_2;
  bVar1 = *(byte *)(param_2 + 1);
  uVar7 = uVar8;
  if ((uVar8 & 1) != 0) {
    uVar12 = (ulonglong)*(byte *)(param_1 + 0x10f5);
    iVar11 = *(int *)(param_1 + 0xab4 + uVar12 * 4);
    if (iVar11 != 0) {
      do {
        QueueRequestDescriptor
                  (param_1,iVar11,*(undefined4 *)(param_1 + 0xdd4 + uVar12 * 4),bVar1,iVar2);
        *(undefined4 *)(param_1 + 0xab4 + uVar12 * 4) = 0;
        uVar5 = (int)uVar12 + 1;
        in_RAX = (longlong *)(ulonglong)uVar5;
        *(undefined4 *)(param_1 + 0xdd4 + uVar12 * 4) = 0;
        uVar7 = 0;
        if ((char)uVar12 != -0x39) {
          uVar7 = uVar5;
        }
        uVar12 = (ulonglong)(uVar7 & 0xff);
        *(char *)(param_1 + 0x10f5) = (char)uVar7;
        iVar11 = *(int *)(param_1 + 0xab4 + uVar12 * 4);
      } while (iVar11 != 0);
      uVar7 = *(uint *)(param_1 + 0x9c0);
    }
    uVar7 = uVar7 & 0xfffffffe;
    *(uint *)(param_1 + 0x9c0) = uVar7;
  }
  if ((uVar8 & 2) != 0) {
    uVar12 = (ulonglong)*(byte *)(param_1 + 0x10f7);
    sVar14 = *(short *)(param_1 + 0x10f8 + uVar12 * 8);
    if (sVar14 != 0) {
      do {
        if (*(char *)(param_1 + 0xbbd0) == '\0') {
          uVar10 = 0;
          do {
            while( true ) {
              uVar8 = *(uint *)(*(longlong *)(param_1 + 0xaa8) + (ulonglong)uVar10 * 4);
              uVar7 = 0;
              if (uVar8 != 0) {
                for (; (uVar8 >> uVar7 & 1) == 0; uVar7 = uVar7 + 1) {
                }
              }
              if (uVar8 != 0) break;
              uVar10 = uVar10 + 1;
              in_RAX = (longlong *)(ulonglong)uVar10;
              if ((ushort)((*(ushort *)(param_1 + 0x998) >> 5) + 1) < uVar10) goto LAB_140015675;
            }
            LOCK();
            pbVar3 = (byte *)(*(longlong *)(param_1 + 0xaa8) + (ulonglong)uVar10 * 4 +
                             ((longlong)(int)uVar7 >> 3));
            bVar4 = *pbVar3;
            *pbVar3 = *pbVar3 & ~('\x01' << (uVar7 & 7));
            UNLOCK();
          } while ((bVar4 >> (uVar7 & 7) & 1) == 0);
          local_res8 = (short)uVar7;
          uVar10 = uVar10 * 0x20 + local_res8;
          if (*(ushort *)(param_1 + 0x998) < uVar10) {
            in_RAX = *(longlong **)(param_1 + 0xaa8);
            LOCK();
            pbVar3 = (byte *)((longlong)in_RAX +
                             ((longlong)(int)(uVar10 & 0x1f) >> 3) + (ulonglong)(uVar10 >> 5) * 4);
            *pbVar3 = *pbVar3 | '\x01' << (uVar10 & 7);
            UNLOCK();
            goto LAB_140015675;
          }
          lVar13 = (ulonglong)uVar10 * 0x20 + *(longlong *)(param_1 + 0x598);
        }
        else {
          in_RAX = *(longlong **)(param_1 + 0x910);
          lVar13 = *in_RAX;
          if (*(longlong *)(lVar13 + 8) != 0) goto LAB_140015675;
          lVar6 = *(longlong *)(param_1 + 0x910) + 8;
          *(longlong *)(param_1 + 0x910) = lVar6;
          if (lVar6 == *(longlong *)(param_1 + 0x920)) {
            *(undefined8 *)(param_1 + 0x910) = *(undefined8 *)(param_1 + 0x908);
          }
        }
        uVar10 = *(ushort *)(lVar13 + 0x10);
        *(undefined8 *)(lVar13 + 8) = 0xdeadbeef;
        *(undefined1 *)(lVar13 + 0x13) = 2;
        puVar9 = (undefined8 *)
                 ((longlong)(int)((uint)*(ushort *)(param_1 + 0x534) * (uint)uVar10) +
                 *(longlong *)(param_1 + 0x558));
        *puVar9 = 0;
        puVar9[1] = 0;
        *(undefined4 *)(puVar9 + 2) = 0;
        *(short *)((longlong)puVar9 + 0xc) = sVar14;
        *(undefined1 *)((longlong)puVar9 + 3) = 8;
        *(undefined4 *)(puVar9 + 2) = *(undefined4 *)(param_1 + 0x10fc + uVar12 * 8);
        QueueRequestDescriptor(param_1,(uint)uVar10 * 0x10000 + 8,0,bVar1,iVar2);
        *(undefined2 *)(param_1 + 0x10f8 + uVar12 * 8) = 0;
        uVar7 = (int)uVar12 + 1;
        in_RAX = (longlong *)(ulonglong)uVar7;
        uVar8 = 0;
        if ((char)uVar12 != '\t') {
          uVar8 = uVar7;
        }
        uVar12 = (ulonglong)(uVar8 & 0xff);
        *(char *)(param_1 + 0x10f7) = (char)uVar8;
        sVar14 = *(short *)(param_1 + 0x10f8 + uVar12 * 8);
      } while (sVar14 != 0);
      uVar7 = *(uint *)(param_1 + 0x9c0);
    }
    *(uint *)(param_1 + 0x9c0) = uVar7 & 0xfffffffd;
  }
LAB_140015675:
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== QueueRequestDescriptor @ 1400156b0 =====

void QueueRequestDescriptor
               (longlong param_1,undefined4 param_2,undefined4 param_3,byte param_4,int param_5)

{
  byte bVar1;
  ulonglong uVar2;
  char cVar3;
  
  if (*(char *)(param_1 + 0x11d7) != '\0') {
    if (*(char *)(param_1 + 0xbbc5) == '\0') {
      **(undefined8 **)(param_1 + 0xe8) = CONCAT44(param_3,param_2);
      LOCK();
      UNLOCK();
      return;
    }
    **(undefined4 **)(param_1 + 0xf8) = param_2;
    LOCK();
    UNLOCK();
    return;
  }
  bVar1 = *(byte *)(param_1 + 0x10f4);
  uVar2 = (ulonglong)bVar1;
  if (*(int *)(param_1 + 0xab4 + uVar2 * 4) == 0) {
    *(undefined4 *)(param_1 + 0xab4 + uVar2 * 4) = param_2;
    *(undefined4 *)(param_1 + 0xdd4 + uVar2 * 4) = param_3;
    cVar3 = '\0';
    if (bVar1 != 199) {
      cVar3 = bVar1 + 1;
    }
    *(uint *)(param_1 + 0x9c0) = *(uint *)(param_1 + 0x9c0) | 1;
    *(char *)(param_1 + 0x10f4) = cVar3;
    if (*(char *)(param_1 + 0x1211) == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00014001577b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      StorPortNotification(6,param_1,WatchdogTimer,10000);
      return;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1218) = 1;
    if (*(int *)(param_1 + 0x970) == 0) {
      PauseAdapterQueue(param_1,0x15,param_4,param_5);
    }
    *(undefined2 *)(param_1 + 0x1214) = 0;
    LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                        "Diag Reset(miniport)-Request descriptor queue is full",param_4,param_5);
    KickStart(param_1,param_4,param_5);
  }
  return;
}



===== ReadAndSetSASPages @ 140015810 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ReadAndSetSASPages(longlong param_1,byte param_2,int param_3)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  bool bVar5;
  char cVar6;
  ushort uVar7;
  int iVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined4 uVar11;
  char cVar12;
  uint uVar13;
  uint uVar14;
  char *pcVar15;
  ushort local_res8;
  ushort local_res20;
  undefined4 local_48;
  undefined1 local_40 [8];
  
  cVar12 = '\x01';
  local_res20 = local_res8;
  do {
    bVar5 = true;
    switch(cVar12) {
    case '\x01':
      cVar12 = '\x02';
      bVar5 = false;
      goto LAB_140016973;
    case '\x02':
      local_48 = 0x1010000;
      cVar12 = '\x03';
      goto LAB_1400158b0;
    case '\x03':
      cVar12 = '\x1c';
      goto LAB_140015918;
    case '\x04':
      local_48 = 0x1080000;
      cVar12 = '\x05';
      goto LAB_1400158b0;
    case '\x05':
      cVar12 = '\x06';
      goto LAB_140015918;
    case '\x06':
      lVar9 = *(longlong *)(param_1 + 0x1860);
      *(undefined1 *)(param_1 + 0x18b8) = *(undefined1 *)(lVar9 + 4);
      *(undefined2 *)(param_1 + 0x18be) = *(undefined2 *)(lVar9 + 10);
      *(undefined2 *)(param_1 + 0x18c0) = *(undefined2 *)(lVar9 + 0xc);
      if (*(short *)(param_1 + 0x18bc) == 0) {
        *(undefined2 *)(param_1 + 0x18bc) = *(undefined2 *)(lVar9 + 8);
      }
      if ((*(uint *)(param_1 + 0x120c) & 4) != 0) {
        cVar12 = '\a';
        local_48 = 0x10000;
        goto LAB_1400158b0;
      }
      cVar12 = '\t';
      bVar5 = false;
      goto LAB_140016973;
    case '\a':
      cVar12 = '\b';
      goto LAB_140015918;
    case '\b':
      uVar13 = *(uint *)(param_1 + 0x1868);
      cVar12 = '\t';
      if (*(char *)(param_1 + 0x120b) == '\0') {
        puVar1 = (uint *)(*(longlong *)(param_1 + 0x1860) + 4);
        *puVar1 = *puVar1 | 0x20;
      }
      else {
        puVar1 = (uint *)(*(longlong *)(param_1 + 0x1860) + 4);
        *puVar1 = *puVar1 & 0xffffffdf;
      }
      uVar4 = *(undefined8 *)(param_1 + 0x1860);
      uVar7 = *(ushort *)(param_1 + 0x9b0);
      puVar10 = *(undefined8 **)(param_1 + 0x560);
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined4 *)((longlong)puVar10 + 0x1c) = 0xd3000000;
      *(undefined1 *)puVar10 = 2;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(uint *)((longlong)puVar10 + 0x14) = uVar13;
      iVar8 = *(int *)(param_1 + 0x108);
      uVar13 = (uVar13 >> 8 & 0xff) << 2;
      *(uint *)((longlong)puVar10 + 0x1c) = uVar13 | 0xd3000000;
      *(int *)(puVar10 + 4) = (int)uVar4 - iVar8;
      uVar14 = (uint)uVar7;
      uVar11 = *(undefined4 *)(param_1 + 500);
      *(uint *)((longlong)puVar10 + 0x1c) = uVar13 | 0xd7000000;
      *(undefined4 *)((longlong)puVar10 + 0x24) = uVar11;
      goto LAB_1400158f8;
    case '\t':
      cVar12 = '\n';
      local_48 = 0x2030000;
      goto LAB_1400158b0;
    case '\n':
      cVar12 = '\f';
      goto LAB_140015918;
    default:
switchD_140015896_caseD_b:
      *(undefined1 *)(param_1 + 0x121d) = 0;
      return;
    case '\f':
      cVar12 = '\r';
      local_48 = 0x9000000;
      *(undefined4 *)(param_1 + 0x1168) = *(undefined4 *)(*(longlong *)(param_1 + 0x1860) + 8);
      goto LAB_1400158b0;
    case '\r':
      uVar13 = *(uint *)(param_1 + 0x1868);
      lVar9 = *(longlong *)(param_1 + 0x1900);
      if (lVar9 == 0) {
        uVar7 = ((ushort)(uVar13 >> 8) & 0xff) << 2;
        if (*(uint *)(param_1 + 0x185c) < (uint)uVar7) goto switchD_140015896_caseD_b;
        lVar9 = *(longlong *)(param_1 + 0x1860);
        *(longlong *)(param_1 + 0x1900) = lVar9;
        *(ulonglong *)(param_1 + 0x1860) = (ulonglong)uVar7 + lVar9;
        *(uint *)(param_1 + 0x185c) = *(uint *)(param_1 + 0x185c) - (uint)uVar7;
      }
      puVar10 = *(undefined8 **)(param_1 + 0x560);
      uVar7 = *(ushort *)(param_1 + 0x9b0);
      cVar12 = '\x0e';
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(uint *)((longlong)puVar10 + 0x14) = uVar13;
      *(undefined4 *)((longlong)puVar10 + 0x1c) = 0xd3000000;
      *(undefined1 *)puVar10 = 6;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      iVar8 = *(int *)(param_1 + 0x108);
      *(uint *)((longlong)puVar10 + 0x1c) = (uVar13 >> 8 & 0xff) << 2 | 0xd3000000;
      *(int *)(puVar10 + 4) = (int)lVar9 - iVar8;
      goto LAB_1400158ef;
    case '\x0e':
      if (*(short *)(param_1 + 0x185a) != 0x23) {
        memmove((void *)(param_1 + 0x1974),(void *)(*(longlong *)(param_1 + 0x1900) + 0x3c),0x10);
      }
      cVar12 = '\x0f';
      local_48 = 0x9050000;
      goto LAB_1400158b0;
    case '\x0f':
      puVar10 = *(undefined8 **)(param_1 + 0x560);
      uVar13 = *(uint *)(param_1 + 0x1868);
      iVar8 = (int)*(undefined8 *)(param_1 + 0x1860);
      cVar12 = '\x1a';
      uVar7 = *(ushort *)(param_1 + 0x9b0);
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)puVar10 = 6;
      goto LAB_14001594d;
    case '\x10':
      lVar9 = *(longlong *)(param_1 + 0x1860);
      *(byte *)(param_1 + 0x18b0) = *(byte *)(lVar9 + 0x2c) >> 4 & 1;
      *(undefined1 *)(param_1 + 0xb9e9) = *(undefined1 *)(lVar9 + 0x4e);
      *(undefined1 *)(param_1 + 0xb9ea) = *(undefined1 *)(lVar9 + 0x4f);
      *(undefined2 *)(param_1 + 0xb9ec) = *(undefined2 *)(lVar9 + 0x50);
      *(undefined2 *)(param_1 + 0xb9ee) = *(undefined2 *)(lVar9 + 0x52);
      *(undefined1 *)(param_1 + 0xbbda) = *(undefined1 *)(lVar9 + 0x54);
      *(undefined4 *)(param_1 + 0xb9f0) = 0;
      bVar2 = *(byte *)(lVar9 + 0x55);
      if (bVar2 != 0) {
        if ((char)bVar2 < '\0') {
          iVar8 = (bVar2 & 0x7f) * 0xe10;
        }
        else {
          iVar8 = (bVar2 & 0x7f) * 0x3c;
        }
        *(int *)(param_1 + 0xb9f0) = iVar8;
      }
      cVar12 = '\x11';
      if (((local_40 == (undefined1 *)(param_1 + 0x1920)) ||
          (local_40 == (undefined1 *)(param_1 + 0x1940))) ||
         ((local_40 == (undefined1 *)(param_1 + 0x1950) ||
          ((local_40 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01')))
          ))) {
        puVar10 = *(undefined8 **)(param_1 + 0x570);
        uVar7 = *(ushort *)(param_1 + 0x9b4);
        iVar8 = *(int *)(param_1 + 0x20c);
      }
      else {
        puVar10 = *(undefined8 **)(param_1 + 0x560);
        uVar7 = *(ushort *)(param_1 + 0x9b0);
        iVar8 = *(int *)(param_1 + 0x204);
      }
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)((longlong)puVar10 + 0x17) = 0xf;
      goto LAB_140015edd;
    case '\x11':
      if (*(longlong *)(param_1 + 0x19c8) == 0) {
        uVar7 = *(short *)(param_1 + 0x19a4) << 2;
        if (*(uint *)(param_1 + 0x185c) < (uint)uVar7) goto switchD_140015896_caseD_b;
        *(longlong *)(param_1 + 0x19c8) = *(longlong *)(param_1 + 0x1860);
        *(ulonglong *)(param_1 + 0x1860) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1860);
        *(uint *)(param_1 + 0x185c) = *(uint *)(param_1 + 0x185c) - (uint)uVar7;
      }
      cVar12 = '\x12';
      if ((((local_40 == (undefined1 *)(param_1 + 0x1920)) ||
           (local_40 == (undefined1 *)(param_1 + 0x1940))) ||
          (local_40 == (undefined1 *)(param_1 + 0x1950))) ||
         ((local_40 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01'))))
      {
        puVar10 = *(undefined8 **)(param_1 + 0x570);
        uVar7 = *(ushort *)(param_1 + 0x9b4);
        iVar8 = *(int *)(param_1 + 0x20c);
      }
      else {
        puVar10 = *(undefined8 **)(param_1 + 0x560);
        uVar7 = *(ushort *)(param_1 + 0x9b0);
        iVar8 = *(int *)(param_1 + 0x204);
      }
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined2 *)((longlong)puVar10 + 0x16) = 0xf01;
      *(undefined2 *)((longlong)puVar10 + 4) = 0;
LAB_140015edd:
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(undefined1 *)((longlong)puVar10 + 6) = 0x10;
      break;
    case '\x12':
      if (*(longlong *)(param_1 + 0x19d0) == 0) {
        uVar7 = *(short *)(param_1 + 0x19ac) << 2;
        if (*(uint *)(param_1 + 0x185c) < (uint)uVar7) goto switchD_140015896_caseD_b;
        *(longlong *)(param_1 + 0x19d0) = *(longlong *)(param_1 + 0x1860);
        *(ulonglong *)(param_1 + 0x1860) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1860);
        *(uint *)(param_1 + 0x185c) = *(uint *)(param_1 + 0x185c) - (uint)uVar7;
      }
      cVar12 = '\x13';
      if (((local_40 == (undefined1 *)(param_1 + 0x1920)) ||
          (local_40 == (undefined1 *)(param_1 + 0x1940))) ||
         ((local_40 == (undefined1 *)(param_1 + 0x1950) ||
          ((local_40 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01')))
          ))) {
        puVar10 = *(undefined8 **)(param_1 + 0x570);
        uVar7 = *(ushort *)(param_1 + 0x9b4);
        iVar8 = *(int *)(param_1 + 0x20c);
      }
      else {
        puVar10 = *(undefined8 **)(param_1 + 0x560);
        uVar7 = *(ushort *)(param_1 + 0x9b0);
        iVar8 = *(int *)(param_1 + 0x204);
      }
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(undefined1 *)((longlong)puVar10 + 0x17) = 0xf;
      *(undefined1 *)((longlong)puVar10 + 6) = 0x12;
      break;
    case '\x13':
      if (*(longlong *)(param_1 + 0x1928) == 0) {
        uVar7 = *(short *)(param_1 + 0x1924) << 2;
        if (*(uint *)(param_1 + 0x185c) < (uint)uVar7) goto switchD_140015896_caseD_b;
        *(longlong *)(param_1 + 0x1928) = *(longlong *)(param_1 + 0x1860);
        *(ulonglong *)(param_1 + 0x1860) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1860);
        *(uint *)(param_1 + 0x185c) = *(uint *)(param_1 + 0x185c) - (uint)uVar7;
      }
      cVar12 = '\x14';
      if (*(char *)(param_1 + 0x11e7) == '\0') {
        cVar12 = '\x16';
      }
      if ((((local_40 == (undefined1 *)(param_1 + 0x1920)) ||
           (local_40 == (undefined1 *)(param_1 + 0x1940))) ||
          (local_40 == (undefined1 *)(param_1 + 0x1950))) ||
         ((local_40 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01'))))
      {
        puVar10 = *(undefined8 **)(param_1 + 0x570);
        uVar7 = *(ushort *)(param_1 + 0x9b4);
        iVar8 = *(int *)(param_1 + 0x20c);
      }
      else {
        puVar10 = *(undefined8 **)(param_1 + 0x560);
        uVar7 = *(ushort *)(param_1 + 0x9b0);
        iVar8 = *(int *)(param_1 + 0x204);
      }
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(undefined2 *)((longlong)puVar10 + 0x16) = 0xf01;
      *(undefined2 *)((longlong)puVar10 + 4) = 0;
      *(undefined1 *)((longlong)puVar10 + 6) = 0x12;
      break;
    case '\x14':
      if (*(longlong *)(param_1 + 0x19d8) == 0) {
        uVar7 = *(short *)(param_1 + 0x19b4) << 2;
        if (*(uint *)(param_1 + 0x185c) < (uint)uVar7) goto switchD_140015896_caseD_b;
        *(longlong *)(param_1 + 0x19d8) = *(longlong *)(param_1 + 0x1860);
        *(ulonglong *)(param_1 + 0x1860) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1860);
        *(uint *)(param_1 + 0x185c) = *(uint *)(param_1 + 0x185c) - (uint)uVar7;
      }
      cVar12 = '\x15';
      if (((local_40 == (undefined1 *)(param_1 + 0x1920)) ||
          (local_40 == (undefined1 *)(param_1 + 0x1940))) ||
         ((local_40 == (undefined1 *)(param_1 + 0x1950) ||
          ((local_40 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01')))
          ))) {
        puVar10 = *(undefined8 **)(param_1 + 0x570);
        uVar7 = *(ushort *)(param_1 + 0x9b4);
        iVar8 = *(int *)(param_1 + 0x20c);
      }
      else {
        puVar10 = *(undefined8 **)(param_1 + 0x560);
        uVar7 = *(ushort *)(param_1 + 0x9b0);
        iVar8 = *(int *)(param_1 + 0x204);
      }
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(undefined1 *)((longlong)puVar10 + 0x17) = 0xf;
      *(undefined1 *)((longlong)puVar10 + 6) = 0x1d;
      break;
    case '\x15':
      if (*(longlong *)(param_1 + 0x1948) == 0) {
        uVar7 = *(short *)(param_1 + 0x1944) << 2;
        if (*(uint *)(param_1 + 0x185c) < (uint)uVar7) goto switchD_140015896_caseD_b;
        *(longlong *)(param_1 + 0x1948) = *(longlong *)(param_1 + 0x1860);
        *(ulonglong *)(param_1 + 0x1860) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1860);
        *(uint *)(param_1 + 0x185c) = *(uint *)(param_1 + 0x185c) - (uint)uVar7;
      }
      cVar12 = '\x16';
      if ((((local_40 == (undefined1 *)(param_1 + 0x1920)) ||
           (local_40 == (undefined1 *)(param_1 + 0x1940))) ||
          (local_40 == (undefined1 *)(param_1 + 0x1950))) ||
         ((local_40 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01'))))
      {
        puVar10 = *(undefined8 **)(param_1 + 0x570);
        uVar7 = *(ushort *)(param_1 + 0x9b4);
        iVar8 = *(int *)(param_1 + 0x20c);
      }
      else {
        puVar10 = *(undefined8 **)(param_1 + 0x560);
        uVar7 = *(ushort *)(param_1 + 0x9b0);
        iVar8 = *(int *)(param_1 + 0x204);
      }
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(undefined2 *)((longlong)puVar10 + 0x16) = 0xf02;
      *(undefined2 *)((longlong)puVar10 + 4) = 0;
      *(undefined1 *)((longlong)puVar10 + 6) = 0x1d;
      break;
    case '\x16':
      if (*(char *)(param_1 + 0x11e7) == '\0') {
        if (*(longlong *)(param_1 + 0x19d8) == 0) {
          uVar13 = *(uint *)(param_1 + 0x185c);
          uVar7 = *(short *)(param_1 + 0x19b4) << 2;
          if (uVar7 <= uVar13) {
            lVar9 = *(longlong *)(param_1 + 0x1860);
            *(longlong *)(param_1 + 0x19d8) = lVar9;
            goto LAB_140016469;
          }
          goto switchD_140015896_caseD_b;
        }
      }
      else if (*(longlong *)(param_1 + 0x1958) == 0) {
        uVar13 = *(uint *)(param_1 + 0x185c);
        uVar7 = *(short *)(param_1 + 0x1954) << 2;
        if (uVar13 < uVar7) goto switchD_140015896_caseD_b;
        lVar9 = *(longlong *)(param_1 + 0x1860);
        *(longlong *)(param_1 + 0x1958) = lVar9;
LAB_140016469:
        *(ulonglong *)(param_1 + 0x1860) = (ulonglong)uVar7 + lVar9;
        *(uint *)(param_1 + 0x185c) = uVar13 - uVar7;
      }
      cVar12 = '\x17';
      if (((local_40 == (undefined1 *)(param_1 + 0x1920)) ||
          (local_40 == (undefined1 *)(param_1 + 0x1940))) ||
         ((local_40 == (undefined1 *)(param_1 + 0x1950) ||
          ((local_40 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01')))
          ))) {
        puVar10 = *(undefined8 **)(param_1 + 0x570);
        uVar7 = *(ushort *)(param_1 + 0x9b4);
        iVar8 = *(int *)(param_1 + 0x20c);
      }
      else {
        puVar10 = *(undefined8 **)(param_1 + 0x560);
        uVar7 = *(ushort *)(param_1 + 0x9b0);
        iVar8 = *(int *)(param_1 + 0x204);
      }
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(undefined1 *)((longlong)puVar10 + 0x17) = 0xf;
      *(undefined1 *)((longlong)puVar10 + 6) = 0x13;
      break;
    case '\x17':
      if (*(longlong *)(param_1 + 0x19e0) == 0) {
        uVar7 = *(short *)(param_1 + 0x19bc) << 2;
        if (*(uint *)(param_1 + 0x185c) < (uint)uVar7) goto switchD_140015896_caseD_b;
        *(longlong *)(param_1 + 0x19e0) = *(longlong *)(param_1 + 0x1860);
        *(ulonglong *)(param_1 + 0x1860) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1860);
        *(uint *)(param_1 + 0x185c) = *(uint *)(param_1 + 0x185c) - (uint)uVar7;
      }
      cVar12 = '\x18';
      if ((((local_40 == (undefined1 *)(param_1 + 0x1920)) ||
           (local_40 == (undefined1 *)(param_1 + 0x1940))) ||
          (local_40 == (undefined1 *)(param_1 + 0x1950))) ||
         ((local_40 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01'))))
      {
        puVar10 = *(undefined8 **)(param_1 + 0x570);
        uVar7 = *(ushort *)(param_1 + 0x9b4);
        iVar8 = *(int *)(param_1 + 0x20c);
      }
      else {
        puVar10 = *(undefined8 **)(param_1 + 0x560);
        uVar7 = *(ushort *)(param_1 + 0x9b0);
        iVar8 = *(int *)(param_1 + 0x204);
      }
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(undefined2 *)((longlong)puVar10 + 0x16) = 0xf01;
      *(undefined2 *)((longlong)puVar10 + 4) = 0;
      *(undefined1 *)((longlong)puVar10 + 6) = 0x13;
      break;
    case '\x18':
      if (*(longlong *)(param_1 + 0x19e8) == 0) {
        uVar7 = *(short *)(param_1 + 0x19c4) << 2;
        if (*(uint *)(param_1 + 0x185c) < (uint)uVar7) goto switchD_140015896_caseD_b;
        *(longlong *)(param_1 + 0x19e8) = *(longlong *)(param_1 + 0x1860);
        *(ulonglong *)(param_1 + 0x1860) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1860);
        *(uint *)(param_1 + 0x185c) = *(uint *)(param_1 + 0x185c) - (uint)uVar7;
      }
      cVar12 = '\x1d';
      if (((local_40 == (undefined1 *)(param_1 + 0x1920)) ||
          (local_40 == (undefined1 *)(param_1 + 0x1940))) ||
         ((local_40 == (undefined1 *)(param_1 + 0x1950) ||
          ((local_40 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01')))
          ))) {
        puVar10 = *(undefined8 **)(param_1 + 0x570);
        uVar7 = *(ushort *)(param_1 + 0x9b4);
        iVar8 = *(int *)(param_1 + 0x20c);
      }
      else {
        puVar10 = *(undefined8 **)(param_1 + 0x560);
        uVar7 = *(ushort *)(param_1 + 0x9b0);
        iVar8 = *(int *)(param_1 + 0x204);
      }
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(undefined1 *)((longlong)puVar10 + 0x17) = 0xf;
      *(undefined1 *)((longlong)puVar10 + 6) = 0x15;
      break;
    case '\x19':
      uVar7 = *(ushort *)(param_1 + 0x185a);
      if (uVar7 != 0) {
        LogSystemEvent(param_1,(uint)uVar7,0x4004af00,
                       (byte *)"Driver Trigger Persistency feature unsupported, IOCStatus logged",
                       param_2,param_3);
      }
      *(bool *)(param_1 + 0xb7ed) = uVar7 == 0;
      if ((*(byte *)(param_1 + 0x18c0) & 1) == 0) {
        local_res8 = 0;
        cVar12 = -0x10;
        if ((((local_40 == (undefined1 *)(param_1 + 0x1920)) ||
             (local_40 == (undefined1 *)(param_1 + 0x1940))) ||
            (local_40 == (undefined1 *)(param_1 + 0x1950))) ||
           ((local_40 == (undefined1 *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01'))
           )) {
          puVar10 = *(undefined8 **)(param_1 + 0x570);
          uVar7 = *(ushort *)(param_1 + 0x9b4);
          iVar8 = *(int *)(param_1 + 0x20c);
        }
        else {
          puVar10 = *(undefined8 **)(param_1 + 0x560);
          uVar7 = *(ushort *)(param_1 + 0x9b0);
          iVar8 = *(int *)(param_1 + 0x204);
        }
        *(undefined1 *)(param_1 + 0x9ba) = 0;
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10[3] = 0;
        puVar10[4] = 0;
        *(undefined4 *)(puVar10 + 5) = 0;
        *(undefined1 *)((longlong)puVar10 + 3) = 4;
        *(undefined1 *)((longlong)puVar10 + 0x17) = 0xf;
        *(undefined1 *)((longlong)puVar10 + 6) = 0x17;
        break;
      }
      LogSystemEvent(param_1,0,0x8004af01,(byte *)"Persistency is disabled in IOCPage8",param_2,
                     param_3);
      bVar5 = false;
      cVar12 = -0xf;
      goto LAB_140016973;
    case '\x1a':
      cVar12 = '\x1b';
      local_48 = 0x90b0000;
      *(undefined4 *)(param_1 + 0x1874) = *(undefined4 *)(*(longlong *)(param_1 + 0x1860) + 0x10);
      *(undefined4 *)(param_1 + 0x1878) = *(undefined4 *)(*(longlong *)(param_1 + 0x1860) + 0x14);
LAB_1400158b0:
      puVar10 = *(undefined8 **)(param_1 + 0x560);
      uVar7 = *(ushort *)(param_1 + 0x9b0);
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(undefined4 *)((longlong)puVar10 + 0x14) = local_48;
      *(undefined4 *)((longlong)puVar10 + 0x1c) = 0xd3000000;
      *(int *)(puVar10 + 4) = *(int *)(param_1 + 0x204) + 0x2c;
LAB_1400158ef:
      uVar14 = (uint)uVar7;
      *(undefined4 *)((longlong)puVar10 + 0x24) = *(undefined4 *)(param_1 + 500);
LAB_1400158f8:
      QueueRequestDescriptor(param_1,uVar14 * 0x10000 + 8,0,param_2,param_3);
      goto LAB_140016973;
    case '\x1b':
      cVar12 = '\x10';
LAB_140015918:
      puVar10 = *(undefined8 **)(param_1 + 0x560);
      uVar13 = *(uint *)(param_1 + 0x1868);
      iVar8 = (int)*(undefined8 *)(param_1 + 0x1860);
      uVar7 = *(ushort *)(param_1 + 0x9b0);
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      *(undefined4 *)(puVar10 + 5) = 0;
      *(undefined1 *)puVar10 = 1;
LAB_14001594d:
      uVar14 = (uint)uVar7;
      *(undefined1 *)((longlong)puVar10 + 3) = 4;
      *(uint *)((longlong)puVar10 + 0x14) = uVar13;
      *(undefined4 *)((longlong)puVar10 + 0x1c) = 0xd3000000;
      iVar3 = *(int *)(param_1 + 0x108);
      *(uint *)((longlong)puVar10 + 0x1c) = (uVar13 >> 8 & 0xff) << 2 | 0xd3000000;
      *(int *)(puVar10 + 4) = iVar8 - iVar3;
      *(undefined4 *)((longlong)puVar10 + 0x24) = *(undefined4 *)(param_1 + 500);
      goto LAB_1400158f8;
    case '\x1c':
      lVar9 = *(longlong *)(param_1 + 0x1860);
      uVar13 = *(uint *)(param_1 + 0x1868);
      uVar7 = (ushort)*(byte *)(lVar9 + 0xd);
      if (*(byte *)(lVar9 + 0xd) == 0xff) {
        uVar7 = 0xffff;
      }
      *(ushort *)(param_1 + 0x1960) = uVar7;
      if (*(char *)(param_1 + 0xbbc4) == '\0') {
        bVar5 = false;
        cVar12 = '\x04';
      }
      else {
        if ((*(uint *)(lVar9 + 4) & 1) == 0) {
          *(undefined4 *)(lVar9 + 0x14) = 0;
          *(undefined4 *)(lVar9 + 8) = 0;
          pcVar15 = "Int coalescing is not enabled in FW";
          *(undefined1 *)(lVar9 + 0xc) = 0;
          uVar11 = 0;
          *(undefined1 *)(param_1 + 0xba00) = 0;
          *(undefined1 *)(param_1 + 0xbbd0) = 0;
LAB_140015a64:
          LogSystemEvent(param_1,uVar11,0x4004af00,(byte *)pcVar15,param_2,param_3);
        }
        else {
          iVar8 = *(int *)(param_1 + 0xbbd4);
          if (iVar8 == 0) {
            if (*(char *)(param_1 + 0xba00) == '\0') {
              *(undefined4 *)(param_1 + 0xbbd4) = 2;
LAB_140015a28:
              *(undefined4 *)(lVar9 + 0x14) = 0;
              pcVar15 = "LATENCY Perf Mode:IOC page1 CoalescingTimeout is logged";
              *(undefined4 *)(lVar9 + 8) = 10;
              uVar11 = 10;
            }
            else {
              pcVar15 = "Balanced Perf Mode:IOC page1 CoalescingTimeout is logged";
              *(uint *)(lVar9 + 0x14) =
                   (1 << ((byte)*(undefined4 *)(param_1 + 0xba04) & 0x1f)) - 1U | 0x80000000;
              uVar11 = *(undefined4 *)(lVar9 + 8);
            }
            goto LAB_140015a64;
          }
          if (iVar8 == 1) {
            *(undefined4 *)(lVar9 + 0x14) = 0;
            pcVar15 = "IOPS Perf Mode:IOC page1 CoalescingTimeout is logged";
            uVar11 = *(undefined4 *)(lVar9 + 8);
            goto LAB_140015a64;
          }
          if (iVar8 == 2) goto LAB_140015a28;
        }
        uVar7 = *(ushort *)(param_1 + 0x9b0);
        puVar10 = *(undefined8 **)(param_1 + 0x560);
        uVar4 = *(undefined8 *)(param_1 + 0x1860);
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10[3] = 0;
        puVar10[4] = 0;
        *(undefined4 *)(puVar10 + 5) = 0;
        *(undefined4 *)((longlong)puVar10 + 0x1c) = 0xd3000000;
        *(undefined1 *)puVar10 = 2;
        *(undefined1 *)((longlong)puVar10 + 3) = 4;
        *(uint *)((longlong)puVar10 + 0x14) = uVar13;
        iVar8 = *(int *)(param_1 + 0x108);
        uVar13 = (uVar13 >> 8 & 0xff) << 2;
        *(uint *)((longlong)puVar10 + 0x1c) = uVar13 | 0xd3000000;
        *(int *)(puVar10 + 4) = (int)uVar4 - iVar8;
        uVar11 = *(undefined4 *)(param_1 + 500);
        *(uint *)((longlong)puVar10 + 0x1c) = uVar13 | 0xd7000000;
        *(undefined4 *)((longlong)puVar10 + 0x24) = uVar11;
        QueueRequestDescriptor(param_1,(uint)uVar7 * 0x10000 + 8,0,param_2,param_3);
        cVar12 = '\x04';
      }
      goto LAB_140016973;
    case '\x1d':
      if (*(longlong *)(param_1 + 0x1938) == 0) {
        uVar7 = *(short *)(param_1 + 0x1934) << 2;
        if (*(uint *)(param_1 + 0x185c) < (uint)uVar7) goto switchD_140015896_caseD_b;
        *(longlong *)(param_1 + 0x1938) = *(longlong *)(param_1 + 0x1860);
        *(ulonglong *)(param_1 + 0x1860) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1860);
        *(uint *)(param_1 + 0x185c) = *(uint *)(param_1 + 0x185c) - (uint)uVar7;
      }
      cVar12 = '\x19';
      GetDriverTriggerPageHeader(param_1,0,param_2,param_3);
      goto LAB_140016973;
    case -0x10:
      if ((char)local_res8 == '\0') {
        local_res20 = *(ushort *)(param_1 + 0x190c);
      }
      *(ushort *)(param_1 + 0x190c) = (ushort)(*(short *)(param_1 + 0x18bc) * 0x14 + 8U) >> 2;
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      if ((char)local_res8 == '\0') {
LAB_140016945:
        local_res8 = (ushort)(byte)((char)local_res8 + 1);
        SendExtendedConfigPageMessage
                  (param_1,'\x06',(char *)(param_1 + 0x1908),
                   (uint)*(ushort *)(param_1 + 0x18bc) << 0x10,
                   (int)*(undefined8 *)(param_1 + 0x1910),param_2,param_3);
      }
      else if (*(short *)(param_1 + 0x185a) == 0) {
        bVar5 = false;
        *(ushort *)(param_1 + 0x190c) = local_res20 + 5;
        cVar12 = -0xf;
      }
      else {
        if ((char)local_res8 != '\x02') goto LAB_140016945;
        *(ushort *)(param_1 + 0x18c0) = *(ushort *)(param_1 + 0x18c0) | 1;
        LogSystemEvent(param_1,0xad010050,0x8004af01,(byte *)"Persistency Forced Off",param_2,
                       param_3);
        cVar12 = -0xf;
        *(undefined4 *)(param_1 + 0x187c) = _DAT_0000badd;
        bVar5 = false;
      }
      goto LAB_140016973;
    }
    *(undefined4 *)(puVar10 + 3) = 0;
    *(undefined4 *)((longlong)puVar10 + 0x1c) = 0xd3000000;
    *(int *)(puVar10 + 4) = iVar8 + 0x2c;
    *(undefined4 *)((longlong)puVar10 + 0x24) = *(undefined4 *)(param_1 + 500);
    QueueRequestDescriptor(param_1,(uint)uVar7 * 0x10000 + 8,0,param_2,param_3);
LAB_140016973:
    uVar13 = 0;
    *(char *)(param_1 + 0x121d) = cVar12;
    if (bVar5) {
      do {
        cVar6 = PollLSImpiIsr(param_1,param_2,param_3);
        if (cVar6 != '\0') goto LAB_1400169e0;
        StorPortStallExecution(500);
        uVar13 = uVar13 + 1;
      } while (uVar13 < 20000);
      if (uVar13 == 20000) {
        return;
      }
LAB_1400169e0:
      if (cVar12 == '\0') {
        return;
      }
    }
  } while( true );
}



===== ReadRegisterUlong @ 140016ba0 =====

void ReadRegisterUlong(longlong param_1,int *param_2)

{
  byte bVar1;
  
  bVar1 = 0;
  if (*(char *)(param_1 + 0xbbc4) == '\0') {
    bVar1 = 2;
  }
  do {
    bVar1 = bVar1 + 1;
    if (*param_2 != 0) {
      return;
    }
  } while (bVar1 < 3);
  return;
}



===== ReceiveDataViaHandshake @ 140016bd0 =====

undefined8 ReceiveDataViaHandshake(longlong param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined2 *puVar10;
  
  bVar3 = false;
  uVar9 = 60000;
  if (*(char *)(param_1 + 0x9c7) == '\x06') {
    uVar9 = *(uint *)(param_1 + 0x958);
  }
  uVar7 = 0;
  puVar10 = (undefined2 *)(param_1 + 0xa64);
  do {
    if (bVar3) break;
    uVar5 = SymWaitForDoorBell(param_1,uVar9);
    if ((char)uVar5 == '\0') {
      bVar3 = true;
    }
    bVar4 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar4 = 2;
    }
    do {
      bVar4 = bVar4 + 1;
      if (**(int **)(param_1 + 0x18) != 0) break;
    } while (bVar4 < 3);
    *puVar10 = (short)**(int **)(param_1 + 0x18);
    **(undefined4 **)(param_1 + 0x48) = 0;
    LOCK();
    UNLOCK();
    uVar7 = uVar7 + 1;
    puVar10 = puVar10 + 1;
  } while (uVar7 < 2);
  uVar7 = 2;
  uVar9 = (uint)(byte)*(undefined2 *)(param_1 + 0xa66) * 2;
  if (2 < uVar9) {
    puVar10 = (undefined2 *)(param_1 + 0xa68);
    do {
      if (bVar3) break;
      uVar8 = 0;
      do {
        bVar4 = 0;
        if (*(char *)(param_1 + 0xbbc4) == '\0') {
          bVar4 = 2;
        }
        do {
          uVar1 = **(uint **)(param_1 + 0x48);
          bVar4 = bVar4 + 1;
          if (uVar1 != 0) {
            if (uVar1 == 0xffffffff) goto LAB_140016cfa;
            if ((uVar1 & 1) != 0) goto LAB_140016cfe;
            break;
          }
        } while (bVar4 < 3);
        StorPortStallExecution();
        uVar8 = uVar8 + 1;
      } while (uVar8 < 60000);
LAB_140016cfa:
      bVar3 = true;
LAB_140016cfe:
      if (uVar7 < param_2) {
        bVar4 = 0;
        if (*(char *)(param_1 + 0xbbc4) == '\0') {
          bVar4 = 2;
        }
        do {
          iVar2 = **(int **)(param_1 + 0x18);
          bVar4 = bVar4 + 1;
          if (iVar2 != 0) break;
        } while (bVar4 < 3);
        *puVar10 = (short)iVar2;
      }
      else {
        bVar4 = 0;
        if (*(char *)(param_1 + 0xbbc4) == '\0') {
          bVar4 = 2;
        }
        do {
          bVar4 = bVar4 + 1;
          if (**(int **)(param_1 + 0x18) != 0) break;
        } while (bVar4 < 3);
      }
      **(undefined4 **)(param_1 + 0x48) = 0;
      LOCK();
      UNLOCK();
      uVar7 = uVar7 + 1;
      puVar10 = puVar10 + 1;
    } while (uVar7 < uVar9);
  }
  uVar9 = 0;
  do {
    bVar4 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar4 = 2;
    }
    do {
      uVar8 = **(uint **)(param_1 + 0x48);
      bVar4 = bVar4 + 1;
      if (uVar8 != 0) {
        if (uVar8 == 0xffffffff) goto LAB_140016daa;
        if ((uVar8 & 1) != 0) goto LAB_140016dae;
        break;
      }
    } while (bVar4 < 3);
    StorPortStallExecution(500);
    uVar9 = uVar9 + 1;
    if (59999 < uVar9) {
LAB_140016daa:
      bVar3 = true;
LAB_140016dae:
      **(undefined4 **)(param_1 + 0x48) = 0;
      LOCK();
      UNLOCK();
      if (((uVar7 >> 1 != (uint)*(byte *)(param_1 + 0xa66)) ||
          ((*(ushort *)(param_1 + 0xa72) & 0x7fff) != 0)) || (bVar3)) {
        uVar6 = 0;
      }
      else {
        uVar6 = 1;
      }
      return uVar6;
    }
  } while( true );
}



===== ReleaseFwDiagBuffer @ 140016e10 =====

ulonglong ReleaseFwDiagBuffer(longlong param_1,longlong param_2,byte param_3,int param_4)

{
  void *_Dst;
  ulonglong in_RAX;
  undefined8 uVar1;
  
  if (*(char *)(param_2 + 0x10) == '\0') {
    return in_RAX & 0xffffffffffffff00;
  }
  _Dst = *(void **)(param_1 + 0x578);
  if (*(ushort *)(param_1 + 0x534) != 0) {
    memset(_Dst,0,(ulonglong)*(ushort *)(param_1 + 0x534));
  }
  *(undefined1 *)((longlong)_Dst + 1) = *(undefined1 *)(param_2 + 0xc);
  *(undefined1 *)((longlong)_Dst + 3) = 0x1e;
  QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x9b6) * 0x10000 + 8,0,param_3,param_4)
  ;
  uVar1 = LogSystemEvent(param_1,0,0x4004af00,(byte *)"Diag buffer release message sent to FW.",
                         param_3,param_4);
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x11c) != 0)) {
    uVar1 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x11c,
                        (undefined1 *)0x0,0,param_3,param_4);
  }
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== ResetActive @ 140016f20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ResetActive(longlong param_1,uint param_2,byte param_3,int param_4)

{
  undefined1 auStackY_68 [32];
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = *(undefined4 *)(param_1 + 0x968);
  local_20 = 0;
  if ((param_2 >> 0x1e & 1) == 0) {
    *(uint *)(param_1 + 0x968) = param_2;
  }
  else if ((((*(longlong *)(param_1 + 0x928) == 0) && (*(char *)(param_1 + 0x18f4) == '\0')) &&
           (*(char *)(param_1 + 0x1210) == '\0')) && (*(int *)(param_1 + 0x1288) == 0)) {
    *(undefined4 *)(param_1 + 0x968) = 0;
    local_20 = 0xffffffff;
  }
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20020) != 0)) {
    local_24 = param_2;
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20020,
                (undefined1 *)&local_28,0xc,param_3,param_4);
  }
  return;
}



===== ResumeAdapterQueue @ 140016ff0 =====

void ResumeAdapterQueue(longlong param_1,undefined1 param_2,byte param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 local_res10;
  char local_res11;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xb9fc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  cVar3 = (char)iVar2 + -1;
  if (cVar3 == '\0') {
    StorPortResume();
  }
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40d) != 0)) {
    local_res10 = param_2;
    local_res11 = cVar3;
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40d,&local_res10
                ,2,param_3,param_4);
  }
  return;
}



===== ResumeDevice @ 1400170a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ResumeDevice(longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,byte param_8,int param_9)

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
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x232) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x232,
                  (undefined1 *)&local_58,0x10,param_8,param_9);
    }
  }
  else {
    local_49 = *(char *)(lVar1 + 0x30);
    while (local_49 != '\0') {
      local_49 = local_49 + -1;
      *(char *)(lVar1 + 0x30) = local_49;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x112) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x112,
                    (undefined1 *)&local_58,0x10,param_8,param_9);
      }
      StorPortResumeDevice(param_1,param_2,param_3,param_4);
      local_49 = *(char *)(lVar1 + 0x30);
    }
  }
  return;
}



===== RsIoctl_sm @ 140017250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RsIoctl_sm(longlong param_1,longlong param_2,longlong param_3,byte param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  ushort *puVar4;
  ushort uVar5;
  short *psVar6;
  undefined1 *puVar7;
  longlong lVar8;
  longlong lVar9;
  short *psVar10;
  undefined8 uVar11;
  undefined1 auStackY_88 [32];
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar8 = 0;
  psVar10 = (short *)0x0;
  uVar5 = 0;
  uVar11 = 1;
  while( true ) {
    while( true ) {
      if (*(longlong *)(param_1 + 0x618) == 0) {
        if ((param_2 == 0) && (*(int *)(param_1 + 0x610) != 0)) {
          *(undefined4 *)(param_1 + 0x610) = 0;
          *(undefined1 *)(param_1 + 0x1220) = 0;
          if (*(char *)(param_1 + 0x608) == '\0') {
            return 1;
          }
          if ((*(uint *)(param_1 + 0x60c) & 0x27b) == 0) {
            return 1;
          }
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x27b,
                      (undefined1 *)0x0,0,param_4,param_5);
          return 1;
        }
      }
      else {
        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x618) + 0x40);
        psVar10 = (short *)(lVar8 + 0x24);
      }
      iVar2 = *(int *)(param_1 + 0x610);
      if (iVar2 != 0) break;
      if (param_3 != 0) {
        return 1;
      }
      *(undefined1 *)(param_1 + 0x1220) = 1;
      *(longlong *)(param_1 + 0x618) = param_2;
      *(undefined4 *)(param_1 + 0x610) = 1;
    }
    if (iVar2 != 1) break;
    if (lVar8 == 0) {
LAB_14001749a:
      *(undefined1 *)(param_1 + 0x1220) = 0;
      *(undefined8 *)(param_1 + 0x618) = 0;
      *(undefined4 *)(param_1 + 0x610) = 0;
      return 0;
    }
    if (*(uint *)(lVar8 + 0x18) < 0x20) {
      *(undefined4 *)(lVar8 + 0x14) = 2;
      goto LAB_14001749a;
    }
    uVar5 = *psVar10 * 0x80 + psVar10[1];
    if (*(uint *)(param_1 + 0x9bc) <= (uint)uVar5) {
      *(undefined4 *)(lVar8 + 0x14) = 3;
      goto LAB_14001749a;
    }
    uVar5 = *(ushort *)((ulonglong)uVar5 * 0x2c + 0x1a + *(longlong *)(param_1 + 0x5c0));
    if (uVar5 == 0) {
      *(undefined4 *)(lVar8 + 0x14) = 5;
      goto LAB_14001749a;
    }
    if (*(int *)(lVar8 + 0x20) == 1) {
      *(undefined4 *)(param_1 + 0x610) = 2;
    }
    else {
      if (1 < *(int *)(lVar8 + 0x20) - 2U) {
        *(undefined1 *)(param_1 + 0x1220) = 0;
        *(undefined8 *)(param_1 + 0x618) = 0;
        *(undefined4 *)(lVar8 + 0x14) = 1;
        *(undefined4 *)(param_1 + 0x610) = 0;
        LogSystemEvent(param_1,0xad010079,0x8004af01,(byte *)"Invalid function for Read slot IOCTL",
                       param_4,param_5);
        if (*(char *)(param_1 + 0x608) == '\0') {
          return 0;
        }
        if ((*(uint *)(param_1 + 0x60c) & 0x248) == 0) {
          return 0;
        }
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x248,
                    (undefined1 *)(lVar8 + 0x20),4,param_4,param_5);
        return 0;
      }
      *(undefined4 *)(param_1 + 0x610) = 4;
    }
  }
  if (iVar2 == 2) {
    SendExtendedConfigPageMessage
              (param_1,'\x01',(char *)(param_1 + 0x1920),uVar5 | 0x20000000,
               (int)*(undefined8 *)(param_1 + 0x1928),param_4,param_5);
    *(undefined4 *)(param_1 + 0x610) = 3;
    return 1;
  }
  if (iVar2 == 3) {
    if (lVar8 != 0) {
      *(undefined4 *)(lVar8 + 0x1c) = RsIoctlRecordVersion;
    }
    lVar3 = *(longlong *)(param_1 + 0x1928);
    if (*(short *)(param_1 + 0x185a) == 0x22) {
      *(undefined4 *)(lVar8 + 0x14) = 4;
      uVar11 = 0;
      goto LAB_1400175b5;
    }
    if (psVar10 != (short *)0x0) {
      psVar6 = psVar10 + 4;
      *(undefined4 *)(psVar10 + 10) = *(undefined4 *)(lVar3 + 0x1c);
      puVar7 = (undefined1 *)(lVar3 + 0x13);
      lVar9 = 8;
      psVar10[3] = *(short *)(lVar3 + 8);
      do {
        uVar1 = *puVar7;
        puVar7 = puVar7 + -1;
        *(undefined1 *)psVar6 = uVar1;
        psVar6 = (short *)((longlong)psVar6 + 1);
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      *(undefined1 *)(psVar10 + 8) = *(undefined1 *)(lVar3 + 0x16);
    }
    if (lVar8 == 0) goto LAB_1400175b5;
  }
  else {
    if (iVar2 != 4) goto LAB_1400175b5;
    if ((lVar8 == 0) || (*(int *)(lVar8 + 0x20) != 2)) {
      puVar4 = *(ushort **)(param_1 + 0x560);
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
    }
    else {
      puVar4 = *(ushort **)(param_1 + 0x560);
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
      puVar4[6] = 0x40;
      puVar4[7] = 0;
    }
    *puVar4 = uVar5;
    *(undefined1 *)((longlong)puVar4 + 3) = 0x18;
    QueueRequestDescriptor
              (param_1,(uint)*(ushort *)(param_1 + 0x9b0) * 0x10000 + 8,0,param_4,param_5);
  }
  *(undefined4 *)(lVar8 + 0x14) = 0;
LAB_1400175b5:
  local_48 = *(longlong *)(param_1 + 0x618);
  if (local_48 != 0) {
    local_40 = *(undefined4 *)(local_48 + 0x50);
    local_3c = *(undefined4 *)(local_48 + 0x54);
    local_38 = 1;
    *(undefined1 *)(local_48 + 3) = 1;
    StorPortNotification(0,param_1,*(undefined8 *)(param_1 + 0x618));
    *(undefined8 *)(param_1 + 0x618) = 0;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400020) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400020,
                  (undefined1 *)&local_48,0x11,param_4,param_5);
    }
    *(undefined1 *)(param_1 + 0x1220) = 0;
    *(undefined4 *)(param_1 + 0x610) = 0;
  }
  return uVar11;
}



===== SasBcAsyncEvent @ 1400176d0 =====

void SasBcAsyncEvent(longlong param_1,byte param_2,int param_3)

{
  char *pcVar1;
  undefined1 uVar2;
  char cVar3;
  short sVar4;
  short *psVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ushort uVar11;
  
  bVar6 = false;
  if (*(char *)(param_1 + 0x18f4) == '\0') {
    *(undefined1 *)(param_1 + 0x18f8) = 0;
    return;
  }
LAB_140017730:
  do {
    switch(*(undefined1 *)(param_1 + 0x18f8)) {
    case 1:
      *(undefined2 *)(param_1 + 0x18f0) = 1;
      *(undefined1 *)(param_1 + 0x18f8) = 3;
      break;
    case 2:
      *(short *)(param_1 + 0x18f0) = *(short *)(param_1 + 0x18f0) + 1;
      if (*(ushort *)(param_1 + 0x998) < *(ushort *)(param_1 + 0x18f0)) {
        *(undefined1 *)(param_1 + 0x18f8) = 0xb;
        break;
      }
    case 3:
      *(undefined1 *)(param_1 + 0x18f8) = 2;
      lVar9 = (ulonglong)*(ushort *)(param_1 + 0x18f0) * 0x20 + *(longlong *)(param_1 + 0x598);
      if (*(longlong *)(lVar9 + 8) != 0) {
        sVar4 = *(short *)(lVar9 + 0x14);
        uVar2 = *(undefined1 *)(lVar9 + 0x16);
        uVar8 = GetMapTableIndexFromHandle(param_1,sVar4);
        if ((uVar8 != 0xffffffff) &&
           ((*(uint *)((ulonglong)uVar8 * 0x2c + 0x14 + *(longlong *)(param_1 + 0x5c0)) >> 10 & 1)
            != 0)) {
          *(undefined1 *)(param_1 + 0x18f8) = 4;
          psVar5 = *(short **)(param_1 + 0x948);
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
          *psVar5 = sVar4;
          *(undefined1 *)((longlong)psVar5 + 3) = 1;
          *(undefined1 *)((longlong)psVar5 + 5) = 7;
          *(undefined1 *)((longlong)psVar5 + 0xd) = uVar2;
          psVar5[0x18] = *(short *)(lVar9 + 0x10);
          QueueRequestDescriptor
                    (param_1,(uint)*(ushort *)(param_1 + 0x9ae) * 0x10000 + 6,0,param_2,param_3);
          return;
        }
      }
      break;
    case 4:
      *(undefined1 *)(param_1 + 0x18f8) = 2;
      lVar9 = (ulonglong)*(ushort *)(param_1 + 0x18f0) * 0x20 + *(longlong *)(param_1 + 0x598);
      if (*(longlong *)(lVar9 + 8) != 0) {
        if (*(short *)(*(longlong *)(param_1 + 0x940) + 0xe) == 0) {
          cVar3 = *(char *)(*(longlong *)(param_1 + 0x940) + 4);
          if ((cVar3 == -0x80) || (cVar3 == '\b')) break;
          if (cVar3 == '\0') goto LAB_1400178ba;
        }
        LogSystemEvent(param_1,0xad010037,0x8004af01,
                       (byte *)"Broadcast Async Event Task Management error",param_2,param_3);
LAB_1400178ba:
        *(undefined1 *)(param_1 + 0x18f8) = 5;
        sVar4 = *(short *)(lVar9 + 0x14);
        *(short *)(param_1 + 0x18f2) = sVar4;
        uVar2 = *(undefined1 *)(lVar9 + 0x16);
        psVar5 = *(short **)(param_1 + 0x948);
        *(undefined1 *)(param_1 + 0x18f7) = uVar2;
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
        *psVar5 = sVar4;
        *(undefined1 *)((longlong)psVar5 + 3) = 1;
        *(undefined1 *)((longlong)psVar5 + 5) = 2;
        *(undefined1 *)((longlong)psVar5 + 0xd) = uVar2;
        uVar8 = GetMapTableIndexFromHandle(param_1,sVar4);
        if (uVar8 != 0xffffffff) {
          if (((*(char *)((ulonglong)uVar8 * 0x2c + 0x24 + *(longlong *)(param_1 + 0x5c0)) != '\0')
              && (*(char *)(param_1 + 0x18b0) == '\0')) &&
             ((*(uint *)((ulonglong)uVar8 * 0x2c + 0x14 + *(longlong *)(param_1 + 0x5c0)) & 4) == 0)
             ) {
            *(undefined1 *)((longlong)psVar5 + 7) = 0x18;
          }
        }
        *(undefined1 *)(param_1 + 0x18f6) = 1;
        *(undefined1 *)(param_1 + 0x1984) = 2;
        QueueRequestDescriptor
                  (param_1,(uint)*(ushort *)(param_1 + 0x9ae) * 0x10000 + 6,0,param_2,param_3);
        AfdMasterTrigger(param_1,4,param_2,param_3);
        return;
      }
      break;
    case 5:
      *(undefined1 *)(param_1 + 0x18f6) = 0;
      *(undefined1 *)(param_1 + 0x1984) = 0;
      if (*(short *)(*(longlong *)(param_1 + 0x940) + 0xe) != 0) {
        LogSystemEvent(param_1,0xad010037,0x8004af01,
                       (byte *)"Broadcast Async Event Task Management (Abort task set) error",
                       param_2,param_3);
      }
      *(undefined2 *)(param_1 + 0x18f8) = 0x506;
      break;
    case 6:
      uVar11 = 1;
      sVar4 = *(short *)(param_1 + 0x18f2);
      cVar3 = *(char *)(param_1 + 0x18f7);
      if (*(short *)(param_1 + 0x998) != 0) {
        do {
          lVar9 = (ulonglong)uVar11 * 0x20 + *(longlong *)(param_1 + 0x598);
          if (((*(longlong *)(lVar9 + 8) != 0) && (sVar4 == *(short *)(lVar9 + 0x14))) &&
             (cVar3 == *(char *)(lVar9 + 0x16))) {
            pcVar1 = (char *)(param_1 + 0x18f9);
            *pcVar1 = *pcVar1 + -1;
            bVar6 = true;
            if (*pcVar1 == '\0') {
              *(undefined1 *)(param_1 + 0x18f8) = 9;
              if ((*(char *)(param_1 + 0x608) != '\0') &&
                 ((*(uint *)(param_1 + 0x60c) & 0x250) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x250,
                            (undefined1 *)0x0,0,param_2,param_3);
              }
            }
            else {
              *(undefined1 *)(param_1 + 0x18f8) = 7;
            }
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 <= *(ushort *)(param_1 + 0x998));
      }
      if (!bVar6) {
        *(undefined1 *)(param_1 + 0x18f8) = 2;
      }
      break;
    case 7:
      goto switchD_14001774e_caseD_7;
    case 8:
      *(undefined1 *)(param_1 + 0x18f8) = 6;
      break;
    case 9:
      LogSystemEvent(param_1,0xad010035,0xc004af02,
                     (byte *)"IOs still active on bus when TM reply was received(SasBcAsyncEvent)",
                     param_2,param_3);
      *(undefined1 *)(param_1 + 0x18f8) = 10;
      *(undefined4 *)(param_1 + 0x1218) = 1;
      LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                          "Diag Reset(miniport)-IOs still active on bus when TM reply received(SasBcAsyncEvent)"
                          ,param_2,param_3);
      KickStart(param_1,param_2,param_3);
      return;
    default:
      goto switchD_14001774e_caseD_a;
    case 0xb:
      if (*(char *)(param_1 + 0x18f5) == '\0') {
        *(undefined1 *)(param_1 + 0x18f4) = 0;
        *(undefined1 *)(param_1 + 0x18f8) = 0;
        ResumeAdapterQueue(param_1,6,param_2,param_3);
        ResetActive(param_1,0x40000007,param_2,param_3);
        CheckResetQueue(param_1,param_2,param_3);
        return;
      }
      *(undefined1 *)(param_1 + 0x18f5) = 0;
      *(undefined1 *)(param_1 + 0x18f8) = 1;
    }
  } while( true );
switchD_14001774e_caseD_7:
  uVar10 = GtfStartTimer(param_1,1,1,BaeStuckIoTimerCallback,0,param_2,param_3);
  if ((char)uVar10 == -2) {
    if (*(short *)(param_1 + 0x960) != 0) {
      LogSystemEvent(param_1,0xad01007c,0x8004af01,
                     (byte *)"No Timer available for BaeStuckIoTimerCallback",param_2,param_3);
    }
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                  (undefined1 *)0x0,0,param_2,param_3);
    }
    bVar7 = true;
  }
  else {
    bVar7 = false;
  }
  *(undefined1 *)(param_1 + 0x18f8) = 8;
  if (!bVar7) {
switchD_14001774e_caseD_a:
    return;
  }
  goto LAB_140017730;
}



===== SendAndProcessSSUCommands @ 140017ca0 =====

void SendAndProcessSSUCommands(longlong param_1,byte param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  
  bVar3 = 8;
  do {
    if (bVar3 == 8) {
      *(undefined4 *)(param_1 + 0xb65c) = 0;
      bVar3 = 9;
      *(undefined2 *)(param_1 + 0xb666) = 0;
LAB_140017f8b:
      *(undefined4 *)(param_1 + 0xb660) = 20000;
    }
    else if (bVar3 == 9) {
      SendSsuMessagesToDevices(param_1,param_2,param_3);
      bVar3 = -(*(int *)(param_1 + 0xb65c) != 0) & 10;
    }
    else if (bVar3 == 10) {
      iVar4 = 0;
      do {
        cVar2 = PollLSImpiIsr(param_1,param_2,param_3);
        StorPortStallExecution(500);
      } while (cVar2 != '\0');
      if ((uint)*(ushort *)(param_1 + 0xb666) < *(uint *)(param_1 + 0x9bc)) {
LAB_140017f52:
        bVar3 = 9;
      }
      else {
        if (*(int *)(param_1 + 0xb65c) == 0) {
          iVar4 = 1;
        }
        else {
          piVar1 = (int *)(param_1 + 0xb660);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            if ((*(char *)(param_1 + 0x608) != '\0') &&
               ((*(uint *)(param_1 + 0x60c) & 0x80003) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80003,
                          (undefined1 *)(param_1 + 0xb65c),4,param_2,param_3);
            }
            iVar4 = 3;
          }
        }
        if (iVar4 == 1) {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x80002) != 0))
          {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80002,
                        (undefined1 *)(param_1 + 0xb65c),4,param_2,param_3);
          }
LAB_140017f4d:
          bVar3 = 0;
        }
        else {
          if (iVar4 == 2) goto LAB_140017f52;
          if (iVar4 == 3) {
            bVar3 = 0xb;
          }
        }
      }
    }
    else {
      if (bVar3 == 0xb) {
        SendSsuTmrMessagesToDevices(param_1,param_2,param_3);
        bVar3 = 0xc;
        goto LAB_140017f8b;
      }
      if (bVar3 == 0xc) {
        do {
          cVar2 = PollLSImpiIsr(param_1,param_2,param_3);
          StorPortStallExecution(500);
        } while (cVar2 != '\0');
        if (*(int *)(param_1 + 0xb65c) == 0) goto LAB_140017f4d;
        piVar1 = (int *)(param_1 + 0xb660);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          LogSystemEvent(param_1,0xad010071,0x8004af01,
                         (byte *)"TMR commands time out which are sent after SSU times out",param_2,
                         param_3);
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x80005) != 0))
          {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80005,
                        (undefined1 *)(param_1 + 0xb65c),4,param_2,param_3);
          }
          LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                              "Diag Reset(miniport)-TMR commands time out which are sent after SSU times out"
                              ,param_2,param_3);
          KickStart(param_1,param_2,param_3);
          bVar3 = 0;
        }
      }
      else {
        LogSystemEvent(param_1,0xad010072,0xc004af02,
                       (byte *)"Sending SSU commands Failed in SCSI STOP ADAPTER ",param_2,param_3);
      }
    }
    StorPortStallExecution(500);
    if (bVar3 == 0) {
      return;
    }
  } while( true );
}



===== SendConfigPageMessage @ 140017fd0 =====

void SendConfigPageMessage
               (longlong param_1,char param_2,undefined4 *param_3,undefined4 param_4,int param_5,
               byte param_6,int param_7)

{
  ushort uVar1;
  char *pcVar2;
  uint uVar3;
  
  pcVar2 = *(char **)(param_1 + 0x560);
  uVar1 = *(ushort *)(param_1 + 0x9b0);
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
    *(int *)(pcVar2 + 0x20) = *(int *)(param_1 + 0x204) + 0x2c;
    *(undefined4 *)(pcVar2 + 0x24) = *(undefined4 *)(param_1 + 500);
  }
  else {
    *(int *)(pcVar2 + 0x20) = param_5 - *(int *)(param_1 + 0x108);
    uVar3 = (uint)*(byte *)((longlong)param_3 + 1) << 2;
    *(uint *)(pcVar2 + 0x1c) = uVar3 | 0xd3000000;
    *(undefined4 *)(pcVar2 + 0x24) = *(undefined4 *)(param_1 + 500);
    if (param_2 == '\x02') {
      *(uint *)(pcVar2 + 0x1c) = uVar3 | 0xd7000000;
    }
  }
  QueueRequestDescriptor(param_1,(uint)uVar1 * 0x10000 + 8,0,param_6,param_7);
  return;
}



===== SendExtendedConfigPageMessage @ 140018090 =====

void SendExtendedConfigPageMessage
               (longlong param_1,char param_2,char *param_3,undefined4 param_4,int param_5,
               byte param_6,int param_7)

{
  ushort uVar1;
  char *pcVar2;
  int iVar3;
  ushort uVar4;
  
  if ((((param_3 == (char *)(param_1 + 0x1920)) || (param_3 == (char *)(param_1 + 0x1940))) ||
      (param_3 == (char *)(param_1 + 0x1950))) ||
     ((param_3 == (char *)(param_1 + 0x1908) && (*(char *)(param_1 + 0x9ba) == '\x01')))) {
    pcVar2 = *(char **)(param_1 + 0x570);
    uVar4 = *(ushort *)(param_1 + 0x9b4);
    iVar3 = *(int *)(param_1 + 0x20c);
  }
  else {
    pcVar2 = *(char **)(param_1 + 0x560);
    uVar4 = *(ushort *)(param_1 + 0x9b0);
    iVar3 = *(int *)(param_1 + 0x204);
  }
  *(undefined1 *)(param_1 + 0x9ba) = 0;
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
  pcVar2[0x14] = *param_3;
  pcVar2[0x16] = param_3[2];
  pcVar2[0x17] = param_3[3];
  *(undefined2 *)(pcVar2 + 4) = *(undefined2 *)(param_3 + 4);
  pcVar2[6] = param_3[6];
  *(undefined4 *)(pcVar2 + 0x18) = param_4;
  pcVar2[0x1c] = '\0';
  pcVar2[0x1d] = '\0';
  pcVar2[0x1e] = '\0';
  pcVar2[0x1f] = -0x2d;
  if (param_2 == '\0') {
    *(int *)(pcVar2 + 0x20) = iVar3 + 0x2c;
    *(undefined4 *)(pcVar2 + 0x24) = *(undefined4 *)(param_1 + 500);
  }
  else {
    *(int *)(pcVar2 + 0x20) = param_5 - *(int *)(param_1 + 0x108);
    uVar1 = *(ushort *)(param_3 + 4);
    *(uint *)(pcVar2 + 0x1c) = (uint)uVar1 << 2 | 0xd3000000;
    *(undefined4 *)(pcVar2 + 0x24) = *(undefined4 *)(param_1 + 500);
    if ((param_2 - 2U & 0xfd) == 0) {
      *(uint *)(pcVar2 + 0x1c) = (uint)uVar1 << 2 | 0xd7000000;
    }
  }
  QueueRequestDescriptor(param_1,(uint)uVar4 * 0x10000 + 8,0,param_6,param_7);
  return;
}



===== SendIOCInitMessage @ 1400181d0 =====

ulonglong SendIOCInitMessage(longlong param_1,byte param_2,int param_3)

{
  undefined4 uVar1;
  bool bVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong local_res8;
  
  uVar1 = *(undefined4 *)(param_1 + 500);
  *(undefined8 *)(param_1 + 0x9c4) = 0;
  *(undefined8 *)(param_1 + 0x9cc) = 0;
  *(undefined8 *)(param_1 + 0x9d4) = 0;
  *(undefined8 *)(param_1 + 0x9dc) = 0;
  *(undefined8 *)(param_1 + 0x9e4) = 0;
  *(undefined8 *)(param_1 + 0x9ec) = 0;
  *(undefined8 *)(param_1 + 0x9f4) = 0;
  *(undefined8 *)(param_1 + 0x9fc) = 0;
  *(undefined8 *)(param_1 + 0xa04) = 0;
  *(undefined8 *)(param_1 + 0xa64) = 0;
  *(undefined8 *)(param_1 + 0xa6c) = 0;
  *(undefined4 *)(param_1 + 0xa74) = 0;
  *(undefined1 *)(param_1 + 0x9c7) = 2;
  *(undefined1 *)(param_1 + 0x9c4) = 4;
  *(undefined4 *)(param_1 + 0x9d0) = 0x3a000206;
  *(undefined1 *)(param_1 + 0x9da) = 0xc;
  *(undefined2 *)(param_1 + 0x9de) = *(undefined2 *)(param_1 + 0x536);
  *(undefined2 *)(param_1 + 0x9e0) = *(undefined2 *)(param_1 + 0x53a);
  *(undefined2 *)(param_1 + 0x9e2) = *(undefined2 *)(param_1 + 0x538);
  *(undefined4 *)(param_1 + 0x9e4) = uVar1;
  *(undefined4 *)(param_1 + 0x9e8) = uVar1;
  *(undefined4 *)(param_1 + 0x9ec) = *(undefined4 *)(param_1 + 0x200);
  *(undefined4 *)(param_1 + 0x9f0) = uVar1;
  *(undefined4 *)(param_1 + 0x9f4) = *(undefined4 *)(param_1 + 0x1fc);
  *(undefined4 *)(param_1 + 0x9f8) = uVar1;
  *(ushort *)(param_1 + 0x9d8) = *(ushort *)(param_1 + 0x9d8) | 2;
  *(undefined4 *)(param_1 + 0x9fc) = *(undefined4 *)(param_1 + 0x1f8);
  *(undefined4 *)(param_1 + 0xa00) = uVar1;
  StorPortQuerySystemTime(&local_res8);
  local_res8 = (local_res8 + -0x19db1ded53e8000) / 10000;
  *(longlong *)(param_1 + 0xa04) = local_res8;
  if (*(char *)(param_1 + 0x132) != '\0') {
    *(undefined1 *)(param_1 + 0x9db) = *(undefined1 *)(param_1 + 0x133);
  }
  bVar2 = SendMessageViaHandShake(param_1,0,0x12);
  if (bVar2) {
    uVar3 = ReceiveDataViaHandshake(param_1,10);
    if ((char)uVar3 != '\0') {
      *(undefined1 *)(param_1 + 0x1212) = 0;
      *(undefined2 *)(param_1 + 0x224) = 0;
      return 1;
    }
  }
  *(undefined2 *)(param_1 + 0x224) = 0;
  *(undefined1 *)(param_1 + 0x1212) = 0;
  uVar4 = LogSystemEvent(param_1,0xad010010,0xc004af02,
                         (byte *)"Handshake of IOC Init message failed",param_2,param_3);
  return uVar4 & 0xffffffffffffff00;
}



===== SendIOCTLMessage @ 1400183c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SendIOCTLMessage(longlong param_1,ushort *param_2,void *param_3,byte param_4,int param_5)

{
  ushort *_Src;
  int *piVar1;
  longlong lVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint extraout_EAX;
  ulonglong uVar7;
  longlong *plVar8;
  byte *pbVar9;
  undefined8 uVar10;
  byte bVar11;
  uint uVar12;
  short sVar13;
  char cVar14;
  uint *_Dst;
  void *pvVar15;
  undefined1 auStackY_138 [32];
  byte local_e8;
  undefined2 local_e4;
  ushort local_e0;
  byte local_de;
  undefined1 local_dd;
  char local_dc;
  uint local_d8;
  uint local_d4;
  int local_d0;
  ushort local_cc;
  ushort local_ca;
  uint local_c8;
  int local_c4;
  int local_c0;
  void *local_b8;
  longlong local_b0;
  longlong local_a8;
  void *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined1 local_90;
  uint local_88;
  undefined1 uStack_84;
  undefined1 uStack_83;
  undefined1 uStack_82;
  undefined1 uStack_81;
  undefined4 uStack_80;
  undefined2 uStack_7c;
  undefined2 uStack_7a;
  undefined6 local_78;
  undefined2 uStack_72;
  undefined6 uStack_70;
  undefined2 uStack_6a;
  undefined6 local_68;
  undefined2 uStack_62;
  undefined1 local_60 [16];
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_138;
  bVar11 = *(byte *)((longlong)param_2 + 0xb);
  _Src = param_2 + 4;
  local_a8 = *(longlong *)((longlong)param_3 + 0x68);
  local_e0 = *(ushort *)(param_1 + 0x532);
  local_cc = *(ushort *)(param_1 + 0x534);
  local_68 = 0;
  uStack_62 = 0;
  local_90 = 0;
  uVar7 = *(ulonglong *)((longlong)param_3 + 0x40);
  local_e4 = 0;
  local_c0 = 0;
  local_d0 = 0;
  local_c4 = 0;
  local_dd = 0;
  local_dc = '\0';
  local_b0 = 0;
  local_94 = 0;
  local_e8 = 8;
  uStack_84 = 0;
  uStack_83 = 0;
  uStack_82 = 0;
  uStack_81 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_7a = 0;
  local_78 = 0;
  uStack_72 = 0;
  uStack_70 = 0;
  uStack_6a = 0;
  local_98 = *(undefined4 *)(uVar7 + 0x10);
  local_88 = (uint)bVar11;
  local_de = bVar11;
  local_b8 = param_3;
  local_a0 = param_3;
  if (bVar11 == 0) {
    uVar10 = *(undefined8 *)(param_2 + 0x24);
    uStack_82 = (undefined1)uVar10;
    uStack_81 = (undefined1)((ulonglong)uVar10 >> 8);
    uStack_80 = (undefined4)((ulonglong)uVar10 >> 0x10);
    uStack_7c = (undefined2)((ulonglong)uVar10 >> 0x30);
    uStack_7a = (undefined2)*(undefined8 *)(param_2 + 0x28);
    local_78 = (undefined6)((ulonglong)*(undefined8 *)(param_2 + 0x28) >> 0x10);
    uStack_72 = (undefined2)*(undefined8 *)(param_2 + 0x2c);
    uStack_70 = (undefined6)((ulonglong)*(undefined8 *)(param_2 + 0x2c) >> 0x10);
    uStack_6a = (undefined2)*(undefined8 *)(param_2 + 0x30);
    local_68 = (undefined6)((ulonglong)*(undefined8 *)(param_2 + 0x30) >> 0x10);
LAB_140018698:
    uStack_84 = (undefined1)*_Src;
    uStack_83 = (undefined1)(*_Src >> 8);
  }
  else if (bVar11 == 1) {
    if (*(int *)(param_1 + 0x968) != 0) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40000a) != 0)) {
        uVar7 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                            0x40000a,(undefined1 *)&local_a0,0x11,param_4,param_5);
        return uVar7 & 0xffffffffffffff00;
      }
      goto LAB_140018526;
    }
    AfdMasterTrigger(param_1,4,param_4,param_5);
    local_e8 = 6;
    PauseAdapterQueue(param_1,7,param_4,param_5);
    ResetActive(param_1,5,param_4,param_5);
  }
  else if (bVar11 == 4) {
    uStack_84 = *(undefined1 *)((longlong)param_2 + 0x1f);
    uStack_83 = (undefined1)param_2[0xf];
    uStack_82 = (undefined1)param_2[7];
    uStack_80 = *(undefined4 *)(param_2 + 0x10);
  }
  else if (bVar11 == 0x33) {
    uVar5 = GetMapTableIndexFromHandle(param_1,*_Src);
    if (*(uint *)(param_1 + 0x9bc) <= uVar5) {
      uVar7 = LogSystemEvent(param_1,(uint)*_Src,0x8004af01,
                             (byte *)"Nvme Device is not present in mapping table,Dev handle logged"
                             ,param_4,param_5);
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x24c) != 0)) {
        uVar7 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x24c,
                            (undefined1 *)_Src,2,param_4,param_5);
      }
      goto LAB_140018526;
    }
    local_b0 = (ulonglong)uVar5 * 0x2c + *(longlong *)(param_1 + 0x5c0);
    if (*(char *)(local_b0 + 0x24) != '\x01') {
      uVar7 = LogSystemEvent(param_1,0xad010098,0x8004af01,
                             (byte *)"IOCTL on Non-Nvme Device is failed",param_4,param_5);
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x24d) != 0)) {
        uVar7 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x24d,
                            (undefined1 *)0x0,0,param_4,param_5);
        return uVar7 & 0xffffffffffffff00;
      }
      goto LAB_140018526;
    }
    goto LAB_140018698;
  }
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400001) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400001,
                (undefined1 *)&local_88,0x28,param_4,param_5);
  }
  if ((((bVar11 == 0x17) && (*(char *)(param_1 + 0xb690) == '\0')) && ((char)*_Src == '\0')) &&
     ((*(uint *)(param_2 + 10) & 0x4000000) != 0)) {
    *(ushort **)(param_1 + 0xb680) = param_2;
    *(void **)(param_1 + 0xb688) = param_3;
    *(undefined1 *)(param_1 + 0xb690) = 1;
    uVar7 = HandleFWDowngrade(param_1,'\x01',param_4,param_5);
    return uVar7;
  }
  uVar4 = *param_2;
  local_d4 = (uint)param_2[1] * 4;
  uVar5 = local_d4 + 8;
  if ((short)uVar4 < 0) {
    local_d8 = (*(uint *)(param_2 + 2) & 0xffff) + (uint)local_e0;
    uVar5 = uVar5 + param_2[3];
  }
  else if ((uVar4 & 1) == 0) {
    local_d8 = *(int *)(param_2 + 2) + (uint)local_e0;
  }
  else {
    local_d8 = (uint)local_e0;
    uVar5 = uVar5 + *(int *)(param_2 + 2);
  }
  local_c8 = (uint)local_e0;
  if ((uVar4 >> 0xe & 1) == 0) {
    if ((uVar4 >> 0xd & 1) != 0) {
      local_d8 = local_d8 + 0x10;
    }
  }
  else {
    local_d8 = local_d8 + 0xff;
  }
  uVar7 = *(ulonglong *)((longlong)param_3 + 0x40);
  if (local_d8 < uVar5) {
    local_d8 = uVar5;
  }
  if (*(uint *)(uVar7 + 0x18) < local_d8) {
LAB_140018526:
    return uVar7 & 0xffffffffffffff00;
  }
  if (*(char *)(param_1 + 0xbbd0) == '\0') {
    plVar8 = (longlong *)GetHostReqTag(param_1,&local_e4);
    if ((char)plVar8 == '\0') goto LAB_1400187e4;
    LOCK();
    pbVar9 = (byte *)(*(longlong *)(param_1 + 0xaa8) + (ulonglong)(local_e4 >> 5) * 4 +
                     ((longlong)(int)(local_e4 & 0x1f) >> 3));
    *pbVar9 = *pbVar9 | '\x01' << (local_e4 & 7);
    UNLOCK();
  }
  else {
    plVar8 = *(longlong **)(param_1 + 0x910);
    if (*(longlong *)(*plVar8 + 8) != 0) {
LAB_1400187e4:
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40000b) != 0)) {
        plVar8 = (longlong *)
                 RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                             0x40000b,(undefined1 *)&local_a0,0x11,param_4,param_5);
      }
      *(undefined1 *)((longlong)param_3 + 3) = 5;
      return (ulonglong)plVar8 & 0xffffffffffffff00;
    }
  }
  lVar2 = local_a8;
  _Dst = (uint *)(local_a8 + 0x168);
  uVar5 = StorPortGetPhysicalAddress(param_1,param_3,_Dst);
  memmove(_Dst,_Src,(ulonglong)local_d4);
  pvVar15 = local_b8;
  local_ca = *(ushort *)(param_1 + 0x9ae);
  *(undefined4 *)(param_1 + 0x1198) = 0;
  uVar4 = local_e4 >> 8;
  local_e4 = local_e4 & 0xff00;
  *(undefined4 *)((ulonglong)local_ca * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 1;
  if (*(char *)(param_1 + 0x120a) != '\0') {
    pbVar9 = &IeeeSglFuncList;
    uVar12 = 0;
    do {
      if (local_de == *pbVar9) {
        if ((local_de != 0x17) || (local_dc = *(char *)_Dst, (local_dc - 6U & 0xfd) == 0)) {
          local_e4 = CONCAT11((char)uVar4,1);
        }
        break;
      }
      uVar12 = uVar12 + 1;
      pbVar9 = pbVar9 + 1;
    } while (uVar12 < 8);
  }
  uVar4 = *param_2;
  uVar3 = uVar4 & 0xf000;
  if (uVar3 == 0x2000) {
    *(undefined2 *)(lVar2 + 0x16c) = 0x40;
    uVar12 = 0;
    *(undefined2 *)(lVar2 + 0x180) = 0x10;
    local_c4 = 0x10;
    if ((*param_2 & 1) == 0) {
      uVar12 = *(uint *)(param_2 + 2);
    }
    local_e8 = 0x10;
    *(uint *)(lVar2 + 0x178) = uVar5 - 0x100;
    *(undefined4 *)(lVar2 + 0x17c) = *(undefined4 *)(param_1 + 500);
    *(undefined8 *)(local_a8 + 0x68) = 0;
    *(undefined8 *)(local_a8 + 0x70) = 0;
    *(ulonglong *)(param_1 + 0x1278) = (longlong)param_2 + (ulonglong)local_e0 + (ulonglong)uVar12;
    *param_2 = *param_2 & 0xdfff;
    uVar4 = *param_2;
LAB_140018b5a:
    pvVar15 = local_b8;
    if (uVar4 == 1) {
      uVar12 = (param_2[1] + 2) * 4;
      cVar14 = (char)local_e4;
      goto LAB_140018a0c;
    }
  }
  else {
    if (uVar3 == 0x4000) {
      sVar13 = *(short *)_Dst;
      *(undefined1 *)(lVar2 + 0x17c) = 0x18;
      uVar12 = GetMapTableIndexFromHandle(param_1,sVar13);
      if (uVar12 != 0xffffffff) {
        local_b0 = (ulonglong)uVar12 * 0x2c + *(longlong *)(param_1 + 0x5c0);
        local_dd = *(undefined1 *)(local_b0 + 0x24);
      }
      *(undefined1 *)(lVar2 + 0x17a) = 0xff;
      uVar12 = 0;
      local_c4 = 0xff;
      if ((*param_2 & 1) == 0) {
        uVar12 = *(uint *)(param_2 + 2);
      }
      *(uint *)(lVar2 + 0x174) = uVar5 - 0x100;
      *(ulonglong *)(param_1 + 0x1278) = (longlong)param_2 + (ulonglong)local_e0 + (ulonglong)uVar12
      ;
      *(uint *)(lVar2 + 0x1a4) = *(uint *)(lVar2 + 0x1a4) & 0xfffff8ff;
      uVar4 = *param_2 & 0xbfff;
      *param_2 = uVar4;
      if (*(char *)(lVar2 + 0x16b) == '\0') {
        local_c0 = (uint)*(ushort *)_Dst << 0x10;
        local_e8 = 0;
      }
      goto LAB_140018b5a;
    }
    if (uVar3 != 0x8000) goto LAB_140018b5a;
    uVar10 = StorPortGetPhysicalAddress
                       (param_1,local_b8,param_2 + ((ulonglong)param_2[1] + 2) * 2,&local_d8);
    local_d8 = (uint)param_2[3];
    uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
    if ((char)local_e4 == '\0') {
      bVar11 = *(byte *)(param_1 + 0x542) & 1;
      sVar13 = bVar11 + 2;
      uVar7 = (ulonglong)local_d4;
      *(uint *)(uVar7 + (longlong)_Dst) = (bVar11 + 0x2a) * 0x2000000 | local_d8;
      *(int *)(uVar7 + 4 + (longlong)_Dst) = (int)uVar10;
      if (bVar11 != 0) {
        *(undefined4 *)(uVar7 + 8 + (longlong)_Dst) = uVar6;
      }
    }
    else {
      uVar7 = (ulonglong)local_d4;
      sVar13 = 4;
      *(int *)(uVar7 + (longlong)_Dst) = (int)uVar10;
      *(undefined4 *)(uVar7 + 4 + (longlong)_Dst) = uVar6;
      *(uint *)(uVar7 + 8 + (longlong)_Dst) = local_d8;
      *(undefined4 *)(uVar7 + 0xc + (longlong)_Dst) = 0x40000000;
    }
    param_2[1] = param_2[1] + sVar13;
    local_d4 = (uint)param_2[1] << 2;
    param_2[3] = 0;
    *param_2 = 0;
  }
  uVar12 = (uint)local_e0;
  local_d0 = *(int *)(param_2 + 2);
  cVar14 = (char)local_e4;
LAB_140018a0c:
  uVar12 = uVar12 + (int)param_2;
  if (local_de == 0x33) {
    if ((*(int *)(param_2 + 2) != 0) &&
       (uVar7 = BuildNVMePRP(param_1,(longlong)pvVar15,uVar12,(longlong)_Dst,uVar5,local_b0,param_4,
                             param_5), (char)uVar7 == '\0')) {
      return uVar7;
    }
  }
  else if (*(int *)(param_2 + 2) == 0) {
    piVar1 = (int *)((ulonglong)local_d4 + (longlong)_Dst);
    if (cVar14 == '\0') {
      *piVar1 = -0x2d000000;
      piVar1[1] = local_d4 + uVar5;
      piVar1[2] = *(int *)(param_1 + 500);
    }
    else {
      *piVar1 = local_d4 + uVar5;
      piVar1[1] = *(int *)(param_1 + 500);
      piVar1[2] = 0;
      piVar1[3] = 0x40000000;
    }
  }
  else {
    BuildIoctlScatterGather(param_1,(longlong)pvVar15,_Dst,uVar5,(short *)param_2,uVar12,cVar14);
    local_d8 = extraout_EAX;
    if (local_d0 != 0) {
      local_d0 = local_d0 - extraout_EAX;
    }
  }
  if (((local_dc == '\x01') && ((*param_2 & 1) != 0)) && (param_2[2] != 0)) {
    pvVar15 = (void *)(lVar2 + 0x174);
    uVar4 = (*(ushort *)(param_1 + 0x542) & 1 | 2) << 2;
    memmove(local_60,(void *)((ulonglong)uVar4 + (longlong)pvVar15),(ulonglong)(uint)uVar4);
    memmove((void *)((ulonglong)uVar4 + (longlong)pvVar15),pvVar15,(ulonglong)(uint)uVar4);
    memmove(pvVar15,local_60,(ulonglong)uVar4);
  }
  *(uint *)((longlong)local_b8 + 0x3c) = local_d0 + 0x1c + local_c8 + local_c4;
  *(void **)(param_1 + 0x1228) = local_b8;
  memmove((void *)(param_1 + 0x1230),local_b8,0x40);
  uVar5 = (uint)local_cc;
  *(undefined1 *)(param_1 + 0x1221) = *(undefined1 *)(local_a8 + 0x62);
  memmove(*(void **)(param_1 + 0x1270),_Dst,(ulonglong)uVar5);
  memmove(*(void **)(param_1 + 0x948),_Dst,(ulonglong)uVar5);
  *(undefined1 *)(param_1 + 0x1220) = 1;
  uVar10 = QueueRequestDescriptor
                     (param_1,(uint)local_ca * 0x10000 + (uint)local_e8,local_c0,param_4,param_5);
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40000e) != 0)) {
    uVar10 = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40000e,
                         (undefined1 *)&local_a0,0x11,param_4,param_5);
  }
  return CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
}



===== SendLunResetTur @ 140018d60 =====

void SendLunResetTur(longlong param_1,ushort param_2,byte param_3,int param_4)

{
  longlong lVar1;
  ushort *puVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  undefined1 local_res10 [8];
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x928) + 0x68);
  uVar4 = GtfStartTimer(param_1,1,2,LunResetTurTimeout,0,param_3,param_4);
  *(char *)(param_1 + 0xab0) = (char)uVar4;
  if ((((char)uVar4 == -2) && (*(char *)(param_1 + 0x608) != '\0')) &&
     ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                (undefined1 *)0x0,0,param_3,param_4);
  }
  *(undefined4 *)
   ((ulonglong)*(ushort *)(param_1 + 0x9b2) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0x40;
  *(undefined1 *)(lVar1 + 0x65) = 0;
  puVar2 = *(ushort **)(param_1 + 0x568);
  puVar2[0] = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  puVar2[0x10] = 0;
  puVar2[0x11] = 0;
  puVar2[0x12] = 0;
  puVar2[0x13] = 0;
  puVar2[0x14] = 0;
  puVar2[0x15] = 0;
  puVar2[0x16] = 0;
  puVar2[0x17] = 0;
  puVar2[0x18] = 0;
  puVar2[0x19] = 0;
  puVar2[0x1a] = 0;
  puVar2[0x1b] = 0;
  puVar2[0x1c] = 0;
  puVar2[0x1d] = 0;
  puVar2[0x1e] = 0;
  puVar2[0x1f] = 0;
  puVar2[0x20] = 0;
  puVar2[0x21] = 0;
  puVar2[0x22] = 0;
  puVar2[0x23] = 0;
  puVar2[0x24] = 0;
  puVar2[0x25] = 0;
  puVar2[0x26] = 0;
  puVar2[0x27] = 0;
  puVar2[0x28] = 0;
  puVar2[0x29] = 0;
  puVar2[0x2a] = 0;
  puVar2[0x2b] = 0;
  puVar2[0x2c] = 0;
  puVar2[0x2d] = 0;
  puVar2[0x2e] = 0;
  puVar2[0x2f] = 0;
  puVar2[0x30] = 0;
  puVar2[0x31] = 0;
  puVar2[0x32] = 0;
  puVar2[0x33] = 0;
  puVar2[0x34] = 0;
  puVar2[0x35] = 0;
  puVar2[0x36] = 0;
  puVar2[0x37] = 0;
  *(undefined1 *)(puVar2 + 10) = 0x18;
  *puVar2 = param_2;
  uVar3 = StorPortGetPhysicalAddress
                    (param_1,*(undefined8 *)(param_1 + 0x928),lVar1 + 0x68,local_res10);
  *(undefined1 *)(puVar2 + 9) = 0xff;
  *(undefined4 *)(puVar2 + 6) = uVar3;
  puVar2[0x12] = 6;
  BuildZeroLenSGE(param_1,(longlong)puVar2,*(int *)(param_1 + 0x208),*(char *)(param_1 + 0x120a));
  QueueRequestDescriptor
            (param_1,(uint)*(ushort *)(param_1 + 0x9b2) << 0x10,(uint)*puVar2 << 0x10,param_3,
             param_4);
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20008) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20008,
                (undefined1 *)(lVar1 + 0x62),3,param_3,param_4);
  }
  return;
}



===== SendMessageViaHandShake @ 140018f50 =====

bool SendMessageViaHandShake(longlong param_1,int param_2,uint param_3)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  undefined4 *puVar7;
  bool bVar8;
  bool bVar9;
  
  uVar4 = 10000;
  if (param_2 == 0) {
    lVar2 = 0x9c4;
    uVar4 = 10000;
    if (*(char *)(param_1 + 0x9c7) != '\x04') {
      uVar4 = 60000;
    }
  }
  else {
    lVar2 = 0xa14;
  }
  puVar7 = (undefined4 *)(lVar2 + param_1);
  uVar6 = 0;
  **(undefined4 **)(param_1 + 0x48) = 0;
  LOCK();
  UNLOCK();
  **(int **)(param_1 + 0x18) = (param_3 | 0x4200) << 0x10;
  LOCK();
  UNLOCK();
  uVar3 = SymWaitForDoorBell(param_1,uVar4);
  bVar9 = (char)uVar3 == '\0';
  bVar1 = 0;
  if (*(char *)(param_1 + 0xbbc4) == '\0') {
    bVar1 = 2;
  }
  do {
    bVar1 = bVar1 + 1;
    if (**(uint **)(param_1 + 0x18) != 0) break;
  } while (bVar1 < 3);
  bVar8 = (**(uint **)(param_1 + 0x18) >> 0x1b & 1) == 0;
  bVar5 = bVar8 || bVar9;
  **(undefined4 **)(param_1 + 0x48) = 0;
  LOCK();
  UNLOCK();
  if ((bVar8 || bVar9) || (lVar2 = SymWaitForResponse(param_1), (char)lVar2 == '\0')) {
    bVar5 = true;
  }
  if (param_3 != 0) {
    do {
      if (bVar5) {
        return !bVar5;
      }
      **(undefined4 **)(param_1 + 0x18) = *puVar7;
      LOCK();
      UNLOCK();
      lVar2 = SymWaitForResponse(param_1);
      if ((char)lVar2 == '\0') {
        bVar5 = true;
      }
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar6 < param_3);
  }
  return !bVar5;
}



===== SendMpiEventToApplication @ 140019090 =====

void SendMpiEventToApplication(longlong param_1,uint param_2,void *param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  longlong lVar4;
  undefined8 *_Dst;
  
  if (((byte)(param_2 >> 5) < 4) &&
     ((*(uint *)(param_1 + 0x119c + ((ulonglong)(param_2 >> 5) & 0xff) * 4) >> (param_2 & 0x1f) & 1)
      != 0)) {
    bVar1 = *(byte *)(param_1 + 0x11b0);
    lVar4 = (ulonglong)bVar1 * 200;
    *(uint *)(lVar4 + 0x1a1c + param_1) = param_2;
    *(int *)(param_1 + 0x11ac) = *(int *)(param_1 + 0x11ac) + 1;
    *(undefined4 *)(lVar4 + 0x1a20 + param_1) = *(undefined4 *)(param_1 + 0x11ac);
    _Dst = (undefined8 *)(lVar4 + 0x1a24 + param_1);
    uVar2 = 0xc0;
    if (param_4 < 0xc1) {
      uVar2 = param_4;
    }
    *_Dst = 0;
    _Dst[1] = 0;
    _Dst[2] = 0;
    _Dst[3] = 0;
    _Dst[4] = 0;
    _Dst[5] = 0;
    _Dst[6] = 0;
    _Dst[7] = 0;
    _Dst[8] = 0;
    _Dst[9] = 0;
    _Dst[10] = 0;
    _Dst[0xb] = 0;
    _Dst[0xc] = 0;
    _Dst[0xd] = 0;
    _Dst[0xe] = 0;
    _Dst[0xf] = 0;
    _Dst[0x10] = 0;
    _Dst[0x11] = 0;
    _Dst[0x12] = 0;
    _Dst[0x13] = 0;
    _Dst[0x14] = 0;
    _Dst[0x15] = 0;
    _Dst[0x16] = 0;
    _Dst[0x17] = 0;
    memmove(_Dst,param_3,(ulonglong)uVar2);
    cVar3 = '\0';
    if (bVar1 != 199) {
      cVar3 = bVar1 + 1;
    }
    *(char *)(param_1 + 0x11b0) = cVar3;
    if (*(char *)(param_1 + 0x18b1) != '\0') {
      ScsiPortWmiFireLogicalUnitEvent
                (param_1,-1,0,0,(int *)&MegaSASWmiMpiEventGuid,0,0x10,(int *)(param_1 + 0x1a0));
    }
  }
  return;
}



===== SendSEPMessage @ 1400191c0 =====

void SendSEPMessage(longlong param_1,undefined4 param_2,undefined2 param_3,byte param_4,int param_5)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x560);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined4 *)((longlong)puVar1 + 0xc) = param_2;
  *(undefined2 *)puVar1 = param_3;
  *(undefined1 *)((longlong)puVar1 + 3) = 0x18;
  QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x9b0) * 0x10000 + 8,0,param_4,param_5)
  ;
  return;
}



===== SendSsuMessage @ 140019200 =====

ulonglong SendSsuMessage(longlong param_1,ushort param_2,byte param_3,int param_4)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  longlong lVar6;
  ushort *puVar7;
  ushort local_res8 [4];
  undefined2 local_38 [2];
  undefined2 local_34 [6];
  
  local_res8[0] = 0;
  if (*(char *)(param_1 + 0xbbd0) == '\0') {
    plVar2 = (longlong *)GetHostReqTag(param_1,local_res8);
    if ((char)plVar2 != '\0') {
      lVar6 = (ulonglong)local_res8[0] * 0x20 + *(longlong *)(param_1 + 0x598);
LAB_140019298:
      *(uint *)(lVar6 + 0x18) = *(uint *)(lVar6 + 0x18) | 0x10;
      *(ulonglong *)(lVar6 + 8) = (ulonglong)param_2;
      *(undefined1 *)(lVar6 + 0x13) = 2;
      *(int *)(param_1 + 0xb65c) = *(int *)(param_1 + 0xb65c) + 1;
      iVar5 = (uint)*(ushort *)(param_1 + 0x534) * (uint)*(ushort *)(lVar6 + 0x10);
      iVar1 = *(int *)(param_1 + 0x200);
      puVar7 = (ushort *)((longlong)iVar5 + *(longlong *)(param_1 + 0x558));
      puVar7[0] = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7[3] = 0;
      puVar7[4] = 0;
      puVar7[5] = 0;
      puVar7[6] = 0;
      puVar7[7] = 0;
      puVar7[8] = 0;
      puVar7[9] = 0;
      puVar7[10] = 0;
      puVar7[0xb] = 0;
      puVar7[0xc] = 0;
      puVar7[0xd] = 0;
      puVar7[0xe] = 0;
      puVar7[0xf] = 0;
      puVar7[0x10] = 0;
      puVar7[0x11] = 0;
      puVar7[0x12] = 0;
      puVar7[0x13] = 0;
      puVar7[0x14] = 0;
      puVar7[0x15] = 0;
      puVar7[0x16] = 0;
      puVar7[0x17] = 0;
      puVar7[0x18] = 0;
      puVar7[0x19] = 0;
      puVar7[0x1a] = 0;
      puVar7[0x1b] = 0;
      puVar7[0x1c] = 0;
      puVar7[0x1d] = 0;
      puVar7[0x1e] = 0;
      puVar7[0x1f] = 0;
      puVar7[0x20] = 0;
      puVar7[0x21] = 0;
      puVar7[0x22] = 0;
      puVar7[0x23] = 0;
      puVar7[0x24] = 0;
      puVar7[0x25] = 0;
      puVar7[0x26] = 0;
      puVar7[0x27] = 0;
      puVar7[0x28] = 0;
      puVar7[0x29] = 0;
      puVar7[0x2a] = 0;
      puVar7[0x2b] = 0;
      puVar7[0x2c] = 0;
      puVar7[0x2d] = 0;
      puVar7[0x2e] = 0;
      puVar7[0x2f] = 0;
      puVar7[0x30] = 0;
      puVar7[0x31] = 0;
      puVar7[0x32] = 0;
      puVar7[0x33] = 0;
      puVar7[0x34] = 0;
      puVar7[0x35] = 0;
      puVar7[0x36] = 0;
      puVar7[0x37] = 0;
      *puVar7 = param_2;
      *(undefined1 *)(puVar7 + 10) = 0x18;
      *(undefined1 *)(puVar7 + 0x20) = 0x1b;
      GetBusTargetFromDevHandle(param_1,param_2,local_38,local_34);
      BuildZeroLenSGE(param_1,(longlong)puVar7,iVar1 + iVar5,*(char *)(param_1 + 0x120a));
      uVar4 = QueueRequestDescriptor
                        (param_1,(uint)*(ushort *)(lVar6 + 0x10) << 0x10,(uint)param_2 << 0x10,
                         param_3,param_4);
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
  }
  else {
    plVar2 = *(longlong **)(param_1 + 0x910);
    lVar6 = *plVar2;
    if (*(longlong *)(lVar6 + 8) == 0) {
      lVar3 = *(longlong *)(param_1 + 0x910) + 8;
      *(longlong *)(param_1 + 0x910) = lVar3;
      if (lVar3 == *(longlong *)(param_1 + 0x920)) {
        *(undefined8 *)(param_1 + 0x910) = *(undefined8 *)(param_1 + 0x908);
      }
      goto LAB_140019298;
    }
  }
  return (ulonglong)plVar2 & 0xffffffffffffff00;
}



===== SendSsuMessagesToDevices @ 1400193b0 =====

void SendSsuMessagesToDevices(longlong param_1,byte param_2,int param_3)

{
  char cVar1;
  char cVar2;
  undefined8 uVar3;
  byte bVar4;
  ushort uVar5;
  longlong lVar6;
  
  uVar5 = *(ushort *)(param_1 + 0xb666);
  cVar2 = '\x01';
  if ((uint)uVar5 < *(uint *)(param_1 + 0x9bc)) {
    do {
      lVar6 = (ulonglong)uVar5 * 0x2c + *(longlong *)(param_1 + 0x5c0);
      if ((((*(ushort *)(lVar6 + 0x1a) == 0) || (*(char *)(lVar6 + 0x25) == '\0')) ||
          ((bVar4 = (byte)*(undefined4 *)(lVar6 + 0x14), -1 < (char)bVar4 && ((bVar4 & 0xf) != 3))))
         || (((bVar4 & 7) != 1 && (*(char *)(lVar6 + 0x24) == '\0')))) goto LAB_1400194a1;
      switch(*(ushort *)(param_1 + 0xb664) & 7) {
      case 1:
        if (*(char *)(lVar6 + 0x26) != '\0') break;
        goto LAB_14001949c;
      case 2:
        if (*(char *)(lVar6 + 0x26) != '\0') goto LAB_14001949c;
      case 3:
        cVar1 = *(char *)(lVar6 + 0x24);
LAB_140019487:
        if (cVar1 == '\0') break;
        goto LAB_14001949c;
      case 4:
switchD_140019455_caseD_4:
        if (*(char *)(lVar6 + 0x24) == '\0') goto LAB_14001949c;
        break;
      case 5:
        if (*(char *)(lVar6 + 0x26) == '\0') goto switchD_140019455_caseD_4;
        break;
      case 6:
        cVar1 = *(char *)(lVar6 + 0x26);
        goto LAB_140019487;
      }
      uVar3 = SendSsuMessage(param_1,*(ushort *)(lVar6 + 0x1a),param_2,param_3);
      cVar2 = (char)uVar3;
LAB_14001949c:
      if (cVar2 == '\0') break;
LAB_1400194a1:
      uVar5 = uVar5 + 1;
    } while ((uint)uVar5 < *(uint *)(param_1 + 0x9bc));
    *(ushort *)(param_1 + 0xb666) = uVar5;
  }
  else {
    *(ushort *)(param_1 + 0xb666) = uVar5;
  }
  return;
}



===== SendSsuTmrMessagesToDevices @ 140019500 =====

void SendSsuTmrMessagesToDevices(longlong param_1,byte param_2,int param_3)

{
  int *piVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  longlong lVar5;
  short *psVar6;
  longlong *plVar7;
  longlong lVar8;
  int local_res8 [2];
  
  piVar1 = (int *)(param_1 + 0xb65c);
  plVar7 = *(longlong **)(param_1 + 0x908);
  *piVar1 = 0;
  if (plVar7 < *(longlong **)(param_1 + 0x920)) {
    do {
      lVar5 = *plVar7;
      if (*(longlong *)(lVar5 + 8) != 0) {
        *(undefined4 *)(lVar5 + 0x18) = 0x20;
        *piVar1 = *piVar1 + 1;
        sVar2 = *(short *)(lVar5 + 8);
        uVar3 = *(ushort *)(lVar5 + 0x10);
        local_res8[0] = 0;
        psVar6 = (short *)((longlong)(int)((uint)*(ushort *)(param_1 + 0x534) * (uint)uVar3) +
                          *(longlong *)(param_1 + 0x558));
        psVar6[0] = 0;
        psVar6[1] = 0;
        psVar6[2] = 0;
        psVar6[3] = 0;
        psVar6[4] = 0;
        psVar6[5] = 0;
        psVar6[6] = 0;
        psVar6[7] = 0;
        psVar6[8] = 0;
        psVar6[9] = 0;
        psVar6[10] = 0;
        psVar6[0xb] = 0;
        psVar6[0xc] = 0;
        psVar6[0xd] = 0;
        psVar6[0xe] = 0;
        psVar6[0xf] = 0;
        psVar6[0x10] = 0;
        psVar6[0x11] = 0;
        psVar6[0x12] = 0;
        psVar6[0x13] = 0;
        psVar6[0x14] = 0;
        psVar6[0x15] = 0;
        psVar6[0x16] = 0;
        psVar6[0x17] = 0;
        psVar6[0x18] = 0;
        psVar6[0x19] = 0;
        *psVar6 = sVar2;
        *(undefined1 *)((longlong)psVar6 + 3) = 1;
        *(undefined1 *)((longlong)psVar6 + 5) = 3;
        uVar4 = GetMapTableIndexFromHandle(param_1,sVar2);
        if (uVar4 != 0xffffffff) {
          lVar8 = (ulonglong)uVar4 * 0x2c;
          lVar5 = *(longlong *)(param_1 + 0x5c0);
          if (((*(char *)(lVar8 + 0x24 + lVar5) != '\0') && (*(char *)(param_1 + 0x18b0) == '\0'))
             && ((*(uint *)(lVar8 + 0x14 + lVar5) & 4) == 0)) {
            *(undefined1 *)((longlong)psVar6 + 7) = 0x18;
            lVar5 = *(longlong *)(param_1 + 0x5c0);
          }
          local_res8[0] =
               CONCAT22(*(undefined2 *)(lVar8 + 0x1c + lVar5),*(undefined2 *)(lVar8 + 0x1e + lVar5))
          ;
          LogOperationalEvent(param_1,local_res8,4,0x4004af00,
                              "Target reset issued to clean any SSU timed out command(BT logged)",
                              param_2,param_3);
        }
        QueueRequestDescriptor(param_1,(uint)uVar3 * 0x10000 + 6,0,param_2,param_3);
        AfdMasterTrigger(param_1,4,param_2,param_3);
      }
      plVar7 = plVar7 + 1;
    } while (plVar7 < *(longlong **)(param_1 + 0x920));
  }
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x80004) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80004,
                (undefined1 *)piVar1,4,param_2,param_3);
  }
  return;
}



===== SetNvmeMaxShutdownTime @ 1400196f0 =====

void SetNvmeMaxShutdownTime(longlong param_1)

{
  undefined4 *puVar1;
  ushort uVar2;
  ulonglong uVar3;
  
  uVar2 = 6;
  if (*(uint *)(param_1 + 0x9bc) != 0) {
    uVar3 = (ulonglong)*(uint *)(param_1 + 0x9bc);
    puVar1 = (undefined4 *)(*(longlong *)(param_1 + 0x5c0) + 0x14);
    do {
      if (((*(char *)(puVar1 + 4) != '\0') && (((byte)*puVar1 & 0xf) == 3)) &&
         (uVar2 < *(ushort *)(puVar1 + 5))) {
        uVar2 = *(ushort *)(puVar1 + 5);
      }
      puVar1 = puVar1 + 0xb;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  *(ushort *)(param_1 + 0xbbd8) = uVar2;
  return;
}



===== SymWaitForDoorBell @ 140019740 =====

ulonglong SymWaitForDoorBell(longlong param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  ulonglong in_RAX;
  uint uVar3;
  
  uVar3 = 0;
  if (param_2 != 0) {
    do {
      in_RAX = 0;
      if (*(char *)(param_1 + 0xbbc4) == '\0') {
        in_RAX = 2;
      }
      do {
        uVar1 = **(uint **)(param_1 + 0x48);
        bVar2 = (char)in_RAX + 1;
        in_RAX = (ulonglong)bVar2;
        if (uVar1 != 0) {
          if (uVar1 == 0xffffffff) goto LAB_1400197af;
          if ((uVar1 & 1) != 0) {
            return 1;
          }
          break;
        }
      } while (bVar2 < 3);
      in_RAX = StorPortStallExecution(500);
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_2);
  }
LAB_1400197af:
  return in_RAX & 0xffffffffffffff00;
}



===== SymWaitForResponse @ 1400197d0 =====

longlong SymWaitForResponse(longlong param_1)

{
  int iVar1;
  byte bVar2;
  uint7 uVar3;
  uint7 extraout_var;
  uint uVar4;
  
  uVar4 = 0;
  do {
    bVar2 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar2 = 2;
    }
    while( true ) {
      uVar3 = 0;
      iVar1 = **(int **)(param_1 + 0x48);
      bVar2 = bVar2 + 1;
      if (iVar1 != 0) break;
      if (2 < bVar2) {
        return 1;
      }
    }
    if (iVar1 == -1) break;
    if (-1 < iVar1) {
      return 1;
    }
    StorPortStallExecution(500);
    uVar4 = uVar4 + 1;
    uVar3 = extraout_var;
  } while (uVar4 < 120000);
  return (ulonglong)uVar3 << 8;
}



===== SynchronizeHandleOrphanedIoctl @ 140019860 =====

undefined8 SynchronizeHandleOrphanedIoctl(longlong param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  ulonglong in_RAX;
  
  iVar2 = *param_2;
  bVar1 = *(byte *)(param_2 + 1);
  if (((*(char *)(param_1 + 0x1220) == '\0') && (*(longlong *)(param_1 + 0x1228) == 0)) &&
     (in_RAX = (ulonglong)*(byte *)(param_1 + 0x12ae),
     *(longlong *)(param_1 + 0x12b8 + in_RAX * 8) != 0)) {
    in_RAX = CheckIoctlQueue(param_1,bVar1,iVar2);
    if ((char)in_RAX != '\0') {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x249) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x249,
                    (undefined1 *)0x0,0,bVar1,iVar2);
      }
      in_RAX = LogSystemEvent(param_1,0xad01007b,0x8004af01,
                              (byte *)"an orphaned ioctl found by watchdog timer on ioctl queue",
                              bVar1,iVar2);
    }
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== SynchronizeRestartRecovery @ 140019930 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SynchronizeRestartRecovery(longlong param_1,int *param_2)

{
  undefined4 *puVar1;
  ushort *puVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  bool bVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  byte bVar14;
  ushort uVar15;
  uint *puVar16;
  undefined4 uVar17;
  int *piVar18;
  char *pcVar19;
  undefined1 local_98 [32];
  ushort local_58 [2];
  uint local_54;
  longlong local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_98;
  iVar4 = *param_2;
  puVar1 = (undefined4 *)(param_1 + 0x1218);
  iVar11 = 0;
  bVar3 = *(byte *)(param_2 + 1);
  local_58[0] = 0;
  switch(*(undefined1 *)puVar1) {
  case 1:
    if (*(int *)(param_1 + 0x97c) == 0) {
      bVar14 = 0;
      if (*(char *)(param_1 + 0xbbc4) == '\0') {
        bVar14 = 2;
      }
      do {
        bVar14 = bVar14 + 1;
        if (**(uint **)(param_1 + 0x18) != 0) break;
      } while (bVar14 < 3);
      local_54 = **(uint **)(param_1 + 0x18) & 0xf0000000;
      if (local_54 == 0x10000000) {
        *puVar1 = 2;
        goto switchD_140019998_caseD_2;
      }
      if (local_54 == 0xf0000000) goto LAB_14001ab6c;
      *(short *)(param_1 + 0x1214) = *(short *)(param_1 + 0x1214) + 1;
      if (3000 < *(ushort *)(param_1 + 0x1214)) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20b) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20b,
                      (undefined1 *)(param_1 + 0x1190),4,bVar3,iVar4);
        }
        pcVar19 = 
        "Diag Reset(miniport)-During recovery DB never reached ready and its state logged)";
        iVar11 = 4;
        puVar16 = &local_54;
        goto LAB_140019a67;
      }
    }
    break;
  case 2:
switchD_140019998_caseD_2:
    bVar14 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar14 = 2;
    }
    do {
      bVar14 = bVar14 + 1;
      if (**(uint **)(param_1 + 0x50) != 0) break;
    } while (bVar14 < 3);
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    CompleteAllSrbs(param_1,bVar3,iVar4);
    *(undefined2 *)(param_1 + 0x1214) = 0;
    LsiMpiPartitionMemory(param_1,bVar3,iVar4);
    uVar12 = SendIOCInitMessage(param_1,bVar3,iVar4);
    if ((char)uVar12 == '\0') {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20d) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20d,
                    (undefined1 *)(param_1 + 0x1190),4,bVar3,iVar4);
      }
      LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                          "Diag Reset(miniport)-During Recovery Send IOC Init failed",bVar3,iVar4);
      KickStart(param_1,bVar3,iVar4);
      *(undefined4 *)(param_1 + 0x1218) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x1218) = 3;
    }
    break;
  case 3:
    bVar14 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar14 = 2;
    }
    do {
      bVar14 = bVar14 + 1;
      if (**(uint **)(param_1 + 0x18) != 0) break;
    } while (bVar14 < 3);
    local_54 = **(uint **)(param_1 + 0x18) & 0xf0000000;
    if (local_54 == 0x20000000) {
      *(undefined1 *)(param_1 + 0x121c) = 0;
      *(undefined8 *)(param_1 + 0x9c4) = 0;
      *(undefined4 *)(param_1 + 0x9cc) = 0;
      *(undefined8 *)(param_1 + 0xa64) = 0;
      *(undefined8 *)(param_1 + 0xa6c) = 0;
      *(undefined8 *)(param_1 + 0xa74) = 0;
      *(undefined8 *)(param_1 + 0xa7c) = 0;
      *(undefined8 *)(param_1 + 0xa84) = 0;
      *(undefined8 *)(param_1 + 0xa8c) = 0;
      *(undefined8 *)(param_1 + 0xa94) = 0;
      *(undefined8 *)(param_1 + 0xa9c) = 0;
      *(undefined4 *)(param_1 + 0xaa4) = 0;
      *(undefined1 *)(param_1 + 0x9c7) = 3;
      bVar8 = SendMessageViaHandShake(param_1,0,3);
      if ((!bVar8) || (uVar13 = ReceiveDataViaHandshake(param_1,0x22), (char)uVar13 == '\0')) {
        LogSystemEvent(param_1,0xad01000d,0xc004af02,
                       (byte *)"Handshake of a IOCFacts message failed, reading HBA FW version",
                       bVar3,iVar4);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x26e) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x26e,
                      (undefined1 *)0x0,0,bVar3,iVar4);
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x1164) = *(undefined4 *)(param_1 + 0xa84);
      }
      InitReplyFreeQueue(param_1);
      if (((*(char *)(param_1 + 0xb670) == '\0') &&
          (cVar9 = IsHbaFwDowngradeInProgress(param_1), cVar9 == '\0')) ||
         ((*(byte *)(param_1 + 0x18c0) & 1) != 0)) {
        *puVar1 = 4;
        *(bool *)(param_1 + 0x11e5) = *(char *)(param_1 + 0x11e5) == '\0';
        goto switchD_140019998_caseD_4;
      }
LAB_14001a27b:
      *puVar1 = 0x10;
    }
    else {
      if (local_54 == 0xf0000000) {
LAB_14001ab6c:
        *puVar1 = 0;
        *(undefined1 *)(param_1 + 0x1212) = 0;
        goto LAB_14001ac22;
      }
      *(short *)(param_1 + 0x1214) = *(short *)(param_1 + 0x1214) + 1;
      if (100 < *(ushort *)(param_1 + 0x1214)) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20c) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20c,
                      (undefined1 *)(param_1 + 0x1190),4,bVar3,iVar4);
        }
        pcVar19 = 
        "Diag Reset(miniport)-During Recovery FW didn\'t reach operational state,DB logged";
        iVar11 = 4;
        puVar16 = &local_54;
        goto LAB_140019c61;
      }
    }
    break;
  case 4:
switchD_140019998_caseD_4:
    cVar9 = *(char *)(param_1 + 0xb7ed);
    ReadAndSetSASPages(param_1,bVar3,iVar4);
    if (((cVar9 == '\0') && (*(char *)(param_1 + 0xb7ed) != '\0')) &&
       (*(int *)(param_1 + 0xb7f0) != 0)) {
      SetDriverTriggerValues(param_1,bVar3,iVar4);
    }
    ProcessDPMPage0(param_1,bVar3,iVar4);
    EnableDisableEvents(param_1,'\x01',bVar3,iVar4);
    puVar6 = *(undefined8 **)(param_1 + 0x568);
    *(undefined2 *)(param_1 + 0x1214) = 0;
    *puVar6 = 0;
    *(undefined4 *)(puVar6 + 1) = 0;
    *(undefined1 *)((longlong)puVar6 + 3) = 6;
    *(undefined1 *)(param_1 + 0x11d8) = 1;
    QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x9b2) * 0x10000 + 8,0,bVar3,iVar4);
    *puVar1 = 5;
    break;
  case 5:
    PollLSImpiIsr(param_1,bVar3,iVar4);
    if (*(char *)(param_1 + 0x11d8) == '\0') {
      *(undefined2 *)(param_1 + 0x1214) = 0;
      if (*(short *)(param_1 + 0x966) == 0) {
        *(char *)(param_1 + 0x121c) = *(char *)(param_1 + 0x121c) + '\x01';
        uVar17 = 4;
        if (*(ushort *)(param_1 + 0x99a) <= (ushort)*(byte *)(param_1 + 0x121c)) {
          uVar17 = 6;
        }
        *puVar1 = uVar17;
      }
      else {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20f) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20f,
                      (undefined1 *)(param_1 + 0x1190),4,bVar3,iVar4);
        }
        LogOperationalEvent(param_1,(int *)(param_1 + 0x966),2,0x4004af00,
                            "Diag Reset(miniport)-During Recovery port enable reply failed,its status logged"
                            ,bVar3,iVar4);
        KickStart(param_1,bVar3,iVar4);
        *puVar1 = 1;
      }
    }
    else {
      *(short *)(param_1 + 0x1214) = *(short *)(param_1 + 0x1214) + 1;
      if ((ushort)((ulonglong)*(uint *)(param_1 + 0x958) / 200) < *(ushort *)(param_1 + 0x1214)) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20e) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20e,
                      (undefined1 *)(param_1 + 0x1190),4,bVar3,iVar4);
        }
        iVar11 = 0;
        pcVar19 = "Diag Reset(miniport)-During recovery no port enable reply received";
        puVar16 = (uint *)0x0;
        goto LAB_140019c61;
      }
    }
    break;
  case 6:
    if ((*(char *)(param_1 + 0x11dc) == '\0') && (*(char *)(param_1 + 0x11dd) == '\0')) {
      MapSODChecks(param_1,bVar3,iVar4);
      CompressEnclosureTable(param_1);
      if ((*(char *)(param_1 + 0x11e5) == '\0') && (*(char *)(param_1 + 0x11e4) != '\0')) {
        *(undefined1 *)(param_1 + 0x11e4) = 0;
        FlushAllDPMPage0(param_1,bVar3,iVar4);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x100007) != 0))
        {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x100007,
                      (undefined1 *)puVar1,4,bVar3,iVar4);
        }
        iVar11 = 0;
        pcVar19 = "Diag Reset(miniport)-To reclaim device Mapping space during recovery";
        puVar16 = (uint *)0x0;
        goto LAB_140019c61;
      }
      *(undefined1 *)(param_1 + 0x11e5) = 1;
      *puVar1 = 7;
    }
    else {
      do {
        cVar9 = PollLSImpiIsr(param_1,bVar3,iVar4);
        StorPortStallExecution(500);
      } while (cVar9 != '\0');
      *(short *)(param_1 + 0x1214) = *(short *)(param_1 + 0x1214) + 1;
      if (12000 < *(ushort *)(param_1 + 0x1214)) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x275) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x275,
                      (undefined1 *)puVar1,4,bVar3,iVar4);
        }
        iVar11 = 0;
        pcVar19 = "Diag Reset(miniport)-During Recovery Device Mapping Timeout";
        puVar16 = (uint *)0x0;
        goto LAB_140019c61;
      }
    }
    break;
  case 7:
    InternalLSImpiHWInitialize(param_1,bVar3,iVar4);
    if (*(char *)(param_1 + 0x11bd) != '\0') {
      lVar7 = *(longlong *)(param_1 + 0x1228);
      if (lVar7 != 0) {
        local_44 = *(undefined4 *)(*(longlong *)(lVar7 + 0x40) + 0x14);
        local_48 = *(undefined4 *)(*(longlong *)(lVar7 + 0x40) + 0x10);
        local_40 = 1;
        *(undefined1 *)(lVar7 + 3) = 1;
        local_50 = lVar7;
        StorPortNotification(0,param_1);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40001f) != 0))
        {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40001f,
                      (undefined1 *)&local_50,0x11,bVar3,iVar4);
        }
      }
      *(undefined1 *)(param_1 + 0x11bd) = 0;
      *(undefined8 *)(param_1 + 0x1228) = 0;
    }
    if (((*(char *)(param_1 + 0xb9fc) != '\x01') &&
        (*(undefined1 *)(param_1 + 0xb9fc) = 1, *(char *)(param_1 + 0x608) != '\0')) &&
       ((*(uint *)(param_1 + 0x60c) & 0x40e) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40e,
                  (undefined1 *)0x0,0,bVar3,iVar4);
    }
    ResumeAdapterQueue(param_1,8,bVar3,iVar4);
    StorPortReady(param_1);
    if (((*(short *)(param_1 + 0x9aa) == 0) && (*(char *)(param_1 + 0x11d4) == '\0')) &&
       (uVar10 = 0, *(short *)(param_1 + 0x9a4) != 0)) {
      do {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40002) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40002,
                      (undefined1 *)0x0,0,bVar3,iVar4);
        }
        StorPortNotification(7);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(ushort *)(param_1 + 0x9a4));
    }
    *(undefined1 *)(param_1 + 0x11d4) = 0;
    *puVar1 = 0;
    if (*(char *)(param_1 + 0x11be) != '\0') {
      HbaFwReloadFsm(param_1,'\x01',0,bVar3,iVar4);
    }
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40001) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40001,
                  (undefined1 *)0x0,0,bVar3,iVar4);
    }
    LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,"Diag Reset completed",bVar3,iVar4);
    break;
  case 8:
    bVar14 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar14 = 2;
    }
    do {
      bVar14 = bVar14 + 1;
      if (**(uint **)(param_1 + 0x50) != 0) break;
    } while (bVar14 < 3);
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0xb65c) = 0;
    *(undefined4 *)(param_1 + 0xb660) = 100;
    *(undefined2 *)(param_1 + 0xb666) = 0;
LAB_14001a79b:
    *puVar1 = 9;
    break;
  case 9:
    SendSsuMessagesToDevices(param_1,bVar3,iVar4);
    uVar17 = 10;
    if (*(int *)(param_1 + 0xb65c) == 0) {
      uVar17 = 0xd;
    }
    *puVar1 = uVar17;
    break;
  case 10:
    uVar13 = ProcessSsuReplies(param_1,bVar3,iVar4);
    iVar11 = (int)uVar13;
    if (iVar11 == 1) {
      if ((*(char *)(param_1 + 0x608) == '\0') || ((*(uint *)(param_1 + 0x60c) & 0x80002) == 0))
      goto LAB_14001a978;
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80002,
                  (undefined1 *)(param_1 + 0xb65c),4,bVar3,iVar4);
      *puVar1 = 0xd;
    }
    else {
      if (iVar11 == 2) goto LAB_14001a79b;
      if (iVar11 == 3) {
        *puVar1 = 0xb;
      }
    }
    break;
  case 0xb:
    SendSsuTmrMessagesToDevices(param_1,bVar3,iVar4);
    *(undefined4 *)(param_1 + 0xb660) = 100;
    *puVar1 = 0xc;
    break;
  case 0xc:
    do {
      cVar9 = PollLSImpiIsr(param_1,bVar3,iVar4);
      StorPortStallExecution(500);
    } while (cVar9 != '\0');
    if (*(int *)(param_1 + 0xb65c) != 0) {
      piVar18 = (int *)(param_1 + 0xb660);
      *piVar18 = *piVar18 + -1;
      if (*piVar18 != 0) break;
      LogSystemEvent(param_1,0xad010071,0x8004af01,
                     (byte *)"TMR commands time out which are sent after SSU times out",bVar3,iVar4)
      ;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x80005) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x80005,
                    (undefined1 *)(param_1 + 0xb65c),4,bVar3,iVar4);
      }
      LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                          "Diag Reset(miniport)-TMR commands time out which are sent after SSU times out"
                          ,bVar3,iVar4);
      KickStart(param_1,bVar3,iVar4);
    }
LAB_14001a978:
    *puVar1 = 0xd;
    break;
  case 0xd:
    bVar14 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar14 = 2;
    }
    do {
      bVar14 = bVar14 + 1;
      if (**(uint **)(param_1 + 0x50) != 0) break;
    } while (bVar14 < 3);
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    *(undefined1 *)(param_1 + 0x11d4) = 1;
    FlushAllDPMPage0(param_1,bVar3,iVar4);
    *(undefined2 *)(param_1 + 0x1214) = 0;
    if ((*(uint *)(param_1 + 0x120c) & 0x2000) == 0) {
      *puVar1 = 0xf;
      LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                          "Diag Reset(miniport)-During Recovery FW doesn\'t support event replay",
                          bVar3,iVar4);
      KickStart(param_1,bVar3,iVar4);
    }
    else {
      **(undefined4 **)(param_1 + 0x18) = 0x40000000;
      LOCK();
      UNLOCK();
      *puVar1 = 0xe;
    }
    break;
  case 0xe:
    bVar14 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar14 = 2;
    }
    do {
      iVar5 = **(int **)(param_1 + 0x48);
      bVar14 = bVar14 + 1;
      if (iVar5 != 0) {
        if (iVar5 < 0) {
          if (iVar5 == -1) goto LAB_14001ab6c;
          *(short *)(param_1 + 0x1214) = *(short *)(param_1 + 0x1214) + 1;
          if (300 < *(ushort *)(param_1 + 0x1214)) {
            if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x210) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x210,
                          (undefined1 *)(param_1 + 0x1190),4,bVar3,iVar4);
            }
            LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                                "Diag Reset(miniport)-During Recovery No response of MUR",bVar3,
                                iVar4);
            KickStart(param_1,bVar3,iVar4);
          }
        }
        *(undefined2 *)(param_1 + 0x1214) = 0;
        *puVar1 = 0xf;
        goto switchD_140019998_default;
      }
    } while (bVar14 < 3);
    *(undefined2 *)(param_1 + 0x1214) = 0;
    *puVar1 = 0xf;
    break;
  case 0xf:
    bVar14 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar14 = 2;
    }
    do {
      bVar14 = bVar14 + 1;
      if (**(uint **)(param_1 + 0x18) != 0) break;
    } while (bVar14 < 3);
    local_54 = **(uint **)(param_1 + 0x18) & 0xf0000000;
    if (local_54 == 0x10000000) {
      *(undefined1 *)(*(longlong *)(param_1 + 0x928) + 3) = 1;
      StorPortNotification(0);
      *(undefined8 *)(param_1 + 0x928) = 0;
      *puVar1 = 0;
    }
    else {
      if (local_54 == 0xf0000000) goto LAB_14001ab6c;
      *(short *)(param_1 + 0x1214) = *(short *)(param_1 + 0x1214) + 1;
      if (300 < *(ushort *)(param_1 + 0x1214)) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20b) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20b,
                      (undefined1 *)(param_1 + 0x1190),4,bVar3,iVar4);
        }
        iVar11 = 0;
        pcVar19 = "Diag Reset(miniport)-During Recovery FW never reached ready";
        puVar16 = (uint *)0x0;
LAB_140019a67:
        LogOperationalEvent(param_1,(int *)puVar16,iVar11,0x4004af00,pcVar19,bVar3,iVar4);
        KickStart(param_1,bVar3,iVar4);
        *(undefined2 *)(param_1 + 0x1214) = 0;
      }
    }
    break;
  case 0x10:
    uVar15 = *(ushort *)(param_1 + 0x18bc);
    piVar18 = (int *)((longlong)*(void **)(param_1 + 0x1910) + 8);
    if (uVar15 != 0) {
      do {
        if (((*piVar18 != 0) && (piVar18[1] != 0)) ||
           (*(char *)((ulonglong)local_58[0] + *(longlong *)(param_1 + 0x18d8)) != '\0')) {
          *(undefined1 *)((ulonglong)local_58[0] + *(longlong *)(param_1 + 0x18d8)) = 1;
          *(undefined2 *)(param_1 + 0x1214) = 0;
          FlushDPMPage0Entry(param_1,bVar3,iVar4);
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x11d) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x11d,
                        (undefined1 *)local_58,2,bVar3,iVar4);
          }
          piVar18[0] = 0;
          piVar18[1] = 0;
          *(undefined1 *)((ulonglong)local_58[0] + *(longlong *)(param_1 + 0x18d8)) = 0;
          *puVar1 = 0x11;
          goto switchD_140019998_default;
        }
        local_58[0] = local_58[0] + 1;
        piVar18 = piVar18 + 5;
      } while (local_58[0] < uVar15);
    }
    uVar10 = (uint)uVar15 * 0x14 + 8;
    if (uVar10 != 0) {
      memset(*(void **)(param_1 + 0x1910),0,(ulonglong)uVar10);
      uVar15 = *(ushort *)(param_1 + 0x18bc);
    }
    uVar10 = (uint)uVar15;
    if ((uVar15 & 3) != 0) {
      uVar10 = uVar10 + (4 - (uVar10 & 3));
    }
    if (uVar10 != 0) {
      memset(*(void **)(param_1 + 0x18d8),0,(ulonglong)uVar10);
    }
    if (*(char *)(param_1 + 0xb670) == '\0') {
      if (*(char *)(param_1 + 0xb96e) != '\0') {
        *(undefined1 *)(param_1 + 0xb96e) = 0;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0xb670) = 0;
    }
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x10e) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x10e,
                  (undefined1 *)0x0,0,bVar3,iVar4);
    }
    *puVar1 = 4;
    *(bool *)(param_1 + 0x11e5) = *(char *)(param_1 + 0x11e5) == '\0';
    break;
  case 0x11:
    PollLSImpiIsr(param_1,bVar3,iVar4);
    if (*(char *)(param_1 + 0x11da) == '\0') {
      puVar2 = (ushort *)(param_1 + 0x185a);
      uVar15 = *puVar2;
      if (uVar15 == 0) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x11e) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x11e,
                      (undefined1 *)puVar2,2,bVar3,iVar4);
        }
        goto LAB_14001a27b;
      }
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x281) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x281,
                    (undefined1 *)puVar2,2,bVar3,iVar4);
        uVar15 = *(ushort *)(param_1 + 0x185a);
      }
      uVar10 = (uint)uVar15;
      pcVar19 = "DPM0 wrt cmd during FW downgrade process not success,ConfigPageStatus logged";
    }
    else {
      *(short *)(param_1 + 0x1214) = *(short *)(param_1 + 0x1214) + 1;
      if (*(ushort *)(param_1 + 0x1214) < 0x65) break;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x280) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x280,
                    (undefined1 *)0x0,0,bVar3,iVar4);
      }
      uVar10 = 0;
      pcVar19 = "No reply of DPM0 write cmd in FW downgrade process in 10 sec";
    }
    LogSystemEvent(param_1,uVar10,0x8004af01,(byte *)pcVar19,bVar3,iVar4);
    uVar15 = *(ushort *)(param_1 + 0x18bc);
    uVar10 = (uint)uVar15 * 0x14 + 8;
    if (uVar10 != 0) {
      memset(*(void **)(param_1 + 0x1910),0,(ulonglong)uVar10);
      uVar15 = *(ushort *)(param_1 + 0x18bc);
    }
    uVar10 = (uint)uVar15;
    if ((uVar15 & 3) != 0) {
      uVar10 = uVar10 + (4 - (uVar10 & 3));
    }
    if (uVar10 != 0) {
      memset(*(void **)(param_1 + 0x18d8),0,(ulonglong)uVar10);
    }
    if (*(char *)(param_1 + 0xb670) == '\0') {
      if (*(char *)(param_1 + 0xb96e) != '\0') {
        *(undefined1 *)(param_1 + 0xb96e) = 0;
      }
      iVar11 = 0;
      pcVar19 = "Diag Reset(miniport)-During Recovery DPM0 write failed or timed out";
      puVar16 = (uint *)0x0;
    }
    else {
      iVar11 = 0;
      *(undefined1 *)(param_1 + 0xb670) = 0;
      puVar16 = (uint *)0x0;
      pcVar19 = "Diag Reset(miniport)-During Recovery DPM0 write failed or timed out";
    }
LAB_140019c61:
    LogOperationalEvent(param_1,(int *)puVar16,iVar11,0x4004af00,pcVar19,bVar3,iVar4);
    KickStart(param_1,bVar3,iVar4);
    *(undefined2 *)(param_1 + 0x1214) = 0;
    *puVar1 = 1;
  }
switchD_140019998_default:
  iVar11 = *(int *)(param_1 + 0x1218);
LAB_14001ac22:
  uVar17 = 100000;
  if (iVar11 == 0) {
    uVar17 = 1000000;
  }
  if (*(int *)(param_1 + 0x97c) != 0) {
    iVar11 = *(int *)(param_1 + 0x97c) + -1;
    uVar17 = 1000000;
    *(int *)(param_1 + 0x97c) = iVar11;
    if (iVar11 == 0) {
      LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                          "Diag Reset(miniport)-During Recovery if there is any delay set",bVar3,
                          iVar4);
      KickStart(param_1,bVar3,iVar4);
    }
  }
  *(undefined1 *)(param_1 + 0x1211) = 0;
  uVar13 = StorPortNotification(6,param_1,WatchdogTimer,uVar17);
  return CONCAT71((int7)((ulonglong)uVar13 >> 8),1);
}



===== UarStuckAtsTimerCallback @ 14001ad10 =====

ulonglong UarStuckAtsTimerCallback
                    (longlong param_1,undefined8 param_2,undefined4 *param_3,byte param_4,
                    int param_5)

{
  ulonglong uVar1;
  
  *param_3 = 3;
  uVar1 = HandleUnitAttenReset
                    (param_1,*(ushort *)((longlong)param_3 + 10),(undefined8 *)0x0,
                     *(byte *)((longlong)param_3 + 5),*(byte *)((longlong)param_3 + 6),
                     *(char *)((longlong)param_3 + 7),'\0',param_4,param_5);
  return uVar1 & 0xffffffffffffff00;
}



===== UarStuckIoTimerCallback @ 14001ad60 =====

ulonglong UarStuckIoTimerCallback
                    (longlong param_1,undefined8 param_2,longlong param_3,byte param_4,int param_5)

{
  ulonglong uVar1;
  
  uVar1 = HandleUnitAttenReset
                    (param_1,*(ushort *)(param_3 + 10),(undefined8 *)0x0,*(byte *)(param_3 + 5),
                     *(byte *)(param_3 + 6),*(char *)(param_3 + 7),'\0',param_4,param_5);
  return uVar1 & 0xffffffffffffff00;
}



===== WatchdogTimer @ 14001adb0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WatchdogTimer(longlong param_1)

{
  int *piVar1;
  uint uVar2;
  undefined8 *puVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  uint local_res8 [2];
  longlong local_res10;
  int local_28;
  byte local_24;
  undefined8 local_20;
  
  local_28 = 8;
  bVar4 = 0;
  if (*(char *)(param_1 + 0xbbc4) == '\0') {
    bVar4 = 2;
  }
  local_24 = 0;
  do {
    uVar2 = **(uint **)(param_1 + 0x18);
    bVar4 = bVar4 + 1;
    if (uVar2 != 0) break;
  } while (bVar4 < 3);
  local_res8[0] = uVar2 & 0xf0000000;
  if ((*(int *)(param_1 + 0x1218) != 0) && (*(char *)(param_1 + 0xbbdc) == '\0'))
  goto LAB_14001b18b;
  if (uVar2 == 0xffffffff) {
    *(undefined1 *)(param_1 + 0x11d2) = 1;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x234) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x234,
                  (undefined1 *)0x0,0,0,8);
    }
    CompleteAllSrbs(param_1,0,8);
    bVar4 = 0;
    if (*(short *)(param_1 + 0x9a4) == 0) {
      return;
    }
    do {
      StorPortNotification(7,param_1,bVar4);
      bVar4 = bVar4 + 1;
    } while ((ushort)bVar4 < *(ushort *)(param_1 + 0x9a4));
    return;
  }
  if (local_res8[0] == 0x20000000) {
    if (((*(int *)(param_1 + 0x968) == 0) && (*(longlong *)(param_1 + 0x928) == 0)) &&
       (*(longlong *)(param_1 + 0x13b8 + (ulonglong)*(byte *)(param_1 + 0x12b0) * 8) != 0)) {
      AcquireIsrLocks(param_1,0,8);
      bVar4 = local_24;
      iVar6 = local_28;
      if (((*(int *)(param_1 + 0x968) == 0) && (*(longlong *)(param_1 + 0x928) == 0)) &&
         (*(longlong *)(param_1 + 0x13b8 + (ulonglong)*(byte *)(param_1 + 0x12b0) * 8) != 0)) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x23a) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x23a,
                      (undefined1 *)0x0,0,local_24,local_28);
        }
        LogSystemEvent(param_1,0xad010075,0x8004af01,
                       (byte *)"an orphaned reset found by watchdog timer on reset queue",bVar4,
                       iVar6);
        if (*(char *)(param_1 + 0x11ba) != '\0') {
          *(undefined4 *)(param_1 + 0x187c) = _DAT_0000aaaa;
        }
        CheckResetQueue(param_1,bVar4,iVar6);
      }
      ReleaseIsrLocks(param_1,0,8);
    }
    if (((*(char *)(param_1 + 0x1220) == '\0') && (*(longlong *)(param_1 + 0x1228) == 0)) &&
       (*(longlong *)(param_1 + 0x12b8 + (ulonglong)*(byte *)(param_1 + 0x12ae) * 8) != 0)) {
      SynchronizeAccess(param_1,SynchronizeHandleOrphanedIoctl,&local_28,0,8);
    }
    if ((*(char *)(param_1 + 0x11d4) == '\0') && (*(char *)(param_1 + 0x1212) == '\0')) {
      if ((*(int *)(param_1 + 0x978) != 0) &&
         (iVar6 = *(int *)(param_1 + 0x978) + -1, *(int *)(param_1 + 0x978) = iVar6, iVar6 == 0)) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x206) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x206,
                      (undefined1 *)0x0,0,0,8);
        }
        if (*(char *)(param_1 + 0x11be) == '\0') {
          *(undefined1 *)(param_1 + 0x11bd) = 1;
        }
        *(undefined4 *)(param_1 + 0x1218) = 1;
        LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                            "Diag Reset(By IOCTL or may be because of FW update IOCTL)",0,8);
        KickStart(param_1,0,8);
        *(undefined2 *)(param_1 + 0x1214) = 0;
        local_20 = 0;
        AcquireIsrLocks(param_1,0,8);
        SynchronizeRestartRecovery(param_1,&local_28);
        ReleaseIsrLocks(param_1,0,8);
        return;
      }
      if (*(int *)(param_1 + 0x9c0) != 0) {
        local_20 = 0;
        AcquireIsrLocks(param_1,0,8);
        ProcessSynchronousAction(param_1,&local_28);
        ReleaseIsrLocks(param_1,0,8);
      }
      if (*(int *)(param_1 + 0x620) != 0) {
        local_20 = 0;
        AcquireIsrLocks(param_1,0,8);
        GtfProcessTimers(param_1,&local_28);
        ReleaseIsrLocks(param_1,0,8);
      }
      if ((*(char *)(param_1 + 0x1220) != '\0') && (*(int *)(param_1 + 0x1284) != -0x21524111)) {
        uVar2 = *(int *)(param_1 + 0x1284) + 1;
        *(uint *)(param_1 + 0x1284) = uVar2;
        if ((*(longlong *)(param_1 + 0x1228) != 0) &&
           (*(int *)(*(longlong *)(param_1 + 0x1228) + 0x28) + 2U <= uVar2)) {
          LogSystemEvent(param_1,0xad010030,0x8004af01,(byte *)"An Ioctl timed out",0,8);
          *(undefined4 *)(param_1 + 0x1284) = 0xdeadbeef;
          PauseAdapterQueue(param_1,0xb,0,8);
          local_20 = 0;
          AcquireIsrLocks(param_1,0,8);
          HandleIoctlTimeout(param_1,&local_28);
          ReleaseIsrLocks(param_1,0,8);
          goto LAB_14001b8c2;
        }
      }
      if ((*(int *)(param_1 + 0x974) != 0) &&
         (iVar6 = *(int *)(param_1 + 0x974) + -1, *(int *)(param_1 + 0x974) = iVar6, iVar6 == 0)) {
        if (*(int *)(param_1 + 0x968) != 0) {
          LogSystemEvent(param_1,0xad010028,0x8004af01,
                         (byte *)"No reply received from a TM Reset (15 second timeout)",0,8);
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x207) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x207,
                        (undefined1 *)0x0,0,0,8);
          }
          *(undefined4 *)(param_1 + 0x1218) = 1;
          LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                              "Diag Reset(miniport)-No reply received from a TM Reset(15 sec timeout))"
                              ,0,8);
          KickStart(param_1,0,8);
          *(undefined2 *)(param_1 + 0x1214) = 0;
          local_20 = 0;
          AcquireIsrLocks(param_1,0,8);
          SynchronizeRestartRecovery(param_1,&local_28);
          ReleaseIsrLocks(param_1,0,8);
          return;
        }
        if (*(char *)(param_1 + 0x11b6) != '\0') {
          *(undefined1 *)(param_1 + 0x11b6) = 0;
          LogSystemEvent(param_1,0,0x8004af01,(byte *)"Nvme IO unit ctrl shutdown msg timed out",0,8
                        );
          uVar7 = 8;
          if (*(short *)(param_1 + 0xb664) == 0) {
            uVar7 = 0xd;
          }
          *(undefined4 *)(param_1 + 0x1218) = uVar7;
          local_20 = 0;
          AcquireIsrLocks(param_1,0,8);
          SynchronizeRestartRecovery(param_1,&local_28);
          ReleaseIsrLocks(param_1,0,8);
          return;
        }
      }
      if (((*(int *)(param_1 + 0x11e8) != 0) && (*(char *)(param_1 + 0xb670) == '\0')) &&
         (cVar5 = IsHbaFwDowngradeInProgress(param_1), cVar5 == '\0')) {
        piVar1 = (int *)(param_1 + 0x11e8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          FlushDPMPage0Entry(param_1,0,8);
        }
      }
      if ((*(int *)(param_1 + 0xb9f0) != 0) &&
         (iVar6 = *(int *)(param_1 + 0xb9f4), *(int *)(param_1 + 0xb9f4) = iVar6 + 1,
         iVar6 == *(int *)(param_1 + 0xb9f0))) {
        puVar3 = *(undefined8 **)(param_1 + 0x578);
        *(undefined4 *)(param_1 + 0xb9f4) = 0;
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[4] = 0;
        *(undefined4 *)(puVar3 + 5) = 0;
        *(undefined1 *)((longlong)puVar3 + 3) = 0x1b;
        *(undefined1 *)puVar3 = 0xf;
        *(undefined1 *)((longlong)puVar3 + 6) = 0x81;
        StorPortQuerySystemTime(&local_res10);
        local_res10 = (local_res10 + -0x19db1ded53e8000) / 10000;
        puVar3[4] = local_res10;
        *(undefined1 *)(param_1 + 0xb9f9) = 1;
        QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x9b6) * 0x10000 + 8,0,0,8);
        uVar8 = GtfStartTimer(param_1,1,10,IoUnitCtrlTimeSyncTimerCallback,0,0,8);
        *(char *)(param_1 + 0xb9f8) = (char)uVar8;
        if ((char)uVar8 == -2) {
          if (*(short *)(param_1 + 0x960) != 0) {
            LogSystemEvent(param_1,0,0x8004af01,
                           (byte *)"No timer available to time IO Unit Ctrl for TimeSync",0,8);
          }
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                        (undefined1 *)0x0,0,0,8);
          }
        }
      }
    }
LAB_14001b8c2:
    if (*(char *)(param_1 + 0x1211) == '\0') {
      StorPortNotification(6,param_1,WatchdogTimer,1000000);
    }
    else if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20a) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20a,
                  (undefined1 *)(param_1 + 0x1190),4,0,8);
      return;
    }
    return;
  }
  if (*(char *)(param_1 + 0xbbdb) == '\0') {
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x208) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x208,
                  (undefined1 *)local_res8,4,0,8);
    }
    LogSystemEvent(param_1,local_res8[0],0x4004af00,
                   (byte *)"WatchdogTimer FW not operational,DB state logged",0,8);
    bVar4 = 0;
    if (*(char *)(param_1 + 0xbbc4) == '\0') {
      bVar4 = 2;
    }
    do {
      bVar4 = bVar4 + 1;
      if (**(uint **)(param_1 + 0x50) != 0) break;
    } while (bVar4 < 3);
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x1218) = 1;
    if (*(int *)(param_1 + 0x970) == 0) {
      PauseAdapterQueue(param_1,0xc,0,8);
    }
  }
  if (local_res8[0] == 0x50000000) {
    bVar4 = *(byte *)(param_1 + 0xbbdb);
    if (bVar4 <= *(byte *)(param_1 + 0xbbda)) {
      *(byte *)(param_1 + 0xbbdb) = bVar4 + 1;
      if (bVar4 == 0) {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x27c) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x27c,
                      (undefined1 *)0x0,0,0,8);
        }
        LogSystemEvent(param_1,0,0x8004af01,
                       (byte *)"Watchdog timer detected FW entering CoreDump state",0,8);
      }
      *(undefined1 *)(param_1 + 0xbbdc) = 1;
      goto LAB_14001b8c2;
    }
    LogSystemEvent(param_1,0,0x8004af01,
                   (byte *)"FW could not exit CoreDump state within timeout limit",0,8);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x27d) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x27d,
                  (byte *)(param_1 + 0xbbda),1,0,8);
    }
LAB_14001b15a:
    if (*(char *)(param_1 + 0x11b6) != '\0') {
      *(undefined4 *)(param_1 + 0x1218) = 8;
    }
    KickStart(param_1,0,8);
    *(undefined2 *)(param_1 + 0xbbdb) = 0;
  }
  else if (local_res8[0] == 0x40000000) {
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x209) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x209,
                  (undefined1 *)(param_1 + 0x1190),4,0,8);
    }
    LogOperationalEvent(param_1,(int *)local_res8,4,0x4004af00,
                        "Diag Reset(miniport)-WatchdogTimer detected FW Fault,DB state logged",0,8);
    goto LAB_14001b15a;
  }
  *(undefined2 *)(param_1 + 0x1214) = 0;
LAB_14001b18b:
  local_20 = 0;
  AcquireIsrLocks(param_1,0,8);
  SynchronizeRestartRecovery(param_1,&local_28);
  ReleaseIsrLocks(param_1,0,8);
  return;
}



===== ZeroMemory @ 14001b970 =====

void ZeroMemory(void *param_1,uint param_2)

{
  if (param_2 == 0) {
    return;
  }
  memset(param_1,0,(ulonglong)param_2);
  return;
}



===== FillInPortInfo @ 14001b980 =====

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
  ZeroMemory(param_1 + 3,0x202);
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



===== HbaApiWmiCompletion @ 14001ba60 =====

undefined8
HbaApiWmiCompletion(longlong param_1,longlong param_2,ushort param_3,byte param_4,int param_5)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  uint *puVar9;
  char cVar10;
  longlong lVar11;
  ushort local_res18 [8];
  
  cVar10 = '\x01';
  lVar11 = (ulonglong)param_3 * 0x20 + *(longlong *)(param_1 + 0x598);
  lVar4 = *(longlong *)(lVar11 + 8);
  local_res18[0] = param_3;
  if (lVar4 == 0) {
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x211) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x211,
                  (undefined1 *)local_res18,2,param_4,param_5);
    }
    LogSystemEvent(param_1,0xad010024,0xc004af02,(byte *)"NULL Srb pointer (HbaApiWmiCompletion)",
                   param_4,param_5);
    return 1;
  }
  lVar5 = *(longlong *)(lVar4 + 0x68);
  iVar3 = *(int *)(lVar5 + 0x3c);
  puVar1 = (undefined8 *)(lVar5 + 8);
  *(undefined2 *)(lVar5 + 0x3a) = *(undefined2 *)(param_2 + 0xe);
  bVar2 = *(byte *)(lVar5 + 0x38);
  *(longlong *)(lVar5 + 0x28) = lVar11;
  if (bVar2 == 8) {
    puVar9 = (uint *)*puVar1;
    if (iVar3 != 2) {
      ProcessSASPortInfo(param_1,(int *)puVar9,lVar4);
      uVar6 = 0x1730;
      if (iVar3 == 1) {
        uVar6 = 8;
      }
      goto LAB_14001bc01;
    }
  }
  else {
    if ((bVar2 < 9) || ((10 < bVar2 && (bVar2 != 0xb)))) {
      uVar6 = 0;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x212) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x212,
                    (undefined1 *)0x0,0,param_4,param_5);
      }
      cVar10 = '\x04';
      goto LAB_14001bc01;
    }
    puVar9 = (uint *)*puVar1;
  }
  uVar7 = ProcessSASPortAttributes(param_1,puVar9,lVar4,param_4,param_5);
  if ((char)uVar7 == '\0') {
    return uVar7 & 0xffffffffffffff00;
  }
  uVar6 = 0x23c;
LAB_14001bc01:
  ScsiPortWmiPostProcess((longlong)puVar1,cVar10,uVar6);
  *(undefined4 *)(lVar4 + 0x3c) = *(undefined4 *)(lVar5 + 0x24);
  *(undefined1 *)(lVar4 + 3) = *(undefined1 *)(lVar5 + 0x21);
  uVar8 = StorPortNotification(0,param_1,lVar4);
  *(byte *)(lVar11 + 0x13) = *(byte *)(lVar11 + 0x13) | 1;
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== LSIWmiGetAdapHbaAttributes @ 14001bc60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool LSIWmiGetAdapHbaAttributes
               (longlong param_1,undefined8 *param_2,longlong param_3,byte param_4,int param_5)

{
  char cVar1;
  short sVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  byte bVar7;
  byte bVar8;
  char *pcVar9;
  ushort uVar10;
  undefined1 auStackY_118 [32];
  byte local_c0;
  undefined7 uStack_bf;
  undefined2 local_b8;
  byte local_b6;
  byte local_b0 [24];
  byte local_98 [8];
  byte abStack_90 [72];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar3 = *(longlong *)(param_1 + 0x1900);
  lVar4 = *(longlong *)(param_3 + 0x68);
  uVar6 = *(undefined8 *)(param_1 + 0x1874);
  VersionToStr(*(uint *)(param_1 + 0x1168),(char *)local_b0);
  VersionToStr(*(uint *)(param_1 + 0x1164),(char *)&local_c0);
  *param_2 = uVar6;
  *(undefined4 *)(param_2 + 1) = 0;
  *(int *)(param_2 + 2) = *(int *)(param_1 + 0x1150) * 0x10000 + *(int *)(param_1 + 0x115c);
  *(uint *)((longlong)param_2 + 0xc) = (uint)*(ushort *)(param_1 + 0x99a);
  ZeroMemory((void *)((longlong)param_2 + 0x14),0x82);
  *(undefined2 *)((longlong)param_2 + 0x14) = 0x80;
  uVar10 = 0;
  do {
    if (0x3f < uVar10) break;
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0x16) = (ushort)(byte)"Avago Technologies"[uVar5];
  } while ("Avago Technologies"[uVar10] != '\0');
  ZeroMemory((void *)((longlong)param_2 + 0x96),0x82);
  uVar10 = 0;
  *(undefined2 *)((longlong)param_2 + 0x96) = 0x80;
  cVar1 = *(char *)(lVar3 + 0x3c);
  while ((cVar1 != '\0' && (uVar10 < 0x40))) {
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0x98) = (ushort)*(byte *)(uVar5 + 0x3c + lVar3);
    cVar1 = *(char *)((ulonglong)uVar10 + 0x3c + lVar3);
  }
  ZeroMemory(param_2 + 0x23,0x202);
  uVar10 = 0;
  *(undefined2 *)(param_2 + 0x23) = 0x200;
  cVar1 = *(char *)(lVar3 + 0x1c);
  while ((cVar1 != '\0' && (uVar10 < 0x100))) {
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0x11a) = (ushort)*(byte *)(uVar5 + 0x1c + lVar3);
    cVar1 = *(char *)((ulonglong)uVar10 + 0x1c + lVar3);
  }
  uVar5 = 0x10;
  do {
    bVar7 = (byte)uVar5;
    sVar2 = *(short *)((longlong)param_2 + uVar5 * 2 + 0x118);
    if (sVar2 == 0x20) {
      *(undefined2 *)((longlong)param_2 + uVar5 * 2 + 0x118) = 0;
    }
    else if (sVar2 != 0) break;
    bVar8 = bVar7 - 1;
    uVar5 = (ulonglong)bVar8;
    bVar7 = 0;
  } while (bVar8 != 0);
  if (((uint)ChipIds != *(uint *)(param_1 + 0x1150)) ||
     (pcVar9 = BoardDesc, BoardDesc == (undefined *)0x0)) {
    pcVar9 = NoDesc;
  }
  ZeroMemory((void *)((longlong)param_2 + 0x31a),0x202);
  *(undefined2 *)((longlong)param_2 + 0x31a) = 0x200;
  uVar10 = 0;
  cVar1 = *pcVar9;
  while ((cVar1 != '\0' && (uVar10 < 0x100))) {
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0x31c) = (ushort)(byte)pcVar9[uVar5];
    cVar1 = pcVar9[uVar10];
  }
  local_98[0] = 0x41;
  local_98[1] = 0x76;
  local_98[2] = 0x61;
  local_98[3] = 0x67;
  local_98[4] = 0x6f;
  local_98[5] = 0x20;
  memmove(local_98 + 6,(void *)(lVar3 + 0x1c),(ulonglong)bVar7);
  (local_98 + (byte)(bVar7 + 6))[0] = 0x20;
  (local_98 + (byte)(bVar7 + 6))[1] = 0x46;
  local_98[(ulonglong)(byte)(bVar7 + 6) + 2] = 0x56;
  uVar5 = (ulonglong)(byte)(bVar7 + 9);
  *(ulonglong *)(local_98 + uVar5) = CONCAT71(uStack_bf,local_c0);
  *(undefined2 *)(local_98 + uVar5 + 8) = local_b8;
  abStack_90[uVar5 + 2] = local_b6;
  uVar5 = 0;
  (local_98 + (byte)(bVar7 + 0x14))[0] = 0x20;
  (local_98 + (byte)(bVar7 + 0x14))[1] = 0x44;
  local_98[(ulonglong)(byte)(bVar7 + 0x14) + 2] = 0x56;
  do {
    bVar8 = (&DAT_14002b10c)[uVar5];
    local_98[(uint)(byte)(bVar7 + 0x17) + (int)uVar5] = bVar8;
    if (bVar8 == 0) break;
    bVar8 = (char)uVar5 + 1;
    uVar5 = (ulonglong)bVar8;
  } while (bVar8 < 0x50);
  ZeroMemory((void *)((longlong)param_2 + 0xf26),0x202);
  uVar10 = 0;
  *(undefined2 *)((longlong)param_2 + 0xf26) = 0x200;
  bVar7 = local_98[0];
  while ((bVar7 != 0 && (uVar10 < 0x100))) {
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0xf28) = (ushort)local_98[uVar5];
    bVar7 = local_98[uVar10];
  }
  ZeroMemory((void *)((longlong)param_2 + 0x51c),0x202);
  uVar10 = 0;
  *(undefined2 *)((longlong)param_2 + 0x51c) = 0x200;
  cVar1 = *(char *)(lVar3 + 0x14);
  while ((cVar1 != '\0' && (uVar10 < 0x100))) {
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0x51e) = (ushort)*(byte *)(uVar5 + 0x14 + lVar3);
    cVar1 = *(char *)((ulonglong)uVar10 + 0x14 + lVar3);
  }
  ZeroMemory((void *)((longlong)param_2 + 0x71e),0x202);
  uVar10 = 0;
  *(undefined2 *)((longlong)param_2 + 0x71e) = 0x200;
  cVar1 = DAT_14002b10c;
  while ((cVar1 != '\0' && (uVar10 < 0x100))) {
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0x720) = (ushort)(byte)(&DAT_14002b10c)[uVar5];
    cVar1 = (&DAT_14002b10c)[uVar10];
  }
  ZeroMemory(param_2 + 0x124,0x202);
  uVar10 = 0;
  *(undefined2 *)(param_2 + 0x124) = 0x200;
  while ((local_b0[0] != 0 && (uVar10 < 0x100))) {
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0x922) = (ushort)local_b0[uVar5];
    local_b0[0] = local_b0[uVar10];
  }
  ZeroMemory((void *)((longlong)param_2 + 0xb22),0x202);
  uVar10 = 0;
  *(undefined2 *)((longlong)param_2 + 0xb22) = 0x200;
  while ((local_c0 != 0 && (uVar10 < 0x100))) {
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0xb24) = (ushort)local_b0[uVar5 - 0x10];
    local_c0 = local_b0[(ulonglong)uVar10 - 0x10];
  }
  ZeroMemory((void *)((longlong)param_2 + 0xd24),0x202);
  uVar10 = 0;
  *(undefined2 *)((longlong)param_2 + 0xd24) = 0x200;
  do {
    if (0xff < uVar10) break;
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0xd26) = (ushort)(byte)"ItSas35i"[uVar5];
  } while ("ItSas35i"[uVar10] != '\0');
  ZeroMemory(param_2 + 0x225,0x202);
  *(undefined2 *)(param_2 + 0x225) = 0x200;
  ZeroMemory((void *)((longlong)param_2 + 0x132a),0x202);
  *(undefined2 *)((longlong)param_2 + 0x132a) = 0x200;
  ZeroMemory((void *)((longlong)param_2 + 0x152c),0x202);
  uVar10 = 0;
  *(undefined2 *)((longlong)param_2 + 0x152c) = 0x200;
  cVar1 = MfgDomain[0];
  while ((cVar1 != '\0' && (uVar10 < 0x100))) {
    uVar5 = (ulonglong)uVar10;
    uVar10 = uVar10 + 1;
    *(ushort *)((longlong)param_2 + uVar5 * 2 + 0x152e) = (ushort)(byte)MfgDomain[uVar5];
    cVar1 = MfgDomain[uVar10];
  }
  *(undefined2 *)((longlong)param_2 + 0x152c) = 0x10;
  *(undefined1 *)(lVar4 + 0x38) = 8;
  *(undefined8 **)(lVar4 + 8) = param_2;
  uVar6 = SendHbaApiConfigMessage
                    (param_1,param_3,'\x01',(undefined4 *)(param_1 + 0x19a0),0,
                     (int)*(undefined8 *)(param_1 + 0x19c8),param_4,param_5);
  return (char)uVar6 != '\0';
}



===== LSImpiExecuteWmiMethod @ 14001c230 =====

ulonglong LSImpiExecuteWmiMethod
                    (longlong param_1,longlong *param_2,int param_3,undefined8 param_4,int param_5,
                    uint param_6,uint param_7,ulonglong *param_8)

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
    goto LAB_14001c25e;
  }
  if (param_5 == 1) {
    uVar4 = 8;
LAB_14001c2da:
    if (param_7 < uVar4) {
LAB_14001c2e0:
      bVar3 = 0x12;
      goto LAB_14001c25e;
    }
    uVar2 = LsiWmiGetSASPortInfo(param_1,(undefined4 *)param_8,lVar1,0,0xe);
  }
  else {
    if (param_5 == 2) {
      uVar4 = 0x23c;
      goto LAB_14001c2da;
    }
    if (param_5 != 4) {
      if (param_5 != 10) {
        *(undefined4 *)param_8 = 2;
        uVar4 = param_6;
      }
      goto LAB_14001c25e;
    }
    uVar4 = 0x23c;
    if (param_7 < 0x23c) goto LAB_14001c2e0;
    uVar2 = LsiWmiGetSASPortInfoByWWN(param_1,param_8,lVar1,0,0xe);
  }
  if ((char)uVar2 != '\0') {
    return uVar2 & 0xffffffffffffff00;
  }
LAB_14001c25e:
  ScsiPortWmiPostProcess((longlong)param_2,bVar3,uVar4);
  return (ulonglong)bVar3;
}



===== LSImpiFunctionControl @ 14001c320 =====

undefined8
LSImpiFunctionControl(longlong param_1,longlong param_2,int param_3,int param_4,char param_5)

{
  undefined8 uVar1;
  
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x402) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x402,
                (undefined1 *)0x0,0,0,0xf);
  }
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_5 == '\0') {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x103) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x103,
                    (undefined1 *)0x0,0,0,0xf);
      }
      *(undefined1 *)(param_1 + 0x18b1) = 0;
    }
    else {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x102) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x102,
                    (undefined1 *)0x0,0,0,0xf);
      }
      *(undefined1 *)(param_1 + 0x18b1) = 1;
    }
  }
  uVar1 = ScsiPortWmiPostProcess(param_2,'\x01',0);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== LSImpiQueryWmiDataBlock @ 14001c470 =====

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
LAB_14001c4e8:
    uVar4 = 4;
    uVar2 = 4;
    if (3 < param_7) {
      *param_6 = 4;
      goto LAB_14001c4ff;
    }
  }
  else {
    if (param_3 != 1) {
      if (param_3 != 2) {
        bVar5 = 4;
        goto LAB_14001c4ff;
      }
      goto LAB_14001c4e8;
    }
    uVar4 = 0x1730;
    uVar2 = 0x1730;
    if (0x172f < param_7) {
      *param_6 = 0x1730;
      bVar3 = LSIWmiGetAdapHbaAttributes(param_1,param_8,lVar1,0,0xb);
      if (bVar3) {
        return (ulonglong)extraout_var << 8;
      }
      goto LAB_14001c4ff;
    }
  }
  uVar4 = uVar2;
  bVar5 = 0x12;
LAB_14001c4ff:
  ScsiPortWmiPostProcess((longlong)param_2,bVar5,uVar4);
  return (ulonglong)bVar5;
}



===== LSImpiQueryWmiRegInfo @ 14001c530 =====

char * LSImpiQueryWmiRegInfo(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = L"MofResource";
  return "river has detected a Lost SRB";
}



===== LSImpiWmiInitialize @ 14001c540 =====

void LSImpiWmiInitialize(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x160) = 3;
  *(undefined ***)(param_1 + 0x168) = &LSImpiSasGuidList;
  *(code **)(param_1 + 0x170) = LSImpiQueryWmiRegInfo;
  *(code **)(param_1 + 0x178) = LSImpiQueryWmiDataBlock;
  *(code **)(param_1 + 0x198) = LSImpiFunctionControl;
  *(code **)(param_1 + 400) = LSImpiExecuteWmiMethod;
  *(undefined8 *)(param_1 + 0x188) = 0;
  *(undefined8 *)(param_1 + 0x180) = 0;
  return;
}



===== LSImpiWmiSrb @ 14001c5b0 =====

undefined8 LSImpiWmiSrb(longlong param_1,ushort *param_2,byte param_3,int param_4)

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
LAB_14001c66b:
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x22f) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x22f,
                  (undefined1 *)param_2,(uint)*param_2,param_3,param_4);
    }
    LogSystemEvent(param_1,0xad010056,0xc004af02,
                   (byte *)"ExSRB does not have an expected CDB16 or 32 data block(WMI)",param_3,
                   param_4);
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
    if (piVar7 == (int *)0x0) goto LAB_14001c66b;
    if ((*(byte *)((longlong)piVar7 + 9) & 1) == 0) {
      uVar2 = 1;
    }
    else {
      *(ushort **)(lVar1 + 8) = param_2;
      *(undefined8 *)(lVar1 + 0x28) = 0;
      uVar3 = ScsiPortWmiDispatchFunction
                        ((uint *)(param_1 + 0x160),*(byte *)(piVar7 + 2),param_1,lVar1 + 8,
                         *(ulonglong **)(piVar7 + 4),*(uint *)(param_2 + 0x1e),
                         *(uint **)(param_2 + 0x20));
      if ((char)uVar3 != '\0') goto LAB_14001c6ef;
      uVar2 = *(undefined1 *)(lVar1 + 0x21);
      uVar5 = *(undefined4 *)(lVar1 + 0x24);
    }
  }
  *(undefined4 *)(param_2 + 0x1e) = uVar5;
  *(undefined1 *)((longlong)param_2 + 3) = uVar2;
  uVar3 = StorPortNotification(0,param_1,param_2);
LAB_14001c6ef:
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== LsiWmiGetSASPortInfo @ 14001c710 =====

ulonglong LsiWmiGetSASPortInfo
                    (longlong param_1,undefined4 *param_2,longlong param_3,byte param_4,int param_5)

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
                    (param_1,param_3,'\x01',(undefined4 *)(param_1 + 0x19a0),0,
                     (int)*(undefined8 *)(param_1 + 0x19c8),param_4,param_5);
  if ((char)uVar2 == '\0') {
    *param_2 = 10;
    return uVar2;
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== LsiWmiGetSASPortInfoByWWN @ 14001c7a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong LsiWmiGetSASPortInfoByWWN
                    (longlong param_1,ulonglong *param_2,longlong param_3,byte param_4,int param_5)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  ulonglong uVar6;
  int iVar7;
  undefined4 *puVar8;
  char cVar9;
  undefined1 auStackY_88 [32];
  undefined4 uVar10;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar2 = *(longlong *)(param_3 + 0x68);
  if ((uint)param_2[2] < 0x1c) {
    *(undefined4 *)param_2 = 4;
    local_40 = local_40 & 0xffffffffffffff00;
  }
  else {
    local_48 = *param_2 & 0xf0ffffffffffffff;
    bVar4 = 0;
    do {
      if (*(char *)((longlong)&local_48 + (7 - (ulonglong)bVar4)) !=
          *(char *)((ulonglong)bVar4 + 0x1874 + param_1)) goto LAB_14001c8fc;
      bVar4 = bVar4 + 1;
    } while (bVar4 < 8);
    if ((bVar4 == 8) && (*(char *)(*(longlong *)(param_1 + 0x19c8) + 0xc) != '\0')) {
      iVar7 = 0;
      bVar4 = *(byte *)((longlong)param_2 + 7) & 0xf;
      if (bVar4 != 0) {
        cVar9 = '\0';
        uVar6 = 0;
        do {
          cVar1 = *(char *)(*(longlong *)(param_1 + 0x19c8) + 0x10 + uVar6 * 0x14);
          iVar3 = iVar7 + 1;
          if (cVar1 == cVar9) {
            iVar3 = iVar7;
          }
          iVar7 = iVar3;
          bVar5 = (char)uVar6 + 1;
          uVar6 = (ulonglong)bVar5;
          if (cVar1 == cVar9) {
            cVar1 = cVar9;
          }
          cVar9 = cVar1;
        } while (bVar5 <= bVar4);
      }
      *(int *)param_2 = iVar7;
      *(uint *)((longlong)param_2 + 4) = (uint)param_2[2];
      *(undefined4 *)(lVar2 + 0x3c) = 2;
      uVar6 = *(ulonglong *)(param_3 + 0x68);
      if ((*(int *)(uVar6 + 0x3c) == 2) && (*(uint *)((longlong)param_2 + 4) < 0x1c)) {
        *(undefined4 *)param_2 = 4;
        return uVar6 & 0xffffffffffffff00;
      }
      *(undefined1 *)(uVar6 + 0x38) = 8;
      puVar8 = (undefined4 *)(param_1 + 0x19a0);
      *(ulonglong **)(uVar6 + 8) = param_2;
      iVar7 = (int)*(undefined8 *)(param_1 + 0x19c8);
      uVar10 = 0;
    }
    else {
LAB_14001c8fc:
      puVar8 = (undefined4 *)(param_1 + 0x1920);
      *(undefined1 *)(lVar2 + 0x38) = 0xb;
      *(ulonglong **)(lVar2 + 8) = param_2;
      iVar7 = (int)*(undefined8 *)(param_1 + 0x1928);
      uVar10 = 0xffff;
    }
    local_40 = SendHbaApiConfigMessage(param_1,param_3,'\x01',puVar8,uVar10,iVar7,param_4,param_5);
    if ((char)local_40 == '\0') {
      *(undefined4 *)param_2 = 10;
    }
    else {
      local_40 = CONCAT71((int7)(local_40 >> 8),1);
    }
  }
  return local_40;
}



===== ProcessSASPortAttributes @ 14001c970 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
ProcessSASPortAttributes(longlong param_1,uint *param_2,longlong param_3,byte param_4,int param_5)

{
  byte *pbVar1;
  undefined1 uVar2;
  short sVar3;
  int iVar4;
  uint7 uVar8;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar9;
  uint *puVar10;
  longlong lVar11;
  longlong lVar12;
  byte bVar13;
  byte bVar14;
  undefined1 *puVar15;
  undefined1 auStackY_288 [32];
  int local_248 [2];
  longlong alStack_240 [63];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  lVar12 = *(longlong *)(param_3 + 0x68);
  bVar13 = *(byte *)(lVar12 + 0x38);
  sVar3 = *(short *)(lVar12 + 0x3a);
  uVar8 = (uint7)(byte)((ushort)sVar3 >> 8);
  if (bVar13 == 8) {
    lVar11 = *(longlong *)(param_1 + 0x19c8);
    uVar9 = *param_2;
    bVar13 = *(byte *)(lVar11 + 0xc);
    if (sVar3 != 0) goto LAB_14001cb58;
    memset(local_248,0,0x200);
    uVar7 = 0;
    if (bVar13 != 0) {
      do {
        pbVar1 = (byte *)(lVar11 + 0x10 + uVar7 * 0x14);
        if ((*(byte *)(lVar11 + 0x11 + uVar7 * 0x14) & 4) != 0) goto LAB_14001cc70;
        if (*(short *)(pbVar1 + 8) != 0) {
          uVar6 = (ulonglong)*pbVar1;
          local_248[uVar6 * 4] = local_248[uVar6 * 4] + 1;
          if (alStack_240[uVar6 * 2] == 0) {
            alStack_240[uVar6 * 2] = (longlong)pbVar1;
          }
        }
        bVar14 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar14;
      } while (bVar14 < bVar13);
    }
    iVar4 = local_248[(ulonglong)uVar9 * 4];
    if (iVar4 == 0) {
      *param_2 = 6;
      return 1;
    }
    lVar11 = alStack_240[(ulonglong)uVar9 * 2];
    switch(*(byte *)(lVar11 + 3) & 0xf) {
    default:
      uVar9 = 6;
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
      uVar9 = 2;
    }
    param_2[3] = uVar9;
    FillInPortInfo(param_2 + 2,*(uint *)(lVar11 + 4),iVar4);
    *param_2 = (uint)*(ushort *)(lVar11 + 8);
    *(undefined1 *)(lVar12 + 0x38) = 9;
    uVar9 = *(ushort *)(lVar11 + 10) | 0x20000000;
  }
  else {
    if (bVar13 < 9) goto LAB_14001cb58;
    if (10 < bVar13) {
      if (bVar13 != 0xb) {
LAB_14001cb58:
        *param_2 = 1;
        return CONCAT71(uVar8,1);
      }
      lVar12 = *(longlong *)(param_1 + 0x1928);
      if (sVar3 == 0x22) {
        *param_2 = 5;
        return 1;
      }
      if (sVar3 != 0) goto LAB_14001cb58;
      uVar7 = 0;
      while (*(char *)((lVar12 - uVar7) + 0x13) == *(char *)(uVar7 + (longlong)param_2)) {
        bVar13 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar13;
        if (7 < bVar13) {
          *(undefined8 *)(param_2 + 0x89) = *(undefined8 *)param_2;
          FillInPortInfo(param_2 + 2,*(uint *)(lVar12 + 0x1c),1);
          uVar5 = ZeroMemory(param_2 + 0x8b,8);
          param_2[0x8d] = 0;
          *param_2 = 0;
          return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
        }
      }
      uVar9 = (uint)*(ushort *)(lVar12 + 0x18);
      goto LAB_14001cc57;
    }
    lVar11 = *(longlong *)(param_1 + 0x1928);
    if (bVar13 != 9) {
      *param_2 = 0;
      if (sVar3 == 0x22) {
        uVar5 = ZeroMemory(param_2 + 0x8b,8);
        param_2[0x8d] = 0;
        return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
      }
      if (sVar3 != 0) {
        *param_2 = 1;
        return CONCAT71(uVar8,1);
      }
      puVar10 = param_2 + 0x8b;
      puVar15 = (undefined1 *)(lVar11 + 0x13);
      lVar12 = 8;
      do {
        uVar2 = *puVar15;
        puVar15 = puVar15 + -1;
        *(undefined1 *)puVar10 = uVar2;
        puVar10 = (uint *)((longlong)puVar10 + 1);
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      param_2[0x8d] = 1;
      return 1;
    }
    if (sVar3 != 0) goto LAB_14001cb58;
    puVar10 = param_2 + 0x89;
    puVar15 = (undefined1 *)(lVar11 + 0x13);
    lVar11 = 8;
    do {
      uVar2 = *puVar15;
      puVar15 = puVar15 + -1;
      *(undefined1 *)puVar10 = uVar2;
      puVar10 = (uint *)((longlong)puVar10 + 1);
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
    *(undefined1 *)(lVar12 + 0x38) = 10;
    uVar9 = *param_2 + 0x20000000;
  }
  lVar12 = *(longlong *)(param_1 + 0x1928);
LAB_14001cc57:
  uVar7 = SendHbaApiConfigMessage
                    (param_1,param_3,'\x01',(undefined4 *)(param_1 + 0x1920),uVar9,(int)lVar12,
                     param_4,param_5);
  if ((char)uVar7 != '\0') {
    return uVar7 & 0xffffffffffffff00;
  }
LAB_14001cc70:
  *param_2 = 10;
  return CONCAT71((int7)(uVar7 >> 8),1);
}



===== ProcessSASPortInfo @ 14001cce0 =====

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
  lVar2 = *(longlong *)(param_1 + 0x19c8);
  uVar7 = 0;
  bVar6 = *(byte *)(lVar2 + 0xc);
  uVar14 = (ulonglong)bVar6;
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
        pcVar11 = (char *)(lVar2 + 0x10 + uVar14 * 0x14);
        iVar4 = iVar10 + 1;
        cVar5 = *pcVar11;
        if (*pcVar11 == cVar9) {
          iVar4 = iVar10;
          cVar5 = cVar9;
        }
        cVar9 = cVar5;
        iVar10 = iVar4;
        if (*param_2 == iVar10) goto LAB_14001cdad;
        bVar12 = (char)uVar14 + 1;
        uVar14 = (ulonglong)bVar12;
      } while (bVar12 < bVar6);
    }
    if (bVar12 == bVar6) {
      *param_2 = 6;
    }
    else {
LAB_14001cdad:
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
    }
  }
  else if (sVar1 == 0) {
    if (bVar6 != 0) {
      pbVar8 = (byte *)(lVar2 + 0x10);
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
    param_2[3] = uVar15;
    return;
  }
  return;
}



===== SendHbaApiConfigMessage @ 14001ce70 =====

undefined8
SendHbaApiConfigMessage
          (longlong param_1,longlong param_2,char param_3,undefined4 *param_4,undefined4 param_5,
          int param_6,byte param_7,int param_8)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  ushort local_res10 [4];
  char local_res18;
  
  local_res10[0] = 0;
  puVar9 = *(undefined8 **)(*(longlong *)(param_2 + 0x68) + 0x28);
  local_res18 = param_3;
  if (puVar9 == (undefined8 *)0x0) {
    if (*(char *)(param_1 + 0xbbd0) == '\0') {
      plVar6 = (longlong *)GetHostReqTag(param_1,local_res10);
      if ((char)plVar6 == '\0') {
LAB_14001ceea:
        return (ulonglong)plVar6 & 0xffffffffffffff00;
      }
      puVar9 = (undefined8 *)((ulonglong)local_res10[0] * 0x20 + *(longlong *)(param_1 + 0x598));
    }
    else {
      plVar6 = *(longlong **)(param_1 + 0x910);
      puVar9 = (undefined8 *)*plVar6;
      if (puVar9[1] != 0) goto LAB_14001ceea;
      lVar7 = *(longlong *)(param_1 + 0x910) + 8;
      *(longlong *)(param_1 + 0x910) = lVar7;
      if (lVar7 == *(longlong *)(param_1 + 0x920)) {
        *(undefined8 *)(param_1 + 0x910) = *(undefined8 *)(param_1 + 0x908);
      }
    }
  }
  pcVar4 = (char *)*puVar9;
  uVar1 = *(ushort *)(puVar9 + 2);
  puVar9[1] = param_2;
  *(undefined1 *)((longlong)puVar9 + 0x13) = 0;
  ZeroMemory(pcVar4,0x2c);
  *pcVar4 = local_res18;
  pcVar4[3] = '\x04';
  *(undefined4 *)(puVar9 + 3) = 8;
  uVar3 = *param_4;
  *(undefined4 *)(pcVar4 + 0x14) = uVar3;
  uVar5 = (uint)*(byte *)((longlong)param_4 + 1);
  *(undefined4 *)(pcVar4 + 0x18) = param_5;
  if (((byte)((uint)uVar3 >> 0x18) & 0xf) == 0xf) {
    uVar2 = *(ushort *)(param_4 + 1);
    *(ushort *)(pcVar4 + 4) = uVar2;
    uVar5 = (uint)uVar2;
    pcVar4[6] = *(char *)((longlong)param_4 + 6);
  }
  pcVar4[0x1c] = '\0';
  pcVar4[0x1d] = '\0';
  pcVar4[0x1e] = '\0';
  pcVar4[0x1f] = -0x2d;
  *(int *)(pcVar4 + 0x20) = param_6 - *(int *)(param_1 + 0x108);
  *(undefined4 *)(pcVar4 + 0x24) = *(undefined4 *)(param_1 + 500);
  *(uint *)(pcVar4 + 0x1c) = uVar5 * 4 | 0xd3000000;
  if (local_res18 == '\x02') {
    *(uint *)(pcVar4 + 0x1c) = uVar5 * 4 | 0xd7000000;
  }
  uVar8 = QueueRequestDescriptor(param_1,(uint)uVar1 * 0x10000 + 8,0,param_7,param_8);
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== VersionToStr @ 14001d010 =====

void VersionToStr(uint param_1,char *param_2)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  
  cVar3 = '0';
  bVar1 = (byte)(param_1 >> 0x18);
  if (bVar1 < 10) {
    cVar2 = '0';
  }
  else {
    cVar2 = (char)((param_1 >> 0x18) / 10) + '0';
  }
  *param_2 = cVar2;
  param_2[2] = '.';
  param_2[1] = bVar1 + (char)((param_1 >> 0x18) / 10) * -10 + '0';
  uVar4 = param_1 >> 0x10 & 0xff;
  bVar1 = (byte)(param_1 >> 0x10);
  if (bVar1 < 10) {
    cVar2 = '0';
  }
  else {
    cVar2 = (char)(uVar4 / 10) + '0';
  }
  param_2[3] = cVar2;
  param_2[5] = '.';
  param_2[4] = bVar1 + (char)(uVar4 / 10) * -10 + '0';
  uVar4 = param_1 >> 8 & 0xff;
  bVar1 = (byte)(param_1 >> 8);
  if (bVar1 < 10) {
    cVar2 = '0';
  }
  else {
    cVar2 = (char)(uVar4 / 10) + '0';
  }
  param_2[6] = cVar2;
  param_2[8] = '.';
  param_2[7] = bVar1 + (char)(uVar4 / 10) * -10 + '0';
  if (9 < (byte)param_1) {
    cVar3 = (char)((param_1 & 0xff) / 10) + '0';
  }
  param_2[9] = cVar3;
  param_2[0xb] = '\0';
  param_2[10] = (byte)param_1 + (char)((param_1 & 0xff) / 10) * -10 + '0';
  return;
}



===== BuildNvmeEncapXlatedUnmapCommand @ 14001d130 =====

ulonglong BuildNvmeEncapXlatedUnmapCommand
                    (longlong param_1,longlong param_2,longlong param_3,byte param_4,int param_5)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  int iVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  undefined2 local_res10;
  undefined1 local_48 [16];
  
  puVar3 = *(undefined4 **)(param_2 + 0x68);
  uVar2 = *(undefined2 *)(param_3 + 0x1a);
  puVar1 = puVar3 + 0x5a;
  iVar4 = StorPortGetPhysicalAddress(param_1,param_2,puVar1,local_48);
  local_res10 = CONCAT11(*(undefined1 *)(*(longlong *)(param_2 + 0x40) + 2),
                         *(undefined1 *)(*(longlong *)(param_2 + 0x40) + 3));
  local_res10 = local_res10 >> 4;
  if (local_res10 < 0x101) {
    ZeroMemory(puVar1,0x60);
    *(undefined1 *)((longlong)puVar3 + 0x16b) = 0x33;
    puVar8 = puVar3 + 0x72;
    *(undefined2 *)puVar1 = uVar2;
    *(undefined2 *)(puVar3 + 0x5b) = 0x40;
    puVar3[0x5e] = iVar4 + -0x100;
    puVar3[0x5f] = *(undefined4 *)(param_1 + 500);
    puVar3[0x60] = 0x10010;
    puVar3[0x62] = 9;
    puVar3[0x6d] = 4;
    puVar3[99] = *(byte *)(puVar3 + 0x19) + 1;
    puVar3[0x68] = iVar4 + 0x60;
    puVar3[0x69] = *(undefined4 *)(param_1 + 500);
    puVar9 = (undefined1 *)(*(longlong *)(param_2 + 0x40) + 8);
    if (local_res10 != 0) {
      puVar7 = (undefined1 *)(*(longlong *)(param_2 + 0x40) + 0x12);
      puVar6 = (undefined1 *)((longlong)puVar3 + 0x1ce);
      do {
        *puVar8 = 0;
        local_res10 = local_res10 - 1;
        puVar6[1] = puVar7[-2];
        *puVar6 = puVar7[-1];
        puVar6[-1] = *puVar7;
        puVar6[-2] = puVar7[1];
        puVar6[9] = *puVar9;
        puVar6[8] = puVar7[-9];
        puVar6[7] = puVar7[-8];
        puVar6[6] = puVar7[-7];
        puVar6[5] = puVar7[-6];
        puVar6[4] = puVar7[-5];
        puVar6[3] = puVar7[-4];
        puVar6[2] = puVar7[-3];
        if (*(int *)(puVar6 + -2) != 0) {
          puVar8 = puVar8 + 4;
          puVar6 = puVar6 + 0x10;
          *(char *)(puVar3 + 0x6c) = *(char *)(puVar3 + 0x6c) + '\x01';
        }
        puVar9 = puVar9 + 0x10;
        puVar7 = puVar7 + 0x10;
      } while (local_res10 != 0);
    }
    uVar5 = 0;
    if (*(byte *)(puVar3 + 0x6c) != 0) {
      uVar5 = (ulonglong)*(byte *)(puVar3 + 0x6c) << 4;
      if ((uint)uVar5 <= *(uint *)(param_3 + 0x10)) {
        puVar3[0x61] = (uint)uVar5;
        *(char *)(puVar3 + 0x6c) = *(char *)(puVar3 + 0x6c) + -1;
        *puVar3 = 0x10;
        return CONCAT71((int7)(uVar5 >> 8),1);
      }
    }
  }
  else {
    uVar5 = LogSystemEvent(param_1,0xad010094,0xc004af02,
                           (byte *)
                           "BuildNvmeEncapXlatedUnmapCommand: Unmap to nvme has too many descriptors"
                           ,param_4,param_5);
  }
  return uVar5 & 0xffffffffffffff00;
}



===== CompleteNvmeEncapCommand @ 14001d330 =====

void CompleteNvmeEncapCommand
               (longlong param_1,longlong param_2,ushort param_3,byte param_4,int param_5)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  byte *pbVar4;
  longlong lVar5;
  ushort uVar6;
  ushort uVar7;
  longlong lVar8;
  ushort uVar9;
  undefined4 uVar10;
  longlong lVar11;
  char cVar12;
  ushort uVar13;
  char *pcVar14;
  undefined4 local_res8;
  byte local_resc;
  ushort local_res18 [4];
  
  lVar11 = (ulonglong)param_3 * 0x20 + *(longlong *)(param_1 + 0x598);
  lVar2 = *(longlong *)(lVar11 + 8);
  local_res18[0] = param_3;
  if (lVar2 == 0) {
    if (*(ushort *)(param_1 + 0x9ae) <= param_3) {
      return;
    }
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x219) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x219,
                  (undefined1 *)local_res18,2,param_4,param_5);
    }
    LogSystemEvent(param_1,0xad010024,0xc004af02,
                   (byte *)"NULL Srb pointer in CompleteNvmeEncapCommand",param_4,param_5);
    return;
  }
  ZeroMemory(&local_res8,5);
  lVar8 = *(longlong *)(lVar2 + 0x68);
  uVar6 = *(ushort *)(param_2 + 0xe) & 0x7fff;
  lVar3 = *(longlong *)(lVar8 + 0x40);
  if ((uVar6 == 0x48) || (uVar6 == 0x4b)) {
    local_res8 = CONCAT31(local_res8._1_3_,0xe);
    goto LAB_14001d566;
  }
  if (*(ushort *)(param_2 + 0x14) < 0x10) {
    pcVar14 = "NVMe error response count is less than NVMe completion queue entry";
    uVar10 = 0xad010095;
  }
  else {
    uVar6 = *(ushort *)(lVar8 + 0x76) >> 9;
    uVar13 = *(ushort *)(lVar8 + 0x76) >> 1;
    uVar9 = uVar13 & 0xff;
    uVar7 = uVar6 & 7;
    cVar12 = (char)uVar13;
    if ((uVar6 & 7) == 0) {
      lVar5 = (ulonglong)uVar9 * 5;
      if (cVar12 < '\0') {
        local_res8 = *(undefined4 *)(lVar5 + 0x14002b06a);
        local_resc = *(byte *)(lVar5 + 0x14002b06e);
      }
      else {
        local_res8 = *(undefined4 *)(&genericCommandStatusTable + lVar5);
        local_resc = *(byte *)(lVar5 + 0x14002b294);
      }
      goto LAB_14001d566;
    }
    if (uVar7 == 1) {
      lVar5 = (ulonglong)uVar9 * 5;
      if (cVar12 < '\0') {
        local_res8 = *(undefined4 *)(lVar5 + 0x14002b0d5);
        local_resc = *(byte *)(lVar5 + 0x14002b0d9);
      }
      else {
        local_res8 = *(undefined4 *)(&commandSpecificStatusTable + lVar5);
        local_resc = *(byte *)(lVar5 + 0x14002b304);
      }
      goto LAB_14001d566;
    }
    if (uVar7 == 2) {
      lVar5 = ((ulonglong)uVar9 - 0x80) * 5;
      local_res8 = *(undefined4 *)(&mediaErrorTable + lVar5);
      local_resc = *(byte *)(lVar5 + 0x14002b36c);
      goto LAB_14001d566;
    }
    pcVar14 = "CompleteNvmeEncapCommand: Unknown NVMe Status Code Type";
    uVar10 = 0xad010096;
  }
  LogSystemEvent(param_1,uVar10,0xc004af02,(byte *)pcVar14,param_4,param_5);
  local_res8 = CONCAT31(local_res8._1_3_,4);
LAB_14001d566:
  *(undefined1 *)(lVar2 + 3) = (undefined1)local_res8;
  *(char *)(lVar3 + 8) = local_res8._1_1_;
  if (((local_res8._1_1_ == '\x02') || (local_res8._1_1_ == '@')) && (0x11 < *(byte *)(lVar3 + 9)))
  {
    pbVar4 = *(byte **)(lVar3 + 0x10);
    ZeroMemory(pbVar4,(uint)*(byte *)(lVar3 + 9));
    *pbVar4 = *pbVar4 & 0xf0 | 0x70;
    pbVar4[2] = pbVar4[2] ^ (pbVar4[2] ^ local_res8._2_1_) & 0xf;
    pbVar4[0xc] = local_res8._3_1_;
    pbVar4[0xd] = local_resc;
    pbVar4[7] = 10;
    *(undefined1 *)(lVar3 + 9) = 0x12;
    *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) | 0x80;
  }
  else {
    *(undefined1 *)(lVar3 + 9) = 0;
  }
  if ((*(char *)(param_1 + 0xba00) != '\0') &&
     (lVar8 = (ulonglong)*(byte *)(lVar8 + 0x62) * 0x80 + (ulonglong)*(byte *)(lVar8 + 99),
     0 < *(int *)(*(longlong *)(param_1 + 0xba30) + lVar8 * 4))) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(param_1 + 0xba30) + lVar8 * 4);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
  }
  StorPortNotification(0,param_1,lVar2);
  pbVar4 = (byte *)(lVar11 + 0x13);
  *pbVar4 = *pbVar4 | 1;
  return;
}



===== CheckHbaFwReply @ 14001d640 =====

ulonglong CheckHbaFwReply(longlong param_1,longlong param_2,byte param_3,int param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  uVar1 = *(ulonglong *)(param_1 + 0x598);
  lVar3 = (ulonglong)*(ushort *)(param_2 + 2) * 0x20;
  if ((*(uint *)(lVar3 + 0x18 + uVar1) & 0x200) == 0) {
    return uVar1 & 0xffffffffffffff00;
  }
  *(undefined4 *)(lVar3 + 0x18 + uVar1) = 0;
  uVar2 = HbaFwReloadFsm(param_1,'\x01',
                         (ulonglong)*(uint *)(param_2 + 4) + *(longlong *)(param_1 + 0x108),param_3,
                         param_4);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== HbaFwDownloadTimeoutHandler @ 14001d6a0 =====

ulonglong HbaFwDownloadTimeoutHandler
                    (longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,int param_5
                    )

{
  ulonglong uVar1;
  
  *(undefined4 *)(param_1 + 0xb958) = 0xf;
  uVar1 = HbaFwReloadFsm(param_1,'\x01',0,param_4,param_5);
  return uVar1 & 0xffffffffffffff00;
}



===== HbaFwEraseFlashTimeoutHandler @ 14001d6d0 =====

ulonglong HbaFwEraseFlashTimeoutHandler
                    (longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,int param_5
                    )

{
  ulonglong uVar1;
  
  *(undefined4 *)(param_1 + 0xb958) = 0xc;
  uVar1 = HbaFwReloadFsm(param_1,'\x01',0,param_4,param_5);
  return uVar1 & 0xffffffffffffff00;
}



===== HbaFwReloadFsm @ 14001d700 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbaFwReloadFsm(longlong param_1,char param_2,longlong param_3,byte param_4,int param_5)

{
  int *piVar1;
  undefined1 *puVar2;
  void *_Src;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  undefined4 uVar6;
  longlong lVar7;
  longlong lVar8;
  int iVar9;
  uint *puVar10;
  longlong lVar11;
  ulonglong uVar12;
  int *piVar13;
  longlong lVar14;
  undefined4 uVar15;
  undefined1 auStackY_d8 [32];
  int *piVar16;
  uint uVar17;
  undefined4 local_90 [2];
  longlong local_88;
  undefined4 local_80;
  short local_7c;
  undefined1 local_78 [8];
  int local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  longlong local_60;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar7 = *(longlong *)(param_1 + 0x1228);
  piVar1 = (int *)(param_1 + 0xb958);
  lVar8 = *(longlong *)(lVar7 + 0x40);
  lVar14 = *(longlong *)(lVar7 + 0x68);
  local_48 = 0;
  local_4c = 0;
  local_88 = lVar14;
  local_60 = lVar8;
  local_58 = lVar7;
  if (param_2 == '\0') {
    if (*piVar1 != 0) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x26b) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x26b,
                    (undefined1 *)piVar1,0x20,param_4,param_5);
      }
      *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
      local_48 = 1;
      *(undefined1 *)(lVar7 + 3) = 1;
      local_4c = 1;
      local_50 = *(undefined4 *)(lVar8 + 0x10);
      *(undefined4 *)(lVar8 + 0x14) = 1;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400025) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400025,
                    (undefined1 *)&local_58,0x11,param_4,param_5);
      }
      StorPortNotification(0,param_1,lVar7);
      *piVar1 = 0;
      *(undefined8 *)(param_1 + 0x1228) = 0;
      return;
    }
    if ((*(uint *)(lVar8 + 0x28) & 1) == 0) {
      *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
      local_48 = 1;
      *(undefined1 *)(lVar7 + 3) = 1;
      local_4c = 2;
      local_50 = *(undefined4 *)(lVar8 + 0x10);
      *(undefined4 *)(lVar8 + 0x14) = 2;
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40001d) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40001d,
                    (undefined1 *)&local_58,0x11,param_4,param_5);
      }
      StorPortNotification(0,param_1,lVar7);
      *(undefined8 *)(param_1 + 0x1228) = 0;
      return;
    }
  }
  else if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400003) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400003,
                (undefined1 *)piVar1,0x20,param_4,param_5);
  }
LAB_14001d7d0:
  switch(*piVar1) {
  case 0:
    iVar9 = *(int *)(lVar8 + 0x24);
    if (iVar9 == 1) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400004) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400004,
                    (undefined1 *)piVar1,0x20,param_4,param_5);
      }
      *piVar1 = 1;
      *(undefined1 *)(param_1 + 0x1220) = 1;
    }
    else if (iVar9 == 2) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400005) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400005,
                    (undefined1 *)piVar1,0x20,param_4,param_5);
      }
      *piVar1 = 2;
      *(undefined1 *)(param_1 + 0x1220) = 1;
    }
    else if (iVar9 == 3) {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400006) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400006,
                    (undefined1 *)piVar1,0x20,param_4,param_5);
      }
      *piVar1 = 0x10;
      *(undefined1 *)(param_1 + 0x1220) = 1;
    }
    else {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 599) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),599,
                    (undefined1 *)(lVar8 + 0x1c),0x18,param_4,param_5);
      }
      *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
      *(undefined1 *)(lVar7 + 3) = 1;
      *(undefined4 *)(lVar8 + 0x14) = 3;
      *piVar1 = 0x12;
      *(undefined1 *)(param_1 + 0x1220) = 1;
    }
    goto LAB_14001d7d0;
  case 1:
    if (0x4b < *(uint *)(lVar8 + 0x18)) {
      *(undefined4 *)(lVar8 + 0x38) = 2;
      *(undefined4 *)(lVar8 + 0x3c) = 0x18;
      *(undefined4 *)(lVar8 + 0x40) = 0xff000101;
      *(undefined4 *)(lVar8 + 0x44) = 0;
      *(undefined4 *)(lVar8 + 0x48) = 4;
      *(undefined4 *)(lVar8 + 0x4c) = 0x100000;
      *(undefined2 *)(lVar8 + 0x50) = 0;
      HexVersionToString(*(uint *)(param_1 + 0x1164),(char *)(lVar8 + 0x58));
      *(undefined4 *)(lVar8 + 0x52) = 0;
      *(undefined2 *)(lVar8 + 0x56) = 0;
      *(undefined4 *)(lVar7 + 0x3c) = 0x4c;
      *(undefined1 *)(lVar7 + 3) = 1;
      *(undefined4 *)(lVar8 + 0x14) = 0;
      *piVar1 = 0x12;
      goto LAB_14001d7d0;
    }
    *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar7 + 3) = 1;
    *(undefined4 *)(lVar8 + 0x14) = 5;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x256) != 0)) {
      uVar15 = 0x256;
      uVar17 = 0;
      piVar16 = (int *)0x0;
      goto LAB_14001e552;
    }
    break;
  case 2:
    if (*(uint *)(lVar7 + 0x28) < 0x3c) {
      *(undefined4 *)(lVar7 + 0x28) = 0x3c;
    }
    if (*(uint *)(lVar8 + 0xc) < 0x3c) {
      *(undefined4 *)(lVar8 + 0xc) = 0x3c;
    }
    puVar10 = (uint *)StorPortGetScatterGatherList(param_1,lVar7);
    *(uint **)(lVar14 + 0x30) = puVar10;
    uVar17 = 0x101;
    if (*(uint *)(param_1 + 0x990) != 0) {
      uVar17 = *(uint *)(param_1 + 0x990);
    }
    if (*puVar10 <= uVar17) {
      iVar9 = 3;
      if ((*(uint *)(lVar8 + 0x28) & 4) == 0) {
        iVar9 = 0xd;
      }
      *piVar1 = iVar9;
      goto LAB_14001d7d0;
    }
    *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar7 + 3) = 1;
    *(undefined4 *)(lVar8 + 0x14) = 1;
    local_70 = 0x101;
    if (*(int *)(param_1 + 0x990) != 0) {
      local_70 = *(int *)(param_1 + 0x990);
    }
    local_6c = **(undefined4 **)(lVar14 + 0x30);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x26d) != 0)) {
      piVar16 = &local_70;
      uVar15 = 0x26d;
      uVar17 = 8;
      goto LAB_14001e552;
    }
    break;
  case 3:
    cVar3 = *(char *)(param_1 + 0xbbc4);
    lVar11 = 100;
    if (cVar3 != '\0') {
      lVar11 = 0x164;
    }
    piVar16 = (int *)(lVar11 + lVar8);
    piVar13 = (int *)(lVar8 + 0x160);
    if (cVar3 == '\0') {
      piVar13 = (int *)(lVar8 + 0x60);
    }
    if ((*piVar13 == -0x5aa5055b) ||
       (((*piVar13 == -0x5aa5155b && (*piVar16 == 0x5aa55afa)) || (*piVar16 == 0x5aa55aea)))) {
      lVar11 = 0xb0;
      if (cVar3 == '\0') {
        lVar11 = 0x70;
      }
      *(undefined4 *)(param_1 + 0xb968) = *(undefined4 *)(lVar11 + lVar8);
      *(undefined4 *)(param_1 + 0xb970) = *(undefined4 *)(lVar8 + 0x54);
      *piVar1 = 4;
      goto LAB_14001d7d0;
    }
    *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar7 + 3) = 1;
    *(undefined4 *)(lVar8 + 0x14) = 7;
    local_68 = *piVar13;
    local_64 = *piVar16;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x264) != 0)) {
      piVar16 = &local_68;
      uVar15 = 0x264;
      uVar17 = 8;
      goto LAB_14001e552;
    }
    break;
  case 4:
    goto switchD_14001d7e7_caseD_4;
  case 5:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x9b0) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0;
    piVar16 = (int *)(param_3 + 0xe);
    if (*(short *)piVar16 == 0) {
      local_90[0] = *(undefined4 *)(param_3 + 0x14);
      *(undefined4 *)
       ((ulonglong)*(ushort *)(param_1 + 0x9b0) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) =
           0x200;
      SendConfigPageMessage
                (param_1,'\x01',local_90,0,(int)*(undefined8 *)(param_1 + 0x1860),param_4,param_5);
      *piVar1 = 6;
      return;
    }
    *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar7 + 3) = 1;
    *(undefined4 *)(lVar8 + 0x14) = 0x10;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x265) != 0)) {
      uVar15 = 0x265;
      uVar17 = 2;
LAB_14001e552:
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar15,
                  (undefined1 *)piVar16,uVar17,param_4,param_5);
    }
    break;
  case 6:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x9b0) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0;
    piVar16 = (int *)(param_3 + 0xe);
    if (*(short *)piVar16 == 0) {
      bVar4 = *(byte *)(*(longlong *)(param_1 + 0x1860) + 0x13);
      if ((*(byte *)(param_1 + 0xb96b) < bVar4) ||
         ((*(byte *)(param_1 + 0xb96b) == bVar4 &&
          (*(byte *)(param_1 + 0xb96a) < *(byte *)(*(longlong *)(param_1 + 0x1860) + 0x12))))) {
        *(undefined1 *)(param_1 + 0xb96e) = 1;
        *piVar1 = 7;
      }
      else {
        *piVar1 = 0xd;
      }
      goto LAB_14001d7d0;
    }
    *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar7 + 3) = 1;
    *(undefined4 *)(lVar8 + 0x14) = 0x10;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x266) != 0)) {
      uVar15 = 0x266;
      uVar17 = 2;
      goto LAB_14001e552;
    }
    break;
  case 7:
    ZeroMemory((void *)(param_1 + 0x1908),8);
    *(undefined4 *)(param_1 + 0x190a) = 0xf00;
    *(undefined1 *)(param_1 + 0x190e) = 0x17;
    *(undefined1 *)(param_1 + 0x9ba) = 0;
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x9b0) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) =
         0x200;
    SendExtendedConfigPageMessage(param_1,'\0',(char *)(param_1 + 0x1908),0,0,param_4,param_5);
    *piVar1 = 8;
    return;
  case 8:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x9b0) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0;
    if ((*(ushort *)(param_3 + 0xe) & 0x7fff) == 0) {
      *(undefined2 *)(param_1 + 0xb96c) = *(undefined2 *)(param_1 + 0x190c);
      uVar5 = *(ushort *)(param_1 + 0x18bc);
      *(undefined1 *)(param_1 + 0x9ba) = 0;
      *(ushort *)(param_1 + 0x190c) = (ushort)(uVar5 * 0x14 + 8) >> 2;
      *(undefined4 *)
       ((ulonglong)*(ushort *)(param_1 + 0x9b0) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) =
           0x200;
      SendExtendedConfigPageMessage
                (param_1,'\x06',(char *)(param_1 + 0x1908),(uint)uVar5 << 0x10,
                 (int)*(undefined8 *)(param_1 + 0x1910),param_4,param_5);
      *piVar1 = 9;
      return;
    }
    *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar7 + 3) = 1;
    *(undefined4 *)(lVar8 + 0x14) = 0x10;
    LogSystemEvent(param_1,0xad010047,0xc004af02,
                   (byte *)"a read of DPM Page 0 header returned an error (HbaFwReloadFsm)",param_4,
                   param_5);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x267) != 0)) {
      uVar15 = 0x267;
LAB_14001e047:
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar15,
                  (undefined1 *)(param_3 + 0xe),2,param_4,param_5);
    }
    goto LAB_14001e073;
  case 9:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x9b0) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0;
    *(short *)(param_1 + 0x190c) = *(short *)(param_1 + 0xb96c) + 5;
    if ((*(ushort *)(param_3 + 0xe) & 0x7fff) != 0) {
      *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
      *(undefined1 *)(lVar7 + 3) = 1;
      *(undefined4 *)(lVar8 + 0x14) = 0x10;
      LogSystemEvent(param_1,0xad010047,0xc004af02,
                     (byte *)"a read of DPM Page 0 returned an error (HbaFwReloadFsm)",param_4,
                     param_5);
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x268) != 0)) {
        uVar15 = 0x268;
        goto LAB_14001e047;
      }
LAB_14001e073:
      *(undefined1 *)(param_1 + 0xb96e) = 0;
LAB_14001e079:
      lVar14 = local_88;
      goto LAB_14001e07d;
    }
    *piVar1 = 10;
    lVar14 = local_88;
    goto LAB_14001d7d0;
  case 10:
    puVar2 = *(undefined1 **)(param_1 + 0x948);
    iVar9 = StorPortGetPhysicalAddress(param_1,0,puVar2,local_78);
    ZeroMemory(puVar2,0x10);
    puVar2[3] = 0x17;
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 0xc) = 0x4000000;
    uVar12 = GtfStartTimer(param_1,1,0x1e,HbaFwEraseFlashTimeoutHandler,0,param_4,param_5);
    *(char *)(param_1 + 0xb975) = (char)uVar12;
    if ((((char)uVar12 == -2) && (*(char *)(param_1 + 0x608) != '\0')) &&
       ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                  (undefined1 *)0x0,0,param_4,param_5);
    }
    uVar5 = *(ushort *)(param_1 + 0x9ae);
    *(undefined4 *)((ulonglong)uVar5 * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0x200;
    *(int *)(puVar2 + 0x14) = iVar9 + 0x10;
    *(undefined4 *)(puVar2 + 0x10) = 0xd3000000;
    *(undefined4 *)(puVar2 + 0x18) = *(undefined4 *)(param_1 + 500);
    QueueRequestDescriptor(param_1,(uint)uVar5 << 0x10 | 8,0,param_4,param_5);
    *piVar1 = 0xb;
    return;
  case 0xb:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x9ae) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0;
    GtfStopTimer(param_1,*(byte *)(param_1 + 0xb975),param_4,param_5);
    if ((*(ushort *)(param_3 + 0xe) & 0x7fff) != 0) {
      *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
      *(undefined1 *)(lVar7 + 3) = 1;
      *(undefined4 *)(lVar8 + 0x14) = 0x10;
      LogSystemEvent(param_1,0xad01009a,0xc004af02,
                     (byte *)"Error received in MPI ToolBox Clean reply command (HbaFwReloadFsm)",
                     param_4,param_5);
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x269) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x269,
                    (undefined1 *)(param_3 + 0xe),2,param_4,param_5);
      }
      *(undefined1 *)(param_1 + 0xb96e) = 0;
      *(undefined4 *)(param_1 + 0x1218) = 1;
      PauseAdapterQueue(param_1,0xf,param_4,param_5);
      *(undefined2 *)(param_1 + 0x1214) = 0;
      LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                          "Diag Reset(miniport)-Error received in MPI ToolBox Clean reply during FW update"
                          ,param_4,param_5);
      KickStart(param_1,param_4,param_5);
      goto LAB_14001e079;
    }
    *piVar1 = 0xd;
    lVar14 = local_88;
    goto LAB_14001d7d0;
  case 0xc:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x9ae) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0;
    *(undefined1 *)(lVar7 + 3) = 1;
    *(undefined4 *)(lVar8 + 0x14) = 1;
    LogSystemEvent(param_1,0xad01009a,0xc004af02,
                   (byte *)"MPI ToolBox Clean command timed out (HbaFwReloadFsm)",param_4,param_5);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x26a) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x26a,
                  (undefined1 *)0x0,0,param_4,param_5);
    }
    *(undefined4 *)(param_1 + 0x1218) = 1;
    PauseAdapterQueue(param_1,0x10,param_4,param_5);
    *(undefined2 *)(param_1 + 0x1214) = 0;
    LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                        "Diag Reset(miniport)- MPI ToolBox Clean cmd timed out during FW update",
                        param_4,param_5);
    KickStart(param_1,param_4,param_5);
    goto LAB_14001e07d;
  case 0xd:
    if (*(char *)(lVar8 + 0x50) == '\0') {
      puVar2 = (undefined1 *)(lVar14 + 0x168);
      iVar9 = StorPortGetPhysicalAddress(param_1,lVar7,puVar2,local_78);
      ZeroMemory(puVar2,(uint)*(ushort *)(param_1 + 0x534));
      *puVar2 = 1;
      *(undefined1 *)(local_88 + 0x16b) = 9;
      *(undefined4 *)(local_88 + 0x180) = *(undefined4 *)(lVar8 + 0x40);
      *(undefined4 *)(local_88 + 0x184) = *(undefined4 *)(lVar8 + 0x48);
      *(undefined4 *)(local_88 + 0x174) = *(undefined4 *)(param_1 + 0xb970);
      if ((*(uint *)(lVar8 + 0x28) & 2) != 0) {
        *(undefined1 *)(local_88 + 0x16f) = 1;
        *(undefined4 *)(param_1 + 0xb970) = 0;
      }
      uVar15 = *(undefined4 *)(lVar7 + 0x18);
      uVar6 = *(undefined4 *)(lVar7 + 0x3c);
      *(undefined4 *)(lVar7 + 0x18) = 0x80;
      *(undefined4 *)(lVar7 + 0x3c) = *(undefined4 *)(local_88 + 0x184);
      _Src = (void *)(local_88 + 0x168);
      BuildIeeeScatterGather(param_1,lVar7,(int)local_60 + 0x58,(longlong)_Src,iVar9);
      *(undefined4 *)(lVar7 + 0x18) = uVar15;
      *(undefined4 *)(lVar7 + 0x3c) = uVar6;
      uVar5 = *(ushort *)(param_1 + 0x9ae);
      memmove(*(void **)(param_1 + 0x948),_Src,(ulonglong)*(ushort *)(param_1 + 0x534));
      uVar12 = GtfStartTimer(param_1,1,0x1e,HbaFwDownloadTimeoutHandler,0,param_4,param_5);
      *(char *)(param_1 + 0xb974) = (char)uVar12;
      if ((((char)uVar12 == -2) && (*(char *)(param_1 + 0x608) != '\0')) &&
         ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                    (undefined1 *)0x0,0,param_4,param_5);
      }
      *piVar1 = 0xe;
      *(undefined4 *)((ulonglong)uVar5 * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0x200;
      QueueRequestDescriptor(param_1,(uint)uVar5 * 0x10000 + 8,0,param_4,param_5);
      return;
    }
    *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar7 + 3) = 1;
    *(undefined4 *)(lVar8 + 0x14) = 6;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x25a) != 0)) {
      uVar15 = 0x25a;
      uVar17 = 0;
      piVar16 = (int *)0x0;
      goto LAB_14001e552;
    }
    break;
  case 0xe:
    GtfStopTimer(param_1,*(byte *)(param_1 + 0xb974),param_4,param_5);
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x9ae) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0;
    if ((*(ushort *)(param_3 + 0xe) & 0x7fff) == 0) {
      *(undefined4 *)(lVar8 + 0x14) = 0;
      if (*(int *)(param_3 + 0x10) == 0x30010412) goto LAB_14001e3a5;
    }
    else {
      if ((*(ushort *)(param_3 + 0xe) & 0x7fff) == 4) {
        *(undefined4 *)(lVar8 + 0x14) = 0x10;
      }
      else {
        *(undefined4 *)(lVar8 + 0x14) = 1;
      }
LAB_14001e3a5:
      local_7c = *(short *)(param_3 + 0xe);
      local_80 = 0;
      if (local_7c < 0) {
        local_80 = *(undefined4 *)(param_3 + 0x10);
      }
      iVar9 = *(int *)(param_3 + 0x10);
      if (iVar9 == 0x30010412) {
        uVar15 = 0x30010412;
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x286) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x286,
                      (undefined1 *)&local_80,8,param_4,param_5);
          uVar15 = *(undefined4 *)(param_3 + 0x10);
        }
        LogSystemEvent(param_1,uVar15,0x8004af01,
                       (byte *)"HBA FW download POR required (HbaFwReloadFsm)-LogInfo recorded",
                       param_4,param_5);
        *(undefined4 *)(lVar8 + 0x14) = 0x20;
      }
      else {
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x25b) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x25b,
                      (undefined1 *)&local_80,8,param_4,param_5);
          iVar9 = *(int *)(param_3 + 0x10);
        }
        LogSystemEvent(param_1,iVar9,0xc004af02,
                       (byte *)"HBA FW download Error occured (HbaFwReloadFsm)-LogInfo recorded",
                       param_4,param_5);
      }
    }
    *(undefined1 *)(lVar7 + 3) = 1;
    *piVar1 = 0x12;
    goto LAB_14001d7d0;
  case 0xf:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x9ae) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0;
    *(undefined4 *)(lVar7 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar7 + 3) = 1;
    *(undefined4 *)(lVar8 + 0x14) = 1;
    LogSystemEvent(param_1,0xad01009b,0xc004af02,
                   (byte *)"Firmware Download Reply Message timed out (HbaFwReloadFsm)",param_4,
                   param_5);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 600) != 0)) {
      piVar16 = (int *)0x0;
      uVar15 = 600;
      uVar17 = 0;
      goto LAB_14001e552;
    }
    break;
  case 0x10:
    if (*(uint *)(lVar7 + 0x28) < 0x1e) {
      *(undefined4 *)(lVar7 + 0x28) = 0x1e;
    }
    if (*(uint *)(lVar8 + 0xc) < 0x1e) {
      *(undefined4 *)(lVar8 + 0xc) = 0x1e;
    }
    PauseAdapterQueue(param_1,0x11,param_4,param_5);
    ResetActive(param_1,0x16,param_4,param_5);
    EnableDisableEvents(param_1,'\0',param_4,param_5);
    *(undefined1 *)(param_1 + 0x11be) = 1;
    *(undefined4 *)(param_1 + 0x978) = 4;
    *piVar1 = 0x11;
    return;
  case 0x11:
    *(undefined1 *)(param_1 + 0x11be) = 0;
    *(undefined4 *)(lVar7 + 0x3c) = 0;
    *(undefined1 *)(lVar7 + 3) = 1;
    *(undefined8 *)(lVar8 + 0x14) = 0;
    ResetActive(param_1,0x40000016,param_4,param_5);
LAB_14001e07d:
    *piVar1 = 0x12;
    goto LAB_14001d7d0;
  case 0x12:
    *(undefined1 *)(param_1 + 0x1220) = 0;
    *(undefined8 *)(param_1 + 0x1228) = 0;
    CheckIoctlQueue(param_1,param_4,param_5);
    local_50 = *(undefined4 *)(lVar8 + 0x10);
    local_4c = *(undefined4 *)(lVar8 + 0x14);
    local_48 = *(undefined1 *)(lVar7 + 3);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x40001e) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x40001e,
                  (undefined1 *)&local_58,0x11,param_4,param_5);
    }
    StorPortNotification(0,param_1,lVar7);
    *piVar1 = 0;
    return;
  default:
    return;
  }
  *piVar1 = 0x12;
  goto LAB_14001d7d0;
switchD_14001d7e7_caseD_4:
  local_90[0] = 0;
  *(undefined4 *)
   ((ulonglong)*(ushort *)(param_1 + 0x9b0) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x598)) = 0x200;
  SendConfigPageMessage(param_1,'\0',local_90,0,0,param_4,param_5);
  *piVar1 = 5;
  return;
}



===== IsHbaFwDowngradeInProgress @ 14001eb90 =====

undefined1 IsHbaFwDowngradeInProgress(longlong param_1)

{
  return *(undefined1 *)(param_1 + 0xb96e);
}



===== BusResetTimerCallback @ 14001eba0 =====

ulonglong BusResetTimerCallback
                    (longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,int param_5
                    )

{
  ulonglong uVar1;
  
  uVar1 = ProcessBusReset(param_1,param_4,param_5);
  return uVar1 & 0xffffffffffffff00;
}



===== LSImpiReset @ 14001ebc0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 LSImpiReset(longlong param_1,uint param_2,byte param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  ushort local_res8 [4];
  undefined2 local_28 [8];
  
  if (*(short *)(param_1 + 0x960) != 0) {
    in_RAX = LogSystemEvent(param_1,0xad010016,0xc004af02,
                            (byte *)"Task Management bus reset message issued",param_3,param_4);
  }
  uVar1 = 0;
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20013) != 0)) {
    in_RAX = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20013,
                         (undefined1 *)0x0,0,param_3,param_4);
  }
  if (*(char *)(param_1 + 0x11b8) != '\0') {
    in_RAX = (ulonglong)_DAT_00000002;
    *(uint *)(param_1 + 0x187c) = _DAT_00000002;
  }
  if (*(int *)(param_1 + 0x1218) == 0) {
    if (*(longlong *)(param_1 + 0x928) == 0) {
      uVar2 = ReadRegisterUlong(param_1,*(int **)(param_1 + 0x18));
      in_RAX = (ulonglong)(uVar2 & 0xf0000000);
      if ((uVar2 & 0xf0000000) == 0x20000000) {
        if (*(int *)(param_1 + 0x968) == 0) {
          if (((*(char *)(param_1 + 0x1220) != '\0') && (*(byte *)(param_1 + 0x1221) == param_2)) &&
             (*(char *)((longlong)*(short **)(param_1 + 0x1270) + 3) == '\0')) {
            uVar3 = GetBusTargetFromDevHandle
                              (param_1,**(short **)(param_1 + 0x1270),local_res8,local_28);
            if (((char)uVar3 != '\0') && (local_res8[0] != param_2)) {
              *(ushort *)(param_1 + 0x964) =
                   *(ushort *)(param_1 + 0x964) | (ushort)(1 << (param_2 & 0x1f));
              param_2 = (uint)local_res8[0];
            }
          }
          *(undefined1 *)(param_1 + 0x1984) = 0;
          *(undefined2 *)(param_1 + 0xab2) = 1;
          *(char *)(param_1 + 0x11d1) = (char)param_2;
          in_RAX = ProcessBusReset(param_1,param_3,param_4);
          if (((char)in_RAX != '\0') && (*(int *)(param_1 + 0x970) != 0)) {
            do {
              if (*(int *)(param_1 + 0x968) == 0) break;
              PollLSImpiIsr(param_1,param_3,param_4);
              in_RAX = StorPortStallExecution(500);
              uVar1 = uVar1 + 1;
            } while (uVar1 < 120000);
          }
        }
        else if ((*(char *)(param_1 + 0x11d6) != '\0') ||
                ((char)param_2 != *(char *)(param_1 + 0x11d1))) {
          uVar1 = (uint)*(ushort *)(param_1 + 0x964) | 1 << (param_2 & 0x1f);
          in_RAX = (ulonglong)uVar1;
          *(short *)(param_1 + 0x964) = (short)uVar1;
        }
      }
    }
    else {
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20015) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20015,
                    (undefined1 *)0x0,0,param_3,param_4);
      }
      LogSystemEvent(param_1,0xad010036,0xc004af02,
                     (byte *)"LUN/Target reset still active when a Bus Reset request was received",
                     param_3,param_4);
      uVar1 = ReadRegisterUlong(param_1,*(int **)(param_1 + 0x50));
      **(uint **)(param_1 + 0x50) = uVar1 | 0x40000009;
      LOCK();
      UNLOCK();
      if (*(int *)(param_1 + 0x970) == 0) {
        PauseAdapterQueue(param_1,0x12,param_3,param_4);
      }
      *(undefined4 *)(param_1 + 0x1218) = 1;
      LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                          "Diag Reset(part of bus reset)-LUN/Target reset still active when a Bus Reset request was received"
                          ,param_3,param_4);
      in_RAX = KickStart(param_1,param_3,param_4);
    }
  }
  else if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20014) != 0)) {
    in_RAX = RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x20014,
                         (undefined1 *)0x0,0,param_3,param_4);
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== LunTargetResetTimerCallback @ 14001eef0 =====

undefined1
LunTargetResetTimerCallback
          (longlong param_1,undefined8 param_2,undefined8 param_3,byte param_4,int param_5)

{
  ProcessLunTargetReset(param_1,(short *)0x0,param_4,param_5);
  return 0;
}



===== ProcessBusReset @ 14001ef10 =====

ulonglong ProcessBusReset(longlong param_1,byte param_2,int param_3)

{
  char cVar1;
  short *psVar2;
  bool bVar3;
  ushort uVar4;
  uint uVar5;
  ulonglong uVar6;
  byte bVar7;
  short sVar8;
  ulonglong uVar9;
  longlong lVar10;
  ushort uVar11;
  longlong lVar12;
  int local_res8 [2];
  
  uVar4 = *(ushort *)(param_1 + 0x998);
  cVar1 = *(char *)(param_1 + 0x11d1);
  uVar11 = *(ushort *)(param_1 + 0xab2);
  local_res8[0] = 0;
  bVar3 = true;
  lVar10 = 0;
  do {
switchD_14001ef87_default:
    uVar6 = (ulonglong)*(int *)(param_1 + 0x16d8);
    switch(*(int *)(param_1 + 0x16d8)) {
    case 0:
      if (*(short *)(param_1 + 0xab2) != 1) goto LAB_14001f45f;
      uVar6 = ResetActive(param_1,0x14,param_2,param_3);
      *(undefined1 *)(param_1 + 0x1210) = 1;
      if (*(int *)(param_1 + 0x970) == 0) {
        uVar6 = PauseAdapterQueue(param_1,0x13,param_2,param_3);
      }
      *(undefined4 *)(param_1 + 0x16d8) = 1;
      break;
    case 1:
      if (uVar4 < uVar11) {
        if (*(char *)(param_1 + 0x132) == '\0') goto LAB_14001f186;
        uVar6 = GtfStartTimer(param_1,1,4,BusResetTimerCallback,0,param_2,param_3);
        if ((char)uVar6 == -2) {
          if (*(short *)(param_1 + 0x960) != 0) {
            LogSystemEvent(param_1,0xad01007c,0x8004af01,
                           (byte *)"No timer available for BusResetTimerCallback",param_2,param_3);
          }
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                        (undefined1 *)0x0,0,param_2,param_3);
          }
          uVar6 = 0;
          *(undefined4 *)(param_1 + 0x16d8) = 5;
        }
        else {
          uVar6 = 0;
          bVar3 = false;
          *(undefined4 *)(param_1 + 0x16d8) = 3;
        }
      }
      else {
        if ((*(short *)(param_1 + 0x960) != 0) && (uVar11 != 1)) {
          uVar6 = LogSystemEvent(param_1,0xad010017,0xc004af02,
                                 (byte *)"TM reply received (ProcessBusReset)",param_2,param_3);
        }
        uVar9 = (ulonglong)uVar11;
        uVar11 = uVar11 + 1;
        lVar10 = uVar9 * 0x20 + *(longlong *)(param_1 + 0x598);
        if (((*(longlong *)(lVar10 + 8) != 0) && (*(int *)(lVar10 + 0x18) == 0)) &&
           (*(char *)(lVar10 + 0x12) == cVar1)) {
          *(ushort *)(param_1 + 0xab2) = uVar11;
          *(undefined4 *)(param_1 + 0x16d8) = 2;
        }
      }
      break;
    case 2:
      psVar2 = *(short **)(param_1 + 0x568);
      ZeroMemory(psVar2,0x34);
      if (lVar10 == 0) {
        sVar8 = *psVar2;
      }
      else {
        sVar8 = *(short *)(lVar10 + 0x14);
        *psVar2 = sVar8;
      }
      *(undefined1 *)((longlong)psVar2 + 3) = 1;
      *(undefined1 *)((longlong)psVar2 + 5) = 3;
      uVar5 = GetMapTableIndexFromHandle(param_1,sVar8);
      if (uVar5 != 0xffffffff) {
        lVar12 = (ulonglong)uVar5 * 0x2c;
        lVar10 = *(longlong *)(param_1 + 0x5c0);
        if (((*(char *)(lVar12 + 0x24 + lVar10) != '\0') && (*(char *)(param_1 + 0x18b0) == '\0'))
           && ((*(uint *)(lVar12 + 0x14 + lVar10) & 4) == 0)) {
          *(undefined1 *)((longlong)psVar2 + 7) = 0x18;
          lVar10 = *(longlong *)(param_1 + 0x5c0);
        }
        local_res8[0] =
             CONCAT22(*(undefined2 *)(lVar12 + 0x1c + lVar10),
                      *(undefined2 *)(lVar12 + 0x1e + lVar10));
        LogOperationalEvent(param_1,local_res8,4,0x4004af00,
                            "Target reset issued as part of bus reset processing (BT logged)",
                            param_2,param_3);
      }
      uVar6 = QueueRequestDescriptor
                        (param_1,(uint)*(ushort *)(param_1 + 0x9b2) * 0x10000 + 6,0,param_2,param_3)
      ;
      if (*(char *)(param_1 + 0xb699) == '\0') {
        uVar6 = AfdMasterTrigger(param_1,4,param_2,param_3);
        *(undefined1 *)(param_1 + 0xb699) = 1;
      }
      *(undefined4 *)(param_1 + 0x974) = 0xf;
      *(undefined4 *)(param_1 + 0x16d8) = 1;
      goto LAB_14001f3e3;
    case 3:
      *(undefined4 *)(param_1 + 0x16d8) = 4;
      break;
    case 4:
      uVar11 = 1;
      if (uVar4 != 0) {
        do {
          lVar10 = (ulonglong)uVar11 * 0x20 + *(longlong *)(param_1 + 0x598);
          if (((*(longlong *)(lVar10 + 8) != 0) && (*(char *)(lVar10 + 0x12) == cVar1)) &&
             (*(int *)(lVar10 + 0x18) == 0)) {
            LogSystemEvent(param_1,0xad010035,0x8004af01,
                           (byte *)
                           "IOs still active on bus when TM reply was received(ProcessBusReset)",
                           param_2,param_3);
            uVar5 = ReadRegisterUlong(param_1,*(int **)(param_1 + 0x50));
            **(uint **)(param_1 + 0x50) = uVar5 | 0x40000009;
            LOCK();
            UNLOCK();
            if (*(int *)(param_1 + 0x970) == 0) {
              PauseAdapterQueue(param_1,0x14,param_2,param_3);
            }
            *(undefined4 *)(param_1 + 0x1218) = 1;
            LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                                "Diag Reset(part of bus reset)-IOs still active on bus when TM reply was received"
                                ,param_2,param_3);
            KickStart(param_1,param_2,param_3);
            *(undefined1 *)(param_1 + 0x1211) = 0;
            StorPortNotification(6,param_1,WatchdogTimer);
            bVar3 = false;
            uVar6 = 0;
            *(undefined4 *)(param_1 + 0x16d8) = 0;
            goto LAB_14001f2c1;
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 <= uVar4);
      }
LAB_14001f186:
      uVar6 = 0;
      *(undefined4 *)(param_1 + 0x16d8) = 5;
      break;
    case 5:
      lVar12 = *(longlong *)(param_1 + 0x930);
      *(undefined1 *)(param_1 + 0x1210) = 0;
      *(undefined1 *)(param_1 + 0xb699) = 0;
      if ((lVar12 != 0) &&
         (uVar6 = 0, *(char *)(*(longlong *)(lVar12 + 0x68) + 0x62) == *(char *)(param_1 + 0x11d1)))
      {
        *(undefined8 *)(param_1 + 0x930) = 0;
        *(undefined1 *)(lVar12 + 3) = 1;
        uVar6 = StorPortNotification(0,param_1);
      }
      *(undefined4 *)(param_1 + 0x16d8) = 6;
      break;
    case 6:
      ResetActive(param_1,0x40000014,param_2,param_3);
      ResumeAdapterQueue(param_1,9,param_2,param_3);
      bVar7 = 0;
      goto LAB_14001f420;
    default:
      goto switchD_14001ef87_default;
    }
LAB_14001f2c1:
  } while (bVar3);
LAB_14001f3e3:
  return CONCAT71((int7)(uVar6 >> 8),1);
  while (bVar7 = bVar7 + 1, bVar7 < 8) {
LAB_14001f420:
    uVar4 = 1 << (bVar7 & 0x1f);
    uVar6 = (ulonglong)uVar4;
    if ((uVar4 & *(ushort *)(param_1 + 0x964)) != 0) {
      *(ushort *)(param_1 + 0x964) = ~uVar4 & *(ushort *)(param_1 + 0x964);
      uVar6 = LSImpiReset(param_1,(uint)bVar7,param_2,param_3);
      break;
    }
  }
  *(undefined4 *)(param_1 + 0x16d8) = 0;
LAB_14001f45f:
  return uVar6 & 0xffffffffffffff00;
}



===== ProcessLunTargetReset @ 14001f4a0 =====

void ProcessLunTargetReset(longlong param_1,short *param_2,byte param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  longlong lVar6;
  ulonglong uVar7;
  char *pcVar8;
  undefined8 uVar9;
  byte bVar10;
  longlong lVar11;
  longlong *plVar12;
  short sVar13;
  undefined4 uVar14;
  char cVar15;
  char cVar16;
  longlong lVar17;
  longlong lVar18;
  char local_res8;
  short local_46;
  uint local_44 [3];
  
  bVar1 = false;
  cVar16 = '\0';
  bVar2 = false;
  bVar3 = true;
  local_46 = 0;
  local_44[0] = 0;
  sVar13 = 0;
  bVar4 = true;
  lVar18 = 0;
  lVar17 = 0;
  cVar15 = local_res8;
switchD_14001f52d_default:
  switch(*(undefined4 *)(param_1 + 0x16dc)) {
  case 0:
    if (param_2 == (short *)0x0) {
      if (*(char *)(param_1 + 0x608) == '\0') {
        return;
      }
      if ((*(uint *)(param_1 + 0x60c) & 0x24f) == 0) {
        return;
      }
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x24f,
                  (undefined1 *)0x0,0,param_3,param_4);
      return;
    }
    *(undefined4 *)(param_1 + 0x16dc) = 1;
    break;
  case 1:
    lVar18 = *(longlong *)(param_1 + 0x928);
    *(undefined1 *)(param_1 + 0x12b1) = 5;
    local_46 = *param_2;
    cVar16 = *(char *)((longlong)param_2 + 5);
    lVar17 = *(longlong *)(lVar18 + 0x68);
    cVar15 = *(char *)(lVar17 + 100);
    *(undefined4 *)(param_1 + 0x16dc) = 2;
    local_res8 = cVar15;
    sVar13 = local_46;
    break;
  case 2:
    if (lVar18 != 0) {
      if (*(int *)(lVar18 + 0x14) == 0x20) {
        if (cVar16 != '\x05') {
LAB_14001f5b4:
          *(undefined4 *)(param_1 + 0x16dc) = 7;
          break;
        }
      }
      else if ((*(int *)(lVar18 + 0x14) == 0x13) && (cVar16 != '\x03')) goto LAB_14001f5b4;
    }
    *(undefined4 *)(param_1 + 0x16dc) = 3;
    break;
  case 3:
    uVar5 = 1;
    if (*(ushort *)(param_1 + 0x998) != 0) {
      lVar11 = *(longlong *)(param_1 + 0x598);
      do {
        lVar6 = (ulonglong)uVar5 * 0x20;
        if (((*(longlong *)(lVar6 + 8 + lVar11) != 0) &&
            (*(short *)(lVar6 + 0x14 + lVar11) == sVar13)) &&
           ((cVar16 != '\x05' || (*(char *)(lVar6 + 0x16 + lVar11) == cVar15)))) {
          pcVar8 = (char *)(param_1 + 0x12b1);
          *pcVar8 = *pcVar8 + -1;
          if (*pcVar8 == '\0') {
            *(undefined4 *)(param_1 + 0x16dc) = 6;
            bVar1 = true;
            bVar2 = true;
            if (((lVar17 != 0) && (*(char *)(param_1 + 0x608) != '\0')) &&
               ((*(uint *)(param_1 + 0x60c) & 0x2000d) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2000d,
                          (undefined1 *)(lVar17 + 0x62),3,param_3,param_4);
              cVar15 = local_res8;
              sVar13 = local_46;
            }
          }
          else {
            *(undefined4 *)(param_1 + 0x16dc) = 4;
          }
          goto LAB_14001f968;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 <= *(ushort *)(param_1 + 0x998));
    }
    *(undefined4 *)(param_1 + 0x16dc) = 6;
    break;
  case 4:
    uVar7 = GtfStartTimer(param_1,1,1,LunTargetResetTimerCallback,0,param_3,param_4);
    if ((char)uVar7 == -2) {
      if (*(short *)(param_1 + 0x960) != 0) {
        LogSystemEvent(param_1,0xad01007c,0x8004af01,
                       (byte *)"No timer available for LunTargetResetTimerCallback",param_3,param_4)
        ;
      }
      if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                    (undefined1 *)0x0,0,param_3,param_4);
      }
    }
    else {
      bVar3 = false;
      bVar4 = false;
    }
    *(undefined4 *)(param_1 + 0x16dc) = 5;
    cVar15 = local_res8;
    sVar13 = local_46;
    break;
  case 5:
    *(undefined4 *)(param_1 + 0x16dc) = 3;
    break;
  case 6:
    lVar18 = *(longlong *)(param_1 + 0x928);
    lVar17 = *(longlong *)(lVar18 + 0x68);
    if (lVar17 != 0) {
      bVar10 = 4;
      if (!bVar1) {
        bVar10 = 1;
      }
      *(byte *)(lVar18 + 3) = bVar10;
      local_44[0] = local_44[0] | bVar10;
      StorPortNotification(0,param_1,lVar18);
      if (cVar16 == '\x05') {
        if (bVar1) {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x20010) != 0))
          {
            uVar14 = 0x20010;
LAB_14001f803:
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar14,
                        (undefined1 *)(lVar17 + 0x62),3,param_3,param_4);
          }
        }
        else if ((*(char *)(param_1 + 0x608) != '\0') &&
                ((*(uint *)(param_1 + 0x60c) & 0x2000e) != 0)) {
          uVar14 = 0x2000e;
          goto LAB_14001f803;
        }
        pcVar8 = "Lun reset completed (SRB status logged)";
LAB_14001f8b1:
        LogOperationalEvent(param_1,(int *)local_44,4,0x4004af00,pcVar8,param_3,param_4);
      }
      else if (cVar16 == '\x03') {
        if (*(char *)(param_1 + 0x608) != '\0') {
          if (bVar1) {
            if ((*(uint *)(param_1 + 0x60c) & 0x20011) != 0) {
              uVar14 = 0x20011;
LAB_14001f87a:
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),uVar14,
                          (undefined1 *)(lVar17 + 0x62),3,param_3,param_4);
            }
          }
          else if ((*(uint *)(param_1 + 0x60c) & 0x2000f) != 0) {
            uVar14 = 0x2000f;
            goto LAB_14001f87a;
          }
        }
        pcVar8 = "Target reset completed (SRB status logged)";
        goto LAB_14001f8b1;
      }
      plVar12 = (longlong *)(param_1 + 0x13b8);
      lVar11 = 100;
      do {
        if (((*plVar12 == lVar18) && (*plVar12 = -1, *(char *)(param_1 + 0x608) != '\0')) &&
           ((*(uint *)(param_1 + 0x60c) & 0x2001e) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x2001e,
                      (undefined1 *)(lVar17 + 0x62),3,param_3,param_4);
        }
        plVar12 = plVar12 + 1;
        lVar11 = lVar11 + -1;
      } while (lVar11 != 0);
      cVar15 = local_res8;
      sVar13 = local_46;
      bVar1 = bVar2;
      bVar3 = bVar4;
    }
    *(undefined4 *)(param_1 + 0x16dc) = 7;
    break;
  case 7:
    goto switchD_14001f52d_caseD_7;
  default:
    goto switchD_14001f52d_default;
  }
LAB_14001f968:
  if (!bVar3) {
    return;
  }
  goto switchD_14001f52d_default;
switchD_14001f52d_caseD_7:
  *(undefined8 *)(param_1 + 0x928) = 0;
  uVar9 = CheckResetQueue(param_1,param_3,param_4);
  if ((char)uVar9 == '\0') {
    ResetActive(param_1,0x40000015,param_3,param_4);
    ResumeAdapterQueue(param_1,10,param_3,param_4);
    bVar10 = 0;
    do {
      uVar5 = 1 << (bVar10 & 0x1f);
      if ((uVar5 & *(ushort *)(param_1 + 0x964)) != 0) {
        *(ushort *)(param_1 + 0x964) = ~uVar5 & *(ushort *)(param_1 + 0x964);
        LSImpiReset(param_1,(uint)bVar10,param_3,param_4);
        break;
      }
      bVar10 = bVar10 + 1;
    } while (bVar10 < 8);
  }
  *(undefined4 *)(param_1 + 0x16dc) = 0;
  return;
}



===== SynchronizeReset @ 14001faa0 =====

void SynchronizeReset(longlong param_1,int *param_2)

{
  LSImpiReset(param_1,**(uint **)(param_2 + 2),*(byte *)(param_2 + 1),*param_2);
  return;
}



===== RttAddRecord @ 14001fac0 =====

void RttAddRecord(longlong param_1,undefined4 *param_2,undefined4 param_3,undefined1 *param_4,
                 uint param_5,undefined8 param_6,undefined4 param_7)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  
  *param_2 = param_3;
  param_2[1] = param_5 + 0x14;
  StorPortQuerySystemTime(param_2 + 2);
  param_2[4] = param_7;
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



===== RttFormatBuffer @ 14001fb50 =====

void RttFormatBuffer(undefined8 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  param_1[2] = puVar1;
  param_1[1] = (ulonglong)*(uint *)(param_1 + 5) + (longlong)puVar1;
  param_1[3] = puVar1;
  param_1[4] = 0;
  *(undefined4 *)((longlong)param_1 + 0x2c) = 0;
  *puVar1 = 2;
  puVar1[1] = 0x14;
  StorPortQuerySystemTime(puVar1 + 2);
  puVar1[4] = param_2;
  puVar1[5] = 0;
  puVar1[6] = 8;
  *(int *)((longlong)param_1 + 0x2c) = *(int *)((longlong)param_1 + 0x2c) + 1;
  param_1[3] = puVar1 + 5;
  return;
}



===== RttInitTrace @ 14001fbe0 =====

void RttInitTrace(undefined8 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *(undefined4 *)((longlong)param_1 + 0x34) = 0x3fbf00;
  param_1[1] = (ulonglong)*(uint *)(param_1 + 5) + (longlong)puVar1;
  param_1[2] = puVar1;
  param_1[3] = puVar1;
  param_1[4] = 0;
  *(undefined4 *)((longlong)param_1 + 0x2c) = 0;
  *puVar1 = 2;
  puVar1[1] = 0x14;
  StorPortQuerySystemTime(puVar1 + 2);
  puVar1[4] = param_2;
  puVar1[5] = 0;
  puVar1[6] = 8;
  *(int *)((longlong)param_1 + 0x2c) = *(int *)((longlong)param_1 + 0x2c) + 1;
  param_1[3] = puVar1 + 5;
  return;
}



===== RttLogEvent @ 14001fc70 =====

void RttLogEvent(longlong param_1,char *param_2,ulonglong *param_3,undefined4 param_4,
                undefined1 *param_5,uint param_6,byte param_7,int param_8)

{
  ulonglong *local_38;
  undefined4 local_30;
  undefined1 *local_28;
  char *local_20;
  uint local_18;
  byte local_14;
  int local_10;
  
  if (param_8 == 5) {
    AcquireIsrLocks(param_1,param_7,5);
    RttLogEventCore(param_3,param_4,param_5,param_6,param_7,5);
    ReleaseIsrLocks(param_1,param_7,5);
    return;
  }
  if (*param_2 == '\0') {
    local_28 = param_5;
    local_18 = param_6;
    local_14 = param_7;
    local_10 = param_8;
    local_38 = param_3;
    local_30 = param_4;
    local_20 = param_2;
    SynchronizeAccess(param_1,RttLogEventSynchronized,&local_38,param_7,param_8);
    return;
  }
  RttLogEventCore(param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



===== RttLogEventCore @ 14001fdb0 =====

void RttLogEventCore(ulonglong *param_1,undefined4 param_2,undefined1 *param_3,uint param_4,
                    undefined1 param_5,undefined4 param_6)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  ulonglong *puVar10;
  undefined7 in_stack_ffffffffffffffe1;
  
  uVar5 = (ulonglong)param_4;
  uVar9 = param_4 + 0x1c;
  if (uVar9 <= (uint)param_1[5]) {
    puVar4 = (undefined4 *)param_1[2];
    puVar8 = (undefined4 *)param_1[3];
    puVar10 = param_1 + 3;
    puVar3 = puVar4;
    while (puVar8 < puVar3) {
      do {
        if (uVar9 <= (uint)((int)puVar4 - (int)puVar8)) {
          *puVar8 = param_2;
          puVar8[1] = param_4 + 0x14;
          StorPortQuerySystemTime(puVar8 + 2);
          puVar8[4] = param_6;
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
          *(int *)((longlong)param_1 + 0x2c) = *(int *)((longlong)param_1 + 0x2c) + 1;
          *puVar10 = (ulonglong)puVar8;
          return;
        }
        uVar2 = *(uint *)(param_1[2] + 4);
        *(int *)((longlong)param_1 + 0x2c) = *(int *)((longlong)param_1 + 0x2c) + -1;
        piVar7 = (int *)((ulonglong)uVar2 + param_1[2]);
        param_1[2] = (ulonglong)piVar7;
        puVar4 = (undefined4 *)((ulonglong)piVar7 & 0xffffffff);
      } while (*piVar7 != 1);
      puVar3 = (undefined4 *)*param_1;
      param_1[2] = (ulonglong)puVar3;
      puVar4 = (undefined4 *)((ulonglong)puVar3 & 0xffffffff);
    }
    if ((uint)((int)param_1[1] - (int)puVar8) <= uVar9) {
      *(undefined4 *)*puVar10 = 1;
      *(undefined4 *)(*puVar10 + 4) = 8;
      if ((uint)((int)param_1[2] - (int)*param_1) < uVar9) {
        uVar5 = param_1[2];
        iVar6 = *(int *)((longlong)param_1 + 0x2c);
        do {
          iVar6 = iVar6 + -1;
          uVar5 = uVar5 + *(uint *)(uVar5 + 4);
          *(int *)((longlong)param_1 + 0x2c) = iVar6;
          param_1[2] = uVar5;
        } while ((uint)((int)uVar5 - (int)*param_1) < uVar9);
      }
      puVar10 = param_1;
    }
    RttAddRecord((longlong)param_1,(undefined4 *)*puVar10,param_2,param_3,param_4,
                 CONCAT71(in_stack_ffffffffffffffe1,param_5),param_6);
  }
  return;
}



===== RttLogEventSynchronized @ 14001ff20 =====

undefined8 RttLogEventSynchronized(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = RttLogEventCore((ulonglong *)*param_2,*(undefined4 *)(param_2 + 1),
                          (undefined1 *)param_2[2],*(uint *)(param_2 + 4),
                          *(undefined1 *)((longlong)param_2 + 0x24),*(undefined4 *)(param_2 + 5));
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== RttSetTraceParameters @ 14001ff50 =====

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



===== CallStorPortLogSystemEvent @ 14001ff70 =====

void CallStorPortLogSystemEvent(longlong param_1,longlong param_2,byte param_3,int param_4)

{
  int local_res8 [2];
  undefined4 local_res10 [2];
  longlong local_78 [2];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_5c;
  undefined1 local_4c;
  undefined4 local_48;
  undefined4 local_40;
  longlong local_38;
  undefined4 local_30;
  longlong *local_28;
  
  local_res10[0] = 0;
  local_78[0] = 0;
  ZeroMemory(&local_68,0x48);
  local_48 = *(undefined4 *)(param_2 + 4);
  local_68 = 0x100;
  local_64 = 0x48;
  local_5c = 0;
  local_4c = 0;
  local_40 = 4;
  if (*(char *)(param_2 + 0xfe) != '\0') {
    local_78[0] = param_2 + 8;
    local_30 = 1;
    local_28 = local_78;
  }
  local_38 = param_2;
  if (*(char *)(param_1 + 0x11ee) != '\0') {
    ReleaseIsrLocks(param_1,param_3,param_4);
  }
  local_res8[0] = StorPortExtendedFunction(0x10,param_1,&local_68,local_res10);
  if (*(char *)(param_1 + 0x11ee) != '\0') {
    AcquireIsrLocks(param_1,param_3,param_4);
  }
  if (((local_res8[0] != 0) && (*(char *)(param_1 + 0x608) != '\0')) &&
     ((*(uint *)(param_1 + 0x60c) & 0x26c) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x26c,
                (undefined1 *)local_res8,4,param_3,param_4);
  }
  return;
}



===== InitSysLogErrorFIFO @ 1400200d0 =====

void InitSysLogErrorFIFO(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0xb978);
  *(longlong *)(param_1 + 0xb988) = lVar1;
  *(longlong *)(param_1 + 0xb990) = lVar1;
  *(longlong *)(param_1 + 0xb980) = lVar1 + 0x1400;
  return;
}



===== LSImpiPassiveInitialize @ 140020100 =====

undefined8 LSImpiPassiveInitialize(longlong param_1)

{
  undefined8 uVar1;
  undefined4 local_res8 [2];
  
  StorPortNotification(0x1001,param_1,param_1 + 0xb9a0,SystemEventLogger);
  local_res8[0] = 0;
  uVar1 = StorPortNotification(0x1002,param_1,param_1 + 0xb9a0,0,0,local_res8);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== LitInit @ 140020170 =====

void LitInit(longlong param_1)

{
  *(undefined8 *)(param_1 + 0xbb38) = 0;
  *(undefined8 *)(param_1 + 0xbb40) = 0;
  *(undefined8 *)(param_1 + 0xbb48) = 0;
  *(undefined8 *)(param_1 + 0xbb50) = 0;
  *(undefined8 *)(param_1 + 0xbb58) = 0;
  *(undefined8 *)(param_1 + 0xbb60) = 0;
  *(undefined8 *)(param_1 + 0xbb68) = 0;
  *(undefined8 *)(param_1 + 0xbb70) = 0;
  *(undefined8 *)(param_1 + 0xbb78) = 0;
  *(undefined8 *)(param_1 + 48000) = 0;
  *(undefined8 *)(param_1 + 0xbb88) = 0;
  *(undefined8 *)(param_1 + 0xbb90) = 0;
  *(undefined8 *)(param_1 + 0xbb98) = 0;
  *(undefined8 *)(param_1 + 0xbba0) = 0;
  *(undefined8 *)(param_1 + 0xbba8) = 0;
  *(undefined1 *)(param_1 + 0xbbb0) = 0;
  return;
}



===== LitLogInfoReceived @ 1400201f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LitLogInfoReceived(longlong param_1,int param_2,undefined2 param_3,undefined1 param_4,
                       undefined1 param_5,undefined1 param_6,byte param_7,int param_8)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  char *pcVar5;
  int *piVar6;
  uint *puVar7;
  uint uVar8;
  undefined1 auStackY_88 [32];
  int local_48;
  uint local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined2 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  ZeroMemory(&local_48,0x10);
  piVar6 = (int *)(param_1 + 0xbb38);
  local_3f = param_5;
  local_3e = param_6;
  uVar4 = 0;
  do {
    local_48 = param_2;
    local_40 = param_4;
    local_3c = param_3;
    if (*piVar6 == param_2) {
      lVar1 = param_1 + uVar4 * 0xc;
      *(undefined4 *)(lVar1 + 0xbb40) = 0;
      if (*(int *)(lVar1 + 0xbb3c) == -1) {
        return;
      }
      local_44 = *(int *)(lVar1 + 0xbb3c) + 1;
      *(uint *)(lVar1 + 0xbb3c) = local_44;
      if (local_44 < 6) {
        pcVar5 = "LogInfo";
      }
      else if (local_44 == 1000) {
        pcVar5 = "LogInfo(BABBLING-1000 count)";
      }
      else {
        if (local_44 != (local_44 / 10000) * 10000) {
          return;
        }
        pcVar5 = "LogInfo(BABBLING-10000 count)";
      }
      LogOperationalEvent(param_1,&local_48,0x10,0x4004af00,pcVar5,param_7,param_8);
      if (*(char *)(param_1 + 0x608) == '\0') {
        return;
      }
      if ((*(uint *)(param_1 + 0x60c) & 0x238) == 0) {
        return;
      }
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x238,
                  (undefined1 *)&local_48,0x10,param_7,param_8);
      return;
    }
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar3;
    piVar6 = piVar6 + 3;
  } while (uVar3 < 10);
  uVar3 = 0;
  puVar7 = (uint *)(param_1 + 0xbb40);
  uVar8 = 0;
  do {
    if (puVar7[-2] == 0) goto LAB_1400202c3;
    uVar2 = uVar8;
    if (*puVar7 <= *(uint *)(param_1 + 0xbb40 + (ulonglong)uVar3 * 0xc)) {
      uVar2 = uVar3;
    }
    uVar3 = uVar2;
    uVar8 = uVar8 + 1;
    puVar7 = puVar7 + 3;
  } while (uVar8 < 10);
  *(undefined4 *)(param_1 + 0xbb38 + (ulonglong)uVar3 * 0xc) = 0;
  *(undefined8 *)(param_1 + 0xbb3c + (ulonglong)uVar3 * 0xc) = 0;
  uVar8 = uVar3;
LAB_1400202c3:
  uVar4 = (ulonglong)uVar8;
  *(int *)(param_1 + 0xbb38 + uVar4 * 0xc) = param_2;
  piVar6 = (int *)(param_1 + 0xbb3c + uVar4 * 0xc);
  *piVar6 = *piVar6 + 1;
  local_44 = *(undefined4 *)(param_1 + 0xbb3c + uVar4 * 0xc);
  LogOperationalEvent(param_1,&local_48,0x10,0x4004af00,"LogInfo received",param_7,param_8);
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x238) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x238,
                (undefined1 *)&local_48,0x10,param_7,param_8);
  }
  if (*(char *)(param_1 + 0xbbb0) == '\0') {
    *(undefined1 *)(param_1 + 0xbbb0) = 1;
    GtfStartTimer(param_1,2,10,LitServiceActiveList,0,param_7,param_8);
  }
  return;
}



===== LitServiceActiveList @ 1400204c0 =====

char LitServiceActiveList(longlong param_1)

{
  char cVar1;
  
  cVar1 = '\0';
  if (*(int *)(param_1 + 0xbb38) != 0) {
    *(int *)(param_1 + 0xbb40) = *(int *)(param_1 + 0xbb40) + 10;
    if (*(uint *)(param_1 + 0xbb40) < 0xe10) {
      cVar1 = '\x01';
    }
    else {
      *(undefined8 *)(param_1 + 0xbb38) = 0;
      *(undefined4 *)(param_1 + 0xbb40) = 0;
    }
  }
  if (*(int *)(param_1 + 0xbb44) != 0) {
    *(int *)(param_1 + 0xbb4c) = *(int *)(param_1 + 0xbb4c) + 10;
    if (*(uint *)(param_1 + 0xbb4c) < 0xe10) {
      cVar1 = '\x01';
    }
    else {
      *(undefined8 *)(param_1 + 0xbb44) = 0;
      *(undefined4 *)(param_1 + 0xbb4c) = 0;
    }
  }
  if (*(int *)(param_1 + 0xbb50) != 0) {
    *(int *)(param_1 + 0xbb58) = *(int *)(param_1 + 0xbb58) + 10;
    if (*(uint *)(param_1 + 0xbb58) < 0xe10) {
      cVar1 = '\x01';
    }
    else {
      *(undefined8 *)(param_1 + 0xbb50) = 0;
      *(undefined4 *)(param_1 + 0xbb58) = 0;
    }
  }
  if (*(int *)(param_1 + 0xbb5c) != 0) {
    *(int *)(param_1 + 0xbb64) = *(int *)(param_1 + 0xbb64) + 10;
    if (*(uint *)(param_1 + 0xbb64) < 0xe10) {
      cVar1 = '\x01';
    }
    else {
      *(undefined8 *)(param_1 + 0xbb5c) = 0;
      *(undefined4 *)(param_1 + 0xbb64) = 0;
    }
  }
  if (*(int *)(param_1 + 0xbb68) != 0) {
    *(int *)(param_1 + 0xbb70) = *(int *)(param_1 + 0xbb70) + 10;
    if (*(uint *)(param_1 + 0xbb70) < 0xe10) {
      cVar1 = '\x01';
    }
    else {
      *(undefined8 *)(param_1 + 0xbb68) = 0;
      *(undefined4 *)(param_1 + 0xbb70) = 0;
    }
  }
  if (*(int *)(param_1 + 0xbb74) != 0) {
    *(int *)(param_1 + 0xbb7c) = *(int *)(param_1 + 0xbb7c) + 10;
    if (*(uint *)(param_1 + 0xbb7c) < 0xe10) {
      cVar1 = '\x01';
    }
    else {
      *(undefined8 *)(param_1 + 0xbb74) = 0;
      *(undefined4 *)(param_1 + 0xbb7c) = 0;
    }
  }
  if (*(int *)(param_1 + 48000) != 0) {
    *(int *)(param_1 + 0xbb88) = *(int *)(param_1 + 0xbb88) + 10;
    if (*(uint *)(param_1 + 0xbb88) < 0xe10) {
      cVar1 = '\x01';
    }
    else {
      *(undefined8 *)(param_1 + 48000) = 0;
      *(undefined4 *)(param_1 + 0xbb88) = 0;
    }
  }
  if (*(int *)(param_1 + 0xbb8c) != 0) {
    *(int *)(param_1 + 0xbb94) = *(int *)(param_1 + 0xbb94) + 10;
    if (*(uint *)(param_1 + 0xbb94) < 0xe10) {
      cVar1 = '\x01';
    }
    else {
      *(undefined8 *)(param_1 + 0xbb8c) = 0;
      *(undefined4 *)(param_1 + 0xbb94) = 0;
    }
  }
  if (*(int *)(param_1 + 0xbb98) != 0) {
    *(int *)(param_1 + 0xbba0) = *(int *)(param_1 + 0xbba0) + 10;
    if (*(uint *)(param_1 + 0xbba0) < 0xe10) {
      cVar1 = '\x01';
    }
    else {
      *(undefined8 *)(param_1 + 0xbb98) = 0;
      *(undefined4 *)(param_1 + 0xbba0) = 0;
    }
  }
  if (*(int *)(param_1 + 0xbba4) != 0) {
    *(int *)(param_1 + 0xbbac) = *(int *)(param_1 + 0xbbac) + 10;
    if (*(uint *)(param_1 + 0xbbac) < 0xe10) {
      return '\x01';
    }
    *(undefined8 *)(param_1 + 0xbba4) = 0;
    *(undefined4 *)(param_1 + 0xbbac) = 0;
  }
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xbbb0) = 0;
  }
  return cVar1;
}



===== LogOperationalEvent @ 1400206b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LogOperationalEvent(longlong param_1,int *param_2,int param_3,undefined4 param_4,char *param_5,
                        byte param_6,int param_7)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  undefined1 auStackY_488 [32];
  int local_448 [4];
  ushort local_438 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_488;
  iVar3 = 0;
  local_448[1] = 0;
  if ((param_3 == 0) || (param_2 == (int *)0x0)) {
    param_2 = local_448 + 1;
  }
  bVar2 = 0;
  local_438[0] = (ushort)(byte)*param_5;
  uVar1 = local_438[0];
  do {
    if (uVar1 == 0) {
LAB_140020734:
      local_448[0] = StorPortExtendedFunction(0x62,param_1,0);
      if (local_448[0] != 0) {
        if (local_448[0] == -0x3efffffe) {
          if (param_2 != (int *)0x0) {
            iVar3 = *param_2;
          }
        }
        else {
          if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x27a) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x27a,
                        (undefined1 *)local_448,4,param_6,param_7);
          }
          param_5 = "StorPortEtwLogError API failed,it\'s RetCode logged";
          param_4 = 0x8004af01;
          iVar3 = local_448[0];
        }
        LogSystemEvent(param_1,iVar3,param_4,(byte *)param_5,param_6,param_7);
      }
      return;
    }
    bVar2 = bVar2 + 1;
    if (bVar2 == 0x48) {
      local_438[bVar2] = 0;
      goto LAB_140020734;
    }
    uVar1 = (ushort)(byte)param_5[bVar2];
    local_438[bVar2] = uVar1;
  } while( true );
}



===== LogSystemEvent @ 140020840 =====

void LogSystemEvent(longlong param_1,undefined4 param_2,undefined4 param_3,byte *param_4,
                   byte param_5,int param_6)

{
  undefined4 local_28;
  undefined4 local_24;
  byte *local_20;
  byte local_18;
  int local_14;
  
  ZeroMemory(&local_28,0x18);
  local_18 = param_5;
  local_14 = param_6;
  local_28 = param_2;
  local_24 = param_3;
  local_20 = param_4;
  AcquireIsrLocks(param_1,param_5,param_6);
  LogSystemEventInternal(param_1,local_28,local_24,local_20,local_18,local_14);
  ReleaseIsrLocks(param_1,param_5,param_6);
  return;
}



===== LogSystemEventInternal @ 1400208f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LogSystemEventInternal
               (longlong param_1,undefined4 param_2,undefined4 param_3,byte *param_4,byte param_5,
               int param_6)

{
  undefined4 *puVar1;
  ushort uVar2;
  longlong lVar3;
  byte bVar4;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  undefined4 *local_150;
  undefined4 local_148 [4];
  undefined4 local_138;
  undefined4 local_134;
  ushort local_130 [123];
  byte local_3a;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_178;
  if ((*(char *)(param_1 + 0x11ee) == '\0') && (param_6 != 2)) {
    ZeroMemory(&local_138,0x100);
    if (param_4 == (byte *)0x0) {
      local_3a = 0;
    }
    else {
      local_3a = 0;
      local_130[0] = (ushort)*param_4;
      if (local_130[0] != 0) {
        do {
          local_3a = local_3a + 1;
          if (local_3a == 0x48) {
            local_130[local_3a] = 0;
            break;
          }
          bVar4 = param_4[local_3a];
          local_130[local_3a] = (ushort)bVar4;
        } while (bVar4 != 0);
      }
    }
    local_138 = param_2;
    local_134 = param_3;
    CallStorPortLogSystemEvent(param_1,(longlong)&local_138,param_5,param_6);
  }
  else {
    puVar1 = *(undefined4 **)(param_1 + 0xb988);
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
    *(longlong *)(param_1 + 0xb988) = *(longlong *)(param_1 + 0xb988) + 0x100;
    lVar3 = *(longlong *)(param_1 + 0xb988);
    if (lVar3 == *(longlong *)(param_1 + 0xb980)) {
      lVar3 = *(longlong *)(param_1 + 0xb978);
      *(longlong *)(param_1 + 0xb988) = lVar3;
    }
    if (lVar3 == *(longlong *)(param_1 + 0xb990)) {
      *(undefined1 *)(param_1 + 0xb998) = 1;
    }
    else if (param_6 != 2) {
      local_150 = local_148;
      local_148[0] = 0;
      local_158 = 0;
      StorPortNotification(0x1002,param_1,param_1 + 0xb9a0);
    }
  }
  return;
}



===== SystemEventLogger @ 140020ac0 =====

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
  AcquireIsrLocks(param_2,0,0x10);
  do {
    if (*(char *)(param_2 + 0xb998) != '\0') {
      ZeroMemory(&local_118,0x100);
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
      CallStorPortLogSystemEvent(param_2,(longlong)&local_118,0,0x10);
      if ((*(char *)(param_2 + 0x608) != '\0') && ((*(uint *)(param_2 + 0x60c) & 0x114) != 0)) {
        RttLogEvent(param_2,(char *)(param_2 + 0x11d7),(ulonglong *)(param_2 + 0x5d8),0x114,
                    (undefined1 *)0x0,0,0,0x10);
      }
      *(undefined1 *)(param_2 + 0xb998) = 0;
    }
    if (*(longlong *)(param_2 + 0xb990) == *(longlong *)(param_2 + 0xb988)) goto LAB_140020cf1;
    CallStorPortLogSystemEvent(param_2,*(longlong *)(param_2 + 0xb990),0,0x10);
    *(longlong *)(param_2 + 0xb990) = *(longlong *)(param_2 + 0xb990) + 0x100;
    if (*(longlong *)(param_2 + 0xb990) == *(longlong *)(param_2 + 0xb980)) {
      *(undefined8 *)(param_2 + 0xb990) = *(undefined8 *)(param_2 + 0xb978);
    }
    StorPortExtendedFunction(0x2f,param_2,0,&local_150);
  } while (((local_150 - local_148) / local_140) * 1000000 < 100);
  StorPortNotification(0x1002,param_2,param_2 + 0xb9a0,0);
LAB_140020cf1:
  ReleaseIsrLocks(param_2,0,0x10);
  StorPortNotification(0x1004,param_2,local_138);
  return;
}



===== GtfInitialize @ 140020d50 =====

void GtfInitialize(longlong param_1)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  
  puVar1 = (uint *)(param_1 + 0x620);
  *puVar1 = 0;
  bVar3 = 0;
  *(undefined8 *)(param_1 + 0x628) = 0;
  lVar4 = 0;
  do {
    *(undefined8 *)(lVar4 + 0x10 + (longlong)puVar1) = 0;
    bVar2 = bVar3 & 0x1f;
    bVar3 = bVar3 + 1;
    *(undefined8 *)(lVar4 + 0x18 + (longlong)puVar1) = 0;
    *(undefined8 *)(lVar4 + 0x20 + (longlong)puVar1) = 0;
    lVar4 = lVar4 + 0x18;
    *puVar1 = *puVar1 & ~(1 << bVar2);
  } while (bVar3 < 0x1e);
  return;
}



===== GtfProcessTimers @ 140020da0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GtfProcessTimers(longlong param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  undefined8 *puVar6;
  byte bVar7;
  ulonglong local_res8;
  longlong local_res10;
  
  iVar2 = *param_2;
  bVar1 = *(byte *)(param_2 + 1);
  StorPortQuerySystemTime(&local_res8);
  local_res10 = *(longlong *)(param_1 + 0x628);
  if ((longlong)local_res8 < local_res10) {
    local_res10 = local_res10 - local_res8;
    *(ulonglong *)(param_1 + 0x628) = local_res8;
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x115) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x115,
                  (undefined1 *)&local_res10,8,bVar1,iVar2);
    }
    LogSystemEvent(param_1,0xad01009c,0x4004af00,
                   (byte *)"System clock shifted back in time, driver timer system resynchronized",
                   bVar1,iVar2);
    local_res10 = *(longlong *)(param_1 + 0x628);
  }
  local_res10 = local_res8 - local_res10;
  if (9999999 < local_res10) {
    puVar6 = (undefined8 *)(param_1 + 0x638);
    bVar7 = 0;
    *(ulonglong *)(param_1 + 0x628) = local_res8;
    do {
      uVar4 = *(ushort *)((longlong)puVar6 + -2);
      local_res8 = (ulonglong)uVar4;
      if (uVar4 != 0) {
        uVar4 = uVar4 - 1;
        local_res8 = (ulonglong)uVar4;
        *(ushort *)((longlong)puVar6 + -2) = uVar4;
        if (uVar4 == 0) {
          cVar3 = (*(code *)*puVar6)(param_1,bVar7,puVar6[1],bVar1,iVar2);
          if ((cVar3 == '\0') && (*(int *)(puVar6 + -1) != 2)) {
            puVar6[-1] = 0;
            *puVar6 = 0;
            uVar5 = ~(1 << (bVar7 & 0x1f));
            local_res8 = (ulonglong)uVar5;
            puVar6[1] = 0;
            *(uint *)(param_1 + 0x620) = *(uint *)(param_1 + 0x620) & uVar5;
          }
          else {
            local_res8 = (ulonglong)*(ushort *)((longlong)puVar6 + -4);
            *(ushort *)((longlong)puVar6 + -2) = *(ushort *)((longlong)puVar6 + -4);
          }
        }
      }
      bVar7 = bVar7 + 1;
      puVar6 = puVar6 + 3;
    } while (bVar7 < 0x1e);
  }
  return CONCAT71((int7)(local_res8 >> 8),1);
}



===== GtfStartTimer @ 140020f30 =====

ulonglong GtfStartTimer(longlong param_1,undefined4 param_2,undefined2 param_3,undefined8 param_4,
                       undefined8 param_5,byte param_6,int param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  byte bVar3;
  
  if ((param_7 == 5) || (*(char *)(param_1 + 0x11d7) != '\0')) {
    bVar3 = 0;
    do {
      if (*(int *)(param_1 + 0x630 + (ulonglong)bVar3 * 0x18) == 0) {
        lVar1 = param_1 + (ulonglong)bVar3 * 0x18;
        *(undefined8 *)(lVar1 + 0x640) = param_5;
        *(undefined4 *)(lVar1 + 0x630) = param_2;
        *(undefined2 *)(lVar1 + 0x636) = param_3;
        *(undefined2 *)(lVar1 + 0x634) = param_3;
        *(undefined8 *)(lVar1 + 0x638) = param_4;
        goto LAB_140021054;
      }
      bVar3 = bVar3 + 1;
    } while (bVar3 < 0x1e);
    if (bVar3 == 0x1e) {
      bVar3 = 0xfe;
    }
    else {
LAB_140021054:
      *(uint *)(param_1 + 0x620) = *(uint *)(param_1 + 0x620) | 1 << (bVar3 & 0x1f);
    }
    uVar2 = (ulonglong)bVar3;
  }
  else {
    AcquireIsrLocks(param_1,param_6,param_7);
    uVar2 = 0;
    do {
      if (*(int *)(param_1 + 0x630 + uVar2 * 0x18) == 0) {
        lVar1 = param_1 + uVar2 * 0x18;
        *(undefined8 *)(lVar1 + 0x640) = param_5;
        *(undefined4 *)(lVar1 + 0x630) = param_2;
        *(undefined2 *)(lVar1 + 0x636) = param_3;
        *(undefined2 *)(lVar1 + 0x634) = param_3;
        *(undefined8 *)(lVar1 + 0x638) = param_4;
        goto LAB_140020fd3;
      }
      bVar3 = (char)uVar2 + 1;
      uVar2 = (ulonglong)bVar3;
    } while (bVar3 < 0x1e);
    if (bVar3 == 0x1e) {
      uVar2 = 0xfe;
    }
    else {
LAB_140020fd3:
      *(uint *)(param_1 + 0x620) = *(uint *)(param_1 + 0x620) | 1 << ((byte)uVar2 & 0x1f);
    }
    ReleaseIsrLocks(param_1,param_6,param_7);
  }
  return uVar2;
}



===== GtfStopTimer @ 140021080 =====

ulonglong GtfStopTimer(longlong param_1,byte param_2,byte param_3,int param_4)

{
  ulonglong uVar1;
  
  if ((param_4 == 5) || (*(char *)(param_1 + 0x11d7) != '\0')) {
    uVar1 = GtfStopTimerCore((uint *)(param_1 + 0x620),param_2);
  }
  else {
    AcquireIsrLocks(param_1,param_3,param_4);
    uVar1 = GtfStopTimerCore((uint *)(param_1 + 0x620),param_2);
    ReleaseIsrLocks(param_1,param_3,param_4);
    uVar1 = uVar1 & 0xff;
  }
  return uVar1;
}



===== GtfStopTimerCore @ 140021110 =====

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
      } while (bVar4 < 0x1e);
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



===== AfdMasterTrigger @ 1400211a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AfdMasterTrigger(longlong param_1,uint param_2,byte param_3,int param_4)

{
  ushort uVar1;
  undefined8 uVar2;
  undefined1 auStackY_88 [32];
  undefined4 local_48;
  uint local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  if (((*(char *)(param_1 + 0x16f2) != '\0') && (*(char *)(param_1 + 0xb698) != '\0')) &&
     ((*(uint *)(param_1 + 0xb69c) & param_2) != 0)) {
    local_48 = 1;
    local_44 = param_2;
    LogSystemEvent(param_1,param_2,0xc004af02,
                   (byte *)"Master trigger occured-HTB is available, TriggerBitMask logged",param_3,
                   param_4);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x117) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x117,
                  (undefined1 *)&local_48,4,param_3,param_4);
    }
    uVar2 = ReleaseFwDiagBuffer(param_1,param_1 + 0x16e0,param_3,param_4);
    if ((char)uVar2 != '\0') {
      *(undefined1 *)(param_1 + 0x16f2) = 0;
      ZeroMemory((void *)(param_1 + 0xbbb4),0x10);
      *(ushort *)(param_1 + 0xbbb4) = *(ushort *)(param_1 + 0xbbb4) | 5;
      *(undefined4 *)(param_1 + 0xbbb8) = 1;
      *(uint *)(param_1 + 0xbbbc) = param_2;
      if (param_2 == 1) {
        uVar1 = ReadRegisterUlong(param_1,*(int **)(param_1 + 0x18));
        *(uint *)(param_1 + 0xbbc0) = *(uint *)(param_1 + 0xbbc0) | (uint)uVar1;
      }
      else if ((param_2 == 2) && (*(char *)(param_1 + 0x11bd) != '\0')) {
        *(uint *)(param_1 + 0xbbc0) = *(uint *)(param_1 + 0xbbc0) | 1;
      }
    }
    SendMpiEventToApplication(param_1,0x6e,&local_48,0xc);
  }
  return;
}



===== AfdMpiEventTrigger @ 140021320 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AfdMpiEventTrigger(longlong param_1,ushort param_2,ushort param_3,byte param_4,int param_5)

{
  bool bVar1;
  ushort *puVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined1 auStackY_88 [32];
  undefined4 local_48;
  ushort local_44;
  ushort local_42;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  bVar1 = false;
  if ((*(char *)(param_1 + 0x16f2) != '\0') && (*(char *)(param_1 + 0xb698) != '\0')) {
    puVar2 = (ushort *)(param_1 + 0xb6a4);
    uVar4 = 0;
    if (*(uint *)(param_1 + 0xb6a0) != 0) {
      do {
        if (bVar1) goto LAB_1400213ac;
        if ((*puVar2 == param_2) && ((param_2 != 0x21 || (puVar2[1] == param_3)))) {
          bVar1 = true;
        }
        uVar4 = uVar4 + 1;
        puVar2 = puVar2 + 2;
      } while (uVar4 < *(uint *)(param_1 + 0xb6a0));
      if (bVar1) {
LAB_1400213ac:
        local_48 = 2;
        local_44 = param_2;
        local_42 = param_3;
        LogSystemEvent(param_1,(uint)param_2,0xc004af02,
                       (byte *)"MPI event trigger occured-HTB is available, EventValue logged",
                       param_4,param_5);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x118) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x118,
                      (undefined1 *)&local_48,4,param_4,param_5);
        }
        uVar3 = ReleaseFwDiagBuffer(param_1,param_1 + 0x16e0,param_4,param_5);
        if ((char)uVar3 != '\0') {
          *(undefined1 *)(param_1 + 0x16f2) = 0;
          ZeroMemory((void *)(param_1 + 0xbbb4),0x10);
          *(ushort *)(param_1 + 0xbbb4) = *(ushort *)(param_1 + 0xbbb4) | 5;
          *(undefined4 *)(param_1 + 0xbbb8) = 2;
          *(uint *)(param_1 + 0xbbbc) = (uint)param_2;
        }
        SendMpiEventToApplication(param_1,0x6e,&local_48,0xc);
      }
    }
  }
  return;
}



===== AfdMpiLogInfoTrigger @ 1400214d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AfdMpiLogInfoTrigger(longlong param_1,int param_2,ushort param_3,byte param_4,int param_5)

{
  bool bVar1;
  ushort *puVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined1 auStackY_98 [32];
  undefined4 local_58;
  ushort local_54;
  int local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar1 = false;
  if ((*(char *)(param_1 + 0x16f2) != '\0') && (*(char *)(param_1 + 0xb698) != '\0')) {
    puVar2 = (ushort *)(param_1 + 0xb74c);
    uVar4 = 0;
    if (*(uint *)(param_1 + 0xb748) != 0) {
      do {
        if (bVar1) goto LAB_140021561;
        if ((*puVar2 == param_3) &&
           ((*(int *)(puVar2 + 2) == 0xffff || (*(int *)(puVar2 + 2) == param_2)))) {
          bVar1 = true;
        }
        uVar4 = uVar4 + 1;
        puVar2 = puVar2 + 4;
      } while (uVar4 < *(uint *)(param_1 + 0xb748));
      if (bVar1) {
LAB_140021561:
        local_58 = 4;
        local_54 = param_3;
        local_50 = param_2;
        LogSystemEvent(param_1,param_2,0xc004af02,
                       (byte *)"MPI loginfo trigger occured-HTB is available, LogInfo logged",
                       param_4,param_5);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x11a) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x11a,
                      (undefined1 *)&local_58,4,param_4,param_5);
        }
        uVar3 = ReleaseFwDiagBuffer(param_1,param_1 + 0x16e0,param_4,param_5);
        if ((char)uVar3 != '\0') {
          *(undefined1 *)(param_1 + 0x16f2) = 0;
          ZeroMemory((void *)(param_1 + 0xbbb4),0x10);
          *(ushort *)(param_1 + 0xbbb4) = *(ushort *)(param_1 + 0xbbb4) | 5;
          *(undefined4 *)(param_1 + 0xbbb8) = 4;
          *(uint *)(param_1 + 0xbbbc) = (uint)param_3;
          *(int *)(param_1 + 0xbbc0) = param_2;
        }
        SendMpiEventToApplication(param_1,0x6e,&local_58,0xc);
      }
    }
  }
  return;
}



===== AfdScsiSenseTrigger @ 140021680 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AfdScsiSenseTrigger(longlong param_1,char param_2,char param_3,char param_4,byte param_5,
                        int param_6)

{
  bool bVar1;
  char *pcVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined1 auStackY_98 [32];
  undefined4 local_58;
  char local_54;
  char local_53;
  char local_52;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar1 = false;
  if ((*(char *)(param_1 + 0x16f2) != '\0') && (*(char *)(param_1 + 0xb698) != '\0')) {
    pcVar2 = (char *)(param_1 + 0xb6f8);
    uVar4 = 0;
    if (*(uint *)(param_1 + 0xb6f4) != 0) {
      do {
        if (bVar1) goto LAB_14002171c;
        if (((pcVar2[2] == param_2) && ((pcVar2[1] == -1 || (pcVar2[1] == param_3)))) &&
           ((*pcVar2 == -1 || (*pcVar2 == param_4)))) {
          bVar1 = true;
        }
        uVar4 = uVar4 + 1;
        pcVar2 = pcVar2 + 4;
      } while (uVar4 < *(uint *)(param_1 + 0xb6f4));
      if (bVar1) {
LAB_14002171c:
        uVar4 = (uint)CONCAT21(CONCAT11(param_2,param_3),param_4);
        local_58 = 3;
        local_54 = param_4;
        local_53 = param_3;
        local_52 = param_2;
        LogSystemEvent(param_1,uVar4,0xc004af02,
                       (byte *)
                       "SCSI sense trigger occured-HTB is available, Ascq,Asc,SenseKey logged",
                       param_5,param_6);
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x119) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x119,
                      (undefined1 *)&local_58,4,param_5,param_6);
        }
        uVar3 = ReleaseFwDiagBuffer(param_1,param_1 + 0x16e0,param_5,param_6);
        if ((char)uVar3 != '\0') {
          *(undefined1 *)(param_1 + 0x16f2) = 0;
          ZeroMemory((void *)(param_1 + 0xbbb4),0x10);
          *(ushort *)(param_1 + 0xbbb4) = *(ushort *)(param_1 + 0xbbb4) | 5;
          *(undefined4 *)(param_1 + 0xbbb8) = 3;
          *(uint *)(param_1 + 0xbbbc) = uVar4;
        }
        SendMpiEventToApplication(param_1,0x6e,&local_58,0xc);
      }
    }
  }
  return;
}



===== DriverTriggerPageUpdateTimerCallback @ 140021870 =====

ulonglong DriverTriggerPageUpdateTimerCallback
                    (longlong param_1,undefined8 param_2,int *param_3,byte param_4,int param_5)

{
  ulonglong uVar1;
  
  *(undefined1 *)(param_1 + 0xb7ee) = 0;
  if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x284) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x284,
                (undefined1 *)param_3,4,param_4,param_5);
  }
  LogOperationalEvent(param_1,param_3,4,0x8004af01,
                      "Diag Reset(miniport)-Driver Trigger page update cmd timed out",param_4,
                      param_5);
  *(undefined4 *)(param_1 + 0x1218) = 1;
  uVar1 = KickStart(param_1,param_4,param_5);
  return uVar1 & 0xffffffffffffff00;
}



===== GetDriverTriggerPageHeader @ 140021940 =====

void GetDriverTriggerPageHeader(longlong param_1,undefined1 param_2,byte param_3,int param_4)

{
  char local_18 [2];
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_12;
  
  ZeroMemory(local_18,8);
  local_15 = 0xf;
  local_12 = 0xe0;
  local_16 = param_2;
  SendExtendedConfigPageMessage(param_1,'\0',local_18,0,0,param_3,param_4);
  return;
}



===== GetDriverTriggerValues @ 1400219c0 =====

void GetDriverTriggerValues(longlong param_1,byte param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  uint uVar6;
  ulonglong uVar7;
  char *pcVar8;
  bool bVar9;
  
  uVar7 = 0;
  uVar5 = 0;
LAB_1400219f3:
  do {
    bVar9 = true;
    switch(uVar5) {
    case 0:
      uVar5 = 1;
      goto LAB_1400219f3;
    case 1:
      GetDriverTriggerPageHeader(param_1,0,param_2,param_3);
      uVar5 = 2;
      break;
    case 2:
      SendExtendedConfigPageMessage
                (param_1,'\x06',(char *)(param_1 + 0xb904),0,(int)*(undefined8 *)(param_1 + 0x1860),
                 param_2,param_3);
      uVar5 = 3;
      break;
    case 3:
      *(uint *)(param_1 + 0xb7f0) = (uint)*(ushort *)(*(longlong *)(param_1 + 0x1860) + 8);
      GetDriverTriggerPageHeader(param_1,1,param_2,param_3);
      uVar5 = 4;
      break;
    case 4:
      if ((*(uint *)(param_1 + 0xb7f0) & 1) == 0) {
        bVar9 = false;
        uVar5 = 5;
      }
      else {
        SendExtendedConfigPageMessage
                  (param_1,'\x06',(char *)(param_1 + 0xb90c),0,
                   (int)*(undefined8 *)(param_1 + 0x1860),param_2,param_3);
        uVar5 = 5;
      }
      goto LAB_140021cbf;
    case 5:
      if (((*(uint *)(param_1 + 0xb7f0) & 1) != 0) &&
         (*(short *)(*(longlong *)(param_1 + 0x1860) + 8) != 0)) {
        *(uint *)(param_1 + 0xb69c) =
             *(uint *)(param_1 + 0xb69c) | *(uint *)(*(longlong *)(param_1 + 0x1860) + 0xc);
      }
      GetDriverTriggerPageHeader(param_1,2,param_2,param_3);
      uVar5 = 6;
      break;
    case 6:
      if ((*(uint *)(param_1 + 0xb7f0) & 2) == 0) {
        bVar9 = false;
        uVar5 = 7;
      }
      else {
        SendExtendedConfigPageMessage
                  (param_1,'\x06',(char *)(param_1 + 0xb914),0,
                   (int)*(undefined8 *)(param_1 + 0x1860),param_2,param_3);
        uVar5 = 7;
      }
      goto LAB_140021cbf;
    case 7:
      if ((*(uint *)(param_1 + 0xb7f0) & 2) != 0) {
        lVar2 = *(longlong *)(param_1 + 0x1860);
        if (*(ushort *)(lVar2 + 8) != 0) {
          *(uint *)(param_1 + 0xb6a0) = (uint)*(ushort *)(lVar2 + 8);
          uVar6 = 0;
          if (*(short *)(lVar2 + 8) != 0) {
            do {
              uVar4 = (ulonglong)uVar6;
              uVar6 = uVar6 + 1;
              *(undefined4 *)(param_1 + 0xb6a4 + uVar4 * 4) =
                   *(undefined4 *)(lVar2 + 0xc + uVar4 * 4);
            } while (uVar6 < *(ushort *)(lVar2 + 8));
          }
        }
      }
      GetDriverTriggerPageHeader(param_1,3,param_2,param_3);
      uVar5 = 8;
      break;
    case 8:
      if ((*(uint *)(param_1 + 0xb7f0) & 4) == 0) {
        bVar9 = false;
        uVar5 = 9;
      }
      else {
        SendExtendedConfigPageMessage
                  (param_1,'\x06',(char *)(param_1 + 0xb91c),0,
                   (int)*(undefined8 *)(param_1 + 0x1860),param_2,param_3);
        uVar5 = 9;
      }
      goto LAB_140021cbf;
    case 9:
      if ((*(uint *)(param_1 + 0xb7f0) & 4) != 0) {
        lVar2 = *(longlong *)(param_1 + 0x1860);
        if (*(ushort *)(lVar2 + 8) != 0) {
          *(uint *)(param_1 + 0xb6f4) = (uint)*(ushort *)(lVar2 + 8);
          uVar6 = 0;
          if (*(short *)(lVar2 + 8) != 0) {
            do {
              uVar4 = (ulonglong)uVar6;
              uVar6 = uVar6 + 1;
              *(undefined4 *)(param_1 + 0xb6f8 + uVar4 * 4) =
                   *(undefined4 *)(lVar2 + 0xc + uVar4 * 4);
            } while (uVar6 < *(ushort *)(lVar2 + 8));
          }
        }
      }
      GetDriverTriggerPageHeader(param_1,4,param_2,param_3);
      uVar5 = 10;
      break;
    case 10:
      bVar9 = (*(uint *)(param_1 + 0xb7f0) & 8) != 0;
      if (bVar9) {
        SendExtendedConfigPageMessage
                  (param_1,'\x06',(char *)(param_1 + 0xb924),0,
                   (int)*(undefined8 *)(param_1 + 0x1860),param_2,param_3);
      }
      uVar5 = 0xb;
LAB_140021cbf:
      if (!bVar9) goto LAB_1400219f3;
      break;
    case 0xb:
      if ((*(uint *)(param_1 + 0xb7f0) & 8) != 0) {
        lVar2 = *(longlong *)(param_1 + 0x1860);
        if ((*(ushort *)(lVar2 + 8) != 0) &&
           (*(uint *)(param_1 + 0xb748) = (uint)*(ushort *)(lVar2 + 8), *(short *)(lVar2 + 8) != 0))
        {
          do {
            lVar1 = uVar7 * 8;
            uVar6 = (int)uVar7 + 1;
            uVar7 = (ulonglong)uVar6;
            *(undefined8 *)(lVar1 + 0xb74c + param_1) = *(undefined8 *)(lVar1 + 0xc + lVar2);
          } while (uVar6 < *(ushort *)(lVar2 + 8));
        }
      }
    default:
      goto switchD_140021a0d_default;
    }
    uVar6 = 0;
    do {
      cVar3 = PollLSImpiIsr(param_1,param_2,param_3);
      if (cVar3 != '\0') goto LAB_140021d07;
      StorPortStallExecution(500);
      uVar6 = uVar6 + 1;
    } while (uVar6 < 10000);
    if (uVar6 == 10000) goto LAB_140021d14;
LAB_140021d07:
    if (*(short *)(param_1 + 0x185a) != 0) {
LAB_140021d14:
      pcVar8 = "Driver Trigger Persistence page read timed out";
      if (uVar6 != 10000) {
        pcVar8 = "Driver Trigger Persistence read unsuccessful";
      }
      LogSystemEvent(param_1,0,0xc004af02,(byte *)pcVar8,param_2,param_3);
switchD_140021a0d_default:
      return;
    }
  } while( true );
}



===== GetSetDriverTriggerPage @ 140021de0 =====

ulonglong GetSetDriverTriggerPage
                    (longlong param_1,byte param_2,char param_3,int param_4,byte param_5,int param_6
                    )

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  
  if (param_2 == 0) {
    lVar2 = 0xb904;
  }
  else if (param_2 == 1) {
    lVar2 = 0xb90c;
  }
  else if (param_2 == 2) {
    lVar2 = 0xb914;
  }
  else if (param_2 == 3) {
    lVar2 = 0xb91c;
  }
  else {
    if (param_2 != 4) {
      uVar1 = LogSystemEvent(param_1,(uint)param_2,0x8004af01,
                             (byte *)"Invalid DTP page num read request(Page num logged)",param_5,
                             param_6);
      return uVar1 & 0xffffffffffffff00;
    }
    lVar2 = 0xb924;
  }
  cVar4 = '\x06';
  if (param_3 == '\0') {
    cVar4 = '\x04';
  }
  uVar3 = SendExtendedConfigPageMessage
                    (param_1,cVar4,(char *)(lVar2 + param_1),0,param_4,param_5,param_6);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== HandleAfdTriggerIoctl @ 140021ea0 =====

undefined8
HandleAfdTriggerIoctl
          (longlong param_1,longlong param_2,undefined1 *param_3,byte param_4,int param_5)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  ulonglong uVar4;
  byte bVar5;
  undefined4 local_res10 [2];
  
  *(undefined4 *)(param_2 + 0x14) = 0;
  *param_3 = 1;
  *(undefined4 *)(param_2 + 0x1c) = AutoFwDiagBuffRecordVersion;
  iVar1 = *(int *)(param_2 + 0x20);
  if (iVar1 < 0) {
LAB_140022772:
    *(undefined4 *)(param_2 + 0x14) = 2;
  }
  else {
    if (iVar1 < 3) {
      if (0xaf < *(uint *)(param_2 + 0x18)) {
        if (iVar1 == 0) {
          iVar1 = *(int *)(param_2 + 0x24);
          if (iVar1 == 1) {
            *(uint *)(param_1 + 0xb69c) = *(uint *)(param_2 + 0x28) | 3;
            if (*(char *)(param_1 + 0xb7ed) == '\0') {
              return 1;
            }
            pvVar2 = *(void **)(param_1 + 0x1860);
            ZeroMemory(pvVar2,0x10);
            *(undefined2 *)((longlong)pvVar2 + 8) = 1;
            *(uint *)((longlong)pvVar2 + 0xc) =
                 *(uint *)((longlong)pvVar2 + 0xc) | *(uint *)(param_1 + 0xb69c);
            *(undefined1 *)(param_1 + 0xb7ee) = 1;
            local_res10[0] = 0xe;
            uVar4 = GtfStartTimer(param_1,1,10,DriverTriggerPageUpdateTimerCallback,local_res10,
                                  param_4,param_5);
            *(char *)(param_1 + 0xb7ec) = (char)uVar4;
            if ((char)uVar4 == -2) {
              if (*(short *)(param_1 + 0x960) != 0) {
                LogSystemEvent(param_1,0,0x8004af01,
                               (byte *)"No timer available to time trigger page update",param_4,
                               param_5);
              }
              if ((*(char *)(param_1 + 0x608) != '\0') &&
                 ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                            (undefined1 *)0x0,0,param_4,param_5);
              }
            }
            GetSetDriverTriggerPage(param_1,1,'\0',(int)pvVar2,param_4,param_5);
            *param_3 = 0;
            return 1;
          }
          if (iVar1 == 2) {
            if (*(int *)(param_2 + 0x28) - 1U < 0x14) {
              *(int *)(param_1 + 0xb6a0) = *(int *)(param_2 + 0x28);
              uVar4 = 0;
              if (*(int *)(param_2 + 0x28) != 0) {
                do {
                  bVar5 = (char)uVar4 + 1;
                  *(undefined4 *)(param_1 + 0xb6a4 + uVar4 * 4) =
                       *(undefined4 *)(param_2 + 0x2c + uVar4 * 4);
                  uVar4 = (ulonglong)bVar5;
                } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
              }
              if (*(char *)(param_1 + 0xb7ed) == '\0') {
                return 1;
              }
              pvVar2 = *(void **)(param_1 + 0x1860);
              ZeroMemory(pvVar2,0x5c);
              *(undefined2 *)((longlong)pvVar2 + 8) = *(undefined2 *)(param_1 + 0xb6a0);
              uVar4 = 0;
              if (*(int *)(param_2 + 0x28) != 0) {
                do {
                  bVar5 = (char)uVar4 + 1;
                  *(undefined4 *)((longlong)pvVar2 + uVar4 * 4 + 0xc) =
                       *(undefined4 *)(param_2 + 0x2c + uVar4 * 4);
                  uVar4 = (ulonglong)bVar5;
                } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
              }
              *(undefined1 *)(param_1 + 0xb7ee) = 1;
              local_res10[0] = 0xf;
              uVar4 = GtfStartTimer(param_1,1,10,DriverTriggerPageUpdateTimerCallback,local_res10,
                                    param_4,param_5);
              *(char *)(param_1 + 0xb7ec) = (char)uVar4;
              if ((char)uVar4 == -2) {
                if (*(short *)(param_1 + 0x960) != 0) {
                  LogSystemEvent(param_1,0,0x8004af01,
                                 (byte *)"No timer available to time trigger page update",param_4,
                                 param_5);
                }
                if ((*(char *)(param_1 + 0x608) != '\0') &&
                   ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
                  RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                              0x233,(undefined1 *)0x0,0,param_4,param_5);
                }
              }
              GetSetDriverTriggerPage(param_1,2,'\0',(int)pvVar2,param_4,param_5);
              *param_3 = 0;
              return 1;
            }
          }
          else if (iVar1 == 3) {
            if (*(int *)(param_2 + 0x28) - 1U < 0x14) {
              *(int *)(param_1 + 0xb6f4) = *(int *)(param_2 + 0x28);
              uVar4 = 0;
              if (*(int *)(param_2 + 0x28) != 0) {
                do {
                  bVar5 = (char)uVar4 + 1;
                  *(undefined4 *)(param_1 + 0xb6f8 + uVar4 * 4) =
                       *(undefined4 *)(param_2 + 0x2c + uVar4 * 4);
                  uVar4 = (ulonglong)bVar5;
                } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
              }
              if (*(char *)(param_1 + 0xb7ed) == '\0') {
                return 1;
              }
              pvVar2 = *(void **)(param_1 + 0x1860);
              ZeroMemory(pvVar2,0x5c);
              *(undefined2 *)((longlong)pvVar2 + 8) = *(undefined2 *)(param_1 + 0xb6f4);
              uVar4 = 0;
              if (*(int *)(param_2 + 0x28) != 0) {
                do {
                  bVar5 = (char)uVar4 + 1;
                  *(undefined4 *)((longlong)pvVar2 + uVar4 * 4 + 0xc) =
                       *(undefined4 *)(param_2 + 0x2c + uVar4 * 4);
                  uVar4 = (ulonglong)bVar5;
                } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
              }
              *(undefined1 *)(param_1 + 0xb7ee) = 1;
              local_res10[0] = 0x10;
              uVar4 = GtfStartTimer(param_1,1,10,DriverTriggerPageUpdateTimerCallback,local_res10,
                                    param_4,param_5);
              *(char *)(param_1 + 0xb7ec) = (char)uVar4;
              if ((char)uVar4 == -2) {
                if (*(short *)(param_1 + 0x960) != 0) {
                  LogSystemEvent(param_1,0,0x8004af01,
                                 (byte *)"No timer available to time trigger page update",param_4,
                                 param_5);
                }
                if ((*(char *)(param_1 + 0x608) != '\0') &&
                   ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
                  RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                              0x233,(undefined1 *)0x0,0,param_4,param_5);
                }
              }
              GetSetDriverTriggerPage(param_1,3,'\0',(int)pvVar2,param_4,param_5);
              *param_3 = 0;
              return 1;
            }
          }
          else {
            if (iVar1 != 4) goto LAB_140021f5c;
            if (*(int *)(param_2 + 0x28) - 1U < 0x14) {
              *(int *)(param_1 + 0xb748) = *(int *)(param_2 + 0x28);
              uVar4 = 0;
              if (*(int *)(param_2 + 0x28) != 0) {
                do {
                  bVar5 = (char)uVar4 + 1;
                  *(undefined8 *)(uVar4 * 8 + 0xb74c + param_1) =
                       *(undefined8 *)(uVar4 * 8 + 0x2c + param_2);
                  uVar4 = (ulonglong)bVar5;
                } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
              }
              if (*(char *)(param_1 + 0xb7ed) == '\0') {
                return 1;
              }
              pvVar2 = *(void **)(param_1 + 0x1860);
              ZeroMemory(pvVar2,0xac);
              uVar4 = 0;
              *(undefined2 *)((longlong)pvVar2 + 8) = *(undefined2 *)(param_1 + 0xb748);
              if (*(int *)(param_2 + 0x28) != 0) {
                do {
                  bVar5 = (char)uVar4 + 1;
                  *(undefined8 *)(uVar4 * 8 + 0xc + (longlong)pvVar2) =
                       *(undefined8 *)(uVar4 * 8 + 0x2c + param_2);
                  uVar4 = (ulonglong)bVar5;
                } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
              }
              *(undefined1 *)(param_1 + 0xb7ee) = 1;
              local_res10[0] = 0x11;
              uVar4 = GtfStartTimer(param_1,1,10,DriverTriggerPageUpdateTimerCallback,local_res10,
                                    param_4,param_5);
              *(char *)(param_1 + 0xb7ec) = (char)uVar4;
              if ((char)uVar4 == -2) {
                if (*(short *)(param_1 + 0x960) != 0) {
                  LogSystemEvent(param_1,0,0x8004af01,
                                 (byte *)"No timer available to time trigger page update",param_4,
                                 param_5);
                }
                if ((*(char *)(param_1 + 0x608) != '\0') &&
                   ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
                  RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),
                              0x233,(undefined1 *)0x0,0,param_4,param_5);
                }
              }
              GetSetDriverTriggerPage(param_1,4,'\0',(int)pvVar2,param_4,param_5);
              *param_3 = 0;
              return 1;
            }
          }
          *(undefined4 *)(param_2 + 0x14) = 4;
          return 0;
        }
        if (iVar1 != 1) {
          if (iVar1 != 2) {
            return 1;
          }
          iVar1 = *(int *)(param_2 + 0x24);
          if (iVar1 == 1) {
            *(undefined4 *)(param_1 + 0xb69c) = 3;
            if (*(char *)(param_1 + 0xb7ed) == '\0') {
              return 1;
            }
            if ((*(uint *)(param_1 + 0xb7f0) & 1) == 0) {
              return 1;
            }
            uVar3 = *(uint *)(param_1 + 0xb7f0) & 0xfffffffe;
          }
          else if (iVar1 == 2) {
            ZeroMemory((void *)(param_1 + 0xb6a0),0x54);
            if (*(char *)(param_1 + 0xb7ed) == '\0') {
              return 1;
            }
            if ((*(uint *)(param_1 + 0xb7f0) & 2) == 0) {
              return 1;
            }
            uVar3 = *(uint *)(param_1 + 0xb7f0) & 0xfffffffd;
          }
          else if (iVar1 == 3) {
            ZeroMemory((void *)(param_1 + 0xb6f4),0x54);
            if (*(char *)(param_1 + 0xb7ed) == '\0') {
              return 1;
            }
            if ((*(uint *)(param_1 + 0xb7f0) & 4) == 0) {
              return 1;
            }
            uVar3 = *(uint *)(param_1 + 0xb7f0) & 0xfffffffb;
          }
          else {
            if (iVar1 != 4) goto LAB_140021f5c;
            ZeroMemory((void *)(param_1 + 0xb748),0xa4);
            if (*(char *)(param_1 + 0xb7ed) == '\0') {
              return 1;
            }
            if ((*(uint *)(param_1 + 0xb7f0) & 8) == 0) {
              return 1;
            }
            uVar3 = *(uint *)(param_1 + 0xb7f0) & 0xfffffff7;
          }
          pvVar2 = *(void **)(param_1 + 0x1860);
          *(uint *)(param_1 + 0xb7f0) = uVar3;
          ZeroMemory(pvVar2,0x100);
          *(ushort *)((longlong)pvVar2 + 8) =
               *(ushort *)((longlong)pvVar2 + 8) | *(ushort *)(param_1 + 0xb7f0);
          *(undefined1 *)(param_1 + 0xb7ee) = 1;
          local_res10[0] = 0xd;
          uVar4 = GtfStartTimer(param_1,1,10,DriverTriggerPageUpdateTimerCallback,local_res10,
                                param_4,param_5);
          *(char *)(param_1 + 0xb7ec) = (char)uVar4;
          if ((char)uVar4 == -2) {
            if (*(short *)(param_1 + 0x960) != 0) {
              LogSystemEvent(param_1,0,0x8004af01,
                             (byte *)"No timer available to time trigger page update",param_4,
                             param_5);
            }
            if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                          (undefined1 *)0x0,0,param_4,param_5);
            }
          }
          GetSetDriverTriggerPage(param_1,0,'\0',(int)pvVar2,param_4,param_5);
          *param_3 = 0;
          return 1;
        }
        iVar1 = *(int *)(param_2 + 0x24);
        if (iVar1 == 1) {
          *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0xb69c);
          return 1;
        }
        if (iVar1 == 2) {
          iVar1 = *(int *)(param_1 + 0xb6a0);
          *(int *)(param_2 + 0x28) = iVar1;
          uVar4 = 0;
          if (iVar1 == 0) {
            return 1;
          }
          do {
            bVar5 = (char)uVar4 + 1;
            *(undefined4 *)(param_2 + 0x2c + uVar4 * 4) =
                 *(undefined4 *)(param_1 + 0xb6a4 + uVar4 * 4);
            uVar4 = (ulonglong)bVar5;
          } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
          return 1;
        }
        if (iVar1 == 3) {
          iVar1 = *(int *)(param_1 + 0xb6f4);
          *(int *)(param_2 + 0x28) = iVar1;
          uVar4 = 0;
          if (iVar1 == 0) {
            return 1;
          }
          do {
            bVar5 = (char)uVar4 + 1;
            *(undefined4 *)(param_2 + 0x2c + uVar4 * 4) =
                 *(undefined4 *)(param_1 + 0xb6f8 + uVar4 * 4);
            uVar4 = (ulonglong)bVar5;
          } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
          return 1;
        }
        if (iVar1 == 4) {
          iVar1 = *(int *)(param_1 + 0xb748);
          *(int *)(param_2 + 0x28) = iVar1;
          uVar4 = 0;
          if (iVar1 == 0) {
            return 1;
          }
          do {
            bVar5 = (char)uVar4 + 1;
            *(undefined8 *)(uVar4 * 8 + 0x2c + param_2) =
                 *(undefined8 *)(uVar4 * 8 + 0xb74c + param_1);
            uVar4 = (ulonglong)bVar5;
          } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
          return 1;
        }
LAB_140021f5c:
        *(undefined4 *)(param_2 + 0x14) = 1;
        return 0;
      }
    }
    else {
      if (iVar1 != 3) goto LAB_140022772;
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



===== ProcessDTPUpdateReplies @ 1400227a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ProcessDTPUpdateReplies(longlong param_1,longlong param_2,byte param_3,int param_4)

{
  longlong lVar1;
  bool bVar2;
  ulonglong uVar3;
  uint uVar4;
  void *pvVar5;
  undefined1 auStackY_98 [32];
  undefined4 local_58 [2];
  longlong local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar2 = false;
  uVar4 = (uint)*(byte *)(param_2 + 0x16);
  if (*(byte *)(param_2 + 0x16) == 0) {
    *(undefined1 *)(param_1 + 0xb7ee) = 0;
    GtfStopTimer(param_1,*(byte *)(param_1 + 0xb7ec),param_3,param_4);
  }
  else if (uVar4 == 1) {
    *(undefined1 *)(param_1 + 0xb7ee) = 0;
    GtfStopTimer(param_1,*(byte *)(param_1 + 0xb7ec),param_3,param_4);
    if ((*(uint *)(param_1 + 0xb7f0) & 1) == 0) {
      pvVar5 = *(void **)(param_1 + 0x1860);
      ZeroMemory(pvVar5,0x100);
      *(uint *)(param_1 + 0xb7f0) = *(uint *)(param_1 + 0xb7f0) | 1;
LAB_14002292c:
      *(ushort *)((longlong)pvVar5 + 8) =
           *(ushort *)((longlong)pvVar5 + 8) | (ushort)*(undefined4 *)(param_1 + 0xb7f0);
      *(undefined1 *)(param_1 + 0xb7ee) = 1;
      local_58[0] = 0xd;
      uVar3 = GtfStartTimer(param_1,1,10,DriverTriggerPageUpdateTimerCallback,local_58,param_3,
                            param_4);
      *(char *)(param_1 + 0xb7ec) = (char)uVar3;
      if ((char)uVar3 == -2) {
        if (*(short *)(param_1 + 0x960) != 0) {
          LogSystemEvent(param_1,0,0x8004af01,
                         (byte *)"No timer available to time trigger page update",param_3,param_4);
        }
        if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x233) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x233,
                      (undefined1 *)0x0,0,param_3,param_4);
        }
      }
      GetSetDriverTriggerPage(param_1,0,'\0',(int)pvVar5,param_3,param_4);
      return;
    }
  }
  else if (uVar4 == 2) {
    *(undefined1 *)(param_1 + 0xb7ee) = 0;
    GtfStopTimer(param_1,*(byte *)(param_1 + 0xb7ec),param_3,param_4);
    if ((*(uint *)(param_1 + 0xb7f0) & 2) == 0) {
      pvVar5 = *(void **)(param_1 + 0x1860);
      ZeroMemory(pvVar5,0x100);
      *(uint *)(param_1 + 0xb7f0) = *(uint *)(param_1 + 0xb7f0) | 2;
      goto LAB_14002292c;
    }
  }
  else if (uVar4 == 3) {
    *(undefined1 *)(param_1 + 0xb7ee) = 0;
    GtfStopTimer(param_1,*(byte *)(param_1 + 0xb7ec),param_3,param_4);
    if ((*(uint *)(param_1 + 0xb7f0) & 4) == 0) {
      StorPortStallExecution(500);
      pvVar5 = *(void **)(param_1 + 0x1860);
      ZeroMemory(pvVar5,0x100);
      *(uint *)(param_1 + 0xb7f0) = *(uint *)(param_1 + 0xb7f0) | 4;
      goto LAB_14002292c;
    }
  }
  else if (uVar4 == 4) {
    *(undefined1 *)(param_1 + 0xb7ee) = 0;
    GtfStopTimer(param_1,*(byte *)(param_1 + 0xb7ec),param_3,param_4);
    if ((*(uint *)(param_1 + 0xb7f0) & 8) == 0) {
      pvVar5 = *(void **)(param_1 + 0x1860);
      ZeroMemory(pvVar5,0x100);
      *(uint *)(param_1 + 0xb7f0) = *(uint *)(param_1 + 0xb7f0) | 8;
      goto LAB_14002292c;
    }
  }
  else {
    LogSystemEvent(param_1,uVar4,0xc004af02,
                   (byte *)"ProcessDTPUpdateReplies has invalid page num (page num is logged)",
                   param_3,param_4);
    bVar2 = true;
  }
  if ((*(char *)(param_1 + 0x1220) == '\0') && (*(longlong *)(param_1 + 0x1228) == 0)) {
    CleanUpIoctl(param_1,param_3,param_4);
  }
  else {
    local_50 = *(longlong *)(param_1 + 0x1228);
    local_48 = *(undefined4 *)(*(longlong *)(local_50 + 0x40) + 0x10);
    lVar1 = *(longlong *)(local_50 + 0x40);
    if (bVar2) {
      *(undefined1 *)(local_50 + 3) = 4;
      local_40 = 4;
      if (lVar1 != 0) {
        *(undefined4 *)(lVar1 + 0x14) = 6;
        local_40 = *(undefined1 *)(local_50 + 3);
      }
    }
    else {
      *(undefined1 *)(local_50 + 3) = 1;
      local_40 = 1;
    }
    if (lVar1 != 0) {
      local_44 = *(undefined4 *)(lVar1 + 0x14);
    }
    StorPortNotification(0,param_1);
    if ((*(char *)(param_1 + 0x608) != '\0') && ((*(uint *)(param_1 + 0x60c) & 0x400027) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0x11d7),(ulonglong *)(param_1 + 0x5d8),0x400027,
                  (undefined1 *)&local_50,0x11,param_3,param_4);
    }
    *(undefined1 *)(param_1 + 0x1220) = 0;
    *(undefined8 *)(param_1 + 0x1228) = 0;
  }
  CheckIoctlQueue(param_1,param_3,param_4);
  return;
}



===== SetDriverTriggerValues @ 140022b30 =====

void SetDriverTriggerValues(longlong param_1,byte param_2,int param_3)

{
  short sVar1;
  void *pvVar2;
  bool bVar3;
  char cVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined4 uVar7;
  char *pcVar8;
  
  uVar7 = 0xc;
LAB_140022b70:
  do {
    bVar3 = true;
    switch(uVar7) {
    case 0xc:
      uVar7 = 0xd;
      goto LAB_140022b70;
    case 0xd:
      pvVar2 = *(void **)(param_1 + 0x1860);
      ZeroMemory(pvVar2,0x100);
      *(ushort *)((longlong)pvVar2 + 8) =
           *(ushort *)((longlong)pvVar2 + 8) | *(ushort *)(param_1 + 0xb7f0);
      SendExtendedConfigPageMessage
                (param_1,'\x04',(char *)(param_1 + 0xb904),0,(int)pvVar2,param_2,param_3);
      uVar7 = 0xe;
      goto LAB_140022de8;
    case 0xe:
      if ((*(uint *)(param_1 + 0xb7f0) & 1) == 0) {
        bVar3 = false;
        uVar7 = 0xf;
      }
      else {
        pvVar2 = *(void **)(param_1 + 0x1860);
        ZeroMemory(pvVar2,0x10);
        *(undefined2 *)((longlong)pvVar2 + 8) = 1;
        *(uint *)((longlong)pvVar2 + 0xc) =
             *(uint *)((longlong)pvVar2 + 0xc) | *(uint *)(param_1 + 0xb69c);
        SendExtendedConfigPageMessage
                  (param_1,'\x04',(char *)(param_1 + 0xb90c),0,(int)pvVar2,param_2,param_3);
        uVar7 = 0xf;
      }
      break;
    case 0xf:
      if ((*(uint *)(param_1 + 0xb7f0) & 2) == 0) {
        bVar3 = false;
        uVar7 = 0x10;
      }
      else {
        pvVar2 = *(void **)(param_1 + 0x1860);
        ZeroMemory(pvVar2,0x5c);
        sVar1 = *(short *)(param_1 + 0xb6a0);
        uVar6 = 0;
        *(short *)((longlong)pvVar2 + 8) = sVar1;
        if (sVar1 != 0) {
          do {
            uVar5 = (ulonglong)uVar6;
            uVar6 = uVar6 + 1;
            *(undefined4 *)((longlong)pvVar2 + uVar5 * 4 + 0xc) =
                 *(undefined4 *)(param_1 + 0xb6a4 + uVar5 * 4);
          } while (uVar6 < *(ushort *)((longlong)pvVar2 + 8));
        }
        SendExtendedConfigPageMessage
                  (param_1,'\x04',(char *)(param_1 + 0xb914),0,(int)pvVar2,param_2,param_3);
        uVar7 = 0x10;
      }
      break;
    case 0x10:
      if ((*(uint *)(param_1 + 0xb7f0) & 4) == 0) {
        bVar3 = false;
        uVar7 = 0x11;
      }
      else {
        pvVar2 = *(void **)(param_1 + 0x1860);
        ZeroMemory(pvVar2,0x5c);
        sVar1 = *(short *)(param_1 + 0xb6f4);
        uVar6 = 0;
        *(short *)((longlong)pvVar2 + 8) = sVar1;
        if (sVar1 != 0) {
          do {
            uVar5 = (ulonglong)uVar6;
            uVar6 = uVar6 + 1;
            *(undefined4 *)((longlong)pvVar2 + uVar5 * 4 + 0xc) =
                 *(undefined4 *)(param_1 + 0xb6f8 + uVar5 * 4);
          } while (uVar6 < *(ushort *)((longlong)pvVar2 + 8));
        }
        SendExtendedConfigPageMessage
                  (param_1,'\x04',(char *)(param_1 + 0xb91c),0,(int)pvVar2,param_2,param_3);
        uVar7 = 0x11;
      }
      break;
    case 0x11:
      if ((*(uint *)(param_1 + 0xb7f0) & 8) == 0) {
        bVar3 = false;
      }
      else {
        pvVar2 = *(void **)(param_1 + 0x1860);
        ZeroMemory(pvVar2,0xac);
        sVar1 = *(short *)(param_1 + 0xb748);
        uVar6 = 0;
        *(short *)((longlong)pvVar2 + 8) = sVar1;
        if (sVar1 != 0) {
          do {
            uVar5 = (ulonglong)uVar6;
            uVar6 = uVar6 + 1;
            *(undefined8 *)(uVar5 * 8 + 0xc + (longlong)pvVar2) =
                 *(undefined8 *)(uVar5 * 8 + 0xb74c + param_1);
          } while (uVar6 < *(ushort *)((longlong)pvVar2 + 8));
        }
        SendExtendedConfigPageMessage
                  (param_1,'\x04',(char *)(param_1 + 0xb924),0,(int)pvVar2,param_2,param_3);
      }
      uVar7 = 0x12;
      break;
    default:
      goto switchD_140022b8c_caseD_12;
    }
    if (bVar3) {
LAB_140022de8:
      uVar6 = 0;
      do {
        cVar4 = PollLSImpiIsr(param_1,param_2,param_3);
        if (cVar4 != '\0') goto LAB_140022e27;
        StorPortStallExecution(500);
        uVar6 = uVar6 + 1;
      } while (uVar6 < 10000);
      if (uVar6 == 10000) goto LAB_140022e35;
LAB_140022e27:
      if (*(short *)(param_1 + 0x185a) != 0) {
LAB_140022e35:
        pcVar8 = "Driver Trigger Persistence page right timed out";
        if (uVar6 != 10000) {
          pcVar8 = "Driver Trigger Persistence write unsuccessful";
        }
        LogSystemEvent(param_1,0,0xc004af02,(byte *)pcVar8,param_2,param_3);
switchD_140022b8c_caseD_12:
        return;
      }
    }
  } while( true );
}



===== __security_check_cookie @ 140022ec0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 140022ee0 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 140022ef0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== StorPortInitialize @ 140022f00 =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortGetBusData @ 140022f06 =====

void StorPortGetBusData(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetBusData();
  return;
}



===== StorPortGetDeviceBase @ 140022f0c =====

void StorPortGetDeviceBase(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetDeviceBase();
  return;
}



===== StorPortGetLogicalUnit @ 140022f12 =====

void StorPortGetLogicalUnit(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetLogicalUnit();
  return;
}



===== StorPortGetScatterGatherList @ 140022f18 =====

void StorPortGetScatterGatherList(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetScatterGatherList();
  return;
}



===== StorPortGetPhysicalAddress @ 140022f1e =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortGetUncachedExtension @ 140022f24 =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortBusy @ 140022f2a =====

void StorPortBusy(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortBusy();
  return;
}



===== StorPortNotification @ 140022f30 =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== StorPortStallExecution @ 140022f36 =====

void StorPortStallExecution(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== StorPortExtendedFunction @ 140022f3c =====

void StorPortExtendedFunction(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140022f3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortExtendedFunction();
  return;
}



===== __GSHandlerCheck @ 140022f44 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140022f64 =====

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



===== memcmp @ 140022fe0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140023023;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140023094;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140023090:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140023094;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14002308c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140023090;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14002308c;
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
LAB_140023094:
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
LAB_140023023:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== ScsiPortWmiDispatchFunction @ 1400230b0 =====

undefined8
ScsiPortWmiDispatchFunction
          (uint *param_1,byte param_2,undefined8 param_3,longlong param_4,ulonglong *param_5,
          uint param_6,uint *param_7)

{
  char cVar1;
  undefined8 in_RAX;
  undefined7 uVar2;
  undefined7 extraout_var;
  int local_res10 [6];
  uint local_18 [4];
  
  local_res10[0] = 0;
  local_18[0] = 0;
  *(undefined4 *)(param_4 + 0x1c) = 0;
  if (param_2 < 10) {
    *(uint **)(param_4 + 0x10) = param_7;
    *(uint *)(param_4 + 8) = param_6;
    *(byte *)(param_4 + 0x18) = param_2;
    cVar1 = ScsiWmipProcessRequest
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,local_18,
                       (short *)local_res10);
    uVar2 = extraout_var;
    if (local_res10[0] == 1) {
      *(char *)(param_4 + 0x19) = cVar1;
      if (cVar1 != '\x01') {
        local_18[0] = 0;
      }
      *(uint *)(param_4 + 0x1c) = local_18[0];
    }
  }
  else {
    uVar2 = (undefined7)((ulonglong)in_RAX >> 8);
    cVar1 = '\x04';
    *(undefined1 *)(param_4 + 0x19) = 4;
  }
  return CONCAT71(uVar2,cVar1 == '\0');
}



===== ScsiPortWmiFireLogicalUnitEvent @ 140023154 =====

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



===== ScsiPortWmiPostProcess @ 1400231dc =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  
  cVar1 = ScsiWmipPostProcess(*(char *)(param_1 + 0x18),*(uint **)(param_1 + 0x10),
                              *(uint *)(param_1 + 8),param_3,param_2,(uint *)(param_1 + 0x1c));
  *(char *)(param_1 + 0x19) = cVar1;
  return;
}



===== ScsiWmipFindGuid @ 140023210 =====

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



===== ScsiWmipPostProcess @ 140023270 =====

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
        goto LAB_140023338;
      }
      param_5 = '\x12';
    }
LAB_140023316:
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_140023338;
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
        goto LAB_140023338;
      }
      goto LAB_140023316;
    }
    if (param_1 != '\t') goto LAB_140023338;
    uVar5 = param_2[0xf] + param_4;
    if (param_5 == '\x01') {
      if (0x47 < param_3) {
        *param_2 = uVar5;
        param_2[0x10] = param_4;
        uVar7 = uVar5;
      }
      goto LAB_140023338;
    }
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_140023338;
    param_2[0xc] = uVar5;
  }
  *param_2 = 0x38;
  param_2[0xb] = 0x20;
  param_5 = '\x01';
  uVar7 = 0x38;
LAB_140023338:
  *param_6 = uVar7;
  return param_5;
}



===== ScsiWmipProcessRequest @ 1400233c0 =====

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
LAB_1400234b8:
      *param_8 = 0;
      cVar5 = '\x04';
      goto LAB_1400237c6;
    }
    if (((byte)(param_2 - 1) < 3) || (param_2 == 9)) {
      uVar6 = param_7[0xd];
      if (((char)param_7[0xb] < '\0') && (local_38[0] <= uVar6)) goto LAB_1400234b8;
    }
    else {
      uVar6 = 0;
    }
  }
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_1400234fd;
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
              goto LAB_1400237ed;
            }
            goto LAB_140023800;
          }
LAB_1400234fd:
          cVar5 = '\x04';
          goto LAB_140023802;
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
LAB_1400235db:
      cVar5 = (*pcVar8)(param_3,param_4,local_res10[0],uVar6,uVar19,puVar14,iVar16,lVar12);
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar20 = 0;
      uVar17 = 0;
      goto LAB_1400237f1;
    }
  }
  else if (param_2 == 6) {
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar17 = 1;
LAB_1400237ed:
      uVar20 = 1;
LAB_1400237f1:
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
              goto LAB_1400235db;
            }
          }
          cVar5 = '\x04';
          goto LAB_140023802;
        }
        goto LAB_1400234fd;
      }
      param_9 = (short *)0x0;
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
          goto LAB_1400237b9;
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
LAB_1400237b9:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_1400237c6:
      psVar4[0] = 1;
      psVar4[1] = 0;
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar20 = 0;
      uVar17 = 1;
      goto LAB_1400237f1;
    }
  }
LAB_140023800:
  cVar5 = '\x01';
LAB_140023802:
  psVar4[0] = 1;
  psVar4[1] = 0;
  return cVar5;
}



===== _guard_dispatch_icall @ 140023840 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140023840. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memmove @ 140023880 =====

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



===== memset @ 140023b40 =====

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



===== entry @ 14002e000 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14002e02c =====

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


