
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



===== DriverEntry @ 140001020 =====

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  PciIdeXInitialize(param_1,param_2,PiixIdeGetControllerProperties,0x41c);
  return;
}



===== PiixIdeChannelEnabled @ 140001050 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

byte PiixIdeChannelEnabled(undefined8 param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  undefined1 auStack_88 [32];
  undefined1 local_68 [64];
  undefined1 local_28;
  byte abStack_27 [15];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  memset(local_68,0,0x4c);
  if ((param_2 & 0xfffffffe) == 0) {
    iVar2 = PciIdeXGetBusData(param_1,&local_28,0x40);
    if (iVar2 < 0) {
      bVar1 = 2;
    }
    else {
      bVar1 = abStack_27[(ulonglong)param_2 * 2] >> 7;
    }
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}



===== PiixIdeGetControllerProperties @ 1400010f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PiixIdeGetControllerProperties(short *param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  undefined8 uVar3;
  uint *puVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_118 [32];
  int local_f8 [4];
  short local_e8;
  short local_e6;
  byte local_df;
  undefined1 local_a8 [84];
  byte local_54;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_118;
  memset(&local_e8,0,0x40);
  if (*param_2 == 0x50) {
    uVar3 = PciIdeXGetBusData(param_1,&local_e8,0,0x40);
    iVar2 = (int)uVar3;
    if (-1 < iVar2) {
      *param_1 = local_e6;
      if (local_e8 == -0x7f7a) {
        param_1[0xc] = 0;
        param_1[0xd] = 0;
        uVar8 = 0x1f;
        if ((local_df & 0x80) != 0) {
          uVar7 = 0x7ff;
          if (((((local_e6 == 0x7111) ||
                ((((ushort)(local_e6 + 0xdbefU) < 0x3b &&
                  ((0x601000000010001U >> ((ulonglong)(ushort)(local_e6 + 0xdbefU) & 0x3f) & 1) != 0
                  )) || (local_e6 == 0x7601)))) ||
               ((local_e6 == 0x7199 || ((ushort)(local_e6 + 0xdb76U) < 2)))) ||
              ((((ushort)(local_e6 + 0xdb3fU) < 0x1b &&
                ((0x4010601U >> ((ushort)(local_e6 + 0xdb3fU) & 0x1f) & 1) != 0)) ||
               ((((ushort)(local_e6 + 0xda5eU) < 2 || ((ushort)(local_e6 + 0xd9afU) < 3)) ||
                ((local_e6 == 0x266f ||
                 (((ushort)(local_e6 + 0xd840U) < 0x20 &&
                  ((0x80000011U >> ((ushort)(local_e6 + 0xd840U) & 0x1f) & 1) != 0)))))))))) ||
             (((ushort)(local_e6 + 0xd7e0U) < 0x31 &&
              ((0x1000000000121U >> ((ulonglong)(ushort)(local_e6 + 0xd7e0U) & 0x3f) & 1) != 0)))) {
            uVar7 = 0x3fff;
            param_1[0xc] = 1;
            param_1[0xd] = 0;
          }
          if ((((((ushort)(local_e6 + 0xdbefU) < 0x3b) &&
                ((0x601000000000001U >> ((ulonglong)(ushort)(local_e6 + 0xdbefU) & 0x3f) & 1) != 0))
               || ((ushort)(local_e6 + 0xdb76U) < 2)) ||
              ((((ushort)(local_e6 + 0xdb3fU) < 0x1b &&
                ((0x4010601U >> ((ushort)(local_e6 + 0xdb3fU) & 0x1f) & 1) != 0)) ||
               (((ushort)(local_e6 + 0xda5eU) < 2 ||
                (((ushort)(local_e6 + 0xd9afU) < 3 || (local_e6 == 0x266f)))))))) ||
             ((((ushort)(local_e6 + 0xd840U) < 0x20 &&
               ((0x80000011U >> ((ushort)(local_e6 + 0xd840U) & 0x1f) & 1) != 0)) ||
              (((ushort)(local_e6 + 0xd7e0U) < 0x31 &&
               ((0x1000000000121U >> ((ulonglong)(ushort)(local_e6 + 0xd7e0U) & 0x3f) & 1) != 0)))))
             ) {
            memset(local_a8,0,0x56);
            iVar2 = PciIdeXGetBusData(param_1,local_a8,0,0x56);
            if (-1 < iVar2) {
              *(byte *)(param_1 + 10) = local_54 >> 4 & 1;
              *(byte *)((longlong)param_1 + 0x15) = local_54 >> 5 & 1;
              *(byte *)(param_1 + 0xb) = local_54 >> 6 & 1;
              uVar7 = uVar7 | 0xc000;
              *(byte *)((longlong)param_1 + 0x17) = local_54 >> 7;
            }
            param_1[0xc] = 2;
            param_1[0xd] = 0;
          }
          uVar8 = uVar7;
          if ((((((ushort)(local_e6 + 0xdbb6U) < 2) || ((ushort)(local_e6 + 0xdb76U) < 2)) ||
               (((ushort)(local_e6 + 0xdb3fU) < 0x1b &&
                ((0x4010601U >> ((ushort)(local_e6 + 0xdb3fU) & 0x1f) & 1) != 0)))) ||
              (((((ushort)(local_e6 + 0xda5eU) < 2 || ((ushort)(local_e6 + 0xd9afU) < 3)) ||
                (local_e6 == 0x266f)) ||
               (((ushort)(local_e6 + 0xd840U) < 0x20 &&
                ((0x80000011U >> ((ushort)(local_e6 + 0xd840U) & 0x1f) & 1) != 0)))))) ||
             (((ushort)(local_e6 + 0xd7e0U) < 0x31 &&
              ((0x1000000000121U >> ((ulonglong)(ushort)(local_e6 + 0xd7e0U) & 0x3f) & 1) != 0)))) {
            param_1[0xc] = 3;
            param_1[0xd] = 0;
            uVar8 = uVar7 | 0x10000;
            if (iVar2 < 0) {
              uVar8 = uVar7;
            }
          }
        }
        sVar1 = *param_1;
        if (((((ushort)(sVar1 + 0xd9afU) < 3) || (sVar1 == 0x266f)) ||
            (((ushort)(sVar1 + 0xd840U) < 0x20 &&
             ((0x80000011U >> ((ushort)(sVar1 + 0xd840U) & 0x1f) & 1) != 0)))) ||
           (((ushort)(sVar1 + 0xd7e0U) < 0x31 &&
            ((0x1000000000121U >> ((ulonglong)(ushort)(sVar1 + 0xd7e0U) & 0x3f) & 1) != 0)))) {
          local_f8[0] = 0;
          iVar2 = PciIdexGetBusLocation(param_1,local_f8);
          if (-1 < iVar2) {
            sVar1 = *param_1;
            if (((((ushort)(sVar1 + 0xd9afU) < 3) || (sVar1 == 0x266f)) ||
                (((ushort)(sVar1 + 0xd840U) < 0x20 &&
                 ((0x80000011U >> ((ushort)(sVar1 + 0xd840U) & 0x1f) & 1) != 0)))) &&
               (local_f8[0] == 0x1f0002)) {
              param_1[0xc] = 4;
              param_1[0xd] = 0;
            }
            if ((((ushort)(sVar1 + 0xd7e0U) < 0x31) &&
                ((0x1000000000121U >> ((ulonglong)(ushort)(sVar1 + 0xd7e0U) & 0x3f) & 1) != 0)) &&
               (local_f8[0] == 0x1f0005)) {
              param_1[0xc] = 4;
              param_1[0xd] = 0;
            }
          }
        }
        puVar4 = (uint *)(param_2 + 2);
        lVar6 = 2;
        do {
          lVar5 = 2;
          do {
            *(uint *)((longlong)param_1 + (-4 - (longlong)param_2) + (longlong)puVar4) = uVar8;
            *puVar4 = uVar8;
            puVar4 = puVar4 + 1;
            lVar5 = lVar5 + -1;
          } while (lVar5 != 0);
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
        param_2[0x10] = 1;
        *(code **)(param_2 + 6) = PiixIdeChannelEnabled;
        *(code **)(param_2 + 8) = PiixIdeSyncAccessRequired;
        *(code **)(param_2 + 0xe) = PiixIdeUseDma;
        *(code **)(param_2 + 0x12) = PiixIdeUdmaModesSupported;
        *(code **)(param_2 + 10) = PiixIdeTransferModeSelect;
        uVar3 = 0;
      }
      else {
        uVar3 = 0xc0000001;
      }
    }
  }
  else {
    uVar3 = 0xc0000059;
  }
  return uVar3;
}



===== PiixIdeSyncAccessRequired @ 140001630 =====

undefined1 PiixIdeSyncAccessRequired(void)

{
  return 0;
}



===== PiixIdeUseDma @ 140001640 =====

undefined8 PiixIdeUseDma(void)

{
  return 1;
}



===== PiixIdeTransferModeSelect @ 140001650 =====

ulonglong PiixIdeTransferModeSelect(short *param_1,uint *param_2)

{
  undefined8 *puVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  short *psVar5;
  ulonglong uVar6;
  short *psVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  byte local_res18 [8];
  byte local_res20 [8];
  byte *pbVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  byte local_58 [4];
  short local_54 [2];
  ushort local_50 [2];
  ushort local_4c [2];
  undefined8 local_48 [2];
  
  psVar5 = param_1 + 0xe;
  local_50[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  local_58[0] = 0;
  lVar10 = 2;
  local_4c[0] = 0;
  do {
    puVar8 = (undefined8 *)((longlong)param_2 + (0x68 - (longlong)param_1) + (longlong)psVar5);
    lVar11 = 4;
    psVar7 = psVar5;
    do {
      uVar13 = puVar8[1];
      *(undefined8 *)psVar7 = *puVar8;
      *(undefined8 *)(psVar7 + 4) = uVar13;
      uVar13 = puVar8[3];
      *(undefined8 *)(psVar7 + 8) = puVar8[2];
      *(undefined8 *)(psVar7 + 0xc) = uVar13;
      uVar13 = puVar8[5];
      *(undefined8 *)(psVar7 + 0x10) = puVar8[4];
      *(undefined8 *)(psVar7 + 0x14) = uVar13;
      uVar13 = puVar8[7];
      *(undefined8 *)(psVar7 + 0x18) = puVar8[6];
      *(undefined8 *)(psVar7 + 0x1c) = uVar13;
      uVar13 = puVar8[9];
      *(undefined8 *)(psVar7 + 0x20) = puVar8[8];
      *(undefined8 *)(psVar7 + 0x24) = uVar13;
      uVar13 = puVar8[0xb];
      *(undefined8 *)(psVar7 + 0x28) = puVar8[10];
      *(undefined8 *)(psVar7 + 0x2c) = uVar13;
      uVar13 = puVar8[0xd];
      *(undefined8 *)(psVar7 + 0x30) = puVar8[0xc];
      *(undefined8 *)(psVar7 + 0x34) = uVar13;
      puVar1 = puVar8 + 0xe;
      uVar13 = puVar8[0xf];
      puVar8 = puVar8 + 0x10;
      *(undefined8 *)(psVar7 + 0x38) = *puVar1;
      *(undefined8 *)(psVar7 + 0x3c) = uVar13;
      lVar11 = lVar11 + -1;
      psVar7 = psVar7 + 0x40;
    } while (lVar11 != 0);
    psVar5 = psVar5 + 0x100;
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  pbVar12 = local_res18;
  uVar6 = PiixIdepTransferModeSelect
                    (param_1,param_2,local_48,local_50,pbVar12,local_res20,local_58,local_4c);
  uVar9 = uVar6 & 0xffffffff;
  if (-1 < (int)uVar6) {
    uVar13 = CONCAT44((int)((ulonglong)pbVar12 >> 0x20),2);
    local_54[0] = -1;
    uVar4 = PciIdeXSetBusData(param_1,local_50,local_54,*param_2 * 2 + 0x40,uVar13);
    uVar14 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar9 = (ulonglong)uVar4;
    if (-1 < (int)uVar4) {
      if (*param_1 != 0x1230) {
        uVar13 = CONCAT44(uVar14,1);
        local_54[0] = (-(ushort)(*param_2 != 0) & 0xe1) + 0xf;
        uVar4 = PciIdeXSetBusData(param_1,local_res18,local_54,0x44,uVar13);
        uVar14 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar9 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) {
          return uVar9;
        }
      }
      sVar2 = *param_1;
      if (((((sVar2 == 0x7111) ||
            ((((ushort)(sVar2 + 0xdbefU) < 0x3b &&
              ((0x601000000010001U >> ((ulonglong)(ushort)(sVar2 + 0xdbefU) & 0x3f) & 1) != 0)) ||
             (sVar2 == 0x7601)))) || ((sVar2 == 0x7199 || ((ushort)(sVar2 + 0xdb76U) < 2)))) ||
          (((ushort)(sVar2 + 0xdb3fU) < 0x1b &&
           ((0x4010601U >> ((ushort)(sVar2 + 0xdb3fU) & 0x1f) & 1) != 0)))) ||
         (((((ushort)(sVar2 + 0xda5eU) < 2 || ((ushort)(sVar2 + 0xd9afU) < 3)) ||
           ((sVar2 == 0x266f ||
            (((ushort)(sVar2 + 0xd840U) < 0x20 &&
             ((0x80000011U >> ((ushort)(sVar2 + 0xd840U) & 0x1f) & 1) != 0)))))) ||
          (((ushort)(sVar2 + 0xd7e0U) < 0x31 &&
           ((0x1000000000121U >> ((ulonglong)(ushort)(sVar2 + 0xd7e0U) & 0x3f) & 1) != 0)))))) {
        uVar13 = CONCAT44(uVar14,1);
        local_54[0] = (-(ushort)(*param_2 != 0) & 9) + 3;
        uVar4 = PciIdeXSetBusData(param_1,local_res20,local_54,0x48,uVar13);
        if ((int)uVar4 < 0) {
          return (ulonglong)uVar4;
        }
        uVar13 = CONCAT44((int)((ulonglong)uVar13 >> 0x20),1);
        local_54[0] = 0xff;
        uVar4 = PciIdeXSetBusData(param_1,local_58,local_54,*param_2 + 0x4a,uVar13);
        uVar14 = (undefined4)((ulonglong)uVar13 >> 0x20);
        uVar9 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) {
          return uVar9;
        }
      }
      uVar3 = *param_1 + 0xdbef;
      if (((uVar3 < 0x3b) && ((0x601000000010001U >> ((ulonglong)uVar3 & 0x3f) & 1) != 0)) ||
         (*param_1 == 0x7601)) {
        local_54[0] = (-(ushort)(*param_2 != 0) & 9) + 0x403;
        uVar4 = PciIdeXSetBusData(param_1,local_4c,local_54,0x54,CONCAT44(uVar14,2));
        uVar9 = (ulonglong)uVar4;
      }
      if (-1 < (int)uVar9) {
        *(undefined8 *)(param_2 + 0x121) = local_48[0];
      }
    }
  }
  return uVar9;
}



===== PiixIdeUdmaModesSupported @ 1400019d0 =====

undefined8 PiixIdeUdmaModesSupported(longlong param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  
  if ((*(byte *)(param_1 + 0x6a) & 4) != 0) {
    bVar4 = (byte)*(undefined2 *)(param_1 + 0xb0);
    if (bVar4 != 0) {
      iVar3 = 0;
      uVar1 = (uint)bVar4;
      if (bVar4 != 0) {
        do {
          iVar3 = iVar3 + 1;
          uVar1 = uVar1 >> 1;
        } while (uVar1 != 0);
      }
      *param_2 = iVar3 + -1;
    }
    uVar1 = (uint)*(byte *)(param_1 + 0xb1);
    if (*(byte *)(param_1 + 0xb1) != 0) {
      iVar3 = 0;
      do {
        iVar2 = iVar3;
        uVar1 = uVar1 >> 1;
        iVar3 = iVar2 + 1;
      } while (uVar1 != 0);
      *param_3 = iVar2;
    }
  }
  return 0;
}



===== PiixIdepTransferModeSelect @ 140001a20 =====

undefined8
PiixIdepTransferModeSelect
          (short *param_1,uint *param_2,undefined8 *param_3,ushort *param_4,byte *param_5,
          byte *param_6,byte *param_7,ushort *param_8)

{
  uint uVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  ulonglong uVar5;
  byte bVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  ushort uVar14;
  uint uVar15;
  byte bVar16;
  uint uVar17;
  byte bVar18;
  longlong lVar19;
  ulonglong uVar20;
  longlong lVar21;
  byte local_res8;
  undefined2 local_res10;
  uint local_50 [4];
  
  uVar1 = *param_2;
  lVar2 = *(longlong *)(param_2 + 0x126);
  uVar9 = param_2[0x20];
  lVar19 = 0;
  local_res8 = 0;
  lVar21 = 2;
  do {
    uVar15 = 0;
    local_50[lVar19] = 0;
    if (*(char *)(lVar19 + 4 + (longlong)param_2) != '\0') {
      uVar17 = param_2[lVar19 + 4];
      iVar4 = *(int *)(param_1 + 0xc);
      uVar8 = uVar17 & 0x1ffff;
      uVar13 = uVar9;
      if (iVar4 == 1) {
        uVar8 = uVar17 & 0x3fff;
LAB_140001b3b:
        if ((*(char *)(lVar19 + (ulonglong)uVar1 * 2 + 0x14 + (longlong)param_1) == '\0') ||
           (uVar13 == 0)) {
          uVar8 = uVar8 & 0x3fff;
        }
      }
      else {
        if (iVar4 == 2) {
          uVar8 = uVar17 & 0xffff;
          goto LAB_140001b3b;
        }
        if ((iVar4 == 3) || (iVar4 == 4)) {
          uVar13 = 1;
        }
        else {
          uVar8 = uVar17 & 0x7ff;
        }
        if (iVar4 != 4) goto LAB_140001b3b;
      }
      iVar4 = 5;
      for (uVar8 = uVar8 >> 5; uVar8 != 0; uVar8 = uVar8 >> 1) {
        iVar4 = iVar4 + 1;
      }
      if (10 < iVar4 - 1U) {
        uVar15 = 1 << ((byte)(iVar4 - 1U) & 0x1f);
      }
      iVar4 = 5;
      for (uVar8 = uVar17 >> 5 & 0x3f; uVar8 != 0; uVar8 = uVar8 >> 1) {
        iVar4 = iVar4 + 1;
      }
      uVar8 = iVar4 - 1;
      if (uVar8 < 9) {
        if ((uVar8 == 7) && (param_2[lVar19 + 0xc] <= *(uint *)(lVar2 + 0x1c))) {
          uVar15 = uVar15 | 0x80;
        }
      }
      else {
        do {
          uVar5 = (ulonglong)uVar8;
          if (uVar8 == 8) {
            uVar5 = 7;
          }
          if (param_2[lVar19 + 0x10] <= *(uint *)(lVar2 + uVar5 * 4)) {
            uVar15 = uVar15 | 1 << ((byte)uVar5 & 0x1f);
            break;
          }
          uVar8 = (int)uVar5 - 1;
        } while (6 < uVar8);
      }
      uVar5 = 0;
      uVar17 = uVar17 >> 1 & 0xf;
      if (uVar17 == 0) {
LAB_140001bd8:
        uVar15 = uVar15 | 1;
      }
      else {
        do {
          uVar8 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar8;
          uVar17 = uVar17 >> 1;
        } while (uVar17 != 0);
        if (uVar8 != 2) {
          if (1 < uVar8) {
            do {
              if (param_2[lVar19 + 8] <= *(uint *)(lVar2 + uVar5 * 4)) {
                uVar15 = 1 << ((byte)uVar5 & 0x1f) | uVar15;
                local_50[lVar19] = uVar15;
                if (1 < (uint)uVar5) goto LAB_140001be0;
                break;
              }
              uVar17 = (uint)uVar5 - 1;
              uVar5 = (ulonglong)uVar17;
            } while (1 < uVar17);
          }
          goto LAB_140001bd8;
        }
        uVar15 = uVar15 | 4;
      }
      local_50[lVar19] = uVar15;
    }
LAB_140001be0:
    lVar19 = lVar19 + 1;
    lVar21 = lVar21 + -1;
  } while (lVar21 != 0);
  if (((*param_1 == 0x1230) && ((char)param_2[1] != '\0')) &&
     (*(char *)((longlong)param_2 + 5) != '\0')) {
    uVar9 = local_50[0] & 0x7ffff800;
    if ((local_50[1] & 0x7ffff800) < (local_50[0] & 0x7ffff800)) {
      uVar9 = local_50[1] & 0x7ffff800;
    }
    uVar15 = local_50[0] & 0x700;
    if ((local_50[1] & 0x700) < (local_50[0] & 0x700)) {
      uVar15 = local_50[1] & 0x700;
    }
    uVar17 = local_50[0] & 0xe0;
    if ((local_50[1] & 0xe0) < (local_50[0] & 0xe0)) {
      uVar17 = local_50[1] & 0xe0;
    }
    uVar8 = local_50[0] & 0x1f;
    if ((local_50[1] & 0x1f) < (local_50[0] & 0x1f)) {
      uVar8 = local_50[1] & 0x1f;
    }
    local_50[1] = uVar9 | uVar15 | uVar17 | uVar8;
    local_50[0] = local_50[1];
  }
  uVar10 = 0;
  local_res10._1_1_ = 0;
  puVar12 = local_50;
  local_res10._0_1_ = 0;
  puVar11 = param_2 + 3;
  uVar14 = 0x400;
  uVar5 = uVar10;
  do {
    uVar20 = 1;
    bVar3 = 0;
    bVar16 = 0;
    if ((char)puVar11[-2] == '\0') {
      uVar20 = uVar10;
    }
    else {
      uVar9 = *puVar12;
      bVar16 = bVar3;
      if ((uVar9 & 0x7fffffe0) == 0) {
        if ((uVar9 & 1) == 0) {
          if ((uVar9 & 4) == 0) {
            if ((uVar9 & 8) == 0) {
              if ((uVar9 & 0x10) != 0) {
                uVar20 = 4;
              }
            }
            else {
              uVar20 = 3;
            }
          }
          else {
            uVar20 = 2;
            bVar16 = -((char)*puVar11 != '\0') & 2;
          }
        }
      }
      else if ((char)(byte)uVar9 < '\0') {
        bVar3 = ((byte)uVar9 & 1) << 3;
        uVar20 = 2;
        bVar16 = bVar3 | 2;
        if ((char)*puVar11 == '\0') {
          bVar16 = bVar3;
        }
      }
      else if ((uVar9 >> 9 & 1) == 0) {
        if (((uVar9 & 0x400) != 0) && (uVar20 = 4 - (ulonglong)((uVar9 & 8) != 0), (uVar9 & 5) != 0)
           ) {
          bVar16 = 8;
        }
      }
      else {
        uVar20 = 3;
        bVar16 = -((uVar9 & 5) != 0) & 8;
      }
      if ((char)puVar11[-1] != '\0') {
        bVar16 = bVar16 | 4;
      }
    }
    bVar6 = (&PiixRecoveryTimeClockSetting)[uVar20] & 3;
    bVar3 = (&PiixIoReadySamplePointClockSetting)[uVar20];
    if ((int)uVar5 == 0) {
      local_res10._1_1_ = (bVar3 & 3) << 4 | bVar6;
      local_res10._0_1_ = (byte)local_res10 & 0xf0;
      bVar16 = bVar16 | (&PiixSpecialTiming)[uVar20] & 0xf;
    }
    else {
      if (uVar1 == 0) {
        local_res8 = (bVar3 & 3) << 2 | local_res8 & 0xf0 | bVar6;
      }
      else {
        local_res8 = (bVar3 << 2 | bVar6) << 4 | local_res8 & 0xf;
      }
      local_res10._0_1_ = (byte)local_res10 & 0xf;
      bVar16 = (bVar16 | (&PiixSpecialTiming)[uVar20]) << 4;
    }
    local_res10._0_1_ = (byte)local_res10 | bVar16;
    uVar9 = (int)uVar5 + 1;
    uVar5 = (ulonglong)uVar9;
    puVar11 = (uint *)((longlong)puVar11 + 1);
    puVar12 = puVar12 + 1;
  } while (uVar9 < 2);
  if (*param_1 == 0x1230) {
    local_res8 = 0;
  }
  else {
    local_res10._1_1_ = local_res10._1_1_ | 0x40;
  }
  puVar12 = local_50;
  local_res10 = CONCAT11(local_res10._1_1_,(byte)local_res10) | 0x8000;
  bVar3 = 0;
  bVar16 = 0;
  do {
    uVar9 = *puVar12;
    if ((uVar9 & 0x7ffff800) != 0) {
      uVar15 = uVar9 & 0x10000;
      if (uVar15 == 0) {
        if ((uVar9 & 0x8000) == 0) {
          if ((uVar9 & 0x4000) != 0) goto LAB_140001e96;
          if ((uVar9 & 0x2000) != 0) goto LAB_140001e7b;
          if (((uVar9 & 0x1000) != 0) || ((uVar9 >> 0xb & 1) == 0)) goto LAB_140001e96;
          bVar18 = 0;
          bVar6 = 0;
        }
        else {
LAB_140001e7b:
          bVar18 = 2;
          bVar6 = 0x20;
        }
      }
      else {
LAB_140001e96:
        bVar6 = 0x10;
        bVar18 = 1;
      }
      uVar17 = uVar9 & 0xc000;
      if ((int)uVar10 == 0) {
        if (uVar1 == 0) {
          bVar3 = bVar3 | 1;
          if (uVar17 != 0) {
            uVar14 = uVar14 | 1;
          }
          uVar7 = uVar14 | 0x1000;
          if (uVar15 == 0) {
            uVar7 = uVar14;
          }
          uVar14 = uVar7;
        }
        else {
          bVar3 = bVar3 | 4;
          if (uVar17 != 0) {
            uVar14 = uVar14 | 4;
          }
          if (uVar15 != 0) {
            uVar14 = uVar14 | 0x4000;
          }
        }
        bVar16 = bVar16 & 0xfc | bVar18;
      }
      else {
        if (uVar1 == 0) {
          bVar3 = bVar3 | 2;
          if (uVar17 != 0) {
            uVar14 = uVar14 | 2;
          }
          uVar7 = uVar14 | 0x2000;
          if (uVar15 == 0) {
            uVar7 = uVar14;
          }
          uVar14 = uVar7;
        }
        else {
          bVar3 = bVar3 | 8;
          if (uVar17 != 0) {
            uVar14 = uVar14 | 8;
          }
          if (uVar15 != 0) {
            uVar14 = uVar14 | 0x8000;
          }
        }
        bVar16 = bVar16 & 0xcf | bVar6;
      }
      *puVar12 = uVar9 & 0xfffff81f;
    }
    uVar9 = (int)uVar10 + 1;
    uVar10 = (ulonglong)uVar9;
    puVar12 = puVar12 + 1;
    if (1 < uVar9) {
      *param_3 = CONCAT44(local_50[1],local_50[0]);
      *param_4 = local_res10;
      *param_5 = local_res8;
      *param_6 = bVar3;
      *param_7 = bVar16;
      *param_8 = uVar14;
      return 0;
    }
  } while( true );
}



===== __GSHandlerCheck @ 140001fc8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001fec =====

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



===== __cpu_features_init @ 140002060 =====

/* WARNING: Removing unreachable block (ram,0x0001400020ca) */
/* WARNING: Removing unreachable block (ram,0x000140002079) */
/* WARNING: Removing unreachable block (ram,0x00014000206a) */

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



===== _guard_check_icall @ 140002130 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 140002150 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002190 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002190. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400021c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 140002240 =====

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



===== __memset_repmovs @ 140002380 =====

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



===== __memset_query @ 140002400 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140002480 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400025c0 =====

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



===== __memset_spec_plain @ 140002640 =====

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



===== entry @ 140008010 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140008044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  byte *pbVar4;
  char *pcVar5;
  char in_DL;
  byte in_DH;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar2 = (code *)swi(0x29);
    pbVar4 = (byte *)(*pcVar2)(6);
    bVar3 = (byte)pbVar4;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3;
    bVar1 = *pbVar4;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + in_DL + CARRY1(bVar1,bVar3);
    bVar1 = *pbVar4;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3 + CARRY1(bVar1,bVar3);
    pcVar5 = (char *)CONCAT71((int7)((ulonglong)pbVar4 >> 8),bVar3 + in_DH);
    *pcVar5 = *pcVar5 + bVar3 + in_DH + CARRY1(bVar3,in_DH);
    *pcVar5 = *pcVar5 + in_DH;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


