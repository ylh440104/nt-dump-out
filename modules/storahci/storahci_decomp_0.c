
===== InquiryComplete @ 140001010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 InquiryComplete(longlong *param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  longlong *plVar5;
  undefined1 uVar6;
  uint *puVar7;
  ulonglong uVar8;
  char *pcVar9;
  short *psVar10;
  undefined1 uVar11;
  uint uVar12;
  undefined1 uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  uint *puVar16;
  undefined1 uVar17;
  undefined1 auStack_c8 [32];
  uint local_a8;
  void *local_98;
  longlong *local_90;
  byte local_88 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar14 = 0;
  local_88[0x30] = 0;
  local_88[0x31] = 0;
  local_88[0x32] = 0;
  local_88[0x33] = 0;
  local_88[0x34] = 0;
  local_88[0x35] = 0;
  local_88[0x36] = 0;
  local_88[0x37] = 0;
  local_88[0x38] = 0;
  local_88[0x39] = 0;
  local_88[0x3a] = 0;
  local_88[0x3b] = 0;
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[6] = 0;
  local_88[7] = 0;
  local_88[8] = 0;
  local_88[9] = 0;
  local_88[10] = 0;
  local_88[0xb] = 0;
  local_88[0xc] = 0;
  local_88[0xd] = 0;
  local_88[0xe] = 0;
  local_88[0xf] = 0;
  local_88[0x10] = 0;
  local_88[0x11] = 0;
  local_88[0x12] = 0;
  local_88[0x13] = 0;
  local_88[0x14] = 0;
  local_88[0x15] = 0;
  local_88[0x16] = 0;
  local_88[0x17] = 0;
  local_88[0x18] = 0;
  local_88[0x19] = 0;
  local_88[0x1a] = 0;
  local_88[0x1b] = 0;
  local_88[0x1c] = 0;
  local_88[0x1d] = 0;
  local_88[0x1e] = 0;
  local_88[0x1f] = 0;
  local_88[0x20] = 0;
  local_88[0x21] = 0;
  local_88[0x22] = 0;
  local_88[0x23] = 0;
  local_88[0x24] = 0;
  local_88[0x25] = 0;
  local_88[0x26] = 0;
  local_88[0x27] = 0;
  local_88[0x28] = 0;
  local_88[0x29] = 0;
  local_88[0x2a] = 0;
  local_88[0x2b] = 0;
  local_88[0x2c] = 0;
  local_88[0x2d] = 0;
  local_88[0x2e] = 0;
  local_88[0x2f] = 0;
  if (*(char *)(param_2 + 2) == '(') {
    pcVar9 = (char *)0x0;
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar12 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        puVar16 = (uint *)(param_2 + 0x78);
        do {
          uVar3 = *puVar16;
          if ((0x7f < uVar3) &&
             (uVar15 = (ulonglong)*(uint *)(param_2 + 0x10), uVar3 < *(uint *)(param_2 + 0x10))) {
            iVar4 = *(int *)(param_2 + (ulonglong)uVar3);
            lVar2 = param_2 + (ulonglong)uVar3;
            uVar8 = (ulonglong)uVar3;
            if (iVar4 == 0x40) {
              if (uVar8 + 0x28 <= uVar15) {
                if (*(char *)(lVar2 + 10) != '\0') {
LAB_140001111:
                  pcVar9 = (char *)(lVar2 + 0x18);
                }
                goto LAB_140001115;
              }
            }
            else if (iVar4 == 0x41) {
              if (uVar8 + 0x38 <= uVar15) {
                if (*(char *)(lVar2 + 10) != '\0') goto LAB_140001111;
                local_98 = *(void **)(param_2 + 0x40);
                goto LAB_140001128;
              }
            }
            else if ((iVar4 == 0x42) && (uVar8 + 0x28 <= uVar15)) {
              if (*(int *)(lVar2 + 0xc) == 0) goto LAB_140001115;
              local_98 = *(void **)(param_2 + 0x40);
              pcVar9 = (char *)(lVar2 + 0x20);
              goto LAB_140001128;
            }
          }
          uVar12 = uVar12 + 1;
          puVar16 = puVar16 + 1;
        } while (uVar12 < *(uint *)(param_2 + 0x38));
        local_98 = *(void **)(param_2 + 0x40);
        goto LAB_140001128;
      }
    }
LAB_140001115:
    local_98 = *(void **)(param_2 + 0x40);
  }
  else {
    local_98 = *(void **)(param_2 + 0x18);
    pcVar9 = (char *)(param_2 + 0x48);
  }
LAB_140001128:
  uVar13 = 0;
  uVar11 = 0;
  uVar17 = 0;
  if (((pcVar9 != (char *)0x0) && (*pcVar9 == '\x12')) &&
     (((*(byte *)(param_2 + 3) & 0xf6) != 0 || (*(byte *)(param_2 + 3) == 9)))) {
    return 0xc1000001;
  }
  if ((int)param_1[3] == 6) {
    *(undefined1 *)(param_2 + 3) = 8;
    return 0xc1000001;
  }
  if (*(char *)(param_2 + 2) == '(') {
    if (((*(uint *)(param_2 + 0x34) != 0) &&
        (psVar10 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2),
        psVar10 != (short *)0x0)) && (*psVar10 == 1)) {
      uVar13 = (undefined1)psVar10[4];
      uVar11 = *(undefined1 *)((longlong)psVar10 + 9);
      uVar17 = (undefined1)psVar10[5];
    }
  }
  else {
    uVar13 = *(undefined1 *)(param_2 + 5);
    uVar11 = *(undefined1 *)(param_2 + 6);
    uVar17 = *(undefined1 *)(param_2 + 7);
  }
  *(undefined1 *)(param_2 + 3) = 1;
  local_90 = param_1;
  AtaGenerateInquiryData((longlong)param_1,local_88);
  puVar16 = (uint *)(param_2 + 0x3c);
  puVar1 = (uint *)(param_2 + 0x10);
  if (*(char *)(param_2 + 2) == '(') {
    uVar12 = *puVar16;
  }
  else {
    uVar12 = *puVar1;
  }
  if (uVar12 < 0x3c) {
    puVar7 = puVar16;
    if (*(char *)(param_2 + 2) != '(') {
      puVar7 = puVar1;
    }
    uVar12 = *puVar7;
    if (uVar12 != 0) goto LAB_1400011f7;
    uVar14 = 0xc1000006;
  }
  else {
    uVar12 = 0x3c;
LAB_1400011f7:
    if (local_98 != (void *)0x0) {
      memcpy(local_98,local_88,(ulonglong)uVar12);
      if (*(char *)(param_2 + 2) == '(') {
        *puVar16 = uVar12;
      }
      else {
        *puVar1 = uVar12;
      }
      uVar6 = 1;
      goto LAB_14000122c;
    }
    uVar14 = 0xc1000003;
  }
  uVar6 = 0x30;
LAB_14000122c:
  plVar5 = local_90;
  *(undefined1 *)(param_2 + 3) = uVar6;
  local_a8 = (uint)*(byte *)((longlong)local_90 + 0x274);
  StorPortSetDeviceQueueDepth(*local_90,uVar13,uVar11,uVar17);
  lVar2 = *plVar5;
  StorPortExtendedFunction(0x2e,lVar2,plVar5 + 1,~(*(uint *)(lVar2 + 0x2c) >> 2) & 4);
  return uVar14;
}



===== PortReleaseActiveReference @ 1400012c0 =====

void PortReleaseActiveReference(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = PortPoFxEnabled((longlong)param_1);
  if ((char)uVar1 != '\0') {
    if (param_2 != 0) {
      uVar1 = GetSrbExtension(param_2);
      *(uint *)(uVar1 + 0x1104) = *(uint *)(uVar1 + 0x1104) & 0xfffffbff;
    }
    StorPortExtendedFunction(0x32,*param_1,param_1 + 1);
  }
  return;
}



===== LogPageDiscoveryCompletion @ 140001320 =====

void LogPageDiscoveryCompletion(undefined8 *param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  short sVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined8 *puVar10;
  char cVar11;
  uint uVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  
  uVar6 = GetSrbExtension(param_2);
  cVar11 = *(char *)(uVar6 + 0x110a);
  sVar7 = CONCAT11(*(undefined1 *)(uVar6 + 0x1113),*(char *)(uVar6 + 0x110b));
  puVar10 = param_1;
  if (cVar11 == '\0') {
    if (sVar7 != 0) goto LAB_140001a05;
    if ((*(char *)(param_2 + 3) != '\x01') || (*(short *)param_1[0x3c] != 1)) {
      *(uint *)((longlong)param_1 + 0x16c) = *(uint *)((longlong)param_1 + 0x16c) | 0x20;
      cVar11 = '\x04';
      UpdateQueryLogPageSupportive((longlong)param_1,'\x04',0);
      UpdateQueryLogPageSupportive((longlong)puVar10,cVar11,1);
      cVar11 = '0';
      UpdateQueryLogPageSupportive((longlong)puVar10,'0',0);
      UpdateQueryLogPageSupportive((longlong)puVar10,cVar11,3);
      UpdateQueryLogPageSupportive((longlong)puVar10,cVar11,8);
      UpdateQueryLogPageSupportive((longlong)puVar10,cVar11,9);
      sVar7 = 0;
      UpdateQueryLogPageSupportive((longlong)puVar10,'\x12',0);
      UpdateQueryLogPageSupportive((longlong)puVar10,'\x13',sVar7);
      goto LAB_140001a05;
    }
    sVar7 = ((short *)param_1[0x3c])[4];
    *(uint *)((longlong)param_1 + 0x164) =
         (uint)(sVar7 != 0) | *(uint *)((longlong)param_1 + 0x164) & 0xfffffffe;
    if (sVar7 == 0) {
      cVar11 = '\x04';
      puVar8 = param_1;
      UpdateQueryLogPageSupportive((longlong)param_1,'\x04',0);
      UpdateQueryLogPageSupportive((longlong)puVar8,cVar11,1);
    }
    sVar7 = *(short *)(param_1[0x3c] + 0x60);
    *(uint *)(param_1 + 0x2d) = (uint)(sVar7 != 0) | *(uint *)(param_1 + 0x2d) & 0xfffffffe;
    if (sVar7 == 0) {
      cVar11 = '0';
      puVar8 = param_1;
      UpdateQueryLogPageSupportive((longlong)param_1,'0',0);
      UpdateQueryLogPageSupportive((longlong)puVar8,cVar11,3);
      UpdateQueryLogPageSupportive((longlong)puVar8,cVar11,8);
      UpdateQueryLogPageSupportive((longlong)puVar8,cVar11,9);
    }
    uVar5 = *(uint *)((longlong)param_1 + 0x16c);
    uVar12 = (uint)(*(short *)(param_1[0x3c] + 0x20) != 0);
    *(uint *)((longlong)param_1 + 0x16c) = uVar12 | uVar5 & 0xfffffffe;
    sVar7 = *(short *)(param_1[0x3c] + 0x24);
    uVar4 = 0;
    if (sVar7 != 0) {
      uVar4 = 2;
    }
    *(uint *)((longlong)param_1 + 0x16c) = uVar4 | uVar12 | uVar5 & 0xfffffffc;
    if (sVar7 == 0) {
      UpdateQueryLogPageSupportive((longlong)param_1,'\x12',0);
    }
    sVar7 = *(short *)(param_1[0x3c] + 0x26);
    uVar5 = 0;
    if (sVar7 != 0) {
      uVar5 = 4;
    }
    *(uint *)((longlong)param_1 + 0x16c) = uVar5 | *(uint *)((longlong)param_1 + 0x16c) & 0xfffffffb
    ;
    if (sVar7 == 0) {
      UpdateQueryLogPageSupportive((longlong)param_1,'\x13',0);
    }
    uVar5 = *(uint *)((longlong)param_1 + 0x16c);
    lVar9 = param_1[0x3c];
    uVar4 = 0;
    if (*(short *)(lVar9 + 0x28) != 0) {
      uVar4 = 8;
    }
    *(uint *)((longlong)param_1 + 0x16c) = uVar4 | uVar5 & 0xfffffff7;
    uVar12 = 0;
    if (*(short *)(lVar9 + 0x48) != 0) {
      uVar12 = 0x10;
    }
    *(uint *)((longlong)param_1 + 0x16c) = uVar12 | uVar4 | uVar5 & 0xffffffe7;
    sVar7 = *(short *)(lVar9 + 0x4a);
    uVar14 = 0;
    if (sVar7 != 0) {
      uVar14 = 0x20;
    }
    *(uint *)((longlong)param_1 + 0x16c) = uVar14 | uVar12 | uVar4 | uVar5 & 0xffffffc7;
    if (sVar7 != 0) goto LAB_140001a05;
    sVar7 = 0;
    cVar11 = '%';
  }
  else if (cVar11 == '\x04') {
    if (sVar7 != 0) {
      if (sVar7 == 1) {
        if (*(char *)(param_2 + 3) == *(char *)(uVar6 + 0x110b)) {
          uVar6 = *(ulonglong *)param_1[0x3c];
          if ((((uVar6 & 0xffff) - 1 < 2) && ((char)(uVar6 >> 0x10) == '\x01')) &&
             ((longlong)((ulonglong *)param_1[0x3c])[7] < 0)) {
            *(uint *)(param_1 + 0x2e) = *(uint *)(param_1 + 0x2e) | 0x10;
          }
        }
        else {
          *(uint *)((longlong)param_1 + 0x164) = *(uint *)((longlong)param_1 + 0x164) & 0xfffffffd;
        }
      }
      goto LAB_140001a05;
    }
    if (*(char *)(param_2 + 3) == '\x01') {
      puVar8 = (undefined8 *)param_1[0x3c];
      bVar1 = *(byte *)(puVar8 + 1);
      if ((((short)*puVar8 == 1) && ((char)((ulonglong)*puVar8 >> 0x10) == '\0')) && (1 < bVar1)) {
        pcVar13 = (char *)((longlong)puVar8 + 9);
        for (iVar15 = 1; iVar15 <= (int)(uint)bVar1; iVar15 = iVar15 + 1) {
          uVar5 = *(uint *)((longlong)param_1 + 0x164);
          if (*pcVar13 == '\x01') {
            uVar5 = uVar5 | 2;
            *(uint *)((longlong)param_1 + 0x164) = uVar5;
          }
          if (*pcVar13 == '\x05') {
            *(uint *)((longlong)param_1 + 0x164) = uVar5 | 4;
            break;
          }
          pcVar13 = pcVar13 + 1;
        }
      }
      if ((*(uint *)((longlong)param_1 + 0x164) & 2) != 0) goto LAB_140001a05;
      sVar7 = 1;
      cVar11 = '\x04';
    }
    else {
      *(uint *)((longlong)param_1 + 0x164) = *(uint *)((longlong)param_1 + 0x164) & 0xfffffffe;
      sVar7 = 1;
      cVar11 = '\x04';
    }
  }
  else {
    if (cVar11 != '0') {
      if (cVar11 == '%') {
        if ((sVar7 == 0) && (*(char *)(param_2 + 3) != '\x01')) {
          *(uint *)((longlong)param_1 + 0x16c) = *(uint *)((longlong)param_1 + 0x16c) & 0xffffffdf;
        }
      }
      else if (cVar11 == '\x12') {
        if ((sVar7 == 0) && (*(char *)(param_2 + 3) == '\x01')) {
          lVar9 = param_1[0x3c];
          uVar5 = (*(uint *)(param_1 + 0x2e) ^ *(uint *)(lVar9 + 8)) & 1 ^ *(uint *)(param_1 + 0x2e)
          ;
          *(uint *)(param_1 + 0x2e) = uVar5;
          uVar5 = (*(int *)(lVar9 + 0xc) * 2 ^ uVar5) & 2 ^ uVar5;
          *(uint *)(param_1 + 0x2e) = uVar5;
          *(uint *)(param_1 + 0x2e) = (*(int *)(lVar9 + 0x10) << 2 ^ uVar5) & 4 ^ uVar5;
        }
      }
      else if (((cVar11 == '\x13') && (sVar7 == 0)) && (*(char *)(param_2 + 3) == '\x01')) {
        *(uint *)(param_1 + 0x2e) =
             (*(int *)param_1[0x3c] << 2 ^ *(uint *)(param_1 + 0x2e)) & 8 ^
             *(uint *)(param_1 + 0x2e);
      }
      goto LAB_140001a05;
    }
    if (sVar7 == 0) {
      if (*(char *)(param_2 + 3) == '\x01') {
        puVar8 = (undefined8 *)param_1[0x3c];
        bVar1 = *(byte *)(puVar8 + 1);
        if (((((short)*puVar8 == 1) && ((char)((ulonglong)*puVar8 >> 0x10) == '\0')) && (1 < bVar1))
           && ((ulonglong)bVar1 != 0)) {
          lVar9 = 1;
          do {
            cVar11 = *(char *)((longlong)puVar8 + lVar9 + 8);
            if (cVar11 == '\x03') {
              *(uint *)(param_1 + 0x2d) = *(uint *)(param_1 + 0x2d) | 4;
            }
            else if (cVar11 == '\b') {
              *(uint *)(param_1 + 0x2d) = *(uint *)(param_1 + 0x2d) | 2;
            }
            else if (cVar11 == '\t') {
              *(uint *)(param_1 + 0x2d) = *(uint *)(param_1 + 0x2d) | 8;
            }
            lVar9 = lVar9 + 1;
          } while (lVar9 <= (longlong)(ulonglong)bVar1);
        }
        if ((*(uint *)(param_1 + 0x2d) & 2) != 0) goto LAB_140001a05;
        cVar11 = '0';
        UpdateQueryLogPageSupportive((longlong)param_1,'0',3);
        sVar7 = 8;
      }
      else {
        *(uint *)(param_1 + 0x2d) = *(uint *)(param_1 + 0x2d) & 0xfffffffe;
        cVar11 = '0';
        UpdateQueryLogPageSupportive((longlong)param_1,'0',3);
        UpdateQueryLogPageSupportive((longlong)puVar10,cVar11,8);
        sVar7 = 9;
      }
    }
    else {
      if (sVar7 == 3) {
        if (*(char *)(param_2 + 3) == '\x01') {
          puVar8 = (undefined8 *)param_1[0x3c];
          if (((short)*puVar8 == 1) && ((char)((ulonglong)*puVar8 >> 0x10) == '\x03')) {
            UpdateDownloadMicrocodeSupport((longlong)param_1,(longlong)puVar8);
            if ((longlong)puVar8[0xd] < 0) {
              uVar2 = *(ushort *)(param_1[0x18] + 0x8a);
              if ((uVar2 & 3) == 0) {
                *(ushort *)(param_1[0x18] + 0x8a) = ((ushort)puVar8[0xd] ^ uVar2) & 3 ^ uVar2;
              }
              uVar5 = (uint)puVar8[0xd] & 3;
              if (uVar5 == 1) {
                *(undefined4 *)(param_1 + 3) = 4;
              }
              else if (uVar5 == 2) {
                *(undefined4 *)(param_1 + 3) = 5;
              }
            }
            if ((longlong)puVar8[0xe] < 0) {
              uVar5 = ((int)puVar8[0xe] << 5 ^ *(uint *)(param_1 + 0x2e)) & 0x20 ^
                      *(uint *)(param_1 + 0x2e);
              *(uint *)(param_1 + 0x2e) = uVar5;
              uVar5 = ((int)((ulonglong)puVar8[0xe] >> 1) << 6 ^ uVar5) & 0x40 ^ uVar5;
              *(uint *)(param_1 + 0x2e) = uVar5;
              uVar5 = ((int)((ulonglong)puVar8[0xe] >> 3) << 7 ^ uVar5) & 0x80 ^ uVar5;
              *(uint *)(param_1 + 0x2e) = uVar5;
              uVar5 = ((int)((ulonglong)puVar8[0xe] >> 2) << 8 ^ uVar5) & 0x100 ^ uVar5;
              *(uint *)(param_1 + 0x2e) = uVar5;
              *(uint *)(param_1 + 0x2e) =
                   ((int)((ulonglong)puVar8[0xe] >> 4) << 9 ^ uVar5) & 0x200 ^ uVar5;
            }
          }
        }
        else {
          *(uint *)(param_1 + 0x2d) = *(uint *)(param_1 + 0x2d) & 0xfffffffb;
        }
      }
      else {
        if (sVar7 == 8) {
          if (*(char *)(param_2 + 3) == '\x01') {
            uVar3 = *(undefined8 *)param_1[0x3c];
            if (((short)uVar3 == 1) && ((char)((ulonglong)uVar3 >> 0x10) == '\b')) {
              param_1[0x2f] = ((undefined8 *)param_1[0x3c])[6];
            }
          }
          else {
            *(uint *)(param_1 + 0x2d) = *(uint *)(param_1 + 0x2d) & 0xfffffffd;
          }
          goto LAB_140001a05;
        }
        if (sVar7 != 9) goto LAB_140001a05;
        if (*(char *)(param_2 + 3) == '\x01') {
          puVar8 = (undefined8 *)param_1[0x3c];
          if (((short)*puVar8 == 1) && ((char)((ulonglong)*puVar8 >> 0x10) == '\t')) {
            if ((longlong)puVar8[1] < 0) {
              *(byte *)((longlong)param_1 + 0x1cc) = (byte)puVar8[1] & 1;
            }
            if ((longlong)puVar8[3] < 0) {
              *(int *)((longlong)param_1 + 0x1d4) = (int)puVar8[3];
            }
            if ((longlong)puVar8[4] < 0) {
              *(int *)(param_1 + 0x3b) = (int)puVar8[4];
            }
            if ((longlong)puVar8[5] < 0) {
              *(int *)(param_1 + 0x3a) = (int)puVar8[5];
            }
            if ((longlong)puVar8[6] < 0) {
              *(short *)((longlong)param_1 + 0x1ce) = (short)puVar8[6];
            }
          }
        }
        else {
          *(uint *)(param_1 + 0x2d) = *(uint *)(param_1 + 0x2d) & 0xfffffff7;
        }
      }
      if (*(int *)(param_1 + 3) - 3U < 2) goto LAB_140001a05;
      sVar7 = 9;
      cVar11 = '0';
    }
  }
  UpdateQueryLogPageSupportive((longlong)puVar10,cVar11,sVar7);
LAB_140001a05:
  *(short *)((longlong)param_1 + 0xe2) = *(short *)((longlong)param_1 + 0xe2) + 1;
  uVar6 = GetNextQueryLogPageIndex((longlong)param_1);
  if ((ushort)uVar6 == 0xffff) {
    ReportLunsComplete((longlong)param_1,param_2);
    LOCK();
    *(uint *)(param_1 + 0x4a) = *(uint *)(param_1 + 0x4a) & 0xfbffffff;
    UNLOCK();
    PreserveLogPageInformation(param_1);
    return;
  }
  ReadQueryLogPage((longlong)param_1,param_2,(ushort)uVar6);
  return;
}



===== GetNextQueryLogPageIndex @ 140001a70 =====

ulonglong GetNextQueryLogPageIndex(longlong param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0xe2);
  if (uVar1 < *(ushort *)(param_1 + 0xe0)) {
    for (; uVar1 < *(ushort *)(param_1 + 0xe0); uVar1 = uVar1 + 1) {
      if (*(char *)(param_1 + 0xe4 + (ulonglong)uVar1 * 8) != '\0') {
        *(ushort *)(param_1 + 0xe2) = uVar1;
        return (ulonglong)uVar1;
      }
    }
  }
  return 0xffff;
}



===== UpdateQueryLogPageSupportive @ 140001ac0 =====

void UpdateQueryLogPageSupportive(longlong param_1,char param_2,short param_3)

{
  longlong lVar1;
  ushort uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (*(ushort *)(param_1 + 0xe0) <= uVar2) {
      return;
    }
    lVar1 = param_1 + (ulonglong)uVar2 * 8;
    if ((*(char *)(lVar1 + 0xe5) == param_2) && (*(short *)(lVar1 + 0xe6) == param_3)) break;
    uVar2 = uVar2 + 1;
  }
  *(undefined1 *)(lVar1 + 0xe4) = 0;
  return;
}



===== PreserveLogPageInformation @ 140001b00 =====

void PreserveLogPageInformation(undefined8 *param_1)

{
  int iVar1;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = StorPortExtendedFunction(0x1d,*param_1,local_res8);
  if ((iVar1 == 0) &&
     (iVar1 = StorPortExtendedFunction(0x1e,*param_1,AhciRegistryWriteWorker,local_res8[0],param_1),
     iVar1 == 0)) {
    return;
  }
  if (local_res8[0] != 0) {
    StorPortExtendedFunction(0x1f,*param_1);
  }
  return;
}



===== SmartVersion @ 140001b90 =====

undefined8 SmartVersion(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  uint uVar2;
  longlong lVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar2 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar2 = *(uint *)(param_2 + 0x10);
  }
  if (uVar2 < 0x34) {
    *(undefined1 *)(param_2 + 3) = 6;
    return 0xc1000004;
  }
  if (*(char *)(param_2 + 2) == '(') {
    lVar3 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
  }
  *(undefined2 *)(lVar3 + 0x1c) = 0x101;
  *(undefined1 *)(lVar3 + 0x1e) = 0;
  *(undefined4 *)(lVar3 + 0x20) = 7;
  uVar1 = 0x10;
  if (*(int *)(param_1 + 0x18) != 2) {
    uVar1 = 1;
  }
  *(undefined1 *)(lVar3 + 0x1f) = uVar1;
  *(undefined1 *)(param_2 + 3) = 1;
  return 0;
}



===== FillClippedSGL @ 140001c00 =====

ulonglong FillClippedSGL(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  ulonglong uVar3;
  
  if (((param_1 != (uint *)0x0) && (param_2 != (uint *)0x0)) && (param_4 != 0)) {
    uVar2 = 0;
    uVar1 = 0;
    uVar3 = 0;
    if (*param_1 != 0) {
      do {
        if (param_4 == 0) break;
        if (param_3 == 0) {
          param_2[uVar2 * 6 + 4] = param_1[uVar3 * 6 + 4];
          param_2[uVar2 * 6 + 5] = param_1[uVar3 * 6 + 5];
          uVar1 = param_1[uVar3 * 6 + 6];
          in_RAX = (ulonglong)uVar1;
          param_2[uVar2 * 6 + 6] = uVar1;
          if (uVar1 < param_4) {
            param_4 = param_4 - uVar1;
          }
          else {
            param_2[uVar2 * 6 + 6] = param_4;
            param_4 = 0;
          }
LAB_140001c7e:
          uVar2 = (ulonglong)((int)uVar2 + 1);
        }
        else {
          uVar1 = param_1[uVar3 * 6 + 6];
          in_RAX = (ulonglong)uVar1;
          if (param_3 < uVar1) {
            param_2[uVar2 * 6 + 4] = param_1[uVar3 * 6 + 4] + param_3;
            param_2[uVar2 * 6 + 5] = param_1[uVar3 * 6 + 5];
            uVar1 = param_1[uVar3 * 6 + 6] - param_3;
            in_RAX = (ulonglong)uVar1;
            param_2[uVar2 * 6 + 6] = uVar1;
            if (uVar1 < param_4) {
              param_4 = param_4 - uVar1;
            }
            else {
              param_2[uVar2 * 6 + 6] = param_4;
              param_4 = 0;
            }
            param_3 = 0;
            goto LAB_140001c7e;
          }
          if (param_3 == uVar1) {
            param_3 = 0;
          }
          else {
            param_3 = param_3 - uVar1;
          }
        }
        uVar1 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar1;
      } while (uVar1 < *param_1);
      uVar1 = (uint)uVar2;
    }
    *param_2 = uVar1;
    if (((uVar1 < 0x22) && (param_3 == 0)) && (param_4 == 0)) {
      return CONCAT71((int7)(in_RAX >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== RequestSetDataTransferLength @ 140001cf0 =====

void RequestSetDataTransferLength(longlong param_1,undefined4 param_2)

{
  ulonglong uVar1;
  
  uVar1 = GetSrbExtension(param_1);
  if (*(int *)(uVar1 + 0x1130) == 0) {
    if (*(char *)(param_1 + 2) == '(') {
      *(undefined4 *)(param_1 + 0x3c) = param_2;
      return;
    }
    *(undefined4 *)(param_1 + 0x10) = param_2;
  }
  else {
    *(undefined4 *)(uVar1 + 0x1130) = param_2;
  }
  return;
}



===== ReportLunsComplete @ 140001d30 =====

void ReportLunsComplete(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar9 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar9 = *(uint *)(param_2 + 0x10);
  }
  uVar4 = GetSrbExtension(param_2);
  *(undefined2 *)(uVar4 + 0x1100) = 0;
  *(undefined8 *)(uVar4 + 0x2968) = 0;
  bVar2 = *(byte *)(param_2 + 3);
  if (*(char *)(uVar4 + 0x110e) == '/') {
    if (bVar2 < 2) {
      *(undefined1 *)(param_1 + 0x1f0) = 0x25;
    }
    else {
      *(undefined1 *)(param_1 + 0x1f0) = 0xff;
    }
  }
  else {
    if ((bVar2 & 0xf6) != 0) {
      return;
    }
    if (bVar2 == 9) {
      return;
    }
  }
  *(undefined1 *)(param_2 + 3) = 1;
  if (*(char *)(param_2 + 2) == '(') {
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar5 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        do {
          uVar3 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar5 * 4);
          if ((0x7f < uVar3) && (uVar3 < *(uint *)(param_2 + 0x10))) {
            uVar4 = (ulonglong)uVar3;
            iVar8 = *(int *)((ulonglong)uVar3 + param_2);
            if (iVar8 == 0x42) {
              uVar1 = uVar4 + 0x28;
            }
            else if (iVar8 == 0x40) {
              uVar1 = uVar4 + 0x28;
            }
            else {
              if (iVar8 != 0x41) goto LAB_140001dde;
              uVar1 = uVar4 + 0x38;
            }
            if (uVar1 <= *(uint *)(param_2 + 0x10)) {
              *(undefined1 *)(uVar4 + 8 + param_2) = 0;
              break;
            }
          }
LAB_140001dde:
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_2 + 0x38));
      }
    }
  }
  else {
    *(undefined1 *)(param_2 + 4) = 0;
  }
  if (*(char *)(param_2 + 2) == '(') {
    puVar6 = *(undefined1 **)(param_2 + 0x40);
  }
  else {
    puVar6 = *(undefined1 **)(param_2 + 0x18);
  }
  bVar10 = *(int *)(param_1 + 0x18) != 6;
  iVar8 = (uint)bVar10 * 8;
  uVar7 = (undefined1)iVar8;
  if (uVar9 < iVar8 + 8U) {
    *(undefined1 *)(param_2 + 3) = 0x12;
    if (3 < uVar9) {
      puVar6[3] = uVar7;
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
    }
  }
  else {
    puVar6[3] = uVar7;
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    uVar9 = (uint)bVar10;
    uVar4 = 0;
    if (uVar9 != 0) {
      do {
        puVar6[uVar4 * 8 + 9] = (char)uVar4;
        uVar5 = (int)uVar4 + 1;
        puVar6[uVar4 * 8 + 8] = 0;
        *(undefined4 *)(puVar6 + uVar4 * 8 + 10) = 0;
        *(undefined2 *)(puVar6 + uVar4 * 8 + 0xe) = 0;
        uVar4 = (ulonglong)uVar5;
      } while (uVar5 < uVar9);
    }
  }
  return;
}



===== AtaInitModePageHeaderWrapper @ 140001f20 =====

undefined8
AtaInitModePageHeaderWrapper(char *param_1,undefined1 *param_2,uint param_3,undefined8 *param_4)

{
  char cVar1;
  undefined1 *puVar2;
  longlong lVar3;
  
  if (param_3 != 0) {
    memset(param_2,0,(ulonglong)param_3);
  }
  cVar1 = *param_1;
  *param_4 = param_2;
  if (cVar1 == '\x1a') {
    *(undefined4 *)(param_4 + 1) = 4;
    if (param_3 < 4) {
      return 0xc1000006;
    }
    *param_2 = 3;
    lVar3 = 2;
    puVar2 = param_2;
  }
  else {
    *(undefined4 *)(param_4 + 1) = 8;
    if (param_3 < 8) {
      return 0xc1000006;
    }
    puVar2 = param_2 + 1;
    lVar3 = 3;
    *puVar2 = 6;
  }
  param_4[3] = puVar2;
  param_4[2] = param_2 + lVar3;
  return 0;
}



===== AtaModeSenseRequest @ 140001fd0 =====

undefined8 AtaModeSenseRequest(longlong param_1,longlong param_2,char *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  byte *pbVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 *puVar8;
  uint uVar9;
  char *pcVar10;
  longlong local_28;
  ulonglong uStack_20;
  byte *local_18;
  char *pcStack_10;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = (byte *)0x0;
  pcStack_10 = (char *)0x0;
  lVar7 = param_2;
  pcVar10 = param_3;
  uVar2 = GetSrbExtension(param_2);
  if (*(char *)(lVar7 + 2) == '(') {
    uVar9 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar9 = *(uint *)(param_2 + 0x10);
  }
  if (0x3f < (byte)pcVar10[2]) {
    *(undefined1 *)(param_2 + 3) = 6;
    return 0xc1000006;
  }
  if (*(char *)(lVar7 + 2) == '(') {
    puVar8 = *(undefined1 **)(param_2 + 0x40);
  }
  else {
    puVar8 = *(undefined1 **)(param_2 + 0x18);
  }
  if (puVar8 == (undefined1 *)0x0) {
    *(undefined1 *)(param_2 + 3) = 0x30;
    return 0xc1000003;
  }
  uVar3 = AtaInitModePageHeaderWrapper(param_3,puVar8,uVar9,&local_28);
  if ((int)uVar3 != 0) {
    *(undefined1 *)(param_2 + 3) = 6;
    return uVar3;
  }
  uVar6 = uVar9 - (int)uStack_20;
  if (((param_3[2] & 0x3fU) == 8) || ((param_3[2] & 0x3fU) == 0x3f)) {
    if (uVar6 < 0xc) {
      *(undefined1 *)(param_2 + 3) = 0x12;
    }
    else {
      pbVar5 = (byte *)((uStack_20 & 0xffffffff) + local_28);
      pbVar5[2] = pbVar5[2] & 0xfa;
      pbVar5[1] = 10;
      *pbVar5 = *pbVar5 & 0x40 | 8;
      uVar1 = IsFuaSupported(param_1);
      if ((char)uVar1 != '\0') {
        *local_18 = *local_18 | 0x10;
      }
      uVar6 = uVar6 - 0xc;
      *pcStack_10 = *pcStack_10 + '\f';
      if ((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0xa4) & 0x20) != 0) {
        *(uint *)(uVar2 + 0x1104) = *(uint *)(uVar2 + 0x1104) | 2;
        *(undefined2 *)(uVar2 + 0x1100) = 0x101;
        *(undefined8 *)(uVar2 + 0x1120) = *(undefined8 *)(param_1 + 0xc0);
        *(undefined4 *)(uVar2 + 0x1130) = 0x200;
        *(undefined4 *)(uVar2 + 0x1140) = 1;
        *(undefined4 *)(uVar2 + 0x1150) = *(undefined4 *)(param_1 + 200);
        *(undefined4 *)(uVar2 + 0x1154) = *(undefined4 *)(param_1 + 0xcc);
        *(undefined4 *)(uVar2 + 0x1158) = 0x200;
        *(code **)(uVar2 + 0x2968) = AtaModeSenseRequestCompletionWriteCache;
        *(undefined4 **)(uVar2 + 0x1138) = (undefined4 *)(uVar2 + 0x1140);
        *(undefined1 *)(uVar2 + 0x110e) = 0xec;
        return 0;
      }
    }
  }
  if (*(char *)(param_2 + 2) == '(') {
    *(uint *)(param_2 + 0x3c) = uVar9 - uVar6;
  }
  else {
    *(uint *)(param_2 + 0x10) = uVar9 - uVar6;
  }
  if (((*(byte *)(param_1 + 0x20) & 1) == 0) ||
     (uVar4 = IsMsnEnabled(param_1 + 8), (char)uVar4 == '\0')) {
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
    *(undefined2 *)(uVar2 + 0x1100) = 0x100;
    *(code **)(uVar2 + 0x2968) = AtaModeSenseRequestCompletionMediaStatus;
    *(undefined1 *)(uVar2 + 0x110e) = 0xda;
  }
  return 0;
}



===== IOCTLtoATA @ 1400021f0 =====

ulonglong IOCTLtoATA(longlong *param_1,longlong param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar6 = *(longlong *)(param_2 + 0x40);
    uVar3 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar6 = *(longlong *)(param_2 + 0x18);
    uVar3 = *(uint *)(param_2 + 0x10);
  }
  uVar1 = *(uint *)(lVar6 + 0x10);
  if (uVar1 == 0x1b050c) {
switchD_140002265_caseD_1b0502:
    uVar4 = SmartGeneric(param_1,param_2);
    uVar3 = (uint)uVar4;
  }
  else {
    if (uVar1 == 0x1b0501) {
      uVar5 = SmartIdentifyData(param_1,param_2);
      uVar5 = uVar5 & 0xffffffff;
      goto LAB_1400022ab;
    }
    if (uVar1 < 0x1b0601) {
      if (uVar1 != 0x1b0600) {
        switch(uVar1) {
        case 0x1b0500:
          uVar5 = SmartVersion((longlong)param_1,param_2);
          uVar5 = uVar5 & 0xffffffff;
          goto LAB_1400022ab;
        default:
switchD_140002265_caseD_1b0501:
          *(undefined1 *)(param_2 + 3) = 6;
          uVar5 = 0xc1000006;
          goto LAB_1400022ab;
        case 0x1b0502:
        case 0x1b0503:
        case 0x1b0504:
        case 0x1b0505:
        case 0x1b0506:
        case 0x1b0507:
        case 0x1b0508:
        case 0x1b0509:
        case 0x1b050a:
        case 0x1b050b:
          goto switchD_140002265_caseD_1b0502;
        }
      }
      if (uVar3 < 0x4c) {
        *(undefined1 *)(param_2 + 3) = 0x15;
        uVar5 = 0xc1000004;
        goto LAB_1400022ab;
      }
      if (((ulonglong)uVar3 - 0x4c < (ulonglong)*(uint *)(lVar6 + 0x3c)) ||
         (0x20000 < *(uint *)(lVar6 + 0x3c))) {
        *(undefined4 *)(lVar6 + 0x28) = 2;
        uVar5 = 0xc1000006;
        *(undefined1 *)(param_2 + 3) = 0x15;
        goto LAB_1400022ab;
      }
      if (*(short *)(lVar6 + 0x20) == 0xe0) {
        *(undefined1 *)(param_2 + 3) = 0x22;
        uVar5 = 0xc1000006;
        goto LAB_1400022ab;
      }
      uVar4 = NVCacheGeneric(param_1,param_2);
      uVar3 = (uint)uVar4;
    }
    else if (uVar1 < 0x1b0701) {
      if (uVar1 == 0x1b0700) {
        uVar4 = TelemetryGetSettings((longlong)param_1,param_2);
        uVar3 = (uint)uVar4;
      }
      else {
        if (uVar1 != 0x1b0620) goto switchD_140002265_caseD_1b0501;
        uVar5 = HybridIoctlProcess(param_1,param_2);
        uVar3 = (uint)uVar5;
      }
    }
    else if (uVar1 < 0x1b0722) {
      if (uVar1 == 0x1b0721) {
        uVar5 = DsmGeneralIoctlProcess(param_1,param_2);
        uVar3 = (uint)uVar5;
      }
      else {
        switch(uVar1) {
        case 0x1b0701:
          uVar4 = TelemetrySetHostSettings((longlong)param_1,param_2);
          uVar3 = (uint)uVar4;
          break;
        case 0x1b0702:
          uVar4 = TelemetryWriteDriverLog((longlong)param_1,param_2);
          uVar3 = (uint)uVar4;
          break;
        case 0x1b0703:
          uVar4 = TelemetryWritePublicLog((longlong)param_1,param_2);
          uVar3 = (uint)uVar4;
          break;
        case 0x1b0704:
          uVar4 = TelemetryWritePrivateLog(param_1,param_2);
          uVar3 = (uint)uVar4;
          break;
        case 0x1b0705:
          uVar4 = TelemetryFillCommonHeader((longlong)param_1,param_2);
          uVar3 = (uint)uVar4;
          break;
        case 0x1b0706:
          uVar4 = TelemetryFillHeaders((longlong)param_1,param_2);
          uVar3 = (uint)uVar4;
          break;
        default:
          goto switchD_140002265_caseD_1b0501;
        }
      }
    }
    else if (uVar1 == 0x2d1400) {
      cVar2 = CompareId(0x140029260,8,(char *)(lVar6 + 4),8,(uint *)0x0);
      if (cVar2 != '\0') {
        uVar5 = QueryProtocolInfoIoctlProcess(param_1,param_2);
        uVar5 = uVar5 & 0xffffffff;
        goto LAB_1400022ab;
      }
      cVar2 = CompareId(0x14002b2f0,8,(char *)(lVar6 + 4),8,(uint *)0x0);
      if (cVar2 == '\0') {
        cVar2 = CompareId(0x14002b2e0,8,(char *)(lVar6 + 4),8,(uint *)0x0);
        if (cVar2 == '\0') {
          *(undefined1 *)(param_2 + 3) = 6;
          uVar5 = 0xc1000006;
          goto LAB_1400022ab;
        }
        uVar4 = QueryPhysicalTopologyIoctlProcess((undefined4 *)*param_1,param_2);
        uVar3 = (uint)uVar4;
      }
      else {
        uVar3 = QueryTemperatureInfoIoctlProcess(param_1,param_2);
      }
    }
    else if (uVar1 == 0x1b0780) {
      uVar3 = FirmwareIoctlProcess(param_1,param_2);
    }
    else {
      if (uVar1 != 0x1b0900) goto switchD_140002265_caseD_1b0501;
      uVar4 = DiagGeneric(param_1,param_2);
      uVar3 = (uint)uVar4;
    }
  }
  uVar5 = (ulonglong)uVar3;
LAB_1400022ab:
  StorPortExtendedFunction
            (0x55,*param_1,param_1 + 1,0,0x32,L"IOCTLtoATA finished",0x10,4,0,param_2,L"SrbStatus",
             *(undefined1 *)(param_2 + 3),L"SrbControl",*(undefined4 *)(lVar6 + 0x10));
  return uVar5;
}



===== AtaInquiryRequest @ 140002440 =====

ulonglong AtaInquiryRequest(ulonglong *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  char cVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  int iVar9;
  uint uVar10;
  ulonglong *puVar11;
  int iVar12;
  uint uVar13;
  short *psVar14;
  byte *pbVar15;
  byte bVar16;
  byte bVar17;
  ushort uVar18;
  
  uVar5 = 0;
  if (*(char *)(param_2 + 2) == '(') {
    if (((*(uint *)(param_2 + 0x34) != 0) &&
        (psVar14 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2),
        psVar14 != (short *)0x0)) && (*psVar14 == 1)) {
      cVar3 = (char)psVar14[5];
      goto LAB_140002480;
    }
  }
  else {
    cVar3 = *(char *)(param_2 + 7);
LAB_140002480:
    if (cVar3 != '\0') {
      *(undefined1 *)(param_2 + 3) = 10;
      return 0xc1000006;
    }
  }
  if ((*(byte *)(param_3 + 1) & 1) == 0) {
    uVar5 = *param_1;
    if (*(char *)(uVar5 + 0x18c) != '\0') {
      uVar5 = FUN_140024dfc(uVar5,0,*(uint *)(uVar5 + 0x184));
      return uVar5;
    }
    if ((param_1[4] & 0x10) == 0) {
      uVar5 = InquiryComplete((longlong *)param_1,param_2);
      return uVar5;
    }
    IssueIdentifyCommand((longlong)param_1,param_2);
    return 0;
  }
  if (*(char *)(param_2 + 2) == '(') {
    pbVar15 = *(byte **)(param_2 + 0x40);
    uVar13 = *(uint *)(param_2 + 0x3c);
  }
  else {
    pbVar15 = *(byte **)(param_2 + 0x18);
    uVar13 = *(uint *)(param_2 + 0x10);
  }
  if (pbVar15 == (byte *)0x0) {
switchD_140024e5b_caseD_81:
    *(undefined1 *)(param_2 + 3) = 6;
    uVar5 = 0xc1000006;
  }
  else {
    if (uVar13 != 0) {
      memset(pbVar15,0,(ulonglong)uVar13);
    }
    cVar3 = *(char *)(param_3 + 2);
    if (cVar3 == -0x50) {
      if (0x3f < uVar13) {
        pbVar15[0] = 0;
        pbVar15[1] = 0;
        pbVar15[2] = 0;
        pbVar15[3] = 0;
        pbVar15[4] = 0;
        pbVar15[5] = 0;
        pbVar15[6] = 0;
        pbVar15[7] = 0;
        pbVar15[8] = 0;
        pbVar15[9] = 0;
        pbVar15[10] = 0;
        pbVar15[0xb] = 0;
        pbVar15[0xc] = 0;
        pbVar15[0xd] = 0;
        pbVar15[0xe] = 0;
        pbVar15[0xf] = 0;
        pbVar15[0x10] = 0;
        pbVar15[0x11] = 0;
        pbVar15[0x12] = 0;
        pbVar15[0x13] = 0;
        pbVar15[0x14] = 0;
        pbVar15[0x15] = 0;
        pbVar15[0x16] = 0;
        pbVar15[0x17] = 0;
        pbVar15[0x18] = 0;
        pbVar15[0x19] = 0;
        pbVar15[0x1a] = 0;
        pbVar15[0x1b] = 0;
        pbVar15[0x1c] = 0;
        pbVar15[0x1d] = 0;
        pbVar15[0x1e] = 0;
        pbVar15[0x1f] = 0;
        pbVar15[0x20] = 0;
        pbVar15[0x21] = 0;
        pbVar15[0x22] = 0;
        pbVar15[0x23] = 0;
        pbVar15[0x24] = 0;
        pbVar15[0x25] = 0;
        pbVar15[0x26] = 0;
        pbVar15[0x27] = 0;
        pbVar15[0x28] = 0;
        pbVar15[0x29] = 0;
        pbVar15[0x2a] = 0;
        pbVar15[0x2b] = 0;
        pbVar15[0x2c] = 0;
        pbVar15[0x2d] = 0;
        pbVar15[0x2e] = 0;
        pbVar15[0x2f] = 0;
        pbVar15[0x30] = 0;
        pbVar15[0x31] = 0;
        pbVar15[0x32] = 0;
        pbVar15[0x33] = 0;
        pbVar15[0x34] = 0;
        pbVar15[0x35] = 0;
        pbVar15[0x36] = 0;
        pbVar15[0x37] = 0;
        pbVar15[0x38] = 0;
        pbVar15[0x39] = 0;
        pbVar15[0x3a] = 0;
        pbVar15[0x3b] = 0;
        pbVar15[0x3c] = 0;
        pbVar15[0x3d] = 0;
        pbVar15[0x3e] = 0;
        pbVar15[0x3f] = 0;
        bVar16 = *(byte *)((longlong)param_1 + 0x1c);
        pbVar15[1] = 0xb0;
        *pbVar15 = bVar16 & 0x1f;
        uVar5 = IsDeviceSupportsTrim(param_1);
        if ((char)uVar5 == '\0') {
          pbVar15[3] = 0x3c;
        }
        else {
          uVar5 = param_1[0x11];
          pbVar15[3] = 0x3c;
          iVar12 = (int)uVar5 * 0x40;
          iVar9 = (int)uVar5 * 0x3fffc0;
          pbVar15[0x1b] = (byte)iVar12;
          pbVar15[0x17] = (byte)iVar9;
          pbVar15[0x16] = (byte)((uint)iVar9 >> 8);
          pbVar15[0x15] = (byte)((uint)iVar9 >> 0x10);
          pbVar15[0x1a] = (byte)((uint)iVar12 >> 8);
          pbVar15[0x18] = (byte)((uint)iVar12 >> 0x18);
          pbVar15[0x14] = (byte)((uint)iVar9 >> 0x18);
          pbVar15[0x19] = (byte)((uint)iVar12 >> 0x10);
        }
        *(undefined1 *)(param_2 + 3) = 1;
        return 0;
      }
      if (*(char *)(param_2 + 2) == '(') {
        cVar3 = (*(char *)(param_2 + 3) >> 7 & 0x80U) + 0x12;
      }
      else {
        cVar3 = -0x6e;
        if (-1 < *(char *)(param_2 + 3)) {
          cVar3 = '\x12';
        }
      }
      *(char *)(param_2 + 3) = cVar3;
      if (*(char *)(param_2 + 2) == '(') {
        *(undefined4 *)(param_2 + 0x3c) = 0;
      }
      else {
        *(undefined4 *)(param_2 + 0x10) = 0;
      }
      return 0xc1000004;
    }
    if (cVar3 == '\0') {
      if ((int)param_1[3] - 3U < 2) {
        bVar16 = 9;
      }
      else {
        bVar16 = 8;
      }
      uVar10 = bVar16 + 4;
      if (uVar13 < uVar10) {
        *(undefined1 *)(param_2 + 3) = 6;
        return 0xc1000006;
      }
      bVar17 = *(byte *)((longlong)param_1 + 0x1c);
      pbVar15[1] = 0;
      *pbVar15 = bVar17 & 0x1f;
      pbVar15[3] = bVar16;
      pbVar15[4] = 0;
      pbVar15[5] = 0x80;
      pbVar15[6] = 0x83;
      pbVar15[7] = 0x86;
      pbVar15[8] = 0x89;
      pbVar15[9] = 0xb0;
      pbVar15[10] = 0xb1;
      pbVar15[0xb] = 0xb2;
      if ((int)param_1[3] - 3U < 2) {
        pbVar15[0xc] = 0xb6;
      }
      if (*(char *)(param_2 + 2) == '(') {
        *(uint *)(param_2 + 0x3c) = uVar10;
      }
      else {
        *(uint *)(param_2 + 0x10) = uVar10;
      }
      *(undefined1 *)(param_2 + 3) = 1;
      return 0;
    }
    switch(cVar3) {
    case -0x80:
      if (uVar13 < 0x18) {
        uVar5 = 0xc1000006;
        uVar4 = 6;
      }
      else {
        bVar16 = *(byte *)((longlong)param_1 + 0x1c);
        pbVar15[1] = 0x80;
        *pbVar15 = bVar16 & 0x1f;
        pbVar15[3] = 0x14;
        uVar6 = 0;
        do {
          uVar1 = param_1[0x18];
          bVar16 = (char)uVar6 + 2;
          pbVar15[uVar6 + 5] = *(byte *)(uVar1 + 0x14 + uVar6);
          pbVar15[uVar6 + 4] = *(byte *)(uVar1 + 0x15 + uVar6);
          uVar6 = (ulonglong)bVar16;
        } while (bVar16 < pbVar15[3]);
        iVar9 = pbVar15[3] + 4;
        if (*(char *)(param_2 + 2) == '(') {
          *(int *)(param_2 + 0x3c) = iVar9;
        }
        else {
          *(int *)(param_2 + 0x10) = iVar9;
        }
        uVar4 = 1;
      }
      *(undefined1 *)(param_2 + 3) = uVar4;
      break;
    default:
      goto switchD_140024e5b_caseD_81;
    case -0x7d:
      uVar18 = *(ushort *)(param_1[0x18] + 0xae) & 0x100;
      uVar10 = 0x10;
      if (uVar18 == 0) {
        uVar10 = 0x4c;
      }
      if (uVar13 < uVar10) {
        uVar5 = 0xc1000006;
        uVar4 = 6;
      }
      else {
        if (uVar13 != 0) {
          memset(pbVar15,0,(ulonglong)uVar13);
        }
        pbVar15[0] = 0;
        pbVar15[1] = 0x83;
        if (uVar18 == 0) {
          pbVar15[7] = 0x44;
          pbVar15[8] = 0x20;
          pbVar15[9] = 0x20;
          pbVar15[10] = 0x20;
          pbVar15[4] = 2;
          pbVar15[5] = pbVar15[5] & 0x41 | 1;
          pbVar15[0xb] = 0x20;
          pbVar15[0xc] = 0x20;
          pbVar15[0xd] = 0x41;
          pbVar15[0xe] = 0x54;
          pbVar15[0xf] = 0x41;
          uVar6 = param_1[9];
          *(ulonglong *)(pbVar15 + 0x10) = param_1[8];
          *(ulonglong *)(pbVar15 + 0x18) = uVar6;
          uVar6 = param_1[0xb];
          *(ulonglong *)(pbVar15 + 0x20) = param_1[10];
          *(ulonglong *)(pbVar15 + 0x28) = uVar6;
          *(ulonglong *)(pbVar15 + 0x30) = param_1[0xc];
          uVar2 = *(undefined8 *)((longlong)param_1 + 0x7a);
          *(undefined8 *)(pbVar15 + 0x38) = *(undefined8 *)((longlong)param_1 + 0x72);
          *(undefined8 *)(pbVar15 + 0x40) = uVar2;
          *(undefined4 *)(pbVar15 + 0x48) = *(undefined4 *)((longlong)param_1 + 0x82);
        }
        else {
          pbVar15[4] = 1;
          pbVar15[7] = 8;
          pbVar15[5] = pbVar15[5] & 0x43 | 3;
          bVar16 = (byte)((ushort)*(undefined2 *)(param_1[0x18] + 0xd8) >> 8) & 0xf0;
          pbVar15[8] = pbVar15[8] & 0xf | bVar16;
          pbVar15[8] = *(byte *)(param_1[0x18] + 0xd9) & 0xf | bVar16;
          pbVar15[9] = *(byte *)(param_1[0x18] + 0xd8);
          pbVar15[10] = *(byte *)(param_1[0x18] + 0xdb);
          bVar16 = (byte)(*(ushort *)(param_1[0x18] + 0xda) >> 4);
          pbVar15[0xb] = (pbVar15[0xb] ^ bVar16) & 0xf ^ pbVar15[0xb];
          pbVar15[0xb] = *(char *)(param_1[0x18] + 0xda) << 4 | bVar16 & 0xf;
          pbVar15[0xc] = *(byte *)(param_1[0x18] + 0xdd);
          pbVar15[0xd] = *(byte *)(param_1[0x18] + 0xdc);
          pbVar15[0xe] = *(byte *)(param_1[0x18] + 0xdf);
          pbVar15[0xf] = *(byte *)(param_1[0x18] + 0xde);
        }
        pbVar15[3] = pbVar15[7] + 4;
        uVar4 = 1;
      }
      *(undefined1 *)(param_2 + 3) = uVar4;
      break;
    case -0x7a:
      if (uVar13 < 0xe) {
        uVar5 = 0xc1000006;
        uVar4 = 6;
      }
      else {
        memset(pbVar15,0,(ulonglong)uVar13);
        bVar16 = *(byte *)((longlong)param_1 + 0x1c);
        pbVar15[8] = pbVar15[8] | 2;
        *pbVar15 = bVar16 & 0x1f;
        pbVar15[1] = 0x86;
        pbVar15[2] = 0;
        pbVar15[3] = 0x3c;
        if (((*(byte *)(param_1[0x18] + 0x1ac) & 1) != 0) ||
           ((*(byte *)(param_1[0x18] + 0x8a) & 4) != 0)) {
          pbVar15[6] = pbVar15[6] | 2;
        }
        if ((*(byte *)(param_1[0x18] + 0xaa) & 0x60) != 0) {
          pbVar15[6] = pbVar15[6] | 1;
        }
        uVar4 = 1;
      }
      *(undefined1 *)(param_2 + 3) = uVar4;
      break;
    case -0x77:
      if (uVar13 < 0x23c) {
        uVar5 = 0xc1000006;
        uVar4 = 6;
      }
      else {
        memset(pbVar15,0,0x23c);
        bVar16 = *(byte *)((longlong)param_1 + 0x1c);
        uVar13 = 8;
        pbVar15[1] = 0x89;
        pbVar15[2] = 2;
        *pbVar15 = bVar16 & 0x1f;
        pbVar15[3] = 0x38;
        do {
          if (*(char *)((ulonglong)(uVar13 - 1) + 0x40 + (longlong)param_1) == ' ') break;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
        pbVar15[8] = 0x20;
        pbVar15[9] = 0x20;
        pbVar15[10] = 0x20;
        pbVar15[0xb] = 0x20;
        pbVar15[0xc] = 0x20;
        pbVar15[0xd] = 0x20;
        pbVar15[0xe] = 0x20;
        pbVar15[0xf] = 0x20;
        uVar10 = 0x29;
        if (uVar13 < 0x29) {
          uVar10 = uVar13;
        }
        if (uVar10 - 1 < 8) {
          memcpy(pbVar15 + 8,param_1 + 8,(ulonglong)uVar10);
        }
        pbVar15[0x10] = 0x20;
        pbVar15[0x11] = 0x20;
        pbVar15[0x12] = 0x20;
        pbVar15[0x13] = 0x20;
        pbVar15[0x14] = 0x20;
        pbVar15[0x15] = 0x20;
        pbVar15[0x16] = 0x20;
        pbVar15[0x17] = 0x20;
        pbVar15[0x18] = 0x20;
        uVar13 = 0x29 - uVar10;
        pbVar15[0x19] = 0x20;
        pbVar15[0x1a] = 0x20;
        pbVar15[0x1b] = 0x20;
        pbVar15[0x1c] = 0x20;
        pbVar15[0x1d] = 0x20;
        pbVar15[0x1e] = 0x20;
        pbVar15[0x1f] = 0x20;
        if (0x10 < 0x29 - (ulonglong)uVar10) {
          uVar13 = 0x10;
        }
        memcpy(pbVar15 + 0x10,(void *)((ulonglong)uVar10 + 0x40 + (longlong)param_1),
               (ulonglong)uVar13);
        pbVar15[0x20] = 0x20;
        pbVar15[0x21] = 0x20;
        pbVar15[0x22] = 0x20;
        pbVar15[0x23] = 0x20;
        *(undefined4 *)(pbVar15 + 0x20) = *(undefined4 *)((longlong)param_1 + 0x69);
        lVar7 = IsAtaDevice((uint *)(param_1 + 3));
        bVar16 = 0xec;
        if ((char)lVar7 == '\0') {
          bVar16 = 0xa1;
        }
        pbVar15[0x38] = bVar16;
        lVar7 = 4;
        puVar8 = (undefined8 *)param_1[0x18];
        pbVar15 = pbVar15 + 0x3c;
        do {
          uVar2 = puVar8[1];
          *(undefined8 *)pbVar15 = *puVar8;
          *(undefined8 *)(pbVar15 + 8) = uVar2;
          uVar2 = puVar8[3];
          *(undefined8 *)(pbVar15 + 0x10) = puVar8[2];
          *(undefined8 *)(pbVar15 + 0x18) = uVar2;
          uVar2 = puVar8[5];
          *(undefined8 *)(pbVar15 + 0x20) = puVar8[4];
          *(undefined8 *)(pbVar15 + 0x28) = uVar2;
          uVar2 = puVar8[7];
          *(undefined8 *)(pbVar15 + 0x30) = puVar8[6];
          *(undefined8 *)(pbVar15 + 0x38) = uVar2;
          uVar2 = puVar8[9];
          *(undefined8 *)(pbVar15 + 0x40) = puVar8[8];
          *(undefined8 *)(pbVar15 + 0x48) = uVar2;
          uVar2 = puVar8[0xb];
          *(undefined8 *)(pbVar15 + 0x50) = puVar8[10];
          *(undefined8 *)(pbVar15 + 0x58) = uVar2;
          uVar2 = puVar8[0xd];
          *(undefined8 *)(pbVar15 + 0x60) = puVar8[0xc];
          *(undefined8 *)(pbVar15 + 0x68) = uVar2;
          uVar2 = puVar8[0xf];
          *(undefined8 *)(pbVar15 + 0x70) = puVar8[0xe];
          *(undefined8 *)(pbVar15 + 0x78) = uVar2;
          lVar7 = lVar7 + -1;
          puVar8 = puVar8 + 0x10;
          pbVar15 = pbVar15 + 0x80;
        } while (lVar7 != 0);
        if (*(char *)(param_2 + 2) == '(') {
          *(undefined4 *)(param_2 + 0x3c) = 0x23c;
        }
        else {
          *(undefined4 *)(param_2 + 0x10) = 0x23c;
        }
        uVar4 = 1;
      }
      *(undefined1 *)(param_2 + 3) = uVar4;
      break;
    case -0x4f:
      if (uVar13 < 8) {
        uVar5 = 0xc1000006;
        uVar4 = 6;
      }
      else {
        *pbVar15 = *(byte *)((longlong)param_1 + 0x1c) & 0x1f;
        pbVar15[1] = 0xb1;
        pbVar15[3] = 0x3c;
        pbVar15[4] = *(byte *)(param_1[0x18] + 0x1b3);
        pbVar15[5] = *(byte *)(param_1[0x18] + 0x1b2);
        pbVar15[7] = (pbVar15[7] ^ *(byte *)(param_1[0x18] + 0x150)) & 0xf ^ pbVar15[7];
        if (8 < uVar13) {
          pbVar15[8] = (*(char *)(param_1[0x18] + 0x8a) << 4 ^ pbVar15[8]) & 0x30 ^ pbVar15[8];
        }
        uVar4 = 1;
      }
      *(undefined1 *)(param_2 + 3) = uVar4;
      break;
    case -0x4e:
      if (uVar13 < 8) {
        uVar5 = 0xc1000006;
        uVar4 = 6;
      }
      else {
        bVar16 = *(byte *)((longlong)param_1 + 0x1c);
        pbVar15[1] = 0xb2;
        *pbVar15 = bVar16 & 0x1f;
        pbVar15[3] = 4;
        bVar16 = pbVar15[5];
        pbVar15[5] = bVar16 & 0xfe;
        bVar17 = bVar16 & 0xfc;
        if ((*(ushort *)(param_1[0x18] + 0x8a) >> 0xe & 1) == 0) {
          pbVar15[5] = bVar17;
          bVar16 = bVar16 & 0xf8;
        }
        else {
          puVar11 = param_1;
          uVar6 = IsDeviceSupportsTrim(param_1);
          bVar17 = -((char)uVar6 != '\0') & 2U | bVar17;
          pbVar15[5] = bVar17;
          uVar6 = IsDeviceSupportsTrim(puVar11);
          if (((char)uVar6 == '\0') || ((*(byte *)(param_1[0x18] + 0x8a) & 0x20) == 0)) {
            bVar16 = 0;
          }
          else {
            bVar16 = 4;
          }
          bVar16 = bVar17 & 0xfb | bVar16;
        }
        bVar16 = bVar16 & 0x9f;
        pbVar15[5] = bVar16;
        uVar6 = IsDeviceSupportsTrim(param_1);
        pbVar15[5] = -((char)uVar6 != '\0') & 0x80U | bVar16 & 0x7f;
        if (*(char *)(param_2 + 2) == '(') {
          *(undefined4 *)(param_2 + 0x3c) = 8;
        }
        else {
          *(undefined4 *)(param_2 + 0x10) = 8;
        }
        uVar4 = 1;
      }
      *(undefined1 *)(param_2 + 3) = uVar4;
      break;
    case -0x4a:
      if (uVar13 < 0x14) {
        uVar5 = 0xc1000006;
        uVar4 = 6;
      }
      else {
        memset(pbVar15,0,(ulonglong)uVar13);
        bVar16 = *(byte *)((longlong)param_1 + 0x1c);
        pbVar15[1] = 0xb6;
        pbVar15[2] = 0;
        *pbVar15 = bVar16 & 0x1f;
        pbVar15[3] = 0x3c;
        pbVar15[4] = *(char *)((longlong)param_1 + 0x1cc) != '\0' | pbVar15[4] & 0xfe;
        pbVar15[0xb] = *(byte *)((longlong)param_1 + 0x1d4);
        pbVar15[10] = *(byte *)((longlong)param_1 + 0x1d5);
        pbVar15[9] = *(byte *)((longlong)param_1 + 0x1d6);
        pbVar15[8] = *(byte *)((longlong)param_1 + 0x1d7);
        pbVar15[0xf] = (byte)param_1[0x3b];
        pbVar15[0xe] = *(byte *)((longlong)param_1 + 0x1d9);
        pbVar15[0xd] = *(byte *)((longlong)param_1 + 0x1da);
        pbVar15[0xc] = *(byte *)((longlong)param_1 + 0x1db);
        pbVar15[0x13] = (byte)param_1[0x3a];
        pbVar15[0x12] = *(byte *)((longlong)param_1 + 0x1d1);
        pbVar15[0x11] = *(byte *)((longlong)param_1 + 0x1d2);
        pbVar15[0x10] = *(byte *)((longlong)param_1 + 0x1d3);
        uVar4 = 1;
      }
      *(undefined1 *)(param_2 + 3) = uVar4;
    }
  }
  return uVar5;
}



===== RequestGetSrbScsiData @ 1400026d0 =====

longlong RequestGetSrbScsiData
                   (longlong param_1,uint *param_2,undefined8 param_3,undefined8 *param_4,
                   undefined1 *param_5)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  if (*(char *)(param_1 + 2) == '(') {
    if (*(int *)(param_1 + 0x14) == 0) {
      uVar5 = 0;
      if (*(uint *)(param_1 + 0x38) != 0) {
        do {
          uVar1 = *(uint *)(param_1 + 0x78 + (ulonglong)uVar5 * 4);
          uVar4 = (ulonglong)uVar1;
          if ((0x7f < uVar1) &&
             (uVar6 = (ulonglong)*(uint *)(param_1 + 0x10), uVar1 < *(uint *)(param_1 + 0x10))) {
            iVar2 = *(int *)(uVar4 + param_1);
            lVar7 = uVar4 + param_1;
            if (iVar2 == 0x40) {
              if (uVar4 + 0x28 <= uVar6) {
                if (param_2 != (uint *)0x0) {
                  *(undefined1 *)param_2 = *(undefined1 *)(lVar7 + 10);
                }
                lVar3 = lVar7 + 0x18;
                if (*(char *)(lVar7 + 10) == '\0') {
                  lVar3 = 0;
                }
                if (param_4 != (undefined8 *)0x0) {
                  *param_4 = *(undefined8 *)(lVar7 + 0x10);
                }
                if (param_5 == (undefined1 *)0x0) {
                  return lVar3;
                }
                *param_5 = *(undefined1 *)(lVar7 + 9);
                return lVar3;
              }
            }
            else if (iVar2 == 0x41) {
              if (uVar4 + 0x38 <= uVar6) {
                if (param_2 != (uint *)0x0) {
                  *(undefined1 *)param_2 = *(undefined1 *)(lVar7 + 10);
                }
                lVar3 = lVar7 + 0x18;
                if (*(char *)(lVar7 + 10) == '\0') {
                  lVar3 = 0;
                }
                if (param_4 != (undefined8 *)0x0) {
                  *param_4 = *(undefined8 *)(lVar7 + 0x10);
                }
                if (param_5 == (undefined1 *)0x0) {
                  return lVar3;
                }
                *param_5 = *(undefined1 *)(lVar7 + 9);
                return lVar3;
              }
            }
            else if ((iVar2 == 0x42) && (uVar4 + 0x28 <= uVar6)) {
              if (param_2 != (uint *)0x0) {
                *param_2 = *(uint *)(lVar7 + 0xc);
              }
              lVar3 = lVar7 + 0x20;
              if (*(int *)(lVar7 + 0xc) == 0) {
                lVar3 = 0;
              }
              if (param_4 != (undefined8 *)0x0) {
                *param_4 = *(undefined8 *)(lVar7 + 0x18);
              }
              if (param_5 == (undefined1 *)0x0) {
                return lVar3;
              }
              *param_5 = *(undefined1 *)(lVar7 + 9);
              return lVar3;
            }
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_1 + 0x38));
      }
    }
    else {
      if (param_2 != (uint *)0x0) {
        *param_2 = 0;
      }
      if (param_4 != (undefined8 *)0x0) {
        *param_4 = 0;
      }
      if (param_5 != (undefined1 *)0x0) {
        *param_5 = 0;
      }
    }
  }
  else {
    if (*(char *)(param_1 + 2) == '\0') {
      if (param_2 != (uint *)0x0) {
        *param_2 = (uint)*(byte *)(param_1 + 10);
      }
      lVar7 = param_1 + 0x48;
      if (*(char *)(param_1 + 10) == '\0') {
        lVar7 = 0;
      }
      if (param_4 != (undefined8 *)0x0) {
        *param_4 = *(undefined8 *)(param_1 + 0x20);
      }
      if (param_5 != (undefined1 *)0x0) {
        *param_5 = *(undefined1 *)(param_1 + 0xb);
      }
      return lVar7;
    }
    if (param_2 != (uint *)0x0) {
      *param_2 = 0;
    }
    if (param_4 != (undefined8 *)0x0) {
      *param_4 = 0;
    }
    if (param_5 != (undefined1 *)0x0) {
      *param_5 = 0;
    }
  }
  return 0;
}



===== PortAcquireActiveReference @ 1400028f0 =====

undefined8 PortAcquireActiveReference(undefined8 *param_1,longlong param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
  uVar4 = 0;
  uVar5 = 0;
  uVar3 = PortPoFxEnabled((longlong)param_1);
  if ((char)uVar3 != '\0') {
    iVar2 = StorPortExtendedFunction(0x31,*param_1,param_1 + 1,param_2,0,0);
    if (iVar2 == -0x3efffff4) {
      uVar1 = 1;
    }
    else {
      uVar4 = 0;
      uVar1 = 0;
      if (iVar2 != 0) goto LAB_14000295b;
    }
    uVar4 = uVar1;
    if (param_2 != 0) {
      uVar3 = GetSrbExtension(param_2);
      *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 0x400;
    }
    uVar5 = 1;
  }
LAB_14000295b:
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = uVar4;
  }
  return uVar5;
}



===== PortPoFxEnabled @ 140002990 =====

ulonglong PortPoFxEnabled(longlong param_1)

{
  return CONCAT71((uint7)(*(ulonglong *)(param_1 + 0x250) >> 0x15),
                  (char)(*(ulonglong *)(param_1 + 0x250) >> 0xd)) & 0xffffffffffffff01;
}



===== AtaPassThroughRequest @ 1400029b0 =====

undefined8 AtaPassThroughRequest(longlong param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  uint uVar2;
  longlong lVar3;
  
  lVar3 = param_2;
  uVar1 = GetSrbExtension(param_2);
  if (*(char *)(param_2 + 2) == '(') {
    uVar2 = *(uint *)(param_2 + 0x18);
  }
  else {
    uVar2 = *(uint *)(param_2 + 0xc);
  }
  *(undefined2 *)(uVar1 + 0x1100) = 0x100;
  if ((*(byte *)(param_3 + 2) & 0x20) != 0) {
    *(uint *)(uVar1 + 0x1104) = *(uint *)(uVar1 + 0x1104) | 0x40;
    RequestGetSrbScsiData
              (lVar3,(uint *)0x0,lVar3,(undefined8 *)(uVar1 + 0x2988),(undefined1 *)(uVar1 + 0x2998)
              );
  }
  if ((uVar2 & 0x40) != 0) {
    *(uint *)(uVar1 + 0x1104) = *(uint *)(uVar1 + 0x1104) | 2;
  }
  if ((char)uVar2 < '\0') {
    *(uint *)(uVar1 + 0x1104) = *(uint *)(uVar1 + 0x1104) | 4;
  }
  if ((*(int *)(param_1 + 0x30) == 2) && ((*(byte *)(param_3 + 1) & 1) != 0)) {
    *(uint *)(uVar1 + 0x1104) = *(uint *)(uVar1 + 0x1104) | 8;
  }
  *(undefined1 *)(uVar1 + 0x1108) = *(undefined1 *)(param_3 + 4);
  *(undefined1 *)(uVar1 + 0x1109) = *(undefined1 *)(param_3 + 6);
  *(undefined1 *)(uVar1 + 0x110a) = *(undefined1 *)(param_3 + 8);
  *(undefined1 *)(uVar1 + 0x110b) = *(undefined1 *)(param_3 + 10);
  *(undefined1 *)(uVar1 + 0x110c) = *(undefined1 *)(param_3 + 0xc);
  *(undefined1 *)(uVar1 + 0x110d) = *(undefined1 *)(param_3 + 0xd);
  *(undefined1 *)(uVar1 + 0x110e) = *(undefined1 *)(param_3 + 0xe);
  *(undefined1 *)(uVar1 + 0x1110) = *(undefined1 *)(param_3 + 3);
  *(undefined1 *)(uVar1 + 0x1111) = *(undefined1 *)(param_3 + 5);
  *(undefined1 *)(uVar1 + 0x1112) = *(undefined1 *)(param_3 + 7);
  *(undefined1 *)(uVar1 + 0x1113) = *(undefined1 *)(param_3 + 9);
  *(undefined1 *)(uVar1 + 0x1114) = *(undefined1 *)(param_3 + 0xb);
  *(code **)(uVar1 + 0x2968) = AtaPassThroughRequestCompletion;
  *(undefined2 *)(uVar1 + 0x1115) = 0;
  return 0;
}



===== SmartIdentifyData @ 140002b10 =====

undefined8 SmartIdentifyData(undefined8 *param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar2 = *(uint *)(param_2 + 0x3c);
    lVar6 = *(longlong *)(param_2 + 0x40);
  }
  else {
    uVar2 = *(uint *)(param_2 + 0x10);
    lVar6 = *(longlong *)(param_2 + 0x18);
  }
  if (uVar2 < 0x22c) {
    if (0x2b < uVar2) {
      *(undefined2 *)(lVar6 + 0x20) = 4;
      *(undefined4 *)(lVar6 + 0x1c) = 0;
    }
    *(undefined1 *)(param_2 + 3) = 6;
  }
  else {
    if (*(int *)(param_1 + 3) == 2) {
      *(undefined2 *)(lVar6 + 0x20) = 5;
      *(undefined4 *)(lVar6 + 0x1c) = 0;
      *(undefined1 *)(param_2 + 3) = 6;
      return 0xc1000007;
    }
    uVar3 = GetSrbExtension(param_2);
    uVar8 = 0x200;
    uVar2 = 0x2c;
    *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 2;
    *(undefined2 *)(uVar3 + 0x1100) = 0x101;
    puVar1 = (uint *)(uVar3 + 0x1140);
    *(code **)(uVar3 + 0x2968) = AhciPortSmartCompletion;
    *(undefined8 *)(uVar3 + 0x1108) = 0;
    *(undefined8 *)(uVar3 + 0x1110) = 0;
    *(undefined2 *)(uVar3 + 0x110d) = 0xeca0;
    puVar4 = (uint *)StorPortGetScatterGatherList(*param_1);
    if ((puVar4 != (uint *)0x0) && (puVar1 != (uint *)0x0)) {
      uVar7 = 0;
      uVar10 = 0;
      if (*puVar4 != 0) {
        do {
          if (uVar8 == 0) break;
          if (uVar2 == 0) {
            uVar5 = (ulonglong)uVar7;
            *(uint *)(uVar3 + 0x1150 + uVar5 * 0x18) = puVar4[uVar10 * 6 + 4];
            *(uint *)(uVar3 + 0x1154 + uVar5 * 0x18) = puVar4[uVar10 * 6 + 5];
            uVar9 = puVar4[uVar10 * 6 + 6];
            *(uint *)(uVar3 + 0x1158 + uVar5 * 0x18) = uVar9;
            if (uVar9 < uVar8) {
              uVar8 = uVar8 - uVar9;
            }
            else {
              *(uint *)(uVar3 + 0x1158 + uVar5 * 0x18) = uVar8;
              uVar8 = 0;
            }
LAB_140002c42:
            uVar7 = uVar7 + 1;
          }
          else {
            uVar9 = puVar4[uVar10 * 6 + 6];
            if (uVar2 < uVar9) {
              puVar1[(ulonglong)uVar7 * 6 + 4] = puVar4[uVar10 * 6 + 4] + uVar2;
              puVar1[(ulonglong)uVar7 * 6 + 5] = puVar4[uVar10 * 6 + 5];
              uVar2 = puVar4[uVar10 * 6 + 6] - uVar2;
              puVar1[(ulonglong)uVar7 * 6 + 6] = uVar2;
              if (uVar2 < uVar8) {
                uVar8 = uVar8 - uVar2;
              }
              else {
                puVar1[(ulonglong)uVar7 * 6 + 6] = uVar8;
                uVar8 = 0;
              }
              uVar2 = 0;
              goto LAB_140002c42;
            }
            if (uVar2 == uVar9) {
              uVar2 = 0;
            }
            else {
              uVar2 = uVar2 - uVar9;
            }
          }
          uVar9 = (int)uVar10 + 1;
          uVar10 = (ulonglong)uVar9;
        } while (uVar9 < *puVar4);
      }
      *puVar1 = uVar7;
      if (((uVar7 < 0x22) && (uVar2 == 0)) && (uVar8 == 0)) {
        *(uint **)(uVar3 + 0x1138) = puVar1;
        *(undefined4 *)(uVar3 + 0x1130) = 0x200;
        *(undefined1 *)(param_2 + 3) = 0;
        return 0;
      }
    }
    *(undefined1 *)(param_2 + 3) = 6;
  }
  return 0xc1000004;
}



===== SmartGeneric @ 140002d40 =====

undefined8 SmartGeneric(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  ulonglong uVar3;
  uint *puVar4;
  undefined8 uVar5;
  uint uVar6;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar1 = *(longlong *)(param_2 + 0x40);
    uVar6 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar1 = *(longlong *)(param_2 + 0x18);
    uVar6 = *(uint *)(param_2 + 0x10);
  }
  if (*(char *)(lVar1 + 0x26) != -0x50) goto switchD_140002eb8_caseD_d5;
  uVar3 = GetSrbExtension(param_2);
  if (uVar6 < 0x2c) {
LAB_140002edf:
    uVar5 = 0xc1000004;
LAB_140002ee4:
    *(undefined1 *)(param_2 + 3) = 6;
  }
  else {
    if (uVar6 < 0x3c) {
      *(undefined1 *)(lVar1 + 0x20) = 4;
      *(undefined1 *)(lVar1 + 0x21) = 0;
      *(undefined4 *)(lVar1 + 0x1c) = 0;
      goto LAB_140002edf;
    }
    cVar2 = *(char *)(lVar1 + 0x20);
    if (cVar2 == -0x25) goto switchD_140002eb8_caseD_d2;
    if (cVar2 == -0x2b) {
switchD_140002eb8_caseD_d0:
      *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 2;
      uVar6 = uVar6 - 0x2c;
      puVar4 = (uint *)StorPortGetScatterGatherList(*param_1,param_2);
      uVar5 = FillClippedSGL(puVar4,(uint *)(uVar3 + 0x1140),0x2c,uVar6);
      cVar2 = (char)uVar5;
joined_r0x000140002f3a:
      if (cVar2 == '\0') goto LAB_140002edf;
      *(uint *)(uVar3 + 0x1130) = uVar6;
      *(ulonglong *)(uVar3 + 0x1138) = uVar3 + 0x1140;
      goto switchD_140002eb8_caseD_d2;
    }
    switch(cVar2) {
    case -0x30:
    case -0x2f:
      goto switchD_140002eb8_caseD_d0;
    case -0x2e:
    case -0x2d:
    case -0x28:
    case -0x27:
      break;
    case -0x2c:
      if ((byte)(*(char *)(lVar1 + 0x22) + 0x7fU) < 2) goto switchD_140002eb8_caseD_d5;
      break;
    default:
switchD_140002eb8_caseD_d5:
      uVar5 = 0xc1000007;
      goto LAB_140002ee4;
    case -0x2a:
      *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 4;
      uVar6 = uVar6 - 0x3c;
      puVar4 = (uint *)StorPortGetScatterGatherList(*param_1,param_2);
      uVar5 = FillClippedSGL(puVar4,(uint *)(uVar3 + 0x1140),0x3c,uVar6);
      cVar2 = (char)uVar5;
      goto joined_r0x000140002f3a;
    case -0x26:
      *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 0x40;
      *(longlong *)(uVar3 + 0x2988) = lVar1 + 0x2c;
      *(undefined4 *)(uVar3 + 0x2998) = 8;
    }
switchD_140002eb8_caseD_d2:
    *(undefined2 *)(uVar3 + 0x1100) = 0x105;
    *(code **)(uVar3 + 0x2968) = AhciPortSmartCompletion;
    *(undefined8 *)(uVar3 + 0x1108) = 0;
    *(undefined8 *)(uVar3 + 0x1110) = 0;
    *(undefined1 *)(uVar3 + 0x1108) = *(undefined1 *)(lVar1 + 0x20);
    *(undefined1 *)(uVar3 + 0x1109) = *(undefined1 *)(lVar1 + 0x21);
    *(undefined1 *)(uVar3 + 0x110a) = *(undefined1 *)(lVar1 + 0x22);
    *(undefined1 *)(uVar3 + 0x110b) = *(undefined1 *)(lVar1 + 0x23);
    *(undefined1 *)(uVar3 + 0x110c) = *(undefined1 *)(lVar1 + 0x24);
    *(byte *)(uVar3 + 0x110d) = *(byte *)(lVar1 + 0x25) & 0xf | 0xa0;
    *(undefined1 *)(uVar3 + 0x110e) = *(undefined1 *)(lVar1 + 0x26);
    uVar5 = 0;
    *(undefined1 *)(param_2 + 3) = 0;
  }
  return uVar5;
}



===== DeviceProcessTrimRequest @ 140002f70 =====

void DeviceProcessTrimRequest(undefined8 *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  void *_Dst;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  uint uVar14;
  uint local_res10;
  int local_res18;
  ulonglong local_res20;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar10 = *(ulonglong *)(param_2 + 0x68);
  }
  else {
    uVar10 = *(ulonglong *)(param_2 + 0x38);
  }
  if ((uVar10 & 0x7f) != 0) {
    uVar10 = (uVar10 - ((uint)uVar10 & 0x7f)) + 0x80;
  }
  plVar2 = *(longlong **)(uVar10 + 0x2970);
  uVar9 = 0;
  _Dst = *(void **)(uVar10 + 0x1120);
  if ((1 < *(byte *)(param_2 + 3)) || (*(uint *)(plVar2 + 2) <= *(uint *)(plVar2 + 3))) {
    if (_Dst != (void *)0x0) {
      StorPortExtendedFunction
                (0x53,*param_1,_Dst,*(undefined4 *)((longlong)plVar2 + 0x14),1,
                 *(undefined8 *)(uVar10 + 0x1128));
    }
    if (plVar2 != (longlong *)0x0) {
      StorPortExtendedFunction(1,*param_1,plVar2);
    }
    *(undefined8 *)(uVar10 + 0x1120) = 0;
    *(undefined8 *)(uVar10 + 0x2970) = 0;
    *(undefined8 *)(uVar10 + 0x2968) = 0;
    *(undefined2 *)(uVar10 + 0x1100) = 0;
    return;
  }
  if (*(uint *)((longlong)plVar2 + 0x14) != 0) {
    memset(_Dst,0,(ulonglong)*(uint *)((longlong)plVar2 + 0x14));
  }
  uVar6 = *(uint *)(plVar2 + 2) - *(uint *)(plVar2 + 3);
  uVar14 = *(uint *)((longlong)plVar2 + 0xc);
  if (uVar6 < *(uint *)((longlong)plVar2 + 0xc)) {
    uVar14 = uVar6;
  }
  uVar14 = (uVar14 * 8 - 1 & 0xfffffe00) + 0x200;
  if (*(uint *)(plVar2 + 3) < *(uint *)(plVar2 + 2)) {
    do {
      local_res18 = CONCAT31(CONCAT21(CONCAT11((char)plVar2[5],
                                               *(undefined1 *)((longlong)plVar2 + 0x29)),
                                      *(undefined1 *)((longlong)plVar2 + 0x2a)),
                             *(undefined1 *)((longlong)plVar2 + 0x2b));
      if (local_res18 == 0) {
        plVar1 = (longlong *)(*plVar2 + (ulonglong)*(uint *)((longlong)plVar2 + 0x1c) * 0x10);
        lVar3 = *plVar1;
        lVar4 = plVar1[1];
        *(uint *)((longlong)plVar2 + 0x1c) = *(uint *)((longlong)plVar2 + 0x1c) + 1;
        plVar2[4] = lVar3;
        plVar2[5] = lVar4;
      }
      uVar13 = 0;
      uVar6 = 0;
      bVar7 = *(byte *)((longlong)plVar2 + 0x2b);
      bVar5 = *(byte *)((longlong)plVar2 + 0x27);
      uVar11 = (ulonglong)bVar5;
      local_res10 = CONCAT31(CONCAT21(CONCAT11((char)plVar2[5],
                                               *(undefined1 *)((longlong)plVar2 + 0x29)),
                                      *(undefined1 *)((longlong)plVar2 + 0x2a)),bVar7);
      local_res20 = CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11((char)plVar2[4],
                                                                                   *(undefined1 *)
                                                                                    ((longlong)
                                                                                     plVar2 + 0x21))
                                                                          ,*(undefined1 *)
                                                                            ((longlong)plVar2 + 0x22
                                                                            )),
                                                                 *(undefined1 *)
                                                                  ((longlong)plVar2 + 0x23)),
                                                        *(undefined1 *)((longlong)plVar2 + 0x24)),
                                               *(undefined1 *)((longlong)plVar2 + 0x25)),
                                      *(undefined1 *)((longlong)plVar2 + 0x26)),bVar5);
      if (local_res10 != 0) {
        uVar6 = (uint)bVar7;
        while( true ) {
          bVar7 = (byte)uVar6;
          bVar5 = (byte)uVar11;
          uVar6 = (uint)uVar13;
          uVar12 = uVar13 * 8;
          uVar11 = local_res20;
          if (uVar14 - (int)uVar9 <= uVar12) break;
          uVar8 = local_res10;
          if (0xffff < local_res10) {
            uVar8 = 0xffff;
          }
          local_res10 = local_res10 - uVar8;
          uVar6 = uVar6 + 1;
          uVar13 = (ulonglong)uVar6;
          uVar11 = local_res20 + uVar8;
          *(ulonglong *)((longlong)_Dst + uVar12 + uVar9) =
               local_res20 & 0xffffffffffff |
               *(ulonglong *)((longlong)_Dst + uVar12 + uVar9) & 0xffff000000000000;
          *(short *)((longlong)_Dst + uVar12 + 6 + uVar9) = (short)uVar8;
          if (local_res10 == 0) {
            bVar5 = (byte)uVar11;
            bVar7 = 0;
            break;
          }
          local_res20 = uVar11;
          uVar6 = local_res10;
        }
        local_res20 = uVar11;
      }
      *(byte *)((longlong)plVar2 + 0x27) = bVar5;
      uVar8 = (int)uVar9 + uVar6 * 8;
      uVar9 = (ulonglong)uVar8;
      *(char *)((longlong)plVar2 + 0x26) = (char)(local_res20 >> 8);
      *(char *)((longlong)plVar2 + 0x25) = (char)(local_res20 >> 0x10);
      *(char *)((longlong)plVar2 + 0x24) = (char)(local_res20 >> 0x18);
      *(char *)((longlong)plVar2 + 0x23) = (char)(local_res20 >> 0x20);
      *(char *)((longlong)plVar2 + 0x22) = (char)(local_res20 >> 0x28);
      *(char *)((longlong)plVar2 + 0x21) = (char)(local_res20 >> 0x30);
      *(char *)((longlong)plVar2 + 0x2a) = (char)(local_res10 >> 8);
      *(char *)(plVar2 + 4) = (char)(local_res20 >> 0x38);
      *(char *)((longlong)plVar2 + 0x29) = (char)(local_res10 >> 0x10);
      *(byte *)((longlong)plVar2 + 0x2b) = bVar7;
      *(char *)(plVar2 + 5) = (char)(local_res10 >> 0x18);
      uVar6 = (int)plVar2[3] + uVar6;
      *(uint *)(plVar2 + 3) = uVar6;
    } while ((uVar8 != uVar14) && (uVar6 < *(uint *)(plVar2 + 2)));
    *(undefined2 *)(uVar10 + 0x1100) = 0x100;
    *(void **)(uVar10 + 0x1120) = _Dst;
    *(uint *)(uVar10 + 0x1130) = uVar14;
    *(undefined8 *)(uVar10 + 0x1109) = 0;
    *(undefined4 *)(uVar10 + 0x1111) = 0;
    *(undefined2 *)(uVar10 + 0x1115) = 0;
    *(undefined1 *)(uVar10 + 0x1117) = 0;
    *(char *)(uVar10 + 0x1109) = (char)(uVar14 >> 9);
    *(char *)(uVar10 + 0x1111) = (char)((uVar14 >> 9) >> 8);
    *(code **)(uVar10 + 0x2968) = DeviceProcessTrimRequest;
    *(longlong **)(uVar10 + 0x2970) = plVar2;
    *(uint *)(uVar10 + 0x1158) = uVar14;
    *(undefined1 *)(uVar10 + 0x1108) = 1;
    *(undefined2 *)(uVar10 + 0x110d) = 0x6e0;
  }
  return;
}



===== AtaReadCapacityRequest @ 140003340 =====

ulonglong AtaReadCapacityRequest(ulonglong *param_1,longlong param_2,char *param_3,int param_4)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  uVar2 = GetSrbExtension(param_2);
  if (*(char *)(param_2 + 2) == '(') {
    uVar1 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x10);
  }
  if (7 < uVar1) {
    if (param_4 != 0x10) {
LAB_140003373:
      if ((param_1[4] & 1) == 0) {
        uVar2 = AtaReadCapacityCompletion(param_1,param_2);
        return uVar2;
      }
      *(uint *)(uVar2 + 0x1104) = *(uint *)(uVar2 + 0x1104) | 2;
      *(undefined2 *)(uVar2 + 0x1100) = 0x101;
      *(ulonglong *)(uVar2 + 0x1120) = param_1[0x18];
      *(code **)(uVar2 + 0x2968) = AtaReadCapacityRequestCompletion;
      *(undefined4 *)(uVar2 + 0x1130) = 0x200;
      *(undefined4 *)(uVar2 + 0x1140) = 1;
      *(int *)(uVar2 + 0x1150) = (int)param_1[0x19];
      *(undefined4 *)(uVar2 + 0x1154) = *(undefined4 *)((longlong)param_1 + 0xcc);
      *(undefined4 *)(uVar2 + 0x1158) = 0x200;
      *(undefined4 **)(uVar2 + 0x1138) = (undefined4 *)(uVar2 + 0x1140);
      *(undefined1 *)(uVar2 + 0x110e) = 0xec;
      return uVar3 & 0xffffffff;
    }
    if (0xb < uVar1) {
      if ((*param_3 != -0x62) || ((param_3[1] & 0x1fU) == 0x10)) goto LAB_140003373;
      uVar2 = 0xc1000007;
      goto LAB_140003391;
    }
  }
  uVar2 = 0xc1000004;
LAB_140003391:
  *(undefined1 *)(param_2 + 3) = 6;
  return uVar2;
}



===== AtaUnmapRequest @ 140003450 =====

int AtaUnmapRequest(ulonglong *param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  int unaff_R14D;
  uint local_res10;
  longlong *local_res18;
  undefined8 local_res20;
  longlong **pplVar9;
  undefined4 uVar10;
  longlong local_48 [2];
  
  lVar8 = param_2;
  uVar3 = GetSrbExtension(param_2);
  local_res18 = (longlong *)0x0;
  local_48[0] = 0;
  if (*(char *)(lVar8 + 2) == '(') {
    lVar7 = *(longlong *)(lVar8 + 0x40);
    uVar6 = *(uint *)(lVar8 + 0x3c);
  }
  else {
    lVar7 = *(longlong *)(lVar8 + 0x18);
    uVar6 = *(uint *)(lVar8 + 0x10);
  }
  local_res20 = 0;
  if (lVar7 == 0) {
    *(undefined1 *)(lVar8 + 3) = 6;
    return unaff_R14D;
  }
  uVar1 = CONCAT11(*(undefined1 *)(lVar7 + 2),*(undefined1 *)(lVar7 + 3));
  local_res10 = (uint)uVar1;
  uVar4 = IsDeviceSupportsTrim(param_1);
  if (((char)uVar4 == '\0') || (uVar6 < local_res10 + 8)) {
    *(undefined1 *)(param_2 + 3) = 6;
    return unaff_R14D;
  }
  pplVar9 = &local_res18;
  iVar2 = StorPortExtendedFunction(0,*param_1,0x30,0x69636841,pplVar9);
  uVar10 = (undefined4)((ulonglong)pplVar9 >> 0x20);
  if ((iVar2 == 0) && (local_res18 != (longlong *)0x0)) {
    *local_res18 = 0;
    local_res18[1] = 0;
    local_res18[2] = 0;
    local_res18[3] = 0;
    local_res18[4] = 0;
    local_res18[5] = 0;
    *local_res18 = lVar7 + 8;
    *(uint *)(local_res18 + 1) = (uint)(uVar1 >> 4);
    uVar6 = (uint)param_1[0x11] & 0x7fffff;
    *(uint *)((longlong)local_res18 + 0xc) = uVar6 << 6;
    if (uVar6 == 0) {
      *(undefined1 *)(param_2 + 3) = 6;
      goto LAB_140003717;
    }
    uVar6 = 0;
    if ((int)local_res18[1] != 0) {
      do {
        lVar8 = (ulonglong)uVar6 * 0x10 + *local_res18;
        local_res10 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar8 + 8),
                                                 *(undefined1 *)(lVar8 + 9)),
                                        *(undefined1 *)(lVar8 + 10)),*(undefined1 *)(lVar8 + 0xb));
        if (local_res10 != 0) {
          *(uint *)(local_res18 + 2) = (int)local_res18[2] + (local_res10 - 1) / 0xffff + 1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(local_res18 + 1));
    }
    uVar6 = *(uint *)((longlong)local_res18 + 0xc);
    if (*(uint *)(local_res18 + 2) < *(uint *)((longlong)local_res18 + 0xc)) {
      uVar6 = *(uint *)(local_res18 + 2);
    }
    iVar2 = (uVar6 * 8 - 1 & 0xfffffe00) + 0x200;
    *(int *)((longlong)local_res18 + 0x14) = iVar2;
    if (iVar2 == 0) {
      *(undefined1 *)(param_2 + 3) = 1;
      return unaff_R14D;
    }
    uVar4 = *param_1;
    if ((*(int *)(uVar4 + 0x1a8) < 0) && ((*(uint *)(uVar4 + 0x38) & 0x800) != 0)) {
      uVar5 = 0x7fffffffffffffff;
    }
    else {
      uVar5 = 0x7fffffff;
    }
    iVar2 = StorPortExtendedFunction(0x52,uVar4,iVar2,0,uVar5,0,1,0x80000000,local_48,&local_res20);
    uVar10 = (undefined4)((ulonglong)uVar5 >> 0x20);
    if ((iVar2 == 0) && (local_48[0] != 0)) {
      *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 4;
      *(undefined2 *)(uVar3 + 0x1100) = 0x100;
      *(longlong *)(uVar3 + 0x1120) = local_48[0];
      *(undefined8 *)(uVar3 + 0x1128) = local_res20;
      *(undefined4 *)(uVar3 + 0x1130) = *(undefined4 *)((longlong)local_res18 + 0x14);
      *(undefined4 *)(uVar3 + 0x1140) = 1;
      *(longlong **)(uVar3 + 0x2970) = local_res18;
      *(undefined4 *)(uVar3 + 0x1150) = (undefined4)local_res20;
      *(undefined4 *)(uVar3 + 0x1154) = local_res20._4_4_;
      *(undefined4 *)(uVar3 + 0x1158) = *(undefined4 *)((longlong)local_res18 + 0x14);
      *(undefined4 **)(uVar3 + 0x1138) = (undefined4 *)(uVar3 + 0x1140);
      DeviceProcessTrimRequest(param_1,param_2);
      return unaff_R14D;
    }
    *(undefined1 *)(param_2 + 3) = 6;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 6;
  }
  if (iVar2 == 0) {
  }
LAB_140003717:
  if (local_48[0] != 0) {
    StorPortExtendedFunction
              (0x53,*param_1,local_48[0],*(undefined4 *)((longlong)local_res18 + 0x14),
               CONCAT44(uVar10,1),local_res20);
  }
  if (local_res18 != (longlong *)0x0) {
    StorPortExtendedFunction(1,*param_1);
  }
  return unaff_R14D;
}



===== IsDeviceSupportsTrim @ 1400037b0 =====

ulonglong IsDeviceSupportsTrim(ulonglong *param_1)

{
  if ((char)*(undefined4 *)(*param_1 + 0x38) < '\0') {
    return *param_1 & 0xffffffffffffff00;
  }
  return (ulonglong)(*(byte *)(param_1[0x18] + 0x152) & 1);
}



===== GetSrbExtension @ 1400037e0 =====

ulonglong GetSrbExtension(longlong param_1)

{
  ulonglong uVar1;
  
  if (*(char *)(param_1 + 2) == '(') {
    uVar1 = *(ulonglong *)(param_1 + 0x68);
  }
  else {
    uVar1 = *(ulonglong *)(param_1 + 0x38);
  }
  if ((uVar1 & 0x7f) != 0) {
    uVar1 = (uVar1 - ((uint)uVar1 & 0x7f)) + 0x80;
  }
  return uVar1;
}



===== AhciHwStartIo @ 140003810 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AhciHwStartIo(uint *param_1,longlong *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  uint *puVar6;
  undefined1 uVar7;
  bool bVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined8 *puVar13;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  uint *puVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  undefined8 *puVar17;
  short *psVar18;
  ulonglong uVar19;
  longlong lVar20;
  byte bVar21;
  byte bVar22;
  undefined4 *puVar23;
  longlong lVar24;
  wchar_t *pwVar25;
  ulonglong uVar26;
  longlong lVar27;
  undefined1 auStack_2d8 [32];
  undefined2 **local_2b8;
  wchar_t *local_2b0;
  undefined8 local_2a8;
  undefined4 local_2a0;
  undefined4 local_298;
  longlong *local_290;
  wchar_t *local_288;
  ulonglong local_280;
  wchar_t *local_278;
  ulonglong local_270;
  wchar_t *local_268;
  ulonglong local_260;
  wchar_t *local_258;
  ulonglong local_250;
  wchar_t *pwStack_248;
  ulonglong uStack_240;
  wchar_t *pwStack_238;
  ulonglong uStack_230;
  wchar_t *pwStack_228;
  ulonglong uStack_220;
  wchar_t *pwStack_218;
  ulonglong uStack_210;
  undefined2 *local_208;
  undefined8 *local_200;
  longlong local_1f8;
  undefined8 *puStack_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined1 auStack_1c0 [32];
  undefined8 uStack_1a0;
  undefined1 local_188 [32];
  undefined8 uStack_168;
  undefined1 auStack_160 [32];
  undefined8 uStack_140;
  undefined1 auStack_138 [32];
  undefined8 uStack_118;
  undefined1 auStack_110 [32];
  ulonglong uStack_f0;
  undefined1 auStack_e8 [32];
  undefined8 uStack_c8;
  undefined1 auStack_c0 [32];
  undefined8 uStack_a0;
  undefined1 auStack_98 [32];
  ulonglong uStack_78;
  undefined1 auStack_70 [32];
  undefined2 *puStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_2d8;
  bVar22 = *(byte *)((longlong)param_2 + 2);
  local_1e8 = 3;
  local_1e0 = 0;
  local_1d8 = 0;
  uStack_1d0 = 0;
  if (bVar22 == 0x28) {
    bVar21 = 0;
    uVar11 = *(uint *)((longlong)param_2 + 0x14);
    if (((*(uint *)((longlong)param_2 + 0x34) != 0) &&
        (psVar18 = (short *)((ulonglong)*(uint *)((longlong)param_2 + 0x34) + (longlong)param_2),
        psVar18 != (short *)0x0)) && (*psVar18 == 1)) {
      bVar21 = *(byte *)(psVar18 + 4);
    }
  }
  else {
    bVar21 = *(byte *)((longlong)param_2 + 5);
    uVar11 = (uint)bVar22;
  }
  local_208 = (undefined2 *)((ulonglong)local_208 & 0xffffffff00000000);
  uVar16 = 0;
  switch(uVar11) {
  case 2:
    if (bVar22 == 0x28) {
      uVar10 = *(uint *)(param_2 + 3);
    }
    else {
      uVar10 = *(uint *)((longlong)param_2 + 0xc);
    }
    if (((uVar10 & 1) == 0) ||
       (uVar15 = AdapterProcessIOCTL(param_1,(longlong)param_2), (char)uVar15 == '\0'))
    goto switchD_140003bfd_caseD_3;
    break;
  default:
    goto switchD_140003bfd_caseD_3;
  case 8:
    *(undefined1 *)((longlong)param_2 + 3) = 1;
    break;
  case 0x24:
    if ((bVar22 == 0x28) && (*(uint *)(param_2 + 7) != 0)) {
      uVar16 = FUN_140025601(0,&IMAGE_DOS_HEADER_140000000,*(uint *)(param_2 + 7));
      return uVar16;
    }
    if ((bRam0000000000000008 & 1) != 0) {
      uVar7 = switchD_140003bfd::caseD_8();
      return CONCAT71(extraout_var_00,uVar7);
    }
switchD_140003bfd_caseD_3:
    if (((uint)bVar21 <= param_1[0x61]) &&
       (*(longlong *)(param_1 + (ulonglong)bVar21 * 2 + 0x6c) != 0)) {
      puVar6 = param_1 + ((ulonglong)bVar21 + 0x36) * 2;
      local_1f8 = *(longlong *)(param_1 + ((ulonglong)bVar21 + 0x36) * 2);
      local_200 = (undefined8 *)(local_1f8 + 8);
      if ((param_1[0x17] & 4) != 0) {
        AhciSimulateThrottledEtwEvent((longlong)param_1,0,0x26);
        AhciSimulateThrottledEtwEvent((longlong)param_1,local_1f8,0x30);
      }
      if (uVar11 == 0) {
LAB_1400038f5:
        AhciProcessIo(*(longlong **)(param_1 + (ulonglong)bVar21 * 2 + 0x6c),param_2,0);
        puVar13 = (undefined8 *)
                  ActivateQueue(*(longlong **)(param_1 + (ulonglong)bVar21 * 2 + 0x6c),'\0');
        goto LAB_14000391f;
      }
      switch(uVar11) {
      case 2:
        if (*(char *)((longlong)param_2 + 2) == '(') {
          uVar11 = *(uint *)(param_2 + 3);
        }
        else {
          uVar11 = *(uint *)((longlong)param_2 + 0xc);
        }
        if ((uVar11 >> 0xb & 1) == 0) {
          PortAcquireActiveReference
                    (*(undefined8 **)(param_1 + (ulonglong)bVar21 * 2 + 0x6c),(longlong)param_2,
                     (undefined1 *)0x0);
        }
        goto LAB_1400038f5;
      default:
        local_270 = 0;
        local_278 = (wchar_t *)0x0;
        local_280 = (ulonglong)uVar11;
        *(undefined1 *)((longlong)param_2 + 3) = 6;
        local_288 = L"Function";
        local_298 = 0;
        local_2a0 = 4;
        local_2a8 = 0x10;
        local_2b0 = L"Invalid request";
        local_2b8 = (undefined2 **)CONCAT44(local_2b8._4_4_,0x2e);
        local_290 = param_2;
        StorPortExtendedFunction(0x55,param_1,local_200);
        goto LAB_140026335;
      case 7:
        bVar8 = (byte)((char)param_1[99] - 1U) < 2;
        *(uint *)(*(longlong *)puVar6 + 0x20) = *(uint *)(*(longlong *)puVar6 + 0x20) | 2;
        if ((*(uint *)(*(longlong *)(param_1 + (ulonglong)bVar21 * 2 + 0x6c) + 0x170) & 0x10) == 0)
        {
          if (bVar8) {
            uVar16 = GetSrbExtension((longlong)param_2);
            *(undefined2 *)(uVar16 + 0x1100) = 0x100;
            *(undefined1 *)(uVar16 + 0x110e) = 0xe0;
            uVar16 = FUN_140003b59();
            return uVar16;
          }
          *(undefined1 *)((longlong)param_2 + 3) = 1;
          StorPortNotification(0,param_1,param_2);
        }
        else {
          IssueSetDateAndTimeCommand
                    (*(longlong *)(param_1 + (ulonglong)bVar21 * 2 + 0x6c),(longlong)param_2,bVar8);
        }
        uVar16 = FUN_140003b59();
        return uVar16;
      case 0x12:
      case 0x13:
      case 0x20:
        AhciInterruptSpinlockAcquire((longlong)param_1,(uint)bVar21,(longlong)&local_1e8);
        LOCK();
        *(uint *)(*(longlong *)puVar6 + 0x250) = *(uint *)(*(longlong *)puVar6 + 0x250) | 0x800000;
        UNLOCK();
        uVar15 = AhciPortReset(*(ulonglong **)puVar6,'\x01');
        uVar7 = 1;
        if ((char)uVar15 == '\0') {
          uVar7 = 4;
        }
        *(undefined1 *)((longlong)param_2 + 3) = uVar7;
        StorPortNotification(0,param_1,param_2);
        AhciInterruptSpinlockRelease((longlong)param_1,(uint)bVar21,(longlong)&local_1e8);
        local_200 = (undefined8 *)0x0;
        *(int *)(*(longlong *)puVar6 + 0xb4) = *(int *)(*(longlong *)puVar6 + 0xb4) + 1;
        puVar17 = *(undefined8 **)puVar6;
        local_208 = (undefined2 *)(ulonglong)*(byte *)((longlong)param_2 + 3);
        puStack_1f0 = puVar17 + 1;
        puVar13 = puStack_1f0;
        if ((puVar17 != (undefined8 *)0x0) && (*(int *)(puVar17 + 3) != 2)) {
          StorPortQuerySystemTime(&local_200);
          if ((puVar17[0x8be] == 0) ||
             (puVar13 = local_200, 35999999999 < (ulonglong)((longlong)local_200 - puVar17[0x8be])))
          {
            uVar1 = *(undefined4 *)(puVar17 + 0x8bc);
            uVar2 = *(undefined4 *)((longlong)puVar17 + 0x45d4);
            uVar11 = *(uint *)(puVar17 + 0x8bd);
            uVar15 = puVar17[0x49];
            uVar5 = puVar17[0x4a];
            uVar10 = *(uint *)((longlong)puVar17 + 0xb4);
            puVar17[0x8be] = local_200;
            uVar3 = *(undefined4 *)((longlong)puVar17 + 0x45e4);
            uVar4 = *(undefined4 *)((longlong)puVar17 + 0x45dc);
            memset(&uStack_1c8,0,0x180);
            uStack_1c8 = 1;
            uStack_1c4 = 8;
            uVar9 = GetStringLength("AhciHwStartIo RESET Request",0x20);
            memcpy(auStack_1c0,"AhciHwStartIo RESET Request",(ulonglong)uVar9);
            uStack_1a0 = 1;
            uVar9 = GetStringLength("PortReset|PortErrorRecovery",0x20);
            memcpy(local_188,"PortReset|PortErrorRecovery",(ulonglong)uVar9);
            uStack_168 = CONCAT44(*(undefined4 *)(puVar17 + 0x8ba),*(undefined4 *)(puVar17 + 0x8bb))
            ;
            uVar9 = GetStringLength("StartFail|NonQErrorRecovery",0x20);
            memcpy(auStack_160,"StartFail|NonQErrorRecovery",(ulonglong)uVar9);
            uStack_140 = CONCAT44(uVar2,uVar4);
            uVar9 = GetStringLength("NCQError|NCQErrorComplete",0x20);
            memcpy(auStack_138,"NCQError|NCQErrorComplete",(ulonglong)uVar9);
            uStack_118 = CONCAT44(uVar1,uVar3);
            uVar9 = GetStringLength("PortDriverResetCount",0x20);
            memcpy(auStack_110,"PortDriverResetCount",(ulonglong)uVar9);
            uStack_f0 = (ulonglong)uVar10;
            uVar10 = GetStringLength("StateFlags",0x20);
            memcpy(auStack_e8,"StateFlags",(ulonglong)uVar10);
            uStack_c8 = uVar5;
            uVar10 = GetStringLength("StartState",0x20);
            memcpy(auStack_c0,"StartState",(ulonglong)uVar10);
            uStack_a0 = uVar15;
            uVar10 = GetStringLength("TotalCountSurpriseRemove",0x20);
            memcpy(auStack_98,"TotalCountSurpriseRemove",(ulonglong)uVar10);
            uStack_78 = (ulonglong)uVar11;
            uVar11 = GetStringLength("PortResetStatus",0x20);
            memcpy(auStack_70,"PortResetStatus",(ulonglong)uVar11);
            puStack_50 = local_208;
            puVar13 = (undefined8 *)StorPortExtendedFunction(0x4f,*puVar17,puStack_1f0,&uStack_1c8);
          }
        }
        goto LAB_14000391f;
      case 0x25:
        if ((*(char *)((longlong)param_2 + 2) == '(') && (*(uint *)(param_2 + 7) != 0)) {
          for (uVar19 = 0; (uint)uVar19 < *(uint *)(param_2 + 7);
              uVar19 = (ulonglong)((uint)uVar19 + 1)) {
            uVar11 = *(uint *)((longlong)param_2 + uVar19 * 4 + 0x78);
            if (((0x7f < uVar11) && (uVar11 < *(uint *)(param_2 + 2))) &&
               (uVar26 = (longlong)param_2 + (ulonglong)uVar11,
               *(int *)((longlong)param_2 + (ulonglong)uVar11) == 0x62)) goto LAB_1400039bc;
          }
        }
        uVar26 = 0;
LAB_1400039bc:
        if (((*(uint *)(uVar26 + 0x10) & 1) == 0) && (*(int *)(uVar26 + 0xc) == 9)) {
          if (*(char *)((longlong)param_2 + 2) == '(') {
            uVar11 = *(uint *)((longlong)param_2 + 0x3c);
          }
          else {
            uVar11 = *(uint *)(param_2 + 2);
          }
          if (uVar11 < 0x18) goto LAB_140003b37;
          if (*(char *)((longlong)param_2 + 2) == '(') {
            lVar27 = param_2[8];
          }
          else {
            lVar27 = param_2[3];
          }
          *(uint *)(lVar27 + 4) =
               ((*(uint *)(*(longlong *)(param_1 + (ulonglong)bVar21 * 2 + 0x6c) + 0x244) & 1) << 4
               ^ *(uint *)(lVar27 + 4) & 0xffffffef) & 0xfffff990 | 0x80;
          *(undefined1 *)((longlong)param_2 + 3) = 1;
        }
        else {
LAB_140003b37:
          *(undefined1 *)((longlong)param_2 + 3) = 6;
        }
        StorPortNotification(0,param_1,param_2);
        bVar8 = *(char *)((longlong)param_2 + 3) == '\x01';
        if (!bVar8) {
          bVar8 = AhciIsEventAllowedWithinThrottleLimit
                            ((longlong)param_1,local_1f8,0x28,(int *)&local_208);
          puVar13 = (undefined8 *)CONCAT71(extraout_var,bVar8);
          if (!bVar8) goto LAB_14000391f;
          uVar16 = (ulonglong)local_208 & 0xffffffff;
          bVar8 = *(char *)((longlong)param_2 + 3) == '\x01';
        }
        local_270 = (ulonglong)*(int *)(uVar26 + 0xc);
        local_280 = (ulonglong)*(uint *)(uVar26 + 0x10);
        if (bVar8) {
          uVar16 = 0;
        }
        local_250 = 0;
        local_268 = (wchar_t *)0x0;
        local_258 = (wchar_t *)0x0;
        if (!bVar8) {
          local_268 = L"ThrottleCount";
        }
        local_2a0 = 4;
        if (!bVar8) {
          local_2a0 = 2;
        }
        local_278 = L"PnPAction";
        local_288 = L"SrbPnPFlags";
        local_298 = 0;
        local_2a8 = 0x10;
        local_2b0 = L"Completed PnP request";
        local_2b8 = (undefined2 **)CONCAT44(local_2b8._4_4_,0x28);
        local_290 = param_2;
        local_260 = uVar16;
        puVar13 = (undefined8 *)StorPortExtendedFunction(0x56,param_1,local_200,!bVar8);
        goto LAB_14000391f;
      case 0x26:
        local_208 = (undefined2 *)0x0;
        if (*(char *)((longlong)param_2 + 2) == '(') {
          puVar23 = (undefined4 *)param_2[8];
        }
        else {
          puVar23 = (undefined4 *)param_2[3];
        }
        pwVar25 = L"Completed dump pointers";
        if (puVar23 == (undefined4 *)0x0) {
LAB_14002603c:
          pwVar25 = L"Invalid dump pointers request";
LAB_140026043:
          bVar22 = 6;
          *(undefined1 *)((longlong)param_2 + 3) = 6;
LAB_140026048:
          local_2a0 = 2;
        }
        else {
          if (*(char *)((longlong)param_2 + 2) == '(') {
            uVar11 = *(uint *)((longlong)param_2 + 0x3c);
          }
          else {
            uVar11 = *(uint *)(param_2 + 2);
          }
          if (uVar11 < 0x48) goto LAB_14002603c;
          if ((param_1[0xe] & 0x100000) == 0) {
            pwVar25 = L"Dump pointers disabed by config";
            goto LAB_140026043;
          }
          local_2b8 = &local_208;
          iVar12 = StorPortExtendedFunction(0,param_1,0x200,0x69636841);
          if ((iVar12 != 0) || (local_208 == (undefined2 *)0x0)) {
            *(undefined1 *)((longlong)param_2 + 3) = 4;
            pwVar25 = L"Allocate dump context failed";
            bVar22 = 4;
            goto LAB_140026048;
          }
          *puVar23 = 0x700100;
          memset(local_208,0,0x200);
          *local_208 = (short)param_1[4];
          local_208[1] = *(undefined2 *)((longlong)param_1 + 0x12);
          *(char *)(local_208 + 2) = (char)param_1[5];
          *(uint *)(local_208 + 4) = param_1[3];
          *(uint *)(local_208 + 6) = param_1[0xd];
          puVar13 = (undefined8 *)(local_208 + 8);
          puVar6 = param_1 + 0xe;
          lVar27 = 2;
          do {
            lVar20 = lVar27;
            puVar14 = puVar6;
            puVar17 = puVar13;
            uVar15 = *(undefined8 *)(puVar14 + 2);
            *puVar17 = *(undefined8 *)puVar14;
            puVar17[1] = uVar15;
            uVar15 = *(undefined8 *)(puVar14 + 6);
            puVar17[2] = *(undefined8 *)(puVar14 + 4);
            puVar17[3] = uVar15;
            uVar15 = *(undefined8 *)(puVar14 + 10);
            puVar17[4] = *(undefined8 *)(puVar14 + 8);
            puVar17[5] = uVar15;
            uVar15 = *(undefined8 *)(puVar14 + 0xe);
            puVar17[6] = *(undefined8 *)(puVar14 + 0xc);
            puVar17[7] = uVar15;
            uVar15 = *(undefined8 *)(puVar14 + 0x12);
            puVar17[8] = *(undefined8 *)(puVar14 + 0x10);
            puVar17[9] = uVar15;
            uVar15 = *(undefined8 *)(puVar14 + 0x16);
            puVar17[10] = *(undefined8 *)(puVar14 + 0x14);
            puVar17[0xb] = uVar15;
            uVar15 = *(undefined8 *)(puVar14 + 0x1a);
            puVar17[0xc] = *(undefined8 *)(puVar14 + 0x18);
            puVar17[0xd] = uVar15;
            uVar15 = *(undefined8 *)(puVar14 + 0x1e);
            puVar17[0xe] = *(undefined8 *)(puVar14 + 0x1c);
            puVar17[0xf] = uVar15;
            lVar27 = lVar20 + -1;
            puVar13 = puVar17 + 0x10;
            puVar6 = puVar14 + 0x20;
          } while (lVar27 != 0);
          uVar15 = *(undefined8 *)(puVar14 + 0x22);
          puVar17[0x10] = *(undefined8 *)(puVar14 + 0x20);
          puVar17[0x11] = uVar15;
          uVar15 = *(undefined8 *)(puVar14 + 0x26);
          puVar17[0x12] = *(undefined8 *)(puVar14 + 0x24);
          puVar17[0x13] = uVar15;
          uVar15 = *(undefined8 *)(puVar14 + 0x2a);
          puVar17[0x14] = *(undefined8 *)(puVar14 + 0x28);
          puVar17[0x15] = uVar15;
          uVar15 = *(undefined8 *)(puVar14 + 0x2e);
          puVar17[0x16] = *(undefined8 *)(puVar14 + 0x2c);
          puVar17[0x17] = uVar15;
          puVar17[0x18] = *(undefined8 *)(puVar14 + 0x30);
          *(undefined4 *)(local_208 + 0xce) = 1;
          *(undefined4 *)(local_208 + 0xd0) =
               *(undefined4 *)(*(longlong *)(param_1 + (ulonglong)bVar21 * 2 + 0x6c) + 0x240);
          lVar27 = *(longlong *)(param_1 + (ulonglong)bVar21 * 2 + 0x6c);
          uVar15 = *(undefined8 *)(lVar27 + 0x260);
          *(undefined8 *)(local_208 + 0xd2) = *(undefined8 *)(lVar27 + 600);
          *(undefined8 *)(local_208 + 0xd6) = uVar15;
          *(undefined8 *)(local_208 + 0xda) = *(undefined8 *)(lVar27 + 0x268);
          *(undefined4 *)(local_208 + 0xde) = *(undefined4 *)(lVar27 + 0x270);
          lVar27 = *(longlong *)(param_1 + (ulonglong)bVar21 * 2 + 0x6c);
          uVar16 = IsDeviceHybridInfoSupported(lVar27);
          if ((char)uVar16 != '\0') {
            memcpy(local_208 + 0xe0,(void *)(lVar27 + 0x180),(ulonglong)((int)lVar20 + 0x3f));
          }
          *(undefined8 *)(local_208 + 0xac) = 0;
          *(undefined8 *)(local_208 + 0xb0) = 0;
          *(undefined8 *)(local_208 + 0xb4) = 0;
          *(undefined8 *)(local_208 + 0xb8) = 0;
          *(undefined8 *)(local_208 + 0xbc) = 0;
          *(undefined8 *)(local_208 + 0xc0) = 0;
          *(undefined8 *)(local_208 + 0xc4) = 0;
          *(undefined8 *)(local_208 + 200) = 0;
          *(undefined4 *)(local_208 + 0xcc) = 0;
          if (*(int *)(local_208 + 0xcc) == 0) {
            *(undefined4 *)(local_208 + 0xcc) = 0x24;
          }
          *(undefined2 **)(puVar23 + 0x10) = local_208;
          bVar22 = 1;
          *(undefined1 *)((longlong)param_2 + 3) = 1;
          local_2a0 = 4;
        }
        bVar8 = bVar22 != 1;
        if (*(char *)((longlong)param_2 + 2) == '(') {
          uVar11 = *(uint *)((longlong)param_2 + 0x3c);
        }
        else {
          uVar11 = *(uint *)(param_2 + 2);
        }
        local_280 = (ulonglong)bVar22;
        local_2b8 = (undefined2 **)CONCAT44(local_2b8._4_4_,0x2b);
        local_2b0 = pwVar25;
        break;
      case 0x27:
        if (*(char *)((longlong)param_2 + 2) == '(') {
          lVar27 = param_2[8];
        }
        else {
          lVar27 = param_2[3];
        }
        if (lVar27 == 0) {
LAB_140026169:
          local_280 = 6;
        }
        else {
          if (*(char *)((longlong)param_2 + 2) == '(') {
            uVar11 = *(uint *)((longlong)param_2 + 0x3c);
          }
          else {
            uVar11 = *(uint *)(param_2 + 2);
          }
          if (uVar11 < 0x48) goto LAB_140026169;
          iVar12 = StorPortExtendedFunction(1,param_1,*(undefined8 *)(lVar27 + 0x40));
          local_280 = 1;
          if (iVar12 != 0) {
            local_280 = 4;
          }
        }
        bVar8 = (char)local_280 != '\x01';
        *(char *)((longlong)param_2 + 3) = (char)local_280;
        local_2a0 = 4;
        if (bVar8) {
          local_2a0 = 2;
        }
        if (*(char *)((longlong)param_2 + 2) == '(') {
          uVar11 = *(uint *)((longlong)param_2 + 0x3c);
        }
        else {
          uVar11 = *(uint *)(param_2 + 2);
        }
        local_2b0 = L"Completed free dump pointers";
        local_2b8 = (undefined2 **)CONCAT44(local_2b8._4_4_,0x2c);
      }
      local_270 = (ulonglong)uVar11;
      local_278 = L"TransferLen";
      puVar13 = local_200;
      goto LAB_14002610b;
    }
    *(undefined1 *)((longlong)param_2 + 3) = 8;
    bVar8 = AhciIsEventAllowedWithinThrottleLimit((longlong)param_1,0,0x26,(int *)&local_208);
    if (bVar8) {
      local_250 = (ulonglong)param_1[3];
      uStack_220 = (ulonglong)param_1[0x60];
      uStack_210 = (ulonglong)local_208 & 0xffffffff;
      local_260 = (ulonglong)param_1[2];
      local_270 = (ulonglong)param_1[1];
      pwStack_218 = L"ThrottleCount";
      pwStack_228 = L"PortImplemented";
      uStack_240 = (ulonglong)bVar21;
      local_280 = (ulonglong)*param_1;
      uStack_230 = (ulonglong)uVar11;
      pwStack_238 = L"Function";
      pwStack_248 = L"PathId";
      local_258 = L"AhciBaseAddress";
      local_268 = L"SlotNumber";
      local_278 = L"SystemIoBusNumber";
      local_288 = L"AdapterNumber";
      local_298 = 0;
      local_2a0 = 2;
      local_2a8 = 0x10;
      local_2b0 = L"Srb sent to invalid port in StartIo";
      local_2b8 = (undefined2 **)CONCAT44(local_2b8._4_4_,0x26);
      local_290 = param_2;
      StorPortExtendedFunction(0x57,param_1,0);
    }
    break;
  case 0x25:
    if ((bVar22 == 0x28) && (*(uint *)(param_2 + 7) != 0)) {
      for (uVar19 = 0; (uint)uVar19 < *(uint *)(param_2 + 7); uVar19 = (ulonglong)((uint)uVar19 + 1)
          ) {
        uVar10 = *(uint *)((longlong)param_2 + uVar19 * 4 + 0x78);
        if (((0x7f < uVar10) && (uVar10 < *(uint *)(param_2 + 2))) &&
           (lVar27 = (longlong)param_2 + (ulonglong)uVar10,
           *(int *)((longlong)param_2 + (ulonglong)uVar10) == 0x62)) goto LAB_140003c64;
      }
    }
    lVar27 = 0;
LAB_140003c64:
    if ((*(uint *)(lVar27 + 0x10) & 1) == 0) goto switchD_140003bfd_caseD_3;
    iVar12 = *(int *)(lVar27 + 0xc);
    if ((iVar12 == 2) || (iVar12 == 0x17)) {
      param_1[0xb] = param_1[0xb] | 0x20;
LAB_140025543:
      *(undefined1 *)((longlong)param_2 + 3) = 1;
    }
    else {
      if (iVar12 == 4) {
        AhciAdapterStop((longlong)param_1);
        goto LAB_140025543;
      }
      *(undefined1 *)((longlong)param_2 + 3) = 6;
      bVar8 = AhciIsEventAllowedWithinThrottleLimit((longlong)param_1,0,0x27,(int *)&local_208);
      if (!bVar8) break;
      uVar16 = (ulonglong)local_208 & 0xffffffff;
    }
    local_270 = (ulonglong)*(byte *)((longlong)param_2 + 3);
    local_268 = (wchar_t *)0x0;
    local_280 = (ulonglong)*(int *)(lVar27 + 0xc);
    bVar8 = *(byte *)((longlong)param_2 + 3) != 1;
    local_250 = 0;
    local_258 = (wchar_t *)0x0;
    if (bVar8) {
      local_268 = L"ThrottleCount";
      local_260 = uVar16;
    }
    else {
      local_260 = 0;
    }
    local_278 = L"SrbStatus";
    local_2a0 = 4;
    if (bVar8) {
      local_2a0 = 2;
    }
    local_288 = L"PnPAction";
    local_298 = 0;
    local_2a8 = 0x10;
    local_2b0 = L"Processing PNP";
    local_2b8 = (undefined2 **)CONCAT44(local_2b8._4_4_,0x27);
    local_290 = param_2;
    StorPortExtendedFunction(0x56,param_1,0,bVar8);
    break;
  case 0x2a:
    local_208 = (undefined2 *)0x0;
    if (bVar22 == 0x28) {
      uVar11 = *(uint *)((longlong)param_2 + 0x3c);
      lVar27 = param_2[8];
    }
    else {
      uVar11 = *(uint *)(param_2 + 2);
      lVar27 = param_2[3];
    }
    if (((lVar27 == 0) || (uVar11 < 0x20)) ||
       ((*(int *)(lVar27 + 8) != 0x474d4449 || (uVar10 = *(uint *)(lVar27 + 0xc), 0x1f < uVar10 - 1)
        ))) {
      *(undefined1 *)((longlong)param_2 + 3) = 6;
    }
    else {
      local_2b8 = &local_208;
      uVar9 = uVar10 * 0x60 + 0x1a0;
      iVar12 = StorPortExtendedFunction(0,param_1,uVar9,0x69636841);
      if ((iVar12 == 0) && (local_208 != (undefined2 *)0x0)) {
        if (uVar9 != 0) {
          memset(local_208,0,(ulonglong)uVar9);
        }
        lVar20 = 2;
        *local_208 = (short)param_1[4];
        local_208[1] = *(undefined2 *)((longlong)param_1 + 0x12);
        *(char *)(local_208 + 2) = (char)param_1[5];
        *(uint *)(local_208 + 4) = param_1[3];
        *(uint *)(local_208 + 6) = param_1[0xd];
        puVar6 = param_1 + 0xe;
        puVar13 = (undefined8 *)(local_208 + 8);
        do {
          puVar17 = puVar13;
          puVar14 = puVar6;
          uVar15 = *(undefined8 *)(puVar14 + 2);
          *puVar17 = *(undefined8 *)puVar14;
          puVar17[1] = uVar15;
          uVar15 = *(undefined8 *)(puVar14 + 6);
          puVar17[2] = *(undefined8 *)(puVar14 + 4);
          puVar17[3] = uVar15;
          uVar15 = *(undefined8 *)(puVar14 + 10);
          puVar17[4] = *(undefined8 *)(puVar14 + 8);
          puVar17[5] = uVar15;
          uVar15 = *(undefined8 *)(puVar14 + 0xe);
          puVar17[6] = *(undefined8 *)(puVar14 + 0xc);
          puVar17[7] = uVar15;
          uVar15 = *(undefined8 *)(puVar14 + 0x12);
          puVar17[8] = *(undefined8 *)(puVar14 + 0x10);
          puVar17[9] = uVar15;
          uVar15 = *(undefined8 *)(puVar14 + 0x16);
          puVar17[10] = *(undefined8 *)(puVar14 + 0x14);
          puVar17[0xb] = uVar15;
          uVar15 = *(undefined8 *)(puVar14 + 0x1a);
          puVar17[0xc] = *(undefined8 *)(puVar14 + 0x18);
          puVar17[0xd] = uVar15;
          uVar15 = *(undefined8 *)(puVar14 + 0x1e);
          puVar17[0xe] = *(undefined8 *)(puVar14 + 0x1c);
          puVar17[0xf] = uVar15;
          lVar20 = lVar20 + -1;
          puVar6 = puVar14 + 0x20;
          puVar13 = puVar17 + 0x10;
        } while (lVar20 != 0);
        uVar15 = *(undefined8 *)(puVar14 + 0x22);
        puVar17[0x10] = *(undefined8 *)(puVar14 + 0x20);
        puVar17[0x11] = uVar15;
        uVar15 = *(undefined8 *)(puVar14 + 0x26);
        puVar17[0x12] = *(undefined8 *)(puVar14 + 0x24);
        puVar17[0x13] = uVar15;
        uVar15 = *(undefined8 *)(puVar14 + 0x2a);
        puVar17[0x14] = *(undefined8 *)(puVar14 + 0x28);
        puVar17[0x15] = uVar15;
        uVar15 = *(undefined8 *)(puVar14 + 0x2e);
        puVar17[0x16] = *(undefined8 *)(puVar14 + 0x2c);
        puVar17[0x17] = uVar15;
        puVar17[0x18] = *(undefined8 *)(puVar14 + 0x30);
        *(undefined8 *)(local_208 + 0xac) = 0;
        *(undefined8 *)(local_208 + 0xb0) = 0;
        *(undefined8 *)(local_208 + 0xb4) = 0;
        *(undefined8 *)(local_208 + 0xb8) = 0;
        *(undefined8 *)(local_208 + 0xbc) = 0;
        *(undefined8 *)(local_208 + 0xc0) = 0;
        *(undefined8 *)(local_208 + 0xc4) = 0;
        *(undefined8 *)(local_208 + 200) = 0;
        *(undefined4 *)(local_208 + 0xcc) = 0;
        if (*(int *)(local_208 + 0xcc) == 0) {
          *(undefined4 *)(local_208 + 0xcc) = 0x24;
        }
        *(uint *)(local_208 + 0xce) = uVar10;
        *(undefined1 *)((longlong)param_2 + 3) = 1;
        for (uVar9 = 0; uVar9 < uVar10; uVar9 = uVar9 + 1) {
          uVar16 = (ulonglong)uVar9;
          uVar19 = (ulonglong)uVar9;
          if ((*(short *)(lVar27 + 0x10 + uVar16 * 0x10) != 1) ||
             (*(uint *)(lVar27 + 0x14 + uVar16 * 0x10) < 4)) {
            *(undefined1 *)((longlong)param_2 + 3) = 6;
            break;
          }
          bVar22 = *(byte *)(lVar27 + 0x18 + uVar16 * 0x10);
          lVar24 = uVar19 * 0x60;
          *(undefined4 *)(local_208 + uVar19 * 0x30 + 0xd0) =
               *(undefined4 *)(*(longlong *)(param_1 + (ulonglong)bVar22 * 2 + 0x6c) + 0x240);
          lVar20 = *(longlong *)(param_1 + (ulonglong)bVar22 * 2 + 0x6c);
          uVar15 = *(undefined8 *)(lVar20 + 0x260);
          *(undefined8 *)(local_208 + uVar19 * 0x30 + 0xd2) = *(undefined8 *)(lVar20 + 600);
          *(undefined8 *)((longlong)(local_208 + uVar19 * 0x30 + 0xd2) + 8) = uVar15;
          *(undefined8 *)(local_208 + uVar19 * 0x30 + 0xda) = *(undefined8 *)(lVar20 + 0x268);
          *(undefined4 *)(local_208 + uVar19 * 0x30 + 0xde) = *(undefined4 *)(lVar20 + 0x270);
          lVar20 = *(longlong *)(param_1 + (ulonglong)bVar22 * 2 + 0x6c);
          uVar16 = IsDeviceHybridInfoSupported(lVar20);
          if ((char)uVar16 != '\0') {
            memcpy((void *)((longlong)local_208 + lVar24 + 0x1c0),(void *)(lVar20 + 0x180),0x40);
          }
        }
        if (*(char *)((longlong)param_2 + 3) == '\x01') {
          if (*(char *)((longlong)param_2 + 2) == '(') {
            puVar23 = (undefined4 *)param_2[8];
          }
          else {
            puVar23 = (undefined4 *)param_2[3];
          }
          memset(puVar23,0,(ulonglong)uVar11);
          *puVar23 = 0x18;
          puVar23[1] = 0x18;
          puVar23[2] = 0x4d504449;
          *(undefined2 **)(puVar23 + 4) = local_208;
        }
      }
      else {
        *(undefined1 *)((longlong)param_2 + 3) = 4;
      }
    }
    local_280 = (ulonglong)*(byte *)((longlong)param_2 + 3);
    local_270 = 0;
    bVar8 = *(byte *)((longlong)param_2 + 3) != 1;
    local_278 = (wchar_t *)0x0;
    local_2a0 = 4;
    if (bVar8) {
      local_2a0 = 2;
    }
    puVar13 = (undefined8 *)0x0;
    local_2b0 = L"Completed GET_DUMP_INFO";
    local_2b8 = (undefined2 **)CONCAT44(local_2b8._4_4_,0x29);
    goto LAB_14002610b;
  case 0x2b:
    if (bVar22 == 0x28) {
      lVar27 = param_2[8];
    }
    else {
      lVar27 = param_2[3];
    }
    if (lVar27 == 0) {
LAB_1400259dc:
      bVar22 = 6;
    }
    else {
      if (bVar22 == 0x28) {
        uVar11 = *(uint *)((longlong)param_2 + 0x3c);
      }
      else {
        uVar11 = *(uint *)(param_2 + 2);
      }
      if ((uVar11 < 0x18) || (*(int *)(lVar27 + 8) != 0x464d4449)) goto LAB_1400259dc;
      iVar12 = StorPortExtendedFunction(1,param_1,*(undefined8 *)(lVar27 + 0x10));
      bVar22 = 1;
      if (iVar12 != 0) {
        bVar22 = 4;
      }
    }
    local_270 = 0;
    bVar8 = bVar22 != 1;
    local_278 = (wchar_t *)0x0;
    local_280 = (ulonglong)bVar22;
    local_2a0 = 4;
    if (bVar8) {
      local_2a0 = 2;
    }
    *(byte *)((longlong)param_2 + 3) = bVar22;
    puVar13 = (undefined8 *)0x0;
    local_2b0 = L"Completed FREE_DUMP_INFO";
    local_2b8 = (undefined2 **)CONCAT44(local_2b8._4_4_,0x2a);
LAB_14002610b:
    local_288 = L"SrbStatus";
    local_298 = 0;
    local_2a8 = 0x10;
    local_290 = param_2;
    StorPortExtendedFunction(0x55,param_1,puVar13,bVar8);
  }
LAB_140026335:
  puVar13 = (undefined8 *)StorPortNotification(0,param_1,param_2);
LAB_14000391f:
  return CONCAT71((int7)((ulonglong)puVar13 >> 8),1);
}



===== FUN_140003b59 @ 140003b59 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140003b59(void)

{
  uint uVar1;
  ulonglong uVar2;
  longlong *unaff_RBX;
  longlong unaff_RSI;
  byte unaff_DIL;
  char unaff_R12B;
  undefined8 uStack0000000000000030;
  undefined4 uStack0000000000000038;
  
  uStack0000000000000038 = 4;
  uStack0000000000000030 = 0x10;
  uVar2 = StorPortExtendedFunction(0x55);
  if (unaff_R12B != '\0') {
    if (*(char *)((longlong)unaff_RBX + 2) == '(') {
      uVar1 = *(uint *)(unaff_RBX + 3);
    }
    else {
      uVar1 = *(uint *)((longlong)unaff_RBX + 0xc);
    }
    if ((uVar1 >> 0xb & 1) == 0) {
      PortAcquireActiveReference
                (*(undefined8 **)(unaff_RSI + 0x1b0 + (ulonglong)unaff_DIL * 8),(longlong)unaff_RBX,
                 (undefined1 *)0x0);
    }
    AhciProcessIo(*(longlong **)(unaff_RSI + 0x1b0 + (ulonglong)unaff_DIL * 8),unaff_RBX,0);
    uVar2 = ActivateQueue(*(longlong **)(unaff_RSI + 0x1b0 + (ulonglong)unaff_DIL * 8),'\0');
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== caseD_8 @ 140003cdf =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 switchD_140003bfd::caseD_8(void)

{
  longlong unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 3) = 1;
  StorPortNotification(0);
  return 1;
}



===== ActivateQueue @ 140003de0 =====

ulonglong ActivateQueue(longlong *param_1,char param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  ulonglong uVar5;
  byte bVar6;
  undefined4 uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  lVar2 = *param_1;
  uVar5 = 0;
  uVar10 = 0;
  local_38 = 3;
  bVar4 = false;
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((*(uint *)(lVar2 + 0x34) & 1) != 0) {
    RecordExecutionHistory(param_1,0x22);
  }
  if ((char)param_1[0x49] != '\x16') {
    uVar7 = 0x10010022;
LAB_1400042cb:
    uVar5 = RecordExecutionHistory(param_1,uVar7);
    return uVar5 & 0xffffffffffffff00;
  }
  if ((param_1[0x4a] & 4U) != 0) {
    uVar7 = 0x10020022;
    goto LAB_1400042cb;
  }
  if (((*(uint *)(*param_1 + 0x2c) & 3) != 0) || ((param_1[0x4a] & 1U) == 0)) {
    uVar7 = 0x10030022;
    goto LAB_1400042cb;
  }
  if ((param_1[0x4a] & 0x20700U) != 0) {
    uVar7 = 0x10070022;
    goto LAB_1400042cb;
  }
  if (param_2 == '\0') {
    AhciInterruptSpinlockAcquire(*param_1,(int)param_1[0x48],(longlong)&local_38);
  }
  if ((((int)param_1[0x5b] == 0) && (*(int *)((longlong)param_1 + 0x2d4) == 0)) &&
     ((int)param_1[0x5a] == 0)) {
    if ((*(uint *)(lVar2 + 0x34) & 1) != 0) {
      RecordExecutionHistory(param_1,0x10040022);
    }
    goto LAB_140004271;
  }
  if (((param_1[0x4a] & 8U) != 0) && ((*(uint *)(param_1 + 0x5b) & 1) == 0)) {
    if ((*(uint *)(*param_1 + 0x34) & 1) != 0) {
      RecordExecutionHistory(param_1,0x10080022);
    }
    goto LAB_140004271;
  }
  uVar9 = *(uint *)(param_1 + 0x5b);
  if (uVar9 == 0) {
    uVar9 = *(uint *)((longlong)param_1 + 0x2d4);
    if (uVar9 == 0) {
      if ((((int)param_1[0x5a] != 0) && (((ulonglong)param_1[0x4a] >> 0x12 & 1) == 0)) &&
         (*(int *)((longlong)param_1 + 0x2ec) == 0 && (int)param_1[0x5d] == 0)) {
        uVar10 = *(uint *)(param_1 + 0x5a) & *(uint *)((longlong)param_1 + 0x2cc);
        uVar9 = *(uint *)(param_1 + 0x5a);
        if (uVar10 != 0) {
          uVar9 = uVar10;
        }
        if (uVar9 == 0) goto LAB_140004055;
        if (*(byte *)((longlong)param_1 + 0x1e) < *(byte *)((longlong)param_1 + 0x274)) {
          uVar9 = GetSlotToActivate(param_1,uVar9);
        }
        uVar10 = 0;
        if (uVar9 != 0) {
          bVar4 = true;
          *(uint *)(param_1 + 0x5a) = *(uint *)(param_1 + 0x5a) & ~uVar9;
          *(uint *)((longlong)param_1 + 0x2e4) = *(uint *)((longlong)param_1 + 0x2e4) | uVar9;
          goto LAB_14000405d;
        }
      }
    }
    else if (*(int *)((longlong)param_1 + 0x2e4) == 0) {
      uVar10 = *(uint *)((longlong)param_1 + 0x2cc) & uVar9;
      if (uVar10 == 0) {
        *(undefined4 *)((longlong)param_1 + 0x2d4) = 0;
        *(uint *)(param_1 + 0x5d) = *(uint *)(param_1 + 0x5d) | uVar9;
      }
      else {
        *(uint *)((longlong)param_1 + 0x2d4) = ~uVar10 & uVar9;
        *(uint *)(param_1 + 0x5d) = *(uint *)(param_1 + 0x5d) | uVar10;
        uVar9 = uVar10;
      }
LAB_14000405d:
      uVar10 = uVar9;
      if (*(char *)(lVar2 + 0x18e) != '\0') {
        StorPortExtendedFunction(0x2f,lVar2);
        pbVar8 = (byte *)(param_1 + 0x5f);
        uVar9 = uVar10;
        do {
          if (((uVar9 & 1) != 0) && (lVar3 = *(longlong *)(pbVar8 + 8), lVar3 != 0)) {
            if (*(char *)(lVar3 + 2) == '(') {
              uVar5 = *(ulonglong *)(lVar3 + 0x68);
            }
            else {
              uVar5 = *(ulonglong *)(lVar3 + 0x38);
            }
            if ((uVar5 & 0x7f) != 0) {
              uVar5 = (uVar5 - ((uint)uVar5 & 0x7f)) + 0x80;
            }
            *(undefined8 *)(uVar5 + 0x2980) = 0;
            if ((*(uint *)(*param_1 + 0x34) & 2) != 0) {
              *(undefined8 *)((ulonglong)*pbVar8 * 0x3c + 0x36e4 + (longlong)param_1) = 0;
            }
          }
          pbVar8 = pbVar8 + 0x20;
          uVar9 = uVar9 >> 1;
        } while (uVar9 != 0);
      }
      *(uint *)((longlong)param_1 + 0x2dc) = *(uint *)((longlong)param_1 + 0x2dc) | uVar10;
      if (bVar4) {
        *(uint *)(param_1[0x129] + 0x34) = uVar10;
        LOCK();
        UNLOCK();
      }
      *(uint *)(param_1[0x129] + 0x38) = uVar10;
      LOCK();
      UNLOCK();
    }
  }
  else if ((*(int *)((longlong)param_1 + 0x2ec) == 0 && (int)param_1[0x5d] == 0) &&
           *(int *)((longlong)param_1 + 0x2e4) == 0) {
    bVar1 = *(byte *)((longlong)param_1 + 0x275);
    bVar6 = 0;
    if ((uVar9 & 1) == 0) {
      for (bVar6 = bVar1; bVar6 <= ((byte)((uint)*(undefined4 *)(*param_1 + 0x1a8) >> 8) & 0x1f);
          bVar6 = bVar6 + 1) {
        if ((uVar9 & 1 << (bVar6 & 0x1f)) != 0) goto LAB_140003f94;
      }
      bVar6 = 0;
      if (bVar1 != 0) {
        do {
          if ((*(uint *)(param_1 + 0x5b) & 1 << (bVar6 & 0x1f)) != 0) goto LAB_140003f94;
          bVar6 = bVar6 + 1;
        } while (bVar6 < bVar1);
      }
      bVar6 = 0xff;
    }
LAB_140003f94:
    if (bVar6 != 0xff) {
      uVar9 = 1 << (bVar6 & 0x1f);
      *(uint *)((longlong)param_1 + 0x2ec) = *(uint *)((longlong)param_1 + 0x2ec) | uVar9;
      *(uint *)(param_1 + 0x5b) = *(uint *)(param_1 + 0x5b) & ~uVar9;
      param_1[0x4a] = param_1[0x4a] | 4;
      if ((*(uint *)(lVar2 + 0x34) & 1) != 0) {
        RecordExecutionHistory(param_1,0x10090022);
      }
      if ((((param_1[(ulonglong)bVar6 * 4 + 0x60] != 0) &&
           (uVar5 = GetSrbExtension(param_1[(ulonglong)bVar6 * 4 + 0x60]),
           *(short *)(uVar5 + 0x1100) == 0x101)) &&
          (*(code **)(uVar5 + 0x2968) == AhciPortIdentifyDevice)) &&
         ((*(char *)(uVar5 + 0x110e) == -1 && (*(char *)(uVar5 + 2) == -1)))) {
        if ((*(int *)(param_1[0x129] + 0x24) == 0x101) ||
           (*(int *)(param_1[0x129] + 0x24) == -0x5432feff)) {
          *(undefined1 *)(uVar5 + 0x110e) = 0xec;
          *(undefined1 *)(uVar5 + 2) = 0xec;
        }
        else {
          *(undefined1 *)(uVar5 + 0x110e) = 0xa1;
          *(undefined1 *)(uVar5 + 2) = 0xa1;
        }
      }
LAB_140004055:
      uVar10 = 0;
      if (uVar9 != 0) goto LAB_14000405d;
    }
  }
  if ((*(uint *)(lVar2 + 0x34) & 1) != 0) {
    RecordInterruptHistory
              (param_1,uVar10,0,0,*(uint *)((longlong)param_1 + 0x2ec) | *(uint *)(param_1 + 0x5d),
               *(undefined4 *)((longlong)param_1 + 0x2e4),0x10060022);
    RecordExecutionHistory(param_1,0x10050022);
  }
  uVar5 = 1;
LAB_140004271:
  if (param_2 == '\0') {
    lVar2 = *param_1;
    if (((char)*(undefined4 *)(lVar2 + 0x2c) < '\0') && ((int)param_1[0x48] != -1)) {
      StorPortExtendedFunction(0xc,lVar2,(int)param_1[0x48],uStack_20 & 0xff);
      return uVar5;
    }
    StorPortNotification(0x1004,lVar2,&local_38);
  }
  return uVar5;
}



===== SCSItoATA @ 140004300 =====

ulonglong SCSItoATA(ulonglong *param_1,longlong param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong *puVar9;
  byte *pbVar10;
  uint *puVar11;
  uint uVar12;
  
  uVar6 = 0;
  uVar5 = 0;
  cVar1 = *(char *)(param_2 + 2);
  if (cVar1 == '(') {
    pbVar10 = (byte *)0x0;
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar12 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        puVar11 = (uint *)(param_2 + 0x78);
        do {
          uVar3 = *puVar11;
          uVar7 = (ulonglong)uVar3;
          if ((0x7f < uVar3) &&
             (uVar8 = (ulonglong)*(uint *)(param_2 + 0x10), uVar3 < *(uint *)(param_2 + 0x10))) {
            iVar4 = *(int *)(uVar7 + param_2);
            if (iVar4 == 0x40) {
              if (uVar7 + 0x28 <= uVar8) {
                bVar2 = *(byte *)(uVar7 + 10 + param_2);
joined_r0x000140004505:
                uVar5 = (uint)bVar2;
                if (bVar2 != 0) {
                  pbVar10 = (byte *)(param_2 + 0x18 + (ulonglong)uVar3);
                }
                break;
              }
            }
            else if (iVar4 == 0x41) {
              if (uVar7 + 0x38 <= uVar8) {
                bVar2 = *(byte *)(uVar7 + 10 + param_2);
                goto joined_r0x000140004505;
              }
            }
            else if ((iVar4 == 0x42) && (uVar7 + 0x28 <= uVar8)) {
              uVar5 = *(uint *)(uVar7 + 0xc + param_2);
              if (uVar5 != 0) {
                pbVar10 = (byte *)(param_2 + 0x20 + (ulonglong)uVar3);
              }
              break;
            }
          }
          uVar12 = uVar12 + 1;
          puVar11 = puVar11 + 1;
        } while (uVar12 < *(uint *)(param_2 + 0x38));
      }
    }
LAB_1400043c2:
    if (pbVar10 != (byte *)0x0) {
      iVar4 = (int)param_1[3];
      if (iVar4 == 2) {
        bVar2 = *pbVar10;
        if (bVar2 == 0x12) {
          uVar7 = GetSrbExtension(param_2);
          *(uint *)(uVar7 + 0x1104) = *(uint *)(uVar7 + 0x1104) | 2;
          *(undefined2 *)(uVar7 + 0x1100) = 0x200;
          *(code **)(uVar7 + 0x2968) = AtapiInquiryCompletion;
        }
        else {
          if (bVar2 == 0x15) {
            puVar9 = param_1 + 1;
            uVar6 = IsTapeDevice((longlong)puVar9);
            if ((char)uVar6 == '\0') {
              uVar5 = AtapiModeSelectRequest((longlong *)param_1,param_2,(longlong)pbVar10);
              uVar6 = (ulonglong)uVar5;
              goto LAB_14000440a;
            }
          }
          else {
            if (bVar2 != 0x1a) {
              if (bVar2 == 0x85) {
                uVar6 = AtaPassThroughRequest((longlong)param_1,param_2,(longlong)pbVar10);
                uVar6 = uVar6 & 0xffffffff;
              }
              else if (bVar2 == 0xa0) {
                uVar6 = AtaReportLunsCommand((longlong)param_1,param_2);
                uVar6 = uVar6 & 0xffffffff;
              }
              else {
                uVar7 = GetSrbExtension(param_2);
                if (cVar1 == '(') {
                  uVar5 = *(uint *)(param_2 + 0x18);
                }
                else {
                  uVar5 = *(uint *)(param_2 + 0xc);
                }
                *(undefined2 *)(uVar7 + 0x1100) = 0x200;
                if ((uVar5 & 0x40) != 0) {
                  *(uint *)(uVar7 + 0x1104) = *(uint *)(uVar7 + 0x1104) | 2;
                }
                if ((char)uVar5 < '\0') {
                  *(uint *)(uVar7 + 0x1104) = *(uint *)(uVar7 + 0x1104) | 4;
                }
                uVar8 = uVar6 & 0xffffffff;
                while( true ) {
                  if ((&`DmaSafeAtapiCommand'::__l2::dmaCommandList)[uVar8] == 0) break;
                  if (*pbVar10 == (&`DmaSafeAtapiCommand'::__l2::dmaCommandList)[uVar8]) {
                    *(uint *)(uVar7 + 0x1104) = *(uint *)(uVar7 + 0x1104) | 0x10;
                    break;
                  }
                  uVar8 = (ulonglong)((int)uVar8 + 1);
                }
              }
              goto LAB_14000440a;
            }
            puVar9 = param_1 + 1;
            uVar6 = IsTapeDevice((longlong)puVar9);
            if ((char)uVar6 == '\0') {
              uVar5 = AtapiModeSenseRequest((longlong *)param_1,param_2,(longlong)pbVar10);
              uVar6 = (ulonglong)uVar5;
              goto LAB_14000440a;
            }
          }
          uVar6 = AtapiCommonRequest(puVar9,param_2,(char *)pbVar10);
          uVar6 = uVar6 & 0xffffffff;
        }
      }
      else if ((((iVar4 == 1) || (iVar4 - 3U < 3)) || (*pbVar10 == 0xa0)) || (*pbVar10 == 0x12)) {
        puVar9 = param_1;
        uVar6 = FastFailCommand((longlong *)param_1);
        if ((char)uVar6 != '\0') {
          *(undefined1 *)(param_2 + 3) = 8;
          return 0xc1000001;
        }
        uVar6 = RetryCommand(param_1,pbVar10);
        if ((char)uVar6 == '\0') {
          uVar6 = SrbConvertToATACommand(puVar9,param_2,pbVar10,uVar5);
          uVar6 = uVar6 & 0xffffffff;
        }
        else {
          *(undefined1 *)(param_2 + 3) = 5;
          uVar6 = 0xc100000c;
        }
      }
      else {
        *(undefined1 *)(param_2 + 3) = 8;
        uVar6 = 0xc1000007;
      }
      goto LAB_14000440a;
    }
  }
  else if (cVar1 == '\0') {
    uVar5 = (uint)*(byte *)(param_2 + 10);
    pbVar10 = (byte *)(param_2 + 0x48);
    if (*(byte *)(param_2 + 10) == 0) {
      pbVar10 = (byte *)0x0;
    }
    goto LAB_1400043c2;
  }
  *(undefined1 *)(param_2 + 3) = 0x22;
  uVar6 = 0xc1000006;
LAB_14000440a:
  return uVar6 & 0xffffffff;
}



===== AhciProcessIo @ 140004650 =====

undefined8 AhciProcessIo(longlong *param_1,longlong *param_2,byte param_3)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  short *psVar9;
  ulonglong uVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  longlong lVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  uint local_res10 [2];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  if (*(char *)((longlong)param_2 + 2) == '(') {
    uVar10 = param_2[0xd];
  }
  else {
    uVar10 = param_2[7];
  }
  if ((uVar10 & 0x7f) != 0) {
    uVar10 = (uVar10 - ((uint)uVar10 & 0x7f)) + 0x80;
  }
  uVar17 = 0;
  local_48 = 3;
  uVar13 = 0;
  uVar12 = local_res10[0] >> 8;
  local_res10[0] = local_res10[0] & 0xffffff00;
  uVar15 = 0;
  local_40 = 0;
  uVar16 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (*(char *)((longlong)param_2 + 2) == '(') {
    if (((*(uint *)((longlong)param_2 + 0x34) != 0) &&
        (psVar9 = (short *)((ulonglong)*(uint *)((longlong)param_2 + 0x34) + (longlong)param_2),
        psVar9 != (short *)0x0)) && (*psVar9 == 1)) {
      uVar15 = (undefined1)psVar9[4];
      uVar16 = *(undefined1 *)((longlong)psVar9 + 9);
      uVar17 = (undefined1)psVar9[5];
      goto LAB_1400046e7;
    }
  }
  else {
    uVar15 = *(undefined1 *)((longlong)param_2 + 5);
    uVar16 = *(undefined1 *)((longlong)param_2 + 6);
    uVar17 = *(undefined1 *)((longlong)param_2 + 7);
LAB_1400046e7:
    local_res10[0] = CONCAT31((int3)uVar12,uVar17);
  }
  if (*(short *)(uVar10 + 0x1100) == 0) {
    *(undefined1 *)((longlong)param_2 + 3) = 4;
  }
  else {
    bVar11 = param_3;
    if (((char)param_1[0x49] != -1) &&
       (((plVar8 = param_1, uVar5 = FastFailCommand(param_1), (char)uVar5 == '\0' ||
         (param_2 == param_1 + 0x12e)) || (param_2 == param_1 + 0x13b)))) {
      if ((*(short *)(uVar10 + 0x1100) == 0x100) && (*(char *)(uVar10 + 0x110e) == -0x11)) {
        if (*(char *)(uVar10 + 0x1108) == -0x7e) {
          bVar11 = 0x82;
          UpdateSetFeatureCommands((longlong)plVar8,'\x02',-0x7e,'\0',(char)uVar13);
          uVar13 = 0;
        }
        if (*(char *)(uVar10 + 0x1108) == '\x02') {
          bVar11 = 2;
          UpdateSetFeatureCommands((longlong)param_1,-0x7e,'\x02','\0','\0');
          uVar13 = 0;
        }
      }
      if (((*(short *)(uVar10 + 0x1100) == 0x101) &&
          (*(code **)(uVar10 + 0x2968) == AhciPortIdentifyDevice)) &&
         (*(char *)(uVar10 + 0x110e) == -1)) {
        iVar1 = *(int *)(param_1[0x129] + 0x24);
        if (iVar1 == 0x101) {
          *(undefined1 *)(uVar10 + 0x110e) = 0xec;
          *(undefined4 *)(param_1 + 3) = 1;
        }
        else if (iVar1 == -0x5432feff) {
          *(undefined1 *)(uVar10 + 0x110e) = 0xec;
          *(undefined4 *)(param_1 + 3) = 3;
        }
        else if (iVar1 == -0x14ebfeff) {
          *(undefined1 *)(uVar10 + 0x110e) = 0xa1;
          *(undefined4 *)(param_1 + 3) = 2;
        }
        else {
          iVar2 = *(int *)(param_1[0x129] + 0x28);
          RecordExecutionHistory(param_1,0x10090020);
          if ((iVar1 == 0) || ((iVar1 == -1 && (iVar2 != -1)))) {
            iVar1 = (int)param_1[3];
            if ((iVar1 == 1) || ((iVar1 != 2 && (((iVar1 == 3 || (iVar1 == 4)) || (iVar1 == 5))))))
            {
              *(undefined1 *)(uVar10 + 0x110e) = 0xec;
            }
            else {
              *(undefined1 *)(uVar10 + 0x110e) = 0xa1;
            }
          }
          else {
            *(undefined1 *)(uVar10 + 0x110e) = 0xa1;
            *(undefined4 *)(param_1 + 3) = 0;
          }
          uVar13 = 0;
          uVar17 = (undefined1)local_res10[0];
        }
      }
      if ((*(ushort *)(uVar10 + 0x1100) >> 8 & 1) != 0) {
        *(byte *)(uVar10 + 0x110d) = *(byte *)(uVar10 + 0x110d) | 0xa0;
      }
      if (param_3 == 0) {
        if (((char)*(undefined4 *)(*param_1 + 0x2c) < '\0') &&
           (uVar5 = (ulonglong)*(uint *)(param_1 + 0x48), *(uint *)(param_1 + 0x48) != 0xffffffff))
        {
          local_res10[0] = uVar13;
          StorPortExtendedFunction(0xb,*param_1,uVar5,local_res10);
          bVar11 = (byte)uVar5;
          uStack_30 = CONCAT71(uStack_30._1_7_,(undefined1)local_res10[0]);
        }
        else {
          bVar11 = 3;
          StorPortNotification(0x1003);
        }
        uVar13 = 0;
      }
      if (*(char *)((longlong)param_2 + 2) == '(') {
        uVar5 = param_2[0xd];
      }
      else {
        uVar5 = param_2[7];
      }
      if ((uVar5 & 0x7f) != 0) {
        uVar5 = (uVar5 - ((uint)uVar5 & 0x7f)) + 0x80;
      }
      *(undefined1 *)(uVar5 + 0x2978) = 0xff;
      uVar12 = *(uint *)(param_1 + 0x5c) | *(uint *)((longlong)param_1 + 0x2dc) |
               *(uint *)(param_1 + 0x5b) | *(uint *)((longlong)param_1 + 0x2d4) |
               *(uint *)(param_1 + 0x5a);
      if (param_2 == param_1 + 0x12e) {
        uVar4 = 0xff;
        if ((uVar12 & 1) == 0) {
          uVar4 = (char)uVar13;
        }
        *(undefined1 *)(uVar5 + 0x2978) = uVar4;
      }
      else {
        if ((param_2 != param_1 + 0x13b) ||
           ((uVar12 & 1) != 0 || (*(ushort *)(uVar5 + 0x1100) >> 8 & 1) == 0)) {
          bVar11 = (byte)((uint)*(undefined4 *)(*param_1 + 0x1a8) >> 8) & 0x1f;
          for (bVar3 = *(byte *)((longlong)param_1 + 0x275); bVar3 <= bVar11; bVar3 = bVar3 + 1) {
            if ((uVar12 >> (bVar3 & 0x1f) & 1) == 0) goto LAB_14000482d;
          }
          for (bVar3 = 1; bVar3 < *(byte *)((longlong)param_1 + 0x275); bVar3 = bVar3 + 1) {
            if ((uVar12 >> (bVar3 & 0x1f) & 1) == 0) goto LAB_14000482d;
          }
          goto LAB_140004833;
        }
        *(undefined1 *)(uVar5 + 0x2978) = 0;
      }
      goto LAB_14000486f;
    }
    param_3 = bVar11;
    *(undefined1 *)((longlong)param_2 + 3) = 8;
  }
  uVar10 = GetSrbExtension((longlong)param_2);
  *(uint *)(uVar10 + 0x1104) = *(uint *)(uVar10 + 0x1104) | 0x200;
  uVar6 = AhciCompleteRequest(param_1,param_2,param_3);
LAB_1400048cd:
  return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
LAB_14000482d:
  *(byte *)(uVar5 + 0x2978) = bVar3;
LAB_140004833:
  if ((*(short *)(uVar5 + 0x1100) != 0x201) &&
     (bVar3 = *(char *)((longlong)param_1 + 0x275) + 1, *(byte *)((longlong)param_1 + 0x275) = bVar3
     , (uint)bVar3 == (*(uint *)(*param_1 + 0x1a8) >> 8 & 0x1f) + 1)) {
    *(undefined1 *)((longlong)param_1 + 0x275) = 1;
  }
LAB_14000486f:
  lVar14 = *param_1;
  uVar12 = *(uint *)(lVar14 + 0x1a8) >> 8 & 0x1f;
  if (uVar12 < *(byte *)(uVar10 + 0x2978)) {
    lVar7 = IsMiniportInternalSrb((longlong)param_1,(longlong)param_2);
    if ((char)lVar7 == '\0') {
      if (8 < uVar12) {
        uVar12 = 8;
      }
      StorPortDeviceBusy(lVar14,uVar15,uVar16,uVar17,uVar12);
    }
    *(undefined1 *)((longlong)param_2 + 3) = 5;
    uVar10 = GetSrbExtension((longlong)param_2);
    *(uint *)(uVar10 + 0x1104) = *(uint *)(uVar10 + 0x1104) | 0x200;
    AhciCompleteRequest(param_1,param_2,'\x01');
    uVar6 = RecordExecutionHistory(param_1,0x10030020);
  }
  else {
    uVar6 = AhciFormIo(param_1,param_2,bVar11);
  }
  if (param_3 == 0) {
    lVar14 = *param_1;
    if (((char)*(undefined4 *)(lVar14 + 0x2c) < '\0') && ((int)param_1[0x48] != -1)) {
      uVar6 = StorPortExtendedFunction(0xc,lVar14,(int)param_1[0x48],uStack_30 & 0xff);
    }
    else {
      uVar6 = StorPortNotification(0x1004,lVar14,&local_48);
    }
  }
  goto LAB_1400048cd;
}



===== FastFailCommand @ 140004b20 =====

ulonglong FastFailCommand(longlong *param_1)

{
  uint *puVar1;
  uint uVar2;
  ulonglong in_RAX;
  
  if ((((*(uint *)(*param_1 + 0x38) & 0x80000) != 0) &&
      (uVar2 = *(int *)(*param_1 + 0x58) - 5, in_RAX = (ulonglong)uVar2, uVar2 < 0xfffffffa)) &&
     (in_RAX = param_1[0x4a], (in_RAX >> 0x1b & 1) != 0)) {
    LOCK();
    puVar1 = (uint *)((longlong)param_1 + 0xbc);
    uVar2 = *puVar1;
    in_RAX = (ulonglong)uVar2;
    *puVar1 = *puVar1;
    UNLOCK();
    if (uVar2 == 0) {
      return 1;
    }
    LOCK();
    *(uint *)(param_1 + 0x4a) = *(uint *)(param_1 + 0x4a) & 0xf7ffffff;
    UNLOCK();
    LOCK();
    *(undefined4 *)((longlong)param_1 + 0x462c) = 0;
    UNLOCK();
  }
  return in_RAX & 0xffffffffffffff00;
}



===== AhciFormIo @ 140004b80 =====

undefined8 AhciFormIo(longlong *param_1,longlong *param_2,undefined1 param_3)

{
  char cVar1;
  ushort uVar2;
  longlong lVar3;
  uint *puVar4;
  undefined8 uVar5;
  bool bVar6;
  uint uVar7;
  ulonglong uVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  ulonglong uVar12;
  undefined2 *puVar13;
  byte bVar14;
  undefined4 uVar15;
  undefined8 *puVar16;
  size_t _Size;
  longlong *_Src;
  uint uVar17;
  undefined8 *puVar18;
  longlong lVar19;
  void *_Dst;
  byte *pbVar20;
  longlong lVar21;
  uint local_res18 [4];
  
  local_res18[0] = CONCAT31(local_res18[0]._1_3_,param_3);
  uVar7 = 0;
  if (*(char *)((longlong)param_2 + 2) == '(') {
    _Src = (longlong *)0x0;
    if (*(int *)((longlong)param_2 + 0x14) == 0) {
      uVar17 = 0;
      if (*(uint *)(param_2 + 7) != 0) {
        do {
          uVar10 = *(uint *)((longlong)param_2 + (ulonglong)uVar17 * 4 + 0x78);
          uVar12 = (ulonglong)uVar10;
          if ((0x7f < uVar10) &&
             (uVar8 = (ulonglong)*(uint *)(param_2 + 2), uVar10 < *(uint *)(param_2 + 2))) {
            iVar11 = *(int *)(uVar12 + (longlong)param_2);
            if (iVar11 == 0x40) {
              if (uVar12 + 0x28 <= uVar8) {
                cVar9 = *(char *)((longlong)param_2 + uVar12 + 10);
joined_r0x000140005421:
                if (cVar9 != '\0') {
                  _Src = (longlong *)((longlong)param_2 + uVar12 + 0x18);
                }
                break;
              }
            }
            else if (iVar11 == 0x41) {
              if (uVar12 + 0x38 <= uVar8) {
                cVar9 = *(char *)((longlong)param_2 + uVar12 + 10);
                goto joined_r0x000140005421;
              }
            }
            else if ((iVar11 == 0x42) && (uVar12 + 0x28 <= uVar8)) {
              if (*(int *)((longlong)param_2 + uVar12 + 0xc) != 0) {
                _Src = (longlong *)((longlong)param_2 + uVar12 + 0x20);
              }
              break;
            }
          }
          uVar17 = uVar17 + 1;
        } while (uVar17 < *(uint *)(param_2 + 7));
      }
    }
    puVar16 = (undefined8 *)param_2[0xd];
  }
  else {
    puVar16 = (undefined8 *)param_2[7];
    _Src = param_2 + 9;
  }
  if (((ulonglong)puVar16 & 0x7f) != 0) {
    puVar16 = (undefined8 *)((longlong)puVar16 + (0x80 - (ulonglong)((uint)puVar16 & 0x7f)));
  }
  pbVar20 = (byte *)(param_1 + (ulonglong)*(byte *)(puVar16 + 0x52f) * 4 + 0x5f);
  lVar21 = param_1[0x12a] + (ulonglong)*(byte *)(puVar16 + 0x52f) * 0x20;
  *(longlong **)(pbVar20 + 8) = param_2;
  *(longlong *)(pbVar20 + 0x10) = lVar21;
  if (((((*(uint *)((longlong)puVar16 + 0x1104) & 0x40) == 0) && (_Src != (longlong *)0x0)) &&
      (((char)*_Src == '*' || ((char)*_Src == -0x76)))) &&
     (((*_Src & 0x800) != 0 && (uVar17 = IsFuaSupported((longlong)param_1), (char)uVar17 != '\0'))))
  {
    pbVar20[1] = pbVar20[1] | 1;
  }
  if ((*(uint *)(*param_1 + 0x34) & 2) != 0) {
    bVar14 = (char)param_1[0x158] + 1U & 0x3f;
    *(byte *)(param_1 + 0x158) = bVar14;
    *pbVar20 = bVar14;
    puVar18 = (undefined8 *)((ulonglong)bVar14 * 0xb0 + 0xac4 + (longlong)param_1);
    *(uint *)((longlong)puVar18 + 0xa4) = (uint)*(byte *)(puVar16 + 0x52f);
    uVar5 = puVar16[0x222];
    *puVar18 = puVar16[0x221];
    puVar18[1] = uVar5;
    *(undefined4 *)(puVar18 + 2) = *(undefined4 *)param_1[0x129];
    *(undefined4 *)((longlong)puVar18 + 0x14) = *(undefined4 *)(param_1[0x129] + 4);
    *(undefined4 *)(puVar18 + 3) = *(undefined4 *)(param_1[0x129] + 8);
    *(undefined4 *)((longlong)puVar18 + 0x1c) = *(undefined4 *)(param_1[0x129] + 0xc);
    *(undefined4 *)(puVar18 + 4) = *(undefined4 *)(param_1[0x129] + 0x10);
    *(undefined4 *)((longlong)puVar18 + 0x24) = *(undefined4 *)(param_1[0x129] + 0x14);
    *(undefined4 *)(puVar18 + 5) = *(undefined4 *)(param_1[0x129] + 0x18);
    *(undefined4 *)((longlong)puVar18 + 0x2c) = *(undefined4 *)(param_1[0x129] + 0x1c);
    *(undefined4 *)(puVar18 + 6) = *(undefined4 *)(param_1[0x129] + 0x20);
    *(undefined4 *)((longlong)puVar18 + 0x34) = *(undefined4 *)(param_1[0x129] + 0x24);
    *(undefined4 *)(puVar18 + 7) = *(undefined4 *)(param_1[0x129] + 0x28);
    *(undefined4 *)((longlong)puVar18 + 0x3c) = *(undefined4 *)(param_1[0x129] + 0x2c);
    *(undefined4 *)(puVar18 + 8) = *(undefined4 *)(param_1[0x129] + 0x30);
    *(undefined4 *)((longlong)puVar18 + 0x44) = *(undefined4 *)(param_1[0x129] + 0x34);
    *(undefined4 *)(puVar18 + 9) = *(undefined4 *)(param_1[0x129] + 0x38);
    *(undefined4 *)((longlong)puVar18 + 0x4c) = *(undefined4 *)(param_1[0x129] + 0x3c);
    bVar14 = *(byte *)(*(longlong *)(pbVar20 + 8) + 2);
    if (bVar14 == 0x28) {
      uVar17 = *(uint *)(*(longlong *)(pbVar20 + 8) + 0x14);
    }
    else {
      uVar17 = (uint)bVar14;
    }
    *(uint *)(puVar18 + 0x15) = uVar17;
    *(undefined4 *)((longlong)puVar18 + 0xac) = 0;
  }
  uVar2 = *(ushort *)(puVar16 + 0x220);
  if ((uVar2 >> 9 & 1) == 0) {
    if (uVar2 == 0x400) {
      CfistoATA_CFIS(param_1,(longlong)pbVar20);
      goto LAB_140004ca4;
    }
    lVar3 = *(longlong *)(pbVar20 + 8);
    if ((uVar2 & 0x100) != 0) {
      if (*(char *)(lVar3 + 2) == '(') {
        puVar13 = *(undefined2 **)(lVar3 + 0x68);
      }
      else {
        puVar13 = *(undefined2 **)(lVar3 + 0x38);
      }
      if (((ulonglong)puVar13 & 0x7f) != 0) {
        puVar13 = (undefined2 *)((longlong)puVar13 + (0x80 - (ulonglong)((uint)puVar13 & 0x7f)));
      }
      cVar9 = *(char *)(puVar13 + 0x887);
      *puVar13 = 0x8027;
      *(char *)(puVar13 + 1) = cVar9;
      if (puVar13[0x880] == 0x400) {
        cVar9 = *(char *)(puVar13 + 0x885);
LAB_14000524a:
        if ((1 < (byte)(cVar9 + 0xa0U)) && (2 < (byte)(cVar9 + 0x9dU))) goto LAB_140005436;
        bVar6 = true;
      }
      else {
        if ((puVar13[0x880] & 0x100) != 0) goto LAB_14000524a;
LAB_140005436:
        bVar6 = false;
      }
      bVar14 = *(byte *)((longlong)puVar13 + 0x110d);
      if (bVar6) {
        *(char *)(puVar13 + 6) = *(char *)(puVar13 + 0x14bc) << 3;
        *(byte *)((longlong)puVar13 + 7) = bVar14 & 0xf | 0x40;
        *(undefined1 *)((longlong)puVar13 + 3) = *(undefined1 *)((longlong)puVar13 + 0x1109);
        *(undefined1 *)((longlong)puVar13 + 0xb) = *(undefined1 *)((longlong)puVar13 + 0x1111);
        if ((pbVar20[1] & 1) != 0) {
          bVar14 = bVar14 & 0xf | 0xc0;
          goto LAB_140005292;
        }
      }
      else {
        *(undefined1 *)((longlong)puVar13 + 3) = *(undefined1 *)(puVar13 + 0x884);
        *(undefined1 *)((longlong)puVar13 + 0xb) = *(undefined1 *)(puVar13 + 0x888);
        *(undefined1 *)(puVar13 + 6) = *(undefined1 *)((longlong)puVar13 + 0x1109);
        *(undefined1 *)((longlong)puVar13 + 0xd) = *(undefined1 *)((longlong)puVar13 + 0x1111);
LAB_140005292:
        *(byte *)((longlong)puVar13 + 7) = bVar14;
      }
      *(undefined1 *)(puVar13 + 2) = *(undefined1 *)(puVar13 + 0x885);
      *(undefined1 *)(puVar13 + 4) = *(undefined1 *)(puVar13 + 0x889);
      *(undefined1 *)((longlong)puVar13 + 5) = *(undefined1 *)((longlong)puVar13 + 0x110b);
      *(undefined1 *)((longlong)puVar13 + 9) = *(undefined1 *)((longlong)puVar13 + 0x1113);
      *(undefined1 *)(puVar13 + 3) = *(undefined1 *)(puVar13 + 0x886);
      *(undefined1 *)(puVar13 + 5) = *(undefined1 *)(puVar13 + 0x88a);
      *(undefined4 *)(puVar13 + 7) = 0;
      puVar13[9] = 0;
      goto LAB_140004ca4;
    }
    *(undefined1 *)(lVar3 + 3) = 6;
    AhciCompleteJustSlottedRequest(param_1,param_2,'\x01');
    uVar15 = 0x10070020;
  }
  else {
    lVar3 = *(longlong *)(pbVar20 + 8);
    cVar9 = *(char *)(lVar3 + 2);
    if (cVar9 == '(') {
      puVar13 = *(undefined2 **)(lVar3 + 0x68);
    }
    else {
      puVar13 = *(undefined2 **)(lVar3 + 0x38);
    }
    if (((ulonglong)puVar13 & 0x7f) != 0) {
      puVar13 = (undefined2 *)((longlong)puVar13 + (0x80 - (ulonglong)((uint)puVar13 & 0x7f)));
    }
    if (cVar9 == '(') {
      puVar18 = (undefined8 *)0x0;
      if (*(int *)(lVar3 + 0x14) == 0) {
        uVar12 = 0;
        local_res18[0] = 0;
        if (*(uint *)(lVar3 + 0x38) != 0) {
          do {
            uVar17 = *(uint *)(lVar3 + 0x78 + uVar12 * 4);
            if ((0x7f < uVar17) &&
               (uVar12 = (ulonglong)*(uint *)(lVar3 + 0x10), uVar17 < *(uint *)(lVar3 + 0x10))) {
              uVar8 = (ulonglong)uVar17;
              iVar11 = *(int *)(lVar3 + (ulonglong)uVar17);
              if (iVar11 == 0x40) {
                if (uVar8 + 0x28 <= uVar12) {
                  cVar1 = *(char *)(lVar3 + 10 + uVar8);
joined_r0x0001400054c2:
                  if (cVar1 != '\0') {
                    lVar19 = uVar8 + 0x18;
LAB_140004f08:
                    puVar18 = (undefined8 *)(lVar19 + lVar3);
                  }
                  break;
                }
              }
              else if (iVar11 == 0x41) {
                if (uVar8 + 0x38 <= uVar12) {
                  cVar1 = *(char *)(lVar3 + 10 + uVar8);
                  goto joined_r0x0001400054c2;
                }
              }
              else if ((iVar11 == 0x42) && (uVar8 + 0x28 <= uVar12)) {
                if (*(int *)(lVar3 + 0xc + uVar8) != 0) {
                  lVar19 = uVar8 + 0x20;
                  goto LAB_140004f08;
                }
                break;
              }
            }
            local_res18[0] = local_res18[0] + 1;
            uVar12 = (ulonglong)local_res18[0];
          } while (local_res18[0] < *(uint *)(lVar3 + 0x38));
        }
      }
      uVar12 = *(ulonglong *)(lVar3 + 0x68);
    }
    else {
      uVar12 = *(ulonglong *)(lVar3 + 0x38);
      puVar18 = (undefined8 *)(lVar3 + 0x48);
    }
    if ((uVar12 & 0x7f) != 0) {
      uVar12 = (uVar12 - ((uint)uVar12 & 0x7f)) + 0x80;
    }
    iVar11 = *(int *)(uVar12 + 0x1130);
    if (iVar11 == 0) {
      if (cVar9 == '(') {
        iVar11 = *(int *)(lVar3 + 0x3c);
      }
      else {
        iVar11 = *(int *)(lVar3 + 0x10);
      }
    }
    if (puVar18 != (undefined8 *)0x0) {
      uVar5 = puVar18[1];
      *(undefined8 *)(puVar13 + 0x20) = *puVar18;
      *(undefined8 *)(puVar13 + 0x24) = uVar5;
    }
    *puVar13 = 0x8027;
    *(undefined1 *)(puVar13 + 1) = 0xa0;
    if ((*(uint *)(puVar13 + 0x882) & 0x10) == 0) {
      *(undefined1 *)((longlong)puVar13 + 3) = 0;
    }
    else {
      *(undefined1 *)((longlong)puVar13 + 3) = 1;
      lVar3 = param_1[0x18];
      if ((((*(short *)(lVar3 + 0x7c) < 0) && ((*(ushort *)(lVar3 + 0x62) & 0x100) != 0)) &&
          (-1 < (short)*(ushort *)(lVar3 + 0x62))) &&
         (((*(byte *)(lVar3 + 0x7e) & 7) == 0 && ((*(byte *)(lVar3 + 0xb0) & 0x7f) == 0)))) {
        *(byte *)((longlong)puVar13 + 3) = ((byte)*(uint *)(puVar13 + 0x882) & 2) * '\x02' | 1;
      }
    }
    *(char *)((longlong)puVar13 + 5) = (char)iVar11;
    *(char *)(puVar13 + 3) = (char)((uint)iVar11 >> 8);
    *(undefined1 *)(puVar13 + 2) = 0;
    *(undefined8 *)((longlong)puVar13 + 7) = 0;
    *(undefined4 *)((longlong)puVar13 + 0xf) = 0;
    *(undefined1 *)((longlong)puVar13 + 0x13) = 0;
LAB_140004ca4:
    if ((*(uint *)(*param_1 + 0x34) & 2) != 0) {
      _Dst = (void *)((ulonglong)*pbVar20 * 0x3c + 0x36c4 + (longlong)param_1);
      if (_Src != (longlong *)0x0) {
        cVar9 = *(char *)((longlong)param_2 + 2);
        bVar14 = 0;
        local_res18[0] = CONCAT31(local_res18[0]._1_3_,cVar9);
        if (cVar9 == '(') {
          if (*(int *)((longlong)param_2 + 0x14) == 0) {
            uVar12 = 0;
            if (*(uint *)(param_2 + 7) != 0) {
              do {
                uVar17 = *(uint *)((longlong)param_2 + uVar12 * 4 + 0x78);
                if ((0x7f < uVar17) && (uVar10 = *(uint *)(param_2 + 2), uVar17 < uVar10)) {
                  uVar8 = (ulonglong)uVar17;
                  iVar11 = *(int *)((ulonglong)uVar17 + (longlong)param_2);
                  if (iVar11 == 0x40) {
                    uVar8 = uVar8 + 0x28;
                  }
                  else {
                    if (iVar11 != 0x41) {
                      if ((iVar11 != 0x42) || ((ulonglong)uVar10 < uVar8 + 0x28))
                      goto LAB_140026702;
                      break;
                    }
                    uVar8 = uVar8 + 0x38;
                  }
                  if (uVar8 <= uVar10) {
                    bVar14 = *(byte *)((longlong)((ulonglong)uVar17 + (longlong)param_2) + 10);
                    break;
                  }
                }
LAB_140026702:
                uVar17 = (int)uVar12 + 1;
                uVar12 = (ulonglong)uVar17;
              } while (uVar17 < *(uint *)(param_2 + 7));
              goto LAB_14002671a;
            }
            goto LAB_1400265f8;
          }
LAB_14002675d:
          bVar14 = 0;
LAB_140026670:
          _Size = (size_t)bVar14;
        }
        else {
          bVar14 = *(byte *)((longlong)param_2 + 10);
LAB_14002671a:
          if (bVar14 < 0x10) {
LAB_1400265f8:
            bVar14 = 0;
            if (cVar9 == '(') {
              if (*(int *)((longlong)param_2 + 0x14) != 0) goto LAB_14002675d;
              uVar12 = 0;
              if (*(uint *)(param_2 + 7) != 0) {
                do {
                  uVar17 = *(uint *)((longlong)param_2 + uVar12 * 4 + 0x78);
                  bVar14 = 0;
                  if ((0x7f < uVar17) && (uVar10 = *(uint *)(param_2 + 2), uVar17 < uVar10)) {
                    uVar8 = (ulonglong)uVar17;
                    iVar11 = *(int *)((ulonglong)uVar17 + (longlong)param_2);
                    if (iVar11 == 0x40) {
                      uVar8 = uVar8 + 0x28;
                    }
                    else {
                      if (iVar11 != 0x41) {
                        if ((iVar11 != 0x42) || ((ulonglong)uVar10 < uVar8 + 0x28))
                        goto LAB_14002674c;
                        break;
                      }
                      uVar8 = uVar8 + 0x38;
                    }
                    if (uVar8 <= uVar10) {
                      bVar14 = *(byte *)((longlong)((ulonglong)uVar17 + (longlong)param_2) + 10);
                      break;
                    }
                  }
LAB_14002674c:
                  uVar17 = (int)uVar12 + 1;
                  uVar12 = (ulonglong)uVar17;
                } while (uVar17 < *(uint *)(param_2 + 7));
              }
            }
            else {
              bVar14 = *(byte *)((longlong)param_2 + 10);
            }
            goto LAB_140026670;
          }
          _Size = 0x10;
        }
        memcpy(_Dst,_Src,_Size);
      }
      uVar5 = puVar16[1];
      *(undefined8 *)((longlong)_Dst + 0x10) = *puVar16;
      *(undefined8 *)((longlong)_Dst + 0x18) = uVar5;
      *(uint *)((longlong)_Dst + 0x38) = (uint)*(byte *)(puVar16 + 0x52f);
    }
    lVar3 = *(longlong *)(pbVar20 + 8);
    if (*(char *)(lVar3 + 2) == '(') {
      uVar12 = *(ulonglong *)(lVar3 + 0x68);
    }
    else {
      uVar12 = *(ulonglong *)(lVar3 + 0x38);
    }
    if ((uVar12 & 0x7f) != 0) {
      uVar12 = (uVar12 - ((uint)uVar12 & 0x7f)) + 0x80;
    }
    if ((((*(uint *)(uVar12 + 0x1104) & 6) == 0) && (*(longlong *)(uVar12 + 0x1120) == 0)) ||
       (uVar7 = SRBtoPRDT(param_1,(longlong)pbVar20), uVar7 != 0xffffffff)) {
      lVar3 = *(longlong *)(pbVar20 + 8);
      puVar4 = *(uint **)(pbVar20 + 0x10);
      if (*(char *)(lVar3 + 2) == '(') {
        uVar12 = *(ulonglong *)(lVar3 + 0x68);
      }
      else {
        uVar12 = *(ulonglong *)(lVar3 + 0x38);
      }
      if ((uVar12 & 0x7f) != 0) {
        uVar12 = (uVar12 - ((uint)uVar12 & 0x7f)) + 0x80;
      }
      *(short *)((longlong)puVar4 + 2) = (short)uVar7;
      uVar7 = *puVar4;
      *puVar4 = uVar7 & 0xffffffe5 | 5;
      uVar10 = *(ushort *)(uVar12 + 0x1100) >> 4 & 0x20;
      *puVar4 = uVar10 | uVar7 & 0xffffffc5 | 5;
      uVar17 = *(uint *)(uVar12 + 0x1104);
      puVar4[1] = 0;
      *puVar4 = (uVar17 & 4) << 4 | uVar10 | uVar7 & 0xffff0805 | 5;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
      puVar4[7] = 0;
      if (param_1 + 0x12e == param_2) {
        uVar12 = param_1[0x13a];
      }
      else if (param_1 + 0x13b == param_2) {
        uVar12 = param_1[0x147];
      }
      else {
        local_res18[0] = 0;
        uVar12 = StorPortGetPhysicalAddress(*param_1,param_2,puVar16,local_res18);
      }
      if ((uVar12 & 0x7f) != 0) {
        *(undefined1 *)(*(longlong *)(pbVar20 + 8) + 3) = 6;
        if (*(char *)((longlong)param_2 + 2) == '(') {
          uVar12 = param_2[0xd];
        }
        else {
          uVar12 = param_2[7];
        }
        if ((uVar12 & 0x7f) != 0) {
          uVar12 = (uVar12 - ((uint)uVar12 & 0x7f)) + 0x80;
        }
        uVar8 = (ulonglong)*(byte *)(uVar12 + 0x2978);
        if (*(short *)(uVar12 + 0x1100) == 0x201) {
          if (*(char *)((longlong)param_2 + 2) == '(') {
            param_2 = (longlong *)param_2[10];
          }
          else {
            param_2 = (longlong *)param_2[6];
          }
          *(byte *)((longlong)param_2 + 3) = *(byte *)((longlong)param_2 + 3) & 0x7f;
          *(undefined2 *)(uVar12 + 0x1100) = 0;
        }
        pbVar20 = (byte *)(uVar8 * 0x20 + 0x2f9 + (longlong)param_1);
        *pbVar20 = *pbVar20 & 0xfe;
        param_1[uVar8 * 4 + 0x61] = 0;
        *(undefined1 *)(param_1 + uVar8 * 4 + 0x5f) = 0;
        param_1[uVar8 * 4 + 0x60] = 0;
        uVar7 = 1 << (*(byte *)(uVar12 + 0x2978) & 0x1f);
        if ((uVar7 & *(uint *)((longlong)param_1 + 0x2cc)) != 0) {
          *(uint *)((longlong)param_1 + 0x2cc) = ~uVar7 & *(uint *)((longlong)param_1 + 0x2cc);
        }
        uVar7 = 1 << (*(byte *)(uVar12 + 0x2978) & 0x1f);
        if ((uVar7 & *(uint *)(param_1 + 0x5a)) != 0) {
          *(uint *)(param_1 + 0x5a) = ~uVar7 & *(uint *)(param_1 + 0x5a);
        }
        uVar7 = 1 << (*(byte *)(uVar12 + 0x2978) & 0x1f);
        if ((uVar7 & *(uint *)((longlong)param_1 + 0x2d4)) != 0) {
          *(uint *)((longlong)param_1 + 0x2d4) = ~uVar7 & *(uint *)((longlong)param_1 + 0x2d4);
        }
        uVar7 = 1 << (*(byte *)(uVar12 + 0x2978) & 0x1f);
        if ((uVar7 & *(uint *)(param_1 + 0x5b)) != 0) {
          *(uint *)(param_1 + 0x5b) = ~uVar7 & *(uint *)(param_1 + 0x5b);
        }
        uVar7 = 1 << (*(byte *)(uVar12 + 0x2978) & 0x1f);
        if ((uVar7 & *(uint *)(param_1 + 0x5c)) != 0) {
          *(uint *)(param_1 + 0x5c) = ~uVar7 & *(uint *)(param_1 + 0x5c);
        }
        AhciCompleteRequest(param_1,param_2,'\x01');
        lVar21 = RecordExecutionHistory(param_1,0x10080020);
        goto LAB_140004e26;
      }
      *(int *)(lVar21 + 8) = (int)uVar12;
      if (*(int *)(*param_1 + 0x1a8) < 0) {
        *(int *)(lVar21 + 0xc) = (int)(uVar12 >> 0x20);
      }
      if ((char)*(undefined4 *)((longlong)puVar16 + 0x1104) < '\0') {
        *(uint *)((longlong)param_1 + 0x2cc) =
             *(uint *)((longlong)param_1 + 0x2cc) | 1 << (*(byte *)(puVar16 + 0x52f) & 0x1f);
      }
      if (*(ushort *)(puVar16 + 0x220) == 0x400) {
        cVar9 = *(char *)((longlong)puVar16 + 0x110a);
LAB_140004dfa:
        if ((1 < (byte)(cVar9 + 0xa0U)) && (2 < (byte)(cVar9 + 0x9dU))) goto LAB_140005308;
        *(uint *)(param_1 + 0x5a) =
             *(uint *)(param_1 + 0x5a) | 1 << (*(byte *)(puVar16 + 0x52f) & 0x1f);
      }
      else {
        if ((*(ushort *)(puVar16 + 0x220) >> 8 & 1) != 0) {
          cVar9 = *(char *)((longlong)puVar16 + 0x110e);
          goto LAB_140004dfa;
        }
LAB_140005308:
        if ((*(uint *)((longlong)puVar16 + 0x1104) & 0x40) == 0) {
          lVar21 = *(longlong *)(pbVar20 + 8);
          if (*(char *)(lVar21 + 2) == '(') {
            uVar12 = *(ulonglong *)(lVar21 + 0x68);
          }
          else {
            uVar12 = *(ulonglong *)(lVar21 + 0x38);
          }
          if ((uVar12 & 0x7f) != 0) {
            uVar12 = (uVar12 - ((uint)uVar12 & 0x7f)) + 0x80;
          }
          bVar14 = *(byte *)(uVar12 + 0x110e);
          if ((((bVar14 < 0x3f) && ((0x6271027100000000U >> ((ulonglong)bVar14 & 0x3f) & 1) != 0))
              || (((byte)(bVar14 + 0x3c) < 0xb &&
                  ((0x553U >> ((byte)(bVar14 + 0x3c) & 0x1f) & 1) != 0)))) ||
             (*(short *)(uVar12 + 0x1100) == 0x200)) {
            *(uint *)((longlong)param_1 + 0x2d4) =
                 *(uint *)((longlong)param_1 + 0x2d4) | 1 << (*(byte *)(puVar16 + 0x52f) & 0x1f);
            goto LAB_140004e17;
          }
        }
        *(uint *)(param_1 + 0x5b) =
             *(uint *)(param_1 + 0x5b) | 1 << (*(byte *)(puVar16 + 0x52f) & 0x1f);
      }
LAB_140004e17:
      lVar21 = *param_1;
      if ((*(uint *)(lVar21 + 0x34) & 1) == 0) goto LAB_140004e26;
      uVar15 = 0x10000020;
    }
    else {
      *(undefined1 *)(*(longlong *)(pbVar20 + 8) + 3) = 6;
      if (*(char *)((longlong)param_2 + 2) == '(') {
        uVar12 = param_2[0xd];
      }
      else {
        uVar12 = param_2[7];
      }
      if ((uVar12 & 0x7f) != 0) {
        uVar12 = (uVar12 - ((uint)uVar12 & 0x7f)) + 0x80;
      }
      uVar8 = (ulonglong)*(byte *)(uVar12 + 0x2978);
      if (*(short *)(uVar12 + 0x1100) == 0x201) {
        if (*(char *)((longlong)param_2 + 2) == '(') {
          param_2 = (longlong *)param_2[10];
        }
        else {
          param_2 = (longlong *)param_2[6];
        }
        *(byte *)((longlong)param_2 + 3) = *(byte *)((longlong)param_2 + 3) & 0x7f;
        *(undefined2 *)(uVar12 + 0x1100) = 0;
      }
      pbVar20 = (byte *)(uVar8 * 0x20 + 0x2f9 + (longlong)param_1);
      *pbVar20 = *pbVar20 & 0xfe;
      param_1[uVar8 * 4 + 0x61] = 0;
      *(undefined1 *)(param_1 + uVar8 * 4 + 0x5f) = 0;
      param_1[uVar8 * 4 + 0x60] = 0;
      uVar7 = 1 << (*(byte *)(uVar12 + 0x2978) & 0x1f);
      if ((uVar7 & *(uint *)((longlong)param_1 + 0x2cc)) != 0) {
        *(uint *)((longlong)param_1 + 0x2cc) = ~uVar7 & *(uint *)((longlong)param_1 + 0x2cc);
      }
      uVar7 = 1 << (*(byte *)(uVar12 + 0x2978) & 0x1f);
      if ((uVar7 & *(uint *)(param_1 + 0x5a)) != 0) {
        *(uint *)(param_1 + 0x5a) = ~uVar7 & *(uint *)(param_1 + 0x5a);
      }
      uVar7 = 1 << (*(byte *)(uVar12 + 0x2978) & 0x1f);
      if ((uVar7 & *(uint *)((longlong)param_1 + 0x2d4)) != 0) {
        *(uint *)((longlong)param_1 + 0x2d4) = ~uVar7 & *(uint *)((longlong)param_1 + 0x2d4);
      }
      uVar7 = 1 << (*(byte *)(uVar12 + 0x2978) & 0x1f);
      if ((uVar7 & *(uint *)(param_1 + 0x5b)) != 0) {
        *(uint *)(param_1 + 0x5b) = ~uVar7 & *(uint *)(param_1 + 0x5b);
      }
      uVar7 = 1 << (*(byte *)(uVar12 + 0x2978) & 0x1f);
      if ((uVar7 & *(uint *)(param_1 + 0x5c)) != 0) {
        *(uint *)(param_1 + 0x5c) = ~uVar7 & *(uint *)(param_1 + 0x5c);
      }
      AhciCompleteRequest(param_1,param_2,'\x01');
      uVar15 = 0x10060020;
    }
  }
  lVar21 = RecordExecutionHistory(param_1,uVar15);
LAB_140004e26:
  return CONCAT71((int7)((ulonglong)lVar21 >> 8),1);
}



===== SRBtoPRDT @ 140005680 =====

uint SRBtoPRDT(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong uVar12;
  
  lVar1 = *(longlong *)(param_2 + 8);
  if (*(char *)(lVar1 + 2) == '(') {
    uVar8 = *(ulonglong *)(lVar1 + 0x68);
  }
  else {
    uVar8 = *(ulonglong *)(lVar1 + 0x38);
  }
  if ((uVar8 & 0x7f) != 0) {
    uVar8 = (uVar8 - ((uint)uVar8 & 0x7f)) + 0x80;
  }
  puVar2 = *(uint **)(uVar8 + 0x1138);
  if (puVar2 == (uint *)0x0) {
LAB_1400057fb:
    uVar5 = 0xffffffff;
  }
  else {
    uVar9 = 0;
    while( true ) {
      uVar5 = *puVar2;
      uVar3 = (uint)uVar9;
      if (uVar5 <= uVar3) break;
      puVar7 = puVar2 + uVar9 * 6;
      if ((puVar2[uVar9 * 6 + 4] & 1) != 0) goto LAB_1400057fb;
      if (*(int *)(*param_1 + 0x48) == 0) {
        if (puVar7[6] == 0x20000) {
          *(uint *)(uVar8 + 0x80) = puVar2[4];
          if (*(int *)(*param_1 + 0x1a8) < 0) {
            *(uint *)(uVar8 + 0x84) = puVar2[5];
          }
          *(uint *)(uVar8 + 0x8c) = *(uint *)(uVar8 + 0x8c) & 0xffc0ffff | 0xffff;
          *(uint *)(uVar8 + 0x90) = puVar2[4] + 0x10000;
          if (*(int *)(*param_1 + 0x1a8) < 0) {
            if (puVar2[4] + 0x10000 < puVar2[4]) {
              *(uint *)(uVar8 + 0x94) = puVar2[5] + 1;
            }
            else {
              *(uint *)(uVar8 + 0x94) = puVar2[5];
            }
          }
          *(uint *)(uVar8 + 0x9c) = *(uint *)(uVar8 + 0x9c) & 0xffc0ffff | 0xffff;
          return 2;
        }
      }
      else if ((uint)(*(int *)(*param_1 + 0x48) * 0x400) < puVar7[6]) goto LAB_1400057fb;
      *(uint *)(uVar8 + (uVar9 + 8) * 0x10) = puVar2[uVar9 * 6 + 4];
      if (*(int *)(*param_1 + 0x1a8) < 0) {
        *(uint *)(uVar8 + 0x84 + uVar9 * 0x10) = puVar7[5];
      }
      uVar5 = puVar7[6];
      uVar12 = uVar9;
      if ((uVar5 & 1) == 0) {
        if (((*(uint *)(*param_1 + 0x38) & 0x20000) != 0) && (*(uint *)(*param_1 + 0x48) < 0x3fd)) {
          uVar10 = *puVar2;
          if ((4 < uVar10) && ((uVar3 == uVar10 - 1 && (((byte)uVar10 & 3) == 1)))) {
            uVar5 = uVar5 >> 1;
            lVar1 = (ulonglong)(uVar3 + 1) + 8;
            lVar11 = (ulonglong)(uVar3 + 1) * 0x10;
            uVar10 = *(uint *)(uVar8 + 0x8c + uVar9 * 0x10);
            if ((uVar5 & 1) == 0) {
              uVar3 = uVar5 - 1;
              *(uint *)(uVar8 + 0x8c + uVar9 * 0x10) = (uVar3 ^ uVar10) & 0x3fffff ^ uVar10;
              *(uint *)(uVar8 + lVar1 * 0x10) = puVar2[uVar9 * 6 + 4] + uVar5;
              if (*(int *)(*param_1 + 0x1a8) < 0) {
                *(uint *)(lVar11 + 0x84 + uVar8) = puVar2[uVar9 * 6 + 5];
              }
            }
            else {
              *(uint *)(uVar8 + 0x8c + uVar9 * 0x10) = (uVar5 ^ uVar10) & 0x3fffff ^ uVar10;
              *(uint *)(uVar8 + lVar1 * 0x10) = puVar2[uVar9 * 6 + 4] + 1 + uVar5;
              if (*(int *)(*param_1 + 0x1a8) < 0) {
                *(uint *)(lVar11 + 0x84 + uVar8) = puVar2[uVar9 * 6 + 5];
              }
              uVar3 = uVar5 - 2;
            }
            puVar7 = (uint *)(uVar8 + 0x8c + lVar11);
LAB_1400058da:
            *puVar7 = (uVar3 ^ *puVar7) & 0x3fffff ^ *puVar7;
            return *puVar2 + 1;
          }
        }
        uVar5 = uVar5 - 1;
      }
      else {
        lVar1 = *(longlong *)(param_2 + 8);
        uVar4 = GetSrbExtension(lVar1);
        uVar3 = *(uint *)(uVar4 + 0x1130);
        if (uVar3 == 0) {
          if (*(char *)(lVar1 + 2) == '(') {
            uVar3 = *(uint *)(lVar1 + 0x3c);
          }
          else {
            uVar3 = *(uint *)(lVar1 + 0x10);
          }
        }
        if (uVar3 < uVar5) goto LAB_1400057fb;
        uVar4 = GetSrbExtension(lVar1);
        iVar6 = *(int *)(uVar4 + 0x1130);
        if (iVar6 == 0) {
          if (*(char *)(lVar1 + 2) == '(') {
            iVar6 = *(int *)(lVar1 + 0x3c);
          }
          else {
            iVar6 = *(int *)(lVar1 + 0x10);
          }
        }
        RequestSetDataTransferLength(lVar1,iVar6 + -1);
        if (((*(uint *)(*param_1 + 0x38) & 0x20000) != 0) && (*(uint *)(*param_1 + 0x48) < 0x3fd)) {
          uVar5 = *puVar2;
          if (((int)uVar12 == uVar5 - 1) && ((4 < uVar5 && (((byte)uVar5 & 3) == 1)))) {
            uVar10 = puVar2[uVar12 * 6 + 6] - 1 >> 1;
            uVar3 = (int)uVar12 + 1;
            uVar5 = *(uint *)(uVar8 + 0x8c + uVar9 * 0x10);
            lVar1 = (ulonglong)uVar3 + 8;
            lVar11 = (ulonglong)uVar3 * 0x10;
            if ((uVar10 & 1) == 0) {
              uVar3 = uVar10 - 1;
              *(uint *)(uVar8 + 0x8c + uVar9 * 0x10) = (uVar3 ^ uVar5) & 0x3fffff ^ uVar5;
              *(uint *)(uVar8 + lVar1 * 0x10) = puVar2[uVar12 * 6 + 4] + uVar10;
              if (*(int *)(*param_1 + 0x1a8) < 0) {
                *(uint *)(lVar11 + 0x84 + uVar8) = puVar2[uVar9 * 6 + 5];
              }
            }
            else {
              *(uint *)(uVar8 + 0x8c + uVar9 * 0x10) = (uVar10 ^ uVar5) & 0x3fffff ^ uVar5;
              *(uint *)(uVar8 + lVar1 * 0x10) = puVar2[uVar12 * 6 + 4] + 1 + uVar10;
              if (*(int *)(*param_1 + 0x1a8) < 0) {
                *(uint *)(lVar11 + 0x84 + uVar8) = puVar2[uVar9 * 6 + 5];
              }
              uVar3 = uVar10 - 2;
            }
            puVar7 = (uint *)(uVar8 + 0x8c + lVar11);
            goto LAB_1400058da;
          }
        }
        uVar5 = puVar7[6] - 2;
      }
      puVar7 = (uint *)(uVar9 * 0x10 + 0x8c + uVar8);
      uVar3 = *puVar7;
      *puVar7 = (uVar5 ^ uVar3) & 0x3fffff ^ uVar3;
      uVar9 = (ulonglong)((int)uVar12 + 1);
    }
  }
  return uVar5;
}



===== CfistoATA_CFIS @ 140005ad0 =====

void CfistoATA_CFIS(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  undefined8 *puVar3;
  
  lVar1 = *(longlong *)(param_2 + 8);
  if (*(char *)(lVar1 + 2) == '(') {
    puVar3 = *(undefined8 **)(lVar1 + 0x68);
  }
  else {
    puVar3 = *(undefined8 **)(lVar1 + 0x38);
  }
  if (((ulonglong)puVar3 & 0x7f) != 0) {
    puVar3 = (undefined8 *)((longlong)puVar3 + (0x80 - (ulonglong)((uint)puVar3 & 0x7f)));
  }
  *puVar3 = puVar3[0x221];
  puVar3[1] = puVar3[0x222];
  *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(puVar3 + 0x223);
  if (*(char *)(*param_1 + 0x18c) == '\x02') {
    if (*(ushort *)(puVar3 + 0x220) == 0x400) {
      cVar2 = *(char *)((longlong)puVar3 + 0x110a);
    }
    else {
      if ((*(ushort *)(puVar3 + 0x220) >> 8 & 1) == 0) goto LAB_140005b58;
      cVar2 = *(char *)((longlong)puVar3 + 0x110e);
    }
    if (((cVar2 == 'a') && (*(char *)((longlong)puVar3 + 0x2979) != '\0')) &&
       (-1 < (char)param_1[0x4a])) {
      *(undefined1 *)((longlong)puVar3 + 0x12) = 0;
    }
  }
LAB_140005b58:
  if (*(ushort *)(puVar3 + 0x220) == 0x400) {
    cVar2 = *(char *)((longlong)puVar3 + 0x110a);
  }
  else {
    if ((*(ushort *)(puVar3 + 0x220) >> 8 & 1) == 0) goto LAB_140005b98;
    cVar2 = *(char *)((longlong)puVar3 + 0x110e);
  }
  if (((byte)(cVar2 + 0xa0U) < 2) || ((byte)(cVar2 + 0x9dU) < 3)) {
    *(char *)((longlong)puVar3 + 0xc) = *(char *)(puVar3 + 0x52f) << 3;
  }
LAB_140005b98:
  *(undefined2 *)puVar3 = 0x8027;
  *(undefined1 *)((longlong)puVar3 + 0x11) = 0;
  *(undefined1 *)((longlong)puVar3 + 0x13) = 0;
  *(undefined2 *)((longlong)puVar3 + 0xe) = 0;
  return;
}



===== SrbConvertToATACommand @ 140005bc0 =====

/* WARNING: Removing unreachable block (ram,0x000140005ffc) */
/* WARNING: Removing unreachable block (ram,0x00014000600a) */

ulonglong SrbConvertToATACommand(ulonglong *param_1,longlong param_2,byte *param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  ulonglong extraout_RAX;
  ulonglong uVar5;
  ulonglong uVar6;
  
  bVar2 = *param_3;
  uVar6 = 0xc1000007;
  if (bVar2 == 0x8a) {
switchD_140005d48_caseD_28:
    if (*(char *)(param_2 + 2) == '(') {
      uVar6 = *(ulonglong *)(param_2 + 0x68);
    }
    else {
      uVar6 = *(ulonglong *)(param_2 + 0x38);
    }
    if ((uVar6 & 0x7f) != 0) {
      uVar6 = (uVar6 - ((uint)uVar6 & 0x7f)) + 0x80;
    }
    if (*(char *)(param_2 + 2) == '(') {
      uVar4 = *(uint *)(param_2 + 0x18);
    }
    else {
      uVar4 = *(uint *)(param_2 + 0xc);
    }
    if (((((int)param_1[3] == 1) || ((int)param_1[3] - 3U < 3)) &&
        (*(int *)((longlong)param_1 + 0x24) != 0)) && ((uVar4 & 0xc0) != 0)) {
      uVar4 = *(uint *)(uVar6 + 0x1104);
      uVar3 = uVar4 | 0x10;
      *(uint *)(uVar6 + 0x1104) = uVar3;
      if ((int)param_1[6] == 2) {
        uVar3 = uVar4 | 0x18;
        *(uint *)(uVar6 + 0x1104) = uVar3;
      }
      bVar2 = *param_3;
      if (bVar2 == 0x28) {
LAB_140005ced:
        uVar3 = uVar3 | 2;
      }
      else {
        if (bVar2 != 0x2a) {
          if (bVar2 == 0x88) goto LAB_140005ced;
          if (bVar2 != 0x8a) goto LAB_140005e54;
        }
        uVar3 = uVar3 | 4;
      }
      *(uint *)(uVar6 + 0x1104) = uVar3;
      BuildReadWriteCommand((longlong *)param_1,param_2,(char *)param_3,param_4);
      return 0;
    }
LAB_140005e54:
    uVar6 = 0xc1000006;
    goto switchD_140005d48_caseD_1;
  }
  if (bVar2 == 0x25) {
    uVar6 = 0;
    if (*(char *)(param_2 + 2) == '(') {
      uVar5 = *(ulonglong *)(param_2 + 0x68);
    }
    else {
      uVar5 = *(ulonglong *)(param_2 + 0x38);
    }
    if ((uVar5 & 0x7f) != 0) {
      uVar5 = (uVar5 - ((uint)uVar5 & 0x7f)) + 0x80;
    }
    if (*(char *)(param_2 + 2) == '(') {
      uVar4 = *(uint *)(param_2 + 0x3c);
    }
    else {
      uVar4 = *(uint *)(param_2 + 0x10);
    }
    if ((7 < uVar4) && ((param_4 != 0x10 || (0xb < uVar4)))) {
      if ((param_1[4] & 1) == 0) {
        uVar6 = AtaReadCapacityCompletion(param_1,param_2);
        uVar6 = uVar6 & 0xffffffff;
      }
      else {
        *(uint *)(uVar5 + 0x1104) = *(uint *)(uVar5 + 0x1104) | 2;
        *(undefined2 *)(uVar5 + 0x1100) = 0x101;
        *(ulonglong *)(uVar5 + 0x1120) = param_1[0x18];
        *(code **)(uVar5 + 0x2968) = AtaReadCapacityRequestCompletion;
        *(undefined4 *)(uVar5 + 0x1130) = 0x200;
        *(undefined4 *)(uVar5 + 0x1140) = 1;
        *(int *)(uVar5 + 0x1150) = (int)param_1[0x19];
        *(undefined4 *)(uVar5 + 0x1154) = *(undefined4 *)((longlong)param_1 + 0xcc);
        *(undefined4 *)(uVar5 + 0x1158) = 0x200;
        *(undefined4 **)(uVar5 + 0x1138) = (undefined4 *)(uVar5 + 0x1140);
        *(undefined1 *)(uVar5 + 0x110e) = 0xec;
      }
      return uVar6;
    }
    uVar6 = 0xc1000004;
    goto switchD_140005d48_caseD_1;
  }
  if (0xb5 < bVar2) goto switchD_140005d48_caseD_1;
  switch(bVar2) {
  case 0:
    uVar6 = GetSrbExtension(param_2);
    uVar5 = IsMsnEnabled((longlong)(param_1 + 1));
    if ((char)uVar5 == '\0') {
      *(undefined1 *)(param_2 + 3) = 1;
    }
    else {
      *(undefined2 *)(uVar6 + 0x1100) = 0x100;
      *(undefined1 *)(uVar6 + 0x110e) = 0xda;
    }
    uVar6 = 0;
    break;
  default:
    goto switchD_140005d48_caseD_1;
  case 0x12:
    uVar6 = AtaInquiryRequest(param_1,param_2,(longlong)param_3);
    return uVar6;
  case 0x15:
  case 0x55:
    uVar6 = AtaModeSelectRequest((longlong)param_1,param_2,(longlong)param_3);
    uVar6 = uVar6 & 0xffffffff;
    break;
  case 0x1a:
  case 0x5a:
    uVar6 = AtaModeSenseRequest((longlong)param_1,param_2,(char *)param_3);
    return uVar6;
  case 0x1b:
    uVar6 = AtaStartStopUnitRequest((longlong)param_1,param_2,(longlong)param_3);
    uVar6 = uVar6 & 0xffffffff;
    break;
  case 0x1e:
    uVar6 = AtaMediumRemovalRequest((longlong)param_1,param_2,(longlong)param_3);
    uVar6 = uVar6 & 0xffffffff;
    break;
  case 0x28:
  case 0x2a:
  case 0x88:
    goto switchD_140005d48_caseD_28;
  case 0x2f:
  case 0x8f:
    uVar6 = AtaVerifyRequest((longlong)param_1,param_2,(longlong)param_3,param_4);
    uVar6 = uVar6 & 0xffffffff;
    break;
  case 0x35:
    uVar6 = AtaFlushCommandRequest((longlong)param_1,param_2);
    return uVar6;
  case 0x3b:
    uVar6 = AtaWriteBufferRequest(param_1,param_2,param_3);
    uVar6 = uVar6 & 0xffffffff;
    break;
  case 0x42:
    AtaUnmapRequest(param_1,param_2);
    return extraout_RAX;
  case 0x48:
    uVar6 = AtaSanitizeRequest(param_1,param_2,param_3);
    uVar6 = uVar6 & 0xffffffff;
    break;
  case 0x85:
    uVar6 = AtaPassThroughRequest((longlong)param_1,param_2,(longlong)param_3);
    return uVar6;
  case 0x94:
    bVar2 = param_3[1] & 0x1f;
    if (bVar2 == 1) {
      uVar6 = AtaCloseZoneRequest((longlong)param_1,param_2,param_3);
      return uVar6 & 0xffffffff;
    }
    if (bVar2 == 2) {
      uVar6 = AtaFinishZoneRequest((longlong)param_1,param_2,param_3);
      return uVar6 & 0xffffffff;
    }
    if (bVar2 == 3) {
      uVar6 = AtaOpenZoneRequest((longlong)param_1,param_2,param_3);
      return uVar6 & 0xffffffff;
    }
    if (bVar2 == 4) {
      uVar6 = AtaResetWritePointerRequest((longlong)param_1,param_2,param_3);
      return uVar6 & 0xffffffff;
    }
    goto switchD_140005d48_caseD_1;
  case 0x95:
    if ((param_3[1] & 0x1f) == 0) {
      uVar6 = AtaReportZonesRequest((longlong)param_1,param_2,param_3);
      return uVar6 & 0xffffffff;
    }
    goto switchD_140005d48_caseD_1;
  case 0x9b:
    if ((param_3[1] & 0x1f) == 0x1c) {
      bVar2 = param_3[0xe];
      if (bVar2 == 0) {
        uVar6 = AtaGetDeviceCurrentInternalStatusDataHeader((longlong)param_1,param_2);
        return uVar6 & 0xffffffff;
      }
      if ((byte)(bVar2 - 0x10) < 0xe0) {
        if (bVar2 == *(byte *)((longlong)param_1 + 0x463c)) {
          uVar6 = AtaGetDeviceInternalStatusData
                            ((longlong *)param_1,param_2,(longlong)param_3,'\x01');
          return uVar6 & 0xffffffff;
        }
        if (bVar2 == *(byte *)((longlong)param_1 + 0x463d)) {
          uVar6 = AtaGetDeviceInternalStatusData((longlong *)param_1,param_2,(longlong)param_3,'\0')
          ;
          return uVar6 & 0xffffffff;
        }
      }
    }
    goto switchD_140005d48_caseD_1;
  case 0x9e:
    bVar1 = param_3[1] & 0x1f;
    if (bVar1 == 0x10) {
      uVar6 = AtaReadCapacityRequest(param_1,param_2,(char *)param_3,param_4);
      return uVar6 & 0xffffffff;
    }
    if (bVar1 == 0x17) {
      uVar4 = AtaGetPhysicalElementStatusRequest((longlong *)param_1,param_2,(longlong)param_3);
      return (ulonglong)uVar4;
    }
    if (bVar1 == 0x18) {
      uVar6 = AtaRemoveElementAndTruncateRequest
                        (IMAGE_DOS_HEADER_140000000.e_magic +
                         (&switchD_140005d48::switchdataD_14002ba38)
                         [(&switchD_140005d48::switchdataD_14002ba88)[bVar2]],param_2,param_3);
      return uVar6 & 0xffffffff;
    }
switchD_140005d48_caseD_1:
    *(undefined1 *)(param_2 + 3) = 6;
    break;
  case 0xa0:
    uVar6 = AtaReportLunsCommand((longlong)param_1,param_2);
    uVar6 = uVar6 & 0xffffffff;
    break;
  case 0xa2:
  case 0xb5:
    uVar6 = AtaSecurityProtocolRequest((longlong)param_1,param_2,(char *)param_3);
    uVar6 = uVar6 & 0xffffffff;
  }
  return uVar6;
}



===== RetryCommand @ 140006020 =====

ulonglong RetryCommand(ulonglong *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = param_1[0x4a];
  if ((((uVar3 >> 0x16 & 1) == 0) && (uVar3 = *param_1, *(char *)(uVar3 + 0x18d) == '\0')) &&
     (uVar3 = param_1[0x4a], (uVar3 >> 0x19 & 1) == 0)) {
    if ((param_1[0x4a] & 8) == 0) {
      uVar3 = 0;
      if (((char)param_1[0x49] == '\x16') || ((char)param_1[0x49] == -1)) goto LAB_14000608f;
    }
    bVar1 = *param_2;
    uVar2 = bVar1 + 0x62;
    uVar3 = (ulonglong)uVar2;
    if (((0x17 < (byte)uVar2) || ((0x800015U >> (uVar2 & 0x1f) & 1) == 0)) &&
       ((0x35 < bVar1 ||
        (uVar3 = 0x20002008040000, (0x20002008040000U >> ((ulonglong)bVar1 & 0x3f) & 1) == 0)))) {
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
  }
LAB_14000608f:
  return uVar3 & 0xffffffffffffff00;
}



===== BuildReadWriteCommand @ 1400060a0 =====

void BuildReadWriteCommand(longlong *param_1,longlong param_2,char *param_3,int param_4)

{
  ushort uVar1;
  undefined1 uVar2;
  char cVar3;
  bool bVar4;
  byte bVar5;
  char cVar6;
  short sVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined1 uVar14;
  longlong lVar15;
  uint uVar16;
  
  bVar4 = false;
  if (*(char *)(param_2 + 2) == '(') {
    uVar13 = *(ulonglong *)(param_2 + 0x68);
  }
  else {
    uVar13 = *(ulonglong *)(param_2 + 0x38);
  }
  if ((uVar13 & 0x7f) != 0) {
    uVar13 = (uVar13 - ((uint)uVar13 & 0x7f)) + 0x80;
  }
  if (*(char *)(param_2 + 2) == '(') {
    iVar8 = *(int *)(param_2 + 0x3c);
  }
  else {
    iVar8 = *(int *)(param_2 + 0x10);
  }
  uVar11 = (ulonglong)(iVar8 + -1 + *(uint *)((longlong)param_1 + 0x24)) /
           (ulonglong)*(uint *)((longlong)param_1 + 0x24);
  uVar2 = (undefined1)uVar11;
  uVar9 = GetLbaFromCdb((longlong)param_3,param_4);
  uVar16 = 0x400;
  *(undefined2 *)(uVar13 + 0x1100) = 0x400;
  if (*(char *)(param_2 + 2) == '(') {
    uVar12 = *(ulonglong *)(param_2 + 0x68);
  }
  else {
    uVar12 = *(ulonglong *)(param_2 + 0x38);
  }
  if ((uVar12 & 0x7f) != 0) {
    uVar12 = (uVar12 - ((uint)uVar12 & 0x7f)) + 0x80;
  }
  if ((*param_3 == '(') || (*param_3 == -0x78)) {
    if ((param_1[0x4a] & 0x10U) == 0) {
      cVar6 = -0x38;
      if ((*(byte *)(uVar12 + 0x1104) & 8) != 0) {
        cVar6 = '%';
      }
    }
    else {
      cVar6 = '`';
    }
  }
  else if ((param_1[0x4a] & 0x10U) == 0) {
    if ((*(uint *)(uVar12 + 0x1104) & 8) == 0) {
      cVar6 = -0x36;
    }
    else if (((((param_3[1] & 8U) == 0) || ((*(uint *)(param_1 + 0x4b) & 0x10) != 0)) ||
             ((*(uint *)(param_1 + 0x4b) & 1) == 0)) || ((*(uint *)(param_1 + 4) >> 2 & 1) == 0)) {
      cVar6 = '5';
    }
    else {
      cVar6 = '=';
    }
  }
  else {
    cVar6 = 'a';
  }
  *(char *)(uVar13 + 0x110a) = cVar6;
  *(char *)(uVar13 + 0x110d) = (char)(uVar9 >> 8);
  cVar3 = (char)(uVar9 >> 0x10);
  *(char *)(uVar13 + 0x110e) = cVar3;
  *(char *)(uVar13 + 0x110c) = (char)uVar9;
  uVar1 = *(ushort *)(uVar13 + 0x1100);
  bVar5 = (byte)(uVar9 >> 0x18);
  if (uVar1 == 0x400) {
LAB_1400061ee:
    if ((1 < (byte)(cVar6 + 0xa0U)) && (2 < (byte)(cVar6 + 0x9dU))) goto LAB_14000622f;
LAB_140006202:
    *(char *)(uVar13 + 0x1111) = (char)(uVar9 >> 0x20);
    *(char *)(uVar13 + 0x1112) = (char)(uVar9 >> 0x28);
    *(byte *)(uVar13 + 0x1110) = bVar5;
  }
  else {
    if ((uVar1 >> 8 & 1) != 0) {
      cVar6 = cVar3;
      goto LAB_1400061ee;
    }
LAB_14000622f:
    if ((int)param_1[6] == 2) goto LAB_140006202;
    *(byte *)(uVar13 + 0x110f) = bVar5 & 0xf;
  }
  uVar14 = (undefined1)(uVar11 >> 8);
  if (uVar1 == 0x400) {
    bVar5 = *(byte *)(uVar13 + 0x110a);
LAB_140006255:
    if (((bVar5 == 0x62) || (bVar5 < 0x60)) || (0x65 < bVar5)) goto LAB_1400062bb;
    bVar5 = *(byte *)(uVar13 + 0x110f);
    *(undefined1 *)(uVar13 + 0x110b) = uVar2;
    *(byte *)(uVar13 + 0x110f) = bVar5 | 0x40;
    *(undefined1 *)(uVar13 + 0x1113) = uVar14;
    if (((((param_3[1] & 8U) == 0) || ((*(uint *)(param_1 + 0x4b) & 0x10) != 0)) ||
        ((*(uint *)(param_1 + 0x4b) & 1) == 0)) || ((*(uint *)(param_1 + 4) >> 2 & 1) == 0)) {
      *(byte *)(uVar13 + 0x110f) = bVar5 & 0x7f | 0x40;
    }
    else {
      *(byte *)(uVar13 + 0x110f) = bVar5 | 0xc0;
    }
  }
  else {
    if ((uVar1 >> 8 & 1) != 0) {
      bVar5 = *(byte *)(uVar13 + 0x110e);
      goto LAB_140006255;
    }
LAB_1400062bb:
    *(undefined1 *)(uVar13 + 0x1114) = uVar2;
    if ((int)param_1[6] == 2) {
      *(undefined1 *)(uVar13 + 0x1115) = uVar14;
    }
    *(byte *)(uVar13 + 0x110f) = *(byte *)(uVar13 + 0x110f) | 0xe0;
  }
  if (((*(char *)(*param_1 + 0x18c) == '\0') && (-1 < (char)param_1[0x4b])) &&
     ((((int)param_1[3] == 1 || ((int)param_1[3] - 3U < 3)) &&
      (((*(ushort *)(param_1[0x18] + 0x9c) >> 9 & 1) != 0 &&
       ((*(ushort *)(param_1[0x18] + 0x9e) >> 9 & 1) != 0)))))) {
    if (uVar1 == 0x400) {
      cVar6 = *(char *)(uVar13 + 0x110a);
    }
    else {
      if ((uVar1 >> 8 & 1) == 0) goto LAB_14000633f;
      cVar6 = *(char *)(uVar13 + 0x110e);
    }
    if (1 < (byte)(cVar6 + 0xa0U)) goto LAB_14000633f;
  }
  else {
LAB_14000633f:
    if (-1 < (char)param_1[0x4a]) goto LAB_140006427;
    if (*(ushort *)(uVar13 + 0x1100) == 0x400) {
      cVar6 = *(char *)(uVar13 + 0x110a);
    }
    else {
      if ((*(ushort *)(uVar13 + 0x1100) >> 8 & 1) == 0) goto LAB_140006427;
      cVar6 = *(char *)(uVar13 + 0x110e);
    }
    if (cVar6 != 'a') goto LAB_140006427;
  }
  if ((*(char *)(param_2 + 2) == '(') && (*(uint *)(param_2 + 0x38) != 0)) {
    uVar11 = 0;
    do {
      uVar10 = *(uint *)(param_2 + 0x78 + uVar11 * 4);
      if (((0x7f < uVar10) && (uVar10 < *(uint *)(param_2 + 0x10))) &&
         (lVar15 = param_2 + (ulonglong)uVar10, *(int *)(param_2 + (ulonglong)uVar10) == 0x80)) {
        if ((*(int *)(lVar15 + 8) < 0) &&
           (*(byte *)(lVar15 + 0x15) <= (*(byte *)((longlong)param_1 + 0x187) & 0xf))) {
          *(byte *)(uVar13 + 0x111a) = *(byte *)(lVar15 + 0x15) & 0xf | 0x20;
          uVar16 = 0x400;
          if (((*(char *)(*param_1 + 0x18c) == '\0') &&
              ((uVar16 = 0x400, sVar7 = IsNCQWriteCommand(uVar13), (char)sVar7 != '\0' &&
               ((*(uint *)(lVar15 + 8) & 0x20) != 0)))) && ((*(uint *)(param_1 + 0x2e) & 8) != 0)) {
            *(code **)(uVar13 + 0x2968) = HybridWriteThroughCompletion;
          }
          bVar4 = true;
        }
        break;
      }
      uVar10 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar10;
    } while (uVar10 < *(uint *)(param_2 + 0x38));
  }
LAB_140006427:
  if ((((*(uint *)(*param_1 + 0x38) & uVar16) != 0) && (!bVar4)) && ((char)param_1[0x4a] < '\0')) {
    if (*(ushort *)(uVar13 + 0x1100) == (ushort)uVar16) {
      cVar6 = *(char *)(uVar13 + 0x110a);
    }
    else {
      if ((*(ushort *)(uVar13 + 0x1100) >> 8 & 1) == 0) {
        return;
      }
      cVar6 = *(char *)(uVar13 + 0x110e);
    }
    if ((cVar6 == 'a') && ((*(byte *)((longlong)param_1 + 0x187) & 0xf) != 0)) {
      *(undefined1 *)(uVar13 + 0x111a) = 0x21;
    }
  }
  return;
}



===== AtaReadCapacityCompletion @ 1400064a0 =====

undefined8 AtaReadCapacityCompletion(ulonglong *param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar6;
  undefined1 uVar5;
  undefined1 uVar7;
  ushort uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined1 uVar11;
  uint *puVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined4 *puVar15;
  byte bVar16;
  byte bVar17;
  char cVar18;
  undefined4 uVar19;
  byte *pbVar20;
  undefined4 *puVar21;
  undefined8 uVar22;
  uint local_res8;
  
  uVar22 = 0;
  if (*(char *)(param_2 + 2) == '(') {
    puVar15 = *(undefined4 **)(param_2 + 0x40);
    uVar10 = *(uint *)(param_2 + 0x3c);
    cVar18 = '\0';
    if (*(int *)(param_2 + 0x14) == 0) {
      local_res8 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        puVar12 = (uint *)(param_2 + 0x78);
        do {
          uVar1 = *puVar12;
          if ((0x7f < uVar1) && (uVar2 = *(uint *)(param_2 + 0x10), uVar1 < uVar2)) {
            iVar3 = *(int *)((ulonglong)uVar1 + param_2);
            uVar9 = (ulonglong)uVar1;
            if (iVar3 == 0x40) {
              uVar9 = uVar9 + 0x28;
            }
            else {
              if (iVar3 != 0x41) {
                if ((iVar3 != 0x42) || ((ulonglong)uVar2 < uVar9 + 0x28)) goto LAB_1400065e0;
                break;
              }
              uVar9 = uVar9 + 0x38;
            }
            if (uVar9 <= uVar2) {
              cVar18 = *(char *)((ulonglong)uVar1 + param_2 + 10);
              break;
            }
          }
LAB_1400065e0:
          puVar12 = puVar12 + 1;
          local_res8 = local_res8 + 1;
        } while (local_res8 < *(uint *)(param_2 + 0x38));
      }
    }
  }
  else {
    puVar15 = *(undefined4 **)(param_2 + 0x18);
    uVar10 = *(uint *)(param_2 + 0x10);
    cVar18 = *(char *)(param_2 + 10);
  }
  puVar21 = (undefined4 *)(param_2 + 0x10);
  uVar4 = *(undefined4 *)((longlong)param_1 + 0x24);
  uVar9 = param_1[7] - 1;
  if (puVar15 == (undefined4 *)0x0) {
    uVar22 = 0xc1000003;
    uVar7 = 0x30;
  }
  else {
    uVar11 = (undefined1)((uint)uVar4 >> 8);
    uVar13 = (undefined1)((uint)uVar4 >> 0x10);
    uVar14 = (undefined1)((uint)uVar4 >> 0x18);
    uVar7 = (undefined1)(uVar9 >> 0x18);
    uVar5 = (undefined1)(uVar9 >> 8);
    uVar6 = (undefined1)(uVar9 >> 0x10);
    if (cVar18 == '\x10') {
      uVar19 = 0xc;
      if (uVar10 < 0xc) goto LAB_140006655;
      *(char *)((longlong)puVar15 + 7) = (char)uVar9;
      *(undefined1 *)((longlong)puVar15 + 6) = uVar5;
      *(undefined1 *)((longlong)puVar15 + 5) = uVar6;
      *(undefined1 *)(puVar15 + 1) = uVar7;
      *(char *)((longlong)puVar15 + 3) = (char)(uVar9 >> 0x20);
      *(char *)((longlong)puVar15 + 2) = (char)(uVar9 >> 0x28);
      *(char *)((longlong)puVar15 + 1) = (char)(uVar9 >> 0x30);
      *(char *)puVar15 = (char)(uVar9 >> 0x38);
      *(char *)((longlong)puVar15 + 0xb) = (char)uVar4;
      *(undefined1 *)((longlong)puVar15 + 10) = uVar11;
      *(undefined1 *)((longlong)puVar15 + 9) = uVar13;
      *(undefined1 *)(puVar15 + 2) = uVar14;
      if (0xf < (int)uVar10) {
        pbVar20 = (byte *)((longlong)puVar15 + 0xe);
        bVar17 = *pbVar20;
        *(byte *)(puVar15 + 3) = *(byte *)(puVar15 + 3) & 0xf0;
        bVar16 = (*(byte *)((longlong)puVar15 + 0xd) ^ *(byte *)(param_1[0x18] + 0xd4)) & 0xf ^
                 *(byte *)((longlong)puVar15 + 0xd);
        *(byte *)((longlong)puVar15 + 0xd) = bVar16;
        if ((*(ushort *)(param_1[0x18] + 0x1a2) >> 0xe & 1) == 0) {
          bVar17 = bVar17 & 0xc0;
          uVar9 = 0;
        }
        else {
          uVar8 = 1 << (bVar16 & 0xf);
          uVar9 = (longlong)(int)((uint)uVar8 - (*(ushort *)(param_1[0x18] + 0x1a2) & 0x3fff)) %
                  (longlong)(int)(uint)uVar8 & 0xffffffff;
          bVar17 = ((byte)(uVar9 >> 8) ^ bVar17) & 0x3f ^ bVar17;
        }
        *pbVar20 = bVar17;
        *(char *)((longlong)puVar15 + 0xf) = (char)uVar9;
        uVar9 = IsDeviceSupportsTrim(param_1);
        if ((char)uVar9 == '\0') {
          *pbVar20 = bVar17 & 0x7f;
          bVar17 = bVar17 & 0x3f;
        }
        else {
          bVar16 = (byte)(*(ushort *)(param_1[0x18] + 0x8a) >> 7);
          bVar16 = (bVar17 ^ bVar16) & 0x7f ^ bVar16;
          *pbVar20 = bVar16;
          bVar17 = 0;
          if ((*(ushort *)(param_1[0x18] + 0x8a) & 0x4020) == 0x4020) {
            bVar17 = 0x40;
          }
          bVar17 = bVar17 | bVar16 & 0xbf;
        }
        *pbVar20 = bVar17;
        uVar19 = 0x10;
        if (0x1f < uVar10) {
          uVar19 = 0x20;
        }
      }
      if (*(char *)(param_2 + 2) == '(') {
        *(undefined4 *)(param_2 + 0x3c) = uVar19;
      }
      else {
        *puVar21 = uVar19;
      }
    }
    else {
      if (uVar10 < 8) {
LAB_140006655:
        *(undefined1 *)(param_2 + 3) = 6;
        return 0xc1000004;
      }
      *(char *)((longlong)puVar15 + 7) = (char)uVar4;
      *(undefined1 *)((longlong)puVar15 + 6) = uVar11;
      *(undefined1 *)((longlong)puVar15 + 5) = uVar13;
      *(undefined1 *)(puVar15 + 1) = uVar14;
      if (uVar9 < 0xffffffff) {
        *(char *)((longlong)puVar15 + 3) = (char)uVar9;
        *(undefined1 *)((longlong)puVar15 + 2) = uVar5;
        *(undefined1 *)puVar15 = uVar7;
        *(undefined1 *)((longlong)puVar15 + 1) = uVar6;
      }
      else {
        *puVar15 = 0xffffffff;
      }
      if (*(char *)(param_2 + 2) == '(') {
        *(undefined4 *)(param_2 + 0x3c) = 8;
      }
      else {
        *puVar21 = 8;
      }
    }
    uVar7 = 1;
  }
  *(undefined1 *)(param_2 + 3) = uVar7;
  return uVar22;
}



===== AhciCompleteRequest @ 140006670 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AhciCompleteRequest(longlong *param_1,longlong *param_2,char param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  int iVar6;
  undefined4 local_res10 [2];
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  if (*(char *)((longlong)param_2 + 2) == '(') {
    uVar1 = param_2[0xd];
  }
  else {
    uVar1 = param_2[7];
  }
  if ((uVar1 & 0x7f) != 0) {
    uVar1 = (uVar1 - ((uint)uVar1 & 0x7f)) + 0x80;
  }
  if (((*(uint *)(uVar1 + 0x1104) & 0x400) == 0) && (*(longlong *)(uVar1 + 0x2968) == 0)) {
    if ((param_2 == param_1 + 0x12e) || (param_2 == param_1 + 0x13b)) {
      RecordExecutionHistory(param_1,0x20000045);
      return;
    }
    StorPortNotification(0,*param_1,param_2);
    if ((*(uint *)(*param_1 + 0x34) & 1) != 0) {
      RecordExecutionHistory(param_1,0x10000045);
    }
  }
  else {
    if (param_3 == '\0') {
      local_28 = 3;
      local_20 = 0;
      local_18 = 0;
      uStack_10 = 0;
      AhciInterruptSpinlockAcquire(*param_1,(int)param_1[0x48],(longlong)&local_28);
      AddQueue((longlong)param_1,param_1 + 0xdf,(longlong)param_2);
      lVar2 = *param_1;
      if (((char)*(undefined4 *)(lVar2 + 0x2c) < '\0') && ((int)param_1[0x48] != -1)) {
        StorPortExtendedFunction(0xc,lVar2,(int)param_1[0x48],uStack_10 & 0xff);
      }
      else {
        StorPortNotification(0x1004,lVar2,&local_28);
      }
    }
    else {
      StorPortQuerySystemTime(param_1 + 0x115);
      lVar2 = param_1[0xe0];
      if (lVar2 == 0) {
        param_1[0xe0] = (longlong)param_2;
        param_1[0xdf] = (longlong)param_2;
      }
      else {
        if (*(char *)(lVar2 + 2) == '(') {
          lVar4 = *(longlong *)(lVar2 + 0x70);
        }
        else {
          lVar4 = *(longlong *)(lVar2 + 0x28);
        }
        if (lVar4 == 0) {
          plVar5 = param_1;
          if (*(char *)(lVar2 + 2) == '(') {
            *(longlong **)(lVar2 + 0x70) = param_2;
          }
          else {
            *(longlong **)(lVar2 + 0x28) = param_2;
          }
        }
        else {
          plVar5 = (longlong *)0x0;
          _DAT_00000240 = _DAT_00000240 + 1;
        }
        param_1[0xe0] = (longlong)param_2;
        if (*(char *)((longlong)param_2 + 2) == '(') {
          lVar2 = param_2[0xe];
        }
        else {
          lVar2 = param_2[5];
        }
        if (lVar2 != 0) {
          if (param_2 == plVar5 + 0x12e) {
            _DAT_00000244 = _DAT_00000244 + 1;
          }
          else if (param_2 == plVar5 + 0x13b) {
            DAT_00000274 = DAT_00000274 + '\x01';
          }
          else {
            DAT_00000275 = DAT_00000275 + '\x01';
          }
        }
      }
      *(int *)(param_1 + 0xe1) = (int)param_1[0xe1] + 1;
      lVar2 = param_1[0xdf];
      if (lVar2 == 0) {
        iVar6 = 0;
        _DAT_00000240 = _DAT_00000240 + 1;
      }
      else {
        iVar6 = 1;
        if (*(char *)(lVar2 + 2) == '(') {
          lVar2 = *(longlong *)(lVar2 + 0x70);
        }
        else {
          lVar2 = *(longlong *)(lVar2 + 0x28);
        }
        while (lVar2 != 0) {
          iVar6 = iVar6 + 1;
          if (*(char *)(lVar2 + 2) == '(') {
            lVar2 = *(longlong *)(lVar2 + 0x70);
          }
          else {
            lVar2 = *(longlong *)(lVar2 + 0x28);
          }
        }
      }
      *(uint *)((longlong)param_1 + (ulonglong)*(uint *)(param_1 + 0xe2) * 4 + 0x714) =
           *(uint *)(param_1 + 0xe1) | 0x90000000;
      uVar3 = ((int)param_1[0xe2] + 1U) % 100;
      *(uint *)(param_1 + 0xe2) = uVar3;
      *(undefined4 *)((longlong)param_1 + (ulonglong)uVar3 * 4 + 0x714) = 0xdeadbeef;
      if ((int)param_1[0xe1] != iVar6) {
        _DAT_00000240 = _DAT_00000240 + 1;
      }
      if (*(uint *)((longlong)param_1 + 0x70c) < *(uint *)(param_1 + 0xe1)) {
        *(uint *)((longlong)param_1 + 0x70c) = *(uint *)(param_1 + 0xe1);
      }
    }
    if ((*(uint *)(*param_1 + 0x34) & 1) != 0) {
      RecordExecutionHistory(param_1,0x30000045);
    }
    lVar2 = *param_1;
    if (*(char *)(lVar2 + 0x18c) == '\0') {
      local_res10[0] = 0;
      StorPortNotification(0x1002,lVar2,param_1 + 0x117,param_1,param_2,local_res10);
    }
    else {
      AhciPortSrbCompletionDpcRoutine(param_1 + 0x117,lVar2,param_1);
    }
  }
  return;
}



===== RecordExecutionHistory @ 140006990 =====

void RecordExecutionHistory(longlong *param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  bool bVar8;
  
  if (param_1[0x8b9] != 0) {
    do {
      uVar2 = *(uint *)((longlong)param_1 + 0x45c4);
      uVar6 = 0;
      if (uVar2 < 199) {
        uVar6 = (ulonglong)(uVar2 + 1);
      }
      LOCK();
      bVar8 = uVar2 == *(uint *)((longlong)param_1 + 0x45c4);
      if (bVar8) {
        *(uint *)((longlong)param_1 + 0x45c4) = (uint)uVar6;
      }
      UNLOCK();
    } while (!bVar8);
    lVar7 = uVar6 * 0x78;
    StorPortQuerySystemTime(param_1[0x8b9] + 0x70 + lVar7);
    *(undefined4 *)(lVar7 + param_1[0x8b9]) = param_2;
    if (*(longlong *)(*param_1 + 0x1a0) == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = (undefined4)param_1[0x4a];
    }
    *(undefined4 *)(param_1[0x8b9] + 4 + lVar7) = uVar5;
    uVar4 = *(undefined8 *)((longlong)param_1 + 0x2d4);
    lVar3 = param_1[0x8b9];
    puVar1 = (undefined8 *)(lVar7 + 8 + lVar3);
    *puVar1 = *(undefined8 *)((longlong)param_1 + 0x2cc);
    puVar1[1] = uVar4;
    uVar4 = *(undefined8 *)((longlong)param_1 + 0x2e4);
    puVar1 = (undefined8 *)(lVar7 + 0x18 + lVar3);
    *puVar1 = *(undefined8 *)((longlong)param_1 + 0x2dc);
    puVar1[1] = uVar4;
    *(undefined8 *)(lVar7 + 0x28 + lVar3) = *(undefined8 *)((longlong)param_1 + 0x2ec);
    if ((undefined4 *)param_1[0x129] == (undefined4 *)0x0) {
      *(undefined4 *)(param_1[0x8b9] + 0x30 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x34 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x38 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x3c + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x40 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x44 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x48 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x4c + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x50 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x54 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x58 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x5c + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x60 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 100 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x68 + uVar6 * 0x78) = 0xffffffff;
      *(undefined4 *)(param_1[0x8b9] + 0x6c + uVar6 * 0x78) = 0xffffffff;
    }
    else {
      *(undefined4 *)(lVar7 + 0x30 + param_1[0x8b9]) = *(undefined4 *)param_1[0x129];
      *(undefined4 *)(lVar7 + 0x34 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 4);
      *(undefined4 *)(lVar7 + 0x38 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 8);
      *(undefined4 *)(lVar7 + 0x3c + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0xc);
      *(undefined4 *)(lVar7 + 0x40 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x10);
      *(undefined4 *)(lVar7 + 0x44 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x14);
      *(undefined4 *)(lVar7 + 0x48 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x18);
      *(undefined4 *)(lVar7 + 0x4c + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x1c);
      *(undefined4 *)(lVar7 + 0x50 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x20);
      *(undefined4 *)(lVar7 + 0x54 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x24);
      *(undefined4 *)(lVar7 + 0x58 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x28);
      *(undefined4 *)(lVar7 + 0x5c + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x2c);
      *(undefined4 *)(lVar7 + 0x60 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x30);
      *(undefined4 *)(lVar7 + 100 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x34);
      *(undefined4 *)(lVar7 + 0x68 + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x38);
      *(undefined4 *)(lVar7 + 0x6c + param_1[0x8b9]) = *(undefined4 *)(param_1[0x129] + 0x3c);
    }
  }
  return;
}



===== AtaFlushCommandRequest @ 140006ce0 =====

undefined8 AtaFlushCommandRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar3 = *(ulonglong *)(param_2 + 0x68);
  }
  else {
    uVar3 = *(ulonglong *)(param_2 + 0x38);
  }
  if ((uVar3 & 0x7f) != 0) {
    uVar3 = (uVar3 - ((uint)uVar3 & 0x7f)) + 0x80;
  }
  if ((((*(int *)(param_1 + 0x18) == 1) || (*(int *)(param_1 + 0x18) - 3U < 3)) &&
      ((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0xa4) & 0x20) == 0)) &&
     ((*(ushort *)(*(longlong *)(param_1 + 0xc0) + 0xa6) & 0x3000) == 0)) {
    *(undefined1 *)(param_2 + 3) = 1;
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x30);
  *(undefined2 *)(uVar3 + 0x1100) = 0x104;
  uVar2 = 0xea;
  if (iVar1 != 2) {
    uVar2 = 0xe7;
  }
  *(code **)(uVar3 + 0x2968) = AtaAlwaysSuccessRequestCompletion;
  if ((*(uint *)(param_1 + 0x20) & 2) != 0) {
    *(ulonglong *)(param_1 + 0x250) = *(ulonglong *)(param_1 + 0x250) | 2;
  }
  *(undefined1 *)(uVar3 + 0x110e) = uVar2;
  return 0;
}



===== IsFuaSupported @ 140006d90 =====

uint IsFuaSupported(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 600);
  if (((uVar1 & 0x10) == 0) && ((uVar1 & 1) != 0)) {
    return CONCAT31((uint3)(*(uint *)(param_1 + 0x20) >> 10),(char)(*(uint *)(param_1 + 0x20) >> 2))
           & 0xffffff01;
  }
  return uVar1 & 0xffffff00;
}



===== P_Running_Callback @ 140006dc0 =====

void P_Running_Callback(longlong param_1,ulonglong *param_2)

{
  byte bVar1;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  if (param_2 != (ulonglong *)0x0) {
    if ((uint)*(ushort *)((longlong)param_2 + 0x24e) + (uint)*(byte *)((longlong)param_2 + 0x24c) +
        (uint)*(byte *)((longlong)param_2 + 0x24b) + (uint)*(byte *)((longlong)param_2 + 0x24a) +
        (uint)*(byte *)((longlong)param_2 + 0x249) == 1) {
      local_28 = 3;
      local_18 = 0;
      uStack_10 = 0;
      local_20 = 0;
      AhciInterruptSpinlockAcquire(param_1,(int)param_2[0x48],(longlong)&local_28);
      bVar1 = *(byte *)((longlong)param_2 + 0x24d);
      if ((bVar1 & 1) != 0) {
        bVar1 = bVar1 & 0xfe;
        *(byte *)((longlong)param_2 + 0x24d) = bVar1;
      }
      if ((bVar1 & 2) != 0) {
        *(byte *)((longlong)param_2 + 0x24d) = bVar1 & 0xfd;
      }
      if (((char)*(undefined4 *)(param_1 + 0x2c) < '\0') && ((int)param_2[0x48] != -1)) {
        StorPortExtendedFunction(0xc,param_1,(int)param_2[0x48],uStack_10 & 0xff);
      }
      else {
        StorPortNotification(0x1004,param_1,&local_28);
      }
    }
    P_Running(param_2,'\x01');
  }
  return;
}



===== P_Running @ 140006ec0 =====

ulonglong P_Running(ulonglong *param_1,char param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  uVar4 = *param_1;
  uVar9 = param_1[0x129];
  if ((*(uint *)(uVar4 + 0x34) & 1) != 0) {
    RecordExecutionHistory((longlong *)param_1,0x15);
  }
  puVar5 = param_1;
  uVar2 = IsPortStartCapable(param_1);
  if ((char)uVar2 == '\0') {
    RecordExecutionHistory((longlong *)puVar5,0x10120015);
    if ((param_2 == '\0') && ((*(byte *)((longlong)param_1 + 0x24d) & 1) != 0)) {
      cVar6 = '\x01';
    }
    else {
      cVar6 = '\0';
    }
    uVar4 = RunNextPort((longlong *)param_1,cVar6);
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  else if ((param_2 == '\0') || ((*(byte *)((longlong)param_1 + 0x24d) & 2) == 0)) {
    uVar8 = *(uint *)(uVar9 + 0x18);
    if ((uVar8 & 0xc011) == 0xc011) {
      *(undefined1 *)(param_1 + 0x49) = 0x16;
      uVar3 = RecordExecutionHistory((longlong *)puVar5,0x30000015);
      if ((param_2 == '\0') && ((*(byte *)((longlong)param_1 + 0x24d) & 1) != 0)) {
        cVar6 = '\x01';
      }
      else {
        cVar6 = '\0';
      }
      uVar4 = *param_1;
      if (*(char *)(uVar4 + 0x18d) != '\0') {
        uVar9 = (ulonglong)(uint)param_1[0x48];
        do {
          uVar8 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar8;
          if (*(uint *)(uVar4 + 0x184) < uVar8) {
            *(undefined1 *)(uVar4 + 0x18d) = 0;
            if (cVar6 == '\0') {
              uVar3 = AhciPortStartTelemetry(uVar4);
            }
            goto LAB_140006f93;
          }
          plVar1 = *(longlong **)(uVar4 + 0x1b0 + uVar9 * 8);
        } while (plVar1 == (longlong *)0x0);
        if ((*(byte *)(plVar1 + 0x49) & 0xdf) == 0) {
          uVar3 = P_Running_StartAttempt(plVar1,cVar6);
        }
      }
    }
    else {
      if ((param_2 == '\0') && (uVar7 = *(uint *)(uVar4 + 0x38) >> 0xc & 0xf, uVar7 != 0)) {
        ForceGenxSpeed((longlong *)puVar5,uVar7);
      }
      *(uint *)(uVar9 + 0x18) = uVar8 | 2;
      LOCK();
      UNLOCK();
      uVar8 = *(uint *)(uVar9 + 0x18);
      if (((uVar8 & 0x4010) == 0x4000) || (((uVar8 >> 0xf & 1) != 0 && ((uVar8 & 1) == 0)))) {
        uVar3 = P_NotRunning((longlong *)param_1,param_1[0x129]);
        if ((char)uVar3 == '\0') {
          RecordExecutionHistory((longlong *)param_1,0x10880015);
          AhciCOMRESET((longlong *)param_1,param_1[0x129]);
          uVar8 = *(uint *)(uVar9 + 0x18);
          if (((uVar8 & 0x4010) == 0x4000) || ((uVar8 & 0x8001) == 0x8000)) {
            AhciPortLogDeviceStartFailure
                      ((longlong *)param_1,L"Device Start Fail:FR CR error",(ulonglong)uVar8,0,0,0);
            P_Running_StartFailed((longlong *)param_1,param_2);
            uVar4 = RecordExecutionHistory((longlong *)param_1,0x10150014);
            return uVar4 & 0xffffffffffffff00;
          }
        }
        *(undefined1 *)(param_1 + 0x49) = 0x11;
      }
      if (((byte)*(uint *)(uVar9 + 0x28) & 0xf) == 4) {
        AhciPortLogDeviceStartFailure
                  ((longlong *)param_1,L"Device Start Fail:DET is 4",(ulonglong)uVar8,
                   (ulonglong)*(uint *)(uVar9 + 0x28),0,0);
        P_Running_StartFailed((longlong *)param_1,param_2);
        uVar4 = RecordExecutionHistory((longlong *)param_1,0x10150015);
        return uVar4 & 0xffffffffffffff00;
      }
      cVar6 = (char)param_1[0x49];
      if (cVar6 == '\x15') {
        P_Running_WaitOnBSYDRQ((longlong *)param_1,param_2);
      }
      else if (cVar6 == '\x11') {
        P_Running_WaitOnDET(param_1,param_2);
      }
      else if (cVar6 == '\x12') {
        P_Running_WaitWhileDET1((longlong *)param_1,param_2);
      }
      else if (cVar6 == '\x13') {
        P_Running_WaitOnDET3((longlong *)param_1,param_2);
      }
      else if (cVar6 == '\x14') {
        P_Running_WaitOnFRE((longlong *)param_1,param_2);
      }
      uVar3 = RecordExecutionHistory((longlong *)param_1,0x10000015);
    }
LAB_140006f93:
    uVar4 = CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  else {
    RecordExecutionHistory((longlong *)puVar5,0x10130015);
    uVar4 = RunNextPort((longlong *)param_1,'\0');
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  return uVar4;
}



===== AhciHwMSIInterrupt @ 140007130 =====

ulonglong AhciHwMSIInterrupt(longlong param_1,ulonglong param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if ((char)*(undefined4 *)(param_1 + 0x2c) < '\0') {
    puVar3 = *(ulonglong **)(param_1 + 0x1b0 + (param_2 & 0xffffffff) * 8);
LAB_140007206:
    uVar2 = AhciInterruptHandler(puVar3);
    uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  else {
    uVar1 = (ulonglong)*(uint *)(param_1 + 0x2c);
    if ((*(uint *)(param_1 + 0x2c) & 0x20) == 0) {
      uVar5 = *(uint *)(param_1 + 0x180) & **(uint **)(param_1 + 0x1a0);
      uVar7 = (ulonglong)uVar5;
      if (uVar5 != 0) {
        uVar4 = (ulonglong)*(uint *)(param_1 + 0x188);
        uVar5 = uVar5 - (uVar5 >> 1 & 0x55555555);
        uVar5 = (uVar5 >> 2 & 0x33333333) + (uVar5 & 0x33333333);
        if (1 < (byte)(((uVar5 >> 4) + uVar5 & 0xf0f0f0f) * 0x1010101 >> 0x18)) {
          uVar4 = (ulonglong)(*(uint *)(param_1 + 0x188) + 1) %
                  (ulonglong)(*(int *)(param_1 + 0x184) + 1);
        }
        do {
          uVar5 = (uint)uVar4;
          if (((uint)uVar7 >> (uVar5 & 0x1f) & 1) != 0) {
            uVar1 = IsPortStartCapable(*(ulonglong **)(param_1 + 0x1b0 + uVar4 * 8));
            uVar5 = (uint)uVar4;
            uVar6 = (uint)uVar7;
            if ((char)uVar1 != '\0') {
              if (uVar5 != *(uint *)(param_1 + 0x188)) {
                uVar4 = uVar4 & 0xffffffff;
                goto LAB_1400071f7;
              }
              break;
            }
          }
          uVar6 = (uint)uVar7;
          uVar4 = (ulonglong)(*(int *)(param_1 + 0x184) + 1);
          uVar1 = (uVar5 + 1) / uVar4;
          uVar4 = (ulonglong)(uVar5 + 1) % uVar4;
        } while ((int)uVar4 != *(int *)(param_1 + 0x188));
        uVar5 = (uint)uVar4;
        if ((uVar6 >> (uVar5 & 0x1f) & 1) != 0) {
          uVar4 = uVar4 & 0xffffffff;
          uVar1 = IsPortStartCapable(*(ulonglong **)(param_1 + 0x1b0 + uVar4 * 8));
          if ((char)uVar1 != '\0') {
LAB_1400071f7:
            *(uint *)(param_1 + 0x188) = uVar5;
            puVar3 = *(ulonglong **)(param_1 + 0x1b0 + uVar4 * 8);
            goto LAB_140007206;
          }
        }
      }
    }
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  return uVar1;
}



===== AhciHwInterrupt @ 140007270 =====

ulonglong AhciHwInterrupt(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar1 = (ulonglong)*(uint *)(param_1 + 0x2c);
  if ((*(uint *)(param_1 + 0x2c) & 0x20) == 0) {
    uVar4 = *(uint *)(param_1 + 0x180) & **(uint **)(param_1 + 0x1a0);
    uVar6 = (ulonglong)uVar4;
    if (uVar4 != 0) {
      uVar3 = (ulonglong)*(uint *)(param_1 + 0x188);
      uVar4 = uVar4 - (uVar4 >> 1 & 0x55555555);
      uVar4 = (uVar4 >> 2 & 0x33333333) + (uVar4 & 0x33333333);
      if (1 < (byte)(((uVar4 >> 4) + uVar4 & 0xf0f0f0f) * 0x1010101 >> 0x18)) {
        uVar3 = (ulonglong)(*(uint *)(param_1 + 0x188) + 1) %
                (ulonglong)(*(int *)(param_1 + 0x184) + 1);
      }
      do {
        uVar4 = (uint)uVar3;
        if (((uint)uVar6 >> (uVar4 & 0x1f) & 1) != 0) {
          uVar1 = IsPortStartCapable(*(ulonglong **)(param_1 + 0x1b0 + uVar3 * 8));
          uVar4 = (uint)uVar3;
          uVar5 = (uint)uVar6;
          if ((char)uVar1 != '\0') {
            if (uVar4 != *(uint *)(param_1 + 0x188)) {
              uVar3 = uVar3 & 0xffffffff;
              goto LAB_140007320;
            }
            break;
          }
        }
        uVar5 = (uint)uVar6;
        uVar3 = (ulonglong)(*(int *)(param_1 + 0x184) + 1);
        uVar1 = (uVar4 + 1) / uVar3;
        uVar3 = (ulonglong)(uVar4 + 1) % uVar3;
      } while ((int)uVar3 != *(int *)(param_1 + 0x188));
      uVar4 = (uint)uVar3;
      if ((uVar5 >> (uVar4 & 0x1f) & 1) != 0) {
        uVar3 = uVar3 & 0xffffffff;
        uVar1 = IsPortStartCapable(*(ulonglong **)(param_1 + 0x1b0 + uVar3 * 8));
        if ((char)uVar1 != '\0') {
LAB_140007320:
          *(uint *)(param_1 + 0x188) = uVar4;
          uVar2 = AhciInterruptHandler(*(ulonglong **)(param_1 + 0x1b0 + uVar3 * 8));
          return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
        }
      }
    }
  }
  return uVar1 & 0xffffffffffffff00;
}



===== IsPortStartCapable @ 140007380 =====

ulonglong IsPortStartCapable(ulonglong *param_1)

{
  ulonglong in_RAX;
  
  if (param_1 != (ulonglong *)0x0) {
    in_RAX = *param_1;
    if ((((*(uint *)(in_RAX + 0x2c) & 1) == 0) && ((*(uint *)(in_RAX + 0x2c) & 2) == 0)) &&
       (in_RAX = param_1[0x4a], (in_RAX & 1) != 0)) {
      return CONCAT71((int7)(in_RAX >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== AhciInterruptHandler @ 1400073b0 =====

void AhciInterruptHandler(ulonglong *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  wchar_t *pwVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  undefined4 local_res8;
  undefined8 local_res10;
  undefined4 local_res18 [2];
  ulonglong uVar17;
  wchar_t *pwVar18;
  wchar_t *pwVar19;
  wchar_t *pwVar20;
  wchar_t *pwVar21;
  
  if ((*(uint *)(*param_1 + 0x34) & 1) != 0) {
    RecordExecutionHistory((longlong *)param_1,5);
  }
  uVar17 = 0;
  iVar16 = 0;
  uVar5 = 0;
  iVar14 = 0;
  uVar1 = *(uint *)(param_1[0x129] + 0x10);
  if ((uVar1 & 0x78400040) != 0) {
    iVar14 = *(int *)(param_1[0x129] + 0x30);
  }
  if (((uVar1 & 0x38000000) == 0) && ((uVar1 >> 0x1e & 1) == 0)) {
LAB_1400076c4:
    if ((int)uVar1 < 0) {
      *(undefined4 *)(param_1[0x129] + 0x10) = 0x80000000;
      LOCK();
      UNLOCK();
      param_1[0x4a] = param_1[0x4a] | 0x400;
    }
    if (((uVar1 & 0x80) == 0) && ((uVar1 & 0x40) == 0)) {
LAB_140007863:
      local_res8._2_2_ = 0;
    }
    else {
      uVar5 = *(uint *)(param_1[0x129] + 0x18);
      if ((uVar5 == 0xffffffff) && (*(int *)(*(longlong *)(*param_1 + 400) + 0x10) == -1)) {
        local_res10 = local_res10 & 0xffffffff00000000;
        bVar4 = AhciIsEventAllowedWithinThrottleLimit
                          (*param_1,(longlong)param_1,0x2f,(int *)&local_res10);
        if (!bVar4) {
          return;
        }
        uVar7 = local_res10 & 0xffffffff;
        uVar5 = 0xffffffff;
        goto LAB_14000758b;
      }
      if ((uVar1 & 0x80) != 0) {
        *(undefined4 *)(param_1[0x129] + 0x10) = 0x80;
        LOCK();
        UNLOCK();
        if ((uVar5 >> 0x13 & 1) != 0) {
          param_1[0x4a] = param_1[0x4a] | 0x400;
        }
      }
      if ((uVar1 & 0x40) == 0) goto LAB_140007863;
      local_res8._2_2_ = 0x400;
      *(undefined4 *)(param_1[0x129] + 0x30) = 0x4000000;
      LOCK();
      UNLOCK();
      if ((((*(uint *)(*param_1 + 0x38) & 4) == 0) && ((param_1[0x4a] >> 0xb & 1) == 0)) &&
         ((uVar5 & 1) == 0)) {
        param_1[0x4a] = param_1[0x4a] | 0x400;
      }
    }
    if ((uVar1 >> 0x16 & 1) != 0) {
      local_res8 = (uint)local_res8._2_2_ << 0x10 | 0x10000;
      *(uint *)(param_1[0x129] + 0x30) = local_res8;
      LOCK();
      UNLOCK();
      uVar13 = *(uint *)(param_1[0x129] + 0x28);
      uVar17 = (ulonglong)uVar13;
      if ((uVar13 == 0xffffffff) && (*(int *)(*(longlong *)(*param_1 + 400) + 0x10) == -1)) {
        return;
      }
      if (((*(uint *)(*param_1 + 0x38) & 4) == 0) && ((param_1[0x4a] >> 0xb & 1) == 0)) {
        if (((*(uint *)(*param_1 + 0x2c) & 0x10) == 0) ||
           (((int)param_1[3] != 2 || ((*(byte *)(param_1[0x18] + 0x9a) & 0x10) == 0)))) {
          if (((uVar13 >> 8 | uVar13) & 0xf) == 0) {
            param_1[0x4a] = param_1[0x4a] | 0x400;
          }
        }
        else if ((uVar13 & 0xf) == 0) {
          uVar8 = P_NotRunning((longlong *)param_1,param_1[0x129]);
          if ((char)uVar8 != '\0') {
            *(uint *)(param_1 + 0x5c) =
                 (uint)param_1[0x5c] |
                 *(uint *)((longlong)param_1 + 0x2dc) | (uint)param_1[0x5b] |
                 *(uint *)((longlong)param_1 + 0x2d4) | (uint)param_1[0x5a];
            param_1[0x5b] = 0;
            *(undefined8 *)((longlong)param_1 + 0x2e4) = 0;
            *(undefined4 *)((longlong)param_1 + 0x2ec) = 0;
            param_1[0x5a] = 0;
            *(undefined4 *)((longlong)param_1 + 0x2cc) = 0;
          }
        }
        else if ((uVar13 & 0xf) == 3) {
          *(byte *)((longlong)param_1 + 0x24d) = *(byte *)((longlong)param_1 + 0x24d) | 3;
          *(undefined4 *)(param_1 + 0x49) = 0x11;
          *(undefined1 *)((longlong)param_1 + 0x24c) = 0;
          *(undefined2 *)((longlong)param_1 + 0x24e) = 0;
          P_Running(param_1,'\0');
        }
      }
    }
    if (iVar14 != 0) {
      *(undefined4 *)(param_1[0x129] + 0x30) = 0xffffffff;
      LOCK();
      UNLOCK();
    }
    if ((uVar1 >> 0x18 & 1) != 0) {
      *(undefined4 *)(param_1[0x129] + 0x10) = 0x1000000;
      LOCK();
      UNLOCK();
      param_1[0x4a] = param_1[0x4a] | 0x100;
    }
    if ((uVar1 >> 0x1a & 1) != 0) {
      *(undefined4 *)(param_1[0x129] + 0x10) = 0x4000000;
      LOCK();
      UNLOCK();
    }
    if (((((uVar1 & 8) != 0) && (*(char *)(param_1[299] + 0x59) < '\0')) && ((int)param_1[3] == 2))
       && ((*(byte *)(param_1[0x18] + 0x9c) & 0x20) != 0)) {
      local_res18[0] = 0xc1000002;
      StorPortNotification(0x1007,*param_1,param_1 + 1,7,local_res18);
    }
    uVar13 = uVar1 & 1 | 2;
    if ((uVar1 & 2) == 0) {
      uVar13 = uVar1 & 1;
    }
    uVar10 = uVar13 | 4;
    if ((uVar1 & 4) == 0) {
      uVar10 = uVar13;
    }
    uVar13 = uVar10 | 8;
    if ((uVar1 & 8) == 0) {
      uVar13 = uVar10;
    }
    uVar10 = uVar13 | 0x20;
    if ((uVar1 & 0x20) == 0) {
      uVar10 = uVar13;
    }
    if (uVar10 != 0) {
      *(uint *)(param_1[0x129] + 0x10) = uVar10;
      LOCK();
      UNLOCK();
    }
    if ((param_1[0x4a] & 0x20700) == 0) {
      *(undefined4 *)((longlong)param_1 + 0x27c) = 0x40;
    }
    else {
      *(undefined4 *)((longlong)param_1 + 0x27c) = *(undefined4 *)(param_1[0x129] + 0x20);
      if ((((int)param_1[3] == 1) || ((int)param_1[3] - 3U < 3)) &&
         (bVar4 = AhciIsEventAllowedWithinThrottleLimit(*param_1,(longlong)param_1,0x1a,(int *)0x0),
         bVar4)) {
        StorPortExtendedFunction
                  (0x57,*param_1,param_1 + 1,2,0x1a,L"Error recovery",0x10,3,0,0,L"StateFlag",
                   param_1[0x4a],L"IS|SSTS",(ulonglong)uVar1 << 0x20 | uVar17,L"SERR|CMD",
                   CONCAT44(iVar14,uVar5),L"SACT|TFD",
                   CONCAT44(iVar16,*(undefined4 *)((longlong)param_1 + 0x27c)),
                   L"NCQSlice|NormalSlice",
                   CONCAT44((int)param_1[0x5a],*(undefined4 *)((longlong)param_1 + 0x2d4)),
                   L"SingleIOSlice|CI",
                   CONCAT44((int)param_1[0x5b],*(undefined4 *)((longlong)param_1 + 0x2dc)),
                   L"CTC|NCQIssued",
                   CONCAT44((int)param_1[0x5c],*(undefined4 *)((longlong)param_1 + 0x2e4)),
                   L"NormalIssued|SingleIssued",
                   CONCAT44((int)param_1[0x5d],*(undefined4 *)((longlong)param_1 + 0x2ec)));
      }
      if ((*(int *)((longlong)param_1 + 0x27c) == -1) &&
         (*(int *)(*(longlong *)(*param_1 + 400) + 0x10) == -1)) {
        return;
      }
      AhciPortErrorRecovery(param_1);
    }
    iVar16 = 1 << ((byte)param_1[0x48] & 0x1f);
    **(int **)(*param_1 + 0x1a0) = iVar16;
    LOCK();
    UNLOCK();
    uVar10 = *(uint *)(param_1[0x129] + 0x38);
    uVar7 = (ulonglong)uVar10;
    uVar13 = *(uint *)(param_1[0x129] + 0x34);
    if (((uVar10 != 0xffffffff) && (uVar13 != 0xffffffff)) ||
       (*(int *)(*(longlong *)(*param_1 + 400) + 0x10) != -1)) {
      uVar5 = uVar13 | uVar10;
      uVar11 = ~uVar5 & *(uint *)((longlong)param_1 + 0x2dc);
      if (uVar11 == 0) {
        *(int *)((longlong)param_1 + 0x460c) = *(int *)((longlong)param_1 + 0x460c) + 1;
        RecordInterruptHistory
                  ((longlong *)param_1,uVar1,(int)uVar17,iVar14,uVar10,uVar13,0x20010005);
      }
      else {
        *(uint *)(param_1 + 0x5c) = (uint)param_1[0x5c] | uVar11;
        *(uint *)((longlong)param_1 + 0x2e4) = *(uint *)((longlong)param_1 + 0x2e4) & uVar5;
        *(uint *)(param_1 + 0x5d) = (uint)param_1[0x5d] & uVar5;
        *(uint *)((longlong)param_1 + 0x2ec) = *(uint *)((longlong)param_1 + 0x2ec) & uVar5;
        *(uint *)((longlong)param_1 + 0x2dc) = *(uint *)((longlong)param_1 + 0x2dc) & uVar5;
        RecordInterruptHistory
                  ((longlong *)param_1,uVar1,(int)uVar17,iVar14,uVar10,uVar13,0x20000005);
        AhciCompleteIssuedSRBs((longlong *)param_1,'\x01');
      }
      if ((*(uint *)(*param_1 + 0x34) & 1) == 0) {
        return;
      }
      RecordExecutionHistory((longlong *)param_1,0x10000005);
      return;
    }
    local_res10 = (ulonglong)local_res10._4_4_ << 0x20;
    bVar4 = AhciIsEventAllowedWithinThrottleLimit
                      (*param_1,(longlong)param_1,0x2f,(int *)&local_res10);
    if (!bVar4) {
      return;
    }
    uVar9 = local_res10 & 0xffffffff;
    pwVar21 = L"ThrottleCount";
    pwVar20 = L"sact";
    pwVar19 = L"ci";
    pwVar18 = L"is";
    pwVar6 = L"Adapter removed: complete cmd";
  }
  else {
    *(undefined4 *)(param_1[0x129] + 0x10) = 0x78000000;
    LOCK();
    UNLOCK();
    iVar16 = *(int *)(param_1[0x129] + 0x34);
    if ((uVar1 == 0xffffffff) && (iVar14 == -1)) {
      if (iVar16 == -1) {
        if (*(int *)((longlong)param_1 + 0x2dc) != 0) {
          return;
        }
        if ((int)param_1[3] == 6) {
          uVar2 = *(undefined4 *)(param_1[0x129] + 0x28);
          uVar3 = *(undefined4 *)(param_1[0x129] + 0x38);
          *(int *)((longlong)param_1 + 0x460c) = *(int *)((longlong)param_1 + 0x460c) + 1;
          RecordInterruptHistory
                    ((longlong *)param_1,0xffffffff,uVar2,0xffffffff,uVar3,0xffffffff,0x20020005);
          return;
        }
        return;
      }
LAB_140007688:
      if (iVar16 == 0) {
        uVar7 = param_1[0x4a] | 0x200;
      }
      else {
        param_1[0x4a] = param_1[0x4a] | 0x20000;
        if ((param_1[0x4a] & 0x20) != 0) goto LAB_1400076c4;
        uVar7 = param_1[0x4a] & 0xffffffffffffffef;
      }
      param_1[0x4a] = uVar7;
      goto LAB_1400076c4;
    }
    if ((iVar16 != -1) || (*(int *)(*(longlong *)(*param_1 + 400) + 0x10) != -1))
    goto LAB_140007688;
    uVar7 = 0;
    local_res10 = 0;
    if (*param_1 != 0) {
      piVar15 = (int *)param_1[0x8c4];
      if ((piVar15 != (int *)0x0) && (uVar5 = 0, (uint)param_1[0x8c5] != 0)) {
        piVar12 = piVar15;
        do {
          if (*piVar12 == 0x2f) {
            piVar15 = piVar15 + (ulonglong)uVar5 * 8;
            if (piVar15 != (int *)0x0) {
              StorPortQuerySystemTime(&local_res10);
              uVar5 = piVar15[7];
              uVar13 = piVar15[6];
              if ((*(longlong *)(piVar15 + 2) == 0) ||
                 (*(ulonglong *)(piVar15 + 4) <= local_res10 - *(longlong *)(piVar15 + 2))) {
                *(ulonglong *)(piVar15 + 2) = local_res10;
                piVar15[7] = 1;
                uVar7 = (ulonglong)(uVar5 - uVar13);
                if (uVar5 < uVar13) {
                  uVar7 = 0;
                }
              }
              else {
                piVar15[7] = uVar5 + 1;
                if (uVar13 <= uVar5) {
                  return;
                }
                uVar7 = 0;
              }
              goto LAB_14000751d;
            }
            break;
          }
          uVar5 = uVar5 + 1;
          piVar12 = piVar12 + 8;
        } while (uVar5 < (uint)param_1[0x8c5]);
      }
      uVar7 = 0;
    }
LAB_14000751d:
    iVar16 = -1;
    uVar5 = 0;
LAB_14000758b:
    uVar9 = 0;
    pwVar21 = (wchar_t *)0x0;
    uVar13 = 0;
    pwVar20 = (wchar_t *)0x0;
    pwVar19 = L"ThrottleCount";
    pwVar18 = L"sact";
    uVar17 = 0;
    pwVar6 = L"Adapter surprise removed";
  }
  StorPortExtendedFunction
            (0x57,*param_1,param_1 + 1,1,0x2f,pwVar6,0x10,3,0,0,L"pxis",uVar1,L"ssts",uVar17,L"serr"
             ,iVar14,L"cmd",uVar5,pwVar18,iVar16,pwVar19,uVar7,pwVar20,uVar13,pwVar21,uVar9);
  return;
}



===== P_Running_WaitOnBSYDRQ @ 140007f10 =====

void P_Running_WaitOnBSYDRQ(longlong *param_1,char param_2)

{
  short sVar1;
  longlong lVar2;
  longlong *plVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong uStack_40;
  
  lVar2 = *param_1;
  uVar9 = 0;
  while( true ) {
    RecordExecutionHistory(param_1,0x1a);
    uVar7 = *(uint *)(param_1[0x129] + 0x20);
    if (((char)uVar7 < '\0') || ((uVar7 & 8) != 0)) {
      uVar9 = 0x4000000;
      *(undefined4 *)(param_1[0x129] + 0x30) = 0x4000000;
      LOCK();
      UNLOCK();
    }
    if ((-1 < (char)uVar7) && ((uVar7 & 8) == 0)) break;
    uVar10 = 6000;
    if (0x3c < *(uint *)(lVar2 + 0x40)) {
      uVar10 = *(uint *)(lVar2 + 0x40) * 100;
    }
    sVar1 = *(short *)((longlong)param_1 + 0x24e);
    if (uVar10 < (ushort)(sVar1 * 2 + (ushort)*(byte *)((longlong)param_1 + 0x249) +
                          (ushort)*(byte *)((longlong)param_1 + 0x24a) +
                          (ushort)*(byte *)((longlong)param_1 + 0x24b) +
                         (ushort)*(byte *)((longlong)param_1 + 0x24c))) {
      AhciPortLogDeviceStartFailure
                (param_1,L"BSYDRQ total 60s Timeout",(ulonglong)uVar7,(ulonglong)uVar9,0,0);
      P_Running_StartFailed(param_1,param_2);
      uVar8 = 0xff001a;
LAB_140008461:
      RecordExecutionHistory(param_1,uVar8);
      return;
    }
    if (sVar1 == 0x32) {
      uVar6 = P_NotRunning(param_1,param_1[0x129]);
      if ((char)uVar6 != '\0') {
        AhciCOMRESET(param_1,param_1[0x129]);
        *(undefined4 *)((longlong)param_1 + 0x249) = 0;
        *(undefined2 *)((longlong)param_1 + 0x24e) = 0x33;
        *(undefined1 *)(param_1 + 0x49) = 0x13;
        RecordExecutionHistory(param_1,0xfd001a);
        P_Running_WaitOnDET3(param_1,param_2);
        return;
      }
      AhciPortLogDeviceStartFailure
                (param_1,L"BSYDRQ 1s Timeout",(ulonglong)uVar7,(ulonglong)uVar9,0,0);
      P_Running_StartFailed(param_1,param_2);
      uVar8 = 0xfc001a;
      goto LAB_140008461;
    }
    *(short *)((longlong)param_1 + 0x24e) = sVar1 + 1;
    RecordExecutionHistory(param_1,0x8001a);
    if (*(char *)(lVar2 + 0x18c) == '\0') {
      iVar5 = StorPortExtendedFunction(0x21,lVar2,param_1[0x153],P_Running_Callback,param_1,20000,0)
      ;
      if (iVar5 == 0) {
        return;
      }
      if (iVar5 == -0x3efffff4) {
        return;
      }
    }
    StorPortStallExecution(20000);
  }
  local_58 = 3;
  local_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (param_2 == '\0') {
    if ((*(byte *)((longlong)param_1 + 0x24d) & 1) != 0) {
      bVar4 = false;
      goto LAB_140008134;
    }
  }
  else if ((*(byte *)((longlong)param_1 + 0x24d) & 2) != 0) {
    RunNextPort(param_1,'\0');
    return;
  }
  lVar2 = *param_1;
  bVar4 = true;
  if (((char)*(undefined4 *)(lVar2 + 0x2c) < '\0') && ((int)param_1[0x48] != -1)) {
    local_res18[0] = 0;
    StorPortExtendedFunction(0xb,lVar2,(int)param_1[0x48],local_res18);
    uStack_40 = CONCAT71(uStack_40._1_7_,(undefined1)local_res18[0]);
  }
  else {
    StorPortNotification(0x1003,lVar2,3,0,&local_58);
  }
LAB_140008134:
  *(undefined4 *)(param_1[0x129] + 0x30) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1[0x129] + 0x10) = 0xffffffff;
  LOCK();
  UNLOCK();
  **(int **)(*param_1 + 0x1a0) = 1 << ((byte)param_1[0x48] & 0x1f);
  LOCK();
  UNLOCK();
  uVar9 = *(uint *)(param_1[0x129] + 0x14);
  uVar7 = uVar9 & 0xffffffcf | 0xcf;
  if ((*(uint *)(*param_1 + 0x1a8) & 0x10000000) == 0) {
    uVar7 = uVar9 & 0xffffff4f | 0x4f;
  }
  uVar9 = uVar7 & 0xff7fffff | 0xfd400000;
  if ((*(uint *)(param_1[0x129] + 0x18) >> 0x14 & 1) == 0) {
    uVar9 = uVar7 & 0x7f7fffff | 0x7d400000;
  }
  *(uint *)(param_1[0x129] + 0x14) = uVar9;
  LOCK();
  UNLOCK();
  *(uint *)(param_1[0x129] + 0x18) = *(uint *)(param_1[0x129] + 0x18) | 1;
  LOCK();
  UNLOCK();
  *(undefined1 *)(param_1 + 0x49) = 0x16;
  param_1[0x4a] = param_1[0x4a] & 0xfffffffffffff7ff;
  *(uint *)(param_1 + 0x8c0) =
       ((uint)*(byte *)((longlong)param_1 + 0x24c) +
        (uint)*(ushort *)((longlong)param_1 + 0x24e) * 2 +
        (uint)*(byte *)((longlong)param_1 + 0x24b) + (uint)*(byte *)((longlong)param_1 + 0x24a) +
       (uint)*(byte *)((longlong)param_1 + 0x249)) * 10;
  ActivateQueue(param_1,'\x01');
  *(byte *)((longlong)param_1 + 0x24d) = *(byte *)((longlong)param_1 + 0x24d) & 0xfd;
  RecordExecutionHistory(param_1,0x100a001a);
  if (bVar4) {
    lVar2 = *param_1;
    if (((char)*(undefined4 *)(lVar2 + 0x2c) < '\0') && (iVar5 = (int)param_1[0x48], iVar5 != -1)) {
      StorPortExtendedFunction(0xc,lVar2,iVar5,uStack_40 & 0xff);
    }
    else {
      StorPortNotification(0x1004,lVar2,&local_58);
    }
  }
  if (((ulonglong)param_1[0x4a] >> 0x15 & 1) != 0) {
    local_res20[0] = 0;
    StorPortNotification(0x1002,*param_1,param_1 + 0x120,param_1,0,local_res20);
    param_1[0x4a] = param_1[0x4a] & 0xffffffffffdfffff;
  }
  if ((param_2 == '\0') && ((*(byte *)((longlong)param_1 + 0x24d) & 1) != 0)) {
    cVar11 = '\x01';
  }
  else {
    cVar11 = '\0';
  }
  lVar2 = *param_1;
  if (*(char *)(lVar2 + 0x18d) == '\0') {
    return;
  }
  uVar9 = *(uint *)(param_1 + 0x48);
  do {
    uVar9 = uVar9 + 1;
    if (*(uint *)(lVar2 + 0x184) < uVar9) {
      *(undefined1 *)(lVar2 + 0x18d) = 0;
      if (cVar11 == '\0') {
        AhciPortStartTelemetry(lVar2);
        return;
      }
      return;
    }
    plVar3 = *(longlong **)(lVar2 + 0x1b0 + (ulonglong)uVar9 * 8);
  } while (plVar3 == (longlong *)0x0);
  if ((*(byte *)(plVar3 + 0x49) & 0xdf) == 0) {
    P_Running_StartAttempt(plVar3,cVar11);
    return;
  }
  return;
}



===== AhciPortLogDeviceStartFailure @ 140008480 =====

void AhciPortLogDeviceStartFailure
               (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  bool bVar1;
  
  bVar1 = AhciIsEventAllowedWithinThrottleLimit(*param_1,(longlong)param_1,0x1e,(int *)0x0);
  if (bVar1) {
    StorPortExtendedFunction
              (0x57,*param_1,param_1 + 1,2,0x1e,param_2,8,3,1,0,L"StateFlag",param_1[0x4a],
               L"StartState",param_1[0x49],L"PortReset|StartFailed",
               CONCAT44((int)param_1[0x8ba],*(undefined4 *)((longlong)param_1 + 0x45d4)),
               L"ErrorRecovery|BusChange",
               CONCAT44((int)param_1[0x8bb],*(undefined4 *)((longlong)param_1 + 0x4604)),
               L"Parameter1",param_3,L"Parameter2",param_4,L"Parameter3",param_5,L"Parameter4",
               param_6);
  }
  return;
}



===== P_Running_StartFailed @ 140008620 =====

void P_Running_StartFailed(longlong *param_1,char param_2)

{
  longlong *plVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  char cVar6;
  undefined4 local_res10 [2];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  *(int *)((longlong)param_1 + 0x45d4) = *(int *)((longlong)param_1 + 0x45d4) + 1;
  local_48 = 3;
  local_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  *(uint *)(param_1 + 0x8c0) =
       ((uint)*(byte *)((longlong)param_1 + 0x24c) +
        (uint)*(ushort *)((longlong)param_1 + 0x24e) * 2 +
        (uint)*(byte *)((longlong)param_1 + 0x24b) + (uint)*(byte *)((longlong)param_1 + 0x24a) +
       (uint)*(byte *)((longlong)param_1 + 0x249)) * 10;
  if (param_2 == '\0') {
    if ((*(byte *)((longlong)param_1 + 0x24d) & 1) != 0) {
      bVar2 = false;
      goto LAB_140008777;
    }
  }
  else if ((*(byte *)((longlong)param_1 + 0x24d) & 2) != 0) {
    lVar5 = *param_1;
    if (*(char *)(lVar5 + 0x18d) == '\0') {
      return;
    }
    uVar4 = *(uint *)(param_1 + 0x48);
    while (uVar4 = uVar4 + 1, uVar4 <= *(uint *)(lVar5 + 0x184)) {
      plVar1 = *(longlong **)(lVar5 + 0x1b0 + (ulonglong)uVar4 * 8);
      if (plVar1 != (longlong *)0x0) {
        if ((*(byte *)(plVar1 + 0x49) & 0xdf) == 0) {
          P_Running_StartAttempt(plVar1,'\0');
          return;
        }
        return;
      }
    }
    *(undefined1 *)(lVar5 + 0x18d) = 0;
LAB_140008ab0:
    AhciPortStartTelemetry(lVar5);
    return;
  }
  lVar5 = *param_1;
  bVar2 = true;
  if (((char)*(undefined4 *)(lVar5 + 0x2c) < '\0') && ((int)param_1[0x48] != -1)) {
    local_res10[0] = 0;
    StorPortExtendedFunction(0xb,lVar5,(int)param_1[0x48],local_res10);
    uStack_30 = CONCAT71(uStack_30._1_7_,(undefined1)local_res10[0]);
  }
  else {
    StorPortNotification(0x1003,lVar5,3,0,&local_48);
  }
LAB_140008777:
  *(undefined1 *)(param_1 + 0x49) = 0xff;
  param_1[0x4a] = param_1[0x4a] & 0xffffffffffff77ff;
  if (param_1[0x149] != 0) {
    StorPortExtendedFunction(1,*param_1);
    param_1[0x149] = 0;
    *(undefined2 *)(param_1 + 0x148) = 0;
    *(undefined1 *)((longlong)param_1 + 0xa42) = 0;
  }
  if ((int)param_1[0x14a] != 0) {
    param_1[0x14a] = 0;
    param_1[0x14b] = 0;
    param_1[0x14c] = 0;
    param_1[0x14d] = 0;
    param_1[0x14e] = 0;
    param_1[0x14f] = 0;
    param_1[0x150] = 0;
    param_1[0x151] = 0;
    param_1[0x152] = 0;
  }
  *(undefined1 *)((longlong)param_1 + 0x164) = 0;
  *(undefined1 *)((longlong)param_1 + 0x165) = 0;
  *(undefined1 *)((longlong)param_1 + 0x166) = 0;
  *(undefined1 *)((longlong)param_1 + 0x167) = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  *(undefined1 *)((longlong)param_1 + 0x169) = 0;
  *(undefined1 *)((longlong)param_1 + 0x16a) = 0;
  *(undefined1 *)((longlong)param_1 + 0x16b) = 0;
  *(undefined1 *)((longlong)param_1 + 0x16c) = 0;
  *(undefined1 *)((longlong)param_1 + 0x16d) = 0;
  *(undefined1 *)((longlong)param_1 + 0x16e) = 0;
  *(undefined1 *)((longlong)param_1 + 0x16f) = 0;
  *(undefined1 *)(param_1 + 0x2e) = 0;
  *(undefined1 *)((longlong)param_1 + 0x171) = 0;
  *(undefined1 *)((longlong)param_1 + 0x172) = 0;
  *(undefined1 *)((longlong)param_1 + 0x173) = 0;
  *(undefined1 *)(param_1 + 0x2f) = 0;
  *(undefined1 *)((longlong)param_1 + 0x179) = 0;
  *(undefined1 *)((longlong)param_1 + 0x17a) = 0;
  *(undefined1 *)((longlong)param_1 + 0x17b) = 0;
  *(undefined1 *)((longlong)param_1 + 0x17c) = 0;
  *(undefined1 *)((longlong)param_1 + 0x17d) = 0;
  *(undefined1 *)((longlong)param_1 + 0x17e) = 0;
  *(undefined1 *)((longlong)param_1 + 0x17f) = 0;
  *(uint *)(param_1 + 0x5c) =
       *(uint *)(param_1 + 0x5c) |
       *(uint *)((longlong)param_1 + 0x2dc) | *(uint *)(param_1 + 0x5b) |
       *(uint *)((longlong)param_1 + 0x2d4) | *(uint *)(param_1 + 0x5a);
  param_1[0x5b] = 0;
  *(undefined8 *)((longlong)param_1 + 0x2e4) = 0;
  *(undefined4 *)((longlong)param_1 + 0x2ec) = 0;
  param_1[0x5a] = 0;
  *(undefined4 *)((longlong)param_1 + 0x2cc) = 0;
  *(undefined4 *)(param_1[0x129] + 0x30) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1[0x129] + 0x10) = 0xffffffff;
  LOCK();
  UNLOCK();
  **(int **)(*param_1 + 0x1a0) = 1 << ((byte)param_1[0x48] & 0x1f);
  LOCK();
  UNLOCK();
  uVar4 = *(uint *)(param_1[0x129] + 0x14);
  uVar3 = uVar4 & 0xffffffcf | 0xcf;
  if ((*(uint *)(*param_1 + 0x1a8) & 0x10000000) == 0) {
    uVar3 = uVar4 & 0xffffff4f | 0x4f;
  }
  uVar4 = uVar3 & 0xff7fffff | 0xfd400000;
  if ((*(uint *)(param_1[0x129] + 0x18) >> 0x14 & 1) == 0) {
    uVar4 = uVar3 & 0x7f7fffff | 0x7d400000;
  }
  *(uint *)(param_1[0x129] + 0x14) = uVar4;
  LOCK();
  UNLOCK();
  AhciPortFailAllIos(param_1,8);
  *(byte *)((longlong)param_1 + 0x24d) = *(byte *)((longlong)param_1 + 0x24d) & 0xfd;
  if (bVar2) {
    lVar5 = *param_1;
    if (((char)*(undefined4 *)(lVar5 + 0x2c) < '\0') && ((int)param_1[0x48] != -1)) {
      StorPortExtendedFunction(0xc,lVar5,(int)param_1[0x48],uStack_30 & 0xff);
    }
    else {
      StorPortNotification(0x1004,lVar5,&local_48);
    }
  }
  if ((param_2 == '\0') && ((*(byte *)((longlong)param_1 + 0x24d) & 1) != 0)) {
    cVar6 = '\x01';
  }
  else {
    cVar6 = '\0';
  }
  lVar5 = *param_1;
  if (*(char *)(lVar5 + 0x18d) != '\0') {
    uVar4 = *(uint *)(param_1 + 0x48);
    do {
      uVar4 = uVar4 + 1;
      if (*(uint *)(lVar5 + 0x184) < uVar4) {
        *(undefined1 *)(lVar5 + 0x18d) = 0;
        if (cVar6 != '\0') {
          return;
        }
        goto LAB_140008ab0;
      }
      plVar1 = *(longlong **)(lVar5 + 0x1b0 + (ulonglong)uVar4 * 8);
    } while (plVar1 == (longlong *)0x0);
    if ((*(byte *)(plVar1 + 0x49) & 0xdf) == 0) {
      P_Running_StartAttempt(plVar1,cVar6);
      return;
    }
  }
  return;
}



===== RunNextPort @ 140008af0 =====

void RunNextPort(longlong *param_1,char param_2)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar1 = *param_1;
  if (*(char *)(lVar1 + 0x18d) != '\0') {
    uVar4 = (ulonglong)*(uint *)(param_1 + 0x48);
    do {
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
      if (*(uint *)(lVar1 + 0x184) < uVar3) {
        *(undefined1 *)(lVar1 + 0x18d) = 0;
        if (param_2 == '\0') {
          AhciPortStartTelemetry(lVar1);
          return;
        }
        return;
      }
      plVar2 = *(longlong **)(lVar1 + 0x1b0 + uVar4 * 8);
    } while (plVar2 == (longlong *)0x0);
    if ((*(byte *)(plVar2 + 0x49) & 0xdf) == 0) {
      P_Running_StartAttempt(plVar2,param_2);
    }
  }
  return;
}



===== P_Running_StartAttempt @ 140008b30 =====

void P_Running_StartAttempt(longlong *param_1,char param_2)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 3;
  local_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (param_2 == '\0') {
    AhciInterruptSpinlockAcquire(*param_1,(int)param_1[0x48],(longlong)&local_28);
  }
  *(undefined4 *)(param_1 + 0x49) = 0x11;
  *(undefined1 *)((longlong)param_1 + 0x24c) = 0;
  *(undefined2 *)((longlong)param_1 + 0x24e) = 0;
  *(byte *)((longlong)param_1 + 0x24d) =
       param_2 != '\0' | *(byte *)((longlong)param_1 + 0x24d) & 0xfe | 2;
  if (param_2 == '\0') {
    AhciInterruptSpinlockRelease(*param_1,(int)param_1[0x48],(longlong)&local_28);
  }
  P_Running((ulonglong *)param_1,'\0');
  return;
}



===== AhciInterruptSpinlockAcquire @ 140008bf0 =====

void AhciInterruptSpinlockAcquire(longlong param_1,int param_2,longlong param_3)

{
  undefined4 local_res8 [8];
  
  if (((char)*(undefined4 *)(param_1 + 0x2c) < '\0') && (param_2 != -1)) {
    local_res8[0] = 0;
    StorPortExtendedFunction(0xb,param_1,param_2,local_res8);
    *(undefined1 *)(param_3 + 0x18) = (undefined1)local_res8[0];
    return;
  }
  StorPortNotification(0x1003,param_1,3,0,param_3);
  return;
}



===== P_Running_WaitOnFRE @ 140008c70 =====

void P_Running_WaitOnFRE(longlong *param_1,char param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  lVar1 = *param_1;
  while( true ) {
    if ((*(uint *)(lVar1 + 0x34) & 1) != 0) {
      RecordExecutionHistory(param_1,0x19);
    }
    *(uint *)(param_1[0x129] + 0x18) = *(uint *)(param_1[0x129] + 0x18) | 0x10;
    LOCK();
    UNLOCK();
    if ((*(uint *)(param_1[0x129] + 0x18) >> 0xe & 1) != 0) break;
    if (5 < *(byte *)((longlong)param_1 + 0x24c)) {
      uVar3 = 0xff0019;
      goto LAB_140008d06;
    }
    *(byte *)((longlong)param_1 + 0x24c) = *(byte *)((longlong)param_1 + 0x24c) + 1;
    RecordExecutionHistory(param_1,0x80019);
    if (*(char *)(lVar1 + 0x18c) == '\0') {
      iVar2 = StorPortExtendedFunction(0x21,lVar1,param_1[0x153],P_Running_Callback,param_1,10000,0)
      ;
      if (iVar2 == 0) {
        return;
      }
      if (iVar2 == -0x3efffff4) {
        return;
      }
    }
    StorPortStallExecution(10000);
  }
  uVar3 = 0xa0019;
LAB_140008d06:
  *(undefined1 *)(param_1 + 0x49) = 0x15;
  RecordExecutionHistory(param_1,uVar3);
  P_Running_WaitOnBSYDRQ(param_1,param_2);
  return;
}



===== P_Running_WaitOnDET @ 140008da0 =====

void P_Running_WaitOnDET(ulonglong *param_1,char param_2)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong *puVar6;
  byte bVar7;
  undefined4 uVar8;
  
  uVar2 = *param_1;
  bVar7 = 3;
  puVar6 = param_1;
  uVar4 = IsPortD3ColdEnabled(param_1);
  if ((char)uVar4 == '\0') {
    if (*(char *)(uVar2 + 0x18c) == '\0') {
      if ((*(byte *)((longlong)puVar6 + 0x254) & 8) != 0) {
        bVar7 = 0x21;
      }
    }
    else {
      bVar7 = 0x21;
    }
  }
  else {
    bVar7 = 0x21;
  }
  if ((*(char *)(uVar2 + 0x18d) == '\0') && (*(uint *)(uVar2 + 0x54) != 0)) {
    uVar4 = (ulonglong)*(uint *)(uVar2 + 0x54) / 10;
    if ((uint)bVar7 < (uint)uVar4) {
      bVar7 = (byte)uVar4;
    }
  }
  else {
    uVar4 = (ulonglong)*(uint *)(uVar2 + 0x3c) / 10;
    if ((uint)bVar7 < (uint)uVar4) {
      bVar7 = (byte)uVar4;
    }
  }
  while( true ) {
    if ((*(uint *)(uVar2 + 0x34) & 1) != 0) {
      RecordExecutionHistory((longlong *)param_1,0x16);
    }
    uVar1 = *(uint *)(param_1[0x129] + 0x28);
    uVar5 = uVar1 & 0xf;
    if (uVar5 != 0) break;
    if (((uVar1 & 0xf00) == 0x200) || (((uVar1 & 0xf00) - 0x600 & 0xfffffdff) == 0)) {
      uVar8 = 0x10800016;
      goto LAB_140008e9c;
    }
    if (bVar7 < *(byte *)((longlong)param_1 + 0x249)) {
      AhciPortLogDeviceStartFailure
                ((longlong *)param_1,L"Device Start Fail:DET Timeout",(ulonglong)uVar1,
                 (ulonglong)bVar7 * 10,(ulonglong)*(uint *)(uVar2 + 0x3c),
                 (ulonglong)*(uint *)(uVar2 + 0x54));
      P_Running_StartFailed((longlong *)param_1,param_2);
      uVar8 = 0x10ff0016;
LAB_140008faf:
      RecordExecutionHistory((longlong *)param_1,uVar8);
      return;
    }
    *(byte *)((longlong)param_1 + 0x249) = *(byte *)((longlong)param_1 + 0x249) + 1;
    RecordExecutionHistory((longlong *)param_1,0x10810016);
    if (*(char *)(uVar2 + 0x18c) == '\0') {
      iVar3 = StorPortExtendedFunction(0x21,uVar2,param_1[0x153],P_Running_Callback,param_1,10000,0)
      ;
      if (iVar3 == 0) {
        return;
      }
      if (iVar3 == -0x3efffff4) {
        return;
      }
    }
    StorPortStallExecution(10000);
  }
  if (uVar5 == 1) {
    if (((uVar1 & 0xf00) != 0x200) && (((uVar1 & 0xf00) - 0x600 & 0xfffffdff) != 0)) {
      *(undefined1 *)(param_1 + 0x49) = 0x12;
      RecordExecutionHistory((longlong *)param_1,0x10a10016);
      P_Running_WaitWhileDET1((longlong *)param_1,param_2);
      return;
    }
    uVar8 = 0x10a00016;
  }
  else {
    if (uVar5 != 3) {
      AhciPortLogDeviceStartFailure
                ((longlong *)param_1,L"Device Start Fail:DET Error",(ulonglong)uVar1,
                 (ulonglong)bVar7 * 10,(ulonglong)*(uint *)(uVar2 + 0x3c),
                 (ulonglong)*(uint *)(uVar2 + 0x54));
      P_Running_StartFailed((longlong *)param_1,param_2);
      uVar8 = 0x10a30016;
      goto LAB_140008faf;
    }
    uVar8 = 0x10a20016;
  }
LAB_140008e9c:
  *(undefined1 *)(param_1 + 0x49) = 0x14;
  RecordExecutionHistory((longlong *)param_1,uVar8);
  P_Running_WaitOnFRE((longlong *)param_1,param_2);
  return;
}



===== IsPortD3ColdEnabled @ 140009070 =====

ulonglong IsPortD3ColdEnabled(ulonglong *param_1)

{
  if ((*(uint *)(*param_1 + 0x38) & 0x200) == 0) {
    return CONCAT71((uint7)(param_1[0x4a] >> 0x17),(char)(param_1[0x4a] >> 0xf)) &
           0xffffffffffffff01;
  }
  return *param_1 & 0xffffffffffffff00;
}



===== P_Running_WaitOnDET3 @ 1400090a0 =====

void P_Running_WaitOnDET3(longlong *param_1,char param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *param_1;
  do {
    if ((*(uint *)(lVar1 + 0x34) & 1) != 0) {
      RecordExecutionHistory(param_1,0x18);
    }
    if (((byte)*(uint *)(param_1[0x129] + 0x28) & 0xf) == 3) {
      *(undefined1 *)(param_1 + 0x49) = 0x14;
      RecordExecutionHistory(param_1,0x100a0018);
      P_Running_WaitOnFRE(param_1,param_2);
      return;
    }
    if (100 < *(byte *)((longlong)param_1 + 0x24b)) {
      AhciPortLogDeviceStartFailure
                (param_1,L"Device Start Fail:DET3 Timeout",
                 (ulonglong)*(uint *)(param_1[0x129] + 0x28),0,0,0);
      P_Running_StartFailed(param_1,param_2);
      RecordExecutionHistory(param_1,0x10ff0018);
      return;
    }
    *(byte *)((longlong)param_1 + 0x24b) = *(byte *)((longlong)param_1 + 0x24b) + 1;
    RecordExecutionHistory(param_1,0x10080018);
    if (*(char *)(lVar1 + 0x18c) == '\0') {
      iVar2 = StorPortExtendedFunction(0x21,lVar1,param_1[0x153],P_Running_Callback,param_1,10000,0)
      ;
      if (iVar2 == 0) {
        return;
      }
      if (iVar2 == -0x3efffff4) {
        return;
      }
    }
    StorPortStallExecution(10000);
  } while( true );
}



===== PortBusChangeProcess @ 140009200 =====

void PortBusChangeProcess(ulonglong *param_1)

{
  ulonglong *puVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  int local_res8 [2];
  undefined8 in_stack_ffffffffffffffb8;
  uint uVar6;
  ulonglong uVar5;
  code *pcVar7;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar6 = (uint)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  local_28 = 3;
  local_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  uVar4 = *(uint *)(param_1[0x129] + 0x2c) >> 4 & 0xf;
  if (((uVar4 != 0) && (uVar4 != (*(uint *)(*param_1 + 0x38) >> 0xc & 0xf))) &&
     (uVar4 != (*(uint *)(*param_1 + 0x1a8) >> 0x14 & 0xf))) {
    *(uint *)(param_1[0x129] + 0x2c) = *(uint *)(param_1[0x129] + 0x2c) & 0xffffff0f;
    LOCK();
    UNLOCK();
  }
  AhciInterruptSpinlockAcquire(*param_1,(int)param_1[0x48],(longlong)&local_28);
  LOCK();
  *(uint *)(param_1 + 0x4a) = (uint)param_1[0x4a] | 0x1000000;
  UNLOCK();
  AhciPortReset(param_1,'\x01');
  AhciInterruptSpinlockRelease(*param_1,(int)param_1[0x48],(longlong)&local_28);
  *(undefined1 *)((longlong)param_1 + 0x235) = 1;
  pcVar7 = AhciBusChangeCallback;
  uVar5 = (ulonglong)uVar6 << 0x20;
  local_res8[0] = -0x3efffffe;
  StorPortNotification(0x1005,*param_1,2,param_1 + 1,uVar5,AhciBusChangeCallback,0,local_res8);
  if (local_res8[0] == -0x3effffff) {
    if (param_1[0x155] == 0) {
      StorPortExtendedFunction(0x20,*param_1,param_1 + 0x155);
    }
    iVar2 = StorPortExtendedFunction
                      (0x21,*param_1,param_1[0x155],AhciBusChangeTimerCallback,param_1,100000,0);
    if (iVar2 != 0) {
      LOCK();
      puVar1 = param_1 + 0x59;
      uVar5 = *puVar1;
      *(uint *)puVar1 = (uint)*puVar1 & 0xfffffffb;
      UNLOCK();
      if (((uint)uVar5 >> 2 & 1) != 0) {
        PortReleaseActiveReference(param_1,0);
      }
    }
  }
  else {
    if (param_1[0x155] != 0) {
      StorPortExtendedFunction(0x22,*param_1);
      param_1[0x155] = 0;
    }
    LOCK();
    puVar1 = param_1 + 0x59;
    uVar3 = *puVar1;
    *(uint *)puVar1 = (uint)*puVar1 & 0xfffffffb;
    UNLOCK();
    if (((uint)uVar3 >> 2 & 1) != 0) {
      uVar3 = PortPoFxEnabled((longlong)param_1);
      if ((char)uVar3 != '\0') {
        StorPortExtendedFunction
                  (0x32,*param_1,param_1 + 1,0,uVar5 & 0xffffffff00000000,
                   (ulonglong)pcVar7 & 0xffffffff00000000);
      }
    }
  }
  return;
}



===== AhciInterruptSpinlockRelease @ 140009400 =====

void AhciInterruptSpinlockRelease(longlong param_1,int param_2,longlong param_3)

{
  if (((char)*(undefined4 *)(param_1 + 0x2c) < '\0') && (param_2 != -1)) {
    StorPortExtendedFunction(0xc,param_1,param_2,*(undefined1 *)(param_3 + 0x18));
    return;
  }
  StorPortNotification(0x1004,param_1);
  return;
}



===== AhciPortReset @ 140009460 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AhciPortReset(ulonglong *param_1,char param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  ulonglong *puVar4;
  bool bVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  char *pcVar8;
  longlong lVar9;
  undefined8 uVar10;
  uint uVar11;
  uint uVar12;
  char cVar13;
  undefined4 uVar14;
  byte bVar15;
  ulonglong uVar16;
  size_t _Size;
  ulonglong uVar17;
  char *pcVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  undefined8 unaff_R13;
  char cVar21;
  undefined1 auStack_568 [32];
  char local_548;
  ulonglong *local_540;
  ulonglong local_538;
  uint local_530;
  ulonglong local_528;
  longlong local_520;
  ulonglong local_518;
  ulonglong local_510;
  ulonglong local_508;
  ulonglong local_500;
  ulonglong local_4f8;
  ulonglong local_4f0;
  ulonglong local_4e8 [6];
  undefined4 local_4b8;
  undefined4 local_4b4;
  undefined1 local_4b0 [32];
  undefined8 local_490;
  undefined1 local_478 [32];
  undefined8 local_458;
  undefined1 local_450 [32];
  undefined8 local_430;
  undefined1 local_428 [32];
  undefined8 local_408;
  undefined1 local_400 [32];
  ulonglong local_3e0;
  undefined1 local_3d8 [32];
  ulonglong local_3b8;
  undefined1 local_3b0 [32];
  ulonglong local_390;
  undefined1 local_388 [32];
  ulonglong local_368;
  undefined1 local_360 [32];
  ulonglong local_340;
  undefined4 local_338;
  undefined4 local_334;
  undefined1 local_330 [32];
  undefined4 local_310;
  undefined4 local_30c;
  undefined1 local_2f8 [32];
  undefined8 local_2d8;
  undefined1 local_2d0 [32];
  undefined8 local_2b0;
  undefined1 local_2a8 [32];
  undefined8 local_288;
  undefined1 local_280 [32];
  ulonglong local_260;
  undefined1 local_258 [32];
  ulonglong local_238;
  undefined1 local_230 [32];
  ulonglong local_210;
  undefined1 local_208 [32];
  ulonglong local_1e8;
  undefined1 local_1e0 [32];
  ulonglong local_1c0;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined1 local_1b0 [32];
  undefined4 local_190;
  undefined4 local_18c;
  undefined1 local_178 [32];
  undefined8 local_158;
  undefined1 local_150 [32];
  undefined8 local_130;
  undefined1 local_128 [32];
  undefined8 local_108;
  undefined1 local_100 [32];
  ulonglong local_e0;
  undefined1 local_d8 [32];
  ulonglong local_b8;
  undefined1 local_b0 [32];
  ulonglong local_90;
  undefined1 local_88 [32];
  ulonglong local_68;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_568;
  *(int *)(param_1 + 0x8ba) = (int)param_1[0x8ba] + 1;
  bVar5 = false;
  uVar12 = (uint)CONCAT71((int7)((ulonglong)unaff_R13 >> 8),1);
  if (((param_2 == '\0') || ((char)param_1[0x49] == '\x16')) || ((char)param_1[0x49] == -1)) {
    uVar14 = 0x50;
  }
  else {
    bVar5 = true;
    uVar14 = 0x10040050;
  }
  local_548 = param_2;
  local_540 = param_1;
  local_530 = uVar12;
  RecordExecutionHistory((longlong *)param_1,uVar14);
  pcVar18 = "PortStartTakeTooLong";
  if (!bVar5) {
    pcVar18 = "AhciPortReset";
  }
  local_4f0 = 0;
  if ((int)param_1[3] != 2) {
    StorPortQuerySystemTime(&local_4f0);
    if ((param_1[0x8be] == 0) || (35999999999 < local_4f0 - param_1[0x8be])) {
      uVar19 = param_1[0x8bc];
      uVar17 = param_1[0x49];
      uVar16 = param_1[0x4a];
      uVar12 = *(uint *)((longlong)param_1 + 0xb4);
      uVar20 = local_540[0x8ba];
      param_1[0x8be] = local_4f0;
      local_538 = (ulonglong)(uint)param_1[0x8bd];
      uVar14 = *(undefined4 *)((longlong)param_1 + 0x45e4);
      uVar1 = *(undefined4 *)((longlong)param_1 + 0x45d4);
      uVar2 = *(undefined4 *)((longlong)local_540 + 0x45dc);
      uVar6 = local_540[0x8bb];
      local_510 = *local_540;
      memset(&local_4b8,0,0x180);
      uVar11 = 0;
      local_4b8 = 1;
      local_4b4 = 1;
      pcVar8 = pcVar18;
      do {
        if (*pcVar8 == '\0') goto LAB_14000960e;
        if (pcVar8[1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_140009604:
          if (uVar11 < 0x20) goto LAB_14000960e;
          break;
        }
        if (pcVar8[2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_140009604;
        }
        if (pcVar8[3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_140009604;
        }
        pcVar8 = pcVar8 + 4;
        uVar11 = uVar11 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000960e:
      memcpy(local_4b0,pcVar18,(ulonglong)uVar11);
      lVar9 = 0;
      local_490 = 1;
      uVar11 = 0;
      do {
        if ("PortReset|PortErrorRecovery"[lVar9] == '\0') goto LAB_14000967f;
        if ("PortReset|PortErrorRecovery"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000966c:
          if (0x1f < uVar11) {
            uVar11 = 0x20;
          }
          goto LAB_14000967f;
        }
        if ("PortReset|PortErrorRecovery"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000966c;
        }
        if ("PortReset|PortErrorRecovery"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000966c;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000967f:
      memcpy(local_478,"PortReset|PortErrorRecovery",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("StartFail|NonQErrorRecovery"[lVar9] == '\0') goto LAB_1400096d8;
        if ("StartFail|NonQErrorRecovery"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_1400096d1:
          if (uVar11 < 0x20) goto LAB_1400096d8;
          break;
        }
        if ("StartFail|NonQErrorRecovery"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_1400096d1;
        }
        if ("StartFail|NonQErrorRecovery"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_1400096d1;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_1400096d8:
      local_458 = CONCAT44((int)uVar20,(int)uVar6);
      memcpy(local_450,"StartFail|NonQErrorRecovery",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("NCQError|NCQErrorComplete"[lVar9] == '\0') goto LAB_14000972c;
        if ("NCQError|NCQErrorComplete"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_140009725:
          if (uVar11 < 0x20) goto LAB_14000972c;
          break;
        }
        if ("NCQError|NCQErrorComplete"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_140009725;
        }
        if ("NCQError|NCQErrorComplete"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_140009725;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000972c:
      local_430 = CONCAT44(uVar1,uVar2);
      memcpy(local_428,"NCQError|NCQErrorComplete",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("PortDriverResetCount"[lVar9] == '\0') goto LAB_140009780;
        if ("PortDriverResetCount"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_140009779:
          if (uVar11 < 0x20) goto LAB_140009780;
          break;
        }
        if ("PortDriverResetCount"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_140009779;
        }
        if ("PortDriverResetCount"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_140009779;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_140009780:
      local_408 = CONCAT44((int)uVar19,uVar14);
      memcpy(local_400,"PortDriverResetCount",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("StateFlags"[lVar9] == '\0') goto LAB_1400097d8;
        if ("StateFlags"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_1400097d1:
          if (uVar11 < 0x20) goto LAB_1400097d8;
          break;
        }
        if ("StateFlags"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_1400097d1;
        }
        if ("StateFlags"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_1400097d1;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_1400097d8:
      local_3e0 = (ulonglong)uVar12;
      memcpy(local_3d8,"StateFlags",(ulonglong)uVar11);
      uVar12 = 0;
      lVar9 = 0;
      do {
        if ("StartState"[lVar9] == '\0') goto LAB_140009838;
        if ("StartState"[lVar9 + 1] == '\0') {
          uVar12 = uVar12 + 1;
LAB_140009831:
          if (uVar12 < 0x20) goto LAB_140009838;
          break;
        }
        if ("StartState"[lVar9 + 2] == '\0') {
          uVar12 = uVar12 + 2;
          goto LAB_140009831;
        }
        if ("StartState"[lVar9 + 3] == '\0') {
          uVar12 = uVar12 + 3;
          goto LAB_140009831;
        }
        uVar12 = uVar12 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar12 < 0x20);
      uVar12 = 0x20;
LAB_140009838:
      local_3b8 = uVar16;
      memcpy(local_3b0,"StartState",(ulonglong)uVar12);
      uVar12 = 0;
      lVar9 = 0;
      do {
        if ("TotalCountSurpriseRemove"[lVar9] == '\0') goto LAB_14000989c;
        if ("TotalCountSurpriseRemove"[lVar9 + 1] == '\0') {
          uVar12 = uVar12 + 1;
LAB_140009895:
          if (uVar12 < 0x20) goto LAB_14000989c;
          break;
        }
        if ("TotalCountSurpriseRemove"[lVar9 + 2] == '\0') {
          uVar12 = uVar12 + 2;
          goto LAB_140009895;
        }
        if ("TotalCountSurpriseRemove"[lVar9 + 3] == '\0') {
          uVar12 = uVar12 + 3;
          goto LAB_140009895;
        }
        uVar12 = uVar12 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar12 < 0x20);
      uVar12 = 0x20;
LAB_14000989c:
      local_390 = uVar17;
      memcpy(local_388,"TotalCountSurpriseRemove",(ulonglong)uVar12);
      param_1 = local_540;
      local_368 = local_538;
      StorPortExtendedFunction(0x4f,local_510,local_540 + 1,&local_4b8);
      param_2 = local_548;
      uVar12 = local_530;
    }
  }
  uVar20 = 0;
  uVar17 = param_1[0x115];
  uVar16 = param_1[0x8c2];
  uVar19 = param_1[0x8c3];
  local_538 = uVar17;
  local_508 = uVar16;
  local_500 = uVar19;
  if ((longlong)uVar17 <= (longlong)uVar16) {
    if ((longlong)uVar16 <= (longlong)uVar19) goto LAB_140009e40;
  }
  local_520 = 0;
  StorPortQuerySystemTime(&local_520);
  if ((longlong)uVar16 < (longlong)uVar17) {
    if ((longlong)uVar19 < (longlong)uVar16) {
      if ((longlong)param_1[0x8c2] < (longlong)param_1[0x116]) {
        uVar20 = local_520 - param_1[0x116];
      }
      else {
        uVar20 = local_520 - param_1[0x8c2];
      }
    }
    else {
      uVar20 = local_520 - param_1[0x115];
    }
  }
  else if ((longlong)uVar19 < (longlong)uVar16) {
    uVar20 = local_520 - param_1[0x8c2];
  }
  if (((param_1[0x4a] >> 0x17 & 1) != 0) && (100000000 < uVar20)) {
    uVar12 = uVar12 & 0xff;
    if (param_2 != '\0') {
      uVar12 = 0;
    }
    local_530 = uVar12;
  }
  RecordExecutionHistory((longlong *)param_1,0x10050050);
  pcVar18 = "DPC queued or interrupted";
  if ((char)uVar12 == '\0') {
    pcVar18 = "DPC issue, skip reset HW";
  }
  local_4e8[0] = 0;
  if ((int)param_1[3] != 2) {
    StorPortQuerySystemTime(local_4e8);
    uVar16 = param_1[0x8bc];
    uVar17 = param_1[0x4a];
    uVar12 = *(uint *)((longlong)param_1 + 0xb4);
    uVar19 = local_540[0x8ba];
    param_1[0x8be] = local_4e8[0];
    local_518 = (ulonglong)(uint)param_1[0x8bd];
    local_4f8 = param_1[0x49];
    uVar14 = *(undefined4 *)((longlong)param_1 + 0x45e4);
    uVar1 = *(undefined4 *)((longlong)param_1 + 0x45d4);
    uVar2 = *(undefined4 *)((longlong)local_540 + 0x45dc);
    uVar6 = local_540[0x8bb];
    local_528 = *local_540;
    memset(&local_338,0,0x180);
    uVar11 = 0;
    local_338 = 1;
    local_334 = 1;
    pcVar8 = pcVar18;
    do {
      if (*pcVar8 == '\0') goto LAB_140009acb;
      if (pcVar8[1] == '\0') {
        uVar11 = uVar11 + 1;
LAB_140009ac1:
        if (uVar11 < 0x20) goto LAB_140009acb;
        break;
      }
      if (pcVar8[2] == '\0') {
        uVar11 = uVar11 + 2;
        goto LAB_140009ac1;
      }
      if (pcVar8[3] == '\0') {
        uVar11 = uVar11 + 3;
        goto LAB_140009ac1;
      }
      pcVar8 = pcVar8 + 4;
      uVar11 = uVar11 + 4;
    } while (uVar11 < 0x20);
    uVar11 = 0x20;
LAB_140009acb:
    memcpy(local_330,pcVar18,(ulonglong)uVar11);
    lVar9 = 0;
    local_310 = 1;
    uVar11 = 0;
    local_30c = 1;
    do {
      if ("PortReset|PortErrorRecovery"[lVar9] == '\0') goto LAB_140009b4f;
      if ("PortReset|PortErrorRecovery"[lVar9 + 1] == '\0') {
        uVar11 = uVar11 + 1;
LAB_140009b3c:
        if (0x1f < uVar11) {
          uVar11 = 0x20;
        }
        goto LAB_140009b4f;
      }
      if ("PortReset|PortErrorRecovery"[lVar9 + 2] == '\0') {
        uVar11 = uVar11 + 2;
        goto LAB_140009b3c;
      }
      if ("PortReset|PortErrorRecovery"[lVar9 + 3] == '\0') {
        uVar11 = uVar11 + 3;
        goto LAB_140009b3c;
      }
      uVar11 = uVar11 + 4;
      lVar9 = lVar9 + 4;
    } while (uVar11 < 0x20);
    uVar11 = 0x20;
LAB_140009b4f:
    memcpy(local_2f8,"PortReset|PortErrorRecovery",(ulonglong)uVar11);
    uVar11 = 0;
    lVar9 = 0;
    do {
      if ("StartFail|NonQErrorRecovery"[lVar9] == '\0') goto LAB_140009bae;
      if ("StartFail|NonQErrorRecovery"[lVar9 + 1] == '\0') {
        uVar11 = uVar11 + 1;
LAB_140009ba7:
        if (uVar11 < 0x20) goto LAB_140009bae;
        break;
      }
      if ("StartFail|NonQErrorRecovery"[lVar9 + 2] == '\0') {
        uVar11 = uVar11 + 2;
        goto LAB_140009ba7;
      }
      if ("StartFail|NonQErrorRecovery"[lVar9 + 3] == '\0') {
        uVar11 = uVar11 + 3;
        goto LAB_140009ba7;
      }
      uVar11 = uVar11 + 4;
      lVar9 = lVar9 + 4;
    } while (uVar11 < 0x20);
    uVar11 = 0x20;
LAB_140009bae:
    local_2d8 = CONCAT44((int)uVar19,(int)uVar6);
    memcpy(local_2d0,"StartFail|NonQErrorRecovery",(ulonglong)uVar11);
    uVar11 = 0;
    lVar9 = 0;
    do {
      if ("NCQError|NCQErrorComplete"[lVar9] == '\0') goto LAB_140009c0c;
      if ("NCQError|NCQErrorComplete"[lVar9 + 1] == '\0') {
        uVar11 = uVar11 + 1;
LAB_140009c05:
        if (uVar11 < 0x20) goto LAB_140009c0c;
        break;
      }
      if ("NCQError|NCQErrorComplete"[lVar9 + 2] == '\0') {
        uVar11 = uVar11 + 2;
        goto LAB_140009c05;
      }
      if ("NCQError|NCQErrorComplete"[lVar9 + 3] == '\0') {
        uVar11 = uVar11 + 3;
        goto LAB_140009c05;
      }
      uVar11 = uVar11 + 4;
      lVar9 = lVar9 + 4;
    } while (uVar11 < 0x20);
    uVar11 = 0x20;
LAB_140009c0c:
    local_2b0 = CONCAT44(uVar1,uVar2);
    memcpy(local_2a8,"NCQError|NCQErrorComplete",(ulonglong)uVar11);
    uVar11 = 0;
    lVar9 = 0;
    do {
      if ("PortDriverResetCount"[lVar9] == '\0') goto LAB_140009c6c;
      if ("PortDriverResetCount"[lVar9 + 1] == '\0') {
        uVar11 = uVar11 + 1;
LAB_140009c65:
        if (uVar11 < 0x20) goto LAB_140009c6c;
        break;
      }
      if ("PortDriverResetCount"[lVar9 + 2] == '\0') {
        uVar11 = uVar11 + 2;
        goto LAB_140009c65;
      }
      if ("PortDriverResetCount"[lVar9 + 3] == '\0') {
        uVar11 = uVar11 + 3;
        goto LAB_140009c65;
      }
      uVar11 = uVar11 + 4;
      lVar9 = lVar9 + 4;
    } while (uVar11 < 0x20);
    uVar11 = 0x20;
LAB_140009c6c:
    local_288 = CONCAT44((int)uVar16,uVar14);
    memcpy(local_280,"PortDriverResetCount",(ulonglong)uVar11);
    uVar11 = 0;
    lVar9 = 0;
    do {
      if ("StateFlags"[lVar9] == '\0') goto LAB_140009ccc;
      if ("StateFlags"[lVar9 + 1] == '\0') {
        uVar11 = uVar11 + 1;
LAB_140009cc5:
        if (uVar11 < 0x20) goto LAB_140009ccc;
        break;
      }
      if ("StateFlags"[lVar9 + 2] == '\0') {
        uVar11 = uVar11 + 2;
        goto LAB_140009cc5;
      }
      if ("StateFlags"[lVar9 + 3] == '\0') {
        uVar11 = uVar11 + 3;
        goto LAB_140009cc5;
      }
      uVar11 = uVar11 + 4;
      lVar9 = lVar9 + 4;
    } while (uVar11 < 0x20);
    uVar11 = 0x20;
LAB_140009ccc:
    local_260 = (ulonglong)uVar12;
    memcpy(local_258,"StateFlags",(ulonglong)uVar11);
    uVar12 = 0;
    lVar9 = 0;
    do {
      if ("StartState"[lVar9] == '\0') goto LAB_140009d2c;
      if ("StartState"[lVar9 + 1] == '\0') {
        uVar12 = uVar12 + 1;
LAB_140009d25:
        if (uVar12 < 0x20) goto LAB_140009d2c;
        break;
      }
      if ("StartState"[lVar9 + 2] == '\0') {
        uVar12 = uVar12 + 2;
        goto LAB_140009d25;
      }
      if ("StartState"[lVar9 + 3] == '\0') {
        uVar12 = uVar12 + 3;
        goto LAB_140009d25;
      }
      uVar12 = uVar12 + 4;
      lVar9 = lVar9 + 4;
    } while (uVar12 < 0x20);
    uVar12 = 0x20;
LAB_140009d2c:
    local_238 = uVar17;
    memcpy(local_230,"StartState",(ulonglong)uVar12);
    local_210 = local_4f8;
    uVar12 = 0;
    lVar9 = 0;
    do {
      if ("TotalCountSurpriseRemove"[lVar9] == '\0') goto LAB_140009d8f;
      if ("TotalCountSurpriseRemove"[lVar9 + 1] == '\0') {
        uVar12 = uVar12 + 1;
LAB_140009d88:
        if (uVar12 < 0x20) goto LAB_140009d8f;
        break;
      }
      if ("TotalCountSurpriseRemove"[lVar9 + 2] == '\0') {
        uVar12 = uVar12 + 2;
        goto LAB_140009d88;
      }
      if ("TotalCountSurpriseRemove"[lVar9 + 3] == '\0') {
        uVar12 = uVar12 + 3;
        goto LAB_140009d88;
      }
      uVar12 = uVar12 + 4;
      lVar9 = lVar9 + 4;
    } while (uVar12 < 0x20);
    uVar12 = 0x20;
LAB_140009d8f:
    memcpy(local_208,"TotalCountSurpriseRemove",(ulonglong)uVar12);
    local_1e8 = local_518;
    uVar12 = 0;
    lVar9 = 0;
    do {
      if ("Duration(in 100ns)"[lVar9] == '\0') goto LAB_140009df2;
      if ("Duration(in 100ns)"[lVar9 + 1] == '\0') {
        uVar12 = uVar12 + 1;
LAB_140009deb:
        if (uVar12 < 0x20) goto LAB_140009df2;
        break;
      }
      if ("Duration(in 100ns)"[lVar9 + 2] == '\0') {
        uVar12 = uVar12 + 2;
        goto LAB_140009deb;
      }
      if ("Duration(in 100ns)"[lVar9 + 3] == '\0') {
        uVar12 = uVar12 + 3;
        goto LAB_140009deb;
      }
      uVar12 = uVar12 + 4;
      lVar9 = lVar9 + 4;
    } while (uVar12 < 0x20);
    uVar12 = 0x20;
LAB_140009df2:
    memcpy(local_1e0,"Duration(in 100ns)",(ulonglong)uVar12);
    param_1 = local_540;
    local_1c0 = uVar20;
    StorPortExtendedFunction(0x4f,local_528,local_540 + 1,&local_338);
    uVar19 = local_500;
    uVar17 = local_538;
  }
LAB_140009e40:
  uVar16 = local_508;
  cVar21 = local_548;
  if (local_548 != '\0') {
    if (((longlong)local_508 < (longlong)uVar17) || ((longlong)uVar19 < (longlong)local_508)) {
      cVar13 = '\x01';
    }
    else {
      cVar13 = '\0';
    }
    AhciPortCheckIOStatusAndConfigureFastFail(param_1,cVar13);
  }
  if (((longlong)uVar16 < (longlong)uVar17) || ((longlong)uVar19 < (longlong)uVar16)) {
    cVar13 = '\x01';
  }
  else {
    cVar13 = '\0';
  }
  AhciPortLogDeviceReset((longlong *)param_1,cVar13);
  if ((char)local_530 != '\0') {
    P_NotRunning((longlong *)param_1,param_1[0x129]);
    AhciCOMRESET((longlong *)param_1,param_1[0x129]);
  }
  if ((param_1[0x4a] >> 0x12 & 1) != 0) {
    param_1[0x4a] = param_1[0x4a] & 0xfffffffffffbfffb;
  }
  if (cVar21 != '\0') {
    if ((param_1[0x4a] & 4) != 0) {
      if (*(int *)((longlong)param_1 + 0x2dc) == 0) {
        param_1[0x4a] = param_1[0x4a] & 0xfffffffffffffffb;
        RecordExecutionHistory((longlong *)param_1,0x10010050);
        local_510 = 0;
        if ((int)param_1[3] != 2) {
          StorPortQuerySystemTime(&local_510);
          uVar19 = param_1[0x8bd];
          uVar17 = param_1[0x49];
          uVar16 = param_1[0x4a];
          uVar12 = *(uint *)((longlong)param_1 + 0xb4);
          uVar14 = *(undefined4 *)((longlong)local_540 + 0x45d4);
          uVar20 = local_540[0x8ba];
          param_1[0x8be] = local_510;
          uVar1 = *(undefined4 *)((longlong)local_540 + 0x45e4);
          uVar6 = param_1[0x8bc];
          uVar2 = *(undefined4 *)((longlong)local_540 + 0x45dc);
          uVar7 = local_540[0x8bb];
          local_528 = *local_540;
          memset(&local_1b8,0,0x180);
          lVar9 = 0;
          local_1b8 = 1;
          uVar11 = 0;
          local_1b4 = 1;
          do {
            if ("Unpausing queue"[lVar9] == '\0') goto LAB_14000a00f;
            if ("Unpausing queue"[lVar9 + 1] == '\0') {
              uVar11 = uVar11 + 1;
LAB_14000a005:
              if (uVar11 < 0x20) goto LAB_14000a00f;
              break;
            }
            if ("Unpausing queue"[lVar9 + 2] == '\0') {
              uVar11 = uVar11 + 2;
              goto LAB_14000a005;
            }
            if ("Unpausing queue"[lVar9 + 3] == '\0') {
              uVar11 = uVar11 + 3;
              goto LAB_14000a005;
            }
            uVar11 = uVar11 + 4;
            lVar9 = lVar9 + 4;
          } while (uVar11 < 0x20);
          uVar11 = 0x20;
LAB_14000a00f:
          memcpy(local_1b0,"Unpausing queue",(ulonglong)uVar11);
          lVar9 = 0;
          local_190 = 1;
          uVar11 = 0;
          local_18c = 1;
          do {
            if ("PortReset|PortErrorRecovery"[lVar9] == '\0') goto LAB_14000a07f;
            if ("PortReset|PortErrorRecovery"[lVar9 + 1] == '\0') {
              uVar11 = uVar11 + 1;
LAB_14000a075:
              if (uVar11 < 0x20) goto LAB_14000a07f;
              break;
            }
            if ("PortReset|PortErrorRecovery"[lVar9 + 2] == '\0') {
              uVar11 = uVar11 + 2;
              goto LAB_14000a075;
            }
            if ("PortReset|PortErrorRecovery"[lVar9 + 3] == '\0') {
              uVar11 = uVar11 + 3;
              goto LAB_14000a075;
            }
            uVar11 = uVar11 + 4;
            lVar9 = lVar9 + 4;
          } while (uVar11 < 0x20);
          uVar11 = 0x20;
LAB_14000a07f:
          memcpy(local_178,"PortReset|PortErrorRecovery",(ulonglong)uVar11);
          lVar9 = 0;
          uVar11 = 0;
          do {
            if ("StartFail|NonQErrorRecovery"[lVar9] == '\0') goto LAB_14000a0ef;
            if ("StartFail|NonQErrorRecovery"[lVar9 + 1] == '\0') {
              uVar11 = uVar11 + 1;
LAB_14000a0dc:
              if (0x1f < uVar11) {
                uVar11 = 0x20;
              }
              goto LAB_14000a0ef;
            }
            if ("StartFail|NonQErrorRecovery"[lVar9 + 2] == '\0') {
              uVar11 = uVar11 + 2;
              goto LAB_14000a0dc;
            }
            if ("StartFail|NonQErrorRecovery"[lVar9 + 3] == '\0') {
              uVar11 = uVar11 + 3;
              goto LAB_14000a0dc;
            }
            uVar11 = uVar11 + 4;
            lVar9 = lVar9 + 4;
          } while (uVar11 < 0x20);
          uVar11 = 0x20;
LAB_14000a0ef:
          local_158 = CONCAT44((int)uVar20,(int)uVar7);
          memcpy(local_150,"StartFail|NonQErrorRecovery",(ulonglong)uVar11);
          uVar11 = 0;
          lVar9 = 0;
          do {
            if ("NCQError|NCQErrorComplete"[lVar9] == '\0') goto LAB_14000a14e;
            if ("NCQError|NCQErrorComplete"[lVar9 + 1] == '\0') {
              uVar11 = uVar11 + 1;
LAB_14000a147:
              if (uVar11 < 0x20) goto LAB_14000a14e;
              break;
            }
            if ("NCQError|NCQErrorComplete"[lVar9 + 2] == '\0') {
              uVar11 = uVar11 + 2;
              goto LAB_14000a147;
            }
            if ("NCQError|NCQErrorComplete"[lVar9 + 3] == '\0') {
              uVar11 = uVar11 + 3;
              goto LAB_14000a147;
            }
            uVar11 = uVar11 + 4;
            lVar9 = lVar9 + 4;
          } while (uVar11 < 0x20);
          uVar11 = 0x20;
LAB_14000a14e:
          local_130 = CONCAT44(uVar14,uVar2);
          memcpy(local_128,"NCQError|NCQErrorComplete",(ulonglong)uVar11);
          uVar11 = 0;
          lVar9 = 0;
          do {
            if ("PortDriverResetCount"[lVar9] == '\0') goto LAB_14000a1ac;
            if ("PortDriverResetCount"[lVar9 + 1] == '\0') {
              uVar11 = uVar11 + 1;
LAB_14000a1a5:
              if (uVar11 < 0x20) goto LAB_14000a1ac;
              break;
            }
            if ("PortDriverResetCount"[lVar9 + 2] == '\0') {
              uVar11 = uVar11 + 2;
              goto LAB_14000a1a5;
            }
            if ("PortDriverResetCount"[lVar9 + 3] == '\0') {
              uVar11 = uVar11 + 3;
              goto LAB_14000a1a5;
            }
            uVar11 = uVar11 + 4;
            lVar9 = lVar9 + 4;
          } while (uVar11 < 0x20);
          uVar11 = 0x20;
LAB_14000a1ac:
          local_108 = CONCAT44((int)uVar6,uVar1);
          memcpy(local_100,"PortDriverResetCount",(ulonglong)uVar11);
          uVar11 = 0;
          lVar9 = 0;
          do {
            if ("StateFlags"[lVar9] == '\0') goto LAB_14000a20c;
            if ("StateFlags"[lVar9 + 1] == '\0') {
              uVar11 = uVar11 + 1;
LAB_14000a205:
              if (uVar11 < 0x20) goto LAB_14000a20c;
              break;
            }
            if ("StateFlags"[lVar9 + 2] == '\0') {
              uVar11 = uVar11 + 2;
              goto LAB_14000a205;
            }
            if ("StateFlags"[lVar9 + 3] == '\0') {
              uVar11 = uVar11 + 3;
              goto LAB_14000a205;
            }
            uVar11 = uVar11 + 4;
            lVar9 = lVar9 + 4;
          } while (uVar11 < 0x20);
          uVar11 = 0x20;
LAB_14000a20c:
          local_e0 = (ulonglong)uVar12;
          memcpy(local_d8,"StateFlags",(ulonglong)uVar11);
          uVar12 = 0;
          lVar9 = 0;
          do {
            if ("StartState"[lVar9] == '\0') goto LAB_14000a26c;
            if ("StartState"[lVar9 + 1] == '\0') {
              uVar12 = uVar12 + 1;
LAB_14000a265:
              if (uVar12 < 0x20) goto LAB_14000a26c;
              break;
            }
            if ("StartState"[lVar9 + 2] == '\0') {
              uVar12 = uVar12 + 2;
              goto LAB_14000a265;
            }
            if ("StartState"[lVar9 + 3] == '\0') {
              uVar12 = uVar12 + 3;
              goto LAB_14000a265;
            }
            uVar12 = uVar12 + 4;
            lVar9 = lVar9 + 4;
          } while (uVar12 < 0x20);
          uVar12 = 0x20;
LAB_14000a26c:
          local_b8 = uVar16;
          memcpy(local_b0,"StartState",(ulonglong)uVar12);
          uVar12 = 0;
          lVar9 = 0;
          do {
            if ("TotalCountSurpriseRemove"[lVar9] == '\0') goto LAB_14000a2cc;
            if ("TotalCountSurpriseRemove"[lVar9 + 1] == '\0') {
              uVar12 = uVar12 + 1;
LAB_14000a2c5:
              if (uVar12 < 0x20) goto LAB_14000a2cc;
              break;
            }
            if ("TotalCountSurpriseRemove"[lVar9 + 2] == '\0') {
              uVar12 = uVar12 + 2;
              goto LAB_14000a2c5;
            }
            if ("TotalCountSurpriseRemove"[lVar9 + 3] == '\0') {
              uVar12 = uVar12 + 3;
              goto LAB_14000a2c5;
            }
            uVar12 = uVar12 + 4;
            lVar9 = lVar9 + 4;
          } while (uVar12 < 0x20);
          uVar12 = 0x20;
LAB_14000a2cc:
          local_90 = uVar17;
          memcpy(local_88,"TotalCountSurpriseRemove",(ulonglong)uVar12);
          param_1 = local_540;
          local_68 = (ulonglong)(uint)uVar19;
          StorPortExtendedFunction(0x4f,local_528,local_540 + 1,&local_1b8);
          uVar16 = local_508;
          uVar17 = local_538;
          cVar21 = local_548;
        }
      }
    }
  }
  uVar19 = local_500;
  if ((param_1[0x4a] & 8) != 0) {
    *(int *)((longlong)param_1 + 0xa54) = (int)param_1[0x14a];
    *(undefined1 *)((longlong)param_1 + 0xa42) = 0;
  }
  if ((((cVar21 != '\0') && ((param_1[0x4a] & 8) != 0)) &&
      (*(int *)((longlong)param_1 + 0x2ec) == 0)) && ((param_1[0x5b] & 1) == 0)) {
    if (((longlong)uVar16 < (longlong)uVar17) || ((longlong)local_500 < (longlong)uVar16)) {
      RecordExecutionHistory((longlong *)param_1,0x10060050);
    }
    else {
      RecordExecutionHistory((longlong *)param_1,0x10020050);
      AhciPortMarkDeviceFailed((longlong *)param_1,4,2);
    }
    uVar20 = *param_1;
    if ((*(uint *)(uVar20 + 0x38) & 0x40000) != 0) {
      LOCK();
      *(uint *)(param_1 + 0x4a) = (uint)param_1[0x4a] & 0xfffffff7;
      UNLOCK();
      RecordExecutionHistory((longlong *)param_1,0x10070050);
      uVar20 = *param_1;
    }
    if (((longlong)uVar16 < (longlong)uVar17) ||
       (pcVar18 = "ReservedSlotInUse stuck", (longlong)uVar19 < (longlong)uVar16)) {
      pcVar18 = "ReservedSlotInUse outstanding";
    }
    local_518 = (ulonglong)(*(uint *)(uVar20 + 0x38) >> 0x12 & 1);
    local_538 = 0;
    if ((int)param_1[3] != 2) {
      StorPortQuerySystemTime(&local_538);
      uVar19 = param_1[0x8bc];
      uVar17 = param_1[0x49];
      uVar16 = param_1[0x4a];
      uVar12 = *(uint *)((longlong)param_1 + 0xb4);
      uVar20 = local_540[0x8ba];
      param_1[0x8be] = local_538;
      local_528 = (ulonglong)(uint)param_1[0x8bd];
      uVar14 = *(undefined4 *)((longlong)param_1 + 0x45e4);
      uVar1 = *(undefined4 *)((longlong)param_1 + 0x45d4);
      uVar2 = *(undefined4 *)((longlong)local_540 + 0x45dc);
      uVar6 = local_540[0x8bb];
      local_4f8 = *local_540;
      memset(&local_4b8,0,0x180);
      uVar11 = 0;
      local_4b8 = 1;
      local_4b4 = 1;
      pcVar8 = pcVar18;
      do {
        if (*pcVar8 == '\0') goto LAB_14000a4eb;
        if (pcVar8[1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000a4e1:
          if (uVar11 < 0x20) goto LAB_14000a4eb;
          break;
        }
        if (pcVar8[2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000a4e1;
        }
        if (pcVar8[3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000a4e1;
        }
        pcVar8 = pcVar8 + 4;
        uVar11 = uVar11 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000a4eb:
      memcpy(local_4b0,pcVar18,(ulonglong)uVar11);
      lVar9 = 0;
      uVar11 = 0;
      local_490 = 0x100000001;
      do {
        if ("PortReset|PortErrorRecovery"[lVar9] == '\0') goto LAB_14000a562;
        if ("PortReset|PortErrorRecovery"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000a54f:
          if (0x1f < uVar11) {
            uVar11 = 0x20;
          }
          goto LAB_14000a562;
        }
        if ("PortReset|PortErrorRecovery"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000a54f;
        }
        if ("PortReset|PortErrorRecovery"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000a54f;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000a562:
      memcpy(local_478,"PortReset|PortErrorRecovery",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("StartFail|NonQErrorRecovery"[lVar9] == '\0') goto LAB_14000a5bc;
        if ("StartFail|NonQErrorRecovery"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000a5b5:
          if (uVar11 < 0x20) goto LAB_14000a5bc;
          break;
        }
        if ("StartFail|NonQErrorRecovery"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000a5b5;
        }
        if ("StartFail|NonQErrorRecovery"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000a5b5;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000a5bc:
      local_458 = CONCAT44((int)uVar20,(int)uVar6);
      memcpy(local_450,"StartFail|NonQErrorRecovery",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("NCQError|NCQErrorComplete"[lVar9] == '\0') goto LAB_14000a614;
        if ("NCQError|NCQErrorComplete"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000a60d:
          if (uVar11 < 0x20) goto LAB_14000a614;
          break;
        }
        if ("NCQError|NCQErrorComplete"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000a60d;
        }
        if ("NCQError|NCQErrorComplete"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000a60d;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000a614:
      local_430 = CONCAT44(uVar1,uVar2);
      memcpy(local_428,"NCQError|NCQErrorComplete",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("PortDriverResetCount"[lVar9] == '\0') goto LAB_14000a670;
        if ("PortDriverResetCount"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000a669:
          if (uVar11 < 0x20) goto LAB_14000a670;
          break;
        }
        if ("PortDriverResetCount"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000a669;
        }
        if ("PortDriverResetCount"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000a669;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000a670:
      local_408 = CONCAT44((int)uVar19,uVar14);
      memcpy(local_400,"PortDriverResetCount",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("StateFlags"[lVar9] == '\0') goto LAB_14000a6cc;
        if ("StateFlags"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000a6c5:
          if (uVar11 < 0x20) goto LAB_14000a6cc;
          break;
        }
        if ("StateFlags"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000a6c5;
        }
        if ("StateFlags"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000a6c5;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000a6cc:
      local_3e0 = (ulonglong)uVar12;
      memcpy(local_3d8,"StateFlags",(ulonglong)uVar11);
      uVar12 = 0;
      lVar9 = 0;
      do {
        if ("StartState"[lVar9] == '\0') goto LAB_14000a72c;
        if ("StartState"[lVar9 + 1] == '\0') {
          uVar12 = uVar12 + 1;
LAB_14000a725:
          if (uVar12 < 0x20) goto LAB_14000a72c;
          break;
        }
        if ("StartState"[lVar9 + 2] == '\0') {
          uVar12 = uVar12 + 2;
          goto LAB_14000a725;
        }
        if ("StartState"[lVar9 + 3] == '\0') {
          uVar12 = uVar12 + 3;
          goto LAB_14000a725;
        }
        uVar12 = uVar12 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar12 < 0x20);
      uVar12 = 0x20;
LAB_14000a72c:
      local_3b8 = uVar16;
      memcpy(local_3b0,"StartState",(ulonglong)uVar12);
      uVar12 = 0;
      lVar9 = 0;
      do {
        if ("TotalCountSurpriseRemove"[lVar9] == '\0') goto LAB_14000a78c;
        if ("TotalCountSurpriseRemove"[lVar9 + 1] == '\0') {
          uVar12 = uVar12 + 1;
LAB_14000a785:
          if (uVar12 < 0x20) goto LAB_14000a78c;
          break;
        }
        if ("TotalCountSurpriseRemove"[lVar9 + 2] == '\0') {
          uVar12 = uVar12 + 2;
          goto LAB_14000a785;
        }
        if ("TotalCountSurpriseRemove"[lVar9 + 3] == '\0') {
          uVar12 = uVar12 + 3;
          goto LAB_14000a785;
        }
        uVar12 = uVar12 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar12 < 0x20);
      uVar12 = 0x20;
LAB_14000a78c:
      local_390 = uVar17;
      memcpy(local_388,"TotalCountSurpriseRemove",(ulonglong)uVar12);
      local_368 = local_528;
      uVar12 = 0;
      lVar9 = 0;
      do {
        if ("ForceClearReservedSlotInUse"[lVar9] == '\0') goto LAB_14000a7f0;
        if ("ForceClearReservedSlotInUse"[lVar9 + 1] == '\0') {
          uVar12 = uVar12 + 1;
LAB_14000a7e9:
          if (uVar12 < 0x20) goto LAB_14000a7f0;
          break;
        }
        if ("ForceClearReservedSlotInUse"[lVar9 + 2] == '\0') {
          uVar12 = uVar12 + 2;
          goto LAB_14000a7e9;
        }
        if ("ForceClearReservedSlotInUse"[lVar9 + 3] == '\0') {
          uVar12 = uVar12 + 3;
          goto LAB_14000a7e9;
        }
        uVar12 = uVar12 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar12 < 0x20);
      uVar12 = 0x20;
LAB_14000a7f0:
      memcpy(local_360,"ForceClearReservedSlotInUse",(ulonglong)uVar12);
      param_1 = local_540;
      local_340 = local_518;
      StorPortExtendedFunction(0x4f,local_4f8,local_540 + 1,&local_4b8);
    }
  }
  if (((((*(uint *)((longlong)param_1 + 0x2ec) & 1) != 0) &&
       ((ulonglong *)param_1[0x60] != (ulonglong *)0x0)) &&
      (param_1 + 0x12e == (ulonglong *)param_1[0x60])) &&
     ((param_1[0x139] != 0 &&
      ((pcVar3 = *(code **)(param_1[0x139] + 0x2968), pcVar3 == IssuePreservedSettingCommands ||
       (pcVar3 == IssueInitCommands)))))) {
    RecordExecutionHistory((longlong *)param_1,0x10030050);
    local_538 = 0;
    pcVar18 = "Init Command";
    if (pcVar3 != IssueInitCommands) {
      pcVar18 = "Preserved Setting Command";
    }
    if ((int)param_1[3] != 2) {
      StorPortQuerySystemTime(&local_538);
      uVar17 = param_1[0x49];
      uVar16 = param_1[0x4a];
      uVar12 = *(uint *)((longlong)param_1 + 0xb4);
      uVar14 = *(undefined4 *)((longlong)local_540 + 0x45d4);
      uVar19 = local_540[0x8ba];
      param_1[0x8be] = local_538;
      local_528 = (ulonglong)(uint)param_1[0x8bd];
      uVar20 = param_1[0x8bc];
      uVar1 = *(undefined4 *)((longlong)local_540 + 0x45e4);
      uVar2 = *(undefined4 *)((longlong)local_540 + 0x45dc);
      uVar6 = local_540[0x8bb];
      local_518 = *local_540;
      memset(&local_4b8,0,0x180);
      lVar9 = 0;
      local_4b8 = 1;
      uVar11 = 0;
      local_4b4 = 1;
      do {
        if ("Slot 0 command timeout"[lVar9] == '\0') goto LAB_14000a9b1;
        if ("Slot 0 command timeout"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000a9a7:
          if (uVar11 < 0x20) goto LAB_14000a9b1;
          break;
        }
        if ("Slot 0 command timeout"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000a9a7;
        }
        if ("Slot 0 command timeout"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000a9a7;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000a9b1:
      memcpy(local_4b0,"Slot 0 command timeout",(ulonglong)uVar11);
      lVar9 = 0;
      uVar11 = 0;
      local_490 = 0x100000001;
      do {
        if ("PortReset|PortErrorRecovery"[lVar9] == '\0') goto LAB_14000aa15;
        if ("PortReset|PortErrorRecovery"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000aa0b:
          if (uVar11 < 0x20) goto LAB_14000aa15;
          break;
        }
        if ("PortReset|PortErrorRecovery"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000aa0b;
        }
        if ("PortReset|PortErrorRecovery"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000aa0b;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000aa15:
      memcpy(local_478,"PortReset|PortErrorRecovery",(ulonglong)uVar11);
      lVar9 = 0;
      uVar11 = 0;
      do {
        if ("StartFail|NonQErrorRecovery"[lVar9] == '\0') goto LAB_14000aa7f;
        if ("StartFail|NonQErrorRecovery"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000aa6c:
          if (0x1f < uVar11) {
            uVar11 = 0x20;
          }
          goto LAB_14000aa7f;
        }
        if ("StartFail|NonQErrorRecovery"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000aa6c;
        }
        if ("StartFail|NonQErrorRecovery"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000aa6c;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000aa7f:
      _Size = 0x20;
      local_458 = CONCAT44((int)uVar19,(int)uVar6);
      memcpy(local_450,"StartFail|NonQErrorRecovery",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("NCQError|NCQErrorComplete"[lVar9] == '\0') goto LAB_14000aadc;
        if ("NCQError|NCQErrorComplete"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000aad5:
          if (uVar11 < 0x20) goto LAB_14000aadc;
          break;
        }
        if ("NCQError|NCQErrorComplete"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000aad5;
        }
        if ("NCQError|NCQErrorComplete"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000aad5;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000aadc:
      local_430 = CONCAT44(uVar14,uVar2);
      memcpy(local_428,"NCQError|NCQErrorComplete",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("PortDriverResetCount"[lVar9] == '\0') goto LAB_14000ab34;
        if ("PortDriverResetCount"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000ab2d:
          if (uVar11 < 0x20) goto LAB_14000ab34;
          break;
        }
        if ("PortDriverResetCount"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000ab2d;
        }
        if ("PortDriverResetCount"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000ab2d;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000ab34:
      local_408 = CONCAT44((int)uVar20,uVar1);
      memcpy(local_400,"PortDriverResetCount",(ulonglong)uVar11);
      uVar11 = 0;
      lVar9 = 0;
      do {
        if ("StateFlags"[lVar9] == '\0') goto LAB_14000ab93;
        if ("StateFlags"[lVar9 + 1] == '\0') {
          uVar11 = uVar11 + 1;
LAB_14000ab8c:
          if (uVar11 < 0x20) goto LAB_14000ab93;
          break;
        }
        if ("StateFlags"[lVar9 + 2] == '\0') {
          uVar11 = uVar11 + 2;
          goto LAB_14000ab8c;
        }
        if ("StateFlags"[lVar9 + 3] == '\0') {
          uVar11 = uVar11 + 3;
          goto LAB_14000ab8c;
        }
        uVar11 = uVar11 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar11 < 0x20);
      uVar11 = 0x20;
LAB_14000ab93:
      local_3e0 = (ulonglong)uVar12;
      memcpy(local_3d8,"StateFlags",(ulonglong)uVar11);
      uVar12 = 0;
      lVar9 = 0;
      do {
        if ("StartState"[lVar9] == '\0') goto LAB_14000abf2;
        if ("StartState"[lVar9 + 1] == '\0') {
          uVar12 = uVar12 + 1;
LAB_14000abeb:
          if (uVar12 < 0x20) goto LAB_14000abf2;
          break;
        }
        if ("StartState"[lVar9 + 2] == '\0') {
          uVar12 = uVar12 + 2;
          goto LAB_14000abeb;
        }
        if ("StartState"[lVar9 + 3] == '\0') {
          uVar12 = uVar12 + 3;
          goto LAB_14000abeb;
        }
        uVar12 = uVar12 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar12 < 0x20);
      uVar12 = 0x20;
LAB_14000abf2:
      local_3b8 = uVar16;
      memcpy(local_3b0,"StartState",(ulonglong)uVar12);
      uVar12 = 0;
      lVar9 = 0;
      do {
        if ("TotalCountSurpriseRemove"[lVar9] == '\0') goto LAB_14000ac51;
        if ("TotalCountSurpriseRemove"[lVar9 + 1] == '\0') {
          uVar12 = uVar12 + 1;
LAB_14000ac4a:
          if (uVar12 < 0x20) goto LAB_14000ac51;
          break;
        }
        if ("TotalCountSurpriseRemove"[lVar9 + 2] == '\0') {
          uVar12 = uVar12 + 2;
          goto LAB_14000ac4a;
        }
        if ("TotalCountSurpriseRemove"[lVar9 + 3] == '\0') {
          uVar12 = uVar12 + 3;
          goto LAB_14000ac4a;
        }
        uVar12 = uVar12 + 4;
        lVar9 = lVar9 + 4;
      } while (uVar12 < 0x20);
      uVar12 = 0x20;
LAB_14000ac51:
      local_390 = uVar17;
      memcpy(local_388,"TotalCountSurpriseRemove",(ulonglong)uVar12);
      uVar12 = 0;
      local_368 = local_528;
      pcVar8 = pcVar18;
      do {
        if (*pcVar8 == '\0') {
LAB_14000aca8:
          _Size = (size_t)uVar12;
          break;
        }
        if (pcVar8[1] == '\0') {
          uVar12 = uVar12 + 1;
LAB_14000aca3:
          if (uVar12 < 0x20) goto LAB_14000aca8;
          break;
        }
        if (pcVar8[2] == '\0') {
          uVar12 = uVar12 + 2;
          goto LAB_14000aca3;
        }
        if (pcVar8[3] == '\0') {
          uVar12 = uVar12 + 3;
          goto LAB_14000aca3;
        }
        pcVar8 = pcVar8 + 4;
        uVar12 = uVar12 + 4;
      } while (uVar12 < 0x20);
      memcpy(local_360,pcVar18,_Size);
      param_1 = local_540;
      local_340 = 0;
      StorPortExtendedFunction(0x4f,local_518,local_540 + 1,&local_4b8);
    }
  }
  uVar12 = *(uint *)((longlong)param_1 + 0x2dc);
  *(uint *)(param_1 + 0x5c) = uVar12;
  *(uint *)((longlong)param_1 + 0x2cc) = *(uint *)((longlong)param_1 + 0x2cc) & ~uVar12;
  *(undefined4 *)((longlong)param_1 + 0x2dc) = 0;
  *(undefined8 *)((longlong)param_1 + 0x2e4) = 0;
  uVar11 = uVar12 - (uVar12 >> 1 & 0x55555555);
  *(undefined4 *)((longlong)param_1 + 0x2ec) = 0;
  uVar11 = (uVar11 >> 2 & 0x33333333) + (uVar11 & 0x33333333);
  uVar11 = ((uVar11 >> 4) + uVar11 & 0xf0f0f0f) * 0x1010101 >> 0x18;
  if (uVar11 != 0) {
    cVar21 = '\x0e';
    if (uVar11 == 1) {
      uVar11 = 0;
      cVar21 = '\x0e';
      do {
        if ((((uVar12 >> (uVar11 & 0x1f) & 1) != 0) &&
            (puVar4 = (ulonglong *)param_1[((ulonglong)uVar11 + 0x18) * 4],
            puVar4 != (ulonglong *)0x0)) &&
           ((puVar4 != param_1 + 0x12e && (puVar4 != param_1 + 0x13b)))) {
          cVar21 = '\x04';
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 <= (*(uint *)(*param_1 + 0x1a8) >> 8 & 0x1f));
    }
    AhciCompleteIssuedSRBs((longlong *)param_1,cVar21);
  }
  if (local_548 != '\0') {
    uVar17 = 0;
    do {
      if (param_1[(uVar17 + 0x18) * 4] != 0) {
        *(undefined1 *)(param_1[(uVar17 + 0x18) * 4] + 3) = 0xe;
        AhciCompleteJustSlottedRequest
                  ((longlong *)param_1,(longlong *)param_1[(uVar17 + 0x18) * 4],'\x01');
      }
      bVar15 = (char)uVar17 + 1;
      uVar17 = (ulonglong)bVar15;
    } while (bVar15 <= ((byte)((uint)*(undefined4 *)(*param_1 + 0x1a8) >> 8) & 0x1f));
  }
  if ((char)local_530 != '\0') {
    if ((param_1[0x4a] & 8) == 0) {
      RestorePreservedSettings((longlong *)param_1,1);
    }
    *(byte *)((longlong)param_1 + 0x24d) = *(byte *)((longlong)param_1 + 0x24d) | 3;
    local_4e8[1] = 3;
    local_4e8[2] = 0;
    local_4e8[3] = 0;
    local_4e8[4] = 0;
    *(undefined4 *)(param_1 + 0x49) = 0x11;
    *(undefined1 *)((longlong)param_1 + 0x24c) = 0;
    *(undefined2 *)((longlong)param_1 + 0x24e) = 0;
    P_Running(param_1,'\0');
  }
  uVar10 = RecordExecutionHistory((longlong *)param_1,0x10000050);
  return CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
}



===== AhciZeroMemory @ 14000aeb0 =====

void AhciZeroMemory(void *param_1,uint param_2)

{
  if (param_2 != 0) {
    memset(param_1,0,(ulonglong)param_2);
  }
  return;
}



===== AtaMapError @ 14000aed0 =====

undefined1 AtaMapError(longlong param_1,longlong param_2,char param_3)

{
  ulonglong *puVar1;
  int *piVar2;
  longlong lVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  byte bVar9;
  ulonglong uVar10;
  uint *puVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined1 uVar15;
  char cVar16;
  char cVar17;
  void *_Dst;
  byte local_res10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined2 local_48;
  
  cVar17 = *(char *)(param_2 + 2);
  puVar1 = (ulonglong *)(param_2 + 0x38);
  uVar13 = 0;
  local_48 = 0;
  local_res10 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (cVar17 == '(') {
    uVar14 = *(ulonglong *)(param_2 + 0x68);
  }
  else {
    uVar14 = *puVar1;
  }
  if ((uVar14 & 0x7f) != 0) {
    uVar14 = (uVar14 - ((uint)uVar14 & 0x7f)) + 0x80;
  }
  if (cVar17 == '(') {
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar12 = 0;
      if (*(uint *)puVar1 != 0) {
        puVar11 = (uint *)(param_2 + 0x78);
        do {
          uVar5 = *puVar11;
          if ((0x7f < uVar5) && (uVar6 = *(uint *)(param_2 + 0x10), uVar5 < uVar6)) {
            iVar7 = *(int *)((ulonglong)uVar5 + param_2);
            lVar3 = (ulonglong)uVar5 + param_2;
            uVar10 = (ulonglong)uVar5;
            if (iVar7 == 0x40) {
              uVar10 = uVar10 + 0x28;
            }
            else {
              if (iVar7 != 0x41) {
                if ((iVar7 != 0x42) || ((ulonglong)uVar6 < uVar10 + 0x28)) goto LAB_14000b005;
                local_res10 = *(byte *)(lVar3 + 9);
                _Dst = *(void **)(lVar3 + 0x18);
                goto LAB_14000afa5;
              }
              uVar10 = uVar10 + 0x38;
            }
            if (uVar10 <= uVar6) {
              local_res10 = *(byte *)(lVar3 + 9);
              _Dst = *(void **)(lVar3 + 0x10);
              goto LAB_14000afa5;
            }
          }
LAB_14000b005:
          uVar12 = uVar12 + 1;
          puVar11 = puVar11 + 1;
        } while (uVar12 < *(uint *)puVar1);
      }
      _Dst = (void *)0x0;
    }
    else {
LAB_14000b087:
      _Dst = (void *)0x0;
      local_res10 = 0;
    }
  }
  else {
    if (cVar17 != '\0') goto LAB_14000b087;
    _Dst = *(void **)(param_2 + 0x20);
    local_res10 = *(byte *)(param_2 + 0xb);
  }
LAB_14000afa5:
  if ((*(uint *)(uVar14 + 0x1104) & 0x40) != 0) goto LAB_14000afe9;
  if ((param_3 == '\x01') && ((*(uint *)(param_1 + 0x20) & 8) == 0)) {
    if (*(char *)(param_2 + 3) == '\x01') {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 8;
      goto LAB_14000afba;
    }
    if (*(char *)(param_2 + 3) != '\x04') goto LAB_14000afba;
    *(undefined1 *)(param_2 + 3) = 0x84;
    if (cVar17 == '(') {
      if (*(int *)(param_2 + 0x14) == 0) {
        uVar12 = 0;
        if (*(uint *)puVar1 != 0) {
          do {
            uVar5 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar12 * 4);
            if ((0x7f < uVar5) && (uVar5 < *(uint *)(param_2 + 0x10))) {
              uVar10 = (ulonglong)uVar5;
              iVar7 = *(int *)((ulonglong)uVar5 + param_2);
              if (iVar7 == 0x42) {
                uVar10 = uVar10 + 0x28;
              }
              else if (iVar7 == 0x40) {
                uVar10 = uVar10 + 0x28;
              }
              else {
                if (iVar7 != 0x41) goto LAB_140026cd7;
                uVar10 = uVar10 + 0x38;
              }
              if (uVar10 <= *(uint *)(param_2 + 0x10)) {
                *(undefined1 *)((int *)((ulonglong)uVar5 + param_2) + 2) = 2;
                break;
              }
            }
LAB_140026cd7:
            uVar12 = uVar12 + 1;
          } while (uVar12 < *(uint *)puVar1);
        }
      }
    }
    else {
      *(undefined1 *)(param_2 + 4) = 2;
    }
    cVar17 = -0x10;
    uVar15 = 5;
    local_58 = 0xb000000000500f0;
    uStack_50 = 0x2400000000;
  }
  else {
LAB_14000afba:
    local_58._0_1_ = '\0';
    local_58._2_1_ = 0;
    uVar15 = local_58._2_1_;
    cVar17 = (char)local_58;
  }
  if (*(char *)(param_2 + 3) != '\x04') {
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
    if (*(char *)(param_2 + 3) == '\x01') {
      LOCK();
      piVar2 = (int *)(param_1 + 0xbc);
      iVar7 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if (iVar7 != -1) {
        LOCK();
        *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 1;
        UNLOCK();
      }
    }
    goto LAB_14000afe9;
  }
  bVar9 = *(byte *)(param_1 + 0x20) & 1;
  if (-1 < cVar17) {
    bVar4 = *(byte *)(uVar14 + 0x1103);
    if ((char)bVar4 < '\0') {
      *(undefined1 *)(param_2 + 3) = 0xf;
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
      cVar16 = -0x10;
      local_58 = 0xb000000000400f0;
      uStack_50 = 0x30800000000;
    }
    else if ((bVar4 & 0x40) == 0) {
      if ((bVar4 & 0x20) != 0) {
        uStack_50 = 0x2800000000;
        cVar17 = -0x10;
        local_58 = 0xb000000000600f0;
LAB_140026e80:
        *(undefined1 *)(param_2 + 3) = 4;
        goto LAB_140026e84;
      }
      if ((bVar4 & 0x10) == 0) {
        if ((bVar4 & 8) != 0) {
          uStack_50 = 0x15a00000000;
          cVar17 = -0x10;
          local_58 = 0xb000000000600f0;
          goto LAB_140026e80;
        }
        if ((bVar4 & 4) == 0) {
          if ((bVar4 & 2) == 0) {
            if ((bVar4 & 1) == 0) {
              uVar10 = IsReadWriteCommand(param_2);
              if (((char)uVar10 == '\0') || ((*(byte *)(uVar14 + 0x1102) & 0x20) == 0))
              goto LAB_140026e80;
              *(undefined1 *)(param_2 + 3) = 4;
              *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + 1;
              cVar16 = -0x10;
              uVar8 = CONCAT53(local_58._3_5_,CONCAT12(uVar15,(undefined2)local_58));
              local_58 = CONCAT71((uint7)((ulonglong)uVar8 >> 8) & 0xfffffffffff4ff | 0x400,0xf0);
              local_58 = CONCAT17(0xb,(undefined7)local_58);
              uStack_50._0_6_ = CONCAT24(0x44,(undefined4)uStack_50);
            }
            else {
              cVar16 = -0x10;
              *(undefined1 *)(param_2 + 3) = 4;
              uStack_50 = 0;
              local_58._0_3_ = CONCAT12(bVar9 * '\x04' + '\x03',0xf0);
              local_58 = CONCAT53(0xb00000000,(undefined3)local_58);
              cVar17 = -0x10;
              if (bVar9 != 0) goto LAB_140026e84;
              *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
            }
          }
          else {
            *(undefined1 *)(param_2 + 3) = 4;
            *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + 1;
            cVar16 = -0x10;
            local_58 = 0xb000000000200f0;
            uStack_50 = 0x3a00000000;
          }
        }
        else {
          *(undefined1 *)(param_2 + 3) = 2;
          *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + 1;
          cVar16 = -0x10;
          local_58 = 0xb000000000b00f0;
          uStack_50 = 0;
        }
      }
      else {
        *(undefined1 *)(param_2 + 3) = 4;
        *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
        cVar16 = -0x10;
        local_58 = 0xb000000000500f0;
        uStack_50 = 0x2100000000;
      }
    }
    else {
      cVar16 = -0x10;
      *(undefined1 *)(param_2 + 3) = 4;
      uStack_50 = 0;
      local_58._0_3_ = CONCAT12(bVar9 * '\x04' + '\x03',0xf0);
      local_58 = CONCAT53(0xb00000000,(undefined3)local_58);
      cVar17 = -0x10;
      if (bVar9 == 0) {
        *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
      }
      else {
LAB_140026e84:
        cVar16 = cVar17;
        *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
      }
    }
    if (-1 < cVar16) goto LAB_14000afe9;
  }
  if (_Dst != (void *)0x0) {
    uVar12 = 0x12;
    if (local_res10 - 1 < 0x11) {
      uVar12 = (uint)local_res10;
    }
    memcpy(_Dst,&local_58,(ulonglong)uVar12);
    *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) | 0x80;
    if (*(char *)(param_2 + 2) == '(') {
      if ((*(int *)(param_2 + 0x14) == 0) && (*(uint *)puVar1 != 0)) {
        do {
          uVar12 = *(uint *)(param_2 + 0x78 + uVar13 * 4);
          if ((0x7f < uVar12) && (uVar12 < *(uint *)(param_2 + 0x10))) {
            uVar14 = (ulonglong)uVar12;
            iVar7 = *(int *)((ulonglong)uVar12 + param_2);
            if (iVar7 == 0x42) {
              uVar14 = uVar14 + 0x28;
            }
            else if (iVar7 == 0x40) {
              uVar14 = uVar14 + 0x28;
            }
            else {
              if (iVar7 != 0x41) goto LAB_140026f2d;
              uVar14 = uVar14 + 0x38;
            }
            if (uVar14 <= *(uint *)(param_2 + 0x10)) {
              *(undefined1 *)((int *)((ulonglong)uVar12 + param_2) + 2) = 2;
              break;
            }
          }
LAB_140026f2d:
          uVar12 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar12;
        } while (uVar12 < *(uint *)puVar1);
      }
    }
    else {
      *(undefined1 *)(param_2 + 4) = 2;
    }
  }
LAB_14000afe9:
  return *(undefined1 *)(param_2 + 3);
}



===== IsDataTransferNeeded @ 14000b110 =====

longlong IsDataTransferNeeded(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  
  if (*(char *)(param_1 + 2) == '(') {
    uVar1 = *(ulonglong *)(param_1 + 0x68);
  }
  else {
    uVar1 = *(ulonglong *)(param_1 + 0x38);
  }
  if ((uVar1 & 0x7f) != 0) {
    uVar1 = (uVar1 - ((uint)uVar1 & 0x7f)) + 0x80;
  }
  uVar2 = (uint7)(uVar1 >> 8);
  if (((*(uint *)(uVar1 + 0x1104) & 6) == 0) && (*(longlong *)(uVar1 + 0x1120) == 0)) {
    return (ulonglong)uVar2 << 8;
  }
  return CONCAT71(uVar2,1);
}



===== GetLbaFromCdb @ 14000b160 =====

ulonglong GetLbaFromCdb(longlong param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  byte bVar8;
  
  if (param_2 == 0x10) {
    bVar1 = *(byte *)(param_1 + 2);
    uVar5 = (ulonglong)*(byte *)(param_1 + 3);
    uVar6 = (ulonglong)*(byte *)(param_1 + 4);
    uVar7 = (ulonglong)*(byte *)(param_1 + 5);
    bVar8 = *(byte *)(param_1 + 6);
    bVar2 = *(byte *)(param_1 + 7);
    bVar4 = *(byte *)(param_1 + 8);
    bVar3 = *(byte *)(param_1 + 9);
  }
  else {
    bVar8 = *(byte *)(param_1 + 2);
    bVar1 = 0;
    bVar2 = *(byte *)(param_1 + 3);
    uVar5 = 0;
    bVar4 = *(byte *)(param_1 + 4);
    uVar6 = 0;
    bVar3 = *(byte *)(param_1 + 5);
    uVar7 = 0;
  }
  return ((((ulonglong)bVar8 | ((((ulonglong)bVar1 << 8 | uVar5) << 8 | uVar6) << 8 | uVar7) << 8)
           << 8 | (ulonglong)bVar2) << 8 | (ulonglong)bVar4) << 8 | (ulonglong)bVar3;
}



===== IsPortValid @ 14000b220 =====

ulonglong IsPortValid(longlong param_1,uint param_2)

{
  ulonglong in_RAX;
  
  if ((*(uint *)(param_1 + 0x184) < param_2) ||
     (in_RAX = (ulonglong)param_2, *(longlong *)(param_1 + 0x1b0 + in_RAX * 8) == 0)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((uint7)(uint3)(param_2 >> 8),1);
}



===== IsDeviceHybridInfoSupported @ 14000b250 =====

ulonglong IsDeviceHybridInfoSupported(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 600);
  if (((char)uVar1 < '\0') ||
     ((*(int *)(param_1 + 0x18) != 1 && (uVar1 = *(int *)(param_1 + 0x18) - 3, 2 < uVar1)))) {
    return (ulonglong)(uVar1 >> 8) << 8;
  }
  return (ulonglong)(byte)((ushort)*(undefined2 *)(*(longlong *)(param_1 + 0xc0) + 0x9c) >> 9) &
         0xffffffffffffff01;
}



===== IsMiniportInternalSrb @ 14000b290 =====

longlong IsMiniportInternalSrb(longlong param_1,longlong param_2)

{
  uint7 uVar1;
  
  uVar1 = (uint7)((ulonglong)(param_1 + 0x970) >> 8);
  if ((param_2 == param_1 + 0x970) || (param_2 == param_1 + 0x9d8)) {
    return CONCAT71(uVar1,1);
  }
  return (ulonglong)uVar1 << 8;
}



===== SelectDeviceGeometry @ 14000b2c0 =====

void SelectDeviceGeometry(undefined8 param_1,uint *param_2,longlong param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong local_res8;
  
  lVar1 = IsAtaDevice(param_2);
  if ((char)lVar1 != '\0') {
    if (param_2[6] == 2) {
      local_res8 = *(ulonglong *)(param_3 + 200);
    }
    else {
      local_res8 = (ulonglong)*(uint *)(param_3 + 0x78);
    }
    *(ulonglong *)(param_2 + 8) = local_res8;
    if ((*(ushort *)(param_3 + 0xd4) & 0x1000) != 0) {
      param_2[3] = *(int *)(param_3 + 0xea) * 2;
    }
    uVar2 = param_2[3];
    if (uVar2 < 0x200) {
      param_2[3] = 0x200;
      uVar2 = 0x200;
    }
    if ((*(ushort *)(param_3 + 0xd4) & 0x2000) != 0) {
      param_2[4] = (1 << ((byte)*(ushort *)(param_3 + 0xd4) & 0xf)) * uVar2;
    }
    if (param_2[4] < uVar2) {
      param_2[4] = uVar2;
    }
    if ((*(ushort *)(param_3 + 0x1a2) >> 0xe & 1) != 0) {
      param_2[5] = (*(ushort *)(param_3 + 0x1a2) & 0x3fff) * uVar2;
    }
  }
  return;
}



===== IsAhciDEVSLPSupported @ 14000b3b0 =====

ulonglong IsAhciDEVSLPSupported(ulonglong *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  bool bVar3;
  
  uVar1 = *param_1;
  if ((*(uint *)(uVar1 + 0x38) & 0x100) != 0) {
    uVar2 = (ulonglong)*(uint *)(param_1[0x129] + 0x44);
    uVar1 = IsAtaDevice((uint *)(param_1 + 3));
    if (((char)uVar1 != '\0') &&
       (bVar3 = (uVar2 & 2) != 0, uVar1 = CONCAT71((int7)(*param_1 >> 8),bVar3),
       bVar3 && (*(byte *)(*param_1 + 0x1ac) & 8) != 0)) {
      return (ulonglong)(*(byte *)(param_1[0x18] + 0x9d) & 1);
    }
  }
  return uVar1 & 0xffffffffffffff00;
}



===== IsAtaDevice @ 14000b420 =====

longlong IsAtaDevice(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 == 1) || (uVar1 = uVar1 - 3, uVar1 < 3)) {
    return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
  }
  return (ulonglong)(uint3)(uVar1 >> 8) << 8;
}



===== IsDeviceHybridInfoEnabled @ 14000b440 =====

uint IsDeviceHybridInfoEnabled(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 600);
  if (((char)uVar1 < '\0') ||
     (((uVar1 = *(uint *)(param_1 + 0x18), uVar1 != 1 && (uVar1 = uVar1 - 3, 2 < uVar1)) ||
      ((*(ushort *)(*(longlong *)(param_1 + 0xc0) + 0x9c) >> 9 & 1) == 0)))) {
    return uVar1 & 0xffffff00;
  }
  return (byte)((ushort)*(undefined2 *)(*(longlong *)(param_1 + 0xc0) + 0x9e) >> 9) & 0xffffff01;
}



===== CompareId @ 14000b490 =====

char CompareId(longlong param_1,uint param_2,char *param_3,uint param_4,uint *param_5)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  longlong lVar6;
  char cVar7;
  char *pcVar8;
  ulonglong uVar9;
  
  uVar9 = (ulonglong)param_2;
  if ((param_1 == 0) || (param_3 == (char *)0x0)) {
    return '\x01';
  }
  while ((*param_3 != '\0' || (cVar7 = '\0', param_3[1] != '\0'))) {
    pcVar8 = param_3;
    uVar5 = param_4;
    uVar2 = GetStringLength(param_3,param_4);
    uVar3 = (uint)uVar9;
    if (uVar2 <= uVar3) {
      uVar3 = GetStringLength(pcVar8,uVar5);
    }
    if (uVar3 == 0) {
      return '\0';
    }
    cVar7 = '\x01';
    lVar6 = param_1 - (longlong)param_3;
    uVar5 = 0;
    while( true ) {
      if (uVar3 <= uVar5) goto LAB_14000b54e;
      cVar1 = *param_3;
      if (cVar1 == '*') {
        param_3 = param_3 + 1;
        goto LAB_14000b54e;
      }
      if (((param_3[lVar6] == '\0') || (cVar1 == '\0')) ||
         ((param_3[lVar6] != cVar1 && (cVar1 != '?')))) break;
      param_3 = param_3 + 1;
      uVar5 = uVar5 + 1;
    }
    uVar5 = GetStringLength(pcVar8,param_4);
    param_3 = pcVar8 + (uVar5 + 1);
  }
LAB_14000b54e:
  if ((((param_5 != (uint *)0x0) && (cVar7 == '\x01')) && (*param_3 == ' ')) &&
     (uVar4 = StringToULONG(param_3 + 1,param_5), (char)uVar4 == '\0')) {
    cVar7 = '\0';
  }
  return cVar7;
}



===== PortSlumber @ 14000b5b0 =====

void PortSlumber(ulonglong *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  
  puVar3 = param_1;
  uVar2 = NoLpmSupport((longlong *)param_1);
  if ((((((char)uVar2 == '\0') && (uVar2 = IsLPMCapablePort(puVar3), (char)uVar2 != '\0')) &&
       ((*(uint *)(param_1[0x129] + 0x28) & 0xf00) < 0x600)) &&
      ((*(int *)(param_1[0x129] + 0x38) == 0 && (*(int *)(param_1[0x129] + 0x34) == 0)))) &&
     (*(uint *)(param_1[0x129] + 0x18) < 0x10000000)) {
    uVar4 = *(uint *)(param_1[0x129] + 0x18) & 0xfffffff | 0x10000000;
    *(uint *)(param_1[0x129] + 0x18) = uVar4;
    LOCK();
    UNLOCK();
    uVar5 = 0;
    uVar7 = 0;
    uVar1 = *(uint *)(param_1[0x129] + 0x28);
    bVar6 = 0;
    do {
      if ((uVar1 & 0xf00) == 0x100) break;
      if (bVar6 < 3) {
        uVar4 = uVar4 & 0xfffffff | 0x10000000;
        *(uint *)(param_1[0x129] + 0x18) = uVar4;
        LOCK();
        UNLOCK();
      }
      StorPortStallExecution(10);
      uVar7 = uVar7 + 10;
      uVar1 = *(uint *)(param_1[0x129] + 0x28);
      bVar6 = bVar6 + 1;
    } while (uVar7 < 100);
    if ((uVar1 & 0xf00) == 0x100) {
      uVar4 = uVar4 & 0xfffffff | 0x60000000;
      *(uint *)(param_1[0x129] + 0x18) = uVar4;
      LOCK();
      UNLOCK();
      uVar1 = *(uint *)(param_1[0x129] + 0x28);
      bVar6 = 0;
      do {
        if ((uVar1 & 0xf00) == 0x600) {
          return;
        }
        if (bVar6 < 3) {
          uVar4 = uVar4 & 0xfffffff | 0x60000000;
          *(uint *)(param_1[0x129] + 0x18) = uVar4;
          LOCK();
          UNLOCK();
        }
        StorPortStallExecution(10);
        uVar5 = uVar5 + 10;
        uVar1 = *(uint *)(param_1[0x129] + 0x28);
        bVar6 = bVar6 + 1;
      } while (uVar5 < 100);
    }
    else {
      puVar3 = param_1 + 0x53;
      if ((puVar3 != (ulonglong *)0x0) && ((int)*puVar3 != -1)) {
        *(int *)puVar3 = (int)*puVar3 + 1;
      }
    }
  }
  return;
}



===== SetAllowedLpmStates @ 14000b7a0 =====

byte SetAllowedLpmStates(ulonglong *param_1)

{
  uint uVar1;
  byte bVar2;
  ulonglong uVar3;
  byte bVar4;
  
  if (*(char *)((longlong)param_1 + 0x277) != '\0') {
    uVar3 = IsLPMCapablePort(param_1);
    if ((char)uVar3 != '\0') {
      if (((int)param_1[0x4f] == 0) &&
         ((*(uint *)(param_1[0x129] + 0x18) >> 0x17 & 1) == 0 ||
          (*(byte *)(*param_1 + 0x1ac) & 4) == 0)) {
        bVar2 = 2;
      }
      else {
        bVar2 = 0;
      }
      goto LAB_14000b7d8;
    }
  }
  bVar2 = 3;
LAB_14000b7d8:
  uVar1 = *(uint *)(*param_1 + 0x1a8);
  bVar4 = bVar2 | 2;
  if ((uVar1 >> 0xe & 1) != 0) {
    bVar4 = bVar2;
  }
  if ((uVar1 >> 0xd & 1) == 0) {
    bVar4 = 3;
  }
  if (((*(uint *)((longlong)param_1 + 0x254) & 6) != 0) &&
     ((*(uint *)(*param_1 + 0x1ac) & 0x20) != 0)) {
    bVar4 = bVar4 & 0xfd;
  }
  *(uint *)(param_1[0x129] + 0x2c) =
       (uint)bVar4 << 8 | *(uint *)(param_1[0x129] + 0x2c) & 0xfffff0ff;
  LOCK();
  UNLOCK();
  return bVar4;
}



===== AhciLpmSettingsModes @ 14000b890 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AhciLpmSettingsModes(ulonglong *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  ulonglong *puVar10;
  char cVar11;
  uint uVar12;
  char cVar13;
  ulonglong uVar14;
  undefined1 local_218 [32];
  byte local_1e8;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined1 local_1c0 [32];
  undefined8 local_1a0;
  undefined1 local_188 [32];
  ulonglong local_168;
  undefined1 local_160 [32];
  ulonglong local_140;
  undefined1 local_138 [32];
  ulonglong local_118;
  undefined1 local_110 [32];
  ulonglong local_f0;
  undefined1 local_e8 [32];
  ulonglong local_c8;
  undefined1 local_c0 [32];
  ulonglong local_a0;
  undefined1 local_98 [32];
  ulonglong local_78;
  undefined1 local_70 [32];
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_218;
  uVar14 = 0;
  RecordExecutionHistory((longlong *)param_1,0x47);
  puVar10 = param_1;
  uVar6 = NoLpmSupport((longlong *)param_1);
  if (((char)uVar6 != '\0') || (uVar6 = IsLPMCapablePort(puVar10), (char)uVar6 == '\0')) {
    return uVar6 & 0xffffffffffffff00;
  }
  if ((char)*(uint *)((longlong)param_1 + 0x254) < '\0') {
    param_2 = param_2 | 1;
  }
  if ((*(uint *)((longlong)param_1 + 0x254) >> 8 & 1) != 0) {
    param_2 = param_2 | 2;
  }
  *(char *)((longlong)param_1 + 0x277) = (char)param_2;
  if (param_2 == 0) {
    if (((*(uint *)(*param_1 + 0x1a8) & 0x4000000) != 0) &&
       ((*(uint *)(param_1[0x129] + 0x18) >> 0x1a & 1) != 0)) {
      *(uint *)(param_1[0x129] + 0x18) = *(uint *)(param_1[0x129] + 0x18) & 0xf3ffffff;
      LOCK();
      UNLOCK();
    }
    local_1e8 = SetAllowedLpmStates(param_1);
    bVar1 = *(byte *)(param_1[0x18] + 0x9c);
joined_r0x00014000bc34:
    if ((bVar1 & 8) == 0) goto LAB_14000b980;
    cVar13 = -0x70;
    cVar11 = '\x10';
  }
  else {
    local_1e8 = SetAllowedLpmStates(param_1);
    if (((((param_2 & 1) == 0) || (local_1e8 == 3)) ||
        ((*(uint *)(*param_1 + 0x1a8) & 0x4000000) == 0)) ||
       ((*(ushort *)(param_1[0x18] + 0x98) >> 9 & 1) == 0)) {
      if (((*(uint *)(*param_1 + 0x1a8) & 0x4000000) != 0) &&
         ((*(uint *)(param_1[0x129] + 0x18) >> 0x1a & 1) != 0)) {
        uVar5 = *(uint *)(param_1[0x129] + 0x18) & 0xf3ffffff;
        goto LAB_14000be56;
      }
    }
    else {
      uVar5 = *(uint *)(param_1[0x129] + 0x18) & 0xf7ffffff | 0x4000000;
LAB_14000be56:
      *(uint *)(param_1[0x129] + 0x18) = uVar5;
      LOCK();
      UNLOCK();
    }
    if (((param_2 & 2) == 0) || (local_1e8 == 3)) {
      bVar1 = *(byte *)(param_1[0x18] + 0x9c);
      goto joined_r0x00014000bc34;
    }
    if ((*(byte *)(param_1[0x18] + 0x9c) & 8) == 0) goto LAB_14000b980;
    cVar13 = '\x10';
    cVar11 = -0x70;
  }
  UpdateSetFeatureCommands((longlong)param_1,cVar11,cVar13,'\x03','\x03');
  RestorePreservedSettings((longlong *)param_1,0);
  uVar14 = 1;
LAB_14000b980:
  *(int *)((longlong)param_1 + 0x45ec) = *(int *)((longlong)param_1 + 0x45ec) + 1;
  uVar5 = *(uint *)(param_1[0x129] + 0x18);
  uVar6 = *param_1;
  bVar1 = *(byte *)((longlong)param_1 + 0x277);
  uVar4 = param_1[0x4a];
  uVar9 = *(uint *)((longlong)param_1 + 0x45ec);
  uVar2 = *(uint *)(uVar6 + 0x1ac);
  uVar3 = *(uint *)(uVar6 + 0x1a8);
  memset(&local_1c8,0,0x180);
  uVar12 = 0;
  local_1c8 = 1;
  uVar8 = 0;
  local_1c4 = 0xb;
  lVar7 = 0;
  do {
    if ("AhciLpmSettingsModes"[lVar7] == '\0') goto LAB_14000ba35;
    if ("AhciLpmSettingsModes"[lVar7 + 1] == '\0') {
      uVar8 = uVar8 + 1;
LAB_14000ba30:
      if (uVar8 < 0x20) goto LAB_14000ba35;
      break;
    }
    if ("AhciLpmSettingsModes"[lVar7 + 2] == '\0') {
      uVar8 = uVar8 + 2;
      goto LAB_14000ba30;
    }
    if ("AhciLpmSettingsModes"[lVar7 + 3] == '\0') {
      uVar8 = uVar8 + 3;
      goto LAB_14000ba30;
    }
    uVar8 = uVar8 + 4;
    lVar7 = lVar7 + 4;
  } while (uVar8 < 0x20);
  uVar8 = 0x20;
LAB_14000ba35:
  memcpy(local_1c0,"AhciLpmSettingsModes",(ulonglong)uVar8);
  uVar8 = 0;
  local_1a0 = 1;
  lVar7 = 0;
  do {
    if ("PowerSettingChangeCount"[lVar7] == '\0') goto LAB_14000ba95;
    if ("PowerSettingChangeCount"[lVar7 + 1] == '\0') {
      uVar8 = uVar8 + 1;
LAB_14000ba90:
      if (uVar8 < 0x20) goto LAB_14000ba95;
      break;
    }
    if ("PowerSettingChangeCount"[lVar7 + 2] == '\0') {
      uVar8 = uVar8 + 2;
      goto LAB_14000ba90;
    }
    if ("PowerSettingChangeCount"[lVar7 + 3] == '\0') {
      uVar8 = uVar8 + 3;
      goto LAB_14000ba90;
    }
    uVar8 = uVar8 + 4;
    lVar7 = lVar7 + 4;
  } while (uVar8 < 0x20);
  uVar8 = 0x20;
LAB_14000ba95:
  memcpy(local_188,"PowerSettingChangeCount",(ulonglong)uVar8);
  uVar8 = 0;
  lVar7 = 0;
  do {
    if ("StateFlags"[lVar7] == '\0') goto LAB_14000baff;
    if ("StateFlags"[lVar7 + 1] == '\0') {
      uVar8 = uVar8 + 1;
LAB_14000bafa:
      if (uVar8 < 0x20) goto LAB_14000baff;
      break;
    }
    if ("StateFlags"[lVar7 + 2] == '\0') {
      uVar8 = uVar8 + 2;
      goto LAB_14000bafa;
    }
    if ("StateFlags"[lVar7 + 3] == '\0') {
      uVar8 = uVar8 + 3;
      goto LAB_14000bafa;
    }
    uVar8 = uVar8 + 4;
    lVar7 = lVar7 + 4;
  } while (uVar8 < 0x20);
  uVar8 = 0x20;
LAB_14000baff:
  local_168 = (ulonglong)uVar9;
  memcpy(local_160,"StateFlags",(ulonglong)uVar8);
  uVar9 = 0;
  lVar7 = 0;
  do {
    if ("LastUserLpmPowerSetting"[lVar7] == '\0') goto LAB_14000bb6e;
    if ("LastUserLpmPowerSetting"[lVar7 + 1] == '\0') {
      uVar9 = uVar9 + 1;
LAB_14000bb69:
      if (uVar9 < 0x20) goto LAB_14000bb6e;
      break;
    }
    if ("LastUserLpmPowerSetting"[lVar7 + 2] == '\0') {
      uVar9 = uVar9 + 2;
      goto LAB_14000bb69;
    }
    if ("LastUserLpmPowerSetting"[lVar7 + 3] == '\0') {
      uVar9 = uVar9 + 3;
      goto LAB_14000bb69;
    }
    uVar9 = uVar9 + 4;
    lVar7 = lVar7 + 4;
  } while (uVar9 < 0x20);
  uVar9 = 0x20;
LAB_14000bb6e:
  local_140 = uVar4;
  memcpy(local_138,"LastUserLpmPowerSetting",(ulonglong)uVar9);
  uVar9 = 0;
  lVar7 = 0;
  do {
    if ((&s_CAP)[lVar7] == '\0') goto LAB_14000bc80;
    if ((&DAT_1400292c9)[lVar7] == '\0') {
      uVar9 = uVar9 + 1;
LAB_14000bc77:
      if (uVar9 < 0x20) goto LAB_14000bc80;
      break;
    }
    if ((&DAT_1400292ca)[lVar7] == '\0') {
      uVar9 = uVar9 + 2;
      goto LAB_14000bc77;
    }
    if ((&DAT_1400292cb)[lVar7] == '\0') {
      uVar9 = uVar9 + 3;
      goto LAB_14000bc77;
    }
    uVar9 = uVar9 + 4;
    lVar7 = lVar7 + 4;
  } while (uVar9 < 0x20);
  uVar9 = 0x20;
LAB_14000bc80:
  local_118 = (ulonglong)bVar1;
  memcpy(local_110,&s_CAP,(ulonglong)uVar9);
  lVar7 = 0;
  while( true ) {
    if ((&s_CAP2)[lVar7] == '\0') goto LAB_14000bcfc;
    if ((&DAT_14002930d)[lVar7] == '\0') break;
    if ((&DAT_14002930e)[lVar7] == '\0') {
      uVar12 = uVar12 + 2;
      goto LAB_14000bcf7;
    }
    if ((&DAT_14002930f)[lVar7] == '\0') {
      uVar12 = uVar12 + 3;
      goto LAB_14000bcf7;
    }
    uVar12 = uVar12 + 4;
    lVar7 = lVar7 + 4;
    if (0x1f < uVar12) {
LAB_14000bcd6:
      uVar12 = 0x20;
LAB_14000bcfc:
      local_f0 = (ulonglong)uVar3;
      memcpy(local_e8,&s_CAP2,(ulonglong)uVar12);
      local_c8 = (ulonglong)uVar2;
      uVar9 = GetStringLength("PxCMD",0x20);
      memcpy(local_c0,"PxCMD",(ulonglong)uVar9);
      local_a0 = (ulonglong)uVar5;
      uVar5 = GetStringLength("IPM",0x20);
      memcpy(local_98,"IPM",(ulonglong)uVar5);
      local_78 = (ulonglong)local_1e8;
      uVar5 = GetStringLength("LpmMode|SlumberInterval",0x20);
      memcpy(local_70,"LpmMode|SlumberInterval",(ulonglong)uVar5);
      local_50 = (ulonglong)param_2;
      StorPortExtendedFunction(0x4f,uVar6,param_1 + 1,&local_1c8);
      RecordExecutionHistory((longlong *)param_1,0x10000047);
      return uVar14;
    }
  }
  uVar12 = uVar12 + 1;
LAB_14000bcf7:
  if (uVar12 < 0x20) goto LAB_14000bcfc;
  goto LAB_14000bcd6;
}



===== IsLPMCapablePort @ 14000bf00 =====

ulonglong IsLPMCapablePort(ulonglong *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)(uint)param_1[0x4b];
  if (((uint)param_1[0x4b] & 2) == 0) {
    uVar2 = param_1[0x129];
    uVar1 = *(uint *)(uVar2 + 0x18);
    if ((((uVar1 >> 0x12 & 1) != 0) ||
        ((uVar2 = *param_1, (*(uint *)(uVar2 + 0x1a8) & 0x20) != 0 && ((uVar1 >> 0x15 & 1) != 0))))
       && ((uVar1 >> 0x13 & 1) == 0 || (*(uint *)(*param_1 + 0x1a8) & 0x10000000) == 0)) {
      return (ulonglong)((byte)(uVar1 >> 0x14) & 1);
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== NoLpmSupport @ 14000bf70 =====

ulonglong NoLpmSupport(longlong *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(param_1 + 0x4b);
  if ((*(uint *)(param_1 + 0x4b) & 0x20) == 0) {
    uVar1 = *(uint *)(*param_1 + 0x2c);
    uVar2 = (ulonglong)uVar1;
    if ((uVar1 & 1) == 0) {
      uVar1 = *(uint *)(*param_1 + 0x1a8);
      uVar2 = (ulonglong)uVar1;
      if (((uVar1 >> 0xd & 1) != 0) &&
         (((uVar1 >> 0x1a & 1) != 0 || (uVar2 = param_1[0x18], (*(byte *)(uVar2 + 0x9c) & 8) != 0)))
         ) {
        return uVar2 & 0xffffffffffffff00;
      }
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== GetStringLength @ 14000bfc0 =====

uint GetStringLength(char *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      if (*param_1 == '\0') {
        if (uVar1 < param_2) {
          return uVar1;
        }
        return param_2;
      }
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 1;
    } while (uVar1 < param_2);
  }
  return param_2;
}



===== UpdateSetFeatureCommands @ 14000bff0 =====

longlong UpdateSetFeatureCommands
                   (longlong param_1,char param_2,char param_3,char param_4,char param_5)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  ulonglong in_RAX;
  ulonglong uVar6;
  byte bVar7;
  ulonglong uVar8;
  
  uVar6 = in_RAX & 0xffffffffffffff00;
  do {
    if (0x1f < (byte)uVar6) {
      bVar7 = 0;
      uVar5 = *(uint *)(param_1 + 0xa50);
      if (*(uint *)(param_1 + 0xa50) != 0) {
        do {
          uVar4 = uVar5;
          bVar7 = bVar7 + 1;
          uVar5 = uVar4 >> 1;
        } while (uVar5 != 0);
        if (0x1f < bVar7) {
          return (ulonglong)(uVar4 >> 9) << 8;
        }
      }
      *(char *)(param_1 + 0xa59 + (ulonglong)bVar7 * 2) = param_5;
      *(char *)(param_1 + 0xa58 + (ulonglong)bVar7 * 2) = param_3;
      uVar5 = 1 << (bVar7 & 0x1f);
      uVar6 = (ulonglong)uVar5;
      *(uint *)(param_1 + 0xa50) = *(uint *)(param_1 + 0xa50) | uVar5;
LAB_14000c093:
      return CONCAT71((int7)(uVar6 >> 8),1);
    }
    uVar8 = uVar6 & 0xff;
    lVar1 = param_1 + uVar8 * 2;
    cVar3 = *(char *)(lVar1 + 0xa58);
    if ((cVar3 == param_2) && (lVar2 = param_1 + uVar8 * 2, *(char *)(lVar2 + 0xa59) == param_4)) {
      *(char *)(lVar1 + 0xa58) = param_3;
      *(char *)(lVar2 + 0xa59) = param_5;
      goto LAB_14000c093;
    }
    if ((cVar3 == param_3) && (*(char *)(param_1 + 0xa59 + uVar8 * 2) == param_5))
    goto LAB_14000c093;
    uVar6 = CONCAT71((int7)(uVar6 >> 8),(byte)uVar6 + 1);
  } while( true );
}



===== RestorePreservedSettings @ 14000c0b0 =====

void RestorePreservedSettings(longlong *param_1,byte param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  
  RecordExecutionHistory(param_1,0x41);
  *(int *)((longlong)param_1 + 0xa54) = (int)param_1[0x14a];
  LOCK();
  puVar1 = (uint *)(param_1 + 0x4a);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 | 8;
  UNLOCK();
  if ((uVar2 >> 3 & 1) != 0) {
    RecordExecutionHistory(param_1,0x10010041);
    return;
  }
  if (param_2 == 0) {
    LOCK();
    puVar1 = (uint *)(param_1 + 0x59);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 | 1;
    UNLOCK();
    if ((uVar2 & 1) != 0) {
      RecordExecutionHistory(param_1,0x10020041);
      return;
    }
    if (((ulonglong)param_1[0x4a] >> 0xd & 1) != 0) {
      iVar3 = StorPortExtendedFunction(0x31,*param_1,param_1 + 1,0,0,0);
      if ((iVar3 == 0) || (iVar3 == -0x3efffff4)) {
        param_1[0x4a] = param_1[0x4a] | 0x40;
      }
      if (iVar3 == -0x3efffff4) {
        RecordExecutionHistory(param_1,0x10030041);
        return;
      }
    }
    LOCK();
    puVar1 = (uint *)(param_1 + 0x59);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 & 0xfffffffe;
    UNLOCK();
    if ((uVar2 & 1) == 0) {
      RecordExecutionHistory(param_1,0x10040041);
      return;
    }
  }
  if ((*(uint *)((longlong)param_1 + 0x254) & 6) != 0) {
    *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) | 0x240;
  }
  IssuePreservedSettingCommands(param_1);
  uVar4 = param_1[0x135];
  if (uVar4 != 0) {
    if (*(char *)((longlong)param_1 + 0x972) == '(') {
      uVar4 = param_1[0x13b];
    }
    if ((uVar4 & 0x7f) != 0) {
      uVar4 = (uVar4 - ((uint)uVar4 & 0x7f)) + 0x80;
    }
    if (*(short *)(uVar4 + 0x1100) != 0) {
      AhciProcessIo(param_1,param_1 + 0x12e,param_2);
    }
  }
  return;
}



===== RemoveQueue @ 14000c250 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong RemoveQueue(undefined8 param_1,longlong *param_2)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  
  if (*param_2 == 0) {
    return 0;
  }
  StorPortQuerySystemTime(param_2 + 0x37);
  lVar2 = *param_2;
  if (*(char *)(lVar2 + 2) == '(') {
    lVar4 = *(longlong *)(lVar2 + 0x70);
  }
  else {
    lVar4 = *(longlong *)(lVar2 + 0x28);
  }
  uVar5 = 0;
  *param_2 = lVar4;
  if (*(char *)(lVar2 + 2) == '(') {
    *(undefined8 *)(lVar2 + 0x70) = 0;
  }
  else {
    *(undefined8 *)(lVar2 + 0x28) = 0;
  }
  puVar1 = (uint *)(param_2 + 2);
  lVar4 = *param_2;
  uVar3 = (int)param_2[2] - 1;
  *puVar1 = uVar3;
  if (lVar4 == 0) {
    param_2[1] = 0;
  }
  else {
    uVar5 = 1;
    if (*(char *)(lVar4 + 2) == '(') {
      lVar4 = *(longlong *)(lVar4 + 0x70);
    }
    else {
      lVar4 = *(longlong *)(lVar4 + 0x28);
    }
    while (lVar4 != 0) {
      uVar5 = uVar5 + 1;
      if (*(char *)(lVar4 + 2) == '(') {
        lVar4 = *(longlong *)(lVar4 + 0x70);
      }
      else {
        lVar4 = *(longlong *)(lVar4 + 0x28);
      }
    }
  }
  *(uint *)((longlong)param_2 + (ulonglong)*(uint *)(param_2 + 3) * 4 + 0x1c) = uVar3 | 0x9f000000;
  uVar3 = ((int)param_2[3] + 1U) % 100;
  *(uint *)(param_2 + 3) = uVar3;
  *(undefined4 *)((longlong)param_2 + (ulonglong)uVar3 * 4 + 0x1c) = 0xdeadc0de;
  if (*puVar1 != uVar5) {
    _DAT_00000240 = _DAT_00000240 + 1;
  }
  if (*(uint *)((longlong)param_2 + 0x14) < *puVar1) {
    *(uint *)((longlong)param_2 + 0x14) = *puVar1;
  }
  return lVar2;
}



===== AtapiCommonRequest @ 14000c340 =====

undefined8 AtapiCommonRequest(undefined8 param_1,longlong param_2,char *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar3 = *(ulonglong *)(param_2 + 0x68);
  }
  else {
    uVar3 = *(ulonglong *)(param_2 + 0x38);
  }
  if ((uVar3 & 0x7f) != 0) {
    uVar3 = (uVar3 - ((uint)uVar3 & 0x7f)) + 0x80;
  }
  if (*(char *)(param_2 + 2) == '(') {
    uVar1 = *(uint *)(param_2 + 0x18);
  }
  else {
    uVar1 = *(uint *)(param_2 + 0xc);
  }
  *(undefined2 *)(uVar3 + 0x1100) = 0x200;
  if ((uVar1 & 0x40) != 0) {
    *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 2;
  }
  if ((char)uVar1 < '\0') {
    *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 4;
  }
  uVar2 = 0;
  while( true ) {
    if ((&`DmaSafeAtapiCommand'::__l2::dmaCommandList)[uVar2] == '\0') {
      return 0;
    }
    if (*param_3 == (&`DmaSafeAtapiCommand'::__l2::dmaCommandList)[uVar2]) break;
    uVar2 = (ulonglong)((int)uVar2 + 1);
  }
  *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 0x10;
  return 0;
}



===== RequestGetDataTransferLength @ 14000c3d0 =====

int RequestGetDataTransferLength(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  
  if (*(char *)(param_1 + 2) == '(') {
    uVar2 = *(ulonglong *)(param_1 + 0x68);
  }
  else {
    uVar2 = *(ulonglong *)(param_1 + 0x38);
  }
  if ((uVar2 & 0x7f) != 0) {
    uVar2 = (uVar2 - ((uint)uVar2 & 0x7f)) + 0x80;
  }
  iVar1 = *(int *)(uVar2 + 0x1130);
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 2) != '(') {
      return *(int *)(param_1 + 0x10);
    }
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  return iVar1;
}



===== AddQueue @ 14000c420 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AddQueue(longlong param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  
  StorPortQuerySystemTime(param_2 + 0x36);
  lVar1 = param_2[1];
  iVar4 = 0;
  if (lVar1 == 0) {
    param_2[1] = param_3;
    *param_2 = param_3;
  }
  else {
    if (*(char *)(lVar1 + 2) == '(') {
      lVar3 = *(longlong *)(lVar1 + 0x70);
    }
    else {
      lVar3 = *(longlong *)(lVar1 + 0x28);
    }
    if (lVar3 == 0) {
      if (*(char *)(lVar1 + 2) == '(') {
        *(longlong *)(lVar1 + 0x70) = param_3;
      }
      else {
        *(longlong *)(lVar1 + 0x28) = param_3;
      }
    }
    else {
      param_1 = 0;
      _DAT_00000240 = _DAT_00000240 + 1;
    }
    param_2[1] = param_3;
    if (*(char *)(param_3 + 2) == '(') {
      lVar1 = *(longlong *)(param_3 + 0x70);
    }
    else {
      lVar1 = *(longlong *)(param_3 + 0x28);
    }
    if (lVar1 != 0) {
      if (param_3 == param_1 + 0x970) {
        _DAT_00000244 = _DAT_00000244 + 1;
      }
      else if (param_3 == param_1 + 0x9d8) {
        DAT_00000274 = DAT_00000274 + '\x01';
      }
      else {
        DAT_00000275 = DAT_00000275 + '\x01';
      }
    }
  }
  *(int *)(param_2 + 2) = (int)param_2[2] + 1;
  lVar1 = *param_2;
  if (lVar1 == 0) {
    _DAT_00000240 = _DAT_00000240 + 1;
  }
  else {
    iVar4 = 1;
    if (*(char *)(lVar1 + 2) == '(') {
      lVar1 = *(longlong *)(lVar1 + 0x70);
    }
    else {
      lVar1 = *(longlong *)(lVar1 + 0x28);
    }
    while (lVar1 != 0) {
      iVar4 = iVar4 + 1;
      if (*(char *)(lVar1 + 2) == '(') {
        lVar1 = *(longlong *)(lVar1 + 0x70);
      }
      else {
        lVar1 = *(longlong *)(lVar1 + 0x28);
      }
    }
  }
  *(uint *)((longlong)param_2 + (ulonglong)*(uint *)(param_2 + 3) * 4 + 0x1c) =
       *(uint *)(param_2 + 2) | 0x90000000;
  uVar2 = ((int)param_2[3] + 1U) % 100;
  *(uint *)(param_2 + 3) = uVar2;
  *(undefined4 *)((longlong)param_2 + (ulonglong)uVar2 * 4 + 0x1c) = 0xdeadbeef;
  if ((int)param_2[2] != iVar4) {
    _DAT_00000240 = _DAT_00000240 + 1;
  }
  if (*(uint *)((longlong)param_2 + 0x14) < *(uint *)(param_2 + 2)) {
    *(uint *)((longlong)param_2 + 0x14) = *(uint *)(param_2 + 2);
  }
  return;
}



===== AtaAlwaysSuccessRequestCompletion @ 14000c540 =====

void AtaAlwaysSuccessRequestCompletion(undefined8 param_1,longlong param_2)

{
  if ((*(byte *)(param_2 + 3) & 0x3f) == 1) {
    return;
  }
  *(undefined1 *)(param_2 + 3) = 1;
  return;
}



===== P_NotRunning @ 14000c560 =====

ulonglong P_NotRunning(longlong *param_1,longlong param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  
  if ((*(uint *)(*param_1 + 0x38) & 0x10) == 0) {
    bVar5 = 0;
  }
  else {
    bVar5 = (byte)((uint)*(undefined4 *)(*param_1 + 0x1a8) >> 0x18) & 1;
  }
  if ((char)param_1[0x49] == ' ') {
    uVar2 = RecordExecutionHistory(param_1,0x30011);
    uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  else {
    uVar3 = 0x10810011;
    if (bVar5 == 0) {
      uVar3 = 0x11;
    }
    RecordExecutionHistory(param_1,uVar3);
    *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfffffffe;
    LOCK();
    UNLOCK();
    *(undefined1 *)(param_1 + 0x49) = 0x20;
    if (bVar5 != 0) {
      bVar4 = 1;
      do {
        uVar6 = *(uint *)(param_2 + 0x18);
        if ((uVar6 & 1) == 0) goto LAB_140027052;
        StorPortStallExecution(5000);
        bVar4 = bVar4 + 1;
      } while (bVar4 < 0x65);
      if (bVar4 == 0x65) {
        RecordExecutionHistory(param_1,0x10820011);
      }
LAB_140027052:
      if ((char)*(undefined4 *)(param_1[0x129] + 0x20) < '\0') {
        *(uint *)(param_2 + 0x18) = uVar6 | 8;
        LOCK();
        UNLOCK();
      }
    }
    bVar4 = 1;
    do {
      if ((*(uint *)(param_2 + 0x18) & 0x8001) == 0) goto LAB_14000c600;
      StorPortStallExecution(5000);
      bVar4 = bVar4 + 1;
    } while (bVar4 < 0x65);
    if (bVar4 == 0x65) {
      uVar1 = RecordExecutionHistory(param_1,0x10350011);
      uVar1 = uVar1 & 0xffffffffffffff00;
    }
    else {
LAB_14000c600:
      bVar4 = 1;
      do {
        if (*(int *)(param_2 + 0x38) == 0) goto code_r0x00014000c629;
        StorPortStallExecution(0x32);
        bVar4 = bVar4 + 1;
      } while (bVar4 < 0x65);
      if (bVar4 == 0x65) {
        uVar1 = RecordExecutionHistory(param_1,0x10360011);
        uVar1 = uVar1 & 0xffffffffffffff00;
      }
      else {
code_r0x00014000c629:
        uVar6 = *(uint *)(param_2 + 0x18);
        if ((uVar6 & 0x4010) != 0) {
          *(uint *)(param_2 + 0x18) = uVar6 & 0xffffffef;
          LOCK();
          UNLOCK();
          if ((bVar5 != 0) && ((char)*(undefined4 *)(param_1[0x129] + 0x20) < '\0')) {
            *(uint *)(param_2 + 0x18) = uVar6 & 0xffffffef | 8;
            LOCK();
            UNLOCK();
          }
          bVar4 = 1;
          do {
            uVar6 = *(uint *)(param_2 + 0x18);
            if ((uVar6 & 0xc011) == 0) goto LAB_14000c6a6;
            StorPortStallExecution(5000);
            bVar4 = bVar4 + 1;
          } while (bVar4 < 0x65);
          if (bVar4 == 0x65) {
            uVar1 = RecordExecutionHistory(param_1,(uint)bVar5 * 0x10000 + 0x10370011);
            return uVar1 & 0xffffffffffffff00;
          }
        }
LAB_14000c6a6:
        if ((bVar5 != 0) && ((uVar6 & 8) == 0)) {
          bVar5 = 1;
          do {
            if ((*(uint *)(param_2 + 0x18) & 8) == 0) goto LAB_14000c6af;
            StorPortStallExecution(5000);
            bVar5 = bVar5 + 1;
          } while (bVar5 < 0x65);
          if (bVar5 == 0x65) {
            uVar1 = RecordExecutionHistory(param_1,0x10390011);
            return uVar1 & 0xffffffffffffff00;
          }
        }
LAB_14000c6af:
        uVar2 = RecordExecutionHistory(param_1,0x10000011);
        uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
      }
    }
  }
  return uVar1;
}



===== AhciAllocateDmaBuffer @ 14000c750 =====

void AhciAllocateDmaBuffer
               (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  if ((*(int *)(param_1 + 0x1a8) < 0) && ((*(uint *)(param_1 + 0x38) & 0x800) != 0)) {
    uVar1 = 0x7fffffffffffffff;
  }
  else {
    uVar1 = 0x7fffffff;
  }
  StorPortExtendedFunction(0x52,param_1,param_2,0,uVar1,0,1,0x80000000,param_3,param_4);
  return;
}



===== AhciPortSmartCompletion @ 14000c7d0 =====

void AhciPortSmartCompletion(longlong *param_1,longlong param_2)

{
  undefined4 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar3 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
  }
  uVar2 = GetSrbExtension(param_2);
  *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) & 0x7f;
  if (*(char *)(param_2 + 3) == '\x01') {
    *(undefined2 *)(lVar3 + 0x20) = 0;
    if (*(char *)(uVar2 + 0x1108) == -0x26) {
      uVar1 = 8;
    }
    else {
      uVar1 = *(undefined4 *)(uVar2 + 0x1130);
    }
  }
  else {
    *(undefined1 *)(lVar3 + 0x20) = 1;
    *(undefined1 *)(lVar3 + 0x21) = *(undefined1 *)(uVar2 + 0x1102);
    uVar1 = 0;
  }
  *(undefined4 *)(lVar3 + 0x1c) = uVar1;
  if (*(char *)(uVar2 + 0x1108) == -0x26) {
    AhciPortLogIoFailureStatistics(param_1);
  }
  return;
}



===== AhciPortLogIoFailureStatistics @ 14000c850 =====

void AhciPortLogIoFailureStatistics(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong local_res8;
  
  local_res8 = 0;
  if ((*(char *)(*param_1 + 0x18c) == '\0') && (param_1[0x8c6] != 0)) {
    lVar1 = *(longlong *)(param_1[0x8c6] + 0x30);
    StorPortQuerySystemTime(&local_res8);
    if ((lVar1 == 0) || (29999999999 < (ulonglong)(local_res8 - lVar1))) {
      uVar2 = *(int *)((longlong)param_1 + 0xac) + (int)param_1[0x16] + (int)param_1[0x15] +
              *(int *)((longlong)param_1 + 0xa4) + (int)param_1[0x14] +
              *(int *)((longlong)param_1 + 0x9c) + (int)param_1[0x13] +
              *(int *)((longlong)param_1 + 0x94);
      if (*(uint *)(param_1[0x8c6] + 0x38) < uVar2) {
        *(uint *)(param_1[0x8c6] + 0x38) = uVar2;
        StorPortExtendedFunction
                  (0x57,*param_1,param_1 + 1,2,0x1d,L"IO Failure Statistics",1,3,0,0,L"StateFlag",
                   param_1[0x4a],L"StartState",param_1[0x49],L"SuccessCount",(int)param_1[0x12],
                   L"CrcError|MediaError",
                   CONCAT44(*(undefined4 *)((longlong)param_1 + 0x94),(int)param_1[0x13]),
                   L"EndofMedia|IllegalCommand",
                   CONCAT44(*(undefined4 *)((longlong)param_1 + 0x9c),(int)param_1[0x14]),
                   L"AbortedCommand|DeviceFault",
                   CONCAT44(*(undefined4 *)((longlong)param_1 + 0xa4),(int)param_1[0x15]),
                   L"OtherError|NcqReadLogError",
                   CONCAT44(*(undefined4 *)((longlong)param_1 + 0xac),(int)param_1[0x16]),
                   L"PortDriverReset|TotalReset",
                   CONCAT44(*(undefined4 *)((longlong)param_1 + 0xb4),(int)param_1[0x17]));
        StorPortExtendedFunction
                  (0x57,*param_1,param_1 + 1,2,0x1d,L"IO Failure Stats Additional",1,3,0,0,
                   L"Reset|StartFail",
                   CONCAT44((int)param_1[0x8ba],*(undefined4 *)((longlong)param_1 + 0x45d4)),
                   L"ErrorRecv|NonQError",
                   CONCAT44((int)param_1[0x8bb],*(undefined4 *)((longlong)param_1 + 0x45dc)),
                   L"NCQError|NCQErrorComplete",
                   CONCAT44((int)param_1[0x8bc],*(undefined4 *)((longlong)param_1 + 0x45e4)),
                   L"SurpriseRemove|PowerSetting",
                   CONCAT44((int)param_1[0x8bd],*(undefined4 *)((longlong)param_1 + 0x45ec)),
                   L"PowerUp|PowerDown",
                   CONCAT44((int)param_1[0x8bf],*(undefined4 *)((longlong)param_1 + 0x45fc)),
                   L"PortStartTime|BusChange",
                   CONCAT44((int)param_1[0x8c0],*(undefined4 *)((longlong)param_1 + 0x4604)),
                   L"UnsolicitedINT|ResetNotWork",
                   CONCAT44(*(undefined4 *)((longlong)param_1 + 0x460c),
                            *(undefined4 *)((longlong)param_1 + 0x462c)),0,0);
        *(longlong *)(param_1[0x8c6] + 0x30) = local_res8;
      }
    }
  }
  return;
}



===== AhciIsEventAllowedWithinThrottleLimit @ 14000cc30 =====

bool AhciIsEventAllowedWithinThrottleLimit
               (longlong param_1,longlong param_2,int param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  longlong lVar4;
  longlong local_res8;
  
  local_res8 = 0;
  if (param_1 != 0) {
    if (param_2 == 0) {
      lVar4 = *(longlong *)(param_1 + 0x2c0);
      uVar1 = *(uint *)(param_1 + 0x2c8);
    }
    else {
      lVar4 = *(longlong *)(param_2 + 0x4620);
      uVar1 = *(uint *)(param_2 + 0x4628);
    }
    if (lVar4 != 0) {
      for (uVar2 = 0; uVar2 < uVar1; uVar2 = uVar2 + 1) {
        piVar3 = (int *)((ulonglong)uVar2 * 0x20 + lVar4);
        if (*piVar3 == param_3) {
          if (piVar3 != (int *)0x0) {
            StorPortQuerySystemTime(&local_res8);
            uVar1 = piVar3[7];
            uVar2 = piVar3[6];
            if ((*(longlong *)(piVar3 + 2) == 0) ||
               (*(ulonglong *)(piVar3 + 4) <= (ulonglong)(local_res8 - *(longlong *)(piVar3 + 2))))
            {
              if (param_4 != (int *)0x0) {
                if (uVar1 < uVar2) {
                  *param_4 = 0;
                }
                else {
                  *param_4 = uVar1 - uVar2;
                }
              }
              *(longlong *)(piVar3 + 2) = local_res8;
              piVar3[7] = 1;
              return true;
            }
            piVar3[7] = uVar1 + 1;
            if (param_4 != (int *)0x0) {
              if (uVar1 < uVar2) {
                *param_4 = 0;
              }
              else {
                *param_4 = (uVar1 + 1) - uVar2;
              }
            }
            return uVar1 < uVar2;
          }
          break;
        }
      }
    }
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
    }
  }
  return true;
}



===== BuildRequestSenseSrb @ 14000cd60 =====

undefined8 * BuildRequestSenseSrb(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  void *_Dst;
  longlong lVar5;
  ulonglong uVar6;
  byte bVar7;
  void *_Dst_00;
  uint *puVar8;
  uint uVar9;
  undefined4 local_res8 [2];
  
  puVar1 = param_1 + 0x13b;
  _Dst = (void *)param_1[0x146];
  _Dst_00 = (void *)0x0;
  bVar7 = 0;
  local_res8[0] = 0;
  if (*(char *)(param_2 + 2) == '(') {
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar9 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        puVar8 = (uint *)(param_2 + 0x78);
        do {
          uVar2 = *puVar8;
          if ((0x7f < uVar2) && (uVar3 = *(uint *)(param_2 + 0x10), uVar2 < uVar3)) {
            iVar4 = *(int *)((ulonglong)uVar2 + param_2);
            lVar5 = (ulonglong)uVar2 + param_2;
            uVar6 = (ulonglong)uVar2;
            if (iVar4 == 0x40) {
              uVar6 = uVar6 + 0x28;
            }
            else {
              if (iVar4 != 0x41) {
                if ((iVar4 != 0x42) || ((ulonglong)uVar3 < uVar6 + 0x28)) goto LAB_14000cef2;
                _Dst_00 = *(void **)(lVar5 + 0x18);
                bVar7 = *(byte *)(lVar5 + 9);
                break;
              }
              uVar6 = uVar6 + 0x38;
            }
            if (uVar6 <= uVar3) {
              _Dst_00 = *(void **)(lVar5 + 0x10);
              bVar7 = *(byte *)(lVar5 + 9);
              break;
            }
          }
LAB_14000cef2:
          uVar9 = uVar9 + 1;
          puVar8 = puVar8 + 1;
        } while (uVar9 < *(uint *)(param_2 + 0x38));
      }
    }
  }
  else if (*(char *)(param_2 + 2) == '\0') {
    _Dst_00 = *(void **)(param_2 + 0x20);
    bVar7 = *(byte *)(param_2 + 0xb);
  }
  if ((((_Dst != (void *)0x0) && (*(short *)((longlong)_Dst + 0x1100) == 0)) &&
      (_Dst_00 != (void *)0x0)) && (bVar7 != 0)) {
    memset(_Dst_00,0,(ulonglong)bVar7);
    *puVar1 = 0;
    param_1[0x13c] = 0;
    param_1[0x13d] = 0;
    param_1[0x13e] = 0;
    param_1[0x13f] = 0;
    param_1[0x140] = 0;
    param_1[0x141] = 0;
    param_1[0x142] = 0;
    param_1[0x143] = 0;
    param_1[0x144] = 0;
    param_1[0x145] = 0;
    memset(_Dst,0,0x29a0);
    *(undefined2 *)puVar1 = 0x58;
    *(undefined1 *)((longlong)param_1 + 0x9da) = 0;
    *(undefined1 *)((longlong)param_1 + 0x9dd) = *(undefined1 *)(param_1 + 0x48);
    *(undefined4 *)((longlong)param_1 + 0x9e4) = 0x40;
    param_1[0x13e] = _Dst_00;
    param_1[0x142] = _Dst;
    param_1[0x141] = param_2;
    *(undefined4 *)((longlong)param_1 + 0x9ec) = 1;
    *(undefined1 *)((longlong)param_1 + 0x9e2) = 6;
    *(uint *)(param_1 + 0x13d) = (uint)bVar7;
    *(undefined1 *)(param_1 + 0x144) = 3;
    *(byte *)((longlong)param_1 + 0xa24) = bVar7;
    *(undefined2 *)((longlong)_Dst + 0x1100) = 0x201;
    *(undefined4 *)((longlong)_Dst + 0x1104) = 2;
    lVar5 = StorPortGetPhysicalAddress(*param_1,param_2,_Dst_00,local_res8);
    if (lVar5 != 0) {
      *(int *)((longlong)_Dst + 0x1150) = (int)lVar5;
      *(int *)((longlong)_Dst + 0x1154) = (int)((ulonglong)lVar5 >> 0x20);
      *(undefined4 *)((longlong)_Dst + 0x1140) = 1;
      *(undefined4 *)((longlong)_Dst + 0x1158) = *(undefined4 *)(param_1 + 0x13d);
      *(undefined4 **)((longlong)_Dst + 0x1138) = (undefined4 *)((longlong)_Dst + 0x1140);
      return puVar1;
    }
  }
  return (undefined8 *)0x0;
}



===== FormatAtaId @ 14000cfa0 =====

void FormatAtaId(char *param_1,longlong param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  
  *param_1 = '\0';
  CopyField(param_1,param_2,param_3);
  if (param_3 != 0) {
    uVar3 = 0;
    if (param_3 != 1) {
      do {
        cVar1 = param_1[uVar3];
        uVar4 = (int)uVar3 + 1;
        param_1[uVar3] = param_1[uVar4];
        uVar2 = (int)uVar3 + 2;
        uVar3 = (ulonglong)uVar2;
        param_1[uVar4] = cVar1;
      } while (uVar2 < param_3 - 1);
    }
  }
  RemoveTrailingBlanks((longlong)param_1,param_3 + 1);
  return;
}



===== RemoveTrailingBlanks @ 14000d010 =====

int RemoveTrailingBlanks(longlong param_1,uint param_2)

{
  longlong lVar1;
  int iVar2;
  
  if (param_2 < 2) {
    return 0;
  }
  *(undefined1 *)((ulonglong)(param_2 - 1) + param_1) = 0;
  iVar2 = param_2 - 2;
  lVar1 = (longlong)iVar2;
  if (-1 < iVar2) {
    do {
      if (*(char *)(lVar1 + param_1) != ' ') break;
      iVar2 = iVar2 + -1;
      lVar1 = lVar1 + -1;
    } while (-1 < lVar1);
  }
  *(undefined1 *)((longlong)iVar2 + 1 + param_1) = 0;
  return iVar2 + 1;
}



===== AtaModeSenseRequestCompletionWriteCache @ 14000d060 =====

void AtaModeSenseRequestCompletionWriteCache(longlong param_1,longlong param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  void *_Dst;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  char *pcVar8;
  uint *puVar9;
  longlong lVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  
  pcVar13 = (char *)0x0;
  if (*(char *)(param_2 + 2) == '(') {
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar11 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        puVar9 = (uint *)(param_2 + 0x78);
        do {
          uVar3 = *puVar9;
          if ((0x7f < uVar3) &&
             (uVar5 = (ulonglong)*(uint *)(param_2 + 0x10), uVar3 < *(uint *)(param_2 + 0x10))) {
            iVar12 = *(int *)((ulonglong)uVar3 + param_2);
            lVar7 = (ulonglong)uVar3 + param_2;
            uVar6 = (ulonglong)uVar3;
            if (iVar12 == 0x40) {
              if (uVar6 + 0x28 <= uVar5) {
                cVar1 = *(char *)(lVar7 + 10);
joined_r0x00014000d216:
                if (cVar1 != '\0') {
                  pcVar13 = (char *)(lVar7 + 0x18);
                }
                break;
              }
            }
            else if (iVar12 == 0x41) {
              if (uVar6 + 0x38 <= uVar5) {
                cVar1 = *(char *)(lVar7 + 10);
                goto joined_r0x00014000d216;
              }
            }
            else if ((iVar12 == 0x42) && (uVar6 + 0x28 <= uVar5)) {
              if (*(int *)(lVar7 + 0xc) != 0) {
                pcVar13 = (char *)(lVar7 + 0x20);
              }
              break;
            }
          }
          uVar11 = uVar11 + 1;
          puVar9 = puVar9 + 1;
        } while (uVar11 < *(uint *)(param_2 + 0x38));
      }
    }
    _Dst = (void *)GetSrbExtension(param_2);
    lVar7 = *(longlong *)(param_2 + 0x40);
    uVar11 = *(uint *)(param_2 + 0x3c);
    lVar10 = *(longlong *)((longlong)_Dst + 0x1120);
  }
  else {
    if (*(char *)(param_2 + 2) == '\0') {
      _Dst = (void *)GetSrbExtension(param_2);
      pcVar8 = (char *)(param_2 + 0x48);
      if (*(char *)(param_2 + 10) == (char)pcVar13) {
        pcVar8 = pcVar13;
      }
      pcVar13 = pcVar8;
    }
    else {
      _Dst = (void *)GetSrbExtension(param_2);
    }
    lVar7 = *(longlong *)(param_2 + 0x18);
    uVar11 = *(uint *)(param_2 + 0x10);
    lVar10 = *(longlong *)((longlong)_Dst + 0x1120);
  }
  if (pcVar13 != (char *)0x0) {
    lVar4 = 4;
    if (*pcVar13 != '\x1a') {
      lVar4 = 8;
    }
    if (*(char *)(param_2 + 3) != '\x0e') {
      if ((lVar7 == 0) || ((ulonglong)uVar11 < lVar4 + 8U)) {
        *(undefined1 *)(param_2 + 3) = 4;
      }
      else {
        if (*(char *)(param_2 + 3) == '\x01') {
          bVar2 = *(byte *)(lVar4 + lVar7 + 2);
          *(byte *)(lVar4 + lVar7 + 2) =
               ((char)(*(ushort *)(lVar10 + 0xaa) >> 5) << 2 ^ bVar2) & 4 ^ bVar2;
        }
        else {
          *(undefined1 *)(param_2 + 3) = 4;
        }
        iVar12 = (uVar11 - (int)lVar4) + -0xc;
        if (*(char *)(param_2 + 2) == '(') {
          *(int *)(param_2 + 0x3c) = iVar12;
        }
        else {
          *(int *)(param_2 + 0x10) = iVar12;
        }
        if (((*(byte *)(param_1 + 0x20) & 1) != 0) &&
           (uVar5 = IsMsnEnabled(param_1 + 8), (char)uVar5 != '\0')) {
          memset(_Dst,0,0x29a0);
          *(undefined2 *)((longlong)_Dst + 0x1100) = 0x100;
          *(undefined1 *)((longlong)_Dst + 0x110e) = 0xda;
        }
      }
    }
  }
  return;
}



===== AhciPortFailAllIos @ 14000d280 =====

void AhciPortFailAllIos(longlong *param_1,undefined1 param_2)

{
  byte bVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  do {
    if (param_1[(uVar2 + 0x18) * 4] != 0) {
      *(undefined1 *)(param_1[(uVar2 + 0x18) * 4] + 3) = param_2;
      AhciCompleteJustSlottedRequest(param_1,(longlong *)param_1[(uVar2 + 0x18) * 4],'\x01');
    }
    bVar1 = (char)uVar2 + 1;
    uVar2 = (ulonglong)bVar1;
  } while (bVar1 <= ((byte)((uint)*(undefined4 *)(*param_1 + 0x1a8) >> 8) & 0x1f));
  return;
}



===== BuildLocalCommand @ 14000d300 =====

void BuildLocalCommand(longlong *param_1,undefined8 *param_2,undefined8 param_3)

{
  void *_Dst;
  undefined8 uVar1;
  
  *(undefined1 *)((longlong)param_1 + 0x973) = 0;
  _Dst = (void *)param_1[0x139];
  param_1[0x135] = (longlong)_Dst;
  *(undefined4 *)((longlong)param_1 + 0x984) = 1;
  memset(_Dst,0,0x29a0);
  *(undefined2 *)((longlong)_Dst + 0x1100) = 0x100;
  *(undefined8 *)((longlong)_Dst + 0x2968) = param_3;
  uVar1 = param_2[1];
  *(undefined8 *)((longlong)_Dst + 0x1108) = *param_2;
  *(undefined8 *)((longlong)_Dst + 0x1110) = uVar1;
  if ((*(uint *)(*param_1 + 0x34) & 1) != 0) {
    RecordExecutionHistory(param_1,0x1000001d);
  }
  return;
}



===== AtaPassThroughRequestCompletion @ 14000d3a0 =====

void AtaPassThroughRequestCompletion(longlong param_1,longlong param_2)

{
  byte *_Dst;
  byte bVar1;
  ulonglong uVar2;
  
  bVar1 = *(byte *)(param_2 + 3) & 0x3f;
  if (bVar1 == 0xe) {
    uVar2 = GetSrbExtension(param_2);
    _Dst = *(byte **)(uVar2 + 0x2988);
    if ((_Dst != (byte *)0x0) && (8 < *(uint *)(uVar2 + 0x2998))) {
      memset(_Dst,0,(ulonglong)*(uint *)(uVar2 + 0x2998));
      _Dst[7] = 0xe;
      _Dst[8] = 9;
      *_Dst = *_Dst & 0xf2 | 0x72;
      _Dst[9] = 0xc;
      _Dst[10] = (byte)(*(uint *)(uVar2 + 0x1104) >> 3) & 1 | _Dst[10] & 0xfe;
      _Dst[0xb] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x43);
      _Dst[0xd] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x4c);
      _Dst[0xf] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x44);
      _Dst[0x11] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x45);
      _Dst[0x13] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x46);
      _Dst[0x14] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x47);
      _Dst[0x15] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x42);
      if ((*(uint *)(uVar2 + 0x1104) & 8) != 0) {
        _Dst[0xc] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x4d);
        _Dst[0xe] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x48);
        _Dst[0x10] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x49);
        _Dst[0x12] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x4a);
      }
      *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) | 0x80;
    }
  }
  else if (bVar1 != 1) {
    *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) & 0x81 | 1;
  }
  return;
}



===== IssueReadLogExtCommand @ 14000d3f0 =====

void IssueReadLogExtCommand
               (longlong param_1,longlong param_2,undefined1 param_3,undefined2 param_4,
               ushort param_5,undefined2 param_6,undefined8 *param_7,undefined8 param_8,
               undefined8 param_9)

{
  ulonglong uVar1;
  
  uVar1 = GetSrbExtension(param_2);
  *(uint *)(uVar1 + 0x1104) = *(uint *)(uVar1 + 0x1104) | 10;
  *(undefined8 *)(uVar1 + 0x2968) = param_9;
  *(char *)(uVar1 + 0x1108) = (char)param_6;
  *(char *)(uVar1 + 0x110b) = (char)param_4;
  *(undefined1 *)(uVar1 + 0x110a) = param_3;
  *(char *)(uVar1 + 0x1111) = (char)(param_5 >> 8);
  *(char *)(uVar1 + 0x1110) = (char)((ushort)param_6 >> 8);
  *(undefined2 *)(uVar1 + 0x1100) = 0x100;
  *(char *)(uVar1 + 0x1109) = (char)param_5;
  *(undefined4 *)(uVar1 + 0x110c) = 0x2fe000;
  *(undefined1 *)(uVar1 + 0x1112) = 0;
  *(char *)(uVar1 + 0x1113) = (char)((ushort)param_4 >> 8);
  *(undefined4 *)(uVar1 + 0x1114) = 0;
  *(undefined1 *)(param_2 + 3) = 0;
  *(undefined8 *)(uVar1 + 0x1120) = param_8;
  if (param_7 != (undefined8 *)0x0) {
    *(undefined8 *)(uVar1 + 0x1128) = *param_7;
    *(undefined4 *)(uVar1 + 0x1140) = 1;
    *(undefined4 *)(uVar1 + 0x1150) = *(undefined4 *)param_7;
    *(undefined4 *)(uVar1 + 0x1154) = *(undefined4 *)((longlong)param_7 + 4);
    *(uint *)(uVar1 + 0x1158) = (uint)param_5 << 9;
    *(uint *)(uVar1 + 0x1130) = (uint)param_5 << 9;
    *(undefined4 **)(uVar1 + 0x1138) = (undefined4 *)(uVar1 + 0x1140);
  }
  if (param_7 == (undefined8 *)(param_1 + 0x1e8)) {
    *(undefined1 *)(param_1 + 0x1f0) = 0xff;
  }
  return;
}



===== SetReturnRegisterValues @ 14000d510 =====

void SetReturnRegisterValues(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *_Dst;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  char *pcVar9;
  uint *puVar10;
  
  lVar8 = param_2;
  uVar6 = GetSrbExtension(param_2);
  if (*(char *)(lVar8 + 2) == '(') {
    pcVar9 = (char *)0x0;
    if (*(int *)(lVar8 + 0x14) == 0) {
      uVar5 = 0;
      if (*(uint *)(lVar8 + 0x38) != 0) {
        puVar10 = (uint *)(lVar8 + 0x78);
        do {
          uVar2 = *puVar10;
          if ((0x7f < uVar2) && (uVar3 = *(uint *)(param_2 + 0x10), uVar2 < uVar3)) {
            iVar4 = *(int *)((ulonglong)uVar2 + param_2);
            lVar1 = (ulonglong)uVar2 + param_2;
            uVar7 = (ulonglong)uVar2;
            if (iVar4 == 0x40) {
              uVar7 = uVar7 + 0x28;
            }
            else {
              if (iVar4 != 0x41) {
                if ((iVar4 != 0x42) || ((ulonglong)uVar3 < uVar7 + 0x28)) goto LAB_14000d5ba;
                if (*(int *)(lVar1 + 0xc) != 0) {
                  pcVar9 = (char *)(lVar1 + 0x20);
                }
                break;
              }
              uVar7 = uVar7 + 0x38;
            }
            if (uVar7 <= uVar3) {
              if (*(char *)(lVar1 + 10) != '\0') {
                pcVar9 = (char *)(lVar1 + 0x18);
              }
              break;
            }
          }
LAB_14000d5ba:
          uVar5 = uVar5 + 1;
          puVar10 = puVar10 + 1;
        } while (uVar5 < *(uint *)(lVar8 + 0x38));
      }
    }
  }
  else {
    pcVar9 = (char *)(lVar8 + 0x48);
  }
  uVar5 = IsAtaPioDataInCmd(param_2);
  if (((*(uint *)(uVar6 + 0x1104) & 0x40) != 0) &&
     (_Dst = *(byte **)(uVar6 + 0x2988), _Dst != (byte *)0x0)) {
    if ((pcVar9 == (char *)0x0) || (*pcVar9 != -0x7b)) {
      _Dst[6] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x42);
      *_Dst = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x43);
      _Dst[4] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x46);
      _Dst[3] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x45);
      _Dst[5] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x47);
      _Dst[1] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x4c);
      _Dst[2] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x44);
      if (((*(uint *)(uVar6 + 0x1104) & 8) != 0) && (0xf < *(uint *)(uVar6 + 0x2998))) {
        _Dst[0xe] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x42);
        _Dst[8] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x43);
        _Dst[0xc] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x4a);
        _Dst[0xb] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x49);
        _Dst[0xd] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x47);
        _Dst[9] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x4d);
        _Dst[10] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x48);
      }
    }
    else if (8 < *(uint *)(uVar6 + 0x2998)) {
      memset(_Dst,0,(ulonglong)*(uint *)(uVar6 + 0x2998));
      _Dst[7] = 0xe;
      _Dst[8] = 9;
      *_Dst = *_Dst & 0xf2 | 0x72;
      _Dst[9] = 0xc;
      _Dst[10] = (byte)(*(uint *)(uVar6 + 0x1104) >> 3) & 1 | _Dst[10] & 0xfe;
      if (((char)uVar5 == '\0') || ((*(byte *)(param_2 + 3) & 0x3f) != 1)) {
        _Dst[0xb] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x43);
        _Dst[0xd] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x4c);
        _Dst[0xf] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x44);
        _Dst[0x11] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x45);
        _Dst[0x13] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x46);
        _Dst[0x14] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x47);
        _Dst[0x15] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x42);
        if ((*(uint *)(uVar6 + 0x1104) & 8) != 0) {
          _Dst[0xc] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x4d);
          _Dst[0xe] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x48);
          _Dst[0x10] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x49);
          _Dst[0x12] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x4a);
        }
      }
      else {
        _Dst[0x15] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x2f);
        _Dst[0xb] = *(byte *)(*(longlong *)(param_1 + 0x958) + 0x23);
      }
    }
    *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) | 0x80;
  }
  return;
}



===== IsAtaPioDataInCmd @ 14000d830 =====

uint IsAtaPioDataInCmd(longlong param_1)

{
  ulonglong uVar1;
  byte bVar2;
  
  uVar1 = GetSrbExtension(param_1);
  bVar2 = 0xff;
  if (*(ushort *)(uVar1 + 0x1100) == 0x400) {
    bVar2 = *(byte *)(uVar1 + 0x110a);
  }
  else if ((*(ushort *)(uVar1 + 0x1100) >> 8 & 1) != 0) {
    bVar2 = *(byte *)(uVar1 + 0x110e);
  }
  if (bVar2 == 0xec) {
LAB_14000d8a0:
    return 1;
  }
  switch(bVar2 - 0x20) {
  case 0:
  case 4:
  case 9:
  case 0xf:
  case 0x81:
  case 0xa4:
    goto LAB_14000d8a0;
  default:
    return 0;
  }
}



===== GetInterruptMode @ 14000d8b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GetInterruptMode(longlong param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  uVar3 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((*(char *)(param_1 + 0x18c) == '\0') &&
     ((*(uint *)(*(longlong *)(param_1 + 400) + 4) & 4) == 0)) {
    iVar1 = StorPortExtendedFunction(0xd,param_1,0,&local_38);
    while (iVar1 == 0) {
      uVar3 = uVar3 + 1;
      iVar1 = StorPortExtendedFunction(0xd,param_1,uVar3,&local_38);
    }
  }
  uVar2 = *(uint *)(param_1 + 0x2c) | 0x80;
  if (uVar3 <= *(uint *)(param_1 + 0x184)) {
    uVar2 = *(uint *)(param_1 + 0x2c) & 0xffffff7f;
  }
  *(uint *)(param_1 + 0x2c) = uVar2;
  if (((*(uint *)(param_1 + 0x44) != 0) && ((char)uVar2 < '\0')) &&
     (uVar3 < *(uint *)(param_1 + 0x44))) {
    *(uint *)(param_1 + 0x2c) = uVar2 & 0xffffff7f;
  }
  return;
}



===== AhciCompleteJustSlottedRequest @ 14000d990 =====

void AhciCompleteJustSlottedRequest(longlong *param_1,longlong *param_2,char param_3)

{
  byte *pbVar1;
  byte bVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong *plVar5;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_38 = 3;
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  plVar5 = param_2;
  uVar3 = GetSrbExtension((longlong)param_2);
  bVar2 = *(byte *)(uVar3 + 0x2978);
  if (*(short *)(uVar3 + 0x1100) == 0x201) {
    if (*(char *)((longlong)plVar5 + 2) == '(') {
      param_2 = (longlong *)plVar5[10];
    }
    else {
      param_2 = (longlong *)plVar5[6];
    }
    *(byte *)((longlong)param_2 + 3) = *(byte *)((longlong)param_2 + 3) & 0x7f;
    *(undefined2 *)(uVar3 + 0x1100) = 0;
  }
  if (param_3 == '\0') {
    AhciInterruptSpinlockAcquire(*param_1,(int)param_1[0x48],(longlong)&local_38);
  }
  pbVar1 = (byte *)((longlong)param_1 + (ulonglong)bVar2 * 0x20 + 0x2f9);
  *pbVar1 = *pbVar1 & 0xfe;
  param_1[(ulonglong)bVar2 * 4 + 0x61] = 0;
  *(undefined1 *)(param_1 + (ulonglong)bVar2 * 4 + 0x5f) = 0;
  param_1[(ulonglong)bVar2 * 4 + 0x60] = 0;
  uVar4 = 1 << (*(byte *)(uVar3 + 0x2978) & 0x1f);
  if ((uVar4 & *(uint *)((longlong)param_1 + 0x2cc)) != 0) {
    *(uint *)((longlong)param_1 + 0x2cc) = ~uVar4 & *(uint *)((longlong)param_1 + 0x2cc);
  }
  uVar4 = 1 << (*(byte *)(uVar3 + 0x2978) & 0x1f);
  if ((uVar4 & *(uint *)(param_1 + 0x5a)) != 0) {
    *(uint *)(param_1 + 0x5a) = ~uVar4 & *(uint *)(param_1 + 0x5a);
  }
  uVar4 = 1 << (*(byte *)(uVar3 + 0x2978) & 0x1f);
  if ((uVar4 & *(uint *)((longlong)param_1 + 0x2d4)) != 0) {
    *(uint *)((longlong)param_1 + 0x2d4) = ~uVar4 & *(uint *)((longlong)param_1 + 0x2d4);
  }
  uVar4 = 1 << (*(byte *)(uVar3 + 0x2978) & 0x1f);
  if ((uVar4 & *(uint *)(param_1 + 0x5b)) != 0) {
    *(uint *)(param_1 + 0x5b) = ~uVar4 & *(uint *)(param_1 + 0x5b);
  }
  uVar4 = 1 << (*(byte *)(uVar3 + 0x2978) & 0x1f);
  if ((uVar4 & *(uint *)(param_1 + 0x5c)) != 0) {
    *(uint *)(param_1 + 0x5c) = ~uVar4 & *(uint *)(param_1 + 0x5c);
  }
  if (param_3 == '\0') {
    AhciInterruptSpinlockRelease(*param_1,(int)param_1[0x48],(longlong)&local_38);
  }
  AhciCompleteRequest(param_1,param_2,param_3);
  return;
}



===== AtaStartStopUnitRequest @ 14000db30 =====

undefined8 AtaStartStopUnitRequest(longlong param_1,longlong param_2,longlong param_3)

{
  undefined1 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar2 = GetSrbExtension(param_2);
  if ((*(byte *)(param_3 + 4) & 1) == 0) {
    *(undefined2 *)(uVar2 + 0x1100) = 0x100;
    uVar1 = 0xed;
    if ((*(byte *)(param_3 + 4) & 2) == 0) {
      uVar1 = 0xe0;
    }
    *(undefined1 *)(uVar2 + 0x110e) = uVar1;
    return 0;
  }
  if (((*(int *)(param_1 + 0x30) == 2) &&
      (uVar3 = DeviceIncursNoSeekPenalty(param_1), (char)uVar3 == '\0')) &&
     (-1 < *(char *)(*(longlong *)(param_1 + 0xc0) + 0x8a))) {
    *(byte *)(uVar2 + 0x110d) = *(byte *)(uVar2 + 0x110d) | 0xe0;
    *(code **)(uVar2 + 0x2968) = AtaAlwaysSuccessRequestCompletion;
    *(undefined2 *)(uVar2 + 0x1100) = 0x100;
    *(undefined1 *)(uVar2 + 0x1109) = 1;
    *(undefined1 *)(uVar2 + 0x110e) = 0x42;
    return 0;
  }
  *(undefined1 *)(param_2 + 3) = 1;
  return 0;
}



===== AhciPortAhciEnableDevslpICC @ 14000dbe0 =====

void AhciPortAhciEnableDevslpICC(longlong *param_1)

{
  int *piVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  byte bVar8;
  longlong *plVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  int iVar14;
  
  plVar9 = param_1;
  StorPortExtendedFunction(0x21,*param_1,param_1[0x154],AhciAutoPartialToSlumber,param_1,0,0);
  uVar3 = *(uint *)(param_1[0x129] + 0x38);
  iVar14 = *(int *)(param_1[0x129] + 0x34);
  if (((uVar3 != 0) || (iVar14 != 0)) || ((char)param_1[0x49] != '\x16')) {
    lVar6 = *param_1;
    if (*(char *)(lVar6 + 0x18e) == '\0') {
      return;
    }
    pwVar13 = L"SACT";
    pwVar12 = L"CI";
    uVar11 = 3;
LAB_14000dcbc:
    StorPortExtendedFunction
              (0x56,lVar6,param_1 + 1,0,3,L"DEVSLP Enabled",4,4,0,0,L"Using HW DEVSLP",0,L"Status",
               uVar11,pwVar12,uVar3,pwVar13,iVar14);
    return;
  }
  uVar3 = *(uint *)(param_1[0x129] + 0x28);
  uVar4 = (ulonglong)uVar3;
  uVar7 = uVar3 >> 8;
  lVar6 = *param_1;
  uVar5 = uVar3 & 0xf00;
  if (uVar5 == 0x800) {
    if (*(char *)(lVar6 + 0x18e) == '\0') {
      return;
    }
    iVar14 = 0;
    pwVar13 = (wchar_t *)0x0;
    uVar3 = uVar3 >> 8 & 0xf;
    pwVar12 = L"SSTS.IPM";
    uVar11 = 7;
    goto LAB_14000dcbc;
  }
  if ((*(uint *)(lVar6 + 0x1ac) & 0x20) != 0) {
    uVar3 = *(uint *)(param_1[0x129] + 0x18);
    if (uVar5 == 0x600) {
      if (0xfffffff < uVar3) goto LAB_14000df43;
    }
    else {
      if (uVar3 < 0x10000000) {
        piVar1 = (int *)((longlong)param_1 + 0x2ac);
        if ((piVar1 != (int *)0x0) && (*piVar1 != -1)) {
          *piVar1 = *piVar1 + 1;
        }
        if (uVar5 == 0x200) {
          uVar3 = uVar3 & 0xfffffff | 0x10000000;
          *(uint *)(param_1[0x129] + 0x18) = uVar3;
          LOCK();
          UNLOCK();
          uVar7 = 0;
          uVar4 = (ulonglong)*(uint *)(param_1[0x129] + 0x28);
          bVar8 = 0;
          do {
            if (((uint)uVar4 & 0xf00) == 0x100) break;
            if (bVar8 < 3) {
              uVar3 = uVar3 & 0xfffffff | 0x10000000;
              *(uint *)(param_1[0x129] + 0x18) = uVar3;
              LOCK();
              UNLOCK();
            }
            StorPortStallExecution(10);
            uVar7 = uVar7 + 10;
            uVar4 = (ulonglong)*(uint *)(param_1[0x129] + 0x28);
            bVar8 = bVar8 + 1;
          } while (uVar7 < 100);
          if (((uint)uVar4 & 0xf00) == 0x100) {
            plVar2 = (longlong *)((longlong)param_1 + 0x2b4);
            if (plVar2 != (longlong *)0x0) {
              iVar14 = *(int *)plVar2;
joined_r0x00014000de4b:
              if (iVar14 != -1) {
                *(int *)plVar2 = iVar14 + 1;
              }
            }
          }
          else {
            plVar2 = param_1 + 0x56;
            if (plVar2 != (longlong *)0x0) {
              iVar14 = (int)*plVar2;
              goto joined_r0x00014000de4b;
            }
          }
        }
        uVar10 = (undefined4)((ulonglong)plVar9 >> 0x20);
        uVar7 = (uint)(uVar4 >> 8);
        if (((uint)uVar4 & 0xf00) != 0x100) {
          uVar11 = 4;
          goto LAB_14000e060;
        }
        uVar3 = uVar3 & 0xfffffff | 0x60000000;
        *(uint *)(param_1[0x129] + 0x18) = uVar3;
        LOCK();
        UNLOCK();
        uVar7 = 0;
        uVar4 = (ulonglong)*(uint *)(param_1[0x129] + 0x28);
        bVar8 = 0;
        do {
          if (((uint)uVar4 & 0xf00) == 0x600) break;
          if (bVar8 < 3) {
            uVar3 = uVar3 & 0xfffffff | 0x60000000;
            *(uint *)(param_1[0x129] + 0x18) = uVar3;
            LOCK();
            UNLOCK();
          }
          StorPortStallExecution(10);
          uVar7 = uVar7 + 10;
          uVar4 = (ulonglong)*(uint *)(param_1[0x129] + 0x28);
          bVar8 = bVar8 + 1;
        } while (uVar7 < 100);
        uVar10 = (undefined4)((ulonglong)plVar9 >> 0x20);
        uVar7 = (uint)(uVar4 >> 8);
        if (((uint)uVar4 & 0xf00) != 0x600) {
          plVar9 = param_1 + 0x57;
          if ((plVar9 != (longlong *)0x0) && ((int)*plVar9 != -1)) {
            *(int *)plVar9 = (int)*plVar9 + 1;
          }
          uVar11 = 5;
          goto LAB_14000e060;
        }
        plVar2 = (longlong *)((longlong)param_1 + 700);
        if (plVar2 == (longlong *)0x0) goto LAB_14000df5a;
        iVar14 = *(int *)plVar2;
      }
      else {
LAB_14000df43:
        plVar2 = param_1 + 0x55;
        if (plVar2 == (longlong *)0x0) goto LAB_14000df5a;
        iVar14 = (int)*plVar2;
      }
      if (iVar14 != -1) {
        *(int *)plVar2 = iVar14 + 1;
      }
    }
  }
LAB_14000df5a:
  uVar10 = (undefined4)((ulonglong)plVar9 >> 0x20);
  uVar3 = *(uint *)(param_1[0x129] + 0x18);
  if (uVar3 < 0x10000000) {
    piVar1 = (int *)((longlong)param_1 + 0x2ac);
    if ((piVar1 != (int *)0x0) && (*piVar1 != -1)) {
      *piVar1 = *piVar1 + 1;
    }
    uVar3 = uVar3 & 0xfffffff | 0x80000000;
    *(uint *)(param_1[0x129] + 0x18) = uVar3;
    LOCK();
    UNLOCK();
    uVar7 = 0;
    uVar4 = (ulonglong)*(uint *)(param_1[0x129] + 0x28);
    do {
      uVar10 = (undefined4)((ulonglong)plVar9 >> 0x20);
      if (((uint)uVar4 & 0xf00) == 0x800) break;
      *(uint *)(param_1[0x129] + 0x18) = uVar3;
      LOCK();
      UNLOCK();
      StorPortStallExecution(10);
      uVar10 = (undefined4)((ulonglong)plVar9 >> 0x20);
      uVar7 = uVar7 + 1;
      uVar4 = (ulonglong)*(uint *)(param_1[0x129] + 0x28);
    } while (uVar7 < 3);
    uVar7 = (uint)(uVar4 >> 8);
    if (((uint)uVar4 & 0xf00) == 0x800) {
      piVar1 = (int *)((longlong)param_1 + 0x2c4);
      if ((piVar1 != (int *)0x0) && (*piVar1 != -1)) {
        *piVar1 = *piVar1 + 1;
      }
      *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) | 8;
      uVar11 = 0;
    }
    else {
      plVar9 = param_1 + 0x58;
      uVar11 = 6;
      if ((plVar9 != (longlong *)0x0) && ((int)*plVar9 != -1)) {
        *(int *)plVar9 = (int)*plVar9 + 1;
      }
    }
  }
  else {
    plVar9 = param_1 + 0x55;
    if ((plVar9 != (longlong *)0x0) && ((int)*plVar9 != -1)) {
      *(int *)plVar9 = (int)*plVar9 + 1;
    }
    uVar11 = 2;
  }
LAB_14000e060:
  if (*(char *)(*param_1 + 0x18e) == '\0') {
    return;
  }
  StorPortExtendedFunction
            (0x56,*param_1,param_1 + 1,0,CONCAT44(uVar10,3),L"DEVSLP Enabled",4,4,0,0,
             L"Using HW DEVSLP",0,L"Status",uVar11,L"SSTS.IPM",uVar7 & 0xf,L"CMD.ICC",uVar3 >> 0x1c)
  ;
  return;
}



===== AhciCancelF1IdleTimer @ 14000e190 =====

undefined8 AhciCancelF1IdleTimer(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if ((((ulonglong)param_1[0x4a] >> 0xd & 1) != 0) && (1 < *(uint *)(param_1[0x50] + 0x20))) {
    if (*(char *)(param_1 + 0x51) == '\0') {
      StorPortExtendedFunction(0x33,*param_1,param_1 + 1,0,0);
    }
    if ((*(uint *)((longlong)param_1 + 0x254) & 0x10) != 0) {
      uVar1 = StorPortExtendedFunction
                        (0x21,*param_1,param_1[0x156],AhciF1IdleTimerCallback,param_1,0,0);
      *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) & 0xffffffef;
      return uVar1;
    }
  }
  return 0;
}



===== AhciHwAdapterControl @ 14000e250 =====

undefined8 AhciHwAdapterControl(longlong param_1,undefined4 param_2,uint *param_3)

{
  longlong lVar1;
  ulonglong *puVar2;
  longlong *plVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined8 uVar11;
  uint *puVar12;
  undefined8 *local_res8;
  undefined4 local_res10 [2];
  undefined8 in_stack_ffffffffffffff68;
  undefined8 in_stack_ffffffffffffff70;
  undefined4 uVar13;
  undefined8 in_stack_ffffffffffffff88;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff70 >> 0x20);
  uVar9 = 0;
  uVar11 = 0;
  switch(param_2) {
  case 0:
    uVar6 = *param_3;
    if (uVar6 != 0) {
      *(undefined1 *)(param_3 + 1) = 1;
    }
    if (1 < uVar6) {
      *(undefined1 *)((longlong)param_3 + 5) = 1;
    }
    if (2 < uVar6) {
      *(undefined1 *)((longlong)param_3 + 6) = 1;
    }
    if (5 < uVar6) {
      *(undefined1 *)((longlong)param_3 + 9) = 1;
    }
    if (8 < uVar6) {
      *(undefined1 *)(param_3 + 3) = 1;
    }
    if (uVar6 < 10) {
      if (uVar6 < 7) {
        return 0;
      }
    }
    else {
      *(undefined1 *)((longlong)param_3 + 0xd) = 1;
    }
    *(undefined1 *)((longlong)param_3 + 10) = 1;
    if (0xb < uVar6) {
      *(undefined1 *)((longlong)param_3 + 0xf) = 1;
    }
    if (0xc < uVar6) {
      *(undefined1 *)(param_3 + 4) = 1;
    }
    if (0x10 < uVar6) {
      *(undefined1 *)(param_3 + 5) = 1;
    }
    if (0x18 < uVar6) {
      *(undefined1 *)(param_3 + 7) = 1;
    }
    if (0x19 < uVar6) {
      *(undefined1 *)((longlong)param_3 + 0x1d) = 1;
    }
    break;
  case 1:
    if ((*(uint *)(param_1 + 0x2c) & 0x20) != 0) {
      AhciAdapterRemoval(param_1);
    }
    break;
  case 2:
  case 9:
  case 0x10:
    break;
  default:
    goto switchD_14000e28c_caseD_3;
  case 5:
    do {
      puVar2 = *(ulonglong **)(param_1 + 0x1b0 + uVar9 * 8);
      if (puVar2 != (ulonglong *)0x0) {
        AhciPortPowerSettingNotification(puVar2,(int *)param_3);
      }
      uVar6 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar6;
    } while (uVar6 <= *(uint *)(param_1 + 0x184));
    break;
  case 6:
    if (param_3[5] != 1) {
      if (param_3[5] != 4) {
        return 0;
      }
      lVar1 = *(longlong *)(param_1 + 400);
      do {
        puVar2 = *(ulonglong **)(param_1 + 0x1b0 + uVar9 * 8);
        if (((puVar2 != (ulonglong *)0x0) && ((puVar2[0x4a] & 0x1000) == 0)) &&
           ((int)puVar2[3] == 6)) {
          AhciPortPowerDown(puVar2);
        }
        uVar6 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar6;
      } while (uVar6 <= *(uint *)(param_1 + 0x184));
      *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xfffffffd;
      LOCK();
      UNLOCK();
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 2;
      return 0;
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffffd;
    lVar1 = *(longlong *)(param_1 + 400);
    uVar6 = *(uint *)(lVar1 + 4);
    if ((int)uVar6 < 0) {
      if ((uVar6 & 2) == 0) goto LAB_14000e433;
    }
    else {
      uVar6 = 0x80000000;
      *(undefined4 *)(lVar1 + 4) = 0x80000000;
      LOCK();
      UNLOCK();
LAB_14000e433:
      *(uint *)(lVar1 + 4) = uVar6 | 2;
      LOCK();
      UNLOCK();
    }
    do {
      puVar2 = *(ulonglong **)(param_1 + 0x1b0 + uVar9 * 8);
      if (((puVar2 != (ulonglong *)0x0) && ((puVar2[0x4a] & 0x1000) != 0)) && ((int)puVar2[3] == 6))
      {
        AhciPortPowerUp(puVar2);
      }
      uVar6 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar6;
    } while (uVar6 <= *(uint *)(param_1 + 0x184));
    break;
  case 8:
    if (((*(uint *)(param_1 + 0x2c) & 4) != 0) &&
       (*(uint *)(param_1 + 0x2c) =
             -(uint)((char)param_3[5] != '\0') & 8 | *(uint *)(param_1 + 0x2c) & 0xfffffff7,
       (char)param_3[5] != '\0')) {
      LOCK();
      puVar12 = (uint *)(param_1 + 0x28);
      uVar6 = *puVar12;
      *puVar12 = *puVar12 & 0xfffffffe;
      UNLOCK();
      if ((uVar6 & 1) != 0) {
        local_40 = 0;
        local_48 = 2;
        local_38 = 0;
        uStack_30 = 0;
        StorPortNotification(0x1003,param_1,2,0,&local_48);
        AdapterStop(param_1);
        StorPortNotification(0x1004,param_1,&local_48);
      }
    }
    break;
  case 0xb:
    if ((*(uint *)(param_1 + 0x2c) & 0x10) != 0) {
      local_res10[0] = 0;
      local_res8 = (undefined8 *)0x0;
      iVar7 = StorPortExtendedFunction(0,param_1,0x48,0x69636841,&local_res8);
      if (iVar7 == 0) {
        if (local_res8 == (undefined8 *)0x0) goto LAB_14000e649;
        *local_res8 = 0;
        local_res8[1] = 0;
        local_res8[2] = 0;
        local_res8[3] = 0;
        local_res8[4] = 0;
        local_res8[5] = 0;
        local_res8[6] = 0;
        local_res8[7] = 0;
        local_res8[8] = 0;
        *(undefined4 *)local_res8 = 0x43696541;
        *(undefined4 *)((longlong)local_res8 + 4) = 0x4d53445f;
        *(undefined4 *)(local_res8 + 1) = 0x48;
        *(undefined4 *)((longlong)local_res8 + 0xc) = 4;
        *(undefined4 *)(local_res8 + 2) = 0x100002;
        *(undefined4 *)((longlong)local_res8 + 0x14) = 0xe4db149b;
        *(undefined4 *)(local_res8 + 3) = 0x425bfcfe;
        *(undefined4 *)((longlong)local_res8 + 0x1c) = 0x3592d8a6;
        *(undefined4 *)(local_res8 + 4) = 0x7ffc787d;
        *(undefined4 *)((longlong)local_res8 + 0x24) = 0x40000;
        *(undefined4 *)(local_res8 + 5) = 1;
        *(undefined4 *)(local_res8 + 6) = 2;
        *(undefined4 *)((longlong)local_res8 + 0x2c) = 0x40000;
        *(undefined4 *)((longlong)local_res8 + 0x34) = 0x100004;
        *(undefined4 *)(local_res8 + 7) = 0x40000;
        *(undefined4 *)((longlong)local_res8 + 0x3c) = 0xffffffff;
        *(undefined4 *)(local_res8 + 8) = 0x40000;
        *(undefined4 *)((longlong)local_res8 + 0x44) = 1;
        StorPortExtendedFunction
                  (0x1b,param_1,0,0x4d53445f,local_res8,CONCAT44(uVar13,0x48),0,0,local_res10);
      }
      if (local_res8 != (undefined8 *)0x0) {
        StorPortExtendedFunction(1,param_1);
      }
    }
LAB_14000e649:
    if ((*(uint *)(param_1 + 0x2c) & 4) != 0) {
      do {
        plVar3 = *(longlong **)(param_1 + 0x1b0 + uVar9 * 8);
        if (plVar3 != (longlong *)0x0) {
          PortPhyOnline(plVar3);
        }
        uVar6 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar6;
      } while (uVar6 <= *(uint *)(param_1 + 0x184));
    }
    break;
  case 0xc:
    if (0xf < param_3[1]) {
      iVar7 = *(int *)(param_1 + 0x20);
      if (iVar7 != 0) {
        if (param_3[2] != 1) {
          if ((iVar7 == 1) && ((*(uint *)(param_1 + 0x38) & 0x10000) != 0)) {
            StorPortExtendedFunction(0x39,param_1,0,0xffffffff);
          }
          goto LAB_14000e6cf;
        }
        if ((*(uint *)(param_1 + 0x38) & 0x10000) == 0) goto LAB_14000e6cf;
      }
      StorPortExtendedFunction(0x39,param_1,0);
LAB_14000e6cf:
      uVar6 = (uint)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
      uVar8 = (uint)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
      puVar12 = param_3 + 2;
      *(uint *)(param_1 + 0x20) = *puVar12;
      *(uint *)(param_1 + 0x24) = param_3[3];
      if ((*puVar12 == 1) || (iVar7 == 1)) {
        uVar9 = 0;
        do {
          plVar3 = *(longlong **)(param_1 + 0x1b0 + uVar9 * 8);
          if ((plVar3 != (longlong *)0x0) && (((ulonglong)plVar3[0x4a] >> 0xd & 1) != 0)) {
            if (*puVar12 == 1) {
              if ((((ulonglong)plVar3[0x4a] >> 0xe & 1) == 0) &&
                 (1 < *(uint *)(plVar3[0x50] + 0x20))) {
                AhciCancelF1IdleTimer(plVar3);
                AhciSetF1IdleTimer(plVar3);
              }
            }
            else if (((byte)*(undefined4 *)((longlong)plVar3 + 0x254) & 6) == 4) {
              AhciCancelF1IdleTimer(plVar3);
            }
            uVar6 = *(uint *)((longlong)plVar3 + 0x254) & 6;
            if ((uVar6 == 6) || (uVar6 == 4)) {
              *(uint *)((longlong)plVar3 + 0x254) = *(uint *)((longlong)plVar3 + 0x254) | 0x40;
            }
          }
          uVar6 = (uint)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
          uVar8 = (uint)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
          uVar10 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar10;
        } while (uVar10 <= *(uint *)(param_1 + 0x184));
      }
      if (*(char *)(param_1 + 0x18e) == '\0') {
        return 0;
      }
      StorPortExtendedFunction
                (0x55,param_1,0,0,(ulonglong)uVar6 << 0x20,L"Sys Power Hint",4,4,
                 (ulonglong)uVar8 << 0x20,0,L"State",(longlong)(int)param_3[2],L"Latency (ms)",
                 param_3[3]);
      return 0;
    }
    goto switchD_14000e28c_caseD_3;
  case 0x18:
    uVar11 = 3;
    iVar7 = *(int *)(*(longlong *)(*(longlong *)(param_3 + 6) + 0x40) + 0x19c) * 0x60;
    uVar8 = iVar7 + 0x1a0;
    uVar6 = iVar7 + 0x1a8;
    param_3[1] = uVar6;
    if (uVar6 <= param_3[2]) {
      puVar4 = *(undefined4 **)(param_3 + 4);
      *puVar4 = 1;
      puVar4[1] = uVar8;
      memcpy(puVar4 + 2,*(void **)(*(longlong *)(param_3 + 6) + 0x40),(ulonglong)uVar8);
      uVar11 = 0;
    }
    break;
  case 0x19:
    piVar5 = *(int **)(param_3 + 2);
    if ((0x207 < param_3[1]) && (*piVar5 == 1)) {
      param_3[8] = piVar5[1];
      if (param_3[4] < (uint)piVar5[1]) {
        return 3;
      }
      memcpy(*(void **)(param_3 + 6),piVar5 + 2,(ulonglong)(uint)piVar5[1]);
      return 0;
    }
switchD_14000e28c_caseD_3:
    uVar11 = 1;
  }
  return uVar11;
}



===== AhciHwBuildIo @ 14000e900 =====

ulonglong AhciHwBuildIo(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong *puVar6;
  uint uVar7;
  int *piVar8;
  ulonglong uVar9;
  int *piVar10;
  longlong lVar11;
  uint uVar12;
  short *psVar13;
  undefined8 *puVar14;
  byte bVar15;
  int iVar16;
  uint uVar17;
  int *local_res8;
  undefined4 uVar18;
  wchar_t *pwVar19;
  wchar_t *pwVar20;
  wchar_t *pwVar21;
  
  bVar15 = 0;
  if (*(byte *)(param_2 + 2) == 0x28) {
    if (((*(uint *)(param_2 + 0x34) != 0) &&
        (psVar13 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2),
        psVar13 != (short *)0x0)) && (*psVar13 == 1)) {
      bVar15 = *(byte *)(psVar13 + 4);
    }
    uVar12 = *(uint *)(param_2 + 0x14);
    uVar17 = *(uint *)(param_2 + 0x18);
    puVar14 = *(undefined8 **)(param_2 + 0x68);
  }
  else {
    bVar15 = *(byte *)(param_2 + 5);
    uVar12 = (uint)*(byte *)(param_2 + 2);
    uVar17 = *(uint *)(param_2 + 0xc);
    puVar14 = *(undefined8 **)(param_2 + 0x38);
  }
  if (((ulonglong)puVar14 & 0x7f) != 0) {
    puVar14 = (undefined8 *)((longlong)puVar14 + (0x80 - (ulonglong)((uint)puVar14 & 0x7f)));
  }
  memset(puVar14 + 0x220,0,0x18a0);
  piVar8 = (int *)(ulonglong)bVar15;
  *puVar14 = 0;
  puVar14[1] = 0;
  puVar14[2] = 0;
  puVar14[3] = 0;
  puVar14[4] = 0;
  puVar14[5] = 0;
  puVar14[6] = 0;
  puVar14[7] = 0;
  puVar14[8] = 0;
  puVar14[9] = 0;
  puVar14[10] = 0;
  puVar14[0xb] = 0;
  puVar14[0xc] = 0;
  puVar14[0xd] = 0;
  puVar14[0xe] = 0;
  puVar14[0xf] = 0;
  puVar6 = *(ulonglong **)(param_1 + 0x1b0 + (longlong)piVar8 * 8);
  if (((uint)bVar15 <= *(uint *)(param_1 + 0x184)) &&
     (*(longlong *)(param_1 + 0x1b0 + (ulonglong)bVar15 * 8) != 0)) {
    if (uVar12 == 0) {
      if ((puVar6[0x4a] >> 0xc & 1) != 0) {
        AhciPortPowerUp(puVar6);
      }
      goto LAB_14000ea27;
    }
LAB_14000ea14:
    if (uVar12 == 2) {
      if ((uVar17 & 1) != 0) goto LAB_14000eee2;
      goto LAB_14000ea27;
    }
LAB_14000ec3e:
    if (uVar12 == 0x25) {
      if ((*(char *)(param_2 + 2) == '(') && (*(uint *)(param_2 + 0x38) != 0)) {
        uVar12 = 0;
        do {
          uVar17 = *(uint *)(param_2 + 0x78 + (ulonglong)uVar12 * 4);
          if (((0x7f < uVar17) && (uVar17 < *(uint *)(param_2 + 0x10))) &&
             (piVar10 = (int *)((ulonglong)uVar17 + param_2), *piVar10 == 0x62)) goto LAB_14000ec85;
          uVar12 = uVar12 + 1;
        } while (uVar12 < *(uint *)(param_2 + 0x38));
      }
      piVar10 = (int *)0x0;
LAB_14000ec85:
      uVar12 = piVar10[4];
      piVar8 = (int *)(ulonglong)uVar12;
      if (((uVar12 & 1) != 0) && (piVar10[3] == 9)) {
        if (*(char *)(param_2 + 2) == '(') {
          uVar12 = *(uint *)(param_2 + 0x3c);
        }
        else {
          uVar12 = *(uint *)(param_2 + 0x10);
        }
        piVar8 = (int *)0x0;
        if (0x17 < uVar12) {
          if (*(char *)(param_2 + 2) == '(') {
            lVar11 = *(longlong *)(param_2 + 0x40);
          }
          else {
            lVar11 = *(longlong *)(param_2 + 0x18);
          }
          uVar12 = *(uint *)(param_1 + 0x2c);
          *(uint *)(param_1 + 0x2c) = (*(int *)(lVar11 + 4) << 7 ^ uVar12) & 0x800 ^ uVar12;
          *(undefined1 *)(param_2 + 3) = 1;
          piVar8 = (int *)(ulonglong)uVar12;
        }
      }
    }
    goto LAB_14000eee2;
  }
  if (uVar12 != 0) goto LAB_14000ea14;
LAB_14000ea27:
  if ((*(uint *)(param_1 + 0x184) < (uint)bVar15) ||
     (*(longlong *)(param_1 + 0x1b0 + (ulonglong)bVar15 * 8) == 0)) {
    *(undefined1 *)(param_2 + 3) = 8;
    piVar8 = *(int **)(param_1 + 0x2c0);
    local_res8 = (int *)0x0;
    if ((piVar8 != (int *)0x0) && (uVar7 = 0, *(uint *)(param_1 + 0x2c8) != 0)) {
      piVar10 = piVar8;
      do {
        if (*piVar10 == 0x25) {
          piVar8 = piVar8 + (ulonglong)uVar7 * 8;
          if (piVar8 != (int *)0x0) {
            StorPortQuerySystemTime(&local_res8);
            uVar7 = piVar8[7];
            uVar5 = piVar8[6];
            if ((*(longlong *)(piVar8 + 2) == 0) ||
               (*(ulonglong *)(piVar8 + 4) <=
                (ulonglong)((longlong)local_res8 - *(longlong *)(piVar8 + 2)))) {
              if (uVar7 < uVar5) {
                iVar16 = 0;
                *(int **)(piVar8 + 2) = local_res8;
                piVar8[7] = 1;
              }
              else {
                *(int **)(piVar8 + 2) = local_res8;
                iVar16 = uVar7 - uVar5;
                piVar8[7] = 1;
              }
              goto LAB_14000edd7;
            }
            piVar8[7] = uVar7 + 1;
            if (uVar5 <= uVar7) {
              piVar8 = local_res8;
              goto LAB_14000eee2;
            }
            iVar16 = 0;
            goto LAB_14000edd7;
          }
          break;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 8;
      } while (uVar7 < *(uint *)(param_1 + 0x2c8));
    }
    iVar16 = 0;
LAB_14000edd7:
    uVar2 = *(undefined4 *)(param_1 + 8);
    uVar3 = *(undefined4 *)(param_1 + 4);
    uVar4 = *(undefined4 *)(param_1 + 0x180);
    uVar1 = *(undefined1 *)(param_2 + 3);
    pwVar21 = L"SrbFlags";
    pwVar20 = L"Function";
    pwVar19 = L"Srb sent to invalid port in BuildIo";
    uVar18 = 0x25;
  }
  else {
    uVar7 = *(uint *)(param_1 + 0x2c) >> 0xb;
    if (((uVar7 & 1) == 0) ||
       (uVar7 = *(uint *)(*(longlong *)(param_1 + 400) + 0x10), uVar7 != 0xffffffff)) {
      piVar8 = (int *)(ulonglong)uVar7;
      if (uVar12 == 0) {
        piVar8 = (int *)SCSItoATA(*(ulonglong **)(param_1 + 0x1b0 + (ulonglong)bVar15 * 8),param_2);
      }
      else {
        if (uVar12 != 2) goto LAB_14000ec3e;
        if ((uVar17 & 1) != 0) goto LAB_14000eee2;
        piVar8 = (int *)IOCTLtoATA(*(longlong **)(param_1 + 0x1b0 + (ulonglong)bVar15 * 8),param_2);
      }
      if (*(short *)(puVar14 + 0x220) == 0) goto LAB_14000eee2;
      piVar8 = (int *)puVar14[0x227];
      if (piVar8 == (int *)0x0) {
        piVar8 = (int *)IsDataTransferNeeded(param_2);
        if ((char)piVar8 == '\0') goto LAB_14000eee2;
        piVar8 = (int *)StorPortGetScatterGatherList(param_1,param_2);
        puVar14[0x227] = piVar8;
        if (piVar8 == (int *)0x0) goto LAB_14000eee2;
      }
      if (*piVar8 << 4 != 0) {
        piVar8 = memset(puVar14 + 0x10,0,(ulonglong)(uint)(*piVar8 << 4));
      }
      goto LAB_14000eee2;
    }
    *(undefined1 *)(param_2 + 3) = 8;
    piVar8 = *(int **)(param_1 + 0x2c0);
    local_res8 = (int *)0x0;
    if ((piVar8 != (int *)0x0) && (uVar7 = 0, *(uint *)(param_1 + 0x2c8) != 0)) {
      piVar10 = piVar8;
      do {
        if (*piVar10 == 0x33) {
          piVar8 = piVar8 + (ulonglong)uVar7 * 8;
          if (piVar8 != (int *)0x0) {
            StorPortQuerySystemTime(&local_res8);
            uVar7 = piVar8[7];
            uVar5 = piVar8[6];
            if ((*(longlong *)(piVar8 + 2) == 0) ||
               (*(ulonglong *)(piVar8 + 4) <=
                (ulonglong)((longlong)local_res8 - *(longlong *)(piVar8 + 2)))) {
              *(int **)(piVar8 + 2) = local_res8;
              iVar16 = uVar7 - uVar5;
              piVar8[7] = 1;
              if (uVar7 < uVar5) {
                iVar16 = 0;
              }
            }
            else {
              piVar8[7] = uVar7 + 1;
              piVar8 = local_res8;
              if (uVar5 <= uVar7) goto LAB_14000eee2;
              iVar16 = 0;
            }
            goto LAB_14000eab8;
          }
          break;
        }
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 8;
      } while (uVar7 < *(uint *)(param_1 + 0x2c8));
    }
    iVar16 = 0;
LAB_14000eab8:
    uVar2 = *(undefined4 *)(param_1 + 8);
    uVar3 = *(undefined4 *)(param_1 + 4);
    uVar4 = *(undefined4 *)(param_1 + 0x180);
    uVar1 = *(undefined1 *)(param_2 + 3);
    pwVar21 = L"srbFlags";
    pwVar20 = L"function";
    pwVar19 = L"Adapter removed during BuildIo";
    uVar18 = 0x33;
  }
  piVar8 = (int *)StorPortExtendedFunction
                            (0x57,param_1,0,1,uVar18,pwVar19,0x10,2,0,param_2,pwVar20,uVar12,pwVar21
                             ,uVar17,L"SrbStatus",uVar1,L"ThrottleCount",iVar16,L"PathId",bVar15,
                             L"PortImplemented",uVar4,L"SystemIoBusNumber",uVar3,L"SlotNumber",uVar2
                            );
LAB_14000eee2:
  if (*(char *)(param_2 + 3) == '\0') {
    return CONCAT71((int7)((ulonglong)piVar8 >> 8),1);
  }
  uVar9 = StorPortNotification(0,param_1,param_2);
  return uVar9 & 0xffffffffffffff00;
}



===== AhciHwUnitControl @ 14000eff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AhciHwUnitControl(longlong param_1,undefined4 param_2,uint *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  ulonglong *puVar5;
  longlong *plVar6;
  longlong lVar7;
  byte bVar8;
  int iVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  undefined1 uVar16;
  uint uVar17;
  ulonglong *puVar18;
  uint uVar19;
  int iVar20;
  char cVar21;
  size_t _Size;
  undefined1 local_268 [32];
  ulonglong *local_248;
  ulonglong local_240;
  undefined8 local_238;
  char local_228 [8];
  ulonglong local_220;
  ulonglong local_218;
  ulonglong local_210 [3];
  ulonglong uStack_1f8;
  longlong local_1f0;
  longlong local_1e8;
  ulonglong local_1e0;
  longlong local_1d8;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined1 local_1c0 [32];
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined1 local_188 [32];
  undefined8 local_168;
  undefined1 local_160 [32];
  undefined8 local_140;
  undefined1 local_138 [32];
  undefined8 local_118;
  undefined1 local_110 [32];
  ulonglong local_f0;
  undefined1 local_e8 [32];
  longlong local_c8;
  undefined1 local_c0 [32];
  longlong local_a0;
  undefined1 local_98 [32];
  ulonglong local_78;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_268;
  uVar19 = 0;
  switch(param_2) {
  case 0:
    uVar19 = *param_3;
    if (uVar19 != 0) {
      *(undefined1 *)(param_3 + 1) = 1;
    }
    if (2 < uVar19) {
      *(undefined1 *)((longlong)param_3 + 6) = 1;
    }
    if (3 < uVar19) {
      *(undefined1 *)((longlong)param_3 + 7) = 1;
    }
    if (4 < uVar19) {
      *(undefined1 *)(param_3 + 2) = 1;
    }
    if (6 < uVar19) {
      *(undefined1 *)((longlong)param_3 + 10) = 1;
    }
    if (7 < uVar19) {
      *(undefined1 *)((longlong)param_3 + 0xb) = 1;
    }
    if (10 < uVar19) {
      *(undefined1 *)((longlong)param_3 + 0xe) = 1;
    }
    if (uVar19 < 0xe) {
      return 0;
    }
    *(undefined1 *)((longlong)param_3 + 0x11) = 1;
    return 0;
  case 2:
    bVar8 = (byte)param_3[2];
    if (((uint)bVar8 <= *(uint *)(param_1 + 0x184)) &&
       (*(longlong *)(param_1 + 0x1b0 + (ulonglong)bVar8 * 8) != 0)) {
      puVar5 = *(ulonglong **)(param_1 + 0x1b0 + (ulonglong)bVar8 * 8);
      if (puVar5 == (ulonglong *)0x0) {
        return 0;
      }
      AhciDeviceInitialize(puVar5);
      return 0;
    }
    break;
  case 3:
    bVar8 = *(byte *)(*(longlong *)param_3 + 8);
    if (((uint)bVar8 <= *(uint *)(param_1 + 0x184)) &&
       (*(longlong *)(param_1 + 0x1b0 + (ulonglong)bVar8 * 8) != 0)) {
      puVar5 = *(ulonglong **)(param_1 + 0x1b0 + (ulonglong)bVar8 * 8);
      if (param_3[3] == 1) {
        AhciPortPowerUp(puVar5);
        *(undefined4 *)((longlong)puVar5 + 0x28c) = 1;
        return 0;
      }
      if (param_3[3] == 4) {
        AhciCancelF1IdleTimer(puVar5);
        AhciPortPowerDown(puVar5);
        *(undefined4 *)((longlong)puVar5 + 0x28c) = 4;
        return 0;
      }
    }
    break;
  case 4:
    uVar12 = *(ulonglong *)(param_3 + 2);
    local_228[0] = '\0';
    bVar8 = *(byte *)(uVar12 + 8);
    if (*(uint *)(param_1 + 0x184) < (uint)bVar8) {
      return 1;
    }
    if (*(longlong *)(param_1 + 0x1b0 + (ulonglong)bVar8 * 8) == 0) {
      return 1;
    }
    puVar5 = *(ulonglong **)(param_1 + 0x1b0 + (ulonglong)bVar8 * 8);
    iVar20 = 0;
    local_220 = uVar12;
    if ((char)param_3[4] == '\0') {
      if (puVar5[0x50] != 0) {
        StorPortExtendedFunction(1,param_1);
        puVar5[0x50] = 0;
      }
      puVar5[0x4a] = puVar5[0x4a] & 0xffffffffffff9fff;
      return 0;
    }
    if ((puVar5[0x4a] >> 0xd & 1) != 0) {
      return 1;
    }
    if (((*(int *)(param_1 + 0x20) != 0) &&
        (uVar10 = DeviceIncursNoSeekPenalty((longlong)puVar5), (char)uVar10 != '\0')) ||
       ((uVar10 = IsAhciDEVSLPSupported(puVar5), (char)uVar10 != '\0' &&
        (((byte)puVar5[0x4b] & 0xc) != 8)))) {
      iVar20 = 1;
    }
    cVar21 = (char)iVar20;
    puVar18 = puVar5 + 0x50;
    uVar19 = (iVar20 + 3) * 0x20;
    local_218 = CONCAT44(local_218._4_4_,uVar19);
    if (*puVar18 == 0) {
      local_248 = puVar18;
      iVar9 = StorPortExtendedFunction(0,param_1,uVar19,0x69636841);
      if (iVar9 != 0) goto LAB_14000f4a4;
      uVar19 = (uint)local_218;
    }
    pvVar4 = (void *)*puVar18;
    AhciZeroMemory(pvVar4,uVar19);
    *(undefined4 *)*puVar18 = 3;
    *(undefined4 *)(*puVar18 + 4) = 0x18;
    *(undefined4 *)(*puVar18 + 8) = 1;
    *(uint *)(*puVar18 + 0xc) = *(uint *)(*puVar18 + 0xc) | 8;
    if (((*(uint *)(*puVar5 + 0x1a8) & 0x4004000) == 0x4004000) &&
       ((*(ushort *)(puVar5[0x18] + 0x98) >> 9 & 1) != 0)) {
      *(uint *)(*puVar18 + 0xc) = *(uint *)(*puVar18 + 0xc) | 0x100;
    }
    uVar12 = DeviceIncursSeekPenalty((longlong)puVar5);
    if ((char)uVar12 == '\0') {
      if (((*(int *)(param_1 + 0x20) != 0) &&
          (uVar12 = DeviceIncursNoSeekPenalty((longlong)puVar5), (char)uVar12 != '\0')) &&
         ((*(uint *)(param_1 + 0x38) & 0x10000) != 0)) {
        *(uint *)(puVar5[0x50] + 0xc) = *(uint *)(puVar5[0x50] + 0xc) | 0x10;
        *(int *)(puVar5[0x50] + 0x10) = (int)puVar5[0x4e];
      }
    }
    else {
      *(uint *)(puVar5[0x50] + 0xc) = *(uint *)(puVar5[0x50] + 0xc) | 0x20;
      *(int *)(puVar5[0x50] + 0x14) = *(int *)((longlong)puVar5 + 0x26c) * 1000;
    }
    *(undefined4 *)((longlong)pvVar4 + 0x18) = 2;
    *(undefined4 *)((longlong)pvVar4 + 0x1c) = 0x28;
    *(undefined4 *)((longlong)pvVar4 + 0x28) = 0x585d326b;
    *(undefined4 *)((longlong)pvVar4 + 0x2c) = 0x40880b3a;
    *(undefined4 *)((longlong)pvVar4 + 0x30) = 0xb0883989;
    *(undefined4 *)((longlong)pvVar4 + 0x34) = 0xbe58690f;
    *(undefined4 *)((longlong)pvVar4 + 0x24) = 0;
    *(undefined8 *)((longlong)pvVar4 + 0x38) = 0;
    *(int *)((longlong)pvVar4 + 0x20) = iVar20 + 1;
    *(undefined4 *)((longlong)pvVar4 + 0x40) = 1;
    *(undefined4 *)((longlong)pvVar4 + 0x44) = 0x20;
    *(undefined8 *)((longlong)pvVar4 + 0x48) = 0;
    *(undefined8 *)((longlong)pvVar4 + 0x50) = 0;
    *(undefined4 *)((longlong)pvVar4 + 0x58) = 0xffffffff;
    if ((puVar5[0x4b] & 0x100) != 0) {
      *(uint *)(puVar5[0x50] + 0xc) = *(uint *)(puVar5[0x50] + 0xc) | 2;
    }
    if (cVar21 != '\0') {
      *(undefined4 *)((longlong)pvVar4 + 0x60) = 1;
      *(undefined4 *)((longlong)pvVar4 + 100) = 0x20;
      bVar8 = (byte)(puVar5[0x2f] >> 8);
      if (-1 < (longlong)puVar5[0x2f]) {
        bVar8 = 0;
      }
      if (bVar8 == 0) {
        bVar8 = 0x14;
      }
      *(ulonglong *)((longlong)pvVar4 + 0x68) = (ulonglong)bVar8 * 10000;
      uVar12 = puVar5[0x2f];
      uVar10 = uVar12 >> 8;
      bVar8 = (byte)uVar12 & 0x1f;
      if (-1 < (longlong)uVar12) {
        bVar8 = 0;
      }
      if (bVar8 == 0) {
        bVar8 = 10;
      }
      if ((-1 < (longlong)uVar12) || ((char)(uVar12 >> 8) == '\0')) {
        uVar10 = 0x14;
      }
      *(undefined4 *)((longlong)pvVar4 + 0x78) = 0xffffffff;
      *(undefined4 *)((longlong)pvVar4 + 0x3c) = 1;
      *(ulonglong *)((longlong)pvVar4 + 0x70) = ((uVar10 & 0xff) + (ulonglong)bVar8 + 1) * 10000;
    }
    if ((((*(uint *)(param_1 + 0x38) & 0x10000) == 0) || ((*(uint *)(param_1 + 0x2c) & 0x100) == 0))
       || (((puVar5[0x4a] >> 0x10 & 1) == 0 || (cVar21 == '\0')))) {
      uVar19 = *(uint *)(param_1 + 0x2c);
      if ((((uVar19 >> 8 & 1) != 0) && (cVar21 != '\0')) && ((uVar19 >> 10 & 1) == 0)) {
        *(uint *)(param_1 + 0x2c) = uVar19 | 0x400;
        StorPortExtendedFunction(0x39,param_1,0,0xffffffff);
      }
    }
    else {
      *(undefined4 *)((longlong)pvVar4 + 0x38) = 1;
    }
    uVar12 = local_220;
    local_248 = (ulonglong *)local_228;
    iVar9 = StorPortExtendedFunction(0x30,param_1,local_220,puVar5[0x50]);
    if (local_228[0] == '\0') {
      uVar10 = puVar5[0x4a] & 0xffffffffffff7fff;
    }
    else {
      uVar10 = puVar5[0x4a] | 0x8000;
    }
    puVar5[0x4a] = uVar10;
LAB_14000f4a4:
    if (iVar9 != 0) {
      StorPortExtendedFunction(1,param_1,puVar5[0x50]);
      puVar5[0x50] = 0;
      puVar5[0x4a] = puVar5[0x4a] & 0xffffffffffff9fff;
      *(undefined1 *)(puVar5 + 0x51) = 0;
      return 1;
    }
    puVar5[0x4a] = puVar5[0x4a] | 0x6000;
    if (cVar21 != '\0') {
      local_248 = (ulonglong *)0x0;
      StorPortExtendedFunction(0x33,param_1,uVar12);
      local_248 = (ulonglong *)0xffffffffffffffff;
      StorPortExtendedFunction(0x34,param_1,uVar12);
    }
    *(undefined1 *)(puVar5 + 0x51) = 0;
    return 0;
  case 6:
    bVar8 = *(byte *)(*(longlong *)(param_3 + 2) + 8);
    if ((((uint)bVar8 <= *(uint *)(param_1 + 0x184)) &&
        (*(longlong *)(param_1 + 0x1b0 + (ulonglong)bVar8 * 8) != 0)) &&
       ((*(ulonglong *)(*(longlong *)(param_1 + 0x1b0 + (ulonglong)bVar8 * 8) + 0x250) >> 0xd & 1)
        != 0)) {
      puVar5 = *(ulonglong **)
                (param_1 + 0x1b0 + (ulonglong)*(byte *)(*(longlong *)(param_3 + 2) + 8) * 8);
      if ((char)param_3[5] == '\0') {
        uVar12 = puVar5[0x4a] & 0xffffffffffffbfff;
      }
      else {
        uVar12 = puVar5[0x4a] | 0x4000;
      }
      puVar5[0x4a] = uVar12;
      if ((char)param_3[5] == '\0') {
        uVar12 = PartialToSlumberTransitionIsAllowed(puVar5,(uint *)0x0);
        if ((char)uVar12 != '\0') {
          local_240 = (ulonglong)(uint)((int)puVar5[0x4f] * 1000);
          local_238 = 20000;
          local_248 = puVar5;
          StorPortExtendedFunction(0x21,*puVar5,puVar5[0x154],AhciAutoPartialToSlumber);
        }
        uVar19 = *(uint *)((longlong)puVar5 + 0x254);
        if (((uVar19 & 0x40) != 0) && (((uVar19 & 6) == 6 || ((uVar19 & 6) == 4)))) {
          *(uint *)((longlong)puVar5 + 0x254) = uVar19 & 0xffffffbf;
          uVar11 = AhciPortSetDevslpIdleTimeout((longlong *)puVar5);
          if ((char)uVar11 == '\0') {
            *(uint *)((longlong)puVar5 + 0x254) = *(uint *)((longlong)puVar5 + 0x254) | 0x40;
          }
        }
        uVar19 = *(uint *)((longlong)puVar5 + 0x254);
        if (((uVar19 & 0x200) != 0) && ((uVar19 & 6) != 0)) {
          *(uint *)((longlong)puVar5 + 0x254) = uVar19 & 0xfffffdff;
          uVar11 = P_NotRunning((longlong *)puVar5,puVar5[0x129]);
          if ((char)uVar11 != '\0') {
            if ((*(uint *)(puVar5[0x129] + 0x44) & 1) != 0) {
              *(uint *)(puVar5[0x129] + 0x44) = *(uint *)(puVar5[0x129] + 0x44) & 0xfffffffe;
              LOCK();
              UNLOCK();
            }
            uVar12 = puVar5[0x2f];
            bVar8 = (byte)(uVar12 >> 8);
            if (-1 < (longlong)uVar12) {
              bVar8 = 0;
            }
            if (bVar8 == 0) {
              bVar8 = 0x14;
            }
            iVar20 = 0;
            uVar19 = (uint)bVar8 << 2 | *(uint *)(puVar5[0x129] + 0x44) & 0xfffffc03;
            bVar8 = 0;
            if ((longlong)uVar12 < 0) {
              iVar20 = (int)uVar12;
              bVar8 = (byte)uVar12 & 0x1f;
            }
            if (bVar8 == 0) {
              iVar20 = 10;
            }
            *(uint *)(puVar5[0x129] + 0x44) = (iVar20 << 10 ^ uVar19) & 0x7c00 ^ uVar19;
            LOCK();
            UNLOCK();
            if (((byte)*(undefined4 *)((longlong)puVar5 + 0x254) & 6) == 4) {
              *(uint *)(puVar5[0x129] + 0x44) = *(uint *)(puVar5[0x129] + 0x44) | 1;
              LOCK();
              UNLOCK();
            }
            uVar12 = *puVar5;
            local_210[0] = 3;
            local_210[1] = 0;
            local_210[2] = 0;
            uStack_1f8 = 0;
            if (((char)*(undefined4 *)(uVar12 + 0x2c) < '\0') && ((int)puVar5[0x48] != -1)) {
              local_220 = local_220 & 0xffffffff00000000;
              StorPortExtendedFunction(0xb,uVar12,(int)puVar5[0x48],&local_220);
              uStack_1f8 = CONCAT71(uStack_1f8._1_7_,(undefined1)local_220);
              uVar16 = (undefined1)local_220;
            }
            else {
              local_248 = local_210;
              StorPortNotification(0x1003,uVar12,3);
              uVar16 = (undefined1)uStack_1f8;
            }
            uVar12 = *puVar5;
            *(undefined4 *)(puVar5 + 0x49) = 0x11;
            *(byte *)((longlong)puVar5 + 0x24d) = *(byte *)((longlong)puVar5 + 0x24d) & 0xfe | 2;
            *(undefined1 *)((longlong)puVar5 + 0x24c) = 0;
            *(undefined2 *)((longlong)puVar5 + 0x24e) = 0;
            if (((char)*(undefined4 *)(uVar12 + 0x2c) < '\0') && ((int)puVar5[0x48] != -1)) {
              StorPortExtendedFunction(0xc,uVar12,(int)puVar5[0x48],uVar16);
              P_Running(puVar5,'\0');
              AhciSetF1IdleTimer((longlong *)puVar5);
              return 0;
            }
            StorPortNotification(0x1004,uVar12,local_210);
            P_Running(puVar5,'\0');
            AhciSetF1IdleTimer((longlong *)puVar5);
            return 0;
          }
          *(uint *)((longlong)puVar5 + 0x254) = *(uint *)((longlong)puVar5 + 0x254) | 0x200;
        }
        AhciSetF1IdleTimer((longlong *)puVar5);
        return 0;
      }
      local_238 = 0;
      local_240 = 0;
      local_248 = puVar5;
      StorPortExtendedFunction(0x21,*puVar5,puVar5[0x154],AhciAutoPartialToSlumber);
      AhciCancelF1IdleTimer(puVar5);
      LOCK();
      puVar18 = puVar5 + 0x59;
      uVar12 = *puVar18;
      *(uint *)puVar18 = (uint)*puVar18 & 0xfffffffd;
      UNLOCK();
      LOCK();
      puVar18 = puVar5 + 0x59;
      uVar10 = *puVar18;
      *(uint *)puVar18 = (uint)*puVar18 & 0xfffffffe;
      UNLOCK();
      if (((uint)uVar12 >> 1 & 1) != 0) {
        PortBusChangeProcess(puVar5);
      }
      if ((uVar10 & 1) == 0) {
        return 0;
      }
      if ((*(uint *)((longlong)puVar5 + 0x254) & 6) != 0) {
        *(uint *)((longlong)puVar5 + 0x254) = *(uint *)((longlong)puVar5 + 0x254) | 0x240;
      }
      RecordExecutionHistory((longlong *)puVar5,0x10050041);
      IssuePreservedSettingCommands((longlong *)puVar5);
      if (puVar5[0x135] == 0) {
        return 0;
      }
      puVar18 = puVar5 + 0x12e;
      uVar12 = GetSrbExtension((longlong)puVar18);
      if (*(short *)(uVar12 + 0x1100) == 0) {
        return 0;
      }
      AhciProcessIo((longlong *)puVar5,(longlong *)puVar18,0);
      ActivateQueue((longlong *)puVar5,'\0');
      return 0;
    }
    break;
  case 7:
    puVar5 = *(ulonglong **)
              (param_1 + 0x1b0 + (ulonglong)*(byte *)(*(longlong *)(param_3 + 2) + 8) * 8);
    if ((((uint)*(byte *)(*(longlong *)(param_3 + 2) + 8) <= *(uint *)(param_1 + 0x184)) &&
        (puVar5 != (ulonglong *)0x0)) && ((puVar5[0x4a] >> 0xd & 1) != 0)) {
      *(char *)(puVar5 + 0x51) = (char)param_3[5];
      if (param_3[5] == 0) {
        AhciCancelF1IdleTimer(puVar5);
        PortPhyOnline((longlong *)puVar5);
        AhciSetF1IdleTimer((longlong *)puVar5);
        return 0;
      }
      if (param_3[5] == 1) {
        local_238 = 0;
        local_240 = 0;
        local_248 = puVar5;
        StorPortExtendedFunction(0x21,param_1,puVar5[0x154],AhciAutoPartialToSlumber);
        uVar12 = IsAhciDEVSLPSupported(puVar5);
        if ((char)uVar12 == '\0') {
          PortSlumber(puVar5);
          return 0;
        }
        PortDevSleep(puVar5);
        return 0;
      }
    }
    break;
  case 10:
    bVar8 = (byte)param_3[2];
    local_210[0] = 3;
    local_210[1] = 0;
    local_210[2] = 0;
    uStack_1f8 = 0;
    if (*(uint *)(param_1 + 0x184) < (uint)bVar8) {
      return 0;
    }
    if (*(longlong *)(param_1 + 0x1b0 + (ulonglong)bVar8 * 8) == 0) {
      return 0;
    }
    plVar6 = *(longlong **)(param_1 + 0x1b0 + (ulonglong)bVar8 * 8);
    AhciInterruptSpinlockAcquire(param_1,(int)plVar6[0x48],(longlong)local_210);
    uVar17 = *(uint *)((longlong)plVar6 + 0x2dc);
    *(uint *)(plVar6 + 0x5c) = uVar17;
    *(undefined4 *)((longlong)plVar6 + 0x2dc) = 0;
    *(uint *)((longlong)plVar6 + 0x2cc) = *(uint *)((longlong)plVar6 + 0x2cc) & ~uVar17;
    *(undefined8 *)((longlong)plVar6 + 0x2e4) = 0;
    *(undefined4 *)((longlong)plVar6 + 0x2ec) = 0;
    AhciCompleteIssuedSRBs(plVar6,'\b');
    AhciPortFailAllIos(plVar6,8);
    if (((char)*(undefined4 *)(param_1 + 0x2c) < '\0') && ((int)plVar6[0x48] != -1)) {
      StorPortExtendedFunction(0xc,param_1,(int)plVar6[0x48],uStack_1f8 & 0xff);
    }
    else {
      StorPortNotification(0x1004,param_1,local_210);
    }
    *(int *)(plVar6 + 0x8bd) = (int)plVar6[0x8bd] + 1;
    local_220 = 0;
    if ((int)plVar6[3] == 2) {
      return 0;
    }
    StorPortQuerySystemTime(&local_220);
    lVar15 = plVar6[0x8bc];
    uVar1 = *(undefined4 *)((longlong)plVar6 + 0x45d4);
    lVar14 = plVar6[0x8ba];
    plVar6[0x8be] = local_220;
    local_1e0 = (ulonglong)*(uint *)(plVar6 + 0x8bd);
    local_1e8 = plVar6[0x49];
    local_1f0 = plVar6[0x4a];
    local_218 = (ulonglong)*(uint *)((longlong)plVar6 + 0xb4);
    uVar2 = *(undefined4 *)((longlong)plVar6 + 0x45e4);
    uVar3 = *(undefined4 *)((longlong)plVar6 + 0x45dc);
    lVar7 = plVar6[0x8bb];
    local_1d8 = *plVar6;
    memset(&local_1c8,0,0x180);
    uVar17 = 0;
    local_1c8 = 1;
    lVar13 = 0;
    local_1c4 = 9;
    do {
      _Size = 0x20;
      if ("ScsiUnitSurpriseRemoval"[lVar13] == '\0') goto LAB_14000fc35;
      if ("ScsiUnitSurpriseRemoval"[lVar13 + 1] == '\0') {
        uVar17 = uVar17 + 1;
LAB_14000fc2d:
        if (uVar17 < 0x20) goto LAB_14000fc35;
        break;
      }
      if ("ScsiUnitSurpriseRemoval"[lVar13 + 2] == '\0') {
        uVar17 = uVar17 + 2;
        goto LAB_14000fc2d;
      }
      if ("ScsiUnitSurpriseRemoval"[lVar13 + 3] == '\0') {
        uVar17 = uVar17 + 3;
        goto LAB_14000fc2d;
      }
      uVar17 = uVar17 + 4;
      lVar13 = lVar13 + 4;
    } while (uVar17 < 0x20);
    uVar17 = 0x20;
LAB_14000fc35:
    memcpy(local_1c0,"ScsiUnitSurpriseRemoval",(ulonglong)uVar17);
    uVar17 = 0;
    local_1a0 = 1;
    lVar13 = 0;
    local_19c = 1;
    do {
      if ("PortReset|PortErrorRecovery"[lVar13] == '\0') goto LAB_14000fc9d;
      if ("PortReset|PortErrorRecovery"[lVar13 + 1] == '\0') {
        uVar17 = uVar17 + 1;
LAB_14000fc95:
        if (uVar17 < 0x20) goto LAB_14000fc9d;
        break;
      }
      if ("PortReset|PortErrorRecovery"[lVar13 + 2] == '\0') {
        uVar17 = uVar17 + 2;
        goto LAB_14000fc95;
      }
      if ("PortReset|PortErrorRecovery"[lVar13 + 3] == '\0') {
        uVar17 = uVar17 + 3;
        goto LAB_14000fc95;
      }
      uVar17 = uVar17 + 4;
      lVar13 = lVar13 + 4;
    } while (uVar17 < 0x20);
    uVar17 = 0x20;
LAB_14000fc9d:
    memcpy(local_188,"PortReset|PortErrorRecovery",(ulonglong)uVar17);
    uVar17 = 0;
    lVar13 = 0;
    do {
      if ("StartFail|NonQErrorRecovery"[lVar13] == '\0') goto LAB_14000fcfd;
      if ("StartFail|NonQErrorRecovery"[lVar13 + 1] == '\0') {
        uVar17 = uVar17 + 1;
LAB_14000fcf5:
        if (uVar17 < 0x20) goto LAB_14000fcfd;
        break;
      }
      if ("StartFail|NonQErrorRecovery"[lVar13 + 2] == '\0') {
        uVar17 = uVar17 + 2;
        goto LAB_14000fcf5;
      }
      if ("StartFail|NonQErrorRecovery"[lVar13 + 3] == '\0') {
        uVar17 = uVar17 + 3;
        goto LAB_14000fcf5;
      }
      uVar17 = uVar17 + 4;
      lVar13 = lVar13 + 4;
    } while (uVar17 < 0x20);
    uVar17 = 0x20;
LAB_14000fcfd:
    local_168 = CONCAT44((int)lVar14,(int)lVar7);
    memcpy(local_160,"StartFail|NonQErrorRecovery",(ulonglong)uVar17);
    uVar17 = 0;
    lVar14 = 0;
    do {
      if ("NCQError|NCQErrorComplete"[lVar14] == '\0') goto LAB_14000fd5d;
      if ("NCQError|NCQErrorComplete"[lVar14 + 1] == '\0') {
        uVar17 = uVar17 + 1;
LAB_14000fd55:
        if (uVar17 < 0x20) goto LAB_14000fd5d;
        break;
      }
      if ("NCQError|NCQErrorComplete"[lVar14 + 2] == '\0') {
        uVar17 = uVar17 + 2;
        goto LAB_14000fd55;
      }
      if ("NCQError|NCQErrorComplete"[lVar14 + 3] == '\0') {
        uVar17 = uVar17 + 3;
        goto LAB_14000fd55;
      }
      uVar17 = uVar17 + 4;
      lVar14 = lVar14 + 4;
    } while (uVar17 < 0x20);
    uVar17 = 0x20;
LAB_14000fd5d:
    local_140 = CONCAT44(uVar1,uVar3);
    memcpy(local_138,"NCQError|NCQErrorComplete",(ulonglong)uVar17);
    uVar17 = 0;
    lVar14 = 0;
    do {
      if ("PortDriverResetCount"[lVar14] == '\0') goto LAB_14000fdbd;
      if ("PortDriverResetCount"[lVar14 + 1] == '\0') {
        uVar17 = uVar17 + 1;
LAB_14000fdb5:
        if (uVar17 < 0x20) goto LAB_14000fdbd;
        break;
      }
      if ("PortDriverResetCount"[lVar14 + 2] == '\0') {
        uVar17 = uVar17 + 2;
        goto LAB_14000fdb5;
      }
      if ("PortDriverResetCount"[lVar14 + 3] == '\0') {
        uVar17 = uVar17 + 3;
        goto LAB_14000fdb5;
      }
      uVar17 = uVar17 + 4;
      lVar14 = lVar14 + 4;
    } while (uVar17 < 0x20);
    uVar17 = 0x20;
LAB_14000fdbd:
    local_118 = CONCAT44((int)lVar15,uVar2);
    memcpy(local_110,"PortDriverResetCount",(ulonglong)uVar17);
    local_f0 = local_218;
    uVar17 = 0;
    lVar15 = 0;
    do {
      if ("StateFlags"[lVar15] == '\0') goto LAB_14000fe1d;
      if ("StateFlags"[lVar15 + 1] == '\0') {
        uVar17 = uVar17 + 1;
LAB_14000fe15:
        if (uVar17 < 0x20) goto LAB_14000fe1d;
        break;
      }
      if ("StateFlags"[lVar15 + 2] == '\0') {
        uVar17 = uVar17 + 2;
        goto LAB_14000fe15;
      }
      if ("StateFlags"[lVar15 + 3] == '\0') {
        uVar17 = uVar17 + 3;
        goto LAB_14000fe15;
      }
      uVar17 = uVar17 + 4;
      lVar15 = lVar15 + 4;
    } while (uVar17 < 0x20);
    uVar17 = 0x20;
LAB_14000fe1d:
    memcpy(local_e8,"StateFlags",(ulonglong)uVar17);
    local_c8 = local_1f0;
    uVar17 = 0;
    lVar15 = 0;
    do {
      if ("StartState"[lVar15] == '\0') goto LAB_14000fe81;
      if ("StartState"[lVar15 + 1] == '\0') {
        uVar17 = uVar17 + 1;
LAB_14000fe79:
        if (uVar17 < 0x20) goto LAB_14000fe81;
        break;
      }
      if ("StartState"[lVar15 + 2] == '\0') {
        uVar17 = uVar17 + 2;
        goto LAB_14000fe79;
      }
      if ("StartState"[lVar15 + 3] == '\0') {
        uVar17 = uVar17 + 3;
        goto LAB_14000fe79;
      }
      uVar17 = uVar17 + 4;
      lVar15 = lVar15 + 4;
    } while (uVar17 < 0x20);
    uVar17 = 0x20;
LAB_14000fe81:
    memcpy(local_c0,"StartState",(ulonglong)uVar17);
    local_a0 = local_1e8;
    lVar15 = 0;
    do {
      if ("TotalCountSurpriseRemove"[lVar15] == '\0') {
LAB_14000fedf:
        _Size = (size_t)uVar19;
        break;
      }
      if ("TotalCountSurpriseRemove"[lVar15 + 1] == '\0') {
        uVar19 = uVar19 + 1;
LAB_14000feda:
        if (uVar19 < 0x20) goto LAB_14000fedf;
        break;
      }
      if ("TotalCountSurpriseRemove"[lVar15 + 2] == '\0') {
        uVar19 = uVar19 + 2;
        goto LAB_14000feda;
      }
      if ("TotalCountSurpriseRemove"[lVar15 + 3] == '\0') {
        uVar19 = uVar19 + 3;
        goto LAB_14000feda;
      }
      uVar19 = uVar19 + 4;
      lVar15 = lVar15 + 4;
    } while (uVar19 < 0x20);
    memcpy(local_98,"TotalCountSurpriseRemove",_Size);
    local_78 = local_1e0;
    StorPortExtendedFunction(0x4f,local_1d8,plVar6 + 1,&local_1c8);
    return 0;
  case 0xd:
    lVar15 = *(longlong *)
              (param_1 + 0x1b0 + (ulonglong)*(byte *)(*(longlong *)(param_3 + 2) + 8) * 8);
    if (*(uint *)(param_1 + 0x184) < (uint)*(byte *)(*(longlong *)(param_3 + 2) + 8)) {
      return 0;
    }
    if (lVar15 == 0) {
      return 0;
    }
    if (param_3[1] < 0x98) {
      return 1;
    }
    param_3[0] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_3[4] = 0;
    param_3[5] = 0;
    param_3[6] = 0;
    param_3[7] = 0;
    param_3[8] = 0;
    param_3[9] = 0;
    param_3[10] = 0;
    param_3[0xb] = 0;
    param_3[0xc] = 0;
    param_3[0xd] = 0;
    param_3[0xe] = 0;
    param_3[0xf] = 0;
    param_3[0x10] = 0;
    param_3[0x11] = 0;
    param_3[0x12] = 0;
    param_3[0x13] = 0;
    param_3[0x14] = 0;
    param_3[0x15] = 0;
    param_3[0x16] = 0;
    param_3[0x17] = 0;
    param_3[0x18] = 0;
    param_3[0x19] = 0;
    param_3[0x1a] = 0;
    param_3[0x1b] = 0;
    param_3[0x1c] = 0;
    param_3[0x1d] = 0;
    param_3[0x1e] = 0;
    param_3[0x1f] = 0;
    param_3[0x20] = 0;
    param_3[0x21] = 0;
    param_3[0x22] = 0;
    param_3[0x23] = 0;
    param_3[0x24] = 0;
    param_3[0x25] = 0;
    *param_3 = 1;
    param_3[1] = 0x98;
    uVar11 = *(undefined8 *)(lVar15 + 0x7a);
    *(undefined8 *)(param_3 + 4) = *(undefined8 *)(lVar15 + 0x72);
    *(undefined8 *)(param_3 + 6) = uVar11;
    param_3[8] = *(uint *)(lVar15 + 0x82);
    *(undefined1 *)(param_3 + 9) = *(undefined1 *)(lVar15 + 0x86);
    return 0;
  }
  return 1;
}



===== AhciSetF1IdleTimer @ 140010000 =====

int AhciSetF1IdleTimer(longlong *param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  if ((((ulonglong)param_1[0x4a] >> 0xd & 1) != 0) && (1 < *(uint *)(param_1[0x50] + 0x20))) {
    if (*(int *)(*param_1 + 0x20) == 1) {
      uVar1 = *(uint *)((longlong)param_1 + 0x25c);
    }
    else {
      if (((byte)*(undefined4 *)((longlong)param_1 + 0x254) & 6) == 4) {
        return 0;
      }
      uVar1 = *(uint *)(param_1 + 0x4c);
      uVar3 = 1000000;
    }
    iVar2 = StorPortExtendedFunction
                      (0x21,*param_1,param_1[0x156],AhciF1IdleTimerCallback,param_1,
                       (ulonglong)uVar1 * 1000,uVar3);
    if (iVar2 == 0) {
      *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) | 0x10;
    }
  }
  return iVar2;
}



===== PartialToSlumberTransitionIsAllowed @ 1400100b0 =====

ulonglong PartialToSlumberTransitionIsAllowed(ulonglong *param_1,uint *param_2)

{
  uint uVar1;
  ulonglong in_RAX;
  uint uVar2;
  ulonglong *puVar3;
  uint local_18 [6];
  
  local_18[0] = 0;
  if ((((*(byte *)((longlong)param_1 + 0x277) & 3) != 0) && ((int)param_1[0x4f] != 0)) &&
     ((char)param_1[0x49] == '\x16')) {
    puVar3 = param_1;
    in_RAX = NoLpmSupport((longlong *)param_1);
    if ((char)in_RAX != '\0') goto LAB_1400101d2;
    in_RAX = IsLPMCapablePort(param_1);
    if (((((char)in_RAX == '\0') ||
         (in_RAX = puVar3[0x18], (*(ushort *)(in_RAX + 0x98) >> 9 & 1) == 0)) ||
        ((in_RAX = puVar3[0x4a], (in_RAX >> 0xd & 1) != 0 && ((char)puVar3[0x51] != '\0')))) ||
       ((((*(byte *)((longlong)puVar3 + 0x277) & 2) != 0 &&
         ((*(ushort *)(puVar3[0x18] + 0x98) >> 0xe & 1) != 0)) &&
        (in_RAX = 0, *(char *)(puVar3[0x18] + 0x9e) < '\0')))) goto LAB_1400101d2;
    if ((param_2 == (uint *)0x0) || (*param_2 == 0)) {
      param_2 = local_18;
      in_RAX = (ulonglong)*(uint *)(puVar3[0x129] + 0x18);
      local_18[0] = *(uint *)(puVar3[0x129] + 0x18);
    }
    uVar2 = *(uint *)(*puVar3 + 0x1a8) & 0x4000000;
    if ((uVar2 == 0) || ((*param_2 & 0x4000000) == 0)) {
      in_RAX = puVar3[0x18];
      if ((*(byte *)(in_RAX + 0x9c) & 8) == 0) goto LAB_1400101d2;
      if (uVar2 == 0) goto LAB_1400101ca;
    }
    uVar2 = *param_2;
    if (((uVar2 >> 0x1a & 1) == 0) ||
       (((uVar2 >> 0x1b & 1) == 0 &&
        ((uVar1 = *(uint *)(*puVar3 + 0x1ac), in_RAX = (ulonglong)uVar1, (uVar1 & 4) == 0 ||
         ((uVar2 >> 0x17 & 1) == 0)))))) {
LAB_1400101ca:
      return CONCAT71((int7)(in_RAX >> 8),1);
    }
  }
LAB_1400101d2:
  return in_RAX & 0xffffffffffffff00;
}



===== AhciAutoPartialToSlumber @ 1400101e0 =====

void AhciAutoPartialToSlumber(undefined8 param_1,ulonglong *param_2)

{
  int *piVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  bool bVar8;
  uint local_res10 [2];
  
  if ((((param_2 != (ulonglong *)0x0) && (param_2[0x129] != 0)) &&
      (local_res10[0] = *(uint *)(param_2[0x129] + 0x18),
      *(int *)(param_2[0x129] + 0x34) == 0 && *(int *)(param_2[0x129] + 0x38) == 0)) &&
     (uVar3 = PartialToSlumberTransitionIsAllowed(param_2,local_res10), (char)uVar3 != '\0')) {
    uVar5 = 0;
    uVar2 = 0;
    while ((*(uint *)(param_2[0x129] + 0x28) & 0xf00) != 0x200) {
      if ((param_2[0x4a] >> 0x1c & 1) == 0) {
        return;
      }
      if ((*(uint *)(param_2[0x129] + 0x28) & 0xf00) == 0x600) {
        return;
      }
      uVar2 = uVar2 + 1;
      if (2 < uVar2) {
        return;
      }
      StorPortStallExecution(200);
    }
    if ((local_res10[0] & 0xf0000000) == 0) {
      piVar1 = (int *)((longlong)param_2 + 0x294);
      if ((piVar1 != (int *)0x0) && (*piVar1 != -1)) {
        *piVar1 = *piVar1 + 1;
      }
      local_res10[0] = local_res10[0] & 0xfffffff | 0x10000000;
      *(uint *)(param_2[0x129] + 0x18) = local_res10[0];
      LOCK();
      UNLOCK();
      uVar6 = 0;
      uVar2 = *(uint *)(param_2[0x129] + 0x28);
      bVar7 = 0;
      do {
        if ((uVar2 & 0xf00) == 0x100) break;
        if (bVar7 < 3) {
          local_res10[0] = local_res10[0] & 0xfffffff | 0x10000000;
          *(uint *)(param_2[0x129] + 0x18) = local_res10[0];
          LOCK();
          UNLOCK();
        }
        StorPortStallExecution(10);
        uVar6 = uVar6 + 10;
        uVar2 = *(uint *)(param_2[0x129] + 0x28);
        bVar7 = bVar7 + 1;
      } while (uVar6 < 100);
      if ((uVar2 & 0xf00) == 0x100) {
        piVar1 = (int *)((longlong)param_2 + 0x29c);
        if ((piVar1 != (int *)0x0) && (*piVar1 != -1)) {
          *piVar1 = *piVar1 + 1;
        }
        local_res10[0] = local_res10[0] & 0xfffffff | 0x60000000;
        *(uint *)(param_2[0x129] + 0x18) = local_res10[0];
        LOCK();
        UNLOCK();
        uVar2 = *(uint *)(param_2[0x129] + 0x28);
        bVar7 = 0;
        do {
          if ((uVar2 & 0xf00) == 0x600) break;
          if (bVar7 < 3) {
            local_res10[0] = local_res10[0] & 0xfffffff | 0x60000000;
            *(uint *)(param_2[0x129] + 0x18) = local_res10[0];
            LOCK();
            UNLOCK();
          }
          StorPortStallExecution(10);
          uVar5 = uVar5 + 10;
          uVar2 = *(uint *)(param_2[0x129] + 0x28);
          bVar7 = bVar7 + 1;
        } while (uVar5 < 100);
        if ((uVar2 & 0xf00) == 0x600) {
          puVar4 = (ulonglong *)((longlong)param_2 + 0x2a4);
          bVar8 = puVar4 == (ulonglong *)0x0;
        }
        else {
          puVar4 = param_2 + 0x54;
          bVar8 = puVar4 == (ulonglong *)0x0;
        }
      }
      else {
        puVar4 = param_2 + 0x53;
        bVar8 = puVar4 == (ulonglong *)0x0;
      }
    }
    else {
      puVar4 = param_2 + 0x52;
      bVar8 = puVar4 == (ulonglong *)0x0;
    }
    if ((!bVar8) && ((int)*puVar4 != -1)) {
      *(int *)puVar4 = (int)*puVar4 + 1;
    }
  }
  return;
}



===== AhciPortIdentifyDevice @ 140010480 =====

void AhciPortIdentifyDevice(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  int *piVar2;
  uint uVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  ushort uVar10;
  int *piVar11;
  uint uVar12;
  longlong lVar13;
  undefined8 *local_res10;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar15;
  undefined8 uVar14;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar17;
  undefined8 uVar16;
  undefined8 **ppuVar18;
  undefined8 local_28;
  
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  if (*(char *)(param_2 + 2) == '(') {
    piVar11 = (int *)0x0;
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar6 = 0;
      if (*(uint *)(param_2 + 0x38) != 0) {
        do {
          uVar12 = *(uint *)(param_2 + 0x78 + uVar6 * 4);
          if ((0x7f < uVar12) && (uVar3 = *(uint *)(param_2 + 0x10), uVar12 < uVar3)) {
            piVar2 = (int *)((ulonglong)uVar12 + param_2);
            uVar9 = (ulonglong)uVar12;
            iVar5 = *piVar2;
            if (iVar5 == 0x40) {
              uVar9 = uVar9 + 0x28;
            }
            else {
              if (iVar5 != 0x41) {
                if ((iVar5 != 0x42) || ((ulonglong)uVar3 < uVar9 + 0x28)) goto LAB_140010503;
                if (piVar2[3] != 0) {
                  piVar11 = piVar2 + 8;
                }
                break;
              }
              uVar9 = uVar9 + 0x38;
            }
            if (uVar9 <= uVar3) {
              if (*(char *)((longlong)piVar2 + 10) != '\0') {
                piVar11 = piVar2 + 6;
              }
              break;
            }
          }
LAB_140010503:
          uVar12 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar12;
        } while (uVar12 < *(uint *)(param_2 + 0x38));
      }
    }
  }
  else {
    piVar11 = (int *)(param_2 + 0x48);
  }
  if (*(char *)(param_2 + 3) != '\x0e') {
    plVar1 = param_1 + 3;
    if (*(char *)(param_2 + 3) == '\b') {
      *(int *)plVar1 = 6;
    }
    lVar13 = 4;
    if (*(char *)(param_2 + 3) == '\x01') {
      if (((int)*plVar1 == 0) || ((int)*plVar1 == 6)) {
        iVar5 = *(int *)(param_1[0x129] + 0x24);
        if (iVar5 == 0x101) {
          *(int *)plVar1 = 1;
        }
        else if (iVar5 == -0x5432feff) {
          *(int *)plVar1 = 3;
        }
        else if (iVar5 == -0x14ebfeff) {
          *(int *)plVar1 = 2;
        }
      }
      uVar10 = *(ushort *)(param_1[0x18] + 0x8a) & 3;
      if (uVar10 == 1) {
        *(undefined4 *)(param_1 + 3) = 4;
      }
      else if (uVar10 == 2) {
        *(undefined4 *)(param_1 + 3) = 5;
      }
      param_1[0x38] = 0;
      param_1[0x4a] = param_1[0x4a] & 0xffffffffffffff4f;
      *(undefined8 *)((longlong)param_1 + 0x164) = 0;
      *(undefined8 *)((longlong)param_1 + 0x16c) = 0;
      param_1[0x39] = 0;
      param_1[0x3a] = 0;
      *(undefined4 *)(param_1 + 0x3b) = 0;
      param_1[0x2f] = 0;
      UpdateDeviceParameters(param_1);
      DigestDeviceRegistrySettings(param_1);
      uVar10 = *(ushort *)(param_1[0x18] + 0xac);
      *(undefined4 *)((longlong)param_1 + 0x244) = 0;
      *(uint *)(param_1 + 0x4a) =
           ((uint)uVar10 << 0xe ^ *(uint *)(param_1 + 0x4a)) & 0x80000 ^ *(uint *)(param_1 + 0x4a);
      if (((ulonglong)param_1[0x4a] >> 0x14 & 1) == 0) {
        param_1[0x4a] = param_1[0x4a] | 0x100000;
      }
      if (((*(uint *)(param_1 + 0x4b) & 2) == 0) &&
         (((uVar12 = *(uint *)(param_1[0x129] + 0x18), (uVar12 >> 0x12 & 1) != 0 ||
           (((*(uint *)(*param_1 + 0x1a8) & 0x20) != 0 && ((uVar12 >> 0x15 & 1) != 0)))) ||
          (((*(uint *)(*param_1 + 0x1a8) >> 0x1c & 1) != 0 && ((uVar12 >> 0x13 & 1) != 0)))))) {
        *(uint *)((longlong)param_1 + 0x244) = *(uint *)((longlong)param_1 + 0x244) | 1;
      }
    }
    if ((piVar11 == (int *)0x0) || ((char)*piVar11 != -0x60)) {
      if ((*(char *)(*param_1 + 0x18c) == '\0') ||
         ((piVar11 == (int *)0x0 || ((char)*piVar11 != '\x12')))) {
        if (((*(uint *)(param_1 + 4) & 0x10) != 0) &&
           ((piVar11 != (int *)0x0 && ((char)*piVar11 == '\x12')))) {
          *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffffef;
          InquiryComplete(param_1,param_2);
          uVar6 = IsDeviceGeneralPurposeLoggingSupported((longlong)param_1);
          if ((char)uVar6 != '\0') {
            local_res10 = (undefined8 *)0x0;
            local_28 = 0;
            if (((((int)param_1[3] == 1) || ((int)param_1[3] - 3U < 3)) &&
                ((*(byte *)(param_1[0x18] + 0xa8) & 0x20) != 0)) &&
               ((*(ushort *)(param_1[0x18] + 0xa6) >> 10 & 1) != 0)) {
              lVar4 = *param_1;
              if ((-1 < *(int *)(lVar4 + 0x1a8)) ||
                 (uVar7 = 0x7fffffffffffffff, (*(uint *)(lVar4 + 0x38) & 0x800) == 0)) {
                uVar7 = 0x7fffffff;
              }
              puVar8 = &local_28;
              ppuVar18 = &local_res10;
              uVar16 = CONCAT44(uVar17,0x80000000);
              uVar14 = CONCAT44(uVar15,1);
              iVar5 = StorPortExtendedFunction
                                (0x52,lVar4,0x200,0,uVar7,0,uVar14,uVar16,ppuVar18,puVar8);
              if (iVar5 == 0) {
                puVar8 = local_res10;
                if (local_res10 != (undefined8 *)0x0) {
                  do {
                    *puVar8 = 0;
                    puVar8[1] = 0;
                    puVar8[2] = 0;
                    puVar8[3] = 0;
                    puVar8[4] = 0;
                    puVar8[5] = 0;
                    puVar8[6] = 0;
                    puVar8[7] = 0;
                    puVar8[8] = 0;
                    puVar8[9] = 0;
                    puVar8[10] = 0;
                    puVar8[0xb] = 0;
                    puVar8[0xc] = 0;
                    puVar8[0xd] = 0;
                    puVar8[0xe] = 0;
                    puVar8[0xf] = 0;
                    lVar13 = lVar13 + -1;
                    puVar8 = puVar8 + 0x10;
                  } while (lVar13 != 0);
                  if (*(char *)(param_2 + 2) == '(') {
                    uVar6 = *(ulonglong *)(param_2 + 0x68);
                  }
                  else {
                    uVar6 = *(ulonglong *)(param_2 + 0x38);
                  }
                  if ((uVar6 & 0x7f) != 0) {
                    uVar6 = (uVar6 - ((uint)uVar6 & 0x7f)) + 0x80;
                  }
                  *(uint *)(uVar6 + 0x1104) = *(uint *)(uVar6 + 0x1104) | 10;
                  *(code **)(uVar6 + 0x2968) = GetDownloadMicrocodeSupportCompletion;
                  *(undefined2 *)(uVar6 + 0x1100) = 0x100;
                  *(undefined4 *)(uVar6 + 0x1108) = 0x3300100;
                  *(undefined8 *)(uVar6 + 0x110c) = 0x2fe000;
                  *(undefined4 *)(uVar6 + 0x1114) = 0;
                  *(undefined1 *)(param_2 + 3) = 0;
                  *(undefined8 **)(uVar6 + 0x1120) = local_res10;
                  *(longlong *)(uVar6 + 0x1128) = local_28;
                  *(undefined4 *)(uVar6 + 0x1140) = 1;
                  *(undefined4 *)(uVar6 + 0x1150) = (undefined4)local_28;
                  *(undefined4 *)(uVar6 + 0x1154) = local_28._4_4_;
                  *(undefined4 **)(uVar6 + 0x1138) = (undefined4 *)(uVar6 + 0x1140);
                  *(undefined4 *)(uVar6 + 0x1158) = 0x200;
                  *(undefined4 *)(uVar6 + 0x1130) = 0x200;
                  if (&local_28 == param_1 + 0x3d) {
                    *(undefined1 *)(param_1 + 0x3e) = 0xff;
                    return;
                  }
                  return;
                }
              }
              else if (local_res10 != (undefined8 *)0x0) {
                StorPortExtendedFunction
                          (0x53,*param_1,local_res10,0x200,1,local_28,uVar14,uVar16,ppuVar18,puVar8)
                ;
              }
              *(undefined1 *)(param_2 + 3) = 4;
            }
            else {
              *(undefined1 *)(param_2 + 3) = 6;
            }
          }
        }
      }
      else if (((*(char *)(*param_1 + 0x18c) == '\x04') && (*(char *)(param_2 + 3) == '\x01')) &&
              ((uVar6 = IsDeviceGeneralPurposeLoggingSupported((longlong)param_1),
               (char)uVar6 != '\0' &&
               (uVar6 = IsDeviceHybridInfoSupported((longlong)param_1), (char)uVar6 != '\0')))) {
        IssueReadLogExtCommand
                  ((longlong)param_1,param_2,0x14,0,1,0,param_1 + 0x3d,param_1[0x3c],InquiryComplete
                  );
      }
      else {
        InquiryComplete(param_1,param_2);
      }
    }
    else {
      if (((*(char *)(param_2 + 3) == '\x01') &&
          (uVar6 = IsDeviceGeneralPurposeLoggingSupported((longlong)param_1), (char)uVar6 != '\0'))
         && (((ulonglong)param_1[0x4a] >> 0x1a & 1) == 0)) {
        InitQueryLogPages((longlong)param_1);
        uVar6 = GetNextQueryLogPageIndex((longlong)param_1);
        if ((ushort)uVar6 != 0xffff) {
          ReadQueryLogPage((longlong)param_1,param_2,(ushort)uVar6);
          return;
        }
      }
      ReportLunsComplete((longlong)param_1,param_2);
    }
  }
  return;
}



===== AhciPortPowerDown @ 140010a20 =====

void AhciPortPowerDown(ulonglong *param_1)

{
  *(int *)((longlong)param_1 + 0x45fc) = *(int *)((longlong)param_1 + 0x45fc) + 1;
  param_1[0x4a] = param_1[0x4a] | 0x1000;
  StorPortExtendedFunction(0x21,*param_1,param_1[0x153],P_Running_Callback,param_1,0,0);
  if ((param_1[0x4a] >> 0xd & 1) != 0) {
    if (((*(uint *)(*param_1 + 0x38) & 0x200) == 0) && ((param_1[0x4a] >> 0xf & 1) != 0)) {
      param_1[0x4a] = param_1[0x4a] | 0x800;
    }
    if (*(int *)(*param_1 + 0x20) == 1) {
      param_1[0x4a] = param_1[0x4a] | 0x10000000;
      AhciAutoPartialToSlumber(*param_1,param_1);
      param_1[0x4a] = param_1[0x4a] & 0xffffffffefffffff;
    }
    if ((*(uint *)((longlong)param_1 + 0x254) & 8) == 0) {
      PortDevSleep(param_1);
    }
  }
  RecordExecutionHistory((longlong *)param_1,0x10000027);
  return;
}



===== AhciPortPowerUp @ 140010b20 =====

void AhciPortPowerUp(ulonglong *param_1)

{
  ulonglong *puVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined4 local_res8 [2];
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  RecordExecutionHistory((longlong *)param_1,0x26);
  *(int *)(param_1 + 0x8bf) = (int)param_1[0x8bf] + 1;
  uVar2 = *(uint *)(param_1[0x129] + 0x10);
  LOCK();
  puVar1 = param_1 + 0x4a;
  uVar4 = *puVar1;
  *(uint *)puVar1 = (uint)*puVar1 & 0xffffefff;
  UNLOCK();
  if (((uint)uVar4 >> 0xc & 1) == 0) {
    RecordExecutionHistory((longlong *)param_1,0x10026);
    return;
  }
  *(int *)param_1[0x129] = (int)param_1[300];
  LOCK();
  UNLOCK();
  if (*(int *)(*param_1 + 0x1a8) < 0) {
    *(undefined4 *)(param_1[0x129] + 4) = *(undefined4 *)((longlong)param_1 + 0x964);
    LOCK();
    UNLOCK();
  }
  *(int *)(param_1[0x129] + 8) = (int)param_1[0x12d];
  LOCK();
  UNLOCK();
  if (*(int *)(*param_1 + 0x1a8) < 0) {
    *(undefined4 *)(param_1[0x129] + 0xc) = *(undefined4 *)((longlong)param_1 + 0x96c);
    LOCK();
    UNLOCK();
  }
  PortPhyOnline((longlong *)param_1);
  if (((*(int *)((longlong)param_1 + 0x28c) == 4) && ((*(uint *)(*param_1 + 0x38) & 0x200) == 0)) &&
     ((param_1[0x4a] >> 0xf & 1) != 0)) {
    local_28 = 3;
    local_20 = 0;
    local_18 = 0;
    uStack_10 = 0;
    AhciPortIssueInitCommands((longlong *)param_1);
    LOCK();
    puVar1 = param_1 + 0x4a;
    uVar4 = *puVar1;
    *(uint *)puVar1 = (uint)*puVar1 | 0x400000;
    UNLOCK();
    if (((uint)uVar4 >> 0x16 & 1) != 0) {
      RecordExecutionHistory((longlong *)param_1,0x10020026);
    }
    AhciLpmSettingsModes(param_1,(uint)*(byte *)((longlong)param_1 + 0x277));
    if ((*(uint *)((longlong)param_1 + 0x254) & 6) != 0) {
      *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) | 0x200;
    }
    uVar4 = *param_1;
    if (((char)*(undefined4 *)(uVar4 + 0x2c) < '\0') && (iVar3 = (int)param_1[0x48], iVar3 != -1)) {
      local_res8[0] = 0;
      StorPortExtendedFunction(0xb,uVar4,iVar3,local_res8);
      uStack_10 = CONCAT71(uStack_10._1_7_,(undefined1)local_res8[0]);
    }
    else {
      StorPortNotification(0x1003,uVar4,3,0,&local_28);
    }
    AhciPortReset(param_1,'\0');
    uVar4 = *param_1;
    if (((char)*(undefined4 *)(uVar4 + 0x2c) < '\0') && (iVar3 = (int)param_1[0x48], iVar3 != -1)) {
      StorPortExtendedFunction(0xc,uVar4,iVar3,uStack_10 & 0xff);
    }
    else {
      StorPortNotification(0x1004,uVar4,&local_28);
    }
  }
  else {
    if (((uVar2 & 0x40) != 0) && ((char)param_1[0x49] == -1)) {
      param_1[0x4a] = param_1[0x4a] | 0x200000;
    }
    if ((param_1[0x4b] & 0x40) != 0) {
      RestorePreservedSettings((longlong *)param_1,0);
    }
    uVar4 = *param_1;
    local_28 = 3;
    local_20 = 0;
    local_18 = 0;
    uStack_10 = 0;
    if (((char)*(undefined4 *)(uVar4 + 0x2c) < '\0') && (iVar3 = (int)param_1[0x48], iVar3 != -1)) {
      local_res8[0] = 0;
      StorPortExtendedFunction(0xb,uVar4,iVar3,local_res8);
      uStack_10 = CONCAT71(uStack_10._1_7_,(undefined1)local_res8[0]);
      uVar5 = (undefined1)local_res8[0];
    }
    else {
      StorPortNotification(0x1003,uVar4,3,0,&local_28);
      uVar5 = (undefined1)uStack_10;
    }
    uVar4 = *param_1;
    *(undefined4 *)(param_1 + 0x49) = 0x11;
    *(byte *)((longlong)param_1 + 0x24d) = *(byte *)((longlong)param_1 + 0x24d) & 0xfe | 2;
    *(undefined1 *)((longlong)param_1 + 0x24c) = 0;
    *(undefined2 *)((longlong)param_1 + 0x24e) = 0;
    if (((char)*(undefined4 *)(uVar4 + 0x2c) < '\0') && (iVar3 = (int)param_1[0x48], iVar3 != -1)) {
      StorPortExtendedFunction(0xc,uVar4,iVar3,uVar5);
    }
    else {
      StorPortNotification(0x1004,uVar4,&local_28);
    }
    P_Running(param_1,'\0');
  }
  RecordExecutionHistory((longlong *)param_1,0x10000026);
  return;
}



===== IssueInitCommands @ 140010e80 =====

void IssueInitCommands(longlong *param_1)

{
  bool bVar1;
  char *pcVar2;
  
  RecordExecutionHistory(param_1,0x44);
  if (((*(uint *)(param_1 + 0x5c) | *(uint *)((longlong)param_1 + 0x2dc) | *(uint *)(param_1 + 0x5b)
        | *(uint *)((longlong)param_1 + 0x2d4) | *(uint *)(param_1 + 0x5a)) & 1) != 0) {
    RecordExecutionHistory(param_1,0x10010044);
    return;
  }
  if (*(byte *)((longlong)param_1 + 0xa41) <= *(byte *)((longlong)param_1 + 0xa42)) {
    RecordExecutionHistory(param_1,0x10020044);
    *(int *)((longlong)param_1 + 0xa54) = (int)param_1[0x14a];
    IssuePreservedSettingCommands(param_1);
    return;
  }
  pcVar2 = (char *)((ulonglong)*(byte *)((longlong)param_1 + 0xa42) * 0x10 + param_1[0x149]);
  pcVar2[5] = -0x60;
  if (*pcVar2 == '\a') {
    if (((ulonglong)param_1[0x4a] >> 0x13 & 1) != 0) {
      bVar1 = NeedsPuisSpinUpOnPowerUp((longlong)param_1);
      if ((bVar1) && (*(int *)((longlong)param_1 + 0x28c) == 4)) goto LAB_140010f5d;
    }
    *(char *)((longlong)param_1 + 0xa42) = *(char *)((longlong)param_1 + 0xa42) + '\x01';
    pcVar2 = (char *)((ulonglong)*(byte *)((longlong)param_1 + 0xa42) * 0x10 + param_1[0x149]);
    pcVar2[5] = -0x60;
  }
LAB_140010f5d:
  BuildLocalCommand(param_1,(undefined8 *)pcVar2,IssueInitCommands);
  *(char *)((longlong)param_1 + 0xa42) = *(char *)((longlong)param_1 + 0xa42) + '\x01';
  return;
}



===== IssuePreservedSettingCommands @ 140010f90 =====

void IssuePreservedSettingCommands(longlong *param_1)

{
  void *_Dst;
  uint uVar1;
  byte bVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  RecordExecutionHistory(param_1,0x43);
  if (((*(uint *)(param_1 + 0x5c) | *(uint *)((longlong)param_1 + 0x2dc) | *(uint *)(param_1 + 0x5b)
        | *(uint *)((longlong)param_1 + 0x2d4) | *(uint *)(param_1 + 0x5a)) & 1) != 0) {
    RecordExecutionHistory(param_1,0x10010043);
    return;
  }
  bVar2 = 0;
  do {
    uVar1 = 1 << (bVar2 & 0x1f);
    if ((*(uint *)((longlong)param_1 + 0xa54) & uVar1) != 0) {
      *(uint *)((longlong)param_1 + 0xa54) = ~uVar1 & *(uint *)((longlong)param_1 + 0xa54);
      if (bVar2 < 0x20) {
        _Dst = (void *)param_1[0x139];
        uVar3 = CONCAT62((int6)(CONCAT17((char)((ulonglong)uVar3 >> 0x38),
                                         CONCAT25(0xefa0,(int5)uVar3)) >> 0x10),
                         CONCAT11(*(undefined1 *)((longlong)param_1 + (ulonglong)bVar2 * 2 + 0xa59),
                                  *(undefined1 *)((longlong)param_1 + (ulonglong)bVar2 * 2 + 0xa58))
                        );
        *(undefined1 *)((longlong)param_1 + 0x973) = 0;
        param_1[0x135] = (longlong)_Dst;
        *(undefined4 *)((longlong)param_1 + 0x984) = 1;
        memset(_Dst,0,0x29a0);
        *(undefined2 *)((longlong)_Dst + 0x1100) = 0x100;
        *(code **)((longlong)_Dst + 0x2968) = IssuePreservedSettingCommands;
        *(undefined8 *)((longlong)_Dst + 0x1108) = uVar3;
        *(undefined8 *)((longlong)_Dst + 0x1110) = 0;
        if ((*(uint *)(*param_1 + 0x34) & 1) != 0) {
          RecordExecutionHistory(param_1,0x1000001d);
        }
        return;
      }
      break;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 0x20);
  if ((param_1[0x4a] & 0x40U) != 0) {
    if (((ulonglong)param_1[0x4a] >> 0xd & 1) != 0) {
      StorPortExtendedFunction(0x32,*param_1,param_1 + 1,0,0,0,uVar3);
    }
    param_1[0x4a] = param_1[0x4a] & 0xffffffffffffffbf;
  }
  RecordExecutionHistory(param_1,0x10020043);
  LOCK();
  *(uint *)(param_1 + 0x4a) = *(uint *)(param_1 + 0x4a) & 0xfffffff7;
  UNLOCK();
  LOCK();
  *(uint *)(param_1 + 0x4a) = *(uint *)(param_1 + 0x4a) & 0xffbfffff;
  UNLOCK();
  LOCK();
  *(uint *)(param_1 + 0x4a) = *(uint *)(param_1 + 0x4a) & 0xfdffffff;
  UNLOCK();
  return;
}



===== PortPhyOnline @ 140011140 =====

void PortPhyOnline(longlong *param_1)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  wchar_t *pwVar7;
  
  if (((ulonglong)param_1[0x4a] >> 0xd & 1) == 0) {
    return;
  }
  uVar1 = *(uint *)((longlong)param_1 + 0x254) & 6;
  if (uVar1 == 2) {
    uVar1 = *(uint *)(param_1[0x129] + 0x28);
    if ((uVar1 & 0xf00) == 0x800) {
      uVar6 = *(uint *)(param_1[0x129] + 0x18);
      if (uVar6 < 0x10000000) {
        uVar6 = uVar6 & 0xfffffff | 0x10000000;
        *(uint *)(param_1[0x129] + 0x18) = uVar6;
        LOCK();
        UNLOCK();
        lVar5 = param_1[0x2f];
        bVar2 = (byte)((ulonglong)lVar5 >> 8);
        if (-1 < lVar5) {
          bVar2 = 0;
        }
        if (bVar2 == 0) {
          bVar2 = 0x14;
        }
        bVar3 = (byte)lVar5 & 0x1f;
        if (-1 < lVar5) {
          bVar3 = 0;
        }
        if (bVar3 == 0) {
          bVar3 = 10;
        }
        StorPortStallExecution((bVar2 + 1 + (uint)bVar3) * 1000);
        uVar4 = 0;
      }
      else {
        uVar4 = 2;
      }
      lVar5 = *param_1;
      if (*(char *)(lVar5 + 0x18e) == '\0') goto LAB_14001144f;
      uVar6 = uVar6 >> 0x1c;
      pwVar7 = L"CMD.ICC";
    }
    else {
      lVar5 = *param_1;
      if (*(char *)(lVar5 + 0x18e) == '\0') goto LAB_14001144f;
      uVar6 = 0;
      pwVar7 = (wchar_t *)0x0;
      uVar4 = 3;
    }
    StorPortExtendedFunction
              (0x56,lVar5,param_1 + 1,0,4,L"DEVSLP Disabled",4,4,0,0,L"Using HW DEVSLP",0,L"Status",
               uVar4,L"SSTS.IPM",uVar1 >> 8 & 0xf,pwVar7,uVar6);
  }
  else if ((uVar1 == 6) && ((*(uint *)(param_1[0x129] + 0x44) & 1) != 0)) {
    *(uint *)(param_1[0x129] + 0x44) = *(uint *)(param_1[0x129] + 0x44) & 0xfffffffe;
    LOCK();
    UNLOCK();
    bVar2 = (byte)((ulonglong)param_1[0x2f] >> 8);
    if (-1 < param_1[0x2f]) {
      bVar2 = 0;
    }
    if (bVar2 == 0) {
      bVar2 = 0x14;
    }
    StorPortStallExecution((uint)bVar2 * 1000);
    if (((*(uint *)(*param_1 + 0x1ac) & 0x20) != 0) &&
       ((*(ushort *)(param_1[0x18] + 0x98) >> 9 & 1) != 0)) {
      *(uint *)(param_1[0x129] + 0x18) = *(uint *)(param_1[0x129] + 0x18) & 0xff7fffff;
      LOCK();
      UNLOCK();
    }
    if (*(char *)(*param_1 + 0x18e) != '\0') {
      StorPortExtendedFunction
                (0x55,*param_1,param_1 + 1,0,4,L"DEVSLP Disabled",4,4,0,0,L"Using HW DEVSLP",1,
                 L"Success",1);
    }
  }
LAB_14001144f:
  *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) & 0xfffffff7;
  return;
}



===== AhciCOMRESET @ 140011480 =====

void AhciCOMRESET(longlong *param_1,longlong param_2)

{
  uint uVar1;
  byte bVar2;
  
  RecordExecutionHistory(param_1,0x10);
  if ((*(uint *)(param_2 + 0x18) & 1) != 0) {
    RecordExecutionHistory(param_1,0x10fa0010);
    return;
  }
  uVar1 = *(uint *)(param_2 + 0x14);
  *(uint *)(param_2 + 0x14) = uVar1 & 0xffbfffbf;
  LOCK();
  UNLOCK();
  param_1[0x4a] = param_1[0x4a] | 0x800;
  *(uint *)(param_2 + 0x2c) = *(uint *)(param_2 + 0x2c) & 0xfffffff1 | 1;
  LOCK();
  UNLOCK();
  StorPortStallExecution(1000);
  *(uint *)(param_2 + 0x2c) = *(uint *)(param_2 + 0x2c) & 0xfffffff0;
  LOCK();
  UNLOCK();
  StorPortStallExecution(0x32);
  if ((*(uint *)(param_2 + 0x28) & 0xf) == 0) {
    bVar2 = 0;
    do {
      StorPortStallExecution(1000);
      if ((*(uint *)(param_2 + 0x28) & 0xf) != 0) break;
      bVar2 = bVar2 + 1;
    } while (bVar2 < 0x1e);
  }
  *(uint *)(param_2 + 0x14) = uVar1;
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_2 + 0x30) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(int *)(param_1 + 0x17) = (int)param_1[0x17] + 1;
  RecordExecutionHistory(param_1,0x10000010);
  return;
}



===== AhciNonQueuedErrorRecovery @ 1400115b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AhciNonQueuedErrorRecovery(ulonglong *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  uint uVar13;
  ulonglong uVar14;
  uint uVar15;
  char cVar16;
  ulonglong *puVar17;
  char cVar18;
  longlong *plVar19;
  ulonglong uVar20;
  undefined1 auStack_248 [32];
  ulonglong *local_228;
  longlong *local_220;
  ulonglong local_218;
  ulonglong local_210;
  ulonglong local_208;
  undefined8 local_200;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined1 local_1d0 [32];
  undefined8 local_1b0;
  undefined1 local_198 [32];
  undefined8 local_178;
  undefined1 local_170 [32];
  undefined8 local_150;
  undefined1 local_148 [32];
  undefined8 local_128;
  undefined1 local_120 [32];
  ulonglong local_100;
  undefined1 local_f8 [32];
  ulonglong local_d8;
  undefined1 local_d0 [32];
  ulonglong local_b0;
  undefined1 local_a8 [32];
  ulonglong *local_88;
  undefined8 local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_248;
  RecordExecutionHistory((longlong *)param_1,0x13);
  local_210 = 0;
  if ((param_1 != (ulonglong *)0x0) && ((int)param_1[3] != 2)) {
    StorPortQuerySystemTime(&local_210);
    if ((param_1[0x8be] == 0) || (35999999999 < local_210 - param_1[0x8be])) {
      uVar14 = param_1[0x8bc];
      uVar11 = *(undefined4 *)((longlong)param_1 + 0x45d4);
      uVar20 = param_1[0x8ba];
      uVar12 = param_1[0x4a];
      uVar9 = *(uint *)((longlong)param_1 + 0xb4);
      param_1[0x8be] = local_210;
      local_228 = (ulonglong *)(ulonglong)(uint)param_1[0x8bd];
      local_220 = (longlong *)param_1[0x49];
      uVar2 = *(undefined4 *)((longlong)param_1 + 0x45e4);
      uVar3 = *(undefined4 *)((longlong)param_1 + 0x45dc);
      uVar10 = param_1[0x8bb];
      local_218 = *param_1;
      memset(&local_1d8,0,0x180);
      uVar8 = 0;
      local_1d8 = 1;
      lVar6 = 0;
      local_1d4 = 4;
      do {
        uVar13 = 0x20;
        if ("AhciNonQueuedErrorRecovery"[lVar6] == '\0') goto LAB_14001172f;
        if ("AhciNonQueuedErrorRecovery"[lVar6 + 1] == '\0') {
          uVar8 = uVar8 + 1;
LAB_140011729:
          if (uVar8 < 0x20) goto LAB_14001172f;
          break;
        }
        if ("AhciNonQueuedErrorRecovery"[lVar6 + 2] == '\0') {
          uVar8 = uVar8 + 2;
          goto LAB_140011729;
        }
        if ("AhciNonQueuedErrorRecovery"[lVar6 + 3] == '\0') {
          uVar8 = uVar8 + 3;
          goto LAB_140011729;
        }
        uVar8 = uVar8 + 4;
        lVar6 = lVar6 + 4;
      } while (uVar8 < 0x20);
      uVar8 = 0x20;
LAB_14001172f:
      memcpy(local_1d0,"AhciNonQueuedErrorRecovery",(ulonglong)uVar8);
      uVar8 = 0;
      local_1b0 = 1;
      lVar6 = 0;
      do {
        if ("PortReset|PortErrorRecovery"[lVar6] == '\0') goto LAB_14001178a;
        if ("PortReset|PortErrorRecovery"[lVar6 + 1] == '\0') {
          uVar8 = uVar8 + 1;
LAB_140011784:
          if (uVar8 < 0x20) goto LAB_14001178a;
          break;
        }
        if ("PortReset|PortErrorRecovery"[lVar6 + 2] == '\0') {
          uVar8 = uVar8 + 2;
          goto LAB_140011784;
        }
        if ("PortReset|PortErrorRecovery"[lVar6 + 3] == '\0') {
          uVar8 = uVar8 + 3;
          goto LAB_140011784;
        }
        uVar8 = uVar8 + 4;
        lVar6 = lVar6 + 4;
      } while (uVar8 < 0x20);
      uVar8 = 0x20;
LAB_14001178a:
      memcpy(local_198,"PortReset|PortErrorRecovery",(ulonglong)uVar8);
      uVar8 = 0;
      lVar6 = 0;
      do {
        if ("StartFail|NonQErrorRecovery"[lVar6] == '\0') goto LAB_1400117e1;
        if ("StartFail|NonQErrorRecovery"[lVar6 + 1] == '\0') {
          uVar8 = uVar8 + 1;
LAB_1400117db:
          if (uVar8 < 0x20) goto LAB_1400117e1;
          break;
        }
        if ("StartFail|NonQErrorRecovery"[lVar6 + 2] == '\0') {
          uVar8 = uVar8 + 2;
          goto LAB_1400117db;
        }
        if ("StartFail|NonQErrorRecovery"[lVar6 + 3] == '\0') {
          uVar8 = uVar8 + 3;
          goto LAB_1400117db;
        }
        uVar8 = uVar8 + 4;
        lVar6 = lVar6 + 4;
      } while (uVar8 < 0x20);
      uVar8 = 0x20;
LAB_1400117e1:
      local_178 = CONCAT44((int)uVar20,(int)uVar10);
      memcpy(local_170,"StartFail|NonQErrorRecovery",(ulonglong)uVar8);
      uVar8 = 0;
      lVar6 = 0;
      do {
        if ("NCQError|NCQErrorComplete"[lVar6] == '\0') goto LAB_14001183a;
        if ("NCQError|NCQErrorComplete"[lVar6 + 1] == '\0') {
          uVar8 = uVar8 + 1;
LAB_140011834:
          if (uVar8 < 0x20) goto LAB_14001183a;
          break;
        }
        if ("NCQError|NCQErrorComplete"[lVar6 + 2] == '\0') {
          uVar8 = uVar8 + 2;
          goto LAB_140011834;
        }
        if ("NCQError|NCQErrorComplete"[lVar6 + 3] == '\0') {
          uVar8 = uVar8 + 3;
          goto LAB_140011834;
        }
        uVar8 = uVar8 + 4;
        lVar6 = lVar6 + 4;
      } while (uVar8 < 0x20);
      uVar8 = 0x20;
LAB_14001183a:
      local_150 = CONCAT44(uVar11,uVar3);
      memcpy(local_148,"NCQError|NCQErrorComplete",(ulonglong)uVar8);
      uVar8 = 0;
      lVar6 = 0;
      do {
        if ("PortDriverResetCount"[lVar6] == '\0') goto LAB_140011890;
        if ("PortDriverResetCount"[lVar6 + 1] == '\0') {
          uVar8 = uVar8 + 1;
LAB_14001188a:
          if (uVar8 < 0x20) goto LAB_140011890;
          break;
        }
        if ("PortDriverResetCount"[lVar6 + 2] == '\0') {
          uVar8 = uVar8 + 2;
          goto LAB_14001188a;
        }
        if ("PortDriverResetCount"[lVar6 + 3] == '\0') {
          uVar8 = uVar8 + 3;
          goto LAB_14001188a;
        }
        uVar8 = uVar8 + 4;
        lVar6 = lVar6 + 4;
      } while (uVar8 < 0x20);
      uVar8 = 0x20;
LAB_140011890:
      local_128 = CONCAT44((int)uVar14,uVar2);
      memcpy(local_120,"PortDriverResetCount",(ulonglong)uVar8);
      uVar8 = 0;
      lVar6 = 0;
      do {
        if ("StateFlags"[lVar6] == '\0') goto LAB_1400118ea;
        if ("StateFlags"[lVar6 + 1] == '\0') {
          uVar8 = uVar8 + 1;
LAB_1400118e4:
          if (uVar8 < 0x20) goto LAB_1400118ea;
          break;
        }
        if ("StateFlags"[lVar6 + 2] == '\0') {
          uVar8 = uVar8 + 2;
          goto LAB_1400118e4;
        }
        if ("StateFlags"[lVar6 + 3] == '\0') {
          uVar8 = uVar8 + 3;
          goto LAB_1400118e4;
        }
        uVar8 = uVar8 + 4;
        lVar6 = lVar6 + 4;
      } while (uVar8 < 0x20);
      uVar8 = 0x20;
LAB_1400118ea:
      local_100 = (ulonglong)uVar9;
      memcpy(local_f8,"StateFlags",(ulonglong)uVar8);
      uVar9 = 0;
      lVar6 = 0;
      do {
        if ("StartState"[lVar6] == '\0') goto LAB_140011940;
        if ("StartState"[lVar6 + 1] == '\0') {
          uVar9 = uVar9 + 1;
LAB_14001193a:
          if (uVar9 < 0x20) goto LAB_140011940;
          break;
        }
        if ("StartState"[lVar6 + 2] == '\0') {
          uVar9 = uVar9 + 2;
          goto LAB_14001193a;
        }
        if ("StartState"[lVar6 + 3] == '\0') {
          uVar9 = uVar9 + 3;
          goto LAB_14001193a;
        }
        uVar9 = uVar9 + 4;
        lVar6 = lVar6 + 4;
      } while (uVar9 < 0x20);
      uVar9 = 0x20;
LAB_140011940:
      local_d8 = uVar12;
      memcpy(local_d0,"StartState",(ulonglong)uVar9);
      local_b0 = (ulonglong)local_220;
      uVar9 = 0;
      lVar6 = 0;
      do {
        if ("TotalCountSurpriseRemove"[lVar6] == '\0') {
LAB_14001199c:
          uVar13 = uVar9;
          break;
        }
        if ("TotalCountSurpriseRemove"[lVar6 + 1] == '\0') {
          uVar9 = uVar9 + 1;
LAB_140011998:
          if (uVar9 < 0x20) goto LAB_14001199c;
          break;
        }
        if ("TotalCountSurpriseRemove"[lVar6 + 2] == '\0') {
          uVar9 = uVar9 + 2;
          goto LAB_140011998;
        }
        if ("TotalCountSurpriseRemove"[lVar6 + 3] == '\0') {
          uVar9 = uVar9 + 3;
          goto LAB_140011998;
        }
        uVar9 = uVar9 + 4;
        lVar6 = lVar6 + 4;
      } while (uVar9 < 0x20);
      memcpy(local_a8,"TotalCountSurpriseRemove",(ulonglong)uVar13);
      local_88 = local_228;
      StorPortExtendedFunction(0x4f,local_218,param_1 + 1);
    }
  }
  local_220 = (longlong *)0x0;
  plVar19 = (longlong *)0x0;
  uVar9 = *(uint *)(param_1[0x129] + 0x38);
  uVar8 = *(uint *)(param_1[0x129] + 0x18);
  uVar7 = P_NotRunning((longlong *)param_1,param_1[0x129]);
  if ((char)uVar7 == '\0') {
    uVar11 = 0x10160013;
    goto LAB_140011e46;
  }
  uVar13 = *(uint *)((longlong)param_1 + 0x2dc);
  uVar12 = 0;
  uVar15 = uVar13;
  cVar16 = '\0';
  if (uVar13 == 0) {
LAB_140011a7c:
    if (((uVar8 & 1) != 0) && ((*(uint *)(*param_1 + 0x38) & 8) != 0)) {
      uVar11 = 0x10180013;
LAB_140011e46:
      RecordExecutionHistory((longlong *)param_1,uVar11);
      AhciPortReset(param_1,'\0');
      return;
    }
    uVar15 = uVar8 >> 8 & 0x1f;
    uVar14 = (ulonglong)uVar15;
    if (((uVar13 & 1 << (sbyte)uVar15) == 0) ||
       (param_1[((ulonglong)(uVar8 >> 8 & 0x1f) + 0x18) * 4] == 0)) {
      uVar11 = 0x10190013;
      goto LAB_140011e46;
    }
  }
  else {
    do {
      uVar14 = uVar12;
      cVar18 = cVar16 + '\x01';
      if ((uVar15 & 1) == 0) {
        cVar18 = cVar16;
      }
      uVar15 = uVar15 >> 1;
      uVar12 = (ulonglong)((int)uVar14 + 1);
      cVar16 = cVar18;
    } while (uVar15 != 0);
    if (cVar18 != '\x01') goto LAB_140011a7c;
    if (param_1[(uVar14 + 0x18) * 4] == 0) {
      uVar11 = 0x10170013;
      goto LAB_140011e46;
    }
  }
  if ((uVar8 & 1) != 0) {
    puVar17 = param_1 + (uVar14 + 0x18) * 4;
    local_38 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_48 = 0;
    uStack_40 = 0;
    uVar12 = *puVar17;
    if (*(char *)(uVar12 + 2) == '(') {
      uVar12 = *(ulonglong *)(uVar12 + 0x68);
    }
    else {
      uVar12 = *(ulonglong *)(uVar12 + 0x38);
    }
    if ((uVar12 & 0x7f) != 0) {
      uVar12 = (uVar12 - ((uint)uVar12 & 0x7f)) + 0x80;
    }
    uVar8 = 1 << ((byte)uVar14 & 0x1f);
    *(uint *)(param_1 + 0x5c) = (uint)param_1[0x5c] | uVar8;
    uVar8 = ~uVar8;
    *(uint *)((longlong)param_1 + 0x2e4) = *(uint *)((longlong)param_1 + 0x2e4) & uVar8;
    *(uint *)(param_1 + 0x5d) = (uint)param_1[0x5d] & uVar8;
    *(uint *)((longlong)param_1 + 0x2ec) = *(uint *)((longlong)param_1 + 0x2ec) & uVar8;
    uVar9 = uVar9 & uVar8;
    *(uint *)((longlong)param_1 + 0x2cc) = *(uint *)((longlong)param_1 + 0x2cc) & uVar8;
    *(uint *)((longlong)param_1 + 0x2dc) = uVar8 & uVar13;
    *(undefined1 *)(uVar12 + 0x1102) = *(undefined1 *)((longlong)param_1 + 0x27c);
    *(undefined1 *)(uVar12 + 0x1103) = *(undefined1 *)((longlong)param_1 + 0x27d);
    local_218 = CONCAT44(local_218._4_4_,uVar8);
    local_228 = puVar17;
    local_208 = uVar14;
    iVar5 = StorPortExtendedFunction(0x1c,*param_1,*puVar17,&local_58);
    if ((iVar5 == 0) && ((uStack_50 & 2) != 0)) {
      *(undefined1 *)(*puVar17 + 3) = 5;
    }
    else {
      *(undefined1 *)(*puVar17 + 3) = 4;
    }
    uVar12 = *puVar17;
    cVar16 = *(char *)(uVar12 + 2);
    if (cVar16 == '(') {
      uVar20 = *(ulonglong *)(uVar12 + 0x68);
    }
    else {
      uVar20 = *(ulonglong *)(uVar12 + 0x38);
    }
    if ((uVar20 & 0x7f) != 0) {
      uVar20 = (uVar20 - ((uint)uVar20 & 0x7f)) + 0x80;
    }
    uVar8 = 0;
    cVar18 = '\0';
    lVar6 = 0;
    if (cVar16 == '(') {
      if (*(int *)(uVar12 + 0x14) == 0) {
        if (*(uint *)(uVar12 + 0x38) != 0) {
          do {
            uVar13 = *(uint *)(uVar12 + 0x78 + (ulonglong)uVar8 * 4);
            if ((0x7f < uVar13) && (uVar15 = *(uint *)(uVar12 + 0x10), uVar13 < uVar15)) {
              piVar1 = (int *)(uVar13 + uVar12);
              uVar10 = (ulonglong)uVar13;
              iVar5 = *piVar1;
              if (iVar5 == 0x40) {
                uVar10 = uVar10 + 0x28;
LAB_140011d05:
                if (uVar15 < uVar10) goto LAB_140011d0a;
                lVar6 = *(longlong *)(piVar1 + 4);
              }
              else {
                if (iVar5 == 0x41) {
                  uVar10 = uVar10 + 0x38;
                  goto LAB_140011d05;
                }
                if ((iVar5 != 0x42) || ((ulonglong)uVar15 < uVar10 + 0x28)) goto LAB_140011d0a;
                lVar6 = *(longlong *)(piVar1 + 6);
              }
              cVar18 = *(char *)((longlong)piVar1 + 9);
              break;
            }
LAB_140011d0a:
            uVar8 = uVar8 + 1;
          } while (uVar8 < *(uint *)(uVar12 + 0x38));
        }
        puVar17 = local_228;
      }
    }
    else if (cVar16 == '\0') {
      lVar6 = *(longlong *)(uVar12 + 0x20);
      cVar18 = *(char *)(uVar12 + 0xb);
    }
    if (((((*(ushort *)(uVar20 + 0x1100) >> 9 & 1) == 0) || (*(ushort *)(uVar20 + 0x1100) == 0x201))
        || (*(char *)(uVar12 + 3) != '\x04')) || ((lVar6 == 0 || (cVar18 == '\0')))) {
      plVar19 = local_220;
    }
    else {
      plVar19 = BuildRequestSenseSrb(param_1,uVar12);
      if (plVar19 != (longlong *)0x0) {
        *puVar17 = 0;
        param_1[local_208 * 4 + 0x61] = 0;
        *(undefined1 *)(param_1 + local_208 * 4 + 0x5f) = 0;
        *(uint *)(param_1 + 0x5c) = (uint)param_1[0x5c] & (uint)local_218;
        RecordExecutionHistory((longlong *)param_1,0x10730013);
        goto LAB_140011d5d;
      }
    }
    ReleaseSlottedCommand((longlong *)param_1,(byte)uVar14);
    RecordExecutionHistory((longlong *)param_1,0x10630013);
  }
LAB_140011d5d:
  bVar4 = false;
  if (((char)*(uint *)(param_1[0x129] + 0x20) < '\0') ||
     ((*(uint *)(param_1[0x129] + 0x20) & 8) != 0)) {
    AhciCOMRESET((longlong *)param_1,param_1[0x129]);
    bVar4 = true;
  }
  *(uint *)((longlong)param_1 + 0x2d4) = *(uint *)((longlong)param_1 + 0x2d4) | uVar9;
  uVar9 = ~uVar9;
  *(uint *)((longlong)param_1 + 0x2dc) = *(uint *)((longlong)param_1 + 0x2dc) & uVar9;
  *(uint *)((longlong)param_1 + 0x2e4) = *(uint *)((longlong)param_1 + 0x2e4) & uVar9;
  *(uint *)(param_1 + 0x5d) = (uint)param_1[0x5d] & uVar9;
  *(uint *)((longlong)param_1 + 0x2ec) = *(uint *)((longlong)param_1 + 0x2ec) & uVar9;
  if ((int)param_1[0x5c] != 0) {
    AhciCompleteIssuedSRBs((longlong *)param_1,'\x01');
  }
  if (plVar19 != (longlong *)0x0) {
    param_1[0x4a] = param_1[0x4a] & 0xfffffffffffffffb;
    AhciProcessIo((longlong *)param_1,plVar19,1);
  }
  if (bVar4) {
    RestorePreservedSettings((longlong *)param_1,1);
  }
  *(byte *)((longlong)param_1 + 0x24d) = *(byte *)((longlong)param_1 + 0x24d) | 3;
  local_200 = 3;
  local_1f8 = 0;
  local_1f0 = 0;
  uStack_1e8 = 0;
  *(undefined4 *)(param_1 + 0x49) = 0x11;
  *(undefined1 *)((longlong)param_1 + 0x24c) = 0;
  *(undefined2 *)((longlong)param_1 + 0x24e) = 0;
  P_Running(param_1,'\0');
  RecordExecutionHistory((longlong *)param_1,0x10000013);
  return;
}



===== AhciPortErrorRecovery @ 140011e90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AhciPortErrorRecovery(ulonglong *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int *piVar12;
  ulonglong uVar13;
  size_t _Size;
  undefined1 auStack_2b8 [32];
  undefined8 local_298;
  wchar_t *local_290;
  undefined8 local_288;
  undefined4 local_280;
  undefined4 local_278;
  undefined8 local_270;
  wchar_t *local_268;
  ulonglong local_260;
  wchar_t *local_258;
  ulonglong local_250;
  wchar_t *local_248;
  ulonglong local_240;
  wchar_t *local_238;
  ulonglong local_230;
  wchar_t *local_228;
  ulonglong local_220;
  wchar_t *local_218;
  ulonglong local_210;
  wchar_t *local_208;
  undefined8 local_200;
  wchar_t *local_1f8;
  ulonglong local_1f0;
  ulonglong local_1e8;
  ulonglong local_1e0;
  ulonglong local_1d8;
  ulonglong local_1d0;
  ulonglong local_1c8 [2];
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined1 local_1b0 [32];
  undefined8 local_190;
  undefined1 local_178 [32];
  undefined8 local_158;
  undefined1 local_150 [32];
  undefined8 local_130;
  undefined1 local_128 [32];
  undefined8 local_108;
  undefined1 local_100 [32];
  ulonglong local_e0;
  undefined1 local_d8 [32];
  ulonglong local_b8;
  undefined1 local_b0 [32];
  ulonglong local_90;
  undefined1 local_88 [32];
  ulonglong local_68;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2b8;
  *(int *)(param_1 + 0x8bb) = (int)param_1[0x8bb] + 1;
  uVar13 = 0;
  local_1c8[0] = 0;
  if ((int)param_1[3] != 2) {
    StorPortQuerySystemTime(local_1c8);
    if ((param_1[0x8be] == 0) || (35999999999 < local_1c8[0] - param_1[0x8be])) {
      uVar5 = param_1[0x8bc];
      uVar1 = *(undefined4 *)((longlong)param_1 + 0x45d4);
      uVar6 = param_1[0x8ba];
      param_1[0x8be] = local_1c8[0];
      local_1e8 = (ulonglong)(uint)param_1[0x8bd];
      local_1e0 = param_1[0x49];
      local_1d8 = param_1[0x4a];
      uVar2 = *(undefined4 *)((longlong)param_1 + 0x45e4);
      uVar10 = *(uint *)((longlong)param_1 + 0xb4);
      uVar3 = *(undefined4 *)((longlong)param_1 + 0x45dc);
      uVar7 = param_1[0x8bb];
      local_1d0 = *param_1;
      memset(&local_1b8,0,0x180);
      uVar9 = 0;
      local_1b8 = 1;
      lVar8 = 0;
      local_1b4 = 3;
      do {
        _Size = 0x20;
        if ("AhciPortErrorRecovery"[lVar8] == '\0') goto LAB_140012003;
        if ("AhciPortErrorRecovery"[lVar8 + 1] == '\0') {
          uVar9 = uVar9 + 1;
LAB_140011ffb:
          if (uVar9 < 0x20) goto LAB_140012003;
          break;
        }
        if ("AhciPortErrorRecovery"[lVar8 + 2] == '\0') {
          uVar9 = uVar9 + 2;
          goto LAB_140011ffb;
        }
        if ("AhciPortErrorRecovery"[lVar8 + 3] == '\0') {
          uVar9 = uVar9 + 3;
          goto LAB_140011ffb;
        }
        uVar9 = uVar9 + 4;
        lVar8 = lVar8 + 4;
      } while (uVar9 < 0x20);
      uVar9 = 0x20;
LAB_140012003:
      memcpy(local_1b0,"AhciPortErrorRecovery",(ulonglong)uVar9);
      uVar9 = 0;
      local_190 = 1;
      lVar8 = 0;
      do {
        if ("PortReset|PortErrorRecovery"[lVar8] == '\0') goto LAB_14001205f;
        if ("PortReset|PortErrorRecovery"[lVar8 + 1] == '\0') {
          uVar9 = uVar9 + 1;
LAB_140012057:
          if (uVar9 < 0x20) goto LAB_14001205f;
          break;
        }
        if ("PortReset|PortErrorRecovery"[lVar8 + 2] == '\0') {
          uVar9 = uVar9 + 2;
          goto LAB_140012057;
        }
        if ("PortReset|PortErrorRecovery"[lVar8 + 3] == '\0') {
          uVar9 = uVar9 + 3;
          goto LAB_140012057;
        }
        uVar9 = uVar9 + 4;
        lVar8 = lVar8 + 4;
      } while (uVar9 < 0x20);
      uVar9 = 0x20;
LAB_14001205f:
      memcpy(local_178,"PortReset|PortErrorRecovery",(ulonglong)uVar9);
      uVar9 = 0;
      lVar8 = 0;
      do {
        if ("StartFail|NonQErrorRecovery"[lVar8] == '\0') goto LAB_1400120bd;
        if ("StartFail|NonQErrorRecovery"[lVar8 + 1] == '\0') {
          uVar9 = uVar9 + 1;
LAB_1400120b5:
          if (uVar9 < 0x20) goto LAB_1400120bd;
          break;
        }
        if ("StartFail|NonQErrorRecovery"[lVar8 + 2] == '\0') {
          uVar9 = uVar9 + 2;
          goto LAB_1400120b5;
        }
        if ("StartFail|NonQErrorRecovery"[lVar8 + 3] == '\0') {
          uVar9 = uVar9 + 3;
          goto LAB_1400120b5;
        }
        uVar9 = uVar9 + 4;
        lVar8 = lVar8 + 4;
      } while (uVar9 < 0x20);
      uVar9 = 0x20;
LAB_1400120bd:
      local_158 = CONCAT44((int)uVar6,(int)uVar7);
      memcpy(local_150,"StartFail|NonQErrorRecovery",(ulonglong)uVar9);
      uVar9 = 0;
      lVar8 = 0;
      do {
        if ("NCQError|NCQErrorComplete"[lVar8] == '\0') goto LAB_14001211d;
        if ("NCQError|NCQErrorComplete"[lVar8 + 1] == '\0') {
          uVar9 = uVar9 + 1;
LAB_140012115:
          if (uVar9 < 0x20) goto LAB_14001211d;
          break;
        }
        if ("NCQError|NCQErrorComplete"[lVar8 + 2] == '\0') {
          uVar9 = uVar9 + 2;
          goto LAB_140012115;
        }
        if ("NCQError|NCQErrorComplete"[lVar8 + 3] == '\0') {
          uVar9 = uVar9 + 3;
          goto LAB_140012115;
        }
        uVar9 = uVar9 + 4;
        lVar8 = lVar8 + 4;
      } while (uVar9 < 0x20);
      uVar9 = 0x20;
LAB_14001211d:
      local_130 = CONCAT44(uVar1,uVar3);
      memcpy(local_128,"NCQError|NCQErrorComplete",(ulonglong)uVar9);
      uVar9 = 0;
      lVar8 = 0;
      do {
        if ("PortDriverResetCount"[lVar8] == '\0') goto LAB_14001217d;
        if ("PortDriverResetCount"[lVar8 + 1] == '\0') {
          uVar9 = uVar9 + 1;
LAB_140012175:
          if (uVar9 < 0x20) goto LAB_14001217d;
          break;
        }
        if ("PortDriverResetCount"[lVar8 + 2] == '\0') {
          uVar9 = uVar9 + 2;
          goto LAB_140012175;
        }
        if ("PortDriverResetCount"[lVar8 + 3] == '\0') {
          uVar9 = uVar9 + 3;
          goto LAB_140012175;
        }
        uVar9 = uVar9 + 4;
        lVar8 = lVar8 + 4;
      } while (uVar9 < 0x20);
      uVar9 = 0x20;
LAB_14001217d:
      local_108 = CONCAT44((int)uVar5,uVar2);
      memcpy(local_100,"PortDriverResetCount",(ulonglong)uVar9);
      uVar9 = 0;
      lVar8 = 0;
      do {
        if ("StateFlags"[lVar8] == '\0') goto LAB_1400121e1;
        if ("StateFlags"[lVar8 + 1] == '\0') {
          uVar9 = uVar9 + 1;
LAB_1400121d9:
          if (uVar9 < 0x20) goto LAB_1400121e1;
          break;
        }
        if ("StateFlags"[lVar8 + 2] == '\0') {
          uVar9 = uVar9 + 2;
          goto LAB_1400121d9;
        }
        if ("StateFlags"[lVar8 + 3] == '\0') {
          uVar9 = uVar9 + 3;
          goto LAB_1400121d9;
        }
        uVar9 = uVar9 + 4;
        lVar8 = lVar8 + 4;
      } while (uVar9 < 0x20);
      uVar9 = 0x20;
LAB_1400121e1:
      local_e0 = (ulonglong)uVar10;
      memcpy(local_d8,"StateFlags",(ulonglong)uVar9);
      local_b8 = local_1d8;
      uVar10 = 0;
      lVar8 = 0;
      do {
        if ("StartState"[lVar8] == '\0') goto LAB_140012244;
        if ("StartState"[lVar8 + 1] == '\0') {
          uVar10 = uVar10 + 1;
LAB_14001223c:
          if (uVar10 < 0x20) goto LAB_140012244;
          break;
        }
        if ("StartState"[lVar8 + 2] == '\0') {
          uVar10 = uVar10 + 2;
          goto LAB_14001223c;
        }
        if ("StartState"[lVar8 + 3] == '\0') {
          uVar10 = uVar10 + 3;
          goto LAB_14001223c;
        }
        uVar10 = uVar10 + 4;
        lVar8 = lVar8 + 4;
      } while (uVar10 < 0x20);
      uVar10 = 0x20;
LAB_140012244:
      memcpy(local_b0,"StartState",(ulonglong)uVar10);
      local_90 = local_1e0;
      uVar10 = 0;
      lVar8 = 0;
      do {
        if ("TotalCountSurpriseRemove"[lVar8] == '\0') {
LAB_1400122aa:
          _Size = (size_t)uVar10;
          break;
        }
        if ("TotalCountSurpriseRemove"[lVar8 + 1] == '\0') {
          uVar10 = uVar10 + 1;
LAB_1400122a5:
          if (uVar10 < 0x20) goto LAB_1400122aa;
          break;
        }
        if ("TotalCountSurpriseRemove"[lVar8 + 2] == '\0') {
          uVar10 = uVar10 + 2;
          goto LAB_1400122a5;
        }
        if ("TotalCountSurpriseRemove"[lVar8 + 3] == '\0') {
          uVar10 = uVar10 + 3;
          goto LAB_1400122a5;
        }
        uVar10 = uVar10 + 4;
        lVar8 = lVar8 + 4;
      } while (uVar10 < 0x20);
      memcpy(local_88,"TotalCountSurpriseRemove",_Size);
      local_68 = local_1e8;
      StorPortExtendedFunction(0x4f,local_1d0,param_1 + 1,&local_1b8);
    }
  }
  if (((int)param_1[3] == 1) || ((int)param_1[3] - 3U < 3)) {
    local_1e8 = 0;
    if (*param_1 != 0) {
      piVar12 = (int *)param_1[0x8c4];
      if ((piVar12 != (int *)0x0) && (uVar10 = 0, (uint)param_1[0x8c5] != 0)) {
        piVar11 = piVar12;
        do {
          if (*piVar11 == 0x30) {
            piVar12 = piVar12 + (ulonglong)uVar10 * 8;
            if (piVar12 != (int *)0x0) {
              StorPortQuerySystemTime(&local_1e8);
              uVar10 = piVar12[7];
              uVar9 = piVar12[6];
              if ((*(longlong *)(piVar12 + 2) == 0) ||
                 (*(ulonglong *)(piVar12 + 4) <= local_1e8 - *(longlong *)(piVar12 + 2))) {
                *(ulonglong *)(piVar12 + 2) = local_1e8;
                piVar12[7] = 1;
                uVar13 = (ulonglong)(uVar10 - uVar9);
                if (uVar10 < uVar9) {
                  uVar13 = 0;
                }
              }
              else {
                piVar12[7] = uVar10 + 1;
                if (uVar9 <= uVar10) goto LAB_140012483;
                uVar13 = 0;
              }
              goto LAB_140012346;
            }
            break;
          }
          uVar10 = uVar10 + 1;
          piVar11 = piVar11 + 8;
        } while (uVar10 < (uint)param_1[0x8c5]);
      }
      uVar13 = 0;
    }
LAB_140012346:
    local_220 = (ulonglong)*(uint *)((longlong)param_1 + 0x45d4);
    local_230 = (ulonglong)(uint)param_1[0x8ba];
    local_250 = (ulonglong)(uint)param_1[0x8bb];
    local_1f0 = (ulonglong)*(uint *)((longlong)param_1 + 0x4604) << 0x20 | uVar13;
    local_200 = CONCAT44((int)param_1[0x8bc],*(undefined4 *)((longlong)param_1 + 0x45e4));
    local_210 = (ulonglong)*(uint *)((longlong)param_1 + 0x45dc);
    local_1f8 = L"BusChange|ThrottleCount";
    local_208 = L"NCQError|NCQErrorComplete";
    local_218 = L"NonQ\'dErrRecov";
    local_228 = L"RunningStrtFail";
    local_238 = L"PortReset";
    local_240 = param_1[0x49];
    local_248 = L"StartState";
    local_258 = L"PortErrRecovery";
    local_260 = param_1[0x4a];
    local_268 = L"StateFlags";
    local_270 = 0;
    local_278 = 0;
    local_280 = 3;
    local_288 = 0x10;
    local_290 = L"AhciPortErrorRecovery";
    local_298 = CONCAT44(local_298._4_4_,0x30);
    StorPortExtendedFunction(0x57,*param_1,param_1 + 1);
  }
LAB_140012483:
  if ((param_1[0x4a] >> 10 & 1) != 0) {
    param_1[0x4a] = param_1[0x4a] & 0xfffffffffffdf8ff;
    if ((*(char *)(*param_1 + 0x18c) == '\0') && (param_1[0x8c6] != 0)) {
      local_1e0 = 0;
      StorPortQuerySystemTime(&local_1e0);
      *(int *)((longlong)param_1 + 0x4604) = *(int *)((longlong)param_1 + 0x4604) + 1;
      uVar13 = param_1[0x8c6];
      if (*(longlong *)(uVar13 + 0x28) == 0) {
        *(int *)(uVar13 + 0x10) = *(int *)(uVar13 + 0x10) + 1;
      }
      else {
        if (local_1e0 - *(longlong *)(uVar13 + 0x28) < 36000000000) {
          *(int *)(uVar13 + 0x10) = *(int *)(uVar13 + 0x10) + 1;
          if (99 < *(uint *)(uVar13 + 0x10)) {
            *(int *)(uVar13 + 0x14) = *(int *)(uVar13 + 0x14) + 1;
            *(undefined4 *)(uVar13 + 0x10) = 0;
            *(undefined8 *)(uVar13 + 0x28) = 0;
            AhciPortMarkDeviceFailed((longlong *)param_1,1,2);
          }
          goto LAB_1400125c6;
        }
        *(undefined4 *)(uVar13 + 0x10) = 1;
      }
      *(ulonglong *)(uVar13 + 0x28) = local_1e0;
    }
LAB_1400125c6:
    uVar13 = *param_1;
    if (*(char *)(uVar13 + 0x18c) == '\0') {
      local_290 = (wchar_t *)&local_1d0;
      local_1d0 = local_1d0 & 0xffffffff00000000;
      local_298 = 0;
      StorPortNotification(0x1002,uVar13,param_1 + 0x120,param_1);
    }
    else {
      AhciPortBusChangeDpcRoutine(param_1 + 0x120,uVar13,param_1);
    }
  }
  if ((param_1[0x4a] >> 0x11 & 1) != 0) {
    param_1[0x4a] = param_1[0x4a] & 0xfffffffffffdfcff;
    if ((*(char *)(*param_1 + 0x18c) == '\0') && (param_1[0x8c6] != 0)) {
      local_1d8 = 0;
      StorPortQuerySystemTime(&local_1d8);
      *(int *)(param_1 + 0x8bc) = (int)param_1[0x8bc] + 1;
      puVar4 = (uint *)param_1[0x8c6];
      if (*(longlong *)(puVar4 + 6) == 0) {
        *puVar4 = *puVar4 + 1;
      }
      else {
        if (local_1d8 - *(longlong *)(puVar4 + 6) < 36000000000) {
          *puVar4 = *puVar4 + 1;
          if (99 < *puVar4) {
            puVar4[1] = puVar4[1] + 1;
            *puVar4 = 0;
            puVar4[6] = 0;
            puVar4[7] = 0;
            AhciPortMarkDeviceFailed((longlong *)param_1,2,2);
          }
          goto LAB_1400126b3;
        }
        *puVar4 = 1;
      }
      *(ulonglong *)(puVar4 + 6) = local_1d8;
    }
LAB_1400126b3:
    if ((((param_1[0x4b] & 0x200) == 0) && ((*(uint *)((longlong)param_1 + 0x16c) & 1) != 0)) &&
       (((uint)param_1[0x16] < 6 || ((*(uint *)(*param_1 + 0x5c) & 2) != 0)))) {
      AhciNcqErrorRecovery(param_1);
    }
    else {
      param_1[0x4a] = param_1[0x4a] | 0x100;
    }
  }
  if ((param_1[0x4a] >> 8 & 1) != 0) {
    param_1[0x4a] = param_1[0x4a] & 0xfffffffffffffcff;
    AhciPortReset(param_1,'\0');
  }
  if ((param_1[0x4a] >> 9 & 1) == 0) {
    return;
  }
  param_1[0x4a] = param_1[0x4a] & 0xfffffffffffffdff;
  if ((*(char *)(*param_1 + 0x18c) == '\0') && (param_1[0x8c6] != 0)) {
    local_1e8 = 0;
    StorPortQuerySystemTime(&local_1e8);
    *(int *)((longlong)param_1 + 0x45dc) = *(int *)((longlong)param_1 + 0x45dc) + 1;
    uVar13 = param_1[0x8c6];
    if (*(longlong *)(uVar13 + 0x20) == 0) {
      *(int *)(uVar13 + 8) = *(int *)(uVar13 + 8) + 1;
    }
    else {
      if (local_1e8 - *(longlong *)(uVar13 + 0x20) < 36000000000) {
        *(int *)(uVar13 + 8) = *(int *)(uVar13 + 8) + 1;
        if (199 < *(uint *)(uVar13 + 8)) {
          *(int *)(uVar13 + 0xc) = *(int *)(uVar13 + 0xc) + 1;
          *(undefined4 *)(uVar13 + 8) = 0;
          *(undefined8 *)(uVar13 + 0x20) = 0;
          AhciPortMarkDeviceFailed((longlong *)param_1,3,2);
        }
        goto LAB_1400127d3;
      }
      *(undefined4 *)(uVar13 + 8) = 1;
    }
    *(ulonglong *)(uVar13 + 0x20) = local_1e8;
  }
LAB_1400127d3:
  AhciNonQueuedErrorRecovery(param_1);
  return;
}



===== AhciPortLogDeviceReset @ 140012800 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AhciPortLogDeviceReset(longlong *param_1,char param_2)

{
  wchar_t *pwVar1;
  uint *puVar2;
  wchar_t wVar3;
  longlong lVar4;
  size_t _Size;
  bool bVar5;
  uint uVar6;
  longlong *plVar7;
  int iVar8;
  wchar_t *_Src;
  undefined1 auStack_178 [32];
  int local_158;
  wchar_t *local_150;
  undefined8 local_148;
  undefined4 local_140;
  undefined4 local_138;
  undefined8 local_130;
  wchar_t *local_128;
  longlong local_120;
  wchar_t *local_118;
  ulonglong local_110;
  wchar_t *local_108;
  undefined8 local_100;
  wchar_t *local_f8;
  undefined8 local_f0;
  wchar_t *local_e8;
  ulonglong local_e0;
  wchar_t *local_d8;
  longlong local_d0;
  wchar_t *local_c8;
  longlong local_c0;
  wchar_t *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_178;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if ((*(char *)(*param_1 + 0x18c) == '\0') && ((int)param_1[3] != 2)) {
    LOCK();
    puVar2 = (uint *)(param_1 + 0x4a);
    uVar6 = *puVar2;
    *puVar2 = *puVar2 & 0xff7fffff;
    UNLOCK();
    plVar7 = param_1;
    if ((uVar6 >> 0x17 & 1) == 0) {
      LOCK();
      puVar2 = (uint *)(param_1 + 0x4a);
      uVar6 = *puVar2;
      *puVar2 = *puVar2 & 0xfeffffff;
      UNLOCK();
      if ((uVar6 >> 0x18 & 1) == 0) {
        if (((ulonglong)param_1[0x4a] >> 0x16 & 1) == 0) {
          iVar8 = 0x23;
          _Src = L"Port reset:Error recover";
        }
        else {
          iVar8 = 0x1b;
          _Src = L"Port reset:Power up in progress";
        }
      }
      else {
        iVar8 = 0x1f;
        _Src = L"Port reset:Bus change";
      }
    }
    else if (param_2 == '\0') {
      bVar5 = IsThereIoOutstandingInDevice((longlong)param_1);
      if (bVar5) {
        iVar8 = 0x20;
        _Src = L"Port reset:Device timeout IO";
      }
      else if ((((int)plVar7[0x5a] == 0) && (*(int *)((longlong)plVar7 + 0x2d4) == 0)) &&
              ((int)plVar7[0x5b] == 0)) {
        iVar8 = 0x24;
        _Src = L"Port reset:Unknown reason";
      }
      else {
        iVar8 = 0x21;
        _Src = L"Port reset:IO stuck";
      }
    }
    else {
      iVar8 = 0x22;
      _Src = L"Reset:IO timeout DPC related";
    }
    bVar5 = AhciIsEventAllowedWithinThrottleLimit(*plVar7,(longlong)param_1,iVar8,(int *)0x0);
    if (bVar5) {
      local_b0 = CONCAT44((int)param_1[0x8bb],*(undefined4 *)((longlong)param_1 + 0x4604));
      local_c0 = CONCAT44((int)param_1[0x5d],*(undefined4 *)((longlong)param_1 + 0x2ec));
      local_d0 = CONCAT44((int)param_1[0x5c],*(undefined4 *)((longlong)param_1 + 0x2e4));
      local_e0 = CONCAT44((int)param_1[0x5b],*(undefined4 *)((longlong)param_1 + 0x2dc));
      local_f0 = CONCAT44((int)param_1[0x5a],*(undefined4 *)((longlong)param_1 + 0x2d4));
      local_100 = CONCAT44((int)param_1[0x8ba],*(undefined4 *)((longlong)param_1 + 0x45d4));
      local_b8 = L"ErrorRecovery|BusChange";
      local_c8 = L"NormalIssued|SingleIssued";
      local_d8 = L"CTC|NCQIssued";
      local_e8 = L"SingleIOSlice|CI";
      local_f8 = L"NCQSlice|NormalSlice";
      local_108 = L"PortReset|StartFailed";
      local_110 = param_1[0x49];
      local_118 = L"StartState";
      local_120 = param_1[0x4a];
      local_128 = L"StateFlag";
      local_130 = 0;
      local_138 = 0;
      local_140 = 3;
      local_148 = 0x10;
      local_158 = iVar8;
      local_150 = _Src;
      StorPortExtendedFunction(0x57,*param_1,param_1 + 1,2);
      uVar6 = 0;
      wVar3 = *_Src;
      pwVar1 = _Src;
      while (wVar3 != L'\0') {
        pwVar1 = pwVar1 + 1;
        uVar6 = uVar6 + 1;
        wVar3 = *pwVar1;
      }
      _Size = (ulonglong)uVar6 * 2;
      memcpy(&local_a8,_Src,_Size);
      lVar4 = *param_1;
      local_b0 = CONCAT44(*(undefined4 *)((longlong)param_1 + 0xb4),(int)param_1[0x17]);
      local_c0 = CONCAT44(*(undefined4 *)((longlong)param_1 + 0xac),(int)param_1[0x16]);
      local_b8 = L"PortDriverReset|TotalReset";
      local_d0 = CONCAT44(*(undefined4 *)((longlong)param_1 + 0xa4),(int)param_1[0x15]);
      local_e0 = CONCAT44(*(undefined4 *)((longlong)param_1 + 0x9c),(int)param_1[0x14]);
      local_c8 = L"OtherError|NcqReadLogError";
      local_f0 = CONCAT44(*(undefined4 *)((longlong)param_1 + 0x94),(int)param_1[0x13]);
      local_100 = CONCAT44((int)param_1[0x12],*(undefined4 *)((longlong)param_1 + 0x460c));
      *(undefined4 *)((longlong)&local_a8 + _Size) = 0x2b;
      local_110 = (ulonglong)*(uint *)(lVar4 + 0x30);
      local_d8 = L"AbortedCommand|DeviceFault";
      local_e8 = L"EndofMedia|IllegalCommand";
      local_f8 = L"CrcError|MediaError";
      local_108 = L"SuccessCount|UnsolicitedINT";
      local_118 = L"AdapterErrorFlag";
      local_120 = *(undefined8 *)(lVar4 + 0x2c);
      local_128 = L"AdapterStateFlag";
      local_150 = (wchar_t *)&local_a8;
      local_130 = 0;
      local_138 = 0;
      local_140 = 3;
      local_148 = 0x10;
      local_158 = iVar8;
      StorPortExtendedFunction(0x57,lVar4,param_1 + 1);
      lVar4 = param_1[0x8bf];
      local_e0 = (ulonglong)*(uint *)((longlong)param_1 + 0x462c);
      *(undefined4 *)((longlong)&local_a8 + _Size) = 0x2b002b;
      *(undefined2 *)((longlong)&local_a8 + _Size + 4) = 0;
      local_f0 = CONCAT44((int)lVar4,*(undefined4 *)((longlong)param_1 + 0x45fc));
      local_b0 = 0;
      local_b8 = (wchar_t *)0x0;
      local_100 = CONCAT44((int)param_1[0x8bd],*(undefined4 *)((longlong)param_1 + 0x45ec));
      local_110 = CONCAT44((int)param_1[0x8bc],*(undefined4 *)((longlong)param_1 + 0x45e4));
      local_120 = CONCAT44((int)param_1[0x8c0],*(undefined4 *)((longlong)param_1 + 0x45dc));
      local_c0 = param_1[0x8c3];
      local_c8 = L"LastTimestampDpcComplete";
      local_d0 = param_1[0x8c2];
      local_d8 = L"LastTimestampDpcStart";
      local_e8 = L"ResetNotWork";
      local_f8 = L"PowerUp|PowerDown";
      local_108 = L"SurpriseRemove|PowerSetting";
      local_118 = L"NCQError|NCQErrorComplete";
      local_128 = L"PortStartTime|NonQError";
      local_150 = (wchar_t *)&local_a8;
      local_130 = 0;
      local_138 = 0;
      local_140 = 3;
      local_148 = 0x10;
      local_158 = iVar8;
      StorPortExtendedFunction(0x57,*param_1,param_1 + 1);
    }
  }
  return;
}



===== RecordInterruptHistory @ 140012e30 =====

void RecordInterruptHistory
               (longlong *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  bool bVar7;
  
  if (param_1[0x8b9] != 0) {
    do {
      uVar2 = *(uint *)((longlong)param_1 + 0x45c4);
      uVar5 = 0;
      if (uVar2 < 199) {
        uVar5 = (ulonglong)(uVar2 + 1);
      }
      LOCK();
      bVar7 = uVar2 == *(uint *)((longlong)param_1 + 0x45c4);
      if (bVar7) {
        *(uint *)((longlong)param_1 + 0x45c4) = (uint)uVar5;
      }
      UNLOCK();
    } while (!bVar7);
    lVar6 = uVar5 * 0x78;
    StorPortQuerySystemTime(param_1[0x8b9] + 0x70 + lVar6);
    *(undefined4 *)(lVar6 + param_1[0x8b9]) = param_7;
    if (*(longlong *)(*param_1 + 0x1a0) == 0) {
      *(undefined4 *)(param_1[0x8b9] + 4 + lVar6) = 0xffffffff;
    }
    else {
      *(int *)(param_1[0x8b9] + 4 + lVar6) = (int)param_1[0x4a];
    }
    lVar3 = param_1[0x8b9];
    uVar4 = *(undefined8 *)((longlong)param_1 + 0x2d4);
    puVar1 = (undefined8 *)(lVar3 + 8 + lVar6);
    *puVar1 = *(undefined8 *)((longlong)param_1 + 0x2cc);
    puVar1[1] = uVar4;
    uVar4 = *(undefined8 *)((longlong)param_1 + 0x2e4);
    puVar1 = (undefined8 *)(lVar3 + 0x18 + lVar6);
    *puVar1 = *(undefined8 *)((longlong)param_1 + 0x2dc);
    puVar1[1] = uVar4;
    *(undefined8 *)(lVar3 + 0x28 + lVar6) = *(undefined8 *)((longlong)param_1 + 0x2ec);
    lVar3 = param_1[0x8b9];
    *(undefined8 *)(lVar3 + 0x30 + lVar6) = 0;
    *(undefined8 *)(lVar3 + 0x38 + lVar6) = 0;
    *(undefined8 *)(lVar3 + 0x40 + lVar6) = 0;
    *(undefined8 *)(lVar3 + 0x48 + lVar6) = 0;
    *(undefined8 *)(lVar3 + 0x50 + lVar6) = 0;
    *(undefined8 *)(lVar3 + 0x58 + lVar6) = 0;
    *(undefined8 *)(lVar3 + 0x60 + lVar6) = 0;
    *(undefined8 *)(lVar3 + 0x68 + lVar6) = 0;
    *(undefined4 *)(param_1[0x8b9] + 0x40 + lVar6) = param_2;
    *(undefined4 *)(param_1[0x8b9] + 0x58 + lVar6) = param_3;
    *(undefined4 *)(param_1[0x8b9] + 0x60 + lVar6) = param_4;
    *(undefined4 *)(param_1[0x8b9] + 100 + lVar6) = param_6;
    *(undefined4 *)(param_1[0x8b9] + 0x68 + lVar6) = param_5;
  }
  return;
}



===== ReleaseSlottedCommand @ 140012fd0 =====

void ReleaseSlottedCommand(longlong *param_1,byte param_2)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  bool bVar7;
  short sVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong *plVar12;
  longlong *plVar13;
  uint uVar14;
  ulonglong uVar15;
  byte *pbVar16;
  undefined8 local_res8;
  
  lVar10 = *param_1;
  local_res8 = 0;
  pbVar16 = (byte *)(param_1 + (ulonglong)param_2 * 4 + 0x5f);
  plVar13 = *(longlong **)(pbVar16 + 8);
  if (plVar13 == (longlong *)0x0) {
    return;
  }
  if (*(char *)((longlong)plVar13 + 2) == '(') {
    uVar11 = plVar13[0xd];
  }
  else {
    uVar11 = plVar13[7];
  }
  if ((uVar11 & 0x7f) != 0) {
    uVar11 = (uVar11 - ((uint)uVar11 & 0x7f)) + 0x80;
  }
  sVar8 = *(short *)(uVar11 + 0x1100);
  bVar7 = false;
  if (plVar13 == param_1 + 0x13b) {
    bVar7 = false;
    if (((ulonglong)param_1[0x4a] >> 0x12 & 1) != 0) {
      bVar7 = true;
    }
  }
  if ((*(uint *)(*param_1 + 0x34) & 1) != 0) {
    RecordExecutionHistory(param_1,0x10000053);
  }
  if ((*(uint *)(*param_1 + 0x34) & 2) != 0) {
    *pbVar16 = *pbVar16 & 0x3f;
    bVar1 = *pbVar16;
    lVar3 = param_1[299];
    uVar4 = *(undefined4 *)(lVar3 + 0x44);
    uVar5 = *(undefined4 *)(lVar3 + 0x48);
    uVar6 = *(undefined4 *)(lVar3 + 0x4c);
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb54) =
         *(undefined4 *)(lVar3 + 0x40);
    *(undefined4 *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x16b) = uVar4;
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb5c) = uVar5;
    *(undefined4 *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x16c) = uVar6;
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb64) =
         *(undefined4 *)(lVar3 + 0x50);
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb14) =
         *(undefined4 *)param_1[0x129];
    *(undefined4 *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x163) = *(undefined4 *)(param_1[0x129] + 4)
    ;
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb1c) =
         *(undefined4 *)(param_1[0x129] + 8);
    *(undefined4 *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x164) =
         *(undefined4 *)(param_1[0x129] + 0xc);
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb24) =
         *(undefined4 *)(param_1[0x129] + 0x10);
    *(undefined4 *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x165) =
         *(undefined4 *)(param_1[0x129] + 0x14);
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb2c) =
         *(undefined4 *)(param_1[0x129] + 0x18);
    *(undefined4 *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x166) =
         *(undefined4 *)(param_1[0x129] + 0x1c);
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb34) =
         *(undefined4 *)(param_1[0x129] + 0x20);
    *(undefined4 *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x167) =
         *(undefined4 *)(param_1[0x129] + 0x24);
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb3c) =
         *(undefined4 *)(param_1[0x129] + 0x28);
    *(undefined4 *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x168) =
         *(undefined4 *)(param_1[0x129] + 0x2c);
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb44) =
         *(undefined4 *)(param_1[0x129] + 0x30);
    *(undefined4 *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x169) =
         *(undefined4 *)(param_1[0x129] + 0x34);
    *(undefined4 *)((longlong)param_1 + (ulonglong)bVar1 * 0xb0 + 0xb4c) =
         *(undefined4 *)(param_1[0x129] + 0x38);
    *(undefined4 *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x16a) =
         *(undefined4 *)(param_1[0x129] + 0x3c);
    *(uint *)(param_1 + (ulonglong)bVar1 * 0x16 + 0x16e) =
         (uint)*(byte *)(*(longlong *)(pbVar16 + 8) + 3);
    StorPortExtendedFunction(0x2f,lVar10);
    *(undefined8 *)((ulonglong)*pbVar16 * 0x3c + 0x36ec + (longlong)param_1) = local_res8;
  }
  plVar13 = *(longlong **)(pbVar16 + 8);
  if (sVar8 == 0x201) {
    if (*(char *)((longlong)plVar13 + 2) == '(') {
      plVar12 = (longlong *)plVar13[10];
    }
    else {
      plVar12 = (longlong *)plVar13[6];
    }
    if (*(char *)((longlong)plVar13 + 3) == '\x01') {
      *(byte *)((longlong)plVar12 + 3) = *(byte *)((longlong)plVar12 + 3) | 0x80;
      if (*(char *)((longlong)plVar12 + 2) != '(') {
        *(undefined1 *)((longlong)plVar12 + 4) = 2;
        *(undefined2 *)(uVar11 + 0x1100) = 0;
        plVar13 = plVar12;
        goto LAB_140013382;
      }
      if (*(int *)((longlong)plVar12 + 0x14) == 0) {
        uVar15 = 0;
        if (*(uint *)(plVar12 + 7) != 0) {
          do {
            uVar14 = *(uint *)((longlong)plVar12 + uVar15 * 4 + 0x78);
            if ((0x7f < uVar14) && (uVar14 < *(uint *)(plVar12 + 2))) {
              iVar2 = *(int *)((ulonglong)uVar14 + (longlong)plVar12);
              if (iVar2 == 0x40) {
LAB_14001329e:
                uVar9 = (ulonglong)uVar14 + 0x28;
              }
              else {
                if (iVar2 != 0x41) {
                  if (iVar2 != 0x42) goto LAB_1400132a7;
                  goto LAB_14001329e;
                }
                uVar9 = (ulonglong)uVar14 + 0x38;
              }
              if (uVar9 <= *(uint *)(plVar12 + 2)) {
                *(undefined1 *)((int *)((ulonglong)uVar14 + (longlong)plVar12) + 2) = 2;
                *(undefined2 *)(uVar11 + 0x1100) = 0;
                plVar13 = plVar12;
                goto LAB_140013382;
              }
            }
LAB_1400132a7:
            uVar14 = (int)uVar15 + 1;
            uVar15 = (ulonglong)uVar14;
          } while (uVar14 < *(uint *)(plVar12 + 7));
          *(undefined2 *)(uVar11 + 0x1100) = 0;
          plVar13 = plVar12;
          goto LAB_140013382;
        }
      }
    }
    else {
      *(byte *)((longlong)plVar12 + 3) = *(byte *)((longlong)plVar12 + 3) & 0x7f;
    }
    *(undefined2 *)(uVar11 + 0x1100) = 0;
    plVar13 = plVar12;
  }
  else if ((*(uint *)(uVar11 + 0x1104) >> 0xb & 1) == 0) {
    *(undefined1 *)(uVar11 + 0x1102) = *(undefined1 *)((longlong)param_1 + 0x27c);
    *(undefined1 *)(uVar11 + 0x1103) = *(undefined1 *)((longlong)param_1 + 0x27d);
    if ((*(uint *)(uVar11 + 0x1104) & 0x40) != 0) {
      SetReturnRegisterValues((longlong)param_1,(longlong)plVar13);
    }
    if (((*(ushort *)(uVar11 + 0x1100) >> 8 & 1) == 0) && (*(ushort *)(uVar11 + 0x1100) != 0x400)) {
      if ((*plVar13 & 0x3f000000) == 0x1000000) {
        *(int *)(param_1 + 0x12) = (int)param_1[0x12] + 1;
      }
      else {
        *(int *)((longlong)param_1 + 0xac) = *(int *)((longlong)param_1 + 0xac) + 1;
      }
    }
    else {
      AtaMapError((longlong)param_1,(longlong)plVar13,pbVar16[1] & 1);
    }
  }
LAB_140013382:
  if ((*(uint *)(*param_1 + 0x34) & 2) != 0) {
    StorPortExtendedFunction(0x2f,lVar10,0,&local_res8);
    lVar10 = (ulonglong)*pbVar16 * 0x3c;
    *(undefined8 *)(lVar10 + 0x36ec + (longlong)param_1) = local_res8;
    *(uint *)(lVar10 + 0x36f4 + (longlong)param_1) = (uint)*(byte *)(uVar11 + 0x1102);
    *(uint *)(lVar10 + 0x36f8 + (longlong)param_1) = (uint)*(byte *)(uVar11 + 0x1103);
  }
  pbVar16[1] = pbVar16[1] & 0xfe;
  pbVar16[0x10] = 0;
  pbVar16[0x11] = 0;
  pbVar16[0x12] = 0;
  pbVar16[0x13] = 0;
  pbVar16[0x14] = 0;
  pbVar16[0x15] = 0;
  pbVar16[0x16] = 0;
  pbVar16[0x17] = 0;
  uVar14 = ~(1 << (param_2 & 0x1f));
  *pbVar16 = 0;
  pbVar16[8] = 0;
  pbVar16[9] = 0;
  pbVar16[10] = 0;
  pbVar16[0xb] = 0;
  pbVar16[0xc] = 0;
  pbVar16[0xd] = 0;
  pbVar16[0xe] = 0;
  pbVar16[0xf] = 0;
  *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) & uVar14;
  *(uint *)((longlong)param_1 + 0x2cc) = *(uint *)((longlong)param_1 + 0x2cc) & uVar14;
  if (((ulonglong)param_1[0x4a] >> 0x12 & 1) == 0) {
    param_1[0x4a] = param_1[0x4a] & 0xfffffffffffffffb;
  }
  if (((*(char *)((longlong)plVar13 + 3) != '\x01') && (sVar8 != 0x201)) &&
     (*(char *)(uVar11 + 0x2979) == '\0')) {
    if (((char)param_1[0x4a] < '\0') && (sVar8 = IsNCQWriteCommand(uVar11), (char)sVar8 != '\0')) {
      param_1[0x4a] = param_1[0x4a] & 0xffffffffffffff7f;
    }
    else if (*(char *)((longlong)plVar13 + 3) != '\x0f') goto LAB_140013493;
    if (!bVar7) {
      *(undefined1 *)((longlong)plVar13 + 3) = 0;
      *(char *)(uVar11 + 0x2979) = *(char *)(uVar11 + 0x2979) + '\x01';
      AhciProcessIo(param_1,plVar13,1);
      return;
    }
  }
LAB_140013493:
  AhciCompleteRequest(param_1,plVar13,'\x01');
  return;
}



===== AhciCompleteIssuedSRBs @ 1400134d0 =====

void AhciCompleteIssuedSRBs(longlong *param_1,char param_2)

{
  ushort uVar1;
  longlong lVar2;
  longlong *plVar3;
  byte bVar4;
  char cVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  byte bVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong local_res8;
  longlong local_res20;
  
  lVar2 = *param_1;
  local_res20 = 0;
  local_res8 = 0;
  if ((*(uint *)(lVar2 + 0x34) & 1) != 0) {
    RecordExecutionHistory(param_1,0x46);
  }
  if ((*(char *)(lVar2 + 0x18e) != '\0') && ((int)param_1[0x5c] != 0)) {
    StorPortExtendedFunction(0x2f,lVar2,&local_res8,&local_res20);
  }
  bVar11 = 0;
  uVar7 = local_res8;
  do {
    uVar8 = 1 << (bVar11 & 0x1f);
    uVar9 = *(uint *)(param_1 + 0x5c);
    if ((uVar9 & uVar8) != 0) {
      plVar3 = (longlong *)param_1[(ulonglong)bVar11 * 4 + 0x60];
      if (plVar3 == (longlong *)0x0) {
        *(uint *)((longlong)param_1 + 0x2cc) = *(uint *)((longlong)param_1 + 0x2cc) & ~uVar8;
        *(uint *)(param_1 + 0x5c) = ~uVar8 & uVar9;
      }
      else {
        if (param_1[(ulonglong)bVar11 * 4 + 0x61] == 0) {
          *(uint *)((longlong)param_1 + 0x2cc) = *(uint *)((longlong)param_1 + 0x2cc) & ~uVar8;
          *(uint *)(param_1 + 0x5c) = ~uVar8 & uVar9;
          *(undefined1 *)(param_1[(ulonglong)bVar11 * 4 + 0x60] + 3) = 2;
          AhciCompleteRequest(param_1,(longlong *)param_1[(ulonglong)bVar11 * 4 + 0x60],'\x01');
        }
        else {
          if (*(char *)((longlong)plVar3 + 2) == '(') {
            uVar10 = plVar3[0xd];
          }
          else {
            uVar10 = plVar3[7];
          }
          if ((uVar10 & 0x7f) != 0) {
            uVar10 = (uVar10 - ((uint)uVar10 & 0x7f)) + 0x80;
          }
          if ((((*(char *)(lVar2 + 0x18e) != '\0') && (*(longlong *)(uVar10 + 0x2980) != 0)) &&
              (local_res20 != 0)) && ((plVar3 != param_1 + 0x12e && (plVar3 != param_1 + 0x13b)))) {
            lVar6 = 0;
            if (uVar7 != 0) {
              uVar12 = local_res20 - *(longlong *)(uVar10 + 0x2980);
              uVar13 = (uVar12 % uVar7) * 1000;
              lVar6 = (uVar13 / uVar7 + (uVar12 / uVar7) * 1000) * 10000 +
                      ((uVar13 % uVar7) * 10000) / uVar7;
            }
            StorPortNotification(0x1006,lVar2,lVar6);
          }
          if (((param_2 == '\x01') && (uVar1 = *(ushort *)(uVar10 + 0x1100), uVar1 != 0x201)) &&
             (uVar1 != 0x105)) {
            if (uVar1 == 0x400) {
              bVar4 = *(byte *)(uVar10 + 0x110a);
LAB_140013712:
              if (((bVar4 != 0x62) && (0x5f < bVar4)) && (bVar4 < 0x66)) goto LAB_14001381f;
            }
            else if ((uVar1 >> 8 & 1) != 0) {
              bVar4 = *(byte *)(uVar10 + 0x110e);
              goto LAB_140013712;
            }
            lVar6 = param_1[(ulonglong)bVar11 * 4 + 0x60];
            cVar5 = *(char *)(lVar6 + 2);
            if (cVar5 == '(') {
              uVar7 = *(ulonglong *)(lVar6 + 0x68);
            }
            else {
              uVar7 = *(ulonglong *)(lVar6 + 0x38);
            }
            if ((uVar7 & 0x7f) != 0) {
              uVar7 = (uVar7 - ((uint)uVar7 & 0x7f)) + 0x80;
            }
            uVar9 = *(uint *)(uVar7 + 0x1130);
            if (uVar9 == 0) {
              if (cVar5 == '(') {
                uVar9 = *(uint *)(lVar6 + 0x3c);
              }
              else {
                uVar9 = *(uint *)(lVar6 + 0x10);
              }
            }
            uVar8 = *(uint *)(param_1[(ulonglong)bVar11 * 4 + 0x61] + 4);
            if (uVar8 == uVar9) goto LAB_14001381f;
            if (cVar5 == '(') {
              uVar7 = *(ulonglong *)(lVar6 + 0x68);
            }
            else {
              uVar7 = *(ulonglong *)(lVar6 + 0x38);
            }
            if ((uVar7 & 0x7f) != 0) {
              uVar7 = (uVar7 - ((uint)uVar7 & 0x7f)) + 0x80;
            }
            uVar9 = *(uint *)(uVar7 + 0x1130);
            if (uVar9 == 0) {
              if (cVar5 == '(') {
                uVar9 = *(uint *)(lVar6 + 0x3c);
              }
              else {
                uVar9 = *(uint *)(lVar6 + 0x10);
              }
            }
            if (uVar8 < uVar9) {
              if (cVar5 == '(') {
                uVar7 = *(ulonglong *)(lVar6 + 0x68);
              }
              else {
                uVar7 = *(ulonglong *)(lVar6 + 0x38);
              }
              if ((uVar7 & 0x7f) != 0) {
                uVar7 = (uVar7 - ((uint)uVar7 & 0x7f)) + 0x80;
              }
              if (*(int *)(uVar7 + 0x1130) == 0) {
                if (cVar5 == '(') {
                  *(uint *)(lVar6 + 0x3c) = uVar8;
                  *(undefined1 *)(param_1[(ulonglong)bVar11 * 4 + 0x60] + 3) = 1;
                }
                else {
                  *(uint *)(lVar6 + 0x10) = uVar8;
                  *(undefined1 *)(param_1[(ulonglong)bVar11 * 4 + 0x60] + 3) = 1;
                }
              }
              else {
                *(uint *)(uVar7 + 0x1130) = uVar8;
                *(undefined1 *)(param_1[(ulonglong)bVar11 * 4 + 0x60] + 3) = 1;
              }
            }
            else {
              *(undefined1 *)(lVar6 + 3) = 0x12;
            }
          }
          else {
LAB_14001381f:
            if (*(char *)(param_1[(ulonglong)bVar11 * 4 + 0x60] + 3) == '\0') {
              *(char *)(param_1[(ulonglong)bVar11 * 4 + 0x60] + 3) = param_2;
            }
          }
          if (*(char *)(param_1[(ulonglong)bVar11 * 4 + 0x60] + 3) == '\x01') {
            if (*(ushort *)(uVar10 + 0x1100) == 0x400) {
              cVar5 = *(char *)(uVar10 + 0x110a);
            }
            else {
              if ((*(ushort *)(uVar10 + 0x1100) >> 8 & 1) == 0) goto LAB_140013882;
              cVar5 = *(char *)(uVar10 + 0x110e);
            }
            if (((byte)(cVar5 + 0xa0U) < 2) || ((byte)(cVar5 + 0x9dU) < 3)) {
              param_1[0x4a] = param_1[0x4a] | 0x20;
            }
          }
LAB_140013882:
          ReleaseSlottedCommand(param_1,bVar11);
          if ((*(uint *)(lVar2 + 0x34) & 1) != 0) {
            RecordExecutionHistory(param_1,0x10000046);
          }
        }
        uVar7 = local_res8;
      }
    }
    bVar11 = bVar11 + 1;
    if (((byte)((uint)*(undefined4 *)(lVar2 + 0x1a8) >> 8) & 0x1f) < bVar11) {
      ActivateQueue(param_1,'\x01');
      return;
    }
  } while( true );
}



===== AhciPortSrbCompletionDpcRoutine @ 140013910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AhciPortSrbCompletionDpcRoutine(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  int *piVar14;
  int iVar15;
  ulonglong uVar16;
  undefined4 uVar17;
  uint unaff_R15D;
  undefined1 auStack_328 [32];
  wchar_t *local_308;
  undefined4 local_300;
  undefined4 *local_2f8;
  char local_2e8;
  undefined4 local_2e4;
  ulonglong local_2e0;
  uint local_2d8;
  longlong local_2d0;
  ulonglong local_2c8;
  longlong local_2c0;
  longlong *local_2b8;
  ulonglong local_2b0;
  undefined8 local_2a8;
  wchar_t local_2a0 [12];
  undefined8 uStack_288;
  undefined4 local_278;
  undefined4 local_274;
  undefined1 local_270 [32];
  undefined8 local_250;
  undefined1 local_238 [32];
  ulonglong local_218;
  undefined1 local_210 [32];
  ulonglong local_1f0;
  undefined1 local_1e8 [32];
  ulonglong local_1c8;
  undefined1 local_1c0 [32];
  ulonglong local_1a0;
  undefined1 local_198 [32];
  ulonglong local_178;
  undefined1 local_170 [32];
  longlong local_150;
  undefined1 local_148 [32];
  longlong local_128;
  undefined1 local_120 [32];
  ulonglong local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_328;
  local_2a0[0] = L'\x03';
  local_2a0[1] = L'\0';
  local_2a0[2] = L'\0';
  local_2a0[3] = L'\0';
  uVar12 = unaff_R15D & 0xffffff00;
  local_2a0[4] = L'\0';
  local_2a0[5] = L'\0';
  local_2a0[6] = L'\0';
  local_2a0[7] = L'\0';
  local_2e8 = '\0';
  local_2a0[8] = L'\0';
  local_2a0[9] = L'\0';
  local_2a0[10] = L'\0';
  local_2a0[0xb] = L'\0';
  uStack_288 = 0;
  if (param_3 != (longlong *)0x0) {
    local_2d8 = uVar12;
    local_2a8 = param_2;
    if ((*(uint *)(*param_3 + 0x34) & 1) != 0) {
      RecordExecutionHistory(param_3,0x1e);
    }
    StorPortQuerySystemTime(param_3 + 0x8c2);
    uVar16 = (ulonglong)((uint)param_3[0x4a] & 8);
    local_2b0 = uVar16;
    while( true ) {
      if (((char)*(undefined4 *)(*param_3 + 0x2c) < '\0') && ((int)param_3[0x48] != -1)) {
        local_2e4 = 0;
        uVar13 = 0xb;
        StorPortExtendedFunction();
        uStack_288 = CONCAT71(uStack_288._1_7_,(undefined1)local_2e4);
      }
      else {
        local_308 = local_2a0;
        uVar13 = 0x1003;
        StorPortNotification(0x1003,*param_3,3);
      }
      plVar3 = (longlong *)RemoveQueue(uVar13,param_3 + 0xdf);
      local_2b8 = plVar3;
      if (((char)*(undefined4 *)(*param_3 + 0x2c) < '\0') && ((int)param_3[0x48] != -1)) {
        StorPortExtendedFunction();
      }
      else {
        StorPortNotification();
      }
      if (plVar3 == (longlong *)0x0) break;
      if (*(char *)((longlong)plVar3 + 2) == '(') {
        local_2e0 = plVar3[0xd];
      }
      else {
        local_2e0 = plVar3[7];
      }
      if ((local_2e0 & 0x7f) != 0) {
        local_2e0 = (local_2e0 - ((uint)local_2e0 & 0x7f)) + 0x80;
      }
      uVar6 = local_2e0;
      pcVar2 = *(code **)(local_2e0 + 0x2968);
      *(undefined2 *)(local_2e0 + 0x1100) = 0;
      uVar17 = 1;
      local_2e4 = 1;
      *(undefined8 *)(local_2e0 + 0x2968) = 0;
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(param_3);
        if (((*(short *)(uVar6 + 0x1100) == 0) || ((*(uint *)(uVar6 + 0x1104) & 0x200) != 0)) ||
           (*(char *)((longlong)plVar3 + 3) == '\x0e')) {
          uVar11 = *(uint *)(uVar6 + 0x1104);
          if ((uVar11 >> 9 & 1) != 0) {
            *(uint *)(uVar6 + 0x1104) = uVar11 & 0xfffffdff;
          }
        }
        else {
          AhciProcessIo(param_3,plVar3,0);
          local_2d8 = uVar12 & 0xff;
          uVar17 = 0;
          local_2e8 = '\x01';
          if (plVar3 == param_3 + 0x12e) {
            local_2d8 = 1;
          }
          uVar12 = local_2d8;
        }
        if ((*(uint *)(uVar6 + 0x1104) & 0x1000) != 0) {
          uVar17 = 0;
        }
        local_2e4 = uVar17;
      }
      if (((plVar3 == param_3 + 0x12e) && (uVar16 != 0)) &&
         (((param_3[0x4a] & 8U) != 0 && ((char)uVar12 == '\0')))) {
        RecordExecutionHistory(param_3,0x1001001e);
        lVar5 = param_3[0x4a];
        uVar12 = *(uint *)(param_3 + 0x5c);
        uVar11 = *(uint *)(param_3 + 0x5b);
        uVar10 = *(uint *)(param_3 + 0x5a);
        uVar9 = *(uint *)((longlong)param_3 + 0x2dc);
        uVar1 = *(uint *)((longlong)param_3 + 0x2d4);
        local_2c8 = (ulonglong)
                    CONCAT42(*(undefined4 *)(uVar6 + 0x1104),*(undefined2 *)(uVar6 + 0x1100)) <<
                    0x10 | (ulonglong)*(byte *)((longlong)plVar3 + 3);
        local_2d0 = param_3[0x49];
        local_2c0 = *param_3;
        memset(&local_278,0,0x180);
        local_274 = 0xd;
        local_278 = 1;
        lVar4 = 0;
        uVar8 = 0;
        do {
          if ("Reserved Slot Stuck"[lVar4] == '\0') goto LAB_140013c73;
          if ("Reserved Slot Stuck"[lVar4 + 1] == '\0') {
            uVar8 = uVar8 + 1;
LAB_140013c69:
            if (uVar8 < 0x20) goto LAB_140013c73;
            break;
          }
          if ("Reserved Slot Stuck"[lVar4 + 2] == '\0') {
            uVar8 = uVar8 + 2;
            goto LAB_140013c69;
          }
          if ("Reserved Slot Stuck"[lVar4 + 3] == '\0') {
            uVar8 = uVar8 + 3;
            goto LAB_140013c69;
          }
          uVar8 = uVar8 + 4;
          lVar4 = lVar4 + 4;
        } while (uVar8 < 0x20);
        uVar8 = 0x20;
LAB_140013c73:
        memcpy(local_270,"Reserved Slot Stuck",(ulonglong)uVar8);
        lVar4 = 0;
        local_250 = 1;
        uVar8 = 0;
        do {
          if ("CommandsIssued"[lVar4] == '\0') goto LAB_140013cd1;
          if ("CommandsIssued"[lVar4 + 1] == '\0') {
            uVar8 = uVar8 + 1;
LAB_140013cc7:
            if (uVar8 < 0x20) goto LAB_140013cd1;
            break;
          }
          if ("CommandsIssued"[lVar4 + 2] == '\0') {
            uVar8 = uVar8 + 2;
            goto LAB_140013cc7;
          }
          if ("CommandsIssued"[lVar4 + 3] == '\0') {
            uVar8 = uVar8 + 3;
            goto LAB_140013cc7;
          }
          uVar8 = uVar8 + 4;
          lVar4 = lVar4 + 4;
        } while (uVar8 < 0x20);
        uVar8 = 0x20;
LAB_140013cd1:
        memcpy(local_238,"CommandsIssued",(ulonglong)uVar8);
        uVar8 = 0;
        lVar4 = 0;
        do {
          if ("NCQueueSlice"[lVar4] == '\0') goto LAB_140013d2b;
          if ("NCQueueSlice"[lVar4 + 1] == '\0') {
            uVar8 = uVar8 + 1;
LAB_140013d21:
            if (uVar8 < 0x20) goto LAB_140013d2b;
            break;
          }
          if ("NCQueueSlice"[lVar4 + 2] == '\0') {
            uVar8 = uVar8 + 2;
            goto LAB_140013d21;
          }
          if ("NCQueueSlice"[lVar4 + 3] == '\0') {
            uVar8 = uVar8 + 3;
            goto LAB_140013d21;
          }
          uVar8 = uVar8 + 4;
          lVar4 = lVar4 + 4;
        } while (uVar8 < 0x20);
        uVar8 = 0x20;
LAB_140013d2b:
        local_218 = (ulonglong)uVar9;
        memcpy(local_210,"NCQueueSlice",(ulonglong)uVar8);
        uVar9 = 0;
        lVar4 = 0;
        do {
          if ("NormalQueueSlice"[lVar4] == '\0') goto LAB_140013d82;
          if ("NormalQueueSlice"[lVar4 + 1] == '\0') {
            uVar9 = uVar9 + 1;
LAB_140013d78:
            if (uVar9 < 0x20) goto LAB_140013d82;
            break;
          }
          if ("NormalQueueSlice"[lVar4 + 2] == '\0') {
            uVar9 = uVar9 + 2;
            goto LAB_140013d78;
          }
          if ("NormalQueueSlice"[lVar4 + 3] == '\0') {
            uVar9 = uVar9 + 3;
            goto LAB_140013d78;
          }
          uVar9 = uVar9 + 4;
          lVar4 = lVar4 + 4;
        } while (uVar9 < 0x20);
        uVar9 = 0x20;
LAB_140013d82:
        local_1f0 = (ulonglong)uVar10;
        memcpy(local_1e8,"NormalQueueSlice",(ulonglong)uVar9);
        uVar10 = 0;
        lVar4 = 0;
        do {
          if ("SingleIoSlice"[lVar4] == '\0') goto LAB_140013ddb;
          if ("SingleIoSlice"[lVar4 + 1] == '\0') {
            uVar10 = uVar10 + 1;
LAB_140013dd1:
            if (uVar10 < 0x20) goto LAB_140013ddb;
            break;
          }
          if ("SingleIoSlice"[lVar4 + 2] == '\0') {
            uVar10 = uVar10 + 2;
            goto LAB_140013dd1;
          }
          if ("SingleIoSlice"[lVar4 + 3] == '\0') {
            uVar10 = uVar10 + 3;
            goto LAB_140013dd1;
          }
          uVar10 = uVar10 + 4;
          lVar4 = lVar4 + 4;
        } while (uVar10 < 0x20);
        uVar10 = 0x20;
LAB_140013ddb:
        local_1c8 = (ulonglong)uVar1;
        memcpy(local_1c0,"SingleIoSlice",(ulonglong)uVar10);
        uVar10 = 0;
        lVar4 = 0;
        do {
          if ("CommandsToComplete"[lVar4] == '\0') goto LAB_140013e3b;
          if ("CommandsToComplete"[lVar4 + 1] == '\0') {
            uVar10 = uVar10 + 1;
LAB_140013e31:
            if (uVar10 < 0x20) goto LAB_140013e3b;
            break;
          }
          if ("CommandsToComplete"[lVar4 + 2] == '\0') {
            uVar10 = uVar10 + 2;
            goto LAB_140013e31;
          }
          if ("CommandsToComplete"[lVar4 + 3] == '\0') {
            uVar10 = uVar10 + 3;
            goto LAB_140013e31;
          }
          uVar10 = uVar10 + 4;
          lVar4 = lVar4 + 4;
        } while (uVar10 < 0x20);
        uVar10 = 0x20;
LAB_140013e3b:
        local_1a0 = (ulonglong)uVar11;
        memcpy(local_198,"CommandsToComplete",(ulonglong)uVar10);
        uVar11 = 0;
        lVar4 = 0;
        do {
          if ("StateFlags"[lVar4] == '\0') goto LAB_140013e9b;
          if ("StateFlags"[lVar4 + 1] == '\0') {
            uVar11 = uVar11 + 1;
LAB_140013e91:
            if (uVar11 < 0x20) goto LAB_140013e9b;
            break;
          }
          if ("StateFlags"[lVar4 + 2] == '\0') {
            uVar11 = uVar11 + 2;
            goto LAB_140013e91;
          }
          if ("StateFlags"[lVar4 + 3] == '\0') {
            uVar11 = uVar11 + 3;
            goto LAB_140013e91;
          }
          uVar11 = uVar11 + 4;
          lVar4 = lVar4 + 4;
        } while (uVar11 < 0x20);
        uVar11 = 0x20;
LAB_140013e9b:
        local_178 = (ulonglong)uVar12;
        memcpy(local_170,"StateFlags",(ulonglong)uVar11);
        uVar12 = 0;
        lVar4 = 0;
        do {
          if ("StartState"[lVar4] == '\0') goto LAB_140013efb;
          if ("StartState"[lVar4 + 1] == '\0') {
            uVar12 = uVar12 + 1;
LAB_140013ef1:
            if (uVar12 < 0x20) goto LAB_140013efb;
            break;
          }
          if ("StartState"[lVar4 + 2] == '\0') {
            uVar12 = uVar12 + 2;
            goto LAB_140013ef1;
          }
          if ("StartState"[lVar4 + 3] == '\0') {
            uVar12 = uVar12 + 3;
            goto LAB_140013ef1;
          }
          uVar12 = uVar12 + 4;
          lVar4 = lVar4 + 4;
        } while (uVar12 < 0x20);
        uVar12 = 0x20;
LAB_140013efb:
        local_150 = lVar5;
        memcpy(local_148,"StartState",(ulonglong)uVar12);
        local_128 = local_2d0;
        uVar12 = 0;
        lVar5 = 0;
        do {
          if ("Flags|Function|Status"[lVar5] == '\0') goto LAB_140013f5d;
          if ("Flags|Function|Status"[lVar5 + 1] == '\0') {
            uVar12 = uVar12 + 1;
LAB_140013f53:
            if (uVar12 < 0x20) goto LAB_140013f5d;
            break;
          }
          if ("Flags|Function|Status"[lVar5 + 2] == '\0') {
            uVar12 = uVar12 + 2;
            goto LAB_140013f53;
          }
          if ("Flags|Function|Status"[lVar5 + 3] == '\0') {
            uVar12 = uVar12 + 3;
            goto LAB_140013f53;
          }
          uVar12 = uVar12 + 4;
          lVar5 = lVar5 + 4;
        } while (uVar12 < 0x20);
        uVar12 = 0x20;
LAB_140013f5d:
        memcpy(local_120,"Flags|Function|Status",(ulonglong)uVar12);
        local_100 = local_2c8;
        StorPortExtendedFunction(0x4f,local_2c0,param_3 + 1);
        plVar3 = local_2b8;
        uVar6 = local_2e0;
        uVar16 = local_2b0;
        uVar12 = local_2d8;
      }
      if ((char)local_2e4 != '\0') {
        if (((*(uint *)(uVar6 + 0x1104) & 0x400) != 0) &&
           (((ulonglong)param_3[0x4a] >> 0xd & 1) != 0)) {
          if (*(char *)((longlong)plVar3 + 2) == '(') {
            uVar6 = plVar3[0xd];
          }
          else {
            uVar6 = plVar3[7];
          }
          if ((uVar6 & 0x7f) != 0) {
            uVar6 = (uVar6 - ((uint)uVar6 & 0x7f)) + 0x80;
          }
          *(uint *)(uVar6 + 0x1104) = *(uint *)(uVar6 + 0x1104) & 0xfffffbff;
          local_300 = 0;
          local_308 = (wchar_t *)((ulonglong)local_308 & 0xffffffff00000000);
          StorPortExtendedFunction(0x32,*param_3,param_3 + 1);
        }
        if ((plVar3 != param_3 + 0x12e) && (plVar3 != param_3 + 0x13b)) {
          iVar15 = 0;
          if ((*plVar3 & 0x3f000000) != 0x1000000) {
            local_2e0 = 0;
            if (*param_3 != 0) {
              piVar14 = (int *)param_3[0x8c4];
              if ((piVar14 != (int *)0x0) && (uVar11 = 0, *(uint *)(param_3 + 0x8c5) != 0)) {
                piVar7 = piVar14;
                do {
                  if (*piVar7 == 0x34) {
                    piVar14 = piVar14 + (ulonglong)uVar11 * 8;
                    if (piVar14 != (int *)0x0) {
                      StorPortQuerySystemTime(&local_2e0);
                      uVar11 = piVar14[7];
                      uVar10 = piVar14[6];
                      if ((*(longlong *)(piVar14 + 2) == 0) ||
                         (*(ulonglong *)(piVar14 + 4) <= local_2e0 - *(longlong *)(piVar14 + 2))) {
                        *(ulonglong *)(piVar14 + 2) = local_2e0;
                        iVar15 = uVar11 - uVar10;
                        piVar14[7] = 1;
                        if (uVar11 < uVar10) {
                          iVar15 = 0;
                        }
                      }
                      else {
                        piVar14[7] = uVar11 + 1;
                        if (uVar10 <= uVar11) goto LAB_140014186;
                        iVar15 = 0;
                      }
                    }
                    break;
                  }
                  uVar11 = uVar11 + 1;
                  piVar7 = piVar7 + 8;
                } while (uVar11 < *(uint *)(param_3 + 0x8c5));
              }
            }
            memset(&local_f8,0,0xb0);
            FillAtaCommandErrorStruct(&local_f8,(undefined1 *)plVar3,(longlong)param_3,iVar15);
            local_2f8 = &local_f8;
            local_300 = local_f4;
            local_308 = L"Finished I/O with error";
            StorPortExtendedFunction(0x62,*param_3,param_3 + 1);
          }
LAB_140014186:
          StorPortNotification(0,local_2a8,plVar3);
        }
      }
    }
    if (((uVar16 != 0) && ((param_3[0x4a] & 8U) == 0)) || (local_2e8 != '\0')) {
      ActivateQueue(param_3,*(char *)(*param_3 + 0x18c) != '\0');
    }
    StorPortQuerySystemTime(param_3 + 0x8c3);
    if ((*(uint *)(*param_3 + 0x34) & 1) != 0) {
      RecordExecutionHistory(param_3,0x1000001e);
    }
  }
  return;
}



===== AhciF1IdleTimerCallback @ 140014240 =====

void AhciF1IdleTimerCallback(undefined8 param_1,longlong param_2)

{
  StorPortExtendedFunction
            (0x33,param_1,param_2 + 8,0,*(undefined8 *)(*(longlong *)(param_2 + 0x280) + 0x68));
  *(uint *)(param_2 + 0x254) = *(uint *)(param_2 + 0x254) & 0xffffffef;
  return;
}



===== IssueIdentifyCommand @ 140014290 =====

void IssueIdentifyCommand(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = GetSrbExtension(param_2);
  *(uint *)(uVar1 + 0x1104) = *(uint *)(uVar1 + 0x1104) | 2;
  *(undefined2 *)(uVar1 + 0x1100) = 0x101;
  *(undefined4 *)(uVar1 + 0x1108) = 0;
  *(code **)(uVar1 + 0x2968) = AhciPortIdentifyDevice;
  *(undefined8 *)(uVar1 + 0x110c) = 0xffa000;
  *(undefined4 *)(uVar1 + 0x1114) = 0;
  *(undefined1 *)(param_2 + 3) = 0;
  *(undefined8 *)(uVar1 + 0x1120) = *(undefined8 *)(param_1 + 0xc0);
  *(undefined4 *)(uVar1 + 0x1140) = 1;
  *(undefined4 *)(uVar1 + 0x1150) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(uVar1 + 0x1154) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(uVar1 + 0x1158) = 0x200;
  *(undefined4 **)(uVar1 + 0x1138) = (undefined4 *)(uVar1 + 0x1140);
  *(undefined4 *)(uVar1 + 0x1130) = 0x200;
  return;
}



===== QueryProtocolInfoIoctlProcess @ 140014350 =====

undefined8 QueryProtocolInfoIoctlProcess(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar2 = *(uint *)(param_2 + 0x18);
    lVar4 = *(longlong *)(param_2 + 0x40);
    uVar5 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar2 = *(uint *)(param_2 + 0xc);
    lVar4 = *(longlong *)(param_2 + 0x18);
    uVar5 = *(uint *)(param_2 + 0x10);
  }
  if ((uVar2 & 1) == 0) {
    if ((uVar5 < 0x4c) ||
       (uVar6 = (ulonglong)*(uint *)(lVar4 + 0x34) + 0x24,
       (ulonglong)uVar5 < *(uint *)(lVar4 + 0x38) + uVar6)) {
      *(undefined1 *)(param_2 + 3) = 0x15;
      return 0xc1000006;
    }
    if ((((uVar6 & 7) == 0) && (*(int *)(lVar4 + 0x24) == 2)) &&
       (iVar1 = *(int *)(lVar4 + 0x28), iVar1 != 0)) {
      if (iVar1 == 1) {
        uVar3 = QueryProtocolInfoIdentifyData(param_1,param_2);
        return uVar3;
      }
      if (iVar1 == 2) {
        uVar3 = QueryProtocolInfoLogPageData(param_1,param_2);
        return uVar3;
      }
    }
  }
  *(undefined1 *)(param_2 + 3) = 6;
  return 0xc1000006;
}



===== CopyField @ 1400143f0 =====

void CopyField(char *param_1,longlong param_2,uint param_3)

{
  bool bVar1;
  ulonglong uVar2;
  char cVar3;
  char *pcVar4;
  
  bVar1 = false;
  if (param_3 == 0) {
    *param_1 = '\0';
  }
  else {
    uVar2 = (ulonglong)param_3;
    pcVar4 = param_1;
    do {
      if (bVar1) {
LAB_14001442d:
        cVar3 = ' ';
      }
      else {
        cVar3 = pcVar4[param_2 - (longlong)param_1];
        if (cVar3 == '\0') {
          bVar1 = true;
          goto LAB_14001442d;
        }
        if ((0x5e < (byte)(cVar3 - 0x21U)) || (cVar3 == ',')) goto LAB_14001442d;
      }
      *pcVar4 = cVar3;
      pcVar4 = pcVar4 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    param_1[param_3] = '\0';
  }
  return;
}



===== ReadQueryLogPage @ 140014460 =====

void ReadQueryLogPage(longlong param_1,longlong param_2,ushort param_3)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)param_3;
  IssueReadLogExtCommand
            (param_1,param_2,*(undefined1 *)(param_1 + 0xe5 + uVar1 * 8),
             *(undefined2 *)(param_1 + 0xe6 + uVar1 * 8),*(ushort *)(param_1 + 0xe8 + uVar1 * 8),
             *(undefined2 *)(param_1 + 0xea + uVar1 * 8),(undefined8 *)(param_1 + 0x1e8),
             *(undefined8 *)(param_1 + 0x1e0),LogPageDiscoveryCompletion);
  return;
}



===== __report_gsfailure @ 1400144e0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== AdapterStop @ 1400144f0 =====

void AdapterStop(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  do {
    plVar1 = *(longlong **)(param_1 + 0x1b0 + uVar3 * 8);
    if (plVar1 != (longlong *)0x0) {
      AhciPortStop(plVar1);
    }
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulonglong)uVar2;
  } while (uVar2 <= *(uint *)(param_1 + 0x184));
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 1;
  *(undefined8 *)(param_1 + 400) = 0;
  if ((*(uint *)(param_1 + 0x2c) & 4) != 0) {
    StorPortExtendedFunction(0x32,param_1,0,0,0,0);
  }
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffffe;
  return;
}



===== AhciAdapterRemoval @ 140014568 =====

void AhciAdapterRemoval(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  
  lVar3 = 0;
  lVar7 = 0;
  lVar6 = 0;
  if (*(char *)(param_1 + 0x18c) == '\0') {
    if (*(longlong *)(param_1 + 0x18) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffff3;
      *(undefined8 *)(param_1 + 0x18) = 0;
    }
    if (*(longlong *)(param_1 + 0x2b8) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x2b8) = 0;
    }
    if (*(longlong *)(param_1 + 0x60) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(undefined4 *)(param_1 + 0x68) = 0;
    }
    if (*(longlong *)(param_1 + 0x70) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined4 *)(param_1 + 0x78) = 0;
    }
    if (*(longlong *)(param_1 + 0x80) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x80) = 0;
      *(undefined4 *)(param_1 + 0x88) = 0;
    }
    if (*(longlong *)(param_1 + 0x90) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x90) = 0;
      *(undefined4 *)(param_1 + 0x98) = 0;
    }
    if (*(longlong *)(param_1 + 0xa0) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0xa0) = 0;
      *(undefined4 *)(param_1 + 0xa8) = 0;
    }
    if (*(longlong *)(param_1 + 0xb0) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0xb0) = 0;
      *(undefined4 *)(param_1 + 0xb8) = 0;
    }
    if (*(longlong *)(param_1 + 0xc0) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0xc0) = 0;
      *(undefined4 *)(param_1 + 200) = 0;
    }
    if (*(longlong *)(param_1 + 0xd0) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0xd0) = 0;
      *(undefined4 *)(param_1 + 0xd8) = 0;
    }
    if (*(longlong *)(param_1 + 0xe0) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0xe0) = 0;
      *(undefined4 *)(param_1 + 0xe8) = 0;
    }
    if (*(longlong *)(param_1 + 0xf0) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0xf0) = 0;
      *(undefined4 *)(param_1 + 0xf8) = 0;
    }
    if (*(longlong *)(param_1 + 0x100) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x100) = 0;
      *(undefined4 *)(param_1 + 0x108) = 0;
    }
    if (*(longlong *)(param_1 + 0x120) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x120) = 0;
      *(undefined4 *)(param_1 + 0x128) = 0;
    }
    if (*(longlong *)(param_1 + 0x130) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x130) = 0;
      *(undefined4 *)(param_1 + 0x138) = 0;
    }
    if (*(longlong *)(param_1 + 0x140) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x140) = 0;
      *(undefined4 *)(param_1 + 0x148) = 0;
    }
    if (*(longlong *)(param_1 + 0x110) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x110) = 0;
      *(undefined4 *)(param_1 + 0x118) = 0;
    }
    if (*(longlong *)(param_1 + 0x150) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x150) = 0;
      *(undefined4 *)(param_1 + 0x158) = 0;
    }
    if (*(longlong *)(param_1 + 0x160) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x160) = 0;
      *(undefined4 *)(param_1 + 0x168) = 0;
    }
    if (*(longlong *)(param_1 + 0x170) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x170) = 0;
      *(undefined4 *)(param_1 + 0x178) = 0;
    }
    if (*(longlong *)(param_1 + 0x2c0) != 0) {
      StorPortExtendedFunction(1,param_1);
      *(undefined8 *)(param_1 + 0x2c0) = 0;
      *(undefined4 *)(param_1 + 0x2c8) = 0;
    }
    uVar4 = 0;
    do {
      uVar5 = (ulonglong)uVar4;
      lVar2 = *(longlong *)(param_1 + 0x1b0 + uVar5 * 8);
      if (lVar2 != 0) {
        if (lVar3 == 0) {
          lVar3 = lVar2;
        }
        if (*(longlong *)(lVar2 + 0xa98) != 0) {
          StorPortExtendedFunction(0x22,param_1);
          *(undefined8 *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0xa98) = 0;
        }
        if (*(longlong *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0xaa0) != 0) {
          StorPortExtendedFunction(0x22,param_1);
          *(undefined8 *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0xaa0) = 0;
        }
        if (*(longlong *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0xaa8) != 0) {
          StorPortExtendedFunction(0x22,param_1);
          *(undefined8 *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0xaa8) = 0;
        }
        if (*(longlong *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0xab0) != 0) {
          StorPortExtendedFunction(0x22,param_1);
          *(undefined8 *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0xab0) = 0;
        }
        if (*(longlong *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0xa48) != 0) {
          StorPortExtendedFunction(1,param_1);
          *(undefined8 *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0xa48) = 0;
        }
        lVar2 = *(longlong *)(param_1 + 0x1b0 + uVar5 * 8);
        if (*(longlong *)(lVar2 + 0x280) != 0) {
          StorPortExtendedFunction(1,param_1);
          *(undefined8 *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0x280) = 0;
          puVar1 = (uint *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0x250);
          *puVar1 = *puVar1 & 0xffffdfff;
          puVar1 = (uint *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0x250);
          *puVar1 = *puVar1 & 0xffffbfff;
          lVar2 = *(longlong *)(param_1 + 0x1b0 + uVar5 * 8);
        }
        if ((lVar7 == 0) && (*(longlong *)(lVar2 + 0x45c8) != 0)) {
          lVar7 = *(longlong *)(lVar2 + 0x45c8);
LAB_140014ac1:
          *(undefined8 *)(lVar2 + 0x45c8) = 0;
          lVar2 = *(longlong *)(param_1 + 0x1b0 + uVar5 * 8);
        }
        else if (*(longlong *)(lVar2 + 0x45c8) != 0) goto LAB_140014ac1;
        if ((lVar6 == 0) && (*(longlong *)(lVar2 + 0x4630) != 0)) {
          lVar6 = *(longlong *)(lVar2 + 0x4630);
LAB_140014aef:
          *(undefined8 *)(lVar2 + 0x4630) = 0;
        }
        else if (*(longlong *)(lVar2 + 0x4630) != 0) goto LAB_140014aef;
        if (*(longlong *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0x4620) != 0) {
          StorPortExtendedFunction(1,param_1);
          *(undefined8 *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0x4620) = 0;
          *(undefined4 *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0x4628) = 0;
        }
        *(undefined8 *)(param_1 + 0x1b0 + uVar5 * 8) = 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= *(uint *)(param_1 + 0x184));
    if (lVar3 != 0) {
      StorPortExtendedFunction(1,param_1,lVar3);
    }
    if (lVar7 != 0) {
      StorPortExtendedFunction(1,param_1,lVar7);
    }
    if (lVar6 != 0) {
      StorPortExtendedFunction(1,param_1,lVar6);
    }
  }
  return;
}



===== AhciAdapterStop @ 140014bc4 =====

void AhciAdapterStop(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x2c) & 1) == 0) {
    LOCK();
    puVar1 = (uint *)(param_1 + 0x28);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 | 1;
    UNLOCK();
    if ((uVar2 & 1) == 0) {
      if (((*(uint *)(param_1 + 0x2c) & 4) != 0) &&
         (iVar3 = StorPortExtendedFunction(0x31,param_1,0,0,0,0), iVar3 == -0x3efffff4)) {
        return;
      }
      LOCK();
      puVar1 = (uint *)(param_1 + 0x28);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 & 0xfffffffe;
      UNLOCK();
      if ((uVar2 & 1) != 0) {
        AdapterStop(param_1);
      }
    }
  }
  return;
}



===== AhciEnableThrottlingAdapter @ 140014c34 =====

undefined8 AhciEnableThrottlingAdapter(longlong param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 *puVar7;
  longlong lVar8;
  
  if (param_1 == 0) {
    uVar5 = 0xc1000006;
  }
  else {
    uVar5 = StorPortExtendedFunction(0,param_1,0x80,0x69636841,(longlong *)(param_1 + 0x2c0));
    if ((int)uVar5 == 0) {
      lVar6 = 0;
      *(undefined4 *)(param_1 + 0x2c8) = 4;
      puVar7 = &g_AhciThrottledAdapterEtwEventIds;
      lVar8 = 4;
      do {
        uVar1 = *(uint *)(param_1 + 0x4c);
        lVar4 = *(longlong *)(param_1 + 0x2c0);
        uVar2 = *(undefined4 *)(param_1 + 0x50);
        uVar3 = *puVar7;
        puVar7 = puVar7 + 1;
        *(undefined8 *)(lVar6 + 8 + lVar4) = 0;
        *(undefined4 *)(lVar6 + 0x1c + lVar4) = 0;
        *(ulonglong *)(lVar6 + 0x10 + lVar4) = (ulonglong)uVar1 * 10;
        *(undefined4 *)(lVar6 + lVar4) = uVar3;
        *(undefined4 *)(lVar6 + 0x18 + lVar4) = uVar2;
        lVar6 = lVar6 + 0x20;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      uVar5 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x2c8) = 0;
    }
  }
  return uVar5;
}



===== AhciEnableThrottlingChannel @ 140014cf0 =====

undefined8 AhciEnableThrottlingChannel(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 *puVar8;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar5 = 0xc1000006;
  }
  else {
    uVar5 = StorPortExtendedFunction(0,param_1,0x160,0x69636841,(longlong *)(param_2 + 0x4620));
    if ((int)uVar5 == 0) {
      lVar7 = 0xb;
      puVar8 = &g_AhciThrottledUnitEtwEventIds;
      *(undefined4 *)(param_2 + 0x4628) = 0xb;
      lVar6 = 0;
      do {
        uVar1 = *(uint *)(param_1 + 0x4c);
        lVar4 = *(longlong *)(param_2 + 0x4620);
        uVar2 = *(undefined4 *)(param_1 + 0x50);
        uVar3 = *puVar8;
        puVar8 = puVar8 + 1;
        *(undefined8 *)(lVar6 + 8 + lVar4) = 0;
        *(undefined4 *)(lVar6 + 0x1c + lVar4) = 0;
        *(ulonglong *)(lVar6 + 0x10 + lVar4) = (ulonglong)uVar1 * 10;
        *(undefined4 *)(lVar6 + lVar4) = uVar3;
        *(undefined4 *)(lVar6 + 0x18 + lVar4) = uVar2;
        lVar6 = lVar6 + 0x20;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      uVar5 = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0x4628) = 0;
    }
  }
  return uVar5;
}



===== AhciHwFindAdapter @ 140014dc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AhciHwFindAdapter(uint *param_1)

{
  char cVar1;
  undefined2 *puVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined8 *puVar7;
  uint *puVar8;
  byte bVar9;
  uint uVar10;
  longlong lVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  int iVar17;
  longlong in_stack_00000028;
  undefined1 local_c8 [32];
  uint *local_a8;
  undefined4 local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)local_c8;
  iVar17 = 0;
  local_98 = 0;
  puVar2 = *(undefined2 **)(in_stack_00000028 + 0x40);
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  if ((param_1[0xb] & 1) == 0) {
    *(uint **)(&g_AdapterExtension + (ulonglong)g_AdapterExtensionIndex * 8) = param_1;
    g_AdapterExtensionIndex = g_AdapterExtensionIndex + 1 & 3;
  }
  param_1[1] = *(uint *)(in_stack_00000028 + 4);
  param_1[2] = *(uint *)(in_stack_00000028 + 100);
  local_70 = 0x100;
  uStack_68 = 0x101;
  StorPortExtendedFunction(0x67,param_1,0x10,&local_70);
  cVar1 = *(char *)(in_stack_00000028 + 0xc5);
  *(char *)(param_1 + 99) = cVar1;
  if (cVar1 == '\0') {
    bVar4 = false;
    if (*(int *)(in_stack_00000028 + 8) == 5) {
      local_a8 = (uint *)&local_60;
      local_a0 = 0x30;
      local_60 = 0;
      uStack_58 = 0;
      local_50 = 0;
      uStack_48 = 0;
      local_40 = 0;
      uStack_38 = 0;
      iVar6 = StorPortGetBusData(param_1,4,*(undefined4 *)(in_stack_00000028 + 4),
                                 *(undefined4 *)(in_stack_00000028 + 100));
      if (iVar6 != 0x30) {
        return 2;
      }
      *(undefined2 *)(param_1 + 4) = (undefined2)local_60;
      *(undefined2 *)((longlong)param_1 + 0x12) = local_60._2_2_;
      *(undefined1 *)(param_1 + 5) = (undefined1)uStack_58;
      param_1[3] = local_40._4_4_ & 0xfffffff0;
    }
  }
  else {
    bVar4 = true;
    if (puVar2 == (undefined2 *)0x0) {
      return 2;
    }
    local_a8 = (uint *)((ulonglong)local_a8 & 0xffffffff00000000);
    StorPortExtendedFunction(0x2d,param_1,puVar2,(ulonglong)*(uint *)(puVar2 + 0xce) * 0x60 + 0x1a0)
    ;
    *(undefined2 *)(param_1 + 4) = *puVar2;
    lVar11 = 2;
    *(undefined2 *)((longlong)param_1 + 0x12) = puVar2[1];
    *(undefined1 *)(param_1 + 5) = *(undefined1 *)(puVar2 + 2);
    param_1[3] = *(uint *)(puVar2 + 4);
    puVar5 = (undefined8 *)(puVar2 + 8);
    puVar8 = param_1 + 0xe;
    do {
      puVar12 = puVar8;
      puVar7 = puVar5;
      uVar3 = puVar7[1];
      *(undefined8 *)puVar12 = *puVar7;
      *(undefined8 *)(puVar12 + 2) = uVar3;
      uVar3 = puVar7[3];
      *(undefined8 *)(puVar12 + 4) = puVar7[2];
      *(undefined8 *)(puVar12 + 6) = uVar3;
      uVar3 = puVar7[5];
      *(undefined8 *)(puVar12 + 8) = puVar7[4];
      *(undefined8 *)(puVar12 + 10) = uVar3;
      uVar3 = puVar7[7];
      *(undefined8 *)(puVar12 + 0xc) = puVar7[6];
      *(undefined8 *)(puVar12 + 0xe) = uVar3;
      uVar3 = puVar7[9];
      *(undefined8 *)(puVar12 + 0x10) = puVar7[8];
      *(undefined8 *)(puVar12 + 0x12) = uVar3;
      uVar3 = puVar7[0xb];
      *(undefined8 *)(puVar12 + 0x14) = puVar7[10];
      *(undefined8 *)(puVar12 + 0x16) = uVar3;
      uVar3 = puVar7[0xd];
      *(undefined8 *)(puVar12 + 0x18) = puVar7[0xc];
      *(undefined8 *)(puVar12 + 0x1a) = uVar3;
      uVar3 = puVar7[0xf];
      *(undefined8 *)(puVar12 + 0x1c) = puVar7[0xe];
      *(undefined8 *)(puVar12 + 0x1e) = uVar3;
      lVar11 = lVar11 + -1;
      puVar5 = puVar7 + 0x10;
      puVar8 = puVar12 + 0x20;
    } while (lVar11 != 0);
    uVar3 = puVar7[0x11];
    *(undefined8 *)(puVar12 + 0x20) = puVar7[0x10];
    *(undefined8 *)(puVar12 + 0x22) = uVar3;
    uVar3 = puVar7[0x13];
    *(undefined8 *)(puVar12 + 0x24) = puVar7[0x12];
    *(undefined8 *)(puVar12 + 0x26) = uVar3;
    uVar3 = puVar7[0x15];
    *(undefined8 *)(puVar12 + 0x28) = puVar7[0x14];
    *(undefined8 *)(puVar12 + 0x2a) = uVar3;
    uVar3 = puVar7[0x17];
    *(undefined8 *)(puVar12 + 0x2c) = puVar7[0x16];
    *(undefined8 *)(puVar12 + 0x2e) = uVar3;
    *(undefined8 *)(puVar12 + 0x30) = puVar7[0x18];
    param_1[0xd] = *(uint *)(puVar2 + 6);
  }
  puVar8 = (uint *)GetABARAddress((longlong)param_1,in_stack_00000028);
  if (puVar8 == (uint *)0x0) {
    return 2;
  }
  *(uint **)(param_1 + 100) = puVar8;
  param_1[0x66] = puVar8[4];
  param_1[0x6a] = *puVar8;
  param_1[0x6b] = puVar8[9];
  uVar13 = 0;
  if ((int)puVar8[1] < 0) {
    lVar11 = *(longlong *)(param_1 + 100);
    if (lVar11 == 0) {
      return 2;
    }
    *(undefined4 *)(lVar11 + 4) = 1;
    LOCK();
    UNLOCK();
    uVar13 = *(uint *)(lVar11 + 4);
    do {
      if ((uVar13 & 1) == 0) goto LAB_140015094;
      StorPortStallExecution(20000);
      iVar17 = iVar17 + 1;
      uVar13 = *(uint *)(lVar11 + 4);
    } while (iVar17 < 0x32);
    if (iVar17 == 0x32) {
      param_1[0xc] = 0x20000000;
      return 2;
    }
LAB_140015094:
    uVar13 = local_98;
  }
  uVar15 = 0x80000000;
  puVar8[1] = 0x80000000;
  LOCK();
  UNLOCK();
  *(uint **)(param_1 + 0x68) = puVar8 + 2;
  if (bVar4) {
    param_1[0x60] = 0;
    uVar14 = 0;
    if (*(int *)(puVar2 + 0xce) == 0) {
      return 2;
    }
    uVar10 = 0;
    do {
      uVar16 = (ulonglong)uVar14;
      uVar14 = uVar14 + 1;
      uVar10 = 1 << ((byte)*(undefined4 *)(puVar2 + uVar16 * 0x30 + 0xd0) & 0x1f) | uVar10;
      param_1[0x60] = uVar10;
    } while (uVar14 < *(uint *)(puVar2 + 0xce));
  }
  else {
    uVar10 = puVar8[3];
    param_1[0x60] = uVar10;
  }
  puVar12 = (uint *)(ulonglong)uVar10;
  if (uVar10 == 0) {
    return 2;
  }
  if (bVar4) {
    uVar13 = *(uint *)(puVar2 + 0xce);
    bVar9 = 0;
    if (uVar13 != 0) {
      puVar12 = (uint *)(puVar2 + 0xd0);
      uVar16 = (ulonglong)uVar13;
      do {
        if ((uint)bVar9 < *puVar12) {
          bVar9 = (byte)*puVar12;
        }
        puVar12 = puVar12 + 0x18;
        uVar16 = uVar16 - 1;
        uVar15 = 0;
      } while (uVar16 != 0);
    }
  }
  else {
    bVar9 = 0x20;
    do {
      bVar9 = bVar9 - 1;
      if (((uint)uVar15 & uVar10) != 0) break;
      uVar14 = (uint)uVar15 >> 1;
      uVar15 = (ulonglong)uVar14;
    } while (uVar14 != 0);
    uVar15 = 0;
    do {
      uVar14 = uVar13 + 1;
      if ((uVar10 >> ((uint)uVar15 & 0x1f) & 1) == 0) {
        uVar14 = uVar13;
      }
      uVar13 = uVar14;
      uVar14 = (uint)uVar15 + 1;
      uVar15 = (ulonglong)uVar14;
    } while (uVar14 <= bVar9);
  }
  param_1[0x61] = (uint)bVar9;
  *(undefined4 *)(in_stack_00000028 + 0x18) = 0x20000;
  *(undefined4 *)(in_stack_00000028 + 0x1c) = 0x21;
  *(undefined4 *)(in_stack_00000028 + 0x30) = 1;
  *(undefined1 *)(in_stack_00000028 + 0x51) = 1;
  *(undefined2 *)(in_stack_00000028 + 0x91) = 0x101;
  *(byte *)(in_stack_00000028 + 0x48) = bVar9 + 1;
  *(undefined1 *)(in_stack_00000028 + 0x61) = 1;
  *(undefined4 *)(in_stack_00000028 + 0x94) = 1;
  *(undefined4 *)(in_stack_00000028 + 0xd8) = 0;
  uVar14 = param_1[0x6a];
  *(uint *)(in_stack_00000028 + 0xdc) = *(uint *)(in_stack_00000028 + 0xdc) | 0x2b;
  *(uint *)(in_stack_00000028 + 0xcc) = (uVar14 >> 8 & 0x1f) * uVar13;
  if (*(int *)(in_stack_00000028 + 0x14) == 1) {
    *(undefined4 *)(in_stack_00000028 + 0xa0) = 2;
    *(code **)(in_stack_00000028 + 0x98) = AhciHwMSIInterrupt;
    if (bVar4) goto LAB_140015299;
    local_a8 = param_1 + 0xae;
    StorPortExtendedFunction(0,param_1,(param_1[0x61] + 1) * 0x10,0x69636841);
  }
  else {
    *(undefined4 *)(in_stack_00000028 + 0xa0) = 1;
    if (bVar4) goto LAB_140015299;
  }
  uVar15 = 2;
  local_90 = 0x449ca2a10b2d69d7;
  uStack_88 = 0x601c52701cf98096;
  local_80 = 0x4fbc53fedab60367;
  uStack_78 = 0x56249d061d525e82;
  puVar12 = param_1;
  StorPortExtendedFunction(0x1a,param_1,2,&local_90);
LAB_140015299:
  param_1[0x62] = 0xffffffff;
  puVar8[1] = 0x80000002;
  LOCK();
  UNLOCK();
  if ((param_1[0xb] & 1) == 0) {
    GetMiniportRegistrySettings((longlong)param_1);
    GetAdapterRegistrySettings((longlong)param_1);
    GetDeviceRegistrySettings((longlong)param_1,puVar12,uVar15);
  }
  if (param_1[0x12] != 0) {
    *(uint *)(in_stack_00000028 + 0x18) = param_1[0x12] << 10;
    *(uint *)(in_stack_00000028 + 0x1c) = (param_1[0x12] >> 2) + 1;
  }
  if ((int)param_1[0x6a] < 0) {
    *(undefined1 *)(in_stack_00000028 + 0x90) = 1;
    if ((param_1[0xe] & 0x800) != 0) {
      *(undefined1 *)(in_stack_00000028 + 0x90) = 3;
    }
    *(int *)(in_stack_00000028 + 0x8c) =
         *(int *)(in_stack_00000028 + 0x8c) + *(int *)(in_stack_00000028 + 0x1c) * 4 + 8;
  }
  if (((param_1[0xb] & 1) == 0) &&
     (uVar15 = AllocateResourcesForAdapter((longlong)param_1,in_stack_00000028,uVar13),
     (char)uVar15 == '\0')) {
    return 2;
  }
  if (!bVar4) {
    for (uVar13 = 0; uVar13 <= param_1[0x61]; uVar13 = uVar13 + 1) {
      uVar15 = (ulonglong)uVar13;
      if (*(longlong *)(param_1 + uVar15 * 2 + 0x6c) != 0) {
        if ((*(longlong *)(*(longlong *)(param_1 + uVar15 * 2 + 0x6c) + 0xa98) == 0) &&
           (iVar17 = StorPortExtendedFunction(0x20,param_1), iVar17 != 0)) {
          return 2;
        }
        if ((*(longlong *)(*(longlong *)(param_1 + uVar15 * 2 + 0x6c) + 0xaa0) == 0) &&
           (iVar17 = StorPortExtendedFunction(0x20,param_1), iVar17 != 0)) {
          return 2;
        }
        if ((*(longlong *)(*(longlong *)(param_1 + uVar15 * 2 + 0x6c) + 0xab0) == 0) &&
           (iVar17 = StorPortExtendedFunction(0x20,param_1), iVar17 != 0)) {
          return 2;
        }
      }
    }
  }
  param_1[0xb] = param_1[0xb] & 0xfffffffe;
  uVar13 = 0;
  do {
    if (*(longlong **)(param_1 + (ulonglong)uVar13 * 2 + 0x6c) != (longlong *)0x0) {
      AhciPortInitialize(*(longlong **)(param_1 + (ulonglong)uVar13 * 2 + 0x6c));
    }
    uVar13 = uVar13 + 1;
  } while (uVar13 <= param_1[0x61]);
  if ((bVar4) && (uVar13 = 0, *(int *)(puVar2 + 0xce) != 0)) {
    do {
      uVar15 = (ulonglong)uVar13;
      uVar14 = *(uint *)(puVar2 + uVar15 * 0x30 + 0xd0);
      lVar11 = *(longlong *)(param_1 + (ulonglong)uVar14 * 2 + 0x6c);
      if (lVar11 != 0) {
        uVar3 = *(undefined8 *)((longlong)(puVar2 + uVar15 * 0x30 + 0xd2) + 8);
        *(undefined8 *)(lVar11 + 600) = *(undefined8 *)(puVar2 + uVar15 * 0x30 + 0xd2);
        *(undefined8 *)(lVar11 + 0x260) = uVar3;
        *(undefined8 *)(lVar11 + 0x268) = *(undefined8 *)(puVar2 + uVar15 * 0x30 + 0xda);
        *(undefined4 *)(lVar11 + 0x270) = *(undefined4 *)(puVar2 + uVar15 * 0x30 + 0xde);
        memcpy((void *)(*(longlong *)(param_1 + (ulonglong)uVar14 * 2 + 0x6c) + 0x180),
               puVar2 + uVar15 * 0x30 + 0xe0,0x40);
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < *(uint *)(puVar2 + 0xce));
  }
  return 1;
}



===== AhciHwInitialize @ 1400154c0 =====

undefined8 AhciHwInitialize(longlong param_1)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  void *_Dst;
  undefined4 local_res8 [2];
  undefined8 local_38;
  ulonglong uStack_30;
  longlong lStack_28;
  undefined8 uStack_20;
  void *pvStack_18;
  
  uStack_30 = 0;
  lStack_28 = 0;
  uStack_20 = 0;
  pvStack_18 = (void *)0x0;
  GetInterruptMode(param_1);
  local_res8[0] = 0;
  StorPortNotification(0x1000,param_1,AhciHwPassiveInitialize,local_res8);
  local_38 = 0x2800000008;
  iVar1 = StorPortExtendedFunction(0xe,param_1,1,&local_38);
  if ((iVar1 == 0) && ((uStack_30 & 1) != 0)) {
    pvStack_18 = (void *)0x0;
    lStack_28 = 0;
    uStack_20 = 0;
    uStack_30._0_4_ = 1;
    local_38 = 0x2800000008;
    uStack_30 = 1;
    if (((char)*(undefined4 *)(param_1 + 0x2c) < '\0') &&
       (_Dst = *(void **)(param_1 + 0x2b8), _Dst != (void *)0x0)) {
      uVar2 = (*(int *)(param_1 + 0x184) + 1) * 0x10;
      if (uVar2 != 0) {
        memset(_Dst,0,(ulonglong)uVar2);
        _Dst = *(void **)(param_1 + 0x2b8);
      }
      uStack_30._0_4_ = (uint)uStack_30 | 0xc;
      if (*(uint *)(param_1 + 0x184) == 0) {
        lStack_28 = 0;
      }
      else {
        lStack_28 = (ulonglong)*(uint *)(param_1 + 0x184) << 0x20;
      }
      pvStack_18 = _Dst;
    }
    uVar2 = *(uint *)(param_1 + 0x180) - (*(uint *)(param_1 + 0x180) >> 1 & 0x55555555);
    uVar2 = (uVar2 >> 2 & 0x33333333) + (uVar2 & 0x33333333);
    uStack_30 = CONCAT44(((uVar2 >> 4) + uVar2 & 0xf0f0f0f) * 0x1010101 >> 0x18,(uint)uStack_30) | 2
    ;
    StorPortExtendedFunction(0xe,param_1,0,&local_38);
  }
  uVar3 = 0;
  do {
    if (*(uint *)(param_1 + 0x184) < (uint)uVar3) {
LAB_14001564e:
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
    if (*(longlong *)(param_1 + 0x1b0 + uVar3 * 8) != 0) {
      *(undefined1 *)(param_1 + 0x18d) = 1;
      uVar3 = P_Running_StartAttempt(*(longlong **)(param_1 + 0x1b0 + uVar3 * 8),'\x01');
      goto LAB_14001564e;
    }
    uVar3 = (ulonglong)((uint)uVar3 + 1);
  } while( true );
}



===== AhciHwPassiveInitialize @ 140015670 =====

undefined8 AhciHwPassiveInitialize(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  bool bVar8;
  char local_res8 [8];
  byte local_res10 [8];
  undefined1 local_res18 [8];
  
  uVar6 = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  do {
    lVar2 = *(longlong *)(param_1 + 0x1b0 + uVar6 * 8);
    if (lVar2 != 0) {
      StorPortNotification(0x1001,param_1,lVar2 + 0x8b8,AhciPortSrbCompletionDpcRoutine);
      StorPortNotification
                (0x1001,param_1,*(longlong *)(param_1 + 0x1b0 + uVar6 * 8) + 0x900,
                 AhciPortBusChangeDpcRoutine);
    }
    uVar5 = (int)uVar6 + 1;
    uVar6 = (ulonglong)uVar5;
  } while (uVar5 <= *(uint *)(param_1 + 0x184));
  AhciAdapterEvaluateDSMMethod(param_1);
  local_res8[0] = '\0';
  StorPortExtendedFunction(0x3d,param_1,local_res8);
  *(uint *)(param_1 + 0x2c) =
       *(uint *)(param_1 + 0x2c) & 0xffffffbf | -(uint)(local_res8[0] != '\0') & 0x40;
  iVar3 = StorPortExtendedFunction(0x43,param_1,0,local_res10);
  if (iVar3 == 0) {
    *(uint *)(param_1 + 0x2c) =
         ((uint)local_res10[0] << 8 ^ *(uint *)(param_1 + 0x2c)) & 0x100 ^ *(uint *)(param_1 + 0x2c)
    ;
  }
  plVar1 = (longlong *)(param_1 + 0x18);
  uVar5 = *(uint *)(param_1 + 0x2c) & 0x100;
  bVar8 = uVar5 != 0;
  uVar4 = StorPortExtendedFunction(0,param_1,bVar8 * ' ' + 'X',0x69636841,plVar1);
  if ((int)uVar4 == 0) {
    memset((void *)*plVar1,0,0x58);
    *(undefined4 *)*plVar1 = 3;
    *(undefined4 *)(*plVar1 + 4) = 0x18;
    *(undefined4 *)(*plVar1 + 8) = 1;
    if ((*(uint *)(param_1 + 0x38) >> 9 & 1) == 0) {
      *(undefined4 *)(*plVar1 + 0xc) = 4;
    }
    plVar7 = (longlong *)(param_1 + 0x18);
    *(uint *)(*plVar1 + 0xc) = *(uint *)(*plVar1 + 0xc) | 0x800;
    *(uint *)(*plVar1 + 0xc) = *(uint *)(*plVar1 + 0xc) | 8;
    *(undefined4 *)(*plVar1 + 0x18) = 1;
    *(undefined4 *)(*plVar1 + 0x1c) = 0x20;
    *(uint *)(*plVar1 + 0x20) = bVar8 + 1;
    *(uint *)(*plVar1 + 0x24) = (uint)bVar8;
    lVar2 = *plVar1;
    *(undefined4 *)(lVar2 + 0x28) = 0xdcaf9c10;
    *(undefined4 *)(lVar2 + 0x2c) = 0x481f895f;
    *(undefined4 *)(lVar2 + 0x30) = 0xced492a4;
    *(undefined4 *)(lVar2 + 0x34) = 0x3356f5d2;
    *(undefined4 *)(*plVar1 + 0x38) = 1;
    *(undefined4 *)(*plVar1 + 0x3c) = 0x20;
    *(undefined8 *)(*plVar1 + 0x40) = 0;
    *(undefined8 *)(*plVar1 + 0x48) = 0;
    *(undefined4 *)(*plVar1 + 0x50) = 0xffffffff;
    if (uVar5 != 0) {
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffbff;
      *(undefined4 *)(*plVar7 + 0x58) = 1;
      *(undefined4 *)(*plVar7 + 0x5c) = 0x20;
      *(undefined8 *)(*plVar7 + 0x60) = 1;
      *(undefined8 *)(*plVar7 + 0x68) = 0;
      *(undefined4 *)(*plVar7 + 0x70) = 0xffffffff;
    }
    if ((*(uint *)(param_1 + 0x2c) & 0x400) != 0) {
      *(uint *)(*plVar7 + 0xc) = *(uint *)(*plVar7 + 0xc) | 2;
    }
    uVar4 = StorPortExtendedFunction(0x30,param_1,0,*plVar7,local_res18);
    if ((int)uVar4 == 0) {
      if (uVar5 != 0) {
        uVar4 = StorPortExtendedFunction(0x33,param_1,0,0,1);
      }
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0xc;
    }
    else {
      uVar4 = StorPortExtendedFunction(1,param_1,*plVar7);
      *plVar7 = 0;
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffff3;
    }
  }
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== AhciHwResetBus @ 140015920 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

byte AhciHwResetBus(longlong param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined1 auStack_228 [32];
  byte local_208;
  longlong local_200 [2];
  undefined8 *local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined1 local_1c0 [32];
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined1 local_188 [32];
  undefined8 local_168;
  undefined1 local_160 [32];
  undefined8 local_140;
  undefined1 local_138 [32];
  undefined8 local_118;
  undefined1 local_110 [32];
  ulonglong local_f0;
  undefined1 local_e8 [32];
  undefined8 local_c8;
  undefined1 local_c0 [32];
  undefined8 local_a0;
  undefined1 local_98 [32];
  ulonglong local_78;
  undefined1 local_70 [32];
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_228;
  local_1e0 = 0;
  local_1d8 = 0;
  uStack_1d0 = 0;
  uVar16 = (ulonglong)param_2;
  local_1e8 = 3;
  lVar15 = param_1;
  uVar13 = IsPortValid(param_1,param_2);
  local_208 = 0;
  if ((char)uVar13 != '\0') {
    AhciInterruptSpinlockAcquire(lVar15,-1,(longlong)&local_1e8);
    LOCK();
    puVar1 = (uint *)(*(longlong *)(param_1 + 0x1b0 + uVar16 * 8) + 0x250);
    *puVar1 = *puVar1 | 0x800000;
    UNLOCK();
    uVar14 = AhciPortReset(*(ulonglong **)(param_1 + 0x1b0 + uVar16 * 8),'\x01');
    local_208 = (byte)uVar14;
    AhciInterruptSpinlockRelease(param_1,-1,(longlong)&local_1e8);
    local_200[0] = 0;
    piVar2 = (int *)(*(longlong *)(param_1 + 0x1b0 + uVar16 * 8) + 0xb4);
    *piVar2 = *piVar2 + 1;
    puVar7 = *(undefined8 **)(param_1 + 0x1b0 + uVar16 * 8);
    local_1f0 = puVar7 + 1;
    if ((puVar7 != (undefined8 *)0x0) && (*(int *)(puVar7 + 3) != 2)) {
      StorPortQuerySystemTime(local_200);
      if ((puVar7[0x8be] == 0) || (35999999999 < (ulonglong)(local_200[0] - puVar7[0x8be]))) {
        uVar3 = *(undefined4 *)(puVar7 + 0x8bc);
        uVar4 = *(undefined4 *)((longlong)puVar7 + 0x45d4);
        uVar12 = *(uint *)(puVar7 + 0x8bd);
        uVar14 = puVar7[0x49];
        uVar8 = puVar7[0x4a];
        uVar11 = *(uint *)((longlong)puVar7 + 0xb4);
        puVar7[0x8be] = local_200[0];
        uVar5 = *(undefined4 *)((longlong)puVar7 + 0x45e4);
        uVar6 = *(undefined4 *)((longlong)puVar7 + 0x45dc);
        memset(&local_1c8,0,0x180);
        local_1c8 = 1;
        local_1c4 = 7;
        uVar10 = GetStringLength("AhciHwResetBus",0x20);
        memcpy(local_1c0,"AhciHwResetBus",(ulonglong)uVar10);
        local_19c = 0;
        local_1a0 = 1;
        uVar10 = GetStringLength("PortReset|PortErrorRecovery",0x20);
        memcpy(local_188,"PortReset|PortErrorRecovery",(ulonglong)uVar10);
        local_168 = CONCAT44(*(undefined4 *)(puVar7 + 0x8ba),*(undefined4 *)(puVar7 + 0x8bb));
        uVar10 = GetStringLength("StartFail|NonQErrorRecovery",0x20);
        memcpy(local_160,"StartFail|NonQErrorRecovery",(ulonglong)uVar10);
        local_140 = CONCAT44(uVar4,uVar6);
        uVar10 = GetStringLength("NCQError|NCQErrorComplete",0x20);
        memcpy(local_138,"NCQError|NCQErrorComplete",(ulonglong)uVar10);
        local_118 = CONCAT44(uVar3,uVar5);
        uVar10 = GetStringLength("PortDriverResetCount",0x20);
        memcpy(local_110,"PortDriverResetCount",(ulonglong)uVar10);
        local_f0 = (ulonglong)uVar11;
        uVar11 = GetStringLength("StateFlags",0x20);
        memcpy(local_e8,"StateFlags",(ulonglong)uVar11);
        local_c8 = uVar8;
        uVar11 = GetStringLength("StartState",0x20);
        memcpy(local_c0,"StartState",(ulonglong)uVar11);
        local_a0 = uVar14;
        uVar11 = GetStringLength("TotalCountSurpriseRemove",0x20);
        memcpy(local_98,"TotalCountSurpriseRemove",(ulonglong)uVar11);
        local_78 = (ulonglong)uVar12;
        uVar12 = GetStringLength("PortResetStatus",0x20);
        memcpy(local_70,"PortResetStatus",(ulonglong)uVar12);
        bVar9 = local_208;
        local_50 = (ulonglong)local_208;
        StorPortExtendedFunction(0x4f,*puVar7,local_1f0,&local_1c8);
        return bVar9;
      }
    }
  }
  return local_208;
}



===== AhciHwTracingEnabled @ 140015ca0 =====

void AhciHwTracingEnabled(longlong param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x18e) = param_2;
  return;
}



===== AhciSimulateThrottledEtwEvent @ 140015cb0 =====

void AhciSimulateThrottledEtwEvent(longlong param_1,longlong param_2,int param_3)

{
  bool bVar1;
  wchar_t *pwVar2;
  int local_res20 [2];
  
  local_res20[0] = 0;
  bVar1 = AhciIsEventAllowedWithinThrottleLimit(param_1,param_2,param_3,local_res20);
  if (bVar1) {
    pwVar2 = L"TestEventThrottling: Adapter";
    if (param_2 != 0) {
      pwVar2 = L"TestEventThrottling: Channel";
    }
    StorPortExtendedFunction
              (0x55,param_1,-(ulonglong)(param_2 != 0) & param_2 + 8U,1,param_3,pwVar2,0x10,2,0,0,
               L"ThrottleCount",local_res20[0],0,0);
  }
  return;
}



===== AllocateResourcesForAdapter @ 140015d7c =====

ulonglong AllocateResourcesForAdapter(longlong param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  char cVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  void *_Dst;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong lVar9;
  int iVar10;
  uint uVar11;
  void *local_res8;
  void *local_res20;
  longlong local_48 [2];
  
  cVar2 = *(char *)(param_1 + 0x18c);
  local_res8 = (void *)0x0;
  local_48[0] = 0;
  uVar11 = 0;
  local_res20 = (void *)0x0;
  uVar1 = (*(uint *)(param_1 + 0x1a8) >> 0xb & 3) * 8 + 8;
  iVar4 = uVar1 * 0x20;
  if (cVar2 == '\0') {
    iVar10 = (iVar4 + 0x5923U & 0xfffffc00) + 0x400;
    iVar4 = iVar10;
  }
  else {
    iVar10 = iVar4 + 0x5d24;
    iVar4 = iVar4 + 0xa364;
  }
  _Dst = (void *)StorPortGetUncachedExtension(param_1,param_2,iVar4 * param_3);
  *(void **)(param_1 + 0x2b0) = _Dst;
  uVar6 = 0;
  if (_Dst == (void *)0x0) {
LAB_140016093:
    uVar6 = uVar6 & 0xffffffffffffff00;
  }
  else {
    uVar5 = iVar10 * param_3;
    if (uVar5 != 0) {
      memset(_Dst,0,(ulonglong)uVar5);
    }
    if (cVar2 == '\0') {
      uVar6 = StorPortExtendedFunction(0,param_1,param_3 * 0x4640,0x69636841,&local_res8);
      if (((int)uVar6 != 0) || (local_res8 == (void *)0x0)) goto LAB_140016093;
      StorPortExtendedFunction(0,param_1,param_3 * 24000,0x69636841,local_48);
      uVar5 = param_3 << 7;
      StorPortExtendedFunction(0,param_1,uVar5,0x69636841,&local_res20);
      if ((local_res20 != (void *)0x0) && (uVar5 != 0)) {
        memset(local_res20,0,(ulonglong)uVar5);
      }
      AhciEnableThrottlingAdapter(param_1);
    }
    else {
      local_res8 = (void *)(*(longlong *)(param_1 + 0x2b0) + (ulonglong)uVar5);
    }
    if (param_3 * 0x4640 != 0) {
      memset(local_res8,0,(ulonglong)(uint)(param_3 * 0x4640));
    }
    uVar6 = 0;
    do {
      uVar7 = (ulonglong)*(uint *)(param_1 + 0x180);
      uVar5 = (uint)uVar6;
      if ((*(uint *)(param_1 + 0x180) >> (uVar5 & 0x1f) & 1) != 0) {
        plVar8 = (longlong *)((ulonglong)(uVar11 * 0x4640) + (longlong)local_res8);
        lVar9 = (ulonglong)(uVar11 * iVar10) + *(longlong *)(param_1 + 0x2b0);
        *(longlong **)(param_1 + 0x1b0 + uVar6 * 8) = plVar8;
        *plVar8 = param_1;
        *(uint *)(*(longlong *)(param_1 + 0x1b0 + uVar6 * 8) + 0x240) = uVar5;
        lVar3 = *(longlong *)(param_1 + 0x1b0 + uVar6 * 8);
        if (cVar2 == '\0') {
          *(longlong *)(lVar3 + 0x950) = lVar9;
          if (local_48[0] != 0) {
            *(ulonglong *)(*(longlong *)(param_1 + 0x1b0 + uVar6 * 8) + 0x45c8) =
                 (ulonglong)(uVar11 * 24000) + local_48[0];
          }
          if (local_res20 != (void *)0x0) {
            *(void **)(*(longlong *)(param_1 + 0x1b0 + uVar6 * 8) + 0x4630) =
                 (void *)((ulonglong)uVar11 * 0x80 + (longlong)local_res20);
          }
          AhciEnableThrottlingChannel(param_1,*(longlong *)(param_1 + 0x1b0 + uVar6 * 8));
        }
        else {
          uVar7 = (ulonglong)((uint)lVar9 & 0x3ff);
          if (uVar7 != 0) {
            lVar9 = (lVar9 - uVar7) + 0x400;
          }
          *(longlong *)(lVar3 + 0x950) = lVar9;
        }
        lVar3 = *(longlong *)(param_1 + 0x1b0 + uVar6 * 8);
        *(ulonglong *)(lVar3 + 0x958) = (ulonglong)uVar1 * 0x20 + *(longlong *)(lVar3 + 0x950);
        lVar3 = *(longlong *)(param_1 + 0x1b0 + uVar6 * 8);
        *(longlong *)(lVar3 + 0x9c8) = *(longlong *)(lVar3 + 0x958) + 0x100;
        lVar3 = *(longlong *)(param_1 + 0x1b0 + uVar6 * 8);
        *(longlong *)(lVar3 + 0xa30) = *(longlong *)(lVar3 + 0x9c8) + 0x2a00;
        lVar3 = *(longlong *)(param_1 + 0x1b0 + uVar6 * 8);
        uVar7 = *(longlong *)(lVar3 + 0xa30) + 0x2a00;
        *(ulonglong *)(lVar3 + 0xc0) = uVar7;
        lVar3 = *(longlong *)(param_1 + 0x1b0 + uVar6 * 8);
        *(longlong *)(lVar3 + 0x1e0) = *(longlong *)(lVar3 + 0xc0) + 0x200;
        lVar3 = *(longlong *)(param_1 + 0x1b0 + uVar6 * 8);
        *(longlong *)(lVar3 + 0xd0) = *(longlong *)(lVar3 + 0x1e0) + 0x200;
        uVar11 = uVar11 + 1;
      }
      uVar6 = (ulonglong)(uVar5 + 1);
    } while (uVar5 + 1 <= *(uint *)(param_1 + 0x184));
    uVar6 = CONCAT71((int7)(uVar7 >> 8),1);
  }
  return uVar6;
}



===== DeviceDevSlpDETO @ 1400160b4 =====

char DeviceDevSlpDETO(longlong param_1)

{
  char cVar1;
  
  if ((-1 < *(longlong *)(param_1 + 0x178)) || (cVar1 = *(char *)(param_1 + 0x179), cVar1 == '\0'))
  {
    cVar1 = '\x14';
  }
  return cVar1;
}



===== DeviceDevSlpMDAT @ 1400160d4 =====

byte DeviceDevSlpMDAT(longlong param_1)

{
  byte bVar1;
  
  if ((-1 < *(longlong *)(param_1 + 0x178)) ||
     (bVar1 = *(byte *)(param_1 + 0x178) & 0x1f, bVar1 == 0)) {
    bVar1 = 10;
  }
  return bVar1;
}



===== DeviceIncursNoSeekPenalty @ 1400160f4 =====

ulonglong DeviceIncursNoSeekPenalty(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = IsAtaDevice((uint *)(param_1 + 0x18));
  if ((char)uVar1 == '\0') {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar1 = CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0xc0) >> 8),
                     *(short *)(*(longlong *)(param_1 + 0xc0) + 0x1b2) == 1);
  }
  return uVar1;
}



===== DeviceIncursSeekPenalty @ 14001612c =====

ulonglong DeviceIncursSeekPenalty(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = IsAtaDevice((uint *)(param_1 + 0x18));
  if ((char)uVar1 == '\0') {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar1 = CONCAT71(0xfb,(ushort)(*(short *)(*(longlong *)(param_1 + 0xc0) + 0x1b2) - 0x401U) <
                          0xfbfe);
  }
  return uVar1;
}



===== DriverEntry @ 140016174 =====

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
  code *local_60;
  code *local_58;
  code *local_28;
  uint local_20;
  undefined4 local_1c;
  code *local_10;
  
  memset(&local_d8,0,0xd0);
  local_20 = local_20 | 0x112fe;
  local_d0 = AhciHwInitialize;
  local_d8 = 0xd0;
  local_c8 = AhciHwStartIo;
  local_80 = 0x1010102;
  local_c0 = AhciHwInterrupt;
  local_8c = 6;
  local_b8 = AhciHwFindAdapter;
  local_d4 = 5;
  local_b0 = AhciHwResetBus;
  local_60 = AhciHwAdapterControl;
  local_58 = AhciHwBuildIo;
  local_28 = AhciHwTracingEnabled;
  local_10 = AhciHwUnitControl;
  local_7c = 1;
  local_98 = 0x2d0;
  local_90 = 0x2a20;
  local_1c = 2;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== AhciAdapterEvaluateDSMMethod @ 140016278 =====

void AhciAdapterEvaluateDSMMethod(longlong param_1)

{
  uint *puVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  void *pvVar8;
  uint local_res10 [2];
  undefined8 *local_res18;
  void *local_res20;
  
  local_res10[0] = 0;
  local_res18 = (undefined8 *)0x0;
  local_res20 = (void *)0x0;
  iVar2 = StorPortExtendedFunction(0,param_1,0x10c,0x69636841,&local_res20);
  if (iVar2 == 0) {
    pvVar8 = local_res20;
    if (local_res20 == (void *)0x0) goto LAB_140016543;
    memset(local_res20,0,0x10c);
    iVar2 = StorPortExtendedFunction(0,param_1,0x3c,0x69636841,&local_res18);
    if (iVar2 != 0) goto LAB_14001653f;
    if (local_res18 != (undefined8 *)0x0) {
      *local_res18 = 0;
      local_res18[1] = 0;
      local_res18[2] = 0;
      local_res18[3] = 0;
      local_res18[4] = 0;
      local_res18[5] = 0;
      local_res18[6] = 0;
      *(undefined4 *)(local_res18 + 7) = 0;
      *(undefined4 *)local_res18 = 0x43696541;
      *(undefined4 *)((longlong)local_res18 + 4) = 0x4d53445f;
      *(undefined4 *)(local_res18 + 1) = 0x3c;
      *(undefined4 *)((longlong)local_res18 + 0xc) = 4;
      *(undefined4 *)(local_res18 + 2) = 0x100002;
      *(undefined4 *)((longlong)local_res18 + 0x14) = 0xe4db149b;
      *(undefined4 *)(local_res18 + 3) = 0x425bfcfe;
      *(undefined4 *)((longlong)local_res18 + 0x1c) = 0x3592d8a6;
      *(undefined4 *)(local_res18 + 4) = 0x7ffc787d;
      *(undefined4 *)((longlong)local_res18 + 0x24) = 0x40000;
      *(undefined4 *)(local_res18 + 5) = 1;
      *(undefined8 *)((longlong)local_res18 + 0x2c) = 0x40000;
      *(undefined8 *)((longlong)local_res18 + 0x34) = 0x40003;
      iVar2 = StorPortExtendedFunction
                        (0x1b,param_1,0,0x4d53445f,local_res18,0x3c,local_res20,0x10c,local_res10);
      if ((iVar2 != 0) || (local_res10[0] < 0x14)) goto LAB_14001653f;
      pvVar8 = local_res20;
      if (((byte)*(undefined4 *)((longlong)local_res20 + 0x10) & 3) == 3) {
        if ((*(uint *)(param_1 + 0x2c) & 0x10) == 0) {
          *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x10;
        }
        *local_res18 = 0;
        local_res18[1] = 0;
        local_res18[2] = 0;
        local_res18[3] = 0;
        local_res18[4] = 0;
        local_res18[5] = 0;
        local_res18[6] = 0;
        *(undefined4 *)(local_res18 + 7) = 0;
        memset(local_res20,0,0x10c);
        *(undefined4 *)local_res18 = 0x43696541;
        *(undefined4 *)((longlong)local_res18 + 4) = 0x4d53445f;
        *(undefined4 *)(local_res18 + 1) = 0x3c;
        *(undefined4 *)((longlong)local_res18 + 0xc) = 4;
        *(undefined4 *)(local_res18 + 2) = 0x100002;
        *(undefined4 *)((longlong)local_res18 + 0x14) = 0xe4db149b;
        *(undefined4 *)(local_res18 + 3) = 0x425bfcfe;
        *(undefined4 *)((longlong)local_res18 + 0x1c) = 0x3592d8a6;
        *(undefined4 *)(local_res18 + 4) = 0x7ffc787d;
        *(undefined4 *)((longlong)local_res18 + 0x24) = 0x40000;
        *(undefined4 *)(local_res18 + 5) = 1;
        *(undefined4 *)((longlong)local_res18 + 0x2c) = 0x40000;
        *(undefined4 *)(local_res18 + 6) = 1;
        *(undefined8 *)((longlong)local_res18 + 0x34) = 0x40003;
        iVar2 = StorPortExtendedFunction
                          (0x1b,param_1,0,0x4d53445f,local_res18,0x3c,local_res20,0x10c,local_res10)
        ;
        if ((iVar2 != 0) || (local_res10[0] < 0x14)) goto LAB_14001653f;
        uVar7 = 0;
        lVar6 = (longlong)local_res20 + 0xc;
        pvVar8 = local_res20;
        if (*(int *)((longlong)local_res20 + 8) != 0) {
          do {
            if ((short)*(uint *)(lVar6 + 4) == -1) {
              uVar4 = *(uint *)(lVar6 + 4) >> 0x10;
              uVar5 = (ulonglong)uVar4;
              uVar3 = IsPortValid(param_1,uVar4);
              if ((char)uVar3 != '\0') {
                puVar1 = (uint *)(*(longlong *)(param_1 + 0x1b0 + uVar5 * 8) + 0x254);
                *puVar1 = *puVar1 | 1;
                pvVar8 = local_res20;
              }
            }
            uVar3 = (ulonglong)*(ushort *)(lVar6 + 2);
            if (*(ushort *)(lVar6 + 2) < 4) {
              uVar3 = 4;
            }
            uVar7 = uVar7 + 1;
            lVar6 = lVar6 + 4 + uVar3;
          } while (uVar7 < *(uint *)((longlong)pvVar8 + 8));
        }
      }
      goto LAB_140016543;
    }
  }
  else {
LAB_14001653f:
    pvVar8 = local_res20;
LAB_140016543:
    if (local_res18 == (undefined8 *)0x0) goto LAB_140016561;
    StorPortExtendedFunction(1,param_1);
  }
  pvVar8 = local_res20;
LAB_140016561:
  if (pvVar8 != (void *)0x0) {
    StorPortExtendedFunction(1,param_1,pvVar8);
  }
  return;
}



===== AhciDeviceInitialize @ 14001659c =====

undefined8 AhciDeviceInitialize(ulonglong *param_1)

{
  uint *puVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong *puVar8;
  uint uVar9;
  char cVar10;
  char local_res8 [8];
  undefined4 uVar11;
  
  RecordExecutionHistory((longlong *)param_1,7);
  puVar8 = param_1 + 3;
  lVar5 = IsAtaDevice((uint *)puVar8);
  if ((char)lVar5 == '\0') {
    if ((uint)*puVar8 == 2) {
      cVar10 = '\0';
      UpdateSetFeatureCommands((longlong)param_1,-1,'\x03','\0','B');
      if (((*(byte *)(param_1[0x18] + 0x9c) & 0x20) != 0) &&
         ((*(byte *)(param_1[0x18] + 0x9e) & 0x20) == 0)) {
        UpdateSetFeatureCommands((longlong)param_1,-1,'\x10',cVar10,'\x05');
      }
    }
    goto LAB_14001693c;
  }
  if ((param_1[0x4b] & 0x40) != 0) {
    UpdateSetFeatureCommands((longlong)param_1,-1,'\x03','\0','D');
  }
  uVar11 = 0;
  UpdateSetFeatureCommands((longlong)param_1,-1,'\x02','\0','\0');
  uVar6 = IsAhciDEVSLPSupported(param_1);
  if ((char)uVar6 == '\0') {
    *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) & 0xfffffff9;
  }
  else {
    uVar9 = (uint)param_1[0x4b] >> 2 & 3;
    if (uVar9 - 2 < 2) {
      uVar2 = *(uint *)(*param_1 + 0x1ac);
      if ((uVar2 & 0x10) != 0) {
        if ((uVar2 & 0x20) != 0) {
          if (((*(uint *)(*param_1 + 0x1a8) >> 0xe & 1) == 0) ||
             ((*(byte *)(param_1[0x18] + 0x9c) & 8) == 0)) {
            uVar9 = 1;
          }
          else {
            *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) | 0x100;
          }
        }
        goto LAB_14001665f;
      }
      uVar9 = 1;
LAB_140016664:
      if ((*(uint *)(*param_1 + 0x1ac) & 0x20) != 0) {
        if (((*(uint *)(*param_1 + 0x1a8) >> 0xe & 1) == 0) ||
           ((*(ushort *)(param_1[0x18] + 0x98) >> 9 & 1) == 0)) {
          uVar9 = 0;
        }
        else {
          *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) | 0x80;
        }
      }
    }
    else {
LAB_14001665f:
      if (uVar9 == 1) goto LAB_140016664;
    }
    puVar1 = (uint *)((longlong)param_1 + 0x254);
    *puVar1 = *puVar1 & 0xfffffff9 | uVar9 * 2;
    if (uVar9 != 0) {
      uVar9 = *(uint *)(param_1[0x129] + 0x44);
      puVar8 = param_1;
      bVar3 = DeviceDevSlpDETO((longlong)param_1);
      uVar9 = (uint)bVar3 << 2 | uVar9 & 0xfffffc02;
      bVar3 = DeviceDevSlpMDAT((longlong)puVar8);
      *(uint *)(param_1[0x129] + 0x44) = ((uint)bVar3 << 10 ^ uVar9) & 0x7c00 ^ uVar9;
      LOCK();
      UNLOCK();
      if (((*puVar1 & 6) == 6) || ((*puVar1 & 6) == 4)) {
        AhciPortSetDevslpIdleTimeout((longlong *)param_1);
      }
      if ((*(ushort *)(param_1[0x18] + 0x9e) & 0x100) == 0) {
        uVar11 = 9;
        UpdateSetFeatureCommands((longlong)param_1,-1,'\x10','\0','\t');
      }
    }
    uVar9 = *(uint *)(param_1[0x129] + 0x44);
    if (*(char *)(*param_1 + 0x18e) != '\0') {
      uVar11 = 2;
      StorPortExtendedFunction
                (0x57,*param_1,param_1 + 1,0,2,L"DEVSLP Support",0xc,4,0,0,L"DEVSLP Mode",
                 *(uint *)((longlong)param_1 + 0x254) >> 1 & 3,L"DEVSLP.ADSE",uVar9 & 1,
                 L"DEVSLP.DSP",uVar9 >> 1 & 1,L"DEVSLP.DITO",uVar9 >> 0xf & 0x3ff,L"DEVSLP.DM",
                 uVar9 >> 0x19 & 0xf,L"DEVSLP.DETO",(char)(uVar9 >> 2),L"DEVSLP.MDAT",
                 uVar9 >> 10 & 0x1f,0,0);
    }
  }
  local_res8[0] = '\0';
  iVar4 = StorPortExtendedFunction(0x43,*param_1,param_1 + 1,local_res8,uVar11);
  if (iVar4 == 0) {
    if (local_res8[0] == '\0') {
      uVar6 = param_1[0x4a] & 0xfffffffffffeffff;
    }
    else {
      uVar6 = param_1[0x4a] | 0x10000;
    }
    param_1[0x4a] = uVar6;
  }
LAB_14001693c:
  uVar6 = IsDeviceHybridInfoSupported((longlong)param_1);
  if ((((char)uVar6 != '\0') && ((*(byte *)(param_1[0x18] + 0xa6) & 0x20) != 0)) &&
     ((*(byte *)(param_1[0x18] + 0xac) & 0x20) == 0)) {
    UpdateSetFeatureCommands((longlong)param_1,-0x7a,'\x06','\0','\0');
    param_1[0x4a] = param_1[0x4a] | 0x80000;
  }
  AhciPortEvaluateSDDMethod(param_1);
  AhciPortGetInitCommands(param_1);
  AhciPortIssueInitCommands((longlong *)param_1);
  ActivateQueue((longlong *)param_1,'\0');
  uVar7 = RecordExecutionHistory((longlong *)param_1,0x10000007);
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
}



===== AhciKickDevslpIdleTimer @ 1400169dc =====

bool AhciKickDevslpIdleTimer(longlong *param_1)

{
  uint uVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar1 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if ((*(uint *)(*param_1 + 0x34) & 1) != 0) {
    RecordExecutionHistory(param_1,0x48);
  }
  if (((*(uint *)(param_1 + 0x5c) | *(uint *)((longlong)param_1 + 0x2dc) | *(uint *)(param_1 + 0x5b)
        | *(uint *)((longlong)param_1 + 0x2d4) | *(uint *)(param_1 + 0x5a)) & 1) == 0) {
    local_18._0_7_ = CONCAT25(0xefa0,(undefined5)local_18);
    local_18 = CONCAT71(local_18._1_7_,0x66);
    BuildLocalCommand(param_1,&local_18,AhciKickDevslpIdleTimerComplete);
    *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) & 0xffffffdf;
    AhciProcessIo(param_1,param_1 + 0x12e,0);
    ActivateQueue(param_1,'\0');
    if ((*(uint *)((longlong)param_1 + 0x254) & 0x20) == 0) {
      do {
        if (49999 < uVar1) {
          return false;
        }
        StorPortStallExecution(10);
        uVar1 = uVar1 + 10;
      } while ((*(uint *)((longlong)param_1 + 0x254) & 0x20) == 0);
      return uVar1 < 50000;
    }
  }
  else if ((*(uint *)(*param_1 + 0x34) & 1) != 0) {
    RecordExecutionHistory(param_1,0x10010048);
  }
  return true;
}



===== AhciKickDevslpIdleTimerComplete @ 140016ae0 =====

void AhciKickDevslpIdleTimerComplete(longlong param_1)

{
  *(uint *)(param_1 + 0x254) = *(uint *)(param_1 + 0x254) | 0x20;
  return;
}



===== AhciPortAhciEnableDevslpADSE @ 140016af0 =====

void AhciPortAhciEnableDevslpADSE(longlong *param_1)

{
  *(uint *)(param_1[0x129] + 0x44) = *(uint *)(param_1[0x129] + 0x44) | 1;
  LOCK();
  UNLOCK();
  if (((*(uint *)(*param_1 + 0x1ac) & 0x20) != 0) &&
     ((*(ushort *)(param_1[0x18] + 0x98) >> 9 & 1) != 0)) {
    *(uint *)(param_1[0x129] + 0x18) = *(uint *)(param_1[0x129] + 0x18) | 0x800000;
    LOCK();
    UNLOCK();
  }
  AhciKickDevslpIdleTimer(param_1);
  *(uint *)((longlong)param_1 + 0x254) = *(uint *)((longlong)param_1 + 0x254) | 8;
  if (*(char *)(*param_1 + 0x18e) != '\0') {
    StorPortExtendedFunction
              (0x55,*param_1,param_1 + 1,0,3,L"DEVSLP Enabled",4,4,0,0,L"Using HW DEVSLP",1,
               L"Success",1);
  }
  return;
}



===== AhciPortEvaluateSDDMethod @ 140016bec =====

void AhciPortEvaluateSDDMethod(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined4 local_res8 [2];
  undefined4 *local_res10;
  
  local_res8[0] = 0;
  local_res10 = (undefined4 *)0x0;
  iVar6 = StorPortExtendedFunction(0,*param_1,0x218,0x69636841,&local_res10);
  if (iVar6 == 0) {
    if (local_res10 == (undefined4 *)0x0) {
      return;
    }
    memset(local_res10,0,0x218);
    lVar9 = 4;
    *local_res10 = 0x43696541;
    local_res10[1] = 0x4444535f;
    local_res10[2] = 0x218;
    local_res10[3] = 1;
    local_res10[4] = 0x2000002;
    puVar8 = (undefined8 *)param_1[0x18];
    puVar7 = (undefined8 *)(local_res10 + 5);
    do {
      uVar5 = puVar8[1];
      *puVar7 = *puVar8;
      puVar7[1] = uVar5;
      uVar5 = puVar8[3];
      puVar7[2] = puVar8[2];
      puVar7[3] = uVar5;
      uVar5 = puVar8[5];
      puVar7[4] = puVar8[4];
      puVar7[5] = uVar5;
      uVar5 = puVar8[7];
      puVar7[6] = puVar8[6];
      puVar7[7] = uVar5;
      uVar5 = puVar8[9];
      puVar7[8] = puVar8[8];
      puVar7[9] = uVar5;
      uVar5 = puVar8[0xb];
      puVar7[10] = puVar8[10];
      puVar7[0xb] = uVar5;
      uVar2 = *(undefined4 *)((longlong)puVar8 + 100);
      uVar3 = *(undefined4 *)(puVar8 + 0xd);
      uVar4 = *(undefined4 *)((longlong)puVar8 + 0x6c);
      *(undefined4 *)(puVar7 + 0xc) = *(undefined4 *)(puVar8 + 0xc);
      *(undefined4 *)((longlong)puVar7 + 100) = uVar2;
      *(undefined4 *)(puVar7 + 0xd) = uVar3;
      *(undefined4 *)((longlong)puVar7 + 0x6c) = uVar4;
      puVar1 = puVar8 + 0xe;
      uVar2 = *(undefined4 *)((longlong)puVar8 + 0x74);
      uVar3 = *(undefined4 *)(puVar8 + 0xf);
      uVar4 = *(undefined4 *)((longlong)puVar8 + 0x7c);
      puVar8 = puVar8 + 0x10;
      *(undefined4 *)(puVar7 + 0xe) = *(undefined4 *)puVar1;
      *(undefined4 *)((longlong)puVar7 + 0x74) = uVar2;
      *(undefined4 *)(puVar7 + 0xf) = uVar3;
      *(undefined4 *)((longlong)puVar7 + 0x7c) = uVar4;
      lVar9 = lVar9 + -1;
      puVar7 = puVar7 + 0x10;
    } while (lVar9 != 0);
    StorPortExtendedFunction(0x1b,*param_1,param_1 + 1,0x4444535f,local_res10,0x218,0,0,local_res8);
  }
  if (local_res10 != (undefined4 *)0x0) {
    StorPortExtendedFunction(1,*param_1);
  }
  return;
}



===== AhciPortGetInitCommands @ 140016d50 =====

void AhciPortGetInitCommands(undefined8 *param_1)

{
  longlong *plVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  undefined1 *puVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  byte bVar12;
  undefined4 local_res8 [2];
  int local_res10 [2];
  int *local_res18;
  undefined4 local_res20;
  undefined4 local_res24;
  undefined4 uVar13;
  int *piVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  
  plVar1 = param_1 + 0x149;
  local_res18 = (int *)0x0;
  piVar11 = (int *)0x0;
  local_res8[0] = 0;
  uVar9 = 0;
  *(undefined2 *)(param_1 + 0x148) = 0;
  bVar2 = true;
  *(undefined1 *)((longlong)param_1 + 0xa42) = 0;
  if (*plVar1 != 0) {
    StorPortExtendedFunction(1,*param_1);
    *plVar1 = 0;
  }
  local_res20 = 0x42696541;
  local_res24 = 0x4654475f;
  iVar4 = StorPortExtendedFunction(0,*param_1,0x100,0x69636841,&local_res18);
  if (local_res18 != (int *)0x0) {
    puVar16 = local_res8;
    uVar15 = 0x100;
    uVar13 = 8;
    piVar14 = local_res18;
    iVar4 = StorPortExtendedFunction
                      (0x1b,*param_1,param_1 + 1,0x4654475f,&local_res20,8,local_res18,0x100,puVar16
                      );
    if (iVar4 == -0x3efffffc) {
      uVar10 = local_res18[1];
      if (uVar10 < 0x101) goto LAB_140016f27;
      StorPortExtendedFunction(1,*param_1);
      local_res18 = (int *)0x0;
      iVar4 = StorPortExtendedFunction
                        (0,*param_1,uVar10,0x69636841,&local_res18,uVar13,piVar14,uVar15,puVar16);
      if (local_res18 != (int *)0x0) {
        iVar4 = StorPortExtendedFunction
                          (0x1b,*param_1,param_1 + 1,0x4654475f,&local_res20,8,local_res18,uVar10,
                           local_res8);
      }
    }
  }
  if ((((iVar4 == 0) && (local_res18 != (int *)0x0)) && (*local_res18 == 0x426f6541)) &&
     ((local_res18[2] == 1 && (piVar11 = local_res18 + 3, (short)*piVar11 == 2)))) {
    uVar7 = (ulonglong)*(ushort *)((longlong)local_res18 + 0xe) / 7;
    uVar9 = (uint)((*(ushort *)((longlong)local_res18 + 0xe) - uVar7 >> 1) + uVar7 >> 2);
  }
LAB_140016f27:
  uVar10 = 0;
  local_res10[0] = 0;
  iVar4 = StorPortExtendedFunction(0x37,*param_1,0,&DAT_14002a0b0,local_res10);
  if ((iVar4 == 0) && (bVar2 = true, local_res10[0] == 1)) {
    bVar2 = false;
  }
  bVar12 = (char)uVar9 + 1;
  *(byte *)(param_1 + 0x148) = bVar12;
  lVar5 = IsAtaDevice((uint *)(param_1 + 3));
  if ((char)lVar5 != '\0') {
    if ((*(uint *)(param_1 + 0x2e) & 0x10) != 0) {
      bVar12 = bVar12 + 1;
      *(byte *)(param_1 + 0x148) = bVar12;
    }
    if (bVar2) {
      bVar12 = bVar12 + 1;
      *(byte *)(param_1 + 0x148) = bVar12;
    }
    bVar3 = NeedsPuisSpinUpOnPowerUp((longlong)param_1);
    if (bVar3) {
      bVar12 = bVar12 + 1;
      *(byte *)(param_1 + 0x148) = bVar12;
    }
  }
  if (((bVar12 != 0) &&
      (iVar4 = StorPortExtendedFunction(0,*param_1,(ulonglong)bVar12 << 4,0x69636841,plVar1),
      iVar4 == 0)) && ((void *)*plVar1 != (void *)0x0)) {
    bVar12 = *(byte *)(param_1 + 0x148);
    if ((int)((ulonglong)bVar12 << 4) != 0) {
      memset((void *)*plVar1,0,(ulonglong)bVar12 << 4);
      bVar12 = *(byte *)(param_1 + 0x148);
    }
    bVar3 = NeedsPuisSpinUpOnPowerUp((longlong)param_1);
    if ((bVar3) && (bVar12 != 0)) {
      puVar6 = (undefined1 *)*plVar1;
      uVar10 = 1;
      puVar6[6] = 0xef;
      *puVar6 = 7;
    }
    if ((char)uVar9 != '\0') {
      uVar7 = (ulonglong)(uVar9 & 0xff);
      piVar11 = piVar11 + 1;
      do {
        lVar5 = *plVar1;
        uVar8 = (ulonglong)uVar10;
        uVar10 = uVar10 + 1;
        *(int *)(lVar5 + uVar8 * 0x10) = *piVar11;
        *(short *)(lVar5 + 4 + uVar8 * 0x10) = (short)piVar11[1];
        *(undefined1 *)(lVar5 + 6 + uVar8 * 0x10) = *(undefined1 *)((longlong)piVar11 + 6);
        uVar7 = uVar7 - 1;
        piVar11 = (int *)((longlong)piVar11 + 7);
      } while (uVar7 != 0);
    }
    if (*(byte *)(param_1 + 0x148) != uVar10) {
      puVar6 = (undefined1 *)((ulonglong)uVar10 * 0x10 + *plVar1);
      uVar10 = uVar10 + 1;
      *puVar6 = 0x66;
      puVar6[6] = 0xef;
    }
    lVar5 = IsAtaDevice((uint *)(param_1 + 3));
    if ((char)lVar5 != '\0') {
      if ((bVar2) && (*(byte *)(param_1 + 0x148) != uVar10)) {
        uVar7 = (ulonglong)uVar10;
        uVar10 = uVar10 + 1;
        *(undefined1 *)(*plVar1 + 6 + uVar7 * 0x10) = 0xf5;
      }
      if ((*(byte *)(param_1 + 0x148) != uVar10) && ((*(uint *)(param_1 + 0x2e) & 0x10) != 0)) {
        BuildSetDateAndTimeTaskFile((undefined8 *)((ulonglong)uVar10 * 0x10 + *plVar1));
        uVar10 = uVar10 + 1;
      }
    }
    *(char *)((longlong)param_1 + 0xa41) = (char)uVar10;
  }
  if (local_res18 != (int *)0x0) {
    StorPortExtendedFunction(1,*param_1);
  }
  return;
}



===== AhciPortInitialize @ 14001712c =====

ulonglong AhciPortInitialize(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  byte bVar6;
  undefined4 uVar7;
  undefined4 local_res8 [2];
  int local_res10 [2];
  
  lVar1 = *param_1;
  local_res8[0] = 0;
  local_res10[0] = 0;
  if ((*(uint *)(lVar1 + 0x34) & 1) != 0) {
    RecordExecutionHistory(param_1,0x24);
  }
  *(undefined1 *)((longlong)param_1 + 0x275) = 1;
  param_1[0x4a] = param_1[0x4a] | 0x800;
  param_1[0x129] = ((ulonglong)*(uint *)(param_1 + 0x48) + 2) * 0x80 + *(longlong *)(lVar1 + 400);
  lVar3 = StorPortGetPhysicalAddress(lVar1,0,param_1[0x12a],local_res8);
  param_1[300] = lVar3;
  if (lVar3 == 0) {
    uVar7 = 0xff02;
  }
  else if ((*(uint *)(param_1 + 300) & 0x3ff) == 0) {
    *(uint *)param_1[0x129] = *(uint *)(param_1 + 300);
    LOCK();
    UNLOCK();
    if (*(int *)(lVar1 + 0x1a8) < 0) {
      *(undefined4 *)(param_1[0x129] + 4) = *(undefined4 *)((longlong)param_1 + 0x964);
      LOCK();
      UNLOCK();
    }
    lVar3 = StorPortGetPhysicalAddress(lVar1,0,param_1[299],local_res8);
    param_1[0x12d] = lVar3;
    if (lVar3 == 0) {
      uVar7 = 0xff04;
    }
    else {
      if ((char)param_1[0x12d] == '\0') {
        *(int *)(param_1[0x129] + 8) = (int)param_1[0x12d];
        LOCK();
        UNLOCK();
        if (*(int *)(lVar1 + 0x1a8) < 0) {
          *(undefined4 *)(param_1[0x129] + 0xc) = *(undefined4 *)((longlong)param_1 + 0x96c);
          LOCK();
          UNLOCK();
        }
        lVar3 = StorPortGetPhysicalAddress(lVar1,0,param_1[0x139],local_res8);
        param_1[0x13a] = lVar3;
        lVar3 = StorPortGetPhysicalAddress(lVar1,0,param_1[0x146],local_res8);
        param_1[0x147] = lVar3;
        lVar3 = StorPortGetPhysicalAddress(lVar1,0,param_1[0x18],local_res8);
        param_1[0x19] = lVar3;
        lVar3 = StorPortGetPhysicalAddress(lVar1,0,param_1[0x1a],local_res8);
        param_1[0x1b] = lVar3;
        lVar3 = StorPortGetPhysicalAddress(lVar1,0,param_1[0x3c],local_res8);
        param_1[0x3d] = lVar3;
        *(char *)(param_1 + 2) = (char)param_1[0x48];
        *(undefined4 *)(param_1 + 1) = 1;
        *(undefined4 *)((longlong)param_1 + 0xc) = 4;
        *(undefined2 *)((longlong)param_1 + 0x11) = 0;
        *(undefined4 *)((longlong)param_1 + 0x28c) = 1;
        *(undefined4 *)(param_1[0x129] + 0x30) = 0xffffffff;
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1[0x129] + 0x10) = 0xffffffff;
        LOCK();
        UNLOCK();
        **(int **)(*param_1 + 0x1a0) = 1 << ((byte)param_1[0x48] & 0x1f);
        LOCK();
        UNLOCK();
        param_1[0x4a] = param_1[0x4a] | 1;
        if ((*(uint *)(lVar1 + 0x1a8) >> 8 & 0x1f) == 0) {
          bVar6 = 1;
        }
        else {
          bVar6 = (byte)(*(uint *)(lVar1 + 0x1a8) >> 8) & 0x1f;
        }
        *(byte *)((longlong)param_1 + 0x274) = bVar6;
        if (((*(uint *)(lVar1 + 0x38) & 1) != 0) || (*(char *)(lVar1 + 0x18c) != '\0')) {
          *(undefined1 *)((longlong)param_1 + 0x274) = 1;
          bVar6 = 1;
        }
        *(undefined1 *)((longlong)param_1 + 0x276) = 0;
        *(byte *)((longlong)param_1 + 0x1e) = bVar6;
        if ((*(char *)(lVar1 + 0x18c) == '\0') && ((*(uint *)(lVar1 + 0x38) & 2) != 0)) {
          P_NotRunning(param_1,param_1[0x129]);
          AhciCOMRESET(param_1,param_1[0x129]);
        }
        iVar2 = StorPortExtendedFunction(0x37,*param_1,0,&DAT_14002a0a0,local_res10);
        if (((iVar2 == 0) && (local_res10[0] != 0)) &&
           (*(char *)((longlong)param_1 + 0x235) == '\0')) {
          AhciPortUpdateLogPageUsingCachedData(param_1);
        }
        *(undefined4 *)((longlong)param_1 + 0xbc) = 0xffffffff;
        uVar4 = RecordExecutionHistory(param_1,0x10000024);
        return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
      }
      uVar7 = 0xff05;
    }
  }
  else {
    uVar7 = 0xff03;
  }
  uVar5 = RecordExecutionHistory(param_1,uVar7);
  return uVar5 & 0xffffffffffffff00;
}



===== AhciPortNVCacheCompletion @ 140017480 =====

void AhciPortNVCacheCompletion(undefined8 *param_1,longlong param_2)

{
  byte bVar1;
  byte *pbVar2;
  ushort uVar3;
  uint3 uVar4;
  uint uVar5;
  uint5 uVar6;
  ulonglong uVar7;
  longlong lVar8;
  
  uVar7 = GetSrbExtension(param_2);
  if (*(char *)(param_2 + 2) == '(') {
    lVar8 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar8 = *(longlong *)(param_2 + 0x18);
  }
  *(undefined4 *)(lVar8 + 0x28) = 0;
  pbVar2 = *(byte **)(uVar7 + 0x2988);
  if (pbVar2 == (byte *)0x0) {
    if (*(char *)(param_2 + 3) == '\x01') {
      *(undefined8 *)(lVar8 + 0x40) = 0;
    }
    else {
      *(uint *)(lVar8 + 0x40) = (uint)*(byte *)(uVar7 + 0x1102);
      *(uint *)(lVar8 + 0x44) = (uint)*(byte *)(uVar7 + 0x1103);
    }
  }
  else {
    *(uint *)(lVar8 + 0x40) = (uint)pbVar2[6];
    if ((pbVar2[6] & 1) != 0) {
      *(uint *)(lVar8 + 0x44) = (uint)*pbVar2;
    }
    *(uint *)(lVar8 + 0x2c) = (uint)CONCAT11(pbVar2[1],pbVar2[9]);
    bVar1 = pbVar2[0xc];
    *(ulonglong *)(lVar8 + 0x34) = (ulonglong)bVar1 * 0x100;
    uVar3 = CONCAT11(bVar1,pbVar2[0xb]);
    *(ulonglong *)(lVar8 + 0x34) = (ulonglong)uVar3 * 0x100;
    uVar4 = CONCAT21(uVar3,pbVar2[10]);
    *(ulonglong *)(lVar8 + 0x34) = (ulonglong)uVar4 * 0x100;
    uVar5 = CONCAT31(uVar4,pbVar2[4]);
    *(ulonglong *)(lVar8 + 0x34) = (ulonglong)uVar5 * 0x100;
    uVar6 = CONCAT41(uVar5,pbVar2[3]);
    *(ulonglong *)(lVar8 + 0x34) = (ulonglong)uVar6 * 0x100;
    *(ulonglong *)(lVar8 + 0x34) = (ulonglong)CONCAT51(uVar6,pbVar2[2]);
    StorPortExtendedFunction
              (0x53,*param_1,pbVar2,*(undefined4 *)(uVar7 + 0x2998),1,
               *(undefined8 *)(uVar7 + 0x2990));
  }
  return;
}



===== AhciPortPowerSettingNotification @ 1400175a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AhciPortPowerSettingNotification(ulonglong *param_1,int *param_2)

{
  byte bVar1;
  ulonglong uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint *puVar9;
  ulonglong *puVar10;
  int *piVar11;
  int *piVar12;
  undefined1 auStack_1f8 [32];
  uint local_1d8;
  ulonglong *local_1d0;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined1 local_1c0 [32];
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined1 local_188 [32];
  ulonglong local_168;
  undefined1 local_160 [32];
  ulonglong local_140;
  undefined1 local_138 [32];
  ulonglong local_118;
  undefined1 local_110 [32];
  ulonglong local_f0;
  undefined1 local_e8 [32];
  ulonglong local_c8;
  undefined1 local_c0 [32];
  ulonglong local_a0;
  undefined1 local_98 [32];
  ulonglong local_78;
  undefined1 local_70 [32];
  ulonglong local_50;
  ulonglong local_48;
  
  uVar8 = __security_cookie ^ (ulonglong)auStack_1f8;
  if ((((((char)param_1[0x49] == -1) || ((int)param_1[3] == 6)) ||
       (puVar10 = param_1, local_1d0 = param_1, local_48 = uVar8,
       uVar8 = NoLpmSupport((longlong *)param_1), (char)uVar8 != '\0')) ||
      ((uVar8 = IsLPMCapablePort(puVar10), (char)uVar8 == '\0' || (param_2[6] != 4)))) ||
     ((piVar11 = param_2, uVar8 = IsLpmModeSetting(param_2), (char)uVar8 == '\0' &&
      (uVar8 = IsLpmAdaptiveSetting(param_2), (char)uVar8 == '\0')))) {
    return uVar8 & 0xffffffffffffff00;
  }
  piVar12 = piVar11;
  uVar8 = IsLpmAdaptiveSetting(piVar11);
  if ((char)uVar8 == '\0') {
    puVar9 = (uint *)IsLpmModeSetting(piVar11);
    if (((char)puVar9 != '\0') &&
       (puVar9 = (uint *)AhciLpmSettingsModes(param_1,**(uint **)(piVar12 + 4)),
       (char)puVar9 != '\0')) {
      puVar9 = (uint *)ActivateQueue((longlong *)param_1,'\0');
    }
  }
  else {
    puVar9 = *(uint **)(piVar12 + 4);
    if (*puVar9 < 0x493e1) {
      *(uint *)(param_1 + 0x4f) = *puVar9;
      bVar3 = SetAllowedLpmStates(param_1);
      *(int *)((longlong)param_1 + 0x45ec) = *(int *)((longlong)param_1 + 0x45ec) + 1;
      local_1d8 = (uint)param_1[0x4f];
      uVar7 = *(uint *)(param_1[0x129] + 0x18);
      uVar8 = *param_1;
      bVar1 = *(byte *)((longlong)param_1 + 0x277);
      uVar2 = param_1[0x4a];
      uVar6 = *(uint *)(uVar8 + 0x1ac);
      uVar5 = *(uint *)(uVar8 + 0x1a8);
      memset(&local_1c8,0,0x180);
      local_1c8 = 1;
      local_1c4 = 10;
      uVar4 = GetStringLength("LpmAdaptiveSetting",0x20);
      memcpy(local_1c0,"LpmAdaptiveSetting",(ulonglong)uVar4);
      local_19c = 0;
      local_1a0 = 1;
      uVar4 = GetStringLength("PowerSettingChangeCount",0x20);
      memcpy(local_188,"PowerSettingChangeCount",(ulonglong)uVar4);
      local_168 = (ulonglong)*(uint *)((longlong)local_1d0 + 0x45ec);
      uVar4 = GetStringLength("StateFlags",0x20);
      memcpy(local_160,"StateFlags",(ulonglong)uVar4);
      local_140 = uVar2;
      uVar4 = GetStringLength("LastUserLpmPowerSetting",0x20);
      memcpy(local_138,"LastUserLpmPowerSetting",(ulonglong)uVar4);
      local_118 = (ulonglong)bVar1;
      uVar4 = GetStringLength("CAP",0x20);
      memcpy(local_110,&s_CAP,(ulonglong)uVar4);
      local_f0 = (ulonglong)uVar5;
      uVar5 = GetStringLength("CAP2",0x20);
      memcpy(local_e8,&s_CAP2,(ulonglong)uVar5);
      local_c8 = (ulonglong)uVar6;
      uVar6 = GetStringLength("PxCMD",0x20);
      memcpy(local_c0,"PxCMD",(ulonglong)uVar6);
      local_a0 = (ulonglong)uVar7;
      uVar7 = GetStringLength("IPM",0x20);
      memcpy(local_98,"IPM",(ulonglong)uVar7);
      local_78 = (ulonglong)bVar3;
      uVar7 = GetStringLength("LpmMode|SlumberInterval",0x20);
      memcpy(local_70,"LpmMode|SlumberInterval",(ulonglong)uVar7);
      local_50 = (ulonglong)local_1d8;
      puVar9 = (uint *)StorPortExtendedFunction(0x4f,uVar8,local_1d0 + 1,&local_1c8);
    }
  }
  return CONCAT71((int7)((ulonglong)puVar9 >> 8),1);
}



===== AhciPortSetDevslpIdleTimeout @ 1400178c0 =====

undefined8 AhciPortSetDevslpIdleTimeout(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  
  lVar1 = *param_1;
  uVar3 = P_NotRunning(param_1,param_1[0x129]);
  if ((char)uVar3 == '\0') {
    return uVar3 & 0xffffffffffffff00;
  }
  uVar5 = *(uint *)(param_1[0x129] + 0x44);
  if ((uVar5 & 1) != 0) {
    uVar5 = uVar5 & 0xfffffffe;
    *(uint *)(param_1[0x129] + 0x44) = uVar5;
    LOCK();
    UNLOCK();
  }
  if (*(int *)(lVar1 + 0x20) == 1) {
    uVar2 = *(uint *)((longlong)param_1 + 0x264);
  }
  else {
    if (((byte)*(undefined4 *)((longlong)param_1 + 0x254) & 6) != 4) {
      uVar2 = 0;
      goto LAB_14001793c;
    }
    uVar2 = *(uint *)(param_1 + 0x4c);
  }
  if (0x3ff0 < uVar2) {
    uVar2 = 0x3ff0;
  }
LAB_14001793c:
  *(uint *)(param_1[0x129] + 0x44) =
       uVar5 ^ (uVar2 / ((uVar5 >> 0x19 & 0xf) + 1) << 0xf ^ uVar5) & 0x1ff8000;
  LOCK();
  UNLOCK();
  if (((byte)*(undefined4 *)((longlong)param_1 + 0x254) & 6) == 4) {
    *(uint *)(param_1[0x129] + 0x44) = *(uint *)(param_1[0x129] + 0x44) | 1;
    LOCK();
    UNLOCK();
  }
  uVar4 = P_Running_StartAttempt(param_1,'\0');
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== AhciPortStop @ 1400179b4 =====

void AhciPortStop(longlong *param_1)

{
  undefined8 uVar1;
  
  if ((*(uint *)(*param_1 + 0x34) & 1) != 0) {
    RecordExecutionHistory(param_1,0x25);
  }
  uVar1 = P_NotRunning(param_1,param_1[0x129]);
  if ((char)uVar1 == '\0') {
    RecordExecutionHistory(param_1,0xff08);
  }
  *(undefined4 *)(param_1[0x129] + 0x14) = 0;
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1[0x129] + 0x30) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1[0x129] + 0x10) = 0xffffffff;
  LOCK();
  UNLOCK();
  **(int **)(*param_1 + 0x1a0) = 1 << ((byte)param_1[0x48] & 0x1f);
  LOCK();
  UNLOCK();
  param_1[0x129] = 0;
  param_1[0x4a] = param_1[0x4a] & 0xfffffffffffffffc;
  RecordExecutionHistory(param_1,0x10000025);
  return;
}



===== AhciPortUpdateLogPageUsingCachedData @ 140017a80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AhciPortUpdateLogPageUsingCachedData(undefined8 *param_1)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_128 [32];
  undefined4 local_108;
  undefined8 **local_100;
  int *local_f8;
  int local_e8 [2];
  undefined8 *local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 uStack_58;
  undefined8 local_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined8 local_44;
  undefined8 local_38;
  undefined1 local_30;
  undefined8 local_28;
  undefined3 local_20;
  char cStack_1d;
  char local_1c;
  undefined1 local_1b;
  undefined2 local_1a;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_128;
  local_1a = 0;
  memset(&local_d8,0,0xb0);
  local_e0 = &local_d8;
  uVar2 = *(uint *)(param_1 + 0x48) & 0xf;
  local_e8[0] = 0xb0;
  local_28 = 0x4965676150676f4c;
  local_1b = 0;
  uVar3 = *(uint *)(param_1 + 0x48) >> 4 & 0xf;
  local_1c = (-(uVar2 < 10) & 0xf9U) + (char)uVar2 + '7';
  _local_20 = CONCAT13((-(uVar3 < 10) & 0xf9U) + (char)uVar3 + '7',0x6f666e);
  local_f8 = local_e8;
  local_100 = &local_e0;
  local_108 = 3;
  uVar1 = StorPortExtendedFunction(0x3e,*param_1,"StorAHCI",&local_28);
  if (((int)uVar1 == 0) && (local_e8[0] == 0xb0)) {
    param_1[0x1c] = local_d8;
    param_1[0x1d] = uStack_d0;
    param_1[0x1e] = local_c8;
    param_1[0x1f] = uStack_c0;
    param_1[0x20] = local_b8;
    param_1[0x21] = uStack_b0;
    param_1[0x22] = local_a8;
    param_1[0x23] = uStack_a0;
    param_1[0x24] = local_98;
    param_1[0x25] = uStack_90;
    param_1[0x26] = local_88;
    param_1[0x27] = uStack_80;
    param_1[0x28] = local_78;
    param_1[0x29] = uStack_70;
    param_1[0x2a] = local_68;
    param_1[0x2b] = uStack_60;
    *(undefined4 *)(param_1 + 0x2c) = uStack_58;
    *(undefined8 *)((longlong)param_1 + 0x164) = local_54;
    *(undefined4 *)((longlong)param_1 + 0x16c) = local_4c;
    *(undefined4 *)(param_1 + 0x2e) = local_48;
    *(undefined8 *)((longlong)param_1 + 0x1c4) = local_44;
    param_1[0x2f] = local_38;
    *(undefined1 *)(param_1 + 0x3e) = local_30;
    uVar1 = CONCAT71((int7)((ulonglong)local_38 >> 8),1);
    LOCK();
    *(uint *)(param_1 + 0x4a) = *(uint *)(param_1 + 0x4a) | 0x4000000;
    UNLOCK();
  }
  else {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  return uVar1;
}



===== AhciRegistryWriteWorker @ 140017c40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AhciRegistryWriteWorker(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_138 [32];
  undefined4 local_118;
  undefined8 *local_110;
  undefined4 local_108;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined4 uStack_78;
  undefined8 local_74;
  undefined4 local_6c;
  undefined4 local_68;
  undefined8 local_64;
  undefined8 local_58;
  undefined1 local_50;
  undefined8 local_48;
  undefined3 local_40;
  char cStack_3d;
  char local_3c;
  undefined1 local_3b;
  undefined2 local_3a;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_138;
  local_3a = 0;
  memset(&local_f8,0,0xb0);
  uVar2 = *(uint *)(param_2 + 0x240) & 0xf;
  local_48 = 0x4965676150676f4c;
  local_108 = 0xb0;
  local_3b = 0;
  uVar3 = *(uint *)(param_2 + 0x240) >> 4 & 0xf;
  local_3c = (-(uVar2 < 10) & 0xf9U) + (char)uVar2 + '7';
  _local_40 = CONCAT13((-(uVar3 < 10) & 0xf9U) + (char)uVar3 + '7',0x6f666e);
  local_f8 = *(undefined8 *)(param_2 + 0xe0);
  uStack_f0 = *(undefined8 *)(param_2 + 0xe8);
  local_e8 = *(undefined8 *)(param_2 + 0xf0);
  uStack_e0 = *(undefined8 *)(param_2 + 0xf8);
  local_d8 = *(undefined8 *)(param_2 + 0x100);
  uStack_d0 = *(undefined8 *)(param_2 + 0x108);
  local_c8 = *(undefined8 *)(param_2 + 0x110);
  uStack_c0 = *(undefined8 *)(param_2 + 0x118);
  local_b8 = *(undefined8 *)(param_2 + 0x120);
  uStack_b0 = *(undefined8 *)(param_2 + 0x128);
  local_a8 = *(undefined4 *)(param_2 + 0x130);
  uStack_a4 = *(undefined4 *)(param_2 + 0x134);
  uStack_a0 = *(undefined4 *)(param_2 + 0x138);
  uStack_9c = *(undefined4 *)(param_2 + 0x13c);
  local_98 = *(undefined8 *)(param_2 + 0x140);
  uStack_90 = *(undefined8 *)(param_2 + 0x148);
  uStack_88 = *(undefined8 *)(param_2 + 0x150);
  uStack_80 = *(undefined8 *)(param_2 + 0x158);
  uStack_78 = *(undefined4 *)(param_2 + 0x160);
  local_6c = *(undefined4 *)(param_2 + 0x16c);
  local_74 = *(undefined8 *)(param_2 + 0x164);
  local_68 = *(undefined4 *)(param_2 + 0x170);
  local_64 = *(undefined8 *)(param_2 + 0x1c4);
  local_58 = *(undefined8 *)(param_2 + 0x178);
  local_50 = *(undefined1 *)(param_2 + 0x1f0);
  local_110 = &local_f8;
  local_118 = 3;
  iVar1 = StorPortExtendedFunction(0x3f,param_1,"StorAHCI",&local_48);
  if (iVar1 == 0) {
    *(undefined1 *)(param_2 + 0x235) = 0;
  }
  if (param_3 != 0) {
    StorPortExtendedFunction(0x1f,param_1,param_3);
  }
  return;
}



===== BuildSetDateAndTimeTaskFile @ 140017de4 =====

void BuildSetDateAndTimeTaskFile(undefined8 *param_1)

{
  longlong lVar1;
  ulonglong local_res8 [4];
  
  local_res8[0] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  StorPortQuerySystemTime(local_res8);
  *(undefined2 *)((longlong)param_1 + 5) = 0x77a0;
  lVar1 = local_res8[0] / 10000 - 0xa9730b66800;
  *(char *)((longlong)param_1 + 2) = (char)lVar1;
  *(char *)((longlong)param_1 + 3) = (char)((ulonglong)lVar1 >> 8);
  *(char *)((longlong)param_1 + 4) = (char)((ulonglong)lVar1 >> 0x10);
  *(char *)((longlong)param_1 + 10) = (char)((ulonglong)lVar1 >> 0x18);
  *(char *)((longlong)param_1 + 0xb) = (char)((ulonglong)lVar1 >> 0x20);
  *(char *)((longlong)param_1 + 0xc) = (char)((ulonglong)lVar1 >> 0x28);
  return;
}



===== GetDownloadMicrocodeSupportCompletion @ 140017e70 =====

void GetDownloadMicrocodeSupportCompletion(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = GetSrbExtension(param_2);
  if (*(char *)(param_2 + 3) == '\x01') {
    UpdateDownloadMicrocodeSupport((longlong)param_1,*(longlong *)(uVar1 + 0x1120));
  }
  StorPortExtendedFunction
            (0x53,*param_1,*(longlong *)(uVar1 + 0x1120),0x200,1,*(undefined8 *)(uVar1 + 0x1128));
  return;
}



===== InitQueryLogPages @ 140017ef0 =====

void InitQueryLogPages(longlong param_1)

{
  ushort *_Dst;
  ushort uVar1;
  ulonglong uVar2;
  
  _Dst = (ushort *)(param_1 + 0xe0);
  uVar2 = IsDeviceGeneralPurposeLoggingSupported(param_1);
  if ((char)uVar2 != '\0') {
    memset(_Dst,0,0x84);
    *(undefined1 *)(param_1 + 0xe4) = 1;
    *(undefined2 *)(param_1 + 0xe8) = 1;
    *_Dst = 1;
    *(undefined1 *)(param_1 + 0xec) = 1;
    *(undefined1 *)(param_1 + 0xe5 + (ulonglong)*_Dst * 8) = 4;
    *(undefined2 *)(param_1 + 0xe6 + (ulonglong)*_Dst * 8) = 0;
    *(undefined2 *)(param_1 + 0xe8 + (ulonglong)*_Dst * 8) = 1;
    *(undefined2 *)(param_1 + 0xea + (ulonglong)*_Dst * 8) = 0;
    *_Dst = *_Dst + 1;
    *(undefined1 *)(param_1 + 0xe4 + (ulonglong)*_Dst * 8) = 1;
    *(undefined1 *)(param_1 + 0xe5 + (ulonglong)*_Dst * 8) = 4;
    *(undefined2 *)(param_1 + 0xe6 + (ulonglong)*_Dst * 8) = 1;
    *(undefined2 *)(param_1 + 0xe8 + (ulonglong)*_Dst * 8) = 1;
    *(undefined2 *)(param_1 + 0xea + (ulonglong)*_Dst * 8) = 0;
    *_Dst = *_Dst + 1;
    *(undefined1 *)(param_1 + 0xe4 + (ulonglong)*_Dst * 8) = 1;
    *(undefined1 *)(param_1 + 0xe5 + (ulonglong)*_Dst * 8) = 0x30;
    *(undefined2 *)(param_1 + 0xe6 + (ulonglong)*_Dst * 8) = 0;
    *(undefined2 *)(param_1 + 0xe8 + (ulonglong)*_Dst * 8) = 1;
    *(undefined2 *)(param_1 + 0xea + (ulonglong)*_Dst * 8) = 0;
    *_Dst = *_Dst + 1;
    *(undefined1 *)(param_1 + 0xe4 + (ulonglong)*_Dst * 8) = 1;
    *(undefined1 *)(param_1 + 0xe5 + (ulonglong)*_Dst * 8) = 0x30;
    *(undefined2 *)(param_1 + 0xe6 + (ulonglong)*_Dst * 8) = 3;
    *(undefined2 *)(param_1 + 0xe8 + (ulonglong)*_Dst * 8) = 1;
    *(undefined2 *)(param_1 + 0xea + (ulonglong)*_Dst * 8) = 0;
    *_Dst = *_Dst + 1;
    *(undefined1 *)(param_1 + 0xe4 + (ulonglong)*_Dst * 8) = 1;
    *(undefined1 *)(param_1 + 0xe5 + (ulonglong)*_Dst * 8) = 0x30;
    *(undefined2 *)(param_1 + 0xe6 + (ulonglong)*_Dst * 8) = 8;
    *(undefined2 *)(param_1 + 0xe8 + (ulonglong)*_Dst * 8) = 1;
    *(undefined2 *)(param_1 + 0xea + (ulonglong)*_Dst * 8) = 0;
    *_Dst = *_Dst + 1;
    *(undefined1 *)(param_1 + 0xe4 + (ulonglong)*_Dst * 8) = 1;
    *(undefined1 *)(param_1 + 0xe5 + (ulonglong)*_Dst * 8) = 0x30;
    *(undefined2 *)(param_1 + 0xe6 + (ulonglong)*_Dst * 8) = 9;
    *(undefined2 *)(param_1 + 0xe8 + (ulonglong)*_Dst * 8) = 1;
    *(undefined2 *)(param_1 + 0xea + (ulonglong)*_Dst * 8) = 0;
    *_Dst = *_Dst + 1;
    *(undefined1 *)(param_1 + 0xe4 + (ulonglong)*_Dst * 8) = 1;
    *(undefined1 *)(param_1 + 0xe5 + (ulonglong)*_Dst * 8) = 0x25;
    *(undefined2 *)(param_1 + 0xe6 + (ulonglong)*_Dst * 8) = 0;
    *(undefined2 *)(param_1 + 0xe8 + (ulonglong)*_Dst * 8) = 1;
    *(undefined2 *)(param_1 + 0xea + (ulonglong)*_Dst * 8) = 0;
    uVar1 = *_Dst + 1;
    *_Dst = uVar1;
    if (((*(ushort *)(*(longlong *)(param_1 + 0xc0) + 0x98) >> 8 & 1) == 0) ||
       ((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0x9a) & 0x20) == 0)) {
      *(undefined1 *)(param_1 + 0xe4 + (ulonglong)uVar1 * 8) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0xe4 + (ulonglong)uVar1 * 8) = 1;
    }
    *(undefined1 *)(param_1 + 0xe5 + (ulonglong)*_Dst * 8) = 0x12;
    *(undefined2 *)(param_1 + 0xe6 + (ulonglong)*_Dst * 8) = 0;
    *(undefined2 *)(param_1 + 0xe8 + (ulonglong)*_Dst * 8) = 1;
    *(undefined2 *)(param_1 + 0xea + (ulonglong)*_Dst * 8) = 0;
    uVar1 = *_Dst + 1;
    *_Dst = uVar1;
    if (((*(ushort *)(*(longlong *)(param_1 + 0xc0) + 0x98) >> 8 & 1) == 0) ||
       ((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0x9a) & 0x40) == 0)) {
      *(undefined1 *)(param_1 + 0xe4 + (ulonglong)uVar1 * 8) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0xe4 + (ulonglong)uVar1 * 8) = 1;
    }
    *(undefined1 *)(param_1 + 0xe5 + (ulonglong)*_Dst * 8) = 0x13;
    *(undefined2 *)(param_1 + 0xe6 + (ulonglong)*_Dst * 8) = 0;
    *(undefined2 *)(param_1 + 0xe8 + (ulonglong)*_Dst * 8) = 1;
    *(undefined2 *)(param_1 + 0xea + (ulonglong)*_Dst * 8) = 0;
    *_Dst = *_Dst + 1;
  }
  return;
}



===== IsDeviceGeneralPurposeLoggingSupported @ 1400181cc =====

ulonglong IsDeviceGeneralPurposeLoggingSupported(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = IsAtaDevice((uint *)(param_1 + 0x18));
  if (((char)uVar1 == '\0') || ((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0xa8) & 0x20) == 0)) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar1 = (ulonglong)(byte)((ushort)*(undefined2 *)(*(longlong *)(param_1 + 0xc0) + 0xa6) >> 10) &
            0xffffffffffffff01;
  }
  return uVar1;
}



===== IsLpmAdaptiveSetting @ 140018210 =====

ulonglong IsLpmAdaptiveSetting(int *param_1)

{
  ulonglong in_RAX;
  
  if ((((((*param_1 == -0x2549fc99) && (in_RAX = 0x53fe, (short)param_1[1] == 0x53fe)) &&
        (in_RAX = 0x4fbc, *(short *)((longlong)param_1 + 6) == 0x4fbc)) &&
       (((char)param_1[2] == -0x7e && (*(char *)((longlong)param_1 + 9) == '^')))) &&
      ((*(char *)((longlong)param_1 + 10) == 'R' &&
       ((*(char *)((longlong)param_1 + 0xb) == '\x1d' && ((char)param_1[3] == '\x06')))))) &&
     ((*(char *)((longlong)param_1 + 0xd) == -99 && (*(char *)((longlong)param_1 + 0xe) == '$')))) {
    return CONCAT71(0x4f,*(char *)((longlong)param_1 + 0xf) == 'V');
  }
  return in_RAX & 0xffffffffffffff00;
}



===== IsLpmModeSetting @ 14001826c =====

ulonglong IsLpmModeSetting(int *param_1)

{
  ulonglong in_RAX;
  
  if ((((((*param_1 == 0xb2d69d7) && (in_RAX = 0xa2a1, (short)param_1[1] == -0x5d5f)) &&
        (in_RAX = 0x449c, *(short *)((longlong)param_1 + 6) == 0x449c)) &&
       (((char)param_1[2] == -0x6a && (*(char *)((longlong)param_1 + 9) == -0x80)))) &&
      ((*(char *)((longlong)param_1 + 10) == -7 &&
       ((*(char *)((longlong)param_1 + 0xb) == '\x1c' && ((char)param_1[3] == 'p')))))) &&
     ((*(char *)((longlong)param_1 + 0xd) == 'R' && (*(char *)((longlong)param_1 + 0xe) == '\x1c')))
     ) {
    return CONCAT71(0x44,*(char *)((longlong)param_1 + 0xf) == '`');
  }
  return in_RAX & 0xffffffffffffff00;
}



===== IssueSetDateAndTimeCommand @ 1400182c8 =====

void IssueSetDateAndTimeCommand(undefined8 param_1,longlong param_2,char param_3)

{
  ulonglong uVar1;
  
  uVar1 = GetSrbExtension(param_2);
  BuildSetDateAndTimeTaskFile((undefined8 *)(uVar1 + 0x1108));
  *(undefined2 *)(uVar1 + 0x1100) = 0x100;
  *(ulonglong *)(uVar1 + 0x2968) = -(ulonglong)(param_3 != '\0') & 0x1400183d0;
  return;
}



===== NeedsPuisSpinUpOnPowerUp @ 140018320 =====

bool NeedsPuisSpinUpOnPowerUp(longlong param_1)

{
  ulonglong uVar1;
  
  if (((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0xa6) & 0x60) == 0x60) &&
     (uVar1 = DeviceIncursSeekPenalty(param_1), (char)uVar1 != '\0')) {
    uVar1 = IsDeviceHybridInfoSupported(param_1);
    return (char)uVar1 == '\0';
  }
  return false;
}



===== PortDevSleep @ 140018364 =====

void PortDevSleep(ulonglong *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  
  if ((param_1[0x4a] & 0x2000) != 0) {
    uVar2 = IsAhciDEVSLPSupported(param_1);
    if ((char)uVar2 != '\0') {
      param_1[0x4a] = param_1[0x4a] | 0x800;
      uVar1 = *(uint *)((longlong)param_1 + 0x254) & 6;
      if (uVar1 == 2) {
        AhciPortAhciEnableDevslpICC((longlong *)param_1);
      }
      else if (uVar1 == 6) {
        AhciPortAhciEnableDevslpADSE((longlong *)param_1);
      }
    }
  }
  return;
}



===== SetDateAndTimeCompletion @ 1400183d0 =====

void SetDateAndTimeCompletion(undefined8 param_1,longlong param_2)

{
  void *_Dst;
  
  _Dst = (void *)GetSrbExtension(param_2);
  memset(_Dst,0,0x29a0);
  *(undefined2 *)((longlong)_Dst + 0x1100) = 0x100;
  *(undefined1 *)((longlong)_Dst + 0x110e) = 0xe0;
  return;
}



===== UpdateDownloadMicrocodeSupport @ 140018410 =====

void UpdateDownloadMicrocodeSupport(longlong param_1,longlong param_2)

{
  undefined2 uVar1;
  ulonglong uVar2;
  ushort uVar3;
  ulonglong uVar4;
  
  *(undefined1 *)(param_1 + 0x1c8) = 0;
  if (((longlong)*(ulonglong *)(param_2 + 0x10) < 0) &&
     ((((*(ushort *)(*(longlong *)(param_1 + 0xc0) + 0x8a) & 0x100) != 0 ||
       ((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0xa6) & 1) != 0)) &&
      (uVar4 = *(ulonglong *)(param_2 + 0x10) >> 0x22, *(byte *)(param_1 + 0x1c8) = (byte)uVar4 & 1,
      (uVar4 & 1) != 0)))) {
    uVar4 = *(ulonglong *)(param_2 + 0x10) & 0xffff;
    if (uVar4 - 1 < 0xfffe) {
      uVar2 = 0x100;
      if (uVar4 < 0x100) {
        uVar2 = uVar4;
      }
      uVar1 = (undefined2)uVar2;
    }
    else {
      uVar1 = 1;
    }
    *(undefined2 *)(param_1 + 0x1c4) = uVar1;
    uVar3 = *(ushort *)(param_2 + 0x12);
    if ((ushort)(uVar3 - 1) < 0xfffe) {
      if (0xff < uVar3) {
        uVar3 = 0x100;
      }
      *(ushort *)(param_1 + 0x1c6) = uVar3;
      return;
    }
    *(undefined2 *)(param_1 + 0x1c6) = 0x100;
  }
  return;
}



===== AhciNcqErrorRecovery @ 1400184c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AhciNcqErrorRecovery(ulonglong *param_1)

{
  ulonglong *_Dst;
  undefined4 uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  undefined1 auStackY_218 [32];
  ulonglong local_1c0;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined1 local_1b0 [32];
  undefined8 local_190;
  undefined1 local_178 [32];
  undefined8 local_158;
  undefined1 local_150 [32];
  undefined8 local_130;
  undefined1 local_128 [32];
  undefined8 local_108;
  undefined1 local_100 [32];
  ulonglong local_e0;
  undefined1 local_d8 [32];
  ulonglong local_b8;
  undefined1 local_b0 [32];
  ulonglong local_90;
  undefined1 local_88 [32];
  ulonglong local_68;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_218;
  RecordExecutionHistory((longlong *)param_1,0x14);
  local_1c0 = 0;
  if ((param_1 != (ulonglong *)0x0) && ((int)param_1[3] != 2)) {
    StorPortQuerySystemTime(&local_1c0);
    if ((param_1[0x8be] == 0) || (35999999999 < local_1c0 - param_1[0x8be])) {
      uVar5 = param_1[0x8bc];
      uVar10 = *(undefined4 *)((longlong)param_1 + 0x45d4);
      uVar6 = param_1[0x8bd];
      uVar3 = param_1[0x49];
      uVar4 = param_1[0x4a];
      uVar8 = *(uint *)((longlong)param_1 + 0xb4);
      param_1[0x8be] = local_1c0;
      uVar1 = *(undefined4 *)((longlong)param_1 + 0x45e4);
      uVar2 = *(undefined4 *)((longlong)param_1 + 0x45dc);
      memset(&local_1b8,0,0x180);
      local_1b8 = 1;
      local_1b4 = 5;
      uVar7 = GetStringLength("AhciNcqErrorRecovery Enter",0x20);
      memcpy(local_1b0,"AhciNcqErrorRecovery Enter",(ulonglong)uVar7);
      local_190 = 1;
      uVar7 = GetStringLength("PortReset|PortErrorRecovery",0x20);
      memcpy(local_178,"PortReset|PortErrorRecovery",(ulonglong)uVar7);
      local_158 = CONCAT44((int)param_1[0x8ba],(int)param_1[0x8bb]);
      uVar7 = GetStringLength("StartFail|NonQErrorRecovery",0x20);
      memcpy(local_150,"StartFail|NonQErrorRecovery",(ulonglong)uVar7);
      local_130 = CONCAT44(uVar10,uVar2);
      uVar7 = GetStringLength("NCQError|NCQErrorComplete",0x20);
      memcpy(local_128,"NCQError|NCQErrorComplete",(ulonglong)uVar7);
      local_108 = CONCAT44((int)uVar5,uVar1);
      uVar7 = GetStringLength("PortDriverResetCount",0x20);
      memcpy(local_100,"PortDriverResetCount",(ulonglong)uVar7);
      local_e0 = (ulonglong)uVar8;
      uVar8 = GetStringLength("StateFlags",0x20);
      memcpy(local_d8,"StateFlags",(ulonglong)uVar8);
      local_b8 = uVar4;
      uVar8 = GetStringLength("StartState",0x20);
      memcpy(local_b0,"StartState",(ulonglong)uVar8);
      local_90 = uVar3;
      uVar8 = GetStringLength("TotalCountSurpriseRemove",0x20);
      memcpy(local_88,"TotalCountSurpriseRemove",(ulonglong)uVar8);
      local_68 = (ulonglong)(uint)uVar6;
      StorPortExtendedFunction(0x4f,*param_1,param_1 + 1);
    }
  }
  uVar9 = P_NotRunning((longlong *)param_1,param_1[0x129]);
  if ((((char)uVar9 == '\0') || ((char)*(byte *)((longlong)param_1 + 0x27c) < '\0')) ||
     ((*(byte *)((longlong)param_1 + 0x27c) & 8) != 0)) {
    uVar10 = 0x10160014;
  }
  else if ((((uint)param_1[0x5c] | (uint)param_1[0x5b] | *(uint *)((longlong)param_1 + 0x2d4) |
             *(uint *)((longlong)param_1 + 0x2dc) | (uint)param_1[0x5a]) & 1) == 0) {
    if ((param_1[0x4a] & 0x40000) == 0) {
      _Dst = param_1 + 0x13b;
      param_1[0x4a] = param_1[0x4a] | 0x40000;
      memset(_Dst,0,0x58);
      memset((void *)param_1[0x146],0,0x29a0);
      param_1[0x142] = param_1[0x146];
      param_1[0x141] = (ulonglong)_Dst;
      *(ulonglong *)(param_1[0x146] + 0x2970) = (ulonglong)*(uint *)((longlong)param_1 + 0x2dc);
      *(uint *)(param_1 + 0x5a) = (uint)param_1[0x5a] | *(uint *)((longlong)param_1 + 0x2dc);
      *(undefined4 *)((longlong)param_1 + 0x2dc) = 0;
      *(undefined4 *)((longlong)param_1 + 0x2e4) = 0;
      IssueReadLogExtCommand
                ((longlong)param_1,(longlong)_Dst,0x10,0,1,0,param_1 + 0x3d,param_1[0x3c],
                 NcqErrorRecoveryCompletion);
      param_1[0x4a] = param_1[0x4a] & 0xfffffffffffffffb;
      AhciProcessIo((longlong *)param_1,(longlong *)_Dst,1);
      P_Running_StartAttempt((longlong *)param_1,'\x01');
      RecordExecutionHistory((longlong *)param_1,0x10000014);
      local_1c0 = 0;
      if ((int)param_1[3] == 2) {
        return;
      }
      StorPortQuerySystemTime(&local_1c0);
      if ((param_1[0x8be] == 0) || (35999999999 < local_1c0 - param_1[0x8be])) {
        uVar5 = param_1[0x8bc];
        uVar10 = *(undefined4 *)((longlong)param_1 + 0x45d4);
        uVar6 = param_1[0x8bd];
        uVar3 = param_1[0x49];
        uVar4 = param_1[0x4a];
        uVar8 = *(uint *)((longlong)param_1 + 0xb4);
        param_1[0x8be] = local_1c0;
        uVar1 = *(undefined4 *)((longlong)param_1 + 0x45e4);
        uVar2 = *(undefined4 *)((longlong)param_1 + 0x45dc);
        memset(&local_1b8,0,0x180);
        local_1b4 = 5;
        local_1b8 = 1;
        uVar7 = GetStringLength("AhciNcqErrorRecovery Exit",0x20);
        memcpy(local_1b0,"AhciNcqErrorRecovery Exit",(ulonglong)uVar7);
        local_190 = 1;
        uVar7 = GetStringLength("PortReset|PortErrorRecovery",0x20);
        memcpy(local_178,"PortReset|PortErrorRecovery",(ulonglong)uVar7);
        local_158 = CONCAT44((int)param_1[0x8ba],(int)param_1[0x8bb]);
        uVar7 = GetStringLength("StartFail|NonQErrorRecovery",0x20);
        memcpy(local_150,"StartFail|NonQErrorRecovery",(ulonglong)uVar7);
        local_130 = CONCAT44(uVar10,uVar2);
        uVar7 = GetStringLength("NCQError|NCQErrorComplete",0x20);
        memcpy(local_128,"NCQError|NCQErrorComplete",(ulonglong)uVar7);
        local_108 = CONCAT44((int)uVar5,uVar1);
        uVar7 = GetStringLength("PortDriverResetCount",0x20);
        memcpy(local_100,"PortDriverResetCount",(ulonglong)uVar7);
        local_e0 = (ulonglong)uVar8;
        uVar8 = GetStringLength("StateFlags",0x20);
        memcpy(local_d8,"StateFlags",(ulonglong)uVar8);
        local_b8 = uVar4;
        uVar8 = GetStringLength("StartState",0x20);
        memcpy(local_b0,"StartState",(ulonglong)uVar8);
        local_90 = uVar3;
        uVar8 = GetStringLength("TotalCountSurpriseRemove",0x20);
        memcpy(local_88,"TotalCountSurpriseRemove",(ulonglong)uVar8);
        local_68 = (ulonglong)(uint)uVar6;
        StorPortExtendedFunction(0x4f,*param_1,param_1 + 1,&local_1b8);
        return;
      }
      return;
    }
    uVar10 = 0x10170015;
  }
  else {
    uVar10 = 0x10170014;
  }
  RecordExecutionHistory((longlong *)param_1,uVar10);
  AhciPortReset(param_1,'\0');
  return;
}



===== ForceGenxSpeed @ 140018b3c =====

void ForceGenxSpeed(longlong *param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 != 0) {
    uVar1 = *(uint *)(*param_1 + 0x1a8) >> 0x14;
    if ((uVar1 & 0xf) <= param_2) {
      param_2 = (uint)((byte)uVar1 & 0xf);
    }
    uVar1 = *(uint *)(param_1[0x129] + 0x2c);
    if ((uVar1 >> 4 & 0xf) != (param_2 & 0xff)) {
      *(uint *)(param_1[0x129] + 0x2c) = ((param_2 & 0xff) << 4 ^ uVar1) & 0xf0 ^ uVar1;
      LOCK();
      UNLOCK();
      AhciCOMRESET(param_1,param_1[0x129]);
      *(undefined4 *)(param_1[0x129] + 0x30) = 0xffffffff;
      LOCK();
      UNLOCK();
    }
  }
  return;
}



===== NcqErrorRecoveryCompletion @ 140018be0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NcqErrorRecoveryCompletion(ulonglong *param_1,longlong param_2,ulonglong *param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  byte bVar13;
  undefined1 auStack_248 [32];
  ulonglong local_208;
  ulonglong local_200;
  longlong local_1f8;
  undefined8 local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined1 local_1c0 [32];
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined1 local_188 [32];
  undefined8 local_168;
  undefined1 local_160 [32];
  undefined8 local_140;
  undefined1 local_138 [32];
  undefined8 local_118;
  undefined1 local_110 [32];
  ulonglong local_f0;
  undefined1 local_e8 [32];
  ulonglong local_c8;
  undefined1 local_c0 [32];
  ulonglong local_a0;
  undefined1 local_98 [32];
  ulonglong local_78;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_248;
  local_1f8 = param_2;
  uVar10 = GetSrbExtension(param_2);
  uVar2 = *(uint *)(uVar10 + 0x2970);
  local_1e8 = 0;
  local_1f0 = 3;
  local_1e0 = 0;
  uStack_1d8 = 0;
  local_200 = uVar10;
  RecordExecutionHistory((longlong *)param_1,0x1b);
  *(int *)((longlong)param_1 + 0x45e4) = *(int *)((longlong)param_1 + 0x45e4) + 1;
  local_208 = 0;
  if ((int)param_1[3] != 2) {
    StorPortQuerySystemTime(&local_208);
    if ((param_1[0x8be] == 0) || (35999999999 < local_208 - param_1[0x8be])) {
      uVar6 = param_1[0x8bc];
      uVar12 = *(undefined4 *)((longlong)param_1 + 0x45d4);
      uVar7 = param_1[0x8bd];
      uVar10 = param_1[0x49];
      uVar11 = param_1[0x4a];
      uVar9 = *(uint *)((longlong)param_1 + 0xb4);
      param_1[0x8be] = local_208;
      uVar3 = *(undefined4 *)((longlong)param_1 + 0x45e4);
      uVar4 = *(undefined4 *)((longlong)param_1 + 0x45dc);
      memset(&local_1c8,0,0x180);
      local_1c8 = 1;
      local_1c4 = 6;
      uVar8 = GetStringLength("NcqErrorRecoveryCompletion",0x20);
      memcpy(local_1c0,"NcqErrorRecoveryCompletion",(ulonglong)uVar8);
      local_19c = 0;
      local_1a0 = 1;
      uVar8 = GetStringLength("PortReset|PortErrorRecovery",0x20);
      memcpy(local_188,"PortReset|PortErrorRecovery",(ulonglong)uVar8);
      local_168 = CONCAT44((int)param_1[0x8ba],(int)param_1[0x8bb]);
      uVar8 = GetStringLength("StartFail|NonQErrorRecovery",0x20);
      memcpy(local_160,"StartFail|NonQErrorRecovery",(ulonglong)uVar8);
      local_140 = CONCAT44(uVar12,uVar4);
      uVar8 = GetStringLength("NCQError|NCQErrorComplete",0x20);
      memcpy(local_138,"NCQError|NCQErrorComplete",(ulonglong)uVar8);
      local_118 = CONCAT44((int)uVar6,uVar3);
      uVar8 = GetStringLength("PortDriverResetCount",0x20);
      memcpy(local_110,"PortDriverResetCount",(ulonglong)uVar8);
      local_f0 = (ulonglong)uVar9;
      uVar9 = GetStringLength("StateFlags",0x20);
      memcpy(local_e8,"StateFlags",(ulonglong)uVar9);
      local_c8 = uVar11;
      uVar9 = GetStringLength("StartState",0x20);
      memcpy(local_c0,"StartState",(ulonglong)uVar9);
      local_a0 = uVar10;
      uVar9 = GetStringLength("TotalCountSurpriseRemove",0x20);
      memcpy(local_98,"TotalCountSurpriseRemove",(ulonglong)uVar9);
      param_3 = param_1 + 1;
      local_78 = (ulonglong)(uint)uVar7;
      StorPortExtendedFunction(0x4f,*param_1,param_3,&local_1c8);
      uVar10 = local_200;
    }
  }
  cVar1 = *(char *)(local_1f8 + 3);
  if (cVar1 == '\x0e') {
    uVar12 = 0x1001001b;
    param_1[0x4a] = param_1[0x4a] & 0xfffffffffffbffff;
    *(int *)(param_1 + 0x16) = (int)param_1[0x16] + 1;
    goto LAB_1400190a3;
  }
  if (cVar1 == '\x01') {
    pbVar5 = (byte *)param_1[0x3c];
    bVar13 = *pbVar5 & 0x1f;
    uVar9 = 1 << bVar13;
    if ((uVar2 & uVar9) == 0) {
      uVar12 = 0x1002001b;
      goto LAB_14001902d;
    }
    uVar10 = param_1[((ulonglong)bVar13 + 0x18) * 4];
    if (uVar10 != 0) {
      uVar11 = GetSrbExtension(uVar10);
      *(byte *)(uVar11 + 0x1102) = pbVar5[2];
      *(byte *)(uVar11 + 0x1103) = pbVar5[3];
      if ((*(uint *)(uVar11 + 0x1104) & 0x40) != 0) {
        SetReturnRegisterValues((longlong)param_1,uVar10);
      }
      if ((*(char *)(param_1[0x18] + 0x9c) < '\0') && (pbVar5[0xe] != 0)) {
        AhciSetSenseData(uVar10,4,CONCAT71((int7)((ulonglong)param_3 >> 8),pbVar5[0xe]),pbVar5[0xf],
                         pbVar5[0x10]);
      }
      else {
        *(undefined1 *)(uVar10 + 3) = 4;
        AtaMapError((longlong)param_1,uVar10,
                    *(byte *)((ulonglong)bVar13 * 0x20 + 0x2f9 + (longlong)param_1) & 1);
      }
      *(uint *)(uVar11 + 0x1104) = *(uint *)(uVar11 + 0x1104) | 0x800;
      AhciInterruptSpinlockAcquire(*param_1,(int)param_1[0x48],(longlong)&local_1f0);
      *(uint *)(param_1 + 0x5a) = (uint)param_1[0x5a] & ~uVar9;
      *(uint *)(param_1 + 0x5c) = (uint)param_1[0x5c] | uVar9;
      param_1[0x4a] = param_1[0x4a] & 0xfffffffffffbffff;
      ReleaseSlottedCommand((longlong *)param_1,bVar13);
      ActivateQueue((longlong *)param_1,'\x01');
      goto LAB_14001907f;
    }
    param_1[0x4a] = param_1[0x4a] & 0xfffffffffffbffff;
  }
  else {
    if ((cVar1 == '\x05') && (*(char *)(uVar10 + 0x2978) == -1)) {
      uVar12 = 0x1004001b;
    }
    else {
      *(int *)(param_1 + 0x16) = (int)param_1[0x16] + 1;
      uVar12 = 0x1003001b;
    }
LAB_14001902d:
    RecordExecutionHistory((longlong *)param_1,uVar12);
    AhciInterruptSpinlockAcquire(*param_1,(int)param_1[0x48],(longlong)&local_1f0);
    *(uint *)((longlong)param_1 + 0x2dc) = *(uint *)((longlong)param_1 + 0x2dc) | uVar2;
    *(uint *)((longlong)param_1 + 0x2e4) = *(uint *)((longlong)param_1 + 0x2e4) | uVar2;
    param_1[0x4a] = param_1[0x4a] & 0xfffffffffffbffff;
    *(uint *)(param_1 + 0x5a) = (uint)param_1[0x5a] & ~uVar2;
    AhciPortReset(param_1,'\0');
LAB_14001907f:
    AhciInterruptSpinlockRelease(*param_1,(int)param_1[0x48],(longlong)&local_1f0);
  }
  if ((*(uint *)(*param_1 + 0x34) & 1) == 0) {
    return;
  }
  uVar12 = 0x1000001b;
LAB_1400190a3:
  RecordExecutionHistory((longlong *)param_1,uVar12);
  return;
}



===== P_Running_WaitWhileDET1 @ 1400190dc =====

void P_Running_WaitWhileDET1(longlong *param_1,char param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *param_1;
  do {
    if ((*(uint *)(lVar1 + 0x34) & 1) != 0) {
      RecordExecutionHistory(param_1,0x17);
    }
    if (((byte)*(undefined4 *)(param_1[0x129] + 0x28) & 0xf) == 3) {
      *(undefined1 *)(param_1 + 0x49) = 0x14;
      RecordExecutionHistory(param_1,0x10a20017);
      P_Running_WaitOnFRE(param_1,param_2);
      return;
    }
    if (100 < *(byte *)((longlong)param_1 + 0x24a)) {
      ForceGenxSpeed(param_1,1);
      *(undefined1 *)(param_1 + 0x49) = 0x13;
      RecordExecutionHistory(param_1,0x100a0017);
      if ((*(char *)(lVar1 + 0x18c) != '\0') ||
         ((iVar2 = StorPortExtendedFunction
                             (0x21,lVar1,param_1[0x153],P_Running_Callback,param_1,10000,0),
          iVar2 != 0 && (iVar2 != -0x3efffff4)))) {
        StorPortStallExecution(10000);
        P_Running_WaitOnDET3(param_1,param_2);
      }
      return;
    }
    *(byte *)((longlong)param_1 + 0x24a) = *(byte *)((longlong)param_1 + 0x24a) + 1;
    RecordExecutionHistory(param_1,0x10600017);
    if (*(char *)(lVar1 + 0x18c) == '\0') {
      iVar2 = StorPortExtendedFunction(0x21,lVar1,param_1[0x153],P_Running_Callback,param_1,10000,0)
      ;
      if (iVar2 == 0) {
        return;
      }
      if (iVar2 == -0x3efffff4) {
        return;
      }
    }
    StorPortStallExecution(10000);
  } while( true );
}



===== AhciBusChangeCallback @ 140019260 =====

void AhciBusChangeCallback
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,int param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  if (param_5 != 0) {
    uVar2 = (ulonglong)*(byte *)(param_4 + 8);
    uVar1 = IsPortValid(param_1,(uint)*(byte *)(param_4 + 8));
    if ((char)uVar1 != '\0') {
      param_5 = -0x3efffffe;
      StorPortNotification
                (0x1005,param_1,2,*(longlong *)(param_1 + 0x1b0 + uVar2 * 8) + 8,(int)uVar3,
                 AhciBusChangeCallback,uVar3,&param_5);
    }
  }
  return;
}



===== AhciBusChangeTimerCallback @ 1400192e0 =====

void AhciBusChangeTimerCallback(undefined8 param_1,ulonglong *param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  
  if ((param_2 != (ulonglong *)0x0) && (param_2[0x129] != 0)) {
    if ((*(uint *)(*param_2 + 0x2c) & 2) == 0) {
      AhciPortBusChangeDpcRoutine(param_2 + 0x120,param_1,param_2);
    }
    else {
      LOCK();
      puVar1 = param_2 + 0x59;
      uVar2 = *puVar1;
      *(uint *)puVar1 = (uint)*puVar1 & 0xfffffffb;
      UNLOCK();
      if (((uint)uVar2 >> 2 & 1) != 0) {
        PortReleaseActiveReference(param_2,0);
      }
    }
  }
  return;
}



===== AhciFillDeviceFailureLog @ 14001933c =====

void AhciFillDeviceFailureLog(longlong param_1,undefined4 *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  *param_2 = 0x128;
  param_2[1] = 0x128;
  *(undefined8 *)(param_2 + 2) = *(undefined8 *)(param_1 + 0x250);
  *(undefined8 *)(param_2 + 4) = *(undefined8 *)(param_1 + 0x248);
  uVar2 = *(undefined8 *)(param_1 + 0x98);
  *(undefined8 *)(param_2 + 6) = *(undefined8 *)(param_1 + 0x90);
  *(undefined8 *)(param_2 + 8) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0xa8);
  *(undefined8 *)(param_2 + 10) = *(undefined8 *)(param_1 + 0xa0);
  *(undefined8 *)(param_2 + 0xc) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0xb8);
  *(undefined8 *)(param_2 + 0xe) = *(undefined8 *)(param_1 + 0xb0);
  *(undefined8 *)(param_2 + 0x10) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x2d4);
  *(undefined8 *)(param_2 + 0x12) = *(undefined8 *)(param_1 + 0x2cc);
  *(undefined8 *)(param_2 + 0x14) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x2e4);
  *(undefined8 *)(param_2 + 0x16) = *(undefined8 *)(param_1 + 0x2dc);
  *(undefined8 *)(param_2 + 0x18) = uVar2;
  *(undefined8 *)(param_2 + 0x1a) = *(undefined8 *)(param_1 + 0x2ec);
  param_2[0x1c] = *(undefined4 *)(param_1 + 0x45d0);
  param_2[0x1d] = *(undefined4 *)(param_1 + 0x45d4);
  param_2[0x1e] = *(undefined4 *)(param_1 + 0x45d8);
  param_2[0x1f] = *(undefined4 *)(param_1 + 0x45dc);
  param_2[0x20] = *(undefined4 *)(param_1 + 0x45e0);
  param_2[0x21] = *(undefined4 *)(param_1 + 0x45e4);
  param_2[0x22] = *(undefined4 *)(param_1 + 0x45e8);
  param_2[0x23] = *(undefined4 *)(param_1 + 0x45ec);
  param_2[0x24] = *(undefined4 *)(param_1 + 0x45f8);
  param_2[0x25] = *(undefined4 *)(param_1 + 0x45fc);
  param_2[0x26] = *(undefined4 *)(param_1 + 0x4600);
  param_2[0x27] = *(undefined4 *)(param_1 + 0x4604);
  param_2[0x28] = *(undefined4 *)(param_1 + 0x460c);
  puVar1 = *(undefined8 **)(param_1 + 0x4630);
  if (puVar1 != (undefined8 *)0x0) {
    uVar2 = puVar1[1];
    *(undefined8 *)(param_2 + 0x2a) = *puVar1;
    *(undefined8 *)(param_2 + 0x2c) = uVar2;
    uVar2 = puVar1[3];
    *(undefined8 *)(param_2 + 0x2e) = puVar1[2];
    *(undefined8 *)(param_2 + 0x30) = uVar2;
    uVar2 = puVar1[5];
    *(undefined8 *)(param_2 + 0x32) = puVar1[4];
    *(undefined8 *)(param_2 + 0x34) = uVar2;
    uVar2 = puVar1[7];
    *(undefined8 *)(param_2 + 0x36) = puVar1[6];
    *(undefined8 *)(param_2 + 0x38) = uVar2;
    uVar2 = puVar1[9];
    *(undefined8 *)(param_2 + 0x3a) = puVar1[8];
    *(undefined8 *)(param_2 + 0x3c) = uVar2;
    uVar2 = puVar1[0xb];
    *(undefined8 *)(param_2 + 0x3e) = puVar1[10];
    *(undefined8 *)(param_2 + 0x40) = uVar2;
    uVar2 = puVar1[0xd];
    *(undefined8 *)(param_2 + 0x42) = puVar1[0xc];
    *(undefined8 *)(param_2 + 0x44) = uVar2;
    uVar2 = puVar1[0xf];
    *(undefined8 *)(param_2 + 0x46) = puVar1[0xe];
    *(undefined8 *)(param_2 + 0x48) = uVar2;
  }
  return;
}



===== AhciPortBusChangeDpcRoutine @ 1400194a0 =====

void AhciPortBusChangeDpcRoutine(undefined8 param_1,undefined8 param_2,ulonglong *param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  char local_res18 [16];
  
  if (param_3 != (ulonglong *)0x0) {
    local_res18[0] = '\0';
    if ((*(uint *)(*param_3 + 0x2c) & 2) == 0) {
      LOCK();
      puVar1 = param_3 + 0x59;
      uVar2 = *puVar1;
      *(uint *)puVar1 = (uint)*puVar1 | 2;
      UNLOCK();
      if (((uint)uVar2 >> 1 & 1) == 0) {
        RecordExecutionHistory((longlong *)param_3,0x30);
        LOCK();
        puVar1 = param_3 + 0x59;
        uVar2 = *puVar1;
        *(uint *)puVar1 = (uint)*puVar1 | 4;
        UNLOCK();
        if (((uint)uVar2 >> 2 & 1) == 0) {
          uVar3 = PortAcquireActiveReference(param_3,0,local_res18);
          if ((char)uVar3 == '\0') {
            LOCK();
            *(uint *)(param_3 + 0x59) = (uint)param_3[0x59] & 0xfffffffb;
            UNLOCK();
          }
          if (local_res18[0] != '\0') {
            return;
          }
        }
        LOCK();
        puVar1 = param_3 + 0x59;
        uVar2 = *puVar1;
        *(uint *)puVar1 = (uint)*puVar1 & 0xfffffffd;
        UNLOCK();
        if (((uint)uVar2 >> 1 & 1) != 0) {
          PortBusChangeProcess(param_3);
        }
      }
    }
    else {
      LOCK();
      puVar1 = param_3 + 0x59;
      uVar2 = *puVar1;
      *(uint *)puVar1 = (uint)*puVar1 & 0xfffffffb;
      UNLOCK();
      if (((uint)uVar2 >> 2 & 1) != 0) {
        PortReleaseActiveReference(param_3,0);
      }
    }
  }
  return;
}



===== AhciPortCheckIOStatusAndConfigureFastFail @ 14001954c =====

ulonglong AhciPortCheckIOStatusAndConfigureFastFail(ulonglong *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  ulonglong uVar5;
  undefined7 extraout_var;
  
  uVar5 = *param_1;
  if ((*(char *)(uVar5 + 0x18c) == '\0') &&
     (uVar5 = IsAtaDevice((uint *)(param_1 + 3)), (char)uVar5 != '\0')) {
    if (((param_1[0x4a] >> 0x18 & 1) == 0) || (uVar5 = param_1[0x4a], (uVar5 >> 0x1b & 1) == 0)) {
      uVar5 = param_1[0x4a];
      if (((uVar5 >> 0x17 & 1) != 0) && (uVar5 = param_1[0x4a], (uVar5 >> 0x1b & 1) == 0)) {
        LOCK();
        piVar1 = (int *)((longlong)param_1 + 0xbc);
        iVar2 = *piVar1;
        *piVar1 = *piVar1;
        UNLOCK();
        if (iVar2 == 0) {
          bVar4 = IsThereIoOutstandingInDevice((longlong)param_1);
          uVar5 = CONCAT71(extraout_var,bVar4);
          if ((bVar4) && (param_2 == '\0')) {
            LOCK();
            *(int *)((longlong)param_1 + 0x462c) = *(int *)((longlong)param_1 + 0x462c) + 1;
            UNLOCK();
            uVar3 = *(uint *)(*param_1 + 0x58) - 5;
            uVar5 = (ulonglong)uVar3;
            if ((uVar3 < 0xfffffffa) &&
               (*(uint *)(*param_1 + 0x58) <= *(uint *)((longlong)param_1 + 0x462c))) {
              LOCK();
              *(uint *)(param_1 + 0x4a) = (uint)param_1[0x4a] | 0x8000000;
              UNLOCK();
              AhciPortMarkDeviceFailed((longlong *)param_1,4,2);
              uVar5 = StorPortExtendedFunction
                                (0x57,*param_1,param_1 + 1,2,0x36,L"Device stuck:Set fast fail",0x10
                                 ,2,0,0,L"StateFlag",param_1[0x4a],L"StartState",param_1[0x49],
                                 L"SuccessCount|UnsolicitedINT",
                                 CONCAT44((int)param_1[0x12],
                                          *(undefined4 *)((longlong)param_1 + 0x460c)),
                                 L"CrcError|MediaError",
                                 CONCAT44(*(undefined4 *)((longlong)param_1 + 0x94),
                                          (int)param_1[0x13]),L"EndofMedia|IllegalCommand",
                                 CONCAT44(*(undefined4 *)((longlong)param_1 + 0x9c),
                                          (int)param_1[0x14]),L"AbortedCommand|DeviceFault",
                                 CONCAT44(*(undefined4 *)((longlong)param_1 + 0xa4),
                                          (int)param_1[0x15]),L"OtherError|NcqReadLogError",
                                 CONCAT44(*(undefined4 *)((longlong)param_1 + 0xac),
                                          (int)param_1[0x16]),L"PortDriverReset|TotalReset",
                                 CONCAT44(*(undefined4 *)((longlong)param_1 + 0xb4),
                                          (int)param_1[0x17]));
            }
          }
        }
        else {
          uVar5 = 0xffffffff;
          LOCK();
          uVar3 = *(uint *)((longlong)param_1 + 0xbc);
          if (uVar3 == 0xffffffff) {
            *(uint *)((longlong)param_1 + 0xbc) = 0;
          }
          else {
            uVar5 = (ulonglong)uVar3;
          }
          UNLOCK();
          if (uVar3 == 0xffffffff) {
            if (*(int *)((longlong)param_1 + 0x462c) == 0) {
              return uVar5;
            }
          }
          else {
            LOCK();
            uVar3 = *(uint *)((longlong)param_1 + 0xbc);
            *(uint *)((longlong)param_1 + 0xbc) = 0;
            uVar5 = (ulonglong)uVar3;
            UNLOCK();
          }
          LOCK();
          *(undefined4 *)((longlong)param_1 + 0x462c) = 0;
          UNLOCK();
        }
      }
    }
    else {
      LOCK();
      *(uint *)(param_1 + 0x4a) = (uint)param_1[0x4a] & 0xf7ffffff;
      UNLOCK();
    }
  }
  return uVar5;
}



===== AhciPortIssueInitCommands @ 140019800 =====

void AhciPortIssueInitCommands(longlong *param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  
  RecordExecutionHistory(param_1,0x42);
  *(undefined1 *)((longlong)param_1 + 0xa42) = 0;
  LOCK();
  *(uint *)(param_1 + 0x4a) = *(uint *)(param_1 + 0x4a) | 0x2000000;
  UNLOCK();
  LOCK();
  puVar1 = (uint *)(param_1 + 0x4a);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 | 8;
  UNLOCK();
  if ((uVar2 >> 3 & 1) != 0) {
    RecordExecutionHistory(param_1,0x10010042);
    return;
  }
  if (((ulonglong)param_1[0x4a] >> 0xd & 1) != 0) {
    iVar3 = StorPortExtendedFunction(0x31,*param_1,param_1 + 1,0,0,0);
    if ((iVar3 == 0) || (iVar3 == -0x3efffff4)) {
      param_1[0x4a] = param_1[0x4a] | 0x40;
    }
  }
  IssueInitCommands(param_1);
  uVar4 = param_1[0x135];
  if (uVar4 != 0) {
    if (*(char *)((longlong)param_1 + 0x972) == '(') {
      uVar4 = param_1[0x13b];
    }
    if ((uVar4 & 0x7f) != 0) {
      uVar4 = (uVar4 - ((uint)uVar4 & 0x7f)) + 0x80;
    }
    if (*(short *)(uVar4 + 0x1100) != 0) {
      AhciProcessIo(param_1,param_1 + 0x12e,0);
    }
  }
  return;
}



===== AhciPortMarkDeviceFailed @ 1400198f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AhciPortMarkDeviceFailed(longlong *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined1 auStack_1c8 [32];
  uint local_1a8;
  wchar_t *local_1a0;
  undefined4 local_198;
  undefined4 *local_190;
  undefined4 local_188;
  undefined8 local_180;
  undefined4 *local_178;
  undefined4 local_168 [4];
  undefined4 local_158 [76];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1c8;
  memset(local_158,0,0x128);
  lVar2 = IsAtaDevice((uint *)(param_1 + 3));
  local_180 = 0;
  if ((char)lVar2 == '\0') {
    return;
  }
  lVar2 = *param_1;
  if (*(char *)(lVar2 + 0x18c) != '\0') {
    return;
  }
  AhciFillDeviceFailureLog((longlong)param_1,local_158);
  local_188 = (undefined4)local_180;
  if (param_2 == 1) {
    uVar1 = 1;
    if ((*(uint *)(param_1 + 0x8c1) & 1) == 0) {
      local_1a0 = L"Too many bus change";
LAB_140019af8:
      local_178 = local_168;
      local_190 = local_158;
      local_198 = 0x128;
      local_168[0] = 0xc1000002;
      local_1a8 = uVar1;
      StorPortNotification(0x100d,lVar2,param_1 + 1,param_3);
    }
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 3) {
        if ((*(uint *)(param_1 + 0x8c1) & 4) == 0) {
          local_178 = local_168;
          local_168[0] = 0xc1000002;
          local_190 = local_158;
          local_198 = 0x128;
          local_1a0 = L"Too many NonQueue error";
          local_1a8 = 3;
          StorPortNotification(0x100d,lVar2,param_1 + 1,param_3);
        }
        if ((*(uint *)(param_1 + 0x8c1) & 4) != 0) {
          return;
        }
        uVar1 = *(uint *)(param_1 + 0x8c1) | 4;
      }
      else {
        if (param_2 != 4) {
          return;
        }
        if ((*(uint *)(param_1 + 0x8c1) & 8) == 0) {
          local_178 = local_168;
          local_168[0] = 0xc1000002;
          local_190 = local_158;
          local_198 = 0x128;
          local_1a0 = L"Device may be stuck";
          local_1a8 = 4;
          StorPortNotification(0x100d,lVar2,param_1 + 1,param_3);
        }
        if ((*(uint *)(param_1 + 0x8c1) & 8) != 0) {
          return;
        }
        uVar1 = *(uint *)(param_1 + 0x8c1) | 8;
      }
      goto LAB_140019b36;
    }
    uVar1 = 2;
    if ((*(uint *)(param_1 + 0x8c1) & 2) == 0) {
      local_1a0 = L"Too many NCQ error";
      goto LAB_140019af8;
    }
  }
  if ((byte)((byte)uVar1 & (byte)*(uint *)(param_1 + 0x8c1)) != 0) {
    return;
  }
  uVar1 = *(uint *)(param_1 + 0x8c1) | uVar1;
LAB_140019b36:
  *(uint *)(param_1 + 0x8c1) = uVar1;
  return;
}



===== AhciPortStartTelemetry @ 140019b6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AhciPortStartTelemetry(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined1 auStack_208 [32];
  undefined4 local_1e8;
  undefined4 local_1e4;
  uint local_1e0;
  char *local_1d8;
  undefined8 *local_1d0;
  longlong local_1c8;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined1 local_1b0 [32];
  undefined4 local_190;
  undefined4 local_18c;
  undefined1 local_178 [32];
  undefined8 local_158;
  undefined1 local_150 [32];
  undefined8 local_130;
  undefined1 local_128 [32];
  undefined8 local_108;
  undefined1 local_100 [32];
  ulonglong local_e0;
  undefined1 local_d8 [32];
  undefined8 local_b8;
  undefined1 local_b0 [32];
  undefined8 local_90;
  undefined1 local_88 [32];
  ulonglong local_68;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_208;
  uVar11 = 0;
  local_1e0 = 0;
  local_1c8 = param_1;
  do {
    local_1d0 = *(undefined8 **)(local_1c8 + 0x1b0 + uVar11 * 8);
    if (local_1d0 != (undefined8 *)0x0) {
      if (*(char *)(local_1d0 + 0x49) == '\x16') {
        local_1d8 = "Port Start Success";
        local_1e8 = 0xc;
        if (*(uint *)(local_1d0 + 0x8c0) < 1000) goto LAB_140019df7;
        local_1e4 = 0;
      }
      else {
        local_1e4 = 1;
        local_1d8 = "Port Start Failed";
        local_1e8 = 2;
      }
      uVar1 = *(undefined4 *)((longlong)local_1d0 + 0x45e4);
      uVar2 = *(undefined4 *)(local_1d0 + 0x8bc);
      uVar3 = *(undefined4 *)((longlong)local_1d0 + 0x45d4);
      uVar4 = *(uint *)(local_1d0 + 0x8c0);
      uVar6 = local_1d0[0x49];
      uVar7 = local_1d0[0x4a];
      uVar10 = *(uint *)((longlong)local_1d0 + 0xb4);
      uVar8 = *local_1d0;
      uVar5 = *(undefined4 *)((longlong)local_1d0 + 0x45dc);
      memset(&local_1b8,0,0x180);
      local_1b4 = local_1e8;
      local_1b8 = 1;
      uVar9 = GetStringLength(local_1d8,0x20);
      memcpy(local_1b0,local_1d8,(ulonglong)uVar9);
      local_18c = local_1e4;
      local_190 = 1;
      uVar9 = GetStringLength("PortReset|PortErrorRecovery",0x20);
      memcpy(local_178,"PortReset|PortErrorRecovery",(ulonglong)uVar9);
      local_158 = CONCAT44(*(undefined4 *)(local_1d0 + 0x8ba),*(undefined4 *)(local_1d0 + 0x8bb));
      uVar9 = GetStringLength("StartFail|NonQErrorRecovery",0x20);
      memcpy(local_150,"StartFail|NonQErrorRecovery",(ulonglong)uVar9);
      local_130 = CONCAT44(uVar3,uVar5);
      uVar9 = GetStringLength("NCQError|NCQErrorComplete",0x20);
      memcpy(local_128,"NCQError|NCQErrorComplete",(ulonglong)uVar9);
      local_108 = CONCAT44(uVar2,uVar1);
      uVar9 = GetStringLength("PortDriverResetCount",0x20);
      memcpy(local_100,"PortDriverResetCount",(ulonglong)uVar9);
      local_e0 = (ulonglong)uVar10;
      uVar10 = GetStringLength("StateFlags",0x20);
      memcpy(local_d8,"StateFlags",(ulonglong)uVar10);
      local_b8 = uVar7;
      uVar10 = GetStringLength("StartState",0x20);
      memcpy(local_b0,"StartState",(ulonglong)uVar10);
      local_90 = uVar6;
      uVar10 = GetStringLength("PortStartTime(ms)",0x20);
      memcpy(local_88,"PortStartTime(ms)",(ulonglong)uVar10);
      local_68 = (ulonglong)uVar4;
      StorPortExtendedFunction(0x4f,uVar8,local_1d0 + 1,&local_1b8);
    }
LAB_140019df7:
    local_1e0 = local_1e0 + 1;
    uVar11 = (ulonglong)local_1e0;
    if (*(uint *)(local_1c8 + 0x184) < local_1e0) {
      return;
    }
  } while( true );
}



===== DigestDeviceRegistrySettings @ 140019e4c =====

void DigestDeviceRegistrySettings(longlong *param_1)

{
  uint *puVar1;
  ushort uVar2;
  char cVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  undefined4 uVar7;
  char *pcVar8;
  longlong lVar9;
  undefined4 local_res8;
  
  lVar9 = *param_1;
  if (*(char *)(lVar9 + 0x18c) != '\0') {
    return;
  }
  puVar1 = (uint *)(param_1 + 3);
  *(undefined4 *)(param_1 + 0x4c) = 6000;
  *(undefined4 *)((longlong)param_1 + 0x25c) = 0x32;
  uVar6 = *(uint *)(param_1 + 0x4b) & 0xfffff804 | 4;
  *(uint *)(param_1 + 0x4b) = uVar6;
  uVar7 = 1000;
  *(undefined8 *)((longlong)param_1 + 0x264) = 1000;
  *(undefined4 *)((longlong)param_1 + 0x26c) = 300;
  lVar5 = IsAtaDevice(puVar1);
  if ((char)lVar5 == '\0') {
    *(undefined4 *)(param_1 + 0x11) = 0;
    goto LAB_140019f1c;
  }
  if ((*(byte *)(param_1[0x18] + 0x152) & 1) == 0) {
LAB_140019ef8:
    uVar4 = 8;
  }
  else {
    uVar2 = *(ushort *)(param_1[0x18] + 0xd2);
    uVar4 = (uint)uVar2;
    if (uVar2 == 0) goto LAB_140019ef8;
    if (0x100 < uVar2) {
      uVar4 = 0x100;
    }
  }
  *(uint *)(param_1 + 0x11) = uVar4;
  *(uint *)(param_1 + 0x4b) = uVar6 | 0x800;
  *(undefined4 *)(param_1 + 0x4e) = uVar7;
LAB_140019f1c:
  pcVar8 = *(char **)(lVar9 + 0x60);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x68),(uint *)0x0);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4b) = *(uint *)(param_1 + 0x4b) | 1;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x70);
  if (pcVar8 != (char *)0x0) {
    uVar6 = *(uint *)(param_1 + 0x48);
    local_res8 = local_res8 & 0xff000000;
    if (uVar6 < 10) {
      local_res8 = CONCAT31(local_res8._1_3_,(char)param_1[0x48] + '0');
    }
    else {
      cVar3 = (char)((ulonglong)uVar6 / 10);
      local_res8._0_2_ = CONCAT11((char)uVar6 + cVar3 * -10 + '0',cVar3 + '0');
    }
    uVar6 = GetStringLength((char *)&local_res8,3);
    cVar3 = CompareId((longlong)&local_res8,uVar6,pcVar8,*(uint *)(lVar9 + 0x78),(uint *)0x0);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4b) = *(uint *)(param_1 + 0x4b) | 2;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x80);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    local_res8 = 0;
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x88),&local_res8);
    if ((cVar3 == '\x01') && (local_res8 - 1 < 0xffff)) {
      uVar6 = local_res8;
      if (0x100 < local_res8) {
        uVar6 = 0x100;
      }
      *(uint *)(param_1 + 0x11) = uVar6;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x90);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x98),(uint *)0x0);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4b) = *(uint *)(param_1 + 0x4b) | 0x10;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0xa0);
  if (pcVar8 != (char *)0x0) {
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0xa8),(uint *)0x0);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4b) = *(uint *)(param_1 + 0x4b) | 0x20;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0xb0);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0xb8),(uint *)0x0);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4b) = *(uint *)(param_1 + 0x4b) | 0x40;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0xc0);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    local_res8 = 0;
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 200),&local_res8);
    if ((cVar3 != '\0') && (local_res8 < 3)) {
      *(uint *)(param_1 + 0x4b) = (local_res8 & 3) << 2 | *(uint *)(param_1 + 0x4b) & 0xfffffff3;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0xe0);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    local_res8 = 0;
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0xe8),&local_res8);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4c) = local_res8;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0xd0);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    local_res8 = 0;
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0xd8),&local_res8);
    if (cVar3 != '\0') {
      *(uint *)((longlong)param_1 + 0x25c) = local_res8;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0xf0);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    local_res8 = 0;
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0xf8),&local_res8);
    if (cVar3 != '\0') {
      uVar6 = 0x3ff0;
      if (local_res8 < 0x3ff1) {
        uVar6 = local_res8;
      }
      *(uint *)((longlong)param_1 + 0x264) = uVar6;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x100);
  if (pcVar8 != (char *)0x0) {
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x108),(uint *)0x0);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4b) = *(uint *)(param_1 + 0x4b) | 0x100;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x120);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x128),(uint *)0x0);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4b) = *(uint *)(param_1 + 0x4b) | 0x80;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x130);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    local_res8 = 0;
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x138),&local_res8);
    if ((cVar3 != '\0') && (local_res8 - 1 < 0xff)) {
      *(uint *)(param_1 + 0x4d) = local_res8;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x140);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x148),(uint *)0x0);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4b) = *(uint *)(param_1 + 0x4b) | 0x200;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x110);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    local_res8 = 0;
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x118),&local_res8);
    if (cVar3 != '\0') {
      *(uint *)((longlong)param_1 + 0x26c) = local_res8;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x150);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x158),(uint *)0x0);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4b) = *(uint *)(param_1 + 0x4b) | 0x400;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x160);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    local_res8 = 0;
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x168),&local_res8);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4e) = local_res8;
    }
  }
  lVar9 = *param_1;
  pcVar8 = *(char **)(lVar9 + 0x170);
  if ((pcVar8 != (char *)0x0) && (lVar5 = IsAtaDevice(puVar1), (char)lVar5 != '\0')) {
    local_res8 = 0;
    uVar6 = GetStringLength((char *)(param_1 + 8),0x28);
    cVar3 = CompareId((longlong)(param_1 + 8),uVar6,pcVar8,*(uint *)(lVar9 + 0x178),&local_res8);
    if (cVar3 != '\0') {
      *(uint *)(param_1 + 0x4b) =
           *(uint *)(param_1 + 0x4b) & 0xfffff7ff | -(uint)(local_res8 != 0) & 0x800;
    }
  }
  return;
}



===== FillAtaCommandErrorStruct @ 14001a510 =====

void FillAtaCommandErrorStruct
               (undefined4 *param_1,undefined1 *param_2,longlong param_3,undefined4 param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  longlong lVar9;
  uint *puVar10;
  uint uVar11;
  undefined1 *puVar12;
  longlong lVar13;
  undefined4 *puVar14;
  ulonglong uVar15;
  
  uVar6 = GetSrbExtension((longlong)param_2);
  lVar13 = 8;
  puVar14 = param_1 + 2;
  lVar9 = 8;
  do {
    *(undefined1 *)puVar14 =
         *(undefined1 *)((param_3 - (longlong)param_1) + 0x248 + (longlong)puVar14);
    puVar14 = (undefined4 *)((longlong)puVar14 + 1);
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  puVar14 = param_1 + 4;
  do {
    *(undefined1 *)puVar14 =
         *(undefined1 *)((param_3 - (longlong)param_1) + 0x238 + (longlong)puVar14);
    puVar14 = (undefined4 *)((longlong)puVar14 + 1);
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  lVar9 = 0x80;
  puVar8 = param_2;
  do {
    puVar8[(longlong)param_1 + (0x18 - (longlong)param_2)] = *puVar8;
    puVar8 = puVar8 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  if (*(int *)(param_2 + 0x14) == 0) {
    if (param_2[2] == '(') {
      bVar4 = false;
      uVar11 = 0;
      puVar12 = (undefined1 *)0x0;
      puVar8 = puVar12;
      if (*(uint *)(param_2 + 0x38) != 0) {
        puVar10 = (uint *)(param_2 + 0x78);
        do {
          uVar2 = *puVar10;
          uVar7 = (ulonglong)uVar2;
          if ((0x7f < uVar2) &&
             (uVar15 = (ulonglong)*(uint *)(param_2 + 0x10), uVar2 < *(uint *)(param_2 + 0x10))) {
            iVar3 = *(int *)(param_2 + uVar7);
            puVar8 = puVar12;
            if (iVar3 == 0x40) {
              if (uVar7 + 0x28 <= uVar15) {
                if (param_2[uVar7 + 10] != '\0') {
                  puVar8 = param_2 + uVar7 + 0x18;
                }
                break;
              }
            }
            else if (iVar3 == 0x41) {
              if (uVar7 + 0x38 <= uVar15) {
                bVar4 = true;
                if (param_2[uVar7 + 10] == '\0') break;
                puVar12 = param_2 + uVar7 + 0x18;
              }
            }
            else if ((iVar3 == 0x42) && (uVar7 + 0x28 <= uVar15)) {
              puVar8 = param_2 + uVar7 + 0x20;
              if (*(int *)(param_2 + uVar7 + 0xc) == 0) {
                puVar8 = puVar12;
              }
              break;
            }
            puVar8 = puVar12;
            if (bVar4) break;
          }
          uVar11 = uVar11 + 1;
          puVar10 = puVar10 + 1;
          puVar8 = puVar12;
        } while (uVar11 < *(uint *)(param_2 + 0x38));
      }
    }
    else {
      puVar8 = param_2 + 0x48;
    }
    if (puVar8 != (undefined1 *)0x0) {
      puVar8 = param_2 + 0x48;
      if (param_2[2] == '(') {
        bVar4 = false;
        uVar11 = 0;
        puVar8 = (undefined1 *)0x0;
        if (*(uint *)(param_2 + 0x38) != 0) {
          puVar10 = (uint *)(param_2 + 0x78);
          puVar12 = (undefined1 *)0x0;
          do {
            uVar2 = *puVar10;
            uVar7 = (ulonglong)uVar2;
            puVar8 = puVar12;
            if ((0x7f < uVar2) &&
               (uVar15 = (ulonglong)*(uint *)(param_2 + 0x10), uVar2 < *(uint *)(param_2 + 0x10))) {
              iVar3 = *(int *)(param_2 + uVar7);
              if (iVar3 == 0x40) {
                if (uVar7 + 0x28 <= uVar15) {
                  if (param_2[uVar7 + 10] != '\0') {
                    puVar8 = param_2 + uVar7 + 0x18;
                  }
                  break;
                }
              }
              else if (iVar3 == 0x41) {
                if (uVar7 + 0x38 <= uVar15) {
                  bVar4 = true;
                  if (param_2[uVar7 + 10] == '\0') break;
                  puVar12 = param_2 + uVar7 + 0x18;
                }
              }
              else if ((iVar3 == 0x42) && (uVar7 + 0x28 <= uVar15)) {
                puVar8 = param_2 + uVar7 + 0x20;
                if (*(int *)(param_2 + uVar7 + 0xc) == 0) {
                  puVar8 = puVar12;
                }
                break;
              }
              puVar8 = puVar12;
              if (bVar4) break;
            }
            uVar11 = uVar11 + 1;
            puVar10 = puVar10 + 1;
            puVar12 = puVar8;
          } while (uVar11 < *(uint *)(param_2 + 0x38));
        }
      }
      lVar9 = 0x10;
      puVar12 = puVar8;
      do {
        puVar12[(longlong)param_1 + (0x98 - (longlong)puVar8)] = *puVar12;
        puVar12 = puVar12 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
    }
  }
  uVar1 = *(ushort *)(uVar6 + 0x1100);
  uVar5 = 0xff;
  if ((uVar1 == 0x400) || ((uVar1 >> 9 & 1) != 0)) {
    uVar5 = *(undefined1 *)(uVar6 + 0x110a);
  }
  else if ((uVar1 >> 8 & 1) != 0) {
    uVar5 = *(undefined1 *)(uVar6 + 0x110e);
  }
  *(undefined1 *)(param_1 + 0x2a) = uVar5;
  *(undefined1 *)((longlong)param_1 + 0xa9) = *(undefined1 *)(uVar6 + 0x1102);
  *(undefined1 *)((longlong)param_1 + 0xaa) = *(undefined1 *)(uVar6 + 0x1103);
  *param_1 = 2;
  param_1[1] = 0xb0;
  param_1[0x2b] = param_4;
  return;
}



===== GetABARAddress @ 14001a7bc =====

undefined8 GetABARAddress(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  
  if (*(uint *)(param_2 + 0x34) != 0) {
    for (uVar4 = 0; uVar4 < *(uint *)(param_2 + 0x34); uVar4 = uVar4 + 1) {
      lVar1 = *(longlong *)(param_2 + 0x38);
      uVar3 = (ulonglong)uVar4;
      if (*(int *)(param_2 + 8) == 5) {
        if (*(ulonglong *)(lVar1 + uVar3 * 0x10) == (ulonglong)*(uint *)(param_1 + 0xc)) {
LAB_14001a7f8:
          uVar2 = StorPortGetDeviceBase
                            (param_1,*(int *)(param_2 + 8),*(undefined4 *)(param_2 + 4),
                             *(undefined8 *)(lVar1 + uVar3 * 0x10),
                             *(undefined4 *)(lVar1 + 8 + uVar3 * 0x10),
                             *(char *)(lVar1 + 0xc + uVar3 * 0x10) == '\0');
          return uVar2;
        }
      }
      else if (*(longlong *)(lVar1 + uVar3 * 0x10) != 0) goto LAB_14001a7f8;
    }
  }
  return 0;
}



===== GetAdapterRegistrySettings @ 14001a84c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GetAdapterRegistrySettings(longlong param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  ulonglong _Size;
  ulonglong uVar5;
  undefined1 auStackY_b8 [32];
  char local_68 [4];
  uint local_64;
  uint local_60 [2];
  void *local_58;
  uint local_50 [2];
  char local_48 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  builtin_strncpy(local_48,"VEN_vvvv&DEV_dddd&REV_rr",0x19);
  local_68[0] = '\0';
  local_64 = 0x200;
  local_50[0] = 0;
  if (*(char *)(param_1 + 0x18c) != '\0') {
    return;
  }
  pvVar4 = (void *)StorPortAllocateRegistryBuffer(0x45522664,&local_64);
  if (pvVar4 == (void *)0x0) {
    return;
  }
  uVar5 = (ulonglong)local_64;
  local_58 = pvVar4;
  if (3 < local_64) {
    UlongToHex((longlong)(local_48 + 4),(uint)*(ushort *)(param_1 + 0x10),4);
    UlongToHex((longlong)(local_48 + 0xd),(uint)*(ushort *)(param_1 + 0x12),4);
    _Size = 2;
    UlongToHex((longlong)(local_48 + 0x16),(uint)*(byte *)(param_1 + 0x14),2);
    local_60[0] = (uint)uVar5;
    if (local_60[0] != 0) {
      memset(pvVar4,0,uVar5);
      _Size = uVar5;
    }
    uVar2 = GetStringLength(local_48,0x1d);
    local_68[0] = ReadMultiSzRegistryValueAndCompareId
                            (param_1,"ResetInInit",_Size,&local_58,&local_64,local_60,
                             (longlong)local_48,uVar2,(uint *)0x0);
    uVar2 = *(uint *)(param_1 + 0x38) | 2;
    if (local_68[0] == '\0') {
      uVar2 = *(uint *)(param_1 + 0x38) & 0xfffffffd;
    }
    *(uint *)(param_1 + 0x38) = uVar2;
    if (local_58 == (void *)0x0) {
      return;
    }
    local_60[0] = local_64;
    if (local_64 != 0) {
      _Size = (ulonglong)local_64;
      memset(local_58,0,_Size);
    }
    uVar2 = GetStringLength(local_48,0x1d);
    local_68[0] = ReadMultiSzRegistryValueAndCompareId
                            (param_1,"SingleIO",_Size,&local_58,&local_64,local_60,
                             (longlong)local_48,uVar2,(uint *)0x0);
    uVar2 = *(uint *)(param_1 + 0x38) | 1;
    if (local_68[0] == '\0') {
      uVar2 = *(uint *)(param_1 + 0x38) & 0xfffffffe;
    }
    *(uint *)(param_1 + 0x38) = uVar2;
    if (local_58 == (void *)0x0) {
      return;
    }
    local_60[0] = local_64;
    if (local_64 != 0) {
      _Size = (ulonglong)local_64;
      memset(local_58,0,_Size);
    }
    uVar2 = GetStringLength(local_48,0x1d);
    local_68[0] = ReadMultiSzRegistryValueAndCompareId
                            (param_1,"IgnoreHotPlug",_Size,&local_58,&local_64,local_60,
                             (longlong)local_48,uVar2,(uint *)0x0);
    uVar2 = *(uint *)(param_1 + 0x38) | 4;
    if (local_68[0] == '\0') {
      uVar2 = *(uint *)(param_1 + 0x38) & 0xfffffffb;
    }
    *(uint *)(param_1 + 0x38) = uVar2;
    if (local_58 == (void *)0x0) {
      return;
    }
    local_60[0] = local_64;
    if (local_64 != 0) {
      _Size = (ulonglong)local_64;
      memset(local_58,0,_Size);
    }
    uVar2 = GetStringLength(local_48,0x1d);
    local_68[0] = ReadMultiSzRegistryValueAndCompareId
                            (param_1,"NeverNonQueuedErrorRecovery",_Size,&local_58,&local_64,
                             local_60,(longlong)local_48,uVar2,(uint *)0x0);
    uVar2 = *(uint *)(param_1 + 0x38) | 8;
    if (local_68[0] == '\0') {
      uVar2 = *(uint *)(param_1 + 0x38) & 0xfffffff7;
    }
    *(uint *)(param_1 + 0x38) = uVar2;
    if (local_58 == (void *)0x0) {
      return;
    }
    local_60[0] = local_64;
    if (local_64 != 0) {
      _Size = (ulonglong)local_64;
      memset(local_58,0,_Size);
    }
    uVar2 = GetStringLength(local_48,0x1d);
    local_68[0] = ReadMultiSzRegistryValueAndCompareId
                            (param_1,"EnableCLOReset",_Size,&local_58,&local_64,local_60,
                             (longlong)local_48,uVar2,(uint *)0x0);
    uVar2 = *(uint *)(param_1 + 0x38) | 0x10;
    if (local_68[0] == '\0') {
      uVar2 = *(uint *)(param_1 + 0x38) & 0xffffffef;
    }
    *(uint *)(param_1 + 0x38) = uVar2;
    if (local_58 == (void *)0x0) {
      return;
    }
    local_60[0] = local_64;
    if (local_64 != 0) {
      _Size = (ulonglong)local_64;
      memset(local_58,0,_Size);
    }
    uVar2 = GetStringLength(local_48,0x1d);
    local_68[0] = ReadMultiSzRegistryValueAndCompareId
                            (param_1,"ExpectedMsiMessageCount",_Size,&local_58,&local_64,local_60,
                             (longlong)local_48,uVar2,local_50);
    if ((local_68[0] == '\0') || (local_50[0] == 0)) {
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    else {
      *(uint *)(param_1 + 0x44) = local_50[0];
    }
    if (local_58 == (void *)0x0) {
      return;
    }
    local_60[0] = local_64;
    if (local_64 != 0) {
      _Size = (ulonglong)local_64;
      memset(local_58,0,_Size);
    }
    uVar2 = GetStringLength(local_48,0x1d);
    cVar1 = ReadMultiSzRegistryValueAndCompareId
                      (param_1,"DmaFull64BitNoBoundaryReqSupport",_Size,&local_58,&local_64,local_60
                       ,(longlong)local_48,uVar2,(uint *)0x0);
    pvVar4 = local_58;
    uVar2 = *(uint *)(param_1 + 0x38) | 0x800;
    if (cVar1 == '\0') {
      uVar2 = *(uint *)(param_1 + 0x38) & 0xfffff7ff;
    }
    *(uint *)(param_1 + 0x38) = uVar2;
    if (local_58 == (void *)0x0) {
      return;
    }
    uVar5 = 0;
    local_68[0] = '\0';
    iVar3 = StorPortExtendedFunction(0x61,param_1,0,local_68);
    if ((iVar3 == 0) && (local_68[0] != '\0')) {
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x10000;
    }
    else {
      local_60[0] = local_64;
      if (local_64 != 0) {
        uVar5 = (ulonglong)local_64;
        memset(pvVar4,0,uVar5);
      }
      uVar2 = GetStringLength(local_48,0x1d);
      local_68[0] = ReadMultiSzRegistryValueAndCompareId
                              (param_1,"D3ColdInLowestSystemPower",uVar5,&local_58,&local_64,
                               local_60,(longlong)local_48,uVar2,(uint *)0x0);
      uVar2 = *(uint *)(param_1 + 0x38) | 0x10000;
      if (local_68[0] == '\0') {
        uVar2 = *(uint *)(param_1 + 0x38) & 0xfffeffff;
      }
      *(uint *)(param_1 + 0x38) = uVar2;
      pvVar4 = local_58;
      if (local_58 == (void *)0x0) {
        return;
      }
    }
    local_60[0] = local_64;
    if (local_64 != 0) {
      uVar5 = (ulonglong)local_64;
      memset(pvVar4,0,uVar5);
    }
    uVar2 = GetStringLength(local_48,0x1d);
    local_68[0] = ReadMultiSzRegistryValueAndCompareId
                            (param_1,"PRDTSplit",uVar5,&local_58,&local_64,local_60,
                             (longlong)local_48,uVar2,(uint *)0x0);
    uVar2 = *(uint *)(param_1 + 0x38) | 0x20000;
    if (local_68[0] == '\0') {
      uVar2 = *(uint *)(param_1 + 0x38) & 0xfffdffff;
    }
    *(uint *)(param_1 + 0x38) = uVar2;
    if (local_58 == (void *)0x0) {
      return;
    }
  }
  StorPortFreeRegistryBuffer(param_1,local_58);
  return;
}



===== GetDeviceRegistrySettings @ 14001ade0 =====

void GetDeviceRegistrySettings(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  ulonglong _Size;
  uint local_res8 [2];
  uint local_res10 [2];
  void *local_res18;
  
  local_res10[0] = 0x200;
  if ((*(char *)(param_1 + 0x18c) == '\0') &&
     (pvVar4 = (void *)StorPortAllocateRegistryBuffer(), pvVar4 != (void *)0x0)) {
    _Size = (ulonglong)local_res10[0];
    local_res18 = pvVar4;
    if (3 < local_res10[0]) {
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        memset(pvVar4,0,_Size);
        param_3 = _Size;
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"EnableFuaSupport",param_3,&local_res18,local_res10,local_res8,0,0,
                         (uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x60);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x68) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"TreatAsInternalPort",param_3,&local_res18,local_res10,local_res8,0
                         ,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x70);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x78) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"DSMDataSizeCapInBlocks",param_3,&local_res18,local_res10,
                         local_res8,0,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x80);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x88) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"NoFUACommand",param_3,&local_res18,local_res10,local_res8,0,0,
                         (uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x90);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x98) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"NoLPM",param_3,&local_res18,local_res10,local_res8,0,0,(uint *)0x0
                        );
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0xa0);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0xa8) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"NeedSetTransferModeCommand",param_3,&local_res18,local_res10,
                         local_res8,0,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0xb0);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0xb8) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"DeviceSleepMode",param_3,&local_res18,local_res10,local_res8,0,0,
                         (uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0xc0);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 200) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"IrIdleTimeoutInMS",param_3,&local_res18,local_res10,local_res8,0,0
                         ,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0xd0);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0xd8) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"DeviceSleepIdleTimeoutInMS",param_3,&local_res18,local_res10,
                         local_res8,0,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0xe0);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0xe8) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"HwDeviceSleepIdleTimeoutInMS",param_3,&local_res18,local_res10,
                         local_res8,0,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0xf0);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0xf8) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"NoIdleD3",param_3,&local_res18,local_res10,local_res8,0,0,
                         (uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x100);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x108) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"MinPowerCyclePeriodInSecs",param_3,&local_res18,local_res10,
                         local_res8,0,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x110);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x118) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"DisableHybrid",param_3,&local_res18,local_res10,local_res8,0,0,
                         (uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x120);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x128) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"MaxLbaRangeCountForChangeLba",param_3,&local_res18,local_res10,
                         local_res8,0,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x130);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x138) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"NoNcqEnhancedErrorRecovery",param_3,&local_res18,local_res10,
                         local_res8,0,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x140);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x148) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"SupportFirmwareUpgrade",param_3,&local_res18,local_res10,
                         local_res8,0,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x150);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x158) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"DeviceLowestPowerIdleTimeoutInMs",param_3,&local_res18,local_res10
                         ,local_res8,0,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (param_3 = (ulonglong)local_res8[0], local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x160);
        iVar3 = StorPortExtendedFunction(0,param_1,param_3,0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          param_3 = (ulonglong)local_res8[0];
          *(uint *)(param_1 + 0x168) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,param_3);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
      local_res8[0] = local_res10[0];
      if (local_res10[0] != 0) {
        param_3 = (ulonglong)local_res10[0];
        memset(pvVar4,0,param_3);
      }
      cVar2 = ReadMultiSzRegistryValueAndCompareId
                        (param_1,"EnableReinitDeviceAfterFwActivation",param_3,&local_res18,
                         local_res10,local_res8,0,0,(uint *)0x0);
      pvVar4 = local_res18;
      if ((cVar2 != '\0') && (local_res8[0] != 0)) {
        plVar1 = (longlong *)(param_1 + 0x170);
        iVar3 = StorPortExtendedFunction(0,param_1,local_res8[0],0x69636841,plVar1);
        if ((iVar3 == 0) || (*plVar1 != 0)) {
          *(uint *)(param_1 + 0x178) = local_res8[0];
          memcpy((void *)*plVar1,pvVar4,(ulonglong)local_res8[0]);
        }
      }
      if (pvVar4 == (void *)0x0) {
        return;
      }
    }
    StorPortFreeRegistryBuffer(param_1,pvVar4);
  }
  return;
}



===== GetMiniportRegistrySettings @ 14001b9f4 =====

void GetMiniportRegistrySettings(longlong param_1)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  uint local_res8 [2];
  
  local_res8[0] = 4;
  if ((*(char *)(param_1 + 0x18c) == '\0') &&
     (puVar3 = (uint *)StorPortAllocateRegistryBuffer(param_1,local_res8), puVar3 != (uint *)0x0)) {
    if (3 < local_res8[0]) {
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"LogFlags",1,4,puVar3,local_res8);
      if ((cVar1 != '\x01') || (uVar2 = *puVar3, uVar2 == 0)) {
        uVar2 = 0;
      }
      *(uint *)(param_1 + 0x34) = uVar2;
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"TestFlags",1,4,puVar3,local_res8);
      if ((cVar1 != '\x01') || (uVar2 = *puVar3, uVar2 == 0)) {
        uVar2 = 0;
      }
      *(uint *)(param_1 + 0x5c) = uVar2;
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"EtwThrottleInterval",1,4,puVar3,local_res8);
      if ((cVar1 != '\x01') || (uVar2 = *puVar3, uVar2 == 0)) {
        uVar2 = 3600000000;
      }
      *(uint *)(param_1 + 0x4c) = uVar2;
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"EtwEventsPerInterval",1,4,puVar3,local_res8);
      if ((cVar1 != '\x01') || (uVar2 = *puVar3, uVar2 == 0)) {
        uVar2 = 10;
      }
      *(uint *)(param_1 + 0x50) = uVar2;
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"ReportSataBusTypeAsAta",1,4,puVar3,local_res8);
      if ((cVar1 == '\x01') && (*puVar3 != 0)) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      }
      else {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xffffffdf;
      }
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"NcqDisabled",1,4,puVar3,local_res8);
      if ((cVar1 == '\x01') && (*puVar3 != 0)) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x40;
      }
      else {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xffffffbf;
      }
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"DisableTrim",1,4,puVar3,local_res8);
      if ((cVar1 == '\x01') && (*puVar3 != 0)) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x80;
      }
      else {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xffffff7f;
      }
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"EnableDEVSLP",1,4,puVar3,local_res8);
      if (cVar1 == '\x01') {
        *(uint *)(param_1 + 0x38) =
             -(uint)(*puVar3 != 0) & 0x100 | *(uint *)(param_1 + 0x38) & 0xfffffeff;
      }
      else {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x100;
      }
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"NoD3Cold",1,4,puVar3,local_res8);
      if ((cVar1 == '\x01') && (*puVar3 != 0)) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
      }
      else {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xfffffdff;
      }
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"DETDetectionTime",1,4,puVar3,local_res8);
      if ((cVar1 != '\x01') || (uVar2 = *puVar3, 0x7b2 < uVar2 - 0x1e)) {
        uVar2 = 0;
      }
      *(uint *)(param_1 + 0x3c) = uVar2;
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"PortStartTimeout",1,4,puVar3,local_res8);
      if ((cVar1 != '\x01') || (uVar2 = *puVar3, uVar2 == 0)) {
        uVar2 = 0;
      }
      *(uint *)(param_1 + 0x40) = uVar2;
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"ForceGenxSpeed",1,4,puVar3,local_res8);
      if ((cVar1 == '\x01') && (*puVar3 - 1 < 3)) {
        *(uint *)(param_1 + 0x38) =
             (*puVar3 << 0xc ^ *(uint *)(param_1 + 0x38)) & 0xf000 ^ *(uint *)(param_1 + 0x38);
      }
      else {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xffff0fff;
      }
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"AllowDeviceHybridInfo",1,4,puVar3,local_res8);
      if ((cVar1 == '\x01') && (*puVar3 != 0)) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x400;
      }
      else {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xfffffbff;
      }
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"MaxIoTransferSize",1,4,puVar3,local_res8);
      if ((cVar1 != '\x01') || (uVar2 = *puVar3, 0x37f < uVar2 - 0x81)) {
        uVar2 = 0;
      }
      *(uint *)(param_1 + 0x48) = uVar2;
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"ForceClearReservedSlotInUseFlag",1,4,puVar3,local_res8);
      if ((cVar1 == '\x01') && (*puVar3 != 0)) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x40000;
      }
      else {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xfffbffff;
      }
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"DETDetectionTimeForRecovery",1,4,puVar3,local_res8);
      if ((cVar1 != '\x01') || (uVar2 = *puVar3, 0x7b2 < uVar2 - 0x1e)) {
        uVar2 = 0;
      }
      *(uint *)(param_1 + 0x54) = uVar2;
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"FastFailIOForStuckDevice",1,4,puVar3,local_res8);
      if ((cVar1 == '\x01') && (*puVar3 != 0)) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x80000;
      }
      else {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xfff7ffff;
      }
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead
                        (param_1,"DeviceResetToleranceCountForFastFailIO",1,4,puVar3,local_res8);
      if (cVar1 == '\x01') {
        uVar2 = *puVar3;
        if (uVar2 < 6) {
          uVar2 = 5;
        }
      }
      else {
        uVar2 = 0xffffffff;
      }
      *(uint *)(param_1 + 0x58) = uVar2;
      local_res8[0] = 4;
      *puVar3 = 0;
      cVar1 = StorPortRegistryRead(param_1,"UseDumpPointers",1,4,puVar3,local_res8);
      if ((cVar1 == '\x01') && (*puVar3 == 0)) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xffefffff;
      }
      else {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x100000;
      }
    }
    StorPortFreeRegistryBuffer(param_1,puVar3);
  }
  return;
}



===== IsNCQWriteCommand @ 14001bfc8 =====

short IsNCQWriteCommand(longlong param_1)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  
  uVar2 = *(ushort *)(param_1 + 0x1100);
  bVar3 = (byte)(uVar2 >> 8);
  if (uVar2 == 0x400) {
    cVar1 = *(char *)(param_1 + 0x110a);
  }
  else {
    if ((uVar2 >> 8 & 1) == 0) {
      return (ushort)bVar3 << 8;
    }
    cVar1 = *(char *)(param_1 + 0x110e);
  }
  return CONCAT11(bVar3,cVar1 == 'a');
}



===== IsThereIoOutstandingInDevice @ 14001c000 =====

bool IsThereIoOutstandingInDevice(longlong param_1)

{
  if (((*(int *)(param_1 + 0x2dc) == 0) && (*(int *)(param_1 + 0x2e4) == 0)) &&
     (*(int *)(param_1 + 0x2e8) == 0)) {
    return *(int *)(param_1 + 0x2ec) != 0;
  }
  return true;
}



===== ReadMultiSzRegistryValueAndCompareId @ 14001c030 =====

char ReadMultiSzRegistryValueAndCompareId
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
               uint *param_5,uint *param_6,longlong param_7,uint param_8,uint *param_9)

{
  uint uVar1;
  short *psVar2;
  char cVar3;
  int iVar4;
  void *_Dst;
  int iVar5;
  uint uVar6;
  short *psVar7;
  short *_Dst_00;
  
  cVar3 = StorPortRegistryRead(param_1,param_2,1,7,*param_4,param_6);
  if (cVar3 == '\0') {
    if (*param_6 <= *param_5) {
      return '\0';
    }
    StorPortFreeRegistryBuffer(param_1,*param_4);
    *param_5 = *param_6;
    _Dst = (void *)StorPortAllocateRegistryBuffer(param_1);
    *param_4 = _Dst;
    if (_Dst == (void *)0x0) {
      return '\0';
    }
    uVar1 = *param_5;
    if (*param_6 < uVar1) {
      StorPortFreeRegistryBuffer(param_1,_Dst);
      *param_4 = 0;
      return '\0';
    }
    if (uVar1 != 0) {
      memset(_Dst,0,(ulonglong)uVar1);
    }
    cVar3 = StorPortRegistryRead(param_1,param_2,1,7,_Dst,param_6);
  }
  if (cVar3 != '\x01') {
    return '\0';
  }
  if (*param_6 < 2) {
    return '\0';
  }
  if (*param_5 < 2) {
    return '\0';
  }
  psVar2 = (short *)*param_4;
  if (((char)*psVar2 == '\0') && (*(char *)((longlong)psVar2 + 1) == '\0')) {
    return '\0';
  }
  iVar5 = 0;
  do {
    iVar4 = *param_5 - iVar5;
    iVar5 = iVar5 + 1;
    *(undefined1 *)((ulonglong)(iVar4 - 1) + (longlong)psVar2) = 0;
  } while (iVar5 < 2);
  if ((psVar2 != (short *)0x0) && (uVar1 = *param_6, 3 < uVar1)) {
    uVar6 = 0;
    psVar7 = psVar2;
    _Dst_00 = psVar2;
    if (uVar1 >> 1 != 1) {
      do {
        if ((*psVar7 == 0) && (psVar7[1] == 0)) break;
        uVar6 = uVar6 + 1;
        *(char *)_Dst_00 = (char)*psVar7;
        psVar7 = psVar7 + 1;
        _Dst_00 = (short *)((longlong)_Dst_00 + 1);
      } while (uVar6 < (uVar1 >> 1) - 1);
      if (uVar1 <= uVar6) goto LAB_14001c1ba;
    }
    if (uVar1 - uVar6 != 0) {
      memset(_Dst_00,0,(ulonglong)(uVar1 - uVar6));
    }
  }
LAB_14001c1ba:
  cVar3 = CompareId(param_7,param_8,(char *)psVar2,*param_6,param_9);
  return cVar3;
}



===== StringToULONG @ 14001c20c =====

undefined8 StringToULONG(char *param_1,uint *param_2)

{
  uint uVar1;
  ulonglong in_RAX;
  undefined1 uVar2;
  uint uVar3;
  char cVar4;
  undefined7 in_register_00000091;
  
  uVar3 = 0;
  uVar2 = 1;
  if ((param_1 == (char *)0x0) || (param_2 == (uint *)0x0)) {
    return in_RAX & 0xffffffffffffff00;
  }
  cVar4 = *param_1;
  do {
    if (cVar4 == '\0') {
LAB_14001c25b:
      *param_2 = uVar3;
      goto LAB_14001c25e;
    }
    uVar1 = (int)CONCAT71(in_register_00000091,cVar4) - 0x30;
    in_RAX = (ulonglong)uVar1;
    if (9 < (byte)uVar1) break;
    param_1 = param_1 + 1;
    uVar1 = (uint)cVar4;
    in_RAX = (ulonglong)uVar1;
    cVar4 = *param_1;
    uVar3 = uVar1 + (uVar3 * 5 + -0x18) * 2;
    if (cVar4 == '\0') goto LAB_14001c25b;
  } while (uVar3 < 0x1999999a);
  uVar2 = 0;
LAB_14001c25e:
  return CONCAT71((int7)(in_RAX >> 8),uVar2);
}



===== UlongToHex @ 14001c270 =====

void UlongToHex(longlong param_1,uint param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = (longlong)(param_3 + -1);
  if (-1 < param_3 + -1) {
    do {
      uVar1 = param_2 & 0xf;
      param_2 = param_2 >> 4;
      *(char *)(lVar2 + param_1) = "0123456789ABCDEF"[uVar1];
      lVar2 = lVar2 + -1;
    } while (-1 < lVar2);
  }
  return;
}



===== GetSlotToActivate @ 14001c2a0 =====

uint GetSlotToActivate(longlong *param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  
  uVar6 = *(uint *)((longlong)param_1 + 0x2dc);
  bVar2 = 0;
  uVar4 = 0;
  if (uVar6 != 0) {
    uVar6 = uVar6 - (uVar6 >> 1 & 0x55555555);
    uVar6 = (uVar6 >> 2 & 0x33333333) + (uVar6 & 0x33333333);
    bVar2 = (byte)(((uVar6 >> 4) + uVar6 & 0xf0f0f0f) * 0x1010101 >> 0x18);
  }
  if (*(byte *)((longlong)param_1 + 0x1e) <= bVar2) {
    return 0;
  }
  cVar5 = *(byte *)((longlong)param_1 + 0x1e) - bVar2;
  uVar6 = param_2 - (param_2 >> 1 & 0x55555555);
  uVar6 = (uVar6 >> 2 & 0x33333333) + (uVar6 & 0x33333333);
  uVar6 = ((uVar6 >> 4) + uVar6 & 0xf0f0f0f) * 0x1010101 >> 0x18;
  for (bVar2 = *(byte *)((longlong)param_1 + 0x276);
      bVar2 <= ((byte)((uint)*(undefined4 *)(*param_1 + 0x1a8) >> 8) & 0x1f); bVar2 = bVar2 + 1) {
    uVar1 = 1 << (bVar2 & 0x1f);
    if ((param_2 & uVar1) != 0) {
      uVar4 = uVar4 | uVar1;
      bVar3 = (char)uVar6 - 1;
      uVar6 = (uint)bVar3;
      cVar5 = cVar5 + -1;
      if ((cVar5 == '\0') || (bVar3 == 0)) goto LAB_14001c39d;
    }
  }
  bVar2 = 1;
  do {
    if (*(byte *)((longlong)param_1 + 0x276) < bVar2) {
      return uVar4;
    }
    uVar1 = 1 << (bVar2 & 0x1f);
    if ((param_2 & uVar1) != 0) {
      uVar4 = uVar4 | uVar1;
      bVar3 = (char)uVar6 - 1;
      uVar6 = (uint)bVar3;
      cVar5 = cVar5 + -1;
      if ((cVar5 == '\0') || (bVar3 == 0)) {
LAB_14001c39d:
        *(byte *)((longlong)param_1 + 0x276) = bVar2;
        return uVar4;
      }
    }
    bVar2 = bVar2 + 1;
  } while( true );
}



===== AdapterProcessIOCTL @ 14001c3bc =====

undefined8 AdapterProcessIOCTL(undefined4 *param_1,longlong param_2)

{
  char cVar1;
  undefined8 in_RAX;
  undefined7 extraout_var;
  undefined1 uVar2;
  longlong lVar3;
  
  uVar2 = 0;
  if (*(char *)(param_2 + 2) == '(') {
    lVar3 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
  }
  if (*(int *)(lVar3 + 0x10) == 0x2d1400) {
    cVar1 = CompareId(0x14002b2e0,8,(char *)(lVar3 + 4),8,(uint *)0x0);
    in_RAX = CONCAT71(extraout_var,cVar1);
    if (cVar1 != '\0') {
      in_RAX = QueryPhysicalTopologyIoctlProcess(param_1,param_2);
      uVar2 = 1;
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),uVar2);
}



===== AhciSetSenseData @ 14001c438 =====

void AhciSetSenseData(longlong param_1,undefined1 param_2,ulonglong param_3,undefined1 param_4,
                     undefined1 param_5)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  void *local_res8;
  byte local_res10 [8];
  undefined1 local_28 [7];
  undefined1 uStack_21;
  longlong lStack_20;
  undefined2 local_18;
  
  *(undefined1 *)(param_1 + 3) = param_2;
  local_res8 = (void *)0x0;
  local_18 = 0;
  local_res10[0] = 0;
  lStack_20 = (ulonglong)CONCAT11(param_5,param_4) << 0x20;
  _local_28 = CONCAT17(10,CONCAT43(0,CONCAT12((char)(param_3 & 0xffffffffffffff0f),0xf0)));
  RequestGetSrbScsiData(param_1,(uint *)0x0,param_3 & 0xffffffffffffff0f,&local_res8,local_res10);
  if ((local_res8 != (void *)0x0) && (local_res10[0] != 0)) {
    uVar5 = 0x12;
    if (local_res10[0] < 0x13) {
      uVar5 = (uint)local_res10[0];
    }
    memcpy(local_res8,local_28,(ulonglong)uVar5);
    *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x80;
    if (*(char *)(param_1 + 2) == '(') {
      bVar3 = false;
      if ((*(int *)(param_1 + 0x14) == 0) && (uVar6 = 0, *(int *)(param_1 + 0x38) != 0)) {
        do {
          uVar5 = *(uint *)(param_1 + 0x78 + uVar6 * 4);
          if ((0x7f < uVar5) && (uVar1 = *(uint *)(param_1 + 0x10), uVar5 < uVar1)) {
            uVar4 = (ulonglong)uVar5;
            iVar2 = *(int *)((ulonglong)uVar5 + param_1);
            if (iVar2 == 0x40) {
LAB_14001c50d:
              if (uVar4 + 0x28 <= (ulonglong)uVar1) {
                *(undefined1 *)(uVar4 + 8 + param_1) = 2;
                return;
              }
            }
            else if (iVar2 == 0x41) {
              if (uVar4 + 0x38 <= (ulonglong)uVar1) {
                bVar3 = true;
                *(undefined1 *)(uVar4 + 8 + param_1) = 2;
              }
            }
            else if (iVar2 == 0x42) goto LAB_14001c50d;
            if (bVar3) {
              return;
            }
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(uint *)(param_1 + 0x38));
      }
    }
    else {
      *(undefined1 *)(param_1 + 4) = 2;
    }
  }
  return;
}



===== AtaCloseZoneRequest @ 14001c558 =====

undefined8 AtaCloseZoneRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined7 uVar9;
  
  uVar8 = (undefined1)param_3;
  uVar9 = (undefined7)((ulonglong)param_3 >> 8);
  uVar6 = GetSrbExtension(param_2);
  if (*(int *)(param_1 + 0x18) - 3U < 2) {
    *(uint *)(uVar6 + 0x1104) = *(uint *)(uVar6 + 0x1104) | 8;
    *(undefined2 *)(uVar6 + 0x1100) = 0x400;
    *(byte *)(uVar6 + 0x110f) = *(byte *)(uVar6 + 0x110f) | 0x40;
    *(undefined2 *)(uVar6 + 0x110a) = 0x19f;
    if ((*(byte *)(CONCAT71(uVar9,uVar8) + 0xe) & 1) != 0) {
      *(byte *)(uVar6 + 0x1113) = *(byte *)(uVar6 + 0x1113) | 1;
    }
    uVar1 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 4);
    uVar2 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 5);
    uVar3 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 6);
    uVar4 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 7);
    uVar5 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 8);
    *(undefined1 *)(uVar6 + 0x110c) = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 9);
    *(undefined1 *)(uVar6 + 0x110d) = uVar5;
    *(undefined1 *)(uVar6 + 0x110e) = uVar4;
    *(undefined1 *)(uVar6 + 0x1110) = uVar3;
    *(undefined1 *)(uVar6 + 0x1111) = uVar2;
    uVar7 = 0;
    *(undefined1 *)(uVar6 + 0x1112) = uVar1;
  }
  else {
    AhciSetSenseData(param_2,6,CONCAT71(uVar9,5),0x24,0);
    uVar7 = 0xc1000007;
  }
  return uVar7;
}



===== AtaFinishZoneRequest @ 14001c66c =====

undefined8 AtaFinishZoneRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined7 uVar9;
  
  uVar8 = (undefined1)param_3;
  uVar9 = (undefined7)((ulonglong)param_3 >> 8);
  uVar6 = GetSrbExtension(param_2);
  if (*(int *)(param_1 + 0x18) - 3U < 2) {
    *(uint *)(uVar6 + 0x1104) = *(uint *)(uVar6 + 0x1104) | 8;
    *(undefined2 *)(uVar6 + 0x1100) = 0x400;
    *(byte *)(uVar6 + 0x110f) = *(byte *)(uVar6 + 0x110f) | 0x40;
    *(undefined2 *)(uVar6 + 0x110a) = 0x29f;
    if ((*(byte *)(CONCAT71(uVar9,uVar8) + 0xe) & 1) != 0) {
      *(byte *)(uVar6 + 0x1113) = *(byte *)(uVar6 + 0x1113) | 1;
    }
    uVar1 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 4);
    uVar2 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 5);
    uVar3 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 6);
    uVar4 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 7);
    uVar5 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 8);
    *(undefined1 *)(uVar6 + 0x110c) = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 9);
    *(undefined1 *)(uVar6 + 0x110d) = uVar5;
    *(undefined1 *)(uVar6 + 0x110e) = uVar4;
    *(undefined1 *)(uVar6 + 0x1110) = uVar3;
    *(undefined1 *)(uVar6 + 0x1111) = uVar2;
    uVar7 = 0;
    *(undefined1 *)(uVar6 + 0x1112) = uVar1;
  }
  else {
    AhciSetSenseData(param_2,6,CONCAT71(uVar9,5),0x24,0);
    uVar7 = 0xc1000007;
  }
  return uVar7;
}



===== AtaFirmwareActivateCompletion @ 14001c780 =====

void AtaFirmwareActivateCompletion(longlong *param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_2 + 3) == '\x01') {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
    if ((*(uint *)(param_1 + 0x4b) & 0x800) != 0) {
      AhciPortIssueInitCommands(param_1);
      ActivateQueue(param_1,'\0');
    }
  }
  else {
    lVar2 = param_2;
    uVar1 = GetSrbExtension(param_2);
    if (*(char *)(lVar2 + 2) == '(') {
      lVar2 = *(longlong *)(lVar2 + 0x40);
    }
    else {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    UpdateFirmwareIoctlReturnCode(param_2);
    if (lVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(lVar2 + 0x14);
    }
    StorPortExtendedFunction
              (0x57,*param_1,param_1 + 1,0,0x13,L"Firmware Activate Completion",1,2,0,param_2,
               L"SrbStatus",*(undefined1 *)(param_2 + 3),L"ReturnCode",uVar3,L"FeaturesReg",
               *(undefined1 *)(uVar1 + 0x1108),L"SectorCountReg",*(undefined1 *)(uVar1 + 0x1109),
               L"DriveHeadReg",*(undefined1 *)(uVar1 + 0x110d),L"CommandReg",
               *(undefined1 *)(uVar1 + 0x110e),0,0,0,0);
  }
  return;
}



===== AtaFirmwareDownloadCompletion @ 14001c920 =====

void AtaFirmwareDownloadCompletion(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_2 + 3) != '\x01') {
    lVar2 = param_2;
    uVar1 = GetSrbExtension(param_2);
    if (*(char *)(lVar2 + 2) == '(') {
      lVar2 = *(longlong *)(lVar2 + 0x40);
    }
    else {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    UpdateFirmwareIoctlReturnCode(param_2);
    if (lVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(lVar2 + 0x14);
    }
    StorPortExtendedFunction
              (0x57,*param_1,param_1 + 1,0,0x11,L"Firmware Download Completion",1,2,0,param_2,
               L"SrbStatus",*(undefined1 *)(param_2 + 3),L"ReturnCode",uVar3,L"FeaturesReg",
               *(undefined1 *)(uVar1 + 0x1108),L"SectorCountReg",*(undefined1 *)(uVar1 + 0x1109),
               L"DriveHeadReg",*(undefined1 *)(uVar1 + 0x110d),L"CommandReg",
               *(undefined1 *)(uVar1 + 0x110e),0,0,0,0);
  }
  return;
}



===== AtaGenerateInquiryData @ 14001ca90 =====

void AtaGenerateInquiryData(longlong param_1,byte *param_2)

{
  byte *pbVar1;
  char cVar2;
  uint uVar3;
  size_t _Size;
  uint uVar4;
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  param_2[0x12] = 0;
  param_2[0x13] = 0;
  param_2[0x14] = 0;
  param_2[0x15] = 0;
  param_2[0x16] = 0;
  param_2[0x17] = 0;
  param_2[0x18] = 0;
  param_2[0x19] = 0;
  param_2[0x1a] = 0;
  param_2[0x1b] = 0;
  param_2[0x1c] = 0;
  param_2[0x1d] = 0;
  param_2[0x1e] = 0;
  param_2[0x1f] = 0;
  param_2[0x20] = 0;
  param_2[0x21] = 0;
  param_2[0x22] = 0;
  param_2[0x23] = 0;
  param_2[0x24] = 0;
  param_2[0x25] = 0;
  param_2[0x26] = 0;
  param_2[0x27] = 0;
  param_2[0x28] = 0;
  param_2[0x29] = 0;
  param_2[0x2a] = 0;
  param_2[0x2b] = 0;
  param_2[0x2c] = 0;
  param_2[0x2d] = 0;
  param_2[0x2e] = 0;
  param_2[0x2f] = 0;
  param_2[0x30] = 0;
  param_2[0x31] = 0;
  param_2[0x32] = 0;
  param_2[0x33] = 0;
  param_2[0x34] = 0;
  param_2[0x35] = 0;
  param_2[0x36] = 0;
  param_2[0x37] = 0;
  param_2[0x38] = 0;
  param_2[0x39] = 0;
  param_2[0x3a] = 0;
  param_2[0x3b] = 0;
  *param_2 = *(byte *)(param_1 + 0x1c) & 0x1f;
  cVar2 = *(char *)(param_1 + 0x20);
  param_2[4] = 0x37;
  param_2[1] = cVar2 << 7 | param_2[1] & 0x7f;
  uVar3 = 8;
  param_2[7] = param_2[7] | 2;
  param_2[3] = param_2[3] & 0xf2 | 2;
  do {
    if (*(char *)((ulonglong)(uVar3 - 1) + 0x40 + param_1) == ' ') break;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  pbVar1 = param_2 + 8;
  uVar4 = 0x29;
  if (uVar3 < 0x29) {
    uVar4 = uVar3;
  }
  pbVar1[0] = 0x20;
  pbVar1[1] = 0x20;
  pbVar1[2] = 0x20;
  pbVar1[3] = 0x20;
  pbVar1[4] = 0x20;
  pbVar1[5] = 0x20;
  pbVar1[6] = 0x20;
  pbVar1[7] = 0x20;
  if (uVar4 - 1 < 8) {
    memcpy(pbVar1,(void *)(param_1 + 0x40),(ulonglong)uVar4);
  }
  _Size = 0x10;
  if (0x29 - (ulonglong)uVar4 < 0x11) {
    _Size = (size_t)(0x29 - uVar4);
  }
  pbVar1 = param_2 + 0x10;
  pbVar1[0] = 0x20;
  pbVar1[1] = 0x20;
  pbVar1[2] = 0x20;
  pbVar1[3] = 0x20;
  pbVar1[4] = 0x20;
  pbVar1[5] = 0x20;
  pbVar1[6] = 0x20;
  pbVar1[7] = 0x20;
  param_2[0x18] = 0x20;
  param_2[0x19] = 0x20;
  param_2[0x1a] = 0x20;
  param_2[0x1b] = 0x20;
  param_2[0x1c] = 0x20;
  param_2[0x1d] = 0x20;
  param_2[0x1e] = 0x20;
  param_2[0x1f] = 0x20;
  memcpy(pbVar1,(void *)(param_1 + 0x40 + (ulonglong)uVar4),_Size);
  param_2[0x20] = 0x20;
  param_2[0x21] = 0x20;
  param_2[0x22] = 0x20;
  param_2[0x23] = 0x20;
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x69);
  if (((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0x60) & 1) != 0) &&
     (*(char *)(*(longlong *)(param_1 + 0xc0) + 0x8a) < '\0')) {
    param_2[0x3a] = 0xff;
    param_2[0x3b] = 0xc0;
  }
  return;
}



===== AtaGetDeviceCurrentInternalStatusDataHeader @ 14001cbb4 =====

undefined8 AtaGetDeviceCurrentInternalStatusDataHeader(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar3 = *(longlong *)(param_2 + 0x40);
    uVar1 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
    uVar1 = *(uint *)(param_2 + 0x10);
  }
  if ((lVar3 == 0) || (uVar1 < 0x30)) {
    *(undefined1 *)(param_2 + 3) = 0x15;
    uVar2 = 0xc1000006;
  }
  else {
    *(undefined1 *)(param_1 + 0x1f0) = 0xff;
    IssueReadLogExtCommand
              (param_1,param_2,0,0,1,0,(undefined8 *)(param_1 + 0x1e8),
               *(undefined8 *)(param_1 + 0x1e0),
               AtaGetDeviceCurrentInternalStatusDataHeaderCompletion);
    uVar2 = 0;
  }
  return uVar2;
}



===== AtaGetDeviceCurrentInternalStatusDataHeaderCompletion @ 14001cc40 =====

void AtaGetDeviceCurrentInternalStatusDataHeaderCompletion(undefined8 *param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  short *psVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  int iVar8;
  short sVar9;
  longlong lVar10;
  ushort uVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined8 in_stack_ffffffffffffff50;
  undefined4 uVar14;
  undefined8 in_stack_ffffffffffffff58;
  uint uVar15;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);
  uVar15 = (uint)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  lVar13 = param_2;
  uVar7 = GetSrbExtension(param_2);
  if (*(char *)(param_2 + 3) == '\x01') {
    sVar9 = CONCAT11(*(undefined1 *)(uVar7 + 0x1113),*(undefined1 *)(uVar7 + 0x110b));
    if (*(char *)(uVar7 + 0x110a) == '\0') {
      if ((sVar9 == 0) && (psVar4 = (short *)param_1[0x3c], *psVar4 == 1)) {
        *(short *)(param_1 + 0x8c7) = psVar4[0x24];
        *(short *)((longlong)param_1 + 0x463a) = psVar4[0x25];
        if ((psVar4[0x24] != 0) || (psVar4[0x25] != 0)) {
          IssueReadLogExtCommand
                    ((longlong)param_1,lVar13,0x24,0,1,1,param_1 + 0x3d,psVar4,
                     AtaGetDeviceCurrentInternalStatusDataHeaderCompletion);
          return;
        }
        *(undefined1 *)(lVar13 + 3) = 6;
        goto LAB_14001cea7;
      }
    }
    else if ((*(char *)(uVar7 + 0x110a) == '$') && (sVar9 == 0)) {
      if (*(char *)(lVar13 + 2) == '(') {
        puVar12 = *(undefined8 **)(lVar13 + 0x40);
      }
      else {
        puVar12 = *(undefined8 **)(lVar13 + 0x18);
      }
      uVar6 = RequestGetDataTransferLength(lVar13);
      *(undefined1 *)(param_1 + 0x3e) = 0x24;
      uVar11 = 0;
      lVar10 = 0;
      *puVar12 = 0;
      puVar12[1] = 0;
      puVar12[2] = 0;
      puVar12[3] = 0;
      puVar12[4] = 0;
      if (0x1ff < uVar6) {
        lVar5 = param_1[0x3c];
        *(byte *)((longlong)puVar12 + 9) = *(byte *)((longlong)puVar12 + 9) | 6;
        *puVar12 = 0x2020202020415441;
        uVar2 = *(ushort *)(lVar5 + 0xc);
        if (uVar2 != 0) {
          uVar3 = *(ushort *)(param_1 + 0x8c7);
          *(undefined2 *)(puVar12 + 4) = 0x110;
          uVar11 = 8;
          lVar10 = 1;
          if (uVar3 <= uVar2) {
            uVar2 = uVar3;
          }
          iVar8 = (uVar2 + 1) * 0x200;
          *(byte *)((longlong)puVar12 + 0x22) = *(byte *)((longlong)puVar12 + 0x22) & 0xf3 | 3;
          *(char *)((longlong)puVar12 + 0x26) = (char)((uint)iVar8 >> 8);
          *(undefined1 *)((longlong)puVar12 + 0x27) = 0;
          *(char *)((longlong)puVar12 + 0x25) = (char)((uint)iVar8 >> 0x10);
          *(char *)((longlong)puVar12 + 0x24) = (char)((uint)iVar8 >> 0x18);
          *(undefined1 *)((longlong)param_1 + 0x463c) = *(undefined1 *)(puVar12 + 4);
        }
        if ((*(char *)(lVar5 + 0x17e) != '\0') && (*(ushort *)((longlong)param_1 + 0x463a) != 0)) {
          iVar8 = (*(ushort *)((longlong)param_1 + 0x463a) + 1) * 0x200;
          uVar11 = uVar11 + 8;
          bVar1 = *(byte *)((longlong)puVar12 + lVar10 * 8 + 0x22);
          *(char *)(puVar12 + lVar10 + 4) = (char)lVar10 + '\x10';
          *(undefined1 *)((longlong)puVar12 + lVar10 * 8 + 0x21) = 2;
          *(byte *)((longlong)puVar12 + lVar10 * 8 + 0x22) = bVar1 & 0xf2 | 2;
          *(char *)((longlong)puVar12 + lVar10 * 8 + 0x26) = (char)((uint)iVar8 >> 8);
          *(undefined1 *)((longlong)puVar12 + lVar10 * 8 + 0x27) = 0;
          *(char *)((longlong)puVar12 + lVar10 * 8 + 0x25) = (char)((uint)iVar8 >> 0x10);
          *(char *)((longlong)puVar12 + lVar10 * 8 + 0x24) = (char)((uint)iVar8 >> 0x18);
          *(undefined1 *)((longlong)param_1 + 0x463d) = *(undefined1 *)(puVar12 + lVar10 + 4);
        }
        *(char *)((longlong)puVar12 + 0x1f) = (char)uVar11;
        *(undefined1 *)((longlong)puVar12 + 0x1e) = 0;
        if (*(char *)(lVar13 + 2) == '(') {
          *(uint *)(lVar13 + 0x3c) = uVar11 + 0x20;
          return;
        }
        *(uint *)(lVar13 + 0x10) = uVar11 + 0x20;
        return;
      }
    }
    *(undefined1 *)(lVar13 + 3) = 4;
  }
LAB_14001cea7:
  *(undefined1 *)(param_1 + 0x3e) = 0xff;
  StorPortExtendedFunction
            (0x57,*param_1,param_1 + 1,0,0x16,L"Internal Status Data Header",1,CONCAT44(uVar14,2),
             (ulonglong)uVar15 << 0x20,lVar13,L"SrbStatus",*(undefined1 *)(lVar13 + 3),L"ErrorReg",
             *(undefined1 *)(uVar7 + 0x1108),L"StatusReg",*(undefined1 *)(uVar7 + 0x110e),0,0,0,0,0,
             0,0,0,0,0);
  return;
}



===== AtaGetDeviceInternalStatusData @ 14001cfb0 =====

/* WARNING: Removing unreachable block (ram,0x00014001d132) */
/* WARNING: Removing unreachable block (ram,0x00014001d13b) */
/* WARNING: Removing unreachable block (ram,0x00014001d13e) */

undefined8
AtaGetDeviceInternalStatusData(longlong *param_1,longlong param_2,longlong param_3,char param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint3 uVar9;
  ushort uVar10;
  int iVar11;
  void *_Dst;
  longlong lVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  uint uVar15;
  byte bVar16;
  void *pvVar17;
  longlong lVar18;
  uint uVar19;
  uint local_res20;
  void *local_50;
  longlong local_48 [2];
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar18 = *(longlong *)(param_2 + 0x40);
    uVar19 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar18 = *(longlong *)(param_2 + 0x18);
    uVar19 = *(uint *)(param_2 + 0x10);
  }
  bVar16 = 0;
  local_50 = (void *)0x0;
  lVar12 = 0;
  local_48[0] = 0;
  pvVar17 = (void *)0x0;
  local_res20 = 0;
  if (param_4 == '\0') {
    uVar10 = *(ushort *)((longlong)param_1 + 0x463a);
  }
  else {
    uVar10 = *(ushort *)(param_1 + 0x8c7);
  }
  uVar15 = (uVar10 + 1) * 0x200;
  _Dst = (void *)GetSrbExtension(param_2);
  if ((lVar18 == 0) || (uVar19 < 0x200)) {
    *(undefined1 *)(param_2 + 3) = 0x15;
    uVar14 = 0xc1000006;
  }
  else {
    uVar9 = CONCAT21(CONCAT11(*(undefined1 *)(param_3 + 0xb),*(undefined1 *)(param_3 + 0xc)),
                     *(undefined1 *)(param_3 + 0xd));
    local_res20 = (uint)uVar9;
    uVar1 = *(undefined1 *)(param_3 + 2);
    uVar2 = *(undefined1 *)(param_3 + 3);
    uVar3 = *(undefined1 *)(param_3 + 4);
    uVar4 = *(undefined1 *)(param_3 + 5);
    uVar5 = *(undefined1 *)(param_3 + 6);
    uVar6 = *(undefined1 *)(param_3 + 7);
    uVar7 = *(undefined1 *)(param_3 + 8);
    uVar8 = *(undefined1 *)(param_3 + 9);
    uVar10 = CONCAT11(uVar7,uVar8);
    uVar19 = CONCAT13(uVar5,CONCAT12(uVar6,uVar10));
    local_res20 = local_res20 * 0x200;
    if ((uVar15 <= uVar19) || ((uVar10 & 0x1ff) != 0)) {
      *(undefined1 *)(param_2 + 3) = 6;
      return 0xc1000007;
    }
    if (uVar15 < uVar19 + local_res20) {
      local_res20 = uVar15 - uVar19;
    }
    if (bVar16 < *(byte *)(*param_1 + 0x18c)) {
      lVar12 = StorPortGetPhysicalAddress();
      bVar16 = 0;
      *(undefined1 *)(param_2 + 3) = 4;
      uVar14 = 0xc1000003;
      pvVar17 = local_50;
      local_48[0] = lVar12;
    }
    else {
      iVar11 = AhciAllocateDmaBuffer(*param_1,local_res20,&local_50,local_48);
      bVar16 = 0;
      if ((iVar11 == 0) && (local_50 != (void *)0x0)) {
        if (local_res20 != 0) {
          memset(local_50,0,(ulonglong)local_res20);
        }
        memset(_Dst,0,0x29a0);
        *(uint *)((longlong)_Dst + 0x1130) = local_res20;
        uVar13 = CONCAT17(uVar1,CONCAT16(uVar2,CONCAT15(uVar3,CONCAT14(uVar4,CONCAT13(uVar5,CONCAT12
                                                  (uVar6,CONCAT11(uVar7,uVar8))))))) / 0x200;
        *(ulonglong *)((longlong)_Dst + 0x2970) = uVar13 & 0xffffffff;
        local_res20._0_2_ = (ushort)uVar9;
        IssueReadLogExtCommand
                  ((longlong)param_1,param_2,'%' - (param_4 != '\0'),(short)uVar13,
                   (ushort)local_res20,0,local_48,local_50,AtaGetDeviceInternalStatusDataCompletion)
        ;
        return 0;
      }
      *(undefined1 *)(param_2 + 3) = 4;
      uVar14 = 0xc1000003;
      lVar12 = local_48[0];
      pvVar17 = local_50;
    }
  }
  if ((pvVar17 != (void *)0x0) && (*(byte *)(*param_1 + 0x18c) <= bVar16)) {
    StorPortExtendedFunction(0x53,*param_1,pvVar17,local_res20,1,lVar12);
  }
  return uVar14;
}



===== AtaGetDeviceInternalStatusDataCompletion @ 14001d250 =====

void AtaGetDeviceInternalStatusDataCompletion(longlong *param_1,longlong param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  void *_Dst;
  longlong lVar6;
  void *_Src;
  uint uVar7;
  
  lVar6 = param_2;
  uVar5 = GetSrbExtension(param_2);
  iVar2 = *(int *)(uVar5 + 0x2970);
  if (*(char *)(lVar6 + 3) != '\x01') goto LAB_14001d562;
  if (*(char *)(lVar6 + 2) == '(') {
    _Dst = *(void **)(lVar6 + 0x40);
    uVar7 = *(uint *)(lVar6 + 0x3c);
  }
  else {
    _Dst = *(void **)(lVar6 + 0x18);
    uVar7 = *(uint *)(lVar6 + 0x10);
  }
  uVar4 = RequestGetDataTransferLength(param_2);
  *(undefined1 *)(param_1 + 0x3e) = *(undefined1 *)(uVar5 + 0x110a);
  if ((*(char *)(*param_1 + 0x18c) == '\0') && (uVar7 != 0)) {
    memset(_Dst,0,(ulonglong)uVar7);
  }
  _Src = *(void **)(uVar5 + 0x1120);
  if (iVar2 == 0) {
    if (uVar4 < 0x200) {
      *(undefined1 *)(param_1 + 0x3e) = 0xff;
      StorPortExtendedFunction
                (0x57,*param_1,param_1 + 1,0,0x17,L"Internal Status Data",1,2,0,param_2,L"SrbStatus"
                 ,*(undefined1 *)(param_2 + 3),L"ErrorReg",*(undefined1 *)(uVar5 + 0x1108),
                 L"StatusReg",*(undefined1 *)(uVar5 + 0x110e),0,0,0,0,0,0,0,0,0,0);
      goto LAB_14001d562;
    }
    uVar1 = *(undefined1 *)((longlong)_Src + 4);
    if (*(char *)(*param_1 + 0x18c) == '\0') {
      *(undefined1 *)((longlong)_Dst + 7) = uVar1;
      *(undefined1 *)((longlong)_Dst + 6) = *(undefined1 *)((longlong)_Src + 5);
      *(undefined1 *)((longlong)_Dst + 5) = *(undefined1 *)((longlong)_Src + 6);
      *(undefined1 *)((longlong)_Dst + 4) = *(undefined1 *)((longlong)_Src + 7);
      *(undefined1 *)((longlong)_Dst + 9) = *(undefined1 *)((longlong)_Src + 8);
      *(undefined1 *)((longlong)_Dst + 8) = *(undefined1 *)((longlong)_Src + 9);
      *(undefined1 *)((longlong)_Dst + 0xb) = *(undefined1 *)((longlong)_Src + 10);
      *(undefined1 *)((longlong)_Dst + 10) = *(undefined1 *)((longlong)_Src + 0xb);
      *(undefined1 *)((longlong)_Dst + 0xd) = *(undefined1 *)((longlong)_Src + 0xc);
      *(undefined1 *)((longlong)_Dst + 0xc) = *(undefined1 *)((longlong)_Src + 0xd);
      *(undefined1 *)((longlong)_Dst + 0x17e) = *(undefined1 *)((longlong)_Src + 0x17e);
      *(undefined1 *)((longlong)_Dst + 0x17f) = *(undefined1 *)((longlong)_Src + 0x17f);
      uVar3 = *(undefined8 *)((longlong)_Src + 0x188);
      *(undefined8 *)((longlong)_Dst + 0x180) = *(undefined8 *)((longlong)_Src + 0x180);
      *(undefined8 *)((longlong)_Dst + 0x188) = uVar3;
      uVar3 = *(undefined8 *)((longlong)_Src + 0x198);
      *(undefined8 *)((longlong)_Dst + 400) = *(undefined8 *)((longlong)_Src + 400);
      *(undefined8 *)((longlong)_Dst + 0x198) = uVar3;
      uVar3 = *(undefined8 *)((longlong)_Src + 0x1a8);
      *(undefined8 *)((longlong)_Dst + 0x1a0) = *(undefined8 *)((longlong)_Src + 0x1a0);
      *(undefined8 *)((longlong)_Dst + 0x1a8) = uVar3;
      uVar3 = *(undefined8 *)((longlong)_Src + 0x1b8);
      *(undefined8 *)((longlong)_Dst + 0x1b0) = *(undefined8 *)((longlong)_Src + 0x1b0);
      *(undefined8 *)((longlong)_Dst + 0x1b8) = uVar3;
      uVar3 = *(undefined8 *)((longlong)_Src + 0x1c8);
      *(undefined8 *)((longlong)_Dst + 0x1c0) = *(undefined8 *)((longlong)_Src + 0x1c0);
      *(undefined8 *)((longlong)_Dst + 0x1c8) = uVar3;
      uVar3 = *(undefined8 *)((longlong)_Src + 0x1d8);
      *(undefined8 *)((longlong)_Dst + 0x1d0) = *(undefined8 *)((longlong)_Src + 0x1d0);
      *(undefined8 *)((longlong)_Dst + 0x1d8) = uVar3;
      uVar3 = *(undefined8 *)((longlong)_Src + 0x1e8);
      *(undefined8 *)((longlong)_Dst + 0x1e0) = *(undefined8 *)((longlong)_Src + 0x1e0);
      *(undefined8 *)((longlong)_Dst + 0x1e8) = uVar3;
      uVar3 = *(undefined8 *)((longlong)_Src + 0x1f8);
      *(undefined8 *)((longlong)_Dst + 0x1f0) = *(undefined8 *)((longlong)_Src + 0x1f0);
      *(undefined8 *)((longlong)_Dst + 0x1f8) = uVar3;
    }
    else {
      *(undefined1 *)((longlong)_Src + 4) = *(undefined1 *)((longlong)_Src + 7);
      *(undefined1 *)((longlong)_Src + 7) = uVar1;
      uVar1 = *(undefined1 *)((longlong)_Src + 5);
      *(undefined1 *)((longlong)_Src + 5) = *(undefined1 *)((longlong)_Src + 6);
      *(undefined1 *)((longlong)_Src + 6) = uVar1;
      uVar1 = *(undefined1 *)((longlong)_Src + 9);
      *(undefined1 *)((longlong)_Src + 9) = *(undefined1 *)((longlong)_Src + 8);
      *(undefined1 *)((longlong)_Src + 8) = uVar1;
      uVar1 = *(undefined1 *)((longlong)_Src + 0xb);
      *(undefined1 *)((longlong)_Src + 0xb) = *(undefined1 *)((longlong)_Src + 10);
      *(undefined1 *)((longlong)_Src + 10) = uVar1;
      uVar1 = *(undefined1 *)((longlong)_Src + 0xd);
      *(undefined1 *)((longlong)_Src + 0xd) = *(undefined1 *)((longlong)_Src + 0xc);
      *(undefined1 *)((longlong)_Src + 0xc) = uVar1;
    }
    if (((0x200 < uVar4) && (uVar4 <= uVar7)) && (*(char *)(*param_1 + 0x18c) == '\0')) {
      _Src = (void *)((longlong)_Src + 0x200);
      _Dst = (void *)((longlong)_Dst + 0x200);
      uVar7 = uVar4 - 0x200;
      goto LAB_14001d54f;
    }
  }
  else if (((0x200 < uVar4) && (uVar4 <= uVar7)) && (*(char *)(*param_1 + 0x18c) == '\0')) {
    uVar7 = uVar4;
LAB_14001d54f:
    memcpy(_Dst,_Src,(ulonglong)uVar7);
  }
  if (*(char *)(param_2 + 2) == '(') {
    *(uint *)(param_2 + 0x3c) = uVar4;
  }
  else {
    *(uint *)(param_2 + 0x10) = uVar4;
  }
LAB_14001d562:
  if ((*(longlong *)(uVar5 + 0x1120) != 0) && (*(char *)(*param_1 + 0x18c) == '\0')) {
    StorPortExtendedFunction
              (0x53,*param_1,*(longlong *)(uVar5 + 0x1120),*(undefined4 *)(uVar5 + 0x1130),1,
               *(undefined8 *)(uVar5 + 0x1128));
    *(undefined8 *)(uVar5 + 0x1120) = 0;
  }
  return;
}



===== AtaGetPhysicalElementStatusCompletion @ 14001d5e0 =====

void AtaGetPhysicalElementStatusCompletion(undefined8 *param_1,longlong param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  uint uVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  
  lVar4 = param_2;
  uVar3 = GetSrbExtension(param_2);
  if (*(char *)(lVar4 + 3) == '\x01') {
    cVar7 = *(char *)(lVar4 + 2);
    if (cVar7 == '(') {
      uVar9 = *(uint *)(lVar4 + 0x3c);
    }
    else {
      uVar9 = *(uint *)(lVar4 + 0x10);
    }
    uVar2 = RequestGetDataTransferLength(param_2);
    puVar1 = *(undefined1 **)(uVar3 + 0x1120);
    if (cVar7 == '(') {
      puVar5 = *(undefined1 **)(param_2 + 0x40);
    }
    else {
      puVar5 = *(undefined1 **)(param_2 + 0x18);
    }
    uVar8 = 0x40;
    puVar5[3] = *puVar1;
    uVar6 = 0;
    puVar5[2] = puVar1[1];
    puVar5[1] = puVar1[2];
    *puVar5 = puVar1[3];
    puVar5[7] = puVar1[4];
    puVar5[6] = puVar1[5];
    puVar5[5] = puVar1[6];
    puVar5[4] = puVar1[7];
    puVar5[0xb] = puVar1[8];
    puVar5[10] = puVar1[9];
    puVar5[9] = puVar1[10];
    puVar5[8] = puVar1[0xb];
    if (*(int *)(puVar1 + 4) != 0) {
      do {
        if ((uVar9 < uVar8) || (uVar2 < uVar8)) break;
        uVar8 = uVar8 + 0x20;
        lVar4 = (ulonglong)uVar6 * 0x20;
        uVar6 = uVar6 + 1;
        puVar5[lVar4 + 0x2e] = puVar1[lVar4 + 0x2e];
        puVar5[lVar4 + 0x2f] = puVar1[lVar4 + 0x2f];
        puVar5[lVar4 + 0x27] = puVar1[lVar4 + 0x24];
        puVar5[lVar4 + 0x26] = puVar1[lVar4 + 0x25];
        puVar5[lVar4 + 0x25] = puVar1[lVar4 + 0x26];
        puVar5[lVar4 + 0x24] = puVar1[lVar4 + 0x27];
        puVar5[lVar4 + 0x37] = puVar1[lVar4 + 0x30];
        puVar5[lVar4 + 0x36] = puVar1[lVar4 + 0x31];
        puVar5[lVar4 + 0x35] = puVar1[lVar4 + 0x32];
        puVar5[lVar4 + 0x34] = puVar1[lVar4 + 0x33];
        puVar5[lVar4 + 0x33] = puVar1[lVar4 + 0x34];
        puVar5[lVar4 + 0x32] = puVar1[lVar4 + 0x35];
        puVar5[lVar4 + 0x31] = puVar1[lVar4 + 0x36];
        puVar5[lVar4 + 0x30] = puVar1[lVar4 + 0x37];
      } while (uVar6 < *(uint *)(puVar1 + 4));
    }
  }
  if (*(longlong *)(uVar3 + 0x1120) != 0) {
    StorPortExtendedFunction
              (0x53,*param_1,*(longlong *)(uVar3 + 0x1120),*(undefined8 *)(uVar3 + 0x2970),1,
               *(undefined8 *)(uVar3 + 0x1128));
    *(undefined8 *)(uVar3 + 0x1120) = 0;
  }
  if (*(char *)(param_2 + 3) != '\x01') {
    StorPortExtendedFunction
              (0x57,*param_1,param_1 + 1,0,0x14,L"Get Physical Element status",1,2,0,param_2,
               L"SrbStatus",*(char *)(param_2 + 3),L"ErrorReg",*(undefined1 *)(param_1[299] + 0x43),
               L"StatusReg",*(undefined1 *)(param_1[299] + 0x42),0,0,0,0,0,0,0,0,0,0);
  }
  return;
}



===== AtaGetPhysicalElementStatusRequest @ 14001d8b0 =====

undefined4 AtaGetPhysicalElementStatusRequest(longlong *param_1,longlong param_2,longlong param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 uVar9;
  longlong lVar10;
  int local_res10;
  undefined8 local_res20;
  void *local_38 [2];
  
  lVar5 = param_2;
  lVar10 = param_3;
  uVar4 = GetSrbExtension(param_2);
  if (*(char *)(lVar5 + 2) == '(') {
    lVar5 = *(longlong *)(lVar5 + 0x40);
    uVar7 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar5 = *(longlong *)(lVar5 + 0x18);
    uVar7 = *(uint *)(param_2 + 0x10);
  }
  uVar8 = 0;
  local_38[0] = (void *)0x0;
  local_res20 = 0;
  if ((lVar5 == 0) || (uVar7 < 0x40)) {
    uVar6 = 0xc1000006;
    uVar9 = 6;
  }
  else {
    *(uint *)(uVar4 + 0x1104) = *(uint *)(uVar4 + 0x1104) | 0x1a;
    *(code **)(uVar4 + 0x2968) = AtaGetPhysicalElementStatusCompletion;
    *(undefined2 *)(uVar4 + 0x1100) = 0x400;
    *(undefined2 *)(uVar4 + 0x110a) = 0x12;
    *(byte *)(uVar4 + 0x1113) = *(byte *)(lVar10 + 0xe) & 0xcf;
    local_res10 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar10 + 10),
                                             *(undefined1 *)(lVar10 + 0xb)),
                                    *(undefined1 *)(lVar10 + 0xc)),*(undefined1 *)(lVar10 + 0xd));
    uVar7 = local_res10 + 0x1ffU >> 9;
    uVar8 = uVar7 << 9;
    iVar3 = AhciAllocateDmaBuffer(*param_1,uVar8,local_38,&local_res20);
    if ((iVar3 == 0) && (local_38[0] != (void *)0x0)) {
      if (uVar7 != 0) {
        memset(local_38[0],0,(ulonglong)uVar8);
      }
      *(void **)(uVar4 + 0x1120) = local_38[0];
      *(undefined8 *)(uVar4 + 0x1128) = local_res20;
      *(undefined4 *)(uVar4 + 0x1140) = 1;
      *(uint *)(uVar4 + 0x1130) = uVar8;
      *(ulonglong *)(uVar4 + 0x2970) = (ulonglong)uVar8;
      *(undefined4 *)(uVar4 + 0x1150) = (undefined4)local_res20;
      *(undefined4 *)(uVar4 + 0x1154) = local_res20._4_4_;
      *(undefined4 **)(uVar4 + 0x1138) = (undefined4 *)(uVar4 + 0x1140);
      *(uint *)(uVar4 + 0x1158) = uVar8;
      *(char *)(uVar4 + 0x1114) = (char)uVar7;
      *(char *)(uVar4 + 0x1115) = (char)(uVar7 >> 8);
      uVar9 = *(undefined1 *)(param_3 + 6);
      uVar1 = *(undefined1 *)(param_3 + 7);
      uVar2 = *(undefined1 *)(param_3 + 8);
      *(undefined1 *)(uVar4 + 0x110c) = *(undefined1 *)(param_3 + 9);
      *(undefined1 *)(uVar4 + 0x110d) = uVar2;
      *(undefined1 *)(uVar4 + 0x1110) = uVar9;
      *(undefined1 *)(uVar4 + 0x110e) = uVar1;
      return 0;
    }
    uVar6 = 0xc1000003;
    uVar9 = 4;
  }
  *(undefined1 *)(param_2 + 3) = uVar9;
  if (local_38[0] != (void *)0x0) {
    StorPortExtendedFunction(0x53,*param_1,local_38[0],uVar8,1,local_res20);
  }
  *(undefined8 *)(uVar4 + 0x1120) = 0;
  return uVar6;
}



===== AtaMediumRemovalRequest @ 14001daf4 =====

undefined8 AtaMediumRemovalRequest(longlong param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar2 = GetSrbExtension(param_2);
  lVar3 = IsAtaDevice((uint *)(param_1 + 0x18));
  if ((((char)lVar3 == '\0') || (((*(char **)(param_1 + 0xc0))[0xa4] & 4U) == 0)) ||
     (-1 < **(char **)(param_1 + 0xc0))) {
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
    bVar1 = *(byte *)(param_3 + 4);
    *(undefined2 *)(uVar2 + 0x1100) = 0x100;
    *(byte *)(uVar2 + 0x110e) = (~bVar1 & 1) - 0x22;
  }
  return 0;
}



===== AtaModeSelectRequest @ 14001db5c =====

undefined8 AtaModeSelectRequest(longlong param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar2 = GetSrbExtension(param_2);
  if (*(char *)(param_2 + 2) == '(') {
    uVar6 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar6 = *(uint *)(param_2 + 0x10);
  }
  if (((*(byte *)(param_3 + 1) & 0x10) == 0) || (uVar6 < 4)) {
    *(undefined1 *)(param_2 + 3) = 6;
    uVar3 = 0xc1000007;
  }
  else {
    if (*(char *)(param_2 + 2) == '(') {
      lVar4 = *(longlong *)(param_2 + 0x40);
    }
    else {
      lVar4 = *(longlong *)(param_2 + 0x18);
    }
    uVar3 = 0;
    if (lVar4 == 0) {
      *(undefined1 *)(param_2 + 3) = 0x30;
      uVar3 = 0xc1000003;
    }
    else {
      uVar1 = *(byte *)(lVar4 + 3) + 4;
      pbVar5 = (byte *)((ulonglong)uVar1 + lVar4);
      if ((((-(uint)(uVar1 < uVar6) & uVar6 - uVar1) < 0xc) || ((*pbVar5 & 0x3f) != 8)) ||
         (pbVar5[1] != 10)) {
        *(undefined1 *)(param_2 + 3) = 6;
        uVar3 = 0xc1000006;
      }
      else if ((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0xa4) & 0x20) == 0) {
        *(undefined1 *)(param_2 + 3) = 1;
      }
      else {
        *(undefined2 *)(uVar2 + 0x1100) = 0x100;
        *(byte *)(uVar2 + 0x1108) = ~(pbVar5[2] << 5) & 0x82;
        *(undefined1 *)(uVar2 + 0x110e) = 0xef;
      }
    }
  }
  return uVar3;
}



===== AtaModeSenseRequestCompletionMediaStatus @ 14001dc50 =====

void AtaModeSenseRequestCompletionMediaStatus(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar2 = GetSrbExtension(param_2);
  if (*(char *)(param_2 + 2) == '(') {
    lVar3 = *(longlong *)(param_2 + 0x40);
    uVar1 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
    uVar1 = *(uint *)(param_2 + 0x10);
  }
  if ((((*(char *)(param_2 + 3) != '\x0e') && (7 < uVar1)) && ((*(byte *)(uVar2 + 0x1102) & 1) != 0)
      ) && ((*(byte *)(uVar2 + 0x1103) & 0x40) != 0)) {
    *(byte *)(lVar3 + 2) = *(byte *)(lVar3 + 2) | 0x80;
  }
  return;
}



===== AtaOpenZoneRequest @ 14001dca4 =====

undefined8 AtaOpenZoneRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined7 uVar9;
  
  uVar8 = (undefined1)param_3;
  uVar9 = (undefined7)((ulonglong)param_3 >> 8);
  uVar6 = GetSrbExtension(param_2);
  if (*(int *)(param_1 + 0x18) - 3U < 2) {
    *(uint *)(uVar6 + 0x1104) = *(uint *)(uVar6 + 0x1104) | 8;
    *(undefined2 *)(uVar6 + 0x1100) = 0x400;
    *(byte *)(uVar6 + 0x110f) = *(byte *)(uVar6 + 0x110f) | 0x40;
    *(undefined2 *)(uVar6 + 0x110a) = 0x39f;
    if ((*(byte *)(CONCAT71(uVar9,uVar8) + 0xe) & 1) != 0) {
      *(byte *)(uVar6 + 0x1113) = *(byte *)(uVar6 + 0x1113) | 1;
    }
    uVar1 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 4);
    uVar2 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 5);
    uVar3 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 6);
    uVar4 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 7);
    uVar5 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 8);
    *(undefined1 *)(uVar6 + 0x110c) = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 9);
    *(undefined1 *)(uVar6 + 0x110d) = uVar5;
    *(undefined1 *)(uVar6 + 0x110e) = uVar4;
    *(undefined1 *)(uVar6 + 0x1110) = uVar3;
    *(undefined1 *)(uVar6 + 0x1111) = uVar2;
    uVar7 = 0;
    *(undefined1 *)(uVar6 + 0x1112) = uVar1;
  }
  else {
    AhciSetSenseData(param_2,6,CONCAT71(uVar9,5),0x24,0);
    uVar7 = 0xc1000007;
  }
  return uVar7;
}



===== AtaPollSanitizeStatusTimer @ 14001ddc0 =====

void AtaPollSanitizeStatusTimer(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  short *psVar4;
  
  if (param_2 != (longlong *)0x0) {
    uVar3 = 0;
    if (*(char *)((longlong)param_2 + 2) == '(') {
      if (((*(uint *)((longlong)param_2 + 0x34) != 0) &&
          (psVar4 = (short *)((ulonglong)*(uint *)((longlong)param_2 + 0x34) + (longlong)param_2),
          psVar4 != (short *)0x0)) && (*psVar4 == 1)) {
        uVar3 = (ulonglong)*(byte *)(psVar4 + 4);
      }
    }
    else {
      uVar3 = (ulonglong)*(byte *)((longlong)param_2 + 5);
    }
    if (((*(uint *)(param_1 + 0x2c) & 0x20) == 0) &&
       (uVar2 = IsPortValid(param_1,(uint)uVar3), (char)uVar2 != '\0')) {
      plVar1 = *(longlong **)(param_1 + 0x1b0 + (uVar3 & 0xff) * 8);
      uVar3 = GetSrbExtension((longlong)param_2);
      BuildSanitizeStatusCommand(uVar3,'\0');
      AhciProcessIo(plVar1,param_2,0);
      ActivateQueue(plVar1,'\0');
    }
    else {
      *(undefined1 *)((longlong)param_2 + 3) = 8;
      StorPortNotification(0,param_1,param_2);
    }
  }
  return;
}



===== AtaReadCapacityRequestCompletion @ 14001de80 =====

void AtaReadCapacityRequestCompletion(ulonglong *param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong local_88;
  ulonglong uStack_80;
  ulonglong local_78;
  ulonglong uStack_70;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  ulonglong uStack_30;
  ulonglong local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  lVar2 = param_2;
  lVar3 = param_2;
  uVar1 = GetSrbExtension(param_2);
  lVar4 = *(longlong *)(uVar1 + 0x1120);
  if (*(char *)(lVar3 + 3) == '\x01') {
    local_88 = param_1[3];
    uStack_80 = param_1[4];
    local_78 = param_1[5];
    uStack_70 = param_1[6];
    local_68 = param_1[7];
    uStack_60 = param_1[8];
    local_58 = param_1[9];
    uStack_50 = param_1[10];
    local_48 = param_1[0xb];
    uStack_40 = param_1[0xc];
    local_38 = param_1[0xd];
    uStack_30 = param_1[0xe];
    local_28 = param_1[0xf];
    uStack_20 = param_1[0x10];
    local_18 = param_1[0x11];
    SelectDeviceGeometry(lVar2,(uint *)&local_88,lVar4);
    if ((longlong)local_68 < 2) {
      AhciSetSenseData(param_2,4,CONCAT71((int7)((ulonglong)lVar4 >> 8),2),0x3a,0);
      if (*(char *)(param_2 + 2) == '(') {
        *(undefined4 *)(param_2 + 0x3c) = 0;
      }
      else {
        *(undefined4 *)(param_2 + 0x10) = 0;
      }
    }
    else {
      param_1[3] = local_88;
      param_1[4] = uStack_80;
      param_1[5] = local_78;
      param_1[6] = uStack_70;
      param_1[7] = local_68;
      param_1[8] = uStack_60;
      param_1[9] = local_58;
      param_1[10] = uStack_50;
      param_1[0xb] = local_48;
      param_1[0xc] = uStack_40;
      param_1[0xd] = local_38;
      param_1[0xe] = uStack_30;
      param_1[0xf] = local_28;
      param_1[0x10] = uStack_20;
      param_1[0x11] = local_18;
      AtaReadCapacityCompletion(param_1,param_2);
    }
  }
  else {
    if (*(char *)(lVar3 + 2) == '(') {
      *(undefined4 *)(lVar3 + 0x3c) = 0;
    }
    else {
      *(undefined4 *)(lVar3 + 0x10) = 0;
    }
    if (*(char *)(lVar3 + 3) != '\x0e') {
      *(undefined1 *)(lVar3 + 3) = 10;
    }
  }
  return;
}



===== AtaRemoveElementAndTruncateCompletion @ 14001dfc0 =====

void AtaRemoveElementAndTruncateCompletion(undefined8 *param_1,longlong param_2)

{
  if (*(char *)(param_2 + 3) != '\x01') {
    StorPortExtendedFunction
              (0x57,*param_1,param_1 + 1,0,0x15,L"Remove Element And Truncate",1,2,0,param_2,
               L"SrbStatus",*(char *)(param_2 + 3),L"ErrorReg",*(undefined1 *)(param_1[299] + 0x43),
               L"StatusReg",*(undefined1 *)(param_1[299] + 0x42),0,0,0,0,0,0,0,0,0,0);
  }
  return;
}



===== AtaRemoveElementAndTruncateRequest @ 14001e0c8 =====

undefined8
AtaRemoveElementAndTruncateRequest(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  undefined7 uVar4;
  longlong local_res8;
  
  uVar3 = (undefined1)param_3;
  uVar4 = (undefined7)((ulonglong)param_3 >> 8);
  uVar1 = GetSrbExtension(param_2);
  local_res8 = CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                               (CONCAT71(uVar4,uVar3
                                                                                        ) + 2),
                                                                              *(undefined1 *)
                                                                               (CONCAT71(uVar4,uVar3
                                                                                        ) + 3)),
                                                                     *(undefined1 *)
                                                                      (CONCAT71(uVar4,uVar3) + 4)),
                                                            *(undefined1 *)
                                                             (CONCAT71(uVar4,uVar3) + 5)),
                                                   *(undefined1 *)(CONCAT71(uVar4,uVar3) + 6)),
                                          *(undefined1 *)(CONCAT71(uVar4,uVar3) + 7)),
                                 *(undefined1 *)(CONCAT71(uVar4,uVar3) + 8)),
                        *(undefined1 *)(CONCAT71(uVar4,uVar3) + 9));
  if (local_res8 == 1) {
    AhciSetSenseData(param_2,6,CONCAT71(uVar4,5),0x24,0);
    uVar2 = 0xc1000007;
  }
  else {
    if (local_res8 != 0) {
      local_res8 = local_res8 + -1;
    }
    *(char *)(uVar1 + 0x110c) = (char)local_res8;
    *(char *)(uVar1 + 0x110d) = (char)((ulonglong)local_res8 >> 8);
    *(char *)(uVar1 + 0x110e) = (char)((ulonglong)local_res8 >> 0x10);
    *(char *)(uVar1 + 0x1110) = (char)((ulonglong)local_res8 >> 0x18);
    *(char *)(uVar1 + 0x1111) = (char)((ulonglong)local_res8 >> 0x20);
    *(char *)(uVar1 + 0x1112) = (char)((ulonglong)local_res8 >> 0x28);
    *(uint *)(uVar1 + 0x1104) = *(uint *)(uVar1 + 0x1104) | 8;
    *(code **)(uVar1 + 0x2968) = AtaRemoveElementAndTruncateCompletion;
    *(undefined2 *)(uVar1 + 0x1100) = 0x400;
    *(undefined1 *)(uVar1 + 0x110a) = 0x7c;
    *(undefined1 *)(uVar1 + 0x110b) = *(undefined1 *)(CONCAT71(uVar4,uVar3) + 0xb);
    *(undefined1 *)(uVar1 + 0x1113) = *(undefined1 *)(CONCAT71(uVar4,uVar3) + 10);
    *(undefined1 *)(uVar1 + 0x1114) = *(undefined1 *)(CONCAT71(uVar4,uVar3) + 0xd);
    *(undefined1 *)(uVar1 + 0x1115) = *(undefined1 *)(CONCAT71(uVar4,uVar3) + 0xc);
    uVar2 = 0;
  }
  return uVar2;
}



===== AtaReportLunsCommand @ 14001e200 =====

ulonglong AtaReportLunsCommand(longlong param_1,longlong param_2)

{
  char cVar1;
  short *psVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(char *)(param_2 + 2) == '(') {
    if (((*(uint *)(param_2 + 0x34) != 0) &&
        (psVar2 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2), psVar2 != (short *)0x0)
        ) && (*psVar2 == 1)) {
      cVar1 = (char)psVar2[5];
      goto LAB_14001e22c;
    }
  }
  else {
    cVar1 = *(char *)(param_2 + 7);
LAB_14001e22c:
    if (cVar1 != '\0') {
      *(undefined1 *)(param_2 + 3) = 10;
      uVar3 = 0xc1000006;
      goto LAB_14001e241;
    }
  }
  IssueIdentifyCommand(param_1,param_2);
LAB_14001e241:
  return uVar3 & 0xffffffff;
}



===== AtaReportZonesRequest @ 14001e250 =====

undefined8 AtaReportZonesRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  byte bVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  undefined7 uVar10;
  uint uVar11;
  
  uVar9 = (undefined1)param_3;
  uVar10 = (undefined7)((ulonglong)param_3 >> 8);
  uVar6 = GetSrbExtension(param_2);
  if (*(char *)(param_2 + 2) == '(') {
    uVar11 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar11 = *(uint *)(param_2 + 0x10);
  }
  uVar11 = uVar11 >> 9;
  if (*(int *)(param_1 + 0x18) - 3U < 2) {
    if (uVar11 == 0) {
      uVar8 = 0xc1000004;
      goto LAB_14001e3aa;
    }
    if (uVar11 < 0x10000) {
      *(uint *)(uVar6 + 0x1104) = *(uint *)(uVar6 + 0x1104) | 10;
      *(code **)(uVar6 + 0x2968) = AtaReportZonesRequestCompletion;
      *(undefined2 *)(uVar6 + 0x1100) = 0x400;
      *(byte *)(uVar6 + 0x110f) = *(byte *)(uVar6 + 0x110f) | 0x40;
      *(undefined2 *)(uVar6 + 0x110a) = 0x4a;
      bVar7 = *(byte *)(CONCAT71(uVar10,uVar9) + 0xe) & 0x3f;
      *(byte *)(uVar6 + 0x1113) = bVar7;
      if (*(char *)(CONCAT71(uVar10,uVar9) + 0xe) < '\0') {
        *(byte *)(uVar6 + 0x1113) = bVar7 | 0x80;
      }
      *(char *)(uVar6 + 0x1114) = (char)uVar11;
      *(char *)(uVar6 + 0x1115) = (char)(uVar11 >> 8);
      uVar1 = *(undefined1 *)(CONCAT71(uVar10,uVar9) + 4);
      uVar2 = *(undefined1 *)(CONCAT71(uVar10,uVar9) + 5);
      uVar3 = *(undefined1 *)(CONCAT71(uVar10,uVar9) + 6);
      uVar4 = *(undefined1 *)(CONCAT71(uVar10,uVar9) + 7);
      uVar5 = *(undefined1 *)(CONCAT71(uVar10,uVar9) + 8);
      *(undefined1 *)(uVar6 + 0x110c) = *(undefined1 *)(CONCAT71(uVar10,uVar9) + 9);
      *(undefined1 *)(uVar6 + 0x110d) = uVar5;
      *(undefined1 *)(uVar6 + 0x110e) = uVar4;
      *(undefined1 *)(uVar6 + 0x1110) = uVar3;
      *(undefined1 *)(uVar6 + 0x1111) = uVar2;
      *(undefined1 *)(uVar6 + 0x1112) = uVar1;
      return 0;
    }
  }
  uVar8 = 0xc1000007;
LAB_14001e3aa:
  AhciSetSenseData(param_2,6,CONCAT71(uVar10,5),0x24,0);
  return uVar8;
}



===== AtaReportZonesRequestCompletion @ 14001e3d0 =====

void AtaReportZonesRequestCompletion(undefined8 param_1,longlong param_2)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar4 = *(uint *)(param_2 + 0x3c);
    puVar3 = *(undefined1 **)(param_2 + 0x40);
  }
  else {
    uVar4 = *(uint *)(param_2 + 0x10);
    puVar3 = *(undefined1 **)(param_2 + 0x18);
  }
  if (*(char *)(param_2 + 3) == '\x01') {
    uVar1 = puVar3[3];
    uVar5 = 0x80;
    puVar3[3] = *puVar3;
    *puVar3 = uVar1;
    uVar1 = puVar3[2];
    puVar3[2] = puVar3[1];
    puVar3[1] = uVar1;
    uVar2 = *(ulonglong *)(puVar3 + 8) & 0xffffffffffff;
    puVar3[0xf] = (char)uVar2;
    puVar3[0xe] = (char)(uVar2 >> 8);
    puVar3[0xd] = (char)(uVar2 >> 0x10);
    puVar3[0xc] = (char)(uVar2 >> 0x18);
    puVar3[0xb] = (char)(uVar2 >> 0x20);
    puVar3[10] = (char)(uVar2 >> 0x28);
    puVar3[9] = 0;
    puVar3[8] = 0;
    puVar3 = puVar3 + 0x4e;
    do {
      uVar5 = uVar5 + 0x40;
      uVar2 = *(ulonglong *)(puVar3 + -6) & 0xffffffffffff;
      puVar3[1] = (char)uVar2;
      *puVar3 = (char)(uVar2 >> 8);
      puVar3[-1] = (char)(uVar2 >> 0x10);
      puVar3[-2] = (char)(uVar2 >> 0x18);
      puVar3[-3] = (char)(uVar2 >> 0x20);
      puVar3[-4] = (char)(uVar2 >> 0x28);
      puVar3[-5] = 0;
      puVar3[-6] = 0;
      uVar2 = *(ulonglong *)(puVar3 + 2) & 0xffffffffffff;
      puVar3[9] = (char)uVar2;
      puVar3[8] = (char)(uVar2 >> 8);
      puVar3[7] = (char)(uVar2 >> 0x10);
      puVar3[6] = (char)(uVar2 >> 0x18);
      puVar3[5] = (char)(uVar2 >> 0x20);
      puVar3[4] = (char)(uVar2 >> 0x28);
      puVar3[3] = 0;
      puVar3[2] = 0;
      uVar2 = *(ulonglong *)(puVar3 + 10) & 0xffffffffffff;
      puVar3[0x11] = (char)uVar2;
      puVar3[0x10] = (char)(uVar2 >> 8);
      puVar3[0xf] = (char)(uVar2 >> 0x10);
      puVar3[0xe] = (char)(uVar2 >> 0x18);
      puVar3[0xd] = (char)(uVar2 >> 0x20);
      puVar3[0xc] = (char)(uVar2 >> 0x28);
      puVar3[0xb] = 0;
      puVar3[10] = 0;
      puVar3 = puVar3 + 0x40;
    } while (uVar5 <= uVar4);
    if (*(char *)(param_2 + 2) == '(') {
      *(uint *)(param_2 + 0x3c) = uVar4 & 0xfffffe00;
    }
    else {
      *(uint *)(param_2 + 0x10) = uVar4 & 0xfffffe00;
    }
  }
  uVar2 = GetSrbExtension(param_2);
  *(uint *)(uVar2 + 0x1104) = *(uint *)(uVar2 + 0x1104) | 0x200;
  return;
}



===== AtaResetWritePointerRequest @ 14001e5c0 =====

undefined8 AtaResetWritePointerRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined7 uVar9;
  
  uVar8 = (undefined1)param_3;
  uVar9 = (undefined7)((ulonglong)param_3 >> 8);
  uVar6 = GetSrbExtension(param_2);
  if (*(int *)(param_1 + 0x18) - 3U < 2) {
    *(uint *)(uVar6 + 0x1104) = *(uint *)(uVar6 + 0x1104) | 8;
    *(undefined2 *)(uVar6 + 0x1100) = 0x400;
    *(byte *)(uVar6 + 0x110f) = *(byte *)(uVar6 + 0x110f) | 0x40;
    *(undefined2 *)(uVar6 + 0x110a) = 0x49f;
    if ((*(byte *)(CONCAT71(uVar9,uVar8) + 0xe) & 1) != 0) {
      *(byte *)(uVar6 + 0x1113) = *(byte *)(uVar6 + 0x1113) | 1;
    }
    uVar1 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 4);
    uVar2 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 5);
    uVar3 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 6);
    uVar4 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 7);
    uVar5 = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 8);
    *(undefined1 *)(uVar6 + 0x110c) = *(undefined1 *)(CONCAT71(uVar9,uVar8) + 9);
    *(undefined1 *)(uVar6 + 0x110d) = uVar5;
    *(undefined1 *)(uVar6 + 0x110e) = uVar4;
    *(undefined1 *)(uVar6 + 0x1110) = uVar3;
    *(undefined1 *)(uVar6 + 0x1111) = uVar2;
    uVar7 = 0;
    *(undefined1 *)(uVar6 + 0x1112) = uVar1;
  }
  else {
    AhciSetSenseData(param_2,6,CONCAT71(uVar9,5),0x24,0);
    uVar7 = 0xc1000007;
  }
  return uVar7;
}



===== AtaSanitizeBlockErase @ 14001e6d4 =====

void AtaSanitizeBlockErase(undefined8 *param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  
  uVar2 = GetSrbExtension(param_2);
  *(undefined2 *)(uVar2 + 0x1100) = 0x100;
  *(code **)(uVar2 + 0x2968) = AtaSanitizeCryptoEraseCompletion;
  *(undefined1 *)(uVar2 + 0x110e) = 0xb4;
  *(undefined1 *)(uVar2 + 0x1108) = 0x12;
  *(undefined2 *)(uVar2 + 0x110a) = 0x4572;
  *(undefined1 *)(uVar2 + 0x110c) = 0x6b;
  *(undefined1 *)(uVar2 + 0x1112) = 0x42;
  if ((*(byte *)(param_3 + 1) & 0x20) != 0) {
    *(undefined1 *)(uVar2 + 0x1109) = 0x10;
  }
  StorPortExtendedFunction(0,*param_1,0x10,0x69636841,(undefined8 *)(uVar2 + 0x2988));
  puVar1 = *(undefined8 **)(uVar2 + 0x2988);
  if (puVar1 == (undefined8 *)0x0) {
    *(undefined1 *)(param_2 + 3) = 0x26;
    *(undefined8 *)(uVar2 + 0x2970) = 0;
    *(undefined8 *)(uVar2 + 0x2968) = 0;
    *(undefined2 *)(uVar2 + 0x1100) = 0;
    *(undefined4 *)(uVar2 + 0x1104) = 0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    *(uint *)(uVar2 + 0x1104) = *(uint *)(uVar2 + 0x1104) | 0x40;
    *(undefined4 *)(uVar2 + 0x2998) = 0x10;
  }
  return;
}



===== AtaSanitizeCryptoEraseCompletion @ 14001e7c0 =====

void AtaSanitizeCryptoEraseCompletion(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  
  uVar2 = GetSrbExtension(param_2);
  if ((char)*(byte *)(param_2 + 3) < '\0') {
    if ((*(byte *)(param_2 + 3) & 0x3f) == 1) {
      cVar3 = '\0';
    }
    else {
      lVar1 = *(longlong *)(uVar2 + 0x2988);
      if ((((*(byte *)(lVar1 + 6) & 0x21) != 1) || ((*(byte *)(lVar1 + 9) & 0x60) != 0)) ||
         (1 < *(byte *)(lVar1 + 2))) goto joined_r0x00014001e822;
      cVar3 = '\x01';
    }
    BuildSanitizeStatusCommand(uVar2,cVar3);
  }
  else {
    lVar1 = *(longlong *)(uVar2 + 0x2988);
joined_r0x00014001e822:
    if (lVar1 != 0) {
      StorPortExtendedFunction(1,*param_1);
      *(undefined8 *)(uVar2 + 0x2988) = 0;
      *(undefined4 *)(uVar2 + 0x2998) = 0;
    }
    *(undefined8 *)(uVar2 + 0x2970) = 0;
    *(undefined8 *)(uVar2 + 0x2968) = 0;
    *(undefined2 *)(uVar2 + 0x1100) = 0;
    *(undefined4 *)(uVar2 + 0x1104) = 0;
  }
  return;
}



===== AtaSanitizeCryptoErase @ 14001e87c =====

void AtaSanitizeCryptoErase(undefined8 *param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  
  uVar2 = GetSrbExtension(param_2);
  *(undefined2 *)(uVar2 + 0x1100) = 0x100;
  *(code **)(uVar2 + 0x2968) = AtaSanitizeCryptoEraseCompletion;
  *(undefined1 *)(uVar2 + 0x110e) = 0xb4;
  *(undefined1 *)(uVar2 + 0x1108) = 0x11;
  *(undefined2 *)(uVar2 + 0x110a) = 0x7970;
  *(undefined1 *)(uVar2 + 0x110c) = 0x72;
  *(undefined1 *)(uVar2 + 0x1112) = 0x43;
  if ((*(byte *)(param_3 + 1) & 0x20) != 0) {
    *(undefined1 *)(uVar2 + 0x1109) = 0x10;
  }
  StorPortExtendedFunction(0,*param_1,0x10,0x69636841,(undefined8 *)(uVar2 + 0x2988));
  puVar1 = *(undefined8 **)(uVar2 + 0x2988);
  if (puVar1 == (undefined8 *)0x0) {
    *(undefined1 *)(param_2 + 3) = 0x26;
    *(undefined8 *)(uVar2 + 0x2970) = 0;
    *(undefined8 *)(uVar2 + 0x2968) = 0;
    *(undefined2 *)(uVar2 + 0x1100) = 0;
    *(undefined4 *)(uVar2 + 0x1104) = 0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    *(uint *)(uVar2 + 0x1104) = *(uint *)(uVar2 + 0x1104) | 0x40;
    *(undefined4 *)(uVar2 + 0x2998) = 0x10;
  }
  return;
}



===== AtaSanitizeRequest @ 14001e968 =====

undefined8 AtaSanitizeRequest(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  byte bVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  undefined7 uVar4;
  byte bVar5;
  
  uVar3 = (undefined1)param_3;
  uVar4 = (undefined7)((ulonglong)param_3 >> 8);
  uVar2 = GetSrbExtension(param_2);
  if (*(int *)(param_1 + 6) == 2) {
    *(uint *)(uVar2 + 0x1104) = *(uint *)(uVar2 + 0x1104) | 8;
    bVar5 = *(byte *)(CONCAT71(uVar4,uVar3) + 1);
    if ((((-1 < (char)bVar5) && (*(char *)(CONCAT71(uVar4,uVar3) + 7) == '\0')) &&
        (*(char *)(CONCAT71(uVar4,uVar3) + 8) == '\0')) &&
       (bVar1 = *(byte *)(param_1[0x18] + 0x77), (bVar1 & 0x10) != 0)) {
      bVar5 = bVar5 & 0x1f;
      if (bVar5 == 3) {
        if ((bVar1 & 0x20) != 0) {
          AtaSanitizeCryptoErase(param_1,param_2,CONCAT71(uVar4,uVar3));
          return 0;
        }
      }
      else if ((bVar5 == 2) && ((char)bVar1 < '\0')) {
        AtaSanitizeBlockErase(param_1,param_2,CONCAT71(uVar4,uVar3));
        return 0;
      }
    }
  }
  AhciSetSenseData(param_2,4,CONCAT71(uVar4,5),0x24,0);
  return 0xc1000007;
}



===== AtaSanitizeStatusClearFailureCompletion @ 14001ea10 =====

void AtaSanitizeStatusClearFailureCompletion(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = GetSrbExtension(param_2);
  if (param_1[0x157] != 0) {
    StorPortExtendedFunction(0x22,*param_1);
    param_1[0x157] = 0;
  }
  if (*(longlong *)(uVar1 + 0x2988) != 0) {
    StorPortExtendedFunction(1,*param_1);
    *(undefined8 *)(uVar1 + 0x2988) = 0;
    *(undefined4 *)(uVar1 + 0x2998) = 0;
  }
  *(undefined8 *)(uVar1 + 0x2970) = 0;
  *(undefined8 *)(uVar1 + 0x2968) = 0;
  *(undefined2 *)(uVar1 + 0x1100) = 0;
  *(undefined4 *)(uVar1 + 0x1104) = 0;
  *(undefined1 *)(param_2 + 3) = 4;
  return;
}



===== AtaSanitizeStatusCompletion @ 14001ead0 =====

void AtaSanitizeStatusCompletion(undefined8 *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  ulonglong uVar6;
  char cVar7;
  longlong lVar8;
  
  lVar8 = param_2;
  uVar6 = GetSrbExtension(param_2);
  plVar1 = (longlong *)(uVar6 + 0x2988);
  if ((char)*(byte *)(lVar8 + 3) < '\0') {
    lVar3 = *plVar1;
    if ((*(byte *)(lVar8 + 3) & 0x3f) == 1) {
      if ((*(byte *)(lVar3 + 6) & 0x21) == 0) {
        if ((-1 < *(char *)(lVar3 + 9)) && (*(short *)(lVar3 + 2) != -1)) {
          bVar4 = true;
          goto LAB_14001eb63;
        }
      }
      else {
        *(undefined1 *)(lVar8 + 3) = 4;
      }
      goto LAB_14001eb60;
    }
    bVar4 = false;
    if ((((*(byte *)(lVar3 + 6) & 0x21) == 1) && ((*(byte *)(lVar3 + 9) & 0x60) == 0)) &&
       (*(byte *)(lVar3 + 2) < 2)) {
      cVar7 = '\x01';
      goto LAB_14001ec39;
    }
  }
  else {
LAB_14001eb60:
    bVar4 = false;
  }
LAB_14001eb63:
  plVar2 = param_1 + 0x157;
  lVar8 = *plVar2;
  if (!bVar4) {
    if (lVar8 != 0) {
      StorPortExtendedFunction(0x22,*param_1,lVar8);
      *plVar2 = 0;
    }
    if (*plVar1 != 0) {
      StorPortExtendedFunction(1,*param_1);
      *plVar1 = 0;
      *(undefined4 *)(uVar6 + 0x2998) = 0;
    }
    *(undefined8 *)(uVar6 + 0x2970) = 0;
    *(undefined8 *)(uVar6 + 0x2968) = 0;
    *(undefined2 *)(uVar6 + 0x1100) = 0;
    *(undefined4 *)(uVar6 + 0x1104) = 0;
    return;
  }
  if (lVar8 == 0) {
    StorPortExtendedFunction(0x20,*param_1,plVar2);
  }
  if ((*plVar2 != 0) &&
     (iVar5 = StorPortExtendedFunction
                        (0x21,*param_1,*plVar2,AtaPollSanitizeStatusTimer,param_2,200000,20000),
     iVar5 == 0)) {
    *(uint *)(uVar6 + 0x1104) = *(uint *)(uVar6 + 0x1104) | 0x1000;
    return;
  }
  cVar7 = '\0';
LAB_14001ec39:
  BuildSanitizeStatusCommand(uVar6,cVar7);
  return;
}



===== AtaSecurityProtocolRequest @ 14001ec64 =====

undefined8 AtaSecurityProtocolRequest(longlong param_1,longlong param_2,char *param_3)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar7;
  bool bVar8;
  
  uVar4 = GetSrbExtension(param_2);
  bVar8 = false;
  if (((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0x60) & 1) == 0) || (-1 < param_3[4])) {
LAB_14001ed95:
    *(undefined1 *)(param_2 + 3) = 6;
    return 0;
  }
  bVar1 = param_3[1];
  cVar2 = param_3[9];
  uVar6 = CONCAT31(CONCAT21(CONCAT11(param_3[6],param_3[7]),param_3[8]),cVar2);
  if (0xffff < uVar6) goto LAB_14001ed95;
  cVar3 = *param_3;
  if (uVar6 == 0) {
    bVar8 = cVar3 == -0x5e;
    uVar7 = 0x5b;
  }
  else {
    uVar7 = 0x5f;
    if (cVar3 == -0x5e) {
      uVar7 = 0x5d;
    }
    uVar5 = *(uint *)(uVar4 + 0x1104) | 2;
    if (cVar3 != -0x5e) {
      uVar5 = *(uint *)(uVar4 + 0x1104) | 4;
    }
    *(uint *)(uVar4 + 0x1104) = uVar5 | 0x10;
  }
  *(undefined2 *)(uVar4 + 0x1100) = 0x100;
  *(undefined1 *)(uVar4 + 0x110e) = uVar7;
  *(byte *)(uVar4 + 0x1108) = bVar1;
  if (bVar1 == 0xee) {
    *(char *)(uVar4 + 0x1109) = param_3[9];
    *(char *)(uVar4 + 0x110a) = param_3[8];
  }
  else {
    if (2 < bVar1) goto LAB_14001ed88;
    if (0xff < uVar6) {
      *(undefined1 *)(param_2 + 3) = 6;
      goto LAB_14001ed88;
    }
    *(char *)(uVar4 + 0x1109) = cVar2;
    if (1 < (byte)(bVar1 - 1)) goto LAB_14001ed88;
  }
  *(char *)(uVar4 + 0x110c) = param_3[2];
  *(char *)(uVar4 + 0x110b) = param_3[3];
LAB_14001ed88:
  *(byte *)(uVar4 + 0x110d) = *(byte *)(uVar4 + 0x110d) | bVar8 | 0xa0U;
  return 0;
}



===== AtaVerifyRequest @ 14001edb4 =====

undefined8 AtaVerifyRequest(longlong param_1,longlong param_2,longlong param_3,int param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  byte bVar5;
  longlong lVar6;
  undefined1 uVar7;
  int iVar8;
  uint uVar9;
  uint local_res20;
  
  lVar6 = param_3;
  iVar8 = param_4;
  uVar1 = GetSrbExtension(param_2);
  uVar2 = GetLbaFromCdb(lVar6,iVar8);
  if (param_4 == 0x10) {
    local_res20 = CONCAT31(CONCAT12(*(undefined1 *)(param_3 + 10),
                                    CONCAT11(*(undefined1 *)(param_3 + 0xb),
                                             *(undefined1 *)(param_3 + 0xc))),
                           *(byte *)(param_3 + 0xd));
    uVar9 = (uint)*(byte *)(param_3 + 0xd);
  }
  else {
    local_res20 = (uint)CONCAT11(*(undefined1 *)(param_3 + 7),*(undefined1 *)(param_3 + 8));
    uVar9 = local_res20;
  }
  uVar7 = (undefined1)uVar9;
  if ((local_res20 < 0x10001) && ((*(int *)(param_1 + 0x30) == 2 || (local_res20 < 0x101)))) {
    *(undefined2 *)(uVar1 + 0x1100) = 0x100;
    if (*(int *)(param_1 + 0x30) == 2) {
      *(uint *)(uVar1 + 0x1104) = *(uint *)(uVar1 + 0x1104) | 8;
    }
    uVar3 = GetSrbExtension(param_2);
    bVar5 = (byte)(uVar2 >> 0x18);
    if (*(int *)(param_1 + 0x30) == 2) {
      *(byte *)(uVar3 + 0x1112) = bVar5;
      *(char *)(uVar3 + 0x1113) = (char)(uVar2 >> 0x20);
      *(char *)(uVar3 + 0x1114) = (char)(uVar2 >> 0x28);
      *(char *)(uVar3 + 0x1111) = (char)(local_res20 >> 8);
      *(byte *)(uVar3 + 0x110d) = *(byte *)(uVar3 + 0x110d) | 0xe0;
    }
    else {
      *(byte *)(uVar3 + 0x110d) = bVar5 & 0xf | *(byte *)(uVar3 + 0x110d) | 0xe0;
    }
    *(char *)(uVar3 + 0x110a) = (char)uVar2;
    *(char *)(uVar3 + 0x110b) = (char)(uVar2 >> 8);
    *(undefined1 *)(uVar3 + 0x1109) = uVar7;
    *(char *)(uVar3 + 0x110c) = (char)(uVar2 >> 0x10);
    uVar7 = 0x42;
    if (*(int *)(param_1 + 0x30) != 2) {
      uVar7 = 0x40;
    }
    *(undefined1 *)(uVar1 + 0x110e) = uVar7;
    uVar4 = 0;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 6;
    uVar4 = 0xc1000006;
  }
  return uVar4;
}



===== AtaWriteBufferFirmwareActivate @ 14001ef1c =====

void AtaWriteBufferFirmwareActivate(undefined8 *param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  lVar3 = param_2;
  uVar2 = GetSrbExtension(param_2);
  if (*(char *)(lVar3 + 2) == '(') {
    lVar3 = *(longlong *)(lVar3 + 0x40);
  }
  else {
    lVar3 = *(longlong *)(lVar3 + 0x18);
  }
  if (((((*(byte *)(param_3 + 1) < 0x20) && (*(char *)(param_3 + 2) == '\0')) &&
       (*(char *)(param_3 + 3) == '\0')) &&
      ((*(char *)(param_3 + 4) == '\0' && (*(char *)(param_3 + 5) == '\0')))) &&
     ((*(char *)(param_3 + 6) == '\0' &&
      ((*(char *)(param_3 + 7) == '\0' && (*(char *)(param_3 + 8) == '\0')))))) {
    cVar1 = GetFirmwareUpdateCommand((longlong)param_1);
    if (cVar1 == -0x6d) {
      *(uint *)(uVar2 + 0x1104) = *(uint *)(uVar2 + 0x1104) | 0x10;
    }
    *(undefined2 *)(uVar2 + 0x1100) = 0x100;
    *(code **)(uVar2 + 0x2968) = AtaFirmwareActivateCompletion;
    *(char *)(uVar2 + 0x110e) = cVar1;
    *(undefined1 *)(uVar2 + 0x1108) = 0xf;
  }
  else {
    AhciSetSenseData(param_2,6,CONCAT71((int7)(uVar2 >> 8),5),0x24,0);
    *(undefined4 *)(lVar3 + 0x14) = 3;
    StorPortExtendedFunction
              (0x57,*param_1,param_1 + 1,0,0x12,L"Firmware Activate",1,2,0,param_2,L"Operation Code"
               ,*(byte *)(param_3 + 1) >> 5,L"Buffer ID",*(undefined1 *)(param_3 + 2),
               L"Buffer Offset0",*(undefined1 *)(param_3 + 3),L"Buffer Offset1",
               *(undefined1 *)(param_3 + 4),L"Buffer Offset2",*(undefined1 *)(param_3 + 5),
               L"ParaList Len0",*(undefined1 *)(param_3 + 6),L"ParaList Len1",
               *(undefined1 *)(param_3 + 7),L"ParaList Len2",*(undefined1 *)(param_3 + 8));
  }
  return;
}



===== AtaWriteBufferFirmwareDownload @ 14001f11c =====

void AtaWriteBufferFirmwareDownload(undefined8 *param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  byte bVar2;
  uint3 uVar3;
  uint3 uVar4;
  ushort uVar5;
  ushort uVar6;
  char cVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  
  lVar9 = param_2;
  lVar12 = param_3;
  uVar8 = GetSrbExtension(param_2);
  if (*(char *)(lVar9 + 2) == '(') {
    lVar9 = *(longlong *)(lVar9 + 0x40);
  }
  else {
    lVar9 = *(longlong *)(lVar9 + 0x18);
  }
  bVar1 = *(byte *)(lVar12 + 3);
  bVar2 = *(byte *)(lVar12 + 6);
  uVar3 = CONCAT21(CONCAT11(bVar1,*(undefined1 *)(lVar12 + 4)),*(undefined1 *)(lVar12 + 5));
  uVar11 = (uint)uVar3;
  uVar4 = CONCAT21(CONCAT11(bVar2,*(undefined1 *)(lVar12 + 7)),*(undefined1 *)(lVar12 + 8));
  uVar10 = (uint)uVar4;
  if (((uVar4 | uVar3) & 0x1ff) == 0) {
    uVar5 = CONCAT11(bVar1,*(undefined1 *)(lVar12 + 4)) >> 1;
    uVar11 = (uint)uVar5;
    uVar6 = CONCAT11(bVar2,*(undefined1 *)(lVar12 + 7)) >> 1;
    uVar10 = (uint)uVar6;
    if (((uVar10 <= *(ushort *)((longlong)param_1 + 0x1c6)) &&
        (*(ushort *)((longlong)param_1 + 0x1c4) <= uVar10)) &&
       (((*(byte *)(lVar12 + 1) & 0x1f) != 0xd || ((*(byte *)(lVar12 + 1) & 0xc0) == 0x80)))) {
      cVar7 = GetFirmwareUpdateCommand((longlong)param_1);
      if (cVar7 == -0x6d) {
        *(uint *)(uVar8 + 0x1104) = *(uint *)(uVar8 + 0x1104) | 0x10;
      }
      *(uint *)(uVar8 + 0x1104) = *(uint *)(uVar8 + 0x1104) | 4;
      *(char *)(uVar8 + 0x1109) = (char)uVar6;
      *(char *)(uVar8 + 0x110b) = (char)uVar5;
      *(byte *)(uVar8 + 0x110c) = bVar1 >> 1;
      *(undefined2 *)(uVar8 + 0x1100) = 0x100;
      *(code **)(uVar8 + 0x2968) = AtaFirmwareDownloadCompletion;
      *(char *)(uVar8 + 0x110e) = cVar7;
      *(undefined1 *)(uVar8 + 0x1108) = 0xe;
      *(byte *)(uVar8 + 0x110a) = bVar2 >> 1;
      return;
    }
  }
  AhciSetSenseData(param_2,6,CONCAT71((int7)((ulonglong)lVar12 >> 8),5),0x24,0);
  *(undefined4 *)(lVar9 + 0x14) = 3;
  StorPortExtendedFunction
            (0x57,*param_1,param_1 + 1,0,0x10,L"Firmware Download",1,2,0,param_2,L"BufferOffset",
             uVar11,L"DataLength",uVar10,L"MaxTransBlocks",
             *(undefined2 *)((longlong)param_1 + 0x1c6),L"MinTransBlocks",
             *(undefined2 *)((longlong)param_1 + 0x1c4),L"Mode",*(byte *)(param_3 + 1) & 0x1f,
             L"ModeSpecific",*(byte *)(param_3 + 1) >> 5,L"CommandReg",0,L"ReturnCode",3);
  return;
}



===== AtaWriteBufferRequest @ 14001f39c =====

undefined8 AtaWriteBufferRequest(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  bool bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined7 uVar4;
  undefined1 uVar5;
  undefined7 uVar6;
  
  uVar5 = (undefined1)param_3;
  uVar6 = (undefined7)((ulonglong)param_3 >> 8);
  uVar3 = (undefined1)param_2;
  uVar4 = (undefined7)((ulonglong)param_2 >> 8);
  bVar1 = IsFirmwareUpdateSupported((longlong)param_1);
  if (bVar1) {
    bVar2 = *(byte *)(CONCAT71(uVar6,uVar5) + 1) & 0x1f;
    if ((byte)(bVar2 - 0xd) < 2) {
      AtaWriteBufferFirmwareDownload(param_1,CONCAT71(uVar4,uVar3),CONCAT71(uVar6,uVar5));
      return 0;
    }
    if (bVar2 == 0xf) {
      AtaWriteBufferFirmwareActivate(param_1,CONCAT71(uVar4,uVar3),CONCAT71(uVar6,uVar5));
      return 0;
    }
  }
  AhciSetSenseData(param_2,6,CONCAT71(uVar6,5),0x24,0);
  return 0;
}



===== AtapiInquiryCompletion @ 14001f400 =====

void AtapiInquiryCompletion(longlong *param_1,longlong param_2)

{
  short *psVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = 0;
  if (*(char *)(param_2 + 3) == '\x01') {
    if (*(char *)(param_2 + 2) == '(') {
      if (((*(uint *)(param_2 + 0x34) != 0) &&
          (psVar1 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2),
          psVar1 != (short *)0x0)) && (*psVar1 == 1)) {
        uVar4 = (undefined1)psVar1[4];
        uVar3 = *(undefined1 *)((longlong)psVar1 + 9);
        uVar2 = (undefined1)psVar1[5];
      }
    }
    else {
      uVar4 = *(undefined1 *)(param_2 + 5);
      uVar3 = *(undefined1 *)(param_2 + 6);
      uVar2 = *(undefined1 *)(param_2 + 7);
    }
    StorPortSetDeviceQueueDepth
              (*param_1,uVar4,uVar3,uVar2,*(undefined1 *)((longlong)param_1 + 0x274));
    if ((int)param_1[3] == 2) {
      StorPortExtendedFunction
                (0x2e,*param_1,param_1 + 1,
                 (*(ushort *)(param_1[0x18] + 0x9c) & 0x20 |
                 *(ushort *)(param_1[0x18] + 0x9a) & 0x10) >> 4 |
                 ~(*(uint *)(*param_1 + 0x2c) >> 2) & 4);
    }
  }
  return;
}



===== AtapiModeCommandRequestCompletion @ 14001f4d0 =====

void AtapiModeCommandRequestCompletion(undefined8 *param_1,longlong param_2)

{
  char *pcVar1;
  uint *puVar2;
  uint uVar3;
  ulonglong uVar4;
  uint *puVar5;
  char cVar6;
  longlong lVar7;
  ulonglong _Size;
  char *pcVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined8 uVar11;
  
  pcVar1 = (char *)(param_2 + 2);
  cVar6 = *pcVar1;
  if (cVar6 == '(') {
    pcVar8 = *(char **)(param_2 + 0x40);
  }
  else {
    pcVar8 = *(char **)(param_2 + 0x18);
  }
  uVar4 = GetSrbExtension(param_2);
  if (*(char *)(param_2 + 3) == '\x0e') {
    lVar7 = *(longlong *)(uVar4 + 0x1120);
    if (lVar7 == 0) {
      return;
    }
    uVar11 = *(undefined8 *)(uVar4 + 0x1128);
    uVar9 = *(undefined8 *)(uVar4 + 0x2970);
LAB_14001f538:
    StorPortExtendedFunction(0x53,*param_1,lVar7,uVar9,1,uVar11);
    *(undefined8 *)(uVar4 + 0x1120) = 0;
  }
  else {
    if ((pcVar8 != (char *)0x0) && (lVar7 = *(longlong *)(uVar4 + 0x1120), lVar7 != 0)) {
      if (cVar6 == '(') {
        uVar3 = *(uint *)(param_2 + 0x3c);
      }
      else {
        uVar3 = *(uint *)(param_2 + 0x10);
      }
      if ((3 < uVar3) && (3 < *(uint *)(uVar4 + 0x1130))) {
        if (*(char *)(uVar4 + 0x1108) == 'Z') {
          uVar3 = RequestGetDataTransferLength(param_2);
          puVar2 = (uint *)(param_2 + 0x3c);
          *pcVar8 = *(char *)(lVar7 + 1) + -3;
          pcVar8[1] = *(char *)(lVar7 + 2);
          pcVar8[2] = *(char *)(lVar7 + 3);
          pcVar8[3] = *(char *)(lVar7 + 7);
          if (uVar3 < 9) {
            if (4 < uVar3) goto LAB_14001f628;
            if (*pcVar1 == '(') {
              *(uint *)(param_2 + 0x3c) = uVar3;
              goto LAB_14001f643;
            }
          }
          else {
            if (*pcVar1 == '(') {
              uVar10 = *puVar2;
            }
            else {
              uVar10 = *(uint *)(param_2 + 0x10);
            }
            _Size = (ulonglong)uVar3 - 8;
            if ((ulonglong)uVar10 - 4 < _Size) {
              puVar5 = puVar2;
              if (*pcVar1 != '(') {
                puVar5 = (uint *)(param_2 + 0x10);
              }
              _Size = (ulonglong)*puVar5 - 4;
            }
            memcpy(pcVar8 + 4,(void *)(lVar7 + 8),_Size);
LAB_14001f628:
            uVar3 = uVar3 - 4;
            if (*pcVar1 == '(') {
              *puVar2 = uVar3;
              goto LAB_14001f643;
            }
          }
          *(uint *)(param_2 + 0x10) = uVar3;
        }
LAB_14001f643:
        lVar7 = *(longlong *)(uVar4 + 0x1120);
        if (lVar7 == 0) {
          return;
        }
        uVar11 = *(undefined8 *)(uVar4 + 0x1128);
        uVar9 = *(undefined8 *)(uVar4 + 0x2970);
        goto LAB_14001f538;
      }
    }
    if (*(longlong *)(uVar4 + 0x1120) != 0) {
      StorPortExtendedFunction
                (0x53,*param_1,*(longlong *)(uVar4 + 0x1120),*(undefined8 *)(uVar4 + 0x2970),1,
                 *(undefined8 *)(uVar4 + 0x1128));
      *(undefined8 *)(uVar4 + 0x1120) = 0;
    }
    *(undefined1 *)(param_2 + 3) = 6;
  }
  return;
}



===== AtapiModeSelectRequest @ 14001f6d0 =====

undefined4 AtapiModeSelectRequest(longlong *param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  byte bVar4;
  ushort uVar5;
  short sVar6;
  longlong lVar7;
  undefined4 uVar8;
  uint uVar9;
  longlong *plVar10;
  byte bVar11;
  uint uVar12;
  undefined1 *puVar13;
  void *local_res10;
  longlong local_res18;
  undefined8 local_res20;
  
  local_res20 = 0;
  lVar7 = param_2;
  plVar10 = param_1;
  local_res18 = param_3;
  uVar3 = GetSrbExtension(param_2);
  if (*(char *)(lVar7 + 2) == '(') {
    puVar13 = *(undefined1 **)(lVar7 + 0x40);
    uVar9 = *(uint *)(lVar7 + 0x3c);
  }
  else {
    puVar13 = *(undefined1 **)(lVar7 + 0x18);
    uVar9 = *(uint *)(lVar7 + 0x10);
  }
  uVar12 = 0;
  local_res10 = (void *)0x0;
  if (puVar13 == (undefined1 *)0x0) {
    *(undefined1 *)(lVar7 + 3) = 6;
LAB_14001f72b:
    uVar8 = 0xc1000006;
    goto LAB_14001f928;
  }
  if (uVar9 < 4) {
LAB_14001f8ef:
    uVar8 = 0xc1000004;
LAB_14001f8f4:
    *(undefined1 *)(param_2 + 3) = 6;
    param_1 = plVar10;
  }
  else {
    uVar1 = (byte)puVar13[3] + 4;
    if (uVar9 < uVar1) goto LAB_14001f8ef;
    if (0xff < uVar1) {
      *(undefined1 *)(param_2 + 3) = 6;
      goto LAB_14001f72b;
    }
    uVar12 = (uVar9 - (byte)puVar13[3]) + 4;
    iVar2 = AhciAllocateDmaBuffer(*plVar10,uVar12,&local_res10,&local_res20);
    if ((iVar2 == 0) && (local_res10 != (void *)0x0)) {
      if (uVar12 != 0) {
        memset(local_res10,0,(ulonglong)uVar12);
      }
      *(undefined1 *)((longlong)local_res10 + 1) = *puVar13;
      *(undefined1 *)((longlong)local_res10 + 2) = puVar13[1];
      bVar11 = puVar13[3] + 4;
      if (bVar11 < uVar9) {
        memcpy((void *)((longlong)local_res10 + 8),puVar13 + bVar11,(ulonglong)(uVar9 - bVar11));
      }
      uVar5 = *(byte *)(local_res18 + 4) + 8;
      if ((7 < uVar5) && (bVar11 <= uVar5)) {
        *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 0x104;
        sVar6 = uVar5 - bVar11;
        *(undefined2 *)(uVar3 + 0x1100) = 0x200;
        *(void **)(uVar3 + 0x1120) = local_res10;
        *(undefined8 *)(uVar3 + 0x1128) = local_res20;
        *(code **)(uVar3 + 0x2968) = AtapiModeCommandRequestCompletion;
        *(uint *)(uVar3 + 0x1130) = uVar12;
        *(undefined1 *)(uVar3 + 0x1108) = 0x55;
        *(ulonglong *)(uVar3 + 0x2970) = (ulonglong)uVar12;
        bVar4 = (*(byte *)(uVar3 + 0x1109) ^ *(byte *)(local_res18 + 1)) & 1 ^
                *(byte *)(uVar3 + 0x1109) | 0x10;
        *(byte *)(uVar3 + 0x1109) = bVar4;
        bVar11 = *(byte *)(local_res18 + 1);
        *(char *)(uVar3 + 0x1110) = (char)sVar6;
        *(byte *)(uVar3 + 0x1109) = (bVar4 ^ bVar11) & 0x1f ^ bVar11;
        *(char *)(uVar3 + 0x110f) = (char)((ushort)sVar6 >> 8);
        *(undefined1 *)(uVar3 + 0x1111) = *(undefined1 *)(local_res18 + 5);
        *(undefined4 *)(uVar3 + 0x1140) = 1;
        *(undefined4 *)(uVar3 + 0x1150) = (undefined4)local_res20;
        *(undefined4 *)(uVar3 + 0x1154) = local_res20._4_4_;
        *(uint *)(uVar3 + 0x1158) = uVar12;
        *(undefined4 **)(uVar3 + 0x1138) = (undefined4 *)(uVar3 + 0x1140);
        return 0;
      }
      uVar8 = 0xc1000006;
      plVar10 = param_1;
      goto LAB_14001f8f4;
    }
    uVar8 = 0xc1000003;
    *(undefined1 *)(param_2 + 3) = 4;
  }
  if (local_res10 != (void *)0x0) {
    StorPortExtendedFunction(0x53,*param_1,local_res10,uVar12,1,local_res20);
  }
LAB_14001f928:
  *(undefined8 *)(uVar3 + 0x1120) = 0;
  return uVar8;
}



===== AtapiModeSenseRequest @ 14001f94c =====

undefined4 AtapiModeSenseRequest(longlong *param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  undefined4 uVar8;
  short sVar9;
  undefined1 *puVar10;
  undefined8 local_res10;
  void *local_res20;
  
  local_res10 = 0;
  lVar6 = param_2;
  uVar5 = GetSrbExtension(param_2);
  if (*(char *)(lVar6 + 2) == '(') {
    puVar10 = *(undefined1 **)(lVar6 + 0x40);
    uVar7 = *(uint *)(lVar6 + 0x3c);
  }
  else {
    puVar10 = *(undefined1 **)(lVar6 + 0x18);
    uVar7 = *(uint *)(lVar6 + 0x10);
  }
  local_res20 = (void *)0x0;
  if (3 < uVar7) {
    if (puVar10 == (undefined1 *)0x0) {
      *(undefined1 *)(lVar6 + 3) = 6;
      uVar8 = 0xc1000006;
      goto LAB_14001fb3a;
    }
    uVar7 = uVar7 + 4;
    if (7 < uVar7) {
      iVar4 = AhciAllocateDmaBuffer(*param_1,uVar7,&local_res20,&local_res10);
      if ((iVar4 == 0) && (local_res20 != (void *)0x0)) {
        memset(local_res20,0,(ulonglong)uVar7);
        sVar9 = *(byte *)(param_3 + 4) + 4;
        *(undefined1 *)((longlong)local_res20 + 1) = *puVar10;
        *(undefined1 *)((longlong)local_res20 + 2) = puVar10[1];
        *(undefined1 *)((longlong)local_res20 + 7) = puVar10[3];
        *(undefined1 *)(uVar5 + 0x1108) = 0x5a;
        *(byte *)(uVar5 + 0x1109) =
             (*(byte *)(uVar5 + 0x1109) ^ *(byte *)(param_3 + 1)) & 8 ^ *(byte *)(uVar5 + 0x1109);
        bVar1 = *(byte *)(param_3 + 2);
        *(byte *)(uVar5 + 0x110a) =
             (bVar1 ^ *(byte *)(uVar5 + 0x110a)) & 0x3f ^ *(byte *)(uVar5 + 0x110a);
        bVar2 = *(byte *)(param_3 + 2);
        *(char *)(uVar5 + 0x1110) = (char)sVar9;
        *(char *)(uVar5 + 0x110f) = (char)((ushort)sVar9 >> 8);
        *(byte *)(uVar5 + 0x110a) = (bVar1 ^ bVar2) & 0x3f ^ bVar2;
        uVar3 = *(undefined1 *)(param_3 + 5);
        *(uint *)(uVar5 + 0x1104) = *(uint *)(uVar5 + 0x1104) | 0x102;
        *(undefined1 *)(uVar5 + 0x1111) = uVar3;
        *(undefined2 *)(uVar5 + 0x1100) = 0x200;
        *(void **)(uVar5 + 0x1120) = local_res20;
        *(undefined8 *)(uVar5 + 0x1128) = local_res10;
        *(code **)(uVar5 + 0x2968) = AtapiModeCommandRequestCompletion;
        *(ulonglong *)(uVar5 + 0x2970) = (ulonglong)uVar7;
        *(uint *)(uVar5 + 0x1130) = uVar7;
        *(undefined4 *)(uVar5 + 0x1140) = 1;
        *(undefined4 *)(uVar5 + 0x1150) = (undefined4)local_res10;
        *(undefined4 *)(uVar5 + 0x1154) = local_res10._4_4_;
        *(uint *)(uVar5 + 0x1158) = uVar7;
        *(undefined4 **)(uVar5 + 0x1138) = (undefined4 *)(uVar5 + 0x1140);
        return 0;
      }
      *(undefined1 *)(param_2 + 3) = 4;
      uVar8 = 0xc1000003;
      if (local_res20 != (void *)0x0) {
        StorPortExtendedFunction(0x53,*param_1,local_res20,uVar7,1,local_res10);
      }
      goto LAB_14001fb3a;
    }
  }
  *(undefined1 *)(lVar6 + 3) = 6;
  uVar8 = 0xc1000004;
LAB_14001fb3a:
  *(undefined8 *)(uVar5 + 0x1120) = 0;
  return uVar8;
}



===== BuildHybridEvictCommand @ 14001fb64 =====

void BuildHybridEvictCommand(longlong param_1,short param_2)

{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x10) = 1;
  }
  else {
    *(char *)(param_1 + 3) = (char)param_2;
    *(char *)(param_1 + 0xb) = (char)((ushort)param_2 >> 8);
  }
  *(byte *)(param_1 + 7) = *(byte *)(param_1 + 7) | 0x40;
  *(undefined1 *)(param_1 + 0xd) = 1;
  *(undefined1 *)(param_1 + 2) = 100;
  return;
}



===== BuildSanitizeStatusCommand @ 14001fb90 =====

void BuildSanitizeStatusCommand(longlong param_1,char param_2)

{
  undefined8 *puVar1;
  
  *(undefined8 *)(param_1 + 0x1108) = 0;
  *(undefined8 *)(param_1 + 0x1110) = 0;
  puVar1 = *(undefined8 **)(param_1 + 0x2988);
  *puVar1 = 0;
  puVar1[1] = 0;
  *(undefined2 *)(param_1 + 0x1100) = 0x100;
  *(code **)(param_1 + 0x2968) = AtaSanitizeStatusCompletion;
  *(undefined1 *)(param_1 + 0x110e) = 0xb4;
  *(undefined1 *)(param_1 + 0x1108) = 0;
  if (param_2 != '\0') {
    *(undefined1 *)(param_1 + 0x1109) = 1;
    *(code **)(param_1 + 0x2968) = AtaSanitizeStatusClearFailureCompletion;
  }
  *(uint *)(param_1 + 0x1104) = *(uint *)(param_1 + 0x1104) | 0x40;
  *(undefined4 *)(param_1 + 0x2998) = 0x10;
  return;
}



===== ConvertDataSetRangeToAtaLbaRanges @ 14001fc00 =====

ulonglong ConvertDataSetRangeToAtaLbaRanges
                    (ulonglong *param_1,ulonglong *param_2,longlong param_3,uint param_4)

{
  ushort uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar2 = *param_2;
  uVar4 = 0;
  uVar5 = *param_1;
  if (uVar2 != 0) {
    do {
      uVar3 = uVar4 * 8;
      if (param_4 <= uVar3) break;
      uVar1 = 0xffff;
      if (uVar2 < 0x10000) {
        uVar1 = (ushort)uVar2;
      }
      uVar4 = (ulonglong)((int)uVar4 + 1);
      *(ulonglong *)(uVar3 + param_3) =
           (uVar5 ^ *(ulonglong *)(uVar3 + param_3)) & 0xffff000000000000 ^ uVar5;
      uVar5 = uVar5 + uVar1;
      *(ushort *)(uVar3 + 6 + param_3) = uVar1;
      uVar2 = uVar2 - uVar1;
    } while (uVar2 != 0);
  }
  *param_1 = uVar5;
  *param_2 = uVar2;
  return uVar4;
}



===== DsmGeneralIoctlProcess @ 14001fca8 =====

ulonglong DsmGeneralIoctlProcess(longlong *param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_var;
  ulonglong uVar3;
  longlong lVar4;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar4 = *(longlong *)(param_2 + 0x40);
    uVar1 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar4 = *(longlong *)(param_2 + 0x18);
    uVar1 = *(uint *)(param_2 + 0x10);
  }
  uVar3 = (ulonglong)uVar1;
  if ((((0x3b < uVar3) && (lVar4 != 0)) &&
      ((ulonglong)*(uint *)(lVar4 + 0x38) + 0x20 + (ulonglong)*(uint *)(lVar4 + 0x34) <= uVar3)) &&
     (((ulonglong)*(uint *)(lVar4 + 0x30) + 0x20 + (ulonglong)*(uint *)(lVar4 + 0x2c) <= uVar3 &&
      ((ulonglong)*(uint *)(lVar4 + 0x38) + 0x20 + (ulonglong)*(uint *)(lVar4 + 0x30) <= uVar3)))) {
    if (*(int *)(lVar4 + 0x24) == -0x7ffffff2) {
      uVar3 = HybridChangeByLba(param_1,param_2);
      return uVar3;
    }
    if (*(int *)(lVar4 + 0x24) == -0x7ffffff1) {
      iVar2 = HybridEvict(param_1,param_2);
      return CONCAT44(extraout_var,iVar2);
    }
  }
  *(undefined1 *)(param_2 + 3) = 6;
  return 0xc1000004;
}



===== FirmwareGetInfo @ 14001fd48 =====

int FirmwareGetInfo(undefined8 *param_1,longlong param_2)

{
  uint *puVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  uint *_Dst;
  undefined1 uVar7;
  undefined1 uVar8;
  int iVar9;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar6 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar6 = *(longlong *)(param_2 + 0x18);
  }
  if (*(uint *)(lVar6 + 0x30) < 0x18) {
    uVar7 = 0x15;
    *(undefined4 *)(lVar6 + 0x14) = 3;
    uVar8 = 0;
    *(undefined1 *)(param_2 + 3) = 0x15;
    uVar4 = 0;
    iVar9 = -0x3efffffa;
    uVar5 = 0;
  }
  else {
    _Dst = (uint *)((ulonglong)*(uint *)(lVar6 + 0x2c) + lVar6);
    puVar1 = _Dst + 1;
    if ((*_Dst < 2) || (*puVar1 < 0x18)) {
      uVar7 = 0x15;
      iVar9 = -0x3efffffa;
      uVar3 = 3;
    }
    else {
      memset(_Dst,0,(ulonglong)*(uint *)(lVar6 + 0x30));
      *_Dst = 2;
      *puVar1 = 0x18;
      bVar2 = IsFirmwareUpdateSupported((longlong)param_1);
      *(bool *)(_Dst + 2) = bVar2;
      *(undefined4 *)((longlong)_Dst + 9) = 0xff0001;
      _Dst[4] = (uint)*(ushort *)((longlong)param_1 + 0x1c4) << 9;
      _Dst[5] = (uint)*(ushort *)((longlong)param_1 + 0x1c6) << 9;
      if (0x2f < *(uint *)(lVar6 + 0x30)) {
        *(undefined2 *)(_Dst + 6) = 0;
        *(undefined8 *)(_Dst + 8) = *(undefined8 *)((longlong)param_1 + 0x69);
        *(undefined4 *)(lVar6 + 0x14) = 0;
        *(undefined1 *)(param_2 + 3) = 1;
        return 0;
      }
      iVar9 = 0;
      *(undefined4 *)(lVar6 + 0x30) = 0x30;
      uVar7 = 1;
      uVar3 = 5;
    }
    *(undefined4 *)(lVar6 + 0x14) = uVar3;
    *(undefined1 *)(param_2 + 3) = uVar7;
    if (iVar9 == 0) {
      return 0;
    }
    uVar8 = (undefined1)_Dst[2];
    uVar4 = *puVar1;
    uVar5 = *_Dst;
  }
  StorPortExtendedFunction
            (0x57,*param_1,param_1 + 1,0,0xf,L"Get Firmware Info",1,2,0,param_2,L"SrbStatus",uVar7,
             L"Status",iVar9,L"DataBufferLen",*(undefined4 *)(lVar6 + 0x30),L"ReturnCode",
             *(undefined4 *)(lVar6 + 0x14),L"Version",uVar5,L"Size",uVar4,L"UpgradeSupport",uVar8,0,
             0);
  return iVar9;
}



===== FirmwareIoctlProcess @ 14001ff98 =====

int FirmwareIoctlProcess(undefined8 *param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar4 = *(longlong *)(param_2 + 0x40);
    uVar1 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar4 = *(longlong *)(param_2 + 0x18);
    uVar1 = *(uint *)(param_2 + 0x10);
  }
  if (uVar1 < 0x34) {
    uVar5 = 0;
    iVar2 = -0x3efffffa;
    *(undefined4 *)(lVar4 + 0x14) = 3;
    *(undefined1 *)(param_2 + 3) = 0x15;
    uVar3 = 0;
    uVar6 = 0;
    goto LAB_14002004e;
  }
  if ((((ulonglong)uVar1 < (ulonglong)*(uint *)(lVar4 + 0x30) + (ulonglong)*(uint *)(lVar4 + 0x2c))
      || (*(int *)(lVar4 + 0x1c) == 0)) || (*(uint *)(lVar4 + 0x2c) < 0x38)) {
    *(undefined4 *)(lVar4 + 0x14) = 3;
LAB_14002000f:
    *(undefined1 *)(param_2 + 3) = 0x15;
    iVar2 = -0x3efffffa;
  }
  else {
    if (*(int *)(lVar4 + 0x24) != 1) goto LAB_14002000f;
    iVar2 = FirmwareGetInfo(param_1,param_2);
    if (iVar2 == 0) {
      return 0;
    }
  }
  uVar3 = *(undefined4 *)(lVar4 + 0x2c);
  uVar5 = *(undefined4 *)(lVar4 + 0x24);
  uVar6 = *(undefined4 *)(lVar4 + 0x1c);
LAB_14002004e:
  StorPortExtendedFunction
            (0x57,*param_1,param_1 + 1,0,0xe,L"Firmware Ioctl",1,2,0,param_2,L"SrbDataBufLen",
             (ulonglong)uVar1,L"SrbStatus",*(undefined1 *)(param_2 + 3),L"ReturnCode",
             *(undefined4 *)(lVar4 + 0x14),L"FWReqVersion",uVar6,L"FWReqFunction",uVar5,
             L"FWBufOffset",uVar3,L"Status",iVar2,0,0);
  return iVar2;
}



===== GetDevicePhysicalTopologyData @ 140020170 =====

void GetDevicePhysicalTopologyData(longlong *param_1,undefined4 *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ushort uVar3;
  uint *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  puVar4 = (uint *)(param_1 + 3);
  *param_2 = (int)param_1[0x48];
  param_2[1] = 4;
  puVar6 = param_2;
  lVar1 = IsAtaDevice(puVar4);
  uVar5 = 0;
  if ((((char)lVar1 == '\0') && (*puVar4 != 2)) || ((param_1[0x4a] & 1U) == 0)) {
    param_2[2] = 0;
  }
  else {
    uVar5 = 0;
    uVar2 = IsNCQSupported(param_1);
    if (((char)uVar2 == '\0') || ((param_1[0x4a] & 0x10U) != 0)) {
      puVar6[2] = 1;
    }
    else {
      puVar6[2] = 2;
    }
  }
  puVar6[3] = 2;
  *(undefined2 *)((longlong)puVar6 + 0x12) = *(undefined2 *)(param_1[0x18] + 0xa0);
  *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(param_1[0x18] + 0xa2);
  uVar3 = *(ushort *)(param_1[0x18] + 0x150) & 0xf;
  if ((uVar3 == 1) || (uVar3 == 2)) {
    uVar5 = 1;
  }
  else if (uVar3 == 3) {
    uVar5 = 2;
  }
  else if (uVar3 == 4) {
    uVar5 = 3;
  }
  else if (uVar3 == 5) {
    uVar5 = 4;
  }
  else if (uVar3 == 6) {
    uVar5 = 7;
  }
  else if (uVar3 == 7) {
    uVar5 = 8;
  }
  else if (uVar3 == 8) {
    uVar5 = 5;
  }
  else if (uVar3 == 9) {
    uVar5 = 6;
  }
  puVar6[5] = uVar5;
  puVar6[6] = 0x415441;
  lVar1 = param_1[9];
  *(longlong *)(puVar6 + 8) = param_1[8];
  *(longlong *)(puVar6 + 10) = lVar1;
  lVar1 = param_1[0xb];
  *(longlong *)(puVar6 + 0xc) = param_1[10];
  *(longlong *)(puVar6 + 0xe) = lVar1;
  *(longlong *)(puVar6 + 0x10) = param_1[0xc];
  *(undefined8 *)(puVar6 + 0x12) = *(undefined8 *)((longlong)param_1 + 0x69);
  *(ulonglong *)(puVar6 + 0x16) =
       ((ulonglong)param_1[7] >> 10) * (ulonglong)*(uint *)((longlong)param_1 + 0x24);
  return;
}



===== GetFirmwareUpdateCommand @ 1400202d4 =====

char GetFirmwareUpdateCommand(longlong param_1)

{
  if ((*(ushort *)(*(longlong *)(param_1 + 0xc0) + 0x8a) >> 8 & 1) == 0) {
    return (-((*(byte *)(*(longlong *)(param_1 + 0xc0) + 0xa6) & 1) != 0) & 0x93U) - 1;
  }
  return -0x6d;
}



===== GetHybridMaxLbaRangeCountForChangeLba @ 140020304 =====

int GetHybridMaxLbaRangeCountForChangeLba(longlong param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x268);
  if (iVar1 == 0) {
    iVar1 = (-(uint)((*(byte *)(param_1 + 0x18a) & 2) != 0) & 0x38) + 8;
  }
  return iVar1;
}



===== HybridChangeByLba @ 140020328 =====

undefined8 HybridChangeByLba(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  lVar9 = param_2;
  uVar5 = GetSrbExtension(param_2);
  uVar12 = (ulonglong)*(uint *)((longlong)param_1 + 0x24);
  if (*(char *)(lVar9 + 2) == '(') {
    lVar11 = *(longlong *)(lVar9 + 0x40);
  }
  else {
    lVar11 = *(longlong *)(lVar9 + 0x18);
  }
  lVar1 = lVar11 + 0x20;
  uVar13 = (ulonglong)*(uint *)(lVar11 + 0x2c);
  lVar2 = (ulonglong)*(uint *)(lVar11 + 0x34) + lVar1;
  if (*(uint *)(lVar11 + 0x30) < 8) {
    *(undefined4 *)(lVar11 + 0x14) = 2;
    *(undefined1 *)(lVar9 + 3) = 0x15;
  }
  else {
    lVar9 = lVar11;
    if ((0x1b < *(uint *)(lVar11 + 0x34)) && (uVar4 = *(uint *)(lVar11 + 0x38), 0xf < uVar4)) {
      plVar8 = param_1;
      uVar3 = GetHybridMaxLbaRangeCountForChangeLba((longlong)param_1);
      if (uVar4 >> 4 <= uVar3) {
        if ((*(byte *)((longlong)param_1 + 0x187) & 0xf) < *(byte *)(uVar13 + 4 + lVar1)) {
          *(undefined4 *)(lVar9 + 0x14) = 2;
          *(undefined1 *)(param_2 + 3) = 0x15;
          goto LAB_140020558;
        }
        uVar6 = IsNCQSupported(plVar8);
        if (((char)uVar6 != '\0') && ((param_1[0x4a] & 0x10U) != 0)) {
          plVar8 = param_1;
          uVar6 = IsDeviceHybridInfoSupported((longlong)param_1);
          if (((char)uVar6 != '\0') &&
             (((uVar4 = IsDeviceHybridInfoEnabled((longlong)plVar8), (char)uVar4 != '\0' &&
               ((*(uint *)(param_1 + 0x2e) & 2) != 0)) && ((int)uVar12 != 0)))) {
            if (*(ulonglong *)(lVar2 + 8) / uVar12 == 0) {
              *(undefined1 *)(param_2 + 3) = 1;
            }
            else {
              StorPortExtendedFunction(0,*param_1,0x30,0x69636841,&local_res8);
              if (local_res8 == (longlong *)0x0) {
                *(undefined1 *)(param_2 + 3) = 6;
                uVar10 = 0xc1000003;
                goto LAB_14002055d;
              }
              uVar6 = 0;
              *local_res8 = 0;
              local_res8[1] = 0;
              local_res8[2] = 0;
              local_res8[3] = 0;
              local_res8[4] = 0;
              local_res8[5] = 0;
              *(undefined1 *)(local_res8 + 5) = *(undefined1 *)(uVar13 + 4 + lVar1);
              *local_res8 = lVar2;
              uVar4 = *(uint *)(lVar11 + 0x38) >> 4;
              *(uint *)(local_res8 + 1) = uVar4;
              if (uVar4 != 0) {
                do {
                  uVar7 = *(ulonglong *)(lVar2 + 8 + uVar6 * 0x10) / uVar12;
                  if (uVar7 != 0) {
                    *(int *)((longlong)local_res8 + 0xc) =
                         *(int *)((longlong)local_res8 + 0xc) + (int)((uVar7 - 1) / 0xffff) + 1;
                  }
                  uVar4 = (int)uVar6 + 1;
                  uVar6 = (ulonglong)uVar4;
                } while (uVar4 < *(uint *)(local_res8 + 1));
              }
              *(undefined2 *)(uVar5 + 0x1100) = 0x400;
              *(code **)(uVar5 + 0x2968) = HybridChangeByLbaCompletion;
              *(longlong **)(uVar5 + 0x2970) = local_res8;
              HybridChangeByLbaCompletion(param_1,param_2);
            }
            uVar10 = 0;
            goto LAB_14002055d;
          }
        }
      }
    }
    *(undefined4 *)(lVar9 + 0x14) = 1;
    *(undefined1 *)(param_2 + 3) = 0x22;
  }
LAB_140020558:
  uVar10 = 0xc1000006;
LAB_14002055d:
  if ((*(char *)(param_2 + 3) != '\0') && (*(char *)(*param_1 + 0x18e) != '\0')) {
    StorPortExtendedFunction
              (0x56,*param_1,param_1 + 1,0,9,L"Hybrid Change By LBA",1,4,0,param_2,L"Srb Status",
               *(char *)(param_2 + 3),L"Device CMD Sent",0,L"Target Priority",
               *(undefined1 *)(uVar13 + 4 + lVar1),L"LBA Range Count",*(uint *)(lVar11 + 0x38) >> 4)
    ;
  }
  return uVar10;
}



===== HybridChangeByLbaCompletion @ 140020650 =====

void HybridChangeByLbaCompletion(longlong *param_1,longlong param_2)

{
  ulonglong *puVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  code *pcVar8;
  longlong *plVar9;
  byte bVar10;
  ulonglong local_res8;
  
  uVar6 = GetSrbExtension(param_2);
  bVar10 = *(byte *)(param_2 + 3);
  pcVar8 = (code *)0x0;
  uVar3 = *(uint *)((longlong)param_1 + 0x24);
  local_res8 = 0;
  plVar9 = *(longlong **)(uVar6 + 0x2970);
  if ((bVar10 < 2) && (*(uint *)(plVar9 + 2) < *(uint *)((longlong)plVar9 + 0xc))) {
    if (uVar3 != 0) {
      puVar1 = (ulonglong *)(plVar9 + 4);
      if (*puVar1 == 0) {
        uVar4 = *(uint *)((longlong)plVar9 + 0x14);
        plVar9[3] = *(longlong *)(*plVar9 + (ulonglong)uVar4 * 0x10) / (longlong)(ulonglong)uVar3;
        *puVar1 = *(ulonglong *)(*plVar9 + 8 + (ulonglong)uVar4 * 0x10) / (ulonglong)uVar3;
        *(uint *)((longlong)plVar9 + 0x14) = uVar4 + 1;
      }
      uVar7 = ConvertDataSetRangeToAtaLbaRanges
                        ((ulonglong *)(plVar9 + 3),puVar1,(longlong)&local_res8,8);
      *(int *)(plVar9 + 2) = (int)plVar9[2] + (int)uVar7;
      *(undefined8 *)(uVar6 + 0x1108) = 0;
      *(undefined8 *)(uVar6 + 0x1110) = 0;
      *(undefined4 *)(uVar6 + 0x1118) = 0;
      bVar10 = *(byte *)((longlong)param_1 + 0x18a);
      uVar7 = local_res8 & 0xffffffffffff;
      bVar2 = *(byte *)(plVar9 + 5);
      *(undefined1 *)(uVar6 + 0x110b) = 3;
      if ((bVar10 & 2) != 0) {
        *(undefined1 *)(uVar6 + 0x110b) = 0x13;
      }
      *(char *)(uVar6 + 0x1113) = (char)(local_res8 >> 0x30);
      pcVar8 = HybridChangeByLbaCompletion;
      *(char *)(uVar6 + 0x110d) = (char)(uVar7 >> 8);
      *(char *)(uVar6 + 0x110e) = (char)(uVar7 >> 0x10);
      *(char *)(uVar6 + 0x1110) = (char)(uVar7 >> 0x18);
      *(char *)(uVar6 + 0x110c) = (char)uVar7;
      *(byte *)(uVar6 + 0x110f) = *(byte *)(uVar6 + 0x110f) | 0x40;
      *(byte *)(uVar6 + 0x111a) = bVar2 & 0xf | 0x20;
      uVar5 = 0x400;
      *(char *)(uVar6 + 0x1111) = (char)(uVar7 >> 0x20);
      *(char *)(uVar6 + 0x1115) = (char)(local_res8 >> 0x38);
      *(char *)(uVar6 + 0x1112) = (char)(uVar7 >> 0x28);
      *(undefined1 *)(uVar6 + 0x110a) = 99;
      goto LAB_1400208a5;
    }
    bVar10 = 0x20;
    *(undefined1 *)(param_2 + 3) = 0x20;
  }
  if (*(char *)(*param_1 + 0x18e) != '\0') {
    StorPortExtendedFunction
              (0x56,*param_1,param_1 + 1,0,9,L"Hybrid Change By LBA",1,4,0,param_2,L"Srb Status",
               bVar10,L"Device CMD Sent",1,L"Target Priority",(char)plVar9[5],L"LBA Range Count",
               (int)plVar9[1]);
  }
  if (plVar9 != (longlong *)0x0) {
    StorPortExtendedFunction(1,*param_1,plVar9);
  }
  uVar5 = 0;
  plVar9 = (longlong *)0x0;
LAB_1400208a5:
  *(code **)(uVar6 + 0x2968) = pcVar8;
  *(longlong **)(uVar6 + 0x2970) = plVar9;
  *(undefined2 *)(uVar6 + 0x1100) = uVar5;
  return;
}



===== HybridControlCachingMediumCompletion @ 1400208e0 =====

void HybridControlCachingMediumCompletion(longlong *param_1,longlong param_2)

{
  ushort *puVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
  
  uVar3 = GetSrbExtension(param_2);
  if (((*(char *)(uVar3 + 0x110a) == -0x11) && (*(char *)(uVar3 + 0x110b) == '\x10')) &&
     (*(char *)(uVar3 + 0x1114) == '\n')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (*(char *)(*param_1 + 0x18e) != '\0') {
    if (bVar2) {
      pwVar5 = L"Hybrid Caching Medium Enable";
      uVar4 = 7;
    }
    else {
      pwVar5 = L"Hybrid Caching Medium Disable";
      uVar4 = 8;
    }
    StorPortExtendedFunction
              (0x56,*param_1,param_1 + 1,0,uVar4,pwVar5,1,4,0,param_2,L"Srb Status",
               *(undefined1 *)(param_2 + 3),L"Device CMD Sent",1,L"Post-RefCount",
               (longlong)(int)param_1[0x38],0,0);
  }
  if (*(char *)(param_2 + 3) == '\x01') {
    if (bVar2) {
      puVar1 = (ushort *)(param_1[0x18] + 0x9e);
      *puVar1 = *puVar1 | 0x200;
    }
    else {
      puVar1 = (ushort *)(param_1[0x18] + 0x9e);
      *puVar1 = *puVar1 & 0xfdff;
    }
  }
  return;
}



===== HybridDemoteBySize @ 140020a38 =====

undefined8 HybridDemoteBySize(longlong *param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  char cVar5;
  undefined8 uVar6;
  byte bVar7;
  byte bVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *plVar11;
  
  bVar7 = 0;
  cVar5 = *(char *)(param_2 + 2);
  bVar8 = 0;
  lVar9 = 0;
  if (cVar5 == '(') {
    lVar10 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar10 = *(longlong *)(param_2 + 0x18);
  }
  uVar3 = GetSrbExtension(param_2);
  uVar4 = (ulonglong)*(uint *)(lVar10 + 0x2c);
  if (*(uint *)(lVar10 + 0x2c) < 0x34) {
LAB_140020a83:
    *(undefined4 *)(lVar10 + 0x14) = 2;
    *(undefined1 *)(param_2 + 3) = 0x15;
    plVar11 = param_1;
  }
  else {
    if (cVar5 == '(') {
      uVar2 = *(uint *)(param_2 + 0x3c);
    }
    else {
      uVar2 = *(uint *)(param_2 + 0x10);
    }
    if ((uVar2 < 0x4c) || (*(uint *)(lVar10 + 0x30) < 0x18)) {
      *(undefined4 *)(lVar10 + 0x14) = 3;
      uVar6 = 0xc1000004;
      *(undefined4 *)(lVar10 + 0x30) = 0x18;
      *(undefined1 *)(param_2 + 3) = 0x12;
      goto LAB_140020bd4;
    }
    bVar7 = *(byte *)(uVar4 + 8 + lVar10);
    bVar1 = *(byte *)((longlong)param_1 + 0x187) & 0xf;
    bVar8 = *(byte *)(uVar4 + 9 + lVar10);
    lVar9 = *(longlong *)(uVar4 + 0x10 + lVar10);
    if ((((bVar1 < bVar7) || (bVar1 < bVar8)) || (bVar7 <= bVar8)) || (lVar9 == 0))
    goto LAB_140020a83;
    uVar4 = IsNCQSupported(param_1);
    plVar11 = param_1;
    if (((char)uVar4 != '\0') && ((param_1[0x4a] & 0x10U) != 0)) {
      uVar4 = IsDeviceHybridInfoSupported((longlong)param_1);
      if ((char)uVar4 != '\0') {
        uVar2 = IsDeviceHybridInfoEnabled((longlong)param_1);
        if (((char)uVar2 != '\0') && ((*(uint *)(plVar11 + 0x2e) & 1) != 0)) {
          *(byte *)(uVar3 + 0x110f) = *(byte *)(uVar3 + 0x110f) | 0x40;
          *(char *)(uVar3 + 0x1113) = (char)lVar9;
          *(byte *)(uVar3 + 0x110b) = bVar7 << 4 | 2;
          *(char *)(uVar3 + 0x1115) = (char)((ulonglong)lVar9 >> 8);
          *(char *)(uVar3 + 0x110c) = (char)((ulonglong)lVar9 >> 0x10);
          *(char *)(uVar3 + 0x110d) = (char)((ulonglong)lVar9 >> 0x18);
          *(undefined1 *)(uVar3 + 0x110a) = 99;
          *(undefined2 *)(uVar3 + 0x1100) = 0x400;
          *(byte *)(uVar3 + 0x111a) = bVar8 & 0xf | 0x20;
          if (*(char *)(*plVar11 + 0x18e) != '\0') {
            *(code **)(uVar3 + 0x2968) = HybridDemoteBySizeCompletion;
          }
          uVar6 = 0;
          param_1 = plVar11;
          goto LAB_140020bd4;
        }
      }
    }
    *(undefined4 *)(lVar10 + 0x14) = 1;
    *(undefined1 *)(param_2 + 3) = 0x22;
  }
  uVar6 = 0xc1000006;
  param_1 = plVar11;
LAB_140020bd4:
  if ((*(char *)(param_2 + 3) != '\0') && (*(char *)(*param_1 + 0x18e) != '\0')) {
    StorPortExtendedFunction
              (0x57,*param_1,param_1 + 1,0,10,L"Hybrid Demote By Size",1,4,0,param_2,L"Srb Status",
               *(char *)(param_2 + 3),L"Device CMD Sent",0,L"Source Priority",bVar7,
               L"Target Priority",bVar8,L"LBA Count",lVar9,0,0,0,0,0,0);
  }
  return uVar6;
}



===== HybridDemoteBySizeCompletion @ 140020d00 =====

void HybridDemoteBySizeCompletion(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(char *)(*param_1 + 0x18e) != '\0') {
    if (*(char *)(param_2 + 2) == '(') {
      lVar1 = *(longlong *)(param_2 + 0x40);
    }
    else {
      lVar1 = *(longlong *)(param_2 + 0x18);
    }
    lVar1 = (ulonglong)*(uint *)(lVar1 + 0x2c) + lVar1;
    StorPortExtendedFunction
              (0x57,*param_1,param_1 + 1,0,10,L"Hybrid Demote By Size",1,4,0,param_2,L"Srb Status",
               *(undefined1 *)(param_2 + 3),L"Device CMD Sent",1,L"Source Priority",
               *(undefined1 *)(lVar1 + 8),L"Target Priority",*(undefined1 *)(lVar1 + 9),L"LBA Count"
               ,*(undefined8 *)(lVar1 + 0x10),0,0,0,0,0,0);
  }
  return;
}



===== HybridDisableCachingMedium @ 140020e38 =====

undefined8 HybridDisableCachingMedium(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong lVar8;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar8 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar8 = *(longlong *)(param_2 + 0x18);
  }
  uVar4 = GetSrbExtension(param_2);
  uVar5 = IsNCQSupported(param_1);
  plVar7 = param_1;
  if (((char)uVar5 != '\0') && ((param_1[0x4a] & 0x10U) != 0)) {
    uVar5 = IsDeviceHybridInfoSupported((longlong)param_1);
    if (((char)uVar5 != '\0') && ((*(uint *)(plVar7 + 0x2e) & 4) != 0)) {
      uVar3 = IsDeviceHybridInfoEnabled((longlong)param_1);
      if ((char)uVar3 == '\0') {
        *(undefined1 *)(param_2 + 3) = 1;
      }
      else {
        LOCK();
        plVar1 = plVar7 + 0x38;
        lVar2 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if (1 < (int)lVar2) {
          *(undefined4 *)(lVar8 + 0x14) = 0x10;
          uVar6 = 0xc1000001;
          *(undefined1 *)(param_2 + 3) = 2;
          goto LAB_140020f17;
        }
        if ((int)lVar2 + -1 < 0) {
          LOCK();
          *(int *)(plVar7 + 0x38) = (int)plVar7[0x38] + 1;
          UNLOCK();
        }
        *(byte *)(uVar4 + 0x110f) = *(byte *)(uVar4 + 0x110f) | 0x40;
        *(code **)(uVar4 + 0x2968) = HybridControlCachingMediumCompletion;
        *(undefined2 *)(uVar4 + 0x110a) = 0x8463;
        *(undefined2 *)(uVar4 + 0x1100) = 0x400;
      }
      uVar6 = 0;
      goto LAB_140020f17;
    }
  }
  *(undefined4 *)(lVar8 + 0x14) = 1;
  uVar6 = 0xc1000006;
  *(undefined1 *)(param_2 + 3) = 0x22;
LAB_140020f17:
  if ((*(char *)(param_2 + 3) != '\0') && (*(char *)(*plVar7 + 0x18e) != '\0')) {
    StorPortExtendedFunction
              (0x56,*plVar7,plVar7 + 1,0,8,L"Hybrid Caching Medium Disable",1,4,0,param_2,
               L"Srb Status",*(char *)(param_2 + 3),L"Device CMD Sent",0,L"Post-RefCount",
               (longlong)(int)plVar7[0x38],0,0);
  }
  return uVar6;
}



===== HybridEnableCachingMedium @ 140020fdc =====

undefined8 HybridEnableCachingMedium(longlong *param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong *plVar6;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar4 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar4 = *(longlong *)(param_2 + 0x18);
  }
  uVar2 = GetSrbExtension(param_2);
  uVar3 = IsNCQSupported(param_1);
  plVar6 = param_1;
  if (((char)uVar3 != '\0') && ((param_1[0x4a] & 0x10U) != 0)) {
    uVar3 = IsDeviceHybridInfoSupported((longlong)param_1);
    if (((char)uVar3 != '\0') && ((*(uint *)(plVar6 + 0x2e) & 4) != 0)) {
      LOCK();
      *(int *)(plVar6 + 0x38) = (int)plVar6[0x38] + 1;
      UNLOCK();
      uVar1 = IsDeviceHybridInfoEnabled((longlong)param_1);
      uVar5 = 0;
      if ((char)uVar1 == '\0') {
        *(undefined2 *)(uVar2 + 0x110a) = 0x10ef;
        *(code **)(uVar2 + 0x2968) = HybridControlCachingMediumCompletion;
        *(undefined1 *)(uVar2 + 0x1114) = 10;
        *(undefined2 *)(uVar2 + 0x1100) = 0x400;
      }
      else {
        *(undefined1 *)(param_2 + 3) = 1;
      }
      goto LAB_14002108c;
    }
  }
  *(undefined4 *)(lVar4 + 0x14) = 1;
  uVar5 = 0xc1000006;
  *(undefined1 *)(param_2 + 3) = 0x22;
LAB_14002108c:
  if ((*(char *)(param_2 + 3) != '\0') && (*(char *)(*plVar6 + 0x18e) != '\0')) {
    StorPortExtendedFunction
              (0x56,*plVar6,plVar6 + 1,0,7,L"Hybrid Caching Medium Enable",1,4,0,param_2,
               L"Srb Status",*(char *)(param_2 + 3),L"Device CMD Sent",0,L"Post-RefCount",
               (longlong)(int)plVar6[0x38],0,0);
  }
  return uVar5;
}



===== HybridEvict @ 140021150 =====

int HybridEvict(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *local_res8;
  undefined8 local_res10;
  longlong local_res18 [2];
  
  lVar9 = param_2;
  uVar4 = GetSrbExtension(param_2);
  local_res8 = (longlong *)0x0;
  local_res18[0] = 0;
  local_res10 = 0;
  uVar3 = *(uint *)((longlong)param_1 + 0x24);
  if (*(char *)(lVar9 + 2) == '(') {
    lVar10 = *(longlong *)(lVar9 + 0x40);
  }
  else {
    lVar10 = *(longlong *)(lVar9 + 0x18);
  }
  lVar1 = lVar10 + 0x20 + (ulonglong)*(uint *)(lVar10 + 0x34);
  if (((*(uint *)(lVar10 + 0x28) & 1) == 0) &&
     ((*(uint *)(lVar10 + 0x34) < 0x1c || (*(uint *)(lVar10 + 0x38) < 0x10)))) {
    *(undefined4 *)(lVar10 + 0x14) = 1;
    *(undefined1 *)(lVar9 + 3) = 0x22;
  }
  else {
    lVar9 = lVar10;
    uVar5 = IsNCQSupported(param_1);
    if (((char)uVar5 != '\0') && ((param_1[0x4a] & 0x10U) != 0)) {
      plVar7 = param_1;
      uVar5 = IsDeviceHybridInfoSupported((longlong)param_1);
      if (((char)uVar5 != '\0') &&
         ((((uVar2 = IsDeviceHybridInfoEnabled((longlong)plVar7), (char)uVar2 != '\0' &&
            ((*(uint *)(param_1 + 0x2e) & 8) != 0)) && (uVar3 != 0)) &&
          ((*(uint *)(lVar10 + 0x28) & 1) == 0)))) {
        StorPortExtendedFunction(0,*param_1,0x30,0x69636841,&local_res8);
        if (local_res8 == (longlong *)0x0) {
          *(undefined1 *)(param_2 + 3) = 6;
          iVar8 = -0x3efffffd;
        }
        else {
          *local_res8 = 0;
          local_res8[1] = 0;
          local_res8[2] = 0;
          local_res8[3] = 0;
          local_res8[4] = 0;
          local_res8[5] = 0;
          *local_res8 = lVar1;
          *(uint *)(local_res8 + 1) = *(uint *)(lVar10 + 0x38) >> 4;
          *(uint *)((longlong)local_res8 + 0xc) = (uint)*(ushort *)((longlong)param_1 + 0x1a2) << 6;
          if (*(int *)((longlong)local_res8 + 0xc) == 0) {
            *(undefined4 *)((longlong)local_res8 + 0xc) = 0x40;
          }
          uVar5 = 0;
          if ((int)local_res8[1] != 0) {
            do {
              uVar6 = *(ulonglong *)(lVar1 + 8 + uVar5 * 0x10) / (ulonglong)uVar3;
              if (uVar6 != 0) {
                *(int *)(local_res8 + 2) = (int)local_res8[2] + (int)((uVar6 - 1) / 0xffff) + 1;
              }
              uVar2 = (int)uVar5 + 1;
              uVar5 = (ulonglong)uVar2;
            } while (uVar2 < *(uint *)(local_res8 + 1));
          }
          uVar3 = *(uint *)((longlong)local_res8 + 0xc);
          if (*(uint *)(local_res8 + 2) < *(uint *)((longlong)local_res8 + 0xc)) {
            uVar3 = *(uint *)(local_res8 + 2);
          }
          iVar8 = (uVar3 * 8 - 1 & 0xfffffe00) + 0x200;
          *(int *)((longlong)local_res8 + 0x14) = iVar8;
          if (iVar8 == 0) {
            *(undefined1 *)(param_2 + 3) = 1;
          }
          else {
            iVar8 = AhciAllocateDmaBuffer(*param_1,iVar8,local_res18,&local_res10);
            if ((iVar8 != 0) || (local_res18[0] == 0)) {
              *(undefined1 *)(param_2 + 3) = 6;
              if (iVar8 == 0) {
                iVar8 = -0x3efffffd;
              }
              goto LAB_1400213ff;
            }
            *(uint *)(uVar4 + 0x1104) = *(uint *)(uVar4 + 0x1104) | 4;
            *(undefined2 *)(uVar4 + 0x1100) = 0x400;
            *(longlong *)(uVar4 + 0x1120) = local_res18[0];
            *(undefined8 *)(uVar4 + 0x1128) = local_res10;
            *(undefined4 *)(uVar4 + 0x1130) = *(undefined4 *)((longlong)local_res8 + 0x14);
            *(undefined4 *)(uVar4 + 0x1140) = 1;
            *(longlong **)(uVar4 + 0x2970) = local_res8;
            *(undefined4 *)(uVar4 + 0x1150) = (undefined4)local_res10;
            *(undefined4 *)(uVar4 + 0x1154) = local_res10._4_4_;
            *(undefined4 *)(uVar4 + 0x1158) = *(undefined4 *)((longlong)local_res8 + 0x14);
            *(undefined4 **)(uVar4 + 0x1138) = (undefined4 *)(uVar4 + 0x1140);
            HybridEvictCompletion(param_1,param_2);
          }
          iVar8 = 0;
        }
        goto LAB_1400213ff;
      }
    }
    *(undefined4 *)(lVar9 + 0x14) = 1;
    *(undefined1 *)(param_2 + 3) = 0x22;
  }
  iVar8 = -0x3efffffa;
LAB_1400213ff:
  if ((*(char *)(param_2 + 3) != '\0') && (*(char *)(*param_1 + 0x18e) != '\0')) {
    StorPortExtendedFunction
              (0x56,*param_1,param_1 + 1,0,0xb,L"Hybrid Evict",1,4,0,param_2,L"Srb Status",
               *(char *)(param_2 + 3),L"Device CMD Sent",0,L"Evict All",*(uint *)(lVar10 + 0x28) & 1
               ,L"LBA Range Count",*(uint *)(lVar10 + 0x38) >> 4);
  }
  if (iVar8 != 0) {
    if (local_res18[0] != 0) {
      StorPortExtendedFunction
                (0x53,*param_1,local_res18[0],*(undefined4 *)((longlong)local_res8 + 0x14),1,
                 local_res10);
    }
    if (local_res8 != (longlong *)0x0) {
      StorPortExtendedFunction(1,*param_1);
    }
  }
  return iVar8;
}



===== HybridEvictCompletion @ 140021540 =====

void HybridEvictCompletion(longlong *param_1,longlong param_2)

{
  ulonglong *puVar1;
  uint uVar2;
  longlong *plVar3;
  void *_Dst;
  ulonglong uVar4;
  ulonglong uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  uVar4 = GetSrbExtension(param_2);
  bVar6 = *(byte *)(param_2 + 3);
  uVar2 = *(uint *)((longlong)param_1 + 0x24);
  uVar10 = 0;
  plVar3 = *(longlong **)(uVar4 + 0x2970);
  _Dst = *(void **)(uVar4 + 0x1120);
  if ((bVar6 < 2) && (*(uint *)(plVar3 + 3) < *(uint *)(plVar3 + 2))) {
    if (uVar2 != 0) {
      if (*(uint *)((longlong)plVar3 + 0x14) != 0) {
        memset(_Dst,0,(ulonglong)*(uint *)((longlong)plVar3 + 0x14));
      }
      uVar7 = *(uint *)(plVar3 + 2) - *(uint *)(plVar3 + 3);
      uVar8 = *(uint *)((longlong)plVar3 + 0xc);
      if (uVar7 < *(uint *)((longlong)plVar3 + 0xc)) {
        uVar8 = uVar7;
      }
      uVar8 = (uVar8 * 8 - 1 & 0xfffffe00) + 0x200;
      if (*(uint *)(plVar3 + 2) <= *(uint *)(plVar3 + 3)) {
        return;
      }
      do {
        puVar1 = (ulonglong *)(plVar3 + 5);
        if (*puVar1 == 0) {
          uVar7 = *(uint *)((longlong)plVar3 + 0x1c);
          plVar3[4] = *(longlong *)(*plVar3 + (ulonglong)uVar7 * 0x10) / (longlong)(ulonglong)uVar2;
          *puVar1 = *(ulonglong *)(*plVar3 + 8 + (ulonglong)uVar7 * 0x10) / (ulonglong)uVar2;
          *(uint *)((longlong)plVar3 + 0x1c) = uVar7 + 1;
        }
        uVar5 = ConvertDataSetRangeToAtaLbaRanges
                          ((ulonglong *)(plVar3 + 4),puVar1,uVar10 + (longlong)_Dst,
                           uVar8 - (int)uVar10);
        uVar7 = (int)plVar3[3] + (int)uVar5;
        *(uint *)(plVar3 + 3) = uVar7;
        uVar9 = (int)uVar10 + (int)uVar5 * 8;
        uVar10 = (ulonglong)uVar9;
      } while ((uVar9 != uVar8) && (uVar7 < *(uint *)(plVar3 + 2)));
      *(undefined8 *)(uVar4 + 0x1108) = 0;
      *(undefined8 *)(uVar4 + 0x1110) = 0;
      *(undefined4 *)(uVar4 + 0x1118) = 0;
      BuildHybridEvictCommand((longlong)(uVar4 + 0x1108),(short)(uVar8 >> 9));
      *(undefined2 *)(uVar4 + 0x1100) = 0x400;
      *(code **)(uVar4 + 0x2968) = HybridEvictCompletion;
      *(void **)(uVar4 + 0x1120) = _Dst;
      *(longlong **)(uVar4 + 0x2970) = plVar3;
      *(uint *)(uVar4 + 0x1158) = uVar8;
      *(uint *)(uVar4 + 0x1130) = uVar8;
      return;
    }
    bVar6 = 0x20;
    *(undefined1 *)(param_2 + 3) = 0x20;
  }
  if (*(char *)(*param_1 + 0x18e) != '\0') {
    StorPortExtendedFunction
              (0x56,*param_1,param_1 + 1,0,0xb,L"Hybrid Evict",1,4,0,param_2,L"Srb Status",bVar6,
               L"Device CMD Sent",1,L"Evict All",0,L"LBA Range Count",(int)plVar3[1]);
  }
  if (_Dst != (void *)0x0) {
    StorPortExtendedFunction
              (0x53,*param_1,_Dst,*(undefined4 *)((longlong)plVar3 + 0x14),1,
               *(undefined8 *)(uVar4 + 0x1128));
  }
  if (plVar3 != (longlong *)0x0) {
    StorPortExtendedFunction(1,*param_1,plVar3);
  }
  *(undefined8 *)(uVar4 + 0x1120) = 0;
  *(undefined8 *)(uVar4 + 0x2970) = 0;
  *(undefined8 *)(uVar4 + 0x2968) = 0;
  *(undefined2 *)(uVar4 + 0x1100) = 0;
  return;
}



===== HybridGetInfo @ 1400217e4 =====

undefined4 HybridGetInfo(longlong *param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  undefined4 uVar8;
  void *local_res10;
  undefined8 local_res18;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar5 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar5 = *(longlong *)(param_2 + 0x18);
  }
  uVar7 = (ulonglong)*(uint *)(lVar5 + 0x2c);
  if (*(uint *)(lVar5 + 0x2c) < 0x34) {
    *(undefined4 *)(lVar5 + 0x14) = 2;
    uVar6 = 0xc1000006;
    *(undefined1 *)(param_2 + 3) = 0x15;
  }
  else {
    if (*(char *)(param_2 + 2) == '(') {
      uVar1 = *(uint *)(param_2 + 0x3c);
    }
    else {
      uVar1 = *(uint *)(param_2 + 0x10);
    }
    uVar8 = 0x48;
    if ((uVar1 < 0x7c) || (*(uint *)(lVar5 + 0x30) < 0x48)) {
      *(undefined4 *)(lVar5 + 0x14) = 3;
      uVar6 = 0xc1000004;
      *(undefined4 *)(lVar5 + 0x30) = 0x48;
      *(undefined1 *)(param_2 + 3) = 0x12;
    }
    else {
      plVar4 = param_1;
      uVar3 = IsDeviceHybridInfoSupported((longlong)param_1);
      if ((char)uVar3 == '\0') {
        *(undefined4 *)(uVar7 + lVar5) = 1;
        uVar6 = 0;
        *(undefined4 *)(uVar7 + 4 + lVar5) = uVar8;
        *(undefined1 *)(uVar7 + 8 + lVar5) = 0;
        *(undefined1 *)(param_2 + 3) = 1;
      }
      else {
        local_res10 = (void *)0x0;
        local_res18 = 0;
        iVar2 = AhciAllocateDmaBuffer(*plVar4,0x200,&local_res10,&local_res18);
        if ((iVar2 == 0) && (local_res10 != (void *)0x0)) {
          memset(local_res10,0,0x200);
          IssueReadLogExtCommand
                    ((longlong)param_1,param_2,0x14,0,1,0,&local_res18,local_res10,
                     HybridInfoCompletion);
          uVar6 = 0;
        }
        else {
          *(undefined1 *)(param_2 + 3) = 4;
          uVar6 = 0xc1000003;
        }
      }
    }
  }
  if ((*(char *)(param_2 + 3) != '\0') && (*(char *)(*param_1 + 0x18e) != '\0')) {
    IsDeviceHybridInfoSupported((longlong)param_1);
    StorPortExtendedFunction(0x57);
  }
  return uVar6;
}



===== HybridInfoCompletion @ 140021a70 =====

void HybridInfoCompletion(longlong *param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  ushort *puVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined4 *puVar11;
  ushort uVar12;
  uint *puVar13;
  uint *puVar14;
  undefined8 uVar15;
  
  lVar9 = param_2;
  uVar5 = GetSrbExtension(param_2);
  if (*(char *)(lVar9 + 2) == '(') {
    lVar10 = *(longlong *)(lVar9 + 0x40);
  }
  else {
    lVar10 = *(longlong *)(lVar9 + 0x18);
  }
  puVar3 = *(ushort **)(uVar5 + 0x1120);
  puVar11 = (undefined4 *)((ulonglong)*(uint *)(lVar10 + 0x2c) + lVar10);
  if (*(char *)(lVar9 + 3) == '\x01') {
    lVar9 = *(longlong *)(puVar3 + 4);
    param_1[0x30] = *(longlong *)puVar3;
    param_1[0x31] = lVar9;
    lVar9 = *(longlong *)(puVar3 + 0xc);
    param_1[0x32] = *(longlong *)(puVar3 + 8);
    param_1[0x33] = lVar9;
    lVar9 = *(longlong *)(puVar3 + 0x14);
    param_1[0x34] = *(longlong *)(puVar3 + 0x10);
    param_1[0x35] = lVar9;
    lVar9 = *(longlong *)(puVar3 + 0x1c);
    param_1[0x36] = *(longlong *)(puVar3 + 0x18);
    param_1[0x37] = lVar9;
    if (*(uint *)(lVar10 + 0x30) != 0) {
      memset((void *)((ulonglong)*(uint *)(lVar10 + 0x2c) + lVar10),0,
             (ulonglong)*(uint *)(lVar10 + 0x30));
    }
    *puVar11 = 1;
    puVar11[1] = 0x48;
    uVar6 = IsDeviceHybridInfoSupported((longlong)param_1);
    *(char *)(puVar11 + 2) = (char)uVar6;
    cVar2 = (char)puVar3[1];
    if (cVar2 == '\0') {
      puVar11[3] = 2;
    }
    else if (cVar2 == -0x80) {
      puVar11[3] = 1;
    }
    else if (cVar2 == -1) {
      puVar11[3] = 3;
    }
    puVar11[4] = 2;
    puVar11[5] = 2;
    puVar11[6] = 0xff;
    *(undefined8 *)(puVar11 + 8) = *(undefined8 *)(puVar3 + 8);
    uVar8 = (*(uint *)(param_1 + 0x2e) >> 2 ^ puVar11[10]) & 1 ^ puVar11[10];
    puVar11[10] = uVar8;
    uVar8 = (*(uint *)(param_1 + 0x2e) >> 2 ^ uVar8) & 2 ^ uVar8;
    puVar11[10] = uVar8;
    puVar11[10] = ((uVar8 ^ *(uint *)(param_1 + 0x2e)) & 4 ^ uVar8) & 0xfffffff7;
    *(byte *)(puVar11 + 0xb) = (*(byte *)((longlong)puVar3 + 7) & 0xf) + 1;
    *(byte *)((longlong)puVar11 + 0x2d) = (byte)puVar3[5] & 1;
    *(char *)((longlong)puVar11 + 0x2e) = (char)puVar3[3];
    puVar11[0xc] = (uint)(byte)puVar3[2];
    puVar11[0xd] = (uint)*(byte *)((longlong)puVar3 + 5);
    uVar8 = (*(uint *)(param_1 + 0x2e) >> 2 ^ puVar11[0xe]) & 1 ^ puVar11[0xe];
    puVar11[0xe] = uVar8;
    uVar8 = (*(uint *)(param_1 + 0x2e) >> 1 ^ uVar8) & 2 ^ uVar8;
    puVar11[0xe] = uVar8;
    uVar8 = ((int)param_1[0x2e] << 2 ^ uVar8) & 4 ^ uVar8;
    puVar11[0xe] = uVar8;
    uVar8 = ((int)param_1[0x2e] << 2 ^ uVar8) & 8 ^ uVar8;
    puVar11[0xe] = uVar8;
    puVar11[0xe] = ((int)param_1[0x2e] * 2 ^ uVar8) & 0x10 ^ uVar8;
    puVar11[0xf] = puVar3[0x10] & 0x1f;
    puVar11[0x10] = (uint)puVar3[0x11] << 6;
    iVar4 = GetHybridMaxLbaRangeCountForChangeLba((longlong)param_1);
    puVar11[0x11] = iVar4;
    puVar14 = puVar11 + 0x12;
    uVar8 = *(int *)(lVar10 + 0x30) - 0x48;
    iVar4 = 0;
    uVar12 = *puVar3;
    if ((uVar12 & 0xf) != 0) {
      lVar9 = (longlong)puVar3 + 0x41;
      do {
        if (uVar8 < 0x18) break;
        *(undefined1 *)puVar14 = *(undefined1 *)(lVar9 + -1);
        lVar7 = 0;
        puVar13 = puVar14;
        do {
          puVar13 = puVar13 + 1;
          pbVar1 = (byte *)(lVar9 + lVar7);
          lVar7 = lVar7 + 1;
          *puVar13 = (uint)*pbVar1;
        } while (lVar7 < 4);
        uVar12 = *puVar3;
        puVar14 = puVar14 + 6;
        uVar8 = uVar8 - 0x18;
        iVar4 = iVar4 + 1;
        lVar9 = lVar9 + 0x10;
      } while (iVar4 < (int)(uVar12 & 0xf));
    }
    if (iVar4 < (int)(uVar12 & 0xf)) {
      *(undefined4 *)(lVar10 + 0x14) = 3;
      *(uint *)(lVar10 + 0x30) = ((*puVar3 & 0xf) + 3) * 0x18;
      *(undefined1 *)(param_2 + 3) = 0x12;
    }
    iVar4 = *(int *)(lVar10 + 0x2c) + *(int *)(lVar10 + 0x30);
    if (*(char *)(param_2 + 2) == '(') {
      *(int *)(param_2 + 0x3c) = iVar4;
    }
    else {
      *(int *)(param_2 + 0x10) = iVar4;
    }
    if (*(char *)(*param_1 + 0x18e) != '\0') {
      StorPortExtendedFunction
                (0x57,*param_1,param_1 + 1,0,6,L"Hybrid Get Info",1,4,0,param_2,L"Srb Status",
                 *(undefined1 *)(param_2 + 3),L"Hybrid Disk",1,L"NvCache Size",
                 *(undefined8 *)(puVar11 + 8),L"NvCache Levels",*(undefined1 *)(puVar11 + 0xb),
                 L"NvCache Status",(char)puVar3[1],L"MaxLevelBehavior",
                 *(undefined1 *)((longlong)puVar11 + 0x2d),L"D_ThresholdLow",puVar11[0xc],
                 L"D_ThresholdHigh",puVar11[0xd]);
    }
    uVar15 = *(undefined8 *)(uVar5 + 0x1128);
  }
  else {
    if (*(char *)(*param_1 + 0x18e) != '\0') {
      StorPortExtendedFunction
                (0x57,*param_1,param_1 + 1,0,6,L"Hybrid Get Info",1,4,0,param_2,L"Srb Status",
                 *(char *)(lVar9 + 3),L"Hybrid Disk",1,L"NvCache Size",0,L"NvCache Levels",0,
                 L"NvCache Status",0,L"MaxLevelBehavior",0,L"D_ThresholdLow",0,L"D_ThresholdHigh",0)
      ;
    }
    uVar15 = *(undefined8 *)(uVar5 + 0x1128);
  }
  StorPortExtendedFunction(0x53,*param_1,*(undefined8 *)(uVar5 + 0x1120),0x200,1,uVar15);
  return;
}



===== HybridIoctlProcess @ 140021fa4 =====

ulonglong HybridIoctlProcess(longlong *param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  longlong lVar5;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar5 = *(longlong *)(param_2 + 0x40);
    uVar2 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar5 = *(longlong *)(param_2 + 0x18);
    uVar2 = *(uint *)(param_2 + 0x10);
  }
  if (0x33 < (ulonglong)uVar2) {
    if ((ulonglong)uVar2 < (ulonglong)*(uint *)(lVar5 + 0x30) + (ulonglong)*(uint *)(lVar5 + 0x2c))
    {
      *(undefined4 *)(lVar5 + 0x14) = 2;
    }
    else {
      iVar1 = *(int *)(lVar5 + 0x24);
      if (iVar1 == 1) {
        uVar3 = HybridGetInfo(param_1,param_2);
        return CONCAT44(extraout_var,uVar3);
      }
      if (iVar1 == 0x10) {
        uVar4 = HybridDisableCachingMedium(param_1,param_2);
        return uVar4;
      }
      if (iVar1 == 0x11) {
        uVar4 = HybridEnableCachingMedium(param_1,param_2);
        return uVar4;
      }
      if (iVar1 == 0x12) {
        uVar4 = HybridSetDirtyThreshold(param_1,param_2);
        return uVar4;
      }
      if (iVar1 == 0x13) {
        uVar4 = HybridDemoteBySize(param_1,param_2);
        return uVar4;
      }
    }
  }
  *(undefined1 *)(param_2 + 3) = 0x15;
  return 0xc1000006;
}



===== HybridSetDirtyThreshold @ 140022048 =====

undefined8 HybridSetDirtyThreshold(longlong *param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  char cVar6;
  undefined8 uVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  
  uVar8 = 0;
  cVar6 = *(char *)(param_2 + 2);
  uVar9 = 0;
  if (cVar6 == '(') {
    lVar10 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar10 = *(longlong *)(param_2 + 0x18);
  }
  uVar3 = GetSrbExtension(param_2);
  uVar2 = *(uint *)(lVar10 + 0x2c);
  if (uVar2 < 0x34) {
LAB_14002208f:
    *(undefined4 *)(lVar10 + 0x14) = 2;
    *(undefined1 *)(param_2 + 3) = 0x15;
  }
  else {
    if (cVar6 == '(') {
      uVar1 = *(uint *)(param_2 + 0x3c);
    }
    else {
      uVar1 = *(uint *)(param_2 + 0x10);
    }
    if ((uVar1 < 0x44) || (*(uint *)(lVar10 + 0x30) < 0x10)) {
      *(undefined4 *)(lVar10 + 0x14) = 3;
      uVar7 = 0xc1000004;
      *(undefined4 *)(lVar10 + 0x30) = 0x10;
      *(undefined1 *)(param_2 + 3) = 0x12;
      goto LAB_14002218e;
    }
    uVar8 = *(uint *)((ulonglong)uVar2 + 8 + lVar10);
    uVar9 = *(uint *)((ulonglong)uVar2 + 0xc + lVar10);
    if (((0xff < uVar8) || (0xff < uVar9)) || (uVar9 < uVar8)) goto LAB_14002208f;
    uVar4 = IsNCQSupported(param_1);
    if (((char)uVar4 != '\0') && ((param_1[0x4a] & 0x10U) != 0)) {
      plVar5 = param_1;
      uVar4 = IsDeviceHybridInfoSupported((longlong)param_1);
      if ((char)uVar4 != '\0') {
        uVar2 = IsDeviceHybridInfoEnabled((longlong)plVar5);
        if (((char)uVar2 != '\0') && ((*(uint *)(param_1 + 0x2e) & 4) != 0)) {
          *(byte *)(uVar3 + 0x110f) = *(byte *)(uVar3 + 0x110f) | 0x40;
          *(undefined2 *)(uVar3 + 0x110a) = 0x463;
          *(char *)(uVar3 + 0x110c) = (char)uVar8;
          *(char *)(uVar3 + 0x110d) = (char)uVar9;
          *(undefined2 *)(uVar3 + 0x1100) = 0x400;
          if (*(char *)(*param_1 + 0x18e) != '\0') {
            *(code **)(uVar3 + 0x2968) = HybridSetThresholdCompletion;
          }
          uVar7 = 0;
          goto LAB_14002218e;
        }
      }
    }
    *(undefined4 *)(lVar10 + 0x14) = 1;
    *(undefined1 *)(param_2 + 3) = 0x22;
  }
  uVar7 = 0xc1000006;
LAB_14002218e:
  if ((*(char *)(param_2 + 3) != '\0') && (*(char *)(*param_1 + 0x18e) != '\0')) {
    StorPortExtendedFunction
              (0x56,*param_1,param_1 + 1,0,0xc,L"Hybrid Set Dirty Threshold",1,4,0,param_2,
               L"Srb Status",*(char *)(param_2 + 3),L"Device CMD Sent",0,L"D_ThresholdLow",uVar8,
               L"D_ThresholdHigh",uVar9);
  }
  return uVar7;
}



===== HybridSetThresholdCompletion @ 140022270 =====

void HybridSetThresholdCompletion(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(char *)(*param_1 + 0x18e) != '\0') {
    if (*(char *)(param_2 + 2) == '(') {
      lVar1 = *(longlong *)(param_2 + 0x40);
    }
    else {
      lVar1 = *(longlong *)(param_2 + 0x18);
    }
    StorPortExtendedFunction
              (0x56,*param_1,param_1 + 1,0,0xc,L"Hybrid Set Dirty Threshold",1,4,0,param_2,
               L"Srb Status",*(undefined1 *)(param_2 + 3),L"Device CMD Sent",1,L"D_ThresholdLow",
               *(undefined4 *)((ulonglong)*(uint *)(lVar1 + 0x2c) + 8 + lVar1),L"D_ThresholdHigh",
               *(undefined4 *)((ulonglong)*(uint *)(lVar1 + 0x2c) + 0xc + lVar1));
  }
  return;
}



===== HybridWriteThroughCompletion @ 140022360 =====

void HybridWriteThroughCompletion(longlong *param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong *local_res10;
  undefined8 local_res18;
  
  local_res10 = (ulonglong *)0x0;
  local_res18 = 0;
  if (*(char *)(param_2 + 3) == '\x01') {
    uVar2 = GetSrbExtension(param_2);
    iVar1 = AhciAllocateDmaBuffer(*param_1,0x200,&local_res10,&local_res18);
    if ((iVar1 == 0) && (local_res10 != (ulonglong *)0x0)) {
      memset(local_res10,0,0x200);
      *local_res10 = (ulonglong)
                     CONCAT51(CONCAT41(CONCAT31(*(undefined3 *)(uVar2 + 0x1110),
                                                *(undefined1 *)(uVar2 + 0x110e)),
                                       *(undefined1 *)(uVar2 + 0x110d)),
                              *(undefined1 *)(uVar2 + 0x110c));
      *(ushort *)((longlong)local_res10 + 6) =
           CONCAT11(*(undefined1 *)(uVar2 + 0x1113),*(undefined1 *)(uVar2 + 0x110b));
      *(uint *)(uVar2 + 0x1104) = *(uint *)(uVar2 + 0x1104) | 4;
      *(undefined2 *)(uVar2 + 0x1100) = 0x400;
      *(ulonglong **)(uVar2 + 0x1120) = local_res10;
      *(undefined8 *)(uVar2 + 0x1128) = local_res18;
      *(undefined4 *)(uVar2 + 0x1130) = 0x200;
      *(undefined4 *)(uVar2 + 0x1140) = 1;
      *(undefined4 *)(uVar2 + 0x1150) = (undefined4)local_res18;
      *(undefined4 *)(uVar2 + 0x1154) = local_res18._4_4_;
      *(undefined4 *)(uVar2 + 0x1158) = 0x200;
      *(undefined4 **)(uVar2 + 0x1138) = (undefined4 *)(uVar2 + 0x1140);
      *(undefined8 *)(uVar2 + 0x1108) = 0;
      *(undefined8 *)(uVar2 + 0x1110) = 0;
      *(undefined4 *)(uVar2 + 0x1118) = 0;
      *(byte *)(uVar2 + 0x110f) = *(byte *)(uVar2 + 0x110f) | 0x40;
      *(undefined2 *)(uVar2 + 0x110a) = 0x164;
      *(undefined1 *)(uVar2 + 0x1115) = 1;
      *(code **)(uVar2 + 0x2968) = HybridWriteThroughEvictCompletion;
    }
    else {
      *(undefined1 *)(param_2 + 3) = 4;
    }
  }
  return;
}



===== HybridWriteThroughEvictCompletion @ 140022500 =====

void HybridWriteThroughEvictCompletion(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = GetSrbExtension(param_2);
  StorPortExtendedFunction
            (0x53,*param_1,*(undefined8 *)(uVar1 + 0x1120),0x200,1,*(undefined8 *)(uVar1 + 0x1128));
  return;
}



===== IsFirmwareUpdateSupported @ 140022550 =====

bool IsFirmwareUpdateSupported(longlong param_1)

{
  if ((*(uint *)(param_1 + 600) & 0x400) == 0) {
    return *(char *)(param_1 + 0x1c8) != '\0';
  }
  return true;
}



===== IsMsnEnabled @ 140022574 =====

ulonglong IsMsnEnabled(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = IsAtaDevice((uint *)(param_1 + 0x10));
  if (((char)uVar1 == '\0') ||
     (uVar1 = CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0xb8) >> 8),1),
     (*(byte *)(*(longlong *)(param_1 + 0xb8) + 0xfe) & 3) != 1)) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  return uVar1;
}



===== IsNCQSupported @ 1400225ac =====

ulonglong IsNCQSupported(longlong *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  
  lVar2 = *param_1;
  uVar1 = (ulonglong)*(uint *)(lVar2 + 0x38);
  if (((((*(uint *)(lVar2 + 0x38) & 0x40) == 0) &&
       (uVar1 = IsAtaDevice((uint *)(param_1 + 3)), (char)uVar1 != '\0')) &&
      ((*(uint *)(lVar2 + 0x1a8) & 0x40000000) != 0)) &&
     ((*(ushort *)(param_1[0x18] + 0x98) >> 8 & 1) != 0)) {
    uVar1 = CONCAT71((int7)(uVar1 >> 8),*(undefined1 *)(param_1[0x18] + 0x96)) & 0xffffffffffffff1f;
    return CONCAT71((int7)(uVar1 >> 8),1 < (byte)uVar1);
  }
  return uVar1 & 0xffffffffffffff00;
}



===== IsReadWriteCommand @ 140022608 =====

ulonglong IsReadWriteCommand(longlong param_1)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar4 = GetSrbExtension(param_1);
  uVar2 = *(ushort *)(uVar4 + 0x1100);
  if (uVar2 == 0x400) {
    cVar1 = *(char *)(uVar4 + 0x110a);
  }
  else {
    if ((uVar2 >> 8 & 1) == 0) {
      return uVar4 & 0xffffffffffffff00;
    }
    cVar1 = *(char *)(uVar4 + 0x110e);
  }
  uVar2 = CONCAT11((char)(uVar2 >> 8),cVar1);
  uVar3 = uVar2 - 0x24;
  uVar4 = (ulonglong)uVar3;
  if (((0x3d < (byte)uVar3) || ((0x3000000006271027U >> (uVar4 & 0x3f) & 1) == 0)) && (cVar1 != ' ')
     ) {
    uVar3 = uVar2 + 0x3c;
    uVar4 = (ulonglong)uVar3;
    if ((10 < (byte)uVar3) || ((0x453U >> (uVar3 & 0x1f) & 1) == 0)) {
      return (ulonglong)CONCAT31((int3)(uVar3 >> 8),cVar1 == -0x34);
    }
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== IsSmartFeatureSupported @ 140022680 =====

ulonglong IsSmartFeatureSupported(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = IsAtaDevice((uint *)(param_1 + 0x10));
  if (((char)uVar1 == '\0') ||
     (uVar1 = CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0xb8) >> 8),1),
     (*(byte *)(*(longlong *)(param_1 + 0xb8) + 0xa4) & 1) == 0)) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  return uVar1;
}



===== IsTapeDevice @ 1400226b8 =====

ulonglong IsTapeDevice(longlong param_1)

{
  ulonglong in_RAX;
  
  if ((*(int *)(param_1 + 0x10) == 2) &&
     (in_RAX = 0x100, (**(ushort **)(param_1 + 0xb8) & 0x1f00) == 0x100)) {
    return 0x101;
  }
  return in_RAX & 0xffffffffffffff00;
}



===== NVCacheGeneric @ 1400226e8 =====

undefined8 NVCacheGeneric(longlong *param_1,longlong param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  ulonglong uVar4;
  uint *puVar5;
  undefined8 uVar6;
  uint *puVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  char cVar12;
  undefined8 *local_res10;
  undefined8 local_res18 [2];
  
  cVar11 = *(char *)(param_2 + 2);
  puVar5 = (uint *)(param_2 + 0x18);
  cVar12 = '(';
  if (cVar11 == '(') {
    uVar9 = *(uint *)(param_2 + 0x3c);
    uVar10 = *puVar5;
  }
  else {
    uVar9 = *(uint *)(param_2 + 0x10);
    uVar10 = *(uint *)(param_2 + 0xc);
  }
  local_res10 = (undefined8 *)0x0;
  local_res18[0] = 0;
  lVar8 = param_2;
  uVar4 = GetSrbExtension(param_2);
  puVar7 = (uint *)(lVar8 + 0x40);
  if (cVar11 != cVar12) {
    puVar7 = puVar5;
  }
  lVar8 = *(longlong *)puVar7;
  uVar1 = *(ushort *)(lVar8 + 0x20);
  if (uVar1 < 0x14) {
    if (uVar1 != 0x13) {
      if ((uVar1 == 0) || (uVar1 == 1)) goto LAB_14002289f;
      if (((uVar1 != 0x10) && (uVar1 != 0x11)) && (uVar1 != 0x12)) {
LAB_1400227c7:
        if (0x2b < uVar9) {
          *(undefined4 *)(lVar8 + 0x28) = 1;
        }
        *(undefined1 *)(param_2 + 3) = 0x22;
        return 0xc1000007;
      }
    }
  }
  else if (((uVar1 != 0x14) && (uVar1 != 0xd0)) && (uVar1 != 0xd1)) {
    if (uVar1 != 0xe5) {
      if (uVar1 != 0xec) goto LAB_1400227c7;
      if (99 < uVar9) {
        *(ushort *)(lVar8 + 0x4c) = *(ushort *)(param_1[0x18] + 0x1ac) & 1;
        *(ushort *)(lVar8 + 0x50) = *(ushort *)(param_1[0x18] + 0x1ac) >> 4 & 1;
        *(ushort *)(lVar8 + 0x54) = (ushort)(*(byte *)(param_1[0x18] + 0x1ad) & 0xf);
        *(ushort *)(lVar8 + 0x56) = *(ushort *)(param_1[0x18] + 0x1ac) >> 0xc;
        uVar1 = *(ushort *)(param_1[0x18] + 0x1b0);
        *(uint *)(lVar8 + 0x58) = (uint)uVar1 << 0x10;
        uVar2 = *(undefined2 *)(param_1[0x18] + 0x1ae);
        *(undefined4 *)(lVar8 + 0x5c) = 0;
        *(uint *)(lVar8 + 0x58) = CONCAT22(uVar1,uVar2);
        *(uint *)(lVar8 + 0x60) = (uint)*(byte *)(param_1[0x18] + 0x1b6);
        *(undefined1 *)(param_2 + 3) = 1;
        *(undefined4 *)(lVar8 + 0x28) = 0;
        return 0;
      }
      goto LAB_1400228fa;
    }
LAB_14002289f:
    if (cVar11 == cVar12) {
      *puVar5 = *puVar5 | uVar10 & 0xffffff3f;
    }
    else {
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | uVar10 & 0xffffff3f;
    }
    *(uint *)(uVar4 + 0x1104) = *(uint *)(uVar4 + 0x1104) & 0xffffff3f;
    goto LAB_140022922;
  }
  if (((ushort)(uVar1 - 0x12) < 2) || ((ushort)(uVar1 - 0xd0) < 2)) {
    *(uint *)(uVar4 + 0x1104) = *(uint *)(uVar4 + 0x1104) | 2;
  }
  else {
    *(uint *)(uVar4 + 0x1104) = *(uint *)(uVar4 + 0x1104) | 4;
  }
  puVar5 = (uint *)StorPortGetScatterGatherList(*param_1,param_2);
  uVar6 = FillClippedSGL(puVar5,(uint *)(uVar4 + 0x1140),0x4c,uVar9 - 0x4c);
  if ((char)uVar6 == '\0') {
LAB_1400228fa:
    if (0x2b < uVar9) {
      *(undefined4 *)(lVar8 + 0x28) = 2;
    }
    *(undefined1 *)(param_2 + 3) = 0x15;
    return 0xc1000004;
  }
  *(uint **)(uVar4 + 0x1138) = (uint *)(uVar4 + 0x1140);
  *(uint *)(uVar4 + 0x1130) = uVar9 - 0x4c;
LAB_140022922:
  iVar3 = AhciAllocateDmaBuffer(*param_1,0x10,&local_res10,local_res18);
  if ((iVar3 == 0) && (local_res10 != (undefined8 *)0x0)) {
    *local_res10 = 0;
    local_res10[1] = 0;
    *(undefined8 **)(uVar4 + 0x2988) = local_res10;
    *(uint *)(uVar4 + 0x1104) = *(uint *)(uVar4 + 0x1104) | 0x40;
    *(undefined8 *)(uVar4 + 0x2990) = local_res18[0];
    *(code **)(uVar4 + 0x2968) = AhciPortNVCacheCompletion;
    *(undefined4 *)(uVar4 + 0x2998) = 0x10;
    *(undefined2 *)(uVar4 + 0x1100) = 0x100;
    *(undefined8 *)(uVar4 + 0x1108) = 0;
    *(undefined8 *)(uVar4 + 0x1110) = 0;
    *(undefined1 *)(uVar4 + 0x1108) = *(undefined1 *)(lVar8 + 0x20);
    *(undefined1 *)(uVar4 + 0x1109) = *(undefined1 *)(lVar8 + 0x2c);
    *(char *)(uVar4 + 0x1111) = (char)((uint)*(undefined4 *)(lVar8 + 0x2c) >> 8);
    uVar6 = *(undefined8 *)(lVar8 + 0x34);
    *(char *)(uVar4 + 0x110a) = (char)uVar6;
    *(char *)(uVar4 + 0x110b) = (char)((ulonglong)uVar6 >> 8);
    *(char *)(uVar4 + 0x110c) = (char)((ulonglong)uVar6 >> 0x10);
    *(char *)(uVar4 + 0x1112) = (char)((ulonglong)uVar6 >> 0x18);
    *(char *)(uVar4 + 0x1113) = (char)((ulonglong)uVar6 >> 0x20);
    *(char *)(uVar4 + 0x1114) = (char)((ulonglong)uVar6 >> 0x28);
    *(undefined2 *)(uVar4 + 0x110d) = 0xb6a0;
    *(undefined1 *)(param_2 + 3) = 0;
    return 0;
  }
  *(undefined1 *)(param_2 + 3) = 4;
  return 0xc1000003;
}



===== QueryPhysicalTopologyIoctlProcess @ 140022a2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 QueryPhysicalTopologyIoctlProcess(undefined4 *param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  short *psVar6;
  undefined8 uVar7;
  byte bVar8;
  longlong *plVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined1 auStack_88 [32];
  char local_68;
  char local_60 [24];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_88;
  uVar7 = 0;
  iVar13 = 0;
  if (*(char *)(param_2 + 2) == '(') {
    uVar5 = *(uint *)(param_2 + 0x18);
    lVar3 = *(longlong *)(param_2 + 0x40);
    uVar12 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar5 = *(uint *)(param_2 + 0xc);
    lVar3 = *(longlong *)(param_2 + 0x18);
    uVar12 = *(uint *)(param_2 + 0x10);
  }
  if (uVar12 < 0x54) {
    *(undefined1 *)(param_2 + 3) = 0x15;
    uVar7 = 0xc1000006;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 1;
    uVar1 = uVar12 - 0x1c;
    if ((uVar5 & 1) == 0) {
      local_68 = '\0';
      iVar13 = 1;
    }
    else {
      uVar10 = (ulonglong)(uint)param_1[0x61];
      plVar9 = (longlong *)(param_1 + 0x6c);
      uVar11 = (ulonglong)(uint)param_1[0x60];
      uVar5 = 0;
      local_68 = '\x01';
      do {
        if ((((uint)uVar11 >> (uVar5 & 0x1f) & 1) != 0) && (*plVar9 != 0)) {
          puVar4 = (uint *)(*plVar9 + 0x18);
          lVar2 = IsAtaDevice(puVar4);
          if (((char)lVar2 != '\0') || (*puVar4 == 2)) {
            iVar13 = iVar13 + 1;
          }
        }
        uVar5 = uVar5 + 1;
        plVar9 = plVar9 + 1;
      } while (uVar5 <= (uint)uVar10);
    }
    if (uVar1 != 0) {
      memset((void *)(lVar3 + 0x1c),0,(ulonglong)uVar1);
    }
    *(undefined4 *)(lVar3 + 0x1c) = 0x38;
    *(int *)(lVar3 + 0x20) = iVar13 * 0x88 + 0xb8;
    *(undefined4 *)(lVar3 + 0x24) = 1;
    *(undefined4 *)(lVar3 + 0x34) = 0x80;
    *(undefined4 *)(lVar3 + 0x38) = 0x28;
    *(int *)(lVar3 + 0x40) = iVar13 * 0x88;
    *(undefined4 *)(lVar3 + 0x44) = 0xa8;
    *(undefined4 *)(lVar3 + 0x2c) = 0;
    *(undefined4 *)(lVar3 + 0x30) = 1;
    *(int *)(lVar3 + 0x3c) = iVar13;
    if (uVar1 < 0xb8) {
      *(undefined8 *)(lVar3 + 0x34) = 0;
    }
    else {
      *(undefined4 *)(lVar3 + 0x54) = *param_1;
      if (param_1[0xc] == 0) {
        *(uint *)(lVar3 + 0x58) = (-(uint)((*(byte *)(param_1 + 0xb) & 1) != 0) & 3) + 1;
      }
      else {
        *(undefined4 *)(lVar3 + 0x58) = 5;
      }
      *(undefined4 *)(lVar3 + 0x5c) = 2;
      *(undefined4 *)(lVar3 + 0x60) = param_1[0x66];
      local_60[0x10] = 0;
      builtin_strncpy(local_60,"0123456789ABCDEF",0x10);
      *(char *)(lVar3 + 100) = local_60[*(ushort *)(param_1 + 4) >> 0xc];
      *(char *)(lVar3 + 0x65) = local_60[*(byte *)((longlong)param_1 + 0x11) & 0xf];
      *(char *)(lVar3 + 0x66) = local_60[*(ushort *)(param_1 + 4) >> 4 & 0xf];
      *(char *)(lVar3 + 0x67) = local_60[*(ushort *)(param_1 + 4) & 0xf];
      *(char *)(lVar3 + 0x6c) = local_60[*(ushort *)((longlong)param_1 + 0x12) >> 0xc];
      *(char *)(lVar3 + 0x6d) = local_60[*(byte *)((longlong)param_1 + 0x13) & 0xf];
      *(char *)(lVar3 + 0x6e) = local_60[*(ushort *)((longlong)param_1 + 0x12) >> 4 & 0xf];
      *(char *)(lVar3 + 0x6f) = local_60[*(ushort *)((longlong)param_1 + 0x12) & 0xf];
      *(char *)(lVar3 + 0x94) = local_60[*(byte *)(param_1 + 5) >> 4];
      bVar8 = *(byte *)(param_1 + 5);
      *(undefined1 *)(lVar3 + 0xc4) = 0;
      *(char *)(lVar3 + 0x95) = local_60[bVar8 & 0xf];
      if (0x13f < uVar1) {
        puVar14 = (undefined4 *)(lVar3 + 0xd4);
        if (local_68 == '\0') {
          bVar8 = 0;
          if (*(char *)(param_2 + 2) == '(') {
            if (((*(uint *)(param_2 + 0x34) != 0) &&
                (psVar6 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2),
                psVar6 != (short *)0x0)) && (*psVar6 == 1)) {
              bVar8 = *(byte *)(psVar6 + 4);
            }
          }
          else {
            bVar8 = *(byte *)(param_2 + 5);
          }
          GetDevicePhysicalTopologyData
                    (*(longlong **)(param_1 + (ulonglong)bVar8 * 2 + 0x6c),puVar14);
          return 0;
        }
        uVar12 = uVar12 - 0xd4;
        uVar5 = 0;
        do {
          if ((((uint)param_1[0x60] >> (uVar5 & 0x1f) & 1) != 0) &&
             (plVar9 = *(longlong **)(param_1 + (ulonglong)uVar5 * 2 + 0x6c),
             plVar9 != (longlong *)0x0)) {
            puVar4 = (uint *)(plVar9 + 3);
            lVar3 = IsAtaDevice(puVar4);
            if (((char)lVar3 != '\0') || (*puVar4 == 2)) {
              GetDevicePhysicalTopologyData(plVar9,puVar14);
              uVar12 = uVar12 - 0x88;
              if (uVar12 < 0x88) {
                return 0;
              }
              puVar14 = puVar14 + 0x22;
            }
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 <= (uint)param_1[0x61]);
        return 0;
      }
    }
    *(undefined8 *)(lVar3 + 0x40) = 0;
  }
  return uVar7;
}



===== QueryProtocolInfoCompletion @ 140022d40 =====

void QueryProtocolInfoCompletion(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  uVar1 = GetSrbExtension(param_2);
  if (*(char *)(param_2 + 2) == '(') {
    lVar2 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar2 = *(longlong *)(param_2 + 0x18);
  }
  if (*(char *)(param_2 + 3) == '\x01') {
    uVar3 = *(undefined4 *)(uVar1 + 0x1130);
  }
  else {
    uVar3 = 0;
  }
  *(undefined4 *)(lVar2 + 0x38) = uVar3;
  *(undefined8 *)(uVar1 + 0x1120) = 0;
  *(undefined8 *)(uVar1 + 0x2970) = 0;
  *(undefined8 *)(uVar1 + 0x2968) = 0;
  *(undefined2 *)(uVar1 + 0x1100) = 0;
  return;
}



===== QueryProtocolInfoIdentifyData @ 140022d9c =====

undefined8 QueryProtocolInfoIdentifyData(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint *puVar4;
  longlong lVar5;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar5 = *(longlong *)(param_2 + 0x40);
  }
  else {
    lVar5 = *(longlong *)(param_2 + 0x18);
  }
  if (*(uint *)(lVar5 + 0x38) < 0x200) {
    *(undefined1 *)(param_2 + 3) = 0x15;
    uVar2 = 0xc1000006;
  }
  else {
    uVar3 = GetSrbExtension(param_2);
    *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 2;
    *(undefined2 *)(uVar3 + 0x1100) = 0x101;
    *(code **)(uVar3 + 0x2968) = QueryProtocolInfoCompletion;
    *(undefined8 *)(uVar3 + 0x1108) = 0;
    *(undefined8 *)(uVar3 + 0x1110) = 0;
    *(undefined2 *)(uVar3 + 0x110d) = 0xeca0;
    iVar1 = *(int *)(lVar5 + 0x34);
    puVar4 = (uint *)StorPortGetScatterGatherList(*param_1);
    uVar2 = FillClippedSGL(puVar4,(uint *)(uVar3 + 0x1140),iVar1 + 0x24,0x200);
    if ((char)uVar2 == '\0') {
      *(undefined1 *)(param_2 + 3) = 6;
      uVar2 = 0xc1000004;
    }
    else {
      *(uint **)(uVar3 + 0x1138) = (uint *)(uVar3 + 0x1140);
      uVar2 = 0;
      *(undefined4 *)(uVar3 + 0x1130) = 0x200;
    }
  }
  return uVar2;
}



===== QueryProtocolInfoLogPageData @ 140022e88 =====

undefined8 QueryProtocolInfoLogPageData(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  longlong lVar8;
  uint uVar9;
  undefined8 *puVar10;
  char cVar11;
  bool bVar12;
  
  lVar4 = param_2;
  uVar2 = GetSrbExtension(param_2);
  if (*(char *)(lVar4 + 2) == '(') {
    lVar8 = *(longlong *)(lVar4 + 0x40);
  }
  else {
    lVar8 = *(longlong *)(lVar4 + 0x18);
  }
  uVar9 = *(uint *)(lVar8 + 0x2c);
  if ((0xff < uVar9) || (0xffff < *(uint *)(lVar8 + 0x30))) goto LAB_140022f90;
  if (*(uint *)(lVar8 + 0x38) < 0x200) {
    *(undefined1 *)(lVar4 + 3) = 0x15;
    return 0xc1000006;
  }
  if ((((uVar9 == 1) || (uVar9 == 2)) || (uVar9 == 6)) || (uVar9 == 9)) {
    puVar10 = param_1 + 1;
    cVar11 = '\x01';
    uVar3 = IsSmartFeatureSupported((longlong)puVar10);
    if ((char)uVar3 == '\0') goto LAB_140022f90;
  }
  else {
    cVar11 = '\0';
    uVar3 = IsDeviceGeneralPurposeLoggingSupported((longlong)param_1);
    if ((char)uVar3 == '\0') goto LAB_140022f90;
    puVar10 = param_1 + 1;
  }
  if (uVar9 < 10) {
    if (uVar9 != 9) {
      if (((uVar9 == 1) || (uVar9 == 2)) || (uVar9 == 3)) {
        uVar3 = IsSmartFeatureSupported((longlong)puVar10);
        if ((char)uVar3 == '\0') goto LAB_140022f90;
        bVar12 = (*(byte *)(puVar10[0x17] + 0xa8) & 1) == 0;
        goto LAB_140022fd3;
      }
      if ((uVar9 != 6) && (uVar9 != 7)) {
        if (uVar9 == 8) {
          lVar4 = IsAtaDevice((uint *)(param_1 + 3));
          if (((char)lVar4 == '\0') || (-1 < *(char *)(param_1[0x18] + 0xee))) goto LAB_140022f90;
          goto LAB_140023074;
        }
        goto LAB_14002305a;
      }
    }
    uVar3 = IsSmartFeatureSupported((longlong)puVar10);
    if ((char)uVar3 == '\0') goto LAB_140022f90;
    bVar12 = (*(byte *)(puVar10[0x17] + 0xa8) & 2) == 0;
LAB_140022fd3:
    if (bVar12) goto LAB_140022f90;
  }
  else if (((uVar9 == 0x10) || (uVar9 == 0x12)) || (uVar9 == 0x13)) {
    lVar4 = IsAtaDevice((uint *)(param_1 + 3));
    if (((char)lVar4 == '\0') || ((*(ushort *)(param_1[0x18] + 0x98) >> 8 & 1) == 0))
    goto LAB_140022f90;
  }
  else if ((uVar9 == 0x21) || (uVar9 == 0x22)) {
    lVar4 = IsAtaDevice((uint *)(param_1 + 3));
    if ((char)lVar4 == '\0') goto LAB_140022f90;
    bVar12 = (*(byte *)(param_1[0x18] + 0xa8) & 0x10) == 0;
    goto LAB_140022fd3;
  }
LAB_14002305a:
  if ((0x5e < uVar9 - 0x80) ||
     (uVar3 = IsSmartFeatureSupported((longlong)(param_1 + 1)), (char)uVar3 != '\0')) {
LAB_140023074:
    lVar4 = (ulonglong)*(uint *)(lVar8 + 0x34) + 0x24 + lVar8;
    uVar9 = *(uint *)(lVar8 + 0x38) >> 9;
    if (cVar11 == '\0') {
      IssueReadLogExtCommand
                ((longlong)param_1,param_2,*(undefined1 *)(lVar8 + 0x2c),
                 *(undefined2 *)(lVar8 + 0x30),(ushort)uVar9,0,(undefined8 *)0x0,lVar4,
                 QueryProtocolInfoCompletion);
    }
    else {
      uVar7 = *(undefined1 *)(lVar8 + 0x2c);
      uVar3 = GetSrbExtension(param_2);
      *(uint *)(uVar3 + 0x1104) = *(uint *)(uVar3 + 0x1104) | 2;
      *(undefined2 *)(uVar3 + 0x1100) = 0x105;
      *(code **)(uVar3 + 0x2968) = QueryProtocolInfoCompletion;
      *(undefined8 *)(uVar3 + 0x1108) = 0;
      *(undefined8 *)(uVar3 + 0x1110) = 0;
      *(undefined1 *)(uVar3 + 0x1108) = 0xd5;
      *(char *)(uVar3 + 0x1109) = (char)uVar9;
      *(undefined1 *)(uVar3 + 0x110a) = uVar7;
      *(undefined4 *)(uVar3 + 0x110b) = 0xb0a0c24f;
      *(undefined1 *)(param_2 + 3) = 0;
      *(longlong *)(uVar3 + 0x1120) = lVar4;
    }
    iVar1 = *(int *)(lVar8 + 0x34);
    puVar5 = (uint *)StorPortGetScatterGatherList(*param_1,param_2);
    uVar6 = FillClippedSGL(puVar5,(uint *)(uVar2 + 0x1140),iVar1 + 0x24,uVar9 << 9);
    if ((char)uVar6 == '\0') {
      *(undefined1 *)(param_2 + 3) = 6;
      return 0xc1000004;
    }
    *(uint **)(uVar2 + 0x1138) = (uint *)(uVar2 + 0x1140);
    *(uint *)(uVar2 + 0x1130) = uVar9 << 9;
    return 0;
  }
LAB_140022f90:
  *(undefined1 *)(param_2 + 3) = 6;
  return 0xc1000006;
}



===== QueryTemperatureInfoCompletion @ 140023180 =====

void QueryTemperatureInfoCompletion(undefined8 *param_1,longlong param_2)

{
  uint *puVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar5 = param_2;
  uVar4 = GetSrbExtension(param_2);
  if (*(char *)(lVar5 + 2) == '(') {
    iVar3 = *(int *)(lVar5 + 0x3c);
    lVar6 = *(longlong *)(lVar5 + 0x40);
  }
  else {
    iVar3 = *(int *)(lVar5 + 0x10);
    lVar6 = *(longlong *)(lVar5 + 0x18);
  }
  if (*(char *)(lVar5 + 3) == '\x01') {
    puVar1 = *(uint **)(uVar4 + 0x1120);
    if (iVar3 - 0x1cU != 0) {
      memset((void *)(lVar6 + 0x1c),0,(ulonglong)(iVar3 - 0x1cU));
    }
    *(undefined4 *)(lVar6 + 0x20) = 0x28;
    *(undefined4 *)(lVar6 + 0x1c) = 0x28;
    *(undefined4 *)(lVar6 + 0x24) = 0x80008000;
    *(undefined2 *)(lVar6 + 0x28) = 1;
    *(undefined4 *)(lVar6 + 0x38) = 0x80008000;
    *(undefined4 *)(lVar6 + 0x34) = 0x80000000;
    *(undefined2 *)(lVar6 + 0x3c) = 0;
    *(undefined1 *)(lVar6 + 0x3e) = 0;
    if ((*(char *)((longlong)puVar1 + 2) == '\x05') && ((*puVar1 & 0xffff) == 1)) {
      uVar2 = *(ulonglong *)(puVar1 + 2);
      if (((longlong)uVar2 < 0) && ((uVar2 >> 0x3e & 1) != 0)) {
        *(ushort *)(lVar6 + 0x36) = (ushort)uVar2 & 0xff;
      }
      uVar2 = *(ulonglong *)(puVar1 + 0x16);
      if (((longlong)uVar2 < 0) && ((uVar2 >> 0x3e & 1) != 0)) {
        *(ushort *)(lVar6 + 0x38) = (ushort)uVar2 & 0xff;
        *(ushort *)(lVar6 + 0x26) = (ushort)puVar1[0x16] & 0xff;
      }
      uVar2 = *(ulonglong *)(puVar1 + 0x1a);
      if (((longlong)uVar2 < 0) && ((uVar2 >> 0x3e & 1) != 0)) {
        *(ushort *)(lVar6 + 0x3a) = (ushort)uVar2 & 0xff;
      }
    }
    else {
      *(undefined1 *)(param_2 + 3) = 4;
    }
  }
  if (*(longlong *)(uVar4 + 0x1120) != 0) {
    StorPortExtendedFunction
              (0x53,*param_1,*(longlong *)(uVar4 + 0x1120),0x200,1,*(undefined8 *)(uVar4 + 0x1128));
    *(undefined8 *)(uVar4 + 0x1120) = 0;
  }
  *(undefined8 *)(uVar4 + 0x2970) = 0;
  *(undefined8 *)(uVar4 + 0x2968) = 0;
  *(undefined2 *)(uVar4 + 0x1100) = 0;
  return;
}



===== QueryTemperatureInfoIoctlProcess @ 14002330c =====

undefined4 QueryTemperatureInfoIoctlProcess(longlong *param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  void *local_res10;
  undefined8 local_res18;
  
  if (*(char *)(param_2 + 2) == '(') {
    bVar3 = (byte)*(undefined4 *)(param_2 + 0x18);
  }
  else {
    bVar3 = (byte)*(undefined4 *)(param_2 + 0xc);
  }
  local_res10 = (void *)0x0;
  local_res18 = 0;
  if (*(char *)(param_2 + 2) == '(') {
    uVar1 = *(uint *)(param_2 + 0x3c);
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x10);
  }
  if ((bVar3 & 1) == 0) {
    if (uVar1 < 0x44) {
      *(undefined1 *)(param_2 + 3) = 0x15;
      return 0xc1000006;
    }
    if ((*(uint *)((longlong)param_1 + 0x164) & 4) != 0) {
      iVar2 = AhciAllocateDmaBuffer(*param_1,0x200,&local_res10,&local_res18);
      if ((iVar2 == 0) && (local_res10 != (void *)0x0)) {
        memset(local_res10,0,0x200);
        IssueReadLogExtCommand
                  ((longlong)param_1,param_2,4,5,1,0,&local_res18,local_res10,
                   QueryTemperatureInfoCompletion);
        return 0;
      }
      *(undefined1 *)(param_2 + 3) = 4;
      return 0xc1000003;
    }
  }
  *(undefined1 *)(param_2 + 3) = 6;
  return 0xc1000006;
}



===== TelemetryFillCommonHeader @ 14002341c =====

undefined8 TelemetryFillCommonHeader(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint *puVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar1 = *(uint *)(param_2 + 0x3c);
    puVar3 = *(uint **)(param_2 + 0x40);
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x10);
    puVar3 = *(uint **)(param_2 + 0x18);
  }
  if ((*puVar3 < uVar1) && (0x10f < uVar1)) {
    memset(*(void **)(param_1 + 0x1e0),0,0x200);
    *(undefined1 *)(param_1 + 0x1f0) = 0xff;
    if (*(short *)(param_1 + 0x231) == 0) {
      *(undefined2 *)(param_1 + 0x231) = AhciGPLogPageIntoPrivate;
      *(undefined2 *)(param_1 + 0x233) = 0;
    }
    IssueReadLogExtCommand
              (param_1,param_2,0x24,0,1,1,(undefined8 *)(param_1 + 0x1e8),
               *(undefined8 *)(param_1 + 0x1e0),TelemetryFillCommonHeaderCompletion);
    uVar2 = 0;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 6;
    uVar2 = 0xc1000004;
  }
  return uVar2;
}



===== TelemetryFillCommonHeaderCompletion @ 140023500 =====

void TelemetryFillCommonHeaderCompletion(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  longlong lVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  longlong lVar9;
  int local_res10 [2];
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar9 = *(longlong *)(param_2 + 0x40);
    uVar4 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar9 = *(longlong *)(param_2 + 0x18);
    uVar4 = *(uint *)(param_2 + 0x10);
  }
  if (uVar4 < 0x110) {
    uVar8 = 6;
  }
  else {
    uVar8 = 1;
    if (*(char *)(param_2 + 3) == '\x01') {
      lVar2 = *(longlong *)(param_1 + 0x1e0);
      *(undefined1 *)(param_1 + 0x1f0) = 0x24;
      local_res10[0] = *(int *)(lVar2 + 4);
      *(undefined1 *)(lVar9 + 0x2c) = 0;
      if (local_res10[0] != 0) {
        pbVar6 = (byte *)local_res10;
        lVar5 = 4;
        puVar7 = (undefined1 *)(lVar9 + 0x2c);
        do {
          bVar1 = *pbVar6;
          pbVar6 = pbVar6 + 1;
          *puVar7 = (&DAT_14002b750)[bVar1 >> 4];
          puVar7[1] = (&DAT_14002b750)[bVar1 & 0xf];
          lVar5 = lVar5 + -1;
          puVar7 = puVar7 + 2;
        } while (lVar5 != 0);
        *(undefined1 *)(lVar9 + 0x34) = 0;
      }
      uVar3 = *(undefined8 *)(lVar2 + 0x188);
      *(undefined8 *)(lVar9 + 0x8c) = *(undefined8 *)(lVar2 + 0x180);
      *(undefined8 *)(lVar9 + 0x94) = uVar3;
      uVar3 = *(undefined8 *)(lVar2 + 0x198);
      *(undefined8 *)(lVar9 + 0x9c) = *(undefined8 *)(lVar2 + 400);
      *(undefined8 *)(lVar9 + 0xa4) = uVar3;
      uVar3 = *(undefined8 *)(lVar2 + 0x1a8);
      *(undefined8 *)(lVar9 + 0xac) = *(undefined8 *)(lVar2 + 0x1a0);
      *(undefined8 *)(lVar9 + 0xb4) = uVar3;
      uVar3 = *(undefined8 *)(lVar2 + 0x1b8);
      *(undefined8 *)(lVar9 + 0xbc) = *(undefined8 *)(lVar2 + 0x1b0);
      *(undefined8 *)(lVar9 + 0xc4) = uVar3;
      uVar3 = *(undefined8 *)(lVar2 + 0x1c8);
      *(undefined8 *)(lVar9 + 0xcc) = *(undefined8 *)(lVar2 + 0x1c0);
      *(undefined8 *)(lVar9 + 0xd4) = uVar3;
      uVar3 = *(undefined8 *)(lVar2 + 0x1d8);
      *(undefined8 *)(lVar9 + 0xdc) = *(undefined8 *)(lVar2 + 0x1d0);
      *(undefined8 *)(lVar9 + 0xe4) = uVar3;
      uVar3 = *(undefined8 *)(lVar2 + 0x1e8);
      *(undefined8 *)(lVar9 + 0xec) = *(undefined8 *)(lVar2 + 0x1e0);
      *(undefined8 *)(lVar9 + 0xf4) = uVar3;
      uVar3 = *(undefined8 *)(lVar2 + 0x1f8);
      *(undefined8 *)(lVar9 + 0xfc) = *(undefined8 *)(lVar2 + 0x1f0);
      *(undefined8 *)(lVar9 + 0x104) = uVar3;
      *(undefined1 *)(lVar9 + 0x10b) = 0;
      if (*(short *)(param_1 + 0x233) == 0) {
        *(undefined2 *)(param_1 + 0x231) = AhciGPLogPageIntoPrivate;
        *(undefined2 *)(param_1 + 0x233) = *(undefined2 *)(lVar2 + 0xc);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x1f0) = 0xff;
    }
    if (*(char *)(param_2 + 2) == '(') {
      *(undefined4 *)(param_2 + 0x3c) = 0x110;
    }
    else {
      *(undefined4 *)(param_2 + 0x10) = 0x110;
    }
  }
  *(undefined1 *)(param_2 + 3) = uVar8;
  return;
}



===== TelemetryFillHeaders @ 140023698 =====

undefined8 TelemetryFillHeaders(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint *puVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    uVar1 = *(uint *)(param_2 + 0x3c);
    puVar3 = *(uint **)(param_2 + 0x40);
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x10);
    puVar3 = *(uint **)(param_2 + 0x18);
  }
  if ((*puVar3 < uVar1) && (0x70 < uVar1)) {
    memset(*(void **)(param_1 + 0x1e0),0,0x200);
    IssueReadLogExtCommand
              (param_1,param_2,0,0,1,0,(undefined8 *)(param_1 + 0x1e8),
               *(undefined8 *)(param_1 + 0x1e0),TelemetryFillHeadersCompletion);
    uVar2 = 0;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 6;
    uVar2 = 0xc1000004;
  }
  return uVar2;
}



===== TelemetryFillHeadersCompletion @ 140023740 =====

void TelemetryFillHeadersCompletion(longlong param_1,longlong param_2)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar6 = *(longlong *)(param_2 + 0x40);
    uVar2 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar6 = *(longlong *)(param_2 + 0x18);
    uVar2 = *(uint *)(param_2 + 0x10);
  }
  if (uVar2 < 0x71) {
    *(undefined1 *)(param_2 + 3) = 6;
  }
  else if (*(char *)(param_2 + 3) == '\x01') {
    puVar3 = (undefined2 *)(param_1 + 499);
    lVar5 = (lVar6 + 0x1c) - param_1;
    lVar4 = 0x10;
    do {
      uVar1 = *(undefined2 *)((longlong)puVar3 + (param_1 - (lVar6 + 0x1c)) + lVar5 + -2);
      *puVar3 = *(undefined2 *)(*(longlong *)(param_1 + 0x1e0) + (ulonglong)(byte)uVar1 * 2);
      *(undefined2 *)((longlong)puVar3 + lVar5 + -0x1ef) = uVar1;
      *(undefined2 *)(lVar5 + -0x1ed + (longlong)puVar3) = *puVar3;
      puVar3 = puVar3 + 2;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    if (*(short *)(param_1 + 0x233) == 0) {
      *(undefined2 *)(param_1 + 0x231) = 0x24;
      *(undefined2 *)(param_1 + 0x233) = *(undefined2 *)(*(longlong *)(param_1 + 0x1e0) + 0x48);
    }
    builtin_strncpy((char *)(lVar6 + 0x60),"ATAGPLog",8);
    *(undefined4 *)(lVar6 + 0x68) = 0x65676150;
    *(undefined1 *)(lVar6 + 0x6c) = 0x73;
    *(undefined1 *)(lVar6 + 0x6d) = 0;
    if (*(char *)(param_2 + 2) == '(') {
      *(undefined4 *)(param_2 + 0x3c) = 0x200;
    }
    else {
      *(undefined4 *)(param_2 + 0x10) = 0x200;
    }
  }
  return;
}



===== TelemetryGetSettings @ 140023860 =====

undefined8 TelemetryGetSettings(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  longlong lVar4;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar4 = *(longlong *)(param_2 + 0x40);
    uVar3 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar4 = *(longlong *)(param_2 + 0x18);
    uVar3 = *(uint *)(param_2 + 0x10);
  }
  if (uVar3 < 0x7c) {
    *(undefined1 *)(param_2 + 3) = 6;
    return 0xc1000004;
  }
  *(undefined2 *)(lVar4 + 0x1c) = 2;
  *(undefined4 *)(lVar4 + 0x1c) = 0x59455300;
  *(undefined1 *)(lVar4 + 0x74) = 0x24;
  uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0xc0) + 0x3e);
  *(undefined8 *)(lVar4 + 0x20) = *(undefined8 *)(*(longlong *)(param_1 + 0xc0) + 0x36);
  *(undefined8 *)(lVar4 + 0x28) = uVar2;
  *(undefined4 *)(lVar4 + 0x30) = *(undefined4 *)(*(longlong *)(param_1 + 0xc0) + 0x2e);
  lVar1 = *(longlong *)(param_1 + 0xc0);
  uVar2 = *(undefined8 *)(lVar1 + 0x1c);
  *(undefined8 *)(lVar4 + 0x34) = *(undefined8 *)(lVar1 + 0x14);
  *(undefined8 *)(lVar4 + 0x3c) = uVar2;
  *(undefined4 *)(lVar4 + 0x44) = *(undefined4 *)(lVar1 + 0x24);
  *(undefined1 *)(lVar4 + 0x54) = 0;
  *(undefined1 *)(param_2 + 3) = 1;
  return 0;
}



===== TelemetrySetHostSettings @ 1400238e8 =====

undefined8 TelemetrySetHostSettings(longlong param_1,longlong param_2)

{
  short sVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined2 *puVar4;
  longlong lVar5;
  short *psVar6;
  longlong lVar7;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar7 = *(longlong *)(param_2 + 0x40);
    uVar2 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar7 = *(longlong *)(param_2 + 0x18);
    uVar2 = *(uint *)(param_2 + 0x10);
  }
  if (uVar2 < 0x7c) {
    *(undefined1 *)(param_2 + 3) = 6;
    uVar3 = 0xc1000004;
  }
  else {
    psVar6 = (short *)(lVar7 + 0x1e);
    *(undefined8 *)(param_1 + 0x1f1) = 0;
    *(undefined8 *)(param_1 + 0x1f9) = 0;
    puVar4 = (undefined2 *)(param_1 + 499);
    *(undefined8 *)(param_1 + 0x201) = 0;
    *(undefined8 *)(param_1 + 0x209) = 0;
    *(undefined8 *)(param_1 + 0x211) = 0;
    *(undefined8 *)(param_1 + 0x219) = 0;
    lVar5 = 0x10;
    *(undefined8 *)(param_1 + 0x221) = 0;
    *(undefined8 *)(param_1 + 0x229) = 0;
    if (*psVar6 == 0) {
      do {
        puVar4[-1] = *(undefined2 *)((longlong)L"sact" + (5 - param_1) + (longlong)puVar4);
        *puVar4 = 0;
        puVar4 = puVar4 + 2;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
    }
    else {
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
        puVar4[-1] = sVar1;
        *puVar4 = 0;
        puVar4 = puVar4 + 2;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      *(undefined2 *)(param_1 + 0x231) = *(undefined2 *)(lVar7 + 0x3e);
      *(undefined2 *)(param_1 + 0x233) = 0;
    }
    if (*(short *)(param_1 + 0x231) == 0) {
      *(undefined2 *)(param_1 + 0x231) = AhciGPLogPageIntoPrivate;
      *(undefined2 *)(param_1 + 0x233) = 0;
    }
    *(undefined1 *)(param_2 + 3) = 1;
    uVar3 = 0;
  }
  return uVar3;
}



===== TelemetryWriteDriverLog @ 1400239d4 =====

undefined8 TelemetryWriteDriverLog(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint *_Dst;
  size_t _Size;
  
  if (*(char *)(param_2 + 2) == '(') {
    _Dst = *(uint **)(param_2 + 0x40);
    uVar1 = *(uint *)(param_2 + 0x3c);
  }
  else {
    _Dst = *(uint **)(param_2 + 0x18);
    uVar1 = *(uint *)(param_2 + 0x10);
  }
  if (*_Dst < uVar1) {
    _Size = 0xf00;
    if (uVar1 < 0xf01) {
      _Size = (size_t)uVar1;
    }
    memcpy(_Dst,(void *)(param_1 + 0x36c4),_Size);
    uVar2 = 0;
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 6;
    uVar2 = 0xc1000004;
  }
  return uVar2;
}



===== TelemetryWritePrivateLog @ 140023a34 =====

undefined8 TelemetryWritePrivateLog(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  uint *puVar3;
  longlong lVar4;
  uint *puVar5;
  uint uVar6;
  ushort uVar7;
  
  lVar4 = param_2;
  uVar1 = GetSrbExtension(param_2);
  if (*(char *)(lVar4 + 2) == '(') {
    puVar5 = *(uint **)(lVar4 + 0x40);
    uVar6 = *(uint *)(lVar4 + 0x3c);
  }
  else {
    puVar5 = *(uint **)(lVar4 + 0x18);
    uVar6 = *(uint *)(lVar4 + 0x10);
  }
  if (*puVar5 < uVar6) {
    uVar7 = (ushort)uVar6 >> 9;
    if (*(ushort *)((longlong)param_1 + 0x233) <= uVar7) {
      uVar7 = *(ushort *)((longlong)param_1 + 0x233);
    }
    if (uVar7 != 0) {
      uVar2 = StorPortGetScatterGatherList(*param_1);
      *(undefined8 *)(uVar1 + 0x1138) = uVar2;
      puVar3 = (uint *)StorPortGetScatterGatherList(*param_1,param_2);
      uVar2 = FillClippedSGL(puVar3,(uint *)(uVar1 + 0x1140),0x1c,uVar6 - 0x1c);
      if ((char)uVar2 != '\0') {
        *(uint **)(uVar1 + 0x1138) = (uint *)(uVar1 + 0x1140);
        *(uint *)(uVar1 + 0x1130) = uVar6 - 0x1c;
        IssueReadLogExtCommand
                  ((longlong)param_1,param_2,*(undefined1 *)((longlong)param_1 + 0x231),0,uVar7,0,
                   (undefined8 *)0x0,puVar5,TelemetryWritePublicLogCompletion);
        return 0;
      }
    }
  }
  *(undefined1 *)(param_2 + 3) = 6;
  return 0xc1000004;
}



===== TelemetryWritePublicLogCompletion @ 140023b60 =====

void TelemetryWritePublicLogCompletion(undefined8 param_1,longlong param_2)

{
  *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) & 0x7f;
  return;
}



===== TelemetryWritePublicLog @ 140023b6c =====

undefined8 TelemetryWritePublicLog(longlong param_1,longlong param_2)

{
  uint *puVar1;
  undefined8 uVar2;
  uint uVar3;
  
  if (*(char *)(param_2 + 2) == '(') {
    puVar1 = *(uint **)(param_2 + 0x40);
    uVar3 = *(uint *)(param_2 + 0x3c);
  }
  else {
    puVar1 = *(uint **)(param_2 + 0x18);
    uVar3 = *(uint *)(param_2 + 0x10);
  }
  if (*puVar1 < uVar3) {
    IssueReadLogExtCommand
              (param_1,param_2,(char)puVar1[7],0,(ushort)puVar1[8],0,(undefined8 *)0x0,puVar1 + 7,
               TelemetryWritePublicLogCompletion);
    uVar2 = 0;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 6;
    uVar2 = 0xc1000004;
  }
  return uVar2;
}



===== UpdateDeviceParameters @ 140023be4 =====

void UpdateDeviceParameters(longlong *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  ulonglong uVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 uVar10;
  
  puVar2 = (ushort *)param_1[0x18];
  *(undefined1 *)((longlong)param_1 + 0x1d) = 0;
  uVar10 = 2;
  if ((int)param_1[3] == 2) {
    *(undefined1 *)((longlong)param_1 + 0x1e) = 1;
    *(undefined4 *)(param_1 + 6) = 0;
    goto LAB_140023d51;
  }
  uVar5 = 1;
  *(byte *)((longlong)param_1 + 0x1c) = ((int)param_1[3] != 3) - 1U & 0x14;
  uVar9 = ((uint)(*puVar2 >> 7) ^ *(uint *)(param_1 + 4)) & 1 ^ *(uint *)(param_1 + 4);
  *(uint *)(param_1 + 4) = uVar9;
  bVar3 = (byte)puVar2[0x4b] & 0x1f;
  bVar4 = *(byte *)((longlong)param_1 + 0x274);
  if (bVar3 <= *(byte *)((longlong)param_1 + 0x274)) {
    bVar4 = bVar3;
  }
  *(byte *)((longlong)param_1 + 0x1e) = bVar4;
  if (((puVar2[0x54] & 0x40) != 0) && ((puVar2[0x57] & 0x40) != 0)) {
    *(uint *)(param_1 + 4) = uVar9 | 4;
  }
  iVar7 = 0;
  if ((((puVar2[0x53] >> 10 & 1) != 0) && ((puVar2[0x56] >> 10 & 1) != 0)) &&
     (iVar7 = 0, 0xfffffff < *(longlong *)(puVar2 + 100))) {
    iVar7 = 1;
  }
  *(int *)(param_1 + 6) = iVar7 + 1;
  uVar6 = IsNCQSupported(param_1);
  if ((char)uVar6 != '\0') {
    if (*(char *)(*param_1 + 0x18c) == '\0') {
      uVar6 = param_1[0x4a] | 0x10;
    }
    else {
      if ((*(char *)(*param_1 + 0x18c) != (char)uVar10) ||
         (uVar9 = IsDeviceHybridInfoEnabled((longlong)param_1), (char)uVar9 == '\0'))
      goto LAB_140023d09;
      uVar6 = param_1[0x4a] | 0x90;
    }
    param_1[0x4a] = uVar6;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
    *(undefined4 *)(param_1 + 6) = uVar10;
  }
LAB_140023d09:
  uVar1 = puVar2[0xea];
  if ((uVar1 != 0) && (uVar5 = uVar1, 0xff < uVar1)) {
    uVar5 = 0x100;
  }
  *(ushort *)((longlong)param_1 + 0x1c4) = uVar5;
  uVar5 = puVar2[0xeb];
  if (uVar5 == 0) {
    *(undefined2 *)((longlong)param_1 + 0x1c6) = 0x100;
  }
  else {
    if (0xff < uVar5) {
      uVar5 = 0x100;
    }
    *(ushort *)((longlong)param_1 + 0x1c6) = uVar5;
  }
LAB_140023d51:
  FormatAtaId((char *)(param_1 + 8),(longlong)(puVar2 + 0x1b),0x28);
  FormatAtaId((char *)((longlong)param_1 + 0x69),(longlong)(puVar2 + 0x17),8);
  pcVar8 = (char *)((longlong)param_1 + 0x72);
  FormatAtaId(pcVar8,(longlong)(puVar2 + 10),0x14);
  SelectDeviceGeometry(pcVar8,(uint *)(param_1 + 3),(longlong)puVar2);
  return;
}



===== UpdateFirmwareIoctlReturnCode @ 140023db0 =====

void UpdateFirmwareIoctlReturnCode(longlong param_1)

{
  byte bVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar2 = GetSrbExtension(param_1);
  if (*(char *)(param_1 + 2) == '(') {
    lVar3 = *(longlong *)(param_1 + 0x40);
  }
  else {
    lVar3 = *(longlong *)(param_1 + 0x18);
  }
  if (lVar3 != 0) {
    bVar1 = *(byte *)(uVar2 + 0x1103);
    if ((char)bVar1 < '\0') {
      *(undefined4 *)(lVar3 + 0x14) = 0x80;
    }
    else if ((bVar1 & 0x40) == 0) {
      if ((bVar1 & 0x20) == 0) {
        if ((bVar1 & 0x10) == 0) {
          if ((bVar1 & 8) == 0) {
            if ((bVar1 & 4) == 0) {
              if ((bVar1 & 2) == 0) {
                *(uint *)(lVar3 + 0x14) = (-(uint)((bVar1 & 1) != 0) & 0x86) + 1;
              }
              else {
                *(undefined4 *)(lVar3 + 0x14) = 0x86;
              }
            }
            else {
              *(undefined4 *)(lVar3 + 0x14) = 0x85;
            }
          }
          else {
            *(undefined4 *)(lVar3 + 0x14) = 0x84;
          }
        }
        else {
          *(undefined4 *)(lVar3 + 0x14) = 0x83;
        }
      }
      else {
        *(undefined4 *)(lVar3 + 0x14) = 0x82;
      }
    }
    else {
      *(undefined4 *)(lVar3 + 0x14) = 0x40;
    }
  }
  return;
}



===== DiagAllDiagnosticData @ 140023e50 =====

undefined8 DiagAllDiagnosticData(longlong *param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  lVar2 = *param_1;
  uVar3 = 0;
  local_38 = 3;
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar1 = *(uint *)(param_2 + 0x20);
  if (uVar1 < 0x5fa8) {
    *(uint *)(param_2 + 0x20) = 0x5fa8;
    uVar3 = 0xc1000004;
    *(undefined4 *)(param_3 + 0x14) = 6;
  }
  else {
    memset((void *)(param_2 + 0x28),0,(ulonglong)uVar1);
    *(undefined4 *)(param_2 + 0x28) = 0x5fa8;
    *(undefined4 *)(param_2 + 0x2c) = 4;
    AhciInterruptSpinlockAcquire(lVar2,-1,(longlong)&local_38);
    if (param_1[0x8b9] != 0) {
      *(undefined4 *)(param_2 + 0x30) = 200;
      *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)((longlong)param_1 + 0x45c4);
      memcpy((void *)(param_2 + 0x38),(void *)param_1[0x8b9],24000);
    }
    *(undefined4 *)(param_2 + 0x5df8) = *(undefined4 *)param_1[0x129];
    *(undefined4 *)(param_2 + 0x5dfc) = *(undefined4 *)(param_1[0x129] + 4);
    *(undefined4 *)(param_2 + 0x5e00) = *(undefined4 *)(param_1[0x129] + 8);
    *(undefined4 *)(param_2 + 0x5e04) = *(undefined4 *)(param_1[0x129] + 0xc);
    *(undefined4 *)(param_2 + 0x5e08) = *(undefined4 *)(param_1[0x129] + 0x10);
    *(undefined4 *)(param_2 + 0x5e0c) = *(undefined4 *)(param_1[0x129] + 0x14);
    *(undefined4 *)(param_2 + 0x5e10) = *(undefined4 *)(param_1[0x129] + 0x18);
    *(undefined4 *)(param_2 + 0x5e14) = *(undefined4 *)(param_1[0x129] + 0x1c);
    *(undefined4 *)(param_2 + 0x5e18) = *(undefined4 *)(param_1[0x129] + 0x20);
    *(undefined4 *)(param_2 + 0x5e1c) = *(undefined4 *)(param_1[0x129] + 0x24);
    *(undefined4 *)(param_2 + 0x5e20) = *(undefined4 *)(param_1[0x129] + 0x28);
    *(undefined4 *)(param_2 + 0x5e24) = *(undefined4 *)(param_1[0x129] + 0x2c);
    *(undefined4 *)(param_2 + 0x5e28) = *(undefined4 *)(param_1[0x129] + 0x30);
    *(undefined4 *)(param_2 + 0x5e2c) = *(undefined4 *)(param_1[0x129] + 0x34);
    *(undefined4 *)(param_2 + 0x5e30) = *(undefined4 *)(param_1[0x129] + 0x38);
    *(undefined4 *)(param_2 + 0x5e34) = *(undefined4 *)(param_1[0x129] + 0x3c);
    *(undefined4 *)(param_2 + 0x5e38) = *(undefined4 *)(param_1[0x129] + 0x40);
    *(undefined4 *)(param_2 + 0x5e34) = *(undefined4 *)(param_1[0x129] + 0x3c);
    *(undefined4 *)(param_2 + 0x5e3c) = *(undefined4 *)(param_1[0x129] + 0x44);
    *(undefined4 *)(param_2 + 0x5e68) = *(undefined4 *)(param_1[0x129] + 0x70);
    *(undefined4 *)(param_2 + 0x5e6c) = *(undefined4 *)(param_1[0x129] + 0x74);
    *(undefined4 *)(param_2 + 0x5e70) = *(undefined4 *)(param_1[0x129] + 0x78);
    *(undefined4 *)(param_2 + 0x5e74) = *(undefined4 *)(param_1[0x129] + 0x7c);
    AhciInterruptSpinlockRelease(lVar2,-1,(longlong)&local_38);
    lVar2 = param_1[0x13];
    *(longlong *)(param_2 + 0x5e78) = param_1[0x12];
    *(longlong *)(param_2 + 0x5e80) = lVar2;
    lVar2 = param_1[0x15];
    *(longlong *)(param_2 + 0x5e88) = param_1[0x14];
    *(longlong *)(param_2 + 0x5e90) = lVar2;
    lVar2 = param_1[0x17];
    *(longlong *)(param_2 + 0x5e98) = param_1[0x16];
    *(longlong *)(param_2 + 0x5ea0) = lVar2;
    AhciFillDeviceFailureLog((longlong)param_1,(undefined4 *)(param_2 + 0x5ea8));
    *(undefined4 *)(param_2 + 0x20) = 0x5fa8;
  }
  return uVar3;
}



===== DiagGeneric @ 140024104 =====

undefined8 DiagGeneric(longlong *param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  longlong lVar4;
  
  if (*(char *)(param_2 + 2) == '(') {
    lVar4 = *(longlong *)(param_2 + 0x40);
    uVar1 = *(uint *)(param_2 + 0x3c);
  }
  else {
    lVar4 = *(longlong *)(param_2 + 0x18);
    uVar1 = *(uint *)(param_2 + 0x10);
  }
  *(undefined4 *)(lVar4 + 0x14) = 0;
  uVar3 = 1;
  if ((uVar1 < 0x48) || ((ulonglong)uVar1 < (ulonglong)*(uint *)(lVar4 + 0x18) + 0x1c)) {
    *(undefined4 *)(lVar4 + 0x14) = 1;
    uVar2 = 0xc1000004;
  }
  else if (((((*(char *)(lVar4 + 4) == 'S') && (*(char *)(lVar4 + 5) == 'T')) &&
            (*(char *)(lVar4 + 6) == 'O')) &&
           ((*(char *)(lVar4 + 7) == 'R' && (*(char *)(lVar4 + 8) == 'D')))) &&
          ((*(char *)(lVar4 + 9) == 'I' &&
           ((*(char *)(lVar4 + 10) == 'A' && (*(char *)(lVar4 + 0xb) == 'G')))))) {
    if (*(int *)(lVar4 + 0x1c) == 0x2c) {
      if (*(int *)(lVar4 + 0x20) == *(int *)(lVar4 + 0x3c) + 0x28) {
        if (*(int *)(lVar4 + 0x24) == 2) {
          *(undefined8 *)(lVar4 + 0x2c) = 0x41acbecc735c4667;
          *(undefined8 *)(lVar4 + 0x34) = 0x96fbc637b331d8b5;
          if (*(int *)(lVar4 + 0x28) == 0) {
            uVar2 = DiagAllDiagnosticData(param_1,lVar4 + 0x1c,lVar4);
            if (((int)uVar2 != 0) && ((int)uVar2 != -0x3efffffc)) {
              uVar3 = 4;
            }
            goto LAB_140024220;
          }
        }
        else {
          *(undefined4 *)(lVar4 + 0x14) = 5;
        }
      }
      else {
        *(undefined4 *)(lVar4 + 0x14) = 3;
      }
      uVar2 = 0xc1000006;
    }
    else {
      *(undefined4 *)(lVar4 + 0x14) = 2;
      uVar2 = 0xc100000b;
    }
  }
  else {
    *(undefined4 *)(lVar4 + 0x14) = 4;
    uVar2 = 0xc1000007;
  }
  uVar3 = 6;
LAB_140024220:
  *(undefined1 *)(param_2 + 3) = uVar3;
  return uVar2;
}



===== _guard_check_icall @ 140024240 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140024258 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14002427c =====

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



===== __cpu_features_init @ 1400242f0 =====

/* WARNING: Removing unreachable block (ram,0x00014002435a) */
/* WARNING: Removing unreachable block (ram,0x000140024309) */
/* WARNING: Removing unreachable block (ram,0x0001400242fa) */

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



===== __security_check_cookie @ 1400243c0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140024400 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140024430 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140024430. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140024460 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1400244c0 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

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



===== memset @ 1400247c0 =====

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



===== __memset_repmovs @ 140024900 =====

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



===== __memset_query @ 140024980 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140024a00 =====

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



===== __memset_spec_ermsb_repmovsb @ 140024b40 =====

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



===== __memset_spec_plain @ 140024bc0 =====

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



===== FUN_140024dfc @ 140024dfc =====

/* PDB: Separated code (from the compiler): 140024dfc - 1400254b1 for parent address: 140002440 */

ulonglong FUN_140024dfc(longlong param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  uint unaff_EBP;
  longlong unaff_RDI;
  longlong *unaff_R15;
  
  for (; param_2 <= param_3; param_2 = param_2 + 1) {
    lVar1 = *(longlong *)(param_1 + 0x1b0 + (ulonglong)param_2 * 8);
    if ((lVar1 != 0) &&
       ((*(uint *)(lVar1 + 0x18) == unaff_EBP || ((*(uint *)(lVar1 + 0x250) & 0x100000) == 0))))
    goto LAB_140002617;
  }
  if ((*(uint *)(unaff_R15 + 4) & 0x10) == 0) {
    uVar2 = InquiryComplete(unaff_R15,unaff_RDI);
    return uVar2;
  }
LAB_140002617:
  IssueIdentifyCommand((longlong)unaff_R15,unaff_RDI);
  return (ulonglong)unaff_EBP;
}



===== FUN_140025601 @ 140025601 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_140025601(uint param_1,undefined8 param_2,uint param_3)

{
  longlong *plVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 uVar11;
  bool bVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  undefined8 *puVar17;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined8 uVar18;
  ulonglong uVar19;
  undefined8 *puVar20;
  longlong *unaff_RBX;
  void *unaff_RBP;
  longlong unaff_RSI;
  byte unaff_DIL;
  ulonglong in_R10;
  undefined4 *puVar21;
  int unaff_R14D;
  ulonglong uVar22;
  undefined8 *puVar23;
  longlong unaff_R15;
  longlong lVar24;
  longlong lVar25;
  
  for (; param_1 < param_3; param_1 = param_1 + 1) {
    uVar15 = *(uint *)((longlong)unaff_RBX + (ulonglong)param_1 * 4 + 0x78);
    if (((0x7f < uVar15) && (uVar15 < *(uint *)(unaff_RBX + 2))) &&
       (uVar19 = (longlong)unaff_RBX + (ulonglong)uVar15,
       *(int *)((longlong)unaff_RBX + (ulonglong)uVar15) == 0x61)) goto LAB_14002563a;
  }
  uVar19 = in_R10;
LAB_14002563a:
  if ((*(byte *)(uVar19 + 8) & 1) != 0) {
    uVar11 = switchD_140003bfd::caseD_8();
    return CONCAT71(extraout_var_00,uVar11);
  }
  if ((*(uint *)(unaff_RSI + 0x184) < (uint)unaff_DIL) ||
     (*(longlong *)(unaff_RSI + 0x1b0 + (ulonglong)unaff_DIL * 8) == unaff_R15)) {
    *(undefined1 *)((longlong)unaff_RBX + 3) = 8;
    bVar12 = AhciIsEventAllowedWithinThrottleLimit
                       (unaff_RSI,0,0x26,(int *)((longlong)unaff_RBP + -0x80));
    if (bVar12) {
      StorPortExtendedFunction(0x57);
    }
  }
  else {
    plVar1 = (longlong *)(unaff_RSI + ((ulonglong)unaff_DIL + 0x36) * 8);
    lVar25 = *(longlong *)(unaff_RSI + ((ulonglong)unaff_DIL + 0x36) * 8);
    *(longlong *)((longlong)unaff_RBP + -0x70) = lVar25;
    *(longlong *)((longlong)unaff_RBP + -0x78) = lVar25 + 8;
    if ((*(uint *)(unaff_RSI + 0x5c) & 4) != 0) {
      AhciSimulateThrottledEtwEvent(unaff_RSI,0,0x26);
      AhciSimulateThrottledEtwEvent(unaff_RSI,*(longlong *)((longlong)unaff_RBP + -0x70),0x30);
      in_R10 = 0;
    }
    if (unaff_R14D == 0) {
LAB_1400038f5:
      AhciProcessIo(*(longlong **)(unaff_RSI + 0x1b0 + (ulonglong)unaff_DIL * 8),unaff_RBX,0);
      puVar17 = (undefined8 *)
                ActivateQueue(*(longlong **)(unaff_RSI + 0x1b0 + (ulonglong)unaff_DIL * 8),'\0');
      goto LAB_14000391f;
    }
    switch(unaff_R14D) {
    case 2:
      if (*(char *)((longlong)unaff_RBX + 2) == '(') {
        uVar15 = *(uint *)(unaff_RBX + 3);
      }
      else {
        uVar15 = *(uint *)((longlong)unaff_RBX + 0xc);
      }
      if ((uVar15 >> 0xb & 1) == 0) {
        PortAcquireActiveReference
                  (*(undefined8 **)(unaff_RSI + 0x1b0 + (ulonglong)unaff_DIL * 8),
                   (longlong)unaff_RBX,(undefined1 *)0x0);
      }
      goto LAB_1400038f5;
    default:
      *(undefined1 *)((longlong)unaff_RBX + 3) = 6;
      StorPortExtendedFunction(0x55);
      goto LAB_140026335;
    case 7:
      bVar12 = (byte)(*(char *)(unaff_RSI + 0x18c) - 1U) < 2;
      *(uint *)(*plVar1 + 0x20) = *(uint *)(*plVar1 + 0x20) | 2;
      lVar25 = *(longlong *)(unaff_RSI + 0x1b0 + (ulonglong)unaff_DIL * 8);
      if ((*(uint *)(lVar25 + 0x170) & 0x10) == 0) {
        if (bVar12) {
          uVar19 = GetSrbExtension((longlong)unaff_RBX);
          *(undefined2 *)(uVar19 + 0x1100) = 0x100;
          *(undefined1 *)(uVar19 + 0x110e) = 0xe0;
          uVar19 = FUN_140003b59();
          return uVar19;
        }
        *(undefined1 *)((longlong)unaff_RBX + 3) = 1;
        StorPortNotification(0);
      }
      else {
        IssueSetDateAndTimeCommand(lVar25,(longlong)unaff_RBX,bVar12);
      }
      uVar19 = FUN_140003b59();
      return uVar19;
    case 0x12:
    case 0x13:
    case 0x20:
      AhciInterruptSpinlockAcquire(unaff_RSI,(uint)unaff_DIL,(longlong)unaff_RBP + -0x60);
      LOCK();
      *(uint *)(*plVar1 + 0x250) = *(uint *)(*plVar1 + 0x250) | 0x800000;
      UNLOCK();
      uVar18 = AhciPortReset((ulonglong *)*plVar1,'\x01');
      uVar11 = 1;
      if ((char)uVar18 == '\0') {
        uVar11 = 4;
      }
      *(undefined1 *)((longlong)unaff_RBX + 3) = uVar11;
      StorPortNotification(0);
      AhciInterruptSpinlockRelease(unaff_RSI,(uint)unaff_DIL,(longlong)unaff_RBP + -0x60);
      lVar25 = *plVar1;
      *(longlong *)((longlong)unaff_RBP + -0x78) = unaff_R15;
      *(int *)(lVar25 + 0xb4) = *(int *)(lVar25 + 0xb4) + 1;
      puVar7 = (undefined8 *)*plVar1;
      *(ulonglong *)((longlong)unaff_RBP + -0x80) = (ulonglong)*(byte *)((longlong)unaff_RBX + 3);
      puVar17 = puVar7 + 1;
      *(undefined8 **)((longlong)unaff_RBP + -0x68) = puVar17;
      if ((puVar7 != (undefined8 *)0x0) && (*(int *)(puVar7 + 3) != 2)) {
        StorPortQuerySystemTime((longlong)unaff_RBP + -0x78);
        puVar17 = *(undefined8 **)((longlong)unaff_RBP + -0x78);
        if ((puVar7[0x8be] == 0) || (35999999999 < (ulonglong)((longlong)puVar17 - puVar7[0x8be])))
        {
          uVar3 = *(undefined4 *)(puVar7 + 0x8bc);
          uVar4 = *(undefined4 *)((longlong)puVar7 + 0x45d4);
          uVar15 = *(uint *)(puVar7 + 0x8bd);
          uVar18 = puVar7[0x49];
          uVar8 = puVar7[0x4a];
          uVar14 = *(uint *)((longlong)puVar7 + 0xb4);
          puVar7[0x8be] = puVar17;
          uVar5 = *(undefined4 *)((longlong)puVar7 + 0x45e4);
          uVar6 = *(undefined4 *)((longlong)puVar7 + 0x45dc);
          memset((void *)((longlong)unaff_RBP + -0x40),0,0x180);
          *(undefined4 *)((longlong)unaff_RBP + -0x40) = 1;
          *(undefined4 *)((longlong)unaff_RBP + -0x3c) = 8;
          uVar13 = GetStringLength("AhciHwStartIo RESET Request",0x20);
          memcpy((void *)((longlong)unaff_RBP + -0x38),"AhciHwStartIo RESET Request",
                 (ulonglong)uVar13);
          *(undefined8 *)((longlong)unaff_RBP + -0x18) = 1;
          uVar13 = GetStringLength("PortReset|PortErrorRecovery",0x20);
          memcpy(unaff_RBP,"PortReset|PortErrorRecovery",(ulonglong)uVar13);
          *(ulonglong *)((longlong)unaff_RBP + 0x20) =
               CONCAT44(*(undefined4 *)(puVar7 + 0x8ba),*(undefined4 *)(puVar7 + 0x8bb));
          uVar13 = GetStringLength("StartFail|NonQErrorRecovery",0x20);
          memcpy((void *)((longlong)unaff_RBP + 0x28),"StartFail|NonQErrorRecovery",
                 (ulonglong)uVar13);
          *(ulonglong *)((longlong)unaff_RBP + 0x48) = CONCAT44(uVar4,uVar6);
          uVar13 = GetStringLength("NCQError|NCQErrorComplete",0x20);
          memcpy((void *)((longlong)unaff_RBP + 0x50),"NCQError|NCQErrorComplete",(ulonglong)uVar13)
          ;
          *(ulonglong *)((longlong)unaff_RBP + 0x70) = CONCAT44(uVar3,uVar5);
          uVar13 = GetStringLength("PortDriverResetCount",0x20);
          memcpy((void *)((longlong)unaff_RBP + 0x78),"PortDriverResetCount",(ulonglong)uVar13);
          *(ulonglong *)((longlong)unaff_RBP + 0x98) = (ulonglong)uVar14;
          uVar14 = GetStringLength("StateFlags",0x20);
          memcpy((void *)((longlong)unaff_RBP + 0xa0),"StateFlags",(ulonglong)uVar14);
          *(undefined8 *)((longlong)unaff_RBP + 0xc0) = uVar8;
          uVar14 = GetStringLength("StartState",0x20);
          memcpy((void *)((longlong)unaff_RBP + 200),"StartState",(ulonglong)uVar14);
          *(undefined8 *)((longlong)unaff_RBP + 0xe8) = uVar18;
          uVar14 = GetStringLength("TotalCountSurpriseRemove",0x20);
          memcpy((void *)((longlong)unaff_RBP + 0xf0),"TotalCountSurpriseRemove",(ulonglong)uVar14);
          *(ulonglong *)((longlong)unaff_RBP + 0x110) = (ulonglong)uVar15;
          uVar15 = GetStringLength("PortResetStatus",0x20);
          memcpy((void *)((longlong)unaff_RBP + 0x118),"PortResetStatus",(ulonglong)uVar15);
          uVar18 = *puVar7;
          *(undefined8 *)((longlong)unaff_RBP + 0x138) =
               *(undefined8 *)((longlong)unaff_RBP + -0x80);
          puVar17 = (undefined8 *)
                    StorPortExtendedFunction
                              (0x4f,uVar18,*(undefined8 *)((longlong)unaff_RBP + -0x68),
                               (longlong)unaff_RBP + -0x40);
        }
      }
      goto LAB_14000391f;
    case 0x25:
      if ((*(char *)((longlong)unaff_RBX + 2) == '(') && (*(uint *)(unaff_RBX + 7) != 0)) {
        for (uVar19 = in_R10 & 0xffffffff; (uint)uVar19 < *(uint *)(unaff_RBX + 7);
            uVar19 = (ulonglong)((uint)uVar19 + 1)) {
          uVar15 = *(uint *)((longlong)unaff_RBX + uVar19 * 4 + 0x78);
          if (((0x7f < uVar15) && (uVar15 < *(uint *)(unaff_RBX + 2))) &&
             (uVar22 = (longlong)unaff_RBX + (ulonglong)uVar15,
             *(int *)((longlong)unaff_RBX + (ulonglong)uVar15) == 0x62)) goto LAB_1400039bc;
        }
      }
      uVar22 = in_R10;
LAB_1400039bc:
      if (((*(uint *)(uVar22 + 0x10) & 1) == 0) && (*(int *)(uVar22 + 0xc) == 9)) {
        if (*(char *)((longlong)unaff_RBX + 2) == '(') {
          uVar15 = *(uint *)((longlong)unaff_RBX + 0x3c);
        }
        else {
          uVar15 = *(uint *)(unaff_RBX + 2);
        }
        if (uVar15 < 0x18) goto LAB_140003b37;
        if (*(char *)((longlong)unaff_RBX + 2) == '(') {
          lVar25 = unaff_RBX[8];
        }
        else {
          lVar25 = unaff_RBX[3];
        }
        *(uint *)(lVar25 + 4) =
             ((*(uint *)(*(longlong *)(unaff_RSI + 0x1b0 + (ulonglong)unaff_DIL * 8) + 0x244) & 1)
              << 4 ^ *(uint *)(lVar25 + 4) & 0xffffffef) & 0xfffff990 | 0x80;
        *(undefined1 *)((longlong)unaff_RBX + 3) = 1;
      }
      else {
LAB_140003b37:
        *(undefined1 *)((longlong)unaff_RBX + 3) = 6;
      }
      StorPortNotification(0);
      if (*(char *)((longlong)unaff_RBX + 3) != '\x01') {
        bVar12 = AhciIsEventAllowedWithinThrottleLimit
                           (unaff_RSI,*(longlong *)((longlong)unaff_RBP + -0x70),0x28,
                            (int *)((longlong)unaff_RBP + -0x80));
        puVar17 = (undefined8 *)CONCAT71(extraout_var,bVar12);
        if (!bVar12) goto LAB_14000391f;
      }
      puVar17 = (undefined8 *)StorPortExtendedFunction(0x56);
      goto LAB_14000391f;
    case 0x26:
      cVar2 = *(char *)((longlong)unaff_RBX + 2);
      *(ulonglong *)((longlong)unaff_RBP + -0x80) = in_R10;
      if (cVar2 == '(') {
        puVar21 = (undefined4 *)unaff_RBX[8];
      }
      else {
        puVar21 = (undefined4 *)unaff_RBX[3];
      }
      if (puVar21 != (undefined4 *)0x0) {
        if (cVar2 == '(') {
          uVar15 = *(uint *)((longlong)unaff_RBX + 0x3c);
        }
        else {
          uVar15 = *(uint *)(unaff_RBX + 2);
        }
        if ((0x47 < uVar15) && ((*(uint *)(unaff_RSI + 0x38) & 0x100000) != 0)) {
          iVar16 = StorPortExtendedFunction(0);
          if ((iVar16 == 0) && (*(longlong *)((longlong)unaff_RBP + -0x80) != unaff_R15)) {
            *puVar21 = 0x700100;
            memset(*(void **)((longlong)unaff_RBP + -0x80),0,0x200);
            **(undefined2 **)((longlong)unaff_RBP + -0x80) = *(undefined2 *)(unaff_RSI + 0x10);
            *(undefined2 *)(*(longlong *)((longlong)unaff_RBP + -0x80) + 2) =
                 *(undefined2 *)(unaff_RSI + 0x12);
            *(undefined1 *)(*(longlong *)((longlong)unaff_RBP + -0x80) + 4) =
                 *(undefined1 *)(unaff_RSI + 0x14);
            *(undefined4 *)(*(longlong *)((longlong)unaff_RBP + -0x80) + 8) =
                 *(undefined4 *)(unaff_RSI + 0xc);
            *(undefined4 *)(*(longlong *)((longlong)unaff_RBP + -0x80) + 0xc) =
                 *(undefined4 *)(unaff_RSI + 0x34);
            puVar17 = (undefined8 *)(*(longlong *)((longlong)unaff_RBP + -0x80) + 0x10);
            puVar7 = (undefined8 *)(unaff_RSI + 0x38);
            lVar25 = 2;
            do {
              lVar24 = lVar25;
              puVar23 = puVar7;
              puVar20 = puVar17;
              uVar18 = puVar23[1];
              *puVar20 = *puVar23;
              puVar20[1] = uVar18;
              uVar18 = puVar23[3];
              puVar20[2] = puVar23[2];
              puVar20[3] = uVar18;
              uVar18 = puVar23[5];
              puVar20[4] = puVar23[4];
              puVar20[5] = uVar18;
              uVar18 = puVar23[7];
              puVar20[6] = puVar23[6];
              puVar20[7] = uVar18;
              uVar18 = puVar23[9];
              puVar20[8] = puVar23[8];
              puVar20[9] = uVar18;
              uVar18 = puVar23[0xb];
              puVar20[10] = puVar23[10];
              puVar20[0xb] = uVar18;
              uVar18 = puVar23[0xd];
              puVar20[0xc] = puVar23[0xc];
              puVar20[0xd] = uVar18;
              uVar18 = puVar23[0xf];
              puVar20[0xe] = puVar23[0xe];
              puVar20[0xf] = uVar18;
              lVar25 = lVar24 + -1;
              puVar17 = puVar20 + 0x10;
              puVar7 = puVar23 + 0x10;
            } while (lVar25 != 0);
            uVar18 = puVar23[0x11];
            puVar20[0x10] = puVar23[0x10];
            puVar20[0x11] = uVar18;
            uVar18 = puVar23[0x13];
            puVar20[0x12] = puVar23[0x12];
            puVar20[0x13] = uVar18;
            uVar18 = puVar23[0x15];
            puVar20[0x14] = puVar23[0x14];
            puVar20[0x15] = uVar18;
            uVar18 = puVar23[0x17];
            puVar20[0x16] = puVar23[0x16];
            puVar20[0x17] = uVar18;
            puVar20[0x18] = puVar23[0x18];
            *(undefined4 *)(*(longlong *)((longlong)unaff_RBP + -0x80) + 0x19c) = 1;
            lVar25 = unaff_RSI + (ulonglong)unaff_DIL * 8;
            *(undefined4 *)(*(longlong *)((longlong)unaff_RBP + -0x80) + 0x1a0) =
                 *(undefined4 *)(*(longlong *)(lVar25 + 0x1b0) + 0x240);
            lVar9 = *(longlong *)(lVar25 + 0x1b0);
            lVar10 = *(longlong *)((longlong)unaff_RBP + -0x80);
            uVar18 = *(undefined8 *)(lVar9 + 0x260);
            *(undefined8 *)(lVar10 + 0x1a4) = *(undefined8 *)(lVar9 + 600);
            *(undefined8 *)(lVar10 + 0x1ac) = uVar18;
            *(undefined8 *)(lVar10 + 0x1b4) = *(undefined8 *)(lVar9 + 0x268);
            *(undefined4 *)(lVar10 + 0x1bc) = *(undefined4 *)(lVar9 + 0x270);
            lVar25 = *(longlong *)(lVar25 + 0x1b0);
            uVar19 = IsDeviceHybridInfoSupported(lVar25);
            if ((char)uVar19 != '\0') {
              memcpy((void *)(*(longlong *)((longlong)unaff_RBP + -0x80) + 0x1c0),
                     (void *)(lVar25 + 0x180),(ulonglong)((int)lVar24 + 0x3f));
            }
            lVar25 = *(longlong *)((longlong)unaff_RBP + -0x80);
            *(undefined8 *)(lVar25 + 0x158) = 0;
            *(undefined8 *)(lVar25 + 0x160) = 0;
            *(undefined8 *)(lVar25 + 0x168) = 0;
            *(undefined8 *)(lVar25 + 0x170) = 0;
            *(undefined8 *)(lVar25 + 0x178) = 0;
            *(undefined8 *)(lVar25 + 0x180) = 0;
            *(undefined8 *)(lVar25 + 0x188) = 0;
            *(undefined8 *)(lVar25 + 400) = 0;
            *(undefined4 *)(*(longlong *)((longlong)unaff_RBP + -0x80) + 0x198) = 0;
            lVar25 = *(longlong *)((longlong)unaff_RBP + -0x80);
            if (*(int *)(lVar25 + 0x198) == 0) {
              *(undefined4 *)(lVar25 + 0x198) = 0x24;
              lVar25 = *(longlong *)((longlong)unaff_RBP + -0x80);
            }
            *(longlong *)(puVar21 + 0x10) = lVar25;
            *(undefined1 *)((longlong)unaff_RBX + 3) = 1;
          }
          else {
            *(undefined1 *)((longlong)unaff_RBX + 3) = 4;
          }
          break;
        }
      }
      *(undefined1 *)((longlong)unaff_RBX + 3) = 6;
      break;
    case 0x27:
      if (*(char *)((longlong)unaff_RBX + 2) == '(') {
        lVar25 = unaff_RBX[8];
      }
      else {
        lVar25 = unaff_RBX[3];
      }
      if (lVar25 == 0) {
LAB_140026169:
        uVar11 = 6;
      }
      else {
        if (*(char *)((longlong)unaff_RBX + 2) == '(') {
          uVar15 = *(uint *)((longlong)unaff_RBX + 0x3c);
        }
        else {
          uVar15 = *(uint *)(unaff_RBX + 2);
        }
        if (uVar15 < 0x48) goto LAB_140026169;
        iVar16 = StorPortExtendedFunction(1);
        uVar11 = 1;
        if (iVar16 != 0) {
          uVar11 = 4;
        }
      }
      *(undefined1 *)((longlong)unaff_RBX + 3) = uVar11;
    }
    StorPortExtendedFunction(0x55);
  }
LAB_140026335:
  puVar17 = (undefined8 *)StorPortNotification(0);
LAB_14000391f:
  return CONCAT71((int7)((ulonglong)puVar17 >> 8),1);
}



===== entry @ 140033010 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140033044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte in_DL;
  byte in_DH;
  undefined1 unaff_BL;
  char unaff_BH;
  undefined6 unaff_0000001a;
  undefined1 *unaff_RBP;
  
  if ((__security_cookie != 0) && (__security_cookie != 0x2b992ddfa232)) {
    ___security_cookie_complement = ~__security_cookie;
    return;
  }
  pbVar5 = (byte *)0x6;
  pcVar2 = (code *)swi(0x29);
  pbVar4 = (byte *)(*pcVar2)();
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
  *pbVar4 = *pbVar4 + bVar3;
  *(byte *)CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) =
       *(byte *)CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) & in_DL;
  bVar1 = *pbVar4;
  *pbVar4 = *pbVar4 + bVar3;
  if (SCARRY1(bVar1,bVar3)) {
    *(int *)pbVar5 = *(int *)pbVar5 + (int)pbVar4;
    pbVar4[-0x7ffffefc] = pbVar4[-0x7ffffefc] + bVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar1 = *pbVar4;
  *pbVar4 = *pbVar4 + bVar3;
  *pbVar4 = *pbVar4 + unaff_BH + CARRY1(bVar1,bVar3);
  *pbVar4 = *pbVar4 + bVar3;
  *unaff_RBP = *unaff_RBP;
  *pbVar5 = *pbVar5 ^ in_DH;
  pbVar4[0x72] = pbVar4[0x72] + in_DH;
  *pbVar4 = *pbVar4 + bVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


