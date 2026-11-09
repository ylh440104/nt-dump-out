
===== _tlgCreate1Sz_char @ 180001008 =====

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



===== _tlgKeywordOn @ 18000103c =====

undefined1 _tlgKeywordOn(longlong param_1,ulonglong param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if ((param_2 == 0) ||
     (((*(ulonglong *)(param_1 + 0x10) & param_2) != 0 &&
      ((*(ulonglong *)(param_1 + 0x18) & param_2) == *(ulonglong *)(param_1 + 0x18))))) {
    uVar1 = 1;
  }
  return uVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 180001068 =====

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
  *param_6 = PTR_DAT_18000f048;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_18000f048;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_18000f060,&local_18,0,0,param_5,param_6);
  return;
}



===== HidP_SysPowerEvent @ 180001120 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int HidP_SysPowerEvent(char *param_1,short param_2,int *param_3,uint *param_4)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  ulonglong uVar4;
  undefined1 auStackY_a8 [32];
  uint local_68 [4];
  short local_58 [32];
  ulonglong local_18;
  
                    /* 0x1120  30  HidP_SysPowerEvent */
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68[0] = 0x20;
  *param_4 = 0;
  if (param_3[3] == 0) {
    iVar2 = -0x3fffff45;
  }
  else {
    iVar2 = HidP_GetUsages(0,1,0,local_58,local_68,param_3,param_1,param_2);
    if ((-1 < iVar2) && (uVar4 = (ulonglong)local_68[0], local_68[0] != 0)) {
      psVar3 = local_58;
      do {
        sVar1 = *psVar3;
        if (sVar1 == 0x81) {
          *param_4 = *param_4 | 1;
        }
        else if (sVar1 == 0x82) {
          *param_4 = *param_4 | 2;
        }
        else if (sVar1 == 0x83) {
          *param_4 = *param_4 | 0x80000000;
        }
        psVar3 = psVar3 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
  }
  return iVar2;
}



===== HidP_GetUsagesEx @ 180001200 =====

void HidP_GetUsagesEx(int param_1,short param_2,void *param_3,uint *param_4,int *param_5,
                     char *param_6,short param_7)

{
                    /* 0x1200  18  HidP_GetUsagesEx */
  HidP_GetUsages(param_1,0,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



===== HidP_GetUsages @ 180001250 =====

undefined4
HidP_GetUsages(int param_1,short param_2,short param_3,void *param_4,uint *param_5,int *param_6,
              char *param_7,short param_8)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  short sVar7;
  uint uVar8;
  byte bVar9;
  ushort uVar10;
  longlong lVar11;
  ushort uVar12;
  ulonglong uVar13;
  int *piVar14;
  ushort uVar15;
  uint uVar16;
  int *piVar17;
  ushort uVar18;
  ulonglong uVar19;
  ushort local_46;
  
                    /* 0x1250  17  HidP_GetUsages */
  bVar2 = false;
  bVar1 = false;
  uVar19 = 0;
  uVar8 = 0;
  if (((param_6 == (int *)0x0) || (*param_6 != 0x50646948)) || (param_6[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  memset(param_4,0,(ulonglong)*param_5 * 2);
  if (param_1 == 0) {
    lVar11 = 0x10;
  }
  else if (param_1 == 1) {
    lVar11 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar11 = 0x20;
  }
  sVar7 = *(short *)(lVar11 + 6 + (longlong)param_6);
  if (param_8 == sVar7) {
    if (sVar7 == 0) {
      uVar5 = 0xc0110010;
    }
    else {
      local_46 = *(ushort *)(lVar11 + (longlong)param_6);
      bVar3 = false;
      bVar4 = false;
      if (local_46 < *(ushort *)(lVar11 + 4 + (longlong)param_6)) {
        do {
          bVar2 = bVar4;
          bVar1 = bVar3;
          piVar17 = param_6 + (ulonglong)local_46 * 0x1a + 0xb;
          if ((((piVar17[6] & 4U) != 0) && ((param_2 == 0 || ((short)*piVar17 == param_2)))) &&
             ((param_3 == 0 ||
              ((param_3 == *(short *)((longlong)piVar17 + 0x12) ||
               ((param_3 == -1 && (*(short *)((longlong)piVar17 + 0x12) == 0)))))))) {
            if ((*param_7 == '\0') || (*(char *)((longlong)piVar17 + 2) == *param_7)) {
              bVar9 = *(byte *)((longlong)piVar17 + 3);
              uVar18 = (ushort)bVar9;
              uVar10 = *(ushort *)(piVar17 + 1);
              uVar8 = (uint)*(ushort *)((longlong)piVar17 + 10) + (uint)bVar9;
              bVar1 = true;
              if (uVar10 == 1) {
                if (bVar9 < uVar8) {
                  uVar13 = uVar19;
                  uVar10 = uVar18;
                  do {
                    uVar12 = (short)piVar17[2] * 8 + uVar18;
                    uVar19 = uVar13;
                    if (((ushort)(short)param_7[uVar12 >> 3] >> (uVar12 & 7) & 1) != 0) {
                      sVar7 = (short)piVar17[0xf];
                      if ((piVar17[6] & 0x10U) != 0) {
                        sVar7 = (sVar7 - uVar10) + uVar18;
                      }
                      if ((uint)uVar13 < *param_5) {
                        if (param_2 == 0) {
                          uVar19 = (ulonglong)(ushort)((short)uVar13 + 1);
                          *(short *)((longlong)param_4 + uVar13 * 4 + 2) = (short)*piVar17;
                          *(short *)((longlong)param_4 + uVar13 * 4) = sVar7;
                          goto LAB_180001447;
                        }
                        *(short *)((longlong)param_4 + uVar13 * 2) = sVar7;
                      }
                      uVar19 = (ulonglong)(ushort)((short)uVar13 + 1);
                    }
LAB_180001447:
                    uVar10 = (ushort)*(byte *)((longlong)piVar17 + 3);
                    uVar18 = uVar18 + 1;
                    uVar13 = uVar19;
                  } while ((uint)uVar18 <
                           (uint)*(ushort *)((longlong)piVar17 + 10) +
                           (uint)*(byte *)((longlong)piVar17 + 3));
                }
              }
              else {
                if (bVar9 < uVar8) {
                  do {
                    uVar8 = 0;
                    uVar12 = ((uVar18 >> 3) + (short)piVar17[2]) * 8 + uVar10 + (uVar18 & 7);
                    uVar15 = uVar12 >> 3;
                    uVar12 = uVar12 & 7;
                    if (uVar10 < uVar12) {
                      uVar8 = ((1 << (sbyte)uVar12) - 1U & (uint)(byte)param_7[uVar15]) >>
                              (sbyte)(uVar18 & 7);
                    }
                    else {
                      if (uVar12 != 0) {
                        uVar8 = (1 << (sbyte)uVar12) - 1U & (uint)(byte)param_7[uVar15];
                        uVar10 = uVar10 - uVar12;
                      }
                      uVar15 = uVar15 - 1;
                      if (7 < uVar10) {
                        uVar13 = (ulonglong)(uVar10 >> 3);
                        do {
                          uVar6 = (ulonglong)uVar15;
                          uVar10 = uVar10 - 8;
                          uVar15 = uVar15 - 1;
                          uVar8 = uVar8 << 8 | (uint)(byte)param_7[uVar6];
                          uVar13 = uVar13 - 1;
                        } while (uVar13 != 0);
                      }
                      if (uVar10 != 0) {
                        bVar9 = (byte)uVar10;
                        uVar8 = (uint)(byte)((byte)param_7[uVar15] >> (8 - bVar9 & 0x1f) &
                                            ('\x01' << (bVar9 & 0x1f)) - 1U) |
                                uVar8 << (bVar9 & 0x1f);
                      }
                    }
                    if (uVar8 != 0) {
                      uVar16 = piVar17[6];
                      piVar14 = piVar17;
                      while ((uVar16 & 1) != 0) {
                        uVar16 = piVar14[0x20];
                        piVar14 = piVar14 + 0x1a;
                      }
                      while (uVar8 != 0) {
                        if ((piVar14[6] & 0x10U) == 0) {
                          if (uVar8 == 1) {
                            sVar7 = (short)piVar14[0xf];
                            goto LAB_180001694;
                          }
                          uVar8 = uVar8 - 1;
                        }
                        else {
                          sVar7 = (short)piVar14[0xf];
                          if (sVar7 == 0) {
                            sVar7 = 1;
                          }
                          uVar16 = (uint)(ushort)((*(short *)((longlong)piVar14 + 0x3e) - sVar7) + 1
                                                 );
                          if (uVar8 <= uVar16) {
                            sVar7 = (short)uVar8 + sVar7 + -1;
LAB_180001694:
                            uVar5 = CONCAT22((short)*piVar14,sVar7);
                            goto LAB_1800016a7;
                          }
                          uVar8 = uVar8 - uVar16;
                        }
                        if (piVar17 == piVar14) break;
                        piVar14 = piVar14 + -0x1a;
                      }
                      uVar5 = 0;
LAB_1800016a7:
                      if ((short)uVar5 != 0) {
                        if ((uint)uVar19 < *param_5) {
                          if (param_2 == 0) {
                            *(undefined4 *)((longlong)param_4 + uVar19 * 4) = uVar5;
                          }
                          else {
                            *(short *)((longlong)param_4 + uVar19 * 2) = (short)uVar5;
                          }
                        }
                        uVar19 = (ulonglong)(ushort)((short)uVar19 + 1);
                      }
                    }
                    uVar10 = *(ushort *)(piVar17 + 1);
                    uVar18 = uVar18 + uVar10;
                  } while ((uint)uVar18 <
                           (uint)*(ushort *)((longlong)piVar17 + 10) +
                           (uint)*(byte *)((longlong)piVar17 + 3));
                }
                uVar13 = (ulonglong)local_46;
                uVar8 = piVar17[6];
                while ((uVar8 & 1) != 0) {
                  local_46 = (short)uVar13 + 1;
                  uVar13 = (ulonglong)local_46;
                  uVar8 = param_6[uVar13 * 0x1a + 0x11];
                }
              }
            }
            else {
              bVar2 = true;
            }
          }
          uVar8 = (uint)uVar19;
          local_46 = local_46 + 1;
          bVar3 = bVar1;
          bVar4 = bVar2;
        } while (local_46 < *(ushort *)(lVar11 + 4 + (longlong)param_6));
      }
      uVar16 = *param_5;
      *param_5 = uVar8;
      uVar5 = 0xc0110007;
      if (uVar8 <= uVar16) {
        uVar5 = 0x110000;
      }
      if ((!bVar1) && (uVar5 = 0xc0110004, bVar2)) {
        uVar5 = 0xc011000a;
      }
    }
  }
  else {
    uVar5 = 0xc0110003;
  }
  return uVar5;
}



===== HidP_GetUsageValue @ 1800017d0 =====

undefined8
HidP_GetUsageValue(int param_1,short param_2,short param_3,ushort param_4,uint *param_5,int *param_6
                  ,char *param_7,short param_8)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  ushort uVar6;
  ulonglong uVar7;
  short sVar8;
  ushort uVar9;
  ushort uVar10;
  byte bVar11;
  ushort uVar12;
  uint uVar13;
  
                    /* 0x17d0  15  HidP_GetUsageValue */
  bVar1 = false;
  if (((param_6 == (int *)0x0) || (*param_6 != 0x50646948)) || (param_6[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  if (param_1 == 0) {
    lVar5 = 0x10;
  }
  else if (param_1 == 1) {
    lVar5 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar5 = 0x20;
  }
  sVar8 = *(short *)(lVar5 + 6 + (longlong)param_6);
  if (param_8 != sVar8) {
    return 0xc0110003;
  }
  uVar13 = 0;
  if (sVar8 == 0) {
    return 0xc0110010;
  }
  uVar2 = (uint)*(ushort *)(lVar5 + (longlong)param_6);
  do {
    if (*(ushort *)(lVar5 + 4 + (longlong)param_6) <= uVar2) {
      uVar4 = 0xc0110004;
      if (bVar1) {
        uVar4 = 0xc011000a;
      }
      return uVar4;
    }
    if ((((param_6[(ulonglong)uVar2 * 0x1a + 0x11] & 4U) == 0) &&
        ((short)param_6[(ulonglong)uVar2 * 0x1a + 0xb] == param_2)) &&
       (((param_3 == 0 ||
         (sVar8 = *(short *)((longlong)param_6 + (ulonglong)uVar2 * 0x68 + 0x3e), param_3 == sVar8))
        || ((param_3 == -1 && (sVar8 == 0)))))) {
      uVar12 = *(ushort *)(param_6 + (ulonglong)uVar2 * 0x1a + 0x1a);
      if ((param_6[(ulonglong)uVar2 * 0x1a + 0x11] & 0x10U) == 0) {
        if (uVar12 == param_4) {
          sVar8 = (ushort)*(byte *)((longlong)param_6 + (ulonglong)uVar2 * 0x68 + 0x2f) +
                  (short)param_6[(ulonglong)uVar2 * 0x1a + 0xd] * 8;
          goto LAB_1800018b7;
        }
      }
      else if ((uVar12 <= param_4) &&
              (param_4 <= *(ushort *)((longlong)param_6 + (ulonglong)uVar2 * 0x68 + 0x6a))) {
        sVar8 = (param_4 - uVar12) * (short)param_6[(ulonglong)uVar2 * 0x1a + 0xc] +
                (short)param_6[(ulonglong)uVar2 * 0x1a + 0xd] * 8 +
                (ushort)*(byte *)((longlong)param_6 + (ulonglong)uVar2 * 0x68 + 0x2f);
LAB_1800018b7:
        if ((*param_7 == '\0') ||
           (*(char *)((longlong)param_6 + (ulonglong)uVar2 * 0x68 + 0x2e) == *param_7)) {
          uVar12 = *(ushort *)(param_6 + (ulonglong)uVar2 * 0x1a + 0xc);
          uVar9 = uVar12 + sVar8;
          uVar10 = uVar9 >> 3;
          uVar6 = uVar9 & 7;
          if (uVar12 < uVar6) {
            uVar13 = ((1 << (sbyte)uVar6) - 1U & (uint)(byte)param_7[uVar10]) >> ((byte)sVar8 & 7);
          }
          else {
            if ((uVar9 & 7) != 0) {
              uVar13 = (1 << (sbyte)uVar6) - 1U & (uint)(byte)param_7[uVar10];
              uVar12 = uVar12 - uVar6;
            }
            uVar10 = uVar10 - 1;
            if (7 < uVar12) {
              uVar7 = (ulonglong)(uVar12 >> 3);
              do {
                uVar3 = (ulonglong)uVar10;
                uVar12 = uVar12 - 8;
                uVar10 = uVar10 - 1;
                uVar13 = uVar13 << 8 | (uint)(byte)param_7[uVar3];
                uVar7 = uVar7 - 1;
              } while (uVar7 != 0);
            }
            if (uVar12 != 0) {
              bVar11 = (byte)uVar12;
              uVar13 = (uint)(byte)((byte)param_7[uVar10] >> (8 - bVar11 & 0x1f) &
                                   ('\x01' << (bVar11 & 0x1f)) - 1U) | uVar13 << (bVar11 & 0x1f);
            }
          }
          *param_5 = uVar13;
          return 0x110000;
        }
        bVar1 = true;
      }
    }
    uVar2 = uVar2 + 1;
  } while( true );
}



===== HidP_GetScaledUsageValue @ 180001ab0 =====

undefined8
HidP_GetScaledUsageValue
          (int param_1,short param_2,short param_3,ushort param_4,uint *param_5,int *param_6,
          char *param_7,short param_8)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  longlong lVar10;
  ushort uVar11;
  ulonglong uVar12;
  byte bVar13;
  ushort uVar14;
  longlong lVar15;
  ushort uVar16;
  ushort uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  short sVar21;
  
                    /* 0x1ab0  12  HidP_GetScaledUsageValue */
  bVar6 = false;
  if (((param_6 == (int *)0x0) || (*param_6 != 0x50646948)) || (param_6[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  if (param_1 == 0) {
    lVar10 = 0x10;
  }
  else if (param_1 == 1) {
    lVar10 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar10 = 0x20;
  }
  sVar21 = *(short *)(lVar10 + 6 + (longlong)param_6);
  if (param_8 != sVar21) {
    return 0xc0110003;
  }
  if (sVar21 == 0) {
    return 0xc0110010;
  }
  uVar20 = (uint)*(ushort *)(lVar10 + (longlong)param_6);
  do {
    if (*(ushort *)(lVar10 + 4 + (longlong)param_6) <= uVar20) {
      uVar9 = 0xc0110004;
      if (bVar6) {
        uVar9 = 0xc011000a;
      }
      return uVar9;
    }
    uVar7 = (ulonglong)uVar20;
    lVar15 = uVar7 * 0x68;
    if ((((param_6[uVar7 * 0x1a + 0x11] & 4U) == 0) &&
        ((short)param_6[uVar7 * 0x1a + 0xb] == param_2)) &&
       (((param_3 == 0 ||
         (sVar21 = *(short *)(lVar15 + 0x3e + (longlong)param_6), param_3 == sVar21)) ||
        ((param_3 == -1 && (sVar21 == 0)))))) {
      uVar1 = *(ushort *)(param_6 + uVar7 * 0x1a + 0x1a);
      if ((param_6[uVar7 * 0x1a + 0x11] & 0x10U) == 0) {
        if (uVar1 == param_4) {
          sVar21 = (ushort)*(byte *)(lVar15 + 0x2f + (longlong)param_6) +
                   (short)param_6[uVar7 * 0x1a + 0xd] * 8;
          goto LAB_180001b93;
        }
      }
      else if ((uVar1 <= param_4) && (param_4 <= *(ushort *)(lVar15 + 0x6a + (longlong)param_6))) {
        sVar21 = (param_4 - uVar1) * (short)param_6[uVar7 * 0x1a + 0xc] +
                 (short)param_6[uVar7 * 0x1a + 0xd] * 8 +
                 (ushort)*(byte *)(lVar15 + 0x2f + (longlong)param_6);
LAB_180001b93:
        if ((*param_7 == '\0') || (*(char *)(lVar15 + 0x2e + (longlong)param_6) == *param_7)) {
          iVar2 = param_6[uVar7 * 0x1a + 0x21];
          uVar20 = 0;
          iVar3 = param_6[uVar7 * 0x1a + 0x1f];
          iVar4 = param_6[uVar7 * 0x1a + 0x20];
          iVar5 = param_6[uVar7 * 0x1a + 0x22];
          uVar1 = *(ushort *)(param_6 + uVar7 * 0x1a + 0xc);
          uVar16 = uVar1 + sVar21;
          uVar17 = uVar16 >> 3;
          uVar11 = uVar16 & 7;
          if (uVar1 < uVar11) {
            uVar20 = ((1 << (sbyte)uVar11) - 1U & (uint)(byte)param_7[uVar17]) >> ((byte)sVar21 & 7)
            ;
          }
          else {
            uVar14 = uVar1;
            if ((uVar16 & 7) != 0) {
              uVar20 = (1 << (sbyte)uVar11) - 1U & (uint)(byte)param_7[uVar17];
              uVar14 = uVar1 - uVar11;
            }
            uVar17 = uVar17 - 1;
            if (7 < uVar14) {
              uVar12 = (ulonglong)(uVar14 >> 3);
              do {
                uVar8 = (ulonglong)uVar17;
                uVar14 = uVar14 - 8;
                uVar17 = uVar17 - 1;
                uVar20 = uVar20 << 8 | (uint)(byte)param_7[uVar8];
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
            }
            if (uVar14 != 0) {
              bVar13 = (byte)uVar14;
              uVar20 = (uint)(byte)((byte)param_7[uVar17] >> (8 - bVar13 & 0x1f) &
                                   ('\x01' << (bVar13 & 0x1f)) - 1U) | uVar20 << (bVar13 & 0x1f);
            }
          }
          uVar18 = 1 << ((char)uVar1 - 1U & 0x1f);
          uVar19 = -uVar18;
          if ((uVar20 & uVar18) == 0) {
            uVar19 = 0;
          }
          uVar19 = uVar19 | uVar20;
          if ((iVar2 == 0) && (iVar5 == 0)) {
            if (iVar4 != iVar3) {
              uVar20 = uVar19;
              goto LAB_180001cbf;
            }
          }
          else if ((iVar3 < iVar4) && (iVar2 < iVar5)) {
            uVar20 = (int)(((longlong)(iVar5 - iVar2) * (longlong)(int)(uVar19 - iVar3)) /
                          (longlong)(iVar4 - iVar3)) + iVar2;
LAB_180001cbf:
            *param_5 = uVar20;
            if ((iVar3 <= (int)uVar19) && ((int)uVar19 <= iVar4)) {
              return 0x110000;
            }
            *param_5 = 0;
            if ((char)param_6[uVar7 * 0x1a + 0x1e] == '\0') {
              return 0xc0110005;
            }
            return 0x80110001;
          }
          *param_5 = 0;
          return 0xc0110006;
        }
        bVar6 = true;
      }
    }
    uVar20 = uVar20 + 1;
  } while( true );
}



===== HidP_GetUsageValueArray @ 180001e80 =====

undefined8
HidP_GetUsageValueArray
          (int param_1,short param_2,short param_3,ushort param_4,undefined1 *param_5,ushort param_6
          ,int *param_7,char *param_8,short param_9)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  longlong lVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
                    /* 0x1e80  16  HidP_GetUsageValueArray */
  bVar3 = false;
  if (((param_7 == (int *)0x0) || (*param_7 != 0x50646948)) || (param_7[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  if (param_1 == 0) {
    lVar7 = 0x10;
  }
  else if (param_1 == 1) {
    lVar7 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar7 = 0x20;
  }
  sVar1 = *(short *)(lVar7 + 6 + (longlong)param_7);
  if (param_9 == sVar1) {
    if (sVar1 == 0) {
      uVar6 = 0xc0110010;
    }
    else {
      for (uVar4 = (uint)*(ushort *)(lVar7 + (longlong)param_7);
          uVar4 < *(ushort *)(lVar7 + 4 + (longlong)param_7); uVar4 = uVar4 + 1) {
        if ((((param_7[(ulonglong)uVar4 * 0x1a + 0x11] & 4U) == 0) &&
            ((short)param_7[(ulonglong)uVar4 * 0x1a + 0xb] == param_2)) &&
           (((param_3 == 0 ||
             (sVar1 = *(short *)((longlong)param_7 + (ulonglong)uVar4 * 0x68 + 0x3e),
             param_3 == sVar1)) || ((param_3 == -1 && (sVar1 == 0)))))) {
          if ((param_7[(ulonglong)uVar4 * 0x1a + 0x11] & 0x10U) == 0) {
            if (*(ushort *)(param_7 + (ulonglong)uVar4 * 0x1a + 0x1a) == param_4) {
              uVar2 = *(ushort *)((longlong)param_7 + (ulonglong)uVar4 * 0x68 + 0x32);
              if (uVar2 == 1) {
                return 0xc011000b;
              }
              uVar11 = (uint)*(byte *)((longlong)param_7 + (ulonglong)uVar4 * 0x68 + 0x2f) +
                       (uint)*(ushort *)(param_7 + (ulonglong)uVar4 * 0x1a + 0xd) * 8;
              if ((*param_8 == '\0') ||
                 (*(char *)((longlong)param_7 + (ulonglong)uVar4 * 0x68 + 0x2e) == *param_8)) {
                uVar8 = *(ushort *)(param_7 + (ulonglong)uVar4 * 0x1a + 0xc);
                if ((int)((uint)param_6 * 8) < (int)((uint)uVar8 * (uint)uVar2)) {
                  return 0xc0110007;
                }
                if ((uVar8 & 7) != 0) {
                  return 0xc0110020;
                }
                if ((uVar11 & 7) == 0) {
                  memmove(param_5,param_8 + (uVar11 >> 3),
                          (ulonglong)((uint)uVar2 * (uint)(uVar8 >> 3)));
                }
                else {
                  uVar10 = 0;
                  if (uVar2 != 0) {
                    do {
                      uVar9 = 0;
                      if ((uVar8 & 0xfff8) != 0) {
                        do {
                          uVar5 = HidP_ExtractData((short)(uVar11 >> 3),(ushort)uVar11 & 7,8,
                                                   (longlong)param_8);
                          *param_5 = (char)uVar5;
                          uVar11 = uVar11 + 8;
                          uVar8 = *(ushort *)(param_7 + (ulonglong)uVar4 * 0x1a + 0xc);
                          param_5 = param_5 + 1;
                          uVar9 = uVar9 + 1;
                        } while (uVar9 < uVar8 >> 3);
                      }
                      uVar10 = uVar10 + 1;
                    } while (uVar10 < *(ushort *)
                                       ((longlong)param_7 + (ulonglong)uVar4 * 0x68 + 0x32));
                  }
                }
                return 0x110000;
              }
              bVar3 = true;
            }
          }
          else if ((*(ushort *)(param_7 + (ulonglong)uVar4 * 0x1a + 0x1a) <= param_4) &&
                  (param_4 <= *(ushort *)((longlong)param_7 + (ulonglong)uVar4 * 0x68 + 0x6a))) {
            return 0xc011000b;
          }
        }
      }
      uVar6 = 0xc0110004;
      if (bVar3) {
        uVar6 = 0xc011000a;
      }
    }
  }
  else {
    uVar6 = 0xc0110003;
  }
  return uVar6;
}



===== HidP_UnsetUsages @ 180002140 =====

ulonglong HidP_UnsetUsages(int param_1,ushort param_2,ushort param_3,longlong param_4,uint *param_5,
                          int *param_6,char *param_7,uint param_8)

{
  short sVar1;
  ushort uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  
                    /* 0x2140  33  HidP_UnsetUsages */
  uVar6 = 0x110000;
  if (((param_6 == (int *)0x0) || (*param_6 != 0x50646948)) || (param_6[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  if (param_1 == 0) {
    lVar3 = 0x10;
  }
  else if (param_1 == 1) {
    lVar3 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar3 = 0x20;
  }
  sVar1 = *(short *)(lVar3 + 6 + (longlong)param_6);
  if ((short)param_8 == sVar1) {
    if (sVar1 == 0) {
      uVar6 = 0xc0110010;
    }
    else {
      uVar4 = 0;
      uVar5 = 0;
      if (*param_5 != 0) {
        do {
          uVar5 = (uint)uVar4;
          uVar2 = *(ushort *)(param_4 + uVar4 * 2);
          if (uVar2 != 0) {
            uVar4 = HidP_SetUnsetOneUsage
                              ((ushort *)(lVar3 + (longlong)param_6),param_2,param_3,uVar2,
                               (longlong)param_6,param_7,param_8,'\0');
            uVar6 = uVar4 & 0xffffffff;
            if ((int)uVar4 < 0) break;
          }
          uVar5 = uVar5 + 1;
          uVar4 = (ulonglong)uVar5;
        } while (uVar5 < *param_5);
      }
      *param_5 = uVar5;
    }
  }
  else {
    uVar6 = 0xc0110003;
  }
  return uVar6;
}



===== HidP_SetUsages @ 1800022b0 =====

ulonglong HidP_SetUsages(int param_1,ushort param_2,ushort param_3,longlong param_4,uint *param_5,
                        int *param_6,char *param_7,uint param_8)

{
  short sVar1;
  ushort uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  
                    /* 0x22b0  28  HidP_SetUsages */
  uVar6 = 0x110000;
  if (((param_6 == (int *)0x0) || (*param_6 != 0x50646948)) || (param_6[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  if (param_1 == 0) {
    lVar3 = 0x10;
  }
  else if (param_1 == 1) {
    lVar3 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar3 = 0x20;
  }
  sVar1 = *(short *)(lVar3 + 6 + (longlong)param_6);
  if ((short)param_8 == sVar1) {
    if (sVar1 == 0) {
      uVar6 = 0xc0110010;
    }
    else {
      uVar4 = 0;
      uVar5 = 0;
      if (*param_5 != 0) {
        do {
          uVar5 = (uint)uVar4;
          uVar2 = *(ushort *)(param_4 + uVar4 * 2);
          if (uVar2 != 0) {
            uVar4 = HidP_SetUnsetOneUsage
                              ((ushort *)(lVar3 + (longlong)param_6),param_2,param_3,uVar2,
                               (longlong)param_6,param_7,param_8,'\x01');
            uVar6 = uVar4 & 0xffffffff;
            if ((int)uVar4 < 0) break;
          }
          uVar5 = uVar5 + 1;
          uVar4 = (ulonglong)uVar5;
        } while (uVar5 < *param_5);
      }
      *param_5 = uVar5;
    }
  }
  else {
    uVar6 = 0xc0110003;
  }
  return uVar6;
}



===== HidP_SetUnsetOneUsage @ 180002420 =====

undefined8
HidP_SetUnsetOneUsage
          (ushort *param_1,ushort param_2,ushort param_3,ushort param_4,longlong param_5,
          char *param_6,uint param_7,char param_8)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  undefined8 uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  uint uVar10;
  ushort *puVar11;
  ushort uVar12;
  ushort *puVar13;
  uint local_54;
  ushort *local_48;
  
  local_48 = (ushort *)0x0;
  bVar1 = false;
  bVar3 = false;
  bVar2 = false;
  local_54 = 0;
  if (param_7 == 0) {
    return 0xc0110003;
  }
  uVar5 = (uint)*param_1;
  puVar13 = (ushort *)0x0;
  do {
    while( true ) {
      if (param_1[2] <= uVar5) {
        if (bVar1) {
          return 0xc011000a;
        }
        if (!bVar2) {
          if (!bVar3) {
            return 0xc0110004;
          }
          return 0xc0110007;
        }
        return 0xc011000f;
      }
      puVar11 = (ushort *)((ulonglong)uVar5 * 0x68 + 0x2c + param_5);
      if ((puVar13 == (ushort *)0x0) || ((*(uint *)(puVar13 + 0xc) & 1) == 0)) {
        local_48 = puVar11;
      }
      if ((((*(uint *)(puVar11 + 0xc) & 4) != 0) && (*puVar11 == param_2)) &&
         (((param_3 == 0 || (param_3 == puVar11[9])) || ((param_3 == 0xffff && (puVar11[9] == 0)))))
         ) break;
LAB_18000259d:
      uVar5 = uVar5 + 1;
      puVar13 = puVar11;
    }
    if ((*(uint *)(puVar11 + 0xc) & 0x10) == 0) {
      if (puVar11[0x1e] == param_4) goto LAB_18000250c;
      goto LAB_18000259d;
    }
    if ((param_4 < puVar11[0x1e]) || (puVar11[0x1f] < param_4)) goto LAB_18000259d;
LAB_18000250c:
    if ((*param_6 == '\0') || ((char)puVar11[1] == *param_6)) {
      *param_6 = (char)puVar11[1];
      uVar7 = puVar11[2];
      if (uVar7 == 1) {
        uVar7 = (((ushort)*(byte *)((longlong)puVar11 + 3) + puVar11[4] * 8) - puVar11[0x1e]) +
                param_4;
        uVar5 = (uint)(uVar7 >> 3);
        if (param_7 <= uVar5) {
          return 0xc0110003;
        }
        uVar10 = uVar7 & 7;
        bVar4 = param_6[uVar5];
        if (param_8 == '\0') {
          if (((uint)(int)(char)bVar4 >> uVar10 & 1) == 0) {
            return 0xc011000f;
          }
          bVar4 = bVar4 & ~(byte)(1 << uVar10);
        }
        else {
          bVar4 = bVar4 | (byte)(1 << uVar10);
        }
        param_6[uVar5] = bVar4;
        return 0x110000;
      }
      if (param_8 == '\0') {
        uVar10 = HidP_Usage2Index(local_48,param_4);
        uVar9 = (short)local_54 + puVar11[4] * 8;
        local_54 = (uint)uVar9;
        uVar6 = HidP_DeleteArrayEntry((uint)uVar9,uVar7,puVar11[3],uVar10,(longlong)param_6,param_7)
        ;
        if ((int)uVar6 == -0x3feefff1) {
          bVar2 = true;
        }
        else if (-1 < (int)uVar6) {
          return uVar6;
        }
      }
      else {
        bVar4 = *(byte *)((longlong)puVar11 + 3);
        uVar9 = puVar11[5];
        local_54 = (uint)bVar4;
        while (uVar8 = (ushort)local_54, local_54 < (uint)uVar9 + (uint)bVar4) {
          uVar12 = (uVar8 >> 3) + puVar11[4];
          uVar10 = HidP_ExtractData(uVar12,uVar8 & 7,uVar7,(longlong)param_6);
          if (uVar10 == 0) {
            uVar5 = HidP_Usage2Index(local_48,param_4);
            if (uVar5 == 0) {
              return 0xc0110008;
            }
            HidP_InsertData(uVar12,uVar8 & 7,uVar7,(longlong)param_6,param_7,uVar5);
            return 0x110000;
          }
          bVar3 = true;
          local_54 = (uint)(ushort)(uVar8 + uVar7);
        }
        uVar10 = *(uint *)(puVar11 + 0xc);
        while ((uVar10 & 1) != 0) {
          uVar5 = uVar5 + 1;
          puVar11 = (ushort *)((ulonglong)uVar5 * 0x68 + 0x2c + param_5);
          uVar10 = *(uint *)(puVar11 + 0xc);
        }
      }
      goto LAB_18000259d;
    }
    uVar5 = uVar5 + 1;
    bVar1 = true;
    puVar13 = puVar11;
  } while( true );
}



===== HidP_GetData @ 1800027b0 =====

undefined8
HidP_GetData(int param_1,longlong param_2,uint *param_3,int *param_4,char *param_5,short param_6)

{
  ushort *puVar1;
  short *psVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  ushort uVar8;
  int *piVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  short sVar13;
  
                    /* 0x27b0  9  HidP_GetData */
  uVar12 = 0;
  if (((param_4 == (int *)0x0) || (*param_4 != 0x50646948)) || (param_4[1] != 0x52444b20)) {
    uVar7 = 0xc0110001;
  }
  else {
    if (param_1 == 0) {
      lVar6 = 0x10;
    }
    else if (param_1 == 1) {
      lVar6 = 0x18;
    }
    else {
      if (param_1 != 2) {
        return 0xc0110002;
      }
      lVar6 = 0x20;
    }
    puVar1 = (ushort *)(lVar6 + (longlong)param_4);
    sVar13 = *(short *)(lVar6 + 6 + (longlong)param_4);
    if (param_6 != sVar13) {
      return 0xc0110003;
    }
    if (sVar13 == 0) {
      uVar7 = 0xc0110010;
    }
    else {
      uVar10 = *puVar1;
      if (uVar10 < puVar1[2]) {
        do {
          sVar13 = 0;
          piVar9 = param_4 + (ulonglong)uVar10 * 0x1a + 0xb;
          if ((((piVar9[6] & 0x10U) != 0) || (*(short *)((longlong)piVar9 + 6) == 1)) &&
             ((*param_5 == '\0' || (*(char *)((longlong)piVar9 + 2) == *param_5)))) {
            if ((piVar9[6] & 4U) == 0) {
              bVar3 = *(byte *)((longlong)piVar9 + 3);
              uVar11 = (ushort)bVar3;
              if ((uint)bVar3 < (uint)*(ushort *)((longlong)piVar9 + 10) + (uint)bVar3) {
                uVar8 = *(ushort *)(piVar9 + 1);
                do {
                  if ((uint)uVar12 < *param_3) {
                    psVar2 = (short *)(param_2 + (ulonglong)uVar12 * 8);
                    uVar5 = HidP_ExtractData((uVar11 >> 3) + (short)piVar9[2],uVar11 & 7,uVar8,
                                             (longlong)param_5);
                    *(uint *)(psVar2 + 2) = uVar5;
                    *psVar2 = sVar13 + (short)piVar9[0x12];
                  }
                  uVar12 = uVar12 + 1;
                  uVar8 = *(ushort *)(piVar9 + 1);
                  sVar13 = sVar13 + 1;
                  uVar11 = uVar11 + uVar8;
                } while ((uint)uVar11 <
                         (uint)*(byte *)((longlong)piVar9 + 3) +
                         (uint)*(ushort *)((longlong)piVar9 + 10));
              }
            }
            else {
              bVar3 = *(byte *)((longlong)piVar9 + 3);
              uVar11 = (ushort)bVar3;
              uVar5 = (uint)*(ushort *)((longlong)piVar9 + 10) + (uint)bVar3;
              if ((short)piVar9[1] == 1) {
                if (bVar3 < uVar5) {
                  do {
                    uVar8 = (short)piVar9[2] * 8 + uVar11;
                    if (((uint)(int)param_5[uVar8 >> 3] >> (uVar8 & 7) & 1) != 0) {
                      sVar13 = (short)piVar9[0x12];
                      if ((piVar9[6] & 0x10U) != 0) {
                        sVar13 = (sVar13 - (ushort)bVar3) + uVar11;
                      }
                      if ((uint)uVar12 < *param_3) {
                        *(undefined1 *)(param_2 + 4 + (ulonglong)uVar12 * 8) = 1;
                        *(short *)(param_2 + (ulonglong)uVar12 * 8) = sVar13;
                      }
                      uVar12 = uVar12 + 1;
                    }
                    bVar3 = *(byte *)((longlong)piVar9 + 3);
                    uVar11 = uVar11 + 1;
                  } while ((uint)uVar11 < (uint)*(ushort *)((longlong)piVar9 + 10) + (uint)bVar3);
                }
              }
              else if (bVar3 < uVar5) {
                do {
                  uVar5 = HidP_ExtractData((uVar11 >> 3) + (short)piVar9[2],uVar11 & 7,
                                           *(ushort *)(piVar9 + 1),(longlong)param_5);
                  if ((uVar5 & 0xffff) != 0) {
                    uVar4 = piVar9[6];
                    while ((uVar4 & 1) != 0) {
                      uVar10 = uVar10 + 1;
                      uVar4 = piVar9[0x20];
                      piVar9 = piVar9 + 0x1a;
                    }
                    sVar13 = (short)uVar5 + (short)piVar9[0x12];
                    if ((uint)uVar12 < *param_3) {
                      if ((short)piVar9[0xf] != 0) {
                        sVar13 = sVar13 + -1;
                      }
                      *(undefined1 *)(param_2 + 4 + (ulonglong)uVar12 * 8) = 1;
                      *(short *)(param_2 + (ulonglong)uVar12 * 8) = sVar13;
                    }
                    uVar12 = uVar12 + 1;
                  }
                  uVar11 = uVar11 + (short)piVar9[1];
                } while ((uint)uVar11 <
                         (uint)*(ushort *)((longlong)piVar9 + 10) +
                         (uint)*(byte *)((longlong)piVar9 + 3));
              }
            }
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < puVar1[2]);
      }
      uVar5 = *param_3;
      *param_3 = (uint)uVar12;
      uVar7 = 0xc0110007;
      if (uVar12 <= uVar5) {
        uVar7 = 0x110000;
      }
    }
  }
  return uVar7;
}



===== HidP_ExtractData @ 180002b00 =====

uint HidP_ExtractData(short param_1,short param_2,ushort param_3,longlong param_4)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ushort uVar4;
  ushort uVar5;
  byte bVar6;
  
  uVar1 = 0;
  uVar4 = param_1 * 8 + param_2 + param_3;
  uVar5 = uVar4 >> 3;
  uVar4 = uVar4 & 7;
  if (param_3 < uVar4) {
    return ((uint)*(byte *)((ulonglong)uVar5 + param_4) & (1 << (sbyte)uVar4) - 1U) >>
           ((byte)param_2 & 0x1f);
  }
  if (uVar4 != 0) {
    uVar1 = (1 << (sbyte)uVar4) - 1U & (uint)*(byte *)((ulonglong)uVar5 + param_4);
    param_3 = param_3 - uVar4;
  }
  uVar5 = uVar5 - 1;
  if (7 < param_3) {
    uVar3 = (ulonglong)(param_3 >> 3);
    do {
      uVar2 = (ulonglong)uVar5;
      param_3 = param_3 - 8;
      uVar5 = uVar5 - 1;
      uVar1 = uVar1 << 8 | (uint)*(byte *)(uVar2 + param_4);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  if (param_3 != 0) {
    bVar6 = (byte)param_3;
    uVar1 = (uint)(byte)(*(byte *)((ulonglong)uVar5 + param_4) >> (8 - bVar6 & 0x1f) &
                        ('\x01' << (bVar6 & 0x1f)) - 1U) | uVar1 << (bVar6 & 0x1f);
  }
  return uVar1;
}



===== HidP_SetScaledUsageValue @ 180002c00 =====

undefined8
HidP_SetScaledUsageValue
          (int param_1,short param_2,short param_3,ushort param_4,uint param_5,int *param_6,
          char *param_7,uint param_8)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  longlong lVar12;
  longlong lVar13;
  uint uVar14;
  
                    /* 0x2c00  25  HidP_SetScaledUsageValue */
  bVar8 = false;
  if (((param_6 == (int *)0x0) || (*param_6 != 0x50646948)) || (param_6[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  if (param_1 == 0) {
    lVar12 = 0x10;
  }
  else if (param_1 == 1) {
    lVar12 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar12 = 0x20;
  }
  sVar2 = *(short *)(lVar12 + 6 + (longlong)param_6);
  if ((short)param_8 != sVar2) {
    return 0xc0110003;
  }
  if (sVar2 == 0) {
    uVar11 = 0xc0110010;
  }
  else {
    for (uVar9 = (uint)*(ushort *)(lVar12 + (longlong)param_6);
        uVar9 < *(ushort *)(lVar12 + 4 + (longlong)param_6); uVar9 = uVar9 + 1) {
      uVar10 = (ulonglong)uVar9;
      lVar13 = uVar10 * 0x68;
      if ((((param_6[uVar10 * 0x1a + 0x11] & 4U) == 0) &&
          ((short)param_6[uVar10 * 0x1a + 0xb] == param_2)) &&
         (((param_3 == 0 ||
           (sVar2 = *(short *)(lVar13 + 0x3e + (longlong)param_6), param_3 == sVar2)) ||
          ((param_3 == -1 && (sVar2 == 0)))))) {
        uVar3 = *(ushort *)(param_6 + uVar10 * 0x1a + 0x1a);
        if ((param_6[uVar10 * 0x1a + 0x11] & 0x10U) == 0) {
          if (uVar3 == param_4) {
            uVar14 = (uint)*(byte *)(lVar13 + 0x2f + (longlong)param_6) +
                     (uint)*(ushort *)(param_6 + uVar10 * 0x1a + 0xd) * 8;
LAB_180002cf6:
            if ((*param_7 == '\0') || (*(char *)(lVar13 + 0x2e + (longlong)param_6) == *param_7)) {
              *param_7 = *(char *)(lVar13 + 0x2e + (longlong)param_6);
              iVar4 = param_6[uVar10 * 0x1a + 0x21];
              iVar5 = param_6[uVar10 * 0x1a + 0x1f];
              iVar6 = param_6[uVar10 * 0x1a + 0x20];
              iVar7 = param_6[uVar10 * 0x1a + 0x22];
              if ((iVar4 == 0) && (iVar7 == 0)) {
                if (iVar6 == iVar5) {
                  return 0xc0110006;
                }
                if ((iVar5 <= (int)param_5) && ((int)param_5 <= iVar6)) {
                  if ((int)param_5 < 0) {
                    uVar9 = param_5 | 1 << (*(ushort *)(param_6 + uVar10 * 0x1a + 0xc) - 1 & 0x1f);
                  }
                  else {
                    uVar9 = param_5 & (1 << ((byte)(*(ushort *)(param_6 + uVar10 * 0x1a + 0xc) - 1)
                                            & 0x1f)) - 1U;
                  }
                  goto LAB_180002d6f;
                }
                cVar1 = (char)param_6[uVar10 * 0x1a + 0x1e];
              }
              else {
                if (iVar6 <= iVar5) {
                  return 0xc0110006;
                }
                if (iVar7 <= iVar4) {
                  return 0xc0110006;
                }
                if ((iVar4 <= (int)param_5) && ((int)param_5 <= iVar7)) {
                  uVar9 = (int)(((iVar6 - iVar5) + 1) * (param_5 - iVar4)) / ((iVar7 - iVar4) + 1) +
                          iVar5;
                  goto LAB_180002d6f;
                }
                cVar1 = (char)param_6[uVar10 * 0x1a + 0x1e];
              }
              if (cVar1 == '\0') {
                return 0xc0110005;
              }
              uVar9 = 1 << ((char)param_6[uVar10 * 0x1a + 0xc] - 1U & 0x1f);
LAB_180002d6f:
              HidP_InsertData((ushort)(uVar14 >> 3),(ushort)uVar14 & 7,
                              *(ushort *)(param_6 + uVar10 * 0x1a + 0xc),(longlong)param_7,param_8,
                              uVar9);
              return 0x110000;
            }
            bVar8 = true;
          }
        }
        else if ((uVar3 <= param_4) && (param_4 <= *(ushort *)(lVar13 + 0x6a + (longlong)param_6)))
        {
          uVar14 = ((uint)param_4 - (uint)uVar3) * (uint)*(ushort *)(param_6 + uVar10 * 0x1a + 0xc)
                   + (uint)*(ushort *)(param_6 + uVar10 * 0x1a + 0xd) * 8 +
                   (uint)*(byte *)(lVar13 + 0x2f + (longlong)param_6);
          goto LAB_180002cf6;
        }
      }
    }
    uVar11 = 0xc0110004;
    if (bVar8) {
      uVar11 = 0xc011000a;
    }
  }
  return uVar11;
}



===== HidP_SetData @ 180002f20 =====

undefined8
HidP_SetData(int param_1,ushort *param_2,uint *param_3,int *param_4,char *param_5,uint param_6)

{
  short sVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  
                    /* 0x2f20  24  HidP_SetData */
  uVar2 = 0xc0110010;
  if (((param_4 == (int *)0x0) || (*param_4 != 0x50646948)) || (param_4[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  if (param_1 == 0) {
    lVar3 = 0x10;
  }
  else if (param_1 == 1) {
    lVar3 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar3 = 0x20;
  }
  sVar1 = *(short *)(lVar3 + 6 + (longlong)param_4);
  if ((short)param_6 == sVar1) {
    uVar4 = 0;
    if (sVar1 != 0) {
      if (*param_3 != 0) {
        do {
          uVar2 = HidP_SetOneData((ushort *)(lVar3 + (longlong)param_4),param_2,(longlong)param_4,
                                  param_5,param_6);
          if ((int)uVar2 < 0) break;
          uVar4 = uVar4 + 1;
          param_2 = param_2 + 4;
        } while (uVar4 < *param_3);
      }
      *param_3 = uVar4;
    }
  }
  else {
    uVar2 = 0xc0110003;
  }
  return uVar2;
}



===== HidP_SetOneData @ 180003040 =====

undefined8
HidP_SetOneData(ushort *param_1,ushort *param_2,longlong param_3,char *param_4,uint param_5)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  undefined8 uVar7;
  ushort uVar8;
  uint uVar9;
  longlong lVar10;
  uint uVar11;
  ushort uVar12;
  
  bVar3 = false;
  bVar5 = false;
  bVar4 = false;
  if (param_5 == 0) {
    return 0xc0110003;
  }
  uVar8 = *param_1;
LAB_18000308b:
  do {
    if (param_1[2] <= uVar8) {
      if (bVar3) {
        return 0xc011000a;
      }
      if (bVar4) {
        return 0xc011000f;
      }
      if (bVar5) {
        return 0xc0110007;
      }
      return 0xc011000d;
    }
    lVar10 = (ulonglong)uVar8 * 0x68 + 0x2c + param_3;
    if ((*(ushort *)(lVar10 + 0x48) <= *param_2) && (*param_2 <= *(ushort *)(lVar10 + 0x4a))) {
      if (((*(uint *)(lVar10 + 0x18) & 0x10) == 0) && (*(short *)(lVar10 + 6) != 1)) {
        return 0xc011000c;
      }
      if (*param_4 == '\0') {
        *param_4 = *(char *)(lVar10 + 2);
      }
      else if (*(char *)(lVar10 + 2) != *param_4) {
        bVar3 = true;
        goto LAB_180003162;
      }
      uVar11 = *(uint *)(lVar10 + 0x18);
      if ((uVar11 & 4) == 0) {
        uVar8 = (*param_2 - *(short *)(lVar10 + 0x48)) * *(ushort *)(lVar10 + 4) +
                *(short *)(lVar10 + 8) * 8 + (ushort)*(byte *)(lVar10 + 3);
        HidP_InsertData(uVar8 >> 3,uVar8 & 7,*(ushort *)(lVar10 + 4),(longlong)param_4,param_5,
                        *(uint *)(param_2 + 2));
        return 0x110000;
      }
      if (*(short *)(lVar10 + 4) == 1) {
        uVar8 = (*(short *)(lVar10 + 8) * 8 - *(short *)(lVar10 + 0x48)) +
                (ushort)*(byte *)(lVar10 + 3) + *param_2;
        uVar11 = (uint)(uVar8 >> 3);
        if (param_5 <= uVar11) {
          return 0xc0110003;
        }
        uVar9 = uVar8 & 7;
        bVar6 = param_4[uVar11];
        if ((char)param_2[2] == '\0') {
          if (((uint)(int)(char)bVar6 >> uVar9 & 1) == 0) {
            return 0xc011000f;
          }
          bVar6 = bVar6 & ~(byte)(1 << uVar9);
        }
        else {
          bVar6 = bVar6 | (byte)(1 << uVar9);
        }
        param_4[uVar11] = bVar6;
        return 0x110000;
      }
      if ((char)param_2[2] == '\0') {
        while ((uVar11 & 1) != 0) {
          uVar8 = uVar8 + 1;
          uVar11 = *(uint *)(lVar10 + 0x80);
          lVar10 = lVar10 + 0x68;
        }
        uVar11 = (uint)*param_2 - (uint)*(ushort *)(lVar10 + 0x48);
        if (*(short *)(lVar10 + 0x3c) != 0) {
          uVar11 = uVar11 + 1;
        }
        uVar7 = HidP_DeleteArrayEntry
                          ((uint)(ushort)(*(short *)(lVar10 + 8) * 8 + (ushort)*(byte *)(lVar10 + 3)
                                         ),*(ushort *)(lVar10 + 4),*(ushort *)(lVar10 + 6),uVar11,
                           (longlong)param_4,param_5);
        if ((int)uVar7 == -0x3feefff1) {
          bVar4 = true;
          uVar8 = uVar8 + 1;
          goto LAB_18000308b;
        }
        if (-1 < (int)uVar7) {
          return uVar7;
        }
      }
      bVar6 = *(byte *)(lVar10 + 3);
      uVar1 = *(ushort *)(lVar10 + 10);
      uVar11 = (uint)bVar6;
      while (uVar12 = (ushort)uVar11, uVar11 < (uint)uVar1 + (uint)bVar6) {
        uVar2 = *(ushort *)(lVar10 + 4);
        uVar11 = HidP_ExtractData((uVar12 >> 3) + *(short *)(lVar10 + 8),uVar12 & 7,uVar2,
                                  (longlong)param_4);
        if ((short)uVar11 == 0) {
          uVar11 = *(uint *)(lVar10 + 0x18);
          while ((uVar11 & 1) != 0) {
            uVar11 = *(uint *)(lVar10 + 0x80);
            lVar10 = lVar10 + 0x68;
          }
          uVar11 = (uint)*param_2 - (uint)*(ushort *)(lVar10 + 0x48);
          if (*(short *)(lVar10 + 0x3c) != 0) {
            uVar11 = uVar11 + 1;
          }
          HidP_InsertData((uVar12 >> 3) + *(short *)(lVar10 + 8),uVar12 & 7,*(ushort *)(lVar10 + 4),
                          (longlong)param_4,param_5,uVar11);
          return 0x110000;
        }
        bVar5 = true;
        uVar11 = (uint)(ushort)(uVar12 + uVar2);
      }
    }
LAB_180003162:
    uVar8 = uVar8 + 1;
  } while( true );
}



===== HidP_SetUsageValueArray @ 180003360 =====

undefined8
HidP_SetUsageValueArray
          (int param_1,short param_2,short param_3,ushort param_4,char *param_5,ushort param_6,
          int *param_7,char *param_8,uint param_9)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
                    /* 0x3360  27  HidP_SetUsageValueArray */
  bVar2 = false;
  if (((param_7 == (int *)0x0) || (*param_7 != 0x50646948)) || (param_7[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  if (param_1 == 1) {
    lVar5 = 0x18;
  }
  else if (param_1 == 0) {
    lVar5 = 0x10;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar5 = 0x20;
  }
  sVar1 = *(short *)(lVar5 + 6 + (longlong)param_7);
  if ((short)param_9 != sVar1) {
    return 0xc0110003;
  }
  if (sVar1 == 0) {
    uVar4 = 0xc0110010;
  }
  else {
    for (uVar6 = (uint)*(ushort *)(lVar5 + (longlong)param_7);
        uVar6 < *(ushort *)(lVar5 + 4 + (longlong)param_7); uVar6 = uVar6 + 1) {
      if ((((param_7[(ulonglong)uVar6 * 0x1a + 0x11] & 4U) == 0) &&
          ((short)param_7[(ulonglong)uVar6 * 0x1a + 0xb] == param_2)) &&
         (((param_3 == 0 ||
           (sVar1 = *(short *)((longlong)param_7 + (ulonglong)uVar6 * 0x68 + 0x3e), param_3 == sVar1
           )) || ((param_3 == -1 && (sVar1 == 0)))))) {
        if ((param_7[(ulonglong)uVar6 * 0x1a + 0x11] & 0x10U) == 0) {
          if (*(ushort *)(param_7 + (ulonglong)uVar6 * 0x1a + 0x1a) == param_4) {
            if (*(short *)((longlong)param_7 + (ulonglong)uVar6 * 0x68 + 0x32) == 1) {
              return 0xc011000b;
            }
            uVar8 = (uint)*(byte *)((longlong)param_7 + (ulonglong)uVar6 * 0x68 + 0x2f) +
                    (uint)*(ushort *)(param_7 + (ulonglong)uVar6 * 0x1a + 0xd) * 8;
            if ((*param_8 == '\0') ||
               (*(char *)((longlong)param_7 + (ulonglong)uVar6 * 0x68 + 0x2e) == *param_8)) {
              *param_8 = *(char *)((longlong)param_7 + (ulonglong)uVar6 * 0x68 + 0x2e);
              uVar3 = *(ushort *)(param_7 + (ulonglong)uVar6 * 0x1a + 0xc);
              uVar9 = (uint)*(ushort *)((longlong)param_7 + (ulonglong)uVar6 * 0x68 + 0x32);
              if ((int)((uint)param_6 * 8) < (int)(uVar3 * uVar9)) {
                return 0xc0110007;
              }
              if ((uVar3 & 7) != 0) {
                return 0xc0110020;
              }
              uVar7 = 0;
              if (uVar9 != 0) {
                do {
                  uVar9 = 0;
                  if ((char)(uVar3 >> 3) != '\0') {
                    do {
                      HidP_InsertData((ushort)(uVar8 >> 3),(ushort)uVar8 & 7,8,(longlong)param_8,
                                      param_9,(int)*param_5);
                      uVar3 = *(ushort *)(param_7 + (ulonglong)uVar6 * 0x1a + 0xc);
                      uVar8 = uVar8 + 8;
                      param_5 = param_5 + 1;
                      uVar9 = uVar9 + 1;
                    } while (uVar9 < (byte)(uVar3 >> 3));
                  }
                  uVar7 = uVar7 + 1;
                } while (uVar7 < *(ushort *)((longlong)param_7 + (ulonglong)uVar6 * 0x68 + 0x32));
              }
              return 0x110000;
            }
            bVar2 = true;
          }
        }
        else if ((*(ushort *)(param_7 + (ulonglong)uVar6 * 0x1a + 0x1a) <= param_4) &&
                (param_4 <= *(ushort *)((longlong)param_7 + (ulonglong)uVar6 * 0x68 + 0x6a))) {
          return 0xc011000b;
        }
      }
    }
    uVar4 = 0xc0110004;
    if (bVar2) {
      uVar4 = 0xc011000a;
    }
  }
  return uVar4;
}



===== HidP_SetUsageValue @ 180003610 =====

undefined8
HidP_SetUsageValue(int param_1,short param_2,short param_3,ushort param_4,uint param_5,int *param_6,
                  char *param_7,uint param_8)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  
                    /* 0x3610  26  HidP_SetUsageValue */
  bVar3 = false;
  if (((param_6 == (int *)0x0) || (*param_6 != 0x50646948)) || (param_6[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  if (param_1 == 0) {
    lVar6 = 0x10;
  }
  else if (param_1 == 1) {
    lVar6 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar6 = 0x20;
  }
  sVar1 = *(short *)(lVar6 + 6 + (longlong)param_6);
  if ((short)param_8 != sVar1) {
    return 0xc0110003;
  }
  if (sVar1 == 0) {
    uVar5 = 0xc0110010;
  }
  else {
    for (uVar4 = (uint)*(ushort *)(lVar6 + (longlong)param_6);
        uVar4 < *(ushort *)(lVar6 + 4 + (longlong)param_6); uVar4 = uVar4 + 1) {
      if ((((param_6[(ulonglong)uVar4 * 0x1a + 0x11] & 4U) == 0) &&
          ((short)param_6[(ulonglong)uVar4 * 0x1a + 0xb] == param_2)) &&
         (((param_3 == 0 ||
           (sVar1 = *(short *)((longlong)param_6 + (ulonglong)uVar4 * 0x68 + 0x3e), param_3 == sVar1
           )) || ((param_3 == -1 && (sVar1 == 0)))))) {
        uVar2 = *(ushort *)(param_6 + (ulonglong)uVar4 * 0x1a + 0x1a);
        if ((param_6[(ulonglong)uVar4 * 0x1a + 0x11] & 0x10U) == 0) {
          if (uVar2 == param_4) {
            uVar7 = (uint)*(byte *)((longlong)param_6 + (ulonglong)uVar4 * 0x68 + 0x2f) +
                    (uint)*(ushort *)(param_6 + (ulonglong)uVar4 * 0x1a + 0xd) * 8;
LAB_180003700:
            if ((*param_7 == '\0') ||
               (*(char *)((longlong)param_6 + (ulonglong)uVar4 * 0x68 + 0x2e) == *param_7)) {
              *param_7 = *(char *)((longlong)param_6 + (ulonglong)uVar4 * 0x68 + 0x2e);
              HidP_InsertData((ushort)(uVar7 >> 3),(ushort)uVar7 & 7,
                              *(ushort *)(param_6 + (ulonglong)uVar4 * 0x1a + 0xc),(longlong)param_7
                              ,param_8,param_5);
              return 0x110000;
            }
            bVar3 = true;
          }
        }
        else if ((uVar2 <= param_4) &&
                (param_4 <= *(ushort *)((longlong)param_6 + (ulonglong)uVar4 * 0x68 + 0x6a))) {
          uVar7 = ((uint)param_4 - (uint)uVar2) *
                  (uint)*(ushort *)(param_6 + (ulonglong)uVar4 * 0x1a + 0xc) +
                  (uint)*(ushort *)(param_6 + (ulonglong)uVar4 * 0x1a + 0xd) * 8 +
                  (uint)*(byte *)((longlong)param_6 + (ulonglong)uVar4 * 0x68 + 0x2f);
          goto LAB_180003700;
        }
      }
    }
    uVar5 = 0xc0110004;
    if (bVar3) {
      uVar5 = 0xc011000a;
    }
  }
  return uVar5;
}



===== HidP_InsertData @ 180003840 =====

void HidP_InsertData(ushort param_1,ushort param_2,ushort param_3,longlong param_4,uint param_5,
                    uint param_6)

{
  ushort uVar1;
  ulonglong uVar2;
  byte bVar3;
  byte bVar4;
  
  uVar2 = (ulonglong)param_1;
  if (param_1 < param_5) {
    bVar3 = (byte)param_2;
    if ((uint)param_2 + (uint)param_3 < 8) {
      bVar4 = ('\x01' << ((byte)((uint)param_2 + (uint)param_3) & 0x1f)) -
              ('\x01' << (bVar3 & 0x1f));
      *(byte *)(uVar2 + param_4) =
           (char)param_6 << (bVar3 & 0x1f) & bVar4 | ~bVar4 & *(byte *)(uVar2 + param_4);
    }
    else {
      if (param_2 != 0) {
        bVar4 = (char)param_6 << (bVar3 & 0x1f);
        param_3 = param_3 + (param_2 - 8);
        param_6 = param_6 >> (8 - bVar3 & 0x1f);
        *(byte *)(uVar2 + param_4) =
             ('\x01' << (bVar3 & 0x1f)) - 1U & *(byte *)(uVar2 + param_4) | bVar4;
        uVar2 = (ulonglong)(ushort)(param_1 + 1);
      }
      uVar1 = (ushort)uVar2;
      for (; 7 < param_3; param_3 = param_3 - 8) {
        uVar1 = (ushort)uVar2;
        if (param_5 <= (uint)uVar2) goto LAB_180003905;
        uVar1 = uVar1 + 1;
        *(byte *)(uVar2 + param_4) = (byte)param_6;
        param_6 = param_6 >> 8;
        uVar2 = (ulonglong)uVar1;
      }
      if (param_3 != 0) {
LAB_180003905:
        if (uVar1 < param_5) {
          *(byte *)((ulonglong)uVar1 + param_4) =
               ('\x01' << ((byte)param_3 & 0x1f)) - 1U & (byte)param_6 |
               -1 << ((byte)param_3 & 0x1f) & *(byte *)((ulonglong)uVar1 + param_4);
        }
      }
    }
  }
  return;
}



===== HidP_GetValueCaps @ 180003970 =====

void HidP_GetValueCaps(int param_1,longlong param_2,ushort *param_3,int *param_4)

{
                    /* 0x3970  19  HidP_GetValueCaps */
  HidP_GetSpecificValueCaps(param_1,0,0,0,param_2,param_3,param_4);
  return;
}



===== HidP_GetSpecificValueCaps @ 1800039b0 =====

undefined8
HidP_GetSpecificValueCaps
          (int param_1,short param_2,short param_3,ushort param_4,longlong param_5,ushort *param_6,
          int *param_7)

{
  short sVar1;
  ushort uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  ushort uVar6;
  
                    /* 0x39b0  14  HidP_GetSpecificValueCaps */
  uVar4 = 0xc0110004;
  if (((param_7 == (int *)0x0) || (*param_7 != 0x50646948)) || (param_7[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  if (param_1 == 0) {
    lVar5 = 0x10;
  }
  else if (param_1 == 1) {
    lVar5 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0xc0110002;
    }
    lVar5 = 0x20;
  }
  uVar2 = *(ushort *)(lVar5 + (longlong)param_7);
  uVar6 = 0;
  if (uVar2 < *(ushort *)(lVar5 + 4 + (longlong)param_7)) {
    do {
      if (((((param_7[(ulonglong)uVar2 * 0x1a + 0x11] & 4U) == 0) &&
           ((param_2 == 0 || (param_2 == (short)param_7[(ulonglong)uVar2 * 0x1a + 0xb])))) &&
          ((param_3 == 0 ||
           ((sVar1 = *(short *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x3e),
            param_3 == sVar1 || ((param_3 == -1 && (sVar1 == 0)))))))) &&
         ((param_4 == 0 ||
          ((*(ushort *)(param_7 + (ulonglong)uVar2 * 0x1a + 0x1a) <= param_4 &&
           (param_4 <= *(ushort *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x6a))))))) {
        uVar4 = 0x110000;
        if (uVar6 < *param_6) {
          uVar3 = (ulonglong)uVar6;
          *(short *)(param_5 + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0xb];
          *(undefined2 *)(param_5 + 6 + uVar3 * 0x48) =
               *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x3e);
          *(short *)(param_5 + 10 + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0x10];
          *(undefined2 *)(param_5 + 8 + uVar3 * 0x48) =
               *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x42);
          *(byte *)(param_5 + 0xc + uVar3 * 0x48) =
               (byte)((uint)param_7[(ulonglong)uVar2 * 0x1a + 0x11] >> 4) & 1;
          *(byte *)(param_5 + 0xd + uVar3 * 0x48) =
               (byte)((uint)param_7[(ulonglong)uVar2 * 0x1a + 0x11] >> 6) & 1;
          *(byte *)(param_5 + 0xe + uVar3 * 0x48) =
               (byte)((uint)param_7[(ulonglong)uVar2 * 0x1a + 0x11] >> 7) & 1;
          *(undefined1 *)(param_5 + 2 + uVar3 * 0x48) =
               *(undefined1 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x2e);
          *(short *)(param_5 + 4 + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0xe];
          *(short *)(param_5 + 0x12 + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0xc];
          *(byte *)(param_5 + 0xf + uVar3 * 0x48) =
               (byte)((uint)param_7[(ulonglong)uVar2 * 0x1a + 0x11] >> 3) & 1;
          *(char *)(param_5 + 0x10 + uVar3 * 0x48) = (char)param_7[(ulonglong)uVar2 * 0x1a + 0x1e];
          *(int *)(param_5 + 0x24 + uVar3 * 0x48) = param_7[(ulonglong)uVar2 * 0x1a + 0x23];
          *(int *)(param_5 + 0x20 + uVar3 * 0x48) = param_7[(ulonglong)uVar2 * 0x1a + 0x24];
          *(int *)(param_5 + 0x28 + uVar3 * 0x48) = param_7[(ulonglong)uVar2 * 0x1a + 0x1f];
          *(int *)(param_5 + 0x2c + uVar3 * 0x48) = param_7[(ulonglong)uVar2 * 0x1a + 0x20];
          *(int *)(param_5 + 0x30 + uVar3 * 0x48) = param_7[(ulonglong)uVar2 * 0x1a + 0x21];
          *(int *)(param_5 + 0x34 + uVar3 * 0x48) = param_7[(ulonglong)uVar2 * 0x1a + 0x22];
          *(byte *)(param_5 + 3 + uVar3 * 0x48) =
               (byte)((uint)param_7[(ulonglong)uVar2 * 0x1a + 0x11] >> 5) & 1;
          *(short *)(param_5 + 0x38 + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0x1a]
          ;
          *(undefined2 *)(param_5 + 0x3a + uVar3 * 0x48) =
               *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x6a);
          *(short *)(param_5 + 0x44 + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0x1d]
          ;
          *(undefined2 *)(param_5 + 0x46 + uVar3 * 0x48) =
               *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x76);
          *(short *)(param_5 + 0x3c + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0x1b]
          ;
          *(undefined2 *)(param_5 + 0x3e + uVar3 * 0x48) =
               *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x6e);
          *(short *)(param_5 + 0x40 + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0x1c]
          ;
          *(undefined2 *)(param_5 + 0x42 + uVar3 * 0x48) =
               *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x72);
          if ((param_7[(ulonglong)uVar2 * 0x1a + 0x11] & 0x10U) != 0) {
            uVar6 = uVar6 + 1;
            *(undefined2 *)(param_5 + 0x14 + uVar3 * 0x48) = 1;
            goto LAB_180003a79;
          }
          *(undefined2 *)(param_5 + 0x14 + uVar3 * 0x48) =
               *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x32);
        }
        else {
          uVar4 = 0xc0110007;
        }
        uVar6 = uVar6 + 1;
      }
LAB_180003a79:
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(ushort *)(lVar5 + 4 + (longlong)param_7));
  }
  *param_6 = uVar6;
  return uVar4;
}



===== HidP_UsageListDifference @ 180003ca0 =====

undefined8
HidP_UsageListDifference
          (short *param_1,short *param_2,longlong param_3,longlong param_4,uint param_5)

{
  short sVar1;
  uint uVar2;
  ulonglong uVar3;
  short *psVar4;
  uint uVar5;
  undefined2 *puVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  
                    /* 0x3ca0  35  HidP_UsageListDifference */
  uVar9 = 0;
  uVar5 = 0;
  uVar2 = 0;
  if (param_5 != 0) {
    psVar4 = param_1;
    uVar3 = 0;
    do {
      uVar5 = (uint)uVar3;
      sVar1 = *psVar4;
      if (sVar1 == 0) break;
      for (uVar8 = 0; (uVar8 < param_5 && (param_2[uVar8] != 0)); uVar8 = uVar8 + 1) {
        uVar7 = uVar3;
        if (param_2[uVar8] == sVar1) goto LAB_180003d63;
      }
      uVar7 = (ulonglong)(uVar5 + 1);
      *(short *)(param_3 + uVar3 * 2) = sVar1;
LAB_180003d63:
      uVar5 = (uint)uVar7;
      uVar2 = uVar2 + 1;
      psVar4 = psVar4 + 1;
      uVar3 = uVar7;
    } while (uVar2 < param_5);
  }
  uVar2 = 0;
  if (param_5 != 0) {
    do {
      sVar1 = *param_2;
      if (sVar1 == 0) break;
      for (uVar8 = 0; (uVar8 < param_5 && (param_1[uVar8] != 0)); uVar8 = uVar8 + 1) {
        if (param_1[uVar8] == sVar1) goto LAB_180003d91;
      }
      uVar3 = (ulonglong)uVar9;
      uVar9 = uVar9 + 1;
      *(short *)(param_4 + uVar3 * 2) = sVar1;
LAB_180003d91:
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 1;
    } while (uVar2 < param_5);
  }
  if (uVar5 < param_5) {
    puVar6 = (undefined2 *)(param_3 + (ulonglong)uVar5 * 2);
    for (uVar3 = (ulonglong)(param_5 - uVar5); uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
  }
  if (uVar9 < param_5) {
    puVar6 = (undefined2 *)(param_4 + (ulonglong)uVar9 * 2);
    for (uVar3 = (ulonglong)(param_5 - uVar9); uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
  }
  return 0x110000;
}



===== HidP_GetSpecificButtonCaps @ 180003dd0 =====

undefined8
HidP_GetSpecificButtonCaps
          (int param_1,short param_2,short param_3,ushort param_4,longlong param_5,ushort *param_6,
          int *param_7)

{
  short sVar1;
  ushort uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ushort uVar5;
  longlong lVar6;
  
                    /* 0x3dd0  13  HidP_GetSpecificButtonCaps */
  uVar4 = 0xc0110004;
  if (((param_7 == (int *)0x0) || (*param_7 != 0x50646948)) || (param_7[1] != 0x52444b20)) {
    uVar4 = 0xc0110001;
  }
  else {
    if (param_1 == 0) {
      lVar6 = 0x10;
    }
    else if (param_1 == 1) {
      lVar6 = 0x18;
    }
    else {
      if (param_1 != 2) {
        return 0xc0110002;
      }
      lVar6 = 0x20;
    }
    uVar2 = *(ushort *)(lVar6 + (longlong)param_7);
    uVar5 = 0;
    if (uVar2 < *(ushort *)(lVar6 + 4 + (longlong)param_7)) {
      do {
        if (((((param_7[(ulonglong)uVar2 * 0x1a + 0x11] & 4U) != 0) &&
             ((param_2 == 0 || (param_2 == (short)param_7[(ulonglong)uVar2 * 0x1a + 0xb])))) &&
            ((param_3 == 0 ||
             ((sVar1 = *(short *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x3e),
              param_3 == sVar1 || ((param_3 == -1 && (sVar1 == 0)))))))) &&
           ((param_4 == 0 ||
            ((*(ushort *)(param_7 + (ulonglong)uVar2 * 0x1a + 0x1a) <= param_4 &&
             (param_4 <= *(ushort *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x6a))))))) {
          uVar4 = 0x110000;
          if (uVar5 < *param_6) {
            uVar3 = (ulonglong)uVar5;
            *(short *)(param_5 + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0xb];
            *(undefined2 *)(param_5 + 6 + uVar3 * 0x48) =
                 *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x3e);
            *(short *)(param_5 + 10 + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0x10]
            ;
            *(undefined2 *)(param_5 + 8 + uVar3 * 0x48) =
                 *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x42);
            *(byte *)(param_5 + 0xc + uVar3 * 0x48) =
                 (byte)((uint)param_7[(ulonglong)uVar2 * 0x1a + 0x11] >> 4) & 1;
            *(byte *)(param_5 + 0xd + uVar3 * 0x48) =
                 (byte)((uint)param_7[(ulonglong)uVar2 * 0x1a + 0x11] >> 6) & 1;
            *(byte *)(param_5 + 0xe + uVar3 * 0x48) =
                 (byte)((uint)param_7[(ulonglong)uVar2 * 0x1a + 0x11] >> 7) & 1;
            *(undefined1 *)(param_5 + 2 + uVar3 * 0x48) =
                 *(undefined1 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x2e);
            *(short *)(param_5 + 4 + uVar3 * 0x48) = (short)param_7[(ulonglong)uVar2 * 0x1a + 0xe];
            *(byte *)(param_5 + 0xf + uVar3 * 0x48) =
                 (byte)((uint)param_7[(ulonglong)uVar2 * 0x1a + 0x11] >> 3) & 1;
            *(byte *)(param_5 + 3 + uVar3 * 0x48) =
                 (byte)((uint)param_7[(ulonglong)uVar2 * 0x1a + 0x11] >> 5) & 1;
            *(short *)(param_5 + 0x38 + uVar3 * 0x48) =
                 (short)param_7[(ulonglong)uVar2 * 0x1a + 0x1a];
            *(undefined2 *)(param_5 + 0x3a + uVar3 * 0x48) =
                 *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x6a);
            *(short *)(param_5 + 0x44 + uVar3 * 0x48) =
                 (short)param_7[(ulonglong)uVar2 * 0x1a + 0x1d];
            *(undefined2 *)(param_5 + 0x46 + uVar3 * 0x48) =
                 *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x76);
            *(short *)(param_5 + 0x3c + uVar3 * 0x48) =
                 (short)param_7[(ulonglong)uVar2 * 0x1a + 0x1b];
            *(undefined2 *)(param_5 + 0x3e + uVar3 * 0x48) =
                 *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x6e);
            *(short *)(param_5 + 0x40 + uVar3 * 0x48) =
                 (short)param_7[(ulonglong)uVar2 * 0x1a + 0x1c];
            *(undefined2 *)(param_5 + 0x42 + uVar3 * 0x48) =
                 *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x72);
            *(undefined2 *)(param_5 + 0x12 + uVar3 * 0x48) = 0;
            if ((param_7[(ulonglong)uVar2 * 0x1a + 0x11] & 0x10U) != 0) {
              uVar5 = uVar5 + 1;
              *(undefined2 *)(param_5 + 0x10 + uVar3 * 0x48) = 1;
              goto LAB_180003e73;
            }
            *(undefined2 *)(param_5 + 0x10 + uVar3 * 0x48) =
                 *(undefined2 *)((longlong)param_7 + (ulonglong)uVar2 * 0x68 + 0x32);
          }
          else {
            uVar4 = 0xc0110007;
          }
          uVar5 = uVar5 + 1;
        }
LAB_180003e73:
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(ushort *)(lVar6 + 4 + (longlong)param_7));
    }
    *param_6 = uVar5;
  }
  return uVar4;
}



===== HidP_KeyboardKeypadCode @ 180004080 =====

undefined1
HidP_KeyboardKeypadCode
          (longlong param_1,byte param_2,undefined *param_3,undefined8 param_4,int param_5,
          uint *param_6)

{
  if (((*param_6 & 0x400) != 0) && (param_5 == 1)) {
    HidP_KbdPutKey(0x2ae0,1,param_3,param_4);
  }
  HidP_KbdPutKey(*(undefined4 *)(param_1 + (ulonglong)param_2 * 4),param_5,param_3,param_4);
  if (((*param_6 & 0x400) != 0) && (param_5 == 0)) {
    HidP_KbdPutKey(0x2ae0,0,param_3,param_4);
  }
  return 1;
}



===== HidP_ModifierCode @ 180004130 =====

undefined8
HidP_ModifierCode(longlong param_1,byte param_2,undefined *param_3,undefined8 param_4,int param_5,
                 uint *param_6)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  uVar3 = (ulonglong)param_2;
  if (param_2 < 8) {
    if (param_5 != 0) {
      if (param_5 == 1) {
        *param_6 = *param_6 | 1 << (param_2 & 0x1f);
      }
      goto LAB_18000415c;
    }
  }
  else {
    if (param_5 != 0) {
      if (param_5 == 1) {
        uVar1 = 1 << (param_2 + 0x10 & 0x1f);
        if ((*param_6 & uVar1) == 0) {
          *param_6 = (uVar1 | *param_6) ^ 1 << (param_2 & 0x1f);
        }
      }
      goto LAB_18000415c;
    }
    param_2 = param_2 + 0x10;
  }
  *param_6 = *param_6 & ~(1 << (param_2 & 0x1f));
LAB_18000415c:
  uVar2 = HidP_KbdPutKey(*(undefined4 *)(param_1 + uVar3 * 4),param_5,param_3,param_4);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== HidP_TranslateUsageAndPagesToI8042ScanCodes @ 1800041f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
HidP_TranslateUsageAndPagesToI8042ScanCodes
          (ushort *param_1,uint param_2,int param_3,uint *param_4,undefined *param_5,
          undefined8 param_6)

{
  ushort uVar1;
  char cVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  
                    /* 0x41f0  31  HidP_TranslateUsageAndPagesToI8042ScanCodes */
  uVar3 = 0x110000;
  uVar5 = 0;
  if (param_2 != 0) {
    do {
      uVar1 = *param_1;
      if (uVar1 == 0) {
        return uVar3;
      }
      if (param_1[1] == 7) {
        if ((0xff < uVar1) ||
           (uVar4 = *(uint *)(&HidP_KeyboardToScanCodeTable + (ulonglong)uVar1 * 4), uVar4 == 0)) {
          return 0xc0110009;
        }
        if (((*param_4 & 0x11) == 0) || (uVar4 != 0x451de1)) {
          if (((byte)uVar4 & 0xf0) != 0xf0) goto LAB_1800042c1;
          if ((code *)(&HidP_KeyboardSubTables)[(ulonglong)(uVar4 & 0xf) * 2] == (code *)0x0) {
            return 0xc0110009;
          }
          cVar2 = (*(code *)(&HidP_KeyboardSubTables)[(ulonglong)(uVar4 & 0xf) * 2])
                            ((&PTR_HidP_XlateKbdPadCodesSubTable_18000c008)
                             [(ulonglong)(uVar4 & 0xf) * 2],uVar4 >> 8 & 0xff,param_5,param_6,
                             param_3,param_4);
          if (cVar2 == '\0') {
            return 0xc0110009;
          }
        }
        else {
          uVar4 = 0x46e0;
LAB_1800042c1:
          HidP_KbdPutKey(uVar4,param_3,param_5,param_6);
        }
        uVar3 = 0x110000;
      }
      else {
        if (param_1[1] != 0xc) {
          return 0xc0110009;
        }
        uVar3 = HidP_TranslateUsage(uVar1,param_3,param_4,HidP_AssociativeLookup,
                                    &HidP_ConsumerToScanCodeTable,0x18000c670,param_5,param_6);
        if ((int)uVar3 != 0x110000) {
          return uVar3;
        }
      }
      uVar5 = uVar5 + 1;
      param_1 = param_1 + 2;
    } while (uVar5 < param_2);
  }
  return uVar3;
}



===== HidP_TranslateUsage @ 180004380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
HidP_TranslateUsage(undefined2 param_1,int param_2,uint *param_3,undefined *param_4,
                   undefined8 param_5,longlong param_6,undefined *param_7,undefined8 param_8)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  undefined8 *puVar4;
  
  uVar3 = (*(code *)param_4)(param_5,param_1);
  if (uVar3 == 0) {
    return 0xc0110009;
  }
  if (((*param_3 & 0x11) == 0) || (uVar3 != 0x451de1)) {
    if (((byte)uVar3 & 0xf0) == 0xf0) {
      puVar4 = (undefined8 *)((ulonglong)(uVar3 & 0xf) * 0x10 + param_6);
      pcVar1 = (code *)*puVar4;
      if (pcVar1 == (code *)0x0) {
        return 0xc0110009;
      }
      cVar2 = (*pcVar1)(puVar4[1],uVar3 >> 8 & 0xff,param_7,param_8,param_2,param_3);
      if (cVar2 == '\0') {
        return 0xc0110009;
      }
      return 0x110000;
    }
  }
  else {
    uVar3 = 0x46e0;
  }
  HidP_KbdPutKey(uVar3,param_2,param_7,param_8);
  return 0x110000;
}



===== HidP_KbdPutKey @ 180004450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HidP_KbdPutKey(undefined4 param_1,int param_2,undefined *param_3,undefined8 param_4)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 local_res8 [8];
  
  local_res8[0] = param_1;
  pbVar1 = (byte *)local_res8;
  uVar2 = 0;
  do {
    if (*pbVar1 == 0) break;
    if (param_2 == 0) {
      *pbVar1 = *pbVar1 | 0x80;
    }
    uVar2 = uVar2 + 1;
    pbVar1 = pbVar1 + 1;
  } while (uVar2 < 4);
  if (uVar2 != 0) {
    (*(code *)param_3)(param_4,local_res8);
  }
  return;
}



===== HidP_UsageAndPageListDifference @ 1800044a0 =====

undefined8
HidP_UsageAndPageListDifference
          (int *param_1,int *param_2,longlong param_3,longlong param_4,uint param_5)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  
                    /* 0x44a0  34  HidP_UsageAndPageListDifference */
  uVar5 = 0;
  uVar6 = 0;
  uVar8 = 0;
  if (param_5 != 0) {
    piVar4 = param_1;
    do {
      iVar1 = *piVar4;
      if (iVar1 == 0) break;
      for (uVar3 = 0; (uVar3 < param_5 && (param_2[uVar3] != 0)); uVar3 = uVar3 + 1) {
        if (param_2[uVar3] == iVar1) goto LAB_180004575;
      }
      uVar2 = (ulonglong)uVar6;
      uVar6 = uVar6 + 1;
      *(int *)(param_3 + uVar2 * 4) = iVar1;
LAB_180004575:
      uVar8 = uVar8 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar8 < param_5);
  }
  uVar8 = 0;
  if (param_5 != 0) {
    do {
      iVar1 = *param_2;
      if (iVar1 == 0) break;
      for (uVar3 = 0; (uVar3 < param_5 && (param_1[uVar3] != 0)); uVar3 = uVar3 + 1) {
        if (param_1[uVar3] == iVar1) goto LAB_1800045ac;
      }
      uVar2 = (ulonglong)uVar5;
      uVar5 = uVar5 + 1;
      *(int *)(param_4 + uVar2 * 4) = iVar1;
LAB_1800045ac:
      uVar8 = uVar8 + 1;
      param_2 = param_2 + 1;
    } while (uVar8 < param_5);
  }
  if (uVar6 < param_5) {
    puVar7 = (undefined4 *)(param_3 + (ulonglong)uVar6 * 4);
    for (uVar2 = (ulonglong)(param_5 - uVar6); uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
  }
  if (uVar5 < param_5) {
    puVar7 = (undefined4 *)(param_4 + (ulonglong)uVar5 * 4);
    for (uVar2 = (ulonglong)(param_5 - uVar5); uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
  }
  return 0x110000;
}



===== HidP_GetCaps @ 1800045d0 =====

undefined8 HidP_GetCaps(int *param_1,undefined8 *param_2)

{
  ushort uVar1;
  short sVar2;
  ulonglong uVar3;
  short *psVar4;
  short sVar5;
  uint uVar6;
  
                    /* 0x45d0  6  HidP_GetCaps */
  if (((param_1 == (int *)0x0) || (*param_1 != 0x50646948)) || (param_1[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  sVar5 = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  *(undefined2 *)((longlong)param_2 + 2) = *(undefined2 *)((longlong)param_1 + 10);
  *(short *)param_2 = (short)param_1[2];
  *(undefined2 *)((longlong)param_2 + 4) = *(undefined2 *)((longlong)param_1 + 0x16);
  *(undefined2 *)((longlong)param_2 + 6) = *(undefined2 *)((longlong)param_1 + 0x1e);
  *(undefined2 *)(param_2 + 1) = *(undefined2 *)((longlong)param_1 + 0x26);
  *(undefined2 *)((longlong)param_2 + 0x2c) = *(undefined2 *)((longlong)param_1 + 0x2a);
  *(undefined4 *)((longlong)param_2 + 0x2e) = 0;
  *(undefined4 *)((longlong)param_2 + 0x34) = 0;
  *(undefined4 *)((longlong)param_2 + 0x3a) = 0;
  uVar1 = *(ushort *)(param_1 + 4);
  uVar3 = (ulonglong)uVar1;
  *(undefined2 *)((longlong)param_2 + 0x32) = 0;
  if (uVar1 < *(ushort *)(param_1 + 5)) {
    sVar2 = 0;
    psVar4 = (short *)(uVar3 * 0x68 + 0x76 + (longlong)param_1);
    do {
      if ((*(uint *)(psVar4 + -0x19) & 4) == 0) {
        *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;
      }
      else {
        *(short *)((longlong)param_2 + 0x2e) = *(short *)((longlong)param_2 + 0x2e) + 1;
      }
      uVar6 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar6;
      sVar2 = (sVar2 - psVar4[-1]) + 1 + *psVar4;
      psVar4 = psVar4 + 0x34;
      *(short *)((longlong)param_2 + 0x32) = sVar2;
    } while (uVar6 < *(ushort *)(param_1 + 5));
  }
  uVar1 = *(ushort *)(param_1 + 6);
  uVar3 = (ulonglong)uVar1;
  *(undefined2 *)(param_2 + 7) = 0;
  if (uVar1 < *(ushort *)(param_1 + 7)) {
    sVar2 = 0;
    psVar4 = (short *)(uVar3 * 0x68 + 0x76 + (longlong)param_1);
    do {
      if ((*(uint *)(psVar4 + -0x19) & 4) == 0) {
        *(short *)((longlong)param_2 + 0x36) = *(short *)((longlong)param_2 + 0x36) + 1;
      }
      else {
        *(short *)((longlong)param_2 + 0x34) = *(short *)((longlong)param_2 + 0x34) + 1;
      }
      uVar6 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar6;
      sVar2 = (sVar2 - psVar4[-1]) + 1 + *psVar4;
      psVar4 = psVar4 + 0x34;
      *(short *)(param_2 + 7) = sVar2;
    } while (uVar6 < *(ushort *)(param_1 + 7));
  }
  uVar1 = *(ushort *)(param_1 + 8);
  uVar3 = (ulonglong)uVar1;
  *(undefined2 *)((longlong)param_2 + 0x3e) = 0;
  if (uVar1 < *(ushort *)(param_1 + 9)) {
    psVar4 = (short *)(uVar3 * 0x68 + 0x76 + (longlong)param_1);
    do {
      if ((*(uint *)(psVar4 + -0x19) & 4) == 0) {
        *(short *)((longlong)param_2 + 0x3c) = *(short *)((longlong)param_2 + 0x3c) + 1;
      }
      else {
        *(short *)((longlong)param_2 + 0x3a) = *(short *)((longlong)param_2 + 0x3a) + 1;
      }
      uVar6 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar6;
      sVar5 = (sVar5 - psVar4[-1]) + 1 + *psVar4;
      psVar4 = psVar4 + 0x34;
      *(short *)((longlong)param_2 + 0x3e) = sVar5;
    } while (uVar6 < *(ushort *)(param_1 + 9));
  }
  return 0x110000;
}



===== HidP_MaxUsageListLength @ 180004760 =====

int HidP_MaxUsageListLength(int param_1,ushort param_2,int *param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  
                    /* 0x4760  22  HidP_MaxUsageListLength */
  iVar6 = 0;
  if ((*param_3 != 0x50646948) && (param_3[1] != 0x52444b20)) {
    return 0;
  }
  if (param_1 == 0) {
    lVar4 = 0x10;
  }
  else if (param_1 == 1) {
    lVar4 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0;
    }
    lVar4 = 0x20;
  }
  uVar1 = *(ushort *)(lVar4 + (longlong)param_3);
  uVar2 = *(ushort *)(lVar4 + 4 + (longlong)param_3);
  if (uVar1 < uVar2) {
    puVar3 = (ushort *)((longlong)param_3 + (ulonglong)uVar1 * 0x68 + 0x32);
    uVar5 = (ulonglong)(ushort)(uVar2 - uVar1);
    do {
      if (((*(uint *)(puVar3 + 9) & 4) != 0) && ((param_2 == 0 || (puVar3[-3] == param_2)))) {
        iVar6 = iVar6 + (uint)*puVar3;
      }
      puVar3 = puVar3 + 0x34;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return iVar6;
}



===== HidP_StraightLookup @ 180004800 =====

undefined4 HidP_StraightLookup(longlong param_1,uint param_2)

{
  if (param_2 < 0x100) {
    return *(undefined4 *)(param_1 + (ulonglong)param_2 * 4);
  }
  return 0;
}



===== HidP_InitializeReportForID @ 180004820 =====

void HidP_InitializeReportForID(int param_1,char param_2,int *param_3,char *param_4,uint param_5)

{
                    /* 0x4820  20  HidP_InitializeReportForID */
  HidP_InitializeFields(param_1,param_2,param_3,param_4,param_5);
  return;
}



===== HidP_InitializeFields @ 180004840 =====

undefined8 HidP_InitializeFields(int param_1,char param_2,int *param_3,char *param_4,uint param_5)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  undefined8 uVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  longlong lVar9;
  uint uStack0000000000000030;
  
  uVar5 = 0xc0110010;
  if (((param_3 == (int *)0x0) || (*param_3 != 0x50646948)) || (param_3[1] != 0x52444b20)) {
    uVar5 = 0xc0110001;
  }
  else {
    if (param_1 == 1) {
      lVar9 = 0x18;
    }
    else if (param_1 == 0) {
      lVar9 = 0x10;
    }
    else {
      if (param_1 != 2) {
        return 0xc0110002;
      }
      lVar9 = 0x20;
    }
    sVar1 = *(short *)(lVar9 + 6 + (longlong)param_3);
    if ((short)param_5 == sVar1) {
      if (sVar1 == 0) {
        uVar5 = 0xc0110010;
      }
      else {
        memset(param_4,0,(ulonglong)param_5);
        *param_4 = param_2;
        uVar6 = (uint)*(ushort *)(lVar9 + (longlong)param_3);
        if (*(ushort *)(lVar9 + (longlong)param_3) < *(ushort *)(lVar9 + 4 + (longlong)param_3)) {
          puVar4 = (uint *)(param_3 + 0x11);
          do {
            if (*(char *)((longlong)puVar4 + -0x16) == param_2) {
              uVar5 = 0x110000;
              if (((*puVar4 & 0x26) == 0) && ((char)puVar4[0xd] != '\0')) {
                uVar7 = (ushort)puVar4[-5];
                if (uVar7 == 0x20) {
                  uVar2 = 0xffffffff;
                }
                else {
                  uVar2 = (1 << ((byte)puVar4[-5] & 0x1f)) - 1;
                }
                uVar3 = puVar4[0xe];
                if ((int)puVar4[0xf] < (int)uVar3) {
                  uVar2 = 0;
                }
                else {
                  uVar2 = uVar3 - 1 & uVar2;
                }
                if ((((int)uVar2 < (int)uVar3) || ((int)puVar4[0xf] < (int)uVar2)) && (uVar2 != 0))
                {
                  uStack0000000000000030 = uVar2;
                  if ((*puVar4 & 0x10) == 0) {
                    HidP_InsertData((ushort)puVar4[-4],(ushort)*(byte *)((longlong)puVar4 + -0x15),
                                    uVar7,(longlong)param_4,param_5,uVar2);
                  }
                  else {
                    uVar3 = (uint)*(byte *)((longlong)puVar4 + -0x15) + (uint)(ushort)puVar4[-4] * 8
                    ;
                    if (*(short *)((longlong)puVar4 + -0x12) != 0) {
                      uVar8 = 0;
                      do {
                        HidP_InsertData((ushort)(uVar3 >> 3),(ushort)uVar3 & 7,uVar7,
                                        (longlong)param_4,param_5,uVar2);
                        uVar7 = (ushort)puVar4[-5];
                        uVar8 = uVar8 + 1;
                        uVar3 = uVar3 + uVar7;
                      } while (uVar8 < *(ushort *)((longlong)puVar4 + -0x12));
                    }
                  }
                }
              }
            }
            uVar6 = uVar6 + 1;
            puVar4 = puVar4 + 0x1a;
          } while (uVar6 < *(ushort *)(lVar9 + 4 + (longlong)param_3));
        }
      }
    }
    else {
      uVar5 = 0xc0110003;
    }
  }
  return uVar5;
}



===== HidP_GetLinkCollectionNodes @ 180004aa0 =====

undefined4 HidP_GetLinkCollectionNodes(longlong param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  
                    /* 0x4aa0  11  HidP_GetLinkCollectionNodes */
  if (((param_3 == (int *)0x0) || (*param_3 != 0x50646948)) || (param_3[1] != 0x52444b20)) {
    return 0xc0110001;
  }
  uVar1 = *(ushort *)((longlong)param_3 + 0x2a);
  uVar5 = *param_2;
  uVar6 = (uint)uVar1;
  uVar2 = 0xc0110007;
  if (uVar6 <= uVar5) {
    uVar2 = 0x110000;
  }
  *param_2 = uVar6;
  if (uVar6 <= uVar5) {
    uVar5 = (uint)uVar1;
  }
  uVar6 = 0;
  if (uVar5 != 0) {
    puVar3 = (undefined2 *)(param_1 + 4);
    puVar4 = (undefined2 *)((ulonglong)*(ushort *)(param_3 + 10) + 0x2c + (longlong)param_3);
    do {
      uVar6 = uVar6 + 1;
      puVar3[-2] = *puVar4;
      puVar3[-1] = puVar4[1];
      *puVar3 = puVar4[2];
      puVar3[1] = puVar4[3];
      puVar3[2] = puVar4[4];
      puVar3[3] = puVar4[5];
      *(undefined1 *)(puVar3 + 4) = *(undefined1 *)(puVar4 + 6);
      *(uint *)(puVar3 + 4) =
           (*(uint *)(puVar3 + 4) ^ *(uint *)(puVar4 + 6)) & 0x100 ^ *(uint *)(puVar3 + 4);
      puVar3 = puVar3 + 0xc;
      puVar4 = puVar4 + 8;
    } while (uVar6 < uVar5);
  }
  return uVar2;
}



===== HidP_FreeCollectionDescription @ 180004b90 =====

void HidP_FreeCollectionDescription(longlong *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
                    /* 0x4b90  3  HidP_FreeCollectionDescription */
  uVar2 = 0;
  if ((int)param_1[1] != 0) {
    do {
      ExFreePool(*(undefined8 *)(*param_1 + 0x20 + uVar2 * 0x28));
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar1;
    } while (uVar1 < *(uint *)(param_1 + 1));
  }
  ExFreePool(*param_1);
  ExFreePool(param_1[2]);
  return;
}



===== HidP_SysPowerCaps @ 180004c00 =====

undefined8 HidP_SysPowerCaps(longlong param_1,undefined4 *param_2)

{
                    /* 0x4c00  29  HidP_SysPowerCaps */
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  return 0;
}



===== HidP_VendorBreakCodesAsMakeCodes @ 180004c10 =====

undefined8
HidP_VendorBreakCodesAsMakeCodes
          (longlong param_1,ulonglong param_2,undefined *param_3,undefined8 param_4,int param_5)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_5 == 0) {
    uVar2 = *(int *)(param_1 + (param_2 & 0xff) * 4) << 8 | 0xe1;
    iVar3 = 0;
  }
  else {
    if (param_5 != 1) {
      return (ulonglong)(uint3)((uint)param_5 >> 8) << 8;
    }
    iVar3 = 1;
    uVar2 = *(uint *)(param_1 + (param_2 & 0xff) * 4);
  }
  uVar1 = HidP_KbdPutKey(uVar2,iVar3,param_3,param_4);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== HidP_PrintScreenCode @ 180004c60 =====

undefined8
HidP_PrintScreenCode
          (longlong param_1,byte param_2,undefined *param_3,undefined8 param_4,int param_5,
          uint *param_6)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  if ((*param_6 & 0x44) == 0) {
    if ((*param_6 & 0x33) == 0) {
      if (param_5 == 1) {
        HidP_KbdPutKey(0x2ae0,1,param_3,param_4);
      }
      uVar1 = HidP_KbdPutKey(*(undefined4 *)(param_1 + (ulonglong)param_2 * 4),param_5,param_3,
                             param_4);
      if (param_5 != 0) goto LAB_180004ce2;
      param_5 = 0;
      uVar2 = 0x2ae0;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + (ulonglong)param_2 * 4);
    }
  }
  else {
    uVar2 = 0x54;
  }
  uVar1 = HidP_KbdPutKey(uVar2,param_5,param_3,param_4);
LAB_180004ce2:
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== HidP_DeleteArrayEntry @ 180004d10 =====

undefined8
HidP_DeleteArrayEntry
          (uint param_1,ushort param_2,ushort param_3,uint param_4,longlong param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = (uint)param_3;
  if (param_3 == 0) {
    if (param_4 == 0) {
      uVar2 = 0;
LAB_180004d7d:
      if (1 < uVar2) {
        uVar3 = (ulonglong)(uVar2 - 1);
        uVar2 = param_1;
        do {
          param_1 = param_2 + uVar2;
          uVar1 = HidP_ExtractData((short)(param_1 >> 3),(ushort)param_1 & 7,param_2,param_5);
          HidP_InsertData((ushort)(uVar2 >> 3),(ushort)uVar2 & 7,param_2,param_5,param_6,uVar1);
          uVar3 = uVar3 - 1;
          uVar2 = param_1;
        } while (uVar3 != 0);
      }
      HidP_InsertData((ushort)(param_1 >> 3),(ushort)param_1 & 7,param_2,param_5,param_6,0);
      return 0x110000;
    }
  }
  else {
    do {
      uVar1 = HidP_ExtractData((short)(param_1 >> 3),(ushort)param_1 & 7,param_2,param_5);
      if (param_4 == uVar1) goto LAB_180004d7d;
      param_1 = param_1 + param_2;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0xc011000f;
}



===== HidP_Usage2Index @ 180004e30 =====

int HidP_Usage2Index(ushort *param_1,ushort param_2)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  ushort uVar4;
  
  iVar3 = 0;
  uVar1 = *(uint *)(param_1 + 0xc);
  puVar2 = param_1;
  while ((uVar1 & 1) != 0) {
    uVar1 = *(uint *)(puVar2 + 0x40);
    puVar2 = puVar2 + 0x34;
  }
  puVar2 = puVar2 + 0x1e;
  do {
    if (puVar2 + -0x1e < param_1) {
      return 0;
    }
    uVar4 = *puVar2;
    if ((*(uint *)(puVar2 + -0x12) & 0x10) == 0) {
      iVar3 = iVar3 + 1;
      if (param_2 == uVar4) {
        return iVar3;
      }
    }
    else {
      if (uVar4 == 0) {
        uVar4 = 1;
      }
      if ((uVar4 <= param_2) && (param_2 <= puVar2[1])) {
        return ((uint)param_2 - (uint)uVar4) + 1 + iVar3;
      }
      iVar3 = iVar3 + 1 + ((uint)puVar2[1] - (uint)uVar4);
    }
    puVar2 = puVar2 + -0x34;
  } while( true );
}



===== __report_gsfailure @ 180004ed0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== Feature_1728472377__private_IsEnabledDeviceUsageNoInline @ 180004ee0 =====

ulonglong Feature_1728472377__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1728472377__private_featureState;
  if ((Feature_1728472377__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1728472377__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1728472377__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1728472377__private_IsEnabledFallback @ 180004f18 =====

void Feature_1728472377__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1728472377__private_descriptor);
  return;
}



===== Feature_2041211192__private_IsEnabledDeviceUsageNoInline @ 180004f34 =====

ulonglong Feature_2041211192__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2041211192__private_featureState;
  if ((Feature_2041211192__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2041211192__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2041211192__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2041211192__private_IsEnabledFallback @ 180004f6c =====

void Feature_2041211192__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2041211192__private_descriptor);
  return;
}



===== Feature_2176477499__private_IsEnabledDeviceUsageNoInline @ 180004f88 =====

ulonglong Feature_2176477499__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2176477499__private_featureState;
  if ((Feature_2176477499__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2176477499__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2176477499__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2176477499__private_IsEnabledFallback @ 180004fc0 =====

void Feature_2176477499__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2176477499__private_descriptor);
  return;
}



===== Feature_2804573496__private_IsEnabledDeviceUsageNoInline @ 180004fdc =====

ulonglong Feature_2804573496__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2804573496__private_featureState;
  if ((Feature_2804573496__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2804573496__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2804573496__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2804573496__private_IsEnabledFallback @ 180005014 =====

void Feature_2804573496__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2804573496__private_descriptor);
  return;
}



===== Feature_2873779512__private_IsEnabledDeviceUsageNoInline @ 180005030 =====

ulonglong Feature_2873779512__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2873779512__private_featureState;
  if ((Feature_2873779512__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2873779512__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2873779512__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2873779512__private_IsEnabledFallback @ 180005068 =====

void Feature_2873779512__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2873779512__private_descriptor);
  return;
}



===== Feature_3810682171__private_IsEnabledDeviceUsageNoInline @ 180005084 =====

ulonglong Feature_3810682171__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3810682171__private_featureState;
  if ((Feature_3810682171__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3810682171__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3810682171__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3810682171__private_IsEnabledFallback @ 1800050bc =====

void Feature_3810682171__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3810682171__private_descriptor);
  return;
}



===== Feature_3878577467__private_IsEnabledDeviceUsageNoInline @ 1800050d8 =====

ulonglong Feature_3878577467__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3878577467__private_featureState;
  if ((Feature_3878577467__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3878577467__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3878577467__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3878577467__private_IsEnabledFallback @ 180005110 =====

void Feature_3878577467__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3878577467__private_descriptor);
  return;
}



===== Feature_4123420985__private_IsEnabledDeviceUsageNoInline @ 18000512c =====

ulonglong Feature_4123420985__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_4123420985__private_featureState;
  if ((Feature_4123420985__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4123420985__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_4123420985__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4123420985__private_IsEnabledFallback @ 180005164 =====

void Feature_4123420985__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_4123420985__private_descriptor);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 180005180 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar4 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar4 | 1;
    if ((uVar4 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar3 = uVar4 >> 0xf & 0x7f;
      if (uVar3 != 0) {
        param_4[1] = uVar3;
        uVar3 = 5;
        if (param_2 != 1) {
          uVar3 = 1;
        }
        uVar1 = uVar4 & 0xffc07fff | 1;
        param_4[2] = uVar3;
      }
      uVar3 = 0;
      if (param_2 == 5) {
        uVar3 = 0x400000;
      }
      uVar1 = uVar3 | uVar1 & 0xffbfffff;
    }
    uVar2 = uVar1 >> 0xf & 0x7f;
    uVar3 = uVar2 + 1;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      uVar3 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar4 == uVar2) {
      *param_1 = (uVar3 << 0xf ^ uVar1) & 0x3f8000 ^ uVar1;
      uVar1 = uVar4;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar4 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar4 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 180005258 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar3 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar3 | 1;
    if ((uVar3 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar3 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar1 = uVar3 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar1 = uVar4 | uVar1 & 0xffffbfff;
    }
    uVar2 = uVar1 >> 5 & 0x1ff;
    uVar4 = uVar2 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar3 == uVar2) {
      *param_1 = (uVar4 << 5 ^ uVar1) & 0x3fe0 ^ uVar1;
      uVar1 = uVar3;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar3 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar3 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 18000533c =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_180005494:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_180005487:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_180005494;
      if (uVar5 == 5) goto LAB_180005487;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 1800054bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 180005540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_68;
  uint local_60 [6];
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_60,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_48 = *puVar2;
  uStack_44 = puVar2[1];
  uStack_40 = puVar2[2];
  uStack_3c = puVar2[3];
  local_38 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_78 = &local_48;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 180005630 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 180005740 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 1800057a4 =====

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



===== wil_details_IsEnabledFallback @ 180005904 =====

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



===== wil_details_MapReportingKind @ 180005998 =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 180005a38 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_18000b44f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 180005a60 =====

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



===== wil_details_RecordFeatureUsageReporting @ 180005bc0 =====

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



===== HidP_GetButtonArray @ 180005c50 =====

int HidP_GetButtonArray(int param_1,short param_2,short param_3,ushort param_4,void *param_5,
                       ushort *param_6,int *param_7,char *param_8,short param_9)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  int iVar9;
  longlong lVar10;
  
                    /* 0x5c50  4  HidP_GetButtonArray */
  uVar8 = 0;
  iVar9 = 0x110000;
  bVar2 = 0;
  if (((param_7 == (int *)0x0) || (*param_7 != 0x50646948)) || (param_7[1] != 0x52444b20)) {
    iVar9 = -0x3feeffff;
  }
  else {
    memset(param_5,0,(ulonglong)*param_6 << 2);
    if (param_1 == 0) {
      lVar4 = 0x10;
    }
    else if (param_1 == 1) {
      lVar4 = 0x18;
    }
    else {
      if (param_1 != 2) {
        return -0x3feefffe;
      }
      lVar4 = 0x20;
    }
    sVar1 = *(short *)(lVar4 + 6 + (longlong)param_7);
    if (sVar1 == 0) {
      iVar9 = -0x3feefff0;
    }
    else if (param_9 == sVar1) {
      uVar6 = *(ushort *)(lVar4 + (longlong)param_7);
      for (; uVar6 < *(ushort *)(lVar4 + 4 + (longlong)param_7); uVar6 = uVar6 + 1) {
        uVar5 = (ulonglong)uVar6;
        lVar10 = uVar5 * 0x68;
        if ((((param_7[uVar5 * 0x1a + 0x11] & 4U) != 0) &&
            ((param_2 == 0 || ((short)param_7[uVar5 * 0x1a + 0xb] == param_2)))) &&
           ((param_3 == 0 ||
            ((sVar1 = *(short *)(lVar10 + 0x3e + (longlong)param_7), param_3 == sVar1 ||
             ((param_3 == -1 && (sVar1 == 0)))))))) {
          if ((param_7[uVar5 * 0x1a + 0x11] & 0x10U) == 0) {
            if (*(ushort *)(param_7 + uVar5 * 0x1a + 0x1a) == param_4) {
              sVar1 = *(short *)(lVar10 + 0x32 + (longlong)param_7);
              if (sVar1 == 1) {
                return -0x3feeffdf;
              }
              if ((*param_8 == '\0') || (*(char *)(lVar10 + 0x2e + (longlong)param_7) == *param_8))
              {
                iVar3 = param_7[uVar5 * 0x1a + 0xd];
                uVar6 = 0;
                if (sVar1 != 0) {
                  do {
                    uVar7 = (ushort)*(byte *)(lVar10 + 0x2f + (longlong)param_7) + (short)iVar3 * 8
                            + uVar6;
                    if (((ushort)(short)param_8[uVar7 >> 3] >> (uVar7 & 7) & 1) != 0) {
                      if (uVar8 < *param_6) {
                        *(ushort *)((longlong)param_5 + (ulonglong)uVar8 * 4) = uVar6;
                        *(undefined1 *)((longlong)param_5 + (ulonglong)uVar8 * 4 + 2) = 1;
                      }
                      else {
                        iVar9 = -0x3feefff9;
                      }
                      uVar8 = uVar8 + 1;
                    }
                    uVar6 = uVar6 + 1;
                  } while (uVar6 < *(ushort *)(lVar10 + 0x32 + (longlong)param_7));
                }
                *param_6 = uVar8;
                goto LAB_180005e53;
              }
              bVar2 = 1;
            }
          }
          else if ((*(ushort *)(param_7 + uVar5 * 0x1a + 0x1a) <= param_4) &&
                  (param_4 <= *(ushort *)(lVar10 + 0x6a + (longlong)param_7))) {
            return -0x3feeffdf;
          }
        }
      }
      iVar9 = (-(uint)bVar2 & 6) + 0xc0110004;
    }
    else {
      iVar9 = -0x3feefffd;
    }
  }
LAB_180005e53:
  return iVar9;
}



===== HidP_GetButtonCaps @ 180005e80 =====

void HidP_GetButtonCaps(int param_1,longlong param_2,ushort *param_3,int *param_4)

{
                    /* 0x5e80  5  HidP_GetButtonCaps */
  HidP_GetSpecificButtonCaps(param_1,0,0,0,param_2,param_3,param_4);
  return;
}



===== HidP_GetExtendedAttributes @ 180005ec0 =====

int HidP_GetExtendedAttributes(int param_1,ushort param_2,int *param_3,void *param_4,uint *param_5)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  ulonglong local_28 [2];
  
                    /* 0x5ec0  10  HidP_GetExtendedAttributes */
  iVar6 = -0x3feefff3;
  if (((param_3 == (int *)0x0) || (*param_3 != 0x50646948)) || (param_3[1] != 0x52444b20)) {
    iVar6 = -0x3feeffff;
  }
  else {
    if (param_1 == 0) {
      lVar1 = 0x10;
    }
    else if (param_1 == 1) {
      lVar1 = 0x18;
    }
    else {
      if (param_1 != 2) {
        return -0x3feefffe;
      }
      lVar1 = 0x20;
    }
    piVar5 = param_3 + 0xb;
    for (uVar2 = (uint)*(ushort *)(lVar1 + (longlong)param_3);
        uVar2 < *(ushort *)(lVar1 + 4 + (longlong)param_3); uVar2 = uVar2 + 1) {
      if ((*(ushort *)(piVar5 + 0x12) <= param_2) &&
         (param_2 <= *(ushort *)((longlong)piVar5 + 0x4a))) {
        memset(param_4,0,(ulonglong)*param_5);
        local_28[1] = 0;
        local_28[0] = (ulonglong)(byte)((uint)piVar5[6] >> 0x1c);
        uVar2 = ((uint)piVar5[6] >> 0x1c) * 8 + 0xc;
        uVar4 = 0x10;
        if (*param_5 < 0x10) {
          uVar4 = *param_5;
        }
        memmove(param_4,local_28,(ulonglong)uVar4);
        uVar4 = *param_5;
        uVar3 = uVar4;
        if (uVar2 <= uVar4) {
          uVar3 = uVar2;
        }
        uVar3 = uVar3 - 0xc;
        if (uVar3 != 0) {
          if (uVar2 <= uVar4) {
            uVar4 = uVar2;
          }
          if (uVar3 <= uVar4) {
            memmove((void *)((longlong)param_4 + 0xc),piVar5 + 7,(ulonglong)uVar3);
          }
        }
        iVar6 = (-(uint)(*param_5 < uVar2) & 0xc0000007) + 0x110000;
        break;
      }
      piVar5 = piVar5 + 0x1a;
    }
  }
  return iVar6;
}



===== HidP_MaxDataListLength @ 180006010 =====

int HidP_MaxDataListLength(int param_1,int *param_2)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  ushort *puVar4;
  uint uVar5;
  ulonglong uVar6;
  int iVar7;
  
                    /* 0x6010  21  HidP_MaxDataListLength */
  iVar7 = 0;
  if ((*param_2 != 0x50646948) && (param_2[1] != 0x52444b20)) {
    return 0;
  }
  if (param_1 == 0) {
    lVar3 = 0x10;
  }
  else if (param_1 == 1) {
    lVar3 = 0x18;
  }
  else {
    if (param_1 != 2) {
      return 0;
    }
    lVar3 = 0x20;
  }
  uVar1 = *(ushort *)(lVar3 + (longlong)param_2);
  uVar2 = *(ushort *)(lVar3 + 4 + (longlong)param_2);
  if (uVar1 < uVar2) {
    puVar4 = (ushort *)((longlong)param_2 + (ulonglong)uVar1 * 0x68 + 0x32);
    uVar6 = (ulonglong)(ushort)(uVar2 - uVar1);
    do {
      if (((*(uint *)(puVar4 + 9) & 4) == 0) && ((*(uint *)(puVar4 + 9) & 0x10) == 0)) {
        uVar5 = 1;
      }
      else {
        uVar5 = (uint)*puVar4;
      }
      iVar7 = iVar7 + uVar5;
      puVar4 = puVar4 + 0x34;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return iVar7;
}



===== HidP_SetButtonArray @ 1800060a0 =====

int HidP_SetButtonArray(int param_1,short param_2,short param_3,ushort param_4,longlong param_5,
                       ushort param_6,int *param_7,char *param_8,uint param_9)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  byte bVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
                    /* 0x60a0  23  HidP_SetButtonArray */
  iVar12 = 0x110000;
  bVar1 = 0;
  if (((param_7 == (int *)0x0) || (*param_7 != 0x50646948)) || (param_7[1] != 0x52444b20)) {
    iVar12 = -0x3feeffff;
  }
  else {
    if (param_1 == 0) {
      lVar6 = 0x10;
    }
    else if (param_1 == 1) {
      lVar6 = 0x18;
    }
    else {
      if (param_1 != 2) {
        return -0x3feefffe;
      }
      lVar6 = 0x20;
    }
    sVar2 = *(short *)(lVar6 + 6 + (longlong)param_7);
    if (sVar2 == 0) {
      iVar12 = -0x3feefff0;
    }
    else if ((short)param_9 == sVar2) {
      for (uVar9 = *(ushort *)(lVar6 + (longlong)param_7);
          uVar9 < *(ushort *)(lVar6 + 4 + (longlong)param_7); uVar9 = uVar9 + 1) {
        uVar7 = (ulonglong)uVar9;
        lVar8 = uVar7 * 0x68;
        if ((((param_7[uVar7 * 0x1a + 0x11] & 4U) != 0) &&
            ((param_2 == 0 || ((short)param_7[uVar7 * 0x1a + 0xb] == param_2)))) &&
           ((param_3 == 0 ||
            ((sVar2 = *(short *)(lVar8 + 0x3e + (longlong)param_7), param_3 == sVar2 ||
             ((param_3 == -1 && (sVar2 == 0)))))))) {
          if ((param_7[uVar7 * 0x1a + 0x11] & 0x10U) == 0) {
            if (*(ushort *)(param_7 + uVar7 * 0x1a + 0x1a) == param_4) {
              if (*(short *)(lVar8 + 0x32 + (longlong)param_7) == 1) {
                return -0x3feeffdf;
              }
              if ((*param_8 == '\0') || (*(char *)(lVar8 + 0x2e + (longlong)param_7) == *param_8)) {
                iVar4 = param_7[uVar7 * 0x1a + 0xd];
                uVar9 = 0;
                bVar1 = *(byte *)(lVar8 + 0x2f + (longlong)param_7);
                goto LAB_18000620d;
              }
              bVar1 = 1;
            }
          }
          else if ((*(ushort *)(param_7 + uVar7 * 0x1a + 0x1a) <= param_4) &&
                  (param_4 <= *(ushort *)(lVar8 + 0x6a + (longlong)param_7))) {
            return -0x3feeffdf;
          }
        }
      }
      iVar12 = (-(uint)bVar1 & 6) + 0xc0110004;
    }
    else {
LAB_18000627b:
      iVar12 = -0x3feefffd;
    }
  }
LAB_180006287:
  return iVar12;
LAB_18000620d:
  if (param_6 <= uVar9) goto LAB_180006287;
  uVar3 = *(ushort *)(param_5 + (ulonglong)uVar9 * 4);
  if (*(ushort *)(lVar8 + 0x32 + (longlong)param_7) < uVar3) {
    return -0x3feefff2;
  }
  uVar10 = (uint)uVar3 + (uint)(ushort)((short)iVar4 * 8 + (ushort)bVar1);
  uVar11 = uVar10 & 7;
  uVar10 = uVar10 >> 3;
  if (param_9 <= uVar10) goto LAB_18000627b;
  if (*(char *)(param_5 + 2 + (ulonglong)uVar9 * 4) == '\0') {
    bVar5 = param_8[uVar10] & ~(byte)(1 << uVar11);
  }
  else {
    bVar5 = param_8[uVar10] | (byte)(1 << uVar11);
  }
  param_8[uVar10] = bVar5;
  uVar9 = uVar9 + 1;
  goto LAB_18000620d;
}



===== HidP_AssociativeLookup @ 1800062b0 =====

undefined4 HidP_AssociativeLookup(longlong param_1,int param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  while( true ) {
    uVar1 = (uint)uVar2;
    if (0xe < uVar1) {
      return 0;
    }
    if (param_2 == *(int *)(param_1 + uVar2 * 4)) break;
    uVar2 = (ulonglong)(uVar1 + 2);
  }
  return *(undefined4 *)(param_1 + (ulonglong)(uVar1 + 1) * 4);
}



===== HidP_TranslateUsagesToI8042ScanCodes @ 1800062e0 =====

undefined8
HidP_TranslateUsagesToI8042ScanCodes
          (short *param_1,uint param_2,int param_3,uint *param_4,undefined *param_5,
          undefined8 param_6)

{
  undefined8 uVar1;
  uint uVar2;
  
                    /* 0x62e0  32  HidP_TranslateUsagesToI8042ScanCodes */
  uVar1 = 0x110000;
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      if (*param_1 == 0) {
        return uVar1;
      }
      uVar1 = HidP_TranslateUsage(*param_1,param_3,param_4,HidP_StraightLookup,
                                  &HidP_KeyboardToScanCodeTable,0x18000c000,param_5,param_6);
      if ((int)uVar1 != 0x110000) {
        return uVar1;
      }
      uVar2 = uVar2 + 1;
      param_1 = param_1 + 1;
    } while (uVar2 < param_2);
  }
  return uVar1;
}



===== GetImageTuple @ 18000639c =====

/* WARNING: Removing unreachable block (ram,0x0001800063d2) */

undefined8 GetImageTuple(undefined8 param_1,dword *param_2,dword *param_3)

{
  *param_2 = 0xe0cc8dde;
  *param_3 = 0x19000;
  return 1;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 1800063ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 InitializeTelemetryAssertsKMWorkerInternal(ushort *param_1)

{
  undefined8 uVar1;
  
  KeInitializeSpinLock(&g_AssertSpinLock);
  uVar1 = 0;
  g_ModuleName = (void *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 1,0x74727341);
  if (g_ModuleName == (void *)0x0) {
    uVar1 = 0xc0000017;
  }
  else {
    memmove(g_ModuleName,*(void **)(param_1 + 4),(ulonglong)*param_1);
    _DAT_18000c698 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x18000f040);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x18000f008);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x18000f078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 1800064a0 =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  ulonglong unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,0,param_2,param_3,param_4);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 1800064d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,char *param_6)

{
  ulonglong uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  char cVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  ulonglong *puVar11;
  ulonglong *puVar12;
  undefined8 uVar13;
  char *pcVar14;
  ulonglong *puVar15;
  longlong *plVar16;
  uint uVar17;
  undefined1 *puVar18;
  ulonglong uVar19;
  char *pcVar20;
  undefined1 auStack_1b8 [8];
  undefined1 auStack_1b0 [120];
  undefined4 local_138;
  char *local_130;
  char *local_128;
  undefined1 local_118 [32];
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  longlong local_b8 [2];
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  longlong local_78 [2];
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
  puVar18 = auStack_1b8;
  local_38 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_128 = param_6;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_180006a75;
  local_138 = param_4;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar18 = auStack_1b8;
  for (puVar12 = g_MicrosoftTelemetryAssertsTriggeredList;
      (ulonglong **)puVar12 != &g_MicrosoftTelemetryAssertsTriggeredList;
      puVar12 = (ulonglong *)*puVar12) {
    puVar11 = puVar12 + -4;
    if (*puVar11 == param_1) goto LAB_180006617;
  }
  puVar11 = (ulonglong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar3 = _DAT_fffff78000000320;
  puVar18 = auStack_1b8;
  if (puVar11 != (ulonglong *)0x0) {
    *puVar11 = param_1;
    uVar8 = KeQueryTimeIncrement();
    puVar18 = auStack_1b8;
    *(undefined4 *)(puVar11 + 2) = 0;
    *(undefined4 *)((longlong)puVar11 + 0x14) = 0;
    *(undefined4 *)(puVar11 + 3) = 0;
    puVar11[1] = (longlong)((ulonglong)uVar8 * lVar3) / 10000 - 0xea61;
    puVar12 = puVar11 + 4;
    puVar15 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((ulonglong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      puVar15 = (ulonglong *)0x3;
      pcVar2 = (code *)swi(0x29);
      puVar12 = (ulonglong *)(*pcVar2)();
      puVar18 = auStack_1b0;
    }
    *puVar12 = (ulonglong)puVar15;
    puVar12[1] = (ulonglong)&g_MicrosoftTelemetryAssertsTriggeredList;
    puVar15[1] = (ulonglong)puVar12;
    g_MicrosoftTelemetryAssertsTriggeredList = puVar12;
LAB_180006617:
    *(int *)(puVar11 + 2) = (int)puVar11[2] + 1;
    *(int *)((longlong)puVar11 + 0x14) = *(int *)((longlong)puVar11 + 0x14) + 1;
    lVar3 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar18 + -8) = 0x180006627;
    uVar8 = KeQueryTimeIncrement();
    *(undefined4 *)(puVar18 + 0x54) = 0;
    *(undefined4 *)(puVar18 + 0x50) = 0;
    uVar19 = (longlong)((ulonglong)uVar8 * lVar3) / 10000;
    if (60000 < uVar19 - puVar11[1]) {
      *(undefined8 *)(puVar18 + -8) = 0x180006675;
      uVar13 = GetImageTuple((ulonglong)uVar8 * lVar3,(dword *)(puVar18 + 0x54),
                             (dword *)(puVar18 + 0x50));
      uVar8 = *(uint *)(puVar18 + 0x50);
      iVar9 = (int)uVar13;
      if ((((iVar9 == 0) || (param_1 < 0x180000000)) ||
          (uVar1 = (ulonglong)uVar8 + 0x180000000, uVar1 < 0x180000001)) || (uVar1 < param_1)) {
        uVar17 = 0;
      }
      else {
        uVar17 = (int)param_1 + 0x80000000;
      }
      *(int *)(puVar18 + 0x50) = (int)puVar11[2];
      puVar11[1] = uVar19;
      uVar19 = puVar11[3];
      *(undefined4 *)(puVar18 + 0x7c) = *(undefined4 *)((longlong)puVar11 + 0x14);
      *(undefined8 *)(puVar18 + -8) = 0x1800066c9;
      KeReleaseSpinLock(&g_AssertSpinLock,uVar5);
      local_130 = g_ModuleName;
      if (5 < DAT_18000f040) {
        *(undefined8 *)(puVar18 + -8) = 0x180006703;
        pcVar20 = g_ModuleName;
        cVar6 = _tlgKeywordOn(0x18000f040,0x400000000000);
        uVar13 = 0;
        if (cVar6 != '\0') {
          local_f8 = puVar18 + 0x58;
          *(undefined4 *)(puVar18 + 0x58) = 10;
          local_e8 = puVar18 + 0x5c;
          local_f0 = 4;
          *(uint *)(puVar18 + 0x5c) = uVar17;
          local_d8 = puVar18 + 0x60;
          local_e0 = 4;
          *(uint *)(puVar18 + 0x60) = -(uint)(iVar9 != 0) & *(uint *)(puVar18 + 0x54);
          local_c8 = puVar18 + 100;
          local_d0 = 4;
          local_c0 = 4;
          *(uint *)(puVar18 + 100) = -(uint)(iVar9 != 0) & uVar8;
          pcVar14 = "<unknown>";
          if (pcVar20 != (char *)0x0) {
            pcVar14 = pcVar20;
          }
          *(undefined8 *)(puVar18 + -8) = 0x18000678e;
          _tlgCreate1Sz_char(local_b8,pcVar14);
          local_a8 = puVar18 + 0x68;
          *(undefined4 *)(puVar18 + 0x6c) = *(undefined4 *)(puVar18 + 0x7c);
          local_98 = puVar18 + 0x6c;
          *(undefined4 *)(puVar18 + 0x68) = *(undefined4 *)(puVar18 + 0x50);
          local_a0 = 4;
          local_90 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x1800067c7;
          bVar7 = KeGetCurrentIrql();
          *(uint *)(puVar18 + 0x70) = (uint)bVar7;
          local_88 = puVar18 + 0x70;
          local_80 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x1800067f1;
          _tlgCreate1Sz_char(local_78,local_130);
          uVar4 = local_138;
          local_68 = puVar18 + 0x74;
          *(undefined4 *)(puVar18 + 0x78) = param_5;
          local_58 = puVar18 + 0x78;
          *(undefined4 *)(puVar18 + 0x74) = uVar4;
          local_60 = 4;
          pcVar14 = local_128;
          if (local_128 == (char *)0x0) {
            pcVar14 = "<unknown>";
          }
          local_50 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x18000683b;
          _tlgCreate1Sz_char(local_48,pcVar14);
          *(undefined1 **)(puVar18 + 0x28) = local_118;
          *(undefined4 *)(puVar18 + 0x20) = 0xe;
          *(undefined8 *)(puVar18 + -8) = 0x180006858;
          _tlgWriteTransfer_EtwWriteTransfer
                    (local_118,&DAT_1800096b9,uVar13,pcVar20,*(undefined4 *)(puVar18 + 0x20),
                     *(undefined8 **)(puVar18 + 0x28));
        }
      }
      if ((DAT_18000f078 == 0) || ((int)uVar19 != 0)) goto LAB_180006a75;
      *(undefined8 *)(puVar18 + -8) = 0x180006877;
      cVar6 = KeGetCurrentIrql();
      if (cVar6 != '\0') goto LAB_180006a75;
      *(undefined4 *)(puVar18 + 0x40) = 0;
      *(undefined8 *)(puVar18 + 0x38) = 0;
      *(undefined8 *)(puVar18 + 0x30) = 0;
      *(ulonglong *)(puVar18 + 0x28) = (ulonglong)uVar8;
      *(ulonglong *)(puVar18 + 0x20) = (ulonglong)*(uint *)(puVar18 + 0x54);
      uVar19 = (ulonglong)uVar17;
      *(undefined8 *)(puVar18 + -8) = 0x1800068c1;
      pcVar20 = g_ModuleName;
      iVar10 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      if (5 < DAT_18000f040) {
        *(undefined8 *)(puVar18 + -8) = 0x1800068eb;
        cVar6 = _tlgKeywordOn(0x18000f040,0x400000000000);
        if (cVar6 != '\0') {
          local_f8 = puVar18 + 0x78;
          *(undefined4 *)(puVar18 + 0x78) = 10;
          local_e8 = puVar18 + 0x74;
          local_f0 = 4;
          local_d8 = puVar18 + 0x70;
          *(uint *)(puVar18 + 0x74) = uVar17;
          *(uint *)(puVar18 + 0x70) = -(uint)(iVar9 != 0) & *(uint *)(puVar18 + 0x54);
          local_e0 = 4;
          local_d0 = 4;
          local_c0 = 4;
          *(uint *)(puVar18 + 0x6c) = -(uint)(iVar9 != 0) & uVar8;
          local_c8 = puVar18 + 0x6c;
          pcVar14 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar14 = g_ModuleName;
          }
          *(undefined8 *)(puVar18 + -8) = 0x180006978;
          _tlgCreate1Sz_char(local_b8,pcVar14);
          plVar16 = local_78;
          *(undefined4 *)(puVar18 + 0x68) = *(undefined4 *)(puVar18 + 0x50);
          local_a8 = puVar18 + 0x68;
          *(undefined4 *)(puVar18 + 100) = *(undefined4 *)(puVar18 + 0x7c);
          local_98 = puVar18 + 100;
          local_88 = puVar18 + 0x60;
          local_a0 = 4;
          local_90 = 4;
          *(int *)(puVar18 + 0x60) = iVar10;
          local_80 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x1800069cc;
          _tlgCreate1Sz_char(plVar16,local_130);
          *(undefined4 *)(puVar18 + 0x5c) = local_138;
          local_68 = puVar18 + 0x5c;
          *(undefined4 *)(puVar18 + 0x58) = param_5;
          local_58 = puVar18 + 0x58;
          *(undefined1 **)(puVar18 + 0x28) = local_118;
          *(undefined4 *)(puVar18 + 0x20) = 0xd;
          local_60 = 4;
          local_50 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x180006a1c;
          _tlgWriteTransfer_EtwWriteTransfer
                    (plVar16,&DAT_180009763,uVar19,pcVar20,*(undefined4 *)(puVar18 + 0x20),
                     *(undefined8 **)(puVar18 + 0x28));
        }
      }
      if (iVar10 != 0) goto LAB_180006a75;
      *(undefined8 *)(puVar18 + -8) = 0x180006a2e;
      uVar5 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      puVar12 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((ulonglong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if (puVar12[-4] == param_1) {
            *(int *)(puVar12 + -1) = (int)puVar12[-1] + 1;
            break;
          }
          puVar12 = (ulonglong *)*puVar12;
        } while ((ulonglong **)puVar12 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar18 + -8) = 0x180006a70;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar5);
LAB_180006a75:
  *(undefined8 *)(puVar18 + -8) = 0x180006a84;
  return;
}



===== UninitializeTelemetryAssertsKM @ 180006aa8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UninitializeTelemetryAssertsKM(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  LOCK();
  UNLOCK();
  if (g_AssertsOperational != 0) {
    LOCK();
    g_AssertsOperational = g_AssertsOperational + -1;
    UNLOCK();
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
    puVar6 = auStack_28;
    while ((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList !=
           &g_MicrosoftTelemetryAssertsTriggeredList) {
      if (((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
           &g_MicrosoftTelemetryAssertsTriggeredList) ||
         (puVar1 = (undefined8 *)*g_MicrosoftTelemetryAssertsTriggeredList,
         (undefined8 *)puVar1[1] != g_MicrosoftTelemetryAssertsTriggeredList)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar6 = auStack_20;
        break;
      }
      puVar5 = g_MicrosoftTelemetryAssertsTriggeredList + -4;
      g_MicrosoftTelemetryAssertsTriggeredList = puVar1;
      puVar1[1] = &g_MicrosoftTelemetryAssertsTriggeredList;
      ExFreePoolWithTag(puVar5,0x74727341);
    }
    *(undefined8 *)(puVar6 + -8) = 0x180006b3b;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x180006b58;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_18000f098;
    DAT_18000f098 = 0;
    DAT_18000f078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x180006b82;
    EtwUnregister(uVar3);
    uVar3 = DAT_18000f028;
    DAT_18000f028 = 0;
    _DAT_18000f008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x180006ba4;
    EtwUnregister(uVar3);
    uVar3 = DAT_18000f060;
    DAT_18000f060 = 0;
    DAT_18000f040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x180006bc6;
    EtwUnregister(uVar3);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 180006be0 =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== _guard_check_icall @ 180006c00 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 180006c18 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 180006c3c =====

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



===== __cpu_features_init @ 180006cb0 =====

/* WARNING: Removing unreachable block (ram,0x000180006d1a) */
/* WARNING: Removing unreachable block (ram,0x000180006cc9) */
/* WARNING: Removing unreachable block (ram,0x000180006cba) */

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



===== __security_check_cookie @ 180006d80 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 180006dc0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 180006df0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180006df0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 180006e20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 180006e80 =====

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



===== memset @ 180007180 =====

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



===== __memset_repmovs @ 1800072c0 =====

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



===== __memset_query @ 180007340 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1800073c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 180007500 =====

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



===== __memset_spec_plain @ 180007580 =====

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



===== HidP_GetCollectionDescription2 @ 180010010 =====

void HidP_GetCollectionDescription2
               (longlong param_1,uint param_2,undefined4 param_3,longlong *param_4)

{
                    /* 0x10010  8  HidP_GetCollectionDescription2 */
  HidP_GetCollectionDescriptionInternal(param_1,param_2,param_3,param_4,'\x01');
  return;
}



===== HidP_GetCollectionDescriptionInternal @ 18001002c =====

ulonglong HidP_GetCollectionDescriptionInternal
                    (longlong param_1,uint param_2,undefined4 param_3,longlong *param_4,char param_5
                    )

{
  uint *puVar1;
  undefined8 *puVar2;
  ushort *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  void *_Dst;
  ulonglong uVar7;
  uint local_res20 [2];
  uint *puVar8;
  ushort *local_38 [2];
  
  local_38[0] = (ushort *)0x0;
  local_res20[0] = 0;
  memset(param_4,0,0x40);
  puVar8 = local_res20;
  puVar1 = (uint *)((longlong)param_4 + 0x1c);
  uVar6 = HidP_AllocateCollections
                    (param_1,param_2,param_3,local_38,puVar8,puVar1,(longlong)param_4,param_5);
  uVar7 = uVar6 & 0xffffffff;
  if (local_res20[0] == 0) {
    uVar7 = 0x80000022;
  }
  else if (-1 < (int)uVar6) {
    uVar6 = HidP_ParseCollections
                      (param_1,param_2,param_3,local_38[0],
                       CONCAT44((int)((ulonglong)puVar8 >> 0x20),local_res20[0]),puVar1,
                       (longlong)param_4,param_5);
    uVar7 = uVar6 & 0xffffffff;
    if (-1 < (int)uVar6) {
      _Dst = (void *)ExAllocatePoolWithTag(param_3,(ulonglong)local_res20[0] * 0x28,0x50646948);
      *param_4 = (longlong)_Dst;
      if (_Dst != (void *)0x0) {
        memset(_Dst,0,(ulonglong)local_res20[0] * 0x28);
        uVar6 = 0;
        *(uint *)(param_4 + 1) = local_res20[0];
        if (local_38[0] != (ushort *)0x0) {
          while( true ) {
            puVar3 = *(ushort **)(local_38[0] + 0x14);
            local_res20[0] = (int)uVar6 + 1;
            uVar5 = *(undefined8 *)(local_38[0] + 4);
            lVar4 = *param_4;
            puVar2 = (undefined8 *)(lVar4 + uVar6 * 0x28);
            *puVar2 = *(undefined8 *)local_38[0];
            puVar2[1] = uVar5;
            uVar5 = *(undefined8 *)(local_38[0] + 0xc);
            puVar2 = (undefined8 *)(lVar4 + 0x10 + uVar6 * 0x28);
            *puVar2 = *(undefined8 *)(local_38[0] + 8);
            puVar2[1] = uVar5;
            *(undefined8 *)(lVar4 + 0x20 + uVar6 * 0x28) = *(undefined8 *)(local_38[0] + 0x10);
            HidP_AssignDataIndices(*(longlong *)(local_38[0] + 0x10));
            ExFreePool(local_38[0]);
            if (puVar3 == (ushort *)0x0) break;
            uVar6 = (ulonglong)local_res20[0];
            local_38[0] = puVar3;
          }
        }
        return 0;
      }
      uVar7 = 0xc000009a;
      *puVar1 = param_2;
      *(undefined4 *)(param_4 + 4) = 1;
    }
  }
  while (local_38[0] != (ushort *)0x0) {
    puVar3 = *(ushort **)(local_38[0] + 0x14);
    if (*(longlong *)(local_38[0] + 0x10) != 0) {
      ExFreePool();
    }
    ExFreePool(local_38[0]);
    local_38[0] = puVar3;
  }
  if (param_4[2] != 0) {
    ExFreePool();
  }
  return uVar7;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 180010228 =====

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



===== DllUnload @ 180010300 =====

undefined8 DllUnload(void)

{
                    /* 0x10300  2  DllUnload */
  UninitializeTelemetryAssertsKM();
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return 0;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 180010360 =====

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
      goto LAB_1800103bd;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1800103bd;
    }
  }
  uVar1 = 0x206;
LAB_1800103bd:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1800103c8 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_2176477499__private_descriptor);
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &Feature_2176477499__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 180010480 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1800104b8 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_18001053a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_18001053a;
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
LAB_18001053a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 180010590 =====

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
      ppuVar3 = &Feature_2176477499__private_descriptor;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1800105f0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 18001060c =====

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
  ppuVar3 = &Feature_2176477499__private_descriptor;
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



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1800106c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(longlong param_1)

{
  longlong *plVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  code *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar7 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar3 = *(longlong *)(param_1 + 8);
  plVar1 = (longlong *)(param_1 + 0x20);
  local_28 = *(undefined4 *)(lVar3 + -0x10);
  uStack_24 = *(undefined4 *)(lVar3 + -0xc);
  uStack_20 = *(undefined4 *)(lVar3 + -8);
  uStack_1c = *(undefined4 *)(lVar3 + -4);
  if (*plVar1 != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar7 = auStack_40;
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x180010723;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x180010743;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x180010757;
  return iVar6;
}



===== _tlgEnableCallback @ 180010770 =====

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



===== HidP_PushUsageList @ 1800107f0 =====

undefined8 * HidP_PushUsageList(char *param_1,undefined4 param_2,char param_3)

{
  undefined8 *puVar1;
  char cVar2;
  
  puVar1 = (undefined8 *)ExAllocatePoolWithTag(param_2,0x18,0x50646948);
  if (puVar1 == (undefined8 *)0x0) {
    HidP_FreeUsageList((undefined8 *)param_1);
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = param_1;
    if (param_3 == '\0') {
      if (*param_1 == '\0') {
        cVar2 = '\x01';
      }
      else {
        cVar2 = (param_1[8] - param_1[6]) + '\x01';
      }
      cVar2 = cVar2 + param_1[10];
    }
    else {
      cVar2 = param_1[10];
    }
    *(char *)((longlong)puVar1 + 10) = cVar2;
  }
  return puVar1;
}



===== HidP_FreeUsageList @ 180010880 =====

undefined8 * HidP_FreeUsageList(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)param_1[2];
  while (puVar1 = puVar2, puVar1 != (undefined8 *)0x0) {
    ExFreePool(param_1);
    param_1 = puVar1;
    puVar2 = (undefined8 *)puVar1[2];
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



===== HidP_AssignDataIndices @ 1800108d0 =====

void HidP_AssignDataIndices(longlong param_1)

{
  uint *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  short sVar5;
  ushort uVar6;
  ulonglong uVar7;
  ushort *puVar8;
  
  puVar8 = (ushort *)(param_1 + 0x10);
  while( true ) {
    while( true ) {
      uVar7 = (ulonglong)*puVar8;
      sVar5 = 0;
      uVar2 = uVar7 * 0x68 + 0x2c + param_1;
      if (*puVar8 < puVar8[2]) {
        do {
          uVar6 = (ushort)uVar7;
          if ((*(uint *)(uVar2 + 0x18) & 1) == 0) {
            *(short *)(uVar2 + 0x48) = sVar5;
            sVar5 = sVar5 + (*(short *)(uVar2 + 0x3e) - *(short *)(uVar2 + 0x3c));
            *(short *)(uVar2 + 0x4a) = sVar5;
            sVar5 = sVar5 + 1;
            uVar3 = uVar2;
          }
          else {
            uVar4 = uVar2;
            do {
              uVar3 = uVar4 + 0x68;
              uVar6 = (short)uVar7 + 1;
              uVar7 = (ulonglong)uVar6;
              puVar1 = (uint *)(uVar4 + 0x80);
              uVar4 = uVar3;
            } while ((*puVar1 & 1) != 0);
            do {
              *(short *)(uVar4 + 0x48) = sVar5;
              sVar5 = sVar5 + (*(short *)(uVar4 + 0x3e) - *(short *)(uVar4 + 0x3c));
              *(short *)(uVar4 + 0x4a) = sVar5;
              sVar5 = sVar5 + 1;
              uVar4 = uVar4 - 0x68;
            } while (uVar2 <= uVar4);
          }
          uVar7 = (ulonglong)(ushort)(uVar6 + 1);
          uVar2 = uVar3 + 0x68;
        } while ((ushort)(uVar6 + 1) < puVar8[2]);
      }
      if ((ushort *)(param_1 + 0x10) != puVar8) break;
      puVar8 = (ushort *)(param_1 + 0x18);
    }
    if ((ushort *)(param_1 + 0x18) != puVar8) break;
    puVar8 = (ushort *)(param_1 + 0x20);
  }
  return;
}



===== HidP_AllocateCollections @ 1800109c0 =====

undefined8
HidP_AllocateCollections
          (longlong param_1,uint param_2,undefined4 param_3,undefined8 *param_4,uint *param_5,
          uint *param_6,longlong param_7,char param_8)

{
  byte bVar1;
  undefined4 *puVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  ushort uVar9;
  ushort uVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  void *pvVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  ulonglong uVar20;
  byte bVar21;
  short sVar22;
  ushort uVar23;
  int iVar24;
  byte local_58;
  int local_44;
  undefined8 *local_40;
  
  bVar21 = 0;
  bVar6 = false;
  local_58 = 0;
  *param_5 = 0;
  uVar10 = 0;
  uVar23 = 0;
  local_40 = (undefined8 *)0x0;
  local_44 = 0;
  uVar15 = 0;
  uVar4 = 0;
  uVar5 = 0;
  sVar22 = 0;
  uVar3 = 0;
  bVar7 = false;
  bVar8 = false;
  uVar12 = 0;
  iVar17 = 0;
  if (param_2 == 0) {
LAB_1800111fd:
    if ((uint)bVar21 < *param_5) {
      *param_6 = uVar15;
      param_6[1] = 0x15;
      uVar13 = 0xc00000b9;
    }
    else if (iVar17 < 1) {
      if (bVar21 == 0) {
        *param_6 = uVar15;
        param_6[1] = 0x1a;
        uVar13 = 0x80000022;
      }
      else {
        *(uint *)(param_7 + 0x18) = (uint)bVar21;
        pvVar14 = (void *)ExAllocatePoolWithTag(param_3,(ulonglong)bVar21 << 3,0x50646948);
        *(void **)(param_7 + 0x10) = pvVar14;
        if (pvVar14 == (void *)0x0) {
LAB_180011021:
          uVar13 = 0xc000009a;
        }
        else {
          memset(pvVar14,0,(ulonglong)bVar21 << 3);
          uVar13 = 0;
        }
      }
    }
    else {
      *param_6 = uVar15;
      param_6[1] = 4;
      uVar13 = 0xc00000b9;
    }
    return uVar13;
  }
LAB_180010a47:
  iVar17 = (int)uVar12;
  uVar18 = iVar17 + 1;
  uVar20 = (ulonglong)uVar18;
  bVar1 = *(byte *)(uVar12 + param_1);
  uVar15 = uVar18;
  switch(bVar1) {
  case 9:
  case 0x19:
    goto switchD_180010a83_caseD_9;
  case 10:
  case 0x1a:
    goto switchD_180010a83_caseD_a;
  case 0xb:
  case 0x1b:
    uVar18 = iVar17 + 3;
    goto switchD_180010a83_caseD_a;
  default:
    uVar9 = (ushort)(bVar1 & 3);
    if ((bVar1 & 3) == 3) {
      uVar9 = 4;
    }
    if (param_2 < uVar9 + uVar18) {
      *param_6 = uVar18;
      param_6[1] = 6;
      return 0xc0000023;
    }
    uVar20 = (ulonglong)(uVar9 + uVar18);
    break;
  case 0x81:
    if (param_2 <= uVar18) goto LAB_1800110cb;
    iVar17 = 1;
    goto LAB_180010df7;
  case 0x82:
    if (param_2 <= iVar17 + 2U) goto LAB_1800110cb;
    iVar17 = 2;
LAB_180010df7:
    uVar18 = iVar17 + uVar18;
    if (sVar22 == 0) {
      if ((*(byte *)(uVar20 + param_1) & 1) == 0) {
        *param_6 = uVar18;
        param_6[1] = 10;
        return 0xc00000b9;
      }
    }
    else {
      if (sVar22 < 2) {
        sVar22 = 1;
      }
      uVar23 = sVar22 + uVar10;
      if (uVar23 < uVar10) {
        *param_6 = uVar18;
        param_6[1] = 5;
        return 0xc00000b9;
      }
      if (bVar6) {
        if (bVar8) {
          *param_6 = uVar18;
LAB_180010fb6:
          uVar15 = *param_5;
          param_6[1] = 0x16;
          param_6[2] = uVar15;
          return 0xc00000b9;
        }
        bVar7 = true;
      }
      sVar22 = 0;
      uVar10 = uVar23;
    }
    if (local_44 == 0) {
      *param_6 = uVar18;
      param_6[1] = 0x1b;
      return 0xc00000b9;
    }
    uVar20 = (ulonglong)uVar18;
    break;
  case 0x85:
    if (param_2 <= uVar18) goto LAB_1800110cb;
    bVar1 = *(byte *)(uVar20 + param_1);
    uVar18 = iVar17 + 2;
    uVar20 = (ulonglong)uVar18;
    if (local_44 < 1) {
      *param_6 = uVar18;
      param_6[1] = 0x13;
      param_6[2] = (uint)bVar1;
      return 0xc00000b9;
    }
    if (bVar6) {
      bVar6 = false;
    }
    else {
      bVar21 = bVar21 + 1;
      local_58 = bVar21;
    }
    bVar8 = true;
    if (!bVar7) break;
    goto LAB_180010fac;
  case 0x91:
    if (param_2 <= uVar18) goto LAB_1800110cb;
    uVar15 = iVar17 + 2;
    goto LAB_180010e8d;
  case 0x92:
    if (param_2 <= iVar17 + 2U) goto LAB_1800110cb;
    uVar15 = iVar17 + 3;
LAB_180010e8d:
    uVar20 = (ulonglong)uVar15;
    if (sVar22 == 0) {
      bVar1 = *(byte *)((ulonglong)uVar18 + param_1);
joined_r0x000180010f3f:
      if ((bVar1 & 1) == 0) {
        *param_6 = uVar15;
        param_6[1] = 10;
        return 0xc00000b9;
      }
    }
    else {
      if (sVar22 < 2) {
        sVar22 = 1;
      }
      uVar9 = sVar22 + uVar4;
      if (uVar9 < uVar4) {
LAB_180011183:
        *param_6 = uVar15;
        param_6[1] = 5;
        return 0xc00000b9;
      }
LAB_180010ed6:
      uVar18 = (uint)uVar20;
      if (bVar6) {
        if (bVar8) {
LAB_180010fac:
          *param_6 = uVar18;
          goto LAB_180010fb6;
        }
        bVar7 = true;
      }
      sVar22 = 0;
      uVar4 = uVar9;
    }
    if (local_44 == 0) {
      *param_6 = (uint)uVar20;
      param_6[1] = 0x1b;
      return 0xc00000b9;
    }
    break;
  case 0xa1:
    if (param_2 <= uVar18) goto LAB_1800110cb;
    iVar24 = local_44 + 1;
    uVar18 = iVar17 + 2;
    uVar20 = (ulonglong)uVar18;
    if (iVar24 == 1) {
      uVar5 = 0;
      uVar10 = 0;
      uVar4 = 0;
      uVar23 = 0;
      if ((sVar22 == 0) || (1 < sVar22)) {
        uVar15 = *param_5;
        *param_6 = uVar18;
        param_6[1] = 0xb;
        param_6[2] = uVar15;
        return 0xc00000b9;
      }
      if (bVar6) {
        uVar15 = *param_5;
        *param_6 = uVar18;
        param_6[1] = 0x15;
        param_6[2] = uVar15;
        return 0xc00000b9;
      }
      if (bVar7) goto LAB_180010fac;
      bVar21 = bVar21 + 1;
      bVar6 = true;
      bVar1 = (byte)*param_5 + 1;
      if (bVar1 < (byte)*param_5) {
        *(undefined1 *)param_5 = 0xff;
        goto LAB_180011030;
      }
      *(byte *)param_5 = bVar1;
      puVar11 = (undefined8 *)ExAllocatePoolWithTag(param_3,local_44 + 0x30,0x50646948);
      if (puVar11 == (undefined8 *)0x0) {
        *param_6 = uVar18;
        param_6[1] = 3;
        goto LAB_180011021;
      }
      *puVar11 = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[4] = 0;
      puVar11[5] = 0;
      local_58 = bVar21;
      uVar3 = 1;
      if (local_40 == (undefined8 *)0x0) {
        *param_4 = puVar11;
        sVar22 = 0;
        local_44 = iVar24;
        local_40 = puVar11;
      }
      else {
        local_40[5] = puVar11;
        sVar22 = 0;
        local_44 = iVar24;
        local_40 = puVar11;
      }
    }
    else {
      uVar9 = uVar3;
      if (1 < iVar24) {
        if (sVar22 == 0) {
          sVar22 = 1;
        }
        uVar9 = sVar22 + uVar3;
        if (uVar9 < uVar3) goto LAB_180011030;
      }
      sVar22 = 0;
      local_44 = iVar24;
      uVar3 = uVar9;
    }
    break;
  case 0xa9:
    if (param_2 <= uVar18) goto LAB_1800110cb;
    bVar1 = *(byte *)(uVar20 + param_1);
    if (bVar1 != 1) {
LAB_180011120:
      *param_6 = uVar18;
      param_6[1] = 0x22;
      param_6[2] = (uint)bVar1;
      return 0xc00000b9;
    }
    uVar15 = iVar17 + 2;
    while( true ) {
      if (param_2 <= uVar15) {
        *param_6 = uVar15;
        param_6[1] = 0x20;
        return 0xc00000b9;
      }
      uVar18 = uVar15 + 1;
      if (*(byte *)((ulonglong)uVar15 + param_1) == 0xa9) break;
      uVar16 = (uint)*(byte *)((ulonglong)uVar15 + param_1);
      uVar19 = uVar18;
      if (uVar16 != 9) {
        if (uVar16 != 10) {
          if (uVar16 != 0xb) {
            *param_6 = uVar18;
            param_6[1] = 0x21;
            param_6[2] = uVar16;
            return 0xc00000b9;
          }
          uVar18 = uVar15 + 3;
        }
        uVar19 = uVar18 + 1;
      }
      uVar18 = uVar19 + 1;
      if (param_2 <= uVar19) goto LAB_1800110cb;
      sVar22 = sVar22 + 1;
      uVar15 = uVar18;
    }
    if (param_2 <= uVar18) goto LAB_1800110cb;
    bVar1 = *(byte *)((ulonglong)uVar18 + param_1);
    if (bVar1 != 0) goto LAB_180011120;
    uVar20 = (ulonglong)(uVar15 + 2);
    break;
  case 0xb1:
    if (param_2 <= uVar18) goto LAB_1800110cb;
    uVar15 = iVar17 + 2;
    goto LAB_180010f33;
  case 0xb2:
    if (param_2 <= iVar17 + 2U) goto LAB_1800110cb;
    uVar15 = iVar17 + 3;
LAB_180010f33:
    uVar20 = (ulonglong)uVar15;
    if (sVar22 == 0) {
      bVar1 = *(byte *)((ulonglong)uVar18 + param_1);
      goto joined_r0x000180010f3f;
    }
    if (sVar22 < 2) {
      sVar22 = 1;
    }
    if ((ushort)(sVar22 + uVar5) < uVar5) goto LAB_180011183;
    uVar9 = uVar4;
    uVar5 = sVar22 + uVar5;
    goto LAB_180010ed6;
  case 0xc0:
    local_44 = local_44 + -1;
    sVar22 = 0;
    if (local_44 < 0) {
      *param_6 = uVar18;
      param_6[1] = 4;
      return 0xc00000b9;
    }
    if (local_44 < 1) {
      *(char *)((longlong)local_40 + 4) = (char)*param_5;
      uVar15 = (uint)uVar3 * 0x10 + 0x94 + ((uint)uVar4 + (uint)uVar5 + (uint)uVar23) * 0x68;
      *(short *)((longlong)local_40 + 0x1a) = (short)uVar15;
      if (0xffff < uVar15) {
LAB_180011030:
        *param_6 = uVar18;
        param_6[1] = 5;
        return 0xc00000b9;
      }
      pvVar14 = (void *)ExAllocatePoolWithTag(param_3,uVar15,0x50646948);
      local_40[4] = pvVar14;
      if (pvVar14 == (void *)0x0) {
        *param_6 = uVar18;
        param_6[1] = 5;
        return 0xc000009a;
      }
      memset(pvVar14,0,(ulonglong)uVar15);
      puVar2 = (undefined4 *)local_40[4];
      *puVar2 = 0x50646948;
      puVar2[1] = 0x52444b20;
      *(undefined2 *)(puVar2 + 4) = 0;
      *(undefined2 *)(puVar2 + 5) = 0;
      *(ushort *)((longlong)puVar2 + 0x12) = uVar23;
      uVar12 = Feature_2804573496__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar12 == 0) {
        *(ushort *)(puVar2 + 6) = uVar23 & 0xff;
        *(ushort *)(puVar2 + 7) = uVar23 & 0xff;
      }
      else if (param_8 == '\0') {
        uVar10 = uVar23 & 0xff;
        *(ushort *)(puVar2 + 6) = uVar10;
        *(ushort *)(puVar2 + 7) = uVar10;
        if (uVar10 != uVar23) {
          MicrosoftTelemetryAssertTriggeredArgsMsgKM
                    (pvVar14,(uint)uVar23,0,"Output partition Offset truncated");
        }
      }
      else {
        *(ushort *)(puVar2 + 6) = uVar23;
        *(ushort *)(puVar2 + 7) = uVar23;
      }
      *(ushort *)((longlong)puVar2 + 0x1a) = uVar4;
      uVar10 = uVar23 + uVar4;
      uVar12 = Feature_2804573496__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar12 == 0) {
        *(ushort *)(puVar2 + 8) = uVar10 & 0xff;
        *(ushort *)(puVar2 + 9) = uVar10 & 0xff;
      }
      else if (param_8 == '\0') {
        uVar9 = uVar10 & 0xff;
        *(ushort *)(puVar2 + 8) = uVar9;
        *(ushort *)(puVar2 + 9) = uVar9;
        if (uVar9 != uVar10) {
          MicrosoftTelemetryAssertTriggeredArgsMsgKM
                    (pvVar14,(uint)uVar10,0,"Feature partition Offset truncated");
        }
      }
      else {
        *(ushort *)(puVar2 + 8) = uVar10;
        *(ushort *)(puVar2 + 9) = uVar10;
      }
      uVar15 = (uint)(ushort)(uVar10 + uVar5) * 0x68;
      *(ushort *)((longlong)puVar2 + 0x22) = uVar5;
      if (0xffff < uVar15) {
        *(undefined2 *)(puVar2 + 10) = 0xffff;
        goto LAB_180011030;
      }
      *(short *)(puVar2 + 10) = (short)uVar15;
      *(ushort *)((longlong)puVar2 + 0x2a) = uVar3;
      bVar21 = local_58;
      uVar10 = uVar23;
    }
    break;
  case 0xfe:
    *param_6 = uVar18;
    param_6[1] = 0x12;
    param_6[2] = (uint)bVar1;
    return 0xc00000b9;
  }
LAB_180010ff3:
  uVar15 = (uint)uVar20;
  iVar17 = local_44;
  if (param_2 <= uVar15) goto LAB_1800111fd;
  uVar12 = uVar20;
  goto LAB_180010a47;
switchD_180010a83_caseD_a:
  uVar15 = uVar18 + 1;
switchD_180010a83_caseD_9:
  uVar18 = uVar15 + 1;
  uVar20 = (ulonglong)uVar18;
  if (param_2 <= uVar15) {
LAB_1800110cb:
    *(uint *)(param_7 + 0x1c) = uVar18;
    *(undefined4 *)(param_7 + 0x20) = 2;
    return 0xc0000023;
  }
  sVar22 = sVar22 + 1;
  goto LAB_180010ff3;
}



===== HidP_GetCollectionDescription @ 1800112d0 =====

void HidP_GetCollectionDescription
               (longlong param_1,uint param_2,undefined4 param_3,longlong *param_4)

{
                    /* 0x112d0  7  HidP_GetCollectionDescription */
  HidP_GetCollectionDescriptionInternal(param_1,param_2,param_3,param_4,'\0');
  return;
}



===== HidP_ParseCollections @ 1800112f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
HidP_ParseCollections
          (longlong param_1,uint param_2,undefined4 param_3,ushort *param_4,undefined8 param_5,
          uint *param_6,longlong param_7,char param_8)

{
  undefined1 uVar1;
  uint3 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte *pbVar6;
  char cVar7;
  byte bVar8;
  ushort uVar9;
  short sVar10;
  ushort *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ushort uVar16;
  ushort uVar17;
  uint uVar18;
  uint uVar19;
  longlong lVar20;
  undefined8 uVar21;
  ushort *puVar22;
  ushort *puVar23;
  uint uVar24;
  byte *pbVar25;
  ushort *puVar26;
  ushort *puVar27;
  char *pcVar28;
  int iVar29;
  uint uVar30;
  ulonglong uVar31;
  byte bVar32;
  undefined4 *puVar33;
  bool bVar34;
  undefined1 auStack_248 [32];
  uint local_228;
  byte local_224;
  byte local_223;
  uint *local_220;
  char *local_218;
  longlong local_210;
  ushort local_208;
  uint local_204;
  ushort *local_200;
  char local_1f8;
  ushort local_1f6;
  ushort local_1f4;
  ushort local_1f2;
  ushort local_1f0;
  ushort local_1ee;
  ushort local_1ec;
  ushort local_1ea;
  char local_1e8;
  char local_1e7;
  ushort local_1e6;
  ushort local_1e4;
  char local_1e2;
  ushort *local_1e0;
  ushort local_1d8;
  longlong local_1d0;
  uint local_1c8;
  undefined4 local_1c4;
  ushort *local_1c0;
  ushort *local_1b8;
  undefined6 local_1b0;
  undefined2 uStack_1aa;
  undefined2 uStack_1a8;
  undefined4 local_1a0;
  uint local_19c;
  undefined6 local_198;
  undefined2 uStack_192;
  undefined2 uStack_190;
  ushort *local_188;
  ushort *local_180;
  char *local_178;
  undefined4 local_16a;
  ushort *local_160;
  undefined4 local_158;
  undefined8 local_154;
  undefined8 uStack_14c;
  undefined8 local_144;
  undefined8 uStack_13c;
  undefined8 local_134;
  undefined8 uStack_12c;
  undefined8 local_124;
  undefined8 uStack_11c;
  undefined8 local_114;
  undefined8 uStack_10c;
  undefined8 local_104;
  undefined8 uStack_fc;
  undefined8 local_f4;
  undefined8 uStack_ec;
  undefined8 local_e4;
  undefined8 uStack_dc;
  undefined8 local_d4;
  undefined8 uStack_cc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined4 local_98;
  undefined8 uStack_94;
  undefined8 uStack_8c;
  undefined8 uStack_84;
  undefined4 uStack_7c;
  undefined1 local_78;
  undefined8 uStack_77;
  undefined8 uStack_6f;
  undefined8 uStack_67;
  undefined8 uStack_5f;
  undefined8 local_57;
  undefined4 local_4f;
  undefined2 local_4b;
  undefined1 local_49;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_248;
  puVar23 = (ushort *)&local_98;
  puVar33 = &local_158;
  local_220 = param_6;
  local_57 = 0;
  local_4f = 0;
  local_4b = 0;
  pbVar12 = (byte *)&local_b8;
  local_49 = 0;
  uVar14 = 0;
  local_b8 = 0;
  puVar22 = (ushort *)0x0;
  local_223 = 0;
  local_224 = 0;
  uStack_192 = 0;
  uStack_190 = 0;
  local_1e2 = '\0';
  puVar26 = (ushort *)0x0;
  puVar11 = (ushort *)0x0;
  local_158 = 0;
  local_98 = 0;
  uStack_94 = 0;
  uStack_8c = 0;
  uStack_84 = 0;
  uStack_7c = 0;
  local_78 = 0;
  local_1ee = 0;
  local_1f4 = 0;
  local_1c0 = (ushort *)0x0;
  local_188 = (ushort *)0x0;
  local_1e0 = (ushort *)0x0;
  local_180 = (ushort *)0x0;
  local_1c8 = 0;
  pcVar28 = *(char **)(param_7 + 0x10);
  local_210 = param_7;
  uStack_1aa = 0;
  uStack_1a8 = 0;
  local_16a = 0;
  local_178 = pcVar28 + (ulonglong)*(uint *)(param_7 + 0x18) * 8;
  local_200 = (ushort *)0x0;
  local_204 = 0;
  local_1e8 = '\x01';
  local_1f8 = '\0';
  local_1e7 = '\x01';
  local_154 = 0;
  uStack_14c = 0;
  local_144 = 0;
  uStack_13c = 0;
  local_134 = 0;
  uStack_12c = 0;
  local_124 = 0;
  uStack_11c = 0;
  local_114 = 0;
  uStack_10c = 0;
  local_104 = 0;
  uStack_fc = 0;
  local_f4 = 0;
  uStack_ec = 0;
  local_e4 = 0;
  uStack_dc = 0;
  local_d4 = 0;
  uStack_cc = 0;
  uStack_77 = 0;
  uStack_6f = 0;
  uStack_67 = 0;
  uStack_5f = 0;
  uStack_b0 = 0;
  uStack_a8 = 0;
  local_228 = param_2;
  local_218 = pcVar28;
  local_1d0 = param_1;
  local_1c4 = param_3;
  local_1b8 = puVar23;
  local_160 = param_4;
  if (param_2 == 0) {
LAB_1800137da:
    lVar20 = local_210;
    pbVar25 = *(byte **)(pbVar12 + 0x10);
    while (pbVar13 = pbVar25, pbVar13 != (byte *)0x0) {
      ExFreePool(pbVar12);
      pbVar12 = pbVar13;
      pbVar25 = *(byte **)(pbVar13 + 0x10);
    }
    pbVar12[0] = 0;
    pbVar12[1] = 0;
    pbVar12[2] = 0;
    pbVar12[3] = 0;
    pbVar12[4] = 0;
    pbVar12[5] = 0;
    pbVar12[6] = 0;
    pbVar12[7] = 0;
    pbVar12[8] = 0;
    pbVar12[9] = 0;
    pbVar12[10] = 0;
    pbVar12[0xb] = 0;
    pbVar12[0xc] = 0;
    pbVar12[0xd] = 0;
    pbVar12[0xe] = 0;
    pbVar12[0xf] = 0;
    pbVar12[0x10] = 0;
    pbVar12[0x11] = 0;
    pbVar12[0x12] = 0;
    pbVar12[0x13] = 0;
    pbVar12[0x14] = 0;
    pbVar12[0x15] = 0;
    pbVar12[0x16] = 0;
    pbVar12[0x17] = 0;
    *(int *)(lVar20 + 0x18) = (int)((longlong)pcVar28 - *(longlong *)(lVar20 + 0x10) >> 3);
    return 0;
  }
  local_1ea = 0;
  local_1e4 = 0;
  local_1f0 = 0;
  local_1a0 = 8;
  local_1e6 = 0;
  local_1ec = 0;
  local_1f2 = 0;
  uVar15 = 0;
LAB_1800114b3:
  cVar7 = local_1f8;
  iVar29 = (int)uVar15;
  uVar30 = iVar29 + 1;
  uVar31 = (ulonglong)uVar30;
  bVar32 = *(byte *)(uVar15 + local_1d0);
  local_19c = (uint)bVar32;
  pbVar13 = pbVar12;
  puVar27 = puVar26;
  pcVar28 = local_218;
  uVar24 = uVar30;
  pbVar25 = pbVar12;
  switch(bVar32) {
  case 5:
    if (local_228 <= uVar30) {
LAB_180013573:
      uVar21 = 0xc0000023;
      local_220[1] = 6;
      goto LAB_180013504;
    }
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    *puVar23 = (ushort)*pbVar25;
    break;
  case 6:
    uVar24 = iVar29 + 2;
    if (uVar24 < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *puVar23 = (ushort)bVar32;
      *puVar23 = CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
      goto LAB_180011e12;
    }
    goto LAB_1800135d8;
  case 7:
  case 8:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x18:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x28:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x38:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x48:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x58:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
  case 0x7f:
  case 0x80:
  case 0x83:
  case 0x84:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x93:
  case 0x94:
  case 0x97:
  case 0x98:
  case 0x9a:
  case 0x9b:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa2:
  case 0xa3:
  case 0xa5:
  case 0xa6:
  case 0xa7:
  case 0xa8:
  case 0xaa:
  case 0xab:
  case 0xac:
  case 0xad:
  case 0xae:
  case 0xaf:
  case 0xb0:
  case 0xb3:
  case 0xb5:
  case 0xb6:
  case 0xb7:
  case 0xb8:
  case 0xb9:
  case 0xba:
  case 0xbb:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xbf:
  default:
    bVar8 = bVar32 & 0xc;
    if (bVar8 != 0) {
      if (bVar8 == 4) {
        uVar16 = puVar23[3];
        if (3 < uVar16) {
          puVar23[3] = 3;
          uVar16 = 3;
        }
        uVar15 = (ulonglong)uVar16;
        uVar24 = local_19c & 3;
        *(byte *)(puVar23 + uVar15 * 4 + 0x10) = bVar32;
        if (uVar24 == 1) {
          if (local_228 <= uVar30) {
            uVar21 = 0xc0000023;
            local_220[1] = 6;
            *local_220 = uVar30;
            goto LAB_180013508;
          }
          uVar24 = (uint)*(byte *)(uVar31 + local_1d0);
LAB_1800134ca:
          *(uint *)(puVar23 + uVar15 * 4 + 0x12) = uVar24;
          uVar31 = (ulonglong)(uVar30 + 1);
        }
        else {
          if (uVar24 == 2) {
            uVar19 = iVar29 + 2;
            if (uVar19 < local_228) {
              bVar32 = *(byte *)(uVar31 + local_1d0);
              *(uint *)(puVar23 + uVar15 * 4 + 0x12) = (uint)bVar32;
              uVar24 = (uint)CONCAT11(*(undefined1 *)((ulonglong)uVar19 + local_1d0),bVar32);
              puVar11 = local_200;
              uVar30 = uVar19;
              goto LAB_1800134ca;
            }
            uVar21 = 0xc0000023;
            local_220[1] = 7;
            *local_220 = uVar30;
            goto LAB_180013508;
          }
          if (uVar24 == 3) {
            if (iVar29 + 4U < local_228) {
              bVar32 = *(byte *)(uVar31 + local_1d0);
              *(uint *)(puVar23 + uVar15 * 4 + 0x12) = (uint)bVar32;
              uVar16 = CONCAT11(*(undefined1 *)((ulonglong)(iVar29 + 2) + local_1d0),bVar32);
              *(uint *)(puVar23 + uVar15 * 4 + 0x12) = (uint)uVar16;
              uVar2 = CONCAT12(*(undefined1 *)((ulonglong)(iVar29 + 3) + local_1d0),uVar16);
              *(uint *)(puVar23 + uVar15 * 4 + 0x12) = (uint)uVar2;
              uVar24 = CONCAT13(*(undefined1 *)((ulonglong)(iVar29 + 4U) + local_1d0),uVar2);
              puVar11 = local_200;
              uVar30 = iVar29 + 4U;
              goto LAB_1800134ca;
            }
            uVar21 = 0xc0000023;
            local_220[1] = 8;
            *local_220 = uVar30;
            goto LAB_180013508;
          }
        }
        puVar23[3] = puVar23[3] + 1;
        puVar27 = local_1e0;
        break;
      }
      if (bVar8 != 8) {
        if (bVar8 != 0xc) break;
      }
    }
    uVar21 = 0xc000001d;
    local_220[1] = 0x12;
LAB_1800134ff:
    local_220[2] = local_19c;
    goto LAB_180013504;
  case 9:
  case 10:
  case 0xb:
    if (((((byte *)&local_b8 == pbVar12) || (*(short *)(pbVar12 + 4) != 0)) ||
        (*(short *)(pbVar12 + 8) != 0)) || (*(short *)(pbVar12 + 6) != 0)) {
      pbVar12 = (byte *)HidP_PushUsageList((char *)pbVar12,local_1c4,local_1f8);
      if (pbVar12 == (byte *)0x0) goto LAB_1800136ac;
      uVar14 = (ulonglong)local_204;
      puVar26 = local_1e0;
    }
    *pbVar12 = 0;
    if (bVar32 == 9) {
      if (local_228 <= uVar30) goto LAB_180013573;
      *(ushort *)(pbVar12 + 4) = (ushort)*(byte *)(uVar31 + local_1d0);
LAB_1800121a1:
      uVar31 = (ulonglong)(uVar24 + 1);
      if (cVar7 != '\0') {
        bVar34 = local_1e7 == '\0';
        local_1e7 = '\0';
        pbVar12[1] = bVar34;
      }
      goto LAB_180011e15;
    }
    uVar24 = iVar29 + 2;
    if (bVar32 == 10) {
      if (uVar24 < local_228) {
        bVar32 = *(byte *)(uVar31 + local_1d0);
        *(ushort *)(pbVar12 + 4) = (ushort)bVar32;
        *(ushort *)(pbVar12 + 4) = CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
        goto LAB_1800121a1;
      }
      goto LAB_1800135d8;
    }
    if (local_228 <= uVar24) goto LAB_1800135d8;
    bVar32 = *(byte *)(uVar31 + local_1d0);
    *(ushort *)(pbVar12 + 4) = (ushort)bVar32;
    *(ushort *)(pbVar12 + 4) = CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
    uVar24 = iVar29 + 4;
    if (uVar24 < local_228) {
      bVar32 = *(byte *)((ulonglong)(iVar29 + 3) + local_1d0);
      *(ushort *)(pbVar12 + 2) = (ushort)bVar32;
      *(ushort *)(pbVar12 + 2) = CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
      goto LAB_1800121a1;
    }
LAB_18001365d:
    uVar21 = 0xc0000023;
    local_220[1] = 7;
    *local_220 = iVar29 + 3;
    goto LAB_180013508;
  case 0x15:
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    *(uint *)(puVar23 + 4) = -(uint)((*pbVar25 & 0x80) != 0) & 0xffffff00 | (uint)*pbVar25;
    goto LAB_180011e15;
  case 0x16:
    if (iVar29 + 2U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 4) = (uint)bVar32;
      bVar8 = *(byte *)((ulonglong)(iVar29 + 2U) + local_1d0);
      uVar31 = (ulonglong)(iVar29 + 3);
      *(uint *)(puVar23 + 4) =
           -(uint)((bVar8 & 0x80) != 0) & 0xffff0000 | (uint)CONCAT11(bVar8,bVar32);
      goto LAB_180011e15;
    }
    goto LAB_1800135d8;
  case 0x17:
    if (iVar29 + 4U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 4) = (uint)bVar32;
      uVar16 = CONCAT11(*(undefined1 *)((ulonglong)(iVar29 + 2) + local_1d0),bVar32);
      *(uint *)(puVar23 + 4) = (uint)uVar16;
      uVar24 = iVar29 + 4;
      uVar2 = CONCAT12(*(undefined1 *)((ulonglong)(iVar29 + 3) + local_1d0),uVar16);
      *(uint *)(puVar23 + 4) = (uint)uVar2;
      *(uint *)(puVar23 + 4) = CONCAT13(*(undefined1 *)((ulonglong)uVar24 + local_1d0),uVar2);
      goto LAB_180011e12;
    }
    goto LAB_1800135f0;
  case 0x19:
  case 0x1a:
  case 0x1b:
    if (((byte *)&local_b8 == pbVar12) || (*(short *)(pbVar12 + 6) != 0)) {
LAB_1800121dc:
      pbVar13 = (byte *)ExAllocatePoolWithTag(local_1c4,0x18,0x50646948);
      if (pbVar13 == (byte *)0x0) {
        pbVar12 = *(byte **)(pbVar12 + 0x10);
        while( true ) {
          pbVar6 = pbVar12;
          pbVar12 = pbVar13;
          if (pbVar6 == (byte *)0x0) break;
          ExFreePool(pbVar25);
          pbVar12 = *(byte **)(pbVar6 + 0x10);
          pbVar25 = pbVar6;
        }
        goto LAB_18001369d;
      }
      pbVar13[0] = 0;
      pbVar13[1] = 0;
      pbVar13[2] = 0;
      pbVar13[3] = 0;
      pbVar13[4] = 0;
      pbVar13[5] = 0;
      pbVar13[6] = 0;
      pbVar13[7] = 0;
      pbVar13[8] = 0;
      pbVar13[9] = 0;
      pbVar13[10] = 0;
      pbVar13[0xb] = 0;
      pbVar13[0xc] = 0;
      pbVar13[0xd] = 0;
      pbVar13[0xe] = 0;
      pbVar13[0xf] = 0;
      *(byte **)(pbVar13 + 0x10) = pbVar12;
      if (*pbVar12 == 0) {
        cVar7 = '\x01';
      }
      else {
        cVar7 = (pbVar12[8] - pbVar12[6]) + '\x01';
      }
      uVar14 = (ulonglong)local_204;
      pbVar13[10] = cVar7 + pbVar12[10];
      puVar26 = local_1e0;
      puVar23 = local_1b8;
    }
    else if (*(short *)(pbVar12 + 4) != 0) goto LAB_1800121dc;
    *pbVar13 = 1;
    pbVar12 = pbVar13;
    if (bVar32 == 0x19) {
      if (local_228 <= uVar30) goto LAB_180013573;
      *(ushort *)(pbVar13 + 6) = (ushort)*(byte *)(uVar31 + local_1d0);
      goto LAB_180011e12;
    }
    uVar24 = iVar29 + 2;
    if (bVar32 == 0x1a) {
      if (uVar24 < local_228) {
        bVar32 = *(byte *)(uVar31 + local_1d0);
        *(ushort *)(pbVar13 + 6) = (ushort)bVar32;
        *(ushort *)(pbVar13 + 6) = CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
        goto LAB_180011e12;
      }
    }
    else if (uVar24 < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(ushort *)(pbVar13 + 6) = (ushort)bVar32;
      *(ushort *)(pbVar13 + 6) = CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
      goto LAB_1800122bc;
    }
    goto LAB_1800135d8;
  case 0x25:
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    *(uint *)(puVar23 + 6) = -(uint)((*pbVar25 & 0x80) != 0) & 0xffffff00 | (uint)*pbVar25;
    goto LAB_180011e15;
  case 0x26:
    if (iVar29 + 2U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 6) = (uint)bVar32;
      bVar8 = *(byte *)((ulonglong)(iVar29 + 2U) + local_1d0);
      uVar31 = (ulonglong)(iVar29 + 3);
      *(uint *)(puVar23 + 6) =
           -(uint)((bVar8 & 0x80) != 0) & 0xffff0000 | (uint)CONCAT11(bVar8,bVar32);
      goto LAB_180011e15;
    }
    goto LAB_1800135d8;
  case 0x27:
    if (iVar29 + 4U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 6) = (uint)bVar32;
      uVar16 = CONCAT11(*(undefined1 *)((ulonglong)(iVar29 + 2) + local_1d0),bVar32);
      *(uint *)(puVar23 + 6) = (uint)uVar16;
      uVar2 = CONCAT12(*(undefined1 *)((ulonglong)(iVar29 + 3) + local_1d0),uVar16);
      *(uint *)(puVar23 + 6) = (uint)uVar2;
      *(uint *)(puVar23 + 6) = CONCAT13(*(undefined1 *)((ulonglong)(iVar29 + 4U) + local_1d0),uVar2)
      ;
      uVar24 = iVar29 + 4U;
      goto LAB_180011e12;
    }
    goto LAB_1800135f0;
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (((byte *)&local_b8 != pbVar12) && (*(short *)(pbVar12 + 8) == 0)) {
      if (*(short *)(pbVar12 + 4) != 0) goto LAB_180012305;
LAB_180012366:
      *pbVar13 = 1;
      pbVar12 = pbVar13;
      if (bVar32 == 0x29) {
        if (local_228 <= uVar30) goto LAB_180013573;
        *(ushort *)(pbVar13 + 8) = (ushort)*(byte *)(uVar31 + local_1d0);
      }
      else {
        uVar24 = iVar29 + 2;
        if (bVar32 == 0x2a) {
          if (uVar24 < local_228) {
            bVar32 = *(byte *)(uVar31 + local_1d0);
            *(ushort *)(pbVar13 + 8) = (ushort)bVar32;
            *(ushort *)(pbVar13 + 8) =
                 CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
            goto LAB_180011e12;
          }
          goto LAB_1800135d8;
        }
        if (local_228 <= uVar24) goto LAB_1800135d8;
        bVar32 = *(byte *)(uVar31 + local_1d0);
        *(ushort *)(pbVar13 + 8) = (ushort)bVar32;
        *(ushort *)(pbVar13 + 8) = CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
LAB_1800122bc:
        uVar24 = iVar29 + 4;
        pbVar12 = pbVar13;
        if (local_228 <= uVar24) goto LAB_18001365d;
        bVar32 = *(byte *)((ulonglong)(iVar29 + 3) + local_1d0);
        *(ushort *)(pbVar13 + 2) = (ushort)bVar32;
        *(ushort *)(pbVar13 + 2) = CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
      }
LAB_180011e12:
      uVar31 = (ulonglong)(uVar24 + 1);
      goto LAB_180011e15;
    }
LAB_180012305:
    pbVar13 = (byte *)ExAllocatePoolWithTag(local_1c4,0x18,0x50646948);
    if (pbVar13 != (byte *)0x0) {
      pbVar13[0] = 0;
      pbVar13[1] = 0;
      pbVar13[2] = 0;
      pbVar13[3] = 0;
      pbVar13[4] = 0;
      pbVar13[5] = 0;
      pbVar13[6] = 0;
      pbVar13[7] = 0;
      pbVar13[8] = 0;
      pbVar13[9] = 0;
      pbVar13[10] = 0;
      pbVar13[0xb] = 0;
      pbVar13[0xc] = 0;
      pbVar13[0xd] = 0;
      pbVar13[0xe] = 0;
      pbVar13[0xf] = 0;
      *(byte **)(pbVar13 + 0x10) = pbVar12;
      if (*pbVar12 == 0) {
        cVar7 = '\x01';
      }
      else {
        cVar7 = (pbVar12[8] - pbVar12[6]) + '\x01';
      }
      uVar14 = (ulonglong)local_204;
      pbVar13[10] = cVar7 + pbVar12[10];
      puVar26 = local_1e0;
      puVar23 = local_1b8;
      goto LAB_180012366;
    }
    pbVar12 = *(byte **)(pbVar12 + 0x10);
    while( true ) {
      pbVar6 = pbVar12;
      pbVar12 = pbVar13;
      if (pbVar6 == (byte *)0x0) break;
      ExFreePool(pbVar25);
      pbVar12 = *(byte **)(pbVar6 + 0x10);
      pbVar25 = pbVar6;
    }
LAB_18001369d:
    pbVar25[0] = 0;
    pbVar25[1] = 0;
    pbVar25[2] = 0;
    pbVar25[3] = 0;
    pbVar25[4] = 0;
    pbVar25[5] = 0;
    pbVar25[6] = 0;
    pbVar25[7] = 0;
    pbVar25[8] = 0;
    pbVar25[9] = 0;
    pbVar25[10] = 0;
    pbVar25[0xb] = 0;
    pbVar25[0xc] = 0;
    pbVar25[0xd] = 0;
    pbVar25[0xe] = 0;
    pbVar25[0xf] = 0;
    pbVar25[0x10] = 0;
    pbVar25[0x11] = 0;
    pbVar25[0x12] = 0;
    pbVar25[0x13] = 0;
    pbVar25[0x14] = 0;
    pbVar25[0x15] = 0;
    pbVar25[0x16] = 0;
    pbVar25[0x17] = 0;
LAB_1800136ac:
    uVar21 = 0xc000009a;
    local_220[1] = 0x10;
LAB_180013504:
    *local_220 = uVar30;
LAB_180013508:
    puVar23 = local_1b8;
    if (local_1b8 != (ushort *)&local_98) {
      do {
        puVar11 = *(ushort **)(puVar23 + 0x24);
        ExFreePool(puVar23);
        puVar23 = puVar11;
      } while (puVar11 != (ushort *)&local_98);
    }
LAB_180013537:
    if (pbVar12 != (byte *)0x0) {
      pbVar25 = *(byte **)(pbVar12 + 0x10);
      while (pbVar13 = pbVar25, pbVar13 != (byte *)0x0) {
        ExFreePool(pbVar12);
        pbVar12 = pbVar13;
        pbVar25 = *(byte **)(pbVar13 + 0x10);
      }
      pbVar12[0] = 0;
      pbVar12[1] = 0;
      pbVar12[2] = 0;
      pbVar12[3] = 0;
      pbVar12[4] = 0;
      pbVar12[5] = 0;
      pbVar12[6] = 0;
      pbVar12[7] = 0;
      pbVar12[8] = 0;
      pbVar12[9] = 0;
      pbVar12[10] = 0;
      pbVar12[0xb] = 0;
      pbVar12[0xc] = 0;
      pbVar12[0xd] = 0;
      pbVar12[0xe] = 0;
      pbVar12[0xf] = 0;
      pbVar12[0x10] = 0;
      pbVar12[0x11] = 0;
      pbVar12[0x12] = 0;
      pbVar12[0x13] = 0;
      pbVar12[0x14] = 0;
      pbVar12[0x15] = 0;
      pbVar12[0x16] = 0;
      pbVar12[0x17] = 0;
    }
    return uVar21;
  case 0x35:
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    *(uint *)(puVar23 + 8) = -(uint)((*pbVar25 & 0x80) != 0) & 0xffffff00 | (uint)*pbVar25;
    goto LAB_180011e15;
  case 0x36:
    if (iVar29 + 2U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 8) = (uint)bVar32;
      bVar8 = *(byte *)((ulonglong)(iVar29 + 2U) + local_1d0);
      uVar31 = (ulonglong)(iVar29 + 3);
      *(uint *)(puVar23 + 8) =
           -(uint)((bVar8 & 0x80) != 0) & 0xffff0000 | (uint)CONCAT11(bVar8,bVar32);
      goto LAB_180011e15;
    }
    goto LAB_1800135d8;
  case 0x37:
    if (iVar29 + 4U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 8) = (uint)bVar32;
      uVar16 = CONCAT11(*(undefined1 *)((ulonglong)(iVar29 + 2) + local_1d0),bVar32);
      *(uint *)(puVar23 + 8) = (uint)uVar16;
      uVar2 = CONCAT12(*(undefined1 *)((ulonglong)(iVar29 + 3) + local_1d0),uVar16);
      *(uint *)(puVar23 + 8) = (uint)uVar2;
      *(uint *)(puVar23 + 8) = CONCAT13(*(undefined1 *)((ulonglong)(iVar29 + 4U) + local_1d0),uVar2)
      ;
      uVar24 = iVar29 + 4U;
      goto LAB_180011e12;
    }
    goto LAB_1800135f0;
  case 0x39:
    local_223 = 0;
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    local_1ee = (ushort)*pbVar25;
    break;
  case 0x45:
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    *(uint *)(puVar23 + 10) = -(uint)((*pbVar25 & 0x80) != 0) & 0xffffff00 | (uint)*pbVar25;
    goto LAB_180011e15;
  case 0x46:
    if (iVar29 + 2U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 10) = (uint)bVar32;
      bVar8 = *(byte *)((ulonglong)(iVar29 + 2U) + local_1d0);
      uVar31 = (ulonglong)(iVar29 + 3);
      *(uint *)(puVar23 + 10) =
           -(uint)((bVar8 & 0x80) != 0) & 0xffff0000 | (uint)CONCAT11(bVar8,bVar32);
      goto LAB_180011e15;
    }
    goto LAB_1800135d8;
  case 0x47:
    if (iVar29 + 4U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 10) = (uint)bVar32;
      uVar16 = CONCAT11(*(undefined1 *)((ulonglong)(iVar29 + 2) + local_1d0),bVar32);
      *(uint *)(puVar23 + 10) = (uint)uVar16;
      uVar2 = CONCAT12(*(undefined1 *)((ulonglong)(iVar29 + 3) + local_1d0),uVar16);
      *(uint *)(puVar23 + 10) = (uint)uVar2;
      *(uint *)(puVar23 + 10) =
           CONCAT13(*(undefined1 *)((ulonglong)(iVar29 + 4U) + local_1d0),uVar2);
      uVar24 = iVar29 + 4U;
      goto LAB_180011e12;
    }
    goto LAB_1800135f0;
  case 0x49:
    local_223 = 1;
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    local_1ec = (ushort)*pbVar25;
    break;
  case 0x55:
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    *(uint *)(puVar23 + 0xc) = -(uint)((*pbVar25 & 0x80) != 0) & 0xffffff00 | (uint)*pbVar25;
    goto LAB_180011e15;
  case 0x56:
    if (iVar29 + 2U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 0xc) = (uint)bVar32;
      bVar8 = *(byte *)((ulonglong)(iVar29 + 2U) + local_1d0);
      uVar31 = (ulonglong)(iVar29 + 3);
      *(uint *)(puVar23 + 0xc) =
           -(uint)((bVar8 & 0x80) != 0) & 0xffff0000 | (uint)CONCAT11(bVar8,bVar32);
      goto LAB_180011e15;
    }
    goto LAB_1800135d8;
  case 0x57:
    if (iVar29 + 4U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 0xc) = (uint)bVar32;
      uVar16 = CONCAT11(*(undefined1 *)((ulonglong)(iVar29 + 2) + local_1d0),bVar32);
      *(uint *)(puVar23 + 0xc) = (uint)uVar16;
      uVar2 = CONCAT12(*(undefined1 *)((ulonglong)(iVar29 + 3) + local_1d0),uVar16);
      *(uint *)(puVar23 + 0xc) = (uint)uVar2;
      *(uint *)(puVar23 + 0xc) =
           CONCAT13(*(undefined1 *)((ulonglong)(iVar29 + 4U) + local_1d0),uVar2);
      uVar24 = iVar29 + 4U;
      goto LAB_180011e12;
    }
    goto LAB_1800135f0;
  case 0x59:
    local_223 = 1;
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    local_1ea = (ushort)*pbVar25;
    break;
  case 0x65:
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    *(uint *)(puVar23 + 0xe) = (uint)*pbVar25;
    break;
  case 0x66:
    uVar24 = iVar29 + 2;
    if (uVar24 < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 0xe) = (uint)bVar32;
      uVar30 = (uint)CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
LAB_180011e0e:
      *(uint *)(puVar23 + 0xe) = uVar30;
      goto LAB_180011e12;
    }
    goto LAB_1800135d8;
  case 0x67:
    if (iVar29 + 4U < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      *(uint *)(puVar23 + 0xe) = (uint)bVar32;
      uVar16 = CONCAT11(*(undefined1 *)((ulonglong)(iVar29 + 2) + local_1d0),bVar32);
      *(uint *)(puVar23 + 0xe) = (uint)uVar16;
      uVar24 = iVar29 + 4;
      uVar2 = CONCAT12(*(undefined1 *)((ulonglong)(iVar29 + 3) + local_1d0),uVar16);
      *(uint *)(puVar23 + 0xe) = (uint)uVar2;
      uVar30 = CONCAT13(*(undefined1 *)((ulonglong)uVar24 + local_1d0),uVar2);
      goto LAB_180011e0e;
    }
LAB_1800135f0:
    uVar21 = 0xc0000023;
    local_220[1] = 8;
    goto LAB_180013504;
  case 0x75:
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    puVar23[1] = (ushort)*pbVar25;
    break;
  case 0x79:
    local_224 = 0;
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    local_1f4 = (ushort)*pbVar25;
    break;
  case 0x81:
    lVar20 = *(longlong *)(puVar23 + 0x20);
    local_1b0 = (undefined6)lVar20;
    uStack_1aa = (undefined2)((ulonglong)lVar20 >> 0x30);
    if (lVar20 == 0) goto LAB_1800135ce;
    uVar16 = puVar23[2];
    local_208 = *(ushort *)(lVar20 + 2);
    uVar24 = (uint)puVar23[1] * (uint)uVar16;
    if ((uVar24 < 0x10000) && (uVar9 = (short)uVar24 + local_208, local_208 <= uVar9)) {
      *(ushort *)(lVar20 + 2) = uVar9;
    }
    else {
      if (param_8 != '\0') {
LAB_1800136ed:
        uVar21 = 0xc00000b9;
        local_220[1] = 0x24;
        goto LAB_180013504;
      }
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                ((ulonglong)uVar16,CONCAT22(puVar23[1],uVar16),(uint)local_208,
                 "Report InputLength integer overflow");
      uVar14 = (ulonglong)local_204;
      *(short *)(lVar20 + 2) = *(short *)(lVar20 + 2) + puVar23[1] * puVar23[2];
      puVar26 = local_1e0;
    }
    puVar11 = (ushort *)(puVar33 + 5);
    local_198 = SUB86(puVar11,0);
    uStack_192 = (undefined2)((ulonglong)puVar11 >> 0x30);
    if (local_228 <= uVar30) goto LAB_180013573;
    uVar16 = (ushort)*(byte *)(uVar31 + local_1d0);
LAB_18001287f:
    uVar30 = uVar30 + 1;
    uVar31 = (ulonglong)uVar30;
    local_1f6 = uVar16;
    if (local_1e2 != '\0') {
      if ((uVar16 & 2) == 0) {
        if ((uVar16 & 1) != 0) goto LAB_180011e15;
        if (pbVar12[1] != 0) {
          uVar21 = 0xc00000b9;
          local_220[1] = 0x40;
          goto LAB_180013504;
        }
        uVar14 = Feature_3878577467__private_IsEnabledDeviceUsageNoInline();
        if ((((int)uVar14 != 0) ||
            (uVar14 = Feature_2176477499__private_IsEnabledDeviceUsageNoInline(), (int)uVar14 != 0))
           || (uVar14 = Feature_2041211192__private_IsEnabledDeviceUsageNoInline(), (int)uVar14 != 0
              )) {
          if (puVar11 == (ushort *)(puVar33 + 5)) {
            uVar14 = (ulonglong)
                     (ushort)(*(short *)((longlong)puVar33 + 0x12) + *(short *)(puVar33 + 4));
          }
          else if (puVar11 == (ushort *)(puVar33 + 7)) {
            uVar14 = (ulonglong)
                     (ushort)(*(short *)((longlong)puVar33 + 0x1a) + *(short *)(puVar33 + 6));
          }
          else {
            uVar14 = (ulonglong)
                     (ushort)(*(short *)((longlong)puVar33 + 0x22) + *(short *)(puVar33 + 8));
          }
          if ((ushort)uVar14 <= *puVar11) {
            if (param_8 != '\0') {
              pbVar25 = *(byte **)(pbVar12 + 0x10);
              while (pbVar13 = pbVar25, pbVar13 != (byte *)0x0) {
                ExFreePool(pbVar12);
                pbVar12 = pbVar13;
                pbVar25 = *(byte **)(pbVar13 + 0x10);
              }
              pbVar12[0] = 0;
              pbVar12[1] = 0;
              pbVar12[2] = 0;
              pbVar12[3] = 0;
              pbVar12[4] = 0;
              pbVar12[5] = 0;
              pbVar12[6] = 0;
              pbVar12[7] = 0;
              pbVar12[8] = 0;
              pbVar12[9] = 0;
              pbVar12[10] = 0;
              pbVar12[0xb] = 0;
              pbVar12[0xc] = 0;
              pbVar12[0xd] = 0;
              pbVar12[0xe] = 0;
              pbVar12[0xf] = 0;
              pbVar12[0x10] = 0;
              pbVar12[0x11] = 0;
              pbVar12[0x12] = 0;
              pbVar12[0x13] = 0;
              pbVar12[0x14] = 0;
              pbVar12[0x15] = 0;
              pbVar12[0x16] = 0;
              pbVar12[0x17] = 0;
              goto LAB_180012969;
            }
            MicrosoftTelemetryAssertTriggeredArgsMsgKM
                      (uVar14,(uint)*puVar11,(int)uVar14,
                       "Array channel index exceeds partition size");
          }
        }
        if (pbVar12 != (byte *)&local_b8) {
LAB_1800129b1:
          if ((uint)*(ushort *)((longlong)puVar33 + 0x1a) +
              (uint)*(ushort *)((longlong)puVar33 + 0x12) +
              (uint)*(ushort *)((longlong)puVar33 + 0x22) <= (uint)*puVar11) goto LAB_180013705;
          uVar14 = Feature_3878577467__private_IsEnabledDeviceUsageNoInline();
          if ((((int)uVar14 != 0) ||
              (uVar14 = Feature_2176477499__private_IsEnabledDeviceUsageNoInline(), (int)uVar14 != 0
              )) || (uVar14 = Feature_2041211192__private_IsEnabledDeviceUsageNoInline(),
                    (int)uVar14 != 0)) {
            if (puVar11 == (ushort *)(puVar33 + 5)) {
              uVar14 = (ulonglong)
                       (ushort)(*(short *)(puVar33 + 4) + *(short *)((longlong)puVar33 + 0x12));
            }
            else if (puVar11 == (ushort *)(puVar33 + 7)) {
              uVar14 = (ulonglong)
                       (ushort)(*(short *)(puVar33 + 6) + *(short *)((longlong)puVar33 + 0x1a));
            }
            else {
              uVar14 = (ulonglong)
                       (ushort)(*(short *)(puVar33 + 8) + *(short *)((longlong)puVar33 + 0x22));
            }
            if (*puVar11 < (ushort)uVar14) goto LAB_180012a49;
            if (param_8 == '\0') {
              MicrosoftTelemetryAssertTriggeredArgsMsgKM
                        (uVar14,(uint)*puVar11,(int)uVar14,
                         "Array channel index exceeds partition size in loop");
              goto LAB_180012a49;
            }
            *(uint *)(puVar22 + 0xc) = *(uint *)(puVar22 + 0xc) & 0xfffffffe;
            pbVar25 = *(byte **)(pbVar12 + 0x10);
            while (pbVar13 = pbVar25, pbVar13 != (byte *)0x0) {
              ExFreePool(pbVar12);
              pbVar12 = pbVar13;
              pbVar25 = *(byte **)(pbVar13 + 0x10);
            }
            pbVar12[0] = 0;
            pbVar12[1] = 0;
            pbVar12[2] = 0;
            pbVar12[3] = 0;
            pbVar12[4] = 0;
            pbVar12[5] = 0;
            pbVar12[6] = 0;
            pbVar12[7] = 0;
            pbVar12[8] = 0;
            pbVar12[9] = 0;
            pbVar12[10] = 0;
            pbVar12[0xb] = 0;
            pbVar12[0xc] = 0;
            pbVar12[0xd] = 0;
            pbVar12[0xe] = 0;
            pbVar12[0xf] = 0;
            pbVar12[0x10] = 0;
            pbVar12[0x11] = 0;
            pbVar12[0x12] = 0;
            pbVar12[0x13] = 0;
            pbVar12[0x14] = 0;
            pbVar12[0x15] = 0;
            pbVar12[0x16] = 0;
            pbVar12[0x17] = 0;
            goto LAB_180012969;
          }
LAB_180012a49:
          puVar22 = (ushort *)(puVar33 + (ulonglong)*puVar11 * 0x1a + 0xb);
          *(uint *)(puVar22 + 0xc) = *(uint *)(puVar22 + 0xc) | 1;
          *(uint *)(puVar22 + 6) = (uint)uVar16;
          puVar22[9] = (ushort)((longlong)local_200 - (longlong)local_188 >> 4);
          puVar22[0xb] = *local_200;
          puVar22[10] = local_200[1];
          uVar16 = *(ushort *)(pbVar12 + 2);
          if (uVar16 == 0) {
            uVar16 = *puVar23;
          }
          *puVar22 = uVar16;
          *(byte *)((longlong)puVar22 + 3) = (byte)local_208 & 7;
          puVar22[4] = local_208 >> 3;
          puVar22[2] = puVar23[1];
          puVar22[3] = puVar23[2];
          uVar24 = (uint)puVar23[1] * (uint)puVar23[2];
          if (uVar24 < 0x10000) {
            uVar16 = (ushort)uVar24;
          }
          else {
            puVar22[5] = 0xffff;
            if (param_8 != '\0') goto LAB_1800136ed;
            MicrosoftTelemetryAssertTriggeredArgsMsgKM
                      ((ulonglong)local_208,CONCAT22(puVar23[1],puVar23[2]),0,
                       "Channel BitLength integer overflow");
            uVar16 = (ushort)((uint)puVar23[1] * (uint)puVar23[2]);
            uVar24 = (uint)puVar23[1] * (uint)puVar23[2] & 0xffff;
          }
          puVar22[5] = uVar16;
          uVar16 = (ushort)*(byte *)((longlong)puVar22 + 3) + (short)uVar24;
          puVar22[8] = (ushort)((uVar16 & 7) != 0) + (uVar16 >> 3) + puVar22[4];
          if (*(undefined1 **)(puVar23 + 0x20) == (undefined1 *)0x0) goto LAB_1800135ce;
          *(undefined1 *)(puVar22 + 1) = **(undefined1 **)(puVar23 + 0x20);
          *(undefined4 *)(puVar22 + 0x30) = *(undefined4 *)(puVar23 + 0xe);
          *(undefined4 *)(puVar22 + 0x32) = *(undefined4 *)(puVar23 + 0xc);
          uVar24 = ((ushort)~local_1f6 & 4 | 2) * 2 | *(uint *)(puVar22 + 0xc) & 0xfffffff5;
          *(uint *)(puVar22 + 0xc) = uVar24;
          *(undefined4 *)(puVar22 + 0x26) = *(undefined4 *)(puVar23 + 4);
          *(undefined4 *)(puVar22 + 0x28) = *(undefined4 *)(puVar23 + 6);
          uVar24 = ((uint)*pbVar12 << 4 ^ uVar24) & 0x10 ^ uVar24;
          uVar24 = ((uint)local_223 << 7 ^ uVar24) & 0x80 ^ uVar24;
          uVar24 = ((uint)local_224 << 6 ^ uVar24) & 0x40 ^ uVar24;
          *(uint *)(puVar22 + 0xc) = uVar24;
          if (*pbVar12 == 0) {
            uVar16 = *(ushort *)(pbVar12 + 4);
            puVar22[0x1e] = uVar16;
          }
          else {
            puVar22[0x1e] = *(ushort *)(pbVar12 + 6);
            uVar16 = *(ushort *)(pbVar12 + 8);
          }
          puVar22[0x1f] = uVar16;
          if (local_223 == 0) {
            puVar22[0x22] = local_1ee;
            uVar16 = local_1ee;
          }
          else {
            puVar22[0x22] = local_1ec;
            uVar16 = local_1ea;
          }
          puVar22[0x23] = uVar16;
          if (local_224 == 0) {
            puVar22[0x20] = local_1f4;
            uVar16 = local_1f4;
          }
          else {
            puVar22[0x20] = local_1f2;
            uVar16 = local_1f0;
          }
          puVar22[0x21] = uVar16;
          *(uint *)(puVar22 + 0xc) = (uint)puVar23[3] << 0x1c | uVar24 & 0xfffffff;
          if (puVar23[3] != 0) {
            memmove(puVar22 + 0xe,puVar23 + 0x10,(ulonglong)puVar23[3] << 3);
          }
          if (*puVar22 == 1) {
            if ((puVar22[0x1e] < 0x82) && (0x80 < puVar22[0x1f])) {
              puVar33[3] = puVar33[3] | 1;
            }
            if ((puVar22[0x1e] < 0x83) && (0x81 < puVar22[0x1f])) {
              puVar33[3] = puVar33[3] | 2;
            }
            if ((puVar22[0x1e] < 0x84) && (0x82 < puVar22[0x1f])) {
              puVar33[3] = puVar33[3] | 0x80000000;
            }
          }
          *puVar11 = *puVar11 + 1;
          pbVar25 = *(byte **)(pbVar12 + 0x10);
          if (pbVar25 != (byte *)0x0) {
            ExFreePool(pbVar12);
            pbVar12 = pbVar25;
          }
          if (pbVar12 != (byte *)&local_b8) goto code_r0x000180012cd6;
        }
        *(uint *)(puVar22 + 0xc) = *(uint *)(puVar22 + 0xc) & 0xfffffffe;
      }
      else {
        uVar14 = Feature_3878577467__private_IsEnabledDeviceUsageNoInline();
        if ((((int)uVar14 != 0) ||
            (uVar14 = Feature_2176477499__private_IsEnabledDeviceUsageNoInline(), (int)uVar14 != 0))
           || (uVar14 = Feature_2041211192__private_IsEnabledDeviceUsageNoInline(), (int)uVar14 != 0
              )) {
          if (puVar11 == (ushort *)(puVar33 + 5)) {
            uVar14 = (ulonglong)
                     (ushort)(*(short *)((longlong)puVar33 + 0x12) + *(short *)(puVar33 + 4));
          }
          else if (puVar11 == (ushort *)(puVar33 + 7)) {
            uVar14 = (ulonglong)
                     (ushort)(*(short *)((longlong)puVar33 + 0x1a) + *(short *)(puVar33 + 6));
          }
          else {
            uVar14 = (ulonglong)
                     (ushort)(*(short *)((longlong)puVar33 + 0x22) + *(short *)(puVar33 + 8));
          }
          if ((ushort)uVar14 <= *puVar11) {
            if (param_8 != '\0') {
              pbVar25 = *(byte **)(pbVar12 + 0x10);
              while (pbVar13 = pbVar25, pbVar13 != (byte *)0x0) {
                ExFreePool(pbVar12);
                pbVar12 = pbVar13;
                pbVar25 = *(byte **)(pbVar13 + 0x10);
              }
              pbVar12[0] = 0;
              pbVar12[1] = 0;
              pbVar12[2] = 0;
              pbVar12[3] = 0;
              pbVar12[4] = 0;
              pbVar12[5] = 0;
              pbVar12[6] = 0;
              pbVar12[7] = 0;
              pbVar12[8] = 0;
              pbVar12[9] = 0;
              pbVar12[10] = 0;
              pbVar12[0xb] = 0;
              pbVar12[0xc] = 0;
              pbVar12[0xd] = 0;
              pbVar12[0xe] = 0;
              pbVar12[0xf] = 0;
              pbVar12[0x10] = 0;
              pbVar12[0x11] = 0;
              pbVar12[0x12] = 0;
              pbVar12[0x13] = 0;
              pbVar12[0x14] = 0;
              pbVar12[0x15] = 0;
              pbVar12[0x16] = 0;
              pbVar12[0x17] = 0;
              goto LAB_180012969;
            }
            MicrosoftTelemetryAssertTriggeredArgsMsgKM
                      (uVar14,(uint)*puVar11,(int)uVar14,
                       "Variable channel index exceeds partition size");
          }
        }
        puVar22 = (ushort *)(puVar33 + (ulonglong)*puVar11 * 0x1a + 0xb);
        if ((uVar16 & 1) == 0) {
          *(uint *)(puVar22 + 0xc) = *(uint *)(puVar22 + 0xc) & 0xfffffffd;
        }
        else {
          if ((pbVar12[10] == 0) ||
             (((*(short *)(pbVar12 + 4) == 0 && (*(short *)(pbVar12 + 6) == 0)) &&
              (*(short *)(pbVar12 + 8) == 0)))) {
            pbVar25 = *(byte **)(pbVar12 + 0x10);
            while (pbVar13 = pbVar25, pbVar13 != (byte *)0x0) {
              ExFreePool(pbVar12);
              pbVar12 = pbVar13;
              pbVar25 = *(byte **)(pbVar13 + 0x10);
            }
            uVar14 = (ulonglong)local_204;
            pbVar12[0] = 0;
            pbVar12[1] = 0;
            pbVar12[2] = 0;
            pbVar12[3] = 0;
            pbVar12[4] = 0;
            pbVar12[5] = 0;
            pbVar12[6] = 0;
            pbVar12[7] = 0;
            pbVar12[8] = 0;
            pbVar12[9] = 0;
            pbVar12[10] = 0;
            pbVar12[0xb] = 0;
            pbVar12[0xc] = 0;
            pbVar12[0xd] = 0;
            pbVar12[0xe] = 0;
            pbVar12[0xf] = 0;
            pbVar12[0x10] = 0;
            pbVar12[0x11] = 0;
            pbVar12[0x12] = 0;
            pbVar12[0x13] = 0;
            pbVar12[0x14] = 0;
            pbVar12[0x15] = 0;
            pbVar12[0x16] = 0;
            pbVar12[0x17] = 0;
            puVar26 = local_1e0;
            goto LAB_180011e15;
          }
          *(uint *)(puVar22 + 0xc) = *(uint *)(puVar22 + 0xc) | 2;
        }
        sVar10 = 0;
        if (*pbVar12 != 0) {
          if (*(ushort *)(pbVar12 + 8) < *(ushort *)(pbVar12 + 6)) {
LAB_180013705:
            uVar21 = 0xc000001d;
            local_220[1] = 0x12;
            local_220[2] = local_19c;
            goto LAB_180013504;
          }
          sVar10 = *(ushort *)(pbVar12 + 8) - *(ushort *)(pbVar12 + 6);
        }
        uVar9 = puVar23[2];
        uVar16 = (ushort)pbVar12[10] + sVar10;
        if (uVar9 < uVar16) {
          do {
            uVar17 = (ushort)pbVar12[10];
            if (uVar17 < uVar16) {
              sVar10 = (*(short *)(pbVar12 + 6) - uVar17) + uVar9;
              *(short *)(pbVar12 + 8) = sVar10;
              uVar16 = (sVar10 - *(short *)(pbVar12 + 6)) + uVar17;
            }
            else {
              pbVar25 = *(byte **)(pbVar12 + 0x10);
              uVar16 = uVar17 - 1;
              if (pbVar25 == (byte *)0x0) {
                puVar23 = local_1b8;
              }
              else {
                ExFreePool(pbVar12);
                pbVar12 = pbVar25;
                puVar23 = local_1b8;
              }
            }
            uVar9 = puVar23[2];
          } while (uVar9 < uVar16);
        }
        local_1d8 = 0;
        uVar16 = ((*(short *)(pbVar12 + 8) - *(short *)(pbVar12 + 6)) - uVar16) + 1 + uVar9;
        local_208 = local_208 + (uVar9 - uVar16) * puVar23[1];
        if (uVar9 != 0) {
LAB_180012f30:
          do {
            puVar11 = (ushort *)CONCAT26(uStack_192,local_198);
            if ((uint)*(ushort *)((longlong)puVar33 + 0x1a) +
                (uint)*(ushort *)((longlong)puVar33 + 0x12) +
                (uint)*(ushort *)((longlong)puVar33 + 0x22) <= (uint)*puVar11) {
              uVar21 = 0xc000001d;
              *local_220 = uVar30;
              local_220[1] = 0x12;
              local_220[2] = local_19c;
              goto LAB_180013508;
            }
            uVar14 = Feature_3878577467__private_IsEnabledDeviceUsageNoInline();
            if ((((int)uVar14 != 0) ||
                (uVar14 = Feature_2176477499__private_IsEnabledDeviceUsageNoInline(),
                (int)uVar14 != 0)) ||
               (uVar14 = Feature_2041211192__private_IsEnabledDeviceUsageNoInline(),
               (int)uVar14 != 0)) {
              if (puVar11 == (ushort *)(puVar33 + 5)) {
                uVar14 = (ulonglong)
                         (ushort)(*(short *)(puVar33 + 4) + *(short *)((longlong)puVar33 + 0x12));
              }
              else if (puVar11 == (ushort *)(puVar33 + 7)) {
                uVar14 = (ulonglong)
                         (ushort)(*(short *)(puVar33 + 6) + *(short *)((longlong)puVar33 + 0x1a));
              }
              else {
                uVar14 = (ulonglong)
                         (ushort)(*(short *)(puVar33 + 8) + *(short *)((longlong)puVar33 + 0x22));
              }
              if (*puVar11 < (ushort)uVar14) goto LAB_180012fc8;
              if (param_8 == '\0') {
                MicrosoftTelemetryAssertTriggeredArgsMsgKM
                          (uVar14,(uint)*puVar11,(int)uVar14,
                           "Variable channel index exceeds partition size in loop");
                goto LAB_180012fc8;
              }
              pbVar25 = *(byte **)(pbVar12 + 0x10);
              while (pbVar13 = pbVar25, pbVar13 != (byte *)0x0) {
                ExFreePool(pbVar12);
                pbVar12 = pbVar13;
                pbVar25 = *(byte **)(pbVar13 + 0x10);
              }
              pbVar12[0] = 0;
              pbVar12[1] = 0;
              pbVar12[2] = 0;
              pbVar12[3] = 0;
              pbVar12[4] = 0;
              pbVar12[5] = 0;
              pbVar12[6] = 0;
              pbVar12[7] = 0;
              pbVar12[8] = 0;
              pbVar12[9] = 0;
              pbVar12[10] = 0;
              pbVar12[0xb] = 0;
              pbVar12[0xc] = 0;
              pbVar12[0xd] = 0;
              pbVar12[0xe] = 0;
              pbVar12[0xf] = 0;
              pbVar12[0x10] = 0;
              pbVar12[0x11] = 0;
              pbVar12[0x12] = 0;
              pbVar12[0x13] = 0;
              pbVar12[0x14] = 0;
              pbVar12[0x15] = 0;
              pbVar12[0x16] = 0;
              pbVar12[0x17] = 0;
              break;
            }
LAB_180012fc8:
            uVar9 = *puVar11;
            *puVar11 = uVar9 + 1;
            puVar22 = (ushort *)(puVar33 + (ulonglong)uVar9 * 0x1a + 0xb);
            *(uint *)(puVar22 + 6) = (uint)local_1f6;
            *(uint *)(puVar22 + 0xc) = *(uint *)(puVar22 + 0xc) & 0xfffffffe | 0x20;
            puVar22[9] = (ushort)((longlong)local_200 - (longlong)local_188 >> 4);
            puVar22[0xb] = *local_200;
            puVar22[10] = local_200[1];
            uVar9 = *(ushort *)(pbVar12 + 2);
            if (uVar9 == 0) {
              uVar9 = *puVar23;
            }
            *puVar22 = uVar9;
            *(byte *)((longlong)puVar22 + 3) = (byte)local_208 & 7;
            puVar22[4] = local_208 >> 3;
            puVar22[2] = puVar23[1];
            puVar22[3] = uVar16;
            uVar24 = (uint)puVar23[1] * (uint)uVar16;
            if (uVar24 < 0x10000) {
              uVar9 = (ushort)uVar24;
            }
            else {
              puVar22[5] = 0xffff;
              if (param_8 != '\0') {
                uVar21 = 0xc00000b9;
                *local_220 = uVar30;
                local_220[1] = 0x24;
                goto LAB_180013508;
              }
              MicrosoftTelemetryAssertTriggeredArgsMsgKM
                        ((ulonglong)uVar16,CONCAT22(puVar23[1],uVar16),0,
                         "Channel BitLength integer overflow");
              uVar9 = (ushort)((uint)puVar23[1] * (uint)uVar16);
              uVar24 = (uint)puVar23[1] * (uint)uVar16 & 0xffff;
            }
            puVar22[5] = uVar9;
            uVar9 = (ushort)*(byte *)((longlong)puVar22 + 3) + (short)uVar24;
            uVar17 = uVar9 >> 3;
            uVar14 = (ulonglong)uVar17;
            puVar22[8] = ((uVar9 & 7) != 0) + uVar17 + puVar22[4];
            if (*(longlong *)(puVar23 + 0x20) == 0) goto LAB_1800135ce;
            uVar15 = Feature_2873779512__private_IsEnabledDeviceUsageNoInline();
            if (((((int)uVar15 == 0) &&
                 (uVar15 = Feature_3810682171__private_IsEnabledDeviceUsageNoInline(),
                 (int)uVar15 == 0)) &&
                (uVar15 = Feature_1728472377__private_IsEnabledDeviceUsageNoInline(),
                (int)uVar15 == 0)) &&
               (uVar15 = Feature_4123420985__private_IsEnabledDeviceUsageNoInline(),
               (int)uVar15 == 0)) {
LAB_18001317d:
              uVar24 = *(uint *)(puVar22 + 0xc);
              *(undefined1 *)(puVar22 + 1) = **(undefined1 **)(puVar23 + 0x20);
              uVar19 = ((ushort)~local_1f6 & 4) * 2;
              uVar18 = uVar19 | uVar24 & 0xfffffff7;
              *(uint *)(puVar22 + 0xc) = uVar18;
              *(undefined4 *)(puVar22 + 0x30) = *(undefined4 *)(puVar23 + 0xe);
              *(undefined4 *)(puVar22 + 0x32) = *(undefined4 *)(puVar23 + 0xc);
              if (puVar23[1] == 1) {
                uVar18 = uVar18 | 4;
              }
              else {
                uVar18 = uVar19 | uVar24 & 0xfffffff3;
                *(uint *)(puVar22 + 0xc) = uVar18;
                *(byte *)(puVar22 + 0x26) = (byte)(*(uint *)(puVar22 + 6) >> 6) & 1;
                *(undefined4 *)(puVar22 + 0x28) = *(undefined4 *)(puVar23 + 4);
                *(undefined4 *)(puVar22 + 0x2a) = *(undefined4 *)(puVar23 + 6);
                *(undefined4 *)(puVar22 + 0x2c) = *(undefined4 *)(puVar23 + 8);
                *(undefined4 *)(puVar22 + 0x2e) = *(undefined4 *)(puVar23 + 10);
              }
              uVar18 = ((uint)local_223 << 7 ^ uVar18) & 0x80 ^ uVar18;
              uVar18 = ((uint)local_224 << 6 ^ uVar18) & 0x40 ^ uVar18;
              *(uint *)(puVar22 + 0xc) = uVar18;
              *(uint *)(puVar22 + 0xc) = ((uint)*pbVar12 << 4 ^ uVar18) & 0x10 ^ uVar18;
              if (*pbVar12 == 0) {
                uVar9 = *(ushort *)(pbVar12 + 4);
                puVar22[0x1e] = uVar9;
              }
              else {
                puVar22[0x1e] = *(ushort *)(pbVar12 + 6);
                uVar9 = *(ushort *)(pbVar12 + 8);
              }
              puVar22[0x1f] = uVar9;
              if (local_223 == 0) {
                puVar22[0x22] = local_1ee;
                uVar9 = local_1ee;
              }
              else {
                puVar22[0x22] = local_1ec;
                uVar9 = local_1ea;
              }
              puVar22[0x23] = uVar9;
              if (local_224 == 0) {
                puVar22[0x20] = local_1f4;
                uVar9 = local_1f4;
              }
              else {
                puVar22[0x20] = local_1f2;
                uVar9 = local_1f0;
              }
              puVar22[0x21] = uVar9;
              pbVar25 = *(byte **)(pbVar12 + 0x10);
              bVar32 = pbVar12[1];
              if (pbVar25 != (byte *)0x0) {
                ExFreePool(pbVar12);
                pbVar12 = pbVar25;
              }
              *(uint *)(puVar22 + 0xc) =
                   (uint)local_1b8[3] << 0x1c | *(uint *)(puVar22 + 0xc) & 0xfffffff;
              if (local_1b8[3] != 0) {
                memmove(puVar22 + 0xe,local_1b8 + 0x10,(ulonglong)local_1b8[3] << 3);
              }
              if (*puVar22 == 1) {
                if ((puVar22[0x1e] < 0x82) && (0x80 < puVar22[0x1f])) {
                  puVar33[3] = puVar33[3] | 1;
                }
                if ((puVar22[0x1e] < 0x83) && (0x81 < puVar22[0x1f])) {
                  puVar33[3] = puVar33[3] | 2;
                }
                if ((puVar22[0x1e] < 0x84) && (0x82 < puVar22[0x1f])) {
                  puVar33[3] = puVar33[3] | 0x80000000;
                }
              }
            }
            else {
              if (puVar11 == (ushort *)(puVar33 + 5)) {
                uVar9 = *(ushort *)(CONCAT26(uStack_1aa,local_1b0) + 2);
              }
              else if (puVar11 == (ushort *)(puVar33 + 7)) {
                uVar9 = *(ushort *)(CONCAT26(uStack_1aa,local_1b0) + 4);
              }
              else {
                uVar9 = *(ushort *)(CONCAT26(uStack_1aa,local_1b0) + 6);
              }
              uVar24 = uVar9 + 7 >> 3;
              if (puVar22[8] <= uVar24) goto LAB_18001317d;
              if (param_8 == '\0') {
                MicrosoftTelemetryAssertTriggeredArgsMsgKM
                          (uVar14,(uint)puVar22[8],uVar24,"Channel ByteEnd exceeds report length");
                goto LAB_18001317d;
              }
              *puVar11 = *puVar11 - 1;
              pbVar25 = *(byte **)(pbVar12 + 0x10);
              bVar32 = pbVar12[1];
              if (pbVar25 != (byte *)0x0) {
                ExFreePool(pbVar12);
                pbVar12 = pbVar25;
              }
            }
            puVar23 = local_1b8;
            if (bVar32 == 0) goto code_r0x00018001333c;
          } while( true );
        }
      }
LAB_180012969:
      local_1ee = 0;
      local_1f4 = 0;
      uVar14 = (ulonglong)local_204;
      local_1f0 = local_1e4;
      local_1ea = local_1e4;
      local_224 = 0;
      local_223 = 0;
      puVar26 = local_1e0;
      local_1f2 = local_1e6;
      local_1ec = local_1e6;
      goto LAB_180011e15;
    }
    goto LAB_1800135ce;
  case 0x82:
    lVar20 = *(longlong *)(puVar23 + 0x20);
    local_1b0 = (undefined6)lVar20;
    uStack_1aa = (undefined2)((ulonglong)lVar20 >> 0x30);
    if (lVar20 == 0) goto LAB_1800135ce;
    uVar16 = puVar23[2];
    local_208 = *(ushort *)(lVar20 + 2);
    uVar24 = (uint)puVar23[1] * (uint)uVar16;
    if ((uVar24 < 0x10000) && (uVar9 = (short)uVar24 + local_208, local_208 <= uVar9)) {
      *(ushort *)(lVar20 + 2) = uVar9;
      puVar11 = (ushort *)(puVar33 + 5);
    }
    else {
      if (param_8 != '\0') goto LAB_1800136ed;
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                ((ulonglong)uVar16,CONCAT22(puVar23[1],uVar16),(uint)local_208,
                 "Report InputLength integer overflow");
      puVar11 = (ushort *)(puVar33 + 5);
      uVar14 = (ulonglong)local_204;
      *(short *)(lVar20 + 2) = *(short *)(lVar20 + 2) + puVar23[2] * puVar23[1];
      puVar26 = local_1e0;
    }
LAB_180012858:
    uVar24 = iVar29 + 2;
    local_198 = SUB86(puVar11,0);
    uStack_192 = (undefined2)((ulonglong)puVar11 >> 0x30);
    if (uVar24 < local_228) {
      uVar16 = CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),
                        *(undefined1 *)(uVar31 + local_1d0));
      uVar30 = uVar24;
      goto LAB_18001287f;
    }
    goto LAB_1800135d8;
  case 0x85:
    if (local_228 <= uVar30) goto LAB_180013573;
    cVar7 = *(char *)(uVar31 + local_1d0);
    uVar30 = iVar29 + 2;
    uVar31 = (ulonglong)uVar30;
    for (pcVar28 = *(char **)(local_210 + 0x10); pcVar28 != local_218; pcVar28 = pcVar28 + 8) {
      if (*pcVar28 == cVar7) {
        if (pcVar28[1] != (char)local_1c0[2]) {
          uVar21 = 0xc0110002;
          local_220[1] = 0x13;
          goto LAB_1800134ff;
        }
        *(char **)(puVar23 + 0x20) = pcVar28;
        break;
      }
    }
    if (local_1e8 == '\0') {
      if (pcVar28 == local_218) {
        if ((local_218 == (char *)0x0) || (local_178 <= local_218)) goto LAB_1800135ce;
        *(char **)(puVar23 + 0x20) = local_218;
        local_218[6] = '\b';
        local_218[7] = '\0';
        local_218[2] = '\b';
        local_218[3] = '\0';
        local_218[4] = '\b';
        local_218[5] = '\0';
        local_218[1] = (char)local_1c0[2];
        local_218 = local_218 + 8;
      }
    }
    else {
      local_1e8 = '\0';
    }
    if (*(char **)(puVar23 + 0x20) == (char *)0x0) goto LAB_1800135ce;
    **(char **)(puVar23 + 0x20) = cVar7;
    if (**(char **)(puVar23 + 0x20) != '\0') {
      puVar11 = local_200;
      pcVar28 = local_218;
      goto LAB_180011e24;
    }
    uVar21 = 0xc0110002;
    local_220[1] = 0x14;
    goto LAB_180013504;
  case 0x89:
    local_224 = 1;
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    local_1f2 = (ushort)*pbVar25;
    break;
  case 0x91:
    lVar20 = *(longlong *)(puVar23 + 0x20);
    local_1b0 = (undefined6)lVar20;
    uStack_1aa = (undefined2)((ulonglong)lVar20 >> 0x30);
    if (lVar20 != 0) {
      uVar16 = puVar23[2];
      local_208 = *(ushort *)(lVar20 + 4);
      uVar24 = (uint)puVar23[1] * (uint)uVar16;
      if ((uVar24 < 0x10000) && (uVar9 = (short)uVar24 + local_208, local_208 <= uVar9)) {
        *(ushort *)(lVar20 + 4) = uVar9;
      }
      else {
        if (param_8 != '\0') goto LAB_1800136ed;
        MicrosoftTelemetryAssertTriggeredArgsMsgKM
                  ((ulonglong)uVar16,CONCAT22(puVar23[1],uVar16),(uint)local_208,
                   "Report OutputLength integer overflow");
        uVar14 = (ulonglong)local_204;
        *(short *)(lVar20 + 4) = *(short *)(lVar20 + 4) + puVar23[2] * puVar23[1];
        puVar26 = local_1e0;
      }
      puVar11 = (ushort *)(puVar33 + 7);
      local_198 = SUB86(puVar11,0);
      uStack_192 = (undefined2)((ulonglong)puVar11 >> 0x30);
      if (uVar30 < local_228) {
        uVar16 = (ushort)*(byte *)(uVar31 + local_1d0);
        goto LAB_18001287f;
      }
      goto LAB_180013573;
    }
    goto LAB_1800135ce;
  case 0x92:
    lVar20 = *(longlong *)(puVar23 + 0x20);
    local_1b0 = (undefined6)lVar20;
    uStack_1aa = (undefined2)((ulonglong)lVar20 >> 0x30);
    if (lVar20 != 0) {
      uVar16 = puVar23[2];
      local_208 = *(ushort *)(lVar20 + 4);
      uVar24 = (uint)puVar23[1] * (uint)uVar16;
      if ((uVar24 < 0x10000) && (uVar9 = (short)uVar24 + local_208, local_208 <= uVar9)) {
        *(ushort *)(lVar20 + 4) = uVar9;
        puVar11 = (ushort *)(puVar33 + 7);
      }
      else {
        if (param_8 != '\0') goto LAB_1800136ed;
        MicrosoftTelemetryAssertTriggeredArgsMsgKM
                  ((ulonglong)uVar16,CONCAT22(puVar23[1],uVar16),(uint)local_208,
                   "Report OutputLength integer overflow");
        puVar11 = (ushort *)(puVar33 + 7);
        uVar14 = (ulonglong)local_204;
        *(short *)(lVar20 + 4) = *(short *)(lVar20 + 4) + puVar23[2] * puVar23[1];
        puVar26 = local_1e0;
      }
      goto LAB_180012858;
    }
    goto LAB_1800135ce;
  case 0x95:
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    puVar23[2] = (ushort)*pbVar25;
    break;
  case 0x96:
    uVar24 = iVar29 + 2;
    if (uVar24 < local_228) {
      bVar32 = *(byte *)(uVar31 + local_1d0);
      puVar23[2] = (ushort)bVar32;
      puVar23[2] = CONCAT11(*(undefined1 *)((ulonglong)uVar24 + local_1d0),bVar32);
      goto LAB_180011e12;
    }
LAB_1800135d8:
    uVar21 = 0xc0000023;
    local_220[1] = 7;
    goto LAB_180013504;
  case 0x99:
    local_224 = 1;
    if (local_228 <= uVar30) goto LAB_180013573;
    pbVar25 = (byte *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    local_1f0 = (ushort)*pbVar25;
    break;
  case 0xa1:
    if (local_228 <= uVar30) goto LAB_180013573;
    uVar1 = *(undefined1 *)(uVar31 + local_1d0);
    local_1c8 = local_1c8 + 1;
    uVar31 = (ulonglong)(iVar29 + 2);
    if (local_1c8 != 1) {
      if (1 < local_1c8) {
        uVar16 = (short)uVar14 + 1;
        uVar14 = CONCAT62((int6)(uVar14 >> 0x10),uVar16);
        lVar20 = (ulonglong)uVar16 * 0x10;
        while( true ) {
          local_200 = (ushort *)(lVar20 + (longlong)local_188);
          local_204 = (uint)uVar14;
          local_1e0 = puVar11;
          if (local_180 <= local_200) goto LAB_1800135ce;
          uVar16 = *(ushort *)(pbVar12 + 2);
          if (uVar16 == 0) {
            uVar16 = *puVar23;
          }
          local_200[1] = uVar16;
          if (*pbVar12 == 0) {
            uVar16 = *(ushort *)(pbVar12 + 4);
          }
          else {
            uVar16 = *(ushort *)(pbVar12 + 6);
          }
          *local_200 = uVar16;
          local_200[3] = 0;
          local_200[5] = 0;
          local_200[2] = (ushort)((longlong)puVar11 - (longlong)local_188 >> 4);
          local_200[4] = puVar11[5];
          puVar11[3] = puVar11[3] + 1;
          puVar11[5] = (ushort)uVar14;
          *(undefined1 *)(local_200 + 6) = uVar1;
          if (pbVar12[1] == 0) break;
          *(uint *)(local_200 + 6) = *(uint *)(local_200 + 6) | 0x100;
          uVar16 = (ushort)uVar14 + 1;
          uVar14 = CONCAT62((int6)(uVar14 >> 0x10),uVar16);
          lVar20 = (ulonglong)uVar16 << 4;
        }
        local_224 = 0;
        local_223 = 0;
        local_1f4 = 0;
        local_1f2 = local_1e6;
        local_1f0 = local_1e4;
        local_1ee = 0;
        local_1ec = local_1e6;
        local_1ea = local_1e4;
        pbVar25 = *(byte **)(pbVar12 + 0x10);
        if (*(byte **)(pbVar12 + 0x10) != (byte *)0x0) {
          do {
            pbVar12 = pbVar25;
            ExFreePool(pbVar13);
            pbVar25 = *(byte **)(pbVar12 + 0x10);
            pbVar13 = pbVar12;
          } while (*(byte **)(pbVar12 + 0x10) != (byte *)0x0);
          uVar14 = (ulonglong)local_204;
        }
        pbVar12[0] = 0;
        pbVar12[1] = 0;
        pbVar12[2] = 0;
        pbVar12[3] = 0;
        pbVar12[4] = 0;
        pbVar12[5] = 0;
        pbVar12[6] = 0;
        pbVar12[7] = 0;
        pbVar12[8] = 0;
        pbVar12[9] = 0;
        pbVar12[10] = 0;
        pbVar12[0xb] = 0;
        pbVar12[0xc] = 0;
        pbVar12[0xd] = 0;
        pbVar12[0xe] = 0;
        pbVar12[0xf] = 0;
        pbVar12[0x10] = 0;
        pbVar12[0x11] = 0;
        pbVar12[0x12] = 0;
        pbVar12[0x13] = 0;
        pbVar12[0x14] = 0;
        pbVar12[0x15] = 0;
        pbVar12[0x16] = 0;
        pbVar12[0x17] = 0;
        puVar11 = local_200;
        puVar27 = local_1e0;
      }
      break;
    }
    if (local_1c0 == (ushort *)0x0) {
      local_1c0 = local_160;
    }
    else {
      local_1c0 = *(ushort **)(local_1c0 + 0x14);
    }
    puVar33 = *(undefined4 **)(local_1c0 + 0x10);
    local_1e2 = '\x01';
    if ((local_218 == (char *)0x0) || (local_178 <= local_218)) goto LAB_1800135ce;
    *(char **)(puVar23 + 0x20) = local_218;
    local_218[6] = '\b';
    local_218[7] = '\0';
    local_218[2] = '\b';
    local_218[3] = '\0';
    local_218[4] = '\b';
    local_218[5] = '\0';
    *local_218 = '\0';
    local_218[1] = (char)local_1c0[2];
    pcVar28 = local_218 + 8;
    uVar16 = *(ushort *)(pbVar12 + 2);
    local_1e8 = '\x01';
    if (uVar16 == 0) {
      uVar16 = *puVar23;
    }
    *local_1c0 = uVar16;
    *(ushort *)((longlong)puVar33 + 10) = uVar16;
    if (*pbVar12 == 0) {
      uVar16 = *(ushort *)(pbVar12 + 4);
    }
    else {
      uVar16 = *(ushort *)(pbVar12 + 6);
    }
    local_1c0[1] = uVar16;
    *(ushort *)(puVar33 + 2) = uVar16;
    local_224 = 0;
    local_223 = 0;
    local_1f4 = 0;
    local_1ee = 0;
    local_218 = pcVar28;
    pbVar25 = *(byte **)(pbVar12 + 0x10);
    local_1f2 = local_1e6;
    local_1f0 = local_1e4;
    local_1ec = local_1e6;
    local_1ea = local_1e4;
    while (pbVar13 = pbVar25, pbVar13 != (byte *)0x0) {
      ExFreePool(pbVar12);
      pbVar12 = pbVar13;
      pbVar25 = *(byte **)(pbVar13 + 0x10);
    }
    local_204 = 0;
    uVar14 = 0;
    pbVar12[0] = 0;
    pbVar12[1] = 0;
    pbVar12[2] = 0;
    pbVar12[3] = 0;
    pbVar12[4] = 0;
    pbVar12[5] = 0;
    pbVar12[6] = 0;
    pbVar12[7] = 0;
    pbVar12[8] = 0;
    pbVar12[9] = 0;
    pbVar12[10] = 0;
    pbVar12[0xb] = 0;
    pbVar12[0xc] = 0;
    pbVar12[0xd] = 0;
    pbVar12[0xe] = 0;
    pbVar12[0xf] = 0;
    pbVar12[0x10] = 0;
    pbVar12[0x11] = 0;
    pbVar12[0x12] = 0;
    pbVar12[0x13] = 0;
    pbVar12[0x14] = 0;
    pbVar12[0x15] = 0;
    pbVar12[0x16] = 0;
    pbVar12[0x17] = 0;
    puVar11 = (ushort *)((ulonglong)*(ushort *)(puVar33 + 10) + 0x2c + (longlong)puVar33);
    local_180 = puVar11 + (ulonglong)*(ushort *)((longlong)puVar33 + 0x2a) * 8;
    puVar11[1] = *local_1c0;
    *puVar11 = local_1c0[1];
    puVar11[2] = 0;
    puVar11[3] = 0;
    puVar11[4] = 0;
    puVar11[5] = 0;
    *(undefined1 *)(puVar11 + 6) = uVar1;
    puVar26 = puVar11;
    local_200 = puVar11;
    local_1e0 = puVar11;
    local_188 = puVar11;
    goto LAB_180011e1f;
  case 0xa4:
    puVar11 = (ushort *)ExAllocatePoolWithTag(local_1c4,0x50,0x50646948);
    if (puVar11 != (ushort *)0x0) {
      uVar21 = *(undefined8 *)(puVar23 + 4);
      uVar14 = (ulonglong)local_204;
      *(undefined8 *)puVar11 = *(undefined8 *)puVar23;
      *(undefined8 *)(puVar11 + 4) = uVar21;
      uVar21 = *(undefined8 *)(puVar23 + 0xc);
      *(undefined8 *)(puVar11 + 8) = *(undefined8 *)(puVar23 + 8);
      *(undefined8 *)(puVar11 + 0xc) = uVar21;
      uVar21 = *(undefined8 *)(puVar23 + 0x14);
      *(undefined8 *)(puVar11 + 0x10) = *(undefined8 *)(puVar23 + 0x10);
      *(undefined8 *)(puVar11 + 0x14) = uVar21;
      uVar21 = *(undefined8 *)(puVar23 + 0x1c);
      *(undefined8 *)(puVar11 + 0x18) = *(undefined8 *)(puVar23 + 0x18);
      *(undefined8 *)(puVar11 + 0x1c) = uVar21;
      uVar3 = *(undefined4 *)(puVar23 + 0x22);
      uVar4 = *(undefined4 *)(puVar23 + 0x24);
      uVar5 = *(undefined4 *)(puVar23 + 0x26);
      *(undefined4 *)(puVar11 + 0x20) = *(undefined4 *)(puVar23 + 0x20);
      *(undefined4 *)(puVar11 + 0x22) = uVar3;
      *(undefined4 *)(puVar11 + 0x24) = uVar4;
      *(undefined4 *)(puVar11 + 0x26) = uVar5;
      *(ushort **)(puVar11 + 0x24) = puVar23;
      puVar26 = local_1e0;
      puVar23 = puVar11;
      local_1b8 = puVar11;
      goto LAB_180011e15;
    }
    goto LAB_1800136ac;
  case 0xa9:
    if (local_228 <= uVar30) goto LAB_180013573;
    cVar7 = *(char *)(uVar31 + local_1d0);
    uVar31 = (ulonglong)(iVar29 + 2);
    if (cVar7 != '\x01') {
      if (cVar7 == '\0') {
        local_1f8 = cVar7;
      }
      goto LAB_180011e24;
    }
    local_1e7 = '\x01';
    local_1f8 = cVar7;
    break;
  case 0xb1:
    lVar20 = *(longlong *)(puVar23 + 0x20);
    local_1b0 = (undefined6)lVar20;
    uStack_1aa = (undefined2)((ulonglong)lVar20 >> 0x30);
    if (lVar20 != 0) {
      uVar16 = puVar23[2];
      local_208 = *(ushort *)(lVar20 + 6);
      uVar24 = (uint)puVar23[1] * (uint)uVar16;
      if ((uVar24 < 0x10000) && (uVar9 = (short)uVar24 + local_208, local_208 <= uVar9)) {
        *(ushort *)(lVar20 + 6) = uVar9;
      }
      else {
        if (param_8 != '\0') goto LAB_1800136ed;
        MicrosoftTelemetryAssertTriggeredArgsMsgKM
                  ((ulonglong)uVar16,CONCAT22(puVar23[1],uVar16),(uint)local_208,
                   "Report FeatureLength integer overflow");
        uVar14 = (ulonglong)local_204;
        *(short *)(lVar20 + 6) = *(short *)(lVar20 + 6) + puVar23[2] * puVar23[1];
        puVar26 = local_1e0;
      }
      puVar11 = (ushort *)(puVar33 + 9);
      local_198 = SUB86(puVar11,0);
      uStack_192 = (undefined2)((ulonglong)puVar11 >> 0x30);
      if (uVar30 < local_228) {
        uVar16 = (ushort)*(byte *)(uVar31 + local_1d0);
        goto LAB_18001287f;
      }
      goto LAB_180013573;
    }
    goto LAB_1800135ce;
  case 0xb2:
    lVar20 = *(longlong *)(puVar23 + 0x20);
    local_1b0 = (undefined6)lVar20;
    uStack_1aa = (undefined2)((ulonglong)lVar20 >> 0x30);
    if (lVar20 == 0) goto LAB_1800135ce;
    uVar16 = puVar23[2];
    local_208 = *(ushort *)(lVar20 + 6);
    uVar24 = (uint)puVar23[1] * (uint)uVar16;
    if ((uVar24 < 0x10000) && (uVar9 = (short)uVar24 + local_208, local_208 <= uVar9)) {
      *(ushort *)(lVar20 + 6) = uVar9;
    }
    else {
      if (param_8 != '\0') {
        uVar21 = 0xc00000b9;
        *local_220 = uVar30;
        local_220[1] = 0x24;
        goto LAB_180013508;
      }
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                ((ulonglong)uVar16,CONCAT22(puVar23[1],uVar16),(uint)local_208,
                 "Report FeatureLength integer overflow");
      uVar14 = (ulonglong)local_204;
      *(short *)(lVar20 + 6) = *(short *)(lVar20 + 6) + puVar23[1] * puVar23[2];
      puVar26 = local_1e0;
    }
    puVar11 = (ushort *)(puVar33 + 9);
    goto LAB_180012858;
  case 0xb4:
    if (puVar23 == (ushort *)&local_98) {
      uVar21 = 0xc00000b9;
      *local_220 = uVar30;
      local_220[1] = 0x12;
      local_220[2] = 0xb4;
      goto LAB_180013537;
    }
    puVar11 = *(ushort **)(puVar23 + 0x24);
    ExFreePool(puVar23);
    uVar14 = (ulonglong)local_204;
    puVar26 = local_1e0;
    puVar23 = puVar11;
    local_1b8 = puVar11;
LAB_180011e15:
    puVar11 = local_200;
    puVar27 = puVar26;
    break;
  case 0xc0:
    uVar24 = local_1c8 - 1;
    bVar34 = local_1c8 != 0;
    local_1c8 = uVar24;
    if (bVar34) {
      if (uVar24 == 0) {
        pbVar25 = (byte *)(local_218 + -8);
        if (pbVar25 != (byte *)(*(longlong *)(local_210 + 0x10) + -8)) {
          do {
            if (pbVar25 == (byte *)0x0) goto LAB_1800135ce;
            if (pbVar25[1] == (byte)local_1c0[2]) {
              if ((((*(ushort *)(pbVar25 + 2) & 7) != 0) || ((pbVar25[4] & 7) != 0)) ||
                 ((pbVar25[6] & 7) != 0)) {
                *local_220 = uVar30;
                local_220[1] = 9;
                local_220[2] = (uint)(byte)local_1c0[2];
                local_220[3] = (uint)*pbVar25;
                local_220[4] = (uint)*(ushort *)(pbVar25 + 2);
                local_220[5] = (uint)*(ushort *)(pbVar25 + 4);
                local_220[6] = (uint)*(ushort *)(pbVar25 + 6);
                goto LAB_1800135ce;
              }
              uVar16 = *(ushort *)(pbVar25 + 2) >> 3;
              if (uVar16 <= *(ushort *)((longlong)puVar33 + 0x16)) {
                uVar16 = *(ushort *)((longlong)puVar33 + 0x16);
              }
              *(ushort *)((longlong)puVar33 + 0x16) = uVar16;
              uVar16 = *(ushort *)(pbVar25 + 4) >> 3;
              if (*(ushort *)(pbVar25 + 4) >> 3 <= *(ushort *)((longlong)puVar33 + 0x1e)) {
                uVar16 = *(ushort *)((longlong)puVar33 + 0x1e);
              }
              *(ushort *)((longlong)puVar33 + 0x1e) = uVar16;
              uVar16 = *(ushort *)(pbVar25 + 6) >> 3;
              if (*(ushort *)(pbVar25 + 6) >> 3 <= *(ushort *)((longlong)puVar33 + 0x26)) {
                uVar16 = *(ushort *)((longlong)puVar33 + 0x26);
              }
              *(ushort *)((longlong)puVar33 + 0x26) = uVar16;
              if (*pbVar25 == 0) {
                *(ushort *)(pbVar25 + 2) = (*(ushort *)(pbVar25 + 2) >> 3) - 1;
                *(ushort *)(pbVar25 + 4) = (*(ushort *)(pbVar25 + 4) >> 3) - 1;
                uVar16 = (*(ushort *)(pbVar25 + 6) >> 3) - 1;
              }
              else {
                uVar16 = 0;
                if ((ushort)local_1a0 != *(ushort *)(pbVar25 + 2)) {
                  uVar16 = *(ushort *)(pbVar25 + 2) >> 3;
                }
                *(ushort *)(pbVar25 + 2) = uVar16;
                uVar16 = 0;
                if ((ushort)local_1a0 != *(ushort *)(pbVar25 + 4)) {
                  uVar16 = *(ushort *)(pbVar25 + 4) >> 3;
                }
                *(ushort *)(pbVar25 + 4) = uVar16;
                uVar16 = 0;
                if ((ushort)local_1a0 != *(ushort *)(pbVar25 + 6)) {
                  uVar16 = *(ushort *)(pbVar25 + 6) >> 3;
                }
              }
              *(ushort *)(pbVar25 + 6) = uVar16;
            }
            pbVar25 = pbVar25 + -8;
          } while (pbVar25 != (byte *)(*(longlong *)(local_210 + 0x10) + -8));
          puVar11 = local_200;
        }
        uVar16 = *(ushort *)((longlong)puVar33 + 0x16);
        local_1c0[10] = uVar16;
        if (uVar16 == 1) {
          *(undefined2 *)((longlong)puVar33 + 0x16) = 0;
          local_1c0[10] = 0;
        }
        uVar16 = *(ushort *)((longlong)puVar33 + 0x1e);
        local_1c0[0xb] = uVar16;
        if (uVar16 == 1) {
          *(undefined2 *)((longlong)puVar33 + 0x1e) = 0;
          local_1c0[0xb] = 0;
        }
        uVar16 = *(ushort *)((longlong)puVar33 + 0x26);
        local_1c0[0xc] = uVar16;
        if (uVar16 == 1) {
          *(undefined2 *)((longlong)puVar33 + 0x26) = 0;
          local_1c0[0xc] = 0;
        }
        goto LAB_180011e24;
      }
      if (puVar26 < local_180) {
        if (puVar26[2] < *(ushort *)((longlong)puVar33 + 0x2a)) {
          local_1e0 = local_188 + (ulonglong)puVar26[2] * 8;
          puVar11 = puVar26;
          puVar27 = local_1e0;
          local_200 = puVar26;
          break;
        }
      }
    }
LAB_1800135ce:
    uVar21 = 0xc00000b9;
    goto LAB_180013508;
  }
  puVar26 = puVar27;
  pcVar28 = local_218;
LAB_180011e1f:
LAB_180011e24:
  uVar15 = uVar31;
  if (local_228 <= (uint)uVar31) goto LAB_1800137da;
  goto LAB_1800114b3;
code_r0x000180012cd6:
  uVar16 = local_1f6;
  goto LAB_1800129b1;
code_r0x00018001333c:
  *(uint *)(puVar22 + 0xc) = *(uint *)(puVar22 + 0xc) & 0xffffffdf;
  local_1d8 = local_1d8 + uVar16;
  if (*pbVar12 == 0) {
    sVar10 = 0;
  }
  else {
    sVar10 = *(short *)(pbVar12 + 8) - *(short *)(pbVar12 + 6);
  }
  uVar16 = sVar10 + 1;
  local_208 = local_208 - local_1b8[1] * uVar16;
  if (local_1b8[2] <= local_1d8) goto LAB_180012969;
  goto LAB_180012f30;
}



===== entry @ 180015010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 180015044 =====

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



===== DllInitialize @ 180015080 =====

undefined8 DllInitialize(void)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x15080  1  DllInitialize */
  __security_init_cookie();
  wil_InitializeFeatureStaging();
  local_28 = 0;
  uStack_20 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitAnsiString(&local_28,"hidparse.sys");
    local_18 = local_28;
    uStack_10 = uStack_20;
    InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_18);
  }
  return 0;
}



===== DriverEntry @ 1800151b8 =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== wil_InitializeFeatureStaging @ 1800151c4 =====

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
    ppuVar4 = &Feature_2176477499__private_descriptor;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1800152b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &Feature_2176477499__private_descriptor;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) {
      return;
    }
    local_30 = 0;
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    if ((*(char *)((longlong)plVar2 + 0x1d) == '\0') && (*(char *)((longlong)plVar2 + 0x1e) == '\0')
       ) {
      iVar1 = RtlQueryFeatureConfiguration
                        ((int)plVar2[3],1 < (byte)(*(char *)((longlong)plVar2 + 0x1c) - 2U),
                         &local_30,&local_28);
      if (iVar1 == -0x7fffffde) {
        local_38 = 0x206;
        uVar4 = 0x206;
        do {
          *(undefined8 *)*plVar2 = uVar4;
          plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2 + 7);
        } while (plVar2 != (longlong *)0x0);
        return;
      }
    }
    else {
      iVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,(uint *)&local_38);
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


