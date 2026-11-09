
===== RestoreAbnormalDevices @ 00011000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001145f) */
/* WARNING: Removing unreachable block (ram,0x000110d7) */
/* WARNING: Removing unreachable block (ram,0x0001140e) */
/* WARNING: Removing unreachable block (ram,0x000115a0) */

void RestoreAbnormalDevices(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  ulonglong uVar2;
  code *pcVar3;
  bool bVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  short sVar9;
  undefined2 uVar10;
  ulonglong uVar11;
  byte bVar12;
  uint uVar13;
  longlong lVar14;
  undefined8 uVar15;
  ushort *puVar16;
  int iVar17;
  uint *puVar18;
  int iVar19;
  undefined8 uVar20;
  uint uVar21;
  byte *pbVar22;
  bool bVar23;
  undefined1 auStack_88 [32];
  ulonglong local_68;
  uint local_60 [2];
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  char *local_40;
  char local_38 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  local_50 = 0;
  local_58 = 0;
  bVar4 = false;
  uVar13 = 0;
  local_48 = param_1;
  do {
    uVar11 = (ulonglong)uVar13;
    if (7 < uVar11) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(8);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    bVar5 = *(byte *)(uVar11 + 0x948 + param_1);
    local_38[uVar11] = '\0';
    if ((bVar5 != 0) && (cVar7 = *(char *)(uVar11 + param_2), cVar7 != '\0')) {
      if ((bVar5 & 2) == 0) {
        if ((bVar5 & 4) == 0) {
          if (((bVar5 & 1) != 0) &&
             (((cVar7 == '\x01' && ((*(byte *)(param_1 + 0xab8 + uVar11 * 2) & 1) != 0)) ||
              ((cVar7 == '\x02' && ((*(byte *)(param_1 + 0xab8 + uVar11 * 2) & 1) == 0))))))
          goto LAB_00011176;
        }
        else if (cVar7 == '\x02') {
          bVar23 = (*(byte *)((longlong)(int)(uVar13 >> 1 & 0x80000003) * 0x80 + 0x128 +
                             *(longlong *)(param_1 + 0x58)) & 1) == 0;
          goto LAB_000110aa;
        }
      }
      else if (cVar7 == '\x02') {
        ReadWriteHostSStatusRegister(param_1,uVar13,param_3,(uint *)&local_68);
        *(uint *)(param_1 + 0x100 + uVar11 * 4) = (uint)local_68;
        bVar23 = (local_68 & 1) == 0;
LAB_000110aa:
        if ((bVar23) || ((*(ushort *)(param_1 + 0xab8 + uVar11 * 2) & 0x2000) != 0))
        goto LAB_00011176;
      }
      bVar5 = *(byte *)(uVar11 + 0x948 + param_1);
      local_38[uVar11] = '\x01';
      if ((bVar5 & 2) == 0) {
        if ((((bVar5 & 4) != 0) && (*(int *)(param_1 + 0x4834) == 0)) &&
           ((*(ushort *)(param_1 + 0xab8 + uVar11 * 2) & 0x4000) == 0)) {
          param_3 = 0;
          AhciResetPort(param_1,uVar13 >> 1,'\0');
        }
      }
      else if ((*(int *)(param_1 + 0x4834) == 0) &&
              ((*(ushort *)(param_1 + 0xab8 + uVar11 * 2) & 0x4000) == 0)) {
        CommReset(param_1,uVar13);
      }
    }
LAB_00011176:
    uVar13 = uVar13 + 1;
  } while (uVar13 < 8);
  uVar13 = 0;
  local_68 = local_68 & 0xffffffff00000000;
  uVar11 = 0;
  do {
    iVar19 = (int)uVar11;
    bVar5 = *(byte *)(uVar11 + 0x948 + param_1);
    if ((bVar5 != 0) && ((local_38[uVar11] != '\0' || (local_38[iVar19 + 1] != '\0')))) {
      if ((bVar5 & 1) != 0) {
        iVar1 = *(int *)(param_1 + 0x20c);
        if (bVar5 == 1) {
          if (iVar1 == 0x5811106) {
            uVar2 = *(ulonglong *)(param_1 + 0xc0 + (ulonglong)uVar13 * 8);
            uVar10 = (undefined2)uVar2;
            out(uVar10,4);
            StorPortStallExecution(99,uVar2 & 0xffff);
            out(uVar10,0);
            lVar14 = 2000;
            do {
              StorPortStallExecution(1000);
              lVar14 = lVar14 + -1;
            } while (lVar14 != 0);
            StorPortStallExecution(0);
          }
          else {
            if (iVar1 == 0x31641106) {
              bVar5 = 0x58;
              iVar17 = 0x48;
            }
            else {
              if (iVar1 != 0x32491106) goto LAB_0001133b;
              bVar5 = 0xb8;
              iVar17 = 0xa8;
            }
            local_60[0] = *(uint *)(param_1 + 0x21c) & 0xffffff00;
            uVar21 = bVar5 + local_60[0];
            uVar8 = ReadConfigSpaceUlong(param_1,uVar21);
            if ((uVar13 & 1) == 0) {
              uVar8 = uVar8 | 0x800000;
            }
            else {
              uVar8 = uVar8 | 0x400000;
            }
            WriteConfigSpaceUlong(param_1,uVar21,uVar8);
            lVar14 = 5000;
            do {
              StorPortStallExecution(1000);
              lVar14 = lVar14 + -1;
            } while (lVar14 != 0);
            StorPortStallExecution(0);
            if ((uVar13 & 1) == 0) {
              uVar8 = uVar8 & 0xff7fffff;
            }
            else {
              uVar8 = uVar8 & 0xffbfffff;
            }
            WriteConfigSpaceUlong(param_1,uVar21,uVar8);
            lVar14 = 3000;
            do {
              StorPortStallExecution(1000);
              lVar14 = lVar14 + -1;
            } while (lVar14 != 0);
            StorPortStallExecution(0);
            uVar13 = iVar17 + local_60[0];
            if (iVar1 == 0x31641106) {
              uVar8 = 0xa8a8a8a8;
            }
            else if (iVar1 == 0x32491106) {
              uVar8 = ReadConfigSpaceUlong(param_1,uVar13);
              uVar8 = uVar8 & 0xffff | 0xa8a80000;
            }
            WriteConfigSpaceUlong(param_1,uVar13,uVar8);
            StorPortStallExecution(1000);
            StorPortStallExecution(0);
            uVar13 = (uint)local_68;
          }
        }
LAB_0001133b:
        bVar4 = true;
      }
      local_38[uVar11] = '\x01';
      local_38[iVar19 + 1] = '\x01';
    }
    uVar8 = 0;
    lVar14 = 2000;
    uVar13 = uVar13 + 1;
    uVar11 = (ulonglong)(iVar19 + 2U);
    local_68 = CONCAT44(local_68._4_4_,uVar13);
  } while (iVar19 + 2U < 8);
  if (bVar4) {
    do {
      StorPortStallExecution(1000);
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    StorPortStallExecution(0);
  }
  pbVar22 = (byte *)(param_1 + 0x948);
  local_40 = local_38 + -(longlong)pbVar22;
  local_68 = -(longlong)pbVar22;
  puVar18 = (uint *)(param_1 + 0x100);
  puVar16 = (ushort *)(param_1 + 0xab8);
  uVar20 = local_58;
  do {
    bVar5 = *pbVar22;
    if ((bVar5 != 0) && (pbVar22[(longlong)local_40] != 0)) {
      if ((bVar5 & 2) == 0) {
        if (((bVar5 & 4) == 0) ||
           ((*(byte *)((longlong)(int)(uVar8 >> 1 & 0x80000003) * 0x80 + 0x128 +
                      *(longlong *)(param_1 + 0x58)) & 1) != 0)) goto LAB_00011430;
      }
      else {
        ReadWriteHostSStatusRegister(param_1,uVar8,0x8000,local_60);
        *puVar18 = local_60[0];
        if ((local_60[0] & 1) != 0) {
LAB_00011430:
          uVar15 = 0x8000;
          bVar5 = *pbVar22;
          bVar12 = (byte)uVar8;
          if ((bVar5 & 4) == 0) {
            if ((((*puVar16 & 0x2000) == 0) || ((bVar5 & 2) == 0)) &&
               (((*puVar16 & 0x8000) == 0 || ((bVar5 & 2) == 0)))) {
              local_50 = *(undefined8 *)
                          (param_1 + 0xa0 + ((ulonglong)(pbVar22 + local_68) >> 1) * 8);
              local_58 = *(undefined8 *)
                          (param_1 + 0xc0 + ((ulonglong)(pbVar22 + local_68) >> 1) * 8);
              sVar9 = (short)local_50 + 6;
              cVar7 = (bVar12 & 1 | 0xfa) << 4;
              out(sVar9,cVar7);
              uVar10 = (undefined2)local_58;
              in(uVar10);
              uVar13 = 0;
              do {
                out(sVar9,cVar7);
                cVar6 = in(uVar10);
                if (-1 < cVar6) break;
                StorPortStallExecution(1000);
                StorPortStallExecution(0);
                uVar13 = uVar13 + 1;
              } while (uVar13 < 40000);
              out(sVar9,cVar7);
              in(uVar10);
              param_1 = local_48;
              uVar20 = local_58;
              goto LAB_00011547;
            }
          }
          else if (((*puVar16 & 0x2000) == 0) && ((*puVar16 & 0x8000) == 0)) {
            lVar14 = *(longlong *)(param_1 + 0x58);
            uVar13 = 0;
            do {
              if (-1 < *(char *)(((longlong)(int)(uVar8 >> 1 & 0x80000003) + 2) * 0x80 + lVar14 +
                                0x20)) break;
              StorPortStallExecution(0x96);
              uVar13 = uVar13 + 1;
            } while (uVar13 < 20000);
LAB_00011547:
            IsDevReady(param_1,uVar8,uVar15);
            if ((*puVar16 & 1) != 0) {
              if (*(int *)(param_1 + 0x4834) == 0) {
                SetAllFeature(param_1,bVar12,uVar15);
              }
              if ((*puVar16 & 2) == 0) {
                SetDriveParameters(param_1,bVar12);
              }
              DevInitializeEx(param_1,uVar8);
              if ((*pbVar22 & 4) == 0) {
                out((short)local_50 + 6,(bVar12 & 1 | 0xfa) << 4);
                uVar13 = 0;
                do {
                  cVar7 = in((short)uVar20);
                  if (-1 < cVar7) break;
                  StorPortStallExecution(0x96);
                  uVar13 = uVar13 + 1;
                } while (uVar13 < 20000);
              }
              else {
                lVar14 = *(longlong *)(param_1 + 0x58);
                uVar13 = 0;
                do {
                  if (-1 < *(char *)(((longlong)(int)(uVar8 >> 1 & 0x80000003) + 2) * 0x80 + lVar14
                                    + 0x20)) break;
                  StorPortStallExecution(0x96);
                  uVar13 = uVar13 + 1;
                } while (uVar13 < 20000);
              }
            }
          }
        }
      }
    }
    uVar8 = uVar8 + 1;
    puVar18 = puVar18 + 1;
    puVar16 = puVar16 + 1;
    pbVar22 = pbVar22 + 1;
    if (7 < uVar8) {
      return;
    }
  } while( true );
}



===== RestoreOneAbnormalDevice @ 00011664 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RestoreOneAbnormalDevice(longlong param_1,byte param_2,longlong param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  byte bVar9;
  int iVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  short sVar14;
  longlong lVar15;
  byte *pbVar16;
  char *pcVar17;
  undefined4 *puVar18;
  uint uVar19;
  ushort *puVar20;
  byte **ppbVar21;
  undefined1 *puVar22;
  ulonglong uVar23;
  int *piVar24;
  longlong lVar25;
  longlong lVar26;
  uint *puVar27;
  undefined8 *puVar28;
  uint *puVar29;
  byte *pbVar30;
  uint uVar31;
  int iVar32;
  byte *pbVar33;
  bool bVar34;
  undefined8 uStack_f0;
  undefined1 auStack_e8 [8];
  undefined1 auStack_e0 [24];
  undefined4 auStack_c8 [4];
  int *piStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  byte abStack_70 [8];
  byte *pbStack_68;
  ulonglong uStack_60;
  
  uVar11 = 0;
  bVar34 = true;
  while (bVar34) {
    abStack_70[uVar11 + 0x58] = 0;
    uVar11 = uVar11 + 1;
    bVar34 = uVar11 < 8;
    if (7 < (longlong)uVar11) {
      abStack_70[(ulonglong)param_2 + 0x58] = 2;
      RestoreAbnormalDevices(param_1,(longlong)(abStack_70 + 0x58),param_3);
      return;
    }
  }
  lVar15 = 8;
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)();
  puVar22 = auStack_e8;
  uStack_60 = __security_cookie ^ (ulonglong)auStack_e8;
  uVar11 = 0;
  piStack_b8 = (int *)(*(longlong *)(lVar15 + 0x4848) + 0x40);
  iVar10 = 7;
  iVar32 = 6;
  if ((*(char *)(lVar15 + 0x14b4) == '\0') || (param_2 == 0)) {
    if (*(char *)(lVar15 + 0x14c2) != '\0') {
      *(undefined1 *)(lVar15 + 0x14c2) = 0;
    }
    uVar13 = 0x2000;
    lVar26 = lVar15;
    puVar22 = auStack_e8;
    if (*(int *)(lVar15 + 0x90) == 2) {
      uVar19 = 0;
      param_3 = lVar15 - (longlong)abStack_70;
      uVar12 = 0;
      do {
        if (*(char *)((longlong)register0x00000020 + param_3 + uVar12 + 0x144a) == '\0') {
          if (7 < uVar12) {
            lVar26 = 8;
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)();
            puVar22 = auStack_e0;
            goto LAB_0001178a;
          }
          abStack_70[uVar12] = 0;
        }
        else {
          abStack_70[uVar12] = 2;
        }
        uVar19 = uVar19 + 1;
        uVar12 = uVar12 + 1;
        puVar22 = auStack_e8;
      } while (uVar19 < 8);
    }
    else {
LAB_0001178a:
      pbVar16 = (byte *)(lVar26 + 0x39a);
      puVar20 = (ushort *)(lVar26 + 0xab8);
      uVar23 = uVar11 & 0xffffffff;
      pbStack_68 = pbVar16;
      uVar12 = uVar11;
      do {
        uVar2 = *puVar20;
        if ((uVar2 & 0x8000) != 0) goto LAB_00011b0a;
        if (7 < uVar11) goto LAB_00011ee1;
        abStack_70[uVar11] = (byte)uVar12;
        uVar19 = (uint)uVar23;
        if (((ushort)uVar13 & uVar2) == 0) {
LAB_00011800:
          if (*(char *)(uVar11 + 0x14ba + lVar15) == (char)uVar12) {
            *(undefined8 *)(puVar22 + -8) = 0x11815;
            bVar9 = GetDevExistStatus(lVar15,uVar19,param_3);
            if (1 < bVar9) {
              if (*(char *)(uVar11 + 0x948 + lVar15) == '\x01') {
                uVar31 = 0;
                do {
                  *(undefined8 *)(puVar22 + -8) = 0x11836;
                  StorPortStallExecution(200);
                  *(undefined8 *)(puVar22 + -8) = 0x11841;
                  bVar9 = GetDevExistStatus(lVar15,uVar19,param_3);
                  if (bVar9 < 2) goto LAB_000118e5;
                  uVar31 = uVar31 + 1;
                } while (uVar31 < 10);
              }
              abStack_70[uVar11] = 1;
            }
LAB_000118e5:
            uVar12 = 0;
            uVar13 = 0x2000;
          }
          else if (((ushort)uVar13 & *puVar20) == 0) {
            *(undefined8 *)(puVar22 + -8) = 0x1187c;
            uVar12 = IsDevReady(lVar15,uVar19,param_3);
            if (((char)uVar12 == '\0') || (3 < *pbVar16)) {
              abStack_70[uVar11] = 2;
            }
            uVar2 = *puVar20;
            if ((uVar2 & 0x8000) != 0) {
              abStack_70[uVar11] = 0;
            }
            if (((abStack_70[uVar11] == 0) || ((uVar2 & 1) == 0)) || ((uVar2 & 2) == 0))
            goto LAB_000118e5;
            *(undefined8 *)(puVar22 + -8) = 0x118be;
            bVar9 = GetDevExistStatus(lVar15,uVar19,param_3);
            uVar12 = 0;
            uVar13 = 0x2000;
            if (bVar9 != 0) {
              abStack_70[uVar11] = 0;
            }
          }
          else {
            abStack_70[uVar11] = 2;
          }
        }
        else {
          *(undefined8 *)(puVar22 + -8) = 0x117d7;
          bVar9 = GetDevExistStatus(lVar15,uVar19,param_3);
          uVar13 = 0x2000;
          if (bVar9 != 4) {
            uVar12 = 0;
            goto LAB_00011800;
          }
          abStack_70[uVar11] = 2;
          *puVar20 = *puVar20 & 0xdfff;
          uVar12 = 0;
        }
        uVar23 = (ulonglong)(uVar19 + 1);
        uVar11 = uVar11 + 1;
        puVar20 = puVar20 + 1;
        pbVar16 = pbVar16 + 0xb8;
      } while (uVar19 + 1 < 8);
      uVar23 = uVar12 & 0xffffffff;
      uVar11 = uVar12;
      do {
        iVar32 = (int)uVar23;
        if (((abStack_70[uVar11] == 2) && (*(char *)(uVar11 + 0x948 + lVar15) == '\x02')) &&
           (*(int *)(lVar15 + 0x20c) == 0x5811106)) {
          if (iVar32 == 0) {
            if (abStack_70[1] == (byte)uVar12) {
              uVar19 = 1;
LAB_0001194e:
              *(undefined8 *)(puVar22 + -8) = 0x11956;
              CommReset(lVar15,uVar19);
              uVar12 = 0;
            }
          }
          else if ((iVar32 == 1) && (abStack_70[0] == (byte)uVar12)) {
            uVar19 = 0;
            goto LAB_0001194e;
          }
        }
        uVar23 = (ulonglong)(iVar32 + 1U);
        uVar11 = uVar11 + 1;
      } while (iVar32 + 1U < 8);
      uVar11 = uVar12 & 0xffffffff;
      pbVar16 = abStack_70;
      do {
        uVar19 = (uint)uVar11;
        bVar9 = (byte)uVar12;
        if (*pbVar16 != bVar9) break;
        uVar19 = uVar19 + 1;
        uVar11 = (ulonglong)uVar19;
        pbVar16 = pbVar16 + 1;
      } while (uVar19 < 8);
      if (7 < uVar19) goto LAB_00011b0a;
      pbVar16 = abStack_70;
      lVar26 = 8;
      pbVar33 = pbStack_68;
      do {
        if (*pbVar16 != bVar9) {
          *pbVar33 = bVar9;
        }
        pbVar16 = pbVar16 + 1;
        pbVar33 = pbVar33 + 0xb8;
        lVar26 = lVar26 + -1;
      } while (lVar26 != 0);
      *(undefined8 *)(puVar22 + -8) = 0x119af;
      RestoreAbnormalDevices(lVar15,(longlong)abStack_70,param_3);
      puVar20 = (ushort *)(lVar15 + 0xab8);
      *(undefined1 *)(lVar15 + 0x2c) = 0;
      uVar19 = 0;
      uVar11 = 0;
      do {
        if (((*puVar20 & 0x2000) == 0) || (abStack_70[uVar11] != 2)) {
          if (7 < uVar11) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(8);
LAB_00011ee1:
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(8);
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          abStack_70[uVar11] = 0;
          *(undefined8 *)(puVar22 + -8) = 0x119ef;
          uVar12 = IsDevReady(lVar15,uVar19,param_3);
          bVar9 = (byte)uVar12;
          abStack_70[uVar11 + 8] = bVar9;
          if (*(char *)(uVar11 + 0x14ba + lVar15) == '\0') {
            if (bVar9 != 0) {
              abStack_70[uVar11] = 1;
            }
          }
          else {
            if (bVar9 == 0) {
              abStack_70[uVar11] = 2;
            }
            if (((abStack_70[uVar11] != 0) && ((*puVar20 & 1) != 0)) && ((*puVar20 & 2) != 0)) {
              *(undefined8 *)(puVar22 + -8) = 0x11a3a;
              bVar9 = GetDevExistStatus(lVar15,uVar19,param_3);
              if (bVar9 != 0) {
                abStack_70[uVar11] = 0;
              }
            }
          }
        }
        uVar19 = uVar19 + 1;
        uVar11 = uVar11 + 1;
        puVar20 = puVar20 + 1;
      } while (uVar19 < 8);
    }
    piVar24 = piStack_b8;
    puVar29 = (uint *)0x0;
    uVar11 = 0;
    puVar18 = (undefined4 *)(lVar15 + 0x4850);
    puVar20 = (ushort *)(lVar15 + 0xab8);
    puVar27 = puVar29;
    do {
      if ((abStack_70[uVar11] == 2) && ((*puVar20 & 0x2000) != 0)) {
        *puVar20 = 0x2000;
        *puVar18 = 0;
        if (*(char *)(uVar11 + 0x14ba + lVar15) == '\0') {
          if (7 < uVar11) {
            pcVar4 = (code *)swi(0x29);
            uVar11 = (*pcVar4)(8);
            puVar22 = puVar22 + 8;
            goto LAB_00011b3c;
          }
          abStack_70[uVar11] = 0;
        }
      }
      uVar19 = (int)puVar27 + 1;
      puVar27 = (uint *)(ulonglong)uVar19;
      uVar11 = uVar11 + 1;
      puVar20 = puVar20 + 1;
      puVar18 = puVar18 + 1;
    } while (uVar19 < 8);
    uVar19 = 0;
    pbVar16 = abStack_70;
    do {
      if (*pbVar16 != 0) break;
      uVar19 = uVar19 + 1;
      pbVar16 = pbVar16 + 1;
    } while (uVar19 < 8);
    if (7 < uVar19) {
      if ((*(int *)(lVar15 + 0x4834) != 0) && (*(char *)(lVar15 + 0x14b8) != '\0')) {
        uVar11 = 0;
        pcVar17 = (char *)(lVar15 + 0x4828);
        do {
          if (*pcVar17 != '\0') goto LAB_00011b3c;
          uVar19 = (int)uVar11 + 1;
          uVar11 = (ulonglong)uVar19;
          pcVar17 = pcVar17 + 1;
        } while (uVar19 < 8);
      }
      goto LAB_00011b0a;
    }
    pbVar16 = abStack_70;
    puVar18 = (undefined4 *)(lVar15 + 0xae0);
    lVar26 = 8;
    do {
      lVar25 = lVar26;
      if (*pbVar16 != 0) {
        *puVar18 = 0;
      }
      puVar18 = puVar18 + 1;
      pbVar16 = pbVar16 + 1;
      lVar26 = lVar25 + -1;
    } while (lVar26 != 0);
    uVar19 = 0;
    pbVar16 = abStack_70;
    iVar32 = (int)lVar25 + 0x17;
    puVar18 = (undefined4 *)0x0;
    do {
      bVar9 = *pbVar16;
      if ((bVar9 != 0) && (Hibernate == '\0')) {
        *piVar24 = iVar32;
        piVar24[1] = 100;
        piVar24[2] = 0;
        piVar24[3] = (uint)bVar9;
        iVar10 = *(int *)(lVar15 + 0x98);
        piVar24[5] = uVar19;
        piVar24[4] = iVar10;
        uVar8 = uRam00000000000362b4;
        uVar7 = uRam00000000000362b0;
        uVar6 = uRam00000000000362ac;
        uVar5 = _HotPlug_Of_Event;
        puVar18 = *(undefined4 **)(lVar15 + 0x4848);
        puVar27 = (uint *)0xff;
        puVar18[0xb] = 0x8a;
        puVar18[6] = uVar5;
        puVar18[7] = uVar6;
        puVar18[8] = uVar7;
        puVar18[9] = uVar8;
        puVar18[3] = 0;
        puVar18[0xd] = 0;
        puVar18[0xf] = iVar32;
        puVar18[0xe] = 0x40;
        *puVar18 = 0x58;
        *(undefined8 *)(puVar22 + -8) = 0x11c11;
        ScsiPortNotification(8);
      }
      uVar19 = uVar19 + 1;
      pbVar16 = pbVar16 + 1;
    } while (uVar19 < 8);
    *(byte *)(lVar15 + 0x14c3) = *(byte *)(lVar15 + 0x14c3) | 1;
    if (*(int *)(lVar15 + 0x4834) != 0) {
      *(undefined1 *)(lVar15 + 0x4830) = 1;
    }
    *(undefined8 *)(puVar22 + -8) = 0x11c42;
    SataResetController(lVar15,'\0',puVar18,puVar27);
    *(undefined8 *)(puVar22 + -8) = 0x11c4a;
    AhciResetInterrupt(lVar15);
    uVar19 = 0;
    uStack_b0 = *(undefined8 *)(lVar15 + 0xc0);
    ppbVar21 = &pbStack_68;
    uStack_a8 = *(undefined8 *)(lVar15 + 200);
    uStack_a0 = *(undefined8 *)(lVar15 + 0xd0);
    uStack_98 = *(undefined8 *)(lVar15 + 0xd8);
    uStack_90 = *(undefined8 *)(lVar15 + 0xa0);
    uStack_88 = *(undefined8 *)(lVar15 + 0xa8);
    uStack_80 = *(undefined8 *)(lVar15 + 0xb0);
    uStack_78 = *(undefined8 *)(lVar15 + 0xb8);
    do {
      uVar31 = uVar19 * 2;
      uVar19 = uVar19 + 1;
      *(undefined1 *)ppbVar21 = *(undefined1 *)((ulonglong)uVar31 + 0x948 + lVar15);
      ppbVar21 = (byte **)((longlong)ppbVar21 + 1);
    } while (uVar19 < 4);
    ppbVar21 = &pbStack_68;
    puVar28 = &uStack_b0;
    lVar26 = 4;
    do {
      lVar25 = lVar26;
      if ((*(byte *)ppbVar21 != 0) && ((*(byte *)ppbVar21 & 4) == 0)) {
        uVar3 = *(undefined2 *)puVar28;
        out(uVar3,0);
        *(undefined8 *)(puVar22 + -8) = 0x11cea;
        StorPortStallExecution(100,uVar3);
      }
      ppbVar21 = (byte **)((longlong)ppbVar21 + 1);
      puVar28 = puVar28 + 1;
      lVar26 = lVar25 + -1;
    } while (lVar26 != 0);
    uVar19 = 0;
    uVar11 = 0;
    do {
      bVar9 = *(byte *)(lVar15 + 0x948 + uVar11);
      if ((bVar9 != 0) && ((bVar9 & 4) == 0)) {
        out(*(short *)(abStack_70 + (uVar11 >> 1) * 8 + -0x20) + 6,((byte)uVar19 & 1 | 0xfa) << 4);
        in((short)lVar25 + 6 + *(short *)(abStack_70 + (uVar11 >> 1) * 8 + -0x20));
      }
      uVar19 = uVar19 + 1;
      uVar11 = uVar11 + 1;
    } while (uVar19 < 8);
    ppbVar21 = &pbStack_68;
    puVar28 = (undefined8 *)(lVar15 + 0xe0);
    lVar26 = 4;
    do {
      lVar25 = lVar26;
      if ((*(byte *)ppbVar21 != 0) && ((*(byte *)ppbVar21 & 4) == 0)) {
        sVar14 = (short)*puVar28;
        bVar9 = in(sVar14);
        out(sVar14,bVar9 & 0xfe);
        bVar9 = in(sVar14 + 2);
        out(sVar14 + 2,bVar9 | 6);
      }
      puVar28 = puVar28 + 1;
      ppbVar21 = (byte **)((longlong)ppbVar21 + 1);
      lVar26 = lVar25 + -1;
    } while (lVar26 != 0);
    pbVar16 = (byte *)(lVar15 + 0xab8);
    if (*(char *)(lVar15 + 0x14b5) != '\0') {
      iVar32 = 0;
      pbVar33 = abStack_70;
      piVar24 = (int *)(lVar15 + 0x388);
      uVar11 = (ulonglong)((int)lVar25 + 1);
      pbVar30 = pbVar16;
      do {
        if (*pbVar33 == 1) {
          if ((((*pbVar30 & 1) != 0) && (piVar24[3] == 0)) && (*piVar24 != 0)) {
            *(undefined8 *)(puVar22 + -8) = 0x11dc9;
            HideParentLogicTarget(lVar15,(byte)iVar32,1);
          }
          uVar11 = 2;
        }
        iVar32 = iVar32 + 1;
        pbVar30 = pbVar30 + uVar11;
        pbVar33 = pbVar33 + 1;
        piVar24 = piVar24 + 0x2e;
      } while (iVar32 < 8);
      *(undefined8 *)(puVar22 + -8) = 0x11deb;
      uVar13 = HasLogicDevice(lVar15);
      if ((char)uVar13 == '\0') {
        iVar32 = 0;
        pbVar33 = abStack_70;
        piVar24 = (int *)(lVar15 + 0x388);
        pbVar30 = pbVar16;
        do {
          if (((*pbVar33 == 1) && ((*pbVar30 & 1) != 0)) && ((piVar24[3] == 0 && (*piVar24 != 0))))
          {
            *(undefined8 *)(puVar22 + -8) = 0x11e2b;
            HideParentLogicTarget(lVar15,(byte)iVar32,0);
          }
          iVar32 = iVar32 + 1;
          pbVar30 = pbVar30 + 2;
          pbVar33 = pbVar33 + 1;
          piVar24 = piVar24 + 0x2e;
        } while (iVar32 < 8);
      }
    }
    pbVar33 = (byte *)(lVar15 + 0x14ba);
    lVar26 = 8;
    do {
      lVar25 = lVar26;
      bVar9 = *pbVar16;
      pbVar16 = pbVar16 + 2;
      *pbVar33 = bVar9 & 1;
      pbVar33 = pbVar33 + 1;
      lVar26 = lVar25 + -1;
    } while (lVar26 != 0);
    iVar32 = (int)lVar25;
    iVar10 = iVar32 + 6;
    iVar32 = iVar32 + 5;
  }
  else {
    *(undefined1 *)(lVar15 + 0x14b4) = 0;
  }
  uVar1 = *(undefined1 *)(lVar15 + 0x214);
  *(undefined8 *)(puVar22 + -8) = 0x11e7d;
  StorPortNotification(iVar10,lVar15,uVar1);
  if (*(char *)(lVar15 + 0x14b9) != '\0') {
    *(undefined1 *)(lVar15 + 0x14b6) = 1;
  }
  *(undefined8 *)(puVar22 + -8) = 0x11e95;
  uVar13 = HasLogicDevice(lVar15);
  *(char *)(lVar15 + 0x14b7) = (char)uVar13;
  if ((((char)uVar13 != '\0') ||
      (*(undefined1 *)(lVar15 + 0x14b5) = 0, *(char *)(lVar15 + 0x14b8) != '\0')) ||
     ((*(char *)(lVar15 + 0x14b6) == '\0' || (*(int *)(lVar15 + 0x90) == 2)))) goto LAB_00011b0a;
  *(undefined1 *)(lVar15 + 0x14b6) = 0;
LAB_00011b49:
  *(undefined4 *)(puVar22 + 0x20) = 0xffffffff;
  *(undefined8 *)(puVar22 + -8) = 0x11b64;
  StorPortNotification(iVar32,lVar15,AtapiScsiTimer,3000000);
LAB_00011b0a:
  *(undefined8 *)(puVar22 + -8) = 0x11b16;
  return;
LAB_00011b3c:
  *(char *)(uVar11 + 0x4828 + lVar15) = (char)puVar29;
  iVar32 = 6;
  goto LAB_00011b49;
}



===== CheckController @ 000116b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CheckController(longlong param_1,char param_2,longlong param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  byte bVar9;
  int iVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  short sVar13;
  ulonglong uVar14;
  byte *pbVar15;
  char *pcVar16;
  undefined4 *puVar17;
  uint uVar18;
  ushort *puVar19;
  byte **ppbVar20;
  undefined1 *puVar21;
  ulonglong uVar22;
  int *piVar23;
  longlong lVar24;
  longlong lVar25;
  uint *puVar26;
  undefined8 *puVar27;
  uint *puVar28;
  byte *pbVar29;
  uint uVar30;
  int iVar31;
  byte *pbVar32;
  undefined8 uStack_c0;
  undefined1 auStack_b8 [8];
  undefined1 auStack_b0 [24];
  undefined4 local_98 [4];
  int *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  byte local_40 [8];
  byte *local_38;
  ulonglong local_30;
  
  puVar21 = auStack_b8;
  local_30 = __security_cookie ^ (ulonglong)auStack_b8;
  uVar14 = 0;
  local_88 = (int *)(*(longlong *)(param_1 + 0x4848) + 0x40);
  iVar10 = 7;
  iVar31 = 6;
  if ((*(char *)(param_1 + 0x14b4) == '\0') || (param_2 == '\0')) {
    if (*(char *)(param_1 + 0x14c2) != '\0') {
      *(undefined1 *)(param_1 + 0x14c2) = 0;
    }
    uVar12 = 0x2000;
    lVar25 = param_1;
    puVar21 = auStack_b8;
    if (*(int *)(param_1 + 0x90) == 2) {
      uVar18 = 0;
      param_3 = param_1 - (longlong)local_40;
      uVar11 = 0;
      do {
        if (*(char *)((longlong)register0x00000020 + param_3 + uVar11 + 0x147a) == '\0') {
          if (7 < uVar11) {
            lVar25 = 8;
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)();
            puVar21 = auStack_b0;
            goto LAB_0001178a;
          }
          local_40[uVar11] = 0;
        }
        else {
          local_40[uVar11] = 2;
        }
        uVar18 = uVar18 + 1;
        uVar11 = uVar11 + 1;
        puVar21 = auStack_b8;
      } while (uVar18 < 8);
    }
    else {
LAB_0001178a:
      pbVar15 = (byte *)(lVar25 + 0x39a);
      puVar19 = (ushort *)(lVar25 + 0xab8);
      uVar22 = uVar14 & 0xffffffff;
      local_38 = pbVar15;
      uVar11 = uVar14;
      do {
        uVar2 = *puVar19;
        if ((uVar2 & 0x8000) != 0) goto LAB_00011b0a;
        if (7 < uVar14) goto LAB_00011ee1;
        local_40[uVar14] = (byte)uVar11;
        uVar18 = (uint)uVar22;
        if (((ushort)uVar12 & uVar2) == 0) {
LAB_00011800:
          if (*(char *)(uVar14 + 0x14ba + param_1) == (char)uVar11) {
            *(undefined8 *)(puVar21 + -8) = 0x11815;
            bVar9 = GetDevExistStatus(param_1,uVar18,param_3);
            if (1 < bVar9) {
              if (*(char *)(uVar14 + 0x948 + param_1) == '\x01') {
                uVar30 = 0;
                do {
                  *(undefined8 *)(puVar21 + -8) = 0x11836;
                  StorPortStallExecution(200);
                  *(undefined8 *)(puVar21 + -8) = 0x11841;
                  bVar9 = GetDevExistStatus(param_1,uVar18,param_3);
                  if (bVar9 < 2) goto LAB_000118e5;
                  uVar30 = uVar30 + 1;
                } while (uVar30 < 10);
              }
              local_40[uVar14] = 1;
            }
LAB_000118e5:
            uVar11 = 0;
            uVar12 = 0x2000;
          }
          else if (((ushort)uVar12 & *puVar19) == 0) {
            *(undefined8 *)(puVar21 + -8) = 0x1187c;
            uVar11 = IsDevReady(param_1,uVar18,param_3);
            if (((char)uVar11 == '\0') || (3 < *pbVar15)) {
              local_40[uVar14] = 2;
            }
            uVar2 = *puVar19;
            if ((uVar2 & 0x8000) != 0) {
              local_40[uVar14] = 0;
            }
            if (((local_40[uVar14] == 0) || ((uVar2 & 1) == 0)) || ((uVar2 & 2) == 0))
            goto LAB_000118e5;
            *(undefined8 *)(puVar21 + -8) = 0x118be;
            bVar9 = GetDevExistStatus(param_1,uVar18,param_3);
            uVar11 = 0;
            uVar12 = 0x2000;
            if (bVar9 != 0) {
              local_40[uVar14] = 0;
            }
          }
          else {
            local_40[uVar14] = 2;
          }
        }
        else {
          *(undefined8 *)(puVar21 + -8) = 0x117d7;
          bVar9 = GetDevExistStatus(param_1,uVar18,param_3);
          uVar12 = 0x2000;
          if (bVar9 != 4) {
            uVar11 = 0;
            goto LAB_00011800;
          }
          local_40[uVar14] = 2;
          *puVar19 = *puVar19 & 0xdfff;
          uVar11 = 0;
        }
        uVar22 = (ulonglong)(uVar18 + 1);
        uVar14 = uVar14 + 1;
        puVar19 = puVar19 + 1;
        pbVar15 = pbVar15 + 0xb8;
      } while (uVar18 + 1 < 8);
      uVar22 = uVar11 & 0xffffffff;
      uVar14 = uVar11;
      do {
        iVar31 = (int)uVar22;
        if (((local_40[uVar14] == 2) && (*(char *)(uVar14 + 0x948 + param_1) == '\x02')) &&
           (*(int *)(param_1 + 0x20c) == 0x5811106)) {
          if (iVar31 == 0) {
            if (local_40[1] == (byte)uVar11) {
              uVar18 = 1;
LAB_0001194e:
              *(undefined8 *)(puVar21 + -8) = 0x11956;
              CommReset(param_1,uVar18);
              uVar11 = 0;
            }
          }
          else if ((iVar31 == 1) && (local_40[0] == (byte)uVar11)) {
            uVar18 = 0;
            goto LAB_0001194e;
          }
        }
        uVar22 = (ulonglong)(iVar31 + 1U);
        uVar14 = uVar14 + 1;
      } while (iVar31 + 1U < 8);
      uVar14 = uVar11 & 0xffffffff;
      pbVar15 = local_40;
      do {
        uVar18 = (uint)uVar14;
        bVar9 = (byte)uVar11;
        if (*pbVar15 != bVar9) break;
        uVar18 = uVar18 + 1;
        uVar14 = (ulonglong)uVar18;
        pbVar15 = pbVar15 + 1;
      } while (uVar18 < 8);
      if (7 < uVar18) goto LAB_00011b0a;
      pbVar15 = local_40;
      lVar25 = 8;
      pbVar32 = local_38;
      do {
        if (*pbVar15 != bVar9) {
          *pbVar32 = bVar9;
        }
        pbVar15 = pbVar15 + 1;
        pbVar32 = pbVar32 + 0xb8;
        lVar25 = lVar25 + -1;
      } while (lVar25 != 0);
      *(undefined8 *)(puVar21 + -8) = 0x119af;
      RestoreAbnormalDevices(param_1,(longlong)local_40,param_3);
      puVar19 = (ushort *)(param_1 + 0xab8);
      *(undefined1 *)(param_1 + 0x2c) = 0;
      uVar18 = 0;
      uVar14 = 0;
      do {
        if (((*puVar19 & 0x2000) == 0) || (local_40[uVar14] != 2)) {
          if (7 < uVar14) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(8);
LAB_00011ee1:
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(8);
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          local_40[uVar14] = 0;
          *(undefined8 *)(puVar21 + -8) = 0x119ef;
          uVar11 = IsDevReady(param_1,uVar18,param_3);
          bVar9 = (byte)uVar11;
          local_40[uVar14 + 8] = bVar9;
          if (*(char *)(uVar14 + 0x14ba + param_1) == '\0') {
            if (bVar9 != 0) {
              local_40[uVar14] = 1;
            }
          }
          else {
            if (bVar9 == 0) {
              local_40[uVar14] = 2;
            }
            if (((local_40[uVar14] != 0) && ((*puVar19 & 1) != 0)) && ((*puVar19 & 2) != 0)) {
              *(undefined8 *)(puVar21 + -8) = 0x11a3a;
              bVar9 = GetDevExistStatus(param_1,uVar18,param_3);
              if (bVar9 != 0) {
                local_40[uVar14] = 0;
              }
            }
          }
        }
        uVar18 = uVar18 + 1;
        uVar14 = uVar14 + 1;
        puVar19 = puVar19 + 1;
      } while (uVar18 < 8);
    }
    piVar23 = local_88;
    puVar28 = (uint *)0x0;
    uVar14 = 0;
    puVar17 = (undefined4 *)(param_1 + 0x4850);
    puVar19 = (ushort *)(param_1 + 0xab8);
    puVar26 = puVar28;
    do {
      if ((local_40[uVar14] == 2) && ((*puVar19 & 0x2000) != 0)) {
        *puVar19 = 0x2000;
        *puVar17 = 0;
        if (*(char *)(uVar14 + 0x14ba + param_1) == '\0') {
          if (7 < uVar14) {
            pcVar4 = (code *)swi(0x29);
            uVar14 = (*pcVar4)(8);
            puVar21 = puVar21 + 8;
            goto LAB_00011b3c;
          }
          local_40[uVar14] = 0;
        }
      }
      uVar18 = (int)puVar26 + 1;
      puVar26 = (uint *)(ulonglong)uVar18;
      uVar14 = uVar14 + 1;
      puVar19 = puVar19 + 1;
      puVar17 = puVar17 + 1;
    } while (uVar18 < 8);
    uVar18 = 0;
    pbVar15 = local_40;
    do {
      if (*pbVar15 != 0) break;
      uVar18 = uVar18 + 1;
      pbVar15 = pbVar15 + 1;
    } while (uVar18 < 8);
    if (7 < uVar18) {
      if ((*(int *)(param_1 + 0x4834) != 0) && (*(char *)(param_1 + 0x14b8) != '\0')) {
        uVar14 = 0;
        pcVar16 = (char *)(param_1 + 0x4828);
        do {
          if (*pcVar16 != '\0') goto LAB_00011b3c;
          uVar18 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar18;
          pcVar16 = pcVar16 + 1;
        } while (uVar18 < 8);
      }
      goto LAB_00011b0a;
    }
    pbVar15 = local_40;
    puVar17 = (undefined4 *)(param_1 + 0xae0);
    lVar25 = 8;
    do {
      lVar24 = lVar25;
      if (*pbVar15 != 0) {
        *puVar17 = 0;
      }
      puVar17 = puVar17 + 1;
      pbVar15 = pbVar15 + 1;
      lVar25 = lVar24 + -1;
    } while (lVar25 != 0);
    uVar18 = 0;
    pbVar15 = local_40;
    iVar31 = (int)lVar24 + 0x17;
    puVar17 = (undefined4 *)0x0;
    do {
      bVar9 = *pbVar15;
      if ((bVar9 != 0) && (Hibernate == '\0')) {
        *piVar23 = iVar31;
        piVar23[1] = 100;
        piVar23[2] = 0;
        piVar23[3] = (uint)bVar9;
        iVar10 = *(int *)(param_1 + 0x98);
        piVar23[5] = uVar18;
        piVar23[4] = iVar10;
        uVar8 = uRam00000000000362b4;
        uVar7 = uRam00000000000362b0;
        uVar6 = uRam00000000000362ac;
        uVar5 = _HotPlug_Of_Event;
        puVar17 = *(undefined4 **)(param_1 + 0x4848);
        puVar26 = (uint *)0xff;
        puVar17[0xb] = 0x8a;
        puVar17[6] = uVar5;
        puVar17[7] = uVar6;
        puVar17[8] = uVar7;
        puVar17[9] = uVar8;
        puVar17[3] = 0;
        puVar17[0xd] = 0;
        puVar17[0xf] = iVar31;
        puVar17[0xe] = 0x40;
        *puVar17 = 0x58;
        *(undefined8 *)(puVar21 + -8) = 0x11c11;
        ScsiPortNotification(8);
      }
      uVar18 = uVar18 + 1;
      pbVar15 = pbVar15 + 1;
    } while (uVar18 < 8);
    *(byte *)(param_1 + 0x14c3) = *(byte *)(param_1 + 0x14c3) | 1;
    if (*(int *)(param_1 + 0x4834) != 0) {
      *(undefined1 *)(param_1 + 0x4830) = 1;
    }
    *(undefined8 *)(puVar21 + -8) = 0x11c42;
    SataResetController(param_1,'\0',puVar17,puVar26);
    *(undefined8 *)(puVar21 + -8) = 0x11c4a;
    AhciResetInterrupt(param_1);
    uVar18 = 0;
    local_80 = *(undefined8 *)(param_1 + 0xc0);
    ppbVar20 = &local_38;
    local_78 = *(undefined8 *)(param_1 + 200);
    local_70 = *(undefined8 *)(param_1 + 0xd0);
    local_68 = *(undefined8 *)(param_1 + 0xd8);
    local_60 = *(undefined8 *)(param_1 + 0xa0);
    local_58 = *(undefined8 *)(param_1 + 0xa8);
    local_50 = *(undefined8 *)(param_1 + 0xb0);
    local_48 = *(undefined8 *)(param_1 + 0xb8);
    do {
      uVar30 = uVar18 * 2;
      uVar18 = uVar18 + 1;
      *(undefined1 *)ppbVar20 = *(undefined1 *)((ulonglong)uVar30 + 0x948 + param_1);
      ppbVar20 = (byte **)((longlong)ppbVar20 + 1);
    } while (uVar18 < 4);
    ppbVar20 = &local_38;
    puVar27 = &local_80;
    lVar25 = 4;
    do {
      lVar24 = lVar25;
      if ((*(byte *)ppbVar20 != 0) && ((*(byte *)ppbVar20 & 4) == 0)) {
        uVar3 = *(undefined2 *)puVar27;
        out(uVar3,0);
        *(undefined8 *)(puVar21 + -8) = 0x11cea;
        StorPortStallExecution(100,uVar3);
      }
      ppbVar20 = (byte **)((longlong)ppbVar20 + 1);
      puVar27 = puVar27 + 1;
      lVar25 = lVar24 + -1;
    } while (lVar25 != 0);
    uVar18 = 0;
    uVar14 = 0;
    do {
      bVar9 = *(byte *)(param_1 + 0x948 + uVar14);
      if ((bVar9 != 0) && ((bVar9 & 4) == 0)) {
        out(*(short *)(local_40 + (uVar14 >> 1) * 8 + -0x20) + 6,((byte)uVar18 & 1 | 0xfa) << 4);
        in((short)lVar24 + 6 + *(short *)(local_40 + (uVar14 >> 1) * 8 + -0x20));
      }
      uVar18 = uVar18 + 1;
      uVar14 = uVar14 + 1;
    } while (uVar18 < 8);
    ppbVar20 = &local_38;
    puVar27 = (undefined8 *)(param_1 + 0xe0);
    lVar25 = 4;
    do {
      lVar24 = lVar25;
      if ((*(byte *)ppbVar20 != 0) && ((*(byte *)ppbVar20 & 4) == 0)) {
        sVar13 = (short)*puVar27;
        bVar9 = in(sVar13);
        out(sVar13,bVar9 & 0xfe);
        bVar9 = in(sVar13 + 2);
        out(sVar13 + 2,bVar9 | 6);
      }
      puVar27 = puVar27 + 1;
      ppbVar20 = (byte **)((longlong)ppbVar20 + 1);
      lVar25 = lVar24 + -1;
    } while (lVar25 != 0);
    pbVar15 = (byte *)(param_1 + 0xab8);
    if (*(char *)(param_1 + 0x14b5) != '\0') {
      iVar31 = 0;
      pbVar32 = local_40;
      piVar23 = (int *)(param_1 + 0x388);
      uVar14 = (ulonglong)((int)lVar24 + 1);
      pbVar29 = pbVar15;
      do {
        if (*pbVar32 == 1) {
          if ((((*pbVar29 & 1) != 0) && (piVar23[3] == 0)) && (*piVar23 != 0)) {
            *(undefined8 *)(puVar21 + -8) = 0x11dc9;
            HideParentLogicTarget(param_1,(byte)iVar31,1);
          }
          uVar14 = 2;
        }
        iVar31 = iVar31 + 1;
        pbVar29 = pbVar29 + uVar14;
        pbVar32 = pbVar32 + 1;
        piVar23 = piVar23 + 0x2e;
      } while (iVar31 < 8);
      *(undefined8 *)(puVar21 + -8) = 0x11deb;
      uVar12 = HasLogicDevice(param_1);
      if ((char)uVar12 == '\0') {
        iVar31 = 0;
        pbVar32 = local_40;
        piVar23 = (int *)(param_1 + 0x388);
        pbVar29 = pbVar15;
        do {
          if (((*pbVar32 == 1) && ((*pbVar29 & 1) != 0)) && ((piVar23[3] == 0 && (*piVar23 != 0))))
          {
            *(undefined8 *)(puVar21 + -8) = 0x11e2b;
            HideParentLogicTarget(param_1,(byte)iVar31,0);
          }
          iVar31 = iVar31 + 1;
          pbVar29 = pbVar29 + 2;
          pbVar32 = pbVar32 + 1;
          piVar23 = piVar23 + 0x2e;
        } while (iVar31 < 8);
      }
    }
    pbVar32 = (byte *)(param_1 + 0x14ba);
    lVar25 = 8;
    do {
      lVar24 = lVar25;
      bVar9 = *pbVar15;
      pbVar15 = pbVar15 + 2;
      *pbVar32 = bVar9 & 1;
      pbVar32 = pbVar32 + 1;
      lVar25 = lVar24 + -1;
    } while (lVar25 != 0);
    iVar31 = (int)lVar24;
    iVar10 = iVar31 + 6;
    iVar31 = iVar31 + 5;
  }
  else {
    *(undefined1 *)(param_1 + 0x14b4) = 0;
  }
  uVar1 = *(undefined1 *)(param_1 + 0x214);
  *(undefined8 *)(puVar21 + -8) = 0x11e7d;
  StorPortNotification(iVar10,param_1,uVar1);
  if (*(char *)(param_1 + 0x14b9) != '\0') {
    *(undefined1 *)(param_1 + 0x14b6) = 1;
  }
  *(undefined8 *)(puVar21 + -8) = 0x11e95;
  uVar12 = HasLogicDevice(param_1);
  *(char *)(param_1 + 0x14b7) = (char)uVar12;
  if ((((char)uVar12 != '\0') ||
      (*(undefined1 *)(param_1 + 0x14b5) = 0, *(char *)(param_1 + 0x14b8) != '\0')) ||
     ((*(char *)(param_1 + 0x14b6) == '\0' || (*(int *)(param_1 + 0x90) == 2)))) goto LAB_00011b0a;
  *(undefined1 *)(param_1 + 0x14b6) = 0;
LAB_00011b49:
  *(undefined4 *)(puVar21 + 0x20) = 0xffffffff;
  *(undefined8 *)(puVar21 + -8) = 0x11b64;
  StorPortNotification(iVar31,param_1,AtapiScsiTimer,3000000);
LAB_00011b0a:
  *(undefined8 *)(puVar21 + -8) = 0x11b16;
  return;
LAB_00011b3c:
  *(char *)(uVar14 + 0x4828 + param_1) = (char)puVar28;
  iVar31 = 6;
  goto LAB_00011b49;
}



===== AtapiScsiTimer @ 00011ee8 =====

void AtapiScsiTimer(ulonglong *param_1,undefined8 param_2,undefined1 *param_3)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  ulonglong *puVar5;
  longlong *plVar6;
  byte bVar7;
  bool bVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  int iVar13;
  longlong lVar14;
  uint uVar15;
  longlong lVar16;
  undefined8 uVar17;
  ulonglong *puVar18;
  ulonglong *puVar19;
  char *pcVar20;
  ulonglong *puVar21;
  uint local_res10 [2];
  char *local_res18;
  longlong local_res20;
  undefined1 *in_stack_ffffffffffffff88;
  undefined1 *puVar22;
  undefined4 uVar23;
  undefined1 local_68 [40];
  
  cVar3 = *(char *)((longlong)param_1 + 0x14c2);
  *(undefined4 *)(param_1 + 0x90e) = 1;
  if ((cVar3 == '\0') && (*(char *)((longlong)param_1 + 0x14b6) != '\0')) {
    *(undefined4 *)(param_1 + 0x90e) = 0;
    return;
  }
  if (Hibernate == '\0') {
    in_stack_ffffffffffffff88 = local_68;
    param_3 = (undefined1 *)0x0;
    StorPortNotification(0x1003,param_1,3,0,in_stack_ffffffffffffff88);
  }
  if (*(char *)((longlong)param_1 + 0x61) == '\0') {
    local_res18 = (char *)((longlong)param_1 + 0x399);
    uVar15 = 0;
    local_res20 = -0x948 - (longlong)param_1;
    puVar21 = param_1 + 0x129;
    puVar19 = param_1 + 0x157;
    puVar18 = param_1 + 0x20;
    do {
      iVar13 = 0;
      pcVar20 = local_res18;
      if (((*puVar19 & 1) != 0) && (*local_res18 == '\0')) {
        do {
          param_3 = (undefined1 *)0x8000;
          bVar4 = (byte)*puVar21;
          if (bVar4 == 0) goto LAB_000120a4;
          if ((bVar4 & 4) == 0) {
            if (bVar4 != 2) goto LAB_0001209e;
            if ((*puVar19 & 0x8000) == 0) {
              ReadWriteHostSStatusRegister((longlong)param_1,uVar15,0x8000,local_res10);
              *(uint *)puVar18 = local_res10[0];
              if ((((byte)local_res10[0] & 0xf) != 3) && ((local_res10[0] & 1) != 0)) {
                if ((*puVar19 & 0x2000) == 0) {
                  CommReset((longlong)param_1,uVar15);
                }
                else {
                  CommReset_for_ErrorDisk((longlong)param_1,uVar15);
                }
                ReadWriteHostSStatusRegister((longlong)param_1,uVar15,param_3,local_res10);
                *(uint *)puVar18 = local_res10[0];
              }
              if (((byte)local_res10[0] & 0xf) == 3) goto LAB_0001209e;
            }
          }
          else {
            uVar11 = uVar15 >> 1;
            lVar16 = ((ulonglong)(uVar11 & 3) + 2) * 0x80 + param_1[0xb];
            if ((*puVar19 & 0x8000) == 0) {
              bVar4 = *(byte *)(lVar16 + 0x28);
              bVar7 = bVar4 & 0xf;
              if (bVar7 != 3) {
                if ((bVar4 & 1) != 0) {
                  if ((*puVar19 & 0x2000) == 0) {
                    param_3 = (undefined1 *)0x0;
                    AhciResetPort((longlong)param_1,uVar11,'\0');
                  }
                  else {
                    AhciResetPort_for_ErrorDisk((longlong)param_1,uVar11);
                  }
                  bVar7 = *(byte *)(lVar16 + 0x28) & 0xf;
                }
                if (bVar7 != 3) goto LAB_00011fea;
              }
LAB_0001209e:
              bVar8 = true;
            }
            else {
LAB_00011fea:
              bVar8 = false;
            }
            if (bVar8) break;
          }
LAB_000120a4:
          lVar16 = 5;
          do {
            StorPortStallExecution(1000);
            lVar16 = lVar16 + -1;
          } while (lVar16 != 0);
          StorPortStallExecution(0);
          iVar13 = iVar13 + 1;
          param_3 = (undefined1 *)0x8000;
        } while (iVar13 < 3);
        pcVar20 = local_res18;
        if (2 < iVar13) {
          *(undefined1 *)(param_1 + 0x65) = 1;
          lVar16 = (longlong)(int)uVar15 >> 1;
          ((byte *)((longlong)puVar21 + local_res20 + 0x4874))[(longlong)param_1] = 1;
          uVar10 = param_1[lVar16 + 0x68];
          if (uVar10 == 0) break;
          do {
            *(undefined1 *)(uVar10 + 0x4b) = 5;
            if ((*puVar19 & 2) != 0) {
              *(undefined2 *)(uVar10 + 0x4b) = 0x284;
            }
            *(undefined1 *)(*(longlong *)(uVar10 + 0x10) + 0xebe) = 1;
            if ((*puVar19 & 2) != 0) {
              *(undefined1 *)(*(longlong *)(uVar10 + 0x10) + 0xebe) = 0;
            }
            pcVar1 = (char *)(lVar16 + 0x318 + (longlong)param_1);
            *pcVar1 = *pcVar1 + '\x01';
            StorCompleteSubCmdEx(param_1,uVar10);
            uVar10 = param_1[lVar16 + 0x68];
          } while (uVar10 != 0);
        }
      }
      param_3 = (undefined1 *)0x8000;
      local_res18 = pcVar20 + 0xb8;
      uVar15 = uVar15 + 1;
      puVar19 = (ulonglong *)((longlong)puVar19 + 2);
      puVar21 = (ulonglong *)((longlong)puVar21 + 1);
      puVar18 = (ulonglong *)((longlong)puVar18 + 4);
    } while ((int)uVar15 < 8);
  }
  uVar10 = 0;
  if (Hibernate == '\0') {
    param_3 = local_68;
    StorPortNotification(0x1004,param_1,param_3);
  }
  lVar16 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
  uVar12 = 0;
  bVar8 = StorLockCtrlrSrv((longlong)param_1,0,'\x01');
  uVar23 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  if (bVar8) {
    if (*(char *)((longlong)param_1 + 0x61) != '\0') {
      if (*(char *)((longlong)param_1 + 0x62) != '\0') {
        RestartAdapter((longlong)param_1);
      }
      pcVar20 = (char *)((longlong)param_1 + 0x399);
      puVar21 = param_1 + 0x157;
      do {
        if (((*puVar21 & 1) != 0) && (*pcVar20 == '\0')) {
          uVar15 = 0;
          do {
            uVar12 = uVar10;
            uVar9 = IsDevReady((longlong)param_1,(uint)uVar10,lVar16);
            if ((char)uVar9 != '\0') break;
            lVar14 = 500;
            do {
              StorPortStallExecution(1000);
              lVar14 = lVar14 + -1;
            } while (lVar14 != 0);
            StorPortStallExecution(0);
            uVar15 = uVar15 + 1;
          } while (uVar15 < 0x50);
        }
        uVar15 = (uint)uVar10 + 1;
        uVar10 = (ulonglong)uVar15;
        puVar21 = (ulonglong *)((longlong)puVar21 + 2);
        pcVar20 = pcVar20 + 0xb8;
      } while (uVar15 < 8);
      uVar12 = CONCAT71((int7)(uVar12 >> 8),0xff);
      SetAllFeature((longlong)param_1,-1,lVar16);
      if (*(char *)((longlong)param_1 + 0x62) == '\0') {
        *(undefined1 *)((longlong)param_1 + 0x61) = 0;
      }
    }
    puVar21 = (ulonglong *)CONCAT71((int7)(uVar12 >> 8),1);
    CheckController((longlong)param_1,'\x01',lVar16);
    if (Hibernate == '\0') {
      in_stack_ffffffffffffff88 = local_68;
      puVar21 = param_1;
      StorPortNotification(0x1003);
    }
    uVar23 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
    puVar19 = param_1 + 0x51;
    if ((ulonglong *)*puVar19 != (ulonglong *)0x0) {
      iVar13 = 0;
      puVar18 = (ulonglong *)*puVar19;
      if (0 < (int)param_1[0x57]) {
        do {
          puVar5 = (ulonglong *)*puVar18;
          if ((*(char *)((longlong)puVar18 + 0xeb6) != '\0') &&
             (uVar10 = puVar18[0x1e],
             (int)puVar18[0x1d7] !=
             *(int *)((longlong)param_1 + (ulonglong)*(byte *)(uVar10 + 6) * 4 + 700))) {
            plVar6 = *(longlong **)(uVar10 + 0x38);
            *(undefined1 *)(uVar10 + 6) = *(undefined1 *)((longlong)puVar18 + 0xeca);
            ReInitSrbExtension(plVar6);
            StorGetSetSrbExtension(plVar6,puVar21,'\x01');
            puVar21 = param_1;
            ReleaseTmpCmdBufs((longlong)param_1,(longlong)puVar18);
            plVar6[0xe] = (longlong)puVar18;
            ReInitLogicCmd(puVar21,puVar18,uVar10);
            uVar10 = puVar18[0x1e];
            uVar23 = *(undefined4 *)((longlong)param_1 + (ulonglong)*(byte *)(uVar10 + 6) * 4 + 700)
            ;
            *(undefined1 *)(puVar18 + 0x1d6) = 2;
            *(undefined4 *)((longlong)puVar18 + 0xea4) = 1;
            *(undefined4 *)(puVar18 + 0x1d7) = uVar23;
            if ((*(uint *)(uVar10 + 0xc) & 0xc0) != 0) {
              if (*(char *)(uVar10 + 2) == '\0') {
                uVar10 = StorPortGetScatterGatherList(param_1);
                puVar18[0x1d] = uVar10;
              }
              else {
                puVar18[0x1d] = 0;
              }
            }
            puVar21 = puVar18;
            ParseLogicCmd(param_1,(ulonglong)puVar18);
            if (*(int *)((longlong)puVar18 + 0xfc) == 1) {
              if (*(int *)((longlong)plVar6 + 0x27c) != 0) {
                *(longlong *)(puVar18[0x1e] + 0x18) = plVar6[0x50];
              }
              piVar2 = (int *)((longlong)param_1 +
                              (ulonglong)*(byte *)(puVar18[0x1e] + 6) * 4 + 0x290);
              *piVar2 = *piVar2 + -1;
              StorIoCompleteLogicCmd(param_1,(longlong)puVar18);
              RemoveListEntry((longlong *)puVar19,(longlong *)puVar18);
              *(int *)((longlong)param_1 + 0x2b4) = *(int *)((longlong)param_1 + 0x2b4) + -1;
              *(int *)(param_1 + 0x57) = (int)param_1[0x57] + -1;
              iVar13 = iVar13 + -1;
              puVar21 = puVar18;
            }
            else if (*(int *)((longlong)puVar18 + 0xfc) == 2) {
              StorPortBusy(param_1,8);
              *(undefined1 *)(puVar18[0x1e] + 3) = 5;
              if (*(int *)((longlong)plVar6 + 0x27c) != 0) {
                *(longlong *)(puVar18[0x1e] + 0x18) = plVar6[0x50];
              }
              RemoveListEntry((longlong *)puVar19,(longlong *)puVar18);
              *(int *)((longlong)param_1 + 0x2b4) = *(int *)((longlong)param_1 + 0x2b4) + -1;
              *(int *)(param_1 + 0x57) = (int)param_1[0x57] + -1;
              iVar13 = iVar13 + -1;
              piVar2 = (int *)((longlong)param_1 +
                              (ulonglong)*(byte *)(puVar18[0x1e] + 6) * 4 + 0x290);
              *piVar2 = *piVar2 + -1;
              *(undefined1 *)(puVar18[0x1e] + 6) = *(undefined1 *)((longlong)puVar18 + 0xeca);
              puVar21 = param_1;
              StorPortNotification(0);
            }
          }
          uVar23 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
          iVar13 = iVar13 + 1;
          puVar18 = puVar5;
        } while (iVar13 < (int)param_1[0x57]);
      }
    }
    if (Hibernate == '\0') {
      StorPortNotification(0x1004);
    }
    StorLockCtrlrSrv((longlong)param_1,0,'\0');
    if (Hibernate == '\0') {
      puVar22 = local_68;
      StorPortNotification(0x1003,param_1,3,0,puVar22);
      uVar23 = (undefined4)((ulonglong)puVar22 >> 0x20);
    }
    if ((char)param_1[0x65] != '\0') {
      *(undefined1 *)(param_1 + 0x65) = 0;
    }
    StorDequeueLogicCmd(param_1,'\x01');
    if (Hibernate == '\0') {
      StorPortNotification(0x1004,param_1,local_68);
    }
  }
  else {
    StorPortBusy(param_1,8);
  }
  if (cVar3 == '\0') {
    if (*(char *)((longlong)param_1 + 0x14b6) != '\0') goto LAB_00012535;
    uVar17 = 3000000;
  }
  else {
    if (*(char *)((longlong)param_1 + 0x14c2) == '\0') goto LAB_00012535;
    uVar17 = 100000;
  }
  StorPortNotification(6,param_1,AtapiScsiTimer,uVar17,CONCAT44(uVar23,0xffffffff));
LAB_00012535:
  *(undefined4 *)(param_1 + 0x90e) = 0;
  return;
}



===== AtapiCheckErrorDiskTimer @ 0001254c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AtapiCheckErrorDiskTimer(longlong param_1)

{
  int *piVar1;
  ushort uVar2;
  ulonglong uVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  ushort *puVar10;
  longlong lVar11;
  uint *puVar12;
  code *pcVar13;
  undefined8 uVar14;
  short sVar15;
  char cVar16;
  longlong lVar17;
  undefined2 uVar18;
  char *pcVar19;
  int aiStack_48a8 [4610];
  undefined8 uStack_a0;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  uint local_68 [2];
  longlong local_60;
  int local_58 [8];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_98;
  *(undefined4 *)(param_1 + 0x4870) = 1;
  pcVar13 = (code *)0x20;
  uStack_a0 = 0x12598;
  memset(local_58,0,0x20);
  uVar9 = 0;
  do {
    lVar11 = (longlong)(int)uVar9;
    cVar5 = *(char *)(lVar11 + 0x948 + param_1);
    if ((cVar5 != '\0') && ((*(ushort *)(param_1 + 0xab8 + lVar11 * 2) & 0x8000) != 0)) {
      bVar8 = (byte)uVar9;
      if (cVar5 == '\x02') {
        uVar3 = *(ulonglong *)(param_1 + 0xc0 + (lVar11 >> 1) * 8);
        sVar15 = (short)*(undefined8 *)(param_1 + 0xa0 + (lVar11 >> 1) * 8) + 6;
        out(sVar15,0xa0);
        uVar18 = (undefined2)uVar3;
        cVar5 = in(uVar18);
        uStack_a0 = 0x12603;
        ReadWriteHostSStatusRegister(param_1,uVar9,pcVar13,local_68);
        *(uint *)(param_1 + 0x100 + lVar11 * 4) = local_68[0];
        if (((((byte)local_68[0] & 0xf) == 3) && (-1 < cVar5)) &&
           ((*(byte *)(param_1 + 0xab8 + lVar11 * 2) & 1) != 0)) {
          uStack_a0 = 0x1262f;
          SetAllFeature(param_1,bVar8,pcVar13);
        }
        uVar6 = *(uint *)(param_1 + 0x100 + lVar11 * 4) & 0xf;
        if ((uVar6 == 0) || ((uVar6 == 3 && (-1 < cVar5)))) {
          *(ushort *)(param_1 + 0xab8 + (longlong)(int)uVar9 * 2) =
               *(ushort *)(param_1 + 0xab8 + (longlong)(int)uVar9 * 2) & 0x3fff | 0x4000;
LAB_00012939:
          local_78 = 0xffffffff;
          *(undefined1 *)(param_1 + 0x14b6) = 0;
          uStack_a0 = 0x1295b;
          StorPortNotification(6,param_1,AtapiScsiTimer,100000);
          return;
        }
        uStack_a0 = 0x1265e;
        ReadWriteHostSControlRegister(param_1,uVar9,'\x01',local_68);
        local_68[0] = local_68[0] & 0xfffff301 | 0x301;
        *(uint *)(param_1 + 0x120 + lVar11 * 4) = local_68[0];
        uStack_a0 = 0x12686;
        ReadWriteHostSControlRegister(param_1,uVar9,'\0',local_68);
        lVar17 = 2;
        do {
          uStack_a0 = 0x12697;
          StorPortStallExecution(1000);
          lVar17 = lVar17 + -1;
        } while (lVar17 != 0);
        uStack_a0 = 0x126a4;
        StorPortStallExecution(0);
        uStack_a0 = 0x126b5;
        ReadWriteHostSControlRegister(param_1,uVar9,'\x01',local_68);
        local_68[0] = local_68[0] & 0xfffffff0;
        *(uint *)(param_1 + 0x120 + lVar11 * 4) = local_68[0];
        uStack_a0 = 0x126d6;
        ReadWriteHostSControlRegister(param_1,uVar9,'\0',local_68);
        lVar17 = 2;
        do {
          uStack_a0 = 0x126e7;
          StorPortStallExecution(1000);
          lVar17 = lVar17 + -1;
        } while (lVar17 != 0);
        uStack_a0 = 0x126f4;
        StorPortStallExecution(0);
        local_68[0] = 0xffffffff;
        pcVar13 = (code *)0x0;
        uStack_a0 = 0x12709;
        ReadWriteHostSErrorRegister(param_1,uVar9,'\0',local_68);
        lVar17 = 10;
        do {
          uStack_a0 = 0x1271a;
          StorPortStallExecution(1000);
          lVar17 = lVar17 + -1;
        } while (lVar17 != 0);
        uStack_a0 = 0x12727;
        StorPortStallExecution(0);
        uStack_a0 = 0x12735;
        ReadWriteHostSStatusRegister(param_1,uVar9,pcVar13,local_68);
        *(uint *)(param_1 + 0x100 + lVar11 * 4) = local_68[0];
        if ((local_68[0] & 1) != 0) {
          cVar16 = (bVar8 & 1 | 0xfa) << 4;
          out(sVar15,cVar16);
          cVar5 = in(uVar18);
          if (cVar5 < '\0') {
            out(uVar18,4);
            uStack_a0 = 0x12779;
            StorPortStallExecution(99);
            out(uVar18,0);
            uStack_a0 = 0x12789;
            StorPortStallExecution(0x14,uVar3 & 0xffff);
            out(sVar15,cVar16);
            local_58[lVar11] = 1;
          }
        }
      }
      else if (cVar5 == '\x04') {
        uVar6 = (int)uVar9 >> 1 & 0x80000003;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
        }
        lVar17 = ((longlong)(int)uVar6 + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
        cVar5 = *(char *)(lVar17 + 0x20);
        local_68[0] = *(byte *)(lVar17 + 0x28) & 0xf;
        *(uint *)(param_1 + 0x100 + lVar11 * 4) = local_68[0];
        if ((((char)local_68[0] == '\x03') && (-1 < cVar5)) &&
           ((*(byte *)(param_1 + 0xab8 + lVar11 * 2) & 1) != 0)) {
          uStack_a0 = 0x12803;
          SetAllFeature(param_1,bVar8,pcVar13);
        }
        uVar6 = *(uint *)(param_1 + 0x100 + lVar11 * 4) & 0xf;
        if ((uVar6 == 0) || ((uVar6 == 3 && (-1 < cVar5)))) {
          *(ushort *)(param_1 + 0xab8 + (longlong)(int)uVar9 * 2) =
               *(ushort *)(param_1 + 0xab8 + (longlong)(int)uVar9 * 2) & 0x3fff | 0x4000;
          goto LAB_00012939;
        }
        uStack_a0 = 0x12832;
        AhciResetPort_for_ErrorDisk_disableINT(param_1,(int)uVar9 >> 1);
        if (((char)*(byte *)(lVar17 + 0x20) < '\0') || ((*(byte *)(lVar17 + 0x20) & 0x20) != 0)) {
          piVar1 = (int *)(param_1 + 0x4850 + lVar11 * 4);
          *piVar1 = *piVar1 + 1;
          if (2 < *(uint *)(param_1 + 0x4850 + lVar11 * 4)) {
            *(ushort *)(param_1 + 0xab8 + lVar11 * 2) =
                 *(ushort *)(param_1 + 0xab8 + lVar11 * 2) & 0x5fff | 0x2000;
            goto LAB_000128de;
          }
          uVar14 = 1000000;
          pcVar13 = AtapiCheckErrorDiskTimer;
        }
        else {
          uVar2 = *(ushort *)(param_1 + 0xab8 + lVar11 * 2);
          *(ushort *)(param_1 + 0xab8 + lVar11 * 2) = uVar2 & 0x3fff | 0x4000;
          if ((uVar2 & 1) != 0) {
            uStack_a0 = 0x1286e;
            SetAllFeature(param_1,bVar8,pcVar13);
          }
          *(undefined1 *)(param_1 + 0x14b6) = 0;
          uVar14 = 100000;
          pcVar13 = AtapiScsiTimer;
        }
        local_78 = 0xffffffff;
        uStack_a0 = 0x12895;
        StorPortNotification(6,param_1,pcVar13,uVar14);
      }
    }
LAB_000128de:
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < 8);
  bVar4 = false;
  iVar7 = 0;
  local_68[0] = 0;
  while (local_58[iVar7] == 0) {
    iVar7 = iVar7 + 1;
    if (7 < iVar7) goto LAB_00012acf;
  }
  lVar11 = 20000;
  do {
    uStack_a0 = 0x12998;
    StorPortStallExecution(0x96);
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  iVar7 = 0;
  lVar11 = -0x948 - param_1;
  pcVar19 = (char *)(param_1 + 0x948);
  puVar10 = (ushort *)(param_1 + 0xab8);
  puVar12 = (uint *)(param_1 + 0x4850);
  local_60 = lVar11;
  do {
    if (((*pcVar19 != '\0') &&
        (*(int *)(((longlong)aiStack_48a8 - param_1) + (longlong)puVar12) != 0)) &&
       (*pcVar19 == '\x02')) {
      cVar5 = in((short)*(undefined8 *)(param_1 + 0xc0 + ((longlong)(pcVar19 + lVar11) >> 1) * 8));
      if (cVar5 < '\0') {
        *puVar12 = *puVar12 + 1;
        if (2 < *puVar12) {
          *(undefined1 *)(param_1 + 0x14b6) = 0;
          *puVar10 = *puVar10 & 0x5fff | 0x2000;
          goto LAB_00012a88;
        }
        if (local_68[0] == 0) {
          local_78 = 0xffffffff;
          pcVar13 = AtapiCheckErrorDiskTimer;
          uStack_a0 = 0x12a33;
          StorPortNotification(6,param_1,AtapiCheckErrorDiskTimer,1000000);
          local_68[0] = 1;
        }
      }
      else {
        uVar2 = *puVar10;
        *puVar10 = uVar2 & 0x3fff | 0x4000;
        if ((uVar2 & 1) != 0) {
          uStack_a0 = 0x12a81;
          SetAllFeature(param_1,(char)iVar7,pcVar13);
        }
        *(undefined1 *)(param_1 + 0x14b6) = 0;
LAB_00012a88:
        if (!bVar4) {
          local_78 = 0xffffffff;
          pcVar13 = AtapiScsiTimer;
          uStack_a0 = 0x12aad;
          StorPortNotification(6,param_1,AtapiScsiTimer,100000);
          bVar4 = true;
        }
      }
      lVar11 = local_60;
    }
    iVar7 = iVar7 + 1;
    puVar10 = puVar10 + 1;
    puVar12 = puVar12 + 1;
    pcVar19 = pcVar19 + 1;
  } while (iVar7 < 8);
LAB_00012acf:
  *(undefined4 *)(param_1 + 0x4870) = 0;
  return;
}



===== AtapiFindNativePCIController @ 00012b00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00012f54) */

undefined8
AtapiFindNativePCIController
          (void *param_1,undefined8 param_2,undefined8 param_3,char *param_4,longlong param_5,
          undefined1 *param_6)

{
  undefined1 uVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  ulonglong *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  char cVar11;
  byte bVar12;
  uint uVar13;
  int iVar14;
  char *pcVar15;
  uint *puVar16;
  byte *pbVar17;
  undefined1 *puVar18;
  undefined4 *puVar19;
  ulonglong *puVar20;
  undefined8 *puVar21;
  uint uVar22;
  int iVar23;
  ulonglong *puVar24;
  undefined1 *puVar25;
  int iVar26;
  int iVar27;
  ulonglong uVar28;
  longlong lVar29;
  longlong lVar30;
  longlong lVar31;
  ulonglong uVar32;
  longlong *plVar33;
  bool bVar34;
  undefined8 uStack_140;
  undefined1 auStack_138 [8];
  undefined1 auStack_130 [24];
  int local_118 [2];
  undefined1 local_110 [8];
  int local_108 [2];
  undefined8 local_100;
  ulonglong local_e8;
  undefined4 local_e0;
  undefined1 local_dc [148];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_138;
  iVar26 = 0;
  if (param_4 == (char *)0x0) goto LAB_00012b9f;
  cVar11 = *param_4;
  pcVar15 = param_4;
  while (cVar11 != '\0') {
    if ((byte)(*pcVar15 + 0xbfU) < 0x1a) {
      *pcVar15 = *pcVar15 + ' ';
    }
    pcVar15 = pcVar15 + 1;
    cVar11 = *pcVar15;
  }
  pcVar15 = "ntldr=1";
  cVar11 = 'n';
  do {
    if (cVar11 != (param_4 + -0x33440)[(longlong)pcVar15]) {
      pcVar15 = "dump=1";
      cVar11 = 'd';
      goto LAB_00012b89;
    }
    pcVar15 = pcVar15 + 1;
    cVar11 = *pcVar15;
  } while (cVar11 != '\0');
  goto LAB_00012b98;
  while( true ) {
    pcVar15 = pcVar15 + 1;
    cVar11 = *pcVar15;
    if (cVar11 == '\0') break;
LAB_00012b89:
    if (cVar11 != (param_4 + -210000)[(longlong)pcVar15]) goto LAB_00012b9f;
  }
LAB_00012b98:
  Hibernate = '\x01';
LAB_00012b9f:
  *(undefined1 *)((longlong)param_1 + 0xb10) = 1;
  memset(param_1,0,0x4880);
  memset(&local_e8,0,0xa0);
  puVar25 = (undefined1 *)((longlong)param_1 + 0x958);
  memset(puVar25,0,0x140);
  lVar8 = 8;
  do {
    *puVar25 = 0xff;
    puVar25 = puVar25 + 0x28;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  memset((void *)((longlong)param_1 + 0x388),0,0x5c0);
  uVar32 = (ulonglong)GLOBALCOUNTER;
  uVar3 = (&DAT_0003414c)[uVar32 * 10];
  *(undefined4 *)((longlong)param_1 + 0x208) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x20c) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x210) = (&DAT_00034150)[uVar32 * 10];
  uVar1 = *(undefined1 *)(param_5 + 4);
  *(undefined1 *)((longlong)param_1 + 0x214) = uVar1;
  *(byte *)((longlong)param_1 + 0x215) = *(byte *)(param_5 + 100) & 0x1f;
  *(byte *)((longlong)param_1 + 0x216) = *(byte *)(param_5 + 100) >> 5;
  *(undefined1 *)((longlong)param_1 + 0x21a) = uVar1;
  *(uint *)((longlong)param_1 + 0x218) =
       *(uint *)((longlong)param_1 + 0x218) ^
       ((uint)*(byte *)((longlong)param_1 + 0x215) << 0xb ^ *(uint *)((longlong)param_1 + 0x218)) &
       0xf800;
  uVar13 = (*(byte *)((longlong)param_1 + 0x216) & 7 | 0xff800000) << 8 |
           *(uint *)((longlong)param_1 + 0x218) & 0xfffff8ff;
  *(uint *)((longlong)param_1 + 0x218) = uVar13;
  *(uint *)((longlong)param_1 + 0x21c) = uVar13;
  ReadConfigSpace((longlong)param_1);
  puVar25 = auStack_138;
  uVar13 = 0;
  puVar16 = &DAT_00034150;
  while ((*(uint *)((longlong)param_1 + 0x13b4) != puVar16[-1] ||
         (*(uint *)(param_5 + 0x34) < *puVar16))) {
    uVar13 = uVar13 + 1;
    puVar16 = puVar16 + 10;
    puVar18 = auStack_138;
    if (6 < uVar13) goto LAB_00012cdd;
  }
  *(uint *)((longlong)param_1 + 0x208) = puVar16[-1];
  uVar22 = 0;
  *(undefined4 *)((longlong)param_1 + 0x20c) = (&DAT_0003414c)[(ulonglong)uVar13 * 10];
  uVar13 = (&DAT_00034150)[(ulonglong)uVar13 * 10];
  *(uint *)((longlong)param_1 + 0x210) = uVar13;
  if (uVar13 != 0) {
    lVar8 = *(longlong *)(param_5 + 0x38);
    do {
      uVar32 = (ulonglong)uVar22;
      uVar22 = uVar22 + 1;
      *(ulonglong *)(local_dc + uVar32 * 0x10 + -0xc) = (ulonglong)*(uint *)(lVar8 + uVar32 * 0x10);
      *(undefined4 *)(local_dc + uVar32 * 0x10 + -4) = *(undefined4 *)(lVar8 + 8 + uVar32 * 0x10);
      local_dc[uVar32 * 0x10] = *(undefined1 *)(lVar8 + 0xc + uVar32 * 0x10);
    } while (uVar22 < uVar13);
  }
  *param_6 = 1;
  iVar14 = LookForCount + 1;
  LookForCount = iVar14;
  *param_6 = iVar14 < 3;
  uVar13 = DAT_00036300;
  puVar18 = auStack_138;
  if (iVar14 < 4) {
    uVar32 = (ulonglong)DAT_00036300;
    uVar28 = 0xff;
    uVar22 = 0;
    *(undefined4 *)((longlong)param_1 + 0x94) = *(undefined4 *)(param_5 + 0xc);
    if (uVar13 == 0) {
LAB_00012ded:
      *(undefined4 *)(&DAT_00036318 + uVar32 * 4) = *(undefined4 *)((longlong)param_1 + 0x218);
      DAT_00036300 = uVar13 + 1;
    }
    else {
      while (*(char *)((longlong)param_1 + 0x21a) != (&DAT_0003631a)[(ulonglong)uVar22 * 4]) {
LAB_00012de6:
        uVar22 = uVar22 + 1;
        if (uVar13 <= uVar22) goto LAB_00012ded;
      }
      if ((((*(uint *)((longlong)param_1 + 0x218) ^ *(uint *)(&DAT_00036318 + (ulonglong)uVar22 * 4)
            ) & 0xf800) != 0) ||
         (((*(uint *)((longlong)param_1 + 0x218) ^ *(uint *)(&DAT_00036318 + (ulonglong)uVar22 * 4))
          & 0x700) != 0)) goto LAB_00012de6;
      puVar18 = auStack_138;
      if ((&flg_StopAdapter)[uVar22] == '\0') goto LAB_00012cdd;
      uVar28 = (ulonglong)uVar22;
      if (uVar22 == 0xff) goto LAB_00012ded;
      *(undefined4 *)
       (&DAT_00036318 + (ulonglong)*(uint *)(&StoppedController + (ulonglong)uVar22 * 4) * 4) =
           *(undefined4 *)((longlong)param_1 + 0x218);
    }
    if ((int)uVar28 == 0xff) {
LAB_00012e93:
      *(int *)((longlong)param_1 + 0x98) = GlobalAdapterIndex;
      GlobalAdapterIndex = GlobalAdapterIndex + 1;
    }
    else {
      uVar32 = uVar28;
      puVar25 = auStack_138;
      if ((&flg_StopAdapter)[uVar28] == '\0') {
LAB_00012e6d:
        if (*(char *)(uVar32 + 0x36310) != '\0') {
          *(int *)((longlong)param_1 + 0x98) = (int)uVar28;
          if (uVar32 < 4) {
            *(undefined1 *)(uVar32 + 0x36310) = 0;
            goto LAB_00012ea6;
          }
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(8);
          puVar25 = puVar25 + 8;
        }
        goto LAB_00012e93;
      }
      *(undefined4 *)((longlong)param_1 + 0x98) = *(undefined4 *)(&StoppedController + uVar28 * 4);
      if (3 < uVar28) {
        uVar32 = 8;
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)();
        puVar25 = auStack_130;
        goto LAB_00012e6d;
      }
      (&flg_StopAdapter)[uVar28] = 0;
      puVar25 = auStack_138;
    }
LAB_00012ea6:
    iVar14 = 0;
    *(void **)(&DeviceExt + (ulonglong)*(uint *)((longlong)param_1 + 0x98) * 8) = param_1;
    if (*(uint *)((longlong)param_1 + 0x210) != 0) {
      plVar33 = (longlong *)(puVar25 + 0x50);
      uVar32 = (ulonglong)*(uint *)((longlong)param_1 + 0x210);
      do {
        lVar8 = *plVar33;
        lVar31 = plVar33[1];
        cVar11 = *(char *)((longlong)plVar33 + 0xc);
        *(undefined4 *)(puVar25 + 0x3c) = 0;
        *(int *)(puVar25 + 0x38) = (int)lVar8;
        if ((int)lVar8 != 0) {
          uVar3 = *(undefined4 *)(param_5 + 4);
          uVar4 = *(undefined4 *)(param_5 + 8);
          puVar25[0x28] = cVar11 == '\0';
          *(int *)(puVar25 + 0x20) = (int)lVar31;
          *(undefined8 *)(puVar25 + -8) = 0x12f02;
          lVar8 = StorPortGetDeviceBase(param_1,uVar4,uVar3,*(undefined8 *)(puVar25 + 0x38));
          if (lVar8 != 0) {
            iVar14 = iVar14 + 1;
            *plVar33 = lVar8;
          }
        }
        plVar33 = plVar33 + 2;
        uVar32 = uVar32 - 1;
      } while (uVar32 != 0);
    }
    puVar18 = puVar25;
    if (iVar14 == *(int *)((longlong)param_1 + 0x210)) {
      *(undefined8 *)(puVar25 + -8) = 0x12f36;
      FillBaseRegisterAddr((longlong)param_1,(longlong *)(puVar25 + 0x50));
      *(undefined8 *)(puVar25 + -8) = 0x12f3e;
      SetTargetProperty((longlong)param_1);
      *(undefined8 *)(puVar25 + -8) = 0x12f46;
      ModifyConfigSpace((longlong)param_1);
      *(undefined1 *)(param_5 + 0x48) = 1;
      if (0x10000 < *(uint *)(param_5 + 0x18)) {
        *(undefined4 *)(param_5 + 0x18) = 0x10000;
      }
      bVar34 = Hibernate != '\x01';
      *(undefined2 *)(param_5 + 0x51) = 0x101;
      *(undefined1 *)(param_5 + 0x57) = 1;
      *(undefined8 *)(param_5 + 0x10) = 0;
      *(undefined4 *)(param_5 + 0x30) = 1;
      *(undefined1 *)(param_5 + 0x61) = 8;
      *(undefined1 *)(param_5 + 0x53) = 1;
      *(uint *)(param_5 + 0x94) = (uint)bVar34;
      *(undefined1 *)(param_5 + 0x90) = 0;
      *(undefined4 *)(param_5 + 0x59) = 0x1010102;
      *(undefined1 *)(param_5 + 0x5d) = 1;
      *(undefined2 *)(param_5 + 0x92) = 8;
      if (!bVar34) {
        puVar10 = (undefined8 *)((longlong)param_1 + 0xc0);
        pbVar17 = (byte *)((longlong)param_1 + 0x948);
        lVar8 = 4;
        do {
          if ((*pbVar17 != 0) && ((*pbVar17 & 4) == 0)) {
            out((short)*puVar10,0);
          }
          puVar10 = puVar10 + 1;
          pbVar17 = pbVar17 + 2;
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
      }
      *(undefined8 *)(puVar25 + -8) = 0x12fe9;
      GetDeviceExtensionSize((longlong)param_1);
      *(undefined8 *)(puVar25 + -8) = 0x12ff4;
      uVar9 = AllocateUncachedBuffers((longlong)param_1,param_5);
      cVar11 = Hibernate;
      if ((char)uVar9 == '\0') {
        uVar9 = 2;
        goto LAB_00012cdf;
      }
      if (*(int *)((longlong)param_1 + 0x20c) == 0x33491106) {
        if (Hibernate != '\0') {
          if (Hibernate == '\x01') {
            *(undefined8 *)((longlong)param_1 + 0x42a0) = *(undefined8 *)(param_5 + 0xa8);
            g_raid5hiberBufSize = 0x8000;
            *(undefined8 *)((longlong)param_1 + 0x42a8) = *(undefined8 *)(param_5 + 0xb0);
            *(undefined8 *)((longlong)param_1 + 0x42b0) = *(undefined8 *)(param_5 + 0xb8);
            lVar8 = *(longlong *)(param_5 + 0xa8);
            *(longlong *)((longlong)param_1 + 0x4260) = lVar8;
            *(longlong *)((longlong)param_1 + 0x4220) = lVar8;
            *(longlong *)((longlong)param_1 + 0x4270) = lVar8 + 0x8000;
            *(longlong *)((longlong)param_1 + 0x4230) = lVar8 + 0x8000;
            *(longlong *)((longlong)param_1 + 0x4280) = lVar8 + 0x10000;
            *(longlong *)((longlong)param_1 + 0x4240) = lVar8 + 0x10000;
            *(longlong *)((longlong)param_1 + 0x4290) = lVar8 + 0x18000;
            *(longlong *)((longlong)param_1 + 0x4250) = lVar8 + 0x18000;
          }
          goto LAB_000130af;
        }
        *(int *)(param_5 + 0xc0) = *(int *)((longlong)param_1 + 4) << 0xf;
LAB_000130b3:
        *(undefined1 *)(param_5 + 0x93) = 1;
        puVar19 = *(undefined4 **)((longlong)param_1 + 0x4840);
        *(undefined8 *)(puVar25 + -8) = 0x130ce;
        DbgPrint("\nFunction WmiInitialize entry\n");
        *(undefined ***)(puVar19 + 2) = &GuidListInfo;
        *(code **)(puVar19 + 4) = QueryWmiRegInfo;
        *puVar19 = 1;
        *(code **)(puVar19 + 6) = QueryWmiDataBlock;
        *(undefined8 *)(puVar19 + 10) = 0;
        *(undefined8 *)(puVar19 + 8) = 0;
        *(undefined8 *)(puVar19 + 0xc) = 0;
        *(code **)(puVar19 + 0xe) = SwitchOfFunctionControl;
        *(undefined8 *)(puVar25 + -8) = 0x13119;
        DbgPrint("\n-----------GuidCount = %d\n",1);
        *(undefined8 *)(puVar25 + -8) = 0x13126;
        DbgPrint("\nFunction WmiInitialize return\n");
      }
      else {
LAB_000130af:
        if (cVar11 == '\0') goto LAB_000130b3;
      }
      *(undefined8 *)(puVar25 + -8) = 0x1312e;
      GetPRDTablePointer((longlong)param_1);
      uVar13 = 0;
      pcVar15 = (char *)((longlong)param_1 + 0x948);
      do {
        if (*pcVar15 == '\x02') {
          *(undefined4 *)(puVar25 + 0x30) = 0xffffffff;
          *(undefined8 *)(puVar25 + -8) = 0x13154;
          ReadWriteHostSErrorRegister((longlong)param_1,uVar13,'\0',(undefined4 *)(puVar25 + 0x30));
        }
        uVar13 = uVar13 + 1;
        pcVar15 = pcVar15 + 1;
      } while (uVar13 < 8);
      iVar14 = *(int *)((longlong)param_1 + 0x20c);
      *(undefined2 *)((longlong)param_1 + 0x9c) = 0x100;
      bVar2 = *(byte *)((longlong)param_1 + 0x13bc);
      bVar12 = *(byte *)((longlong)param_1 + 0x13f4) >> 4;
      if (iVar14 == 0x5711106) {
LAB_000131b2:
        *(undefined1 *)((longlong)param_1 + 0x9d) = 0;
      }
      else {
        if (iVar14 == 0x31491106) {
          if ((bVar2 != 0x50) || (4 < bVar12)) {
            if (bVar2 == 0x80) {
              bVar34 = bVar12 < 2;
              goto LAB_000131b0;
            }
            goto LAB_000131b9;
          }
          goto LAB_000131b2;
        }
        if (iVar14 == 0x31641106) goto LAB_000131b2;
        if (iVar14 == 0x32491106) {
          bVar34 = bVar2 < 0x50;
LAB_000131b0:
          if (bVar34) goto LAB_000131b2;
        }
      }
LAB_000131b9:
      *(undefined1 *)((longlong)param_1 + 0x254) = 0;
      puVar18 = (undefined1 *)((longlong)param_1 + 0x318);
      puVar19 = (undefined4 *)((longlong)param_1 + 0x32c);
      puVar10 = (undefined8 *)((longlong)param_1 + 0x2f8);
      lVar8 = 4;
      do {
        puVar10[9] = 0;
        *puVar10 = 0;
        *puVar19 = 0;
        *puVar18 = 0;
        puVar10 = puVar10 + 1;
        puVar18 = puVar18 + 1;
        puVar19 = puVar19 + 1;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      *(undefined8 *)((longlong)param_1 + 800) = 0;
      *(undefined1 *)((longlong)param_1 + 0x328) = 0;
      puVar18 = (undefined1 *)((longlong)param_1 + 0x2dc);
      puVar19 = (undefined4 *)((longlong)param_1 + 0x4850);
      lVar8 = 8;
      do {
        lVar31 = lVar8;
        *puVar18 = 0;
        puVar18 = puVar18 + 1;
        *puVar19 = 0;
        puVar19 = puVar19 + 1;
        lVar8 = lVar31 + -1;
      } while (lVar8 != 0);
      *(undefined4 *)((longlong)param_1 + 0x4870) = 0;
      *(longlong *)((longlong)param_1 + 0x278) = (longlong)param_1 + 600;
      *(undefined8 *)((longlong)param_1 + 0x290) = 0;
      *(undefined8 *)((longlong)param_1 + 0x298) = 0;
      *(undefined8 *)((longlong)param_1 + 0x2a0) = 0;
      *(undefined8 *)((longlong)param_1 + 0x2a8) = 0;
      *(undefined8 *)((longlong)param_1 + 0x2b0) = 0;
      *(undefined4 *)((longlong)param_1 + 0x280) = 0;
      *(undefined4 *)((longlong)param_1 + 0x2b8) = 0;
      *(undefined8 *)((longlong)param_1 + 0x288) = 0;
      *(undefined8 *)(puVar25 + -8) = 0x1327f;
      memset((void *)((longlong)param_1 + 0x47a8),0,(ulonglong)((int)lVar31 + 0x3f));
      puVar10 = *(undefined8 **)((longlong)param_1 + 8);
      *(undefined8 *)((longlong)param_1 + 0x42d0) = 0xffffffffffffffff;
      *(undefined8 *)((longlong)param_1 + 0x47e8) = 0;
      *(undefined2 *)((longlong)param_1 + 0x61) = 0;
      *(undefined8 *)((longlong)param_1 + 0x42c0) = 0;
      *(undefined4 *)((longlong)param_1 + 0x42c8) = 0xff;
      *(undefined8 *)(puVar25 + -8) = 0x132b7;
      memset(puVar10,0,0x498);
      uVar32 = *(ulonglong *)((longlong)param_1 + 0x20);
      puVar20 = puVar10 + 0x81;
      *puVar20 = uVar32;
      iVar14 = *(int *)((longlong)param_1 + 0x28);
      iVar23 = 0;
      *(undefined1 *)((longlong)puVar10 + 0x415) = 0;
      *(int *)(puVar10 + 0x82) = iVar14;
      iVar27 = 0;
      if ((iVar14 != 0) && (uVar32 != 0)) {
        iVar23 = 1;
        iVar27 = iVar14;
      }
      uVar32 = *(ulonglong *)((longlong)param_1 + 0x10);
      iVar14 = *(int *)((longlong)param_1 + 0x18);
      lVar8 = (longlong)iVar23;
      if (uVar32 != 0) {
        puVar20[lVar8 * 2] = uVar32;
        *(int *)(puVar10 + lVar8 * 2 + 0x82) = iVar14;
        *(undefined1 *)((longlong)puVar10 + lVar8 * 0x10 + 0x415) = 0;
        if ((iVar14 != 0) && (uVar32 != 0)) {
          iVar27 = iVar27 + iVar14;
          iVar23 = iVar23 + 1;
        }
      }
      lVar8 = (longlong)iVar23;
      *(int *)(puVar10 + 0x91) = iVar23;
      *(int *)(puVar10 + 0x92) = iVar27;
      *(int *)((longlong)puVar10 + 0x48c) = iVar27;
      if (lVar8 != 0) {
        lVar29 = 1;
        lVar31 = lVar8;
        do {
          if (lVar29 < lVar8) {
            lVar30 = lVar8 - lVar29;
            puVar6 = puVar20;
            do {
              puVar24 = puVar6 + 2;
              if (*puVar24 < *puVar20) {
                uVar32 = puVar6[3];
                uVar28 = *puVar20;
                uVar7 = puVar20[1];
                *puVar20 = *puVar24;
                puVar20[1] = uVar32;
                *puVar24 = uVar28;
                puVar6[3] = uVar7;
              }
              lVar30 = lVar30 + -1;
              puVar6 = puVar24;
            } while (lVar30 != 0);
          }
          puVar20 = puVar20 + 2;
          lVar29 = lVar29 + 1;
          lVar31 = lVar31 + -1;
        } while (lVar31 != 0);
      }
      if (0 < *(int *)(puVar10 + 0x91)) {
        puVar21 = puVar10;
        do {
          iVar26 = iVar26 + 1;
          *puVar21 = puVar21[0x81];
          puVar21[1] = puVar21[0x82];
          puVar21 = puVar21 + 2;
        } while (iVar26 < *(int *)(puVar10 + 0x91));
      }
      uVar9 = 1;
      *(undefined4 *)(puVar10 + 0x80) = *(undefined4 *)(puVar10 + 0x91);
      goto LAB_00012cdf;
    }
  }
LAB_00012cdd:
  puVar25 = puVar18;
  uVar9 = 0;
LAB_00012cdf:
  *(undefined8 *)(puVar25 + -8) = 0x12ceb;
  return uVar9;
}



===== AtapiResetController @ 000133ac =====

undefined8 AtapiResetController(longlong param_1)

{
  ushort uVar1;
  byte bVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined8 uVar5;
  ushort *puVar6;
  uint *puVar7;
  char *pcVar8;
  uint uVar9;
  byte *pbVar10;
  ulonglong uVar11;
  longlong lVar12;
  char cVar13;
  undefined2 uVar14;
  byte *pbVar15;
  
  pbVar15 = (byte *)(param_1 + 0x948);
  *(undefined1 *)(param_1 + 0x2c) = 1;
  puVar6 = (ushort *)(param_1 + 0xac8);
  uVar11 = 0;
  puVar7 = (uint *)(param_1 + 0x39c);
  lVar12 = 8;
  pbVar10 = pbVar15;
  do {
    if (((((*pbVar10 != 0) && (uVar1 = puVar6[-8], (uVar1 & 2) != 0)) && ((uVar1 & 1) != 0)) &&
        (((uVar1 & 0x100) != 0 && ((*puVar6 & 2) == 0)))) &&
       (*(char *)((uVar11 >> 1) + 0x42dc + param_1) != '\0')) {
      *puVar7 = *puVar7 & 0xfffffffb;
      puVar6[-8] = puVar6[-8] & 0xfeff;
      *puVar6 = *puVar6 | 4;
    }
    uVar11 = uVar11 + 1;
    puVar6 = puVar6 + 1;
    pbVar10 = pbVar10 + 1;
    puVar7 = puVar7 + 0x2e;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  *(undefined1 *)(param_1 + 0x2d) = 1;
  CheckController(param_1,'\0',(longlong)pbVar10);
  uVar9 = 0;
  puVar6 = (ushort *)(param_1 + 0xab8);
  pcVar8 = (char *)(param_1 + 0x39a);
  do {
    if (((*puVar6 & 1) != 0) && ((*puVar6 & 2) != 0)) {
      pbVar15[-0x91a] = 0;
      if (*pcVar8 == '\0') {
        uVar11 = IsDevReady(param_1,uVar9,pbVar10);
        if ((char)uVar11 != '\0') goto LAB_0001358d;
      }
      bVar2 = (byte)uVar9;
      if ((*pbVar15 & 4) == 0) {
        uVar5 = *(undefined8 *)(param_1 + 0xa0 + (longlong)((int)uVar9 / 2) * 8);
        uVar14 = (undefined2)*(undefined8 *)(param_1 + 0xc0 + (longlong)((int)uVar9 / 2) * 8);
        in(uVar14);
        uVar4 = (int)uVar5 + 6;
        uVar3 = (undefined2)uVar4;
        cVar13 = (bVar2 & 1 | 0xfa) << 4;
        out(uVar3,cVar13);
        StorPortStallExecution(500,uVar4 & 0xffff);
        out((short)uVar5 + 7,8);
        lVar12 = 10;
        do {
          StorPortStallExecution(1000);
          lVar12 = lVar12 + -1;
        } while (lVar12 != 0);
        StorPortStallExecution(0);
        out(uVar3,cVar13);
        uVar4 = 0;
        do {
          cVar13 = in(uVar14);
          if (-1 < cVar13) break;
          StorPortStallExecution(0x96);
          uVar4 = uVar4 + 1;
        } while (uVar4 < 20000);
        StorPortStallExecution(500);
        in(uVar14);
      }
      else {
        AhciDevReset(param_1,uVar9);
      }
      uVar11 = IsDevReady(param_1,uVar9,pbVar10);
      if ((char)uVar11 == '\0') {
        RestoreOneAbnormalDevice(param_1,bVar2,(longlong)pbVar10);
      }
      if (((*puVar6 & 0x8000) == 0) && ((*puVar6 & 0x2000) == 0)) {
        SetAllFeature(param_1,bVar2,pbVar10);
      }
    }
LAB_0001358d:
    uVar9 = uVar9 + 1;
    puVar6 = puVar6 + 1;
    pcVar8 = pcVar8 + 0xb8;
    pbVar15 = pbVar15 + 1;
    if (7 < (int)uVar9) {
      if (*(longlong *)(param_1 + 0x47e8) == 0) {
        StorClearSubCmd(param_1);
        StorClearLogicCmd(param_1);
      }
      uVar5 = StorClearWaitLogicCmd(param_1,'\0');
      *(undefined2 *)(param_1 + 0x2c) = 0;
      return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
    }
  } while( true );
}



===== GetDeviceExtensionSize @ 000135f0 =====

int GetDeviceExtensionSize(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  
  lVar2 = 0;
  iVar3 = 0;
  if (param_1 == 0) {
    iVar3 = 0x6398;
  }
  else {
    uVar1 = param_1 + 0x4c80U & 0xfffffffffffffc00;
    *(ulonglong *)(param_1 + 0x2e8) = uVar1;
    *(ulonglong *)(param_1 + 8) = uVar1 + 0xf00;
    lVar2 = uVar1 + 0x1398;
  }
  if (Hibernate == '\0') {
    if (param_1 == 0) {
      iVar3 = iVar3 + 0xa0;
    }
    else {
      *(longlong *)(param_1 + 0x4840) = lVar2;
      DbgPrint("SCSI_WMILIB_CONTEXT struct ptr = x%p\n",lVar2);
      *(longlong *)(param_1 + 0x4848) = lVar2 + 0x40;
      DbgPrint("BufferForWMI struct ptr = x%p\n",lVar2 + 0x40);
    }
  }
  DbgPrint("totally need 0x%x bytes for deviceExt memory\n",iVar3);
  return iVar3;
}



===== GetPRDTablePointer @ 000136c4 =====

void GetPRDTablePointer(longlong param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  undefined1 local_res8 [8];
  
  puVar4 = (undefined8 *)(param_1 + 0xe0);
  pbVar2 = (byte *)(param_1 + 0x948);
  puVar5 = (undefined4 *)(param_1 + 0x240);
  lVar3 = 4;
  do {
    if ((*pbVar2 != 0) && ((*pbVar2 & 4) == 0)) {
      uVar1 = StorPortGetPhysicalAddress(param_1,0,puVar4[0x28],local_res8);
      *puVar5 = uVar1;
      if (*pbVar2 != 0) {
        out((short)*puVar4 + 4,uVar1);
      }
    }
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
    pbVar2 = pbVar2 + 2;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}



===== CheckDeviceCheckSum @ 00013748 =====

ulonglong CheckDeviceCheckSum(longlong param_1,int *param_2)

{
  byte bVar1;
  uint uVar2;
  undefined8 in_RAX;
  uint7 uVar4;
  ulonglong uVar3;
  longlong lVar5;
  uint uVar6;
  uint *puVar7;
  
  uVar6 = 0;
  puVar7 = (uint *)(param_2 + 0x1e);
  uVar4 = (uint7)((ulonglong)in_RAX >> 8);
  if ((*param_2 != 0) || (param_2[3] != 0)) {
    uVar3 = CONCAT71(uVar4,1);
    goto LAB_00013794;
  }
  uVar2 = param_2[8];
  uVar3 = (ulonglong)uVar4 << 8;
  if (1 < uVar2) {
    if (uVar2 == 5) {
      uVar3 = CONCAT71(uVar4,(char)param_2[10]) & 0xffffffffffffff0f;
      uVar3 = CONCAT71((int7)(uVar3 >> 8),(char)uVar3 + '\x01');
      goto LAB_00013794;
    }
    if (uVar2 != 8) {
      if (uVar2 == 9) {
        uVar3 = CONCAT71(uVar4,(char)param_2[10]) & 0xffffffffffffff0f;
        uVar3 = CONCAT71((int7)(uVar3 >> 8),(char)uVar3 * '\x02');
      }
      goto LAB_00013794;
    }
  }
  uVar3 = CONCAT71(uVar4,(char)param_2[10]) & 0xffffffffffffff0f;
LAB_00013794:
  bVar1 = *(byte *)(param_1 + 2);
  if ((byte)uVar3 != bVar1) {
LAB_0001379b:
    return uVar3 & 0xffffffffffffff00;
  }
  if (bVar1 != 0) {
    lVar5 = param_1 - (longlong)puVar7;
    do {
      uVar3 = (ulonglong)*puVar7;
      if (*(uint *)(lVar5 + 4 + (longlong)puVar7) != *puVar7) goto LAB_0001379b;
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar6 < bVar1);
  }
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== SetFirstTarget @ 000137c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001397a) */
/* WARNING: Removing unreachable block (ram,0x00013a9c) */

void SetFirstTarget(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  char *pcVar3;
  uint uVar4;
  byte *pbVar5;
  longlong lVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  byte bVar11;
  byte bVar12;
  longlong lVar13;
  undefined8 *puVar14;
  longlong lVar15;
  longlong lVar16;
  undefined1 auStack_68 [32];
  char local_48 [8];
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  pbVar5 = (byte *)(param_1 + 0x958);
  lVar6 = 8;
  puVar14 = &local_40;
  local_48[0] = '\0';
  local_48[1] = '\0';
  local_48[2] = '\0';
  local_48[3] = '\0';
  local_48[4] = '\0';
  local_48[5] = '\0';
  local_48[6] = '\0';
  local_48[7] = '\0';
  local_40 = 0;
  lVar15 = 8;
  pbVar8 = pbVar5;
  lVar13 = param_1;
  do {
    if (*pbVar8 != 0xff) {
      uVar2 = 0;
      do {
        bVar12 = (byte)uVar2;
        if ((*(byte *)(lVar13 + 0xab8 + uVar2 * 2) & 1) == 0) {
          local_48[uVar2] = '\x01';
        }
        else {
          lVar16 = uVar2 * 0xb8 + lVar13;
          uVar1 = CheckDeviceCheckSum((longlong)pbVar8,(int *)(lVar16 + 0x388));
          if (((char)uVar1 != '\0') &&
             (((iVar7 = *(int *)(lVar16 + 0x38c), local_48[uVar2] = '\x01', iVar7 == 1 ||
               (*(int *)(lVar16 + 0x394) == 1)) || (*(int *)(lVar16 + 0x388) == 1)))) {
            *pbVar8 = bVar12;
            lVar16 = uVar2 * 0xb8;
            if (*(int *)(lVar16 + 0x38c + lVar13) != 0) {
              if (pbVar8[1] == 0) {
LAB_000138a6:
                if (*(char *)(lVar16 + 0x390 + lVar13) != '\0') {
LAB_000138b0:
                  *(undefined1 *)puVar14 = 1;
                }
              }
              else {
                if (*(char *)(lVar16 + 0x390 + lVar13) == '\0') goto LAB_000138b0;
                if (pbVar8[1] == 0) goto LAB_000138a6;
              }
              pbVar8[1] = *(byte *)(lVar16 + 0x390 + lVar13);
            }
            break;
          }
        }
        bVar12 = bVar12 + 1;
        uVar2 = (ulonglong)bVar12;
      } while (bVar12 < 8);
      if (7 < bVar12) {
        *pbVar8 = 0xff;
      }
    }
    puVar14 = (undefined8 *)((longlong)puVar14 + 1);
    pbVar8 = pbVar8 + 0x28;
    lVar15 = lVar15 + -1;
  } while (lVar15 != 0);
  bVar12 = 0;
  do {
    if (local_48[bVar12] != '\x01') {
      lVar15 = (ulonglong)bVar12 * 0xb8;
      if (*(int *)(lVar15 + 0x38c + lVar13) == 1) {
LAB_00013936:
        if ((*(int *)(lVar15 + 0x394 + lVar13) == 1) || (*(int *)(lVar15 + 0x388 + lVar13) == 1))
        goto LAB_00013957;
        uVar4 = (uint)*(byte *)(lVar15 + 0x3b4 + lVar13);
      }
      else {
        if (*(int *)(lVar15 + 0x394 + lVar13) != 1) {
          if (*(int *)(lVar15 + 0x388 + lVar13) != 1) goto LAB_00013a67;
          goto LAB_00013936;
        }
LAB_00013957:
        uVar4 = 1;
      }
      iVar7 = 0;
      if (uVar4 != 0) {
        do {
          bVar11 = 0;
          do {
            uVar9 = (uint)bVar11 + (uint)bVar12 & 0x80000007;
            if (pbVar5[(ulonglong)uVar9 * 0x28] == 0xff) break;
            bVar11 = bVar11 + 1;
          } while (bVar11 < 8);
          if (7 < bVar11) {
            return;
          }
          uVar2 = (ulonglong)uVar9;
          *(char *)(param_1 + 0x97c + uVar2 * 0x28) = (char)iVar7;
          pbVar5[uVar2 * 0x28] = bVar12;
          *(undefined1 *)(param_1 + 0x959 + uVar2 * 0x28) = *(undefined1 *)(lVar15 + 0x390 + lVar13)
          ;
          if ((*(int *)(lVar15 + 0x388 + lVar13) == 0) && (*(int *)(lVar15 + 0x394 + lVar13) == 0))
          {
            uVar9 = *(uint *)(lVar15 + 0x3a8 + lVar13);
            bVar11 = 0;
            if (uVar9 < 2) {
LAB_00013a11:
              bVar11 = *(byte *)(lVar15 + 0x3b0 + lVar13) & 0xf;
            }
            else if (uVar9 == 5) {
              bVar11 = (*(byte *)(lVar15 + 0x3b0 + lVar13) & 0xf) + 1;
            }
            else {
              if (uVar9 == 8) goto LAB_00013a11;
              if (uVar9 == 9) {
                bVar11 = (*(byte *)(lVar15 + 0x3b0 + lVar13) & 0xf) * '\x02';
              }
            }
          }
          else {
            bVar11 = 1;
          }
          *(byte *)(param_1 + 0x95a + uVar2 * 0x28) = bVar11;
          pbVar10 = pbVar5 + uVar2 * 0x28 + 4;
          pbVar8 = (byte *)(lVar13 + 0x400 + lVar15);
          if (pbVar10 != pbVar8) {
            *(undefined8 *)pbVar10 = *(undefined8 *)pbVar8;
            *(undefined8 *)(pbVar10 + 8) = *(undefined8 *)(pbVar8 + 8);
            *(undefined8 *)(pbVar10 + 0x10) = *(undefined8 *)(pbVar8 + 0x10);
            *(undefined8 *)(pbVar10 + 0x18) = *(undefined8 *)(pbVar8 + 0x18);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)uVar4);
      }
    }
LAB_00013a67:
    bVar12 = bVar12 + 1;
    if (7 < bVar12) {
      bVar12 = 0;
      do {
        uVar2 = (ulonglong)bVar12;
        if (local_48[uVar2 + 8] != '\0') {
          bVar11 = 0;
          do {
            uVar4 = (uint)bVar11 + (uint)pbVar5[uVar2 * 0x28] & 0x80000007;
            if (pbVar5[(ulonglong)uVar4 * 0x28] == 0xff) break;
            bVar11 = bVar11 + 1;
          } while (bVar11 < 8);
          if (7 < bVar11) {
            return;
          }
          uVar1 = (ulonglong)uVar4;
          *(undefined4 *)(pbVar5 + uVar1 * 0x28) = *(undefined4 *)(pbVar5 + uVar2 * 0x28);
          *(undefined4 *)(param_1 + 0x95c + uVar1 * 0x28) =
               *(undefined4 *)(param_1 + 0x95c + uVar2 * 0x28);
          *(undefined4 *)(param_1 + 0x960 + uVar1 * 0x28) =
               *(undefined4 *)(param_1 + 0x960 + uVar2 * 0x28);
          *(undefined4 *)(param_1 + 0x964 + uVar1 * 0x28) =
               *(undefined4 *)(param_1 + 0x964 + uVar2 * 0x28);
          *(undefined4 *)(param_1 + 0x968 + uVar1 * 0x28) =
               *(undefined4 *)(param_1 + 0x968 + uVar2 * 0x28);
          *(undefined4 *)(param_1 + 0x96c + uVar1 * 0x28) =
               *(undefined4 *)(param_1 + 0x96c + uVar2 * 0x28);
          *(undefined4 *)(param_1 + 0x970 + uVar1 * 0x28) =
               *(undefined4 *)(param_1 + 0x970 + uVar2 * 0x28);
          *(undefined4 *)(param_1 + 0x974 + uVar1 * 0x28) =
               *(undefined4 *)(param_1 + 0x974 + uVar2 * 0x28);
          *(undefined4 *)(param_1 + 0x978 + uVar1 * 0x28) =
               *(undefined4 *)(param_1 + 0x978 + uVar2 * 0x28);
          *(undefined4 *)(param_1 + 0x97c + uVar1 * 0x28) =
               *(undefined4 *)(param_1 + 0x97c + uVar2 * 0x28);
        }
        bVar12 = bVar12 + 1;
        if (7 < bVar12) {
          pcVar3 = (char *)&local_40;
          do {
            if (*pcVar3 != '\0') {
              *pbVar5 = 0xff;
            }
            pcVar3 = pcVar3 + 1;
            pbVar5 = pbVar5 + 0x28;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          *(undefined8 *)(lVar13 + 0x2dc) = 0;
          return;
        }
      } while( true );
    }
  } while( true );
}



===== BuildDeviceParameter @ 00013b78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BuildDeviceParameter
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  int *piVar6;
  char *pcVar7;
  undefined1 *puVar8;
  ushort *puVar9;
  int *piVar10;
  byte bVar11;
  uint uVar12;
  int *piVar13;
  short *psVar14;
  undefined4 *puVar15;
  short *_Dst;
  byte *pbVar16;
  longlong lVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  ushort *puVar20;
  byte *pbVar21;
  ushort *puVar22;
  longlong lVar23;
  longlong lVar24;
  undefined1 auStack_68 [32];
  char local_38 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  uVar12 = 0;
  psVar14 = (short *)(param_1 + 0x14c4);
  puVar22 = (ushort *)(param_1 + 0xab8);
  lVar24 = 8;
  puVar9 = puVar22;
  _Dst = psVar14;
  do {
    if (((*puVar9 & 1) != 0) && ((*puVar9 & 2) == 0)) {
      memset(_Dst,0,0x200);
      ReadWriteConfigFromHDD(param_1,uVar12,(undefined8 *)_Dst,param_4,'\0');
    }
    uVar12 = uVar12 + 1;
    _Dst = _Dst + 0x100;
    puVar9 = puVar9 + 1;
  } while ((int)uVar12 < 8);
  RfCheckDiskRaidParameter(param_1);
  puVar4 = (undefined4 *)(param_1 + 0x388);
  memset(puVar4,0,0x5c0);
  lVar17 = 8;
  puVar9 = puVar22;
  do {
    if ((*puVar9 & 1) != 0) {
      if ((*puVar9 & 2) == 0) {
        if (*psVar14 != -0x55ab) {
          *puVar4 = 1;
        }
      }
      else {
        puVar4[3] = 1;
      }
    }
    puVar9 = puVar9 + 1;
    puVar4 = puVar4 + 0x2e;
    psVar14 = psVar14 + 0x100;
    lVar17 = lVar17 + -1;
  } while (lVar17 != 0);
  uVar12 = 0;
  piVar10 = (int *)(param_1 + 0xd42);
  piVar13 = (int *)(param_1 + 0x400);
  uVar18 = 0;
  puVar9 = puVar22;
  do {
    if ((*puVar9 & 1) != 0) {
      BuildDiskModeParameter(param_1,uVar12,uVar18);
      if ((piVar13[-0x1b] == 0) && (piVar13[-0x1e] == 0)) {
        RfBuildRaidDiskBasicParameter(param_1,uVar12);
      }
      else {
        iVar3 = 0;
        piVar6 = (int *)((longlong)piVar10 + -0x1a);
        lVar17 = 5;
        do {
          iVar3 = iVar3 + *piVar6;
          piVar6 = piVar6 + 1;
          lVar17 = lVar17 + -1;
        } while (lVar17 != 0);
        lVar17 = 0xc;
        piVar6 = piVar10;
        do {
          iVar3 = iVar3 + *piVar6;
          piVar6 = piVar6 + 1;
          lVar17 = lVar17 + -1;
        } while (lVar17 != 0);
        piVar13[-3] = iVar3;
        *piVar13 = iVar3;
      }
    }
    uVar12 = uVar12 + 1;
    puVar9 = puVar9 + 1;
    piVar13 = piVar13 + 0x2e;
    piVar10 = piVar10 + 0x35;
  } while ((int)uVar12 < 8);
  RfBuildDiskLinker(param_1);
  uVar5 = 0;
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  pcVar7 = (char *)(param_1 + 0x3a4);
  lVar17 = 0;
  puVar9 = puVar22;
  do {
    bVar2 = false;
    if (((((*puVar9 & 1) != 0) && (*(int *)(pcVar7 + -0x10) == 0)) &&
        (*(int *)(pcVar7 + -0x1c) == 0)) && (local_38[lVar17] == '\0')) {
      piVar10 = (int *)(param_1 + 0x3a8);
      uVar19 = uVar5;
      puVar20 = puVar22;
      do {
        if ((((((*puVar20 & 1) != 0) && (piVar10[-5] == 0)) &&
             ((piVar10[-8] == 0 &&
              ((local_38[uVar19] == '\0' && (*piVar10 == *(int *)(pcVar7 + 4))))))) &&
            ((char)piVar10[-1] == *pcVar7)) && (local_38[uVar19] = '\x01', piVar10[-7] != 0)) {
          *(undefined1 *)(piVar10 + -6) = 0;
          bVar2 = true;
        }
        uVar19 = uVar19 + 1;
        puVar20 = puVar20 + 1;
        piVar10 = piVar10 + 0x2e;
      } while ((longlong)uVar19 < 8);
      if (!bVar2) {
        pcVar7[-0x18] = '\x01';
        pcVar7[-0x17] = '\0';
        pcVar7[-0x16] = '\0';
        pcVar7[-0x15] = '\0';
        pcVar7[-0x14] = '\x01';
      }
    }
    lVar17 = lVar17 + 1;
    puVar9 = puVar9 + 1;
    pcVar7 = pcVar7 + 0xb8;
  } while (lVar17 < 8);
  puVar4 = (undefined4 *)(param_1 + 0x3f0);
  puVar15 = (undefined4 *)(param_1 + 0xd8c);
  puVar9 = puVar22;
  do {
    if (((*puVar9 & 1) != 0) && (puVar4[-0x17] != 1)) {
      if (puVar4[-0x1a] == 1) {
        lVar17 = CONCAT44(puVar15[0x14],*puVar15) + -1;
        *puVar4 = (int)lVar17;
        puVar4[0x12] = (int)((ulonglong)lVar17 >> 0x20);
      }
      else {
        RfCheckRaidCapacity(param_1,(int)uVar5);
      }
    }
    uVar12 = (int)uVar5 + 1;
    uVar5 = (ulonglong)uVar12;
    puVar9 = puVar9 + 1;
    puVar4 = puVar4 + 0x2e;
    puVar15 = puVar15 + 0x35;
  } while ((int)uVar12 < 8);
  uVar5 = SetFirstTarget(param_1);
  pbVar16 = (byte *)(param_1 + 0x958);
  puVar8 = (undefined1 *)(param_1 + 0x43c);
  lVar17 = 8;
  do {
    uVar5 = CONCAT71((int7)(uVar5 >> 8),(byte)*puVar22);
    if ((((byte)*puVar22 & 1) != 0) && (puVar8[-0xa3] == '\0')) {
      *puVar8 = 0xff;
    }
    puVar22 = puVar22 + 1;
    puVar8 = puVar8 + 0xb8;
    lVar17 = lVar17 + -1;
  } while (lVar17 != 0);
  bVar11 = 0;
  lVar17 = param_1 - (longlong)pbVar16;
  pbVar21 = pbVar16;
  do {
    piVar10 = (int *)(param_1 + 0x388);
    if (pbVar16[lVar17 + 0x958] < 8) {
      lVar23 = 8;
      do {
        uVar5 = CheckDeviceCheckSum((longlong)pbVar16,piVar10);
        if ((char)uVar5 != '\0') {
          *(byte *)(piVar10 + 0x2d) = bVar11;
        }
        piVar10 = piVar10 + 0x2e;
        lVar23 = lVar23 + -1;
      } while (lVar23 != 0);
    }
    bVar11 = bVar11 + 1;
    pbVar16 = pbVar16 + 0x28;
  } while (bVar11 < 8);
  piVar10 = (int *)(param_1 + 700);
  do {
    if (pbVar21[1] == 0) {
      bVar11 = *pbVar21;
      uVar5 = CONCAT71((int7)(uVar5 >> 8),bVar11);
      if (bVar11 == 0xff) goto LAB_00013ec3;
      cVar1 = *(char *)((ulonglong)bVar11 * 0xb8 + 0x3ac + param_1);
      uVar5 = (ulonglong)(byte)-cVar1;
      *piVar10 = (cVar1 != '\0') + 1;
    }
    else {
LAB_00013ec3:
      *piVar10 = 0;
    }
    piVar10 = piVar10 + 1;
    pbVar21 = pbVar21 + 0x28;
    lVar24 = lVar24 + -1;
    if (lVar24 == 0) {
      return uVar5;
    }
  } while( true );
}



===== AllocateUncachedBuffers @ 00013f00 =====

undefined8 AllocateUncachedBuffers(longlong param_1,undefined8 param_2)

{
  void *_Dst;
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  uint uVar8;
  byte *pbVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  longlong lVar12;
  byte *pbVar13;
  int iVar14;
  
  pbVar13 = (byte *)(param_1 + 0x948);
  iVar4 = 0;
  iVar14 = 0;
  iVar3 = 0;
  lVar12 = 4;
  pbVar9 = pbVar13;
  do {
    if ((*pbVar9 & 4) != 0) {
      iVar3 = iVar3 + 1;
    }
    pbVar9 = pbVar9 + 2;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  if (iVar3 == 0) {
    uVar8 = *(uint *)(param_1 + 4);
    if (Hibernate == '\0') {
      iVar4 = uVar8 * 0x50000 + 0x10000;
      iVar3 = uVar8 * 0x10000 + 0x2000 + iVar4;
    }
    else {
      iVar3 = 0x2000;
      g_raid5hiberBufSize = (uint)(0x8000 / (ulonglong)uVar8) & 0xfffffe00;
    }
    lVar12 = StorPortGetUncachedExtension(param_1,param_2,iVar3);
    if (lVar12 == 0) {
      return 0;
    }
    plVar5 = (longlong *)(param_1 + 0x220);
    lVar1 = 4;
    do {
      lVar7 = lVar1;
      lVar2 = lVar12;
      *plVar5 = lVar2;
      plVar5 = plVar5 + 1;
      lVar1 = lVar7 + -1;
      lVar12 = lVar2 + 0x400;
    } while (lVar1 != 0);
    *(longlong *)(param_1 + 0x47f0) = lVar2 + 0x400;
    lVar2 = lVar2 + 0x1400;
    if (Hibernate == '\0') {
      *(longlong *)(param_1 + 0x20) = lVar2;
      *(uint *)(param_1 + 0x28) = uVar8 * 0x10000;
      plVar5 = (longlong *)(param_1 + 0x4220);
      plVar6 = (longlong *)(param_1 + 0x46f0);
      uVar11 = (ulonglong)((int)lVar7 + 7);
      do {
        if (*pbVar13 != 0) {
          *plVar6 = lVar2;
          plVar5[8] = lVar2;
          *plVar5 = lVar2;
          lVar2 = lVar2 + 0x10000;
        }
        plVar5 = plVar5 + 1;
        pbVar13 = pbVar13 + 1;
        plVar6 = plVar6 + 3;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
      *(longlong *)(param_1 + 0x10) = lVar2;
      *(int *)(param_1 + 0x18) = iVar4;
    }
  }
  else {
    uVar8 = (iVar3 + 2) * 0x1000;
    if (Hibernate == '\0') {
      iVar14 = iVar3 * 0x50000 + 0x10000;
      uVar8 = uVar8 + iVar3 * 0x10000 + iVar14;
    }
    else {
      iVar4 = (int)(0x8000 / (longlong)iVar3);
      g_raid5hiberBufSize = iVar4 + (iVar4 >> 0x1f & 0x1ffU) & 0xfffffe00;
    }
    _Dst = (void *)StorPortGetUncachedExtension(param_1,param_2,uVar8);
    if (_Dst == (void *)0x0) {
      return 0;
    }
    memset(_Dst,0,(ulonglong)uVar8);
    if (((ulonglong)_Dst & 0xfff) != 0) {
      _Dst = (void *)((((ulonglong)_Dst >> 0xc) + 1) * 0x1000);
    }
    iVar4 = 0;
    puVar10 = (undefined8 *)(param_1 + 0x38);
    lVar12 = 4;
    pbVar9 = pbVar13;
    do {
      if ((*pbVar9 & 4) != 0) {
        lVar1 = (longlong)iVar4;
        iVar4 = iVar4 + 1;
        *puVar10 = (void *)(lVar1 * 0x1000 + (longlong)_Dst);
      }
      puVar10 = puVar10 + 1;
      pbVar9 = pbVar9 + 2;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
    lVar2 = (longlong)iVar4 * 0x1000;
    *(void **)(param_1 + 0x47f0) = (void *)(lVar2 + (longlong)_Dst);
    lVar12 = lVar2 + (longlong)_Dst + 0x1000;
    if (Hibernate == '\0') {
      *(longlong *)(param_1 + 0x20) = lVar12;
      *(int *)(param_1 + 0x28) = iVar3 * 0x10000;
      lVar2 = 0;
      plVar5 = (longlong *)(param_1 + 0x4220);
      plVar6 = (longlong *)(param_1 + 0x46f0);
      do {
        if (pbVar13[lVar2] != 0) {
          *plVar6 = lVar12;
          plVar5[8] = lVar12;
          *plVar5 = lVar12;
          lVar12 = lVar12 + 0x10000;
        }
        lVar2 = lVar2 + 1;
        plVar5 = plVar5 + 1;
        plVar6 = plVar6 + 3;
      } while (lVar2 < 8);
      *(longlong *)(param_1 + 0x10) = lVar12;
      *(int *)(param_1 + 0x18) = iVar14;
    }
  }
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
}



===== ParseScsiMiniportIoctl @ 00014170 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ParseScsiMiniportIoctl(undefined8 *param_1,ulonglong param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong lVar6;
  undefined1 auStack_98 [32];
  undefined8 local_78 [12];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  puVar4 = *(undefined8 **)(param_2 + 0xf0);
  lVar6 = puVar4[3];
  if (lVar6 == 0) {
    *(undefined4 *)(param_2 + 0xfc) = 1;
    *(undefined4 *)(param_2 + 0xf8) = 6;
    return;
  }
  iVar5 = AtapiStringCmp(lVar6 + 4,(byte *)"SCSIDISK",8);
  if (iVar5 == 0) {
    uVar3 = *(uint *)(lVar6 + 0x10);
    if (uVar3 == 0x1b0500) {
      bVar1 = *(byte *)(lVar6 + 0x28);
      if (bVar1 < 8) {
        bVar2 = *(byte *)(param_1 + (ulonglong)bVar1 * 5 + 299);
        if ((bVar2 != 0xff) &&
           (*(char *)((longlong)param_1 + (ulonglong)bVar1 * 0x28 + 0x959) == '\0')) {
          *(undefined8 *)(lVar6 + 0x1c) = 0;
          *(undefined8 *)(lVar6 + 0x24) = 0;
          *(undefined8 *)(lVar6 + 0x2c) = 0;
          *(undefined1 *)(lVar6 + 0x1e) = 0;
          *(undefined2 *)(lVar6 + 0x1c) = 0x101;
          *(uint *)(lVar6 + 0x20) =
               (-(uint)((*(byte *)((longlong)param_1 + (ulonglong)bVar2 * 2 + 0xab8) & 2) != 0) &
               0xfffffffd) + 5;
          if ((*(byte *)((longlong)param_1 + (ulonglong)bVar2 * 2 + 0xab8) & 2) == 0) {
            *(char *)(lVar6 + 0x1f) = '\x01' << (bVar2 & 0x1f);
          }
          else {
            *(char *)(lVar6 + 0x1f) = '\x01' << (bVar2 + 4 & 0x1f);
          }
          *(undefined4 *)(param_2 + 0xf8) = 1;
          goto LAB_00014304;
        }
      }
      *(undefined4 *)(param_2 + 0xf8) = 10;
      goto LAB_00014304;
    }
    if (uVar3 == 0x1b0501) {
      ParseIoctlIdentify((longlong)param_1,param_2);
      return;
    }
    if (0x1b0501 < uVar3) {
      if (uVar3 < 0x1b050a) {
        ParseSmartCommand((longlong)param_1,param_2);
        return;
      }
      if (uVar3 == 0x1b0800) {
        ConstructUserSrb(puVar4,local_78);
        ParseUserCommand(param_1,param_2,local_78);
        return;
      }
      if (uVar3 == 0x1b081f) {
        ParseIoctlSerialNumber((longlong)param_1,param_2);
        return;
      }
    }
  }
  *(undefined4 *)(param_2 + 0xf8) = 6;
LAB_00014304:
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return;
}



===== ParseUserCommand @ 00014334 =====

/* WARNING: Removing unreachable block (ram,0x00014bc2) */

void ParseUserCommand(undefined8 *param_1,ulonglong param_2,undefined8 *param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined8 *puVar8;
  bool bVar9;
  void *pvVar10;
  ulonglong uVar11;
  longlong lVar12;
  byte bVar13;
  uint uVar14;
  longlong lVar15;
  longlong lVar16;
  undefined1 *puVar17;
  char *pcVar18;
  longlong lVar19;
  ulonglong uVar20;
  char cVar21;
  uint local_res8 [2];
  
  bVar13 = *(byte *)((longlong)param_3 + 0x4d);
  bVar1 = *(byte *)(*(longlong *)(param_2 + 0xf0) + 6);
  if ((*(char *)((longlong)param_3 + 0x49) != '\x06') ||
     (*(char *)((longlong)param_3 + 0x4a) != '\x11')) goto LAB_00014cc0;
  bVar2 = *(byte *)((longlong)param_3 + 0x4b);
  if (bVar2 < 10) {
    if (7 < bVar2) {
      ParseUserRwDeviceData((ulonglong)bVar2,param_2,(longlong)param_3);
      return;
    }
    if (bVar2 == 1) {
      *(undefined4 *)(param_2 + 0xf8) = 1;
      goto LAB_00014cc7;
    }
    if (bVar2 != 2) {
      if (bVar2 == 3) {
        if (3 < bVar13 >> 1) goto LAB_00014cc0;
        puVar6 = (undefined4 *)param_3[3];
        uVar11 = (ulonglong)(bVar13 >> 1);
        lVar19 = uVar11 * 2;
        if (*(char *)(lVar19 + 0x948 + (longlong)param_1) == '\0') {
          *(byte *)((longlong)puVar6 + 0xf) = *(byte *)((longlong)puVar6 + 0xf) | 2;
        }
        else {
          *(byte *)((longlong)puVar6 + 0xf) = *(byte *)((longlong)puVar6 + 0xf) & 0xfd;
          *(byte *)((longlong)puVar6 + 0xd) = *(byte *)((longlong)param_1 + uVar11 * 4 + 0xab8) & 1;
          *(byte *)((longlong)puVar6 + 0xe) = *(byte *)((longlong)param_1 + uVar11 * 4 + 0xaba) & 1;
          if (*(char *)(lVar19 + 0x948 + (longlong)param_1) != '\x04') {
            *puVar6 = *(undefined4 *)(param_1 + uVar11 + 0x14);
            puVar6[1] = *(undefined4 *)(param_1 + uVar11 + 0x18);
            puVar6[2] = *(undefined4 *)(param_1 + uVar11 + 0x1c);
          }
          *(undefined1 *)(puVar6 + 3) = 1;
          if (*(char *)(lVar19 + 0x948 + (longlong)param_1) == '\x01') {
            if ((*(byte *)((longlong)param_1 + uVar11 * 4 + 0xab8) & 1) != 0) {
              *(byte *)(puVar6 + 3) =
                   ((byte)(*(uint *)(uVar11 * 0x170 + 0x39c + (longlong)param_1) >> 6) & 3) - 1;
            }
          }
          else {
            *(undefined1 *)(puVar6 + 3) = 2;
          }
          if ((*(char *)(lVar19 + 0x949 + (longlong)param_1) == '\0') ||
             (((*(int *)((longlong)param_1 + 0x20c) == 0x31491106 ||
               (*(int *)((longlong)param_1 + 0x20c) == 0x5911106)) &&
              ((*(byte *)((longlong)param_1 + 0x13fd) & 0x20) == 0)))) {
            bVar13 = *(byte *)((longlong)puVar6 + 0xf) | 1;
          }
          else {
            bVar13 = *(byte *)((longlong)puVar6 + 0xf) & 0xfe;
          }
          *(byte *)((longlong)puVar6 + 0xf) = bVar13;
        }
      }
      else {
        if (bVar2 != 4) {
LAB_000149f5:
          bVar9 = RfParseRaidUserCmd(param_1,param_2,param_3);
          if (bVar9) {
            return;
          }
          *(undefined4 *)(param_2 + 0xf8) = 6;
          goto LAB_000149ad;
        }
        if (7 < bVar13) goto LAB_00014cc0;
        lVar19 = param_3[3];
        uVar11 = (ulonglong)bVar13;
        uVar4 = *(ushort *)((longlong)param_1 + uVar11 * 2 + 0xab8);
        if ((uVar4 & 1) == 0) {
          *(undefined4 *)(param_2 + 0xf8) = 6;
          goto LAB_00014cc7;
        }
        if ((uVar4 & 2) == 0) {
          *(byte *)(lVar19 + 200) = -(*(char *)(uVar11 + 0x948 + (longlong)param_1) != '\x01') & 2;
        }
        else {
          *(undefined1 *)(lVar19 + 200) = 1;
        }
        lVar16 = uVar11 * 0xd4;
        puVar17 = (undefined1 *)((longlong)param_1 + lVar16 + 0xd28);
        lVar15 = 10;
        lVar12 = (lVar19 + uVar11 * -0xd4) - (longlong)param_1;
        do {
          puVar17[lVar12 + -0xd28] = puVar17[1];
          uVar3 = *puVar17;
          puVar17 = puVar17 + 2;
          puVar17[lVar12 + -0xd29] = uVar3;
          lVar15 = lVar15 + -1;
        } while (lVar15 != 0);
        puVar17 = (undefined1 *)((longlong)param_1 + lVar16 + 0xd42);
        lVar15 = 4;
        do {
          puVar17[lVar12 + -0xd22] = puVar17[1];
          uVar3 = *puVar17;
          puVar17 = puVar17 + 2;
          puVar17[lVar12 + -0xd23] = uVar3;
          lVar15 = lVar15 + -1;
        } while (lVar15 != 0);
        lVar15 = 0x14;
        puVar17 = (undefined1 *)((longlong)param_1 + lVar16 + 0xd4a);
        do {
          puVar17[lVar12 + -0xd1a] = puVar17[1];
          uVar3 = *puVar17;
          puVar17 = puVar17 + 2;
          puVar17[lVar12 + -0xd1b] = uVar3;
          lVar15 = lVar15 + -1;
        } while (lVar15 != 0);
        uVar4 = *(ushort *)((longlong)param_1 + lVar16 + 0xdb6);
        uVar14 = (uint)uVar4;
        if (0x1d < (ushort)(uVar4 - 1)) {
          uVar14 = 0x1f;
        }
        memcpy((void *)(lVar19 + 0x88),&UNK_00034210 + (ulonglong)uVar14 * 0x40,0x40);
        lVar12 = uVar11 * 0xb8;
        *(undefined4 *)(lVar19 + 0x7c) = *(undefined4 *)((longlong)param_1 + lVar16 + 0xd8c);
        *(undefined4 *)(lVar19 + 0x80) = *(undefined4 *)((longlong)param_1 + lVar16 + 0xddc);
        *(uint *)(lVar19 + 0x70) = (uint)*(ushort *)((longlong)param_1 + lVar16 + 0xd80);
        *(uint *)(lVar19 + 0x74) = (uint)*(ushort *)((longlong)param_1 + lVar16 + 0xd82);
        *(uint *)(lVar19 + 0x78) = (uint)*(ushort *)((longlong)param_1 + lVar16 + 0xd84);
        uVar14 = *(uint *)(lVar12 + 0x39c + (longlong)param_1) >> 0xc;
        if ((uVar14 & 0xf) == 0) {
          *(undefined1 *)(lVar19 + 0x84) = 0xff;
        }
        else {
          *(byte *)(lVar19 + 0x84) = (byte)uVar14 & 0xf;
        }
        uVar14 = *(uint *)(lVar12 + 0x39c + (longlong)param_1) >> 0x14;
        if ((uVar14 & 0xf) == 0) {
          *(undefined1 *)(lVar19 + 0x85) = 0xff;
        }
        else {
          *(byte *)(lVar19 + 0x85) = (byte)uVar14 & 0xf;
        }
        uVar14 = *(uint *)(lVar12 + 0x39c + (longlong)param_1);
        bVar13 = 0;
        if (uVar14 >> 0x1c == 0) {
          *(undefined1 *)(lVar19 + 0x86) = 0xff;
        }
        else {
          *(byte *)(lVar19 + 0x86) = (byte)(uVar14 >> 0x1c);
        }
        uVar14 = *(uint *)(lVar12 + 0x39c + (longlong)param_1);
        if ((uVar14 & 4) == 0) {
          bVar13 = (byte)(uVar14 >> 8) & 0xf;
        }
        else if ((uVar14 & 0xf000000) == 0) {
          if ((uVar14 & 0xf0000) != 0) {
            bVar13 = ((byte)(uVar14 >> 0x10) & 0xf) + 0x20;
          }
        }
        else {
          bVar13 = ((byte)(uVar14 >> 0x18) & 0xf) + 0x40;
        }
        *(byte *)(lVar19 + 0x87) = bVar13;
      }
      goto LAB_000149a7;
    }
    iVar5 = *(int *)(param_1 + 0x41);
    pcVar7 = (char *)param_3[3];
    if (iVar5 == 0x5811106) {
      pcVar18 = pcVar7;
      lVar19 = 0x20;
      do {
        lVar12 = lVar19 + -1;
        if ((lVar12 == 0) ||
           (pcVar18[(longlong)"VIA MSP RAID Controller - 0581" - (longlong)pcVar7] == '\0')) break;
        *pcVar18 = pcVar18[(longlong)"VIA MSP RAID Controller - 0581" - (longlong)pcVar7];
        pcVar18 = pcVar18 + 1;
        lVar19 = lVar12;
      } while (lVar12 != 0);
      if (lVar19 == 0) {
        pcVar18 = pcVar18 + -1;
      }
      *pcVar18 = '\0';
    }
    else {
      pcVar18 = pcVar7;
      if (iVar5 == 0x5911106) {
        lVar19 = 0x20;
        do {
          if ((lVar19 == 5) ||
             (pcVar18[(longlong)"VIA RAID Controller - 0591" - (longlong)pcVar7] == '\0')) break;
          *pcVar18 = pcVar18[(longlong)"VIA RAID Controller - 0591" - (longlong)pcVar7];
          pcVar18 = pcVar18 + 1;
          lVar19 = lVar19 + -1;
        } while (lVar19 != 0);
      }
      else {
        if (iVar5 == 0x31491106) {
          lVar19 = (longlong)"VIA RAID Controller - 3149" - (longlong)pcVar7;
          if (*(char *)((longlong)param_1 + 0x13bc) == 'P') {
            lVar12 = 0x20;
            do {
              if ((lVar12 == 5) || (pcVar18[lVar19] == '\0')) break;
              *pcVar18 = pcVar18[lVar19];
              pcVar18 = pcVar18 + 1;
              lVar12 = lVar12 + -1;
            } while (lVar12 != 0);
          }
          else {
            lVar12 = 0x20;
            if (*(char *)((longlong)param_1 + 0x13bc) == -0x80) {
              do {
                if ((lVar12 == 5) || (pcVar18[lVar19] == '\0')) break;
                *pcVar18 = pcVar18[lVar19];
                pcVar18 = pcVar18 + 1;
                lVar12 = lVar12 + -1;
              } while (lVar12 != 0);
            }
            else {
              do {
                if ((lVar12 == 5) || (pcVar18[lVar19] == '\0')) break;
                *pcVar18 = pcVar18[lVar19];
                pcVar18 = pcVar18 + 1;
                lVar12 = lVar12 + -1;
              } while (lVar12 != 0);
            }
          }
          if (lVar12 == 0) {
            pcVar18 = pcVar18 + -1;
          }
          *pcVar18 = '\0';
          goto LAB_00014942;
        }
        lVar19 = 0x20;
        if (iVar5 == 0x31641106) {
          do {
            if ((lVar19 == 5) ||
               (pcVar18[(longlong)"VIA RAID Controller - 3164" - (longlong)pcVar7] == '\0')) break;
            *pcVar18 = pcVar18[(longlong)"VIA RAID Controller - 3164" - (longlong)pcVar7];
            pcVar18 = pcVar18 + 1;
            lVar19 = lVar19 + -1;
          } while (lVar19 != 0);
        }
        else if (iVar5 == 0x32491106) {
          do {
            if ((lVar19 == 5) ||
               (pcVar18[(longlong)"VIA RAID Controller - 3249" - (longlong)pcVar7] == '\0')) break;
            *pcVar18 = pcVar18[(longlong)"VIA RAID Controller - 3249" - (longlong)pcVar7];
            pcVar18 = pcVar18 + 1;
            lVar19 = lVar19 + -1;
          } while (lVar19 != 0);
        }
        else if (iVar5 == 0x33491106) {
          do {
            if ((lVar19 == 5) ||
               (pcVar18[(longlong)"VIA RAID Controller - 3349" - (longlong)pcVar7] == '\0')) break;
            *pcVar18 = pcVar18[(longlong)"VIA RAID Controller - 3349" - (longlong)pcVar7];
            pcVar18 = pcVar18 + 1;
            lVar19 = lVar19 + -1;
          } while (lVar19 != 0);
        }
        else if (iVar5 == 0x73721106) {
          do {
            if ((lVar19 == 5) ||
               (pcVar18[(longlong)"VIA RAID Controller - 7372" - (longlong)pcVar7] == '\0')) break;
            *pcVar18 = pcVar18[(longlong)"VIA RAID Controller - 7372" - (longlong)pcVar7];
            pcVar18 = pcVar18 + 1;
            lVar19 = lVar19 + -1;
          } while (lVar19 != 0);
        }
        else {
          do {
            if ((lVar19 == 0xd) ||
               (pcVar18[(longlong)"Unknown Controller" - (longlong)pcVar7] == '\0')) break;
            *pcVar18 = pcVar18[(longlong)"Unknown Controller" - (longlong)pcVar7];
            pcVar18 = pcVar18 + 1;
            lVar19 = lVar19 + -1;
          } while (lVar19 != 0);
        }
      }
      if (lVar19 == 0) {
        pcVar18 = pcVar18 + -1;
      }
      *pcVar18 = '\0';
    }
LAB_00014942:
    lVar19 = 0x20;
    pcVar18 = pcVar7 + 0x20;
    lVar12 = (longlong)"VIA Technologies" - (longlong)pcVar18;
    do {
      if ((lVar19 == 0xf) || (pcVar18[lVar12] == '\0')) break;
      *pcVar18 = pcVar18[lVar12];
      pcVar18 = pcVar18 + 1;
      lVar19 = lVar19 + -1;
    } while (lVar19 != 0);
    if (lVar19 == 0) {
      pcVar18 = pcVar18 + -1;
    }
    *pcVar18 = '\0';
    cVar21 = '\x04';
    pcVar18 = (char *)((longlong)param_1 + 0x94e);
    pcVar7[0x40] = '\x04';
    pcVar7[0x41] = '\x02';
    pcVar7[0x42] = '\x06';
    lVar19 = 3;
    do {
      if (*pcVar18 != '\0') break;
      cVar21 = cVar21 + -1;
      pcVar18 = pcVar18 + -2;
      lVar19 = lVar19 + -1;
    } while (-1 < lVar19);
    pcVar7[0x43] = cVar21;
  }
  else if (bVar2 == 0xc) {
    if (7 < bVar13) goto LAB_00014cc0;
    puVar6 = (undefined4 *)param_3[3];
    uVar11 = (ulonglong)bVar13;
    if ((*(byte *)((longlong)param_1 + uVar11 * 2 + 0xab8) & 1) != 0) {
      *puVar6 = *(undefined4 *)(param_1 + uVar11 * 0x17 + 0x7f);
      if ((*(char *)(uVar11 * 0xb8 + 0x399 + (longlong)param_1) == '\0') ||
         (*(char *)(uVar11 * 0xb8 + 0x3ae + (longlong)param_1) != '\0')) {
        *(undefined1 *)(puVar6 + 1) = 0;
        goto LAB_000149a7;
      }
    }
    *(undefined1 *)(puVar6 + 1) = 1;
  }
  else if (bVar2 == 0xe) {
    if (7 < bVar13) {
LAB_00014cc0:
      *(undefined4 *)(param_2 + 0xf8) = 6;
LAB_00014cc7:
      *(undefined4 *)(param_2 + 0xfc) = 1;
      return;
    }
    uVar20 = (ulonglong)bVar13;
    uVar4 = *(ushort *)((longlong)param_1 + uVar20 * 2 + 0xab8);
    uVar11 = 0xe;
    if (((uVar4 & 1) == 0) || ((uVar4 & 2) == 0)) {
LAB_00014c61:
      TestDeviceReady(uVar11,param_2,param_3);
      return;
    }
    bVar2 = *(byte *)(uVar20 + 0x948 + (longlong)param_1);
    uVar11 = (ulonglong)bVar2;
    if ((bVar2 - 2 & 0xfd) != 0) goto LAB_00014c61;
    if (bVar2 == 4) {
      local_res8[0] =
           *(uint *)((longlong)(int)(bVar13 >> 1 & 0x80000003) * 0x80 + 0x128 + param_1[0xb]);
    }
    else {
      ReadWriteHostSStatusRegister((longlong)param_1,(uint)bVar13,param_3,local_res8);
    }
    *(uint *)((longlong)param_1 + uVar20 * 4 + 0x100) = local_res8[0];
    if (((byte)local_res8[0] & 0xf) != 3) {
      *(undefined2 *)((longlong)param_1 + uVar20 * 2 + 0xab8) = 0;
      *(undefined1 *)(param_1 + (ulonglong)bVar1 * 5 + 299) = 0xff;
      cVar21 = *(char *)(uVar20 * 0xb8 + 0x39a + (longlong)param_1);
      if (cVar21 != -1) {
        *(char *)(uVar20 * 0xb8 + 0x39a + (longlong)param_1) = cVar21 + '\x01';
      }
      if (*(uint *)(param_1 + uVar20 * 0x17 + 0x7f) < 0xfffffff0) {
        *(uint *)(param_1 + uVar20 * 0x17 + 0x7f) = *(uint *)(param_1 + uVar20 * 0x17 + 0x7f) + 1;
      }
      *(undefined4 *)(param_2 + 0xf8) = 4;
      goto LAB_000149ad;
    }
  }
  else {
    if (bVar2 != 0x24) {
      if (bVar2 != 0xb0) goto LAB_000149f5;
      if (bVar13 < 8) {
        pvVar10 = StorAllocateSubCmd(0xb0,param_2);
        if (pvVar10 == (void *)0x0) {
          *(undefined4 *)(param_2 + 0xfc) = 2;
          *(undefined1 *)(param_2 + 0x100) = 2;
          return;
        }
        *(undefined8 *)(param_2 + 0x104) = 1;
        *(undefined4 *)(param_2 + 0x10c) = 1;
        *(undefined8 *)(param_2 + 0x160) = 0;
        *(ulonglong *)((longlong)pvVar10 + 0x10) = param_2;
        *(undefined4 *)((longlong)pvVar10 + 0xa0) = 0;
        *(undefined8 *)((longlong)pvVar10 + 0x48) = *param_3;
        *(undefined8 *)((longlong)pvVar10 + 0x50) = param_3[1];
        *(undefined8 *)((longlong)pvVar10 + 0x58) = param_3[2];
        *(undefined8 *)((longlong)pvVar10 + 0x60) = param_3[3];
        *(undefined8 *)((longlong)pvVar10 + 0x68) = param_3[4];
        *(undefined8 *)((longlong)pvVar10 + 0x70) = param_3[5];
        *(undefined8 *)((longlong)pvVar10 + 0x78) = param_3[6];
        *(undefined8 *)((longlong)pvVar10 + 0x80) = param_3[7];
        *(undefined8 *)((longlong)pvVar10 + 0x88) = param_3[8];
        *(undefined8 *)((longlong)pvVar10 + 0x90) = param_3[9];
        *(undefined8 *)((longlong)pvVar10 + 0x98) = param_3[10];
        *(byte *)((longlong)pvVar10 + 0x4e) = bVar13;
        *(code **)((longlong)pvVar10 + 0x18) = DispatchUserSmartCommand;
        if (*(int *)(param_2 + 0xea4) != 0) {
          lVar19 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
          *(void **)(lVar19 + 0x78 + (ulonglong)*(byte *)(lVar19 + 0x278) * 8) = pvVar10;
          *(char *)(lVar19 + 0x278) = *(char *)(lVar19 + 0x278) + '\x01';
        }
        *(undefined4 *)(param_2 + 0xfc) = 0;
        return;
      }
      goto LAB_00014cc0;
    }
    uVar11 = (ulonglong)*(byte *)(param_1 + (ulonglong)bVar13 * 5 + 299);
    if ((*(byte *)(param_1 + (ulonglong)bVar13 * 5 + 299) == 0xff) ||
       ((*(byte *)((longlong)param_1 + uVar11 * 2 + 0xab8) & 1) == 0)) {
      *(undefined4 *)(param_2 + 0xfc) = 1;
      *(undefined4 *)(param_2 + 0xf8) = 10;
      return;
    }
    puVar8 = (undefined8 *)param_3[3];
    *puVar8 = param_1[uVar11 * 0xd + 0x7cc];
    puVar8[1] = param_1[uVar11 * 0xd + 0x7cd];
    *(undefined4 *)(puVar8 + 2) = *(undefined4 *)(param_1 + uVar11 * 0xd + 0x7ce);
  }
LAB_000149a7:
  *(undefined4 *)(param_2 + 0xf8) = 1;
LAB_000149ad:
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return;
}



===== ConstructUserSrb @ 00014cec =====

void ConstructUserSrb(undefined8 *param_1,undefined8 *param_2)

{
  longlong lVar1;
  
  lVar1 = param_1[3];
  if (param_2 != param_1) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = param_1[2];
    param_2[3] = param_1[3];
    param_2[4] = param_1[4];
    param_2[5] = param_1[5];
    param_2[6] = param_1[6];
    param_2[7] = param_1[7];
    param_2[8] = param_1[8];
    param_2[9] = param_1[9];
    param_2[10] = param_1[10];
  }
  if (param_2 + 9 != (undefined8 *)(lVar1 + 0x20)) {
    memcpy(param_2 + 9,(undefined8 *)(lVar1 + 0x20),(ulonglong)*(byte *)(lVar1 + 0x1c));
  }
  *(undefined1 *)((longlong)param_2 + 10) = *(undefined1 *)(lVar1 + 0x1c);
  param_2[3] = lVar1 + 0x34;
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)(lVar1 + 0x30);
  param_2[7] = param_1[7];
  return;
}



===== TestDeviceReady @ 00014da4 =====

void TestDeviceReady(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  void *pvVar3;
  
  uVar1 = *(undefined1 *)((longlong)param_3 + 0x4d);
  pvVar3 = StorAllocateSubCmd(param_1,param_2);
  if (pvVar3 == (void *)0x0) {
    *(undefined4 *)(param_2 + 0xfc) = 2;
    *(undefined1 *)(param_2 + 0x100) = 2;
  }
  else {
    *(undefined8 *)(param_2 + 0x104) = 1;
    *(undefined4 *)(param_2 + 0x10c) = 1;
    *(undefined8 *)(param_2 + 0x160) = 0;
    *(longlong *)((longlong)pvVar3 + 0x10) = param_2;
    *(undefined4 *)((longlong)pvVar3 + 0xa0) = 0;
    *(undefined8 *)((longlong)pvVar3 + 0x48) = *param_3;
    *(undefined8 *)((longlong)pvVar3 + 0x50) = param_3[1];
    *(undefined8 *)((longlong)pvVar3 + 0x58) = param_3[2];
    *(undefined8 *)((longlong)pvVar3 + 0x60) = param_3[3];
    *(undefined8 *)((longlong)pvVar3 + 0x68) = param_3[4];
    *(undefined8 *)((longlong)pvVar3 + 0x70) = param_3[5];
    *(undefined8 *)((longlong)pvVar3 + 0x78) = param_3[6];
    *(undefined8 *)((longlong)pvVar3 + 0x80) = param_3[7];
    *(undefined8 *)((longlong)pvVar3 + 0x88) = param_3[8];
    *(undefined8 *)((longlong)pvVar3 + 0x90) = param_3[9];
    *(undefined8 *)((longlong)pvVar3 + 0x98) = param_3[10];
    *(undefined1 *)((longlong)pvVar3 + 0x4e) = uVar1;
    *(code **)((longlong)pvVar3 + 0x18) = DispatchTestDevReady;
    if (*(int *)(param_2 + 0xea4) != 0) {
      lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
      *(void **)(lVar2 + 0x78 + (ulonglong)*(byte *)(lVar2 + 0x278) * 8) = pvVar3;
      *(char *)(lVar2 + 0x278) = *(char *)(lVar2 + 0x278) + '\x01';
    }
    *(undefined4 *)(param_2 + 0xfc) = 0;
  }
  return;
}



===== ParseSmartCommand @ 00014ebc =====

void ParseSmartCommand(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  void *pvVar8;
  byte bVar9;
  char cVar10;
  char local_30;
  
  puVar4 = *(undefined8 **)(param_2 + 0xf0);
  uVar5 = *(undefined8 *)(puVar4[3] + 0x24);
  uVar6 = *(undefined8 *)(puVar4[3] + 0x1c);
  bVar9 = (byte)((ulonglong)uVar5 >> 0x20);
  if (bVar9 < 8) {
    bVar1 = *(byte *)(param_1 + 0x958 + (ulonglong)bVar9 * 0x28);
    if ((bVar1 != 0xff) && (*(char *)(param_1 + 0x959 + (ulonglong)bVar9 * 0x28) == '\0')) {
      if (*(char *)(param_2 + 0xec9) != '\0') {
        uVar2 = *(undefined1 *)((longlong)puVar4 + 6);
        *(byte *)(param_2 + 0xecb) = bVar9;
        *(undefined1 *)(param_2 + 0xeca) = uVar2;
        *(byte *)((longlong)puVar4 + 6) = bVar9;
      }
      if ((((char)((ulonglong)uVar6 >> 0x38) != 'O') || (local_30 = (char)uVar5, local_30 != -0x3e))
         || ((cVar10 = (char)((ulonglong)uVar5 >> 0x10), cVar10 != -0x50 && (cVar10 != -0x14)))) {
        *(undefined4 *)(param_2 + 0xf8) = 6;
        goto LAB_000150a0;
      }
      uVar3 = *(ushort *)(param_1 + 0xab8 + (ulonglong)bVar1 * 2);
      if (((uVar3 & 1) != 0) && ((uVar3 & 2) == 0)) {
        pvVar8 = StorAllocateSubCmd((ulonglong)uVar3,param_2);
        if (pvVar8 == (void *)0x0) {
          *(undefined4 *)(param_2 + 0xfc) = 2;
          *(undefined1 *)(param_2 + 0x100) = 2;
          return;
        }
        *(undefined4 *)(param_2 + 0x108) = 0;
        *(undefined4 *)(param_2 + 0x104) = 1;
        *(undefined8 *)(param_2 + 0x160) = 0;
        *(undefined4 *)(param_2 + 0x10c) = 1;
        *(undefined4 *)((longlong)pvVar8 + 0xa0) = 0;
        *(longlong *)((longlong)pvVar8 + 0x10) = param_2;
        *(undefined8 *)((longlong)pvVar8 + 0x48) = *puVar4;
        *(undefined8 *)((longlong)pvVar8 + 0x50) = puVar4[1];
        *(undefined8 *)((longlong)pvVar8 + 0x58) = puVar4[2];
        *(undefined8 *)((longlong)pvVar8 + 0x60) = puVar4[3];
        *(undefined8 *)((longlong)pvVar8 + 0x68) = puVar4[4];
        *(undefined8 *)((longlong)pvVar8 + 0x70) = puVar4[5];
        *(undefined8 *)((longlong)pvVar8 + 0x78) = puVar4[6];
        *(undefined8 *)((longlong)pvVar8 + 0x80) = puVar4[7];
        *(undefined8 *)((longlong)pvVar8 + 0x88) = puVar4[8];
        *(undefined8 *)((longlong)pvVar8 + 0x90) = puVar4[9];
        *(undefined8 *)((longlong)pvVar8 + 0x98) = puVar4[10];
        *(byte *)((longlong)pvVar8 + 0x4e) = bVar1;
        *(code **)((longlong)pvVar8 + 0x18) = DispatchSmartCommand;
        if (*(int *)(param_2 + 0xea4) != 0) {
          lVar7 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
          *(void **)(lVar7 + 0x78 + (ulonglong)*(byte *)(lVar7 + 0x278) * 8) = pvVar8;
          *(char *)(lVar7 + 0x278) = *(char *)(lVar7 + 0x278) + '\x01';
        }
        *(undefined4 *)(param_2 + 0xfc) = 0;
        return;
      }
    }
  }
  *(undefined4 *)(param_2 + 0xf8) = 10;
LAB_000150a0:
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return;
}



===== ParseUserRwDeviceData @ 000150bc =====

void ParseUserRwDeviceData(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  short sVar7;
  void *pvVar8;
  
  sVar7 = CONCAT11(*(undefined1 *)(param_3 + 0x4e),*(undefined1 *)(param_3 + 0x4f));
  uVar1 = *(undefined1 *)(param_3 + 0x50);
  uVar2 = *(undefined1 *)(param_3 + 0x51);
  uVar3 = *(undefined1 *)(param_3 + 0x52);
  uVar4 = *(undefined1 *)(param_3 + 0x53);
  if (sVar7 != 0) {
    *(undefined4 *)(param_2 + 0xe98) = 1;
  }
  if ((*(char *)(param_3 + 0x48) == -1) && ((byte)(*(char *)(param_3 + 0x4b) - 8U) < 2)) {
    pvVar8 = StorAllocateSubCmd(param_1,param_2);
    if (pvVar8 == (void *)0x0) {
      *(undefined4 *)(param_2 + 0xfc) = 2;
      *(undefined1 *)(param_2 + 0x100) = 2;
    }
    else {
      *(undefined4 *)((longlong)pvVar8 + 0xa0) = 0;
      *(longlong *)((longlong)pvVar8 + 0x10) = param_2;
      *(code **)((longlong)pvVar8 + 0x18) = DispatchDiskReadWrite;
      if (*(char *)(param_3 + 0x4b) == '\b') {
        *(undefined4 *)((longlong)pvVar8 + 0x54) = 0x40;
      }
      else {
        *(undefined4 *)((longlong)pvVar8 + 0x54) = 0x80;
      }
      *(undefined1 *)((longlong)pvVar8 + 0x90) = 0xff;
      *(undefined1 *)((longlong)pvVar8 + 0x4e) = *(undefined1 *)(param_3 + 0x4d);
      *(undefined4 *)((longlong)pvVar8 + 0x58) = *(undefined4 *)(param_3 + 0x10);
      uVar5 = *(undefined8 *)(param_3 + 0x18);
      *(undefined8 *)((longlong)pvVar8 + 0x30) = 0;
      *(undefined8 *)((longlong)pvVar8 + 0x60) = uVar5;
      *(undefined4 *)((longlong)pvVar8 + 0xa4) = 1;
      *(ulonglong *)((longlong)pvVar8 + 0x40) =
           (ulonglong)CONCAT51(CONCAT41(CONCAT31(CONCAT21(sVar7,uVar1),uVar2),uVar3),uVar4);
      *(undefined4 *)((longlong)pvVar8 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
      if (*(int *)(param_2 + 0xea4) != 0) {
        lVar6 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
        *(void **)(lVar6 + 0x78 + (ulonglong)*(byte *)(lVar6 + 0x278) * 8) = pvVar8;
        *(char *)(lVar6 + 0x278) = *(char *)(lVar6 + 0x278) + '\x01';
      }
      *(undefined4 *)(param_2 + 0x108) = 0;
      *(undefined4 *)(param_2 + 0x104) = 1;
      *(undefined1 **)(param_2 + 0x160) = &DebugCallback;
      *(undefined4 *)(param_2 + 0x10c) = 1;
      *(char **)(param_2 + 0x200) = "Debug Read/Write Device Data Complete";
      *(undefined4 *)(param_2 + 0xfc) = 0;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0xf8) = 4;
    *(undefined4 *)(param_2 + 0xfc) = 1;
  }
  return;
}



===== ParseIoctlIdentify @ 00015254 =====

void ParseIoctlIdentify(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong lVar4;
  void *pvVar5;
  void *_Dst;
  byte bVar6;
  int iVar7;
  
  lVar3 = *(longlong *)(param_2 + 0xf0);
  lVar4 = *(longlong *)(lVar3 + 0x18);
  if ((char)((ulonglong)*(undefined8 *)(lVar4 + 0x24) >> 0x10) == -0x14) {
    bVar6 = (byte)((ulonglong)*(undefined8 *)(lVar4 + 0x24) >> 0x20);
    if (bVar6 < 8) {
      bVar1 = *(byte *)(param_1 + 0x958 + (ulonglong)bVar6 * 0x28);
      if (((bVar1 != 0xff) && (*(char *)(param_1 + 0x959 + (ulonglong)bVar6 * 0x28) == '\0')) &&
         ((*(byte *)(param_1 + 0xab8 + (ulonglong)bVar1 * 2) & 1) != 0)) {
        if (*(char *)(param_2 + 0xec9) != '\0') {
          uVar2 = *(undefined1 *)(lVar3 + 6);
          *(byte *)(param_2 + 0xecb) = bVar6;
          *(undefined1 *)(param_2 + 0xeca) = uVar2;
          *(byte *)(lVar3 + 6) = bVar6;
        }
        pvVar5 = (void *)0x210;
        if ((ulonglong)*(uint *)(lVar3 + 0x10) - 0x1c < 0x210) {
          pvVar5 = (void *)(ulonglong)(*(uint *)(lVar3 + 0x10) - 0x1c);
        }
        iVar7 = (int)pvVar5 + -0x10;
        _Dst = pvVar5;
        if ((int)pvVar5 != 0) {
          _Dst = (void *)(lVar4 + 0x1c);
          memset(_Dst,0,(size_t)pvVar5);
        }
        *(int *)(lVar4 + 0x1c) = iVar7;
        *(undefined2 *)(lVar4 + 0x20) = 0;
        pvVar5 = StorAllocateSubCmd(_Dst,param_2);
        if (pvVar5 == (void *)0x0) {
          *(undefined4 *)(param_2 + 0xfc) = 2;
          *(undefined1 *)(param_2 + 0x100) = 2;
          return;
        }
        *(undefined4 *)((longlong)pvVar5 + 0xa0) = 0;
        *(longlong *)((longlong)pvVar5 + 0x10) = param_2;
        *(byte *)((longlong)pvVar5 + 0x4e) = bVar1;
        *(int *)((longlong)pvVar5 + 0x58) = iVar7;
        *(longlong *)((longlong)pvVar5 + 0x60) = lVar4 + 0x2c;
        *(byte *)((longlong)pvVar5 + 0x90) =
             (-(*(int *)((ulonglong)bVar1 * 0xb8 + 0x394 + param_1) != 0) & 0xb5U) - 0x14;
        *(code **)((longlong)pvVar5 + 0x18) = DispatchIoctlIdentify;
        *(undefined4 *)(param_2 + 0x108) = 0;
        *(undefined4 *)(param_2 + 0x104) = 1;
        *(undefined4 *)(param_2 + 0x10c) = 1;
        if (*(int *)(param_2 + 0xea4) != 0) {
          lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
          *(void **)(lVar3 + 0x78 + (ulonglong)*(byte *)(lVar3 + 0x278) * 8) = pvVar5;
          *(char *)(lVar3 + 0x278) = *(char *)(lVar3 + 0x278) + '\x01';
        }
        *(undefined4 *)(param_2 + 0xf8) = 0;
        *(undefined4 *)(param_2 + 0xfc) = 0;
        return;
      }
    }
    *(undefined4 *)(param_2 + 0xf8) = 10;
  }
  else {
    *(undefined4 *)(param_2 + 0xf8) = 6;
  }
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return;
}



===== ParseIoctlSerialNumber @ 0001542c =====

void ParseIoctlSerialNumber(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  size_t _Size;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x18);
  if ((char)(*(ulonglong *)(lVar3 + 0x24) >> 0x10) == -0x14) {
    uVar5 = *(ulonglong *)(lVar3 + 0x24) >> 0x20 & 0xff;
    bVar1 = *(byte *)(param_1 + 0x958 + uVar5 * 0x28);
    if (((bVar1 == 0xff) || (*(char *)(param_1 + 0x959 + uVar5 * 0x28) != '\0')) ||
       ((*(byte *)(param_1 + 0xab8 + (ulonglong)bVar1 * 2) & 1) == 0)) {
      *(undefined4 *)(param_2 + 0xf8) = 10;
    }
    else {
      uVar2 = *(uint *)(*(longlong *)(param_2 + 0xf0) + 0x10);
      _Size = 0x24;
      if ((ulonglong)uVar2 - 0x1c < 0x24) {
        _Size = (size_t)(uVar2 - 0x1c);
      }
      if ((int)_Size != 0) {
        memset((void *)(lVar3 + 0x1c),0,_Size);
      }
      *(int *)(lVar3 + 0x1c) = (int)_Size + -0x10;
      *(undefined2 *)(lVar3 + 0x20) = 0;
      lVar4 = uVar5 * 0x68;
      *(undefined8 *)(lVar3 + 0x2c) = *(undefined8 *)(lVar4 + 0x3e60 + param_1);
      *(undefined8 *)(lVar3 + 0x34) = *(undefined8 *)(lVar4 + 0x3e68 + param_1);
      *(undefined4 *)(lVar3 + 0x3c) = *(undefined4 *)(lVar4 + 0x3e70 + param_1);
      *(undefined4 *)(param_2 + 0xf8) = 1;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0xf8) = 6;
  }
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return;
}



===== AddListEntryToTail @ 0001555c =====

void AddListEntryToTail(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  if ((param_2 != (longlong *)0x0) && (param_1 != (longlong *)0x0)) {
    lVar1 = *param_1;
    if (lVar1 == 0) {
      param_2[1] = (longlong)param_2;
      *param_2 = (longlong)param_2;
      *param_1 = (longlong)param_2;
      return;
    }
    puVar2 = *(undefined8 **)(lVar1 + 8);
    *(longlong **)(lVar1 + 8) = param_2;
    *puVar2 = param_2;
    param_2[1] = (longlong)puVar2;
    *param_2 = lVar1;
  }
  return;
}



===== RemoveListEntry @ 0001558c =====

ulonglong RemoveListEntry(longlong *param_1,longlong *param_2)

{
  ulonglong in_RAX;
  longlong *plVar1;
  
  if (((param_2 == (longlong *)0x0) || (param_1 == (longlong *)0x0)) ||
     (plVar1 = (longlong *)*param_1, in_RAX = 0, plVar1 == (longlong *)0x0)) {
    return in_RAX & 0xffffffffffffff00;
  }
  if ((longlong *)*plVar1 == plVar1) {
    *param_1 = 0;
  }
  else {
    if (param_2 == plVar1) {
      *param_1 = *plVar1;
    }
    *(longlong *)param_2[1] = *param_2;
    plVar1 = (longlong *)param_2[1];
    *(longlong **)(*param_2 + 8) = plVar1;
  }
  return CONCAT71((int7)((ulonglong)plVar1 >> 8),1);
}



===== AtaModeSense @ 000155d0 =====

undefined8 AtaModeSense(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined8 in_RAX;
  ulonglong uVar4;
  undefined1 uVar5;
  
  uVar1 = *(uint *)(param_2 + 0x10);
  uVar4 = CONCAT71((int7)((ulonglong)in_RAX >> 8),*(undefined1 *)(param_2 + 0x4a)) &
          0xffffffffffffff3f;
  cVar3 = (char)uVar4;
  if ((cVar3 == '\b') || (cVar3 == '?')) {
    if (uVar1 < 4) {
LAB_0001563a:
      return CONCAT71((int7)(uVar4 >> 8),4);
    }
    puVar2 = *(undefined4 **)(param_2 + 0x18);
    uVar4 = (ulonglong)(uVar1 - 4);
    *puVar2 = 0x100000;
    if (uVar1 - 4 < 0xc) {
      *(undefined4 *)(param_2 + 0x10) = 4;
    }
    else {
      *(undefined1 *)puVar2 = 0xf;
      *(undefined2 *)(puVar2 + 1) = 0xa08;
      *(undefined1 *)((longlong)puVar2 + 6) = 0;
      *(undefined1 *)((longlong)puVar2 + 7) = 0;
      *(undefined1 *)(puVar2 + 2) = 0;
      *(undefined1 *)((longlong)puVar2 + 9) = 0;
      *(undefined1 *)((longlong)puVar2 + 10) = 0;
      *(undefined1 *)((longlong)puVar2 + 0xb) = 0;
      *(undefined1 *)(puVar2 + 3) = 0;
      *(undefined1 *)((longlong)puVar2 + 0xd) = 0;
      *(undefined1 *)((longlong)puVar2 + 0xe) = 0;
      *(undefined1 *)((longlong)puVar2 + 0xf) = 0;
      *(undefined4 *)(param_2 + 0x10) = 0x10;
    }
    uVar5 = 1;
  }
  else if (cVar3 == '\0') {
    if (uVar1 < 4) goto LAB_0001563a;
    puVar2 = *(undefined4 **)(param_2 + 0x18);
    uVar4 = (ulonglong)(uVar1 - 4);
    uVar5 = 1;
    *puVar2 = 0x100000;
    if (uVar1 - 4 < 8) {
      *(undefined4 *)(param_2 + 0x10) = 4;
    }
    else {
      *(undefined4 *)((longlong)puVar2 + 3) = 8;
      *(undefined2 *)((longlong)puVar2 + 7) = 0;
      *(undefined1 *)((longlong)puVar2 + 9) = 0;
      *(undefined1 *)((longlong)puVar2 + 10) = 1;
      *(undefined1 *)((longlong)puVar2 + 0xb) = 0;
      *(undefined4 *)(param_2 + 0x10) = 0xc;
    }
  }
  else {
    uVar5 = 6;
  }
  return CONCAT71((int7)(uVar4 >> 8),uVar5);
}



===== ParseIdeCmd @ 00015694 =====

undefined1 ParseIdeCmd(ulonglong *param_1,ulonglong param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  code *pcVar7;
  undefined8 *puVar8;
  undefined1 uVar9;
  undefined1 *puVar10;
  
  puVar8 = *(undefined8 **)(param_2 + 0xf0);
  uVar6 = 6;
  bVar2 = *(byte *)(puVar8 + 9);
  if (bVar2 < 0x30) {
    if (bVar2 == 0x2f) goto LAB_0001596d;
    uVar9 = 0;
    if (bVar2 == 0) {
      if ((*(byte *)((longlong)param_1 +
                    (ulonglong)(byte)param_1[(ulonglong)*(byte *)((longlong)puVar8 + 6) * 5 + 299] *
                    2 + 0xab8) & 0x20) == 0) {
        *(undefined4 *)(param_2 + 0xfc) = 1;
        *(undefined4 *)(param_2 + 0xf8) = 1;
        return 1;
      }
      pcVar7 = DispatchIdeTestUnitReady;
      if ((*(byte *)((ulonglong)(byte)param_1[(ulonglong)*(byte *)((longlong)puVar8 + 6) * 5 + 299]
                     + 0x948 + (longlong)param_1) & 4) != 0) {
        pcVar7 = AhciDispatchIdeTestUnitReady;
      }
      bVar2 = ParseIdeSimpleCmd((longlong)param_1,param_2,pcVar7);
    }
    else {
      if (bVar2 == 3) {
        pbVar1 = (byte *)puVar8[3];
        if (*(uint *)(puVar8 + 2) < 4) {
          uVar6 = 4;
          goto LAB_00015985;
        }
        pbVar1[7] = 0;
        pbVar1[0xc] = 0;
        pbVar1[0xd] = 0;
        pbVar1[2] = pbVar1[2] & 0xf0;
        *pbVar1 = *pbVar1 & 0xf0 | 0x70;
        *(undefined4 *)(param_2 + 0xfc) = 1;
        *(undefined4 *)(param_2 + 0xf8) = 1;
        *(undefined1 *)((longlong)puVar8 + 4) = 0;
        goto LAB_00015819;
      }
      if (bVar2 == 0x12) {
        uVar5 = Inquiry((longlong)param_1,param_2);
        bVar2 = (byte)uVar5;
      }
      else {
        if (bVar2 == 0x1a) {
          uVar4 = AtaModeSense(param_1,(longlong)puVar8);
          uVar6 = uVar4 & 0xff;
          *(char *)((longlong)puVar8 + 3) = (char)uVar4;
          if ((char)uVar4 == '\x01') {
            *(undefined1 *)((longlong)puVar8 + 4) = uVar9;
          }
          else {
            *(undefined1 *)((longlong)puVar8 + 4) = 2;
          }
          *(undefined4 *)(param_2 + 0xfc) = 1;
          *(int *)(param_2 + 0xf8) = (int)uVar6;
          goto LAB_00015985;
        }
        if (bVar2 != 0x1b) {
          if (bVar2 == 0x25) {
            *(undefined4 *)(puVar8[3] + 4) = 0x20000;
            uVar3 = GetLogicTargetCapacity
                              ((longlong)param_1,
                               CONCAT71((int7)(param_2 >> 8),
                                        *(undefined1 *)(*(longlong *)(param_2 + 0xf0) + 6)));
            *(uint *)puVar8[3] =
                 ((uVar3 >> 8 & 0xff | (uVar3 & 0xff) << 8) << 8 | uVar3 >> 0x10 & 0xff) << 8 |
                 uVar3 >> 0x18;
            goto LAB_0001576f;
          }
          if ((bVar2 != 0x28) && (bVar2 != 0x2a)) goto LAB_000158ae;
          goto LAB_0001596d;
        }
        uVar3 = ParseStartStopUnit(param_1,param_2);
        bVar2 = (byte)uVar3;
      }
    }
  }
  else {
    if (bVar2 == 0x35) {
      ParseFlushCacheToHDD((longlong)param_1,param_2,'\0');
      goto LAB_00015985;
    }
    if (((bVar2 != 0x88) && (bVar2 != 0x8a)) && (bVar2 != 0x8f)) {
      if (bVar2 == 0x9e) {
        puVar10 = (undefined1 *)puVar8[3];
        *(undefined4 *)(param_2 + 0xe98) = 1;
        *(undefined4 *)(puVar8[3] + 8) = 0x20000;
        uVar5 = GetLogicTargetCapacity64
                          ((longlong)param_1,*(byte *)(*(longlong *)(param_2 + 0xf0) + 6));
        puVar10[7] = (char)uVar5;
        *puVar10 = (char)((ulonglong)uVar5 >> 0x38);
        puVar10[1] = (char)((ulonglong)uVar5 >> 0x30);
        puVar10[2] = (char)((ulonglong)uVar5 >> 0x28);
        puVar10[3] = (char)((ulonglong)uVar5 >> 0x20);
        puVar10[5] = (char)((ulonglong)uVar5 >> 0x10);
        puVar10[4] = (char)((ulonglong)uVar5 >> 0x18);
        puVar10[6] = (char)((ulonglong)uVar5 >> 8);
      }
      else {
        if (bVar2 != 0xa0) {
          if (bVar2 == 0xff) {
            ParseUserCommand(param_1,param_2,puVar8);
            return *(undefined1 *)(param_2 + 0xf8);
          }
LAB_000158ae:
          *(undefined4 *)(param_2 + 0xfc) = 1;
          *(undefined4 *)(param_2 + 0xf8) = 6;
          goto LAB_00015985;
        }
        *(undefined1 *)(puVar8[3] + 3) = 8;
      }
LAB_0001576f:
      *(undefined4 *)(param_2 + 0xfc) = 1;
      *(undefined4 *)(param_2 + 0xf8) = 1;
LAB_00015819:
      uVar6 = 1;
      goto LAB_00015985;
    }
    *(undefined4 *)(param_2 + 0xe98) = 1;
LAB_0001596d:
    uVar6 = ParseIdeReadWrite(param_1,param_2);
    bVar2 = (byte)uVar6;
  }
  uVar6 = (ulonglong)bVar2;
LAB_00015985:
  return (char)uVar6;
}



===== StartAutoChkTimer @ 00015994 =====

void StartAutoChkTimer(longlong param_1)

{
  if ((*(char *)(param_1 + 0x9c) == '\0') && (*(char *)(param_1 + 0x14b6) == '\0')) {
    StorPortNotification(6,param_1,AtapiScsiTimer,10000000,0xffffffff);
    *(undefined1 *)(param_1 + 0x9c) = 1;
  }
  return;
}



===== ResumePowerInStartIo @ 000159dc =====

void ResumePowerInStartIo(longlong param_1,longlong param_2,undefined8 param_3)

{
  bool bVar1;
  ulonglong uVar2;
  char *pcVar3;
  uint uVar4;
  undefined8 uVar5;
  byte *pbVar6;
  
  uVar5 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
  bVar1 = StorLockCtrlrSrv(param_1,param_2,'\x01');
  if (bVar1) {
    if (*(char *)(param_1 + 0x62) != '\0') {
      RestartAdapter(param_1);
    }
    uVar4 = 0;
    pcVar3 = (char *)(param_1 + 0x399);
    pbVar6 = (byte *)(param_1 + 0xab8);
    do {
      if (((*pbVar6 & 1) != 0) && (*pcVar3 == '\0')) {
        uVar2 = IsDevReady(param_1,uVar4,uVar5);
        if ((char)uVar2 == '\0') {
          *(undefined4 *)(param_2 + 0xfc) = 1;
          *(undefined4 *)(param_2 + 0xf8) = 5;
          goto LAB_00015a69;
        }
      }
      uVar4 = uVar4 + 1;
      pbVar6 = pbVar6 + 2;
      pcVar3 = pcVar3 + 0xb8;
    } while (uVar4 < 8);
    SetAllFeature(param_1,-1,uVar5);
    if (*(char *)(param_1 + 0x62) == '\0') {
      *(undefined1 *)(param_1 + 0x61) = 0;
    }
LAB_00015a69:
    StorLockCtrlrSrv(param_1,param_2,'\0');
  }
  else {
    *(undefined4 *)(param_2 + 0xfc) = 2;
    *(undefined1 *)(param_2 + 0x100) = 1;
  }
  return;
}



===== PreParseLogicCmd @ 00015abc =====

ulonglong PreParseLogicCmd(longlong param_1,longlong param_2,undefined8 param_3)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  longlong lVar4;
  undefined7 extraout_var;
  ulonglong uVar5;
  uint7 extraout_var_00;
  ushort *puVar6;
  
  if (*(char *)(param_1 + 0x9c) == '\0') {
    StartAutoChkTimer(param_1);
  }
  if (*(char *)(param_1 + 0x61) != '\0') {
    ResumePowerInStartIo(param_1,param_2,param_3);
    uVar3 = *(int *)(param_2 + 0xfc) - 1;
    uVar5 = (ulonglong)uVar3;
    if (uVar3 < 2) {
LAB_00015af8:
      return uVar5 & 0xffffffffffffff00;
    }
  }
  uVar3 = 0;
  puVar6 = (ushort *)(param_1 + 0xab8);
  lVar4 = 0;
  do {
    if (3 < *(byte *)(lVar4 + 0x39a + param_1)) {
      uVar1 = *puVar6;
      if ((uVar1 & 1) == 0) {
        *(undefined1 *)(lVar4 + 0x39a + param_1) = 0;
      }
      else if ((uVar1 & 0x8000) == 0) {
        lVar4 = CONCAT71((uint7)(byte)(uVar1 >> 8),1);
        bVar2 = StorLockCtrlrSrv(param_1,param_2,'\x01');
        uVar5 = CONCAT71(extraout_var,bVar2);
        if (!bVar2) {
          *(undefined4 *)(param_2 + 0xfc) = 2;
          *(undefined1 *)(param_2 + 0x100) = 1;
          goto LAB_00015af8;
        }
        CheckController(param_1,'\0',lVar4);
        StorLockCtrlrSrv(param_1,param_2,'\0');
        lVar4 = (ulonglong)extraout_var_00 << 8;
        break;
      }
    }
    uVar3 = uVar3 + 1;
    puVar6 = puVar6 + 1;
    lVar4 = lVar4 + 0xb8;
  } while (uVar3 < 8);
  return CONCAT71((int7)((ulonglong)lVar4 >> 8),1);
}



===== ParseFlushCacheToHDD @ 00015b94 =====

void ParseFlushCacheToHDD(longlong param_1,longlong param_2,char param_3)

{
  int *piVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  void *_Dst;
  longlong lVar8;
  int iVar9;
  
  puVar5 = *(undefined8 **)(param_2 + 0xf0);
  bVar2 = *(byte *)((longlong)puVar5 + 6);
  iVar9 = 0;
  do {
    lVar8 = (longlong)iVar9;
    uVar3 = *(ushort *)(param_1 + 0xab8 + lVar8 * 2);
    if ((((uVar3 & 1) != 0) && ((uVar3 & 2) == 0)) &&
       (lVar6 = lVar8 * 0xb8, *(char *)(lVar6 + 0x399 + param_1) == '\0')) {
      if (param_3 == '\0') {
        lVar8 = ((ulonglong)bVar2 * 5 + 299) * 8 + param_1;
        uVar7 = CheckDeviceCheckSum(lVar8,(int *)(param_1 + 0x388 + lVar6));
        if ((char)uVar7 == '\0') goto LAB_00015d0c;
      }
      _Dst = StorAllocateSubCmd(lVar8,param_2);
      if (_Dst == (void *)0x0) {
        *(undefined4 *)(param_2 + 0xfc) = 2;
        *(undefined1 *)(param_2 + 0x100) = 2;
        return;
      }
      memset(_Dst,0,0xc0);
      if ((undefined8 *)((longlong)_Dst + 0x48) != puVar5) {
        *(undefined8 *)((longlong)_Dst + 0x48) = *puVar5;
        *(undefined8 *)((longlong)_Dst + 0x50) = puVar5[1];
        *(undefined8 *)((longlong)_Dst + 0x58) = puVar5[2];
        *(undefined8 *)((longlong)_Dst + 0x60) = puVar5[3];
        *(undefined8 *)((longlong)_Dst + 0x68) = puVar5[4];
        *(undefined8 *)((longlong)_Dst + 0x70) = puVar5[5];
        *(undefined8 *)((longlong)_Dst + 0x78) = puVar5[6];
        *(undefined8 *)((longlong)_Dst + 0x80) = puVar5[7];
        *(undefined8 *)((longlong)_Dst + 0x88) = puVar5[8];
        *(undefined8 *)((longlong)_Dst + 0x90) = puVar5[9];
        *(undefined8 *)((longlong)_Dst + 0x98) = puVar5[10];
      }
      *(undefined4 *)((longlong)_Dst + 0x54) = 1;
      *(char *)((longlong)_Dst + 0x4e) = (char)iVar9;
      uVar4 = *(undefined4 *)(param_2 + 0x104);
      *(undefined8 *)((longlong)_Dst + 0x30) = 0;
      *(undefined4 *)((longlong)_Dst + 0xa0) = uVar4;
      *(longlong *)((longlong)_Dst + 0x10) = param_2;
      *(code **)((longlong)_Dst + 0x18) = DispatchSyncCache;
      piVar1 = (int *)(param_2 + 0x10c + (longlong)*(int *)(param_2 + 0x104) * 4);
      *piVar1 = *piVar1 + 1;
      if (*(int *)(param_2 + 0xea4) != 0) {
        lVar8 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
        *(void **)(lVar8 + 0x78 + (ulonglong)*(byte *)(lVar8 + 0x278) * 8) = _Dst;
        *(char *)(lVar8 + 0x278) = *(char *)(lVar8 + 0x278) + '\x01';
      }
    }
LAB_00015d0c:
    iVar9 = iVar9 + 1;
    if (7 < iVar9) {
      *(undefined4 *)(param_2 + 0x108) = 0;
      *(int *)(param_2 + 0x104) = *(int *)(param_2 + 0x104) + 1;
      *(undefined4 *)(param_2 + 0xf8) = 0;
      *(undefined4 *)(param_2 + 0xfc) = 0;
      return;
    }
  } while( true );
}



===== ParseSrbFunctionPower @ 00015d64 =====

void ParseSrbFunctionPower(longlong param_1,longlong param_2)

{
  int *piVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  void *_Dst;
  longlong lVar5;
  int iVar6;
  
  puVar4 = *(undefined8 **)(param_2 + 0xf0);
  iVar6 = 0;
  do {
    lVar5 = (longlong)iVar6;
    uVar2 = *(ushort *)(param_1 + 0xab8 + lVar5 * 2);
    if ((((uVar2 & 1) != 0) && ((uVar2 & 2) == 0)) &&
       (*(char *)(lVar5 * 0xb8 + 0x399 + param_1) == '\0')) {
      _Dst = StorAllocateSubCmd(lVar5,param_2);
      if (_Dst == (void *)0x0) {
        *(undefined4 *)(param_2 + 0xfc) = 2;
        *(undefined1 *)(param_2 + 0x100) = 2;
        return;
      }
      memset(_Dst,0,0xc0);
      if ((undefined8 *)((longlong)_Dst + 0x48) != puVar4) {
        *(undefined8 *)((longlong)_Dst + 0x48) = *puVar4;
        *(undefined8 *)((longlong)_Dst + 0x50) = puVar4[1];
        *(undefined8 *)((longlong)_Dst + 0x58) = puVar4[2];
        *(undefined8 *)((longlong)_Dst + 0x60) = puVar4[3];
        *(undefined8 *)((longlong)_Dst + 0x68) = puVar4[4];
        *(undefined8 *)((longlong)_Dst + 0x70) = puVar4[5];
        *(undefined8 *)((longlong)_Dst + 0x78) = puVar4[6];
        *(undefined8 *)((longlong)_Dst + 0x80) = puVar4[7];
        *(undefined8 *)((longlong)_Dst + 0x88) = puVar4[8];
        *(undefined8 *)((longlong)_Dst + 0x90) = puVar4[9];
        *(undefined8 *)((longlong)_Dst + 0x98) = puVar4[10];
      }
      *(undefined4 *)((longlong)_Dst + 0x54) = 1;
      *(char *)((longlong)_Dst + 0x4e) = (char)iVar6;
      *(undefined1 *)((longlong)_Dst + 0x4c) = 0;
      uVar3 = *(undefined4 *)(param_2 + 0x104);
      *(undefined8 *)((longlong)_Dst + 0x30) = 0;
      *(longlong *)((longlong)_Dst + 0x10) = param_2;
      *(undefined4 *)((longlong)_Dst + 0xa0) = uVar3;
      *(code **)((longlong)_Dst + 0x18) = DispatchSyncCache;
      piVar1 = (int *)(param_2 + 0x10c + (longlong)*(int *)(param_2 + 0x104) * 4);
      *piVar1 = *piVar1 + 1;
      if (*(int *)(param_2 + 0xea4) != 0) {
        lVar5 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
        *(void **)(lVar5 + 0x78 + (ulonglong)*(byte *)(lVar5 + 0x278) * 8) = _Dst;
        *(char *)(lVar5 + 0x278) = *(char *)(lVar5 + 0x278) + '\x01';
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  *(undefined4 *)(param_2 + 0x108) = 0;
  *(int *)(param_2 + 0x104) = *(int *)(param_2 + 0x104) + 1;
  *(undefined4 *)(param_2 + 0xf8) = 0;
  *(undefined4 *)(param_2 + 0xfc) = 0;
  if (*(char *)(param_2 + 0xec9) != '\0') {
    SetRealLogicTarget(param_1,param_2);
  }
  return;
}



===== ParseLogicCmd @ 00015f0c =====

void ParseLogicCmd(ulonglong *param_1,ulonglong param_2)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 uVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong *puVar10;
  uint uVar11;
  ulonglong *puVar12;
  longlong lVar13;
  
  lVar5 = *(longlong *)(param_2 + 0xf0);
  if (*(char *)((longlong)param_1 + 0x9c) == '\0') {
    StartAutoChkTimer((longlong)param_1);
  }
  lVar13 = *(longlong *)(param_2 + 0xf0);
  bVar2 = (byte)param_1[(ulonglong)*(byte *)(lVar13 + 6) * 5 + 299];
  *(undefined2 *)(param_2 + 0xeb1) = 0xff00;
  *(undefined1 *)(param_2 + 0xec9) = 0;
  if (lVar13 == 0) {
LAB_0001625f:
    *(undefined4 *)(param_2 + 0xf8) = 6;
  }
  else {
    bVar3 = *(byte *)(lVar13 + 2);
    if (bVar3 == 2) {
      lVar6 = *(longlong *)(lVar13 + 0x18);
      iVar8 = AtapiStringCmp(lVar6 + 4,(byte *)"SCSIDISK",8);
      if (iVar8 != 0) goto LAB_0001625f;
      if (*(int *)(lVar6 + 0x10) != 0x1b0800) goto LAB_00015fe6;
      *(undefined1 *)(param_2 + 0xeb1) = 1;
      lVar13 = *(longlong *)(lVar13 + 0x18);
      bVar3 = *(byte *)(lVar13 + 0x23);
      if (bVar3 < 10) {
LAB_00015fdb:
        uVar7 = *(undefined1 *)(lVar13 + 0x25);
      }
      else if (bVar3 < 0xc) {
        uVar7 = *(undefined1 *)(lVar13 + 0x45);
      }
      else {
        if (2 < (byte)(bVar3 - 0x17)) goto LAB_00015fdb;
        uVar7 = *(undefined1 *)(lVar13 + 0x24);
      }
      *(undefined1 *)(param_2 + 0xeb2) = uVar7;
    }
    else if ((bVar3 < 0x25) && ((0x1000050180U >> ((ulonglong)bVar3 & 0x3f) & 1) != 0)) {
LAB_00015fe6:
      *(undefined1 *)(param_2 + 0xec9) = 1;
    }
    else if ((bVar3 != 0) || (7 < (byte)param_1[(ulonglong)*(byte *)(lVar13 + 6) * 5 + 299]))
    goto LAB_0001625f;
    if ((bVar2 < 8) && (*(char *)(param_2 + 0xec9) == '\0')) {
      if ((*(char *)(param_2 + 0xeb1) == '\0') &&
         ((*(byte *)((longlong)param_1 + (ulonglong)bVar2 * 2 + 0xab8) & 4) != 0)) {
        puVar1 = (uint *)((ulonglong)bVar2 * 0xb8 + 0x39c + (longlong)param_1);
        *puVar1 = *puVar1 & 0xfffffff3;
      }
      if (((((*(char *)(param_2 + 0xec9) != '\0') || (*(char *)(param_2 + 0xeb1) != '\0')) ||
           (*(int *)((ulonglong)bVar2 * 0xb8 + 0x38c + (longlong)param_1) == 0)) ||
          ((char)param_1[(ulonglong)bVar2 * 0x17 + 0x72] == '\0')) ||
         ((*(char *)(lVar5 + 2) == '\0' && (*(char *)(lVar5 + 0x48) == '\x12')))) goto LAB_000160a1;
    }
    else {
LAB_000160a1:
      if ((*(int *)((longlong)param_1 + (ulonglong)(bVar2 & 0xf) * 4 + 0xae0) == 4) &&
         ((*(char *)(lVar5 + 0x48) != '\x1b' && (bVar2 != 0xff)))) {
        uVar11 = 0;
        lVar13 = 0;
        puVar10 = param_1 + 0x157;
        puVar12 = param_1 + 0x15c;
        do {
          if (((*puVar10 & 1) != 0) &&
             (uVar9 = CheckDeviceCheckSum((longlong)
                                          (param_1 + (ulonglong)*(byte *)(lVar5 + 6) * 5 + 299),
                                          (int *)(param_1 + (ulonglong)uVar11 * 0x17 + 0x71)),
             (char)uVar9 != '\0')) {
            if ((*(byte *)(lVar13 + 0x948 + (longlong)param_1) & 4) == 0) {
              CommReset((longlong)param_1,uVar11);
            }
            else {
              AhciResetPort((longlong)param_1,uVar11 >> 1,'\0');
            }
            *(undefined4 *)puVar12 = 0;
          }
          uVar11 = uVar11 + 1;
          lVar13 = lVar13 + 1;
          puVar10 = (ulonglong *)((longlong)puVar10 + 2);
          puVar12 = (ulonglong *)((longlong)puVar12 + 4);
        } while (uVar11 < 8);
      }
      cVar4 = *(char *)(lVar5 + 2);
      if (cVar4 != '\0') {
        if (cVar4 == '\x02') {
          ParseScsiMiniportIoctl(param_1,param_2);
          return;
        }
        if (cVar4 == '\a') {
          SaveConfigSpace((longlong)param_1);
          RfParseLcmdShutdown((longlong)param_1,param_2);
          return;
        }
        if (cVar4 != '\b') {
          if ((cVar4 == '\x10') || (cVar4 == '\x12')) {
            *(undefined1 *)(param_2 + 0xeb0) = 1;
            param_1[0x8fd] = param_2;
            if (*(char *)(param_2 + 0xec9) != '\0') {
              SetRealLogicTarget((longlong)param_1,param_2);
            }
            *(undefined1 *)(param_2 + 0xebc) = 1;
            *(undefined8 *)(param_2 + 0xf8) = 0;
            return;
          }
          if (cVar4 != '$') goto LAB_0001625f;
          if ((*(int *)(lVar5 + 8) == 4) && (*(int *)(lVar5 + 0x40) - 2U < 5)) {
            SaveConfigSpace((longlong)param_1);
            ParseSrbFunctionPower((longlong)param_1,param_2);
            *(undefined1 *)(param_2 + 0xec8) = 1;
            return;
          }
          if (*(int *)(lVar5 + 8) != 1) {
            return;
          }
        }
        *(undefined4 *)(param_2 + 0xf8) = 1;
        goto LAB_00016269;
      }
      if (bVar2 < 8) {
        if ((*(byte *)((longlong)param_1 + (ulonglong)bVar2 * 2 + 0xab8) & 2) == 0) {
          ParseIdeCmd(param_1,param_2);
          return;
        }
        ParseAtapiCmd(param_1,param_2);
        return;
      }
    }
    *(undefined4 *)(param_2 + 0xf8) = 8;
  }
LAB_00016269:
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return;
}



===== ParseAtapiCmd @ 0001628c =====

undefined1 ParseAtapiCmd(undefined8 *param_1,ulonglong param_2)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  void *pvVar7;
  void *pvVar8;
  longlong lVar9;
  ulonglong uVar10;
  bool bVar11;
  bool bVar12;
  longlong local_res10;
  
  puVar5 = *(undefined8 **)(param_2 + 0xf0);
  pvVar8 = (void *)0x0;
  if (*(char *)(puVar5 + 9) == -1) {
    ParseUserCommand(param_1,param_2,puVar5);
    return *(undefined1 *)(param_2 + 0xf8);
  }
  if (*(char *)(puVar5 + 9) == -0x67) {
    *(undefined4 *)(param_2 + 0xfc) = 1;
    *(undefined4 *)(param_2 + 0xf8) = 1;
    return 1;
  }
  lVar9 = (ulonglong)*(byte *)((longlong)puVar5 + 6) * 5;
  if (*(char *)((ulonglong)*(byte *)(param_1 + (ulonglong)*(byte *)((longlong)puVar5 + 6) * 5 + 299)
                + 0x4874 + (longlong)param_1) != '\0') {
    *(undefined4 *)(param_2 + 0xfc) = 1;
    *(undefined4 *)(param_2 + 0xf8) = 4;
    return 4;
  }
  bVar11 = (*(byte *)((longlong)puVar5 + 0xc) & 0x20) == 0;
  local_res10 = 0;
  if (((puVar5[7] != 0) && (*(int *)(puVar5[7] + 0x27c) == 0)) &&
     (*(char *)(param_2 + 0xee0) == '\0')) {
    bVar12 = Hibernate == '\0';
    *(undefined1 *)(param_2 + 0xee0) = 1;
    if (bVar12) {
      StorPortNotification(0xf,param_1,&local_res10);
      if ((local_res10 == 0) || (*(code **)(local_res10 + 0x30) == (code *)0x0)) {
        lVar9 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x18);
        *(longlong *)(param_2 + 0xed8) = lVar9;
      }
      else {
        lVar9 = *(longlong *)(param_2 + 0xf0);
        uVar6 = (**(code **)(local_res10 + 0x30))();
        *(undefined8 *)(param_2 + 0xed8) = uVar6;
      }
    }
    else {
      *(undefined8 *)(param_2 + 0xed8) = puVar5[3];
    }
  }
  pvVar7 = StorAllocateSubCmd(lVar9,param_2);
  if (pvVar7 == (void *)0x0) {
LAB_000163c1:
    *(undefined4 *)(param_2 + 0xfc) = 2;
    *(undefined1 *)(param_2 + 0x100) = 2;
    return 4;
  }
  if ((undefined8 *)((longlong)pvVar7 + 0x48) != puVar5) {
    *(undefined8 *)((longlong)pvVar7 + 0x48) = *puVar5;
    *(undefined8 *)((longlong)pvVar7 + 0x50) = puVar5[1];
    *(undefined8 *)((longlong)pvVar7 + 0x58) = puVar5[2];
    *(undefined8 *)((longlong)pvVar7 + 0x60) = puVar5[3];
    *(undefined8 *)((longlong)pvVar7 + 0x68) = puVar5[4];
    *(undefined8 *)((longlong)pvVar7 + 0x70) = puVar5[5];
    *(undefined8 *)((longlong)pvVar7 + 0x78) = puVar5[6];
    *(undefined8 *)((longlong)pvVar7 + 0x80) = puVar5[7];
    *(undefined8 *)((longlong)pvVar7 + 0x88) = puVar5[8];
    *(undefined8 *)((longlong)pvVar7 + 0x90) = puVar5[9];
    *(undefined8 *)((longlong)pvVar7 + 0x98) = puVar5[10];
  }
  uVar10 = (ulonglong)
           *(byte *)(param_1 + (ulonglong)*(byte *)(*(longlong *)(param_2 + 0xf0) + 6) * 5 + 299);
  *(byte *)((longlong)pvVar7 + 0x4e) =
       *(byte *)(param_1 + (ulonglong)*(byte *)(*(longlong *)(param_2 + 0xf0) + 6) * 5 + 299);
  if (((*(uint *)((longlong)pvVar7 + 0x60) & 3) != 0) &&
     (*(uint *)((longlong)pvVar7 + 0x58) < 0x1000)) {
    *(undefined4 *)((longlong)pvVar7 + 0xac) = 1;
  }
  *(ulonglong *)((longlong)pvVar7 + 0x10) = param_2;
  *(undefined4 *)((longlong)pvVar7 + 0xa0) = 0;
  *(undefined1 *)((longlong)pvVar7 + 0xbc) = 0;
  *(code **)((longlong)pvVar7 + 0x18) = DispatchAtapiReadWrite;
  *(undefined8 *)(param_2 + 0x104) = 1;
  *(undefined4 *)(param_2 + 0x10c) = 1;
  if (*(int *)(param_2 + 0xea4) != 0) {
    uVar10 = *(ulonglong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
    *(void **)(uVar10 + 0x78 + (ulonglong)*(byte *)(uVar10 + 0x278) * 8) = pvVar7;
    *(char *)(uVar10 + 0x278) = *(char *)(uVar10 + 0x278) + '\x01';
  }
  if (*(char *)(puVar5 + 9) != '\x03') {
    if (bVar11) {
      pvVar8 = StorAllocateSubCmd(uVar10,param_2);
      if (pvVar8 == (void *)0x0) goto LAB_000163c1;
      puVar1 = (undefined8 *)((longlong)pvVar8 + 0x48);
      if (puVar1 != puVar5) {
        *puVar1 = *puVar5;
        *(undefined8 *)((longlong)pvVar8 + 0x50) = puVar5[1];
        *(undefined8 *)((longlong)pvVar8 + 0x58) = puVar5[2];
        *(undefined8 *)((longlong)pvVar8 + 0x60) = puVar5[3];
        *(undefined8 *)((longlong)pvVar8 + 0x68) = puVar5[4];
        *(undefined8 *)((longlong)pvVar8 + 0x70) = puVar5[5];
        *(undefined8 *)((longlong)pvVar8 + 0x78) = puVar5[6];
        *(undefined8 *)((longlong)pvVar8 + 0x80) = puVar5[7];
        *(undefined8 *)((longlong)pvVar8 + 0x88) = puVar5[8];
        *(undefined8 *)((longlong)pvVar8 + 0x90) = puVar5[9];
        *(undefined8 *)((longlong)pvVar8 + 0x98) = puVar5[10];
      }
      *(undefined1 *)((longlong)pvVar8 + 0x4e) =
           *(undefined1 *)
            (param_1 + (ulonglong)*(byte *)(*(longlong *)(param_2 + 0xf0) + 6) * 5 + 299);
      *(ulonglong *)((longlong)pvVar8 + 0x10) = param_2;
      *(undefined4 *)((longlong)pvVar8 + 0xa4) = 1;
      *(undefined4 *)((longlong)pvVar8 + 0xac) = 1;
      uVar2 = *(undefined1 *)((longlong)pvVar8 + 0x4d);
      bVar3 = *(byte *)((longlong)pvVar8 + 0x4e);
      uVar4 = *(undefined1 *)((longlong)pvVar8 + 0x4f);
      memset(puVar1,0,0x58);
      *(undefined1 *)((longlong)pvVar8 + 0x4d) = uVar2;
      *(byte *)((longlong)pvVar8 + 0x4e) = bVar3;
      *(undefined1 *)((longlong)pvVar8 + 0x4f) = uVar4;
      *(undefined4 *)((longlong)pvVar8 + 0x54) = 0x40;
      *(undefined4 *)((longlong)pvVar8 + 0x5c) = 4;
      *(undefined1 *)((longlong)pvVar8 + 0x52) = 6;
      *(undefined4 *)((longlong)pvVar8 + 0x58) = 0x12;
      *(undefined1 *)((longlong)pvVar8 + 0x4a) = 0;
      *(undefined2 *)puVar1 = 0x58;
      puVar1 = (undefined8 *)((longlong)param_1 + (ulonglong)(bVar3 >> 1) * 0x12 + 0x46a0);
      *(undefined8 **)((longlong)pvVar8 + 0x60) = puVar1;
      *puVar1 = 0;
      puVar1[1] = 0;
      *(undefined2 *)(puVar1 + 2) = 0;
      *(undefined1 *)((longlong)pvVar8 + 0x90) = 3;
      *(undefined1 *)((longlong)pvVar8 + 0x94) = 0x12;
      *(ulonglong *)((longlong)pvVar8 + 0x10) = param_2;
      *(undefined4 *)((longlong)pvVar8 + 0xa0) = 1;
      *(undefined1 *)((longlong)pvVar8 + 0xbc) = 1;
      *(code **)((longlong)pvVar8 + 0x18) = DispatchAtapiReadWrite;
    }
    if (*(char *)(puVar5 + 9) != '\x03') {
      if (bVar11) {
        *(int *)(param_2 + 0x104) = *(int *)(param_2 + 0x104) + 1;
        *(undefined4 *)(param_2 + 0x110) = 1;
        *(code **)(param_2 + 0x168) = AtapiAutoModeSense;
        *(undefined8 *)(param_2 + 0x200) = puVar5[4];
        bVar3 = *(byte *)((longlong)puVar5 + 0xb);
        *(void **)(param_2 + 0x210) = pvVar8;
        *(ulonglong *)(param_2 + 0x208) = (ulonglong)bVar3;
      }
      if ((*(char *)(puVar5 + 9) != '\x03') && (bVar11)) {
        if (*(int *)(param_2 + 0xea4) != 0) {
          lVar9 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
          *(void **)(lVar9 + 0x78 + (ulonglong)*(byte *)(lVar9 + 0x278) * 8) = pvVar8;
          *(char *)(lVar9 + 0x278) = *(char *)(lVar9 + 0x278) + '\x01';
        }
        *(undefined1 *)(param_2 + 0xebf) = 1;
        *(void **)(param_2 + 0xec0) = pvVar8;
      }
    }
  }
  *(undefined8 *)(param_2 + 0xf8) = 0;
  return 0;
}



===== IDESanityCheck64 @ 000166b4 =====

ulonglong IDESanityCheck64(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong local_res8;
  longlong local_res10;
  
  GetStartEndFromSrb(param_2,&local_res8,&local_res10,*(int *)(param_3 + 0xe98));
  lVar1 = *(longlong *)(param_3 + 0xf0);
  uVar2 = GetLogicTargetCapacity64(param_1,*(byte *)(lVar1 + 6));
  if (*(char *)(param_2 + 0x48) != -0x71) {
    local_res8 = local_res8 + ((*(int *)(param_2 + 0x10) + 0x1ffU >> 9) - 1);
  }
  if ((uVar2 < local_res8) ||
     ((*(int *)(param_2 + 0x10) == 0 && ((*(char *)(param_2 + 0x48) + 0x78U & 0xfd) == 0)))) {
    *(undefined4 *)(param_3 + 0xf8) = 10;
    *(undefined4 *)(param_3 + 0xfc) = 1;
    uVar3 = uVar2;
LAB_00016731:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x18);
    if (((*(uint *)(param_2 + 0x18) & 1) != 0) && (*(int *)(param_2 + 0x10) != 0)) {
      *(undefined1 *)(param_3 + 0x101) = 1;
    }
    if (*(char *)(param_2 + 0x48) == -0x71) {
      uVar3 = 0;
      uVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x52),
                                         *(undefined1 *)(param_2 + 0x53)),
                                *(undefined1 *)(param_2 + 0x54)),*(undefined1 *)(param_2 + 0x55));
      if ((uVar4 != 0) && (uVar3 = (ulonglong)uVar4, uVar2 <= ((ulonglong)uVar4 - 1) + local_res8))
      {
        *(undefined4 *)(param_3 + 0xf8) = 10;
        *(undefined4 *)(param_3 + 0xfc) = 1;
        *(undefined1 *)(lVar1 + 4) = 2;
        goto LAB_00016731;
      }
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 0x80;
      if (0x100 < uVar4) {
        uVar4 = 0x100;
      }
      *(uint *)(param_2 + 0x10) = uVar4 << 9;
    }
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}



===== IDESanityCheck @ 000167cc =====

ulonglong IDESanityCheck(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  uint3 uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  ulonglong uVar6;
  uint uVar7;
  
  lVar1 = *(longlong *)(param_3 + 0xf0);
  uVar7 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),*(undefined1 *)(param_2 + 0x4b)
                                    ),*(undefined1 *)(param_2 + 0x4c)),
                   *(undefined1 *)(param_2 + 0x4d));
  if (*(int *)(param_3 + 0xe98) != 0) {
    uVar5 = IDESanityCheck64(param_1,param_2,param_3);
    return uVar5;
  }
  uVar3 = GetLogicTargetCapacity
                    (param_1,CONCAT71((int7)((ulonglong)param_2 >> 8),*(undefined1 *)(lVar1 + 6)));
  uVar5 = (ulonglong)uVar3;
  if (*(char *)(param_2 + 0x48) != '/') {
    uVar7 = uVar7 + ((*(int *)(param_2 + 0x10) + 0x1ffU >> 9) - 1);
  }
  if ((uVar3 < uVar7) ||
     ((*(int *)(param_2 + 0x10) == 0 && ((*(char *)(param_2 + 0x48) - 0x28U & 0xfd) == 0)))) {
    *(undefined4 *)(param_3 + 0xf8) = 10;
    *(undefined4 *)(param_3 + 0xfc) = 1;
    uVar5 = CONCAT44(extraout_var,uVar3);
LAB_00016871:
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  else {
    uVar6 = (ulonglong)*(uint *)(param_2 + 0x18);
    if (((*(uint *)(param_2 + 0x18) & 1) != 0) && (*(int *)(param_2 + 0x10) != 0)) {
      *(undefined1 *)(param_3 + 0x101) = 1;
    }
    if (*(char *)(param_2 + 0x48) == '/') {
      uVar6 = 0;
      uVar7 = (uint)CONCAT11(*(undefined1 *)(param_2 + 0x4f),*(undefined1 *)(param_2 + 0x50));
      if ((uVar7 != 0) &&
         (uVar4 = (uVar7 - 1) +
                  CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                             *(undefined1 *)(param_2 + 0x4b)),
                                    *(undefined1 *)(param_2 + 0x4c)),*(undefined1 *)(param_2 + 0x4d)
                          ), uVar6 = (ulonglong)uVar4, uVar3 <= uVar4)) {
        *(undefined4 *)(param_3 + 0xf8) = 10;
        *(undefined4 *)(param_3 + 0xfc) = 1;
        *(undefined1 *)(lVar1 + 4) = 2;
        uVar5 = uVar6;
        goto LAB_00016871;
      }
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 0x80;
      if (0x100 < uVar7) {
        uVar7 = 0x100;
      }
      *(uint *)(param_2 + 0x10) = uVar7 << 9;
    }
    if (*(char *)(param_2 + 0x48) == -0x71) {
      uVar2 = CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x52),*(undefined1 *)(param_2 + 0x53)),
                       *(undefined1 *)(param_2 + 0x54));
      uVar7 = CONCAT31(uVar2,*(byte *)(param_2 + 0x55));
      uVar6 = 0;
      if ((uVar7 != 0) &&
         (uVar6 = uVar5,
         uVar5 <= ((ulonglong)uVar7 - 1) +
                  ((longlong)
                   (int)((uint)CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4e),
                                                 *(undefined1 *)(param_2 + 0x4f)),
                                        *(undefined1 *)(param_2 + 0x50)) << 8) |
                   ((ulonglong)*(byte *)(param_2 + 0x55) | (longlong)(int)((uint)uVar2 << 8)) <<
                   0x20 | (ulonglong)*(byte *)(param_2 + 0x51)))) {
        *(undefined4 *)(param_3 + 0xf8) = 10;
        *(undefined4 *)(param_3 + 0xfc) = 1;
        *(undefined1 *)(param_2 + 4) = 2;
        goto LAB_00016871;
      }
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 0x80;
      if (0x100 < uVar7) {
        uVar7 = 0x100;
      }
      *(uint *)(param_2 + 0x10) = uVar7 << 9;
    }
    uVar5 = CONCAT71((int7)(uVar6 >> 8),1);
  }
  return uVar5;
}



===== NormalHDDCommand @ 000169e4 =====

longlong NormalHDDCommand(ulonglong param_1,undefined8 *param_2,longlong param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  longlong lVar4;
  undefined8 *puVar5;
  ulonglong local_res8;
  longlong local_res18 [2];
  
  puVar5 = param_2;
  local_res8 = param_1;
  GetStartEndFromSrb((longlong)param_2,&local_res8,local_res18,*(int *)(param_3 + 0xe98));
  pvVar3 = StorAllocateSubCmd(puVar5,param_3);
  if (pvVar3 == (void *)0x0) {
    *(undefined4 *)(param_3 + 0xfc) = 2;
    *(undefined1 *)(param_3 + 0x100) = 2;
    lVar4 = 4;
  }
  else {
    if (*(char *)(param_3 + 0x102) == '\x01') {
      *(undefined4 *)((longlong)pvVar3 + 0xa4) = 1;
    }
    uVar1 = *(uint *)(param_3 + 0x104);
    *(uint *)((longlong)pvVar3 + 0xa0) = uVar1;
    *(undefined1 *)((ulonglong)uVar1 + 0x2a0 + param_3) = 0;
    *(longlong *)((longlong)pvVar3 + 0x10) = param_3;
    *(code **)((longlong)pvVar3 + 0x18) = DispatchDiskReadWrite;
    *(ulonglong *)((longlong)pvVar3 + 0x40) = local_res8;
    if (*(int *)(param_3 + 0xe98) != 0) {
      *(undefined4 *)((longlong)pvVar3 + 0x38) = 1;
    }
    if ((undefined8 *)((longlong)pvVar3 + 0x48) != param_2) {
      *(undefined8 *)((longlong)pvVar3 + 0x48) = *param_2;
      *(undefined8 *)((longlong)pvVar3 + 0x50) = param_2[1];
      *(undefined8 *)((longlong)pvVar3 + 0x58) = param_2[2];
      *(undefined8 *)((longlong)pvVar3 + 0x60) = param_2[3];
      *(undefined8 *)((longlong)pvVar3 + 0x68) = param_2[4];
      *(undefined8 *)((longlong)pvVar3 + 0x70) = param_2[5];
      *(undefined8 *)((longlong)pvVar3 + 0x78) = param_2[6];
      *(undefined8 *)((longlong)pvVar3 + 0x80) = param_2[7];
      *(undefined8 *)((longlong)pvVar3 + 0x88) = param_2[8];
      *(undefined8 *)((longlong)pvVar3 + 0x90) = param_2[9];
      *(undefined8 *)((longlong)pvVar3 + 0x98) = param_2[10];
    }
    *(undefined8 *)((longlong)pvVar3 + 0x30) = 0;
    if (*(int *)(param_3 + 0xea4) != 0) {
      lVar4 = *(longlong *)(*(longlong *)(param_3 + 0xf0) + 0x38);
      *(void **)(lVar4 + 0x78 + (ulonglong)*(byte *)(lVar4 + 0x278) * 8) = pvVar3;
      *(char *)(lVar4 + 0x278) = *(char *)(lVar4 + 0x278) + '\x01';
    }
    iVar2 = *(int *)(param_3 + 0x104);
    *(undefined4 *)(param_3 + 0x10c + (longlong)iVar2 * 4) = 1;
    *(int *)(param_3 + 0x104) = *(int *)(param_3 + 0x104) + 1;
    lVar4 = (ulonglong)(uint7)(int7)(int3)((uint)iVar2 >> 8) << 8;
    *(undefined4 *)(param_3 + 0x108) = 0;
    *(undefined8 *)(param_3 + 0xf8) = 0;
  }
  return lVar4;
}



===== ParseIdeReadWrite @ 00016b44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ParseIdeReadWrite(ulonglong *param_1,longlong param_2)

{
  undefined4 uVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined1 auStack_b8 [32];
  longlong local_98 [2];
  undefined8 local_88;
  ulonglong local_80;
  ulonglong local_78;
  ulonglong local_70;
  ulonglong local_68;
  ulonglong local_60;
  ulonglong local_58;
  ulonglong local_50;
  ulonglong local_48;
  ulonglong local_40;
  ulonglong local_38;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  puVar2 = *(ulonglong **)(param_2 + 0xf0);
  memset(&local_88,0,0x58);
  if (&local_88 != puVar2) {
    local_88 = *puVar2;
    local_80 = puVar2[1];
    local_78 = puVar2[2];
    local_70 = puVar2[3];
    local_68 = puVar2[4];
    local_60 = puVar2[5];
    local_58 = puVar2[6];
    local_50 = puVar2[7];
    local_48 = puVar2[8];
    local_40 = puVar2[9];
    local_38 = puVar2[10];
  }
  uVar4 = local_88 >> 0x30;
  local_88._0_7_ = CONCAT16((char)param_1[(uVar4 & 0xff) * 5 + 299],(undefined6)local_88);
  uVar4 = IDESanityCheck((longlong)param_1,(longlong)&local_88,param_2);
  if ((char)uVar4 == '\0') {
    return CONCAT71((int7)(uVar4 >> 8),4);
  }
  uVar3 = local_88 >> 0x30;
  local_98[0] = 0;
  *(undefined1 *)(param_2 + 0xeb6) = 1;
  uVar1 = *(undefined4 *)((longlong)param_1 + (ulonglong)*(byte *)((longlong)puVar2 + 6) * 4 + 700);
  *(undefined1 *)(param_2 + 0xee1) = 0;
  *(undefined4 *)(param_2 + 0xeb8) = uVar1;
  uVar4 = *(ulonglong *)(param_2 + 0xf0);
  if (((*(longlong *)(uVar4 + 0x38) != 0) && (*(int *)(*(longlong *)(uVar4 + 0x38) + 0x27c) == 0))
     && (*(char *)(param_2 + 0xee0) == '\0')) {
    bVar6 = Hibernate == '\0';
    *(undefined1 *)(param_2 + 0xee0) = 1;
    if (bVar6) {
      StorPortNotification(0xf,param_1,local_98);
      if ((local_98[0] == 0) || (*(code **)(local_98[0] + 0x30) == (code *)0x0)) {
        uVar4 = *(ulonglong *)(*(longlong *)(param_2 + 0xf0) + 0x18);
        *(ulonglong *)(param_2 + 0xed8) = uVar4;
        goto LAB_00016ccd;
      }
      uVar4 = *(ulonglong *)(param_2 + 0xf0);
      uVar5 = (**(code **)(local_98[0] + 0x30))();
    }
    else {
      uVar5 = *(undefined8 *)(uVar4 + 0x18);
    }
    *(undefined8 *)(param_2 + 0xed8) = uVar5;
  }
LAB_00016ccd:
  if ((int)param_1[(uVar3 & 0xff) * 0x17 + 0x71] == 0) {
    uVar4 = RfRaidCommand(param_1,&local_88,param_2);
  }
  else {
    uVar4 = NormalHDDCommand(uVar4,&local_88,param_2);
  }
  return uVar4;
}



===== ParseIdeSimpleCmd @ 00016d10 =====

undefined1 ParseIdeSimpleCmd(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  void *pvVar6;
  
  lVar4 = *(longlong *)(param_2 + 0xf0);
  uVar1 = *(undefined1 *)(lVar4 + 3);
  uVar2 = *(undefined1 *)(param_1 + 0x958 + (ulonglong)*(byte *)(lVar4 + 6) * 0x28);
  if (*(char *)(lVar4 + 0x48) != '5') {
    *(undefined4 *)(param_2 + 0x104) = 0;
  }
  pvVar6 = StorAllocateSubCmd(param_1,param_2);
  if (pvVar6 == (void *)0x0) {
    *(undefined4 *)(param_2 + 0xfc) = 2;
    *(undefined1 *)(param_2 + 0x100) = 2;
  }
  else {
    uVar3 = *(undefined4 *)(param_2 + 0x104);
    *(undefined8 *)((longlong)pvVar6 + 0x30) = 0;
    *(longlong *)((longlong)pvVar6 + 0x10) = param_2;
    *(undefined4 *)((longlong)pvVar6 + 0xa0) = uVar3;
    *(undefined8 *)((longlong)pvVar6 + 0x18) = param_3;
    puVar5 = *(undefined8 **)(param_2 + 0xf0);
    if ((undefined8 *)((longlong)pvVar6 + 0x48) != puVar5) {
      *(undefined8 *)((longlong)pvVar6 + 0x48) = *puVar5;
      *(undefined8 *)((longlong)pvVar6 + 0x50) = puVar5[1];
      *(undefined8 *)((longlong)pvVar6 + 0x58) = puVar5[2];
      *(undefined8 *)((longlong)pvVar6 + 0x60) = puVar5[3];
      *(undefined8 *)((longlong)pvVar6 + 0x68) = puVar5[4];
      *(undefined8 *)((longlong)pvVar6 + 0x70) = puVar5[5];
      *(undefined8 *)((longlong)pvVar6 + 0x78) = puVar5[6];
      *(undefined8 *)((longlong)pvVar6 + 0x80) = puVar5[7];
      *(undefined8 *)((longlong)pvVar6 + 0x88) = puVar5[8];
      *(undefined8 *)((longlong)pvVar6 + 0x90) = puVar5[9];
      *(undefined8 *)((longlong)pvVar6 + 0x98) = puVar5[10];
    }
    *(undefined1 *)((longlong)pvVar6 + 0x4b) = 0;
    *(undefined1 *)((longlong)pvVar6 + 0x4e) = uVar2;
    *(int *)(param_2 + 0x108) = *(int *)(param_2 + 0x104);
    *(undefined4 *)(param_2 + 0x10c + (longlong)*(int *)(param_2 + 0x104) * 4) = 1;
    *(undefined4 *)(param_2 + 0xfc) = 0;
    *(undefined8 *)(param_2 + 0x160 + (longlong)*(int *)(param_2 + 0x104) * 8) = 0;
    *(int *)(param_2 + 0x104) = *(int *)(param_2 + 0x104) + 1;
    if (*(int *)(param_2 + 0xea4) != 0) {
      lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
      *(void **)(lVar4 + 0x78 + (ulonglong)*(byte *)(lVar4 + 0x278) * 8) = pvVar6;
      *(char *)(lVar4 + 0x278) = *(char *)(lVar4 + 0x278) + '\x01';
    }
  }
  return uVar1;
}



===== ReInitLogicCmd @ 00016e74 =====

void ReInitLogicCmd(undefined8 param_1,undefined8 *param_2,longlong param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 local_38;
  undefined8 local_30;
  
  if (&local_38 == param_2) {
    uVar5 = local_30;
    uVar6 = local_38;
  }
  else {
    uVar5 = param_2[1];
    uVar6 = *param_2;
  }
  uVar1 = *(undefined1 *)(param_2 + 0x1d6);
  uVar3 = *(undefined4 *)(param_2 + 0x1d7);
  uVar4 = param_2[0x1db];
  uVar2 = *(undefined1 *)(param_2 + 0x1dc);
  memset(param_2,0,0xf00);
  if (param_2 != &local_38) {
    *param_2 = uVar6;
    param_2[1] = uVar5;
  }
  *(undefined1 *)(param_2 + 0x1d6) = uVar1;
  *(undefined4 *)(param_2 + 0x1d7) = uVar3;
  param_2[0x1db] = uVar4;
  *(undefined1 *)(param_2 + 0x1dc) = uVar2;
  param_2[0x1e] = param_3;
  *(undefined1 *)((longlong)param_2 + 0xeca) = *(undefined1 *)(param_3 + 6);
  *(undefined1 *)(param_3 + 4) = 0;
  param_2[0x1f] = 0;
  return;
}



===== ReInitSrbExtension @ 00016f44 =====

void ReInitSrbExtension(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 local_318 [79];
  undefined4 local_9c;
  undefined8 local_98;
  
  if (local_318 != param_1) {
    if ((((uint)param_1 | (uint)local_318) & 0xf) == 0) {
      lVar5 = 6;
      puVar6 = local_318;
      puVar8 = param_1;
      do {
        uVar1 = puVar8[1];
        uVar2 = puVar8[2];
        uVar3 = puVar8[3];
        *puVar6 = *puVar8;
        puVar6[1] = uVar1;
        uVar1 = puVar8[4];
        uVar4 = puVar8[5];
        puVar6[2] = uVar2;
        puVar6[3] = uVar3;
        uVar2 = puVar8[6];
        uVar3 = puVar8[7];
        puVar6[4] = uVar1;
        puVar6[5] = uVar4;
        uVar1 = puVar8[8];
        uVar4 = puVar8[9];
        puVar6[6] = uVar2;
        puVar6[7] = uVar3;
        uVar2 = puVar8[10];
        uVar3 = puVar8[0xb];
        puVar6[8] = uVar1;
        puVar6[9] = uVar4;
        uVar1 = puVar8[0xc];
        uVar4 = puVar8[0xd];
        puVar6[10] = uVar2;
        puVar6[0xb] = uVar3;
        uVar2 = puVar8[0xe];
        uVar3 = puVar8[0xf];
        puVar8 = puVar8 + 0x10;
        puVar6[0xc] = uVar1;
        puVar6[0xd] = uVar4;
        puVar7 = puVar6 + 0x10;
        puVar6[0xe] = uVar2;
        puVar6[0xf] = uVar3;
        lVar5 = lVar5 + -1;
        puVar6 = puVar7;
      } while (lVar5 != 0);
      *puVar7 = *puVar8;
    }
    else {
      memcpy(local_318,param_1,0x308);
    }
  }
  memset(param_1,0,0x308);
  *(undefined4 *)((longlong)param_1 + 0x27c) = local_9c;
  param_1[0x50] = local_98;
  return;
}



===== AtapiAutoModeSense @ 0001700c =====

void AtapiAutoModeSense(undefined8 param_1,longlong param_2)

{
  byte *_Dst;
  byte *_Src;
  byte bVar1;
  
  _Dst = *(byte **)(param_2 + 0x200);
  bVar1 = *(byte *)(param_2 + 0x208);
  _Src = *(byte **)(*(longlong *)(param_2 + 0x210) + 0x60);
  if (-1 < (char)*_Src) {
    *_Src = *_Src | 0x80;
  }
  *_Src = *_Src & 0xf0 | 0x70;
  memset(_Dst,0,(ulonglong)bVar1);
  if (_Dst != _Src) {
    if (0x12 < bVar1) {
      bVar1 = 0x12;
    }
    memcpy(_Dst,_Src,(ulonglong)bVar1);
  }
  return;
}



===== SetRealLogicTarget @ 00017088 =====

void SetRealLogicTarget(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  longlong lVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  
  if (*(char *)(param_2 + 0xec9) != '\0') {
    bVar4 = 0;
    bVar6 = 0;
    do {
      uVar2 = *(ushort *)(param_1 + 0xab8 + (ulonglong)bVar4 * 2);
      bVar5 = bVar6;
      if (((uVar2 & 1) != 0) && ((uVar2 & 2) == 0)) {
        lVar3 = (ulonglong)bVar4 * 0xb8;
        *(undefined1 *)(param_2 + 0xecb) = *(undefined1 *)(lVar3 + 0x43c + param_1);
        bVar5 = *(byte *)(lVar3 + 0x43c + param_1);
        if (*(char *)(param_1 + 0x959 + (ulonglong)bVar5 * 0x28) == '\0') {
          *(undefined1 *)(param_2 + 0xeca) = *(undefined1 *)(*(longlong *)(param_2 + 0xf0) + 6);
          *(undefined1 *)(*(longlong *)(param_2 + 0xf0) + 6) = *(undefined1 *)(param_2 + 0xecb);
          break;
        }
      }
      bVar4 = bVar4 + 1;
      bVar6 = bVar5;
    } while (bVar4 < 8);
    if (bVar4 == 8) {
      uVar1 = *(undefined1 *)(*(longlong *)(param_2 + 0xf0) + 6);
      *(byte *)(param_2 + 0xecb) = bVar6;
      *(undefined1 *)(param_2 + 0xeca) = uVar1;
      *(byte *)(*(longlong *)(param_2 + 0xf0) + 6) = bVar6;
    }
  }
  return;
}



===== ViaAllocatePool @ 0001712c =====

undefined8 ViaAllocatePool(longlong param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  longlong lVar2;
  uint *puVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  
  lVar2 = *(longlong *)(param_1 + 8);
  if (param_3 == 0) {
    return 0;
  }
  iVar1 = *(int *)(lVar2 + 0x400);
  uVar9 = param_3 + 0xfffU & 0xfffff000;
  if (iVar1 == 0) {
    return 0;
  }
  if (*(uint *)(lVar2 + 0x490) < uVar9) {
    return 0;
  }
  iVar5 = 0;
  lVar8 = 0;
  if (0 < iVar1) {
    puVar3 = (uint *)(lVar2 + 8);
    do {
      if (((char)puVar3[1] == '\0') && (uVar9 <= *puVar3)) break;
      lVar8 = lVar8 + 1;
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 4;
    } while (lVar8 < iVar1);
  }
  if (iVar5 == iVar1) {
    return 0;
  }
  lVar8 = (longlong)iVar5;
  iVar5 = *(int *)(lVar2 + 8 + lVar8 * 0x10) - uVar9;
  if (iVar5 != 0) {
    if (iVar1 == 0x40) {
      *(undefined1 *)(lVar2 + 0xc + lVar8 * 0x10) = 1;
      goto LAB_00017212;
    }
    lVar6 = (longlong)(iVar1 + -1);
    if (lVar8 < lVar6) {
      lVar7 = lVar6 - lVar8;
      puVar4 = (undefined8 *)(lVar6 * 0x10 + lVar2);
      do {
        puVar4[2] = *puVar4;
        puVar4[3] = puVar4[1];
        lVar7 = lVar7 + -1;
        puVar4 = puVar4 + -2;
      } while (lVar7 != 0);
    }
    lVar6 = lVar8 + 1;
    *(ulonglong *)(lVar2 + lVar6 * 0x10) = (ulonglong)uVar9 + *(longlong *)(lVar2 + lVar8 * 0x10);
    *(undefined1 *)(lVar2 + 0xc + lVar6 * 0x10) = 0;
    *(int *)(lVar2 + 8 + lVar6 * 0x10) = iVar5;
    *(int *)(lVar2 + 0x400) = iVar1 + 1;
  }
  *(undefined1 *)(lVar2 + 0xc + lVar8 * 0x10) = 1;
  *(uint *)(lVar2 + 8 + lVar8 * 0x10) = uVar9;
  *(int *)(lVar2 + 0x490) = *(int *)(lVar2 + 0x490) - uVar9;
LAB_00017212:
  return *(undefined8 *)(lVar2 + lVar8 * 0x10);
}



===== ViaFreePool @ 0001721c =====

void ViaFreePool(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  int iVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong *puVar5;
  int iVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  int iVar13;
  ulonglong uVar14;
  
  puVar2 = *(ulonglong **)(param_1 + 8);
  uVar14 = 0;
  iVar1 = (int)puVar2[0x80];
  lVar12 = (longlong)iVar1;
  if (((0 < iVar1) && (*puVar2 <= param_3)) && (param_3 <= puVar2[lVar12 * 2 + -2])) {
    uVar8 = 0;
    uVar9 = iVar1 - 1;
    if (*puVar2 == param_3) {
      uVar7 = 0;
    }
    else {
      uVar4 = uVar9;
      if (((int)uVar9 < 1) || (puVar2[(longlong)(int)uVar9 * 2] != param_3)) {
        while( true ) {
          if ((int)uVar4 < 2) {
            return;
          }
          uVar4 = (int)(uVar9 + uVar8) / 2;
          uVar7 = (ulonglong)(int)uVar4;
          if (puVar2[uVar7 * 2] == param_3) break;
          if (puVar2[uVar7 * 2] < param_3) {
            uVar8 = uVar4;
            uVar4 = uVar9;
          }
          uVar9 = uVar4;
          uVar4 = uVar4 - uVar8;
        }
      }
      else {
        uVar7 = (ulonglong)uVar9;
      }
    }
    iVar6 = (int)uVar7;
    lVar11 = (longlong)iVar6;
    if (*(char *)(lVar11 * 0x10 + 0xc + (longlong)puVar2) != '\0') {
      uVar3 = puVar2[lVar11 * 2 + 1];
      *(undefined1 *)(lVar11 * 0x10 + 0xc + (longlong)puVar2) = 0;
      *(int *)(puVar2 + 0x92) = (int)puVar2[0x92] + (int)uVar3;
      iVar10 = 0;
      if (iVar6 < iVar6 + 2) {
        puVar5 = puVar2 + lVar11 * 2 + -1;
        do {
          iVar13 = (int)uVar14;
          if (lVar12 <= lVar11) break;
          if ((((int)uVar7 != 0) && (*(char *)((longlong)puVar5 + 0x14) == '\0')) &&
             (*(char *)((longlong)puVar5 + 4) == '\0')) {
            if (puVar5[-1] + (ulonglong)(uint)*puVar5 == puVar5[1]) {
              *(uint *)(puVar5 + 2) = (uint)puVar5[2] + (uint)*puVar5;
              puVar5[1] = puVar5[-1];
              uVar14 = uVar7 & 0xffffffff;
              iVar10 = iVar10 + 1;
            }
          }
          iVar13 = (int)uVar14;
          uVar9 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar9;
          lVar11 = lVar11 + 1;
          puVar5 = puVar5 + 2;
        } while ((int)uVar9 < iVar6 + 2);
        if (0 < iVar10) {
          lVar11 = (longlong)iVar13;
          if (lVar11 < lVar12) {
            puVar5 = puVar2 + lVar11 * 2;
            lVar12 = lVar12 - lVar11;
            do {
              uVar14 = puVar5[1];
              puVar5[(longlong)iVar10 * -2] = *puVar5;
              (puVar5 + (longlong)iVar10 * -2)[1] = uVar14;
              puVar5 = puVar5 + 2;
              lVar12 = lVar12 + -1;
            } while (lVar12 != 0);
          }
          *(int *)(puVar2 + 0x80) = iVar1 - iVar10;
        }
      }
    }
  }
  return;
}



===== ReleaseTmpCmdBufs @ 000173a4 =====

void ReleaseTmpCmdBufs(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  int iVar3;
  undefined8 *puVar4;
  
  iVar3 = 0;
  if (0 < *(int *)(param_2 + 0xe0)) {
    puVar4 = (undefined8 *)(param_2 + 0x50);
    lVar2 = param_2;
    do {
      puVar1 = (ulonglong *)*puVar4;
      ViaFreePool(param_1,lVar2,*puVar1);
      *puVar1 = 0;
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar3 < *(int *)(param_2 + 0xe0));
  }
  *(undefined4 *)(param_2 + 0xe0) = 0;
  return;
}



===== AtapiStringCmp @ 00017414 =====

int AtapiStringCmp(longlong param_1,byte *param_2,int param_3)

{
  longlong lVar1;
  byte bVar2;
  byte bVar3;
  
  lVar1 = param_1 - (longlong)param_2;
  do {
    bVar2 = param_2[lVar1];
    bVar3 = *param_2;
    param_2 = param_2 + 1;
    if (bVar2 != bVar3) {
      if ((byte)(bVar2 + 0xbf) < 0x1a) {
        bVar2 = bVar2 + 0x20;
      }
      if ((byte)(bVar3 + 0xbf) < 0x1a) {
        bVar3 = bVar3 + 0x20;
      }
      if (bVar2 != bVar3) {
        return (uint)bVar2 - (uint)bVar3;
      }
    }
    param_3 = param_3 + -1;
    if ((param_3 == 0) || (bVar2 == 0)) {
      return 0;
    }
  } while( true );
}



===== GetLogicTargetCapacity64 @ 0001745c =====

undefined8 GetLogicTargetCapacity64(longlong param_1,byte param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  lVar3 = (ulonglong)*(byte *)(param_1 + 0x958 + (ulonglong)param_2 * 0x28) * 0xb8 + param_1;
  if (*(int *)(lVar3 + 0x388) == 0) {
    uVar1 = (ulonglong)*(byte *)(param_1 + 0x97c + (ulonglong)param_2 * 0x28);
    uVar2 = CONCAT44(*(undefined4 *)(lVar3 + 0x420 + uVar1 * 4),
                     *(undefined4 *)(lVar3 + 0x3b8 + uVar1 * 4));
  }
  else {
    uVar2 = CONCAT44(*(undefined4 *)(lVar3 + 0x438),*(undefined4 *)(lVar3 + 0x3f0));
  }
  return uVar2;
}



===== GetLogicTargetCapacity @ 000174bc =====

undefined4 GetLogicTargetCapacity(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = (ulonglong)*(byte *)(param_1 + 0x958 + (param_2 & 0xff) * 0x28) * 0xb8 + param_1;
  if (*(int *)(lVar1 + 0x388) == 0) {
    uVar2 = (ulonglong)*(byte *)(param_1 + 0x97c + (param_2 & 0xff) * 0x28);
    if (*(int *)(lVar1 + 0x420 + uVar2 * 4) == 0) {
      return *(undefined4 *)(lVar1 + 0x3b8 + uVar2 * 4);
    }
  }
  else if (*(int *)(lVar1 + 0x438) == 0) {
    return *(undefined4 *)(lVar1 + 0x3f0);
  }
  return 0xffffffff;
}



===== CheckSleeptimeHotplug @ 00017510 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CheckSleeptimeHotplug(longlong param_1,undefined8 param_2,longlong param_3)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  ulonglong uVar4;
  longlong lVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  byte *pbVar10;
  byte *pbVar11;
  undefined1 auStack_58 [32];
  char local_38 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_58;
  bVar2 = false;
  lVar5 = 10;
  do {
    StorPortStallExecution(1000);
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  StorPortStallExecution(0);
  pbVar10 = (byte *)(param_1 + 0xab8);
  uVar8 = 0;
  pcVar6 = local_38;
  pbVar11 = pbVar10;
  do {
    if ((pcVar6[(param_1 - (longlong)local_38) + 0x948] != 0) &&
       ((pcVar6[(param_1 - (longlong)local_38) + 0x948] & 1U) == 0)) {
      bVar1 = *pbVar11;
      bVar3 = GetDevExistStatus(param_1,uVar8,param_3);
      *pcVar6 = bVar3 != 0;
      if (bVar3 != 0) {
        if ((bVar1 & 1) == 0) {
LAB_000175b2:
          bVar2 = true;
        }
      }
      else if ((bVar1 & 1) != 0) goto LAB_000175b2;
    }
    uVar8 = uVar8 + 1;
    pbVar11 = pbVar11 + 2;
    pcVar6 = pcVar6 + 1;
  } while (uVar8 < 8);
  if (bVar2) {
    uVar8 = 0;
    pcVar9 = local_38;
    pcVar6 = (char *)(param_1 + 0x399);
    do {
      if (pcVar9[(param_1 - (longlong)local_38) + 0x948] != 0) {
        if ((pcVar9[(param_1 - (longlong)local_38) + 0x948] & 1U) == 0) {
          if (*pcVar9 != '\0') {
            if ((*pbVar10 & 1) != 0) goto LAB_00017601;
LAB_00017606:
            uVar7 = 0;
            do {
              uVar4 = IsDevReady(param_1,uVar8,param_3);
              if ((char)uVar4 != '\0') break;
              lVar5 = 500;
              do {
                StorPortStallExecution(1000);
                lVar5 = lVar5 + -1;
              } while (lVar5 != 0);
              StorPortStallExecution(0);
              uVar7 = uVar7 + 1;
            } while (uVar7 < 4);
          }
        }
        else if ((*pbVar10 & 1) != 0) {
LAB_00017601:
          if (*pcVar6 == '\0') goto LAB_00017606;
        }
      }
      uVar8 = uVar8 + 1;
      pbVar10 = pbVar10 + 2;
      pcVar9 = pcVar9 + 1;
      pcVar6 = pcVar6 + 0xb8;
    } while (uVar8 < 8);
    *(undefined4 *)(param_1 + 0x42dc) = 0;
    CheckController(param_1,'\x01',param_3);
  }
  return;
}



===== SaveConfigSpace @ 00017690 =====

void SaveConfigSpace(longlong param_1)

{
  undefined4 uVar1;
  uint uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(param_1 + 0x13b4);
  uVar2 = *(uint *)(param_1 + 0x21c) & 0xffffff00;
  lVar3 = 0x40;
  do {
    uVar1 = ReadConfigSpaceUlong(param_1,uVar2);
    uVar2 = uVar2 + 4;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}



===== RestoreConfigSpace @ 000176ec =====

void RestoreConfigSpace(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  
  uVar1 = *(uint *)(param_1 + 0x21c) & 0xffffff00;
  lVar2 = 0;
  do {
    if (lVar2 != 2) {
      WriteConfigSpaceUlong(param_1,uVar1,*(undefined4 *)(param_1 + 0x13b4 + lVar2 * 4));
    }
    lVar2 = lVar2 + 1;
    uVar1 = uVar1 + 4;
  } while (lVar2 < 0x40);
  return;
}



===== AhciResetPortCheckStatus @ 00017740 =====

/* WARNING: Removing unreachable block (ram,0x00017b31) */
/* WARNING: Removing unreachable block (ram,0x00017aa0) */
/* WARNING: Removing unreachable block (ram,0x00017907) */
/* WARNING: Removing unreachable block (ram,0x0001781b) */
/* WARNING: Removing unreachable block (ram,0x00017777) */
/* WARNING: Removing unreachable block (ram,0x00017897) */
/* WARNING: Removing unreachable block (ram,0x00017941) */
/* WARNING: Removing unreachable block (ram,0x00017baf) */
/* WARNING: Removing unreachable block (ram,0x00017bf8) */

bool AhciResetPortCheckStatus(longlong param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  uint *_Dst;
  char cVar3;
  sbyte sVar4;
  undefined1 *puVar5;
  longlong lVar6;
  longlong lVar7;
  byte bVar8;
  uint uVar9;
  uint *_Dst_00;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  char cVar13;
  ushort *puVar14;
  uint uVar15;
  ulonglong uVar16;
  int *piVar17;
  
  piVar17 = (int *)(param_1 + 0x4808);
  bVar8 = 0;
  piVar11 = piVar17;
  do {
    uVar15 = 0;
    lVar7 = *(longlong *)(param_1 + 0x58);
    lVar6 = ((longlong)(int)(bVar8 & 0x80000003) + 2) * 0x80 + lVar7;
    if (*piVar11 == 0) {
      *(undefined4 *)(lVar6 + 0x14) = 0;
      do {
        if ((*(uint *)(lVar6 + 0x10) & 0x40) != 0) {
          *(uint *)(lVar6 + 0x30) = *(uint *)(lVar6 + 0x30) | 0x4000000;
          break;
        }
        StorPortStallExecution(10);
        uVar15 = uVar15 + 1;
      } while (uVar15 < 1000);
      if ((*(byte *)(lVar6 + 0x28) & 1) == 0) {
        *(uint *)(lVar6 + 0x18) = *(uint *)(lVar6 + 0x18) & 0xffffffee;
        *piVar11 = 1;
        *(undefined4 *)(lVar6 + 0x30) = 0xffffffff;
        *(undefined4 *)(lVar6 + 0x10) = 0xffffffff;
        *(int *)(lVar7 + 8) = 1 << (sbyte)(bVar8 & 0x80000003);
        *(undefined4 *)(lVar6 + 0x14) = 0xffffffff;
      }
    }
    bVar8 = bVar8 + 1;
    piVar11 = piVar11 + 2;
  } while (bVar8 < 4);
  uVar15 = 0;
  bVar8 = 0;
  piVar11 = piVar17;
  do {
    lVar7 = ((longlong)(int)(bVar8 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
    if ((*piVar11 == 0) && (*(char *)(lVar7 + 0x20) < '\0')) {
      while ((uVar15 < 300000 && (*(char *)(lVar7 + 0x20) < '\0'))) {
        StorPortStallExecution(10);
        uVar15 = uVar15 + 1;
      }
    }
    bVar8 = bVar8 + 1;
    piVar11 = piVar11 + 2;
  } while (bVar8 < 4);
  uVar10 = 0;
  piVar11 = piVar17;
  do {
    uVar9 = 0;
    lVar7 = ((longlong)(int)(uVar10 & 3) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
    if (*piVar11 == 0) {
      do {
        if ((char)((uint)*(undefined4 *)(lVar7 + 0x20) >> 8) == '\x01') break;
        StorPortStallExecution(10);
        uVar9 = uVar9 + 1;
      } while (uVar9 < 1000);
      puVar1 = (uint *)(lVar7 + 0x18);
      *puVar1 = *puVar1 | 0x11;
    }
    bVar8 = (char)uVar10 + 1;
    uVar10 = (uint)bVar8;
    piVar11 = piVar11 + 2;
  } while (bVar8 < 4);
  uVar16 = 0;
  piVar11 = piVar17;
  do {
    uVar10 = (uint)uVar16;
    puVar1 = *(uint **)(param_1 + 0x58);
    lVar7 = (longlong)(int)(uVar10 & 0x80000003) + 2;
    if (*piVar11 == 0) {
      if ((char)puVar1[lVar7 * 0x20 + 8] < '\0') {
        _Dst = *(uint **)(param_1 + 0x38 + uVar16 * 8);
        lVar7 = (longlong)(int)(uVar10 & 0x80000003) + 2;
        AhciStopPort(param_1,uVar10);
        uVar10 = 0;
        do {
          uVar9 = puVar1[lVar7 * 0x20 + 8];
          if ((uVar9 & 0x88) == 0) goto LAB_000179b0;
          StorPortStallExecution(10);
          uVar10 = uVar10 + 1;
        } while (uVar10 < 2000);
        if ((uVar9 & 0x88) != 0) {
          if ((*puVar1 & 0x1000000) == 0) goto LAB_00017a75;
          puVar1[lVar7 * 0x20 + 6] = puVar1[lVar7 * 0x20 + 6] | 8;
        }
LAB_000179b0:
        puVar1[lVar7 * 0x20 + 6] = puVar1[lVar7 * 0x20 + 6] | 0x11;
        memset(_Dst + 0x140,0,0x40);
        *(byte *)((longlong)_Dst + 0x501) = *(byte *)((longlong)_Dst + 0x501) & 0x7f;
        *(undefined1 *)(_Dst + 0x140) = 0x27;
        *(undefined1 *)((longlong)_Dst + 0x50f) = 4;
        *(undefined1 *)((longlong)_Dst + 0x507) = 0xa0;
        uVar10 = _Dst[2];
        uVar9 = _Dst[3];
        memset(_Dst,0,0x20);
        _Dst[3] = uVar9;
        _Dst[2] = uVar10;
        *_Dst = *_Dst & 0xffffffe5 | 0x505;
        _Dst_00 = _Dst + 8;
        memset(_Dst + 0x280,0,0x40);
        *(byte *)((longlong)_Dst + 0xa01) = *(byte *)((longlong)_Dst + 0xa01) & 0x7f;
        *(undefined1 *)(_Dst + 0x280) = 0x27;
        *(undefined1 *)((longlong)_Dst + 0xa0f) = 0;
        *(undefined1 *)((longlong)_Dst + 0xa07) = 0xa0;
        uVar10 = _Dst[10];
        uVar9 = _Dst[0xb];
        memset(_Dst_00,0,0x20);
        _Dst[10] = uVar10;
        _Dst[0xb] = uVar9;
        *_Dst_00 = *_Dst_00 & 0xfffffae5 | 5;
        puVar1[lVar7 * 0x20 + 0xe] = puVar1[lVar7 * 0x20 + 0xe] | 1;
        StorPortStallExecution(0x14);
        puVar1[lVar7 * 0x20 + 0xe] = puVar1[lVar7 * 0x20 + 0xe] | 2;
      }
      else {
        *piVar11 = 1;
        puVar1[lVar7 * 0x20 + 0xc] = 0xffffffff;
        puVar1[lVar7 * 0x20 + 4] = 0xffffffff;
        puVar1[2] = 1 << (sbyte)(uVar10 & 0x80000003);
        puVar1[lVar7 * 0x20 + 5] = 0xffffffff;
      }
    }
LAB_00017a75:
    bVar8 = (char)uVar16 + 1;
    uVar16 = (ulonglong)bVar8;
    piVar11 = piVar11 + 2;
  } while (bVar8 < 4);
  uVar10 = 0;
  uVar9 = 0;
  piVar11 = piVar17;
  do {
    lVar7 = *(longlong *)(param_1 + 0x58);
    if (*piVar11 == 0) {
      while ((uVar10 < 300000 &&
             ((*(uint *)(((longlong)(int)(uVar9 & 3) + 2) * 0x80 + lVar7 + 0x38) & 3) != 0))) {
        StorPortStallExecution(10);
        uVar10 = uVar10 + 1;
      }
    }
    uVar12 = 0;
    bVar8 = (char)uVar9 + 1;
    uVar9 = (uint)bVar8;
    piVar11 = piVar11 + 2;
  } while (bVar8 < 4);
  puVar5 = (undefined1 *)(param_1 + 0x4828);
  puVar14 = (ushort *)(param_1 + 0xab8);
  piVar11 = piVar17;
  do {
    if ((*piVar11 == 0) && ((puVar5[-0x3ee0] & 4) != 0)) {
      if ((*puVar14 & 1) == 0) {
        lVar7 = ((longlong)(int)(uVar12 & 3) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
        uVar2 = *(undefined4 *)(lVar7 + 0x24);
        cVar13 = (char)((uint)uVar2 >> 0x10);
        cVar3 = (char)((uint)uVar2 >> 0x18);
        if (((cVar13 == '\x14') && (cVar3 == -0x15)) || ((cVar13 == 'i' && (cVar3 == -0x6a)))) {
          *piVar11 = 1;
          cVar3 = *(char *)(lVar7 + 0x20);
          goto LAB_00017b78;
        }
      }
      else if ((*puVar14 & 2) != 0) {
        *piVar11 = 1;
        cVar3 = *(char *)((longlong)(int)(uVar12 & 3) * 0x80 + 0x120 + *(longlong *)(param_1 + 0x58)
                         );
LAB_00017b78:
        if (cVar3 < '\0') {
          *puVar5 = 1;
        }
      }
    }
    bVar8 = (char)uVar12 + 1;
    uVar12 = (uint)bVar8;
    puVar14 = puVar14 + 2;
    piVar11 = piVar11 + 2;
    puVar5 = puVar5 + 2;
    if (3 < bVar8) {
      uVar10 = 0;
      do {
        lVar7 = *(longlong *)(param_1 + 0x58);
        lVar6 = ((longlong)(int)(uVar10 & 0x80000003) + 2) * 0x80 + lVar7;
        if (*piVar17 == 0) {
          sVar4 = (sbyte)(uVar10 & 0x80000003);
          if (*(char *)(lVar6 + 0x20) < '\0') {
            *(undefined4 *)(lVar6 + 0x30) = 0xffffffff;
            *(undefined4 *)(lVar6 + 0x10) = 0xffffffff;
            *(int *)(lVar7 + 8) = 1 << sVar4;
            *(undefined4 *)(lVar6 + 0x14) = 0xffffffff;
            AhciResetPort(param_1,uVar10,'\0');
          }
          else {
            *piVar17 = 1;
            *(undefined4 *)(lVar6 + 0x30) = 0xffffffff;
            *(undefined4 *)(lVar6 + 0x10) = 0xffffffff;
            *(int *)(lVar7 + 8) = 1 << sVar4;
            *(undefined4 *)(lVar6 + 0x14) = 0xffffffff;
          }
        }
        bVar8 = (char)uVar10 + 1;
        uVar10 = (uint)bVar8;
        piVar17 = piVar17 + 2;
      } while (bVar8 < 4);
      return 99999 < uVar15;
    }
  } while( true );
}



===== SpecialSataResetPortCheckStatus @ 00017c90 =====

bool SpecialSataResetPortCheckStatus(longlong param_1,byte param_2,undefined8 param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  char cVar3;
  char cVar4;
  short sVar5;
  uint uVar6;
  int *piVar7;
  ulonglong uVar8;
  char cVar9;
  undefined1 *puVar10;
  undefined2 uVar11;
  ulonglong uVar12;
  ushort *puVar13;
  byte *pbVar14;
  byte bVar15;
  bool bVar16;
  ulonglong local_res18;
  
  uVar8 = 1;
  bVar16 = false;
  if (param_2 < 8) {
    uVar12 = (ulonglong)param_2;
    piVar7 = (int *)(param_1 + 0x4808 + uVar12 * 4);
    bVar15 = param_2;
    do {
      if (*piVar7 == 0) {
        if ((*(byte *)(param_1 + 0x948 + uVar12) & 2) == 0) {
          param_3 = *(undefined8 *)(param_1 + 0xa0 + (uVar12 >> 1) * 8);
          sVar5 = (short)param_3 + 6;
          cVar4 = (bVar15 & 1 | 0xfa) * '\x10';
          out(sVar5,cVar4);
          cVar3 = in(sVar5);
          if (cVar3 == cVar4) {
            sVar5 = (short)param_3 + 2;
            param_3 = CONCAT62((int6)((ulonglong)param_3 >> 0x10),sVar5);
            out(sVar5,0x55);
            cVar3 = in(sVar5);
            if (cVar3 == 'U') {
              out(sVar5,0xaa);
              cVar3 = in(sVar5);
              if (cVar3 == -0x56) goto LAB_00017d47;
            }
          }
        }
        else {
          ReadWriteHostSStatusRegister(param_1,(uint)bVar15,param_3,(uint *)&local_res18);
          piVar7[-0x11c2] = (int)local_res18;
          if ((local_res18 & 0xf) != 0) goto LAB_00017d47;
        }
        *piVar7 = 1;
      }
LAB_00017d47:
      bVar15 = bVar15 + 2;
      uVar12 = uVar12 + 2;
      piVar7 = piVar7 + 2;
    } while (bVar15 < 8);
  }
  uVar6 = 0;
  if (param_2 < 8) {
    uVar12 = (ulonglong)param_2;
    piVar7 = (int *)(param_1 + 0x4808 + uVar12 * 4);
    bVar15 = param_2;
    do {
      if (*piVar7 == 0) {
        out((short)*(undefined8 *)(param_1 + 0xa0 + (uVar12 >> 1) * 8) + 6,(bVar15 & 1 | 0xfa) << 4)
        ;
        uVar11 = (undefined2)*(undefined8 *)(param_1 + 0xc0 + (uVar12 >> 1) * 8);
        cVar3 = in(uVar11);
        if (cVar3 < '\0') {
          while ((uVar6 < 300000 && (cVar3 = in(uVar11), cVar3 < '\0'))) {
            StorPortStallExecution(10);
            uVar6 = uVar6 + 1;
          }
        }
      }
      bVar15 = bVar15 + 2;
      uVar12 = uVar12 + 2;
      piVar7 = piVar7 + 2;
    } while (bVar15 < 8);
    bVar16 = 199999 < uVar6;
  }
  if (param_2 < 8) {
    uVar12 = (ulonglong)param_2;
    piVar7 = (int *)(param_1 + 0x4808 + uVar12 * 4);
    bVar15 = param_2;
    do {
      if (*piVar7 == 0) {
        uVar1 = *(undefined8 *)(param_1 + 0xa0 + (uVar12 >> 1) * 8);
        uVar2 = *(ulonglong *)(param_1 + 0xc0 + (uVar12 >> 1) * 8);
        uVar11 = (undefined2)uVar2;
        cVar3 = in(uVar11);
        if (cVar3 < '\0') {
          cVar3 = (bVar15 & 1 | 0xfa) << 4;
          sVar5 = (short)uVar1 + 6;
          local_res18 = CONCAT62((int6)((ulonglong)uVar1 >> 0x10),sVar5);
          out(sVar5,cVar3);
          out(uVar11,4);
          StorPortStallExecution(99,uVar2 & 0xffff);
          out(uVar11,0);
          StorPortStallExecution(0x14,uVar2 & 0xffff);
          out((undefined2)local_res18,cVar3);
        }
        else {
          *piVar7 = 1;
        }
      }
      bVar15 = bVar15 + 2;
      uVar12 = uVar12 + 2;
      piVar7 = piVar7 + 2;
    } while (bVar15 < 8);
  }
  uVar6 = 0;
  if (param_2 < 8) {
    uVar12 = (ulonglong)param_2;
    piVar7 = (int *)(param_1 + 0x4808 + uVar12 * 4);
    bVar15 = param_2;
    do {
      if (*piVar7 == 0) {
        out((short)*(undefined8 *)(param_1 + 0xa0 + (uVar12 >> 1) * 8) + 6,(bVar15 & 1 | 0xfa) << 4)
        ;
        uVar11 = (undefined2)*(undefined8 *)(param_1 + 0xc0 + (uVar12 >> 1) * 8);
        cVar3 = in(uVar11);
        if (cVar3 < '\0') {
          bVar16 = true;
          while ((uVar6 < 300000 && (cVar3 = in(uVar11), cVar3 < '\0'))) {
            StorPortStallExecution(10);
            uVar6 = uVar6 + 1;
          }
        }
        else {
          *piVar7 = 1;
        }
      }
      bVar15 = bVar15 + 2;
      uVar12 = uVar12 + 2;
      piVar7 = piVar7 + 2;
    } while (bVar15 < 8);
  }
  if (param_2 < 8) {
    uVar12 = (ulonglong)param_2;
    puVar10 = (undefined1 *)(param_1 + 0x4828 + uVar12);
    piVar7 = (int *)(param_1 + 0x4808 + uVar12 * 4);
    puVar13 = (ushort *)(param_1 + (uVar12 + 0x55c) * 2);
    bVar15 = param_2;
    do {
      if ((*piVar7 == 0) && ((puVar10[-0x3ee0] & 2) != 0)) {
        if ((*puVar13 & 1) == 0) {
          sVar5 = (short)*(undefined8 *)
                          (param_1 + 0xa0 + ((ulonglong)(puVar10 + (-0x4828 - param_1)) >> 1) * 8);
          cVar9 = (bVar15 & 1 | 0xfa) << 4;
          out(sVar5 + 6,cVar9);
          cVar3 = in(sVar5 + 4);
          cVar4 = in(sVar5 + 5);
          out(sVar5 + 6,cVar9);
          if (((cVar3 == '\x14') && (cVar4 == -0x15)) || ((cVar3 == 'i' && (cVar4 == -0x6a)))) {
            *piVar7 = 1;
            *puVar10 = 1;
          }
        }
        else if ((*puVar13 & 2) != 0) {
          *piVar7 = 1;
          *puVar10 = 1;
        }
      }
      bVar15 = bVar15 + 2;
      puVar13 = puVar13 + 2;
      piVar7 = piVar7 + 2;
      puVar10 = puVar10 + 2;
    } while (bVar15 < 8);
  }
  if (param_2 < 8) {
    uVar12 = (ulonglong)param_2;
    piVar7 = (int *)(param_1 + 0x4808 + uVar12 * 4);
    bVar15 = param_2;
    do {
      if (*piVar7 == 0) {
        cVar4 = (bVar15 & 1 | 0xfa) << 4;
        sVar5 = (short)*(undefined8 *)(param_1 + 0xa0 + (uVar12 >> 1) * 8) + 6;
        out(sVar5,cVar4);
        cVar3 = in((short)*(undefined8 *)(param_1 + 0xc0 + (uVar12 >> 1) * 8));
        out(sVar5,cVar4);
        if (-1 < cVar3) {
          *piVar7 = 1;
        }
      }
      bVar15 = bVar15 + 2;
      uVar12 = uVar12 + 2;
      piVar7 = piVar7 + 2;
    } while (bVar15 < 8);
  }
  bVar15 = param_2;
  if (param_2 < 8) {
    do {
      if (*(int *)(param_1 + 0x4808 + (ulonglong)bVar15 * 4) == 0) break;
      bVar15 = bVar15 + 2;
    } while (bVar15 < 8);
    if (bVar15 < 8) {
      *(undefined1 *)(((ulonglong)param_2 & 1) + 0x951 + param_1) = 0;
      goto LAB_000180f2;
    }
  }
  *(undefined1 *)(((ulonglong)param_2 & 1) + 0x951 + param_1) = 1;
LAB_000180f2:
  if ((*(int *)(param_1 + 0x4838) < 2) && (*(char *)(param_1 + 0x951) == '\0')) {
    uVar8 = 0;
  }
  if ((byte)uVar8 < 8) {
    piVar7 = (int *)(param_1 + 0x4808 + uVar8 * 4);
    pbVar14 = (byte *)(param_1 + 0x948 + uVar8);
    do {
      if ((*piVar7 == 0) && ((*pbVar14 & 2) != 0)) {
        CommReset_for_PM(param_1,(uint)uVar8);
      }
      bVar15 = (char)uVar8 + 2;
      uVar8 = (ulonglong)bVar15;
      piVar7 = piVar7 + 2;
      pbVar14 = pbVar14 + 2;
    } while (bVar15 < 8);
  }
  return bVar16;
}



===== SataResetPortCheckStatus @ 00018168 =====

undefined1 SataResetPortCheckStatus(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong uVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  ulonglong uVar6;
  byte bVar7;
  longlong lVar8;
  undefined1 *puVar9;
  ushort *puVar10;
  undefined2 uVar11;
  short sVar12;
  uint uVar13;
  int *piVar14;
  uint local_res8 [2];
  
  piVar14 = (int *)(param_1 + 0x4808);
  uVar4 = 0;
  uVar6 = 0;
  piVar5 = piVar14;
  do {
    if (*piVar5 == 0) {
      if ((*(byte *)(param_1 + 0x948 + uVar6) & 2) == 0) {
        param_3 = *(undefined8 *)(param_1 + 0xa0 + (uVar6 >> 1) * 8);
        sVar12 = (short)param_3 + 6;
        cVar3 = ((byte)uVar4 & 1 | 0xfa) * '\x10';
        out(sVar12,cVar3);
        cVar2 = in(sVar12);
        if (cVar2 == cVar3) {
          sVar12 = (short)param_3 + 2;
          param_3 = CONCAT62((int6)((ulonglong)param_3 >> 0x10),sVar12);
          out(sVar12,0x55);
          cVar2 = in(sVar12);
          if (cVar2 == 'U') {
            out(sVar12,0xaa);
            cVar2 = in(sVar12);
            if (cVar2 == -0x56) goto LAB_00018223;
          }
        }
        *piVar5 = 1;
      }
      else {
        ReadWriteHostSStatusRegister(param_1,uVar4,param_3,local_res8);
        piVar5[-0x11c2] = local_res8[0];
        if ((local_res8[0] & 0xf) == 0) {
          *piVar5 = 1;
        }
      }
    }
LAB_00018223:
    bVar7 = (byte)uVar4 + 1;
    uVar4 = (uint)bVar7;
    uVar6 = uVar6 + 1;
    piVar5 = piVar5 + 1;
    if (7 < bVar7) {
      uVar4 = 0;
      bVar7 = 0;
      uVar6 = 0;
      piVar5 = piVar14;
      do {
        if (*piVar5 == 0) {
          out((short)*(undefined8 *)(param_1 + 0xa0 + (uVar6 >> 1) * 8) + 6,(bVar7 & 1 | 0xfa) << 4)
          ;
          uVar11 = (undefined2)*(undefined8 *)(param_1 + 0xc0 + (uVar6 >> 1) * 8);
          cVar2 = in(uVar11);
          if (cVar2 < '\0') {
            while ((uVar4 < 300000 && (cVar2 = in(uVar11), cVar2 < '\0'))) {
              StorPortStallExecution();
              uVar4 = uVar4 + 1;
            }
          }
        }
        bVar7 = bVar7 + 1;
        uVar6 = uVar6 + 1;
        piVar5 = piVar5 + 1;
      } while (bVar7 < 8);
      bVar7 = 0;
      local_res8[0] = (uint)(199999 < uVar4);
      uVar6 = 0;
      piVar5 = piVar14;
      do {
        if (*piVar5 == 0) {
          uVar1 = *(ulonglong *)(param_1 + 0xc0 + (uVar6 >> 1) * 8);
          uVar11 = (undefined2)uVar1;
          cVar2 = in(uVar11);
          if (cVar2 < '\0') {
            cVar2 = (bVar7 & 1 | 0xfa) << 4;
            sVar12 = (short)*(undefined8 *)(param_1 + 0xa0 + (uVar6 >> 1) * 8) + 6;
            out(sVar12,cVar2);
            out(uVar11,4);
            StorPortStallExecution(99,uVar1 & 0xffff);
            out(uVar11,0);
            StorPortStallExecution(0x14,uVar1 & 0xffff);
            out(sVar12,cVar2);
          }
          else {
            *piVar5 = 1;
          }
        }
        bVar7 = bVar7 + 1;
        uVar6 = uVar6 + 1;
        piVar5 = piVar5 + 1;
      } while (bVar7 < 8);
      uVar4 = 0;
      bVar7 = 0;
      uVar6 = 0;
      piVar5 = piVar14;
      uVar13 = local_res8[0];
      do {
        if (*piVar5 == 0) {
          out((short)*(undefined8 *)(param_1 + 0xa0 + (uVar6 >> 1) * 8) + 6,(bVar7 & 1 | 0xfa) << 4)
          ;
          uVar11 = (undefined2)*(undefined8 *)(param_1 + 0xc0 + (uVar6 >> 1) * 8);
          cVar2 = in(uVar11);
          if (cVar2 < '\0') {
            uVar13 = 1;
            while ((uVar4 < 300000 && (cVar2 = in(uVar11), cVar2 < '\0'))) {
              StorPortStallExecution();
              uVar4 = uVar4 + 1;
            }
          }
          else {
            *piVar5 = 1;
          }
        }
        bVar7 = bVar7 + 1;
        uVar6 = uVar6 + 1;
        piVar5 = piVar5 + 1;
      } while (bVar7 < 8);
      lVar8 = 8;
      puVar9 = (undefined1 *)(param_1 + 0x4828);
      puVar10 = (ushort *)(param_1 + 0xab8);
      piVar5 = piVar14;
      do {
        if ((*piVar5 == 0) && ((puVar9[-0x3ee0] & 2) != 0)) {
          if ((*puVar10 & 1) == 0) {
            sVar12 = (short)*(undefined8 *)
                             (param_1 + 0xa0 + ((ulonglong)(puVar9 + (-0x4828 - param_1)) >> 1) * 8)
            ;
            cVar2 = in(sVar12 + 4);
            cVar3 = in(sVar12 + 5);
            if (((cVar2 == '\x14') && (cVar3 == -0x15)) || ((cVar2 == 'i' && (cVar3 == -0x6a)))) {
              *piVar5 = 1;
              *puVar9 = 1;
            }
          }
          else if ((*puVar10 & 2) != 0) {
            *piVar5 = 1;
            *puVar9 = 1;
          }
        }
        puVar10 = puVar10 + 1;
        piVar5 = piVar5 + 1;
        puVar9 = puVar9 + 1;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      bVar7 = 0;
      uVar6 = 0;
      do {
        if (*piVar14 == 0) {
          out((short)*(undefined8 *)(param_1 + 0xa0 + (uVar6 >> 1) * 8) + 6,(bVar7 & 1 | 0xfa) << 4)
          ;
          cVar2 = in((short)*(undefined8 *)(param_1 + 0xc0 + (uVar6 >> 1) * 8));
          if (cVar2 < '\0') {
            if ((*(byte *)(uVar6 + 0x948 + param_1) & 2) != 0) {
              CommReset_for_PM(param_1,(uint)bVar7);
            }
          }
          else {
            *piVar14 = 1;
          }
        }
        bVar7 = bVar7 + 1;
        uVar6 = uVar6 + 1;
        piVar14 = piVar14 + 1;
      } while (bVar7 < 8);
      return (char)uVar13;
    }
  } while( true );
}



===== AhciRestartAdapterCallBack @ 00018520 =====

void AhciRestartAdapterCallBack(longlong param_1,undefined8 param_2,longlong param_3)

{
  bool bVar1;
  int *piVar2;
  longlong lVar3;
  
  *(undefined1 *)(param_1 + 0x62) = 0;
  *(undefined8 *)(param_1 + 0x47f8) = 0;
  *(undefined8 *)(param_1 + 0x4800) = 0;
  bVar1 = AhciResetPortCheckStatus(param_1);
  lVar3 = 0;
  piVar2 = (int *)(param_1 + 0x4808);
  do {
    if (*piVar2 == 0) {
      *(int *)(param_1 + 0x4838) = *(int *)(param_1 + 0x4838) + 1;
      if (*(int *)(param_1 + 0x4838) < 4) goto LAB_000185a1;
      goto LAB_00018561;
    }
    lVar3 = lVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (lVar3 < 8);
  if (bVar1) {
LAB_000185a1:
    StorPortNotification(6,param_1,AhciRestartAdapterCallBack,1000000,0xffffffff);
    return;
  }
LAB_00018561:
  *(undefined4 *)(param_1 + 0x4838) = 0;
  CheckSleeptimeHotplug(param_1,lVar3,param_3);
  if (*(char *)(param_1 + 0x14b8) != '\0') {
    *(undefined1 *)(param_1 + 0x14b9) = 1;
  }
  if (*(char *)(param_1 + 0x4830) == '\0') {
    AhciResumeSetAllFeature(param_1,lVar3,param_3);
  }
  else {
    *(undefined1 *)(param_1 + 0x4830) = 0;
  }
  *(undefined4 *)(param_1 + 0x4834) = 0;
  *(undefined1 *)(param_1 + 0x61) = 0;
  if (*(char *)(param_1 + 0x14b6) == '\0') {
    StorPortNotification(6,param_1,AtapiScsiTimer,15000000,0xffffffff);
  }
                    /* WARNING: Could not recover jumptable at 0x0001860b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortResume(param_1);
  return;
}



===== SpecialSataRestartAdapterCallBack @ 00018614 =====

void SpecialSataRestartAdapterCallBack(longlong param_1,ulonglong param_2,ulonglong param_3)

{
  bool bVar1;
  int *piVar2;
  ushort *puVar3;
  longlong lVar4;
  byte *pbVar5;
  ulonglong *puVar6;
  
  *(undefined1 *)(param_1 + 0x62) = 0;
  if ((2 < *(int *)(param_1 + 0x4838)) ||
     (param_2 = param_2 & 0xffffffffffffff00, *(char *)(param_1 + 0x951) != '\0')) {
    param_2 = CONCAT71((int7)(param_2 >> 8),1);
  }
  bVar1 = SpecialSataResetPortCheckStatus(param_1,(byte)param_2,param_3);
  if (*(char *)(param_1 + 0x952) == '\0') {
    *(int *)(param_1 + 0x4838) = *(int *)(param_1 + 0x4838) + 1;
    if (4 < *(int *)(param_1 + 0x4838)) {
      lVar4 = 8;
      piVar2 = (int *)(param_1 + 0x4808);
      puVar3 = (ushort *)(param_1 + 0xab8);
      do {
        if (*piVar2 == 0) {
          *puVar3 = *puVar3 | 0x2000;
          *piVar2 = 1;
        }
        puVar3 = puVar3 + 1;
        piVar2 = piVar2 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
  }
  else if (!bVar1) {
    *(undefined4 *)(param_1 + 0x4838) = 0;
    GetPRDTablePointer(param_1);
    lVar4 = 4;
    puVar6 = (ulonglong *)(param_1 + 0xc0);
    pbVar5 = (byte *)(param_1 + 0x948);
    do {
      if (((*pbVar5 & 1) != 0) || ((*pbVar5 & 2) != 0)) {
        param_2 = *puVar6;
        out((short)param_2,0);
        StorPortStallExecution(99);
      }
      puVar6 = puVar6 + 1;
      pbVar5 = pbVar5 + 2;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    CheckSleeptimeHotplug(param_1,param_2,param_3);
    if (*(char *)(param_1 + 0x14b8) == '\0') {
      *(undefined1 *)(param_1 + 0x14b6) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x14b9) = 1;
    }
    if (*(char *)(param_1 + 0x4830) == '\0') {
      *(undefined1 *)(param_1 + 0x953) = 0;
      SpecialSataResumeSetAllFeature(param_1,param_2,param_3);
      return;
    }
    *(undefined1 *)(param_1 + 0x4830) = 0;
    *(undefined4 *)(param_1 + 0x4834) = 0;
    *(undefined1 *)(param_1 + 0x61) = 0;
    if ((*(char *)(param_1 + 0x14b6) == '\0') && (*(int *)(param_1 + 0x90) != 2)) {
      StorPortNotification(6,param_1,AtapiScsiTimer,15000000,0xffffffff);
    }
    StorPortResume(param_1);
    return;
  }
  StorPortNotification(6,param_1,SpecialSataRestartAdapterCallBack,1000000,0xffffffff);
  return;
}



===== SataRestartAdapterCallBack @ 000187b4 =====

void SataRestartAdapterCallBack(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  ushort *puVar2;
  int *piVar3;
  int *piVar4;
  longlong lVar5;
  byte *pbVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  
  *(undefined1 *)(param_1 + 0x62) = 0;
  cVar1 = SataResetPortCheckStatus(param_1,param_2,param_3);
  lVar8 = 0;
  piVar3 = (int *)(param_1 + 0x4808);
  lVar7 = 4;
  lVar5 = 8;
  piVar4 = piVar3;
  do {
    if (*piVar4 == 0) {
      *(int *)(param_1 + 0x4838) = *(int *)(param_1 + 0x4838) + 1;
      if (3 < *(int *)(param_1 + 0x4838)) {
        puVar2 = (ushort *)(param_1 + 0xab8);
        do {
          if (*piVar3 == 0) {
            *puVar2 = *puVar2 | 0x2000;
            *piVar3 = 1;
          }
          puVar2 = puVar2 + 1;
          piVar3 = piVar3 + 1;
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
      }
      goto LAB_00018902;
    }
    lVar8 = lVar8 + 1;
    piVar4 = piVar4 + 1;
  } while (lVar8 < 8);
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0x4838) = 0;
    GetPRDTablePointer(param_1);
    puVar9 = (undefined8 *)(param_1 + 0xc0);
    pbVar6 = (byte *)(param_1 + 0x948);
    do {
      if (((*pbVar6 & 1) != 0) || ((*pbVar6 & 2) != 0)) {
        piVar4 = (int *)*puVar9;
        out((short)piVar4,0);
        StorPortStallExecution(99);
      }
      puVar9 = puVar9 + 1;
      pbVar6 = pbVar6 + 2;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    CheckSleeptimeHotplug(param_1,piVar4,lVar8);
    if (*(char *)(param_1 + 0x14b8) == '\0') {
      *(undefined1 *)(param_1 + 0x14b6) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x14b9) = 1;
    }
    if (*(char *)(param_1 + 0x4830) == '\0') {
      SataResumeSetAllFeature(param_1);
    }
    else {
      *(undefined1 *)(param_1 + 0x4830) = 0;
    }
    *(undefined4 *)(param_1 + 0x4834) = 0;
    *(undefined1 *)(param_1 + 0x61) = 0;
    if ((*(char *)(param_1 + 0x14b6) == '\0') && (*(int *)(param_1 + 0x90) != 2)) {
      StorPortNotification(6,param_1,AtapiScsiTimer,15000000,0xffffffff);
    }
    StorPortResume(param_1);
  }
  else {
LAB_00018902:
    StorPortNotification(6,param_1,SataRestartAdapterCallBack,1000000,0xffffffff);
  }
  return;
}



===== AhciPowerResetPort @ 00018940 =====

void AhciPowerResetPort(longlong param_1,uint param_2,char param_3)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  
  uVar2 = param_2 & 0x80000003;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
  }
  lVar1 = *(longlong *)(param_1 + 0x58);
  lVar6 = 2;
  iVar4 = 1 << ((byte)uVar2 & 0x1f);
  lVar3 = ((longlong)(int)uVar2 + 2) * 0x80 + lVar1;
  *(undefined4 *)(lVar3 + 0x14) = 0;
  *(undefined4 *)(lVar3 + 0x30) = 0xffffffff;
  *(undefined4 *)(lVar3 + 0x10) = 0xffffffff;
  *(int *)(lVar1 + 8) = iVar4;
  *(uint *)(lVar3 + 0x18) = *(uint *)(lVar3 + 0x18) & 0xffffffee;
  uVar2 = *(uint *)(lVar3 + 0x18);
  if ((param_3 == '\0') || ((uVar2 & 2) != 0)) {
    *(uint *)(lVar3 + 0x2c) = *(uint *)(lVar3 + 0x2c) | 1;
    lVar5 = 2;
    *(uint *)(lVar3 + 0x18) = uVar2 | 0x10;
    do {
      StorPortStallExecution(1000);
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    StorPortStallExecution(0);
    *(uint *)(lVar3 + 0x2c) = *(uint *)(lVar3 + 0x2c) & 0xfffffffe;
    do {
      StorPortStallExecution(1000);
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    StorPortStallExecution(0);
  }
  else {
    *(uint *)(lVar3 + 0x18) = uVar2 | 2;
  }
  *(undefined4 *)(lVar3 + 0x30) = 0xffffffff;
  *(undefined4 *)(lVar3 + 0x10) = 0xffffffff;
  *(int *)(lVar1 + 8) = iVar4;
  *(undefined4 *)(lVar3 + 0x14) = 0xffffffff;
  return;
}



===== AhciPowerRestartAdapter @ 00018a1c =====

void AhciPowerRestartAdapter(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  longlong lVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x58);
  uVar6 = 0;
  *(undefined4 *)(param_1 + 0x4834) = 1;
  *(undefined8 *)(param_1 + 0x47f8) = 0;
  *(undefined8 *)(param_1 + 0x4800) = 0;
  puVar3 = (undefined8 *)(param_1 + 0x4808);
  pbVar5 = (byte *)(param_1 + 0x948);
  lVar7 = 8;
  *puVar3 = 0;
  *(undefined8 *)(param_1 + 0x4810) = 0;
  *(undefined8 *)(param_1 + 0x4818) = 0;
  *(undefined8 *)(param_1 + 0x4820) = 0;
  pbVar4 = pbVar5;
  do {
    if ((*pbVar4 & 4) == 0) {
      *(undefined4 *)puVar3 = 1;
    }
    puVar3 = (undefined8 *)((longlong)puVar3 + 4);
    pbVar4 = pbVar4 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  uVar1 = *(uint *)(lVar2 + 4);
  if ((int)uVar1 < 0) {
    *(uint *)(lVar2 + 4) = uVar1 | 2;
  }
  else {
    AhciInitCtler(param_1);
  }
  do {
    if ((*pbVar5 & 4) != 0) {
      AhciResetPort(param_1,uVar6,'\0');
    }
    uVar6 = uVar6 + 1;
    pbVar5 = pbVar5 + 2;
  } while (uVar6 < 4);
  *(undefined4 *)(param_1 + 0x4838) = 1;
  StorPortPause(param_1,0x14);
  StorPortNotification(6,param_1,AhciRestartAdapterCallBack,1000000,0xffffffff);
  return;
}



===== PowerRestartAdapter @ 00018b08 =====

void PowerRestartAdapter(longlong param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  uint uVar5;
  byte *pbVar6;
  longlong lVar7;
  code *pcVar8;
  
  *(undefined4 *)(param_1 + 0x4834) = 1;
  *(undefined8 *)(param_1 + 0x47f8) = 0;
  *(undefined8 *)(param_1 + 0x4800) = 0;
  puVar4 = (undefined4 *)(param_1 + 0x4808);
  puVar1 = (undefined1 *)(param_1 + 0x4828);
  lVar7 = 8;
  puVar2 = puVar4;
  do {
    *puVar2 = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  pbVar6 = (byte *)(param_1 + 0x948);
  lVar7 = 8;
  pbVar3 = pbVar6;
  do {
    if ((*pbVar3 & 3) == 0) {
      *puVar4 = 1;
    }
    puVar4 = puVar4 + 1;
    pbVar3 = pbVar3 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  uVar5 = 0;
  if (*(char *)(param_1 + 0x950) == '\0') {
    do {
      if ((*pbVar6 & 2) != 0) {
        CommReset_for_PM(param_1,uVar5);
      }
      uVar5 = uVar5 + 1;
      pbVar6 = pbVar6 + 1;
    } while (uVar5 < 8);
  }
  else {
    do {
      if ((*pbVar6 & 2) != 0) {
        CommReset_for_PM(param_1,uVar5);
      }
      uVar5 = uVar5 + 2;
      pbVar6 = pbVar6 + 2;
    } while (uVar5 < 8);
  }
  *(undefined4 *)(param_1 + 0x4838) = 1;
  StorPortPause(param_1,0x14);
  if (*(char *)(param_1 + 0x950) == '\0') {
    pcVar8 = SataRestartAdapterCallBack;
  }
  else {
    *(undefined2 *)(param_1 + 0x951) = 0;
    pcVar8 = SpecialSataRestartAdapterCallBack;
  }
  StorPortNotification(6,param_1,pcVar8,1000000,0xffffffff);
  return;
}



===== AtapiPnp @ 00018c28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AtapiPnp(longlong param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  ushort *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  longlong lVar9;
  undefined1 auStack_48 [32];
  int *local_28;
  undefined4 local_20;
  int local_18;
  undefined1 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  if (param_2 == 0) {
    local_18 = 0x10101;
    local_14 = 0;
    uVar8 = 5;
    if (*param_3 < 5) {
      uVar8 = *param_3;
    }
    if (uVar8 != 0) {
      memcpy(param_3 + 1,&local_18,(ulonglong)uVar8);
    }
  }
  else if (param_2 == 1) {
    puVar3 = (undefined4 *)(param_1 + 0xae0);
    lVar9 = 8;
    puVar6 = (ushort *)(param_1 + 0xab8);
    do {
      if (((*puVar6 & 1) != 0) && ((*puVar6 & 2) == 0)) {
        *puVar3 = 2;
      }
      puVar6 = puVar6 + 1;
      puVar3 = puVar3 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    *(undefined2 *)(param_1 + 0x61) = 0x101;
    if (*(char *)(param_1 + 0x14b8) != '\0') {
      *(undefined1 *)(param_1 + 0x14b9) = 0;
    }
    LookForCount = LookForCount + -1;
    *(uint *)(&StoppedController + (ulonglong)*(uint *)(param_1 + 0x98) * 4) =
         *(uint *)(param_1 + 0x98);
    iVar2 = *(int *)(param_1 + 0x20c);
    (&flg_StopAdapter)[*(uint *)(param_1 + 0x98)] = 1;
    if (((iVar2 == 0x33491106) && (Hibernate == '\0')) && (g_Raid5Exist == '\x01')) {
      iVar2 = *(int *)(param_1 + 0x21c);
      uVar4 = ReadConfigSpaceUCHAR(param_1,iVar2 + 0x77);
      WriteConfigSpaceUCHAR(param_1,iVar2 + 0x77,(byte)uVar4 | 1);
    }
    if (*(char *)(param_1 + 0x60) != '\0') {
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x58) + 4);
      *puVar1 = *puVar1 & 0xfffffffd;
    }
    *(undefined4 *)(param_1 + 0x90) = 1;
    StorClearSubCmd(param_1);
    StorClearLogicCmd(param_1);
    StorClearWaitLogicCmd(param_1,'\x01');
    puVar5 = (undefined1 *)(param_1 + 0x2dc);
    puVar7 = (undefined8 *)(param_1 + 0x47a8);
    puVar3 = (undefined4 *)(param_1 + 0x290);
    lVar9 = 8;
    do {
      *puVar3 = 0;
      *puVar7 = 0;
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
      puVar3 = puVar3 + 1;
      puVar7 = puVar7 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    *(undefined8 *)(param_1 + 0x2b0) = 0;
    *(undefined4 *)(param_1 + 0x280) = 0;
    *(undefined4 *)(param_1 + 0x2b8) = 0;
    *(undefined8 *)(param_1 + 0x288) = 0;
    *(undefined8 *)(param_1 + 0x47e8) = 0;
    *(undefined1 *)(param_1 + 0x254) = 0;
  }
  else if (param_2 == 2) {
    uVar8 = *(uint *)(param_1 + 0x21c);
    local_20 = 4;
    local_18 = 0;
    local_28 = &local_18;
    StorPortGetBusData(param_1,4,uVar8 >> 0x10 & 0xff,
                       ((uVar8 & 0xffffff00) >> 3 & 0xe0) + (uVar8 >> 0xb & 0x1f));
    *(undefined1 *)(param_1 + 0x62) = 0;
    *(uint *)(param_1 + 0x90) = -(uint)(local_18 != *(int *)(param_1 + 0x208)) & 2;
    RestoreConfigSpace(param_1);
    if (*(char *)(param_1 + 0x60) == '\0') {
      PowerRestartAdapter(param_1);
    }
    else {
      AhciPowerRestartAdapter(param_1);
    }
  }
  else if ((param_2 != 3) && (param_2 != 4)) {
    return 1;
  }
  return 0;
}



===== RemoveSubCmdFromChnl @ 00018e98 =====

ulonglong RemoveSubCmdFromChnl(longlong param_1,longlong *param_2)

{
  int *piVar1;
  byte bVar2;
  undefined8 in_RAX;
  ulonglong uVar3;
  ulonglong uVar4;
  
  bVar2 = *(byte *)((longlong)param_2 + 0x4e) >> 1;
  uVar3 = CONCAT71((int7)((ulonglong)in_RAX >> 8),bVar2);
  if (bVar2 < 4) {
    uVar4 = (ulonglong)bVar2;
    uVar3 = RemoveListEntry((longlong *)(param_1 + 0x2f8 + uVar4 * 8),param_2);
    if ((char)uVar3 != '\0') {
      piVar1 = (int *)(param_1 + 0x32c + uVar4 * 4);
      *piVar1 = *piVar1 + -1;
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffffffffffff00;
}



===== AhciDispatchDiskReadWrite @ 00018ed4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018f11) */

bool AhciDispatchDiskReadWrite(longlong param_1,longlong param_2)

{
  ushort uVar1;
  ushort uVar2;
  ulonglong uVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStackY_a8 [32];
  undefined1 local_78;
  byte local_77;
  byte local_76;
  char local_74;
  undefined1 local_73;
  undefined1 local_72;
  byte local_71;
  byte local_70;
  undefined2 local_6f;
  undefined1 local_6c;
  undefined1 local_6b;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  bVar5 = *(byte *)(param_2 + 0x4e);
  lVar9 = ((longlong)(int)(bVar5 >> 1 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  bVar4 = *(byte *)(lVar9 + 0x20);
  if ((char)bVar4 < '\0') {
    *(undefined4 *)(lVar9 + 0x14) = 0;
    AhciResetPort(param_1,(uint)(bVar5 >> 1),'\0');
    bVar4 = *(byte *)(lVar9 + 0x20);
    *(undefined4 *)(lVar9 + 0x14) = 0xffffffff;
    if ((char)bVar4 < '\0') goto LAB_00019121;
  }
  if ((((bVar4 & 0x40) != 0) && ((bVar4 & 1) == 0)) && ((bVar4 & 0x20) == 0)) {
    memset(&local_78,0,0x40);
    uVar7 = *(uint *)(param_2 + 0x40);
    local_77 = local_77 | 0x80;
    local_78 = 0x27;
    lVar9 = (ulonglong)bVar5 * 0xb8;
    if ((*(uint *)(lVar9 + 0x39c + param_1) & 0x10) == 0) {
      lVar8 = (ulonglong)bVar5 * 0xd4;
      uVar1 = *(ushort *)(lVar8 + 0xd20 + param_1);
      uVar2 = *(ushort *)(lVar8 + 0xd1a + param_1);
      local_6c = (undefined1)(*(int *)(param_2 + 0x58) + 0x1ffU >> 9);
      local_74 = (char)((ulonglong)uVar7 % (ulonglong)uVar1) + '\x01';
      uVar3 = (ulonglong)uVar7 / (ulonglong)((uint)uVar2 * (uint)uVar1);
      local_73 = (undefined1)uVar3;
      local_72 = (undefined1)(uVar3 >> 8);
      local_71 = (byte)(((ulonglong)uVar7 / (ulonglong)uVar1) % (ulonglong)uVar2) | 0xa0;
    }
    else {
      local_74 = (char)uVar7;
      local_73 = (undefined1)(uVar7 >> 8);
      local_72 = (undefined1)(uVar7 >> 0x10);
      bVar5 = (byte)(uVar7 >> 0x18);
      if ((*(uint *)(param_1 + 0x39c + lVar9) & 0x20) == 0) {
        local_6c = (undefined1)(*(int *)(param_2 + 0x58) + 0x1ffU >> 9);
        local_71 = bVar5 | 0xe0;
      }
      else {
        uVar7 = *(int *)(param_2 + 0x58) + 0x1ffU >> 9;
        local_6c = (undefined1)uVar7;
        local_6b = (undefined1)(uVar7 >> 8);
        if (*(int *)(param_2 + 0x38) == 0) {
          local_6f = 0;
        }
        else {
          local_6f = (undefined2)((ulonglong)*(undefined8 *)(param_2 + 0x40) >> 0x20);
        }
        local_71 = 0xe0;
        local_70 = bVar5;
      }
    }
    if ((*(uint *)(param_2 + 0x54) & 0x40) == 0) {
      if ((*(char *)(param_2 + 0x90) == '/') || (*(char *)(param_2 + 0x90) == -0x71)) {
        *(uint *)(param_2 + 0xb0) = *(uint *)(param_2 + 0xb0) | 1;
        local_76 = (byte)(*(uint *)(param_1 + 0x39c + lVar9) >> 4) & 2 | 0x40;
      }
      else {
        local_76 = (-((*(uint *)(param_1 + 0x39c + lVar9) & 0x20) != 0) & 0x6bU) - 0x36;
      }
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
      local_76 = (-((*(uint *)(param_1 + 0x39c + lVar9) & 0x20) != 0) & 0x5dU) - 0x38;
    }
    IssueAhciCommand(param_1,param_2,(uint *)&local_78,(uint *)0x0,'\x01',cVar6);
    return *(char *)(param_2 + 0x4b) == '\0';
  }
LAB_00019121:
  *(undefined1 *)(param_2 + 0x4b) = 4;
  return false;
}



===== AhciDispatchUserDiskVerify @ 0001914c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00019189) */

bool AhciDispatchUserDiskVerify(longlong param_1,longlong param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStackY_a8 [32];
  undefined1 local_78;
  byte local_77;
  byte local_76;
  char local_74;
  undefined1 local_73;
  undefined1 local_72;
  byte local_71;
  byte local_70;
  undefined2 local_6f;
  undefined1 local_6c;
  undefined1 local_6b;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  bVar6 = *(byte *)(param_2 + 0x4e);
  lVar9 = ((longlong)(int)(bVar6 >> 1 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  bVar5 = *(byte *)(lVar9 + 0x20);
  if ((char)bVar5 < '\0') {
    *(undefined4 *)(lVar9 + 0x14) = 0;
    AhciResetPort(param_1,(uint)(bVar6 >> 1),'\0');
    bVar5 = *(byte *)(lVar9 + 0x20);
    *(undefined4 *)(lVar9 + 0x14) = 0xffffffff;
    if ((char)bVar5 < '\0') goto LAB_00019348;
  }
  if ((((bVar5 & 0x40) != 0) && ((bVar5 & 1) == 0)) && ((bVar5 & 0x20) == 0)) {
    memset(&local_78,0,0x40);
    uVar7 = *(uint *)(param_2 + 0x40);
    local_77 = local_77 | 0x80;
    local_78 = 0x27;
    lVar9 = (ulonglong)bVar6 * 0xb8;
    uVar3 = *(uint *)(lVar9 + 0x39c + param_1);
    if ((uVar3 & 0x10) == 0) {
      lVar8 = (ulonglong)bVar6 * 0xd4;
      uVar1 = *(ushort *)(lVar8 + 0xd20 + param_1);
      uVar2 = *(ushort *)(lVar8 + 0xd1a + param_1);
      local_6c = (undefined1)(*(int *)(param_2 + 0x58) + 0x1ffU >> 9);
      local_74 = (char)((ulonglong)uVar7 % (ulonglong)uVar1) + '\x01';
      uVar4 = (ulonglong)uVar7 / (ulonglong)((uint)uVar2 * (uint)uVar1);
      local_73 = (undefined1)uVar4;
      local_72 = (undefined1)(uVar4 >> 8);
      local_71 = (byte)(((ulonglong)uVar7 / (ulonglong)uVar1) % (ulonglong)uVar2) | 0xa0;
    }
    else {
      local_74 = (char)uVar7;
      local_73 = (undefined1)(uVar7 >> 8);
      local_72 = (undefined1)(uVar7 >> 0x10);
      bVar6 = (byte)(uVar7 >> 0x18);
      if ((uVar3 & 0x20) == 0) {
        local_6c = (undefined1)(*(int *)(param_2 + 0x58) + 0x1ffU >> 9);
        local_71 = bVar6 | 0xe0;
      }
      else {
        uVar7 = *(int *)(param_2 + 0x58) + 0x1ffU >> 9;
        local_6c = (undefined1)uVar7;
        local_6b = (undefined1)(uVar7 >> 8);
        if (*(int *)(param_2 + 0x38) == 0) {
          local_6f = 0;
        }
        else {
          local_6f = (undefined2)((ulonglong)*(undefined8 *)(param_2 + 0x40) >> 0x20);
        }
        local_71 = 0xe0;
        local_70 = bVar6;
      }
    }
    *(uint *)(param_2 + 0xb0) = *(uint *)(param_2 + 0xb0) | 1;
    local_76 = (byte)(*(uint *)(lVar9 + 0x39c + param_1) >> 4) & 2 | 0x40;
    IssueAhciCommand(param_1,param_2,(uint *)&local_78,(uint *)0x0,'\x01','\0');
    return *(char *)(param_2 + 0x4b) == '\0';
  }
LAB_00019348:
  *(undefined1 *)(param_2 + 0x4b) = 4;
  return false;
}



===== AhciDispatchIdeTestUnitReady @ 00019374 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000193b4) */

undefined8 AhciDispatchIdeTestUnitReady(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 extraout_var_00;
  undefined7 extraout_var;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 auStackY_158 [32];
  undefined1 local_128 [48];
  undefined8 local_f8;
  byte local_da;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined4 local_84;
  undefined4 local_68;
  undefined1 local_61;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_158;
  bVar1 = *(byte *)(param_2 + 0x4e);
  lVar4 = ((longlong)(int)(bVar1 >> 1 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  *(undefined1 *)((ulonglong)(bVar1 >> 1) + 0x42dc + param_1) = 0;
  memset(&local_68,0,0x40);
  local_68._1_1_ = local_68._1_1_ | 0x80;
  local_f8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_68._0_1_ = 0x27;
  local_68._2_1_ = 0xda;
  local_61 = 0xa0;
  local_84 = 1;
  local_da = bVar1;
  uVar2 = IssueAhciCommand(param_1,(longlong)local_128,&local_68,(uint *)0x0,'\0','\0');
  uVar3 = CONCAT44(extraout_var_00,uVar2);
  if (((*(byte *)(lVar4 + 0x20) & 1) == 0) ||
     (uVar2 = *(uint *)(lVar4 + 0x20), uVar3 = (ulonglong)(uVar2 >> 8), (char)(uVar2 >> 8) == '@'))
  {
    *(undefined1 *)(param_2 + 0x4b) = 1;
  }
  else {
    bVar1 = AhciMapError(param_1,param_2 + 0x48);
    uVar3 = CONCAT71(extraout_var,bVar1);
    *(byte *)(param_2 + 0x4b) = bVar1;
  }
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== AhciDispatchPowerConditionChange @ 0001947c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AhciDispatchPowerConditionChange(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  undefined7 extraout_var;
  undefined4 extraout_var_00;
  undefined7 uVar5;
  undefined1 auStackY_168 [32];
  undefined1 local_138 [48];
  undefined8 local_108;
  undefined1 local_ed;
  byte local_ea;
  undefined4 local_e0;
  undefined8 local_d8;
  undefined4 local_94;
  undefined4 local_78;
  undefined1 local_71;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  bVar1 = *(byte *)(param_2 + 0x4e);
  uVar2 = *(undefined1 *)(param_2 + 0x90);
  if ((*(byte *)(*(longlong *)(param_2 + 0x10) + 0xea8 + (ulonglong)bVar1) & 1) != 0) {
    cVar3 = FlushCacheToHDD(param_1,bVar1,0,'\x01');
    if (cVar3 != '\0') {
      *(undefined1 *)(param_2 + 0x4b) = 0;
      uVar5 = extraout_var;
      goto LAB_00019546;
    }
  }
  *(undefined1 *)((ulonglong)(bVar1 >> 1) + 0x42dc + param_1) = 1;
  memset(&local_78,0,0x40);
  local_78._1_1_ = local_78._1_1_ | 0x80;
  local_108 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_78._0_1_ = 0x27;
  local_71 = 0xa0;
  local_94 = 1;
  local_ea = bVar1;
  local_78._2_1_ = uVar2;
  uVar4 = IssueAhciCommand(param_1,(longlong)local_138,&local_78,(uint *)0x0,'\x01','\0');
  uVar5 = (undefined7)(CONCAT44(extraout_var_00,uVar4) >> 8);
  *(undefined1 *)(param_2 + 0x4b) = local_ed;
LAB_00019546:
  return CONCAT71(uVar5,1);
}



===== AhciDispatchMediaEject @ 0001956c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AhciDispatchMediaEject(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 extraout_var;
  undefined1 auStackY_158 [32];
  undefined1 local_128 [48];
  undefined8 local_f8;
  char local_dd;
  byte local_da;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined4 local_84;
  undefined4 local_68;
  undefined1 local_61;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_158;
  bVar1 = *(byte *)(param_2 + 0x4e);
  *(undefined1 *)((ulonglong)(bVar1 >> 1) + 0x42dc + param_1) = 0;
  memset(&local_68,0,0x40);
  local_68._1_1_ = local_68._1_1_ | 0x80;
  local_f8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_68._0_1_ = 0x27;
  local_68._2_1_ = 0xed;
  local_61 = 0xa0;
  local_84 = 1;
  local_da = bVar1;
  uVar2 = IssueAhciCommand(param_1,(longlong)local_128,&local_68,(uint *)0x0,'\0','\0');
  *(char *)(param_2 + 0x4b) = local_dd;
  return CONCAT71((int7)(CONCAT44(extraout_var,uVar2) >> 8),local_dd == '\x01');
}



===== AhciFlushCacheToHDD @ 00019628 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00019699) */

ulonglong AhciFlushCacheToHDD(longlong param_1,byte param_2,undefined8 param_3,char param_4)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  uint7 uVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 auStackY_178 [32];
  undefined1 local_148 [48];
  undefined8 local_118;
  byte local_fa;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined4 local_a4;
  undefined4 local_88;
  undefined1 local_81;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_178;
  uVar2 = *(ushort *)(param_1 + 0xab8 + (longlong)(char)param_2 * 2);
  uVar4 = local_48;
  if (((uVar2 & 1) != 0) && ((uVar2 & 2) == 0)) {
    uVar4 = (longlong)(char)param_2 * 0xb8;
    uVar6 = 0;
    if (*(char *)(uVar4 + 0x399 + param_1) == '\0') {
      lVar7 = ((longlong)(int)(param_2 >> 1 & 0x80000003) + 2) * 0x80 +
              *(longlong *)(param_1 + 0x58);
      *(undefined1 *)((ulonglong)(param_2 >> 1) + 0x42dc + param_1) = 0;
      memset(&local_88,0,0x40);
      local_88._1_1_ = local_88._1_1_ | 0x80;
      local_88._0_1_ = 0x27;
      local_81 = 0xa0;
      local_a4 = 1;
      local_118 = 0;
      local_88._2_1_ =
           (-((*(byte *)((ulonglong)param_2 * 0xb8 + 0x39c + param_1) & 0x20) != 0) & 3U) - 0x19;
      local_f0 = 0;
      local_e8 = 0;
      local_fa = param_2;
      uVar3 = IssueAhciCommand(param_1,(longlong)local_148,&local_88,(uint *)0x0,param_4,'\0');
      uVar5 = (uint7)(CONCAT44(extraout_var,uVar3) >> 8);
      uVar4 = CONCAT71(uVar5,*(byte *)(lVar7 + 0x20));
      if ((*(byte *)(lVar7 + 0x20) & 1) != 0) {
        return (ulonglong)uVar5 << 8;
      }
      if (param_4 == '\0') {
        uVar3 = 0;
        do {
          uVar4 = CONCAT71((int7)(uVar4 >> 8),*(char *)(lVar7 + 0x20));
          if (-1 < *(char *)(lVar7 + 0x20)) break;
          uVar4 = StorPortStallExecution(0x96);
          uVar3 = uVar3 + 1;
        } while (uVar3 < 20000);
        do {
          bVar1 = *(byte *)(lVar7 + 0x20);
          if (-1 < (char)bVar1) break;
          uVar4 = StorPortStallExecution(0x96);
          uVar6 = uVar6 + 1;
        } while (uVar6 < 20000);
        return CONCAT71((int7)(uVar4 >> 8),~(bVar1 >> 7)) & 0xffffffffffffff01;
      }
      *(undefined1 *)((ulonglong)(param_2 >> 1) + 0x42dc + param_1) = 1;
    }
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== AhciMapError @ 000197bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00019808) */

byte AhciMapError(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  undefined1 *puVar6;
  byte bVar7;
  char cVar8;
  longlong lVar9;
  undefined1 auStackY_188 [32];
  undefined1 local_148 [48];
  undefined8 local_118;
  byte local_fa;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined4 local_a4;
  undefined1 local_88;
  byte local_87;
  undefined1 local_86;
  undefined1 local_81;
  undefined2 local_7c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  bVar2 = *(byte *)(param_2 + 6);
  bVar7 = 0;
  lVar9 = ((longlong)(int)(bVar2 >> 1 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  uVar5 = *(uint *)(lVar9 + 0x20);
  if ((*(byte *)(param_1 + 0xab8 + (ulonglong)bVar2 * 2) & 2) != 0) {
    uVar5 = (uVar5 >> 8 & 0xff) >> 4;
    if ((((uVar5 < 6) && (uVar5 != 5)) && (uVar5 != 0)) && (uVar5 == 1)) {
      cVar8 = '\0';
      bVar7 = 1;
    }
    else {
      bVar7 = 4;
      cVar8 = '\x02';
    }
    if (((*(uint *)(param_2 + 0xc) & 0x20) == 0) && (cVar8 != '\0')) {
      bVar7 = bVar7 | 0x80;
    }
    goto LAB_00019a87;
  }
  cVar8 = '\0';
  cVar4 = (char)(uVar5 >> 8);
  *(char *)(param_1 + 0x84 + (ulonglong)bVar2) = cVar4;
  if ((uVar5 & 0x800) == 0) {
    if ((uVar5 >> 8 & 4) == 0) {
      if ((uVar5 & 0x200) == 0) {
        if ((uVar5 & 0x100) == 0) {
          if (cVar4 < '\0') {
LAB_00019974:
            cVar8 = '\x02';
            bVar7 = 4;
            puVar6 = *(undefined1 **)(param_2 + 0x20);
            if (puVar6 != (undefined1 *)0x0) {
              *(undefined2 *)(puVar6 + 0xc) = 0;
              bVar7 = puVar6[2] & 0xf3 | 3;
LAB_00019989:
              cVar8 = '\x02';
              puVar6[2] = bVar7;
              puVar6[7] = 0xb;
              bVar7 = 0x84;
              *puVar6 = 0xf0;
            }
          }
          else {
            if ((uVar5 & 0x1000) != 0) {
              puVar6 = *(undefined1 **)(param_2 + 0x20);
              bVar7 = 4;
              if (puVar6 != (undefined1 *)0x0) {
                bVar7 = 0x84;
                bVar3 = puVar6[2] & 0xf3 | 3;
                goto LAB_00019915;
              }
              goto LAB_00019924;
            }
            if ((uVar5 & 0x2000) == 0) {
              if ((uVar5 & 0x4000) != 0) {
                if ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(param_2 + 6) * 2) & 0x20) == 0
                   ) {
                  piVar1 = (int *)(param_1 + 100 + (ulonglong)*(byte *)(param_2 + 6) * 4);
                  *piVar1 = *piVar1 + 1;
                }
                goto LAB_00019974;
              }
            }
            else {
              puVar6 = *(undefined1 **)(param_2 + 0x20);
              cVar8 = '\x02';
              bVar7 = 4;
              if (puVar6 != (undefined1 *)0x0) {
                *(undefined2 *)(puVar6 + 0xc) = 0x28;
                bVar7 = puVar6[2] & 0xf6 | 6;
                goto LAB_00019989;
              }
            }
          }
        }
        else {
          bVar7 = 6;
        }
      }
      else {
        cVar8 = '\x02';
        bVar7 = 4;
        if ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(param_2 + 6) * 2) & 0x20) == 0) {
          piVar1 = (int *)(param_1 + 100 + (ulonglong)*(byte *)(param_2 + 6) * 4);
          *piVar1 = *piVar1 + 1;
        }
      }
    }
    else {
      puVar6 = *(undefined1 **)(param_2 + 0x20);
      bVar7 = 2;
      if (puVar6 != (undefined1 *)0x0) {
        bVar7 = 0x82;
        bVar3 = puVar6[2] & 0xfb | 0xb;
LAB_00019915:
        *(undefined2 *)(puVar6 + 0xc) = 0;
        puVar6[2] = bVar3;
        puVar6[7] = 0xb;
        *puVar6 = 0xf0;
      }
LAB_00019924:
      cVar8 = '\x02';
      piVar1 = (int *)(param_1 + 100 + (ulonglong)*(byte *)(param_2 + 6) * 4);
      *piVar1 = *piVar1 + 1;
    }
  }
  else {
    cVar8 = '\x02';
    bVar7 = 4;
  }
  if (3 < *(uint *)(param_1 + 100 + (ulonglong)*(byte *)(param_2 + 6) * 4)) {
    *(undefined1 *)(param_1 + 0xb08 + (ulonglong)*(byte *)(param_2 + 6)) = 0;
    *(undefined1 *)((ulonglong)*(byte *)(param_2 + 6) + 0xb00 + param_1) = 0;
    StorPortLogError(param_1,param_2,*(undefined1 *)(param_2 + 5));
    if ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(param_2 + 6) * 2) & 1) != 0) {
      memset(&local_88,0,0x40);
      local_87 = local_87 | 0x80;
      local_88 = 0x27;
      local_86 = 0xc6;
      local_81 = 0xa0;
      local_7c = 0;
      local_a4 = 1;
      local_118 = 0;
      local_f0 = 0;
      local_e8 = 0;
      local_fa = bVar2;
      IssueAhciCommand(param_1,(longlong)local_148,(uint *)&local_88,(uint *)0x0,'\0','\0');
      uVar5 = 0;
      do {
        bVar2 = *(byte *)(lVar9 + 0x20);
        if (-1 < (char)bVar2) break;
        StorPortStallExecution(0x96);
        uVar5 = uVar5 + 1;
      } while (uVar5 < 20000);
      if ((bVar2 & 1) != 0) {
        *(undefined1 *)((ulonglong)*(byte *)(param_2 + 6) + 0xb00 + param_1) = 0;
      }
    }
  }
LAB_00019a87:
  *(char *)(param_2 + 4) = cVar8;
  return bVar7;
}



===== AhciInitCtler @ 00019ab4 =====

void AhciInitCtler(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  void *_Dst;
  undefined4 *puVar5;
  undefined8 *puVar6;
  uint *puVar7;
  longlong lVar8;
  byte *pbVar9;
  undefined4 local_res8 [2];
  uint *local_res10;
  uint *local_res18;
  longlong local_res20;
  
  if (*(char *)(param_1 + 0x60) != '\0') {
    local_res20 = *(longlong *)(param_1 + 0x58);
    if ((*(uint *)(local_res20 + 4) & 0x80000000) == 0) {
      *(uint *)(local_res20 + 4) = *(uint *)(local_res20 + 4) | 0x80000000;
    }
    *(uint *)(local_res20 + 4) = *(uint *)(local_res20 + 4) & 0xfffffffd;
    uVar4 = 0;
    puVar5 = (undefined4 *)(param_1 + 0x47f8);
    puVar6 = (undefined8 *)(param_1 + 0x38);
    pbVar9 = (byte *)(param_1 + 0x948);
    do {
      if ((*pbVar9 & 4) != 0) {
        local_res10 = *(uint **)(param_1 + 0x58);
        local_res8[0] = 0;
        uVar1 = uVar4 & 0x80000003;
        if ((int)uVar1 < 0) {
          uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;
        }
        puVar7 = local_res10 + ((longlong)(int)uVar1 + 2) * 0x20;
        puVar7[5] = 0;
        local_res18 = puVar7;
        AhciStopPort(param_1,uVar4);
        _Dst = (void *)*puVar6;
        memset(_Dst,0,0x1000);
        uVar2 = StorPortGetPhysicalAddress(param_1,0,_Dst,local_res8);
        *puVar7 = (uint)uVar2;
        puVar7[1] = (uint)((ulonglong)uVar2 >> 0x20);
        uVar2 = StorPortGetPhysicalAddress(param_1,0,(longlong)_Dst + 0x400,local_res8);
        puVar7[2] = (uint)uVar2;
        puVar3 = (undefined4 *)((longlong)_Dst + 0xc);
        puVar7[3] = (uint)((ulonglong)uVar2 >> 0x20);
        lVar8 = 2;
        do {
          _Dst = (void *)((longlong)_Dst + 0x500);
          uVar2 = StorPortGetPhysicalAddress(param_1,0,_Dst,local_res8);
          puVar7 = local_res18;
          puVar3[-1] = (int)uVar2;
          *puVar3 = (int)((ulonglong)uVar2 >> 0x20);
          puVar3 = puVar3 + 8;
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
        if (((*local_res10 >> 0x1b & 1) != 0) && ((local_res18[6] & 2) == 0)) {
          *puVar5 = 1;
          AhciResetPort(param_1,uVar4,'\x01');
        }
        puVar7[6] = puVar7[6] & 0xfbffffff;
        puVar7[0xb] = 0x300;
        puVar7[0xc] = 0xffffffff;
        puVar7[4] = 0xffffffff;
        puVar7[5] = 0xffffffff;
      }
      uVar4 = uVar4 + 1;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
      pbVar9 = pbVar9 + 2;
    } while ((int)uVar4 < 4);
    *(uint *)(local_res20 + 4) = *(uint *)(local_res20 + 4) | 2;
    *(undefined4 *)(local_res20 + 8) = 0xffffffff;
  }
  return;
}



===== AhciStopPort @ 00019c74 =====

void AhciStopPort(longlong param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  
  puVar1 = *(uint **)(param_1 + 0x58);
  uVar2 = param_2 & 0x80000003;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
  }
  lVar3 = (longlong)(int)uVar2 + 2;
  puVar1[lVar3 * 0x20 + 0xb] = puVar1[lVar3 * 0x20 + 0xb] & 0xfffffff0;
  puVar1[lVar3 * 0x20 + 6] = puVar1[lVar3 * 0x20 + 6] & 0xfffffffe;
  uVar6 = 0;
  uVar5 = 0;
  do {
    if ((puVar1[lVar3 * 0x20 + 6] & 0x8000) == 0) break;
    StorPortStallExecution(1000);
    StorPortStallExecution(0);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 500);
  puVar1[lVar3 * 0x20 + 6] = puVar1[lVar3 * 0x20 + 6] & 0xffffffef;
  do {
    if ((puVar1[lVar3 * 0x20 + 6] & 0x4000) == 0) break;
    StorPortStallExecution(1000);
    StorPortStallExecution(0);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 500);
  uVar5 = puVar1[lVar3 * 0x20 + 6];
  if (((uVar5 >> 0xf & 1) != 0) || ((uVar5 & 0x4000) != 0)) {
    if (((*puVar1 & 0x8000000) == 0) || ((uVar5 & 2) != 0)) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    AhciResetPort(param_1,param_2,cVar4);
  }
  puVar1[lVar3 * 0x20 + 0xc] = 0xffffffff;
  puVar1[lVar3 * 0x20 + 4] = 0xffffffff;
  puVar1[2] = 1 << ((byte)uVar2 & 0x1f);
  return;
}



===== AhciResetPort @ 00019d80 =====

void AhciResetPort(longlong param_1,uint param_2,char param_3)

{
  ushort *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  int iVar9;
  longlong lVar10;
  bool bVar11;
  
  lVar10 = (longlong)(int)param_2;
  if (*(int *)(param_1 + 0x4834) == 0) {
    uVar7 = param_2 & 0x80000003;
    if ((int)uVar7 < 0) {
      uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
    }
    puVar3 = *(uint **)(param_1 + 0x58);
    lVar8 = (longlong)(int)uVar7 + 2;
    puVar3[lVar8 * 0x20 + 5] = 0;
    uVar2 = *(ushort *)(param_1 + 0xab8 + lVar10 * 4);
    if ((uVar2 & 0x2000) == 0) {
      if ((uVar2 & 0x8000) == 0) {
        iVar9 = 0;
        uVar4 = 1 << ((byte)uVar7 & 0x1f);
        do {
          puVar3[lVar8 * 0x20 + 0xc] = 0xffffffff;
          puVar3[lVar8 * 0x20 + 4] = 0xffffffff;
          puVar3[2] = uVar4;
          puVar3[lVar8 * 0x20 + 6] = puVar3[lVar8 * 0x20 + 6] & 0xffffffee;
          if ((*puVar3 & 0x8000000) == 0) {
            if (param_3 != '\0') {
              DbgPrint("HBA NOT support staggered spin-up, force to do normal COMRESET\n");
              param_3 = '\0';
              goto LAB_00019e77;
            }
LAB_00019ea4:
            DbgPrint("do com reset on AHCI port %d\n",uVar7);
            puVar3[lVar8 * 0x20 + 0xb] = puVar3[lVar8 * 0x20 + 0xb] | 1;
            puVar3[lVar8 * 0x20 + 6] = puVar3[lVar8 * 0x20 + 6] | 0x10;
            lVar6 = 2;
            do {
              StorPortStallExecution(1000);
              lVar6 = lVar6 + -1;
            } while (lVar6 != 0);
            StorPortStallExecution(0);
            puVar3[lVar8 * 0x20 + 0xb] = puVar3[lVar8 * 0x20 + 0xb] & 0xfffffffe;
            lVar6 = 2;
            do {
              StorPortStallExecution(1000);
              lVar6 = lVar6 + -1;
            } while (lVar6 != 0);
            StorPortStallExecution(0);
          }
          else {
            if ((puVar3[lVar8 * 0x20 + 6] & 2) == 0) {
              if (param_3 == '\0') {
                DbgPrint("port %d PxCMD.SUD is 0, force to do spin-up\n",uVar7);
                param_3 = '\x01';
                goto LAB_00019e77;
              }
            }
            else {
LAB_00019e77:
              if (param_3 == '\0') goto LAB_00019ea4;
            }
            DbgPrint("do stagger spin up on AHCI port %d\n",uVar7);
            puVar3[lVar8 * 0x20 + 0xb] = puVar3[lVar8 * 0x20 + 0xb] & 0xfffffffe;
            puVar3[lVar8 * 0x20 + 6] = puVar3[lVar8 * 0x20 + 6] & 0xfffffffd;
            StorPortStallExecution(100);
            puVar3[lVar8 * 0x20 + 6] = puVar3[lVar8 * 0x20 + 6] | 0x12;
          }
          uVar5 = 0;
          do {
            if ((puVar3[lVar8 * 0x20 + 4] & 0x40) != 0) {
              puVar3[lVar8 * 0x20 + 0xc] = puVar3[lVar8 * 0x20 + 0xc] | 0x4000000;
              break;
            }
            StorPortStallExecution(10);
            uVar5 = uVar5 + 1;
          } while (uVar5 < 1000);
          lVar6 = 10;
          do {
            StorPortStallExecution(1000);
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          StorPortStallExecution(0);
          if ((puVar3[lVar8 * 0x20 + 10] & 1) == 0) {
            puVar3[lVar8 * 0x20 + 6] = puVar3[lVar8 * 0x20 + 6] & 0xffffffee;
            break;
          }
          if ((puVar3[lVar8 * 0x20 + 10] & 0xf) == 1) {
            if ((*(int *)(param_1 + 0x4870) == 0) && (*(char *)(param_1 + 0x2d) == '\0')) {
              if (iVar9 != 1) break;
            }
            else if (iVar9 != 0) break;
LAB_0001a05f:
            puVar1 = (ushort *)(param_1 + 0xab8 + lVar10 * 4);
            *puVar1 = *puVar1 | 0x8000;
            break;
          }
          uVar5 = 0;
          if ((char)puVar3[lVar8 * 0x20 + 8] < '\0') {
            do {
              if (-1 < (char)puVar3[lVar8 * 0x20 + 8]) break;
              StorPortStallExecution(10);
              uVar5 = uVar5 + 1;
            } while (uVar5 < 300000);
          }
          uVar5 = 0;
          do {
            if ((char)(puVar3[lVar8 * 0x20 + 8] >> 8) == '\x01') break;
            StorPortStallExecution(10);
            uVar5 = uVar5 + 1;
          } while (uVar5 < 1000);
          puVar3[lVar8 * 0x20 + 6] = puVar3[lVar8 * 0x20 + 6] | 0x11;
          if ((char)puVar3[lVar8 * 0x20 + 8] < '\0') {
            AhciSoftwareReset(param_1,param_2);
            if ((*(int *)(param_1 + 0x4870) == 0) && (*(char *)(param_1 + 0x2d) == '\0')) {
              uVar5 = 0;
              do {
                if (-1 < (char)puVar3[lVar8 * 0x20 + 8]) break;
                StorPortStallExecution(0x96);
                uVar5 = uVar5 + 1;
              } while (uVar5 < 20000);
            }
            else {
              uVar5 = 0;
              do {
                if (-1 < (char)puVar3[lVar8 * 0x20 + 8]) break;
                StorPortStallExecution(0x96);
                uVar5 = uVar5 + 1;
              } while (uVar5 < 7000);
            }
          }
          if ((-1 < (char)(byte)puVar3[lVar8 * 0x20 + 8]) &&
             (((byte)puVar3[lVar8 * 0x20 + 8] & 0x20) == 0)) break;
          if ((*(int *)(param_1 + 0x4870) == 0) && (*(char *)(param_1 + 0x2d) == '\0')) {
            bVar11 = iVar9 == 1;
          }
          else {
            bVar11 = iVar9 == 0;
          }
          if (bVar11) goto LAB_0001a05f;
          iVar9 = iVar9 + 1;
        } while (iVar9 < 3);
        puVar3[lVar8 * 0x20 + 0xc] = 0xffffffff;
        puVar3[lVar8 * 0x20 + 4] = 0xffffffff;
        puVar3[2] = uVar4;
        puVar3[lVar8 * 0x20 + 5] = 0xffffffff;
        if ((*(ushort *)(param_1 + 0xab8 + lVar10 * 4) & 0x8000) != 0) {
          *(undefined4 *)(param_1 + 0x4850 + lVar10 * 8) = 0;
          *(undefined1 *)(param_1 + 0x14b6) = 1;
          StorPortNotification(6,param_1,AtapiCheckErrorDiskTimer,2000000,0xffffffff);
        }
      }
    }
    else {
      AhciResetPort_for_ErrorDisk(param_1,param_2);
    }
  }
  else {
    AhciPowerResetPort(param_1,param_2,param_3);
  }
  return;
}



===== AhciResetInterrupt @ 0001a0e4 =====

void AhciResetInterrupt(longlong param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  longlong lVar4;
  
  if (*(char *)(param_1 + 0x60) != '\0') {
    lVar1 = *(longlong *)(param_1 + 0x58);
    pbVar3 = (byte *)(param_1 + 0x948);
    lVar4 = 4;
    puVar2 = (undefined4 *)(lVar1 + 0x110);
    do {
      if ((*pbVar3 & 4) != 0) {
        puVar2[8] = 0xffffffff;
        *puVar2 = 0xffffffff;
        puVar2[1] = 0xffffffff;
      }
      puVar2 = puVar2 + 0x20;
      pbVar3 = pbVar3 + 2;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | 2;
    *(undefined4 *)(lVar1 + 8) = 0xffffffff;
  }
  return;
}



===== AhciSoftwareReset @ 0001a130 =====

longlong AhciSoftwareReset(longlong param_1,uint param_2)

{
  uint *puVar1;
  uint *_Dst;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = param_2 & 0x80000003;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
  }
  puVar1 = *(uint **)(param_1 + 0x58);
  _Dst = *(uint **)(param_1 + 0x38 + (longlong)(int)param_2 * 8);
  lVar4 = (longlong)(int)uVar3 + 2;
  AhciStopPort(param_1,param_2);
  uVar6 = 0;
  uVar5 = 0;
  do {
    uVar2 = puVar1[lVar4 * 0x20 + 8];
    if ((uVar2 & 0x88) == 0) goto LAB_0001a1c8;
    StorPortStallExecution(1);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 20000);
  if ((uVar2 & 0x88) != 0) {
    if ((*puVar1 >> 0x18 & 1) == 0) {
      return (ulonglong)(uint3)(*puVar1 >> 8) << 8;
    }
    puVar1[lVar4 * 0x20 + 6] = puVar1[lVar4 * 0x20 + 6] | 8;
  }
LAB_0001a1c8:
  puVar1[lVar4 * 0x20 + 6] = puVar1[lVar4 * 0x20 + 6] | 0x11;
  puVar1[lVar4 * 0x20 + 0xc] = 0xffffffff;
  puVar1[lVar4 * 0x20 + 4] = 0xffffffff;
  puVar1[lVar4 * 0x20 + 5] = 0;
  uVar2 = 1 << ((byte)uVar3 & 0x1f);
  puVar1[2] = uVar2;
  memset(_Dst + 0x140,0,0x40);
  *(byte *)((longlong)_Dst + 0x501) = *(byte *)((longlong)_Dst + 0x501) & 0x7f;
  *(undefined1 *)(_Dst + 0x140) = 0x27;
  *(undefined1 *)((longlong)_Dst + 0x50f) = 4;
  *(undefined1 *)((longlong)_Dst + 0x507) = 0xa0;
  uVar3 = _Dst[2];
  uVar5 = _Dst[3];
  memset(_Dst,0,0x20);
  _Dst[3] = uVar5;
  *_Dst = *_Dst & 0xffffffe5 | 0x505;
  _Dst[2] = uVar3;
  memset(_Dst + 0x280,0,0x40);
  *(byte *)((longlong)_Dst + 0xa01) = *(byte *)((longlong)_Dst + 0xa01) & 0x7f;
  *(undefined1 *)(_Dst + 0x280) = 0x27;
  *(undefined1 *)((longlong)_Dst + 0xa0f) = 0;
  *(undefined1 *)((longlong)_Dst + 0xa07) = 0xa0;
  uVar3 = _Dst[10];
  uVar5 = _Dst[0xb];
  memset(_Dst + 8,0,0x20);
  _Dst[0xb] = uVar5;
  _Dst[10] = uVar3;
  _Dst[8] = _Dst[8] & 0xfffffae5 | 5;
  puVar1[lVar4 * 0x20 + 0xe] = puVar1[lVar4 * 0x20 + 0xe] | 1;
  StorPortStallExecution(0x14);
  puVar1[lVar4 * 0x20 + 0xe] = puVar1[lVar4 * 0x20 + 0xe] | 2;
  if (*(int *)(param_1 + 0x4834) == 0) {
    if ((*(int *)(param_1 + 0x4870) == 0) && (*(char *)(param_1 + 0x2d) == '\0')) {
      do {
        if ((puVar1[lVar4 * 0x20 + 0xe] & 3) == 0) break;
        StorPortStallExecution(1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < 6000000);
    }
    else if ((*(ushort *)(param_1 + 0xab8 + (longlong)(int)param_2 * 4) & 0x2000) == 0) {
      do {
        if ((puVar1[lVar4 * 0x20 + 0xe] & 3) == 0) break;
        StorPortStallExecution(1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < 600000);
    }
    else {
      do {
        if ((puVar1[lVar4 * 0x20 + 0xe] & 3) == 0) break;
        StorPortStallExecution(1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < 100000);
    }
  }
  puVar1[lVar4 * 0x20 + 0xc] = 0xffffffff;
  puVar1[lVar4 * 0x20 + 4] = 0xffffffff;
  puVar1[2] = uVar2;
  puVar1[lVar4 * 0x20 + 5] = 0xffffffff;
  return 0xffffff01;
}



===== AhciIdeMediaStatus @ 0001a358 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001a38e) */

void AhciIdeMediaStatus(undefined8 param_1,longlong param_2,uint param_3)

{
  ushort *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStackY_148 [32];
  undefined4 local_118;
  undefined1 local_111;
  undefined1 local_d8 [78];
  undefined1 local_8a;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  uVar3 = (ulonglong)param_3;
  lVar2 = *(longlong *)(param_2 + 0x58);
  memset(local_d8,0,0xc0);
  local_8a = (undefined1)param_3;
  memset(&local_118,0,0x40);
  local_118._1_1_ = local_118._1_1_ | 0x80;
  local_118._0_1_ = 0x27;
  local_111 = 0xa0;
  if ((*(byte *)(param_2 + 0xab8 + uVar3 * 2) & 0x10) != 0) {
    local_118._2_2_ = 0x95ef;
    IssueAhciCommand(param_2,(longlong)local_d8,&local_118,(uint *)0x0,'\0','\0');
    if ((*(byte *)(((longlong)(int)(param_3 >> 1 & 3) + 2) * 0x80 + lVar2 + 0x20) & 1) == 0) {
      puVar1 = (ushort *)(param_2 + 0xab8 + uVar3 * 2);
      *puVar1 = *puVar1 | 0x20;
      *(undefined1 *)(uVar3 + 0x84 + param_2) = 0;
    }
  }
  return;
}



===== AhciSetMultiple @ 0001a44c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001a484) */

ulonglong AhciSetMultiple(longlong param_1,ulonglong param_2)

{
  ushort *puVar1;
  char cVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 auStackY_158 [32];
  undefined4 local_128;
  undefined1 local_121;
  undefined1 local_11c;
  undefined1 local_e8 [78];
  undefined1 local_9a;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_158;
  uVar7 = param_2 & 0xffffffff;
  lVar6 = ((longlong)(int)((uint)(param_2 >> 1) & 3) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  uVar5 = 0;
  do {
    cVar2 = *(char *)(lVar6 + 0x20);
    if (-1 < cVar2) goto LAB_0001a4c6;
    uVar4 = StorPortStallExecution(0x96);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 20000);
  if (cVar2 < '\0') {
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  else {
LAB_0001a4c6:
    memset(local_e8,0,0xc0);
    local_9a = (undefined1)uVar7;
    memset(&local_128,0,0x40);
    local_11c = *(undefined1 *)(uVar7 + 0xb00 + param_1);
    local_128._1_1_ = local_128._1_1_ | 0x80;
    local_128._0_1_ = 0x27;
    local_121 = 0xa0;
    local_128._2_1_ = 0xc6;
    uVar5 = IssueAhciCommand(param_1,(longlong)local_e8,&local_128,(uint *)0x0,'\0','\0');
    bVar3 = *(byte *)(lVar6 + 0x20);
    lVar6 = CONCAT71((int7)(CONCAT44(extraout_var,uVar5) >> 8),bVar3);
    if ((bVar3 & 1) == 0) {
      puVar1 = (ushort *)(uVar7 * 0xd4 + 0xd8a + param_1);
      *puVar1 = *puVar1 | *(byte *)(uVar7 + 0xb00 + param_1) | 0x100;
    }
    else {
      lVar6 = uVar7 * 0xd4;
      *(undefined1 *)(uVar7 + 0xb00 + param_1) = 0;
      *(undefined1 *)(lVar6 + 0xd8a + param_1) = 0;
    }
    uVar4 = CONCAT71((int7)((ulonglong)lVar6 >> 8),1);
  }
  return uVar4;
}



===== AhciDevReset @ 0001a5a0 =====

ulonglong AhciDevReset(longlong param_1,int param_2)

{
  uint uVar1;
  uint *_Dst;
  uint uVar2;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  
  uVar5 = param_2 >> 1;
  uVar2 = uVar5 & 0x80000003;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
  }
  _Dst = *(uint **)(param_1 + 0x38 + (longlong)(int)uVar5 * 8);
  lVar6 = ((longlong)(int)uVar2 + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  AhciStopPort(param_1,uVar5);
  uVar7 = 0;
  uVar2 = 0;
  do {
    bVar4 = *(byte *)(lVar6 + 0x20);
    if ((bVar4 & 0x88) == 0) goto LAB_0001a638;
    StorPortStallExecution(1);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 20000);
  if ((bVar4 & 0x88) == 0) {
LAB_0001a638:
    *(uint *)(lVar6 + 0x18) = *(uint *)(lVar6 + 0x18) | 0x11;
    *(undefined4 *)(lVar6 + 0x14) = 0;
    memset(_Dst + 0x140,0,0x40);
    *(byte *)((longlong)_Dst + 0x501) = *(byte *)((longlong)_Dst + 0x501) | 0x80;
    *(undefined1 *)(_Dst + 0x140) = 0x27;
    *(undefined1 *)((longlong)_Dst + 0x507) = 0xa0;
    *(undefined1 *)((longlong)_Dst + 0x502) = 8;
    uVar2 = _Dst[2];
    uVar1 = _Dst[3];
    memset(_Dst,0,0x20);
    _Dst[2] = uVar2;
    _Dst[3] = uVar1;
    *_Dst = *_Dst & 0xffff0fc5 | 0x105;
    *(uint *)(lVar6 + 0x38) = *(uint *)(lVar6 + 0x38) | 1;
    while (uVar3 = (ulonglong)*(uint *)(lVar6 + 0x20), (*(uint *)(lVar6 + 0x20) & 0x80) == 0) {
      StorPortStallExecution(1);
    }
    if ((*(int *)(param_1 + 0x4870) == 0) && (*(char *)(param_1 + 0x2d) == '\0')) {
      do {
        bVar4 = *(byte *)(lVar6 + 0x20);
        if ((bVar4 & 0x80) == 0) break;
        uVar3 = StorPortStallExecution(0x96);
        uVar7 = uVar7 + 1;
      } while (uVar7 < 20000);
    }
    else {
      do {
        bVar4 = *(byte *)(lVar6 + 0x20);
        if ((bVar4 & 0x80) == 0) break;
        uVar3 = StorPortStallExecution(0x96);
        uVar7 = uVar7 + 1;
      } while (uVar7 < 7000);
    }
    if ((bVar4 & 0x88) == 0) {
      if ((bVar4 & 1) != 0) {
        uVar3 = AhciStopPort(param_1,uVar5);
        *(uint *)(lVar6 + 0x18) = *(uint *)(lVar6 + 0x18) | 0x11;
      }
      *(undefined4 *)(lVar6 + 0x14) = 0xffffffff;
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
  }
  uVar3 = AhciResetPort(param_1,uVar5,'\0');
  return uVar3 & 0xffffffffffffff00;
}



===== AhciIssueIdentifyCmd @ 0001a744 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001a78a) */

ulonglong AhciIssueIdentifyCmd(longlong param_1,ulonglong param_2,char param_3,undefined8 param_4)

{
  byte bVar1;
  char cVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  undefined8 uVar4;
  char cVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  undefined1 auStackY_198 [32];
  undefined1 local_158;
  byte local_157;
  char local_156;
  undefined2 local_153;
  undefined1 local_151;
  undefined1 local_118 [75];
  char local_cd;
  undefined1 local_ca;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined4 local_74;
  undefined4 local_6c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_198;
  uVar9 = (uint)(param_2 >> 1);
  lVar6 = 2;
  lVar7 = ((longlong)(int)(uVar9 & 3) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  uVar8 = 0;
  do {
    bVar1 = *(byte *)(lVar7 + 0x20);
    if (-1 < (char)bVar1) break;
    StorPortStallExecution(0x96);
    uVar8 = uVar8 + 1;
  } while (uVar8 < 20000);
  if ((param_3 == -0x14) && ((bVar1 & 0xfc) != 0x50)) {
    uVar3 = AhciSoftwareReset(param_1,uVar9 & 0x7fffffff);
    uVar9 = 0;
    do {
      bVar1 = *(byte *)(lVar7 + 0x20);
      if (-1 < (char)bVar1) break;
      uVar3 = StorPortStallExecution(0x96);
      uVar9 = uVar9 + 1;
    } while (uVar9 < 20000);
    if ((bVar1 & 0xfd) != 0x50) goto LAB_0001a807;
    uVar3 = 0;
    cVar5 = (char)((uint)*(undefined4 *)(lVar7 + 0x24) >> 0x10);
    cVar2 = (char)((uint)*(undefined4 *)(lVar7 + 0x24) >> 0x18);
    if (((cVar5 == '\x14') && (cVar2 == -0x15)) || ((cVar5 == 'i' && (cVar2 == -0x6a))))
    goto LAB_0001a807;
  }
  memset(local_118,0,0xc0);
  local_ca = (undefined1)param_2;
  local_6c = 1;
  local_74 = 1;
  local_c0 = 0x200;
  local_b8 = param_4;
  memset(&local_158,0,0x40);
  local_157 = local_157 | 0x80;
  local_158 = 0x27;
  local_153 = 0x200;
  local_151 = 0xa0;
  local_156 = param_3;
  uVar9 = IssueAhciCommand(param_1,(longlong)local_118,(uint *)&local_158,(uint *)0x0,'\0','\x01');
  uVar3 = CONCAT44(extraout_var,uVar9);
  if (local_cd == '\x01') {
    do {
      StorPortStallExecution(1000);
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    uVar4 = StorPortStallExecution(0);
    return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  }
LAB_0001a807:
  return uVar3 & 0xffffffffffffff00;
}



===== AhciResumeSetAllFeature @ 0001a8f0 =====

/* WARNING: Removing unreachable block (ram,0x0001ad01) */
/* WARNING: Removing unreachable block (ram,0x0001aaef) */
/* WARNING: Removing unreachable block (ram,0x0001a975) */
/* WARNING: Removing unreachable block (ram,0x0001a9d4) */
/* WARNING: Removing unreachable block (ram,0x0001ab4e) */
/* WARNING: Removing unreachable block (ram,0x0001ad68) */

void AhciResumeSetAllFeature(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  byte bVar4;
  uint uVar5;
  longlong lVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  uint *puVar10;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x4834) != 0) {
    pbVar7 = (byte *)(param_1 + 0xab8);
    uVar8 = 0;
    pbVar9 = pbVar7;
    do {
      if ((*pbVar9 & 1) != 0) {
        DisableDevIPM(param_1,uVar8);
      }
      bVar4 = (char)uVar8 + 1;
      uVar8 = (uint)bVar4;
      pbVar9 = pbVar9 + 2;
    } while (bVar4 < 8);
    uVar8 = 0;
    uVar1 = 0;
    pbVar9 = pbVar7;
    do {
      if ((*pbVar9 & 1) != 0) {
        lVar6 = *(longlong *)(param_1 + 0x58);
        while ((uVar8 < 100000 &&
               ((*(uint *)(((longlong)(int)(uVar1 & 0x80000003) + 2) * 0x80 + lVar6 + 0x38) & 1) !=
                0))) {
          StorPortStallExecution(10);
          uVar8 = uVar8 + 1;
        }
      }
      bVar4 = (char)uVar1 + 1;
      uVar1 = (uint)bVar4;
      pbVar9 = pbVar9 + 4;
    } while (bVar4 < 4);
    uVar8 = 0;
    uVar1 = 0;
    pbVar9 = pbVar7;
    do {
      lVar6 = ((longlong)(int)(uVar1 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
      if (((*pbVar9 & 1) != 0) && (*(char *)(lVar6 + 0x20) < '\0')) {
        while ((uVar8 < 100000 && (*(char *)(lVar6 + 0x20) < '\0'))) {
          StorPortStallExecution(10);
          uVar8 = uVar8 + 1;
        }
      }
      bVar4 = (char)uVar1 + 1;
      uVar1 = (uint)bVar4;
      pbVar9 = pbVar9 + 4;
    } while (bVar4 < 4);
    uVar8 = 0;
    puVar10 = (uint *)(param_1 + 0x39c);
    puVar3 = (ushort *)(param_1 + 0xd94);
    pbVar9 = pbVar7;
    do {
      if ((*pbVar9 & 1) != 0) {
        *puVar10 = *puVar10 & 0xfffff0ff;
        if ((*puVar10 >> 0xc & 0xf) != 0) {
          bVar4 = (byte)(*puVar10 >> 0xc) & 0xf;
          if (bVar4 == 4) {
            *puVar3 = *puVar3 | 2;
          }
          else if (bVar4 == 3) {
            *puVar3 = *puVar3 | 1;
          }
          StorPortStallExecution(99);
          AhciResumeSetFeature(param_1,uVar8,param_3,bVar4 | 8);
          uVar1 = *puVar10;
          *puVar10 = (uVar1 >> 4 ^ uVar1) & 0xf00 ^ uVar1 | 1;
        }
      }
      bVar4 = (char)uVar8 + 1;
      uVar8 = (uint)bVar4;
      pbVar9 = pbVar9 + 2;
      puVar3 = puVar3 + 0x6a;
      puVar10 = puVar10 + 0x2e;
    } while (bVar4 < 8);
    uVar8 = 0;
    uVar1 = 0;
    pbVar9 = pbVar7;
    do {
      if ((*pbVar9 & 1) != 0) {
        lVar6 = *(longlong *)(param_1 + 0x58);
        while ((uVar8 < 100000 &&
               ((*(uint *)(((longlong)(int)(uVar1 & 0x80000003) + 2) * 0x80 + lVar6 + 0x38) & 1) !=
                0))) {
          StorPortStallExecution(10);
          uVar8 = uVar8 + 1;
        }
      }
      bVar4 = (char)uVar1 + 1;
      uVar1 = (uint)bVar4;
      pbVar9 = pbVar9 + 4;
    } while (bVar4 < 4);
    uVar8 = 0;
    uVar1 = 0;
    do {
      lVar6 = ((longlong)(int)(uVar1 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
      if ((*pbVar7 & 1) == 0) {
        *(undefined4 *)(lVar6 + 0x14) = 0xffffffff;
      }
      else if (*(char *)(lVar6 + 0x20) < '\0') {
        while ((uVar8 < 100000 && (*(char *)(lVar6 + 0x20) < '\0'))) {
          StorPortStallExecution(10);
          uVar8 = uVar8 + 1;
        }
      }
      bVar4 = (char)uVar1 + 1;
      uVar1 = (uint)bVar4;
      pbVar7 = pbVar7 + 4;
    } while (bVar4 < 4);
    uVar8 = 0;
    pbVar7 = (byte *)(param_1 + 0xac8);
    puVar3 = (ushort *)(param_1 + 0xd92);
    puVar10 = (uint *)(param_1 + 0x39c);
    do {
      if ((pbVar7[-0x10] & 1) != 0) {
        uVar1 = *puVar10;
        uVar5 = uVar1 & 0xf0f0fffb;
        *puVar10 = uVar5;
        if (uVar1 >> 0x1c == 0) {
          bVar4 = (byte)(uVar5 >> 0x14);
          if ((uVar5 >> 0x14 & 0xf) != 0) {
            *puVar3 = 1 << bVar4 + 8 | *puVar3 & 0xf8ff;
            StorPortStallExecution(99);
            AhciResumeSetFeature(param_1,uVar8,param_3,bVar4 | 0x20);
            uVar1 = *puVar10;
            uVar1 = (uVar1 >> 4 ^ uVar1) & 0xf0000 ^ uVar1 | 4;
            goto LAB_0001acba;
          }
        }
        else {
          bVar4 = (byte)(uVar5 >> 0x1c);
          puVar3[0x19] = 1 << bVar4 + 8 | puVar3[0x19] & 0x80ff;
          StorPortStallExecution(99);
          AhciResumeSetFeature(param_1,uVar8,param_3,bVar4 | 0x40);
          uVar1 = *puVar10;
          uVar1 = (uVar1 >> 4 ^ uVar1) & 0xf000000 ^ uVar1;
          *puVar10 = uVar1 | 4;
          if ((*pbVar7 & 4) != 0) {
            uVar1 = uVar1 & 0xfffffffb;
LAB_0001acba:
            *puVar10 = uVar1;
          }
        }
      }
      bVar4 = (char)uVar8 + 1;
      uVar8 = (uint)bVar4;
      pbVar7 = pbVar7 + 2;
      puVar3 = puVar3 + 0x6a;
      puVar10 = puVar10 + 0x2e;
    } while (bVar4 < 8);
    pbVar7 = (byte *)(param_1 + 0xab8);
    uVar8 = 0;
    uVar1 = 0;
    pbVar9 = pbVar7;
    do {
      if ((*pbVar9 & 1) != 0) {
        lVar6 = *(longlong *)(param_1 + 0x58);
        while ((uVar8 < 100000 &&
               ((*(uint *)(((longlong)(int)(uVar1 & 0x80000003) + 2) * 0x80 + lVar6 + 0x38) & 1) !=
                0))) {
          StorPortStallExecution(10);
          uVar8 = uVar8 + 1;
        }
      }
      bVar4 = (char)uVar1 + 1;
      uVar1 = (uint)bVar4;
      pbVar9 = pbVar9 + 4;
    } while (bVar4 < 4);
    uVar8 = 0;
    do {
      lVar6 = ((longlong)(int)(uVar8 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
      if ((*pbVar7 & 1) != 0) {
        if (*(char *)(lVar6 + 0x20) < '\0') {
          while ((uVar2 < 100000 && (*(char *)(lVar6 + 0x20) < '\0'))) {
            StorPortStallExecution(10);
            uVar2 = uVar2 + 1;
          }
        }
        *(undefined4 *)(lVar6 + 0x14) = 0xffffffff;
      }
      bVar4 = (char)uVar8 + 1;
      uVar8 = (uint)bVar4;
      pbVar7 = pbVar7 + 4;
    } while (bVar4 < 4);
  }
  return;
}



===== AhciResumeSetFeature @ 0001ade0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001ae14) */

undefined8 AhciResumeSetFeature(longlong param_1,uint param_2,undefined8 param_3,undefined1 param_4)

{
  uint uVar1;
  undefined4 extraout_var;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  undefined1 auStackY_168 [32];
  undefined4 local_138;
  undefined1 local_131;
  undefined1 local_12c;
  undefined1 local_f8 [78];
  undefined1 local_aa;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  lVar3 = ((longlong)(int)(param_2 >> 1 & 3) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  if (*(char *)(lVar3 + 0x20) < '\0') {
    uVar2 = 0;
  }
  else {
    memset(local_f8,0,0xc0);
    local_aa = (undefined1)param_2;
    memset(&local_138,0,0x40);
    local_138._1_1_ = local_138._1_1_ | 0x80;
    uVar4 = 0;
    local_138._0_1_ = 0x27;
    local_138._2_2_ = 0x3ef;
    local_131 = 0xa0;
    local_12c = param_4;
    uVar1 = IssueAhciCommand(param_1,(longlong)local_f8,&local_138,(uint *)0x0,'\0','\0');
    uVar2 = CONCAT44(extraout_var,uVar1);
    if (*(int *)(param_1 + 0x4834) == 0) {
      do {
        if (-1 < *(char *)(lVar3 + 0x20)) break;
        uVar2 = StorPortStallExecution(0x96);
        uVar4 = uVar4 + 1;
      } while (uVar4 < 200000);
    }
    uVar2 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  return uVar2;
}



===== AhciSetFeature @ 0001aedc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001af1c) */

ulonglong AhciSetFeature(longlong param_1,ulonglong param_2,undefined1 param_3,undefined1 param_4)

{
  char cVar1;
  byte bVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined4 extraout_var;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStackY_198 [32];
  undefined4 local_158;
  undefined1 local_151;
  undefined1 local_14c;
  undefined1 local_118 [78];
  undefined1 local_ca;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_198;
  uVar8 = param_2 & 0xffffffff;
  lVar3 = *(longlong *)(param_1 + 0x58);
  lVar6 = ((longlong)(int)((uint)(param_2 >> 1) & 3) + 2) * 0x80;
  uVar7 = 0;
  do {
    cVar1 = *(char *)(lVar6 + 0x20 + lVar3);
    if (-1 < cVar1) goto LAB_0001af5f;
    uVar4 = StorPortStallExecution(0x96);
    uVar7 = uVar7 + 1;
  } while (uVar7 < 20000);
  if (cVar1 < '\0') {
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  else {
LAB_0001af5f:
    memset(local_118,0,0xc0);
    local_ca = (char)uVar8;
    memset(&local_158,0,0x40);
    local_158._1_1_ = local_158._1_1_ | 0x80;
    local_158._0_1_ = 0x27;
    local_151 = 0xa0;
    local_158._2_1_ = 0xef;
    local_158._3_1_ = param_3;
    local_14c = param_4;
    IssueAhciCommand(param_1,(longlong)local_118,&local_158,(uint *)0x0,'\0','\0');
    if (*(int *)(param_1 + 0x4834) == 0) {
      uVar7 = 0;
      do {
        if (-1 < *(char *)(lVar6 + 0x20 + lVar3)) break;
        StorPortStallExecution(0x96);
        uVar7 = uVar7 + 1;
      } while (uVar7 < 200000);
    }
    bVar2 = *(byte *)(uVar8 * 0xd4 + 0xdb8 + param_1);
    uVar5 = CONCAT71((int7)(uVar8 >> 8),bVar2);
    if ((bVar2 & 2) != 0) {
      lVar3 = *(longlong *)(param_1 + 0x58);
      uVar7 = 0;
      do {
        cVar1 = *(char *)(lVar6 + 0x20 + lVar3);
        if (-1 < cVar1) goto LAB_0001b034;
        uVar5 = StorPortStallExecution(0x96);
        uVar7 = uVar7 + 1;
      } while (uVar7 < 20000);
      if (-1 < cVar1) {
LAB_0001b034:
        memset(local_118,0,0xc0);
        local_ca = (char)uVar8;
        memset(&local_158,0,0x40);
        local_158._1_1_ = local_158._1_1_ | 0x80;
        local_158._0_1_ = 0x27;
        local_151 = 0xa0;
        local_158._2_1_ = 0xf5;
        uVar7 = IssueAhciCommand(param_1,(longlong)local_118,&local_158,(uint *)0x0,'\0','\0');
        uVar5 = CONCAT44(extraout_var,uVar7);
      }
    }
    uVar4 = CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
  }
  return uVar4;
}



===== AhciSetDriveParameters @ 0001b0b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001b0f6) */

ulonglong AhciSetDriveParameters(longlong param_1,byte param_2)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  uint uVar4;
  undefined1 auStackY_168 [32];
  undefined4 local_138;
  undefined1 local_131;
  undefined1 local_12c;
  undefined1 local_f8 [75];
  char local_ad;
  byte local_aa;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  uVar3 = 0;
  lVar2 = *(longlong *)(param_1 + 0x58);
  uVar4 = 0;
  do {
    bVar1 = *(byte *)(((longlong)(int)(param_2 >> 1 & 0x80000003) + 2) * 0x80 + lVar2 + 0x20);
    if ((bVar1 & 0x50) != 0) break;
    uVar3 = StorPortStallExecution(0x96);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 20000);
  if ((char)bVar1 < '\0') {
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    memset(local_f8,0,0xc0);
    local_aa = param_2;
    memset(&local_138,0,0x40);
    local_12c = *(undefined1 *)((ulonglong)param_2 * 0xd4 + 0xd20 + param_1);
    local_138._1_1_ = local_138._1_1_ | 0x80;
    local_138._0_1_ = 0x27;
    local_131 = 0xa0;
    local_138._2_1_ = 0x91;
    uVar4 = IssueAhciCommand(param_1,(longlong)local_f8,&local_138,(uint *)0x0,'\0','\0');
    uVar3 = CONCAT71((int7)(CONCAT44(extraout_var,uVar4) >> 8),local_ad == '\x01');
  }
  return uVar3;
}



===== IssueAhciCommand @ 0001b1d0 =====

/* WARNING: Removing unreachable block (ram,0x0001b271) */

uint IssueAhciCommand(longlong param_1,longlong param_2,uint *param_3,uint *param_4,char param_5,
                     char param_6)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  byte bVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  void *pvVar8;
  void *_Dst;
  uint uVar9;
  int iVar10;
  ulonglong uVar11;
  uint *puVar12;
  longlong lVar13;
  uint local_res10 [2];
  uint *local_res18;
  uint *local_res20;
  int local_88;
  uint local_84;
  undefined8 local_80;
  uint local_78;
  uint local_74;
  void *local_70;
  longlong local_68;
  uint *local_60;
  longlong local_58;
  ulonglong local_50;
  
  uVar7 = 0;
  *(undefined1 *)(param_2 + 0x4b) = 0;
  local_88 = 0;
  local_78 = 0;
  local_70 = (void *)0x0;
  if ((*(uint *)(param_2 + 0xb0) & 1) == 0) {
    puVar12 = *(uint **)(param_2 + 0x30);
    if (puVar12 != (uint *)0x0) goto LAB_0001b249;
    local_84 = (*(uint *)(param_2 + 0x58) & 0x7ffff | 0xffe00000) << 10;
  }
  else {
    local_84 = 0x80000000;
  }
  puVar12 = &local_84;
LAB_0001b249:
  bVar4 = *(byte *)(param_2 + 0x4e);
  local_50 = (ulonglong)(bVar4 >> 1);
  local_68 = *(longlong *)(param_1 + 0x340 + local_50 * 8);
  local_80 = *(uint **)(param_1 + 0x38 + local_50 * 8);
  lVar13 = ((ulonglong)((bVar4 & 0x80000007) / 2) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  local_res18 = param_3;
  local_res20 = param_4;
  local_58 = lVar13;
  if (*(char *)(lVar13 + 0x20) < '\0') {
    *(undefined4 *)(lVar13 + 0x14) = 0;
    AhciResetPort(param_1,(uint)(bVar4 >> 1),'\0');
    *(undefined4 *)(lVar13 + 0x14) = 0xffffffff;
  }
  if (param_5 == '\0') {
    *(undefined4 *)(lVar13 + 0x14) = 0;
  }
  uVar5 = local_80[2];
  uVar9 = local_80[3];
  local_60 = local_80 + 0x140;
  memset(local_80,0,0x20);
  puVar3 = local_80;
  uVar2 = *local_80;
  local_80[2] = uVar5;
  local_80[3] = uVar9;
  uVar5 = uVar2 & 0xffffffe5;
  *local_80 = uVar5 | 5;
  if (local_res20 == (uint *)0x0) {
    uVar5 = uVar2 & 0xffffffc5 | 5;
  }
  else {
    uVar5 = uVar5 | 0x25;
  }
  *local_80 = uVar5;
  if (param_6 == '\0') {
    *local_80 = *local_80 | 0x40;
  }
  else {
    *local_80 = *local_80 & 0xffffffbf;
  }
  *local_80 = *local_80 & 0xffffff7f;
  local_74 = 0;
LAB_0001b334:
  while( true ) {
    uVar5 = *puVar12;
    uVar9 = uVar5 >> 10 & 0x7ffff;
    local_80 = (uint *)(CONCAT44(local_80._4_4_,uVar5 >> 10) & 0xffffffff0007ffff);
    if (uVar9 != 0) break;
    if ((int)uVar5 < 0) goto LAB_0001b553;
    puVar12 = puVar12 + 1;
  }
  if ((Hibernate != '\0') && ((uVar5 >> 0x1e & 1) != 0)) {
    *puVar12 = uVar5 & 0xfffffc00;
  }
  if (*(longlong *)(param_2 + 0x20) == 0) {
    pvVar8 = (void *)((ulonglong)((*puVar12 & 0x3ff) << 9) + *(longlong *)(param_2 + 0x60));
  }
  else if ((*(int *)(param_2 + 0xa4) == 0) && ((*puVar12 >> 0x1e & 1) == 0)) {
    pvVar8 = (void *)((ulonglong)((*puVar12 & 0x3ff) << 9) + *(longlong *)(param_2 + 0x28));
  }
  else {
    pvVar8 = (void *)((ulonglong)((*puVar12 & 0x3ff) << 9) + *(longlong *)(param_2 + 0x20));
  }
  _Dst = pvVar8;
  if (*(int *)(param_2 + 0xac) != 0) {
    local_70 = pvVar8;
    _Dst = *(void **)(param_1 + 0x47f0);
    local_78 = uVar9;
    if (param_6 == '\0') {
      memcpy(_Dst,pvVar8,(ulonglong)uVar9);
    }
  }
  do {
    if (((*(int *)(param_2 + 0xa4) == 0) && ((*puVar12 & 0x40000000) == 0)) &&
       (*(int *)(param_2 + 0xac) == 0)) {
      lVar13 = *(longlong *)(param_2 + 0x10);
      if (lVar13 == 0) {
        lVar13 = 0;
      }
      else if (*(longlong *)(lVar13 + 0x10) != 0) {
        lVar13 = *(longlong *)(lVar13 + 0x10);
      }
      if (lVar13 == 0) goto LAB_0001b48c;
      if (*(uint **)(lVar13 + 0xe8) != (uint *)0x0) {
        lVar13 = GetPhyAddrFromSGL(*(uint **)(lVar13 + 0xe8),
                                   (int)_Dst - *(int *)(*(longlong *)(lVar13 + 0xf0) + 0x18),
                                   (int *)local_res10);
        goto LAB_0001b4a1;
      }
      uVar6 = *(undefined8 *)(lVar13 + 0xf0);
LAB_0001b48e:
      lVar13 = StorPortGetPhysicalAddress(param_1,uVar6,_Dst,local_res10);
    }
    else {
      if (((Hibernate != '\x01') || (pvVar8 = *(void **)(param_1 + 0x42a0), _Dst < pvVar8)) ||
         ((void *)((ulonglong)*(uint *)(param_1 + 0x42b0) + (longlong)pvVar8) < _Dst)) {
LAB_0001b48c:
        uVar6 = 0;
        goto LAB_0001b48e;
      }
      lVar13 = (*(longlong *)(param_1 + 0x42a8) - (longlong)pvVar8) + (longlong)_Dst;
      local_res10[0] = g_raid5hiberBufSize;
    }
LAB_0001b4a1:
    uVar5 = (uint)lVar13;
    uVar9 = ((uVar5 & 0xffff0000) - uVar5) + 0x10000;
    if ((local_res10[0] & 1) != 0) {
      local_res10[0] = local_res10[0] - 1;
    }
    if (uVar9 < local_res10[0]) {
      local_res10[0] = uVar9;
    }
    uVar9 = (uint)local_80;
    if (local_res10[0] < (uint)local_80) {
      uVar9 = local_res10[0];
    }
    if (uVar9 == 0) break;
    uVar11 = (ulonglong)local_74;
    iVar10 = (uint)local_80 - uVar9;
    local_88 = local_88 + uVar9;
    local_80 = (uint *)CONCAT44(local_80._4_4_,iVar10);
    puVar3[uVar11 * 4 + 0x163] =
         puVar3[uVar11 * 4 + 0x163] ^ (uVar9 - 1 ^ puVar3[uVar11 * 4 + 0x163]) & 0x3fffff;
    puVar3[(uVar11 + 8) * 4 + 0x140] = uVar5;
    puVar3[uVar11 * 4 + 0x161] = (uint)((ulonglong)lVar13 >> 0x20);
    *(short *)((longlong)puVar3 + 2) = *(short *)((longlong)puVar3 + 2) + 1;
    local_74 = local_74 + 1;
    _Dst = (void *)((longlong)_Dst + (ulonglong)uVar9);
  } while (iVar10 != 0);
  if (-1 < (int)*puVar12) {
    puVar12 = puVar12 + 1;
    goto LAB_0001b334;
  }
LAB_0001b553:
  lVar13 = local_58;
  cVar1 = *(char *)((longlong)local_res18 + 2);
  if (local_68 != 0) {
    *(undefined4 *)(local_68 + 0xb8) = 0;
    *(int *)(local_68 + 0xb4) = local_88;
  }
  if (local_60 != local_res18) {
    *(undefined8 *)local_60 = *(undefined8 *)local_res18;
    *(undefined8 *)(local_60 + 2) = *(undefined8 *)(local_res18 + 2);
    *(undefined8 *)(local_60 + 4) = *(undefined8 *)(local_res18 + 4);
    *(undefined8 *)(local_60 + 6) = *(undefined8 *)(local_res18 + 6);
    *(undefined8 *)(local_60 + 8) = *(undefined8 *)(local_res18 + 8);
    *(undefined8 *)(local_60 + 10) = *(undefined8 *)(local_res18 + 10);
    *(undefined8 *)(local_60 + 0xc) = *(undefined8 *)(local_res18 + 0xc);
    *(undefined8 *)(local_60 + 0xe) = *(undefined8 *)(local_res18 + 0xe);
  }
  if ((local_res20 != (uint *)0x0) && (local_60 + 0x10 != local_res20)) {
    *(undefined8 *)(local_60 + 0x10) = *(undefined8 *)local_res20;
    *(undefined8 *)(local_60 + 0x12) = *(undefined8 *)(local_res20 + 2);
    *(undefined8 *)(local_60 + 0x14) = *(undefined8 *)(local_res20 + 4);
    *(undefined8 *)(local_60 + 0x16) = *(undefined8 *)(local_res20 + 6);
  }
  *(uint *)(local_58 + 0x38) = *(uint *)(local_58 + 0x38) | 1;
  if (param_5 == '\0') {
    uVar7 = 0;
    do {
      if ((*(uint *)(lVar13 + 0x38) & 1) == 0) break;
      StorPortStallExecution(1);
      uVar7 = uVar7 + 1;
    } while (uVar7 < 20000);
    if (cVar1 == -0x14) {
      uVar7 = 0;
      do {
        if ((*(uint *)(lVar13 + 0x38) & 1) == 0) break;
        StorPortStallExecution(1);
        uVar7 = uVar7 + 1;
      } while (uVar7 < 400000);
    }
    if (((*(uint *)(lVar13 + 0x38) & 1) != 0) && ((*(byte *)(lVar13 + 0x20) & 1) == 0)) {
      if (*(int *)(param_1 + 0x4834) != 0) {
        return 0;
      }
      StorPortResume(param_1);
      uVar7 = 0;
      do {
        if ((*(uint *)(lVar13 + 0x38) & 1) == 0) break;
        StorPortStallExecution(1);
        uVar7 = uVar7 + 1;
      } while (uVar7 < 500000);
    }
    bVar4 = *(byte *)(lVar13 + 0x20);
    uVar7 = 0;
    if ((bVar4 & 8) == 0) {
      if ((char)bVar4 < '\0') {
        *(undefined1 *)(param_2 + 0x4b) = 5;
      }
      else if ((bVar4 & 1) == 0) {
        *(undefined1 *)(param_2 + 0x4b) = 1;
      }
      else {
        *(undefined1 *)(param_2 + 0x4b) = 4;
        uVar7 = *(uint *)(lVar13 + 0x20) >> 8;
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x4b) = 9;
    }
    *(undefined4 *)(lVar13 + 0x30) = 0xffffffff;
    *(undefined4 *)(lVar13 + 0x10) = 0xffffffff;
    if ((*(int *)(param_2 + 0xac) != 0) && (param_6 != '\0')) {
      memcpy(local_70,*(void **)(param_1 + 0x47f0),(ulonglong)local_78);
    }
    *(undefined4 *)(lVar13 + 0x14) = 0xffffffff;
    uVar7 = uVar7 & 0xff;
  }
  else {
    *(undefined1 *)(local_50 + 0x42dc + param_1) = 1;
    *(undefined1 *)(param_2 + 0x4b) = 0;
    if (((*(byte *)(param_1 + 0xac8 + (ulonglong)bVar4 * 2) & 1) != 0) &&
       (*(char *)(param_2 + 0x90) == '\0')) {
      if (*(int *)(local_58 + 0x38) != 0) {
        uVar7 = 0;
        do {
          if ((*(uint *)(lVar13 + 0x38) & 1) == 0) break;
          StorPortStallExecution(1);
          uVar7 = uVar7 + 1;
        } while (uVar7 < 20000);
      }
      bVar4 = 0;
      if (*(int *)(lVar13 + 0x38) != 0) {
        bVar4 = 4;
      }
      uVar7 = (uint)bVar4;
    }
  }
  return uVar7;
}



===== AhciErrorProcessInISR @ 0001b778 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001b7c4) */

undefined8 AhciErrorProcessInISR(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  longlong lVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined1 auStackY_368 [32];
  undefined4 local_338;
  undefined2 local_333;
  undefined1 local_331;
  undefined1 local_2f8 [78];
  byte local_2aa;
  undefined4 local_2a0;
  undefined1 *local_298;
  undefined4 local_254;
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_368;
  bVar1 = *(byte *)(param_2 + 0x4e);
  uVar6 = 0;
  bVar5 = bVar1 >> 1;
  uVar3 = 0;
  lVar4 = ((longlong)(int)(bVar1 >> 1 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  if ((*(char *)(param_2 + 0x90) == '\b') &&
     (uVar3 = (ulonglong)bVar1, (*(byte *)(param_1 + 0xab8 + uVar3 * 2) & 4) != 0)) {
    *(int *)(param_2 + 0x58) =
         *(int *)(param_2 + 0x58) + *(int *)(param_1 + 0x42e0 + (ulonglong)bVar5 * 4) * -2;
    uVar3 = *(ulonglong *)(param_2 + 0x10);
    *(undefined4 *)(*(longlong *)(uVar3 + 0xf0) + 0x10) = *(undefined4 *)(param_2 + 0x58);
  }
  if (*(char *)(param_2 + 0x90) != '\x03') {
    *(undefined1 *)(param_2 + 0x4b) = 4;
    uVar6 = 1;
    *(undefined4 *)(param_1 + 0x42e0 + (ulonglong)bVar5 * 4) = 0;
    uVar3 = 0;
    if (((*(char *)(param_2 + 0x90) == '/') || (*(char *)(param_2 + 0x90) == -0x71)) &&
       (uVar3 = (ulonglong)*(byte *)(param_2 + 0x4e),
       (*(byte *)(param_1 + 0xab8 + uVar3 * 2) & 2) == 0)) {
      AhciStopPort(param_1,(uint)bVar5);
      *(uint *)(lVar4 + 0x18) = *(uint *)(lVar4 + 0x18) | 0x11;
      *(undefined4 *)(lVar4 + 0x14) = 0;
      memset(local_2f8,0,0xc0);
      local_298 = local_238;
      local_254 = 1;
      local_2a0 = 0x200;
      local_2aa = bVar1;
      memset(&local_338,0,0x40);
      local_338._1_1_ = local_338._1_1_ | 0x80;
      local_338._0_1_ = 0x27;
      local_333 = 0x200;
      local_331 = 0xa0;
      local_338._2_1_ = 0xec;
      uVar2 = IssueAhciCommand(param_1,(longlong)local_2f8,&local_338,(uint *)0x0,'\0','\x01');
      uVar3 = CONCAT44(extraout_var,uVar2);
      *(undefined4 *)(lVar4 + 0x14) = 0xffffffff;
      if ((*(byte *)(lVar4 + 0x20) & 1) == 0) {
        uVar6 = 0;
        *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x4e) * 0xb8 + 0x39a + param_1) = 0;
      }
    }
  }
  return CONCAT71((int7)(uVar3 >> 8),uVar6);
}



===== AhciProcessInterrupt @ 0001b92c =====

/* WARNING: Removing unreachable block (ram,0x0001b966) */
/* WARNING: Removing unreachable block (ram,0x0001b9e5) */

undefined8 AhciProcessInterrupt(ulonglong *param_1,ulonglong param_2)

{
  char *pcVar1;
  byte bVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong lVar13;
  char cVar14;
  byte bVar15;
  
  lVar12 = param_2 + 0x48;
  bVar5 = *(byte *)(param_2 + 0x4e);
  cVar14 = '\0';
  pcVar1 = (char *)(param_2 + 0x4b);
  bVar15 = bVar5 >> 1;
  uVar6 = (bVar5 & 0x80000007) / 2;
  uVar11 = (ulonglong)bVar15;
  uVar9 = param_1[uVar11 + 7];
  uVar3 = param_1[0xb];
  *(undefined1 *)((ulonglong)bVar5 + 0x42f0 + (longlong)param_1) = 0;
  *pcVar1 = '\x01';
  *(undefined1 *)(param_2 + 0x4c) = 0;
  lVar13 = ((ulonglong)uVar6 + 2) * 0x80 + uVar3;
  bVar2 = *(byte *)(lVar13 + 0x20);
  if (((((*(uint *)(lVar13 + 0x38) & 1) == 0) && ((bVar2 & 1) == 0)) &&
      (*(uint *)(uVar9 + 4) < *(uint *)(param_2 + 0xb4))) &&
     ((*(byte *)((longlong)param_1 + (ulonglong)bVar5 * 2 + 0xab8) & 2) == 0)) {
    uVar4 = param_1[0xb];
    uVar7 = (*(byte *)(param_2 + 0x4e) & 0x80000007) / 2;
    lVar10 = ((ulonglong)uVar7 + 2) * 0x80 + uVar4;
    if (*(uint *)(param_2 + 0xb8) < 10) {
      *(undefined4 *)(lVar10 + 0x30) = 0xffffffff;
      *(undefined4 *)(lVar10 + 0x10) = 0xffffffff;
      uVar6 = 1 << (sbyte)uVar7;
      uVar9 = (ulonglong)uVar6;
      *(uint *)(uVar4 + 8) = uVar6;
      *(int *)(param_2 + 0xb8) = *(int *)(param_2 + 0xb8) + 1;
      *(uint *)(lVar10 + 0x38) = *(uint *)(lVar10 + 0x38) | 1;
      goto LAB_0001bb3f;
    }
    *(undefined1 *)(param_2 + 0x4b) = 4;
    cVar14 = '\x01';
  }
  *(undefined4 *)(lVar13 + 0x30) = 0xffffffff;
  *(undefined4 *)(lVar13 + 0x10) = 0xffffffff;
  *(int *)(uVar3 + 8) = 1 << (sbyte)uVar6;
  *(uint *)((longlong)param_1 + uVar11 * 4 + 0x42e0) =
       (uint)(*(int *)(param_2 + 0x58) - *(int *)(uVar9 + 4)) >> 1;
  if ((bVar2 & 1) == 0) {
LAB_0001ba8c:
    if (param_1[uVar11 + 0x869] == 0) {
      AhciFinishCurrentCmd((longlong)param_1,(uint)bVar15);
    }
    else {
LAB_0001ba97:
      uVar9 = AtapiOriginalSubCmd((longlong)param_1,(ulonglong)bVar15,pcVar1);
      if ((char)uVar9 != '\0') goto LAB_0001bb3f;
      param_2 = param_1[uVar11 + 0x68];
      *(char *)(param_2 + 0x4b) = *pcVar1;
      lVar12 = param_2 + 0x48;
    }
  }
  else {
    uVar8 = AhciErrorProcessInISR((longlong)param_1,param_2);
    cVar14 = (char)uVar8;
    if (param_1[uVar11 + 0x869] != 0) goto LAB_0001ba97;
    if (*(char *)(param_2 + 0x90) == '\x03') goto LAB_0001ba8c;
  }
  if (*(char *)(lVar12 + 3) != '\x01') {
    if ((*(byte *)((longlong)param_1 + (ulonglong)*(byte *)(lVar12 + 6) * 2 + 0xab8) & 2) == 0) {
      if (cVar14 != '\0') {
        *(undefined1 *)((ulonglong)*(byte *)(lVar12 + 6) * 0xb8 + 0x39a + (longlong)param_1) = 4;
      }
    }
    else {
      bVar5 = AhciMapError((longlong)param_1,lVar12);
      *(byte *)(lVar12 + 3) = bVar5;
      *(undefined1 *)((longlong)param_1 + uVar11 + 0x250) = 0;
    }
  }
  if ((*(int *)(param_2 + 0xac) != 0) && ((*(uint *)(lVar12 + 0xc) & 0x40) != 0)) {
    memcpy(*(void **)(lVar12 + 0x18),(void *)param_1[0x8fe],(ulonglong)*(uint *)(lVar12 + 0x10));
  }
  uVar9 = StorCompleteSubCmdEx(param_1,param_2);
LAB_0001bb3f:
  return CONCAT71((int7)(uVar9 >> 8),1);
}



===== AhciFinishCurrentCmd @ 0001bb60 =====

ulonglong AhciFinishCurrentCmd(longlong param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  
  uVar4 = (ulonglong)param_2;
  lVar1 = *(longlong *)(param_1 + 0x340 + uVar4 * 8);
  lVar2 = *(longlong *)(param_1 + 0x38 + uVar4 * 8);
  uVar3 = param_2 & 0x80000003;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
  }
  puVar5 = *(undefined1 **)(param_1 + 0x58);
  if ((puVar5[(longlong)(int)uVar3 * 0x80 + 0x120] & 1) == 0) {
    *(undefined1 *)(lVar1 + 0x4b) = 1;
    if (((*(char *)(lVar1 + 0x90) == -1) && (*(char *)(lVar1 + 0x93) == -0x50)) &&
       (*(char *)(lVar1 + 0x96) == -0x26)) {
      if ((*(char *)(lVar2 + 0x445) == -0xc) && (*(char *)(lVar2 + 0x446) == ',')) {
        puVar5 = *(undefined1 **)(lVar1 + 0x60);
        *puVar5 = 1;
      }
      else {
        **(undefined1 **)(lVar1 + 0x60) = 0;
      }
    }
    if ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(lVar1 + 0x4e) * 2) & 2) != 0) {
      puVar5 = (undefined1 *)AtapiSpecifiedCMDFinished(param_1,uVar4);
    }
    uVar4 = CONCAT71((int7)((ulonglong)puVar5 >> 8),1);
  }
  else {
    *(undefined1 *)(lVar1 + 0x4b) = 4;
    uVar4 = (ulonglong)puVar5 & 0xffffffffffffff00;
  }
  return uVar4;
}



===== AhciIsDevReady @ 0001bc10 =====

ulonglong AhciIsDevReady(longlong param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined8 in_RAX;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  uVar6 = (ulonglong)param_2;
  lVar5 = ((ulonglong)(param_2 >> 1 & 3) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  uVar3 = CONCAT71((int7)((ulonglong)in_RAX >> 8),*(byte *)(lVar5 + 0x28)) & 0xffffffffffffff0f;
  if ((char)uVar3 != '\x03') {
    if ((*(byte *)(lVar5 + 0x28) & 1) != 0) {
      uVar2 = *(ushort *)(param_1 + 0xab8 + uVar6 * 2);
      uVar4 = 0x2000;
      if (((uVar2 & 0x2000) == 0) && (uVar4 = 0x8000, (uVar2 & 0x8000) == 0)) {
        uVar4 = AhciResetPort(param_1,param_2 >> 1,'\0');
      }
      uVar3 = CONCAT71((int7)((ulonglong)uVar4 >> 8),*(undefined1 *)(lVar5 + 0x28)) &
              0xffffffffffffff0f;
    }
    if ((char)uVar3 != '\x03') goto LAB_0001bca2;
  }
  if ((*(char *)(param_1 + 0x2c) == '\0') || (*(int *)(lVar5 + 0x30) == 0)) {
    uVar2 = *(ushort *)(param_1 + 0xab8 + uVar6 * 2);
    bVar1 = *(byte *)(lVar5 + 0x20);
    uVar3 = uVar6;
    if (((((uVar2 & 1) == 0) || (((uVar2 & 2) != 0 || ((bVar1 & 0x40) != 0)))) && (-1 < (char)bVar1)
        ) && ((bVar1 & 0x20) == 0)) {
      return CONCAT71((uint7)(uint3)(param_2 >> 8),1);
    }
  }
LAB_0001bca2:
  return uVar3 & 0xffffffffffffff00;
}



===== AhciDispatchSmartCommand @ 0001bcc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001bd39) */

ulonglong AhciDispatchSmartCommand(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong lVar8;
  void *pvVar9;
  undefined7 uVar11;
  undefined7 extraout_var;
  ulonglong uVar10;
  undefined4 extraout_var_01;
  undefined7 extraout_var_00;
  byte bVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  char cVar15;
  uint uVar16;
  ulonglong uVar17;
  bool bVar18;
  undefined1 auStackY_1c8 [32];
  undefined8 local_178 [6];
  undefined8 local_148;
  undefined4 uStack_120;
  longlong local_118;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 local_98;
  undefined1 local_88;
  byte local_87;
  undefined1 local_86;
  char local_85;
  undefined1 local_84;
  undefined2 local_83;
  undefined1 local_81;
  undefined1 local_7c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1c8;
  lVar1 = param_2[0xc];
  local_b0 = *(undefined8 *)(lVar1 + 0x24);
  local_b8 = *(undefined8 *)(lVar1 + 0x1c);
  bVar12 = *(byte *)((longlong)param_2 + 0x4e) >> 1;
  local_a8 = *(undefined8 *)(lVar1 + 0x2c);
  local_a0 = *(undefined8 *)(lVar1 + 0x34);
  local_98 = *(undefined1 *)(lVar1 + 0x3c);
  uVar17 = (ulonglong)bVar12;
  lVar8 = ((longlong)(int)(bVar12 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  cVar15 = (char)((ulonglong)local_b8 >> 0x20);
  *(char *)(uVar17 + 0x4668 + param_1) = cVar15;
  pvVar9 = memset(&local_88,0,0x40);
  uVar11 = (undefined7)((ulonglong)pvVar9 >> 8);
  local_85 = local_b8._4_1_;
  local_87 = local_87 | 0x80;
  local_88 = 0x27;
  local_81 = 0xa0;
  local_84 = local_b8._6_1_;
  local_86 = 0xb0;
  if (cVar15 == -0x30) {
    uVar16 = 0;
    do {
      bVar12 = *(byte *)(lVar8 + 0x20);
      bVar18 = true;
      if ((bVar12 & 0x80) == 0) goto LAB_0001bdd4;
      StorPortStallExecution(0x96);
      uVar16 = uVar16 + 1;
      uVar11 = extraout_var;
    } while (uVar16 < 20000);
    bVar18 = (bVar12 & 0x80) == 0;
LAB_0001bdd4:
    if (bVar18) {
      uVar16 = 0;
      if (*(int *)(lVar1 + 0x18) != 0) {
        do {
          uVar10 = (ulonglong)uVar16;
          uVar16 = uVar16 + 1;
          *(undefined1 *)(uVar10 + 0x1c + lVar1) = 0;
        } while (uVar16 < *(uint *)(lVar1 + 0x18));
      }
      *(longlong *)(param_1 + 0x42f8 + uVar17 * 8) = lVar1 + 0x2c;
      *(undefined4 *)(param_1 + 0x42e0 + uVar17 * 4) = 0x100;
      *(undefined1 *)(uVar17 + 0x42dc + param_1) = 1;
      local_7c = 0;
      local_83 = 0xc24f;
      if ((((uint)param_2 | (uint)local_178) & 0xf) == 0) {
        lVar8 = 1;
        puVar6 = local_178;
        puVar7 = param_2;
        do {
          puVar14 = puVar7;
          puVar13 = puVar6;
          uVar2 = puVar14[1];
          uVar3 = puVar14[2];
          uVar4 = puVar14[3];
          *puVar13 = *puVar14;
          puVar13[1] = uVar2;
          uVar2 = puVar14[4];
          uVar5 = puVar14[5];
          puVar13[2] = uVar3;
          puVar13[3] = uVar4;
          uVar3 = puVar14[6];
          uVar4 = puVar14[7];
          puVar13[4] = uVar2;
          puVar13[5] = uVar5;
          uVar2 = puVar14[8];
          uVar5 = puVar14[9];
          puVar13[6] = uVar3;
          puVar13[7] = uVar4;
          uVar3 = puVar14[10];
          uVar4 = puVar14[0xb];
          puVar13[8] = uVar2;
          puVar13[9] = uVar5;
          uVar2 = puVar14[0xc];
          uVar5 = puVar14[0xd];
          puVar13[10] = uVar3;
          puVar13[0xb] = uVar4;
          uVar3 = puVar14[0xe];
          uVar4 = puVar14[0xf];
          puVar13[0xc] = uVar2;
          puVar13[0xd] = uVar5;
          puVar13[0xe] = uVar3;
          puVar13[0xf] = uVar4;
          lVar8 = lVar8 + -1;
          puVar6 = puVar13 + 0x10;
          puVar7 = puVar14 + 0x10;
        } while (lVar8 != 0);
        uVar2 = puVar14[0x11];
        uVar3 = puVar14[0x12];
        uVar4 = puVar14[0x13];
        puVar13[0x10] = puVar14[0x10];
        puVar13[0x11] = uVar2;
        uVar2 = puVar14[0x14];
        uVar5 = puVar14[0x15];
        puVar13[0x12] = uVar3;
        puVar13[0x13] = uVar4;
        uVar3 = puVar14[0x16];
        uVar4 = puVar14[0x17];
        puVar13[0x14] = uVar2;
        puVar13[0x15] = uVar5;
        puVar13[0x16] = uVar3;
        puVar13[0x17] = uVar4;
      }
      else {
        memcpy(local_178,param_2,0xc0);
      }
      uStack_120 = 0x200;
LAB_0001bec0:
      local_118 = lVar1 + 0x2c;
      local_148 = 0;
      uVar16 = IssueAhciCommand(param_1,(longlong)local_178,(uint *)&local_88,(uint *)0x0,'\x01',
                                '\x01');
      *(undefined1 *)((longlong)param_2 + 0x4b) = 0;
      return CONCAT44(extraout_var_01,uVar16) & 0xffffffffffffff00;
    }
  }
  else {
    if ((7 < (byte)(local_b8._4_1_ + 0x2eU)) ||
       (uVar11 = 0, (0xc5U >> ((byte)(local_b8._4_1_ + 0x2eU) & 0x1f) & 1) == 0)) {
      *(undefined1 *)((longlong)param_2 + 0x4b) = 6;
      goto LAB_0001c036;
    }
    uVar16 = 0;
    do {
      bVar12 = *(byte *)(lVar8 + 0x20);
      bVar18 = true;
      if ((bVar12 & 0x80) == 0) goto LAB_0001bf46;
      StorPortStallExecution(0x96);
      uVar16 = uVar16 + 1;
      uVar11 = extraout_var_00;
    } while (uVar16 < 20000);
    bVar18 = (bVar12 & 0x80) == 0;
LAB_0001bf46:
    if (bVar18) {
      uVar16 = 0;
      if (*(int *)(lVar1 + 0x18) != 0) {
        do {
          uVar10 = (ulonglong)uVar16;
          uVar16 = uVar16 + 1;
          *(undefined1 *)(uVar10 + 0x1c + lVar1) = 0;
        } while (uVar16 < *(uint *)(lVar1 + 0x18));
      }
      local_7c = local_b8._5_1_;
      *(longlong *)(param_1 + 0x42f8 + uVar17 * 8) = lVar1 + 0x2c;
      *(undefined4 *)(param_1 + 0x42e0 + uVar17 * 4) = 0;
      local_83 = CONCAT11((undefined1)local_b0,local_b8._7_1_);
      *(undefined1 *)(uVar17 + 0x42dc + param_1) = 1;
      if ((((uint)param_2 | (uint)local_178) & 0xf) == 0) {
        lVar8 = 1;
        puVar6 = local_178;
        puVar7 = param_2;
        do {
          puVar14 = puVar7;
          puVar13 = puVar6;
          uVar2 = puVar14[1];
          uVar3 = puVar14[2];
          uVar4 = puVar14[3];
          *puVar13 = *puVar14;
          puVar13[1] = uVar2;
          uVar2 = puVar14[4];
          uVar5 = puVar14[5];
          puVar13[2] = uVar3;
          puVar13[3] = uVar4;
          uVar3 = puVar14[6];
          uVar4 = puVar14[7];
          puVar13[4] = uVar2;
          puVar13[5] = uVar5;
          uVar2 = puVar14[8];
          uVar5 = puVar14[9];
          puVar13[6] = uVar3;
          puVar13[7] = uVar4;
          uVar3 = puVar14[10];
          uVar4 = puVar14[0xb];
          puVar13[8] = uVar2;
          puVar13[9] = uVar5;
          uVar2 = puVar14[0xc];
          uVar5 = puVar14[0xd];
          puVar13[10] = uVar3;
          puVar13[0xb] = uVar4;
          uVar3 = puVar14[0xe];
          uVar4 = puVar14[0xf];
          puVar13[0xc] = uVar2;
          puVar13[0xd] = uVar5;
          puVar13[0xe] = uVar3;
          puVar13[0xf] = uVar4;
          lVar8 = lVar8 + -1;
          puVar6 = puVar13 + 0x10;
          puVar7 = puVar14 + 0x10;
        } while (lVar8 != 0);
        uVar2 = puVar14[0x11];
        uVar3 = puVar14[0x12];
        uVar4 = puVar14[0x13];
        puVar13[0x10] = puVar14[0x10];
        puVar13[0x11] = uVar2;
        uVar2 = puVar14[0x14];
        uVar5 = puVar14[0x15];
        puVar13[0x12] = uVar3;
        puVar13[0x13] = uVar4;
        uVar3 = puVar14[0x16];
        uVar4 = puVar14[0x17];
        puVar13[0x14] = uVar2;
        puVar13[0x15] = uVar5;
        puVar13[0x16] = uVar3;
        puVar13[0x17] = uVar4;
      }
      else {
        memcpy(local_178,param_2,0xc0);
      }
      uStack_120 = 0;
      goto LAB_0001bec0;
    }
  }
  *(undefined1 *)((longlong)param_2 + 0x4b) = 5;
LAB_0001c036:
  return CONCAT71(uVar11,1);
}



===== AhciDispatchUserSmartCommand @ 0001c064 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0b0) */

undefined8 AhciDispatchUserSmartCommand(longlong param_1,undefined8 *param_2)

{
  byte bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  byte bVar7;
  void *pvVar8;
  undefined8 uVar9;
  longlong lVar10;
  undefined4 extraout_var;
  undefined8 *puVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  uint uVar14;
  undefined1 auStackY_188 [32];
  undefined8 local_148 [6];
  undefined8 local_118;
  undefined4 uStack_f0;
  undefined8 local_e8;
  undefined1 local_88;
  byte local_87;
  undefined1 local_86;
  undefined1 local_85;
  undefined1 local_84 [3];
  undefined1 local_81;
  undefined1 local_7c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  bVar1 = *(byte *)((longlong)param_2 + 0x95);
  lVar10 = *(longlong *)(param_1 + 0x58);
  pvVar8 = memset(&local_88,0,0x40);
  local_85 = *(undefined1 *)((longlong)param_2 + 0x96);
  uVar9 = CONCAT71((int7)((ulonglong)pvVar8 >> 8),local_85);
  local_87 = local_87 | 0x80;
  local_88 = 0x27;
  local_81 = 0xa0;
  local_86 = 0xb0;
  uVar14 = 0;
  do {
    bVar7 = *(byte *)(((longlong)(int)(bVar1 >> 1 & 0x80000003) + 2) * 0x80 + lVar10 + 0x20);
    if ((bVar7 & 0x80) == 0) goto LAB_0001c123;
    uVar9 = StorPortStallExecution(0x96);
    uVar14 = uVar14 + 1;
  } while (uVar14 < 20000);
  if ((bVar7 & 0x80) == 0) {
LAB_0001c123:
    if ((((bVar7 & 0x40) != 0) && ((bVar7 & 1) == 0)) && ((bVar7 & 0x20) == 0)) {
      uVar12 = (ulonglong)(bVar1 >> 1);
      *(undefined1 *)(uVar12 + 0x4668 + param_1) = *(undefined1 *)((longlong)param_2 + 0x96);
      if (*(char *)((longlong)param_2 + 0x96) == -0x30) {
        local_7c = 0;
        *(undefined8 *)(param_1 + 0x42f8 + (ulonglong)bVar1 * 8) = param_2[0xc];
        *(undefined4 *)(param_1 + 0x42e0 + (ulonglong)bVar1 * 4) = 0x100;
        *(undefined1 *)(uVar12 + 0x42dc + param_1) = 1;
        local_84 = (undefined1  [3])0xc24f00;
        if ((((uint)param_2 | (uint)local_148) & 0xf) == 0) {
          lVar10 = 1;
          puVar5 = local_148;
          puVar6 = param_2;
          do {
            puVar13 = puVar6;
            puVar11 = puVar5;
            uVar9 = puVar13[1];
            uVar2 = puVar13[2];
            uVar3 = puVar13[3];
            *puVar11 = *puVar13;
            puVar11[1] = uVar9;
            uVar9 = puVar13[4];
            uVar4 = puVar13[5];
            puVar11[2] = uVar2;
            puVar11[3] = uVar3;
            uVar2 = puVar13[6];
            uVar3 = puVar13[7];
            puVar11[4] = uVar9;
            puVar11[5] = uVar4;
            uVar9 = puVar13[8];
            uVar4 = puVar13[9];
            puVar11[6] = uVar2;
            puVar11[7] = uVar3;
            uVar2 = puVar13[10];
            uVar3 = puVar13[0xb];
            puVar11[8] = uVar9;
            puVar11[9] = uVar4;
            uVar9 = puVar13[0xc];
            uVar4 = puVar13[0xd];
            puVar11[10] = uVar2;
            puVar11[0xb] = uVar3;
            uVar2 = puVar13[0xe];
            uVar3 = puVar13[0xf];
            puVar11[0xc] = uVar9;
            puVar11[0xd] = uVar4;
            puVar11[0xe] = uVar2;
            puVar11[0xf] = uVar3;
            lVar10 = lVar10 + -1;
            puVar5 = puVar11 + 0x10;
            puVar6 = puVar13 + 0x10;
          } while (lVar10 != 0);
          uVar9 = puVar13[0x11];
          uVar2 = puVar13[0x12];
          uVar3 = puVar13[0x13];
          puVar11[0x10] = puVar13[0x10];
          puVar11[0x11] = uVar9;
          uVar9 = puVar13[0x14];
          uVar4 = puVar13[0x15];
          puVar11[0x12] = uVar2;
          puVar11[0x13] = uVar3;
          uVar2 = puVar13[0x16];
          uVar3 = puVar13[0x17];
          puVar11[0x14] = uVar9;
          puVar11[0x15] = uVar4;
          puVar11[0x16] = uVar2;
          puVar11[0x17] = uVar3;
        }
        else {
          memcpy(local_148,param_2,0xc0);
        }
        uStack_f0 = 0x200;
LAB_0001c32c:
        local_118 = 0;
        local_e8 = param_2[0xc];
        uVar14 = IssueAhciCommand(param_1,(longlong)local_148,(uint *)&local_88,(uint *)0x0,'\x01',
                                  '\x01');
        *(undefined1 *)((longlong)param_2 + 0x4b) = 0;
        return CONCAT44(extraout_var,uVar14) & 0xffffffffffffff00;
      }
      bVar7 = *(char *)((longlong)param_2 + 0x96) + 0x2e;
      uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),bVar7);
      if ((bVar7 < 9) && (uVar9 = 0, (0x1c5U >> (bVar7 & 0x1f) & 1) != 0)) {
        *(undefined8 *)(param_1 + 0x42f8 + (ulonglong)bVar1 * 8) = param_2[0xc];
        *(undefined4 *)(param_1 + 0x42e0 + (ulonglong)bVar1 * 4) = 0;
        *(undefined1 *)(uVar12 + 0x42dc + param_1) = 1;
        local_7c = *(undefined1 *)((longlong)param_2 + 0x97);
        local_84._1_2_ = 0xc24f;
        local_84[0] = *(undefined1 *)(param_2 + 0x13);
        if ((((uint)param_2 | (uint)local_148) & 0xf) == 0) {
          lVar10 = 1;
          puVar5 = local_148;
          puVar6 = param_2;
          do {
            puVar13 = puVar6;
            puVar11 = puVar5;
            uVar9 = puVar13[1];
            uVar2 = puVar13[2];
            uVar3 = puVar13[3];
            *puVar11 = *puVar13;
            puVar11[1] = uVar9;
            uVar9 = puVar13[4];
            uVar4 = puVar13[5];
            puVar11[2] = uVar2;
            puVar11[3] = uVar3;
            uVar2 = puVar13[6];
            uVar3 = puVar13[7];
            puVar11[4] = uVar9;
            puVar11[5] = uVar4;
            uVar9 = puVar13[8];
            uVar4 = puVar13[9];
            puVar11[6] = uVar2;
            puVar11[7] = uVar3;
            uVar2 = puVar13[10];
            uVar3 = puVar13[0xb];
            puVar11[8] = uVar9;
            puVar11[9] = uVar4;
            uVar9 = puVar13[0xc];
            uVar4 = puVar13[0xd];
            puVar11[10] = uVar2;
            puVar11[0xb] = uVar3;
            uVar2 = puVar13[0xe];
            uVar3 = puVar13[0xf];
            puVar11[0xc] = uVar9;
            puVar11[0xd] = uVar4;
            puVar11[0xe] = uVar2;
            puVar11[0xf] = uVar3;
            lVar10 = lVar10 + -1;
            puVar5 = puVar11 + 0x10;
            puVar6 = puVar13 + 0x10;
          } while (lVar10 != 0);
          uVar9 = puVar13[0x11];
          uVar2 = puVar13[0x12];
          uVar3 = puVar13[0x13];
          puVar11[0x10] = puVar13[0x10];
          puVar11[0x11] = uVar9;
          uVar9 = puVar13[0x14];
          uVar4 = puVar13[0x15];
          puVar11[0x12] = uVar2;
          puVar11[0x13] = uVar3;
          uVar2 = puVar13[0x16];
          uVar3 = puVar13[0x17];
          puVar11[0x14] = uVar9;
          puVar11[0x15] = uVar4;
          puVar11[0x16] = uVar2;
          puVar11[0x17] = uVar3;
        }
        else {
          memcpy(local_148,param_2,0xc0);
        }
        uStack_f0 = 0;
        goto LAB_0001c32c;
      }
      *(undefined1 *)((longlong)param_2 + 0x4b) = 6;
      goto LAB_0001c35e;
    }
  }
  *(undefined1 *)((longlong)param_2 + 0x4b) = 4;
LAB_0001c35e:
  return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
}



===== AhciDispatchOneAtapiSubCmd @ 0001c388 =====

/* WARNING: Removing unreachable block (ram,0x0001c3d6) */

void AhciDispatchOneAtapiSubCmd(longlong param_1,longlong param_2,undefined8 param_3)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  ushort uVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined1 uVar13;
  byte bVar14;
  undefined1 uVar15;
  undefined8 local_88;
  undefined8 local_80;
  undefined1 local_68;
  byte local_67;
  undefined1 local_66;
  byte local_65;
  undefined1 local_63;
  undefined1 local_62;
  undefined1 local_61;
  
  bVar2 = *(byte *)(param_2 + 0x4e);
  uVar7 = *(ushort *)(param_1 + 0xab8 + (ulonglong)bVar2 * 2);
  bVar14 = bVar2 >> 1;
  lVar11 = ((longlong)(int)(bVar14 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  bVar3 = *(byte *)(lVar11 + 0x20);
  if ((char)bVar3 < '\0') {
    *(undefined1 *)(param_2 + 0x4b) = 5;
  }
  else {
    if ((bVar3 & 1) != 0) {
      AhciStopPort(param_1,(uint)bVar14);
      *(uint *)(lVar11 + 0x18) = *(uint *)(lVar11 + 0x18) | 0x11;
    }
    if ((bVar3 & 8) != 0) {
      uVar9 = 0;
      do {
        if ((*(byte *)(lVar11 + 0x20) & 8) == 0) break;
        uVar9 = uVar9 + 1;
      } while (uVar9 < 0x10000);
      if (uVar9 == 0x10000) {
        AhciSoftwareReset(param_1,(uint)bVar14);
        *(undefined1 *)((ulonglong)bVar14 + 0x42dc + param_1) = 0;
        *(undefined1 *)((ulonglong)bVar14 + 0x250 + param_1) = 0;
        IssueIdentify(param_1,(uint)*(byte *)(param_2 + 0x4e),
                      CONCAT71((int7)((ulonglong)param_3 >> 8),0xa1));
        StorPortNotification(3,param_1);
        *(undefined1 *)(param_2 + 0x4b) = 0xe;
        return;
      }
    }
    uVar9 = 0;
    if ((((uVar7 & 0xc0) != 0) &&
        (*(byte *)(param_2 + 0x91) = *(byte *)(param_2 + 0x91) & 0x1f,
        *(char *)(param_2 + 0x90) == '\0')) && ((char)uVar7 < '\0')) {
      *(undefined1 *)(param_2 + 0x97) = *(undefined1 *)(param_2 + 0x4f);
    }
    uVar12 = (ulonglong)bVar14;
    pcVar1 = (char *)(param_2 + 0x90);
    *(undefined4 *)(param_1 + 0x4690 + uVar12 * 4) = 0;
    cVar4 = *pcVar1;
    if (cVar4 == '\x15') {
      *(undefined2 *)(param_2 + 0x4b) = 1;
      if ((uVar7 & 4) == 0) {
        *(undefined1 *)(uVar12 + 0x42dc + param_1) = 0;
        *(undefined1 *)(param_2 + 0x4b) = 1;
        return;
      }
    }
    else if (cVar4 == '\x1a') {
      if ((uVar7 & 4) == 0) {
        uVar13 = *(undefined1 *)(param_2 + 0x92);
        uVar15 = *(undefined1 *)(param_2 + 0x93);
        uVar5 = *(undefined1 *)(param_2 + 0x94);
        uVar6 = *(undefined1 *)(param_2 + 0x95);
        *(undefined1 *)(param_2 + 0x52) = 0xc;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        pcVar1[4] = '\0';
        pcVar1[5] = '\0';
        pcVar1[6] = '\0';
        pcVar1[7] = '\0';
        *(undefined4 *)(param_2 + 0x98) = 0;
        *pcVar1 = 'Z';
        *(undefined1 *)(param_2 + 0x92) = uVar13;
        *(undefined1 *)(param_2 + 0x98) = 0;
        *(undefined1 *)(param_2 + 0x97) = uVar5;
        *(undefined1 *)(param_2 + 0x93) = uVar15;
        *(undefined1 *)(param_2 + 0x99) = uVar6;
        *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_1 + 0x47f0);
        *(undefined4 *)(param_2 + 0xa4) = 1;
      }
    }
    else if (cVar4 == 'Z') {
      *(undefined4 *)(param_1 + 0x4690 + uVar12 * 4) = 1;
    }
    bVar3 = *(byte *)(param_2 + 0x54);
    lVar8 = *(longlong *)(param_2 + 0x60);
    *(longlong *)(param_1 + 0x42f8 + uVar12 * 8) = lVar8;
    if ((lVar8 == 0) && ((*(uint *)(param_2 + 0x54) & 0xc0) != 0)) {
      lVar8 = *(longlong *)(param_2 + 0x10);
      if (lVar8 == 0) {
        lVar10 = 0;
      }
      else {
        lVar10 = *(longlong *)(*(longlong *)(lVar8 + 0xf0) + 0x38);
      }
      if ((lVar10 != 0) && (*(int *)(lVar10 + 0x27c) == 0)) {
        *(undefined8 *)(param_1 + 0x42f8 + uVar12 * 8) = *(undefined8 *)(lVar8 + 0xed8);
      }
    }
    *(uint *)(param_1 + 0x42e0 + uVar12 * 4) = *(uint *)(param_2 + 0x58) >> 1;
    do {
      if (-1 < *(char *)(lVar11 + 0x20)) break;
      StorPortStallExecution(0x96);
      uVar9 = uVar9 + 1;
    } while (uVar9 < 20000);
    memset(&local_88,0,0x20);
    if ((char *)&local_88 != pcVar1) {
      local_88 = *(undefined8 *)pcVar1;
      local_80 = *(undefined8 *)(param_2 + 0x98);
    }
    uVar13 = *(undefined1 *)(param_2 + 0x58);
    uVar15 = (undefined1)((uint)*(undefined4 *)(param_2 + 0x58) >> 8);
    if (0xffff < *(uint *)(param_2 + 0x58)) {
      uVar13 = 0xff;
      uVar15 = 0xff;
    }
    memset(&local_68,0,0x40);
    local_67 = local_67 | 0x80;
    bVar14 = *(byte *)((ulonglong)*(byte *)(param_2 + 0x4e) * 0xb8 + 0x39c + param_1) & 0xf;
    local_68 = 0x27;
    local_61 = 0xa0;
    local_66 = 0xa0;
    if ((*(longlong *)(param_2 + 0x10) != 0) &&
       (*(char *)(*(longlong *)(param_2 + 0x10) + 0x101) != '\0')) {
      bVar14 = 0;
    }
    if ((bVar14 & 4) == 0) {
      local_65 = 0;
    }
    else {
      local_65 = ~(*(byte *)(param_2 + 0x54) >> 5) & 4 | 1;
    }
    local_63 = uVar13;
    local_62 = uVar15;
    uVar9 = IssueAhciCommand(param_1,param_2,(uint *)&local_68,(uint *)&local_88,'\x01',
                             ~(bVar3 >> 7) & 1);
    if ((((*(byte *)(param_1 + 0xac8 + (ulonglong)bVar2 * 2) & 1) != 0) && (uVar9 == 4)) &&
       (*pcVar1 == '\0')) {
      *(uint *)(lVar11 + 0x18) = *(uint *)(lVar11 + 0x18) | 1;
    }
  }
  return;
}



===== AhciDisableDevIPM @ 0001c708 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AhciDisableDevIPM(longlong param_1,int param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 extraout_var;
  undefined8 uVar3;
  longlong lVar4;
  char cVar5;
  undefined1 auStackY_168 [32];
  undefined4 local_138;
  undefined1 local_131;
  undefined1 local_12c;
  undefined1 local_f8 [78];
  undefined1 local_aa;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  uVar1 = param_2 >> 1 & 0x80000003;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;
  }
  uVar2 = (ulonglong)uVar1;
  lVar4 = ((longlong)(int)uVar1 + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  if (*(int *)(param_1 + 0x4834) == 0) {
    uVar1 = 0;
    do {
      cVar5 = *(char *)(lVar4 + 0x20);
      if (-1 < cVar5) goto LAB_0001c798;
      uVar2 = StorPortStallExecution(0x96);
      uVar1 = uVar1 + 1;
    } while (uVar1 < 20000);
  }
  else {
    cVar5 = *(char *)(lVar4 + 0x20);
  }
  if (cVar5 < '\0') {
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
LAB_0001c798:
    memset(local_f8,0,0xc0);
    local_aa = (undefined1)param_2;
    memset(&local_138,0,0x40);
    local_138._1_1_ = local_138._1_1_ | 0x80;
    local_138._0_1_ = 0x27;
    local_138._2_2_ = 0x90ef;
    local_12c = 3;
    local_131 = 0xa0;
    uVar1 = IssueAhciCommand(param_1,(longlong)local_f8,&local_138,(uint *)0x0,'\0','\0');
    uVar3 = CONCAT44(extraout_var,uVar1);
    if ((*(byte *)(lVar4 + 0x20) & 1) != 0) {
      uVar3 = AhciStopPort(param_1,param_2 >> 1);
      *(uint *)(lVar4 + 0x18) = *(uint *)(lVar4 + 0x18) | 0x11;
    }
    uVar2 = CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  return uVar2;
}



===== AhciReadWriteHDDSector @ 0001c838 =====

/* WARNING: Removing unreachable block (ram,0x0001c86b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1
AhciReadWriteHDDSector
          (longlong param_1,ulonglong param_2,ulonglong param_3,undefined8 param_4,char param_5)

{
  byte bVar1;
  byte bVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  
  uVar3 = param_2 & 0xffffffff;
  lVar4 = ((longlong)(int)((uint)(param_2 >> 1) & 3) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
  if (((byte)*(undefined4 *)(lVar4 + 0x28) & 0xf) == 3) {
    uVar6 = 0;
    do {
      bVar2 = *(byte *)(lVar4 + 0x20);
      if (-1 < (char)bVar2) goto LAB_0001c8bb;
      StorPortStallExecution(0x96);
      uVar6 = uVar6 + 1;
    } while (uVar6 < 20000);
    if (-1 < (char)bVar2) {
LAB_0001c8bb:
      if ((((bVar2 & 0x40) != 0) && ((bVar2 & 1) == 0)) && ((bVar2 & 0x20) == 0)) {
        bVar2 = (byte)uVar3;
        _DAT_0003641c = 1;
        _DAT_000363c8 = 0x200;
        _DAT_00036414 = 1;
        DAT_000363be = bVar2;
        _DAT_000363d0 = param_4;
        memset(&DAT_00036330,0,0x40);
        DAT_00036331 = DAT_00036331 | 0x80;
        lVar4 = uVar3 * 0xb8;
        DAT_00036330 = 0x27;
        uVar6 = *(uint *)(lVar4 + 0x39c + param_1);
        if ((uVar6 & 0x10) == 0) {
          lVar5 = uVar3 * 0xd4;
          if (0xffffffff < param_3) {
            DAT_00036330 = 0x27;
            return 4;
          }
          DAT_00036334 = (char)(param_3 % (ulonglong)*(ushort *)(lVar5 + 0xd20 + param_1)) + '\x01';
          DAT_00036335 = (undefined1)
                         (param_3 /
                         (ulonglong)
                         (longlong)
                         (int)((uint)*(ushort *)(lVar5 + 0xd20 + param_1) *
                              (uint)*(ushort *)(lVar5 + 0xd1a + param_1)));
          DAT_00036336 = (undefined1)
                         (param_3 / (ulonglong)
                                    (longlong)
                                    (int)((uint)*(ushort *)(lVar5 + 0xd20 + param_1) *
                                         (uint)*(ushort *)(lVar5 + 0xd1a + param_1)) >> 8);
          DAT_00036337 = (byte)((param_3 / *(ushort *)(lVar5 + 0xd20 + param_1)) %
                               (ulonglong)*(ushort *)(lVar5 + 0xd1a + param_1)) |
                         (bVar2 & 1 | 0xfa) << 4;
        }
        else {
          bVar1 = (byte)(param_3 >> 0x18);
          if ((uVar6 & 0x20) != 0) {
            DAT_0003633d = 0;
            DAT_0003633a = (undefined1)(param_3 >> 0x28);
            DAT_00036339 = (undefined1)(param_3 >> 0x20);
            DAT_00036338 = bVar1;
          }
          DAT_00036334 = (char)param_3;
          DAT_00036337 = (bVar2 | 0xfe) << 4;
          DAT_00036336 = (undefined1)(param_3 >> 0x10);
          DAT_00036335 = (undefined1)(param_3 >> 8);
          if ((*(uint *)(lVar4 + 0x39c + param_1) & 0x20) == 0) {
            DAT_00036337 = DAT_00036337 | bVar1;
          }
        }
        DAT_0003633c = 1;
        bVar2 = *(byte *)(lVar4 + 0x39c + param_1) >> 3 & 4;
        if (param_5 == '\0') {
          DAT_00036332 = bVar2 | 0x20;
        }
        else {
          DAT_00036332 = bVar2 | 0x30;
        }
        IssueAhciCommand(param_1,0x36370,(uint *)&DAT_00036330,(uint *)0x0,'\0',param_5 == '\0');
        return DAT_000363bb;
      }
    }
  }
  return 4;
}



===== AhciSoftwareResetDisableINT @ 0001caec =====

undefined8 AhciSoftwareResetDisableINT(longlong param_1,uint param_2)

{
  ushort uVar1;
  uint *puVar2;
  uint *_Dst;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  
  uVar5 = param_2 & 0x80000003;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
  }
  puVar2 = *(uint **)(param_1 + 0x58);
  _Dst = *(uint **)(param_1 + 0x38 + (longlong)(int)param_2 * 8);
  lVar8 = (longlong)(int)uVar5 + 2;
  AhciStopPort(param_1,param_2);
  uVar6 = 0;
  uVar7 = 0;
  do {
    uVar3 = puVar2[lVar8 * 0x20 + 8];
    if ((uVar3 & 0x88) == 0) goto LAB_0001cb7b;
    StorPortStallExecution(1);
    uVar7 = uVar7 + 1;
  } while (uVar7 < 20000);
  if ((uVar3 & 0x88) != 0) {
    if ((*puVar2 >> 0x18 & 1) == 0) {
      return (ulonglong)(uint3)(*puVar2 >> 8) << 8;
    }
    puVar2[lVar8 * 0x20 + 6] = puVar2[lVar8 * 0x20 + 6] | 8;
  }
LAB_0001cb7b:
  puVar2[lVar8 * 0x20 + 6] = puVar2[lVar8 * 0x20 + 6] | 0x11;
  puVar2[lVar8 * 0x20 + 0xc] = 0xffffffff;
  puVar2[lVar8 * 0x20 + 4] = 0xffffffff;
  puVar2[lVar8 * 0x20 + 5] = 0;
  puVar2[2] = 1 << ((byte)uVar5 & 0x1f);
  memset(_Dst + 0x140,0,0x40);
  *(byte *)((longlong)_Dst + 0x501) = *(byte *)((longlong)_Dst + 0x501) & 0x7f;
  *(undefined1 *)(_Dst + 0x140) = 0x27;
  *(undefined1 *)((longlong)_Dst + 0x50f) = 4;
  *(undefined1 *)((longlong)_Dst + 0x507) = 0xa0;
  uVar5 = _Dst[2];
  uVar7 = _Dst[3];
  memset(_Dst,0,0x20);
  _Dst[3] = uVar7;
  *_Dst = *_Dst & 0xffffffe5 | 0x505;
  _Dst[2] = uVar5;
  memset(_Dst + 0x280,0,0x40);
  *(byte *)((longlong)_Dst + 0xa01) = *(byte *)((longlong)_Dst + 0xa01) & 0x7f;
  *(undefined1 *)(_Dst + 0x280) = 0x27;
  *(undefined1 *)((longlong)_Dst + 0xa0f) = 0;
  *(undefined1 *)((longlong)_Dst + 0xa07) = 0xa0;
  uVar5 = _Dst[10];
  uVar7 = _Dst[0xb];
  memset(_Dst + 8,0,0x20);
  _Dst[0xb] = uVar7;
  _Dst[10] = uVar5;
  _Dst[8] = _Dst[8] & 0xfffffae5 | 5;
  puVar2[lVar8 * 0x20 + 0xe] = puVar2[lVar8 * 0x20 + 0xe] | 1;
  uVar4 = StorPortStallExecution(0x14);
  puVar2[lVar8 * 0x20 + 0xe] = puVar2[lVar8 * 0x20 + 0xe] | 2;
  if (*(int *)(param_1 + 0x4834) == 0) {
    if ((*(int *)(param_1 + 0x4870) == 0) && (*(char *)(param_1 + 0x2d) == '\0')) {
      do {
        uVar4 = (ulonglong)puVar2[lVar8 * 0x20 + 0xe];
        if ((puVar2[lVar8 * 0x20 + 0xe] & 3) == 0) break;
        uVar4 = StorPortStallExecution(1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < 6000000);
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0xab8 + (longlong)(int)param_2 * 4);
      uVar4 = (ulonglong)uVar1;
      if ((uVar1 & 0x2000) == 0) {
        do {
          if ((puVar2[lVar8 * 0x20 + 0xe] & 3) == 0) break;
          uVar4 = StorPortStallExecution(1);
          uVar6 = uVar6 + 1;
        } while (uVar6 < 600000);
      }
      else {
        do {
          uVar4 = (ulonglong)puVar2[lVar8 * 0x20 + 0xe];
          if ((puVar2[lVar8 * 0x20 + 0xe] & 3) == 0) break;
          uVar4 = StorPortStallExecution(1);
          uVar6 = uVar6 + 1;
        } while (uVar6 < 100000);
      }
    }
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== AhciResetPort_for_ErrorDisk_disableINT @ 0001ccf4 =====

void AhciResetPort_for_ErrorDisk_disableINT(longlong param_1,uint param_2)

{
  ushort uVar1;
  uint *puVar2;
  bool bVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  uint uVar8;
  int iVar9;
  
  bVar3 = false;
  uVar5 = 300000;
  if (*(int *)(param_1 + 0x4834) != 0) {
    AhciPowerResetPort(param_1,param_2,'\0');
    return;
  }
  uVar8 = param_2 & 0x80000003;
  if ((int)uVar8 < 0) {
    uVar8 = (uVar8 - 1 | 0xfffffffc) + 1;
  }
  puVar2 = *(uint **)(param_1 + 0x58);
  iVar9 = 0;
  lVar4 = (longlong)(int)uVar8 + 2;
  puVar2[lVar4 * 0x20 + 5] = 0;
  do {
    puVar2[lVar4 * 0x20 + 0xc] = 0xffffffff;
    puVar2[lVar4 * 0x20 + 4] = 0xffffffff;
    puVar2[2] = 1 << ((byte)uVar8 & 0x1f);
    puVar2[lVar4 * 0x20 + 6] = puVar2[lVar4 * 0x20 + 6] & 0xffffffee;
    if ((*puVar2 >> 0x1b & 1) == 0) {
      if (bVar3) {
        DbgPrint("HBA NOT support staggered spin-up, force to do normal COMRESET\n");
        bVar3 = false;
        goto LAB_0001cdbd;
      }
LAB_0001cdea:
      DbgPrint("do com reset on AHCI port %d\n",uVar8);
      puVar2[lVar4 * 0x20 + 0xb] = puVar2[lVar4 * 0x20 + 0xb] | 1;
      puVar2[lVar4 * 0x20 + 6] = puVar2[lVar4 * 0x20 + 6] | 0x10;
      lVar7 = 2;
      do {
        StorPortStallExecution(1000);
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      StorPortStallExecution(0);
      puVar2[lVar4 * 0x20 + 0xb] = puVar2[lVar4 * 0x20 + 0xb] & 0xfffffffe;
      lVar7 = 2;
      do {
        StorPortStallExecution(1000);
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      StorPortStallExecution(0);
    }
    else {
      if ((puVar2[lVar4 * 0x20 + 6] & 2) == 0) {
        if (!bVar3) {
          DbgPrint("port %d PxCMD.SUD is 0, force to do spin-up\n",uVar8);
          bVar3 = true;
          goto LAB_0001cdbd;
        }
      }
      else {
LAB_0001cdbd:
        if (!bVar3) goto LAB_0001cdea;
      }
      DbgPrint("do stagger spin up on AHCI port %d\n",uVar8);
      puVar2[lVar4 * 0x20 + 0xb] = puVar2[lVar4 * 0x20 + 0xb] & 0xfffffffe;
      puVar2[lVar4 * 0x20 + 6] = puVar2[lVar4 * 0x20 + 6] & 0xfffffffd;
      StorPortStallExecution(100);
      puVar2[lVar4 * 0x20 + 6] = puVar2[lVar4 * 0x20 + 6] | 0x12;
    }
    uVar6 = 0;
    do {
      if ((puVar2[lVar4 * 0x20 + 4] & 0x40) != 0) {
        puVar2[lVar4 * 0x20 + 0xc] = puVar2[lVar4 * 0x20 + 0xc] | 0x4000000;
        break;
      }
      StorPortStallExecution(10);
      uVar6 = uVar6 + 1;
    } while (uVar6 < 1000);
    lVar7 = 10;
    do {
      StorPortStallExecution(1000);
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    StorPortStallExecution(0);
    if ((puVar2[lVar4 * 0x20 + 10] & 1) == 0) {
      puVar2[lVar4 * 0x20 + 6] = puVar2[lVar4 * 0x20 + 6] & 0xffffffee;
      return;
    }
    if ((char)puVar2[lVar4 * 0x20 + 8] < '\0') {
      uVar1 = *(ushort *)(param_1 + 0xab8 + (longlong)(int)param_2 * 4);
      if ((uVar1 & 0x8000) == 0) {
        if ((uVar1 & 0x2000) != 0) {
          uVar5 = 10000;
        }
      }
      else {
        uVar5 = 300000;
      }
      uVar6 = 0;
      if (uVar5 != 0) {
        do {
          if (-1 < (char)puVar2[lVar4 * 0x20 + 8]) break;
          StorPortStallExecution(10);
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar5);
      }
    }
    uVar6 = 0;
    do {
      if ((char)(puVar2[lVar4 * 0x20 + 8] >> 8) == '\x01') break;
      StorPortStallExecution(10);
      uVar6 = uVar6 + 1;
    } while (uVar6 < 1000);
    puVar2[lVar4 * 0x20 + 6] = puVar2[lVar4 * 0x20 + 6] | 0x11;
    if ((char)puVar2[lVar4 * 0x20 + 8] < '\0') {
      AhciSoftwareResetDisableINT(param_1,param_2);
      uVar1 = *(ushort *)(param_1 + 0xab8 + (longlong)(int)param_2 * 4);
      if ((uVar1 & 0x8000) == 0) {
        if ((uVar1 & 0x2000) != 0) {
          uVar5 = 200;
        }
      }
      else {
        uVar5 = 7000;
      }
      uVar6 = 0;
      if (uVar5 != 0) {
        do {
          if (-1 < (char)puVar2[lVar4 * 0x20 + 8]) break;
          StorPortStallExecution(0x96);
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar5);
      }
    }
    if ((-1 < (char)(byte)puVar2[lVar4 * 0x20 + 8]) &&
       (((byte)puVar2[lVar4 * 0x20 + 8] & 0x20) == 0)) {
      return;
    }
    iVar9 = iVar9 + 1;
    if (0 < iVar9) {
      return;
    }
  } while( true );
}



===== AhciResetPort_for_ErrorDisk @ 0001cf98 =====

void AhciResetPort_for_ErrorDisk(longlong param_1,uint param_2)

{
  ushort uVar1;
  uint *puVar2;
  bool bVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  uint uVar9;
  int local_res18;
  
  bVar3 = false;
  uVar6 = 300000;
  if (*(int *)(param_1 + 0x4834) == 0) {
    uVar9 = param_2 & 0x80000003;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
    }
    puVar2 = *(uint **)(param_1 + 0x58);
    local_res18 = 0;
    lVar5 = (longlong)(int)uVar9 + 2;
    puVar2[lVar5 * 0x20 + 5] = 0;
    uVar4 = 1 << ((byte)uVar9 & 0x1f);
LAB_0001d012:
    puVar2[lVar5 * 0x20 + 0xc] = 0xffffffff;
    puVar2[lVar5 * 0x20 + 4] = 0xffffffff;
    puVar2[2] = uVar4;
    puVar2[lVar5 * 0x20 + 6] = puVar2[lVar5 * 0x20 + 6] & 0xffffffee;
    if ((*puVar2 & 0x8000000) == 0) {
      if (bVar3) {
        DbgPrint("HBA NOT support staggered spin-up, force to do normal COMRESET\n");
        bVar3 = false;
        goto LAB_0001d062;
      }
LAB_0001d08f:
      DbgPrint("do com reset on AHCI port %d\n",uVar9);
      puVar2[lVar5 * 0x20 + 0xb] = puVar2[lVar5 * 0x20 + 0xb] | 1;
      puVar2[lVar5 * 0x20 + 6] = puVar2[lVar5 * 0x20 + 6] | 0x10;
      lVar8 = 2;
      do {
        StorPortStallExecution(1000);
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      StorPortStallExecution(0);
      puVar2[lVar5 * 0x20 + 0xb] = puVar2[lVar5 * 0x20 + 0xb] & 0xfffffffe;
      lVar8 = 2;
      do {
        StorPortStallExecution(1000);
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      StorPortStallExecution(0);
    }
    else {
      if ((puVar2[lVar5 * 0x20 + 6] & 2) == 0) {
        if (!bVar3) {
          DbgPrint("port %d PxCMD.SUD is 0, force to do spin-up\n",uVar9);
          bVar3 = true;
          goto LAB_0001d062;
        }
      }
      else {
LAB_0001d062:
        if (!bVar3) goto LAB_0001d08f;
      }
      DbgPrint("do stagger spin up on AHCI port %d\n",uVar9);
      puVar2[lVar5 * 0x20 + 0xb] = puVar2[lVar5 * 0x20 + 0xb] & 0xfffffffe;
      puVar2[lVar5 * 0x20 + 6] = puVar2[lVar5 * 0x20 + 6] & 0xfffffffd;
      StorPortStallExecution(100);
      puVar2[lVar5 * 0x20 + 6] = puVar2[lVar5 * 0x20 + 6] | 0x12;
    }
    uVar7 = 0;
    do {
      if ((puVar2[lVar5 * 0x20 + 4] & 0x40) != 0) {
        puVar2[lVar5 * 0x20 + 0xc] = puVar2[lVar5 * 0x20 + 0xc] | 0x4000000;
        break;
      }
      StorPortStallExecution(10);
      uVar7 = uVar7 + 1;
    } while (uVar7 < 1000);
    lVar8 = 10;
    do {
      StorPortStallExecution();
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    StorPortStallExecution();
    if ((puVar2[lVar5 * 0x20 + 10] & 1) != 0) {
      if ((char)puVar2[lVar5 * 0x20 + 8] < '\0') {
        uVar1 = *(ushort *)(param_1 + 0xab8 + (longlong)(int)param_2 * 4);
        if ((uVar1 & 0x8000) == 0) {
          if ((uVar1 & 0x2000) != 0) {
            uVar6 = 10000;
          }
        }
        else {
          uVar6 = 300000;
        }
        uVar7 = 0;
        if (uVar6 != 0) {
          do {
            if (-1 < (char)puVar2[lVar5 * 0x20 + 8]) break;
            StorPortStallExecution();
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar6);
        }
      }
      uVar7 = 0;
      do {
        if ((char)(puVar2[lVar5 * 0x20 + 8] >> 8) == '\x01') break;
        StorPortStallExecution();
        uVar7 = uVar7 + 1;
      } while (uVar7 < 1000);
      puVar2[lVar5 * 0x20 + 6] = puVar2[lVar5 * 0x20 + 6] | 0x11;
      if ((char)puVar2[lVar5 * 0x20 + 8] < '\0') {
        AhciSoftwareReset(param_1,param_2);
        uVar1 = *(ushort *)(param_1 + 0xab8 + (longlong)(int)param_2 * 4);
        if ((uVar1 & 0x8000) == 0) {
          if ((uVar1 & 0x2000) != 0) {
            uVar6 = 200;
          }
        }
        else {
          uVar6 = 7000;
        }
        uVar7 = 0;
        if (uVar6 != 0) {
          do {
            if (-1 < (char)puVar2[lVar5 * 0x20 + 8]) break;
            StorPortStallExecution();
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar6);
        }
      }
      if (((-1 < (char)(byte)puVar2[lVar5 * 0x20 + 8]) &&
          (((byte)puVar2[lVar5 * 0x20 + 8] & 0x20) == 0)) ||
         (local_res18 = local_res18 + 1, 0 < local_res18)) goto LAB_0001d226;
      goto LAB_0001d012;
    }
    puVar2[lVar5 * 0x20 + 6] = puVar2[lVar5 * 0x20 + 6] & 0xffffffee;
LAB_0001d226:
    puVar2[lVar5 * 0x20 + 0xc] = 0xffffffff;
    puVar2[lVar5 * 0x20 + 4] = 0xffffffff;
    puVar2[2] = uVar4;
    puVar2[lVar5 * 0x20 + 5] = 0xffffffff;
  }
  else {
    AhciPowerResetPort(param_1,param_2,'\0');
  }
  return;
}



===== DispatchDiskReadWrite @ 0001d250 =====

bool DispatchDiskReadWrite(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined8 uVar2;
  longlong lVar3;
  short sVar4;
  bool bVar5;
  byte bVar6;
  undefined1 uVar7;
  char cVar8;
  ulonglong uVar9;
  uint *puVar10;
  longlong lVar11;
  longlong lVar12;
  short sVar13;
  undefined2 *puVar14;
  byte bVar15;
  uint uVar16;
  short sVar17;
  uint uVar18;
  undefined8 local_res8;
  longlong local_res10;
  
  bVar15 = *(byte *)(param_2 + 0x4e);
  uVar9 = (ulonglong)(bVar15 >> 1);
  uVar2 = *(undefined8 *)(param_1 + 0xc0 + uVar9 * 8);
  local_res8 = uVar2;
  local_res10 = *(longlong *)(param_1 + 0xe0 + uVar9 * 8);
  if (*(int *)(param_2 + 0x58) == 0) {
    *(undefined1 *)(param_2 + 0x4b) = 1;
LAB_0001d2a4:
    bVar5 = true;
  }
  else {
    if ((*(byte *)((ulonglong)bVar15 + 0x948 + param_1) & 4) != 0) {
      bVar5 = AhciDispatchDiskReadWrite(param_1,param_2);
      return bVar5;
    }
    if (*(char *)((ulonglong)bVar15 * 0xb8 + 0x399 + param_1) == '\0') {
      sVar17 = (short)*(undefined8 *)(param_1 + 0xa0 + uVar9 * 8);
      sVar13 = sVar17 + 6;
      out(sVar13,(bVar15 & 1 | 0xfa) << 4);
      uVar16 = 0;
      do {
        bVar6 = in((short)uVar2);
        if (-1 < (char)bVar6) break;
        StorPortStallExecution(0x96);
        uVar16 = uVar16 + 1;
      } while (uVar16 < 20000);
      lVar3 = local_res10;
      if ((((-1 < (char)bVar6) && ((bVar6 & 0x40) != 0)) && ((bVar6 & 1) == 0)) &&
         ((bVar6 & 0x20) == 0)) {
        *(undefined1 *)((ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) + 0x42dc + param_1) = 1;
        *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x4e) + 0x42f0 + param_1) = 1;
        puVar10 = *(uint **)(param_2 + 0x30);
        if (puVar10 == (uint *)0x0) {
          puVar10 = (uint *)&local_res8;
          local_res8 = CONCAT44(local_res8._4_4_,
                                (*(uint *)(param_2 + 0x58) & 0x7ffff | 0xffe00000) << 10);
        }
        if (*(longlong *)(param_2 + 0x20) == 0) {
          lVar11 = (ulonglong)((*puVar10 & 0x3ff) << 9) + *(longlong *)(param_2 + 0x60);
        }
        else if ((*(int *)(param_2 + 0xa4) == 0) && ((*puVar10 >> 0x1e & 1) == 0)) {
          lVar11 = (ulonglong)((*puVar10 & 0x3ff) << 9) + *(longlong *)(param_2 + 0x28);
        }
        else {
          lVar11 = (ulonglong)((*puVar10 & 0x3ff) << 9) + *(longlong *)(param_2 + 0x20);
        }
        *(longlong *)(param_1 + 0x42f8 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 8) = lVar11;
        *(uint *)(param_1 + 0x42e0 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 4) =
             *(uint *)(param_2 + 0x58) >> 1;
        uVar9 = *(ulonglong *)(param_2 + 0x40);
        lVar11 = (longlong)(int)(uint)bVar15 * 0xb8;
        uVar16 = *(uint *)(lVar11 + 0x39c + param_1);
        if ((uVar16 & 0x10) == 0) {
          out(sVar17 + 2,(char)(*(int *)(param_2 + 0x58) + 0x1ffU >> 9));
          out(sVar17 + 3,
              (char)((uVar9 & 0xffffffff) %
                    (ulonglong)
                    *(ushort *)((ulonglong)*(byte *)(param_2 + 0x4e) * 0xd4 + 0xd20 + param_1)) +
              '\x01');
          lVar12 = (ulonglong)*(byte *)(param_2 + 0x4e) * 0xd4;
          out(sVar17 + 4,
              (char)((uVar9 & 0xffffffff) /
                    (ulonglong)
                    ((uint)*(ushort *)(lVar12 + 0xd20 + param_1) *
                    (uint)*(ushort *)(lVar12 + 0xd1a + param_1))));
          lVar12 = (ulonglong)*(byte *)(param_2 + 0x4e) * 0xd4;
          out(sVar17 + 5,
              (char)((uVar9 & 0xffffffff) /
                     (ulonglong)
                     ((uint)*(ushort *)(lVar12 + 0xd20 + param_1) *
                     (uint)*(ushort *)(lVar12 + 0xd1a + param_1)) >> 8));
          lVar12 = (ulonglong)*(byte *)(param_2 + 0x4e) * 0xd4;
          bVar15 = (byte)(((uVar9 & 0xffffffff) / (ulonglong)*(ushort *)(lVar12 + 0xd20 + param_1))
                         % (ulonglong)*(ushort *)(lVar12 + 0xd1a + param_1)) |
                   (*(byte *)(param_2 + 0x4e) & 1 | 0xfa) << 4;
          out(sVar13,bVar15);
        }
        else {
          bVar15 = (byte)(uVar9 >> 0x18);
          if ((uVar16 & 0x20) != 0) {
            out(sVar17 + 2,(char)(*(int *)(param_2 + 0x58) + 0x1ffU >> 0x11));
            out(sVar17 + 3,bVar15);
            if (*(int *)(param_2 + 0x38) == 0) {
              out(sVar17 + 4,0);
              out(sVar17 + 5,0);
            }
            else {
              out(sVar17 + 4,(char)(uVar9 >> 0x20));
              out(sVar17 + 5,(char)(uVar9 >> 0x28));
            }
          }
          out(sVar17 + 2,(char)(*(int *)(param_2 + 0x58) + 0x1ffU >> 9));
          out(sVar17 + 3,(char)uVar9);
          out(sVar17 + 4,(char)(uVar9 >> 8));
          out(sVar17 + 5,(char)(uVar9 >> 0x10));
          if ((*(uint *)(lVar11 + 0x39c + param_1) & 0x20) == 0) {
            bVar15 = bVar15 | (*(byte *)(param_2 + 0x4e) | 0xfe) << 4;
          }
          else {
            bVar15 = (*(byte *)(param_2 + 0x4e) | 0xfe) << 4;
          }
          out(sVar13,bVar15);
        }
        bVar6 = *(byte *)(lVar11 + 0x39c + param_1) & 0xf;
        if (*(char *)(*(longlong *)(param_2 + 0x10) + 0x101) != '\0') {
          bVar6 = bVar6 >> 1;
        }
        if ((((bVar6 & 4) == 0) || (*(char *)(param_2 + 0x90) == '/')) ||
           (*(char *)(param_2 + 0x90) == -0x71)) {
          if ((*(uint *)(param_2 + 0x54) & 0x40) == 0) {
            if ((*(char *)(param_2 + 0x90) != '/') && (*(char *)(param_2 + 0x90) != -0x71)) {
              sVar4 = sVar17 + 7;
              bVar6 = *(byte *)((ulonglong)*(byte *)(param_2 + 0x4e) + 0xb00 + param_1);
              if (bVar6 == 0) {
                uVar16 = 0x100;
                if ((*(uint *)(lVar11 + 0x39c + param_1) & 0x20) != 0) {
                  uVar7 = 0x34;
                  goto LAB_0001d6df;
                }
                out(sVar4,0x30);
              }
              else {
                uVar18 = *(uint *)(param_1 + 0x42e0 +
                                  (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 4);
                uVar16 = (uint)bVar6 << 8;
                if (uVar18 < uVar16) {
                  uVar16 = uVar18;
                }
                if ((*(uint *)(lVar11 + 0x39c + param_1) & 0x20) == 0) {
                  uVar7 = 0xc5;
                }
                else {
                  uVar7 = 0x39;
                }
LAB_0001d6df:
                out(sVar4,uVar7);
              }
              out(sVar13,bVar15);
              uVar18 = 0;
              do {
                cVar8 = in(sVar4);
                if (-1 < cVar8) break;
                StorPortStallExecution(0x96);
                uVar18 = uVar18 + 1;
              } while (uVar18 < 20000);
              if (cVar8 < '\0') {
                *(undefined1 *)(param_2 + 0x4b) = 5;
              }
              else {
                uVar18 = 0;
                do {
                  bVar15 = in(sVar4);
                  if ((bVar15 & 8) != 0) break;
                  StorPortStallExecution(200);
                  uVar18 = uVar18 + 1;
                } while (uVar18 < 1000);
                if ((bVar15 & 8) != 0) {
                  do {
                    PIOGetBuffer(*(int *)(param_2 + 0x58) +
                                 *(int *)(param_1 + 0x42e0 +
                                         (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 4) * -2,
                                 uVar16 * 2,param_2,(int *)&local_res8,&local_res10);
                    *(longlong *)
                     (param_1 + 0x42f8 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 8) =
                         local_res10;
                    lVar3 = *(longlong *)(param_2 + 0x10);
                    if (lVar3 == 0) {
                      lVar11 = 0;
                    }
                    else {
                      lVar11 = *(longlong *)(*(longlong *)(lVar3 + 0xf0) + 0x38);
                    }
                    if ((lVar11 != 0) && (*(int *)(lVar11 + 0x27c) == 0)) {
                      *(ulonglong *)
                       (param_1 + 0x42f8 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 8) =
                           (ulonglong)
                           (uint)((int)local_res10 - *(int *)(*(longlong *)(lVar3 + 0xf0) + 0x18)) +
                           *(longlong *)(lVar3 + 0xed8);
                    }
                    uVar18 = (uint)local_res8 >> 1;
                    piVar1 = (int *)(param_1 + 0x42e0 +
                                    (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 4);
                    *piVar1 = *piVar1 - uVar18;
                    uVar9 = (ulonglong)uVar18;
                    puVar14 = *(undefined2 **)
                               (param_1 + 0x42f8 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 8);
                    while (uVar9 != 0) {
                      uVar9 = uVar9 - 1;
                      out(*puVar14,sVar17);
                      puVar14 = puVar14 + 1;
                    }
                    uVar16 = uVar16 - uVar18;
                  } while (uVar16 != 0);
                  goto LAB_0001d852;
                }
                *(undefined4 *)(param_1 + 0x42e0 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 4)
                     = 0;
                *(undefined1 *)((ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) + 0x42dc + param_1) = 0;
                *(undefined1 *)(param_2 + 0x4b) = 9;
              }
              goto LAB_0001d85f;
            }
            if ((*(uint *)(lVar11 + 0x39c + param_1) & 0x20) != 0) {
              uVar7 = 0x42;
              goto LAB_0001d84c;
            }
            out(sVar17 + 7,0x40);
          }
          else {
            uVar16 = *(uint *)(lVar11 + 0x39c + param_1);
            if (*(char *)((ulonglong)*(byte *)(param_2 + 0x4e) + 0xb00 + param_1) == '\0') {
              uVar7 = 0x24;
              if ((uVar16 & 0x20) == 0) {
                uVar7 = 0x20;
              }
            }
            else if ((uVar16 & 0x20) == 0) {
              uVar7 = 0xc4;
            }
            else {
              uVar7 = 0x29;
            }
LAB_0001d84c:
            out(sVar17 + 7,uVar7);
          }
        }
        else {
          if ((*(uint *)(param_2 + 0x54) & 0x40) == 0) {
            if ((char)*(uint *)(param_2 + 0x54) < '\0') {
              if ((*(uint *)(lVar11 + 0x39c + param_1) & 0x20) != 0) {
                uVar7 = 0x35;
                goto LAB_0001d5e6;
              }
              out(sVar17 + 7,0xca);
            }
          }
          else {
            if ((*(uint *)(lVar11 + 0x39c + param_1) & 0x20) == 0) {
              uVar7 = 200;
            }
            else {
              uVar7 = 0x25;
            }
LAB_0001d5e6:
            out(sVar17 + 7,uVar7);
          }
          PreparePRDTable(param_1,param_2);
          sVar17 = (short)lVar3;
          bVar15 = in(sVar17);
          if ((*(uint *)(param_2 + 0x54) & 0x40) == 0) {
            out(sVar17,bVar15 & 0xf7);
          }
          else {
            out(sVar17,bVar15 | 8);
          }
          sVar13 = sVar17 + 2;
          bVar15 = in(sVar13);
          out(sVar13,bVar15 | 2);
          out(sVar13,bVar15 | 4);
          bVar15 = in(sVar17);
          out(sVar17,bVar15 | 1);
        }
LAB_0001d852:
        *(undefined1 *)(param_2 + 0x4b) = 0;
        goto LAB_0001d2a4;
      }
      *(undefined1 *)(param_2 + 0x4b) = 4;
    }
    else {
      *(undefined1 *)(param_2 + 0x4b) = 4;
    }
LAB_0001d85f:
    bVar5 = false;
  }
  return bVar5;
}



===== DispatchUserDiskVerify @ 0001d87c =====

bool DispatchUserDiskVerify(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  short sVar3;
  bool bVar4;
  byte bVar5;
  byte bVar6;
  longlong lVar7;
  short sVar8;
  longlong lVar9;
  uint uVar10;
  
  bVar6 = *(byte *)(param_2 + 0x4e);
  uVar1 = *(undefined8 *)(param_1 + 0xc0 + (ulonglong)(bVar6 >> 1) * 8);
  if (*(int *)(param_2 + 0x58) == 0) {
    *(undefined1 *)(param_2 + 0x4b) = 1;
LAB_0001d8c3:
    bVar4 = true;
  }
  else {
    if ((*(byte *)((ulonglong)bVar6 + 0x948 + param_1) & 4) != 0) {
      bVar4 = AhciDispatchUserDiskVerify(param_1,param_2);
      return bVar4;
    }
    if (*(char *)((ulonglong)bVar6 * 0xb8 + 0x399 + param_1) == '\0') {
      sVar3 = (short)*(undefined8 *)(param_1 + 0xa0 + (ulonglong)(bVar6 >> 1) * 8);
      sVar8 = sVar3 + 6;
      out(sVar8,(bVar6 & 1 | 0xfa) << 4);
      uVar10 = 0;
      do {
        bVar5 = in((short)uVar1);
        if (-1 < (char)bVar5) break;
        StorPortStallExecution(0x96);
        uVar10 = uVar10 + 1;
      } while (uVar10 < 20000);
      if ((((-1 < (char)bVar5) && ((bVar5 & 0x40) != 0)) && ((bVar5 & 1) == 0)) &&
         ((bVar5 & 0x20) == 0)) {
        *(undefined1 *)((ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) + 0x42dc + param_1) = 1;
        *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x4e) + 0x42f0 + param_1) = 1;
        *(undefined8 *)(param_1 + 0x42f8 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 8) = 0;
        *(undefined4 *)(param_1 + 0x42e0 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 4) = 0;
        uVar2 = *(ulonglong *)(param_2 + 0x40);
        lVar9 = (longlong)(int)(uint)bVar6 * 0xb8;
        uVar10 = *(uint *)(lVar9 + 0x39c + param_1);
        if ((uVar10 & 0x10) == 0) {
          out(sVar3 + 2,(char)(*(int *)(param_2 + 0x58) + 0x1ffU >> 9));
          out(sVar3 + 3,
              (char)((uVar2 & 0xffffffff) %
                    (ulonglong)
                    *(ushort *)((ulonglong)*(byte *)(param_2 + 0x4e) * 0xd4 + 0xd20 + param_1)) +
              '\x01');
          lVar7 = (ulonglong)*(byte *)(param_2 + 0x4e) * 0xd4;
          out(sVar3 + 4,
              (char)((uVar2 & 0xffffffff) /
                    (ulonglong)
                    ((uint)*(ushort *)(lVar7 + 0xd20 + param_1) *
                    (uint)*(ushort *)(lVar7 + 0xd1a + param_1))));
          lVar7 = (ulonglong)*(byte *)(param_2 + 0x4e) * 0xd4;
          out(sVar3 + 5,
              (char)((uVar2 & 0xffffffff) /
                     (ulonglong)
                     ((uint)*(ushort *)(lVar7 + 0xd20 + param_1) *
                     (uint)*(ushort *)(lVar7 + 0xd1a + param_1)) >> 8));
          lVar7 = (ulonglong)*(byte *)(param_2 + 0x4e) * 0xd4;
          out(sVar8,(byte)(((uVar2 & 0xffffffff) / (ulonglong)*(ushort *)(lVar7 + 0xd20 + param_1))
                          % (ulonglong)*(ushort *)(lVar7 + 0xd1a + param_1)) |
                    (*(byte *)(param_2 + 0x4e) & 1 | 0xfa) << 4);
        }
        else {
          bVar6 = (byte)(uVar2 >> 0x18);
          if ((uVar10 & 0x20) != 0) {
            out(sVar3 + 2,(char)(*(int *)(param_2 + 0x58) + 0x1ffU >> 0x11));
            out(sVar3 + 3,bVar6);
            if (*(int *)(param_2 + 0x38) == 0) {
              out(sVar3 + 4,0);
              out(sVar3 + 5,0);
            }
            else {
              out(sVar3 + 4,(char)(uVar2 >> 0x20));
              out(sVar3 + 5,(char)(uVar2 >> 0x28));
            }
          }
          out(sVar3 + 2,(char)(*(int *)(param_2 + 0x58) + 0x1ffU >> 9));
          out(sVar3 + 3,(char)uVar2);
          out(sVar3 + 4,(char)(uVar2 >> 8));
          out(sVar3 + 5,(char)(uVar2 >> 0x10));
          if ((*(uint *)(lVar9 + 0x39c + param_1) & 0x20) == 0) {
            bVar6 = (*(byte *)(param_2 + 0x4e) | 0xfe) << 4 | bVar6;
          }
          else {
            bVar6 = (*(byte *)(param_2 + 0x4e) | 0xfe) << 4;
          }
          out(sVar8,bVar6);
        }
        if ((*(uint *)(lVar9 + 0x39c + param_1) & 0x20) == 0) {
          out(sVar3 + 7,0x40);
        }
        else {
          out(sVar3 + 7,0x42);
        }
        *(undefined1 *)(param_2 + 0x4b) = 0;
        goto LAB_0001d8c3;
      }
      *(undefined1 *)(param_2 + 0x4b) = 4;
    }
    else {
      *(undefined1 *)(param_2 + 0x4b) = 4;
    }
    bVar4 = false;
  }
  return bVar4;
}



===== GetPhyAddrFromSGL @ 0001db5c =====

undefined8 GetPhyAddrFromSGL(uint *param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  undefined8 local_res8;
  
  uVar3 = 0;
  puVar4 = param_1 + 4;
  *param_3 = 0;
  uVar2 = *param_1;
  local_res8 = 0;
  if (uVar2 != 0) {
    do {
      if (param_2 < puVar4[2]) break;
      uVar3 = uVar3 + 1;
      param_2 = param_2 - puVar4[2];
      puVar4 = puVar4 + 6;
    } while (uVar3 < uVar2);
  }
  if (uVar3 != uVar2) {
    *param_3 = puVar4[2] - param_2;
    iVar1 = *puVar4 + param_2;
    local_res8 = CONCAT44(puVar4[1],iVar1);
    if (-*puVar4 - 1 < param_2) {
      local_res8 = CONCAT44(puVar4[1] + 1,iVar1);
    }
  }
  return local_res8;
}



===== PreparePRDTable @ 0001dbc0 =====

void PreparePRDTable(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  longlong lVar4;
  uint *puVar5;
  uint uVar6;
  longlong lVar7;
  uint *puVar8;
  uint local_res8 [2];
  uint local_res10 [2];
  
  puVar8 = *(uint **)(param_2 + 0x30);
  puVar5 = *(uint **)(param_1 + 0x220 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 8);
  local_res8[0] = 0;
  if (puVar8 == (uint *)0x0) {
    puVar8 = local_res10;
    local_res10[0] = (*(uint *)(param_2 + 0x58) & 0x7ffff | 0xffe00000) << 10;
  }
  do {
    uVar1 = *puVar8;
    uVar6 = uVar1 >> 10 & 0x7ffff;
    if (*(longlong *)(param_2 + 0x20) == 0) {
      lVar7 = (ulonglong)((uVar1 & 0x3ff) << 9) + *(longlong *)(param_2 + 0x60);
    }
    else if ((*(int *)(param_2 + 0xa4) == 0) && ((uVar1 >> 0x1e & 1) == 0)) {
      lVar7 = (ulonglong)((uVar1 & 0x3ff) << 9) + *(longlong *)(param_2 + 0x28);
    }
    else {
      lVar7 = (ulonglong)((uVar1 & 0x3ff) << 9) + *(longlong *)(param_2 + 0x20);
    }
    while (uVar6 != 0) {
      if ((*(int *)(param_2 + 0xa4) == 0) && ((*puVar8 & 0x40000000) == 0)) {
        lVar4 = *(longlong *)(param_2 + 0x10);
        if ((lVar4 != 0) && (*(longlong *)(lVar4 + 0x10) != 0)) {
          lVar4 = *(longlong *)(lVar4 + 0x10);
        }
        if (lVar4 == 0) goto LAB_0001dcc5;
        if (*(uint **)(lVar4 + 0xe8) == (uint *)0x0) {
          uVar2 = *(undefined8 *)(lVar4 + 0xf0);
          goto LAB_0001dcc7;
        }
        uVar2 = GetPhyAddrFromSGL(*(uint **)(lVar4 + 0xe8),
                                  (int)lVar7 - *(int *)(*(longlong *)(lVar4 + 0xf0) + 0x18),
                                  (int *)local_res8);
        uVar1 = (uint)uVar2;
      }
      else {
LAB_0001dcc5:
        uVar2 = 0;
LAB_0001dcc7:
        uVar1 = StorPortGetPhysicalAddress(param_1,uVar2,lVar7,local_res8);
      }
      uVar3 = ((uVar1 & 0xffff0000) - uVar1) + 0x10000;
      if (uVar3 < local_res8[0]) {
        local_res8[0] = uVar3;
      }
      *puVar5 = uVar1;
      if (local_res8[0] < uVar6) {
        puVar5[1] = local_res8[0];
        uVar6 = uVar6 - local_res8[0];
        lVar7 = lVar7 + (ulonglong)local_res8[0];
      }
      else {
        puVar5[1] = uVar6;
        uVar6 = 0;
      }
      puVar5 = puVar5 + 2;
    }
    if ((int)*puVar8 < 0) {
      if (puVar5 != *(uint **)(param_1 + 0x220 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 8)) {
        puVar5[-1] = puVar5[-1] | 0x80000000;
      }
      return;
    }
    puVar8 = puVar8 + 1;
  } while( true );
}



===== PIOGetBuffer @ 0001dd5c =====

ulonglong PIOGetBuffer(uint param_1,int param_2,longlong param_3,int *param_4,longlong *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  longlong lVar6;
  uint local_res8 [2];
  
  puVar5 = *(uint **)(param_3 + 0x30);
  uVar4 = 0;
  if (puVar5 == (uint *)0x0) {
    puVar5 = local_res8;
    local_res8[0] = (*(uint *)(param_3 + 0x58) & 0x7ffff) << 10 ^ 0x80000000;
  }
  while( true ) {
    if (*(longlong *)(param_3 + 0x20) == 0) {
      uVar3 = *puVar5;
      uVar1 = (uVar3 & 0x3ff) << 9;
      uVar2 = (ulonglong)uVar1;
      lVar6 = (ulonglong)uVar1 + *(longlong *)(param_3 + 0x60);
    }
    else if ((*(int *)(param_3 + 0xa4) == 0) && (uVar3 = *puVar5, (uVar3 >> 0x1e & 1) == 0)) {
      uVar1 = (uVar3 & 0x3ff) << 9;
      uVar2 = (ulonglong)uVar1;
      lVar6 = (ulonglong)uVar1 + *(longlong *)(param_3 + 0x28);
    }
    else {
      uVar3 = *puVar5;
      uVar1 = (uVar3 & 0x3ff) << 9;
      uVar2 = (ulonglong)uVar1;
      lVar6 = (ulonglong)uVar1 + *(longlong *)(param_3 + 0x20);
    }
    uVar1 = uVar3 >> 10 & 0x7ffff;
    if ((uVar4 <= param_1) && (uVar2 = (ulonglong)(uVar1 + uVar4), param_1 < uVar1 + uVar4)) break;
    if ((int)uVar3 < 0) {
      return uVar2 & 0xffffffffffffff00;
    }
    uVar4 = uVar4 + uVar1;
    puVar5 = puVar5 + 1;
  }
  if (uVar1 + uVar4 < param_1 + param_2) {
    *param_4 = (uVar1 - param_1) + uVar4;
  }
  else {
    *param_4 = param_2;
  }
  *param_5 = (ulonglong)(param_1 - uVar4) + lVar6;
  return CONCAT71((int7)((ulonglong)param_5 >> 8),1);
}



===== DispatchSyncCache @ 0001de64 =====

undefined1 DispatchSyncCache(longlong param_1,longlong param_2)

{
  *(undefined1 *)((ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) + 0x42dc + param_1) = 1;
  FlushCacheToHDD(param_1,*(char *)(param_2 + 0x4e),0,'\x01');
  *(undefined1 *)(param_2 + 0x4b) = 0;
  return 1;
}



===== MapError @ 0001de98 =====

byte MapError(longlong param_1,longlong param_2)

{
  int *piVar1;
  short sVar2;
  byte bVar3;
  undefined1 *puVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  
  bVar5 = 0;
  sVar2 = (short)*(undefined8 *)(param_1 + 0xa0 + (ulonglong)(*(byte *)(param_2 + 6) >> 1) * 8);
  bVar3 = in(sVar2 + 1);
  if ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(param_2 + 6) * 2) & 2) != 0) {
    bVar3 = bVar3 >> 4;
    if ((((bVar3 < 6) && (bVar3 != 5)) && (bVar3 != 0)) && (bVar3 == 1)) {
      cVar6 = '\0';
      bVar5 = 1;
    }
    else {
      bVar5 = 4;
      cVar6 = '\x02';
    }
    if (((*(uint *)(param_2 + 0xc) & 0x20) == 0) && (cVar6 != '\0')) {
      bVar5 = bVar5 | 0x80;
    }
    goto LAB_0001e124;
  }
  cVar6 = '\0';
  *(byte *)((ulonglong)*(byte *)(param_2 + 6) + 0x84 + param_1) = bVar3;
  if ((bVar3 & 8) == 0) {
    if ((bVar3 & 4) == 0) {
      if ((bVar3 & 2) == 0) {
        if ((bVar3 & 1) == 0) {
          if ((char)bVar3 < '\0') {
LAB_0001e030:
            cVar6 = '\x02';
            bVar5 = 4;
            puVar4 = *(undefined1 **)(param_2 + 0x20);
            if (puVar4 != (undefined1 *)0x0) {
              *(undefined2 *)(puVar4 + 0xc) = 0;
              bVar3 = puVar4[2] & 0xf3 | 3;
LAB_0001e045:
              cVar6 = '\x02';
              puVar4[2] = bVar3;
              puVar4[7] = 0xb;
              bVar5 = 0x84;
              *puVar4 = 0xf0;
            }
          }
          else {
            if ((bVar3 & 0x10) != 0) {
              puVar4 = *(undefined1 **)(param_2 + 0x20);
              bVar5 = 4;
              if (puVar4 != (undefined1 *)0x0) {
                bVar5 = 0x84;
                bVar3 = puVar4[2] & 0xf3 | 3;
                goto LAB_0001dfd6;
              }
              goto LAB_0001dfe5;
            }
            if ((bVar3 & 0x20) == 0) {
              if ((bVar3 & 0x40) != 0) {
                if ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(param_2 + 6) * 2) & 0x20) == 0
                   ) {
                  piVar1 = (int *)(param_1 + 100 + (ulonglong)*(byte *)(param_2 + 6) * 4);
                  *piVar1 = *piVar1 + 1;
                }
                goto LAB_0001e030;
              }
            }
            else {
              puVar4 = *(undefined1 **)(param_2 + 0x20);
              cVar6 = '\x02';
              bVar5 = 4;
              if (puVar4 != (undefined1 *)0x0) {
                *(undefined2 *)(puVar4 + 0xc) = 0x28;
                bVar3 = puVar4[2] & 0xf6 | 6;
                goto LAB_0001e045;
              }
            }
          }
        }
        else {
          bVar5 = 6;
        }
      }
      else {
        cVar6 = '\x02';
        bVar5 = 4;
        if ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(param_2 + 6) * 2) & 0x20) == 0) {
          piVar1 = (int *)(param_1 + 100 + (ulonglong)*(byte *)(param_2 + 6) * 4);
          *piVar1 = *piVar1 + 1;
        }
      }
    }
    else {
      puVar4 = *(undefined1 **)(param_2 + 0x20);
      bVar5 = 2;
      if (puVar4 != (undefined1 *)0x0) {
        bVar5 = 0x82;
        bVar3 = puVar4[2] & 0xfb | 0xb;
LAB_0001dfd6:
        *(undefined2 *)(puVar4 + 0xc) = 0;
        puVar4[2] = bVar3;
        puVar4[7] = 0xb;
        *puVar4 = 0xf0;
      }
LAB_0001dfe5:
      cVar6 = '\x02';
      piVar1 = (int *)(param_1 + 100 + (ulonglong)*(byte *)(param_2 + 6) * 4);
      *piVar1 = *piVar1 + 1;
    }
  }
  else {
    cVar6 = '\x02';
    bVar5 = 4;
  }
  if (3 < *(uint *)(param_1 + 100 + (ulonglong)*(byte *)(param_2 + 6) * 4)) {
    *(undefined1 *)((ulonglong)*(byte *)(param_2 + 6) + 0xb08 + param_1) = 0;
    *(undefined1 *)((ulonglong)*(byte *)(param_2 + 6) + 0xb00 + param_1) = 0;
    StorPortLogError(param_1,param_2,*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6),
                     *(undefined1 *)(param_2 + 7),9,4);
    if ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(param_2 + 6) * 2) & 1) != 0) {
      out(sVar2 + 6,(*(byte *)(param_2 + 6) & 1 | 0xfa) << 4);
      out(sVar2 + 2,0);
      out(sVar2 + 7,0xc6);
      out(sVar2 + 6,(*(byte *)(param_2 + 6) & 1 | 0xfa) << 4);
      uVar7 = 0;
      do {
        bVar3 = in(sVar2 + 7);
        if (-1 < (char)bVar3) break;
        StorPortStallExecution(0x96);
        uVar7 = uVar7 + 1;
      } while (uVar7 < 20000);
      if ((bVar3 & 1) != 0) {
        in(sVar2 + 1);
        *(undefined1 *)((ulonglong)*(byte *)(param_2 + 6) + 0xb00 + param_1) = 0;
      }
    }
  }
LAB_0001e124:
  *(char *)(param_2 + 4) = cVar6;
  return bVar5;
}



===== FlushCacheToHDD @ 0001e148 =====

undefined1 FlushCacheToHDD(longlong param_1,char param_2,undefined8 param_3,char param_4)

{
  ushort uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  byte bVar4;
  ulonglong uVar5;
  short sVar6;
  short sVar7;
  ulonglong uVar8;
  byte bVar9;
  short sVar10;
  char cVar11;
  undefined7 uVar12;
  undefined1 uVar13;
  char cVar14;
  undefined2 uVar15;
  uint uVar16;
  
  uVar12 = (undefined7)((ulonglong)param_3 >> 8);
  uVar13 = 1;
  uVar5 = 0;
  cVar11 = (char)param_3;
  do {
    bVar9 = (byte)uVar5;
    if ((param_2 == -1) || ((int)uVar5 == (int)param_2)) {
      if (*(char *)(uVar5 + 0x948 + param_1) == '\x04') {
        uVar5 = AhciFlushCacheToHDD(param_1,bVar9,CONCAT71(uVar12,cVar11),param_4);
        if ((char)uVar5 == '\0') {
LAB_0001e1b1:
          uVar13 = 0;
        }
      }
      else {
        uVar1 = *(ushort *)(param_1 + 0xab8 + uVar5 * 2);
        if ((((uVar1 & 1) != 0) && ((uVar1 & 2) == 0)) &&
           (*(char *)(uVar5 * 0xb8 + 0x399 + param_1) == '\0')) {
          uVar8 = uVar5 >> 1;
          uVar2 = *(undefined8 *)(param_1 + 0xc0 + uVar8 * 8);
          uVar3 = *(undefined8 *)(param_1 + 0xe0 + uVar8 * 8);
          sVar10 = (short)*(undefined8 *)(param_1 + 0xa0 + uVar8 * 8);
          sVar6 = sVar10 + 6;
          cVar14 = (bVar9 & 1 | 0xfa) << 4;
          out(sVar6,cVar14);
          sVar10 = sVar10 + 7;
          if ((*(uint *)(uVar5 * 0xb8 + 0x39c + param_1) & 0x20) == 0) {
            out(sVar10,0xe7);
          }
          else {
            out(sVar10,0xea);
          }
          StorPortStallExecution(0x32,sVar10);
          out(sVar6,cVar14);
          uVar15 = (undefined2)uVar2;
          bVar4 = in(uVar15);
          if ((bVar4 & 1) != 0) goto LAB_0001e1b1;
          if (param_4 == '\0') {
            *(undefined1 *)(uVar8 + 0x42dc + param_1) = 0;
            sVar6 = (short)uVar3;
            if ((char)param_3 != '\0') {
              uVar16 = 0;
              sVar7 = sVar6 + 2;
              do {
                in(sVar10);
                bVar4 = in(sVar7);
                if ((bVar4 & 4) != 0) {
                  out(sVar7,bVar4);
                  in(sVar10);
                  break;
                }
                StorPortStallExecution(0x32);
                uVar16 = uVar16 + 1;
              } while (uVar16 < 0x100);
            }
            uVar16 = 0;
            do {
              cVar14 = in(uVar15);
              if (-1 < cVar14) break;
              StorPortStallExecution(0x96);
              uVar16 = uVar16 + 1;
            } while (uVar16 < 20000);
            uVar16 = 0;
            do {
              cVar14 = in(uVar15);
              if (-1 < cVar14) break;
              StorPortStallExecution(0x96);
              uVar16 = uVar16 + 1;
            } while (uVar16 < 20000);
            in(sVar10);
            sVar6 = sVar6 + 2;
            bVar4 = in(sVar6);
            if ((bVar4 & 4) != 0) {
              out(sVar6,bVar4);
            }
          }
          else {
            *(undefined1 *)(uVar8 + 0x42dc + param_1) = 1;
          }
        }
      }
    }
    uVar5 = (ulonglong)(byte)(bVar9 + 1);
    if (7 < (byte)(bVar9 + 1)) {
      return uVar13;
    }
  } while( true );
}



===== DispatchAtapiReadWrite @ 0001e360 =====

undefined8 DispatchAtapiReadWrite(longlong param_1,undefined8 *param_2)

{
  ushort *puVar1;
  byte bVar2;
  ushort uVar3;
  longlong *plVar4;
  byte *pbVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  uint uVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  
  puVar1 = (ushort *)(param_1 + 0xab8 + (ulonglong)*(byte *)((longlong)param_2 + 0x4e) * 2);
  uVar3 = *puVar1;
  puVar13 = param_2;
  if (((uVar3 & 0x100) == 0) &&
     (uVar14 = (ulonglong)(*(byte *)((longlong)param_2 + 0x4e) >> 1),
     *(longlong *)(param_1 + 0x4348 + uVar14 * 8) == 0)) {
    *puVar1 = uVar3 | 0x100;
    *(undefined1 *)(uVar14 + 0x466c + param_1) = 3;
    *(undefined8 **)(param_1 + 0x4348 + uVar14 * 8) = param_2;
    puVar13 = (undefined8 *)(param_1 + 0x4368 + uVar14 * 0xc0);
    if (puVar13 != param_2) {
      if ((((uint)param_2 | (uint)puVar13) & 0xf) == 0) {
        lVar9 = 1;
        puVar7 = puVar13;
        puVar8 = param_2;
        do {
          puVar12 = puVar8;
          puVar11 = puVar7;
          uVar6 = puVar12[1];
          *puVar11 = *puVar12;
          puVar11[1] = uVar6;
          uVar6 = puVar12[3];
          puVar11[2] = puVar12[2];
          puVar11[3] = uVar6;
          uVar6 = puVar12[5];
          puVar11[4] = puVar12[4];
          puVar11[5] = uVar6;
          uVar6 = puVar12[7];
          puVar11[6] = puVar12[6];
          puVar11[7] = uVar6;
          uVar6 = puVar12[9];
          puVar11[8] = puVar12[8];
          puVar11[9] = uVar6;
          uVar6 = puVar12[0xb];
          puVar11[10] = puVar12[10];
          puVar11[0xb] = uVar6;
          uVar6 = puVar12[0xd];
          puVar11[0xc] = puVar12[0xc];
          puVar11[0xd] = uVar6;
          uVar6 = puVar12[0xf];
          puVar11[0xe] = puVar12[0xe];
          puVar11[0xf] = uVar6;
          lVar9 = lVar9 + -1;
          puVar7 = puVar11 + 0x10;
          puVar8 = puVar12 + 0x10;
        } while (lVar9 != 0);
        uVar6 = puVar12[0x11];
        puVar11[0x10] = puVar12[0x10];
        puVar11[0x11] = uVar6;
        uVar6 = puVar12[0x13];
        puVar11[0x12] = puVar12[0x12];
        puVar11[0x13] = uVar6;
        uVar6 = puVar12[0x15];
        puVar11[0x14] = puVar12[0x14];
        puVar11[0x15] = uVar6;
        uVar6 = puVar12[0x17];
        puVar11[0x16] = puVar12[0x16];
        puVar11[0x17] = uVar6;
      }
      else {
        memcpy(puVar13,param_2,0xc0);
      }
    }
    BuildMechanismStatusSrb
              (param_1,*(undefined1 *)((longlong)param_2 + 0x4d),
               (ulonglong)*(byte *)((longlong)param_2 + 0x4e));
    *(undefined8 **)(param_1 + 0x340 + uVar14 * 8) = puVar13;
    DispatchAtapiReadWrite(param_1,puVar13);
    *(undefined1 *)(*(longlong *)(param_1 + 0x4348 + uVar14 * 8) + 0x4b) =
         *(undefined1 *)((longlong)puVar13 + 0x4b);
    if (*(char *)((longlong)puVar13 + 0x4b) == '\0') {
      return 1;
    }
    puVar13 = *(undefined8 **)(param_1 + 0x4348 + uVar14 * 8);
    *(undefined8 **)(param_1 + 0x340 + uVar14 * 8) = puVar13;
    *(undefined8 *)(param_1 + 0x4348 + uVar14 * 8) = 0;
  }
  bVar16 = *(char *)((ulonglong)*(byte *)((longlong)param_2 + 0x4e) + 0x4874 + param_1) == '\0';
  if (!bVar16) {
    *(undefined1 *)((longlong)puVar13 + 0x4b) = 4;
  }
  if ((uVar3 & 0xc0) == 0) {
    bVar15 = false;
    bVar17 = *(char *)((longlong)param_2 + 0x4f) == '\0';
  }
  else {
    uVar10 = *(int *)(param_1 + 0xa98 + (ulonglong)*(byte *)((longlong)param_2 + 0x4e) * 4) - 1;
    bVar15 = *(byte *)((longlong)param_2 + 0x4f) < uVar10;
    bVar17 = *(byte *)((longlong)param_2 + 0x4f) == uVar10;
  }
  if (!bVar15 && !bVar17) {
    *(undefined1 *)((longlong)puVar13 + 0x4b) = 10;
  }
  bVar18 = (uVar3 & 2) != 0;
  if (!bVar18) {
    *(undefined1 *)((longlong)puVar13 + 0x4b) = 10;
  }
  lVar9 = puVar13[2];
  *(undefined1 *)(lVar9 + 0x101) = 0;
  uVar14 = (ulonglong)*(byte *)((longlong)puVar13 + 0x4e);
  if (((*(byte *)(uVar14 * 0xb8 + 0x39c + param_1) & 4) != 0) &&
     ((uVar3 = *(ushort *)(param_1 + 0xab8 + uVar14 * 2), (uVar3 & 4) != 0 ||
      ((*(char *)(uVar14 + 0x948 + param_1) != '\x01' &&
       (((*(char *)(param_1 + 0x9d) == '\0' || ((*(uint *)(puVar13 + 0xb) & 3) != 0)) ||
        (((uVar3 & 0x800) != 0 &&
         (((((char)*(undefined4 *)((longlong)puVar13 + 0x54) < '\0' &&
            (*(uint *)(puVar13 + 0xb) != 0)) ||
           ((bVar2 = *(byte *)(puVar13 + 0x12), bVar2 < 0x1b &&
            ((0x4200009U >> (bVar2 & 0x1f) & 1) != 0)))) || ((bVar2 == 0x5a || (bVar2 == 0x55)))))))
        ))))))) {
    *(undefined1 *)(lVar9 + 0x101) = 1;
  }
  if (bVar18 && ((bVar15 || bVar17) && bVar16)) {
    DispatchOneAtapiSubCmd(param_1,(longlong)puVar13,lVar9);
  }
  else if (*(char *)((longlong)puVar13 + 0xbc) == '\0') {
    lVar9 = puVar13[2];
    if ((*(char *)(lVar9 + 0xebf) != '\0') &&
       (plVar4 = *(longlong **)(lVar9 + 0xec0), plVar4 != (longlong *)0x0)) {
      *(int *)(lVar9 + 0x104) = *(int *)(lVar9 + 0x104) + -1;
      *(undefined1 *)(puVar13[2] + 0xebf) = 0;
      RemoveSubCmdFromChnl(param_1,plVar4);
    }
  }
  else if ((*(char *)(puVar13[2] + 0xebf) != '\0') &&
          (*(char *)((ulonglong)*(byte *)((longlong)param_2 + 0x4e) + 0x4874 + param_1) != '\0')) {
    pbVar5 = (byte *)puVar13[0xc];
    pbVar5[0] = 0;
    pbVar5[1] = 0;
    pbVar5[2] = 0;
    pbVar5[3] = 0;
    pbVar5[4] = 0;
    pbVar5[5] = 0;
    pbVar5[6] = 0;
    pbVar5[7] = 0;
    pbVar5[8] = 0;
    pbVar5[9] = 0;
    pbVar5[10] = 0;
    pbVar5[0xb] = 0;
    pbVar5[0xc] = 0;
    pbVar5[0xd] = 0;
    pbVar5[0xe] = 0;
    pbVar5[0xf] = 0;
    pbVar5[0x10] = 0;
    pbVar5[0x11] = 0;
    if (-1 < (char)*pbVar5) {
      *pbVar5 = *pbVar5 | 0x80;
    }
    pbVar5[7] = 0xb;
    pbVar5[0xc] = 8;
    pbVar5[0xd] = 0;
    *pbVar5 = *pbVar5 & 0xf0 | 0x70;
    pbVar5[2] = pbVar5[2] & 0xf4 | 4;
  }
  return 1;
}



===== DispatchOneAtapiSubCmd @ 0001e66c =====

byte DispatchOneAtapiSubCmd(longlong param_1,longlong param_2,undefined8 param_3)

{
  char *pcVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined8 uVar5;
  byte bVar6;
  char cVar7;
  undefined1 uVar8;
  byte bVar9;
  ulonglong uVar10;
  undefined1 uVar11;
  uint uVar12;
  longlong lVar13;
  undefined8 uVar14;
  short sVar15;
  short sVar16;
  longlong lVar17;
  undefined2 *puVar18;
  undefined8 uVar19;
  undefined2 uVar20;
  byte bVar21;
  undefined2 uVar22;
  uint uVar23;
  bool bVar24;
  
  bVar6 = *(byte *)(param_2 + 0x4e);
  uVar4 = *(ushort *)(param_1 + 0xab8 + (ulonglong)bVar6 * 2);
  uVar10 = (ulonglong)(bVar6 >> 1);
  bVar21 = bVar6 >> 1;
  uVar5 = *(undefined8 *)(param_1 + 0xe0 + uVar10 * 8);
  uVar14 = *(undefined8 *)(param_1 + 0xa0 + uVar10 * 8);
  if ((*(byte *)((ulonglong)bVar6 + 0x948 + param_1) & 4) == 0) {
    uVar23 = (int)uVar14 + 6;
    uVar22 = (undefined2)uVar23;
    out(uVar22,(bVar6 & 1 | 0xfa) << 4);
    uVar20 = (undefined2)*(undefined8 *)(param_1 + 0xc0 + uVar10 * 8);
    bVar6 = in(uVar20);
    if ((char)bVar6 < '\0') {
      *(undefined1 *)(param_2 + 0x4b) = 5;
    }
    else {
      uVar19 = 0x10000;
      sVar16 = (short)uVar14;
      if ((bVar6 & 8) != 0) {
        uVar12 = 0;
        do {
          bVar6 = in(uVar20);
          if ((bVar6 & 8) == 0) break;
          in(sVar16);
          uVar12 = uVar12 + 1;
        } while (uVar12 < 0x10000);
        if (uVar12 == 0x10000) {
          out(uVar22,(*(byte *)(param_2 + 0x4e) & 1 | 0xfa) << 4);
          StorPortStallExecution(500,uVar23 & 0xffff);
          out(sVar16 + 7,8);
          lVar17 = 10;
          do {
            StorPortStallExecution(1000);
            lVar17 = lVar17 + -1;
          } while (lVar17 != 0);
          StorPortStallExecution(0);
          out(uVar22,(*(byte *)(param_2 + 0x4e) & 1 | 0xfa) << 4);
          uVar23 = 0;
          do {
            cVar7 = in(uVar20);
            if (-1 < cVar7) break;
            StorPortStallExecution(0x96);
            uVar23 = uVar23 + 1;
          } while (uVar23 < 20000);
          StorPortStallExecution(500);
          out(uVar22,(*(byte *)(param_2 + 0x4e) & 1 | 0xfa) << 4);
          in(uVar20);
          *(undefined1 *)((ulonglong)bVar21 + 0x42dc + param_1) = 0;
          *(undefined1 *)((ulonglong)bVar21 + 0x250 + param_1) = 0;
          IssueIdentify(param_1,(uint)*(byte *)(param_2 + 0x4e),
                        CONCAT71((int7)((ulonglong)uVar19 >> 8),0xa1));
          bVar6 = StorPortNotification(3,param_1);
          *(undefined1 *)(param_2 + 0x4b) = 0xe;
          return bVar6;
        }
      }
      if ((((uVar4 & 0xc0) != 0) &&
          (*(byte *)(param_2 + 0x91) = *(byte *)(param_2 + 0x91) & 0x1f,
          *(char *)(param_2 + 0x90) == '\0')) && ((char)uVar4 < '\0')) {
        *(undefined1 *)(param_2 + 0x97) = *(undefined1 *)(param_2 + 0x4f);
      }
      pcVar1 = (char *)(param_2 + 0x90);
      uVar10 = (ulonglong)bVar21;
      *(undefined4 *)(param_1 + 0x4690 + uVar10 * 4) = 0;
      cVar7 = *pcVar1;
      if (cVar7 == '\x15') {
        *(undefined2 *)(param_2 + 0x4b) = 1;
        if ((uVar4 & 4) == 0) {
          *(undefined1 *)(uVar10 + 0x42dc + param_1) = 0;
          *(undefined1 *)(param_2 + 0x4b) = 1;
          return 0x15;
        }
      }
      else if (cVar7 == '\x1a') {
        if ((uVar4 & 4) == 0) {
          uVar8 = *(undefined1 *)(param_2 + 0x92);
          uVar11 = *(undefined1 *)(param_2 + 0x93);
          uVar2 = *(undefined1 *)(param_2 + 0x94);
          uVar3 = *(undefined1 *)(param_2 + 0x95);
          *(undefined1 *)(param_2 + 0x52) = 0xc;
          pcVar1[0] = '\0';
          pcVar1[1] = '\0';
          pcVar1[2] = '\0';
          pcVar1[3] = '\0';
          pcVar1[4] = '\0';
          pcVar1[5] = '\0';
          pcVar1[6] = '\0';
          pcVar1[7] = '\0';
          *(undefined4 *)(param_2 + 0x98) = 0;
          *pcVar1 = 'Z';
          *(undefined1 *)(param_2 + 0x92) = uVar8;
          *(undefined1 *)(param_2 + 0x98) = 0;
          *(undefined1 *)(param_2 + 0x97) = uVar2;
          *(undefined1 *)(param_2 + 0x93) = uVar11;
          *(undefined1 *)(param_2 + 0x99) = uVar3;
          *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_1 + 0x47f0);
          *(undefined4 *)(param_2 + 0xa4) = 1;
        }
      }
      else if (cVar7 == 'Z') {
        *(undefined4 *)(param_1 + 0x4690 + uVar10 * 4) = 1;
      }
      lVar17 = *(longlong *)(param_2 + 0x60);
      *(longlong *)(param_1 + 0x42f8 + uVar10 * 8) = lVar17;
      if ((lVar17 == 0) && ((*(uint *)(param_2 + 0x54) & 0xc0) != 0)) {
        lVar17 = *(longlong *)(param_2 + 0x10);
        if (lVar17 == 0) {
          lVar13 = 0;
        }
        else {
          lVar13 = *(longlong *)(*(longlong *)(lVar17 + 0xf0) + 0x38);
        }
        if ((lVar13 != 0) && (*(int *)(lVar13 + 0x27c) == 0)) {
          *(undefined8 *)(param_1 + 0x42f8 + uVar10 * 8) = *(undefined8 *)(lVar17 + 0xed8);
        }
      }
      uVar23 = 0;
      *(uint *)(param_1 + 0x42e0 + uVar10 * 4) = *(uint *)(param_2 + 0x58) >> 1;
      do {
        cVar7 = in(uVar20);
        if (-1 < cVar7) break;
        StorPortStallExecution(0x96);
        uVar23 = uVar23 + 1;
      } while (uVar23 < 20000);
      uVar8 = *(undefined1 *)(param_2 + 0x58);
      uVar11 = (undefined1)((uint)*(undefined4 *)(param_2 + 0x58) >> 8);
      if (0xffff < *(uint *)(param_2 + 0x58)) {
        uVar8 = 0xff;
        uVar11 = 0xff;
      }
      out(sVar16 + 4,uVar8);
      out(sVar16 + 5,uVar11);
      bVar21 = *(byte *)((ulonglong)*(byte *)(param_2 + 0x4e) * 0xb8 + 0x39c + param_1) & 0xf;
      if ((*(longlong *)(param_2 + 0x10) != 0) &&
         (*(char *)(*(longlong *)(param_2 + 0x10) + 0x101) != '\0')) {
        bVar21 = 0;
      }
      sVar15 = sVar16 + 1;
      if ((bVar21 & 4) == 0) {
        out(sVar15,0);
      }
      else {
        if (*(char *)((ulonglong)*(byte *)(param_2 + 0x4e) + 0x948 + param_1) == '\x02') {
          uVar8 = 1;
          if (-1 < (char)*(undefined4 *)(param_2 + 0x54)) {
            uVar8 = 5;
          }
          out(sVar15,uVar8);
        }
        else {
          out(sVar15,1);
        }
        PreparePRDTable(param_1,param_2);
      }
      bVar6 = 0xa0;
      if ((uVar4 & 8) == 0) {
        out(sVar16 + 7,0xa0);
        out(uVar22,(*(byte *)(param_2 + 0x4e) & 1 | 0xfa) << 4);
        uVar23 = 0;
        do {
          cVar7 = in(uVar20);
          if (-1 < cVar7) break;
          StorPortStallExecution(0x96);
          uVar23 = uVar23 + 1;
        } while (uVar23 < 20000);
        uVar23 = 0;
        do {
          bVar9 = in(uVar20);
          if ((char)bVar9 < '\0') {
            uVar14 = 100;
          }
          else {
            bVar24 = (bVar9 & 8) == 0;
            bVar6 = bVar9;
            if (!bVar24) goto LAB_0001eaca;
            uVar14 = 200;
          }
          bVar6 = StorPortStallExecution(uVar14);
          uVar23 = uVar23 + 1;
        } while (uVar23 < 1000);
        bVar24 = (bVar9 & 8) == 0;
LAB_0001eaca:
        if ((bVar24) || ((char)bVar9 < '\0')) {
          *(undefined1 *)(param_2 + 0x4b) = 4;
          return bVar6;
        }
        *(undefined1 *)(uVar10 + 0x42dc + param_1) = 1;
        lVar17 = 6;
        puVar18 = (undefined2 *)(param_2 + 0x90);
        while (lVar17 != 0) {
          lVar17 = lVar17 + -1;
          out(*puVar18,sVar16);
          puVar18 = puVar18 + 1;
        }
        if ((bVar21 & 4) != 0) {
          sVar16 = (short)uVar5;
          sVar15 = sVar16 + 2;
          bVar6 = in(sVar15);
          out(sVar15,bVar6 | 2);
          out(sVar15,bVar6 | 4);
          bVar6 = in(sVar16);
          if ((*(uint *)(param_2 + 0x54) & 0x40) == 0) {
            out(sVar16,bVar6 & 0xf7);
          }
          else {
            out(sVar16,bVar6 | 8);
          }
          bVar6 = in(sVar16);
          bVar6 = bVar6 | 1;
          out(sVar16,bVar6);
        }
      }
      else {
        *(undefined1 *)(uVar10 + 0x42dc + param_1) = 1;
        out(sVar16 + 7,0xa0);
      }
      *(undefined1 *)(param_2 + 0x4b) = 0;
    }
  }
  else {
    bVar6 = AhciDispatchOneAtapiSubCmd(param_1,param_2,param_3);
  }
  return bVar6;
}



===== BuildMechanismStatusSrb @ 0001eb40 =====

void BuildMechanismStatusSrb(longlong param_1,undefined1 param_2,ulonglong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined2 *_Dst;
  
  uVar2 = (param_3 & 0xffffffff) >> 1;
  lVar1 = uVar2 * 0xc0;
  _Dst = (undefined2 *)(param_1 + 0x43b0 + lVar1);
  *(undefined4 *)(lVar1 + 0x440c + param_1) = 1;
  *(undefined4 *)(lVar1 + 0x4414 + param_1) = 1;
  memset(_Dst,0,0x58);
  *(undefined1 *)((longlong)_Dst + 5) = param_2;
  *(char *)(_Dst + 3) = (char)param_3;
  *(undefined1 *)(_Dst + 1) = 0;
  *(ulonglong *)(_Dst + 0xc) = param_1 + 0x4670 + uVar2 * 8;
  *_Dst = 0x58;
  *(undefined4 *)(_Dst + 6) = 0x48;
  *(undefined4 *)(_Dst + 10) = 4;
  *(undefined1 *)(_Dst + 5) = 6;
  *(undefined4 *)(_Dst + 8) = 8;
  *(undefined1 *)(_Dst + 0x24) = 0xbd;
  *(undefined1 *)((longlong)_Dst + 0x51) = 8;
  return;
}



===== ReadWriteHDDSector @ 0001ebfc =====

undefined1
ReadWriteHDDSector(longlong param_1,uint param_2,ulonglong param_3,undefined2 *param_4,char param_5)

{
  undefined2 uVar1;
  undefined8 uVar2;
  short sVar3;
  short sVar4;
  undefined1 uVar5;
  byte bVar6;
  char cVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong lVar14;
  short sVar15;
  longlong lVar16;
  byte bVar17;
  short sVar18;
  undefined2 uVar19;
  uint local_res10 [2];
  uint local_48;
  
  uVar13 = (ulonglong)param_2;
  bVar17 = *(byte *)(uVar13 + 0x948 + param_1);
  if ((bVar17 & 4) != 0) {
    uVar5 = AhciReadWriteHDDSector(param_1,uVar13,param_3,param_4,param_5);
    return uVar5;
  }
  if ((bVar17 & 2) != 0) {
    ReadWriteHostSStatusRegister(param_1,param_2,param_3,local_res10);
    *(uint *)(param_1 + 0x100 + uVar13 * 4) = local_res10[0];
    if (((byte)local_res10[0] & 0xf) != 3) {
      return 4;
    }
  }
  uVar8 = (ulonglong)(param_2 >> 1);
  uVar9 = *(undefined8 *)(param_1 + 0xc0 + uVar8 * 8);
  uVar2 = *(undefined8 *)(param_1 + 0xe0 + uVar8 * 8);
  sVar4 = (short)*(undefined8 *)(param_1 + 0xa0 + uVar8 * 8);
  sVar15 = sVar4 + 6;
  bVar17 = ((byte)param_2 & 1 | 0xfa) << 4;
  out(sVar15,bVar17);
  uVar10 = 0;
  local_48 = 0;
  do {
    uVar19 = (undefined2)uVar9;
    bVar6 = in(uVar19);
    local_res10[0] = CONCAT31(local_res10[0]._1_3_,bVar6);
    if (-1 < (char)bVar6) goto LAB_0001ed03;
    StorPortStallExecution(0x96);
    local_48 = local_48 + 1;
  } while (local_48 < 20000);
  bVar6 = (byte)local_res10[0];
  if (-1 < (char)(byte)local_res10[0]) {
LAB_0001ed03:
    if ((((bVar6 & 0x40) != 0) && ((bVar6 & 1) == 0)) && ((bVar6 & 0x20) == 0)) {
      lVar16 = uVar13 * 0xb8;
      uVar11 = *(uint *)(lVar16 + 0x39c + param_1);
      if ((uVar11 & 0x10) == 0) {
        lVar14 = uVar13 * 0xd4;
        if (0xffffffff < param_3) {
          return 4;
        }
        out(sVar4 + 2,1);
        out(sVar4 + 3,
            (char)((param_3 & 0xffffffff) % (ulonglong)*(ushort *)(lVar14 + 0xd20 + param_1)) +
            '\x01');
        out(sVar4 + 4,
            (char)((param_3 & 0xffffffff) /
                  (ulonglong)
                  ((uint)*(ushort *)(lVar14 + 0xd1a + param_1) *
                  (uint)*(ushort *)(lVar14 + 0xd20 + param_1))));
        out(sVar4 + 5,
            (char)((param_3 & 0xffffffff) /
                   (ulonglong)
                   ((uint)*(ushort *)(lVar14 + 0xd1a + param_1) *
                   (uint)*(ushort *)(lVar14 + 0xd20 + param_1)) >> 8));
        bVar17 = (byte)(((param_3 & 0xffffffff) / (ulonglong)*(ushort *)(lVar14 + 0xd20 + param_1))
                       % (ulonglong)*(ushort *)(lVar14 + 0xd1a + param_1)) | bVar17;
        out(sVar15,bVar17);
      }
      else {
        bVar6 = (byte)(param_3 >> 0x18);
        if ((uVar11 & 0x20) != 0) {
          out(sVar4 + 2,0);
          out(sVar4 + 3,bVar6);
          out(sVar4 + 4,(char)(param_3 >> 0x20));
          out(sVar4 + 5,(char)(param_3 >> 0x28));
        }
        out(sVar4 + 2,1);
        out(sVar4 + 3,(char)param_3);
        out(sVar4 + 4,(char)(param_3 >> 8));
        out(sVar4 + 5,(char)(param_3 >> 0x10));
        bVar17 = ((byte)param_2 | 0xfe) << 4;
        if ((*(uint *)(lVar16 + 0x39c + param_1) & 0x20) == 0) {
          bVar17 = bVar17 | bVar6;
        }
        out(sVar15,bVar17);
      }
      uVar11 = *(uint *)(lVar16 + 0x39c + param_1);
      sVar18 = (short)uVar2;
      if (param_5 == '\0') {
        sVar3 = sVar4 + 7;
        if ((uVar11 & 0x20) == 0) {
          out(sVar3,0x20);
        }
        else {
          out(sVar3,0x24);
        }
        out(sVar15,bVar17);
        uVar11 = 0;
        do {
          cVar7 = in(uVar19);
          if (-1 < cVar7) break;
          StorPortStallExecution(0x96);
          uVar11 = uVar11 + 1;
        } while (uVar11 < 20000);
        uVar11 = 0;
        do {
          bVar17 = in(uVar19);
          if (-1 < (char)bVar17) break;
          StorPortStallExecution(0x96);
          uVar11 = uVar11 + 1;
        } while (uVar11 < 20000);
        if (-1 < (char)bVar17) {
          if ((bVar17 & 1) != 0) {
            return 4;
          }
          uVar11 = 0;
          while( true ) {
            uVar12 = 0;
            do {
              bVar17 = in(uVar19);
              local_res10[0] = CONCAT31(local_res10[0]._1_3_,bVar17);
              if ((char)bVar17 < '\0') {
                uVar9 = 100;
              }
              else {
                if ((bVar17 & 8) != 0) goto LAB_0001ef5c;
                uVar9 = 200;
              }
              StorPortStallExecution(uVar9);
              uVar12 = uVar12 + 1;
            } while (uVar12 < 1000);
            if ((local_res10[0] & 8) != 0) break;
            uVar11 = uVar11 + 1;
            if (0xf < uVar11) goto LAB_0001ef87;
          }
LAB_0001ef5c:
          in(sVar3);
          sVar18 = sVar18 + 2;
          bVar17 = in(sVar18);
          if ((bVar17 & 4) != 0) {
            out(sVar18,bVar17);
          }
          lVar16 = 0x100;
          while (lVar16 != 0) {
            lVar16 = lVar16 + -1;
            uVar1 = in(sVar4);
            *param_4 = uVar1;
            param_4 = param_4 + 1;
          }
LAB_0001ef87:
          if (uVar11 == 0x10) {
            return 9;
          }
          do {
            bVar17 = in(uVar19);
            if ((bVar17 & 8) == 0) {
              return 1;
            }
            in(sVar4);
            uVar10 = uVar10 + 1;
          } while (uVar10 < 0x10000);
          return 1;
        }
      }
      else {
        sVar3 = sVar4 + 7;
        if ((uVar11 & 0x20) == 0) {
          out(sVar3,0x30);
        }
        else {
          out(sVar3,0x34);
        }
        out(sVar15,bVar17);
        uVar11 = 0;
        do {
          cVar7 = in(uVar19);
          if (-1 < cVar7) break;
          StorPortStallExecution(0x96);
          uVar11 = uVar11 + 1;
        } while (uVar11 < 20000);
        uVar11 = 0;
        do {
          bVar17 = in(uVar19);
          if (-1 < (char)bVar17) break;
          StorPortStallExecution(0x96);
          uVar11 = uVar11 + 1;
        } while (uVar11 < 20000);
        if (-1 < (char)bVar17) {
          if ((bVar17 & 1) != 0) {
            return 4;
          }
          uVar11 = 0;
          do {
            bVar17 = in(uVar19);
            local_res10[0] = CONCAT31(local_res10[0]._1_3_,bVar17);
            if ((bVar17 & 8) != 0) goto LAB_0001f06b;
            StorPortStallExecution(200);
            uVar11 = uVar11 + 1;
          } while (uVar11 < 0x10000);
          if ((local_res10[0] & 8) != 0) {
LAB_0001f06b:
            lVar16 = 0x100;
            while (lVar16 != 0) {
              lVar16 = lVar16 + -1;
              out(*param_4,sVar4);
              param_4 = param_4 + 1;
            }
            uVar11 = 0;
            do {
              bVar17 = in(uVar19);
              if ((bVar17 & 8) == 0) break;
              out(sVar4,0);
              uVar11 = uVar11 + 1;
            } while (uVar11 < 0x10000);
            if ((bVar17 & 8) == 0) {
              bVar17 = in(uVar19);
              if ((bVar17 & 1) != 0) {
                return 4;
              }
              uVar11 = 0;
              do {
                cVar7 = in(uVar19);
                if (-1 < cVar7) break;
                StorPortStallExecution(0x96);
                uVar11 = uVar11 + 1;
              } while (uVar11 < 20000);
              do {
                cVar7 = in(uVar19);
                if (-1 < cVar7) break;
                StorPortStallExecution(0x96);
                uVar10 = uVar10 + 1;
              } while (uVar10 < 20000);
              if (-1 < cVar7) {
                in(sVar3);
                sVar18 = sVar18 + 2;
                bVar17 = in(sVar18);
                if ((bVar17 & 4) == 0) {
                  return 1;
                }
                out(sVar18,bVar17);
                return 1;
              }
            }
          }
          return 9;
        }
      }
      return 5;
    }
  }
  return 4;
}



===== ReadConfigSpace @ 0001f130 =====

void ReadConfigSpace(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x21c);
  StorPortGetBusData(param_1,4,uVar1 >> 0x10 & 0xff,(uVar1 >> 3 & 0xe0) + (uVar1 >> 0xb & 0x1f),
                     param_1 + 0x13b4,0x100);
  return;
}



===== ReadConfigSpaceUlong @ 0001f180 =====

undefined4 ReadConfigSpaceUlong(longlong param_1,uint param_2)

{
  StorPortGetBusData(param_1,4,param_2 >> 0x10 & 0xff,
                     (param_2 >> 3 & 0xe0) + (param_2 >> 0xb & 0x1f),param_1 + 0x13b4,0x100);
  return *(undefined4 *)(param_1 + 0x13b4 + (ulonglong)(param_2 >> 2 & 0x3f) * 4);
}



===== WriteConfigSpaceUlong @ 0001f1ec =====

void WriteConfigSpaceUlong(undefined8 param_1,uint param_2,undefined4 param_3)

{
  undefined4 local_res18 [4];
  
  local_res18[0] = param_3;
  StorPortSetBusDataByOffset
            (param_1,4,param_2 >> 0x10 & 0xff,(param_2 >> 3 & 0xe0) + (param_2 >> 0xb & 0x1f),
             local_res18,param_2 & 0xff,4);
  return;
}



===== WriteConfigSpaceUCHAR @ 0001f23c =====

void WriteConfigSpaceUCHAR(undefined8 param_1,uint param_2,undefined1 param_3)

{
  undefined1 local_res18 [16];
  
  local_res18[0] = param_3;
  StorPortSetBusDataByOffset
            (param_1,4,param_2 >> 0x10 & 0xff,(param_2 >> 3 & 0xe0) + (param_2 >> 0xb & 0x1f),
             local_res18,param_2 & 0xff,1);
  return;
}



===== ReadConfigSpaceUCHAR @ 0001f290 =====

undefined8 ReadConfigSpaceUCHAR(longlong param_1,uint param_2)

{
  longlong lVar1;
  
  StorPortGetBusData(param_1,4,param_2 >> 0x10 & 0xff,
                     (param_2 >> 3 & 0xe0) + (param_2 >> 0xb & 0x1f),param_1 + 0x13b4,0x100);
  lVar1 = (ulonglong)((param_2 & 0xff) - (param_2 & 0xfc)) + param_1;
  return CONCAT71((int7)((ulonglong)lVar1 >> 8),
                  *(undefined1 *)(lVar1 + 0x13b4 + (ulonglong)(param_2 >> 2 & 0x3f) * 4));
}



===== SetTargetProperty @ 0001f30c =====

void SetTargetProperty(longlong param_1)

{
  int iVar1;
  byte *pbVar2;
  char *pcVar3;
  uint uVar4;
  longlong lVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)(param_1 + 0x954);
  *puVar6 = 0;
  iVar1 = *(int *)(param_1 + 0x20c);
  if (iVar1 == 0x33491106) {
    lVar5 = *(longlong *)(param_1 + 0x58);
    *(undefined1 *)(param_1 + 0xb10) = 1;
    *(undefined1 *)(param_1 + 0x60) = 1;
    uVar4 = 0;
    pbVar2 = (byte *)(param_1 + 0x948);
    do {
      if ((*(uint *)(lVar5 + 0xc) >> (uVar4 & 0x1f) & 1) != 0) {
        *pbVar2 = *pbVar2 | 4;
        *(undefined1 *)puVar6 = 1;
      }
      uVar4 = uVar4 + 1;
      pbVar2 = pbVar2 + 2;
      puVar6 = (undefined4 *)((longlong)puVar6 + 1);
    } while ((int)uVar4 < 4);
    *(undefined1 *)(param_1 + 0x950) = 0;
    goto LAB_0001f49b;
  }
  if (iVar1 == 0x31491106) {
    *(byte *)(param_1 + 0x948) = *(byte *)(param_1 + 0x948) | 2;
    *(byte *)(param_1 + 0x949) = *(byte *)(param_1 + 0x949) | 2;
    *(byte *)(param_1 + 0x94a) = *(byte *)(param_1 + 0x94a) | 2;
    *(byte *)(param_1 + 0x94b) = *(byte *)(param_1 + 0x94b) | 2;
LAB_0001f48a:
    *(undefined1 *)(param_1 + 0x950) = 1;
    *(undefined1 *)(param_1 + 0x955) = 2;
    *(undefined1 *)puVar6 = 2;
  }
  else {
    if (iVar1 == 0x5911106) {
      ReadConfigSpace(param_1);
      if ((*(byte *)(param_1 + 0x13fd) & 0x20) == 0) {
        *(byte *)(param_1 + 0x948) = *(byte *)(param_1 + 0x948) | 2;
        *(byte *)(param_1 + 0x94a) = *(byte *)(param_1 + 0x94a) | 2;
        *(undefined1 *)(param_1 + 0x950) = 0;
        *(undefined1 *)puVar6 = 1;
      }
      else {
        *(byte *)(param_1 + 0x948) = *(byte *)(param_1 + 0x948) | 2;
        *(byte *)(param_1 + 0x949) = *(byte *)(param_1 + 0x949) | 2;
        *(undefined1 *)(param_1 + 0x950) = 1;
        *(undefined1 *)puVar6 = 2;
      }
      *(undefined1 *)(param_1 + 0xb10) = 0;
      goto LAB_0001f49b;
    }
    if (iVar1 == 0x32491106) {
      *(byte *)(param_1 + 0x948) = *(byte *)(param_1 + 0x948) | 2;
      *(byte *)(param_1 + 0x94a) = *(byte *)(param_1 + 0x94a) | 2;
      *(byte *)(param_1 + 0x94c) = *(byte *)(param_1 + 0x94c) | 1;
      *(byte *)(param_1 + 0x94d) = *(byte *)(param_1 + 0x94d) | 1;
      *(undefined1 *)(param_1 + 0x950) = 1;
      *(undefined2 *)(param_1 + 0x955) = 0x201;
    }
    else {
      if (iVar1 != 0x73721106) {
        if (iVar1 == 0x31641106) {
          *(byte *)(param_1 + 0x948) = *(byte *)(param_1 + 0x948) | 1;
          *(byte *)(param_1 + 0x949) = *(byte *)(param_1 + 0x949) | 1;
        }
        else {
          if (iVar1 != 0x5811106) goto LAB_0001f49b;
          *(byte *)(param_1 + 0x948) = *(byte *)(param_1 + 0x948) | 2;
          *(byte *)(param_1 + 0x949) = *(byte *)(param_1 + 0x949) | 2;
        }
        *(byte *)(param_1 + 0x94a) = *(byte *)(param_1 + 0x94a) | 1;
        *(byte *)(param_1 + 0x94b) = *(byte *)(param_1 + 0x94b) | 1;
        goto LAB_0001f48a;
      }
      *(byte *)(param_1 + 0x948) = *(byte *)(param_1 + 0x948) | 2;
      *(byte *)(param_1 + 0x94a) = *(byte *)(param_1 + 0x94a) | 2;
      *(undefined1 *)(param_1 + 0xb10) = 0;
      *(undefined1 *)(param_1 + 0x950) = 0;
      *(undefined1 *)(param_1 + 0x955) = 1;
    }
    *(undefined1 *)puVar6 = 1;
  }
LAB_0001f49b:
  iVar1 = 0;
  pcVar3 = (char *)(param_1 + 0x948);
  lVar5 = 8;
  do {
    if (*pcVar3 != '\0') {
      iVar1 = iVar1 + 1;
    }
    pcVar3 = pcVar3 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  *(int *)(param_1 + 4) = iVar1;
  return;
}



===== ModifyConfigSpace @ 0001f4c4 =====

void ModifyConfigSpace(longlong param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong lVar7;
  
  iVar1 = *(int *)(param_1 + 0x20c);
  uVar6 = *(uint *)(param_1 + 0x21c);
  if ((iVar1 == 0x31491106) || (iVar1 == 0x5911106)) {
    WriteConfigSpaceUlong(param_1,uVar6 + 8,0x1048f06);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0x44);
    WriteConfigSpaceUCHAR(param_1,uVar6 + 0x44,(byte)uVar4 & 0xf7);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0x48);
    WriteConfigSpaceUCHAR(param_1,uVar6 + 0x48,(byte)uVar4 | 0x10);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0x56);
    WriteConfigSpaceUCHAR(param_1,uVar6 + 0x56,(byte)uVar4 | 4);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0x57);
    uVar6 = uVar6 + 0x57;
    bVar2 = (byte)uVar4 | 4;
  }
  else if (iVar1 == 0x32491106) {
    uVar3 = ReadConfigSpaceUlong(param_1,uVar6 + 4);
    WriteConfigSpaceUlong(param_1,uVar6 + 4,uVar3 | 7);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0x44);
    WriteConfigSpaceUCHAR(param_1,uVar6 + 0x44,(byte)uVar4 & 0xf7);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0xb2);
    WriteConfigSpaceUCHAR(param_1,uVar6 + 0xb2,(byte)uVar4 | 0xef);
    uVar6 = uVar6 + 0xb3;
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6);
    bVar2 = (byte)uVar4 | 0xef;
  }
  else if (iVar1 == 0x73721106) {
    WriteConfigSpaceUlong(param_1,uVar6 + 8,0x1048f06);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0x44);
    WriteConfigSpaceUCHAR(param_1,uVar6 + 0x44,(byte)uVar4 & 0xf7);
    uVar5 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0x49);
    if ((uVar5 & 2) == 0) {
      return;
    }
    bVar2 = (byte)uVar5 & 0xfd;
    uVar6 = uVar6 + 0x49;
  }
  else {
    if (iVar1 == 0x31641106) {
      uVar3 = ReadConfigSpaceUlong(param_1,uVar6 + 4);
      WriteConfigSpaceUlong(param_1,uVar6 + 4,uVar3 | 7);
      uVar3 = ReadConfigSpaceUlong(param_1,uVar6 + 0x40);
      WriteConfigSpaceUlong(param_1,uVar6 + 0x40,uVar3 | 3);
      uVar3 = uVar6 & 0xffffff00;
      uVar4 = ReadConfigSpaceUCHAR(param_1,uVar3 + 0x44);
      WriteConfigSpaceUCHAR(param_1,uVar3 + 0x44,(byte)uVar4 & 0xf7);
      uVar4 = ReadConfigSpaceUCHAR(param_1,uVar3 + 0x54);
      WriteConfigSpaceUCHAR(param_1,uVar3 + 0x54,(byte)uVar4 | 0x10);
      WriteConfigSpaceUlong(param_1,uVar6 + 0x48,0xa8a8a8a8);
      lVar7 = 2;
      do {
        StorPortStallExecution(1000);
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      StorPortStallExecution(0);
      return;
    }
    if (iVar1 != 0x5811106) {
      return;
    }
    uVar3 = ReadConfigSpaceUlong(param_1,uVar6 + 4);
    WriteConfigSpaceUlong(param_1,uVar6 + 4,uVar3 | 7);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0x44);
    WriteConfigSpaceUCHAR(param_1,uVar6 + 0x44,(byte)uVar4 & 0xf7);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0xc4);
    WriteConfigSpaceUCHAR(param_1,uVar6 + 0xc4,(byte)uVar4 & 0xf7);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0x50);
    WriteConfigSpaceUCHAR(param_1,uVar6 + 0x50,(byte)uVar4 | 0xef);
    uVar4 = ReadConfigSpaceUCHAR(param_1,uVar6 + 0x51);
    uVar6 = uVar6 + 0x51;
    bVar2 = (byte)uVar4 | 0xef;
  }
  WriteConfigSpaceUCHAR(param_1,uVar6,bVar2);
  return;
}



===== FillBaseRegisterAddr @ 0001f790 =====

void FillBaseRegisterAddr(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong lVar11;
  
  iVar1 = *(int *)(param_1 + 0x20c);
  plVar4 = (longlong *)(param_1 + 0xa0);
  plVar8 = (longlong *)(param_1 + 0xc0);
  plVar7 = (longlong *)(param_1 + 0xe0);
  lVar10 = param_1 + 0x140;
  plVar9 = (longlong *)(param_1 + 0x1c0);
  lVar11 = param_1 + 0x180;
  if (iVar1 == 0x5811106) {
    lVar10 = 0;
    lVar11 = (longlong)plVar4 - (longlong)plVar8;
    lVar5 = (longlong)plVar7 - (longlong)plVar8;
    lVar6 = 2;
    plVar7 = param_2;
    do {
      *(longlong *)(lVar11 + (longlong)plVar8) = *plVar7;
      *plVar8 = plVar7[2] + 2;
      lVar3 = param_2[8] + lVar10;
      lVar10 = lVar10 + 8;
      *(longlong *)((longlong)plVar8 + lVar5) = lVar3;
      plVar8 = plVar8 + 1;
      lVar6 = lVar6 + -1;
      plVar7 = plVar7 + 4;
    } while (lVar6 != 0);
  }
  else if ((iVar1 == 0x5911106) || (iVar1 == 0x31491106)) {
    lVar10 = lVar10 - (longlong)plVar9;
    *plVar4 = *param_2;
    *plVar8 = param_2[2] + 2;
    *(longlong *)(param_1 + 0xa8) = param_2[4];
    *(longlong *)(param_1 + 200) = param_2[6] + 2;
    *plVar7 = param_2[8];
    *(longlong *)(param_1 + 0xe8) = param_2[8] + 8;
    lVar5 = 0;
    *(longlong *)(param_1 + 0x200) = param_2[10];
    lVar11 = lVar11 - (longlong)plVar9;
    lVar6 = 4;
    do {
      *(longlong *)(lVar10 + (longlong)plVar9) = *(longlong *)(param_1 + 0x200) + lVar5;
      *plVar9 = *(longlong *)(param_1 + 0x200) + 4 + lVar5;
      lVar3 = *(longlong *)(param_1 + 0x200) + 8 + lVar5;
      lVar5 = lVar5 + 0x40;
      *(longlong *)(lVar11 + (longlong)plVar9) = lVar3;
      plVar9 = plVar9 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  else if (iVar1 == 0x31641106) {
    lVar10 = 0;
    lVar11 = (longlong)plVar4 - (longlong)plVar8;
    lVar5 = (longlong)plVar7 - (longlong)plVar8;
    lVar6 = 2;
    plVar7 = param_2;
    do {
      *(longlong *)(lVar11 + (longlong)plVar8) = *plVar7;
      *plVar8 = plVar7[2] + 2;
      lVar3 = param_2[8] + lVar10;
      lVar10 = lVar10 + 8;
      *(longlong *)(lVar5 + (longlong)plVar8) = lVar3;
      plVar8 = plVar8 + 1;
      lVar6 = lVar6 + -1;
      plVar7 = plVar7 + 4;
    } while (lVar6 != 0);
  }
  else if (iVar1 == 0x32491106) {
    lVar3 = 4;
    lVar6 = (longlong)plVar4 - (longlong)plVar8;
    lVar5 = 4;
    plVar4 = param_2;
    do {
      *(longlong *)(lVar6 + (longlong)plVar8) = *plVar4;
      lVar2 = *plVar4;
      plVar4 = plVar4 + 2;
      *plVar8 = lVar2 + 10;
      plVar8 = plVar8 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    lVar5 = 0;
    do {
      lVar6 = param_2[8] + lVar5;
      lVar5 = lVar5 + 8;
      *plVar7 = lVar6;
      plVar7 = plVar7 + 1;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    lVar10 = lVar10 - (longlong)plVar9;
    lVar6 = 2;
    *(longlong *)(param_1 + 0x200) = param_2[10];
    lVar11 = lVar11 - (longlong)plVar9;
    lVar5 = 0;
    do {
      *(longlong *)((longlong)plVar9 + lVar10) = *(longlong *)(param_1 + 0x200) + lVar5;
      *plVar9 = *(longlong *)(param_1 + 0x200) + 4 + lVar5;
      lVar3 = *(longlong *)(param_1 + 0x200) + 8 + lVar5;
      lVar5 = lVar5 + 0x40;
      *(longlong *)((longlong)plVar9 + lVar11) = lVar3;
      plVar9 = plVar9 + 2;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  else if (iVar1 == 0x33491106) {
    *(longlong *)(param_1 + 0x58) = param_2[10];
  }
  else if (iVar1 == 0x73721106) {
    lVar10 = lVar10 - (longlong)plVar9;
    *plVar4 = *param_2;
    *plVar8 = param_2[2] + 2;
    *(longlong *)(param_1 + 0xa8) = param_2[4];
    *(longlong *)(param_1 + 200) = param_2[6] + 2;
    *plVar7 = param_2[8];
    *(longlong *)(param_1 + 0xe8) = param_2[8] + 8;
    lVar5 = 0;
    *(longlong *)(param_1 + 0x200) = param_2[10];
    lVar11 = lVar11 - (longlong)plVar9;
    lVar6 = 4;
    do {
      *(longlong *)(lVar10 + (longlong)plVar9) = *(longlong *)(param_1 + 0x200) + lVar5;
      *plVar9 = *(longlong *)(param_1 + 0x200) + 4 + lVar5;
      lVar3 = *(longlong *)(param_1 + 0x200) + 8 + lVar5;
      lVar5 = lVar5 + 0x40;
      *(longlong *)(lVar11 + (longlong)plVar9) = lVar3;
      plVar9 = plVar9 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  return;
}



===== ReadWriteHostSStatusRegister @ 0001fa90 =====

void ReadWriteHostSStatusRegister(longlong param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  byte bVar3;
  
  if ((*(int *)(param_1 + 0x208) == 0x5811106) || (*(int *)(param_1 + 0x208) == 0x73721106)) {
    *param_4 = 0;
    uVar2 = ReadConfigSpaceUCHAR(param_1,param_2 + 0xa0 + *(int *)(param_1 + 0x218));
    uVar1 = (uint)uVar2 & 3 | *param_4 & 0xfffffff0;
    bVar3 = ((byte)uVar2 >> 2 & 3) - 1;
    if ((char)bVar3 < '\0') {
      bVar3 = 0;
    }
    uVar1 = (((((uint)uVar2 & 0xff) >> 2 & 3) + 1 << (bVar3 & 0x1f)) << 8 ^ uVar1) & 0xf00 ^ uVar1;
    *param_4 = uVar1;
    if ((uVar2 & 0x10) == 0) {
      uVar1 = uVar1 & 0xffffff1f | 0x10;
    }
    else {
      uVar1 = uVar1 & 0xffffff2f | 0x20;
    }
    *param_4 = uVar1;
  }
  else {
    uVar1 = in((short)*(undefined8 *)(param_1 + 0x140 + (ulonglong)param_2 * 8));
    *param_4 = uVar1;
  }
  return;
}



===== ReadWriteHostSControlRegister @ 0001fb48 =====

ulonglong ReadWriteHostSControlRegister(longlong param_1,uint param_2,char param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  if ((*(int *)(param_1 + 0x208) == 0x5811106) || (*(int *)(param_1 + 0x208) == 0x73721106)) {
    if (param_3 == '\0') {
      uVar4 = WriteConfigSpaceUCHAR
                        (param_1,param_2 + 0xa4 + *(int *)(param_1 + 0x218),
                         ((byte)*param_4 >> 1 & 2 | (byte)*param_4 & 1) ^
                         ((byte)(*param_4 >> 8) & 3) << 2);
      return uVar4;
    }
    *param_4 = 0;
    uVar3 = ReadConfigSpaceUCHAR(param_1,param_2 + 0xa4 + *(int *)(param_1 + 0x218));
    uVar1 = (uint)uVar3;
    uVar2 = *param_4;
    *param_4 = (uVar1 & 2) * 2 | (uVar1 & 0xc) << 6 | uVar1 & 1 | uVar2 & 0xfffff000;
    return (ulonglong)(uVar2 & 0xfffff000);
  }
  if (param_3 == '\0') {
    out((short)*(undefined8 *)(param_1 + 0x180 + (ulonglong)param_2 * 8),*param_4);
    return (ulonglong)*param_4;
  }
  uVar2 = in((short)*(undefined8 *)(param_1 + 0x180 + (ulonglong)param_2 * 8));
  *param_4 = uVar2;
  return (ulonglong)uVar2;
}



===== ReadWriteHostSErrorRegister @ 0001fc0c =====

undefined4
ReadWriteHostSErrorRegister(longlong param_1,uint param_2,char param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x208) == 0x5811106) {
    iVar3 = param_2 + 0x2a;
  }
  else {
    if (*(int *)(param_1 + 0x208) != 0x73721106) {
      if (param_3 == '\0') {
        out((short)*(undefined8 *)(param_1 + 0x1c0 + (ulonglong)param_2 * 8),*param_4);
        return *param_4;
      }
      uVar2 = in((short)*(undefined8 *)(param_1 + 0x1c0 + (ulonglong)param_2 * 8));
      *param_4 = uVar2;
      return uVar2;
    }
    iVar3 = param_2 + 0x2c;
  }
  uVar1 = *(int *)(param_1 + 0x218) + iVar3 * 4;
  if (param_3 == '\0') {
    uVar2 = WriteConfigSpaceUlong(param_1,uVar1,*param_4);
    return uVar2;
  }
  uVar2 = ReadConfigSpaceUlong(param_1,uVar1);
  *param_4 = uVar2;
  return uVar2;
}



===== AtapiHwInitialize @ 0001fc84 =====

undefined8 AtapiHwInitialize(longlong param_1,undefined8 param_2,undefined8 param_3,uint *param_4)

{
  undefined8 uVar1;
  
  AhciInitCtler(param_1);
  uVar1 = SataResetController(param_1,'\x01',param_3,param_4);
  if ((char)uVar1 != '\0') {
    uVar1 = InitHotPlugParams(param_1);
    uVar1 = CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
  }
  return uVar1;
}



===== SataResetController @ 0001fcb0 =====

/* WARNING: Removing unreachable block (ram,0x0001febd) */
/* WARNING: Removing unreachable block (ram,0x0001fdf1) */
/* WARNING: Removing unreachable block (ram,0x0001ff2f) */

ulonglong SataResetController(longlong param_1,char param_2,undefined8 param_3,uint *param_4)

{
  char cVar1;
  byte bVar2;
  undefined1 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ushort uVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  byte *pbVar11;
  uint uVar12;
  undefined2 *puVar13;
  ulonglong uVar14;
  int iVar15;
  undefined2 uVar16;
  uint uVar17;
  uint local_res18 [2];
  ulonglong local_68 [4];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_res18[0] = CONCAT31(local_res18[0]._1_3_,(char)param_3);
  local_48 = *(undefined8 *)(param_1 + 0xc0);
  local_40 = *(undefined8 *)(param_1 + 200);
  local_38 = *(undefined8 *)(param_1 + 0xd0);
  local_30 = *(undefined8 *)(param_1 + 0xd8);
  local_68[0] = *(ulonglong *)(param_1 + 0xa0);
  local_68[1] = *(undefined8 *)(param_1 + 0xa8);
  local_68[2] = *(undefined8 *)(param_1 + 0xb0);
  local_68[3] = *(undefined8 *)(param_1 + 0xb8);
  *(undefined1 *)(param_1 + 0x8c) = 0;
  puVar3 = (undefined1 *)(param_1 + 0x4828);
  lVar9 = 8;
  do {
    lVar8 = lVar9;
    puVar3[0x4c] = 0;
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    lVar9 = lVar8 + -1;
  } while (lVar9 != 0);
  iVar7 = (int)lVar8 + 1;
  uVar5 = 0;
  if (*(int *)(param_1 + 0x90) != iVar7) {
    iVar15 = 0;
LAB_0001fd7f:
    uVar14 = 0;
    if (0 < iVar15) {
      param_2 = '\x01';
    }
    if (param_2 != '\0') {
      pbVar11 = (byte *)(param_1 + 0x948);
      uVar4 = uVar14;
      do {
        uVar12 = (uint)uVar4;
        if ((*pbVar11 & 4) == 0) {
          if (((byte)iVar7 & *pbVar11) != 0) {
            CommReset(param_1,uVar12);
            goto LAB_0001fdbe;
          }
        }
        else {
          param_3 = 0;
          uVar4 = (ulonglong)(uVar12 >> 1);
          AhciResetPort(param_1,uVar12 >> 1,'\0');
LAB_0001fdbe:
          iVar7 = 2;
          uVar5 = uVar4;
        }
        uVar4 = (ulonglong)(uVar12 + 1);
        pbVar11 = pbVar11 + 1;
      } while (uVar12 + 1 < 8);
    }
    FindDevices(param_1);
    uVar4 = uVar14;
    do {
      uVar12 = (uint)uVar4;
      bVar2 = *(byte *)(uVar4 + 0x948 + param_1);
      if ((bVar2 & 4) == 0) {
        if ((bVar2 & 2) != 0) {
          param_4 = local_res18;
          uVar5 = uVar4;
          ReadWriteHostSStatusRegister(param_1,uVar12,param_3,param_4);
          *(uint *)(param_1 + 0x100 + uVar4 * 4) = local_res18[0];
          bVar2 = (byte)local_res18[0];
          goto LAB_0001fe38;
        }
      }
      else {
        local_res18[0] =
             *(uint *)((longlong)(int)(uVar12 >> 1 & 0x80000003) * 0x80 + 0x128 +
                      *(longlong *)(param_1 + 0x58));
        uVar5 = (ulonglong)local_res18[0];
        bVar2 = (byte)local_res18[0];
LAB_0001fe38:
        if ((bVar2 & 1) != 0) {
          uVar6 = *(ushort *)(param_1 + 0xab8 + uVar4 * 2);
          uVar4 = (ulonglong)uVar6;
          if (((uVar6 & 1) == 0) && ((uVar6 & 0x2000) == 0)) goto LAB_0001fff7;
        }
      }
      uVar4 = (ulonglong)(uVar12 + 1);
    } while (uVar12 + 1 < 8);
    pbVar11 = (byte *)(param_1 + 0xab8);
    uVar10 = uVar5;
    uVar4 = uVar14;
    do {
      uVar5 = uVar4;
      uVar12 = (uint)uVar5;
      if ((*pbVar11 & 1) != 0) {
        uVar4 = DevInitializeEx(param_1,uVar12);
        uVar10 = uVar5;
        if ((char)uVar4 == '\0') goto LAB_0001fff7;
      }
      uVar5 = uVar10;
      uVar12 = uVar12 + 1;
      pbVar11 = pbVar11 + 2;
      uVar10 = uVar5;
      uVar4 = (ulonglong)uVar12;
    } while (uVar12 < 8);
    do {
      uVar10 = 0;
      uVar12 = (uint)uVar14;
      if (7 < uVar12) {
        StorPortStallExecution(0x32);
        uVar14 = uVar10;
        uVar4 = uVar10;
        do {
          bVar2 = *(byte *)(uVar14 + 0x948 + param_1);
          if ((bVar2 != 0) && ((bVar2 & 4) == 0)) {
            out((ushort)local_68[uVar14 >> 1] + 6,((byte)uVar4 & 1 | 0xfa) << 4);
            uVar12 = (ushort)local_68[uVar14 >> 1] + 7;
            uVar5 = (ulonglong)uVar12;
            in((short)uVar12);
          }
          uVar12 = (int)uVar4 + 1;
          uVar4 = (ulonglong)uVar12;
          uVar14 = uVar14 + 1;
        } while (uVar12 < 8);
        param_3 = 2;
        uVar14 = uVar10;
        do {
          if ((*(char *)((ulonglong)(uint)((int)uVar14 * 2) + 0x948 + param_1) != '\0') &&
             ((*(byte *)(uVar14 + 0x948 + param_1) & 4) == 0)) {
            uVar6 = (short)*(undefined8 *)(param_1 + 0xe0 + uVar14 * 8) + 2;
            uVar5 = (ulonglong)uVar6;
            bVar2 = in(uVar6);
            if ((bVar2 & 4) != 0) {
              out(uVar6,bVar2);
            }
          }
          uVar12 = (int)uVar14 + 1;
          uVar14 = (ulonglong)uVar12;
        } while (uVar12 < 4);
        do {
          if ((*(char *)((ulonglong)(uint)((int)uVar10 * 2) + 0x948 + param_1) != '\0') &&
             ((*(byte *)(uVar10 + 0x948 + param_1) & 4) == 0)) {
            uVar5 = (ulonglong)(ushort)local_68[uVar10 + 4];
            out((ushort)local_68[uVar10 + 4],0);
            StorPortStallExecution(5);
          }
          uVar12 = (int)uVar10 + 1;
          uVar10 = (ulonglong)uVar12;
        } while (uVar12 < 4);
        AhciResetInterrupt(param_1);
        StorPortStallExecution(0x32);
        goto LAB_000200e2;
      }
      bVar2 = *(byte *)(uVar14 + 0x948 + param_1);
      if ((bVar2 & 4) == 0) {
        if ((bVar2 & 2) != 0) {
          param_4 = local_res18;
          uVar5 = uVar14;
          ReadWriteHostSStatusRegister(param_1,uVar12,param_3,param_4);
          *(uint *)(param_1 + 0x100 + uVar14 * 4) = local_res18[0];
          bVar2 = (byte)local_res18[0];
          goto LAB_0001feff;
        }
LAB_0001ff0a:
        if ((*(byte *)(param_1 + 0xab8 + uVar14 * 2) & 1) != 0) {
          if ((*(byte *)(uVar14 + 0x948 + param_1) & 4) == 0) {
            out((short)local_68[uVar14 >> 1] + 6,((byte)uVar14 & 1 | 0xfa) << 4);
            uVar4 = local_68[uVar14 >> 1];
            uVar14 = uVar4 + 7;
            do {
              uVar16 = (undefined2)uVar14;
              cVar1 = in(uVar16);
              uVar4 = CONCAT71((int7)(uVar4 >> 8),cVar1);
              if (-1 < cVar1) break;
              uVar4 = StorPortStallExecution(0x96);
              uVar17 = (int)uVar10 + 1;
              uVar10 = (ulonglong)uVar17;
            } while (uVar17 < 20000);
            uVar17 = 0;
            do {
              uVar5 = uVar14 & 0xffff;
              cVar1 = in(uVar16);
              uVar4 = CONCAT71((int7)(uVar4 >> 8),cVar1);
              if (-1 < cVar1) break;
              uVar4 = StorPortStallExecution(0x96);
              uVar17 = uVar17 + 1;
            } while (uVar17 < 20000);
          }
          else {
            lVar9 = *(longlong *)(param_1 + 0x58);
            do {
              cVar1 = *(char *)(((longlong)(int)(uVar12 >> 1 & 0x80000003) + 2) * 0x80 + lVar9 +
                               0x20);
              if (-1 < cVar1) goto LAB_0001ffe1;
              uVar4 = StorPortStallExecution(0x96);
              uVar17 = (int)uVar10 + 1;
              uVar10 = (ulonglong)uVar17;
            } while (uVar17 < 20000);
          }
          if (cVar1 < '\0') goto LAB_0001fff7;
        }
      }
      else {
        local_res18[0] =
             *(uint *)((longlong)(int)(uVar12 >> 1 & 0x80000003) * 0x80 + 0x128 +
                      *(longlong *)(param_1 + 0x58));
        uVar5 = (ulonglong)local_res18[0];
        bVar2 = (byte)local_res18[0];
LAB_0001feff:
        if ((bVar2 & 1) != 0) goto LAB_0001ff0a;
      }
LAB_0001ffe1:
      uVar14 = (ulonglong)(uVar12 + 1);
    } while( true );
  }
  puVar13 = (undefined2 *)(param_1 + 0xab8);
  for (lVar9 = 8; lVar9 != 0; lVar9 = lVar9 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
LAB_000200e2:
  uVar5 = BuildDeviceParameter(param_1,uVar5,param_3,param_4);
  uVar4 = CONCAT71((int7)(uVar5 >> 8),1);
LAB_000200ed:
  return uVar4;
LAB_0001fff7:
  iVar15 = iVar15 + 1;
  iVar7 = 2;
  if (3 < iVar15) goto code_r0x00020009;
  goto LAB_0001fd7f;
code_r0x00020009:
  uVar4 = uVar4 & 0xffffffffffffff00;
  goto LAB_000200ed;
}



===== HasLogicDevice @ 0002010c =====

undefined8 HasLogicDevice(longlong param_1)

{
  byte bVar1;
  ulonglong uVar2;
  
  bVar1 = 0;
  do {
    uVar2 = (ulonglong)bVar1;
    if (((*(char *)(param_1 + 0x958 + uVar2 * 0x28) != -1) &&
        (*(char *)(uVar2 + 0x3cec + param_1) == '\0')) &&
       (*(char *)(uVar2 + 0x3cf4 + param_1) == '\0')) break;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 8);
  return CONCAT71((int7)(uVar2 * 5 >> 8),bVar1 < 8);
}



===== InitHotPlugParams @ 00020148 =====

void InitHotPlugParams(longlong param_1)

{
  byte bVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  void *_Dst;
  undefined1 *puVar4;
  byte *pbVar5;
  longlong lVar6;
  bool bVar7;
  
  *(undefined1 *)(param_1 + 0x14b6) = 0;
  uVar2 = HasLogicDevice(param_1);
  *(char *)(param_1 + 0x14b7) = (char)uVar2;
  *(undefined1 *)(param_1 + 0x14b8) = 1;
  if (*(int *)(param_1 + 0x20c) != 0x33491106) {
    *(undefined1 *)(param_1 + 0x14b8) = 0;
  }
  bVar7 = *(char *)(param_1 + 0x14b8) != '\0';
  if (bVar7) {
    *(undefined1 *)(param_1 + 0x14b6) = 1;
  }
  pbVar5 = (byte *)(param_1 + 0xab8);
  puVar4 = (undefined1 *)(param_1 + 0x3cfc);
  _Dst = (void *)(param_1 + 0x3e3c);
  lVar6 = 8;
  *(bool *)(param_1 + 0x14b9) = bVar7;
  puVar3 = (undefined1 *)(param_1 + 0x34d4);
  do {
    puVar3[-8] = 0;
    *puVar3 = 0;
    *puVar4 = 0xff;
    memset(_Dst,0,0x68);
    bVar1 = *pbVar5;
    _Dst = (void *)((longlong)_Dst + 0x68);
    pbVar5 = pbVar5 + 2;
    puVar3[-0x201a] = bVar1 & 1;
    puVar4 = puVar4 + 0x28;
    lVar6 = lVar6 + -1;
    puVar3 = puVar3 + 1;
  } while (lVar6 != 0);
  return;
}



===== CommReset @ 0002021c =====

void CommReset(longlong param_1,uint param_2)

{
  ushort *puVar1;
  ushort uVar2;
  ulonglong uVar3;
  byte bVar4;
  ulonglong uVar5;
  int iVar6;
  undefined8 uVar7;
  short sVar8;
  longlong lVar9;
  char cVar10;
  uint uVar11;
  bool bVar12;
  undefined2 local_res8;
  uint local_res10 [2];
  
  uVar3 = *(ulonglong *)(param_1 + 0xc0 + (ulonglong)(param_2 >> 1) * 8);
  uVar2 = *(ushort *)(param_1 + 0xab8 + (ulonglong)param_2 * 2);
  if ((uVar2 & 0x2000) == 0) {
    if ((uVar2 & 0x8000) == 0) {
      iVar6 = 0;
      sVar8 = (short)*(undefined8 *)(param_1 + 0xa0 + (ulonglong)(param_2 >> 1) * 8) + 6;
      do {
        out(sVar8,0xa0);
        ReadWriteHostSControlRegister(param_1,param_2,'\x01',local_res10);
        uVar5 = (ulonglong)param_2;
        local_res10[0] = local_res10[0] & 0xfffff301 | 0x301;
        *(uint *)(param_1 + 0x120 + uVar5 * 4) = local_res10[0];
        ReadWriteHostSControlRegister(param_1,param_2,'\0',local_res10);
        lVar9 = 2;
        do {
          StorPortStallExecution(1000);
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        StorPortStallExecution(0);
        ReadWriteHostSControlRegister(param_1,param_2,'\x01',local_res10);
        local_res10[0] = local_res10[0] & 0xfffffff0;
        *(uint *)(param_1 + 0x120 + uVar5 * 4) = local_res10[0];
        ReadWriteHostSControlRegister(param_1,param_2,'\0',local_res10);
        lVar9 = 2;
        do {
          StorPortStallExecution(1000);
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        StorPortStallExecution(0);
        local_res10[0] = 0xffffffff;
        uVar7 = 0;
        ReadWriteHostSErrorRegister(param_1,param_2,'\0',local_res10);
        lVar9 = 10;
        do {
          StorPortStallExecution(1000);
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        StorPortStallExecution(0);
        *(undefined1 *)(uVar5 + 0xad8 + param_1) = 1;
        ReadWriteHostSStatusRegister(param_1,param_2,uVar7,local_res10);
        *(uint *)(param_1 + 0x100 + uVar5 * 4) = local_res10[0];
        if (((byte)local_res10[0] & 0xf) != 1) {
          if ((local_res10[0] & 1) == 0) break;
          cVar10 = ((byte)param_2 & 1 | 0xfa) << 4;
          out(sVar8,cVar10);
          local_res8 = (undefined2)uVar3;
          bVar4 = in(local_res8);
          if ((char)bVar4 < '\0') {
            out(local_res8,4);
            StorPortStallExecution(99,uVar3 & 0xffff);
            out(local_res8,0);
            StorPortStallExecution(0x14,uVar3 & 0xffff);
            out(sVar8,cVar10);
            uVar11 = 0;
            do {
              bVar4 = in(local_res8);
              if (-1 < (char)bVar4) break;
              StorPortStallExecution(0x96);
              uVar11 = uVar11 + 1;
            } while (uVar11 < 20000);
          }
          if ((-1 < (char)bVar4) && ((bVar4 & 0x20) == 0)) break;
        }
        if ((*(int *)(param_1 + 0x4870) == 0) && (*(char *)(param_1 + 0x2d) == '\0')) {
          bVar12 = iVar6 == 1;
        }
        else {
          bVar12 = iVar6 == 0;
        }
        if (bVar12) {
          puVar1 = (ushort *)(param_1 + 0xab8 + (ulonglong)param_2 * 2);
          *puVar1 = *puVar1 | 0x8000;
          break;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 3);
      if ((*(ushort *)(param_1 + 0xab8 + (ulonglong)param_2 * 2) & 0x8000) != 0) {
        *(undefined4 *)(param_1 + 0x4850 + (ulonglong)param_2 * 4) = 0;
        *(undefined1 *)(param_1 + 0x14b6) = 1;
        *(undefined1 *)(param_1 + 0x9c) = 1;
        StorPortNotification(6,param_1,AtapiCheckErrorDiskTimer,1000000,0xffffffff);
      }
    }
  }
  else {
    CommReset_for_ErrorDisk(param_1,param_2);
  }
  return;
}



===== DevInitializeEx @ 000204cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00020607) */

ulonglong DevInitializeEx(longlong param_1,uint param_2)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  undefined4 extraout_var_00;
  ulonglong uVar4;
  undefined4 extraout_var_01;
  undefined7 uVar5;
  undefined7 extraout_var;
  undefined1 *puVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  ushort uVar12;
  bool bVar13;
  undefined1 auStack_da2 [3362];
  undefined8 uStack_80;
  undefined1 auStack_78 [32];
  undefined1 local_58 [12];
  char local_4c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  uVar8 = (ulonglong)param_2;
  cVar2 = '\0';
  uVar12 = *(ushort *)(param_1 + 0xab8 + uVar8 * 2);
  uVar10 = (ulonglong)param_2;
  uVar4 = local_38;
  if ((uVar12 & 1) == 0) {
LAB_0002050a:
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  else {
    if ((uVar12 & 2) == 0) {
      uStack_80 = 0x20522;
      uVar3 = IdeMediaStatus(param_1,param_1,param_2);
      uVar4 = CONCAT44(extraout_var_00,uVar3);
      if (*(char *)(uVar8 + 0xb00 + param_1) != '\0') {
        uStack_80 = 0x2053a;
        uVar4 = SetMultiple(param_1,param_2);
        if ((char)uVar4 == '\0') goto LAB_0002050a;
      }
    }
    else {
      uVar4 = 0x100;
      if ((uVar12 & 0x100) == 0) {
        puVar6 = (undefined1 *)(param_1 + 0xd4a + uVar10 * 0xd4);
        lVar11 = 7;
        do {
          lVar9 = lVar11;
          puVar6[(longlong)(auStack_da2 + (uVar10 * -0xd4 - param_1))] = puVar6[1];
          uVar1 = *puVar6;
          puVar6 = puVar6 + 2;
          puVar6[(longlong)(auStack_da2 + (uVar10 * -0xd4 - param_1) + -1)] = uVar1;
          lVar11 = lVar9 + -1;
        } while (lVar11 != 0);
        uStack_80 = 0x205b2;
        iVar7 = AtapiStringCmp((longlong)local_58,(byte *)"CD-ROM  CDR",(int)lVar9 + 10);
        uVar4 = CONCAT44(extraout_var_01,iVar7);
        if ((iVar7 == 0) && (local_4c == 'C')) {
          uVar4 = 0x180;
          *(ushort *)(param_1 + 0xab8 + uVar8 * 2) = uVar12 | 0x180;
          *(undefined4 *)(param_1 + 0xa98 + uVar8 * 4) = 3;
        }
      }
    }
    uVar5 = (undefined7)(uVar4 >> 8);
    if ((*(byte *)(param_1 + 0xab8 + uVar8 * 2) & 2) != 0) {
      lVar11 = 0;
      lVar9 = 0;
      if ((*(byte *)(uVar8 + param_1 + 0x948) & 4) == 0) {
        lVar11 = *(longlong *)(param_1 + 0xc0 + (ulonglong)(param_2 >> 1) * 8);
      }
      else {
        lVar9 = ((longlong)(int)(param_2 >> 1 & 0x80000003) + 2) * 0x80 +
                *(longlong *)(param_1 + 0x58);
      }
      iVar7 = 10000;
      do {
        if ((lVar9 == 0) || ((*(byte *)(uVar8 + param_1 + 0x948) & 4) == 0)) {
          if (lVar11 != 0) {
            cVar2 = in((short)lVar11);
          }
        }
        else {
          cVar2 = *(char *)(lVar9 + 0x20);
        }
        if (-1 < cVar2) break;
        uStack_80 = 0x20667;
        StorPortStallExecution(100);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar7 = 5000;
      do {
        uStack_80 = 0x20678;
        StorPortStallExecution(100);
        bVar13 = iVar7 != 0;
        iVar7 = iVar7 + -1;
        uVar5 = extraout_var;
      } while (bVar13);
    }
    uVar4 = CONCAT71(uVar5,1);
  }
  return uVar4;
}



===== SetMultiple @ 000206a8 =====

ulonglong SetMultiple(longlong param_1,uint param_2)

{
  ushort *puVar1;
  short sVar2;
  char cVar3;
  byte bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint7 uVar8;
  longlong lVar7;
  short sVar9;
  char cVar10;
  uint uVar11;
  
  uVar5 = (ulonglong)param_2;
  if ((*(byte *)((ulonglong)param_2 + 0x948 + param_1) & 4) == 0) {
    sVar2 = (short)*(undefined8 *)(param_1 + 0xa0 + (ulonglong)(param_2 >> 1) * 8);
    cVar10 = ((byte)param_2 & 1 | 0xfa) << 4;
    uVar6 = (ulonglong)CONCAT31((uint3)(param_2 >> 9),cVar10);
    out(sVar2 + 6,cVar10);
    uVar11 = 0;
    sVar9 = sVar2 + 7;
    do {
      cVar3 = in(sVar9);
      uVar6 = CONCAT71((int7)(uVar6 >> 8),cVar3);
      if (-1 < cVar3) break;
      uVar6 = StorPortStallExecution(0x96);
      uVar11 = uVar11 + 1;
    } while (uVar11 < 20000);
    uVar11 = 0;
    do {
      cVar3 = in(sVar9);
      uVar6 = CONCAT71((int7)(uVar6 >> 8),cVar3);
      if (-1 < cVar3) break;
      uVar6 = StorPortStallExecution(0x96);
      uVar11 = uVar11 + 1;
    } while (uVar11 < 20000);
    uVar8 = (uint7)(uVar6 >> 8);
    if (cVar3 < '\0') {
      uVar5 = (ulonglong)uVar8 << 8;
    }
    else {
      out(sVar2 + 2,*(undefined1 *)(uVar5 + 0xb00 + param_1));
      out(sVar9,0xc6);
      lVar7 = CONCAT71(uVar8,cVar10);
      out(sVar2 + 6,cVar10);
      uVar11 = 0;
      do {
        bVar4 = in(sVar9);
        lVar7 = CONCAT71((int7)((ulonglong)lVar7 >> 8),bVar4);
        if (-1 < (char)bVar4) break;
        lVar7 = StorPortStallExecution(0x96);
        uVar11 = uVar11 + 1;
      } while (uVar11 < 20000);
      if ((bVar4 & 1) == 0) {
        puVar1 = (ushort *)(uVar5 * 0xd4 + 0xd8a + param_1);
        *puVar1 = *puVar1 | *(byte *)(uVar5 + 0xb00 + param_1) | 0x100;
      }
      else {
        in(sVar2 + 1);
        lVar7 = uVar5 * 0xd4;
        *(undefined1 *)(uVar5 + 0xb00 + param_1) = 0;
        *(undefined1 *)(lVar7 + 0xd8a + param_1) = 0;
      }
      uVar5 = CONCAT71((int7)((ulonglong)lVar7 >> 8),1);
    }
  }
  else {
    uVar5 = AhciSetMultiple(param_1,(ulonglong)param_2);
  }
  return uVar5;
}



===== SpecialSataResumeSetAllFeature @ 0002081c =====

void SpecialSataResumeSetAllFeature(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  byte bVar4;
  ushort *puVar5;
  ulonglong uVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  short sVar10;
  byte *pbVar11;
  ulonglong uVar12;
  uint *puVar13;
  byte local_res8;
  
  local_res8 = *(byte *)(param_1 + 0x953);
  uVar6 = param_3 & 0xffffffffffffff00;
  uVar12 = 0;
  bVar1 = false;
  do {
    if ((*(byte *)(param_1 + 0xab8 + uVar12 * 2) & 1) != 0) {
      uVar6 = CONCAT71((int7)(param_3 >> 8),1);
      break;
    }
    uVar3 = (int)uVar12 + 2;
    uVar12 = (ulonglong)uVar3;
  } while (uVar3 < 8);
  uVar3 = 1;
  do {
    if ((*(byte *)(param_1 + 0xab8 + (ulonglong)uVar3 * 2) & 1) != 0) {
      bVar1 = true;
      break;
    }
    uVar3 = uVar3 + 2;
  } while (uVar3 < 8);
  if (((char)uVar6 == '\0') && (local_res8 == 0)) {
    local_res8 = 1;
    *(undefined1 *)(param_1 + 0x953) = 1;
  }
  if (local_res8 < 8) {
    pbVar11 = (byte *)(param_1 + ((ulonglong)local_res8 + 0x55c) * 2);
    bVar7 = local_res8;
    do {
      if ((*pbVar11 & 1) != 0) {
        DisableDevIPM(param_1,(uint)bVar7);
      }
      bVar7 = bVar7 + 2;
      pbVar11 = pbVar11 + 4;
    } while (bVar7 < 8);
  }
  uVar3 = 0;
  if (local_res8 < 8) {
    uVar12 = (ulonglong)local_res8;
    pbVar11 = (byte *)(param_1 + 0xab8 + uVar12 * 2);
    bVar7 = local_res8;
    do {
      if ((*pbVar11 & 1) != 0) {
        sVar10 = (short)*(undefined8 *)(param_1 + 0xa0 + (uVar12 >> 1) * 8);
        out(sVar10 + 6,(bVar7 & 1 | 0xfa) << 4);
        sVar10 = sVar10 + 7;
        cVar2 = in(sVar10);
        if (cVar2 < '\0') {
          while ((uVar3 < 200000 && (cVar2 = in(sVar10), cVar2 < '\0'))) {
            StorPortStallExecution(10);
            uVar3 = uVar3 + 1;
          }
        }
      }
      bVar7 = bVar7 + 2;
      uVar12 = uVar12 + 2;
      pbVar11 = pbVar11 + 4;
    } while (bVar7 < 8);
  }
  if (local_res8 < 8) {
    uVar12 = (ulonglong)local_res8;
    pbVar11 = (byte *)(param_1 + 0xab8 + uVar12 * 2);
    puVar13 = (uint *)(param_1 + 0x39c + uVar12 * 0xb8);
    puVar5 = (ushort *)(param_1 + 0xd94 + uVar12 * 0xd4);
    bVar7 = local_res8;
    do {
      if ((*pbVar11 & 1) != 0) {
        *puVar13 = *puVar13 & 0xfffff0ff;
        bVar4 = (byte)(*puVar13 >> 0xc);
        if ((*puVar13 >> 0xc & 0xf) != 0) {
          bVar8 = bVar4 & 0xf;
          if (bVar8 == 4) {
            *puVar5 = *puVar5 | 2;
          }
          else if (bVar8 == 3) {
            *puVar5 = *puVar5 | 1;
          }
          StorPortStallExecution(99);
          SataResumeSetFeature(param_1,(ulonglong)bVar7,uVar6,bVar4 & 0xf | 8);
          uVar3 = *puVar13;
          *puVar13 = (uVar3 >> 4 ^ uVar3) & 0xf00 ^ uVar3 | 1;
        }
      }
      bVar7 = bVar7 + 2;
      pbVar11 = pbVar11 + 4;
      puVar5 = puVar5 + 0xd4;
      puVar13 = puVar13 + 0x5c;
    } while (bVar7 < 8);
  }
  uVar3 = 0;
  if (local_res8 < 8) {
    uVar12 = (ulonglong)local_res8;
    pbVar11 = (byte *)(param_1 + 0xab8 + uVar12 * 2);
    bVar7 = local_res8;
    do {
      if ((*pbVar11 & 1) != 0) {
        sVar10 = (short)*(undefined8 *)(param_1 + 0xa0 + (uVar12 >> 1) * 8);
        out(sVar10 + 6,(bVar7 & 1 | 0xfa) << 4);
        sVar10 = sVar10 + 7;
        cVar2 = in(sVar10);
        if (cVar2 < '\0') {
          while ((uVar3 < 200000 && (cVar2 = in(sVar10), cVar2 < '\0'))) {
            StorPortStallExecution(10);
            uVar3 = uVar3 + 1;
          }
        }
      }
      bVar7 = bVar7 + 2;
      uVar12 = uVar12 + 2;
      pbVar11 = pbVar11 + 4;
    } while (bVar7 < 8);
  }
  if (local_res8 < 8) {
    uVar12 = (ulonglong)local_res8;
    pbVar11 = (byte *)(param_1 + 0xac8 + uVar12 * 2);
    puVar13 = (uint *)(param_1 + 0x39c + uVar12 * 0xb8);
    puVar5 = (ushort *)(param_1 + 0xd92 + uVar12 * 0xd4);
    bVar7 = local_res8;
    do {
      if ((pbVar11[-0x10] & 1) != 0) {
        uVar3 = *puVar13;
        uVar9 = uVar3 & 0xf0f0fffb;
        *puVar13 = uVar9;
        if (uVar3 >> 0x1c == 0) {
          bVar4 = (byte)(uVar9 >> 0x14);
          if ((uVar9 >> 0x14 & 0xf) != 0) {
            *puVar5 = 1 << bVar4 + 8 | *puVar5 & 0xf8ff;
            StorPortStallExecution(99);
            SataResumeSetFeature(param_1,(ulonglong)bVar7,uVar6,bVar4 | 0x20);
            uVar3 = *puVar13;
            uVar3 = (uVar3 >> 4 ^ uVar3) & 0xf0000 ^ uVar3 | 4;
            goto LAB_00020c08;
          }
        }
        else {
          bVar4 = (byte)(uVar9 >> 0x1c);
          puVar5[0x19] = 1 << bVar4 + 8 | puVar5[0x19] & 0x80ff;
          StorPortStallExecution(99);
          SataResumeSetFeature(param_1,(ulonglong)bVar7,uVar6,bVar4 | 0x40);
          uVar3 = *puVar13;
          uVar3 = (uVar3 >> 4 ^ uVar3) & 0xf000000 ^ uVar3;
          *puVar13 = uVar3 | 4;
          if ((*pbVar11 & 4) != 0) {
            uVar3 = uVar3 & 0xfffffffb;
LAB_00020c08:
            *puVar13 = uVar3;
          }
        }
      }
      bVar7 = bVar7 + 2;
      pbVar11 = pbVar11 + 4;
      puVar5 = puVar5 + 0xd4;
      puVar13 = puVar13 + 0x5c;
    } while (bVar7 < 8);
  }
  uVar3 = 0;
  if (local_res8 < 8) {
    uVar6 = (ulonglong)local_res8;
    pbVar11 = (byte *)(param_1 + 0xab8 + uVar6 * 2);
    do {
      if ((*pbVar11 & 1) != 0) {
        sVar10 = (short)*(undefined8 *)(param_1 + 0xa0 + (uVar6 >> 1) * 8);
        out(sVar10 + 6,(local_res8 & 1 | 0xfa) << 4);
        sVar10 = sVar10 + 7;
        cVar2 = in(sVar10);
        if (cVar2 < '\0') {
          while ((uVar3 < 200000 && (cVar2 = in(sVar10), cVar2 < '\0'))) {
            StorPortStallExecution(10);
            uVar3 = uVar3 + 1;
          }
        }
      }
      local_res8 = local_res8 + 2;
      uVar6 = uVar6 + 2;
      pbVar11 = pbVar11 + 4;
    } while (local_res8 < 8);
  }
  if ((*(char *)(param_1 + 0x953) == '\0') && (bVar1)) {
    *(undefined1 *)(param_1 + 0x953) = 1;
    StorPortNotification(6,param_1,SpecialSataResumeSetAllFeature,1000000,0xffffffff);
  }
  else {
    *(undefined4 *)(param_1 + 0x4834) = 0;
    *(undefined1 *)(param_1 + 0x61) = 0;
    if ((*(char *)(param_1 + 0x14b6) == '\0') && (*(int *)(param_1 + 0x90) != 2)) {
      StorPortNotification(6,param_1,AtapiScsiTimer,15000000,0xffffffff);
    }
    StorPortResume(param_1);
  }
  return;
}



===== SataResumeSetAllFeature @ 00020d58 =====

void SataResumeSetAllFeature(longlong param_1)

{
  char cVar1;
  uint uVar2;
  ushort *puVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  byte *pbVar8;
  short sVar9;
  byte *pbVar10;
  uint *puVar11;
  uint *puVar12;
  ulonglong uVar13;
  ulonglong local_res8;
  
  uVar2 = 0;
  pbVar8 = (byte *)(param_1 + 0xab8);
  uVar5 = 0;
  pbVar10 = pbVar8;
  do {
    if ((*pbVar10 & 1) != 0) {
      DisableDevIPM(param_1,uVar5);
    }
    bVar4 = (char)uVar5 + 1;
    uVar5 = (uint)bVar4;
    pbVar10 = pbVar10 + 2;
  } while (bVar4 < 8);
  uVar5 = 0;
  bVar4 = 0;
  local_res8 = 0;
  pbVar10 = pbVar8;
  do {
    if ((*pbVar10 & 1) != 0) {
      sVar9 = (short)*(undefined8 *)(param_1 + 0xa0 + (local_res8 >> 1) * 8);
      out(sVar9 + 6,(bVar4 & 1 | 0xfa) << 4);
      sVar9 = sVar9 + 7;
      cVar1 = in(sVar9);
      uVar6 = uVar5;
      if (cVar1 < '\0') {
        while ((uVar6 < 200000 && (cVar1 = in(sVar9), cVar1 < '\0'))) {
          StorPortStallExecution(10);
          uVar5 = uVar5 + 1;
          uVar6 = uVar6 + 1;
        }
      }
    }
    local_res8 = local_res8 + 1;
    bVar4 = bVar4 + 1;
    pbVar10 = pbVar10 + 2;
  } while (bVar4 < 8);
  puVar12 = (uint *)(param_1 + 0x39c);
  uVar13 = 0;
  puVar3 = (ushort *)(param_1 + 0xd94);
  pbVar10 = pbVar8;
  puVar11 = puVar12;
  do {
    uVar7 = 2;
    if ((*pbVar10 & 1) != 0) {
      *puVar11 = *puVar11 & 0xfffff0ff;
      if ((*puVar11 >> 0xc & 0xf) != 0) {
        bVar4 = (byte)(*puVar11 >> 0xc) & 0xf;
        if (bVar4 == 4) {
          *puVar3 = *puVar3 | 2;
        }
        else if (bVar4 == 3) {
          *puVar3 = *puVar3 | 1;
        }
        StorPortStallExecution(99);
        SataResumeSetFeature(param_1,uVar13,uVar7,bVar4 | 8);
        uVar5 = *puVar11;
        *puVar11 = (uVar5 >> 4 ^ uVar5) & 0xf00 ^ uVar5 | 1;
      }
    }
    bVar4 = (char)uVar13 + 1;
    uVar13 = (ulonglong)bVar4;
    pbVar10 = pbVar10 + 2;
    puVar3 = puVar3 + 0x6a;
    puVar11 = puVar11 + 0x2e;
  } while (bVar4 < 8);
  uVar5 = 0;
  bVar4 = 0;
  local_res8 = 0;
  pbVar10 = (byte *)(param_1 + 0xab8);
  do {
    if ((*pbVar10 & 1) != 0) {
      sVar9 = (short)*(undefined8 *)(param_1 + 0xa0 + (local_res8 >> 1) * 8);
      out(sVar9 + 6,(bVar4 & 1 | 0xfa) << 4);
      sVar9 = sVar9 + 7;
      cVar1 = in(sVar9);
      uVar6 = uVar5;
      if (cVar1 < '\0') {
        while ((uVar6 < 200000 && (cVar1 = in(sVar9), cVar1 < '\0'))) {
          StorPortStallExecution(10);
          uVar5 = uVar5 + 1;
          uVar6 = uVar6 + 1;
        }
      }
    }
    local_res8 = local_res8 + 1;
    bVar4 = bVar4 + 1;
    pbVar10 = pbVar10 + 2;
  } while (bVar4 < 8);
  uVar13 = 0;
  pbVar10 = (byte *)(param_1 + 0xac8);
  puVar3 = (ushort *)(param_1 + 0xd92);
  do {
    if ((pbVar10[-0x10] & 1) != 0) {
      uVar5 = *puVar12;
      uVar6 = uVar5 & 0xf0f0fffb;
      *puVar12 = uVar6;
      if (uVar5 >> 0x1c == 0) {
        bVar4 = (byte)(uVar6 >> 0x14);
        if ((uVar6 >> 0x14 & 0xf) != 0) {
          *puVar3 = 1 << bVar4 + 8 | *puVar3 & 0xf8ff;
          StorPortStallExecution(99);
          SataResumeSetFeature(param_1,uVar13,local_res8,bVar4 | 0x20);
          uVar5 = *puVar12;
          uVar5 = (uVar5 >> 4 ^ uVar5) & 0xf0000 ^ uVar5 | 4;
          goto LAB_00021096;
        }
      }
      else {
        bVar4 = (byte)(uVar6 >> 0x1c);
        puVar3[0x19] = 1 << bVar4 + 8 | puVar3[0x19] & 0x80ff;
        StorPortStallExecution(99);
        SataResumeSetFeature(param_1,uVar13,local_res8,bVar4 | 0x40);
        uVar5 = *puVar12;
        uVar5 = (uVar5 >> 4 ^ uVar5) & 0xf000000 ^ uVar5;
        *puVar12 = uVar5 | 4;
        if ((*pbVar10 & 4) != 0) {
          uVar5 = uVar5 & 0xfffffffb;
LAB_00021096:
          *puVar12 = uVar5;
        }
      }
    }
    bVar4 = (char)uVar13 + 1;
    uVar13 = (ulonglong)bVar4;
    pbVar10 = pbVar10 + 2;
    puVar3 = puVar3 + 0x6a;
    puVar12 = puVar12 + 0x2e;
    if (7 < bVar4) {
      bVar4 = 0;
      uVar13 = 0;
      do {
        if ((*pbVar8 & 1) != 0) {
          sVar9 = (short)*(undefined8 *)(param_1 + 0xa0 + (uVar13 >> 1) * 8);
          out(sVar9 + 6,(bVar4 & 1 | 0xfa) << 4);
          sVar9 = sVar9 + 7;
          cVar1 = in(sVar9);
          uVar5 = uVar2;
          if (cVar1 < '\0') {
            while ((uVar5 < 200000 && (cVar1 = in(sVar9), cVar1 < '\0'))) {
              StorPortStallExecution(10);
              uVar2 = uVar2 + 1;
              uVar5 = uVar5 + 1;
            }
          }
        }
        bVar4 = bVar4 + 1;
        uVar13 = uVar13 + 1;
        pbVar8 = pbVar8 + 2;
      } while (bVar4 < 8);
      return;
    }
  } while( true );
}



===== SetAllFeature @ 0002114c =====

void SetAllFeature(longlong param_1,char param_2,undefined8 param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ushort *puVar4;
  uint *puVar5;
  byte bVar6;
  byte *pbVar7;
  
  uVar3 = 0;
  if ('\0' < param_2) {
    uVar3 = (int)param_2;
  }
  if ((int)uVar3 < 8) {
    lVar2 = (longlong)(int)uVar3;
    pbVar7 = (byte *)(param_1 + 0xac8 + lVar2 * 2);
    puVar5 = (uint *)(param_1 + 0x39c + lVar2 * 0xb8);
    puVar4 = (ushort *)(param_1 + 0xd94 + lVar2 * 0xd4);
    do {
      if (param_2 == -1) {
        if ((pbVar7[-0x10] & 1) != 0) goto LAB_000211da;
      }
      else {
        if (uVar3 != (int)param_2) {
          return;
        }
LAB_000211da:
        DisableDevIPM(param_1,uVar3);
        *puVar5 = *puVar5 & 0xf0f0f0fb;
        if ((*puVar5 >> 0xc & 0xf) != 0) {
          bVar6 = (byte)(*puVar5 >> 0xc) & 0xf;
          if (bVar6 == 4) {
            *puVar4 = *puVar4 | 2;
          }
          else if (bVar6 == 3) {
            *puVar4 = *puVar4 | 1;
          }
          StorPortStallExecution(99);
          SetFeature(param_1,(ulonglong)uVar3,param_3,bVar6 | 8);
          uVar1 = *puVar5;
          *puVar5 = (uVar1 >> 4 ^ uVar1) & 0xf00 ^ uVar1 | 1;
        }
        uVar1 = *puVar5;
        if (uVar1 >> 0x1c == 0) {
          if ((uVar1 >> 0x14 & 0xf) != 0) {
            bVar6 = (byte)(uVar1 >> 0x14) & 0xf;
            puVar4[-1] = 1 << bVar6 + 8 | puVar4[-1] & 0xf8ff;
            StorPortStallExecution(99);
            SetFeature(param_1,(ulonglong)uVar3,param_3,bVar6 | 0x20);
            uVar1 = *puVar5;
            uVar1 = (uVar1 >> 4 ^ uVar1) & 0xf0000 ^ uVar1 | 4;
            goto LAB_00021319;
          }
        }
        else {
          bVar6 = (byte)(uVar1 >> 0x1c);
          puVar4[0x18] = 1 << bVar6 + 8 | puVar4[0x18] & 0x80ff;
          StorPortStallExecution(99);
          SetFeature(param_1,(ulonglong)uVar3,param_3,bVar6 | 0x40);
          uVar1 = *puVar5;
          uVar1 = (uVar1 >> 4 ^ uVar1) & 0xf000000 ^ uVar1;
          *puVar5 = uVar1 | 4;
          if ((*pbVar7 & 4) != 0) {
            uVar1 = uVar1 & 0xfffffffb;
LAB_00021319:
            *puVar5 = uVar1;
          }
        }
      }
      uVar3 = uVar3 + 1;
      pbVar7 = pbVar7 + 2;
      puVar4 = puVar4 + 0x6a;
      puVar5 = puVar5 + 0x2e;
    } while ((int)uVar3 < 8);
  }
  return;
}



===== SataResumeSetFeature @ 0002135c =====

longlong SataResumeSetFeature
                   (longlong param_1,ulonglong param_2,undefined8 param_3,undefined1 param_4)

{
  short sVar1;
  char cVar2;
  ulonglong uVar3;
  uint7 uVar5;
  longlong lVar4;
  short sVar6;
  short sVar7;
  char cVar8;
  
  uVar3 = (param_2 & 0xffffffff) >> 1;
  sVar1 = (short)*(undefined8 *)(param_1 + 0xa0 + uVar3 * 8);
  sVar6 = sVar1 + 6;
  cVar8 = ((byte)param_2 & 1 | 0xfa) << 4;
  uVar5 = (uint7)((param_2 & 0xffffffff) >> 9);
  out(sVar6,cVar8);
  cVar2 = in((short)*(undefined8 *)(param_1 + 0xc0 + uVar3 * 8));
  if (cVar2 < '\0') {
    lVar4 = (ulonglong)uVar5 << 8;
  }
  else {
    sVar7 = sVar1 + 7;
    in(sVar7);
    out(sVar6,cVar8);
    out(sVar1 + 2,param_4);
    out(sVar1 + 1,3);
    out(sVar7,0xef);
    out(sVar6,cVar8);
    in(sVar7);
    lVar4 = CONCAT71(uVar5,1);
  }
  return lVar4;
}



===== SetFeature @ 000213e8 =====

/* WARNING: Removing unreachable block (ram,0x0002164e) */

undefined8 SetFeature(longlong param_1,ulonglong param_2,undefined8 param_3,byte param_4)

{
  int iVar1;
  short sVar2;
  char cVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  byte bVar8;
  undefined2 uVar9;
  short sVar10;
  int iVar11;
  char cVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  short sVar17;
  
  uVar5 = (param_2 & 0xffffffff) >> 1;
  uVar7 = param_2 & 0xff;
  uVar6 = *(undefined8 *)(param_1 + 0xc0 + uVar5 * 8);
  if ((*(byte *)((param_2 & 0xffffffff) + 0x948 + param_1) & 4) != 0) {
    uVar6 = AhciSetFeature(param_1,param_2 & 0xffffffff,3,param_4);
    return uVar6;
  }
  sVar2 = (short)*(undefined8 *)(param_1 + 0xa0 + uVar5 * 8);
  sVar17 = sVar2 + 6;
  cVar12 = ((byte)param_2 & 1 | 0xfa) << 4;
  out(sVar17,cVar12);
  uVar13 = 0;
  uVar14 = 0;
  do {
    uVar9 = (undefined2)uVar6;
    cVar3 = in(uVar9);
    if (-1 < cVar3) break;
    StorPortStallExecution(0x96);
    uVar14 = uVar14 + 1;
  } while (uVar14 < 20000);
  uVar14 = 0;
  do {
    cVar3 = in(uVar9);
    if (-1 < cVar3) break;
    StorPortStallExecution(0x96);
    uVar14 = uVar14 + 1;
  } while (uVar14 < 20000);
  if (cVar3 < '\0') {
    if ((*(byte *)(uVar7 + 0x948 + param_1) & 2) != 0) {
      uVar7 = CommReset(param_1,(uint)param_2 & 0xff);
      uVar14 = 0;
      do {
        cVar3 = in(uVar9);
        uVar7 = CONCAT71((int7)(uVar7 >> 8),cVar3);
        if (-1 < cVar3) break;
        uVar7 = StorPortStallExecution(0x96);
        uVar14 = uVar14 + 1;
      } while (uVar14 < 20000);
      uVar14 = 0;
      do {
        cVar3 = in(uVar9);
        uVar7 = CONCAT71((int7)(uVar7 >> 8),cVar3);
        if (-1 < cVar3) break;
        uVar7 = StorPortStallExecution(0x96);
        uVar14 = uVar14 + 1;
      } while (uVar14 < 20000);
    }
    if (cVar3 < '\0') {
      return uVar7 & 0xffffffffffffff00;
    }
  }
  sVar10 = sVar2 + 7;
  in(sVar10);
  out(sVar17,cVar12);
  out(sVar2 + 2,param_4);
  out(sVar2 + 1,3);
  out(sVar10,0xef);
  out(sVar17,cVar12);
  uVar14 = 0;
  do {
    cVar3 = in(uVar9);
    if (-1 < cVar3) break;
    StorPortStallExecution(0x96);
    uVar14 = uVar14 + 1;
  } while (uVar14 < 20000);
  bVar4 = in(sVar10);
  if (((bVar4 & 0x40) != 0) && ((*(byte *)((param_2 & 0xff) * 0xd4 + 0xdb8 + param_1) & 2) != 0)) {
    out(sVar17,cVar12);
    out(sVar10,0xf5);
    uVar14 = 0;
    do {
      cVar12 = in(uVar9);
      if (-1 < cVar12) break;
      StorPortStallExecution(0x96);
      uVar14 = uVar14 + 1;
    } while (uVar14 < 20000);
    in(sVar10);
  }
  uVar5 = param_2 & 0xff;
  if (*(char *)(uVar5 + 0x948 + param_1) != '\x01') goto LAB_00021792;
  iVar1 = *(int *)(param_1 + 0x20c);
  uVar14 = *(uint *)(param_1 + 0x21c);
  uVar5 = 0;
  if (((iVar1 != 0x31641106) && (iVar1 != 0x32491106)) && (iVar1 != 0x5811106)) goto LAB_00021792;
  iVar15 = 0;
  iVar16 = 0;
  iVar11 = 0;
  bVar4 = 0;
  if ((iVar1 == 0x31641106) || (iVar1 == 0x5811106)) {
    iVar15 = 0x50;
    iVar16 = 0x48;
LAB_000216ac:
    iVar11 = 3 - ((uint)param_2 & 3);
  }
  else if (iVar1 == 0x32491106) {
    iVar15 = 0xb0;
    iVar16 = 0xa8;
    goto LAB_000216ac;
  }
  uVar5 = 0;
  if ((param_4 & 0x40) == 0) {
    if ((param_4 & 8) == 0) {
      if ((param_4 & 0x20) == 0) goto LAB_00021792;
      uVar14 = (uVar14 & 0xffffff00) + iVar11 + iVar15;
      if (iVar1 == 0x32491106) {
        uVar6 = ReadConfigSpaceUCHAR(param_1,uVar14);
        bVar4 = (byte)uVar6 & 0x10 | 0xf;
      }
      else {
        uVar6 = ReadConfigSpaceUCHAR(param_1,uVar14);
        bVar4 = (byte)uVar6 & 0x30 | 0x8f;
      }
    }
    else {
      uVar14 = (uVar14 & 0xffffff00) + iVar11 + iVar16;
      bVar8 = param_4 & 7;
      if ((param_4 & 7) == 0) {
        bVar4 = 0xa8;
      }
      else if ((bVar8 == 1) || (bVar8 == 2)) {
        bVar4 = 0x65;
      }
      else if (bVar8 == 3) {
        bVar4 = 0x31;
      }
      else if (bVar8 == 4) {
        bVar4 = 0x20;
      }
    }
  }
  else {
    uVar14 = (uVar14 & 0xffffff00) + iVar11 + iVar15;
    uVar6 = ReadConfigSpaceUCHAR(param_1,uVar14);
    bVar8 = param_4 & 7;
    if ((param_4 & 7) == 0) {
      bVar4 = 0xee;
    }
    else if (bVar8 == 1) {
      bVar4 = 0xe8;
    }
    else if (bVar8 == 2) {
      bVar4 = 0xe6;
    }
    else if (bVar8 == 3) {
      bVar4 = 0xe4;
    }
    else if (bVar8 == 4) {
      bVar4 = 0xe2;
    }
    else if (bVar8 == 5) {
      bVar4 = 0xe1;
    }
    else if (bVar8 == 6) {
      bVar4 = 0xe0;
    }
    bVar4 = (byte)uVar6 & 0x10 | bVar4;
  }
  uVar5 = WriteConfigSpaceUCHAR(param_1,uVar14,bVar4);
LAB_00021792:
  do {
    cVar12 = in(uVar9);
    uVar5 = CONCAT71((int7)(uVar5 >> 8),cVar12);
    if (-1 < cVar12) break;
    uVar5 = StorPortStallExecution(0x96);
    uVar13 = uVar13 + 1;
  } while (uVar13 < 20000);
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== FindDevices @ 000217d0 =====

/* WARNING: Removing unreachable block (ram,0x0002188d) */
/* WARNING: Removing unreachable block (ram,0x00021d8c) */

ulonglong FindDevices(longlong param_1)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  ushort *puVar6;
  ulonglong uVar7;
  undefined4 extraout_var;
  ulonglong uVar8;
  byte bVar9;
  undefined2 uVar10;
  short sVar11;
  undefined2 uVar12;
  longlong lVar13;
  short *psVar14;
  uint uVar15;
  undefined8 uVar16;
  undefined7 uVar17;
  byte bVar18;
  longlong lVar19;
  short sVar20;
  uint uVar21;
  ulonglong uVar22;
  byte local_res10 [8];
  char local_res18;
  uint local_res20 [2];
  ulonglong local_68;
  undefined8 local_60;
  ushort *local_58;
  
  local_58 = (ushort *)(param_1 + 0xab8);
  local_68 = 0;
  uVar16 = 0;
  local_60 = 0;
  local_res10[0] = 0;
  local_res18 = '\0';
  lVar19 = 0;
  lVar13 = 8;
  puVar6 = local_58;
  do {
    uVar1 = *puVar6;
    if ((uVar1 & 0x2000) == 0) {
      if ((uVar1 & 0x8000) != 0) goto LAB_00021848;
      *puVar6 = 0;
    }
    else if ((uVar1 & 0x8000) == 0) {
      *puVar6 = 0x2000;
    }
    else {
LAB_00021848:
      *puVar6 = 0x8000;
    }
    puVar6[8] = 0;
    puVar6 = puVar6 + 1;
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  uVar22 = 0;
  uVar8 = 0;
  do {
    uVar15 = 0;
    uVar21 = (uint)uVar22;
    bVar9 = *(byte *)(uVar22 + 0x948 + param_1);
    if (bVar9 != 0) {
      bVar18 = bVar9 & 4;
      bVar2 = (byte)uVar22;
      if (bVar18 == 0) {
        local_68 = *(ulonglong *)(param_1 + 0xa0 + (uVar22 >> 1) * 8);
        uVar16 = *(undefined8 *)(param_1 + 0xc0 + (uVar22 >> 1) * 8);
        out((short)local_68 + 6,(bVar2 & 1 | 0xfa) << 4);
        cVar4 = in((short)uVar16);
        local_60 = uVar16;
      }
      else {
        lVar19 = ((longlong)(int)((uint)(uVar22 >> 1) & 3) + 2) * 0x80 +
                 *(longlong *)(param_1 + 0x58);
        cVar4 = *(char *)(lVar19 + 0x20);
      }
      if (cVar4 != -1) {
        sVar20 = (short)local_68;
        uVar10 = (undefined2)local_60;
        if (bVar18 == 0) {
          if ((bVar9 & 2) == 0) {
LAB_000219fa:
            if ((*(int *)(param_1 + 0x4870) == 0) && (*(char *)(param_1 + 0x2d) == '\0')) {
              do {
                cVar4 = in(uVar10);
                if (-1 < cVar4) break;
                StorPortStallExecution(0x96);
                uVar15 = uVar15 + 1;
              } while (uVar15 < 200000);
            }
            else {
              do {
                cVar4 = in(uVar10);
                if (-1 < cVar4) break;
                StorPortStallExecution(0x96);
                uVar15 = uVar15 + 1;
              } while (uVar15 < 7000);
            }
            if (cVar4 < '\0') {
              uVar7 = 0;
              if ((bVar9 & 2) != 0) {
                uVar5 = ReadWriteHostSErrorRegister(param_1,uVar21,'\x01',(undefined4 *)local_res10)
                ;
                uVar7 = CONCAT44(extraout_var,uVar5);
              }
LAB_00021d47:
              return uVar7 & 0xffffffffffffff00;
            }
            cVar3 = (bVar2 & 1 | 0xfa) * '\x10';
            out(sVar20 + 6,cVar3);
            cVar4 = in(sVar20 + 6);
            if (cVar4 == cVar3) {
              sVar11 = sVar20 + 2;
              out(sVar11,0x55);
              cVar4 = in(sVar11);
              if (cVar4 == 'U') {
                out(sVar11,0xaa);
                cVar4 = in(sVar11);
                if (cVar4 == -0x56) goto LAB_00021aad;
              }
            }
            goto LAB_00021bdd;
          }
          ReadWriteHostSStatusRegister(param_1,uVar21,uVar8,local_res20);
          *(uint *)(param_1 + 0x100 + uVar22 * 4) = local_res20[0];
          if (((((byte)local_res20[0] & 0xf) == 3) &&
              (uVar1 = *(ushort *)(param_1 + 0xab8 + uVar22 * 2), (uVar1 & 0x2000) == 0)) &&
             ((uVar1 & 0x8000) == 0)) goto LAB_000219fa;
LAB_00021d06:
          uVar8 = CONCAT71((int7)(uVar8 >> 8),local_res10[0]);
        }
        else if ((*(uint *)(lVar19 + 0x28) & 1) != 0) {
          uVar1 = *(ushort *)(param_1 + 0xab8 + uVar22 * 2);
          if (((uVar1 & 0x2000) == 0) && ((uVar1 & 0x8000) == 0)) {
            if ((*(int *)(param_1 + 0x4870) == 0) && (*(char *)(param_1 + 0x2d) == '\0')) {
              do {
                cVar4 = *(char *)(lVar19 + 0x20);
                if (-1 < cVar4) goto LAB_0002198c;
                uVar7 = StorPortStallExecution(0x96);
                uVar15 = uVar15 + 1;
              } while (uVar15 < 200000);
            }
            else {
              do {
                cVar4 = *(char *)(lVar19 + 0x20);
                if (-1 < cVar4) goto LAB_0002198c;
                uVar7 = StorPortStallExecution(0x96);
                uVar15 = uVar15 + 1;
              } while (uVar15 < 7000);
            }
            if (cVar4 < '\0') goto LAB_00021d47;
LAB_0002198c:
            *(uint *)(lVar19 + 0x18) = *(uint *)(lVar19 + 0x18) | 0x11;
LAB_00021aad:
            if (bVar18 == 0) {
              uVar15 = (int)local_68 + 6;
              cVar4 = (bVar2 & 1 | 0xfa) << 4;
              uVar12 = (undefined2)uVar15;
              out(uVar12,cVar4);
              StorPortStallExecution(500,uVar15 & 0xffff);
              out(sVar20 + 7,8);
              lVar13 = 10;
              do {
                StorPortStallExecution(1000);
                lVar13 = lVar13 + -1;
              } while (lVar13 != 0);
              StorPortStallExecution(0);
              out(uVar12,cVar4);
              uVar15 = 0;
              do {
                cVar4 = in(uVar10);
                if (-1 < cVar4) break;
                StorPortStallExecution(0x96);
                uVar15 = uVar15 + 1;
              } while (uVar15 < 20000);
              StorPortStallExecution(500);
            }
            else {
              AhciDevReset(param_1,uVar21);
            }
            if (bVar18 == 0) {
              cVar4 = in(sVar20 + 4);
              cVar3 = in(sVar20 + 5);
              uVar8 = local_68;
            }
            else {
              cVar4 = (char)((uint)*(undefined4 *)(lVar19 + 0x24) >> 0x10);
              cVar3 = (char)((uint)*(undefined4 *)(lVar19 + 0x24) >> 0x18);
            }
            uVar17 = (undefined7)(uVar8 >> 8);
            if (((cVar4 == '\x14') && (cVar3 == -0x15)) || ((cVar4 == 'i' && (cVar3 == -0x6a)))) {
              if (*(char *)(param_1 + 0x8c) == '\0') {
                uVar8 = CONCAT71(uVar17,0xa1);
                lVar13 = IssueIdentify(param_1,uVar21,uVar8);
                if ((char)lVar13 != '\0') {
                  puVar6 = (ushort *)(param_1 + 0xab8 + uVar22 * 2);
                  *puVar6 = *puVar6 | 3;
                  uVar8 = CONCAT71((int7)(uVar8 >> 8),1);
                  local_res10[0] = 1;
                  if (bVar18 == 0) {
                    bVar9 = in(uVar10);
                    uVar16 = local_60;
                    if ((bVar9 & 1) != 0) {
                      uVar15 = (int)local_68 + 6;
                      cVar4 = (bVar2 & 1 | 0xfa) << 4;
                      uVar12 = (undefined2)uVar15;
                      out(uVar12,cVar4);
                      StorPortStallExecution(500,uVar15 & 0xffff);
                      out(sVar20 + 7,8);
                      lVar13 = 10;
                      do {
                        StorPortStallExecution(1000);
                        lVar13 = lVar13 + -1;
                      } while (lVar13 != 0);
                      StorPortStallExecution(0);
                      out(uVar12,cVar4);
                      uVar15 = 0;
                      do {
                        cVar4 = in(uVar10);
                        if (-1 < cVar4) break;
                        StorPortStallExecution(0x96);
                        uVar15 = uVar15 + 1;
                      } while (uVar15 < 20000);
                      StorPortStallExecution(500);
                      uVar8 = CONCAT71((int7)(uVar8 >> 8),1);
                    }
                  }
                  else {
                    uVar16 = local_60;
                    if ((*(byte *)(lVar19 + 0x20) & 1) != 0) {
                      AhciDevReset(param_1,uVar21);
                      goto LAB_00021bdd;
                    }
                  }
                  goto LAB_00021d13;
                }
                puVar6 = (ushort *)(param_1 + 0xab8 + uVar22 * 2);
                *puVar6 = *puVar6 & 0xfffe;
              }
LAB_00021bdd:
              uVar8 = CONCAT71((int7)(uVar8 >> 8),local_res10[0]);
              uVar16 = local_60;
            }
            else {
              uVar8 = CONCAT71(uVar17,0xec);
              lVar13 = IssueIdentify(param_1,uVar21,uVar8);
              uVar16 = local_60;
              if ((char)lVar13 == '\0') goto LAB_00021d06;
              puVar6 = (ushort *)(param_1 + 0xab8 + uVar22 * 2);
              *puVar6 = *puVar6 | 1;
              *(undefined1 *)(uVar22 + 0xad8 + param_1) = 0;
              puVar6 = (ushort *)(param_1 + 0xab8 + uVar22 * 2);
              *puVar6 = *puVar6 & 0xfffd;
              uVar8 = CONCAT71((int7)(uVar8 >> 8),1);
              local_res10[0] = 1;
            }
          }
        }
      }
    }
LAB_00021d13:
    uVar7 = 0;
    uVar22 = (ulonglong)(uVar21 + 1);
  } while (uVar21 + 1 < 8);
  psVar14 = (short *)(param_1 + 0xd1a);
  uVar22 = uVar7;
  do {
    uVar10 = (undefined2)uVar16;
    uVar15 = 0;
    bVar9 = *(byte *)(uVar7 + 0x948 + param_1);
    uVar21 = (uint)uVar22;
    if (bVar9 != 0) {
      bVar9 = bVar9 & 4;
      if (bVar9 == 0) {
        local_68 = *(ulonglong *)(param_1 + 0xa0 + (uVar7 >> 1) * 8);
        local_60 = *(undefined8 *)(param_1 + 0xc0 + (uVar7 >> 1) * 8);
        uVar10 = (undefined2)local_60;
      }
      else {
        lVar19 = ((longlong)(int)(uVar21 >> 1 & 0x80000003) + 2) * 0x80 +
                 *(longlong *)(param_1 + 0x58);
      }
      if ((((*local_58 & 1) != 0) && ((*local_58 & 2) == 0)) && ((char)uVar8 != '\0')) {
        if (psVar14[3] == 0x35) {
          if (*psVar14 == 7) {
            psVar14[3] = 0x34;
            *psVar14 = 0xe;
          }
          if ((psVar14[3] == 0x35) && (*psVar14 == 0xf)) {
            psVar14[3] = 0x34;
            *psVar14 = 0xf;
          }
        }
        if ((psVar14[3] == 0x36) && (*psVar14 == 7)) {
          psVar14[3] = 0x3f;
          *psVar14 = 0x10;
          local_res18 = '\x01';
        }
        if (local_res18 == '\0') {
          if (bVar9 == 0) {
            do {
              cVar4 = in(uVar10);
              if (-1 < cVar4) break;
              StorPortStallExecution(0x96);
              uVar15 = uVar15 + 1;
            } while (uVar15 < 20000);
            cVar4 = ((byte)uVar22 & 1 | 0xfa) << 4;
            sVar20 = (short)local_68 + 6;
            local_res20[0] = CONCAT31(local_res20[0]._1_3_,cVar4);
            out(sVar20,cVar4);
            bVar9 = in(uVar10);
            if (((bVar9 & 0x40) == 0) || ((bVar9 & 0x20) != 0)) goto LAB_0002200e;
            if ((bVar9 & 1) != 0) {
              out(uVar10,4);
              lVar13 = 500;
              do {
                StorPortStallExecution(1000);
                lVar13 = lVar13 + -1;
              } while (lVar13 != 0);
              StorPortStallExecution(0);
              out((undefined2)local_60,0);
              out(sVar20,(undefined1)local_res20[0]);
              uVar15 = 0;
              do {
                cVar4 = in((undefined2)local_60);
                uVar10 = (undefined2)local_60;
                if (-1 < cVar4) break;
                StorPortStallExecution(0x96);
                uVar15 = uVar15 + 1;
              } while (uVar15 < 20000);
            }
            uVar15 = 0;
            do {
              cVar4 = in(uVar10);
              if (-1 < cVar4) break;
              StorPortStallExecution(0x96);
              uVar15 = uVar15 + 1;
            } while (uVar15 < 20000);
          }
          else {
            do {
              bVar9 = *(byte *)(lVar19 + 0x20);
              if (-1 < (char)bVar9) break;
              StorPortStallExecution(0x96);
              uVar15 = uVar15 + 1;
            } while (uVar15 < 20000);
            if (((bVar9 & 0x40) == 0) || ((bVar9 & 0x20) != 0)) {
LAB_0002200e:
              uVar8 = (ulonglong)local_res10[0];
              goto LAB_00022021;
            }
            if ((bVar9 & 1) != 0) {
              AhciSoftwareReset(param_1,uVar21 >> 1);
              uVar15 = 0;
              do {
                if (-1 < *(char *)(lVar19 + 0x20)) break;
                StorPortStallExecution(0x96);
                uVar15 = uVar15 + 1;
              } while (uVar15 < 20000);
            }
            uVar15 = 0;
            do {
              if (-1 < *(char *)(lVar19 + 0x20)) break;
              StorPortStallExecution(0x96);
              uVar15 = uVar15 + 1;
            } while (uVar15 < 20000);
          }
          uVar8 = SetDriveParameters(param_1,(byte)uVar22);
          if ((char)uVar8 == '\0') {
            uVar8 = (ulonglong)local_res10[0];
            *local_58 = 0;
          }
          else {
            uVar8 = 1;
            local_res10[0] = 1;
          }
        }
      }
    }
LAB_00022021:
    local_58 = local_58 + 1;
    uVar22 = (ulonglong)(uVar21 + 1);
    uVar7 = uVar7 + 1;
    psVar14 = psVar14 + 0x6a;
    uVar16 = local_60;
    if (7 < uVar21 + 1) {
      return CONCAT71((int7)((ulonglong)local_58 >> 8),(char)uVar8);
    }
  } while( true );
}



===== LegacyIssueIdentifyCmd @ 00022064 =====

longlong LegacyIssueIdentifyCmd
                   (longlong param_1,uint param_2,undefined8 param_3,undefined2 *param_4)

{
  int iVar1;
  short sVar2;
  bool bVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  ulonglong uVar8;
  uint7 uVar9;
  uint7 extraout_var;
  uint7 extraout_var_00;
  uint7 extraout_var_01;
  uint7 extraout_var_02;
  uint7 extraout_var_03;
  undefined7 uVar10;
  undefined7 extraout_var_04;
  undefined8 uVar11;
  uint uVar12;
  uint uVar13;
  undefined2 uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  longlong lVar18;
  longlong lVar19;
  undefined2 uVar20;
  uint uVar21;
  char cVar22;
  
  cVar7 = (char)param_3;
  uVar11 = *(undefined8 *)(param_1 + 0xa0 + (ulonglong)(param_2 >> 1) * 8);
  uVar8 = *(ulonglong *)(param_1 + 0xc0 + (ulonglong)(param_2 >> 1) * 8);
  iVar1 = (int)uVar11;
  uVar21 = iVar1 + 6;
  uVar20 = (undefined2)uVar21;
  cVar22 = ((byte)param_2 & 1 | 0xfa) << 4;
  out(uVar20,cVar22);
  uVar15 = 0;
  uVar12 = 0;
  do {
    uVar14 = (undefined2)uVar8;
    bVar4 = in(uVar14);
    if (-1 < (char)bVar4) break;
    StorPortStallExecution(0x96);
    uVar12 = uVar12 + 1;
  } while (uVar12 < 20000);
  sVar2 = (short)uVar11;
  if ((cVar7 != -0x14) || ((bVar4 & 0xfc) == 0x50)) {
LAB_000221cb:
    lVar18 = 2;
    out(sVar2 + 5,2);
    uVar9 = 0;
    out(sVar2 + 4,0);
    uVar13 = iVar1 + 7;
    bVar3 = false;
    uVar12 = uVar21;
    uVar17 = uVar13;
    do {
      uVar16 = 0;
      do {
        cVar5 = in(uVar14);
        if (-1 < cVar5) break;
        StorPortStallExecution(0x96);
        uVar16 = uVar16 + 1;
        uVar9 = extraout_var_00;
      } while (uVar16 < 20000);
      out((short)uVar17,cVar7);
      out((short)uVar12,cVar22);
      uVar12 = 0;
      do {
        uVar17 = 0;
        do {
          bVar4 = in(uVar14);
          if ((char)bVar4 < '\0') {
            uVar11 = 100;
          }
          else {
            if ((bVar4 & 8) != 0) goto LAB_000222c5;
            uVar11 = 200;
          }
          StorPortStallExecution(uVar11);
          uVar17 = uVar17 + 1;
          uVar9 = extraout_var_01;
        } while (uVar17 < 1000);
        if ((bVar4 & 8) != 0) {
LAB_000222c5:
          bVar4 = in((short)uVar13);
          break;
        }
        if (cVar7 == -0x14) {
          cVar5 = in(sVar2 + 4);
          cVar6 = in(sVar2 + 5);
          if (((cVar5 == '\x14') && (cVar6 == -0x15)) || ((cVar5 == 'i' && (cVar6 == -0x6a))))
          goto LAB_0002219a;
        }
        uVar17 = 0;
        do {
          bVar4 = in(uVar14);
          if (-1 < (char)bVar4) break;
          StorPortStallExecution(0x96);
          uVar17 = uVar17 + 1;
          uVar9 = extraout_var_02;
        } while (uVar17 < 20000);
        uVar12 = uVar12 + 1;
      } while (uVar12 < 4);
      if ((uVar12 != 4) || (bVar3)) goto LAB_0002239d;
      if ((*(byte *)((ulonglong)param_2 + 0x948 + param_1) & 1) == 0) {
        uVar11 = CommReset(param_1,param_2);
      }
      else {
        out(uVar20,cVar22);
        StorPortStallExecution(500,uVar21 & 0xffff);
        out((short)uVar13,8);
        lVar19 = 10;
        do {
          StorPortStallExecution(1000);
          lVar19 = lVar19 + -1;
        } while (lVar19 != 0);
        StorPortStallExecution(0);
        out(uVar20,cVar22);
        uVar12 = 0;
        do {
          cVar5 = in(uVar14);
          if (-1 < cVar5) break;
          StorPortStallExecution(0x96);
          uVar12 = uVar12 + 1;
        } while (uVar12 < 20000);
        uVar11 = StorPortStallExecution(500);
      }
      uVar12 = uVar21 & 0xffff;
      uVar17 = uVar13 & 0xffff;
      uVar9 = (uint7)((ulonglong)uVar11 >> 8);
      out(uVar20,cVar22);
      in(uVar14);
      bVar3 = true;
    } while( true );
  }
  out(uVar14,4);
  StorPortStallExecution(99,uVar8 & 0xffff);
  out(uVar14,0);
  lVar18 = 2000;
  do {
    StorPortStallExecution(1000);
    lVar18 = lVar18 + -1;
  } while (lVar18 != 0);
  StorPortStallExecution(0);
  uVar12 = param_2 - 1;
  if ((param_2 & 1) == 0) {
    uVar12 = param_2 + 1;
  }
  uVar8 = (ulonglong)uVar12;
  if ((*(byte *)(param_1 + 0xab8 + uVar8 * 2) & 1) != 0) {
    uVar8 = SetAllFeature(param_1,(char)uVar12,param_3);
  }
  uVar9 = (uint7)(uVar8 >> 8);
  out(uVar20,cVar22);
  uVar12 = 0;
  do {
    cVar5 = in(uVar14);
    if (-1 < cVar5) break;
    StorPortStallExecution(0x96);
    uVar12 = uVar12 + 1;
    uVar9 = extraout_var;
  } while (uVar12 < 20000);
  bVar4 = in(uVar14);
  if ((bVar4 & 0xfd) == 0x50) {
    cVar5 = in(sVar2 + 4);
    cVar6 = in(sVar2 + 5);
    if (((cVar5 != '\x14') || (cVar6 != -0x15)) && ((cVar5 != 'i' || (cVar6 != -0x6a))))
    goto LAB_000221cb;
  }
  goto LAB_0002219a;
LAB_0002239d:
  if ((cVar7 != -0x14) || ((bVar4 & 1) == 0)) {
    uVar12 = 0;
    do {
      bVar4 = in(uVar14);
      if (-1 < (char)bVar4) break;
      StorPortStallExecution(0x96);
      uVar12 = uVar12 + 1;
      uVar9 = extraout_var_03;
    } while (uVar12 < 20000);
    if ((bVar4 & 8) != 0) {
      lVar19 = 0x100;
      while (lVar19 != 0) {
        lVar19 = lVar19 + -1;
        uVar20 = in(sVar2);
        *param_4 = uVar20;
        param_4 = param_4 + 1;
      }
      uVar12 = 0;
      do {
        cVar7 = in(uVar14);
        if (-1 < cVar7) break;
        StorPortStallExecution(0x96);
        uVar12 = uVar12 + 1;
      } while (uVar12 < 20000);
      do {
        bVar4 = in(uVar14);
        if ((bVar4 & 8) == 0) break;
        in(sVar2);
        uVar15 = uVar15 + 1;
      } while (uVar15 < 0x10000);
      uVar10 = (undefined7)((ulonglong)param_1 >> 8);
      if ((*(byte *)((ulonglong)param_2 + 0x948 + param_1) & 2) != 0) {
        do {
          StorPortStallExecution(1000);
          lVar18 = lVar18 + -1;
        } while (lVar18 != 0);
        StorPortStallExecution(0);
        uVar10 = extraout_var_04;
      }
      return CONCAT71(uVar10,1);
    }
  }
LAB_0002219a:
  return (ulonglong)uVar9 << 8;
}



===== ProcessIdentifyData @ 0002246c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ProcessIdentifyData(longlong param_1,uint param_2,char param_3,void *param_4)

{
  ushort *puVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  char *pcVar5;
  uint uVar6;
  ushort *puVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint uVar11;
  undefined1 auStack_88 [32];
  char local_68 [24];
  undefined4 local_50;
  undefined2 local_4c;
  undefined1 local_4a;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_88;
  uVar10 = (ulonglong)param_2;
  if ((*(byte *)((longlong)param_4 + 0xfe) & 1) != 0) {
    puVar7 = (ushort *)(param_1 + 0xab8 + uVar10 * 2);
    *puVar7 = *puVar7 | 0x10;
  }
  bVar2 = *(byte *)((longlong)param_4 + 0x5e);
  uVar11 = 0;
  if (bVar2 != 0) {
    bVar3 = *(byte *)(uVar10 + 0x948 + param_1);
    *(byte *)(uVar10 + 0xb00 + param_1) = bVar2;
    if ((((bVar3 & 2) != 0) || ((bVar3 & 4) != 0)) && (0x10 < bVar2)) {
      *(undefined1 *)(uVar10 + 0xb00 + param_1) = 0x10;
    }
  }
  lVar8 = uVar10 * 0xd4;
  memcpy((void *)(param_1 + 0xd14 + lVar8),param_4,0xd4);
  uVar4 = *(ushort *)((longlong)param_4 + 0x98);
  puVar7 = (ushort *)(param_1 + 0xd14 + lVar8);
  puVar7[0x67] = uVar4;
  puVar7[0x4b] = *(ushort *)((longlong)param_4 + 0x96);
  puVar7[0x68] = *(ushort *)((longlong)param_4 + 0x9c);
  if ((ushort)(uVar4 - 1) < 0xfffe) {
    puVar1 = (ushort *)(param_1 + 0xab8 + uVar10 * 2);
    *puVar1 = *puVar1 | 0x200;
    if ((param_3 == -0x14) && ((puVar7[0x67] & 0x100) != 0)) {
      *(ushort *)(param_1 + 0xab8 + uVar10 * 2) = *(ushort *)(param_1 + 0xab8 + uVar10 * 2) | 0x400;
    }
  }
  lVar9 = 1;
  *(undefined2 *)(lVar8 + 0xdb8 + param_1) = *(undefined2 *)((longlong)param_4 + 0xa4);
  *(undefined2 *)(lVar8 + 0xde0 + param_1) = *(undefined2 *)((longlong)param_4 + 0x6a);
  *(undefined2 *)(lVar8 + 0xd94 + param_1) = *(undefined2 *)((longlong)param_4 + 0x80);
  *(undefined2 *)(lVar8 + 0xd8a + param_1) = *(undefined2 *)((longlong)param_4 + 0x76);
  *(undefined2 *)(lVar8 + 0xd92 + param_1) = *(undefined2 *)((longlong)param_4 + 0x7e);
  *(undefined2 *)(lVar8 + 0xdc4 + param_1) = *(undefined2 *)((longlong)param_4 + 0xb0);
  if ((*(ushort *)((longlong)param_4 + 0x62) & 0x200) == 0) {
    *(undefined4 *)(lVar8 + 0xddc + param_1) = 0;
    *(uint *)(lVar8 + 0xd8c + param_1) =
         (uint)*(ushort *)(lVar8 + 0xd20 + param_1) * (uint)*(ushort *)(lVar8 + 0xd1a + param_1) *
         (uint)*(ushort *)(lVar8 + 0xd16 + param_1);
  }
  else {
    *(undefined4 *)(lVar8 + 0xd8c + param_1) = *(undefined4 *)((longlong)param_4 + 0x78);
  }
  *(undefined2 *)(lVar8 + 0xdb4 + param_1) = *(undefined2 *)((longlong)param_4 + 0xa0);
  *(undefined2 *)(lVar8 + 0xdb6 + param_1) = *(undefined2 *)((longlong)param_4 + 0xa2);
  *(undefined2 *)(lVar8 + 0xdbc + param_1) = *(undefined2 *)((longlong)param_4 + 0xa8);
  uVar4 = *(ushort *)((longlong)param_4 + 0xa6);
  *(ushort *)(lVar8 + 0xdba + param_1) = uVar4;
  if ((uVar4 & 0x400) == 0) {
    *(undefined4 *)(lVar8 + 0xddc + param_1) = 0;
  }
  else {
    *(undefined4 *)(lVar8 + 0xd8c + param_1) = *(undefined4 *)((longlong)param_4 + 200);
    *(undefined4 *)(lVar8 + 0xddc + param_1) = *(undefined4 *)((longlong)param_4 + 0xcc);
  }
  if (*(int *)(lVar8 + 0xddc + param_1) != 0) {
    *(undefined1 *)(uVar10 * 0xb8 + 0x430 + param_1) = 1;
  }
  if (((*puVar7 & 0x20) != 0) && (param_3 != -0x14)) {
    puVar1 = (ushort *)(param_1 + 0xab8 + uVar10 * 2);
    *puVar1 = *puVar1 | 8;
  }
  if (((*puVar7 & 0xf00) == 0x100) && (param_3 != -0x14)) {
    *(undefined2 *)(param_1 + 0xab8 + uVar10 * 2) = 0x2004;
  }
  BuildDiskModeParameter(param_1,param_2,1);
  if (param_3 != -0x14) {
    uVar6 = 0;
    builtin_strncpy(local_68,"ASSMNU GDCR-R/ WRDVI EWS",0x18);
    lVar8 = param_1 + 0xd4a + lVar8;
    pcVar5 = local_68;
    local_50 = 0x35322d32;
    local_4c = 0x4620;
    local_4a = 0;
    do {
      if (pcVar5[lVar8 - (longlong)local_68] != *pcVar5) goto LAB_000227a9;
      uVar6 = uVar6 + 1;
      pcVar5 = pcVar5 + 1;
    } while (uVar6 < 0x1e);
    lVar9 = 2000;
    do {
      StorPortStallExecution(1000);
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    StorPortStallExecution(0);
LAB_000227a9:
    uVar6 = 0;
    builtin_strncpy(local_68,"SM I    C -DWRM -S3804 S",0x18);
    pcVar5 = local_68;
    local_50 = CONCAT13(local_50._3_1_,0x2020);
    lVar9 = lVar8 - (longlong)local_68;
    do {
      if (pcVar5[lVar9] != *pcVar5) goto LAB_00022810;
      uVar6 = uVar6 + 1;
      pcVar5 = pcVar5 + 1;
    } while (uVar6 < 0x1a);
    puVar7 = (ushort *)(param_1 + 0xab8 + uVar10 * 2);
    *puVar7 = *puVar7 | 0x800;
LAB_00022810:
    pcVar5 = local_68;
    builtin_strncpy(local_68,"SASU    RC-W25231AT-    ",0x18);
    local_50 = CONCAT13(local_50._3_1_,0x2020);
    do {
      if (pcVar5[lVar8 - (longlong)local_68] != *pcVar5) goto LAB_0002286c;
      uVar11 = uVar11 + 1;
      pcVar5 = pcVar5 + 1;
    } while (uVar11 < 0x1a);
    puVar7 = (ushort *)(param_1 + 0xac8 + uVar10 * 2);
    *puVar7 = *puVar7 | 1;
  }
LAB_0002286c:
  SetAllFeature(param_1,(char)param_2,lVar9);
  return;
}



===== IssueIdentify @ 0002289c =====

longlong IssueIdentify(longlong param_1,uint param_2,undefined8 param_3)

{
  undefined2 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  puVar1 = (undefined2 *)(param_1 + 0xb14);
  if ((*(byte *)((ulonglong)param_2 + 0x948 + param_1) & 4) == 0) {
    lVar2 = LegacyIssueIdentifyCmd(param_1,param_2,param_3,puVar1);
  }
  else {
    lVar2 = AhciIssueIdentifyCmd(param_1,(ulonglong)param_2,(char)param_3,puVar1);
  }
  if ((char)lVar2 != '\0') {
    uVar3 = ProcessIdentifyData(param_1,param_2,(char)param_3,puVar1);
    lVar2 = CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  return lVar2;
}



===== BuildDiskModeParameter @ 00022908 =====

/* WARNING: Removing unreachable block (ram,0x000229d1) */

void BuildDiskModeParameter(longlong param_1,uint param_2,undefined8 param_3)

{
  uint *puVar1;
  ushort *puVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  uint local_res10 [2];
  
  uVar9 = (ulonglong)param_2;
  lVar10 = uVar9 * 0xd4;
  lVar11 = uVar9 * 0xb8;
  if ((*(byte *)(param_1 + 0x948 + uVar9) & 4) != 0) {
    puVar1 = (uint *)(lVar11 + 0x39c + param_1);
    *puVar1 = *puVar1 | 8;
  }
  bVar6 = *(byte *)(param_1 + 0x948 + uVar9);
  if (((bVar6 & 2) == 0) && ((bVar6 & 4) == 0)) {
    puVar1 = (uint *)(lVar11 + 0x3a0 + param_1);
    *puVar1 = *puVar1 & 0xffffff00;
  }
  else {
    if ((*(ushort *)(param_1 + 0xab8 + uVar9 * 2) & 0x200) == 0) {
      *(uint *)(lVar11 + 0x3a0 + param_1) = *(uint *)(lVar11 + 0x3a0 + param_1) & 0xffffff11 | 0x11;
    }
    else {
      if ((*(ushort *)(lVar10 + 0xde2 + param_1) & 4) == 0) {
        uVar8 = *(uint *)(lVar11 + 0x3a0 + param_1) & 0xffffff1f | 0x10;
      }
      else {
        uVar8 = *(uint *)(lVar11 + 0x3a0 + param_1) & 0xffffff2f | 0x20;
      }
      *(uint *)(lVar11 + 0x3a0 + param_1) = uVar8;
      if ((*(byte *)(param_1 + 0x948 + uVar9) & 4) == 0) {
        ReadWriteHostSStatusRegister(param_1,param_2,param_3,local_res10);
      }
      else {
        local_res10[0] =
             *(uint *)((longlong)(int)(param_2 >> 1 & 0x80000003) * 0x80 + 0x128 +
                      *(longlong *)(param_1 + 0x58));
      }
      puVar1 = (uint *)(lVar11 + 0x3a0 + param_1);
      *puVar1 = *puVar1 ^ (local_res10[0] >> 4 ^ *(uint *)(lVar11 + 0x3a0 + param_1)) & 0xf;
    }
    bVar6 = (byte)*(undefined4 *)(lVar11 + 0x3a0 + param_1);
    if ((bVar6 & 0xf) == 1 && (bVar6 & 0xf0) == 0x20) {
      puVar2 = (ushort *)(param_1 + 0xab8 + uVar9 * 2);
      *puVar2 = *puVar2 | 0x1000;
    }
  }
  if ((*(ushort *)(lVar10 + 0xd76 + param_1) & 0x200) == 0) {
    puVar1 = (uint *)(lVar11 + 0x39c + param_1);
    *puVar1 = *puVar1 & 0xffffffef;
  }
  else {
    puVar1 = (uint *)(lVar11 + 0x39c + param_1);
    *puVar1 = *puVar1 | 0x10;
  }
  if (((*(byte *)(lVar10 + 0xde0 + param_1) & 2) != 0) &&
     (uVar3 = *(ushort *)(lVar10 + 0xd94 + param_1), (uVar3 & 3) != 0)) {
    puVar1 = (uint *)(lVar11 + 0x39c + param_1);
    *puVar1 = *puVar1 | 1;
    uVar8 = *(uint *)(lVar11 + 0x39c + param_1);
    if ((uVar3 & 2) == 0) {
      if ((uVar3 & 1) == 0) goto LAB_00022ace;
      uVar8 = uVar8 & 0xffff33ff | 0x3300;
    }
    else {
      uVar8 = uVar8 & 0xffff44ff | 0x4400;
    }
    *(uint *)(lVar11 + 0x39c + param_1) = uVar8;
  }
LAB_00022ace:
  if (*(char *)(lVar10 + 0xd72 + param_1) != '\0') {
    puVar2 = (ushort *)(lVar10 + 0xd8a + param_1);
    *puVar2 = *puVar2 | 0x100;
  }
  if ((*(ushort *)(lVar10 + 0xd8a + param_1) & 0x100) != 0) {
    puVar1 = (uint *)(lVar11 + 0x39c + param_1);
    *puVar1 = *puVar1 | 2;
  }
  uVar3 = *(ushort *)(lVar10 + 0xd92 + param_1);
  if ((uVar3 & 0x700) != 0) {
    puVar1 = (uint *)(lVar11 + 0x39c + param_1);
    *puVar1 = *puVar1 | 4;
    uVar8 = *(uint *)(lVar11 + 0x39c + param_1);
    if ((uVar3 & 0x400) == 0) {
      if ((uVar3 & 0x200) == 0) {
        if ((uVar3 & 0x100) == 0) goto LAB_00022b55;
        uVar8 = uVar8 & 0xfff0ffff;
      }
      else {
        uVar8 = uVar8 & 0xfff1ffff | 0x10000;
      }
    }
    else {
      uVar8 = uVar8 & 0xfff2ffff | 0x20000;
    }
    *(uint *)(lVar11 + 0x39c + param_1) = uVar8;
  }
LAB_00022b55:
  uVar3 = *(ushort *)(lVar10 + 0xd92 + param_1);
  if ((uVar3 & 7) != 0) {
    if ((uVar3 & 4) == 0) {
      if ((uVar3 & 2) == 0) {
        if ((uVar3 & 1) != 0) {
          puVar1 = (uint *)(lVar11 + 0x39c + param_1);
          *puVar1 = *puVar1 & 0xff0fffff;
        }
        goto LAB_00022ba5;
      }
      uVar8 = *(uint *)(lVar11 + 0x39c + param_1) & 0xff1fffff | 0x100000;
    }
    else {
      uVar8 = *(uint *)(lVar11 + 0x39c + param_1) & 0xff2fffff | 0x200000;
    }
    *(uint *)(lVar11 + 0x39c + param_1) = uVar8;
  }
LAB_00022ba5:
  if ((*(byte *)(lVar10 + 0xde0 + param_1) & 4) != 0) {
    uVar3 = *(ushort *)(lVar10 + 0xdc4 + param_1);
    if ((uVar3 & 0x7f00) != 0) {
      puVar1 = (uint *)(lVar11 + 0x39c + param_1);
      *puVar1 = *puVar1 | 4;
      uVar8 = *(uint *)(lVar11 + 0x39c + param_1);
      if ((uVar3 & 0x4000) == 0) {
        if ((uVar3 & 0x2000) == 0) {
          if ((uVar3 & 0x1000) == 0) {
            if ((uVar3 & 0x800) == 0) {
              if ((uVar3 & 0x400) == 0) {
                if ((uVar3 & 0x200) == 0) {
                  if ((uVar3 & 0x100) == 0) goto LAB_00022c6b;
                  uVar8 = uVar8 & 0xf0ffffff;
                }
                else {
                  uVar8 = uVar8 & 0xf1ffffff | 0x1000000;
                }
              }
              else {
                uVar8 = uVar8 & 0xf2ffffff | 0x2000000;
              }
            }
            else {
              uVar8 = uVar8 & 0xf3ffffff | 0x3000000;
            }
          }
          else {
            uVar8 = uVar8 & 0xf4ffffff | 0x4000000;
          }
        }
        else {
          uVar8 = uVar8 & 0xf5ffffff | 0x5000000;
        }
      }
      else {
        uVar8 = uVar8 & 0xf6ffffff | 0x6000000;
      }
      *(uint *)(lVar11 + 0x39c + param_1) = uVar8;
    }
LAB_00022c6b:
    uVar3 = *(ushort *)(lVar10 + 0xdc4 + param_1);
    if ((uVar3 & 0x7f) != 0) {
      if ((uVar3 & 0x40) == 0) {
        if ((uVar3 & 0x20) == 0) {
          if ((uVar3 & 0x10) == 0) {
            if ((uVar3 & 8) == 0) {
              if ((uVar3 & 4) == 0) {
                if ((uVar3 & 2) == 0) {
                  if ((uVar3 & 1) != 0) {
                    puVar1 = (uint *)(lVar11 + 0x39c + param_1);
                    *puVar1 = *puVar1 & 0xfffffff;
                  }
                  goto LAB_00022d0a;
                }
                uVar8 = *(uint *)(lVar11 + 0x39c + param_1) & 0xfffffff | 0x10000000;
              }
              else {
                uVar8 = *(uint *)(lVar11 + 0x39c + param_1) & 0xfffffff | 0x20000000;
              }
            }
            else {
              uVar8 = *(uint *)(lVar11 + 0x39c + param_1) & 0xfffffff | 0x30000000;
            }
          }
          else {
            uVar8 = *(uint *)(lVar11 + 0x39c + param_1) & 0xfffffff | 0x40000000;
          }
        }
        else {
          uVar8 = *(uint *)(lVar11 + 0x39c + param_1) & 0xfffffff | 0x50000000;
        }
      }
      else {
        uVar8 = *(uint *)(lVar11 + 0x39c + param_1) & 0xfffffff | 0x60000000;
      }
      *(uint *)(lVar11 + 0x39c + param_1) = uVar8;
    }
  }
LAB_00022d0a:
  if ((*(ushort *)(lVar10 + 0xdba + param_1) & 0x400) != 0) {
    puVar1 = (uint *)(lVar11 + 0x39c + param_1);
    *puVar1 = *puVar1 | 0x20;
  }
  iVar4 = *(int *)(param_1 + 0x20c);
  iVar5 = *(int *)(param_1 + 0x21c);
  if (((iVar4 == 0x31491106) || (iVar4 == 0x5911106)) || (iVar4 == 0x73721106)) goto LAB_00022de0;
  if (iVar4 == 0x32491106) {
    cVar7 = *(char *)(param_1 + 0x948 + uVar9);
    if (cVar7 != '\x01') {
LAB_00022ddc:
      if (cVar7 != '\x02') {
        return;
      }
      goto LAB_00022de0;
    }
    uVar8 = (iVar5 - (param_2 & 3)) + 0xb3;
  }
  else {
    if (iVar4 != 0x31641106) {
      if (iVar4 != 0x5811106) {
        return;
      }
      cVar7 = *(char *)(param_1 + 0x948 + uVar9);
      if (cVar7 == '\x01') {
        uVar9 = ReadConfigSpaceUCHAR(param_1,(iVar5 - param_2) + 0x53);
        if ((uVar9 & 0x10) != 0) goto LAB_00022de0;
        goto LAB_00022dac;
      }
      goto LAB_00022ddc;
    }
    uVar8 = (iVar5 - param_2) + 0x53;
  }
  uVar9 = ReadConfigSpaceUCHAR(param_1,uVar8);
  if ((uVar9 & 0x10) != 0) {
LAB_00022dac:
    uVar8 = *(uint *)(lVar11 + 0x39c + param_1);
    *(uint *)(lVar11 + 0x39c + param_1) = uVar8 & 0xffffff7f | 0x40;
    if ((uVar8 & 0xf0000000) < 0x20000001) {
      return;
    }
    *(uint *)(lVar11 + 0x39c + param_1) = uVar8 & 0xfffff7f | 0x20000040;
    return;
  }
LAB_00022de0:
  *(uint *)(lVar11 + 0x39c + param_1) = *(uint *)(lVar11 + 0x39c + param_1) & 0xffffffbf | 0x80;
  return;
}



===== SetDriveParameters @ 00022e0c =====

ulonglong SetDriveParameters(longlong param_1,byte param_2)

{
  undefined8 uVar1;
  short sVar2;
  byte bVar3;
  char cVar4;
  undefined8 in_RAX;
  uint7 uVar6;
  ulonglong uVar5;
  uint7 extraout_var;
  uint7 extraout_var_00;
  uint7 extraout_var_01;
  byte bVar7;
  uint uVar8;
  undefined2 uVar9;
  longlong lVar10;
  uint uVar11;
  
  uVar6 = (uint7)((ulonglong)in_RAX >> 8);
  lVar10 = (ulonglong)param_2 * 0xd4;
  if ((*(byte *)((ulonglong)param_2 + 0x948 + param_1) & 4) == 0) {
    uVar1 = *(undefined8 *)(param_1 + 0xc0 + (ulonglong)(param_2 >> 1) * 8);
    bVar7 = (param_2 & 1 | 0xfa) << 4;
    sVar2 = (short)*(undefined8 *)(param_1 + 0xa0 + (ulonglong)(param_2 >> 1) * 8);
    out(sVar2 + 6,*(char *)(lVar10 + 0xd1a + param_1) - 1U | bVar7);
    uVar8 = 0;
    uVar11 = 0;
    do {
      uVar9 = (undefined2)uVar1;
      bVar3 = in(uVar9);
      if ((bVar3 & 0x50) != 0) break;
      StorPortStallExecution(0x96);
      uVar11 = uVar11 + 1;
      uVar6 = extraout_var;
    } while (uVar11 < 20000);
    if ((char)bVar3 < '\0') {
LAB_00022f4f:
      uVar5 = (ulonglong)uVar6 << 8;
    }
    else {
      out(sVar2 + 2,*(undefined1 *)(lVar10 + 0xd20 + param_1));
      out(sVar2 + 7,0x91);
      out(sVar2 + 6,*(char *)(lVar10 + 0xd1a + param_1) - 1U | bVar7);
      uVar11 = 0;
      do {
        bVar7 = in(uVar9);
        if ((bVar7 & 1) != 0) {
          in(sVar2 + 1);
          goto LAB_00022f4f;
        }
        uVar6 = 0;
        if ((bVar7 & 0xfd) == 0x50) break;
        StorPortStallExecution(100);
        uVar11 = uVar11 + 1;
        uVar6 = extraout_var_00;
      } while (uVar11 < 30000);
      do {
        cVar4 = in(uVar9);
        if (-1 < cVar4) break;
        StorPortStallExecution(0x96);
        uVar8 = uVar8 + 1;
        uVar6 = extraout_var_01;
      } while (uVar8 < 20000);
      uVar5 = CONCAT71(uVar6,1);
    }
  }
  else {
    uVar5 = AhciSetDriveParameters(param_1,param_2);
  }
  return uVar5;
}



===== Inquiry @ 00022f70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 Inquiry(longlong param_1,longlong param_2)

{
  char cVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  uint uVar10;
  size_t sVar12;
  size_t sVar11;
  byte *pbVar13;
  longlong lVar14;
  char *pcVar15;
  ulonglong uVar16;
  undefined8 *puVar17;
  char *pcVar18;
  longlong lVar19;
  longlong lVar20;
  char *pcVar21;
  char *pcVar22;
  byte bVar23;
  size_t sVar24;
  size_t _Size;
  int iVar25;
  byte *_Dst;
  undefined1 auStack_1e8 [32];
  byte local_1c8;
  uint local_1c4;
  char *local_1c0;
  int local_1b8;
  longlong local_1b0;
  char *local_1a8;
  longlong local_1a0;
  uint local_198;
  char *local_190;
  undefined8 *local_188;
  ulonglong local_180;
  char *local_178;
  char local_170 [40];
  char local_148;
  undefined8 auStack_147 [2];
  undefined4 uStack_137;
  undefined2 uStack_133;
  undefined1 auStack_131 [233];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1e8;
  lVar14 = *(longlong *)(param_2 + 0xf0);
  local_1c8 = 3;
  bVar23 = *(byte *)(param_1 + 0x958 + (ulonglong)*(byte *)(lVar14 + 6) * 0x28);
  local_180 = (ulonglong)bVar23;
  local_1c0 = "VIA RAID";
  pcVar15 = (char *)0x0;
  pcVar18 = (char *)0x0;
  local_190 = "Invalid!";
  iVar25 = *(int *)(param_1 + 0x208);
  pcVar21 = (char *)0x0;
  local_1a8 = (char *)0x0;
  pcVar22 = (char *)0x0;
  if (iVar25 == 0x32491106) {
    pcVar15 = s_SATA_RAID_0_00036010;
    pcVar18 = s_SATA_RAID_1_00036026;
    local_1a8 = s_SATA_RAID_0_1_0003603c;
    pcVar22 = s_SATA_RAID_JBOD_00036052;
    pcVar21 = s_SATA_RAID_5_00036068;
  }
  else if (iVar25 == 0x31641106) {
    pcVar15 = s_SATA_RAID_0_0003607e;
    pcVar18 = s_SATA_RAID_1_00036094;
    local_1a8 = s_SATA_RAID_0_1_000360aa;
    pcVar22 = s_SATA_RAID_JBOD_000360c0;
    pcVar21 = s_SATA_RAID_5_000360d6;
  }
  else if (((iVar25 == 0x31491106) || (iVar25 == 0x5911106)) || (iVar25 == 0x73721106)) {
    pcVar15 = s_SATA_RAID_0_000360ec;
    pcVar18 = s_SATA_RAID_1_00036102;
    local_1a8 = s_SATA_RAID_0_1_00036118;
    pcVar22 = s_SATA_RAID_JBOD_0003612e;
    pcVar21 = s_SATA_RAID_5_00036144;
  }
  else if (iVar25 == 0x5811106) {
    pcVar15 = s_SATA_RAID_0_0003615a;
    pcVar18 = s_SATA_RAID_1_00036170;
    local_1a8 = s_SATA_RAID_0_1_00036186;
    pcVar22 = s_SATA_RAID_JBOD_0003619c;
    pcVar21 = s_SATA_RAID_5_000361b2;
  }
  else if (iVar25 == 0x33491106) {
    pcVar15 = s_SATA_RAID_0_00036236;
    pcVar18 = s_SATA_RAID_1_0003624c;
    local_1a8 = s_SATA_RAID_0_1_00036262;
    pcVar22 = s_SATA_RAID_JBOD_00036278;
    pcVar21 = s_SATA_RAID_5_0003628e;
  }
  if ((bVar23 == 0xff) || (*(char *)(lVar14 + 7) != '\0')) {
LAB_000238c1:
    *(undefined4 *)(param_2 + 0xf8) = 10;
    uVar6 = 10;
    goto LAB_000238cf;
  }
  if ((((*(byte *)(lVar14 + 0x49) & 1) == 0) && (*(char *)(lVar14 + 0x4a) != '\0')) ||
     ((*(byte *)(lVar14 + 0x49) & 2) != 0)) goto LAB_00023111;
  pbVar13 = *(byte **)(lVar14 + 0x18);
  uVar16 = (ulonglong)*(byte *)(lVar14 + 6);
  local_1c4 = local_1c4 & 0xffffff00;
  uVar10 = *(uint *)(lVar14 + 0x10);
  local_1b0 = param_1 + 0xd14 + local_180 * 0xd4;
  local_198 = 0x68;
  if (uVar10 < 0x68) {
    local_198 = uVar10;
  }
  local_1b8 = 0;
  _Dst = (byte *)(param_1 + 0x3e3c + uVar16 * 0x68);
  local_178 = (char *)(param_1 + 0x3cfc + uVar16 * 0x28);
  local_188 = (undefined8 *)(param_1 + (uVar16 * 5 + 299) * 8);
  if (uVar10 != 0) {
    uVar10 = 0;
    do {
      uVar7 = (ulonglong)uVar10;
      uVar10 = uVar10 + 1;
      *(undefined1 *)(uVar7 + *(longlong *)(lVar14 + 0x18)) = 0;
    } while (uVar10 < *(uint *)(lVar14 + 0x10));
  }
  local_1a0 = local_180 * 0xb8;
  if (*(int *)(local_1a0 + 0x38c + param_1) != 0) {
    if (*(char *)(local_1a0 + 0x390 + param_1) == '\0') {
      local_1c0 = local_1a8;
    }
    else {
      pcVar15 = "VIA RAID 0";
      pcVar18 = "VIA RAID 1";
      pcVar22 = "VIA RAID JBOD";
      pcVar21 = "VIA RAID 5";
      local_1c0 = "VIA RAID 0+1";
    }
    local_1b8 = *(int *)(local_1a0 + 0x3a8 + param_1);
    if (local_1b8 == 0) {
      local_1c0 = pcVar15;
    }
    else if (local_1b8 == 1) {
      local_1c0 = pcVar18;
    }
    else if (local_1b8 == 5) {
      local_1c0 = pcVar21;
    }
    else if (local_1b8 == 8) {
      local_1c0 = pcVar22;
    }
    else if (local_1b8 == 9) {
    }
    else {
      local_1c0 = "VIA RAID";
      DbgPrint("inquiry: unknown RAID TYPE x%x\n",local_1b8);
    }
    if (*(char *)(local_1a0 + 0x390 + param_1) == '\0') {
      local_1c8 = 3;
      local_190 = "VIA";
    }
    else {
      local_1c8 = 8;
      local_190 = "Invalid!";
    }
  }
  uVar7 = 0;
  bVar23 = 0;
  if ((*(char *)(uVar16 + 0x3cec + param_1) != '\0') ||
     (*(char *)(uVar16 + 0x3cf4 + param_1) != '\0')) goto LAB_000238c1;
  if (*(char *)(uVar16 + 0x34d4 + param_1) == '\0') {
    if ((*local_178 != -1) && (bVar2 = *(byte *)((longlong)local_188 + 2), local_178[2] == bVar2)) {
      if (bVar2 != 0) {
        do {
          bVar23 = (byte)uVar7;
          if (*(int *)((longlong)local_188 + uVar7 * 4 + 4) != *(int *)(local_178 + uVar7 * 4 + 4))
          break;
          bVar23 = bVar23 + 1;
          uVar7 = (ulonglong)bVar23;
        } while (bVar23 < bVar2);
      }
      uVar4 = (char)local_1c4;
      if (bVar2 <= bVar23) {
        uVar4 = 1;
      }
      local_1c4 = CONCAT31(local_1c4._1_3_,uVar4);
    }
  }
  else {
    cVar1 = *local_178;
    *(undefined1 *)(uVar16 + 0x34d4 + param_1) = 0;
    local_1c4 = local_1c4 & 0xff;
    if (cVar1 != -1) {
      local_1c4 = 1;
    }
  }
  *(undefined8 *)local_178 = *local_188;
  *(undefined8 *)(local_178 + 8) = local_188[1];
  *(undefined8 *)(local_178 + 0x10) = local_188[2];
  *(undefined8 *)(local_178 + 0x18) = local_188[3];
  *(undefined8 *)(local_178 + 0x20) = local_188[4];
  if ((char)local_1c4 == '\0') {
    if ((*(byte *)(lVar14 + 0x49) & 1) != 0) goto LAB_000233a7;
    *pbVar13 = *pbVar13 & 0xe0;
    if (0x24 < *(uint *)(lVar14 + 0x10)) {
      *(undefined4 *)(lVar14 + 0x10) = 0x24;
    }
    cVar1 = *(char *)(lVar14 + 0x10);
    pbVar13[3] = pbVar13[3] | 0x10;
    pbVar13[4] = cVar1 - 5;
    if ((*(byte *)(param_1 + 0xab8 + local_180 * 2) & 0x10) != 0) {
      pbVar13[1] = pbVar13[1] | 0x80;
    }
    pbVar9 = pbVar13 + 8;
    pbVar9[0] = 0x20;
    pbVar9[1] = 0x20;
    pbVar9[2] = 0x20;
    pbVar9[3] = 0x20;
    pbVar9[4] = 0x20;
    pbVar9[5] = 0x20;
    pbVar9[6] = 0x20;
    pbVar9[7] = 0x20;
    pbVar13[0x10] = 0x20;
    pbVar13[0x11] = 0x20;
    pbVar13[0x12] = 0x20;
    pbVar13[0x13] = 0x20;
    pbVar13[0x14] = 0x20;
    pbVar13[0x15] = 0x20;
    pbVar13[0x16] = 0x20;
    pbVar13[0x17] = 0x20;
    pbVar13[0x18] = 0x20;
    pbVar13[0x19] = 0x20;
    pbVar13[0x1a] = 0x20;
    pbVar13[0x1b] = 0x20;
    pbVar13[0x1c] = 0x20;
    pbVar13[0x1d] = 0x20;
    pbVar13[0x1e] = 0x20;
    pbVar13[0x1f] = 0x20;
    pbVar13[0x20] = 0x20;
    pbVar13[0x21] = 0x20;
    pbVar13[0x22] = 0x20;
    pbVar13[0x23] = 0x20;
    pbVar13[2] = 5;
    pbVar13[3] = pbVar13[3] & 0xf2 | 2;
    if (*(int *)(local_1a0 + 0x38c + param_1) == 0) {
      if (*(int *)(local_1a0 + 0x388 + param_1) != 0) {
        pbVar9 = pbVar13 + 9;
        lVar20 = 4;
        do {
          pbVar9[-1] = pbVar9[(local_1b0 - (longlong)pbVar13) + 0x2e];
          *pbVar9 = pbVar9[(local_1b0 - (longlong)pbVar13) + 0x2d];
          pbVar9 = pbVar9 + 2;
          lVar20 = lVar20 + -1;
        } while (lVar20 != 0);
        lVar20 = 8;
        puVar8 = (undefined1 *)(local_1b0 + 0x3e);
        do {
          puVar8[(longlong)(pbVar13 + (-0x2e - local_1b0))] = puVar8[1];
          uVar4 = *puVar8;
          puVar8 = puVar8 + 2;
          puVar8[(longlong)(pbVar13 + (-0x2f - local_1b0))] = uVar4;
          lVar20 = lVar20 + -1;
        } while (lVar20 != 0);
        goto LAB_00023808;
      }
    }
    else {
      memcpy(pbVar9,local_190,(ulonglong)local_1c8);
      lVar20 = -1;
      do {
        lVar20 = lVar20 + 1;
      } while (local_1c0[lVar20] != '\0');
      bVar23 = 0x16;
      if ((byte)lVar20 < 0x16) {
        bVar23 = (byte)lVar20;
      }
      if (local_1c0 != (char *)0x0) {
        memcpy(pbVar13 + 0x10,local_1c0,(ulonglong)bVar23);
      }
LAB_00023808:
      if (*(int *)(local_1a0 + 0x388 + param_1) != 0) {
        pbVar9 = pbVar13 + 0x21;
        lVar20 = 2;
        do {
          pbVar9[-1] = pbVar9[(local_1b0 - (longlong)pbVar13) + 0xe];
          *pbVar9 = pbVar9[(local_1b0 - (longlong)pbVar13) + 0xd];
          pbVar9 = pbVar9 + 2;
          lVar20 = lVar20 + -1;
        } while (lVar20 != 0);
      }
    }
    memset(_Dst,0,0x68);
    if (_Dst != pbVar13) {
      memcpy(_Dst,pbVar13,(ulonglong)local_198);
    }
    bVar23 = *(byte *)(lVar14 + 6);
    _Dst[0x24] = 0x49;
    _Dst[0x25] = 0x56;
    _Dst[0x26] = 0x20;
    _Dst[0x27] = 0x41;
    srand((int)param_1 + ((uint)bVar23 * 5 + 299) * 8 & 0xff);
    pbVar13 = _Dst + 0x28;
    lVar14 = 0xf;
    do {
      iVar25 = rand();
      iVar25 = iVar25 * 0x1a;
      *pbVar13 = (((char)(iVar25 / 0x7fff) + (char)(iVar25 >> 0x1f)) -
                 (char)((longlong)iVar25 * 0x80010003 >> 0x3f)) + 0x41;
      pbVar13 = pbVar13 + 1;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    _Dst[0x37] = 0;
  }
  else if ((*(byte *)(lVar14 + 0x49) & 1) == 0) {
    if (pbVar13 != _Dst) {
      memcpy(pbVar13,_Dst,(ulonglong)local_198);
    }
  }
  else {
LAB_000233a7:
    cVar1 = *(char *)(lVar14 + 0x4a);
    if (cVar1 == '\0') {
      puVar3 = *(undefined2 **)(lVar14 + 0x18);
      if ((*(int *)(lVar14 + 0x10) != 0) && (puVar3 != (undefined2 *)0x0)) {
        *puVar3 = 0;
        *(undefined1 *)((longlong)puVar3 + 3) = 3;
        if (6 < *(uint *)(lVar14 + 0x10)) {
          puVar3[2] = 0x8000;
          *(undefined1 *)(puVar3 + 3) = 0x83;
          *(undefined4 *)(lVar14 + 0x10) = 7;
        }
      }
    }
    else if (cVar1 == -0x80) {
      puVar3 = *(undefined2 **)(lVar14 + 0x18);
      if ((*(int *)(lVar14 + 0x10) != 0) && (puVar3 != (undefined2 *)0x0)) {
        if (*(int *)(local_1a0 + 0x388 + param_1) == 0) {
          if (*(char *)(uVar16 + 0x34dc + param_1) == '\0') {
            *(undefined1 *)(uVar16 + 0x34dc + param_1) = 1;
            lVar20 = uVar16 * 0x100;
            *(undefined8 *)(lVar20 + 0x34e4 + param_1) = *(undefined8 *)(local_1b0 + 0x14);
            *(undefined8 *)(lVar20 + 0x34ec + param_1) = *(undefined8 *)(local_1b0 + 0x1c);
            *(undefined4 *)(lVar20 + 0x34f4 + param_1) = *(undefined4 *)(local_1b0 + 0x24);
          }
        }
        else {
          *(undefined1 *)(uVar16 + 0x34dc + param_1) = 0;
        }
        *puVar3 = 0x8000;
        *(undefined1 *)((longlong)puVar3 + 3) = 0x14;
        puVar17 = (undefined8 *)(puVar3 + 2);
        *puVar17 = 0;
        *(undefined8 *)(puVar3 + 6) = 0;
        *(undefined4 *)(puVar3 + 10) = 0;
        if (0x17 < *(uint *)(lVar14 + 0x10)) {
          lVar20 = 10;
          *puVar17 = *(undefined8 *)(_Dst + 0x24);
          *(undefined8 *)(puVar3 + 6) = *(undefined8 *)(_Dst + 0x2c);
          *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(_Dst + 0x34);
          do {
            uVar4 = *(undefined1 *)((longlong)puVar17 + 1);
            *(undefined1 *)((longlong)puVar17 + 1) = *(undefined1 *)puVar17;
            *(undefined1 *)puVar17 = uVar4;
            puVar17 = (undefined8 *)((longlong)puVar17 + 2);
            lVar20 = lVar20 + -1;
          } while (lVar20 != 0);
        }
        iVar5 = *(byte *)((longlong)puVar3 + 3) + 4;
        goto LAB_000235cb;
      }
    }
    else {
      if (cVar1 != -0x7d) {
LAB_00023111:
        uVar6 = 6;
        *(undefined1 *)(lVar14 + 4) = 2;
        *(undefined4 *)(param_2 + 0xf8) = 6;
        goto LAB_000238cf;
      }
      puVar3 = *(undefined2 **)(lVar14 + 0x18);
      if (*(int *)(local_1a0 + 0x388 + param_1) == 0) {
        if ((*(int *)(lVar14 + 0x10) == 0) || (puVar3 == (undefined2 *)0x0)) goto LAB_0002338f;
        _itoa_s(*(int *)(local_1a0 + 0x400 + param_1),local_170,0x20,0x10);
        memset(&local_148,0x20,0x100);
        sVar11 = 0xffffffffffffffff;
        do {
          sVar12 = sVar11;
          sVar11 = sVar12 + 1;
        } while (local_190[sVar11] != '\0');
        memcpy(&local_148,local_190,sVar11);
        *(undefined8 *)((longlong)auStack_147 + sVar12) = *(undefined8 *)local_1c0;
        *(undefined8 *)((longlong)auStack_147 + sVar12 + 8) = *(undefined8 *)(local_1c0 + 8);
        *(undefined4 *)((longlong)auStack_147 + sVar12 + 0x10) = *(undefined4 *)(local_1c0 + 0x10);
        *(undefined2 *)(auStack_131 + (sVar12 - 2)) = *(undefined2 *)(local_1c0 + 0x14);
        sVar24 = 0xffffffffffffffff;
        do {
          _Size = sVar24 + 1;
          lVar20 = sVar24 + 1;
          sVar24 = _Size;
        } while (local_170[lVar20] != '\0');
        memcpy(auStack_131 + sVar12,local_170,_Size);
        *puVar3 = 0x8300;
        bVar23 = (char)_Size + '\x16' + (char)sVar11;
        *(byte *)((longlong)puVar3 + 3) = bVar23 + 0x10;
        puVar3[2] = 0x102;
        *(byte *)((longlong)puVar3 + 7) = bVar23;
        if (*(uint *)(lVar14 + 0x10) <= (uint)(byte)(bVar23 + 0x13)) goto LAB_00023111;
        uVar16 = (ulonglong)bVar23;
        memcpy(puVar3 + 4,&local_148,(ulonglong)bVar23);
        *(undefined4 *)(uVar16 + 8 + (longlong)puVar3) = 0x8000201;
        *(undefined4 *)(uVar16 + 0xc + (longlong)puVar3) = 0xffcdab01;
        *(undefined4 *)(uVar16 + 0x10 + (longlong)puVar3) = 0x674523ff;
        *(undefined4 *)(param_2 + 0xfc) = 1;
        iVar5 = bVar23 + 0x14;
        *(undefined4 *)(param_2 + 0xf8) = 1;
      }
      else {
        iVar25 = 0;
        memset(&local_148,(int)CONCAT71((int7)((ulonglong)local_1b0 >> 8),0x20),0x100);
        pcVar15 = (char *)(local_1b0 + 0x36);
        lVar20 = 8;
        do {
          lVar19 = lVar20;
          iVar5 = iVar25 + 1;
          local_170[(longlong)iVar25 + 0x28] = pcVar15[1];
          cVar1 = *pcVar15;
          iVar25 = iVar25 + 2;
          pcVar15 = pcVar15 + 2;
          local_170[(longlong)iVar5 + 0x28] = cVar1;
          lVar20 = lVar19 + -1;
        } while (lVar20 != 0);
        pcVar15 = (char *)(local_1b0 + 0x14);
        uVar16 = (ulonglong)((int)lVar19 + 4);
        do {
          iVar5 = iVar25;
          local_170[(longlong)iVar5 + 0x28] = pcVar15[1];
          cVar1 = *pcVar15;
          iVar25 = iVar5 + 2;
          pcVar15 = pcVar15 + 2;
          local_170[(longlong)(iVar5 + 1) + 0x28] = cVar1;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
        *puVar3 = 0x8300;
        *(char *)((longlong)puVar3 + 3) = (char)iVar5 + '\x12';
        puVar3[2] = 0x102;
        *(char *)((longlong)puVar3 + 7) = (char)iVar25;
        if (*(uint *)(lVar14 + 0x10) <= (iVar5 + 0x15U & 0xff)) goto LAB_00023111;
        sVar11 = (size_t)iVar25;
        memcpy(puVar3 + 4,&local_148,sVar11);
        *(undefined4 *)(sVar11 + 8 + (longlong)puVar3) = 0x8000201;
        *(undefined4 *)(sVar11 + 0xc + (longlong)puVar3) = 0xffcdab01;
        *(undefined4 *)(sVar11 + 0x10 + (longlong)puVar3) = 0x674523ff;
        iVar5 = iVar5 + 0x16;
      }
LAB_000235cb:
      *(int *)(lVar14 + 0x10) = iVar5;
    }
  }
LAB_0002338f:
  *(undefined4 *)(param_2 + 0xf8) = 1;
  uVar6 = 1;
LAB_000238cf:
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return uVar6;
}



===== RestartAdapter @ 00023900 =====

void RestartAdapter(longlong param_1)

{
  byte *pbVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  
  RestoreConfigSpace(param_1);
  if (*(char *)(param_1 + 0x60) != '\0') {
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0x58) + 4);
    if ((int)uVar2 < 0) {
      *(uint *)(*(longlong *)(param_1 + 0x58) + 4) = uVar2 | 2;
    }
    else {
      AhciInitCtler(param_1);
      lVar3 = 10;
      do {
        StorPortStallExecution(1000);
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
      StorPortStallExecution(0);
      pbVar1 = (byte *)(param_1 + 0x948);
      uVar2 = 0;
      do {
        if ((*pbVar1 != 0) && ((*pbVar1 & 4) != 0)) {
          AhciResetPort(param_1,uVar2,'\0');
        }
        uVar2 = uVar2 + 1;
        pbVar1 = pbVar1 + 2;
      } while ((int)uVar2 < 4);
    }
  }
  GetPRDTablePointer(param_1);
  uVar2 = 0;
  puVar4 = (undefined8 *)(param_1 + 0xc0);
  pbVar1 = (byte *)(param_1 + 0x948);
  do {
    if (*pbVar1 != 0) {
      if ((*pbVar1 & 4) == 0) {
        out((short)*puVar4,0);
        StorPortStallExecution(99,*puVar4);
      }
      else {
        AhciResetPort(param_1,uVar2,'\0');
      }
    }
    uVar2 = uVar2 + 1;
    pbVar1 = pbVar1 + 2;
    puVar4 = puVar4 + 1;
  } while (uVar2 < 4);
  return;
}



===== CommReset_for_ErrorDisk @ 000239ec =====

void CommReset_for_ErrorDisk(longlong param_1,uint param_2)

{
  ulonglong uVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined8 uVar7;
  short sVar8;
  longlong lVar9;
  longlong lVar10;
  uint local_res10 [2];
  
  uVar5 = (ulonglong)param_2;
  uVar1 = *(ulonglong *)(param_1 + 0xc0 + (ulonglong)(param_2 >> 1) * 8);
  sVar8 = (short)*(undefined8 *)(param_1 + 0xa0 + (ulonglong)(param_2 >> 1) * 8) + 6;
  out(sVar8,0xa0);
  ReadWriteHostSControlRegister(param_1,param_2,'\x01',local_res10);
  local_res10[0] = local_res10[0] & 0xfffff301 | 0x301;
  *(uint *)(param_1 + 0x120 + uVar5 * 4) = local_res10[0];
  ReadWriteHostSControlRegister(param_1,param_2,'\0',local_res10);
  lVar9 = 2;
  lVar10 = 2;
  do {
    StorPortStallExecution(1000);
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  StorPortStallExecution(0);
  ReadWriteHostSControlRegister(param_1,param_2,'\x01',local_res10);
  local_res10[0] = local_res10[0] & 0xfffffff0;
  *(uint *)(param_1 + 0x120 + uVar5 * 4) = local_res10[0];
  ReadWriteHostSControlRegister(param_1,param_2,'\0',local_res10);
  do {
    StorPortStallExecution(1000);
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  StorPortStallExecution(0);
  local_res10[0] = 0xffffffff;
  uVar7 = 0;
  ReadWriteHostSErrorRegister(param_1,param_2,'\0',local_res10);
  lVar9 = 10;
  do {
    lVar10 = lVar9;
    StorPortStallExecution(1000);
    lVar9 = lVar10 + -1;
  } while (lVar9 != 0);
  StorPortStallExecution(0);
  ReadWriteHostSStatusRegister(param_1,param_2,uVar7,local_res10);
  *(uint *)(param_1 + 0x100 + uVar5 * 4) = local_res10[0];
  if ((local_res10[0] & 1) != 0) {
    cVar3 = ((byte)param_2 & 1 | 0xfa) << 4;
    out(sVar8,cVar3);
    uVar6 = (undefined2)uVar1;
    cVar2 = in(uVar6);
    if (cVar2 < '\0') {
      out(uVar6,4);
      StorPortStallExecution((int)lVar10 + 0x62);
      out(uVar6,0);
      StorPortStallExecution(0x14,uVar1 & 0xffff);
      out(sVar8,cVar3);
      uVar4 = 0;
      do {
        cVar2 = in(uVar6);
        if (-1 < cVar2) {
          return;
        }
        StorPortStallExecution(0x32);
        uVar4 = uVar4 + 1;
      } while (uVar4 < 100);
    }
  }
  return;
}



===== CommReset_for_PM @ 00023b98 =====

void CommReset_for_PM(longlong param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint local_res10 [2];
  
  uVar3 = (ulonglong)param_2;
  out((short)*(undefined8 *)(param_1 + 0xa0 + (ulonglong)(param_2 >> 1) * 8) + 6,0xa0);
  ReadWriteHostSControlRegister(param_1,param_2,'\x01',local_res10);
  local_res10[0] = local_res10[0] & 0xfffff301 | 0x301;
  *(uint *)(param_1 + 0x120 + uVar3 * 4) = local_res10[0];
  ReadWriteHostSControlRegister(param_1,param_2,'\0',local_res10);
  lVar2 = 2;
  lVar1 = 2;
  do {
    StorPortStallExecution(1000);
    lVar1 = lVar1 + -1;
  } while (lVar1 != 0);
  StorPortStallExecution(0);
  ReadWriteHostSControlRegister(param_1,param_2,'\x01',local_res10);
  local_res10[0] = local_res10[0] & 0xfffffff0;
  *(uint *)(param_1 + 0x120 + uVar3 * 4) = local_res10[0];
  ReadWriteHostSControlRegister(param_1,param_2,'\0',local_res10);
  do {
    StorPortStallExecution(1000);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  StorPortStallExecution(0);
  local_res10[0] = 0xffffffff;
  ReadWriteHostSErrorRegister(param_1,param_2,'\0',local_res10);
  *(undefined1 *)(uVar3 + 0xad8 + param_1) = 1;
  return;
}



===== ViaInterrupt @ 00023c9c =====

/* WARNING: Removing unreachable block (ram,0x00023cde) */

ulonglong ViaInterrupt(ulonglong *param_1)

{
  ulonglong uVar1;
  byte bVar2;
  short sVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  sbyte sVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint uVar11;
  
  uVar9 = 0;
  do {
    uVar4 = (uint)uVar9;
    bVar2 = *(byte *)((ulonglong)(uVar4 * 2) + 0x948 + (longlong)param_1);
    uVar5 = (ulonglong)CONCAT31((int3)(uVar4 * 2 >> 8),bVar2);
    if (bVar2 != 0) {
      if ((bVar2 & 4) == 0) {
        sVar3 = (short)param_1[uVar9 + 0x1c];
        bVar2 = in(sVar3 + 2);
        uVar5 = CONCAT71((int7)(uVar9 >> 8),bVar2);
        if ((bVar2 & 4) != 0) {
          in((short)param_1[uVar9 + 0x14] + 7);
          out(sVar3 + 2,bVar2 & 0xfd);
          uVar5 = 0;
          out(sVar3,0);
          if (*(char *)((longlong)param_1 + 0x2c) != '\0') {
            return 0;
          }
          if (*(char *)(uVar9 + 0x42dc + (longlong)param_1) == '\0') {
            return 0;
          }
          if (uVar4 < 4) {
            if (param_1[uVar9 + 0x68] != 0) {
              uVar6 = ProcessInterrupt(param_1,param_1[uVar9 + 0x68]);
              return uVar6;
            }
            *(undefined1 *)(uVar9 + 0x42dc + (longlong)param_1) = 0;
            if ((int)param_1[0x868] == 0) {
              if (param_1[0x14] != 0) {
                in((short)param_1[0x14] + 7);
              }
              uVar9 = param_1[0x15];
              uVar5 = 0;
              if (uVar9 != 0) {
                sVar3 = (short)uVar9 + 7;
                in(sVar3);
                uVar5 = CONCAT62((int6)(uVar9 >> 0x10),sVar3) & 0xffffffffffffff00;
              }
            }
LAB_00023dff:
            return CONCAT71((int7)(uVar5 >> 8),1);
          }
          break;
        }
      }
      else {
        uVar9 = uVar9 & 0xff;
        uVar8 = (uint)uVar9 & 0x80000003;
        uVar1 = param_1[0xb];
        sVar7 = (sbyte)uVar8;
        uVar11 = 1 << sVar7;
        lVar10 = ((ulonglong)uVar8 + 2) * 0x80 + uVar1;
        if ((*(uint *)(uVar1 + 8) & uVar11) != 0) {
          uVar5 = uVar9;
          if ((*(char *)((longlong)param_1 + 0x14b9) == '\0') ||
             ((*(uint *)(lVar10 + 0x10) & 0x400040) == 0)) {
            if (*(char *)(uVar9 + 0x42dc + (longlong)param_1) != '\0') {
              if (param_1[uVar9 + 0x68] != 0) {
                if (((*(uint *)(lVar10 + 0x38) & 1) == 0) ||
                   ((*(uint *)(lVar10 + 0x10) >> 0x1e & 1) != 0)) {
                  uVar5 = AhciProcessInterrupt(param_1,param_1[uVar9 + 0x68]);
                }
                else {
                  uVar4 = 1 << sVar7;
                  uVar5 = (ulonglong)uVar4;
                  *(uint *)(uVar1 + 8) = uVar4;
                }
                goto LAB_00023dff;
              }
              *(undefined1 *)(uVar9 + 0x42dc + (longlong)param_1) = 0;
            }
            *(undefined4 *)(lVar10 + 0x30) = 0xffffffff;
            *(undefined4 *)(lVar10 + 0x10) = 0xffffffff;
            *(uint *)(uVar1 + 8) = uVar11;
          }
          else {
            *(undefined1 *)(uVar9 + 0x42dc + (longlong)param_1) = 0;
            *(undefined4 *)(lVar10 + 0x30) = 0xffffffff;
            *(undefined4 *)(lVar10 + 0x10) = 0xffffffff;
            *(uint *)(uVar1 + 8) = uVar11;
            *(undefined1 *)((longlong)param_1 + 0x14c2) = 1;
            if (*(char *)((longlong)param_1 + 0x14b5) == '\0') {
              uVar5 = StorPortNotification(6,param_1,AtapiScsiTimer,100000,0xffffffff);
            }
          }
        }
      }
    }
    uVar9 = (ulonglong)(uVar4 + 1);
  } while (uVar4 + 1 < 4);
  return uVar5 & 0xffffffffffffff00;
}



===== AtapiErrorProcessInISR @ 00023e88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AtapiErrorProcessInISR(longlong param_1,longlong param_2)

{
  undefined2 uVar1;
  undefined8 uVar2;
  short sVar3;
  byte bVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  undefined7 uVar7;
  longlong lVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined2 *puVar11;
  short sVar12;
  ulonglong uVar13;
  undefined2 uVar14;
  undefined1 auStack_278 [32];
  byte local_258;
  short local_256;
  undefined8 local_250;
  undefined2 local_248 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_278;
  uVar9 = 0;
  uVar13 = (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1);
  uVar6 = (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1);
  local_250 = *(undefined8 *)(param_1 + 0xa0 + uVar6 * 8);
  uVar2 = *(undefined8 *)(param_1 + 0xc0 + uVar6 * 8);
  sVar3 = (short)*(undefined8 *)(param_1 + 0xe0 + uVar6 * 8);
  bVar4 = in(sVar3 + 2);
  sVar12 = (short)local_250 + 7;
  local_258 = in(sVar12);
  uVar6 = 0;
  if ((*(char *)(param_2 + 0x90) == '\b') &&
     (uVar6 = (ulonglong)*(byte *)(param_2 + 0x4e),
     (*(byte *)(param_1 + 0xab8 + uVar6 * 2) & 4) != 0)) {
    *(int *)(param_2 + 0x58) =
         *(int *)(param_2 + 0x58) + *(int *)(param_1 + 0x42e0 + uVar13 * 4) * -2;
    uVar6 = *(ulonglong *)(param_2 + 0x10);
    *(undefined4 *)(*(longlong *)(uVar6 + 0xf0) + 0x10) = *(undefined4 *)(param_2 + 0x58);
  }
  if (*(char *)(param_2 + 0x90) != '\x03') {
    *(undefined1 *)(param_2 + 0x4b) = 4;
    uVar9 = 1;
    if ((bVar4 & 2) == 0) {
      uVar7 = (undefined7)(uVar6 >> 8);
      uVar9 = 1;
      if (((*(char *)(param_2 + 0x90) == '/') || (*(char *)(param_2 + 0x90) == -0x71)) &&
         ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(param_2 + 0x4e) * 2) & 2) == 0)) {
        local_256 = sVar12;
        memset(local_248,0,0x200);
        uVar14 = (undefined2)uVar2;
        out(uVar14,2);
        out(sVar12,0xec);
        uVar10 = 0;
        do {
          bVar4 = in(uVar14);
          if ((bVar4 & 8) == 0) break;
          StorPortStallExecution(200);
          uVar10 = uVar10 + 1;
        } while (uVar10 < 1000);
        uVar10 = 0;
        do {
          bVar4 = in(uVar14);
          if (-1 < (char)bVar4) break;
          StorPortStallExecution(0x96);
          uVar10 = uVar10 + 1;
        } while (uVar10 < 20000);
        uVar9 = 1;
        if ((bVar4 & 8) != 0) {
          lVar8 = 0x100;
          puVar11 = local_248;
          while (lVar8 != 0) {
            lVar8 = lVar8 + -1;
            uVar1 = in((short)local_250);
            *puVar11 = uVar1;
            puVar11 = puVar11 + 1;
          }
          uVar10 = 0;
          do {
            in(uVar14);
            if ((local_258 & 8) == 0) break;
            in((short)local_250);
            uVar10 = uVar10 + 1;
          } while (uVar10 < 0x10000);
          bVar4 = in(local_256);
          if ((bVar4 & 1) == 0) {
            uVar9 = 0;
            *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x4e) * 0xb8 + 0x39a + param_1) = 0;
          }
        }
        uVar7 = 0;
        out(uVar14,0);
      }
      *(undefined4 *)(param_1 + 0x42e0 + uVar13 * 4) = 0;
      uVar5 = in(sVar3);
      uVar6 = CONCAT71(uVar7,uVar5) & 0xfffffffffffffffe;
      out(sVar3,(char)uVar6);
    }
    else {
      out(sVar3 + 2,bVar4 | 2);
      *(undefined4 *)(param_1 + 0x42e0 + uVar13 * 4) = 0;
      bVar4 = in(sVar3);
      uVar6 = 0;
      if ((bVar4 & 1) != 0) {
        uVar6 = 0;
        out(sVar3,bVar4 & 0xfe);
      }
    }
  }
  return CONCAT71((int7)(uVar6 >> 8),uVar9);
}



===== ProcessInterrupt @ 000240b0 =====

undefined8 ProcessInterrupt(ulonglong *param_1,ulonglong param_2)

{
  int *piVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  undefined8 uVar8;
  longlong lVar9;
  ulonglong uVar10;
  short sVar11;
  char *pcVar12;
  uint uVar13;
  char cVar14;
  
  lVar9 = param_2 + 0x48;
  cVar14 = '\0';
  bVar5 = *(byte *)(param_2 + 0x4e);
  bVar7 = bVar5 >> 1;
  uVar10 = (ulonglong)bVar7;
  if ((*(byte *)((ulonglong)bVar5 + 0x948 + (longlong)param_1) & 4) != 0) {
    uVar8 = AhciProcessInterrupt(param_1,param_2);
    return uVar8;
  }
  uVar2 = param_1[(ulonglong)(bVar5 >> 1) + 0x14];
  uVar3 = param_1[(ulonglong)(bVar5 >> 1) + 0x1c];
  out((short)uVar2 + 6,(bVar5 & 1 | 0xfa) << 4);
  *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x4e) + 0x42f0 + (longlong)param_1) = 0;
  *(undefined1 *)(param_2 + 0x4b) = 1;
  *(undefined1 *)(param_2 + 0x4c) = 0;
  bVar5 = in((short)uVar3 + 2);
  sVar11 = (short)uVar2 + 7;
  bVar6 = in(sVar11);
  if ((char)bVar6 < '\0') {
    if (*(char *)((longlong)param_1 + 0x8c) != '\0') {
      return 0;
    }
    uVar13 = 0;
    do {
      bVar6 = in(sVar11);
      if (-1 < (char)bVar6) break;
      StorPortStallExecution(0x32);
      uVar13 = uVar13 + 1;
    } while (uVar13 < 1000);
    if (uVar13 == 1000) {
      *(undefined1 *)(uVar10 + 0x4344 + (longlong)param_1) = 1;
      uVar8 = StorPortNotification(6,param_1,AtapiCallBack,500,bVar7);
      goto LAB_00024332;
    }
  }
  pcVar12 = (char *)(param_2 + 0x4b);
  if (((bVar6 & 1) == 0) && ((bVar5 & 2) == 0)) {
LAB_00024204:
    uVar13 = (uint)bVar7;
    bVar5 = *(byte *)((longlong)param_1 + (ulonglong)*(byte *)(param_2 + 0x4e) * 2 + 0xab8);
    bVar7 = GetInterruptReason((longlong)param_1,(uint)bVar7);
    if (bVar7 == 0xff) {
      cVar14 = '\x01';
    }
    else if (bVar7 == 3) {
      if (param_1[uVar10 + 0x869] == 0) {
        FinishCurrentCmd((longlong)param_1,uVar13);
      }
      else {
        uVar8 = AtapiOriginalSubCmd((longlong)param_1,(ulonglong)uVar13,pcVar12);
        if ((char)uVar8 != '\0') goto LAB_00024332;
        param_2 = param_1[uVar10 + 0x68];
        *(char *)(param_2 + 0x4b) = *pcVar12;
        lVar9 = param_2 + 0x48;
      }
    }
    else {
      if (((bVar5 & 2) == 0) || (bVar7 != 1)) {
        uVar8 = ProcessPIO((longlong)param_1,uVar13,bVar7);
      }
      else {
        uVar8 = SendPacketCommand((longlong)param_1,uVar13);
      }
      if ((char)uVar8 == '\0') goto LAB_00024332;
    }
  }
  else {
    uVar8 = AtapiErrorProcessInISR((longlong)param_1,param_2);
    cVar14 = (char)uVar8;
    if ((param_1[uVar10 + 0x869] != 0) || (*(char *)(param_2 + 0x90) == '\x03')) goto LAB_00024204;
  }
  if (*(char *)(lVar9 + 3) == '\x01') {
    if (((*(byte *)((longlong)param_1 + (ulonglong)*(byte *)(lVar9 + 6) * 2 + 0xab8) & 2) != 0) &&
       (*(char *)(param_2 + 0xbc) == '\0')) {
      plVar4 = *(longlong **)(*(longlong *)(param_2 + 0x10) + 0xec0);
      if (plVar4 != (longlong *)0x0) {
        piVar1 = (int *)(*(longlong *)(param_2 + 0x10) + 0x104);
        *piVar1 = *piVar1 + -1;
        *(undefined1 *)(*(longlong *)(param_2 + 0x10) + 0xebf) = 0;
        RemoveSubCmdFromChnl((longlong)param_1,plVar4);
      }
    }
  }
  else if ((*(byte *)((longlong)param_1 + (ulonglong)*(byte *)(lVar9 + 6) * 2 + 0xab8) & 2) == 0) {
    if (cVar14 != '\0') {
      *(undefined1 *)((ulonglong)*(byte *)(lVar9 + 6) * 0xb8 + 0x39a + (longlong)param_1) = 4;
    }
  }
  else {
    bVar5 = MapError((longlong)param_1,lVar9);
    *(byte *)(lVar9 + 3) = bVar5;
    if (*(char *)(param_2 + 0xbc) != '\0') {
      *(undefined1 *)(uVar10 + 0x250 + (longlong)param_1) = 0;
    }
    *(undefined1 *)(uVar10 + 0x250 + (longlong)param_1) = 0;
  }
  uVar8 = StorCompleteSubCmdEx(param_1,param_2);
LAB_00024332:
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== GetInterruptReason @ 0002434c =====

byte GetInterruptReason(longlong param_1,uint param_2)

{
  char cVar1;
  longlong lVar2;
  byte bVar3;
  undefined2 uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = (ulonglong)param_2;
  lVar2 = *(longlong *)(param_1 + 0x340 + uVar6 * 8);
  if ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(lVar2 + 0x4e) * 2) & 2) != 0) {
    bVar3 = in((short)*(undefined8 *)(param_1 + 0xa0 + uVar6 * 8) + 2);
    return bVar3 & 3;
  }
  cVar1 = *(char *)(uVar6 + 0x4668 + param_1);
  if ((1 < (byte)(cVar1 + 0x30U)) && (cVar1 != -0x14)) {
    uVar5 = 0;
    if ((((*(uint *)((ulonglong)*(byte *)(lVar2 + 0x4e) * 0xb8 + 0x39c + param_1) & 4) != 0) &&
        (*(char *)(*(longlong *)(lVar2 + 0x10) + 0x101) == '\0')) ||
       ((((cVar1 = *(char *)(lVar2 + 0x90), cVar1 == -1 && (*(char *)(lVar2 + 0x93) == -0x50)) &&
         (*(char *)(lVar2 + 0x96) == -0x26)) ||
        ((((cVar1 == '/' || (cVar1 == -0x71)) || (*(char *)(lVar2 + 0x4a) == '\b')) ||
         (cVar1 == '5')))))) {
      return 3;
    }
    uVar4 = (undefined2)*(undefined8 *)(param_1 + 0xc0 + uVar6 * 8);
    bVar3 = in(uVar4);
    if ((bVar3 & 8) == 0) {
      if (-1 < (char)bVar3) {
        if (*(int *)(param_1 + 0x42e0 + uVar6 * 4) == 0) {
          return 3;
        }
        do {
          bVar3 = in(uVar4);
          if ((bVar3 & 8) != 0) break;
          StorPortStallExecution(100);
          uVar5 = uVar5 + 1;
        } while (uVar5 < 5000);
        if (uVar5 != 5000) {
          return (byte)(*(uint *)(lVar2 + 0x54) >> 5) & 2;
        }
      }
      *(undefined1 *)(lVar2 + 0x4b) = 4;
      return 0xff;
    }
    if ((*(uint *)(lVar2 + 0x54) & 0x40) == 0) {
      if ((char)*(uint *)(lVar2 + 0x54) < '\0') {
        return 0;
      }
      return 0xff;
    }
  }
  return 2;
}



===== ProcessPIO @ 0002448c =====

undefined8 ProcessPIO(longlong param_1,uint param_2,char param_3)

{
  longlong *plVar1;
  int *piVar2;
  undefined2 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  byte bVar6;
  char cVar7;
  ulonglong uVar8;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong lVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  uint uVar15;
  undefined2 *puVar16;
  uint uVar17;
  uint *puVar18;
  ulonglong uVar19;
  byte bVar20;
  longlong local_res8;
  uint local_res10 [2];
  
  uVar19 = (ulonglong)param_2;
  local_res8 = *(longlong *)(param_1 + 0xa0 + uVar19 * 8);
  lVar4 = *(longlong *)(param_1 + 0x340 + uVar19 * 8);
  uVar5 = *(undefined8 *)(param_1 + 0xc0 + uVar19 * 8);
  uVar8 = (ulonglong)*(byte *)(lVar4 + 0x4e);
  bVar20 = *(byte *)(param_1 + 0xab8 + uVar8 * 2) & 2;
  uVar17 = 0;
  do {
    uVar13 = (undefined2)uVar5;
    bVar6 = in(uVar13);
    uVar8 = CONCAT71((int7)(uVar8 >> 8),bVar6);
    if ((bVar6 & 8) != 0) break;
    uVar8 = StorPortStallExecution(100);
    uVar17 = uVar17 + 1;
  } while (uVar17 < 5000);
  if (uVar17 != 5000) {
    if (param_3 == '\0') {
      if ((bVar6 & 8) != 0) {
        uVar17 = GetWordCount(param_1,param_2);
        uVar8 = CONCAT44(extraout_var,uVar17);
        uVar11 = (ulonglong)uVar17;
        if ((char)*(undefined4 *)(lVar4 + 0x54) < '\0') {
          uVar15 = 0;
          do {
            cVar7 = in(uVar13);
            if (-1 < cVar7) break;
            StorPortStallExecution(0x96);
            uVar15 = uVar15 + 1;
          } while (uVar15 < 20000);
          uVar13 = (undefined2)local_res8;
          if (bVar20 == 0) {
            do {
              PIOGetBuffer(*(int *)(lVar4 + 0x58) + *(int *)(param_1 + 0x42e0 + uVar19 * 4) * -2,
                           (int)uVar11 * 2,*(longlong *)(param_1 + 0x340 + uVar19 * 8),
                           (int *)local_res10,&local_res8);
              *(longlong *)(param_1 + 0x42f8 + uVar19 * 8) = local_res8;
              lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x340 + uVar19 * 8) + 0x10);
              if (lVar12 == 0) {
                lVar10 = 0;
              }
              else {
                lVar10 = *(longlong *)(*(longlong *)(lVar12 + 0xf0) + 0x38);
              }
              if ((lVar10 != 0) && (*(int *)(lVar10 + 0x27c) == 0)) {
                *(ulonglong *)(param_1 + 0x42f8 + uVar19 * 8) =
                     (ulonglong)
                     (uint)((int)local_res8 - *(int *)(*(longlong *)(lVar12 + 0xf0) + 0x18)) +
                     *(longlong *)(lVar12 + 0xed8);
              }
              uVar17 = local_res10[0] >> 1;
              uVar8 = (ulonglong)uVar17;
              piVar2 = (int *)(param_1 + 0x42e0 + uVar19 * 4);
              *piVar2 = *piVar2 - uVar17;
              uVar9 = (ulonglong)uVar17;
              puVar16 = *(undefined2 **)(param_1 + 0x42f8 + uVar19 * 8);
              while (uVar9 != 0) {
                uVar9 = uVar9 - 1;
                out(*puVar16,uVar13);
                puVar16 = puVar16 + 1;
              }
              uVar17 = (int)uVar11 - uVar17;
              uVar11 = (ulonglong)uVar17;
            } while (uVar17 != 0);
          }
          else {
            uVar8 = uVar11;
            puVar16 = *(undefined2 **)(param_1 + 0x42f8 + uVar19 * 8);
            while (uVar8 != 0) {
              uVar8 = uVar8 - 1;
              out(*puVar16,uVar13);
              puVar16 = puVar16 + 1;
            }
            uVar8 = uVar11 * 2;
            plVar1 = (longlong *)(param_1 + 0x42f8 + uVar19 * 8);
            *plVar1 = *plVar1 + uVar8;
            piVar2 = (int *)(param_1 + 0x42e0 + uVar19 * 4);
            *piVar2 = *piVar2 - uVar17;
          }
LAB_00024820:
          return uVar8 & 0xffffffffffffff00;
        }
      }
    }
    else if ((param_3 == '\x02') && ((bVar6 & 8) != 0)) {
      uVar17 = GetWordCount(param_1,param_2);
      uVar8 = CONCAT44(extraout_var_00,uVar17);
      uVar11 = (ulonglong)uVar17;
      if ((*(uint *)(lVar4 + 0x54) & 0x40) != 0) {
        uVar15 = 0;
        do {
          cVar7 = in(uVar13);
          if (-1 < cVar7) break;
          StorPortStallExecution(0x96);
          uVar15 = uVar15 + 1;
        } while (uVar15 < 20000);
        uVar14 = (undefined2)local_res8;
        if (bVar20 == 0) {
          cVar7 = *(char *)(param_1 + 0x4668 + uVar19);
          if (((byte)(cVar7 + 0x30U) < 2) || (cVar7 == -0x14)) {
            uVar17 = *(uint *)(param_1 + 0x42e0 + uVar19 * 4);
            uVar8 = (ulonglong)uVar17;
            uVar11 = (ulonglong)uVar17;
            puVar16 = *(undefined2 **)(param_1 + 0x42f8 + uVar19 * 8);
            while (uVar11 != 0) {
              uVar11 = uVar11 - 1;
              uVar3 = in(uVar14);
              *puVar16 = uVar3;
              puVar16 = puVar16 + 1;
            }
            uVar17 = 0;
            do {
              bVar20 = in(uVar13);
              uVar8 = CONCAT71((int7)(uVar8 >> 8),bVar20);
              if ((bVar20 & 8) == 0) break;
              lVar12 = 1;
              puVar18 = local_res10;
              while (lVar12 != 0) {
                lVar12 = lVar12 + -1;
                uVar3 = in(uVar14);
                *(undefined2 *)puVar18 = uVar3;
                puVar18 = (uint *)((longlong)puVar18 + 2);
              }
              uVar17 = uVar17 + 1;
            } while (uVar17 < 5000);
            *(undefined4 *)(param_1 + 0x42e0 + uVar19 * 4) = 0;
            *(undefined1 *)(param_1 + 0x4668 + uVar19) = 0;
          }
          else {
            do {
              PIOGetBuffer(*(int *)(lVar4 + 0x58) + *(int *)(param_1 + 0x42e0 + uVar19 * 4) * -2,
                           (int)uVar11 * 2,*(longlong *)(param_1 + 0x340 + uVar19 * 8),
                           (int *)local_res10,&local_res8);
              *(longlong *)(param_1 + 0x42f8 + uVar19 * 8) = local_res8;
              lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x340 + uVar19 * 8) + 0x10);
              if (lVar12 == 0) {
                lVar10 = 0;
              }
              else {
                lVar10 = *(longlong *)(*(longlong *)(lVar12 + 0xf0) + 0x38);
              }
              if ((lVar10 != 0) && (*(int *)(lVar10 + 0x27c) == 0)) {
                *(ulonglong *)(param_1 + 0x42f8 + uVar19 * 8) =
                     (ulonglong)
                     (uint)((int)local_res8 - *(int *)(*(longlong *)(lVar12 + 0xf0) + 0x18)) +
                     *(longlong *)(lVar12 + 0xed8);
              }
              uVar17 = local_res10[0] >> 1;
              uVar8 = (ulonglong)uVar17;
              piVar2 = (int *)(param_1 + 0x42e0 + uVar19 * 4);
              *piVar2 = *piVar2 - uVar17;
              uVar9 = (ulonglong)uVar17;
              puVar16 = *(undefined2 **)(param_1 + 0x42f8 + uVar19 * 8);
              while (uVar9 != 0) {
                uVar9 = uVar9 - 1;
                uVar13 = in(uVar14);
                *puVar16 = uVar13;
                puVar16 = puVar16 + 1;
              }
              uVar17 = (int)uVar11 - uVar17;
              uVar11 = (ulonglong)uVar17;
            } while (uVar17 != 0);
          }
        }
        else {
          uVar8 = uVar11;
          puVar16 = *(undefined2 **)(param_1 + 0x42f8 + uVar19 * 8);
          while (uVar8 != 0) {
            uVar8 = uVar8 - 1;
            uVar13 = in(uVar14);
            *puVar16 = uVar13;
            puVar16 = puVar16 + 1;
          }
          uVar8 = uVar11 * 2;
          plVar1 = (longlong *)(param_1 + 0x42f8 + uVar19 * 8);
          *plVar1 = *plVar1 + uVar8;
          piVar2 = (int *)(param_1 + 0x42e0 + uVar19 * 4);
          *piVar2 = *piVar2 - uVar17;
        }
        if ((*(int *)(param_1 + 0x42e0 + uVar19 * 4) != 0) ||
           (uVar8 = (ulonglong)*(byte *)(lVar4 + 0x4e),
           (*(byte *)(param_1 + 0xab8 + uVar8 * 2) & 2) != 0)) goto LAB_00024820;
        goto LAB_00024829;
      }
    }
  }
  *(undefined1 *)(lVar4 + 0x4b) = 4;
LAB_00024829:
  return CONCAT71((int7)(uVar8 >> 8),1);
}



===== GetWordCount @ 00024844 =====

uint GetWordCount(longlong param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar8 = (ulonglong)param_2;
  uVar7 = 0;
  uVar6 = (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x340 + uVar8 * 8) + 0x4e);
  if ((*(byte *)(param_1 + 0xab8 + uVar6 * 2) & 2) == 0) {
    bVar1 = *(byte *)(uVar6 + 0xb00 + param_1);
    if (bVar1 != 0) {
      uVar7 = (uint)bVar1 << 8;
    }
    uVar2 = *(uint *)(param_1 + 0x42e0 + uVar8 * 4);
    if (uVar2 < uVar7) {
      uVar7 = uVar2;
    }
  }
  else {
    sVar3 = (short)*(undefined8 *)(param_1 + 0xa0 + uVar8 * 8);
    uVar4 = in(sVar3 + 4);
    uVar5 = in(sVar3 + 5);
    uVar2 = *(uint *)(param_1 + 0x42e0 + uVar8 * 4);
    uVar7 = (uint)(ushort)(CONCAT11(uVar5,uVar4) >> 1);
    if (uVar2 < uVar7) {
      uVar7 = uVar2;
    }
  }
  return uVar7;
}



===== AtapiSpecifiedCMDFinished @ 000248c8 =====

void AtapiSpecifiedCMDFinished(longlong param_1,ulonglong param_2)

{
  byte bVar1;
  longlong lVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  void *_Dst;
  int *piVar5;
  longlong lVar6;
  void *_Src;
  longlong lVar7;
  ulonglong uVar8;
  byte bVar9;
  byte *pbVar10;
  byte bVar11;
  ulonglong uVar12;
  
  uVar8 = param_2 & 0xffffffff;
  lVar2 = *(longlong *)(param_1 + 0x340 + uVar8 * 8);
  if ((*(char *)(lVar2 + 0x90) != 'Z') || (*(int *)(param_1 + 0x4690 + uVar8 * 4) != 0))
  goto LAB_00024a59;
  pbVar3 = *(byte **)(lVar2 + 0x60);
  *(undefined1 *)(lVar2 + 0x90) = 0x1a;
  *pbVar3 = pbVar3[1];
  pbVar3[1] = pbVar3[2];
  pbVar3[2] = pbVar3[3];
  bVar11 = *pbVar3;
  pbVar3[3] = pbVar3[7];
  DbgPrint("****!!!!!AtapiSpecifiedCMDFinished lengh\n");
  bVar9 = bVar11 - 2;
  if (((*(byte *)(lVar2 + 0x92) & 0x3f) == 1) && (*(byte *)(lVar2 + 0x98) < 0x14)) {
    uVar12 = 8;
    if (8 < *(uint *)(lVar2 + 0x58)) {
      do {
        bVar11 = (char)uVar12 + 1;
        pbVar3[(byte)((char)uVar12 - 4)] = pbVar3[uVar12];
        uVar12 = (ulonglong)bVar11;
      } while ((uint)bVar11 < *(uint *)(lVar2 + 0x58));
    }
  }
  else {
    bVar9 = *(byte *)(lVar2 + 0x58);
    if (7 < (byte)(bVar9 - 5)) {
      pbVar10 = pbVar3 + (byte)(bVar9 - 5);
      uVar12 = (ulonglong)(byte)(bVar9 - 0xc);
      do {
        bVar9 = bVar9 - 1;
        bVar1 = *pbVar10;
        pbVar10 = pbVar10 + -1;
        pbVar3[bVar9] = bVar1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
    pbVar3[4] = 0;
    pbVar3[5] = 0;
    pbVar3[6] = 0;
    pbVar3[7] = 0;
    pbVar3[8] = 0;
    pbVar3[9] = 0;
    pbVar3[10] = 0;
    pbVar3[0xb] = 0;
    bVar9 = bVar11 + 6;
    pbVar3[3] = 8;
    if (*(uint *)(lVar2 + 0x58) < (uint)bVar9) {
      bVar9 = *(byte *)(lVar2 + 0x58);
    }
  }
  if ((uint)*pbVar3 < *(uint *)(lVar2 + 0x58)) {
    *(uint *)(lVar2 + 0x58) = (uint)bVar9;
    *(uint *)(*(longlong *)(*(longlong *)(lVar2 + 0x10) + 0xf0) + 0x10) = (uint)bVar9;
    *pbVar3 = bVar9 - 1;
  }
  lVar7 = *(longlong *)(lVar2 + 0x10);
  _Dst = *(void **)(*(longlong *)(lVar7 + 0xf0) + 0x18);
  if (_Dst == (void *)0x0) {
    if (lVar7 == 0) {
      lVar6 = 0;
    }
    else {
      lVar6 = *(longlong *)(*(longlong *)(lVar7 + 0xf0) + 0x38);
    }
    if ((lVar6 != 0) && (*(int *)(lVar6 + 0x27c) == 0)) {
      _Dst = *(void **)(lVar7 + 0xed8);
      _Src = *(void **)(lVar2 + 0x60);
      if (_Dst != _Src) goto LAB_00024a48;
    }
  }
  else {
    _Src = *(void **)(lVar2 + 0x60);
    if (_Dst != _Src) {
LAB_00024a48:
      memcpy(_Dst,_Src,(ulonglong)bVar9);
    }
  }
  *(undefined4 *)(param_1 + 0x42e0 + uVar8 * 4) = 0;
LAB_00024a59:
  if ((*(char *)(lVar2 + 0x90) == '%') &&
     ((*(byte *)((ulonglong)*(byte *)(lVar2 + 0x4e) * 0xd4 + 0xd15 + param_1) & 0x1f) == 5)) {
    piVar5 = *(int **)(lVar2 + 0x60);
    *(int **)(param_1 + 0x42f8 + uVar8 * 8) = piVar5;
    if (*(longlong *)(lVar2 + 0x60) == 0) {
      lVar2 = *(longlong *)(lVar2 + 0x10);
      if (lVar2 == 0) {
        lVar7 = 0;
      }
      else {
        lVar7 = *(longlong *)(*(longlong *)(lVar2 + 0xf0) + 0x38);
      }
      if ((lVar7 != 0) && (*(int *)(lVar7 + 0x27c) == 0)) {
        piVar5 = *(int **)(lVar2 + 0xed8);
        *(int **)(param_1 + 0x42f8 + uVar8 * 8) = piVar5;
      }
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 == 0)) {
      *piVar5 = -0x81;
    }
    puVar4 = (undefined4 *)(*(longlong *)(param_1 + 0x42f8 + uVar8 * 8) + 4);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = 0x80000;
    }
  }
  return;
}



===== FinishCurrentCmd @ 00024b08 =====

ulonglong FinishCurrentCmd(longlong param_1,uint param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  uint3 uVar3;
  short sVar4;
  byte bVar5;
  undefined1 uVar6;
  char cVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  
  uVar8 = (ulonglong)param_2;
  lVar1 = *(longlong *)(param_1 + 0x340 + uVar8 * 8);
  uVar2 = *(undefined8 *)(param_1 + 0xa0 + uVar8 * 8);
  sVar4 = (short)*(undefined8 *)(param_1 + 0xe0 + uVar8 * 8);
  uVar3 = (uint3)(param_2 >> 8);
  bVar5 = in(sVar4 + 2);
  if ((bVar5 & 2) == 0) {
    uVar6 = in(sVar4);
    puVar9 = (undefined1 *)((ulonglong)CONCAT31(uVar3,uVar6) & 0xfffffffffffffffe);
    out(sVar4,(char)puVar9);
    *(undefined1 *)(lVar1 + 0x4b) = 1;
    if (((*(char *)(lVar1 + 0x90) == -1) && (*(char *)(lVar1 + 0x93) == -0x50)) &&
       (*(char *)(lVar1 + 0x96) == -0x26)) {
      sVar4 = (short)uVar2;
      cVar7 = in(sVar4 + 4);
      if ((cVar7 == -0xc) && (cVar7 = in(sVar4 + 5), cVar7 == ',')) {
        puVar9 = *(undefined1 **)(lVar1 + 0x60);
        *puVar9 = 1;
      }
      else {
        puVar9 = (undefined1 *)((ulonglong)uVar3 << 8);
        **(undefined1 **)(lVar1 + 0x60) = 0;
      }
    }
    if ((*(byte *)(param_1 + 0xab8 + (ulonglong)*(byte *)(lVar1 + 0x4e) * 2) & 2) != 0) {
      puVar9 = (undefined1 *)AtapiSpecifiedCMDFinished(param_1,uVar8);
    }
    uVar8 = CONCAT71((int7)((ulonglong)puVar9 >> 8),1);
  }
  else {
    out(sVar4 + 2,bVar5 | 2);
    bVar5 = in(sVar4);
    uVar8 = (ulonglong)CONCAT31(uVar3,bVar5);
    if ((bVar5 & 1) != 0) {
      uVar8 = (ulonglong)CONCAT31(uVar3,bVar5) & 0xfffffffffffffffe;
      out(sVar4,(char)uVar8);
    }
    *(undefined1 *)(lVar1 + 0x4b) = 4;
    uVar8 = uVar8 & 0xffffffffffffff00;
  }
  return uVar8;
}



===== SendPacketCommand @ 00024bc0 =====

ulonglong SendPacketCommand(longlong param_1,uint param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  short sVar5;
  byte bVar6;
  undefined1 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  int iVar10;
  undefined2 *puVar11;
  
  uVar8 = (ulonglong)param_2;
  iVar10 = 0;
  lVar1 = *(longlong *)(param_1 + 0x340 + uVar8 * 8);
  uVar2 = *(undefined8 *)(param_1 + 0xa0 + uVar8 * 8);
  uVar3 = *(undefined8 *)(param_1 + 0xc0 + uVar8 * 8);
  uVar4 = *(undefined8 *)(param_1 + 0xe0 + uVar8 * 8);
  do {
    bVar6 = in((short)uVar3);
    register0x00000020 = (BADSPACEBASE *)CONCAT71((int7)((ulonglong)register0x00000020 >> 8),bVar6);
    if ((bVar6 & 8) != 0) break;
    register0x00000020 = (BADSPACEBASE *)StorPortStallExecution(100);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 5000);
  if (iVar10 == 5000) {
    *(undefined1 *)(lVar1 + 0x4b) = 4;
    uVar8 = CONCAT71((int7)((ulonglong)register0x00000020 >> 8),1);
  }
  else {
    *(undefined1 *)(uVar8 + 0x42dc + param_1) = 1;
    lVar9 = 6;
    puVar11 = (undefined2 *)(lVar1 + 0x90);
    while (lVar9 != 0) {
      lVar9 = lVar9 + -1;
      out(*puVar11,(short)uVar2);
      puVar11 = puVar11 + 1;
    }
    uVar8 = *(ulonglong *)(lVar1 + 0x10);
    bVar6 = *(byte *)((ulonglong)*(byte *)(lVar1 + 0x4e) * 0xb8 + 0x39c + param_1) & 0xf;
    if (*(char *)(uVar8 + 0x101) != '\0') {
      bVar6 = 0;
    }
    if ((bVar6 & 4) != 0) {
      sVar5 = (short)uVar4;
      bVar6 = in(sVar5 + 2);
      out(sVar5 + 2,bVar6 | 6);
      uVar7 = in(sVar5);
      uVar8 = CONCAT71((int7)(uVar8 >> 8),uVar7);
      if ((*(uint *)(lVar1 + 0x54) & 0x40) == 0) {
        uVar8 = uVar8 & 0xfffffffffffffff7;
        out(sVar5,(char)uVar8);
      }
      else {
        uVar8 = uVar8 | 8;
        out(sVar5,(char)uVar8);
      }
      uVar7 = in(sVar5);
      uVar8 = CONCAT71((int7)(uVar8 >> 8),uVar7) | 1;
      out(sVar5,(char)uVar8);
    }
    uVar8 = uVar8 & 0xffffffffffffff00;
  }
  return uVar8;
}



===== AtapiOriginalSubCmd @ 00024cbc =====

longlong AtapiOriginalSubCmd(longlong param_1,ulonglong param_2,char *param_3)

{
  ushort *puVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined8 *_Src;
  ulonglong uVar12;
  undefined8 *puVar13;
  undefined2 *_Dst;
  ulonglong uVar14;
  
  uVar14 = param_2 & 0xffffffff;
  _Src = *(undefined8 **)(param_1 + 0x340 + uVar14 * 8);
  if (*(char *)(_Src + 0x12) == -0x43) {
    if (*param_3 == '\x01') {
      bVar2 = *(byte *)((longlong)_Src + 0x4e);
      if ((_Src[0xc] != 0) &&
         (uVar7 = (uint)*(byte *)(_Src[0xc] + 5),
         *(uint *)(param_1 + 0xa98 + (ulonglong)bVar2 * 4) = uVar7, 1 < uVar7)) {
        puVar1 = (ushort *)(param_1 + 0xab8 + (ulonglong)bVar2 * 2);
        *puVar1 = *puVar1 | 0x40;
      }
      puVar1 = (ushort *)(param_1 + 0xac8 + (ulonglong)*(byte *)((longlong)_Src + 0x4e) * 2);
      *puVar1 = *puVar1 | 2;
LAB_00024d2b:
      puVar13 = *(undefined8 **)(param_1 + 0x4348 + uVar14 * 8);
      *(undefined8 *)(param_1 + 0x4348 + uVar14 * 8) = 0;
    }
    else {
      puVar13 = (undefined8 *)(param_1 + 0x4368 + uVar14 * 0xc0);
      if (puVar13 != _Src) {
        if ((((uint)_Src | (uint)puVar13) & 0xf) == 0) {
          lVar10 = 1;
          puVar6 = puVar13;
          do {
            puVar11 = _Src;
            puVar9 = puVar6;
            uVar8 = puVar11[1];
            *puVar9 = *puVar11;
            puVar9[1] = uVar8;
            uVar8 = puVar11[3];
            puVar9[2] = puVar11[2];
            puVar9[3] = uVar8;
            uVar8 = puVar11[5];
            puVar9[4] = puVar11[4];
            puVar9[5] = uVar8;
            uVar8 = puVar11[7];
            puVar9[6] = puVar11[6];
            puVar9[7] = uVar8;
            uVar8 = puVar11[9];
            puVar9[8] = puVar11[8];
            puVar9[9] = uVar8;
            uVar8 = puVar11[0xb];
            puVar9[10] = puVar11[10];
            puVar9[0xb] = uVar8;
            uVar8 = puVar11[0xd];
            puVar9[0xc] = puVar11[0xc];
            puVar9[0xd] = uVar8;
            uVar8 = puVar11[0xf];
            puVar9[0xe] = puVar11[0xe];
            puVar9[0xf] = uVar8;
            lVar10 = lVar10 + -1;
            puVar6 = puVar9 + 0x10;
            _Src = puVar11 + 0x10;
          } while (lVar10 != 0);
          uVar8 = puVar11[0x11];
          puVar9[0x10] = puVar11[0x10];
          puVar9[0x11] = uVar8;
          uVar8 = puVar11[0x13];
          puVar9[0x12] = puVar11[0x12];
          puVar9[0x13] = uVar8;
          uVar8 = puVar11[0x15];
          puVar9[0x14] = puVar11[0x14];
          puVar9[0x15] = uVar8;
          uVar8 = puVar11[0x17];
          puVar9[0x16] = puVar11[0x16];
          puVar9[0x17] = uVar8;
        }
        else {
          memcpy(puVar13,_Src,0xc0);
        }
      }
      lVar10 = *(longlong *)(param_1 + 0x4348 + uVar14 * 8);
      bVar2 = *(byte *)(lVar10 + 0x4e);
      uVar3 = *(undefined1 *)(lVar10 + 0x4d);
      uVar12 = (ulonglong)(bVar2 >> 1);
      lVar10 = uVar12 * 0xc0;
      _Dst = (undefined2 *)(param_1 + 0x43b0 + lVar10);
      *(undefined4 *)(lVar10 + 0x440c + param_1) = 1;
      *(undefined4 *)(lVar10 + 0x4414 + param_1) = 1;
      memset(_Dst,0,0x58);
      *(undefined1 *)((longlong)_Dst + 5) = uVar3;
      *(byte *)(_Dst + 3) = bVar2;
      *(undefined1 *)(_Dst + 1) = 0;
      *_Dst = 0x58;
      *(undefined4 *)(_Dst + 6) = 0x48;
      *(undefined4 *)(_Dst + 10) = 4;
      *(undefined1 *)(_Dst + 5) = 6;
      *(undefined4 *)(_Dst + 8) = 0x12;
      *(ulonglong *)(_Dst + 0xc) = param_1 + 0x46a0 + uVar12 * 0x12;
      *(undefined1 *)(_Dst + 0x24) = 3;
      *(undefined1 *)(_Dst + 0x26) = 0x12;
    }
    *(undefined8 **)(param_1 + 0x340 + uVar14 * 8) = puVar13;
  }
  else {
    lVar10 = _Src[0xc];
    if ((*param_3 == '\x12') &&
       (8 < (uint)(*(int *)(_Src + 0xb) + *(int *)(param_1 + 0x42e0 + uVar14 * 4) * -2))) {
      *param_3 = '\x01';
    }
    if (*param_3 != '\x01') goto LAB_00024fd3;
    if (((*(byte *)(lVar10 + 2) & 0xf) == 5) ||
       (cVar4 = *(char *)(uVar14 + 0x466c + param_1), cVar4 == '\0')) goto LAB_00024d2b;
    *(char *)(uVar14 + 0x466c + param_1) = cVar4 + -1;
    puVar13 = (undefined8 *)(param_1 + 0x4368 + uVar14 * 0xc0);
    if (puVar13 != _Src) {
      if ((((uint)_Src | (uint)puVar13) & 0xf) == 0) {
        lVar10 = 1;
        puVar6 = puVar13;
        do {
          puVar11 = _Src;
          puVar9 = puVar6;
          uVar8 = puVar11[1];
          *puVar9 = *puVar11;
          puVar9[1] = uVar8;
          uVar8 = puVar11[3];
          puVar9[2] = puVar11[2];
          puVar9[3] = uVar8;
          uVar8 = puVar11[5];
          puVar9[4] = puVar11[4];
          puVar9[5] = uVar8;
          uVar8 = puVar11[7];
          puVar9[6] = puVar11[6];
          puVar9[7] = uVar8;
          uVar8 = puVar11[9];
          puVar9[8] = puVar11[8];
          puVar9[9] = uVar8;
          uVar8 = puVar11[0xb];
          puVar9[10] = puVar11[10];
          puVar9[0xb] = uVar8;
          uVar8 = puVar11[0xd];
          puVar9[0xc] = puVar11[0xc];
          puVar9[0xd] = uVar8;
          uVar8 = puVar11[0xf];
          puVar9[0xe] = puVar11[0xe];
          puVar9[0xf] = uVar8;
          lVar10 = lVar10 + -1;
          puVar6 = puVar9 + 0x10;
          _Src = puVar11 + 0x10;
        } while (lVar10 != 0);
        uVar8 = puVar11[0x11];
        puVar9[0x10] = puVar11[0x10];
        puVar9[0x11] = uVar8;
        uVar8 = puVar11[0x13];
        puVar9[0x12] = puVar11[0x12];
        puVar9[0x13] = uVar8;
        uVar8 = puVar11[0x15];
        puVar9[0x14] = puVar11[0x14];
        puVar9[0x15] = uVar8;
        uVar8 = puVar11[0x17];
        puVar9[0x16] = puVar11[0x16];
        puVar9[0x17] = uVar8;
      }
      else {
        memcpy(puVar13,_Src,0xc0);
      }
    }
    lVar10 = *(longlong *)(param_1 + 0x4348 + uVar14 * 8);
    BuildMechanismStatusSrb
              (param_1,*(undefined1 *)(lVar10 + 0x4d),(ulonglong)*(byte *)(lVar10 + 0x4e));
    *(undefined8 **)(param_1 + 0x340 + uVar14 * 8) = puVar13;
  }
  uVar8 = DispatchAtapiReadWrite(param_1,puVar13);
  _Src = puVar13;
  if (*(char *)((longlong)puVar13 + 0x4b) == '\0') {
    return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
LAB_00024fd3:
  puVar13 = *(undefined8 **)(param_1 + 0x4348 + uVar14 * 8);
  if (puVar13 != (undefined8 *)0x0) {
    *(undefined8 **)(param_1 + 0x340 + uVar14 * 8) = puVar13;
    *(undefined8 *)(param_1 + 0x4348 + uVar14 * 8) = 0;
    _Src = puVar13;
  }
  *param_3 = '\x04';
  *(undefined8 *)(param_1 + 0x42f8 + uVar14 * 8) = _Src[0xc];
  uVar5 = *(undefined4 *)(_Src + 0xb);
  *(undefined4 *)(param_1 + 0x42e0 + uVar14 * 4) = uVar5;
  *(undefined1 *)(uVar14 + 0x250 + param_1) = 0;
  return (ulonglong)(uint3)((uint)uVar5 >> 8) << 8;
}



===== AtapiCallBack @ 00025030 =====

/* WARNING: Removing unreachable block (ram,0x000250a6) */

void AtapiCallBack(ulonglong *param_1)

{
  byte bVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong *puVar4;
  char *pcVar5;
  
  pcVar5 = (char *)((longlong)param_1 + 0x4344);
  puVar4 = param_1 + 0x68;
  lVar3 = 4;
  do {
    if (*pcVar5 != '\0') {
      uVar2 = *puVar4;
      if (uVar2 != 0xffffffffffffffb8) {
        bVar1 = *(byte *)(uVar2 + 0x4e);
        if (*(char *)((ulonglong)(bVar1 >> 1) + 0x42dc + (longlong)param_1) == '\0') {
          if ((*(byte *)((ulonglong)bVar1 + 0x948 + (longlong)param_1) & 4) == 0) {
            bVar1 = in((short)param_1[(ulonglong)(bVar1 >> 1) + 0x18]);
          }
          else {
            bVar1 = *(byte *)((longlong)(int)(bVar1 >> 1 & 0x80000003) * 0x80 + 0x120 + param_1[0xb]
                             );
          }
          if ((bVar1 & 0x10) == 0) {
            *(undefined1 *)((ulonglong)(*(byte *)(uVar2 + 0x4e) >> 1) + 0x4344 + (longlong)param_1)
                 = 1;
          }
          else {
            *(undefined1 *)((ulonglong)(*(byte *)(uVar2 + 0x4e) >> 1) + 0x4344 + (longlong)param_1)
                 = 0;
            *(undefined1 *)((ulonglong)(*(byte *)(uVar2 + 0x4e) >> 1) + 0x250 + (longlong)param_1) =
                 0;
            *(undefined1 *)(uVar2 + 0x4b) = 1;
            StorCompleteSubCmdEx(param_1,param_1[(ulonglong)(*(byte *)(uVar2 + 0x4e) >> 1) + 0x68]);
          }
          goto LAB_0002513a;
        }
      }
      *(undefined1 *)((ulonglong)(*(byte *)(uVar2 + 0x4e) >> 1) + 0x4344 + (longlong)param_1) = 0;
      ProcessInterrupt(param_1,param_1[(ulonglong)(*(byte *)(uVar2 + 0x4e) >> 1) + 0x68]);
    }
LAB_0002513a:
    puVar4 = puVar4 + 1;
    pcVar5 = pcVar5 + 1;
    lVar3 = lVar3 + -1;
    if (lVar3 == 0) {
      uVar2 = 0;
      do {
        if (*(char *)(uVar2 + 0x4344 + (longlong)param_1) != '\0') {
          StorPortNotification(6,param_1,AtapiCallBack,1000);
          return;
        }
        bVar1 = (char)uVar2 + 1;
        uVar2 = (ulonglong)bVar1;
      } while (bVar1 < 4);
      if ((*(char *)((longlong)param_1 + 0x14b6) == '\0') ||
         (*(char *)((longlong)param_1 + 0x14c2) != '\0')) {
        StorPortNotification(6,param_1,AtapiScsiTimer,10000000);
        *(undefined1 *)((longlong)param_1 + 0x9c) = 1;
      }
      return;
    }
  } while( true );
}



===== DispatchSmartCommand @ 000251c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DispatchSmartCommand(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  short sVar2;
  undefined8 uVar3;
  byte bVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  bool bVar9;
  undefined1 auStack_98 [32];
  ushort local_78;
  uint local_74;
  undefined8 local_70;
  undefined8 local_68;
  ulonglong local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined1 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  bVar4 = *(byte *)((longlong)param_2 + 0x4e);
  local_60 = (ulonglong)bVar4;
  lVar1 = param_2[0xc];
  local_68 = *(undefined8 *)(param_1 + 0xa0 + (ulonglong)(bVar4 >> 1) * 8);
  local_70 = *(undefined8 *)(param_1 + 0xc0 + (ulonglong)(bVar4 >> 1) * 8);
  local_58 = *(undefined8 *)(lVar1 + 0x1c);
  local_50 = *(undefined8 *)(lVar1 + 0x24);
  local_48 = *(undefined8 *)(lVar1 + 0x2c);
  local_40 = *(undefined8 *)(lVar1 + 0x34);
  local_38 = *(undefined1 *)(lVar1 + 0x3c);
  if ((*(byte *)(local_60 + 0x948 + param_1) & 4) != 0) {
    uVar8 = AhciDispatchSmartCommand(param_1,param_2);
    return uVar8;
  }
  local_58._4_1_ = (char)((ulonglong)local_58 >> 0x20);
  local_50._2_1_ = (char)((ulonglong)local_50 >> 0x10);
  if (local_50._2_1_ == -0x14) {
    *(undefined1 *)((ulonglong)(bVar4 >> 1) + 0x4668 + param_1) = 0xec;
  }
  else {
    *(char *)((ulonglong)(bVar4 >> 1) + 0x4668 + param_1) = local_58._4_1_;
  }
  uVar6 = (int)CONCAT71((int7)((ulonglong)local_70 >> 8),local_58._4_1_) + 0x30;
  uVar8 = (ulonglong)uVar6;
  uVar5 = (undefined2)local_70;
  if (((byte)uVar6 < 2) || (local_50._2_1_ == -0x14)) {
    local_74 = 0;
    do {
      bVar4 = in(uVar5);
      uVar8 = CONCAT71((int7)(uVar8 >> 8),bVar4);
      local_78 = CONCAT11(local_78._1_1_,bVar4);
      bVar9 = true;
      if ((bVar4 & 0x80) == 0) goto LAB_0002545c;
      uVar8 = StorPortStallExecution(0x96);
      local_74 = local_74 + 1;
    } while (local_74 < 20000);
    uVar8 = uVar8 & 0xffffffffffffff00;
    bVar9 = (local_78 & 0x80) == 0;
LAB_0002545c:
    if (bVar9) {
      uVar8 = 0;
      if (*(int *)(lVar1 + 0x18) != 0) {
        do {
          *(undefined1 *)(uVar8 + 0x1c + lVar1) = 0;
          uVar6 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar6;
        } while (uVar6 < *(uint *)(lVar1 + 0x18));
      }
      *(longlong *)(param_1 + 0x42f8 + (ulonglong)(*(byte *)((longlong)param_2 + 0x4e) >> 1) * 8) =
           lVar1 + 0x2c;
      *(uint *)(param_1 + 0x42e0 + (ulonglong)(*(byte *)((longlong)param_2 + 0x4e) >> 1) * 4) =
           *(int *)(lVar1 + 0x18) - 0x20U >> 1;
      *(undefined1 *)((ulonglong)(*(byte *)((longlong)param_2 + 0x4e) >> 1) + 0x42dc + param_1) = 1;
      sVar2 = (short)local_68;
      out(sVar2 + 6,((byte)(local_60 & 0xffffffffffffff01) | 0xfa) << 4);
      out(sVar2 + 1,local_58._4_1_);
      out(sVar2 + 2,local_58._5_1_);
      out(sVar2 + 3,local_58._6_1_);
      out(sVar2 + 4,local_58._7_1_);
      out(sVar2 + 5,(undefined1)local_50);
      uVar8 = CONCAT71((int7)((local_60 & 0xffffffffffffff01) >> 8),local_50._2_1_);
      out(sVar2 + 7,local_50._2_1_);
LAB_00025500:
      *(undefined1 *)((longlong)param_2 + 0x4b) = 0;
LAB_00025504:
      return uVar8 & 0xffffffffffffff00;
    }
  }
  else {
    if ((2 < (byte)(local_58._4_1_ + 0x28U)) && (2 < (byte)(local_58._4_1_ + 0x2eU))) {
      *(undefined1 *)((longlong)param_2 + 0x4b) = 6;
      goto LAB_00025466;
    }
    local_74 = 0;
    do {
      bVar4 = in(uVar5);
      uVar8 = CONCAT71((int7)(uVar8 >> 8),bVar4);
      local_78 = CONCAT11(local_78._1_1_,bVar4);
      bVar9 = true;
      if ((bVar4 & 0x80) == 0) goto LAB_000252f8;
      uVar8 = StorPortStallExecution(0x96);
      local_74 = local_74 + 1;
    } while (local_74 < 20000);
    uVar8 = uVar8 & 0xffffffffffffff00;
    bVar9 = (local_78 & 0x80) == 0;
LAB_000252f8:
    uVar3 = local_70;
    if (bVar9) {
      uVar8 = 0;
      if (*(int *)(lVar1 + 0x18) != 0) {
        do {
          *(undefined1 *)(uVar8 + 0x1c + lVar1) = 0;
          uVar6 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar6;
        } while (uVar6 < *(uint *)(lVar1 + 0x18));
      }
      *(longlong *)(param_1 + 0x42f8 + (ulonglong)(*(byte *)((longlong)param_2 + 0x4e) >> 1) * 8) =
           lVar1 + 0x2c;
      *(undefined4 *)(param_1 + 0x42e0 + (ulonglong)(*(byte *)((longlong)param_2 + 0x4e) >> 1) * 4)
           = 0;
      *(undefined1 *)((ulonglong)(*(byte *)((longlong)param_2 + 0x4e) >> 1) + 0x42dc + param_1) = 1;
      sVar2 = (short)local_68;
      out(sVar2 + 6,((byte)local_60 & 1 | 0xfa) << 4);
      out(sVar2 + 1,local_58._4_1_);
      out(sVar2 + 2,local_58._5_1_);
      out(sVar2 + 3,local_58._6_1_);
      local_78 = sVar2 + 4;
      out(local_78,local_58._7_1_);
      iVar7 = (int)local_68 + 5;
      uVar5 = (undefined2)iVar7;
      local_74 = CONCAT22(local_74._2_2_,uVar5);
      out(uVar5,(undefined1)local_50);
      uVar8 = (ulonglong)CONCAT31((int3)((uint)iVar7 >> 8),local_50._2_1_);
      out(sVar2 + 7,local_50._2_1_);
      if (local_58._4_1_ == -0x26) {
        uVar6 = 0;
        do {
          bVar4 = in((short)uVar3);
          uVar8 = CONCAT71((int7)(uVar8 >> 8),bVar4);
          if ((bVar4 & 0x80) == 0) break;
          uVar8 = StorPortStallExecution(0x96);
          uVar6 = uVar6 + 1;
        } while (uVar6 < 20000);
        if ((bVar4 & 0x80) != 0) {
          *(undefined1 *)((longlong)param_2 + 0x4b) = 5;
          goto LAB_00025504;
        }
        uVar6 = 0;
        do {
          bVar4 = in((short)uVar3);
          uVar8 = CONCAT71((int7)(uVar8 >> 8),bVar4);
          if ((bVar4 & 8) == 0) break;
          uVar8 = StorPortStallExecution(200);
          uVar6 = uVar6 + 1;
        } while (uVar6 < 1000);
        if ((bVar4 & 8) != 0) {
          *(undefined1 *)((longlong)param_2 + 0x4b) = 9;
          goto LAB_00025504;
        }
        in(local_78);
        in((undefined2)local_74);
        uVar8 = uVar8 & 0xffffffffffffff00;
      }
      goto LAB_00025500;
    }
  }
  *(undefined1 *)((longlong)param_2 + 0x4b) = 5;
LAB_00025466:
  return CONCAT71((int7)(uVar8 >> 8),1);
}



===== DispatchUserSmartCommand @ 00025528 =====

undefined8 DispatchUserSmartCommand(longlong param_1,undefined8 *param_2)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint7 uVar7;
  ulonglong uVar8;
  char cVar9;
  ulonglong uVar10;
  short sVar11;
  uint uVar12;
  
  bVar3 = *(byte *)((longlong)param_2 + 0x95);
  uVar10 = (ulonglong)bVar3;
  uVar8 = (ulonglong)(bVar3 >> 1);
  uVar5 = *(undefined8 *)(param_1 + 0xc0 + uVar8 * 8);
  if ((*(byte *)(uVar10 + 0x948 + param_1) & 4) != 0) {
    uVar5 = AhciDispatchUserSmartCommand(param_1,param_2);
    return uVar5;
  }
  uVar1 = *(ushort *)(param_1 + 0xab8 + (ulonglong)bVar3 * 2);
  uVar6 = (ulonglong)uVar1;
  if (((uVar1 & 1) == 0) || ((uVar1 & 2) != 0)) {
    *(undefined1 *)((longlong)param_2 + 0x4b) = 10;
  }
  else {
    sVar2 = (short)*(undefined8 *)(param_1 + 0xa0 + uVar8 * 8);
    sVar11 = sVar2 + 6;
    cVar9 = (bVar3 & 1 | 0xfa) << 4;
    uVar6 = (ulonglong)CONCAT11((char)(uVar1 >> 8),cVar9);
    out(sVar11,cVar9);
    uVar12 = 0;
    do {
      bVar3 = in((short)uVar5);
      uVar6 = CONCAT71((int7)(uVar6 >> 8),bVar3);
      if (-1 < (char)bVar3) break;
      uVar6 = StorPortStallExecution(0x96);
      uVar12 = uVar12 + 1;
    } while (uVar12 < 20000);
    if ((((-1 < (char)bVar3) && ((bVar3 & 0x40) != 0)) && ((bVar3 & 1) == 0)) &&
       ((bVar3 & 0x20) == 0)) {
      *(undefined1 *)(param_1 + 0x4668 + uVar8) = *(undefined1 *)((longlong)param_2 + 0x96);
      if (*(char *)((longlong)param_2 + 0x96) == -0x30) {
        *(undefined8 *)(param_1 + 0x42f8 + uVar10 * 8) = param_2[0xc];
        *(undefined4 *)(param_1 + 0x42e0 + uVar10 * 4) = 0x100;
        *(undefined1 *)(param_1 + 0x42dc + uVar8) = 1;
        out(sVar11,cVar9);
        out(sVar2 + 1,*(undefined1 *)((longlong)param_2 + 0x96));
        uVar4 = 0;
        uVar7 = 0;
        out(sVar2 + 2,0);
      }
      else {
        bVar3 = *(char *)((longlong)param_2 + 0x96) + 0x2e;
        uVar6 = CONCAT71((int7)(uVar6 >> 8),bVar3);
        if ((8 < bVar3) || (uVar6 = 0x1c5, (0x1c5U >> (bVar3 & 0x1f) & 1) == 0)) {
          *(undefined1 *)((longlong)param_2 + 0x4b) = 6;
          goto LAB_000256fb;
        }
        *(undefined8 *)(param_1 + 0x42f8 + uVar10 * 8) = param_2[0xc];
        *(undefined4 *)(param_1 + 0x42e0 + uVar10 * 4) = 0;
        *(undefined1 *)(param_1 + 0x42dc + uVar8) = 1;
        out(sVar11,cVar9);
        out(sVar2 + 1,*(undefined1 *)((longlong)param_2 + 0x96));
        out(sVar2 + 2,*(undefined1 *)((longlong)param_2 + 0x97));
        uVar4 = *(undefined1 *)(param_2 + 0x13);
        uVar7 = 1;
      }
      out(sVar2 + 3,uVar4);
      out(sVar2 + 4,0x4f);
      out(sVar2 + 5,0xc2);
      out(sVar2 + 7,0xb0);
      *(undefined1 *)((longlong)param_2 + 0x4b) = 0;
      return (ulonglong)uVar7 << 8;
    }
    *(undefined1 *)((longlong)param_2 + 0x4b) = 4;
  }
LAB_000256fb:
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== DispatchTestDevReady @ 00025714 =====

undefined8 DispatchTestDevReady(longlong param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  
  uVar1 = IsDevReady(param_1,(uint)*(byte *)(param_2 + 0x4e),param_3);
  *(undefined1 *)(param_2 + 0x4b) = 1;
  if ((char)uVar1 == '\0') {
    *(undefined4 *)(*(longlong *)(param_2 + 0x10) + 0xf8) = 4;
  }
  else {
    uVar1 = *(ulonglong *)(param_2 + 0x10);
    *(undefined4 *)(uVar1 + 0xf8) = 1;
  }
  return CONCAT71((int7)(uVar1 >> 8),1);
}



===== GetDevExistStatus @ 00025754 =====

/* WARNING: Removing unreachable block (ram,0x000258b7) */

byte GetDevExistStatus(longlong param_1,uint param_2,undefined8 param_3)

{
  byte bVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint local_res10 [2];
  
  uVar2 = (ulonglong)param_2;
  uVar4 = (ulonglong)param_2;
  bVar1 = *(byte *)(uVar2 + 0x948 + param_1);
  if (((bVar1 == 0) || (*(int *)(param_1 + 0x90) == 2)) ||
     ((*(int *)(param_1 + 0x4834) != 0 && ((*(ushort *)(param_1 + 0xab8 + uVar2 * 2) & 0x2000) != 0)
      ))) {
LAB_00025779:
    bVar1 = 0;
  }
  else {
    if ((bVar1 & 2) == 0) {
      if ((bVar1 & 4) == 0) {
        uVar2 = IsDevReady(param_1,param_2,param_3);
        return ((char)uVar2 != '\0') + 1;
      }
      uVar3 = param_2 >> 1;
      lVar5 = ((longlong)(int)(uVar3 & 0x80000003) + 2) * 0x80 + *(longlong *)(param_1 + 0x58);
      bVar1 = *(byte *)(lVar5 + 0x28) & 0xf;
      if (bVar1 == 3) {
LAB_00025913:
        if ((bVar1 & 1) != 0) {
          if ((*(ushort *)(param_1 + 0xab8 + uVar4 * 2) & 0x2000) == 0) {
            return 3;
          }
          if (bVar1 == 3) {
            bVar1 = *(byte *)(lVar5 + 0x20);
            goto LAB_0002586b;
          }
          goto LAB_00025779;
        }
      }
      else if ((*(byte *)(lVar5 + 0x28) & 1) != 0) {
        if ((*(ushort *)(param_1 + 0xab8 + uVar4 * 2) & 0x2000) == 0) {
          AhciResetPort(param_1,uVar3,'\0');
          bVar1 = *(byte *)(lVar5 + 0x28) & 0xf;
        }
        else {
          AhciResetPort_for_ErrorDisk(param_1,uVar3);
          bVar1 = *(byte *)(lVar5 + 0x28) & 0xf;
          if (bVar1 == 0) {
            return 4;
          }
        }
        goto LAB_00025913;
      }
      if ((*(ushort *)(param_1 + 0xab8 + uVar4 * 2) & 0x2000) == 0) goto LAB_00025779;
      bVar1 = *(byte *)(param_1 + 0x100 + uVar4 * 4);
    }
    else {
      local_res10[0] = 0;
      ReadWriteHostSStatusRegister(param_1,param_2,param_3,local_res10);
      *(uint *)(param_1 + 0x100 + uVar2 * 4) = local_res10[0];
      if (((byte)local_res10[0] & 0xf) == 3) {
LAB_0002583d:
        if ((local_res10[0] & 1) != 0) {
          if ((*(ushort *)(param_1 + 0xab8 + uVar2 * 2) & 0x2000) == 0) {
            return 3;
          }
          if (((byte)local_res10[0] & 0xf) == 3) {
            bVar1 = in((short)*(undefined8 *)(param_1 + 0xc0 + (ulonglong)(param_2 >> 1) * 8));
LAB_0002586b:
            return ~-((bVar1 & 0x80) != 0) & 3;
          }
          goto LAB_00025779;
        }
      }
      else if ((local_res10[0] & 1) != 0) {
        if ((*(ushort *)(param_1 + 0xab8 + uVar2 * 2) & 0x2000) == 0) {
          CommReset(param_1,param_2);
          ReadWriteHostSStatusRegister(param_1,param_2,param_3,local_res10);
          *(uint *)(param_1 + 0x100 + uVar2 * 4) = local_res10[0];
        }
        else {
          CommReset_for_ErrorDisk(param_1,param_2);
          ReadWriteHostSStatusRegister(param_1,param_2,param_3,local_res10);
          *(uint *)(param_1 + 0x100 + uVar2 * 4) = local_res10[0];
          if ((local_res10[0] & 0xf) == 0) {
            return 4;
          }
        }
        goto LAB_0002583d;
      }
      if ((*(ushort *)(param_1 + 0xab8 + uVar2 * 2) & 0x2000) == 0) goto LAB_00025779;
      bVar1 = (byte)local_res10[0];
    }
    bVar1 = ~-((bVar1 & 0xf) != 0) & 4;
  }
  return bVar1;
}



===== IdeMediaStatus @ 00025984 =====

uint IdeMediaStatus(undefined8 param_1,longlong param_2,uint param_3)

{
  ushort *puVar1;
  uint uVar2;
  short sVar3;
  byte bVar4;
  undefined1 uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  uVar8 = (ulonglong)param_3;
  if ((*(byte *)(uVar8 + 0x948 + param_2) & 4) == 0) {
    sVar3 = (short)*(undefined8 *)(param_2 + 0xa0 + (ulonglong)(param_3 >> 1) * 8);
    uVar2 = CONCAT31((uint3)(param_3 >> 9),(char)param_3) & 0xffffff01;
    uVar6 = uVar2 | 0xa0;
    out(sVar3 + 6,(char)uVar6);
    if ((*(byte *)(param_2 + 0xab8 + uVar8 * 2) & 0x10) != 0) {
      out(sVar3 + 1,0x95);
      out(sVar3 + 7,0xef);
      uVar6 = CONCAT31((int3)(uVar2 >> 8),(char)param_3) & 0xffffff01 | 0xa0;
      uVar7 = (ulonglong)uVar6;
      out(sVar3 + 6,(char)uVar6);
      uVar6 = 0;
      do {
        bVar4 = in(sVar3 + 7);
        uVar7 = CONCAT71((int7)(uVar7 >> 8),bVar4);
        if (-1 < (char)bVar4) break;
        uVar7 = StorPortStallExecution(0x96);
        uVar6 = uVar6 + 1;
      } while (uVar6 < 20000);
      uVar6 = (uint)uVar7;
      if ((bVar4 & 1) == 0) {
        puVar1 = (ushort *)(param_2 + 0xab8 + uVar8 * 2);
        *puVar1 = *puVar1 | 0x20;
        *(undefined1 *)(uVar8 + 0x84 + param_2) = 0;
      }
      else {
        uVar5 = in(sVar3 + 1);
        uVar6 = (uint)CONCAT71((int7)(uVar7 >> 8),uVar5);
      }
    }
  }
  else {
    uVar6 = AhciIdeMediaStatus(param_1,param_2,param_3);
  }
  return uVar6;
}



===== DisableDevIPM @ 00025a64 =====

undefined8 DisableDevIPM(longlong param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  longlong lVar4;
  undefined7 uVar6;
  undefined8 uVar5;
  short sVar7;
  char cVar8;
  longlong lVar9;
  
  lVar9 = (longlong)param_2;
  lVar4 = 0;
  if (((*(ushort *)(param_1 + 0xab8 + lVar9 * 2) & 0x200) != 0) &&
     (lVar4 = lVar9 * 0xd4, (*(byte *)(lVar4 + 0xde4 + param_1) & 8) != 0)) {
    bVar1 = *(byte *)(lVar9 + 0x948 + param_1);
    uVar6 = (undefined7)((ulonglong)lVar4 >> 8);
    lVar4 = CONCAT71(uVar6,bVar1);
    if ((bVar1 & 2) != 0) {
      cVar8 = ((byte)param_2 & 1 | 0xfa) << 4;
      sVar2 = (short)*(undefined8 *)(param_1 + 0xa0 + (lVar9 >> 1) * 8);
      out(sVar2 + 6,cVar8);
      cVar3 = in((short)*(undefined8 *)(param_1 + 0xc0 + (lVar9 >> 1) * 8));
      if (-1 < cVar3) {
        sVar7 = sVar2 + 7;
        in(sVar7);
        out(sVar2 + 1,0x90);
        out(sVar2 + 2,3);
        out(sVar7,0xef);
        out(sVar2 + 6,cVar8);
        in(sVar7);
      }
      return CONCAT71(uVar6,-1 < cVar3);
    }
    if ((bVar1 & 4) != 0) {
      uVar5 = AhciDisableDevIPM(param_1,param_2);
      return uVar5;
    }
  }
  return CONCAT62((int6)((ulonglong)lVar4 >> 0x10),1);
}



===== DispatchIdeTestUnitReady @ 00025b24 =====

undefined8 DispatchIdeTestUnitReady(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  short sVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined7 extraout_var;
  undefined7 uVar6;
  undefined7 extraout_var_00;
  uint uVar7;
  char cVar8;
  
  bVar4 = *(byte *)(param_2 + 0x4e);
  uVar5 = (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1);
  uVar1 = *(undefined8 *)(param_1 + 0xa0 + uVar5 * 8);
  uVar2 = *(undefined8 *)(param_1 + 0xc0 + uVar5 * 8);
  uVar7 = 0;
  *(undefined1 *)((ulonglong)(bVar4 >> 1) + 0x42dc + param_1) = 0;
  sVar3 = (short)uVar1;
  cVar8 = (bVar4 & 1 | 0xfa) << 4;
  out(sVar3 + 6,cVar8);
  out(sVar3 + 7,0xda);
  uVar6 = 0;
  out(sVar3 + 6,cVar8);
  do {
    bVar4 = in((short)uVar2);
    if (-1 < (char)bVar4) break;
    StorPortStallExecution(0x96);
    uVar7 = uVar7 + 1;
    uVar6 = extraout_var;
  } while (uVar7 < 20000);
  if ((bVar4 & 1) != 0) {
    cVar8 = in(sVar3 + 1);
    in(sVar3 + 7);
    if (cVar8 != '@') {
      bVar4 = MapError(param_1,param_2 + 0x48);
      uVar6 = extraout_var_00;
      goto LAB_00025be2;
    }
  }
  bVar4 = 1;
LAB_00025be2:
  *(byte *)(param_2 + 0x4b) = bVar4;
  return CONCAT71(uVar6,1);
}



===== ParseStartStopUnit @ 00025c08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint ParseStartStopUnit(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  byte bVar2;
  ulonglong uVar3;
  void *pvVar4;
  undefined8 *puVar5;
  char cVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  code *pcVar11;
  byte bVar12;
  int *piVar13;
  undefined4 uVar14;
  int iVar15;
  ulonglong *puVar16;
  ushort *puVar17;
  ulonglong uVar18;
  undefined1 auStack_78 [32];
  byte local_58;
  char local_57;
  byte local_56;
  uint local_54;
  longlong local_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_78;
  lVar1 = *(longlong *)(param_2 + 0xf0);
  local_54 = (uint)*(byte *)(lVar1 + 3);
  uVar18 = (ulonglong)*(byte *)(lVar1 + 6);
  local_48 = uVar18;
  uVar14 = 0;
  local_56 = *(byte *)(param_1 + uVar18 * 5 + 299);
  bVar2 = *(byte *)(lVar1 + 0x4c);
  local_58 = 0;
  local_57 = '\0';
  bVar12 = bVar2 >> 4;
  local_50 = param_2;
  if (bVar12 == 0) {
    if ((bVar2 & 2) != 0) {
      if ((bVar2 & 2) == 0) {
        uVar9 = 1;
        *(undefined4 *)(param_2 + 0xfc) = 1;
        *(undefined4 *)(param_2 + 0xf8) = 1;
      }
      else if ((*(byte *)((longlong)param_1 + (ulonglong)local_56 * 2 + 0xab8) & 0x20) == 0) {
        *(undefined4 *)(param_2 + 0xfc) = 1;
        *(undefined4 *)(param_2 + 0xf8) = 6;
        uVar9 = 6;
      }
      else {
        pcVar11 = (code *)&DispatchMediaEject;
        if ((*(byte *)((ulonglong)local_56 + 0x948 + (longlong)param_1) & 4) != 0) {
          pcVar11 = AhciDispatchMediaEject;
        }
        bVar2 = ParseIdeSimpleCmd((longlong)param_1,param_2,pcVar11);
        uVar9 = (uint)bVar2;
      }
      return uVar9;
    }
    if ((bVar2 & 1) == 0) {
      local_58 = 0xe0;
      uVar14 = 2;
    }
  }
  else if (bVar12 != 1) {
    if (bVar12 == 2) {
      cVar6 = *(char *)(lVar1 + 0x49);
      uVar14 = 1;
    }
    else {
      if (bVar12 != 3) {
        if (bVar12 == 4) {
          uVar14 = 4;
          local_58 = 0xe6;
        }
        goto LAB_00025d54;
      }
      cVar6 = *(char *)(lVar1 + 0x49);
      uVar14 = 2;
    }
    local_58 = ~(cVar6 * '\x02') & 2U | 0xe0;
  }
LAB_00025d54:
  iVar15 = 0;
  puVar17 = (ushort *)(param_1 + 0x157);
  piVar13 = (int *)(param_1 + 0x71);
  uVar10 = 0;
  do {
    uVar8 = uVar10;
    if ((((*puVar17 & 1) != 0) && ((*puVar17 & 2) == 0)) &&
       (uVar3 = CheckDeviceCheckSum((longlong)(param_1 + uVar18 * 5 + 299),piVar13),
       (char)uVar3 != '\0')) {
      uVar8 = (ulonglong)(byte)((char)uVar10 + 1);
      *(char *)((longlong)&local_48 + uVar10) = (char)iVar15;
    }
    lVar1 = local_50;
    bVar2 = local_58;
    iVar15 = iVar15 + 1;
    puVar17 = puVar17 + 1;
    piVar13 = piVar13 + 0x2e;
    uVar10 = uVar8;
  } while (iVar15 < 8);
  uVar9 = *(uint *)((longlong)param_1 + (ulonglong)local_56 * 4 + 0xae0);
  puVar5 = (undefined8 *)(ulonglong)uVar9;
  iVar15 = (int)uVar8;
  if ((((uVar9 & 4) != 0) && (bVar12 != 4)) && (iVar15 != 0)) {
    puVar16 = &local_48;
    uVar18 = uVar8;
    do {
      bVar12 = (byte)*puVar16;
      puVar5 = param_1;
      if ((*(byte *)((ulonglong)bVar12 + 0x948 + (longlong)param_1) & 4) == 0) {
        CommReset((longlong)param_1,(uint)bVar12);
      }
      else {
        AhciResetPort((longlong)param_1,(uint)(bVar12 >> 1),'\0');
      }
      puVar16 = (ulonglong *)((longlong)puVar16 + 1);
      uVar18 = uVar18 - 1;
    } while (uVar18 != 0);
  }
  if ((bVar2 == 0) || ((char)uVar8 == '\0')) {
    if (iVar15 != 0) {
      puVar16 = &local_48;
      do {
        uVar18 = *puVar16;
        puVar16 = (ulonglong *)((longlong)puVar16 + 1);
        *(undefined4 *)((longlong)param_1 + (ulonglong)(byte)uVar18 * 4 + 0xae0) = uVar14;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    *(undefined4 *)(lVar1 + 0xfc) = 1;
    *(undefined4 *)(lVar1 + 0xf8) = 1;
    local_54 = 1;
  }
  else {
    iVar7 = 0;
    if (iVar15 == 0) {
      cVar6 = '\0';
    }
    else {
      do {
        puVar5 = (undefined8 *)(ulonglong)*(byte *)((longlong)&local_48 + (longlong)iVar7);
        if (*(int *)((longlong)param_1 + (longlong)puVar5 * 4 + 0xae0) == 0) {
          cVar6 = '\x01';
          local_57 = '\x01';
          goto LAB_00025e59;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar15);
      cVar6 = '\0';
    }
LAB_00025e59:
    iVar7 = 0;
    if (iVar15 != 0) {
      do {
        bVar2 = *(byte *)((longlong)&local_48 + (longlong)iVar7);
        if (*(int *)((longlong)param_1 + (ulonglong)bVar2 * 4 + 0xae0) == 0) {
          pvVar4 = StorAllocateSubCmd(puVar5,lVar1);
          if (pvVar4 != (void *)0x0) {
            memset(pvVar4,0,0xc0);
            puVar5 = *(undefined8 **)(lVar1 + 0xf0);
            if ((undefined8 *)((longlong)pvVar4 + 0x48) != puVar5) {
              *(undefined8 *)((longlong)pvVar4 + 0x48) = *puVar5;
              *(undefined8 *)((longlong)pvVar4 + 0x50) = puVar5[1];
              *(undefined8 *)((longlong)pvVar4 + 0x58) = puVar5[2];
              *(undefined8 *)((longlong)pvVar4 + 0x60) = puVar5[3];
              *(undefined8 *)((longlong)pvVar4 + 0x68) = puVar5[4];
              *(undefined8 *)((longlong)pvVar4 + 0x70) = puVar5[5];
              *(undefined8 *)((longlong)pvVar4 + 0x78) = puVar5[6];
              *(undefined8 *)((longlong)pvVar4 + 0x80) = puVar5[7];
              *(undefined8 *)((longlong)pvVar4 + 0x88) = puVar5[8];
              *(undefined8 *)((longlong)pvVar4 + 0x90) = puVar5[9];
              *(undefined8 *)((longlong)pvVar4 + 0x98) = puVar5[10];
            }
            puVar5 = (undefined8 *)0x0;
            *(undefined4 *)((longlong)pvVar4 + 0x54) = 1;
            *(byte *)((longlong)pvVar4 + 0x4e) = bVar2;
            *(longlong *)((longlong)pvVar4 + 0x10) = lVar1;
            *(undefined1 *)((longlong)pvVar4 + 0x4b) = 0;
            *(undefined4 *)((longlong)pvVar4 + 0xa0) = 0;
            *(undefined8 *)((longlong)pvVar4 + 0x30) = 0;
            *(code **)((longlong)pvVar4 + 0x18) = DispatchSyncCache;
            *(int *)(lVar1 + 0x10c) = *(int *)(lVar1 + 0x10c) + 1;
            if (*(int *)(lVar1 + 0xea4) != 0) {
              puVar5 = *(undefined8 **)(*(longlong *)(lVar1 + 0xf0) + 0x38);
              puVar5[(ulonglong)*(byte *)(puVar5 + 0x4f) + 0xf] = pvVar4;
              *(char *)(puVar5 + 0x4f) = *(char *)(puVar5 + 0x4f) + '\x01';
            }
            goto LAB_00025f56;
          }
LAB_000260a4:
          *(undefined4 *)(lVar1 + 0xfc) = 2;
          *(undefined1 *)(lVar1 + 0x100) = 2;
          goto LAB_000260eb;
        }
LAB_00025f56:
        pvVar4 = StorAllocateSubCmd(puVar5,lVar1);
        if (pvVar4 == (void *)0x0) goto LAB_000260a4;
        *(longlong *)((longlong)pvVar4 + 0x10) = lVar1;
        *(uint *)((longlong)pvVar4 + 0xa0) = (uint)(local_57 != '\0');
        bVar12 = *(byte *)((ulonglong)bVar2 + 0x948 + (longlong)param_1);
        pcVar11 = DispatchPowerConditionChange;
        *(undefined8 *)((longlong)pvVar4 + 0x30) = 0;
        if ((bVar12 & 4) != 0) {
          pcVar11 = AhciDispatchPowerConditionChange;
        }
        *(code **)((longlong)pvVar4 + 0x18) = pcVar11;
        puVar5 = *(undefined8 **)(lVar1 + 0xf0);
        if ((undefined8 *)((longlong)pvVar4 + 0x48) != puVar5) {
          *(undefined8 *)((longlong)pvVar4 + 0x48) = *puVar5;
          *(undefined8 *)((longlong)pvVar4 + 0x50) = puVar5[1];
          *(undefined8 *)((longlong)pvVar4 + 0x58) = puVar5[2];
          *(undefined8 *)((longlong)pvVar4 + 0x60) = puVar5[3];
          *(undefined8 *)((longlong)pvVar4 + 0x68) = puVar5[4];
          *(undefined8 *)((longlong)pvVar4 + 0x70) = puVar5[5];
          *(undefined8 *)((longlong)pvVar4 + 0x78) = puVar5[6];
          *(undefined8 *)((longlong)pvVar4 + 0x80) = puVar5[7];
          *(undefined8 *)((longlong)pvVar4 + 0x88) = puVar5[8];
          *(undefined8 *)((longlong)pvVar4 + 0x90) = puVar5[9];
          *(undefined8 *)((longlong)pvVar4 + 0x98) = puVar5[10];
        }
        *(undefined1 *)((longlong)pvVar4 + 0x4b) = 0;
        *(byte *)((longlong)pvVar4 + 0x4e) = bVar2;
        *(byte *)((longlong)pvVar4 + 0x90) = local_58;
        if (local_57 == '\0') {
          *(int *)(lVar1 + 0x10c) = *(int *)(lVar1 + 0x10c) + 1;
        }
        else {
          *(int *)(lVar1 + 0x110) = *(int *)(lVar1 + 0x110) + 1;
        }
        if (*(int *)(lVar1 + 0xea4) != 0) {
          puVar5 = *(undefined8 **)(*(longlong *)(lVar1 + 0xf0) + 0x38);
          puVar5[(ulonglong)*(byte *)(puVar5 + 0x4f) + 0xf] = pvVar4;
          *(char *)(puVar5 + 0x4f) = *(char *)(puVar5 + 0x4f) + '\x01';
        }
        iVar7 = iVar7 + 1;
        cVar6 = local_57;
      } while (iVar7 < iVar15);
    }
    *(undefined4 *)(lVar1 + 0x108) = 0;
    *(undefined4 *)(lVar1 + 0xfc) = 0;
    *(uint *)(lVar1 + 0x104) = (cVar6 != '\0') + 1;
    if (iVar15 != 0) {
      puVar16 = &local_48;
      do {
        uVar18 = *puVar16;
        puVar16 = (ulonglong *)((longlong)puVar16 + 1);
        *(undefined4 *)((longlong)param_1 + (ulonglong)(byte)uVar18 * 4 + 0xae0) = uVar14;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
  }
LAB_000260eb:
  return local_54;
}



===== DispatchPowerConditionChange @ 00026110 =====

undefined8 DispatchPowerConditionChange(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  byte bVar2;
  undefined8 uVar3;
  short sVar4;
  char cVar5;
  undefined7 extraout_var;
  longlong lVar6;
  ulonglong uVar7;
  short sVar8;
  
  uVar1 = *(undefined1 *)(param_2 + 0x90);
  uVar3 = *(undefined8 *)(param_1 + 0xa0 + (ulonglong)(*(byte *)(param_2 + 0x4e) >> 1) * 8);
  bVar2 = *(byte *)(param_2 + 0x4e);
  lVar6 = *(longlong *)(param_2 + 0x10);
  if ((*(byte *)(lVar6 + 0xea8 + (ulonglong)bVar2) & 1) != 0) {
    cVar5 = FlushCacheToHDD(param_1,bVar2,0,'\x01');
    lVar6 = CONCAT71(extraout_var,cVar5);
    if (cVar5 != '\0') goto LAB_0002619e;
  }
  *(undefined1 *)((ulonglong)(bVar2 >> 1) + 0x42dc + param_1) = 1;
  uVar7 = CONCAT71((int7)((ulonglong)lVar6 >> 8),*(undefined1 *)(param_2 + 0x4e)) &
          0xffffffffffffff01;
  sVar4 = (short)uVar3;
  sVar8 = sVar4 + 6;
  out(sVar8,((byte)uVar7 | 0xfa) << 4);
  out(sVar4 + 7,uVar1);
  uVar7 = CONCAT71((int7)(uVar7 >> 8),*(undefined1 *)(param_2 + 0x4e)) & 0xffffffffffffff01;
  cVar5 = ((byte)uVar7 | 0xfa) << 4;
  lVar6 = CONCAT71((int7)(uVar7 >> 8),cVar5);
  out(sVar8,cVar5);
LAB_0002619e:
  *(undefined1 *)(param_2 + 0x4b) = 0;
  return CONCAT71((int7)((ulonglong)lVar6 >> 8),1);
}



===== IsDevReady @ 00026214 =====

ulonglong IsDevReady(longlong param_1,uint param_2,undefined8 param_3)

{
  ushort uVar1;
  uint3 uVar2;
  short sVar3;
  byte bVar4;
  char cVar5;
  undefined4 uVar6;
  undefined8 in_RAX;
  ulonglong uVar7;
  undefined4 extraout_var;
  short sVar8;
  char cVar9;
  ulonglong uVar10;
  uint local_res10 [2];
  
  uVar10 = (ulonglong)param_2;
  bVar4 = *(byte *)(uVar10 + 0x948 + param_1);
  uVar7 = CONCAT71((int7)((ulonglong)in_RAX >> 8),bVar4);
  if (bVar4 == 0) goto LAB_00026329;
  if ((bVar4 & 4) != 0) {
    uVar7 = AhciIsDevReady(param_1,param_2);
    return uVar7;
  }
  if (bVar4 == 2) {
    ReadWriteHostSStatusRegister(param_1,param_2,param_3,local_res10);
    *(uint *)(param_1 + 0x100 + uVar10 * 4) = local_res10[0];
    uVar7 = 0;
    if ((((byte)local_res10[0] & 0xf) != 3) && ((local_res10[0] & 1) != 0)) {
      uVar1 = *(ushort *)(param_1 + 0xab8 + uVar10 * 2);
      if (((uVar1 & 0x2000) == 0) && ((uVar1 & 0x8000) == 0)) {
        CommReset(param_1,param_2);
      }
      uVar7 = ReadWriteHostSStatusRegister(param_1,param_2,param_3,local_res10);
      *(uint *)(param_1 + 0x100 + uVar10 * 4) = local_res10[0];
    }
    if (((byte)local_res10[0] & 0xf) != 3) goto LAB_00026329;
    if (*(char *)(param_1 + 0x2c) != '\0') {
      uVar6 = ReadWriteHostSErrorRegister(param_1,param_2,'\x01',local_res10);
      uVar7 = CONCAT44(extraout_var,uVar6);
      if (local_res10[0] != 0) goto LAB_00026329;
    }
  }
  sVar3 = (short)*(undefined8 *)(param_1 + 0xa0 + (ulonglong)(param_2 >> 1) * 8);
  sVar8 = sVar3 + 6;
  cVar9 = ((byte)param_2 & 1 | 0xfa) * '\x10';
  uVar2 = (uint3)(param_2 >> 9);
  out(sVar8,cVar9);
  bVar4 = in((short)*(undefined8 *)(param_1 + 0xc0 + (ulonglong)(param_2 >> 1) * 8));
  uVar7 = (ulonglong)CONCAT31(uVar2,bVar4);
  uVar1 = *(ushort *)(param_1 + 0xab8 + (ulonglong)param_2 * 2);
  if ((uVar1 & 1) == 0) {
    if (*(char *)((ulonglong)param_2 + 0x948 + param_1) != '\x02') goto LAB_00026345;
  }
  else if ((uVar1 & 2) == 0) {
LAB_00026345:
    if ((bVar4 & 0x40) == 0) goto LAB_00026329;
  }
  if ((-1 < (char)bVar4) && ((bVar4 & 0x20) == 0)) {
    out(sVar8,cVar9);
    cVar5 = in(sVar8);
    uVar7 = (ulonglong)CONCAT31(uVar2,cVar5);
    if (cVar5 == cVar9) {
      out(sVar3 + 4,0xa5);
      cVar9 = in(sVar3 + 4);
      uVar7 = (ulonglong)CONCAT31(uVar2,cVar9);
      if (cVar9 == -0x5b) {
        out(sVar3 + 5,0xa5);
        cVar9 = in(sVar3 + 5);
        return (ulonglong)CONCAT31(uVar2,cVar9 == -0x5b);
      }
    }
  }
LAB_00026329:
  return uVar7 & 0xffffffffffffff00;
}



===== DispatchIoctlIdentify @ 00026378 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DispatchIoctlIdentify(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte bVar1;
  longlong lVar2;
  char cVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 auStack_238 [32];
  undefined2 local_218 [256];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_238;
  lVar2 = *(longlong *)(param_2 + 0x10);
  bVar1 = *(byte *)(param_2 + 0x4e);
  if ((*(byte *)((ulonglong)bVar1 + 0x948 + param_1) & 4) == 0) {
    lVar5 = LegacyIssueIdentifyCmd
                      (param_1,(uint)bVar1,
                       CONCAT71((int7)((ulonglong)param_3 >> 8),*(char *)(param_2 + 0x90)),local_218
                      );
    cVar3 = (char)lVar5;
  }
  else {
    uVar4 = AhciIssueIdentifyCmd(param_1,(ulonglong)bVar1,*(char *)(param_2 + 0x90),local_218);
    cVar3 = (char)uVar4;
  }
  if (cVar3 == '\0') {
    *(undefined1 *)(param_2 + 0x4b) = 4;
  }
  else {
    if (*(undefined2 **)(param_2 + 0x60) != local_218) {
      memcpy(*(undefined2 **)(param_2 + 0x60),local_218,(ulonglong)*(uint *)(param_2 + 0x58));
    }
    *(int *)(*(longlong *)(lVar2 + 0xf0) + 0x10) = *(int *)(param_2 + 0x58) + 0x2c;
    *(undefined1 *)(param_2 + 0x4b) = 1;
  }
  return;
}



===== RaidSpanCommand @ 00026420 =====

undefined8 RaidSpanCommand(longlong param_1,undefined8 *param_2,longlong param_3)

{
  byte bVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  void *_Dst;
  undefined8 local_res8;
  int local_res10;
  undefined4 uStackX_14;
  uint local_res18;
  longlong local_res20;
  
  local_res20 = param_2[3];
  bVar1 = *(byte *)((longlong)param_2 + 6);
  uVar9 = (ulonglong)bVar1;
  lVar2 = param_2[7];
  uVar4 = GetStartEndFromSrb((longlong)param_2,(ulonglong *)&local_res10,&local_res8,
                             *(int *)(param_3 + 0xe98));
  uVar7 = (uint)bVar1;
  if (uVar7 != 0xff) {
    uVar10 = CONCAT44(uStackX_14,local_res10);
    local_res8._0_2_ = 0;
    while( true ) {
      uVar8 = CONCAT44(*(undefined4 *)(uVar9 * 0xd4 + 0xddc + param_1),
                       *(undefined4 *)(uVar9 * 0xd4 + 0xd8c + param_1)) - 1;
      if (uVar10 < uVar8) break;
      uVar4 = (ulonglong)uVar7 * 0xb8;
      uVar7 = *(uint *)(uVar4 + 0x3b0 + param_1) >> 8 & 0xf;
      uVar9 = (ulonglong)uVar7;
      if (uVar7 == 0xf) goto LAB_0002688a;
      uVar10 = uVar10 - uVar8;
    }
    local_res10 = *(int *)(param_2 + 2);
    if (uVar8 < (local_res10 + 0x1ffU >> 9) + uVar10) {
      iVar6 = (int)uVar8 - (int)uVar10;
      uVar7 = iVar6 * 0x200;
      local_res18 = *(uint *)(uVar9 * 0xb8 + 0x3b0 + param_1) >> 8 & 0xf;
      uVar4 = 0;
      if (local_res18 == 0xf) goto LAB_0002688a;
      uVar3 = *(byte *)(lVar2 + 0x279) + 2;
      uVar4 = (ulonglong)uVar3;
      if ((uVar3 < 0x29) &&
         (uVar4 = StorAllocateMultiPool(lVar2,2,(longlong)&local_res8), (char)uVar4 != '\0')) {
        _Dst = (void *)((ulonglong)(byte)local_res8 * 0xc0 + *(longlong *)(lVar2 + 0x50));
        pvVar5 = (void *)((ulonglong)local_res8._1_1_ * 0xc0 + *(longlong *)(lVar2 + 0x50));
        memset(_Dst,0,0xc0);
        memset(pvVar5,0,0xc0);
        if ((undefined8 *)((longlong)_Dst + 0x48) != param_2) {
          *(undefined8 *)((longlong)_Dst + 0x48) = *param_2;
          *(undefined8 *)((longlong)_Dst + 0x50) = param_2[1];
          *(undefined8 *)((longlong)_Dst + 0x58) = param_2[2];
          *(undefined8 *)((longlong)_Dst + 0x60) = param_2[3];
          *(undefined8 *)((longlong)_Dst + 0x68) = param_2[4];
          *(undefined8 *)((longlong)_Dst + 0x70) = param_2[5];
          *(undefined8 *)((longlong)_Dst + 0x78) = param_2[6];
          *(undefined8 *)((longlong)_Dst + 0x80) = param_2[7];
          *(undefined8 *)((longlong)_Dst + 0x88) = param_2[8];
          *(undefined8 *)((longlong)_Dst + 0x90) = param_2[9];
          *(undefined8 *)((longlong)_Dst + 0x98) = param_2[10];
        }
        if ((undefined8 *)((longlong)pvVar5 + 0x48) != param_2) {
          *(undefined8 *)((longlong)pvVar5 + 0x48) = *param_2;
          *(undefined8 *)((longlong)pvVar5 + 0x50) = param_2[1];
          *(undefined8 *)((longlong)pvVar5 + 0x58) = param_2[2];
          *(undefined8 *)((longlong)pvVar5 + 0x60) = param_2[3];
          *(undefined8 *)((longlong)pvVar5 + 0x68) = param_2[4];
          *(undefined8 *)((longlong)pvVar5 + 0x70) = param_2[5];
          *(undefined8 *)((longlong)pvVar5 + 0x78) = param_2[6];
          *(undefined8 *)((longlong)pvVar5 + 0x80) = param_2[7];
          *(undefined8 *)((longlong)pvVar5 + 0x88) = param_2[8];
          *(undefined8 *)((longlong)pvVar5 + 0x90) = param_2[9];
          *(undefined8 *)((longlong)pvVar5 + 0x98) = param_2[10];
        }
        if (*(char *)(param_3 + 0x102) == '\x01') {
          *(undefined4 *)((longlong)_Dst + 0xa4) = 1;
          *(undefined4 *)((longlong)pvVar5 + 0xa4) = 1;
        }
        *(undefined8 *)(param_3 + 0x104) = 1;
        *(undefined4 *)(param_3 + 0xfc) = 0;
        *(longlong *)((longlong)_Dst + 0x60) = local_res20;
        *(longlong *)((longlong)_Dst + 0x10) = param_3;
        *(undefined4 *)((longlong)_Dst + 0xa0) = 0;
        *(code **)((longlong)_Dst + 0x18) = DispatchDiskReadWrite;
        *(ulonglong *)((longlong)_Dst + 0x40) = uVar10;
        *(char *)((longlong)_Dst + 0x4e) = (char)uVar9;
        *(uint *)((longlong)_Dst + 0x58) = uVar7;
        *(undefined8 *)((longlong)_Dst + 0x30) = 0;
        *(undefined4 *)((longlong)_Dst + 0x38) = *(undefined4 *)(param_3 + 0xe98);
        if (*(int *)(param_3 + 0xea4) != 0) {
          lVar2 = *(longlong *)(*(longlong *)(param_3 + 0xf0) + 0x38);
          *(void **)(lVar2 + 0x78 + (ulonglong)*(byte *)(lVar2 + 0x278) * 8) = _Dst;
          *(char *)(lVar2 + 0x278) = *(char *)(lVar2 + 0x278) + '\x01';
        }
        *(undefined4 *)(param_3 + 0x10c) = 1;
        *(longlong *)((longlong)pvVar5 + 0x10) = param_3;
        *(char *)((longlong)pvVar5 + 0x4e) = (char)local_res18;
        *(undefined4 *)((longlong)pvVar5 + 0xa0) = 0;
        *(code **)((longlong)pvVar5 + 0x18) = DispatchDiskReadWrite;
        *(undefined8 *)((longlong)pvVar5 + 0x40) = 0;
        *(int *)((longlong)pvVar5 + 0x58) = local_res10 + iVar6 * -0x200;
        *(undefined8 *)((longlong)pvVar5 + 0x30) = 0;
        *(ulonglong *)((longlong)pvVar5 + 0x60) = (ulonglong)uVar7 + local_res20;
        uVar4 = (ulonglong)*(uint *)(param_3 + 0xe98);
        *(uint *)((longlong)pvVar5 + 0x38) = *(uint *)(param_3 + 0xe98);
        if (*(int *)(param_3 + 0xea4) != 0) {
          lVar2 = *(longlong *)(*(longlong *)(param_3 + 0xf0) + 0x38);
          uVar4 = (ulonglong)*(byte *)(lVar2 + 0x278);
          *(void **)(lVar2 + 0x78 + uVar4 * 8) = pvVar5;
          *(char *)(lVar2 + 0x278) = *(char *)(lVar2 + 0x278) + '\x01';
        }
        *(undefined4 *)(param_3 + 0x10c) = 2;
LAB_00026875:
        return uVar4 & 0xffffffffffffff00;
      }
    }
    else {
      bVar1 = *(byte *)(lVar2 + 0x279);
      uVar4 = (ulonglong)(bVar1 + 1);
      if (bVar1 + 1 < 0x29) {
        uVar4 = (ulonglong)(bVar1 + 1);
        *(char *)(lVar2 + 0x279) = (char)(bVar1 + 1);
        if (bVar1 != 0xffffffff) {
          pvVar5 = (void *)((ulonglong)bVar1 * 0xc0 + *(longlong *)(lVar2 + 0x50));
          memset(pvVar5,0,0xc0);
          if ((undefined8 *)((longlong)pvVar5 + 0x48) != param_2) {
            *(undefined8 *)((longlong)pvVar5 + 0x48) = *param_2;
            *(undefined8 *)((longlong)pvVar5 + 0x50) = param_2[1];
            *(undefined8 *)((longlong)pvVar5 + 0x58) = param_2[2];
            *(undefined8 *)((longlong)pvVar5 + 0x60) = param_2[3];
            *(undefined8 *)((longlong)pvVar5 + 0x68) = param_2[4];
            *(undefined8 *)((longlong)pvVar5 + 0x70) = param_2[5];
            *(undefined8 *)((longlong)pvVar5 + 0x78) = param_2[6];
            *(undefined8 *)((longlong)pvVar5 + 0x80) = param_2[7];
            *(undefined8 *)((longlong)pvVar5 + 0x88) = param_2[8];
            *(undefined8 *)((longlong)pvVar5 + 0x90) = param_2[9];
            *(undefined8 *)((longlong)pvVar5 + 0x98) = param_2[10];
          }
          if (*(char *)(param_3 + 0x102) == '\x01') {
            *(undefined4 *)((longlong)pvVar5 + 0xa4) = 1;
          }
          *(undefined4 *)(param_3 + 0xfc) = 0;
          *(undefined8 *)(param_3 + 0x104) = 1;
          *(longlong *)((longlong)pvVar5 + 0x10) = param_3;
          *(undefined4 *)((longlong)pvVar5 + 0xa0) = 0;
          *(ulonglong *)((longlong)pvVar5 + 0x40) = uVar10;
          *(char *)((longlong)pvVar5 + 0x4e) = (char)uVar9;
          *(undefined8 *)((longlong)pvVar5 + 0x30) = 0;
          *(code **)((longlong)pvVar5 + 0x18) = DispatchDiskReadWrite;
          uVar4 = (ulonglong)*(uint *)(param_3 + 0xe98);
          *(uint *)((longlong)pvVar5 + 0x38) = *(uint *)(param_3 + 0xe98);
          if (*(int *)(param_3 + 0xea4) != 0) {
            lVar2 = *(longlong *)(*(longlong *)(param_3 + 0xf0) + 0x38);
            uVar4 = (ulonglong)*(byte *)(lVar2 + 0x278);
            *(void **)(lVar2 + 0x78 + uVar4 * 8) = pvVar5;
            *(char *)(lVar2 + 0x278) = *(char *)(lVar2 + 0x278) + '\x01';
          }
          *(undefined4 *)(param_3 + 0x10c) = 1;
          goto LAB_00026875;
        }
      }
    }
    *(undefined1 *)(param_3 + 0x100) = 2;
    *(undefined4 *)(param_3 + 0xfc) = 2;
  }
LAB_0002688a:
  return CONCAT71((int7)(uVar4 >> 8),4);
}



===== Raid1Command @ 0002689c =====

undefined8 Raid1Command(longlong param_1,undefined8 *param_2,longlong param_3)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  void *_Dst;
  void *_Dst_00;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  undefined2 local_res10;
  ulonglong local_res18 [2];
  
  uVar5 = (ulonglong)*(byte *)((longlong)param_2 + 6);
  lVar4 = param_2[7];
  _Dst = (void *)0x0;
  lVar6 = param_1;
  uVar3 = GetStartEndFromSrb((longlong)param_2,local_res18,(longlong *)&local_res10,
                             *(int *)(param_3 + 0xe98));
  if ((int)uVar5 == 0xff) goto LAB_00026c6a;
  uVar7 = *(uint *)(uVar5 * 0xb8 + 0x3b0 + lVar6) >> 8 & 0xf;
  if (((char)*(undefined4 *)((longlong)param_2 + 0xc) < '\0') && (uVar7 != 0xf)) {
    local_res10 = 0;
    uVar2 = *(byte *)(lVar4 + 0x279) + 2;
    uVar3 = (ulonglong)uVar2;
    if ((uVar2 < 0x29) &&
       (uVar3 = StorAllocateMultiPool(lVar4,2,(longlong)&local_res10), (char)uVar3 != '\0')) {
      _Dst_00 = (void *)((ulonglong)(byte)local_res10 * 0xc0 + *(longlong *)(lVar4 + 0x50));
      _Dst = (void *)((ulonglong)local_res10._1_1_ * 0xc0 + *(longlong *)(lVar4 + 0x50));
      memset(_Dst_00,0,0xc0);
      memset(_Dst,0,0xc0);
      if ((undefined8 *)((longlong)_Dst_00 + 0x48) != param_2) {
        *(undefined8 *)((longlong)_Dst_00 + 0x48) = *param_2;
        *(undefined8 *)((longlong)_Dst_00 + 0x50) = param_2[1];
        *(undefined8 *)((longlong)_Dst_00 + 0x58) = param_2[2];
        *(undefined8 *)((longlong)_Dst_00 + 0x60) = param_2[3];
        *(undefined8 *)((longlong)_Dst_00 + 0x68) = param_2[4];
        *(undefined8 *)((longlong)_Dst_00 + 0x70) = param_2[5];
        *(undefined8 *)((longlong)_Dst_00 + 0x78) = param_2[6];
        *(undefined8 *)((longlong)_Dst_00 + 0x80) = param_2[7];
        *(undefined8 *)((longlong)_Dst_00 + 0x88) = param_2[8];
        *(undefined8 *)((longlong)_Dst_00 + 0x90) = param_2[9];
        *(undefined8 *)((longlong)_Dst_00 + 0x98) = param_2[10];
      }
      if ((undefined8 *)((longlong)_Dst + 0x48) != param_2) {
        *(undefined8 *)((longlong)_Dst + 0x48) = *param_2;
        *(undefined8 *)((longlong)_Dst + 0x50) = param_2[1];
        *(undefined8 *)((longlong)_Dst + 0x58) = param_2[2];
        *(undefined8 *)((longlong)_Dst + 0x60) = param_2[3];
        *(undefined8 *)((longlong)_Dst + 0x68) = param_2[4];
        *(undefined8 *)((longlong)_Dst + 0x70) = param_2[5];
        *(undefined8 *)((longlong)_Dst + 0x78) = param_2[6];
        *(undefined8 *)((longlong)_Dst + 0x80) = param_2[7];
        *(undefined8 *)((longlong)_Dst + 0x88) = param_2[8];
        *(undefined8 *)((longlong)_Dst + 0x90) = param_2[9];
        *(undefined8 *)((longlong)_Dst + 0x98) = param_2[10];
      }
      if (*(char *)(param_3 + 0x102) == '\x01') {
        *(undefined4 *)((longlong)_Dst_00 + 0xa4) = 1;
        *(undefined4 *)((longlong)_Dst + 0xa4) = 1;
      }
      *(char *)((longlong)_Dst + 0x4e) = (char)uVar7;
LAB_00026b20:
      *(undefined4 *)(param_3 + 0xfc) = 0;
      *(undefined4 *)(param_3 + 0x108) = 0;
      uVar7 = *(uint *)((longlong)param_2 + 0xc);
      *(undefined4 *)(param_3 + 0x104) = 1;
      *(longlong *)((longlong)_Dst_00 + 0x10) = param_3;
      *(undefined4 *)((longlong)_Dst_00 + 0xa0) = 0;
      *(undefined8 *)((longlong)_Dst_00 + 0x30) = 0;
      *(code **)((longlong)_Dst_00 + 0x18) = DispatchDiskReadWrite;
      if ((uVar7 & 0x40) == 0) {
        *(ulonglong *)((longlong)_Dst_00 + 0x40) = local_res18[0];
        *(undefined4 *)(param_3 + 0x10c) = 1;
        uVar3 = (ulonglong)*(uint *)(param_3 + 0xe98);
        *(uint *)((longlong)_Dst_00 + 0x38) = *(uint *)(param_3 + 0xe98);
        if (*(int *)(param_3 + 0xea4) != 0) {
          lVar4 = *(longlong *)(*(longlong *)(param_3 + 0xf0) + 0x38);
          uVar3 = (ulonglong)*(byte *)(lVar4 + 0x278);
          *(void **)(lVar4 + 0x78 + uVar3 * 8) = _Dst_00;
          *(char *)(lVar4 + 0x278) = *(char *)(lVar4 + 0x278) + '\x01';
        }
        if (_Dst == (void *)0x0) goto LAB_00026c55;
        *(longlong *)((longlong)_Dst + 0x10) = param_3;
        *(code **)((longlong)_Dst + 0x18) = DispatchDiskReadWrite;
        *(ulonglong *)((longlong)_Dst + 0x40) = local_res18[0];
        *(undefined8 *)((longlong)_Dst + 0x30) = 0;
        if (*(char *)(param_1 + 0xb10) == '\x01') {
          *(undefined4 *)(param_3 + 0x104) = 2;
          *(undefined4 *)((longlong)_Dst + 0xa0) = 1;
          *(undefined4 *)(param_3 + 0x110) = 1;
        }
        else {
          *(undefined4 *)((longlong)_Dst + 0xa0) = 0;
          *(undefined4 *)(param_3 + 0x10c) = 2;
        }
        uVar3 = (ulonglong)*(uint *)(param_3 + 0xe98);
        *(uint *)((longlong)_Dst + 0x38) = *(uint *)(param_3 + 0xe98);
        if (*(int *)(param_3 + 0xea4) == 0) goto LAB_00026c55;
        lVar4 = *(longlong *)(*(longlong *)(param_3 + 0xf0) + 0x38);
        *(void **)(lVar4 + 0x78 + (ulonglong)*(byte *)(lVar4 + 0x278) * 8) = _Dst;
      }
      else {
        *(ulonglong *)((longlong)_Dst_00 + 0x40) = local_res18[0];
        *(undefined4 *)(param_3 + 0x10c) = 1;
        uVar3 = (ulonglong)*(uint *)(param_3 + 0xe98);
        *(uint *)((longlong)_Dst_00 + 0x38) = *(uint *)(param_3 + 0xe98);
        if (*(int *)(param_3 + 0xea4) == 0) goto LAB_00026c55;
        lVar4 = *(longlong *)(*(longlong *)(param_3 + 0xf0) + 0x38);
        *(void **)(lVar4 + 0x78 + (ulonglong)*(byte *)(lVar4 + 0x278) * 8) = _Dst_00;
      }
      uVar3 = 0;
      *(char *)(lVar4 + 0x278) = *(char *)(lVar4 + 0x278) + '\x01';
LAB_00026c55:
      return uVar3 & 0xffffffffffffff00;
    }
  }
  else {
    bVar1 = *(byte *)(lVar4 + 0x279);
    uVar3 = (ulonglong)(bVar1 + 1);
    if (bVar1 + 1 < 0x29) {
      uVar3 = (ulonglong)(bVar1 + 1);
      *(char *)(lVar4 + 0x279) = (char)(bVar1 + 1);
      if (bVar1 != 0xffffffff) {
        _Dst_00 = (void *)((ulonglong)bVar1 * 0xc0 + *(longlong *)(lVar4 + 0x50));
        memset(_Dst_00,0,0xc0);
        if ((undefined8 *)((longlong)_Dst_00 + 0x48) != param_2) {
          *(undefined8 *)((longlong)_Dst_00 + 0x48) = *param_2;
          *(undefined8 *)((longlong)_Dst_00 + 0x50) = param_2[1];
          *(undefined8 *)((longlong)_Dst_00 + 0x58) = param_2[2];
          *(undefined8 *)((longlong)_Dst_00 + 0x60) = param_2[3];
          *(undefined8 *)((longlong)_Dst_00 + 0x68) = param_2[4];
          *(undefined8 *)((longlong)_Dst_00 + 0x70) = param_2[5];
          *(undefined8 *)((longlong)_Dst_00 + 0x78) = param_2[6];
          *(undefined8 *)((longlong)_Dst_00 + 0x80) = param_2[7];
          *(undefined8 *)((longlong)_Dst_00 + 0x88) = param_2[8];
          *(undefined8 *)((longlong)_Dst_00 + 0x90) = param_2[9];
          *(undefined8 *)((longlong)_Dst_00 + 0x98) = param_2[10];
        }
        if (*(char *)(param_3 + 0x102) == '\x01') {
          *(undefined4 *)((longlong)_Dst_00 + 0xa4) = 1;
        }
        goto LAB_00026b20;
      }
    }
  }
  *(undefined1 *)(param_3 + 0x100) = 2;
  *(undefined4 *)(param_3 + 0xfc) = 2;
LAB_00026c6a:
  return CONCAT71((int7)(uVar3 >> 8),4);
}



===== RAIDAddSubCmdToChnl @ 00026c7c =====

void RAIDAddSubCmdToChnl(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  longlong *plVar6;
  longlong *plVar7;
  uint uVar8;
  ulonglong uVar9;
  int iVar10;
  
  plVar6 = (longlong *)(param_2 + 0xbc0);
  uVar3 = 0;
  iVar10 = 0;
  uVar5 = 0;
  uVar8 = 0;
  plVar7 = plVar6;
  do {
    lVar4 = 8;
    do {
      if (*plVar7 != 0) {
        *(uint *)(*plVar7 + 0xa0) = uVar8;
        iVar10 = iVar10 + 1;
        uVar5 = uVar8;
      }
      plVar7 = plVar7 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    if (iVar10 != 0) {
      *(int *)(param_2 + 0x10c + (ulonglong)uVar5 * 4) = iVar10;
      iVar10 = 0;
      uVar3 = uVar3 + 1;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 10);
  *(uint *)(param_2 + 0x104) = uVar3;
  if (uVar3 != 0) {
    uVar9 = (ulonglong)uVar3;
    do {
      lVar4 = 8;
      do {
        lVar1 = *plVar6;
        if (lVar1 != 0) {
          if ((*(char *)(lVar1 + 0x90) == '/') || (*(char *)(lVar1 + 0x90) == -0x71)) {
            *(undefined4 *)(lVar1 + 0x54) = 0x80;
          }
          if (*(int *)(param_2 + 0xea4) != 0) {
            lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
            *(longlong *)(lVar2 + 0x78 + (ulonglong)*(byte *)(lVar2 + 0x278) * 8) = lVar1;
            *(char *)(lVar2 + 0x278) = *(char *)(lVar2 + 0x278) + '\x01';
          }
        }
        plVar6 = plVar6 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  return;
}



===== RaidStripCommand @ 00026d4c =====

char RaidStripCommand(ulonglong *param_1,undefined8 *param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *_Src;
  void *_Dst;
  undefined8 *puVar3;
  char cVar4;
  undefined8 uVar5;
  undefined8 *_Dst_00;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  
  lVar2 = param_2[7];
  if (((int)param_1[(ulonglong)*(byte *)((longlong)param_2 + 6) * 0x17 + 0x75] == 5) &&
     (Hibernate != '\0')) {
    uVar5 = Raid5NormalDivider(param_1,param_2,param_3);
    cVar4 = (char)uVar5;
  }
  else {
    uVar5 = Raid5NormalDivide(param_1,param_2,param_3);
    cVar4 = (char)uVar5;
  }
  uVar7 = (ulonglong)*(byte *)((longlong)param_2 + 6);
  if (((int)param_1[uVar7 * 0x17 + 0x75] == 9) &&
     ((char)*(undefined4 *)((longlong)param_2 + 0xc) < '\0')) {
    plVar1 = (longlong *)(param_3 + 0xbc0);
    while( true ) {
      uVar10 = (uint)param_1[uVar7 * 0x17 + 0x76] >> 0xd & 0x7f;
      if ((uVar10 != 0xf) && (plVar1[uVar7] != 0)) {
        _Dst_00 = RAIDAllocateSubCmd((longlong)param_1,param_3,(longlong)param_2,(ulonglong)uVar10,
                                     (uint)((char)param_1[0x162] == '\x01'),plVar1);
        if (_Dst_00 == (undefined8 *)0x0) {
          *(undefined4 *)(param_3 + 0xfc) = 2;
          *(undefined1 *)(param_3 + 0x100) = 2;
          return '\x04';
        }
        _Src = (undefined8 *)plVar1[uVar7];
        _Dst = (void *)_Dst_00[6];
        if (_Dst_00 != _Src) {
          if ((((uint)_Src | (uint)_Dst_00) & 0xf) == 0) {
            lVar6 = 1;
            puVar3 = _Dst_00;
            do {
              puVar9 = _Src;
              puVar8 = puVar3;
              uVar5 = puVar9[1];
              *puVar8 = *puVar9;
              puVar8[1] = uVar5;
              uVar5 = puVar9[3];
              puVar8[2] = puVar9[2];
              puVar8[3] = uVar5;
              uVar5 = puVar9[5];
              puVar8[4] = puVar9[4];
              puVar8[5] = uVar5;
              uVar5 = puVar9[7];
              puVar8[6] = puVar9[6];
              puVar8[7] = uVar5;
              uVar5 = puVar9[9];
              puVar8[8] = puVar9[8];
              puVar8[9] = uVar5;
              uVar5 = puVar9[0xb];
              puVar8[10] = puVar9[10];
              puVar8[0xb] = uVar5;
              uVar5 = puVar9[0xd];
              puVar8[0xc] = puVar9[0xc];
              puVar8[0xd] = uVar5;
              uVar5 = puVar9[0xf];
              puVar8[0xe] = puVar9[0xe];
              puVar8[0xf] = uVar5;
              lVar6 = lVar6 + -1;
              puVar3 = puVar8 + 0x10;
              _Src = puVar9 + 0x10;
            } while (lVar6 != 0);
            uVar5 = puVar9[0x11];
            puVar8[0x10] = puVar9[0x10];
            puVar8[0x11] = uVar5;
            uVar5 = puVar9[0x13];
            puVar8[0x12] = puVar9[0x12];
            puVar8[0x13] = uVar5;
            uVar5 = puVar9[0x15];
            puVar8[0x14] = puVar9[0x14];
            puVar8[0x15] = uVar5;
            uVar5 = puVar9[0x17];
            puVar8[0x16] = puVar9[0x16];
            puVar8[0x17] = uVar5;
          }
          else {
            memcpy(_Dst_00,_Src,0xc0);
          }
        }
        _Dst_00[6] = _Dst;
        *(char *)((longlong)_Dst_00 + 0x4e) = (char)uVar10;
        if (_Dst != *(void **)(plVar1[uVar7] + 0x30)) {
          memcpy(_Dst,*(void **)(plVar1[uVar7] + 0x30),
                 (ulonglong)(uint)(*(int *)(lVar2 + 0x68) << 2));
        }
      }
      if (((uint)param_1[uVar7 * 0x17 + 0x76] >> 0xc & 1) != 0) break;
      uVar7 = (ulonglong)((uint)param_1[uVar7 * 0x17 + 0x76] >> 8 & 0xf);
    }
  }
  if (cVar4 == '\x01') {
    *(undefined4 *)(param_3 + 0xfc) = 0;
    *(undefined4 *)(param_3 + 0x108) = 0;
  }
  else {
    *(undefined4 *)(param_3 + 0xfc) = 2;
    *(undefined1 *)(param_3 + 0x100) = 2;
  }
  if ((int)param_1[(ulonglong)*(byte *)((longlong)param_2 + 6) * 0x17 + 0x75] != 5) {
    RAIDAddSubCmdToChnl((ulonglong)*(byte *)((longlong)param_2 + 6) * 0xb8,param_3);
  }
  return cVar4;
}



===== RaidEmigratingStripCommand @ 00026fa8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RaidEmigratingStripCommand(ulonglong *param_1,ulonglong *param_2,longlong param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_148 [32];
  longlong local_128;
  ulonglong local_120;
  ulonglong local_118 [2];
  ulonglong local_108;
  ulonglong local_100;
  ulonglong local_f8;
  ulonglong local_f0;
  ulonglong local_e8;
  ulonglong local_e0;
  ulonglong local_d8;
  ulonglong local_d0;
  ulonglong local_c8;
  ulonglong local_c0;
  ulonglong local_b8;
  ulonglong local_a8;
  ulonglong local_a0;
  ulonglong local_98;
  ulonglong local_90;
  ulonglong local_88;
  ulonglong local_80;
  ulonglong local_78;
  ulonglong local_70;
  ulonglong local_68;
  ulonglong local_60;
  ulonglong *local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_148;
  iVar8 = *(int *)(param_3 + 0xe98);
  puVar4 = param_2;
  GetStartEndFromSrb((longlong)param_2,local_118,(longlong *)&local_120,iVar8);
  uVar5 = (ulonglong)*(byte *)((longlong)param_2 + 6);
  local_128 = uVar5 * 0xb8;
  uVar1 = param_1[uVar5 * 0x17 + 0x7b];
  uVar5 = param_1[uVar5 * 0x17 + 0x7a];
  if (uVar5 < uVar1) {
    return CONCAT71((int7)((ulonglong)local_128 >> 8),4);
  }
  if (uVar1 < local_120) {
    *(undefined1 *)(param_3 + 0xee1) = 1;
    *(ulonglong *)(param_3 + 0xef8) = uVar5;
    *(ulonglong *)(param_3 + 0xee8) = local_118[0];
    *(ulonglong *)(param_3 + 0xef0) = local_120;
  }
  iVar7 = (int)uVar5;
  if (uVar5 < local_120) {
    if (local_118[0] < uVar5) {
      if (&local_a8 != param_2) {
        local_a8 = *param_2;
        local_a0 = param_2[1];
        local_98 = param_2[2];
        local_90 = param_2[3];
        local_88 = param_2[4];
        local_80 = param_2[5];
        local_78 = param_2[6];
        local_70 = param_2[7];
        local_68 = param_2[8];
        local_60 = param_2[9];
        local_58 = (ulonglong *)param_2[10];
      }
      if (&local_108 != param_2) {
        local_108 = *param_2;
        local_100 = param_2[1];
        local_f8 = param_2[2];
        local_f0 = param_2[3];
        local_e8 = param_2[4];
        local_e0 = param_2[5];
        local_d8 = param_2[6];
        local_d0 = param_2[7];
        local_c8 = param_2[8];
        local_c0 = param_2[9];
        local_b8 = param_2[10];
      }
      iVar3 = iVar7 - (int)local_118[0];
      local_98 = CONCAT44(local_98._4_4_,iVar3 * 0x200);
      local_f8 = CONCAT44(local_f8._4_4_,(int)param_2[2] + iVar3 * -0x200);
      WriteAddressToSrb((longlong)&local_108,uVar5,iVar8);
      local_f0 = local_f0 + (uVar5 - local_118[0]) * 0x200;
      puVar4 = param_1;
      RaidStripCommand(param_1,&local_a8,param_3);
      puVar6 = &local_108;
    }
    else {
      puVar6 = param_2;
    }
    NormalHDDCommand((ulonglong)puVar4,puVar6,param_3);
  }
  else {
    puVar4 = param_1;
    RaidStripCommand(param_1,param_2,param_3);
  }
  uVar2 = (ulonglong)*(uint *)((longlong)param_2 + 0xc);
  if ((-1 < (char)*(uint *)((longlong)param_2 + 0xc)) || (uVar5 <= uVar1)) goto LAB_00027364;
  if (local_118[0] < uVar1) {
    if (local_120 < uVar5) {
      if (local_120 <= uVar1) goto LAB_000272e5;
      if (&local_108 != param_2) {
        local_108 = *param_2;
        local_100 = param_2[1];
        local_f8 = param_2[2];
        local_f0 = param_2[3];
        local_e8 = param_2[4];
        local_e0 = param_2[5];
        local_d8 = param_2[6];
        local_d0 = param_2[7];
        local_c8 = param_2[8];
        local_c0 = param_2[9];
        local_b8 = param_2[10];
      }
      local_f8 = CONCAT44(local_f8._4_4_,((int)local_120 - (int)uVar1) * 0x200);
    }
    else {
      if (&local_108 != param_2) {
        local_108 = *param_2;
        local_100 = param_2[1];
        local_f8 = param_2[2];
        local_f0 = param_2[3];
        local_e8 = param_2[4];
        local_e0 = param_2[5];
        local_d8 = param_2[6];
        local_d0 = param_2[7];
        local_c8 = param_2[8];
        local_c0 = param_2[9];
        local_b8 = param_2[10];
      }
      local_f8 = CONCAT44(local_f8._4_4_,(iVar7 - (int)uVar1) * 0x200);
    }
    puVar4 = &local_108;
    WriteAddressToSrb((longlong)puVar4,*(undefined8 *)(local_128 + 0x3d8 + (longlong)param_1),
                      *(int *)(param_3 + 0xe98));
    param_2 = &local_108;
    local_f0 = local_f0 + (uVar1 - local_118[0]) * 0x200;
  }
  else if (uVar5 < local_120) {
LAB_000272e5:
    if ((uVar5 <= local_118[0]) || (local_120 < uVar5)) goto LAB_00027364;
    if (&local_a8 != param_2) {
      local_a8 = *param_2;
      puVar4 = (ulonglong *)param_2[10];
      local_a0 = param_2[1];
      local_98 = param_2[2];
      local_90 = param_2[3];
      local_88 = param_2[4];
      local_80 = param_2[5];
      local_78 = param_2[6];
      local_70 = param_2[7];
      local_68 = param_2[8];
      local_60 = param_2[9];
      local_58 = puVar4;
    }
    param_2 = &local_a8;
    local_98 = CONCAT44(local_98._4_4_,(iVar7 - (int)local_118[0]) * 0x200);
  }
  uVar2 = NormalHDDCommand((ulonglong)puVar4,param_2,param_3);
LAB_00027364:
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== Raid5DelayCmdCallback @ 00027390 =====

uint Raid5DelayCmdCallback(longlong param_1,longlong param_2,undefined8 *param_3,undefined8 param_4)

{
  char cVar1;
  uint in_EAX;
  undefined3 extraout_var;
  int *piVar2;
  uint uVar3;
  byte *pbVar4;
  
  if (*(uint *)(param_2 + 0xf8) < 2) {
    uVar3 = 0;
    pbVar4 = (byte *)(param_1 + 0x1502);
    piVar2 = (int *)(param_1 + 0x3a8);
    do {
      if (*piVar2 == 5) {
        *pbVar4 = *pbVar4 & 0xf;
        param_3 = (undefined8 *)((longlong)(int)uVar3 * 0x200 + param_1 + 0x14c4);
        in_EAX = ReadWriteConfigFromHDD(param_1,uVar3,param_3,param_4,'\x01');
        if ((char)in_EAX != '\x01') goto LAB_0002743a;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 0x2e;
      pbVar4 = pbVar4 + 0x200;
    } while ((int)uVar3 < 8);
    cVar1 = FlushCacheToHDD(param_1,-1,CONCAT71((int7)((ulonglong)param_3 >> 8),1),'\0');
    in_EAX = CONCAT31(extraout_var,cVar1);
    if (cVar1 != '\0') {
      return CONCAT31(extraout_var,1);
    }
LAB_0002743a:
    *(undefined4 *)(param_2 + 0xf8) = 4;
  }
  return in_EAX & 0xffffff00;
}



===== RfParseLcmdShutdown @ 0002744c =====

void RfParseLcmdShutdown(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  byte bVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = 0;
  if (*(int *)(param_1 + 0x42d8) != 0) {
    piVar7 = (int *)(param_1 + 0x3a8);
    lVar4 = 8;
    do {
      if ((*piVar7 == 5) && (plVar2 = *(longlong **)(param_1 + 0x42c0), plVar2 != (longlong *)0x0))
      {
        *(undefined4 *)(plVar2 + 0x14) = 0;
        plVar2[2] = param_2;
        bVar3 = *(byte *)((longlong)plVar2 + 0x4e) >> 1;
        if (bVar3 < 4) {
          uVar5 = (ulonglong)bVar3;
          AddListEntryToTail((longlong *)(param_1 + 0x2f8 + uVar5 * 8),plVar2);
          piVar1 = (int *)(param_1 + 0x32c + uVar5 * 4);
          *piVar1 = *piVar1 + 1;
        }
        iVar6 = iVar6 + 1;
      }
      piVar7 = piVar7 + 0x2e;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    if (iVar6 != 0) {
      *(undefined4 *)(param_2 + 0x108) = 0;
      *(undefined4 *)(param_2 + 0x104) = 1;
      *(int *)(param_2 + 0x10c) = iVar6;
      *(undefined4 *)(param_2 + 0xfc) = 0;
      *(code **)(param_2 + 0x160) = Raid5DelayCmdCallback;
      return;
    }
  }
  ParseFlushCacheToHDD(param_1,param_2,'\x01');
  SetRealLogicTarget(param_1,param_2);
  return;
}



===== RfRaidCommand @ 00027528 =====

ulonglong RfRaidCommand(ulonglong *param_1,ulonglong *param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined7 extraout_var;
  longlong local_res8;
  
  uVar5 = (ulonglong)*(byte *)((longlong)param_2 + 6);
  iVar1 = (int)param_1[uVar5 * 0x17 + 0x75];
  if (iVar1 == 0) {
    if (*(char *)((longlong)param_1 + uVar5 * 0xb8 + 0x3ac) != '\0') {
LAB_00027566:
      *(undefined4 *)(param_3 + 0xf8) = 4;
      *(undefined4 *)(param_3 + 0xfc) = 1;
      return 4;
    }
    iVar1 = (int)param_1[uVar5 * 0x17 + 0x7c];
  }
  else {
    if (iVar1 == 1) {
      uVar5 = Raid1Command((longlong)param_1,param_2,param_3);
      return uVar5;
    }
    if (iVar1 == 8) {
      if (*(char *)((longlong)param_1 + uVar5 * 0xb8 + 0x3ac) == '\0') {
        uVar5 = RaidSpanCommand((longlong)param_1,param_2,param_3);
        return uVar5;
      }
      goto LAB_00027566;
    }
    if (iVar1 == 9) goto LAB_00027682;
    if (iVar1 != 5) {
      return 6;
    }
    lVar2 = *(longlong *)(*(longlong *)(param_3 + 0xf0) + 0x38);
    if (((lVar2 != 0) && (Hibernate == '\0')) && (*(int *)(lVar2 + 0x27c) == 0)) {
      StorPortNotification(0xf,param_1,&local_res8);
      uVar4 = (**(code **)(local_res8 + 0x30))(*(undefined8 *)(param_3 + 0xf0));
      param_2[3] = uVar4;
      *(undefined8 *)(lVar2 + 0x280) = *(undefined8 *)(*(longlong *)(param_3 + 0xf0) + 0x18);
      *(ulonglong *)(*(longlong *)(param_3 + 0xf0) + 0x18) = uVar4;
      *(undefined4 *)(lVar2 + 0x27c) = 1;
    }
    if (((char)param_2[9] == '/') || ((char)param_2[9] == -0x71)) {
      *(undefined4 *)((longlong)param_2 + 0xc) = 0x40;
    }
    iVar1 = (int)param_1[uVar5 * 0x17 + 0x7c];
  }
  if (iVar1 == 1) {
    uVar5 = RaidEmigratingStripCommand(param_1,param_2,param_3);
    return uVar5;
  }
LAB_00027682:
  cVar3 = RaidStripCommand(param_1,param_2,param_3);
  return CONCAT71(extraout_var,cVar3);
}



===== GetStartEndFromSrb @ 0002769c =====

void GetStartEndFromSrb(longlong param_1,ulonglong *param_2,longlong *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  ulonglong uVar3;
  
  if (param_4 == 0) {
    uVar3 = (ulonglong)
            CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x4b)),
                     *(undefined1 *)(param_1 + 0x4c));
    bVar1 = *(byte *)(param_1 + 0x4d);
  }
  else {
    uVar3 = (ulonglong)
            CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 0x4a),
                                                                  *(undefined1 *)(param_1 + 0x4b)),
                                                         *(undefined1 *)(param_1 + 0x4c)),
                                                *(undefined1 *)(param_1 + 0x4d)),
                                       *(undefined1 *)(param_1 + 0x4e)),
                              *(undefined1 *)(param_1 + 0x4f)),*(undefined1 *)(param_1 + 0x50));
    bVar1 = *(byte *)(param_1 + 0x51);
  }
  iVar2 = *(int *)(param_1 + 0x10);
  uVar3 = uVar3 << 8 | (ulonglong)bVar1;
  *param_2 = uVar3;
  *param_3 = ((ulonglong)(iVar2 + 0x1ffU >> 9) - 1) + uVar3;
  return;
}



===== WriteAddressToSrb @ 00027728 =====

void WriteAddressToSrb(longlong param_1,undefined8 param_2,int param_3)

{
  undefined1 uVar3;
  undefined1 uVar2;
  undefined1 uVar1;
  
  uVar1 = (undefined1)((ulonglong)param_2 >> 8);
  uVar2 = (undefined1)((ulonglong)param_2 >> 0x10);
  uVar3 = (undefined1)((ulonglong)param_2 >> 0x18);
  if (param_3 == 0) {
    *(char *)(param_1 + 0x4d) = (char)param_2;
    *(undefined1 *)(param_1 + 0x4a) = uVar3;
    *(undefined1 *)(param_1 + 0x4b) = uVar2;
    *(undefined1 *)(param_1 + 0x4c) = uVar1;
    return;
  }
  *(char *)(param_1 + 0x51) = (char)param_2;
  *(char *)(param_1 + 0x4a) = (char)((ulonglong)param_2 >> 0x38);
  *(char *)(param_1 + 0x4b) = (char)((ulonglong)param_2 >> 0x30);
  *(char *)(param_1 + 0x4c) = (char)((ulonglong)param_2 >> 0x28);
  *(char *)(param_1 + 0x4d) = (char)((ulonglong)param_2 >> 0x20);
  *(undefined1 *)(param_1 + 0x4e) = uVar3;
  *(undefined1 *)(param_1 + 0x4f) = uVar2;
  *(undefined1 *)(param_1 + 0x50) = uVar1;
  return;
}



===== XOROperation @ 00027798 =====

undefined8 XOROperation(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  
  uVar1 = (ulonglong)*(uint *)(param_2 + 0x108);
  lVar2 = uVar1 * 0xd8;
  if (*(char *)(lVar2 + 699 + param_2) == '\x02') {
    uVar1 = RAID5WriteToCache(param_1,param_2,0,0);
  }
  if (*(char *)(lVar2 + 699 + param_2) == '\x03') {
    RAID5WriteToCache(param_1,param_2,1,0);
    if ((*(uint *)(*(longlong *)(param_2 + 0xf0) + 0xc) & 0x40) == 0) {
      uVar1 = RAID5WriteToCache(param_1,param_2,0,0);
    }
    else {
      uVar1 = RAID5ReadFromCache(param_1,param_2);
    }
  }
  if (*(char *)(lVar2 + 699 + param_2) == '\x04') {
    RAID5WriteToCache(param_1,param_2,1,1);
    uVar1 = RAID5WriteToCache(param_1,param_2,0,0);
  }
  return CONCAT71((int7)(uVar1 >> 8),1);
}



===== RAID5WriteToCache @ 00027854 =====

undefined8 RAID5WriteToCache(longlong param_1,longlong param_2,int param_3,int param_4)

{
  uint *puVar1;
  longlong lVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  char cVar11;
  uint *puVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  longlong lVar16;
  byte bVar17;
  uint uVar18;
  longlong *plVar19;
  int iVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  longlong lVar23;
  ulonglong uVar24;
  ulonglong uVar25;
  uint uVar26;
  uint local_res10;
  uint local_b8;
  undefined4 *local_b0;
  longlong local_a8;
  ulonglong local_a0;
  ulonglong local_98;
  longlong local_88 [9];
  
  lVar16 = *(longlong *)(param_2 + 0xf0);
  lVar2 = param_1 + 0x388;
  uVar18 = *(uint *)(param_2 + 0xe44);
  local_res10 = 0xff;
  uVar8 = *(uint *)((ulonglong)*(byte *)(param_1 + 0x958 + (ulonglong)*(byte *)(lVar16 + 6) * 0x28)
                    * 0xb8 + 0x28 + lVar2);
  local_b8 = uVar8 & 0xf;
  uVar26 = ((uVar8 >> 0x12 & 0xf) + 1) * (uVar8 >> 0x16) * 4;
  uVar8 = uVar26 * local_b8;
  local_a8 = *(longlong *)(lVar16 + 0x38);
  if (Hibernate != '\0') {
    uVar18 = *(uint *)(param_2 + 0xb70 + (longlong)*(int *)(param_2 + 0x108) * 4);
  }
  lVar23 = param_1;
  GetStartEndFromSrb(lVar16,&local_a0,(longlong *)&local_b0,*(int *)(param_2 + 0xe98));
  bVar5 = *(byte *)(lVar23 + 0x958 + (ulonglong)*(byte *)(lVar16 + 6) * 0x28);
  if (param_4 != 0) {
    if (*(char *)((ulonglong)bVar5 * 0xb8 + 0x24 + lVar2) == '\0') {
      lVar9 = lVar2;
      uVar6 = RAID5DirtyStatus(lVar2,(ulonglong)bVar5);
      if ((int)uVar6 != 0) {
        uVar7 = RAID5UnDirtyDiskIndex(lVar9,(uint)bVar5);
        local_res10 = (uint)uVar7;
        lVar23 = param_1;
      }
    }
    local_b8 = local_b8 + 1;
  }
  uVar7 = (ulonglong)uVar8;
  uVar13 = *(int *)(lVar16 + 0x10) - uVar18;
  uVar21 = local_a0 + (uVar18 >> 9);
  local_b0 = (undefined4 *)(*(longlong *)(lVar16 + 0x18) + (ulonglong)uVar18);
  local_a0 = (uVar21 % uVar7) / (ulonglong)uVar26;
  local_98 = (uVar21 % uVar7) % (ulonglong)uVar26;
  bVar5 = BuildRWRaid5Links(lVar23,param_2,lVar16,(uVar21 / uVar7) / (ulonglong)(uVar8 / uVar8));
  cVar11 = Hibernate;
  uVar7 = (ulonglong)bVar5;
  if (param_4 == 0) {
    bVar17 = *(byte *)(uVar7 * 0xb8 + 0x45 + lVar2);
    if (bVar17 == 0xff) {
      lVar16 = 0;
      goto LAB_00027a19;
    }
    uVar21 = (ulonglong)bVar17;
  }
  else {
    uVar21 = (ulonglong)local_res10;
  }
  lVar16 = *(longlong *)(local_a8 + 0x2c8 + uVar21 * 8);
LAB_00027a19:
  uVar8 = 0;
  if ((uint)local_a0 != 0) {
    do {
      bVar17 = (byte)((uint)*(undefined4 *)(uVar7 * 0xb8 + 0x28 + lVar2) >> 8) & 0xf;
      uVar7 = (ulonglong)bVar17;
      if (bVar17 == 0xf) {
        return 4;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < (uint)local_a0);
  }
  if (Hibernate == '\0') {
    puVar14 = (undefined4 *)((ulonglong)uVar18 + *(longlong *)(local_a8 + 0x2c8 + uVar7 * 8));
  }
  else {
    puVar14 = *(undefined4 **)(local_a8 + 0x2c8 + uVar7 * 8);
  }
  uVar8 = (uVar26 - (int)local_98) * 0x200;
  if (uVar8 < uVar13) {
    uVar13 = uVar8;
  }
  uVar21 = 0;
  if (Hibernate == '\0') {
    if (param_3 != 1) {
      *(uint *)(param_2 + 0xe44) = uVar13;
    }
  }
  else {
    uVar13 = *(uint *)(param_2 + 0xb20 + (longlong)*(int *)(param_2 + 0x108) * 4);
    if (param_3 != 1) {
      *(int *)(param_2 + 0xe44) = *(int *)(param_2 + 0xe44) + uVar13;
    }
  }
  cVar4 = Hibernate;
  cVar3 = *(char *)((ulonglong)bVar5 * 0xb8 + 0x45 + lVar2);
  if (param_3 != 1) {
    puVar15 = local_b0;
    for (uVar10 = (ulonglong)(uVar13 >> 2); cVar11 = cVar4, uVar10 != 0; uVar10 = uVar10 - 1) {
      *puVar14 = *puVar15;
      puVar15 = puVar15 + 1;
      puVar14 = puVar14 + 1;
    }
  }
  uVar10 = (ulonglong)bVar5;
  if (((((*(uint *)(*(longlong *)(param_2 + 0xf0) + 0xc) & 0x40) == 0) || ((char)uVar7 == cVar3)) &&
      (lVar16 != 0)) && (uVar13 != 0)) {
    if (cVar11 != '\0') {
      uVar18 = 0;
    }
    uVar13 = uVar13 >> 2;
    uVar22 = (ulonglong)(uVar18 >> 2);
    memset(local_88,0,0x40);
    lVar16 = lVar16 + uVar22 * 4;
    uVar7 = uVar21;
    if (local_b8 != 0) {
      uVar24 = (ulonglong)local_b8;
      do {
        if (param_4 == 0) {
          local_88[uVar7] = *(longlong *)(param_1 + 0x4260 + uVar10 * 8) + uVar22 * 4;
          uVar18 = *(uint *)(uVar10 * 0xb8 + 0x28 + lVar2) >> 8;
LAB_00027bd7:
          uVar7 = (ulonglong)((int)uVar7 + 1);
        }
        else {
          if ((uint)uVar10 != local_res10) {
            local_88[uVar7] = *(longlong *)(param_1 + 0x4260 + uVar10 * 8) + uVar22 * 4;
            uVar18 = *(uint *)(uVar10 * 0xb8 + 0x28 + lVar2) >> 0xe;
            goto LAB_00027bd7;
          }
          uVar18 = *(uint *)(uVar10 * 0xb8 + 0x28 + lVar2) >> 0xe;
        }
        uVar10 = (ulonglong)(uVar18 & 0xf);
        uVar24 = uVar24 - 1;
      } while (uVar24 != 0);
    }
    iVar20 = (int)uVar7;
    if (iVar20 == 2) {
      if (uVar13 != 0) {
        local_88[0] = local_88[0] - local_88[1];
        lVar16 = lVar16 - local_88[1];
        uVar7 = (ulonglong)((uVar13 - 1 >> 2) + 1);
        puVar12 = (uint *)(local_88[1] + 4);
        do {
          *(uint *)((longlong)puVar12 + lVar16 + -4) =
               *(uint *)((longlong)puVar12 + local_88[0] + -4) ^ puVar12[-1];
          *(uint *)((longlong)puVar12 + lVar16) =
               *(uint *)((longlong)puVar12 + local_88[0]) ^ *puVar12;
          *(uint *)((longlong)puVar12 + lVar16 + 4) =
               *(uint *)((longlong)puVar12 + local_88[0] + 4) ^ puVar12[1];
          *(uint *)((longlong)puVar12 + lVar16 + 8) =
               *(uint *)((longlong)puVar12 + local_88[0] + 8) ^ puVar12[2];
          uVar7 = uVar7 - 1;
          puVar12 = puVar12 + 4;
        } while (uVar7 != 0);
      }
    }
    else if (iVar20 == 3) {
      if (uVar13 != 0) {
        local_88[2] = local_88[2] - local_88[1];
        local_88[0] = local_88[0] - local_88[1];
        lVar16 = lVar16 - local_88[1];
        uVar7 = (ulonglong)((uVar13 - 1 >> 2) + 1);
        puVar12 = (uint *)(local_88[1] + 4);
        do {
          *(uint *)((longlong)puVar12 + lVar16 + -4) =
               *(uint *)((longlong)puVar12 + local_88[2] + -4) ^
               *(uint *)((longlong)puVar12 + local_88[0] + -4) ^ puVar12[-1];
          *(uint *)((longlong)puVar12 + lVar16) =
               *(uint *)((longlong)puVar12 + local_88[0]) ^
               *(uint *)((longlong)puVar12 + local_88[2]) ^ *puVar12;
          *(uint *)((longlong)puVar12 + lVar16 + 4) =
               *(uint *)((longlong)puVar12 + local_88[0] + 4) ^
               *(uint *)((longlong)puVar12 + local_88[2] + 4) ^ puVar12[1];
          *(uint *)((longlong)puVar12 + lVar16 + 8) =
               *(uint *)((longlong)puVar12 + local_88[0] + 8) ^
               *(uint *)((longlong)puVar12 + local_88[2] + 8) ^ puVar12[2];
          uVar7 = uVar7 - 1;
          puVar12 = puVar12 + 4;
        } while (uVar7 != 0);
      }
    }
    else if (iVar20 == 4) {
      if (uVar13 != 0) {
        local_88[3] = local_88[3] - local_88[2];
        local_88[1] = local_88[1] - local_88[2];
        lVar16 = lVar16 - local_88[2];
        local_88[0] = local_88[0] - local_88[2];
        uVar7 = (ulonglong)((uVar13 - 1 >> 2) + 1);
        puVar12 = (uint *)(local_88[2] + 4);
        do {
          *(uint *)(lVar16 + -4 + (longlong)puVar12) =
               *(uint *)(local_88[3] + -4 + (longlong)puVar12) ^
               *(uint *)(local_88[0] + -4 + (longlong)puVar12) ^
               *(uint *)(local_88[1] + -4 + (longlong)puVar12) ^ puVar12[-1];
          *(uint *)(lVar16 + (longlong)puVar12) =
               *(uint *)(local_88[0] + (longlong)puVar12) ^
               *(uint *)(local_88[1] + (longlong)puVar12) ^
               *(uint *)(local_88[3] + (longlong)puVar12) ^ *puVar12;
          puVar1 = puVar12 + 4;
          *(uint *)(lVar16 + -0xc + (longlong)puVar1) =
               *(uint *)(local_88[0] + 4 + (longlong)puVar12) ^
               *(uint *)(local_88[1] + -0xc + (longlong)puVar1) ^
               *(uint *)(local_88[3] + -0xc + (longlong)puVar1) ^ puVar12[1];
          *(uint *)(lVar16 + -8 + (longlong)puVar1) =
               *(uint *)(local_88[0] + -8 + (longlong)puVar1) ^
               *(uint *)(local_88[1] + -8 + (longlong)puVar1) ^
               *(uint *)(local_88[3] + -8 + (longlong)puVar1) ^ puVar12[2];
          uVar7 = uVar7 - 1;
          puVar12 = puVar1;
        } while (uVar7 != 0);
      }
    }
    else if (uVar13 != 0) {
      uVar22 = (ulonglong)uVar13;
      uVar10 = uVar21;
      do {
        uVar18 = 0;
        if (iVar20 != 0) {
          plVar19 = local_88;
          uVar24 = uVar21;
          uVar25 = uVar7;
          do {
            lVar2 = *plVar19;
            plVar19 = plVar19 + 1;
            uVar18 = (uint)uVar24 ^ *(uint *)(uVar10 + lVar2);
            uVar24 = (ulonglong)uVar18;
            uVar25 = uVar25 - 1;
          } while (uVar25 != 0);
        }
        *(uint *)(uVar10 + lVar16) = uVar18;
        uVar10 = uVar10 + 4;
        uVar22 = uVar22 - 1;
      } while (uVar22 != 0);
    }
  }
  return 1;
}



===== RAID5ReadFromCache @ 00027db4 =====

undefined8 RAID5ReadFromCache(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  undefined4 *local_res8;
  longlong local_res10;
  ulonglong local_res18;
  
  lVar8 = *(longlong *)(param_2 + 0xf0);
  uVar9 = 0;
  local_res8 = (undefined4 *)0x0;
  uVar3 = *(uint *)((ulonglong)*(byte *)(param_1 + 0x958 + (ulonglong)*(byte *)(lVar8 + 6) * 0x28) *
                    0xb8 + 0x3b0 + param_1);
  local_res10 = *(longlong *)(lVar8 + 0x38);
  uVar2 = ((uVar3 >> 0x12 & 0xf) + 1) * (uVar3 >> 0x16) * 4;
  uVar7 = (ulonglong)(uVar2 * (uVar3 & 0xf));
  uVar3 = *(uint *)(param_2 + 0xe40);
  GetStartEndFromSrb(lVar8,(ulonglong *)&local_res8,(longlong *)&local_res18,
                     *(int *)(param_2 + 0xe98));
  uVar4 = *(int *)(lVar8 + 0x10) - uVar3;
  uVar5 = (longlong)local_res8 + (ulonglong)(uVar3 >> 9);
  local_res8 = (undefined4 *)(*(longlong *)(lVar8 + 0x18) + (ulonglong)uVar3);
  local_res18 = (ulonglong)uVar3;
  uVar1 = BuildRWRaid5Links(param_1,param_2,lVar8,
                            (uVar5 / (uVar7 & 0xffffffff)) /
                            ((uVar7 & 0xffffffff) / (uVar7 & 0xffffffff)));
  uVar3 = (uint)((uVar5 % (uVar7 & 0xffffffff)) / (ulonglong)uVar2);
  if (uVar3 != 0) {
    do {
      uVar1 = (ulonglong)
              (uint3)((uint)*(undefined4 *)((uVar1 & 0xff) * 0xb8 + 0x3b0 + param_1) >> 8) &
              0xffffffffffffff0f;
      if ((char)uVar1 == '\x0f') {
        return CONCAT71((int7)(uVar1 >> 8),4);
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar3);
  }
  uVar3 = (uVar2 - (int)((uVar5 % (uVar7 & 0xffffffff)) % (ulonglong)uVar2)) * 0x200;
  if (uVar3 < uVar4) {
    uVar4 = uVar3;
  }
  puVar6 = (undefined4 *)(*(longlong *)(local_res10 + 0x2c8 + (uVar1 & 0xff) * 8) + local_res18);
  for (uVar5 = (ulonglong)(uVar4 >> 2); uVar5 != 0; uVar5 = uVar5 - 1) {
    *local_res8 = *puVar6;
    puVar6 = puVar6 + 1;
    local_res8 = local_res8 + 1;
  }
  *(uint *)(param_2 + 0xe40) = uVar4;
  return CONCAT71((int7)(local_res18 >> 8),1);
}



===== RAIDAllocateSubCmd @ 00027f38 =====

void * RAIDAllocateSubCmd(longlong param_1,longlong param_2,longlong param_3,ulonglong param_4,
                         int param_5,longlong *param_6)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  void *pvVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  uVar6 = param_4 & 0xffffffff;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
  pvVar3 = StorAllocateSubCmdWithBuf(lVar1);
  if (pvVar3 == (void *)0x0) {
    lVar7 = 0x20;
    do {
      if (*param_6 != 0) {
        lVar4 = *(longlong *)(*param_6 + 0x30) - *(longlong *)(lVar1 + 0x58);
        auVar2._8_8_ = lVar4 >> 0x3f;
        auVar2._0_8_ = lVar4 >> 2;
        *(ulonglong *)(lVar1 + 0x60) =
             *(ulonglong *)(lVar1 + 0x60) &
             (longlong)
             ~(1 << (SUB161(auVar2 / SEXT816((longlong)(ulonglong)*(uint *)(lVar1 + 0x68)),0) & 0x1f
                    ));
      }
      param_6 = param_6 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    pvVar3 = (void *)0x0;
  }
  else {
    if (*(char *)(param_2 + 0x102) == '\x01') {
      *(undefined4 *)((longlong)pvVar3 + 0xa4) = 1;
    }
    *(longlong *)((longlong)pvVar3 + 0x10) = param_2;
    *(undefined8 *)((longlong)pvVar3 + 0x28) = *(undefined8 *)(*(longlong *)(param_2 + 0xf0) + 0x18)
    ;
    if (*(int *)(uVar6 * 0xb8 + 0x3a8 + param_1) == 5) {
      uVar5 = *(undefined8 *)(lVar1 + 0x288 + uVar6 * 8);
    }
    else {
      uVar5 = *(undefined8 *)(param_3 + 0x18);
    }
    *(undefined8 *)((longlong)pvVar3 + 0x20) = uVar5;
    *(code **)((longlong)pvVar3 + 0x18) = DispatchDiskReadWrite;
    *(char *)((longlong)pvVar3 + 0x4e) = (char)uVar6;
    param_6[(uint)(param_5 << 3) + uVar6] = (longlong)pvVar3;
    *(undefined4 *)((longlong)pvVar3 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
  }
  return pvVar3;
}



===== RAID5AllocateSubCmd @ 00028050 =====

void * RAID5AllocateSubCmd(undefined8 param_1,longlong param_2,ulonglong param_3,int param_4,
                          longlong *param_5)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  void *pvVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  uVar5 = param_3 & 0xffffffff;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
  pvVar3 = StorAllocateSubCmdWithBuf(lVar1);
  if (pvVar3 == (void *)0x0) {
    lVar6 = 0x20;
    do {
      if (*param_5 != 0) {
        lVar4 = *(longlong *)(*param_5 + 0x30) - *(longlong *)(lVar1 + 0x58);
        auVar2._8_8_ = lVar4 >> 0x3f;
        auVar2._0_8_ = lVar4 >> 2;
        *(ulonglong *)(lVar1 + 0x60) =
             *(ulonglong *)(lVar1 + 0x60) &
             (longlong)
             ~(1 << (SUB161(auVar2 / SEXT816((longlong)(ulonglong)*(uint *)(lVar1 + 0x68)),0) & 0x1f
                    ));
      }
      param_5 = param_5 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    pvVar3 = (void *)0x0;
  }
  else {
    if (*(char *)(param_2 + 0x102) == '\x01') {
      *(undefined4 *)((longlong)pvVar3 + 0xa4) = 1;
    }
    *(longlong *)((longlong)pvVar3 + 0x10) = param_2;
    *(undefined8 *)((longlong)pvVar3 + 0x28) = *(undefined8 *)(*(longlong *)(param_2 + 0xf0) + 0x18)
    ;
    *(undefined8 *)((longlong)pvVar3 + 0x20) = *(undefined8 *)(lVar1 + 0x288 + uVar5 * 8);
    *(char *)((longlong)pvVar3 + 0x4e) = (char)uVar5;
    *(code **)((longlong)pvVar3 + 0x18) = DispatchDiskReadWrite;
    param_5[(uint)(param_4 << 3) + uVar5] = (longlong)pvVar3;
    *(undefined4 *)((longlong)pvVar3 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
  }
  return pvVar3;
}



===== RAID5DiskTargetId @ 00028140 =====

uint RAID5DiskTargetId(longlong param_1,longlong param_2,uint param_3,uint param_4,byte param_5)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  
  lVar6 = (ulonglong)param_3 * 0xb8;
  cVar1 = *(char *)(lVar6 + 0x24 + param_1);
  uVar7 = *(uint *)(lVar6 + 0x28 + param_1) & 0xf;
  if (cVar1 == '\0') {
    uVar7 = uVar7 + 1;
  }
  uVar3 = (uint)param_5;
  if (param_4 <= param_5) {
    uVar3 = param_5 + 1;
  }
  uVar5 = (uint)*(byte *)(lVar6 + 0x44 + param_1);
  if (cVar1 == '\0') {
    if ((uVar3 == uVar5) && ((*(byte *)(param_2 + 0xc) & 0x40) != 0)) {
      uVar3 = param_4;
    }
  }
  else if (uVar3 == uVar5) {
    uVar3 = param_4;
  }
  uVar4 = 0;
  if (uVar7 != 0) {
    do {
      if ((cVar1 == '\0') || (uVar4 != uVar5)) {
        uVar2 = *(uint *)((ulonglong)param_3 * 0xb8 + 0x28 + param_1);
        if (uVar3 == (uVar2 >> 4 & 0xf)) {
          return param_3;
        }
        param_3 = uVar2 >> 0xe & 0xf;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar7);
  }
  return param_3;
}



===== RAID5DirtyStatus @ 000281f8 =====

undefined8 RAID5DirtyStatus(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  uint uVar2;
  
  uVar2 = 0;
  lVar1 = (param_2 & 0xffffffff) * 0xb8 + param_1;
  if ((*(uint *)(lVar1 + 0x28) & 0xf) != 0xffffffff) {
    do {
      if (*(char *)(lVar1 + 0x25) != '\0') {
        return 1;
      }
      uVar2 = uVar2 + 1;
      lVar1 = (ulonglong)(*(uint *)(lVar1 + 0x28) >> 0xe & 0xf) * 0xb8 + param_1;
    } while (uVar2 < (*(uint *)(lVar1 + 0x28) & 0xf) + 1);
  }
  return 0;
}



===== RAID5UnDirtyDiskIndex @ 00028248 =====

ulonglong RAID5UnDirtyDiskIndex(longlong param_1,uint param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  
  uVar1 = (ulonglong)param_2;
  uVar3 = 0;
  lVar2 = uVar1 * 0xb8 + param_1;
  if ((*(uint *)(lVar2 + 0x28) & 0xf) != 0xffffffff) {
    do {
      if (*(char *)(lVar2 + 0x25) == '\0') {
        return uVar1;
      }
      uVar3 = uVar3 + 1;
      uVar1 = (ulonglong)(*(uint *)(lVar2 + 0x28) >> 0xe & 0xf);
      lVar2 = uVar1 * 0xb8 + param_1;
    } while (uVar3 < (*(uint *)(lVar2 + 0x28) & 0xf) + 1);
  }
  return 0xff;
}



===== BuildRWRaid5Links @ 000282a0 =====

void BuildRWRaid5Links(longlong param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
  longlong lVar1;
  uint *puVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  longlong lVar17;
  uint uVar18;
  uint uVar19;
  
  lVar1 = param_1 + 0x388;
  uVar13 = 0;
  bVar3 = *(byte *)(param_1 + 0x958 + (ulonglong)*(byte *)(*(longlong *)(param_2 + 0xf0) + 6) * 0x28
                   );
  uVar9 = (ulonglong)bVar3;
  lVar17 = uVar9 * 0xb8;
  uVar14 = *(uint *)(lVar17 + 0x28 + lVar1) & 0xf;
  cVar4 = *(char *)(lVar17 + 0x24 + lVar1);
  uVar19 = ((uVar14 + 1) - (int)(param_4 % (ulonglong)(uVar14 + 1))) - 1;
  uVar15 = uVar14;
  if (cVar4 == '\0') {
    uVar15 = uVar14 + 1;
  }
  uVar12 = 0xff;
  if ((cVar4 != '\0') && (uVar13 = 0, uVar19 == *(byte *)(lVar17 + 0x44 + lVar1))) {
    uVar13 = 0xff;
  }
  if (((cVar4 != '\x01') && (uVar19 == *(byte *)(lVar17 + 0x44 + lVar1))) &&
     ((*(byte *)(param_3 + 0xc) & 0x40) != 0)) {
    uVar13 = 0xff;
  }
  if (uVar13 != 0xff) {
    uVar16 = 0;
    uVar11 = uVar9;
    if (uVar15 != 0) {
      do {
        uVar7 = *(uint *)(uVar11 * 0xb8 + 0x28 + lVar1);
        if ((uVar7 >> 4 & 0xf) == uVar19) {
          uVar13 = (uint)uVar11;
          break;
        }
        uVar16 = uVar16 + 1;
        uVar11 = (ulonglong)(uVar7 >> 0xe & 0xf);
      } while (uVar16 < uVar15);
    }
  }
  if (uVar15 != 0) {
    uVar11 = (ulonglong)uVar15;
    do {
      lVar10 = uVar9 * 0xb8;
      puVar2 = (uint *)(lVar10 + 0x28 + lVar1);
      *puVar2 = *puVar2 & 0xffffefff;
      *(char *)(lVar10 + 0x45 + lVar1) = (char)uVar13;
      uVar9 = (ulonglong)(*(uint *)(lVar10 + 0x28 + lVar1) >> 0xe & 0xf);
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  bVar5 = false;
  uVar15 = (uint)bVar3;
  if (*(char *)(lVar17 + 0x24 + lVar1) == '\0') {
    lVar17 = lVar1;
    uVar8 = RAID5DirtyStatus(lVar1,(ulonglong)bVar3);
    if ((int)uVar8 != 0) {
      uVar9 = RAID5UnDirtyDiskIndex(lVar17,uVar15);
      uVar12 = (uint)uVar9;
    }
  }
  uVar6 = RAID5DiskTargetId(lVar1,param_3,uVar15,uVar19,0);
  uVar18 = 1;
  uVar16 = uVar6;
  uVar7 = uVar6;
  if (1 < uVar14) {
    do {
      uVar7 = RAID5DiskTargetId(lVar1,param_3,uVar15,uVar19,(byte)uVar18);
      if (bVar5) {
        puVar2 = (uint *)((ulonglong)uVar13 * 0xb8 + 0x28 + lVar1);
        *puVar2 = *puVar2 ^ (uVar7 << 8 ^ *(uint *)((ulonglong)uVar13 * 0xb8 + 0x28 + lVar1)) &
                            0xf00;
        bVar5 = false;
      }
      else {
        lVar17 = (ulonglong)uVar16 * 0xb8;
        if ((*(char *)(lVar17 + 0x24 + lVar1) == '\0') || (uVar12 != uVar7)) {
          uVar16 = uVar7;
        }
        else {
          bVar5 = true;
          uVar16 = uVar13;
        }
        puVar2 = (uint *)(lVar17 + 0x28 + lVar1);
        *puVar2 = *puVar2 ^ (uVar16 << 8 ^ *(uint *)(lVar17 + 0x28 + lVar1)) & 0xf00;
      }
      uVar18 = uVar18 + 1;
      puVar2 = (uint *)((ulonglong)uVar7 * 0xb8 + 0x28 + lVar1);
      *puVar2 = *puVar2 & 0xffffefff;
      *(char *)((ulonglong)uVar7 * 0xb8 + 0x45 + lVar1) = (char)uVar13;
      uVar16 = uVar7;
    } while (uVar18 < uVar14);
  }
  *(uint *)((ulonglong)uVar7 * 0xb8 + 0x28 + lVar1) =
       (uVar6 & 0xf | 0x10) << 8 | *(uint *)((ulonglong)uVar7 * 0xb8 + 0x28 + lVar1) & 0xfffff0ff;
  return;
}



===== RAID5CreateReadSubCmd @ 000284d8 =====

void RAID5CreateReadSubCmd
               (longlong param_1,undefined8 param_2,int param_3,uint param_4,uint param_5,
               undefined8 param_6,longlong param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint *puVar4;
  ulonglong uVar5;
  
  uVar5 = (ulonglong)param_5;
  lVar1 = *(longlong *)(param_7 + ((param_4 << 3) + uVar5) * 8);
  lVar2 = *(longlong *)(lVar1 + 0x10);
  lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0xf0) + 0x38);
  *(undefined4 *)(lVar1 + 0x54) = 0x40;
  *(byte *)(lVar1 + 0x90) = (-(*(int *)(lVar1 + 0x38) != 0) & 0x60U) + 0x28;
  memset(*(void **)(lVar1 + 0x30),0,(ulonglong)*(uint *)(param_1 + 0x380) << 2);
  *(undefined4 *)(lVar1 + 0xa8) = 0;
  puVar4 = *(uint **)(lVar1 + 0x30);
  *(int *)(lVar1 + 0x58) = param_3;
  *(undefined8 *)(lVar1 + 0x40) = param_2;
  *puVar4 = *puVar4 ^ ((uint)(*(int *)(lVar3 + 0x2c8 + uVar5 * 8) -
                             *(int *)(lVar3 + 0x288 + uVar5 * 8)) >> 9 ^ *puVar4) & 0x3ff;
  puVar4 = (uint *)(*(longlong *)(lVar1 + 0x30) + (ulonglong)*(uint *)(lVar1 + 0xa8) * 4);
  *puVar4 = *puVar4 ^ (param_3 << 10 ^
                      *(uint *)(*(longlong *)(lVar1 + 0x30) + (ulonglong)*(uint *)(lVar1 + 0xa8) * 4
                               )) & 0x1ffffc00;
  puVar4 = (uint *)(*(longlong *)(lVar1 + 0x30) + (ulonglong)*(uint *)(lVar1 + 0xa8) * 4);
  *puVar4 = *puVar4 | 0x40000000;
  puVar4 = (uint *)(*(longlong *)(lVar1 + 0x30) + (ulonglong)*(uint *)(lVar1 + 0xa8) * 4);
  *puVar4 = *puVar4 | 0x80000000;
  *(int *)(lVar1 + 0xa8) = *(int *)(lVar1 + 0xa8) + 1;
  *(undefined1 *)((ulonglong)(param_4 >> 1) * 0xd8 + 699 + lVar2) = 2;
  return;
}



===== RAID5BrokenCmd @ 00028600 =====

undefined8
RAID5BrokenCmd(longlong param_1,longlong param_2,ulonglong param_3,undefined8 param_4,int param_5,
              uint param_6,longlong *param_7)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *_Src;
  undefined8 uVar3;
  uint *puVar4;
  undefined8 uVar5;
  void *pvVar6;
  undefined8 *_Dst;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  longlong *plVar15;
  int iVar16;
  
  puVar13 = (undefined8 *)(ulonglong)param_6;
  iVar16 = 1;
  uVar12 = 0;
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
  plVar15 = param_7 + (param_6 << 3);
  lVar8 = (param_3 & 0xffffffff) * 0xb8;
  uVar11 = *(uint *)(lVar8 + 0x3b0 + param_1) & 0xf;
  if (uVar11 != 0) {
    do {
      if ((plVar15[param_3 & 0xffffffff] == 0) &&
         (pvVar6 = RAID5AllocateSubCmd(lVar8,param_2,param_3,param_6,param_7), pvVar6 == (void *)0x0
         )) {
        return 4;
      }
      uVar12 = uVar12 + 1;
      param_3 = (ulonglong)(*(uint *)((param_3 & 0xffffffff) * 0xb8 + 0x3b0 + param_1) >> 8 & 0xf);
    } while (uVar12 < uVar11);
  }
  puVar7 = *(undefined8 **)(param_2 + 0xf0);
  puVar9 = (undefined8 *)(ulonglong)*(uint *)((longlong)puVar7 + 0xc);
  if ((*(uint *)((longlong)puVar7 + 0xc) & 0x80) != 0) {
    uVar10 = 0;
    iVar16 = 2;
    do {
      if (plVar15[uVar10] != 0) {
        _Dst = RAID5AllocateSubCmd(puVar9,param_2,uVar10,param_6 + 1,param_7);
        if (_Dst == (undefined8 *)0x0) {
          return 4;
        }
        _Src = (undefined8 *)plVar15[uVar10];
        puVar9 = *(undefined8 **)(*(longlong *)(_Src[2] + 0xf0) + 0x38);
        puVar7 = (undefined8 *)puVar9[10];
        if ((((puVar7 <= _Dst) && (puVar9 = puVar7 + 0x3c0, _Dst <= puVar9)) && (puVar7 <= _Src)) &&
           (_Src <= puVar9)) {
          puVar1 = _Dst + 6;
          uVar3 = *puVar1;
          if (_Dst != _Src) {
            if ((((uint)_Src | (uint)_Dst) & 0xf) == 0) {
              lVar8 = 1;
              do {
                puVar14 = _Src;
                puVar7 = _Dst;
                uVar5 = puVar14[1];
                *puVar7 = *puVar14;
                puVar7[1] = uVar5;
                uVar5 = puVar14[3];
                puVar7[2] = puVar14[2];
                puVar7[3] = uVar5;
                uVar5 = puVar14[5];
                puVar7[4] = puVar14[4];
                puVar7[5] = uVar5;
                uVar5 = puVar14[7];
                puVar7[6] = puVar14[6];
                puVar7[7] = uVar5;
                uVar5 = puVar14[9];
                puVar7[8] = puVar14[8];
                puVar7[9] = uVar5;
                uVar5 = puVar14[0xb];
                puVar7[10] = puVar14[10];
                puVar7[0xb] = uVar5;
                uVar5 = puVar14[0xd];
                puVar7[0xc] = puVar14[0xc];
                puVar7[0xd] = uVar5;
                uVar5 = puVar14[0xf];
                puVar7[0xe] = puVar14[0xe];
                puVar7[0xf] = uVar5;
                lVar8 = lVar8 + -1;
                _Dst = puVar7 + 0x10;
                _Src = puVar14 + 0x10;
              } while (lVar8 != 0);
              uVar5 = puVar14[0x11];
              puVar7[0x10] = puVar14[0x10];
              puVar7[0x11] = uVar5;
              uVar5 = puVar14[0x13];
              puVar7[0x12] = puVar14[0x12];
              puVar7[0x13] = uVar5;
              uVar5 = puVar14[0x15];
              puVar7[0x14] = puVar14[0x14];
              puVar7[0x15] = uVar5;
              uVar5 = puVar14[0x17];
              puVar7[0x16] = puVar14[0x16];
              puVar7[0x17] = uVar5;
              puVar7 = (undefined8 *)0x0;
            }
            else {
              puVar7 = memcpy(_Dst,_Src,0xc0);
              puVar9 = _Dst;
            }
          }
          *puVar1 = uVar3;
        }
      }
      uVar11 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar11;
    } while (uVar11 < 8);
  }
  if (param_6 < iVar16 + param_6) {
    lVar8 = (0x51 - (ulonglong)(param_6 << 3)) * 8 - (longlong)param_7;
    param_7 = (longlong *)((longlong)puVar13 * 0xd8 + 699 + param_2);
    lVar8 = lVar8 + lVar2;
    puVar7 = puVar13;
    do {
      uVar11 = 0;
      do {
        lVar2 = *plVar15;
        if (lVar2 != 0) {
          *(char *)(lVar2 + 0x4e) = (char)uVar11;
          *(undefined8 *)(lVar2 + 0x40) = param_4;
          *(int *)(lVar2 + 0x58) = param_5;
          memset(*(void **)(lVar2 + 0x30),0,(ulonglong)*(uint *)(param_1 + 0x380) << 2);
          puVar4 = *(uint **)(lVar2 + 0x30);
          *puVar4 = *puVar4 ^ ((uint)(*(int *)((longlong)plVar15 + lVar8 + 0x40) -
                                     *(int *)((longlong)plVar15 + lVar8)) >> 9 ^ *puVar4) & 0x3ff;
          puVar4 = *(uint **)(lVar2 + 0x30);
          *puVar4 = *puVar4 ^ (param_5 << 10 ^ *puVar4) & 0x1ffffc00;
          **(uint **)(lVar2 + 0x30) = **(uint **)(lVar2 + 0x30) | 0x80000000;
          **(uint **)(lVar2 + 0x30) = **(uint **)(lVar2 + 0x30) | 0x40000000;
          *(undefined4 *)(lVar2 + 0x54) = 0;
          *(undefined4 *)(lVar2 + 0xa8) = 1;
          puVar7 = *(undefined8 **)(param_2 + 0xf0);
          if ((char)*(undefined4 *)((longlong)puVar7 + 0xc) < '\0') {
            uVar12 = (int)puVar13 - param_6;
            puVar7 = (undefined8 *)((ulonglong)(uVar12 >> 8) << 8);
            *(uint *)(lVar2 + 0x54) = (-(uint)((uVar12 & 1) != 0) & 0x40) + 0x40;
          }
          else {
            *(undefined4 *)(lVar2 + 0x54) = 0x40;
          }
        }
        uVar11 = uVar11 + 1;
        plVar15 = plVar15 + 1;
      } while (uVar11 < 8);
      uVar11 = (int)puVar13 + 1;
      puVar13 = (undefined8 *)(ulonglong)uVar11;
      lVar8 = lVar8 + -0x40;
      *(undefined1 *)param_7 = 3;
      param_7 = param_7 + 0x1b;
    } while (uVar11 < iVar16 + param_6);
  }
  return CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
}



===== Raid5CreateWriteAllCMD @ 00028988 =====

undefined8
Raid5CreateWriteAllCMD
          (longlong param_1,longlong param_2,undefined8 param_3,int param_4,int param_5,
          undefined8 param_6,longlong *param_7)

{
  uint *puVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  void *pvVar8;
  uint uVar9;
  ulonglong uVar10;
  
  lVar6 = (ulonglong)
          *(byte *)(param_1 + 0x958 + (ulonglong)*(byte *)(*(longlong *)(param_2 + 0xf0) + 6) * 0x28
                   ) * 0xb8;
  uVar10 = 0;
  cVar3 = *(char *)(lVar6 + 0x3a4 + param_1);
  iVar5 = *(int *)(lVar6 + 0x3a8 + param_1);
  lVar6 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
  lVar7 = lVar6;
  do {
    bVar4 = *(byte *)(param_1 + 0xab8 + uVar10 * 2);
    lVar7 = CONCAT71((int7)((ulonglong)lVar7 >> 8),bVar4);
    if ((((bVar4 & 1) != 0) && (lVar7 = uVar10 * 0xb8, *(int *)(lVar7 + 0x3a8 + param_1) == iVar5))
       && (lVar2 = lVar7 + 0x3a4, lVar7 = 0, *(char *)(lVar2 + param_1) == cVar3)) {
      lVar7 = (uint)(param_5 << 3) + uVar10;
      lVar2 = param_7[lVar7];
      if (lVar2 == 0) {
        pvVar8 = RAID5AllocateSubCmd(lVar7,param_2,uVar10,param_5,param_7);
        if (pvVar8 == (void *)0x0) {
          return 4;
        }
        *(char *)((longlong)pvVar8 + 0x4e) = (char)uVar10;
        *(undefined8 *)((longlong)pvVar8 + 0x40) = param_3;
        *(int *)((longlong)pvVar8 + 0x58) = param_4;
        *(undefined4 *)((longlong)pvVar8 + 0x54) = 0x80;
        if (*(char *)(*(longlong *)(param_2 + 0xf0) + 0x48) == '/') {
          *(undefined1 *)((longlong)pvVar8 + 0x90) = 0x2f;
        }
        if (*(char *)(*(longlong *)(param_2 + 0xf0) + 0x48) == -0x71) {
          *(undefined1 *)((longlong)pvVar8 + 0x90) = 0x8f;
        }
        puVar1 = (uint *)(*(longlong *)((longlong)pvVar8 + 0x30) +
                         (ulonglong)*(uint *)((longlong)pvVar8 + 0xa8) * 4);
        *puVar1 = *puVar1 ^ ((uint)(*(int *)(lVar6 + 0x2c8 + uVar10 * 8) -
                                   *(int *)(lVar6 + 0x288 + uVar10 * 8)) >> 9 ^
                            *(uint *)(*(longlong *)((longlong)pvVar8 + 0x30) +
                                     (ulonglong)*(uint *)((longlong)pvVar8 + 0xa8) * 4)) & 0x3ff;
        puVar1 = (uint *)(*(longlong *)((longlong)pvVar8 + 0x30) +
                         (ulonglong)*(uint *)((longlong)pvVar8 + 0xa8) * 4);
        *puVar1 = *puVar1 ^ (param_4 << 10 ^
                            *(uint *)(*(longlong *)((longlong)pvVar8 + 0x30) +
                                     (ulonglong)*(uint *)((longlong)pvVar8 + 0xa8) * 4)) &
                            0x1ffffc00;
        if (*(int *)((longlong)pvVar8 + 0xa8) != 0) {
          puVar1 = (uint *)(*(longlong *)((longlong)pvVar8 + 0x30) +
                           (ulonglong)(*(int *)((longlong)pvVar8 + 0xa8) - 1) * 4);
          *puVar1 = *puVar1 & 0x7fffffff;
        }
        puVar1 = (uint *)(*(longlong *)((longlong)pvVar8 + 0x30) +
                         (ulonglong)*(uint *)((longlong)pvVar8 + 0xa8) * 4);
        *puVar1 = *puVar1 | 0x80000000;
        lVar7 = *(longlong *)((longlong)pvVar8 + 0x30);
        puVar1 = (uint *)(lVar7 + (ulonglong)*(uint *)((longlong)pvVar8 + 0xa8) * 4);
        *puVar1 = *puVar1 | 0x40000000;
        *(int *)((longlong)pvVar8 + 0xa8) = *(int *)((longlong)pvVar8 + 0xa8) + 1;
      }
      else {
        lVar7 = *(longlong *)(param_2 + 0xf0);
        if (*(char *)(lVar7 + 0x48) == '/') {
          *(undefined4 *)(lVar2 + 0x54) = 0x80;
          *(undefined1 *)(lVar2 + 0x90) = 0x2f;
        }
        else if (*(char *)(lVar7 + 0x48) == -0x71) {
          *(undefined4 *)(lVar2 + 0x54) = 0x80;
          *(undefined1 *)(lVar2 + 0x90) = 0x8f;
        }
      }
    }
    uVar9 = (int)uVar10 + 1;
    uVar10 = (ulonglong)uVar9;
  } while (uVar9 < 8);
  return CONCAT71((int7)((ulonglong)lVar7 >> 8),1);
}



===== RAID5CreateParityCMD @ 00028b94 =====

void RAID5CreateParityCMD
               (undefined8 param_1,longlong param_2,undefined8 *param_3,longlong param_4,
               uint param_5,undefined8 param_6,int param_7)

{
  uint *puVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
  if ((undefined8 *)(param_4 + 0x48) != param_3) {
    *(undefined8 *)(param_4 + 0x48) = *param_3;
    *(undefined8 *)(param_4 + 0x50) = param_3[1];
    *(undefined8 *)(param_4 + 0x58) = param_3[2];
    *(undefined8 *)(param_4 + 0x60) = param_3[3];
    *(undefined8 *)(param_4 + 0x68) = param_3[4];
    *(undefined8 *)(param_4 + 0x70) = param_3[5];
    *(undefined8 *)(param_4 + 0x78) = param_3[6];
    *(undefined8 *)(param_4 + 0x80) = param_3[7];
    *(undefined8 *)(param_4 + 0x88) = param_3[8];
    *(undefined8 *)(param_4 + 0x90) = param_3[9];
    *(undefined8 *)(param_4 + 0x98) = param_3[10];
  }
  *(char *)(param_4 + 0x4e) = (char)param_5;
  *(undefined8 *)(param_4 + 0x40) = param_6;
  *(int *)(param_4 + 0x58) = param_7;
  *(undefined4 *)(param_4 + 0x54) = 0x80;
  puVar1 = (uint *)(*(longlong *)(param_4 + 0x30) + (ulonglong)*(uint *)(param_4 + 0xa8) * 4);
  *puVar1 = *puVar1 ^ ((uint)(*(int *)(lVar2 + 0x2c8 + (ulonglong)param_5 * 8) -
                             *(int *)(lVar2 + 0x288 + (ulonglong)param_5 * 8)) >> 9 ^
                      *(uint *)(*(longlong *)(param_4 + 0x30) +
                               (ulonglong)*(uint *)(param_4 + 0xa8) * 4)) & 0x3ff;
  puVar1 = (uint *)(*(longlong *)(param_4 + 0x30) + (ulonglong)*(uint *)(param_4 + 0xa8) * 4);
  *puVar1 = *puVar1 ^ (param_7 << 10 ^
                      *(uint *)(*(longlong *)(param_4 + 0x30) +
                               (ulonglong)*(uint *)(param_4 + 0xa8) * 4)) & 0x1ffffc00;
  if (*(int *)(param_4 + 0xa8) != 0) {
    puVar1 = (uint *)(*(longlong *)(param_4 + 0x30) + (ulonglong)(*(int *)(param_4 + 0xa8) - 1) * 4)
    ;
    *puVar1 = *puVar1 & 0x7fffffff;
  }
  puVar1 = (uint *)(*(longlong *)(param_4 + 0x30) + (ulonglong)*(uint *)(param_4 + 0xa8) * 4);
  *puVar1 = *puVar1 | 0x80000000;
  puVar1 = (uint *)(*(longlong *)(param_4 + 0x30) + (ulonglong)*(uint *)(param_4 + 0xa8) * 4);
  *puVar1 = *puVar1 | 0x40000000;
  *(int *)(param_4 + 0xa8) = *(int *)(param_4 + 0xa8) + 1;
  return;
}



===== RAID5AddSubCmd @ 00028cb8 =====

undefined * RAID5AddSubCmd(undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  code *pcVar7;
  longlong *plVar8;
  longlong *plVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  code *pcVar13;
  ulonglong uVar14;
  longlong local_298 [80];
  
  uVar12 = 0;
  plVar9 = (longlong *)(param_2 + 0xbc0);
  iVar11 = 0;
  if (local_298 != plVar9) {
    if ((((uint)plVar9 | (uint)local_298) & 0xf) == 0) {
      lVar6 = 5;
      plVar8 = local_298;
      do {
        lVar2 = plVar9[1];
        lVar3 = plVar9[2];
        lVar4 = plVar9[3];
        *plVar8 = *plVar9;
        plVar8[1] = lVar2;
        lVar2 = plVar9[4];
        lVar5 = plVar9[5];
        plVar8[2] = lVar3;
        plVar8[3] = lVar4;
        lVar3 = plVar9[6];
        lVar4 = plVar9[7];
        plVar8[4] = lVar2;
        plVar8[5] = lVar5;
        lVar2 = plVar9[8];
        lVar5 = plVar9[9];
        plVar8[6] = lVar3;
        plVar8[7] = lVar4;
        lVar3 = plVar9[10];
        lVar4 = plVar9[0xb];
        plVar8[8] = lVar2;
        plVar8[9] = lVar5;
        lVar2 = plVar9[0xc];
        lVar5 = plVar9[0xd];
        plVar8[10] = lVar3;
        plVar8[0xb] = lVar4;
        lVar3 = plVar9[0xe];
        lVar4 = plVar9[0xf];
        plVar9 = plVar9 + 0x10;
        plVar8[0xc] = lVar2;
        plVar8[0xd] = lVar5;
        plVar8[0xe] = lVar3;
        plVar8[0xf] = lVar4;
        lVar6 = lVar6 + -1;
        plVar8 = plVar8 + 0x10;
      } while (lVar6 != 0);
    }
    else {
      memcpy(local_298,plVar9,0x280);
    }
  }
  pcVar13 = (code *)0x0;
  pcVar7 = (code *)0xa;
  uVar10 = 4;
  if (Hibernate != '\0') {
    uVar10 = 10;
  }
  if (uVar10 != 0) {
    plVar9 = local_298;
    uVar14 = (ulonglong)uVar10;
    do {
      lVar6 = 8;
      do {
        pcVar7 = (code *)0x0;
        if (*plVar9 != 0) {
          *(int *)(*plVar9 + 0xa0) = (int)pcVar13;
          iVar11 = iVar11 + 1;
          pcVar13[param_2 + 0x2a0] = (code)0x1;
          pcVar7 = pcVar13;
        }
        plVar9 = plVar9 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      if (iVar11 != 0) {
        *(int *)(param_2 + 0x10c + (longlong)pcVar13 * 4) = iVar11;
        iVar11 = 0;
        uVar12 = uVar12 + 1;
        if (pcVar13[param_4] != (code)0x0) {
          pcVar7 = *(code **)(param_2 + 0xf0);
          if ((pcVar7[0x48] != (code)0x2f) && (pcVar7[0x48] != (code)0x8f)) {
            pcVar7 = XOROperation;
            *(code **)(param_2 + 0x160 + (longlong)pcVar13 * 8) = XOROperation;
          }
        }
        pcVar13 = (code *)(ulonglong)((int)pcVar13 + 1);
      }
      uVar14 = uVar14 - 1;
    } while (uVar14 != 0);
  }
  *(uint *)(param_2 + 0x104) = uVar12;
  if (uVar12 != 0) {
    plVar9 = local_298;
    uVar14 = (ulonglong)uVar12;
    do {
      lVar6 = 8;
      do {
        lVar2 = *plVar9;
        if (lVar2 != 0) {
          if (*(int *)(param_2 + 0xe98) == 0) {
            cVar1 = *(char *)(lVar2 + 0x90);
            pcVar7 = (code *)CONCAT71((int7)((ulonglong)pcVar7 >> 8),cVar1);
            if ((cVar1 == '/') || (cVar1 == -0x71)) goto LAB_00028e7e;
            uVar12 = *(uint *)(lVar2 + 0x54);
            pcVar7 = (code *)(ulonglong)uVar12;
            if (uVar12 == 0x80) {
              *(undefined1 *)(lVar2 + 0x90) = 0x2a;
            }
            else if (uVar12 == 0x40) {
              *(undefined1 *)(lVar2 + 0x90) = 0x28;
            }
          }
          else {
            *(undefined4 *)(lVar2 + 0x38) = 1;
            if (*(char *)(lVar2 + 0x90) == -0x71) {
LAB_00028e7e:
              *(undefined4 *)(lVar2 + 0x54) = 0x80;
            }
            else {
              uVar12 = *(uint *)(lVar2 + 0x54);
              pcVar7 = (code *)(ulonglong)uVar12;
              if (uVar12 == 0x80) {
                *(undefined1 *)(lVar2 + 0x90) = 0x88;
              }
              else if (uVar12 == 0x40) {
                *(undefined1 *)(lVar2 + 0x90) = 0x8a;
              }
            }
          }
          if (*(int *)(param_2 + 0xea4) != 0) {
            lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
            pcVar7 = (code *)(ulonglong)*(byte *)(lVar3 + 0x278);
            *(longlong *)(lVar3 + 0x78 + (longlong)pcVar7 * 8) = lVar2;
            *(char *)(lVar3 + 0x278) = *(char *)(lVar3 + 0x278) + '\x01';
          }
        }
        plVar9 = plVar9 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      uVar14 = uVar14 - 1;
    } while (uVar14 != 0);
  }
  return pcVar7;
}



===== Raid5NormalDivider @ 00028edc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong Raid5NormalDivider(ulonglong *param_1,undefined8 *param_2,longlong param_3)

{
  uint *puVar1;
  char cVar2;
  undefined8 uVar3;
  bool bVar4;
  byte bVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  void *pvVar8;
  undefined8 *puVar9;
  ulonglong *puVar10;
  ulonglong *puVar11;
  char *pcVar12;
  longlong lVar13;
  uint uVar14;
  longlong lVar15;
  ulonglong *puVar16;
  uint uVar17;
  ulonglong uVar18;
  longlong lVar19;
  uint uVar20;
  byte *pbVar21;
  int iVar22;
  undefined1 auStackY_428 [32];
  ulonglong *in_stack_fffffffffffffc00;
  undefined4 uVar23;
  uint local_3d4;
  char local_3d0;
  bool local_3cf;
  uint local_3cc;
  uint local_3c8;
  int local_3c4;
  int local_3c0;
  uint local_3bc;
  uint local_3b8;
  ulonglong *local_3b0;
  ulonglong *local_3a8;
  longlong local_3a0;
  longlong local_398;
  uint local_390;
  undefined8 local_388;
  ulonglong local_380;
  uint local_378;
  ulonglong local_370;
  uint local_368;
  ulonglong local_360;
  longlong local_358;
  ulonglong local_350;
  longlong local_348;
  ulonglong *local_340;
  ulonglong local_338 [80];
  ulonglong local_b8 [10];
  ulonglong local_68;
  undefined2 local_60;
  byte local_58 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_428;
  local_358 = param_2[3];
  bVar5 = *(byte *)((longlong)param_2 + 6);
  uVar7 = (ulonglong)bVar5;
  lVar19 = uVar7 * 0xb8;
  local_380 = 0;
  puVar16 = param_1 + 0x71;
  local_3d0 = *(char *)(lVar19 + 0x1c + (longlong)puVar16);
  local_3c0 = (int)puVar16[uVar7 * 0x17 + 4];
  local_368 = g_raid5hiberBufSize;
  uVar17 = 0;
  local_3c4 = 0;
  local_3b8 = (int)(g_raid5hiberBufSize + ((int)g_raid5hiberBufSize >> 0x1f & 0x1ffU)) >> 9;
  local_3c8 = *(int *)(param_2 + 2) + 0x1ffU >> 9;
  uVar14 = (uint)((byte)puVar16[uVar7 * 0x17 + 5] & 0xf);
  local_3d4 = 0;
  local_360 = *(ulonglong *)(*(longlong *)(param_3 + 0xf0) + 0x38);
  local_390 = 0xff;
  local_3b0 = param_1;
  local_398 = lVar19;
  local_348 = param_3;
  local_340 = puVar16;
  uVar6 = GetStartEndFromSrb((longlong)param_2,(ulonglong *)&local_3a8,(longlong *)&local_350,
                             *(int *)(param_3 + 0xe98));
  if (bVar5 == 0xff) {
LAB_00028fc5:
    uVar6 = uVar6 & 0xffffffffffffff00;
  }
  else {
    uVar20 = *(uint *)(lVar19 + 0x28 + (longlong)puVar16);
    local_3bc = ((uVar20 >> 0x12 & 0xf) + 1) * (uVar20 >> 0x16) * 4;
    uVar14 = (uVar14 & 0xff) * local_3bc;
    local_378 = uVar14 / uVar14;
    local_68 = 0;
    local_60 = 0;
    memset(local_b8,0,0x50);
    local_58[0] = 0;
    local_58[1] = 0;
    local_58[2] = 0;
    local_58[3] = 0;
    local_58[4] = 0;
    local_58[5] = 0;
    local_58[6] = 0;
    local_58[7] = 0;
    local_58[8] = 0;
    local_58[9] = 0;
    memset(local_338,0,0x280);
    uVar18 = (ulonglong)local_3bc;
    local_370 = (ulonglong)local_3a8 / (ulonglong)uVar14;
    uVar6 = (ulonglong)local_3a8 % (ulonglong)uVar14;
    local_388 = uVar6 % uVar18;
    if (local_3c0 == 5) {
      local_380 = local_370 / local_378;
      bVar5 = BuildRWRaid5Links((longlong)param_1,param_3,(longlong)param_2,local_380);
      uVar7 = (ulonglong)bVar5;
      local_58[0] = *(undefined1 *)(local_398 + 0x45 + (longlong)puVar16);
    }
    local_3cc = (uint)uVar7;
    if ((char)local_3b0[0x857] == '\0') {
      puVar11 = local_3b0 + 0x84c;
      puVar10 = param_1 + 0x75;
      lVar19 = 8;
      do {
        if ((int)*puVar10 != 5) {
          *puVar11 = 0;
        }
        puVar11 = puVar11 + 1;
        puVar10 = puVar10 + 0x17;
        lVar19 = lVar19 + -1;
      } while (lVar19 != 0);
      *(undefined1 *)(local_3b0 + 0x857) = 1;
    }
    if (local_3c0 == 5) {
      lVar19 = 8;
      pcVar12 = (char *)((longlong)param_1 + 0x3a4);
      puVar9 = (undefined8 *)(local_360 + 0x2c8);
      do {
        if (*(int *)(pcVar12 + 4) == 5) {
          if (*pcVar12 == local_3d0) {
            uVar3 = *(undefined8 *)((longlong)local_3b0 + (0x3f58 - local_360) + (longlong)puVar9);
            *puVar9 = uVar3;
            puVar9[-8] = uVar3;
          }
        }
        else {
          *puVar9 = 0;
        }
        puVar9 = puVar9 + 1;
        pcVar12 = pcVar12 + 0xb8;
        lVar19 = lVar19 + -1;
      } while (lVar19 != 0);
    }
    bVar5 = 0;
    uVar14 = (uint)(uVar6 / uVar18);
    uVar18 = uVar7;
    if (uVar14 != 0) {
      do {
        uVar20 = (uint)puVar16[uVar18 * 0x17 + 5] >> 8 & 0xf;
        uVar18 = (ulonglong)uVar20;
        if (uVar20 == 0xf) {
          return 4;
        }
        bVar5 = bVar5 + 1;
      } while (bVar5 < uVar14);
    }
    local_3a0 = uVar7 * 0xb8;
    puVar10 = local_3b0;
    if (*(char *)(local_3a0 + 0x24 + (longlong)puVar16) == '\0') {
      puVar11 = puVar16;
      uVar6 = uVar7;
      uVar7 = RAID5DirtyStatus((longlong)puVar16,uVar7);
      if ((int)uVar7 != 0) {
        uVar7 = RAID5UnDirtyDiskIndex((longlong)puVar11,(uint)uVar6);
        local_390 = (uint)uVar7;
      }
    }
    lVar19 = local_3bc * local_370;
    lVar15 = (local_388 & 0xffffffff) + lVar19;
    puVar11 = (ulonglong *)(ulonglong)local_3c8;
    local_398 = lVar19;
    if (0 < (int)local_3c8) {
      do {
        bVar4 = false;
        pvVar8 = (void *)local_338[uVar18 + (longlong)(int)uVar17 * 8];
        uVar14 = (uint)uVar18;
        if (pvVar8 == (void *)0x0) {
          in_stack_fffffffffffffc00 = local_338;
          pvVar8 = RAIDAllocateSubCmd((longlong)puVar10,param_3,(longlong)param_2,uVar18,uVar17,
                                      (longlong *)in_stack_fffffffffffffc00);
          if (pvVar8 == (void *)0x0) {
            return 4;
          }
          if ((undefined8 *)((longlong)pvVar8 + 0x48) != param_2) {
            *(undefined8 *)((longlong)pvVar8 + 0x48) = *param_2;
            *(undefined8 *)((longlong)pvVar8 + 0x50) = param_2[1];
            *(undefined8 *)((longlong)pvVar8 + 0x58) = param_2[2];
            *(undefined8 *)((longlong)pvVar8 + 0x60) = param_2[3];
            *(undefined8 *)((longlong)pvVar8 + 0x68) = param_2[4];
            *(undefined8 *)((longlong)pvVar8 + 0x70) = param_2[5];
            *(undefined8 *)((longlong)pvVar8 + 0x78) = param_2[6];
            *(undefined8 *)((longlong)pvVar8 + 0x80) = param_2[7];
            *(undefined8 *)((longlong)pvVar8 + 0x88) = param_2[8];
            *(undefined8 *)((longlong)pvVar8 + 0x90) = param_2[9];
            *(undefined8 *)((longlong)pvVar8 + 0x98) = param_2[10];
          }
          *(undefined4 *)((longlong)pvVar8 + 0x58) = 0;
          lVar15 = (local_388 & 0xffffffff) + lVar19;
          *(char *)((longlong)pvVar8 + 0x4e) = (char)uVar18;
          *(longlong *)((longlong)pvVar8 + 0x40) = lVar15;
          puVar11 = (ulonglong *)0x0;
          *(undefined4 *)((longlong)pvVar8 + 0x54) = *(undefined4 *)((longlong)param_2 + 0xc);
          puVar10 = local_3b0;
          if ((*(int *)(local_3a0 + 0x20 + (longlong)puVar16) == 5) &&
             (uVar14 == *(byte *)(local_3a0 + 0x45 + (longlong)puVar16))) {
            local_3c4 = 1;
          }
        }
        else {
          puVar11 = (ulonglong *)(ulonglong)*(uint *)((longlong)pvVar8 + 0xa8);
        }
        uVar20 = local_3bc - (int)local_388;
        puVar1 = (uint *)(*(longlong *)((longlong)pvVar8 + 0x30) + (longlong)puVar11 * 4);
        *puVar1 = *puVar1 ^ ((uint)((int)local_358 - *(int *)(param_2 + 3)) >> 9 ^
                            *(uint *)(*(longlong *)((longlong)pvVar8 + 0x30) + (longlong)puVar11 * 4
                                     )) & 0x3ff;
        puVar1 = (uint *)(*(longlong *)((longlong)pvVar8 + 0x30) + (longlong)puVar11 * 4);
        *puVar1 = *puVar1 & 0xbfffffff;
        uVar23 = (undefined4)((ulonglong)in_stack_fffffffffffffc00 >> 0x20);
        if (uVar20 < local_3c8) {
          local_3cf = true;
          if (local_3b8 < uVar20) goto LAB_00029314;
        }
        else {
          if (local_3c8 <= local_3b8) {
            iVar22 = local_3c8 * 0x200;
            lVar19 = (longlong)(int)uVar17;
            *(int *)(param_3 + 0xb20 + lVar19 * 4) = iVar22;
            puVar1 = (uint *)(*(longlong *)((longlong)pvVar8 + 0x30) + (longlong)puVar11 * 4);
            *puVar1 = *puVar1 ^ (local_3c8 << 0x13 ^
                                *(uint *)(*(longlong *)((longlong)pvVar8 + 0x30) +
                                         (longlong)puVar11 * 4)) & 0x1ffffc00;
            uVar7 = *(ulonglong *)((longlong)pvVar8 + 0x30);
            puVar1 = (uint *)(uVar7 + (longlong)puVar11 * 4);
            *puVar1 = *puVar1 | 0x80000000;
            *(int *)((longlong)pvVar8 + 0x58) = *(int *)((longlong)pvVar8 + 0x58) + iVar22;
            *(int *)((longlong)pvVar8 + 0xa8) = *(int *)((longlong)pvVar8 + 0xa8) + 1;
            if (*(int *)(local_3a0 + 0x20 + (longlong)puVar16) != 5) break;
            local_b8[lVar19] = local_380;
            if ((*(char *)(param_2 + 9) == '/') || (*(char *)(param_2 + 9) == -0x71)) {
              uVar7 = Raid5CreateWriteAllCMD
                                ((longlong)puVar10,param_3,lVar15,iVar22,uVar17,
                                 in_stack_fffffffffffffc00,(longlong *)local_338);
              puVar11 = puVar10;
            }
            else {
              cVar2 = *(char *)(local_3a0 + 0x24 + (longlong)puVar16);
              puVar11 = (ulonglong *)CONCAT71((int7)((ulonglong)puVar11 >> 8),cVar2);
              if ((cVar2 == '\0') && (*(char *)(local_3a0 + 0x44 + (longlong)puVar16) == -1)) {
                uVar7 = (ulonglong)*(uint *)((longlong)param_2 + 0xc);
                if ((char)*(uint *)((longlong)param_2 + 0xc) < '\0') {
LAB_000296c6:
                  uVar7 = RAID5NormalWriteCmd((longlong)puVar10,param_3,param_2,local_3cc,
                                              (longlong)local_58,(longlong)&local_68,lVar15,iVar22,
                                              &local_3d4,(longlong *)local_338);
                  puVar11 = puVar10;
                  uVar17 = local_3d4;
                }
                break;
              }
              uVar7 = (ulonglong)*(uint *)((longlong)param_2 + 0xc);
              if ((*(uint *)((longlong)param_2 + 0xc) & 0x40) == 0) {
                if (cVar2 == '\0') {
                  if (((local_390 == uVar14) || (local_390 == 0xff)) ||
                     (local_390 == *(byte *)(local_3a0 + 0x45 + (longlong)puVar16)))
                  goto LAB_000296c6;
                  uVar7 = RAID5DirtyWriteCmd((longlong)puVar10,param_3,uVar18,local_390,lVar15,
                                             iVar22,uVar17,(longlong *)local_338);
                }
                else {
                  if (*(char *)(local_3a0 + 0x45 + (longlong)puVar16) == -1) goto LAB_0002982b;
                  uVar7 = RAID5BrokenCmd((longlong)puVar10,param_3,(ulonglong)local_3cc,lVar15,
                                         iVar22,uVar17,(longlong *)local_338);
                }
                *(longlong *)(param_3 + 0xe48 + lVar19 * 8) = lVar15;
                *(undefined1 *)((longlong)local_b8 + lVar19 + 0x50) = 1;
                *(longlong *)(param_3 + 0xe50 + lVar19 * 8) = lVar15;
                puVar11 = puVar10;
                uVar17 = uVar17 + 2;
                break;
              }
              if (local_3c4 == 1) {
                uVar7 = RAID5BrokenCmd((longlong)puVar10,param_3,(ulonglong)local_3cc,lVar15,iVar22,
                                       uVar17,(longlong *)local_338);
                *(longlong *)(param_3 + 0xe48 + lVar19 * 8) = lVar15;
                *(undefined1 *)((longlong)local_b8 + lVar19 + 0x50) = 1;
                puVar11 = puVar10;
              }
            }
LAB_0002982b:
            uVar17 = uVar17 + 1;
            break;
          }
LAB_00029314:
          local_3cf = local_3b8 == uVar20;
          bVar4 = true;
        }
        uVar20 = uVar20 * 0x200;
        if (bVar4) {
          uVar20 = local_368;
        }
        *(uint *)(param_3 + 0xb20 + (longlong)(int)uVar17 * 4) = uVar20;
        puVar1 = (uint *)(*(longlong *)((longlong)pvVar8 + 0x30) + (longlong)puVar11 * 4);
        *puVar1 = *puVar1 ^ (uVar20 << 10 ^
                            *(uint *)(*(longlong *)((longlong)pvVar8 + 0x30) + (longlong)puVar11 * 4
                                     )) & 0x1ffffc00;
        *(int *)((longlong)pvVar8 + 0x58) = *(int *)((longlong)pvVar8 + 0x58) + uVar20;
        puVar1 = (uint *)(*(longlong *)((longlong)pvVar8 + 0x30) + (longlong)puVar11 * 4);
        *puVar1 = *puVar1 | 0x80000000;
        local_3c8 = local_3c8 - (uVar20 >> 9);
        local_350 = (ulonglong)uVar20;
        local_358 = local_358 + local_350;
        if (local_3cf) {
          local_388 = (ulonglong)local_388._4_4_ << 0x20;
          uVar7 = local_350;
        }
        else {
          uVar7 = (ulonglong)local_3b8;
          local_388 = CONCAT44(local_388._4_4_,(int)local_388 + local_3b8);
        }
        *(int *)((longlong)pvVar8 + 0xa8) = *(int *)((longlong)pvVar8 + 0xa8) + 1;
        puVar11 = (ulonglong *)(ulonglong)local_3c8;
        if ((int)local_3c8 < 1) break;
        local_3a8 = (ulonglong *)(uVar18 * 0xb8);
        if (((*(uint *)((longlong)(local_3a8 + 5) + (longlong)puVar16) >> 0xc & 1) != 0) &&
           (local_3cf)) {
          local_370 = local_370 + 1;
          local_398 = local_398 + (ulonglong)local_3bc;
        }
        lVar19 = (longlong)(int)uVar17;
        local_b8[lVar19] = local_380;
        if ((*(char *)(param_2 + 9) == '/') || (*(char *)(param_2 + 9) == -0x71)) {
          Raid5CreateWriteAllCMD
                    ((longlong)puVar10,param_3,lVar15,uVar20,uVar17,in_stack_fffffffffffffc00,
                     (longlong *)local_338);
LAB_00029562:
          uVar17 = uVar17 + 1;
LAB_00029564:
          local_3d4 = uVar17;
        }
        else {
          cVar2 = *(char *)(local_3a0 + 0x24 + (longlong)puVar16);
          if ((cVar2 != '\0') || (*(char *)(local_3a0 + 0x44 + (longlong)puVar16) != -1)) {
            if ((*(uint *)((longlong)param_2 + 0xc) & 0x40) != 0) {
              if (local_3c4 == 1) {
                in_stack_fffffffffffffc00 = (ulonglong *)CONCAT44(uVar23,uVar17);
                RAID5BrokenCmd((longlong)puVar10,param_3,(ulonglong)local_3cc,lVar15,uVar20,uVar17,
                               (longlong *)local_338);
                *(undefined1 *)((longlong)local_b8 + lVar19 + 0x50) = 1;
                *(longlong *)(param_3 + 0xe48 + lVar19 * 8) = lVar15;
              }
              goto LAB_00029562;
            }
            if (cVar2 == '\0') {
              if (((local_390 == uVar14) || (local_390 == 0xff)) ||
                 (local_390 == *(byte *)(local_3a0 + 0x45 + (longlong)puVar16))) goto LAB_00029409;
              in_stack_fffffffffffffc00 = (ulonglong *)CONCAT44(uVar23,uVar20);
              RAID5DirtyWriteCmd((longlong)puVar10,param_3,uVar18,local_390,lVar15,uVar20,uVar17,
                                 (longlong *)local_338);
            }
            else {
              if (*(char *)(local_3a0 + 0x45 + (longlong)puVar16) == -1) goto LAB_00029562;
              in_stack_fffffffffffffc00 = (ulonglong *)CONCAT44(uVar23,uVar17);
              RAID5BrokenCmd((longlong)puVar10,param_3,(ulonglong)local_3cc,lVar15,uVar20,uVar17,
                             (longlong *)local_338);
            }
            *(longlong *)(param_3 + 0xe48 + lVar19 * 8) = lVar15;
            *(undefined1 *)((longlong)local_b8 + lVar19 + 0x50) = 1;
            uVar17 = uVar17 + 2;
            *(longlong *)(param_3 + 0xe50 + lVar19 * 8) = lVar15;
            goto LAB_00029564;
          }
          if ((char)*(undefined4 *)((longlong)param_2 + 0xc) < '\0') {
LAB_00029409:
            in_stack_fffffffffffffc00 = &local_68;
            RAID5NormalWriteCmd((longlong)puVar10,param_3,param_2,local_3cc,(longlong)local_58,
                                (longlong)in_stack_fffffffffffffc00,lVar15,uVar20,&local_3d4,
                                (longlong *)local_338);
            uVar17 = local_3d4;
          }
        }
        lVar19 = local_398;
        lVar13 = 8;
        puVar10 = (ulonglong *)(local_360 + 0x2c8);
        do {
          uVar6 = *puVar10;
          if (uVar6 != 0) {
            uVar6 = uVar6 + local_350;
            *puVar10 = uVar6;
          }
          puVar10 = puVar10 + 1;
          lVar13 = lVar13 + -1;
        } while (lVar13 != 0);
        if (local_3cf != false) {
          if (((local_3c0 == 5) &&
              (uVar6 = local_370 / local_378, local_370 % (ulonglong)local_378 == 0)) &&
             (uVar6 = (ulonglong)*(uint *)((longlong)(local_3a8 + 5) + (longlong)puVar16),
             (*(uint *)((longlong)(local_3a8 + 5) + (longlong)puVar16) >> 0xc & 1) != 0)) {
            local_380 = local_380 + 1;
            uVar6 = BuildRWRaid5Links((longlong)local_3b0,param_3,(longlong)param_2,local_380);
            local_3c4 = 0;
            uVar18 = uVar6 & 0xff;
            bVar5 = *(byte *)(local_3a0 + 0x45 + (longlong)puVar16);
            uVar6 = CONCAT71((int7)(uVar6 >> 8),bVar5);
            local_58[(int)uVar17] = bVar5;
            lVar15 = lVar19;
          }
          else {
            uVar18 = (ulonglong)
                     (*(uint *)((longlong)(local_3a8 + 5) + (longlong)puVar16) >> 8 & 0xf);
          }
        }
        if ((int)uVar18 == 0xf) goto LAB_00028fc5;
        puVar10 = local_3b0;
      } while( true );
    }
    puVar10 = local_3b0;
    if (local_3c0 == 5) {
      if (uVar17 == 0) {
        uVar17 = 1;
      }
      if (((int)local_3b0[0x85b] == 0) ||
         (*(char *)(local_3a0 + 0x24 + (longlong)puVar16) == '\x01')) {
        uVar6 = 0;
        if (0 < (int)uVar17) {
          do {
            iVar22 = (int)uVar6;
            if ((*(uint *)(*(longlong *)(param_3 + 0xf0) + 0xc) & 0x40) != 0) {
              uVar6 = (ulonglong)iVar22;
            }
            lVar19 = (longlong)iVar22;
            puVar11 = (ulonglong *)((uVar6 + 0x2f) * 0x40 + param_3);
            if (puVar11 != local_338 + lVar19 * 8) {
              *puVar11 = local_338[lVar19 * 8];
              puVar11[1] = local_338[lVar19 * 8 + 1];
              puVar11[2] = local_338[lVar19 * 8 + 2];
              puVar11[3] = local_338[lVar19 * 8 + 3];
              puVar11[4] = local_338[lVar19 * 8 + 4];
              puVar11[5] = local_338[lVar19 * 8 + 5];
              puVar11[6] = local_338[lVar19 * 8 + 6];
              puVar11[7] = local_338[lVar19 * 8 + 7];
            }
            uVar6 = (ulonglong)(iVar22 + 1U);
          } while ((int)(iVar22 + 1U) < (int)uVar17);
        }
      }
      else {
        uVar6 = 0;
        iVar22 = 0;
        if (0 < (int)uVar17) {
          pbVar21 = local_58;
          puVar16 = local_338;
          local_3a8 = local_b8;
          do {
            if ((((*(uint *)(*(longlong *)(param_3 + 0xf0) + 0xc) & 0x40) == 0) &&
                (cVar2 = *(char *)(*(longlong *)(param_3 + 0xf0) + 0x48), cVar2 != '/')) &&
               (cVar2 != -0x71)) {
              uVar14 = ExchangeDelayedCmd((longlong)puVar10,param_3,(longlong)local_338,
                                          (longlong)&local_68,*local_3a8,(uint)*pbVar21,iVar22,
                                          (uint)uVar6);
              uVar6 = (ulonglong)uVar14;
            }
            else {
              puVar11 = (ulonglong *)((param_3 - (longlong)local_338) + 0xbc0 + (longlong)puVar16);
              if (puVar11 != puVar16) {
                *puVar11 = *puVar16;
                puVar11[1] = puVar16[1];
                puVar11[2] = puVar16[2];
                puVar11[3] = puVar16[3];
                puVar11[4] = puVar16[4];
                puVar11[5] = puVar16[5];
                puVar11[6] = puVar16[6];
                puVar11[7] = puVar16[7];
              }
            }
            iVar22 = iVar22 + 1;
            puVar16 = puVar16 + 8;
            puVar11 = local_3a8 + 1;
            pbVar21 = pbVar21 + 1;
            local_3a8 = puVar11;
          } while (iVar22 < (int)uVar17);
          puVar16 = local_340;
        }
      }
      RAID5AddSubCmd(puVar11,param_3,uVar6,(longlong)&local_68);
      lVar19 = 8;
      puVar10 = (ulonglong *)(local_360 + 0x2c8);
      pcVar12 = (char *)((longlong)puVar16 + 0x1c);
      do {
        if ((*(int *)(pcVar12 + 4) == 5) && (*pcVar12 == local_3d0)) {
          local_360 = puVar10[-8];
          *puVar10 = local_360;
        }
        puVar10 = puVar10 + 1;
        pcVar12 = pcVar12 + 0xb8;
        lVar19 = lVar19 + -1;
      } while (lVar19 != 0);
      uVar7 = local_360;
      param_3 = local_348;
    }
    *(undefined4 *)(param_3 + 0xb70) = 0;
    iVar22 = 1;
    if (1 < *(int *)(param_3 + 0x104)) {
      do {
        lVar19 = (longlong)iVar22;
        iVar22 = iVar22 + 1;
        *(int *)(param_3 + 0xb70 + lVar19 * 4) =
             *(int *)(param_3 + 0xb6c + lVar19 * 4) + *(int *)(param_3 + 0xb1c + lVar19 * 4);
      } while (iVar22 < *(int *)(param_3 + 0x104));
    }
    uVar6 = CONCAT71((int7)(uVar7 >> 8),1);
  }
  return uVar6;
}



===== Raid5NormalDivide @ 00029ab8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong Raid5NormalDivide(ulonglong *param_1,undefined8 *param_2,longlong param_3)

{
  uint *puVar1;
  char cVar2;
  ulonglong uVar3;
  longlong lVar4;
  byte bVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  void *pvVar9;
  ulonglong *puVar10;
  ulonglong *puVar11;
  ulonglong *puVar12;
  int iVar13;
  byte *pbVar14;
  ulonglong *puVar15;
  uint uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ulonglong *puVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  longlong lVar23;
  uint uVar24;
  int iVar25;
  longlong lVar26;
  undefined1 auStackY_288 [32];
  ulonglong *in_stack_fffffffffffffda0;
  undefined4 uVar27;
  undefined8 local_238;
  byte local_230 [4];
  uint local_22c;
  ulonglong *local_228;
  uint local_220;
  longlong local_218;
  uint local_210;
  int local_20c;
  int local_208;
  undefined8 *local_200;
  uint local_1f8;
  uint local_1f4;
  ulonglong *local_1f0;
  undefined8 local_1e8;
  ulonglong local_1e0;
  uint local_1d8;
  longlong local_1d0;
  ulonglong local_1c8;
  longlong local_1c0;
  ulonglong *local_1b8;
  longlong local_1b0;
  ulonglong *local_1a8;
  ulonglong local_198 [32];
  int local_98 [4];
  ulonglong local_88 [8];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  local_1c0 = param_2[3];
  bVar5 = *(byte *)((longlong)param_2 + 6);
  uVar17 = (ulonglong)bVar5;
  lVar23 = uVar17 * 0xb8;
  puVar12 = param_1 + 0x71;
  local_20c = (int)puVar12[uVar17 * 0x17 + 4];
  uVar6 = 0;
  local_1d8 = (uint)*(byte *)(lVar23 + 0x1c + (longlong)puVar12);
  uVar16 = (uint)puVar12[uVar17 * 0x17 + 5];
  local_220 = *(int *)(param_2 + 2) + 0x1ffU >> 9;
  local_210 = uVar16 >> 0x16;
  uVar21 = uVar16 & 0xf;
  iVar20 = (uVar16 >> 0x12 & 0xf) + 1;
  uVar24 = local_210 * uVar21;
  local_1f4 = (iVar20 * uVar21 * 0x200) / uVar24;
  uVar16 = 0;
  local_1b8 = *(ulonglong **)(*(longlong *)(param_3 + 0xf0) + 0x38);
  local_1e0 = 0;
  local_238._4_4_ = 0;
  local_208 = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  local_230[0] = 0;
  local_230[1] = 0;
  local_230[2] = 0;
  local_230[3] = 0;
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_238._0_4_ = 0;
  local_1f8 = 0xff;
  local_228 = param_1;
  local_200 = param_2;
  local_1b0 = local_1c0;
  local_1a8 = puVar12;
  uVar7 = GetStartEndFromSrb((longlong)param_2,(ulonglong *)&local_1f0,&local_1d0,
                             *(int *)(param_3 + 0xe98));
  if (bVar5 == 0xff) {
LAB_00029be7:
    uVar7 = uVar7 & 0xffffffffffffff00;
  }
  else {
    if (local_20c == 5) {
      local_210 = iVar20 * local_210 * 4;
      uVar24 = local_210 * uVar21;
      local_1f4 = uVar24 / uVar24;
      local_238._0_4_ = 0;
      local_88[0] = 0;
      local_88[1] = 0;
      local_98[0] = 0;
      local_98[1] = 0;
      local_98[2] = 0;
      local_98[3] = 0;
      local_230[0] = 0;
      local_230[1] = 0;
      local_230[2] = 0;
      local_230[3] = 0;
    }
    memset(local_198,0,0x100);
    uVar18 = (ulonglong)local_210;
    local_1c8 = (ulonglong)local_1f0 / (ulonglong)uVar24;
    uVar7 = (ulonglong)local_1f0 % (ulonglong)uVar24;
    local_1e8 = uVar7 % uVar18;
    if (local_20c == 5) {
      local_1e0 = local_1c8 / local_1f4;
      bVar5 = BuildRWRaid5Links((longlong)local_228,param_3,(longlong)local_200,local_1e0);
      uVar17 = (ulonglong)bVar5;
      local_230[0] = *(undefined1 *)(lVar23 + 0x45 + (longlong)puVar12);
    }
    local_22c = (uint)uVar17;
    iVar20 = 1;
    if ((char)local_228[0x857] == '\0') {
      puVar11 = local_228 + 0x84c;
      puVar19 = param_1 + 0x75;
      lVar23 = 8;
      do {
        if ((int)*puVar19 != 5) {
          *puVar11 = 0;
        }
        puVar11 = puVar11 + 1;
        puVar19 = puVar19 + 0x17;
        lVar23 = lVar23 + -1;
      } while (lVar23 != 0);
      *(undefined1 *)(local_228 + 0x857) = 1;
    }
    if (local_20c == 5) {
      pbVar14 = (byte *)((longlong)param_1 + 0x3a4);
      puVar19 = local_1b8 + 0x59;
      lVar23 = 8;
      do {
        lVar26 = lVar23;
        if (*(int *)(pbVar14 + 4) == 5) {
          if (*pbVar14 == local_1d8) {
            uVar3 = *(ulonglong *)
                     ((longlong)local_228 + (0x3f58 - (longlong)local_1b8) + (longlong)puVar19);
            *puVar19 = uVar3;
            puVar19[-8] = uVar3;
          }
        }
        else {
          *puVar19 = 0;
        }
        puVar19 = puVar19 + 1;
        pbVar14 = pbVar14 + 0xb8;
        lVar23 = lVar26 + -1;
      } while (lVar23 != 0);
      iVar20 = (int)lVar26;
    }
    iVar13 = 0;
    iVar25 = (int)(uVar7 / uVar18);
    uVar18 = uVar17;
    if (0 < iVar25) {
      do {
        uVar21 = (uint)puVar12[uVar18 * 0x17 + 5] >> 8 & 0xf;
        uVar18 = (ulonglong)uVar21;
        if (uVar21 == 0xf) {
          return 4;
        }
        iVar13 = iVar13 + iVar20;
      } while (iVar13 < iVar25);
    }
    lVar23 = uVar17 * 0xb8;
    local_218 = lVar23;
    puVar19 = local_228;
    if (*(char *)(lVar23 + 0x24 + (longlong)puVar12) == '\0') {
      puVar11 = puVar12;
      uVar8 = RAID5DirtyStatus((longlong)puVar12,uVar17);
      if ((int)uVar8 != 0) {
        uVar7 = RAID5UnDirtyDiskIndex((longlong)puVar11,(uint)uVar17);
        local_1f8 = (uint)uVar7;
      }
    }
    lVar26 = (local_1e8 & 0xffffffff) + local_210 * local_1c8;
    local_1d0 = local_210 * local_1c8;
    puVar11 = (ulonglong *)(ulonglong)local_220;
    if (0 < (int)local_220) {
      do {
        pvVar9 = (void *)local_198[uVar18 + (ulonglong)uVar16 * 8];
        uVar21 = (uint)uVar18;
        if (pvVar9 == (void *)0x0) {
          in_stack_fffffffffffffda0 = local_198;
          pvVar9 = RAIDAllocateSubCmd((longlong)puVar19,param_3,(longlong)local_200,uVar18,uVar16,
                                      (longlong *)in_stack_fffffffffffffda0);
          if (pvVar9 == (void *)0x0) {
            return 4;
          }
          local_98[uVar16] = local_98[uVar16] + 1;
          if ((undefined8 *)((longlong)pvVar9 + 0x48) != local_200) {
            *(undefined8 *)((longlong)pvVar9 + 0x48) = *local_200;
            *(undefined8 *)((longlong)pvVar9 + 0x50) = local_200[1];
            *(undefined8 *)((longlong)pvVar9 + 0x58) = local_200[2];
            *(undefined8 *)((longlong)pvVar9 + 0x60) = local_200[3];
            *(undefined8 *)((longlong)pvVar9 + 0x68) = local_200[4];
            *(undefined8 *)((longlong)pvVar9 + 0x70) = local_200[5];
            *(undefined8 *)((longlong)pvVar9 + 0x78) = local_200[6];
            *(undefined8 *)((longlong)pvVar9 + 0x80) = local_200[7];
            *(undefined8 *)((longlong)pvVar9 + 0x88) = local_200[8];
            *(undefined8 *)((longlong)pvVar9 + 0x90) = local_200[9];
            *(undefined8 *)((longlong)pvVar9 + 0x98) = local_200[10];
          }
          *(undefined4 *)((longlong)pvVar9 + 0x58) = 0;
          *(char *)((longlong)pvVar9 + 0x4e) = (char)uVar18;
          lVar26 = (local_1e8 & 0xffffffff) + local_1d0;
          uVar7 = 0;
          *(longlong *)((longlong)pvVar9 + 0x40) = lVar26;
          *(undefined4 *)((longlong)pvVar9 + 0x54) = *(undefined4 *)((longlong)local_200 + 0xc);
          if ((*(int *)(lVar23 + 0x20 + (longlong)puVar12) == 5) &&
             (uVar21 == *(byte *)(lVar23 + 0x45 + (longlong)puVar12))) {
            local_208 = 1;
          }
          puVar19 = local_228;
        }
        else {
          uVar7 = (ulonglong)*(uint *)((longlong)pvVar9 + 0xa8);
        }
        puVar1 = (uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + uVar7 * 4);
        *puVar1 = *puVar1 ^ ((uint)((int)local_1c0 - (int)local_1b0) >> 9 ^
                            *(uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + uVar7 * 4)) & 0x3ff;
        puVar1 = (uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + uVar7 * 4);
        *puVar1 = *puVar1 & 0xbfffffff;
        uVar24 = (local_220 - local_210) + (int)local_1e8;
        puVar12 = puVar19 + 0x71;
        iVar20 = (int)uVar7;
        if ((int)uVar24 < 1) {
          uVar22 = local_220 * 0x200;
          local_1e8 = (ulonglong)local_1e8._4_4_ << 0x20;
          uVar24 = (local_220 << 0x13 ^
                   *(uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + uVar7 * 4)) & 0x1ffffc00;
          puVar11 = (ulonglong *)(ulonglong)uVar24;
          puVar1 = (uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + uVar7 * 4);
          *puVar1 = *puVar1 ^ uVar24;
          if (-1 < iVar20 + -1) {
            puVar11 = (ulonglong *)(ulonglong)(iVar20 - 1);
            puVar1 = (uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + (longlong)puVar11 * 4);
            *puVar1 = *puVar1 & 0x7fffffff;
          }
          local_220 = 0;
          puVar1 = (uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + uVar7 * 4);
          *puVar1 = *puVar1 | 0x80000000;
          *(int *)((longlong)pvVar9 + 0x58) = *(int *)((longlong)pvVar9 + 0x58) + uVar22;
          *(int *)((longlong)pvVar9 + 0xa8) = *(int *)((longlong)pvVar9 + 0xa8) + 1;
          lVar23 = local_218;
          if (*(int *)(local_218 + 0x20 + (longlong)puVar12) != 5) break;
          local_88[uVar16] = local_1e0;
          if ((*(char *)(local_200 + 9) != '/') && (*(char *)(local_200 + 9) != -0x71)) {
            cVar2 = *(char *)(local_218 + 0x24 + (longlong)puVar12);
            puVar11 = (ulonglong *)CONCAT71((int7)((ulonglong)puVar11 >> 8),cVar2);
            if ((cVar2 == '\0') && (*(char *)(local_218 + 0x44 + (longlong)puVar12) == -1)) {
              if ((char)*(undefined4 *)((longlong)local_200 + 0xc) < '\0') {
LAB_0002a32e:
                RAID5NormalWriteCmd((longlong)puVar19,param_3,local_200,local_22c,
                                    (longlong)local_230,(longlong)&local_238,lVar26,uVar22,
                                    (uint *)((longlong)&local_238 + 4),(longlong *)local_198);
                puVar11 = puVar19;
                lVar23 = local_218;
                uVar16 = local_238._4_4_;
              }
            }
            else if ((*(uint *)((longlong)local_200 + 0xc) & 0x40) == 0) {
              if (cVar2 == '\0') {
                if (((local_1f8 == uVar21) || (local_1f8 == 0xff)) ||
                   (local_1f8 == *(byte *)(local_218 + 0x45 + (longlong)puVar12)))
                goto LAB_0002a32e;
                RAID5DirtyWriteCmd((longlong)puVar19,param_3,uVar18,local_1f8,lVar26,uVar22,uVar16,
                                   (longlong *)local_198);
              }
              else {
                if (*(char *)(local_218 + 0x45 + (longlong)puVar12) == -1) goto LAB_0002a540;
                RAID5BrokenCmd((longlong)puVar19,param_3,(ulonglong)local_22c,lVar26,uVar22,uVar16,
                               (longlong *)local_198);
              }
              lVar23 = local_218;
              *(longlong *)(param_3 + 0xe48 + (ulonglong)uVar16 * 8) = lVar26;
              local_230[(ulonglong)uVar16 - 8] = 1;
              *(longlong *)(param_3 + 0xe48 + (ulonglong)(uVar16 + 1) * 8) = lVar26;
              puVar11 = puVar19;
              uVar16 = uVar16 + 2;
            }
            else {
              if (local_208 == 1) {
                RAID5BrokenCmd((longlong)puVar19,param_3,(ulonglong)local_22c,lVar26,uVar22,uVar16,
                               (longlong *)local_198);
                local_230[(ulonglong)uVar16 - 8] = 1;
                *(longlong *)(param_3 + 0xe48 + (ulonglong)uVar16 * 8) = lVar26;
                puVar11 = puVar19;
              }
LAB_0002a540:
              lVar23 = local_218;
              uVar16 = uVar16 + 1;
            }
            break;
          }
          Raid5CreateWriteAllCMD
                    ((longlong)puVar19,param_3,lVar26,uVar22,uVar16,in_stack_fffffffffffffda0,
                     (longlong *)local_198);
          uVar16 = uVar16 + 1;
          puVar11 = (ulonglong *)0x0;
          local_238._4_4_ = uVar16;
        }
        else {
          iVar13 = local_210 - (int)local_1e8;
          uVar22 = iVar13 * 0x200;
          puVar1 = (uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + uVar7 * 4);
          *puVar1 = *puVar1 ^ (iVar13 * 0x80000 ^
                              *(uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + uVar7 * 4)) &
                              0x1ffffc00;
          *(int *)((longlong)pvVar9 + 0x58) = *(int *)((longlong)pvVar9 + 0x58) + uVar22;
          if (-1 < iVar20 + -1) {
            puVar1 = (uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + (ulonglong)(iVar20 - 1) * 4);
            *puVar1 = *puVar1 & 0x7fffffff;
          }
          puVar11 = (ulonglong *)(ulonglong)uVar24;
          puVar1 = (uint *)(*(longlong *)((longlong)pvVar9 + 0x30) + uVar7 * 4);
          *puVar1 = *puVar1 | 0x80000000;
          local_220 = uVar24;
          local_1c0 = local_1c0 + (ulonglong)uVar22;
          *(int *)((longlong)pvVar9 + 0xa8) = *(int *)((longlong)pvVar9 + 0xa8) + 1;
          local_1e8 = (ulonglong)local_1e8._4_4_ << 0x20;
        }
        puVar19 = local_228;
        lVar23 = local_218;
        if ((int)puVar11 < 1) break;
        local_1f0 = (ulonglong *)(uVar18 * 0xb8);
        uVar24 = *(uint *)((longlong)((ulonglong *)(uVar18 * 0xb8) + 5) + (longlong)puVar12);
        uVar7 = (ulonglong)uVar24;
        if ((uVar24 >> 0xc & 1) != 0) {
          local_1c8 = local_1c8 + 1;
          local_1d0 = local_1d0 + (ulonglong)local_210;
        }
        if (local_20c == 5) {
          local_88[uVar16] = local_1e0;
          if ((*(char *)(local_200 + 9) == '/') || (*(char *)(local_200 + 9) == -0x71)) {
            Raid5CreateWriteAllCMD
                      ((longlong)local_228,param_3,lVar26,uVar22,uVar16,in_stack_fffffffffffffda0,
                       (longlong *)local_198);
            uVar16 = uVar16 + 1;
LAB_0002a2ab:
            local_238._4_4_ = uVar16;
          }
          else {
            cVar2 = *(char *)(local_218 + 0x24 + (longlong)puVar12);
            if ((cVar2 == '\0') && (*(char *)(local_218 + 0x44 + (longlong)puVar12) == -1)) {
              if ((char)*(undefined4 *)((longlong)local_200 + 0xc) < '\0') {
LAB_0002a0bd:
                in_stack_fffffffffffffda0 = &local_238;
                RAID5NormalWriteCmd((longlong)local_228,param_3,local_200,local_22c,
                                    (longlong)local_230,(longlong)in_stack_fffffffffffffda0,lVar26,
                                    uVar22,(uint *)((longlong)&local_238 + 4),(longlong *)local_198)
                ;
                uVar16 = local_238._4_4_;
              }
            }
            else {
              uVar27 = (undefined4)((ulonglong)in_stack_fffffffffffffda0 >> 0x20);
              if ((*(uint *)((longlong)local_200 + 0xc) & 0x40) == 0) {
                if (cVar2 == '\0') {
                  if (((local_1f8 == uVar21) || (local_1f8 == 0xff)) ||
                     (local_1f8 == *(byte *)(local_218 + 0x45 + (longlong)puVar12)))
                  goto LAB_0002a0bd;
                  in_stack_fffffffffffffda0 = (ulonglong *)CONCAT44(uVar27,uVar22);
                  RAID5DirtyWriteCmd((longlong)local_228,param_3,uVar18,local_1f8,lVar26,uVar22,
                                     uVar16,(longlong *)local_198);
                }
                else {
                  if (*(char *)(local_218 + 0x45 + (longlong)puVar12) == -1) goto LAB_0002a1e6;
                  in_stack_fffffffffffffda0 = (ulonglong *)CONCAT44(uVar27,uVar16);
                  RAID5BrokenCmd((longlong)local_228,param_3,(ulonglong)local_22c,lVar26,uVar22,
                                 uVar16,(longlong *)local_198);
                }
                *(longlong *)(param_3 + 0xe48 + (ulonglong)uVar16 * 8) = lVar26;
                local_230[(ulonglong)uVar16 - 8] = 1;
                *(longlong *)(param_3 + 0xe48 + (ulonglong)(uVar16 + 1) * 8) = lVar26;
                uVar16 = uVar16 + 2;
                goto LAB_0002a2ab;
              }
              if (local_208 == 1) {
                in_stack_fffffffffffffda0 = (ulonglong *)CONCAT44(uVar27,uVar16);
                RAID5BrokenCmd((longlong)local_228,param_3,(ulonglong)local_22c,lVar26,uVar22,uVar16
                               ,(longlong *)local_198);
                local_230[(ulonglong)uVar16 - 8] = 1;
                *(longlong *)(param_3 + 0xe48 + (ulonglong)uVar16 * 8) = lVar26;
              }
              else {
LAB_0002a1e6:
                *(uint *)(param_3 + 0xe44) = uVar22;
                *(uint *)(param_3 + 0xe40) = uVar22;
              }
              uVar16 = uVar16 + 1;
              local_238._4_4_ = uVar16;
            }
          }
          lVar4 = local_1d0;
          lVar23 = 8;
          puVar11 = local_1b8 + 0x59;
          do {
            if (*puVar11 != 0) {
              *puVar11 = (ulonglong)uVar22 + *puVar11;
            }
            puVar11 = puVar11 + 1;
            lVar23 = lVar23 + -1;
          } while (lVar23 != 0);
          uVar7 = local_1c8 / local_1f4;
          if ((local_1c8 % (ulonglong)local_1f4 != 0) ||
             (uVar7 = (ulonglong)*(uint *)((longlong)(local_1f0 + 5) + (longlong)puVar12),
             (*(uint *)((longlong)(local_1f0 + 5) + (longlong)puVar12) >> 0xc & 1) == 0)) {
            uVar24 = *(uint *)((longlong)(local_1f0 + 5) + (longlong)puVar12);
            goto LAB_0002a2eb;
          }
          local_1e0 = local_1e0 + 1;
          uVar7 = BuildRWRaid5Links((longlong)puVar19,param_3,(longlong)local_200,local_1e0);
          lVar23 = local_218;
          uVar18 = uVar7 & 0xff;
          bVar5 = *(byte *)(local_218 + 0x45 + (longlong)puVar12);
          uVar7 = CONCAT71((int7)(uVar7 >> 8),bVar5);
          local_208 = 0;
          local_230[uVar16] = bVar5;
          lVar26 = lVar4;
        }
        else {
LAB_0002a2eb:
          uVar18 = (ulonglong)(uVar24 >> 8 & 0xf);
          lVar23 = local_218;
        }
        if ((int)uVar18 == 0xf) goto LAB_00029be7;
        puVar19 = local_228;
      } while( true );
    }
    puVar19 = (ulonglong *)0x2;
    if (local_20c == 5) {
      if (uVar16 == 0) {
        uVar16 = 1;
      }
      if (((int)local_228[0x85b] == 0) || (*(char *)(lVar23 + 0x24 + (longlong)puVar12) == '\x01'))
      {
        if (uVar16 != 0) {
          puVar15 = local_198;
          puVar19 = (ulonglong *)(param_3 - (longlong)local_198);
          uVar7 = (ulonglong)uVar16;
          do {
            puVar11 = (ulonglong *)((longlong)(puVar19 + 0x178) + (longlong)puVar15);
            if (puVar11 != puVar15) {
              *puVar11 = *puVar15;
              puVar11[1] = puVar15[1];
              puVar11[2] = puVar15[2];
              puVar11[3] = puVar15[3];
              puVar11[4] = puVar15[4];
              puVar11[5] = puVar15[5];
              puVar11[6] = puVar15[6];
              puVar11[7] = puVar15[7];
            }
            puVar15 = puVar15 + 8;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
      }
      else {
        uVar21 = 0;
        if (uVar16 != 0) {
          puVar11 = local_88;
          pbVar14 = local_230;
          puVar12 = local_198;
          local_1f0 = puVar11;
          puVar15 = local_228;
          do {
            if ((((*(uint *)(*(longlong *)(param_3 + 0xf0) + 0xc) & 0x40) == 0) &&
                (cVar2 = *(char *)(*(longlong *)(param_3 + 0xf0) + 0x48), cVar2 != '/')) &&
               (cVar2 != -0x71)) {
              puVar19 = local_198;
              local_1f0 = puVar11;
              uVar6 = ExchangeDelayedCmd((longlong)puVar15,param_3,(longlong)puVar19,
                                         (longlong)&local_238,*puVar11,(uint)*pbVar14,uVar21,uVar6);
              puVar15 = local_228;
            }
            else {
              puVar10 = (ulonglong *)((param_3 - (longlong)local_198) + 0xbc0 + (longlong)puVar12);
              local_1f0 = puVar11;
              if (puVar10 != puVar12) {
                *puVar10 = *puVar12;
                puVar10[1] = puVar12[1];
                puVar10[2] = puVar12[2];
                puVar10[3] = puVar12[3];
                puVar10[4] = puVar12[4];
                puVar10[5] = puVar12[5];
                puVar10[6] = puVar12[6];
                puVar10[7] = puVar12[7];
              }
            }
            puVar12 = puVar12 + 8;
            puVar11 = local_1f0 + 1;
            uVar21 = uVar21 + 1;
            pbVar14 = pbVar14 + 1;
            local_1f0 = puVar11;
          } while (uVar21 < uVar16);
          puVar12 = local_1a8;
        }
      }
      RAID5AddSubCmd(puVar11,param_3,puVar19,(longlong)&local_238);
      pbVar14 = (byte *)((longlong)puVar12 + 0x1c);
      puVar12 = local_1b8 + 0x59;
      lVar23 = 8;
      do {
        if ((*(int *)(pbVar14 + 4) == 5) && (local_1b8 = (ulonglong *)0x0, *pbVar14 == local_1d8)) {
          local_1b8 = (ulonglong *)puVar12[-8];
          *puVar12 = (ulonglong)local_1b8;
        }
        puVar12 = puVar12 + 1;
        pbVar14 = pbVar14 + 0xb8;
        lVar23 = lVar23 + -1;
        puVar11 = local_1b8;
      } while (lVar23 != 0);
    }
    else {
      puVar12 = (ulonglong *)(param_3 + 0xbc0);
      puVar11 = local_198;
      if (puVar12 != local_198) {
        puVar11 = local_198;
        if ((((uint)local_198 | (uint)puVar12) & 0xf) == 0) {
          do {
            uVar7 = puVar11[1];
            uVar17 = puVar11[2];
            uVar18 = puVar11[3];
            *puVar12 = *puVar11;
            puVar12[1] = uVar7;
            uVar7 = puVar11[4];
            uVar3 = puVar11[5];
            puVar12[2] = uVar17;
            puVar12[3] = uVar18;
            uVar17 = puVar11[6];
            uVar18 = puVar11[7];
            puVar12[4] = uVar7;
            puVar12[5] = uVar3;
            uVar7 = puVar11[8];
            uVar3 = puVar11[9];
            puVar12[6] = uVar17;
            puVar12[7] = uVar18;
            uVar17 = puVar11[10];
            uVar18 = puVar11[0xb];
            puVar12[8] = uVar7;
            puVar12[9] = uVar3;
            uVar7 = puVar11[0xc];
            uVar3 = puVar11[0xd];
            puVar12[10] = uVar17;
            puVar12[0xb] = uVar18;
            uVar17 = puVar11[0xe];
            uVar18 = puVar11[0xf];
            puVar12[0xc] = uVar7;
            puVar12[0xd] = uVar3;
            puVar12[0xe] = uVar17;
            puVar12[0xf] = uVar18;
            puVar19 = (ulonglong *)((longlong)puVar19 + -1);
            puVar12 = puVar12 + 0x10;
            puVar11 = puVar11 + 0x10;
          } while (puVar19 != (ulonglong *)0x0);
          puVar11 = (ulonglong *)0x0;
        }
        else {
          puVar11 = memcpy(puVar12,local_198,0x100);
        }
      }
    }
    uVar7 = CONCAT71((int7)((ulonglong)puVar11 >> 8),1);
  }
  return uVar7;
}



===== ExchangeDelayedCmd @ 0002a744 =====

int ExchangeDelayedCmd(longlong param_1,longlong param_2,longlong param_3,longlong param_4,
                      longlong param_5,uint param_6,int param_7,uint param_8)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  
  uVar4 = *(uint *)(param_1 + 0x42c8);
  lVar7 = *(longlong *)(param_1 + 0x42c0);
  uVar8 = (ulonglong)param_8;
  if (*(longlong *)(param_1 + 0x42d0) == param_5) {
    lVar1 = (ulonglong)(uint)(param_7 << 3) + (ulonglong)param_6;
    uVar5 = *(undefined8 *)(param_3 + lVar1 * 8);
    *(uint *)(param_1 + 0x42c8) = param_6;
    *(longlong *)(param_1 + 0x42d0) = param_5;
    *(undefined8 *)(param_1 + 0x42c0) = uVar5;
    *(longlong *)(param_3 + lVar1 * 8) = lVar7;
    puVar2 = (undefined8 *)(param_3 + (ulonglong)(uint)(param_7 << 3) * 8);
    puVar6 = (undefined8 *)((uVar8 + 0x2f) * 0x40 + param_2);
    if (puVar6 != puVar2) {
      *puVar6 = *puVar2;
      puVar6[1] = puVar2[1];
      puVar6[2] = puVar2[2];
      puVar6[3] = puVar2[3];
      puVar6[4] = puVar2[4];
      puVar6[5] = puVar2[5];
      puVar6[6] = puVar2[6];
      puVar6[7] = puVar2[7];
    }
LAB_0002a9ce:
    return param_8 + 1;
  }
  if (lVar7 == 0) {
    lVar7 = (ulonglong)(uint)(param_7 << 3) + (ulonglong)param_6;
    uVar5 = *(undefined8 *)(param_3 + lVar7 * 8);
    *(longlong *)(param_1 + 0x42d0) = param_5;
    *(uint *)(param_1 + 0x42c8) = param_6;
    *(undefined8 *)(param_1 + 0x42c0) = uVar5;
    *(undefined8 *)(param_3 + lVar7 * 8) = 0;
    puVar2 = (undefined8 *)(param_3 + (ulonglong)(uint)(param_7 << 3) * 8);
    puVar6 = (undefined8 *)((uVar8 + 0x2f) * 0x40 + param_2);
    if (puVar6 != puVar2) {
      *puVar6 = *puVar2;
      puVar6[1] = puVar2[1];
      puVar6[2] = puVar2[2];
      puVar6[3] = puVar2[3];
      puVar6[4] = puVar2[4];
      puVar6[5] = puVar2[5];
      puVar6[6] = puVar2[6];
      puVar6[7] = puVar2[7];
    }
    goto LAB_0002a9ce;
  }
  memset((void *)((uVar8 + 0x2f) * 0x40 + param_2),0,0x40);
  *(longlong *)(param_2 + ((ulonglong)uVar4 + (uVar8 + 0x2f) * 8) * 8) = lVar7;
  if (param_7 == 0) {
    *(undefined1 *)((ulonglong)(param_8 + 2) + param_4) =
         *(undefined1 *)((ulonglong)(param_8 + 1) + param_4);
    *(undefined1 *)((ulonglong)(param_8 + 1) + param_4) = *(undefined1 *)(uVar8 + param_4);
    *(undefined1 *)(uVar8 * 0xd8 + 0x46b + param_2) =
         *(undefined1 *)(uVar8 * 0xd8 + 0x393 + param_2);
  }
  else {
    if (param_7 != 1) goto LAB_0002a8c1;
    *(undefined1 *)((ulonglong)(param_8 + 1) + param_4) = *(undefined1 *)(uVar8 + param_4);
  }
  lVar7 = uVar8 * 0xd8;
  uVar3 = *(undefined1 *)(lVar7 + 699 + param_2);
  *(undefined1 *)(uVar8 + param_4) = 0;
  *(undefined1 *)(lVar7 + 699 + param_2) = 0;
  *(undefined1 *)(lVar7 + 0x393 + param_2) = uVar3;
LAB_0002a8c1:
  lVar7 = (ulonglong)(uint)(param_7 << 3) + (ulonglong)param_6;
  uVar5 = *(undefined8 *)(param_3 + lVar7 * 8);
  *(uint *)(param_1 + 0x42c8) = param_6;
  *(undefined8 *)(param_1 + 0x42c0) = uVar5;
  *(longlong *)(param_1 + 0x42d0) = param_5;
  *(undefined8 *)(param_3 + lVar7 * 8) = 0;
  puVar2 = (undefined8 *)(param_3 + (ulonglong)(uint)(param_7 << 3) * 8);
  puVar6 = (undefined8 *)(((ulonglong)(param_8 + 1) + 0x2f) * 0x40 + param_2);
  if (puVar6 != puVar2) {
    *puVar6 = *puVar2;
    puVar6[1] = puVar2[1];
    puVar6[2] = puVar2[2];
    puVar6[3] = puVar2[3];
    puVar6[4] = puVar2[4];
    puVar6[5] = puVar2[5];
    puVar6[6] = puVar2[6];
    puVar6[7] = puVar2[7];
  }
  return param_8 + 2;
}



===== RAID5DirtyWriteCmd @ 0002a9f0 =====

undefined8
RAID5DirtyWriteCmd(longlong param_1,longlong param_2,ulonglong param_3,uint param_4,
                  undefined8 param_5,int param_6,uint param_7,longlong *param_8)

{
  uint *puVar1;
  void *pvVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  int iVar12;
  longlong *plVar13;
  undefined1 *local_res8;
  
  uVar11 = (ulonglong)param_7;
  uVar7 = param_3 & 0xffffffff;
  uVar10 = 0;
  iVar12 = 1;
  plVar13 = param_8 + (param_7 << 3);
  lVar4 = uVar7 * 0xb8;
  lVar8 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
  uVar9 = *(uint *)(lVar4 + 0x3b0 + param_1) & 0xf;
  uVar3 = param_3;
  if (uVar9 != 0xffffffff) {
    do {
      if ((uint)uVar3 == param_4) {
        lVar4 = (uVar3 & 0xffffffff) * 0xb8;
        uVar6 = *(uint *)(lVar4 + 0x3b0 + param_1);
      }
      else {
        if ((plVar13[uVar3 & 0xffffffff] == 0) &&
           (pvVar2 = RAID5AllocateSubCmd(lVar4,param_2,uVar3,param_7,param_8), pvVar2 == (void *)0x0
           )) {
          return 4;
        }
        uVar6 = *(uint *)((uVar3 & 0xffffffff) * 0xb8 + 0x3b0 + param_1);
      }
      uVar10 = uVar10 + 1;
      uVar3 = (ulonglong)(uVar6 >> 0xe & 0xf);
    } while (uVar10 < uVar9 + 1);
  }
  uVar3 = *(ulonglong *)(param_2 + 0xf0);
  uVar5 = (ulonglong)*(uint *)(uVar3 + 0xc);
  if ((char)*(uint *)(uVar3 + 0xc) < '\0') {
    uVar10 = 0;
    iVar12 = 2;
    if (uVar9 != 0xffffffff) {
      do {
        uVar6 = (uint)uVar7;
        if ((uVar6 == param_4) || (uVar6 == (uint)param_3)) {
LAB_0002ab04:
          pvVar2 = RAID5AllocateSubCmd(uVar5,param_2,uVar7,param_7 + 1,param_8);
          if (pvVar2 == (void *)0x0) {
            return 4;
          }
          uVar3 = uVar7;
        }
        else {
          uVar5 = uVar7 * 0xb8;
          uVar3 = 0;
          if (uVar6 == *(byte *)(uVar5 + 0x3cd + param_1)) goto LAB_0002ab04;
        }
        uVar5 = uVar7 * 0xb8;
        uVar10 = uVar10 + 1;
        uVar7 = (ulonglong)(*(uint *)(uVar5 + 0x3b0 + param_1) >> 0xe & 0xf);
      } while (uVar10 < uVar9 + 1);
    }
  }
  if (param_7 < iVar12 + param_7) {
    local_res8 = (undefined1 *)(uVar11 * 0xd8 + 699 + param_2);
    lVar8 = ((0x51 - (ulonglong)(param_7 << 3)) * 8 - (longlong)param_8) + lVar8;
    uVar3 = (ulonglong)-param_7;
    do {
      uVar9 = 0;
      do {
        lVar4 = *plVar13;
        if (lVar4 != 0) {
          *(char *)(lVar4 + 0x4e) = (char)uVar9;
          *(undefined8 *)(lVar4 + 0x40) = param_5;
          *(int *)(lVar4 + 0x58) = param_6;
          memset(*(void **)(lVar4 + 0x30),0,(ulonglong)(uint)(*(int *)(param_1 + 0x380) << 2));
          puVar1 = *(uint **)(lVar4 + 0x30);
          *puVar1 = *puVar1 ^ ((uint)(*(int *)((longlong)plVar13 + lVar8 + 0x40) -
                                     *(int *)((longlong)plVar13 + lVar8)) >> 9 ^ *puVar1) & 0x3ff;
          puVar1 = *(uint **)(lVar4 + 0x30);
          *puVar1 = *puVar1 ^ (param_6 << 10 ^ *puVar1) & 0x1ffffc00;
          **(uint **)(lVar4 + 0x30) = **(uint **)(lVar4 + 0x30) | 0x80000000;
          **(uint **)(lVar4 + 0x30) = **(uint **)(lVar4 + 0x30) | 0x40000000;
          *(undefined4 *)(lVar4 + 0x54) = 0;
          *(undefined4 *)(lVar4 + 0xa8) = 1;
          uVar3 = *(ulonglong *)(param_2 + 0xf0);
          if ((char)*(undefined4 *)(uVar3 + 0xc) < '\0') {
            uVar10 = (int)uVar11 + -param_7;
            uVar3 = (ulonglong)(uVar10 >> 8) << 8;
            *(uint *)(lVar4 + 0x54) = (-(uint)((uVar10 & 1) != 0) & 0x40) + 0x40;
          }
          else {
            *(undefined4 *)(lVar4 + 0x54) = 0x40;
          }
        }
        uVar9 = uVar9 + 1;
        plVar13 = plVar13 + 1;
      } while (uVar9 < 8);
      uVar9 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar9;
      lVar8 = lVar8 + -0x40;
      *local_res8 = 4;
      local_res8 = local_res8 + 0xd8;
    } while (uVar9 < iVar12 + param_7);
  }
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== RAID5NormalWriteCmd @ 0002acc4 =====

undefined8
RAID5NormalWriteCmd(longlong param_1,longlong param_2,undefined8 *param_3,uint param_4,
                   longlong param_5,longlong param_6,undefined8 param_7,int param_8,uint *param_9,
                   longlong *param_10)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  undefined8 uVar6;
  longlong lVar7;
  char *pcVar8;
  uint uVar9;
  ulonglong uVar10;
  byte *pbVar11;
  longlong lVar12;
  undefined8 in_stack_ffffffffffffffa0;
  
  uVar3 = *param_9;
  *(undefined8 *)(param_2 + 0xe48 + (ulonglong)uVar3 * 8) = param_7;
  uVar9 = 0;
  pcVar8 = (char *)(param_1 + 0x3a4);
  pbVar11 = (byte *)(param_1 + 0xab8);
  lVar7 = (ulonglong)
          *(byte *)(param_1 + 0x958 + (ulonglong)*(byte *)(*(longlong *)(param_2 + 0xf0) + 6) * 0x28
                   ) * 0xb8;
  lVar12 = 0;
  cVar1 = *(char *)(lVar7 + 0x3a4 + param_1);
  iVar4 = *(int *)(lVar7 + 0x3a8 + param_1);
  do {
    if (((((*pbVar11 & 1) != 0) && (*(int *)(pcVar8 + 4) == iVar4)) && (*pcVar8 == cVar1)) &&
       ((uVar9 != (byte)pcVar8[0x29] &&
        (lVar7 = (ulonglong)(uVar3 << 3) + lVar12, param_10[lVar7] == 0)))) {
      pvVar5 = RAID5AllocateSubCmd(lVar7,param_2,(ulonglong)uVar9,uVar3,param_10);
      if (pvVar5 == (void *)0x0) break;
      RAID5CreateReadSubCmd
                (param_1,param_7,param_8,uVar3,uVar9,in_stack_ffffffffffffffa0,(longlong)param_10);
    }
    uVar9 = uVar9 + 1;
    lVar12 = lVar12 + 1;
    pbVar11 = pbVar11 + 2;
    pcVar8 = pcVar8 + 0xb8;
  } while (uVar9 < 8);
  uVar3 = *param_9;
  *(undefined1 *)((ulonglong)uVar3 + param_6) = 1;
  *(undefined1 *)((ulonglong)uVar3 * 0xd8 + 699 + param_2) = 2;
  if (*(int *)(param_1 + 0x42d8) == 0) {
    *param_9 = uVar3 + 1;
  }
  lVar12 = (ulonglong)param_4 * 0xb8;
  uVar10 = (ulonglong)*(byte *)(lVar12 + 0x3cd + param_1);
  lVar7 = (*param_9 << 3) + uVar10;
  pvVar5 = (void *)param_10[lVar7];
  if ((pvVar5 == (void *)0x0) &&
     (pvVar5 = RAID5AllocateSubCmd(lVar7,param_2,uVar10,*param_9,param_10), pvVar5 == (void *)0x0))
  {
    uVar6 = 4;
  }
  else {
    bVar2 = *(byte *)(lVar12 + 0x3cd + param_1);
    uVar6 = RAID5CreateParityCMD
                      ((ulonglong)bVar2,param_2,param_3,(longlong)pvVar5,(uint)bVar2,param_7,param_8
                      );
    uVar3 = *param_9;
    uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
    *(undefined1 *)((ulonglong)uVar3 + param_5) = *(undefined1 *)(lVar12 + 0x3cd + param_1);
    *param_9 = uVar3 + 1;
  }
  return uVar6;
}



===== RfBuildRaidDiskBasicParameter @ 0002aecc =====

void RfBuildRaidDiskBasicParameter(longlong param_1,int param_2)

{
  uint *puVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  longlong lVar10;
  longlong lVar11;
  byte bVar12;
  
  bVar12 = 0;
  lVar10 = (longlong)param_2 * 0xb8;
  lVar11 = (longlong)param_2 * 0x200;
  *(undefined4 *)(lVar10 + 0x3c8 + param_1) = *(undefined4 *)(lVar11 + 0x14ca + param_1);
  *(undefined4 *)(lVar10 + 0x434 + param_1) = *(undefined4 *)(lVar11 + 0x14ce + param_1);
  *(undefined4 *)(lVar10 + 0x3f4 + param_1) = *(undefined4 *)(lVar11 + 0x14d2 + param_1);
  *(undefined4 *)(lVar10 + 0x400 + param_1) = *(undefined4 *)(lVar11 + 0x14d6 + param_1);
  *(undefined4 *)(lVar10 + 0x404 + param_1) = *(undefined4 *)(lVar11 + 0x14da + param_1);
  *(undefined4 *)(lVar10 + 0x408 + param_1) = *(undefined4 *)(lVar11 + 0x14de + param_1);
  *(undefined4 *)(lVar10 + 0x40c + param_1) = *(undefined4 *)(lVar11 + 0x14e2 + param_1);
  *(undefined4 *)(lVar10 + 0x410 + param_1) = *(undefined4 *)(lVar11 + 0x14e6 + param_1);
  *(undefined4 *)(lVar10 + 0x414 + param_1) = *(undefined4 *)(lVar11 + 0x14ea + param_1);
  *(undefined4 *)(lVar10 + 0x418 + param_1) = *(undefined4 *)(lVar11 + 0x14ee + param_1);
  *(undefined4 *)(lVar10 + 0x41c + param_1) = *(undefined4 *)(lVar11 + 0x14f2 + param_1);
  *(uint *)(lVar10 + 0x3e0 + param_1) = (uint)*(byte *)(lVar11 + 0x1503 + param_1);
  *(undefined8 *)(lVar10 + 0x3d0 + param_1) = *(undefined8 *)(lVar11 + 0x1504 + param_1);
  *(undefined8 *)(lVar10 + 0x3d8 + param_1) = *(undefined8 *)(lVar11 + 0x1504 + param_1);
  *(uint *)(lVar10 + 0x3a8 + param_1) = *(ushort *)(lVar11 + 0x14c7 + param_1) >> 3 & 0xf;
  *(byte *)(lVar10 + 0x3a4 + param_1) = (byte)(*(ushort *)(lVar11 + 0x14c7 + param_1) >> 7) & 7;
  *(byte *)(lVar10 + 0x3ac + param_1) = *(byte *)(lVar11 + 0x14c9 + param_1) >> 3 & 1;
  uVar3 = *(ushort *)(lVar11 + 0x14c7 + param_1) >> 3;
  uVar5 = uVar3 & 0xf;
  if ((uVar3 & 0xf) == 0) {
    cVar9 = '\x01';
    *(undefined1 *)(lVar10 + 0x3b4 + param_1) = 1;
    bVar2 = *(byte *)(lVar11 + 0x14c9 + param_1);
    uVar7 = ((uint)*(byte *)(lVar11 + 0x14c9 + param_1) << 0x12 ^
            *(uint *)(lVar10 + 0x3b0 + param_1)) & 0x3fffff ^ (uint)bVar2 << 0x12;
    *(uint *)(lVar10 + 0x3b0 + param_1) = uVar7;
    if ((uVar7 & 0xffc00000) != 0) {
      do {
        bVar12 = bVar12 + 1;
        cVar9 = cVar9 * '\x02';
      } while (bVar12 < bVar2 >> 4);
    }
    uVar4 = (uint)(byte)(cVar9 << 3) << 0x16;
    *(uint *)(lVar10 + 0x3b0 + param_1) = uVar4 | uVar7 & 0x3fffff;
    uVar8 = *(byte *)(lVar11 + 0x14c9 + param_1) & 7;
    *(uint *)(lVar10 + 0x3b0 + param_1) = uVar8 | uVar4 | uVar7 & 0x3ffff0;
    uVar6 = *(ushort *)(lVar11 + 0x14c7 + param_1) >> 6 & 0x70;
    uVar8 = uVar8 | uVar4 | uVar7 & 0x3fff00;
LAB_0002b35e:
    *(uint *)(lVar10 + 0x3b0 + param_1) = uVar6 | uVar8;
  }
  else {
    if (uVar5 == 1) {
      *(undefined1 *)(lVar10 + 0x3b4 + param_1) = 1;
      uVar7 = *(ushort *)(lVar11 + 0x14c7 + param_1) >> 6 & 0x30 |
              *(uint *)(lVar10 + 0x3b0 + param_1) & 0xffffff0f;
      *(uint *)(lVar10 + 0x3b0 + param_1) = uVar7;
      *(byte *)(lVar10 + 0x3ad + param_1) =
           (byte)((ushort)*(undefined2 *)(lVar11 + 0x14c7 + param_1) >> 0xc) & 1;
      puVar1 = (uint *)(lVar10 + 0x3b0 + param_1);
      *puVar1 = *puVar1 ^ ((*(byte *)(lVar11 + 0x14c9 + param_1) & 7) + 2 ^ uVar7) & 0xf;
      return;
    }
    if (uVar5 == 5) {
      cVar9 = '\x01';
      *(undefined1 *)(lVar10 + 0x3b4 + param_1) = 1;
      bVar2 = *(byte *)(lVar11 + 0x14c9 + param_1);
      g_Raid5Exist = 1;
      uVar7 = ((uint)*(byte *)(lVar11 + 0x14c9 + param_1) << 0x12 ^
              *(uint *)(lVar10 + 0x3b0 + param_1)) & 0x3fffff ^ (uint)bVar2 << 0x12;
      *(uint *)(lVar10 + 0x3b0 + param_1) = uVar7;
      if ((uVar7 & 0xffc00000) != 0) {
        do {
          bVar12 = bVar12 + 1;
          cVar9 = cVar9 * '\x02';
        } while (bVar12 < bVar2 >> 4);
      }
      uVar7 = (uint)(byte)(cVar9 << 3) << 0x16 | uVar7 & 0x3fffff;
      *(uint *)(lVar10 + 0x3b0 + param_1) = uVar7;
      uVar7 = ((uint)*(byte *)(lVar11 + 0x150c + param_1) << 0x12 ^ uVar7) & 0x3c0000 ^ uVar7;
      *(uint *)(lVar10 + 0x3b0 + param_1) = uVar7;
      uVar7 = ((*(byte *)(lVar11 + 0x14c9 + param_1) & 7) - 1 ^ uVar7) & 0xf ^ uVar7;
      *(uint *)(lVar10 + 0x3b0 + param_1) = uVar7;
      uVar7 = *(ushort *)(lVar11 + 0x14c7 + param_1) >> 6 & 0x70 | uVar7 & 0xffffff0f;
      *(uint *)(lVar10 + 0x3b0 + param_1) = uVar7;
      if ((*(byte *)(lVar11 + 0x1502 + param_1) & 0xf) != 0) {
        *(uint *)(lVar10 + 0x3b0 + param_1) = uVar7 | 0x2000;
      }
      bVar12 = (byte)((ushort)*(undefined2 *)(lVar11 + 0x14c7 + param_1) >> 0xd);
    }
    else {
      if (uVar5 == 8) {
        uVar7 = *(uint *)(lVar10 + 0x3b0 + param_1);
        *(undefined1 *)(lVar10 + 0x3b4 + param_1) = 1;
        uVar8 = *(ushort *)(lVar11 + 0x14c7 + param_1) >> 6 & 0x70;
        *(uint *)(lVar10 + 0x3b0 + param_1) = uVar8 | uVar7 & 0xffffff0f;
        uVar6 = *(byte *)(lVar11 + 0x14c9 + param_1) & 7;
        uVar8 = uVar8 | uVar7 & 0xffffff00;
        goto LAB_0002b35e;
      }
      if (uVar5 != 9) {
        return;
      }
      cVar9 = '\x01';
      *(undefined1 *)(lVar10 + 0x3b4 + param_1) = 1;
      bVar2 = *(byte *)(lVar11 + 0x14c9 + param_1);
      uVar7 = ((uint)*(byte *)(lVar11 + 0x14c9 + param_1) << 0x12 ^
              *(uint *)(lVar10 + 0x3b0 + param_1)) & 0x3fffff ^ (uint)bVar2 << 0x12;
      *(uint *)(lVar10 + 0x3b0 + param_1) = uVar7;
      if ((uVar7 & 0xffc00000) != 0) {
        do {
          bVar12 = bVar12 + 1;
          cVar9 = cVar9 * '\x02';
        } while (bVar12 < bVar2 >> 4);
      }
      uVar4 = (uint)(byte)(cVar9 << 3) << 0x16;
      *(uint *)(lVar10 + 0x3b0 + param_1) = uVar4 | uVar7 & 0x3fffff;
      uVar8 = *(ushort *)(lVar11 + 0x14c7 + param_1) >> 6 & 0x70;
      *(uint *)(lVar10 + 0x3b0 + param_1) = uVar8 | uVar4 | uVar7 & 0x3fff0f;
      uVar6 = *(byte *)(lVar11 + 0x14c9 + param_1) & 7;
      *(uint *)(lVar10 + 0x3b0 + param_1) = uVar6 | uVar8 | uVar4 | uVar7 & 0x3fff00;
      *(uint *)(lVar10 + 0x3b0 + param_1) =
           (*(ushort *)(lVar11 + 0x14c7 + param_1) & 0x2000) << 7 |
           uVar6 | uVar8 | uVar4 | uVar7 & 0xfff00;
      bVar12 = (byte)((ushort)*(undefined2 *)(lVar11 + 0x14c7 + param_1) >> 0xe);
    }
    *(byte *)(lVar10 + 0x3ad + param_1) = bVar12 & 1;
  }
  return;
}



===== ReadWriteConfigFromHDD @ 0002b370 =====

int ReadWriteConfigFromHDD
              (longlong param_1,uint param_2,undefined8 *param_3,undefined8 param_4,char param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined7 extraout_var;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  byte bVar10;
  longlong lVar11;
  ulonglong uVar12;
  longlong lVar13;
  byte local_res10;
  
  uVar8 = (ulonglong)param_2;
  lVar13 = 4;
  lVar11 = (ulonglong)param_2 * 0xd4;
  if (*(int *)(param_1 + 0x13b4) != *(int *)(param_1 + 0x20c)) {
    uVar2 = *(uint *)(param_1 + 0x21c);
    StorPortGetBusData(param_1,4,uVar2 >> 0x10 & 0xff,(uVar2 >> 3 & 0xe0) + (uVar2 >> 0xb & 0x1f),
                       (int *)(param_1 + 0x13b4),0x100);
  }
  if (*(char *)(param_1 + 0x13be) != '\x04') {
    if (param_5 == '\0') {
      memset(param_3,0,0x200);
    }
    return 1;
  }
  if (param_5 == '\x01') {
    puVar6 = (undefined8 *)(param_1 + 0x24c4 + uVar8 * 0x200);
    *(ushort *)((longlong)puVar6 + 3) =
         *(ushort *)((longlong)puVar6 + 3) ^
         (*(ushort *)((longlong)param_3 + 3) ^ *(ushort *)((longlong)puVar6 + 3)) & 0x380;
    *(undefined1 *)((longlong)puVar6 + 0x32) = *(undefined1 *)((longlong)param_3 + 0x32);
    if (puVar6 == param_3) {
      return 1;
    }
    iVar5 = memcmp(puVar6,param_3,0x200);
    if (iVar5 == 0) {
      return 1;
    }
  }
  if ((*(uint *)(uVar8 * 0xb8 + 0x39c + param_1) & 0x10) == 0) {
    uVar12 = (ulonglong)
             ((uint)*(ushort *)(lVar11 + 0xd20 + param_1) *
              (uint)*(ushort *)(lVar11 + 0xd1a + param_1) *
              (uint)*(ushort *)(lVar11 + 0xd16 + param_1) - 2);
  }
  else {
    uVar12 = CONCAT44(*(undefined4 *)(lVar11 + 0xddc + param_1),
                      *(undefined4 *)(lVar11 + 0xd8c + param_1)) - 1;
  }
  bVar10 = 0;
  while( true ) {
    uVar9 = uVar12;
    uVar4 = ReadWriteHDDSector(param_1,param_2,uVar12,(undefined2 *)param_3,param_5);
    iVar5 = (int)CONCAT71(extraout_var,uVar4);
    if (iVar5 == 1) break;
    local_res10 = (byte)param_2;
    RestoreOneAbnormalDevice(param_1,local_res10,uVar9);
    bVar10 = bVar10 + 1;
    if (2 < bVar10) {
      return iVar5;
    }
  }
  puVar6 = (undefined8 *)(param_1 + 0x24c4 + uVar8 * 0x200);
  uVar2 = (uint)param_3;
  if (param_5 == '\0') {
    if (puVar6 == param_3) {
      return 1;
    }
    if (((uVar2 | (uint)puVar6) & 0xf) == 0) {
      do {
        uVar3 = param_3[1];
        *puVar6 = *param_3;
        puVar6[1] = uVar3;
        uVar3 = param_3[3];
        puVar6[2] = param_3[2];
        puVar6[3] = uVar3;
        uVar3 = param_3[5];
        puVar6[4] = param_3[4];
        puVar6[5] = uVar3;
        uVar3 = param_3[7];
        puVar6[6] = param_3[6];
        puVar6[7] = uVar3;
        uVar3 = param_3[9];
        puVar6[8] = param_3[8];
        puVar6[9] = uVar3;
        uVar3 = param_3[0xb];
        puVar6[10] = param_3[10];
        puVar6[0xb] = uVar3;
        uVar3 = param_3[0xd];
        puVar6[0xc] = param_3[0xc];
        puVar6[0xd] = uVar3;
        puVar7 = param_3 + 0xe;
        uVar3 = param_3[0xf];
        param_3 = param_3 + 0x10;
        puVar6[0xe] = *puVar7;
        puVar6[0xf] = uVar3;
        lVar13 = lVar13 + -1;
        puVar6 = puVar6 + 0x10;
      } while (lVar13 != 0);
      return 1;
    }
  }
  else {
    if (puVar6 != param_3) {
      if (((uVar2 | (uint)puVar6) & 0xf) == 0) {
        lVar11 = 4;
        puVar7 = param_3;
        do {
          uVar3 = puVar7[1];
          *puVar6 = *puVar7;
          puVar6[1] = uVar3;
          uVar3 = puVar7[3];
          puVar6[2] = puVar7[2];
          puVar6[3] = uVar3;
          uVar3 = puVar7[5];
          puVar6[4] = puVar7[4];
          puVar6[5] = uVar3;
          uVar3 = puVar7[7];
          puVar6[6] = puVar7[6];
          puVar6[7] = uVar3;
          uVar3 = puVar7[9];
          puVar6[8] = puVar7[8];
          puVar6[9] = uVar3;
          uVar3 = puVar7[0xb];
          puVar6[10] = puVar7[10];
          puVar6[0xb] = uVar3;
          uVar3 = puVar7[0xd];
          puVar6[0xc] = puVar7[0xc];
          puVar6[0xd] = uVar3;
          puVar1 = puVar7 + 0xe;
          uVar3 = puVar7[0xf];
          puVar7 = puVar7 + 0x10;
          puVar6[0xe] = *puVar1;
          puVar6[0xf] = uVar3;
          lVar11 = lVar11 + -1;
          puVar6 = puVar6 + 0x10;
        } while (lVar11 != 0);
      }
      else {
        memcpy(puVar6,param_3,0x200);
      }
    }
    puVar6 = (undefined8 *)(param_1 + 0x14c4 + uVar8 * 0x200);
    if (puVar6 == param_3) {
      return 1;
    }
    if (((uVar2 | (uint)puVar6) & 0xf) == 0) {
      do {
        uVar3 = param_3[1];
        *puVar6 = *param_3;
        puVar6[1] = uVar3;
        uVar3 = param_3[3];
        puVar6[2] = param_3[2];
        puVar6[3] = uVar3;
        uVar3 = param_3[5];
        puVar6[4] = param_3[4];
        puVar6[5] = uVar3;
        uVar3 = param_3[7];
        puVar6[6] = param_3[6];
        puVar6[7] = uVar3;
        uVar3 = param_3[9];
        puVar6[8] = param_3[8];
        puVar6[9] = uVar3;
        uVar3 = param_3[0xb];
        puVar6[10] = param_3[10];
        puVar6[0xb] = uVar3;
        uVar3 = param_3[0xd];
        puVar6[0xc] = param_3[0xc];
        puVar6[0xd] = uVar3;
        puVar7 = param_3 + 0xe;
        uVar3 = param_3[0xf];
        param_3 = param_3 + 0x10;
        puVar6[0xe] = *puVar7;
        puVar6[0xf] = uVar3;
        lVar13 = lVar13 + -1;
        puVar6 = puVar6 + 0x10;
      } while (lVar13 != 0);
      return 1;
    }
  }
  memcpy(puVar6,param_3,0x200);
  return 1;
}



===== RfVerifyIsDiskInRaid @ 0002b688 =====

undefined8 RfVerifyIsDiskInRaid(short *param_1)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  ushort uVar4;
  byte bVar5;
  byte bVar6;
  
  uVar1 = *(ushort *)((longlong)param_1 + 3);
  uVar3 = 0;
  bVar5 = 0;
  uVar4 = uVar1 >> 3 & 0xf;
  bVar6 = -((uVar1 & 4) != 0) & (uVar4 < 10 && *param_1 == -0x55ab);
  if ((uVar4 == 0) || (uVar4 == 5)) {
    uVar3 = *(byte *)((longlong)param_1 + 5) & 7;
    bVar5 = *(byte *)((longlong)param_1 + 5) >> 4;
LAB_0002b748:
    if (1 < uVar3) goto LAB_0002b750;
  }
  else {
    if (uVar4 == 1) {
      uVar3 = (*(byte *)((longlong)param_1 + 5) & 7) + 2;
      if ((uVar1 & 0x7c00) == 0xc00) {
        bVar6 = 0;
      }
      goto LAB_0002b748;
    }
    if (uVar4 == 9) {
      uVar3 = (*(byte *)((longlong)param_1 + 5) & 7) * 2;
      goto LAB_0002b748;
    }
    if (uVar4 == 8) {
      uVar3 = *(byte *)((longlong)param_1 + 5) & 7;
      goto LAB_0002b748;
    }
  }
  bVar6 = 0;
LAB_0002b750:
  if (4 < bVar5) {
    bVar6 = 0;
  }
  if (*(int *)(param_1 + 5) == 0) {
    bVar6 = bVar6 & -(*(int *)(param_1 + 3) != 0);
  }
  lVar2 = 0;
  if (uVar3 != 0) {
    do {
      if (*(int *)(param_1 + lVar2 * 2 + 9) == 0) {
        bVar6 = 0;
        break;
      }
      lVar2 = lVar2 + 1;
    } while (lVar2 < (int)uVar3);
  }
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),bVar6);
}



===== RfCheckDiskRaidParameter @ 0002b7a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RfCheckDiskRaidParameter(longlong param_1)

{
  short *psVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  undefined8 uVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  byte bVar9;
  char *pcVar10;
  int *piVar11;
  char *pcVar12;
  ushort *puVar13;
  undefined8 *puVar14;
  uint uVar15;
  uint uVar16;
  longlong lVar17;
  ushort uVar18;
  ushort uVar19;
  int iVar20;
  ushort *puVar21;
  undefined1 auStack_d8 [32];
  uint local_a8;
  uint local_a4;
  int local_9c;
  ushort *local_98;
  ushort *local_90;
  longlong local_88;
  ushort *local_80;
  undefined7 *local_78;
  char local_58;
  undefined7 uStack_57;
  undefined1 local_50;
  char local_48 [16];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar18 = 0;
  puVar14 = (undefined8 *)(param_1 + 0x14c4);
  local_98 = (ushort *)(param_1 + 0xab8);
  local_48[8] = '\0';
  local_48[9] = '\0';
  local_48[10] = '\0';
  local_48[0xb] = '\0';
  local_48[0xc] = '\0';
  local_48[0xd] = '\0';
  local_48[0xe] = '\0';
  local_48[0xf] = '\0';
  local_48[0] = '\0';
  local_48[1] = '\0';
  local_48[2] = '\0';
  local_48[3] = '\0';
  local_48[4] = '\0';
  local_48[5] = '\0';
  local_48[6] = '\0';
  local_48[7] = '\0';
  uVar19 = 0;
  local_9c = 0;
  local_88 = 0;
  local_90 = (ushort *)(param_1 + 0x14c7);
  local_80 = local_98;
  do {
    if (((*local_80 & 1) != 0) && ((*local_80 & 2) == 0)) {
      psVar1 = (short *)((longlong)local_90 + -3);
      if (*psVar1 == -0x55ab) {
        uVar5 = RfVerifyIsDiskInRaid(psVar1);
        if ((char)uVar5 == '\0') {
          local_48[local_88 + 8] = '\x01';
          local_48[local_88] = '\x01';
        }
        else if (local_48[local_88] != '\x01') {
          uVar3 = *local_90;
          uVar16 = 1;
          local_a4 = 0;
          local_a8 = 1;
          uVar2 = uVar3 >> 3 & 0xf;
          if ((uVar2 == 0) || (uVar2 == 5)) {
            local_a4 = (byte)local_90[1] & 7;
          }
          else if (uVar2 == 1) {
            local_a4 = ((byte)local_90[1] & 7) + 2;
          }
          else if (uVar2 == 9) {
            local_a4 = ((byte)local_90[1] & 7) * 2;
          }
          else if (uVar2 == 8) {
            local_a4 = (byte)local_90[1] & 7;
          }
          _local_58 = CONCAT71(0xffffffffffffff,(char)local_9c);
          uVar18 = (uVar18 & 7) << 7;
          local_78 = &uStack_57;
          local_48[local_88] = '\x01';
          *local_90 = uVar3 & 0xfc7f | uVar18;
          iVar20 = 0;
          local_50 = 0xff;
          lVar17 = 0;
          puVar13 = local_98;
          puVar21 = (ushort *)(param_1 + 0x14c7);
          do {
            if (((((*puVar13 & 1) != 0) && ((*puVar13 & 2) == 0)) &&
                (*(short *)((longlong)puVar21 + -3) == -0x55ab)) && (local_48[lVar17] != '\x01')) {
              uVar5 = RfVerifyIsDiskInRaid(psVar1);
              uVar16 = local_a8;
              if ((char)uVar5 == '\0') {
                local_48[lVar17 + 8] = '\x01';
                local_48[lVar17] = '\x01';
              }
              else {
                uVar7 = 0;
                uVar3 = *local_90 >> 3 & 0xf;
                if ((uVar3 == 0) || (uVar3 == 5)) {
LAB_0002bcb0:
                  uVar7 = (byte)local_90[1] & 7;
                }
                else if (uVar3 == 1) {
                  uVar7 = ((byte)local_90[1] & 7) + 2;
                }
                else if (uVar3 == 9) {
                  uVar7 = ((byte)local_90[1] & 7) * 2;
                }
                else if (uVar3 == 8) goto LAB_0002bcb0;
                uVar15 = 0;
                if (uVar7 != 0) {
                  piVar11 = (int *)((longlong)local_90 + 0xf);
                  do {
                    if (*piVar11 !=
                        *(int *)((longlong)puVar21 +
                                (longlong)piVar11 + (0xf - ((longlong)local_90 + 0xf))))
                    goto LAB_0002b987;
                    uVar15 = uVar15 + 1;
                    piVar11 = piVar11 + 1;
                  } while (uVar15 < uVar7);
                }
                uVar3 = *puVar21;
                *(char *)local_78 = (char)iVar20;
                local_a8 = local_a8 + 1;
                local_78 = (undefined7 *)((longlong)local_78 + 1);
                local_48[lVar17] = '\x01';
                *puVar21 = uVar3 & 0xfc7f | uVar18;
                uVar16 = local_a8;
              }
            }
LAB_0002b987:
            iVar20 = iVar20 + 1;
            puVar13 = puVar13 + 1;
            lVar17 = lVar17 + 1;
            puVar21 = puVar21 + 0x100;
          } while (iVar20 < 8);
          iVar20 = 0;
          if ((int)uVar16 < (int)local_a4) {
            if (local_58 != -1) {
              uVar15 = 1;
              iVar4 = 2;
              uVar7 = uVar16;
              do {
                lVar17 = (longlong)local_48[(longlong)iVar20 + -0x10] * 0x200;
                if ((*(byte *)(lVar17 + 3 + (longlong)puVar14) & 0x78) == 8) {
                  bVar6 = 0xff;
                  bVar9 = (byte)((ushort)*(undefined2 *)
                                          ((longlong)local_58 * 0x200 + 3 + (longlong)puVar14) >> 10
                                ) & 3;
                  if ((char)uStack_57 != -1) {
                    bVar6 = (byte)((ushort)*(undefined2 *)
                                            ((longlong)(char)uStack_57 * 0x200 + 3 +
                                            (longlong)puVar14) >> 10) & 3;
                  }
                  if (((bVar9 == 0) && (bVar6 == 1)) || ((bVar9 == 1 && (bVar6 == 0)))) break;
                  uVar7 = local_a8;
                }
                pbVar8 = (byte *)(lVar17 + 5 + (longlong)puVar14);
                *pbVar8 = *pbVar8 | 8;
                *(undefined8 *)(lVar17 + 0x49 + (longlong)puVar14) = 0;
                uVar18 = *(ushort *)(lVar17 + 3 + (longlong)puVar14);
                uVar3 = uVar18 >> 3 & 0xf;
                if (uVar3 == 9) {
                  uVar3 = uVar18 >> 10 & 7;
                  if (uVar16 == 3) {
                    if (uVar3 != (*(ushort *)
                                   ((longlong)local_48[(longlong)((int)uVar15 % 3) + -0x10] * 0x200
                                    + 3 + (longlong)puVar14) >> 10 & 7)) {
                      uVar7 = iVar4 % 3;
                      goto LAB_0002baba;
                    }
                  }
                  else if (uVar16 == 2) {
                    uVar7 = uVar15 & 0x80000001;
                    if ((int)uVar7 < 0) {
                      uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
                    }
LAB_0002baba:
                    if (uVar3 != (*(ushort *)
                                   ((longlong)local_48[(longlong)(int)uVar7 + -0x10] * 0x200 + 3 +
                                   (longlong)puVar14) >> 10 & 7)) {
                      *(ushort *)(lVar17 + 3 + (longlong)puVar14) = uVar18 | 0x4000;
                    }
                  }
                }
                else {
                  if (uVar3 == 1) {
                    uVar3 = 0x1000;
                  }
                  else {
                    if ((uVar3 != 5) || (uVar7 != local_a4 - 1)) goto LAB_0002bae9;
                    uVar3 = 0x2000;
                  }
                  *(ushort *)(lVar17 + 3 + (longlong)puVar14) = uVar18 | uVar3;
                }
LAB_0002bae9:
                iVar20 = iVar20 + 1;
                iVar4 = iVar4 + 1;
                uVar15 = uVar15 + 1;
                uVar7 = local_a8;
              } while (local_48[(longlong)iVar20 + -0x10] != -1);
            }
          }
          else if ((uVar16 == local_a4) && (lVar17 = 0, local_a4 != 0)) {
            do {
              bVar6 = *(byte *)((longlong)local_48[lVar17 + -0x10] * 0x200 + 5 + (longlong)puVar14);
              if ((bVar6 & 8) != 0) {
                *(byte *)((longlong)local_48[lVar17 + -0x10] * 0x200 + 5 + (longlong)puVar14) =
                     bVar6 & 0xf7;
              }
              lVar17 = lVar17 + 1;
            } while (lVar17 < (int)local_a4);
          }
          uVar19 = uVar19 + 1;
          uVar18 = uVar19;
        }
      }
    }
    lVar17 = 8;
    local_9c = local_9c + 1;
    local_88 = local_88 + 1;
    local_80 = local_80 + 1;
    local_90 = local_90 + 0x100;
  } while (local_9c < 8);
  pcVar10 = local_48 + 8;
  pbVar8 = (byte *)(param_1 + 0x1502);
  puVar13 = local_98;
  do {
    if (((((*puVar13 & 1) != 0) && ((*puVar13 & 2) == 0)) && ((pbVar8[-0x3b] & 0x78) == 0x28)) &&
       (((*pcVar10 != '\x01' && ((*pbVar8 & 0xf0) == 0x10)) && (*(char *)(param_1 + 0x4218) == '\0')
        ))) {
      *pbVar8 = 1;
    }
    puVar13 = puVar13 + 1;
    pbVar8 = pbVar8 + 0x200;
    pcVar10 = pcVar10 + 1;
    lVar17 = lVar17 + -1;
  } while (lVar17 != 0);
  uVar16 = 0;
  pcVar10 = local_48 + 8;
  pcVar12 = (char *)(param_1 + 0x399);
  uVar5 = 0;
  do {
    iVar20 = 0;
    if ((((*local_98 & 2) == 0) && (pcVar12[-1] == '\0')) &&
       ((*pcVar12 == '\0' || (pcVar12[0x15] != '\0')))) {
      if ((*local_98 & 1) != 0) {
        do {
          iVar4 = ReadWriteConfigFromHDD(param_1,uVar16,puVar14,uVar5,'\x01');
          if (iVar4 == 1) break;
          iVar20 = iVar20 + 1;
        } while (iVar20 < 4);
      }
      if (*pcVar10 == '\x01') {
        *(undefined2 *)puVar14 = 0;
      }
    }
    local_98 = local_98 + 1;
    uVar16 = uVar16 + 1;
    pcVar12 = pcVar12 + 0xb8;
    puVar14 = puVar14 + 0x40;
    pcVar10 = pcVar10 + 1;
    if (7 < (int)uVar16) {
      return;
    }
  } while( true );
}



===== RfCheckRaidCapacity @ 0002bdb4 =====

void RfCheckRaidCapacity(longlong param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  int iVar5;
  longlong lVar6;
  byte *pbVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  int *piVar11;
  ushort *puVar12;
  
  lVar6 = (longlong)param_2;
  iVar5 = 0;
  lVar3 = 0;
  lVar9 = lVar6 * 0xb8;
  lVar10 = lVar6 * 0x200;
  iVar1 = *(int *)(lVar9 + 0x3a8 + param_1);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      lVar3 = CONCAT44(*(undefined4 *)(lVar10 + 0x14ce + param_1),
                       *(undefined4 *)(lVar10 + 0x14ca + param_1));
    }
    else {
      if (iVar1 == 5) {
        uVar2 = *(uint *)(lVar9 + 0x3b0 + param_1);
        if (*(int *)(lVar9 + 0x3e0 + param_1) == 0) goto LAB_0002c014;
        pcVar4 = (char *)(param_1 + 0x3a4);
        lVar6 = lVar3;
        do {
          if (((*(int *)(pcVar4 + 4) == 5) && (*pcVar4 == *(char *)(lVar9 + 0x3a4 + param_1))) &&
             ((*(uint *)(pcVar4 + 0xc) & 0xf0) == 0)) goto LAB_0002bfd4;
          lVar6 = lVar6 + 1;
          iVar5 = iVar5 + 1;
          pcVar4 = pcVar4 + 0xb8;
        } while (lVar6 < 8);
        goto LAB_0002c031;
      }
      if (iVar1 == 8) {
        plVar8 = (longlong *)(param_1 + 0x14ca);
        pbVar7 = (byte *)(param_1 + 0xab8);
        lVar10 = CONCAT44(*(undefined4 *)(lVar10 + 0x14ce + param_1),
                          *(undefined4 *)(lVar10 + 0x14ca + param_1));
        piVar11 = (int *)(param_1 + 0x3a8);
        do {
          if (((((lVar3 != lVar6) && ((*pbVar7 & 1) != 0)) && (piVar11[-5] == 0)) &&
              ((piVar11[-8] == 0 && (*piVar11 == 8)))) &&
             ((char)piVar11[-1] == *(char *)(lVar9 + 0x3a4 + param_1))) {
            lVar10 = lVar10 + *plVar8;
          }
          lVar3 = lVar3 + 1;
          pbVar7 = pbVar7 + 2;
          piVar11 = piVar11 + 0x2e;
          plVar8 = plVar8 + 0x40;
        } while (lVar3 < 8);
        *(int *)(lVar9 + 0x3f0 + param_1) = (int)(lVar10 + -1);
        *(int *)(lVar9 + 0x438 + param_1) = (int)((ulonglong)(lVar10 + -1) >> 0x20);
        goto LAB_0002c048;
      }
      if (iVar1 != 9) {
        return;
      }
      lVar3 = CONCAT44(*(undefined4 *)(lVar10 + 0x14ce + param_1),
                       *(undefined4 *)(lVar10 + 0x14ca + param_1)) *
              (ulonglong)(*(uint *)(lVar9 + 0x3b0 + param_1) & 0xf);
    }
    *(int *)(lVar9 + 0x3f0 + param_1) = (int)(lVar3 + -1);
    *(int *)(lVar9 + 0x438 + param_1) = (int)((ulonglong)(lVar3 + -1) >> 0x20);
    goto LAB_0002c048;
  }
  uVar2 = *(uint *)(lVar9 + 0x3b0 + param_1);
  if (*(int *)(lVar9 + 0x3e0 + param_1) == 0) {
LAB_0002c014:
    lVar3 = CONCAT44(*(undefined4 *)(lVar10 + 0x14ce + param_1),
                     *(undefined4 *)(lVar10 + 0x14ca + param_1)) * (ulonglong)(uVar2 & 0xf);
  }
  else {
    puVar12 = (ushort *)(param_1 + 0xab8);
    pcVar4 = (char *)(param_1 + 0x3a4);
    do {
      if (((((*puVar12 & 1) != 0) && ((*puVar12 & 2) == 0)) && (*(int *)(pcVar4 + -0x1c) == 0)) &&
         (((*(int *)(pcVar4 + 4) == 0 && (*pcVar4 == *(char *)(lVar9 + 0x3a4 + param_1))) &&
          ((*(uint *)(pcVar4 + 0xc) & 0xf0) == 0)))) goto LAB_0002bfd4;
      iVar5 = iVar5 + 1;
      puVar12 = puVar12 + 1;
      pcVar4 = pcVar4 + 0xb8;
    } while (iVar5 < 8);
  }
  goto LAB_0002c031;
LAB_0002bfd4:
  lVar3 = (longlong)iVar5 * 0xd4;
  *(undefined4 *)(lVar9 + 0x3f0 + param_1) = *(undefined4 *)(lVar3 + 0xd8c + param_1);
  *(undefined4 *)(lVar9 + 0x438 + param_1) = *(undefined4 *)(lVar3 + 0xddc + param_1);
  lVar3 = CONCAT44(*(undefined4 *)(lVar3 + 0xddc + param_1),*(undefined4 *)(lVar3 + 0xd8c + param_1)
                  );
LAB_0002c031:
  *(int *)(lVar9 + 0x3f0 + param_1) = (int)(lVar3 + -1);
  *(int *)(lVar9 + 0x438 + param_1) = (int)((ulonglong)(lVar3 + -1) >> 0x20);
LAB_0002c048:
  *(undefined4 *)(lVar9 + 0x3b8 + param_1) = *(undefined4 *)(lVar9 + 0x3f0 + param_1);
  *(undefined4 *)(lVar9 + 0x420 + param_1) = *(undefined4 *)(lVar9 + 0x438 + param_1);
  return;
}



===== RfBuildDiskLinker @ 0002c080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RfBuildDiskLinker(longlong param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  longlong lVar5;
  int *piVar6;
  char *pcVar7;
  byte bVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  undefined1 auStack_58 [32];
  char local_38 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_58;
  iVar9 = 0;
  pcVar7 = local_38;
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  piVar6 = (int *)(param_1 + 0x3a8);
  pbVar11 = (byte *)(param_1 + 0xab8);
  do {
    iVar1 = *piVar6;
    iVar2 = piVar6[-1];
    if (((((*pbVar11 & 1) != 0) && (piVar6[-5] == 0)) && (piVar6[-8] == 0)) && (*pcVar7 != '\x01'))
    {
      bVar8 = (byte)iVar9;
      if (iVar1 == 0) {
        if ((char)piVar6[1] == '\0') {
          BuildRaid0Linklist(param_1,bVar8,(longlong)local_38);
        }
        else {
          lVar5 = 0;
          piVar3 = (int *)(param_1 + 0x3a8);
          pbVar10 = (byte *)(param_1 + 0xab8);
          do {
            if ((((*pbVar10 & 1) != 0) && (piVar3[-5] == 0)) &&
               ((piVar3[-8] == 0 && ((*piVar3 == 0 && ((char)piVar3[-1] == (char)iVar2)))))) {
              piVar6[-7] = 0;
              local_38[lVar5] = '\x01';
            }
            lVar5 = lVar5 + 1;
            pbVar10 = pbVar10 + 2;
            piVar3 = piVar3 + 0x2e;
          } while (lVar5 < 8);
        }
      }
      else if (iVar1 == 5) {
        BuildRaid5Linklist(param_1,bVar8,local_38);
      }
      else if (iVar1 == 1) {
        BuildRaid1Linklist(param_1,bVar8,local_38);
      }
      else if (iVar1 == 9) {
        BuildRaid01Linklist(param_1,bVar8,(longlong)local_38);
      }
      else if (iVar1 == 8) {
        if ((char)piVar6[1] == '\0') {
          BuildRaidSpanLinklist(param_1,bVar8,(longlong)local_38);
        }
        else {
          lVar5 = 0;
          pcVar4 = (char *)(param_1 + 0x3a4);
          do {
            if ((*(int *)(pcVar4 + 4) == 8) && (*pcVar4 == (char)iVar2)) {
              piVar6[-7] = 0;
              local_38[lVar5] = '\x01';
            }
            lVar5 = lVar5 + 1;
            pcVar4 = pcVar4 + 0xb8;
          } while (lVar5 < 8);
        }
      }
    }
    iVar9 = iVar9 + 1;
    pbVar11 = pbVar11 + 2;
    piVar6 = piVar6 + 0x2e;
    pcVar7 = pcVar7 + 1;
  } while (iVar9 < 8);
  return;
}



===== BuildRaid0Linklist @ 0002c238 =====

ulonglong BuildRaid0Linklist(longlong param_1,byte param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  int *piVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  
  lVar1 = param_1 + 0x388;
  uVar6 = (ulonglong)param_2;
  uVar11 = 0xffffffff;
  pbVar12 = (byte *)(param_1 + 0xab8);
  cVar3 = *(char *)(uVar6 * 0xb8 + 0x1c + lVar1);
  iVar5 = *(int *)(uVar6 * 0xb8 + 0x20 + lVar1);
  uVar13 = 0;
  piVar8 = (int *)(param_1 + 0x3a8);
  uVar14 = 2;
  do {
    uVar6 = CONCAT71((int7)(uVar6 >> 8),*pbVar12);
    if (((((*pbVar12 & 1) != 0) && (piVar8[-5] == 0)) && (piVar8[-8] == 0)) &&
       (((*piVar8 == iVar5 && (uVar6 = 0, (char)piVar8[-1] == cVar3)) &&
        (uVar6 = (ulonglong)(uint)piVar8[2], (piVar8[2] & 0xf0U) == 0)))) {
      piVar8[-7] = 1;
      uVar11 = uVar13;
    }
    uVar13 = uVar13 + 1;
    pbVar12 = pbVar12 + 2;
    piVar8 = piVar8 + 0x2e;
  } while ((int)uVar13 < 8);
  if (uVar11 == 0xffffffff) {
LAB_0002c2ce:
    uVar6 = uVar6 & 0xffffffffffffff00;
  }
  else {
    lVar7 = (longlong)(int)uVar11 * 0xb8;
    *(undefined1 *)((int)uVar11 + param_3) = 1;
    lVar2 = lVar7 + lVar1;
    cVar3 = *(char *)(lVar2 + 0x1c);
    iVar5 = *(int *)(lVar2 + 0x20);
    uVar6 = CONCAT71((int7)((ulonglong)lVar7 >> 8),*(byte *)(lVar2 + 0x28)) & 0xffffffffffffff0f;
    uVar13 = *(byte *)(lVar2 + 0x28) & 0xf;
    lVar7 = lVar2;
    if (1 < uVar13) {
      do {
        uVar10 = 0;
        while( true ) {
          bVar4 = *(byte *)(param_1 + 0xab8 + uVar10 * 2);
          uVar6 = CONCAT71((int7)(uVar10 >> 8),bVar4);
          piVar8 = (int *)(uVar10 * 0xb8 + lVar1);
          if ((((bVar4 & 1) != 0) && (piVar8[3] == 0)) &&
             ((*piVar8 == 0 &&
              (((piVar8[8] == iVar5 && (uVar6 = 0, (char)piVar8[7] == cVar3)) &&
               (uVar6 = 0, ((uint)piVar8[10] >> 4 & 0xf) + 1 == uVar14)))))) break;
          uVar9 = (uint)uVar10 + 1;
          uVar10 = (ulonglong)uVar9;
          if (7 < uVar9) {
            *(undefined4 *)(lVar2 + 4) = 0;
            goto LAB_0002c2ce;
          }
        }
        *(undefined1 *)(uVar10 + param_3) = 1;
        uVar9 = (((uint)uVar10 & 0xff) << 8 ^ *(uint *)(lVar7 + 0x28)) & 0xf00;
        *(uint *)(lVar7 + 0x28) = *(uint *)(lVar7 + 0x28) ^ uVar9;
        lVar7 = uVar10 * 0xb8 + lVar1;
        if (uVar14 == uVar13) {
          uVar9 = *(uint *)(lVar7 + 0x28) & 0xfffff0ff;
          *(uint *)(lVar7 + 0x28) = (uVar11 & 0xf | 0x10) << 8 | uVar9;
        }
        uVar6 = (ulonglong)uVar9;
        uVar14 = uVar14 + 1;
      } while ((int)uVar14 <= (int)uVar13);
    }
    uVar6 = CONCAT71((int7)(uVar6 >> 8),1);
  }
  return uVar6;
}



===== LookForRaid5Disk @ 0002c3c8 =====

ulonglong LookForRaid5Disk(longlong param_1,byte param_2,byte param_3)

{
  longlong lVar1;
  int *piVar2;
  byte bVar3;
  ulonglong uVar4;
  
  lVar1 = param_1 + 0x388;
  uVar4 = 0;
  while( true ) {
    piVar2 = (int *)(uVar4 * 0xb8 + lVar1);
    if (((((*(byte *)(param_1 + 0xab8 + uVar4 * 2) & 1) != 0) && (piVar2[3] == 0)) && (*piVar2 == 0)
        ) && (((piVar2[8] == *(int *)((ulonglong)param_2 * 0xb8 + 0x20 + lVar1) &&
               ((char)piVar2[7] == *(char *)((ulonglong)param_2 * 0xb8 + 0x1c + lVar1))) &&
              (((byte)((uint)piVar2[10] >> 4) & 0xf) == param_3)))) break;
    bVar3 = (char)uVar4 + 1;
    uVar4 = (ulonglong)bVar3;
    if (7 < bVar3) {
      return 0xff;
    }
  }
  return uVar4;
}



===== BuildRaid5Linklist @ 0002c444 =====

ulonglong BuildRaid5Linklist(longlong param_1,byte param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  uint uVar10;
  int *piVar11;
  undefined8 *puVar12;
  char cVar13;
  int *piVar14;
  byte bVar15;
  undefined1 *puVar16;
  int iVar17;
  byte *pbVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int *piVar22;
  int *piVar23;
  
  lVar8 = param_1 + 0x388;
  piVar22 = (int *)(param_1 + 0x3a8);
  uVar21 = 0xffffffff;
  uVar20 = 0;
  cVar1 = *(char *)((ulonglong)param_2 * 0xb8 + 0x1c + lVar8);
  iVar2 = *(int *)((ulonglong)param_2 * 0xb8 + 0x20 + lVar8);
  pbVar6 = (byte *)(param_1 + 0xab8);
  cVar13 = '\0';
  uVar19 = 0xff;
  uVar10 = 0;
  piVar23 = piVar22;
  puVar16 = param_3;
  pbVar18 = pbVar6;
  do {
    pbVar6 = (byte *)CONCAT71((int7)((ulonglong)pbVar6 >> 8),*pbVar18);
    if (((((*pbVar18 & 1) != 0) && (piVar23[-5] == 0)) && (piVar23[-8] == 0)) &&
       ((*piVar23 == iVar2 && (pbVar6 = (byte *)0x0, (char)piVar23[-1] == cVar1)))) {
      *puVar16 = 1;
      if (cVar13 == '\0') {
        cVar13 = *(char *)((longlong)piVar23 + 5);
      }
      uVar5 = (uint)piVar23[2] >> 4 & 0xf;
      pbVar6 = (byte *)0x0;
      if (uVar5 < uVar19) {
        uVar19 = uVar5;
        uVar21 = uVar10;
      }
      uVar20 = uVar20 + 1;
    }
    uVar10 = uVar10 + 1;
    pbVar18 = pbVar18 + 2;
    piVar23 = piVar23 + 0x2e;
    puVar16 = puVar16 + 1;
  } while ((int)uVar10 < 8);
  if (uVar21 != 0xffffffff) {
    piVar23 = (int *)((longlong)(int)uVar21 * 0xb8 + lVar8);
    iVar4 = piVar23[7];
    iVar2 = piVar23[8];
    pbVar6 = (byte *)(CONCAT71((int7)(int3)(uVar21 >> 8),*(byte *)(piVar23 + 10)) &
                     0xffffffffffffff0f);
    uVar19 = *(byte *)(piVar23 + 10) & 0xf;
    if (uVar19 <= uVar20) {
      piVar23[1] = 1;
      *(undefined1 *)(piVar23 + 0x11) = 0xff;
      if (uVar20 == uVar19) {
        *(undefined1 *)(piVar23 + 9) = 1;
        pbVar18 = (byte *)0x0;
        if (uVar19 != 0xffffffff) {
          do {
            bVar15 = (byte)pbVar18;
            pbVar6 = (byte *)LookForRaid5Disk(param_1,(byte)uVar21,bVar15);
            if ((char)pbVar6 == -1) {
              *(byte *)(piVar23 + 0x11) = bVar15;
              break;
            }
            pbVar6 = (byte *)(ulonglong)(byte)(bVar15 + 1);
            pbVar18 = pbVar6;
          } while ((uint)(byte)(bVar15 + 1) < uVar19 + 1);
        }
      }
      else if (cVar13 == '\x01') {
        bVar15 = 0;
        if (uVar19 != 0xffffffff) {
          do {
            uVar7 = LookForRaid5Disk(param_1,(byte)uVar21,bVar15);
            pbVar6 = (byte *)((uVar7 & 0xff) * 0xb8);
            if (pbVar6[param_1 + 0x3ad] == 0) {
              *(byte *)(piVar23 + 0x11) = bVar15;
              break;
            }
            bVar15 = bVar15 + 1;
            pbVar6 = (byte *)0x0;
          } while ((uint)bVar15 < uVar19 + 1);
        }
      }
      iVar17 = 1;
      uVar19 = 2;
      piVar14 = piVar23;
      if (1 < (int)uVar20) {
        do {
          uVar7 = 0;
          do {
            bVar15 = *(byte *)(param_1 + 0xab8 + uVar7 * 2);
            pbVar6 = (byte *)CONCAT71((int7)(uVar7 >> 8),bVar15);
            piVar11 = (int *)(uVar7 * 0xb8 + param_1 + 0x388);
            if (((((bVar15 & 1) != 0) && (piVar11[3] == 0)) &&
                ((*piVar11 == 0 &&
                 (((piVar11 != piVar14 && (piVar11[8] == iVar2)) &&
                  (pbVar6 = (byte *)0x0, (char)piVar11[7] == (char)iVar4)))))) &&
               (pbVar6 = (byte *)0x0,
               ((uint)piVar11[10] >> 4 & 0xf) == ((uint)piVar14[10] >> 4 & 0xf) + iVar17)) {
              param_3[uVar7] = 1;
              iVar17 = 1;
              uVar10 = (((uint)uVar7 & 0xff) << 0xe ^ piVar14[10]) & 0x3c000;
              piVar14[10] = piVar14[10] ^ uVar10;
              piVar14 = (int *)(uVar7 * 0xb8 + param_1 + 0x388);
              if (uVar19 == uVar20) {
                uVar10 = ((uVar21 & 0xff) << 0xe ^ piVar14[10]) & 0x3c000;
                piVar14[10] = piVar14[10] ^ uVar10;
                *(char *)((longlong)piVar23 + 0x45) = (char)uVar7;
              }
              pbVar6 = (byte *)(ulonglong)uVar10;
              uVar19 = uVar19 + 1;
              goto LAB_0002c62f;
            }
            uVar10 = (uint)uVar7 + 1;
            uVar7 = (ulonglong)uVar10;
          } while (uVar10 < 8);
          if (cVar13 == '\x01') {
            iVar17 = 2;
          }
LAB_0002c62f:
        } while ((int)uVar19 <= (int)uVar20);
      }
      pbVar18 = (byte *)(param_1 + 0xab8);
      lVar8 = 8;
      do {
        pbVar6 = (byte *)CONCAT71((int7)((ulonglong)pbVar6 >> 8),*pbVar18);
        if ((((*pbVar18 & 1) != 0) && (piVar22[-5] == 0)) &&
           ((piVar22[-8] == 0 &&
            ((*piVar22 == iVar2 && (pbVar6 = (byte *)0x0, (char)piVar22[-1] == (char)iVar4)))))) {
          *(char *)(piVar22 + 9) = (char)piVar23[0x11];
          pbVar6 = (byte *)0x0;
          *(char *)(piVar22 + 1) = (char)piVar23[9];
        }
        pbVar18 = pbVar18 + 2;
        piVar22 = piVar22 + 0x2e;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      *(undefined1 *)(param_1 + 0x42b8) = 0;
      if (*(int *)(param_1 + 0x20c) == 0x33491106) {
        pbVar6 = (byte *)CONCAT71((int7)((ulonglong)pbVar6 >> 8),Hibernate);
        if (Hibernate == '\0') {
          puVar9 = (undefined8 *)(param_1 + 0x4220);
          lVar8 = 8;
          puVar12 = (undefined8 *)(param_1 + 0x46f0);
          do {
            puVar9[8] = *puVar12;
            pbVar6 = (byte *)*puVar12;
            puVar12 = puVar12 + 3;
            *puVar9 = pbVar6;
            puVar9 = puVar9 + 1;
            lVar8 = lVar8 + -1;
          } while (lVar8 != 0);
        }
        else if (Hibernate == '\x01') {
          lVar8 = *(longlong *)(param_1 + 0x42a0);
          pbVar6 = (byte *)(ulonglong)g_raid5hiberBufSize;
          *(longlong *)(param_1 + 0x4260) = lVar8;
          *(longlong *)(param_1 + 0x4220) = lVar8;
          pbVar18 = pbVar6 + lVar8;
          *(byte **)(param_1 + 0x4270) = pbVar18;
          *(byte **)(param_1 + 0x4230) = pbVar18;
          pbVar18 = pbVar18 + (longlong)pbVar6;
          *(byte **)(param_1 + 0x4280) = pbVar18;
          *(byte **)(param_1 + 0x4240) = pbVar18;
          *(byte **)(param_1 + 0x4290) = pbVar18 + (longlong)pbVar6;
          *(byte **)(param_1 + 0x4250) = pbVar18 + (longlong)pbVar6;
        }
      }
      else {
        puVar9 = (undefined8 *)(param_1 + 0x4220);
        lVar8 = 8;
        puVar12 = (undefined8 *)(param_1 + 0x46f0);
        do {
          puVar9[8] = *puVar12;
          uVar3 = *puVar12;
          puVar12 = puVar12 + 3;
          *puVar9 = uVar3;
          puVar9 = puVar9 + 1;
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
      }
      return CONCAT71((int7)((ulonglong)pbVar6 >> 8),1);
    }
  }
  return (ulonglong)pbVar6 & 0xffffffffffffff00;
}



===== SetFailedMember @ 0002c834 =====

void SetFailedMember(longlong param_1,byte param_2)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  ushort *puVar8;
  
  puVar8 = (ushort *)(param_1 + 0x14c7);
  piVar5 = (int *)(param_1 + 0x3a8);
  pbVar7 = (byte *)(param_1 + 0xab8);
  iVar2 = *(int *)((ulonglong)param_2 * 0xb8 + 0x3a8 + param_1);
  cVar1 = *(char *)((ulonglong)param_2 * 0xb8 + 0x3a4 + param_1);
  iVar6 = 0;
  do {
    if (((((*pbVar7 & 1) != 0) && (piVar5[-5] == 0)) && (piVar5[-8] == 0)) &&
       (((*piVar5 == iVar2 && ((char)piVar5[-1] == cVar1)) && ((*puVar8 & 0x8000) != 0)))) {
      uVar3 = FindMirrorPair((byte)iVar6,param_1);
      if ((char)uVar3 != -1) {
        lVar4 = (uVar3 & 0xff) * 0xb8;
        *(undefined1 *)(lVar4 + 0x3ae + param_1) = 1;
        *(undefined1 *)(lVar4 + 0x399 + param_1) = 1;
      }
    }
    iVar6 = iVar6 + 1;
    pbVar7 = pbVar7 + 2;
    piVar5 = piVar5 + 0x2e;
    puVar8 = puVar8 + 0x100;
  } while (iVar6 < 8);
  return;
}



===== FindMirrorPair @ 0002c910 =====

undefined8 FindMirrorPair(byte param_1,longlong param_2)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  byte bVar6;
  longlong lVar7;
  longlong lVar8;
  bool bVar9;
  
  lVar7 = (ulonglong)param_1 * 0xb8;
  uVar3 = *(uint *)(lVar7 + 0x3a8 + param_2);
  uVar5 = (ulonglong)uVar3;
  cVar1 = *(char *)(lVar7 + 0x3a4 + param_2);
  if (uVar3 == 1) {
    bVar6 = 0;
    do {
      uVar5 = (ulonglong)bVar6;
      lVar8 = uVar5 * 0xb8;
      if (*(int *)(lVar8 + 0x3a8 + param_2) == 1) {
        uVar3 = *(uint *)(lVar8 + 0x3b0 + param_2);
        uVar5 = (ulonglong)uVar3;
        if ((*(uint *)(lVar7 + 0x3b0 + param_2) & 0xf0) == 0) {
          uVar5 = (ulonglong)uVar3 & 0xfffffffffffffff0;
          bVar9 = (char)uVar5 == '\x10';
        }
        else {
          bVar9 = (uVar3 & 0xf0) == 0;
        }
        if ((bVar9) && (*(char *)(lVar8 + 0x3a4 + param_2) == cVar1)) {
LAB_0002c988:
          return CONCAT71((int7)(uVar5 >> 8),bVar6);
        }
      }
      bVar6 = bVar6 + 1;
    } while (bVar6 < 8);
  }
  else if (uVar3 == 9) {
    bVar6 = 0;
    do {
      uVar5 = (ulonglong)bVar6;
      lVar8 = uVar5 * 0xb8;
      if (*(int *)(lVar8 + 0x3a8 + param_2) == 9) {
        uVar3 = *(uint *)(lVar7 + 0x3b0 + param_2);
        if ((uVar3 & 0x300000) == 0) {
          uVar4 = *(uint *)(lVar8 + 0x3b0 + param_2);
          uVar5 = (ulonglong)(uVar4 & 0x300000);
          if ((uVar4 & 0x300000) == 0x100000) {
            cVar2 = *(char *)(lVar8 + 0x3a4 + param_2);
joined_r0x0002c9fc:
            if ((cVar2 == cVar1) && (((uVar3 ^ uVar4) & 0xf0) == 0)) goto LAB_0002c988;
          }
        }
        else {
          uVar4 = *(uint *)(lVar8 + 0x3b0 + param_2);
          uVar5 = (ulonglong)uVar4;
          if ((uVar4 & 0x300000) == 0) {
            cVar2 = *(char *)(lVar8 + 0x3a4 + param_2);
            goto joined_r0x0002c9fc;
          }
        }
      }
      bVar6 = bVar6 + 1;
    } while (bVar6 < 8);
  }
  return CONCAT71((int7)(uVar5 >> 8),0xff);
}



===== BuildRaid1Linklist @ 0002ca1c =====

undefined8 BuildRaid1Linklist(longlong param_1,byte param_2,undefined1 *param_3)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  char *pcVar7;
  longlong lVar8;
  int iVar9;
  ulonglong uVar10;
  uint uVar11;
  longlong lVar12;
  byte *pbVar13;
  
  uVar10 = (ulonglong)param_2;
  SetFailedMember(param_1,param_2);
  iVar9 = 0;
  pcVar7 = (char *)(param_1 + 0x3a4);
  iVar3 = *(int *)(uVar10 * 0xb8 + 0x3a8 + param_1);
  cVar2 = *(char *)(uVar10 * 0xb8 + 0x3a4 + param_1);
  uVar11 = 0;
  pbVar13 = (byte *)(param_1 + 0xab8);
  do {
    if (((((*pbVar13 & 1) != 0) && (*(int *)(pcVar7 + -0x10) == 0)) &&
        (*(int *)(pcVar7 + -0x1c) == 0)) &&
       ((((iVar4 = *(int *)(pcVar7 + 4), iVar4 == iVar3 && (*pcVar7 == cVar2)) &&
         ((*param_3 = 1, iVar4 != 1 || (((byte)*(undefined4 *)(pcVar7 + 0xc) & 0xf0) != 0x20)))) &&
        (pcVar7[-0xb] != '\x01')))) {
      iVar9 = iVar9 + 1;
      if (iVar4 == 1) {
        uVar10 = (ulonglong)(uVar11 & 0xff);
      }
    }
    uVar11 = uVar11 + 1;
    pbVar13 = pbVar13 + 2;
    pcVar7 = pcVar7 + 0xb8;
    param_3 = param_3 + 1;
  } while ((int)uVar11 < 8);
  if (iVar9 == 1) {
    lVar8 = uVar10 * 0xb8;
    *(undefined4 *)(lVar8 + 0x38c + param_1) = 1;
  }
  else {
    if (1 < iVar9 - 2U) {
      *(undefined4 *)(uVar10 * 0xb8 + 0x38c + param_1) = 0;
      uVar6 = uVar10;
      goto LAB_0002cbff;
    }
    uVar5 = FindMirrorPair((byte)uVar10,param_1);
    uVar6 = uVar5 & 0xff;
    lVar8 = uVar10 * 0xb8;
    if (*(char *)(lVar8 + 0x3ad + param_1) != '\x01') {
      lVar12 = uVar6 * 0xb8;
      if (*(char *)(lVar12 + 0x3ad + param_1) == '\x01') {
        uVar11 = ((int)uVar10 << 8 ^ *(uint *)(lVar12 + 0x3b0 + param_1)) & 0xf00;
        puVar1 = (uint *)(lVar12 + 0x3b0 + param_1);
        *puVar1 = *puVar1 ^ uVar11;
      }
      else {
        uVar11 = *(uint *)(lVar12 + 0x3b0 + param_1);
        if ((uVar11 & 0xf0) != 0) {
          *(undefined4 *)(lVar8 + 0x38c + param_1) = 1;
          puVar1 = (uint *)(lVar8 + 0x3b0 + param_1);
          *puVar1 = *puVar1 ^ (((uint)uVar5 & 0xff) << 8 ^ *(uint *)(lVar8 + 0x3b0 + param_1)) &
                              0xf00;
          puVar1 = (uint *)(lVar12 + 0x3b0 + param_1);
          *puVar1 = *puVar1 | 0xf00;
          goto LAB_0002cbff;
        }
        uVar11 = ((int)uVar10 << 8 ^ uVar11) & 0xf00 ^ uVar11;
        *(uint *)(lVar12 + 0x3b0 + param_1) = uVar11;
      }
      uVar6 = (ulonglong)uVar11;
      *(undefined4 *)(lVar12 + 0x38c + param_1) = 1;
      puVar1 = (uint *)(lVar8 + 0x3b0 + param_1);
      *puVar1 = *puVar1 | 0xf00;
      goto LAB_0002cbff;
    }
    *(undefined4 *)(lVar8 + 0x38c + param_1) = 1;
    puVar1 = (uint *)(lVar8 + 0x3b0 + param_1);
    *puVar1 = *puVar1 ^ ((int)uVar6 << 8 ^ *(uint *)(lVar8 + 0x3b0 + param_1)) & 0xf00;
    lVar8 = (uVar5 & 0xff) * 0xb8;
  }
  puVar1 = (uint *)(lVar8 + 0x3b0 + param_1);
  *puVar1 = *puVar1 | 0xf00;
  uVar6 = 0;
LAB_0002cbff:
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== BuildRaid01Linklist @ 0002cc20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BuildRaid01Linklist(longlong param_1,byte param_2,longlong param_3)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  uint *puVar7;
  int iVar8;
  longlong lVar9;
  char *pcVar10;
  byte *pbVar11;
  undefined1 auStack_98 [32];
  longlong local_78;
  uint local_70;
  uint local_6c;
  longlong local_68;
  byte *local_60;
  longlong local_58;
  char local_50 [8];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_98;
  lVar1 = param_1 + 0x388;
  local_6c = *(uint *)((ulonglong)param_2 * 0xb8 + 0x20 + lVar1);
  uVar4 = 0;
  local_70 = (uint)*(byte *)((ulonglong)param_2 * 0xb8 + 0x1c + lVar1);
  local_68 = param_1;
  local_58 = param_3;
  SetFailedMember(param_1,param_2);
  uVar3 = local_70;
  pbVar11 = (byte *)(param_1 + 0xab8);
  local_50[0] = '\0';
  local_50[1] = '\0';
  local_50[2] = '\0';
  local_50[3] = '\0';
  local_50[4] = '\0';
  local_50[5] = '\0';
  local_50[6] = '\0';
  local_50[7] = '\0';
  lVar5 = param_3 - (longlong)local_50;
  iVar8 = 0;
  pcVar10 = local_50;
  puVar7 = (uint *)(param_1 + 0x3b0);
  lVar9 = 8;
  lVar6 = local_68;
  local_78 = lVar5;
  local_60 = pbVar11;
  do {
    if (((((*pbVar11 & 1) != 0) && (*pcVar10 != '\x01')) && (*pcVar10 = '\x01', puVar7[-7] == 0)) &&
       (((puVar7[-10] == 0 && (puVar7[-2] == local_6c)) &&
        (((byte)puVar7[-3] == uVar3 &&
         (pcVar10[lVar5] = '\x01', *(char *)((longlong)puVar7 + -0x17) != '\x01')))))) {
      uVar4 = FindMirrorPair((byte)iVar8,lVar6);
      uVar4 = uVar4 & 0xff;
      if ((int)uVar4 == 0xff) {
LAB_0002cda1:
        puVar7[-2] = 0;
        *puVar7 = *puVar7 & 0xfff1ffff | 0x1e000;
LAB_0002cdb3:
        uVar4 = (ulonglong)(byte)iVar8;
      }
      else {
        local_50[uVar4] = '\x01';
        *(undefined1 *)(uVar4 + local_58) = 1;
        lVar5 = uVar4 * 0xb8;
        if (*(char *)(lVar5 + 0x11 + lVar1) != '\0') goto LAB_0002cda1;
        puVar2 = (uint *)(lVar5 + 0x28 + lVar1);
        *puVar2 = *puVar2 ^ (iVar8 << 0xd ^ *(uint *)(lVar5 + 0x28 + lVar1)) & 0xfe000;
        *puVar7 = *puVar7 ^ ((int)uVar4 << 0xd ^ *puVar7) & 0xfe000;
        if ((*(char *)(lVar5 + 0x25 + lVar1) != '\x01') &&
           ((*(char *)((longlong)puVar7 + -3) == '\x01' ||
            ((*(uint *)(lVar5 + 0x28 + lVar1) & 0x300000) != 0)))) {
          puVar7[-2] = 0;
          puVar2 = (uint *)(lVar5 + 0x28 + lVar1);
          *puVar2 = *puVar2 | 0x1f00;
          goto LAB_0002cdb3;
        }
        *(undefined4 *)(lVar5 + 0x20 + lVar1) = 0;
        *puVar7 = *puVar7 | 0x1f00;
      }
      lVar5 = local_78;
    }
    iVar8 = iVar8 + 1;
    pbVar11 = pbVar11 + 2;
    pcVar10 = pcVar10 + 1;
    puVar7 = puVar7 + 0x2e;
    if (7 < iVar8) {
      uVar4 = BuildRaid0Linklist(local_68,(byte)uVar4,(longlong)local_50);
      pbVar11 = (byte *)(param_1 + 0x3a4);
      do {
        if (((((*local_60 & 1) != 0) && (*(int *)(pbVar11 + -0x10) == 0)) &&
            (*(int *)(pbVar11 + -0x1c) == 0)) && (*pbVar11 == local_70)) {
          pbVar11[4] = 9;
          pbVar11[5] = 0;
          pbVar11[6] = 0;
          pbVar11[7] = 0;
        }
        local_60 = local_60 + 2;
        pbVar11 = pbVar11 + 0xb8;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      return CONCAT71((int7)(uVar4 >> 8),1);
    }
  } while( true );
}



===== BuildRaidSpanLinklist @ 0002ce48 =====

undefined8 BuildRaidSpanLinklist(longlong param_1,byte param_2,longlong param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  byte *pbVar5;
  longlong lVar6;
  int *piVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  lVar1 = param_1 + 0x388;
  uVar11 = 0;
  uVar12 = 0xffffffff;
  uVar10 = 2;
  iVar3 = *(int *)((ulonglong)param_2 * 0xb8 + 0x20 + lVar1);
  cVar2 = *(char *)((ulonglong)param_2 * 0xb8 + 0x1c + lVar1);
  piVar7 = (int *)(param_1 + 0x3a8);
  pbVar5 = (byte *)(param_1 + 0xab8);
  do {
    if ((((((*pbVar5 & 1) != 0) && (piVar7[-5] == 0)) && (piVar7[-8] == 0)) &&
        ((*piVar7 == iVar3 && ((char)piVar7[-1] == cVar2)))) && ((piVar7[2] & 0xf0U) == 0)) {
      piVar7[-7] = 1;
      uVar12 = uVar11;
    }
    uVar11 = uVar11 + 1;
    pbVar5 = pbVar5 + 2;
    piVar7 = piVar7 + 0x2e;
  } while (uVar11 < 8);
  uVar4 = (ulonglong)uVar12;
  *(undefined1 *)(uVar4 + param_3) = 1;
  lVar8 = uVar4 * 0xb8 + lVar1;
  uVar12 = *(uint *)(lVar8 + 0x28) & 0xf;
  if (1 < uVar12) {
    do {
      uVar9 = 0;
      do {
        lVar6 = uVar9 * 0xb8;
        uVar4 = uVar9;
        if (((*(int *)(lVar6 + 0x20 + lVar1) == iVar3) &&
            (uVar4 = 0, *(char *)(lVar6 + 0x1c + lVar1) == cVar2)) &&
           (uVar4 = 0, (*(uint *)(lVar6 + 0x28 + lVar1) >> 4 & 0xf) + 1 == uVar10)) {
          *(undefined1 *)(uVar9 + param_3) = 1;
          uVar11 = (((uint)uVar9 & 0xff) << 8 ^ *(uint *)(lVar8 + 0x28)) & 0xf00;
          uVar4 = (ulonglong)uVar11;
          *(uint *)(lVar8 + 0x28) = *(uint *)(lVar8 + 0x28) ^ uVar11;
          lVar8 = uVar9 * 0xb8 + lVar1;
          if (uVar10 == uVar12) {
            *(uint *)(lVar8 + 0x28) = *(uint *)(lVar8 + 0x28) | 0xf00;
          }
          break;
        }
        uVar11 = (uint)uVar9 + 1;
        uVar9 = (ulonglong)uVar11;
      } while (uVar11 < 8);
      uVar10 = uVar10 + 1;
    } while (uVar10 <= uVar12);
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== DispatchDynamicUserCmd @ 0002cf78 =====

undefined8
DispatchDynamicUserCmd(longlong param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  uint uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  
  uVar2 = (undefined1)param_2;
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
  if ((*(uint *)(param_2 + 0xb0) & 1) == 0) {
    return 0;
  }
  uVar1 = *(uint *)(param_2 + 0xb0) & 0xfffffffe;
  *(uint *)(param_2 + 0xb0) = uVar1;
  if (uVar1 == 2) {
    DbgPrint("Will call NotifyBusChanged\n");
    NotifyBusChanged(param_1,CONCAT71(uVar3,uVar2),param_3,param_4);
  }
  else {
    if (uVar1 != 4) {
      *(undefined1 *)(param_2 + 0x4b) = 1;
      return 0;
    }
    DbgPrint("Will call CheckController\n");
    CheckController(param_1,'\x01',param_3);
    **(undefined1 **)(param_2 + 0x60) = *(undefined1 *)(param_1 + 0x14c3);
  }
  *(undefined1 *)(param_2 + 0x4b) = 1;
  return 1;
}



===== HideParentLogicTarget @ 0002d00c =====

ulonglong HideParentLogicTarget(longlong param_1,byte param_2,undefined1 param_3)

{
  char *pcVar1;
  ulonglong in_RAX;
  byte bVar2;
  
  if (param_2 < 8) {
    bVar2 = 0;
    do {
      in_RAX = (ulonglong)bVar2;
      pcVar1 = (char *)(param_1 + (in_RAX * 5 + 299) * 8);
      if ((*pcVar1 != -1) &&
         (in_RAX = CheckDeviceCheckSum((longlong)pcVar1,
                                       (int *)(param_1 + 0x388 + (ulonglong)param_2 * 0xb8)),
         (char)in_RAX != '\0')) {
        if (bVar2 < 8) {
          *(undefined1 *)((ulonglong)bVar2 + 0x3cec + param_1) = param_3;
          return CONCAT71((int7)(in_RAX >> 8),1);
        }
        break;
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < 8);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== ReNotifyBusChanged @ 0002d0a0 =====

void ReNotifyBusChanged(longlong param_1)

{
  char *pcVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  pcVar1 = (char *)(param_1 + 0x3cf4);
  lVar3 = 8;
  do {
    if (*pcVar1 != '\0') {
      *pcVar1 = '\0';
    }
    pcVar1 = pcVar1 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  StorPortNotification(7,param_1,*(undefined1 *)(param_1 + 0x214));
  uVar2 = HasLogicDevice(param_1);
  *(char *)(param_1 + 0x14b7) = (char)uVar2;
  if (((char)uVar2 == '\0') &&
     (*(undefined1 *)(param_1 + 0x14b5) = 0, *(char *)(param_1 + 0x14b8) == '\0')) {
    *(undefined1 *)(param_1 + 0x14b6) = 0;
  }
  if (*(char *)(param_1 + 0x14b6) == '\0') {
    StorPortNotification(6,param_1,AtapiScsiTimer,1000000,0xffffffff);
  }
  return;
}



===== NotifyBusChanged @ 0002d130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NotifyBusChanged(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  bool bVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  char *pcVar10;
  char *pcVar11;
  int *_Src;
  byte *pbVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  code *pcVar15;
  uint uVar16;
  longlong lVar17;
  longlong lVar18;
  int *piVar19;
  undefined1 *puVar20;
  int *piVar21;
  undefined1 auStack_1b8 [32];
  undefined4 local_198;
  char local_188 [320];
  byte local_48 [8];
  undefined8 local_40;
  ulonglong local_38;
  char local_30 [8];
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1b8;
  piVar19 = (int *)(param_1 + 0x388);
  _Src = (int *)(param_1 + 0x958);
  uVar14 = 0x140;
  memcpy(local_188,_Src,0x140);
  local_48[0] = 0xff;
  local_48[1] = 0xff;
  local_48[2] = 0xff;
  local_48[3] = 0xff;
  local_48[4] = 0xff;
  local_48[5] = 0xff;
  local_48[6] = 0xff;
  local_48[7] = 0xff;
  local_40 = 0xffffffffffffffff;
  pbVar12 = local_48;
  lVar17 = 8;
  piVar21 = piVar19;
  do {
    if (pbVar12[(param_1 - (longlong)local_48) + 0x34cc] != 0) {
      uVar9 = 0;
      do {
        pcVar10 = (char *)(param_1 + (uVar9 * 5 + 299) * 8);
        if ((*pcVar10 != -1) &&
           (_Src = piVar21, uVar8 = CheckDeviceCheckSum((longlong)pcVar10,piVar21),
           (char)uVar8 != '\0')) {
          *pbVar12 = (byte)uVar9;
          break;
        }
        uVar16 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar16;
      } while (uVar16 < 8);
    }
    piVar21 = piVar21 + 0x2e;
    pbVar12 = pbVar12 + 1;
    lVar17 = lVar17 + -1;
  } while (lVar17 != 0);
  BuildDeviceParameter(param_1,_Src,uVar14,param_4);
  puVar13 = &local_40;
  lVar17 = 8;
  do {
    if (*(char *)((param_1 - (longlong)&local_40) + 0x34cc + (longlong)puVar13) != '\0') {
      uVar9 = 0;
      do {
        pcVar10 = (char *)(param_1 + (uVar9 * 5 + 299) * 8);
        if ((*pcVar10 != -1) &&
           (uVar8 = CheckDeviceCheckSum((longlong)pcVar10,piVar19), (char)uVar8 != '\0')) {
          *(char *)puVar13 = (char)uVar9;
          break;
        }
        uVar16 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar16;
      } while (uVar16 < 8);
    }
    piVar19 = piVar19 + 0x2e;
    puVar13 = (undefined8 *)((longlong)puVar13 + 1);
    lVar17 = lVar17 + -1;
    if (lVar17 == 0) {
      lVar18 = 8;
      lVar17 = 0;
      do {
        if (auStack_1b8[(param_1 - (longlong)&local_40) + lVar17 + 0x3644] != '\0') {
          bVar1 = local_48[lVar17];
          bVar2 = local_48[lVar17 + 8];
          if ((((bVar1 == 0xff) || (*(char *)((ulonglong)bVar1 + 0x34d4 + param_1) == '\0')) &&
              (bVar2 != 0xff)) && (bVar1 != 0xff)) {
            if (bVar2 != bVar1) {
              uVar9 = (ulonglong)bVar1;
              uVar8 = (ulonglong)bVar2;
              uVar14 = *(undefined8 *)(param_1 + 0x958 + uVar9 * 0x28);
              uVar3 = *(undefined8 *)(param_1 + 0x960 + uVar9 * 0x28);
              uVar4 = *(undefined8 *)(param_1 + 0x968 + uVar9 * 0x28);
              uVar5 = *(undefined8 *)(param_1 + 0x970 + uVar9 * 0x28);
              uVar6 = *(undefined8 *)(param_1 + 0x978 + uVar9 * 0x28);
              *(undefined8 *)(param_1 + 0x958 + uVar9 * 0x28) =
                   *(undefined8 *)(param_1 + 0x958 + uVar8 * 0x28);
              *(undefined8 *)(param_1 + 0x960 + uVar9 * 0x28) =
                   *(undefined8 *)(param_1 + 0x960 + uVar8 * 0x28);
              *(undefined8 *)(param_1 + 0x968 + uVar9 * 0x28) =
                   *(undefined8 *)(param_1 + 0x968 + uVar8 * 0x28);
              *(undefined8 *)(param_1 + 0x970 + uVar9 * 0x28) =
                   *(undefined8 *)(param_1 + 0x970 + uVar8 * 0x28);
              *(undefined8 *)(param_1 + 0x978 + uVar9 * 0x28) =
                   *(undefined8 *)(param_1 + 0x978 + uVar8 * 0x28);
              *(undefined8 *)(param_1 + 0x958 + uVar8 * 0x28) = uVar14;
              *(undefined8 *)(param_1 + 0x960 + uVar8 * 0x28) = uVar3;
              *(undefined8 *)(param_1 + 0x968 + uVar8 * 0x28) = uVar4;
              *(undefined8 *)(param_1 + 0x970 + uVar8 * 0x28) = uVar5;
              *(undefined8 *)(param_1 + 0x978 + uVar8 * 0x28) = uVar6;
            }
            *(undefined1 *)((ulonglong)bVar1 + 0x34d4 + param_1) = 1;
          }
        }
        lVar17 = lVar17 + 1;
        lVar18 = lVar18 + -1;
      } while (lVar18 != 0);
      puVar20 = (undefined1 *)(param_1 + 0x3ce4);
      *(undefined8 *)(param_1 + 0x34cc) = 0;
      uVar16 = 0;
      do {
        HideParentLogicTarget(param_1,(byte)uVar16,*puVar20);
        uVar16 = uVar16 + 1;
        puVar20 = puVar20 + 1;
      } while (uVar16 < 8);
      bVar7 = false;
      pcVar10 = (char *)(param_1 + 0x3cec);
      pcVar11 = local_188;
      lVar17 = 8;
      do {
        lVar18 = lVar17;
        if (((*pcVar11 != -1) && (pcVar11[(param_1 - (longlong)local_188) + 0x958] != -1)) &&
           ((pcVar10[-0x818] == '\0' && (*pcVar10 == '\0')))) {
          pcVar10[8] = '\x01';
          bVar7 = true;
        }
        pcVar11 = pcVar11 + 0x28;
        pcVar10 = pcVar10 + 1;
        lVar17 = lVar18 + -1;
      } while (lVar17 != 0);
      StorPortNotification((int)lVar18 + 6,param_1,*(undefined1 *)(param_1 + 0x214));
      if (bVar7) {
        uVar14 = 2000000;
        pcVar15 = ReNotifyBusChanged;
      }
      else {
        uVar14 = HasLogicDevice(param_1);
        *(char *)(param_1 + 0x14b7) = (char)uVar14;
        if (((char)uVar14 == '\0') &&
           (*(undefined1 *)(param_1 + 0x14b5) = 0, *(char *)(param_1 + 0x14b8) == '\0')) {
          *(undefined1 *)(param_1 + 0x14b6) = 0;
        }
        if (*(char *)(param_1 + 0x14b6) != '\0') {
          return;
        }
        uVar14 = 1000000;
        pcVar15 = AtapiScsiTimer;
      }
      local_198 = 0xffffffff;
      StorPortNotification(6,param_1,pcVar15,uVar14);
      return;
    }
  } while( true );
}



===== ParseDynamicUserCmd @ 0002d498 =====

ulonglong ParseDynamicUserCmd(longlong param_1,longlong param_2,undefined8 *param_3)

{
  char cVar1;
  undefined1 *puVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint7 uVar6;
  void *pvVar5;
  byte bVar7;
  undefined1 uVar8;
  char *pcVar9;
  char *pcVar10;
  undefined8 uVar11;
  byte *pbVar12;
  int *piVar13;
  bool bVar14;
  undefined1 uStack0000000000000000;
  
  bVar7 = *(byte *)((longlong)param_3 + 0x4b);
  uVar6 = (uint7)((ulonglong)&uStack0000000000000000 >> 8);
  if (bVar7 < 0x18) {
    if (bVar7 != 0x17) {
      if (bVar7 == 0x12) {
        pvVar5 = StorAllocateSubCmd(param_1,param_2);
        if (pvVar5 == (void *)0x0) {
LAB_0002d6cd:
          *(undefined4 *)(param_2 + 0xfc) = 2;
          *(undefined1 *)(param_2 + 0x100) = 2;
          return 4;
        }
        if ((undefined8 *)((longlong)pvVar5 + 0x48) != param_3) {
          *(undefined8 *)((longlong)pvVar5 + 0x48) = *param_3;
          *(undefined8 *)((longlong)pvVar5 + 0x50) = param_3[1];
          *(undefined8 *)((longlong)pvVar5 + 0x58) = param_3[2];
          *(undefined8 *)((longlong)pvVar5 + 0x60) = param_3[3];
          *(undefined8 *)((longlong)pvVar5 + 0x68) = param_3[4];
          *(undefined8 *)((longlong)pvVar5 + 0x70) = param_3[5];
          *(undefined8 *)((longlong)pvVar5 + 0x78) = param_3[6];
          *(undefined8 *)((longlong)pvVar5 + 0x80) = param_3[7];
          *(undefined8 *)((longlong)pvVar5 + 0x88) = param_3[8];
          *(undefined8 *)((longlong)pvVar5 + 0x90) = param_3[9];
          *(undefined8 *)((longlong)pvVar5 + 0x98) = param_3[10];
        }
        *(longlong *)((longlong)pvVar5 + 0x10) = param_2;
        uVar4 = *(undefined4 *)(param_2 + 0x104);
        *(uint *)((longlong)pvVar5 + 0xb0) = *(uint *)((longlong)pvVar5 + 0xb0) | 3;
      }
      else {
        if (bVar7 == 0x13) {
          bVar14 = *(char *)((longlong)param_3 + 0x4c) != '\0';
          register0x00000020 = (BADSPACEBASE *)CONCAT71(uVar6,bVar14);
          *(bool *)(param_1 + 0x14b5) = bVar14;
LAB_0002d6b2:
          uVar11 = 1;
          goto LAB_0002d8a1;
        }
        if (bVar7 != 0x14) {
          if (bVar7 == 0x15) {
            puVar2 = (undefined1 *)param_3[3];
            uVar11 = 1;
            *puVar2 = (char)*(undefined4 *)(param_1 + 0x98);
            cVar1 = *(char *)(param_1 + 0x14b7);
            puVar2[2] = 1;
            puVar2[1] = cVar1 != '\0';
            bVar14 = *(int *)(param_1 + 0x208) == 0x33491106;
            *(undefined2 *)(puVar2 + 3) = 2;
            register0x00000020 = (BADSPACEBASE *)CONCAT71(uVar6,bVar14);
            *(uint *)(puVar2 + 8) = *(uint *)(puVar2 + 8) | 1;
            puVar2[5] = 0;
            puVar2[6] = bVar14;
          }
          else {
            if (bVar7 != 0x16) goto LAB_0002d793;
            bVar7 = *(byte *)((longlong)param_3 + 0x4c);
            uVar11 = 1;
            if (7 < bVar7) goto LAB_0002d50b;
            cVar1 = *(char *)param_3[3];
            if (cVar1 == '\0') {
              register0x00000020 = (BADSPACEBASE *)(ulonglong)bVar7;
              *(char *)((longlong)register0x00000020 + param_1 + 0x34c4) = '\x01';
            }
            else if (cVar1 == '\x01') {
              register0x00000020 = (BADSPACEBASE *)(ulonglong)bVar7;
              *(char *)((longlong)register0x00000020 + param_1 + 0x34c4) = '\0';
            }
            else if (cVar1 == '\x02') {
              register0x00000020 = (BADSPACEBASE *)0x0;
              *(char *)param_3[3] = *(char *)((ulonglong)bVar7 + 0x34c4 + param_1) != '\0';
            }
          }
          goto LAB_0002d8a1;
        }
        *(undefined1 *)(param_1 + 0x14c3) = 0x80;
        pvVar5 = StorAllocateSubCmd(param_1,param_2);
        if (pvVar5 == (void *)0x0) goto LAB_0002d6cd;
        if ((undefined8 *)((longlong)pvVar5 + 0x48) != param_3) {
          *(undefined8 *)((longlong)pvVar5 + 0x48) = *param_3;
          *(undefined8 *)((longlong)pvVar5 + 0x50) = param_3[1];
          *(undefined8 *)((longlong)pvVar5 + 0x58) = param_3[2];
          *(undefined8 *)((longlong)pvVar5 + 0x60) = param_3[3];
          *(undefined8 *)((longlong)pvVar5 + 0x68) = param_3[4];
          *(undefined8 *)((longlong)pvVar5 + 0x70) = param_3[5];
          *(undefined8 *)((longlong)pvVar5 + 0x78) = param_3[6];
          *(undefined8 *)((longlong)pvVar5 + 0x80) = param_3[7];
          *(undefined8 *)((longlong)pvVar5 + 0x88) = param_3[8];
          *(undefined8 *)((longlong)pvVar5 + 0x90) = param_3[9];
          *(undefined8 *)((longlong)pvVar5 + 0x98) = param_3[10];
        }
        *(longlong *)((longlong)pvVar5 + 0x10) = param_2;
        uVar4 = *(undefined4 *)(param_2 + 0x104);
        *(uint *)((longlong)pvVar5 + 0xb0) = *(uint *)((longlong)pvVar5 + 0xb0) | 5;
      }
      *(undefined4 *)((longlong)pvVar5 + 0xa0) = uVar4;
      uVar11 = 1;
      *(code **)((longlong)pvVar5 + 0x18) = DispatchDynamicUserCmd;
      if (*(int *)(param_2 + 0xea4) != 0) {
        lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
        *(void **)(lVar3 + 0x78 + (ulonglong)*(byte *)(lVar3 + 0x278) * 8) = pvVar5;
        *(char *)(lVar3 + 0x278) = *(char *)(lVar3 + 0x278) + '\x01';
      }
      register0x00000020 = (BADSPACEBASE *)(longlong)*(int *)(param_2 + 0x104);
      *(undefined4 *)(param_2 + 0x10c + (longlong)register0x00000020 * 4) = 1;
      *(int *)(param_2 + 0x104) = *(int *)(param_2 + 0x104) + 1;
      *(undefined4 *)(param_2 + 0x108) = 0;
      *(undefined4 *)(param_2 + 0xf8) = 0;
      *(undefined4 *)(param_2 + 0xfc) = 0;
      goto LAB_0002d8af;
    }
    if (7 < *(byte *)((longlong)param_3 + 0x4c)) goto LAB_0002d50b;
    register0x00000020 = (BADSPACEBASE *)param_3[3];
LAB_0002d76e:
    uVar11 = 1;
    *(char *)register0x00000020 = '\x01';
LAB_0002d8a1:
    *(int *)(param_2 + 0xf8) = (int)uVar11;
  }
  else {
    if (bVar7 != 0x18) {
      if (bVar7 == 0x19) {
        bVar7 = *(byte *)((longlong)param_3 + 0x4c);
        register0x00000020 = (BADSPACEBASE *)CONCAT71(uVar6,bVar7);
        uVar11 = 1;
        if (7 < bVar7) goto LAB_0002d50b;
        register0x00000020 = (BADSPACEBASE *)param_3[3];
        if ((*(byte *)(param_1 + 0xab8 + (ulonglong)bVar7 * 2) & 1) != 0) goto LAB_0002d76e;
        *(char *)register0x00000020 = '\0';
        goto LAB_0002d8a1;
      }
      if (bVar7 != 0x1a) {
        if (bVar7 != 0x1b) {
LAB_0002d793:
          return (ulonglong)uVar6 << 8;
        }
        goto LAB_0002d6b2;
      }
      puVar2 = (undefined1 *)param_3[3];
      if (*(char *)((longlong)param_3 + 0x4c) == '\0') {
        register0x00000020 = *(BADSPACEBASE **)(param_2 + 0xf0);
        bVar7 = *(byte *)((longlong)register0x00000020 + 6);
      }
      else {
        bVar7 = *(byte *)((longlong)param_3 + 0x4d);
      }
      piVar13 = (int *)(param_1 + 0x388);
      uVar11 = 1;
      if (bVar7 < 8) {
        register0x00000020 = (BADSPACEBASE *)(ulonglong)bVar7;
        lVar3 = param_1 + (longlong)register0x00000020 * 0x28;
        if (7 < *(byte *)(lVar3 + 0x958)) goto LAB_0002d824;
        bVar7 = 0;
        pbVar12 = (byte *)(param_1 + 0xab8);
        pcVar9 = (char *)0x0;
        do {
          register0x00000020 =
               (BADSPACEBASE *)CONCAT71((int7)((ulonglong)register0x00000020 >> 8),*pbVar12);
          pcVar10 = pcVar9;
          if ((((byte)uVar11 & *pbVar12) != 0) &&
             (register0x00000020 = (BADSPACEBASE *)CheckDeviceCheckSum(lVar3 + 0x958,piVar13),
             (char)register0x00000020 != '\0')) {
            pcVar10 = (char *)(ulonglong)(byte)((char)pcVar9 + (char)uVar11);
            (pcVar9 + 1)[(longlong)puVar2] = bVar7;
            register0x00000020 = (BADSPACEBASE *)pcVar9;
          }
          uVar8 = SUB81(pcVar10,0);
          bVar7 = bVar7 + (char)uVar11;
          pbVar12 = pbVar12 + 2;
          piVar13 = piVar13 + 0x2e;
          pcVar9 = pcVar10;
        } while (bVar7 < 8);
      }
      else {
LAB_0002d824:
        uVar8 = 0;
      }
      *puVar2 = uVar8;
      goto LAB_0002d8a1;
    }
    bVar7 = *(byte *)((longlong)param_3 + 0x4c);
    uVar11 = 1;
    if (bVar7 < 8) {
      register0x00000020 = (BADSPACEBASE *)param_3[3];
      cVar1 = *(char *)register0x00000020;
      if (cVar1 != '\0') {
        if (cVar1 != '\x01') {
          if (cVar1 == '\x02') {
            register0x00000020 = (BADSPACEBASE *)(ulonglong)bVar7;
            *(char *)((longlong)register0x00000020 + param_1 + 0x3ce4) = '\x01';
          }
          goto LAB_0002d8a1;
        }
        *(undefined1 *)((ulonglong)bVar7 + 0x34cc + param_1) = 1;
      }
      register0x00000020 = (BADSPACEBASE *)(ulonglong)bVar7;
      *(char *)((longlong)register0x00000020 + param_1 + 0x3ce4) = '\0';
      goto LAB_0002d8a1;
    }
LAB_0002d50b:
    uVar11 = 1;
    *(undefined4 *)(param_2 + 0xf8) = 6;
  }
  *(int *)(param_2 + 0xfc) = (int)uVar11;
LAB_0002d8af:
  return CONCAT71((int7)((ulonglong)register0x00000020 >> 8),(char)uVar11);
}



===== VerifyCompleteCallback @ 0002d8d4 =====

undefined4 VerifyCompleteCallback(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x200);
  iVar2 = memcmp(*(void **)(param_1 + 0x4180),*(void **)(param_1 + 0x4188),
                 (ulonglong)(uint)(*(int *)(lVar1 + 8) << 9));
  *(uint *)(lVar1 + 0x14) = (uint)(iVar2 == 0);
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}



===== Raid0MigrateMemCpyCallback @ 0002d910 =====

undefined8 Raid0MigrateMemCpyCallback(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  void *_Src;
  uint uVar7;
  longlong lVar8;
  void *pvVar9;
  
  pvVar4 = (void *)(ulonglong)*(byte *)(param_2 + 0x200);
  _Src = *(void **)(param_1 + 0x41d0);
  uVar5 = *(uint *)(param_2 + 0x208);
  uVar1 = *(uint *)((longlong)pvVar4 * 0xb8 + 0x3b0 + param_1);
  uVar7 = uVar1 >> 0x16;
  if (_Src == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar6 = 0;
    lVar8 = *(longlong *)(param_1 + 0x41d8 + (longlong)pvVar4 * 8);
    pvVar9 = pvVar4;
    while (lVar8 != 0) {
      uVar2 = (uVar6 / (uVar1 & 0xf)) * uVar7 * 0x200;
      pvVar4 = (void *)(ulonglong)uVar2;
      if (uVar5 <= uVar7) {
        pvVar9 = (void *)(lVar8 + (ulonglong)uVar2);
        if (pvVar9 != _Src) {
          pvVar4 = memcpy(pvVar9,_Src,(ulonglong)(uVar5 << 9));
        }
        break;
      }
      if ((void *)(lVar8 + (longlong)pvVar4) != _Src) {
        memcpy((void *)(lVar8 + (longlong)pvVar4),_Src,(ulonglong)(uVar7 << 9));
      }
      uVar5 = uVar5 - uVar7;
      _Src = (void *)((longlong)_Src + (ulonglong)(uVar7 << 9));
      pvVar4 = (void *)((longlong)pvVar9 * 0xb8);
      uVar2 = *(uint *)((longlong)pvVar4 + param_1 + 0x3b0) >> 8 & 0xf;
      uVar6 = uVar6 + 1;
      pvVar9 = (void *)(ulonglong)uVar2;
      lVar8 = *(longlong *)(param_1 + 0x41d8 + (ulonglong)uVar2 * 8);
    }
    uVar3 = CONCAT71((int7)((ulonglong)pvVar4 >> 8),1);
  }
  return uVar3;
}



===== Raid5MigrateXorCallback @ 0002da18 =====

undefined8 Raid5MigrateXorCallback(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  uVar1 = *(uint *)(param_2 + 0x220);
  lVar5 = 0;
  lVar2 = *(longlong *)(param_1 + 0x41d8 + (ulonglong)uVar1 * 8);
  uVar4 = (ulonglong)uVar1 * 0xb8;
  uVar6 = *(uint *)(param_2 + 0x208) & 0x7fffff;
  if (uVar6 != 0) {
    uVar8 = (ulonglong)(*(uint *)(uVar4 + 0x3b0 + param_1) >> 0xe & 0xf);
    uVar7 = (ulonglong)(uVar6 << 7);
    do {
      uVar6 = *(uint *)(lVar5 + *(longlong *)(param_1 + 0x41d8 + uVar8 * 8));
      uVar3 = *(uint *)(uVar8 * 0xb8 + 0x3b0 + param_1);
      while (uVar3 = uVar3 >> 0xe & 0xf, uVar4 = (ulonglong)uVar3, uVar3 != uVar1) {
        uVar6 = uVar6 ^ *(uint *)(*(longlong *)(param_1 + 0x41d8 + uVar4 * 8) + lVar5);
        uVar3 = *(uint *)(uVar4 * 0xb8 + 0x3b0 + param_1);
      }
      *(uint *)(lVar5 + lVar2) = uVar6;
      lVar5 = lVar5 + 4;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== Raid5VerifyCalcParityCallback @ 0002db40 =====

undefined8 Raid5VerifyCalcParityCallback(longlong param_1,longlong param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  byte bVar8;
  ulonglong uVar9;
  uint uVar10;
  
  uVar9 = (ulonglong)*(byte *)(param_2 + 0x200);
  puVar1 = *(undefined1 **)(param_2 + 0x220);
  uVar10 = *(int *)(param_2 + 0x208) << 9;
  uVar6 = 0;
  uVar2 = *(uint *)(uVar9 * 0xb8 + 0x3b0 + param_1) & 0xf;
  lVar4 = 0;
  *puVar1 = 1;
  if (uVar10 != 0) {
    do {
      bVar8 = 0;
      uVar3 = uVar9;
      if (uVar2 != 0) {
        uVar7 = (ulonglong)uVar2;
        do {
          bVar8 = bVar8 ^ *(byte *)(*(longlong *)(param_1 + 0x41d8 + uVar3 * 8) + uVar6);
          uVar3 = (ulonglong)(*(uint *)(uVar3 * 0xb8 + 0x3b0 + param_1) >> 0xe & 0xf);
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      lVar4 = *(longlong *)(param_1 + 0x41d8 + uVar3 * 8);
      if (*(byte *)(uVar6 + lVar4) != bVar8) {
        *puVar1 = 0;
        break;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < uVar10);
  }
  return CONCAT71((int7)((ulonglong)lVar4 >> 8),1);
}



===== Raid5SyncCalcParityCallback @ 0002dbfc =====

undefined8 Raid5SyncCalcParityCallback(longlong param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  byte bVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  ulonglong uVar13;
  uint uVar14;
  ulonglong uVar15;
  
  uVar3 = *(undefined4 *)(param_2 + 0x210);
  uVar4 = *(uint *)(param_2 + 0x208);
  uVar5 = *(undefined4 *)(param_2 + 0x218);
  bVar1 = *(byte *)(param_2 + 0x220);
  bVar2 = *(byte *)(param_2 + 0x200);
  lVar6 = *(longlong *)(param_1 + 0x41d8 + (ulonglong)bVar1 * 8);
  uVar10 = *(uint *)((ulonglong)bVar2 * 0xb8 + 0x3b0 + param_1) & 0xf;
  uVar14 = uVar4 & 0x7fffff;
  uVar7 = uVar14 << 7;
  uVar8 = (ulonglong)uVar7;
  if (uVar14 != 0) {
    lVar12 = 0;
    uVar15 = (ulonglong)uVar7;
    do {
      uVar14 = 0;
      if (uVar10 != 0) {
        uVar11 = (ulonglong)bVar2;
        uVar13 = (ulonglong)uVar10;
        do {
          bVar9 = (byte)uVar11;
          if (bVar9 == bVar1) {
            bVar9 = (byte)(*(uint *)(uVar11 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf;
          }
          uVar14 = uVar14 ^ *(uint *)(*(longlong *)(param_1 + 0x41d8 + (ulonglong)bVar9 * 8) +
                                     lVar12);
          uVar8 = (ulonglong)bVar9 * 0xb8;
          uVar11 = (ulonglong)((byte)(*(uint *)(uVar8 + 0x3b0 + param_1) >> 0xe) & 0xf);
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      *(uint *)(lVar12 + lVar6) = uVar14;
      lVar12 = lVar12 + 4;
      uVar15 = uVar15 - 1;
    } while (uVar15 != 0);
  }
  *(uint *)(param_1 + 0x41b8) = uVar4;
  *(ulonglong *)(param_1 + 0x41b0) = CONCAT44(uVar5,uVar3);
  return CONCAT71((int7)(uVar8 >> 8),1);
}



===== ConstructNormalSrbByUserSrb @ 0002dd60 =====

void ConstructNormalSrbByUserSrb
               (longlong param_1,longlong param_2,undefined8 *param_3,undefined8 *param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  ulonglong uVar7;
  longlong lVar8;
  
  bVar1 = *(byte *)((longlong)param_4 + 0x4d);
  lVar8 = (ulonglong)bVar1 * 0xd4;
  if (param_3 != param_4) {
    *param_3 = *param_4;
    param_3[1] = param_4[1];
    param_3[2] = param_4[2];
    param_3[3] = param_4[3];
    param_3[4] = param_4[4];
    param_3[5] = param_4[5];
    param_3[6] = param_4[6];
    param_3[7] = param_4[7];
    param_3[8] = param_4[8];
    param_3[9] = param_4[9];
    param_3[10] = param_4[10];
  }
  *(undefined1 *)((longlong)param_3 + 6) = *(undefined1 *)((longlong)param_4 + 0x4d);
  if ((*(uint *)((ulonglong)bVar1 * 0xb8 + 0x39c + param_1) & 0x10) == 0) {
    uVar7 = (ulonglong)
            ((uint)*(ushort *)(lVar8 + 0xd20 + param_1) * (uint)*(ushort *)(lVar8 + 0xd1a + param_1)
             * (uint)*(ushort *)(lVar8 + 0xd16 + param_1) - 2);
  }
  else {
    iVar2 = *(int *)(lVar8 + 0xddc + param_1);
    uVar3 = *(undefined4 *)(lVar8 + 0xd8c + param_1);
    if (iVar2 != 0) {
      *(undefined4 *)(param_2 + 0xe98) = 1;
      *(undefined1 *)((longlong)param_3 + 10) = 0x10;
    }
    uVar7 = CONCAT44(iVar2,uVar3) - 1;
  }
  uVar4 = (undefined1)(uVar7 >> 8);
  uVar5 = (undefined1)(uVar7 >> 0x10);
  uVar6 = (undefined1)(uVar7 >> 0x18);
  if (*(int *)(param_2 + 0xe98) == 0) {
    *(undefined1 *)((longlong)param_3 + 0x4c) = uVar4;
    *(char *)((longlong)param_3 + 0x4d) = (char)uVar7;
  }
  else {
    *(undefined1 *)(param_3 + 10) = uVar4;
    *(char *)((longlong)param_3 + 0x51) = (char)uVar7;
    *(undefined1 *)((longlong)param_3 + 0x4f) = uVar5;
    *(undefined1 *)((longlong)param_3 + 0x4e) = uVar6;
    *(char *)((longlong)param_3 + 0x4d) = (char)(uVar7 >> 0x20);
    *(char *)((longlong)param_3 + 0x4c) = (char)(uVar7 >> 0x28);
    uVar5 = (undefined1)(uVar7 >> 0x30);
    uVar6 = (undefined1)(uVar7 >> 0x38);
  }
  *(undefined1 *)((longlong)param_3 + 0x4a) = uVar6;
  *(undefined1 *)((longlong)param_3 + 0x4b) = uVar5;
  *(undefined4 *)((longlong)param_3 + 0xc) = 0x80;
  return;
}



===== UserCmdCallBack @ 0002dec0 =====

undefined8
UserCmdCallBack(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  
  uVar1 = BuildDeviceParameter(param_1,param_2,param_3,param_4);
  return CONCAT71((int7)(uVar1 >> 8),1);
}



===== ParseUserSyncVerify @ 0002ded0 =====

void ParseUserSyncVerify(longlong param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  byte bVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  undefined8 uVar7;
  longlong lVar8;
  byte bVar9;
  ulonglong *puVar10;
  longlong lVar11;
  int iVar12;
  byte bVar13;
  ulonglong uVar14;
  undefined2 local_res20;
  
  plVar3 = *(longlong **)(param_3 + 0x18);
  lVar8 = *(longlong *)(param_3 + 0x38);
  bVar1 = *(byte *)((longlong)plVar3 + 0x13);
  lVar4 = *plVar3;
  iVar12 = (int)plVar3[1] << 9;
  bVar2 = *(byte *)((longlong)plVar3 + 0x11);
  local_res20 = 0;
  if (*(char *)(param_3 + 0x48) == -1) {
    cVar6 = *(char *)(param_3 + 0x4b);
    uVar7 = CONCAT71((int7)((ulonglong)param_2 >> 8),cVar6);
    if ((((byte)(cVar6 - 10U) < 2) && ((*(byte *)(param_1 + 0xab8 + (ulonglong)bVar2 * 2) & 1) != 0)
        ) && ((*(byte *)(param_1 + 0xab8 + (ulonglong)bVar1 * 2) & 1) != 0)) {
      lVar11 = 2;
      if (lVar4 != -1) {
        if (cVar6 == '\n') {
          bVar9 = 2;
        }
        else {
          bVar9 = 0;
          if (cVar6 == '\v') {
            bVar9 = 1;
          }
        }
        uVar14 = 0;
        if (bVar9 != 0) {
          do {
            if (*(longlong *)(param_1 + 0x4180 + uVar14 * 8) == 0) {
              lVar11 = ViaAllocatePool(param_1,uVar7,0x20000);
              *(longlong *)(param_1 + 0x4180 + uVar14 * 8) = lVar11;
              if (lVar11 == 0) goto LAB_0002e194;
            }
            bVar13 = (char)uVar14 + 1;
            uVar14 = (ulonglong)bVar13;
          } while (bVar13 < bVar9);
        }
        if ((*(byte *)(lVar8 + 0x279) + 2 < 0x29) &&
           (cVar6 = StorAllocateMultiPool(lVar8,2,(longlong)&local_res20), cVar6 != '\0')) {
          lVar11 = (ulonglong)(byte)local_res20 * 0xc0 + *(longlong *)(lVar8 + 0x50);
          lVar8 = (ulonglong)local_res20._1_1_ * 0xc0 + *(longlong *)(lVar8 + 0x50);
          if ((*(char *)(param_3 + 0x4b) != '\v') && (*(int *)(param_2 + 0xe0) < 0x10)) {
            *(longlong *)(param_2 + 0x50 + (longlong)*(int *)(param_2 + 0xe0) * 8) =
                 param_1 + 0x4188;
            *(undefined1 *)((longlong)*(int *)(param_2 + 0xe0) + 0xd0 + param_2) = 0;
            *(int *)(param_2 + 0xe0) = *(int *)(param_2 + 0xe0) + 1;
          }
          if (*(int *)(param_2 + 0xe0) < 0x10) {
            *(longlong *)(param_2 + 0x50 + (longlong)*(int *)(param_2 + 0xe0) * 8) =
                 param_1 + 0x4180;
            *(undefined1 *)((longlong)*(int *)(param_2 + 0xe0) + 0xd0 + param_2) = 0;
            *(int *)(param_2 + 0xe0) = *(int *)(param_2 + 0xe0) + 1;
          }
          *(longlong *)(lVar11 + 0x10) = param_2;
          *(undefined4 *)(lVar11 + 0xa0) = 0;
          *(code **)(lVar11 + 0x18) = DispatchDiskReadWrite;
          *(undefined4 *)(lVar11 + 0x54) = 0x40;
          *(undefined1 *)(lVar11 + 0x90) = 0xff;
          *(byte *)(lVar11 + 0x4e) = bVar2;
          *(int *)(lVar11 + 0x58) = iVar12;
          uVar7 = *(undefined8 *)(param_1 + 0x4180);
          *(undefined4 *)(lVar11 + 0xa4) = 1;
          *(undefined8 *)(lVar11 + 0x30) = 0;
          *(longlong *)(lVar11 + 0x40) = lVar4;
          *(undefined8 *)(lVar11 + 0x60) = uVar7;
          *(undefined4 *)(lVar11 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
          if (*(int *)(param_2 + 0xea4) != 0) {
            lVar5 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
            *(longlong *)(lVar5 + 0x78 + (ulonglong)*(byte *)(lVar5 + 0x278) * 8) = lVar11;
            *(char *)(lVar5 + 0x278) = *(char *)(lVar5 + 0x278) + '\x01';
          }
          cVar6 = *(char *)(param_3 + 0x4b);
          *(longlong *)(lVar8 + 0x10) = param_2;
          *(code **)(lVar8 + 0x18) = DispatchDiskReadWrite;
          if (cVar6 == '\n') {
            *(undefined4 *)(lVar8 + 0xa0) = 0;
            *(undefined4 *)(lVar8 + 0x54) = 0x40;
            *(undefined1 *)(lVar8 + 0x90) = 0xff;
            *(byte *)(lVar8 + 0x4e) = bVar1;
            *(int *)(lVar8 + 0x58) = iVar12;
            uVar7 = *(undefined8 *)(param_1 + 0x4188);
          }
          else {
            *(undefined4 *)(lVar8 + 0xa0) = 1;
            *(undefined4 *)(lVar8 + 0x54) = 0x80;
            *(undefined1 *)(lVar8 + 0x90) = 0xff;
            *(byte *)(lVar8 + 0x4e) = bVar1;
            *(int *)(lVar8 + 0x58) = iVar12;
            uVar7 = *(undefined8 *)(param_1 + 0x4180);
          }
          *(undefined8 *)(lVar8 + 0x60) = uVar7;
          *(undefined4 *)(lVar8 + 0xa4) = 1;
          *(undefined8 *)(lVar8 + 0x30) = 0;
          *(longlong *)(lVar8 + 0x40) = lVar4;
          *(undefined4 *)(lVar8 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
          if (*(int *)(param_2 + 0xea4) != 0) {
            lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
            *(longlong *)(lVar4 + 0x78 + (ulonglong)*(byte *)(lVar4 + 0x278) * 8) = lVar8;
            *(char *)(lVar4 + 0x278) = *(char *)(lVar4 + 0x278) + '\x01';
          }
          if (*(char *)(param_3 + 0x4b) == '\n') {
            *(undefined8 *)(param_2 + 0x104) = 1;
            *(undefined4 *)(param_2 + 0x10c) = 2;
            *(code **)(param_2 + 0x160) = VerifyCompleteCallback;
            *(longlong **)(param_2 + 0x200) = plVar3;
          }
          else {
            *(undefined8 *)(param_2 + 0x104) = 2;
            *(undefined4 *)(param_2 + 0x10c) = 1;
            *(undefined4 *)(param_2 + 0x110) = 1;
            *(undefined8 *)(param_2 + 0x160) = 0;
          }
          *(undefined4 *)(param_2 + 0xfc) = 0;
          return;
        }
LAB_0002e194:
        *(undefined4 *)(param_2 + 0xfc) = 2;
        *(undefined1 *)(param_2 + 0x100) = 2;
        return;
      }
      puVar10 = (ulonglong *)(param_1 + 0x4180);
      do {
        if (*puVar10 != 0) {
          ViaFreePool(param_1,uVar7,*puVar10);
          *puVar10 = 0;
        }
        puVar10 = puVar10 + 1;
        lVar11 = lVar11 + -1;
      } while (lVar11 != 0);
      *(undefined4 *)(param_2 + 0xf8) = 1;
      goto LAB_0002e26a;
    }
  }
  *(undefined4 *)(param_2 + 0xf8) = 4;
LAB_0002e26a:
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return;
}



===== ParseRaid5Migration @ 0002e28c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ParseRaid5Migration(longlong param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong *plVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  longlong lVar13;
  byte bVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  byte bVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  undefined1 auStack_198 [32];
  uint local_178;
  uint local_174;
  uint local_170;
  uint local_16c;
  uint local_168;
  uint local_164;
  ulonglong local_160;
  ulonglong local_158;
  ulonglong local_150;
  longlong local_148 [16];
  longlong local_c8;
  undefined1 local_c0 [120];
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_198;
  local_c8 = 0;
  memset(local_c0,0,0x78);
  local_148[0] = 0;
  memset(local_148 + 1,0,0x78);
  bVar20 = *(byte *)(param_3 + 0x4d);
  uVar21 = (ulonglong)bVar20;
  bVar1 = *(byte *)(param_3 + 0x4e);
  uVar16 = *(uint *)(uVar21 * 0xb8 + 0x3b0 + param_1);
  lVar7 = *(longlong *)(param_3 + 0x38);
  local_178 = uVar16 & 0xf;
  local_48 = CONCAT44(*(undefined4 *)(uVar21 * 0xd4 + 0xddc + param_1),
                      *(undefined4 *)(uVar21 * 0xd4 + 0xd8c + param_1)) - 1;
  local_16c = local_178 + 1;
  uVar16 = ((uVar16 >> 0x12 & 0xf) + 1) * (uVar16 >> 0x16) * 4;
  uVar22 = (ulonglong)*(byte *)(param_3 + 0x53) * 0x100;
  local_168 = (uint)uVar22;
  local_174 = uVar16 * local_178;
  local_170 = 1;
  uVar18 = (ulonglong)
           CONCAT31(CONCAT21(CONCAT11(bVar1,*(undefined1 *)(param_3 + 0x4f)),
                             *(undefined1 *)(param_3 + 0x50)),*(undefined1 *)(param_3 + 0x51)) *
           0x100;
  if (*(int *)(uVar21 * 0xb8 + 0x3a8 + param_1) == 5) {
    if (local_168 < 0x20001) {
      uVar19 = (ulonglong)uVar16;
      local_158 = uVar18 % uVar19;
      uVar8 = (uVar22 + uVar18) - 1;
      uVar11 = uVar8 % uVar19;
      if (uVar8 / uVar19 <= uVar18 / uVar19) {
        if (uVar18 / uVar19 != 0) {
          if (local_48 < uVar22 + uVar18) {
            local_168 = (int)local_48 - (int)uVar18;
            uVar22 = (ulonglong)local_168;
          }
          local_150 = uVar21;
          if (0 < (int)(uint)uVar22) {
            uVar11 = (ulonglong)local_174;
            uVar8 = CONCAT71((int7)((uVar18 / uVar11) / (ulonglong)local_16c >> 8),bVar20);
            local_164 = (uint)uVar8;
            uVar16 = (local_16c - (int)((uVar18 / uVar11) % (ulonglong)local_16c)) - 1;
            if (uVar16 != 0) {
              uVar12 = (ulonglong)uVar16;
              do {
                uVar15 = *(uint *)((uVar8 & 0xff) * 0xb8 + 0x3b0 + param_1);
                uVar8 = (ulonglong)CONCAT31((uint3)(uVar15 >> 0x16),(char)(uVar15 >> 0xe)) &
                        0xffffffffffffff0f;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
              local_164 = (uint)uVar8;
            }
            local_160 = uVar18 / uVar11;
            uVar11 = (uVar18 % uVar11) / uVar19;
            uVar8 = uVar11;
            if (uVar16 <= uVar11) {
              uVar8 = uVar11 + 1;
            }
            local_174 = 0;
            bVar14 = bVar20;
            if (uVar8 != 0) {
              uVar16 = 0;
              do {
                uVar16 = uVar16 + 1;
                bVar14 = (byte)(*(uint *)((ulonglong)bVar14 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf;
              } while (uVar16 < uVar8);
            }
            if (uVar11 != local_178 - 1) {
              local_170 = (uint)(local_48 <= uVar22 + uVar19 + uVar18);
            }
            uVar8 = 0;
            local_178 = 0;
            bVar4 = bVar14;
            uVar16 = (uint)uVar22;
            uVar15 = local_170;
            uVar17 = local_16c;
            if (local_16c != 0) {
              do {
                if (((char)uVar15 == '\0') && (bVar4 != bVar14)) break;
                local_48 = (ulonglong)bVar4;
                plVar10 = (longlong *)(param_1 + 0x41d8 + local_48 * 8);
                if (*plVar10 == 0) {
                  lVar9 = ViaAllocatePool(param_1,uVar8,0x20000);
                  plVar10 = (longlong *)(param_1 + (local_48 + 0x83b) * 8);
                  *plVar10 = lVar9;
                  if (lVar9 == 0) goto LAB_0002ea9f;
                  uVar8 = (ulonglong)local_178;
                  uVar15 = local_170;
                  uVar17 = local_16c;
                }
                if (*(int *)(param_2 + 0xe0) < 0x10) {
                  *(longlong **)(param_2 + 0x50 + (longlong)*(int *)(param_2 + 0xe0) * 8) = plVar10;
                  *(undefined1 *)((longlong)*(int *)(param_2 + 0xe0) + 0xd0 + param_2) = 0;
                  *(int *)(param_2 + 0xe0) = *(int *)(param_2 + 0xe0) + 1;
                }
                local_178 = (int)uVar8 + 1;
                uVar8 = (ulonglong)local_178;
                bVar4 = (byte)(*(uint *)(local_48 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf;
              } while (local_178 < uVar17);
              uVar16 = local_168;
            }
            lVar9 = uVar19 * local_160;
            local_48 = local_48 & 0xffffffffffffff00;
            local_160 = CONCAT44(local_160._4_4_,uVar16 << 9);
            lVar9 = lVar9 + local_158;
            if ((*(byte *)(lVar7 + 0x279) + 1 < 0x29) &&
               (cVar5 = StorAllocateMultiPool(lVar7,1,(longlong)&local_48), cVar5 != '\0')) {
              local_178 = 1;
              local_c8 = (local_48 & 0xff) * 0xc0 + *(longlong *)(lVar7 + 0x50);
              *(code **)(local_c8 + 0x18) = DispatchDiskReadWrite;
              *(longlong *)(local_c8 + 0x10) = param_2;
              *(undefined4 *)(local_c8 + 0xa0) = 0;
              *(undefined4 *)(local_c8 + 0x54) = 0x40;
              *(undefined1 *)(local_c8 + 0x90) = 0xff;
              *(undefined4 *)(local_c8 + 0x58) = (undefined4)local_160;
              local_158 = (ulonglong)bVar14;
              *(byte *)(local_c8 + 0x4e) = bVar20;
              uVar2 = *(undefined8 *)(param_1 + 0x41d8 + local_158 * 8);
              *(undefined4 *)(local_c8 + 0xa4) = 1;
              *(undefined8 *)(local_c8 + 0x30) = 0;
              *(ulonglong *)(local_c8 + 0x40) = uVar18;
              *(undefined8 *)(local_c8 + 0x60) = uVar2;
              *(undefined4 *)(local_c8 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
              if (((char)local_170 != '\0') && (local_174 = 0, local_16c != 0)) {
                do {
                  bVar20 = (byte)uVar21;
                  if ((bVar20 != bVar14) && (bVar20 != (byte)local_164)) {
                    local_48 = local_48 & 0xffffffffffffff00;
                    if ((0x28 < *(byte *)(lVar7 + 0x279) + 1) ||
                       (cVar5 = StorAllocateMultiPool(lVar7,1,(longlong)&local_48), cVar5 == '\0'))
                    goto LAB_0002ea81;
                    lVar13 = (local_48 & 0xff) * 0xc0 + *(longlong *)(lVar7 + 0x50);
                    local_148[(ulonglong)local_178 + 0x10] = lVar13;
                    local_178 = local_178 + 1;
                    *(code **)(lVar13 + 0x18) = DispatchDiskReadWrite;
                    *(longlong *)(lVar13 + 0x10) = param_2;
                    *(undefined4 *)(lVar13 + 0xa0) = 0;
                    *(undefined4 *)(lVar13 + 0x54) = 0x40;
                    *(undefined1 *)(lVar13 + 0x90) = 0xff;
                    *(undefined4 *)(lVar13 + 0x58) = (undefined4)local_160;
                    *(byte *)(lVar13 + 0x4e) = bVar20;
                    uVar2 = *(undefined8 *)(param_1 + 0x41d8 + uVar21 * 8);
                    *(undefined4 *)(lVar13 + 0xa4) = 1;
                    *(undefined8 *)(lVar13 + 0x30) = 0;
                    *(longlong *)(lVar13 + 0x40) = lVar9;
                    *(undefined8 *)(lVar13 + 0x60) = uVar2;
                    *(undefined4 *)(lVar13 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
                  }
                  local_174 = local_174 + 1;
                  uVar21 = (ulonglong)
                           ((byte)(*(uint *)(uVar21 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf);
                } while (local_174 < local_16c);
              }
              local_48 = local_48 & 0xffffffffffffff00;
              if ((*(byte *)(lVar7 + 0x279) + 1 < 0x29) &&
                 (cVar5 = StorAllocateMultiPool(lVar7,1,(longlong)&local_48), cVar5 != '\0')) {
                uVar3 = (undefined4)local_160;
                uVar16 = 1;
                local_148[0] = (local_48 & 0xff) * 0xc0 + *(longlong *)(lVar7 + 0x50);
                *(code **)(local_148[0] + 0x18) = DispatchDiskReadWrite;
                *(longlong *)(local_148[0] + 0x10) = param_2;
                *(undefined4 *)(local_148[0] + 0xa0) = 1;
                *(undefined4 *)(local_148[0] + 0x54) = 0x80;
                *(undefined1 *)(local_148[0] + 0x90) = 0xff;
                *(byte *)(local_148[0] + 0x4e) = bVar14;
                *(undefined4 *)(local_148[0] + 0x58) = (undefined4)local_160;
                uVar2 = *(undefined8 *)(param_1 + 0x41d8 + local_158 * 8);
                *(undefined4 *)(local_148[0] + 0xa4) = 1;
                *(undefined8 *)(local_148[0] + 0x30) = 0;
                *(longlong *)(local_148[0] + 0x40) = lVar9;
                *(undefined8 *)(local_148[0] + 0x60) = uVar2;
                *(undefined4 *)(local_148[0] + 0x38) = *(undefined4 *)(param_2 + 0xe98);
                cVar5 = (char)local_170;
                if (cVar5 != '\0') {
                  local_48 = local_48 & 0xffffffffffffff00;
                  if ((0x28 < *(byte *)(lVar7 + 0x279) + 1) ||
                     (cVar6 = StorAllocateMultiPool(lVar7,1,(longlong)&local_48), cVar6 == '\0'))
                  goto LAB_0002ea81;
                  uVar16 = 2;
                  local_148[1] = (local_48 & 0xff) * 0xc0 + *(longlong *)(lVar7 + 0x50);
                  *(code **)(local_148[1] + 0x18) = DispatchDiskReadWrite;
                  *(longlong *)(local_148[1] + 0x10) = param_2;
                  *(undefined4 *)(local_148[1] + 0xa0) = 1;
                  *(undefined4 *)(local_148[1] + 0x54) = 0x80;
                  *(undefined1 *)(local_148[1] + 0x90) = 0xff;
                  *(char *)(local_148[1] + 0x4e) = (char)local_164;
                  *(undefined4 *)(local_148[1] + 0x58) = uVar3;
                  uVar2 = *(undefined8 *)(param_1 + 0x41d8 + (ulonglong)(local_164 & 0xff) * 8);
                  *(undefined4 *)(local_148[1] + 0xa4) = 1;
                  *(undefined8 *)(local_148[1] + 0x30) = 0;
                  *(undefined8 *)(local_148[1] + 0x60) = uVar2;
                  *(longlong *)(local_148[1] + 0x40) = lVar9;
                  *(undefined4 *)(local_148[1] + 0x38) = *(undefined4 *)(param_2 + 0xe98);
                }
                *(undefined8 *)(param_2 + 0x104) = 2;
                *(uint *)(param_2 + 0x110) = uVar16;
                *(uint *)(param_2 + 0x10c) = local_178;
                *(ulonglong *)(param_2 + 0x160) = -(ulonglong)(cVar5 != '\0') & 0x2da18;
                *(undefined1 **)(param_2 + 0x168) = &MigrateUpdateAddrCallback;
                *(ulonglong *)(param_2 + 0x200) = local_150;
                *(ulonglong *)(param_2 + 0x208) = (ulonglong)local_168;
                *(ulonglong *)(param_2 + 0x210) = uVar18 & 0xffffffff;
                *(ulonglong *)(param_2 + 0x218) = (ulonglong)bVar1;
                *(ulonglong *)(param_2 + 0x220) = (ulonglong)(byte)local_164;
                if (local_178 != 0) {
                  plVar10 = &local_c8;
                  uVar22 = (ulonglong)local_178;
                  do {
                    if (*(int *)(param_2 + 0xea4) != 0) {
                      lVar7 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
                      *(longlong *)(lVar7 + 0x78 + (ulonglong)*(byte *)(lVar7 + 0x278) * 8) =
                           *plVar10;
                      *(char *)(lVar7 + 0x278) = *(char *)(lVar7 + 0x278) + '\x01';
                    }
                    plVar10 = plVar10 + 1;
                    uVar22 = uVar22 - 1;
                  } while (uVar22 != 0);
                }
                if (uVar16 != 0) {
                  plVar10 = local_148;
                  uVar22 = (ulonglong)uVar16;
                  do {
                    if (*(int *)(param_2 + 0xea4) != 0) {
                      lVar7 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
                      *(longlong *)(lVar7 + 0x78 + (ulonglong)*(byte *)(lVar7 + 0x278) * 8) =
                           *plVar10;
                      *(char *)(lVar7 + 0x278) = *(char *)(lVar7 + 0x278) + '\x01';
                    }
                    plVar10 = plVar10 + 1;
                    uVar22 = uVar22 - 1;
                  } while (uVar22 != 0);
                }
                *(undefined4 *)(param_2 + 0xfc) = 0;
                return;
              }
            }
LAB_0002ea81:
            *(undefined1 *)(param_2 + 0x100) = 2;
            *(undefined4 *)(param_2 + 0xfc) = 2;
            DbgPrint("!!! ParseRaid5Migration: allocate sub command fail!\n");
LAB_0002ea9f:
            *(undefined1 *)(param_2 + 0x100) = 2;
            *(undefined4 *)(param_2 + 0xfc) = 2;
            return;
          }
          if (*(ulonglong *)(param_1 + 0x41d0) != 0) {
            ViaFreePool(param_1,uVar11,*(ulonglong *)(param_1 + 0x41d0));
            *(undefined8 *)(param_1 + 0x41d0) = 0;
          }
          if (local_16c != 0) {
            uVar22 = (ulonglong)local_16c;
            do {
              uVar18 = *(ulonglong *)(param_1 + 0x41d8 + uVar21 * 8);
              if (uVar18 != 0) {
                ViaFreePool(param_1,uVar11,uVar18);
                *(undefined8 *)(param_1 + 0x41d8 + uVar21 * 8) = 0;
                lVar7 = uVar21 * 0xb8;
                *(undefined8 *)(lVar7 + 0x3d8 + param_1) = 0;
                *(undefined8 *)(lVar7 + 0x3d0 + param_1) = 0;
                *(undefined4 *)(lVar7 + 0x3e0 + param_1) = 0;
              }
              uVar21 = (ulonglong)((byte)(*(uint *)(uVar21 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf);
              uVar22 = uVar22 - 1;
            } while (uVar22 != 0);
          }
        }
        *(undefined4 *)(param_2 + 0xf8) = 1;
        goto LAB_0002e3ba;
      }
    }
    *(undefined4 *)(param_2 + 0xf8) = 4;
  }
  else {
    *(undefined4 *)(param_2 + 0xf8) = 6;
  }
LAB_0002e3ba:
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return;
}



===== ParseRaid0Migration @ 0002ead8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ParseRaid0Migration(longlong param_1,ulonglong param_2,longlong param_3)

{
  byte *pbVar1;
  longlong *plVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  longlong lVar6;
  char cVar7;
  longlong lVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  ulonglong *puVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  ulonglong *puVar15;
  code *pcVar16;
  code *pcVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  uint uVar21;
  ulonglong uVar22;
  ulonglong *puVar23;
  int iVar24;
  ulonglong uVar25;
  uint uVar26;
  uint uVar27;
  undefined4 uVar28;
  ulonglong uVar29;
  uint uVar30;
  undefined8 uStack_1b0;
  undefined1 auStack_1a8 [8];
  undefined1 auStack_1a0 [24];
  uint local_188 [2];
  ulonglong local_180;
  uint local_178 [2];
  ulonglong local_170 [6];
  undefined1 local_140 [120];
  ulonglong local_c8;
  undefined1 local_c0 [120];
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_170[5] = 0;
  memset(local_140,0,0x78);
  local_c8 = 0;
  uVar13 = 0;
  memset(local_c0,0,0x78);
  bVar3 = *(byte *)(param_3 + 0x4d);
  uVar4 = *(undefined1 *)(param_3 + 0x52);
  local_170[3] = (ulonglong)bVar3;
  local_178[0] = (uint)CONCAT71((int7)((ulonglong)uVar13 >> 8),bVar3);
  uVar29 = (ulonglong)bVar3;
  local_170[0] = (longlong)
                 (int)((uint)CONCAT21(CONCAT11(*(undefined1 *)(param_3 + 0x4e),
                                               *(undefined1 *)(param_3 + 0x4f)),
                                      *(undefined1 *)(param_3 + 0x50)) << 8) |
                 (ulonglong)*(byte *)(param_3 + 0x51);
  uVar5 = *(undefined1 *)(param_3 + 0x53);
  iVar24 = *(int *)(local_170[3] * 0xd4 + 0xddc + param_1);
  local_180 = *(longlong *)(param_3 + 0x38);
  uVar14 = CONCAT44(iVar24,*(undefined4 *)(local_170[3] * 0xd4 + 0xd8c + param_1)) - 1;
  if (iVar24 != 0) {
    *(undefined4 *)(param_2 + 0xe98) = 1;
  }
  if (*(int *)(local_170[3] * 0xb8 + 0x3a8 + param_1) == 0) {
    uVar30 = *(uint *)(local_170[3] * 0xb8 + 0x3b0 + param_1);
    uVar26 = uVar30 >> 0x16;
    uVar30 = uVar30 & 0xf;
    local_48 = (ulonglong)uVar30;
    uVar25 = (ulonglong)uVar30 * (ulonglong)uVar26 * local_170[0];
    local_178[1] = uVar26 * uVar30;
    local_188[1] = local_178[1] * CONCAT11(uVar4,uVar5);
    uVar22 = (ulonglong)(uVar30 << 0x11);
    if (uVar30 * 0x100 < local_188[1]) {
      *(undefined4 *)(param_2 + 0xf8) = 4;
    }
    else {
      if (uVar14 < (uVar25 - 1) + (ulonglong)local_188[1]) {
        local_188[1] = (int)uVar14 - (int)uVar25;
      }
      uVar27 = local_188[1];
      pcVar16 = (code *)(ulonglong)local_188[1];
      local_170[1] = uVar25;
      if (0 < (int)local_188[1]) {
        if (*(longlong *)(param_1 + 0x41d0) == 0) {
          lVar8 = ViaAllocatePool(param_1,uVar14,uVar30 << 0x11);
          *(longlong *)(param_1 + 0x41d0) = lVar8;
          if (lVar8 != 0) goto LAB_0002ed2e;
        }
        else {
LAB_0002ed2e:
          uVar21 = (uint)uVar22;
          puVar18 = auStack_1a8;
          puVar19 = auStack_1a8;
          if (*(int *)(param_2 + 0xe0) < 0x10) {
            *(longlong *)(param_2 + 0x50 + (longlong)*(int *)(param_2 + 0xe0) * 8) =
                 param_1 + 0x41d0;
            *(undefined1 *)((longlong)*(int *)(param_2 + 0xe0) + 0xd0 + param_2) = 0;
            *(int *)(param_2 + 0xe0) = *(int *)(param_2 + 0xe0) + 1;
          }
          puVar15 = (ulonglong *)0x0;
          local_188[0] = 0;
          if (uVar30 != 0) {
            do {
              plVar2 = (longlong *)(param_1 + 0x41d8 + uVar29 * 8);
              local_48 = uVar29;
              if (*plVar2 == 0) {
                uVar22 = 0x20000;
                lVar8 = ViaAllocatePool(param_1,puVar15,0x20000);
                *plVar2 = lVar8;
                if (lVar8 == 0) goto LAB_0002f1c6;
                puVar15 = (ulonglong *)(ulonglong)local_188[0];
              }
              uVar21 = (uint)uVar22;
              if (*(int *)(param_2 + 0xe0) < 0x10) {
                *(longlong **)(param_2 + 0x50 + (longlong)*(int *)(param_2 + 0xe0) * 8) = plVar2;
                *(undefined1 *)((longlong)*(int *)(param_2 + 0xe0) + 0xd0 + param_2) = 0;
                *(int *)(param_2 + 0xe0) = *(int *)(param_2 + 0xe0) + 1;
              }
              local_188[0] = (int)puVar15 + 1;
              puVar15 = (ulonglong *)(ulonglong)local_188[0];
              uVar29 = (ulonglong)
                       ((byte)((uint)*(undefined4 *)(local_48 * 0xb8 + 0x3b0 + param_1) >> 8) & 0xf)
              ;
            } while (local_188[0] < uVar30);
          }
          puVar23 = (ulonglong *)0x0;
          if (uVar30 != 0) {
            uVar14 = 0;
            puVar12 = puVar23;
            do {
              if (7 < uVar14) {
                pcVar17 = (code *)swi(0x29);
                (*pcVar17)(8);
                puVar18 = auStack_1a0;
                goto LAB_0002ef66;
              }
              uVar9 = (int)puVar12 + 1;
              puVar12 = (ulonglong *)(ulonglong)uVar9;
              local_c0[uVar14 + 0x78] = 0;
              uVar14 = uVar14 + 1;
            } while (uVar9 < uVar30);
          }
          if (*(byte *)(local_180 + 0x279) + uVar30 < 0x29) {
            puVar12 = &local_48;
            puVar15 = (ulonglong *)(ulonglong)uVar30;
            cVar7 = StorAllocateMultiPool(local_180,uVar30,(longlong)puVar12);
            if (cVar7 != '\0') {
              if (uVar30 != 0) {
                puVar23 = *(ulonglong **)(local_180 + 0x50);
                puVar15 = &local_48;
                puVar12 = &local_c8;
                uVar14 = (ulonglong)uVar30;
                do {
                  uVar29 = *puVar15;
                  puVar15 = (ulonglong *)((longlong)puVar15 + 1);
                  *puVar12 = (ulonglong)(puVar23 + (ulonglong)(byte)uVar29 * 0x18);
                  puVar12 = puVar12 + 1;
                  uVar14 = uVar14 - 1;
                } while (uVar14 != 0);
              }
              uVar21 = (uint)puVar12;
              uVar9 = 0;
              uVar27 = uVar27 + 0xff >> 8;
              uVar29 = (ulonglong)uVar27;
              local_188[0] = uVar27;
              if (uVar27 != 0) {
                uVar14 = 0;
                do {
                  if (7 < uVar14) {
LAB_0002ef66:
                    uVar14 = 8;
                    pcVar17 = (code *)swi(0x29);
                    (*pcVar17)();
                    puVar19 = puVar18 + 8;
                    local_170[2] = uVar25;
                    goto LAB_0002ef6d;
                  }
                  uVar9 = uVar9 + 1;
                  local_c0[uVar14 + 0x78] = 0;
                  uVar14 = uVar14 + 1;
                } while (uVar9 < uVar27);
              }
              if (*(byte *)(local_180 + 0x279) + uVar27 < 0x29) {
                cVar7 = StorAllocateMultiPool(local_180,uVar27,(longlong)&local_48);
                if (cVar7 != '\0') {
                  if (uVar27 != 0) {
                    puVar15 = &local_48;
                    puVar23 = local_170 + 5;
                    lVar8 = *(longlong *)(local_180 + 0x50);
                    uVar14 = (ulonglong)uVar27;
                    do {
                      uVar29 = *puVar15;
                      puVar15 = (ulonglong *)((longlong)puVar15 + 1);
                      *puVar23 = (ulonglong)(byte)uVar29 * 0xc0 + lVar8;
                      puVar23 = puVar23 + 1;
                      uVar14 = uVar14 - 1;
                    } while (uVar14 != 0);
                  }
                  local_170[2] = *(ulonglong *)(param_1 + 0x41d0);
                  local_180 = uVar25;
                  uVar28 = 0;
                  puVar20 = auStack_1a8;
                  if (uVar27 != 0) {
                    uVar29 = (ulonglong)local_178[0];
                    local_48 = (ulonglong)uVar27;
                    puVar23 = local_170 + 5;
                    pcVar17 = DispatchDiskReadWrite;
                    do {
                      puVar15 = (ulonglong *)*puVar23;
                      uVar21 = (uint)pcVar16;
                      uVar14 = uVar25;
                      pcVar16 = pcVar17;
                      if (uVar21 < 0x101) {
LAB_0002ef6d:
                        uVar25 = (ulonglong)uVar21;
                        pcVar17 = pcVar16;
                        pcVar16 = (code *)0x0;
                      }
                      else {
                        uVar25 = 0x100;
                        pcVar16 = (code *)(ulonglong)(uVar21 - 0x100);
                      }
                      *(undefined4 *)(puVar15 + 0x14) = 0;
                      puVar15[2] = param_2;
                      puVar15[3] = (ulonglong)pcVar17;
                      pbVar1 = (byte *)((longlong)puVar15 + 0x54);
                      pbVar1[0] = 0x40;
                      pbVar1[1] = 0;
                      pbVar1[2] = 0;
                      pbVar1[3] = 0;
                      *(byte *)(puVar15 + 0x12) = 0xff;
                      puVar15[6] = 0;
                      *(byte *)((longlong)puVar15 + 0x4e) = (byte)uVar29;
                      puVar15[0xc] = local_170[2];
                      pbVar1 = (byte *)((longlong)puVar15 + 0xa4);
                      pbVar1[0] = 1;
                      pbVar1[1] = 0;
                      pbVar1[2] = 0;
                      pbVar1[3] = 0;
                      puVar15[8] = uVar14;
                      uVar27 = (int)uVar25 << 9;
                      *(uint *)(puVar15 + 0xb) = uVar27;
                      *(undefined4 *)(puVar15 + 7) = *(undefined4 *)(param_2 + 0xe98);
                      if (*(int *)(param_2 + 0xea4) != 0) {
                        lVar8 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
                        *(ulonglong **)(lVar8 + 0x78 + (ulonglong)*(byte *)(lVar8 + 0x278) * 8) =
                             puVar15;
                        *(char *)(lVar8 + 0x278) = *(char *)(lVar8 + 0x278) + '\x01';
                        uVar14 = *(ulonglong *)(puVar19 + 0x28);
                      }
                      puVar23 = puVar23 + 1;
                      local_170[2] = local_170[2] + uVar27;
                      uVar25 = uVar14 + uVar25;
                      local_48 = local_48 - 1;
                      *(ulonglong *)(puVar19 + 0x28) = uVar25;
                    } while (local_48 != 0);
                    pcVar16 = (code *)(ulonglong)*(uint *)(puVar19 + 0x24);
                    uVar28 = *(undefined4 *)(puVar19 + 0x20);
                    uVar25 = *(ulonglong *)(puVar19 + 0x40);
                    puVar20 = puVar19;
                  }
                  if ((int)((ulonglong)pcVar16 % (ulonglong)uVar26) != 0) {
                    uVar27 = (((int)pcVar16 + uVar26) / uVar26) * uVar26;
                    pcVar16 = (code *)(ulonglong)uVar27;
                    *(uint *)(puVar20 + 0x24) = uVar27;
                  }
                  iVar24 = 0;
                  uVar27 = 0;
                  if (uVar30 != 0) {
                    uVar14 = (ulonglong)*(uint *)(puVar20 + 0x30);
                    uVar21 = *(uint *)(puVar20 + 0x34);
                    lVar8 = *(longlong *)(puVar20 + 0x38);
                    puVar15 = &local_c8;
                    do {
                      uVar29 = *puVar15;
                      iVar11 = (int)((ulonglong)pcVar16 / (ulonglong)uVar21);
                      iVar10 = iVar11 + 1;
                      if ((uint)(((ulonglong)pcVar16 % (ulonglong)uVar21) / (ulonglong)uVar26) <=
                          uVar27) {
                        iVar10 = iVar11;
                      }
                      iVar11 = iVar10 * uVar26 * 0x200;
                      if (iVar11 != 0) {
                        *(ulonglong *)(uVar29 + 0x10) = param_2;
                        *(undefined4 *)(uVar29 + 0xa0) = 1;
                        *(undefined4 *)(uVar29 + 0x54) = 0x80;
                        *(code **)(uVar29 + 0x18) = DispatchDiskReadWrite;
                        *(undefined1 *)(uVar29 + 0x90) = 0xff;
                        *(char *)(uVar29 + 0x4e) = (char)uVar14;
                        *(int *)(uVar29 + 0x58) = iVar11;
                        uVar13 = *(undefined8 *)(param_1 + 0x41d8 + (uVar14 & 0xff) * 8);
                        *(undefined8 *)(uVar29 + 0x30) = 0;
                        *(undefined4 *)(uVar29 + 0xa4) = 1;
                        *(undefined8 *)(uVar29 + 0x60) = uVar13;
                        *(ulonglong *)(uVar29 + 0x40) = (ulonglong)uVar26 * lVar8;
                        *(undefined4 *)(uVar29 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
                        if (*(int *)(param_2 + 0xea4) != 0) {
                          lVar6 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
                          *(ulonglong *)(lVar6 + 0x78 + (ulonglong)*(byte *)(lVar6 + 0x278) * 8) =
                               uVar29;
                          *(char *)(lVar6 + 0x278) = *(char *)(lVar6 + 0x278) + '\x01';
                        }
                        iVar24 = iVar24 + 1;
                      }
                      uVar27 = uVar27 + 1;
                      puVar15 = puVar15 + 1;
                      uVar14 = (ulonglong)
                               ((byte)((uint)*(undefined4 *)
                                              ((uVar14 & 0xff) * 0xb8 + 0x3b0 + param_1) >> 8) & 0xf
                               );
                    } while (uVar27 < uVar30);
                    pcVar16 = (code *)(ulonglong)*(uint *)(puVar20 + 0x24);
                    uVar28 = *(undefined4 *)(puVar20 + 0x20);
                    uVar25 = *(ulonglong *)(puVar20 + 0x40);
                  }
                  *(undefined4 *)(param_2 + 0x108) = 0;
                  *(undefined4 *)(param_2 + 0x104) = 2;
                  *(code **)(param_2 + 0x160) = Raid0MigrateMemCpyCallback;
                  *(undefined4 *)(param_2 + 0x10c) = uVar28;
                  *(undefined1 **)(param_2 + 0x168) = &MigrateUpdateAddrCallback;
                  uVar13 = *(undefined8 *)(puVar20 + 0x50);
                  *(int *)(param_2 + 0x110) = iVar24;
                  *(undefined8 *)(param_2 + 0x200) = uVar13;
                  *(code **)(param_2 + 0x208) = pcVar16;
                  *(ulonglong *)(param_2 + 0x210) = uVar25 & 0xffffffff;
                  *(ulonglong *)(param_2 + 0x218) = uVar25 >> 0x20;
                  *(ulonglong *)(param_2 + 0x220) = (ulonglong)*(uint *)(puVar20 + 0x38);
                  *(undefined4 *)(param_2 + 0xfc) = 0;
                  goto LAB_0002f1d7;
                }
              }
            }
          }
        }
LAB_0002f1c6:
        puVar20 = auStack_1a8;
        *(undefined1 *)(param_2 + 0x100) = 2;
        *(undefined4 *)(param_2 + 0xfc) = 2;
        goto LAB_0002f1d7;
      }
      if (*(ulonglong *)(param_1 + 0x41d0) != 0) {
        ViaFreePool(param_1,uVar14,*(ulonglong *)(param_1 + 0x41d0));
        *(undefined8 *)(param_1 + 0x41d0) = 0;
      }
      uVar25 = (ulonglong)uVar30;
      if (uVar30 != 0) {
        do {
          uVar22 = *(ulonglong *)(param_1 + 0x41d8 + uVar29 * 8);
          if (uVar22 != 0) {
            ViaFreePool(param_1,uVar14,uVar22);
            lVar8 = uVar29 * 0xb8;
            *(undefined8 *)(param_1 + 0x41d8 + uVar29 * 8) = 0;
            *(undefined8 *)(lVar8 + 0x3d8 + param_1) = 0;
            *(undefined8 *)(lVar8 + 0x3d0 + param_1) = 0;
            *(undefined4 *)(lVar8 + 0x3e0 + param_1) = 0;
            uVar25 = local_48;
          }
          uVar29 = (ulonglong)
                   ((byte)((uint)*(undefined4 *)(uVar29 * 0xb8 + 0x3b0 + param_1) >> 8) & 0xf);
          uVar25 = uVar25 - 1;
          local_48 = uVar25;
        } while (uVar25 != 0);
      }
      *(undefined4 *)(param_2 + 0xf8) = 1;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0xf8) = 6;
  }
  puVar20 = auStack_1a8;
  *(undefined4 *)(param_2 + 0xfc) = 1;
LAB_0002f1d7:
  *(undefined8 *)(puVar20 + -8) = 0x2f1e3;
  return;
}



===== ParseRaid5Sync @ 0002f200 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ParseRaid5Sync(longlong param_1,longlong param_2,longlong param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  int iVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  code *pcVar12;
  byte bVar13;
  char cVar14;
  longlong lVar15;
  ulonglong uVar16;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  longlong *plVar20;
  ulonglong uVar21;
  uint uVar22;
  uint uVar23;
  ulonglong uVar24;
  byte bVar25;
  undefined1 auStack_108 [32];
  longlong local_e8;
  uint local_e0;
  ulonglong local_d8;
  ulonglong local_d0;
  longlong local_c8;
  undefined1 local_c0 [120];
  uint local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_108;
  local_c8 = 0;
  local_e8 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
  memset(local_c0,0,0x78);
  uVar1 = *(undefined1 *)(param_3 + 0x4f);
  bVar13 = *(byte *)(param_3 + 0x4d);
  uVar21 = (ulonglong)bVar13;
  uVar2 = *(undefined1 *)(param_3 + 0x4e);
  uVar3 = *(undefined1 *)(param_3 + 0x52);
  uVar4 = *(undefined1 *)(param_3 + 0x50);
  uVar5 = *(undefined1 *)(param_3 + 0x51);
  uVar6 = *(undefined1 *)(param_3 + 0x53);
  uVar7 = *(undefined4 *)((ulonglong)bVar13 * 0x200 + 0x14ce + param_1);
  iVar8 = *(int *)((ulonglong)bVar13 * 0x200 + 0x14ca + param_1);
  if (iVar8 != 0) {
    *(undefined4 *)(param_2 + 0xe98) = 1;
  }
  if (*(int *)(uVar21 * 0xb8 + 0x3a8 + param_1) == 5) {
    uVar22 = *(uint *)(uVar21 * 0xb8 + 0x3b0 + param_1);
    uVar17 = uVar22 >> 0x16;
    uVar22 = uVar22 & 0xf;
    uVar23 = uVar22 + 1;
    uVar18 = uVar17 * CONCAT11(uVar3,uVar6);
    uVar24 = (ulonglong)uVar17 * (ulonglong)CONCAT31(CONCAT21(CONCAT11(uVar2,uVar1),uVar4),uVar5);
    if (uVar18 < 0x101) {
      if (CONCAT44(uVar7,iVar8) <= uVar18 + uVar24) {
        uVar18 = iVar8 - (int)uVar24;
      }
      uVar17 = 0;
      bVar25 = bVar13;
      if (uVar23 != 0) {
        do {
          if (*(char *)((ulonglong)bVar25 * 0xb8 + 0x3ad + param_1) == '\0') {
            if (bVar25 != 0xff) {
              *(undefined1 *)(param_2 + 0xeb3) = 1;
              if ((uVar24 == 0) && (uVar18 == 0)) {
                *(undefined8 *)(param_2 + 0xf8) = 1;
                *(undefined2 *)(param_2 + 0xeb4) = 1;
                return;
              }
              if ((int)uVar18 < 1) {
                *(undefined8 *)(param_2 + 0xf8) = 1;
                *(undefined2 *)(param_2 + 0xeb4) = 0x101;
                return;
              }
              local_48[0] = 0;
              local_e0 = uVar23;
              local_d0 = uVar21;
              goto LAB_0002f3dc;
            }
            break;
          }
          uVar17 = uVar17 + 1;
          bVar25 = (byte)(*(uint *)((ulonglong)bVar25 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf;
        } while (uVar17 < uVar23);
      }
    }
    *(undefined4 *)(param_2 + 0xf8) = 4;
  }
  else {
    *(undefined4 *)(param_2 + 0xf8) = 6;
  }
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return;
  while( true ) {
    if (*(int *)(param_2 + 0xe0) < 0x10) {
      *(longlong **)(param_2 + 0x50 + (longlong)*(int *)(param_2 + 0xe0) * 8) = plVar20;
      *(undefined1 *)((longlong)*(int *)(param_2 + 0xe0) + 0xd0 + param_2) = 0;
      *(int *)(param_2 + 0xe0) = *(int *)(param_2 + 0xe0) + 1;
    }
    local_48[0] = local_48[0] + 1;
    bVar13 = (byte)(*(uint *)(local_d8 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf;
    if (uVar23 <= local_48[0]) break;
LAB_0002f3dc:
    local_d8 = (ulonglong)bVar13;
    plVar20 = (longlong *)(param_1 + 0x41d8 + local_d8 * 8);
    if (*plVar20 == 0) {
      lVar15 = ViaAllocatePool(param_1,local_d8,0x20000);
      *plVar20 = lVar15;
      if (lVar15 == 0) goto LAB_0002f752;
    }
  }
  local_48[0] = local_48[0] & 0xffffff00;
  if ((*(byte *)(local_e8 + 0x279) + 1 < 0x29) &&
     (cVar14 = StorAllocateMultiPool(local_e8,1,(longlong)local_48), cVar14 != '\0')) {
    uVar17 = 0;
    lVar15 = (ulonglong)(byte)local_48[0] * 0xc0 + *(longlong *)(local_e8 + 0x50);
    if (uVar22 != 0) {
      uVar16 = 0;
      do {
        if (7 < uVar16) {
          pcVar12 = (code *)swi(0x29);
          (*pcVar12)(8);
          pcVar12 = (code *)swi(3);
          (*pcVar12)();
          return;
        }
        uVar17 = uVar17 + 1;
        *(undefined1 *)((longlong)local_48 + uVar16) = 0;
        uVar16 = uVar16 + 1;
      } while (uVar17 < uVar22);
    }
    if ((*(byte *)(local_e8 + 0x279) + uVar22 < 0x29) &&
       (cVar14 = StorAllocateMultiPool(local_e8,uVar22,(longlong)local_48), cVar14 != '\0')) {
      if (uVar22 != 0) {
        puVar19 = local_48;
        plVar20 = &local_c8;
        lVar9 = *(longlong *)(local_e8 + 0x50);
        uVar16 = (ulonglong)uVar22;
        do {
          uVar17 = *puVar19;
          puVar19 = (uint *)((longlong)puVar19 + 1);
          *plVar20 = (ulonglong)(byte)uVar17 * 0xc0 + lVar9;
          plVar20 = plVar20 + 1;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
      }
      if (uVar22 != 0) {
        plVar20 = &local_c8;
        uVar16 = (ulonglong)uVar22;
        do {
          if ((byte)uVar21 == bVar25) {
            uVar21 = (ulonglong)((byte)(*(uint *)(uVar21 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf);
          }
          lVar9 = *plVar20;
          uVar10 = *(undefined8 *)(param_1 + 0x41d8 + uVar21 * 8);
          *(longlong *)(lVar9 + 0x10) = param_2;
          *(undefined4 *)(lVar9 + 0xa0) = 0;
          *(code **)(lVar9 + 0x18) = DispatchDiskReadWrite;
          *(undefined4 *)(lVar9 + 0x54) = 0x40;
          *(undefined1 *)(lVar9 + 0x90) = 0xff;
          *(undefined8 *)(lVar9 + 0x60) = uVar10;
          *(char *)(lVar9 + 0x4e) = (char)uVar21;
          *(uint *)(lVar9 + 0x58) = uVar18 << 9;
          *(undefined4 *)(lVar9 + 0xa4) = 1;
          *(undefined8 *)(lVar9 + 0x30) = 0;
          *(ulonglong *)(lVar9 + 0x40) = uVar24;
          *(undefined4 *)(lVar9 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
          if (*(int *)(param_2 + 0xea4) != 0) {
            lVar11 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
            *(longlong *)(lVar11 + 0x78 + (ulonglong)*(byte *)(lVar11 + 0x278) * 8) = lVar9;
            *(char *)(lVar11 + 0x278) = *(char *)(lVar11 + 0x278) + '\x01';
          }
          plVar20 = plVar20 + 1;
          uVar21 = (ulonglong)((byte)(*(uint *)(uVar21 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf);
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
        uVar23 = local_e0;
      }
      uVar10 = *(undefined8 *)(param_1 + 0x41d8 + (ulonglong)bVar25 * 8);
      *(code **)(lVar15 + 0x18) = DispatchDiskReadWrite;
      *(longlong *)(lVar15 + 0x10) = param_2;
      *(undefined4 *)(lVar15 + 0xa0) = 1;
      *(undefined4 *)(lVar15 + 0x54) = 0x80;
      *(undefined1 *)(lVar15 + 0x90) = 0xff;
      *(undefined8 *)(lVar15 + 0x30) = 0;
      *(byte *)(lVar15 + 0x4e) = bVar25;
      *(undefined8 *)(lVar15 + 0x60) = uVar10;
      *(undefined4 *)(lVar15 + 0xa4) = 1;
      *(ulonglong *)(lVar15 + 0x40) = uVar24;
      *(uint *)(lVar15 + 0x58) = uVar18 << 9;
      *(undefined4 *)(lVar15 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
      if (*(int *)(param_2 + 0xea4) != 0) {
        lVar9 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
        *(longlong *)(lVar9 + 0x78 + (ulonglong)*(byte *)(lVar9 + 0x278) * 8) = lVar15;
        *(char *)(lVar9 + 0x278) = *(char *)(lVar9 + 0x278) + '\x01';
      }
      *(ulonglong *)(param_1 + 0x41c0) = uVar24;
      *(byte *)(param_1 + 0x4198) = bVar25;
      *(uint *)(param_1 + 0x41c8) = uVar18;
      *(undefined4 *)(param_2 + 0x104) = 2;
      *(undefined4 *)(param_2 + 0x110) = 1;
      *(uint *)(param_2 + 0x10c) = uVar23 - 1;
      *(undefined1 **)(param_2 + 0x168) = &Raid5SyncUpdateAddrCallback;
      *(undefined4 *)(param_2 + 0x108) = 0;
      *(code **)(param_2 + 0x160) = Raid5SyncCalcParityCallback;
      *(ulonglong *)(param_2 + 0x220) = (ulonglong)bVar25;
      *(ulonglong *)(param_2 + 0x200) = local_d0;
      *(ulonglong *)(param_2 + 0x208) = (ulonglong)uVar18;
      *(ulonglong *)(param_2 + 0x218) = uVar24 >> 0x20;
      *(ulonglong *)(param_2 + 0x210) = uVar24 & 0xffffffff;
      *(undefined4 *)(param_2 + 0xfc) = 0;
      return;
    }
  }
LAB_0002f752:
  *(undefined4 *)(param_2 + 0xfc) = 2;
  *(undefined1 *)(param_2 + 0x100) = 2;
  return;
}



===== ParseRaid5Verify @ 0002f770 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ParseRaid5Verify(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  code *pcVar5;
  char cVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  longlong *plVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  undefined1 auStack_108 [8];
  undefined1 auStack_100 [24];
  longlong local_e8;
  ulonglong local_e0;
  longlong local_d8;
  ulonglong local_d0;
  longlong local_c8;
  undefined1 local_c0 [120];
  uint local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_108;
  local_c8 = 0;
  local_e8 = param_3;
  memset(local_c0,0,0x78);
  uVar16 = (ulonglong)*(byte *)(param_3 + 0x4d);
  local_d8 = *(longlong *)(param_3 + 0x38);
  uVar8 = (ulonglong)
          CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_3 + 0x4e),*(undefined1 *)(param_3 + 0x4f)
                                    ),*(undefined1 *)(param_3 + 0x50)),
                   *(undefined1 *)(param_3 + 0x51));
  iVar1 = *(int *)(uVar16 * 0x200 + 0x14ca + param_1);
  if (*(int *)(uVar16 * 0xb8 + 0x3a8 + param_1) == 5) {
    uVar12 = *(uint *)(uVar16 * 0xb8 + 0x3b0 + param_1);
    uVar11 = uVar12 >> 0x16;
    uVar13 = (uVar12 & 0xf) + 1;
    uVar12 = uVar11 * CONCAT11(*(undefined1 *)(param_3 + 0x52),*(undefined1 *)(param_3 + 0x53));
    uVar15 = uVar11 * uVar8;
    if (uVar12 < 0x101) {
      if (CONCAT44(*(undefined4 *)(uVar16 * 0x200 + 0x14ce + param_1),iVar1) <= uVar12 + uVar15) {
        uVar12 = iVar1 - (int)uVar15;
      }
      local_d0 = uVar16;
      if (0 < (int)uVar12) {
        uVar8 = (ulonglong)*(byte *)(param_3 + 0x4d);
        local_48[0] = 0;
        if (uVar13 != 0) {
          do {
            plVar14 = (longlong *)(param_1 + 0x41d8 + uVar8 * 8);
            local_e0 = uVar8;
            if (*plVar14 == 0) {
              lVar7 = ViaAllocatePool(param_1,uVar8,0x20000);
              *plVar14 = lVar7;
              puVar10 = auStack_108;
              if (lVar7 == 0) goto LAB_0002fb35;
            }
            if (*(int *)(param_2 + 0xe0) < 0x10) {
              *(longlong **)(param_2 + 0x50 + (longlong)*(int *)(param_2 + 0xe0) * 8) = plVar14;
              *(undefined1 *)((longlong)*(int *)(param_2 + 0xe0) + 0xd0 + param_2) = 0;
              *(int *)(param_2 + 0xe0) = *(int *)(param_2 + 0xe0) + 1;
            }
            local_48[0] = local_48[0] + 1;
            uVar8 = (ulonglong)(*(uint *)(local_e0 * 0xb8 + 0x3b0 + param_1) >> 0xe & 0xff) &
                    0xffffffffffffff0f;
          } while (local_48[0] < uVar13);
        }
        lVar7 = local_d8;
        uVar11 = 0;
        if (uVar13 != 0) {
          uVar8 = 0;
          do {
            if (7 < uVar8) {
              pcVar5 = (code *)swi(0x29);
              (*pcVar5)(8);
              puVar10 = auStack_100;
              goto LAB_0002fb35;
            }
            uVar11 = uVar11 + 1;
            *(undefined1 *)((longlong)local_48 + uVar8) = 0;
            uVar8 = uVar8 + 1;
          } while (uVar11 < uVar13);
        }
        puVar10 = auStack_108;
        if (*(byte *)(local_d8 + 0x279) + uVar13 < 0x29) {
          cVar6 = StorAllocateMultiPool(local_d8,uVar13,(longlong)local_48);
          puVar10 = auStack_108;
          if (cVar6 != '\0') {
            if (uVar13 != 0) {
              lVar7 = *(longlong *)(lVar7 + 0x50);
              puVar9 = local_48;
              plVar14 = &local_c8;
              uVar8 = (ulonglong)uVar13;
              do {
                uVar11 = *puVar9;
                puVar9 = (uint *)((longlong)puVar9 + 1);
                *plVar14 = (ulonglong)(byte)uVar11 * 0xc0 + lVar7;
                plVar14 = plVar14 + 1;
                uVar8 = uVar8 - 1;
              } while (uVar8 != 0);
            }
            if (uVar13 != 0) {
              plVar14 = &local_c8;
              uVar8 = (ulonglong)uVar13;
              do {
                lVar7 = *plVar14;
                uVar3 = *(undefined8 *)(param_1 + 0x41d8 + uVar16 * 8);
                *(longlong *)(lVar7 + 0x10) = param_2;
                *(undefined4 *)(lVar7 + 0xa0) = 0;
                *(code **)(lVar7 + 0x18) = DispatchDiskReadWrite;
                *(undefined4 *)(lVar7 + 0x54) = 0x40;
                *(undefined1 *)(lVar7 + 0x90) = 0xff;
                *(undefined8 *)(lVar7 + 0x60) = uVar3;
                *(char *)(lVar7 + 0x4e) = (char)uVar16;
                *(uint *)(lVar7 + 0x58) = uVar12 << 9;
                *(undefined4 *)(lVar7 + 0xa4) = 1;
                *(undefined8 *)(lVar7 + 0x30) = 0;
                *(ulonglong *)(lVar7 + 0x40) = uVar15;
                *(undefined4 *)(lVar7 + 0x38) = *(undefined4 *)(param_2 + 0xe98);
                if (*(int *)(param_2 + 0xea4) != 0) {
                  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
                  *(longlong *)(lVar4 + 0x78 + (ulonglong)*(byte *)(lVar4 + 0x278) * 8) = lVar7;
                  *(char *)(lVar4 + 0x278) = *(char *)(lVar4 + 0x278) + '\x01';
                }
                plVar14 = plVar14 + 1;
                uVar16 = (ulonglong)
                         ((byte)(*(uint *)(uVar16 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf);
                uVar8 = uVar8 - 1;
              } while (uVar8 != 0);
            }
            *(undefined8 *)(param_2 + 0x104) = 1;
            *(uint *)(param_2 + 0x10c) = uVar13;
            *(code **)(param_2 + 0x160) = Raid5VerifyCalcParityCallback;
            *(ulonglong *)(param_2 + 0x200) = local_d0;
            *(ulonglong *)(param_2 + 0x208) = (ulonglong)uVar12;
            *(ulonglong *)(param_2 + 0x210) = uVar15 & 0xffffffff;
            *(ulonglong *)(param_2 + 0x218) = uVar15 >> 0x20;
            *(undefined8 *)(param_2 + 0x220) = *(undefined8 *)(local_e8 + 0x18);
            *(undefined4 *)(param_2 + 0xfc) = 0;
            puVar10 = auStack_108;
            goto LAB_0002fb46;
          }
        }
LAB_0002fb35:
        *(undefined1 *)(param_2 + 0x100) = 2;
        *(undefined4 *)(param_2 + 0xfc) = 2;
        goto LAB_0002fb46;
      }
      if (uVar13 != 0) {
        uVar15 = (ulonglong)uVar13;
        do {
          uVar2 = *(ulonglong *)(param_1 + 0x41d8 + uVar16 * 8);
          if (uVar2 != 0) {
            ViaFreePool(param_1,uVar8,uVar2);
            *(undefined8 *)(param_1 + 0x41d8 + uVar16 * 8) = 0;
          }
          uVar16 = (ulonglong)((byte)(*(uint *)(uVar16 * 0xb8 + 0x3b0 + param_1) >> 0xe) & 0xf);
          uVar15 = uVar15 - 1;
        } while (uVar15 != 0);
      }
      **(undefined1 **)(local_e8 + 0x18) = 1;
      *(undefined4 *)(param_2 + 0xf8) = 1;
    }
    else {
      *(undefined4 *)(param_2 + 0xf8) = 4;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0xf8) = 6;
  }
  *(undefined4 *)(param_2 + 0xfc) = 1;
  puVar10 = auStack_108;
LAB_0002fb46:
  *(undefined8 *)(puVar10 + -8) = 0x2fb56;
  return;
}



===== RfParseRaidUserCmd @ 0002fb74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool RfParseRaidUserCmd(undefined8 *param_1,ulonglong param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined8 uVar5;
  ushort uVar6;
  ulonglong uVar7;
  ushort uVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined8 *puVar11;
  longlong lVar12;
  undefined1 uVar13;
  undefined1 auStack_b8 [32];
  undefined8 local_98 [2];
  undefined4 local_88;
  undefined8 *local_80;
  ulonglong local_38;
  
  uVar13 = DAT_000362a4;
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  bVar2 = *(byte *)((longlong)param_3 + 0x4d);
  bVar3 = *(byte *)((longlong)param_3 + 0x4b);
  if (bVar3 < 0x1d) {
    if (bVar3 == 0x1c) {
      if (*(int *)(param_1 + (ulonglong)bVar2 * 0x17 + 0x75) == 0) {
        ParseRaid0Migration((longlong)param_1,param_2,(longlong)param_3);
        return true;
      }
      if (*(int *)(param_1 + (ulonglong)bVar2 * 0x17 + 0x75) == 5) {
        ParseRaid5Migration((longlong)param_1,param_2,(longlong)param_3);
        return true;
      }
    }
    else if ((bVar3 != 5) && (bVar3 != 6)) {
      if (bVar3 == 7) {
        DAT_000362a4 = 0;
        *(undefined1 *)param_3[3] = uVar13;
        goto LAB_0002fe4d;
      }
      if (bVar3 < 10) {
LAB_00030035:
        uVar7 = ParseDynamicUserCmd((longlong)param_1,param_2,param_3);
        return (char)uVar7 != '\0';
      }
      if (bVar3 < 0xc) {
        ParseUserSyncVerify((longlong)param_1,param_2,(longlong)param_3);
        return true;
      }
      if (bVar3 == 0xd) {
        if (7 < bVar2) goto LAB_0002fc0c;
        uVar7 = (ulonglong)bVar2;
        lVar12 = uVar7 * 0xb8;
        if (*(char *)(lVar12 + 0x399 + (longlong)param_1) == '\0') goto LAB_0002fe4d;
        iVar4 = *(int *)(param_1 + uVar7 * 0x17 + 0x75);
        *(undefined1 *)(lVar12 + 0x399 + (longlong)param_1) = 0;
        *(undefined1 *)(lVar12 + 0x3ae + (longlong)param_1) = 0;
        if ((((iVar4 != 9) &&
             ((iVar4 != 1 || (((byte)*(undefined4 *)(param_1 + uVar7 * 0x17 + 0x76) & 0xf0) == 0x20)
              ))) || (uVar7 = FindMirrorPair(bVar2,(longlong)param_1), (char)uVar7 == -1)) ||
           (uVar7 = uVar7 & 0xff, *(char *)(uVar7 * 0xb8 + 0x399 + (longlong)param_1) != '\0'))
        goto LAB_000301d1;
        puVar11 = (undefined8 *)((longlong)param_1 + uVar7 * 0x200 + 0x14c4);
        *(ushort *)((longlong)puVar11 + 3) = *(ushort *)((longlong)puVar11 + 3) & 0x7fff;
        if (*(int *)(param_1 + uVar7 * 0x17 + 0x75) == 9) {
          uVar6 = *(ushort *)((longlong)puVar11 + 3) | 0x4000;
LAB_0002fefd:
          *(ushort *)((longlong)puVar11 + 3) = uVar6;
        }
        else if (*(int *)(param_1 + uVar7 * 0x17 + 0x75) == 1) {
          uVar6 = *(ushort *)((longlong)puVar11 + 3) | 0x1000;
          goto LAB_0002fefd;
        }
        ConstructNormalSrbByUserSrb((longlong)param_1,param_2,local_98,param_3);
        local_80 = (undefined8 *)param_1[0x8fe];
        local_88 = 0x200;
        param_1 = local_80;
        if (local_80 != puVar11) {
          if ((((uint)puVar11 | (uint)local_80) & 0xf) == 0) {
            lVar12 = 4;
            puVar9 = local_80;
            do {
              uVar5 = puVar11[1];
              *puVar9 = *puVar11;
              puVar9[1] = uVar5;
              uVar5 = puVar11[3];
              puVar9[2] = puVar11[2];
              puVar9[3] = uVar5;
              uVar5 = puVar11[5];
              puVar9[4] = puVar11[4];
              puVar9[5] = uVar5;
              uVar5 = puVar11[7];
              puVar9[6] = puVar11[6];
              puVar9[7] = uVar5;
              uVar5 = puVar11[9];
              puVar9[8] = puVar11[8];
              puVar9[9] = uVar5;
              uVar5 = puVar11[0xb];
              puVar9[10] = puVar11[10];
              puVar9[0xb] = uVar5;
              uVar5 = puVar11[0xd];
              puVar9[0xc] = puVar11[0xc];
              puVar9[0xd] = uVar5;
              puVar1 = puVar11 + 0xe;
              uVar5 = puVar11[0xf];
              param_1 = puVar9 + 0x10;
              puVar11 = puVar11 + 0x10;
              puVar9[0xe] = *puVar1;
              puVar9[0xf] = uVar5;
              lVar12 = lVar12 + -1;
              puVar9 = param_1;
            } while (lVar12 != 0);
          }
          else {
LAB_0002fd4f:
            local_88 = 0x200;
            param_1 = local_80;
            memcpy(local_80,puVar11,0x200);
          }
        }
LAB_0002fd57:
        *(code **)(param_2 + 0x160) = UserCmdCallBack;
LAB_0002fd65:
        NormalHDDCommand((ulonglong)param_1,local_98,param_2);
        return true;
      }
      if (bVar3 == 0xf) {
        if (bVar2 < 8) {
          puVar11 = (undefined8 *)param_3[3];
          puVar9 = (undefined8 *)((longlong)param_1 + (ulonglong)bVar2 * 0x200 + 0x14c4);
          if (puVar11 != puVar9) {
            if ((((uint)puVar9 | (uint)puVar11) & 0xf) == 0) {
              lVar12 = 4;
              do {
                uVar5 = puVar9[1];
                *puVar11 = *puVar9;
                puVar11[1] = uVar5;
                uVar5 = puVar9[3];
                puVar11[2] = puVar9[2];
                puVar11[3] = uVar5;
                uVar5 = puVar9[5];
                puVar11[4] = puVar9[4];
                puVar11[5] = uVar5;
                uVar5 = puVar9[7];
                puVar11[6] = puVar9[6];
                puVar11[7] = uVar5;
                uVar5 = puVar9[9];
                puVar11[8] = puVar9[8];
                puVar11[9] = uVar5;
                uVar5 = puVar9[0xb];
                puVar11[10] = puVar9[10];
                puVar11[0xb] = uVar5;
                uVar5 = puVar9[0xd];
                puVar11[0xc] = puVar9[0xc];
                puVar11[0xd] = uVar5;
                puVar1 = puVar9 + 0xe;
                uVar5 = puVar9[0xf];
                puVar9 = puVar9 + 0x10;
                puVar11[0xe] = *puVar1;
                puVar11[0xf] = uVar5;
                lVar12 = lVar12 + -1;
                puVar11 = puVar11 + 0x10;
              } while (lVar12 != 0);
            }
            else {
              memcpy(puVar11,puVar9,0x200);
            }
          }
          goto LAB_000301d1;
        }
      }
      else {
        if (bVar3 != 0x10) {
          if (bVar3 != 0x11) goto LAB_00030035;
          if (8 < bVar2) goto LAB_0002fc0c;
          uVar7 = (ulonglong)bVar2;
          iVar4 = *(int *)(param_1 + uVar7 * 0x17 + 0x75);
          *(undefined1 *)(uVar7 * 0xb8 + 0x3ad + (longlong)param_1) = 0;
          if (((iVar4 != 9) &&
              ((iVar4 != 1 ||
               (((byte)*(undefined4 *)(param_1 + uVar7 * 0x17 + 0x76) & 0xf0) == 0x20)))) ||
             (*(char *)(uVar7 * 0xb8 + 0x399 + (longlong)param_1) != '\0')) {
LAB_000301d1:
            *(undefined4 *)(param_2 + 0xfc) = 1;
            *(undefined4 *)(param_2 + 0xf8) = 1;
            return true;
          }
          puVar11 = (undefined8 *)((longlong)param_1 + uVar7 * 0x200 + 0x14c4);
          if (iVar4 == 9) {
            uVar6 = *(ushort *)((longlong)puVar11 + 3);
            if ((uVar6 & 0x4000) == 0) goto LAB_000301d1;
            uVar8 = 0xbfff;
          }
          else {
            if ((iVar4 != 1) || (uVar6 = *(ushort *)((longlong)puVar11 + 3), (uVar6 & 0x1000) == 0))
            goto LAB_000301d1;
            uVar8 = 0xefff;
          }
          *(ushort *)((longlong)puVar11 + 3) = uVar6 & uVar8;
          ConstructNormalSrbByUserSrb((longlong)param_1,param_2,local_98,param_3);
          local_80 = (undefined8 *)param_1[0x8fe];
          local_88 = 0x200;
          param_1 = local_80;
          if (local_80 != puVar11) {
            if ((((uint)puVar11 | (uint)local_80) & 0xf) == 0) {
              lVar12 = 4;
              puVar9 = local_80;
              do {
                uVar5 = puVar11[1];
                *puVar9 = *puVar11;
                puVar9[1] = uVar5;
                uVar5 = puVar11[3];
                puVar9[2] = puVar11[2];
                puVar9[3] = uVar5;
                uVar5 = puVar11[5];
                puVar9[4] = puVar11[4];
                puVar9[5] = uVar5;
                uVar5 = puVar11[7];
                puVar9[6] = puVar11[6];
                puVar9[7] = uVar5;
                uVar5 = puVar11[9];
                puVar9[8] = puVar11[8];
                puVar9[9] = uVar5;
                uVar5 = puVar11[0xb];
                puVar9[10] = puVar11[10];
                puVar9[0xb] = uVar5;
                uVar5 = puVar11[0xd];
                puVar9[0xc] = puVar11[0xc];
                puVar9[0xd] = uVar5;
                puVar1 = puVar11 + 0xe;
                uVar5 = puVar11[0xf];
                param_1 = puVar9 + 0x10;
                puVar11 = puVar11 + 0x10;
                puVar9[0xe] = *puVar1;
                puVar9[0xf] = uVar5;
                lVar12 = lVar12 + -1;
                puVar9 = param_1;
              } while (lVar12 != 0);
              goto LAB_0002fd57;
            }
            goto LAB_0002fd4f;
          }
          goto LAB_0002fd57;
        }
        if (bVar2 < 8) {
          ConstructNormalSrbByUserSrb((longlong)param_1,param_2,local_98,param_3);
          goto LAB_0002fd65;
        }
      }
    }
  }
  else {
    if (bVar3 == 0x1d) {
      lVar12 = *(longlong *)((longlong)param_3 + 0x4e);
      uVar7 = (ulonglong)bVar2;
      iVar4 = *(int *)(param_1 + uVar7 * 0x17 + 0x75);
      if (lVar12 == -1) {
        if (param_1[0x83a] != 0) {
          ViaFreePool((longlong)param_1,0xffffffffffffffff,param_1[0x83a]);
          param_1[0x83a] = 0;
        }
        do {
          if (param_1[uVar7 + 0x83b] != 0) {
            ViaFreePool((longlong)param_1,lVar12,param_1[uVar7 + 0x83b]);
            param_1[uVar7 + 0x83b] = 0;
            param_1[uVar7 * 0x17 + 0x7b] = 0;
            param_1[uVar7 * 0x17 + 0x7a] = 0;
            *(undefined4 *)(param_1 + uVar7 * 0x17 + 0x7c) = 0;
          }
          uVar10 = *(uint *)(param_1 + uVar7 * 0x17 + 0x76);
          if ((uVar10 & 0x1000) != 0) break;
          if (iVar4 == 0) {
            uVar10 = uVar10 >> 8;
          }
          else {
            uVar10 = uVar10 >> 0xe;
          }
          uVar7 = (ulonglong)(uVar10 & 0xf);
        } while ((uVar10 & 0xf) != (uint)bVar2);
      }
      else {
        do {
          uVar10 = *(uint *)(param_1 + uVar7 * 0x17 + 0x76);
          param_1[uVar7 * 0x17 + 0x7b] = lVar12;
          if ((uVar10 & 0x1000) != 0) break;
          if (iVar4 == 0) {
            uVar10 = uVar10 >> 8;
          }
          else {
            uVar10 = uVar10 >> 0xe;
          }
          uVar7 = (ulonglong)(uVar10 & 0xf);
        } while ((uVar10 & 0xf) != (uint)bVar2);
      }
      goto LAB_000301d1;
    }
    if (bVar3 == 0x1e) {
LAB_0002fe4d:
      *(undefined4 *)(param_2 + 0xf8) = 1;
      goto LAB_0002fc12;
    }
    if (bVar3 == 0x1f) {
      if (*(int *)(param_1 + (ulonglong)bVar2 * 0x17 + 0x75) == 5) {
        ParseRaid5Sync((longlong)param_1,param_2,(longlong)param_3);
        return true;
      }
    }
    else {
      if (bVar3 != 0x20) {
        if (bVar3 == 0x21) {
          uVar13 = *(undefined1 *)(param_1 + 0x85b);
          if (*(char *)((longlong)param_3 + 0x4e) != '\0') {
            *(uint *)(param_1 + 0x85b) = (uint)*(byte *)((longlong)param_3 + 0x4f);
          }
        }
        else {
          if (bVar3 == 0x22) {
            *(undefined1 *)(param_1 + 0x843) = *(undefined1 *)((longlong)param_3 + 0x4e);
            goto LAB_0002fe4d;
          }
          if (bVar3 != 0x23) {
            if (bVar3 == 0x25) {
              ParseFullScanDisks((longlong)param_1,param_2,param_3);
              return true;
            }
            goto LAB_00030035;
          }
          uVar13 = *(int *)(param_1 + 0x41) == 0x33491106;
        }
        *(undefined1 *)param_3[3] = uVar13;
        goto LAB_0002fe4d;
      }
      if (*(int *)(param_1 + (ulonglong)bVar2 * 0x17 + 0x75) == 5) {
        ParseRaid5Verify((longlong)param_1,param_2,(longlong)param_3);
        return true;
      }
    }
  }
LAB_0002fc0c:
  *(undefined4 *)(param_2 + 0xf8) = 6;
LAB_0002fc12:
  *(undefined4 *)(param_2 + 0xfc) = 1;
  return true;
}



===== ParseFullScanDisks @ 00030210 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ParseFullScanDisks(longlong param_1,longlong param_2,undefined8 *param_3)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  void *pvVar10;
  undefined8 *puVar11;
  byte bVar12;
  byte bVar13;
  ulonglong uVar14;
  ulonglong *puVar15;
  undefined8 *puVar16;
  undefined1 auStack_78 [32];
  byte local_58;
  byte local_50 [8];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_78;
  bVar13 = 0;
  if ((*(char *)(param_3 + 9) == -1) && (*(char *)((longlong)param_3 + 0x4b) == '%')) {
    lVar9 = param_3[3];
    cVar2 = *(char *)(lVar9 + 2);
    puVar11 = (undefined8 *)CONCAT71((int7)((ulonglong)param_1 >> 8),cVar2);
    if (cVar2 != '\0') {
      bVar12 = 0;
      do {
        if (((ulonglong)puVar11 & 1) != 0) {
          uVar8 = (ulonglong)bVar13;
          bVar13 = bVar13 + 1;
          local_50[uVar8] = bVar12;
        }
        bVar12 = bVar12 + 1;
        puVar11 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar11 >> 8),(byte)puVar11 >> 1);
      } while (bVar12 < 8);
      if (bVar13 == 0) {
LAB_0003028e:
        *(undefined4 *)(param_2 + 0xf8) = 4;
        *(undefined4 *)(param_2 + 0xfc) = 1;
        return;
      }
      puVar15 = (ulonglong *)(lVar9 + 0x12);
      bVar12 = 0;
      if (bVar13 != 0) {
        do {
          bVar3 = local_50[bVar12];
          uVar4 = *(ushort *)(param_1 + 0xab8 + (ulonglong)bVar3 * 2);
          if ((((uVar4 & 1) == 0) || ((uVar4 & 2) != 0)) ||
             (*(char *)((ulonglong)bVar3 * 0xb8 + 0x399 + param_1) != '\0')) goto LAB_0003028e;
          puVar15 = (ulonglong *)((longlong)puVar15 + (longlong)(int)((uint)bVar12 * 9));
          uVar8 = *puVar15;
          lVar9 = (ulonglong)bVar3 * 0xd4;
          uVar14 = CONCAT44(*(undefined4 *)(lVar9 + 0xddc + param_1),
                            *(undefined4 *)(lVar9 + 0xd8c + param_1));
          if ((uVar14 <= uVar8) || (uVar14 < (byte)puVar15[1] + uVar8)) goto LAB_0003028e;
          puVar11 = (undefined8 *)(uVar8 >> 0x20);
          if ((int)(uVar8 >> 0x20) != 0) {
            *(undefined4 *)(param_2 + 0xe98) = 1;
          }
          bVar12 = bVar12 + 1;
        } while (bVar12 < bVar13);
      }
      *(undefined4 *)(param_2 + 0x104) = 0;
      *(undefined4 *)(param_2 + 0xecc) = 1;
      *(byte *)(param_2 + 0xeb2) = local_50[0];
      uVar8 = 0;
      puVar16 = (undefined8 *)(param_3[3] + 0x12);
      if (bVar13 != 0) {
        do {
          local_58 = local_50[uVar8];
          puVar16 = (undefined8 *)((longlong)puVar16 + (longlong)((int)uVar8 * 9));
          bVar12 = *(byte *)(puVar16 + 1);
          uVar7 = *puVar16;
          pvVar10 = StorAllocateSubCmd(puVar11,param_2);
          if (pvVar10 == (void *)0x0) {
            *(undefined4 *)(param_2 + 0xfc) = 2;
            *(undefined1 *)(param_2 + 0x100) = 2;
            return;
          }
          *(undefined1 *)((longlong)pvVar10 + 0x3c) = 1;
          uVar5 = *(undefined4 *)(param_2 + 0x104);
          *(longlong *)((longlong)pvVar10 + 0x10) = param_2;
          *(undefined4 *)((longlong)pvVar10 + 0xa0) = uVar5;
          *(undefined8 *)((longlong)pvVar10 + 0x40) = uVar7;
          *(code **)((longlong)pvVar10 + 0x18) = DispatchUserDiskVerify;
          if (*(int *)(param_2 + 0xe98) != 0) {
            *(undefined4 *)((longlong)pvVar10 + 0x38) = 1;
          }
          puVar11 = (undefined8 *)((longlong)pvVar10 + 0x48);
          if (puVar11 != param_3) {
            *puVar11 = *param_3;
            *(undefined8 *)((longlong)pvVar10 + 0x50) = param_3[1];
            *(undefined8 *)((longlong)pvVar10 + 0x58) = param_3[2];
            *(undefined8 *)((longlong)pvVar10 + 0x60) = param_3[3];
            *(undefined8 *)((longlong)pvVar10 + 0x68) = param_3[4];
            *(undefined8 *)((longlong)pvVar10 + 0x70) = param_3[5];
            *(undefined8 *)((longlong)pvVar10 + 0x78) = param_3[6];
            *(undefined8 *)((longlong)pvVar10 + 0x80) = param_3[7];
            *(undefined8 *)((longlong)pvVar10 + 0x88) = param_3[8];
            *(undefined8 *)((longlong)pvVar10 + 0x90) = param_3[9];
            *(undefined8 *)((longlong)pvVar10 + 0x98) = param_3[10];
          }
          *(undefined8 *)((longlong)pvVar10 + 0x30) = 0;
          *(undefined8 *)((longlong)pvVar10 + 0x60) = 0;
          *(uint *)((longlong)pvVar10 + 0x58) = (uint)bVar12 << 9;
          *(byte *)((longlong)pvVar10 + 0x4e) = local_58;
          if (*(int *)(param_2 + 0xea4) != 0) {
            puVar11 = *(undefined8 **)(*(longlong *)(param_2 + 0xf0) + 0x38);
            puVar11[(ulonglong)*(byte *)(puVar11 + 0x4f) + 0xf] = pvVar10;
            *(char *)(puVar11 + 0x4f) = *(char *)(puVar11 + 0x4f) + '\x01';
          }
          bVar12 = (char)uVar8 + 1;
          uVar8 = (ulonglong)bVar12;
          piVar1 = (int *)(param_2 + 0x10c + (longlong)*(int *)(param_2 + 0x104) * 4);
          *piVar1 = *piVar1 + 1;
        } while (bVar12 < bVar13);
      }
      *(int *)(param_2 + 0x104) = *(int *)(param_2 + 0x104) + 1;
      *(undefined4 *)(param_2 + 0x108) = 0;
      puVar6 = (undefined1 *)param_3[3];
      *(undefined1 **)(param_2 + 0xed0) = puVar6;
      *puVar6 = 0;
      *(undefined8 *)(param_2 + 0xf8) = 0;
      return;
    }
  }
  *(undefined4 *)(param_2 + 0xfc) = 1;
  *(undefined4 *)(param_2 + 0xf8) = 4;
  return;
}



===== StorBuildIo @ 000305a8 =====

undefined1 StorBuildIo(ulonglong *param_1,longlong param_2)

{
  int iVar1;
  longlong *_Dst;
  void *_Dst_00;
  undefined8 uVar2;
  ulonglong *puVar3;
  undefined1 uVar4;
  byte local_res8 [8];
  
  local_res8[0] = 0;
  uVar4 = 1;
  if (param_2 == 0) {
    param_2 = 0;
  }
  else if (param_1 == (ulonglong *)0x0) {
    *(undefined1 *)(param_2 + 3) = 6;
    param_1 = (ulonglong *)0x0;
  }
  else if ((int)param_1[0x41] == 0) {
    *(undefined1 *)(param_2 + 3) = 6;
  }
  else {
    if (*(char *)(param_2 + 2) == '\x17') {
      WmiSrbPro((longlong)param_1,param_2);
      return 0;
    }
    puVar3 = param_1;
    if (*(char *)(param_2 + 2) == '$') {
      if ((*(int *)(param_2 + 8) == 4) && (*(int *)(param_2 + 0x40) - 2U < 5)) {
        *(undefined1 *)((longlong)param_1 + 0x14b6) = 1;
        puVar3 = (ulonglong *)0x6;
        StorPortNotification(6,param_1,0);
      }
    }
    else if (((int)param_1[0x12] == 1) || (*(char *)((longlong)param_1 + 0x61) != '\0')) {
      *(undefined1 *)(param_2 + 3) = 5;
      goto LAB_00030781;
    }
    StorCheckParse(puVar3,param_2,local_res8);
    _Dst = *(longlong **)(param_2 + 0x38);
    if (_Dst != (longlong *)0x0) {
      uVar2 = 0;
      memset(_Dst,0,0x308);
      StorGetSetSrbExtension(_Dst,uVar2,'\0');
      _Dst_00 = (void *)_Dst[3];
      if (_Dst_00 != (void *)0x0) {
        _Dst[0xe] = (longlong)_Dst_00;
        memset(_Dst_00,0,0xf00);
        *(longlong *)((longlong)_Dst_00 + 0xf0) = param_2;
        *(undefined1 *)((longlong)_Dst_00 + 0xeca) = *(undefined1 *)(param_2 + 6);
        *(undefined1 *)(param_2 + 4) = 0;
        *(undefined4 *)((longlong)_Dst_00 + 0xf8) = 0;
        *(undefined4 *)((longlong)_Dst_00 + 0xfc) = 0;
        *(undefined1 *)((longlong)_Dst_00 + 0xeb0) = 1;
        if ((local_res8[0] & 1) != 0) {
          *(undefined4 *)((longlong)_Dst_00 + 0xe9c) = 1;
        }
        *(undefined4 *)((longlong)_Dst_00 + 0xea4) = 1;
        if ((*(uint *)(*(longlong *)((longlong)_Dst_00 + 0xf0) + 0xc) & 0xc0) != 0) {
          if (*(char *)(param_2 + 2) == '\0') {
            uVar2 = StorPortGetScatterGatherList(param_1);
            *(undefined8 *)((longlong)_Dst_00 + 0xe8) = uVar2;
          }
          else {
            *(undefined8 *)((longlong)_Dst_00 + 0xe8) = 0;
          }
        }
        ParseLogicCmd(param_1,(ulonglong)_Dst_00);
        iVar1 = *(int *)((longlong)_Dst_00 + 0xfc);
        if (iVar1 != 0) {
          if (iVar1 == 1) {
            StorIoCompleteLogicCmd(param_1,(longlong)_Dst_00);
          }
          else {
            if (iVar1 != 2) {
              return 1;
            }
            StorPortBusy(param_1,8);
            *(undefined1 *)(param_2 + 3) = 5;
            *(undefined1 *)(param_2 + 6) = *(undefined1 *)((longlong)_Dst_00 + 0xeca);
            StorPortNotification(0,param_1,param_2);
          }
          uVar4 = 0;
        }
        return uVar4;
      }
    }
    *(undefined1 *)(param_2 + 3) = 6;
  }
LAB_00030781:
  StorPortNotification(0,param_1,param_2);
  return 0;
}



===== StorStartIo @ 000307a0 =====

undefined8 StorStartIo(ulonglong *param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  int iVar8;
  ulonglong uVar9;
  byte *pbVar10;
  longlong *_Dst;
  char cVar11;
  ulonglong *puVar12;
  longlong lVar13;
  undefined8 *puVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  byte local_res8;
  undefined4 uVar18;
  undefined1 *in_stack_ffffffffffffff98;
  undefined1 local_48 [32];
  
  uVar7 = 0;
  memset(local_48,0,0x20);
  if (param_2 == 0) {
    param_2 = 0;
  }
  else if (param_1 == (ulonglong *)0x0) {
    *(undefined1 *)(param_2 + 3) = 6;
    param_1 = (ulonglong *)0x0;
  }
  else {
    if ((int)param_1[0x41] != 0) {
      uVar16 = (ulonglong)*(byte *)(param_2 + 6);
      plVar2 = *(longlong **)(param_2 + 0x38);
      local_res8 = (byte)param_1[uVar16 * 5 + 299];
      if (plVar2 != (longlong *)0x0) {
        _Dst = (longlong *)plVar2[0xe];
        if (_Dst == (longlong *)0x0) {
          _Dst = (longlong *)param_1[0x5d];
          if (_Dst != (longlong *)0x0) goto LAB_00030860;
        }
        else {
          if ((*(char *)((longlong)_Dst + 0xeb6) != '\0') &&
             ((int)_Dst[0x1d7] != *(int *)((longlong)param_1 + uVar16 * 4 + 700))) {
LAB_00030860:
            ReInitSrbExtension(plVar2);
            StorGetSetSrbExtension(plVar2,uVar7,'\0');
            plVar2[0xe] = (longlong)_Dst;
            memset(_Dst,0,0xf00);
            _Dst[0x1e] = param_2;
            *(undefined1 *)((longlong)_Dst + 0xeca) = *(undefined1 *)(param_2 + 6);
            *(undefined1 *)(param_2 + 4) = 0;
            _Dst[0x1f] = 0;
            *(undefined1 *)(_Dst + 0x1d6) = 2;
            *(undefined4 *)((longlong)_Dst + 0xea4) = 1;
            if ((*(uint *)(_Dst[0x1e] + 0xc) & 0xc0) != 0) {
              if (*(char *)(param_2 + 2) == '\0') {
                lVar6 = StorPortGetScatterGatherList(param_1);
                _Dst[0x1d] = lVar6;
              }
              else {
                _Dst[0x1d] = 0;
              }
            }
            ParseLogicCmd(param_1,(ulonglong)_Dst);
            iVar8 = *(int *)((longlong)_Dst + 0xfc);
            if (iVar8 == 0) goto LAB_00030916;
            if (iVar8 != 1) {
              if (iVar8 == 2) {
                *(undefined1 *)((longlong)_Dst + 0xebd) = 1;
              }
              goto LAB_00030916;
            }
            goto LAB_000308fa;
          }
LAB_00030916:
          lVar6 = *(longlong *)(param_2 + 0x38);
          _Dst = *(longlong **)(lVar6 + 0x70);
          if (_Dst != (longlong *)0x0) {
            *(undefined1 *)(_Dst + 0x1d6) = 2;
            if (*(char *)((longlong)_Dst + 0xeb1) != '\0') {
              local_res8 = *(byte *)((longlong)_Dst + 0xeb2);
              uVar16 = (ulonglong)local_res8;
            }
            if (*(char *)((longlong)_Dst + 0xec9) != '\0') {
              uVar16 = (ulonglong)*(byte *)((longlong)_Dst + 0xecb);
              local_res8 = (byte)param_1[uVar16 * 5 + 299];
            }
            if (*(char *)((longlong)_Dst + 0xeb3) != '\0') {
              if (*(char *)((longlong)_Dst + 0xeb4) == '\0') {
                *(undefined1 *)((longlong)param_1 + 0x41cc) = 1;
              }
              else {
                uVar9 = (ulonglong)*(byte *)(*(longlong *)(param_2 + 0x18) + 0x25);
                uVar15 = param_1[uVar9 * 0x17 + 0x76];
                *(undefined1 *)((longlong)param_1 + 0x41cc) = 0;
                uVar5 = ((uint)uVar15 & 0xf) + 1;
                if (uVar5 != 0) {
                  uVar15 = (ulonglong)uVar5;
                  do {
                    uVar17 = uVar9 & 0xff;
                    if (param_1[uVar17 + 0x83b] != 0) {
                      ViaFreePool((longlong)param_1,uVar9,param_1[uVar17 + 0x83b]);
                      param_1[uVar17 + 0x83b] = 0;
                    }
                    if (*(char *)((longlong)_Dst + 0xeb5) != '\0') {
                      param_1[uVar17 * 0x17 + 0x7d] = 0;
                      *(undefined1 *)(uVar17 * 0xb8 + 0x3ad + (longlong)param_1) = 0;
                    }
                    uVar9 = (ulonglong)
                            CONCAT31((uint3)(param_1[uVar17 * 0x17 + 0x76] >> 8) >> 0xe,
                                     (char)((uint)param_1[uVar17 * 0x17 + 0x76] >> 0xe)) &
                            0xffffffffffffff0f;
                    uVar15 = uVar15 - 1;
                  } while (uVar15 != 0);
                }
              }
            }
            if (((int)param_1[0x12] == 1) || (*(char *)((longlong)param_1 + 0x61) != '\0')) {
              *(undefined1 *)(param_2 + 3) = 5;
              *(undefined1 *)(param_2 + 6) = *(undefined1 *)((longlong)_Dst + 0xeca);
              goto LAB_00030ec8;
            }
            if ((*(char *)(lVar6 + 0x278) != '\0') || (*(char *)((longlong)_Dst + 0xebc) != '\0')) {
              iVar8 = 0;
              lVar13 = 0;
              puVar12 = param_1 + 0x157;
              pbVar10 = (byte *)((longlong)param_1 + 0x39a);
              do {
                if ((3 < *pbVar10) && ((*puVar12 & 1) != 0)) break;
                lVar13 = lVar13 + 1;
                iVar8 = iVar8 + 1;
                puVar12 = (ulonglong *)((longlong)puVar12 + 2);
                pbVar10 = pbVar10 + 0xb8;
              } while (lVar13 < 8);
              if ((7 < iVar8) ||
                 (uVar15 = PreParseLogicCmd((longlong)param_1,(longlong)_Dst,puVar12),
                 (char)uVar15 != '\0')) {
                if (Hibernate == '\0') {
                  in_stack_ffffffffffffff98 = local_48;
                  StorPortNotification(0x1003,param_1,3,0,in_stack_ffffffffffffff98);
                }
                if ((char)_Dst[0x1d9] != '\0') {
                  StorClearWaitLogicCmd((longlong)param_1,'\x01');
                }
                if ((*(char *)((longlong)param_1 + 0x254) == '\0') &&
                   (*(char *)((longlong)_Dst + 0xebd) == '\0')) {
                  if (*(int *)((longlong)_Dst + 0xe9c) != 0) {
                    if ((int)param_1[0x56] < 1) {
                      iVar8 = 0;
                      lVar13 = 0;
                      puVar12 = param_1 + 0x52;
                      do {
                        if ((int)*puVar12 != 0) break;
                        lVar13 = lVar13 + 1;
                        iVar8 = iVar8 + 1;
                        puVar12 = (ulonglong *)((longlong)puVar12 + 4);
                      } while (lVar13 < 8);
                      if ((7 < iVar8) &&
                         (cVar3 = StorLockCtrlrSrv_SpinLock((longlong)param_1,lVar13,'\x01'),
                         cVar3 != '\0')) goto LAB_00030c42;
                    }
                    AddListEntryToTail((longlong *)(param_1 + 0x51),_Dst);
                    *(int *)((longlong)param_1 + 0x2b4) = *(int *)((longlong)param_1 + 0x2b4) + 1;
                    *(int *)(param_1 + 0x56) = (int)param_1[0x56] + 1;
                    *(int *)(param_1 + 0x57) = (int)param_1[0x57] + 1;
                    goto LAB_00030b46;
                  }
                  if (0 < (int)param_1[0x56]) {
LAB_00030bbd:
                    AddListEntryToTail((longlong *)(param_1 + 0x51),_Dst);
                    *(int *)((longlong)param_1 + 0x2b4) = *(int *)((longlong)param_1 + 0x2b4) + 1;
                    piVar1 = (int *)((longlong)param_1 + uVar16 * 4 + 0x290);
                    *piVar1 = *piVar1 + 1;
                    *(int *)(param_1 + 0x57) = (int)param_1[0x57] + 1;
                    uVar18 = *(undefined4 *)((longlong)param_1 + uVar16 * 4 + 0x290);
                    goto LAB_00030bee;
                  }
                  if (local_res8 == 0xff) {
                    bVar4 = 0;
                    do {
                      uVar15 = (ulonglong)bVar4;
                      if (*(char *)(uVar15 + 0x2dc + (longlong)param_1) != '\0') goto LAB_00030bbd;
                      bVar4 = bVar4 + 1;
                      *(undefined1 *)(uVar15 + 0x2dc + (longlong)param_1) = 1;
                    } while (bVar4 < 8);
                  }
                  else {
                    if (*(char *)((ulonglong)local_res8 + 0x2dc + (longlong)param_1) != '\0')
                    goto LAB_00030bbd;
                    *(undefined1 *)((ulonglong)local_res8 + 0x2dc + (longlong)param_1) = 1;
                  }
LAB_00030c42:
                  if (*(char *)((longlong)_Dst + 0xebc) == '\0') {
                    if (*(char *)((longlong)_Dst + 0xee1) != '\0') {
                      lVar13 = _Dst[0x1e];
                      uVar15 = _Dst[0x1df];
                      plVar2 = *(longlong **)(lVar13 + 0x38);
                      uVar9 = param_1[(ulonglong)
                                      (byte)param_1[(ulonglong)*(byte *)(lVar13 + 6) * 5 + 299] *
                                      0x17 + 0x7a];
                      if ((uVar15 != uVar9) &&
                         ((((ulonglong)_Dst[0x1dd] <= uVar9 && (uVar15 <= (ulonglong)_Dst[0x1dd]))
                          || (((ulonglong)_Dst[0x1de] <= uVar9 && (uVar15 <= (ulonglong)_Dst[0x1de])
                              ))))) {
                        *(undefined1 *)(lVar13 + 6) = *(undefined1 *)((longlong)_Dst + 0xeca);
                        ReInitSrbExtension(plVar2);
                        StorGetSetSrbExtension(plVar2,uVar9,'\x01');
                        puVar12 = param_1;
                        ReleaseTmpCmdBufs((longlong)param_1,(longlong)_Dst);
                        plVar2[0xe] = (longlong)_Dst;
                        ReInitLogicCmd(puVar12,_Dst,lVar13);
                        lVar13 = _Dst[0x1e];
                        uVar18 = *(undefined4 *)
                                  ((longlong)param_1 + (ulonglong)*(byte *)(lVar13 + 6) * 4 + 700);
                        *(undefined1 *)(_Dst + 0x1d6) = 2;
                        *(undefined4 *)((longlong)_Dst + 0xea4) = 1;
                        *(undefined4 *)(_Dst + 0x1d7) = uVar18;
                        if ((*(uint *)(lVar13 + 0xc) & 0xc0) != 0) {
                          if (*(char *)(lVar13 + 2) == '\0') {
                            lVar13 = StorPortGetScatterGatherList(param_1);
                            _Dst[0x1d] = lVar13;
                          }
                          else {
                            _Dst[0x1d] = 0;
                          }
                        }
                        ParseLogicCmd(param_1,(ulonglong)_Dst);
                      }
                    }
                    param_1[uVar16 + 0x8f5] = (ulonglong)_Dst;
                    *(int *)(param_1 + 0x50) = (int)param_1[0x50] + 1;
                    if ((char)_Dst[0x1d9] != '\0') {
                      *(undefined4 *)(param_1 + 0x12) = 1;
                    }
                    iVar8 = 0;
                    if (*(char *)(lVar6 + 0x278) != '\0') {
                      puVar14 = (undefined8 *)(lVar6 + 0x78);
                      do {
                        bVar4 = *(byte *)((longlong)*puVar14 + 0x4e) >> 1;
                        if (bVar4 < 4) {
                          uVar15 = (ulonglong)bVar4;
                          AddListEntryToTail((longlong *)(param_1 + uVar15 + 0x5f),
                                             (longlong *)*puVar14);
                          piVar1 = (int *)((longlong)param_1 + uVar15 * 4 + 0x32c);
                          *piVar1 = *piVar1 + 1;
                        }
                        iVar8 = iVar8 + 1;
                        puVar14 = puVar14 + 1;
                      } while (iVar8 < (int)(uint)*(byte *)(lVar6 + 0x278));
                    }
                    uVar7 = StorDispatchSubCmds((longlong)param_1,(byte)uVar16 >> 1,'\x01');
                  }
                  else {
                    uVar7 = AtapiResetController((longlong)param_1);
                    if ((char)uVar7 == '\0') {
                      StorPortLogError(param_1,0,0,0,
                                       (ulonglong)in_stack_ffffffffffffff98 & 0xffffffffffffff00,6,
                                       0x500);
                      *(undefined4 *)(_Dst + 0x1f) = 4;
                    }
                    else {
                      *(undefined4 *)(_Dst + 0x1f) = 1;
                    }
                    param_1[0x8fd] = 0;
                    if (*(char *)((longlong)param_1 + 0x254) != '\0') {
                      *(undefined1 *)((longlong)param_1 + 0x254) = 0;
                    }
                    *(char *)(param_2 + 3) = (char)_Dst[0x1f];
                    *(undefined1 *)(param_2 + 6) = *(undefined1 *)((longlong)_Dst + 0xeca);
                    uVar7 = StorPortNotification(0,param_1,param_2);
                  }
                }
                else {
                  AddListEntryToTail((longlong *)(param_1 + 0x51),_Dst);
                  *(int *)((longlong)param_1 + 0x2b4) = *(int *)((longlong)param_1 + 0x2b4) + 1;
                  *(int *)(param_1 + 0x57) = (int)param_1[0x57] + 1;
                  if (*(int *)((longlong)_Dst + 0xe9c) == 0) {
                    piVar1 = (int *)((longlong)param_1 + uVar16 * 4 + 0x290);
                    *piVar1 = *piVar1 + 1;
                  }
                  else {
                    *(int *)(param_1 + 0x56) = (int)param_1[0x56] + 1;
                  }
                  if (*(int *)((longlong)_Dst + 0xe9c) == 0) {
                    uVar18 = *(undefined4 *)((longlong)param_1 + uVar16 * 4 + 0x290);
LAB_00030bee:
                    uVar7 = StorPortDeviceBusy(param_1,*(undefined1 *)(param_2 + 5),uVar16,
                                               *(undefined1 *)(param_2 + 7),uVar18);
                  }
                  else {
LAB_00030b46:
                    uVar7 = StorPortBusy(param_1,8);
                  }
                }
                if (Hibernate == '\0') {
                  uVar7 = StorPortNotification(0x1004,param_1,local_48);
                }
                goto LAB_00030ed0;
              }
              *(undefined4 *)(_Dst + 0x1f) = 5;
              cVar3 = *(char *)(lVar6 + 0x278);
              cVar11 = '\0';
              if (cVar3 != '\0') {
                cVar11 = cVar3;
              }
              *(char *)(lVar6 + 0x278) = cVar3 - cVar11;
            }
LAB_000308fa:
            uVar7 = StorIoCompleteLogicCmd(param_1,(longlong)_Dst);
            goto LAB_00030ed0;
          }
        }
      }
    }
    *(undefined1 *)(param_2 + 3) = 6;
  }
LAB_00030ec8:
  uVar7 = StorPortNotification(0,param_1,param_2);
LAB_00030ed0:
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
}



===== StorDispatchSubCmds @ 00030ef0 =====

void StorDispatchSubCmds(longlong param_1,byte param_2,char param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong *plVar4;
  longlong lVar5;
  uint uVar6;
  char cVar7;
  undefined1 local_38 [32];
  
  memset(local_38,0,0x20);
  if (0xfa < (byte)(param_2 - 4)) {
    uVar6 = (uint)param_2;
    if (param_3 != '\0') {
      uVar6 = 0;
    }
    if (uVar6 < 4) {
      lVar5 = (longlong)(int)uVar6;
      do {
        if ((param_3 == '\0') && (uVar6 != param_2)) {
          return;
        }
        plVar1 = *(longlong **)(param_1 + 0x2f8 + lVar5 * 8);
        if ((plVar1 != (longlong *)0x0) &&
           (plVar4 = plVar1, *(longlong *)(param_1 + 0x340 + lVar5 * 8) == 0)) {
          do {
            lVar2 = plVar4[2];
            if ((int)plVar4[0x14] == *(int *)(lVar2 + 0x108)) {
              if ((((*(int *)(lVar2 + 0xea0) != 0) || (param_3 == '\0')) ||
                  (*(char *)(lVar2 + 0xeb1) != '\0')) ||
                 ((*(char *)(lVar2 + 0xec9) != '\0' ||
                  (param_2 == *(byte *)(*(longlong *)(lVar2 + 0xf0) + 6) >> 1)))) {
                *(undefined1 *)(lVar2 + 0xeb0) = 3;
                *(longlong **)(param_1 + 0x340 + lVar5 * 8) = plVar4;
                if (*(char *)(lVar2 + 0xeb0) == '\x03') {
                  RemoveSubCmdFromChnl(param_1,plVar4);
                }
                else {
                  if (Hibernate == '\0') {
                    StorPortNotification(0x1003,param_1,3,0,local_38);
                  }
                  cVar7 = Hibernate;
                  RemoveSubCmdFromChnl(param_1,plVar4);
                  if (cVar7 == '\0') {
                    StorPortNotification(0x1004,param_1,local_38);
                  }
                }
                (*(code *)plVar4[3])(param_1,plVar4);
                if (*(char *)((longlong)plVar4 + 0x4b) != '\0') {
                  uVar3 = StorCompleteSubCmd((ulonglong *)param_1,(longlong)plVar4,3);
                  if ((char)uVar3 == '\0') {
                    uVar6 = uVar6 - 1;
                    lVar5 = lVar5 + -1;
                  }
                  else {
                    uVar6 = 0xffffffff;
                    param_2 = 0xff;
                    lVar5 = -1;
                  }
                }
              }
              break;
            }
            plVar4 = (longlong *)*plVar4;
          } while (plVar4 != plVar1);
        }
        uVar6 = uVar6 + 1;
        lVar5 = lVar5 + 1;
      } while ((int)uVar6 < 4);
    }
  }
  return;
}



===== StorCompleteLogicCmd @ 000310b0 =====

void StorCompleteLogicCmd(ulonglong *param_1,longlong *param_2,undefined8 param_3)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  byte bVar9;
  
  lVar2 = param_2[0x1e];
  bVar9 = *(byte *)(lVar2 + 6);
  if (*(char *)((longlong)param_2 + 0xeb1) != '\0') {
    bVar9 = *(byte *)((longlong)param_2 + 0xeb2);
  }
  if (*(char *)((longlong)param_2 + 0xec9) != '\0') {
    bVar9 = *(byte *)((longlong)param_2 + 0xecb);
  }
  if ((int)param_2[0x1f] == 0) {
    *(undefined4 *)(param_2 + 0x1f) = 1;
  }
  *(char *)(lVar2 + 3) = (char)param_2[0x1f];
  lVar4 = param_2[0x1d9];
  if (*(char *)((longlong)param_2 + 0xebe) == '\0') {
    ReleaseTmpCmdBufs((longlong)param_1,(longlong)param_2);
    bVar5 = *(byte *)(param_2[0x1e] + 6);
    if (*(char *)((longlong)param_2 + 0xeb1) != '\0') {
      bVar5 = *(byte *)((longlong)param_2 + 0xeb2);
    }
    if (*(char *)((longlong)param_2 + 0xec9) != '\0') {
      bVar5 = *(byte *)((longlong)param_2 + 0xecb);
    }
    if ((byte)((char)param_2[0x1d6] - 2U) < 2) {
      param_1[(ulonglong)bVar5 + 0x8f5] = 0;
    }
    bVar5 = (byte)param_1[(ulonglong)*(byte *)(param_2[0x1e] + 6) * 5 + 299];
    if (*(char *)((longlong)param_2 + 0xeb1) != '\0') {
      bVar5 = *(byte *)((longlong)param_2 + 0xeb2);
    }
    if (*(char *)((longlong)param_2 + 0xec9) != '\0') {
      bVar5 = (byte)param_1[(ulonglong)bVar9 * 5 + 299];
    }
    if (*(int *)((longlong)param_2 + 0xe9c) == 0) {
      if ((int)param_2[0x1d4] != 0) {
        piVar1 = (int *)((longlong)param_1 + (ulonglong)bVar9 * 4 + 0x290);
        *piVar1 = *piVar1 + -1;
        *(int *)((longlong)param_1 + 0x2b4) = *(int *)((longlong)param_1 + 0x2b4) + -1;
      }
      uVar7 = CONCAT71((int7)((ulonglong)param_3 >> 8),bVar5);
      StorLockRaidArraySrv((longlong)param_1,(longlong)param_2,bVar5,'\0');
    }
    else {
      if ((int)param_2[0x1d4] != 0) {
        *(int *)(param_1 + 0x56) = (int)param_1[0x56] + -1;
        *(int *)((longlong)param_1 + 0x2b4) = *(int *)((longlong)param_1 + 0x2b4) + -1;
      }
      uVar7 = 0;
      StorLockCtrlrSrv((longlong)param_1,(longlong)param_2,'\0');
    }
    *(int *)(param_1 + 0x50) = (int)param_1[0x50] + -1;
    uVar6 = (ulonglong)bVar5;
    bVar5 = *(byte *)(uVar6 + 0x948 + (longlong)param_1);
    uVar8 = CONCAT71((int7)((ulonglong)uVar7 >> 8),bVar5) & 0xffffffffffffff02;
    if (((((bVar5 & 2) != 0) || ((bVar5 & 4) != 0)) &&
        ((*(byte *)((longlong)param_1 + uVar6 * 2 + 0xab8) & 2) != 0)) &&
       ((*(byte *)(lVar2 + 3) & 1) != 0)) {
      *(undefined1 *)(uVar6 + 0xad8 + (longlong)param_1) = 0;
    }
    if (((*(char *)((longlong)param_2 + 0xebf) != '\0') &&
        (((bVar5 & 2 & (byte)uVar8) != 0 || ((bVar5 & 4) != 0)))) &&
       (*(char *)(uVar6 + 0xad8 + (longlong)param_1) != '\0')) {
      StorPortPauseDevice(param_1,*(undefined1 *)(lVar2 + 5),
                          CONCAT71((int7)(uVar8 >> 8),*(undefined1 *)(lVar2 + 6)),
                          *(undefined1 *)(lVar2 + 7),0x14);
    }
    lVar3 = *(longlong *)(lVar2 + 0x38);
    if ((lVar3 != 0) && (*(int *)(lVar3 + 0x27c) == 1)) {
      *(undefined8 *)(lVar2 + 0x18) = *(undefined8 *)(lVar3 + 0x280);
      *(undefined4 *)(lVar3 + 0x27c) = 0;
    }
    *(undefined1 *)(lVar2 + 6) = *(undefined1 *)((longlong)param_2 + 0xeca);
    StorPortNotification(0,param_1,lVar2);
    StorPortNotification(1,param_1,bVar9 >> 1);
    if ((char)lVar4 == '\0') {
      StorDequeueLogicCmd(param_1,'\0');
    }
    else {
      StorClearSubCmd((longlong)param_1);
      StorClearLogicCmd((longlong)param_1);
      StorClearWaitLogicCmd((longlong)param_1,'\x01');
    }
  }
  else {
    StorDeleteLogicCmd((longlong)param_1,param_2);
  }
  return;
}



===== StorIoCompleteLogicCmd @ 00031324 =====

void StorIoCompleteLogicCmd(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  byte bVar2;
  
  if (*(longlong *)(param_2 + 0x10) != 0) {
    param_2 = *(longlong *)(param_2 + 0x10);
  }
  lVar1 = *(longlong *)(param_2 + 0xf0);
  bVar2 = *(byte *)(lVar1 + 6);
  if (*(char *)(param_2 + 0xeb1) != '\0') {
    bVar2 = *(byte *)(param_2 + 0xeb2);
  }
  *(undefined1 *)(lVar1 + 3) = *(undefined1 *)(param_2 + 0xf8);
  *(undefined1 *)(lVar1 + 6) = *(undefined1 *)(param_2 + 0xeca);
  StorPortNotification(0,param_1);
                    /* WARNING: Could not recover jumptable at 0x0003138e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(1,param_1,bVar2 >> 1);
  return;
}



===== StorCompleteSubCmd @ 00031398 =====

longlong StorCompleteSubCmd(ulonglong *param_1,longlong param_2,undefined1 param_3)

{
  char *pcVar1;
  int *piVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  longlong *plVar6;
  byte *pbVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  code *pcVar12;
  
  bVar3 = *(byte *)(param_2 + 0x4e);
  plVar6 = *(longlong **)(param_2 + 0x10);
  *(undefined1 *)(plVar6 + 0x1d6) = param_3;
  uVar10 = (ulonglong)*(byte *)(param_2 + 0x4e);
  if ((*(byte *)((longlong)param_1 + uVar10 * 2 + 0xab8) & 2) != 0) {
    if ((*(char *)(uVar10 + 0x2e + (longlong)param_1) == '\x01') &&
       (*(char *)(param_2 + 0x90) == '\0')) {
      if (*(char *)(param_2 + 0x4b) == '\x01') {
        *(undefined1 *)(uVar10 + 0x2e + (longlong)param_1) = 0;
      }
      else {
        *(undefined2 *)(param_2 + 0x4b) = 1;
      }
    }
    if ((*(char *)(param_2 + 0x90) == '\x04') &&
       (*(char *)((ulonglong)*(byte *)(param_2 + 0x4e) + 0x2e + (longlong)param_1) == '\0')) {
      *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x4e) + 0x2e + (longlong)param_1) = 1;
    }
  }
  uVar10 = (ulonglong)(bVar3 >> 1);
  param_1[uVar10 + 0x869] = 0;
  *(undefined1 *)(uVar10 + 0x42dc + (longlong)param_1) = 0;
  *(undefined4 *)((longlong)param_1 + uVar10 * 4 + 0x42e0) = 0;
  param_1[uVar10 + 0x85f] = 0;
  *(undefined1 *)(uVar10 + 0x4344 + (longlong)param_1) = 0;
  *(undefined1 *)(uVar10 + 0x250 + (longlong)param_1) = 0;
  *(undefined1 *)(uVar10 + 0x4668 + (longlong)param_1) = 0;
  if ((*(char *)(param_2 + 0x4b) == '\x01') ||
     (uVar11 = (ulonglong)bVar3, (*(byte *)((longlong)param_1 + uVar11 * 2 + 0xab8) & 1) == 0)) {
    *(undefined1 *)((ulonglong)bVar3 * 0xb8 + 0x39a + (longlong)param_1) = 0;
  }
  else {
    cVar4 = *(char *)(uVar11 * 0xb8 + 0x39a + (longlong)param_1);
    if (cVar4 != -1) {
      *(char *)(uVar11 * 0xb8 + 0x39a + (longlong)param_1) = cVar4 + '\x01';
    }
    if ((uint)param_1[uVar11 * 0x17 + 0x7f] < 0xfffffff0) {
      *(uint *)(param_1 + uVar11 * 0x17 + 0x7f) = (uint)param_1[uVar11 * 0x17 + 0x7f] + 1;
    }
  }
  if ((*(char *)(param_2 + 0x3c) != '\0') && (*(char *)(param_2 + 0x4b) != '\x01')) {
    pbVar7 = *(byte **)(*(longlong *)(param_2 + 0x10) + 0xed0);
    *pbVar7 = *pbVar7 | '\x01' << (*(byte *)(param_2 + 0x4e) & 0x1f);
  }
  if (*(char *)(param_2 + 0xbc) == '\0') {
    if (*(char *)(param_2 + 0x3c) == '\0') {
      *(undefined1 *)(plVar6[0x1e] + 4) = *(undefined1 *)(param_2 + 0x4c);
      if (((1 < *(byte *)(param_2 + 0x4b)) && ((*(uint *)(plVar6 + 0x1f) & 0xfffffffa) == 0)) &&
         (*(uint *)(plVar6 + 0x1f) != 4)) {
        *(uint *)(plVar6 + 0x1f) = (uint)*(byte *)(param_2 + 0x4b);
      }
    }
    else {
      *(undefined1 *)(plVar6[0x1e] + 4) = 0;
      *(undefined4 *)(plVar6 + 0x1f) = 1;
    }
  }
  pcVar1 = (char *)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0xf0) + 0x38) +
                   0x278);
  *pcVar1 = *pcVar1 + -1;
  param_1[uVar10 + 0x68] = 0;
  lVar9 = plVar6[0x21];
  piVar2 = (int *)((longlong)plVar6 + (longlong)(int)lVar9 * 4 + 0x10c);
  *piVar2 = *piVar2 + -1;
  iVar5 = *(int *)((longlong)plVar6 + (longlong)(int)lVar9 * 4 + 0x10c);
  if (iVar5 < 1) {
    pcVar12 = (code *)plVar6[(longlong)(int)plVar6[0x21] + 0x2c];
    if (pcVar12 != (code *)0x0) {
      (*pcVar12)(param_1,plVar6);
    }
    if ((int)plVar6[0x21] == *(int *)((longlong)plVar6 + 0x104) + -1) {
      uVar10 = StorCompleteLogicCmd(param_1,plVar6,pcVar12);
    }
    else {
      uVar8 = (int)plVar6[0x21] + 1;
      uVar10 = (ulonglong)uVar8;
      *(uint *)(plVar6 + 0x21) = uVar8;
    }
    lVar9 = CONCAT71((int7)(uVar10 >> 8),1);
  }
  else {
    lVar9 = (ulonglong)(uint3)((uint)iVar5 >> 8) << 8;
  }
  return lVar9;
}



===== StorDeleteLogicCmd @ 000315ac =====

void StorDeleteLogicCmd(longlong param_1,longlong *param_2)

{
  int *piVar1;
  byte bVar2;
  longlong *plVar3;
  byte bVar4;
  
  bVar4 = *(byte *)(param_2[0x1e] + 6);
  if (*(char *)((longlong)param_2 + 0xeb1) != '\0') {
    bVar4 = *(byte *)((longlong)param_2 + 0xeb2);
  }
  if (*(char *)((longlong)param_2 + 0xec9) != '\0') {
    bVar4 = *(byte *)((longlong)param_2 + 0xecb);
  }
  ReleaseTmpCmdBufs(param_1,(longlong)param_2);
  bVar2 = *(byte *)(param_2[0x1e] + 6);
  if (*(char *)((longlong)param_2 + 0xeb1) != '\0') {
    bVar2 = *(byte *)((longlong)param_2 + 0xeb2);
  }
  if (*(char *)((longlong)param_2 + 0xec9) != '\0') {
    bVar2 = *(byte *)((longlong)param_2 + 0xecb);
  }
  if ((byte)((char)param_2[0x1d6] - 2U) < 2) {
    *(undefined8 *)(param_1 + 0x47a8 + (ulonglong)bVar2 * 8) = 0;
  }
  plVar3 = (longlong *)(param_1 + 0x288);
  *(undefined1 *)((longlong)param_2 + 0xebe) = 0;
  if (plVar3 != (longlong *)0x0) {
    AddListEntryToTail(plVar3,param_2);
    *plVar3 = (longlong)param_2;
  }
  *(int *)(param_1 + 0x2b4) = *(int *)(param_1 + 0x2b4) + 1;
  *(int *)(param_1 + 0x2b8) = *(int *)(param_1 + 0x2b8) + 1;
  if (*(int *)((longlong)param_2 + 0xe9c) == 0) {
    piVar1 = (int *)(param_1 + 0x290 + (ulonglong)bVar4 * 4);
    *piVar1 = *piVar1 + 1;
  }
  else {
    *(int *)(param_1 + 0x2b0) = *(int *)(param_1 + 0x2b0) + 1;
  }
  bVar2 = *(byte *)(param_1 + 0x958 + (ulonglong)*(byte *)(param_2[0x1e] + 6) * 0x28);
  if (*(char *)((longlong)param_2 + 0xeb1) != '\0') {
    bVar2 = *(byte *)((longlong)param_2 + 0xeb2);
  }
  if (*(char *)((longlong)param_2 + 0xec9) != '\0') {
    bVar2 = *(byte *)(param_1 + 0x958 + (ulonglong)bVar4 * 0x28);
  }
  if (*(int *)((longlong)param_2 + 0xe9c) == 0) {
    if ((int)param_2[0x1d4] != 0) {
      piVar1 = (int *)(param_1 + 0x290 + (ulonglong)bVar4 * 4);
      *piVar1 = *piVar1 + -1;
      *(int *)(param_1 + 0x2b4) = *(int *)(param_1 + 0x2b4) + -1;
    }
    StorLockRaidArraySrv(param_1,(longlong)param_2,bVar2,'\0');
  }
  else {
    if ((int)param_2[0x1d4] != 0) {
      *(int *)(param_1 + 0x2b0) = *(int *)(param_1 + 0x2b0) + -1;
      *(int *)(param_1 + 0x2b4) = *(int *)(param_1 + 0x2b4) + -1;
    }
    StorLockCtrlrSrv(param_1,(longlong)param_2,'\0');
  }
  *(int *)(param_1 + 0x280) = *(int *)(param_1 + 0x280) + -1;
  return;
}



===== StorCompleteSubCmdEx @ 0003172c =====

void StorCompleteSubCmdEx(ulonglong *param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  longlong lVar5;
  undefined8 uVar6;
  char cVar7;
  
  lVar5 = *(longlong *)(param_2 + 0x10);
  bVar1 = *(byte *)(param_2 + 0x4e);
  cVar7 = '\0';
  cVar2 = *(char *)(lVar5 + 0xeb1);
  bVar3 = *(byte *)(*(longlong *)(lVar5 + 0xf0) + 6);
  if (*(char *)(lVar5 + 0xec9) != '\0') {
    bVar3 = *(byte *)(lVar5 + 0xecb);
  }
  bVar4 = *(byte *)(lVar5 + 0xeb2);
  uVar6 = StorCompleteSubCmd(param_1,param_2,3);
  if ((char)uVar6 != '\0') {
    bVar1 = bVar3;
    if (cVar2 != '\0') {
      bVar1 = bVar4;
    }
    cVar7 = '\x01';
  }
  StorDispatchSubCmds((longlong)param_1,bVar1 >> 1,cVar7);
  return;
}



===== StorClearSubCmd @ 000317c8 =====

void StorClearSubCmd(longlong param_1)

{
  undefined1 *puVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  longlong lVar4;
  
  puVar1 = (undefined1 *)(param_1 + 0x4344);
  puVar3 = (undefined4 *)(param_1 + 0x42e0);
  puVar2 = (undefined8 *)(param_1 + 0x340);
  lVar4 = 4;
  do {
    puVar2[-9] = 0;
    puVar3[-0xfed] = 0;
    *puVar2 = 0;
    puVar2[0x801] = 0;
    puVar1[-0x68] = 0;
    *puVar3 = 0;
    puVar2[0x7f7] = 0;
    *puVar1 = 0;
    puVar1[-0x40f4] = 0;
    puVar1[0x324] = 0;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}



===== StorClearLogicCmd @ 0003182c =====

void StorClearLogicCmd(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  
  lVar4 = 0;
  plVar5 = (longlong *)(param_1 + 0x47a8);
  do {
    *(undefined1 *)(param_1 + 0x2dc + lVar4) = 0;
    lVar2 = *plVar5;
    if (lVar2 != 0) {
      lVar3 = *(longlong *)(lVar2 + 0xf0);
      bVar1 = *(byte *)(lVar3 + 6);
      *(undefined2 *)(lVar3 + 3) = 0xe;
      *plVar5 = 0;
      *(undefined1 *)(lVar3 + 6) = *(undefined1 *)(lVar2 + 0xeca);
      StorPortNotification(0,param_1);
      StorPortNotification(1,param_1,bVar1 >> 1);
    }
    lVar4 = lVar4 + 1;
    plVar5 = plVar5 + 1;
  } while (lVar4 < 8);
  *(undefined1 *)(param_1 + 0x254) = 0;
  return;
}



===== StorClearWaitLogicCmd @ 000318c8 =====

void StorClearWaitLogicCmd(longlong param_1,char param_2)

{
  int *piVar1;
  longlong lVar2;
  byte bVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined1 local_38 [32];
  
  if (((*(longlong *)(param_1 + 0x47e8) != 0) && (param_2 == '\0')) && (Hibernate == '\0')) {
    StorPortNotification(0x1003,param_1,3,0,local_38);
  }
  puVar4 = *(undefined8 **)(param_1 + 0x288);
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x2b8)) {
    do {
      if (puVar4 == (undefined8 *)0x0) break;
      lVar2 = puVar4[0x1e];
      bVar3 = *(byte *)(lVar2 + 6);
      if (*(char *)((longlong)puVar4 + 0xeb1) != '\0') {
        bVar3 = *(byte *)((longlong)puVar4 + 0xeb2);
      }
      if (*(char *)((longlong)puVar4 + 0xec9) != '\0') {
        bVar3 = *(byte *)((longlong)puVar4 + 0xecb);
      }
      *(undefined2 *)(lVar2 + 3) = 5;
      if (*(int *)(*(longlong *)(lVar2 + 0x38) + 0x27c) != 0) {
        *(undefined8 *)(lVar2 + 0x18) = *(undefined8 *)(*(longlong *)(lVar2 + 0x38) + 0x280);
      }
      *(undefined1 *)(lVar2 + 6) = *(undefined1 *)((longlong)puVar4 + 0xeca);
      *(int *)(param_1 + 0x2b4) = *(int *)(param_1 + 0x2b4) + -1;
      if (*(int *)((longlong)puVar4 + 0xe9c) == 0) {
        piVar1 = (int *)(param_1 + 0x290 + (ulonglong)bVar3 * 4);
        *piVar1 = *piVar1 + -1;
      }
      else {
        *(int *)(param_1 + 0x2b0) = *(int *)(param_1 + 0x2b0) + -1;
      }
      if (*(char *)((longlong)puVar4 + 0xebc) != '\0') {
        *(undefined8 *)(param_1 + 0x47e8) = 0;
      }
      puVar4 = (undefined8 *)*puVar4;
      StorPortNotification(0,param_1);
      StorPortNotification(1,param_1,bVar3 >> 1);
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0x2b8));
  }
  *(undefined4 *)(param_1 + 0x2b8) = 0;
  *(undefined8 *)(param_1 + 0x288) = 0;
  if (((*(longlong *)(param_1 + 0x47e8) != 0) && (param_2 == '\0')) && (Hibernate == '\0')) {
    StorPortNotification(0x1004,param_1,local_38);
  }
  return;
}



===== StorLockCtrlrSrv @ 00031a48 =====

bool StorLockCtrlrSrv(longlong param_1,longlong param_2,char param_3)

{
  bool bVar1;
  longlong *plVar2;
  longlong lVar3;
  char local_res10 [8];
  char local_res20 [8];
  undefined1 local_28 [8];
  char *local_20;
  char *local_10;
  
  local_res10[0] = '\0';
  if ((param_2 == 0) || ((byte)(*(char *)(param_2 + 0xeb0) - 1U) < 2)) {
    local_res20[0] = param_3;
    memset(local_28,0,0x20);
    local_20 = local_res20;
    local_10 = local_res10;
    local_28[0] = 1;
    StorPortSynchronizeAccess(param_1,&StorSyncAccessDevExt,local_28);
    return local_res10[0] != '\0';
  }
  if (*(char *)(param_2 + 0xeb0) == '\x03') {
    if (*(char *)(param_1 + 0x254) == '\0') {
      if (param_3 != '\x01') goto LAB_00031aaf;
      lVar3 = 0;
      plVar2 = (longlong *)(param_1 + 0x47a8);
      do {
        if (*plVar2 != 0) goto LAB_00031aaf;
        lVar3 = lVar3 + 1;
        plVar2 = plVar2 + 1;
      } while (lVar3 < 8);
      *(undefined1 *)(param_1 + 0x254) = 1;
    }
    else {
      if (param_3 != '\0') goto LAB_00031aaf;
      *(undefined1 *)(param_1 + 0x254) = 0;
    }
    bVar1 = true;
  }
  else {
LAB_00031aaf:
    bVar1 = false;
  }
  return bVar1;
}



===== StorLockRaidArraySrv @ 00031b18 =====

bool StorLockRaidArraySrv(longlong param_1,longlong param_2,byte param_3,char param_4)

{
  bool bVar1;
  byte bVar2;
  ulonglong uVar3;
  bool bVar4;
  char local_res10 [8];
  char local_res18 [8];
  byte local_38 [8];
  undefined1 local_30 [8];
  char *local_28;
  byte *local_20;
  char *local_18;
  
  local_res18[0] = '\0';
  if ((byte)(*(char *)(param_2 + 0xeb0) - 1U) < 2) {
    local_res10[0] = param_4;
    local_38[0] = param_3;
    memset(local_30,0,0x20);
    local_28 = local_res10;
    local_20 = local_38;
    local_18 = local_res18;
    local_30[0] = 3;
    StorPortSynchronizeAccess(param_1,&StorSyncAccessDevExt,local_30);
    return local_res18[0] != '\0';
  }
  if (*(char *)(param_2 + 0xeb0) == '\x03') {
    bVar4 = param_4 == '\x01';
    if (param_3 == 0xff) {
      bVar2 = 0;
      do {
        uVar3 = (ulonglong)bVar2;
        bVar1 = bVar4;
        if (*(char *)(uVar3 + 0x2dc + param_1) == '\0') {
          bVar1 = !bVar4;
        }
        if (bVar1) goto LAB_00031b98;
        bVar2 = bVar2 + 1;
        *(bool *)(uVar3 + 0x2dc + param_1) = bVar4;
      } while (bVar2 < 8);
    }
    else {
      bVar1 = bVar4;
      if (*(char *)((ulonglong)param_3 + 0x2dc + param_1) != '\0') {
        bVar1 = !bVar4;
      }
      if (!bVar1) goto LAB_00031b98;
      *(bool *)((ulonglong)param_3 + 0x2dc + param_1) = bVar4;
    }
    bVar4 = true;
  }
  else {
LAB_00031b98:
    bVar4 = false;
  }
  return bVar4;
}



===== StorLockCtrlrSrv_SpinLock @ 00031c1c =====

char StorLockCtrlrSrv_SpinLock(longlong param_1,undefined8 param_2,char param_3)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  
  cVar1 = *(char *)(param_1 + 0x254);
  if (param_3 != '\x03') {
    if (cVar1 == '\0') {
      if (param_3 == '\x01') {
        lVar3 = 0;
        plVar2 = (longlong *)(param_1 + 0x47a8);
        while (*plVar2 == 0) {
          lVar3 = lVar3 + 1;
          plVar2 = plVar2 + 1;
          if (7 < lVar3) {
            *(undefined1 *)(param_1 + 0x254) = 1;
            return '\x01';
          }
        }
      }
    }
    else if (param_3 == '\0') {
      *(undefined1 *)(param_1 + 0x254) = 0;
      return '\x01';
    }
    cVar1 = '\0';
  }
  return cVar1;
}



===== StorGetSetSrbExtension @ 00031da8 =====

int StorGetSetSrbExtension(longlong *param_1,undefined8 param_2,char param_3)

{
  longlong *_Dst;
  int iVar1;
  
  _Dst = (longlong *)0x0;
  iVar1 = 0x308;
  if (param_1 == (longlong *)0x0) {
    iVar1 = 0x16a0;
  }
  else {
    *param_1 = (longlong)(param_1 + 0x61);
    param_1[3] = (longlong)(param_1 + 0xf4);
    if (param_3 == '\0') {
      memset(param_1 + 0xf4,0,0xf00);
    }
    _Dst = param_1 + 0x2d4;
  }
  if (param_1 == (longlong *)0x0) {
    iVar1 = iVar1 + 0x2928;
  }
  else {
    param_1[10] = (longlong)_Dst;
    memset(_Dst,0,0x1e00);
    param_1[0xb] = (longlong)(_Dst + 0x3c0);
    *(undefined4 *)(param_1 + 0xd) = 0x22;
    memset(_Dst + 0x3c0,0,0xb28);
  }
  return iVar1;
}



===== StorCheckParse @ 00031e70 =====

bool StorCheckParse(undefined8 param_1,longlong param_2,byte *param_3)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_2 + 2);
  if (cVar1 != '\0') {
    if (cVar1 == '\x02') {
      lVar2 = *(longlong *)(param_2 + 0x18);
      iVar3 = AtapiStringCmp(lVar2 + 4,(byte *)"SCSIDISK",8);
      if ((iVar3 == 0) && (*(int *)(lVar2 + 0x10) == 0x1b0800)) {
        *param_3 = *param_3 | 1;
      }
    }
    else {
      if ((((cVar1 != '\a') && (cVar1 != '\b')) && (cVar1 != '\x10')) && (cVar1 != '\x12')) {
        *param_3 = *param_3 | 1;
        return cVar1 == '$';
      }
      *param_3 = *param_3 | 1;
    }
  }
  return true;
}



===== StorAllocateSubCmd @ 00031eec =====

void * StorAllocateSubCmd(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  void *_Dst;
  
  if (*(int *)(param_2 + 0xea4) == 0) {
    _Dst = (void *)0x0;
  }
  else {
    lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xf0) + 0x38);
    _Dst = (void *)((ulonglong)*(byte *)(lVar1 + 0x278) * 0xc0 + *(longlong *)(lVar1 + 0x50));
    memset(_Dst,0,0xc0);
  }
  return _Dst;
}



===== StorAllocateMultiPool @ 00031f38 =====

void StorAllocateMultiPool(longlong param_1,int param_2,longlong param_3)

{
  longlong lVar1;
  char cVar2;
  char cVar3;
  
  cVar3 = '\0';
  if (0 < param_2) {
    do {
      lVar1 = (longlong)cVar3;
      cVar2 = *(char *)(param_1 + 0x279) + cVar3;
      cVar3 = cVar3 + '\x01';
      *(char *)(lVar1 + param_3) = cVar2;
    } while (cVar3 < param_2);
  }
  *(char *)(param_1 + 0x279) = *(char *)(param_1 + 0x279) + (char)param_2;
  return;
}



===== StorAllocateSubCmdWithBuf @ 00031f78 =====

void * StorAllocateSubCmdWithBuf(longlong param_1)

{
  void *_Dst;
  byte bVar1;
  ulonglong uVar2;
  void *_Dst_00;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 0x279);
  if ((bVar1 + 1 < 0x29) && (*(byte *)(param_1 + 0x279) = bVar1 + 1, bVar1 != 0xffffffff)) {
    uVar2 = 1;
    iVar3 = 0;
    do {
      if ((uVar2 & *(ulonglong *)(param_1 + 0x60)) == 0) {
        *(ulonglong *)(param_1 + 0x60) = *(ulonglong *)(param_1 + 0x60) | uVar2;
        goto LAB_00031fcd;
      }
      iVar3 = iVar3 + 1;
      uVar2 = uVar2 * 2;
    } while (iVar3 < 0x15);
    iVar3 = -1;
LAB_00031fcd:
    if (iVar3 != -1) {
      _Dst_00 = (void *)((ulonglong)bVar1 * 0xc0 + *(longlong *)(param_1 + 0x50));
      memset(_Dst_00,0,0xc0);
      _Dst = (void *)(*(longlong *)(param_1 + 0x58) +
                     (ulonglong)(uint)(*(int *)(param_1 + 0x68) * iVar3) * 4);
      *(void **)((longlong)_Dst_00 + 0x30) = _Dst;
      memset(_Dst,0,(ulonglong)*(uint *)(param_1 + 0x68) << 2);
      return _Dst_00;
    }
  }
  return (void *)0x0;
}



===== StorDequeueLogicCmd @ 00032028 =====

void StorDequeueLogicCmd(ulonglong *param_1,char param_2)

{
  ulonglong *puVar1;
  int *piVar2;
  undefined4 uVar3;
  longlong *plVar4;
  bool bVar5;
  byte bVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong *puVar9;
  longlong *plVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  longlong *plVar14;
  int iVar15;
  
  if ((char)param_1[0x65] != '\0') {
    return;
  }
  if (0 < (int)param_1[0x57]) {
    plVar4 = (longlong *)param_1[0x51];
    if (plVar4 == (longlong *)0x0) {
      return;
    }
    if (*(char *)((longlong)plVar4 + 0xebc) != '\0') {
      lVar8 = plVar4[0x1d6];
      *(undefined1 *)(plVar4 + 0x1d6) = 3;
      if (((int)param_1[0x50] != 0) ||
         (bVar5 = StorLockCtrlrSrv((longlong)param_1,(longlong)plVar4,'\x01'), !bVar5)) {
        *(char *)(plVar4 + 0x1d6) = (char)lVar8;
        return;
      }
      uVar7 = AtapiResetController((longlong)param_1);
      if ((char)uVar7 == '\0') {
        StorPortLogError(param_1,0,0,0,0,6,0x500);
        *(undefined4 *)(plVar4 + 0x1f) = 4;
      }
      else {
        *(undefined4 *)(plVar4 + 0x1f) = 1;
      }
      param_1[0x8fd] = 0;
      *(char *)(plVar4[0x1e] + 3) = (char)plVar4[0x1f];
      plVar10 = plVar4;
      RemoveListEntry((longlong *)(param_1 + 0x51),plVar4);
      *(int *)((longlong)param_1 + 0x2b4) = *(int *)((longlong)param_1 + 0x2b4) + -1;
      *(int *)(param_1 + 0x56) = (int)param_1[0x56] + -1;
      *(int *)(param_1 + 0x57) = (int)param_1[0x57] + -1;
      StorLockCtrlrSrv((longlong)param_1,(longlong)plVar10,'\0');
      *(undefined1 *)(plVar4[0x1e] + 6) = *(undefined1 *)((longlong)plVar4 + 0xeca);
      StorPortNotification(0,param_1,plVar4[0x1e]);
    }
  }
  if ((int)param_1[0x57] < 1) {
    return;
  }
  puVar1 = param_1 + 0x51;
  plVar4 = (longlong *)*puVar1;
  if (plVar4 == (longlong *)0x0) {
    return;
  }
  lVar8 = plVar4[0x1e];
  uVar12 = (ulonglong)*(byte *)(lVar8 + 6);
  plVar10 = *(longlong **)(lVar8 + 0x38);
  bVar6 = (byte)param_1[uVar12 * 5 + 299];
  if (*(char *)((longlong)plVar4 + 0xeb1) != '\0') {
    bVar6 = *(byte *)((longlong)plVar4 + 0xeb2);
    uVar12 = (ulonglong)bVar6;
  }
  if (*(char *)((longlong)plVar4 + 0xec9) != '\0') {
    uVar12 = (ulonglong)*(byte *)((longlong)plVar4 + 0xecb);
    bVar6 = (byte)param_1[uVar12 * 5 + 299];
  }
  if (*(char *)((longlong)plVar4 + 0xee1) != '\0') {
    uVar13 = plVar4[0x1df];
    uVar11 = param_1[(ulonglong)(byte)param_1[(ulonglong)*(byte *)(lVar8 + 6) * 5 + 299] * 0x17 +
                     0x7a];
    if ((uVar13 != uVar11) &&
       ((((ulonglong)plVar4[0x1dd] <= uVar11 && (uVar13 <= (ulonglong)plVar4[0x1dd])) ||
        (((ulonglong)plVar4[0x1de] <= uVar11 && (uVar13 <= (ulonglong)plVar4[0x1de])))))) {
      *(undefined1 *)(lVar8 + 6) = *(undefined1 *)((longlong)plVar4 + 0xeca);
      ReInitSrbExtension(plVar10);
      StorGetSetSrbExtension(plVar10,uVar11,'\x01');
      puVar9 = param_1;
      ReleaseTmpCmdBufs((longlong)param_1,(longlong)plVar4);
      plVar10[0xe] = (longlong)plVar4;
      ReInitLogicCmd(puVar9,plVar4,lVar8);
      lVar8 = plVar4[0x1e];
      uVar3 = *(undefined4 *)((longlong)param_1 + (ulonglong)*(byte *)(lVar8 + 6) * 4 + 700);
      *(undefined1 *)(plVar4 + 0x1d6) = 2;
      *(undefined4 *)((longlong)plVar4 + 0xea4) = 1;
      *(undefined4 *)(plVar4 + 0x1d7) = uVar3;
      if ((*(uint *)(lVar8 + 0xc) & 0xc0) != 0) {
        if (*(char *)(lVar8 + 2) == '\0') {
          lVar8 = StorPortGetScatterGatherList(param_1);
          plVar4[0x1d] = lVar8;
        }
        else {
          plVar4[0x1d] = 0;
        }
      }
      ParseLogicCmd(param_1,(ulonglong)plVar4);
    }
  }
  lVar8 = plVar4[0x1d6];
  *(undefined1 *)(plVar4 + 0x1d6) = 3;
  if (*(int *)((longlong)plVar4 + 0xe9c) != 0) {
    if ((int)param_1[0x50] == 0) {
      bVar5 = StorLockCtrlrSrv((longlong)param_1,(longlong)plVar4,'\x01');
      if (bVar5) {
        iVar15 = 0;
        param_1[uVar12 + 0x8f5] = (ulonglong)plVar4;
        if ((char)plVar10[0x4f] != '\0') {
          plVar14 = plVar10 + 0xf;
          do {
            bVar6 = *(byte *)(*plVar14 + 0x4e) >> 1;
            if (bVar6 < 4) {
              uVar13 = (ulonglong)bVar6;
              AddListEntryToTail((longlong *)(param_1 + uVar13 + 0x5f),(longlong *)*plVar14);
              piVar2 = (int *)((longlong)param_1 + uVar13 * 4 + 0x32c);
              *piVar2 = *piVar2 + 1;
            }
            iVar15 = iVar15 + 1;
            plVar14 = plVar14 + 1;
          } while (iVar15 < (int)(uint)*(byte *)(plVar10 + 0x4f));
        }
        RemoveListEntry((longlong *)puVar1,plVar4);
        *(undefined4 *)(plVar4 + 0x1d4) = 1;
        *(int *)(param_1 + 0x50) = (int)param_1[0x50] + 1;
        *(int *)(param_1 + 0x57) = (int)param_1[0x57] + -1;
        goto joined_r0x00032456;
      }
      goto LAB_0003246b;
    }
    if (*(int *)((longlong)plVar4 + 0xe9c) != 0) goto LAB_0003246b;
  }
  bVar5 = StorLockRaidArraySrv((longlong)param_1,(longlong)plVar4,bVar6,'\x01');
  if (bVar5) {
    iVar15 = 0;
    param_1[uVar12 + 0x8f5] = (ulonglong)plVar4;
    if ((char)plVar10[0x4f] != '\0') {
      plVar14 = plVar10 + 0xf;
      do {
        bVar6 = *(byte *)(*plVar14 + 0x4e) >> 1;
        if (bVar6 < 4) {
          uVar13 = (ulonglong)bVar6;
          AddListEntryToTail((longlong *)(param_1 + uVar13 + 0x5f),(longlong *)*plVar14);
          piVar2 = (int *)((longlong)param_1 + uVar13 * 4 + 0x32c);
          *piVar2 = *piVar2 + 1;
        }
        iVar15 = iVar15 + 1;
        plVar14 = plVar14 + 1;
      } while (iVar15 < (int)(uint)*(byte *)(plVar10 + 0x4f));
    }
    RemoveListEntry((longlong *)puVar1,plVar4);
    *(undefined4 *)(plVar4 + 0x1d4) = 1;
    *(int *)(param_1 + 0x50) = (int)param_1[0x50] + 1;
    *(int *)(param_1 + 0x57) = (int)param_1[0x57] + -1;
joined_r0x00032456:
    if (param_2 == '\0') {
      return;
    }
    StorDispatchSubCmds((longlong)param_1,(byte)uVar12 >> 1,'\x01');
    return;
  }
LAB_0003246b:
  *(char *)(plVar4 + 0x1d6) = (char)lVar8;
  return;
}



===== QueryWmiRegInfo @ 00032490 =====

undefined8 QueryWmiRegInfo(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  DbgPrint("\nFunction QueryWmiRegInfo entry\n");
  *param_3 = L"MofResource";
  uVar1 = DbgPrint("\nFunction QueryWmiRegInfo return\n");
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== SwitchOfFunctionControl @ 000324c8 =====

undefined1 SwitchOfFunctionControl(undefined8 param_1,longlong param_2,undefined4 param_3)

{
  DbgPrint("\nFunction SwitchOfFunctionControl entry\n");
  DbgPrint("\n-------GuidIndex = %d\n",param_3);
  ScsiPortWmiPostProcess(param_2);
  DbgPrint("\nFunction SwitchOfFunctionControl return\n");
  return 1;
}



===== QueryWmiDataBlock @ 00032518 =====

undefined1 QueryWmiDataBlock(undefined8 param_1,longlong param_2,undefined4 param_3)

{
  DbgPrint("\nFunction QueryWmiDataBlock entry\n");
  DbgPrint("\n-------GuidIndex = %d\n",param_3);
  ScsiPortWmiPostProcess(param_2);
  DbgPrint("\nFunction QueryWmiDataBlock return\n");
  return 1;
}



===== WmiSrbPro @ 00032568 =====

undefined8 WmiSrbPro(longlong param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  undefined8 uVar3;
  uint uVar4;
  uint local_res10 [2];
  int local_res18 [4];
  undefined1 local_38 [8];
  uint local_30;
  uint *local_28;
  byte local_20;
  char local_1f;
  uint local_1c;
  
  DbgPrint("\nFunction WmiSrbPro entry\n");
  memset(local_38,0,0x20);
  if ((*(byte *)(param_2 + 9) & 1) == 0) {
    *(undefined1 *)(param_2 + 3) = 1;
    uVar4 = 0;
  }
  else {
    bVar1 = *(byte *)(param_2 + 4);
    local_res10[0] = 0;
    local_1c = 0;
    if (bVar1 < 10) {
      local_30 = *(uint *)(param_2 + 0x10);
      local_28 = *(uint **)(param_2 + 0x18);
      local_20 = bVar1;
      cVar2 = ScsiWmipProcessRequest
                        (*(uint **)(param_1 + 0x4840),bVar1,param_1,local_38,
                         *(longlong **)(param_2 + 0x20),*(uint *)(param_2 + 0x10),
                         *(uint **)(param_2 + 0x18),local_res10,(short *)local_res18);
      if (local_res18[0] == 1) {
        local_1c = local_res10[0];
        if (cVar2 != '\x01') {
          local_1c = 0;
        }
        local_1f = cVar2;
      }
    }
    else {
      local_1f = '\x04';
    }
    *(char *)(param_2 + 3) = local_1f;
    uVar4 = local_1c;
  }
  *(uint *)(param_2 + 0x10) = uVar4;
  StorPortNotification(0,param_1,param_2);
  StorPortNotification(1,param_1);
  uVar3 = DbgPrint("\nFunction WmiSrbPro return\n");
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== entry @ 00032670 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint entry(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  uint uVar5;
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
  undefined1 local_7c;
  code *local_60;
  code *local_58;
  
  __security_init_cookie();
  _g_DrvObj = param_1;
  if (param_1 == 0) {
    Hibernate = '\x01';
  }
  else {
    puVar2 = (undefined8 *)&DeviceExt;
    do {
      puVar2 = puVar2 + 1;
      *puVar2 = 0;
    } while ((longlong)puVar2 < 0x36460);
  }
  _adapterCount = 0;
  uVar5 = 0xffffffff;
  memset(&local_d8,0,0xd0);
  local_a8 = 0;
  local_a0 = 0;
  local_d8 = 0xd0;
  local_94 = 4;
  local_d0 = AtapiHwInitialize;
  local_d4 = 5;
  local_b0 = AtapiResetController;
  local_80 = 0x1010102;
  local_c0 = ViaInterrupt;
  local_7c = 1;
  local_60 = AtapiPnp;
  local_b8 = AtapiFindNativePCIController;
  local_58 = StorBuildIo;
  local_c8 = StorStartIo;
  uVar3 = 0;
  GLOBALCOUNTER = 0;
  do {
    local_8c = (&DAT_00034150)[uVar3 * 10];
    local_90 = 0x3fc8;
    uVar4 = 0x6398;
    if (Hibernate == '\0') {
      uVar4 = 0x6438;
    }
    DbgPrint("totally need 0x%x bytes for deviceExt memory\n",uVar4);
    local_98 = uVar4;
    uVar1 = StorPortInitialize(param_1,param_2,&local_d8,&adapterCount);
    if (uVar1 < uVar5) {
      uVar5 = uVar1;
    }
    GLOBALCOUNTER = GLOBALCOUNTER + 1;
    uVar3 = (ulonglong)GLOBALCOUNTER;
  } while (GLOBALCOUNTER < 7);
  return uVar5;
}



===== __report_gsfailure @ 000327f0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ScsiPortWmiPostProcess @ 000327f8 =====

void ScsiPortWmiPostProcess(longlong param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  uint *puVar7;
  undefined1 uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  
  cVar1 = *(char *)(param_1 + 0x18);
  uVar2 = *(uint *)(param_1 + 8);
  puVar4 = *(uint **)(param_1 + 0x10);
  uVar10 = 0;
  uVar8 = 1;
  if (cVar1 == '\0') {
    uVar9 = puVar4[0xc];
    uVar3 = puVar4[0xd];
    uVar11 = (ulonglong)uVar3;
    if (uVar2 < uVar9) {
      uVar8 = 0x12;
      if (0x37 < uVar2) {
        *puVar4 = 0x38;
        puVar4[0xb] = 0x20;
        uVar8 = 1;
        uVar10 = 0x38;
      }
    }
    else if (((0x2f < uVar2) && (*puVar4 = uVar9, uVar10 = uVar9, (char)puVar4[0xb] < '\0')) &&
            (puVar7 = puVar4 + 0xf, uVar6 = uVar11, uVar3 != 0)) {
      do {
        uVar5 = (int)uVar6 - 1;
        uVar6 = (ulonglong)uVar5;
        if (uVar6 * 8 + 0x48 <= (ulonglong)uVar2) {
          puVar4[uVar6 * 2 + 0x10] = puVar7[uVar6];
        }
      } while (uVar5 != 0);
      if (uVar3 != 0) {
        uVar6 = 0x48;
        do {
          if (uVar6 <= uVar2) {
            *puVar7 = uVar9;
            uVar9 = uVar9 + 7 + puVar7[1] & 0xfffffff8;
          }
          uVar6 = uVar6 + 8;
          puVar7 = puVar7 + 2;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
    }
  }
  else if (cVar1 == '\x01') {
    if (0x2f < uVar2) {
      *puVar4 = puVar4[0xe];
      uVar10 = puVar4[0xe];
    }
  }
  else if ((cVar1 == '\t') && (0x47 < uVar2)) {
    puVar4[0x10] = 0;
    *puVar4 = puVar4[0xf];
    uVar10 = puVar4[0xf];
  }
  *(undefined1 *)(param_1 + 0x19) = uVar8;
  *(uint *)(param_1 + 0x1c) = uVar10;
  return;
}



===== ScsiWmipProcessRequest @ 0003291c =====

char ScsiWmipProcessRequest
               (uint *param_1,byte param_2,undefined8 param_3,undefined8 param_4,longlong *param_5,
               uint param_6,uint *param_7,uint *param_8,short *param_9)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  short *psVar4;
  char cVar5;
  uint uVar6;
  code *pcVar7;
  uint uVar8;
  longlong *plVar9;
  ulonglong *puVar10;
  undefined2 *puVar11;
  int iVar12;
  longlong lVar13;
  uint *puVar14;
  ushort uVar15;
  uint uVar16;
  uint uVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  undefined4 uVar20;
  
  puVar14 = (uint *)0x0;
  psVar4 = param_9;
  psVar4[0] = 0;
  psVar4[1] = 0;
  uVar6 = 0;
  uVar19 = 0;
  uVar16 = 0;
  if (param_2 != 8) {
    if (*param_1 != 0) {
      plVar9 = *(longlong **)(param_1 + 2);
      do {
        if ((*param_5 == *(longlong *)*plVar9) && (param_5[1] == ((longlong *)*plVar9)[1])) {
          uVar16 = *(uint *)(*(longlong **)(param_1 + 2) + uVar19 * 2 + 1);
          if (((2 < (byte)(param_2 - 1)) && (param_2 != 9)) ||
             ((uVar6 = param_7[0xd], -1 < (char)param_7[0xb] || (uVar6 < uVar16))))
          goto LAB_000329ec;
          break;
        }
        uVar16 = (int)uVar19 + 1;
        uVar19 = (ulonglong)uVar16;
        plVar9 = plVar9 + 2;
      } while (uVar16 < *param_1);
    }
    *param_8 = 0;
    cVar5 = '\x04';
    goto LAB_00032d1e;
  }
LAB_000329ec:
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (0x47 < param_6) {
          param_7[0xb] = param_7[0xb] & 0xffffffef;
          param_7[0xd] = uVar16;
          uVar6 = uVar16 * 8 + 0x40;
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
          goto LAB_00032b39;
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
          lVar13 = (longlong)param_7 + (ulonglong)param_7[0xe];
          iVar12 = param_6 - param_7[0xe];
          puVar14 = param_7 + 0xf;
          uVar16 = 1;
LAB_00032b39:
          cVar5 = (**(code **)(param_1 + 6))
                            (param_3,param_4,uVar19,uVar6,uVar16,puVar14,iVar12,lVar13);
          return cVar5;
        }
        if (param_2 == 2) {
          if (*(code **)(param_1 + 8) != (code *)0x0) {
            cVar5 = (**(code **)(param_1 + 8))
                              (param_3,param_4,uVar19,uVar6,param_7[0xf],
                               (ulonglong)param_7[0xe] + (longlong)param_7);
            return cVar5;
          }
        }
        else if (param_2 == 3) {
          if (*(code **)(param_1 + 10) != (code *)0x0) {
            cVar5 = (**(code **)(param_1 + 10))
                              (param_3,param_4,uVar19,uVar6,param_7[0xe],param_7[0x10],
                               (ulonglong)param_7[0xf] + (longlong)param_7);
            return cVar5;
          }
        }
        else if (param_2 == 4) {
          pcVar7 = *(code **)(param_1 + 0xe);
          if (pcVar7 != (code *)0x0) {
            uVar18 = 0;
            goto LAB_00032d41;
          }
          goto LAB_00032d52;
        }
      }
LAB_00032a61:
      cVar5 = '\x04';
      goto LAB_00032d55;
    }
    pcVar7 = *(code **)(param_1 + 0xe);
    if (pcVar7 != (code *)0x0) {
      uVar20 = 0;
      uVar18 = 0;
      goto LAB_00032d46;
    }
  }
  else if (param_2 == 6) {
    pcVar7 = *(code **)(param_1 + 0xe);
    if (pcVar7 != (code *)0x0) {
      uVar18 = 1;
LAB_00032d41:
      uVar20 = 1;
LAB_00032d46:
      cVar5 = (*pcVar7)(param_3,param_4,uVar19,uVar18,uVar20);
      return cVar5;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (((param_2 == 9) && (*(code **)(param_1 + 0xc) != (code *)0x0)) && (0x47 < param_6)) {
          uVar16 = param_7[0xf];
          if (uVar16 <= param_6) {
            cVar5 = (**(code **)(param_1 + 0xc))
                              (param_3,param_4,uVar19,uVar6,param_7[0xe],param_7[0x10],
                               param_6 - uVar16,(longlong)param_7 + (ulonglong)uVar16);
            return cVar5;
          }
        }
        goto LAB_00032a61;
      }
      cVar5 = (**(code **)(param_1 + 4))(param_3,param_4,&param_9);
      if (cVar5 == '\x01') {
        uVar6 = *param_1;
        uVar19 = (ulonglong)uVar6;
        lVar13 = *(longlong *)(param_1 + 2);
        uVar17 = uVar6 * 0x20 + 0x18;
        uVar16 = uVar6 * 0x20 + 0x34;
        if (param_9 == (short *)0x0) {
          uVar15 = 0;
        }
        else {
          uVar15 = 0;
          sVar2 = *param_9;
          while (sVar2 != 0) {
            uVar15 = uVar15 + 1;
            sVar2 = param_9[uVar15];
          }
          uVar15 = uVar15 * 2;
        }
        uVar8 = uVar15 + uVar16;
        if ((uVar8 < uVar16) || (uVar1 = uVar8 + 2, uVar1 < uVar8)) {
          cVar5 = '\x04';
          goto LAB_00032d0f;
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
          param_7[3] = uVar16;
          param_7[4] = uVar6;
          if (uVar6 != 0) {
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
                *puVar10 = (ulonglong)uVar17;
                *(uint *)((longlong)puVar10 + -4) = puVar14[-1];
              }
              puVar10 = puVar10 + 4;
              puVar14 = puVar14 + 4;
              uVar19 = uVar19 - 1;
            } while (uVar19 != 0);
          }
          puVar11 = (undefined2 *)((ulonglong)uVar17 + (longlong)param_7);
          *puVar11 = 0x1a;
          memcpy(puVar11 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar16 + (longlong)param_7) = uVar15;
          memcpy((ushort *)((ulonglong)uVar16 + (longlong)param_7) + 1,param_9,(ulonglong)uVar15);
          param_6 = uVar1;
        }
      }
      else {
LAB_00032d0f:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_00032d1e:
      psVar4[0] = 1;
      psVar4[1] = 0;
      return cVar5;
    }
    pcVar7 = *(code **)(param_1 + 0xe);
    if (pcVar7 != (code *)0x0) {
      uVar20 = 0;
      uVar18 = 1;
      goto LAB_00032d46;
    }
  }
LAB_00032d52:
  cVar5 = '\x01';
LAB_00032d55:
  psVar4[0] = 1;
  psVar4[1] = 0;
  return cVar5;
}



===== __security_check_cookie @ 00032d90 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== rand @ 00032db0 =====

int __cdecl rand(void)

{
  DAT_00036000 = DAT_00036000 * 0x343fd + 0x269ec3;
  return DAT_00036000 >> 0x10 & 0x7fff;
}



===== srand @ 00032dd0 =====

void __cdecl srand(uint _Seed)

{
  DAT_00036000 = _Seed;
  return;
}



===== __GSHandlerCheck @ 00032dd8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 00032df8 =====

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



===== memcmp @ 00032e70 =====

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
      bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)(lVar3 + (longlong)_Buf1);
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)(lVar3 + (longlong)_Buf1)) goto LAB_00032eb3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)(lVar3 + (longlong)_Buf1)) goto LAB_00032f24;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)(lVar3 + 8 + (longlong)_Buf1)) {
LAB_00032f20:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_00032f24;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)(lVar3 + 0x10 + (longlong)_Buf1)) {
LAB_00032f1c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_00032f20;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)(lVar3 + 0x18 + (longlong)_Buf1)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_00032f1c;
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
          if (uVar2 != *(ulonglong *)(lVar3 + (longlong)_Buf1)) {
LAB_00032f24:
            uVar4 = *(ulonglong *)((longlong)_Buf1 + lVar3);
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
    bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)(lVar3 + (longlong)_Buf1);
    if ((byte)*(ulonglong *)_Buf1 != *(byte *)(lVar3 + (longlong)_Buf1)) break;
    _Buf1 = (void *)((longlong)_Buf1 + 1);
    _Size = _Size - 1;
  }
LAB_00032eb3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== _guard_check_icall @ 00032f40 =====

void _guard_check_icall(void)

{
  return;
}



===== memcpy @ 00032f80 =====

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
        if (uVar12 == 0) goto LAB_00033137;
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
LAB_00033137:
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
      if (uVar12 == 0) goto LAB_00032f92;
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
LAB_00032f92:
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



===== memset @ 000332c0 =====

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
      if (uVar5 == 0) goto LAB_00033380;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_0003337d_caseD_2;
      case 3:
        goto switchD_0003337d_caseD_3;
      case 4:
        goto switchD_0003337d_caseD_4;
      case 5:
        goto switchD_0003337d_caseD_5;
      case 6:
        goto switchD_0003337d_caseD_6;
      case 7:
        goto switchD_0003337d_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_00033380:
        *puVar3 = uVar4;
switchD_0003337d_caseD_7:
        puVar3[1] = uVar4;
switchD_0003337d_caseD_6:
        puVar3[2] = uVar4;
switchD_0003337d_caseD_5:
        puVar3[3] = uVar4;
switchD_0003337d_caseD_4:
        puVar3[4] = uVar4;
switchD_0003337d_caseD_3:
        puVar3[5] = uVar4;
switchD_0003337d_caseD_2:
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



===== __security_init_cookie @ 00038000 =====

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


