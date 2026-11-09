
===== EHCI_GetErrorFromTD @ 140001008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_GetErrorFromTD(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(uint *)(param_3 + 8);
  (*DAT_140016440)(param_1,0x10000001,0x4454655f,uVar1,param_3,0);
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 0x10) != 0) {
      (*DAT_140016440)(param_1,0x10000001,0x32706d5f,0,0,0);
      return 0xc0000012;
    }
    if ((uVar1 & 0x20) != 0) {
      (*DAT_140016440)(param_1,0x10000001,0x33706d5f,0,0,0);
      return 0xc0000013;
    }
    if ((uVar1 & 4) == 0) {
      (*DAT_140016440)(param_1,0x10000001,0x34706d5f,0,0,0);
      return 0xc0000004;
    }
    uVar2 = 0x36706d5f;
  }
  else {
    uVar2 = 0x31706d5f;
  }
  (*DAT_140016440)(param_1,0x10000001,uVar2,0,0,0);
  return 0xc0000011;
}



===== EHCI_PollEndpoint @ 1400010e0 =====

void EHCI_PollEndpoint(longlong param_1,longlong param_2)

{
  int iVar1;
  
  if ((*(uint *)(param_2 + 0x80) & 2) == 0) {
    iVar1 = *(int *)(param_2 + 0x3c);
    if (iVar1 == 0) {
      EHCI_PollIsoEndpoint(param_1,param_2);
    }
    else {
      if (iVar1 == 1) {
        EHCI_PollControlEndpoint(param_1,param_2);
        return;
      }
      if ((iVar1 == 2) || (iVar1 == 3)) {
        EHCI_sMode_PollEndpoint(param_1,param_2);
      }
    }
  }
  else if (*(int *)(param_2 + 0x3c) == 0) {
    EHCI_PollResetIsoEndpoint(param_1,param_2);
  }
  return;
}



===== EHCI_PollIsoEndpoint @ 140001140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_PollIsoEndpoint(longlong param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  
  if (*(longlong *)(param_1 + 200) == 0) {
    iVar2 = -1;
  }
  else {
    uVar1 = *(uint *)(*(longlong *)(param_1 + 200) + 0xc) >> 3;
    iVar2 = (uVar1 & 0x3ff | *(uint *)(param_1 + 0x130)) +
            ((uVar1 & 0x7ff ^ *(uint *)(param_1 + 0x130)) & 0x400);
  }
  (*DAT_140016440)(param_1,0x10000001,0x6c70695f,0,0,iVar2);
  if (*(longlong **)(param_2 + 0xf8) != (longlong *)(param_2 + 0xf8)) {
    (*DAT_140016440)(param_1,0x10000001,0x4949495f,0,0,iVar2);
    if (*(int *)(param_2 + 0x30) == 2) {
      EHCI_InternalPollHsIsoEndpoint(param_1,param_2,'\x01','\0');
    }
    else {
      EHCI_InternalPollIsoEndpoint(param_1,param_2,'\x01');
    }
  }
  return;
}



===== EHCI_InternalPollHsIsoEndpoint @ 140001240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_InternalPollHsIsoEndpoint(longlong param_1,longlong param_2,char param_3,char param_4)

{
  uint *puVar1;
  int *piVar2;
  longlong *plVar3;
  byte bVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined8 *puVar10;
  longlong lVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  int iVar17;
  uint *puVar18;
  undefined8 uVar19;
  longlong lVar20;
  longlong *plVar21;
  longlong *plVar22;
  uint uVar23;
  longlong *plVar24;
  uint local_88;
  int local_84;
  uint local_78;
  uint *local_60;
  
  local_84 = 0;
  uVar9 = (uint)*(byte *)(param_2 + 0x2e);
  uVar7 = EHCI_Get32BitFrameNumber(param_1);
  local_88 = *(uint *)(param_2 + 0xe0);
  (*DAT_140016440)(param_1,0x10000001,0x3e69705f,local_88,uVar7,0);
  if ((uVar7 - local_88) - 0x401 < 0x7fffffff) {
    local_88 = uVar7 - 1;
    (*DAT_140016440)(param_1,0x10000001,0x31766f5f,local_88,uVar7,0);
    lVar11 = 0;
    lVar20 = 0x400;
    do {
      lVar5 = *(longlong *)(param_2 + 200);
      lVar6 = *(longlong *)(lVar11 + 0x78 + lVar5);
      if (lVar6 != 0) {
        *(undefined8 *)(lVar11 + 0x68 + lVar5) = 0;
        *(undefined8 *)(lVar11 + 0x78 + lVar5) = 0;
        piVar2 = (int *)(lVar6 + 0x50);
        *piVar2 = *piVar2 - (int)(8 / (ulonglong)uVar9);
      }
      lVar11 = lVar11 + 0x80;
      lVar20 = lVar20 + -1;
    } while (lVar20 != 0);
  }
  if (local_88 == uVar7) {
    (*DAT_140016440)(param_1,0x10000001,0x7261655f,local_88,uVar7,0);
  }
  local_60 = (uint *)0x0;
  local_78 = local_88 & 0x3ff;
  (*DAT_140016440)(param_1,0x10000001,0x6872665f,local_88,local_78,uVar7);
  iVar13 = 0;
  if (local_78 != (uVar7 & 0x3ff)) {
    do {
      iVar13 = iVar13 + 1;
      lVar20 = (ulonglong)local_78 * 0x80 + *(longlong *)(param_2 + 200);
      lVar11 = *(longlong *)(lVar20 + 0x68);
      if (lVar11 != 0) {
        lVar5 = *(longlong *)(lVar20 + 0x78);
        iVar8 = EHCI_Get32BitFrameNumber(param_1);
        bVar4 = *(byte *)(param_2 + 0x2e);
        (*DAT_140016440)(param_1,0x10000001,0x4970635f,lVar11,lVar20,iVar8);
        uVar16 = 0;
        puVar18 = (uint *)(lVar11 + 0x10);
        do {
          lVar11 = uVar16 * 4;
          uVar14 = *(uint *)(lVar11 + 4 + lVar20);
          puVar1 = puVar18 + -4;
          if ((int)uVar14 < 0) {
            *(uint *)(lVar11 + 4 + lVar20) = uVar14 & 0x7fffffff;
            puVar18[-3] = 0;
            (*DAT_140016440)(param_1,0x10000001,0x736d635f,puVar1,uVar16,puVar18[-2]);
            *puVar18 = 0xc0020000;
          }
          else {
            if ((*(uint *)(lVar20 + 0x28) & 0x800) == 0) {
              uVar19 = 0x3370635f;
              uVar15 = *puVar1;
            }
            else {
              uVar19 = 0x3470635f;
              uVar15 = uVar14 >> 0x10 & 0xfff;
            }
            (*DAT_140016440)(param_1,0x10000001,uVar19,puVar18[-2],*puVar1,puVar1);
            puVar18[-3] = uVar15;
            if ((uVar14 >> 0x1c & 1) == 0) {
              if ((uVar14 >> 0x1d & 1) == 0) {
                *puVar18 = -(uint)((uVar14 & 0x40000000) != 0) & 0xc0000013;
              }
              else {
                *puVar18 = 0xc0000012;
              }
            }
            else {
              *puVar18 = 0xc0000011;
            }
            (*DAT_140016440)(param_1,0x10000001,0x4c70635f,puVar18 + -4,lVar20,uVar15);
            *(uint *)(lVar11 + 4 + lVar20) = uVar14 & 0x8000ffff;
          }
          puVar18 = puVar18 + 0xe;
          uVar14 = (int)uVar16 + (uint)bVar4;
          uVar16 = (ulonglong)uVar14;
        } while (uVar14 < 8);
        *(undefined8 *)(lVar20 + 0x68) = 0;
        *(undefined8 *)(lVar20 + 0x78) = 0;
        piVar2 = (int *)(lVar5 + 0x50);
        *piVar2 = *piVar2 - (int)(8 / (ulonglong)uVar9);
      }
      local_88 = local_88 + 1;
      local_78 = local_78 + 1 & 0x3ff;
    } while (local_78 != (uVar7 & 0x3ff));
  }
  iVar8 = EHCI_Get32BitFrameNumber(param_1);
  (*DAT_140016440)(param_1,0x10000001,0x6b70675f,0,iVar13,iVar8);
  uVar14 = 0;
  if (*(int *)(param_2 + 0x118) != 2) {
    (*DAT_140016440)(param_1,0x10000001,0x6873705f,0,iVar8,uVar7);
    uVar15 = uVar7;
    do {
      uVar23 = uVar15 & 0x3ff;
      puVar18 = (uint *)((ulonglong)uVar23 * 0x80 + *(longlong *)(param_2 + 200));
      (*DAT_140016440)(param_1,0x10000001,0x6670675f,puVar18,uVar23,uVar15);
      if (*(longlong *)(puVar18 + 0x1a) == 0) {
        for (puVar10 = *(undefined8 **)(param_2 + 0xf8); puVar10 != (undefined8 *)(param_2 + 0xf8);
            puVar10 = (undefined8 *)*puVar10) {
          if (*(int *)(puVar10 + -1) - uVar15 < 0x7fffffff) {
            lVar11 = puVar10[2];
            for (uVar16 = 0; (uint)uVar16 < *(uint *)(lVar11 + 4);
                uVar16 = (ulonglong)((uint)uVar16 + 1)) {
              if (*(uint *)(uVar16 * 0x38 + 0x18 + lVar11) == uVar15) {
                lVar20 = lVar11 + 0x10 + uVar16 * 0x38;
                if (lVar20 == 0) goto LAB_140001631;
                EHCI_MapHsIsoPacketsToTd
                          (param_1,param_2,lVar20,puVar18,
                           uVar15 == *(int *)(puVar10 + -1) -
                                     (int)((ulonglong)*(uint *)(lVar11 + 4) / (8 / (ulonglong)uVar9)
                                          ) || uVar15 == *(int *)(puVar10 + -1) - 1U);
                *(longlong *)(puVar18 + 0x1a) = lVar20;
                *(undefined8 **)(puVar18 + 0x1e) = puVar10 + -7;
                *(int *)(puVar10 + 3) = *(int *)(puVar10 + 3) + (int)(8 / (ulonglong)uVar9);
                local_60 = puVar18;
                goto LAB_140001668;
              }
            }
          }
        }
LAB_140001631:
        (*DAT_140016440)(param_1,0x10000001,0x4270675f,0,uVar23,0);
        uVar14 = uVar14 + 1;
        if ((8 < uVar14) && (param_4 == '\0')) break;
      }
      else {
        (*DAT_140016440)(param_1,0x10000001,0x4370675f,0,uVar23,0);
      }
LAB_140001668:
      uVar15 = uVar15 + 1;
    } while (uVar15 - uVar7 < 0x400);
    if (local_60 != (uint *)0x0) {
      uVar9 = 8 - uVar9;
      if (7 < uVar9) {
        return;
      }
      local_60[(ulonglong)uVar9 + 1] = local_60[(ulonglong)uVar9 + 1] | 0x8000;
    }
  }
  iVar13 = 0;
  *(uint *)(param_2 + 0xe0) = local_88;
  iVar8 = EHCI_Get32BitFrameNumber(param_1);
  plVar24 = (longlong *)(param_2 + 0xf8);
  if ((longlong *)*plVar24 == plVar24) {
    iVar17 = local_84;
  }
  else {
    local_84 = 0;
    plVar21 = (longlong *)*plVar24;
    iVar17 = 0;
    iVar13 = 0;
    iVar12 = 0;
    if (param_3 != '\0') {
      do {
        plVar3 = plVar21 + -7;
        (*DAT_140016440)(param_1,0x10000001,0x316b635f,plVar3,(int)plVar21[-1] + 2,iVar8);
        if (((uint)(iVar8 - (int)plVar21[-1]) < 0x7fffffff) && ((int)plVar21[3] == 0)) {
          uVar7 = 0;
          plVar22 = (longlong *)*plVar21;
          lVar11 = plVar21[2] + 0x10;
          if (*(int *)(plVar21[2] + 4) != 0) {
            do {
              (*DAT_140016440)(param_1,0x10000001,0x326b635f,plVar3,0,lVar11);
              if (*(int *)(lVar11 + 0x10) == -1) {
                *(undefined4 *)(lVar11 + 0x10) = 0xc0020000;
              }
              lVar11 = lVar11 + 0x38;
              uVar7 = uVar7 + 1;
            } while (uVar7 < *(uint *)(plVar21[2] + 4));
          }
          EHCI_DecPendingTransfer(param_1,param_2,plVar3);
          (*DAT_140016438)(param_1,param_2,plVar21[-4],plVar21[2]);
          iVar13 = iVar12;
        }
        else {
          plVar22 = (longlong *)*plVar21;
          iVar13 = iVar12 + 1;
          local_84 = (int)plVar21[-1];
        }
        plVar21 = plVar22;
        iVar12 = iVar13;
      } while (plVar22 != plVar24);
      iVar17 = local_84;
    }
  }
  iVar8 = EHCI_Get32BitFrameNumber(param_1);
  if (iVar13 == 1) {
    iVar13 = iVar17 - iVar8;
    if (iVar17 - iVar8 < 1) {
      iVar13 = iVar8 - iVar17;
    }
    if (iVar13 < 2) {
      (*DAT_140016440)(param_1,0x10000001,0x6865725f,iVar17,iVar8,0);
      (*DAT_140016468)(param_1,3);
    }
  }
  (*DAT_140016440)(param_1,0x10000001,0x3c69705f,iVar8,0,0);
  return;
}



===== EHCI_InternalPollIsoEndpoint @ 140001a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_InternalPollIsoEndpoint(longlong param_1,longlong param_2,char param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  uint *puVar4;
  int iVar5;
  undefined8 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  longlong *plVar11;
  longlong *plVar12;
  uint uVar13;
  longlong lVar14;
  int iVar15;
  longlong lVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint local_res8;
  
  if (*(longlong *)(param_1 + 200) == 0) {
    uVar7 = 0xffffffff;
  }
  else {
    uVar7 = *(uint *)(*(longlong *)(param_1 + 200) + 0xc) >> 3;
    uVar7 = (uVar7 & 0x3ff | *(uint *)(param_1 + 0x130)) +
            ((uVar7 & 0x7ff ^ *(uint *)(param_1 + 0x130)) & 0x400);
  }
  local_res8 = *(uint *)(param_2 + 0xe0);
  (*DAT_140016440)(param_1,0x10000001,0x7369705f,local_res8,uVar7,param_2);
  uVar18 = uVar7 - 1;
  if ((uVar7 - local_res8) - 0x21 < 0x7fffffff) {
    (*DAT_140016440)(param_1,0x10000001,0x65766f5f,uVar18,uVar7,0);
    uVar13 = 2;
    do {
      lVar14 = (ulonglong)(uVar13 - 2) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 - 1) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)uVar13 * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 1) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 2) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 3) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 4) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 5) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 6) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 7) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 8) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 9) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 10) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 0xb) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 0xc) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      lVar14 = (ulonglong)(uVar13 + 0xd) * 0x80 + *(longlong *)(param_2 + 0xc0);
      lVar16 = *(longlong *)(lVar14 + 0x58);
      if (lVar16 != 0) {
        *(undefined8 *)(lVar14 + 0x50) = 0;
        *(undefined8 *)(lVar14 + 0x58) = 0;
        piVar1 = (int *)(lVar16 + 0x50);
        *piVar1 = *piVar1 + -1;
      }
      uVar8 = uVar13 + 0xe;
      uVar13 = uVar13 + 0x10;
      local_res8 = uVar18;
    } while (uVar8 < 0x20);
  }
  if (local_res8 == uVar7) {
    (*DAT_140016440)(param_1,0x10000001,0x7261655f,local_res8,uVar7,0);
    return;
  }
  uVar13 = local_res8 & 0x1f;
  (*DAT_140016440)(param_1,0x10000001,0x6d72665f,local_res8,uVar13,uVar7);
  for (; uVar13 != (uVar18 & 0x1f); uVar13 = uVar13 + 1 & 0x1f) {
    lVar16 = (ulonglong)uVar13 * 0x80 + *(longlong *)(param_2 + 0xc0);
    puVar4 = *(uint **)(lVar16 + 0x50);
    (*DAT_140016440)(param_1,0x10000001,0x6b70675f,*(undefined8 *)(lVar16 + 0x58),puVar4,uVar13);
    if (puVar4 != (uint *)0x0) {
      lVar14 = *(longlong *)(lVar16 + 0x58);
      if (*(longlong *)(param_1 + 200) == 0) {
        iVar10 = -1;
      }
      else {
        uVar8 = *(uint *)(*(longlong *)(param_1 + 200) + 0xc) >> 3;
        iVar10 = (uVar8 & 0x3ff | *(uint *)(param_1 + 0x130)) +
                 ((uVar8 & 0x7ff ^ *(uint *)(param_1 + 0x130)) & 0x400);
      }
      (*DAT_140016440)(param_1,0x10000001,0x4970635f,puVar4,lVar16,iVar10);
      uVar8 = *(uint *)(lVar16 + 0xc);
      if ((char)uVar8 < '\0') {
        *(uint *)(lVar16 + 0xc) = uVar8 & 0xffffff7f;
        puVar4[1] = 0;
        (*DAT_140016440)(param_1,0x10000001,0x736d635f,puVar4,0,puVar4[2]);
        puVar4[4] = 0xc0020000;
      }
      else {
        uVar19 = *puVar4;
        uVar9 = uVar8 >> 0x10 & 0x3ff;
        uVar17 = uVar19 - uVar9;
        if (uVar19 < uVar9) {
          uVar17 = 0;
        }
        (*DAT_140016440)(param_1,0x10000001,0x3370635f,puVar4[2],uVar19,uVar8 >> 0x10 & 0x3ff);
        puVar4[1] = uVar17;
        (*DAT_140016440)(param_1,0x10000001,0x4c70635f,puVar4,lVar16,uVar17);
        (*DAT_140016440)(param_1,0x10000001,0x5370635f,puVar4,uVar8,(longlong)(int)puVar4[4]);
        iVar10 = 0;
        puVar4[4] = 0;
        if ((uVar8 & 8) == 0) {
          if ((uVar8 & 0x10) == 0) {
            if ((uVar8 & 0x20) == 0) {
              if (((uVar8 & 0x40) != 0) || ((uVar8 & 4) != 0)) {
                iVar10 = -0x3ffd0000;
                puVar4[4] = 0xc0030000;
              }
            }
            else {
              puVar4[4] = 0xc0000013;
              iVar10 = -0x3fffffed;
            }
          }
          else {
            puVar4[4] = 0xc0000012;
            iVar10 = -0x3fffffee;
          }
        }
        else {
          puVar4[4] = 0xc0000011;
          iVar10 = -0x3fffffef;
        }
        (*DAT_140016440)(param_1,0x10000001,0x5370635f,puVar4,uVar8,(longlong)iVar10);
        *(uint *)(lVar16 + 0xc) = uVar8 & 0xfc00ff83;
      }
      *(undefined8 *)(lVar16 + 0x50) = 0;
      *(undefined8 *)(lVar16 + 0x58) = 0;
      piVar1 = (int *)(lVar14 + 0x50);
      *piVar1 = *piVar1 + -1;
    }
    local_res8 = local_res8 + 1;
  }
  if (*(int *)(param_2 + 0x118) != 2) {
    (*DAT_140016440)(param_1,0x10000001,0x6873705f,0,0,0);
    uVar18 = uVar7 + 1;
    do {
      lVar16 = (ulonglong)(uVar18 & 0x1f) * 0x80 + *(longlong *)(param_2 + 0xc0);
      (*DAT_140016440)(param_1,0x10000001,0x6670675f,lVar16,uVar18 & 0x1f,uVar18);
      if (*(longlong *)(lVar16 + 0x50) == 0) {
        for (puVar6 = *(undefined8 **)(param_2 + 0xf8); puVar6 != (undefined8 *)(param_2 + 0xf8);
            puVar6 = (undefined8 *)*puVar6) {
          if (*(int *)(puVar6 + -1) - uVar18 < 0x7fffffff) {
            lVar14 = puVar6[2];
            for (uVar13 = 0; uVar13 < *(uint *)(lVar14 + 4); uVar13 = uVar13 + 1) {
              if (*(uint *)((ulonglong)uVar13 * 0x38 + 0x18 + lVar14) == uVar18) {
                lVar14 = lVar14 + 0x10 + (ulonglong)uVar13 * 0x38;
                if (lVar14 != 0) {
                  if (*(longlong *)(param_1 + 200) == 0) {
                    iVar10 = -1;
                  }
                  else {
                    uVar13 = *(uint *)(*(longlong *)(param_1 + 200) + 0xc) >> 3;
                    iVar10 = (uVar13 & 0x3ff | *(uint *)(param_1 + 0x130)) +
                             ((uVar13 & 0x7ff ^ *(uint *)(param_1 + 0x130)) & 0x400);
                  }
                  if ((-1 - iVar10) + uVar18 < 0x7fffffff) {
                    (*DAT_140016440)(param_1,0x10000001,0x49706d5f,lVar16,0,lVar14);
                    *(undefined4 *)(lVar16 + 0xc) = 0;
                    uVar19 = 0;
                    uVar13 = *(uint *)(lVar14 + 0x20);
                    *(uint *)(lVar16 + 0x10) = uVar13;
                    *(undefined4 *)(lVar16 + 0x1c) = *(undefined4 *)(lVar14 + 0x24);
                    uVar8 = *(uint *)(lVar14 + 0x18);
                    *(uint *)(lVar16 + 0x48) = uVar13 & 0xfff;
                    *(undefined4 *)(lVar16 + 0x14) = 0;
                    *(undefined4 *)(lVar16 + 0x20) = 0;
                    if (1 < *(uint *)(lVar14 + 0x14)) {
                      uVar19 = *(uint *)(lVar14 + 0x30);
                      *(uint *)(lVar16 + 0x14) = uVar19;
                      *(undefined4 *)(lVar16 + 0x20) = *(undefined4 *)(lVar14 + 0x34);
                      uVar8 = uVar8 + *(int *)(lVar14 + 0x28);
                    }
                    *(uint *)(lVar16 + 0x14) = uVar19 & 0xffffffe7;
                    if (*(int *)(param_2 + 0x40) == 1) {
                      if (uVar8 == 0) {
                        uVar13 = uVar19 & 0xffffffe1 | 1;
                      }
                      else {
                        uVar13 = (uVar8 - 1) / 0xbc + 1 & 7 | uVar19 & 0xffffffe0;
                      }
                      *(uint *)(lVar16 + 0x14) = uVar13;
                      if ((uVar13 & 7) != 1) {
                        uVar13 = uVar13 | 8;
                      }
                    }
                    else {
                      uVar13 = uVar19 & 0xffffffe0;
                    }
                    *(uint *)(lVar16 + 0x14) = uVar13;
                    *(undefined1 *)(lVar16 + 9) = *(undefined1 *)(param_2 + 0x65);
                    *(undefined1 *)(lVar16 + 8) = *(undefined1 *)(param_2 + 100);
                    *(uint *)(lVar16 + 0xc) = (uVar8 & 0x3ff) << 0x10 | 0x80000080;
                    *(longlong *)(lVar16 + 0x50) = lVar14;
                    *(undefined8 **)(lVar16 + 0x58) = puVar6 + -7;
                    *(int *)(puVar6 + 3) = *(int *)(puVar6 + 3) + 1;
                  }
                }
                goto LAB_140001dd7;
              }
            }
          }
        }
      }
LAB_140001dd7:
      uVar18 = uVar18 + 1;
    } while (uVar18 - uVar7 < 0x20);
  }
  plVar3 = (longlong *)(param_2 + 0xf8);
  *(uint *)(param_2 + 0xe0) = local_res8;
  if ((longlong *)*plVar3 != plVar3) {
    iVar15 = 0;
    iVar10 = 0;
    plVar11 = (longlong *)*plVar3;
    if (param_3 != '\0') {
      do {
        plVar2 = plVar11 + -7;
        (*DAT_140016440)(param_1,0x10000001,0x746b635f,plVar2,(int)plVar11[-1] + 2,uVar7);
        iVar5 = (int)plVar11[-1];
        if (((uVar7 - iVar5) - 2 < 0x7fffffff) && ((int)plVar11[3] == 0)) {
          plVar12 = (longlong *)*plVar11;
          (*DAT_140016440)(param_1,0x10000001,0x6970635f,plVar2,uVar7,iVar5);
          EHCI_DecPendingTransfer(param_1,param_2,plVar2);
          (*DAT_140016438)(param_1,param_2,plVar11[-4],plVar11[2]);
        }
        else {
          plVar12 = (longlong *)*plVar11;
          iVar15 = iVar15 + 1;
          iVar10 = iVar5;
        }
        plVar11 = plVar12;
      } while (plVar12 != plVar3);
      if (iVar15 == 1) {
        iVar5 = EHCI_Get32BitFrameNumber(param_1);
        iVar15 = iVar10 - iVar5;
        if (iVar10 - iVar5 < 1) {
          iVar15 = iVar5 - iVar10;
        }
        if (iVar15 < 2) {
          (*DAT_140016440)(param_1,0x10000001,0x6965725f,iVar10,iVar5,0);
          (*DAT_140016468)(param_1,3);
        }
      }
    }
  }
  return;
}



===== EHCI_MapHsIsoPacketsToTd @ 140002500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_MapHsIsoPacketsToTd
               (longlong param_1,longlong param_2,longlong param_3,uint *param_4,char param_5)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  
  bVar2 = *(byte *)(param_2 + 0x2e);
  (*DAT_140016440)(param_1,0x10000001,0x5348485f,param_4,bVar2,param_3);
  puVar10 = param_4 + 9;
  puVar6 = (uint *)(param_3 + 0x24);
  puVar9 = param_4 + 0x10;
  uVar8 = 0;
  uVar4 = 0;
  *puVar10 = (*(uint *)(param_3 + 0x20) ^ *puVar10) & 0xfff ^ *(uint *)(param_3 + 0x20);
  *puVar9 = *puVar6;
  puVar7 = param_4;
  do {
    puVar7 = puVar7 + 1;
    if (uVar4 % (uint)bVar2 == 0) {
      uVar5 = puVar6[-1];
      uVar3 = uVar5 >> 0xc;
      if ((uVar3 != *puVar10 >> 0xc) || (*puVar6 != *puVar9)) {
        puVar1 = puVar10 + 1;
        puVar10 = puVar10 + 1;
        puVar9 = puVar9 + 1;
        uVar8 = uVar8 + 1;
        *puVar10 = *puVar1 & 0xfff | uVar3 << 0xc;
        *puVar9 = *puVar6;
      }
      if (((*(char *)(param_1 + 0x60) != '\0') && (uVar4 == 7)) && (uVar8 < 2)) {
        (*DAT_140016440)(param_1,0x10000001,0x3662735f,uVar8,0,0);
        uVar3 = *puVar10;
        uVar8 = 2;
        puVar10 = param_4 + 0xb;
        param_4[0xb] = (uVar3 ^ param_4[0xb]) & 0xfff ^ uVar3;
        uVar3 = *puVar9;
        puVar9 = param_4 + 0x12;
        param_4[0x12] = uVar3;
      }
      uVar5 = uVar5 & 0xfff;
      uVar3 = ((puVar6[-9] & 0xfff) << 4 | uVar8 & 7) << 0xc;
      if ((param_5 == '\0') || (uVar4 != 8 - bVar2)) {
        uVar5 = uVar3 | *puVar7 & 0xf0000000 | uVar5;
      }
      else {
        uVar5 = uVar3 | *puVar7 & 0xf0008000 | uVar5 | 0x8000;
      }
      param_4[(ulonglong)uVar4 + 1] = uVar5 | 0x80000000;
      if (1 < puVar6[-4]) {
        puVar10 = puVar10 + 1;
        puVar9 = puVar9 + 1;
        uVar8 = uVar8 + 1;
        *puVar10 = (puVar6[3] ^ *puVar10) & 0xfff ^ puVar6[3];
        *puVar9 = puVar6[4];
      }
      puVar6 = puVar6 + 0xe;
    }
    else {
      param_4[(ulonglong)uVar4 + 1] = *puVar7 & 0x7fffffff;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 8);
  (*DAT_140016440)(param_1,0x10000001,0x73686d5f,param_4,0,uVar8);
  return;
}



===== EHCI_PollControlEndpoint @ 140002750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_PollControlEndpoint(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  code *pcVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined8 uStack_50;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  
  local_20 = 0;
  local_28 = 0;
  if (*(int *)(param_2 + 0x94) == 0) {
    (*DAT_140016440)(param_1,0x10000001,0x4e6f705f,param_2);
  }
  else {
    uVar2 = *(undefined4 *)(*(longlong *)(param_2 + 0x78) + 0x18);
    if ((*(uint *)(*(longlong *)(param_2 + 0x78) + 0x4c) & 2) == 0) {
      (*DAT_140016440)(param_1,0x10000001);
      puVar6 = auStack_48;
      lVar4 = param_1;
      plVar5 = (longlong *)param_2;
      if (((byte)uVar2 & 0xc0) == 0x40) goto LAB_140002815;
      EHCI_PollActiveControlEndpoint(param_1,param_2);
      puVar6 = auStack_48;
      do {
        plVar1 = (longlong *)(param_2 + 0x108);
        while( true ) {
          plVar5 = (longlong *)*plVar1;
          if (plVar5 == plVar1) {
            return;
          }
          if (((longlong *)plVar5[1] != plVar1) ||
             (lVar4 = *plVar5, (longlong *)*(longlong *)(lVar4 + 8) != plVar5)) break;
          *plVar1 = lVar4;
          *(longlong **)(lVar4 + 8) = plVar1;
          *(undefined8 *)(puVar6 + -8) = 0x1400027f0;
          EHCI_ProcessDoneAsyncTd(param_1,plVar5 + -0xe,0);
        }
        lVar4 = 3;
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)();
        puVar6 = puVar6 + 8;
LAB_140002815:
        *(undefined4 *)(param_2 + 0x70) = 1;
        *(undefined8 *)(puVar6 + -8) = 0x140002821;
        EHCI_PollHaltedControlEndpoint(lVar4,(longlong)plVar5);
      } while( true );
    }
    (*DAT_140016440)(param_1,0x10000001,0x4d52715f);
  }
  return;
}



===== EHCI_ProcessDoneAsyncTd @ 140002850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_ProcessDoneAsyncTd(longlong param_1,undefined8 *param_2,longlong param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  code *pcVar11;
  undefined8 uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  
  plVar4 = (longlong *)param_2[10];
  *(int *)((longlong)plVar4 + 0x14) = *(int *)((longlong)plVar4 + 0x14) + -1;
  lVar5 = plVar4[3];
  lVar6 = plVar4[5];
  if ((*(uint *)(param_2 + 7) & 0x10) == 0) {
    uVar2 = *(uint *)(param_2 + 1);
    if ((uVar2 & 0x40) == 0) {
      iVar14 = 0;
    }
    else {
      uVar12 = EHCI_GetErrorFromTD(param_1,param_2,(longlong)param_2);
      iVar14 = (int)uVar12;
    }
    (*DAT_140016440)(param_1,0x10000001,0x6474445f,plVar4,(longlong)iVar14,param_2);
    uVar3 = *(uint *)((longlong)param_2 + 0x3c);
    uVar13 = uVar2 >> 0x10 & 0x7fff;
    iVar15 = uVar3 - uVar13;
    if (uVar3 < uVar13) {
      iVar15 = 0;
    }
    (*DAT_140016440)(param_1,0x10000001,0x6e6c745f,iVar15,uVar3,uVar2 >> 0x10 & 0x7fff);
    if ((uVar2 & 0x300) != 0x200) {
      (*DAT_140016440)(param_1,0x10000001,0x7464495f,param_2,plVar4,iVar15);
      *(int *)((longlong)plVar4 + 0x24) = *(int *)((longlong)plVar4 + 0x24) + iVar15;
    }
    if (iVar14 != 0) {
      *(int *)(plVar4 + 4) = iVar14;
      (*DAT_140016440)(param_1,0x10000001,0x5245745f,(longlong)iVar14,0,0);
    }
  }
  else {
    (*DAT_140016440)(param_1,0x10000001,0x64744b5f,plVar4,0,param_2);
  }
  if (-1 < (char)*(undefined4 *)(param_2 + 7)) {
    *(undefined4 *)(param_2 + 7) = 0;
    *param_2 = 0;
    *(int *)(lVar6 + 0xdc) = *(int *)(lVar6 + 0xdc) + 1;
    (*DAT_140016440)(param_1,0x10000001,0x4454665f,param_2,0,0);
    param_2[10] = 0xdeadfacedeadface;
  }
  if (*(int *)((longlong)plVar4 + 0x14) != 0) {
    return;
  }
  iVar14 = *(int *)(lVar6 + 0xf0);
  lVar7 = *(longlong *)(lVar6 + 0x78);
  if (iVar14 != 3) {
    if (iVar14 == 1) {
      *(int *)(lVar6 + 0xf4) = *(int *)(lVar6 + 0xf4) + -1;
      goto LAB_140002a2a;
    }
    if (iVar14 == 2) {
      *(int *)(lVar6 + 0x94) = *(int *)(lVar6 + 0x94) + -1;
      goto LAB_140002a2a;
    }
    if (iVar14 != 4) goto LAB_140002a2a;
  }
  piVar1 = (int *)(lVar6 + 0x94);
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (*(char *)(param_1 + 99) != '\0')) {
    EHCI_RemoveQueueHeadFromHWAsyncList(param_1,lVar7);
  }
LAB_140002a2a:
  lVar8 = *plVar4;
  if ((*(longlong **)(lVar8 + 8) == plVar4) &&
     (plVar9 = (longlong *)plVar4[1], (longlong *)*plVar9 == plVar4)) {
    *plVar9 = lVar8;
    *(longlong **)(lVar8 + 8) = plVar9;
    plVar9 = plVar4 + 7;
    *plVar4 = 0;
    plVar4[1] = 0;
    lVar8 = *plVar9;
    if ((*(longlong **)(lVar8 + 8) == plVar9) &&
       (plVar10 = (longlong *)plVar4[8], (longlong *)*plVar10 == plVar9)) {
      *plVar10 = lVar8;
      *(longlong **)(lVar8 + 8) = plVar10;
      *plVar9 = 0;
      plVar4[8] = 0;
      (*DAT_140016440)(param_1,0x10000001,0x7470635f,(longlong)(int)plVar4[4],plVar4,
                       *(undefined4 *)((longlong)plVar4 + 0x24));
      if (*(char *)(param_1 + 0x62) != '\0') {
        *(undefined4 *)(lVar7 + 0x14) = 1;
        *(undefined4 *)(lVar7 + 0x10) = 1;
      }
      if (param_3 == 0) {
        (*DAT_140016430)(param_1,lVar6,lVar5,(int)plVar4[4],*(undefined4 *)((longlong)plVar4 + 0x24)
                        );
        return;
      }
      return;
    }
  }
  pcVar11 = (code *)swi(0x29);
  (*pcVar11)(3);
  pcVar11 = (code *)swi(3);
  (*pcVar11)();
  return;
}



===== EHCI_PollActiveControlEndpoint @ 140002b98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_PollActiveControlEndpoint(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  longlong lVar8;
  
  uVar7 = *(uint *)(*(longlong *)(param_2 + 0x78) + 0xc) & 0xffffffe0;
  (*DAT_140016440)(param_1,0x10000001,0x6c6f705f,*(longlong *)(param_2 + 0x78),0,uVar7);
  uVar6 = (*DAT_140016448)(uVar7,param_1,param_2);
  lVar3 = *(longlong *)(param_2 + 0x138);
  lVar8 = *(longlong *)(param_2 + 0x130);
  (*DAT_140016440)(param_1,0x10000001,0x3170635f,lVar3,lVar8,uVar6);
  if ((*(uint *)(lVar3 + 8) & 0x80) != 0) {
    (*DAT_140016440)(param_1,0x10000001,0x3270635f,lVar3,lVar8,uVar6);
    return;
  }
  lVar2 = param_2 + 0x108;
  plVar4 = *(longlong **)(param_2 + 0x110);
  plVar1 = (longlong *)(lVar8 + 0x70);
  if (*plVar4 == lVar2) {
    *(longlong **)(lVar8 + 0x78) = plVar4;
    *plVar1 = lVar2;
    *plVar4 = (longlong)plVar1;
    *(longlong **)(param_2 + 0x110) = plVar1;
    if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
      *(uint *)(lVar8 + 0x38) = *(uint *)(lVar8 + 0x38) | 0x80;
      LOCK();
      UNLOCK();
    }
    else {
      LOCK();
      *(uint *)(lVar8 + 0x38) = *(uint *)(lVar8 + 0x38) | 0x80;
      UNLOCK();
    }
    plVar4 = *(longlong **)(param_2 + 0x110);
    plVar1 = (longlong *)(lVar3 + 0x70);
    if (*plVar4 == lVar2) {
      *plVar1 = lVar2;
      *(longlong **)(lVar3 + 0x78) = plVar4;
      *plVar4 = (longlong)plVar1;
      *(longlong **)(param_2 + 0x110) = plVar1;
      if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
        *(uint *)(lVar3 + 0x38) = *(uint *)(lVar3 + 0x38) | 0x80;
        LOCK();
        UNLOCK();
      }
      else {
        LOCK();
        *(uint *)(lVar3 + 0x38) = *(uint *)(lVar3 + 0x38) | 0x80;
        UNLOCK();
      }
      lVar8 = *(longlong *)(lVar8 + 0x58);
      (*DAT_140016440)(param_1,0x10000001,0x3370635f,lVar8,0,uVar6);
      if (lVar8 == lVar3) {
        return;
      }
      do {
        (*DAT_140016440)(param_1,0x10000001,0x3174645f,lVar8,0,*(undefined8 *)(lVar8 + 0x50));
        if ((*(uint *)(lVar8 + 8) & 0x80) == 0) {
LAB_140002d2f:
          if (param_1 != 0) goto LAB_140002d38;
code_r0x000140002e2c:
          *(uint *)(lVar8 + 0x38) = *(uint *)(lVar8 + 0x38) | 8;
          LOCK();
          UNLOCK();
        }
        else {
          (*DAT_140016440)(param_1,0x10000001,0x5374645f,lVar8,0,0);
          if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
            *(uint *)(lVar8 + 0x38) = *(uint *)(lVar8 + 0x38) | 0x10;
            LOCK();
            UNLOCK();
            goto LAB_140002d2f;
          }
          LOCK();
          *(uint *)(lVar8 + 0x38) = *(uint *)(lVar8 + 0x38) | 0x10;
          UNLOCK();
LAB_140002d38:
          if (*(char *)(param_1 + 0x5e) != '\0') goto code_r0x000140002e2c;
          LOCK();
          *(uint *)(lVar8 + 0x38) = *(uint *)(lVar8 + 0x38) | 8;
          UNLOCK();
        }
        plVar4 = *(longlong **)(param_2 + 0x110);
        plVar1 = (longlong *)(lVar8 + 0x70);
        if (*plVar4 != param_2 + 0x108) break;
        *plVar1 = param_2 + 0x108;
        *(longlong **)(lVar8 + 0x78) = plVar4;
        *plVar4 = (longlong)plVar1;
        *(longlong **)(param_2 + 0x110) = plVar1;
        lVar8 = *(longlong *)(lVar8 + 0x58);
        if (lVar8 == lVar3) {
          return;
        }
      } while( true );
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== EHCI_RemoveQueueHeadFromHWAsyncList @ 140002e4c =====

void EHCI_RemoveQueueHeadFromHWAsyncList(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  
  if ((*(uint *)(param_2 + 0x4c) & 0x10) != 0) {
    puVar3 = *(uint **)(param_2 + 0x60);
    puVar4 = *(uint **)(param_2 + 0x68);
    if (((*(char *)(param_1 + 0x65) != '\0') &&
        (puVar2 = *(uint **)(param_1 + 0xf0), puVar3 == puVar2)) && (puVar4 == puVar2)) {
      puVar3 = *(uint **)(param_1 + 0xf8);
      *(uint **)(puVar2 + 0x1a) = puVar3;
      puVar4 = puVar2;
    }
    uVar1 = puVar3[0x11];
    *(uint **)(puVar4 + 0x18) = puVar3;
    *puVar4 = uVar1 & 0xffffffe3 | 2;
    *(uint **)(puVar3 + 0x1a) = puVar4;
    if (*(char *)(param_1 + 0x5e) != '\0') {
      *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xffffffef;
      LOCK();
      UNLOCK();
      return;
    }
    LOCK();
    *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xffffffef;
    UNLOCK();
  }
  return;
}



===== EHCI_Get32BitFrameNumber @ 140002ec0 =====

int EHCI_Get32BitFrameNumber(longlong param_1)

{
  uint uVar1;
  
  if (*(longlong *)(param_1 + 200) == 0) {
    return -1;
  }
  uVar1 = *(uint *)(*(longlong *)(param_1 + 200) + 0xc) >> 3;
  return (uVar1 & 0x3ff | *(uint *)(param_1 + 0x130)) +
         ((uVar1 & 0x7ff ^ *(uint *)(param_1 + 0x130)) & 0x400);
}



===== EHCI_SubmitIsoTransfer @ 140002f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
EHCI_SubmitIsoTransfer
          (longlong param_1,longlong param_2,longlong param_3,longlong *param_4,longlong param_5)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  bool bVar4;
  
  bVar4 = false;
  if ((*(uint *)(param_2 + 0x80) & 2) == 0) {
    bVar1 = *(byte *)(param_2 + 0x2e);
    (*DAT_140016440)(param_1,0x10000001,0x4f53495f,param_4,param_5,(ulonglong)bVar1);
    memset(param_4,0,0x60);
    *(undefined4 *)(param_4 + 2) = 0x72743032;
    param_4[9] = param_5;
    param_4[5] = param_2;
    param_4[3] = param_3;
    iVar2 = EHCI_Get32BitFrameNumber(param_1);
    *(int *)((longlong)param_4 + 0x54) = iVar2;
    if (*(int *)(param_2 + 0x30) == 2) {
      iVar2 = EHCI_Get32BitFrameNumber(param_1);
      (*DAT_140016440)(param_1,0x10000001,0x5348735f,0,iVar2,*(undefined4 *)(param_5 + 0x18));
      *(int *)(param_4 + 6) =
           (int)((ulonglong)*(uint *)(param_5 + 4) / (8 / (ulonglong)bVar1)) +
           *(int *)(param_5 + 0x18);
      bVar4 = (*(int *)(param_5 + 0x18) - iVar2) - 9U < 0x7fffffff;
    }
    else {
      *(int *)(param_4 + 6) = *(int *)(param_5 + 4) + *(int *)(param_5 + 0x18);
    }
    *(undefined4 *)(param_4 + 10) = 0;
    if (*(longlong **)(param_2 + 0xf8) == (longlong *)(param_2 + 0xf8)) {
      *(undefined4 *)(param_2 + 0xe0) = 0;
      (*DAT_140016440)(param_1,0x10000001,0x6973725f,0,0,0);
    }
    EHCI_IncPendingTransfer(param_1,param_2,param_4);
    if (*(int *)(param_2 + 0x30) == 2) {
      EHCI_InternalPollHsIsoEndpoint(param_1,param_2,'\0',bVar4);
    }
    else {
      EHCI_InternalPollIsoEndpoint(param_1,param_2,'\0');
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



===== EHCI_IncPendingTransfer @ 1400030c0 =====

void EHCI_IncPendingTransfer(longlong param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  longlong *plVar2;
  uint *puVar3;
  uint *puVar4;
  code *pcVar5;
  undefined1 uVar6;
  uint *puVar7;
  longlong *plVar8;
  
  iVar1 = *(int *)(param_2 + 0xf0);
  if (iVar1 != 3) {
    if (iVar1 == 1) {
      plVar2 = *(longlong **)(param_1 + 0xa8);
      if (*plVar2 == param_1 + 0xa0) {
        param_3[1] = (longlong)plVar2;
        *param_3 = param_1 + 0xa0;
        *plVar2 = (longlong)param_3;
        *(longlong **)(param_1 + 0xa8) = param_3;
        plVar8 = param_3 + 7;
        plVar2 = *(longlong **)(param_2 + 0x100);
        if (*plVar2 == param_2 + 0xf8) {
          *plVar8 = param_2 + 0xf8;
          param_3[8] = (longlong)plVar2;
          *plVar2 = (longlong)plVar8;
          *(longlong **)(param_2 + 0x100) = plVar8;
          *(int *)(param_2 + 0xf4) = *(int *)(param_2 + 0xf4) + 1;
          return;
        }
      }
      goto LAB_1400032ed;
    }
    if (iVar1 == 2) {
      plVar2 = *(longlong **)(param_1 + 0x98);
      if (*plVar2 == param_1 + 0x90) {
        param_3[1] = (longlong)plVar2;
        *param_3 = param_1 + 0x90;
        *plVar2 = (longlong)param_3;
        *(longlong **)(param_1 + 0x98) = param_3;
        plVar8 = param_3 + 7;
        plVar2 = *(longlong **)(param_2 + 0xa0);
        if (*plVar2 == param_2 + 0x98) {
          *plVar8 = param_2 + 0x98;
          param_3[8] = (longlong)plVar2;
          *plVar2 = (longlong)plVar8;
          *(longlong **)(param_2 + 0xa0) = plVar8;
          *(int *)(param_2 + 0x94) = *(int *)(param_2 + 0x94) + 1;
          return;
        }
      }
      goto LAB_1400032ed;
    }
    if (iVar1 != 4) {
      return;
    }
  }
  plVar2 = *(longlong **)(param_1 + 0x88);
  if (*plVar2 == param_1 + 0x80) {
    *param_3 = param_1 + 0x80;
    param_3[1] = (longlong)plVar2;
    *plVar2 = (longlong)param_3;
    *(longlong **)(param_1 + 0x88) = param_3;
    plVar2 = *(longlong **)(param_2 + 0xa0);
    plVar8 = param_3 + 7;
    if (*plVar2 == param_2 + 0x98) {
      *plVar8 = param_2 + 0x98;
      param_3[8] = (longlong)plVar2;
      *plVar2 = (longlong)plVar8;
      *(longlong **)(param_2 + 0xa0) = plVar8;
      *(int *)(param_2 + 0x94) = *(int *)(param_2 + 0x94) + 1;
      if (((*(int *)(param_2 + 0x94) == 1) && (*(char *)(param_1 + 99) != '\0')) &&
         (puVar3 = *(uint **)(param_2 + 0x78), (puVar3[0x13] & 0x10) == 0)) {
        puVar4 = *(uint **)(param_1 + 0xf0);
        puVar7 = *(uint **)(puVar4 + 0x18);
        if ((*(char *)(param_1 + 0x65) != '\0') && (puVar7 == *(uint **)(param_1 + 0xf8))) {
          puVar7 = puVar4;
        }
        *puVar3 = puVar7[0x11] & 0xffffffe3 | 2;
        *puVar4 = puVar3[0x11] & 0xffffffe3 | 2;
        *(uint **)(puVar3 + 0x18) = puVar7;
        *(uint **)(puVar3 + 0x1a) = puVar4;
        *(uint **)(puVar4 + 0x18) = puVar3;
        *(uint **)(puVar7 + 0x1a) = puVar3;
        if (*(char *)(param_1 + 0x5e) == '\0') {
          LOCK();
          puVar3[0x13] = puVar3[0x13] | 0x10;
          UNLOCK();
        }
        else {
          puVar3[0x13] = puVar3[0x13] | 0x10;
          LOCK();
          UNLOCK();
        }
        if (*(char *)(param_1 + 0x569) != '\0') {
          uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
          *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
          if (*(longlong *)(puVar3 + 0x16) != 0) {
            *(undefined4 *)(*(longlong *)(puVar3 + 0x16) + 0x14c) = *(undefined4 *)(param_1 + 0x570)
            ;
          }
          *(undefined8 *)(param_1 + 0x118) = 0;
          KeReleaseSpinLock(param_1 + 0x110,uVar6);
        }
      }
      return;
    }
  }
LAB_1400032ed:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== EHCI_DecPendingTransfer @ 140003300 =====

void EHCI_DecPendingTransfer(longlong param_1,longlong param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  uint *puVar7;
  code *pcVar8;
  uint *puVar9;
  uint *puVar10;
  
  iVar2 = *(int *)(param_2 + 0xf0);
  if (iVar2 != 3) {
    if (iVar2 == 1) {
      *(int *)(param_2 + 0xf4) = *(int *)(param_2 + 0xf4) + -1;
      goto LAB_140003316;
    }
    if (iVar2 == 2) {
      *(int *)(param_2 + 0x94) = *(int *)(param_2 + 0x94) + -1;
      goto LAB_140003316;
    }
    if (iVar2 != 4) goto LAB_140003316;
  }
  piVar1 = (int *)(param_2 + 0x94);
  *piVar1 = *piVar1 + -1;
  if (((*piVar1 == 0) && (*(char *)(param_1 + 99) != '\0')) &&
     (lVar4 = *(longlong *)(param_2 + 0x78), (*(uint *)(lVar4 + 0x4c) & 0x10) != 0)) {
    puVar9 = *(uint **)(lVar4 + 0x60);
    puVar10 = *(uint **)(lVar4 + 0x68);
    if (((*(char *)(param_1 + 0x65) != '\0') &&
        (puVar7 = *(uint **)(param_1 + 0xf0), puVar9 == puVar7)) && (puVar10 == puVar7)) {
      puVar9 = *(uint **)(param_1 + 0xf8);
      *(uint **)(puVar7 + 0x1a) = puVar9;
      puVar10 = puVar7;
    }
    uVar3 = puVar9[0x11];
    *(uint **)(puVar10 + 0x18) = puVar9;
    *puVar10 = uVar3 & 0xffffffe3 | 2;
    *(uint **)(puVar9 + 0x1a) = puVar10;
    if (*(char *)(param_1 + 0x5e) == '\0') {
      LOCK();
      *(uint *)(lVar4 + 0x4c) = *(uint *)(lVar4 + 0x4c) & 0xffffffef;
      UNLOCK();
    }
    else {
      *(uint *)(lVar4 + 0x4c) = *(uint *)(lVar4 + 0x4c) & 0xffffffef;
      LOCK();
      UNLOCK();
    }
  }
LAB_140003316:
  lVar4 = *param_3;
  if ((*(longlong **)(lVar4 + 8) == param_3) &&
     (plVar5 = (longlong *)param_3[1], (longlong *)*plVar5 == param_3)) {
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    plVar5 = param_3 + 7;
    *param_3 = 0;
    param_3[1] = 0;
    lVar4 = *plVar5;
    if ((*(longlong **)(lVar4 + 8) == plVar5) &&
       (plVar6 = (longlong *)param_3[8], (longlong *)*plVar6 == plVar5)) {
      *plVar6 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar6;
      *plVar5 = 0;
      param_3[8] = 0;
      return;
    }
  }
  pcVar8 = (code *)swi(0x29);
  (*pcVar8)(3);
  pcVar8 = (code *)swi(3);
  (*pcVar8)();
  return;
}



===== EHCI_sMode_InitSlot @ 140003428 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_sMode_InitSlot(longlong param_1,longlong param_2,undefined4 param_3,undefined4 *param_4,
                        undefined8 param_5,longlong param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  
  (*DAT_140016440)(param_1,0x10000001,0x53676c5f,param_4,param_5,param_6);
  param_4[2] = 0;
  *(undefined8 *)(param_4 + 6) = param_5;
  *(undefined8 *)(param_4 + 8) = param_5;
  *param_4 = param_3;
  puVar1 = (undefined4 *)(param_6 + 0x40);
  *(int *)(param_2 + 0x15c) = *(int *)(param_2 + 0x15c) + 1;
  puVar2 = *(undefined4 **)(param_4 + 6);
  param_4[1] = *(undefined4 *)(param_2 + 0x15c);
  puVar3 = puVar2;
  uVar5 = 1;
  if (1 < *(uint *)(param_2 + 0x158)) {
    do {
      puVar2 = (undefined4 *)EHCI_AllocTd(param_1,param_2);
      uVar4 = (int)uVar5 + 1;
      *(undefined4 **)(param_4 + uVar5 * 2 + 8) = puVar2;
      *puVar3 = puVar2[0x10];
      puVar3[1] = *puVar1;
      *(undefined4 **)(puVar3 + 0x16) = puVar2;
      *(longlong *)(puVar3 + 0x18) = param_6;
      *(undefined4 **)(puVar3 + 0x1a) = puVar2;
      puVar3 = puVar2;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(param_2 + 0x158));
  }
  *puVar2 = *puVar1;
  puVar2[1] = *puVar1;
  *(longlong *)(puVar2 + 0x16) = param_6;
  *(longlong *)(puVar2 + 0x18) = param_6;
  *(longlong *)(puVar2 + 0x1a) = param_6;
  EHCI_sMode_ResetSlot(param_1,param_2,(longlong)param_4);
  return;
}



===== EHCI_NotifyTransferQueueState @ 140003540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_NotifyTransferQueueState(longlong param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined1 uVar2;
  uint uVar3;
  
  bVar1 = false;
  if (*(uint **)(param_1 + 200) == (uint *)0x0) {
    return;
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar3 = **(uint **)(param_1 + 200);
    if (((uVar3 & 1) != 0) && (uVar3 != 0xffffffff)) goto LAB_140003598;
  }
  else {
    uVar3 = 0;
  }
  bVar1 = true;
LAB_140003598:
  (*DAT_140016440)(param_1,0x10000001,0x31546e5f,param_2,param_3,uVar3);
  if (!bVar1) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
    *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
    (*DAT_140016440)(param_1,0x10000001,0x32546e5f,param_2,param_3,uVar3);
    *(int *)(param_1 + 0x34) = param_2;
    *(int *)(param_1 + 0x40) = param_3;
    if ((param_2 == 0) && (*(int *)(param_1 + 0x38) != 0)) {
      (*DAT_140016440)(param_1,0x10000001,0x33546e5f,0,param_3,uVar3);
      EHCI_iDisableAsyncList(param_1);
    }
    else {
      (*DAT_140016440)(param_1,0x10000001,0x34546e5f,param_2,param_3,uVar3);
      EHCI_iEnableAsyncList(param_1);
    }
    *(undefined8 *)(param_1 + 0x118) = 0;
    KeReleaseSpinLock(param_1 + 0x110,uVar2);
    (*DAT_140016440)(param_1,0x10000001,0x35546e5f,param_2,param_3,uVar3);
    if ((param_3 == 0) && (*(int *)(param_1 + 0x44) != 0)) {
      EHCI_DisablePeriodicList(param_1);
    }
    else {
      EHCI_EnablePeriodicList(param_1);
    }
  }
  (*DAT_140016440)(param_1,0x10000001,0x36546e5f,param_2,param_3,uVar3);
  return;
}



===== EHCI_EnablePeriodicList @ 140003770 =====

void EHCI_EnablePeriodicList(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
  *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
  EHCI_iEnablePeriodicList(param_1);
  *(undefined8 *)(param_1 + 0x118) = 0;
  KeReleaseSpinLock(param_1 + 0x110,uVar1);
  return;
}



===== EHCI_iEnablePeriodicList @ 1400037f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EHCI_iEnablePeriodicList(longlong param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 local_88 [32];
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_88;
  puVar3 = *(uint **)(param_1 + 200);
  local_60 = 0;
  uVar4 = *puVar3;
  uVar5 = puVar3[1];
  uVar6 = (ulonglong)uVar5;
  local_68 = (undefined8 *)uVar6;
  (*DAT_140016440)(param_1,0x10000001,0x70555341,uVar4);
  if (uVar4 == 0xffffffff) {
    EHCI_SetAsyncScheduleState(param_1,1);
    local_60 = 0;
    local_68 = (undefined8 *)uVar6;
    (*DAT_140016440)(param_1,0x10000001,0x70555350,0xffffffff);
    EHCI_SetPeriodicScheduleState(param_1,1);
    local_60 = 0;
    local_68 = (undefined8 *)uVar6;
    (*DAT_140016440)(param_1,0x10000001,0x506e655f,0xffffffff);
  }
  else {
    if ((uVar4 & 0x20) == 0 && (uVar5 >> 0xf & 1) == 0) {
      iVar2 = *(int *)(param_1 + 0x558);
      local_60 = 0;
      local_68 = (undefined8 *)0x1;
      (*DAT_140016440)(param_1,0x10000001,0x72545341,(longlong)iVar2);
      if (iVar2 != 1) {
        piVar1 = (int *)(param_1 + 0x570);
        *piVar1 = *piVar1 + 1;
        if (*piVar1 == 0) {
          *(undefined4 *)(param_1 + 0x570) = 1;
        }
      }
      if (*(int *)(param_1 + 0x558) != 2) {
        *(undefined4 *)(param_1 + 0x558) = 1;
      }
    }
    else if ((uVar4 & 0x20) != 0 && (uVar5 >> 0xf & 1) != 0) {
      local_60 = 0;
      local_68 = (undefined8 *)0x4;
      (*DAT_140016440)(param_1,0x10000001,0x72545341,(longlong)*(int *)(param_1 + 0x558));
      if (*(int *)(param_1 + 0x558) != 5) {
        *(undefined4 *)(param_1 + 0x558) = 4;
      }
    }
    local_60 = 0;
    local_68 = (undefined8 *)uVar6;
    (*DAT_140016440)(param_1,0x10000001,0x70555350,uVar4);
    if ((uVar4 & 0x10) == 0 && (uVar5 >> 0xe & 1) == 0) {
      local_60 = 0;
      local_68 = (undefined8 *)0x1;
      (*DAT_140016440)(param_1,0x10000001,0x72545350,(longlong)*(int *)(param_1 + 0x560));
      if (*(int *)(param_1 + 0x560) != 2) {
        *(undefined4 *)(param_1 + 0x560) = 1;
      }
    }
    if ((uVar4 & 0x10) != 0 && (uVar5 >> 0xe & 1) != 0) {
      local_60 = 0;
      local_68 = (undefined8 *)0x4;
      (*DAT_140016440)(param_1,0x10000001,0x72545350,(longlong)*(int *)(param_1 + 0x560));
      if (*(int *)(param_1 + 0x560) != 5) {
        *(undefined4 *)(param_1 + 0x560) = 4;
      }
    }
    local_60 = 0;
    local_68 = (undefined8 *)uVar6;
    (*DAT_140016440)(param_1,0x10000001,0x506e655f,uVar4);
    if (((*(char *)(param_1 + 0x568) == '\0') || (*(int *)(param_1 + 0x578) != 0)) ||
       (*(int *)(param_1 + 0x55c) == 1)) {
      if ((uVar4 & 0x10) == 0) {
        if (*(int *)(param_1 + 0x78) == 0) {
          uVar5 = 0;
          do {
            if ((((uint)uVar6 >> 10 ^ uVar4) & 0x10) == 0) break;
            KeStallExecutionProcessor(0x19);
            local_60 = 0;
            uVar4 = *puVar3;
            uVar6 = (ulonglong)puVar3[1];
            local_68 = (undefined8 *)uVar6;
            (*DAT_140016440)(param_1,0x10000001,0x5370655f,uVar4);
            uVar5 = uVar5 + 1;
          } while (uVar5 < 0xf);
          if ((((uint)uVar6 >> 10 ^ uVar4) & 0x10) != 0) {
            *(int *)(param_1 + 0x4f8) = *(int *)(param_1 + 0x4f8) + 1;
          }
        }
        *(int *)(param_1 + 0x4e8) = *(int *)(param_1 + 0x4e8) + 1;
        uVar4 = uVar4 & 0xffffffbf | 0x10;
        *puVar3 = uVar4;
        LOCK();
        UNLOCK();
        local_60 = 0;
        local_68 = (undefined8 *)0x3;
        (*DAT_140016440)(param_1,0x10000001,0x72545350,(longlong)*(int *)(param_1 + 0x560));
        local_68 = &local_48;
        *(undefined4 *)(param_1 + 0x560) = 3;
        local_48 = 0;
        uStack_40 = 0;
        (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_PERIODIC_SCHEDULE_ENABLE,0,1);
      }
    }
    else {
      local_60 = 0;
      local_68 = (undefined8 *)0x2;
      (*DAT_140016440)(param_1,0x10000001,0x72545350,(longlong)*(int *)(param_1 + 0x560));
      *(int *)(param_1 + 0x580) = *(int *)(param_1 + 0x580) + 1;
      *(undefined4 *)(param_1 + 0x560) = 2;
    }
  }
  local_60 = 0;
  local_68 = (undefined8 *)uVar6;
  (*DAT_140016440)(param_1,0x10000001,0x586e655f,uVar4);
  return;
}



===== EHCI_SubmitTransfer @ 140003c70 =====

ulonglong EHCI_SubmitTransfer(longlong param_1,longlong param_2,uint *param_3,longlong *param_4,
                             longlong param_5)

{
  int iVar1;
  ulonglong uVar2;
  char cVar3;
  
  if ((*(uint *)(param_2 + 0x80) & 2) != 0) {
    return 1;
  }
  *param_4 = 0;
  param_4[1] = 0;
  param_4[2] = 0;
  param_4[3] = 0;
  param_4[4] = 0;
  param_4[5] = 0;
  param_4[6] = 0;
  param_4[7] = 0;
  param_4[8] = 0;
  param_4[9] = 0;
  param_4[10] = 0;
  param_4[0xb] = 0;
  *(undefined4 *)(param_4 + 2) = 0x72743032;
  param_4[5] = param_2;
  param_4[3] = (longlong)param_3;
  iVar1 = *(int *)(param_2 + 0x3c);
  if (iVar1 == 2) {
    cVar3 = '\x01';
  }
  else {
    if (iVar1 == 1) {
      uVar2 = EHCI_ControlTransfer(param_1,param_2,param_3,param_4,param_5);
      return uVar2;
    }
    if (iVar1 != 3) {
      return 6;
    }
    cVar3 = '\0';
  }
  uVar2 = EHCI_sMode_Transfer(param_1,param_2,param_3,param_4,param_5,cVar3);
  return uVar2 & 0xffffffff;
}



===== EHCI_sMode_Transfer @ 140003d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
EHCI_sMode_Transfer(longlong param_1,longlong param_2,uint *param_3,longlong *param_4,
                   longlong param_5,char param_6)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  int iVar7;
  longlong lVar8;
  uint *puVar9;
  uint local_res8;
  uint local_res10;
  
  uVar6 = 0;
  (*DAT_140016440)(param_1,0x10000001,0x544c535f,param_2,param_3,param_3[1]);
  if (*(uint *)(param_2 + 0x94) < *(uint *)(param_1 + 0x6c)) {
    cVar2 = (*DAT_140016618)(param_1);
    if ((((*param_3 & 1) == 0) || (*(longlong *)(param_2 + 0x168) == 0)) ||
       (lVar8 = *(longlong *)(*(longlong *)(param_2 + 0x168) + 0x10),
       ((byte)*(undefined4 *)(*(longlong *)(lVar8 + 0x18) + 0xc) & 0x21) != 1)) {
      lVar8 = 0;
      if (*(uint *)(param_2 + 0x160) != 0) {
        lVar4 = param_2 + 0x180;
        uVar5 = (ulonglong)*(uint *)(param_2 + 0x160);
        do {
          if (*(int *)(lVar4 + 8) != 1) {
            if (lVar8 == 0) {
              if (*(int *)(lVar4 + 8) == 0) {
                lVar8 = lVar4;
              }
            }
            else if (*(int *)(lVar4 + 4) < *(int *)(lVar8 + 4)) {
              lVar8 = lVar4;
            }
          }
          lVar4 = lVar4 + 0x120;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
        if (lVar8 != 0) {
          EHCI_IncPendingTransfer(param_1,param_2,param_4);
          *(undefined4 *)(lVar8 + 8) = 1;
          *(longlong **)(lVar8 + 0x10) = param_4;
          *(int *)(param_2 + 0x15c) = *(int *)(param_2 + 0x15c) + 1;
          *(undefined4 *)(lVar8 + 4) = *(undefined4 *)(param_2 + 0x15c);
          param_4[0xb] = lVar8;
          (*DAT_140016440)(param_1,0x10000001,0x5449425f,param_2,param_3,lVar8);
          *(undefined4 *)((longlong)param_4 + 0x14) = 0;
          lVar4 = 0;
          iVar7 = 0;
          local_res10 = 0;
          if (param_3[1] == 0) {
            uVar3 = 0;
          }
          else {
            local_res8 = -(uint)(cVar2 != '\0') & 0x8000;
            do {
              (*DAT_140016440)(param_1,0x10000001,0x3174645f,uVar6,param_4,local_res10);
              *(int *)((longlong)param_4 + 0x14) = *(int *)((longlong)param_4 + 0x14) + 1;
              lVar4 = *(longlong *)(lVar8 + 0x20 + uVar6 * 8);
              if (*(char *)(param_1 + 0x5e) == '\0') {
                LOCK();
                *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) & 0xffffffbf;
                UNLOCK();
              }
              else {
                *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) & 0xffffffbf;
                LOCK();
                UNLOCK();
              }
              *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) | 2;
              *(longlong **)(lVar4 + 0x50) = param_4;
              *(undefined4 *)(lVar4 + 0xc) = 0xbad0000;
              *(undefined8 *)(lVar4 + 0x20) = 0;
              *(undefined4 *)(lVar4 + 0x10) = 0xbad0000;
              *(undefined4 *)(lVar4 + 0x14) = 0xbad0000;
              *(undefined8 *)(lVar4 + 0x28) = 0;
              *(undefined4 *)(lVar4 + 0x18) = 0xbad0000;
              *(undefined4 *)(lVar4 + 0x1c) = 0xbad0000;
              *(undefined4 *)(lVar4 + 0x30) = 0;
              *(undefined4 *)(lVar4 + 8) = 0xc00;
              if ((*param_3 & 1) == 0) {
                uVar3 = *(uint *)(lVar4 + 8) & 0xffff7cff | local_res8;
              }
              else {
                uVar3 = *(uint *)(lVar4 + 8) & 0xffff7dff | local_res8 | 0x100;
              }
              *(uint *)(lVar4 + 8) = uVar3 | 0x80000000;
              (*DAT_140016440)(param_1,0x10000001,0x3274645f,lVar4,local_res10,param_3[1]);
              local_res10 = EHCI_MapAsyncTransferToTd
                                      (param_1,(uint)*(ushort *)(param_2 + 0x2c),local_res10,
                                       (uint *)0x0,(longlong)param_4,lVar4,param_5);
              uVar3 = param_3[1];
              uVar6 = (ulonglong)((int)uVar6 + 1);
            } while (local_res10 < uVar3);
            iVar7 = *(int *)((longlong)param_4 + 0x14);
          }
          if (uVar3 == 0) {
            *(int *)((longlong)param_4 + 0x14) = iVar7 + 1;
            lVar4 = *(longlong *)(lVar8 + 0x20 + uVar6 * 8);
            uVar3 = *(uint *)(lVar4 + 8);
            if (*(char *)(param_1 + 0x5e) == '\0') {
              LOCK();
              *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) & 0xffffffbf;
              UNLOCK();
            }
            else {
              *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) & 0xffffffbf;
              LOCK();
              UNLOCK();
            }
            *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) | 2;
            *(longlong **)(lVar4 + 0x50) = param_4;
            *(undefined4 *)(lVar4 + 0xc) = 0xbad0000;
            *(undefined8 *)(lVar4 + 0x20) = 0;
            *(undefined4 *)(lVar4 + 0x10) = 0xbad0000;
            *(undefined4 *)(lVar4 + 0x14) = 0xbad0000;
            *(undefined8 *)(lVar4 + 0x28) = 0;
            *(undefined4 *)(lVar4 + 0x18) = 0xbad0000;
            *(undefined4 *)(lVar4 + 0x1c) = 0xbad0000;
            *(undefined4 *)(lVar4 + 0x30) = 0;
            *(undefined4 *)(lVar4 + 8) = 0xc00;
            if ((*param_3 & 1) == 0) {
              uVar3 = uVar3 & 0xfffffcff;
            }
            else {
              uVar3 = uVar3 & 0xfffffdff | 0x100;
            }
            uVar3 = uVar3 & 0xffff | 0x80000000;
            *(undefined4 *)(lVar4 + 0xc) = *(undefined4 *)(lVar4 + 0x40);
            *(undefined4 *)(lVar4 + 0x3c) = 0;
          }
          else {
            uVar3 = *(uint *)(lVar4 + 8);
          }
          puVar9 = (uint *)((longlong)param_4 + 0x14);
          *(uint *)(lVar4 + 8) = uVar3 | 0x8000;
          (*DAT_140016440)(param_1,0x10000001,0x41474c5f,*puVar9,0,lVar8);
          puVar1 = *(undefined4 **)(lVar8 + 0x20 + (ulonglong)(*puVar9 - 1) * 8);
          *puVar1 = *(undefined4 *)(*(longlong *)(puVar1 + 0x18) + 0x40);
          *(longlong *)(puVar1 + 0x16) = *(longlong *)(puVar1 + 0x18);
          if (*(longlong *)(param_2 + 0x168) == 0) {
            lVar4 = *(longlong *)(param_2 + 0x78);
            *(longlong *)(param_2 + 0x168) = lVar8;
            *(undefined4 *)(lVar4 + 0xc) = *(undefined4 *)(*(longlong *)(lVar8 + 0x18) + 0x40);
            *(undefined4 *)(lVar4 + 0x14) = *(undefined4 *)(*(longlong *)(lVar8 + 0x18) + 0x40);
            *(undefined4 *)(lVar4 + 0x10) = *(undefined4 *)(*(longlong *)(lVar8 + 0x18) + 0x40);
            *(uint *)(lVar4 + 0x18) = *(uint *)(lVar4 + 0x18) & 0x80008f7d | 0xc00;
          }
          uVar6 = 0;
          if (*puVar9 != 0) {
            do {
              uVar3 = (int)uVar6 + 1;
              lVar4 = *(longlong *)(lVar8 + 0x20 + uVar6 * 8);
              *(uint *)(lVar4 + 8) = *(uint *)(lVar4 + 8) | 0x80;
              uVar6 = (ulonglong)uVar3;
            } while (uVar3 < *puVar9);
          }
          if (param_6 == '\0') {
            EHCI_EnablePeriodicList(param_1);
          }
          else {
            EHCI_EnableAsyncList(param_1);
          }
          return 0;
        }
      }
      (*DAT_140016440)(param_1,0x10000001,0x5342425f,param_2,param_3,0);
      return 1;
    }
    (*DAT_140016440)(param_1,0x10000001,0x3042425f,lVar8,0,0);
  }
  return 1;
}



===== EHCI_ControlTransfer @ 140004210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
EHCI_ControlTransfer
          (longlong param_1,longlong param_2,uint *param_3,longlong *param_4,longlong param_5)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong *plVar4;
  longlong *plVar5;
  uint *puVar6;
  uint *puVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  code *pcVar11;
  undefined1 uVar12;
  uint uVar13;
  undefined8 uVar14;
  int *piVar15;
  int *piVar16;
  uint uVar17;
  uint *puVar18;
  int *piVar19;
  int local_58;
  uint local_54;
  int *local_50;
  int *local_48;
  int *local_40;
  int *local_38;
  int *local_30;
  
  local_58 = 0;
  if ((*(uint *)(param_2 + 0xdc) < 6) ||
     (plVar2 = (longlong *)(param_2 + 0x98), (longlong *)*plVar2 != plVar2)) {
LAB_1400044a6:
    uVar14 = 1;
  }
  else {
    iVar3 = *(int *)(param_2 + 0xf0);
    if (iVar3 == 3) {
LAB_14000426c:
      plVar4 = *(longlong **)(param_1 + 0x88);
      if (*plVar4 != param_1 + 0x80) {
LAB_1400049c0:
        pcVar11 = (code *)swi(0x29);
        (*pcVar11)(3);
        pcVar11 = (code *)swi(3);
        uVar14 = (*pcVar11)();
        return uVar14;
      }
      *param_4 = param_1 + 0x80;
      param_4[1] = (longlong)plVar4;
      *plVar4 = (longlong)param_4;
      *(longlong **)(param_1 + 0x88) = param_4;
      plVar4 = param_4 + 7;
      plVar5 = *(longlong **)(param_2 + 0xa0);
      if ((longlong *)*plVar5 != plVar2) goto LAB_1400049c0;
      *plVar4 = (longlong)plVar2;
      param_4[8] = (longlong)plVar5;
      *plVar5 = (longlong)plVar4;
      *(longlong **)(param_2 + 0xa0) = plVar4;
      *(int *)(param_2 + 0x94) = *(int *)(param_2 + 0x94) + 1;
      if (((*(int *)(param_2 + 0x94) == 1) && (*(char *)(param_1 + 99) != '\0')) &&
         (puVar6 = *(uint **)(param_2 + 0x78), (puVar6[0x13] & 0x10) == 0)) {
        puVar7 = *(uint **)(param_1 + 0xf0);
        puVar18 = *(uint **)(puVar7 + 0x18);
        if ((*(char *)(param_1 + 0x65) != '\0') && (puVar18 == *(uint **)(param_1 + 0xf8))) {
          puVar18 = puVar7;
        }
        *puVar6 = puVar18[0x11] & 0xffffffe3 | 2;
        *puVar7 = puVar6[0x11] & 0xffffffe3 | 2;
        *(uint **)(puVar6 + 0x18) = puVar18;
        *(uint **)(puVar6 + 0x1a) = puVar7;
        *(uint **)(puVar7 + 0x18) = puVar6;
        *(uint **)(puVar18 + 0x1a) = puVar6;
        if (*(char *)(param_1 + 0x5e) == '\0') {
          LOCK();
          puVar6[0x13] = puVar6[0x13] | 0x10;
          UNLOCK();
        }
        else {
          puVar6[0x13] = puVar6[0x13] | 0x10;
          LOCK();
          UNLOCK();
        }
        if (*(char *)(param_1 + 0x569) != '\0') {
          uVar12 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
          *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
          if (*(longlong *)(puVar6 + 0x16) != 0) {
            *(undefined4 *)(*(longlong *)(puVar6 + 0x16) + 0x14c) = *(undefined4 *)(param_1 + 0x570)
            ;
          }
          *(undefined8 *)(param_1 + 0x118) = 0;
          KeReleaseSpinLock(param_1 + 0x110,uVar12);
        }
      }
    }
    else if (iVar3 == 1) {
      plVar2 = *(longlong **)(param_1 + 0xa8);
      if (*plVar2 != param_1 + 0xa0) goto LAB_1400049c0;
      *param_4 = param_1 + 0xa0;
      param_4[1] = (longlong)plVar2;
      *plVar2 = (longlong)param_4;
      *(longlong **)(param_1 + 0xa8) = param_4;
      plVar2 = param_4 + 7;
      plVar4 = *(longlong **)(param_2 + 0x100);
      if (*plVar4 != param_2 + 0xf8) goto LAB_1400049c0;
      *plVar2 = param_2 + 0xf8;
      param_4[8] = (longlong)plVar4;
      *plVar4 = (longlong)plVar2;
      *(longlong **)(param_2 + 0x100) = plVar2;
      *(int *)(param_2 + 0xf4) = *(int *)(param_2 + 0xf4) + 1;
    }
    else if (iVar3 == 2) {
      plVar4 = *(longlong **)(param_1 + 0x98);
      if (*plVar4 != param_1 + 0x90) goto LAB_1400049c0;
      *param_4 = param_1 + 0x90;
      param_4[1] = (longlong)plVar4;
      *plVar4 = (longlong)param_4;
      *(longlong **)(param_1 + 0x98) = param_4;
      plVar4 = param_4 + 7;
      plVar5 = *(longlong **)(param_2 + 0xa0);
      if ((longlong *)*plVar5 != plVar2) goto LAB_1400049c0;
      *plVar4 = (longlong)plVar2;
      param_4[8] = (longlong)plVar5;
      *plVar5 = (longlong)plVar4;
      *(longlong **)(param_2 + 0xa0) = plVar4;
      *(int *)(param_2 + 0x94) = *(int *)(param_2 + 0x94) + 1;
    }
    else if (iVar3 == 4) goto LAB_14000426c;
    local_54 = 1;
    (*DAT_140016440)(param_1,0x10000001,0x5254435f,param_2,param_3,0);
    *(int *)((longlong)param_4 + 0x14) = *(int *)((longlong)param_4 + 0x14) + 1;
    piVar16 = *(int **)(param_2 + 0x130);
    if (piVar16 == (int *)0x0) {
      piVar16 = (int *)EHCI_AllocTd(param_1,param_2);
      *(int **)(param_2 + 0x130) = piVar16;
      if (piVar16 == (int *)0x0) goto LAB_1400044a6;
    }
    piVar16[0xe] = piVar16[0xe] | 2;
    *(longlong **)(piVar16 + 0x14) = param_4;
    piVar16[3] = 0xbad0000;
    piVar16[8] = 0;
    piVar16[9] = 0;
    piVar16[4] = 0xbad0000;
    piVar16[5] = 0xbad0000;
    piVar16[10] = 0;
    piVar16[0xb] = 0;
    piVar16[6] = 0xbad0000;
    piVar16[7] = 0xbad0000;
    piVar16[0xc] = 0;
    *piVar16 = 1;
    piVar16[1] = 1;
    piVar16[2] = 0xc00;
    piVar16[0x16] = 0;
    piVar16[0x17] = 0;
    *(undefined8 *)(piVar16 + 0x1a) = *(undefined8 *)(param_3 + 5);
    local_40 = piVar16 + 0x10;
    piVar16[3] = *local_40 + 0x68;
    piVar16[2] = piVar16[2] & 31999U | 0x88200;
    (*DAT_140016440)(param_1,0x10000001,0x7465735f,piVar16,(longlong)(int)param_3[5],
                     (longlong)(int)param_3[6]);
    piVar15 = *(int **)(param_2 + 0x138);
    if (piVar15 == (int *)0x0) {
      piVar15 = (int *)EHCI_AllocTd(param_1,param_2);
      *(int **)(param_2 + 0x138) = piVar15;
      *(int *)((longlong)param_4 + 0x14) = *(int *)((longlong)param_4 + 0x14) + 1;
      if (piVar15 == (int *)0x0) goto LAB_1400044a6;
    }
    else {
      *(int *)((longlong)param_4 + 0x14) = *(int *)((longlong)param_4 + 0x14) + 1;
    }
    piVar15[0xe] = piVar15[0xe] | 2;
    local_48 = piVar15 + 3;
    *(longlong **)(piVar15 + 0x14) = param_4;
    *local_48 = 0xbad0000;
    piVar15[8] = 0;
    piVar15[9] = 0;
    piVar15[4] = 0xbad0000;
    piVar15[5] = 0xbad0000;
    piVar15[10] = 0;
    piVar15[0xb] = 0;
    piVar15[6] = 0xbad0000;
    piVar15[7] = 0xbad0000;
    piVar15[0xc] = 0;
    piVar15[1] = 1;
    piVar15[0x16] = 0;
    piVar15[0x17] = 0;
    piVar1 = piVar15 + 0x10;
    local_30 = piVar15 + 1;
    local_38 = piVar15 + 0x16;
    *piVar15 = 1;
    piVar15[2] = 0xc00;
    piVar16[1] = *piVar1;
    *(int **)(piVar16 + 0x18) = piVar15;
    uVar13 = 0;
    local_50 = piVar16;
    while (piVar19 = local_50, uVar13 < param_3[1]) {
      uVar17 = 0;
      while( true ) {
        if (*(uint *)(param_2 + 0xd8) <= uVar17) {
          (*DAT_140016470)(param_1);
          goto LAB_140004497;
        }
        piVar19 = (int *)((ulonglong)uVar17 * 0x80 + *(longlong *)(param_2 + 0xb8));
        if ((piVar19[0xe] & 1U) == 0) break;
        uVar17 = uVar17 + 1;
      }
      if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
        piVar19[0xe] = piVar19[0xe] | 1;
        LOCK();
        UNLOCK();
      }
      else {
        LOCK();
        piVar19[0xe] = piVar19[0xe] | 1;
        UNLOCK();
      }
      (*DAT_140016440)(param_1,0x10000001,0x4454615f,piVar19,0,0);
      *(int *)(param_2 + 0xdc) = *(int *)(param_2 + 0xdc) + -1;
      if (piVar19 == (int *)0x0) {
LAB_140004497:
        (*DAT_140016470)(param_1);
        goto LAB_1400044a6;
      }
      piVar19[0xe] = piVar19[0xe] | 2;
      local_58 = local_58 + 1;
      *(longlong **)(piVar19 + 0x14) = param_4;
      piVar19[8] = 0;
      piVar19[9] = 0;
      piVar19[3] = 0xbad0000;
      piVar19[4] = 0xbad0000;
      piVar19[5] = 0xbad0000;
      piVar19[10] = 0;
      piVar19[0xb] = 0;
      piVar19[6] = 0xbad0000;
      piVar19[7] = 0xbad0000;
      piVar19[0xc] = 0;
      piVar19[0x16] = 0;
      piVar19[0x17] = 0;
      *piVar19 = 1;
      piVar19[1] = 1;
      piVar19[2] = 0xc00;
      *(int *)((longlong)param_4 + 0x14) = *(int *)((longlong)param_4 + 0x14) + 1;
      *local_50 = piVar19[0x10];
      *(int **)(local_50 + 0x16) = piVar19;
      if ((*param_3 & 1) == 0) {
        uVar17 = piVar19[2] & 0xfffffcff;
      }
      else {
        uVar17 = piVar19[2] & 0xfffffdffU | 0x100;
      }
      piVar19[2] = uVar17 & 0x7fff7f7f | local_54 << 0x1f | 0x8080;
      piVar19[1] = *piVar1;
      *(int **)(piVar19 + 0x18) = piVar15;
      (*DAT_140016440)(param_1,0x10000001,0x6174645f,piVar19,uVar13,param_3[1]);
      uVar13 = EHCI_MapAsyncTransferToTd
                         (param_1,(uint)*(ushort *)(param_2 + 0x2c),uVar13,&local_54,
                          (longlong)param_4,(longlong)piVar19,param_5);
      local_50 = piVar19;
    }
    *local_50 = *piVar1;
    *(int **)(local_50 + 0x16) = piVar15;
    (*DAT_140016440)(param_1,0x10000001,0x6174735f,piVar15,0,local_58);
    *local_48 = 0;
    piVar15[0xf] = 0;
    if ((*param_3 & 1) == 0) {
      uVar13 = piVar15[2] & 0x7dffU | 0x80008100;
    }
    else {
      uVar13 = piVar15[2] & 31999U | 0x80008000;
    }
    piVar15[2] = uVar13;
    (*DAT_140016440)(param_1,0x10000001,0x6c61545f,*(undefined4 *)((longlong)param_4 + 0x14),
                     piVar19[0x10],piVar19);
    *piVar15 = *local_40;
    *(int **)local_38 = piVar16;
    iVar3 = *local_40;
    *(int **)(piVar15 + 0x18) = piVar16;
    *local_30 = iVar3;
    (*DAT_140016440)(param_1,0x10000001,0x7274635f,0,0,0);
    uVar12 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
    *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
    EHCI_iEnableAsyncList(param_1);
    *(undefined8 *)(param_1 + 0x118) = 0;
    KeReleaseSpinLock(param_1 + 0x110,uVar12);
    lVar8 = *(longlong *)(param_2 + 0x78);
    lVar9 = *(longlong *)(param_2 + 0x130);
    lVar10 = *(longlong *)(param_2 + 0x138);
    (*DAT_140016440)(param_1,0x10000001,0x51324c5f,lVar8,lVar10,lVar9);
    *(undefined4 *)(lVar8 + 0xc) = *(undefined4 *)(lVar9 + 0x40);
    *(undefined4 *)(lVar8 + 0x14) = *(undefined4 *)(lVar9 + 0x40);
    *(undefined4 *)(lVar8 + 0x10) = *(undefined4 *)(lVar9 + 0x40);
    *(uint *)(lVar8 + 0x18) = *(uint *)(lVar8 + 0x18) & 0x8000837d;
    *(uint *)(lVar10 + 8) = *(uint *)(lVar10 + 8) | 0x80;
    *(uint *)(lVar9 + 8) = *(uint *)(lVar9 + 8) | 0x80;
    uVar14 = 0;
  }
  return uVar14;
}



===== EHCI_AllocTd @ 1400049d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong EHCI_AllocTd(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (*(uint *)(param_2 + 0xd8) <= (uint)uVar2) {
      (*DAT_140016470)();
      return 0;
    }
    lVar1 = uVar2 * 0x80 + *(longlong *)(param_2 + 0xb8);
    if ((*(uint *)(lVar1 + 0x38) & 1) == 0) break;
    uVar2 = (ulonglong)((uint)uVar2 + 1);
  }
  if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
    *(uint *)(lVar1 + 0x38) = *(uint *)(lVar1 + 0x38) | 1;
    LOCK();
    UNLOCK();
  }
  else {
    LOCK();
    *(uint *)(lVar1 + 0x38) = *(uint *)(lVar1 + 0x38) | 1;
    UNLOCK();
  }
  (*DAT_140016440)(param_1,0x10000001,0x4454615f,lVar1,0,0);
  *(int *)(param_2 + 0xdc) = *(int *)(param_2 + 0xdc) + -1;
  return lVar1;
}



===== EHCI_EnableAsyncList @ 140004a80 =====

void EHCI_EnableAsyncList(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
  *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
  EHCI_iEnableAsyncList(param_1);
  *(undefined8 *)(param_1 + 0x118) = 0;
  KeReleaseSpinLock(param_1 + 0x110,uVar1);
  return;
}



===== EHCI_iEnableAsyncList @ 140004b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EHCI_iEnableAsyncList(longlong param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined1 local_88 [32];
  undefined8 *local_68;
  ulonglong local_60;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_88;
  puVar3 = *(uint **)(param_1 + 200);
  local_60 = 0;
  uVar5 = *puVar3;
  uVar6 = puVar3[1];
  uVar7 = (ulonglong)uVar6;
  local_68 = (undefined8 *)uVar7;
  (*DAT_140016440)(param_1,0x10000001,0x70555341,uVar5);
  if (uVar5 == 0xffffffff) {
    EHCI_SetAsyncScheduleState(param_1,1);
    local_60 = 0;
    local_68 = (undefined8 *)uVar7;
    (*DAT_140016440)(param_1,0x10000001,0x70555350,0xffffffff);
    EHCI_SetPeriodicScheduleState(param_1,1);
  }
  else {
    if ((uVar5 & 0x20) == 0 && (uVar6 >> 0xf & 1) == 0) {
      iVar2 = *(int *)(param_1 + 0x558);
      local_60 = 0;
      local_68 = (undefined8 *)0x1;
      (*DAT_140016440)(param_1,0x10000001,0x72545341,(longlong)iVar2);
      if (iVar2 != 1) {
        piVar1 = (int *)(param_1 + 0x570);
        *piVar1 = *piVar1 + 1;
        if (*piVar1 == 0) {
          *(undefined4 *)(param_1 + 0x570) = 1;
        }
      }
      if (*(int *)(param_1 + 0x558) != 2) {
        *(undefined4 *)(param_1 + 0x558) = 1;
      }
    }
    else if ((uVar5 & 0x20) != 0 && (uVar6 >> 0xf & 1) != 0) {
      local_60 = 0;
      local_68 = (undefined8 *)0x4;
      (*DAT_140016440)(param_1,0x10000001,0x72545341,(longlong)*(int *)(param_1 + 0x558));
      if (*(int *)(param_1 + 0x558) != 5) {
        *(undefined4 *)(param_1 + 0x558) = 4;
      }
    }
    local_60 = 0;
    local_68 = (undefined8 *)uVar7;
    (*DAT_140016440)(param_1,0x10000001,0x70555350,uVar5);
    if ((uVar5 & 0x10) == 0 && (uVar6 >> 0xe & 1) == 0) {
      local_60 = 0;
      local_68 = (undefined8 *)0x1;
      (*DAT_140016440)(param_1,0x10000001,0x72545350,(longlong)*(int *)(param_1 + 0x560));
      if (*(int *)(param_1 + 0x560) != 2) {
        *(undefined4 *)(param_1 + 0x560) = 1;
      }
    }
    if ((uVar5 & 0x10) != 0 && (uVar6 >> 0xe & 1) != 0) {
      local_60 = 0;
      local_68 = (undefined8 *)0x4;
      (*DAT_140016440)(param_1,0x10000001,0x72545350,(longlong)*(int *)(param_1 + 0x560));
      if (*(int *)(param_1 + 0x560) != 5) {
        *(undefined4 *)(param_1 + 0x560) = 4;
      }
    }
    if (((*(char *)(param_1 + 0x568) == '\0') || (*(int *)(param_1 + 0x578) != 0)) ||
       (*(int *)(param_1 + 0x55c) == 1)) {
      lVar4 = *(longlong *)(param_1 + 0xf0);
      local_60 = 0;
      local_68 = (undefined8 *)0x0;
      (*DAT_140016440)(param_1,0x10000001,0x3171615f,lVar4);
      uVar6 = *(uint *)(lVar4 + 0x44) & 0xffffffe3 | 2;
      local_60 = (ulonglong)uVar6;
      local_68 = (undefined8 *)uVar7;
      (*DAT_140016440)(param_1,0x10000001,0x3141655f,uVar5);
      if ((uVar5 & 0x20) == 0) {
        if (*(int *)(param_1 + 0x74) == 0) {
          uVar8 = 0;
          do {
            if ((((uint)uVar7 >> 10 ^ uVar5) & 0x20) == 0) break;
            KeStallExecutionProcessor(0x19);
            local_60 = 0;
            uVar5 = *puVar3;
            uVar7 = (ulonglong)puVar3[1];
            local_68 = (undefined8 *)uVar7;
            (*DAT_140016440)(param_1,0x10000001,0x5341655f,uVar5);
            uVar8 = uVar8 + 1;
          } while (uVar8 < 0xf);
          if ((((uint)uVar7 >> 10 ^ uVar5) & 0x20) != 0) {
            *(int *)(param_1 + 0x4f0) = *(int *)(param_1 + 0x4f0) + 1;
          }
        }
        if (((uint)uVar7 >> 0xf & 1) == 0) {
          puVar3[6] = uVar6;
          LOCK();
          UNLOCK();
        }
        *(int *)(param_1 + 0x4e0) = *(int *)(param_1 + 0x4e0) + 1;
        uVar5 = uVar5 & 0xffffffbf | 0x20;
        *puVar3 = uVar5;
        LOCK();
        UNLOCK();
        local_60 = 0;
        local_68 = (undefined8 *)0x3;
        (*DAT_140016440)(param_1,0x10000001,0x72545341,(longlong)*(int *)(param_1 + 0x558));
        local_68 = &local_48;
        *(undefined4 *)(param_1 + 0x558) = 3;
        local_48 = 0;
        uStack_40 = 0;
        (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_ASYNC_SCHEDULE_ENABLE,0,1);
      }
    }
    else {
      EHCI_SetAsyncScheduleState(param_1,2);
    }
  }
  local_60 = 0;
  local_68 = (undefined8 *)uVar7;
  (*DAT_140016440)(param_1,0x10000001,0x5841655f,uVar5);
  return;
}



===== EHCI_MapAsyncTransferToTd @ 140004f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int EHCI_MapAsyncTransferToTd
              (undefined8 param_1,uint param_2,uint param_3,uint *param_4,longlong param_5,
              longlong param_6,longlong param_7)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  
  (*DAT_140016440)(param_1,0x10000001,0x72704d5f,param_5,0,param_3);
  lVar2 = *(longlong *)(param_5 + 0x18);
  uVar7 = 0;
  if (*(uint *)(param_7 + 0x18) != 0) {
    piVar5 = (int *)(param_7 + 0x30);
    do {
      if (((uint)piVar5[1] <= param_3) && (param_3 < (uint)(piVar5[1] + *piVar5))) break;
      uVar7 = uVar7 + 1;
      piVar5 = piVar5 + 6;
    } while (uVar7 < *(uint *)(param_7 + 0x18));
  }
  uVar3 = (ulonglong)uVar7;
  (*DAT_140016440)(param_1,0x10000001,0x70704d5f,param_7,0,uVar3);
  lVar1 = param_7 + uVar3 * 0x18;
  uVar4 = uVar7 + 1;
  iVar8 = param_3 - *(int *)(lVar1 + 0x34);
  if (*(int *)(param_7 + 0x18) - uVar7 < 6) {
    uVar6 = *(int *)(lVar2 + 4) - param_3;
    (*DAT_140016440)(param_1,0x10000001,0x4f67735f,iVar8,uVar3,param_3);
    puVar9 = (undefined4 *)(param_6 + 0x24);
    uVar7 = 1;
    *(int *)(param_6 + 0xc) = *(int *)(lVar1 + 0x20) + iVar8;
    *(undefined4 *)(param_6 + 0x20) = *(undefined4 *)(lVar1 + 0x24);
    do {
      if (*(uint *)(param_7 + 0x18) <= uVar4) break;
      uVar3 = (ulonglong)uVar4;
      uVar7 = uVar7 + 1;
      uVar4 = uVar4 + 1;
      puVar9[-5] = *(undefined4 *)(param_7 + 0x20 + uVar3 * 0x18);
      *puVar9 = *(undefined4 *)(param_7 + 0x24 + uVar3 * 0x18);
      puVar9 = puVar9 + 1;
    } while (uVar7 < 5);
    (*DAT_140016440)(param_1,0x10000001,0x3167735f,*(undefined4 *)(param_6 + 0xc),
                     *(undefined4 *)(param_6 + 0x20),0);
  }
  else {
    (*DAT_140016440)(param_1,0x10000001,0x4f67735f,iVar8,uVar3,param_3);
    uVar6 = *(int *)(lVar1 + 0x20) + iVar8;
    *(uint *)(param_6 + 0xc) = uVar6;
    *(undefined4 *)(param_6 + 0x20) = *(undefined4 *)(lVar1 + 0x24);
    uVar6 = 0x5000 - (uVar6 & 0xfff);
    *(undefined4 *)(param_6 + 0x10) = *(undefined4 *)(param_7 + 0x20 + (ulonglong)uVar4 * 0x18);
    *(undefined4 *)(param_6 + 0x24) = *(undefined4 *)(param_7 + 0x24 + (ulonglong)uVar4 * 0x18);
    *(undefined4 *)(param_6 + 0x14) =
         *(undefined4 *)(param_7 + 0x20 + (ulonglong)(uVar7 + 2) * 0x18);
    *(undefined4 *)(param_6 + 0x28) =
         *(undefined4 *)(param_7 + (ulonglong)(uVar7 + 2) * 0x18 + 0x24);
    *(undefined4 *)(param_6 + 0x18) =
         *(undefined4 *)(param_7 + 0x20 + (ulonglong)(uVar7 + 3) * 0x18);
    *(undefined4 *)(param_6 + 0x2c) =
         *(undefined4 *)(param_7 + (ulonglong)(uVar7 + 3) * 0x18 + 0x24);
    *(undefined4 *)(param_6 + 0x1c) =
         *(undefined4 *)(param_7 + 0x20 + (ulonglong)(uVar7 + 4) * 0x18);
    *(undefined4 *)(param_6 + 0x30) =
         *(undefined4 *)(param_7 + (ulonglong)(uVar7 + 4) * 0x18 + 0x24);
    uVar3 = (ulonglong)uVar6 / (ulonglong)param_2;
    (*DAT_140016440)(param_1,0x10000001,0x3267735f,param_2,uVar3,uVar6);
    uVar7 = (int)uVar3 * param_2;
    if (uVar6 - uVar7 != 0) {
      (*DAT_140016440)(param_1,0x10000001,0x6a64615f,uVar6 - uVar7,uVar7,0);
      uVar6 = uVar7;
    }
    if ((param_4 != (uint *)0x0) && ((uVar3 & 1) != 0)) {
      *param_4 = (uint)(*param_4 == 0);
    }
  }
  *(uint *)(param_6 + 0x3c) = uVar6;
  *(uint *)(param_6 + 8) =
       (uVar6 << 0x10 ^ *(uint *)(param_6 + 8)) & 0x7fff0000 ^ *(uint *)(param_6 + 8);
  (*DAT_140016440)(param_1,0x10000001,0x31704d5f,param_3 + uVar6,uVar6,param_6);
  return param_3 + uVar6;
}



===== EHCI_iDisableAsyncList @ 1400052b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EHCI_iDisableAsyncList(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined1 local_78 [32];
  undefined8 *local_58;
  ulonglong local_50;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)local_78;
  puVar1 = *(uint **)(param_1 + 200);
  uVar2 = *puVar1;
  uVar3 = (ulonglong)uVar2;
  uVar5 = (ulonglong)puVar1[1];
  EHCI_UpdateScheduleStates(param_1,uVar2,puVar1[1]);
  local_50 = 0;
  local_58 = (undefined8 *)uVar5;
  (*DAT_140016440)(param_1,0x10000001,0x4173645f,uVar2);
  if (uVar2 != 0xffffffff) {
    if (((*(char *)(param_1 + 0x568) == '\0') || (*(int *)(param_1 + 0x578) != 0)) ||
       (*(int *)(param_1 + 0x55c) == 1)) {
      if ((*(longlong **)(param_1 + 0x100) == (longlong *)(param_1 + 0x100)) &&
         (*(longlong *)(param_1 + 0x120) == 0)) {
        if (*(int *)(param_1 + 0x7c) == 0) {
          if ((*(longlong **)(param_1 + 0x80) == (longlong *)(param_1 + 0x80)) &&
             (*(int *)(param_1 + 0x38) != 0)) {
            if (*(longlong **)(param_1 + 0xb0) == (longlong *)(param_1 + 0xb0)) {
              if ((uVar2 & 0x20) != 0) {
                if (*(int *)(param_1 + 0x74) == 0) {
                  uVar4 = 0;
                  do {
                    uVar2 = (uint)uVar3;
                    if ((((uint)uVar5 >> 10 ^ uVar2) & 0x20) == 0) break;
                    KeStallExecutionProcessor(0x19);
                    local_50 = 0;
                    uVar2 = *puVar1;
                    uVar3 = (ulonglong)uVar2;
                    uVar5 = (ulonglong)puVar1[1];
                    local_58 = (undefined8 *)uVar5;
                    (*DAT_140016440)(param_1,0x10000001,0x5341645f,uVar2);
                    uVar4 = uVar4 + 1;
                  } while (uVar4 < 0xf);
                  if ((((uint)uVar5 >> 10 ^ uVar2) & 0x20) != 0) {
                    *(int *)(param_1 + 0x4f4) = *(int *)(param_1 + 0x4f4) + 1;
                  }
                }
                *(int *)(param_1 + 0x4e4) = *(int *)(param_1 + 0x4e4) + 1;
                uVar2 = uVar2 & 0xffffff9f;
                *puVar1 = uVar2;
                LOCK();
                UNLOCK();
                local_50 = 0;
                local_58 = (undefined8 *)0x6;
                (*DAT_140016440)(param_1,0x10000001,0x72545341,(longlong)*(int *)(param_1 + 0x558));
                local_58 = &local_38;
                *(undefined4 *)(param_1 + 0x558) = 6;
                local_38 = 0;
                uStack_30 = 0;
                (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_ASYNC_SCHEDULE_DISABLE,0,1);
              }
              goto LAB_1400053ba;
            }
            uVar6 = 0x3441645f;
          }
          else {
            uVar6 = 0x3341645f;
          }
        }
        else {
          uVar6 = 0x3241645f;
        }
      }
      else {
        uVar6 = 0x3141645f;
      }
    }
    else {
      EHCI_SetAsyncScheduleState(param_1,5);
      uVar6 = 0x3041645f;
    }
    local_58 = (undefined8 *)0x0;
    local_50 = uVar3;
    (*DAT_140016440)(param_1,0x10000001,uVar6,0);
  }
LAB_1400053ba:
  local_50 = 0;
  local_58 = (undefined8 *)uVar5;
  (*DAT_140016440)(param_1,0x10000001,0x5841645f,uVar2);
  return;
}



===== EHCI_UpdateScheduleStates @ 140005560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_UpdateScheduleStates(longlong param_1,uint param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  (*DAT_140016440)(param_1,0x10000001,0x70555341,param_2,param_3,0);
  if (param_2 == 0xffffffff) {
    EHCI_SetAsyncScheduleState(param_1,1);
    (*DAT_140016440)(param_1,0x10000001,0x70555350,0xffffffff,param_3,0);
    EHCI_SetPeriodicScheduleState(param_1,1);
  }
  else {
    uVar3 = param_2 >> 5 & 1;
    if ((param_3 >> 0xf & 1) == 0) {
      if (uVar3 == 0) {
        iVar2 = *(int *)(param_1 + 0x558);
        (*DAT_140016440)(param_1,0x10000001,0x72545341,(longlong)iVar2,1,0);
        if (iVar2 != 1) {
          piVar1 = (int *)(param_1 + 0x570);
          *piVar1 = *piVar1 + 1;
          if (*piVar1 == 0) {
            *(undefined4 *)(param_1 + 0x570) = 1;
          }
        }
        if (*(int *)(param_1 + 0x558) != 2) {
          *(undefined4 *)(param_1 + 0x558) = 1;
        }
      }
    }
    else if (uVar3 != 0) {
      (*DAT_140016440)(param_1,0x10000001,0x72545341,(longlong)*(int *)(param_1 + 0x558),4,0);
      if (*(int *)(param_1 + 0x558) != 5) {
        *(undefined4 *)(param_1 + 0x558) = 4;
      }
    }
    (*DAT_140016440)(param_1,0x10000001,0x70555350,param_2,param_3,0);
    if ((param_3 >> 0xe & 1) == 0) {
      if ((param_2 & 0x10) == 0) {
        (*DAT_140016440)(param_1,0x10000001,0x72545350,(longlong)*(int *)(param_1 + 0x560),1,0);
        if (*(int *)(param_1 + 0x560) != 2) {
          *(undefined4 *)(param_1 + 0x560) = 1;
        }
      }
    }
    else if ((param_2 & 0x10) != 0) {
      (*DAT_140016440)(param_1,0x10000001,0x72545350,(longlong)*(int *)(param_1 + 0x560),4,0);
      if (*(int *)(param_1 + 0x560) != 5) {
        *(undefined4 *)(param_1 + 0x560) = 4;
      }
    }
  }
  return;
}



===== EHCI_iDisablePeriodicList @ 1400057b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EHCI_iDisablePeriodicList(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 local_78 [32];
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)local_78;
  puVar1 = *(uint **)(param_1 + 200);
  uVar2 = *puVar1;
  uVar4 = puVar1[1];
  uVar5 = (ulonglong)uVar4;
  EHCI_UpdateScheduleStates(param_1,uVar2,uVar4);
  local_50 = 0;
  local_58 = (undefined8 *)uVar5;
  (*DAT_140016440)(param_1,0x10000001,0x5069645f,uVar2);
  if (((*(char *)(param_1 + 0x568) == '\0') || (*(int *)(param_1 + 0x578) != 0)) ||
     (*(int *)(param_1 + 0x55c) == 1)) {
    if ((uVar2 & 0x10) != 0) {
      if (*(int *)(param_1 + 0x78) == 0) {
        uVar3 = 0;
        do {
          uVar4 = (uint)uVar5;
          if (((uVar4 >> 10 ^ uVar2) & 0x10) == 0) break;
          KeStallExecutionProcessor(0x19);
          local_50 = 0;
          uVar2 = *puVar1;
          uVar4 = puVar1[1];
          uVar5 = (ulonglong)uVar4;
          local_58 = (undefined8 *)uVar5;
          (*DAT_140016440)(param_1,0x10000001,0x5370645f,uVar2);
          uVar3 = uVar3 + 1;
        } while (uVar3 < 0xf);
        if (((uVar4 >> 10 ^ uVar2) & 0x10) != 0) {
          *(int *)(param_1 + 0x4fc) = *(int *)(param_1 + 0x4fc) + 1;
        }
      }
      *(int *)(param_1 + 0x4ec) = *(int *)(param_1 + 0x4ec) + 1;
      uVar2 = uVar2 & 0xffffffaf;
      *puVar1 = uVar2;
      LOCK();
      UNLOCK();
      EHCI_SetPeriodicScheduleState(param_1,6);
      local_58 = &local_38;
      local_38 = 0;
      uStack_30 = 0;
      (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_PERIODIC_SCHEDULE_DISABLE,0,1);
    }
  }
  else {
    local_50 = 0;
    local_58 = (undefined8 *)0x5;
    (*DAT_140016440)(param_1,0x10000001,0x72545350,(longlong)*(int *)(param_1 + 0x560));
    *(int *)(param_1 + 0x584) = *(int *)(param_1 + 0x584) + 1;
    *(undefined4 *)(param_1 + 0x560) = 5;
  }
  local_50 = 0;
  local_58 = (undefined8 *)(ulonglong)uVar4;
  (*DAT_140016440)(param_1,0x10000001,0x5869645f,uVar2);
  return;
}



===== EHCI_DisablePeriodicList @ 14000599c =====

void EHCI_DisablePeriodicList(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
  *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
  EHCI_iDisablePeriodicList(param_1);
  *(undefined8 *)(param_1 + 0x118) = 0;
  KeReleaseSpinLock(param_1 + 0x110,uVar1);
  return;
}



===== EHCI_CheckHwSync_Async @ 140005a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int EHCI_CheckHwSync_Async(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  uint *puVar4;
  undefined1 auVar5 [16];
  undefined1 uVar6;
  uint uVar7;
  ulonglong uVar8;
  int iVar9;
  ulonglong uVar10;
  int iStackX_14;
  
  lVar3 = param_2[0xf];
  puVar4 = *(uint **)(param_1 + 200);
  (*DAT_140016440)(param_1,0x10000001,0x3170635f,0,param_2,lVar3);
  lVar1 = param_1 + 0x110;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar7 = *puVar4;
    uVar2 = puVar4[1];
    EHCI_UpdateScheduleStates(param_1,uVar7,uVar2);
    if (((uVar2 >> 0xf & 1) == 0) && ((uVar7 & 0x20) == 0)) goto LAB_140005b83;
    iVar9 = *(int *)((longlong)param_2 + 0x84);
    (*DAT_140016440)(param_1,0x10000001,0x3470635f,0,iVar9,0);
    if (iVar9 != 1) {
      (*DAT_140016440)(param_1,0x10000001,0x3670635f,0,iVar9,0);
      uVar10 = _DAT_fffff78000000320;
      uVar8 = param_2[0x11];
      (*DAT_140016440)(param_1,0x10000001,0x3178635f,(longlong)(int)(uVar8 >> 0x20),
                       uVar8 & 0xffffffff,lVar3);
      iStackX_14 = (int)(uVar10 >> 0x20);
      (*DAT_140016440)(param_1,0x10000001,0x3278635f,(longlong)iStackX_14,uVar10 & 0xffffffff,lVar3)
      ;
      if ((longlong)uVar8 < (longlong)uVar10) {
        uVar10 = uVar10 - uVar8;
        uVar7 = KeQueryTimeIncrement();
        iStackX_14 = (int)(uVar10 >> 0x20);
        uVar8 = (ulonglong)uVar7;
        if (uVar7 == 0) {
          uVar8 = 1;
        }
        (*DAT_140016440)(param_1,0x10000001,0x3378635f,(longlong)iStackX_14,uVar10 & 0xffffffff,
                         uVar8);
        auVar5._8_8_ = 0;
        auVar5._0_8_ = SUB168(SEXT816(20000),8);
        if (SUB168((auVar5 << 0x40 | ZEXT816(20000)) / SEXT816((longlong)uVar8),0) <
            (longlong)uVar10) {
          (*DAT_140016440)(param_1,0x10000001,0x3478635f,0,0,lVar3);
          if (*(longlong **)(param_1 + 0x120) == param_2) {
            (*DAT_140016440)(param_1,0x10000001,0x3578635f,0,0,lVar3);
            EHCI_iAsyncCacheFlush(param_1,param_2,'\x01');
          }
        }
      }
      *(undefined8 *)(param_1 + 0x118) = 0;
      KeReleaseSpinLock(lVar1,uVar6);
      if (iVar9 == 0) {
        (*DAT_140016468)(param_1,3);
      }
      goto LAB_140005b34;
    }
  }
  else {
LAB_140005b83:
    (*DAT_140016440)(param_1,0x10000001,0x3270635f,0,*(uint *)(lVar3 + 0x4c) & 1,lVar3);
    EHCI_ClearAsyncDoorbellList(param_1);
    iVar9 = 1;
    EHCI_UpdateEndpointAsFreedFromHwCache(param_1,(longlong)param_2);
  }
  (*DAT_140016440)();
  *(undefined8 *)(param_1 + 0x118) = 0;
  KeReleaseSpinLock(lVar1,uVar6);
LAB_140005b34:
  (*DAT_140016440)(param_1,0x10000001,0x3770635f,0,iVar9,0);
  return iVar9;
}



===== EHCI_RH_ClearFeaturePortSuspend @ 140005d90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_RH_ClearFeaturePortSuspend(longlong param_1,ushort param_2)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort local_38 [4];
  longlong *local_30;
  uint local_28;
  undefined1 local_24;
  
  lVar1 = *(longlong *)(param_1 + 200);
  uVar4 = 0;
  uVar6 = (ulonglong)param_2;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  if ((lVar1 != 0) && (param_2 != *(ushort *)(param_1 + 1000))) {
    uVar5 = 1 << ((char)param_2 - 1U & 0x1f);
    *(uint *)(param_1 + 0x140) = *(uint *)(param_1 + 0x140) | uVar5;
    uVar3 = *(uint *)(lVar1 + 0x40 + uVar6 * 4);
    (*DAT_140016440)(param_1,0x10000001,0x7372505f,uVar6,uVar3,0);
    *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) | uVar5;
    uVar3 = uVar3 | 0x40;
    *(uint *)(lVar1 + 0x40 + uVar6 * 4) = uVar3;
    LOCK();
    UNLOCK();
    bVar2 = 0x32;
    if (*(int *)(param_1 + 0x5fc + uVar6 * 4) != 0) {
      bVar2 = *(byte *)(uVar6 + 0x63b + param_1);
    }
    local_24 = 0;
    local_38[0] = param_2;
    local_28 = (uint)bVar2;
    local_30 = EHCI_RefAsyncIdle(param_1,2);
    uVar5 = (*DAT_140016568)(param_1,(uint)bVar2,local_38,0x18,EHCI_RH_PortResumeComplete,0,1);
    (*DAT_140016440)(param_1,0x10000001,0x3272505f,uVar6,uVar3,(longlong)(int)uVar5);
    uVar4 = 0;
    if ((uVar5 & 0xc0000000) == 0xc0000000) {
      if (local_30 != (longlong *)0x0) {
        EHCI_DerefAsyncIdle(param_1,local_30);
      }
      uVar4 = 5;
    }
  }
  return uVar4;
}



===== EHCI_RefAsyncIdle @ 140005f18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong * EHCI_RefAsyncIdle(longlong param_1,int param_2)

{
  longlong *plVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong *plVar4;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
  *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
  plVar4 = (longlong *)EHCI_AllocNpPool(0x20);
  (*DAT_140016440)(param_1,0x10000001,0x6961725f,0,(longlong)param_2,plVar4);
  if (plVar4 == (longlong *)0x0) {
    *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 1;
  }
  else {
    plVar4[3] = 0;
    *(undefined4 *)(plVar4 + 2) = 0x46526961;
    *(int *)((longlong)plVar4 + 0x14) = param_2;
    plVar1 = *(longlong **)(param_1 + 0xb8);
    if (*plVar1 != param_1 + 0xb0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      plVar4 = (longlong *)(*pcVar2)();
      return plVar4;
    }
    *plVar4 = param_1 + 0xb0;
    plVar4[1] = (longlong)plVar1;
    *plVar1 = (longlong)plVar4;
    *(longlong **)(param_1 + 0xb8) = plVar4;
  }
  EHCI_iEnableAsyncList(param_1);
  *(undefined8 *)(param_1 + 0x118) = 0;
  KeReleaseSpinLock(param_1 + 0x110,uVar3);
  return plVar4;
}



===== EHCI_EtwLogDeviceData @ 14000601c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_EtwLogDeviceData(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = EHCI_AllocNpPool(800);
  if (lVar1 != 0) {
    *(undefined8 *)(lVar1 + 0x18) = 4;
    *(longlong *)(lVar1 + 0x10) = param_1 + 0x28;
    *(longlong *)(lVar1 + 0x20) = param_1 + 0x3dc;
    *(undefined8 *)(lVar1 + 0x28) = 4;
    *(longlong *)(lVar1 + 0x30) = param_1 + 0x3e0;
    *(undefined8 *)(lVar1 + 0x38) = 4;
    *(longlong *)(lVar1 + 0x40) = param_1 + 0x3e4;
    *(undefined8 *)(lVar1 + 0x48) = 4;
    *(longlong *)(lVar1 + 0x50) = param_1 + 0x4e0;
    *(undefined8 *)(lVar1 + 0x58) = 4;
    *(longlong *)(lVar1 + 0x60) = param_1 + 0x4e4;
    *(undefined8 *)(lVar1 + 0x68) = 4;
    *(longlong *)(lVar1 + 0x70) = param_1 + 0x4e8;
    *(undefined8 *)(lVar1 + 0x78) = 4;
    *(longlong *)(lVar1 + 0x80) = param_1 + 0x4ec;
    *(undefined8 *)(lVar1 + 0x88) = 4;
    *(longlong *)(lVar1 + 0x90) = param_1 + 0x4f0;
    *(undefined8 *)(lVar1 + 0x98) = 4;
    *(longlong *)(lVar1 + 0xa0) = param_1 + 0x4f4;
    *(undefined8 *)(lVar1 + 0xa8) = 4;
    *(longlong *)(lVar1 + 0xb0) = param_1 + 0x4f8;
    *(undefined8 *)(lVar1 + 0xb8) = 4;
    *(longlong *)(lVar1 + 0xc0) = param_1 + 0x4fc;
    *(undefined8 *)(lVar1 + 200) = 4;
    *(longlong *)(lVar1 + 0xd0) = param_1 + 0x500;
    *(undefined8 *)(lVar1 + 0xd8) = 4;
    *(longlong *)(lVar1 + 0xe0) = param_1 + 0x504;
    *(undefined8 *)(lVar1 + 0xe8) = 4;
    *(longlong *)(lVar1 + 0xf0) = param_1 + 0x508;
    *(undefined8 *)(lVar1 + 0xf8) = 4;
    *(longlong *)(lVar1 + 0x100) = param_1 + 0x50c;
    *(undefined8 *)(lVar1 + 0x108) = 4;
    *(longlong *)(lVar1 + 0x110) = param_1 + 0x510;
    *(undefined8 *)(lVar1 + 0x118) = 4;
    *(longlong *)(lVar1 + 0x120) = param_1 + 0x514;
    *(undefined8 *)(lVar1 + 0x128) = 4;
    *(longlong *)(lVar1 + 0x130) = param_1 + 0x518;
    *(undefined8 *)(lVar1 + 0x138) = 4;
    *(longlong *)(lVar1 + 0x140) = param_1 + 0x51c;
    *(undefined8 *)(lVar1 + 0x148) = 4;
    *(longlong *)(lVar1 + 0x150) = param_1 + 0x520;
    *(undefined8 *)(lVar1 + 0x158) = 4;
    *(longlong *)(lVar1 + 0x160) = param_1 + 0x524;
    *(undefined8 *)(lVar1 + 0x168) = 4;
    *(longlong *)(lVar1 + 0x170) = param_1 + 0x528;
    *(undefined8 *)(lVar1 + 0x178) = 4;
    *(longlong *)(lVar1 + 0x180) = param_1 + 0x52c;
    *(undefined8 *)(lVar1 + 0x188) = 4;
    *(longlong *)(lVar1 + 400) = param_1 + 0x530;
    *(undefined8 *)(lVar1 + 0x198) = 4;
    *(longlong *)(lVar1 + 0x1a0) = param_1 + 0x534;
    *(undefined8 *)(lVar1 + 0x1a8) = 4;
    *(longlong *)(lVar1 + 0x1b0) = param_1 + 0x538;
    *(undefined8 *)(lVar1 + 0x1b8) = 4;
    *(undefined8 *)(lVar1 + 0x1c8) = 4;
    *(longlong *)(lVar1 + 0x1c0) = param_1 + 0x53c;
    *(undefined8 *)(lVar1 + 0x1d8) = 4;
    *(longlong *)(lVar1 + 0x1d0) = param_1 + 0x540;
    *(undefined8 *)(lVar1 + 0x1e8) = 4;
    *(longlong *)(lVar1 + 0x1e0) = param_1 + 0x544;
    *(undefined8 *)(lVar1 + 0x1f8) = 4;
    *(longlong *)(lVar1 + 0x1f0) = param_1 + 0x548;
    *(undefined8 *)(lVar1 + 0x208) = 4;
    *(longlong *)(lVar1 + 0x200) = param_1 + 0x54c;
    *(longlong *)(lVar1 + 0x210) = param_1 + 0x550;
    *(undefined8 *)(lVar1 + 0x218) = 4;
    *(longlong *)(lVar1 + 0x220) = param_1 + 0x554;
    *(undefined8 *)(lVar1 + 0x228) = 4;
    *(longlong *)(lVar1 + 0x230) = param_1 + 0x558;
    *(undefined8 *)(lVar1 + 0x238) = 4;
    *(longlong *)(lVar1 + 0x240) = param_1 + 0x55c;
    *(undefined8 *)(lVar1 + 0x248) = 4;
    *(longlong *)(lVar1 + 0x250) = param_1 + 0x560;
    *(undefined8 *)(lVar1 + 600) = 4;
    *(longlong *)(lVar1 + 0x260) = param_1 + 0x564;
    *(undefined8 *)(lVar1 + 0x268) = 4;
    *(longlong *)(lVar1 + 0x270) = param_1 + 0x568;
    *(undefined8 *)(lVar1 + 0x278) = 1;
    *(longlong *)(lVar1 + 0x280) = param_1 + 0x569;
    *(undefined8 *)(lVar1 + 0x288) = 1;
    *(longlong *)(lVar1 + 0x290) = param_1 + 0x56a;
    *(undefined8 *)(lVar1 + 0x298) = 1;
    *(longlong *)(lVar1 + 0x2a0) = param_1 + 0x56b;
    *(undefined8 *)(lVar1 + 0x2a8) = 1;
    *(longlong *)(lVar1 + 0x2b0) = param_1 + 0x56c;
    *(undefined8 *)(lVar1 + 0x2b8) = 1;
    *(longlong *)(lVar1 + 0x2c0) = param_1 + 0x570;
    *(undefined8 *)(lVar1 + 0x2c8) = 4;
    *(longlong *)(lVar1 + 0x2d0) = param_1 + 0x574;
    *(undefined8 *)(lVar1 + 0x2d8) = 4;
    *(longlong *)(lVar1 + 0x2e0) = param_1 + 0x578;
    *(undefined8 *)(lVar1 + 0x2e8) = 4;
    *(longlong *)(lVar1 + 0x2f0) = param_1 + 0x57c;
    *(undefined8 *)(lVar1 + 0x2f8) = 4;
    *(longlong *)(lVar1 + 0x300) = param_1 + 0x580;
    *(undefined8 *)(lVar1 + 0x308) = 4;
    *(longlong *)(lVar1 + 0x310) = param_1 + 0x584;
    *(undefined8 *)(lVar1 + 0x318) = 4;
    (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_DEVICE_DATA,0,0x32,lVar1);
    ExFreePoolWithTag(lVar1,0);
  }
  return 0;
}



===== EHCI_AllocNpPool @ 140006524 =====

void EHCI_AllocNpPool(undefined4 param_1)

{
  ExAllocatePool2(0x40,param_1,0x65686369);
  return;
}



===== EHCI_iAsyncCacheFlush @ 140006550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EHCI_iAsyncCacheFlush(longlong param_1,longlong *param_2,char param_3)

{
  longlong *plVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  code *pcVar6;
  undefined8 uVar7;
  
  lVar4 = param_2[0xf];
  (*DAT_140016440)(param_1,0x10000001,0x3166615f,lVar4,param_2,*(undefined8 *)(param_1 + 0x118));
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar2 = **(uint **)(param_1 + 200);
    uVar3 = (*(uint **)(param_1 + 200))[1];
    EHCI_UpdateScheduleStates(param_1,uVar2,uVar3);
    if ((((uVar2 & 0x20) != 0 || (uVar3 >> 0xf & 1) != 0) && ((uVar2 & 1) != 0)) &&
       (uVar2 != 0xffffffff)) {
      if ((*(char *)(param_1 + 0x569) != '\0') &&
         (*(int *)((longlong)param_2 + 0x14c) != *(int *)(param_1 + 0x570))) {
        (*DAT_140016440)(param_1,0x10000001,0x72506851,param_2,lVar4,0);
        EHCI_UpdateEndpointAsFreedFromHwCache(param_1,(longlong)param_2);
        *(int *)(param_1 + 0x534) = *(int *)(param_1 + 0x534) + 1;
        return;
      }
      plVar1 = (longlong *)(param_1 + 0x100);
      if (param_3 == '\0') {
        *(int *)(param_1 + 0x51c) = *(int *)(param_1 + 0x51c) + 1;
        lVar4 = _DAT_fffff78000000320;
        *(undefined4 *)((longlong)param_2 + 0x84) = 0;
        param_2[0x11] = lVar4;
        *(uint *)(param_2 + 0x12) = 2 - (uint)(*(char *)(param_1 + 0x56a) != '\0');
        puVar5 = *(undefined8 **)(param_1 + 0x108);
        if ((longlong *)*puVar5 != plVar1) goto LAB_140006772;
        *param_2 = (longlong)plVar1;
        uVar7 = 0x3566615f;
        param_2[1] = (longlong)puVar5;
        *puVar5 = param_2;
        *(longlong **)(param_1 + 0x108) = param_2;
      }
      else {
        *(int *)(param_1 + 0x520) = *(int *)(param_1 + 0x520) + 1;
        *(undefined8 *)(param_1 + 0x120) = 0;
        param_2[0x11] = _DAT_fffff78000000320;
        lVar4 = *plVar1;
        if (*(longlong **)(lVar4 + 8) != plVar1) {
LAB_140006772:
          pcVar6 = (code *)swi(0x29);
          (*pcVar6)(3);
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        *param_2 = lVar4;
        uVar7 = 0x3666615f;
        param_2[1] = (longlong)plVar1;
        *(longlong **)(lVar4 + 8) = param_2;
        *plVar1 = (longlong)param_2;
      }
      (*DAT_140016440)(param_1,0x10000001,uVar7,param_2,0,0);
      EHCI_RingAsyncDoorbell(param_1);
      return;
    }
  }
  *(int *)(param_1 + 0x518) = *(int *)(param_1 + 0x518) + 1;
  (*DAT_140016440)(param_1,0x10000001,0x3266615f,lVar4,0,0);
  EHCI_UpdateEndpointAsFreedFromHwCache(param_1,(longlong)param_2);
  EHCI_ClearAsyncDoorbellList(param_1);
  return;
}



===== EHCI_ClearAsyncDoorbellList @ 140006780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_ClearAsyncDoorbellList(longlong param_1)

{
  undefined4 uVar1;
  int iVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  code *pcVar6;
  undefined1 *puVar7;
  undefined1 local_48 [8];
  undefined1 auStack_40 [24];
  longlong *local_28;
  undefined8 local_20;
  
  local_20 = 0;
  local_28 = (longlong *)0x0;
  (*DAT_140016440)(param_1,0x10000001,0x306c635f,0);
  plVar3 = *(longlong **)(param_1 + 0x120);
  *(undefined8 *)(param_1 + 0x538) = 0;
  *(undefined8 *)(param_1 + 0x540) = 0;
  if (plVar3 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x120) = 0;
    local_20 = 0;
    local_28 = plVar3;
    (*DAT_140016440)(param_1,0x10000001,0x316c635f,0);
    EHCI_UpdateEndpointAsFreedFromHwCache(param_1,(longlong)plVar3);
    *plVar3 = 0;
    plVar3[1] = 0;
  }
  puVar7 = local_48;
  plVar3 = (longlong *)(param_1 + 0x100);
  do {
    plVar4 = (longlong *)*plVar3;
    if (plVar4 == plVar3) {
      uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0xf0) + 0x44);
      if (*(int *)(param_1 + 0x28) == 0) {
        *(undefined4 *)(*(longlong *)(param_1 + 200) + 0x18) = uVar1;
        LOCK();
        UNLOCK();
      }
      else {
        *(undefined4 *)(param_1 + 0x3c0) = uVar1;
      }
      iVar2 = *(int *)(param_1 + 0x55c);
      local_20 = 0;
      local_28 = (longlong *)0x1;
      (*DAT_140016440)(param_1,0x10000001,0x75434441,(longlong)iVar2);
      *(undefined4 *)(param_1 + 0x55c) = 1;
      if (iVar2 != 1) {
LAB_140006936:
        *(undefined8 *)(param_1 + 0x538) = 0;
        *(undefined8 *)(param_1 + 0x540) = 0;
        if (*(int *)(param_1 + 0x28) == 0) {
          if (*(int *)(param_1 + 0x558) == 2) {
            *(undefined8 *)(puVar7 + -8) = 0x140006960;
            EHCI_iEnableAsyncList(param_1);
          }
          else if (*(int *)(param_1 + 0x558) == 5) {
            *(undefined8 *)(puVar7 + -8) = 0x14000696f;
            EHCI_iDisableAsyncList(param_1);
          }
          if (*(int *)(param_1 + 0x560) == 2) {
            *(undefined8 *)(puVar7 + -8) = 0x140006982;
            EHCI_iEnablePeriodicList(param_1);
          }
          else if (*(int *)(param_1 + 0x560) == 5) {
            *(undefined8 *)(puVar7 + -8) = 0x140006998;
            EHCI_iDisablePeriodicList(param_1);
          }
        }
      }
      return;
    }
    if (((longlong *)plVar4[1] != plVar3) || (lVar5 = *plVar4, *(longlong **)(lVar5 + 8) != plVar4))
    {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar7 = auStack_40;
      goto LAB_140006936;
    }
    *plVar3 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar3;
    local_20 = 0;
    local_28 = (longlong *)0x0;
    (*DAT_140016440)(param_1,0x10000001,0x326c635f,plVar4);
    local_20 = 0;
    local_28 = plVar4;
    (*DAT_140016440)(param_1,0x10000001,0x336c635f,0);
    EHCI_UpdateEndpointAsFreedFromHwCache(param_1,(longlong)plVar4);
    *plVar4 = 0;
    plVar4[1] = 0;
  } while( true );
}



===== EHCI_RingAsyncDoorbell @ 1400069a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_RingAsyncDoorbell(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  int iVar6;
  longlong *plVar7;
  undefined8 uVar8;
  uint *puVar9;
  
  puVar9 = *(uint **)(param_1 + 200);
  (*DAT_140016440)(param_1,0x10000001,0x3067725f,puVar9,0,*(undefined8 *)(param_1 + 0x118));
  uVar1 = *puVar9;
  plVar7 = (longlong *)(ulonglong)uVar1;
  uVar2 = puVar9[1];
  (*DAT_140016440)(param_1,0x10000001,0x3167725f,0,plVar7,uVar2);
  EHCI_UpdateScheduleStates(param_1,uVar1,uVar2);
  if ((*(uint **)(param_1 + 0x120) == (uint *)0x0) || (uVar1 == 0xffffffff)) {
    plVar7 = (longlong *)(param_1 + 0x100);
    plVar3 = (longlong *)*plVar7;
    if (plVar3 != plVar7) {
      if (((longlong *)plVar3[1] != plVar7) ||
         (lVar5 = *plVar3, *(longlong **)(lVar5 + 8) != plVar3)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *plVar7 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar7;
      (*DAT_140016440)(param_1,0x10000001,0x3467725f,plVar3,0,0);
      *plVar3 = 0;
      plVar3[1] = 0;
      if (uVar1 == 0xffffffff) {
        EHCI_UpdateEndpointAsFreedFromHwCache(param_1,(longlong)plVar3);
        *(int *)(param_1 + 0x510) = *(int *)(param_1 + 0x510) + 1;
        return;
      }
      if ((uVar1 & 0x20) == 0 && (uVar2 >> 0xf & 1) == 0) {
        (*DAT_140016440)(param_1,0x10000001,0x3567725f,plVar3,0,0);
        lVar5 = param_1;
        EHCI_UpdateEndpointAsFreedFromHwCache(param_1,(longlong)plVar3);
        EHCI_ClearAsyncDoorbellList(lVar5);
        *(int *)(param_1 + 0x500) = *(int *)(param_1 + 0x500) + 1;
        return;
      }
      if ((uVar1 & 0x20) == 0 && (uVar2 >> 0xf & 1) != 0) {
        (*DAT_140016440)(param_1,0x10000001,0x3667725f,plVar3,0,0);
        *(int *)(param_1 + 0x504) = *(int *)(param_1 + 0x504) + 1;
        iVar6 = 3;
      }
      else {
        if ((uVar1 & 0x20) == 0 || (uVar2 >> 0xf & 1) != 0) {
          *(longlong **)(param_1 + 0x120) = plVar3;
          if ((*(int *)(param_1 + 0x540) != 0) && (*(int *)(param_1 + 0x578) == 0)) {
            (*DAT_140016440)(param_1,0x10000001,0x5867725f,plVar3,plVar3[0xf],
                             *(int *)(param_1 + 0x540));
            *(int *)(param_1 + 0x530) = *(int *)(param_1 + 0x530) + 1;
            return;
          }
          (*DAT_140016440)(param_1,0x10000001,0x2167725f,plVar3,plVar3[0xf],0);
          *puVar9 = uVar1 | 0x40;
          LOCK();
          UNLOCK();
          if (*(int *)(param_1 + 0x540) == 0) {
            (*DAT_140016440)(param_1,0x10000001,0x30216772,plVar3,plVar3[0xf],0);
            EHCI_SetAsyncDoorbellState(param_1,4);
            *(int *)(param_1 + 0x50c) = *(int *)(param_1 + 0x50c) + 1;
            return;
          }
          (*DAT_140016440)(param_1,0x10000001,0x31216772,plVar3,plVar3[0xf],0);
          EHCI_SetAsyncDoorbellState(param_1,5);
          *(int *)(param_1 + 0x52c) = *(int *)(param_1 + 0x52c) + 1;
          return;
        }
        (*DAT_140016440)(param_1,0x10000001,0x3767725f,plVar3,0,0);
        *(int *)(param_1 + 0x508) = *(int *)(param_1 + 0x508) + 1;
        iVar6 = 2;
      }
      *(longlong **)(param_1 + 0x120) = plVar3;
      EHCI_SetAsyncDoorbellState(param_1,iVar6);
      return;
    }
    uVar8 = 0x3367725f;
  }
  else {
    uVar8 = 0x3267725f;
    puVar9 = *(uint **)(param_1 + 0x120);
  }
  (*DAT_140016440)(param_1,0x10000001,uVar8,puVar9,plVar7,0);
  return;
}



===== EHCI_AbortTransfer @ 140006d00 =====

void EHCI_AbortTransfer(longlong param_1,longlong param_2,longlong *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x3c);
  if (iVar1 == 1) {
    EHCI_AbortControlTransfer(param_1,param_2,(longlong)param_3);
  }
  else if ((iVar1 == 2) || (iVar1 == 3)) {
    EHCI_sMode_AbortAsyncTransfer(param_1,param_2,param_3);
  }
  else {
    EHCI_AbortIsoTransfer(param_1,param_2,param_3);
  }
  *param_4 = *(undefined4 *)((longlong)param_3 + 0x24);
  return;
}



===== EHCI_sMode_AbortAsyncTransfer @ 140006d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_sMode_AbortAsyncTransfer(longlong param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  int *piVar5;
  
  lVar3 = *(longlong *)(param_2 + 0x78);
  (*DAT_140016440)(param_1,0x10000001,0x3161735f,lVar3,param_3,param_2);
  piVar5 = (int *)param_3[0xb];
  EHCI_sMode_AbortSlot(param_1,param_2,(longlong)piVar5,(longlong)param_3);
  EHCI_DecPendingTransfer(param_1,param_2,param_3);
  iVar1 = *(int *)(param_3[3] + 8);
  (*DAT_140016440)(param_1,0x10000001,0x3261735f,iVar1,param_3,param_2);
  piVar5 = (int *)EHCI_sMode_IncSlotIdx(param_1,param_2,piVar5);
  iVar2 = piVar5[2];
  while (iVar2 == 1) {
    lVar4 = *(longlong *)(piVar5 + 8);
    (*DAT_140016440)(param_1,0x10000001,0x3361735f,lVar4,iVar1,piVar5);
    lVar4 = *(longlong *)(lVar4 + 0x50);
    (*DAT_140016440)(param_1,0x10000001,0x3461735f,lVar4,iVar1,piVar5);
    if (*(int *)(*(longlong *)(lVar4 + 0x18) + 8) != iVar1) break;
    piVar5[2] = 2;
    piVar5 = (int *)EHCI_sMode_IncSlotIdx(param_1,param_2,piVar5);
    (*DAT_140016440)(param_1,0x10000001,0x3561735f,0,0,piVar5);
    iVar2 = piVar5[2];
  }
  if (piVar5[2] == 1) {
    (*DAT_140016440)(param_1,0x10000001,0x3661735f,0,0,piVar5);
  }
  *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(*(longlong *)(piVar5 + 6) + 0x40);
  if (piVar5[2] == 1) {
    *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(*(longlong *)(piVar5 + 6) + 0x40);
    *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)(*(longlong *)(piVar5 + 6) + 0x40);
  }
  else {
    *(undefined4 *)(lVar3 + 0x10) = 1;
    *(undefined4 *)(lVar3 + 0x14) = 1;
  }
  *(uint *)(lVar3 + 0x18) = *(uint *)(lVar3 + 0x18) & 0x80008f7d | 0xc00;
  return;
}



===== EHCI_sMode_PollEndpoint @ 140006f60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong EHCI_sMode_PollEndpoint(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int *piVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x78);
  if ((*(uint *)(lVar1 + 0x4c) & 2) != 0) {
    uVar3 = (*DAT_140016440)(param_1,0x10000001,0x4d52715f,param_2,0,0);
    return uVar3;
  }
  piVar2 = *(int **)(param_2 + 0x168);
  while ((uVar3 = 0, piVar2 != (int *)0x0 &&
         (uVar3 = EHCI_sMode_PollEndpointSlot(param_1,param_2,piVar2), (char)uVar3 != '\0'))) {
    piVar2 = *(int **)(param_2 + 0x168);
  }
  if (*(int *)(param_2 + 0x70) == 1) {
    uVar3 = (ulonglong)*(uint *)(lVar1 + 0x18);
  }
  return uVar3;
}



===== EHCI_sMode_PollEndpointSlot @ 140007010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 EHCI_sMode_PollEndpointSlot(longlong param_1,longlong param_2,int *param_3)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  int iVar7;
  ulonglong uVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  longlong *plVar16;
  bool bVar17;
  char local_res10;
  longlong local_60;
  
  plVar16 = (longlong *)0x0;
  local_60 = 0;
LAB_140007037:
  uVar14 = 0;
  lVar4 = *(longlong *)(param_2 + 0x78);
  uVar12 = *(uint *)(lVar4 + 0xc) & 0xffffffe0;
  (*DAT_140016440)(param_1,0x10000001,0x6c70535f,lVar4,param_3,uVar12);
  uVar15 = (*DAT_140016448)(uVar12,param_1,param_2);
  uVar8 = (*DAT_140016440)(param_1,0x10000001,0x3164685f,0,0,uVar15);
  local_res10 = '\0';
  cVar6 = '\0';
  do {
    if (*(uint *)(param_2 + 0x158) <= (uint)uVar14) {
LAB_140007131:
      if ((plVar16 == (longlong *)0x0) || (*(int *)((longlong)plVar16 + 0x14) != 0)) {
        return uVar8 & 0xffffffffffffff00;
      }
      EHCI_DecPendingTransfer(param_1,param_2,plVar16);
      if (local_res10 == '\0') {
        (*DAT_140016440)(param_1,0x10000001,0x7470635f,(longlong)(int)plVar16[4],plVar16,
                         *(undefined4 *)((longlong)plVar16 + 0x24));
        EHCI_sMode_ResetSlot(param_1,param_2,(longlong)param_3);
        EHCI_sMode_IncSlotIdx(param_1,param_2,param_3);
        uVar15 = (*DAT_140016430)(param_1,param_2,local_60,(int)plVar16[4],
                                  *(undefined4 *)((longlong)plVar16 + 0x24));
        return CONCAT71((int7)((ulonglong)uVar15 >> 8),1);
      }
      (*DAT_140016440)(param_1,0x10000001,0x7370635f,(longlong)(int)plVar16[4],plVar16,
                       *(undefined4 *)((longlong)plVar16 + 0x24));
      iVar7 = *(int *)(local_60 + 8);
      (*DAT_140016440)(param_1,0x10000001,0x7268735f,param_2,0,plVar16);
      EHCI_sMode_ResetSlot(param_1,param_2,(longlong)param_3);
      piVar9 = (int *)EHCI_sMode_IncSlotIdx(param_1,param_2,param_3);
      uVar15 = (*DAT_140016430)(param_1,param_2,local_60,(int)plVar16[4],
                                *(undefined4 *)((longlong)plVar16 + 0x24));
      iVar3 = piVar9[2];
      goto joined_r0x0001400074c2;
    }
    lVar5 = *(longlong *)(param_3 + uVar14 * 2 + 8);
    uVar12 = *(uint *)(lVar5 + 8);
    (*DAT_140016440)(param_1,0x10000001,0x314c535f,lVar5,uVar12,uVar14);
    uVar13 = *(uint *)(lVar5 + 0x38);
    if ((uVar13 & 8) != 0) {
      uVar8 = (*DAT_140016440)(param_1,0x10000001,0x324c535f,lVar5,0,uVar14);
      goto LAB_14000717a;
    }
    if ((uVar13 & 0x10) != 0) {
      uVar15 = 0x334c535f;
      uVar12 = 0;
LAB_140007123:
      uVar8 = (*DAT_140016440)(param_1,0x10000001,uVar15,lVar5,uVar12,uVar14);
      goto LAB_140007131;
    }
    if ((uVar13 & 0x40) != 0) {
      uVar15 = 0x784c535f;
      uVar12 = 0;
      goto LAB_140007123;
    }
    plVar16 = *(longlong **)(lVar5 + 0x50);
    local_60 = plVar16[3];
    (*DAT_140016440)(param_1,0x10000001,0x744c535f,lVar5,cVar6,local_res10);
    if ((local_res10 == '\0') && (cVar6 == '\0')) {
      if ((char)uVar12 < '\0') {
        uVar15 = 0x614c535f;
        goto LAB_140007123;
      }
      if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
        *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) | 8;
        LOCK();
        UNLOCK();
      }
      else {
        LOCK();
        *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) | 8;
        UNLOCK();
      }
      *(int *)((longlong)plVar16 + 0x14) = *(int *)((longlong)plVar16 + 0x14) + -1;
      if ((uVar12 & 0x40) == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = uVar12 >> 0x10 & 0x7fff;
        (*DAT_140016440)(param_1,0x10000001,0x784c535f,lVar5,uVar12,uVar13);
        if (((((uVar12 & 4) != 0) && (*(int *)(param_1 + 0x54) != 0)) ||
            (((uVar12 & 8) != 0 && (*(int *)(param_1 + 0x50) != 0)))) && (uVar13 != 0)) {
          uVar8 = _DAT_fffff78000000014 / 10000;
          iVar7 = (int)uVar8;
          if (((uVar12 & 4) != 0) && (1000 < (uint)(iVar7 - *(int *)(param_2 + 0x148)))) {
            *(int *)(param_2 + 0x148) = iVar7;
            *(undefined2 *)(param_2 + 0x142) = *(undefined2 *)(param_1 + 0x54);
            (*DAT_140016440)(param_1,0x10000001,0x624c535f,lVar5,uVar12,uVar8 & 0xffffffff);
          }
          if (((uVar12 & 8) != 0) && (1000 < (uint)(iVar7 - *(int *)(param_2 + 0x144)))) {
            *(int *)(param_2 + 0x144) = iVar7;
            *(undefined2 *)(param_2 + 0x140) = *(undefined2 *)(param_1 + 0x50);
            (*DAT_140016440)(param_1,0x10000001,0x634c535f,lVar5,uVar12,uVar8 & 0xffffffff);
          }
          psVar1 = (short *)(param_2 + 0x142);
          if ((((uVar12 & 4) != 0) && (*psVar1 != 0)) ||
             (((uVar12 & 8) != 0 && (*(short *)(param_2 + 0x140) != 0)))) break;
        }
        uVar15 = 0x10000001;
        (*DAT_140016440)(param_1,0x10000001,0x214c535f,lVar5,0,0);
        uVar15 = EHCI_GetErrorFromTD(param_1,uVar15,lVar5);
        uVar13 = (uint)uVar15;
        *(int *)(param_2 + 0x154) = *(int *)(param_2 + 0x154) + 1;
        *(undefined4 *)(param_2 + 0x70) = 1;
        cVar6 = '\x01';
      }
      (*DAT_140016440)(param_1,0x10000001,0x354c535f,plVar16,(longlong)(int)uVar13,lVar5);
      uVar2 = *(uint *)(lVar5 + 0x3c);
      uVar10 = uVar12 >> 0x10 & 0x7fff;
      iVar7 = uVar2 - uVar10;
      if (uVar2 < uVar10) {
        iVar7 = 0;
      }
      uVar11 = uVar12 >> 0x10 & 0x7fff;
      (*DAT_140016440)(param_1,0x10000001,0x374c535f,iVar7,uVar2,uVar11);
      *(int *)((longlong)plVar16 + 0x24) = *(int *)((longlong)plVar16 + 0x24) + iVar7;
      uVar8 = (ulonglong)uVar13;
      if (uVar13 != 0) {
        *(uint *)(plVar16 + 4) = uVar13;
        uVar8 = (*DAT_140016440)(param_1,0x10000001,0x384c535f,(longlong)(int)uVar13,0,0);
      }
      bVar17 = (uVar12 & 0x80) == 0;
      uVar8 = CONCAT71((int7)(uVar8 >> 8),bVar17);
      if (bVar17 && uVar10 != 0) {
        uVar8 = (*DAT_140016440)(param_1,0x10000001,0x394c535f,uVar11,0,lVar5);
        local_res10 = '\x01';
      }
      if (*(int *)((longlong)plVar16 + 0x14) == 0) {
        uVar8 = (*DAT_140016440)(param_1,0x10000001,0x316c535f,0,0,0);
        goto LAB_140007131;
      }
    }
    else {
      uVar8 = (*DAT_140016440)(param_1,0x10000001,0x344c535f,lVar5,0,uVar14);
      if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
        uVar13 = *(uint *)(lVar5 + 0x38) | 0x10;
        uVar8 = (ulonglong)uVar13;
        *(uint *)(lVar5 + 0x38) = uVar13;
        LOCK();
        UNLOCK();
      }
      else {
        LOCK();
        *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) | 0x10;
        UNLOCK();
      }
      if (cVar6 != '\0') {
        if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
          uVar13 = *(uint *)(lVar5 + 0x38) | 0x100;
          uVar8 = (ulonglong)uVar13;
          *(uint *)(lVar5 + 0x38) = uVar13;
          LOCK();
          UNLOCK();
        }
        else {
          LOCK();
          *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) | 0x100;
          UNLOCK();
        }
      }
      *(uint *)(lVar5 + 8) = uVar12 & 0xffffff7f;
      *(int *)((longlong)plVar16 + 0x14) = *(int *)((longlong)plVar16 + 0x14) + -1;
    }
LAB_14000717a:
    uVar14 = (ulonglong)((uint)uVar14 + 1);
  } while( true );
  (*DAT_140016440)(param_1,0x10000001,0x644c535f,lVar5,uVar12,*(undefined4 *)(lVar4 + 0x18));
  if ((uVar12 & 4) != 0) {
    *psVar1 = *psVar1 + -1;
  }
  if ((uVar12 & 8) != 0) {
    *(short *)(param_2 + 0x140) = *(short *)(param_2 + 0x140) + -1;
  }
  *(int *)((longlong)plVar16 + 0x14) = *(int *)((longlong)plVar16 + 0x14) + 1;
  if (*(char *)(param_1 + 0x5e) == '\0') {
    LOCK();
    *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) & 0xfffffff7;
    UNLOCK();
  }
  else {
    *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) & 0xfffffff7;
    LOCK();
    UNLOCK();
  }
  uVar12 = uVar12 & 0xffffffb1 | 0xc80;
  *(uint *)(lVar5 + 8) = uVar12;
  *(uint *)(lVar4 + 0x18) = uVar12;
  goto LAB_140007037;
joined_r0x0001400074c2:
  if (iVar3 != 1) {
LAB_1400074c8:
    return CONCAT71((int7)((ulonglong)uVar15 >> 8),1);
  }
  lVar4 = *(longlong *)(piVar9 + 8);
  uVar15 = (*DAT_140016440)(param_1,0x10000001,0x3170735f,lVar4,iVar7,piVar9);
  plVar16 = *(longlong **)(lVar4 + 0x50);
  lVar4 = plVar16[3];
  if (*(int *)(lVar4 + 8) != iVar7) goto LAB_1400074c8;
  EHCI_DecPendingTransfer(param_1,param_2,plVar16);
  EHCI_sMode_ResetSlot(param_1,param_2,(longlong)piVar9);
  piVar9 = (int *)EHCI_sMode_IncSlotIdx(param_1,param_2,piVar9);
  uVar15 = (*DAT_140016430)(param_1,param_2,lVar4,(int)plVar16[4],
                            *(undefined4 *)((longlong)plVar16 + 0x24));
  iVar3 = piVar9[2];
  goto joined_r0x0001400074c2;
}



===== EHCI_sMode_IncSlotIdx @ 140007840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong EHCI_sMode_IncSlotIdx(longlong param_1,longlong param_2,int *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  iVar1 = *param_3;
  (*DAT_140016440)(param_1,0x10000001,0x316e695f,0,param_2,param_3);
  uVar4 = 0;
  if (iVar1 + 1U < *(uint *)(param_2 + 0x160)) {
    uVar4 = (ulonglong)(iVar1 + 1U);
  }
  lVar2 = *(longlong *)(param_2 + 0x170 + uVar4 * 8);
  if (*(int *)(lVar2 + 8) == 1) {
    *(longlong *)(param_2 + 0x168) = lVar2;
  }
  else {
    *(undefined8 *)(param_2 + 0x168) = 0;
    if (*(char *)(param_1 + 0x62) != '\0') {
      lVar3 = *(longlong *)(param_2 + 0x78);
      *(undefined4 *)(lVar3 + 0x10) = 1;
      *(undefined4 *)(lVar3 + 0x14) = 1;
    }
  }
  (*DAT_140016440)(param_1,0x10000001,0x326e695f,*(undefined8 *)(param_2 + 0x168),lVar2,0);
  return lVar2;
}



===== EHCI_sMode_ResetSlot @ 140007908 =====

void EHCI_sMode_ResetSlot(longlong param_1,longlong param_2,longlong param_3)

{
  uint *puVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  
  *(undefined4 *)(param_3 + 8) = 0;
  uVar7 = 0;
  if (*(int *)(param_2 + 0x158) != 0) {
    do {
      puVar3 = *(undefined4 **)(param_3 + 0x20 + uVar7 * 8);
      puVar1 = puVar3 + 0xe;
      if ((*puVar1 & 0x40) != 0) {
        return;
      }
      pcVar2 = (char *)(param_1 + 0x5e);
      if ((param_1 == 0) || (*pcVar2 != '\0')) {
        *puVar1 = *puVar1 | 0x40;
        LOCK();
        UNLOCK();
        if (param_1 != 0) goto LAB_140007962;
code_r0x000140007a30:
        *puVar1 = *puVar1 & 0xfffffff7;
        LOCK();
        UNLOCK();
        if (param_1 != 0) goto LAB_140007970;
code_r0x000140007a47:
        puVar3[0xe] = puVar3[0xe] & 0xffffffef;
        LOCK();
        UNLOCK();
      }
      else {
        LOCK();
        *puVar1 = *puVar1 | 0x40;
        UNLOCK();
LAB_140007962:
        if (*pcVar2 != '\0') goto code_r0x000140007a30;
        LOCK();
        *puVar1 = *puVar1 & 0xfffffff7;
        UNLOCK();
LAB_140007970:
        if (*pcVar2 != '\0') goto code_r0x000140007a47;
        LOCK();
        puVar3[0xe] = puVar3[0xe] & 0xffffffef;
        UNLOCK();
      }
      if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
        puVar3[0xe] = puVar3[0xe] & 0xfffffffd;
        LOCK();
        UNLOCK();
      }
      else {
        LOCK();
        puVar3[0xe] = puVar3[0xe] & 0xfffffffd;
        UNLOCK();
      }
      if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
        puVar3[0xe] = puVar3[0xe] & 0xfffffeff;
        LOCK();
        UNLOCK();
      }
      else {
        LOCK();
        puVar3[0xe] = puVar3[0xe] & 0xfffffeff;
        UNLOCK();
      }
      *(undefined8 *)(puVar3 + 0x14) = 0;
      puVar4 = puVar3 + 8;
      lVar5 = 5;
      do {
        puVar4[-5] = 0xbad0000;
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
      puVar3[2] = 0xc00;
      *puVar3 = *(undefined4 *)(*(longlong *)(puVar3 + 0x1a) + 0x40);
      *(longlong *)(puVar3 + 0x16) = *(longlong *)(puVar3 + 0x1a);
    } while (uVar6 < *(uint *)(param_2 + 0x158));
  }
  return;
}



===== EHCI_sMode_AbortSlot @ 140007a60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_sMode_AbortSlot(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  (*DAT_140016440)(param_1,0x10000001,0x726c535f,0,param_4,param_3);
  lVar1 = *(longlong *)(param_2 + 0x78);
  uVar5 = 0;
  do {
    if (*(uint *)(param_2 + 0x158) <= uVar5) {
LAB_140007abb:
      EHCI_sMode_ResetSlot(param_1,param_2,param_3);
      return;
    }
    lVar2 = *(longlong *)(param_3 + 0x20 + (ulonglong)uVar5 * 8);
    uVar3 = *(uint *)(lVar2 + 0x38);
    if ((uVar3 & 8) == 0) {
      if (((uVar3 & 0x10) != 0) || ((uVar3 & 0x40) != 0)) goto LAB_140007abb;
      if ((char)*(uint *)(lVar2 + 8) < '\0') {
        uVar5 = *(uint *)(lVar1 + 0x18);
        if (((char)uVar5 < '\0') && (*(int *)(lVar1 + 0xc) == *(int *)(lVar2 + 0x40))) {
          uVar5 = uVar5 >> 0x10 & 0x7fff;
          iVar4 = *(uint *)(lVar2 + 0x3c) - uVar5;
          if (*(uint *)(lVar2 + 0x3c) < uVar5) {
            iVar4 = 0;
          }
          *(int *)(param_4 + 0x24) = *(int *)(param_4 + 0x24) + iVar4;
        }
        goto LAB_140007abb;
      }
      uVar3 = *(uint *)(lVar2 + 8) >> 0x10 & 0x7fff;
      iVar4 = *(uint *)(lVar2 + 0x3c) - uVar3;
      if (*(uint *)(lVar2 + 0x3c) < uVar3) {
        iVar4 = 0;
      }
      *(int *)(param_4 + 0x24) = *(int *)(param_4 + 0x24) + iVar4;
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



===== EHCI_InterruptDpcEx @ 140007b50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint EHCI_InterruptDpcEx(longlong param_1,char param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 local_res8 [8];
  char local_res10;
  undefined8 local_58;
  longlong *plStack_50;
  undefined2 local_48;
  
  lVar2 = *(longlong *)(param_1 + 200);
  uVar4 = 0;
  local_48 = 0;
  bVar3 = false;
  local_res8[0] = 0;
  uVar7 = 0;
  local_58 = 0;
  plStack_50 = (longlong *)0x0;
  if (lVar2 != 0) {
    uVar1 = *(undefined4 *)(lVar2 + 0xc);
    uVar4 = *(uint *)(lVar2 + 4);
    local_res10 = param_2;
    if ((((uVar4 & 0x20) != 0) && (param_2 != '\0')) && (*(longlong *)(param_1 + 0xe0) != 0)) {
      EHCI_AcquireAsyncDoorbellLock(param_1,local_res8);
      *(int *)(param_1 + 0x544) = *(int *)(param_1 + 0x544) + 1;
      *(undefined8 *)(param_1 + 0x118) = 0;
      KeReleaseSpinLock(param_1 + 0x110,local_res8[0]);
      *(int *)(param_1 + 0x524) = *(int *)(param_1 + 0x524) + 1;
      if (0x10 < *(uint *)(param_1 + 0x544)) {
        *(int *)(param_1 + 0x528) = *(int *)(param_1 + 0x528) + 1;
        KeSynchronizeExecution(*(undefined8 *)(param_1 + 0xe0),EHCI_InterruptDpcSyncRoutine,param_1)
        ;
      }
    }
    LOCK();
    uVar6 = *(uint *)(param_1 + 0x14c);
    *(uint *)(param_1 + 0x14c) = 0;
    UNLOCK();
    (*DAT_140016440)(param_1,0x10000001,0x7064695f,uVar6,uVar4,uVar1);
    uVar6 = *(uint *)(param_1 + 0xe8) & uVar6;
    if ((uVar6 & 0x23) != 0) {
      (*DAT_140016440)(param_1,0x10000001,0x5045695f,uVar6,0,0);
      (*DAT_140016428)(param_1,0);
    }
    if ((uVar6 & 0x20) != 0) {
      (*DAT_140016440)(param_1,0x10000001,0x2162645f,uVar6,0,0);
      EHCI_AnswerAsyncDoorbell(param_1);
    }
    if (((uVar6 & 5) == 0) || (*(int *)(param_1 + 0x28) == 0)) {
      if ((uVar6 & 4) != 0) {
        uVar5 = 0;
        if (*(short *)(param_1 + 0x150) != 0) {
          do {
            uVar4 = *(uint *)(lVar2 + 0x44 + (ulonglong)uVar5 * 4);
            if (((uVar4 & 0x40) == 0) || ((*(uint *)(param_1 + 0x144) >> (uVar5 & 0x1f) & 1) != 0))
            {
              if (((uVar4 & 0x2a) != 0) ||
                 ((-1 < (char)uVar4 && ((*(uint *)(param_1 + 0x148) >> (uVar5 & 0x1f) & 1) != 0))))
              {
                (*DAT_140016440)(param_1,0x10000001,0x6768635f,uVar5 + 1,uVar4,param_1);
                bVar3 = true;
              }
            }
            else {
              (*DAT_140016440)(param_1,0x10000001,0x6773725f,uVar5 + 1,uVar4,param_1);
              *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) | 1 << ((byte)uVar5 & 0x1f);
              local_58 = CONCAT62(local_58._2_6_,uVar5 + 1);
              plStack_50 = EHCI_RefAsyncIdle(param_1,2);
              (*DAT_140016568)(param_1,0x32,&local_58,0x18,EHCI_RH_PortResumeComplete,0,1);
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < *(ushort *)(param_1 + 0x150));
          param_2 = local_res10;
        }
        *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0xe8) & 0xfffffffb;
      }
    }
    else {
      uVar7 = 1;
    }
    uVar4 = uVar7 | 2;
    if (!bVar3) {
      uVar4 = uVar7;
    }
    if (param_2 != '\0') {
      (*DAT_140016440)(param_1,0x10000001,0x4545695f,0,0,*(undefined4 *)(param_1 + 0xe8));
      *(undefined4 *)(lVar2 + 8) = *(undefined4 *)(param_1 + 0xe8);
      LOCK();
      UNLOCK();
    }
  }
  return uVar4;
}



===== EHCI_InterruptService @ 140007eb0 =====

ulonglong EHCI_InterruptService(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  
  puVar1 = *(uint **)(param_1 + 200);
  if (puVar1 != (uint *)0x0) {
    uVar3 = 0;
    in_RAX = (ulonglong)*puVar1;
    if (*puVar1 != 0xffffffff) {
      uVar2 = puVar1[1] & puVar1[2] & 0x3f;
      if (uVar2 != 0) {
        LOCK();
        *(uint *)(param_1 + 0x14c) = *(uint *)(param_1 + 0x14c) | uVar2;
        UNLOCK();
        puVar1[1] = uVar2;
        LOCK();
        UNLOCK();
        if ((uVar2 & 0x10) != 0) {
          *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 1;
          *(undefined4 *)(param_1 + 0x3e4) = 1;
        }
        uVar2 = puVar1[3] >> 3 & 0x7ff;
        if (((uVar2 ^ *(uint *)(param_1 + 300)) >> 10 & 1) != 0) {
          *(uint *)(param_1 + 0x130) =
               (*(uint *)(param_1 + 0x130) - ((*(uint *)(param_1 + 0x130) ^ uVar2) & 0x400)) + 0x800
          ;
        }
        *(uint *)(param_1 + 300) = uVar2;
        uVar3 = 1;
      }
      return uVar3;
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== EHCI_SetAsyncScheduleState @ 140007f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_SetAsyncScheduleState(longlong param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x558);
  (*DAT_140016440)(param_1,0x10000001,0x72545341,(longlong)iVar2,(longlong)param_2,0);
  if ((iVar2 != 1) && (param_2 == 1)) {
    piVar1 = (int *)(param_1 + 0x570);
    *piVar1 = *piVar1 + 1;
    if (*piVar1 == 0) {
      *(undefined4 *)(param_1 + 0x570) = 1;
    }
  }
  if (*(int *)(param_1 + 0x558) == 2) {
    if (param_2 == 1) {
      return;
    }
  }
  else if ((*(int *)(param_1 + 0x558) == 5) && (param_2 == 4)) {
    return;
  }
  *(int *)(param_1 + 0x558) = param_2;
  return;
}



===== EHCI_SetPeriodicScheduleState @ 140008010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_SetPeriodicScheduleState(longlong param_1,int param_2)

{
  (*DAT_140016440)(param_1,0x10000001,0x72545350,(longlong)*(int *)(param_1 + 0x560),
                   (longlong)param_2,0);
  if (*(int *)(param_1 + 0x560) == 2) {
    if (param_2 != 1) {
      *(int *)(param_1 + 0x560) = param_2;
      return;
    }
  }
  else if ((*(int *)(param_1 + 0x560) != 5) || (param_2 != 4)) {
    *(int *)(param_1 + 0x560) = param_2;
  }
  return;
}



===== EHCI_GetEndpointStatus @ 1400080a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int EHCI_GetEndpointStatus(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  if (((*(uint *)(param_2 + 0x80) & 2) == 0) &&
     (((iVar1 = *(int *)(param_2 + 0x3c), iVar1 == 3 || (iVar1 == 1)) || (iVar1 == 2)))) {
    iVar1 = *(int *)(param_2 + 0x70);
    (*DAT_140016440)(param_1,0x10000001,0x7370675f,param_2,(longlong)iVar1,0);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



===== EHCI_AcquireAsyncDoorbellLock @ 140008120 =====

void EHCI_AcquireAsyncDoorbellLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
  *param_2 = uVar1;
  *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
  return;
}



===== EHCI_CheckController @ 140008170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_CheckController(longlong param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined1 uVar3;
  char cVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  if (*(char *)(param_1 + 0x3ec) == '\0') {
    return;
  }
  if (*(int **)(param_1 + 200) == (int *)0x0) {
    return;
  }
  if (**(int **)(param_1 + 200) == -1) {
    uVar5 = 2;
  }
  else {
    if (*(int *)(param_1 + 0x54c) != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x3e4) != 0) {
      *(undefined4 *)(param_1 + 0x3e4) = 0;
      uVar6 = 0xc0010001;
      *(undefined4 *)(param_1 + 0x54c) = 1;
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
    uVar1 = *(uint *)(param_1 + 0x538);
    *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
    if ((uVar1 != 0) && (*(uint *)(param_1 + 0x538) = uVar1 + 1, 0x1e < uVar1)) {
      *(undefined4 *)(param_1 + 0x538) = 0;
      uVar6 = 0xc0010002;
      *(undefined4 *)(param_1 + 0x54c) = 1;
    }
    uVar1 = *(uint *)(param_1 + 0x53c);
    if ((uVar1 != 0) && (*(uint *)(param_1 + 0x53c) = uVar1 + 1, 0x1e < uVar1)) {
      *(undefined4 *)(param_1 + 0x53c) = 0;
      uVar6 = 0xc0010003;
      *(undefined4 *)(param_1 + 0x54c) = 1;
    }
    if (*(uint *)(param_1 + 0x540) != 0) {
      if (((*(int *)(param_1 + 0x578) == 0) && (0xf < *(uint *)(param_1 + 0x540))) &&
         (*(int *)(param_1 + 0x544) == 0)) {
        if ((*(int *)(param_1 + 0x554) != 0) &&
           (cVar4 = KdRefreshDebuggerNotPresent(), cVar4 == '\0')) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        *(undefined4 *)(param_1 + 0x578) = 1;
        if (*(int *)(param_1 + 0x558) == 2) {
          EHCI_iEnablePeriodicList(param_1);
        }
        else if (*(int *)(param_1 + 0x558) == 5) {
          EHCI_iDisablePeriodicList(param_1);
        }
      }
      uVar1 = *(uint *)(param_1 + 0x540);
      *(uint *)(param_1 + 0x540) = uVar1 + 1;
      if (0x1e < uVar1) {
        *(undefined4 *)(param_1 + 0x540) = 0;
        uVar6 = 0xc0010004;
        *(undefined4 *)(param_1 + 0x54c) = 1;
      }
    }
    *(undefined8 *)(param_1 + 0x118) = 0;
    KeReleaseSpinLock(param_1 + 0x110,uVar3);
    if (*(int *)(param_1 + 0x54c) == 0) {
      return;
    }
    *(int *)(param_1 + 0x548) = *(int *)(param_1 + 0x548) + 1;
    EHCI_WriteErrorLogEntry(param_1,uVar6,'\0');
    DbgPrint("Detected Async Advance Hang - Reset Controller?\n");
    if ((*(int *)(param_1 + 0x554) != 0) && (cVar4 = KdRefreshDebuggerNotPresent(), cVar4 == '\0'))
    {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(int *)(param_1 + 0x550) == 0) {
      return;
    }
    uVar5 = 5;
    if (*(char *)(param_1 + 0x71) == '\0') {
      uVar5 = 1;
    }
  }
  (*DAT_140016468)(param_1,uVar5);
  return;
}



===== EHCI_RH_GetPortStatus @ 1400083f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_RH_GetPortStatus(longlong param_1,ushort param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(longlong *)(param_1 + 200) == 0) {
    *param_3 = 0;
    return 0;
  }
  if (param_2 == *(ushort *)(param_1 + 1000)) {
    *param_3 = 0x100;
    return 0;
  }
  uVar1 = *(uint *)(*(longlong *)(param_1 + 200) + 0x40 + (ulonglong)param_2 * 4);
  *param_3 = 0;
  (*DAT_140016440)(param_1,0x10000001,0x3170505f,param_2,uVar1,0);
  uVar4 = (*param_3 ^ uVar1) & 1 ^ *param_3;
  uVar4 = (uVar1 >> 1 ^ uVar4) & 2 ^ uVar4;
  uVar4 = (uVar1 >> 5 ^ uVar4) & 4 ^ uVar4;
  uVar4 = (uVar1 >> 1 ^ uVar4) & 8 ^ uVar4;
  uVar4 = (uVar1 >> 4 ^ uVar4) & 0x10 ^ uVar4;
  uVar4 = (uVar1 >> 4 ^ uVar4) & 0x100 ^ uVar4;
  uVar4 = (uVar1 * 4 ^ uVar4) & 0x8000 ^ uVar4;
  *param_3 = uVar4;
  iVar2 = *(int *)(param_1 + 0x64c);
  if (iVar2 == 0) {
LAB_1400084d8:
    if (((uVar1 & 1) == 0) || ((uVar1 & 4) == 0)) goto LAB_1400084ef;
    uVar4 = uVar4 & 0xfffffdff | 0x400;
  }
  else if (iVar2 == 1) {
    uVar4 = (uVar1 >> 0x11 ^ uVar4) & 0x400 ^ uVar4;
    uVar4 = (uVar4 ^ uVar1 >> 0x11) & 0x200 ^ uVar4;
  }
  else {
    if (iVar2 != 2) goto LAB_1400084d8;
    uVar5 = *(uint *)((ulonglong)((uint)param_2 * 4) + 0x80 + *(longlong *)(param_1 + 200)) >> 0x10;
    uVar4 = (uVar5 ^ *param_3) & 0x400 ^ *param_3;
    uVar4 = (uVar5 ^ uVar4) & 0x200 ^ uVar4;
  }
  *param_3 = uVar4;
LAB_1400084ef:
  cVar3 = (char)param_2;
  if ((uVar1 & 0x40) == 0 && (uVar4 & 4) == 0) {
    uVar4 = 1 << (cVar3 - 1U & 0x1f);
    if ((*(uint *)(param_1 + 0x148) & uVar4) != 0) {
      *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) | uVar4;
      *(uint *)(param_1 + 0x148) = ~uVar4 & *(uint *)(param_1 + 0x148);
    }
  }
  if ((uVar1 & 2) != 0) {
    *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) | 1 << (cVar3 - 1U & 0x1f);
  }
  uVar5 = 1 << (cVar3 - 1U & 0x1f);
  uVar4 = (*param_3 ^ uVar1 << 0xe) & 0x20000 ^ *param_3;
  uVar4 = (uVar4 ^ uVar1 << 0xe) & 0x80000 ^ uVar4;
  *param_3 = uVar4;
  if ((*(uint *)(param_1 + 0x134) & uVar5) != 0) {
    uVar4 = uVar4 | 0x100000;
    *param_3 = uVar4;
  }
  if ((*(uint *)(param_1 + 0x13c) & uVar5) != 0) {
    uVar4 = uVar4 | 0x10000;
    *param_3 = uVar4;
  }
  if ((*(uint *)(param_1 + 0x138) >> (param_2 - 1 & 0x1f) & 1) != 0) {
    uVar4 = uVar4 | 0x40000;
    *param_3 = uVar4;
  }
  (*DAT_140016440)(param_1,0x10000001,0x7370675f,(ulonglong)param_2,uVar4,uVar1);
  return 0;
}



===== EHCI_PollController @ 140008680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_PollController(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = *(longlong *)(param_1 + 200);
  if ((lVar2 != 0) && (uVar3 = 0, *(short *)(param_1 + 0x150) != 0)) {
    do {
      uVar1 = *(uint *)(lVar2 + 0x44 + (ulonglong)uVar3 * 4);
      (*DAT_140016440)(param_1,0x10000001,0x706f505f,(ulonglong)uVar3,uVar1,0);
      if ((uVar1 & 2) != 0) {
        (*DAT_140016420)(param_1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(ushort *)(param_1 + 0x150));
  }
  return;
}



===== EHCI_InitializeHardware @ 140008734 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 EHCI_InitializeHardware(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  ushort uVar4;
  byte extraout_var;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  byte bVar8;
  undefined8 local_res8;
  
  puVar3 = *(uint **)(param_1 + 200);
  local_res8 = 0;
  bVar8 = 0;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xd0) + 4);
  uVar4 = (ushort)(uVar1 >> 0x10);
  if (*(uint **)(param_1 + 0xd8) != (uint *)0x0) {
    uVar2 = **(uint **)(param_1 + 0xd8);
    *(ushort *)(param_1 + 0x3ea) = uVar4 >> 4 & 0xf;
    bVar8 = (byte)(uVar2 >> 10) & 1;
  }
  *(ushort *)(param_1 + 0x150) = (ushort)uVar1 & 0xf;
  if ((uVar1 & 0xf) == 0) {
LAB_14000880a:
    uVar7 = 7;
  }
  else {
    *(ushort *)(param_1 + 0x152) = (ushort)(uVar1 >> 4) & 1;
    if (bVar8 == 0) {
      *(undefined2 *)(param_1 + 1000) = 0;
      (*DAT_140016440)(param_1,0x10000001,0x7365725f,0,0,0);
      *puVar3 = 2;
      LOCK();
      UNLOCK();
      uVar5 = KeQueryInterruptTimePrecise(&local_res8);
      uVar6 = uVar5;
      while ((*puVar3 & 2) != 0) {
        if (uVar5 + 1000000 <= uVar6) goto LAB_14000880a;
        uVar6 = _DAT_fffff78000000008;
      }
      EHCI_EvaluateAcpiRoutineOnHcReset(*(undefined8 *)(param_1 + 0x10));
      *(byte *)(param_1 + 0x71) = extraout_var >> 7 ^ 1;
    }
    else {
      *(ushort *)(param_1 + 1000) = uVar4 >> 4 & 0xf;
    }
    puVar3[6] = 0;
    LOCK();
    UNLOCK();
    puVar3[5] = 0;
    LOCK();
    UNLOCK();
    *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0xe8) | 0x3b;
    uVar7 = 0;
  }
  return uVar7;
}



===== EHCI_ResumeController @ 140008880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EHCI_ResumeController(longlong param_1)

{
  uint uVar1;
  uint *puVar2;
  ushort uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined1 local_c8 [32];
  undefined8 *local_a8;
  undefined8 local_a0;
  int local_88;
  ushort local_84 [6];
  undefined8 local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  ushort *local_58;
  undefined8 local_50;
  longlong local_48;
  int local_40;
  undefined4 local_3c;
  longlong local_38;
  int local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)local_c8;
  local_84[0] = 0;
  memset(&local_78,0,0x50);
  local_a8 = &local_78;
  (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_RESUME_DISPATCH,0,1);
  puVar2 = *(uint **)(param_1 + 200);
  puVar5 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_RESUME_COMPLETE;
  local_88 = 0;
  if (puVar2 == (uint *)0x0) {
    puVar5 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_RESUME_COMPLETE_ERROR_1;
    local_88 = 7;
  }
  else {
    if ((puVar2[1] >> 0xc & 1) == 0) {
      local_a0 = 0;
      local_a8 = (undefined8 *)0x0;
      (*DAT_140016440)(param_1,0x10000001,0x484e525f,puVar2[1]);
      if (*(int *)(param_1 + 0x3dc) == 0) {
        local_88 = 7;
        puVar5 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_RESUME_COMPLETE_ERROR_2;
        goto LAB_140008959;
      }
    }
    if (((puVar2[0x10] & 1) == 0) && ((*(uint *)(param_1 + 0x3d4) & 1) != 0)) {
      uVar4 = puVar2[0x10] | 1;
      *(uint *)(param_1 + 0x3d4) = uVar4;
      puVar2[0x10] = uVar4;
      LOCK();
      UNLOCK();
      puVar5 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_RESUME_COMPLETE_ERROR_3;
      local_88 = 7;
    }
    else {
      uVar4 = 0;
      uVar3 = 0;
      if (*(short *)(param_1 + 0x150) != 0) {
        do {
          local_a0 = 0;
          local_a8 = (undefined8 *)(ulonglong)puVar2[(ulonglong)uVar4 + 0x11];
          *(uint *)(param_1 + 0x5c4 + (ulonglong)uVar4 * 4) = puVar2[(ulonglong)uVar4 + 0x11];
          (*DAT_140016440)(param_1,0x10000001,0x7072505f);
          uVar3 = *(ushort *)(param_1 + 0x150);
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar3);
      }
      for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + 1) {
        uVar1 = *(uint *)(param_1 + 0x5c4 + (ulonglong)uVar4 * 4);
        if ((uVar1 >> 0xc & 1) == 0) {
          puVar5 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_RESUME_COMPLETE_ERROR_4;
          local_88 = 7;
          goto LAB_140008959;
        }
        if (((uVar1 >> 0xd & 1) != 0) &&
           ((*(uint *)(param_1 + 0x588 + (ulonglong)uVar4 * 4) >> 0xd & 1) == 0)) {
          puVar5 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_RESUME_COMPLETE_ERROR_5;
          local_88 = 7;
          goto LAB_140008959;
        }
        if ((uVar1 & 0x20) != 0) {
          puVar5 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_RESUME_COMPLETE_ERROR_6;
          local_88 = 7;
          break;
        }
      }
      if (local_88 == 0) {
        puVar2[4] = *(uint *)(param_1 + 0x3c4);
        LOCK();
        UNLOCK();
        puVar2[5] = *(uint *)(param_1 + 0x3bc);
        LOCK();
        UNLOCK();
        puVar2[6] = *(uint *)(param_1 + 0x3c0);
        LOCK();
        UNLOCK();
        if (*(char *)(param_1 + 0x67) != '\0') {
          EHCI_DisableAMDAsyncQhCache(param_1);
        }
        local_a0 = 0;
        uVar4 = *puVar2;
        local_a8 = (undefined8 *)0x0;
        (*DAT_140016440)(param_1,0x10000001,0x6e75725f,uVar4);
        *puVar2 = *(uint *)(param_1 + 0x3c8) & 0xff0030 | uVar4 & 0xff00ff8f | 1;
        LOCK();
        UNLOCK();
        *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0x3cc);
        puVar2[2] = *(uint *)(param_1 + 0x3cc);
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1 + 0x28) = 0;
        *(undefined4 *)(param_1 + 0x3cc) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x3d8) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x3c8) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x3c4) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x3c0) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x3bc) = 0xffffffff;
      }
    }
  }
LAB_140008959:
  local_84[0] = *(ushort *)(param_1 + 0x150);
  local_68 = &local_88;
  local_a8 = &local_78;
  local_58 = local_84;
  local_40 = (uint)local_84[0] << 2;
  local_48 = param_1 + 0x588;
  local_38 = param_1 + 0x5c4;
  local_78 = 0;
  local_70 = 0;
  local_60 = 4;
  local_50 = 2;
  local_3c = 0;
  local_2c = 0;
  local_30 = local_40;
  (*DAT_1400165e0)(param_1,puVar5,0,5);
  return local_88;
}



===== EHCI_CheckHwSync @ 140008c10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int EHCI_CheckHwSync(longlong param_1,longlong *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(uint *)(param_2 + 0x10) & 2) != 0) {
    return 1;
  }
  (*DAT_140016440)(param_1,0x10000001,0x3177685f,param_2,0,0);
  iVar1 = *(int *)((longlong)param_2 + 0x3c);
  if (iVar1 == 0) {
    iVar2 = *(int *)((longlong)param_2 + 0x84);
  }
  else if ((iVar1 == 1) || (iVar1 == 2)) {
    iVar2 = EHCI_CheckHwSync_Async(param_1,param_2);
  }
  else if (iVar1 == 3) {
    iVar2 = EHCI_CheckHwSync_Periodic(param_1,(longlong)param_2);
  }
  (*DAT_140016440)(param_1,0x10000001,0x3277685f,param_2,iVar2,0);
  return iVar2;
}



===== EHCI_CheckHwSync_Periodic @ 140008cdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int EHCI_CheckHwSync_Periodic(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint *puVar2;
  undefined1 uVar3;
  uint uVar4;
  ulonglong uVar5;
  int iVar6;
  
  lVar1 = *(longlong *)(param_2 + 0x78);
  iVar6 = *(int *)(param_2 + 0x84);
  puVar2 = *(uint **)(param_1 + 200);
  (*DAT_140016440)(param_1,0x10000001,0x31706b5f,iVar6,param_2,lVar1);
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
  *(undefined8 *)(param_1 + 0x118) = 0;
  KeReleaseSpinLock(param_1 + 0x110,uVar3);
  if (iVar6 == 1) {
    (*DAT_140016440)(param_1,0x10000001,0x78706b5f,1,param_2,lVar1);
    return 1;
  }
  if ((*(int *)(param_1 + 0x28) == 0) && (((puVar2[1] >> 0xe & 1) != 0 || ((*puVar2 & 0x10) != 0))))
  {
    if (*(int *)(param_2 + 0x118) == 3) {
      *(undefined8 *)(param_2 + 0x88) = 0;
      *(undefined4 *)(param_2 + 0x84) = 1;
      (*DAT_140016440)(param_1,0x10000001,0x33706b5f,0,0,lVar1);
      return 1;
    }
    uVar5 = _DAT_fffff78000000320 - *(longlong *)(param_2 + 0x88);
    (*DAT_140016440)(param_1,0x10000001,0x34504b5f,(longlong)(int)(uVar5 >> 0x20),uVar5 & 0xffffffff
                    );
    if (1 < (longlong)uVar5) {
      uVar4 = KeQueryTimeIncrement();
      uVar5 = (ulonglong)uVar4 * (uVar5 - 1);
      (*DAT_140016440)(param_1,0x10000001,0x35504b5f,(longlong)(int)(uVar5 >> 0x20),
                       uVar5 & 0xffffffff,lVar1);
      if (19999 < (longlong)uVar5) goto LAB_140008e4d;
    }
    if (iVar6 == 0) {
      (*DAT_140016468)(param_1,3);
    }
  }
  else {
    (*DAT_140016440)(param_1,0x10000001,0x32706b5f,*(uint *)(lVar1 + 0x4c) & 1,0,lVar1);
LAB_140008e4d:
    *(undefined4 *)(param_2 + 0x84) = 1;
    iVar6 = 1;
    *(undefined8 *)(param_2 + 0x88) = 0;
  }
  return iVar6;
}



===== EHCI_InitializeSchedule @ 140008f2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
EHCI_InitializeSchedule
          (longlong param_1,uint *param_2,int param_3,undefined8 param_4,undefined4 param_5)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  
  lVar2 = *(longlong *)(param_1 + 200);
  *(uint **)(param_1 + 0x398) = param_2;
  *(int *)(param_1 + 0x3a0) = param_3;
  puVar5 = (undefined8 *)(param_1 + 400);
  lVar6 = 0x40;
  puVar8 = param_2 + 0x400;
  uVar9 = param_3 + 0x1000;
  do {
    uVar3 = uVar9;
    puVar7 = puVar8;
    puVar7[0x11] = uVar3;
    *puVar5 = puVar7;
    puVar8 = puVar7 + 0x20;
    puVar5 = puVar5 + 1;
    lVar6 = lVar6 + -1;
    uVar9 = uVar3 + 0x80;
  } while (lVar6 != 0);
  puVar1 = puVar7 + 0x40;
  puVar7[0x21] = puVar7[0x21] | 0x8000;
  puVar7[0x31] = uVar3 + 0x80;
  puVar7[0x24] = puVar7[0x24] | 1;
  uVar9 = puVar7[0x31] & 0xffffffe3 | 2;
  puVar7[0x26] = 0x40;
  puVar7[0x32] = 0x71613032;
  puVar7[0x22] = puVar7[0x22] & 0x3fffffff | 0x40000000;
  *(uint **)(param_1 + 0xf0) = puVar8;
  puVar7[0x51] = uVar3 + 0x100;
  puVar7[0x52] = 0x64613032;
  puVar7[0x44] = puVar7[0x44] | 1;
  puVar7[0x46] = 0x40;
  puVar7[0x42] = puVar7[0x42] & 0x3fffffff | 0x40000000;
  if (*(char *)(param_1 + 0x65) == '\0') {
    puVar10 = puVar8;
    uVar3 = uVar9;
  }
  else {
    puVar10 = puVar1;
    uVar3 = puVar7[0x51] & 0xffffffe3 | 2;
  }
  *puVar8 = uVar3;
  *(uint **)(puVar7 + 0x38) = puVar10;
  *(uint **)(puVar7 + 0x3a) = puVar10;
  *puVar1 = uVar9;
  *(uint **)(puVar7 + 0x58) = puVar8;
  *(uint **)(puVar7 + 0x5a) = puVar8;
  *(uint **)(param_1 + 0xf8) = puVar1;
  EHCI_InitializeInterruptSchedule(param_1);
  uVar3 = 0;
  lVar6 = 0x400;
  do {
    uVar4 = uVar3 & 0x1f;
    uVar3 = uVar3 + 1;
    *param_2 = *(uint *)(*(longlong *)
                          (param_1 + 0x288 + (ulonglong)(byte)(&EHCI_Frame2Qhead)[uVar4] * 8) + 0x44
                        ) & 0xffffffe3 | 2;
    param_2 = param_2 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  if (*(int *)(param_1 + 0x30) == 0) {
    *(undefined8 *)(param_1 + 0x3b0) = 0;
    *(undefined4 *)(param_1 + 0x3b8) = 0;
  }
  else {
    (*DAT_140016440)(param_1,0x10000001,0x716d645f,param_4,param_5,0);
    *(undefined8 *)(param_1 + 0x3b0) = param_4;
    *(undefined4 *)(param_1 + 0x3b8) = param_5;
    EHCI_AddDummyQueueHeads(param_1);
  }
  *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)(param_1 + 0x3a0);
  LOCK();
  UNLOCK();
  *(uint *)(lVar2 + 0x18) = uVar9;
  LOCK();
  UNLOCK();
  return 0;
}



===== EHCI_InitializeInterruptSchedule @ 14000911c =====

void EHCI_InitializeInterruptSchedule(longlong param_1)

{
  longlong *plVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  uint uVar8;
  
  plVar1 = (longlong *)(param_1 + 400);
  lVar6 = 0x3f;
  plVar7 = plVar1;
  do {
    lVar5 = lVar6;
    lVar6 = *plVar7;
    plVar7 = plVar7 + 1;
    *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) | 1;
    *(uint *)(lVar6 + 4) = *(uint *)(lVar6 + 4) & 0xffff7fff;
    *(uint *)(lVar6 + 0x18) = *(uint *)(lVar6 + 0x18) | 0x40;
    *(undefined4 *)(lVar6 + 0x48) = 0x71693032;
    lVar6 = lVar5 + -1;
  } while (lVar6 != 0);
  uVar8 = (uint)lVar5;
  lVar6 = 0;
  plVar7 = (longlong *)(param_1 + 0x198);
  do {
    bVar3 = (&DAT_140014311)[lVar6];
    *(undefined8 *)(*plVar7 + 0x60) = *(undefined8 *)(param_1 + 400 + (ulonglong)bVar3 * 8);
    *(undefined8 *)(*plVar7 + 0x68) = 0;
    *(undefined4 *)*plVar7 =
         *(undefined4 *)(*(longlong *)(param_1 + 400 + (ulonglong)bVar3 * 8) + 0x44);
    *(uint *)*plVar7 = *(uint *)*plVar7 | 2;
    *(uint *)(*plVar7 + 8) = *(uint *)(*plVar7 + 8) | 0xff;
    *(uint *)(*plVar7 + 0x4c) = *(uint *)(*plVar7 + 0x4c) | 4;
    uVar4 = 8;
    if (6 < uVar8) {
      uVar4 = 0;
    }
    uVar8 = uVar8 + 1;
    *(uint *)(*plVar7 + 0x4c) = *(uint *)(*plVar7 + 0x4c) | uVar4;
    lVar5 = *plVar7;
    plVar7 = plVar7 + 1;
    pbVar2 = &DAT_140014351 + lVar6;
    lVar6 = lVar6 + 1;
    *(uint *)(lVar5 + 0x54) = (uint)*pbVar2;
  } while (uVar8 < 0x3f);
  *(undefined4 *)*plVar1 = 0;
  *(uint *)*plVar1 = *(uint *)*plVar1 | 1;
  *(uint *)(*plVar1 + 8) = *(uint *)(*plVar1 + 8) | 0xff;
  *(uint *)(*plVar1 + 0x4c) = *(uint *)(*plVar1 + 0x4c) | 0xc;
  return;
}



===== EHCI_AddDummyQueueHeads @ 140009228 =====

int EHCI_AddDummyQueueHeads(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint *_Dst;
  uint *puVar5;
  
  puVar5 = *(uint **)(param_1 + 0x398);
  uVar2 = *(uint *)(param_1 + 0x3b8);
  uVar3 = 0;
  lVar4 = 0x400;
  _Dst = *(uint **)(param_1 + 0x3b0);
  do {
    uVar1 = *puVar5;
    memset(_Dst,0,0x80);
    _Dst[0x11] = uVar2;
    _Dst[0x12] = 0x68716d64;
    _Dst[1] = _Dst[1] & 0xf840c080 | 0x400000;
    *(undefined2 *)(_Dst + 2) = 0;
    uVar2 = uVar2 + 0x80;
    *_Dst = uVar1;
    _Dst[2] = _Dst[2] & 0xffff | 0x40000000;
    _Dst[3] = 0;
    _Dst[5] = 1;
    uVar1 = uVar3 & 0x1f;
    _Dst[4] = 1;
    uVar3 = uVar3 + 1;
    _Dst[6] = 0;
    *(undefined8 *)(_Dst + 0x1c) =
         *(undefined8 *)(param_1 + 0x288 + (ulonglong)(byte)(&EHCI_Frame2Qhead)[uVar1] * 8);
    *puVar5 = _Dst[0x11] & 0xffffffe3 | 2;
    puVar5 = puVar5 + 1;
    lVar4 = lVar4 + -1;
    _Dst = _Dst + 0x20;
  } while (lVar4 != 0);
  return uVar2 - *(int *)(param_1 + 0x3b8);
}



===== EHCI_OpenInterruptEndpoint @ 140009338 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 EHCI_OpenInterruptEndpoint(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  void *_Dst;
  byte bVar3;
  undefined *puVar4;
  uint uVar5;
  void *pvVar6;
  undefined *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  int iVar10;
  undefined1 auStack_98 [32];
  undefined *local_78;
  ulonglong local_70;
  uint local_58;
  int local_54;
  longlong local_50;
  int local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  iVar2 = *(int *)(param_3 + 0x30);
  lVar8 = 0;
  local_48[0] = 0x7030100;
  local_48[1] = 0x1f1f1f0f;
  local_70 = (ulonglong)(iVar2 != 2);
  local_78 = (undefined *)param_2;
  local_54 = iVar2;
  local_50 = param_2;
  (*DAT_140016440)(param_1,0x10000001,0x49706f5f,param_3);
  bVar3 = *(byte *)(param_2 + 6);
  for (uVar5 = 0; ((bVar3 & 1) == 0 && (uVar5 < 7)); uVar5 = uVar5 + 1) {
    bVar3 = bVar3 >> 1;
  }
  lVar1 = param_3 + 0x108;
  *(longlong *)(param_3 + 0x110) = lVar1;
  *(longlong *)lVar1 = lVar1;
  local_58 = *(int *)(param_2 + 0x10);
  _Dst = *(void **)(param_2 + 0x20);
  iVar10 = *(int *)(param_2 + 0x28);
  if (iVar2 == 2) {
    uVar5 = (uint)*(byte *)((longlong)local_48 + (ulonglong)uVar5);
    puVar7 = &periodTable + (ulonglong)(local_58 + uVar5) * 3;
  }
  else {
    puVar7 = (undefined *)0x0;
    uVar5 = (uint)(byte)(&ClassicPeriodIdx)[uVar5];
  }
  local_70 = (ulonglong)uVar5;
  local_78 = puVar7;
  (*DAT_140016440)(param_1,0x10000001,0x7065695f,param_3);
  if (local_54 == 2) {
    uVar9 = (ulonglong)(byte)puVar7[1];
    puVar4 = puVar7;
  }
  else {
    uVar9 = (ulonglong)(local_58 + uVar5);
    puVar4 = (undefined *)0x0;
  }
  *(undefined8 *)(param_3 + 0xa8) = *(undefined8 *)(param_1 + 400 + uVar9 * 8);
  *(undefined **)(param_3 + 0xb0) = puVar4;
  iVar2 = *(int *)(param_2 + 0x2c);
  *(undefined4 *)(param_3 + 0x84) = 1;
  *(int *)(param_3 + 0xe4) = iVar10;
  *(void **)(param_3 + 0xe8) = _Dst;
  memset(_Dst,0,0x100);
  local_48[0] = iVar10 + 0x100;
  local_58 = iVar2 - 0x180U >> 7;
  *(uint *)(param_3 + 0xd8) = local_58;
  iVar10 = iVar10 + 0x180;
  *(longlong *)(param_3 + 0xb8) = (longlong)_Dst + 0x180;
  if (local_58 != 0) {
    uVar9 = (ulonglong)local_58;
    do {
      pvVar6 = (void *)(*(longlong *)(param_3 + 0xb8) + lVar8);
      memset(pvVar6,0,0x80);
      *(int *)((longlong)pvVar6 + 0x40) = iVar10;
      iVar10 = iVar10 + 0x80;
      *(longlong *)((longlong)pvVar6 + 0x48) = param_3;
      lVar8 = lVar8 + 0x80;
      *(undefined4 *)((longlong)pvVar6 + 0x34) = 0x64743032;
      *(undefined8 *)((longlong)pvVar6 + 0x50) = 0xdeadfacedeadface;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    param_2 = local_50;
  }
  *(uint *)(param_3 + 0xdc) = local_58;
  pvVar6 = EHCI_InitializeQH(param_1,param_3,(void *)((longlong)_Dst + 0x100),local_48[0]);
  *(void **)(param_3 + 0x78) = pvVar6;
  if (local_54 == 2) {
    *(undefined *)((longlong)_Dst + 0x108) = puVar7[2];
  }
  else {
    *(undefined1 *)((longlong)_Dst + 0x108) = *(undefined1 *)(param_2 + 0x3c);
    *(undefined1 *)((longlong)_Dst + 0x109) = *(undefined1 *)(param_2 + 0x3d);
  }
  EHCI_sMode_InitEndpoint(param_1,param_3);
  return 0;
}



===== EHCI_OpenEndpoint @ 1400095c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 EHCI_OpenEndpoint(longlong param_1,ushort *param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  code *pcVar5;
  uint uVar6;
  undefined8 uVar7;
  byte bVar8;
  
  *(undefined4 *)(param_3 + 0x20) = 0x70653032;
  lVar2 = param_3 + 0x98;
  uVar7 = *(undefined8 *)(param_2 + 4);
  plVar1 = (longlong *)(param_3 + 0x10);
  *(undefined8 *)(param_3 + 0x28) = *(undefined8 *)param_2;
  *(undefined8 *)(param_3 + 0x30) = uVar7;
  uVar7 = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_3 + 0x38) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_3 + 0x40) = uVar7;
  uVar7 = *(undefined8 *)(param_2 + 0x14);
  *(undefined8 *)(param_3 + 0x48) = *(undefined8 *)(param_2 + 0x10);
  *(undefined8 *)(param_3 + 0x50) = uVar7;
  uVar7 = *(undefined8 *)(param_2 + 0x1c);
  *(undefined8 *)(param_3 + 0x58) = *(undefined8 *)(param_2 + 0x18);
  *(undefined8 *)(param_3 + 0x60) = uVar7;
  uVar7 = *(undefined8 *)(param_2 + 0x20);
  *(undefined4 *)(param_3 + 0x80) = 0;
  *(undefined4 *)(param_3 + 0x94) = 0;
  *(undefined8 *)(param_3 + 0x68) = uVar7;
  *(longlong *)(param_3 + 0xa0) = lVar2;
  *(longlong *)lVar2 = lVar2;
  plVar4 = *(longlong **)(param_1 + 0x20);
  if (*plVar4 != param_1 + 0x18) goto LAB_14000978e;
  *plVar1 = param_1 + 0x18;
  *(longlong **)(param_3 + 0x18) = plVar4;
  *plVar4 = (longlong)plVar1;
  *(longlong **)(param_1 + 0x20) = plVar1;
  *(undefined4 *)(param_3 + 0x14c) = 0;
  *(undefined4 *)(param_3 + 0x70) = 0;
  *(undefined4 *)(param_3 + 0xf0) = 0;
  *(undefined4 *)(param_3 + 0x118) = 2;
  *(undefined4 *)(param_3 + 0x84) = 1;
  *(undefined2 *)(param_3 + 0x140) = *(undefined2 *)(param_1 + 0x50);
  *(undefined2 *)(param_3 + 0x142) = *(undefined2 *)(param_1 + 0x54);
  uVar6 = (uint)(_DAT_fffff78000000014 / 10000) & 0xffff;
  *(uint *)(param_3 + 0x144) = uVar6;
  *(uint *)(param_3 + 0x148) = uVar6;
  iVar3 = *(int *)(param_2 + 10);
  if (iVar3 == 0) {
    *(undefined4 *)(param_3 + 0xf0) = 1;
    if (*(int *)(param_2 + 4) == 2) {
      uVar7 = EHCI_OpenHsIsochronousEndpoint(param_1,param_2,param_3);
    }
    else {
      uVar7 = EHCI_OpenIsochronousEndpoint(param_1,param_2,param_3);
    }
LAB_1400096ef:
    if ((int)uVar7 == 0) {
      return uVar7;
    }
  }
  else {
    if (iVar3 == 1) {
      *(undefined4 *)(param_3 + 0xf0) = 3;
      bVar8 = 1;
LAB_1400096e1:
      uVar7 = EHCI_OpenBulkOrControlEndpoint(param_1,bVar8,(longlong)param_2,param_3);
      goto LAB_1400096ef;
    }
    if (iVar3 == 2) {
      *(undefined4 *)(param_3 + 0xf0) = 4;
      bVar8 = 0;
      goto LAB_1400096e1;
    }
    if (iVar3 == 3) {
      *(undefined4 *)(param_3 + 0xf0) = 2;
      uVar7 = EHCI_OpenInterruptEndpoint(param_1,(longlong)param_2,param_3);
      goto LAB_1400096ef;
    }
    uVar7 = 6;
  }
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_3 + 0x18), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar4;
    *plVar1 = 0;
    *(undefined8 *)(param_3 + 0x18) = 0;
    *(undefined4 *)(param_3 + 0x118) = 5;
    return uVar7;
  }
LAB_14000978e:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  uVar7 = (*pcVar5)();
  return uVar7;
}



===== EHCI_OpenBulkOrControlEndpoint @ 14000979c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
EHCI_OpenBulkOrControlEndpoint(longlong param_1,byte param_2,longlong param_3,longlong param_4)

{
  int iVar1;
  int iVar2;
  void *_Dst;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  
  (*DAT_140016440)(param_1,0x10000001,0x43706f5f,0,0,param_3);
  *(undefined4 *)(param_4 + 0x84) = 1;
  lVar6 = param_4 + 0x108;
  *(longlong *)(param_4 + 0x110) = lVar6;
  *(longlong *)lVar6 = lVar6;
  _Dst = *(void **)(param_3 + 0x20);
  iVar1 = *(int *)(param_3 + 0x28);
  iVar2 = *(int *)(param_3 + 0x2c);
  *(int *)(param_4 + 0xe4) = iVar1;
  *(void **)(param_4 + 0xe8) = _Dst;
  memset(_Dst,0,0x80);
  iVar7 = iVar1 + 0x100;
  uVar9 = iVar2 - 0x100U >> 7;
  lVar6 = 0;
  if (*(uint *)(param_3 + 0x14) == (uint)param_2) {
    if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
      *(uint *)(param_4 + 0x80) = *(uint *)(param_4 + 0x80) | 1;
      LOCK();
      UNLOCK();
    }
    else {
      LOCK();
      *(uint *)(param_4 + 0x80) = *(uint *)(param_4 + 0x80) | 1;
      UNLOCK();
    }
  }
  *(longlong *)(param_4 + 0xb8) = (longlong)_Dst + 0x100;
  *(uint *)(param_4 + 0xd8) = uVar9;
  if (uVar9 != 0) {
    uVar8 = (ulonglong)uVar9;
    do {
      pvVar5 = (void *)(*(longlong *)(param_4 + 0xb8) + lVar6);
      memset(pvVar5,0,0x80);
      *(int *)((longlong)pvVar5 + 0x40) = iVar7;
      *(undefined8 *)((longlong)pvVar5 + 0x50) = 0xdeadfacedeadface;
      iVar7 = iVar7 + 0x80;
      *(longlong *)((longlong)pvVar5 + 0x48) = param_4;
      lVar6 = lVar6 + 0x80;
      *(undefined4 *)((longlong)pvVar5 + 0x34) = 0x64743032;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  *(uint *)(param_4 + 0xdc) = uVar9;
  pvVar5 = EHCI_InitializeQH(param_1,param_4,(void *)((longlong)_Dst + 0x80),iVar1 + 0x80);
  *(void **)(param_4 + 0x78) = pvVar5;
  if (param_2 == 0) {
    uVar9 = *(uint *)((longlong)_Dst + 0x84);
    *(uint *)((longlong)_Dst + 0x84) = uVar9 & 0xffffbfff;
    if (*(int *)(param_1 + 0x654) != 0) {
      *(uint *)((longlong)_Dst + 0x84) = *(int *)(param_1 + 0x654) << 0x1c | uVar9 & 0xfffbfff;
    }
    EHCI_sMode_InitEndpoint(param_1,param_4);
  }
  else {
    puVar3 = (undefined4 *)EHCI_AllocTd(param_1,param_4);
    if (puVar3 == (undefined4 *)0x0) {
      (*DAT_140016470)(param_1);
      return 2;
    }
    *(undefined4 **)(param_4 + 0x130) = puVar3;
    puVar4 = puVar3 + 3;
    *(uint *)((longlong)_Dst + 0x84) = *(uint *)((longlong)_Dst + 0x84) | 0x4000;
    *(undefined4 *)((longlong)_Dst + 0x8c) = puVar3[0x10];
    *(undefined4 *)((longlong)_Dst + 0x90) = 1;
    *(undefined4 *)((longlong)_Dst + 0x94) = 1;
    lVar6 = 5;
    *(undefined4 *)((longlong)_Dst + 0x98) = 0;
    *puVar3 = 1;
    *(undefined8 *)(puVar3 + 0x16) = 0;
    puVar3[1] = 1;
    *(undefined8 *)(puVar3 + 0x18) = 0;
    puVar3[2] = 0;
    do {
      *puVar4 = puVar3[0x10];
      puVar4 = puVar4 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  return 0;
}



===== EHCI_InitializeQH @ 1400099d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void * EHCI_InitializeQH(undefined8 param_1,longlong param_2,void *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  
  memset(param_3,0,0x80);
  *(undefined4 *)((longlong)param_3 + 0x44) = param_4;
  *(longlong *)((longlong)param_3 + 0x58) = param_2;
  *(undefined4 *)((longlong)param_3 + 0x48) = 0x68713032;
  uVar5 = ((uint)*(ushort *)(param_2 + 0x28) ^ *(uint *)((longlong)param_3 + 4)) & 0x7f ^
          *(uint *)((longlong)param_3 + 4);
  *(uint *)((longlong)param_3 + 4) = uVar5;
  uVar5 = ((uint)*(ushort *)(param_2 + 0x2a) << 8 ^ uVar5) & 0xf00 ^ uVar5;
  *(uint *)((longlong)param_3 + 4) = uVar5;
  iVar1 = *(int *)(param_2 + 0x30);
  if (iVar1 == 0) {
    uVar4 = 0x534c695f;
    uVar5 = uVar5 & 0xffffdfff | 0x1000;
  }
  else if (iVar1 == 1) {
    uVar5 = uVar5 & 0xffffcfff;
    uVar4 = 0x5346695f;
  }
  else {
    if (iVar1 != 2) {
      (*DAT_140016470)(param_1);
      goto LAB_140009a8f;
    }
    uVar4 = 0x5348695f;
    uVar5 = uVar5 & 0xffffefff | 0x2000;
  }
  *(uint *)((longlong)param_3 + 4) = uVar5;
  (*DAT_140016440)(param_1,0x10000001,uVar4,param_2,0,0);
LAB_140009a8f:
  uVar3 = ((uint)*(ushort *)(param_2 + 0x2c) << 0x10 ^ *(uint *)((longlong)param_3 + 4)) & 0x7ff0000
          ^ *(uint *)((longlong)param_3 + 4);
  uVar5 = *(uint *)((longlong)param_3 + 8);
  *(uint *)((longlong)param_3 + 4) = uVar3;
  uVar2 = uVar5 & 0x3fffffff | 0x40000000;
  *(uint *)((longlong)param_3 + 8) = uVar2;
  if (*(int *)(param_2 + 0x30) == 2) {
    *(uint *)((longlong)param_3 + 8) = uVar5 & 0xffff | 0x40000000;
  }
  else {
    uVar2 = ((uint)*(ushort *)(param_2 + 0x60) << 0x10 ^ uVar2) & 0x7f0000 ^ uVar2;
    *(uint *)((longlong)param_3 + 8) = uVar2;
    *(uint *)((longlong)param_3 + 8) =
         ((uint)*(ushort *)(param_2 + 0x62) << 0x17 ^ uVar2) & 0x3f800000 ^ uVar2;
    if (*(int *)(param_2 + 0x3c) == 1) {
      uVar3 = uVar3 | 0x8000000;
      *(uint *)((longlong)param_3 + 4) = uVar3;
    }
    (*DAT_140016440)(param_1,0x10000001,0x5454695f,*(undefined2 *)(param_2 + 0x62),
                     *(undefined2 *)(param_2 + 0x60),uVar3 >> 0x1b & 1);
  }
  *(undefined4 *)((longlong)param_3 + 0x10) = 1;
  *(undefined4 *)((longlong)param_3 + 0x14) = 1;
  *(undefined4 *)((longlong)param_3 + 0x18) = 0;
  return param_3;
}



===== EHCI_InsertQueueHeadInHWAsyncList @ 140009ba0 =====

void EHCI_InsertQueueHeadInHWAsyncList(longlong param_1,uint *param_2)

{
  uint *puVar1;
  undefined1 uVar2;
  uint *puVar3;
  
  if ((param_2[0x13] & 0x10) == 0) {
    puVar1 = *(uint **)(param_1 + 0xf0);
    puVar3 = *(uint **)(puVar1 + 0x18);
    if ((*(char *)(param_1 + 0x65) != '\0') && (puVar3 == *(uint **)(param_1 + 0xf8))) {
      puVar3 = puVar1;
    }
    *param_2 = puVar3[0x11] & 0xffffffe3 | 2;
    *puVar1 = param_2[0x11] & 0xffffffe3 | 2;
    *(uint **)(param_2 + 0x18) = puVar3;
    *(uint **)(param_2 + 0x1a) = puVar1;
    *(uint **)(puVar1 + 0x18) = param_2;
    *(uint **)(puVar3 + 0x1a) = param_2;
    if (*(char *)(param_1 + 0x5e) == '\0') {
      LOCK();
      param_2[0x13] = param_2[0x13] | 0x10;
      UNLOCK();
    }
    else {
      param_2[0x13] = param_2[0x13] | 0x10;
      LOCK();
      UNLOCK();
    }
    if (*(char *)(param_1 + 0x569) != '\0') {
      uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x110);
      *(void **)(param_1 + 0x118) = SystemReserved1[0xf];
      if (*(longlong *)(param_2 + 0x16) != 0) {
        *(undefined4 *)(*(longlong *)(param_2 + 0x16) + 0x14c) = *(undefined4 *)(param_1 + 0x570);
      }
      *(undefined8 *)(param_1 + 0x118) = 0;
      KeReleaseSpinLock(param_1 + 0x110,uVar2);
    }
  }
  return;
}



===== EHCI_RH_SetWakeConnect @ 140009cb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_RH_SetWakeConnect(longlong param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = *(longlong *)(param_1 + 200);
  if (lVar2 != 0) {
    (*DAT_140016440)(param_1,0x10000001,0x7772735f,param_2,param_1,0);
    if (*(short *)(param_1 + 0x150) != 0) {
      uVar3 = 0;
      do {
        uVar1 = uVar3 + 1;
        (*DAT_140016440)(param_1,0x10000001,0x7072735f,uVar1,0,0);
        *(uint *)(lVar2 + 0x44 + (ulonglong)uVar3 * 4) =
             *(uint *)(lVar2 + 0x44 + (ulonglong)uVar3 * 4) & 0xffcfffd5 |
             ((param_2 & 1) * 2 | param_2 & 1) << 0x14;
        LOCK();
        UNLOCK();
        uVar3 = uVar1;
      } while (uVar1 < *(ushort *)(param_1 + 0x150));
    }
  }
  return 0;
}



===== EHCI_SuspendController @ 140009d90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EHCI_SuspendController(longlong param_1)

{
  uint *puVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 local_88 [32];
  undefined8 *local_68;
  ulonglong local_60;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_88;
  local_68 = &local_48;
  local_48 = 0;
  uStack_40 = 0;
  (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_SUSPEND_DISPATCH,0,1);
  puVar1 = *(uint **)(param_1 + 200);
  if (puVar1 != (uint *)0x0) {
    cVar2 = USBPORT_IsControllerInHibernatePath(*(undefined8 *)(param_1 + 8));
    if ((cVar2 == '\0') && (uVar6 = 0, *(short *)(param_1 + 0x150) != 0)) {
      do {
        uVar5 = (ulonglong)uVar6;
        if (((puVar1[uVar5 + 0x11] & 4) != 0) && ((puVar1[uVar5 + 0x11] & 0x2080) == 0)) {
          uVar4 = puVar1[uVar5 + 0x11];
          local_68 = (undefined8 *)0x0;
          local_60 = uVar5;
          (*DAT_140016440)(param_1,0x10000001,0x7350785f,uVar4);
          puVar1[uVar5 + 0x11] = uVar4 & 0xffffffd5 | 0x80;
          LOCK();
          UNLOCK();
          KeStallExecutionProcessor(0x7d);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(ushort *)(param_1 + 0x150));
    }
    uVar6 = 0;
    *(uint *)(param_1 + 0x3bc) = puVar1[5];
    *(uint *)(param_1 + 0x3c0) = puVar1[6];
    *(uint *)(param_1 + 0x3c4) = puVar1[4];
    *(uint *)(param_1 + 0x3c8) = *puVar1;
    *(uint *)(param_1 + 0x3d8) = puVar1[0x10];
    *(undefined8 *)(param_1 + 0x588) = 0;
    *(undefined8 *)(param_1 + 0x590) = 0;
    *(undefined8 *)(param_1 + 0x598) = 0;
    *(undefined8 *)(param_1 + 0x5a0) = 0;
    *(undefined8 *)(param_1 + 0x5a8) = 0;
    *(undefined8 *)(param_1 + 0x5b0) = 0;
    *(undefined8 *)(param_1 + 0x5b8) = 0;
    *(undefined4 *)(param_1 + 0x5c0) = 0;
    *(undefined8 *)(param_1 + 0x5c4) = 0;
    *(undefined8 *)(param_1 + 0x5cc) = 0;
    *(undefined8 *)(param_1 + 0x5d4) = 0;
    *(undefined8 *)(param_1 + 0x5dc) = 0;
    *(undefined8 *)(param_1 + 0x5e4) = 0;
    *(undefined8 *)(param_1 + 0x5ec) = 0;
    *(undefined8 *)(param_1 + 0x5f4) = 0;
    *(undefined4 *)(param_1 + 0x5fc) = 0;
    if (*(short *)(param_1 + 0x150) != 0) {
      do {
        uVar5 = (ulonglong)uVar6;
        uVar6 = uVar6 + 1;
        *(uint *)(param_1 + 0x588 + uVar5 * 4) = puVar1[uVar5 + 0x11];
      } while (uVar6 < *(ushort *)(param_1 + 0x150));
    }
    *(undefined4 *)(param_1 + 0x140) = 0;
    *puVar1 = *puVar1 & 0xffffffbf;
    LOCK();
    UNLOCK();
    local_60 = 0;
    uVar6 = *puVar1;
    local_68 = (undefined8 *)0x0;
    (*DAT_140016440)(param_1,0x10000001,0x3174735f,uVar6);
    uVar4 = uVar6 & 0xfffffffe;
    if (cVar2 != '\0') {
      uVar4 = uVar6;
    }
    *puVar1 = uVar4 & 0xffffffbf;
    LOCK();
    UNLOCK();
    KeStallExecutionProcessor(0x7d);
    if ((puVar1[1] & 0x3f) != 0) {
      puVar1[1] = puVar1[1] & 0x3f;
      LOCK();
      UNLOCK();
    }
    puVar1[2] = 0;
    LOCK();
    UNLOCK();
    if (cVar2 == '\0') {
      uVar6 = 0;
      do {
        uVar4 = puVar1[1];
        if ((uVar4 >> 0xc & 1) != 0) break;
        (*DAT_140016460)(param_1,1);
        uVar6 = uVar6 + 1;
      } while (uVar6 < 10);
      uVar6 = ~(uVar4 >> 0xc) & 1;
    }
    else {
      uVar6 = 1;
    }
    *(uint *)(param_1 + 0x3dc) = uVar6;
    *(undefined4 *)(param_1 + 0x3cc) = *(undefined4 *)(param_1 + 0xe8);
    uVar6 = puVar1[2];
    *(uint *)(param_1 + 0xe8) = uVar6 | 4;
    puVar1[2] = uVar6 | 4;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x28) = 1;
    cVar3 = (*DAT_140016620)();
    if ((cVar3 == '\0') && (uVar6 = 0, *(short *)(param_1 + 0x150) != 0)) {
      do {
        uVar4 = puVar1[(ulonglong)uVar6 + 0x11];
        if (cVar2 == '\0') {
          *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) & ~(1 << ((byte)uVar6 & 0x1f));
        }
        if ((uVar4 & 0x40) != 0) {
          *(undefined1 *)(param_1 + 0x651) = 1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(ushort *)(param_1 + 0x150));
    }
    local_68 = &local_48;
    local_48 = 0;
    uStack_40 = 0;
    (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_SUSPEND_COMPLETE,0,1);
  }
  return;
}



===== EHCI_RH_EnableIrq @ 14000a120 =====

void EHCI_RH_EnableIrq(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 200);
  if (lVar2 != 0) {
    uVar1 = *(uint *)(lVar2 + 8);
    *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0xe8) | 4;
    if ((uVar1 & 1) != 0) {
      *(uint *)(lVar2 + 8) = uVar1 | 4;
      LOCK();
      UNLOCK();
      return;
    }
  }
  return;
}



===== EHCI_SetEndpointState @ 14000a150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_SetEndpointState(longlong param_1,longlong param_2,int param_3)

{
  int iVar1;
  longlong lVar2;
  
  (*DAT_140016440)(param_1,0x10000001,0x7365735f,param_2,(longlong)*(int *)(param_2 + 0x118),
                   (longlong)param_3);
  iVar1 = *(int *)(param_2 + 0x3c);
  if ((*(uint *)(param_2 + 0x80) & 2) == 0) {
    if (iVar1 == 0) {
      EHCI_SetIsoEndpointState(param_1,param_2,param_3);
      *(undefined4 *)(param_2 + 0x84) = 1;
    }
    else {
      if (((iVar1 != 1) && (iVar1 != 2)) && (iVar1 != 3)) {
        (*DAT_140016470)(param_1);
        return;
      }
      EHCI_SetAsyncEndpointState(param_1,param_2,param_3);
    }
  }
  else if ((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) && (param_3 == 4)) {
    lVar2 = *(longlong *)(param_2 + 0x78);
    if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
      *(uint *)(lVar2 + 0x4c) = *(uint *)(lVar2 + 0x4c) | 2;
      LOCK();
      UNLOCK();
    }
    else {
      LOCK();
      *(uint *)(lVar2 + 0x4c) = *(uint *)(lVar2 + 0x4c) | 2;
      UNLOCK();
    }
  }
  *(int *)(param_2 + 0x118) = param_3;
  return;
}



===== EHCI_SetAsyncEndpointState @ 14000a244 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_SetAsyncEndpointState(longlong param_1,longlong param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2 + 0x78);
  iVar2 = *(int *)(param_2 + 0x3c);
  (*DAT_140016440)(param_1,0x10000001,0x6561735f,lVar3,param_2,0);
  *(undefined8 *)(param_2 + 0x88) = 0;
  if (param_3 != 2) {
    if (param_3 == 3) {
      if (iVar2 == 3) {
        EHCI_InsertQueueHeadInPeriodicList(param_1,param_2);
        return;
      }
      EHCI_InsertQueueHeadInAsyncList(param_1,*(uint **)(param_2 + 0x78));
      return;
    }
    if (param_3 != 4) {
      return;
    }
    puVar1 = (uint *)(lVar3 + 0x4c);
    *puVar1 = *puVar1 | 2;
  }
  if (iVar2 == 3) {
    EHCI_RemoveQueueHeadFromPeriodicList(param_1,param_2);
  }
  else {
    EHCI_RemoveQueueHeadFromAsyncList(param_1,*(longlong *)(param_2 + 0x78));
  }
  return;
}



===== EHCI_SetEndpointStatus @ 14000a310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_SetEndpointStatus(undefined8 param_1,longlong param_2,int param_3)

{
  int iVar1;
  
  if (((*(uint *)(param_2 + 0x80) & 2) == 0) && (iVar1 = *(int *)(param_2 + 0x3c), iVar1 != 0)) {
    if ((iVar1 != 1) && ((iVar1 != 2 && (iVar1 != 3)))) {
      (*DAT_140016470)();
      return;
    }
    EHCI_SetAsyncEndpointStatus(param_1,param_2,param_3);
  }
  return;
}



===== EHCI_SetAsyncEndpointStatus @ 14000a35c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_SetAsyncEndpointStatus(undefined8 param_1,longlong param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar2 = *(longlong *)(param_2 + 0x78);
  uVar1 = *(uint *)(lVar2 + 0x18);
  (*DAT_140016440)(param_1,0x10000001,0x3065735f,param_2,(longlong)param_3,0);
  if (param_3 == 0) {
    if (*(int *)(param_2 + 0x70) == 1) {
      *(undefined4 *)(param_2 + 0x70) = 0;
      lVar3 = *(longlong *)(param_2 + 0x168);
      (*DAT_140016440)(param_1,0x10000001,0x3165735f,param_2,lVar3,lVar2);
      if (lVar3 != 0) {
        (*DAT_140016440)(param_1,0x10000001,0x3265735f,param_2,lVar3,lVar2);
        lVar4 = *(longlong *)(param_2 + 0x78);
        *(undefined4 *)(lVar4 + 0xc) = *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x40);
        *(undefined4 *)(lVar4 + 0x14) = *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x40);
        *(undefined4 *)(lVar4 + 0x10) = *(undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x40);
        *(uint *)(lVar4 + 0x18) = *(uint *)(lVar4 + 0x18) & 0x80008f7d | 0xc00;
        *(uint *)(lVar2 + 0x18) = *(uint *)(lVar2 + 0x18) & 0xffffffbf;
        return;
      }
    }
    *(uint *)(lVar2 + 0x18) = uVar1 & 0xffffffbf;
  }
  else if (param_3 == 1) {
    *(undefined4 *)(param_2 + 0x70) = 1;
  }
  return;
}



===== EHCI_RemoveHsIsoTdsFromSchedule @ 14000a494 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_RemoveHsIsoTdsFromSchedule(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 *puVar7;
  
  lVar6 = *(longlong *)(param_2 + 0x120);
  lVar5 = *(longlong *)(param_2 + 0x128);
  puVar7 = *(undefined4 **)(param_1 + 0x398);
  (*DAT_140016440)(param_1,0x10000001,0x4d52695f,lVar6,lVar5,param_2);
  lVar4 = 0;
  if (*(longlong *)(param_1 + 0x3a8) == param_2) {
    lVar6 = 0;
    lVar4 = 0x400;
    do {
      lVar2 = *(longlong *)(param_2 + 200);
      uVar1 = *(undefined4 *)(lVar6 + lVar2);
      if (*(int *)(param_1 + 0x30) == 0) {
        *puVar7 = uVar1;
      }
      else {
        lVar3 = *(longlong *)(param_1 + 0x3b0);
        *(undefined4 *)(lVar6 + lVar3) = uVar1;
        *(undefined8 *)(lVar6 + 0x70 + lVar3) = *(undefined8 *)(lVar6 + 0x70 + lVar2);
      }
      puVar7 = puVar7 + 1;
      lVar6 = lVar6 + 0x80;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    *(undefined8 *)(param_1 + 0x3a8) = *(undefined8 *)(param_2 + 0x128);
    if (lVar5 != 0) {
      *(undefined8 *)(lVar5 + 0x120) = 0;
    }
  }
  else {
    *(longlong *)(lVar6 + 0x128) = lVar5;
    if (lVar5 != 0) {
      *(longlong *)(lVar5 + 0x120) = lVar6;
    }
    lVar5 = 0x400;
    do {
      *(undefined4 *)(lVar4 + *(longlong *)(lVar6 + 200)) =
           *(undefined4 *)(lVar4 + *(longlong *)(param_2 + 200));
      lVar4 = lVar4 + 0x80;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  return;
}



===== EHCI_StopBIOS @ 14000a5b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 EHCI_StopBIOS(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  uint local_res8 [2];
  undefined8 local_res10;
  
  local_res10 = 0;
  if ((*(char *)(param_1 + 0x70) == '\0') && (uVar1 = EHCI_GetEECP(param_1), (char)uVar1 != '\0')) {
    uVar1 = uVar1 & 0xff;
    (*DAT_140016458)(param_1,1,&local_res10,uVar1,8);
    if (((uint)local_res10 >> 0x10 & 1) != 0) {
      local_res8[0] = (uint)local_res10 | 0x1000000;
      (*DAT_140016458)(param_1,0,local_res8,uVar1,4);
      lVar2 = _DAT_fffff78000000014 + 1000000;
      do {
        (*DAT_140016458)(param_1,1,local_res8,uVar1,4);
        if (lVar2 < _DAT_fffff78000000014) {
          return 0;
        }
      } while ((local_res8[0] & 0x10000) != 0);
    }
  }
  return 0;
}



===== EHCI_InterruptNextSOF @ 14000a6a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_InterruptNextSOF(undefined8 param_1)

{
  (*DAT_140016468)(param_1,3);
  return;
}



===== EHCI_OpenHsIsochronousEndpoint @ 14000a6c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_OpenHsIsochronousEndpoint(longlong param_1,ushort *param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  
  uVar3 = 0;
  uVar2 = 0x10000001;
  lVar1 = param_1;
  (*DAT_140016440)(param_1,0x10000001,0x53706f5f,0,0,param_2);
  iVar5 = *(int *)(param_2 + 0x14);
  *(undefined8 *)(param_3 + 200) = *(undefined8 *)(param_2 + 0x10);
  *(undefined4 *)(param_3 + 0xd8) = 0x400;
  *(undefined4 *)(param_3 + 0xe0) = 0;
  do {
    puVar4 = param_2;
    EHCI_Initialize_iTD(lVar1,uVar2,param_2,
                        (undefined4 *)((ulonglong)uVar3 * 0x80 + *(longlong *)(param_3 + 200)),iVar5
                        ,uVar3);
    iVar5 = iVar5 + 0x80;
    uVar3 = uVar3 + 1;
  } while (uVar3 < *(uint *)(param_3 + 0xd8));
  EHCI_InsertHsIsoTdsInSchedule(param_1,param_3,puVar4,*(longlong *)(param_1 + 0x3a8));
  lVar1 = param_3 + 0xf8;
  *(longlong *)(param_3 + 0x100) = lVar1;
  *(longlong *)lVar1 = lVar1;
  EHCI_EnablePeriodicList(param_1);
  return 0;
}



===== EHCI_Initialize_iTD @ 14000a798 =====

void EHCI_Initialize_iTD(undefined8 param_1,undefined8 param_2,ushort *param_3,undefined4 *param_4,
                        undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  longlong lVar3;
  
  lVar3 = 8;
  *(undefined8 *)(param_4 + 0x1a) = 0;
  param_4[0x18] = param_5;
  param_4[0x19] = param_6;
  param_4[0x17] = 0x64744948;
  puVar1 = param_4;
  do {
    puVar1 = puVar1 + 1;
    *puVar1 = 0;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  uVar2 = ((uint)*param_3 ^ param_4[9]) & 0x7f ^ param_4[9];
  param_4[9] = uVar2;
  param_4[9] = ((uint)param_3[1] << 8 ^ uVar2) & 0xf00 ^ uVar2;
  uVar2 = ((uint)param_3[0x20] ^ param_4[10]) & 0x7ff ^ param_4[10];
  param_4[10] = uVar2;
  param_4[10] = ~-(uint)(*(int *)(param_3 + 0xc) != 0) & 0x800 | uVar2 & 0xfffff7ff;
  param_4[0xb] = ((uint)(byte)param_3[0x1f] ^ param_4[0xb]) & 3 ^ param_4[0xb];
  return;
}



===== EHCI_InsertHsIsoTdsInSchedule @ 14000a844 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_InsertHsIsoTdsInSchedule
               (longlong param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  uint uVar1;
  longlong lVar2;
  uint *puVar3;
  longlong lVar4;
  uint *puVar5;
  uint *puVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  
  (*DAT_140016440)(param_1,0x10000001,0x4841695f,0,param_4,param_2);
  *(longlong *)(param_1 + 0x3a8) = param_2;
  *(undefined8 *)(param_2 + 0x120) = 0;
  *(longlong *)(param_2 + 0x128) = param_4;
  if (param_4 != 0) {
    *(longlong *)(param_4 + 0x120) = param_2;
  }
  puVar6 = *(uint **)(param_1 + 0x398);
  lVar7 = 0;
  uVar8 = 0;
  lVar4 = 0x400;
  lVar9 = 0;
  do {
    puVar5 = (uint *)0x0;
    puVar3 = (uint *)(*(longlong *)(param_2 + 200) + lVar7);
    if (*(int *)(param_1 + 0x30) != 0) {
      puVar5 = (uint *)(*(longlong *)(param_1 + 0x3b0) + lVar9);
    }
    if (param_4 == 0) {
      if (*(int *)(param_1 + 0x30) == 0) {
        *puVar3 = *puVar6;
        lVar2 = *(longlong *)
                 (param_1 + 0x288 + (ulonglong)(byte)(&EHCI_Frame2Qhead)[uVar8 & 0x1f] * 8);
        goto LAB_14000a946;
      }
      *puVar3 = *puVar5;
      *(undefined8 *)(puVar3 + 0x1c) = *(undefined8 *)(puVar5 + 0x1c);
    }
    else {
      if (*(int *)(param_4 + 0x30) == 2) {
        lVar2 = *(longlong *)(param_4 + 200) + lVar7;
        uVar1 = *(uint *)(lVar2 + 0x60);
      }
      else {
        lVar2 = (ulonglong)(uVar8 & 0x1f) * 0x80 + *(longlong *)(param_4 + 0xc0);
        uVar1 = *(uint *)(lVar2 + 0x44) & 0xffffffe5 | 4;
      }
      *puVar3 = uVar1;
LAB_14000a946:
      *(longlong *)(puVar3 + 0x1c) = lVar2;
    }
    if (*(int *)(param_1 + 0x30) == 0) {
      *puVar6 = puVar3[0x18];
    }
    else {
      *puVar5 = puVar3[0x18];
      *(uint **)(puVar5 + 0x1c) = puVar3;
    }
    puVar6 = puVar6 + 1;
    uVar8 = uVar8 + 1;
    lVar9 = lVar9 + 0x80;
    lVar7 = lVar7 + 0x80;
    lVar4 = lVar4 + -1;
    if (lVar4 == 0) {
      return;
    }
  } while( true );
}



===== EHCI_CloseEndpoint @ 14000a9a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_CloseEndpoint(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 local_res10 [8];
  
  local_res10[0] = 0;
  (*DAT_140016440)(param_1,0x10000001,0x6f6c635f,0,0,param_2);
  iVar2 = *(int *)(param_2 + 0x3c);
  uVar3 = *(undefined8 *)(param_2 + 0x78);
  if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 3)) {
    (*DAT_140016440)(param_1,0x10000001,0x4f4c435f,uVar3,0,param_2);
    EHCI_AcquireAsyncDoorbellLock(param_1,local_res10);
    *(undefined8 *)(param_1 + 0x118) = 0;
    KeReleaseSpinLock(param_1 + 0x110,local_res10[0]);
  }
  plVar1 = (longlong *)(param_2 + 0x10);
  (*DAT_140016440)(param_1,0x10000001,0x314c435f,uVar3,*plVar1,*(undefined8 *)(param_2 + 0x18));
  lVar4 = *plVar1;
  if ((*(longlong **)(lVar4 + 8) == plVar1) &&
     (plVar5 = *(longlong **)(param_2 + 0x18), (longlong *)*plVar5 == plVar1)) {
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    *plVar1 = 0;
    *(undefined8 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x118) = 5;
    (*DAT_140016440)(param_1,0x10000001,0x6f6c635f,0,1,param_2);
    return;
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



===== EHCI_RemoveQueueHeadFromPeriodicList @ 14000ab14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EHCI_RemoveQueueHeadFromPeriodicList(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  uint *puVar3;
  uint *puVar4;
  longlong lVar5;
  uint uVar6;
  
  lVar2 = *(longlong *)(param_2 + 0x78);
  puVar3 = *(uint **)(param_1 + 200);
  if ((*(uint *)(lVar2 + 0x4c) & 1) == 0) {
    (*DAT_140016440)(param_1,0x10000001,0x2170725f,param_2,lVar2,*(undefined8 *)(param_2 + 0xa8));
  }
  else {
    (*DAT_140016440)(param_1,0x10000001,0x516d725f,param_2,lVar2,*(undefined8 *)(param_2 + 0xa8));
    puVar4 = *(uint **)(lVar2 + 0x68);
    lVar5 = *(longlong *)(lVar2 + 0x60);
    puVar1 = puVar4 + 0x18;
    if (puVar4 != (uint *)0x0) {
      (*DAT_140016440)(param_1,0x10000001,0x506d725f,puVar4,*(longlong *)puVar1,
                       *(undefined8 *)(puVar4 + 0x1a));
    }
    if (lVar5 == 0) {
      puVar1[0] = 0;
      puVar1[1] = 0;
      uVar6 = 1;
    }
    else {
      (*DAT_140016440)(param_1,0x10000001,0x4e6d725f,lVar5,*(undefined8 *)(lVar5 + 0x60),
                       *(undefined8 *)(lVar5 + 0x68));
      *(longlong *)puVar1 = lVar5;
      if ((*(uint *)(lVar5 + 0x4c) & 4) == 0) {
        *(uint **)(lVar5 + 0x68) = puVar4;
      }
      uVar6 = *(uint *)(lVar5 + 0x44) & 0xffffffe3 | 2;
    }
    *puVar4 = uVar6;
    if (*(char *)(param_1 + 0x5e) == '\0') {
      LOCK();
      *(uint *)(lVar2 + 0x4c) = *(uint *)(lVar2 + 0x4c) & 0xfffffffe;
      UNLOCK();
    }
    else {
      *(uint *)(lVar2 + 0x4c) = *(uint *)(lVar2 + 0x4c) & 0xfffffffe;
      LOCK();
      UNLOCK();
    }
    *(undefined8 *)(lVar2 + 0x60) = 0;
    *(undefined8 *)(lVar2 + 0x68) = 0;
    uVar6 = *puVar3;
    if ((((uVar6 & 0x10) == 0 && (puVar3[1] >> 0xe & 1) == 0) || ((uVar6 & 1) == 0)) ||
       (uVar6 == 0xffffffff)) {
      (*DAT_140016440)(param_1,0x10000001,0x786d725f,lVar2,0,0);
      *(undefined8 *)(param_2 + 0x88) = 0;
      *(undefined4 *)(param_2 + 0x84) = 1;
    }
    else {
      *(undefined4 *)(param_2 + 0x84) = 0;
      *(undefined8 *)(param_2 + 0x88) = _DAT_fffff78000000320;
    }
  }
  return;
}



===== EHCI_RH_ChirpRootPort @ 14000acf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_RH_ChirpRootPort(longlong param_1,ushort param_2)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  
  puVar1 = *(uint **)(param_1 + 200);
  uVar5 = 0;
  if ((puVar1 != (uint *)0x0) && (param_2 != *(ushort *)(param_1 + 1000))) {
    uVar3 = (ulonglong)param_2;
    uVar2 = puVar1[uVar3 + 0x10];
    (*DAT_140016440)(param_1,0x10000001,0x7268635f,uVar2,0,uVar3);
    uVar4 = 1 << ((char)param_2 - 1U & 0x1f);
    if (((*(uint *)(param_1 + 0x140) & uVar4) == 0) &&
       (((uVar2 >> 0xc & 1) != 0 && ((uVar2 & 0x2005) == 1)))) {
      if (((uVar2 & 0xc00) == 0x400) &&
         (((uVar2 & 0x2085) == 1 && (*(char *)(param_1 + 0x5d) != '\0')))) {
        puVar1[uVar3 + 0x10] = uVar2 | 0x2000;
        LOCK();
        UNLOCK();
      }
      else {
        (*DAT_140016440)(param_1,0x10000001,0x7373725f,uVar2,0,uVar3);
        puVar1[uVar3 + 0x10] = uVar2 & 0xfffffffb | 0x100;
        LOCK();
        UNLOCK();
        (*DAT_140016460)(param_1,10);
        do {
          uVar2 = 0;
          puVar1[uVar3 + 0x10] = puVar1[uVar3 + 0x10] & 0xfffffed5;
          LOCK();
          UNLOCK();
          do {
            KeStallExecutionProcessor(0x14);
            uVar2 = uVar2 + 0x14;
            if (((((puVar1[uVar3 + 0x10] & 0x100) == 0) || (puVar1[uVar3 + 0x10] == 0xffffffff)) ||
                (puVar1[0x10] == 0)) || ((*puVar1 & 1) == 0)) goto code_r0x00014000ae6a;
          } while (uVar2 < 0x1f5);
          uVar5 = uVar5 + 1;
        } while (uVar5 < 0x3e9);
code_r0x00014000ae6a:
        if ((puVar1[uVar3 + 0x10] & 4) == 0) {
          if (*(char *)(param_1 + 0x5d) == '\0') {
            return 0;
          }
          puVar1[uVar3 + 0x10] = puVar1[uVar3 + 0x10] | 0x2000;
        }
        else {
          uVar5 = puVar1[uVar3 + 0x10];
          (*DAT_140016460)(param_1,10);
          *(uint *)(param_1 + 0x140) = *(uint *)(param_1 + 0x140) | uVar4;
          puVar1[uVar3 + 0x10] = uVar5 & 0xffffffd1;
        }
        LOCK();
        UNLOCK();
      }
    }
  }
  return 0;
}



===== EHCI_DbgFreeEndpoint @ 14000aee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_DbgFreeEndpoint(longlong param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  (*DAT_140016440)(param_1,0x10000001,0x7065665f,0,0,param_2);
  for (puVar1 = *(undefined8 **)(param_1 + 0x18); puVar1 != (undefined8 *)(param_1 + 0x18);
      puVar1 = (undefined8 *)*puVar1) {
    (*DAT_140016440)(param_1,0x10000001,0x656b635f,puVar1,0,puVar1 + -2);
  }
  (*DAT_140016440)(param_1,0x10000001,0x7065665f,0,1,param_2);
  return;
}



===== EHCI_SetAsyncDoorbellState @ 14000af98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_SetAsyncDoorbellState(longlong param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x55c);
  if (param_2 == 2) {
    if (*(int *)(param_1 + 0x53c) == 0) {
      *(undefined4 *)(param_1 + 0x53c) = 1;
    }
  }
  else if (param_2 == 3) {
    if (*(int *)(param_1 + 0x538) == 0) {
      *(undefined4 *)(param_1 + 0x538) = 1;
    }
  }
  else if ((param_2 == 4) && (*(int *)(param_1 + 0x540) == 0)) {
    *(undefined4 *)(param_1 + 0x540) = 1;
  }
  (*DAT_140016440)(param_1,0x10000001,0x75434441,(longlong)iVar1,(longlong)param_2,0);
  *(int *)(param_1 + 0x55c) = param_2;
  if ((iVar1 != 1) && (param_2 == 1)) {
    *(undefined4 *)(param_1 + 0x538) = 0;
    *(undefined4 *)(param_1 + 0x53c) = 0;
    *(undefined4 *)(param_1 + 0x540) = 0;
    *(undefined4 *)(param_1 + 0x544) = 0;
    if (*(int *)(param_1 + 0x28) == 0) {
      if (*(int *)(param_1 + 0x558) == 2) {
        EHCI_iEnableAsyncList(param_1);
      }
      else if (*(int *)(param_1 + 0x558) == 5) {
        EHCI_iDisableAsyncList(param_1);
      }
      if (*(int *)(param_1 + 0x560) == 2) {
        EHCI_iEnablePeriodicList(param_1);
      }
      else if (*(int *)(param_1 + 0x560) == 5) {
        EHCI_iDisablePeriodicList(param_1);
      }
    }
  }
  return;
}



===== EHCI_WaitFrames @ 14000b0b4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EHCI_WaitFrames(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  
  puVar1 = *(uint **)(param_1 + 200);
  lVar2 = 2;
  do {
    do {
      if ((((*puVar1 & 1) == 0) || (*puVar1 == 0xffffffff)) ||
         (_DAT_fffff78000000014 + 10000000 < _DAT_fffff78000000014)) break;
    } while ((puVar1[3] >> 3 & 0x7ff) == (puVar1[3] >> 3 & 0x7ff));
    lVar2 = lVar2 + -1;
    if (lVar2 == 0) {
      return;
    }
  } while( true );
}



===== EHCI_PassThru @ 14000b120 =====

undefined4 EHCI_PassThru(longlong param_1,longlong *param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = *param_2 + -0x4e3fed5d022252a1;
  if (lVar2 == 0) {
    lVar2 = param_2[1] + 0x2cd4c224264d9069;
  }
  if (lVar2 == 0) {
    uVar3 = EHCI_RH_UsbprivRootPortStatus(param_1,param_3,param_4);
    uVar1 = (undefined4)uVar3;
  }
  else {
    lVar2 = *param_2 + -0x4b0a0e27e1b9c71c;
    if (lVar2 == 0) {
      lVar2 = param_2[1] + 0x122cd06396de7c7d;
    }
    if (lVar2 == 0) {
      uVar1 = EHCI_GetIdleStatus(param_1,param_3,param_4);
      return uVar1;
    }
    lVar2 = *param_2 + -0x49b3debbf5293e35;
    if (lVar2 == 0) {
      lVar2 = param_2[1] + -0xa2dd68d2981f6a5;
    }
    if (lVar2 != 0) {
      return 6;
    }
    uVar3 = EHCI_EtwLogDeviceData(param_1);
    uVar1 = (undefined4)uVar3;
  }
  return uVar1;
}



===== EHCI_RH_UsbprivRootPortStatus @ 14000b1b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_RH_UsbprivRootPortStatus(longlong param_1,uint param_2,uint *param_3)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  
  if (param_2 < 8) {
LAB_14000b39f:
    uVar4 = 5;
  }
  else {
    lVar2 = *(longlong *)(param_1 + 200);
    if (lVar2 != 0) {
      uVar8 = param_3[1];
      uVar1 = (ushort)uVar8;
      uVar7 = (ulonglong)uVar1;
      uVar3 = Feature_1273213241__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar3 != 0) && ((uVar1 == 0 || (*(ushort *)(param_1 + 0x150) < uVar1))))
      goto LAB_14000b39f;
      uVar6 = *(uint *)(lVar2 + 0x40 + uVar7 * 4);
      (*DAT_140016440)(param_1,0x10000001,0x3170555f,uVar7,uVar6,0);
      uVar8 = 1 << ((char)uVar8 - 1U & 0x1f);
      if ((uVar6 & 0x40) != 0) {
        (*DAT_140016460)(param_1,0x32);
        *(uint *)(lVar2 + 0x40 + uVar7 * 4) = uVar6 & 0xffffff15;
        LOCK();
        UNLOCK();
        uVar6 = *(uint *)(lVar2 + 0x40 + uVar7 * 4);
        *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) | uVar8;
        (*DAT_140016440)(param_1,0x10000001,0x3270555f,uVar7,uVar6,0);
      }
      uVar5 = uVar6 >> 1 & 0x40;
      *param_3 = ((uVar5 | uVar6 & 0x1100) >> 3 | uVar6 & 0x14) >> 1 | (uVar6 & 0x2000) << 2 |
                 uVar6 & 1 | 0x400;
      if (((uVar5 == 0) && ((uVar6 & 0x40) == 0)) && ((uVar8 & *(uint *)(param_1 + 0x148)) != 0)) {
        *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) | uVar8;
        *(uint *)(param_1 + 0x148) = ~uVar8 & *(uint *)(param_1 + 0x148);
      }
      uVar5 = (uVar6 << 0xf ^ *param_3) & 0x10000 ^ *param_3;
      uVar5 = (uVar6 << 0xe ^ uVar5) & 0x20000 ^ uVar5;
      uVar5 = (uVar5 ^ uVar6 << 0xe) & 0x80000 ^ uVar5;
      *param_3 = uVar5;
      if ((*(uint *)(param_1 + 0x134) & uVar8) != 0) {
        uVar5 = uVar5 | 0x100000;
        *param_3 = uVar5;
      }
      if ((*(uint *)(param_1 + 0x13c) & uVar8) != 0) {
        uVar5 = uVar5 | 0x10000;
        *param_3 = uVar5;
      }
      if ((*(uint *)(param_1 + 0x138) & uVar8) != 0) {
        uVar5 = uVar5 | 0x40000;
        *param_3 = uVar5;
      }
      (*DAT_140016440)(param_1,0x10000001,0x7370555f,uVar7,uVar5,uVar6);
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== EHCI_RH_DisableIrq @ 14000b3d0 =====

void EHCI_RH_DisableIrq(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 200);
  if (lVar2 != 0) {
    uVar1 = *(uint *)(lVar2 + 8);
    *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0xe8) & 0xfffffffb;
    if ((uVar1 & 1) != 0) {
      *(uint *)(lVar2 + 8) = uVar1 & 0xfffffffb;
      LOCK();
      UNLOCK();
      return;
    }
  }
  return;
}



===== EHCI_RH_PortResetComplete @ 14000b410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_RH_PortResetComplete(longlong param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint *puVar3;
  longlong *plVar4;
  bool bVar5;
  uint uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  uint local_res10;
  uint local_res18;
  
  puVar3 = *(uint **)(param_1 + 200);
  local_res10 = 0;
  bVar5 = false;
  if (puVar3 != (uint *)0x0) {
    plVar4 = *(longlong **)(param_2 + 4);
    uVar1 = *param_2;
    uVar8 = (ulonglong)uVar1;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    (*DAT_140016440)(param_1,0x10000001,0x4372705f,param_2,0,0);
    if (uVar1 < 0x10) {
      *(undefined8 *)(param_1 + 1000 + uVar8 * 8) = 0;
      *(undefined8 *)(param_1 + 0x460 + uVar8 * 8) = 0;
      do {
        local_res18 = 0;
        uVar2 = puVar3[uVar8 + 0x10];
        if (local_res10 < 10) {
          (*DAT_140016440)(param_1,0x10000001,0x3272705f,uVar2,*(undefined4 *)(param_1 + 0x134),
                           uVar8);
        }
        puVar3[uVar8 + 0x10] = uVar2 & 0xfffffed5;
        LOCK();
        UNLOCK();
        while( true ) {
          KeStallExecutionProcessor(0x14);
          uVar2 = puVar3[uVar8 + 0x10];
          local_res18 = local_res18 + 0x14;
          if (500 < local_res18) break;
          if (uVar2 == 0xffffffff) goto LAB_14000b5d8;
          uVar6 = puVar3[0x10];
          if (local_res10 < 10) {
            (*DAT_140016440)(param_1,0x10000001,0x3372705f,uVar2,uVar6,uVar8);
          }
          if ((uVar6 == 0) || ((*(char *)(param_1 + 0x650) == '\0' && ((*puVar3 & 1) == 0))))
          goto LAB_14000b5d8;
          if ((uVar2 >> 8 & 1) == 0) goto LAB_14000b5db;
        }
        local_res10 = local_res10 + 1;
      } while (local_res10 < 0x3e9);
LAB_14000b5d8:
      bVar5 = true;
LAB_14000b5db:
      if (*(char *)(param_1 + 0x650) != '\0') {
        EHCI_QualcommClearUlpiReset(param_1);
        *puVar3 = *puVar3 | 1;
        LOCK();
        UNLOCK();
      }
      uVar8 = (ulonglong)uVar1;
      if (bVar5) {
        *(uint *)(param_1 + 0x140) = *(uint *)(param_1 + 0x140) & ~(1 << ((char)uVar1 - 1U & 0x1f));
      }
      else {
        plVar7 = EHCI_RefAsyncIdle(param_1,3);
        *(longlong **)(param_2 + 4) = plVar7;
        *(longlong **)(param_1 + 0x460 + uVar8 * 8) = plVar7;
        uVar6 = (*DAT_140016568)(param_1,0x32,param_2,0x18,EHCI_RH_FinishReset,
                                 param_1 + (uVar8 + 0x7d) * 8,1);
        (*DAT_140016440)(param_1,0x10000001,0x3472705f,uVar8,uVar2,(longlong)(int)uVar6);
        if (((uVar6 & 0xc0000000) == 0xc0000000) && (*(longlong **)(param_2 + 4) != (longlong *)0x0)
           ) {
          EHCI_DerefAsyncIdle(param_1,*(longlong **)(param_2 + 4));
          param_2[4] = 0;
          param_2[5] = 0;
          param_2[6] = 0;
          param_2[7] = 0;
          *(undefined8 *)(param_1 + 0x460 + uVar8 * 8) = 0;
        }
      }
      if (plVar4 != (longlong *)0x0) {
        EHCI_DerefAsyncIdle(param_1,plVar4);
      }
    }
    else {
      if (plVar4 != (longlong *)0x0) {
        EHCI_DerefAsyncIdle(param_1,plVar4);
      }
      (*DAT_140016440)(param_1,0x10000001,0x3172705f,param_2,0,0);
    }
  }
  return;
}



===== EHCI_RH_PortResumeComplete @ 14000b6f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_RH_PortResumeComplete(longlong param_1,ushort *param_2)

{
  ushort uVar1;
  longlong lVar2;
  ushort uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  lVar2 = *(longlong *)(param_1 + 200);
  if (lVar2 != 0) {
    uVar1 = *param_2;
    uVar8 = (ulonglong)uVar1;
    uVar6 = *(uint *)(lVar2 + 0x40 + uVar8 * 4);
    (*DAT_140016440)(param_1,0x10000001,0x5352705f,uVar6,*(undefined4 *)(param_1 + 0x138),uVar8);
    *(uint *)(lVar2 + 0x40 + uVar8 * 4) = uVar6 & 0xffffff15;
    LOCK();
    UNLOCK();
    if (((*(int *)(param_1 + 0x5fc + uVar8 * 4) != 0) && (*(uint *)(param_2 + 8) < 0x32)) &&
       ((char)*(undefined4 *)(lVar2 + 0x40 + uVar8 * 4) < '\0')) {
      uVar3 = param_2[10];
      *(undefined1 *)(param_2 + 10) = 1;
      iVar5 = (-(uint)((char)uVar3 != '\0') & 0xd) + 2;
      *(uint *)(param_2 + 8) = iVar5 + *(uint *)(param_2 + 8);
      iVar5 = (*DAT_140016568)(param_1,iVar5,param_2,0x18,EHCI_RH_PortResumeComplete,0,1);
      if (-1 < iVar5) {
        return;
      }
    }
    uVar6 = 1 << ((char)uVar1 - 1U & 0x1f);
    uVar7 = ~uVar6;
    *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) & uVar7;
    cVar4 = (*DAT_140016620)(param_1);
    if (cVar4 == '\0') {
      *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) | uVar6;
      *(uint *)(param_1 + 0x148) = *(uint *)(param_1 + 0x148) & uVar7;
      (*DAT_140016420)(param_1);
    }
    if (*(longlong **)(param_2 + 4) != (longlong *)0x0) {
      EHCI_DerefAsyncIdle(param_1,*(longlong **)(param_2 + 4));
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[6] = 0;
      param_2[7] = 0;
    }
  }
  return;
}



===== EHCI_RH_GetHubStatus @ 14000b840 =====

undefined8 EHCI_RH_GetHubStatus(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  return 0;
}



===== EHCI_RH_SetFeaturePortSuspend @ 14000b850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_RH_SetFeaturePortSuspend(longlong param_1,ushort param_2)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  
  puVar1 = *(uint **)(param_1 + 200);
  uVar3 = (ulonglong)param_2;
  if ((puVar1 != (uint *)0x0) && (param_2 != *(ushort *)(param_1 + 1000))) {
    if (*(char *)(param_1 + 0x650) != '\0') {
      *puVar1 = *puVar1 & 0xfffffffe;
      LOCK();
      UNLOCK();
      uVar2 = 0;
      do {
        if ((puVar1[1] >> 0xc & 1) != 0) break;
        KeStallExecutionProcessor(0x7d);
        uVar2 = uVar2 + 1;
      } while (uVar2 < 0x10);
    }
    uVar2 = puVar1[uVar3 + 0x10];
    (*DAT_140016440)(param_1,0x10000001,0x7370735f,uVar2,0,uVar3);
    *(uint *)(param_1 + 0x148) = *(uint *)(param_1 + 0x148) | 1 << ((char)param_2 - 1U & 0x1f);
    puVar1[uVar3 + 0x10] = uVar2 & 0xffffffd5 | 0x80;
    LOCK();
    UNLOCK();
    KeStallExecutionProcessor(0x7d);
    if (*(char *)(param_1 + 0x650) != '\0') {
      *puVar1 = *puVar1 | 1;
      LOCK();
      UNLOCK();
    }
  }
  return 0;
}



===== EHCI_QueryEndpointRequirements @ 14000b970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_QueryEndpointRequirements(undefined8 param_1,longlong param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 == 0) {
    if (*(int *)(param_2 + 8) == 2) {
      *param_3 = 0x20000;
      param_3[1] = 0x180000;
    }
    else {
      *param_3 = 0x1000;
      param_3[1] = 0x40000;
    }
  }
  else if (iVar1 == 1) {
    *param_3 = 0x400;
    param_3[1] = 0x10000;
  }
  else if ((iVar1 == 2) || (iVar1 == 3)) {
    *param_3 = 0x2100;
    param_3[1] = 0x80000;
  }
  else {
    *param_3 = 0;
    param_3[1] = 0;
    (*DAT_140016470)();
  }
  return 0;
}



===== EHCI_GetEECP @ 14000ba00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong EHCI_GetEECP(longlong param_1)

{
  uint uVar1;
  byte bVar2;
  ulonglong in_RAX;
  uint uVar3;
  uint local_res10 [6];
  
  local_res10[0] = 0;
  if (*(char *)(param_1 + 0x70) == '\0') {
    uVar1 = *(uint *)(*(longlong *)(param_1 + 0xd0) + 8);
    uVar3 = uVar1 >> 8;
    bVar2 = (byte)(uVar1 >> 8);
    while (bVar2 != 0) {
      (*DAT_140016458)(param_1,1,local_res10,uVar3 & 0xff,4);
      if ((char)local_res10[0] == '\x01') {
        return (ulonglong)CONCAT31((int3)(local_res10[0] >> 8),(char)uVar3);
      }
      in_RAX = (ulonglong)(local_res10[0] >> 8);
      bVar2 = (byte)(local_res10[0] >> 8);
      uVar3 = (uint)bVar2;
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== EHCI_UpdateEndpointAsFreedFromHwCache @ 14000ba7c =====

void EHCI_UpdateEndpointAsFreedFromHwCache(longlong param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined8 *)(param_2 + 0x88) = 0;
  *(undefined4 *)(param_2 + 0x90) = 0;
  if (*(char *)(param_1 + 0x569) != '\0') {
    *(undefined4 *)(param_2 + 0x14c) = 0;
  }
  return;
}



===== EHCI_sMode_InitEndpoint @ 14000baac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_sMode_InitEndpoint(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  undefined4 *puVar7;
  longlong lVar8;
  
  lVar1 = *(longlong *)(param_2 + 0x78);
  *(undefined4 *)(param_2 + 0x15c) = 0;
  *(undefined4 *)(param_2 + 0x158) = 0x20;
  *(undefined4 *)(param_2 + 0x150) = 1;
  *(undefined4 *)(param_2 + 0x160) = 2;
  (*DAT_140016440)(param_1,0x10000001,0x49676c5f,lVar1,0x20,0);
  uVar6 = 0;
  lVar2 = EHCI_AllocTd(param_1,param_2);
  uVar4 = *(uint *)(param_2 + 0x160);
  lVar8 = lVar2;
  if (uVar4 != 0) {
    do {
      puVar7 = (undefined4 *)(uVar6 * 0x120 + 0x180 + param_2);
      iVar5 = (int)uVar6;
      if (iVar5 == uVar4 - 1) {
        lVar3 = lVar2;
      }
      else {
        lVar3 = EHCI_AllocTd(param_1,param_2);
      }
      EHCI_sMode_InitSlot(param_1,param_2,iVar5,puVar7,lVar8,lVar3);
      *(undefined4 **)(param_2 + 0x170 + uVar6 * 8) = puVar7;
      uVar4 = *(uint *)(param_2 + 0x160);
      uVar6 = (ulonglong)(iVar5 + 1U);
      lVar8 = lVar3;
    } while (iVar5 + 1U < uVar4);
  }
  if (*(char *)(param_1 + 0x62) == '\0') {
    *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(*(longlong *)(param_2 + 0x198) + 0x40);
    *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)(*(longlong *)(param_2 + 0x198) + 0x40);
    *(undefined4 *)(lVar1 + 0x14) = *(undefined4 *)(*(longlong *)(param_2 + 0x198) + 0x40);
  }
  *(uint *)(lVar1 + 0x18) = *(uint *)(lVar1 + 0x18) & 0x8000ff7f;
  return;
}



===== __report_gsfailure @ 14000bc10 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== memcpy_s @ 14000bc20 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_14000bc3d:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_14000bc7f:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memmove(_Dst,_Src,_MaxCount);
        goto LAB_14000bc3d;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_14000bc7f;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _guard_check_icall();
  }
  return eVar1;
}



===== __cpu_features_init @ 14000bcc0 =====

/* WARNING: Removing unreachable block (ram,0x00014000bd2a) */
/* WARNING: Removing unreachable block (ram,0x00014000bcd9) */
/* WARNING: Removing unreachable block (ram,0x00014000bcca) */

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



===== EHCI_AbortIsoTransfer @ 14000bd88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_AbortIsoTransfer(longlong param_1,longlong param_2,longlong *param_3)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = 0;
  if (*(int *)(param_2 + 0x30) == 2) {
    lVar3 = 0x400;
    do {
      bVar1 = *(byte *)(param_2 + 0x2e);
      (*DAT_140016440)(param_1,0x10000001,0x6862695f,param_3,param_2,(ulonglong)bVar1);
      lVar2 = *(longlong *)(param_2 + 200);
      if (*(longlong **)(lVar4 + 0x78 + lVar2) == param_3) {
        *(undefined8 *)(lVar4 + 0x78 + lVar2) = 0;
        *(undefined8 *)(lVar4 + 0x68 + lVar2) = 0;
        *(int *)(param_3 + 10) = (int)param_3[10] - (int)(8 / (ulonglong)bVar1);
      }
      lVar4 = lVar4 + 0x80;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
  else {
    lVar3 = 0x20;
    do {
      (*DAT_140016440)(param_1,0x10000001,0x6962695f,param_3,param_2,1);
      lVar2 = *(longlong *)(param_2 + 0xc0);
      if (*(longlong **)(lVar4 + 0x58 + lVar2) == param_3) {
        *(undefined8 *)(lVar4 + 0x58 + lVar2) = 0;
        *(undefined8 *)(lVar4 + 0x50 + lVar2) = 0;
        *(int *)(param_3 + 10) = (int)param_3[10] + -1;
      }
      lVar4 = lVar4 + 0x80;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
  EHCI_DecPendingTransfer(param_1,param_2,param_3);
  return 0;
}



===== EHCI_InsertIsoTdsInSchedule @ 14000be9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_InsertIsoTdsInSchedule
               (longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  uint *puVar5;
  undefined4 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint *puVar9;
  longlong lVar10;
  uint uVar11;
  
  (*DAT_140016440)(param_1,0x10000001,0x4441695f,param_3,param_4,param_2);
  puVar9 = *(uint **)(param_1 + 0x398);
  uVar11 = 0;
  lVar7 = 0;
  do {
    lVar10 = (ulonglong)(uVar11 & 0x1f) * 0x80;
    puVar5 = (uint *)(*(longlong *)(param_2 + 0xc0) + lVar10);
    if (param_4 == 0) {
      if (param_3 == 0) {
        if (uVar11 == 0) {
          *(longlong *)(param_1 + 0x3a8) = param_2;
          *(undefined8 *)(param_2 + 0x120) = 0;
          *(undefined8 *)(param_2 + 0x128) = 0;
        }
        if (*(int *)(param_1 + 0x30) == 0) {
          uVar8 = *(undefined8 *)
                   (param_1 + 0x288 + (ulonglong)(byte)(&EHCI_Frame2Qhead)[uVar11 & 0x1f] * 8);
          *puVar5 = *puVar9;
        }
        else {
          lVar10 = *(longlong *)(param_1 + 0x3b0);
          *puVar5 = *(uint *)(lVar7 + lVar10);
          uVar8 = *(undefined8 *)(lVar7 + 0x70 + lVar10);
        }
        *(undefined8 *)(puVar5 + 0x18) = uVar8;
LAB_14000c16e:
        uVar3 = puVar5[0x11] & 0xffffffe5 | 4;
        if (*(int *)(param_1 + 0x30) == 0) {
          *puVar9 = uVar3;
        }
        else {
          lVar10 = *(longlong *)(param_1 + 0x3b0);
          *(uint *)(lVar7 + lVar10) = uVar3;
          *(uint **)(lVar7 + 0x70 + lVar10) = puVar5;
        }
      }
      else {
        if (uVar11 == 0) {
          *(longlong *)(param_3 + 0x128) = param_2;
          *(undefined8 *)(param_2 + 0x128) = 0;
          *(longlong *)(param_2 + 0x120) = param_3;
        }
        (*DAT_140016440)(param_1,0x10000001,0x4c54695f,param_3,0,param_2);
        puVar6 = (undefined4 *)(*(longlong *)(param_2 + 0xc0) + lVar10);
        if (*(int *)(param_3 + 0x30) == 2) {
          lVar10 = *(longlong *)(param_3 + 200);
          uVar8 = *(undefined8 *)(lVar7 + 0x70 + lVar10);
          *puVar6 = *(undefined4 *)(lVar7 + lVar10);
          *(undefined8 *)(puVar6 + 0x18) = uVar8;
          *(undefined4 **)(lVar7 + 0x70 + lVar10) = puVar6;
          *(uint *)(lVar7 + lVar10) = puVar6[0x11] & 0xffffffe5 | 4;
        }
        else {
          lVar4 = *(longlong *)(param_3 + 0xc0);
          if (uVar11 < 0x20) {
            uVar1 = *(undefined4 *)(lVar10 + lVar4);
            uVar8 = *(undefined8 *)(lVar10 + 0x60 + lVar4);
            *(undefined8 *)(puVar6 + 0x18) = uVar8;
            *puVar6 = uVar1;
            (*DAT_140016440)(param_1,0x10000001,0x316e695f,uVar1,uVar8,puVar6);
            uVar3 = puVar6[0x11];
            *(undefined4 **)(lVar10 + 0x60 + lVar4) = puVar6;
            uVar3 = uVar3 & 0xffffffe5 | 4;
            *(uint *)(lVar10 + lVar4) = uVar3;
            (*DAT_140016440)(param_1,0x10000001,0x326e695f,uVar3,puVar6,puVar6);
          }
        }
      }
    }
    else {
      if (uVar11 == 0) {
        *(longlong *)(param_2 + 0x128) = param_4;
        *(longlong *)(param_4 + 0x120) = param_2;
      }
      lVar4 = *(longlong *)(param_4 + 0xc0) + lVar10;
      uVar3 = *(uint *)(lVar4 + 0x44);
      *(longlong *)(puVar5 + 0x18) = lVar4;
      *puVar5 = uVar3 & 0xffffffe5 | 4;
      if (param_3 == 0) {
        if (uVar11 == 0) {
          *(longlong *)(param_1 + 0x3a8) = param_2;
          *(undefined8 *)(param_2 + 0x120) = 0;
        }
        goto LAB_14000c16e;
      }
      if (uVar11 == 0) {
        *(longlong *)(param_3 + 0x128) = param_2;
        *(longlong *)(param_2 + 0x120) = param_3;
      }
      lVar4 = *(longlong *)(param_2 + 0xc0) + lVar10;
      uVar3 = *(uint *)(lVar4 + 0x44) & 0xffffffe5 | 4;
      if (*(int *)(param_3 + 0x30) == 2) {
        lVar10 = *(longlong *)(param_3 + 200);
        *(uint *)(lVar7 + lVar10) = uVar3;
        *(longlong *)(lVar7 + 0x70 + lVar10) = lVar4;
      }
      else {
        lVar2 = *(longlong *)(param_3 + 0xc0);
        *(uint *)(lVar10 + lVar2) = uVar3;
        *(longlong *)(lVar10 + 0x60 + lVar2) = lVar4;
      }
    }
    puVar9 = puVar9 + 1;
    uVar11 = uVar11 + 1;
    lVar7 = lVar7 + 0x80;
    if (0x3ff < uVar11) {
      return;
    }
  } while( true );
}



===== EHCI_OpenIsochronousEndpoint @ 14000c19c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_OpenIsochronousEndpoint(longlong param_1,ushort *param_2,longlong param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  int iVar10;
  
  (*DAT_140016440)(param_1,0x10000001,0x52706f5f,0,0,param_2);
  uVar3 = *(undefined8 *)(param_2 + 0x10);
  iVar10 = *(int *)(param_2 + 0x14);
  *(undefined4 *)(param_3 + 0xe0) = 0;
  *(undefined8 *)(param_3 + 0xc0) = uVar3;
  uVar9 = 0;
  uVar5 = 0x20;
  *(undefined4 *)(param_3 + 0xd8) = 0x20;
  do {
    lVar7 = *(longlong *)(param_3 + 0xc0);
    uVar4 = uVar9;
    if (uVar9 == 0) {
      uVar4 = uVar5;
    }
    lVar6 = (ulonglong)uVar9 * 0x80 + lVar7;
    *(undefined4 *)(lVar6 + 4) = 0;
    *(undefined8 *)(lVar6 + 0x50) = 0;
    *(int *)(lVar6 + 0x44) = iVar10;
    *(undefined4 *)(lVar6 + 0x40) = 0x64744953;
    uVar1 = *param_2;
    *(uint *)(lVar6 + 4) = uVar1 & 0x7f;
    uVar5 = (param_2[1] & 0xf) << 8 | uVar1 & 0x7f;
    *(uint *)(lVar6 + 4) = uVar5;
    uVar5 = (param_2[0x1c] & 0x7f) << 0x10 | uVar5;
    *(uint *)(lVar6 + 4) = uVar5;
    uVar5 = (param_2[0x1d] & 0x7f) << 0x18 | uVar5;
    *(uint *)(lVar6 + 4) = uVar5;
    iVar2 = *(int *)(param_2 + 0xc);
    *(undefined4 *)(lVar6 + 8) = 0;
    iVar10 = iVar10 + 0x80;
    uVar9 = uVar9 + 1;
    *(uint *)(lVar6 + 4) = ~-(uint)(iVar2 != 0) & 0x80000000 | uVar5;
    *(undefined1 *)(lVar6 + 9) = *(undefined1 *)((longlong)param_2 + 0x3d);
    *(char *)(lVar6 + 8) = (char)param_2[0x1e];
    *(undefined4 *)(lVar6 + 0x18) = *(undefined4 *)((ulonglong)(uVar4 - 1) * 0x80 + lVar7 + 0x44);
    *(undefined4 *)(lVar6 + 0xc) = 0;
    uVar5 = *(uint *)(param_3 + 0xd8);
  } while (uVar9 < uVar5);
  *(undefined4 *)(*(longlong *)(param_3 + 0xc0) + 0x18) =
       *(undefined4 *)((ulonglong)(uVar5 - 1) * 0x80 + 0x44 + *(longlong *)(param_3 + 0xc0));
  lVar6 = *(longlong *)(param_1 + 0x3a8);
  lVar7 = 0;
  while (lVar8 = lVar6, lVar8 != 0) {
    if (*(int *)(lVar8 + 0x30) != 2) {
      lVar6 = lVar8;
      goto LAB_14000c2fd;
    }
    lVar7 = lVar8;
    lVar6 = *(longlong *)(lVar8 + 0x128);
  }
  goto LAB_14000c31d;
  while (lVar8 = *(longlong *)(lVar6 + 0x128), lVar7 = lVar6, lVar6 = lVar8, lVar8 != 0) {
LAB_14000c2fd:
    if ((*(uint *)(param_3 + 0x6c) <= *(uint *)(lVar6 + 0x6c)) &&
       ((lVar8 = lVar6, *(uint *)(param_3 + 0x6c) != *(uint *)(lVar6 + 0x6c) ||
        (*(byte *)(param_3 + 100) <= *(byte *)(lVar6 + 100))))) break;
  }
LAB_14000c31d:
  EHCI_InsertIsoTdsInSchedule(param_1,param_3,lVar7,lVar8);
  lVar7 = param_3 + 0xf8;
  *(longlong *)(param_3 + 0x100) = lVar7;
  *(longlong *)lVar7 = lVar7;
  EHCI_EnablePeriodicList(param_1);
  return 0;
}



===== EHCI_PokeIsoEndpoint @ 14000c358 =====

undefined8 EHCI_PokeIsoEndpoint(undefined8 param_1,ushort *param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (*(int *)(param_3 + 0x30) == 2) {
    uVar4 = 0;
    if (*(int *)(param_3 + 0xd8) != 0) {
      do {
        uVar3 = (int)uVar4 + 1;
        lVar2 = uVar4 * 0x80 + *(longlong *)(param_3 + 200);
        uVar1 = ((uint)*param_2 ^ *(uint *)(lVar2 + 0x24)) & 0x7f ^ *(uint *)(lVar2 + 0x24);
        *(uint *)(lVar2 + 0x24) = uVar1;
        *(uint *)(lVar2 + 0x24) = ((uint)param_2[1] << 8 ^ uVar1) & 0xf00 ^ uVar1;
        uVar4 = (ulonglong)uVar3;
      } while (uVar3 < *(uint *)(param_3 + 0xd8));
    }
  }
  else {
    uVar4 = 0;
    if (*(int *)(param_3 + 0xd8) != 0) {
      do {
        uVar3 = (int)uVar4 + 1;
        lVar2 = uVar4 * 0x80 + *(longlong *)(param_3 + 0xc0);
        uVar1 = ((uint)*param_2 ^ *(uint *)(lVar2 + 4)) & 0x7f ^ *(uint *)(lVar2 + 4);
        *(uint *)(lVar2 + 4) = uVar1;
        *(uint *)(lVar2 + 4) = ((uint)param_2[0x1c] << 0x10 ^ uVar1) & 0x7f0000 ^ uVar1;
        uVar4 = (ulonglong)uVar3;
      } while (uVar3 < *(uint *)(param_3 + 0xd8));
    }
  }
  return 0;
}



===== EHCI_PollResetIsoEndpoint @ 14000c404 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_PollResetIsoEndpoint(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  
  puVar3 = *(undefined8 **)(param_2 + 0xf8);
  while (puVar3 != (undefined8 *)(param_2 + 0xf8)) {
    plVar4 = puVar3 + -7;
    uVar2 = 0;
    if (*(int *)(puVar3[2] + 4) != 0) {
      puVar1 = (undefined4 *)(puVar3[2] + 0x20);
      do {
        puVar1[-3] = 0;
        uVar2 = uVar2 + 1;
        *puVar1 = 0xc0000011;
        puVar1 = puVar1 + 0xe;
      } while (uVar2 < *(uint *)(puVar3[2] + 4));
    }
    puVar3 = (undefined8 *)*puVar3;
    EHCI_DecPendingTransfer(param_1,param_2,plVar4);
    (*DAT_140016438)(param_1,param_2,plVar4[3],plVar4[9]);
  }
  return;
}



===== EHCI_RebalanceIsoEndpoint @ 14000c4a0 =====

void EHCI_RebalanceIsoEndpoint(longlong param_1,undefined8 *param_2,longlong param_3)

{
  undefined8 uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  
  uVar2 = EHCI_Get32BitFrameNumber(param_1);
  uVar1 = param_2[1];
  uVar4 = 0;
  *(undefined8 *)(param_3 + 0x28) = *param_2;
  *(undefined8 *)(param_3 + 0x30) = uVar1;
  uVar1 = param_2[3];
  *(undefined8 *)(param_3 + 0x38) = param_2[2];
  *(undefined8 *)(param_3 + 0x40) = uVar1;
  uVar1 = param_2[5];
  *(undefined8 *)(param_3 + 0x48) = param_2[4];
  *(undefined8 *)(param_3 + 0x50) = uVar1;
  uVar1 = param_2[7];
  *(undefined8 *)(param_3 + 0x58) = param_2[6];
  *(undefined8 *)(param_3 + 0x60) = uVar1;
  *(undefined8 *)(param_3 + 0x68) = param_2[8];
  if (*(int *)(param_3 + 0xd8) != 1) {
    do {
      uVar2 = uVar2 + 1 & 0x1f;
      uVar4 = uVar4 + 1;
      lVar3 = (ulonglong)uVar2 * 0x80 + *(longlong *)(param_3 + 0xc0);
      *(undefined1 *)(lVar3 + 9) = *(undefined1 *)((longlong)param_2 + 0x3d);
      *(undefined1 *)(lVar3 + 8) = *(undefined1 *)((longlong)param_2 + 0x3c);
    } while (uVar4 < *(int *)(param_3 + 0xd8) - 1U);
  }
  return;
}



===== EHCI_RemoveIsoTdsFromSchedule @ 14000c534 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_RemoveIsoTdsFromSchedule(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 *puVar5;
  uint uVar6;
  longlong lVar7;
  undefined4 *puVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  
  lVar7 = *(longlong *)(param_2 + 0x120);
  lVar2 = *(longlong *)(param_2 + 0x128);
  (*DAT_140016440)();
  if (*(longlong *)(param_1 + 0x3a8) == param_2) {
    puVar8 = *(undefined4 **)(param_1 + 0x398);
    lVar7 = 0;
    uVar11 = 0;
    lVar9 = 0x400;
    do {
      puVar5 = (undefined4 *)((ulonglong)(uVar11 & 0x1f) * 0x80 + *(longlong *)(param_2 + 0xc0));
      uVar1 = *puVar5;
      if (*(int *)(param_1 + 0x30) == 0) {
        *puVar8 = uVar1;
      }
      else {
        lVar10 = *(longlong *)(param_1 + 0x3b0);
        *(undefined4 *)(lVar7 + lVar10) = uVar1;
        *(undefined8 *)(lVar7 + 0x70 + lVar10) = *(undefined8 *)(puVar5 + 0x18);
      }
      puVar8 = puVar8 + 1;
      uVar11 = uVar11 + 1;
      lVar7 = lVar7 + 0x80;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    *(undefined8 *)(param_1 + 0x3a8) = *(undefined8 *)(param_2 + 0x128);
    if (lVar2 != 0) {
      *(undefined8 *)(lVar2 + 0x120) = 0;
    }
  }
  else {
    if (*(int *)(lVar7 + 0x30) == 2) {
      lVar10 = 0x400;
      uVar11 = 0;
      lVar9 = 0;
      do {
        lVar3 = *(longlong *)(lVar7 + 200);
        uVar6 = uVar11 & 0x1f;
        uVar11 = uVar11 + 1;
        puVar8 = (undefined4 *)((ulonglong)uVar6 * 0x80 + *(longlong *)(param_2 + 0xc0));
        *(undefined4 *)(lVar9 + lVar3) = *puVar8;
        *(undefined8 *)(lVar9 + 0x70 + lVar3) = *(undefined8 *)(puVar8 + 0x18);
        lVar10 = lVar10 + -1;
        lVar9 = lVar9 + 0x80;
      } while (lVar10 != 0);
    }
    else {
      lVar9 = 0;
      lVar10 = 0x20;
      do {
        lVar3 = *(longlong *)(param_2 + 0xc0);
        lVar4 = *(longlong *)(lVar7 + 0xc0);
        *(undefined4 *)(lVar9 + lVar4) = *(undefined4 *)(lVar9 + lVar3);
        *(undefined8 *)(lVar9 + 0x60 + lVar4) = *(undefined8 *)(lVar9 + 0x60 + lVar3);
        lVar9 = lVar9 + 0x80;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
    }
    *(undefined8 *)(lVar7 + 0x128) = *(undefined8 *)(param_2 + 0x128);
    if (lVar2 != 0) {
      *(longlong *)(lVar2 + 0x120) = lVar7;
    }
  }
  return;
}



===== EHCI_SetIsoEndpointState @ 14000c6b8 =====

void EHCI_SetIsoEndpointState(longlong param_1,longlong param_2,int param_3)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  
  if (param_3 == 2) {
    uVar4 = 0;
    if (*(int *)(param_2 + 0x30) == 2) {
      if (*(int *)(param_2 + 0xd8) != 0) {
        do {
          lVar6 = 8;
          lVar5 = (ulonglong)uVar4 << 7;
          lVar2 = (ulonglong)uVar4 << 7;
          do {
            lVar2 = lVar2 + 4;
            lVar5 = lVar5 + 4;
            *(uint *)(*(longlong *)(param_2 + 200) + lVar2) =
                 *(uint *)(*(longlong *)(param_2 + 200) + lVar5) & 0x7fffffff;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(param_2 + 0xd8));
      }
    }
    else if (*(int *)(param_2 + 0xd8) != 0) {
      do {
        uVar3 = (ulonglong)uVar4;
        uVar4 = uVar4 + 1;
        *(uint *)(uVar3 * 0x80 + 0xc + *(longlong *)(param_2 + 0xc0)) =
             *(uint *)(uVar3 * 0x80 + 0xc + *(longlong *)(param_2 + 0xc0)) & 0xffffff7f;
      } while (uVar4 < *(uint *)(param_2 + 0xd8));
    }
  }
  else if (param_3 == 3) {
    iVar1 = EHCI_Get32BitFrameNumber(param_1);
    *(int *)(param_2 + 0xe0) = iVar1;
  }
  else if (param_3 == 4) {
    if (*(int *)(param_2 + 0x30) == 2) {
      EHCI_RemoveHsIsoTdsFromSchedule(param_1,param_2);
    }
    else {
      EHCI_RemoveIsoTdsFromSchedule(param_1,param_2);
    }
  }
  return;
}



===== EHCI_InsertQueueHeadInPeriodicList @ 14000c79c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_InsertQueueHeadInPeriodicList(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  
  puVar4 = *(uint **)(param_2 + 0xa8);
  puVar1 = *(uint **)(param_2 + 0x78);
  puVar3 = *(uint **)(puVar4 + 0x18);
  (*DAT_140016440)(param_1,0x10000001,0x516e695f,param_2,puVar1,puVar4);
  puVar1[0x14] = *(uint *)(param_2 + 0x6c);
  puVar1[0x15] = (uint)*(byte *)(param_2 + 0x2e);
  if ((puVar4[0x13] & 4) == 0) goto LAB_14000c84c;
  if ((puVar3 == (uint *)0x0) || (puVar2 = puVar3, (puVar3[0x13] & 4) != 0)) {
    (*DAT_140016440)(param_1,0x10000001,0x3171695f,puVar4,0,puVar3);
  }
  else {
    do {
      puVar3 = puVar2;
      if (((puVar2[0x13] & 4) != 0) || (puVar1[0x14] <= puVar2[0x14])) break;
      puVar3 = *(uint **)(puVar2 + 0x18);
      puVar4 = puVar2;
LAB_14000c84c:
      puVar2 = puVar3;
    } while (puVar3 != (uint *)0x0);
  }
  *(uint **)(puVar1 + 0x18) = puVar3;
  *(uint **)(puVar1 + 0x1a) = puVar4;
  if ((puVar3 != (uint *)0x0) && ((puVar3[0x13] & 4) == 0)) {
    *(uint **)(puVar3 + 0x1a) = puVar1;
  }
  *(uint **)(puVar4 + 0x18) = puVar1;
  *puVar1 = *puVar4;
  *puVar4 = puVar1[0x11] & 0xffffffe3 | 2;
  if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
    puVar1[0x13] = puVar1[0x13] | 1;
    LOCK();
    UNLOCK();
  }
  else {
    LOCK();
    puVar1[0x13] = puVar1[0x13] | 1;
    UNLOCK();
  }
  *(undefined8 *)(param_2 + 0x88) = 0;
  *(undefined4 *)(param_2 + 0x84) = 1;
  return;
}



===== EHCI_RebalanceInterruptEndpoint @ 14000c8d4 =====

void EHCI_RebalanceInterruptEndpoint(longlong param_1,undefined8 *param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  
  uVar2 = param_2[1];
  lVar1 = *(longlong *)(param_3 + 0x78);
  *(undefined8 *)(param_3 + 0x28) = *param_2;
  *(undefined8 *)(param_3 + 0x30) = uVar2;
  uVar2 = param_2[3];
  *(undefined8 *)(param_3 + 0x38) = param_2[2];
  *(undefined8 *)(param_3 + 0x40) = uVar2;
  uVar2 = param_2[5];
  *(undefined8 *)(param_3 + 0x48) = param_2[4];
  *(undefined8 *)(param_3 + 0x50) = uVar2;
  uVar2 = param_2[7];
  *(undefined8 *)(param_3 + 0x58) = param_2[6];
  *(undefined8 *)(param_3 + 0x60) = uVar2;
  *(undefined8 *)(param_3 + 0x68) = param_2[8];
  uVar5 = *(uint *)(lVar1 + 0x4c) & 1;
  if (*(uint *)(lVar1 + 0x54) == (uint)*(byte *)((longlong)param_2 + 6)) {
    if (uVar5 != 0) {
      EHCI_RemoveQueueHeadFromPeriodicList(param_1,param_3);
    }
    EHCI_WaitFrames(param_1);
    *(uint *)(lVar1 + 0x18) = *(uint *)(lVar1 + 0x18) & 0xfffff3fd;
    *(uint *)(lVar1 + 0x20) = *(uint *)(lVar1 + 0x20) & 0xffffff00;
    *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) & 0xfffff01f;
    *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) & 0xffffffe0;
  }
  else {
    if (uVar5 != 0) {
      EHCI_RemoveQueueHeadFromPeriodicList(param_1,param_3);
    }
    EHCI_WaitFrames(param_1);
    *(uint *)(lVar1 + 0x18) = *(uint *)(lVar1 + 0x18) & 0xfffff3fd;
    *(uint *)(lVar1 + 0x20) = *(uint *)(lVar1 + 0x20) & 0xffffff00;
    *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) & 0xfffff01f;
    *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) & 0xffffffe0;
    bVar4 = *(byte *)((longlong)param_2 + 6);
    for (uVar3 = 0; ((bVar4 & 1) == 0 && ((uint)uVar3 < 7)); uVar3 = (ulonglong)((uint)uVar3 + 1)) {
      bVar4 = bVar4 >> 1;
    }
    uVar2 = *(undefined8 *)
             (param_1 + 400 +
             (ulonglong)((uint)(byte)(&ClassicPeriodIdx)[uVar3] + *(int *)(param_2 + 2)) * 8);
    *(undefined8 *)(param_3 + 0xb0) = 0;
    *(undefined8 *)(param_3 + 0xa8) = uVar2;
    *(uint *)(lVar1 + 0x54) = (uint)*(byte *)((longlong)param_2 + 6);
  }
  *(undefined1 *)(lVar1 + 8) = *(undefined1 *)((longlong)param_2 + 0x3c);
  *(undefined1 *)(lVar1 + 9) = *(undefined1 *)((longlong)param_2 + 0x3d);
  if (uVar5 != 0) {
    EHCI_InsertQueueHeadInPeriodicList(param_1,param_3);
  }
  return;
}



===== EHCI_EndSendOnePacket @ 14000ca40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
EHCI_EndSendOnePacket
          (longlong param_1,undefined8 param_2,void *param_3,uint *param_4,undefined8 param_5,
          undefined8 param_6,undefined8 param_7,int *param_8)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  void *_Src;
  longlong *plVar4;
  int *piVar5;
  uint uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined1 local_res20 [8];
  
  local_res20[0] = 0;
  (*DAT_140016440)(param_1,0x10000001,0x4573735f,0,0,0);
  plVar4 = (longlong *)CONCAT71(param_5._1_7_,(undefined1)param_5);
  lVar2 = *plVar4;
  lVar3 = plVar4[1];
  _Src = (void *)plVar4[2];
  (*DAT_140016440)(param_1,0x10000001,0x3245735f,lVar2,lVar3,*param_4);
  piVar5 = param_8;
  if (((*(uint *)(lVar2 + 4) & 0xf00) == 0) && (*param_8 == 0)) {
    if (((byte)*(undefined4 *)(lVar3 + 8) & 0xf8) != 0x80) {
LAB_14000cafd:
      EHCI_RemoveQueueHeadFromAsyncList(param_1,lVar2);
      param_5._0_1_ = 0;
      EHCI_AcquireAsyncDoorbellLock(param_1,(undefined1 *)&param_5);
      EHCI_iDisableAsyncList(param_1);
      *(undefined8 *)(param_1 + 0x118) = 0;
      KeReleaseSpinLock(param_1 + 0x110,(undefined1)param_5);
      goto LAB_14000cb4e;
    }
LAB_14000caef:
    uVar7 = 1;
  }
  else {
    if (*param_8 != -0x3fff0000) goto LAB_14000cafd;
LAB_14000cb4e:
    uVar1 = *(uint *)(lVar2 + 0x18);
    if ((char)uVar1 < '\0') {
      if (*piVar5 != -0x3fff0000) {
        *piVar5 = -0x3fff0000;
        goto LAB_14000caef;
      }
    }
    else if ((uVar1 & 0x40) == 0) {
      *piVar5 = 0;
    }
    else if ((uVar1 & 8) == 0) {
      if ((uVar1 & 0x10) == 0) {
        if ((uVar1 & 0x20) == 0) {
          if ((uVar1 & 4) != 0) goto LAB_14000cb8e;
          *piVar5 = -0x3ffffffc;
        }
        else {
          *piVar5 = -0x3fffffed;
        }
      }
      else {
        *piVar5 = -0x3fffffee;
      }
    }
    else {
LAB_14000cb8e:
      *piVar5 = -0x3fffffef;
    }
    uVar8 = uVar1 >> 0x10 & 0x7fff;
    uVar6 = *param_4 - uVar8;
    if (*param_4 < uVar8) {
      uVar6 = 0;
    }
    *param_4 = uVar6;
    (*DAT_140016440)(param_1,0x10000001,0x3345735f,uVar1 >> 0x10 & 0x7fff,lVar3,uVar6);
    if ((uVar1 & 0x300) == 0x100) {
      memmove(param_3,_Src,(ulonglong)*param_4);
    }
    EHCI_AcquireAsyncDoorbellLock(param_1,local_res20);
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(undefined8 *)(param_1 + 0x118) = 0;
    KeReleaseSpinLock(param_1 + 0x110,local_res20[0]);
    uVar7 = 0;
  }
  return uVar7;
}



===== EHCI_StartSendOnePacket @ 14000cc60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
EHCI_StartSendOnePacket
          (longlong param_1,byte *param_2,void *param_3,uint *param_4,undefined8 *param_5,
          int param_6,int param_7,undefined4 *param_8)

{
  uint *_Dst;
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 *_Dst_00;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  (*DAT_140016440)(param_1,0x10000001,0x5373735f,param_6,0,param_5);
  EHCI_AcquireAsyncDoorbellLock(param_1,local_res8);
  *(undefined4 *)(param_1 + 0x7c) = 1;
  *(undefined8 *)(param_1 + 0x118) = 0;
  KeReleaseSpinLock(param_1 + 0x110,local_res8[0]);
  _Dst = (uint *)(param_5 + 0x20);
  _Dst_00 = param_5 + 0x40;
  (*DAT_140016440)(param_1,0x10000001,0x5173735f,_Dst,0,param_6 + 0x100);
  (*DAT_140016440)(param_1,0x10000001,0x5473735f,_Dst_00,0,param_6 + 0x200);
  (*DAT_140016440)(param_1,0x10000001,0x4473735f,param_3,*param_4,0);
  if (param_7 - 0x300U < *param_4) {
    *param_8 = 0xc0000e00;
    return 6;
  }
  memmove(param_5 + 0x60,param_3,(ulonglong)*param_4);
  memset(_Dst,0,0x80);
  uVar4 = *(uint *)((longlong)param_5 + 0x104) | 0x4000;
  *(uint *)((longlong)param_5 + 0x104) = uVar4;
  *(int *)((longlong)param_5 + 0x144) = param_6 + 0x100;
  param_5[0x2b] = 0;
  uVar5 = *(uint *)(param_5 + 0x21) & 0xffff | 0x40000000;
  *(undefined4 *)(param_5 + 0x29) = 0x71643032;
  uVar4 = (*param_2 ^ uVar4) & 0x7f ^ uVar4;
  *(uint *)((longlong)param_5 + 0x104) = uVar4;
  bVar1 = param_2[1];
  *(uint *)(param_5 + 0x21) = uVar5;
  uVar4 = ((uint)bVar1 << 8 ^ uVar4) & 0xf00 ^ uVar4;
  *(uint *)((longlong)param_5 + 0x104) = uVar4;
  iVar3 = *(int *)(param_2 + 0xc);
  if (iVar3 == 0) {
    uVar4 = uVar4 & 0xffffdfff | 0x1000;
LAB_14000ce80:
    *(uint *)((longlong)param_5 + 0x104) = uVar4;
    uVar5 = (*(ushort *)(param_2 + 0x14) & 0x7f) << 0x10 | uVar5;
    *(uint *)(param_5 + 0x21) = uVar5;
    *(uint *)(param_5 + 0x21) = (*(ushort *)(param_2 + 0x16) & 0x7f) << 0x17 | uVar5;
    if ((*(int *)(param_2 + 8) != 0) && ((uVar4 & 0xf00) != 0)) goto LAB_14000ceb4;
    uVar4 = uVar4 | 0x8000000;
  }
  else {
    if (iVar3 == 1) {
      uVar4 = uVar4 & 0xffffcfff;
      goto LAB_14000ce80;
    }
    if (iVar3 != 2) {
      (*DAT_140016470)(param_1);
      goto LAB_14000ceb4;
    }
    uVar4 = uVar4 & 0xffffefff | 0x2000;
  }
  *(uint *)((longlong)param_5 + 0x104) = uVar4;
LAB_14000ceb4:
  *(uint *)((longlong)param_5 + 0x104) =
       ((uint)*(ushort *)(param_2 + 2) << 0x10 ^ *(uint *)((longlong)param_5 + 0x104)) & 0x7ff0000 ^
       *(uint *)((longlong)param_5 + 0x104);
  memset(_Dst_00,0,0x80);
  uVar4 = 0;
  *(undefined8 *)((longlong)param_5 + 0x20c) = 0xbadf0000badf000;
  *(undefined8 *)((longlong)param_5 + 0x214) = 0xbadf0000badf000;
  *(undefined4 *)((longlong)param_5 + 0x21c) = 0xbadf000;
  *(int *)(param_5 + 0x48) = param_6 + 0x200;
  *(undefined4 *)((longlong)param_5 + 0x234) = 0x64743032;
  iVar3 = *(int *)(param_2 + 8);
  if (iVar3 == 0) {
    (*DAT_140016440)(param_1,0x10000001,0x5553735f,0,0,0);
    uVar4 = 0x200;
  }
  else if (iVar3 == 1) {
    (*DAT_140016440)(param_1,0x10000001,0x4973735f,0,0,0);
    uVar4 = 0x100;
  }
  else if (iVar3 == 2) {
    (*DAT_140016440)(param_1,0x10000001,0x4f73735f,0,0,0);
  }
  if ((*(int *)(param_2 + 0x10) != 0) && (*(int *)(param_2 + 0x10) == 1)) {
    uVar4 = uVar4 | 0x80000000;
  }
  uVar2 = *(ushort *)(param_2 + 4);
  *(int *)((longlong)param_5 + 0x20c) = param_6 + 0x300;
  *(uint *)(param_5 + 0x41) = uVar4 | ((*param_4 & 0x7fff) << 6 | uVar2 & 3) << 10 | 0x80;
  *(undefined4 *)(param_5 + 0x22) = *(undefined4 *)(param_5 + 0x48);
  *(undefined4 *)_Dst_00 = 1;
  *(undefined4 *)((longlong)param_5 + 0x204) = 1;
  param_5[2] = param_5 + 0x60;
  *param_5 = _Dst;
  param_5[1] = _Dst_00;
  *param_8 = 0;
  EHCI_InsertQueueHeadInAsyncList(param_1,_Dst);
  EHCI_EnableAsyncList(param_1);
  return 0;
}



===== EHCI_AbortControlTransfer @ 14000d040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_AbortControlTransfer(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong lVar10;
  
  lVar3 = *(longlong *)(param_2 + 0x78);
  (*DAT_140016440)(param_1,0x10000001,0x7262615f,lVar3,param_3,*(undefined8 *)(param_2 + 0x130));
  uVar8 = (*DAT_140016448)(*(uint *)(lVar3 + 0xc) & 0xffffffe0,param_1,param_2);
  lVar4 = *(longlong *)(param_2 + 0x138);
  lVar5 = *(longlong *)(param_2 + 0x130);
  (*DAT_140016440)(param_1,0x10000001,0x3170612b,lVar4,lVar5,uVar8);
  lVar10 = param_2 + 0x108;
  plVar6 = *(longlong **)(param_2 + 0x110);
  plVar1 = (longlong *)(lVar5 + 0x70);
  if (*plVar6 == lVar10) {
    *plVar1 = lVar10;
    *(longlong **)(lVar5 + 0x78) = plVar6;
    *plVar6 = (longlong)plVar1;
    *(longlong **)(param_2 + 0x110) = plVar1;
    if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
      *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) | 0x80;
      LOCK();
      UNLOCK();
    }
    else {
      LOCK();
      *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) | 0x80;
      UNLOCK();
    }
    *(uint *)(lVar5 + 8) = *(uint *)(lVar5 + 8) & 0xffffff7f;
    plVar1 = (longlong *)(lVar4 + 0x70);
    plVar6 = *(longlong **)(param_2 + 0x110);
    if (*plVar6 == lVar10) {
      *plVar1 = lVar10;
      *(longlong **)(lVar4 + 0x78) = plVar6;
      *plVar6 = (longlong)plVar1;
      *(longlong **)(param_2 + 0x110) = plVar1;
      if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
        *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) | 0x80;
        LOCK();
        UNLOCK();
      }
      else {
        LOCK();
        *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) | 0x80;
        UNLOCK();
      }
      *(uint *)(lVar4 + 8) = *(uint *)(lVar4 + 8) & 0xffffff7f;
      lVar10 = *(longlong *)(lVar5 + 0x58);
      (*DAT_140016440)(param_1,0x10000001,0x3370615f,lVar10,0,uVar8);
      if (lVar10 != lVar4) {
        do {
          (*DAT_140016440)(param_1,0x10000001,0x3174615f,lVar10,0,*(undefined8 *)(lVar10 + 0x50));
          if ((*(uint *)(lVar10 + 8) & 0x80) == 0) {
LAB_14000d24e:
            if (param_1 != 0) goto LAB_14000d253;
code_r0x00014000d261:
            *(uint *)(lVar10 + 0x38) = *(uint *)(lVar10 + 0x38) | 8;
            LOCK();
            UNLOCK();
          }
          else {
            (*DAT_140016440)(param_1,0x10000001,0x5374615f,lVar10,0,0);
            if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
              *(uint *)(lVar10 + 0x38) = *(uint *)(lVar10 + 0x38) | 0x10;
              LOCK();
              UNLOCK();
              goto LAB_14000d24e;
            }
            LOCK();
            *(uint *)(lVar10 + 0x38) = *(uint *)(lVar10 + 0x38) | 0x10;
            UNLOCK();
LAB_14000d253:
            if (*(char *)(param_1 + 0x5e) != '\0') goto code_r0x00014000d261;
            LOCK();
            *(uint *)(lVar10 + 0x38) = *(uint *)(lVar10 + 0x38) | 8;
            UNLOCK();
          }
          plVar6 = *(longlong **)(param_2 + 0x110);
          plVar1 = (longlong *)(lVar10 + 0x70);
          if (*plVar6 != param_2 + 0x108) goto LAB_14000d371;
          *plVar1 = param_2 + 0x108;
          *(longlong **)(lVar10 + 0x78) = plVar6;
          *plVar6 = (longlong)plVar1;
          *(longlong **)(param_2 + 0x110) = plVar1;
          lVar10 = *(longlong *)(lVar10 + 0x58);
        } while (lVar10 != lVar4);
      }
      plVar1 = (longlong *)(param_2 + 0x108);
      while( true ) {
        plVar6 = (longlong *)*plVar1;
        if (plVar6 == plVar1) {
          *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(lVar4 + 0x40);
          if (*(char *)(param_1 + 0x62) == '\0') {
            *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)(lVar5 + 0x40);
            *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(lVar5 + 0x40);
          }
          uVar2 = *(uint *)(lVar3 + 0x18);
          uVar9 = uVar2 & 0x8000ffff;
          if ((*(uint *)(param_2 + 0x80) & 1) != 0) {
            (*DAT_140016440)(param_1,0x10000001,0x3470685f,lVar3,0,0);
            *(undefined4 *)(param_2 + 0x70) = 0;
            uVar9 = uVar2 & 0x8000ff3f | 0xc00;
          }
          *(uint *)(lVar3 + 0x18) = uVar9;
          return;
        }
        if (((longlong *)plVar6[1] != plVar1) ||
           (lVar10 = *plVar6, (longlong *)*(longlong *)(lVar10 + 8) != plVar6)) break;
        *plVar1 = lVar10;
        *(longlong **)(lVar10 + 8) = plVar1;
        EHCI_ProcessDoneAsyncTd(param_1,plVar6 + -0xe,param_3);
      }
    }
  }
LAB_14000d371:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
}



===== EHCI_AnswerAsyncDoorbell @ 14000d380 =====

void EHCI_AnswerAsyncDoorbell(longlong param_1)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 local_res8 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  local_res8[0] = 0;
  EHCI_AcquireAsyncDoorbellLock(param_1,local_res8);
  *(int *)(param_1 + 0x514) = *(int *)(param_1 + 0x514) + 1;
  plVar1 = *(longlong **)(param_1 + 0x120);
  if (((*(int *)(param_1 + 0x57c) == 0) && (*(int *)(param_1 + 0x578) != 0)) &&
     (*(int *)(param_1 + 0x544) == 0)) {
    *(undefined4 *)(param_1 + 0x57c) = 1;
    EHCI_WriteErrorLogEntry(param_1,0x40010005,'\x01');
  }
  puVar5 = auStack_28;
  *(undefined8 *)(param_1 + 0x120) = 0;
  puVar6 = auStack_28;
  if (plVar1 != (longlong *)0x0) {
    plVar3 = plVar1 + 0x12;
    *(int *)plVar3 = (int)*plVar3 + -1;
    if ((int)*plVar3 == 0) {
      EHCI_UpdateEndpointAsFreedFromHwCache(param_1,(longlong)plVar1);
      puVar6 = auStack_28;
    }
    else {
      plVar3 = (longlong *)(param_1 + 0x100);
      lVar4 = *plVar3;
      if (*(longlong **)(lVar4 + 8) != plVar3) {
        lVar4 = 3;
        pcVar2 = (code *)swi(0x29);
        plVar3 = (longlong *)(*pcVar2)();
        puVar5 = auStack_20;
      }
      *plVar1 = lVar4;
      plVar1[1] = (longlong)plVar3;
      *(longlong **)(lVar4 + 8) = plVar1;
      *plVar3 = (longlong)plVar1;
      puVar6 = puVar5;
    }
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000d433;
  EHCI_SetAsyncDoorbellState(param_1,1);
  if (*(longlong **)(param_1 + 0x100) != (longlong *)(param_1 + 0x100)) {
    *(undefined8 *)(puVar6 + -8) = 0x14000d447;
    EHCI_RingAsyncDoorbell(param_1);
  }
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(puVar6 + -8) = 0x14000d461;
  KeReleaseSpinLock(param_1 + 0x110,puVar6[0x30]);
  return;
}



===== EHCI_DerefAsyncIdle @ 14000d478 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_DerefAsyncIdle(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 *puVar6;
  undefined1 local_res8 [8];
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  longlong *local_20;
  
  local_res8[0] = 0;
  EHCI_AcquireAsyncDoorbellLock(param_1,local_res8);
  plVar1 = (longlong *)(param_1 + 0xb0);
  local_28 = 0;
  local_20 = param_2;
  (*DAT_140016440)(param_1,0x10000001,0x6961645f,plVar1);
  puVar6 = auStack_48;
  if (param_2 != (longlong *)0x0) {
    lVar3 = *param_2;
    if ((*(longlong **)(lVar3 + 8) == param_2) &&
       (plVar4 = (longlong *)param_2[1], (longlong *)*plVar4 == param_2)) {
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      ExFreePoolWithTag(param_2,0);
      puVar6 = auStack_48;
      goto LAB_14000d52b;
    }
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    puVar6 = auStack_40;
  }
  iVar2 = *(int *)(param_1 + 0xc0);
  if (iVar2 == 0) {
    *(undefined8 *)(puVar6 + -8) = 0x14000d52b;
    (*DAT_140016470)(param_1);
  }
  else {
    *(int *)(param_1 + 0xc0) = iVar2 + -1;
  }
LAB_14000d52b:
  if (((longlong *)*plVar1 == plVar1) && (*(int *)(param_1 + 0xc0) == 0)) {
    *(undefined8 *)(puVar6 + -8) = 0x14000d53d;
    EHCI_iDisableAsyncList(param_1);
  }
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(puVar6 + -8) = 0x14000d557;
  KeReleaseSpinLock(param_1 + 0x110,puVar6[0x50]);
  return;
}



===== EHCI_InsertQueueHeadInAsyncList @ 14000d574 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_InsertQueueHeadInAsyncList(longlong param_1,uint *param_2)

{
  longlong lVar1;
  
  (*DAT_140016440)(param_1,0x10000001,0x6e69415f,0,param_2,0);
  lVar1 = *(longlong *)(param_2 + 0x16);
  if (((lVar1 == 0) || (*(char *)(param_1 + 99) == '\0')) || (*(int *)(lVar1 + 0x94) != 0)) {
    EHCI_InsertQueueHeadInHWAsyncList(param_1,param_2);
  }
  if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
    param_2[0x13] = param_2[0x13] | 1;
    LOCK();
    UNLOCK();
  }
  else {
    LOCK();
    param_2[0x13] = param_2[0x13] | 1;
    UNLOCK();
  }
  if (lVar1 != 0) {
    *(undefined8 *)(lVar1 + 0x88) = 0;
    *(undefined4 *)(lVar1 + 0x84) = 1;
  }
  return;
}



===== EHCI_PokeAsyncEndpoint @ 14000d620 =====

undefined8 EHCI_PokeAsyncEndpoint(undefined8 param_1,undefined8 *param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  
  uVar2 = param_2[1];
  lVar1 = *(longlong *)(param_3 + 0x78);
  *(undefined8 *)(param_3 + 0x28) = *param_2;
  *(undefined8 *)(param_3 + 0x30) = uVar2;
  uVar2 = param_2[3];
  *(undefined8 *)(param_3 + 0x38) = param_2[2];
  *(undefined8 *)(param_3 + 0x40) = uVar2;
  uVar2 = param_2[5];
  *(undefined8 *)(param_3 + 0x48) = param_2[4];
  *(undefined8 *)(param_3 + 0x50) = uVar2;
  uVar2 = param_2[7];
  *(undefined8 *)(param_3 + 0x58) = param_2[6];
  *(undefined8 *)(param_3 + 0x60) = uVar2;
  *(undefined8 *)(param_3 + 0x68) = param_2[8];
  uVar3 = ((uint)*(ushort *)(param_3 + 0x28) ^ *(uint *)(lVar1 + 4)) & 0x7f ^ *(uint *)(lVar1 + 4);
  *(uint *)(lVar1 + 4) = uVar3;
  *(uint *)(lVar1 + 4) = ((uint)*(ushort *)(param_3 + 0x2c) << 0x10 ^ uVar3) & 0x7ff0000 ^ uVar3;
  if (*(int *)(param_3 + 0x30) == 2) {
    uVar3 = *(uint *)(lVar1 + 8) & 0xc000ffff;
  }
  else {
    uVar3 = ((uint)*(ushort *)(param_3 + 0x60) << 0x10 ^ *(uint *)(lVar1 + 8)) & 0x7f0000 ^
            *(uint *)(lVar1 + 8);
  }
  *(uint *)(lVar1 + 8) = uVar3;
  return 0;
}



===== EHCI_PollHaltedControlEndpoint @ 14000d6b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_PollHaltedControlEndpoint(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong lVar10;
  
  lVar3 = *(longlong *)(param_2 + 0x78);
  uVar8 = (*DAT_140016448)(*(uint *)(lVar3 + 0xc) & 0xffffffe0,param_1,param_2);
  lVar4 = *(longlong *)(param_2 + 0x138);
  lVar5 = *(longlong *)(param_2 + 0x130);
  (*DAT_140016440)(param_1,0x10000001,0x3170685f,lVar4,lVar5,uVar8);
  lVar10 = param_2 + 0x108;
  plVar6 = *(longlong **)(param_2 + 0x110);
  plVar1 = (longlong *)(lVar5 + 0x70);
  if (*plVar6 == lVar10) {
    *plVar1 = lVar10;
    *(longlong **)(lVar5 + 0x78) = plVar6;
    *plVar6 = (longlong)plVar1;
    *(longlong **)(param_2 + 0x110) = plVar1;
    if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
      *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) | 0x80;
      LOCK();
      UNLOCK();
    }
    else {
      LOCK();
      *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) | 0x80;
      UNLOCK();
    }
    *(uint *)(lVar5 + 8) = *(uint *)(lVar5 + 8) & 0xffffff7f;
    plVar1 = (longlong *)(lVar4 + 0x70);
    plVar6 = *(longlong **)(param_2 + 0x110);
    if (*plVar6 == lVar10) {
      *plVar1 = lVar10;
      *(longlong **)(lVar4 + 0x78) = plVar6;
      *plVar6 = (longlong)plVar1;
      *(longlong **)(param_2 + 0x110) = plVar1;
      if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
        *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) | 0x80;
        LOCK();
        UNLOCK();
      }
      else {
        LOCK();
        *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) | 0x80;
        UNLOCK();
      }
      *(uint *)(lVar4 + 8) = *(uint *)(lVar4 + 8) & 0xffffff7f;
      lVar10 = *(longlong *)(lVar5 + 0x58);
      (*DAT_140016440)(param_1,0x10000001,0x3370685f,lVar10,0,uVar8);
      if (lVar10 != lVar4) {
        do {
          (*DAT_140016440)(param_1,0x10000001,0x3174685f,lVar10,0,*(undefined8 *)(lVar10 + 0x50));
          if ((char)*(undefined4 *)(lVar10 + 8) < '\0') {
            (*DAT_140016440)(param_1,0x10000001,0x5374685f,lVar10,0,0);
            if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
              *(uint *)(lVar10 + 0x38) = *(uint *)(lVar10 + 0x38) | 0x10;
              LOCK();
              UNLOCK();
              goto LAB_14000d892;
            }
            LOCK();
            *(uint *)(lVar10 + 0x38) = *(uint *)(lVar10 + 0x38) | 0x10;
            UNLOCK();
LAB_14000d897:
            if (*(char *)(param_1 + 0x5e) != '\0') goto code_r0x00014000d8a5;
            LOCK();
            *(uint *)(lVar10 + 0x38) = *(uint *)(lVar10 + 0x38) | 8;
            UNLOCK();
          }
          else {
LAB_14000d892:
            if (param_1 != 0) goto LAB_14000d897;
code_r0x00014000d8a5:
            *(uint *)(lVar10 + 0x38) = *(uint *)(lVar10 + 0x38) | 8;
            LOCK();
            UNLOCK();
          }
          plVar6 = *(longlong **)(param_2 + 0x110);
          plVar1 = (longlong *)(lVar10 + 0x70);
          if (*plVar6 != param_2 + 0x108) goto LAB_14000d969;
          *plVar1 = param_2 + 0x108;
          *(longlong **)(lVar10 + 0x78) = plVar6;
          *plVar6 = (longlong)plVar1;
          *(longlong **)(param_2 + 0x110) = plVar1;
          lVar10 = *(longlong *)(lVar10 + 0x58);
        } while (lVar10 != lVar4);
      }
      *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(lVar4 + 0x40);
      *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)(lVar5 + 0x40);
      *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(lVar5 + 0x40);
      uVar2 = *(uint *)(lVar3 + 0x18);
      uVar9 = uVar2 & 0x8000ffff;
      if ((*(uint *)(param_2 + 0x80) & 1) != 0) {
        (*DAT_140016440)(param_1,0x10000001,0x3470685f,lVar3,0,0);
        *(undefined4 *)(param_2 + 0x70) = 0;
        uVar9 = uVar2 & 0x8000ff3f | 0xc00;
      }
      *(uint *)(lVar3 + 0x18) = uVar9;
      return;
    }
  }
LAB_14000d969:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
}



===== EHCI_RemoveQueueHeadFromAsyncList @ 14000d978 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_RemoveQueueHeadFromAsyncList(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 local_res10 [8];
  
  local_res10[0] = 0;
  (*DAT_140016440)(param_1,0x10000001,0x416d725f,param_2,0,0);
  if ((*(uint *)(param_2 + 0x4c) & 1) == 0) {
    (*DAT_140016440)(param_1,0x10000001,0x3141725f,param_2,0,0);
  }
  else {
    plVar1 = *(longlong **)(param_2 + 0x58);
    lVar2 = param_1;
    EHCI_RemoveQueueHeadFromHWAsyncList(param_1,param_2);
    if ((param_1 == 0) || (*(char *)(param_1 + 0x5e) != '\0')) {
      *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xfffffffe;
      LOCK();
      UNLOCK();
    }
    else {
      LOCK();
      *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xfffffffe;
      UNLOCK();
    }
    if (plVar1 != (longlong *)0x0) {
      EHCI_AcquireAsyncDoorbellLock(lVar2,local_res10);
      EHCI_iAsyncCacheFlush(param_1,plVar1,'\0');
      *(undefined8 *)(param_1 + 0x118) = 0;
      KeReleaseSpinLock(param_1 + 0x110,local_res10[0]);
    }
  }
  return;
}



===== DriverEntry @ 14000da68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined1 local_134 [284];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  memset(local_134,0,0x110);
  local_138 = 0x114;
  RtlGetVersion(&local_138);
  wil_InitializeFeatureStaging();
  iVar1 = USBPORT_GetHciMn();
  if (iVar1 == 0x10000001) {
    _DAT_140016270 = 0x658;
    _DAT_140016650 = EHCI_PreStartController;
    _DAT_1400162a8 = EHCI_StartController;
    _DAT_1400162b0 = EHCI_StopController;
    _DAT_1400162b8 = EHCI_SuspendController;
    _DAT_1400162c0 = EHCI_ResumeController;
    _DAT_140016320 = EHCI_EnableInterrupts;
    _DAT_140016328 = EHCI_DisableInterrupts;
    _DAT_1400162c8 = EHCI_InterruptService;
    _DAT_140016350 = EHCI_ResetController;
    _DAT_140016628 = EHCI_ResetControllerDontReinit;
    _DAT_140016638 = EHCI_ReinitController;
    _DAT_140016630 = EHCI_PostResetController;
    _DAT_1400163d8 = EHCI_RH_DisableIrq;
    _DAT_1400163e0 = EHCI_RH_EnableIrq;
    _DAT_140016358 = EHCI_RH_GetRootHubData;
    _DAT_140016360 = EHCI_RH_GetStatus;
    _DAT_140016370 = EHCI_RH_GetHubStatus;
    _DAT_140016368 = EHCI_RH_GetPortStatus;
    _DAT_140016378 = EHCI_RH_SetFeaturePortReset;
    _DAT_140016380 = EHCI_RH_SetFeaturePortPower;
    _DAT_140016388 = EHCIDumpCleanUpInterface;
    _DAT_140016390 = EHCI_RH_SetFeaturePortSuspend;
    _DAT_140016398 = EHCI_RH_ClearFeaturePortEnable;
    _DAT_1400163a0 = EHCI_RH_ClearFeaturePortPower;
    _DAT_1400163a8 = EHCI_RH_ClearFeaturePortSuspend;
    _DAT_1400163b0 = EHCI_RH_ClearFeaturePortEnableChange;
    _DAT_1400163b8 = EHCI_RH_ClearFeaturePortConnectChange;
    _DAT_1400163c0 = EHCI_RH_ClearFeaturePortResetChange;
    _DAT_1400163c8 = EHCI_RH_ClearFeaturePortSuspendChange;
    _DAT_1400163d0 = EHCI_RH_ClearFeaturePortOvercurrentChange;
    _DAT_140016348 = EHCI_SetEndpointStatus;
    _DAT_140016340 = EHCI_GetEndpointStatus;
    _DAT_140016338 = EHCI_SetEndpointDataToggle;
    _DAT_140016288 = EHCI_OpenEndpoint;
    _DAT_140016290 = EHCI_PokeEndpoint;
    _DAT_140016298 = EHCI_QueryEndpointRequirements;
    _DAT_1400162a0 = EHCI_CloseEndpoint;
    _DAT_140016274 = 0x3c0;
    _DAT_140016278 = 0x60;
    DAT_140016284 = 0x4000;
    _DAT_1400164b0 = 1;
    DAT_1400164b4 = 0x20000;
    _DAT_140016300 = EHCI_PollEndpoint;
    _DAT_14001627c = 0x45425355;
    _DAT_1400162f8 = EHCI_SetEndpointState;
    _DAT_140016280 = 0x494348;
    _DAT_1400162f0 = EHCI_GetEndpointState;
    _DAT_140016264 = 0x180a95;
    _DAT_140016310 = EHCI_Get32BitFrameNumber;
    _RegistrationPacket = 3;
    _DAT_140016330 = EHCI_PollController;
    _DAT_140016308 = EHCI_CheckController;
    _DAT_140016318 = EHCI_InterruptNextSOF;
    _DAT_1400162d8 = EHCI_SubmitTransfer;
    _DAT_1400162d0 = EHCI_InterruptDpc;
    _DAT_1400162e8 = EHCI_AbortTransfer;
    _DAT_1400163e8 = EHCI_StartSendOnePacket;
    _DAT_1400163f0 = EHCI_EndSendOnePacket;
    _DAT_1400163f8 = EHCI_PassThru;
    _DAT_1400162e0 = EHCI_SubmitIsoTransfer;
    _DAT_140016480 = EHCI_RebalanceEndpoint;
    _DAT_140016488 = EHCI_FlushInterrupts;
    _DAT_140016490 = EHCI_RH_ChirpRootPort;
    _DAT_140016498 = EHCI_TakePortControl;
    _DAT_1400164e0 = EHCI_ReleasePortControl;
    _DAT_1400164e8 = EHCI_ReadConfigFlag;
    _DAT_1400164f0 = EHCI_RH_SetWakeConnect;
    _DAT_1400164f8 = EHCI_InterruptDpcEx;
    _DAT_140016500 = EHCI_NotifyTransferQueueState;
    _DAT_140016508 = EHCI_CheckHwSync;
    _DAT_140016590 = EHCI_CreateDeviceData;
    _DAT_140016598 = _guard_check_icall;
    _DAT_1400165a0 = EHCI_DbgFreeEndpoint;
    _DAT_1400165b8 = EHCI_HaltController;
    _DAT_1400165f8 = EHCI_GetHcCapabilities;
    _DAT_140016600 = EHCIDumpInitializeInterface;
    _DAT_140016608 = EHCIDumpCleanUpInterface;
    _DAT_140016610 = EHCI_GetDebugPortNumber;
    _DAT_140016640 = EHCI_CheckInvalidateRootHub;
    _DAT_140016648 = EHCI_SetPortResumeTime;
    _DAT_140016268 = 400000;
    *(code **)(param_1 + 0x68) = EHCI_Unload;
    iVar1 = USBPORT_RegisterUSBPortDriver(param_1,500,&RegistrationPacket,param_2);
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  else {
    iVar1 = -0x3fffffff;
  }
  wil_UninitializeFeatureStaging();
  return iVar1;
}



===== EHCI_Unload @ 14000df90 =====

void EHCI_Unload(void)

{
  wil_UninitializeFeatureStaging();
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 14000dfa8 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140015bdf < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 14000dfd0 =====

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



===== wil_details_RecordFeatureUsageReporting @ 14000e130 =====

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



===== EHCI_DisableInterrupts @ 14000e1c0 =====

void EHCI_DisableInterrupts(longlong param_1)

{
  if (*(longlong *)(param_1 + 200) != 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 200) + 8) = 0;
    LOCK();
    UNLOCK();
  }
  return;
}



===== EHCI_EnableInterrupts @ 14000e1e0 =====

void EHCI_EnableInterrupts(longlong param_1)

{
  if (*(longlong *)(param_1 + 200) != 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 200) + 8) = *(undefined4 *)(param_1 + 0xe8);
    LOCK();
    UNLOCK();
  }
  return;
}



===== EHCI_FlushInterrupts @ 14000e210 =====

void EHCI_FlushInterrupts(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 200);
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 4) = *(undefined4 *)(lVar1 + 4);
    LOCK();
    UNLOCK();
  }
  return;
}



===== EHCI_InterruptDpc @ 14000e230 =====

void EHCI_InterruptDpc(longlong param_1,char param_2)

{
  EHCI_InterruptDpcEx(param_1,param_2);
  return;
}



===== EHCI_InterruptDpcSyncRoutine @ 14000e250 =====

ulonglong EHCI_InterruptDpcSyncRoutine(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong in_RAX;
  
  lVar2 = *(longlong *)(param_1 + 200);
  if (lVar2 != 0) {
    uVar1 = *(uint *)(lVar2 + 8);
    in_RAX = (ulonglong)uVar1;
    if ((*(uint *)(lVar2 + 4) & uVar1 & 0x20) != 0) {
      LOCK();
      *(uint *)(param_1 + 0x14c) = *(uint *)(param_1 + 0x14c) | 0x20;
      UNLOCK();
      *(undefined4 *)(lVar2 + 4) = 0x20;
      LOCK();
      UNLOCK();
      return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== EHCI_CheckInvalidateRootHub @ 14000e290 =====

undefined1 EHCI_CheckInvalidateRootHub(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = *(undefined1 *)(param_1 + 0x651);
  *(undefined1 *)(param_1 + 0x651) = 0;
  return uVar1;
}



===== EHCI_GetDebugPortNumber @ 14000e2b0 =====

undefined2 EHCI_GetDebugPortNumber(longlong param_1)

{
  return *(undefined2 *)(param_1 + 0x3ea);
}



===== EHCI_QualcommClearUlpiReset @ 14000e2c0 =====

void EHCI_QualcommClearUlpiReset(longlong param_1)

{
  uint uVar1;
  
  uVar1 = EHCI_ReadQcHsicDbg1Register(param_1);
  EHCI_WriteQcHsicDbg1Register(param_1,(byte)uVar1 & 0xef);
  return;
}



===== EHCI_RH_ClearFeaturePortConnectChange @ 14000e2f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_RH_ClearFeaturePortConnectChange(longlong param_1,ushort param_2)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 200);
  if ((lVar2 != 0) && (param_2 != *(ushort *)(param_1 + 1000))) {
    uVar1 = *(uint *)(lVar2 + 0x40 + (ulonglong)param_2 * 4);
    (*DAT_140016440)(param_1,0x10000001,0x6363705f,uVar1,0,param_2);
    if ((uVar1 & 2) != 0) {
      *(uint *)(lVar2 + 0x40 + (ulonglong)param_2 * 4) = uVar1 & 0xffffffd7 | 2;
      LOCK();
      UNLOCK();
    }
    *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) & ~(1 << ((char)param_2 - 1U & 0x1f));
  }
  return 0;
}



===== EHCI_RH_ClearFeaturePortEnable @ 14000e3b0 =====

undefined8 EHCI_RH_ClearFeaturePortEnable(longlong param_1,ushort param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 200);
  if ((lVar1 != 0) && (param_2 != *(ushort *)(param_1 + 1000))) {
    *(uint *)(lVar1 + 0x40 + (ulonglong)param_2 * 4) =
         *(uint *)(lVar1 + 0x40 + (ulonglong)param_2 * 4) & 0xffffffd1;
    LOCK();
    UNLOCK();
  }
  return 0;
}



===== EHCI_RH_ClearFeaturePortEnableChange @ 14000e3f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_RH_ClearFeaturePortEnableChange(longlong param_1,ushort param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 200);
  if ((lVar1 != 0) && (param_2 != *(ushort *)(param_1 + 1000))) {
    (*DAT_140016440)(param_1,0x10000001,0x6570635f,param_2,0,0);
    *(uint *)(lVar1 + 0x40 + (ulonglong)param_2 * 4) =
         *(uint *)(lVar1 + 0x40 + (ulonglong)param_2 * 4) & 0xffffffdd | 8;
    LOCK();
    UNLOCK();
  }
  return 0;
}



===== EHCI_RH_ClearFeaturePortOvercurrentChange @ 14000e460 =====

undefined8 EHCI_RH_ClearFeaturePortOvercurrentChange(longlong param_1,ushort param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 200);
  if ((lVar1 != 0) && (param_2 != *(ushort *)(param_1 + 1000))) {
    *(uint *)(lVar1 + 0x40 + (ulonglong)param_2 * 4) =
         *(uint *)(lVar1 + 0x40 + (ulonglong)param_2 * 4) & 0xfffffff5 | 0x20;
    LOCK();
    UNLOCK();
  }
  return 0;
}



===== EHCI_RH_ClearFeaturePortPower @ 14000e4a0 =====

undefined8 EHCI_RH_ClearFeaturePortPower(longlong param_1,ushort param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 200);
  if ((lVar1 != 0) && (param_2 != *(ushort *)(param_1 + 1000))) {
    *(uint *)(lVar1 + 0x40 + (ulonglong)param_2 * 4) =
         *(uint *)(lVar1 + 0x40 + (ulonglong)param_2 * 4) & 0xffffefff;
    LOCK();
    UNLOCK();
  }
  return 0;
}



===== EHCI_RH_ClearFeaturePortResetChange @ 14000e4e0 =====

undefined8 EHCI_RH_ClearFeaturePortResetChange(longlong param_1,short param_2)

{
  if (param_2 != *(short *)(param_1 + 1000)) {
    *(uint *)(param_1 + 0x134) = *(uint *)(param_1 + 0x134) & ~(1 << ((char)param_2 - 1U & 0x1f));
  }
  return 0;
}



===== EHCI_RH_ClearFeaturePortSuspendChange @ 14000e510 =====

undefined8 EHCI_RH_ClearFeaturePortSuspendChange(longlong param_1,short param_2)

{
  if (param_2 != *(short *)(param_1 + 1000)) {
    *(uint *)(param_1 + 0x138) = *(uint *)(param_1 + 0x138) & ~(1 << ((char)param_2 - 1U & 0x1f));
  }
  return 0;
}



===== EHCI_RH_FinishReset @ 14000e540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_RH_FinishReset(longlong param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  
  lVar3 = *(longlong *)(param_1 + 200);
  if (lVar3 != 0) {
    uVar1 = *param_2;
    uVar5 = (ulonglong)uVar1;
    uVar4 = (uint)uVar1;
    (*DAT_140016440)(param_1,0x10000001,0x726e665f,uVar4,param_2,0);
    if (uVar1 < 0x10) {
      *(undefined8 *)(param_1 + 1000 + uVar5 * 8) = 0;
      *(undefined8 *)(param_1 + 0x460 + uVar5 * 8) = 0;
      iVar2 = *(int *)(lVar3 + 0x40 + uVar5 * 4);
      if (iVar2 != -1) {
        if ((((byte)iVar2 & 7) == 1) && (*(char *)(param_1 + 0x5d) != '\0')) {
          *(uint *)(lVar3 + 0x40 + (ulonglong)uVar4 * 4) =
               *(uint *)(lVar3 + 0x40 + (ulonglong)uVar4 * 4) | 0x2000;
          LOCK();
          UNLOCK();
        }
        uVar4 = 1 << ((char)uVar1 - 1U & 0x1f);
        *(uint *)(param_1 + 0x134) = *(uint *)(param_1 + 0x134) | uVar4;
        (*DAT_140016420)(param_1);
        *(uint *)(param_1 + 0x140) = *(uint *)(param_1 + 0x140) & ~uVar4;
      }
    }
    if (*(longlong **)(param_2 + 4) != (longlong *)0x0) {
      EHCI_DerefAsyncIdle(param_1,*(longlong **)(param_2 + 4));
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[6] = 0;
      param_2[7] = 0;
    }
  }
  return;
}



===== EHCI_RH_GetRootHubData @ 14000e640 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_RH_GetRootHubData(longlong param_1,uint *param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *(ushort *)(param_1 + 0x150);
  *param_2 = (uint)uVar1;
  if (*(short *)(param_1 + 0x152) == 1) {
    uVar2 = (ushort)param_2[1] & 0xfffd | 1;
  }
  else {
    uVar2 = 0;
  }
  param_2[2] = 2;
  param_2[3] = 0;
  *(ushort *)(param_2 + 1) = uVar2 & 3;
  *(undefined2 *)((longlong)param_2 + 6) = 0;
  (*DAT_140016440)(param_1,0x10000001,0x6275685f,uVar1,*(undefined2 *)(param_1 + 0x152),0);
  return;
}



===== EHCI_RH_GetStatus @ 14000e6d0 =====

undefined8 EHCI_RH_GetStatus(undefined8 param_1,undefined2 *param_2)

{
  *param_2 = 1;
  return 0;
}



===== EHCIDumpCleanUpInterface @ 14000e6e0 =====

undefined8 EHCIDumpCleanUpInterface(void)

{
  return 0;
}



===== EHCI_RH_SetFeaturePortPower @ 14000e6f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_RH_SetFeaturePortPower(longlong param_1,ushort param_2)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 200);
  if ((lVar2 != 0) && (param_2 != *(ushort *)(param_1 + 1000))) {
    uVar1 = *(uint *)(lVar2 + 0x40 + (ulonglong)param_2 * 4);
    (*DAT_140016440)(param_1,0x10000001,0x7070735f,uVar1,0,param_2);
    *(uint *)(lVar2 + 0x40 + (ulonglong)param_2 * 4) = uVar1 & 0xffffffd5 | 0x1000;
    LOCK();
    UNLOCK();
  }
  return 0;
}



===== EHCI_RH_SetFeaturePortReset @ 14000e780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_RH_SetFeaturePortReset(longlong param_1,ushort param_2)

{
  longlong *plVar1;
  uint *puVar2;
  char cVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  uint uVar10;
  ulonglong uVar11;
  ushort local_48 [5];
  undefined6 uStack_3e;
  undefined2 uStack_38;
  
  puVar2 = *(uint **)(param_1 + 200);
  uVar9 = 0;
  uVar7 = (ulonglong)param_2;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  uStack_3e = 0;
  uStack_38 = 0;
  if (puVar2 == (uint *)0x0) {
    return 0;
  }
  if (param_2 == *(ushort *)(param_1 + 1000)) {
    return 0;
  }
  if (param_2 < 0x10) {
    uVar11 = (ulonglong)(uint)param_2;
    plVar1 = (longlong *)(param_1 + 1000 + uVar7 * 8);
    if (*plVar1 != 0) {
      cVar3 = (*DAT_140016570)(0,*plVar1,1);
      if (cVar3 == '\0') goto LAB_14000ea6d;
      plVar4 = *(longlong **)(param_1 + 0x460 + uVar7 * 8);
      *plVar1 = 0;
      if (plVar4 != (longlong *)0x0) {
        EHCI_DerefAsyncIdle(param_1,plVar4);
        *(undefined8 *)(param_1 + 0x460 + uVar7 * 8) = 0;
      }
    }
    uVar5 = puVar2[uVar7 + 0x10];
    uVar6 = (ulonglong)uVar5;
    (*DAT_140016440)(param_1,0x10000001,0x7270735f,uVar5,0,uVar11);
    if (((((uVar5 & 0xc00) == 0x400) && ((uVar5 & 0x2087) == 1)) && (*(int *)(param_1 + 0x4c) != 0))
       && (*(char *)(param_1 + 0x5d) != '\0')) {
      puVar2[uVar7 + 0x10] = uVar5 | 0x2000;
      LOCK();
      UNLOCK();
      uVar10 = puVar2[uVar7 + 0x10];
      uVar9 = 0x3172725f;
      uVar6 = uVar11;
      uVar11 = 0;
    }
    else {
      uVar10 = 0;
      if ((uVar5 & 0x2001) == 1) {
        *(uint *)(param_1 + 0x140) = *(uint *)(param_1 + 0x140) | 1 << ((char)param_2 - 1U & 0x1f);
        (*DAT_140016440)(param_1,0x10000001,0x7365725f,uVar6,0,uVar11);
        if (*(char *)(param_1 + 0x650) != '\0') {
          *puVar2 = *puVar2 & 0xfffffffe;
          LOCK();
          UNLOCK();
          uVar10 = 0;
          do {
            if ((puVar2[1] >> 0xc & 1) != 0) break;
            KeStallExecutionProcessor(0x7d);
            uVar10 = uVar10 + 1;
          } while (uVar10 < 0x10);
        }
        uVar5 = uVar5 & 0xffffffd1 | 0x100;
        puVar2[uVar7 + 0x10] = uVar5;
        LOCK();
        UNLOCK();
        if (*(char *)(param_1 + 0x650) != '\0') {
          uVar10 = EHCI_ReadQcHsicDbg1Register(param_1);
          EHCI_WriteQcHsicDbg1Register(param_1,(byte)uVar10 & 0x9f | 0x10);
        }
        uVar8 = 0x32;
        local_48[0] = param_2;
        if (*(char *)(param_1 + 0x650) == '\0') {
          plVar4 = EHCI_RefAsyncIdle(param_1,4);
          local_48[4] = (ushort)plVar4;
          uStack_3e = (undefined6)((ulonglong)plVar4 >> 0x10);
          *(longlong **)(param_1 + 0x460 + uVar11 * 8) = plVar4;
        }
        else {
          uVar8 = 0x3c;
          *(undefined8 *)(param_1 + 0x460 + uVar11 * 8) = 0;
        }
        uVar10 = (*DAT_140016568)(param_1,uVar8,local_48,0x18,EHCI_RH_PortResetComplete,plVar1,1);
        (*DAT_140016440)(param_1,0x10000001,0x3272735f,uVar11,uVar5,(longlong)(int)uVar10);
        if ((uVar10 & 0xc0000000) == 0xc0000000) {
          if ((longlong *)CONCAT62(uStack_3e,local_48[4]) != (longlong *)0x0) {
            EHCI_DerefAsyncIdle(param_1,(longlong *)CONCAT62(uStack_3e,local_48[4]));
            local_48[4] = 0;
            uStack_3e = 0;
            *(undefined8 *)(param_1 + 0x460 + uVar11 * 8) = 0;
          }
          if (*(char *)(param_1 + 0x650) != '\0') {
            EHCI_QualcommClearUlpiReset(param_1);
            *puVar2 = *puVar2 | 1;
            LOCK();
            UNLOCK();
          }
          uVar9 = 5;
        }
        return uVar9;
      }
      uVar9 = 0x70746d5f;
    }
    (*DAT_140016440)(param_1,0x10000001,uVar9,uVar6,uVar10,uVar11);
    uVar9 = 0;
  }
  else {
LAB_14000ea6d:
    uVar9 = 5;
  }
  return uVar9;
}



===== EHCI_ReadQcHsicDbg1Register @ 14000ea98 =====

uint EHCI_ReadQcHsicDbg1Register(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  bool bVar4;
  
  lVar2 = *(longlong *)(param_1 + 200);
  *(undefined4 *)(lVar2 + 0x30) = 0x40380000;
  LOCK();
  UNLOCK();
  uVar3 = 0;
  do {
    KeStallExecutionProcessor(5);
    uVar1 = *(uint *)(lVar2 + 0x30);
    if ((uVar1 >> 0x1e & 1) == 0) break;
    bVar4 = uVar3 < 10;
    uVar3 = uVar3 + 1;
  } while (bVar4);
  return uVar1 >> 8;
}



===== EHCI_SetPortResumeTime @ 14000eb00 =====

void EHCI_SetPortResumeTime(longlong param_1,ushort param_2,char param_3,byte param_4)

{
  int iVar1;
  ulonglong uVar2;
  
  if (param_2 < 0x10) {
    uVar2 = (ulonglong)param_2;
    iVar1 = *(int *)(param_1 + 0x5fc + uVar2 * 4);
    if (param_3 == '\x01') {
      iVar1 = iVar1 + 1;
      *(int *)(param_1 + 0x5fc + uVar2 * 4) = iVar1;
      if (((1 < iVar1) && (*(byte *)(uVar2 + param_1 + 0x63b) < param_4)) || (iVar1 == 1)) {
        *(byte *)(uVar2 + param_1 + 0x63b) = param_4;
        return;
      }
    }
    else if (0 < iVar1) {
      *(int *)(param_1 + 0x5fc + uVar2 * 4) = iVar1 + -1;
    }
  }
  return;
}



===== EHCI_WriteQcHsicDbg1Register @ 14000eb60 =====

void EHCI_WriteQcHsicDbg1Register(longlong param_1,byte param_2)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  
  lVar1 = *(longlong *)(param_1 + 200);
  *(uint *)(lVar1 + 0x30) = param_2 | 0x60380000;
  LOCK();
  UNLOCK();
  uVar2 = 0;
  do {
    KeStallExecutionProcessor(5);
    if ((*(uint *)(lVar1 + 0x30) >> 0x1e & 1) == 0) {
      return;
    }
    bVar3 = uVar2 < 10;
    uVar2 = uVar2 + 1;
  } while (bVar3);
  return;
}



===== Feature_1273213241__private_IsEnabledDeviceUsageNoInline @ 14000ebbc =====

ulonglong Feature_1273213241__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_1273213241__private_featureState;
  if ((Feature_1273213241__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1273213241__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1273213241__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1273213241__private_IsEnabledFallback @ 14000ebf4 =====

void Feature_1273213241__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14000ec0c =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14000ece4 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000edc8 =====

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
LAB_14000ef20:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000ef13:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_14000ef20;
      if (uVar5 == 5) goto LAB_14000ef13;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000ef48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3b0a60c,&Feature_1273213241_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000efc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,(uint *)&Feature_1273213241__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3b0a60c,param_3 & 0xffffffff,1,&Feature_1273213241__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3b0a60c);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000f0b0 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000f1c0 =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_2 == 3) {
    uVar2 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar2 = 0x20;
  }
  if ((Feature_1273213241__private_featureState & 2) != 0) {
    uVar1 = Feature_1273213241__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_1273213241__private_featureState;
      if (bVar3) {
        Feature_1273213241__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_1273213241__private_featureState;
      }
      UNLOCK();
      if (bVar3) {
        return;
      }
      if ((uVar1 & 2) == 0) {
        return;
      }
    }
  }
  return;
}



===== wil_details_GetCurrentFeatureEnabledState @ 14000f214 =====

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



===== wil_details_IsEnabledFallback @ 14000f374 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_1273213241__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_1273213241__private_featureState,(ulonglong)param_1,
                             0x140015ba8);
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
  }
  else {
    puVar1 = param_1;
  }
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,local_res18,param_2);
    if (param_2 - 3 < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res18,param_2);
    }
  }
  return (uint)puVar1 & 1;
}



===== wil_details_MapReportingKind @ 14000f404 =====

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



===== EHCI_CreateDeviceData @ 14000f4b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EHCI_CreateDeviceData(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined1 auStack_68 [32];
  undefined8 *local_48;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 *local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  *param_1 = 0x69636865;
  puVar1 = param_1 + 0x40;
  *(undefined4 **)(param_1 + 0x42) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  KeInitializeSpinLock(param_1 + 0x44);
  puVar1 = param_1 + 0x20;
  *(undefined4 **)(param_1 + 0x22) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  puVar1 = param_1 + 0x24;
  *(undefined4 **)(param_1 + 0x26) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  puVar1 = param_1 + 0x28;
  *(undefined4 **)(param_1 + 0x2a) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  puVar1 = param_1 + 0x2c;
  *(undefined4 **)(param_1 + 0x2e) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  puVar1 = param_1 + 6;
  param_1[0x15c] = 1;
  param_1[0xc] = 1;
  *(undefined8 *)(param_1 + 0x13) = 1;
  *(undefined1 *)((longlong)param_1 + 0x5d) = 1;
  param_1[0xe] = 1;
  param_1[0x11] = 1;
  param_1[0x159] = 0;
  param_1[10] = 0;
  param_1[0x15] = 10;
  *(undefined8 *)(param_1 + 0x1d) = 0;
  *(undefined4 **)(param_1 + 8) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  *(undefined1 *)((longlong)param_1 + 99) = 1;
  *(undefined8 *)(param_1 + 0x154) = 1;
  param_1[0x156] = 1;
  param_1[0x157] = 1;
  param_1[0x158] = 1;
  *(undefined1 *)(param_1 + 0xfb) = 0;
  *(undefined8 *)(param_1 + 0xea) = 0;
  param_1[0x16] = 0;
  param_1[0x193] = 0;
  *(undefined1 *)((longlong)param_1 + 0x65) = 0;
  *(undefined8 *)(param_1 + 0x15d) = 0;
  param_1[0x15f] = 0;
  param_1[0x15a] = 0x101;
  *(undefined1 *)((longlong)param_1 + 0x5e) = 0;
  param_1[0x195] = 0;
  EHCI_GetRegistryParameters((longlong)param_1);
  local_38[0] = param_1[0x195];
  local_48 = &local_30;
  local_20 = local_38;
  *(undefined1 *)((longlong)param_1 + 0x62) = 0;
  local_18 = 4;
  local_30 = 0;
  uStack_28 = 0;
  (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_CREATE_DEVICE_DATA,0,2);
  return;
}



===== _guard_check_icall @ 14000f640 =====

void _guard_check_icall(void)

{
  return;
}



===== EHCI_DisableAMDAsyncQhCache @ 14000f64c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_DisableAMDAsyncQhCache(longlong param_1)

{
  uint local_res8 [8];
  
  local_res8[0] = 0;
  if (*(char *)(param_1 + 0x70) == '\0') {
    (*DAT_140016458)(param_1,1,local_res8,0x50,4);
    if ((local_res8[0] & 0x2000000) == 0) {
      local_res8[0] = local_res8[0] | 0x2000000;
      (*DAT_140016458)(param_1,0,local_res8,0x50,4);
    }
  }
  return;
}



===== EHCI_EvaluateAcpiDsmRoutine @ 14000f6c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EHCI_EvaluateAcpiDsmRoutine(undefined8 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  undefined4 local_80;
  undefined1 local_78;
  undefined8 *local_70;
  undefined8 *local_68;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  local_40 = 0;
  uStack_38 = 0;
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x3c,0x65686369);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *puVar2 = 0x43696541;
    puVar2[1] = 0x4d53445f;
    puVar2[2] = 0x3c;
    puVar2[3] = 4;
    puVar2[4] = 0x100002;
    memcpy_s(puVar2 + 5,0x10,&GUID_USB_ACPI_DSM,0x10);
    uVar3 = (ulonglong)*(ushort *)((longlong)puVar2 + 0x12);
    if (*(ushort *)((longlong)puVar2 + 0x12) < 4) {
      uVar3 = 4;
    }
    *(undefined8 *)((longlong)puVar2 + uVar3 + 0x14) = 0x40000;
    *(undefined4 *)((longlong)puVar2 + uVar3 + 0x1c) = 0x40000;
    *(undefined4 *)((longlong)puVar2 + uVar3 + 0x20) = 1;
    *(undefined4 *)((longlong)puVar2 + uVar3 + 0x24) = 3;
    KeInitializeEvent(&local_58,0,0);
    local_68 = &local_40;
    local_70 = &local_58;
    local_78 = 0;
    local_88 = &local_30;
    local_80 = 0x14;
    lVar4 = IoBuildDeviceIoControlRequest(0x32c004,param_1,puVar2,0x3c);
    if (lVar4 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
      *(undefined8 *)(lVar4 + 0x38) = 0;
      iVar1 = IofCallDriver(param_1,lVar4);
      if (iVar1 == 0x103) {
        local_88 = (undefined8 *)0x0;
        KeWaitForSingleObject(&local_58,0,0,0);
        iVar1 = (int)local_40;
      }
    }
    ExFreePoolWithTag(puVar2,0x65686369);
  }
  return iVar1;
}



===== EHCI_EvaluateAcpiRoutine @ 14000f89c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong EHCI_EvaluateAcpiRoutine(undefined8 param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined1 auStack_a8 [32];
  ulonglong *local_88;
  undefined4 local_80;
  undefined1 local_78;
  undefined8 *local_70;
  ulonglong *local_68;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38 [4];
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_58 = 0x42696541;
  local_40 = 0;
  local_18 = 0;
  local_54 = 0x4642555f;
  local_38[0] = 0;
  local_38[1] = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  KeInitializeEvent(&local_50,1,0);
  local_68 = local_38;
  local_70 = &local_50;
  local_78 = 0;
  local_88 = local_38 + 2;
  local_80 = 0x14;
  lVar1 = IoBuildDeviceIoControlRequest(0x32c004,param_1,&local_58,8);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(param_1,lVar1);
    if ((int)uVar2 == 0x103) {
      local_88 = (ulonglong *)0x0;
      KeWaitForSingleObject(&local_50,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== EHCI_EvaluateAcpiRoutineOnHcReset @ 14000f9b0 =====

void EHCI_EvaluateAcpiRoutineOnHcReset(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = EHCI_EvaluateAcpiDsmRoutine(param_1);
  if (iVar1 < 0) {
    EHCI_EvaluateAcpiRoutine(param_1);
  }
  return;
}



===== EHCI_GetEndpointState @ 14000f9e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int EHCI_GetEndpointState(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x118);
  (*DAT_140016440)(param_1,0x10000001,0x7365675f,param_2,0,(longlong)iVar1);
  return iVar1;
}



===== EHCI_GetHcCapabilities @ 14000fa30 =====

undefined8 EHCI_GetHcCapabilities(longlong param_1,ushort *param_2)

{
  if (*param_2 < 0xc) {
    if (*param_2 < 8) {
      return 5;
    }
    param_2[0] = 8;
    param_2[1] = 1;
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)(param_1 + 0x58);
  }
  else {
    param_2[0] = 0xc;
    param_2[1] = 2;
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)(param_1 + 0x58);
    *(bool *)(param_2 + 4) = *(int *)(param_1 + 0x64c) != 0;
  }
  return 0;
}



===== EHCI_GetIdleStatus @ 14000fa84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 EHCI_GetIdleStatus(longlong param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  (*DAT_140016440)(param_1,0x10000001,0x3173695f,param_2,param_3,0);
  if ((param_2 < 4) || (param_3 == (uint *)0x0)) {
    uVar2 = 5;
  }
  else {
    uVar1 = 0xc;
    if (*(int *)(param_1 + 0x558) == 1) {
      uVar1 = 8;
    }
    uVar3 = uVar1 | 2;
    if (*(int *)(param_1 + 0x560) == 1) {
      uVar3 = uVar1;
    }
    if ((*(int *)(param_1 + 0x28) == 0) || (*(int *)(param_1 + 0x3dc) != 0)) {
      uVar3 = uVar3 | 1;
    }
    *param_3 = uVar3;
    uVar2 = 0;
  }
  (*DAT_140016440)(param_1,0x10000001,0x5873695f,uVar3,uVar2,0);
  return uVar2;
}



===== EHCI_GetRegistryParameters @ 14000fb58 =====

void EHCI_GetRegistryParameters(longlong param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  byte local_res8 [8];
  uint local_res10 [2];
  uint local_res18 [4];
  undefined1 in_stack_ffffffffffffffc8;
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  local_res18[0] = 0;
  EHCI_ReadUlongRegFlag(param_1,L"DsLowSpeedHandoff",0x24,0,local_res18,0,in_stack_ffffffffffffffc8)
  ;
  if (local_res18[0] != 0) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  piVar1 = (int *)(param_1 + 0x6c);
  EHCI_ReadUlongRegValue
            (param_1,L"SlotsPerEndpoint",0x22,*piVar1,piVar1,0,in_stack_ffffffffffffffc8);
  if (1 < *piVar1 - 1U) {
    *piVar1 = 2;
  }
  puVar2 = (uint *)(param_1 + 0x564);
  EHCI_ReadUlongRegValue
            (param_1,L"USBEHCI_InternalFlags",0x2c,*puVar2,puVar2,0,in_stack_ffffffffffffffc8);
  uVar3 = *puVar2;
  if ((uVar3 & 1) != 0) {
    *(undefined4 *)(param_1 + 0x574) = 1;
    *(undefined4 *)(param_1 + 0x578) = 1;
  }
  if ((uVar3 & 4) != 0) {
    *(undefined1 *)(param_1 + 0x568) = 0;
  }
  if ((uVar3 & 2) != 0) {
    *(undefined1 *)(param_1 + 0x569) = 0;
  }
  if ((uVar3 & 8) != 0) {
    *(undefined1 *)(param_1 + 0x56a) = 1;
  }
  if ((uVar3 & 0x10) != 0) {
    *(undefined1 *)(param_1 + 0x56b) = 1;
  }
  EHCI_ReadUlongRegFlag
            (param_1,L"EnHcAsyncIdle",0x1c,*(uint *)(param_1 + 0x38),(uint *)(param_1 + 0x38),0,
             in_stack_ffffffffffffffc8);
  EHCI_ReadUlongRegFlag
            (param_1,L"EnHcPeriodicIdle",0x22,*(uint *)(param_1 + 0x44),(uint *)(param_1 + 0x44),
             (longlong)local_res8,in_stack_ffffffffffffffc8);
  *(uint *)(param_1 + 0x48) = (uint)local_res8[0];
  local_res18[0] = 0;
  EHCI_ReadUlongRegFlag(param_1,L"EnHcSoftRetry",0x1c,0,local_res18,0,in_stack_ffffffffffffffc8);
  puVar2 = (uint *)(param_1 + 0x50);
  if (local_res18[0] != 0) {
    *puVar2 = 10;
  }
  EHCI_ReadUlongRegValue
            (param_1,L"HcSoftPerSecRetryCount",0x2e,*puVar2,puVar2,0,in_stack_ffffffffffffffc8);
  if (*(char *)(param_1 + 0x61) == '\0') {
    if (100 < *puVar2) {
      *puVar2 = 100;
    }
  }
  else if (1000 < *puVar2) {
    *puVar2 = 1000;
  }
  puVar2 = (uint *)(param_1 + 0x54);
  EHCI_ReadUlongRegValue
            (param_1,L"MissedMicroframePerSecRetryCount",0x42,*puVar2,puVar2,0,
             in_stack_ffffffffffffffc8);
  if (*(char *)(param_1 + 0x61) == '\0') {
    if (100 < *puVar2) {
      *puVar2 = 100;
    }
  }
  else if (1000 < *puVar2) {
    *puVar2 = 1000;
  }
  EHCI_ReadUlongRegFlag
            (param_1,L"EnAsyncQhIdleRemoval",0x2a,(uint)*(byte *)(param_1 + 99),local_res10,
             (longlong)local_res8,in_stack_ffffffffffffffc8);
  *(bool *)(param_1 + 99) = local_res10[0] != 0;
  *(byte *)(param_1 + 100) = local_res8[0];
  EHCI_ReadUlongRegFlag
            (param_1,L"EnAsyncQhDummy",0x1e,(uint)*(byte *)(param_1 + 0x65),local_res10,
             (longlong)local_res8,in_stack_ffffffffffffffc8);
  *(bool *)(param_1 + 0x65) = local_res10[0] != 0;
  *(byte *)(param_1 + 0x66) = local_res8[0];
  EHCI_ReadUlongRegFlag
            (param_1,L"DisableAMDAsyncQhCache",0x2e,(uint)*(byte *)(param_1 + 0x67),local_res10,
             (longlong)local_res8,in_stack_ffffffffffffffc8);
  *(bool *)(param_1 + 0x67) = local_res10[0] != 0;
  *(byte *)(param_1 + 0x68) = local_res8[0];
  EHCI_ReadUlongRegFlag
            (param_1,L"En64BitAddressing",0x24,*(uint *)(param_1 + 0x58),local_res10,
             (longlong)local_res8,in_stack_ffffffffffffffc8);
  *(byte *)(param_1 + 0x5c) = local_res8[0];
  *(uint *)(param_1 + 0x58) = (uint)(local_res10[0] != 0);
  EHCI_ReadUlongRegValue
            (param_1,L"ResetRecoveryEnable",0x28,*(undefined4 *)(param_1 + 0x550),
             (undefined4 *)(param_1 + 0x550),0,in_stack_ffffffffffffffc8);
  EHCI_ReadUlongRegValue
            (param_1,L"ResetRecoveryBreak",0x26,*(undefined4 *)(param_1 + 0x554),
             (undefined4 *)(param_1 + 0x554),0,in_stack_ffffffffffffffc8);
  EHCI_ReadUlongRegValue
            (param_1,L"IntegratedTTType",0x22,0,(undefined4 *)(param_1 + 0x64c),param_1 + 0x56c,
             in_stack_ffffffffffffffc8);
  EHCI_ReadUlongRegFlag
            (param_1,L"NoInterlockedOpOnCommonBuffers",0x3e,(uint)*(byte *)(param_1 + 0x5e),
             local_res10,(longlong)local_res8,in_stack_ffffffffffffffc8);
  puVar2 = (uint *)(param_1 + 0x654);
  *(bool *)(param_1 + 0x5e) = local_res10[0] != 0;
  *(byte *)(param_1 + 0x5f) = local_res8[0];
  EHCI_ReadUlongRegValue(param_1,L"NakReloadCount",0x1e,*puVar2,puVar2,0,in_stack_ffffffffffffffc8);
  if (0xf < *puVar2) {
    *puVar2 = 0xf;
  }
  return;
}



===== EHCI_HaltController @ 14000ff40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_HaltController(longlong param_1)

{
  uint uVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = *(uint **)(param_1 + 200);
  uVar5 = 0;
  if (puVar2 != (uint *)0x0) {
    cVar3 = USBPORT_IsControllerInHibernatePath(*(undefined8 *)(param_1 + 8));
    uVar1 = *puVar2;
    (*DAT_140016440)(param_1,0x10000001,0x7074735f,uVar1,0,0);
    uVar4 = uVar1 & 0xfffffffe;
    if (cVar3 != '\0') {
      uVar4 = uVar1;
    }
    *puVar2 = uVar4 & 0xffffffbf;
    LOCK();
    UNLOCK();
    if (cVar3 == '\0') {
      do {
        if ((puVar2[1] >> 0xc & 1) != 0) {
          return;
        }
        KeStallExecutionProcessor(0x7d);
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0x12);
    }
  }
  return;
}



===== EHCI_LocateDebugPortRegisters @ 140010010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong EHCI_LocateDebugPortRegisters(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  uint uVar2;
  undefined1 auStack_148 [32];
  undefined4 local_128;
  undefined4 local_118;
  byte local_112;
  byte local_e4;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  memset(&local_118,0,0x100);
  uVar2 = 0;
  if (*(char *)(param_1 + 0x70) == '\0') {
    local_128 = 0x100;
    (*DAT_140016458)(param_1,1,&local_118,0);
    if ((local_112 & 0x10) != 0) {
      while( true ) {
        if ((local_e4 & 0xfc) < 0x40) {
          return 0;
        }
        if (0x2f < uVar2) {
          return 0;
        }
        uVar1 = (ulonglong)(local_e4 & 0xfc);
        if (*(char *)((longlong)&local_118 + uVar1) == '\n') break;
        local_e4 = *(byte *)((longlong)&local_118 + uVar1 + 1);
        uVar2 = uVar2 + 1;
      }
      if ((*(uint *)((longlong)&local_118 + uVar1) & 0xe0000000) == 0x20000000) {
        return (ulonglong)(*(uint *)((longlong)&local_118 + uVar1) >> 0x10 & 0xfff) +
               *(longlong *)(param_2 + 0x28);
      }
    }
  }
  return 0;
}



===== EHCI_PokeEndpoint @ 1400100f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 EHCI_PokeEndpoint(undefined8 param_1,ushort *param_2,longlong param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  (*DAT_140016440)(param_1,0x10000001,0x6b6f505f,param_3,param_2,0);
  if ((*(uint *)(param_3 + 0x80) & 2) == 0) {
    iVar1 = *(int *)(param_3 + 0x3c);
    if (iVar1 == 0) {
      uVar2 = EHCI_PokeIsoEndpoint(0,param_2,param_3);
      return uVar2;
    }
    uVar4 = (ulonglong)(iVar1 - 1U);
    if (iVar1 - 1U != 0) {
      uVar3 = iVar1 - 2;
      uVar4 = (ulonglong)uVar3;
      if ((uVar3 != 0) && (uVar3 != 1)) goto LAB_14001015f;
    }
    uVar2 = EHCI_PokeAsyncEndpoint(uVar4,(undefined8 *)param_2,param_3);
  }
  else {
LAB_14001015f:
    uVar2 = 0;
  }
  return uVar2;
}



===== EHCI_PostResetController @ 140010180 =====

void EHCI_PostResetController(longlong param_1)

{
  EHCI_EvaluateAcpiRoutineOnHcReset(*(undefined8 *)(param_1 + 0x10));
  return;
}



===== EHCI_PreStartController @ 1400101a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EHCI_PreStartController(longlong param_1,uint *param_2)

{
  short *psVar1;
  longlong lVar2;
  uint uVar3;
  undefined *puVar4;
  undefined1 auStack_a8 [32];
  undefined8 *local_88;
  undefined8 local_80;
  undefined1 local_68 [4];
  int local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  int *local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  psVar1 = (short *)(param_1 + 0x3d0);
  *(uint *)(param_1 + 0x128) = param_2[1];
  uVar3 = param_2[0x32];
  *(char *)(param_1 + 0x70) = (char)uVar3;
  local_68[0] = 0;
  local_64 = 0;
  puVar4 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_COMPLETE;
  if ((char)uVar3 == '\0') {
    local_88._0_4_ = 2;
    (*DAT_140016458)(param_1,1,psVar1,0);
    local_88._0_4_ = 2;
    (*DAT_140016458)(param_1,1,(undefined2 *)(param_1 + 0x3d2),2);
    local_88 = (undefined8 *)CONCAT44(local_88._4_4_,1);
    (*DAT_140016458)(param_1,1,local_68,0x61);
    *(undefined1 *)(param_1 + 0x3ed) = local_68[0];
  }
  else {
    *psVar1 = 0;
    *(undefined2 *)(param_1 + 0x3d2) = 0;
    *(undefined1 *)(param_1 + 0x3ed) = 0;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x64c) = 0;
  if (*(char *)(param_1 + 0x5c) == '\0') {
    if ((*param_2 & 8) == 0) {
      local_64 = 4;
      puVar4 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_COMPLETE_ERROR_1;
      goto LAB_14001036b;
    }
    lVar2 = *(longlong *)(param_2 + 10);
    local_80 = 0;
    local_88 = (undefined8 *)0x0;
    (*DAT_140016440)(param_1,0x10000001,0x7273505f,lVar2);
    uVar3 = *(uint *)(lVar2 + 8);
    if (uVar3 == 0xffffffff) {
      *(undefined8 *)(param_1 + 200) = 0;
      puVar4 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_COMPLETE_ERROR_2;
      local_64 = 7;
      goto LAB_14001036b;
    }
    if (*psVar1 == 0x10de) {
      *(undefined4 *)(param_1 + 0x58) = 0;
    }
    else {
      *(uint *)(param_1 + 0x58) = uVar3 & 1;
    }
  }
  if (*(char *)(param_1 + 0x56c) == '\0') {
    if (*(int *)(param_1 + 0x128) == 0x1389) {
LAB_14001035e:
      *(undefined4 *)(param_1 + 0x64c) = 2;
    }
    else {
      *(undefined4 *)(param_1 + 0x64c) = 0;
      if (param_2[0x36] != 0) {
        if (*(short *)(*(longlong *)(param_2 + 0x34) + 0x1a) == 1) {
          *(undefined4 *)(param_1 + 0x64c) = 1;
        }
        else if (*(short *)(*(longlong *)(param_2 + 0x34) + 0x1a) == 2) goto LAB_14001035e;
      }
    }
  }
  if (local_64 == 0) {
    return 0;
  }
LAB_14001036b:
  local_88 = &local_60;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = (int *)0x0;
  uStack_48 = 0;
  (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_DISPATCH,0,1);
  local_50 = &local_64;
  local_60 = 0;
  local_88 = &local_60;
  uStack_58 = 0;
  uStack_48 = 4;
  (*DAT_1400165e0)(param_1,puVar4,0,2);
  return local_64;
}



===== EHCI_ReadConfigFlag @ 140010410 =====

int EHCI_ReadConfigFlag(longlong param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(longlong *)(param_1 + 200) != 0) {
    iVar1 = *(int *)(*(longlong *)(param_1 + 200) + 0x40);
    iVar2 = 0;
    if (iVar1 != -1) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}



===== EHCI_ReadUlongRegFlag @ 140010430 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_ReadUlongRegFlag
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint param_4,uint *param_5,
               longlong param_6,undefined1 param_7)

{
  int iVar1;
  
  _param_7 = 0;
  iVar1 = (*DAT_140016418)(param_1,0,param_2,param_3,&param_7,4);
  if (iVar1 == 0) {
    param_4 = (uint)(_param_7 != 0);
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = param_4;
  }
  if (param_6 != 0) {
    *(bool *)param_6 = iVar1 == 0;
  }
  return;
}



===== EHCI_ReadUlongRegValue @ 1400104a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_ReadUlongRegValue
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5,longlong param_6,undefined1 param_7)

{
  int iVar1;
  
  _param_7 = 0;
  iVar1 = (*DAT_140016418)(param_1,0,param_2,param_3,&param_7,4);
  if (iVar1 == 0) {
    param_4 = _param_7;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = param_4;
  }
  if (param_6 != 0) {
    *(bool *)param_6 = iVar1 == 0;
  }
  return;
}



===== EHCI_RebalanceEndpoint @ 140010510 =====

void EHCI_RebalanceEndpoint(longlong param_1,undefined8 *param_2,longlong param_3)

{
  if ((*(uint *)(param_3 + 0x80) & 2) == 0) {
    if (*(int *)((longlong)param_2 + 0x14) == 0) {
      EHCI_RebalanceIsoEndpoint(param_1,param_2,param_3);
    }
    else if (*(int *)((longlong)param_2 + 0x14) == 3) {
      EHCI_RebalanceInterruptEndpoint(param_1,param_2,param_3);
    }
  }
  return;
}



===== EHCI_ReinitController @ 140010550 =====

void EHCI_ReinitController(longlong param_1)

{
  uint *puVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 *puVar4;
  
  puVar1 = *(uint **)(param_1 + 200);
  if (puVar1 != (uint *)0x0) {
    puVar4 = *(undefined1 **)(param_1 + 0x170);
    for (uVar2 = (ulonglong)*(uint *)(param_1 + 0x17c); uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = *(undefined1 **)(param_1 + 0x180);
    for (uVar2 = (ulonglong)*(uint *)(param_1 + 0x18c); uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    EHCI_InitializeSchedule
              (param_1,*(uint **)(param_1 + 0x170),*(int *)(param_1 + 0x178),
               *(undefined8 *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x188));
    *(undefined8 *)(param_1 + 0x3a8) = 0;
    *puVar1 = *puVar1 & 0xff01ffbf | 0x10000;
    LOCK();
    UNLOCK();
    if (*(char *)(param_1 + 0x67) != '\0') {
      EHCI_DisableAMDAsyncQhCache(param_1);
    }
    *puVar1 = *puVar1 & 0xffffffbf | 1;
    LOCK();
    UNLOCK();
    if ((*(short *)(param_1 + 0x152) == 1) && (uVar3 = 0, *(short *)(param_1 + 0x150) != 0)) {
      do {
        puVar1[(ulonglong)uVar3 + 0x11] = puVar1[(ulonglong)uVar3 + 0x11] & 0xffffffd5 | 0x1000;
        LOCK();
        UNLOCK();
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(ushort *)(param_1 + 0x150));
    }
    puVar1[0x10] = 1;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x54c) = 0;
  }
  return;
}



===== EHCI_ReleasePortControl @ 140010660 =====

void EHCI_ReleasePortControl(longlong param_1)

{
  if (*(longlong *)(param_1 + 200) != 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 200) + 0x40) = 0;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x3d4) = 0;
  }
  return;
}



===== EHCI_ResetController @ 140010690 =====

void EHCI_ResetController(longlong param_1)

{
  EHCI_ResetControllerDontReinit(param_1);
  EHCI_ReinitController(param_1);
  return;
}



===== EHCI_ResetControllerDontReinit @ 1400106c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EHCI_ResetControllerDontReinit(longlong param_1)

{
  int iVar1;
  uint *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 local_res8 [8];
  undefined8 local_res10;
  
  puVar2 = *(uint **)(param_1 + 200);
  local_res10 = 0;
  local_res8[0] = 0;
  if (puVar2 != (uint *)0x0) {
    *puVar2 = *puVar2 & 0xffffffbe;
    LOCK();
    UNLOCK();
    uVar5 = 0;
    do {
      if ((puVar2[1] >> 0xc & 1) != 0) break;
      KeStallExecutionProcessor(0x7d);
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x12);
    *puVar2 = 2;
    LOCK();
    UNLOCK();
    lVar4 = KeQueryInterruptTimePrecise(&local_res10);
    uVar5 = *puVar2;
    while (((uVar5 & 2) != 0 && (_DAT_fffff78000000008 < lVar4 + 1000000U))) {
      uVar5 = *puVar2;
    }
    EHCI_AcquireAsyncDoorbellLock(param_1,local_res8);
    *(undefined4 *)(param_1 + 0x55c) = 1;
    *(undefined4 *)(param_1 + 0x558) = 1;
    *(undefined4 *)(param_1 + 0x560) = 1;
    EHCI_ClearAsyncDoorbellList(param_1);
    *(undefined8 *)(param_1 + 0x118) = 0;
    KeReleaseSpinLock(param_1 + 0x110,local_res8[0]);
    for (puVar3 = *(undefined8 **)(param_1 + 0x18); puVar3 != (undefined8 *)(param_1 + 0x18);
        puVar3 = (undefined8 *)*puVar3) {
      if (*(char *)(param_1 + 0x5e) == '\0') {
        LOCK();
        *(uint *)(puVar3 + 0xe) = *(uint *)(puVar3 + 0xe) | 2;
        UNLOCK();
      }
      else {
        *(uint *)(puVar3 + 0xe) = *(uint *)(puVar3 + 0xe) | 2;
        LOCK();
        UNLOCK();
      }
      iVar1 = *(int *)((longlong)puVar3 + 0x2c);
      if (iVar1 == 0) {
        puVar3[0x23] = 0;
        puVar3[0x22] = 0;
      }
      else if ((iVar1 == 1) || (iVar1 == 2)) {
        lVar4 = puVar3[0xd];
        if (*(char *)(param_1 + 0x5e) == '\0') {
          LOCK();
          *(uint *)(lVar4 + 0x4c) = *(uint *)(lVar4 + 0x4c) & 0xfffffffe;
          UNLOCK();
        }
        else {
          *(uint *)(lVar4 + 0x4c) = *(uint *)(lVar4 + 0x4c) & 0xfffffffe;
          LOCK();
          UNLOCK();
        }
        if (*(char *)(param_1 + 0x5e) == '\0') {
          LOCK();
          *(uint *)(lVar4 + 0x4c) = *(uint *)(lVar4 + 0x4c) & 0xffffffef;
          UNLOCK();
        }
        else {
          *(uint *)(lVar4 + 0x4c) = *(uint *)(lVar4 + 0x4c) & 0xffffffef;
          LOCK();
          UNLOCK();
        }
      }
      else if (iVar1 == 3) {
        lVar4 = puVar3[0xd];
        if (*(char *)(param_1 + 0x5e) == '\0') {
          LOCK();
          *(uint *)(lVar4 + 0x4c) = *(uint *)(lVar4 + 0x4c) & 0xfffffffe;
          UNLOCK();
        }
        else {
          *(uint *)(lVar4 + 0x4c) = *(uint *)(lVar4 + 0x4c) & 0xfffffffe;
          LOCK();
          UNLOCK();
        }
        puVar3[0xf] = 0;
        *(undefined4 *)((longlong)puVar3 + 0x74) = 1;
      }
    }
  }
  return;
}



===== EHCI_SetEndpointDataToggle @ 140010890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EHCI_SetEndpointDataToggle(undefined8 param_1,longlong param_2,int param_3)

{
  if (1 < *(uint *)(param_2 + 0x3c)) {
    *(uint *)(*(longlong *)(param_2 + 0x78) + 0x18) =
         *(uint *)(*(longlong *)(param_2 + 0x78) + 0x18) & 0x7fffffff | param_3 << 0x1f;
    (*DAT_140016440)(param_1,0x10000001,0x6774735f,param_2,0,param_3);
  }
  return;
}



===== EHCI_StartController @ 1400108f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EHCI_StartController(undefined4 *param_1,undefined4 *param_2)

{
  short *psVar1;
  short *psVar2;
  char cVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint *puVar8;
  undefined1 uVar9;
  longlong lVar10;
  undefined8 uVar11;
  short sVar12;
  undefined1 uVar13;
  uint *puVar14;
  undefined *puVar15;
  undefined1 local_b8 [32];
  char local_78 [4];
  int local_74;
  ulonglong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  int *local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_b8;
  local_78[0] = '\0';
  local_68 = 0;
  uStack_60 = 0;
  local_58 = (int *)0x0;
  uStack_50 = 0;
  (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_DISPATCH,0,1);
  if (*(char *)((longlong)param_2 + 0x45) != '\0') {
    EHCI_CreateDeviceData(param_1);
  }
  puVar15 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_COMPLETE;
  *(undefined8 *)(param_1 + 2) = *(undefined8 *)(param_2 + 0x2c);
  psVar1 = (short *)(param_1 + 0xf4);
  psVar2 = (short *)((longlong)param_1 + 0x3d2);
  *(undefined8 *)(param_1 + 4) = *(undefined8 *)(param_2 + 0x30);
  param_1[0x4a] = param_2[1];
  cVar3 = *(char *)(param_2 + 0x32);
  *(char *)(param_1 + 0x1c) = cVar3;
  if (cVar3 == '\0') {
    (*DAT_140016458)(param_1,1,psVar1,0);
    (*DAT_140016458)(param_1,1,psVar2,2);
    (*DAT_140016458)(param_1,1,local_78,0x61);
    *(char *)((longlong)param_1 + 0x3ed) = local_78[0];
  }
  else {
    *psVar1 = 0;
    *psVar2 = 0;
    *(undefined1 *)((longlong)param_1 + 0x3ed) = 0;
  }
  if (((byte)*param_2 & 0xc) != 0xc) {
    local_74 = 4;
    puVar15 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_COMPLETE_ERROR_1;
    goto LAB_140010e06;
  }
  *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)(param_2 + 8);
  puVar14 = *(uint **)(param_2 + 10);
  *(uint **)(param_1 + 0x34) = puVar14;
  uVar5 = *puVar14;
  local_70 = (ulonglong)uVar5;
  (*DAT_140016440)(param_1,0x10000001,0x7274535f,puVar14);
  if (uVar5 == 0xffffffff) {
    local_74 = 7;
    *(undefined8 *)(param_1 + 0x32) = 0;
    puVar15 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_COMPLETE_ERROR_2;
    goto LAB_140010e06;
  }
  param_1[0xb] = uVar5 >> 0x10;
  uVar5 = puVar14[2];
  puVar14 = (uint *)((longlong)puVar14 + (local_70 & 0xff));
  *(uint **)(param_1 + 0x32) = puVar14;
  if (*(char *)(param_2 + 0x32) == '\0') {
    lVar10 = EHCI_LocateDebugPortRegisters((longlong)param_1,(longlong)param_2);
  }
  else {
    lVar10 = 0;
  }
  *(longlong *)(param_1 + 0x36) = lVar10;
  if (*(char *)(param_1 + 0x17) == '\0') {
    if (*psVar1 == 0x10de) {
      param_1[0x16] = 0;
    }
    else {
      param_1[0x16] = uVar5 & 1;
    }
  }
  uVar13 = 0;
  if ((*(char *)(param_1 + 0x19) == '\0') && (*psVar1 == 0x10de)) {
    *(undefined1 *)((longlong)param_1 + 99) = 0;
  }
  if ((*(char *)((longlong)param_1 + 0x66) == '\0') && (*psVar1 == 0x1106)) {
    *(undefined1 *)((longlong)param_1 + 0x65) = 1;
  }
  if (*(char *)(param_1 + 0x1a) == '\0') {
    if (*psVar1 == 0x1002) {
      if ((*psVar2 == 0x4386) || (*psVar2 == 0x4396)) goto LAB_140010ba9;
    }
    else if ((*psVar1 == 0x1022) && (*psVar2 == 0x7808)) {
LAB_140010ba9:
      *(undefined1 *)((longlong)param_1 + 0x67) = 1;
    }
  }
  sVar4 = *(short *)(param_1 + 0xf4);
  sVar12 = sVar4;
  if ((sVar4 != 0x1002) && (sVar4 != 0x1022)) {
    sVar12 = *(short *)(param_1 + 0xf4);
    *(undefined1 *)((longlong)param_1 + 0x67) = 0;
  }
  if (*(char *)(param_1 + 0x1c) != '\0') {
    *(undefined1 *)((longlong)param_1 + 0x67) = 0;
  }
  if (sVar4 == 0x1002) {
    *(undefined1 *)((longlong)param_1 + 0x62) = 1;
  }
  else if (sVar4 == 0x1033) {
    param_1[0x1d] = 1;
    param_1[0x1e] = 1;
  }
  if (*(char *)(param_1 + 0x15b) == '\0') {
    if (param_1[0x4a] == 0x1389) {
      param_1[0x193] = 2;
    }
    else {
      param_1[0x193] = 0;
      if (param_2[0x36] != 0) {
        if (*(short *)(*(longlong *)(param_2 + 0x34) + 0x1a) == 1) {
          param_1[0x193] = 1;
        }
        else if (*(short *)(*(longlong *)(param_2 + 0x34) + 0x1a) == 2) {
          param_1[0x193] = 2;
        }
      }
    }
  }
  if (param_1[0x193] != 0) {
    *(undefined1 *)((longlong)param_1 + 0x5d) = 0;
  }
  if ((sVar12 != 0x1002) || (uVar9 = 1, *(short *)((longlong)param_1 + 0x3d2) != 0x4386)) {
    uVar9 = uVar13;
  }
  *(undefined1 *)(param_1 + 0x18) = uVar9;
  if ((sVar12 == -0x7f7a) &&
     ((*(short *)((longlong)param_1 + 0x3d2) == 0x806 ||
      (*(short *)((longlong)param_1 + 0x3d2) == 0x811)))) {
    uVar13 = 1;
  }
  *(undefined1 *)((longlong)param_1 + 0x61) = uVar13;
  if (((param_1[0x12] == 0) && (sVar12 == 0x1002)) &&
     ((*(short *)((longlong)param_1 + 0x3d2) == 0x4373 ||
      ((*(short *)((longlong)param_1 + 0x3d2) + 0xbc7aU & 0xffef) == 0)))) {
    param_1[0x11] = 0;
  }
  if (*(char *)((longlong)param_1 + 99) == '\0') {
    *(undefined1 *)((longlong)param_1 + 0x569) = 0;
  }
  uVar11 = EHCI_StopBIOS((longlong)param_1);
  local_74 = (int)uVar11;
  if (local_74 == 0) {
    uVar11 = EHCI_InitializeHardware((longlong)param_1);
    local_74 = (int)uVar11;
    if (local_74 == 0) {
      puVar8 = *(uint **)(param_2 + 0xe);
      *(uint **)(param_1 + 0x5c) = puVar8;
      iVar6 = param_2[0x10];
      param_1[0x5e] = iVar6;
      param_1[0x5f] = DAT_140016284;
      uVar11 = *(undefined8 *)(param_2 + 0x14);
      *(undefined8 *)(param_1 + 0x60) = uVar11;
      uVar7 = param_2[0x24];
      param_1[0x62] = uVar7;
      param_1[99] = DAT_1400164b4;
      uVar11 = EHCI_InitializeSchedule((longlong)param_1,puVar8,iVar6,uVar11,uVar7);
      local_74 = (int)uVar11;
      if (local_74 == 0) {
        if (*(char *)(param_1 + 0x1c) == '\0') {
          (*DAT_140016458)(param_1,1,local_78,0x61);
          if (local_78[0] != *(char *)((longlong)param_1 + 0x3ed)) {
            local_78[0] = *(char *)((longlong)param_1 + 0x3ed);
            (*DAT_140016458)(param_1,0,local_78,0x61);
          }
        }
        if (*(char *)((longlong)param_1 + 0x67) != '\0') {
          EHCI_DisableAMDAsyncQhCache((longlong)param_1);
        }
        *puVar14 = *puVar14 & 0xff01ffbf | 0x10000;
        LOCK();
        UNLOCK();
        uVar5 = *puVar14;
        (*DAT_140016440)(param_1,0x10000001,0x6e75725f,uVar5);
        *puVar14 = uVar5 & 0xffffffbf | 1;
        LOCK();
        UNLOCK();
        *(undefined1 *)(param_1 + 0xfb) = 1;
        if (*(char *)((longlong)param_2 + 0x45) != '\0') {
          puVar14[0x10] = 1;
          LOCK();
          UNLOCK();
          param_1[0xf5] = 1;
        }
      }
      else {
        puVar15 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_COMPLETE_ERROR_5;
      }
    }
    else {
      puVar15 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_COMPLETE_ERROR_4;
    }
  }
  else {
    puVar15 = &USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_START_COMPLETE_ERROR_3;
  }
LAB_140010e06:
  local_58 = &local_74;
  local_68 = 0;
  uStack_60 = 0;
  uStack_50 = 4;
  (*DAT_1400165e0)(param_1,puVar15,0,2);
  return local_74;
}



===== EHCI_StopController @ 140010e80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EHCI_StopController(longlong param_1)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined1 local_68 [32];
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_68;
  local_48 = &local_28;
  local_28 = 0;
  uStack_20 = 0;
  (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_STOP_DISPATCH,0,1);
  puVar1 = *(uint **)(param_1 + 200);
  if (puVar1 != (uint *)0x0) {
    cVar2 = USBPORT_IsControllerInHibernatePath(*(undefined8 *)(param_1 + 8));
    local_40 = 0;
    uVar4 = *puVar1;
    local_48 = (undefined8 *)0x0;
    (*DAT_140016440)(param_1,0x10000001,0x7074735f,uVar4);
    uVar3 = uVar4 & 0xfffffffe;
    if (cVar2 != '\0') {
      uVar3 = uVar4;
    }
    *puVar1 = uVar3 & 0xffffffbf;
    LOCK();
    UNLOCK();
    puVar1[2] = 0;
    LOCK();
    UNLOCK();
    if (cVar2 == '\0') {
      uVar4 = 0;
      do {
        if ((puVar1[1] >> 0xc & 1) != 0) break;
        KeStallExecutionProcessor(0x7d);
        uVar4 = uVar4 + 1;
      } while (uVar4 < 0x12);
      puVar1[0x10] = 0;
      LOCK();
      UNLOCK();
    }
    *(undefined8 *)(param_1 + 0xe0) = 0;
    local_48 = &local_28;
    local_28 = 0;
    uStack_20 = 0;
    (*DAT_1400165e0)(param_1,&USBPORT_ETW_EVENT_HC_EHCI_MINIPORT_STOP_COMPLETE,0,1);
  }
  return;
}



===== EHCI_TakePortControl @ 140010ff0 =====

void EHCI_TakePortControl(longlong param_1)

{
  if (*(longlong *)(param_1 + 200) != 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 200) + 0x40) = 1;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x3d4) = 1;
  }
  return;
}



===== EHCI_WriteErrorLogEntry @ 14001101c =====

void EHCI_WriteErrorLogEntry(longlong param_1,undefined4 param_2,char param_3)

{
  undefined8 *puVar1;
  undefined4 in_register_00000014;
  undefined1 uVar2;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  puVar1 = (undefined8 *)
           IoAllocateErrorLogEntry
                     (*(undefined8 *)(param_1 + 8),
                      CONCAT71((int7)(CONCAT44(in_register_00000014,param_2) >> 8),0x94));
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = 0x680000;
    *(undefined2 *)(puVar1 + 1) = 0;
    *(undefined4 *)((longlong)puVar1 + 0xc) = param_2;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    *(undefined2 *)(puVar1 + 5) = *(undefined2 *)(param_1 + 0x3d0);
    *(undefined2 *)((longlong)puVar1 + 0x2a) = *(undefined2 *)(param_1 + 0x3d2);
    uVar2 = 0;
    if (param_3 == '\0') {
      EHCI_AcquireAsyncDoorbellLock(param_1,local_res8);
      uVar2 = local_res8[0];
    }
    *(undefined4 *)((longlong)puVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x3e0);
    *(undefined4 *)(puVar1 + 6) = *(undefined4 *)(param_1 + 0x4e0);
    *(undefined4 *)((longlong)puVar1 + 0x34) = *(undefined4 *)(param_1 + 0x4e4);
    *(undefined4 *)(puVar1 + 7) = *(undefined4 *)(param_1 + 0x4e8);
    *(undefined4 *)((longlong)puVar1 + 0x3c) = *(undefined4 *)(param_1 + 0x4ec);
    *(undefined4 *)(puVar1 + 8) = *(undefined4 *)(param_1 + 0x4f0);
    *(undefined4 *)((longlong)puVar1 + 0x44) = *(undefined4 *)(param_1 + 0x4f4);
    *(undefined4 *)(puVar1 + 9) = *(undefined4 *)(param_1 + 0x4f8);
    *(undefined4 *)((longlong)puVar1 + 0x4c) = *(undefined4 *)(param_1 + 0x4fc);
    *(undefined4 *)(puVar1 + 10) = *(undefined4 *)(param_1 + 0x500);
    *(undefined4 *)((longlong)puVar1 + 0x54) = *(undefined4 *)(param_1 + 0x504);
    *(undefined4 *)(puVar1 + 0xb) = *(undefined4 *)(param_1 + 0x508);
    *(undefined4 *)((longlong)puVar1 + 0x5c) = *(undefined4 *)(param_1 + 0x50c);
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_1 + 0x514);
    *(undefined4 *)((longlong)puVar1 + 100) = *(undefined4 *)(param_1 + 0x518);
    *(undefined4 *)(puVar1 + 0xd) = *(undefined4 *)(param_1 + 0x51c);
    *(undefined4 *)((longlong)puVar1 + 0x6c) = *(undefined4 *)(param_1 + 0x520);
    *(undefined4 *)(puVar1 + 0xe) = *(undefined4 *)(param_1 + 0x524);
    *(undefined4 *)((longlong)puVar1 + 0x74) = *(undefined4 *)(param_1 + 0x528);
    *(undefined4 *)(puVar1 + 0xf) = *(undefined4 *)(param_1 + 0x548);
    *(undefined4 *)((longlong)puVar1 + 0x7c) = *(undefined4 *)(param_1 + 0x574);
    *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(param_1 + 0x578);
    *(undefined4 *)((longlong)puVar1 + 0x84) = *(undefined4 *)(param_1 + 0x57c);
    *(undefined4 *)(puVar1 + 0x11) = *(undefined4 *)(param_1 + 0x580);
    *(undefined4 *)((longlong)puVar1 + 0x8c) = *(undefined4 *)(param_1 + 0x584);
    if (param_3 == '\0') {
      *(undefined8 *)(param_1 + 0x118) = 0;
      KeReleaseSpinLock(param_1 + 0x110,uVar2);
    }
    IoWriteErrorLogEntry(puVar1);
  }
  return;
}



===== EHCIDumpBulkTransfer @ 1400111ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EHCIDumpBulkTransfer(longlong param_1,longlong param_2,uint *param_3)

{
  longlong *plVar1;
  byte bVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  uint *puVar6;
  uint uVar7;
  longlong *plVar8;
  uint uVar9;
  undefined8 *puVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong lVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined1 auStack_128 [32];
  char local_108;
  uint local_100;
  void *local_f8;
  longlong local_f0;
  longlong local_e8 [20];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_128;
  local_f8 = (void *)0x0;
  local_108 = '\0';
  uVar17 = **(uint **)(param_1 + 0x28);
  if (uVar17 == 0xffffffff) {
    return -0x3ffffc9a;
  }
  local_f0 = (ulonglong)(uVar17 & 0xff) + (longlong)*(uint **)(param_1 + 0x28);
  uVar12 = 1;
  bVar2 = *(byte *)(*(longlong *)(param_2 + 0x18) + 2);
  local_100 = (uint)bVar2;
  while( true ) {
    if (4 < (uint)uVar12) {
      return -0x3ffffe7c;
    }
    plVar1 = &DumpEndpoint + uVar12 * 5;
    if (((*(uint *)(*plVar1 + 4) >> 8 ^ local_100) & 0xf) == 0) break;
    uVar12 = (ulonglong)((uint)uVar12 + 1);
  }
  if (plVar1 == (longlong *)0x0) {
    return -0x3ffffe7c;
  }
  if ((*(uint *)(*plVar1 + 4) & 0xf00) == 0) {
    return -0x3ffffe7c;
  }
  uVar17 = *(uint *)(param_2 + 0x24);
  lVar14 = 4;
  puVar10 = &DAT_140016188 + uVar12 * 5;
  do {
    EHCIDumpInitTD((undefined4 *)*puVar10);
    puVar10 = puVar10 + 1;
    lVar14 = lVar14 + -1;
  } while (lVar14 != 0);
  if ((*(char *)(param_1 + 0x5a) == '\0') && (param_3[1] != 0)) {
    local_f8 = (void *)(*(longlong *)(param_1 + 0x10) + 0x2000);
    if ((char)bVar2 < '\0') {
      local_108 = '\x01';
    }
    else {
      memmove(local_f8,*(void **)(param_2 + 0x28),(ulonglong)*(uint *)(param_2 + 0x24));
    }
    memset(local_e8,0,0xa0);
    uVar9 = 1;
    uVar13 = *(uint *)(param_2 + 0x24) >> 0xc;
    local_e8[0] = *(longlong *)(param_1 + 0x18) + 0x2000;
    if (uVar13 != 0) {
      do {
        if (0x13 < uVar9) break;
        uVar7 = uVar9 - 1;
        uVar5 = (ulonglong)uVar9;
        uVar9 = uVar9 + 1;
        local_e8[uVar5] = local_e8[uVar7] + 0x1000;
      } while (uVar9 <= uVar13);
    }
    param_3 = (uint *)local_e8;
  }
  lVar14 = *plVar1;
  uVar9 = 0;
  uVar5 = 0;
  uVar13 = 0;
  if (uVar17 == 0) {
    puVar11 = (undefined4 *)(&DAT_140016188)[uVar12 * 5];
    LOCK();
    puVar11[0xe] = puVar11[0xe] & 0xffffffbf;
    UNLOCK();
    EHCIDumpInitTD(puVar11);
    if ((char)bVar2 < '\0') {
      uVar17 = puVar11[2] & 0xffff7dff | 0x100;
    }
    else {
      uVar17 = puVar11[2] & 0xffff7cff;
    }
    puVar11[3] = puVar11[0x10];
    puVar11[2] = uVar17 & 0xffff;
    puVar11[0xf] = 0;
  }
  else {
    uVar7 = 0;
    uVar13 = (uint)bVar2;
    do {
      if (3 < (uint)uVar5) break;
      lVar3 = (&DAT_140016188)[uVar12 * 5 + uVar5];
      LOCK();
      *(uint *)(lVar3 + 0x38) = *(uint *)(lVar3 + 0x38) & 0xffffffbf;
      UNLOCK();
      if ((char)uVar13 < '\0') {
        uVar13 = *(uint *)(lVar3 + 8) & 0xffff7dff | 0x100;
      }
      else {
        uVar13 = *(uint *)(lVar3 + 8) & 0xffff7cff;
      }
      uVar16 = *param_3;
      *(uint *)(lVar3 + 0xc) = uVar16;
      uVar15 = uVar7 << 0x1f;
      uVar7 = uVar7 ^ 1;
      uVar15 = uVar15 | uVar13 & 0x7fffffff;
      puVar6 = param_3 + 1;
      param_3 = param_3 + 2;
      *(uint *)(lVar3 + 0x20) = *puVar6;
      if (uVar17 < 0x1000) {
        uVar13 = uVar17;
      }
      else {
        uVar13 = 0x1000 - (uVar16 & 0xfff);
      }
      uVar16 = 1;
      puVar6 = (uint *)(lVar3 + 0x24);
      do {
        if (uVar17 <= uVar13 + uVar9) break;
        puVar6[-5] = *param_3;
        *puVar6 = param_3[1];
        if (uVar17 < uVar13 + uVar9 + 0x1000) {
          uVar13 = uVar17 - uVar9;
        }
        else {
          uVar13 = uVar13 + 0x1000;
        }
        param_3 = param_3 + 2;
        uVar16 = uVar16 + 1;
        puVar6 = puVar6 + 1;
      } while (uVar16 < 5);
      uVar9 = uVar9 + uVar13;
      uVar5 = (ulonglong)((uint)uVar5 + 1);
      *(uint *)(lVar3 + 8) = (uVar13 << 0x10 ^ uVar15) & 0x7fff0000 ^ uVar15;
      uVar13 = local_100;
    } while (uVar9 < uVar17);
    uVar13 = (uint)uVar5;
    plVar8 = &DAT_140016188 + uVar12 * 5;
    if (uVar9 < uVar17) {
      return -0x3fffff66;
    }
    uVar17 = 0;
    if (uVar13 != 0) {
      do {
        if (uVar13 < 2) break;
        uVar17 = uVar17 + 1;
        *(undefined4 *)*plVar8 =
             *(undefined4 *)((&DAT_140016188)[uVar12 * 5 + (ulonglong)uVar17 % uVar5] + 0x40);
        lVar3 = *plVar8;
        plVar8 = plVar8 + 1;
        *(undefined8 *)(lVar3 + 0x58) = (&DAT_140016188)[uVar12 * 5 + (ulonglong)uVar17 % uVar5];
      } while (uVar17 < uVar13);
    }
  }
  plVar8 = &DAT_140016188 + uVar12 * 5;
  *(undefined4 *)(lVar14 + 0xc) = *(undefined4 *)(*plVar8 + 0x40);
  *(undefined4 *)(lVar14 + 0x14) = *(undefined4 *)(*plVar8 + 0x40);
  *(undefined4 *)(lVar14 + 0x10) = *(undefined4 *)(*plVar8 + 0x40);
  *(uint *)(lVar14 + 0x18) = *(uint *)(lVar14 + 0x18) & 0x80008f7d | 0xc00;
  if (uVar13 != 0) {
    uVar12 = (ulonglong)uVar13;
    do {
      lVar14 = *plVar8;
      lVar3 = *plVar8;
      plVar8 = plVar8 + 1;
      *(uint *)(lVar3 + 8) = *(uint *)(lVar14 + 8) | 0x80;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
  }
  iVar4 = EHCIDumpPollForCompletion(local_f0,plVar1);
  if ((-1 < iVar4) && (local_108 != '\0')) {
    memmove(*(void **)(param_2 + 0x28),local_f8,(ulonglong)*(uint *)(param_2 + 0x24));
  }
  return iVar4;
}



===== EHCIDumpControlTransfer @ 1400115a8 =====

int EHCIDumpControlTransfer(longlong param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uStackX_1c;
  
  uVar8 = (undefined4)param_3;
  puVar2 = *(uint **)(param_1 + 0x28);
  uVar1 = *puVar2;
  if (uVar1 == 0xffffffff) {
    iVar5 = -0x3ffffc9a;
  }
  else {
    lVar6 = 4;
    puVar9 = &DAT_140016188;
    puVar11 = DAT_140016188;
    do {
      EHCIDumpInitTD((undefined4 *)*puVar9);
      iVar5 = (int)param_4;
      puVar9 = puVar9 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    *(undefined8 *)(puVar11 + 0x1a) = *(undefined8 *)param_2;
    puVar11[3] = puVar11[0x10] + 0x68;
    puVar11[2] = puVar11[2] & 31999 | 0x80200;
    puVar10 = DAT_140016198;
    EHCIDumpInitTD(DAT_140016198);
    puVar11[1] = puVar10[0x10];
    *(undefined4 **)(puVar11 + 0x18) = puVar10;
    puVar3 = DAT_140016190;
    puVar7 = puVar11;
    if (iVar5 != 0) {
      EHCIDumpInitTD(DAT_140016190);
      *puVar11 = puVar3[0x10];
      *(undefined4 **)(puVar11 + 0x16) = puVar3;
      if (*param_2 < '\0') {
        uVar4 = puVar3[2] & 0xfffffdff | 0x100;
      }
      else {
        uVar4 = puVar3[2] & 0xfffffcff;
      }
      puVar3[2] = iVar5 << 0x10 | uVar4 & 0x7f7f | 0x80000080;
      puVar3[1] = puVar10[0x10];
      uStackX_1c = (undefined4)((ulonglong)param_3 >> 0x20);
      puVar3[8] = uStackX_1c;
      *(undefined4 **)(puVar3 + 0x18) = puVar10;
      puVar3[3] = uVar8;
      puVar7 = puVar3;
    }
    *puVar7 = puVar10[0x10];
    *(undefined4 **)(puVar7 + 0x16) = puVar10;
    puVar10[3] = 0;
    puVar10[0xf] = 0;
    if (*param_2 < '\0') {
      uVar4 = puVar10[2] & 31999 | 0x80000000;
    }
    else {
      uVar4 = puVar10[2] & 0x7dff | 0x80000100;
    }
    puVar10[2] = uVar4;
    *puVar10 = puVar11[0x10];
    *(undefined4 **)(puVar10 + 0x16) = puVar11;
    puVar10[1] = puVar11[0x10];
    *(undefined4 **)(puVar10 + 0x18) = puVar11;
    lVar6 = DumpEndpoint;
    *(undefined4 *)(DumpEndpoint + 0xc) = puVar11[0x10];
    *(undefined4 *)(lVar6 + 0x14) = puVar11[0x10];
    *(undefined4 *)(lVar6 + 0x10) = puVar11[0x10];
    *(uint *)(lVar6 + 0x18) = *(uint *)(lVar6 + 0x18) & 0x8000837d;
    puVar10[2] = puVar10[2] | 0x80;
    puVar11[2] = puVar11[2] | 0x80;
    iVar5 = EHCIDumpPollForCompletion((ulonglong)(uVar1 & 0xff) + (longlong)puVar2,&DumpEndpoint);
  }
  return iVar5;
}



===== EHCIDumpControllerCleanUp @ 140011760 =====

undefined4 EHCIDumpControllerCleanUp(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  
  uVar2 = **(uint **)(param_1 + 0x28);
  if (uVar2 == 0xffffffff) {
    uVar3 = 0xc0000366;
  }
  else {
    puVar4 = (uint *)((ulonglong)(uVar2 & 0xff) + (longlong)*(uint **)(param_1 + 0x28));
    *puVar4 = *puVar4 & 0xffffffbe;
    LOCK();
    UNLOCK();
    uVar2 = 0;
    do {
      uVar1 = puVar4[1];
      if ((uVar1 & 0x1000) != 0) break;
      KeStallExecutionProcessor(0x7d);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x12);
    uVar3 = 0;
    if ((uVar1 & 0x1000) == 0) {
      uVar3 = 0xc0000366;
    }
  }
  return uVar3;
}



===== EHCIDumpControllerInitialize @ 1400117f0 =====

int EHCIDumpControllerInitialize(longlong param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  uVar1 = **(uint **)(param_1 + 0x28);
  if ((uVar1 == 0xffffffff) ||
     (puVar3 = (uint *)((ulonglong)(uVar1 & 0xff) + (longlong)*(uint **)(param_1 + 0x28)),
     (puVar3[1] & 0x10) != 0)) {
    iVar2 = -0x3ffffc9a;
  }
  else {
    puVar3[2] = puVar3[2] & 0xfffffffe;
    LOCK();
    UNLOCK();
    iVar2 = EHCIDumpDisableSchedule(puVar3);
    if (-1 < iVar2) {
      EHCIDumpInitializeQH((longlong)puVar3,param_1);
      iVar2 = EHCIDumpEnableAsyncSchedule(puVar3);
    }
  }
  return iVar2;
}



===== EHCIDumpDisableSchedule @ 140011860 =====

undefined4 EHCIDumpDisableSchedule(uint *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  uVar2 = (ulonglong)param_1[1];
  if ((uVar1 & 0x10) == 0) {
LAB_1400118b7:
    if ((uVar1 & 0x20) == 0) {
LAB_1400118ec:
      *param_1 = uVar1 & 0xffffff8f;
      LOCK();
      UNLOCK();
      uVar4 = 0;
      uVar1 = param_1[1];
      do {
        if (((uVar1 >> 0xf & 1) == 0) && ((uVar1 >> 0xe & 1) == 0)) break;
        KeStallExecutionProcessor(0x19);
        uVar4 = uVar4 + 1;
        uVar1 = param_1[1];
      } while (uVar4 < 40000);
      uVar3 = 0;
      if (uVar4 == 40000) {
        uVar3 = 0xc0000185;
      }
      return uVar3;
    }
    uVar4 = 0;
    do {
      if ((((uint)(uVar2 >> 10) ^ uVar1) & 0x20) == 0) goto LAB_1400118ec;
      KeStallExecutionProcessor(0x19);
      uVar4 = uVar4 + 1;
      uVar1 = *param_1;
      uVar2 = (ulonglong)param_1[1];
    } while (uVar4 < 40000);
  }
  else {
    uVar4 = 0;
    do {
      if ((((uint)uVar2 >> 10 ^ uVar1) & 0x10) == 0) goto LAB_1400118b7;
      KeStallExecutionProcessor(0x19);
      uVar4 = uVar4 + 1;
      uVar1 = *param_1;
      uVar2 = (ulonglong)param_1[1];
    } while (uVar4 < 40000);
  }
  return 0xc0000185;
}



===== EHCIDumpEnableAsyncSchedule @ 14001194c =====

undefined4 EHCIDumpEnableAsyncSchedule(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  uVar4 = param_1[1];
  if ((uVar1 & 0x20) == 0) {
    uVar3 = 0;
    do {
      if (((uVar4 >> 10 ^ uVar1) & 0x20) == 0) goto LAB_1400119a0;
      KeStallExecutionProcessor(0x19);
      uVar3 = uVar3 + 1;
      uVar1 = *param_1;
      uVar4 = param_1[1];
    } while (uVar3 < 40000);
    uVar2 = 0xc0000185;
  }
  else {
LAB_1400119a0:
    *param_1 = uVar1 | 0x60;
    LOCK();
    UNLOCK();
    uVar4 = 0;
    uVar1 = param_1[1];
    do {
      if ((uVar1 >> 0xf & 1) != 0) {
        return 0;
      }
      KeStallExecutionProcessor(0x19);
      uVar4 = uVar4 + 1;
      uVar1 = param_1[1];
    } while (uVar4 < 40000);
    uVar2 = 0;
    if (uVar4 == 40000) {
      uVar2 = 0xc0000185;
    }
  }
  return uVar2;
}



===== EHCIDumpInitTD @ 1400119fc =====

void EHCIDumpInitTD(undefined4 *param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  
  param_1[0xe] = param_1[0xe] | 2;
  puVar1 = param_1 + 8;
  lVar2 = 5;
  do {
    *puVar1 = 0;
    puVar1[-5] = 0xbad0000;
    puVar1 = puVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  *(undefined8 *)(param_1 + 0x16) = 0;
  *param_1 = 1;
  param_1[1] = 1;
  param_1[2] = 0xc00;
  return;
}



===== EHCIDumpInitializeInterface @ 140011a40 =====

undefined8 EHCIDumpInitializeInterface(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(code **)(param_1 + 0x10) = EHCIDumpControllerInitialize;
  *(code **)(param_1 + 0x18) = EHCIDumpUrbSend;
  *(code **)(param_1 + 0x38) = EHCIDumpControllerCleanUp;
  *(code **)(param_1 + 0x30) = EHCIDumpResetDevice;
  return 0;
}



===== EHCIDumpInitializeQH @ 140011a80 =====

void EHCIDumpInitializeQH(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  longlong lVar6;
  undefined4 *puVar7;
  longlong *plVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  uint uVar11;
  longlong lVar12;
  longlong lVar13;
  longlong *plVar14;
  ulonglong uVar15;
  uint *puVar16;
  byte *pbVar17;
  uint uVar18;
  
  puVar10 = &DumpEndpoint;
  memset(&DumpEndpoint,0,200);
  memset(*(void **)(param_2 + 0x10),0,(ulonglong)*(uint *)(param_2 + 0x20));
  puVar5 = *(uint **)(param_2 + 0x10);
  uVar18 = *(uint *)(param_2 + 0x18);
  plVar14 = &DumpEndpoint;
  puVar16 = puVar5 + 0x20;
  lVar12 = 4;
  puVar5[1] = puVar5[1] | 0x8000;
  puVar5[0x11] = uVar18;
  uVar18 = uVar18 + 0x80;
  puVar5[4] = puVar5[4] | 1;
  puVar5[6] = 0x40;
  puVar5[0x12] = 0x71613032;
  puVar5[2] = puVar5[2] & 0x3fffffff | 0x40000000;
  uVar3 = puVar5[0x11];
  uVar11 = 0;
  do {
    *plVar14 = (longlong)puVar16;
    plVar1 = plVar14 + 1;
    puVar16[0x11] = uVar18;
    lVar13 = 4;
    uVar18 = uVar18 + 0x80;
    puVar16 = puVar16 + 0x20;
    *(undefined4 *)(*plVar14 + 0x48) = 0x68713032;
    plVar8 = plVar1;
    do {
      *plVar8 = (longlong)puVar16;
      puVar16[0x10] = uVar18;
      *(undefined4 *)(*plVar8 + 0x34) = 0x64743032;
      lVar6 = *plVar8;
      plVar8 = plVar8 + 1;
      *(undefined8 *)(lVar6 + 0x50) = 0xdeadfacedeadface;
      uVar18 = uVar18 + 0x80;
      puVar16 = puVar16 + 0x20;
      lVar13 = lVar13 + -1;
    } while (lVar13 != 0);
    uVar4 = *(uint *)(*plVar14 + 4);
    *(uint *)(*plVar14 + 4) = (uVar4 ^ *(uint *)(param_2 + 8)) & 0x7f ^ uVar4;
    *(uint *)(*plVar14 + 4) = *(uint *)(*plVar14 + 4) & 0xffffefff | 0x2000;
    *(uint *)(*plVar14 + 8) = *(uint *)(*plVar14 + 8) & 0x3fffffff | 0x40000000;
    *(undefined4 *)(*plVar14 + 0x10) = 1;
    *(undefined4 *)(*plVar14 + 0x14) = 1;
    *(undefined4 *)(*plVar14 + 0x18) = 0;
    if (uVar11 == 0) {
      puVar7 = (undefined4 *)*plVar1;
      lVar13 = 5;
      puVar2 = (uint *)(*plVar14 + 4);
      *puVar2 = *puVar2 | 0x4000;
      *(uint *)(*plVar14 + 4) = *(uint *)(*plVar14 + 4) & 0xf840ffff | 0x400000;
      *(undefined4 *)(*plVar14 + 0xc) = puVar7[0x10];
      *(undefined4 *)(*plVar14 + 0x10) = 1;
      *(undefined4 *)(*plVar14 + 0x14) = 1;
      *(undefined4 *)(*plVar14 + 0x18) = 0;
      *puVar7 = 1;
      puVar7[1] = 1;
      puVar9 = puVar7 + 3;
      *(undefined8 *)(puVar7 + 0x16) = 0;
      *(undefined8 *)(puVar7 + 0x18) = 0;
      puVar7[2] = 0;
      do {
        *puVar9 = puVar7[0x10];
        puVar9 = puVar9 + 1;
        lVar13 = lVar13 + -1;
      } while (lVar13 != 0);
    }
    else {
      puVar2 = (uint *)(*plVar14 + 4);
      *puVar2 = *puVar2 & 0xffffbfff;
      *(uint *)(*plVar14 + 4) = *(uint *)(*plVar14 + 4) & 0xfa00ffff | 0x2000000;
      *(undefined4 *)(*plVar14 + 0xc) = *(undefined4 *)(*plVar1 + 0x40);
      *(undefined4 *)(*plVar14 + 0x10) = *(undefined4 *)(*plVar1 + 0x40);
      *(undefined4 *)(*plVar14 + 0x14) = *(undefined4 *)(*plVar1 + 0x40);
      *(undefined4 *)(*plVar14 + 0x18) = 0;
    }
    uVar11 = uVar11 + 1;
    plVar14 = plVar14 + 5;
  } while (uVar11 < 5);
  uVar15 = 0;
  pbVar17 = (byte *)(param_2 + 0x5c);
  do {
    uVar18 = (int)uVar15 + 1;
    uVar15 = (ulonglong)uVar18;
    if (*pbVar17 != 0) {
      uVar11 = *(uint *)((&DumpEndpoint)[uVar15 * 5] + 4);
      *(uint *)((&DumpEndpoint)[uVar15 * 5] + 4) = ((uint)*pbVar17 << 8 ^ uVar11) & 0xf00 ^ uVar11;
    }
    pbVar17 = pbVar17 + 8;
  } while (uVar18 < 4);
  plVar14 = &DAT_1400161a8;
  *puVar5 = *(uint *)(DumpEndpoint + 0x44) & 0xffffffe3 | 2;
  do {
    lVar13 = *plVar14;
    plVar14 = plVar14 + 5;
    *(undefined4 *)*puVar10 = *(undefined4 *)(lVar13 + 0x44);
    *(uint *)*puVar10 = *(uint *)*puVar10 & 0xffffffe1;
    puVar16 = (uint *)*puVar10;
    puVar10 = puVar10 + 5;
    *puVar16 = *puVar16 | 2;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  uVar18 = puVar5[0x11];
  *DAT_140016220 = uVar18;
  uVar18 = uVar18 & 0xffffffe1;
  *DAT_140016220 = uVar18;
  *DAT_140016220 = uVar18 | 2;
  *(uint *)(param_1 + 0x18) = uVar3 & 0xffffffe3 | 2;
  LOCK();
  UNLOCK();
  return;
}



===== EHCIDumpPollForCompletion @ 140011d70 =====

int EHCIDumpPollForCompletion(longlong param_1,longlong *param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  
  iVar2 = 0;
  lVar3 = 0;
  do {
    param_2 = param_2 + 1;
    if (3 < lVar3) {
      return iVar2;
    }
    iVar4 = 5000000;
    while( true ) {
      uVar1 = *(uint *)(*param_2 + 8);
      if ((param_1 != 0) && ((uVar1 & 0x40) != 0)) {
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffd;
        LOCK();
        UNLOCK();
        return -0x3ffffffc;
      }
      if ((uVar1 & 8) != 0) break;
      if ((uVar1 & 0x10) != 0) {
        iVar2 = -0x3fffffee;
        goto LAB_140011e1d;
      }
      if ((uVar1 & 0x20) != 0) {
        iVar2 = -0x3fffffed;
        goto LAB_140011e1d;
      }
      if ((uVar1 & 4) != 0) break;
      KeStallExecutionProcessor(0x32);
      iVar4 = iVar4 + -0x32;
      if (-1 < (char)uVar1) goto LAB_140011e1d;
      if (iVar4 == 0) {
        return -0x3fffa000;
      }
    }
    iVar2 = -0x3fffffef;
LAB_140011e1d:
    if (iVar4 == 0) {
      return -0x3fffa000;
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    lVar3 = lVar3 + 1;
  } while( true );
}



===== EHCIDumpResetDevice @ 140011e50 =====

int EHCIDumpResetDevice(longlong param_1)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  
  if ((**(int **)(param_1 + 0x28) == -1) || (iVar2 = *(int *)(param_1 + 0x30), iVar2 == 0)) {
    iVar2 = -0x3ffffc9a;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x34 + (ulonglong)(iVar2 - 1) * 4);
    uVar3 = (ulonglong)uVar1;
    if (iVar2 == 1) {
      iVar2 = EHCIDumpResetRHPort(param_1,uVar1);
    }
    else {
      iVar2 = EHCIDumpResetExternalHubPort(param_1,(short)uVar1);
    }
    if (-1 < iVar2) {
      *(uint *)(DumpEndpoint + 4) = *(uint *)(DumpEndpoint + 4) & 0xffffff80;
      iVar2 = UsbDumpResetDevice(param_1,uVar3,(uint *)(DumpEndpoint + 4));
      if (-1 < iVar2) {
        EHCIDumpControllerInitialize(param_1);
      }
    }
  }
  return iVar2;
}



===== EHCIDumpResetExternalHubPort @ 140011ed8 =====

int EHCIDumpResetExternalHubPort(longlong param_1,undefined2 param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  char local_res8 [4];
  undefined2 local_resc;
  undefined2 local_rese;
  
  if (**(int **)(param_1 + 0x28) == -1) {
    iVar3 = -0x3ffffc9a;
  }
  else {
    builtin_strncpy(local_res8,"#\x03\x04",4);
    local_rese = 0;
    *(uint *)(DumpEndpoint + 4) =
         (*(uint *)(DumpEndpoint + 4) ^ *(uint *)(param_1 + 0xc)) & 0x7f ^
         *(uint *)(DumpEndpoint + 4);
    local_resc = param_2;
    iVar3 = EHCIDumpControlTransfer(param_1,local_res8,0,0);
    if (-1 < iVar3) {
      KeStallExecutionProcessor(50000);
      iVar4 = 10;
      do {
        lVar1 = *(longlong *)(param_1 + 0x18);
        local_rese = 4;
        lVar2 = *(longlong *)(param_1 + 0x10);
        local_res8[0] = -0x5d;
        local_res8[1] = '\0';
        local_res8[2] = '\0';
        local_res8[3] = '\0';
        *(undefined4 *)(lVar2 + 0x1000) = 0;
        local_resc = param_2;
        iVar3 = EHCIDumpControlTransfer(param_1,local_res8,lVar1 + 0x1000,4);
        if (iVar3 < 0) goto LAB_140011fec;
        if (((*(byte *)(lVar2 + 0x1000) & 0x10) == 0) &&
           (iVar5 = iVar4, (*(byte *)(lVar2 + 0x1002) & 0x10) != 0)) break;
        KeStallExecutionProcessor(50000);
        iVar5 = iVar4 + -1;
        bVar6 = iVar4 != 0;
        iVar4 = iVar5;
      } while (bVar6);
      if (iVar5 == 0) {
        iVar3 = 0x102;
      }
    }
  }
LAB_140011fec:
  *(uint *)(DumpEndpoint + 4) =
       (*(uint *)(DumpEndpoint + 4) ^ *(uint *)(param_1 + 8)) & 0x7f ^ *(uint *)(DumpEndpoint + 4);
  return iVar3;
}



===== EHCIDumpResetRHPort @ 140012024 =====

undefined4 EHCIDumpResetRHPort(longlong param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  puVar1 = *(uint **)(param_1 + 0x28);
  if (*puVar1 == 0xffffffff) {
    uVar3 = 0xc0000366;
  }
  else {
    uVar4 = *puVar1 & 0xff;
    uVar2 = param_2 - 1;
    *(undefined4 *)((longlong)puVar1 + (ulonglong)uVar2 * 4 + (ulonglong)uVar4 + 0x44) = 0x100;
    LOCK();
    UNLOCK();
    KeStallExecutionProcessor(50000);
    *(undefined4 *)((longlong)puVar1 + (ulonglong)uVar2 * 4 + (ulonglong)uVar4 + 0x44) = 0;
    LOCK();
    UNLOCK();
    KeStallExecutionProcessor(50000);
    uVar3 = 0;
    if ((*(uint *)((longlong)puVar1 + (ulonglong)uVar2 * 4 + (ulonglong)uVar4 + 0x44) >> 8 & 1) != 0
       ) {
      uVar3 = 0xc0000366;
    }
  }
  return uVar3;
}



===== EHCIDumpUrbSend @ 1400120c0 =====

ulonglong EHCIDumpUrbSend(longlong param_1,longlong param_2,ulonglong *param_3)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  longlong *plVar6;
  longlong lVar7;
  char local_res10 [4];
  ushort local_res14;
  undefined2 local_res16;
  
  sVar2 = *(short *)(param_2 + 2);
  uVar5 = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  if (sVar2 == 8) {
    if (param_3 != (ulonglong *)0x0) {
      uVar5 = *param_3;
    }
    iVar4 = EHCIDumpControlTransfer
                      (param_1,(char *)(param_2 + 0x80),uVar5,(ulonglong)*(uint *)(param_2 + 0x24));
    uVar5 = CONCAT44(extraout_var_00,iVar4);
  }
  else if (sVar2 == 9) {
    iVar4 = EHCIDumpBulkTransfer(param_1,param_2,(uint *)param_3);
    uVar5 = CONCAT44(extraout_var,iVar4);
  }
  else if (sVar2 == 0x1e) {
    local_res10[0] = '\x02';
    local_res10[1] = '\x01';
    local_res10[2] = '\0';
    local_res10[3] = '\0';
    local_res16 = 0;
    bVar1 = *(byte *)(*(longlong *)(param_2 + 0x18) + 2);
    local_res14 = (ushort)bVar1;
    uVar3 = EHCIDumpControlTransfer(param_1,local_res10,0,0);
    plVar6 = &DAT_1400161a8;
    lVar7 = 4;
    do {
      if ((bVar1 & 0xf) == (*(uint *)(*plVar6 + 4) >> 8 & 0xf)) {
        *(uint *)(*plVar6 + 0x18) = *(uint *)(*plVar6 + 0x18) & 0x7fffffff;
      }
      plVar6 = plVar6 + 5;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    uVar5 = (ulonglong)uVar3;
  }
  return uVar5;
}



===== UsbDumpResetDevice @ 140012198 =====

void UsbDumpResetDevice(longlong param_1,undefined8 param_2,uint *param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 local_res10;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_res10 = 0x40000001000680;
  *(undefined8 *)(lVar2 + 0x1000) = 0;
  *(undefined8 *)(lVar2 + 0x1008) = 0;
  *(undefined2 *)(lVar2 + 0x1010) = 0;
  KeStallExecutionProcessor(5000);
  iVar3 = EHCIDumpControlTransfer(param_1,(char *)&local_res10,lVar1 + 0x1000,0x40);
  if (-1 < iVar3) {
    local_res10._2_6_ = (uint6)*(ushort *)(param_1 + 8);
    local_res10 = CONCAT62(local_res10._2_6_,0x500);
    KeStallExecutionProcessor(5000);
    iVar3 = EHCIDumpControlTransfer(param_1,(char *)&local_res10,0,0);
    if (-1 < iVar3) {
      *param_3 = *param_3 & 0xffffff80;
      *param_3 = *param_3 | (uint)*(byte *)(param_1 + 8);
      lVar1 = *(longlong *)(param_1 + 0x18);
      lVar2 = *(longlong *)(param_1 + 0x10);
      local_res10 = 0x40000001000680;
      *(undefined8 *)(lVar2 + 0x1000) = 0;
      *(undefined8 *)(lVar2 + 0x1008) = 0;
      *(undefined2 *)(lVar2 + 0x1010) = 0;
      KeStallExecutionProcessor(5000);
      iVar3 = EHCIDumpControlTransfer(param_1,(char *)&local_res10,lVar1 + 0x1000,0x40);
      if (-1 < iVar3) {
        local_res10._2_6_ = (uint6)*(byte *)(param_1 + 0x86);
        local_res10 = CONCAT62(local_res10._2_6_,0x900);
        KeStallExecutionProcessor(5000);
        iVar3 = EHCIDumpControlTransfer(param_1,(char *)&local_res10,0,0);
        if (-1 < iVar3) {
          if (*(byte *)(param_1 + 0x85) != 0) {
            local_res10._0_4_ = CONCAT22((ushort)*(byte *)(param_1 + 0x85),0xb01);
            local_res10 = (ulonglong)
                          CONCAT14(*(undefined1 *)(param_1 + 0x84),(undefined4)local_res10);
            KeStallExecutionProcessor(5000);
            EHCIDumpControlTransfer(param_1,(char *)&local_res10,0,0);
          }
        }
      }
    }
  }
  return;
}



===== __GSHandlerCheck @ 140012368 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001238c =====

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



===== __security_check_cookie @ 140012400 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140012440 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140012470 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140012470. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400124a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140012500 =====

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



===== memset @ 140012800 =====

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



===== __memset_repmovs @ 140012940 =====

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



===== __memset_query @ 1400129c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140012a40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140012b80 =====

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



===== __memset_spec_plain @ 140012c00 =====

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



===== wil_UninitializeFeatureStaging @ 140019008 =====

void wil_UninitializeFeatureStaging(void)

{
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140019060 =====

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
      goto LAB_1400190bd;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1400190bd;
    }
  }
  uVar1 = 0x206;
LAB_1400190bd:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1400190c8 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
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
  ppuVar2 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140019180 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1400191b8 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14001923a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14001923a;
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
LAB_14001923a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140019290 =====

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
      ppuVar3 = &wil_details_featureDescriptors_a;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400192f0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001930c =====

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
  ppuVar3 = &wil_details_featureDescriptors_a;
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



===== wil_RtlStagingConfig_QueryFeatureState @ 1400193c0 =====

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



===== entry @ 14001a010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001a044 =====

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



===== wil_InitializeFeatureStaging @ 14001a078 =====

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
    ppuVar4 = &wil_details_featureDescriptors_a;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001a168 =====

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
  ppuVar3 = &wil_details_featureDescriptors_a;
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


