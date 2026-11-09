
===== BuildIeeeScatterGather @ 140001000 =====

ulonglong BuildIeeeScatterGather
                    (longlong param_1,longlong param_2,int param_3,longlong param_4,longlong param_5
                    ,ushort param_6,int *param_7)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  uint *puVar7;
  uint *puVar8;
  longlong lVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  uint uVar19;
  
  puVar11 = (uint *)(param_4 + 0x80);
  puVar1 = (uint *)(param_4 + 0x40);
  uVar19 = 0;
  lVar9 = param_5 + 0x80;
  iVar17 = 0;
  uVar12 = 3;
  uVar15 = 0x40000;
  if ((*(uint *)(param_2 + 0x18) & 0x80) == 0) {
    uVar15 = 0x80000;
  }
  *(uint *)(param_4 + 0xc) = *(uint *)(param_4 + 0xc) | uVar15;
  puVar4 = (uint *)StorPortGetScatterGatherList(param_1);
  if (puVar4 == (uint *)0x0) {
    param_5._0_4_ = 3;
    uVar6 = 0;
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x29f) != 0)) {
      uVar6 = RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x29f,(undefined1 *)&param_5,4,
                          param_6,param_7);
    }
    uVar6 = uVar6 & 0xffffffffffffff00;
    *(undefined1 *)(param_2 + 3) = 4;
  }
  else {
    puVar8 = puVar4 + 4;
    uVar15 = *puVar4;
    uVar10 = param_3 - *(int *)(param_2 + 0x40);
    if (uVar10 != 0) {
      puVar7 = puVar4 + 6;
      puVar4 = (uint *)(ulonglong)*puVar7;
      if (*puVar7 <= uVar10) {
        do {
          puVar18 = puVar8 + 6;
          uVar10 = uVar10 - (int)puVar4;
          uVar15 = uVar15 - 1;
          puVar7 = puVar8 + 8;
          puVar4 = (uint *)(ulonglong)*puVar7;
          puVar8 = puVar18;
        } while (*puVar7 <= uVar10);
      }
      uVar16 = *(uint *)(param_2 + 0x3c);
      uVar14 = 0;
      puVar7 = puVar8;
      if (uVar15 != 0) {
        do {
          uVar5 = puVar7[2] - uVar10;
          if (puVar7 != puVar8) {
            uVar5 = puVar7[2];
          }
          uVar2 = uVar16;
          iVar3 = uVar5 - uVar16;
          if (uVar5 <= uVar16) {
            uVar2 = uVar5;
            iVar3 = iVar17;
          }
          iVar17 = iVar3;
          puVar4 = (uint *)(ulonglong)uVar2;
          uVar16 = uVar16 - uVar2;
          if (uVar16 == 0) break;
          uVar14 = uVar14 + 1;
          puVar7 = puVar7 + 6;
        } while (uVar14 < uVar15);
      }
      uVar15 = uVar14 + 1;
    }
    puVar7 = puVar1;
    puVar18 = (uint *)0x0;
    uVar16 = 3;
    if (uVar15 < 5) {
      uVar16 = uVar15;
    }
    while( true ) {
      puVar13 = puVar7;
      uVar14 = 0;
      if (uVar16 != 0) {
        uVar6 = (ulonglong)uVar16;
        do {
          *puVar13 = *puVar8;
          puVar13[1] = puVar8[1];
          puVar7 = puVar8 + 2;
          puVar4 = (uint *)(ulonglong)*puVar7;
          puVar8 = puVar8 + 6;
          puVar13[2] = *puVar7;
          puVar13[3] = 0;
          puVar13 = puVar13 + 4;
          uVar6 = uVar6 - 1;
          uVar14 = uVar16;
        } while (uVar6 != 0);
      }
      uVar19 = uVar19 + uVar14;
      if (uVar15 <= uVar19) break;
      if (uVar19 == uVar12) {
        uVar12 = 0xff;
      }
      if (puVar18 != (uint *)0x0) {
        puVar11 = puVar11 + 0x400;
        puVar18[2] = (uVar14 + 1) * 0x10;
        lVar9 = lVar9 + 0x1000;
      }
      *puVar13 = (uint)lVar9;
      puVar13[1] = (uint)((ulonglong)lVar9 >> 0x20);
      puVar4 = (uint *)(ulonglong)(uVar12 + 1);
      puVar13[3] = 0x30000000;
      puVar7 = puVar11;
      puVar18 = puVar13;
      uVar16 = uVar15 - uVar19;
      if (uVar12 + 1 < uVar15 - uVar19) {
        uVar16 = uVar12;
      }
    }
    puVar13[-1] = puVar13[-1] | 0x8000000;
    if (iVar17 != 0) {
      puVar13[-2] = puVar13[-2] - iVar17;
    }
    if (puVar18 != (uint *)0x0) {
      puVar18[2] = uVar14 << 4;
    }
    uVar6 = CONCAT71((int7)((ulonglong)puVar4 >> 8),1);
    if (uVar10 != 0) {
      *puVar1 = *puVar1 + uVar10;
      *(int *)(param_4 + 0x48) = *(int *)(param_4 + 0x48) - uVar10;
    }
  }
  return uVar6;
}



===== mpi3BuildIo @ 140001280 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 mpi3BuildIo(longlong param_1,longlong param_2)

{
  void *pvVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  short sVar5;
  longlong lVar6;
  byte *pbVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  undefined8 uVar12;
  uint uVar13;
  int *piVar14;
  short *psVar15;
  uint uVar16;
  ulonglong uVar17;
  ushort uVar18;
  ushort uVar19;
  short sVar20;
  char *pcVar21;
  undefined1 auStackY_b8 [32];
  int local_70;
  undefined1 local_6c;
  undefined4 local_68 [2];
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_58;
  short local_50;
  byte local_4e;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar6 = *(longlong *)(param_2 + 0x68);
  uVar17 = 0;
  local_70 = 0;
  local_6c = 0;
  if (*(char *)(param_2 + 2) == '(') {
    if (*(int *)(param_1 + 0x428) == 0) {
      if ((*(char *)(param_1 + 0x411) == '\0') || (*(char *)(param_1 + 0x417) != '\0')) {
        *(undefined1 *)(param_2 + 3) = 0x11;
      }
      else {
        psVar15 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2);
        if (*psVar15 == 1) {
          bVar2 = *(byte *)(psVar15 + 4);
          *(byte *)(lVar6 + 0x4a) = bVar2;
          bVar3 = *(byte *)((longlong)psVar15 + 9);
          *(byte *)(lVar6 + 0x4b) = bVar3;
          sVar8 = psVar15[5];
          *(char *)(lVar6 + 0x4c) = (char)sVar8;
          switch(*(undefined4 *)(param_2 + 0x14)) {
          case 0:
            uVar16 = 0;
            if (*(uint *)(param_2 + 0x38) == 0) {
              return 1;
            }
            while( true ) {
              piVar14 = (int *)((ulonglong)*(uint *)(param_2 + 0x78 + (ulonglong)uVar16 * 4) +
                               param_2);
              iVar10 = *piVar14;
              if (iVar10 - 0x40U < 2) break;
              uVar16 = uVar16 + 1;
              if (*(uint *)(param_2 + 0x38) <= uVar16) {
                return 1;
              }
            }
            *(int **)(lVar6 + 0x30) = piVar14;
            cVar4 = (char)piVar14[6];
            *(char *)(lVar6 + 0x48) = cVar4;
            *(undefined1 *)(lVar6 + 0x49) = *(undefined1 *)((longlong)piVar14 + 0x19);
            if ((((uint)bVar2 == *(ushort *)(param_1 + 0x374) - 1) && (cVar4 == '\x12')) &&
               (bVar3 == 0x80)) {
              *(undefined1 *)(param_1 + 0x422) = 1;
            }
            uVar18 = (ushort)bVar2 * 0x80 + (ushort)bVar3;
            if (uVar18 < *(ushort *)(param_1 + 0x372)) {
              lVar11 = *(longlong *)(param_1 + 0x9f8) + (ulonglong)uVar18 * 0x18;
              sVar5 = *(short *)(*(longlong *)(param_1 + 0x9f8) + 8 + (ulonglong)uVar18 * 0x18);
              if ((sVar5 != 0) && ((*(byte *)(lVar11 + 0x16) & 2) == 0)) {
                if ((*(char *)(param_1 + 0x397) == '\0') || ((cVar4 != '5' && (cVar4 != -0x6f)))) {
                  if ((*(char *)(lVar11 + 0x14) == '\x01') && (cVar4 == 'B')) {
                    pbVar7 = *(byte **)(param_2 + 0x20);
                    uVar18 = CONCAT11(*(undefined1 *)((longlong)piVar14 + 0x1f),(char)piVar14[8]);
                    if (uVar18 < 0x18) {
                      if (uVar18 == 0) {
                        *(undefined2 *)(param_2 + 3) = 1;
                        pcVar21 = "SCSI Unmap: Parameter List Length = 0, return Success to OS";
                      }
                      else {
                        *(undefined1 *)(param_2 + 4) = 2;
                        ZeroMemory(pbVar7,0x12);
                        pcVar21 = 
                        "SCSI Unmap: Parameter List Length 1 to 23, return 05/1A sense data to OS";
                        pbVar7[0xc] = 0x1a;
                        pbVar7[0xd] = 0;
                        pbVar7[7] = 10;
                        *pbVar7 = *pbVar7 & 0xf0 | 0x70;
                        pbVar7[2] = pbVar7[2] & 0xf5 | 5;
                      }
                      LogSystemEvent(param_1,0,0x4004af00,(byte *)pcVar21,0,&local_70);
                      *(int *)(param_1 + 0x8f4) = *(int *)(param_1 + 0x8f4) + 1;
                      break;
                    }
                    uVar19 = CONCAT11(*(undefined1 *)(*(longlong *)(param_2 + 0x40) + 2),
                                      *(undefined1 *)(*(longlong *)(param_2 + 0x40) + 3));
                    if (uVar19 + 8 < (uint)uVar18) {
                      sVar20 = uVar19 + 8;
                      *(char *)(piVar14 + 8) = (char)sVar20;
                      *(char *)((longlong)piVar14 + 0x1f) = (char)((ushort)sVar20 >> 8);
                      LogSystemEvent(param_1,0,0x4004af00,
                                     (byte *)
                                     "SCSI Unmap: Truncated Parameter List Length to match Unmap Block Descriptor Data Length"
                                     ,0,&local_70);
                    }
                    *(int *)(param_1 + 0x8f0) = *(int *)(param_1 + 0x8f0) + 1;
                  }
                  pvVar1 = (void *)(lVar6 + 0x60);
                  uVar16 = *(uint *)(param_2 + 0x18);
                  if (((ulonglong)pvVar1 & 0xf) != 0) {
                    local_68[0] = _DAT_0000dcba;
                  }
                  ZeroMemory(pvVar1,0x80);
                  *(short *)(lVar6 + 0x6a) = sVar5;
                  *(undefined1 *)(lVar6 + 99) = 0x20;
                  if ((uVar16 & 2) == 0) {
                    uVar13 = 0;
                  }
                  else {
                    uVar13 = (*(ushort *)(param_2 + 0x26) & 3) << 0x18;
                  }
                  uVar9 = uVar13 | 0x20000000;
                  if (iVar10 != 0x41) {
                    uVar9 = uVar13;
                  }
                  *(uint *)(lVar6 + 0x6c) = uVar9;
                  *(undefined4 *)(lVar6 + 0x74) = *(undefined4 *)(param_2 + 0x3c);
                  *(char *)(lVar6 + 0x79) = (char)sVar8;
                  memmove((void *)(lVar6 + 0x80),piVar14 + 6,
                          (ulonglong)*(byte *)((longlong)piVar14 + 10));
                  lVar11 = StorPortGetPhysicalAddress(param_1,param_2,pvVar1,local_68);
                  if ((uVar16 & 0xc0) == 0) {
                    *(undefined4 *)(lVar6 + 0xa8) = 0;
                    *(longlong *)(lVar6 + 0xa0) = lVar11 + 0x80;
                    *(undefined1 *)(lVar6 + 0xaf) = 8;
LAB_14000162f:
                    *(undefined4 *)(lVar6 + 0x50) = 0;
                    if (*(char *)(param_1 + 0x3c2) == '\0') {
                      return 1;
                    }
                    local_60 = 2;
                    local_5c = 0x14;
                    iVar10 = StorPortExtendedFunction(0xf,param_1,param_2,&local_60);
                    if (iVar10 == 0) {
                      *(undefined2 *)(lVar6 + 0x50) = local_58;
                      *(ushort *)(lVar6 + 0x52) = local_50 * 0x40 + (ushort)local_4e;
                      return 1;
                    }
                    return 1;
                  }
                  uVar12 = BuildIeeeScatterGather
                                     (param_1,param_2,(int)*(undefined8 *)(param_2 + 0x40),
                                      (longlong)pvVar1,lVar11,0,&local_70);
                  if ((char)uVar12 != '\0') goto LAB_14000162f;
                  *(undefined1 *)(param_2 + 3) = 4;
                  goto LAB_1400016d9;
                }
                *(undefined1 *)(param_2 + 3) = 1;
                break;
              }
            }
            *(undefined1 *)(param_2 + 3) = 10;
            break;
          case 2:
            return 1;
          case 0x10:
          case 0x14:
            *(undefined1 *)(param_2 + 3) = 3;
            break;
          case 0x12:
            break;
          case 0x13:
          case 0x20:
            if (*(int *)(param_1 + 0x428) == 0) {
              return 1;
            }
            *(undefined1 *)(param_2 + 3) = 5;
            break;
          case 0x17:
            if (*(char *)(param_1 + 0x408) == '\0') {
              return 1;
            }
          default:
            *(undefined1 *)(param_2 + 3) = 0x22;
            break;
          case 0x24:
            if (*(int *)(param_2 + 0x38) == 0) {
              return 1;
            }
            do {
              piVar14 = (int *)((ulonglong)*(uint *)(param_2 + 0x78 + uVar17 * 4) + param_2);
              if (*piVar14 == 0x61) {
                *(int **)(lVar6 + 0x38) = piVar14;
              }
              uVar16 = (int)uVar17 + 1;
              uVar17 = (ulonglong)uVar16;
            } while (uVar16 < *(uint *)(param_2 + 0x38));
            return 1;
          }
        }
        else {
          *(undefined1 *)(param_2 + 3) = 4;
        }
      }
    }
    else {
      *(undefined1 *)(param_2 + 3) = 5;
    }
  }
  else {
    *(undefined1 *)(param_2 + 3) = 0x22;
  }
LAB_1400016d9:
  StorPortNotification(0,param_1,param_2);
  return 0;
}



===== AddToDeviceRemovalTable @ 140001760 =====

void AddToDeviceRemovalTable
               (longlong param_1,short param_2,undefined1 param_3,ushort param_4,int *param_5)

{
  undefined4 *puVar1;
  longlong lVar2;
  ushort local_res8;
  undefined2 local_resa;
  short local_resc;
  undefined1 local_rese;
  undefined1 local_resf;
  
  local_res8 = 0;
  lVar2 = *(longlong *)(param_1 + 0x9f8);
  if (*(ushort *)(param_1 + 0x372) != 0) {
    while (local_resc = *(short *)(lVar2 + 8), local_resc != param_2) {
      local_res8 = local_res8 + 1;
      lVar2 = lVar2 + 0x18;
      if (*(ushort *)(param_1 + 0x372) <= local_res8) {
        return;
      }
    }
    *(byte *)(lVar2 + 0x16) = *(byte *)(lVar2 + 0x16) | 2;
    puVar1 = (undefined4 *)(*(longlong *)(param_1 + 0xa00) + (ulonglong)local_res8 * 8);
    if (*(short *)(*(longlong *)(param_1 + 0xa00) + 4 + (ulonglong)local_res8 * 8) == 0) {
      *(short *)(puVar1 + 1) = param_2;
      *puVar1 = 1;
      *(undefined1 *)((longlong)puVar1 + 6) = param_3;
      LOCK();
      *(short *)(param_1 + 0x88e) = *(short *)(param_1 + 0x88e) + 1;
      UNLOCK();
      return;
    }
    local_resa = *(undefined2 *)(lVar2 + 10);
    local_rese = *(undefined1 *)((longlong)puVar1 + 6);
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x120) != 0)) {
      local_resf = param_3;
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x120,(undefined1 *)&local_res8,8,param_4,
                  param_5);
    }
    *puVar1 = 1;
    *(undefined1 *)((longlong)puVar1 + 6) = param_3;
  }
  return;
}



===== HandleEventNotification @ 140001890 =====

void HandleEventNotification(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  short sVar3;
  uint uVar4;
  char cVar5;
  ushort uVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  char cVar9;
  bool bVar10;
  uint local_res8 [2];
  
  uVar2 = *(undefined1 *)(param_2 + 0x11);
  *(undefined2 *)(param_1 + 0x8ec) = *(undefined2 *)(param_2 + 0x12);
  switch(uVar2) {
  case 7:
  case 8:
    ProcessDeviceAddedEvent(param_1,param_2,param_3,param_4);
    break;
  case 9:
    if (*(char *)(param_2 + 0x18) == '\x01') {
      if (*(char *)(param_1 + 0x408) == '\0') {
        *(undefined4 *)(param_1 + 0x424) = 1;
        *(undefined2 *)(param_1 + 0x8a0) = 600;
        PauseController(param_1,2,1,param_4);
      }
    }
    else if (*(char *)(param_2 + 0x18) == '\x02') {
      *(undefined4 *)(param_1 + 0x424) = 0;
      *(undefined2 *)(param_1 + 0x8a0) = 0;
      ResumeController(param_1,2,param_3,param_4);
    }
    break;
  case 0xd:
    sVar3 = *(short *)(param_2 + 0x1e);
    uVar7 = 0;
    uVar8 = 1;
    if (*(ushort *)(param_1 + 0x372) != 0) {
LAB_140001930:
      lVar1 = *(longlong *)(param_1 + 0x9f8) + uVar7 * 0x18;
      if (*(short *)(*(longlong *)(param_1 + 0x9f8) + 8 + uVar7 * 0x18) != sVar3)
      goto code_r0x000140001943;
      switch(*(undefined1 *)(param_2 + 0x1a)) {
      case 1:
        goto switchD_1400019da_caseD_1;
      case 2:
        *(byte *)(lVar1 + 0x16) = *(byte *)(lVar1 + 0x16) | 2;
        uVar8 = 1;
        goto LAB_1400019e8;
      case 3:
        *(byte *)(lVar1 + 0x16) = *(byte *)(lVar1 + 0x16) & 0xfd;
        *(undefined1 *)(param_1 + 0x416) = 1;
        goto switchD_1400018f3_caseD_a;
      case 0x20:
      case 0x24:
        if ((*(byte *)(lVar1 + 0x16) & 1) == 0) {
          StorPortPauseDevice(param_1,(char)(*(ushort *)(lVar1 + 10) >> 7),
                              (byte)*(ushort *)(lVar1 + 10) & 0x7f,0,0xe10);
          *(byte *)(lVar1 + 0x16) = *(byte *)(lVar1 + 0x16) | 1;
          *(undefined1 *)(param_1 + 0x416) = 0;
          goto switchD_1400018f3_caseD_a;
        }
        break;
      case 0x21:
      case 0x25:
        if ((*(byte *)(lVar1 + 0x16) & 1) != 0) {
          StorPortResumeDevice
                    (param_1,(char)(*(ushort *)(lVar1 + 10) >> 7),
                     (byte)*(ushort *)(lVar1 + 10) & 0x7f,0);
          *(byte *)(lVar1 + 0x16) = *(byte *)(lVar1 + 0x16) & 0xfe;
        }
        break;
      case 0x50:
        *(byte *)(lVar1 + 0x16) = *(byte *)(lVar1 + 0x16) | 2;
        uVar8 = 0;
LAB_1400019e8:
        AddToDeviceRemovalTable(param_1,sVar3,uVar8,param_3,param_4);
        ProcessDeviceRemoval(param_1,param_3,param_4);
        *(undefined1 *)(param_1 + 0x416) = 1;
        goto switchD_1400018f3_caseD_a;
      }
      uVar8 = 0;
switchD_1400019da_caseD_1:
      *(undefined1 *)(param_1 + 0x416) = uVar8;
      break;
    }
    break;
  case 0xe:
    *(undefined2 *)(param_1 + 0x3f8) = *(undefined2 *)(param_2 + 4);
    break;
  case 0x16:
  case 0x20:
    ProcessTopologyChangeEvent(param_1,param_2,param_3,param_4);
    break;
  case 0x19:
    local_res8[0] = (uint)*(ushort *)(param_2 + 0x18) << 8 | 0x19 | (uint)*(byte *)(param_2 + 0x1a);
    LogSystemEvent(param_1,0,0x8004af01,
                   (byte *)"SMP command sent to the expander by FW failed/timed out",param_3,param_4
                  );
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x26f) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x26f,(undefined1 *)local_res8,4,param_3,
                  param_4);
    }
  }
switchD_1400018f3_caseD_a:
  if ((*(byte *)(param_2 + 7) & 1) != 0) {
    do {
      LOCK();
      bVar10 = *(int *)(param_1 + 0x788) == 0;
      if (bVar10) {
        *(int *)(param_1 + 0x788) = 1;
      }
      UNLOCK();
    } while (!bVar10);
    if (*(short *)(param_1 + 0x784) == 0x20) {
      LogSystemEvent(param_1,0,0x8004af01,(byte *)"Event Acknowledgement Queue is full, Ack Dropped"
                     ,param_3,param_4);
    }
    else {
      uVar7 = (ulonglong)*(byte *)(param_1 + 0x780);
      cVar9 = *(char *)(param_1 + 0x78c + uVar7 * 8);
      while (cVar5 = (char)uVar7, cVar9 != '\0') {
        uVar4 = 0;
        if (cVar5 != '\x1f') {
          uVar4 = (int)uVar7 + 1;
        }
        uVar7 = (ulonglong)(uVar4 & 0xff);
        *(char *)(param_1 + 0x780) = (char)uVar4;
        cVar9 = *(char *)(param_1 + 0x78c + uVar7 * 8);
      }
      *(undefined1 *)(param_1 + 0x78c + uVar7 * 8) = uVar2;
      *(undefined4 *)(param_1 + 0x790 + uVar7 * 8) = *(undefined4 *)(param_2 + 0x14);
      *(short *)(param_1 + 0x784) = *(short *)(param_1 + 0x784) + 1;
      cVar9 = '\0';
      if (cVar5 != '\x1f') {
        cVar9 = cVar5 + '\x01';
      }
      *(char *)(param_1 + 0x780) = cVar9;
    }
    LOCK();
    *(int *)(param_1 + 0x788) = *(int *)(param_1 + 0x788) + -1;
    UNLOCK();
  }
  return;
code_r0x000140001943:
  uVar6 = (short)uVar7 + 1;
  uVar7 = (ulonglong)uVar6;
  if (*(ushort *)(param_1 + 0x372) <= uVar6) goto switchD_1400018f3_caseD_a;
  goto LAB_140001930;
}



===== PELAbort @ 140001d00 =====

void PELAbort(longlong param_1,ushort param_2,int *param_3)

{
  undefined2 *puVar1;
  
  puVar1 = *(undefined2 **)(param_1 + 0x990);
  ZeroMemory(puVar1,8);
  *(undefined1 *)((longlong)puVar1 + 3) = 9;
  *puVar1 = 0xada7;
  *(undefined1 *)(puVar1 + 5) = 6;
  puVar1[8] = 0xada6;
  AdminQueueRequestPost(param_1,puVar1,param_2,param_3);
  return;
}



===== PELGetSetSeqNumbers @ 140001d70 =====

void PELGetSetSeqNumbers(longlong param_1,ushort param_2,int *param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x990);
  if (*(int *)(param_1 + 0x428) == 0) {
    ZeroMemory((void *)(lVar1 + 0x18),0x48);
    *(undefined1 *)(lVar1 + 0x1b) = 9;
    *(undefined2 *)(lVar1 + 0x18) = 0xada5;
    *(undefined1 *)(lVar1 + 0x22) = 1;
    *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(param_1 + 0x998);
    *(undefined4 *)(lVar1 + 0x40) = 0x18;
    *(undefined1 *)(lVar1 + 0x47) = 8;
    AdminQueueRequestPost(param_1,(void *)(lVar1 + 0x18),param_2,param_3);
  }
  return;
}



===== PELWait @ 140001e00 =====

void PELWait(longlong param_1,ushort param_2,int *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x990);
  ZeroMemory((void *)(lVar1 + 0x18),8);
  *(undefined1 *)(lVar1 + 0x1b) = 9;
  *(undefined2 *)(lVar1 + 0x18) = 0xada6;
  *(undefined1 *)(lVar1 + 0x22) = 5;
  *(undefined2 *)(lVar1 + 0x28) = *(undefined2 *)(param_1 + 0x97c);
  *(undefined1 *)(lVar1 + 0x2a) = *(undefined1 *)(param_1 + 0x97e);
  *(int *)(lVar1 + 0x24) = *(int *)(param_1 + 0x9a0) + 1;
  uVar2 = AdminQueueRequestPost(param_1,(void *)(lVar1 + 0x18),param_2,param_3);
  if ((char)uVar2 != '\0') {
    *(undefined1 *)(param_1 + 0x9a4) = 1;
  }
  return;
}



===== ProcessDeviceAddedEvent @ 140001ea0 =====

void ProcessDeviceAddedEvent(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  undefined4 *puVar1;
  char cVar2;
  ushort uVar3;
  longlong lVar4;
  short sVar5;
  ulonglong uVar6;
  byte bVar7;
  
  lVar4 = *(longlong *)(param_1 + 0xa00);
  uVar6 = (ulonglong)*(ushort *)(param_2 + 0x30);
  if (*(ushort *)(param_1 + 0x372) <= *(ushort *)(param_2 + 0x30)) {
    LogSystemEvent(param_1,0,0x4004af00,
                   (byte *)"Got persistent ID greater than maxDevices supported",param_3,param_4);
    return;
  }
  puVar1 = (undefined4 *)(*(longlong *)(param_1 + 0x9f8) + uVar6 * 0x18);
  *(undefined2 *)(lVar4 + 4 + uVar6 * 8) = 0;
  *(undefined4 *)(lVar4 + uVar6 * 8) = 4;
  *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_2 + 0x20);
  *(undefined2 *)((longlong)puVar1 + 10) = *(undefined2 *)(param_2 + 0x30);
  uVar3 = *(ushort *)(param_2 + 0x34);
  *(ushort *)(puVar1 + 3) = uVar3;
  *(undefined1 *)(puVar1 + 5) = *(undefined1 *)(param_2 + 0x3f);
  bVar7 = ((char)(uVar3 >> 3) * '\x02' ^ *(byte *)((longlong)puVar1 + 0x16)) & 2 ^
          *(byte *)((longlong)puVar1 + 0x16);
  *(byte *)((longlong)puVar1 + 0x16) = bVar7;
  sVar5 = 0x20;
  if (*(short *)(param_2 + 0x3a) != 0) {
    sVar5 = *(short *)(param_2 + 0x3a);
  }
  *(short *)((longlong)puVar1 + 0x12) = sVar5;
  cVar2 = *(char *)(param_2 + 0x3f);
  if (cVar2 == '\0') {
    *(undefined2 *)((longlong)puVar1 + 0xe) = *(undefined2 *)(param_2 + 0x48);
    uVar3 = *(ushort *)(param_2 + 0x4a);
    *(ushort *)(puVar1 + 4) = uVar3;
    if ((uVar3 & 1) == 0 || (uVar3 & 0x180) == 0) {
      *(byte *)((longlong)puVar1 + 0x16) = bVar7 | 2;
    }
    sVar5 = *(short *)(param_1 + 0x39a);
    if (sVar5 == 0) goto LAB_140002016;
    if (-1 < (char)uVar3) {
      sVar5 = *(short *)(param_1 + 0x398);
    }
  }
  else {
    if (cVar2 == '\x01') {
      *puVar1 = *(undefined4 *)(param_2 + 0x48);
      puVar1[1] = *(undefined4 *)(param_2 + 0x4c);
      *(undefined1 *)((longlong)puVar1 + 0x17) = *(undefined1 *)(param_2 + 0x53);
      if ((*(byte *)(param_2 + 0x46) & 1) == 0) {
        *(byte *)((longlong)puVar1 + 0x16) = bVar7 | 2;
      }
      sVar5 = *(short *)(param_1 + 0x39c);
    }
    else {
      if (cVar2 != '\x02') goto LAB_140002016;
      *(undefined1 *)((longlong)puVar1 + 0x15) = *(undefined1 *)(param_2 + 0x40);
      sVar5 = *(short *)(param_1 + 0x39e);
    }
    if (sVar5 == 0) goto LAB_140002016;
  }
  *(short *)((longlong)puVar1 + 0x12) = sVar5;
LAB_140002016:
  *(undefined1 *)(param_1 + 0x416) = 1;
  return;
}



===== ProcessDeviceRemoval @ 140002030 =====

void ProcessDeviceRemoval(longlong param_1,ushort param_2,int *param_3)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ushort uVar8;
  int *piVar9;
  int *piVar10;
  longlong local_res20;
  
  lVar7 = *(longlong *)(param_1 + 0x9f8);
  piVar10 = *(int **)(param_1 + 0xa00);
  if (((*(short *)(param_1 + 0x88e) != 0) && (*(char *)(param_1 + 0x88c) == '\0')) &&
     (*(int *)(param_1 + 0x428) == 0)) {
    uVar8 = 0;
    *(undefined1 *)(param_1 + 0x88c) = 1;
    if (*(short *)(param_1 + 0x372) != 0) {
      piVar9 = piVar10 + 1;
      local_res20 = lVar7;
      do {
        if ((short)*piVar9 != 0) {
          iVar3 = *piVar10;
          if (iVar3 == 0) {
            if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x283) != 0))
            {
              RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x283,(undefined1 *)piVar9,2,param_2
                          ,param_3);
            }
            LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                                "Kill Adapter (Driver) - Incorrect Device Setup",param_2,param_3);
            KillAdapter(param_1,0x18,param_2,param_3);
          }
          else if (iVar3 == 1) {
            puVar4 = *(undefined2 **)(param_1 + 800);
            ZeroMemory(puVar4,0x80);
            *(undefined1 *)((longlong)puVar4 + 3) = 0x21;
            puVar4[5] = (short)*piVar9;
            *(undefined1 *)(puVar4 + 7) = 3;
            *puVar4 = 0xadb2;
            uVar6 = AdminQueueRequestPost(param_1,puVar4,param_2,param_3);
            if ((char)uVar6 != '\0') {
              *piVar10 = 2;
              return;
            }
            if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x273) != 0))
            {
              RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x273,(undefined1 *)piVar9,2,param_2
                          ,param_3);
            }
            LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                                "Posting TM for device Remove-Hide failed",param_2,param_3);
          }
          else if (iVar3 == 2) {
            puVar4 = *(undefined2 **)(param_1 + 800);
            ZeroMemory(puVar4,0x80);
            *(undefined1 *)((longlong)puVar4 + 3) = 8;
            uVar5 = 0x10;
            if (*(char *)((longlong)piVar9 + 2) != '\0') {
              uVar5 = 0x12;
            }
            *(undefined1 *)((longlong)puVar4 + 0xb) = uVar5;
            puVar4[0x18] = (short)*piVar9;
            *puVar4 = 0xadb2;
            uVar6 = AdminQueueRequestPost(param_1,puVar4,param_2,param_3);
            if ((char)uVar6 != '\0') {
              *piVar10 = 3;
              return;
            }
            if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x274) != 0))
            {
              RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x274,(undefined1 *)piVar9,2,param_2
                          ,param_3);
            }
            LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                                "Posting IOU for device Remove failed",param_2,param_3);
          }
          else {
            if (iVar3 != 3) goto LAB_14000240e;
            *(undefined1 *)(param_1 + 0x416) = 1;
            local_res20 = lVar7 + (ulonglong)uVar8 * 0x18;
            if (*(char *)((longlong)piVar9 + 2) == '\0') {
              *(undefined2 *)(local_res20 + 8) = 0;
            }
            LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,"Device Removed Completely",param_2,
                                param_3);
            if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x121) != 0))
            {
              RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x121,(undefined1 *)piVar9,2,param_2
                          ,param_3);
            }
            *piVar10 = 4;
            *(short *)piVar9 = 0;
            LOCK();
            psVar1 = (short *)(param_1 + 0x88e);
            sVar2 = *psVar1;
            *psVar1 = *psVar1 + -1;
            UNLOCK();
            if (sVar2 == 1) {
              if ((*(char *)(param_1 + 0xc00) != '\0') &&
                 ((*(uint *)(param_1 + 0xc04) & 0x122) != 0)) {
                RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x122,(undefined1 *)0x0,0,param_2,
                            param_3);
              }
              LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                                  "All devices have been removed/Hidden",param_2,param_3);
              break;
            }
            if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x123) != 0))
            {
              RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x123,
                          (undefined1 *)(param_1 + 0x88e),2,param_2,param_3);
            }
            LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                                "we have not handled everything; returing back in loop",param_2,
                                param_3);
          }
          lVar7 = local_res20;
        }
LAB_14000240e:
        uVar8 = uVar8 + 1;
        piVar10 = piVar10 + 2;
        piVar9 = piVar9 + 2;
      } while (uVar8 < *(ushort *)(param_1 + 0x372));
    }
    *(undefined1 *)(param_1 + 0x88c) = 0;
  }
  return;
}



===== ProcessTopologyChangeEvent @ 1400024d0 =====

void ProcessTopologyChangeEvent(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  byte bVar1;
  short *psVar2;
  short sVar3;
  ulonglong uVar4;
  
  bVar1 = *(byte *)(param_2 + 0x20);
  uVar4 = (ulonglong)bVar1;
  sVar3 = -1;
  if (*(char *)(param_2 + 0x11) == '\x16') {
    if (bVar1 == 0) {
      return;
    }
    if ((ushort)((bVar1 + 3) * 4) != (ushort)((ushort)*(byte *)(param_2 + 0x10) << 2)) {
      return;
    }
    if (bVar1 == 0) {
      return;
    }
    psVar2 = (short *)(param_2 + 0x24);
    do {
      if (*(char *)((longlong)psVar2 + 3) == '\x02') {
        sVar3 = *psVar2;
        AddToDeviceRemovalTable(param_1,sVar3,0,param_3,param_4);
      }
      psVar2 = psVar2 + 2;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  else {
    if (bVar1 == 0) {
      return;
    }
    if ((ushort)((bVar1 + 2) * 8) != (ushort)((ushort)*(byte *)(param_2 + 0x10) << 2)) {
      return;
    }
    if (bVar1 == 0) {
      return;
    }
    psVar2 = (short *)(param_2 + 0x28);
    do {
      if ((char)psVar2[1] == '\x02') {
        sVar3 = *psVar2;
        AddToDeviceRemovalTable(param_1,sVar3,0,param_3,param_4);
      }
      psVar2 = psVar2 + 4;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (sVar3 != -1) {
    ProcessDeviceRemoval(param_1,param_3,param_4);
  }
  return;
}



===== AdminQueueRequestPostPollReply @ 140002600 =====

ulonglong AdminQueueRequestPostPollReply
                    (longlong param_1,void *param_2,short param_3,ushort param_4,ushort param_5,
                    int *param_6)

{
  ushort uVar1;
  ushort uVar2;
  ulonglong uVar3;
  short sVar4;
  longlong lVar5;
  short sVar6;
  ushort uVar7;
  uint uVar8;
  ushort uVar9;
  ushort *puVar10;
  uint uVar11;
  
  uVar1 = *(ushort *)(param_1 + 0x2ac);
  if (((uint)*(ushort *)(param_1 + 0x2ae) == uVar1 + 1) ||
     ((*(ushort *)(param_1 + 0x2ae) == 0 && ((uint)uVar1 == *(ushort *)(param_1 + 0x2a0) - 1)))) {
    uVar3 = LogSystemEvent(param_1,0,0xc004af02,(byte *)"INIT Failed: Admin Queue is full",param_5,
                           param_6);
    *(undefined4 *)(param_1 + 0x20) = 0xc;
    return uVar3 & 0xffffffffffffff00;
  }
  memmove((void *)((ulonglong)uVar1 * 0x80 + *(longlong *)(param_1 + 0x2c8)),param_2,0x80);
  sVar4 = 0;
  if ((ushort)(uVar1 + 1) != *(short *)(param_1 + 0x2a0)) {
    sVar4 = uVar1 + 1;
  }
  *(short *)(param_1 + 0x2ac) = sVar4;
  **(short **)(param_1 + 0x78) = sVar4;
  LOCK();
  UNLOCK();
  if (param_3 != -0x5260) {
    return 0xad01;
  }
  uVar7 = 0;
  uVar1 = *(ushort *)(param_1 + 0x2b0);
  uVar2 = *(ushort *)(param_1 + 0x2d8);
  puVar10 = (ushort *)((ulonglong)uVar1 * 0x10 + *(longlong *)(param_1 + 0x2d0));
  if (param_4 != 0) {
    do {
      if ((puVar10[7] & 1) == uVar2) break;
      lVar5 = 100;
      do {
        StorPortStallExecution(1000);
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_4);
  }
  if (uVar7 == param_4) {
    uVar3 = LogSystemEvent(param_1,0,0x8004af01,(byte *)"Reply not posted within timeout",param_5,
                           param_6);
    *(undefined4 *)(param_1 + 0x20) = 0xd;
    goto LAB_14000274b;
  }
  *(ushort *)(param_1 + 0x2ae) = puVar10[4];
  uVar7 = puVar10[7] & 0xf000;
  if ((puVar10[7] & 0xf000) == 0) {
    sVar6 = uVar1 + 1;
    uVar7 = *(ushort *)(*(longlong *)(param_1 + 0xa50) + 10 + *(longlong *)puVar10);
    sVar4 = 0;
    if (sVar6 != *(short *)(param_1 + 0x2a2)) {
      sVar4 = sVar6;
    }
    uVar9 = uVar2 ^ 1;
    if (sVar6 != *(short *)(param_1 + 0x2a2)) {
      uVar9 = uVar2;
    }
    if (puVar10 != (ushort *)0x0) {
      uVar8 = *(uint *)(param_1 + 0xa88);
      *(longlong *)(*(longlong *)(param_1 + 0xa58) + (ulonglong)uVar8 * 8) = *(longlong *)puVar10;
      uVar8 = uVar8 + 1;
      uVar11 = 0;
      if (uVar8 != *(ushort *)(param_1 + 0x362)) {
        uVar11 = uVar8;
      }
      **(uint **)(param_1 + 0xd8) = uVar11;
      LOCK();
      UNLOCK();
      *(uint *)(param_1 + 0xa88) = uVar11;
    }
  }
  else {
    if (uVar7 == 0x1000) {
      uVar7 = 0;
LAB_140002807:
      sVar6 = *(short *)(param_1 + 0x2a2);
      sVar4 = 0;
      if ((ushort)(uVar1 + 1) != sVar6) {
        sVar4 = uVar1 + 1;
      }
    }
    else {
      if (uVar7 != 0x3000) {
        uVar7 = 0x7fff;
        LogSystemEvent(param_1,0,0xc004af02,(byte *)"Invalid Reply Descriptor received",param_5,
                       param_6);
        goto LAB_140002807;
      }
      sVar6 = *(short *)(param_1 + 0x2a2);
      uVar7 = *puVar10;
      sVar4 = 0;
      if ((ushort)(uVar1 + 1) != sVar6) {
        sVar4 = uVar1 + 1;
      }
    }
    uVar9 = uVar2 ^ 1;
    if ((ushort)(uVar1 + 1) != sVar6) {
      uVar9 = uVar2;
    }
  }
  **(short **)(param_1 + 0x88) = sVar4;
  LOCK();
  UNLOCK();
  *(uint *)(param_1 + 0x2d8) = (uint)uVar9;
  *(short *)(param_1 + 0x2b0) = sVar4;
  if ((uVar7 & 0x7fff) == 0) {
    return 0x7f01;
  }
  uVar3 = LogSystemEvent(param_1,0,0xc004af02,
                         (byte *)"INIT Failed: Admin reply did not complete with Success status",
                         param_5,param_6);
  *(undefined4 *)(param_1 + 0x20) = 0xe;
LAB_14000274b:
  return uVar3 & 0xffffffffffffff00;
}



===== AllocateFixedSizedMemoryBuffers @ 140002940 =====

ulonglong AllocateFixedSizedMemoryBuffers
                    (longlong param_1,undefined8 param_2,ushort param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_res8 [2];
  
  cVar1 = *(char *)(param_1 + 0x408);
  uVar9 = 0x4000;
  if (cVar1 != '\0') {
    uVar9 = 0x2000;
  }
  uVar7 = 0x2000;
  if (cVar1 != '\0') {
    uVar7 = 0x1000;
  }
  uVar8 = 0x2000;
  if (cVar1 != '\0') {
    uVar8 = 0;
  }
  *(uint *)(param_1 + 0x2a4) = uVar7;
  *(uint *)(param_1 + 0x2a8) = uVar9;
  *(short *)(param_1 + 0x2a0) = (short)(uVar7 >> 7);
  *(short *)(param_1 + 0x2a2) = (short)(uVar9 >> 4);
  iVar5 = uVar7 + 0x1680 + uVar8 + uVar9;
  if (*(char *)(param_1 + 0x408) != '\0') {
    iVar2 = MemoryNeededInDumpMode(param_1);
    iVar5 = iVar5 + iVar2;
  }
  lVar3 = StorPortGetUncachedExtension(param_1,param_2,iVar5);
  *(longlong *)(param_1 + 8) = lVar3;
  if (lVar3 == 0) {
    uVar4 = LogSystemEvent(param_1,0,0xc004af02,(byte *)"Failed to allocate fixed memory",param_3,
                           param_4);
    uVar4 = uVar4 & 0xffffffffffffff00;
    *(undefined4 *)(param_1 + 0x20) = 10;
  }
  else {
    uVar4 = StorPortGetPhysicalAddress(param_1,0,lVar3,local_res8);
    local_res8[0] = (uint)uVar4 & 0xfff;
    uVar9 = 0x1000 - local_res8[0];
    if ((uVar4 & 0xfff) == 0) {
      uVar9 = 0;
    }
    lVar3 = uVar4 + uVar9;
    lVar6 = *(longlong *)(param_1 + 8) + (ulonglong)uVar9;
    *(longlong *)(param_1 + 0x18) = lVar3;
    *(longlong *)(param_1 + 0x10) = lVar6;
    *(longlong *)(param_1 + 0x2b8) = lVar3;
    *(longlong *)(param_1 + 0x2c8) = lVar6;
    lVar6 = lVar6 + (ulonglong)*(uint *)(param_1 + 0x2a4);
    *(longlong *)(param_1 + 0x2d0) = lVar6;
    lVar3 = lVar3 + (ulonglong)*(uint *)(param_1 + 0x2a4);
    *(longlong *)(param_1 + 0x2c0) = lVar3;
    lVar6 = lVar6 + (ulonglong)*(uint *)(param_1 + 0x2a8);
    *(longlong *)(param_1 + 0x330) = lVar6;
    lVar3 = lVar3 + (ulonglong)*(uint *)(param_1 + 0x2a8);
    *(longlong *)(param_1 + 0x308) = lVar3;
    *(longlong *)(param_1 + 0x2e8) = lVar3 + 0x80;
    *(longlong *)(param_1 + 0x310) = lVar6 + 0x80;
    *(longlong *)(param_1 + 0x318) = lVar6 + 0x100;
    *(longlong *)(param_1 + 0x2f0) = lVar3 + 0x100;
    *(longlong *)(param_1 + 800) = lVar6 + 0x180;
    *(longlong *)(param_1 + 0x2f8) = lVar3 + 0x180;
    *(longlong *)(param_1 + 0x328) = lVar6 + 0x200;
    *(longlong *)(param_1 + 0x300) = lVar3 + 0x200;
    *(longlong *)(param_1 + 0x990) = lVar6 + 0x280;
    *(longlong *)(param_1 + 0x998) = lVar3 + 0x2c8;
    *(longlong *)(param_1 + 0xb98) = lVar6 + 0x300;
    *(longlong *)(param_1 + 0xb88) = lVar3 + 0x300;
    *(undefined4 *)(param_1 + 0xba0) = 0x200;
    *(longlong *)(param_1 + 0xb90) = lVar6 + 0x500;
    *(longlong *)(param_1 + 0xb80) = lVar3 + 0x500;
    *(longlong *)(param_1 + 0x338) = lVar6 + 0x580;
    uVar4 = (ulonglong)uVar8;
    lVar3 = lVar6 + 0x580 + uVar4;
    *(longlong *)(param_1 + 0xae0) = lVar3;
    if (*(char *)(param_1 + 0x408) != '\0') {
      *(longlong *)(param_1 + 0x9b0) = lVar3 + 0x100;
      uVar4 = PartitionDumpModeMemory(param_1);
    }
    uVar4 = CONCAT71((int7)(uVar4 >> 8),1);
  }
  return uVar4;
}



===== AllocateOpQueueMemory @ 140002bd0 =====

void * AllocateOpQueueMemory
                 (longlong param_1,uint param_2,undefined4 param_3,longlong *param_4,ushort param_5,
                 int *param_6)

{
  longlong lVar1;
  undefined4 local_res10 [2];
  undefined4 uVar2;
  ulonglong uVar3;
  int *piVar4;
  void **ppvVar5;
  undefined1 local_38 [8];
  void *local_30;
  
  ppvVar5 = &local_30;
  local_30 = (void *)0x0;
  piVar4 = (int *)0x1;
  uVar3 = 0;
  uVar2 = 0xffffffff;
  StorPortExtendedFunction(0x18,param_1,param_2,0,0xffffffffffffffff,0,1,param_3,ppvVar5);
  if (local_30 == (void *)0x0) {
    ppvVar5 = &local_30;
    param_3 = 0x80000000;
    piVar4 = (int *)0x1;
    uVar3 = 0;
    uVar2 = 0xffffffff;
    local_res10[0] =
         StorPortExtendedFunction(0x18,param_1,param_2,0,0xffffffffffffffff,0,1,0x80000000,ppvVar5);
    if (local_30 == (void *)0x0) {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x29c) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x29c,(undefined1 *)local_res10,4,param_5,
                    param_6);
      }
      return local_30;
    }
    if (*(char *)(param_1 + 0x3fa) == '\0') {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x128) != 0)) {
        uVar3 = (ulonglong)param_5;
        piVar4 = param_6;
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x128,(undefined1 *)0x0,0,param_5,param_6)
        ;
      }
      *(undefined1 *)(param_1 + 0x3fa) = 1;
    }
  }
  lVar1 = StorPortGetPhysicalAddress(param_1,0,local_30,local_38);
  if (lVar1 == 0) {
    local_res10[0] =
         StorPortExtendedFunction
                   (0x19,param_1,local_30,param_2,CONCAT44(uVar2,1),uVar3,piVar4,param_3,ppvVar5);
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x29d) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x29d,(undefined1 *)0x0,0,param_5,param_6);
    }
    local_30 = (void *)0x0;
  }
  else {
    *param_4 = lVar1;
    ZeroMemory(local_30,param_2);
  }
  return local_30;
}



===== BuildIOCInit @ 140002de0 =====

void BuildIOCInit(longlong param_1)

{
  undefined2 *puVar1;
  longlong local_res8;
  
  puVar1 = *(undefined2 **)(param_1 + 0x310);
  ZeroMemory(puVar1,0x80);
  *(undefined1 *)((longlong)puVar1 + 3) = 2;
  *puVar1 = 0xada0;
  *(undefined4 *)(puVar1 + 6) = 0x3000012;
  StorPortQuerySystemTime(&local_res8);
  *(undefined1 *)((longlong)puVar1 + 0x19) = 3;
  *(longlong *)(puVar1 + 8) = (local_res8 + -0x19db1ded53e8000) / 10000;
  puVar1[0xe] = *(undefined2 *)(param_1 + 0x362);
  *(undefined8 *)(puVar1 + 0x10) = *(undefined8 *)(param_1 + 0xa60);
  puVar1[0x16] = *(undefined2 *)(param_1 + 0x366);
  puVar1[0x17] = 0x100;
  *(undefined8 *)(puVar1 + 0x18) = *(undefined8 *)(param_1 + 0xa80);
  memmove(*(void **)(param_1 + 0x318),&DAT_140014000,0x78);
  *(undefined8 *)(puVar1 + 0x1c) = *(undefined8 *)(param_1 + 0x2f0);
  return;
}



===== CreateAdministrativeQueuePair @ 140002ec0 =====

void CreateAdministrativeQueuePair(longlong param_1)

{
  **(undefined4 **)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x2a0);
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x2b8);
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x60) = *(undefined4 *)(param_1 + 700);
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x2c0);
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x2c4);
  LOCK();
  UNLOCK();
  **(undefined2 **)(param_1 + 0x78) = 0;
  LOCK();
  UNLOCK();
  **(undefined2 **)(param_1 + 0x88) = 0;
  LOCK();
  UNLOCK();
  ZeroMemory(*(void **)(param_1 + 0x2d0),*(uint *)(param_1 + 0x2a8));
  ZeroMemory(*(void **)(param_1 + 0x2c8),*(uint *)(param_1 + 0x2a4));
  *(undefined4 *)(param_1 + 0x2ac) = 0;
  *(undefined2 *)(param_1 + 0x2b0) = 0;
  *(undefined4 *)(param_1 + 0x2d8) = 1;
  return;
}



===== CreateOperationalQueues @ 140002fa0 =====

undefined8 CreateOperationalQueues(longlong param_1,ushort param_2,int *param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ulonglong uVar5;
  ushort uVar6;
  uint uVar7;
  ushort uVar8;
  byte *pbVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  
  if (*(char *)(param_1 + 0x408) == '\0') {
    uVar6 = 0x20;
    if (*(ushort *)(param_1 + 0x376) < 0x20) {
      uVar6 = *(ushort *)(param_1 + 0x376);
    }
    uVar2 = *(ushort *)(param_1 + 0x378);
    if (uVar6 <= *(ushort *)(param_1 + 0x378)) {
      uVar2 = uVar6;
    }
    if (uVar2 == 1) {
      *(undefined1 *)(param_1 + 0x396) = 1;
    }
    uVar6 = *(ushort *)(param_1 + 0x29a);
    uVar10 = *(ushort *)(param_1 + 0x294);
    if (uVar2 <= *(ushort *)(param_1 + 0x294)) {
      uVar10 = uVar2;
    }
  }
  else {
    uVar6 = 0;
    uVar10 = 1;
  }
  uVar2 = *(ushort *)(param_1 + 0x368);
  uVar3 = *(ushort *)(param_1 + 0x35c);
  if (uVar2 < *(ushort *)(param_1 + 0x35c)) {
    *(ushort *)(param_1 + 0x35c) = uVar2;
    uVar3 = uVar2;
  }
  uVar1 = *(ushort *)(param_1 + 0x36a);
  uVar4 = *(ushort *)(param_1 + 0x35e);
  if (uVar2 < *(ushort *)(param_1 + 0x35e)) {
    *(ushort *)(param_1 + 0x35e) = uVar2;
    uVar4 = uVar2;
  }
  uVar2 = *(ushort *)(param_1 + 0x36e);
  uVar12 = 0;
  pbVar9 = *(byte **)(param_1 + 0x9d8);
  uVar8 = 0;
  uVar5 = (ulonglong)uVar4;
  uVar11 = 0;
  if (uVar10 != 0) {
    do {
      uVar7 = 0;
      if (*(ushort *)(param_1 + 0x298) <= uVar11) break;
      if (*(char *)(param_1 + 0x408) == '\0') {
        uVar7 = (uint)*(ushort *)(pbVar9 + 2);
        uVar5 = (ulonglong)*pbVar9;
      }
      else {
        uVar5 = 0;
      }
      if ((ushort)uVar5 < *(ushort *)(param_1 + 0x3c4)) {
        uVar12 = uVar12 + 1;
        uVar5 = CreateOperationalReplyQueue
                          (param_1,uVar12,(ushort)uVar5,(uint)uVar2 * (uint)uVar4,uVar7,param_2,
                           param_3);
        if ((char)uVar5 == '\0') {
LAB_1400031a1:
          return uVar5 & 0xffffffffffffff00;
        }
        uVar8 = uVar8 + 1;
        *(ushort *)(pbVar9 + 4) = uVar12;
        uVar5 = CreateOperationalRequestQueue
                          (param_1,uVar8,uVar12,(uint)uVar1 * (uint)uVar3,uVar7,param_2,param_3);
        if ((char)uVar5 == '\0') goto LAB_1400031a1;
        *(ushort *)(pbVar9 + 6) = uVar8;
        if (uVar6 < uVar8) break;
      }
      uVar11 = uVar11 + 1;
      pbVar9 = pbVar9 + 8;
    } while (uVar8 < uVar10);
  }
  *(ushort *)(param_1 + 0x388) = uVar8;
  *(ushort *)(param_1 + 0x38a) = uVar12;
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== CreateOperationalReplyQueue @ 1400031b0 =====

undefined8
CreateOperationalReplyQueue
          (longlong param_1,ushort param_2,ushort param_3,uint param_4,undefined4 param_5,
          ushort param_6,int *param_7)

{
  longlong *plVar1;
  undefined2 *puVar2;
  void *pvVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  bool bVar8;
  longlong local_res8;
  
  puVar2 = *(undefined2 **)(param_1 + 0x310);
  plVar1 = (longlong *)(*(longlong *)(param_1 + 0xa18) + (ulonglong)param_2 * 0x18);
  if (*(char *)(param_1 + 0x408) == '\0') {
    pvVar3 = AllocateOpQueueMemory(param_1,param_4,param_5,&local_res8,param_6,param_7);
    if (pvVar3 == (void *)0x0) {
      uVar4 = LogSystemEvent(param_1,0,0xc004af02,
                             (byte *)
                             "CreateOperationalReplyQueue:Memory allocation failed due to Insufficient Resources"
                             ,param_6,param_7);
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x29b) != 0)) {
        uVar4 = RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x29b,(undefined1 *)0x0,0,param_6,
                            param_7);
      }
      *(undefined4 *)(param_1 + 0x20) = 0x14;
      return uVar4 & 0xffffffffffffff00;
    }
    *plVar1 = local_res8;
    plVar1[1] = (longlong)pvVar3;
  }
  else {
    ZeroMemory((void *)plVar1[1],param_4);
  }
  uVar5 = 0;
  *(uint *)(plVar1 + 2) = param_4;
  *(undefined2 *)((longlong)plVar1 + 0x14) = 0;
  *(undefined1 *)((longlong)plVar1 + 0x16) = 1;
  ZeroMemory(puVar2,0x80);
  *puVar2 = 0xada2;
  *(undefined1 *)((longlong)puVar2 + 3) = 0x72;
  *(undefined1 *)(puVar2 + 5) = 1;
  puVar2[7] = param_2;
  puVar2[6] = *(undefined2 *)(param_1 + 0x35e);
  puVar2[8] = param_3;
  *(longlong *)(puVar2 + 0xc) = *plVar1;
  *(undefined1 *)(param_1 + 0x414) = 1;
  uVar4 = AdminQueueRequestPostPollReply
                    (param_1,puVar2,-0x525e,*(ushort *)(param_1 + 0x8b0),param_6,param_7);
  if (*(char *)(param_1 + 0x411) == '\0') {
    bVar8 = *(int *)(param_1 + 0x8b0) == 0;
    if (*(int *)(param_1 + 0x8b0) != 0) {
      do {
        lVar7 = 100;
        do {
          lVar6 = lVar7;
          StorPortStallExecution(1000);
          lVar7 = lVar6 + -1;
        } while (lVar7 != 0);
        if (*(char *)(param_1 + 0x408) != '\0') {
          Poll_mpi3Isr(param_1,(int)lVar6 + 2,param_7);
        }
      } while ((*(char *)(param_1 + 0x414) != '\0') &&
              (uVar5 = uVar5 + 1, uVar5 < *(uint *)(param_1 + 0x8b0)));
      bVar8 = uVar5 == *(uint *)(param_1 + 0x8b0);
    }
    if (bVar8) {
      uVar4 = LogSystemEvent(param_1,0,0xc004af02,(byte *)"Create OP Request Queue TIMEDOUT",param_6
                             ,param_7);
      *(undefined4 *)(param_1 + 0x20) = 0x15;
      return uVar4 & 0xffffffffffffff00;
    }
    if (*(char *)(param_1 + 0x415) == '\0') {
      uVar4 = LogSystemEvent(param_1,0,0xc004af02,(byte *)"Create OP Reply Queue Failed",param_6,
                             param_7);
      *(undefined4 *)(param_1 + 0x20) = 0x16;
      return uVar4 & 0xffffffffffffff00;
    }
    uVar4 = *(ulonglong *)(param_1 + 0x9e0);
    *(ushort *)(uVar4 + (ulonglong)param_3 * 2) = param_2;
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== CreateOperationalRequestQueue @ 140003430 =====

undefined8
CreateOperationalRequestQueue
          (longlong param_1,ushort param_2,undefined2 param_3,uint param_4,undefined4 param_5,
          ushort param_6,int *param_7)

{
  undefined2 *puVar1;
  void *pvVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  bool bVar8;
  longlong local_res8;
  
  puVar1 = *(undefined2 **)(param_1 + 0x310);
  plVar5 = (longlong *)((ulonglong)param_2 * 0x20 + *(longlong *)(param_1 + 0xa10));
  if (*(char *)(param_1 + 0x408) == '\0') {
    pvVar2 = AllocateOpQueueMemory(param_1,param_4,param_5,&local_res8,param_6,param_7);
    if (pvVar2 == (void *)0x0) {
      uVar3 = LogSystemEvent(param_1,0,0xc004af02,
                             (byte *)
                             "CreateOperationalRequestQueue:Memory allocation failed due to Insufficient Resources"
                             ,param_6,param_7);
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x29a) != 0)) {
        uVar3 = RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x29a,(undefined1 *)0x0,0,param_6,
                            param_7);
      }
      *(undefined4 *)(param_1 + 0x20) = 0x17;
      return uVar3 & 0xffffffffffffff00;
    }
    *plVar5 = local_res8;
    plVar5[1] = (longlong)pvVar2;
  }
  else {
    ZeroMemory((void *)plVar5[1],param_4);
  }
  *(uint *)(plVar5 + 2) = param_4;
  uVar4 = 0;
  *(undefined2 *)((longlong)plVar5 + 0x1c) = param_3;
  *(undefined4 *)(plVar5 + 3) = 0;
  *(undefined4 *)((longlong)plVar5 + 0x14) = 0;
  ZeroMemory(puVar1,0x80);
  *(undefined1 *)((longlong)puVar1 + 3) = 0x70;
  *puVar1 = 0xada2;
  puVar1[7] = param_2;
  puVar1[6] = *(undefined2 *)(param_1 + 0x35c);
  puVar1[8] = param_3;
  *(longlong *)(puVar1 + 0xc) = *plVar5;
  *(undefined1 *)(param_1 + 0x414) = 1;
  uVar3 = AdminQueueRequestPostPollReply
                    (param_1,puVar1,-0x525e,*(ushort *)(param_1 + 0x8b0),param_6,param_7);
  if (*(char *)(param_1 + 0x411) == '\0') {
    bVar8 = *(int *)(param_1 + 0x8b0) == 0;
    if (*(int *)(param_1 + 0x8b0) != 0) {
      do {
        lVar7 = 100;
        do {
          lVar6 = lVar7;
          uVar3 = StorPortStallExecution(1000);
          lVar7 = lVar6 + -1;
        } while (lVar7 != 0);
        if (*(char *)(param_1 + 0x408) != '\0') {
          uVar3 = Poll_mpi3Isr(param_1,(int)lVar6 + 2,param_7);
        }
      } while ((*(char *)(param_1 + 0x414) != '\0') &&
              (uVar4 = uVar4 + 1, uVar4 < *(uint *)(param_1 + 0x8b0)));
      bVar8 = uVar4 == *(uint *)(param_1 + 0x8b0);
    }
    if (bVar8) {
      uVar3 = LogSystemEvent(param_1,0,0xc004af02,(byte *)"Create OP Request Queue TIMEDOUT",param_6
                             ,param_7);
      *(undefined4 *)(param_1 + 0x20) = 0x18;
      return uVar3 & 0xffffffffffffff00;
    }
    if (*(char *)(param_1 + 0x415) == '\0') {
      uVar3 = LogSystemEvent(param_1,0,0xc004af02,(byte *)"create OP Request Queue Failed",param_6,
                             param_7);
      *(undefined4 *)(param_1 + 0x20) = 0x19;
      return uVar3 & 0xffffffffffffff00;
    }
  }
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== DriverEntry @ 1400036a0 =====

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
  pcStack_d0 = mpi3HWInitialize;
  local_c8 = mpi3StartIo;
  pcStack_c0 = mpi3Isr;
  local_b8 = mpi3FindAdapter;
  pcStack_b0 = mpi3OSBusReset;
  pcStack_60 = mpi3AdapterControl;
  local_58 = mpi3BuildIo;
  local_d8 = 0x5000000d0;
  uStack_80 = 0x101010102;
  local_98 = 0xc90;
  uStack_90 = 0x2000001d0;
  local_18 = 1;
  uStack_20 = 0x200000022;
  StorPortInitialize(0,param_2,&local_d8,0);
  return;
}



===== FreeMemoryAllocations @ 1400037a0 =====

void FreeMemoryAllocations(longlong param_1,ushort param_2,int *param_3)

{
  int local_res8 [2];
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar1;
  
  uVar1 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  if (*(char *)(param_1 + 0x408) == '\0') {
    FreeOperationalQueues(param_1,param_2,param_3);
    if (*(longlong *)(param_1 + 0x9b0) != 0) {
      local_res8[0] = StorPortExtendedFunction(1);
      if (local_res8[0] != 0) {
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x286) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x286,(undefined1 *)local_res8,4,param_2
                      ,param_3);
        }
        uVar1 = 1;
        LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                            "Kill Adapter (Driver) - Free mermory pool Failed",param_2,param_3);
        KillAdapter(param_1,0x19,param_2,param_3);
      }
      *(undefined8 *)(param_1 + 0x9b0) = 0;
      *(undefined4 *)(param_1 + 0x9d0) = 0;
    }
    if (*(longlong *)(param_1 + 0x9c0) != 0) {
      local_res8[0] =
           StorPortExtendedFunction
                     (0x19,param_1,*(longlong *)(param_1 + 0x9c0),*(undefined4 *)(param_1 + 0x9d4),
                      CONCAT44(uVar1,1));
      if (local_res8[0] != 0) {
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x287) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x287,(undefined1 *)local_res8,4,param_2
                      ,param_3);
        }
        LogOperationalEvent(param_1,local_res8,4,0xc004af02,
                            "Kill Adapter (Driver) - Free DMA mermory pointer Failed (logged status)"
                            ,param_2,param_3);
        KillAdapter(param_1,0x1a,param_2,param_3);
      }
      *(undefined8 *)(param_1 + 0x9c0) = 0;
      *(undefined4 *)(param_1 + 0x9d4) = 0;
    }
  }
  else {
    *(undefined8 *)(param_1 + 0x9b0) = 0;
    *(undefined8 *)(param_1 + 0x9c0) = 0;
    *(undefined8 *)(param_1 + 0x9d0) = 0;
  }
  return;
}



===== FreeOperationalQueues @ 140003980 =====

void FreeOperationalQueues(longlong param_1,ushort param_2,int *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int local_res8 [2];
  
  if (*(char *)(param_1 + 0x408) == '\0') {
    uVar1 = 1;
    if (*(short *)(param_1 + 0x388) != 0) {
      puVar2 = (undefined4 *)(*(longlong *)(param_1 + 0xa10) + 0x10);
      do {
        if (*(longlong *)(puVar2 + -2) != 0) {
          local_res8[0] =
               StorPortExtendedFunction(0x19,param_1,*(longlong *)(puVar2 + -2),*puVar2,1);
          if (local_res8[0] != 0) {
            if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x284) != 0))
            {
              RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x284,(undefined1 *)local_res8,4,
                          param_2,param_3);
            }
            LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                                "Kill Adapter (Driver) - Free mermory for Operationl Request Queue Failed"
                                ,param_2,param_3);
            KillAdapter(param_1,0x1b,param_2,param_3);
          }
          *(undefined8 *)(puVar2 + -2) = 0;
          *puVar2 = 0;
        }
        puVar2 = puVar2 + 8;
        uVar1 = uVar1 + 1;
      } while (uVar1 <= *(ushort *)(param_1 + 0x388));
    }
    uVar1 = 1;
    if (*(short *)(param_1 + 0x38a) != 0) {
      puVar2 = (undefined4 *)(*(longlong *)(param_1 + 0xa18) + 0x10);
      do {
        if (*(longlong *)(puVar2 + -2) != 0) {
          local_res8[0] =
               StorPortExtendedFunction(0x19,param_1,*(longlong *)(puVar2 + -2),*puVar2,1);
          if (local_res8[0] != 0) {
            if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x285) != 0))
            {
              RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x285,(undefined1 *)local_res8,4,
                          param_2,param_3);
            }
            LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                                "Kill Adapter (Driver) - Free mermory for Operationl Reply Queue Failed"
                                ,param_2,param_3);
            KillAdapter(param_1,0x1c,param_2,param_3);
          }
          *(undefined8 *)(puVar2 + -2) = 0;
          *puVar2 = 0;
        }
        puVar2 = puVar2 + 6;
        uVar1 = uVar1 + 1;
      } while (uVar1 <= *(ushort *)(param_1 + 0x38a));
    }
  }
  return;
}



===== GetNumaNodeData @ 140003bc0 =====

ulonglong GetNumaNodeData(longlong param_1,ushort param_2,int *param_3)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  ushort uVar11;
  char *pcVar12;
  short sVar13;
  int *piVar14;
  uint local_res8;
  
  piVar14 = *(int **)(param_1 + 0x338);
  iVar4 = StorPortExtendedFunction(0x17);
  if (iVar4 == 0) {
LAB_140003c68:
    if ((0x2f < (uint)piVar14[1]) && (*piVar14 == 1)) {
      uVar11 = *(ushort *)(param_1 + 0x298);
      puVar1 = *(undefined4 **)(param_1 + 0x9d8);
      ZeroMemory(puVar1,(uint)uVar11 << 3);
      if (uVar11 != 0) {
        uVar6 = (ulonglong)uVar11;
        puVar5 = puVar1;
        do {
          *puVar5 = 0xffffffff;
          puVar5 = puVar5 + 2;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      sVar13 = 0;
      local_res8 = 0;
      do {
        uVar11 = *(ushort *)((longlong)piVar14 + 0x1e);
        uVar6 = (ulonglong)uVar11;
        puVar7 = (ulonglong *)(piVar14 + 8);
        iVar4 = piVar14[2];
        if (uVar11 == 0) {
          uVar6 = 1;
LAB_140003d10:
          uVar8 = uVar6;
          do {
            uVar10 = 1;
            uVar2 = *puVar7;
            uVar11 = (short)puVar7[1] * 0x40;
            uVar6 = uVar6 & 0xffffffffffffff00;
            do {
              if ((uVar2 & uVar10) != 0) {
                sVar13 = sVar13 + 1;
                *(short *)((longlong)puVar1 + ((uVar6 & 0xff) + (ulonglong)uVar11) * 8 + 2) =
                     (short)iVar4;
                *(ushort *)(param_1 + 0x29a) = ((ushort)uVar6 & 0xff) + uVar11;
              }
              uVar10 = uVar10 * 2;
              bVar3 = (char)uVar6 + 1;
              uVar6 = CONCAT71((int7)(uVar6 >> 8),bVar3);
            } while (bVar3 < 0x40);
            puVar7 = puVar7 + 2;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
        }
        else if (uVar11 != 0) goto LAB_140003d10;
        local_res8 = local_res8 + piVar14[1];
        piVar14 = (int *)((longlong)piVar14 + (ulonglong)(uint)piVar14[1]);
      } while (local_res8 < 0x2000);
      if (sVar13 == *(short *)(param_1 + 0x294)) {
        return CONCAT71((int7)(uVar6 >> 8),1);
      }
      pcVar12 = "Core Count mismatch";
      uVar9 = 0x4004af00;
      goto LAB_140003dfe;
    }
  }
  else {
    LogSystemEvent(param_1,0,0x4004af00,(byte *)"Get RelationNumaNodeEx relationship failed",param_2
                   ,param_3);
    iVar4 = StorPortExtendedFunction(0x17);
    if (iVar4 == 0) goto LAB_140003c68;
  }
  pcVar12 = "Get RelationNumaNode relationship failed";
  uVar9 = 0xc004af02;
LAB_140003dfe:
  uVar6 = LogSystemEvent(param_1,0,uVar9,(byte *)pcVar12,param_2,param_3);
  return uVar6 & 0xffffffffffffff00;
}



===== InitializeAllocatedMemory @ 140003e20 =====

void InitializeAllocatedMemory(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 *puVar4;
  ushort uVar5;
  int *piVar6;
  ushort uVar7;
  
  uVar1 = *(ushort *)(param_1 + 0x368);
  lVar2 = *(longlong *)(param_1 + 0x9f0);
  uVar7 = uVar1;
  if (*(char *)(param_1 + 0x408) == '\0') {
    uVar7 = uVar1 + 6;
  }
  ZeroMemory(*(void **)(param_1 + 0x9f8),(uint)*(ushort *)(param_1 + 0x372) * 0x18);
  ZeroMemory(*(void **)(param_1 + 0xa00),(uint)*(ushort *)(param_1 + 0x372) << 3);
  uVar5 = 0;
  piVar6 = *(int **)(param_1 + 0x9e8);
  if (uVar1 != 0) {
    do {
      uVar3 = (uint)uVar5;
      uVar5 = uVar5 + 1;
      *piVar6 = uVar3 + 1;
      piVar6 = piVar6 + 1;
    } while (uVar5 < uVar1);
  }
  *(undefined4 *)(param_1 + 0xaec) = 0;
  uVar5 = 0;
  *(undefined4 *)(param_1 + 0xae8) = 0;
  *(uint *)(param_1 + 0xaf0) = (uint)uVar1;
  if (uVar7 != 0) {
    puVar4 = (undefined1 *)(lVar2 + 10);
    do {
      *(ushort *)(puVar4 + -2) = uVar5;
      uVar5 = uVar5 + 1;
      *(undefined8 *)(puVar4 + -10) = 0;
      *puVar4 = 0;
      *(undefined4 *)(puVar4 + 6) = 0;
      puVar4 = puVar4 + 0x18;
    } while (uVar5 < uVar7);
  }
  ZeroMemory(*(void **)(param_1 + 0x9e0),0x100);
  if (*(char *)(param_1 + 0x408) == '\0') {
    ZeroMemory(*(void **)(param_1 + 0xa10),(*(ushort *)(param_1 + 0x376) + 1) * 0x20);
    ZeroMemory(*(void **)(param_1 + 0xa18),(*(ushort *)(param_1 + 0x378) + 1) * 0x18);
    if (*(char *)(param_1 + 0x411) == '\0') {
      ZeroMemory(*(void **)(param_1 + 0xbc8),*(uint *)(param_1 + 0xbf8));
      ZeroMemory(*(void **)(param_1 + 0xaf8),0x1400);
      ZeroMemory(*(void **)(param_1 + 0xb70),(uint)*(ushort *)(param_1 + 0x3c4) << 2);
    }
  }
  return;
}



===== Internalmpi3HWInitialize @ 140003fa0 =====

undefined8 Internalmpi3HWInitialize(longlong param_1,ushort param_2,int *param_3)

{
  undefined4 *puVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  undefined8 uVar7;
  ushort uVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong *puVar11;
  undefined4 local_res20 [2];
  
  puVar1 = (undefined4 *)(param_1 + 0xab0);
  iVar6 = StorPortExtendedFunction(0xd,param_1,0,param_1 + 0xa90);
  if (iVar6 == 0) {
    *(undefined1 *)(param_1 + 0x3c1) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x3c2) = 0;
    LogSystemEvent(param_1,0,0x4004af00,(byte *)"StorPortGetMSIInfo failed, Numa Disabled",param_2,
                   param_3);
  }
  if ((*(char *)(param_1 + 0x3c2) != '\0') && (*(char *)(param_1 + 0x411) == '\0')) {
    *(undefined1 *)(param_1 + 0x3c2) = 0;
    *(undefined4 *)(param_1 + 0xab4) = 0x28;
    *puVar1 = 6;
    iVar6 = StorPortExtendedFunction(0xe,param_1,1,puVar1);
    if (iVar6 == 0) {
      uVar3 = *(uint *)(param_1 + 0xab8);
      uVar10 = uVar3 & 1;
      *(undefined4 *)(param_1 + 0xab4) = 0x28;
      *puVar1 = 6;
      if ((uVar3 & 4) != 0) {
        *(undefined4 *)(param_1 + 0xac0) = 0;
        uVar10 = uVar10 | 4;
        *(uint *)(param_1 + 0xac4) = *(ushort *)(param_1 + 0x3c4) - 1;
      }
      if ((uVar3 & 8) != 0) {
        uVar10 = uVar10 | 8;
        *(void **)(param_1 + 0xad0) = *(void **)(param_1 + 0x338);
        ZeroMemory(*(void **)(param_1 + 0x338),(uint)*(ushort *)(param_1 + 0x3c4) << 4);
      }
      if (uVar10 == 0xd) {
        *(undefined4 *)(param_1 + 0xab8) = 0xd;
        iVar6 = StorPortExtendedFunction(0xe,param_1,0,puVar1);
        if (iVar6 == 0) {
          *(undefined1 *)(param_1 + 0x3c2) = 1;
        }
        LogSystemEvent(param_1,0,0x4004af00,
                       (byte *)"StorPortInitializePerfOpts failed, Numa Disabled",param_2,param_3);
      }
    }
  }
  if (*(char *)(param_1 + 0x3c2) == '\0') {
    *(undefined2 *)(param_1 + 0x378) = 1;
    **(undefined2 **)(param_1 + 0x9d8) = 0;
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0x3c4);
    iVar6 = 0;
    lVar4 = *(longlong *)(param_1 + 0x9d8);
    uVar8 = 0;
    puVar11 = *(ulonglong **)(param_1 + 0x338);
    if (uVar2 != 0) {
      do {
        uVar9 = *puVar11;
        lVar5 = 0;
        if (uVar9 != 0) {
          for (; (uVar9 >> lVar5 & 1) == 0; lVar5 = lVar5 + 1) {
          }
        }
        if ((uVar9 != 0) &&
           (uVar9 = (ulonglong)((int)lVar5 + (uint)(ushort)puVar11[1] * 0x40),
           *(short *)(lVar4 + uVar9 * 8) == -1)) {
          *(ushort *)(lVar4 + uVar9 * 8) = uVar8;
          iVar6 = iVar6 + 1;
        }
        puVar11 = puVar11 + 2;
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar2);
    }
    *(int *)(param_1 + 0x3c8) = iVar6;
  }
  if (*(char *)(param_1 + 0x408) == '\0') {
    local_res20[0] = 0;
    StorPortNotification(0x1000,param_1,mpi3PassiveInitialization,local_res20);
  }
  else {
    CreateOperationalQueues(param_1,param_2,param_3);
    *(undefined1 *)(param_1 + 0x411) = 1;
  }
  uVar7 = ClearHwResetHistory(param_1);
  *(undefined1 *)(param_1 + 0x430) = 0;
  *(undefined4 *)(param_1 + 0x8e8) = 0;
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
}



===== IssueConfigPageMessagePolled @ 140004210 =====

void IssueConfigPageMessagePolled
               (longlong param_1,void *param_2,undefined4 param_3,ushort param_4,ushort param_5,
               int *param_6)

{
  int *piVar1;
  longlong lVar2;
  ushort uVar3;
  char *pcVar4;
  
  AdminQueueRequestPostPollReply(param_1,param_2,-0x525d,param_4,param_5,param_6);
  uVar3 = 0;
  if (param_4 != 0) {
    do {
      Poll_mpi3Isr(param_1,param_3,param_6);
      if (*(int *)(param_1 + 0x8d0) - 4U < 2) {
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x125) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x125,(undefined1 *)(param_1 + 0x8d0),4,
                      param_5,param_6);
        }
        break;
      }
      lVar2 = 100;
      do {
        StorPortStallExecution(1000);
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_4);
  }
  if ((uVar3 == param_4) || (*(int *)(param_1 + 0x8d0) == 5)) {
    piVar1 = (int *)(param_1 + 0x8d0);
    if (*piVar1 == 5) {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x292) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x292,(undefined1 *)piVar1,4,param_5,
                    param_6);
      }
      pcVar4 = "Config request received failure from IOC";
    }
    else {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x293) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x293,(undefined1 *)piVar1,4,param_5,
                    param_6);
      }
      pcVar4 = "Config request TIMEDOUT";
    }
    LogSystemEvent(param_1,0,0xc004af02,(byte *)pcVar4,param_5,param_6);
  }
  return;
}



===== IssueDiagBufferPostPolled @ 1400043e0 =====

bool IssueDiagBufferPostPolled
               (longlong param_1,undefined1 param_2,undefined8 param_3,undefined4 param_4,
               ushort param_5,int *param_6)

{
  undefined2 *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  bool bVar5;
  
  puVar1 = *(undefined2 **)(param_1 + 0x328);
  ZeroMemory(puVar1,0x80);
  *(undefined4 *)(puVar1 + 0xc) = param_4;
  *puVar1 = 0xada4;
  *(undefined1 *)((longlong)puVar1 + 3) = 0x81;
  *(undefined1 *)(puVar1 + 6) = param_2;
  *(undefined8 *)(puVar1 + 8) = param_3;
  uVar2 = AdminQueueRequestPost(param_1,puVar1,param_5,param_6);
  if ((char)uVar2 != '\0') {
    *(undefined1 *)(param_1 + 0x9a5) = 1;
  }
  uVar4 = 0;
  bVar5 = *(int *)(param_1 + 0x8b0) == 0;
  if (*(int *)(param_1 + 0x8b0) != 0) {
    do {
      Poll_mpi3Isr(param_1,2,param_6);
      if (*(char *)(param_1 + 0x9a5) == '\0') break;
      lVar3 = 100;
      do {
        StorPortStallExecution(1000);
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x8b0));
    bVar5 = uVar4 == *(uint *)(param_1 + 0x8b0);
  }
  if (bVar5) {
    LogSystemEvent(param_1,0,0xc004af02,
                   (byte *)"mpi3drv:DiagBuffer registration failed due to timeout",param_5,param_6);
  }
  return !bVar5;
}



===== MemoryNeededInDumpMode @ 140004500 =====

int MemoryNeededInDumpMode(longlong param_1)

{
  uint uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  
  uVar1 = **(uint **)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x35c) = 0x100010;
  *(undefined4 *)(param_1 + 0x370) = 0x3210080;
  *(short *)(param_1 + 0x36e) = 1 << ((byte)(uVar1 >> 0x14) & 0xf);
  *(undefined2 *)(param_1 + 0x364) = 4;
  *(undefined8 *)(param_1 + 0x3fc) = 0;
  *(undefined4 *)(param_1 + 0x376) = 0x10001;
  *(undefined2 *)(param_1 + 0x3c4) = 1;
  *(undefined4 *)(param_1 + 0x366) = 0x100005;
  *(undefined4 *)(param_1 + 0x360) = 0x110010;
  *(undefined2 *)(param_1 + 0x37a) = 1;
  uVar3 = 1 << ((byte)(uVar1 >> 0x10) & 0xf);
  *(ushort *)(param_1 + 0x36a) = uVar3;
  *(ushort *)(param_1 + 0x36c) = uVar3 >> 2;
  *(undefined4 *)(param_1 + 0x296) = 0x10001;
  *(undefined2 *)(param_1 + 0x29a) = 1;
  *(undefined2 *)(param_1 + 0x294) = 1;
  iVar4 = (uint)*(ushort *)(param_1 + 0x3c4) * 4 + (uint)*(ushort *)(param_1 + 0x368) * 0x1c +
          ((uint)*(ushort *)(param_1 + 0x298) + (uint)*(ushort *)(param_1 + 0x372) * 4) * 8 +
          (uint)*(ushort *)(param_1 + 0x378) * 0x18 + (uint)*(ushort *)(param_1 + 0x376) * 0x20 +
          0x17f8;
  *(int *)(param_1 + 0x9d0) = iVar4;
  iVar2 = (uint)*(ushort *)(param_1 + 0x364) * 0x108 + 0x410 +
          (*(ushort *)(param_1 + 0x370) + 8) * (uint)*(ushort *)(param_1 + 0x360) +
          (uint)*(ushort *)(param_1 + 0x36a) * (uint)*(ushort *)(param_1 + 0x35c) +
          (uint)*(ushort *)(param_1 + 0x36e) * (uint)*(ushort *)(param_1 + 0x35e);
  *(int *)(param_1 + 0x9d4) = iVar2;
  return iVar2 + iVar4;
}



===== PartitionDumpModeMemory @ 140004680 =====

void PartitionDumpModeMemory(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 local_res8 [8];
  
  uVar1 = *(ulonglong *)(param_1 + 0x9b0);
  if ((uVar1 & 7) != 0) {
    uVar1 = uVar1 + (8 - ((uint)uVar1 & 7));
  }
  *(ulonglong *)(param_1 + 0x9d8) = uVar1;
  lVar2 = uVar1 + (ulonglong)*(ushort *)(param_1 + 0x298) * 8;
  *(longlong *)(param_1 + 0x9e0) = lVar2;
  lVar2 = lVar2 + 0x100;
  *(longlong *)(param_1 + 0x9e8) = lVar2;
  uVar1 = lVar2 + (ulonglong)*(ushort *)(param_1 + 0x368) * 4;
  if ((uVar1 & 7) != 0) {
    uVar1 = uVar1 + (8 - ((uint)uVar1 & 7));
  }
  *(ulonglong *)(param_1 + 0x9f0) = uVar1;
  lVar2 = uVar1 + ((ulonglong)*(ushort *)(param_1 + 0x368) + 6) * 0x18;
  *(longlong *)(param_1 + 0x9f8) = lVar2;
  lVar2 = lVar2 + (ulonglong)*(ushort *)(param_1 + 0x372) * 0x18;
  *(longlong *)(param_1 + 0xa00) = lVar2;
  lVar2 = lVar2 + (ulonglong)*(ushort *)(param_1 + 0x372) * 8;
  *(longlong *)(param_1 + 0xa08) = lVar2;
  uVar1 = lVar2 + 0x1b0;
  if ((uVar1 & 7) != 0) {
    uVar1 = uVar1 + (8 - ((uint)uVar1 & 7));
  }
  *(ulonglong *)(param_1 + 0xa10) = uVar1;
  lVar2 = (ulonglong)*(ushort *)(param_1 + 0x376) * 0x20 + 0x20 + uVar1;
  *(longlong *)(param_1 + 0xa18) = lVar2;
  lVar2 = lVar2 + ((ulonglong)*(ushort *)(param_1 + 0x378) + 1) * 0x18;
  *(longlong *)(param_1 + 0xaf8) = lVar2;
  lVar2 = lVar2 + 0x1400;
  *(longlong *)(param_1 + 0xb70) = lVar2;
  lVar5 = *(longlong *)(param_1 + 0xa18);
  lVar6 = *(longlong *)(param_1 + 0xa10);
  lVar2 = lVar2 + (ulonglong)*(ushort *)(param_1 + 0x3c4) * 4;
  *(longlong *)(param_1 + 0x9b8) = lVar2;
  uVar1 = lVar2 + 1;
  *(ulonglong *)(param_1 + 0x9c0) = uVar1;
  lVar2 = StorPortGetPhysicalAddress(param_1,0,uVar1,local_res8);
  if ((uVar1 & 0x7f) != 0) {
    uVar3 = (ulonglong)(0x80 - ((uint)uVar1 & 0x7f));
    uVar1 = uVar1 + uVar3;
    lVar2 = lVar2 + uVar3;
  }
  uVar4 = (uint)*(ushort *)(param_1 + 0x36e) * (uint)*(ushort *)(param_1 + 0x35e);
  *(ulonglong *)(lVar5 + 0x20) = uVar1;
  *(longlong *)(lVar5 + 0x18) = lVar2;
  *(uint *)(lVar5 + 0x28) = uVar4;
  uVar1 = uVar1 + uVar4;
  lVar2 = lVar2 + (ulonglong)uVar4;
  if ((uVar1 & 0xf) != 0) {
    uVar3 = (ulonglong)(0x10 - ((uint)uVar1 & 0xf));
    uVar1 = uVar1 + uVar3;
    lVar2 = lVar2 + uVar3;
  }
  uVar4 = (uint)*(ushort *)(param_1 + 0x36a) * (uint)*(ushort *)(param_1 + 0x35c);
  *(ulonglong *)(lVar6 + 0x28) = uVar1;
  *(longlong *)(lVar6 + 0x20) = lVar2;
  *(uint *)(lVar6 + 0x30) = uVar4;
  uVar1 = uVar1 + uVar4;
  lVar2 = lVar2 + (ulonglong)uVar4;
  if ((uVar1 & 0xf) != 0) {
    uVar3 = (ulonglong)(0x10 - ((uint)uVar1 & 0xf));
    uVar1 = uVar1 + uVar3;
    lVar2 = lVar2 + uVar3;
  }
  *(ulonglong *)(param_1 + 0xa40) = uVar1;
  *(ulonglong *)(param_1 + 0xa50) = uVar1 - lVar2;
  *(longlong *)(param_1 + 0xa48) = lVar2;
  lVar5 = (ulonglong)*(ushort *)(param_1 + 0x370) * (ulonglong)*(ushort *)(param_1 + 0x360);
  lVar6 = uVar1 + lVar5;
  lVar2 = lVar2 + lVar5;
  *(longlong *)(param_1 + 0xa68) = lVar6;
  *(longlong *)(param_1 + 0xa70) = lVar2;
  lVar5 = (ulonglong)*(ushort *)(param_1 + 0x364) * 0x100;
  lVar6 = lVar6 + lVar5;
  lVar2 = lVar2 + lVar5;
  *(longlong *)(param_1 + 0xa58) = lVar6;
  *(longlong *)(param_1 + 0xa60) = lVar2;
  uVar4 = (uint)*(ushort *)(param_1 + 0x360) * 8 + 8;
  lVar6 = lVar6 + (ulonglong)uVar4;
  *(longlong *)(param_1 + 0xa78) = lVar6;
  *(ulonglong *)(param_1 + 0xa80) = (ulonglong)uVar4 + lVar2;
  *(ulonglong *)(param_1 + 0x9c8) = lVar6 + ((ulonglong)*(ushort *)(param_1 + 0x364) + 1) * 8;
  return;
}



===== PerformMemoryAllocations @ 140004930 =====

undefined8 PerformMemoryAllocations(longlong param_1,ushort param_2,int *param_3)

{
  ulonglong *puVar1;
  ulonglong *puVar2;
  longlong lVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  undefined8 in_RAX;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  int iVar12;
  undefined1 local_44 [12];
  
  puVar2 = (ulonglong *)(param_1 + 0x9b0);
  if (*(char *)(param_1 + 0x411) != '\0') {
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  uVar4 = *(ushort *)(param_1 + 0x298);
  uVar5 = *(ushort *)(param_1 + 0x364);
  uVar6 = *(ushort *)(param_1 + 0x360);
  uVar7 = *(ushort *)(param_1 + 0x368);
  iVar12 = (*(ushort *)(param_1 + 0x3c4) + 0x2f9e +
            ((uint)uVar4 +
            (uint)*(ushort *)(param_1 + 0x372) +
            ((uint)*(ushort *)(param_1 + 0x378) +
            (uVar7 + 6 & 0xffff) + (uint)*(ushort *)(param_1 + 0x372)) * 3 +
            (uint)*(ushort *)(param_1 + 0x376) * 4) * 2 + (uint)uVar7) * 4;
  *(int *)(param_1 + 0x9d0) = iVar12;
  iVar12 = StorPortExtendedFunction(0,param_1,iVar12,0x74726976,puVar2);
  if ((iVar12 == 0) && (*puVar2 != 0)) {
    puVar1 = (ulonglong *)(param_1 + 0x9c0);
    iVar12 = (*(ushort *)(param_1 + 0x370) + 8) * (uint)uVar6 + (uint)uVar5 * 0x108 +
             *(int *)(param_1 + 0xbf8) + *(int *)(param_1 + 0x3fc) +
             *(int *)(param_1 + 0x400) + 0x90;
    *(int *)(param_1 + 0x9d4) = iVar12;
    iVar12 = StorPortExtendedFunction
                       (0x18,param_1,iVar12,0,0xffffffffffffffff,0x100000000,1,0x80000000,puVar1);
    if ((iVar12 == 0) && (*puVar1 != 0)) {
      uVar8 = *puVar2;
      if ((uVar8 & 7) != 0) {
        uVar8 = uVar8 + (8 - ((uint)uVar8 & 7));
      }
      *(ulonglong *)(param_1 + 0x9d8) = uVar8;
      lVar9 = uVar8 + (ulonglong)uVar4 * 8;
      *(longlong *)(param_1 + 0x9e0) = lVar9;
      lVar9 = lVar9 + 0x100;
      *(longlong *)(param_1 + 0x9e8) = lVar9;
      uVar8 = lVar9 + (ulonglong)uVar7 * 4;
      if ((uVar8 & 7) != 0) {
        uVar8 = uVar8 + (8 - ((uint)uVar8 & 7));
      }
      *(ulonglong *)(param_1 + 0x9f0) = uVar8;
      lVar9 = uVar8 + (ulonglong)(uVar7 + 6 & 0xffff) * 0x18;
      *(longlong *)(param_1 + 0x9f8) = lVar9;
      lVar9 = lVar9 + (ulonglong)*(ushort *)(param_1 + 0x372) * 0x18;
      *(longlong *)(param_1 + 0xa00) = lVar9;
      lVar9 = lVar9 + (ulonglong)*(ushort *)(param_1 + 0x372) * 8;
      *(longlong *)(param_1 + 0xa08) = lVar9;
      uVar8 = lVar9 + 0xa8c0;
      if ((uVar8 & 7) != 0) {
        uVar8 = uVar8 + (8 - ((uint)uVar8 & 7));
      }
      *(ulonglong *)(param_1 + 0xa10) = uVar8;
      lVar9 = (ulonglong)*(ushort *)(param_1 + 0x376) * 0x20 + 0x20 + uVar8;
      *(longlong *)(param_1 + 0xa18) = lVar9;
      lVar9 = lVar9 + ((ulonglong)*(ushort *)(param_1 + 0x378) + 1) * 0x18;
      *(longlong *)(param_1 + 0xaf8) = lVar9;
      lVar9 = lVar9 + 0x1400;
      *(longlong *)(param_1 + 0xb70) = lVar9;
      uVar8 = *puVar1;
      *(ulonglong *)(param_1 + 0x9b8) = lVar9 + (ulonglong)*(ushort *)(param_1 + 0x3c4) * 4;
      lVar9 = StorPortGetPhysicalAddress(param_1,0,uVar8,local_44);
      if ((uVar8 & 0xf) != 0) {
        uVar10 = (ulonglong)(0x10 - ((uint)uVar8 & 0xf));
        uVar8 = uVar8 + uVar10;
        lVar9 = lVar9 + uVar10;
      }
      *(ulonglong *)(param_1 + 0xa40) = uVar8;
      *(longlong *)(param_1 + 0xa48) = lVar9;
      *(ulonglong *)(param_1 + 0xa50) = uVar8 - lVar9;
      uVar10 = (ulonglong)((uint)uVar6 * (uint)*(ushort *)(param_1 + 0x370));
      lVar11 = uVar8 + uVar10;
      lVar9 = lVar9 + uVar10;
      *(longlong *)(param_1 + 0xa68) = lVar11;
      uVar8 = (ulonglong)((uint)uVar6 * 8 + 8);
      *(longlong *)(param_1 + 0xa70) = lVar9;
      lVar11 = lVar11 + (ulonglong)uVar5 * 0x100;
      lVar9 = lVar9 + (ulonglong)uVar5 * 0x100;
      *(longlong *)(param_1 + 0xa58) = lVar11;
      lVar11 = lVar11 + uVar8;
      *(longlong *)(param_1 + 0xa60) = lVar9;
      lVar9 = lVar9 + uVar8;
      *(longlong *)(param_1 + 0xa78) = lVar11;
      *(longlong *)(param_1 + 0xa80) = lVar9;
      lVar3 = (ulonglong)uVar5 * 8 + 8;
      lVar11 = lVar11 + lVar3;
      lVar9 = lVar9 + lVar3;
      *(longlong *)(param_1 + 0xa20) = lVar11;
      *(longlong *)(param_1 + 0xa28) = lVar9;
      lVar11 = lVar11 + (ulonglong)*(uint *)(param_1 + 0x3fc);
      *(longlong *)(param_1 + 0xa30) = lVar11;
      *(ulonglong *)(param_1 + 0xa38) = (ulonglong)*(uint *)(param_1 + 0x3fc) + lVar9;
      uVar8 = lVar11 + (ulonglong)*(uint *)(param_1 + 0x400);
      if ((uVar8 & 0xf) != 0) {
        uVar8 = uVar8 + (0x10 - ((uint)uVar8 & 0xf));
      }
      if (*(char *)(param_1 + 0x411) == '\0') {
        *(ulonglong *)(param_1 + 0xbc8) = uVar8;
      }
      lVar9 = *(uint *)(param_1 + 0xbf8) + uVar8;
      *(longlong *)(param_1 + 0x9c8) = lVar9;
      return CONCAT71((int7)((ulonglong)lVar9 >> 8),1);
    }
    LogSystemEvent(param_1,0,0xc004af02,(byte *)"INIT Failed: Failed to allocate DMA\'able memory",
                   param_2,param_3);
    *(undefined4 *)(param_1 + 0x20) = 0x11;
    uVar8 = StorPortExtendedFunction(1,param_1,*puVar2);
    if ((int)uVar8 != 0) {
      uVar8 = LogSystemEvent(param_1,0,0xc004af02,
                             (byte *)"INIT Failed: Failed to free memory on INIT failure",param_2,
                             param_3);
    }
    *puVar2 = 0;
  }
  else {
    uVar8 = LogSystemEvent(param_1,0,0xc004af02,
                           (byte *)"INIT Failed: Failed to allocate virtual Memory",param_2,param_3)
    ;
    *(undefined4 *)(param_1 + 0x20) = 0x10;
  }
  return uVar8 & 0xffffffffffffff00;
}



===== PopulateReplySenseFreeQueues @ 140004d70 =====

void PopulateReplySenseFreeQueues(longlong param_1)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong lVar5;
  
  uVar1 = *(ushort *)(param_1 + 0x370);
  uVar3 = (ulonglong)*(ushort *)(param_1 + 0x360);
  plVar4 = *(longlong **)(param_1 + 0xa58);
  uVar2 = (uint)*(ushort *)(param_1 + 0x360);
  lVar5 = *(longlong *)(param_1 + 0xa48);
  if (uVar2 != 0) {
    do {
      *plVar4 = lVar5;
      plVar4 = plVar4 + 1;
      lVar5 = lVar5 + (ulonglong)uVar1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  *plVar4 = 0;
  *(uint *)(param_1 + 0xa88) = uVar2;
  **(uint **)(param_1 + 0xd8) = uVar2;
  LOCK();
  UNLOCK();
  plVar4 = *(longlong **)(param_1 + 0xa78);
  lVar5 = *(longlong *)(param_1 + 0xa70);
  *(uint *)(param_1 + 0xa88) = uVar2;
  uVar3 = (ulonglong)*(ushort *)(param_1 + 0x364);
  uVar2 = (uint)*(ushort *)(param_1 + 0x364);
  if (uVar2 != 0) {
    do {
      *plVar4 = lVar5;
      plVar4 = plVar4 + 1;
      lVar5 = lVar5 + 0x100;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  *plVar4 = 0;
  *(uint *)(param_1 + 0xa8c) = uVar2;
  **(uint **)(param_1 + 0xe0) = uVar2;
  LOCK();
  UNLOCK();
  *(uint *)(param_1 + 0xa8c) = uVar2;
  return;
}



===== ProcessIOCFactsData @ 140004e30 =====

ulonglong ProcessIOCFactsData(longlong param_1,ushort param_2,int *param_3)

{
  longlong lVar1;
  byte bVar2;
  short sVar3;
  ulonglong uVar4;
  ushort uVar5;
  ushort uVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x330);
  *(undefined4 *)(param_1 + 0x348) = *(undefined4 *)(lVar1 + 4);
  uVar6 = *(short *)(lVar1 + 0x1e) * 4;
  *(ushort *)(param_1 + 0x370) = uVar6;
  *(byte *)(param_1 + 0x38c) = *(byte *)(lVar1 + 0x44) & 0xf;
  *(undefined2 *)(param_1 + 0x34c) = *(undefined2 *)(lVar1 + 8);
  *(undefined2 *)(param_1 + 0x34e) = *(undefined2 *)(lVar1 + 10);
  *(undefined1 *)(param_1 + 0x353) = *(undefined1 *)(lVar1 + 0xf);
  *(undefined1 *)(param_1 + 0x352) = *(undefined1 *)(lVar1 + 0xe);
  *(undefined1 *)(param_1 + 0x351) = *(undefined1 *)(lVar1 + 0xd);
  *(undefined1 *)(param_1 + 0x350) = *(undefined1 *)(lVar1 + 0xc);
  *(uint *)(param_1 + 0x354) = (uint)*(byte *)(lVar1 + 0x24) << (*(byte *)(lVar1 + 0x26) & 0x1f);
  *(uint *)(param_1 + 0x358) = (uint)*(byte *)(lVar1 + 0x25) << (*(byte *)(lVar1 + 0x26) & 0x1f);
  sVar3 = 0x3c;
  if (*(short *)(lVar1 + 0x4c) != 0) {
    sVar3 = *(short *)(lVar1 + 0x4c);
  }
  *(short *)(param_1 + 0x3f8) = sVar3;
  *(undefined8 *)(param_1 + 0x3fc) = 0;
  if (*(char *)(param_1 + 0x408) == '\0') {
    sVar3 = *(short *)(lVar1 + 0x18);
    *(ushort *)(param_1 + 0x368) = sVar3 - 7U;
    *(undefined2 *)(param_1 + 0x36c) = *(undefined2 *)(lVar1 + 0x1c);
    *(short *)(param_1 + 0x36a) = *(short *)(lVar1 + 0x1c) << 2;
    *(undefined2 *)(param_1 + 0x372) = *(undefined2 *)(lVar1 + 0x22);
    *(undefined2 *)(param_1 + 0x376) = *(undefined2 *)(lVar1 + 0x48);
    *(undefined2 *)(param_1 + 0x378) = *(undefined2 *)(lVar1 + 0x4a);
    *(short *)(param_1 + 0x360) = sVar3 + 0x19;
    uVar6 = (ushort)(sVar3 - 7U) / 3;
    *(ushort *)(param_1 + 0x364) = uVar6;
    *(ushort *)(param_1 + 0x366) = uVar6 + 1;
    *(short *)(param_1 + 0x362) = sVar3 + 0x1a;
    if (1 < *(ushort *)(lVar1 + 0x16)) {
      if (*(char *)(param_1 + 0x3c3) == '\0') {
        *(ushort *)(param_1 + 0x3c4) = *(ushort *)(lVar1 + 0x16);
        *(undefined1 *)(param_1 + 0x3c2) = 1;
      }
      else {
        *(undefined2 *)(param_1 + 0x3c4) = 1;
        *(undefined1 *)(param_1 + 0x3c2) = 0;
      }
    }
  }
  else if (uVar6 != 0x80) {
    *(short *)(param_1 + 0x360) = (short)(0x800 / (ulonglong)uVar6) + -1;
  }
  uVar6 = 1;
  if (0x80 < *(ushort *)(param_1 + 0x372)) {
    uVar6 = ((ushort)(*(ushort *)(param_1 + 0x372) - 0x81) >> 7) + 2;
    uVar5 = 0xff;
    if (0xff < uVar6) goto LAB_140005019;
  }
  uVar5 = uVar6;
LAB_140005019:
  *(ushort *)(param_1 + 0x374) = uVar5;
  bVar2 = *(byte *)(lVar1 + 0x27);
  if ((bVar2 & 4) != 0) {
    *(undefined1 *)(param_1 + 0x394) = 1;
    bVar2 = *(byte *)(lVar1 + 0x27);
  }
  if ((bVar2 & 2) != 0) {
    *(undefined1 *)(param_1 + 0x395) = 1;
  }
  sVar3 = 1 << ((byte)(**(uint **)(param_1 + 0x40) >> 0x10) & 0xf);
  if (*(short *)(param_1 + 0x36a) == sVar3) {
    *(short *)(param_1 + 0x36e) = 1 << ((byte)(**(uint **)(param_1 + 0x40) >> 0x14) & 0xf);
    return CONCAT71((uint7)(byte)((ushort)sVar3 >> 8),1);
  }
  uVar4 = LogSystemEvent(param_1,0,0xc004af02,
                         (byte *)
                         "INIT Failed: Operational Request Queue Entry size mismatched in IOCFacts",
                         param_2,param_3);
  *(undefined4 *)(param_1 + 0x20) = 0xf;
  return uVar4 & 0xffffffffffffff00;
}



===== ProcessPolledReplyDescriptor @ 1400050c0 =====

void ProcessPolledReplyDescriptor
               (longlong param_1,longlong *param_2,undefined2 *param_3,undefined4 *param_4,
               undefined8 *param_5,undefined2 *param_6,ushort param_7,int *param_8)

{
  ushort uVar1;
  undefined2 *puVar2;
  
  *param_5 = 0;
  uVar1 = *(ushort *)((longlong)param_2 + 0xe) & 0xf000;
  if ((*(ushort *)((longlong)param_2 + 0xe) & 0xf000) == 0) {
    puVar2 = (undefined2 *)(*(longlong *)(param_1 + 0xa50) + *param_2);
    *param_5 = param_2;
    *param_3 = puVar2[5];
    *param_4 = *(undefined4 *)(puVar2 + 6);
    *param_6 = *puVar2;
    return;
  }
  if (uVar1 == 0x1000) {
    *param_3 = 0;
    *param_4 = 0;
    *param_6 = *(undefined2 *)((longlong)param_2 + 0xc);
    return;
  }
  if (uVar1 == 0x3000) {
    *param_3 = (short)*param_2;
    *param_4 = *(undefined4 *)((longlong)param_2 + 4);
    *param_6 = *(undefined2 *)((longlong)param_2 + 0xc);
    return;
  }
  *param_3 = 0x7fff;
  LogSystemEvent(param_1,0,0xc004af02,(byte *)"Invalid Reply Descriptor received",param_7,param_8);
  return;
}



===== ReadWriteConfigPages @ 140005170 =====

void ReadWriteConfigPages(longlong param_1,undefined4 param_2,ushort param_3,int *param_4)

{
  int iVar1;
  undefined2 *puVar2;
  longlong lVar3;
  ushort local_res8 [4];
  
  puVar2 = *(undefined2 **)(param_1 + 0xb90);
  do {
    while( true ) {
      while (iVar1 = *(int *)(param_1 + 0x8d0), iVar1 == 1) {
        *(undefined4 *)(param_1 + 0x8d0) = 2;
      }
      if (iVar1 != 2) break;
      ZeroMemory(puVar2,0x80);
      *(undefined4 *)(puVar2 + 6) = 0x10000;
      *(undefined1 *)((longlong)puVar2 + 3) = 0x10;
      *puVar2 = 0xada3;
      puVar2[10] = 0;
      local_res8[0] = 8;
      if (*(uint *)(param_1 + 0xba0) < 8) {
LAB_1400052e4:
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x294) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x294,(undefined1 *)local_res8,2,param_3
                      ,param_4);
        }
        *(undefined4 *)(param_1 + 0x8d0) = 5;
      }
      else {
        *(undefined8 *)(param_1 + 0xb78) = *(undefined8 *)(param_1 + 0xb98);
        *(undefined8 *)(puVar2 + 0x10) = *(undefined8 *)(param_1 + 0xb88);
        *(undefined4 *)(puVar2 + 0x14) = 8;
        *(undefined1 *)((longlong)puVar2 + 0x2f) = 8;
        *(longlong *)(param_1 + 0xb98) = *(longlong *)(param_1 + 0xb98) + 8;
        *(longlong *)(param_1 + 0xb88) = *(longlong *)(param_1 + 0xb88) + 8;
        *(int *)(param_1 + 0xba0) = *(int *)(param_1 + 0xba0) + -8;
        IssueConfigPageMessagePolled
                  (param_1,puVar2,param_2,*(ushort *)(param_1 + 0x8b0),param_3,param_4);
        if (*(int *)(param_1 + 0x8d0) == 4) {
          *(undefined4 *)(param_1 + 0x8d0) = 3;
        }
      }
    }
    if (iVar1 != 3) {
      *(undefined4 *)(param_1 + 0x8d0) = 0;
      return;
    }
    local_res8[0] = *(short *)(*(longlong *)(param_1 + 0xb78) + 4) << 2;
    ZeroMemory(puVar2,0x80);
    *(undefined1 *)((longlong)puVar2 + 0xf) = 2;
    *(undefined1 *)((longlong)puVar2 + 3) = 0x10;
    *puVar2 = 0xada3;
    puVar2[10] = local_res8[0];
    *(undefined2 *)((longlong)puVar2 + 0xd) = 0x100;
    if (*(uint *)(param_1 + 0xba0) < (uint)local_res8[0]) goto LAB_1400052e4;
    lVar3 = *(longlong *)(param_1 + 0xb98);
    *(undefined8 *)(puVar2 + 0x10) = *(undefined8 *)(param_1 + 0xb88);
    *(uint *)(puVar2 + 0x14) = (uint)local_res8[0];
    *(undefined1 *)((longlong)puVar2 + 0x2f) = 8;
    *(longlong *)(param_1 + 0xb98) = *(longlong *)(param_1 + 0xb98) + (ulonglong)local_res8[0];
    *(longlong *)(param_1 + 0xb88) = *(longlong *)(param_1 + 0xb88) + (ulonglong)local_res8[0];
    *(int *)(param_1 + 0xba0) = *(int *)(param_1 + 0xba0) - (uint)local_res8[0];
    IssueConfigPageMessagePolled
              (param_1,puVar2,param_2,*(ushort *)(param_1 + 0x8b0),param_3,param_4);
    if (*(int *)(param_1 + 0x8d0) == 4) {
      memmove((void *)(param_1 + 0xba4),(void *)(lVar3 + 0x70),0x20);
      *(undefined1 *)(param_1 + 0xbc4) = 0;
    }
  } while( true );
}



===== mpi3AdapterControl @ 1400053f0 =====

undefined8 mpi3AdapterControl(longlong param_1,int param_2,undefined4 *param_3)

{
  bool bVar1;
  int local_res8;
  undefined1 local_resc;
  
  local_resc = 0;
  local_res8 = 1;
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 1) = 0x101;
    *(undefined1 *)((longlong)param_3 + 6) = 1;
    *(undefined1 *)((longlong)param_3 + 0x15) = 1;
  }
  else if (param_2 == 1) {
    if (*(int *)(param_1 + 0x8c8) == 0) {
      LOCK();
      bVar1 = *(int *)(param_1 + 0x41c) == 0;
      if (bVar1) {
        *(int *)(param_1 + 0x41c) = 1;
      }
      UNLOCK();
      if (bVar1) {
        *(undefined8 *)(param_1 + 0x8c4) = 4;
        StartShutdown(param_1,0,&local_res8);
        return 0;
      }
    }
  }
  else {
    if (param_2 == 2) {
      *(undefined8 *)(param_1 + 0x8c4) = 5;
      *(undefined4 *)(param_1 + 0x41c) = 0;
      *(undefined1 *)(param_1 + 0x410) = 0;
      *(undefined1 *)(param_1 + 0x417) = 0;
      *(undefined4 *)(param_1 + 0x8a4) = 1;
      *(undefined4 *)(param_1 + 0x428) = 1;
      StartAdapterReset(param_1,0x100,0,&local_res8);
      return 0;
    }
    if (param_2 == 0x11) {
      ZeroMemory(param_3,0x10c);
      *param_3 = 1;
      param_3[1] = 0x10c;
      *(undefined1 *)(param_3 + 2) = 0;
      memmove((void *)((longlong)param_3 + 9),(void *)(param_1 + 0xba4),0x20);
      return 0;
    }
  }
  return 0;
}



===== mpi3FindAdapter @ 140005530 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
mpi3FindAdapter(undefined8 *param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               longlong param_5)

{
  ushort *puVar1;
  longlong *plVar2;
  byte bVar3;
  short sVar4;
  undefined2 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  char cVar9;
  uint uVar10;
  undefined4 uVar11;
  longlong lVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  undefined1 *puVar16;
  ushort uVar17;
  int iVar18;
  undefined8 *puVar19;
  byte *pbVar20;
  longlong *plVar21;
  uint *puVar22;
  int *piVar23;
  ushort uVar24;
  ushort uVar25;
  short sVar26;
  uint uVar27;
  char *pcVar28;
  uint uVar29;
  bool bVar30;
  undefined1 local_10a8 [32];
  int local_1068;
  undefined1 local_1064;
  int local_1060 [2];
  longlong local_1058 [2];
  undefined8 local_1048 [32];
  ushort local_f48 [1920];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_10a8;
  uVar29 = 0;
  local_1068 = 0xf;
  local_1064 = 0;
  if (param_1[1] != 0) {
    ZeroMemory(param_1,0xc90);
  }
  *param_1 = 0x7672643369706d;
  *(undefined4 *)(param_1 + 0x11a) = 0;
  memmove((void *)((longlong)param_1 + 0xba4),"NOT AVAILABLE",0xe);
  *(undefined1 *)(param_1 + 0x78) = 0;
  puVar13 = *(undefined8 **)(param_5 + 0x38);
  if (*(int *)(puVar13 + 1) == 0) {
LAB_140005603:
    LogSystemEvent((longlong)param_1,0,0xc004af02,
                   (byte *)"INIT Failed: Failed to get MemoryMap Access Range",0,&local_1068);
    *(undefined4 *)(param_1 + 4) = 1;
LAB_14000568f:
    if (*(char *)(param_1 + 0x81) == '\0') {
      FreeOperationalQueues((longlong)param_1,0,&local_1068);
      if (param_1[0x136] != 0) {
        local_1060[0] = StorPortExtendedFunction(1);
        if (local_1060[0] != 0) {
          if ((*(char *)(param_1 + 0x180) != '\0') &&
             ((*(uint *)((longlong)param_1 + 0xc04) & 0x286) != 0)) {
            RttLogEvent((longlong)param_1,param_1 + 0x179,0x286,(undefined1 *)local_1060,4,0,
                        &local_1068);
          }
          LogOperationalEvent((longlong)param_1,(int *)0x0,0,0xc004af02,
                              "Kill Adapter (Driver) - Free mermory pool Failed",0,&local_1068);
          KillAdapter((longlong)param_1,0x19,0,&local_1068);
        }
        param_1[0x136] = 0;
        *(undefined4 *)(param_1 + 0x13a) = 0;
      }
      if (param_1[0x138] == 0) {
        return 0;
      }
      local_1060[0] =
           StorPortExtendedFunction
                     (0x19,param_1,param_1[0x138],*(undefined4 *)((longlong)param_1 + 0x9d4));
      if (local_1060[0] != 0) {
        if ((*(char *)(param_1 + 0x180) != '\0') &&
           ((*(uint *)((longlong)param_1 + 0xc04) & 0x287) != 0)) {
          RttLogEvent((longlong)param_1,param_1 + 0x179,0x287,(undefined1 *)local_1060,4,0,
                      &local_1068);
        }
        LogOperationalEvent((longlong)param_1,local_1060,4,0xc004af02,
                            "Kill Adapter (Driver) - Free DMA mermory pointer Failed (logged status)"
                            ,0,&local_1068);
        KillAdapter((longlong)param_1,0x1a,0,&local_1068);
      }
      *(undefined4 *)((longlong)param_1 + 0x9d4) = 0;
    }
    else {
      param_1[0x136] = 0;
      param_1[0x13a] = 0;
    }
    param_1[0x138] = 0;
    return 0;
  }
  uVar27 = 0;
  puVar19 = puVar13;
  while ((*(int *)(puVar19 + 1) == 0 || (*(char *)((longlong)puVar19 + 0xc) == '\0'))) {
    uVar27 = uVar27 + 1;
    puVar19 = puVar13 + (ulonglong)uVar27 * 2;
    if (1 < uVar27) goto LAB_140005603;
  }
  lVar12 = StorPortGetDeviceBase
                     (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),*puVar19);
  param_1[5] = lVar12;
  if (lVar12 == 0) {
    LogSystemEvent((longlong)param_1,0,0xc004af02,
                   (byte *)"INIT Failed: Failed to get base address of System Register",0,
                   &local_1068);
    *(undefined4 *)(param_1 + 4) = 2;
    goto LAB_14000568f;
  }
  ZeroMemory(local_1048,0x1000);
  uVar10 = StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 100))
  ;
  puVar1 = local_f48;
  if (local_f48[0] < 0x100) {
    lVar12 = 2;
    puVar13 = param_1 + 0x1f;
    puVar19 = local_1048;
    do {
      uVar15 = puVar19[1];
      uVar6 = puVar19[2];
      uVar7 = puVar19[3];
      *puVar13 = *puVar19;
      puVar13[1] = uVar15;
      uVar15 = puVar19[4];
      uVar8 = puVar19[5];
      puVar13[2] = uVar6;
      puVar13[3] = uVar7;
      uVar6 = puVar19[6];
      uVar7 = puVar19[7];
      puVar13[4] = uVar15;
      puVar13[5] = uVar8;
      uVar15 = puVar19[8];
      uVar8 = puVar19[9];
      puVar13[6] = uVar6;
      puVar13[7] = uVar7;
      uVar6 = puVar19[10];
      uVar7 = puVar19[0xb];
      puVar13[8] = uVar15;
      puVar13[9] = uVar8;
      uVar15 = puVar19[0xc];
      uVar8 = puVar19[0xd];
      puVar13[10] = uVar6;
      puVar13[0xb] = uVar7;
      uVar6 = puVar19[0xe];
      uVar7 = puVar19[0xf];
      puVar13[0xc] = uVar15;
      puVar13[0xd] = uVar8;
      puVar13[0xe] = uVar6;
      puVar13[0xf] = uVar7;
      lVar12 = lVar12 + -1;
      puVar13 = puVar13 + 0x10;
      puVar19 = puVar19 + 0x10;
    } while (lVar12 != 0);
    while( true ) {
      if ((0xf < uVar27) || (0xfe < (ushort)(*puVar1 - 1))) goto LAB_140005793;
      if (*puVar1 == 3) break;
      uVar27 = uVar27 + 1;
      puVar1 = puVar1 + (ulonglong)(puVar1[1] >> 4) * 2;
    }
    if (*(int *)(puVar1 + 2) != 0) goto LAB_140005793;
    pcVar28 = "mpi3drv:INIT Failed: Adapter is INVALID";
  }
  else {
    uVar10 = StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),
                                *(undefined4 *)(param_5 + 100));
    lVar12 = 2;
    puVar13 = param_1 + 0x1f;
    puVar19 = local_1048;
    do {
      uVar15 = puVar19[1];
      uVar6 = puVar19[2];
      uVar7 = puVar19[3];
      *puVar13 = *puVar19;
      puVar13[1] = uVar15;
      uVar15 = puVar19[4];
      uVar8 = puVar19[5];
      puVar13[2] = uVar6;
      puVar13[3] = uVar7;
      uVar6 = puVar19[6];
      uVar7 = puVar19[7];
      puVar13[4] = uVar15;
      puVar13[5] = uVar8;
      uVar15 = puVar19[8];
      uVar8 = puVar19[9];
      puVar13[6] = uVar6;
      puVar13[7] = uVar7;
      uVar6 = puVar19[10];
      uVar7 = puVar19[0xb];
      puVar13[8] = uVar15;
      puVar13[9] = uVar8;
      uVar15 = puVar19[0xc];
      uVar8 = puVar19[0xd];
      puVar13[10] = uVar6;
      puVar13[0xb] = uVar7;
      uVar6 = puVar19[0xe];
      uVar7 = puVar19[0xf];
      puVar13[0xc] = uVar15;
      puVar13[0xd] = uVar8;
      puVar13[0xe] = uVar6;
      puVar13[0xf] = uVar7;
      lVar12 = lVar12 + -1;
      puVar13 = puVar13 + 0x10;
      puVar19 = puVar19 + 0x10;
    } while (lVar12 != 0);
LAB_140005793:
    puVar22 = (uint *)param_1[5];
    param_1[6] = puVar22;
    param_1[8] = puVar22 + 5;
    param_1[9] = puVar22 + 7;
    param_1[10] = puVar22 + 9;
    param_1[7] = puVar22 + 1;
    param_1[0xb] = puVar22 + 10;
    param_1[0xc] = puVar22 + 0xb;
    param_1[0xd] = puVar22 + 0xc;
    param_1[0xe] = puVar22 + 0xd;
    param_1[0xf] = puVar22 + 0x400;
    param_1[0x11] = puVar22 + 0x401;
    param_1[0x13] = puVar22 + 0x402;
    param_1[0x14] = puVar22 + 0x403;
    param_1[0x15] = puVar22 + 0x701;
    param_1[0x16] = puVar22 + 0x702;
    param_1[0x17] = puVar22 + 0x704;
    param_1[0x18] = puVar22 + 0x705;
    param_1[0x19] = puVar22 + 0x706;
    param_1[0x1a] = puVar22 + 0x707;
    param_1[0x1b] = puVar22 + 0x710;
    param_1[0x1c] = puVar22 + 0x711;
    param_1[0x1d] = puVar22 + 0x73c;
    param_1[0x1e] = puVar22 + 0x73d;
    if (2 < uVar10) {
      uVar29 = *(int *)(param_5 + 4) << 8 | *(uint *)(param_5 + 100);
      SetAdapInfo((longlong)param_1,(longlong)(param_1 + 0x1f),uVar29);
      puVar22 = (uint *)param_1[6];
    }
    *(uint *)(param_1 + 0x68) = (*puVar22 >> 0x18) * 0x14;
    uVar27 = *(uint *)param_1[9] & 1;
    if ((*(uint *)param_1[9] & 2) == 0) {
      if ((*(uint *)param_1[8] & 1) != 0) {
        if (uVar27 == 0) goto LAB_140005a3b;
        *(undefined4 *)((longlong)param_1 + 0x8c4) = 3;
        uVar14 = InitiateMURPollMode((longlong)param_1,0,&local_1068);
        cVar9 = (char)uVar14;
        goto LAB_140005a58;
      }
      if (uVar27 != 0) {
LAB_140005a3b:
        *(undefined4 *)((longlong)param_1 + 0x8c4) = 9;
        goto LAB_140005a45;
      }
    }
    else {
      uVar11 = *(undefined4 *)param_1[0x17];
      *(undefined4 *)((longlong)param_1 + 0x42c) = uVar11;
      *(undefined4 *)((longlong)param_1 + 0x8c4) = 7;
      *(undefined4 *)param_1[0x1e] = uVar11;
      LOCK();
      UNLOCK();
LAB_140005a45:
      uVar14 = InitiateResetPollMode((longlong)param_1,0x100,0,&local_1068);
      cVar9 = (char)uVar14;
LAB_140005a58:
      if (cVar9 == '\0') goto LAB_14000568f;
    }
    plVar2 = param_1 + 0x179;
    RttSetTraceParameters((longlong)plVar2,0x32000,1);
    if (param_4 != (char *)0x0) {
      ProcessRegistrySettings((longlong)param_1,param_4);
    }
    if (*(char *)(param_1 + 0x81) != '\0') {
      RttSetTraceParameters((longlong)plVar2,0,0);
    }
    *(undefined4 *)((longlong)param_1 + 0xb6c) = 0xc;
    if (*(char *)(param_5 + 0x90) == -0x80) {
      *(undefined1 *)(param_5 + 0x90) = 4;
    }
    if (*(char *)(param_1 + 0x81) == '\0') {
      uVar27 = 0x100;
      if (*(uint *)((longlong)param_1 + 0x9ac) != 0) {
        uVar27 = *(uint *)((longlong)param_1 + 0x9ac);
      }
    }
    else {
      uVar27 = 0x11;
    }
    *(uint *)(param_5 + 0x1c) = uVar27;
    iVar18 = (uVar27 & 0xffff) - 3;
    *(undefined4 *)(param_5 + 0x18) = 0xffffff;
    *(undefined1 *)(param_5 + 0x51) = 1;
    *(uint *)(param_5 + 0x8c) =
         (uint)(ushort)((((short)(iVar18 / 0xff) + (short)(iVar18 >> 0x1f)) -
                        (short)((longlong)iVar18 * 0x80808081 >> 0x3f)) + 1) * 0x1000 + 0xf0;
    uVar15 = AllocateFixedSizedMemoryBuffers((longlong)param_1,param_5,0,&local_1068);
    if ((char)uVar15 != '\0') {
      if (*(char *)(param_1 + 0x81) == '\0') {
        piVar23 = (int *)param_1[0x67];
        local_1060[1] = 0x2000;
        sVar26 = 0;
        iVar18 = StorPortExtendedFunction(0x17);
        if (((iVar18 == 0) && (0x4f < (uint)piVar23[1])) && (*piVar23 == 4)) {
          sVar4 = *(short *)((longlong)piVar23 + 10);
          *(short *)((longlong)param_1 + 0x296) = sVar4;
          *(short *)(param_1 + 0x53) = sVar4 << 6;
          if (*(ushort *)((longlong)piVar23 + 10) != 0) {
            uVar14 = (ulonglong)*(ushort *)((longlong)piVar23 + 10);
            pbVar20 = (byte *)((longlong)piVar23 + 0x21);
            do {
              bVar3 = *pbVar20;
              pbVar20 = pbVar20 + 0x30;
              sVar26 = sVar26 + (ushort)bVar3;
              uVar14 = uVar14 - 1;
            } while (uVar14 != 0);
          }
          *(short *)((longlong)param_1 + 0x294) = sVar26;
        }
        else {
          LogSystemEvent((longlong)param_1,0,0xc004af02,
                         (byte *)"Get RelationGroup relationship failed",0,&local_1068);
          LogSystemEvent((longlong)param_1,0,0xc004af02,
                         (byte *)"INIT Failed: MPI_LOG_GROUP_INFO_FAILED",0,&local_1068);
          *(undefined2 *)((longlong)param_1 + 0x3c2) = 0x100;
        }
      }
      *(undefined4 *)param_1[10] = *(undefined4 *)(param_1 + 0x54);
      LOCK();
      UNLOCK();
      *(undefined4 *)param_1[0xb] = *(undefined4 *)(param_1 + 0x57);
      LOCK();
      UNLOCK();
      *(undefined4 *)param_1[0xc] = *(undefined4 *)((longlong)param_1 + 700);
      LOCK();
      UNLOCK();
      *(undefined4 *)param_1[0xd] = *(undefined4 *)(param_1 + 0x58);
      LOCK();
      UNLOCK();
      *(undefined4 *)param_1[0xe] = *(undefined4 *)((longlong)param_1 + 0x2c4);
      LOCK();
      UNLOCK();
      *(undefined2 *)param_1[0xf] = 0;
      LOCK();
      UNLOCK();
      *(undefined2 *)param_1[0x11] = 0;
      LOCK();
      UNLOCK();
      ZeroMemory((void *)param_1[0x5a],*(uint *)(param_1 + 0x55));
      ZeroMemory((void *)param_1[0x59],*(uint *)((longlong)param_1 + 0x2a4));
      *(undefined4 *)((longlong)param_1 + 0x2ac) = 0;
      *(undefined2 *)(param_1 + 0x56) = 0;
      *(undefined4 *)(param_1 + 0x5b) = 1;
      *(uint *)param_1[8] = *(uint *)param_1[8] | 1;
      LOCK();
      UNLOCK();
      uVar27 = *(uint *)(param_1 + 0x68);
      uVar10 = 0;
      if (uVar27 != 0) {
        do {
          if ((*(uint *)param_1[9] & 1) != 0) break;
          lVar12 = 100;
          do {
            StorPortStallExecution(1000);
            lVar12 = lVar12 + -1;
          } while (lVar12 != 0);
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar27);
      }
      if (uVar10 == uVar27) {
        LogSystemEvent((longlong)param_1,0,0xc004af02,(byte *)"INIT Failed: IOC did not reach Ready"
                       ,0,&local_1068);
        *(undefined4 *)(param_1 + 4) = 0xb;
      }
      else {
        puVar5 = (undefined2 *)param_1[0x62];
        ZeroMemory(puVar5,0x80);
        *(undefined1 *)((longlong)puVar5 + 3) = 1;
        *puVar5 = 0xada0;
        *(undefined8 *)(puVar5 + 8) = param_1[0x61];
        *(undefined4 *)(puVar5 + 0xc) = 0x58;
        *(undefined1 *)((longlong)puVar5 + 0x1f) = 8;
        uVar14 = AdminQueueRequestPostPollReply
                           ((longlong)param_1,puVar5,-0x5260,*(ushort *)(param_1 + 0x116),0,
                            &local_1068);
        if ((char)uVar14 != '\0') {
          if ((*(char *)(param_1 + 0x180) != '\0') &&
             ((*(uint *)((longlong)param_1 + 0xc04) & 0x11d) != 0)) {
            RttLogEvent((longlong)param_1,plVar2,0x11d,(undefined1 *)0x0,0,0,&local_1068);
          }
          uVar14 = ProcessIOCFactsData((longlong)param_1,0,&local_1068);
          if ((char)uVar14 == '\0') goto LAB_14000568f;
          if (*(char *)((longlong)param_1 + 0x395) == '\0') {
            LogSystemEvent((longlong)param_1,0,0xc004af02,
                           (byte *)"INIT Failed: Adapter is not a SCSI initiator",0,&local_1068);
            *(undefined4 *)(param_1 + 4) = 4;
          }
          else if ((*(char *)(param_1 + 0x81) != '\0') ||
                  (uVar15 = PerformMemoryAllocations((longlong)param_1,0,&local_1068),
                  (char)uVar15 != '\0')) {
            uVar25 = *(ushort *)(param_1 + 0x6d);
            lVar12 = param_1[0x13e];
            uVar24 = uVar25;
            if (*(char *)(param_1 + 0x81) == '\0') {
              uVar24 = uVar25 + 6;
            }
            ZeroMemory((void *)param_1[0x13f],(uint)*(ushort *)((longlong)param_1 + 0x372) * 0x18);
            ZeroMemory((void *)param_1[0x140],(uint)*(ushort *)((longlong)param_1 + 0x372) << 3);
            uVar17 = 0;
            piVar23 = (int *)param_1[0x13d];
            if (uVar25 != 0) {
              do {
                uVar27 = (uint)uVar17;
                uVar17 = uVar17 + 1;
                *piVar23 = uVar27 + 1;
                piVar23 = piVar23 + 1;
              } while (uVar17 < uVar25);
            }
            *(undefined4 *)((longlong)param_1 + 0xaec) = 0;
            uVar17 = 0;
            *(undefined4 *)(param_1 + 0x15d) = 0;
            *(uint *)(param_1 + 0x15e) = (uint)uVar25;
            if (uVar24 != 0) {
              puVar16 = (undefined1 *)(lVar12 + 10);
              do {
                *(ushort *)(puVar16 + -2) = uVar17;
                uVar17 = uVar17 + 1;
                *(undefined8 *)(puVar16 + -10) = 0;
                *puVar16 = 0;
                *(undefined4 *)(puVar16 + 6) = 0;
                puVar16 = puVar16 + 0x18;
              } while (uVar17 < uVar24);
            }
            ZeroMemory((void *)param_1[0x13c],0x100);
            if (*(char *)(param_1 + 0x81) == '\0') {
              ZeroMemory((void *)param_1[0x142],(*(ushort *)((longlong)param_1 + 0x376) + 1) * 0x20)
              ;
              ZeroMemory((void *)param_1[0x143],(*(ushort *)(param_1 + 0x6f) + 1) * 0x18);
              if (*(char *)((longlong)param_1 + 0x411) == '\0') {
                ZeroMemory((void *)*plVar2,*(uint *)(param_1 + 0x17f));
                ZeroMemory((void *)param_1[0x15f],0x1400);
                ZeroMemory((void *)param_1[0x16e],(uint)*(ushort *)((longlong)param_1 + 0x3c4) << 2)
                ;
              }
              if (*(char *)(param_1 + 0x81) == '\0') {
                RttInitTrace((longlong)param_1,plVar2,0,&local_1068);
              }
            }
            InitSysLogErrorFIFO((longlong)param_1);
            LogSystemEvent((longlong)param_1,0,0x8004af01,
                           (byte *)"Current mpi3drv driver lacks full performance.  Please upgrade."
                           ,0,&local_1068);
            LitInit((longlong)param_1,0,&local_1068);
            if ((*(char *)(param_1 + 0x81) == '\0') &&
               (uVar14 = GetNumaNodeData((longlong)param_1,0,&local_1068), (char)uVar14 == '\0')) {
              LogSystemEvent((longlong)param_1,0,0xc004af02,
                             (byte *)"INIT:  Failed to get NUMA node information, disable NUMA",0,
                             &local_1068);
              *(undefined2 *)((longlong)param_1 + 0x3c2) = 0x100;
            }
            uVar14 = (ulonglong)*(ushort *)(param_1 + 0x6c);
            uVar25 = *(ushort *)(param_1 + 0x6e);
            uVar27 = (uint)*(ushort *)(param_1 + 0x6c);
            plVar21 = (longlong *)param_1[0x14b];
            lVar12 = param_1[0x149];
            if (uVar27 != 0) {
              do {
                *plVar21 = lVar12;
                plVar21 = plVar21 + 1;
                lVar12 = lVar12 + (ulonglong)uVar25;
                uVar14 = uVar14 - 1;
              } while (uVar14 != 0);
            }
            *plVar21 = 0;
            *(uint *)(param_1 + 0x151) = uVar27;
            *(uint *)param_1[0x1b] = uVar27;
            LOCK();
            UNLOCK();
            plVar21 = (longlong *)param_1[0x14f];
            lVar12 = param_1[0x14e];
            *(uint *)(param_1 + 0x151) = uVar27;
            uVar14 = (ulonglong)*(ushort *)((longlong)param_1 + 0x364);
            uVar27 = (uint)*(ushort *)((longlong)param_1 + 0x364);
            if (uVar27 != 0) {
              do {
                *plVar21 = lVar12;
                plVar21 = plVar21 + 1;
                lVar12 = lVar12 + 0x100;
                uVar14 = uVar14 - 1;
              } while (uVar14 != 0);
            }
            *plVar21 = 0;
            *(uint *)((longlong)param_1 + 0xa8c) = uVar27;
            *(uint *)param_1[0x1c] = uVar27;
            LOCK();
            UNLOCK();
            *(uint *)((longlong)param_1 + 0xa8c) = uVar27;
            *(undefined1 *)(param_5 + 0x92) = 0xff;
            uVar11 = 0x10;
            if (*(char *)(param_1 + 0x81) == '\0') {
              uVar11 = 300;
            }
            *(undefined4 *)(param_5 + 0xcc) = uVar11;
            *(undefined4 *)(param_5 + 0xd8) = 0;
            *(undefined1 *)(param_5 + 0x61) = 0x80;
            *(undefined1 *)(param_5 + 0x54) = 0;
            *(undefined1 *)(param_5 + 0x48) = *(undefined1 *)((longlong)param_1 + 0x374);
            *(code **)(param_5 + 0x98) = mpi3MSIIsr;
            *(undefined1 *)(param_5 + 0x91) = 1;
            *(undefined4 *)(param_5 + 0x94) = 1;
            *(undefined4 *)(param_5 + 0xa0) = 2;
            if (*(char *)(param_1 + 0x81) == '\0') {
              mpi3WmiInitialize((longlong)param_1);
              *(uint *)(param_1 + 0x12f) = uVar29;
            }
            puVar5 = (undefined2 *)param_1[0x62];
            ZeroMemory(puVar5,0x80);
            *(undefined1 *)((longlong)puVar5 + 3) = 2;
            *puVar5 = 0xada0;
            *(undefined4 *)(puVar5 + 6) = 0x3000012;
            StorPortQuerySystemTime(local_1058);
            local_1058[0] = (local_1058[0] + -0x19db1ded53e8000) / 10000;
            *(longlong *)(puVar5 + 8) = local_1058[0];
            *(undefined1 *)((longlong)puVar5 + 0x19) = 3;
            puVar5[0xe] = *(undefined2 *)((longlong)param_1 + 0x362);
            *(undefined8 *)(puVar5 + 0x10) = param_1[0x14c];
            puVar5[0x16] = *(undefined2 *)((longlong)param_1 + 0x366);
            puVar5[0x17] = 0x100;
            *(undefined8 *)(puVar5 + 0x18) = param_1[0x150];
            memmove((void *)param_1[99],&DAT_140014000,0x78);
            *(undefined8 *)(puVar5 + 0x1c) = param_1[0x5e];
            uVar14 = AdminQueueRequestPostPollReply
                               ((longlong)param_1,(void *)param_1[0x62],-0x5260,
                                *(ushort *)(param_1 + 0x116),0,&local_1068);
            if ((char)uVar14 == '\0') {
              LogSystemEvent((longlong)param_1,0,0xc004af02,
                             (byte *)"INIT Failed: MPI_LOG_IOCINIT Failed",0,&local_1068);
              *(undefined4 *)(param_1 + 4) = 6;
            }
            else {
              param_1[0x112] = 0;
              *(undefined4 *)((longlong)param_1 + 0x424) = 0;
              *(undefined2 *)(param_1 + 0x114) = 600;
              *(undefined4 *)(param_1 + 0x11a) = 1;
              ReadWriteConfigPages((longlong)param_1,2,0,&local_1068);
              puVar5 = (undefined2 *)param_1[0x62];
              ZeroMemory(puVar5,0x80);
              *puVar5 = 0xada0;
              *(undefined1 *)((longlong)puVar5 + 3) = 4;
              uVar14 = AdminQueueRequestPostPollReply
                                 ((longlong)param_1,puVar5,-0x5260,*(ushort *)(param_1 + 0x116),0,
                                  &local_1068);
              if ((char)uVar14 == '\0') {
                LogSystemEvent((longlong)param_1,0,0xc004af02,
                               (byte *)"INIT Failed: Failed to Enabled Events",0,&local_1068);
                *(undefined4 *)(param_1 + 4) = 7;
              }
              else {
                puVar5 = (undefined2 *)param_1[0x62];
                ZeroMemory(puVar5,0x80);
                *(undefined1 *)((longlong)puVar5 + 3) = 3;
                *puVar5 = 0xada1;
                *(undefined1 *)((longlong)param_1 + 0x412) = 1;
                AdminQueueRequestPostPollReply((longlong)param_1,puVar5,-0x525f,18000,0,&local_1068)
                ;
                uVar25 = 0;
                do {
                  Poll_mpi3Isr((longlong)param_1,2,&local_1068);
                  if (*(char *)((longlong)param_1 + 0x412) == '\0') goto LAB_14000642f;
                  lVar12 = 100;
                  do {
                    StorPortStallExecution(1000);
                    lVar12 = lVar12 + -1;
                  } while (lVar12 != 0);
                  uVar25 = uVar25 + 1;
                } while (uVar25 < 18000);
                if (uVar25 == 18000) {
                  LogSystemEvent((longlong)param_1,0,0xc004af02,
                                 (byte *)"INIT Failed: Port Enabled failed due to timeout",0,
                                 &local_1068);
                  *(undefined4 *)(param_1 + 4) = 0x12;
                  goto LAB_14000568f;
                }
LAB_14000642f:
                if (*(char *)((longlong)param_1 + 0x413) != '\0') {
                  do {
                    uVar25 = 0;
                    while( true ) {
                      if (0x13 < uVar25) {
                        InitTimerRoutine((longlong)param_1);
                        do {
                          LOCK();
                          bVar30 = *(int *)(param_1 + 0xf1) == 0;
                          if (bVar30) {
                            *(int *)(param_1 + 0xf1) = 1;
                          }
                          UNLOCK();
                        } while (!bVar30);
                        *(undefined2 *)((longlong)param_1 + 0x781) = 0;
                        *(undefined1 *)(param_1 + 0xf0) = 0;
                        *(undefined2 *)((longlong)param_1 + 0x784) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x78c) = 0;
                        *(undefined4 *)(param_1 + 0xf2) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x794) = 0;
                        *(undefined4 *)(param_1 + 0xf3) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x79c) = 0;
                        *(undefined4 *)(param_1 + 0xf4) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7a4) = 0;
                        *(undefined4 *)(param_1 + 0xf5) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7ac) = 0;
                        *(undefined4 *)(param_1 + 0xf6) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7b4) = 0;
                        *(undefined4 *)(param_1 + 0xf7) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7bc) = 0;
                        *(undefined4 *)(param_1 + 0xf8) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7c4) = 0;
                        *(undefined4 *)(param_1 + 0xf9) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7cc) = 0;
                        *(undefined4 *)(param_1 + 0xfa) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7d4) = 0;
                        *(undefined4 *)(param_1 + 0xfb) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7dc) = 0;
                        *(undefined4 *)(param_1 + 0xfc) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7e4) = 0;
                        *(undefined4 *)(param_1 + 0xfd) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7ec) = 0;
                        *(undefined4 *)(param_1 + 0xfe) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7f4) = 0;
                        *(undefined4 *)(param_1 + 0xff) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x7fc) = 0;
                        *(undefined4 *)(param_1 + 0x100) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x804) = 0;
                        *(undefined4 *)(param_1 + 0x101) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x80c) = 0;
                        *(undefined4 *)(param_1 + 0x102) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x814) = 0;
                        *(undefined4 *)(param_1 + 0x103) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x81c) = 0;
                        *(undefined4 *)(param_1 + 0x104) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x824) = 0;
                        *(undefined4 *)(param_1 + 0x105) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x82c) = 0;
                        *(undefined4 *)(param_1 + 0x106) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x834) = 0;
                        *(undefined4 *)(param_1 + 0x107) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x83c) = 0;
                        *(undefined4 *)(param_1 + 0x108) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x844) = 0;
                        *(undefined4 *)(param_1 + 0x109) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x84c) = 0;
                        *(undefined4 *)(param_1 + 0x10a) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x854) = 0;
                        *(undefined4 *)(param_1 + 0x10b) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x85c) = 0;
                        *(undefined4 *)(param_1 + 0x10c) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x864) = 0;
                        *(undefined4 *)(param_1 + 0x10d) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x86c) = 0;
                        *(undefined4 *)(param_1 + 0x10e) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x874) = 0;
                        *(undefined4 *)(param_1 + 0x10f) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x87c) = 0;
                        *(undefined4 *)(param_1 + 0x110) = 0;
                        *(undefined1 *)((longlong)param_1 + 0x884) = 0;
                        *(undefined4 *)(param_1 + 0x111) = 0;
                        LOCK();
                        *(int *)(param_1 + 0xf1) = *(int *)(param_1 + 0xf1) + -1;
                        UNLOCK();
                        *(undefined1 *)(param_1 + 0x87) = 0;
                        if ((*(char *)(param_1 + 0x180) != '\0') &&
                           ((*(uint *)((longlong)param_1 + 0xc04) & 0x400) != 0)) {
                          RttLogEvent((longlong)param_1,plVar2,0x400,(undefined1 *)0x0,0,0,
                                      &local_1068);
                        }
                        return 1;
                      }
                      cVar9 = Poll_mpi3Isr((longlong)param_1,2,&local_1068);
                      if (cVar9 != '\0') break;
                      lVar12 = 100;
                      do {
                        StorPortStallExecution(1000);
                        lVar12 = lVar12 + -1;
                      } while (lVar12 != 0);
                      uVar25 = uVar25 + 1;
                    }
                  } while( true );
                }
                LogSystemEvent((longlong)param_1,0,0xc004af02,
                               (byte *)"INIT Failed: Port Enable Failed",0,&local_1068);
                *(undefined4 *)(param_1 + 4) = 0x13;
              }
            }
          }
        }
      }
      goto LAB_14000568f;
    }
    pcVar28 = "INIT Fail: Failed to get fixed memory";
  }
  LogSystemEvent((longlong)param_1,0,0xc004af02,(byte *)pcVar28,0,&local_1068);
  goto LAB_14000568f;
}



===== mpi3HWInitialize @ 140006900 =====

void mpi3HWInitialize(longlong param_1)

{
  int local_res8;
  undefined1 local_resc;
  
  local_res8 = 0x10;
  local_resc = 1;
  Internalmpi3HWInitialize(param_1,0,&local_res8);
  *(undefined1 *)(param_1 + 0x416) = 0;
  return;
}



===== mpi3OSBusReset @ 140006930 =====

undefined8 mpi3OSBusReset(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  int local_res8;
  undefined1 local_resc;
  
  local_res8 = 10;
  local_resc = 0;
  uVar1 = GetPendingIOCount(param_1);
  if (*(int *)(param_1 + 0x41c) != 0) {
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x27d) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x27d,(undefined1 *)0x0,0,0,&local_res8);
    }
    uVar2 = LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                                "Bus Reset Backout (OS) - Adapter already Stopped",0,&local_res8);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if (*(char *)(param_1 + 0x417) != '\0') {
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x27e) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x27e,(undefined1 *)0x0,0,0,&local_res8);
    }
    uVar2 = LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                                "Bus Reset Backout (OS) - Adapter Gone, already killed",0,
                                &local_res8);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if (*(int *)(param_1 + 0x428) != 0) {
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x27f) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x27f,(undefined1 *)(param_1 + 0x8c4),4,0,
                  &local_res8);
    }
    uVar2 = LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                                "Bus Reset Backout (OS) - Reset Already Active",0,&local_res8);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if ((short)uVar1 == 0) {
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x280) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x280,(undefined1 *)0x0,0,0,&local_res8);
    }
    uVar2 = LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                                "Bus Reset Backout (OS) - No IOs pending at FW",0,&local_res8);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if (*(char *)(param_1 + 0x421) == '\0') {
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x20013) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x20013,(undefined1 *)0x0,0,0,&local_res8);
    }
    LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,"Bus Reset (OS) - Bus Reset from OS Started"
                        ,0,&local_res8);
    *(undefined4 *)(param_1 + 0x428) = 1;
    *(undefined1 *)(param_1 + 0x421) = 1;
    *(undefined4 *)(param_1 + 0x8a4) = 1;
    *(undefined4 *)(param_1 + 0x8c4) = 1;
    uVar2 = StartAdapterReset(param_1,0x100,0,&local_res8);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x281) != 0)) {
    RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x281,(undefined1 *)0x0,0,0,&local_res8);
  }
  uVar2 = LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,
                              "Bus Reset Backout (OS) - 3 Minute Wait Timer Still Active",0,
                              &local_res8);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== mpi3PassiveInitialization @ 140006cb0 =====

undefined8 mpi3PassiveInitialization(longlong param_1)

{
  undefined8 uVar1;
  undefined4 local_res8 [2];
  int local_res10;
  undefined1 local_res14;
  
  local_res10 = 0x11;
  local_res14 = 1;
  uVar1 = CreateOperationalQueues(param_1,0,&local_res10);
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  StorPortNotification(0x1001,param_1,param_1 + 0xb20,SystemEventLoggerDpc);
  local_res8[0] = 0;
  uVar1 = StorPortNotification(0x1002,param_1,param_1 + 0xb20,param_1,param_1,local_res8);
  *(undefined1 *)(param_1 + 0x411) = 1;
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== Poll_mpi3Isr @ 140006d40 =====

void Poll_mpi3Isr(longlong param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = *param_3;
  *(undefined4 *)(param_1 + 0x434) = param_2;
  *(undefined4 *)(param_1 + 0xb6c) = uVar1;
  mpi3MSIIsr(param_1,0);
  *(undefined4 *)(param_1 + 0x434) = 0;
  *(undefined4 *)(param_1 + 0xb6c) = 0xc;
  return;
}



===== PostFreeReplyFrame @ 140006d80 =====

void PostFreeReplyFrame(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  do {
    uVar1 = *(uint *)(param_1 + 0xa88);
    uVar2 = 0;
    if (uVar1 + 1 != (uint)*(ushort *)(param_1 + 0x362)) {
      uVar2 = uVar1 + 1;
    }
    LOCK();
    bVar3 = uVar1 == *(uint *)(param_1 + 0xa88);
    if (bVar3) {
      *(uint *)(param_1 + 0xa88) = uVar2;
    }
    UNLOCK();
  } while (!bVar3);
  *(undefined8 *)(*(longlong *)(param_1 + 0xa58) + (ulonglong)uVar1 * 8) = *param_2;
  **(undefined4 **)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 0xa88);
  LOCK();
  UNLOCK();
  return;
}



===== ProcessAdminReplyDescriptor @ 140006de0 =====

/* WARNING: Type propagation algorithm not settling */

void ProcessAdminReplyDescriptor(longlong param_1,ushort *param_2,ushort param_3,int *param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  ushort uVar5;
  ushort *puVar6;
  undefined1 uVar7;
  ushort *_Src;
  short sVar8;
  bool bVar9;
  char local_res8;
  char local_res10;
  undefined4 local_48;
  uint local_44;
  
  uVar5 = param_2[7] & 0xf000;
  local_44 = (uint)uVar5;
  bVar4 = false;
  local_res8 = '\0';
  _Src = (ushort *)0x0;
  if (uVar5 == 0) {
    puVar6 = (ushort *)(*(longlong *)(param_1 + 0xa50) + *(longlong *)param_2);
    local_res8 = *(char *)((longlong)puVar6 + 3);
    switch(local_res8) {
    case '\x04':
      HandleEventNotification(param_1,(longlong)puVar6,param_3,param_4);
      goto LAB_1400070f9;
    default:
      if (*puVar6 != 0xadb0) {
        local_48._2_2_ = *puVar6;
        local_48._0_1_ = local_res8;
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x28c) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x28c,(undefined1 *)&local_48,4,param_3,
                      param_4);
        }
        LogOperationalEvent(param_1,&local_48,4,0xc004af02,
                            "Kill Adapter (Driver) - Bad IOCTL Address-Reply (saved Function & Host Tag)"
                            ,param_3,param_4);
        **(undefined4 **)(param_1 + 0xc0) = *(undefined4 *)param_2;
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 200) = CONCAT22(param_2[4],param_2[5]);
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0xd0) = CONCAT22(param_2[6],param_2[7]);
        LOCK();
        UNLOCK();
        KillAdapter(param_1,0x16,param_3,param_4);
        goto LAB_1400070f9;
      }
      break;
    case '\b':
      if (*puVar6 != 0xadb0) {
        if (*puVar6 == 0xadb2) {
          *(undefined1 *)(param_1 + 0x88c) = 0;
          ProcessDeviceRemoval(param_1,param_3,param_4);
        }
        goto LAB_1400070f9;
      }
      break;
    case '\t':
      uVar5 = *puVar6;
      if (uVar5 == 0xada5) {
        if ((puVar6[5] == 0) &&
           (*(undefined4 *)(param_1 + 0x9a0) =
                 *(undefined4 *)(*(longlong *)(param_1 + 0x990) + 0x48),
           *(char *)(param_1 + 0x9a4) == '\0')) {
          PELWait(param_1,param_3,param_4);
        }
        goto LAB_1400070f9;
      }
      if (uVar5 == 0xada6) {
        *(undefined1 *)(param_1 + 0x9a4) = 0;
        if (puVar6[5] == 0) {
          if (*(char *)(param_1 + 0x988) != '\0') {
            ScsiPortWmiFireLogicalUnitEvent
                      (param_1,-1,0,0,(int *)&DAT_140014078,0,0x10,(int *)(param_1 + 0x938));
          }
          PELGetSetSeqNumbers(param_1,param_3,param_4);
        }
        goto LAB_1400070f9;
      }
      if (uVar5 != 0xadb0) goto LAB_1400070f9;
      break;
    case '!':
      if (puVar6[5] == 0) {
        uVar7 = 1;
        if ((puVar6[10] & 0xf7) != 0) {
          uVar7 = 4;
        }
      }
      else {
        uVar7 = 4;
      }
      uVar5 = *puVar6;
      if (uVar5 == 0xadb0) {
        bVar4 = true;
        *(undefined1 *)(*(longlong *)(param_1 + 0x448) + 3) = 1;
        ResumeController(param_1,1,param_3,param_4);
        *(undefined4 *)(param_1 + 0x428) = 0;
      }
      else if (uVar5 == 0xadb1) {
        *(undefined1 *)(*(longlong *)(param_1 + 0x450) + 3) = uVar7;
        StorPortNotification(0,param_1);
        *(undefined8 *)(param_1 + 0x450) = 0;
        CheckTMQueue(param_1,param_3,param_4);
        puVar6 = _Src;
        if (*(short *)(param_1 + 0x88e) != 0) {
          ProcessDeviceRemoval(param_1,param_3,param_4);
        }
      }
      else {
        if (uVar5 != 0xadb2) {
          if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x28d) != 0)) {
            RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x28d,(undefined1 *)puVar6,2,param_3,
                        param_4);
          }
          LogOperationalEvent(param_1,(int *)puVar6,2,0xc004af02,
                              "Kill Adapter (Driver) - TM completed with Host Tag not used (Host Tag)"
                              ,param_3,param_4);
          KillAdapter(param_1,0x12,param_3,param_4);
          return;
        }
        *(undefined1 *)(param_1 + 0x88c) = 0;
        ProcessDeviceRemoval(param_1,param_3,param_4);
        puVar6 = _Src;
      }
      goto LAB_1400070f1;
    }
    bVar4 = true;
LAB_1400070f1:
    local_res10 = '\x02';
    _Src = puVar6;
  }
  else {
    if (uVar5 == 0x1000) {
      if (param_2[6] == 0xadb0) {
        bVar4 = true;
        *param_2 = 0;
        local_res10 = '\x01';
        _Src = param_2;
      }
      else {
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x28e) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x28e,(undefined1 *)(param_2 + 6),2,
                      param_3,param_4);
        }
        LogOperationalEvent(param_1,(int *)(param_2 + 6),2,0xc004af02,
                            "Kill Adapter (Driver) - Incorrect completion IOCTL in SuccessDesc (Host Tag saved)"
                            ,param_3,param_4);
        **(undefined4 **)(param_1 + 0xc0) = *(undefined4 *)param_2;
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 200) = CONCAT22(param_2[4],param_2[5]);
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0xd0) = CONCAT22(param_2[6],param_2[7]);
        LOCK();
        UNLOCK();
        KillAdapter(param_1,0x17,param_3,param_4);
      }
      goto LAB_1400070f9;
    }
    if (uVar5 != 0x3000) {
      LogSystemEvent(param_1,0,0xc004af02,(byte *)"Invalid reply type",param_3,param_4);
      goto switchD_140006e99_caseD_ada5;
    }
    uVar5 = *param_2 & 0x7fff;
    switch(param_2[6]) {
    case 0xada1:
      *(bool *)(param_1 + 0x413) = uVar5 == 0;
      *(undefined1 *)(param_1 + 0x412) = 0;
      break;
    case 0xada2:
      *(bool *)(param_1 + 0x415) = uVar5 == 0;
      *(undefined1 *)(param_1 + 0x414) = 0;
      break;
    case 0xada3:
      if (uVar5 == 0) {
        *(undefined4 *)(param_1 + 0x8d0) = 4;
        break;
      }
      *(undefined4 *)(param_1 + 0x8d0) = 5;
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x295) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x295,(undefined1 *)param_2,2,param_3,
                    param_4);
        break;
      }
    default:
switchD_140006e99_caseD_ada5:
      break;
    case 0xada4:
      *(undefined1 *)(param_1 + 0x9a5) = 0;
      break;
    case 0xadb0:
      bVar4 = true;
      local_res10 = '\x01';
      _Src = param_2;
      break;
    case 0xadb4:
      do {
        LOCK();
        bVar9 = *(int *)(param_1 + 0x788) == 0;
        if (bVar9) {
          *(int *)(param_1 + 0x788) = 1;
        }
        UNLOCK();
      } while (!bVar9);
      *(undefined1 *)(param_1 + 0x782) = 0;
      LOCK();
      *(int *)(param_1 + 0x788) = *(int *)(param_1 + 0x788) + -1;
      UNLOCK();
    }
  }
LAB_1400070f9:
  if (param_2[5] != 0xffff) {
    if (bVar4) {
      lVar1 = *(longlong *)(param_1 + 0x448);
      lVar2 = *(longlong *)(lVar1 + 0x68);
      lVar3 = *(longlong *)(lVar1 + 0x40);
      if (local_res10 == '\x01') {
        local_res8 = *(char *)(lVar2 + 99);
      }
      if (3 < *(uint *)(lVar2 + 0x58)) {
        *(char *)(lVar3 + 0x1c) = local_res10;
        memmove((void *)(lVar3 + 0x20),_Src,(ulonglong)(*(int *)(lVar2 + 0x58) - 4));
      }
      sVar8 = (short)local_44;
      if ((sVar8 == 0) && (local_res8 == ' ')) {
        ProcessScsiErrorReply(param_1,(short *)_Src,(longlong *)0x0,param_3,param_4);
      }
      *(undefined1 *)(lVar1 + 3) = 1;
      StorPortNotification(0,param_1,*(undefined8 *)(param_1 + 0x448));
      *(undefined4 *)(param_1 + 0x43c) = 0;
      *(undefined8 *)(param_1 + 0x448) = 0;
    }
    else {
      sVar8 = (short)local_44;
    }
    if (sVar8 == 0) {
      PostFreeReplyFrame(param_1,(undefined8 *)param_2);
    }
  }
  return;
}



===== ProcessScsiErrorReply @ 1400075f0 =====

void ProcessScsiErrorReply
               (longlong param_1,short *param_2,longlong *param_3,ushort param_4,int *param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  char *_Src;
  longlong lVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  uint uVar8;
  bool bVar9;
  int local_res10 [2];
  char local_78;
  ushort local_74 [2];
  short local_70 [2];
  int local_6c;
  undefined4 local_68;
  uint local_64;
  undefined4 local_60 [2];
  longlong local_58;
  longlong local_50;
  longlong local_48;
  
  local_res10[0]._0_1_ = *(char *)((longlong)param_2 + 3);
  local_70[0] = *param_2;
  local_6c = 0;
  local_48 = 0;
  if ((char)local_res10[0] != ' ') {
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x28b) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x28b,(undefined1 *)local_res10,1,param_4,
                  param_5);
    }
    LogOperationalEvent(param_1,local_res10,1,0xc004af02,
                        "Kill Adapter (Driver) - Invalid Function in MPI SCSI Reply (saved Function)"
                        ,param_4,param_5);
    KillAdapter(param_1,0x14,param_4,param_5);
    return;
  }
  if (local_70[0] == -0x5250) {
    lVar4 = *(longlong *)(param_1 + 0x448);
    uVar7 = 0xfe;
    uVar5 = 0xfe;
    local_78 = -2;
    uVar6 = 0xfe;
    local_58 = 0;
    local_50 = *(longlong *)(lVar4 + 0x68);
    local_48 = *(longlong *)(lVar4 + 0x40) + 0x1c;
  }
  else {
    if (param_3 == (longlong *)0x0) {
      KillAdapter(param_1,0x15,param_4,param_5);
      return;
    }
    lVar4 = *param_3;
    if (lVar4 == 0) {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x219) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x219,(undefined1 *)local_70,2,param_4,
                    param_5);
      }
      LogSystemEvent(param_1,0,0xc004af02,(byte *)"NULL SRB",param_4,param_5);
      return;
    }
    local_50 = *(longlong *)(lVar4 + 0x68);
    local_78 = *(char *)(local_50 + 0x48);
    local_58 = *(longlong *)(local_50 + 0x30);
    uVar7 = *(undefined1 *)(local_50 + 0x4a);
    uVar5 = *(undefined1 *)(local_50 + 0x4b);
    uVar6 = *(undefined1 *)(local_50 + 0x4c);
  }
  local_74[0] = param_2[5] & 0x7fff;
  if (param_2[5] < 0) {
    local_6c = *(int *)(param_2 + 6);
    LitLogInfoReceived(param_1,local_6c,param_2[9],uVar7,uVar5,uVar6,param_4,param_5);
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x238) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x238,(undefined1 *)&local_6c,4,param_4,
                  param_5);
    }
  }
  bVar1 = *(byte *)(param_2 + 8);
  switch(local_74[0]) {
  case 0:
  case 0x40:
    *(undefined1 *)(lVar4 + 3) = 1;
    goto LAB_1400078a8;
  case 1:
    *(undefined1 *)(lVar4 + 3) = 6;
    goto LAB_1400078a8;
  case 2:
  case 0x49:
    *(undefined1 *)(lVar4 + 3) = 5;
    uVar8 = 8;
    break;
  case 3:
  case 6:
  case 7:
  case 0x46:
  case 0x47:
  case 0x4a:
    *(undefined1 *)(lVar4 + 3) = 4;
    if (*(char *)(param_1 + 0xc00) == '\0') goto LAB_1400078a8;
    if ((*(uint *)(param_1 + 0xc04) & 0x227) == 0) goto LAB_140007a35;
    RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x227,(undefined1 *)local_74,2,param_4,param_5
               );
    uVar8 = (uint)bVar1;
    break;
  default:
    *(undefined1 *)(lVar4 + 3) = 4;
    if (*(char *)(param_1 + 0xc00) == '\0') goto LAB_1400078a8;
    if ((*(uint *)(param_1 + 0xc04) & 0x228) == 0) goto LAB_140007a35;
    RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x228,(undefined1 *)local_74,2,param_4,param_5
               );
    uVar8 = (uint)bVar1;
    break;
  case 0x42:
    *(undefined1 *)(lVar4 + 3) = 0x21;
    goto LAB_1400078a8;
  case 0x43:
    *(undefined1 *)(lVar4 + 3) = 10;
    goto LAB_1400078a8;
  case 0x44:
    *(undefined1 *)(lVar4 + 3) = 0x12;
    goto LAB_1400078a8;
  case 0x45:
    uVar8 = (uint)bVar1;
    if (local_70[0] == -0x5250) {
      *(undefined1 *)(lVar4 + 3) = 1;
    }
    else if (((bVar1 - 8 & 0xdf) != 0) && (*(int *)(param_2 + 0xc) == 0)) {
      *(undefined1 *)(lVar4 + 3) = 0x12;
      *(undefined4 *)(lVar4 + 0x3c) = *(undefined4 *)(param_2 + 10);
    }
    break;
  case 0x48:
    *(undefined1 *)(lVar4 + 3) = 5;
    if (*(char *)(param_1 + 0xc00) == '\0') goto LAB_1400078a8;
    if ((*(uint *)(param_1 + 0xc04) & 0x224) != 0) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x224,(undefined1 *)0x0,0,param_4,param_5);
    }
LAB_140007a35:
    uVar8 = (uint)bVar1;
    break;
  case 0x4b:
    *(undefined1 *)(lVar4 + 3) = 5;
    if (local_6c != 0x31170000) goto LAB_140007a35;
    uVar8 = 8;
    break;
  case 0x4c:
    *(undefined1 *)(lVar4 + 3) = 5;
LAB_1400078a8:
    uVar8 = (uint)bVar1;
    break;
  case 0x4d:
  case 0x4e:
  case 0x4f:
    *(undefined1 *)(lVar4 + 3) = 0xf;
    local_68._0_3_ = CONCAT12(uVar6,CONCAT11(uVar5,uVar7));
    local_64 = (uint)local_74[0];
    LogSystemEvent(param_1,local_68,0xc004af02,(byte *)"EEDP DIF error detected",param_4,param_5);
    if ((*(char *)(param_1 + 0xc00) == '\0') || ((*(uint *)(param_1 + 0xc04) & 0x226) == 0))
    goto LAB_140007a35;
    RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x226,(undefined1 *)&local_68,8,param_4,
                param_5);
    uVar8 = (uint)bVar1;
  }
  uVar7 = (undefined1)uVar8;
  uVar3 = *(uint *)(param_2 + 0xc);
  bVar1 = *(byte *)((longlong)param_2 + 0x11) & 3;
  if (((uVar3 == 0) || (*(longlong *)(param_2 + 0x18) == 0)) || (bVar1 != 0)) {
    if ((byte)(bVar1 - 1) < 2) {
      *(undefined1 *)(lVar4 + 3) = 4;
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x229) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x229,(undefined1 *)0x0,0,param_4,param_5)
        ;
      }
    }
    else if ((((*(byte *)((longlong)param_2 + 0x11) & 0x10) != 0) &&
             (*(char *)(lVar4 + 3) == '\x01')) && (*(int *)(param_2 + 0xe) != 0)) {
      *(undefined1 *)(lVar4 + 3) = 4;
      uVar7 = 0;
      goto LAB_140007cf5;
    }
  }
  else {
    _Src = (char *)(*(longlong *)(param_1 + 0xa50) + *(longlong *)(param_2 + 0x18));
    if ((*(uint *)(lVar4 + 0x18) & 0x20) == 0) {
      if (((local_78 != -0x7b) && (local_78 != -0x5f)) && ((byte)(*_Src + 0x90U) < 2)) {
        bVar1 = _Src[7];
        if (0xf4 < bVar1) {
          _Src[7] = -0xc;
          bVar1 = 0xf4;
        }
        uVar3 = bVar1 + 8;
      }
      if (local_70[0] == -0x5250) {
        uVar2 = *(uint *)(local_50 + 0x54);
        *(byte *)(lVar4 + 3) = *(byte *)(lVar4 + 3) | 0x80;
        if (uVar3 <= uVar2) {
          uVar2 = uVar3;
        }
        memmove((void *)((ulonglong)*(uint *)(local_50 + 0x58) + local_48),_Src,(ulonglong)uVar2);
      }
      else if (local_58 == 0) {
        local_60[0] = 2;
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x29f) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x29f,(undefined1 *)local_60,4,param_4,
                      param_5);
        }
      }
      else {
        if (uVar3 < *(byte *)(local_58 + 9)) {
          *(char *)(local_58 + 9) = (char)uVar3;
        }
        *(undefined1 *)(lVar4 + 3) = 0x84;
        memmove(*(void **)(local_58 + 0x10),_Src,(ulonglong)*(byte *)(local_58 + 9));
      }
    }
    else {
      memmove(*(void **)(param_1 + 0xae0),_Src,0xff);
      *(undefined1 *)(param_1 + 0xad8) = 1;
      *(undefined1 *)(lVar4 + 3) = 4;
    }
    do {
      uVar3 = *(uint *)(param_1 + 0xa8c);
      uVar2 = 0;
      if (uVar3 + 1 != (uint)*(ushort *)(param_1 + 0x366)) {
        uVar2 = uVar3 + 1;
      }
      LOCK();
      bVar9 = uVar3 == *(uint *)(param_1 + 0xa8c);
      if (bVar9) {
        *(uint *)(param_1 + 0xa8c) = uVar2;
      }
      UNLOCK();
    } while (!bVar9);
    *(undefined8 *)(*(longlong *)(param_1 + 0xa78) + (ulonglong)uVar3 * 8) =
         *(undefined8 *)(param_2 + 0x18);
    **(undefined4 **)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xa8c);
    LOCK();
    UNLOCK();
  }
  if (((byte)(uVar8 - 0x18) < 0x29) &&
     ((0x10000000401U >> ((ulonglong)(uVar8 - 0x18) & 0x3f) & 1) != 0)) {
    *(undefined1 *)(lVar4 + 3) = 4;
  }
  else if ((uVar8 - 8 & 0xdf) == 0) {
    *(undefined1 *)(lVar4 + 3) = 5;
  }
LAB_140007cf5:
  if (local_70[0] != -0x5250) {
    if (local_58 != 0) {
      *(undefined1 *)(local_58 + 8) = uVar7;
    }
    LOCK();
    *(int *)(param_1 + 0x8e8) = *(int *)(param_1 + 0x8e8) + -1;
    UNLOCK();
    StorPortNotification(0,param_1,lVar4);
  }
  return;
}



===== mpi3Isr @ 140007dd0 =====

void mpi3Isr(longlong param_1)

{
  mpi3MSIIsr(param_1,0);
  return;
}



===== mpi3MSIIsr @ 140007de0 =====

undefined8 mpi3MSIIsr(longlong param_1,ushort param_2)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort uVar11;
  ushort uVar12;
  short sVar13;
  ushort *puVar14;
  ulonglong uVar15;
  bool bVar16;
  short local_res8;
  ushort local_res18 [4];
  ushort local_res20;
  uint local_48;
  undefined1 local_44;
  longlong local_40;
  
  local_48 = *(uint *)(param_1 + 0xb6c);
  uVar5 = (ulonglong)local_48;
  uVar12 = *(ushort *)(param_1 + 0x35e);
  local_44 = local_48 != 0xc;
  uVar15 = 0xffff;
  if ((*(char *)(param_1 + 0x410) != '\0') ||
     ((*(char *)(param_1 + 0x8a2) != '\0' && (*(int *)(param_1 + 0x434) != 1)))) goto LAB_140008473;
  if (*(char *)(param_1 + 0x3c2) == '\0') {
    param_2 = 0;
  }
  sVar13 = 0;
  local_res8 = 0;
  local_res18[0] = *(ushort *)(*(longlong *)(param_1 + 0x9e0) + (ulonglong)param_2 * 2);
  local_res20 = uVar12;
  if (local_res18[0] == 0) {
    if ((param_2 != 0) || ((*(char *)(param_1 + 0x411) != '\0' && (*(int *)(param_1 + 0x428) == 0)))
       ) {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x288) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x288,(undefined1 *)local_res18,2,param_2,
                    (int *)&local_48);
      }
      LogOperationalEvent(param_1,(int *)local_res18,2,0xc004af02,
                          "Kill Adapter (Driver) - Bad MSIx (logged MSIx Reply QID)",param_2,
                          (int *)&local_48);
      uVar5 = KillAdapter(param_1,0x13,param_2,(int *)&local_48);
      goto LAB_1400082a3;
    }
LAB_1400082ac:
    bVar16 = true;
    uVar5 = *(ulonglong *)(param_1 + 0x2d0);
    if ((*(ushort *)(uVar5 + 0xe + (ulonglong)*(ushort *)(param_1 + 0x2b0) * 0x10) & 1) ==
        *(ushort *)(param_1 + 0x2d8)) {
      AcquireIsrLocks(param_1,0,(int *)&local_48);
      uVar12 = *(ushort *)(param_1 + 0x2b0);
      uVar7 = *(ushort *)(param_1 + 0x2d8);
      puVar9 = (ushort *)((ulonglong)uVar12 * 0x10 + *(longlong *)(param_1 + 0x2d0));
      if ((puVar9[7] & 1) == uVar7) {
        do {
          *(ushort *)(param_1 + 0x2ae) = puVar9[4];
          ProcessAdminReplyDescriptor(param_1,puVar9,0,(int *)&local_48);
          puVar9[5] = 0xffff;
          uVar8 = uVar12 + 1;
          uVar12 = 0;
          if (uVar8 != *(ushort *)(param_1 + 0x2a2)) {
            uVar12 = uVar8;
          }
          uVar11 = uVar7 ^ 1;
          if (uVar8 != *(ushort *)(param_1 + 0x2a2)) {
            uVar11 = uVar7;
          }
          puVar9 = (ushort *)((ulonglong)uVar12 * 0x10 + *(longlong *)(param_1 + 0x2d0));
          uVar7 = uVar11;
        } while ((puVar9[7] & 1) == uVar11);
        **(ushort **)(param_1 + 0x88) = uVar12;
        LOCK();
        UNLOCK();
        *(ushort *)(param_1 + 0x2b0) = uVar12;
        *(uint *)(param_1 + 0x2d8) = (uint)uVar11;
      }
      else {
        bVar16 = false;
      }
      uVar5 = ReleaseIsrLocks(param_1,0,(int *)&local_48);
    }
    else {
      bVar16 = false;
    }
  }
  else {
    uVar7 = *(ushort *)(*(longlong *)(param_1 + 0xa18) + 0x14 + (ulonglong)local_res18[0] * 0x18);
    local_40 = *(longlong *)(param_1 + 0xa18) + (ulonglong)local_res18[0] * 0x18;
    uVar11 = (ushort)*(byte *)(local_40 + 0x16);
    puVar9 = (ushort *)((ulonglong)uVar7 * 0x10 + *(longlong *)(local_40 + 8));
    uVar8 = puVar9[7];
    uVar5 = 0;
    if ((uVar8 & 1) == (ushort)*(byte *)(local_40 + 0x16)) {
      do {
        puVar10 = (ushort *)0x0;
        *(ushort *)((ulonglong)puVar9[5] * 0x20 + 0x1a + *(longlong *)(param_1 + 0xa10)) = puVar9[4]
        ;
        sVar13 = local_res8;
        if ((uVar8 & 0xf000) == 0x1000) {
          uVar8 = puVar9[6];
          uVar15 = (ulonglong)uVar8;
          if (uVar8 == 0) {
            if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x289) != 0))
            {
              RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x289,(undefined1 *)0x0,0,param_2,
                          (int *)&local_48);
            }
            LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                                "Kill Adapter (Driver) - Received Host Tag 0",param_2,
                                (int *)&local_48);
            uVar5 = KillAdapter(param_1,0x10,param_2,(int *)&local_48);
            goto LAB_1400082a3;
          }
          lVar3 = *(longlong *)(param_1 + 0x9f0);
          lVar4 = *(longlong *)(lVar3 + uVar15 * 0x18);
          *(undefined8 *)(lVar3 + uVar15 * 0x18) = 0;
          *(undefined4 *)(lVar3 + 0x10 + uVar15 * 0x18) = 0;
          ReturnHostTagToFIFO(param_1,uVar8);
          if ((lVar4 == 0) || (*(longlong *)(lVar4 + 0x68) == 0)) {
            LogSystemEvent(param_1,0,0xc004af02,(byte *)"Received NULL SRB with bad context ",
                           param_2,(int *)&local_48);
          }
          else {
            *(undefined1 *)(*(longlong *)(*(longlong *)(lVar4 + 0x68) + 0x30) + 8) = 0;
            *(undefined1 *)(lVar4 + 3) = 1;
            LOCK();
            *(int *)(param_1 + 0x8e8) = *(int *)(param_1 + 0x8e8) + -1;
            UNLOCK();
            StorPortNotification(0,param_1,lVar4);
          }
          uVar8 = uVar7 + 1;
          if (uVar8 == uVar12) {
            uVar11 = uVar11 ^ 1;
          }
          uVar7 = 0;
          if (uVar8 != uVar12) {
            uVar7 = uVar8;
          }
        }
        else {
          if ((uVar8 & 0xf000) == 0) {
            puVar14 = (ushort *)(*(longlong *)(param_1 + 0xa50) + *(longlong *)puVar9);
            uVar12 = *puVar14;
            uVar15 = (ulonglong)uVar12;
            puVar10 = puVar9;
            if (uVar12 == 0) {
              if ((*(char *)(param_1 + 0xc00) != '\0') &&
                 ((*(uint *)(param_1 + 0xc04) & 0x28a) != 0)) {
                RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x28a,(undefined1 *)0x0,0,param_2,
                            (int *)&local_48);
              }
              LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                                  "Kill Adapter (Driver) - Received Host Tag 0 Address Reply",
                                  param_2,(int *)&local_48);
              uVar5 = KillAdapter(param_1,0x11,param_2,(int *)&local_48);
              goto LAB_1400082a3;
            }
          }
          else {
            LogSystemEvent(param_1,0,0x8004af01,
                           (byte *)"An invalid reply descriptor type was received, Ignored",param_2,
                           (int *)&local_48);
            puVar14 = puVar10;
          }
          plVar1 = (longlong *)(*(longlong *)(param_1 + 0x9f0) + uVar15 * 0x18);
          ProcessScsiErrorReply(param_1,(short *)puVar14,plVar1,param_2,(int *)&local_48);
          *plVar1 = 0;
          *(undefined4 *)(plVar1 + 2) = 0;
          ReturnHostTagToFIFO(param_1,(ushort)uVar15);
          if (puVar14 != (ushort *)0x0) {
            do {
              uVar2 = *(uint *)(param_1 + 0xa88);
              uVar6 = 0;
              if (uVar2 + 1 != (uint)*(ushort *)(param_1 + 0x362)) {
                uVar6 = uVar2 + 1;
              }
              LOCK();
              bVar16 = uVar2 == *(uint *)(param_1 + 0xa88);
              if (bVar16) {
                *(uint *)(param_1 + 0xa88) = uVar6;
              }
              UNLOCK();
            } while (!bVar16);
            *(undefined8 *)(*(longlong *)(param_1 + 0xa58) + (ulonglong)uVar2 * 8) =
                 *(undefined8 *)puVar10;
            **(undefined4 **)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 0xa88);
            LOCK();
            UNLOCK();
          }
          uVar7 = uVar7 + 1;
          uVar12 = local_res20;
          if (uVar7 == local_res20) {
            uVar11 = uVar11 ^ 1;
            uVar7 = 0;
          }
        }
        local_res8 = local_res8 + 1;
        puVar9 = (ushort *)((ulonglong)uVar7 * 0x10 + *(longlong *)(local_40 + 8));
        uVar8 = puVar9[7];
        uVar5 = 0;
      } while ((uVar8 & 1) == uVar11);
      sVar13 = local_res8;
      if (local_res8 != 0) {
        uVar5 = *(ulonglong *)(param_1 + 0xa0);
        *(uint *)((uVar5 - 8) + (ulonglong)((uint)local_res18[0] * 2) * 4) = (uint)uVar7;
        LOCK();
        UNLOCK();
        *(ushort *)(local_40 + 0x14) = uVar7;
        *(char *)(local_40 + 0x16) = (char)uVar11;
      }
    }
LAB_1400082a3:
    bVar16 = false;
    if (param_2 == 0) goto LAB_1400082ac;
  }
  if ((sVar13 != 0) || (bVar16)) {
    return CONCAT71((int7)(uVar5 >> 8),1);
  }
LAB_140008473:
  return uVar5 & 0xffffffffffffff00;
}



===== MPI3BuildNVMePRPforIOCTL @ 140008490 =====

ulonglong MPI3BuildNVMePRPforIOCTL
                    (longlong param_1,longlong param_2,uint param_3,longlong param_4,uint param_5,
                    ushort param_6,int *param_7)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  longlong lVar4;
  uint *puVar5;
  ushort uVar6;
  ulonglong uVar7;
  uint *puVar8;
  char cVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  ulonglong uVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  uint *puVar18;
  bool bVar19;
  uint local_res8;
  undefined1 local_58 [4];
  uint local_54;
  undefined4 local_50 [2];
  undefined8 local_48;
  
  lVar4 = *(longlong *)(param_1 + 0x9f8);
  uVar16 = 0x1000;
  uVar6 = 0;
  if (*(ushort *)(param_1 + 0x372) != 0) {
    do {
      if (*(short *)(lVar4 + 8) == *(short *)(param_4 + 10)) {
        if (*(byte *)(lVar4 + 0x17) != 0) {
          uVar16 = 1 << (*(byte *)(lVar4 + 0x17) & 0x1f);
        }
        break;
      }
      uVar6 = uVar6 + 1;
      lVar4 = lVar4 + 0x18;
    } while (uVar6 < *(ushort *)(param_1 + 0x372));
  }
  uVar1 = uVar16 - 1;
  puVar5 = (uint *)StorPortGetScatterGatherList(param_1);
  if (puVar5 == (uint *)0x0) {
    local_50[0] = 1;
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x29f) != 0)) {
      puVar5 = (uint *)RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x29f,
                                   (undefined1 *)local_50,4,param_6,param_7);
    }
  }
  else {
    puVar11 = puVar5 + 4;
    local_res8 = *puVar5;
    if (param_5 != 0) {
      bVar19 = false;
      if (uVar16 * 2 < param_5) {
        bVar19 = true;
      }
      else if (uVar16 < param_5) {
        bVar19 = uVar16 - (param_3 & uVar1) < param_5 % uVar16;
      }
      uVar15 = param_3 - *(int *)(param_2 + 0x40);
      uVar10 = puVar5[6];
      puVar18 = puVar11;
      if (uVar10 <= uVar15) {
        do {
          puVar18 = puVar11 + 6;
          uVar15 = uVar15 - uVar10;
          local_res8 = local_res8 - 1;
          uVar10 = puVar11[8];
          puVar11 = puVar18;
        } while (uVar10 <= uVar15);
      }
      uVar3 = StorPortGetPhysicalAddress(param_1,param_2,param_4 + 0x80,local_58);
      uVar7 = param_4 + 0x88U & (ulonglong)uVar1;
      cVar9 = '\x01';
      puVar11 = (uint *)(param_4 + 0x38);
      uVar10 = uVar3 + 8;
      if (uVar7 != 0) {
        uVar10 = uVar3;
      }
      local_54 = 0;
      if (local_res8 == 0) {
        return 1;
      }
      lVar4 = 0x88;
      if (uVar7 != 0) {
        lVar4 = 0x80;
      }
      puVar8 = (uint *)(lVar4 + param_4);
      do {
        uVar7 = (ulonglong)uVar15 + *(longlong *)puVar18;
        uVar15 = puVar18[2] - uVar15;
        if (uVar15 != 0) {
          local_48._4_4_ = (uint)(uVar7 >> 0x20);
          puVar17 = puVar8 + 2;
          uVar14 = uVar7 & 0xffffffff;
          uVar3 = local_48._4_4_;
          local_48 = uVar7;
          do {
            bVar2 = true;
            if (((ulonglong)uVar1 & (ulonglong)puVar17) == 0) {
              uVar10 = uVar10 + 8;
              *puVar8 = uVar10;
              puVar8[1] = *(uint *)(param_1 + 0x1c);
              puVar8 = puVar8 + 2;
              puVar17 = puVar17 + 2;
            }
            uVar13 = (uint)uVar14;
            uVar12 = uVar16 - (uVar13 & uVar16 - 1);
            if (cVar9 == '\x01') {
              *puVar11 = uVar13;
              uVar13 = *(uint *)(param_1 + 0x354);
              puVar5 = (uint *)(ulonglong)uVar13;
              if ((uVar3 & uVar13) != 0) goto LAB_1400087d4;
              cVar9 = '\x02';
              uVar3 = ~uVar13 & uVar3 | *(uint *)(param_1 + 0x358);
              puVar11[1] = uVar3;
              puVar11 = puVar11 + 2;
LAB_14000871d:
              local_48 = CONCAT44(uVar3,(undefined4)local_48);
LAB_140008721:
              uVar7 = local_48 + uVar12;
              if (uVar15 < uVar12) break;
              local_48._4_4_ = (uint)(uVar7 >> 0x20);
              uVar15 = uVar15 - uVar12;
              uVar14 = uVar7 & 0xffffffff;
              uVar3 = local_48._4_4_;
              local_48 = uVar7;
            }
            else {
              if (cVar9 != '\x02') {
                *puVar8 = uVar13;
                uVar13 = *(uint *)(param_1 + 0x354);
                puVar5 = (uint *)(ulonglong)uVar13;
                if ((uVar3 & uVar13) == 0) {
                  puVar17 = puVar17 + 2;
                  uVar3 = ~uVar13 & uVar3 | *(uint *)(param_1 + 0x358);
                  puVar8[1] = uVar3;
                  puVar8 = puVar8 + 2;
                  uVar10 = uVar10 + 8;
                  goto LAB_14000871d;
                }
                goto LAB_1400087d4;
              }
              if (bVar19) {
                *puVar11 = uVar10;
                bVar2 = false;
                puVar11[1] = *(uint *)(param_1 + 0x1c);
              }
              else {
                *puVar11 = uVar13;
                uVar13 = *(uint *)(param_1 + 0x354);
                puVar5 = (uint *)(ulonglong)uVar13;
                if ((uVar3 & uVar13) != 0) goto LAB_1400087d4;
                uVar3 = uVar3 & ~uVar13 | *(uint *)(param_1 + 0x358);
                local_48 = CONCAT44(uVar3,(undefined4)local_48);
                puVar11[1] = uVar3;
              }
              cVar9 = '\x03';
              if (bVar2) goto LAB_140008721;
            }
          } while (uVar15 != 0);
        }
        puVar18 = puVar18 + 6;
        local_54 = local_54 + 1;
        uVar15 = 0;
        if (local_res8 <= local_54) {
          return CONCAT71((uint7)(uint3)(local_54 >> 8),1);
        }
      } while( true );
    }
  }
LAB_1400087d4:
  return (ulonglong)puVar5 & 0xffffffffffffff00;
}



===== MPI3BuildScatterGatherforIOCTL @ 140008800 =====

longlong MPI3BuildScatterGatherforIOCTL
                   (undefined8 param_1,undefined8 param_2,undefined8 *param_3,longlong param_4,
                   uint param_5)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar4 = 0;
  uVar3 = param_5;
  do {
    puVar2 = param_3;
    uVar1 = StorPortGetPhysicalAddress(param_1,param_2,param_4,&param_5);
    *puVar2 = uVar1;
    if (uVar3 < param_5) {
      param_5 = uVar3;
    }
    uVar4 = uVar4 + 1;
    param_4 = param_4 + (ulonglong)param_5;
    *(uint *)(puVar2 + 1) = param_5;
    uVar3 = uVar3 - param_5;
    param_3 = puVar2 + 2;
  } while (uVar3 != 0);
  *(byte *)((longlong)puVar2 + 0xf) = *(byte *)((longlong)puVar2 + 0xf) | 4;
  return (ulonglong)uVar4 << 4;
}



===== MPI3HandleAppRequest @ 140008890 =====

void MPI3HandleAppRequest(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  lVar2 = *(longlong *)(param_2 + 0x40);
  iVar1 = *(int *)(lVar2 + 0x10);
  if (iVar1 == -0x7f8d8b8c) {
    if ((((*(char *)(lVar2 + 4) != 'R') || (*(char *)(lVar2 + 5) != 'T')) ||
        (*(char *)(lVar2 + 6) != 'T')) ||
       (((*(char *)(lVar2 + 7) != 'r' || (*(char *)(lVar2 + 8) != 'a')) ||
        ((*(char *)(lVar2 + 9) != 'c' || (*(char *)(lVar2 + 10) != 'e')))))) {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x260) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x260,(undefined1 *)0x0,0,param_3,param_4)
        ;
      }
      *(undefined1 *)(param_2 + 3) = 6;
      *(undefined4 *)(param_2 + 0x3c) = 0;
      *(undefined4 *)(lVar2 + 0x14) = 4;
      StorPortNotification(0,param_1,param_2);
      *(undefined4 *)(param_1 + 0x43c) = 0;
      return;
    }
  }
  else if (((((*(char *)(lVar2 + 4) != 'B') || (*(char *)(lVar2 + 5) != 'R')) ||
            (*(char *)(lVar2 + 6) != 'O')) ||
           ((*(char *)(lVar2 + 7) != 'A' || (*(char *)(lVar2 + 8) != 'D')))) ||
          ((*(char *)(lVar2 + 9) != 'C' ||
           ((*(char *)(lVar2 + 10) != 'O' || (*(char *)(lVar2 + 0xb) != 'M')))))) {
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(param_2 + 0x3c) = 0;
    *(undefined4 *)(lVar2 + 0x14) = 0xfa01;
    StorPortNotification(0,param_1,param_2);
    *(undefined4 *)(param_1 + 0x43c) = 0;
    return;
  }
  if (iVar1 == -0x7fbcb6b3) {
    uVar4 = RetrieveHostDriverData(param_1,param_2,param_3,param_4);
    cVar3 = (char)uVar4;
  }
  else {
    if (iVar1 == -0x7f928f97) {
      uVar4 = MPI3SendIOCTLMessage(param_1,param_2,param_3,param_4);
      if ((char)uVar4 != '\0') {
        return;
      }
      uVar6 = 4;
      goto LAB_140008c1c;
    }
    if (iVar1 == -0x7f8d8c8c) {
      cVar3 = *(char *)(param_1 + 0xc00);
      if (*(int *)(lVar2 + 0x1c) == 1) {
        if ((cVar3 != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x20023) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x20023,(undefined1 *)0x0,0,param_3,
                      param_4);
        }
        uVar7 = 0x100;
        pcVar5 = "TM Reset (IOCTL) - Soft Reset requested via IOCTL";
        uVar8 = 0xc;
      }
      else {
        if (*(int *)(lVar2 + 0x1c) != 2) {
          if ((cVar3 != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x20025) != 0)) {
            RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x20025,(undefined1 *)(lVar2 + 0x1c),4
                        ,param_3,param_4);
          }
          LogOperationalEvent(param_1,(int *)(lVar2 + 0x1c),4,0x4004af00,
                              "TM Reset (IOCTL) - Unrecognized type of Reset requested via IOCTL",
                              param_3,param_4);
          *(undefined1 *)(param_2 + 3) = 6;
          *(undefined4 *)(lVar2 + 0x14) = 0xfa09;
          StorPortNotification(0,param_1,param_2);
          return;
        }
        if ((cVar3 != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x20024) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x20024,(undefined1 *)0x0,0,param_3,
                      param_4);
        }
        uVar7 = 0x700;
        pcVar5 = "TM Reset (IOCTL) - Diag Fault Reset requested via IOCTL";
        uVar8 = 0xd;
      }
      LogOperationalEvent(param_1,(int *)0x0,0,0x4004af00,pcVar5,param_3,param_4);
      *(undefined4 *)(param_1 + 0x8c4) = uVar8;
      *(undefined4 *)(lVar2 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x428) = 1;
      *(undefined4 *)(param_1 + 0x8a4) = 1;
      *(undefined1 *)(param_1 + 0x440) = 1;
      *(longlong *)(param_1 + 0x448) = param_2;
      StartAdapterReset(param_1,uVar7,param_3,param_4);
      return;
    }
    if (iVar1 != -0x7f8d8b8c) {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x203) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x203,(undefined1 *)(lVar2 + 0x10),4,
                    param_3,param_4);
      }
      uVar6 = 6;
      goto LAB_140008c1c;
    }
    uVar4 = RttHandleIoctl(param_1,lVar2,param_3,param_4);
    cVar3 = (char)uVar4;
  }
  uVar6 = 4;
  if (cVar3 != '\0') {
    uVar6 = 1;
  }
LAB_140008c1c:
  *(undefined1 *)(param_2 + 3) = uVar6;
  StorPortNotification(0,param_1,param_2);
  *(undefined4 *)(param_1 + 0x43c) = 0;
  return;
}



===== MPI3SendIOCTLMessage @ 140008c70 =====

ulonglong MPI3SendIOCTLMessage(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  byte bVar1;
  longlong lVar2;
  int *piVar3;
  ulonglong in_RAX;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  uint uVar10;
  longlong lVar11;
  uint uVar12;
  longlong lVar13;
  byte bVar14;
  byte *pbVar15;
  void *_Src;
  uint uVar16;
  void *pvVar17;
  void *_Src_00;
  undefined8 *puVar18;
  byte *pbVar19;
  ushort uVar20;
  undefined8 *_Dst;
  undefined8 *puVar21;
  byte local_res8 [8];
  longlong local_res10;
  ushort local_res18;
  int *local_res20;
  byte local_a8;
  uint local_a4;
  uint local_9c;
  uint local_98;
  void *local_90;
  void *local_88;
  undefined8 *local_70;
  undefined1 local_68 [8];
  ulonglong local_60;
  longlong local_58;
  
  lVar2 = *(longlong *)(param_2 + 0x40);
  lVar11 = *(longlong *)(param_2 + 0x68);
  pbVar19 = (byte *)(lVar2 + 0x28);
  local_9c = 0;
  local_a4 = 0;
  *(undefined8 *)(lVar11 + 0x54) = 0;
  uVar16 = 0;
  *(undefined4 *)(lVar11 + 0x5c) = 0;
  uVar10 = 0;
  bVar1 = *(byte *)(lVar2 + 0x1c);
  if (bVar1 == 0) {
    *(undefined4 *)(lVar2 + 0x14) = 0xfa0a;
    uVar6 = in_RAX & 0xffffffffffffff00;
  }
  else {
    uVar20 = *(short *)(lVar2 + 0x1e) << 2;
    bVar14 = 0;
    uVar7 = (uint)uVar20;
    uVar12 = (uint)bVar1 * 8 + 0xc + uVar7;
    uVar8 = 0xc;
    pbVar15 = pbVar19;
    if (bVar1 != 0) {
      do {
        in_RAX = (ulonglong)*pbVar15;
        switch(in_RAX) {
        default:
          *(undefined4 *)(lVar2 + 0x14) = 0xfa0b;
          return 0;
        case 1:
        case 4:
          uVar12 = uVar12 + *(int *)(pbVar15 + 4);
          uVar16 = uVar16 + 1;
          break;
        case 2:
        case 3:
          uVar8 = uVar8 + *(int *)(pbVar15 + 4);
          uVar10 = uVar10 + 1;
          break;
        case 5:
        case 6:
          uVar8 = uVar8 + *(int *)(pbVar15 + 4);
        }
        pbVar15 = pbVar15 + 8;
        bVar14 = bVar14 + 1;
      } while (bVar14 < bVar1);
    }
    if (uVar8 < uVar12) {
      uVar8 = uVar12;
    }
    if (*(uint *)(lVar2 + 0x18) < uVar8) {
      *(undefined4 *)(lVar2 + 0x14) = 0xfa02;
      uVar6 = in_RAX & 0xffffffffffffff00;
    }
    else {
      _Src_00 = (void *)((ulonglong)bVar1 * 8 + lVar2 + 0x28);
      local_res8[0] = *(byte *)((longlong)_Src_00 + 3);
      if ((local_res8[0] == 0x24) && ((1 < uVar16 || (1 < uVar10)))) {
        *(undefined4 *)(lVar2 + 0x14) = 0xfa0c;
        uVar6 = 0;
      }
      else {
        pvVar9 = (void *)(lVar11 + 0x60);
        local_res10 = param_2;
        local_res18 = param_3;
        local_res20 = param_4;
        local_58 = lVar11;
        ZeroMemory(pvVar9,0x1080);
        uVar4 = (ulonglong)uVar20;
        local_60 = uVar4;
        memmove(pvVar9,_Src_00,uVar4);
        puVar18 = (undefined8 *)(uVar4 + (longlong)pvVar9);
        uVar6 = 0;
        local_70 = puVar18;
        switch(local_res8[0]) {
        case 10:
          if (*pbVar19 != 1) {
            *(undefined4 *)(lVar2 + 0x14) = 0xfa0d;
            return 0;
          }
        case 0x24:
          local_70 = (undefined8 *)(lVar11 + 0xe0);
          break;
        case 0x21:
          if (*(char *)(param_1 + 0x408) == '\0') {
            PauseController(param_1,1,local_res18,local_res20);
          }
          *(undefined4 *)(param_1 + 0x428) = 1;
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
        case 0x1d:
        case 0x1e:
        case 0x1f:
        case 0x20:
        case 0x22:
        case 0x23:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2b:
        case 0x2c:
        case 0x2d:
        case 0x2e:
        case 0x2f:
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
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
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
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
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x59:
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
        case 0x65:
        case 0x66:
        case 0x67:
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
        case 0x75:
        case 0x76:
        case 0x77:
        case 0x78:
        case 0x79:
        case 0x7a:
        case 0x7b:
        case 0x7c:
        case 0x7d:
        case 0x7e:
        case 0x7f:
        case 0x80:
          break;
        case 0x81:
        case 0x82:
        case 0x83:
          if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x29e) != 0)) {
            uVar6 = RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x29e,local_res8,1,local_res18
                                ,local_res20);
          }
          *(undefined4 *)(lVar2 + 0x14) = 0xfa15;
          return uVar6 & 0xffffffffffffff00;
        }
        pvVar9 = (void *)(lVar2 + 0x1c);
        local_a8 = 0;
        _Src = (void *)(uVar4 + (longlong)_Src_00);
        pvVar17 = pvVar9;
        if (bVar1 != 0) {
          _Dst = local_70;
          local_90 = pvVar9;
          local_88 = _Src;
          do {
            lVar13 = lVar2 + 0x1c;
            switch(*pbVar19) {
            case 1:
              uVar10 = *(uint *)(pbVar19 + 4);
              memmove(_Dst,_Src,(ulonglong)uVar10);
              _Src = (void *)((longlong)local_88 + (ulonglong)uVar10);
              _Dst = (undefined8 *)((longlong)_Dst + (ulonglong)uVar10);
              local_9c = local_9c + uVar10;
              pvVar9 = local_90;
              lVar11 = local_58;
              local_88 = _Src;
              goto switchD_140008f33_default;
            case 2:
              uVar10 = *(uint *)(pbVar19 + 4);
              pvVar17 = (void *)((ulonglong)*(uint *)(lVar11 + 0x58) + lVar13);
              *(uint *)(lVar11 + 0x54) = uVar10;
              local_90 = (void *)((longlong)pvVar17 + (ulonglong)uVar10);
              break;
            case 3:
              local_98 = *(uint *)(pbVar19 + 4);
              *(int *)(lVar11 + 0x5c) = *(int *)(lVar11 + 0x5c) + local_98;
              if (local_res8[0] == 0x24) {
LAB_140008fbd:
                MPI3BuildNVMePRPforIOCTL
                          (param_1,local_res10,(uint)pvVar9,(longlong)_Src_00,local_98,local_res18,
                           local_res20);
                memmove((void *)(lVar11 + 0x60),_Src_00,local_60);
                pvVar9 = local_90;
                _Src = local_88;
                goto switchD_140008f33_default;
              }
              uVar4 = MPI3BuildScatterGatherforIOCTL
                                (param_1,local_res10,_Dst,(longlong)pvVar9,local_98);
              local_a4 = (uint)uVar4;
              uVar6 = uVar4 & 0xffffffff;
              if (0x1000 < local_a4) {
LAB_1400093a1:
                *(undefined4 *)(lVar2 + 0x14) = 0xfa0e;
                return uVar4 & 0xffffffffffffff00;
              }
              puVar21 = _Dst;
              if ((local_res8[0] != 10) && (0x80 < uVar7 + local_a4)) {
                ZeroMemory(_Dst,local_a4);
                puVar21 = (undefined8 *)(lVar11 + 0xe0);
                uVar5 = StorPortGetPhysicalAddress(param_1,local_res10,puVar21,local_68);
                *_Dst = uVar5;
                *(uint *)(_Dst + 1) = local_a4;
                *(undefined1 *)((longlong)_Dst + 0xf) = 0x30;
                uVar6 = MPI3BuildScatterGatherforIOCTL
                                  (param_1,local_res10,puVar21,(longlong)local_90,local_98);
                local_a4 = (uint)uVar6;
                uVar6 = uVar6 & 0xffffffff;
                local_70 = puVar21;
              }
              uVar10 = (uint)uVar6;
              if (local_res8[0] == 0x22) {
                *(byte *)((longlong)puVar21 + 0xf) = *(byte *)((longlong)puVar21 + 0xf) | 8;
              }
              local_9c = local_9c + uVar10;
              _Dst = (undefined8 *)((longlong)puVar21 + uVar6);
              pvVar9 = (void *)((longlong)local_90 + (ulonglong)local_98);
              _Src = local_88;
              local_90 = pvVar9;
              goto LAB_14000929e;
            case 4:
              local_98 = *(uint *)(pbVar19 + 4);
              if (local_res8[0] == 0x24) {
                pvVar9 = _Src;
                goto LAB_140008fbd;
              }
              uVar4 = MPI3BuildScatterGatherforIOCTL
                                (param_1,local_res10,_Dst,(longlong)_Src,local_98);
              local_a4 = (uint)uVar4;
              uVar6 = uVar4 & 0xffffffff;
              if (0x1000 < local_a4) goto LAB_1400093a1;
              puVar21 = _Dst;
              if ((local_res8[0] != 10) && (0x80 < uVar7 + local_a4)) {
                ZeroMemory(_Dst,local_a4);
                puVar21 = (undefined8 *)(lVar11 + 0xe0);
                uVar5 = StorPortGetPhysicalAddress(param_1,local_res10,puVar21,local_68);
                *_Dst = uVar5;
                *(uint *)(_Dst + 1) = local_a4;
                *(undefined1 *)((longlong)_Dst + 0xf) = 0x30;
                uVar6 = MPI3BuildScatterGatherforIOCTL
                                  (param_1,local_res10,puVar21,(longlong)local_88,local_98);
                local_a4 = (uint)uVar6;
                uVar6 = uVar6 & 0xffffffff;
                local_70 = puVar21;
              }
              uVar10 = (uint)uVar6;
              if (local_res8[0] == 0x22) {
                *(byte *)((longlong)puVar21 + 0xf) = *(byte *)((longlong)puVar21 + 0xf) | 8;
              }
              local_9c = local_9c + uVar10;
              _Dst = (undefined8 *)((longlong)puVar21 + uVar6);
              local_88 = (void *)((longlong)local_88 + (ulonglong)local_98);
              pvVar9 = local_90;
              _Src = local_88;
              goto LAB_14000929e;
            case 5:
              uVar10 = *(uint *)(pbVar19 + 4);
              *(uint *)(lVar11 + 0x58) = uVar10;
              if (local_res8[0] != 10) {
                local_90 = (void *)((ulonglong)*(uint *)(lVar11 + 0x54) + lVar13 + (ulonglong)uVar10
                                   );
                goto LAB_140009292;
              }
              pvVar17 = (void *)(lVar13 + (ulonglong)uVar10);
              local_90 = (void *)((ulonglong)*(uint *)(lVar11 + 0x54) + (longlong)pvVar17);
              break;
            case 6:
              uVar10 = *(uint *)(pbVar19 + 4);
              *(uint *)(lVar11 + 0x54) = uVar10;
              local_90 = (void *)((ulonglong)*(uint *)(lVar11 + 0x58) + (ulonglong)uVar10 + lVar13);
LAB_140009292:
              pvVar17 = local_90;
              break;
            default:
              goto switchD_140008f33_default;
            }
            pvVar9 = local_90;
switchD_140008f33_default:
            uVar10 = local_a4;
LAB_14000929e:
            local_a8 = local_a8 + 1;
            pbVar19 = pbVar19 + 8;
          } while (local_a8 < bVar1);
          if (uVar10 != 0) {
            *(byte *)((longlong)_Dst + -1) = *(byte *)((longlong)_Dst + -1) | 8;
          }
        }
        piVar3 = local_res20;
        uVar20 = local_res18;
        *(undefined2 *)(lVar11 + 0x60) = 0xadb0;
        if (local_res8[0] == 10) {
          uVar6 = MPI3BuildScatterGatherforIOCTL
                            (param_1,local_res10,puVar18,(longlong)local_70,local_9c);
          puVar18 = (undefined8 *)((longlong)puVar18 + (uVar6 & 0xffffffff));
          *(byte *)((longlong)puVar18 + -1) = *(byte *)((longlong)puVar18 + -1) | 8;
          if (*(int *)(lVar11 + 0x54) != 0) {
            uVar6 = MPI3BuildScatterGatherforIOCTL
                              (param_1,local_res10,puVar18,(longlong)pvVar17,
                               *(uint *)(lVar11 + 0x54));
            pbVar19 = (byte *)((longlong)puVar18 + ((uVar6 & 0xffffffff) - 1));
            *pbVar19 = *pbVar19 | 8;
          }
        }
        *(longlong *)(param_1 + 0x448) = local_res10;
        uVar6 = AdminQueueRequestPost(param_1,(void *)(lVar11 + 0x60),uVar20,piVar3);
        if ((char)uVar6 == '\0') {
          *(undefined4 *)(lVar2 + 0x14) = 0xfa0f;
          *(undefined8 *)(param_1 + 0x448) = 0;
          uVar10 = *(uint *)(lVar2 + 0x14);
          uVar16 = uVar10;
          if (uVar10 < 0xfa01) {
            uVar16 = 0xfa10;
          }
          uVar6 = (ulonglong)(uint3)(uVar10 >> 8) << 8;
          *(uint *)(lVar2 + 0x14) = uVar16;
        }
        else {
          uVar6 = CONCAT71((int7)(uVar6 >> 8),1);
        }
      }
    }
  }
  return uVar6;
}



===== RetrieveHostDriverData @ 140009490 =====

ulonglong RetrieveHostDriverData(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  ushort uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  void *pvVar10;
  short *psVar11;
  undefined8 uVar12;
  undefined1 uVar13;
  int iVar14;
  ushort *puVar15;
  ushort uVar16;
  ulonglong uVar17;
  ushort *_Dst;
  bool bVar18;
  byte local_res8 [8];
  
  lVar6 = *(longlong *)(param_2 + 0x40);
  uVar17 = 0;
  *(undefined4 *)(lVar6 + 0x14) = 0;
  uVar8 = *(int *)(lVar6 + 0x1c) - 1;
  uVar9 = (ulonglong)uVar8;
  if (9 < uVar8) {
switchD_1400094d1_caseD_5:
    *(undefined4 *)(lVar6 + 0x14) = 0xfa08;
LAB_1400099db:
    return uVar9 & 0xffffffffffffff00;
  }
  uVar9 = (ulonglong)(int)uVar8;
  switch(uVar8) {
  case 0:
    if (0x9f < *(uint *)(lVar6 + 0x18)) {
      pvVar10 = memmove((void *)(lVar6 + 0x20),(void *)(param_1 + 0x1f8),0x9c);
      *(undefined4 *)(param_2 + 0x3c) = 0xbc;
      return CONCAT71((int7)((ulonglong)pvVar10 >> 8),1);
    }
    break;
  case 1:
    if (0x103 < *(uint *)(lVar6 + 0x18)) {
      pvVar10 = memmove((void *)(lVar6 + 0x20),(void *)(param_1 + 0xf8),0x100);
      *(undefined4 *)(param_2 + 0x3c) = 0x120;
      return CONCAT71((int7)((ulonglong)pvVar10 >> 8),1);
    }
    break;
  case 2:
    if (0x13 < *(uint *)(lVar6 + 0x18)) {
      bVar1 = *(byte *)(lVar6 + 0x24);
      iVar14 = *(int *)(lVar6 + 0x20);
      sVar2 = *(short *)(lVar6 + 0x28);
      sVar3 = *(short *)(lVar6 + 0x2a);
      if ((bVar1 == 0xff) || (iVar14 == -1)) {
        if (sVar3 == -1) {
          if (sVar2 == -1) {
            *(undefined4 *)(lVar6 + 0x14) = 0xfa07;
            return 0;
          }
          if ((bVar1 == 0xff) && (iVar14 == -1)) {
            uVar9 = 0;
            if (*(ushort *)(param_1 + 0x372) != 0) {
              do {
                uVar16 = (ushort)uVar17;
                uVar9 = *(longlong *)(param_1 + 0x9f8) + uVar17 * 0x18;
                if (*(short *)(*(longlong *)(param_1 + 0x9f8) + 8 + uVar17 * 0x18) == sVar2) {
                  *(undefined2 *)(lVar6 + 0x2a) = *(undefined2 *)(uVar9 + 10);
                  goto LAB_1400096a0;
                }
                uVar17 = (ulonglong)(ushort)(uVar16 + 1);
              } while ((ushort)(uVar16 + 1) < *(ushort *)(param_1 + 0x372));
            }
            *(undefined4 *)(lVar6 + 0x14) = 0xfa06;
            return uVar9 & 0xffffffffffffff00;
          }
        }
        else if (((bVar1 == 0xff) && (sVar2 == -1)) && (iVar14 == -1)) {
          uVar9 = 0;
          if (*(ushort *)(param_1 + 0x372) != 0) {
            do {
              uVar16 = (ushort)uVar17;
              uVar9 = *(longlong *)(param_1 + 0x9f8) + uVar17 * 0x18;
              if (*(short *)(*(longlong *)(param_1 + 0x9f8) + 10 + uVar17 * 0x18) == sVar3) {
                if (*(short *)(uVar9 + 8) != 0) {
                  *(short *)(lVar6 + 0x28) = *(short *)(uVar9 + 8);
LAB_1400096a0:
                  *(char *)(lVar6 + 0x24) = (char)(uVar16 >> 7);
                  *(uint *)(lVar6 + 0x20) = uVar16 & 0x7f;
                  uVar9 = (ulonglong)*(ushort *)(param_1 + 0x8ec);
                  *(ushort *)(lVar6 + 0x2c) = *(ushort *)(param_1 + 0x8ec);
                  *(undefined4 *)(param_2 + 0x3c) = 0x30;
                  goto LAB_1400096c7;
                }
                goto LAB_140009688;
              }
              uVar17 = (ulonglong)(ushort)(uVar16 + 1);
            } while ((ushort)(uVar16 + 1) < *(ushort *)(param_1 + 0x372));
          }
          *(undefined4 *)(lVar6 + 0x14) = 0xfa05;
          return uVar9 & 0xffffffffffffff00;
        }
      }
      else if ((sVar3 == -1) && (sVar2 == -1)) {
        uVar16 = (ushort)bVar1 * 0x80 + (short)iVar14;
        if (*(ushort *)(param_1 + 0x372) < uVar16) {
          *(undefined4 *)(lVar6 + 0x14) = 0xfa04;
          return 0;
        }
        uVar9 = *(ulonglong *)(param_1 + 0x9f8);
        sVar2 = *(short *)(uVar9 + 8 + (ulonglong)uVar16 * 0x18);
        if (sVar2 != 0) {
          *(short *)(lVar6 + 0x28) = sVar2;
          *(undefined2 *)(lVar6 + 0x2a) = *(undefined2 *)(uVar9 + 10 + (ulonglong)uVar16 * 0x18);
          uVar4 = *(undefined2 *)(param_1 + 0x8ec);
          *(undefined2 *)(lVar6 + 0x2c) = uVar4;
          *(undefined4 *)(param_2 + 0x3c) = 0x30;
          return CONCAT71((uint7)(byte)((ushort)uVar4 >> 8),1);
        }
LAB_140009688:
        *(undefined4 *)(lVar6 + 0x14) = 0xfa13;
        return uVar9 & 0xffffffffffffff00;
      }
      *(undefined4 *)(lVar6 + 0x14) = 0xfa03;
      return 0;
    }
    break;
  case 3:
    uVar8 = *(uint *)(lVar6 + 0x18);
    uVar9 = (ulonglong)uVar8;
    if (0x13 < uVar8) {
      uVar16 = 0;
      _Dst = (ushort *)(lVar6 + 0x24);
      *(undefined2 *)(lVar6 + 0x20) = 0;
      lVar7 = *(longlong *)(param_1 + 0x9f8);
      uVar9 = (ulonglong)(uVar8 - 8) / 0xc;
      memset(_Dst,0xff,(ulonglong)(uVar8 - 8));
      if ((short)uVar9 != 0) {
        puVar15 = (ushort *)(lVar7 + 10);
        do {
          if (puVar15[-1] != 0) {
            *_Dst = puVar15[-1];
            uVar5 = *puVar15;
            _Dst[1] = uVar5;
            if ((puVar15[6] & 2) == 0) {
              uVar8 = uVar5 & 0x7f;
              uVar13 = (undefined1)(uVar5 >> 7);
            }
            else {
              uVar8 = 0xffff;
              uVar13 = 0xff;
            }
            *(undefined1 *)(_Dst + 4) = uVar13;
            *(uint *)(_Dst + 2) = uVar8;
            _Dst = _Dst + 6;
            *(short *)(lVar6 + 0x20) = *(short *)(lVar6 + 0x20) + 1;
            uVar9 = (ulonglong)(ushort)((short)uVar9 - 1);
          }
          uVar16 = uVar16 + 1;
        } while ((uVar16 <= *(ushort *)(param_1 + 0x372)) &&
                (puVar15 = puVar15 + 0xc, (short)uVar9 != 0));
      }
      if (*(ushort *)(lVar6 + 0x20) == 0) {
        iVar14 = 0x24;
      }
      else {
        iVar14 = (*(ushort *)(lVar6 + 0x20) + 3) * 0xc;
      }
      *(int *)(param_2 + 0x3c) = iVar14;
      *(undefined2 *)(lVar6 + 0x22) = *(undefined2 *)(lVar6 + 0x20);
      *(undefined2 *)(lVar6 + 0x20) = 0;
      uVar9 = *(ulonglong *)(param_1 + 0x9f8);
      if (*(short *)(param_1 + 0x372) != 0) {
        psVar11 = (short *)(uVar9 + 8);
        do {
          if (*psVar11 != 0) {
            *(short *)(lVar6 + 0x20) = *(short *)(lVar6 + 0x20) + 1;
          }
          uVar16 = (short)uVar17 + 1;
          uVar17 = (ulonglong)uVar16;
          psVar11 = psVar11 + 0xc;
        } while (uVar16 < *(ushort *)(param_1 + 0x372));
        return CONCAT71((int7)((ulonglong)psVar11 >> 8),1);
      }
LAB_1400096c7:
      return CONCAT71((int7)(uVar9 >> 8),1);
    }
    break;
  case 4:
    if (7 < *(uint *)(lVar6 + 0x18)) {
      uVar4 = *(undefined2 *)(param_1 + 0x8ec);
      *(undefined2 *)(lVar6 + 0x20) = uVar4;
      *(undefined4 *)(param_2 + 0x3c) = 0x24;
      return CONCAT71((uint7)(byte)((ushort)uVar4 >> 8),1);
    }
    break;
  default:
    goto switchD_1400094d1_caseD_5;
  case 9:
    if (*(uint *)(lVar6 + 0x18) < 8) break;
    local_res8[0] = *(byte *)(lVar6 + 0x22);
    uVar9 = 0;
    uVar16 = *(ushort *)(lVar6 + 0x20);
    if (local_res8[0] < 7) {
      bVar18 = *(byte *)(param_1 + 0x97e) <= local_res8[0];
      if (!bVar18) {
        *(byte *)(param_1 + 0x97e) = local_res8[0];
      }
      uVar5 = *(ushort *)(param_1 + 0x97c);
      uVar9 = (ulonglong)uVar5;
      if (uVar5 == uVar16) {
        if (bVar18) goto LAB_1400099bd;
      }
      else {
        *(ushort *)(param_1 + 0x97c) = uVar5 | uVar16;
      }
      if (*(char *)(param_1 + 0x9a4) != '\0') {
        uVar12 = PELAbort(param_1,param_3,param_4);
        *(undefined4 *)(param_2 + 0x3c) = 0x24;
        return CONCAT71((int7)((ulonglong)uVar12 >> 8),1);
      }
      uVar9 = PELGetSetSeqNumbers(param_1,param_3,param_4);
LAB_1400099bd:
      *(undefined4 *)(param_2 + 0x3c) = 0x24;
      return CONCAT71((int7)(uVar9 >> 8),1);
    }
    *(undefined4 *)(lVar6 + 0x14) = 0xfa14;
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x296) != 0)) {
      uVar9 = RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x296,local_res8,1,param_3,param_4);
      return uVar9 & 0xffffffffffffff00;
    }
    goto LAB_1400099db;
  }
  *(undefined4 *)(lVar6 + 0x14) = 0xfa02;
  return uVar9 & 0xffffffffffffff00;
}



===== StartIoctl @ 140009a10 =====

undefined8 StartIoctl(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  undefined8 uVar1;
  
  AcquireIsrLocks(param_1,(ulonglong)param_3,param_4);
  if (((*(int *)(param_1 + 0x428) == 0) && (*(char *)(param_1 + 0x417) == '\0')) &&
     (*(int *)(param_1 + 0x41c) == 0)) {
    MPI3HandleAppRequest(param_1,param_2,param_3,param_4);
    uVar1 = 1;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 5;
    StorPortNotification(0,param_1,param_2);
    uVar1 = 0;
  }
  ReleaseIsrLocks(param_1,param_3,param_4);
  return uVar1;
}



===== HexVersionToString @ 140009ab0 =====

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
      goto LAB_140009b0a;
    }
  }
  else {
    *param_2 = (char)((ulonglong)(uVar2 & 0xff) / 10) + '0';
LAB_140009b0a:
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
      goto LAB_140009b87;
    }
  }
  else {
    *pcVar3 = bStackX_a / 10 + 0x30;
LAB_140009b87:
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
      goto LAB_140009bfc;
    }
  }
  else {
    *pcVar4 = bStackX_11 / 10 + 0x30;
LAB_140009bfc:
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
    if (bVar1) goto LAB_140009c77;
    *pcVar3 = '0';
  }
  else {
    *pcVar3 = local_res10 / 10 + 0x30;
  }
  pcVar3 = pcVar3 + 1;
LAB_140009c77:
  *pcVar3 = local_res10 % 10 + 0x30;
  pcVar3[1] = '\0';
  return;
}



===== RttAddRecord @ 140009ca0 =====

void RttAddRecord(longlong *param_1,undefined4 *param_2,undefined4 param_3,undefined1 *param_4,
                 uint param_5,undefined4 *param_6)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  
  *param_2 = param_3;
  param_2[1] = param_5 + 0x14;
  StorPortQuerySystemTime(param_2 + 2);
  param_2[4] = *param_6;
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
  *(int *)((longlong)param_1 + 0x34) = *(int *)((longlong)param_1 + 0x34) + 1;
  param_1[4] = (longlong)puVar3;
  *(undefined4 *)(*param_1 + 0x48) = *(undefined4 *)((longlong)param_1 + 0x34);
  return;
}



===== RttFormatBuffer @ 140009d40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RttFormatBuffer(longlong param_1,longlong *param_2,ushort param_3,int *param_4)

{
  longlong lVar1;
  void *_Dst;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_78 [32];
  undefined2 local_58;
  undefined2 local_56;
  undefined4 local_54;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_78;
  AcquireIsrLocks(param_1,(ulonglong)param_3,param_4);
  _Dst = (void *)*param_2;
  param_2[5] = 0;
  param_2[1] = (ulonglong)*(uint *)(param_2 + 6) + (longlong)_Dst;
  lVar1 = (longlong)_Dst + 0x80;
  *(undefined4 *)((longlong)param_2 + 0x34) = 0;
  param_2[2] = lVar1;
  param_2[3] = lVar1;
  param_2[4] = lVar1;
  ZeroMemory(_Dst,0x80);
  memmove(_Dst,s_mpi3drv_sys_1400140cc,0x10);
  local_54 = 4;
  local_58 = 1;
  iVar3 = StorPortExtendedFunction(0x29,param_1,&local_58);
  if (iVar3 == 0) {
    *(undefined2 *)((longlong)_Dst + 0x10) = local_56;
  }
  memmove((void *)((longlong)_Dst + 0x20),"3.00.71.90",0xb);
  *(undefined1 *)((longlong)_Dst + 0x2b) = 0;
  HexVersionToString(*(uint *)(param_1 + 0x348),(char *)((longlong)_Dst + 0x30));
  *(undefined4 *)((longlong)_Dst + 0x40) = RttraceRecordVersion;
  *(int *)((longlong)_Dst + 0x44) = (int)param_2[6];
  *(undefined4 *)((longlong)_Dst + 0x60) = 0x61942f23;
  *(undefined4 *)((longlong)_Dst + 0x48) = *(undefined4 *)((longlong)param_2 + 0x34);
  *(undefined4 *)((longlong)_Dst + 100) = 0;
  *(undefined4 *)((longlong)_Dst + 0x4c) = *(undefined4 *)((longlong)param_2 + 0x3c);
  *(char *)((longlong)_Dst + 0x68) = (char)param_2[7];
  puVar2 = (undefined4 *)param_2[4];
  *puVar2 = 2;
  puVar2[1] = 0x14;
  StorPortQuerySystemTime(puVar2 + 2);
  puVar2[4] = *param_4;
  puVar2[5] = 0;
  puVar2[6] = 8;
  *(int *)((longlong)param_2 + 0x34) = *(int *)((longlong)param_2 + 0x34) + 1;
  param_2[4] = (longlong)(puVar2 + 5);
  *(undefined4 *)(*param_2 + 0x48) = *(undefined4 *)((longlong)param_2 + 0x34);
  ReleaseIsrLocks(param_1,param_3,param_4);
  return;
}



===== RttHandleIoctl @ 140009eb0 =====

undefined8 RttHandleIoctl(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  int iVar4;
  int *_Src;
  undefined4 uVar5;
  void *_Dst;
  undefined4 local_res8;
  undefined4 local_resc;
  
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined4 *)(param_2 + 0x1c) = RttraceRecordVersion;
  iVar4 = *(int *)(param_2 + 0x20);
  if (iVar4 == 1) {
    if (*(uint *)(param_2 + 0x18) < 0x48) {
LAB_14000a141:
      *(undefined4 *)(param_2 + 0x14) = 2;
      *(undefined4 *)(param_2 + 0x28) = 2;
      return 0;
    }
    *(undefined1 *)(param_2 + 0x3c) = *(undefined1 *)(param_1 + 0xc00);
    *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 0xc04);
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_1 + 0xbfc);
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0xbf8);
    *(undefined4 *)(param_2 + 0x60) = 0x61942f23;
    memmove((void *)(param_2 + 0x3d),"3.00.71.90",0xb);
    *(undefined1 *)(param_2 + 0x48) = 0;
    HexVersionToString(*(uint *)(param_1 + 0x348),(char *)(param_2 + 0x4d));
    *(undefined4 *)(param_2 + 0x2c) = 0x7f;
  }
  else if (iVar4 == 2) {
    if (*(uint *)(param_2 + 0x18) < 0x48) goto LAB_14000a141;
    uVar2 = *(uint *)(param_2 + 0x2c);
    if ((uVar2 & 4) != 0) {
      if ((*(uint *)(param_2 + 0x24) & 4) == 0) {
        uVar2 = uVar2 & 0xfffffffb;
        *(uint *)(param_2 + 0x2c) = uVar2;
      }
      else {
        RttFormatBuffer(param_1,(longlong *)(param_1 + 0xbc8),param_3,param_4);
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),5,(undefined1 *)0x0,0,param_3,param_4);
        uVar2 = *(uint *)(param_2 + 0x2c);
      }
    }
    if ((uVar2 & 1) != 0) {
      *(undefined1 *)(param_1 + 0xc00) = *(undefined1 *)(param_2 + 0x3c);
      *(undefined1 *)(*(longlong *)(param_1 + 0xbc8) + 0x68) = *(undefined1 *)(param_2 + 0x3c);
      if ((*(uint *)(param_2 + 0x24) & 4) != 0) {
        uVar5 = 4;
        if (*(char *)(param_2 + 0x3c) == '\0') {
          uVar5 = 3;
        }
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),uVar5,(undefined1 *)0x0,0,param_3,param_4)
        ;
      }
    }
    if ((*(uint *)(param_2 + 0x2c) & 2) != 0) {
      local_res8 = *(undefined4 *)(param_1 + 0xc04);
      local_resc = *(undefined4 *)(param_2 + 0x38);
      *(undefined4 *)(param_1 + 0xc04) = local_resc;
      *(undefined4 *)(*(longlong *)(param_1 + 0xbc8) + 0x4c) = *(undefined4 *)(param_2 + 0x38);
      if ((*(uint *)(param_2 + 0x24) & 4) != 0) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),6,(undefined1 *)&local_res8,8,param_3,
                    param_4);
      }
    }
  }
  else {
    if (iVar4 != 3) {
      if (iVar4 != 4) {
        *(undefined4 *)(param_2 + 0x14) = 1;
        return 0;
      }
      if (*(uint *)(param_2 + 0x18) < 0x90) {
        *(undefined4 *)(param_2 + 0x14) = 5;
        *(undefined4 *)(param_2 + 0x28) = 2;
        return 0;
      }
      memmove((void *)(param_2 + 0x2c),*(void **)(param_1 + 0xbc8),0x80);
      *(undefined8 *)(param_2 + 0x24) = 0;
      return 1;
    }
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x2c);
    if ((ulonglong)*(uint *)(param_2 + 0x18) < uVar3 + 0x14) {
      *(undefined4 *)(param_2 + 0x14) = 3;
      *(undefined4 *)(param_2 + 0x28) = 2;
      return 0;
    }
    if ((*(uint *)(param_2 + 0x24) & 1) == 0) {
      _Src = *(int **)(param_1 + 0xbf0);
    }
    else {
      _Src = *(int **)(param_1 + 0xbe0);
      *(int **)(param_1 + 0xbf0) = _Src;
      uVar3 = (ulonglong)*(uint *)(param_2 + 0x2c);
    }
    _Dst = (void *)(param_2 + 0x30);
    iVar4 = 0;
    uVar2 = (uint)uVar3;
    if ((uint)_Src[1] < uVar2) {
      do {
        uVar2 = (uint)uVar3;
        if (*_Src == 0) break;
        if (*_Src == 1) {
          _Src = *(int **)(param_1 + 0xbd8);
        }
        else {
          iVar4 = iVar4 + _Src[1];
          memmove(_Dst,_Src,(ulonglong)(uint)_Src[1]);
          _Dst = (void *)((longlong)_Dst + (ulonglong)(uint)_Src[1]);
          _Src = (int *)((longlong)_Src + (ulonglong)(uint)_Src[1]);
        }
        uVar2 = *(uint *)(param_2 + 0x2c);
        uVar3 = (ulonglong)uVar2;
      } while ((uint)_Src[1] < uVar2 - iVar4);
    }
    uVar1 = _Src[1];
    if ((uVar1 < uVar2 - iVar4) && (*_Src == 0)) {
      memmove(_Dst,_Src,(ulonglong)uVar1);
      *(undefined4 *)(param_2 + 0x24) = 2;
      *(undefined8 *)(param_1 + 0xbf0) = 0;
      *(uint *)(param_2 + 0x2c) = iVar4 + uVar1;
    }
    else {
      *(int **)(param_1 + 0xbf0) = _Src;
      *(undefined4 *)(param_2 + 0x24) = 0;
      *(int *)(param_2 + 0x2c) = iVar4;
    }
  }
  *(undefined4 *)(param_2 + 0x28) = 0;
  return 1;
}



===== RttInitTrace @ 14000a1e0 =====

void RttInitTrace(longlong param_1,longlong *param_2,ushort param_3,int *param_4)

{
  *(undefined4 *)((longlong)param_2 + 0x3c) = 0x3fbf00;
  RttFormatBuffer(param_1,param_2,param_3,param_4);
  return;
}



===== RttLogEvent @ 14000a1f0 =====

void RttLogEvent(longlong param_1,longlong *param_2,undefined4 param_3,undefined1 *param_4,
                uint param_5,ushort param_6,int *param_7)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  
  AcquireIsrLocks(param_1,(ulonglong)param_6,param_7);
  uVar1 = param_5 + 0x1c;
  if (uVar1 <= *(uint *)(param_2 + 6)) {
    uVar3 = param_2[3];
    uVar5 = param_2[4];
    if (uVar5 < uVar3) {
      do {
        do {
          if (uVar1 <= (uint)((int)uVar3 - (int)param_2[4])) goto LAB_14000a35a;
          uVar2 = *(uint *)(param_2[3] + 4);
          *(int *)((longlong)param_2 + 0x34) = *(int *)((longlong)param_2 + 0x34) + -1;
          param_2[3] = (ulonglong)uVar2 + param_2[3];
          *(undefined4 *)(*param_2 + 0x48) = *(undefined4 *)((longlong)param_2 + 0x34);
          *(int *)(*param_2 + 100) = (int)param_2[3] - (int)param_2[2];
          uVar3 = (ulonglong)param_2[3] & 0xffffffff;
        } while (*(int *)param_2[3] != 1);
        param_2[3] = param_2[2];
        *(undefined4 *)(*param_2 + 100) = 0;
        uVar3 = param_2[3] & 0xffffffff;
        uVar5 = param_2[4] & 0xffffffff;
      } while ((ulonglong)param_2[4] < (ulonglong)param_2[3]);
    }
    if (uVar1 < (uint)((int)param_2[1] - (int)uVar5)) {
LAB_14000a35a:
      puVar4 = (undefined4 *)param_2[4];
    }
    else {
      *(undefined4 *)param_2[4] = 1;
      *(undefined4 *)(param_2[4] + 4) = 8;
      uVar2 = (int)param_2[3] - (int)param_2[2];
      while (uVar2 < uVar1) {
        uVar2 = *(uint *)(param_2[3] + 4);
        *(int *)((longlong)param_2 + 0x34) = *(int *)((longlong)param_2 + 0x34) + -1;
        param_2[3] = (ulonglong)uVar2 + param_2[3];
        *(undefined4 *)(*param_2 + 0x48) = *(undefined4 *)((longlong)param_2 + 0x34);
        *(int *)(*param_2 + 100) = (int)param_2[3] - (int)param_2[2];
        uVar2 = (int)param_2[3] - (int)param_2[2];
      }
      puVar4 = (undefined4 *)param_2[2];
    }
    RttAddRecord(param_2,puVar4,param_3,param_4,param_5,param_7);
  }
  ReleaseIsrLocks(param_1,param_6,param_7);
  return;
}



===== RttSetTraceParameters @ 14000a360 =====

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



===== mpi3StartIo @ 14000a380 =====

undefined1 mpi3StartIo(longlong param_1,ushort *param_2)

{
  undefined8 *puVar1;
  short *psVar2;
  undefined1 uVar3;
  char cVar4;
  ushort uVar5;
  uint uVar6;
  longlong lVar7;
  short *psVar8;
  short *psVar9;
  short *psVar10;
  undefined1 uVar11;
  undefined8 uVar12;
  ushort uVar13;
  uint uVar14;
  longlong lVar15;
  ushort uVar16;
  bool bVar17;
  bool bVar18;
  int local_res8;
  undefined1 local_resc;
  ushort *local_res10;
  
  lVar7 = *(longlong *)(param_2 + 0x34);
  bVar18 = false;
  lVar15 = *(longlong *)(param_1 + 0x9d8);
  local_res8 = 6;
  local_resc = 0;
  if ((char)param_2[1] != '(') {
    *(undefined1 *)((longlong)param_2 + 3) = 0x22;
LAB_14000a3c6:
    StorPortNotification(0,param_1,param_2);
    return 0;
  }
  uVar11 = *(undefined1 *)(lVar7 + 0x4a);
  uVar3 = *(undefined1 *)(lVar7 + 0x4c);
  cVar4 = *(char *)(lVar7 + 0x48);
  switch(*(undefined4 *)(param_2 + 10)) {
  case 0:
    if ((*(char *)(param_1 + 0xad8) == '\0') ||
       (*(undefined1 *)(param_1 + 0xad8) = 0, cVar4 != '\x03')) {
      if ((*(int *)(param_1 + 0x428) == 0) && (*(char *)(param_1 + 0x417) == '\0')) {
        do {
          uVar6 = *(uint *)(param_1 + 0xae8);
          uVar13 = *(ushort *)(*(longlong *)(param_1 + 0x9e8) + (ulonglong)uVar6 * 4);
          if (*(longlong *)(*(longlong *)(param_1 + 0x9f0) + (ulonglong)uVar13 * 0x18) != 0) {
            StorPortBusy(param_1);
            if (*(char *)(param_1 + 0x9a8) != '\0') {
              LogSystemEvent(param_1,0,0x4004af00,
                             (byte *)"returning an IO with BUSY, no IOC credits",0,&local_res8);
            }
            goto LAB_14000a75b;
          }
          uVar14 = 0;
          if (uVar6 + 1 != *(uint *)(param_1 + 0xaf0)) {
            uVar14 = uVar6 + 1;
          }
          LOCK();
          bVar17 = uVar6 == *(uint *)(param_1 + 0xae8);
          if (bVar17) {
            *(uint *)(param_1 + 0xae8) = uVar14;
          }
          UNLOCK();
        } while (!bVar17);
        if (uVar13 != 0) {
          puVar1 = (undefined8 *)(*(longlong *)(param_1 + 0x9f0) + (ulonglong)uVar13 * 0x18);
          local_res10 = (ushort *)(lVar7 + 0x60);
          *puVar1 = param_2;
          *(undefined1 *)((longlong)puVar1 + 10) = uVar11;
          *local_res10 = uVar13;
          *(undefined2 *)((longlong)puVar1 + 0xc) = *(undefined2 *)(lVar7 + 0x6a);
          *(undefined1 *)((longlong)puVar1 + 0xe) = uVar3;
          *(char *)((longlong)puVar1 + 0xf) = (char)param_2[0x10];
          uVar13 = *(ushort *)(lVar15 + 6 + (ulonglong)*(ushort *)(lVar7 + 0x52) * 8);
          psVar2 = (short *)(lVar15 + (ulonglong)*(ushort *)(lVar7 + 0x52) * 8);
LAB_14000a594:
          if ((uVar13 == 0) || (bVar18)) {
            uVar5 = *(ushort *)(param_1 + 0x298);
            psVar8 = *(short **)(param_1 + 0x9d8);
            if (uVar13 != 0) {
              if ((!bVar18) || (uVar13 = uVar13 - 1, uVar13 == 0)) {
LAB_14000a75b:
                *(undefined1 *)((longlong)param_2 + 3) = 5;
                StorPortNotification(0,param_1,param_2);
                return 1;
              }
              goto LAB_14000a661;
            }
            if (*(short *)(lVar7 + 0x50) == *psVar2) {
LAB_14000a601:
              psVar9 = psVar2;
              do {
                psVar10 = psVar2;
                if ((psVar8 + (ulonglong)uVar5 * 4 <= psVar9 + 4) || (psVar9[5] != psVar2[1]))
                goto joined_r0x00014000a62f;
                uVar13 = psVar9[7];
                psVar9 = psVar9 + 4;
              } while (uVar13 == 0);
            }
            else {
              uVar13 = 0;
              if (uVar5 != 0) {
                do {
                  if (psVar8[(ulonglong)uVar13 * 4] == *(short *)(lVar7 + 0x50)) break;
                  uVar13 = uVar13 + 1;
                } while (uVar13 < uVar5);
              }
              if (((uVar13 == uVar5) || (psVar8 == psVar2)) || (uVar13 = psVar8[3], uVar13 == 0))
              goto LAB_14000a601;
            }
            goto LAB_14000a5fa;
          }
          goto LAB_14000a661;
        }
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x28f) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x28f,(undefined1 *)0x0,0,0,&local_res8)
          ;
        }
        LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                            "Kill Adapter (Driver) - Host Tag 0 Generated",0,&local_res8);
        KillAdapter(param_1,0xf,0,&local_res8);
        *(undefined1 *)((longlong)param_2 + 3) = 10;
        goto LAB_14000a3c6;
      }
      *(undefined1 *)((longlong)param_2 + 3) = 5;
      if (*(char *)(param_1 + 0x417) == '\0') {
        if (*(char *)(param_1 + 0x418) == '\0') {
          *(undefined1 *)(param_1 + 0x418) = 1;
        }
      }
      else {
        *(undefined1 *)((longlong)param_2 + 3) = 0x11;
      }
    }
    else {
      memmove(*(void **)(param_2 + 0x20),*(void **)(param_1 + 0xae0),
              (ulonglong)*(uint *)(param_2 + 0x1e));
      *(undefined1 *)((longlong)param_2 + 3) = 1;
      *(undefined1 *)(*(longlong *)(lVar7 + 0x30) + 8) = 0;
    }
    goto LAB_14000a8fc;
  default:
switchD_14000a411_caseD_1:
    *(undefined1 *)((longlong)param_2 + 3) = 0x22;
LAB_14000a8fc:
    StorPortNotification(0,param_1,param_2);
LAB_14000a909:
    uVar11 = 1;
    break;
  case 2:
    LOCK();
    bVar18 = *(int *)(param_1 + 0x43c) == 0;
    if (bVar18) {
      *(int *)(param_1 + 0x43c) = 1;
    }
    UNLOCK();
    if (!bVar18) {
      *(undefined1 *)((longlong)param_2 + 3) = 5;
      StorPortNotification(0,param_1,param_2);
      return 1;
    }
    uVar12 = StartIoctl(param_1,(longlong)param_2,0,&local_res8);
    uVar11 = (undefined1)uVar12;
    break;
  case 0x13:
  case 0x20:
    AcquireIsrLocks(param_1,0,&local_res8);
    uVar12 = LunTargetReset(param_1,(longlong)param_2,0,&local_res8);
    uVar11 = (undefined1)uVar12;
    ReleaseIsrLocks(param_1,0,&local_res8);
    break;
  case 0x17:
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x404) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x404,(undefined1 *)param_2,0x80,0,
                  &local_res8);
    }
    uVar12 = mpi3WmiSrb(param_1,param_2,0,&local_res8);
    uVar11 = (undefined1)uVar12;
    break;
  case 0x24:
    lVar15 = *(longlong *)(lVar7 + 0x38);
    if ((*(int *)(lVar15 + 0x10) - 4U < 2) || (*(int *)(lVar15 + 0x10) == 6)) {
      *(undefined1 *)(param_1 + 0x8cc) = 1;
      lVar15 = *(longlong *)(lVar7 + 0x38);
    }
    if (*(int *)(lVar15 + 0xc) != 4) goto switchD_14000a411_caseD_1;
    if (*(int *)(param_1 + 0x8c8) != 0) {
      return 6;
    }
    *(ushort **)(param_1 + 0x8e0) = param_2;
    *(undefined8 *)(param_1 + 0x8c4) = 6;
    StartShutdown(param_1,0,&local_res8);
    goto LAB_14000a909;
  }
  return uVar11;
  while (uVar13 = psVar10[-1], psVar10 = psVar10 + -4, uVar13 == 0) {
joined_r0x00014000a62f:
    if ((psVar10 + -4 < psVar8) || (psVar10[-3] != psVar2[1])) {
      uVar13 = 1;
      goto LAB_14000a661;
    }
  }
LAB_14000a5fa:
  psVar2[3] = uVar13;
LAB_14000a661:
  lVar15 = (ulonglong)uVar13 * 0x20 + *(longlong *)(param_1 + 0xa10);
  do {
    LOCK();
    bVar18 = *(int *)(lVar15 + 0x14) == 0;
    if (bVar18) {
      *(int *)(lVar15 + 0x14) = 1;
    }
    UNLOCK();
  } while (!bVar18);
  uVar5 = *(ushort *)(lVar15 + 0x18);
  if (((uint)*(ushort *)(lVar15 + 0x1a) != uVar5 + 1) &&
     ((*(ushort *)(lVar15 + 0x1a) != 0 || ((uint)uVar5 != *(ushort *)(param_1 + 0x35c) - 1)))) {
    lVar7 = *(longlong *)(lVar15 + 8);
    LOCK();
    *(int *)(param_1 + 0x8e8) = *(int *)(param_1 + 0x8e8) + 1;
    UNLOCK();
    memmove((void *)(lVar7 + (longlong)(int)((uint)*(ushort *)(param_1 + 0x36c) * (uint)uVar5) * 4),
            local_res10,(ulonglong)*(ushort *)(param_1 + 0x36a));
    uVar16 = 0;
    if ((ushort)(uVar5 + 1) != *(ushort *)(param_1 + 0x35c)) {
      uVar16 = uVar5 + 1;
    }
    *(ushort *)(lVar15 + 0x18) = uVar16;
    *(uint *)(*(longlong *)(param_1 + 0x98) + -8 + (ulonglong)uVar13 * 8) = (uint)uVar16;
    LOCK();
    UNLOCK();
    LOCK();
    *(int *)(lVar15 + 0x14) = *(int *)(lVar15 + 0x14) + -1;
    UNLOCK();
    *(undefined1 *)(param_1 + 0x418) = 0;
    return 1;
  }
  LOCK();
  *(int *)(lVar15 + 0x14) = *(int *)(lVar15 + 0x14) + -1;
  UNLOCK();
  bVar18 = true;
  goto LAB_14000a594;
}



===== AcquireIsrLocks @ 14000a970 =====

void AcquireIsrLocks(longlong param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  bool bVar4;
  
  if (((*(char *)(param_1 + 0x408) == '\0') && (*(char *)(param_1 + 0x411) != '\0')) &&
     (iVar1 = param_3[1], *(char *)(param_3 + 1) = (char)iVar1 + '\x01', (char)iVar1 == '\0')) {
    if (*param_3 == 0xc) {
      do {
        LOCK();
        bVar4 = *(int *)(param_1 + 0xb68) == 0;
        if (bVar4) {
          *(int *)(param_1 + 0xb68) = 1;
        }
        UNLOCK();
      } while (!bVar4);
      return;
    }
    uVar3 = 0;
    if (*(int *)(param_1 + 0x3c8) != 0) {
      do {
        StorPortExtendedFunction(0xb,param_1,uVar3,*(longlong *)(param_1 + 0xb70) + uVar3 * 4);
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(param_1 + 0x3c8));
    }
  }
  return;
}



===== ReleaseIsrLocks @ 14000aa10 =====

void ReleaseIsrLocks(longlong param_1,ushort param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  
  if ((*(char *)(param_1 + 0x408) == '\0') && (*(char *)(param_1 + 0x411) != '\0')) {
    piVar1 = param_3 + 1;
    *(char *)piVar1 = (char)*piVar1 + -1;
    if ((char)*piVar1 == '\0') {
      if (*param_3 == 0xc) {
        iVar2 = 1;
        LOCK();
        iVar4 = *(int *)(param_1 + 0xb68);
        if (iVar4 == 1) {
          *(int *)(param_1 + 0xb68) = 0;
        }
        else {
          iVar2 = iVar4;
        }
        UNLOCK();
        if (((iVar2 == 0) && (*(char *)(param_1 + 0xc00) != '\0')) &&
           ((*(uint *)(param_1 + 0xc04) & 0x24e) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x24e,(undefined1 *)0x0,0,param_2,
                      param_3);
          return;
        }
      }
      else {
        iVar4 = *(int *)(param_1 + 0x3c8) + -1;
        if (-1 < iVar4) {
          lVar3 = (longlong)iVar4 * 4;
          do {
            StorPortExtendedFunction
                      (0xc,param_1,iVar4,*(undefined4 *)(*(longlong *)(param_1 + 0xb70) + lVar3));
            iVar4 = iVar4 + -1;
            lVar3 = lVar3 + -4;
          } while (-1 < iVar4);
        }
      }
    }
  }
  return;
}



===== CallStorPortLogSystemEvent @ 14000ab10 =====

void CallStorPortLogSystemEvent(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  undefined4 local_res8 [2];
  int local_res10 [2];
  longlong local_78 [2];
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined1 local_4c;
  undefined4 local_48;
  undefined4 local_40;
  longlong local_38;
  undefined4 local_30;
  longlong *local_28;
  
  local_res8[0] = 0;
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
  local_res10[0] = StorPortExtendedFunction(0x10,param_1,&local_68,local_res8);
  if (((local_res10[0] != 0) && (*(char *)(param_1 + 0xc00) != '\0')) &&
     ((*(uint *)(param_1 + 0xc04) & 0x26c) != 0)) {
    RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x26c,(undefined1 *)local_res10,4,param_3,
                param_4);
  }
  return;
}



===== InitSysLogErrorFIFO @ 14000ac30 =====

void InitSysLogErrorFIFO(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0xaf8);
  *(longlong *)(param_1 + 0xb08) = lVar1;
  *(longlong *)(param_1 + 0xb10) = lVar1;
  *(longlong *)(param_1 + 0xb00) = lVar1 + 0x1400;
  return;
}



===== LogOperationalEvent @ 14000ac60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LogOperationalEvent(longlong param_1,int *param_2,int param_3,undefined4 param_4,char *param_5,
                        ushort param_6,int *param_7)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  undefined1 auStackY_498 [32];
  int local_458 [4];
  ushort local_448 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_498;
  iVar3 = 0;
  local_458[1] = 0;
  if ((param_3 == 0) || (param_2 == (int *)0x0)) {
    param_2 = local_458 + 1;
  }
  bVar2 = 0;
  local_448[0] = (ushort)(byte)*param_5;
  uVar1 = local_448[0];
  do {
    if (uVar1 == 0) {
LAB_14000acf4:
      local_458[0] = StorPortExtendedFunction(0x62,param_1,0);
      if (local_458[0] != 0) {
        if (local_458[0] == -0x3efffffe) {
          if (param_2 != (int *)0x0) {
            iVar3 = *param_2;
          }
        }
        else {
          if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x27a) != 0)) {
            RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x27a,(undefined1 *)local_458,4,
                        param_6,param_7);
          }
          param_5 = "StorPortEtwLogError API failed,it\'s RetCode logged";
          param_4 = 0x8004af01;
          iVar3 = local_458[0];
        }
        LogSystemEvent(param_1,iVar3,param_4,(byte *)param_5,param_6,param_7);
      }
      return;
    }
    bVar2 = bVar2 + 1;
    if (bVar2 == 0x48) {
      local_448[bVar2] = 0;
      goto LAB_14000acf4;
    }
    uVar1 = (ushort)(byte)param_5[bVar2];
    local_448[bVar2] = uVar1;
  } while( true );
}



===== LogSystemEvent @ 14000ade0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LogSystemEvent(longlong param_1,undefined4 param_2,undefined4 param_3,byte *param_4,
                   ushort param_5,int *param_6)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 auStackY_188 [32];
  undefined4 local_138;
  undefined4 local_134;
  ushort local_130 [123];
  byte local_3a;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_188;
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
        bVar1 = param_4[local_3a];
        local_130[local_3a] = (ushort)bVar1;
      } while (bVar1 != 0);
    }
  }
  local_138 = param_2;
  local_134 = param_3;
  if ((*(char *)(param_1 + 0x411) == '\0') && (*param_6 != 0x10)) {
    CallStorPortLogSystemEvent(param_1,(longlong)&local_138,param_5,param_6);
  }
  else {
    AcquireIsrLocks(param_1,(ulonglong)param_5,param_6);
    puVar2 = *(undefined4 **)(param_1 + 0xb08);
    puVar3 = puVar2 + 0x40;
    if (puVar3 == *(undefined4 **)(param_1 + 0xb00)) {
      puVar3 = *(undefined4 **)(param_1 + 0xaf8);
    }
    if (puVar3 == *(undefined4 **)(param_1 + 0xb10)) {
      *(undefined1 *)(param_1 + 0xb18) = 1;
      ReleaseIsrLocks(param_1,param_5,param_6);
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x114) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x114,(undefined1 *)0x0,0,param_5,param_6)
        ;
      }
    }
    else {
      *puVar2 = local_138;
      puVar2[1] = local_134;
      *(byte *)((longlong)puVar2 + 0xfe) = local_3a;
      memmove(puVar2 + 2,local_130,0xf6);
      *(undefined4 **)(param_1 + 0xb08) = puVar3;
      ReleaseIsrLocks(param_1,param_5,param_6);
      if (*param_6 != 0x10) {
        StorPortNotification(0x1002,param_1,param_1 + 0xb20,param_1);
      }
    }
  }
  return;
}



===== SystemEventLoggerDpc @ 14000aff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SystemEventLoggerDpc(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined1 auStack_188 [32];
  longlong local_168;
  undefined4 *local_160;
  int local_158;
  undefined1 local_154;
  undefined4 local_150 [2];
  longlong local_148;
  longlong local_140;
  longlong local_138 [2];
  undefined4 local_128;
  undefined4 local_124;
  ushort local_120 [123];
  byte local_2a;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_188;
  local_158 = 3;
  local_154 = 0;
  StorPortExtendedFunction(0x2f,param_2,local_138,&local_140);
  do {
    AcquireIsrLocks(param_2,0,&local_158);
    if (*(char *)(param_2 + 0xb18) == '\0') {
      puVar2 = *(undefined4 **)(param_2 + 0xb10);
      if (puVar2 == *(undefined4 **)(param_2 + 0xb08)) {
        ReleaseIsrLocks(param_2,0,&local_158);
        return;
      }
      ZeroMemory(&local_128,0x100);
      local_128 = *puVar2;
      local_124 = puVar2[1];
      local_2a = *(byte *)((longlong)puVar2 + 0xfe);
      memmove(local_120,puVar2 + 2,0xf6);
      *(longlong *)(param_2 + 0xb10) = *(longlong *)(param_2 + 0xb10) + 0x100;
      if (*(longlong *)(param_2 + 0xb10) == *(longlong *)(param_2 + 0xb00)) {
        *(undefined8 *)(param_2 + 0xb10) = *(undefined8 *)(param_2 + 0xaf8);
      }
    }
    else {
      ZeroMemory(&local_128,0x100);
      local_2a = 0;
      local_128 = 0;
      local_124 = 0x8004af01;
      local_120[0] = 0x53;
      do {
        local_2a = local_2a + 1;
        if (local_2a == 0x48) {
          local_120[local_2a] = 0;
          *(undefined1 *)(param_2 + 0xb18) = 0;
          goto LAB_14000b15c;
        }
        bVar1 = "System Log Event dropped"[local_2a];
        local_120[local_2a] = (ushort)bVar1;
      } while (bVar1 != 0);
      *(undefined1 *)(param_2 + 0xb18) = 0;
    }
LAB_14000b15c:
    ReleaseIsrLocks(param_2,0,&local_158);
    CallStorPortLogSystemEvent(param_2,(longlong)&local_128,0,&local_158);
    StorPortExtendedFunction(0x2f,param_2,0,&local_148);
    if (99 < ((local_148 - local_140) / local_138[0]) * 1000000) {
      local_160 = local_150;
      local_150[0] = 0;
      local_168 = param_2;
      StorPortNotification(0x1002,param_2,param_2 + 0xb20,param_2);
      return;
    }
  } while( true );
}



===== LitInit @ 14000b220 =====

void LitInit(longlong param_1,ushort param_2,int *param_3)

{
  int local_res8 [2];
  
  *(undefined8 *)(param_1 + 0xc08) = 0;
  *(undefined8 *)(param_1 + 0xc10) = 0;
  *(undefined8 *)(param_1 + 0xc18) = 0;
  *(undefined8 *)(param_1 + 0xc20) = 0;
  *(undefined8 *)(param_1 + 0xc28) = 0;
  *(undefined8 *)(param_1 + 0xc30) = 0;
  *(undefined8 *)(param_1 + 0xc38) = 0;
  *(undefined8 *)(param_1 + 0xc40) = 0;
  *(undefined8 *)(param_1 + 0xc48) = 0;
  *(undefined8 *)(param_1 + 0xc50) = 0;
  *(undefined8 *)(param_1 + 0xc58) = 0;
  *(undefined8 *)(param_1 + 0xc60) = 0;
  *(undefined8 *)(param_1 + 0xc68) = 0;
  *(undefined8 *)(param_1 + 0xc70) = 0;
  *(undefined8 *)(param_1 + 0xc78) = 0;
  *(undefined1 *)(param_1 + 0xc80) = 0;
  local_res8[0] = StorPortExtendedFunction(0x20,param_1,param_1 + 0xc88);
  if (local_res8[0] != 0) {
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x27b) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x27b,(undefined1 *)local_res8,4,param_2,
                  param_3);
    }
    LogOperationalEvent(param_1,local_res8,4,0x8004af01,
                        "LogInfo Timer Init Failed, Return Status Logged",param_2,param_3);
  }
  return;
}



===== LitLogInfoReceived @ 14000b350 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LitLogInfoReceived(longlong param_1,int param_2,undefined2 param_3,undefined1 param_4,
                       undefined1 param_5,undefined1 param_6,ushort param_7,int *param_8)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint *puVar8;
  ulonglong uVar9;
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
  piVar5 = (int *)(param_1 + 0xc08);
  local_3f = param_5;
  local_3e = param_6;
  uVar3 = 0;
  do {
    local_48 = param_2;
    local_40 = param_4;
    local_3c = param_3;
    if (*piVar5 == param_2) {
      uVar6 = (ulonglong)uVar3;
      *(undefined4 *)(param_1 + 0xc10 + uVar6 * 0xc) = 0;
      iVar2 = *(int *)(param_1 + 0xc0c + uVar6 * 0xc);
      if (iVar2 == -1) {
        return;
      }
      local_44 = iVar2 + 1;
      *(uint *)(param_1 + 0xc0c + uVar6 * 0xc) = local_44;
      if (local_44 < 6) {
        pcVar4 = "LogInfo";
      }
      else {
        if ((local_44 != 1000) && (local_44 != (local_44 / 10000) * 10000)) {
          return;
        }
        pcVar4 = "LogInfo(BABBLING)";
      }
      LogOperationalEvent(param_1,&local_48,0x10,0x4004af00,pcVar4,param_7,param_8);
      return;
    }
    uVar3 = uVar3 + 1;
    piVar5 = piVar5 + 3;
  } while (uVar3 < 10);
  puVar8 = (uint *)(param_1 + 0xc10);
  uVar9 = 0;
  uVar6 = 0;
  do {
    if (puVar8[-2] == 0) goto LAB_14000b432;
    uVar7 = uVar9;
    if (*puVar8 <= *(uint *)(param_1 + 0xc10 + uVar6 * 0xc)) {
      uVar7 = uVar6;
    }
    uVar3 = (int)uVar9 + 1;
    uVar9 = (ulonglong)uVar3;
    puVar8 = puVar8 + 3;
    uVar6 = uVar7;
  } while (uVar3 < 10);
  lVar1 = param_1 + uVar7 * 0xc;
  *(undefined4 *)(lVar1 + 0xc08) = 0;
  *(undefined4 *)(param_1 + 0xc0c + uVar7 * 0xc) = 0;
  *(undefined4 *)(lVar1 + 0xc10) = 0;
  uVar9 = uVar7;
LAB_14000b432:
  *(int *)(param_1 + 0xc08 + uVar9 * 0xc) = param_2;
  piVar5 = (int *)(param_1 + 0xc0c + uVar9 * 0xc);
  *piVar5 = *piVar5 + 1;
  local_44 = *(undefined4 *)(param_1 + 0xc0c + uVar9 * 0xc);
  LogOperationalEvent(param_1,&local_48,0x10,0x4004af00,"LogInfo received",param_7,param_8);
  if (*(char *)(param_1 + 0xc80) == '\0') {
    *(undefined1 *)(param_1 + 0xc80) = 1;
    StorPortExtendedFunction
              (0x21,param_1,*(undefined8 *)(param_1 + 0xc88),LitServiceActiveListCallback);
  }
  return;
}



===== LitServiceActiveListCallback @ 14000b5a0 =====

void LitServiceActiveListCallback(longlong param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (*(int *)(param_1 + 0xc08) != 0) {
    *(int *)(param_1 + 0xc10) = *(int *)(param_1 + 0xc10) + 10;
    if (*(uint *)(param_1 + 0xc10) < 0xe10) {
      bVar1 = true;
    }
    else {
      *(undefined8 *)(param_1 + 0xc08) = 0;
      *(undefined4 *)(param_1 + 0xc10) = 0;
    }
  }
  if (*(int *)(param_1 + 0xc14) != 0) {
    *(int *)(param_1 + 0xc1c) = *(int *)(param_1 + 0xc1c) + 10;
    if (*(uint *)(param_1 + 0xc1c) < 0xe10) {
      bVar1 = true;
    }
    else {
      *(undefined8 *)(param_1 + 0xc14) = 0;
      *(undefined4 *)(param_1 + 0xc1c) = 0;
    }
  }
  if (*(int *)(param_1 + 0xc20) != 0) {
    *(int *)(param_1 + 0xc28) = *(int *)(param_1 + 0xc28) + 10;
    if (*(uint *)(param_1 + 0xc28) < 0xe10) {
      bVar1 = true;
    }
    else {
      *(undefined8 *)(param_1 + 0xc20) = 0;
      *(undefined4 *)(param_1 + 0xc28) = 0;
    }
  }
  if (*(int *)(param_1 + 0xc2c) != 0) {
    *(int *)(param_1 + 0xc34) = *(int *)(param_1 + 0xc34) + 10;
    if (*(uint *)(param_1 + 0xc34) < 0xe10) {
      bVar1 = true;
    }
    else {
      *(undefined8 *)(param_1 + 0xc2c) = 0;
      *(undefined4 *)(param_1 + 0xc34) = 0;
    }
  }
  if (*(int *)(param_1 + 0xc38) != 0) {
    *(int *)(param_1 + 0xc40) = *(int *)(param_1 + 0xc40) + 10;
    if (*(uint *)(param_1 + 0xc40) < 0xe10) {
      bVar1 = true;
    }
    else {
      *(undefined8 *)(param_1 + 0xc38) = 0;
      *(undefined4 *)(param_1 + 0xc40) = 0;
    }
  }
  if (*(int *)(param_1 + 0xc44) != 0) {
    *(int *)(param_1 + 0xc4c) = *(int *)(param_1 + 0xc4c) + 10;
    if (*(uint *)(param_1 + 0xc4c) < 0xe10) {
      bVar1 = true;
    }
    else {
      *(undefined8 *)(param_1 + 0xc44) = 0;
      *(undefined4 *)(param_1 + 0xc4c) = 0;
    }
  }
  if (*(int *)(param_1 + 0xc50) != 0) {
    *(int *)(param_1 + 0xc58) = *(int *)(param_1 + 0xc58) + 10;
    if (*(uint *)(param_1 + 0xc58) < 0xe10) {
      bVar1 = true;
    }
    else {
      *(undefined8 *)(param_1 + 0xc50) = 0;
      *(undefined4 *)(param_1 + 0xc58) = 0;
    }
  }
  if (*(int *)(param_1 + 0xc5c) != 0) {
    *(int *)(param_1 + 0xc64) = *(int *)(param_1 + 0xc64) + 10;
    if (*(uint *)(param_1 + 0xc64) < 0xe10) {
      bVar1 = true;
    }
    else {
      *(undefined8 *)(param_1 + 0xc5c) = 0;
      *(undefined4 *)(param_1 + 0xc64) = 0;
    }
  }
  if (*(int *)(param_1 + 0xc68) != 0) {
    *(int *)(param_1 + 0xc70) = *(int *)(param_1 + 0xc70) + 10;
    if (*(uint *)(param_1 + 0xc70) < 0xe10) {
      bVar1 = true;
    }
    else {
      *(undefined8 *)(param_1 + 0xc68) = 0;
      *(undefined4 *)(param_1 + 0xc70) = 0;
    }
  }
  if (*(int *)(param_1 + 0xc74) != 0) {
    *(int *)(param_1 + 0xc7c) = *(int *)(param_1 + 0xc7c) + 10;
    if (*(uint *)(param_1 + 0xc7c) < 0xe10) goto LAB_14000b775;
    *(undefined8 *)(param_1 + 0xc74) = 0;
    *(undefined4 *)(param_1 + 0xc7c) = 0;
  }
  if (!bVar1) {
    *(undefined1 *)(param_1 + 0xc80) = 0;
    return;
  }
LAB_14000b775:
  *(undefined1 *)(param_1 + 0xc80) = 1;
  StorPortExtendedFunction
            (0x21,param_1,*(undefined8 *)(param_1 + 0xc88),LitServiceActiveListCallback,0,10000000,
             100000);
  return;
}



===== AdminQueueRequestPost @ 14000b7d0 =====

ulonglong AdminQueueRequestPost(longlong param_1,void *param_2,ushort param_3,int *param_4)

{
  ushort uVar1;
  short *psVar2;
  ulonglong uVar3;
  short sVar4;
  bool bVar5;
  
  do {
    LOCK();
    bVar5 = *(int *)(param_1 + 0x2dc) == 0;
    if (bVar5) {
      *(int *)(param_1 + 0x2dc) = 1;
    }
    UNLOCK();
  } while (!bVar5);
  uVar1 = *(ushort *)(param_1 + 0x2ac);
  if (((uint)*(ushort *)(param_1 + 0x2ae) == uVar1 + 1) ||
     ((*(ushort *)(param_1 + 0x2ae) == 0 && ((uint)uVar1 == *(ushort *)(param_1 + 0x2a0) - 1)))) {
    LOCK();
    *(int *)(param_1 + 0x2dc) = *(int *)(param_1 + 0x2dc) + -1;
    UNLOCK();
    uVar3 = LogSystemEvent(param_1,0,0xc004af02,
                           (byte *)"AdminQueueRequestPost Failed: Admin queue is full",param_3,
                           param_4);
    *(undefined4 *)(param_1 + 0x20) = 0xc;
    return uVar3 & 0xffffffffffffff00;
  }
  memmove((void *)((ulonglong)uVar1 * 0x80 + *(longlong *)(param_1 + 0x2c8)),param_2,0x80);
  sVar4 = 0;
  if ((ushort)(uVar1 + 1) != *(short *)(param_1 + 0x2a0)) {
    sVar4 = uVar1 + 1;
  }
  *(short *)(param_1 + 0x2ac) = sVar4;
  psVar2 = *(short **)(param_1 + 0x78);
  *psVar2 = sVar4;
  LOCK();
  UNLOCK();
  LOCK();
  *(int *)(param_1 + 0x2dc) = *(int *)(param_1 + 0x2dc) + -1;
  UNLOCK();
  return CONCAT71((int7)((ulonglong)psVar2 >> 8),1);
}



===== BuildFireTM @ 14000b8c0 =====

ulonglong BuildFireTM(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  short sVar1;
  longlong lVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  ushort uVar5;
  undefined4 local_res8;
  short local_resc;
  
  lVar2 = *(longlong *)(param_2 + 0x68);
  uVar5 = (ushort)*(byte *)(lVar2 + 0x4a) * 0x80 + (ushort)*(byte *)(lVar2 + 0x4b);
  if ((uVar5 < *(ushort *)(param_1 + 0x372)) &&
     (sVar1 = *(short *)(*(longlong *)(param_1 + 0x9f8) + 8 + (ulonglong)uVar5 * 0x18), sVar1 != 0))
  {
    *(longlong *)(param_1 + 0x450) = param_2;
    ZeroMemory((void *)(lVar2 + 0x60),0x20);
    *(undefined1 *)(lVar2 + 99) = 0x21;
    *(undefined2 *)(lVar2 + 0x60) = 0xadb1;
    *(short *)(lVar2 + 0x6a) = sVar1;
    local_res8._0_1_ = *(undefined1 *)(lVar2 + 0x4a);
    local_res8._1_1_ = *(undefined1 *)(lVar2 + 0x4b);
    local_res8._2_1_ = *(undefined1 *)(lVar2 + 0x4c);
    local_resc = sVar1;
    if (*(int *)(param_2 + 0x14) == 0x13) {
      LogOperationalEvent(param_1,&local_res8,6,0x4004af00,
                          "Device Reset (OS) - Device Reset SRB received, sent to HBA",param_3,
                          param_4);
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x20006) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x20006,(undefined1 *)&local_res8,6,
                    param_3,param_4);
      }
      *(undefined1 *)(lVar2 + 0x6e) = 3;
    }
    else if (*(int *)(param_2 + 0x14) == 0x20) {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x20007) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x20007,(undefined1 *)&local_res8,6,
                    param_3,param_4);
      }
      LogOperationalEvent(param_1,&local_res8,6,0x4004af00,
                          "LUN Reset (OS) - LUN Reset SRB received, sent to HBA",param_3,param_4);
      *(undefined1 *)(lVar2 + 0x79) = *(undefined1 *)(lVar2 + 0x4c);
      *(undefined1 *)(lVar2 + 0x6e) = 5;
    }
    uVar4 = AdminQueueRequestPost(param_1,(void *)(lVar2 + 0x60),param_3,param_4);
    if ((char)uVar4 != '\0') {
      return CONCAT71((int7)(uVar4 >> 8),1);
    }
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x27c) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x27c,(undefined1 *)&local_res8,6,param_3,
                  param_4);
    }
    LogOperationalEvent(param_1,&local_res8,6,0xc004af02,
                        "TM Reset (OS) - TM Reset Queue Full, SRB Failed back to OS",param_3,param_4
                       );
    uVar3 = 4;
  }
  else {
    uVar3 = 10;
  }
  *(undefined1 *)(param_2 + 3) = uVar3;
  uVar4 = StorPortNotification(0,param_1,param_2);
  if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x20012) != 0)) {
    uVar4 = RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x20012,(undefined1 *)0x0,0,param_3,
                        param_4);
  }
  *(undefined8 *)(param_1 + 0x450) = 0;
  return uVar4 & 0xffffffffffffff00;
}



===== CheckTMQueue @ 14000bb80 =====

ulonglong CheckTMQueue(longlong param_1,ushort param_2,int *param_3)

{
  byte bVar1;
  longlong lVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  char cVar4;
  
  if (*(longlong *)(param_1 + 0x450) == 0) {
    bVar1 = *(byte *)(param_1 + 0x779);
    lVar2 = *(longlong *)(param_1 + 0x458 + (ulonglong)bVar1 * 8);
    if (lVar2 != 0) {
      *(undefined8 *)(param_1 + 0x458 + (ulonglong)bVar1 * 8) = 0;
      cVar4 = '\0';
      if ((byte)(bVar1 + 1) != 'd') {
        cVar4 = bVar1 + 1;
      }
      *(char *)(param_1 + 0x779) = cVar4;
      uVar3 = BuildFireTM(param_1,lVar2,param_2,param_3);
      return uVar3;
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== ClearHwResetHistory @ 14000bbe0 =====

void ClearHwResetHistory(longlong param_1)

{
  if ((**(uint **)(param_1 + 0x48) & 0x10) != 0) {
    **(uint **)(param_1 + 0x48) = **(uint **)(param_1 + 0x48);
    LOCK();
    UNLOCK();
  }
  return;
}



===== InitiateMURPollMode @ 14000bc00 =====

ulonglong InitiateMURPollMode(longlong param_1,ushort param_2,int *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 extraout_var;
  uint *puVar3;
  longlong lVar4;
  
  if ((**(uint **)(param_1 + 0x48) & 0x10) != 0) {
    **(uint **)(param_1 + 0x48) = **(uint **)(param_1 + 0x48);
    LOCK();
    UNLOCK();
  }
  **(undefined4 **)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0x8c4);
  LOCK();
  UNLOCK();
  **(uint **)(param_1 + 0x40) = **(uint **)(param_1 + 0x40) & 0xfffffffe;
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1 + 0x8d4) = *(undefined4 *)(param_1 + 0x340);
  uVar2 = MonitorBitToggleInIOCStatusPollMode(param_1,0x10);
  if ((char)uVar2 == '\0') {
    LogSystemEvent(param_1,0,0xc004af02,
                   (byte *)
                   "InitiateMURPollMode: INIT Failed: Reset history bit not toggled by IOC after MUR"
                   ,param_2,param_3);
    *(undefined4 *)(param_1 + 0x20) = 0x1c;
  }
  else {
    if ((**(uint **)(param_1 + 0x48) & 1) == 0) {
      puVar3 = *(uint **)(param_1 + 0x48);
LAB_14000bdfe:
      uVar1 = *puVar3;
      if ((uVar1 & 0x10) != 0) {
        puVar3 = *(uint **)(param_1 + 0x48);
        *puVar3 = uVar1;
        LOCK();
        UNLOCK();
      }
      return CONCAT71((int7)((ulonglong)puVar3 >> 8),1);
    }
    LogSystemEvent(param_1,0,0xc004af02,(byte *)"INIT Failed: Ready BIT not cleared after MUR",
                   param_2,param_3);
  }
  *(undefined4 *)(param_1 + 0x8c4) = 8;
  do {
    uVar1 = UnlockHostDiag(param_1,param_2,param_3);
    puVar3 = (uint *)CONCAT44(extraout_var,uVar1);
    if (uVar1 == 0xffff) break;
    **(undefined4 **)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0x8c4);
    LOCK();
    UNLOCK();
    **(uint **)(param_1 + 0xb0) = uVar1 | 0x100;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x8d4) = *(undefined4 *)(param_1 + 0x340);
    uVar1 = **(uint **)(param_1 + 0x48);
    while ((uVar1 & 0x10) == 0) {
      if (*(int *)(param_1 + 0x8d4) == 0) {
        puVar3 = (uint *)LogSystemEvent(param_1,0,0xc004af02,
                                        (byte *)" ResetHistory bit did not transition to 1",param_2,
                                        param_3);
        *(undefined4 *)(param_1 + 0x20) = 0x1b;
        goto LAB_14000bd93;
      }
      lVar4 = 100;
      *(int *)(param_1 + 0x8d4) = *(int *)(param_1 + 0x8d4) + -1;
      do {
        StorPortStallExecution(1000);
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      uVar1 = **(uint **)(param_1 + 0x48);
    }
    puVar3 = *(uint **)(param_1 + 0x48);
    if (((*puVar3 & 2) == 0) && (((*puVar3 | **(uint **)(param_1 + 0x40)) & 1) == 0)) {
      **(undefined4 **)(param_1 + 0xa8) = 4;
      LOCK();
      UNLOCK();
      puVar3 = *(uint **)(param_1 + 0x48);
      goto LAB_14000bdfe;
    }
LAB_14000bd93:
    *(char *)(param_1 + 0x430) = *(char *)(param_1 + 0x430) + '\x01';
  } while (*(byte *)(param_1 + 0x430) < 3);
  return (ulonglong)puVar3 & 0xffffffffffffff00;
}



===== InitiateResetPollMode @ 14000be20 =====

ulonglong InitiateResetPollMode(longlong param_1,int param_2,ushort param_3,int *param_4)

{
  uint uVar1;
  uint *in_RAX;
  undefined4 extraout_var;
  uint *puVar2;
  longlong lVar3;
  
  if (param_2 == 0x100) {
    do {
      uVar1 = UnlockHostDiag(param_1,param_3,param_4);
      in_RAX = (uint *)CONCAT44(extraout_var,uVar1);
      if (uVar1 == 0xffff) break;
      **(undefined4 **)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0x8c4);
      LOCK();
      UNLOCK();
      **(uint **)(param_1 + 0xb0) = uVar1 | 0x100;
      LOCK();
      UNLOCK();
      *(undefined4 *)(param_1 + 0x8d4) = *(undefined4 *)(param_1 + 0x340);
      uVar1 = **(uint **)(param_1 + 0x48);
      while ((uVar1 & 0x10) == 0) {
        if (*(int *)(param_1 + 0x8d4) == 0) {
          in_RAX = (uint *)LogSystemEvent(param_1,0,0xc004af02,
                                          (byte *)" ResetHistory bit did not transition to 1",
                                          param_3,param_4);
          *(undefined4 *)(param_1 + 0x20) = 0x1b;
          goto LAB_14000bef3;
        }
        lVar3 = 100;
        *(int *)(param_1 + 0x8d4) = *(int *)(param_1 + 0x8d4) + -1;
        do {
          StorPortStallExecution(1000);
          lVar3 = lVar3 + -1;
        } while (lVar3 != 0);
        uVar1 = **(uint **)(param_1 + 0x48);
      }
      in_RAX = *(uint **)(param_1 + 0x48);
      if (((*in_RAX & 2) == 0) && (((*in_RAX | **(uint **)(param_1 + 0x40)) & 1) == 0)) {
        **(undefined4 **)(param_1 + 0xa8) = 4;
        LOCK();
        UNLOCK();
        puVar2 = *(uint **)(param_1 + 0x48);
        uVar1 = *puVar2;
        if ((uVar1 & 0x10) != 0) {
          puVar2 = *(uint **)(param_1 + 0x48);
          *puVar2 = uVar1;
          LOCK();
          UNLOCK();
        }
        return CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
      }
LAB_14000bef3:
      *(char *)(param_1 + 0x430) = *(char *)(param_1 + 0x430) + '\x01';
    } while (*(byte *)(param_1 + 0x430) < 3);
  }
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== LunTargetReset @ 14000bf80 =====

ulonglong LunTargetReset(longlong param_1,longlong param_2,ushort param_3,int *param_4)

{
  byte bVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  undefined8 uVar3;
  ushort uVar4;
  undefined4 uVar5;
  
  if (param_2 == 0) goto LAB_14000bff7;
  if (*(longlong *)(param_2 + 0x68) == 0) {
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x23c) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x23c,(undefined1 *)0x0,0,param_3,param_4);
    }
    *(undefined1 *)(param_2 + 3) = 10;
  }
  else {
    if (*(int *)(param_2 + 0x14) == 0x20) {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x405) != 0)) {
        uVar5 = 0x405;
LAB_14000c039:
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),uVar5,
                    (undefined1 *)(*(longlong *)(param_2 + 0x68) + 0x4a),3,param_3,param_4);
      }
    }
    else if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x406) != 0)) {
      uVar5 = 0x406;
      goto LAB_14000c039;
    }
    uVar2 = *(ulonglong *)(param_1 + 0x450);
    if (uVar2 == 0) {
      uVar3 = BuildFireTM(param_1,param_2,param_3,param_4);
      return uVar3;
    }
    if (param_2 == uVar2) {
LAB_14000c0fc:
      return CONCAT71((int7)(uVar2 >> 8),1);
    }
    uVar4 = 0;
    do {
      uVar2 = (ulonglong)uVar4;
      if (*(longlong *)(param_1 + 0x458 + uVar2 * 8) == param_2) goto LAB_14000c0fc;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 100);
    bVar1 = *(byte *)(param_1 + 0x778);
    if (*(longlong *)(param_1 + 0x458 + (ulonglong)bVar1 * 8) == 0) {
      *(longlong *)(param_1 + 0x458 + (ulonglong)bVar1 * 8) = param_2;
      uVar2 = 0;
      if ((byte)(bVar1 + 1) != 100) {
        uVar2 = (ulonglong)(byte)(bVar1 + 1);
      }
      *(char *)(param_1 + 0x778) = (char)uVar2;
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x20000) != 0)) {
        uVar2 = RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x20000,(undefined1 *)0x0,0,
                            param_3,param_4);
      }
      goto LAB_14000c0fc;
    }
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x216) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x216,(undefined1 *)0x0,0,param_3,param_4);
    }
    LogSystemEvent(param_1,0,0xc004af02,(byte *)"Reset SRB Queue Full, Incoming Reset Failed",
                   param_3,param_4);
    *(undefined1 *)(param_2 + 3) = 4;
  }
  in_RAX = StorPortNotification(0,param_1,param_2);
LAB_14000bff7:
  return in_RAX & 0xffffffffffffff00;
}



===== MonitorBitToggleInIOCStatusPollMode @ 14000c190 =====

undefined8 MonitorBitToggleInIOCStatusPollMode(longlong param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  longlong lVar3;
  
  puVar2 = *(uint **)(param_1 + 0x48);
  uVar1 = *puVar2;
  while( true ) {
    if ((param_2 & uVar1) != 0) {
      return CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
    }
    if (*(int *)(param_1 + 0x8d4) == 0) break;
    lVar3 = 100;
    *(int *)(param_1 + 0x8d4) = *(int *)(param_1 + 0x8d4) + -1;
    do {
      StorPortStallExecution(1000);
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    puVar2 = *(uint **)(param_1 + 0x48);
    uVar1 = *puVar2;
  }
  return 0;
}



===== ReturnHostTagToFIFO @ 14000c210 =====

void ReturnHostTagToFIFO(longlong param_1,ushort param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  do {
    uVar1 = *(uint *)(param_1 + 0xaec);
    uVar2 = 0;
    if (uVar1 + 1 != *(uint *)(param_1 + 0xaf0)) {
      uVar2 = uVar1 + 1;
    }
    LOCK();
    bVar3 = uVar1 == *(uint *)(param_1 + 0xaec);
    if (bVar3) {
      *(uint *)(param_1 + 0xaec) = uVar2;
    }
    UNLOCK();
  } while (!bVar3);
  *(uint *)(*(longlong *)(param_1 + 0x9e8) + (ulonglong)uVar1 * 4) = (uint)param_2;
  return;
}



===== ReturnIOsToSystem @ 14000c260 =====

void ReturnIOsToSystem(longlong param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  longlong lVar3;
  longlong *plVar4;
  
  plVar4 = *(longlong **)(param_1 + 0x9f0);
  uVar1 = 0xb;
  if (*(char *)(param_1 + 0x438) != '\0') {
    uVar1 = 0x11;
  }
  uVar2 = 0;
  if (*(short *)(param_1 + 0x368) != 0) {
    do {
      lVar3 = *plVar4;
      *plVar4 = 0;
      *(undefined4 *)(plVar4 + 2) = 0;
      if (lVar3 != 0) {
        LOCK();
        *(int *)(param_1 + 0x8e8) = *(int *)(param_1 + 0x8e8) + -1;
        UNLOCK();
        *(undefined1 *)(lVar3 + 3) = uVar1;
        StorPortNotification(0,param_1);
      }
      plVar4 = plVar4 + 3;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(ushort *)(param_1 + 0x368));
  }
  if (*(longlong *)(param_1 + 0x450) != 0) {
    *(undefined1 *)(*(longlong *)(param_1 + 0x450) + 3) = uVar1;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0x450) = 0;
  }
  plVar4 = (longlong *)(param_1 + 0x458);
  lVar3 = 100;
  do {
    if (*plVar4 != 0) {
      *(undefined1 *)(*plVar4 + 3) = uVar1;
      StorPortNotification(0,param_1);
      *plVar4 = 0;
    }
    plVar4 = plVar4 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  *(undefined2 *)(param_1 + 0x778) = 0;
  if ((*(int *)(param_1 + 0x43c) != 0) && (*(char *)(param_1 + 0x440) == '\0')) {
    lVar3 = *(longlong *)(param_1 + 0x448);
    *(undefined1 *)(lVar3 + 3) = uVar1;
    *(undefined4 *)(*(longlong *)(lVar3 + 0x40) + 0x14) = 0xfa11;
    StorPortNotification(0,param_1);
    *(undefined4 *)(param_1 + 0x43c) = 0;
    *(undefined8 *)(param_1 + 0x448) = 0;
  }
  return;
}



===== StartAdapterReset @ 14000c3a0 =====

void StartAdapterReset(longlong param_1,undefined4 param_2,ushort param_3,int *param_4)

{
  undefined2 *puVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  longlong *plVar11;
  ushort uVar12;
  ushort uVar13;
  short sVar14;
  uint unaff_EDI;
  longlong lVar15;
  short sVar16;
  undefined4 uVar17;
  undefined1 uVar18;
  ushort local_res8 [4];
  undefined4 local_res10;
  undefined8 uVar19;
  undefined2 local_58 [2];
  uint local_54;
  undefined4 local_50 [2];
  undefined8 *local_48 [2];
  
  local_54 = unaff_EDI & 0xffffff00;
  uVar13 = 0;
  uVar17 = 0x1c;
  uVar6 = param_2;
  local_res10 = param_2;
  uVar5 = local_54;
LAB_14000c3f0:
  switch(*(undefined4 *)(param_1 + 0x8a4)) {
  case 0:
  case 1:
    *(undefined4 *)(param_1 + 0x8c0) = uVar6;
    if (*(char *)(param_1 + 0x411) != '\0') {
      PauseController(param_1,0,param_3,param_4);
      uVar6 = local_res10;
    }
    local_54 = uVar5 & 0xff;
    if ((**(uint **)(param_1 + 0xb0) & 0x80) != 0) {
      local_54 = 1;
    }
    uVar5 = local_54;
    if (*(int *)(param_1 + 0x8c0) == 0x700) {
      *(undefined8 *)(param_1 + 0x8a8) = 0x1e;
      *(undefined1 *)(param_1 + 0x430) = 4;
      *(undefined4 *)(param_1 + 0x8a4) = 5;
      goto LAB_14000c3f0;
    }
    iVar7 = *(int *)(param_1 + 0x8c4);
    if (iVar7 == 1) {
      *(undefined4 *)(param_1 + 0x8ac) = 0xa5;
      uVar4 = 3;
    }
    else if (iVar7 == 0xb) {
      if ((char)local_54 == '\0') goto LAB_14000c4c6;
      *(undefined4 *)(param_1 + 0x8ac) = 0x3c;
      uVar4 = 4;
    }
    else {
      if (iVar7 == 5) {
LAB_14000c4c6:
        *(undefined4 *)(param_1 + 0x8a4) = 5;
        goto LAB_14000c3f0;
      }
      *(undefined4 *)(param_1 + 0x8ac) = 5;
      uVar4 = 2;
    }
    *(undefined4 *)(param_1 + 0x8a8) = 5;
    *(undefined4 *)(param_1 + 0x8a4) = uVar4;
    goto LAB_14000c3f0;
  case 2:
  case 8:
    iVar7 = *(int *)(param_1 + 0x8ac);
    if (iVar7 != 0) goto LAB_14000d554;
    *(undefined4 *)(param_1 + 0x8a4) = *(undefined4 *)(param_1 + 0x8a8);
    goto LAB_14000c3f0;
  case 3:
    uVar9 = GetPendingIOCount(param_1);
    if ((short)uVar9 == 0) {
      *(undefined4 *)(param_1 + 0x428) = 0;
      *(undefined1 *)(param_1 + 0x421) = 0;
      *(undefined1 *)(param_1 + 0x430) = 0;
      *(undefined4 *)(param_1 + 0x8a4) = 0;
      *(undefined4 *)(param_1 + 0x8a8) = 0x1d;
      *(undefined4 *)(param_1 + 0x8c4) = 0;
      if ((*(int *)(param_1 + 0x9a0) != 0) && (*(char *)(param_1 + 0x9a4) == '\0')) {
        PELGetSetSeqNumbers(param_1,param_3,param_4);
      }
      InitTimerRoutine(param_1);
      ResumeController(param_1,0,param_3,param_4);
      return;
    }
    iVar7 = *(int *)(param_1 + 0x8ac);
    if (iVar7 == 0) {
      *(undefined4 *)(param_1 + 0x8a4) = *(undefined4 *)(param_1 + 0x8a8);
      break;
    }
    goto LAB_14000d554;
  case 4:
    if (((char)**(undefined4 **)(param_1 + 0xb0) < '\0') &&
       (iVar7 = *(int *)(param_1 + 0x8ac), iVar7 != 0)) goto LAB_14000d554;
    *(undefined4 *)(param_1 + 0x8a4) = 5;
    goto LAB_14000c3f0;
  case 5:
    *(undefined4 *)(param_1 + 0x428) = 1;
    if (*(longlong *)(param_1 + 0xc88) != 0) {
      *(undefined1 *)(param_1 + 0xc80) = 0;
      StorPortExtendedFunction
                (0x21,param_1,*(longlong *)(param_1 + 0xc88),LitServiceActiveListCallback,0,0,0);
    }
    *(undefined1 *)(param_1 + 0x3fa) = 0;
    *(undefined1 *)(param_1 + 0x8a2) = 1;
    uVar12 = 0;
    plVar11 = *(longlong **)(param_1 + 0x9f0);
    uVar18 = 0xb;
    if (*(char *)(param_1 + 0x438) != '\0') {
      uVar18 = 0x11;
    }
    if (*(short *)(param_1 + 0x368) != 0) {
      do {
        lVar15 = *plVar11;
        *plVar11 = 0;
        *(undefined4 *)(plVar11 + 2) = 0;
        if (lVar15 != 0) {
          LOCK();
          *(int *)(param_1 + 0x8e8) = *(int *)(param_1 + 0x8e8) + -1;
          UNLOCK();
          *(undefined1 *)(lVar15 + 3) = uVar18;
          StorPortNotification(0,param_1);
        }
        plVar11 = plVar11 + 3;
        uVar12 = uVar12 + 1;
      } while (uVar12 < *(ushort *)(param_1 + 0x368));
    }
    if (*(longlong *)(param_1 + 0x450) != 0) {
      *(undefined1 *)(*(longlong *)(param_1 + 0x450) + 3) = uVar18;
      StorPortNotification(0,param_1);
      *(undefined8 *)(param_1 + 0x450) = 0;
    }
    plVar11 = (longlong *)(param_1 + 0x458);
    lVar15 = 100;
    do {
      if (*plVar11 != 0) {
        *(undefined1 *)(*plVar11 + 3) = uVar18;
        StorPortNotification(0,param_1);
        *plVar11 = 0;
      }
      plVar11 = plVar11 + 1;
      lVar15 = lVar15 + -1;
    } while (lVar15 != 0);
    *(undefined2 *)(param_1 + 0x778) = 0;
    if ((*(int *)(param_1 + 0x43c) != 0) && (*(char *)(param_1 + 0x440) == '\0')) {
      lVar15 = *(longlong *)(param_1 + 0x448);
      *(undefined1 *)(lVar15 + 3) = uVar18;
      *(undefined4 *)(*(longlong *)(lVar15 + 0x40) + 0x14) = 0xfa11;
      StorPortNotification(0,param_1);
      *(undefined4 *)(param_1 + 0x43c) = 0;
      *(undefined8 *)(param_1 + 0x448) = 0;
    }
    uVar5 = UnlockHostDiag(param_1,param_3,param_4);
    if (uVar5 == 0xffff) {
      if (*(int *)(param_1 + 0x8a8) == 0x1e) {
        *(undefined4 *)(param_1 + 0x8c4) = 0x1f;
        uVar6 = 0x1e;
      }
      else {
        uVar6 = 0x1c;
      }
      *(undefined4 *)(param_1 + 0x8a4) = uVar6;
      uVar5 = local_54;
    }
    else {
      **(undefined4 **)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0x8c4);
      LOCK();
      UNLOCK();
      if (*(int *)(param_1 + 0x8c4) == 1) {
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x127) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x127,(undefined1 *)0x0,0,param_3,
                      param_4);
        }
        **(uint **)(param_1 + 0x40) = **(uint **)(param_1 + 0x40) | 0x10;
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1 + 0x8c4) = 2;
        *(undefined4 *)(param_1 + 0x8ac) = 0x3c;
        *(undefined4 *)(param_1 + 0x8a4) = 4;
        *(undefined4 *)(param_1 + 0x8a8) = 5;
LAB_14000c7db:
        uVar5 = uVar5 | 0x700;
      }
      else {
        if (*(int *)(param_1 + 0x8c0) != 0x100) {
          *(undefined4 *)(param_1 + 0x8ac) = 300;
          *(undefined4 *)(param_1 + 0x8a4) = 6;
          goto LAB_14000c7db;
        }
        uVar5 = uVar5 | 0x100;
        *(undefined4 *)(param_1 + 0x8ac) = *(undefined4 *)(param_1 + 0x340);
        *(undefined4 *)(param_1 + 0x8a4) = 7;
      }
      **(uint **)(param_1 + 0xb0) = uVar5;
      LOCK();
      UNLOCK();
      uVar5 = local_54;
    }
    break;
  case 6:
    if ((**(uint **)(param_1 + 0x48) & 2) != 0) {
      uVar9 = **(uint **)(param_1 + 0xb8);
      *(uint *)(param_1 + 0x42c) = uVar9;
      *(undefined4 *)(param_1 + 0x8a4) = 0x1e;
      if ((uVar9 & 0xf0000000) == 0xf0000000) {
        *(undefined4 *)(param_1 + 0x8a8) = 0x1d;
      }
      else {
        *(undefined4 *)(param_1 + 0x8a8) = 0x1c;
      }
    }
    iVar7 = *(int *)(param_1 + 0x8ac);
    if (iVar7 != 0) goto LAB_14000c95c;
    *(undefined4 *)(param_1 + 0x8a8) = 0x1c;
    *(undefined4 *)(param_1 + 0x8a4) = 0x1e;
    goto LAB_14000c3f0;
  case 7:
    uVar9 = **(uint **)(param_1 + 0x48);
    if ((uVar9 & 0x10) == 0) goto LAB_14000c94e;
    if (((uVar9 & 2) == 0) && (((uVar9 | **(uint **)(param_1 + 0x40)) & 1) == 0)) {
      **(undefined4 **)(param_1 + 0xa8) = 4;
      LOCK();
      UNLOCK();
      if ((**(uint **)(param_1 + 0x48) & 0x10) != 0) {
        **(uint **)(param_1 + 0x48) = **(uint **)(param_1 + 0x48);
        LOCK();
        UNLOCK();
      }
      if (*(int *)(param_1 + 0x428) == 0) {
        *(undefined4 *)(param_1 + 0x8a8) = 0x1d;
        return;
      }
      *(undefined4 *)(param_1 + 0x8a4) = 9;
      uVar6 = local_res10;
    }
    else {
      *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
      uVar6 = local_res10;
    }
    goto LAB_14000c3f0;
  case 9:
    CreateAdministrativeQueuePair(param_1);
    **(uint **)(param_1 + 0x40) = **(uint **)(param_1 + 0x40) | 1;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x8ac) = *(undefined4 *)(param_1 + 0x340);
    *(undefined4 *)(param_1 + 0x8a4) = 10;
    *(undefined4 *)(param_1 + 0x8a8) = 0xb;
    break;
  case 10:
    if ((**(uint **)(param_1 + 0x48) & 1) == 0) {
LAB_14000c94e:
      iVar7 = *(int *)(param_1 + 0x8ac);
      if (iVar7 != 0) {
LAB_14000c95c:
        uVar19 = 100000;
        goto LAB_14000d562;
      }
LAB_14000d2b3:
      *(undefined4 *)(param_1 + 0x8a8) = *(undefined4 *)(param_1 + 0x8a4);
      *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
    }
    else {
      *(undefined4 *)(param_1 + 0x8a4) = *(undefined4 *)(param_1 + 0x8a8);
    }
    goto LAB_14000c3f0;
  case 0xb:
    puVar1 = *(undefined2 **)(param_1 + 0x310);
    ZeroMemory(puVar1,0x80);
    *(undefined1 *)((longlong)puVar1 + 3) = 1;
    *puVar1 = 0xada0;
    *(undefined8 *)(puVar1 + 8) = *(undefined8 *)(param_1 + 0x308);
    *(undefined4 *)(puVar1 + 0xc) = 0x58;
    *(undefined1 *)((longlong)puVar1 + 0x1f) = 8;
    uVar8 = AdminQueueRequestPost(param_1,puVar1,param_3,param_4);
    if ((char)uVar8 == '\0') {
LAB_14000ccf6:
      uVar6 = *(undefined4 *)(param_1 + 0x8a4);
      *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
      *(undefined4 *)(param_1 + 0x8a8) = uVar6;
      uVar5 = local_54;
    }
    else {
      *(undefined4 *)(param_1 + 0x8ac) = *(undefined4 *)(param_1 + 0x8b0);
      *(undefined4 *)(param_1 + 0x8a4) = 0xc;
      *(undefined4 *)(param_1 + 0x8a8) = 0xd;
      uVar5 = local_54;
    }
    break;
  case 0xc:
    uVar12 = *(ushort *)(param_1 + 0x2b0);
    uVar3 = *(ushort *)(param_1 + 0x2d8);
    plVar11 = (longlong *)((ulonglong)uVar12 * 0x10 + *(longlong *)(param_1 + 0x2d0));
    if ((*(ushort *)((longlong)plVar11 + 0xe) & 1) != uVar3) {
      iVar7 = *(int *)(param_1 + 0x8ac);
      if (iVar7 != 0) goto LAB_14000c95c;
      *(undefined4 *)(param_1 + 0x8a8) = 0xc;
      *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
      uVar6 = local_res10;
      uVar5 = local_54;
      goto LAB_14000c3f0;
    }
    *(undefined4 *)(param_1 + 0x8a4) = *(undefined4 *)(param_1 + 0x8a8);
    *(short *)(param_1 + 0x2ae) = (short)plVar11[1];
    ProcessPolledReplyDescriptor
              (param_1,plVar11,local_res8,local_50,local_48,local_58,param_3,param_4);
    uVar5 = local_54;
    sVar14 = uVar12 + 1;
    sVar16 = 0;
    if (sVar14 != *(short *)(param_1 + 0x2a2)) {
      sVar16 = sVar14;
    }
    uVar12 = uVar3 ^ 1;
    if (sVar14 != *(short *)(param_1 + 0x2a2)) {
      uVar12 = uVar3;
    }
    if (local_48[0] != (undefined8 *)0x0) {
      uVar9 = *(uint *)(param_1 + 0xa88);
      *(undefined8 *)(*(longlong *)(param_1 + 0xa58) + (ulonglong)uVar9 * 8) = *local_48[0];
      uVar9 = uVar9 + 1;
      uVar10 = 0;
      if (uVar9 != *(ushort *)(param_1 + 0x362)) {
        uVar10 = uVar9;
      }
      **(uint **)(param_1 + 0xd8) = uVar10;
      LOCK();
      UNLOCK();
      *(uint *)(param_1 + 0xa88) = uVar10;
    }
    **(short **)(param_1 + 0x88) = sVar16;
    LOCK();
    UNLOCK();
    *(uint *)(param_1 + 0x2d8) = (uint)uVar12;
    *(short *)(param_1 + 0x2b0) = sVar16;
    uVar6 = local_res10;
    if ((local_res8[0] & 0x7fff) == 0) goto LAB_14000c3f0;
    LogSystemEvent(param_1,0,0xc004af02,
                   (byte *)"StartAdapterReset: Admin reply did not complete with Success status",
                   param_3,param_4);
    *(undefined4 *)(param_1 + 0x8a8) = *(undefined4 *)(param_1 + 0x8a4);
    *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
    break;
  case 0xd:
    uVar8 = ProcessIOCFactsData(param_1,param_3,param_4);
    if ((char)uVar8 != '\0') {
      if (*(char *)(param_1 + 0x395) != '\0') {
        FreeOperationalQueues(param_1,param_3,param_4);
        InitializeAllocatedMemory(param_1);
        PopulateReplySenseFreeQueues(param_1);
        *(undefined4 *)(param_1 + 0x8a4) = 0xe;
        break;
      }
      LogSystemEvent(param_1,0,0xc004af02,
                     (byte *)"StartAdapterReset Failed: Adapter is not a SCSI initiator",param_3,
                     param_4);
    }
LAB_14000cbc5:
    *(undefined4 *)(param_1 + 0x8a8) = *(undefined4 *)(param_1 + 0x8a4);
    *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
    break;
  case 0xe:
    BuildIOCInit(param_1);
    uVar8 = AdminQueueRequestPost(param_1,*(void **)(param_1 + 0x310),param_3,param_4);
    if ((char)uVar8 == '\0') {
      uVar6 = *(undefined4 *)(param_1 + 0x8a4);
      *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
      *(undefined4 *)(param_1 + 0x8a8) = uVar6;
    }
    else {
      *(undefined4 *)(param_1 + 0x8ac) = *(undefined4 *)(param_1 + 0x8b0);
      *(undefined4 *)(param_1 + 0x8a4) = 0xc;
      *(undefined4 *)(param_1 + 0x8a8) = 0x10;
    }
    break;
  default:
    *(undefined4 *)(param_1 + 0x8a4) = 5;
    *(undefined4 *)(param_1 + 0x8a8) = 0x1e;
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x290) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x290,(undefined1 *)0x0,0,param_3,param_4);
    }
    LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                        "Kill Adapter (Driver) - Invalid state detected in Soft Reset state machine"
                        ,param_3,param_4);
    KillAdapter(param_1,0x1d,param_3,param_4);
    break;
  case 0x10:
    *(undefined8 *)(param_1 + 0x890) = 0;
    *(undefined2 *)(param_1 + 0x8a0) = 600;
    *(undefined4 *)(param_1 + 0x424) = 0;
    puVar1 = *(undefined2 **)(param_1 + 0x310);
    ZeroMemory(puVar1,0x80);
    *(undefined1 *)((longlong)puVar1 + 3) = 4;
    *puVar1 = 0xada0;
    uVar8 = AdminQueueRequestPost(param_1,puVar1,param_3,param_4);
    if ((char)uVar8 == '\0') goto LAB_14000ccf6;
    *(undefined4 *)(param_1 + 0x8ac) = *(undefined4 *)(param_1 + 0x8b0);
    *(undefined4 *)(param_1 + 0x8a4) = 0xc;
    *(undefined4 *)(param_1 + 0x8a8) = 0x11;
    uVar5 = local_54;
    break;
  case 0x11:
    puVar1 = *(undefined2 **)(param_1 + 0x310);
    ZeroMemory(puVar1,0x80);
    *(undefined1 *)((longlong)puVar1 + 3) = 3;
    *puVar1 = 0xada1;
    *(undefined1 *)(param_1 + 0x412) = 1;
    uVar8 = AdminQueueRequestPost(param_1,puVar1,param_3,param_4);
    uVar5 = local_54;
    if ((char)uVar8 == '\0') {
      *(undefined4 *)(param_1 + 0x8a8) = *(undefined4 *)(param_1 + 0x8a4);
      *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
    }
    else {
      *(undefined4 *)(param_1 + 0x8ac) = 18000;
      *(undefined4 *)(param_1 + 0x8a4) = 0x12;
    }
    break;
  case 0x12:
    *(undefined1 *)(param_1 + 0x8a2) = 0;
    Poll_mpi3Isr(param_1,1,param_4);
    if (*(char *)(param_1 + 0x412) == '\0') {
      if (*(char *)(param_1 + 0x413) == '\0') {
        LogSystemEvent(param_1,0,0xc004af02,(byte *)"PortEnable completed with Failed statusD",
                       param_3,param_4);
        *(undefined4 *)(param_1 + 0x8a8) = *(undefined4 *)(param_1 + 0x8a4);
        *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
      }
      else {
        *(undefined4 *)(param_1 + 0x8ac) = 0x14;
        *(undefined4 *)(param_1 + 0x8a4) = 0x18;
      }
    }
    else {
      if (*(int *)(param_1 + 0x8ac) == 0) goto LAB_14000cbc5;
      lVar15 = *(longlong *)(param_1 + 0x8b8);
      *(int *)(param_1 + 0x8ac) = *(int *)(param_1 + 0x8ac) + -1;
      if (lVar15 != 0) {
        uVar19 = 100000;
        goto LAB_14000d571;
      }
      lVar15 = 100;
      do {
        StorPortStallExecution(1000);
        lVar15 = lVar15 + -1;
      } while (lVar15 != 0);
      uVar5 = local_54;
    }
    break;
  case 0x13:
    if (*(char *)(param_1 + 0x408) == '\0') {
      uVar12 = *(ushort *)(param_1 + 0x376);
      if (0x1f < uVar12) {
        uVar12 = 0x20;
      }
      uVar3 = *(ushort *)(param_1 + 0x378);
      *(ushort *)(param_1 + 0x37a) = uVar12;
      if (uVar3 < uVar12) {
        *(ushort *)(param_1 + 0x37a) = uVar3;
        uVar12 = uVar3;
      }
      if (uVar12 == 1) {
        *(undefined1 *)(param_1 + 0x396) = 1;
      }
      uVar3 = *(ushort *)(param_1 + 0x37a);
      if (*(ushort *)(param_1 + 0x294) < uVar12) {
        uVar3 = *(ushort *)(param_1 + 0x294);
      }
      *(ushort *)(param_1 + 0x37a) = uVar3;
      uVar6 = local_res10;
    }
    else {
      *(undefined2 *)(param_1 + 0x37a) = 1;
    }
    uVar12 = *(ushort *)(param_1 + 0x368);
    if (uVar12 < *(ushort *)(param_1 + 0x35c)) {
      *(ushort *)(param_1 + 0x35c) = uVar12;
    }
    if (uVar12 < *(ushort *)(param_1 + 0x35e)) {
      *(ushort *)(param_1 + 0x35e) = uVar12;
    }
    *(undefined4 *)(param_1 + 0x388) = 0;
    *(undefined8 *)(param_1 + 0x380) = *(undefined8 *)(param_1 + 0x9d8);
    *(undefined2 *)(param_1 + 0x37c) = 0;
    *(undefined4 *)(param_1 + 0x8ac) = *(undefined4 *)(param_1 + 0x8b0);
    *(undefined4 *)(param_1 + 0x8a4) = 0x14;
    goto LAB_14000c3f0;
  case 0x14:
    if (*(char *)(param_1 + 0x408) == '\0') {
      uVar12 = **(ushort **)(param_1 + 0x380);
      uVar9 = (uint)(*(ushort **)(param_1 + 0x380))[1];
    }
    else {
      uVar12 = 0;
      uVar9 = 0;
    }
    if (*(ushort *)(param_1 + 0x37c) < *(ushort *)(param_1 + 0x37a)) {
      if (uVar12 < *(ushort *)(param_1 + 0x3c4)) {
        *(short *)(param_1 + 0x38a) = *(short *)(param_1 + 0x38a) + 1;
        *(undefined4 *)(param_1 + 0x390) = 1;
        CreateOperationalReplyQueue
                  (param_1,*(ushort *)(param_1 + 0x38a),uVar12 & 0xff,
                   (uint)*(ushort *)(param_1 + 0x36e) * (uint)*(ushort *)(param_1 + 0x35e),uVar9,
                   param_3,param_4);
        *(undefined4 *)(param_1 + 0x8ac) = *(undefined4 *)(param_1 + 0x8b0);
        *(undefined4 *)(param_1 + 0x8a4) = 0x15;
        uVar6 = local_res10;
      }
      else {
        *(longlong *)(param_1 + 0x380) = *(longlong *)(param_1 + 0x380) + 8;
        *(ushort *)(param_1 + 0x37c) = *(ushort *)(param_1 + 0x37c) + 1;
        *(undefined4 *)(param_1 + 0x8a4) = 0x14;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x8a4) = 0x19;
    }
    goto LAB_14000c3f0;
  case 0x15:
    if (*(int *)(param_1 + 0x8ac) == 0) {
      if (*(int *)(param_1 + 0x390) == 1) {
        LogSystemEvent(param_1,0,0xc004af02,(byte *)"Create OP Request Queue TIMEDOUT",param_3,
                       param_4);
        *(undefined4 *)(param_1 + 0x20) = 0x15;
LAB_14000d29f:
        uVar6 = local_res10;
      }
      else if (*(int *)(param_1 + 0x390) == 0) {
        LogSystemEvent(param_1,0,0xc004af02,(byte *)"Create OP Request Queue TIMEDOUT",param_3,
                       param_4);
        *(undefined4 *)(param_1 + 0x20) = 0x18;
        goto LAB_14000d29f;
      }
      goto LAB_14000d2b3;
    }
    *(int *)(param_1 + 0x8ac) = *(int *)(param_1 + 0x8ac) + -1;
    if (*(char *)(param_1 + 0x414) != '\0') {
      if (*(longlong *)(param_1 + 0x8b8) != 0) {
        StorPortExtendedFunction
                  (0x21,param_1,*(longlong *)(param_1 + 0x8b8),StartAdapterResetCallback,0,100000,0)
        ;
        *(undefined4 *)(param_1 + 0x8a4) = 0x15;
        return;
      }
      lVar15 = 100;
      do {
        StorPortStallExecution(1000);
        lVar15 = lVar15 + -1;
      } while (lVar15 != 0);
      *(undefined4 *)(param_1 + 0x8a4) = 0x15;
      uVar5 = local_54;
      break;
    }
    if (*(int *)(param_1 + 0x390) == 0) {
      if (*(char *)(param_1 + 0x415) == '\0') {
        LogSystemEvent(param_1,0,0xc004af02,(byte *)"create OP Request Queue Failed",param_3,param_4
                      );
        *(undefined4 *)(param_1 + 0x20) = 0x19;
        *(undefined4 *)(param_1 + 0x8a8) = *(undefined4 *)(param_1 + 0x8a4);
        *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
        uVar6 = local_res10;
      }
      else {
        *(undefined2 *)(*(longlong *)(param_1 + 0x380) + 6) = *(undefined2 *)(param_1 + 0x388);
        *(short *)(param_1 + 0x37c) = *(short *)(param_1 + 0x37c) + 1;
        *(longlong *)(param_1 + 0x380) = *(longlong *)(param_1 + 0x380) + 8;
        *(undefined4 *)(param_1 + 0x8a4) = 0x14;
      }
    }
    else {
      if (*(int *)(param_1 + 0x390) != 1) goto switchD_14000c40b_caseD_16;
      if (*(char *)(param_1 + 0x415) == '\0') {
        LogSystemEvent(param_1,0,0xc004af02,(byte *)"Create OP Reply Queue Failed",param_3,param_4);
        *(undefined4 *)(param_1 + 0x20) = 0x16;
        *(undefined4 *)(param_1 + 0x8a8) = *(undefined4 *)(param_1 + 0x8a4);
        *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
        uVar6 = local_res10;
      }
      else {
        *(undefined2 *)
         (*(longlong *)(param_1 + 0x9e0) + (ulonglong)**(ushort **)(param_1 + 0x380) * 2) =
             *(undefined2 *)(param_1 + 0x38a);
        *(undefined2 *)(*(longlong *)(param_1 + 0x380) + 4) = *(undefined2 *)(param_1 + 0x38a);
        *(short *)(param_1 + 0x388) = *(short *)(param_1 + 0x388) + 1;
        *(undefined4 *)(param_1 + 0x8a4) = 0x16;
        uVar6 = local_res10;
      }
    }
    goto LAB_14000c3f0;
  case 0x16:
switchD_14000c40b_caseD_16:
    uVar12 = *(ushort *)(param_1 + 0x35c);
    uVar3 = *(ushort *)(param_1 + 0x36a);
    *(undefined2 *)(*(longlong *)(param_1 + 0x380) + 4) = *(undefined2 *)(param_1 + 0x38a);
    if (*(char *)(param_1 + 0x408) == '\0') {
      uVar9 = (uint)*(ushort *)(*(longlong *)(param_1 + 0x380) + 2);
    }
    else {
      uVar9 = 0;
    }
    *(undefined4 *)(param_1 + 0x390) = 0;
    CreateOperationalRequestQueue
              (param_1,*(ushort *)(param_1 + 0x388),*(undefined2 *)(param_1 + 0x38a),
               (uint)uVar3 * (uint)uVar12,uVar9,param_3,param_4);
    *(undefined4 *)(param_1 + 0x8ac) = *(undefined4 *)(param_1 + 0x8b0);
    *(undefined4 *)(param_1 + 0x8a4) = 0x15;
    break;
  case 0x18:
    cVar2 = Poll_mpi3Isr(param_1,1,param_4);
    uVar6 = local_res10;
    if (cVar2 != '\0') goto LAB_14000c3f0;
    if (*(int *)(param_1 + 0x8ac) == 0) {
      *(undefined4 *)(param_1 + 0x8a4) = 0x13;
      goto LAB_14000c3f0;
    }
    *(int *)(param_1 + 0x8ac) = *(int *)(param_1 + 0x8ac) + -1;
    StorPortExtendedFunction
              (0x21,param_1,*(undefined8 *)(param_1 + 0x8b8),StartAdapterResetCallback,0,100000,0);
    break;
  case 0x19:
    if (*(int *)(param_1 + 0x3fc) == 0) {
      *(undefined4 *)(param_1 + 0x8a4) = 0x1a;
      goto LAB_14000c3f0;
    }
    *(undefined4 *)(param_1 + 0x8ac) = *(undefined4 *)(param_1 + 0x8b0);
    *(undefined4 *)(param_1 + 0x8a4) = 0x1b;
    *(undefined4 *)(param_1 + 0x8a8) = 0x1a;
    IssueDiagBufferPostPolled
              (param_1,1,*(undefined8 *)(param_1 + 0xa28),*(undefined4 *)(param_1 + 0x3fc),param_3,
               param_4);
    break;
  case 0x1a:
    if (*(int *)(param_1 + 0x400) == 0) {
      *(undefined4 *)(param_1 + 0x8a4) = 0x1d;
      goto LAB_14000c3f0;
    }
    *(undefined4 *)(param_1 + 0x8ac) = *(undefined4 *)(param_1 + 0x8b0);
    *(undefined4 *)(param_1 + 0x8a4) = 0x1b;
    *(undefined4 *)(param_1 + 0x8a8) = 0x1d;
    IssueDiagBufferPostPolled
              (param_1,2,*(undefined8 *)(param_1 + 0xa38),*(undefined4 *)(param_1 + 0x400),param_3,
               param_4);
    break;
  case 0x1b:
    if (*(char *)(param_1 + 0x9a5) == '\0') {
      *(undefined4 *)(param_1 + 0x8a4) = *(undefined4 *)(param_1 + 0x8a8);
    }
    else {
      iVar7 = *(int *)(param_1 + 0x8ac);
      if (iVar7 != 0) {
LAB_14000d554:
        uVar19 = 1000000;
LAB_14000d562:
        lVar15 = *(longlong *)(param_1 + 0x8b8);
        *(int *)(param_1 + 0x8ac) = iVar7 + -1;
LAB_14000d571:
        StorPortExtendedFunction(0x21,param_1,lVar15,StartAdapterResetCallback,0,uVar19,0);
        return;
      }
      *(undefined4 *)(param_1 + 0x8a4) = 0x1c;
    }
    goto LAB_14000c3f0;
  case 0x1c:
    *(char *)(param_1 + 0x430) = *(char *)(param_1 + 0x430) + '\x01';
    if (2 < *(byte *)(param_1 + 0x430)) {
      LogSystemEvent(param_1,0,0xc004af02,(byte *)"SoftReset Failed-Start KillAdapter",param_3,
                     param_4);
      *(undefined4 *)(param_1 + 0x8a4) = 5;
      *(undefined4 *)(param_1 + 0x8a8) = 0x1e;
      *(undefined4 *)(param_1 + 0x8c4) = 0x1f;
      *(undefined4 *)(param_1 + 0x8c0) = 0x700;
      *(undefined4 *)(param_1 + 0x8c8) = 0;
      break;
    }
    *(undefined4 *)(param_1 + 0x8a4) = 5;
    goto LAB_14000c3f0;
  case 0x1d:
    goto switchD_14000c40b_caseD_1d;
  case 0x1e:
    if (*(char *)(param_1 + 0x440) != '\0') {
      lVar15 = *(longlong *)(param_1 + 0x448);
      if (*(int *)(param_1 + 0x8c4) == 0x1f) {
        *(undefined1 *)(lVar15 + 3) = 4;
        *(undefined4 *)(*(longlong *)(lVar15 + 0x40) + 0x14) = 0xfa12;
      }
      else {
        *(undefined1 *)(lVar15 + 3) = 1;
        *(undefined4 *)(*(longlong *)(lVar15 + 0x40) + 0x14) = 0;
        if ((**(uint **)(param_1 + 0x48) & 0x10) != 0) {
          **(uint **)(param_1 + 0x48) = **(uint **)(param_1 + 0x48);
          LOCK();
          UNLOCK();
        }
        uVar17 = 0x1d;
      }
      *(undefined4 *)(param_1 + 0x8a8) = uVar17;
      *(undefined1 *)(param_1 + 0x440) = 0;
      StorPortNotification(0,param_1,*(undefined8 *)(param_1 + 0x448));
      *(undefined4 *)(param_1 + 0x43c) = 0;
      *(undefined8 *)(param_1 + 0x448) = 0;
    }
    *(undefined1 *)(param_1 + 0x417) = 1;
    LogSystemEvent(param_1,0,0xc004af02,(byte *)"Diag Fault completed",param_3,param_4);
    ResumeController(param_1,0,param_3,param_4);
    if (*(short *)(param_1 + 0x374) == 0) {
      return;
    }
    do {
      StorPortNotification(7,param_1,uVar13);
      uVar13 = uVar13 + 1;
    } while (uVar13 < *(ushort *)(param_1 + 0x374));
    return;
  }
  uVar6 = local_res10;
  goto LAB_14000c3f0;
switchD_14000c40b_caseD_1d:
  if (*(char *)(param_1 + 0x411) == '\0') {
    *(undefined1 *)(param_1 + 0x411) = 1;
  }
  InitTimerRoutine(param_1);
  uVar13 = 0;
  if (*(short *)(param_1 + 0x374) != 0) {
    do {
      StorPortNotification(7,param_1,uVar13);
      uVar13 = uVar13 + 1;
    } while (uVar13 < *(ushort *)(param_1 + 0x374));
  }
  if (*(char *)(param_1 + 0x9a4) != '\0') {
    *(undefined1 *)(param_1 + 0x9a4) = 0;
    PELWait(param_1,param_3,param_4);
  }
  *(undefined4 *)(param_1 + 0x8e8) = 0;
  if (*(short *)(param_1 + 0x88e) != 0) {
    *(undefined2 *)(param_1 + 0x88e) = 0;
  }
  ResumeController(param_1,0,param_3,param_4);
  *(undefined4 *)(param_1 + 0x428) = 0;
  *(undefined1 *)(param_1 + 0x430) = 0;
  *(undefined1 *)(param_1 + 0x421) = 0;
  if ((**(uint **)(param_1 + 0x48) & 0x10) != 0) {
    **(uint **)(param_1 + 0x48) = **(uint **)(param_1 + 0x48);
    LOCK();
    UNLOCK();
  }
  *(undefined4 *)(param_1 + 0x8a4) = 0;
  *(undefined4 *)(param_1 + 0x8a8) = 0x1d;
  *(undefined4 *)(param_1 + 0x8c4) = 0;
  *(undefined1 *)(param_1 + 0x438) = 0;
  if (*(char *)(param_1 + 0x440) != '\0') {
    lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x448) + 0x40);
    *(undefined1 *)(param_1 + 0x440) = 0;
    *(undefined1 *)(*(longlong *)(param_1 + 0x448) + 3) = 1;
    *(undefined4 *)(lVar15 + 0x14) = 0;
    StorPortNotification(0,param_1,*(undefined8 *)(param_1 + 0x448));
    *(undefined4 *)(param_1 + 0x43c) = 0;
    *(undefined8 *)(param_1 + 0x448) = 0;
  }
  *(undefined4 *)(param_1 + 0x8c8) = 0;
  LogSystemEvent(param_1,0,0x4004af00,(byte *)"SoftReset SUCCESS",param_3,param_4);
  return;
}



===== StartAdapterResetCallback @ 14000d920 =====

void StartAdapterResetCallback(longlong param_1)

{
  int local_res8;
  undefined1 local_resc;
  
  local_res8 = 8;
  local_resc = 0;
  StartAdapterReset(param_1,*(undefined4 *)(param_1 + 0x8c0),0,&local_res8);
  return;
}



===== StartShutdown @ 14000d950 =====

void StartShutdown(longlong param_1,ushort param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  
  puVar1 = (uint *)(param_1 + 0x8c8);
  uVar4 = *puVar1;
  iVar3 = (uint)*(ushort *)(param_1 + 0x3f8) * 10;
  do {
    if (6 < uVar4) {
      if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x291) != 0)) {
        RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x291,(undefined1 *)puVar1,4,param_2,
                    param_3);
      }
      LogOperationalEvent(param_1,(int *)0x0,0,0xc004af02,
                          "Kill Adapter (Driver) - Invalid state detected in Shutdown state machine"
                          ,param_2,param_3);
      KillAdapter(param_1,0x1e,param_2,param_3);
      return;
    }
    switch(uVar4) {
    case 0:
      StopTimerRoutine(param_1);
      *(int *)(param_1 + 0x8d4) = iVar3;
      *puVar1 = 1;
      break;
    case 1:
      uVar4 = GetPendingIOCount(param_1);
      if (((short)uVar4 == 0) || (*(int *)(param_1 + 0x8d4) == 0)) {
        *puVar1 = 2;
      }
      else {
        *(int *)(param_1 + 0x8d4) = *(int *)(param_1 + 0x8d4) + -1;
        if (*param_3 != 1) {
LAB_14000dbe6:
          StorPortExtendedFunction
                    (0x21,param_1,*(undefined8 *)(param_1 + 0x8d8),StartShutdownCallback,0,100000,0)
          ;
          return;
        }
        lVar5 = 100;
        do {
          StorPortStallExecution(1000);
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
      }
      break;
    case 2:
      *(undefined1 *)(param_1 + 0x410) = 1;
      if ((**(uint **)(param_1 + 0x48) & 0x10) != 0) {
        **(uint **)(param_1 + 0x48) = **(uint **)(param_1 + 0x48);
        LOCK();
        UNLOCK();
      }
      **(undefined4 **)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0x8c4);
      LOCK();
      UNLOCK();
      **(uint **)(param_1 + 0x40) = **(uint **)(param_1 + 0x40) & 0xfffffffe;
      LOCK();
      UNLOCK();
      *(int *)(param_1 + 0x8d4) = iVar3;
      *puVar1 = 3;
      break;
    case 3:
      if (((**(uint **)(param_1 + 0x48) & 0x10) == 0) && (*(int *)(param_1 + 0x8d4) != 0)) {
        *(int *)(param_1 + 0x8d4) = *(int *)(param_1 + 0x8d4) + -1;
        if (*param_3 != 1) goto LAB_14000dbe6;
        lVar5 = 100;
        do {
          StorPortStallExecution(1000);
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
      }
      else {
        *puVar1 = 4;
      }
      break;
    case 4:
      **(uint **)(param_1 + 0x40) = **(uint **)(param_1 + 0x40) | 0x6000;
      LOCK();
      UNLOCK();
      *(int *)(param_1 + 0x8d4) = iVar3;
      *puVar1 = 5;
      break;
    case 5:
      if (((**(uint **)(param_1 + 0x48) & 8) == 0) &&
         (iVar2 = *(int *)(param_1 + 0x8d4), *(int *)(param_1 + 0x8d4) = iVar2 + -1, iVar2 != 0)) {
        if (*param_3 != 1) goto LAB_14000dbe6;
        lVar5 = 100;
        do {
          StorPortStallExecution(1000);
          lVar5 = lVar5 + -1;
        } while (lVar5 != 0);
      }
      else {
        *puVar1 = 6;
      }
      break;
    case 6:
      *(undefined4 *)(param_1 + 0x41c) = 1;
      *(undefined1 *)(param_1 + 0x410) = 1;
      *(undefined1 *)(param_1 + 0x417) = 1;
      *puVar1 = 7;
      if (*(char *)(param_1 + 0x8cc) != '\0') {
        FreeTimerRoutine(param_1);
        FreeMemoryAllocations(param_1,param_2,param_3);
      }
      if (*(int *)(param_1 + 0x8c4) != 6) {
        return;
      }
      if (*(longlong *)(param_1 + 0x8e0) == 0) {
        return;
      }
      StorPortNotification(0,param_1);
      return;
    }
    uVar4 = *puVar1;
  } while( true );
}



===== StartShutdownCallback @ 14000dcb0 =====

void StartShutdownCallback(longlong param_1)

{
  int local_res8 [8];
  
  local_res8[0] = 8;
  StartShutdown(param_1,0,local_res8);
  return;
}



===== UnlockHostDiag @ 14000dcd0 =====

uint UnlockHostDiag(longlong param_1,ushort param_2,int *param_3)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  do {
    **(undefined4 **)(param_1 + 0xa8) = 0;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xa8) = 0xf;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xa8) = 4;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xa8) = 0xb;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xa8) = 2;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xa8) = 7;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xa8) = 0xd;
    LOCK();
    UNLOCK();
    StorPortStallExecution(1000);
    uVar1 = **(uint **)(param_1 + 0xb0);
    if ((uVar1 & 1) != 0) {
      if ((**(uint **)(param_1 + 0x48) & 0x10) == 0) {
        return uVar1;
      }
      **(uint **)(param_1 + 0x48) = **(uint **)(param_1 + 0x48);
      LOCK();
      UNLOCK();
      return uVar1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  LogSystemEvent(param_1,0,0xc004af02,(byte *)"Unlock HostDiagReg FAILED",param_2,param_3);
  *(undefined4 *)(param_1 + 0x20) = 0x1a;
  return 0xffff;
}



===== FreeTimerRoutine @ 14000de00 =====

void FreeTimerRoutine(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x8b8) != 0) {
    StorPortExtendedFunction
              (0x21,param_1,*(longlong *)(param_1 + 0x8b8),StartAdapterResetCallback,0,0,0);
    StorPortExtendedFunction(0x22,param_1,*(undefined8 *)(param_1 + 0x8b8));
    *(undefined8 *)(param_1 + 0x8b8) = 0;
  }
  if (*(longlong *)(param_1 + 0x8d8) != 0) {
    StorPortExtendedFunction
              (0x21,param_1,*(longlong *)(param_1 + 0x8d8),StartShutdownCallback,0,0,0);
    StorPortExtendedFunction(0x22,param_1,*(undefined8 *)(param_1 + 0x8d8));
    *(undefined8 *)(param_1 + 0x8d8) = 0;
  }
  if (*(longlong *)(param_1 + 0xc88) != 0) {
    StorPortExtendedFunction
              (0x21,param_1,*(longlong *)(param_1 + 0xc88),LitServiceActiveListCallback,0,0,0);
    StorPortExtendedFunction(0x22,param_1,*(undefined8 *)(param_1 + 0xc88));
    *(undefined8 *)(param_1 + 0xc88) = 0;
    *(undefined1 *)(param_1 + 0xc80) = 0;
  }
  return;
}



===== GetPendingIOCount @ 14000df00 =====

uint GetPendingIOCount(longlong param_1)

{
  longlong lVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  
  uVar4 = 0;
  plVar5 = *(longlong **)(param_1 + 0x9f0);
  uVar2 = *(short *)(param_1 + 0x368) + 6;
  if (uVar2 == 0) {
    return 0;
  }
  uVar6 = (ulonglong)uVar2;
  do {
    lVar1 = *plVar5;
    uVar3 = uVar4 + 1;
    plVar5 = plVar5 + 3;
    if (lVar1 == 0) {
      uVar3 = CONCAT22((short)(uVar3 >> 0x10),(short)uVar4);
    }
    uVar4 = uVar3 & 0xffff;
    uVar6 = uVar6 - 1;
  } while (uVar6 != 0);
  return uVar3;
}



===== InitTimerRoutine @ 14000df40 =====

void InitTimerRoutine(longlong param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x420) = 0;
  StorPortNotification(6,param_1,WatchdogTimer,1000000);
  if (*(char *)(param_1 + 0x408) == '\0') {
    iVar1 = StorPortExtendedFunction(0x20,param_1,param_1 + 0x8b8);
    if (iVar1 != 0) {
      *(undefined8 *)(param_1 + 0x8b8) = 0;
    }
    iVar1 = StorPortExtendedFunction(0x20,param_1,param_1 + 0x8d8);
    if (iVar1 != 0) {
      *(undefined8 *)(param_1 + 0x8d8) = 0;
    }
  }
  return;
}



===== KillAdapter @ 14000dfd0 =====

void KillAdapter(longlong param_1,int param_2,ushort param_3,int *param_4)

{
  int local_res10 [2];
  
  local_res10[0] = param_2;
  if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x282) != 0)) {
    RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x282,(undefined1 *)local_res10,4,param_3,
                param_4);
  }
  LogOperationalEvent(param_1,local_res10,4,0xc004af02,
                      "Kill Adapter (Driver) - Driver Killed Adcapter, Reason Code Logged",param_3,
                      param_4);
  *(int *)(param_1 + 0x8c4) = local_res10[0];
  *(undefined1 *)(param_1 + 0x438) = 1;
  *(undefined4 *)(param_1 + 0x8a4) = 1;
  *(undefined4 *)(param_1 + 0x428) = 1;
  StartAdapterReset(param_1,0x700,param_3,param_4);
  return;
}



===== PauseController @ 14000e0b0 =====

void PauseController(longlong param_1,uint param_2,ushort param_3,int *param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x40c);
  if ((uVar1 >> (param_2 & 0x1f) & 1) != 0) {
    LogSystemEvent(param_1,0,0xc004af02,(byte *)"Controller paused for same reason",param_3,param_4)
    ;
    return;
  }
  if (uVar1 == 0) {
    StorPortPause(param_1,900);
  }
  else if (param_2 == 0) {
    *(uint *)(param_1 + 0x40c) = uVar1 & 0xfffffffb;
    LogSystemEvent(param_1,0,0xc004af02,
                   (byte *)"Change Pause reason from PrepareForReset to SoftReset",param_3,param_4);
  }
  *(uint *)(param_1 + 0x40c) = *(uint *)(param_1 + 0x40c) | 1 << (param_2 & 0x1f);
  return;
}



===== ProcessParseArgumentString @ 14000e150 =====

ulonglong ProcessParseArgumentString(char *param_1,char *param_2,int *param_3)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  uVar10 = 0;
  uVar8 = 0;
  *param_3 = 0;
  uVar9 = 0;
  cVar1 = *param_1;
  pcVar4 = param_1;
  while (cVar1 != '\0') {
    pcVar4 = pcVar4 + 1;
    uVar8 = uVar8 + 1;
    cVar1 = *pcVar4;
  }
  cVar1 = *param_2;
  pcVar4 = param_2;
  if (cVar1 != '\0') {
    do {
      pcVar4 = pcVar4 + 1;
      uVar9 = uVar9 + 1;
    } while (*pcVar4 != '\0');
    if (uVar8 < uVar9) {
LAB_14000e345:
      return (ulonglong)pcVar4 & 0xffffffffffffff00;
    }
  }
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          cVar2 = *param_1;
          pcVar4 = (char *)0x0;
          if ((cVar2 != ' ') && (cVar2 != '\t')) break;
          param_1 = param_1 + 1;
        }
        if (cVar2 == '\0') goto LAB_14000e345;
        cVar6 = cVar1;
        if (cVar2 == cVar1) {
          pcVar4 = param_2 + -(longlong)param_1;
          pcVar5 = param_1;
          do {
            param_1 = pcVar5 + 1;
            if (*pcVar5 == '\0') goto LAB_14000e345;
            cVar6 = pcVar4[(longlong)param_1];
            pcVar5 = param_1;
          } while (*param_1 == cVar6);
        }
        if (cVar6 == '\0') break;
        do {
          cVar2 = *param_1;
          pcVar4 = (char *)0x0;
          if (cVar2 == '\0') goto LAB_14000e345;
          param_1 = param_1 + 1;
        } while (cVar2 != ';');
      }
      for (; (cVar2 = *param_1, cVar2 == ' ' || (cVar2 == '\t')); param_1 = param_1 + 1) {
      }
      if (cVar2 == '=') break;
      do {
        cVar2 = *param_1;
        pcVar4 = (char *)0x0;
        if (cVar2 == '\0') goto LAB_14000e345;
        param_1 = param_1 + 1;
      } while (cVar2 != ';');
    }
    do {
      do {
        pcVar5 = param_1;
        bVar3 = pcVar5[1];
        param_1 = pcVar5 + 1;
      } while (bVar3 == 0x20);
    } while (bVar3 == 9);
    pcVar4 = (char *)0x0;
    if (bVar3 == 0) goto LAB_14000e345;
    if (bVar3 != 0x3b) break;
    param_1 = pcVar5 + 2;
  }
  pcVar4 = (char *)0x0;
  if ((bVar3 == 0x30) && (pcVar5[2] == 'x')) {
    bVar3 = pcVar5[3];
    if (bVar3 != 0) {
      while ((0x3b < bVar3 || ((0x800000100000200U >> ((ulonglong)bVar3 & 0x3f) & 1) == 0))) {
        pcVar4 = (char *)(ulonglong)(bVar3 - 0x30);
        if ((byte)(bVar3 - 0x30) < 10) {
          iVar7 = *param_3 * 0x10 + -0x30;
        }
        else {
          pcVar4 = (char *)(ulonglong)(bVar3 - 0x61);
          if (5 < (byte)(bVar3 - 0x61)) goto LAB_14000e345;
          iVar7 = *param_3 * 0x10 + -0x57;
        }
        uVar10 = (ulonglong)((int)uVar10 + 1);
        *param_3 = (char)bVar3 + iVar7;
        bVar3 = param_1[uVar10 + 2];
        if (bVar3 == 0) {
          return CONCAT71((int7)((ulonglong)pcVar4 >> 8),1);
        }
      }
    }
  }
  else {
    do {
      if ((bVar3 < 0x3c) && ((0x800000100000200U >> ((ulonglong)bVar3 & 0x3f) & 1) != 0)) break;
      pcVar4 = (char *)(ulonglong)(bVar3 - 0x30);
      if (9 < (byte)(bVar3 - 0x30)) goto LAB_14000e345;
      uVar10 = (ulonglong)((int)uVar10 + 1);
      pcVar4 = (char *)(ulonglong)(uint)(int)(char)bVar3;
      *param_3 = (int)(char)bVar3 + (*param_3 * 5 + -0x18) * 2;
      bVar3 = param_1[uVar10];
    } while (bVar3 != 0);
  }
  return CONCAT71((int7)((ulonglong)pcVar4 >> 8),1);
}



===== ProcessRegistrySettings @ 14000e360 =====

void ProcessRegistrySettings(longlong param_1,char *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint local_res8 [2];
  
  uVar2 = ProcessParseArgumentString(param_2,"dump",(int *)local_res8);
  if (((char)uVar2 != '\0') && (local_res8[0] != 0)) {
    *(undefined1 *)(param_1 + 0x408) = 1;
  }
  uVar2 = ProcessParseArgumentString(param_2,"ReqQEntries",(int *)local_res8);
  if ((char)uVar2 == '\0') {
    uVar1 = 0x200;
LAB_14000e3ce:
    *(short *)(param_1 + 0x35c) = (short)uVar1;
  }
  else {
    uVar1 = local_res8[0];
    if (0x7f < local_res8[0]) goto LAB_14000e3ce;
    *(undefined2 *)(param_1 + 0x35c) = 0x80;
  }
  uVar2 = ProcessParseArgumentString(param_2,"RepQEntries",(int *)local_res8);
  if ((char)uVar2 == '\0') {
    uVar1 = 0x400;
  }
  else {
    uVar1 = local_res8[0];
    if (local_res8[0] < 0x80) {
      *(undefined2 *)(param_1 + 0x35e) = 0x80;
      goto LAB_14000e40a;
    }
  }
  *(short *)(param_1 + 0x35e) = (short)uVar1;
LAB_14000e40a:
  *(undefined4 *)(param_1 + 0x8b0) = 100;
  uVar2 = ProcessParseArgumentString(param_2,"defaulttimeout",(int *)local_res8);
  if (((char)uVar2 != '\0') && (10 < local_res8[0])) {
    *(uint *)(param_1 + 0x8b0) = local_res8[0] * 10;
  }
  uVar2 = ProcessParseArgumentString(param_2,"BlockSyncCache",(int *)local_res8);
  if ((char)uVar2 != '\0') {
    *(bool *)(param_1 + 0x397) = local_res8[0] != 0;
  }
  uVar2 = ProcessParseArgumentString(param_2,"MaxSGList",(int *)local_res8);
  if (((char)uVar2 != '\0') && (0x10 < local_res8[0])) {
    *(uint *)(param_1 + 0x9ac) = local_res8[0];
  }
  uVar2 = ProcessParseArgumentString(param_2,"MaxSASQueueDepth",(int *)local_res8);
  if ((char)uVar2 != '\0') {
    if (local_res8[0] == 0) {
      *(undefined2 *)(param_1 + 0x398) = 1;
    }
    else {
      *(short *)(param_1 + 0x398) = (short)local_res8[0];
    }
  }
  uVar2 = ProcessParseArgumentString(param_2,"MaxSATAQueueDepth",(int *)local_res8);
  if ((char)uVar2 != '\0') {
    if (local_res8[0] == 0) {
      *(undefined2 *)(param_1 + 0x39a) = 1;
    }
    else {
      *(short *)(param_1 + 0x39a) = (short)local_res8[0];
    }
  }
  uVar2 = ProcessParseArgumentString(param_2,"MaxNVMeQueueDepth",(int *)local_res8);
  if ((char)uVar2 != '\0') {
    if (local_res8[0] == 0) {
      *(undefined2 *)(param_1 + 0x39c) = 1;
    }
    else {
      *(short *)(param_1 + 0x39c) = (short)local_res8[0];
    }
  }
  uVar2 = ProcessParseArgumentString(param_2,"MaxLDQueueDepth",(int *)local_res8);
  if ((char)uVar2 != '\0') {
    if (local_res8[0] == 0) {
      *(undefined2 *)(param_1 + 0x39e) = 1;
    }
    else {
      *(short *)(param_1 + 0x39e) = (short)local_res8[0];
    }
  }
  uVar2 = ProcessParseArgumentString(param_2,"RTTraceBufferSize",(int *)local_res8);
  if (((char)uVar2 != '\0') && (local_res8[0] != 0)) {
    if ((local_res8[0] & 3) != 0) {
      local_res8[0] = local_res8[0] + (4 - (local_res8[0] & 3));
    }
    RttSetTraceParameters(param_1 + 0xbc8,local_res8[0],2);
  }
  return;
}



===== ResumeController @ 14000e5b0 =====

void ResumeController(longlong param_1,uint param_2,ushort param_3,int *param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x40c);
  if (uVar1 == 0) {
    LogSystemEvent(param_1,0,0xc004af02,(byte *)"Controller was not paused",param_3,param_4);
    return;
  }
  if ((uVar1 >> (param_2 & 0x1f) & 1) == 0) {
    LogSystemEvent(param_1,0,0xc004af02,(byte *)"Controller not paused for current resume",param_3,
                   param_4);
    return;
  }
  uVar1 = uVar1 & ~(1 << (param_2 & 0x1f));
  *(uint *)(param_1 + 0x40c) = uVar1;
  if (uVar1 == 0) {
    StorPortResume();
  }
  if (*(short *)(param_1 + 0x88e) != 0) {
    ProcessDeviceRemoval(param_1,param_3,param_4);
  }
  return;
}



===== SetAdapInfo @ 14000e680 =====

void SetAdapInfo(longlong param_1,longlong param_2,uint param_3)

{
  *(uint *)(param_1 + 0x200) = (uint)*(ushort *)(param_2 + 2);
  *(uint *)(param_1 + 0x204) = (uint)*(byte *)(param_2 + 8);
  *(uint *)(param_1 + 0x208) = (uint)*(ushort *)(param_2 + 0x2e);
  *(uint *)(param_1 + 0x20c) = (uint)*(ushort *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x1f8) = 1;
  memmove((void *)(param_1 + 0x21c),&DAT_140014140,0x78);
  *(undefined4 *)(param_1 + 0x218) = 3;
  *(uint *)(param_1 + 0x214) = param_3 >> 0x10 & 0xff;
  *(uint *)(param_1 + 0x210) = param_3 & 0xffff;
  return;
}



===== StopTimerRoutine @ 14000e710 =====

void StopTimerRoutine(longlong param_1)

{
  StorPortNotification(6,param_1,WatchdogTimer);
  if (*(longlong *)(param_1 + 0x8b8) != 0) {
    StorPortExtendedFunction
              (0x21,param_1,*(longlong *)(param_1 + 0x8b8),StartAdapterResetCallback,0,0,0);
  }
  if (*(longlong *)(param_1 + 0x8d8) != 0) {
    StorPortExtendedFunction
              (0x21,param_1,*(longlong *)(param_1 + 0x8d8),StartShutdownCallback,0,0,0);
  }
  if (*(longlong *)(param_1 + 0xc88) != 0) {
    *(undefined1 *)(param_1 + 0xc80) = 0;
    StorPortExtendedFunction
              (0x21,param_1,*(longlong *)(param_1 + 0xc88),LitServiceActiveListCallback,0,0,0);
  }
  return;
}



===== WatchdogTimer @ 14000e7e0 =====

void WatchdogTimer(longlong param_1)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  char cVar5;
  uint uVar6;
  longlong lVar7;
  byte *pbVar8;
  ushort uVar9;
  ulonglong uVar10;
  int iVar11;
  bool bVar12;
  uint local_res8 [4];
  int local_res18;
  undefined1 local_res1c;
  longlong local_res20;
  int local_48;
  undefined4 local_44;
  
  local_res18 = 9;
  local_res1c = 0;
  if (*(char *)(param_1 + 0x417) == '\0') {
    if (*(char *)(param_1 + 0x411) == '\0') {
      StorPortNotification(6,param_1,WatchdogTimer,1000000);
      return;
    }
    *(longlong *)(param_1 + 0x890) = *(longlong *)(param_1 + 0x890) + 1;
    if ((**(uint **)(param_1 + 0x48) & 2) == 0) {
      if (*(int *)(param_1 + 0x428) == 0) {
        uVar9 = 0;
        if (*(char *)(param_1 + 0x422) != '\0') {
          iVar11 = 0;
          if (*(short *)(param_1 + 0x372) != 0) {
            pbVar8 = (byte *)(*(longlong *)(param_1 + 0x9f8) + 0x16);
            do {
              if ((*(short *)(pbVar8 + -0xe) != 0) && ((*pbVar8 & 2) == 0)) {
                uVar6 = iVar11 >> 0x1f & 0x7f;
                uVar4 = iVar11 + uVar6;
                StorPortSetDeviceQueueDepth
                          (param_1,(int)uVar4 >> 7 & 0xff,(uVar4 & 0x7f) - uVar6 & 0xff,0,
                           *(undefined2 *)(pbVar8 + -4));
              }
              iVar11 = iVar11 + 1;
              pbVar8 = pbVar8 + 0x18;
            } while (iVar11 < (int)(uint)*(ushort *)(param_1 + 0x372));
          }
          *(undefined1 *)(param_1 + 0x422) = 0;
        }
        if (*(short *)(param_1 + 0x88e) != 0) {
          ProcessDeviceRemoval(param_1,0,&local_res18);
        }
        uVar10 = *(ulonglong *)(param_1 + 0x890);
        auVar3._8_8_ = 0;
        auVar3._0_8_ = uVar10;
        lVar7 = SUB168(ZEXT816(0x23456789abcdf013) * auVar3,8);
        if (uVar10 == ((uVar10 - lVar7 >> 1) + lVar7 >> 9) * 900) {
          StorPortQuerySystemTime(&local_res20);
          local_res20 = (local_res20 + -0x19db1ded53e8000) / 10000;
          puVar2 = *(undefined8 **)(param_1 + 0x318);
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
          *(undefined1 *)((longlong)puVar2 + 3) = 8;
          *(undefined1 *)((longlong)puVar2 + 0xb) = 4;
          puVar2[2] = local_res20;
          *(undefined2 *)puVar2 = 0xadb3;
          AdminQueueRequestPost(param_1,puVar2,0,&local_res18);
          uVar10 = *(ulonglong *)(param_1 + 0x890);
        }
        if ((uVar10 == (uVar10 / 0x3c) * 0x3c) &&
           ((((iVar11 = *(int *)(param_1 + 0x8f0), iVar11 != 0 || (*(int *)(param_1 + 0x8f4) != 0))
             && (local_44 = *(undefined4 *)(param_1 + 0x8f4), local_48 = iVar11,
                *(char *)(param_1 + 0xc00) != '\0')) && ((*(uint *)(param_1 + 0xc04) & 0x124) != 0))
           )) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x124,(undefined1 *)&local_48,8,0,
                      &local_res18);
        }
        do {
          LOCK();
          bVar12 = *(int *)(param_1 + 0x788) == 0;
          if (bVar12) {
            *(int *)(param_1 + 0x788) = 1;
          }
          UNLOCK();
        } while (!bVar12);
        if ((*(char *)(param_1 + 0x782) == '\0') && (*(short *)(param_1 + 0x784) != 0)) {
          bVar1 = *(byte *)(param_1 + 0x781);
          uVar10 = (ulonglong)bVar1;
          if (*(char *)(param_1 + 0x78c + uVar10 * 8) != '\0') {
            puVar2 = *(undefined8 **)(param_1 + 0x310);
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
            *(undefined2 *)puVar2 = 0xadb4;
            *(undefined1 *)((longlong)puVar2 + 3) = 5;
            *(undefined1 *)((longlong)puVar2 + 0xc) = *(undefined1 *)(param_1 + 0x78c + uVar10 * 8);
            *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(param_1 + 0x790 + uVar10 * 8);
            AdminQueueRequestPost(param_1,puVar2,0,&local_res18);
            *(undefined1 *)(param_1 + 0x782) = 1;
            *(short *)(param_1 + 0x784) = *(short *)(param_1 + 0x784) + -1;
          }
          *(undefined1 *)(param_1 + 0x78c + uVar10 * 8) = 0;
          cVar5 = '\0';
          if (bVar1 != 0x1f) {
            cVar5 = bVar1 + 1;
          }
          *(undefined4 *)(param_1 + 0x790 + uVar10 * 8) = 0;
          *(char *)(param_1 + 0x781) = cVar5;
        }
        LOCK();
        *(int *)(param_1 + 0x788) = *(int *)(param_1 + 0x788) + -1;
        UNLOCK();
        if (*(int *)(param_1 + 0x424) == 1) {
          if (*(short *)(param_1 + 0x8a0) == 0) {
            *(undefined4 *)(param_1 + 0x8a4) = 1;
            *(undefined4 *)(param_1 + 0x424) = 0;
            StorPortNotification(6,param_1);
            **(undefined4 **)(param_1 + 0xf0) = 0xf001;
            LOCK();
            UNLOCK();
            *(undefined4 *)(param_1 + 0x8c4) = 0xe;
            *(undefined4 *)(param_1 + 0x428) = 1;
            StartAdapterReset(param_1,0x100,0,&local_res18);
            return;
          }
          *(short *)(param_1 + 0x8a0) = *(short *)(param_1 + 0x8a0) + -1;
        }
        if ((*(char *)(param_1 + 0x416) != '\0') &&
           (*(undefined1 *)(param_1 + 0x416) = 0, *(short *)(param_1 + 0x374) != 0)) {
          do {
            StorPortNotification(7,param_1,uVar9);
            uVar9 = uVar9 + 1;
          } while (uVar9 < *(ushort *)(param_1 + 0x374));
        }
        if (*(char *)(param_1 + 0x420) == '\0') {
          StorPortNotification(6,param_1,WatchdogTimer,1000000);
        }
      }
    }
    else {
      local_res8[0] = **(uint **)(param_1 + 0xb8);
      *(uint *)(param_1 + 0x42c) = local_res8[0];
      if ((local_res8[0] & 0xffff) == 0xf005) {
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x299) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x299,(undefined1 *)0x0,0,0,&local_res18
                     );
        }
        LogSystemEvent(param_1,0,0x4004af00,(byte *)"MPI3_SYSIF_FAULT_CODE_FACTORY_RESET detected",0
                       ,&local_res18);
        *(undefined1 *)(param_1 + 0x438) = 1;
        ReturnIOsToSystem(param_1);
        *(undefined1 *)(param_1 + 0x417) = 1;
        return;
      }
      if ((local_res8[0] & 0xffff) != 0xf001) {
        LogSystemEvent(param_1,0,0x4004af00,
                       (byte *)"MPI3_SYSIF_FAULT_CODE_CI_ACTIVATION_RESET detected",0,&local_res18);
      }
      if (*(int *)(param_1 + 0x8a4) == 0) {
        if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x209) != 0)) {
          RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x209,(undefined1 *)local_res8,4,0,
                      &local_res18);
        }
        LogOperationalEvent(param_1,(int *)local_res8,4,0xc004af02,
                            "Soft Reset (Driver) - Initiated Soft Reset, found Adapter in Fault",0,
                            &local_res18);
        *(undefined4 *)(param_1 + 0x8a4) = 1;
        *(undefined4 *)(param_1 + 0x428) = 1;
        StorPortNotification(6,param_1,WatchdogTimer,0);
        **(undefined4 **)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0x42c);
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1 + 0x8c4) = 0xb;
        StartAdapterReset(param_1,0x100,0,&local_res18);
        return;
      }
    }
  }
  return;
}



===== ZeroMemory @ 14000ede0 =====

void ZeroMemory(void *param_1,uint param_2)

{
  if (param_2 == 0) {
    return;
  }
  memset(param_1,0,(ulonglong)param_2);
  return;
}



===== mpi3FunctionControl @ 14000edf0 =====

undefined1
mpi3FunctionControl(longlong param_1,longlong param_2,int param_3,int param_4,char param_5)

{
  if ((param_4 == 0) && (param_3 == 0)) {
    *(bool *)(param_1 + 0x988) = param_5 != '\0';
  }
  ScsiPortWmiPostProcess(param_2,'\x01',0);
  return 1;
}



===== mpi3QueryWmiDataBlock @ 14000ee30 =====

char mpi3QueryWmiDataBlock
               (undefined8 param_1,longlong *param_2,int param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,uint param_7)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = '\x01';
  *(undefined4 *)(*(longlong *)(*param_2 + 0x68) + 0x2c) = 0;
  if (param_3 == 0) {
    uVar2 = 4;
    if (param_7 < 4) {
      cVar1 = '\x12';
    }
    else {
      *param_6 = 4;
    }
  }
  else {
    cVar1 = '\x04';
  }
  ScsiPortWmiPostProcess((longlong)param_2,cVar1,uVar2);
  return cVar1;
}



===== mpi3QueryWmiRegInfo @ 14000ee90 =====

char * mpi3QueryWmiRegInfo(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = L"MofResource";
  return "eason Code Logged";
}



===== mpi3WmiInitialize @ 14000eea0 =====

void mpi3WmiInitialize(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x8f8) = 1;
  *(undefined ***)(param_1 + 0x900) = &mpi3drvGuidList;
  *(code **)(param_1 + 0x908) = mpi3QueryWmiRegInfo;
  *(code **)(param_1 + 0x910) = mpi3QueryWmiDataBlock;
  *(code **)(param_1 + 0x930) = mpi3FunctionControl;
  *(undefined8 *)(param_1 + 0x928) = 0;
  *(undefined8 *)(param_1 + 0x920) = 0;
  *(undefined8 *)(param_1 + 0x918) = 0;
  return;
}



===== mpi3WmiSrb @ 14000ef00 =====

undefined8 mpi3WmiSrb(longlong param_1,ushort *param_2,ushort param_3,int *param_4)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  int *piVar4;
  uint uVar5;
  ulonglong uVar6;
  int *piVar7;
  
  puVar1 = *(undefined8 **)(param_2 + 0x34);
  piVar7 = (int *)0x0;
  uVar6 = 0;
  if (*(int *)(param_2 + 0x1c) == 0) {
LAB_14000efbf:
    if ((*(char *)(param_1 + 0xc00) != '\0') && ((*(uint *)(param_1 + 0xc04) & 0x22f) != 0)) {
      RttLogEvent(param_1,(longlong *)(param_1 + 0xbc8),0x22f,(undefined1 *)param_2,(uint)*param_2,
                  param_3,param_4);
    }
    LogSystemEvent(param_1,0,0xc004af02,
                   (byte *)"ExSRB does not have an expected CDB16 or 32 data block(WMI)",param_3,
                   param_4);
    uVar2 = 4;
LAB_14000f01f:
    param_2[0x1e] = 0;
    param_2[0x1f] = 0;
  }
  else {
    do {
      piVar4 = (int *)((ulonglong)*(uint *)(param_2 + uVar6 * 2 + 0x3c) + (longlong)param_2);
      if (*piVar4 == 0x60) {
        puVar1[8] = piVar4;
        piVar7 = piVar4;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *(uint *)(param_2 + 0x1c));
    if (piVar7 == (int *)0x0) goto LAB_14000efbf;
    if ((*(byte *)((longlong)piVar7 + 9) & 1) == 0) {
      uVar2 = 1;
      goto LAB_14000f01f;
    }
    *puVar1 = param_2;
    puVar1[4] = 0;
    uVar3 = ScsiPortWmiDispatchFunction
                      ((uint *)(param_1 + 0x8f8),*(byte *)(piVar7 + 2),param_1,(longlong)puVar1,
                       *(ulonglong **)(piVar7 + 4),*(uint *)(param_2 + 0x1e),
                       *(uint **)(param_2 + 0x20));
    if ((char)uVar3 != '\0') goto LAB_14000f036;
    *(undefined4 *)(param_2 + 0x1e) = *(undefined4 *)((longlong)puVar1 + 0x1c);
    uVar2 = *(undefined1 *)((longlong)puVar1 + 0x19);
  }
  *(undefined1 *)((longlong)param_2 + 3) = uVar2;
  uVar3 = StorPortNotification(0,param_1,param_2);
LAB_14000f036:
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== __security_check_cookie @ 14000f070 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __report_gsfailure @ 14000f090 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
                    /* WARNING: Could not recover jumptable at 0x00014000f097. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetScatterGatherList();
  return;
}



===== StorPortGetScatterGatherList @ 14000f097 =====

void StorPortGetScatterGatherList(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f097. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetScatterGatherList();
  return;
}



===== StorPortGetPhysicalAddress @ 14000f09d =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f09d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortNotification @ 14000f0a3 =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f0a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== StorPortExtendedFunction @ 14000f0a9 =====

void StorPortExtendedFunction(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f0a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortExtendedFunction();
  return;
}



===== __GSHandlerCheck @ 14000f0b0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000f0d0 =====

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



===== StorPortPauseDevice @ 14000f130 =====

void StorPortPauseDevice(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f130. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortPauseDevice();
  return;
}



===== StorPortResumeDevice @ 14000f136 =====

void StorPortResumeDevice(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f136. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortResumeDevice();
  return;
}



===== StorPortInitialize @ 14000f13c =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f13c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortGetBusData @ 14000f142 =====

void StorPortGetBusData(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f142. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetBusData();
  return;
}



===== StorPortGetDeviceBase @ 14000f148 =====

void StorPortGetDeviceBase(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f148. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetDeviceBase();
  return;
}



===== StorPortGetUncachedExtension @ 14000f14e =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f14e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortStallExecution @ 14000f154 =====

void StorPortStallExecution(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== StorPortQuerySystemTime @ 14000f15a =====

void StorPortQuerySystemTime(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f15a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortQuerySystemTime();
  return;
}



===== StorPortBusy @ 14000f160 =====

void StorPortBusy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortBusy();
  return;
}



===== StorPortPause @ 14000f166 =====

void StorPortPause(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f166. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortPause();
  return;
}



===== StorPortResume @ 14000f16c =====

void StorPortResume(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f16c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortResume();
  return;
}



===== StorPortSetDeviceQueueDepth @ 14000f172 =====

void StorPortSetDeviceQueueDepth(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f172. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortSetDeviceQueueDepth();
  return;
}



===== __cpu_features_init @ 14000f180 =====

/* WARNING: Removing unreachable block (ram,0x00014000f1bd) */
/* WARNING: Removing unreachable block (ram,0x00014000f199) */
/* WARNING: Removing unreachable block (ram,0x00014000f18a) */

undefined8 __cpu_features_init(void)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  byte bVar5;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  bVar5 = 0;
  lVar2 = cpuid_Version_info(1);
  uVar3 = *(uint *)(lVar2 + 0xc);
  if (6 < *piVar1) {
    bVar5 = 0;
    lVar2 = cpuid_Extended_Feature_Enumeration_info(7);
    if ((*(uint *)(lVar2 + 4) >> 9 & 1) != 0) {
      bVar5 = 2;
    }
  }
  if (((((uVar3 >> 0x14 & 1) != 0) && ((uVar3 >> 0x1b & 1) != 0)) && ((uVar3 >> 0x1c & 1) != 0)) &&
     (uVar4 = xinuse(0), (in_XCR0 & (byte)uVar4 & 6) == 6)) {
    bVar5 = bVar5 | 4;
  }
  __isa_info = bVar5 | 1;
  return 0;
}



===== ScsiPortWmiDispatchFunction @ 14000f21c =====

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



===== ScsiPortWmiFireLogicalUnitEvent @ 14000f2c0 =====

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



===== ScsiPortWmiPostProcess @ 14000f348 =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  
  cVar1 = ScsiWmipPostProcess(*(char *)(param_1 + 0x18),*(uint **)(param_1 + 0x10),
                              *(uint *)(param_1 + 8),param_3,param_2,(uint *)(param_1 + 0x1c));
  *(char *)(param_1 + 0x19) = cVar1;
  return;
}



===== ScsiWmipFindGuid @ 14000f380 =====

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



===== ScsiWmipPostProcess @ 14000f3e0 =====

char ScsiWmipPostProcess(char param_1,uint *param_2,uint param_3,uint param_4,char param_5,
                        uint *param_6)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = 0;
  if (param_1 == '\0') {
    uVar6 = param_2[0xc];
    uVar1 = param_2[0xd];
    uVar5 = (ulonglong)uVar1;
    uVar2 = uVar6 + param_4;
    if (param_5 != '\x01') goto LAB_14000f504;
    if (uVar2 <= param_3) {
      if (((0x2f < param_3) && (*param_2 = uVar2, uVar7 = uVar2, (char)param_2[0xb] < '\0')) &&
         (puVar4 = param_2 + 0xf, uVar1 != 0)) {
        uVar3 = uVar5;
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
              *puVar4 = uVar6;
              uVar6 = uVar6 + 7 + puVar4[1] & 0xfffffff8;
            }
            uVar3 = uVar3 + 8;
            puVar4 = puVar4 + 2;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
      }
      goto LAB_14000f526;
    }
    param_5 = '\x12';
LAB_14000f50a:
    if (param_3 < 0x38) goto LAB_14000f526;
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
        goto LAB_14000f526;
      }
LAB_14000f504:
      if (param_5 != '\x12') goto LAB_14000f526;
      goto LAB_14000f50a;
    }
    if (param_1 != '\t') goto LAB_14000f526;
    uVar6 = param_2[0xf] + param_4;
    if (param_5 == '\x01') {
      if (0x47 < param_3) {
        *param_2 = uVar6;
        param_2[0x10] = param_4;
        uVar7 = uVar6;
      }
      goto LAB_14000f526;
    }
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_14000f526;
    param_2[0xc] = uVar6;
  }
  *param_2 = 0x38;
  param_2[0xb] = 0x20;
  param_5 = '\x01';
  uVar7 = 0x38;
LAB_14000f526:
  *param_6 = uVar7;
  return param_5;
}



===== ScsiWmipProcessRequest @ 14000f550 =====

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
LAB_14000f648:
      *param_8 = 0;
      cVar5 = '\x04';
      goto LAB_14000f956;
    }
    if (((byte)(param_2 - 1) < 3) || (param_2 == 9)) {
      uVar6 = param_7[0xd];
      if (((char)param_7[0xb] < '\0') && (local_38[0] <= uVar6)) goto LAB_14000f648;
    }
    else {
      uVar6 = 0;
    }
  }
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_14000f68d;
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
              goto LAB_14000f97d;
            }
            goto LAB_14000f990;
          }
LAB_14000f68d:
          cVar5 = '\x04';
          goto LAB_14000f992;
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
LAB_14000f76b:
      cVar5 = (*pcVar8)(param_3,param_4,local_res10[0],uVar6,uVar19,puVar14,iVar16,lVar12);
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar20 = 0;
      uVar17 = 0;
      goto LAB_14000f981;
    }
  }
  else if (param_2 == 6) {
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar17 = 1;
LAB_14000f97d:
      uVar20 = 1;
LAB_14000f981:
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
              goto LAB_14000f76b;
            }
          }
          cVar5 = '\x04';
          goto LAB_14000f992;
        }
        goto LAB_14000f68d;
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
          goto LAB_14000f949;
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
LAB_14000f949:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_14000f956:
      psVar4[0] = 1;
      psVar4[1] = 0;
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar20 = 0;
      uVar17 = 1;
      goto LAB_14000f981;
    }
  }
LAB_14000f990:
  cVar5 = '\x01';
LAB_14000f992:
  psVar4[0] = 1;
  psVar4[1] = 0;
  return cVar5;
}



===== __chkstk @ 14000f9b5 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000f9b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== _guard_check_icall @ 14000f9c0 =====

void _guard_check_icall(void)

{
  return;
}



===== _guard_dispatch_icall @ 14000f9e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000f9e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000fa00 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000fa40 =====

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



===== memset @ 14000fd00 =====

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



===== __memset_repmovs @ 14000fe40 =====

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



===== __memset_query @ 14000fec0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== entry @ 140016000 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001602c =====

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


