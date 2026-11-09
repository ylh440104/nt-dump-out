
===== LSImpiFindAdapter @ 1c0001000 =====

undefined8
LSImpiFindAdapter(longlong *param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                 longlong param_5)

{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  uint *puVar6;
  undefined8 uVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  ushort uVar10;
  ushort uVar11;
  uint uVar12;
  undefined1 uVar13;
  short sVar14;
  longlong lVar15;
  ushort uVar16;
  int iVar17;
  undefined8 *puVar18;
  uint uVar19;
  int iVar20;
  size_t _Size;
  undefined8 *puVar21;
  int iVar22;
  bool bVar23;
  undefined1 local_res8;
  byte *in_stack_ffffffffffffff88;
  undefined4 uVar24;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  
  local_50 = 0x40;
  local_40 = 0;
  uVar19 = 0;
  local_48 = 0x50;
  local_54 = 0;
  local_4c = 0x10;
  local_44 = 0;
  local_34 = 0;
  local_res8 = 0x20;
  local_3c = 0;
  local_30 = 0;
  if (*param_1 != 0) {
    memset(param_1,0,0x1368);
  }
  puVar18 = (undefined8 *)0x0;
  puVar21 = (undefined8 *)0x0;
  if (*(int *)(*(undefined8 **)(param_5 + 0x38) + 1) != 0) {
    lVar15 = 2;
    puVar4 = *(undefined8 **)(param_5 + 0x38);
    do {
      if (*(int *)(puVar4 + 1) != 0) {
        if ((*(char *)((longlong)puVar4 + 0xc) == '\0') || (puVar21 != (undefined8 *)0x0)) {
          puVar18 = puVar4;
        }
        else {
          puVar21 = puVar4;
        }
      }
      lVar15 = lVar15 + -1;
      puVar4 = puVar4 + 2;
    } while (lVar15 != 0);
    if (puVar21 != (undefined8 *)0x0) {
      if (puVar18 != (undefined8 *)0x0) {
        *(undefined4 *)(param_1 + 0x1e9) = *(undefined4 *)puVar18;
      }
      *(undefined4 *)((longlong)param_1 + 0xf4c) = *(undefined4 *)puVar21;
      *(undefined4 *)(param_1 + 0x1ea) = *(undefined4 *)((longlong)puVar21 + 4);
      *(undefined1 *)((longlong)param_1 + 0xf41) = 0xff;
      *(undefined4 *)((longlong)param_1 + 0xf54) = 3;
      *(undefined4 *)((longlong)param_1 + 0x1354) = 1;
      lVar15 = StorPortGetDeviceBase
                         (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),*puVar21
                          ,*(undefined4 *)(puVar21 + 1),*(char *)((longlong)puVar21 + 0xc) == '\0');
      param_1[1] = lVar15;
      if (puVar18 != (undefined8 *)0x0) {
        lVar15 = StorPortGetDeviceBase
                           (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),
                            *puVar18,*(undefined4 *)(puVar18 + 1),
                            *(char *)((longlong)puVar18 + 0xc) == '\0');
        param_1[10] = lVar15;
      }
      pbVar1 = (byte *)(param_1 + 0x178);
      in_stack_ffffffffffffff88 = pbVar1;
      local_38 = StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),
                                    *(undefined4 *)(param_5 + 100),pbVar1,0x100);
      if (2 < local_38) {
        uVar19 = (uint)*(ushort *)((longlong)param_1 + 0xbc2);
        *(uint *)(param_1 + 0x35) = uVar19;
        if ((uVar19 - 0x30 & 0xfffffffd) == 0) {
          *(ushort *)((longlong)param_1 + 0x134) = *(ushort *)((longlong)param_1 + 0x134) | 0x80;
          local_48 = CONCAT22(local_48._2_2_,0x40);
        }
        else if ((uVar19 - 0x50 < 0x13) && ((0x40151U >> (uVar19 - 0x50 & 0x1f) & 1) != 0)) {
          *(ushort *)((longlong)param_1 + 0x134) = *(ushort *)((longlong)param_1 + 0x134) | 0x200;
          *(undefined4 *)(param_1 + 0x3f) = 0x28000;
        }
        else {
          *(ushort *)((longlong)param_1 + 0x134) = *(ushort *)((longlong)param_1 + 0x134) | 0x100;
        }
        local_34 = *(int *)(param_5 + 4) << 8 | *(uint *)(param_5 + 100);
        GetCimData((longlong)param_1,(longlong)pbVar1,local_34);
        if ((uVar19 - 0x626 & 0xfffffffd) == 0) {
          *(undefined4 *)((longlong)param_1 + 0x1ac) = 1;
        }
        if ((((uVar19 == 0x30) && (*(byte *)(param_1 + 0x179) < 8)) ||
            (((uVar19 - 0x626 & 0xfffffffd) == 0 && ((char)param_1[0x179] == '\0')))) &&
           (*(undefined1 *)(param_1 + 0xcd) = 1, uVar19 != 0x30)) {
          *(undefined1 *)((longlong)param_1 + 0x81) = 1;
        }
      }
      puVar6 = (uint *)param_1[1];
      if ((puVar6 == (uint *)0x0) ||
         ((param_1[10] == 0 && ((*(byte *)((longlong)param_1 + 0x134) & 0x80) != 0)))) {
        uVar24 = 0xad010002;
        goto LAB_1c0002973;
      }
      param_1[2] = (longlong)puVar6;
      param_1[3] = (longlong)(puVar6 + 1);
      param_1[4] = (longlong)(puVar6 + 2);
      param_1[5] = (longlong)(puVar6 + 0xc);
      param_1[6] = (longlong)(puVar6 + 0xd);
      param_1[7] = (longlong)(puVar6 + 0x10);
      param_1[8] = (longlong)(puVar6 + 0x11);
      param_1[9] = (longlong)(puVar6 + 0x12);
      if ((*puVar6 & 0x7000000) == 0x3000000) {
        uVar24 = 0xad010018;
        goto LAB_1c0002973;
      }
      *(undefined2 *)((longlong)param_1 + 0x1b6) = 0;
      if (param_4 != (char *)0x0) {
        uVar5 = ProcessParseArgumentString(param_4,"ResetType",(int *)&local_58);
        if (((char)uVar5 != '\0') && (local_58 != 0)) {
          *(short *)((longlong)param_1 + 0x1b6) = (short)local_58;
        }
        ProcessParseArgumentString(param_4,"dump",(int *)&local_54);
        ProcessParseArgumentString(param_4,"ntldr",(int *)&local_44);
        local_54 = local_54 | local_44;
        if (local_54 != 0) {
          *(uint *)(param_1 + 0x39) = local_54;
          *(ushort *)((longlong)param_1 + 0x134) = *(ushort *)((longlong)param_1 + 0x134) | 0x100;
        }
      }
      *(undefined4 *)(param_1 + 0x3f) = 0x12c00;
      if ((0x69 < local_38) && ((char)param_1[0xcd] != '\0')) {
        in_stack_ffffffffffffff88 = (byte *)((longlong)param_1 + 0xc2a);
        *in_stack_ffffffffffffff88 = *in_stack_ffffffffffffff88 & 0x8f;
        StorPortSetBusDataByOffset
                  (param_1,4,*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 100),
                   in_stack_ffffffffffffff88,0x6a,2);
      }
      ClearResetHistoryBit((longlong)param_1);
      if (((uVar19 - 0x56 & 0xfffffffd) == 0) || ((*(uint *)param_1[2] >> 0x1b & 1) != 0)) {
        KickStart((longlong)param_1);
      }
      puVar6 = (uint *)param_1[2];
      uVar19 = 0;
      while (uVar12 = *puVar6 & 0xf0000000, uVar12 != 0x10000000) {
        if (uVar12 == 0x20000000) {
          *(undefined4 *)param_1[2] = 0x40000000;
          LOCK();
          UNLOCK();
          SymWaitForResponse((longlong)param_1);
        }
        else if (uVar12 != 0) {
          *(undefined4 *)param_1[2] = 0x41000000;
          LOCK();
          UNLOCK();
          uVar5 = SymWaitForResponse((longlong)param_1);
          if (((char)uVar5 == '\0') && (uVar7 = KickStart((longlong)param_1), (char)uVar7 == '\0'))
          {
            return 2;
          }
        }
        lVar15 = 100;
        do {
          StorPortStallExecution();
          lVar15 = lVar15 + -1;
        } while (lVar15 != 0);
        if (200 < uVar19) {
          uVar24 = 0xad010003;
          goto LAB_1c0001496;
        }
        uVar19 = uVar19 + 1;
        puVar6 = (uint *)param_1[2];
      }
      uVar5 = IssueIOCFacts((longlong)param_1);
      if ((char)uVar5 == '\0') {
        return 2;
      }
      uVar16 = *(ushort *)((longlong)param_1 + 300);
      local_44 = (uint)*(ushort *)((longlong)param_1 + 0x132);
      if ((*(byte *)((longlong)param_1 + 0x134) & 0x80) == 0) {
        *(undefined2 *)((longlong)param_1 + 0x1ea) = 0x80;
        *(undefined4 *)((longlong)param_1 + 0x1cc) = 0x40;
      }
      else {
        *(undefined4 *)((longlong)param_1 + 0x1cc) = 0x3f;
        *(undefined2 *)((longlong)param_1 + 0x1ea) = 0x10;
      }
      uVar19 = 0;
      *(undefined4 *)(param_1 + 0x3a) = 0x20;
      if (*(short *)((longlong)param_1 + 0x1dc) != 0) {
        do {
          param_1[0x40] = 0;
          *(undefined4 *)(param_1 + 0x41) = 0;
          memset(param_1 + 0x50,0,0x28);
          *(undefined1 *)((longlong)param_1 + 0x203) = 5;
          *(char *)((longlong)param_1 + 0x206) = (char)uVar19;
          bVar2 = SendMessageViaHandShake((longlong)param_1,0,3);
          if ((!bVar2) ||
             (lVar15 = ReceiveDataViaHandshake((longlong)param_1,0x14), (char)lVar15 == '\0')) {
            uVar24 = 0xad01000f;
LAB_1c0001496:
            StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00
                             ,6,uVar24);
            return 2;
          }
          if ((*(byte *)((longlong)param_1 + 0x29a) & 8) != 0) {
            if ((*(ushort *)((longlong)param_1 + 0x134) & 0x200) == 0) {
              uVar10 = *(ushort *)((longlong)param_1 + 0x296);
            }
            else {
              uVar10 = (short)param_1[0x53] + 1;
            }
            *(ushort *)(param_1 + 0x3c) = (short)param_1[0x3c] + uVar10;
            *(undefined2 *)((longlong)param_1 + 0x1ec) = *(undefined2 *)((longlong)param_1 + 0x29e);
            uVar11 = *(ushort *)((longlong)param_1 + 0x1ea);
            if (uVar11 < uVar10) {
              uVar11 = uVar10;
            }
            *(ushort *)((longlong)param_1 + 0x1e2) = uVar11;
            uVar10 = *(ushort *)(param_1 + 0x53);
            *(ushort *)((longlong)param_1 + 0x1ee) = uVar10;
            if (0x7f < uVar10) {
              if ((char)*(ushort *)((longlong)param_1 + 0x134) < '\0') {
                in_stack_ffffffffffffff88 =
                     (byte *)((ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00);
                StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff88,6,0xad010019);
              }
              else if (0xff < uVar10) {
                *(undefined2 *)((longlong)param_1 + 0x1ee) = 0xff;
              }
            }
          }
          uVar19 = uVar19 + 1;
        } while (uVar19 < *(ushort *)((longlong)param_1 + 0x1dc));
      }
      uVar10 = *(ushort *)((longlong)param_1 + 0x1ea);
      if (uVar10 < *(ushort *)((longlong)param_1 + 0x1e2)) {
        uVar11 = *(ushort *)(param_1 + 0x3c);
        *(ushort *)((longlong)param_1 + 0x1e6) = uVar10;
        *(undefined2 *)((longlong)param_1 + 0x1e4) = 1;
        if (uVar10 < uVar11) {
          sVar14 = 1;
          do {
            uVar11 = uVar11 - uVar10;
            sVar14 = sVar14 + 1;
          } while (uVar10 < uVar11);
          *(short *)((longlong)param_1 + 0x1e4) = sVar14;
        }
      }
      else {
        *(undefined2 *)((longlong)param_1 + 0x1e4) = *(undefined2 *)((longlong)param_1 + 0x1dc);
        *(ushort *)((longlong)param_1 + 0x1e6) = *(ushort *)((longlong)param_1 + 0x1e2);
      }
      if (8 < *(ushort *)((longlong)param_1 + 0x1e4)) {
        *(undefined2 *)((longlong)param_1 + 0x1e4) = 8;
      }
      *(undefined4 *)((longlong)param_1 + 0x2dc) = 0xffffffff;
      *(undefined1 *)(param_1 + 0x5b) = 0xff;
      if (((*(ushort *)((longlong)param_1 + 0x134) & 0x100) != 0) && (local_54 == 0)) {
        *(undefined4 *)(param_1 + 0x1ab) = 1;
        *(ushort *)((longlong)param_1 + 0x134) = *(ushort *)((longlong)param_1 + 0x134) | 0x800;
      }
      if (param_4 != (char *)0x0) {
        uVar5 = ProcessParseArgumentString(param_4,"NumberOfReplyBuffers",(int *)&local_58);
        if (((char)uVar5 != '\0') && (local_50 = 0x40, local_58 != 0)) {
          local_50 = local_58 & 0xffff;
        }
        uVar5 = ProcessParseArgumentString(param_4,"SizeOfReplyBuffer",(int *)&local_58);
        if (((char)uVar5 != '\0') && (0x24 < local_58)) {
          local_48 = CONCAT22(local_48._2_2_,((ushort)local_58 & 0xf) + (ushort)local_58);
        }
        uVar5 = ProcessParseArgumentString(param_4,"NumberOfRequestMessageBuffers",(int *)&local_58)
        ;
        if (((char)uVar5 != '\0') && (local_40 = local_58, local_58 < 0x11)) {
          local_40 = 0x10;
        }
        uVar5 = ProcessParseArgumentString(param_4,"LogExceptionEvents",(int *)&local_58);
        if (((char)uVar5 != '\0') && (local_58 != 0)) {
          *(undefined2 *)(param_1 + 0x37) = 1;
        }
        uVar5 = ProcessParseArgumentString(param_4,"DisableRescan",(int *)&local_58);
        if (((char)uVar5 != '\0') && (local_58 != 0)) {
          *(undefined2 *)(param_1 + 0x3e) = 1;
        }
        uVar5 = ProcessParseArgumentString(param_4,"StopOnBusReset",(int *)&local_58);
        if (((char)uVar5 != '\0') && (local_58 != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x65d) = 1;
        }
        uVar5 = ProcessParseArgumentString(param_4,"StopOnDiagReset",(int *)&local_58);
        if (((char)uVar5 != '\0') && (local_58 != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x65e) = 1;
        }
        uVar5 = ProcessParseArgumentString(param_4,"DisableFwQueueFullHandling",(int *)&local_58);
        if (((char)uVar5 != '\0') && (local_58 != 0)) {
          *(undefined1 *)((longlong)param_1 + 0x679) = 0;
        }
        uVar5 = ProcessParseArgumentString(param_4,"HWFaultLimit",(int *)&local_58);
        if (((char)uVar5 != '\0') && (local_58 != 0)) {
          *(short *)((longlong)param_1 + 0x1be) = (short)local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"MaxSGList",(int *)&local_58);
        if (((char)uVar5 != '\0') && (local_58 - 0x11 < 0x1f1)) {
          *(uint *)((longlong)param_1 + 0x1d4) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"MaximumTargetQueueDepth",(int *)&local_58);
        if ((char)uVar5 != '\0') {
          uVar19 = local_58;
          if (local_58 == 0) {
            uVar19 = 1;
          }
          *(uint *)((longlong)param_1 + 0x1cc) = uVar19;
        }
        uVar10 = *(ushort *)((longlong)param_1 + 0x134);
        if ((uVar10 & 0x100) == 0) {
          if ((char)uVar10 < '\0') {
            uVar5 = ProcessParseArgumentString(param_4,"Enable160IU",(int *)&local_58);
            if (((char)uVar5 != '\0') && (local_58 != 0)) {
              *(ushort *)((longlong)param_1 + 0x134) = uVar10 | 8;
            }
            uVar5 = ProcessParseArgumentString(param_4,"Enable160QAS",(int *)&local_58);
            if (((char)uVar5 != '\0') && (local_58 != 0)) {
              *(ushort *)((longlong)param_1 + 0x134) = *(ushort *)((longlong)param_1 + 0x134) | 0x10
              ;
            }
            uVar5 = ProcessParseArgumentString(param_4,"Disable320QAS",(int *)&local_58);
            if (((char)uVar5 != '\0') && (local_58 != 0)) {
              *(ushort *)((longlong)param_1 + 0x134) = *(ushort *)((longlong)param_1 + 0x134) | 0x20
              ;
            }
            uVar5 = ProcessParseArgumentString(param_4,"ScsiMaxLunLimit",(int *)&local_58);
            if ((((char)uVar5 != '\0') && (local_58 != 0)) &&
               (local_res8 = (undefined1)local_58, 0xff < local_58)) {
              local_res8 = 0xff;
            }
          }
          else if ((uVar10 & 0x200) != 0) {
            uVar5 = ProcessParseArgumentString(param_4,"DisableSASPersClear",(int *)&local_58);
            if (((char)uVar5 != '\0') && (local_58 != 0)) {
              *(ushort *)((longlong)param_1 + 0x134) = uVar10 | 0x1000;
            }
            uVar5 = ProcessParseArgumentString(param_4,"MaxSASQueueDepth",(int *)&local_58);
            if ((char)uVar5 != '\0') {
              uVar19 = local_58;
              if (local_58 == 0) {
                uVar19 = 1;
              }
              *(uint *)((longlong)param_1 + 0x1cc) = uVar19;
            }
            uVar5 = ProcessParseArgumentString(param_4,"MaxSATAQueueDepth",(int *)&local_58);
            if ((char)uVar5 != '\0') {
              uVar19 = local_58;
              if (local_58 == 0) {
                uVar19 = 1;
              }
              *(uint *)(param_1 + 0x3a) = uVar19;
            }
          }
        }
        else {
          uVar5 = ProcessParseArgumentString(param_4,"NoBoardReset",(int *)&local_58);
          if (((char)uVar5 != '\0') && (local_58 != 0)) {
            *(short *)((longlong)param_1 + 0x1b4) = (short)local_58;
          }
          uVar5 = ProcessParseArgumentString(param_4,"MPIOMode",(int *)&local_58);
          if (((char)uVar5 != '\0') && (local_58 != 0)) {
            *(char *)(param_1 + 0xcc) = (char)local_58;
          }
          uVar5 = ProcessParseArgumentString(param_4,"MaxInBandBuffers",(int *)&local_58);
          if (((char)uVar5 != '\0') && (local_58 != 0)) {
            if (local_58 < 4) {
              local_58 = 4;
            }
            if (local_58 < 0x100) {
              local_4c = CONCAT22((short)(local_4c >> 0x10),(short)local_58);
            }
          }
          uVar5 = ProcessParseArgumentString(param_4,"LUN_Pers",(int *)&local_58);
          if (((char)uVar5 != '\0') && (local_58 == 0)) {
            *(ushort *)((longlong)param_1 + 0x134) = uVar10 & 0xf7ff;
          }
          uVar5 = ProcessParseArgumentString(param_4,"EEDP_T10_Enable",(int *)&local_58);
          if (((char)uVar5 != '\0') && (local_58 != 0)) {
            *(undefined1 *)((longlong)param_1 + 0x66c) = 1;
          }
          uVar5 = ProcessParseArgumentString(param_4,"CheckFcLinkSpeed",(int *)&local_58);
          if ((char)uVar5 != '\0') {
            *(uint *)(param_1 + 0x1ab) = local_58;
          }
          uVar5 = ProcessParseArgumentString(param_4,"Enable520B",(int *)&local_58);
          if (((char)uVar5 != '\0') && (local_58 != 0)) {
            *(undefined1 *)((longlong)param_1 + 0x66d) = 1;
          }
        }
        uVar10 = *(ushort *)((longlong)param_1 + 0x134);
        if ((((char)uVar10 < '\0') &&
            (uVar5 = ProcessParseArgumentString(param_4,"DisableDomainValidation",(int *)&local_58),
            (char)uVar5 != '\0')) && (local_58 != 0)) {
          *(ushort *)((longlong)param_1 + 0x134) = uVar10 | 2;
        }
        uVar5 = ProcessParseArgumentString(param_4,"IntCoalTimeout",(int *)&local_58);
        if ((char)uVar5 != '\0') {
          *(uint *)((longlong)param_1 + 0x2dc) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"IntCoalDepth",(int *)&local_58);
        if ((char)uVar5 != '\0') {
          *(undefined1 *)(param_1 + 0x5b) = (undefined1)local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"EnaDiag",(int *)&local_58);
        bVar2 = false;
        if ((char)uVar5 != '\0') {
          bVar2 = false;
          if (local_58 != 0) {
            bVar2 = true;
          }
        }
        uVar5 = ProcessParseArgumentString(param_4,"SSBuffSize",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xd15) != '\0')))) {
          *(uint *)(param_1 + 0x19f) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"SSImmed",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xd15) != '\0')))) {
          *(undefined1 *)((longlong)param_1 + 0xd14) = 1;
        }
        uVar5 = ProcessParseArgumentString(param_4,"TBuffSize",(int *)&local_58);
        if (((((char)uVar5 != '\0') && (bVar2)) && (local_58 != 0)) &&
           (*(char *)((longlong)param_1 + 0xce5) != '\0')) {
          *(uint *)(param_1 + 0x199) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"TImmed",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xce5) != '\0')))) {
          *(undefined1 *)((longlong)param_1 + 0xce4) = 1;
        }
        uVar5 = ProcessParseArgumentString(param_4,"EXBuffSize",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xd45) != '\0')))) {
          *(uint *)(param_1 + 0x1a5) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"EXImmed",(int *)&local_58);
        if (((((char)uVar5 != '\0') && (bVar2)) && (local_58 != 0)) &&
           (*(char *)((longlong)param_1 + 0xd45) != '\0')) {
          *(undefined1 *)((longlong)param_1 + 0xd44) = 1;
        }
        uVar5 = ProcessParseArgumentString(param_4,"EXType",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xd45) != '\0')))) {
          *(uint *)(param_1 + 0x1a6) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"EXDW1",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xd45) != '\0')))) {
          *(uint *)((longlong)param_1 + 0xd34) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"EXDW2",(int *)&local_58);
        if (((((char)uVar5 != '\0') && (bVar2)) && (local_58 != 0)) &&
           (*(char *)((longlong)param_1 + 0xd45) != '\0')) {
          *(uint *)(param_1 + 0x1a7) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"EXDW3",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xd45) != '\0')))) {
          *(uint *)((longlong)param_1 + 0xd3c) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"EXDW4",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xd45) != '\0')))) {
          *(uint *)(param_1 + 0x1a8) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"SSDW1",(int *)&local_58);
        if (((((char)uVar5 != '\0') && (bVar2)) && (local_58 != 0)) &&
           (*(char *)((longlong)param_1 + 0xd15) != '\0')) {
          *(uint *)((longlong)param_1 + 0xd04) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"SSDW2",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xd15) != '\0')))) {
          *(uint *)(param_1 + 0x1a1) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"SSDW3",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xd15) != '\0')))) {
          *(uint *)((longlong)param_1 + 0xd0c) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"SSDW4",(int *)&local_58);
        if (((((char)uVar5 != '\0') && (bVar2)) && (local_58 != 0)) &&
           (*(char *)((longlong)param_1 + 0xd15) != '\0')) {
          *(uint *)(param_1 + 0x1a2) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"TDW1",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xce5) != '\0')))) {
          *(uint *)((longlong)param_1 + 0xcd4) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"TDW2",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xce5) != '\0')))) {
          *(uint *)(param_1 + 0x19b) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"TDW3",(int *)&local_58);
        if (((((char)uVar5 != '\0') && (bVar2)) && (local_58 != 0)) &&
           (*(char *)((longlong)param_1 + 0xce5) != '\0')) {
          *(uint *)((longlong)param_1 + 0xcdc) = local_58;
        }
        uVar5 = ProcessParseArgumentString(param_4,"TDW4",(int *)&local_58);
        if ((((char)uVar5 != '\0') && (bVar2)) &&
           ((local_58 != 0 && (*(char *)((longlong)param_1 + 0xce5) != '\0')))) {
          *(uint *)(param_1 + 0x19c) = local_58;
        }
      }
      uVar13 = 0xff;
      if ((*(byte *)((longlong)param_1 + 0x134) & 0x80) != 0) {
        uVar13 = local_res8;
      }
      *(undefined1 *)(param_5 + 0x92) = uVar13;
      if (*(char *)(param_5 + 0x90) == -0x80) {
        *(undefined1 *)(param_5 + 0x90) = 1;
        *(ushort *)((longlong)param_1 + 0x134) = *(ushort *)((longlong)param_1 + 0x134) | 1;
      }
      uVar10 = (*(ushort *)((longlong)param_1 + 0x134) & 1) << 2 | 8;
      uVar5 = (ulonglong)(ushort)(uVar16 - 0x38) / (ulonglong)(longlong)(int)(uint)uVar10;
      iVar17 = (int)uVar5;
      *(short *)((longlong)param_1 + 0x124) = (short)uVar5;
      uVar19 = (uint)uVar10;
      *(short *)(param_1 + 0x25) =
           (short)((ulonglong)(ushort)(uVar16 - 8) / (ulonglong)(longlong)(int)(uint)uVar10);
      *(int *)(param_1 + 0x23) = (int)((longlong)(int)(iVar17 * uVar19) + 0x30U >> 2);
      if (*(char *)((longlong)param_1 + 0x66c) != '\0') {
        uVar5 = (ulonglong)(ushort)(uVar16 - 0x70) / (ulonglong)(longlong)(int)uVar19;
        iVar17 = (int)uVar5;
        *(short *)((longlong)param_1 + 0x126) = (short)uVar5;
        *(int *)((longlong)param_1 + 0x11c) = (int)((longlong)(int)(iVar17 * uVar19) + 0x68U >> 2);
      }
      iVar20 = 0x101;
      if (*(int *)((longlong)param_1 + 0x1d4) != 0) {
        iVar20 = *(int *)((longlong)param_1 + 0x1d4);
      }
      *(int *)(param_5 + 0x1c) = iVar20;
      uVar10 = (short)((int)((uint)*(ushort *)(param_5 + 0x1c) - iVar17) /
                      (int)(uint)*(ushort *)(param_1 + 0x25)) + 1;
      if ((ushort)local_44 < uVar10) {
        *(uint *)(param_5 + 0x1c) = (local_44 & 0xffff) * (uint)*(ushort *)(param_1 + 0x25) + iVar17
        ;
        uVar19 = local_44;
      }
      else {
        uVar19 = (uint)uVar10;
      }
      if (local_54 == 0) {
        uVar5 = (ulonglong)local_50;
        uVar10 = (ushort)local_40;
        if ((uVar10 != 0) && (uVar10 < *(ushort *)(param_1 + 0x3b))) {
          *(ushort *)(param_1 + 0x3b) = uVar10;
        }
      }
      else {
        *(undefined2 *)(param_1 + 0x3b) = 4;
        uVar5 = 4;
        *(undefined4 *)(param_5 + 0x1c) = 0x11;
        uVar19 = 2;
        local_4c = 0;
      }
      if (((*(ushort *)((longlong)param_1 + 0x134) & 0x100) != 0) && (local_54 == 0)) {
        uVar5 = (ulonglong)(ushort)((short)param_1[0x3b] + 0x10);
      }
      uVar10 = *(ushort *)((longlong)param_1 + 0x134) & 0x200;
      if ((uVar10 != 0) && (local_54 == 0)) {
        uVar5 = (ulonglong)(ushort)((short)param_1[0x3c] + 1);
      }
      local_50 = (uint)uVar5;
      uVar11 = *(ushort *)(param_1 + 0x3b);
      *(short *)((longlong)param_1 + 0x12a) = (short)local_48;
      *(ushort *)((longlong)param_1 + 300) = uVar16;
      if (*(ushort *)(param_1 + 0x26) < (ushort)uVar5) {
        local_50 = (uint)CONCAT62((int6)(uVar5 >> 0x10),*(ushort *)(param_1 + 0x26));
      }
      *(short *)((longlong)param_1 + 0x12e) = (short)local_50;
      if (uVar10 != 0) {
        local_3c = *(ushort *)(param_1 + 0x3c) + 8;
        *(int *)(param_1 + 0x26a) = local_3c;
      }
      *(undefined4 *)(param_5 + 0x18) = 0xffffff;
      *(undefined1 *)(param_5 + 0x61) = *(undefined1 *)((longlong)param_1 + 0x1e6);
      *(undefined1 *)(param_5 + 0x51) = 1;
      *(undefined1 *)(param_5 + 0x54) = 0;
      *(undefined1 *)(param_5 + 0x48) = *(undefined1 *)((longlong)param_1 + 0x1e4);
      *(undefined1 *)(param_5 + 0x91) = 1;
      *(undefined4 *)(param_5 + 0x94) = 1;
      if (*(char *)((longlong)param_1 + 0x81) == '\0') {
        *(undefined4 *)(param_5 + 0xa0) = 1;
        *(code **)(param_5 + 0x98) = LSImpiMSIIsr;
        bVar3 = *(byte *)((longlong)param_1 + 0xbf4);
        if (bVar3 != 0) {
          do {
            if (*(char *)((longlong)param_1 + (ulonglong)bVar3 + 0xbc0) == '\x11') break;
            bVar3 = *(byte *)((longlong)param_1 + (ulonglong)bVar3 + 0xbc1);
          } while (bVar3 != 0);
          if ((bVar3 != 0) && (*(char *)((longlong)param_1 + (ulonglong)bVar3 + 0xbc3) < '\0')) {
            param_1[0x32] =
                 ((ulonglong)*(uint *)((longlong)param_1 + (ulonglong)bVar3 + 0xbc4) & 0xfffffff8) +
                 param_1[1];
          }
        }
      }
      if ((-1 < *(char *)((longlong)param_1 + 0x134)) && (local_54 == 0)) {
        *(undefined4 *)(param_1 + 0x11) = 3;
        param_1[0x12] = (longlong)&LSImpiSasGuidList;
        param_1[0x13] = (longlong)LSImpiQueryWmiRegInfo;
        param_1[0x14] = (longlong)LSImpiQueryWmiDataBlock;
        param_1[0x18] = (longlong)LSImpiFunctionControl;
        param_1[0x17] = (longlong)LSImpiExecuteWmiMethod;
        param_1[0x16] = 0;
        param_1[0x15] = 0;
        *(uint *)(param_1 + 0x21) = local_34;
        *(undefined4 *)(param_1 + 0x66) = 0x380;
      }
      if (((*(ushort *)((longlong)param_1 + 0x134) & 0x100) != 0) && (local_54 == 0)) {
        CheckInBandSupport((longlong)param_1);
      }
      *(int *)(param_5 + 0x8c) =
           *(int *)(param_5 + 0x8c) + ((uVar19 & 0xffff) + 1) * (uint)uVar16 + -0x100;
      iVar20 = (local_48 & 0xffff) * (local_50 & 0xffff);
      iVar17 = (uint)uVar11 * 0x20 + 0x524 + iVar20 + (uint)uVar16 * 5;
      if (local_54 == 0) {
        iVar17 = iVar17 + (int)param_1[0x34];
      }
      if (*(int *)((longlong)param_1 + 0x1fc) != 0) {
        iVar17 = iVar17 + (int)param_1[0x3f];
      }
      uVar16 = *(ushort *)((longlong)param_1 + 0x134);
      if ((uVar16 & 0x400) != 0) {
        *(short *)((longlong)param_1 + 0xb94) = (short)local_4c;
        iVar17 = iVar17 + (local_4c & 0xffff) * 0x148;
      }
      if (((uVar16 & 0x100) != 0) && (local_54 == 0)) {
        iVar17 = iVar17 + (uint)*(ushort *)(param_1 + 0x3c) * 0x18 + 0x800;
      }
      if ((uVar16 & 0x200) != 0) {
        iVar17 = iVar17 + (local_3c + 0x1a) * 0x10;
      }
      plVar8 = param_1 + 0x199;
      lVar15 = 3;
      iVar22 = local_30;
      do {
        iVar22 = iVar22 + (int)*plVar8;
        plVar8 = plVar8 + 6;
        lVar15 = lVar15 + -1;
      } while (lVar15 != 0);
      iVar17 = iVar17 + iVar22;
      if ((char)uVar16 < '\0') {
        iVar17 = iVar17 + 0xc20;
      }
      while( true ) {
        lVar15 = StorPortGetUncachedExtension(param_1,param_5,iVar17);
        *param_1 = lVar15;
        if (lVar15 != 0) break;
        in_stack_ffffffffffffff88 =
             (byte *)((ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00);
        StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff88,6,0xad010004);
        if (iVar22 == 0) {
          return 2;
        }
        iVar17 = iVar17 - iVar22;
        puVar9 = (undefined1 *)((longlong)param_1 + 0xce5);
        iVar22 = 0;
        lVar15 = 3;
        do {
          *puVar9 = 0;
          puVar9 = puVar9 + 0x30;
          lVar15 = lVar15 + -1;
        } while (lVar15 != 0);
      }
      uVar19 = StorPortGetPhysicalAddress(param_1,0,lVar15,&local_38);
      iVar17 = 0x10 - (uVar19 & 0xf);
      lVar15 = (longlong)iVar17 + *param_1;
      param_1[0x27] = lVar15;
      uVar19 = iVar17 + uVar19;
      *(uint *)(param_1 + 0x24) = uVar19;
      param_1[0xb] = lVar15 - (ulonglong)uVar19;
      param_1[0x28] = iVar20 + lVar15;
      LsiMpiPartitionMemory((longlong)param_1);
      if ((*(ushort *)((longlong)param_1 + 0x134) & 0x100) != 0) {
        if ((*(ushort *)((longlong)param_1 + 0x134) & 0x400) != 0) {
          memset(param_1 + 0x40,0,0x28);
          param_1[0x50] = 0;
          param_1[0x51] = 0;
          param_1[0x52] = 0;
          *(undefined1 *)((longlong)param_1 + 0x203) = 4;
          *(undefined1 *)(param_1 + 0x40) = 1;
          *(int *)((longlong)param_1 + 0x214) = (int)param_1[0x172];
          _Size = (ulonglong)*(byte *)((longlong)param_1 + 0x215) * 4;
          *(int *)((longlong)param_1 + 0x21c) = (int)_Size + -0x2f000000;
          *(int *)(param_1 + 0x44) = (int)param_1[0x175] - (int)param_1[0xb];
          bVar2 = SendMessageViaHandShake((longlong)param_1,0,10);
          if (((bVar2) &&
              (lVar15 = ReceiveDataViaHandshake((longlong)param_1,0xc), (char)lVar15 != '\0')) &&
             (*(short *)((longlong)param_1 + 0x28e) == 0)) {
            memcpy((void *)((longlong)param_1 + 0xb84),(void *)param_1[0x175],_Size);
            if (*(uint *)(param_1 + 0x171) < 4) {
              *(undefined4 *)(param_1 + 0x174) = 0;
              *(undefined2 *)((longlong)param_1 + 0xb96) =
                   *(undefined2 *)((longlong)param_1 + 0xb94);
              if (*(ushort *)((longlong)param_1 + 0xb8c) < *(ushort *)((longlong)param_1 + 0xb94)) {
                *(ushort *)((longlong)param_1 + 0xb96) = *(ushort *)((longlong)param_1 + 0xb8c);
              }
              goto LAB_1c000258c;
            }
            in_stack_ffffffffffffff88 =
                 (byte *)((ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00);
            StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff88,6,0xad010025);
          }
          *(ushort *)((longlong)param_1 + 0x134) = *(ushort *)((longlong)param_1 + 0x134) & 0xfbff;
        }
LAB_1c000258c:
        MPIOCompatibility((longlong)param_1);
      }
      uVar7 = SendIOCInitMessage((longlong)param_1);
      if ((char)uVar7 == '\0') {
LAB_1c0002924:
        StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00,6,
                         0xad010006);
        return 2;
      }
      bVar23 = *(short *)((longlong)param_1 + 0x1dc) != 0;
      bVar2 = false;
      uVar16 = 0;
      while (bVar23) {
        param_1[0x40] = 0;
        *(undefined4 *)(param_1 + 0x41) = 0;
        param_1[0x50] = 0;
        param_1[0x51] = 0;
        *(undefined4 *)(param_1 + 0x52) = 0;
        *(undefined1 *)((longlong)param_1 + 0x203) = 6;
        *(char *)((longlong)param_1 + 0x206) = (char)uVar16;
        bVar23 = SendMessageViaHandShake((longlong)param_1,0,3);
        if ((!bVar23) ||
           (lVar15 = ReceiveDataViaHandshake((longlong)param_1,10), (char)lVar15 == '\0')) {
          bVar2 = true;
          break;
        }
        uVar16 = uVar16 + 1;
        bVar23 = uVar16 < *(ushort *)((longlong)param_1 + 0x1dc);
      }
      if ((*(uint *)param_1[4] & 0x20) != 0) {
        ClearResetHistoryBit((longlong)param_1);
      }
      if (bVar2) goto LAB_1c0002924;
      if (-1 < *(char *)((longlong)param_1 + 0x134)) goto LAB_1c000274a;
      if (*(byte *)(param_5 + 0x49) != 0xff) {
        *(ushort *)((longlong)param_1 + 0x1ee) = (ushort)*(byte *)(param_5 + 0x49);
        goto LAB_1c000274a;
      }
      plVar8 = param_1 + 0x40;
      memset(plVar8,0,0x28);
      param_1[0x50] = 0;
      param_1[0x51] = 0;
      param_1[0x52] = 0;
      *(undefined1 *)((longlong)param_1 + 0x203) = 4;
      *(undefined1 *)plVar8 = 0;
      *(undefined4 *)((longlong)param_1 + 0x214) = 0x3020000;
      bVar2 = SendMessageViaHandShake((longlong)param_1,0,10);
      if (((!bVar2) ||
          (lVar15 = ReceiveDataViaHandshake((longlong)param_1,0xc), (char)lVar15 == '\0')) ||
         (*(short *)((longlong)param_1 + 0x28e) != 0)) {
LAB_1c0002732:
        uVar16 = 7;
      }
      else {
        *(undefined1 *)plVar8 = 6;
        *(uint *)((longlong)param_1 + 0x214) = *(uint *)((longlong)param_1 + 0x294);
        *(undefined4 *)((longlong)param_1 + 0x21c) = 0xd1000000;
        *(int *)(param_1 + 0x44) = (int)param_1[0x1b2] - (int)param_1[0xb];
        *(uint *)((longlong)param_1 + 0x21c) =
             (*(uint *)((longlong)param_1 + 0x294) >> 8 & 0xff) << 2 | 0xd1000000;
        bVar2 = SendMessageViaHandShake((longlong)param_1,0,10);
        if (((!bVar2) ||
            (lVar15 = ReceiveDataViaHandshake((longlong)param_1,0xc), (char)lVar15 == '\0')) ||
           (*(short *)((longlong)param_1 + 0x28e) != 0)) goto LAB_1c0002732;
        uVar16 = *(ushort *)(param_1[0x1b2] + 8) & 0xf;
      }
      *(ushort *)((longlong)param_1 + 0x1ee) = uVar16;
LAB_1c000274a:
      uVar13 = *(undefined1 *)((longlong)param_1 + 0x1ee);
      if (((*(char *)((longlong)param_1 + 0x134) < '\0') &&
          (*(int *)((longlong)param_1 + 0x2f4) != 0xe11)) &&
         ((*(int *)((longlong)param_1 + 0x2f4) != 0x103c &&
          (uVar19 = 0, *(char *)(param_5 + 0x48) != '\0')))) {
        do {
          uVar5 = (ulonglong)uVar19;
          uVar19 = uVar19 + 1;
          *(undefined1 *)(uVar5 + 0x49 + param_5) = uVar13;
        } while (uVar19 < *(byte *)(param_5 + 0x48));
      }
      *(undefined1 *)((longlong)param_1 + 0x325) = uVar13;
      if ((((*(ushort *)((longlong)param_1 + 0x134) & 0x100) != 0) &&
          (0x100 < *(ushort *)((longlong)param_1 + 0x1f2))) &&
         ((2 < *(int *)((longlong)param_1 + 0x2fc) - 0x1004U &&
          (((param_4 != (char *)0x0 &&
            (uVar5 = ProcessParseArgumentString(param_4,"UseLinkReset",(int *)&local_58),
            (char)uVar5 != '\0')) && (local_58 != 0)))))) {
        *(undefined1 *)((longlong)param_1 + 0x669) = 1;
      }
      if (*(uint *)((longlong)param_1 + 0x1fc) != 0) {
        if (*(uint *)(param_1 + 0x3f) < *(uint *)((longlong)param_1 + 0x1fc)) {
          StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00,6
                           ,0xad010022);
          return 2;
        }
        param_1[0x40] = 0;
        param_1[0x41] = 0;
        param_1[0x42] = 0;
        param_1[0x43] = 0;
        *(undefined4 *)(param_1 + 0x44) = 0;
        param_1[0x50] = 0;
        param_1[0x51] = 0;
        param_1[0x52] = 0;
        *(undefined1 *)((longlong)param_1 + 0x203) = 0x12;
        *(undefined1 *)(param_1 + 0x40) = 0;
        *(undefined2 *)((longlong)param_1 + 0x20e) = 0xc;
        *(undefined4 *)(param_1 + 0x43) = *(undefined4 *)((longlong)param_1 + 0x1fc);
        *(int *)((longlong)param_1 + 0x21c) = *(int *)((longlong)param_1 + 0x1fc) + -0x2f000000;
        *(int *)(param_1 + 0x44) = (int)param_1[0x33] - (int)param_1[0xb];
        bVar2 = SendMessageViaHandShake((longlong)param_1,0,9);
        if (((!bVar2) ||
            (lVar15 = ReceiveDataViaHandshake((longlong)param_1,0xc), (char)lVar15 == '\0')) ||
           (*(int *)((longlong)param_1 + 0x294) != *(int *)((longlong)param_1 + 0x1fc))) {
          StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00,6
                           ,0xad010022);
          *(undefined4 *)((longlong)param_1 + 0x1fc) = 0;
        }
      }
      *(undefined1 *)((longlong)param_1 + 0x681) = 0;
      StorPortNotification(6,param_1,WatchdogTimer,1000000);
      return 1;
    }
  }
  uVar24 = 0xad010001;
LAB_1c0002973:
  StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00,6,uVar24)
  ;
  return 0;
}



===== LSImpiHWInitialize @ 1c00029b0 =====

ulonglong LSImpiHWInitialize(longlong param_1)

{
  ushort *puVar1;
  ushort uVar2;
  undefined4 *puVar3;
  bool bVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  uint *puVar8;
  longlong lVar9;
  undefined2 uVar10;
  undefined4 uVar11;
  int *piVar12;
  ushort uVar13;
  byte bVar14;
  uint uVar15;
  undefined2 *puVar16;
  byte *pbVar17;
  bool bVar18;
  char cVar19;
  undefined4 local_res8 [2];
  undefined4 *in_stack_ffffffffffffffb8;
  
  uVar2 = *(ushort *)(param_1 + 0x12a);
  if ((*(char *)(param_1 + 0x81) == '\0') &&
     (iVar5 = StorPortExtendedFunction(0xd,param_1,0), iVar5 == 0)) {
    *(undefined1 *)(param_1 + 0x80) = 1;
  }
  do {
    puVar8 = *(uint **)(param_1 + 0x10);
    if ((*puVar8 & 0xf0000000) != 0x20000000) break;
    uVar15 = 0;
    if (*(short *)(param_1 + 0x12e) != 0) {
      iVar5 = 0;
      do {
        **(int **)(param_1 + 0x40) = *(int *)(param_1 + 0x120) + iVar5;
        LOCK();
        UNLOCK();
        uVar15 = uVar15 + 1;
        iVar5 = iVar5 + (uint)uVar2;
      } while (uVar15 < *(ushort *)(param_1 + 0x12e));
    }
    **(undefined4 **)(param_1 + 0x30) = 9;
    LOCK();
    UNLOCK();
    bVar14 = 0;
    do {
      piVar12 = (int *)(((ulonglong)bVar14 + 0x44) * 0x30 + param_1);
      if ((*(char *)((longlong)piVar12 + 0x25) != '\0') &&
         (((char)piVar12[9] != '\0' || (*(char *)((longlong)piVar12 + 0x27) != '\0')))) {
        uVar6 = PostFwDiagBuffer(param_1,piVar12,'\x01');
        if ((char)uVar6 == '\0') {
          in_stack_ffffffffffffffb8 =
               (undefined4 *)((ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00);
          StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8,6,0xad01002a);
          break;
        }
        uVar13 = 0;
        do {
          uVar7 = LSImpiMSIIsr(param_1);
          if ((char)uVar7 != '\0') break;
          StorPortStallExecution(500);
          uVar13 = uVar13 + 1;
        } while (uVar13 < 4000);
      }
      bVar14 = bVar14 + 1;
    } while (bVar14 < 3);
    if (*(char *)(param_1 + 0x134) < '\0') {
      if (*(char *)(param_1 + 0x66a) != '\0') {
        if (*(char *)(param_1 + 0xd62) != -1) {
          local_res8[0] = *(undefined4 *)(param_1 + 0xe3c);
          bVar14 = 0;
          puVar3 = *(undefined4 **)(param_1 + 0xe70);
          do {
            *(undefined1 *)(param_1 + 0xd62) = 0xf0;
            cVar19 = bVar14 != 0x10;
            if (bVar14 < 0x10) {
              uVar6 = (ulonglong)bVar14;
              uVar15 = *(uint *)(param_1 + 0xed8 + uVar6 * 4);
              *(uint *)(param_1 + 0xed4) = uVar15;
              if ((char)uVar15 != '\0') {
                uVar11 = 0;
                if ((char)(uVar15 >> 8) == '\0') {
                  uVar11 = 4;
                }
                puVar3[3] = uVar11;
                if ((uVar15 & 0x100000) != 0) {
                  puVar3[3] = puVar3[3] | 2;
                }
                BuildScsiDevicePage1
                          (param_1,(longlong)puVar3,*(ushort *)(param_1 + 0xe78 + uVar6 * 2));
                if (*(char *)(param_1 + 0xe9c + uVar6) == '\v') {
                  puVar3[1] = puVar3[1] & 0xfffffffb;
                }
                uVar15 = (uint)bVar14;
                cVar19 = '\x02';
                in_stack_ffffffffffffffb8 = puVar3;
                goto LAB_1c0002bea;
              }
            }
            else {
              if ((bool)cVar19) {
                in_stack_ffffffffffffffb8 = *(undefined4 **)(param_1 + 0xe58);
                local_res8[0] = *in_stack_ffffffffffffffb8;
              }
              else {
                local_res8[0] = 0x1030000;
                in_stack_ffffffffffffffb8 = (undefined4 *)0x0;
              }
              uVar15 = 0;
LAB_1c0002bea:
              SendConfigPageMessage(param_1,cVar19,local_res8,uVar15,(int)in_stack_ffffffffffffffb8)
              ;
              uVar13 = 0;
              do {
                uVar7 = LSImpiMSIIsr(param_1);
                if ((char)uVar7 != '\0') break;
                StorPortStallExecution(500);
                uVar13 = uVar13 + 1;
              } while (uVar13 < 500);
            }
            bVar14 = bVar14 + 1;
          } while (bVar14 < 0x12);
          *(undefined1 *)(param_1 + 0xd62) = 0;
        }
        goto LAB_1c0002cd5;
      }
      cVar19 = ReadPortPages(param_1);
      puVar8 = (uint *)CONCAT71(extraout_var,cVar19);
      if (cVar19 != '\0') {
        if (*(longlong *)(param_1 + 0xe48) != 0) {
          uVar10 = 1;
          if (((*(byte *)(param_1 + 0x134) & 2) != 0) ||
             (((byte)*(undefined4 *)(*(longlong *)(param_1 + 0xe48) + 4) & 0x60) == 0x60)) {
            uVar10 = 0x11;
          }
          puVar16 = (undefined2 *)(param_1 + 0xe78);
          for (lVar9 = 0x10; lVar9 != 0; lVar9 = lVar9 + -1) {
            *puVar16 = uVar10;
            puVar16 = puVar16 + 1;
          }
          lVar9 = *(longlong *)(param_1 + 0xe50);
          if ((lVar9 != 0) && (*(byte *)(lVar9 + 8) != 0)) {
            pbVar17 = (byte *)(lVar9 + 0xc);
            uVar6 = (ulonglong)*(byte *)(lVar9 + 8);
            do {
              bVar14 = *pbVar17;
              uVar7 = CheckPhysDisk(param_1,bVar14);
              if ((char)uVar7 == '\0') {
                puVar1 = (ushort *)(param_1 + 0xe78 + (ulonglong)bVar14 * 2);
                *puVar1 = *puVar1 & 0xfffe;
              }
              pbVar17 = pbVar17 + 8;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
        }
        goto LAB_1c0002cd5;
      }
    }
    else {
LAB_1c0002cd5:
      if ((*(ushort *)(param_1 + 0x134) & 0x200) != 0) {
        ReadAndSetSASPages(param_1);
      }
      if ((*(char *)(param_1 + 0x134) < '\0') && (*(char *)(param_1 + 0x65c) != '\0')) {
        LSImpiReset(param_1,0);
      }
      if (((*(ushort *)(param_1 + 0x134) & 0x100) != 0) && (*(int *)(param_1 + 0x1c8) == 0)) {
        cVar19 = ReadFcPortPages(param_1);
        puVar8 = (uint *)CONCAT71(extraout_var_00,cVar19);
        if (cVar19 == '\0') goto LAB_1c0002d39;
      }
      puVar8 = (uint *)EnableDisableEvents(param_1,'\x01');
      if ((char)puVar8 != '\0') {
        uVar6 = (ulonglong)*(ushort *)(param_1 + 0x134);
        if (((*(ushort *)(param_1 + 0x134) & 0x100) != 0) && (*(int *)(param_1 + 0x1c8) == 0)) {
          uVar6 = UpdatePersistencyTable(param_1);
          *(undefined1 *)(param_1 + 0xd60) = 1;
        }
        **(undefined4 **)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x1ac);
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1 + 0xf54) = 1;
        *(undefined1 *)(param_1 + 0x66a) = 1;
        return CONCAT71((int7)(uVar6 >> 8),1);
      }
    }
LAB_1c0002d39:
    if (*(char *)(param_1 + 0x66b) != '\0') break;
    *(undefined1 *)(param_1 + 0x66b) = 1;
    puVar8 = (uint *)KickStart(param_1);
    if ((char)puVar8 == '\0') break;
    LsiMpiPartitionMemory(param_1);
    TestFWUploadNeeded(param_1);
    puVar8 = (uint *)SendIOCInitMessage(param_1);
    if ((char)puVar8 == '\0') break;
    bVar18 = *(short *)(param_1 + 0x1dc) != 0;
    bVar4 = false;
    uVar13 = 0;
    while (bVar18) {
      *(undefined8 *)(param_1 + 0x200) = 0;
      *(undefined4 *)(param_1 + 0x208) = 0;
      *(undefined8 *)(param_1 + 0x280) = 0;
      *(undefined8 *)(param_1 + 0x288) = 0;
      *(undefined4 *)(param_1 + 0x290) = 0;
      *(undefined1 *)(param_1 + 0x203) = 6;
      *(char *)(param_1 + 0x206) = (char)uVar13;
      bVar18 = SendMessageViaHandShake(param_1,0,3);
      if ((!bVar18) || (lVar9 = ReceiveDataViaHandshake(param_1,10), (char)lVar9 == '\0')) {
        bVar4 = true;
        break;
      }
      uVar13 = uVar13 + 1;
      bVar18 = uVar13 < *(ushort *)(param_1 + 0x1dc);
    }
    puVar8 = (uint *)(ulonglong)**(uint **)(param_1 + 0x20);
    if ((**(uint **)(param_1 + 0x20) & 0x20) != 0) {
      puVar8 = (uint *)ClearResetHistoryBit(param_1);
    }
  } while (!bVar4);
  return (ulonglong)puVar8 & 0xffffffffffffff00;
}



===== LSImpiOSReset @ 1c0002e80 =====

longlong LSImpiOSReset(longlong param_1,uint param_2)

{
  longlong lVar1;
  uint local_res10 [6];
  
  if (*(uint *)(param_1 + 0xf68) < 0xfffffffe) {
    *(uint *)(param_1 + 0xf68) = *(uint *)(param_1 + 0xf68) + 1;
  }
  if (param_2 < *(ushort *)(param_1 + 0x1e4)) {
    local_res10[0] = param_2;
    lVar1 = StorPortSynchronizeAccess(param_1,SynchronizeReset,local_res10);
  }
  else {
    lVar1 = (ulonglong)(byte)(*(ushort *)(param_1 + 0x1e4) >> 8) << 8;
  }
  return lVar1;
}



===== LSImpiBuildIo @ 1c0002ed0 =====

undefined8 LSImpiBuildIo(longlong param_1,longlong param_2)

{
  uint *_Dst;
  byte bVar1;
  byte bVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  undefined8 in_RAX;
  uint7 uVar9;
  char *pcVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar10;
  bool bVar11;
  undefined1 local_res8 [8];
  
  bVar1 = *(byte *)(param_2 + 2);
  uVar9 = (uint7)((ulonglong)in_RAX >> 8);
  uVar7 = CONCAT71(uVar9,bVar1);
  puVar3 = *(uint **)(param_2 + 0x38);
  bVar2 = *(byte *)(param_2 + 0x48);
  if (bVar1 == 0) {
    if ((((*(ushort *)(param_1 + 0x134) & 0x2000) == 0) ||
        (bVar1 = (&OpCodeProt)[bVar2], bVar1 == 0)) ||
       (pcVar6 = (char *)StorPortGetLogicalUnit
                                   (param_1,*(undefined1 *)(param_2 + 5),
                                    *(undefined1 *)(param_2 + 6),*(undefined1 *)(param_2 + 7)),
       *pcVar6 == '\0')) {
      uVar5 = *(uint *)(param_2 + 0xc);
      _Dst = puVar3 + 0x4e;
      memset(_Dst,0,0x30);
      *(undefined1 *)_Dst = *(undefined1 *)(param_2 + 6);
      *(undefined1 *)((longlong)puVar3 + 0x139) = *(undefined1 *)(param_2 + 5);
      *(undefined1 *)((longlong)puVar3 + 0x13b) = 0;
      *(undefined1 *)(puVar3 + 0x4f) = *(undefined1 *)(param_2 + 10);
      *(undefined1 *)((longlong)puVar3 + 0x145) = *(undefined1 *)(param_2 + 7);
      if ((uVar5 & 2) == 0) {
        uVar4 = ~-(uint)((*(ushort *)(param_1 + 0xf44) >> (*(byte *)(param_2 + 6) & 0x1f) & 1) != 0)
                & 0x500;
      }
      else {
        uVar4 = (*(byte *)(param_2 + 9) & 3) << 8;
      }
      puVar3[0x53] = uVar4;
      memcpy(puVar3 + 0x54,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
      puVar3[0x58] = *(uint *)(param_2 + 0x10);
      lVar8 = param_1;
      uVar4 = StorPortGetPhysicalAddress(param_1,param_2,_Dst,local_res8);
      puVar3[0x59] = uVar4 - 0x100;
      if ((uVar5 & 0x20) == 0) {
        *(undefined1 *)((longlong)puVar3 + 0x13d) = *(undefined1 *)(param_2 + 0xb);
      }
      else {
        *(undefined1 *)((longlong)puVar3 + 0x13d) = 0xff;
      }
      if ((uVar5 & 0xc0) == 0) {
        lVar8 = BuildZeroLenSGE(lVar8,(longlong)_Dst,uVar4);
        uVar5 = (uint)lVar8;
      }
      else {
        uVar5 = BuildScatterGather(param_1,param_2,(int)*(undefined8 *)(param_2 + 0x18),_Dst,uVar4);
      }
      uVar7 = (ulonglong)*(ushort *)(param_1 + 0x134);
      if ((*(ushort *)(param_1 + 0x134) & 0x800) != 0) {
        lVar8 = *(longlong *)(param_1 + 0x178);
        lVar10 = (longlong)
                 (int)((uint)*(ushort *)(param_1 + 0x1ea) *
                      (uint)*(byte *)((longlong)puVar3 + 0x139)) + (ulonglong)(byte)*_Dst;
        *(undefined1 *)((longlong)puVar3 + 0x139) = *(undefined1 *)(lVar8 + 0x10 + lVar10 * 0x18);
        uVar7 = 0;
        *(undefined1 *)_Dst = *(undefined1 *)(lVar8 + 0x11 + lVar10 * 0x18);
      }
      if ((bVar2 == 0x12) &&
         (uVar7 = CONCAT71((int7)(uVar7 >> 8),*(byte *)(param_2 + 0x49)),
         (*(byte *)(param_2 + 0x49) & 1) == 0)) {
        puVar3[0x50] = 0x2000000;
      }
      if (uVar5 < *(uint *)(param_1 + 500)) {
        uVar4 = uVar5 / *(ushort *)(param_1 + 0x1de) + 1 & 3 | uVar4;
        uVar7 = (ulonglong)uVar4;
        *puVar3 = uVar4;
      }
      else {
        *puVar3 = uVar4;
      }
    }
    else {
      uVar7 = BuildScsiIo32(param_1,param_2,puVar3,(ushort)bVar1);
    }
    goto LAB_1c0002f55;
  }
  if (bVar1 == 2) goto LAB_1c0002f55;
  if (bVar1 == 0x10) {
LAB_1c0003122:
    *(undefined1 *)(param_2 + 3) = 3;
  }
  else {
    if (0x11 < bVar1) {
      if (bVar1 < 0x14) goto LAB_1c0002f55;
      if (bVar1 == 0x14) goto LAB_1c0003122;
      if (bVar1 == 0x17) {
        if (*(char *)(param_1 + 0x134) < '\0') goto LAB_1c000311c;
        bVar11 = *(int *)(param_1 + 0x1c8) == 0;
      }
      else {
        bVar11 = (bVar1 - 0x20 & 0xfb) == 0;
      }
      uVar7 = (ulonglong)uVar9 << 8;
      if (bVar11) {
LAB_1c0002f55:
        return CONCAT71((int7)(uVar7 >> 8),1);
      }
    }
LAB_1c000311c:
    *(undefined1 *)(param_2 + 3) = 0x22;
  }
  uVar7 = StorPortNotification(0,param_1,param_2);
  return uVar7 & 0xffffffffffffff00;
}



===== LSImpiStartIo @ 1c0003140 =====

undefined8 LSImpiStartIo(longlong param_1,longlong param_2)

{
  ushort *puVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  longlong *plVar6;
  bool bVar7;
  char cVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  byte bVar12;
  ushort uVar13;
  ulonglong uVar14;
  uint local_res8 [2];
  
  cVar8 = *(char *)(param_2 + 2);
  puVar5 = *(undefined4 **)(param_2 + 0x38);
  cVar2 = *(char *)(param_2 + 0x48);
  uVar3 = *(undefined1 *)(param_2 + 6);
  if (cVar8 == '\0') {
    if ((*(char *)(param_1 + 0x66e) == '\0') ||
       (*(undefined1 *)(param_1 + 0x66e) = 0, cVar2 != '\x03')) {
      plVar6 = (longlong *)**(undefined8 **)(param_1 + 0x158);
      if ((plVar6[1] != 0) ||
         ((((*(int *)(param_1 + 0x1c0) != 0 || (*(short *)(param_1 + 0x1da) != 0)) ||
           (*(char *)(param_1 + 0x662) != '\0')) || (*(char *)(param_1 + 0x688) != '\0')))) {
        *(undefined1 *)(param_2 + 3) = 5;
        if (*(char *)(param_1 + 0x662) == '\0') {
          if ((plVar6[1] != 0) && (StorPortBusy(param_1,10), *(short *)(param_1 + 0x1b8) != 0)) {
            StorPortLogError(param_1,0,0,0,0,6,0xad010012);
          }
        }
        else {
          *(undefined1 *)(param_2 + 3) = 0x11;
        }
        goto LAB_1c0003392;
      }
      puVar10 = *(undefined8 **)(param_1 + 0x158) + 1;
      *(undefined8 **)(param_1 + 0x158) = puVar10;
      if (puVar10 == *(undefined8 **)(param_1 + 0x168)) {
        *(undefined8 *)(param_1 + 0x158) = *(undefined8 *)(param_1 + 0x150);
      }
      if ((*(ushort *)(param_1 + 0x134) & 0x100) != 0) {
        if ((*(uint *)(param_2 + 0xc) & 0xc0) == 0) {
          *(longlong *)(param_1 + 0xe20) = *(longlong *)(param_1 + 0xe20) + 1;
        }
        else if ((*(uint *)(param_2 + 0xc) & 0x40) == 0) {
          *(longlong *)(param_1 + 0xe18) = *(longlong *)(param_1 + 0xe18) + 1;
        }
        else {
          *(longlong *)(param_1 + 0xe10) = *(longlong *)(param_1 + 0xe10) + 1;
        }
      }
      uVar4 = *(uint *)(plVar6 + 2);
      *plVar6 = (longlong)(puVar5 + 0x4e);
      puVar5[0x50] = puVar5[0x50] | uVar4;
      plVar6[1] = param_2;
      *(undefined1 *)((longlong)plVar6 + 0x14) = *(undefined1 *)(param_2 + 5);
      *(undefined1 *)((longlong)plVar6 + 0x15) = uVar3;
      *(undefined1 *)((longlong)plVar6 + 0x16) = *(undefined1 *)(param_2 + 7);
      *(undefined1 *)((longlong)plVar6 + 0x17) = *(undefined1 *)(param_2 + 8);
      if ((*(char *)(param_1 + 0x134) < '\0') && (cVar2 == -0x60)) {
        bVar12 = *(byte *)(param_2 + 6);
        uVar14 = (ulonglong)bVar12;
        uVar13 = *(ushort *)(param_1 + 0xe78 + uVar14 * 2);
        if ((uVar13 & 0x100) != 0) {
          *(undefined1 *)(param_2 + 3) = 5;
          goto LAB_1c00031a2;
        }
        if ((((byte)uVar13 & 3) == 1) && (*(char *)(param_1 + 0xec1) == '\0')) {
          *(longlong *)(param_1 + 0xf20) = param_2;
          *(byte *)(param_1 + 0xeb0) = bVar12;
          if ((uVar13 & 4) == 0) {
            *(undefined1 *)(param_1 + 0xeae) = 1;
          }
          else {
            puVar1 = (ushort *)(param_1 + 0xe78 + uVar14 * 2);
            *puVar1 = *puVar1 & 0xfffb;
            *(undefined1 *)(param_1 + 0xeae) = 0xe;
          }
          puVar1 = (ushort *)(param_1 + 0xe78 + uVar14 * 2);
          *puVar1 = *puVar1 | 2;
          *(undefined1 *)(param_1 + 0xec1) = 1;
          puVar9 = (undefined4 *)DomainValidation(param_1);
        }
        else {
          puVar9 = (undefined4 *)((ulonglong)(uint3)(uVar4 >> 8) << 8);
        }
        if ((char)puVar9 == '\0') goto LAB_1c000332a;
      }
      else {
LAB_1c000332a:
        puVar9 = *(undefined4 **)(param_1 + 0x38);
        *puVar9 = *puVar5;
        LOCK();
        UNLOCK();
      }
    }
    else {
      memcpy(*(void **)(param_2 + 0x18),*(void **)(param_1 + 0x670),
             (ulonglong)*(uint *)(param_2 + 0x10));
      *(undefined2 *)(param_2 + 3) = 1;
LAB_1c00031a2:
      puVar9 = (undefined4 *)StorPortNotification(0,param_1,param_2);
    }
LAB_1c00031b0:
    uVar11 = CONCAT71((int7)((ulonglong)puVar9 >> 8),1);
  }
  else {
    if (cVar8 == '\x02') {
      if (*(short *)(param_1 + 0x1da) != 0) {
        *(undefined1 *)(param_2 + 3) = 5;
        goto LAB_1c0003392;
      }
      StorPortSynchronizeAccess(param_1,SynchronizeStartIoctl,param_2);
    }
    else {
      if (cVar8 != '\x12') {
        if (cVar8 != '\x13') {
          if (cVar8 == '\x17') {
            uVar11 = LSImpiWmiSrb(param_1,param_2);
            return uVar11;
          }
          if (cVar8 != ' ') {
            if ((cVar8 != '$') || (*(int *)(param_2 + 8) != 4)) {
              *(undefined1 *)(param_2 + 3) = 0x22;
              goto LAB_1c0003392;
            }
            *(longlong *)(param_1 + 0x170) = param_2;
            **(undefined4 **)(param_1 + 0x30) = 9;
            LOCK();
            UNLOCK();
            *(undefined1 *)(param_1 + 0x664) = 1;
            if ((*(uint *)(param_1 + 0x328) & 0xe0) == 0) {
              StorPortStallExecution(500);
            }
            puVar9 = (undefined4 *)(ulonglong)**(uint **)(param_1 + 0x10);
            if (**(uint **)(param_1 + 0x10) == 0) {
LAB_1c0003430:
              *(undefined1 *)(param_1 + 0x688) = 0xd;
            }
            else {
              if ((**(uint **)(param_1 + 0x20) & 0x20) != 0) {
                puVar9 = (undefined4 *)ClearResetHistoryBit(param_1);
                goto LAB_1c0003430;
              }
              puVar9 = *(undefined4 **)(param_1 + 0x10);
              *puVar9 = 0x40000000;
              LOCK();
              UNLOCK();
              *(undefined1 *)(param_1 + 0x688) = 9;
            }
            *(undefined2 *)(param_1 + 0x686) = 0;
            goto LAB_1c00031b0;
          }
        }
        if (*(char *)(param_1 + 0x688) == '\0') {
          if (((*(int *)(param_1 + 0x1c0) == 0) && (*(longlong *)(param_1 + 0x170) == 0)) &&
             (*(char *)(param_1 + 0xec1) == '\0')) {
            if (*(char *)(param_1 + 0x667) == '\0') {
              *(longlong *)(param_1 + 0x170) = param_2;
              uVar11 = StorPortSynchronizeAccess(param_1,SynchronizeLunTargetReset,param_2);
              return uVar11;
            }
          }
          else {
            if (param_2 == *(longlong *)(param_1 + 0x170)) {
              return 1;
            }
            bVar12 = 0;
            do {
              puVar9 = (undefined4 *)(ulonglong)bVar12;
              if (*(longlong *)(param_1 + 0x860 + (longlong)puVar9 * 8) == param_2)
              goto LAB_1c00031b0;
              bVar12 = bVar12 + 1;
            } while (bVar12 < 100);
            bVar12 = *(byte *)(param_1 + 0xb80);
            if (*(longlong *)(param_1 + 0x860 + (ulonglong)bVar12 * 8) == 0) {
              *(longlong *)(param_1 + 0x860 + (ulonglong)bVar12 * 8) = param_2;
              puVar9 = (undefined4 *)(ulonglong)(byte)(bVar12 + 1);
              if ((byte)(bVar12 + 1) == 100) {
                puVar9 = (undefined4 *)0x0;
              }
              *(char *)(param_1 + 0xb80) = (char)puVar9;
              goto LAB_1c00031b0;
            }
            StorPortLogError(param_1,0,0,0,0,6,0xad01003a);
          }
        }
        puVar5 = (undefined4 *)0x0;
        bVar7 = false;
        if (param_2 == *(longlong *)(param_1 + 0x170)) {
          bVar7 = true;
        }
        do {
          puVar9 = puVar5;
          if (*(longlong *)(param_1 + 0x860 + (longlong)puVar9 * 8) == param_2) {
            bVar7 = true;
            break;
          }
          uVar13 = (short)puVar9 + 1;
          puVar5 = (undefined4 *)(ulonglong)uVar13;
        } while (uVar13 < 100);
        if (!bVar7) {
          *(undefined1 *)(param_2 + 3) = 4;
          goto LAB_1c00031a2;
        }
        goto LAB_1c00031b0;
      }
      local_res8[0] = (uint)*(byte *)(param_2 + 5);
      cVar8 = StorPortSynchronizeAccess(param_1,SynchronizeReset,local_res8);
      *(byte *)(param_2 + 3) = (-(cVar8 != '\0') & 0xfdU) + 4;
LAB_1c0003392:
      StorPortNotification(0,param_1,param_2);
    }
    uVar11 = 1;
  }
  return uVar11;
}



===== BuildScatterGather @ 1c00035fc =====

int BuildScatterGather(longlong param_1,longlong param_2,int param_3,uint *param_4,uint param_5)

{
  ushort uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint *puVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int local_res20;
  uint local_68;
  int local_64;
  uint *local_60;
  uint *local_58;
  
  local_68 = 0;
  local_64 = 0;
  local_60 = (uint *)0x0;
  bVar5 = *(byte *)(param_1 + 0x134) & 1;
  uVar14 = 0x10;
  if ((char)*(undefined4 *)(param_2 + 0xc) < '\0') {
    param_4[5] = param_4[5] | 0x1000000;
    uVar14 = 0x14;
  }
  else {
    param_4[5] = param_4[5] | 0x2000000;
  }
  if (bVar5 == 0) {
    uVar17 = 2;
  }
  else {
    uVar14 = uVar14 | 2;
    uVar17 = 3;
  }
  if (*(char *)((longlong)param_4 + 3) == '\x1f') {
    uVar1 = *(ushort *)(param_1 + 0x126);
    puVar10 = param_4 + 0x1a;
    uVar2 = *(undefined1 *)(param_1 + 0x11c);
    local_res20 = 0x1a;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x124);
    puVar10 = param_4 + 0xc;
    uVar2 = *(undefined1 *)(param_1 + 0x118);
    local_res20 = 0xc;
  }
  uVar15 = (uint)uVar1;
  puVar4 = (uint *)StorPortGetScatterGatherList(param_1,param_2);
  uVar16 = param_3 - *(int *)(param_2 + 0x18);
  uVar13 = *puVar4;
  puVar9 = puVar4 + 4;
  if (uVar16 != 0) {
    uVar7 = puVar4[6];
    puVar4 = puVar9;
    if (uVar7 <= uVar16) {
      do {
        puVar9 = puVar4 + 6;
        uVar16 = uVar16 - uVar7;
        uVar13 = uVar13 - 1;
        uVar7 = puVar4[8];
        puVar4 = puVar9;
      } while (uVar7 <= uVar16);
    }
    uVar7 = *(uint *)(param_2 + 0x10);
    uVar12 = 0;
    puVar4 = puVar9;
    if (uVar13 != 0) {
      do {
        uVar3 = puVar4[2];
        if (puVar4 == puVar9) {
          uVar3 = uVar3 - uVar16;
        }
        if (uVar7 < uVar3) {
          local_64 = uVar3 - uVar7;
          uVar3 = uVar7;
        }
        uVar7 = uVar7 - uVar3;
        if (uVar7 == 0) break;
        puVar4 = puVar4 + 6;
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar13);
    }
    uVar13 = uVar12 + 1;
  }
  uVar7 = uVar15;
  if (uVar13 <= uVar15) {
    uVar7 = uVar13;
  }
  puVar4 = puVar10;
  local_58 = param_4;
  while( true ) {
    uVar8 = (ulonglong)uVar7;
    puVar11 = puVar4;
    uVar12 = 0;
    if (uVar7 != 0) {
      local_res20 = local_res20 + uVar7 * uVar17;
      do {
        *puVar4 = puVar9[2] | uVar14 << 0x18;
        puVar4[1] = *puVar9;
        if (bVar5 != 0) {
          puVar4[2] = puVar9[1];
        }
        puVar4 = puVar4 + uVar17;
        puVar9 = puVar9 + 6;
        uVar8 = uVar8 - 1;
        puVar11 = puVar4;
        uVar12 = uVar7;
      } while (uVar8 != 0);
    }
    local_68 = local_68 + uVar12;
    if (uVar13 <= local_68) break;
    puVar11[-(ulonglong)uVar17] = puVar11[-(ulonglong)uVar17] | 0x80000000;
    if (local_68 == uVar15) {
      *(undefined1 *)((longlong)param_4 + 2) = uVar2;
      uVar15 = (uint)*(ushort *)(param_1 + 0x128);
    }
    if (local_60 != (uint *)0x0) {
      cVar6 = (char)uVar17 * (char)uVar12;
      *(char *)((longlong)local_60 + 2) = cVar6;
      *(ushort *)local_60 = (byte)(cVar6 * '\x04') + 8;
    }
    param_5 = param_5 + *(ushort *)(param_1 + 300);
    puVar4 = (uint *)((longlong)local_58 + (ulonglong)*(ushort *)(param_1 + 300));
    *puVar11 = 0x30000000;
    puVar11[1] = param_5;
    uVar7 = uVar15;
    local_60 = puVar11;
    local_58 = puVar4;
    if (uVar13 - local_68 <= uVar15) {
      uVar7 = uVar13 - local_68;
    }
  }
  puVar11 = puVar11 + -(ulonglong)uVar17;
  *puVar11 = *puVar11 | 0xc1000000;
  if (local_64 != 0) {
    *puVar11 = *puVar11 - local_64;
  }
  if (local_60 != (uint *)0x0) {
    *(undefined1 *)((longlong)local_60 + 2) = 0;
    *(ushort *)local_60 = (ushort)(byte)((char)uVar17 * (char)uVar12 * '\x04');
  }
  if (uVar16 != 0) {
    *puVar10 = *puVar10 - uVar16;
    puVar10[1] = puVar10[1] + uVar16;
  }
  if ((*(int *)(param_1 + 0x1a8) == 0x62) && (bVar5 != 0)) {
    puVar10 = param_4 + 0xc;
    while( true ) {
      while (uVar14 = *puVar10, ((byte)(uVar14 >> 0x18) & 0x30) != 0x10) {
        puVar10 = (uint *)((longlong)param_4 + (ulonglong)*(ushort *)(param_1 + 300));
        param_4 = puVar10;
      }
      uVar13 = puVar10[2];
      uVar16 = uVar13;
      if ((uVar14 & 0xffffff) + puVar10[1] < puVar10[1]) {
        uVar16 = uVar13 + 1;
      }
      if (uVar16 == 9) {
        *puVar10 = uVar14 | 0x8000000;
        puVar10[2] = uVar13 | 0x80000000;
      }
      if ((uVar14 & 0x1000000) != 0) break;
      puVar10 = puVar10 + uVar17;
    }
  }
  return local_res20;
}



===== BuildZeroLenSGE @ 1c0003944 =====

longlong BuildZeroLenSGE(undefined8 param_1,longlong param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (*(char *)(param_2 + 3) == '\x1f') {
    puVar2 = (undefined4 *)(param_2 + 0x68);
    uVar1 = 0x74;
  }
  else {
    puVar2 = (undefined4 *)(param_2 + 0x30);
    uVar1 = 0x3c;
  }
  *puVar2 = 0xd1000000;
  puVar2[1] = uVar1 + param_3;
  return ((ulonglong)uVar1 - 0xc >> 2) + 2;
}



===== SynchronizeOtherChannelRestart @ 1c0003980 =====

undefined8 SynchronizeOtherChannelRestart(longlong param_1)

{
  undefined8 uVar1;
  
  CompleteAllSrbs(param_1);
  LsiMpiPartitionMemory(param_1);
  TestFWUploadNeeded(param_1);
  uVar1 = SendIOCInitMessage(param_1);
  if ((char)uVar1 != '\0') {
    SendPortEnables(param_1);
  }
  uVar1 = LSImpiHWInitialize(param_1);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== BuildScsiIo32 @ 1c00039c4 =====

void BuildScsiIo32(longlong param_1,longlong param_2,uint *param_3,ushort param_4)

{
  uint *_Dst;
  byte bVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 local_res20 [8];
  
  uVar2 = *(uint *)(param_2 + 0xc);
  _Dst = param_3 + 0x4e;
  bVar1 = *(byte *)(param_2 + 6);
  memset(_Dst,0,0x68);
  *(byte *)(param_3 + 0x62) = bVar1;
  lVar5 = 2;
  *(undefined1 *)((longlong)param_3 + 0x189) = *(undefined1 *)(param_2 + 5);
  *(undefined1 *)((longlong)param_3 + 0x13b) = 0x1f;
  *(undefined1 *)(param_3 + 0x4f) = *(undefined1 *)(param_2 + 10);
  *(undefined1 *)((longlong)param_3 + 0x145) = *(undefined1 *)(param_2 + 7);
  param_3[0x5c] = *(uint *)(param_2 + 0x10);
  if ((uVar2 & 2) == 0) {
    uVar3 = ~-(uint)((*(ushort *)(param_1 + 0xf44) >> (bVar1 & 0x1f) & 1) != 0) & 0x500;
  }
  else {
    uVar3 = (*(byte *)(param_2 + 9) & 3) << 8;
  }
  param_3[0x53] = uVar3;
  memcpy(param_3 + 0x54,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  param_3[0x61] = 0x208;
  *(ushort *)(param_3 + 0x60) = param_4;
  if (*(char *)(param_1 + 0x66d) == '\0') {
    *(ushort *)(param_3 + 0x60) = param_4 | 0x8700;
    *(byte *)((longlong)param_3 + 0x151) = *(byte *)(param_2 + 0x49) & 0x1f | 0x20;
  }
  if ((char)param_3[0x4f] == '\x10') {
    lVar5 = 6;
  }
  memcpy(param_3 + 0x59,(void *)((longlong)param_3 + lVar5 + 0x150),4);
  *(undefined2 *)((longlong)param_3 + 0x16a) = 0xffff;
  lVar5 = param_1;
  uVar3 = StorPortGetPhysicalAddress(param_1,param_2,_Dst,local_res20);
  param_3[0x67] = uVar3 - 0x100;
  if ((uVar2 & 0x20) == 0) {
    *(undefined1 *)((longlong)param_3 + 0x13d) = *(undefined1 *)(param_2 + 0xb);
  }
  else {
    *(undefined1 *)((longlong)param_3 + 0x13d) = 0xff;
  }
  if ((uVar2 & 0xc0) == 0) {
    BuildZeroLenSGE(lVar5,(longlong)_Dst,uVar3);
  }
  else {
    BuildScatterGather(param_1,param_2,(int)*(undefined8 *)(param_2 + 0x18),_Dst,uVar3);
  }
  if ((*(ushort *)(param_1 + 0x134) & 0x800) != 0) {
    lVar5 = *(longlong *)(param_1 + 0x178);
    lVar4 = (longlong)(int)((uint)*(ushort *)(param_1 + 0x1ea) * (uint)*(byte *)(param_2 + 5)) +
            (ulonglong)bVar1;
    *(undefined1 *)((longlong)param_3 + 0x189) = *(undefined1 *)(lVar5 + 0x10 + lVar4 * 0x18);
    *(undefined1 *)(param_3 + 0x62) = *(undefined1 *)(lVar5 + 0x11 + lVar4 * 0x18);
  }
  *param_3 = uVar3;
  return;
}



===== SynchronizeLunTargetReset @ 1c0003b80 =====

undefined8 SynchronizeLunTargetReset(longlong param_1,longlong param_2)

{
  undefined1 *_Dst;
  bool bVar1;
  undefined4 *in_RAX;
  undefined7 extraout_var;
  
  if ((*(longlong *)(param_2 + 0x38) != 0) && (param_2 == *(longlong *)(param_1 + 0x170))) {
    if (*(char *)(param_1 + 0x688) == '\0') {
      _Dst = (undefined1 *)(param_1 + 0x240);
      memset(_Dst,0,0x34);
      *_Dst = *(undefined1 *)(param_2 + 6);
      *(undefined1 *)(param_1 + 0x241) = *(undefined1 *)(param_2 + 5);
      *(undefined1 *)(param_1 + 0x243) = 1;
      *(undefined1 *)(param_1 + 0x245) = 3;
      if (*(char *)(param_2 + 2) == ' ') {
        *(undefined1 *)(param_1 + 0x245) = 5;
        *(undefined1 *)(param_1 + 0x24d) = *(undefined1 *)(param_2 + 7);
      }
      if (*(int *)(param_1 + 0x1c8) == 0) {
        StorPortPause(param_1,300);
      }
      *(undefined4 *)(param_1 + 0x1c0) = 10;
      *(longlong *)(param_1 + 0x170) = param_2;
      if (*(char *)(param_1 + 0x678) == '\0') {
        if (*(int *)(param_1 + 0x1c8) == 0) {
          in_RAX = *(undefined4 **)(param_1 + 0x30);
          *in_RAX = 9;
          LOCK();
          UNLOCK();
          *(undefined4 *)(param_1 + 0x68c) = 0xd;
          *(undefined4 *)(param_1 + 0x690) = 10;
          *(undefined1 **)(param_1 + 0x698) = _Dst;
          *(undefined1 *)(param_1 + 0x688) = 0xe;
        }
        else {
          bVar1 = SendMessageViaHandShake(param_1,1,0xd);
          in_RAX = (undefined4 *)CONCAT71(extraout_var,bVar1);
          if (!bVar1) {
            if (*(longlong *)(param_2 + 0x38) != 0) {
              *(undefined1 *)(param_2 + 3) = 4;
              StorPortNotification(0,param_1,param_2);
            }
            *(undefined8 *)(param_1 + 0x170) = 0;
            *(undefined4 *)(param_1 + 0x1c0) = 0;
            in_RAX = (undefined4 *)StorPortResume(param_1);
          }
        }
      }
      else {
        memcpy(*(void **)(param_1 + 0xd68),_Dst,0x34);
        in_RAX = *(undefined4 **)(param_1 + 0x48);
        *in_RAX = *(undefined4 *)(param_1 + 0xd80);
        LOCK();
        UNLOCK();
      }
    }
    else {
      *(undefined1 *)(param_2 + 3) = 4;
      in_RAX = (undefined4 *)StorPortNotification(0,param_1,param_2);
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== SynchronizeStartIoctl @ 1c0003cf0 =====

ulonglong SynchronizeStartIoctl(longlong param_1,void *param_2)

{
  byte bVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  if (*(char *)(param_1 + 0x664) == '\0') {
    if ((((*(char *)(param_1 + 0x6a1) == '\0') && (*(int *)(param_1 + 0x1c0) == 0)) &&
        (*(char *)(param_1 + 0x688) == '\0')) && (*(char *)(param_1 + 0x135c) == '\0')) {
      uVar2 = LsiHandleAppRequest(param_1,param_2);
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
    bVar1 = *(byte *)(param_1 + 0x858);
    if ((*(char *)(param_1 + 0x688) == '\0') &&
       (*(longlong *)(param_1 + 0x758 + (ulonglong)bVar1 * 8) == 0)) {
      *(void **)(param_1 + 0x758 + (ulonglong)bVar1 * 8) = param_2;
      uVar3 = (ulonglong)(byte)(bVar1 + 1);
      if ((byte)(bVar1 + 1) == 0x20) {
        uVar3 = 0;
      }
      *(char *)(param_1 + 0x858) = (char)uVar3;
      goto LAB_1c0003d7c;
    }
  }
  *(undefined1 *)((longlong)param_2 + 3) = 5;
  uVar3 = StorPortNotification(0,param_1,param_2);
LAB_1c0003d7c:
  return uVar3 & 0xffffffffffffff00;
}



===== SendIOCInitMessage @ 1c0003d84 =====

undefined8 SendIOCInitMessage(longlong param_1)

{
  bool bVar1;
  bool bVar2;
  longlong lVar3;
  undefined7 extraout_var;
  ulonglong uVar4;
  
  bVar1 = false;
  memset((undefined1 *)(param_1 + 0x200),0,0x2c);
  *(undefined8 *)(param_1 + 0x280) = 0;
  *(undefined8 *)(param_1 + 0x288) = 0;
  *(undefined4 *)(param_1 + 0x290) = 0;
  *(undefined1 *)(param_1 + 0x203) = 2;
  *(undefined1 *)(param_1 + 0x200) = 4;
  *(undefined1 *)(param_1 + 0x205) = *(undefined1 *)(param_1 + 0x1e6);
  *(undefined1 *)(param_1 + 0x206) = *(undefined1 *)(param_1 + 0x1e4);
  *(undefined2 *)(param_1 + 0x20c) = *(undefined2 *)(param_1 + 0x12a);
  if ((*(byte *)(param_1 + 0x134) & 0x40) != 0) {
    *(undefined1 *)(param_1 + 0x204) = 1;
    *(ushort *)(param_1 + 0x134) = *(ushort *)(param_1 + 0x134) & 0xffbf;
  }
  if (*(int *)(param_1 + 0x1a0) != 0) {
    *(int *)(param_1 + 0x21c) = *(int *)(param_1 + 0x1a0);
    *(undefined4 *)(param_1 + 0x220) = *(undefined4 *)(param_1 + 0x1a4);
  }
  lVar3 = 0x105;
  if (0x104 < *(ushort *)(param_1 + 0x1f2)) {
    *(undefined4 *)(param_1 + 0x228) = 0x14000105;
  }
  if (*(char *)(param_1 + 0x688) == '\0') {
    bVar2 = SendMessageViaHandShake(param_1,0,0xb);
    lVar3 = CONCAT71(extraout_var,bVar2);
    if ((!bVar2) || (lVar3 = ReceiveDataViaHandshake(param_1,10), (char)lVar3 == '\0')) {
      bVar1 = true;
    }
    *(undefined1 *)(param_1 + 0x682) = 0;
    if (bVar1) {
      uVar4 = StorPortLogError(param_1,0,0,0,0,6,0xad010010);
      return uVar4 & 0xffffffffffffff00;
    }
  }
  return CONCAT71((int7)((ulonglong)lVar3 >> 8),1);
}



===== SendPortEnables @ 1c0003ea4 =====

bool SendPortEnables(longlong param_1)

{
  bool bVar1;
  longlong lVar2;
  ushort uVar3;
  bool bVar4;
  
  bVar4 = *(short *)(param_1 + 0x1dc) != 0;
  bVar1 = false;
  uVar3 = 0;
  do {
    if (!bVar4) {
LAB_1c0003f2d:
      if ((**(uint **)(param_1 + 0x20) & 0x20) != 0) {
        ClearResetHistoryBit(param_1);
      }
      return !bVar1;
    }
    *(undefined8 *)(param_1 + 0x200) = 0;
    *(undefined4 *)(param_1 + 0x208) = 0;
    *(undefined8 *)(param_1 + 0x280) = 0;
    *(undefined8 *)(param_1 + 0x288) = 0;
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined1 *)(param_1 + 0x203) = 6;
    *(char *)(param_1 + 0x206) = (char)uVar3;
    bVar4 = SendMessageViaHandShake(param_1,0,3);
    if (!bVar4) {
LAB_1c0003f2a:
      bVar1 = true;
      goto LAB_1c0003f2d;
    }
    lVar2 = ReceiveDataViaHandshake(param_1,10);
    if ((char)lVar2 == '\0') goto LAB_1c0003f2a;
    uVar3 = uVar3 + 1;
    bVar4 = uVar3 < *(ushort *)(param_1 + 0x1dc);
  } while( true );
}



===== ClearResetHistoryBit @ 1c0003f5c =====

void ClearResetHistoryBit(longlong param_1)

{
  EnableDiagnosticRegister(param_1);
  **(undefined4 **)(param_1 + 0x20) = 0;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x18) = 0xf;
  LOCK();
  UNLOCK();
  return;
}



===== IssueIOCFacts @ 1c0003f8c =====

ulonglong IssueIOCFacts(longlong param_1)

{
  ushort *_Dst;
  int iVar1;
  bool bVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  iVar1 = *(int *)(param_1 + 0x1c8);
  _Dst = (ushort *)(param_1 + 0x280);
  *(undefined8 *)(param_1 + 0x200) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0;
  memset(_Dst,0,0x50);
  *(undefined1 *)(param_1 + 0x203) = 3;
  bVar2 = SendMessageViaHandShake(param_1,0,3);
  if ((bVar2) && (lVar4 = ReceiveDataViaHandshake(param_1,0x28), (char)lVar4 != '\0')) {
    *(ushort *)(param_1 + 0x1f2) = *_Dst;
    *(short *)(param_1 + 300) = *(short *)(param_1 + 0x29a) << 2;
    *(uint *)(param_1 + 500) = (uint)*(ushort *)(param_1 + 0x29a);
    *(undefined2 *)(param_1 + 0x130) = *(undefined2 *)(param_1 + 0x298);
    *(ushort *)(param_1 + 0x132) = (ushort)*(byte *)(param_1 + 0x294);
    *(undefined2 *)(param_1 + 0x1d8) = *(undefined2 *)(param_1 + 0x2a4);
    *(ushort *)(param_1 + 0x1dc) = (ushort)*(byte *)(param_1 + 0x2a6);
    *(ushort *)(param_1 + 0x1de) = (ushort)*(byte *)(param_1 + 0x296);
    *(undefined1 *)(param_1 + 0xe2a) = *(undefined1 *)(param_1 + 0x286);
    *(undefined4 *)(param_1 + 0x67c) = *(undefined4 *)(param_1 + 0x2b4);
    if ((*(uint *)(param_1 + 0x2b4) & 1) != 0) {
      *(undefined1 *)(param_1 + 0x678) = 1;
    }
    if ((*(uint *)(param_1 + 0x2b4) & 4) != 0) {
      *(undefined1 *)(param_1 + 0x679) = 1;
    }
    if ((*(uint *)(param_1 + 0x2b4) & 0x800) != 0) {
      *(ushort *)(param_1 + 0x134) = *(ushort *)(param_1 + 0x134) | 0x4000;
    }
    if ((*(byte *)(param_1 + 0x28c) & 8) != 0) {
      *(undefined1 *)(param_1 + 0x680) = 1;
    }
    if (*_Dst < 0x102) {
      uVar3 = (uint)*(ushort *)(param_1 + 0x29c);
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x2b8);
    }
    *(uint *)(param_1 + 0x2fc) = uVar3;
    if (((*(byte *)(param_1 + 0x134) & 0x80) != 0) && ((int)uVar3 < 0x1032300)) {
      *(undefined1 *)(param_1 + 0x667) = 1;
      StorPortLogError(param_1,0,0,0,0,9,uVar3);
    }
    if ((*(byte *)(param_1 + 0x297) & 1) != 0) {
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x1fc) = *(undefined4 *)(param_1 + 0x2b0);
      }
      else {
        *(undefined1 *)(param_1 + 0x65c) = 1;
      }
    }
    if (0x101 < *_Dst) {
      if (((*(ushort *)(param_1 + 0x29e) & 0xf000) == 0) && (iVar1 != 0)) {
        *(ushort *)(param_1 + 0x134) = *(ushort *)(param_1 + 0x134) & 0xfeff | 0x80;
      }
      if ((0x101 < *_Dst) && (iVar1 == 0)) {
        if ((*(uint *)(param_1 + 0x2b4) & 8) != 0) {
          *(undefined1 *)(param_1 + 0xce5) = 1;
        }
        if ((*(uint *)(param_1 + 0x2b4) & 0x10) != 0) {
          *(undefined1 *)(param_1 + 0xd15) = 1;
        }
        if ((*(uint *)(param_1 + 0x2b4) & 0x20) != 0) {
          *(undefined1 *)(param_1 + 0xd45) = 1;
        }
      }
    }
    if ((((0x104 < *_Dst) && (*(uint *)(param_1 + 0x2c0) != 0)) &&
        (*(char *)(param_1 + 0x66a) == '\0')) && (*(char *)(param_1 + 0x66b) == '\0')) {
      uVar3 = *(uint *)(param_1 + 0x2c0) & 0xffffff;
      if (0x20000 < uVar3) {
        uVar3 = 0x20000;
      }
      *(uint *)(param_1 + 0x1a0) = uVar3;
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0x1a4) = *(undefined4 *)(param_1 + 0x2c4);
      }
    }
    *(undefined4 *)(param_1 + 0x1b0) = 60000;
    if ((0x300 < (*(ushort *)(param_1 + 0x29e) & 0xf00)) ||
       ((*(ushort *)(param_1 + 0x134) & 0x200) != 0)) {
      *(undefined4 *)(param_1 + 0x1b0) = 600000;
    }
    return 0xf01;
  }
  uVar5 = StorPortLogError(param_1,0,0,0,0,6,0xad01000d);
  return uVar5 & 0xffffffffffffff00;
}



===== SymWaitForResponse @ 1c0004244 =====

ulonglong SymWaitForResponse(longlong param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    piVar1 = *(int **)(param_1 + 0x28);
    if (*piVar1 == -1) break;
    if (-1 < *piVar1) {
      return CONCAT71((int7)((ulonglong)piVar1 >> 8),1);
    }
    piVar1 = (int *)(ulonglong)**(uint **)(param_1 + 0x20);
    if ((**(uint **)(param_1 + 0x20) & 0x20) != 0) break;
    piVar1 = (int *)StorPortStallExecution(500);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 60000);
  return (ulonglong)piVar1 & 0xffffffffffffff00;
}



===== SymWaitForDoorBell @ 1c0004294 =====

ulonglong SymWaitForDoorBell(longlong param_1,uint param_2)

{
  uint *in_RAX;
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      in_RAX = *(uint **)(param_1 + 0x28);
      if (*in_RAX == 0xffffffff) break;
      if ((*in_RAX & 1) != 0) {
        return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
      }
      in_RAX = (uint *)(ulonglong)**(uint **)(param_1 + 0x20);
      if ((**(uint **)(param_1 + 0x20) & 0x20) != 0) break;
      in_RAX = (uint *)StorPortStallExecution(500);
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== SendMessageViaHandShake @ 1c00042f0 =====

bool SendMessageViaHandShake(longlong param_1,int param_2,uint param_3)

{
  ulonglong uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 *puVar4;
  bool bVar5;
  bool bVar6;
  
  uVar2 = 60000;
  if (param_2 == 0) {
    puVar4 = (undefined4 *)(param_1 + 0x200);
    if (*(char *)(param_1 + 0x203) != '\x04') goto LAB_1c0004348;
  }
  else {
    puVar4 = (undefined4 *)(param_1 + 0x240);
  }
  uVar2 = 10000;
LAB_1c0004348:
  **(undefined4 **)(param_1 + 0x28) = 0;
  LOCK();
  UNLOCK();
  **(int **)(param_1 + 0x10) = (param_3 | 0x4200) << 0x10;
  LOCK();
  UNLOCK();
  uVar1 = SymWaitForDoorBell(param_1,uVar2);
  bVar5 = (char)uVar1 == '\0';
  bVar6 = (**(uint **)(param_1 + 0x10) & 0x8000000) == 0;
  bVar3 = bVar6 || bVar5;
  **(undefined4 **)(param_1 + 0x28) = 0;
  LOCK();
  UNLOCK();
  if ((bVar6 || bVar5) || (uVar1 = SymWaitForResponse(param_1), (char)uVar1 == '\0')) {
    bVar3 = true;
  }
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      if (bVar3) {
        return !bVar3;
      }
      **(undefined4 **)(param_1 + 0x10) = *puVar4;
      LOCK();
      UNLOCK();
      uVar1 = SymWaitForResponse(param_1);
      if ((char)uVar1 == '\0') {
        bVar3 = true;
      }
      uVar2 = uVar2 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar2 < param_3);
  }
  return !bVar3;
}



===== ReceiveDataViaHandshake @ 1c0004404 =====

longlong ReceiveDataViaHandshake(longlong param_1,uint param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  ulonglong uVar3;
  uint7 uVar5;
  longlong lVar4;
  uint uVar6;
  uint uVar7;
  undefined2 *puVar8;
  
  bVar2 = false;
  puVar8 = (undefined2 *)(param_1 + 0x280);
  uVar6 = 60000;
  if (*(char *)(param_1 + 0x203) == '\x06') {
    uVar6 = *(uint *)(param_1 + 0x1b0);
  }
  uVar7 = 0;
  do {
    if (bVar2) break;
    uVar3 = SymWaitForDoorBell(param_1,uVar6);
    if ((char)uVar3 == '\0') {
      bVar2 = true;
    }
    *puVar8 = (short)**(undefined4 **)(param_1 + 0x10);
    **(undefined4 **)(param_1 + 0x28) = 0;
    LOCK();
    UNLOCK();
    uVar7 = uVar7 + 1;
    puVar8 = puVar8 + 1;
  } while (uVar7 < 2);
  uVar7 = 2;
  uVar6 = (uint)(byte)*(undefined2 *)(param_1 + 0x282) * 2;
  if (2 < uVar6) {
    puVar8 = (undefined2 *)(param_1 + 0x284);
    do {
      if (bVar2) break;
      uVar3 = SymWaitForDoorBell(param_1,60000);
      if ((char)uVar3 == '\0') {
        bVar2 = true;
      }
      if (uVar7 < param_2) {
        *puVar8 = (short)**(undefined4 **)(param_1 + 0x10);
      }
      **(undefined4 **)(param_1 + 0x28) = 0;
      LOCK();
      UNLOCK();
      uVar7 = uVar7 + 1;
      puVar8 = puVar8 + 1;
    } while (uVar7 < uVar6);
  }
  uVar3 = SymWaitForDoorBell(param_1,60000);
  puVar1 = *(undefined4 **)(param_1 + 0x28);
  if ((char)uVar3 == '\0') {
    bVar2 = true;
  }
  *puVar1 = 0;
  LOCK();
  UNLOCK();
  uVar5 = (uint7)((ulonglong)puVar1 >> 8);
  if (((uVar7 >> 1 != (uint)*(byte *)(param_1 + 0x282)) ||
      ((*(ushort *)(param_1 + 0x28e) & 0x7fff) != 0)) || (bVar2)) {
    lVar4 = (ulonglong)uVar5 << 8;
  }
  else {
    lVar4 = CONCAT71(uVar5,1);
  }
  return lVar4;
}



===== KickStart @ 1c0004560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong KickStart(longlong param_1)

{
  int iVar1;
  uint *puVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 *puVar6;
  byte bVar7;
  uint uVar8;
  undefined4 *puVar9;
  short sVar10;
  undefined1 local_88 [32];
  undefined1 local_68;
  undefined4 local_60;
  int local_58;
  undefined4 local_48 [4];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_88;
  iVar1 = *(int *)(param_1 + 0x1a8);
  puVar2 = *(uint **)(param_1 + 0x10);
  uVar8 = *puVar2;
  if (uVar8 == 0xffffffff) goto LAB_1c00045a0;
  if ((uVar8 & 0xf0000000) == 0x40000000) {
    local_58 = (uVar8 & 0xffff) + 0xad0f0000;
    local_60 = 6;
    local_68 = 0;
    StorPortLogError(param_1,0,0,0);
    if (*(char *)(param_1 + 0x65e) != '\0') {
      *(undefined4 *)(param_1 + 0x1a8) = _DAT_0000face;
    }
    if (((((*(short *)(param_1 + 0x1be) != 0) && (*(char *)(param_1 + 0x65f) == '\0')) &&
         ((*(ushort *)(param_1 + 0x134) & 0x100) != 0)) &&
        (((uVar8 = uVar8 & 0xff00, uVar8 == 0x1100 || (uVar8 == 0x3200)) ||
         ((uVar8 == 0x3300 || (uVar8 == 0x8100)))))) &&
       (sVar3 = *(short *)(param_1 + 0x1be) + -1, *(short *)(param_1 + 0x1be) = sVar3, sVar3 == 0))
    {
      local_58 = -0x52feffd2;
      local_60 = 6;
      local_68 = 0;
      StorPortLogError(param_1,0,0,0);
      *(undefined2 *)(param_1 + 0x1b4) = 1;
    }
    if ((*(short *)(param_1 + 0x1f0) == 0) && (bVar7 = 0, *(short *)(param_1 + 0x1e4) != 0)) {
      do {
        StorPortNotification(7,param_1,bVar7);
        bVar7 = bVar7 + 1;
      } while ((ushort)bVar7 < *(ushort *)(param_1 + 0x1e4));
    }
  }
  if ((*(short *)(param_1 + 0x1b4) == 0) || (*(char *)(param_1 + 0x65f) != '\0')) {
    if (*(char *)(param_1 + 0x65e) != '\0') {
      *(undefined4 *)(param_1 + 0x1a8) = _DAT_0000dead;
    }
    if (*(undefined4 **)(param_1 + 400) != (undefined4 *)0x0) {
      puVar6 = *(undefined4 **)(param_1 + 400);
      puVar9 = local_48;
      for (lVar4 = 4; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar9 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar9 = puVar9 + 1;
      }
    }
    *(undefined1 *)(param_1 + 0x682) = 1;
    *(undefined4 *)(param_1 + 0x1c4) = 0x1e;
    lVar4 = 3;
    if (iVar1 == 0x62) {
      *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x10fc) = 7;
      LOCK();
      UNLOCK();
      StorPortStallExecution(100);
    }
    else {
      EnableDiagnosticRegister(param_1);
      if ((**(uint **)(param_1 + 0x20) & 0x20) == 0) {
        if ((*(int *)(param_1 + 0x1fc) == 0) || (-1 < *(char *)(param_1 + 0x134))) {
          **(undefined4 **)(param_1 + 0x20) = 2;
          LOCK();
          UNLOCK();
          StorPortStallExecution(200);
          **(undefined4 **)(param_1 + 0x20) = 4;
        }
        else {
          **(undefined4 **)(param_1 + 0x20) = 0x202;
          LOCK();
          UNLOCK();
          StorPortStallExecution(999);
          **(uint **)(param_1 + 0x20) = **(uint **)(param_1 + 0x20) | 4;
          LOCK();
          UNLOCK();
          StorPortStallExecution(999);
          uVar8 = 0;
          do {
            if ((**(uint **)(param_1 + 0x20) & 4) == 0) break;
            StorPortStallExecution(999);
            uVar8 = uVar8 + 1;
          } while (uVar8 < 3000);
          if (uVar8 == 3000) {
            local_58 = 0xad010023;
            goto LAB_1c00046e0;
          }
          EnableDiagnosticRegister(param_1);
          **(uint **)(param_1 + 0x20) = **(uint **)(param_1 + 0x20) | 0x12;
          LOCK();
          UNLOCK();
          lVar5 = *(longlong *)(param_1 + 0x198);
          sVar3 = (short)*(undefined8 *)(param_1 + 0x50);
          sVar10 = sVar3 + 0x10;
          sVar3 = sVar3 + 0x14;
          out(sVar3,*(undefined4 *)(lVar5 + 0x34));
          puVar6 = *(undefined4 **)(param_1 + 0x198);
          for (uVar8 = *(int *)(param_1 + 0x1fc) + 3U >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            out(sVar10,*puVar6);
            puVar6 = puVar6 + 1;
          }
          uVar8 = *(uint *)(lVar5 + 0x30);
          while (uVar8 != 0) {
            puVar9 = (undefined4 *)((ulonglong)uVar8 + lVar5);
            out(sVar3,puVar9[4]);
            puVar6 = puVar9;
            for (uVar8 = puVar9[2] + 3 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              out(sVar10,*puVar6);
              puVar6 = puVar6 + 1;
            }
            uVar8 = puVar9[3];
          }
          out(sVar3,*(undefined4 *)(lVar5 + 0x3c));
          in(sVar3);
          out(sVar10,*(undefined4 *)(lVar5 + 0x38));
          out(sVar3,0x3f000000);
          in(sVar3);
          uVar8 = in(sVar10);
          out(sVar3,0x3f000000);
          in(sVar3);
          out(sVar10,uVar8 | 0x40000000);
          in(sVar3);
          **(uint **)(param_1 + 0x20) = **(uint **)(param_1 + 0x20) & 0xfffffdfd;
          LOCK();
          UNLOCK();
          **(uint **)(param_1 + 0x20) = **(uint **)(param_1 + 0x20) & 0xffffffcf;
        }
        LOCK();
        UNLOCK();
        StorPortStallExecution(100);
        if ((**(uint **)(param_1 + 0x20) & 0x42) != 0) {
          local_58 = -0x52fefffb;
          local_60 = 6;
          local_68 = 0;
          StorPortLogError(param_1,0,0,0);
        }
        **(undefined4 **)(param_1 + 0x20) = 0;
      }
      else {
        **(uint **)(param_1 + 0x20) = **(uint **)(param_1 + 0x20) & 0xffffffdf;
      }
      LOCK();
      UNLOCK();
      **(undefined4 **)(param_1 + 0x18) = 0xf;
      LOCK();
      UNLOCK();
    }
    if (*(undefined4 **)(param_1 + 400) != (undefined4 *)0x0) {
      puVar6 = local_48;
      puVar9 = *(undefined4 **)(param_1 + 400);
      for (lVar5 = 4; lVar5 != 0; lVar5 = lVar5 + -1) {
        *puVar9 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar9 = puVar9 + 1;
      }
      LOCK();
      UNLOCK();
    }
    puVar2 = (uint *)(param_1 + 0xce7);
    do {
      if (((*(char *)((longlong)puVar2 + -2) != '\0') && (*(char *)((longlong)puVar2 + -1) != '\0'))
         && ((char)*puVar2 != '\0')) {
        *(char *)puVar2 = '\0';
        *(char *)((longlong)puVar2 + -0x19) = '\x01';
      }
      puVar2 = puVar2 + 0xc;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    if ((*(char *)(param_1 + 0x664) != '\0') || (*(char *)(param_1 + 0x688) != '\0')) {
LAB_1c0004a45:
      return CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
    }
    uVar8 = 0;
    do {
      puVar2 = *(uint **)(param_1 + 0x10);
      if (*puVar2 == 0xffffffff) goto LAB_1c00045a0;
      if ((*puVar2 & 0xf0000000) == 0x10000000) break;
      puVar2 = (uint *)StorPortStallExecution(1000);
      uVar8 = uVar8 + 1;
    } while (uVar8 < 20000);
    if (uVar8 < 20000) goto LAB_1c0004a45;
    local_58 = 0xad01000b;
  }
  else {
    local_58 = 0xad01000c;
  }
LAB_1c00046e0:
  local_60 = 6;
  local_68 = 0;
  puVar2 = (uint *)StorPortLogError(param_1,0,0,0);
LAB_1c00045a0:
  return (ulonglong)puVar2 & 0xffffffffffffff00;
}



===== EnableDiagnosticRegister @ 1c0004a74 =====

void EnableDiagnosticRegister(longlong param_1)

{
  bool bVar1;
  char cVar2;
  
  bVar1 = true;
  **(undefined4 **)(param_1 + 0x18) = 0xf;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x18) = 4;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x18) = 0xb;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x18) = 2;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x18) = 7;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x18) = 0xd;
  LOCK();
  UNLOCK();
  StorPortStallExecution(900);
  cVar2 = (char)**(undefined4 **)(param_1 + 0x20);
  while ((-1 < cVar2 && (StorPortLogError(param_1,0,0,0,0,6,0xad010029), bVar1))) {
    bVar1 = false;
    **(undefined4 **)(param_1 + 0x18) = 0xf;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x18) = 4;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x18) = 0xb;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x18) = 2;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x18) = 7;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x18) = 0xd;
    LOCK();
    UNLOCK();
    StorPortStallExecution(900);
    cVar2 = (char)**(undefined4 **)(param_1 + 0x20);
  }
  return;
}



===== SynchronizeReset @ 1c0004bb0 =====

void SynchronizeReset(longlong param_1,uint *param_2)

{
  LSImpiReset(param_1,*param_2);
  return;
}



===== LSImpiReset @ 1c0004bb8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 LSImpiReset(longlong param_1,uint param_2)

{
  void *_Dst;
  int iVar1;
  undefined8 *puVar2;
  bool bVar3;
  uint uVar4;
  
  if (*(short *)(param_1 + 0x1b8) != 0) {
    register0x00000020 = (BADSPACEBASE *)StorPortLogError(param_1,0,0,0,0,6,0xad010016);
  }
  if (*(char *)(param_1 + 0x65d) != '\0') {
    register0x00000020 = (BADSPACEBASE *)(ulonglong)_DAT_00000000;
    *(uint *)(param_1 + 0xdf0) = _DAT_00000000;
  }
  if (((*(short *)(param_1 + 0x1da) != 0) || (*(char *)(param_1 + 0x688) != '\0')) ||
     (register0x00000020 = *(BADSPACEBASE **)(param_1 + 0x10),
     (*(uint *)register0x00000020 & 0xf0000000) != 0x20000000)) goto LAB_1c0004ee5;
  if (*(longlong *)(param_1 + 0x170) == 0) {
    if (*(char *)(param_1 + 0x669) != '\0') goto LAB_1c0004caa;
LAB_1c0004d13:
    if (*(int *)(param_1 + 0x1c0) != 0) {
      if ((*(char *)(param_1 + 0x666) != '\0') || ((char)param_2 != *(char *)(param_1 + 0x661))) {
        uVar4 = (uint)*(ushort *)(param_1 + 0x1bc) | 1 << (param_2 & 0x1f);
        register0x00000020 = (BADSPACEBASE *)(ulonglong)uVar4;
        *(short *)(param_1 + 0x1bc) = (short)uVar4;
      }
      goto LAB_1c0004ee5;
    }
    CompaqCheckOutstandingTmRequest(param_1);
    if (((*(char *)(param_1 + 0x6a1) != '\0') && (*(byte *)(param_1 + 0x6a3) == param_2)) &&
       ((*(char *)(*(longlong *)(param_1 + 0x6f8) + 3) == '\0' &&
        (uVar4 = (uint)*(byte *)(*(longlong *)(param_1 + 0x6f8) + 1), uVar4 != param_2)))) {
      *(ushort *)(param_1 + 0x1bc) = *(ushort *)(param_1 + 0x1bc) | (ushort)(1 << (param_2 & 0x1f));
      param_2 = uVar4;
    }
    *(undefined1 *)(param_1 + 0xf40) = 0;
    _Dst = (void *)(param_1 + 0x240);
    memset(_Dst,0,0x34);
    *(char *)(param_1 + 0x241) = (char)param_2;
    *(undefined1 *)(param_1 + 0x243) = 1;
    *(undefined1 *)(param_1 + 0x245) = 4;
    if (((*(ushort *)(param_1 + 0x134) & 0x100) != 0) && (*(short *)(param_1 + 0x1b6) == 0)) {
      *(undefined1 *)(param_1 + 0x247) = 2;
    }
    *(char *)(param_1 + 0x661) = (char)param_2;
    if (*(int *)(param_1 + 0x1c8) == 0) {
      StorPortPause(param_1,300);
    }
    *(undefined4 *)(param_1 + 0x1c0) = 3;
    if (*(char *)(param_1 + 0x678) == '\0') {
      if (*(int *)(param_1 + 0x1c8) == 0) {
        register0x00000020 = *(BADSPACEBASE **)(param_1 + 0x30);
        *(uint *)register0x00000020 = 9;
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1 + 0x68c) = 0xd;
        *(undefined4 *)(param_1 + 0x690) = 10;
        *(void **)(param_1 + 0x698) = _Dst;
        *(undefined1 *)(param_1 + 0x688) = 0xe;
        goto LAB_1c0004ee5;
      }
      bVar3 = SendMessageViaHandShake(param_1,1,0xd);
      if (!bVar3) {
        StorPortLogError(param_1,0,0,0,0,6,0xad010034);
        goto LAB_1c0004c8d;
      }
    }
    else {
      memcpy(*(void **)(param_1 + 0xd68),_Dst,0x34);
      **(undefined4 **)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0xd80);
      LOCK();
      UNLOCK();
    }
    uVar4 = *(uint *)(param_1 + 0xf60);
    if (uVar4 < 0xfffffffe) {
      uVar4 = uVar4 + 1;
      *(uint *)(param_1 + 0xf60) = uVar4;
    }
    register0x00000020 = (BADSPACEBASE *)(ulonglong)uVar4;
    if (*(int *)(param_1 + 0x1c8) != 0) {
      uVar4 = 0;
      do {
        if (*(int *)(param_1 + 0x1c0) == 0) break;
        LSImpiMSIIsr(param_1);
        register0x00000020 = (BADSPACEBASE *)StorPortStallExecution(500);
        uVar4 = uVar4 + 1;
      } while (uVar4 < 60000);
      goto LAB_1c0004ee5;
    }
  }
  else {
    if (*(char *)(param_1 + 0x669) == '\0') {
      StorPortLogError(param_1,0,0,0,0,6,0xad010036);
      **(undefined4 **)(param_1 + 0x30) = 9;
      LOCK();
      UNLOCK();
LAB_1c0004c8d:
      *(undefined1 *)(param_1 + 0x688) = 1;
      register0x00000020 = (BADSPACEBASE *)KickStart(param_1);
      goto LAB_1c0004ee5;
    }
LAB_1c0004caa:
    if (*(int *)(param_1 + 0x1c8) != 0) goto LAB_1c0004d13;
    puVar2 = *(undefined8 **)(param_1 + 0x188);
    *(undefined4 *)(param_1 + 0x1c0) = 0xc;
    iVar1 = *(int *)(param_1 + 0x58);
    StorPortPause(param_1,300);
    *puVar2 = 0;
    puVar2[1] = 0;
    *(undefined1 *)puVar2 = 4;
    *(undefined1 *)((longlong)puVar2 + 3) = 0x14;
    **(int **)(param_1 + 0x38) = (int)puVar2 - iVar1;
    LOCK();
    UNLOCK();
  }
  *(undefined1 *)(param_1 + 0x681) = 1;
  register0x00000020 = (BADSPACEBASE *)StorPortNotification(6,param_1,ResetScsiTimer,15000000);
LAB_1c0004ee5:
  return CONCAT71((int7)((ulonglong)register0x00000020 >> 8),1);
}



===== IssueMessageUnitReset @ 1c0004f04 =====

undefined8 IssueMessageUnitReset(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint *puVar6;
  
  if (((*(ushort *)(param_1 + 0x134) & 0x200) != 0) && (*(char *)(param_1 + 0x1260) != '\0')) {
    puVar6 = (uint *)(param_1 + 0x11b4);
    lVar5 = 8;
    do {
      if ((*puVar6 & 1) != 0) {
        *puVar6 = 0;
        lVar1 = *(longlong *)(puVar6 + -3);
        lVar2 = *(longlong *)(lVar1 + 0x18);
        if (*(int *)(lVar2 + 0x10) == 0x1d) {
          *(undefined4 *)(lVar2 + 0x14) = 1;
        }
        *(undefined2 *)(lVar1 + 3) = 1;
        StorPortNotification(0,param_1);
      }
      puVar6 = puVar6 + 6;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  **(undefined4 **)(param_1 + 0x10) = 0x40000000;
  LOCK();
  UNLOCK();
  uVar3 = SymWaitForResponse(param_1);
  if (((char)uVar3 == '\0') && (uVar4 = KickStart(param_1), (char)uVar4 == '\0')) {
    return uVar4;
  }
  uVar4 = StorPortSynchronizeAccess(param_1,SynchronizeOtherChannelRestart,0);
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== ResetScsiTimer @ 1c0004fc0 =====

void ResetScsiTimer(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x681) = 0;
  if (*(int *)(param_1 + 0x1c0) != 0) {
    StorPortLogError(param_1,0,0,0,0,6,0xad010028);
    *(undefined1 *)(param_1 + 0x688) = 1;
    KickStart(param_1);
  }
  *(undefined1 *)(param_1 + 0x681) = 0;
                    /* WARNING: Could not recover jumptable at 0x0001c000502c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(6,param_1,WatchdogTimer,1000000);
  return;
}



===== NonSCB_Func_handler @ 1c0005034 =====

void NonSCB_Func_handler(longlong param_1,char *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  bool bVar8;
  byte bVar10;
  char cVar9;
  bool bVar11;
  ushort uVar12;
  uint uVar13;
  longlong lVar14;
  ulonglong uVar15;
  char *pcVar16;
  undefined8 *puVar17;
  code *pcVar18;
  undefined8 uVar19;
  undefined4 uVar20;
  
  bVar8 = false;
  bVar10 = param_2[3];
  if (bVar10 != 1) {
    if (bVar10 == 4) {
      uVar20 = *(undefined4 *)(param_2 + 0x14);
      cVar9 = (char)((uint)uVar20 >> 0x10);
      bVar10 = (byte)((uint)uVar20 >> 0x18);
      if (((*(char *)(param_1 + 0xd61) != '\0') && (*(byte *)(param_1 + 0xda7) == bVar10)) &&
         (*(char *)(param_1 + 0xda6) == cVar9)) {
        *(undefined1 *)(param_1 + 0xd61) = 0;
        if ((*(char *)(*(longlong *)(param_1 + 0xdb8) + 10) == '\x02') &&
           (uVar13 = *(uint *)(*(longlong *)(param_1 + 0xdb8) + 0x28), uVar13 != 0)) {
          uVar6 = *(uint *)(param_1 + 0xd5c);
          if ((uVar6 != uVar13) && ((uVar6 != 0 || (1 < *(uint *)(param_1 + 0xd58))))) {
            StorPortLogError(param_1,0,0,0,0,5,(uVar13 << 8 | uVar6) << 0x10 | 0x7759);
          }
          *(uint *)(param_1 + 0xd5c) = uVar13;
        }
      }
      bVar3 = *(byte *)(param_1 + 0xd62);
      uVar13 = bVar3 + 0x3f;
      if (((byte)uVar13 < 0x30) &&
         ((0x800000000005U >> ((ulonglong)(uVar13 & 0xff) & 0x3f) & 1) != 0)) goto LAB_1c0005b1f;
      if (bVar3 == 0xc0) {
        lVar14 = *(longlong *)(param_1 + 0x1188);
        lVar7 = *(longlong *)(lVar14 + 0x18);
        if (*(short *)(param_2 + 0xe) == 0) {
          uVar13 = *(uint *)(*(longlong *)(param_1 + 0xe68) + 4);
          *(char *)(lVar7 + 0x24) = (char)(uVar13 >> 8);
          *(char *)(lVar7 + 0x26) = (char)(uVar13 >> 0x10);
          *(byte *)(lVar7 + 0x25) = (-((uVar13 & 0x20000000) != 0) & 8U) + 8;
          bVar10 = *(byte *)(*(longlong *)(param_1 + 0xe40) + 8);
          *(char *)(lVar7 + 0x28) = (char)uVar13;
          *(byte *)(lVar7 + 0x27) = (bVar10 & 3) - 1;
        }
        else {
          *(undefined4 *)(lVar7 + 0x14) = 1;
        }
LAB_1c00053a6:
        *(undefined2 *)(lVar14 + 3) = 1;
        StorPortNotification(0,param_1);
        *(undefined1 *)(param_1 + 0x6a1) = 0;
        goto LAB_1c0005b1f;
      }
      if (bVar3 == 0xc2) {
        CompaqCompleteSDP3Read(param_1,(longlong)param_2);
        goto LAB_1c0005b1f;
      }
      uVar12 = *(ushort *)(param_2 + 0xe);
      *(ushort *)(param_1 + 0xd64) = uVar12 & 0x7fff;
      if (((uVar12 & 0x7fff) == 0) || (-1 < (char)*(ushort *)(param_1 + 0x134))) {
        if (((param_2[0x17] & 0xfU) == 0xf) && (*param_2 == '\0')) {
          cVar4 = param_2[6];
          if (cVar4 == '\x10') {
            cVar4 = param_2[0x16];
            if (cVar4 == '\0') {
              pcVar16 = (char *)(param_1 + 0x1266);
            }
            else if (cVar4 == '\x01') {
              pcVar16 = (char *)(param_1 + 0x126e);
            }
            else if (cVar4 == '\x02') {
              pcVar16 = (char *)(param_1 + 0x1276);
            }
            else {
              if (cVar4 != '\x03') goto LAB_1c00054f5;
              pcVar16 = (char *)(param_1 + 0x127e);
            }
          }
          else if (cVar4 == '\x12') {
            if (param_2[0x16] == '\0') {
              pcVar16 = (char *)(param_1 + 0x1286);
            }
            else {
              if (param_2[0x16] != '\x01') goto LAB_1c00054f5;
              pcVar16 = (char *)(param_1 + 0x128e);
            }
          }
          else if (cVar4 == '\x13') {
            if (param_2[0x16] == '\0') {
              pcVar16 = (char *)(param_1 + 0x1296);
            }
            else {
              if (param_2[0x16] != '\x01') goto LAB_1c00054f5;
              pcVar16 = (char *)(param_1 + 0x129e);
            }
          }
          else {
            pcVar16 = (char *)(param_1 + 0x12a6);
            if (cVar4 != '\x15') {
LAB_1c00054f5:
              pcVar16 = (char *)(param_1 + 0xd9c);
            }
          }
          *pcVar16 = param_2[0x14];
          pcVar16[2] = param_2[0x16];
          pcVar16[3] = param_2[0x17];
          *(undefined2 *)(pcVar16 + 4) = *(undefined2 *)(param_2 + 4);
          pcVar16[6] = param_2[6];
        }
        else {
          *(undefined4 *)(param_1 + 0xd98) = *(undefined4 *)(param_2 + 0x14);
        }
        if (((*(ushort *)(param_1 + 0x134) & 0x200) == 0) || (*(char *)(param_1 + 0x6a0) != '\0')) {
          if (*param_2 == '\0') {
            if ((bVar10 & 0xf) == 4) {
              if (cVar9 == '\0') {
                *(undefined4 *)(param_1 + 0xe38) = uVar20;
              }
              else if (cVar9 == '\x01') {
                *(undefined4 *)(param_1 + 0xe3c) = uVar20;
              }
              else {
                *(undefined4 *)(param_1 + 0x117c) = uVar20;
              }
            }
            else {
              *(undefined4 *)(param_1 + 0xd98) = uVar20;
            }
          }
        }
        else if (*(char *)(param_1 + 0x1326) == '\0') {
          if ((*(char *)(param_1 + 0x1362) == '\0') || (*(int *)(param_2 + 8) != 0xbcaec)) {
            if (*(char *)(param_1 + 0x131a) == '\0') {
              if (*(char *)(param_1 + 0x131b) == '\0') {
                if (*(char *)(param_1 + 0x131c) == '\0') {
                  if (*(char *)(param_1 + 0x131e) == '\0') {
                    if (*(char *)(param_1 + 0x131f) == '\0') {
                      if (*(char *)(param_1 + 0x1320) == '\0') {
                        if (*(char *)(param_1 + 0x1321) == '\0') {
                          if (*(char *)(param_1 + 0x131d) == '\0') {
                            if (*(char *)(param_1 + 0x1322) == '\0') {
                              if (*(char *)(param_1 + 0x1323) == '\0') {
                                if (*(char *)(param_1 + 0x1324) == '\0') {
                                  if (*(char *)(param_1 + 0x1325) != '\0') {
                                    HpSasGetLocation(param_1);
                                  }
                                }
                                else {
                                  HpSasPhyControl(param_1);
                                }
                              }
                              else {
                                HpSasGetRaidConfig(param_1);
                              }
                            }
                            else {
                              HpSasGetRaidInfo(param_1);
                            }
                          }
                          else {
                            HpSasGetConnectorInfo(param_1);
                          }
                        }
                        else {
                          HpSasGetDeviceAddress(param_1);
                        }
                      }
                      else {
                        HpSasGetSataSignature(param_1);
                      }
                    }
                    else {
                      HpSasGetLinkErrors(param_1);
                    }
                  }
                  else {
                    HpSasSetPhyInfo(param_1);
                  }
                }
                else {
                  HpSasGetPhyInfo(param_1);
                }
              }
              else {
                HpSasSendStpPassThrough(param_1);
              }
            }
            else {
              HpSasSendSspPassThrough(param_1);
            }
          }
          else {
            SasBcAsyncEvent(param_1);
          }
        }
        else {
          HpSasGetHotSpare(param_1);
        }
        if (*(byte *)(param_1 + 0xd62) < 0x8f) goto LAB_1c0005b1f;
      }
      else {
        if (((*(short *)(param_2 + 0xe) == 0x23) && ((bVar3 - 0x31 & 0xe7) == 0)) && (bVar3 != 0x39)
           ) {
          *(ushort *)(param_1 + 0x134) = *(ushort *)(param_1 + 0x134) | 4;
          goto LAB_1c0005b1f;
        }
        if (bVar3 < 0x8f) {
          *(undefined1 *)(param_1 + 0xd62) = 0xff;
          goto LAB_1c0005b1f;
        }
        *(undefined1 *)(param_1 + 0xeae) = 0;
      }
      if ((*(uint *)(param_2 + 8) & 0x10000000) == 0) goto LAB_1c0005b1f;
LAB_1c00051ac:
      DomainValidation(param_1);
      goto LAB_1c0005b1f;
    }
    if (bVar10 == 8) goto LAB_1c0005b1f;
    uVar13 = (uint)bVar10;
    if (bVar10 == 0x14) {
      if (*(short *)(param_1 + 0x1b8) != 0) {
        StorPortLogError(param_1,0,0,0,0,6,0xad010017);
      }
      if ((*(char *)(param_1 + 0x6a1) == '\0') || (*(int *)(param_1 + 0x710) != -0x21524111)) {
        *(undefined1 *)(param_1 + 0x681) = 0;
        pcVar18 = WatchdogTimer;
        uVar19 = 1000000;
      }
      else {
        puVar17 = *(undefined8 **)(param_1 + 0x188);
        iVar5 = *(int *)(param_1 + 0x58);
        *puVar17 = 0;
        *(undefined4 *)(puVar17 + 1) = 0;
        *(undefined1 *)((longlong)puVar17 + 3) = 7;
        *(undefined1 *)puVar17 = 0;
        **(int **)(param_1 + 0x38) = (int)puVar17 - iVar5;
        LOCK();
        UNLOCK();
        *(undefined1 *)(param_1 + 0x681) = 1;
        pcVar18 = DelayedIoctlTimeout;
        uVar19 = 3000000;
      }
      StorPortNotification(6,param_1,pcVar18,uVar19);
      *(undefined4 *)(param_1 + 0x1c0) = 0;
      StorPortResume(param_1);
      goto LAB_1c0005b1f;
    }
    if (bVar10 == 0x15) {
      if ((*(ushort *)(param_1 + 0x134) & 0x200) != 0) {
        *(char **)(param_1 + 0x1340) = param_2;
        if (*(char *)(param_1 + 0x1323) == '\x06') {
          HpSasGetRaidConfig(param_1);
        }
        goto LAB_1c0005b1f;
      }
      *(undefined2 *)(param_1 + 0xeca) = *(undefined2 *)(param_2 + 0xc);
      *(undefined2 *)(param_1 + 0xec8) = *(undefined2 *)(param_2 + 0xe);
      goto LAB_1c00051ac;
    }
    if (bVar10 == 0x17) {
      if (*param_2 != '\x03') goto LAB_1c0005b1f;
      lVar14 = *(longlong *)(param_1 + 0x1188);
      if (*(short *)(param_2 + 0xe) == 0) {
        lVar7 = *(longlong *)(lVar14 + 0x18);
        uVar1 = *(undefined1 *)(lVar7 + 0x5a);
        uVar2 = *(undefined1 *)(lVar7 + 0x5b);
        *(undefined1 *)(lVar7 + 0x5a) = *(undefined1 *)(lVar7 + 0x5c);
        *(undefined1 *)(lVar7 + 0x5b) = uVar1;
        *(undefined1 *)(lVar7 + 0x5c) = uVar2;
      }
      goto LAB_1c00053a6;
    }
    if (bVar10 == 0x18) goto LAB_1c0005b1f;
    if (bVar10 == 0x1b) {
      if (*(char *)(param_1 + 0x6a0) == '\0') {
        *(undefined2 *)(param_1 + 0x1318) = *(undefined2 *)(param_2 + 0xe);
        if (*(char *)(param_1 + 0x131f) == '\0') {
          if (*(char *)(param_1 + 0x1324) != '\0') {
            HpSasPhyControl(param_1);
          }
        }
        else {
          HpSasGetLinkErrors(param_1);
        }
      }
      else if (*(short *)(param_2 + 0xe) == 0) {
        *(undefined1 *)(param_1 + 0x680) = 0;
      }
      goto LAB_1c0005b1f;
    }
    uVar20 = 5;
LAB_1c00050ab:
    StorPortLogError(param_1,0,0,0,0,uVar20,uVar13);
    goto LAB_1c0005b1f;
  }
  cVar9 = param_2[5];
  if ((*(char *)(param_1 + 0x135c) != '\0') && (*(int *)(param_2 + 8) == 0xbcaec)) {
    *(char **)(param_1 + 0x1340) = param_2;
    SasBcAsyncEvent(param_1);
    goto LAB_1c0005b1f;
  }
  if ((*(uint *)(param_2 + 8) >> 0x1a & 1) != 0) {
    uVar13 = *(uint *)(param_2 + 8) & 0xfbffffff;
    if (uVar13 < 8) {
      lVar14 = (ulonglong)uVar13 + 0xbc;
      *(undefined4 *)(param_1 + 0x14 + lVar14 * 0x18) = 0;
      if (*(char *)(param_1 + 0x1260) != '\0') {
        *(char *)(param_1 + 0x1260) = *(char *)(param_1 + 0x1260) + -1;
      }
      *(undefined1 *)(param_1 + 0xf40) = 0;
      lVar14 = *(longlong *)(param_1 + 8 + lVar14 * 0x18);
      if (lVar14 != 0) {
        lVar7 = *(longlong *)(lVar14 + 0x18);
        *(undefined2 *)(lVar14 + 3) = 1;
        *(undefined1 *)(lVar7 + 0x3c) = 0;
        if (*(short *)(param_2 + 0xe) == 0) {
          *(undefined4 *)(lVar7 + 0x14) = 0;
          *(undefined1 *)(lVar7 + 0x39) = 2;
          if (cVar9 == '\a') {
            *(undefined1 *)(lVar7 + 0x3c) = 1;
            *(undefined1 *)(lVar7 + 0x3e) = 1;
            *(char *)(lVar7 + 0x40) = param_2[4];
          }
        }
        else if (*(short *)(param_2 + 0xe) == 6) {
          *(undefined4 *)(lVar7 + 0x14) = 0;
          *(undefined1 *)(lVar7 + 0x39) = 4;
        }
        else {
          *(undefined4 *)(lVar7 + 0x14) = 1;
          *(undefined1 *)(lVar7 + 0x39) = 3;
        }
        StorPortNotification(0,param_1);
        *(undefined1 *)(param_1 + 0x6a1) = 0;
        goto LAB_1c00057c4;
      }
    }
    uVar13 = 0xad01002c;
    uVar20 = 6;
    goto LAB_1c00050ab;
  }
LAB_1c00057c4:
  if (*(int *)(param_2 + 8) == 0xc0ffaf) {
    lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x1188) + 0x18);
    *(undefined2 *)(*(longlong *)(param_1 + 0x1188) + 3) = 1;
    if (cVar9 == '\x01') {
      *(undefined8 *)(param_1 + 0x1190) = 0;
      if ((*(short *)(param_2 + 0xe) != 0) || (*(int *)(param_2 + 0x14) == 0)) {
        *(undefined4 *)(lVar14 + 0x14) = 6;
      }
    }
    else if ((cVar9 == '\x03') &&
            (*(undefined8 *)(param_1 + 0x1198) = 0, *(short *)(param_2 + 0xe) != 0)) {
      *(undefined4 *)(lVar14 + 0x14) = 7;
    }
    StorPortNotification(0,param_1);
    *(undefined1 *)(param_1 + 0xf40) = 0;
    *(undefined1 *)(param_1 + 0x6a1) = 0;
    if (cVar9 == '\x04') goto LAB_1c000583e;
LAB_1c0005971:
    if (*(longlong *)(param_1 + 0x170) == 0) goto LAB_1c000597a;
  }
  else {
LAB_1c000583e:
    if ((cVar9 - 3U & 0xfd) != 0) {
      if (cVar9 == '\x04') {
        if (*(short *)(param_1 + 0x1b8) != 0) {
          StorPortLogError(param_1,0,0,0,0,6,0xad010017);
        }
        if ((*(char *)(param_1 + 0x6a1) != '\0') && (*(int *)(param_1 + 0x710) == -0x21524111)) {
          puVar17 = *(undefined8 **)(param_1 + 0x188);
          iVar5 = *(int *)(param_1 + 0x58);
          *puVar17 = 0;
          *(undefined4 *)(puVar17 + 1) = 0;
          *(undefined1 *)((longlong)puVar17 + 3) = 7;
          *(undefined1 *)puVar17 = 0;
          **(int **)(param_1 + 0x38) = (int)puVar17 - iVar5;
          LOCK();
          UNLOCK();
          *(undefined1 *)(param_1 + 0x681) = 1;
          StorPortNotification(6,param_1,DelayedIoctlTimeout,3000000);
          bVar8 = true;
        }
        uVar12 = *(ushort *)(param_1 + 0xe78 + (ulonglong)*(byte *)(param_1 + 0xeb0) * 2);
        if ((uVar12 & 0x102) == 2) {
          *(undefined1 *)(param_1 + 0xec1) = 0;
          *(ushort *)(param_1 + 0xe78 + (ulonglong)*(byte *)(param_1 + 0xeb0) * 2) =
               uVar12 & 0xfffd | 4;
          DvCompleteOrigIo(param_1,0xe);
        }
        if ((*(char *)(param_1 + 0xec0) != '\0') && (!bVar8)) {
          *(undefined1 *)(param_1 + 0x681) = 1;
          StorPortNotification(6,param_1,DvScsiTimer,3000000);
          bVar8 = true;
        }
        goto LAB_1c000595b;
      }
      goto LAB_1c0005971;
    }
    if (*(char *)(param_1 + 0x666) != '\0') {
      uVar13 = 0;
      if (*(uint *)(param_1 + 0x1350) != 0) {
        do {
          puVar17 = (undefined8 *)((ulonglong)uVar13 * 0x10 + *(longlong *)(param_1 + 0x1348));
          if ((*(uint *)((longlong)puVar17 + 0xc) & 0x20000000) != 0) {
            uVar1 = *(undefined1 *)((longlong)puVar17 + 9);
            uVar2 = *(undefined1 *)(puVar17 + 1);
            *puVar17 = 0;
            puVar17[1] = 0;
            memset((undefined1 *)(param_1 + 0x240),0,0x34);
            *(undefined1 *)(param_1 + 0x240) = uVar1;
            *(undefined1 *)(param_1 + 0x241) = uVar2;
            *(undefined1 *)(param_1 + 0x243) = 1;
            *(undefined1 *)(param_1 + 0x245) = 3;
            bVar11 = SendMessageViaHandShake(param_1,1,0xd);
            if (bVar11) {
              *(undefined1 *)(param_1 + 0x681) = 1;
              StorPortNotification(6,param_1,ResetScsiTimer,15000000);
              goto LAB_1c0005b1f;
            }
            *(undefined1 *)(param_1 + 0x666) = 0;
            break;
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < *(uint *)(param_1 + 0x1350));
      }
      *(undefined1 *)(param_1 + 0x324) = 1;
      if ((*(short *)(param_1 + 0x1f0) == 0) && (uVar13 = 0, *(short *)(param_1 + 0x1e4) != 0)) {
        do {
          StorPortNotification(7,param_1,uVar13);
          uVar13 = uVar13 + 1;
        } while (uVar13 < *(ushort *)(param_1 + 0x1e4));
      }
      *(undefined1 *)(param_1 + 0x666) = 0;
    }
    if (*(longlong *)(param_1 + 0x170) != 0) {
LAB_1c000595b:
      uVar15 = ProcessTmResetReply(param_1,param_2);
      if ((char)uVar15 != '\0') goto LAB_1c0005b1f;
      goto LAB_1c0005971;
    }
LAB_1c000597a:
    uVar19 = CheckResetQueue(param_1);
    if ((char)uVar19 != '\0') goto LAB_1c0005b1f;
  }
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  StorPortResume(param_1);
  if (!bVar8) {
    *(undefined1 *)(param_1 + 0x681) = 0;
    StorPortNotification(6,param_1,WatchdogTimer,1000000);
  }
  uVar13 = 0;
  do {
    uVar12 = 1 << ((byte)uVar13 & 0x1f);
    if ((uVar12 & *(ushort *)(param_1 + 0x1bc)) != 0) {
      *(ushort *)(param_1 + 0x1bc) = ~uVar12 & *(ushort *)(param_1 + 0x1bc);
      LSImpiReset(param_1,uVar13);
      break;
    }
    uVar13 = uVar13 + 1;
  } while (uVar13 < 8);
LAB_1c0005b1f:
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    CheckIoctlQueue(param_1);
  }
  return;
}



===== ProcessTmResetReply @ 1c0005b4c =====

ulonglong ProcessTmResetReply(longlong param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  bool bVar7;
  longlong *in_RAX;
  ulonglong uVar8;
  ushort uVar9;
  longlong lVar10;
  undefined1 uVar11;
  longlong lVar12;
  char local_res10;
  
  cVar1 = param_2[5];
  uVar11 = 0;
  cVar2 = param_2[1];
  bVar5 = false;
  cVar6 = '\0';
  bVar7 = false;
  lVar12 = 0;
  if (cVar1 != '\x04') {
    lVar12 = *(longlong *)(param_1 + 0x170);
    bVar4 = false;
    bVar5 = true;
    cVar3 = *(char *)(lVar12 + 2);
    local_res10 = *(char *)(lVar12 + 7);
    if ((*(longlong *)(lVar12 + 0x38) == 0) ||
       (((cVar3 != ' ' && (cVar3 != '\x13')) ||
        (in_RAX = (longlong *)0x0, *(ushort *)(param_1 + 0x1e4) <= (ushort)*(byte *)(lVar12 + 5)))))
    {
      bVar4 = true;
    }
    if (((cVar3 == ' ') && (cVar1 != '\x05')) || ((cVar3 == '\x13' && (cVar1 != '\x03')))) {
      bVar4 = true;
    }
    if (bVar4) {
      *(undefined8 *)(param_1 + 0x170) = 0;
      uVar8 = CheckResetQueue(param_1);
      return uVar8;
    }
  }
  lVar10 = *(longlong *)(param_1 + 0x148);
  if (cVar1 == '\x03') {
    uVar9 = 0;
    if (*(ushort *)(param_1 + 0x1d8) != 0) {
      in_RAX = (longlong *)(lVar10 + 0x14);
      do {
        if (((*(longlong *)((longlong)in_RAX + -0xc) != 0) && ((char)*in_RAX == cVar2)) &&
           (*(char *)((longlong)in_RAX + 1) == *param_2)) goto LAB_1c0005cbd;
        in_RAX = in_RAX + 3;
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(ushort *)(param_1 + 0x1d8));
    }
  }
  else if (cVar1 == '\x04') {
    uVar9 = 0;
    if (*(ushort *)(param_1 + 0x1d8) != 0) {
      in_RAX = (longlong *)(lVar10 + 0x14);
      do {
        if ((*(longlong *)((longlong)in_RAX + -0xc) != 0) && ((char)*in_RAX == cVar2)) {
          bVar7 = true;
          break;
        }
        in_RAX = in_RAX + 3;
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(ushort *)(param_1 + 0x1d8));
    }
  }
  else if (cVar1 == '\x05') {
    uVar9 = 0;
    if (*(ushort *)(param_1 + 0x1d8) != 0) {
      in_RAX = (longlong *)(lVar10 + 0x14);
      do {
        if ((((*(longlong *)((longlong)in_RAX + -0xc) != 0) && ((char)*in_RAX == cVar2)) &&
            (*(char *)((longlong)in_RAX + 1) == *param_2)) &&
           (*(char *)((longlong)in_RAX + 2) == local_res10)) goto LAB_1c0005cbd;
        in_RAX = in_RAX + 3;
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(ushort *)(param_1 + 0x1d8));
    }
  }
LAB_1c0005cc0:
  if (bVar5) {
    if (*(longlong *)(lVar12 + 0x38) != 0) {
      *(byte *)(lVar12 + 3) = (-cVar6 & 3U) + 1;
      StorPortNotification(0,param_1,lVar12);
      in_RAX = (longlong *)(param_1 + 0x860);
      lVar10 = 100;
      do {
        if (*in_RAX == lVar12) {
          *in_RAX = -1;
        }
        in_RAX = in_RAX + 1;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
    }
    *(undefined8 *)(param_1 + 0x170) = 0;
  }
  else if (bVar7) {
    StorPortLogError(param_1,0,0,0,0,6,0xad010035);
    **(undefined4 **)(param_1 + 0x30) = 9;
    LOCK();
    UNLOCK();
    *(undefined1 *)(param_1 + 0x688) = 1;
    in_RAX = (longlong *)KickStart(param_1);
  }
  if (*(longlong *)(param_1 + 0x170) == 0) {
    in_RAX = (longlong *)CheckResetQueue(param_1);
    uVar11 = SUB81(in_RAX,0);
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),uVar11);
LAB_1c0005cbd:
  cVar6 = '\x01';
  goto LAB_1c0005cc0;
}



===== LsiMpiPartitionMemory @ 1c0005d84 =====

void LsiMpiPartitionMemory(longlong param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  ushort uVar6;
  uint *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  
  uVar6 = *(ushort *)(param_1 + 0x1d8);
  uVar8 = (ulonglong)*(ushort *)(param_1 + 300);
  uVar1 = *(ushort *)(param_1 + 0xb94);
  iVar2 = *(int *)(param_1 + 0x1c8);
  *(undefined2 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined2 *)(param_1 + 0x1da) = 0;
  *(undefined8 *)(param_1 + 0x170) = 0;
  *(undefined1 *)(param_1 + 0x6a2) = 0;
  *(undefined1 *)(param_1 + 0x681) = 0;
  *(undefined1 *)(param_1 + 0x666) = 0;
  *(undefined1 *)(param_1 + 0xd61) = 0;
  if ((*(char *)(param_1 + 0x6a1) != '\0') && (*(char *)(param_1 + 0x65f) == '\0')) {
    CleanUpIoctl(param_1);
  }
  *(longlong *)(param_1 + 0x188) = *(longlong *)(param_1 + 0x140);
  *(undefined1 *)(param_1 + 0x6a1) = 0;
  *(undefined1 *)(param_1 + 0x1362) = 0;
  lVar9 = *(longlong *)(param_1 + 0x140) + uVar8;
  *(undefined2 *)(param_1 + 0x135c) = 0;
  lVar5 = lVar9 + uVar8;
  *(longlong *)(param_1 + 0xd78) = lVar9;
  iVar3 = *(int *)(param_1 + 0x58);
  lVar9 = lVar5 + uVar8;
  *(longlong *)(param_1 + 0xd70) = lVar5;
  *(longlong *)(param_1 + 0xd68) = lVar9;
  *(int *)(param_1 + 0xd88) = *(int *)(param_1 + 0xd78) - iVar3;
  *(int *)(param_1 + 0xd84) = *(int *)(param_1 + 0xd70) - iVar3;
  *(int *)(param_1 + 0xd80) = (int)lVar9 - iVar3;
  plVar4 = (longlong *)(lVar9 + uVar8);
  if (*(char *)(param_1 + 0x134) < '\0') {
    *(longlong **)(param_1 + 0xf30) = plVar4;
    *(longlong **)(param_1 + 0xf38) = plVar4 + 0x80;
    *(longlong **)(param_1 + 0xe30) = plVar4 + 0x100;
    *(longlong **)(param_1 + 0xf28) = plVar4 + 0x180;
    plVar4 = plVar4 + 0x184;
  }
  *(longlong **)(param_1 + 0x150) = plVar4;
  *(longlong **)(param_1 + 0x158) = plVar4;
  *(longlong **)(param_1 + 0x148) = plVar4 + uVar6;
  uVar10 = 0;
  *(longlong **)(param_1 + 0x160) = plVar4;
  if (uVar6 != 0) {
    lVar9 = 0;
    do {
      *(undefined8 *)(lVar9 + 8 + *(longlong *)(param_1 + 0x148)) = 0;
      *(uint *)(lVar9 + 0x10 + *(longlong *)(param_1 + 0x148)) = uVar10;
      uVar10 = uVar10 + 1;
      lVar5 = *(longlong *)(param_1 + 0x148) + lVar9;
      lVar9 = lVar9 + 0x18;
      *plVar4 = lVar5;
      plVar4 = plVar4 + 1;
    } while (uVar10 < uVar6);
  }
  *(longlong **)(param_1 + 0x168) = plVar4;
  lVar9 = *(longlong *)(param_1 + 0x148) + (ulonglong)uVar6 * 0x18;
  *(longlong *)(param_1 + 0x670) = lVar9;
  lVar9 = lVar9 + 0x100;
  *(longlong *)(param_1 + 0x6f8) = lVar9;
  lVar9 = lVar9 + uVar8;
  lVar5 = (int)((uint)uVar1 * 0x120) + lVar9;
  *(longlong *)(param_1 + 0xba8) = lVar9;
  *(longlong *)(param_1 + 0xbb0) = lVar5;
  lVar5 = lVar5 + (ulonglong)uVar1 * 0x28;
  *(longlong *)(param_1 + 0x178) = lVar5;
  *(longlong *)(param_1 + 0x198) = lVar5;
  uVar6 = *(ushort *)(param_1 + 0x134) & 0x100;
  if ((uVar6 != 0) && (iVar2 == 0)) {
    *(ulonglong *)(param_1 + 0x198) = lVar5 + (ulonglong)*(ushort *)(param_1 + 0x1e0) * 0x18;
  }
  lVar9 = *(longlong *)(param_1 + 0x198);
  if (*(int *)(param_1 + 0x1fc) != 0) {
    lVar9 = lVar9 + (ulonglong)*(uint *)(param_1 + 0x1f8);
  }
  if ((uVar6 != 0) && (iVar2 == 0)) {
    *(longlong *)(param_1 + 0x180) = lVar9;
    lVar9 = lVar9 + 0x800;
  }
  uVar10 = 0;
  puVar7 = (uint *)(param_1 + 0xcc8);
  do {
    if ((*(char *)((longlong)puVar7 + 0x1d) == '\0') || (*puVar7 == 0)) {
      *(undefined1 *)((longlong)puVar7 + 0x1d) = 0;
    }
    else {
      *(longlong *)(puVar7 + -2) = lVar9;
      lVar9 = lVar9 + (ulonglong)*puVar7;
      *(char *)(puVar7 + 1) = (char)uVar10;
    }
    uVar10 = uVar10 + 1;
    puVar7 = puVar7 + 0xc;
  } while (uVar10 < 3);
  if ((*(ushort *)(param_1 + 0x134) & 0x200) != 0) {
    if (*(uint *)(param_1 + 0x1350) != 0) {
      *(longlong *)(param_1 + 0x1348) = lVar9;
      lVar9 = lVar9 + (ulonglong)*(uint *)(param_1 + 0x1350) * 0x10;
    }
    uVar10 = 0;
    puVar7 = (uint *)(param_1 + 0x11b0);
    do {
      *(longlong *)(puVar7 + -4) = lVar9;
      puVar7[1] = 0;
      lVar9 = lVar9 + 0x34;
      *puVar7 = uVar10 | 0x4000000;
      uVar10 = uVar10 + 1;
      puVar7[-2] = 0;
      puVar7[-1] = 0;
      puVar7 = puVar7 + 6;
    } while (uVar10 < 8);
  }
  if ((*(char *)(param_1 + 0x66a) == '\0') && (*(char *)(param_1 + 0x66b) == '\0')) {
    if ((*(uint *)(param_1 + 0x1a0) != 0) && (*(int *)(param_1 + 0x1c8) == 0)) {
      *(int *)(param_1 + 0x1a4) = (int)lVar9 - *(int *)(param_1 + 0x58);
      lVar9 = lVar9 + (ulonglong)*(uint *)(param_1 + 0x1a0);
    }
    *(undefined4 *)(param_1 + 0xd8c) = 0x400;
    *(ulonglong *)(param_1 + 0xd90) = (lVar9 - (ulonglong)((uint)lVar9 & 3)) + 4;
  }
  uVar10 = 0;
  if (*(short *)(param_1 + 0x12e) != 0) {
    do {
      if (**(int **)(param_1 + 0x40) == -1) break;
      uVar10 = uVar10 + 1;
    } while (uVar10 < *(ushort *)(param_1 + 0x12e));
  }
  *(undefined2 *)(param_1 + 0x858) = 0;
  memset((void *)(param_1 + 0x758),0,0x100);
  *(undefined2 *)(param_1 + 0xb80) = 0;
  memset((void *)(param_1 + 0x860),0,800);
  return;
}



===== LsiHandleAppRequest @ 1c0006130 =====

void LsiHandleAppRequest(longlong param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  char *pcVar10;
  byte bVar11;
  ulonglong uVar12;
  short sVar13;
  bool bVar14;
  char local_res8 [8];
  
  lVar4 = *(longlong *)((longlong)param_2 + 0x18);
  iVar1 = *(int *)(lVar4 + 0x14);
  *(void **)(param_1 + 0x6b0) = param_2;
  *(void **)(param_1 + 0x6a8) = param_2;
  *(undefined4 *)(param_1 + 0x710) = 0;
  if ((char)*(ushort *)(param_1 + 0x134) < '\0') {
    uVar8 = CompaqCsmiIOCTLRequest(param_1,(longlong)param_2);
    if ((char)uVar8 != '\0') goto LAB_1c0006626;
    puVar9 = CompaqMandPIOCTLRequest(param_1,(longlong)param_2,local_res8);
    if (((char)puVar9 != '\0') ||
       (pcVar10 = CompaqPSuiteIOCTLRequest(param_1,(longlong)param_2,local_res8),
       (char)pcVar10 != '\0')) goto LAB_1c0006193;
    uVar8 = CompaqScsiIOCTLRequest(param_1,param_2);
    if ((char)uVar8 == '\0') goto LAB_1c00061e7;
    bVar14 = *(int *)(lVar4 + 0x14) == 0;
  }
  else {
    if (((*(ushort *)(param_1 + 0x134) & 0x200) == 0) ||
       (uVar8 = HpCsmiSASIOCTLRequest(param_1,param_2,local_res8), (char)uVar8 == '\0')) {
LAB_1c00061e7:
      if (*(int *)(param_1 + 0x1c0) == 0) {
        if (**(uint **)(param_1 + 0x10) != 0xffffffff) {
          if ((**(uint **)(param_1 + 0x10) & 0xf0000000) == 0x10000000) {
            SynchronizeOtherChannelRestart(param_1);
          }
          goto LAB_1c000621c;
        }
      }
      else {
LAB_1c000621c:
        iVar2 = *(int *)(lVar4 + 0x10);
        if (iVar2 == -0x7fffff01) {
          LSImpiReset(param_1,(uint)*(byte *)((longlong)param_2 + 5));
          goto LAB_1c0006626;
        }
        if (iVar2 == -0x7fbcb6b3) {
          bVar11 = 0;
          do {
            if (*(char *)((ulonglong)bVar11 + 4 + lVar4) != (&CIM_IOCTLVER)[bVar11]) {
              *(undefined4 *)((longlong)param_2 + 0x10) = 0;
              break;
            }
            bVar11 = bVar11 + 1;
          } while (bVar11 < 4);
          if (bVar11 == 4) {
            uVar8 = RetrieveHostDriverData(param_1,(longlong)param_2);
            *(int *)((longlong)param_2 + 0x10) = (int)uVar8;
          }
          goto LAB_1c0006626;
        }
        if (iVar2 == -0x7f9b969f) {
          bVar11 = 0;
          do {
            if (*(char *)((ulonglong)bVar11 + 4 + lVar4) != (&FW_DIAG_IOCTLSIG)[bVar11]) {
              *(undefined4 *)((longlong)param_2 + 0x10) = 0;
              break;
            }
            bVar11 = bVar11 + 1;
          } while (bVar11 < 8);
          if (bVar11 != 8) goto LAB_1c0006626;
          *(void **)(param_1 + 0xd50) = param_2;
          uVar8 = PerformFwDiagOperation(param_1,lVar4,local_res8);
          if ((char)uVar8 != '\0') {
            if (local_res8[0] == '\0') {
              return;
            }
            goto LAB_1c0006626;
          }
          if ((iVar1 == -0x7f919a89) && (*(int *)(lVar4 + 0x14) != 0)) {
            *(undefined2 *)((longlong)param_2 + 3) = 1;
            goto LAB_1c0006626;
          }
        }
        else if (iVar2 == -0x7f96919f) {
          uVar12 = 0;
          do {
            bVar11 = (byte)uVar12;
            if (*(char *)(uVar12 + 4 + lVar4) != "InBand  "[uVar12]) {
              *(undefined4 *)((longlong)param_2 + 0x10) = 0;
              break;
            }
            bVar11 = bVar11 + 1;
            uVar12 = (ulonglong)bVar11;
          } while (bVar11 < 8);
          if (bVar11 != 8) goto LAB_1c0006626;
          *(void **)(param_1 + 3000) = param_2;
          lVar4 = *(longlong *)((longlong)param_2 + 0x18);
          iVar1 = *(int *)(lVar4 + 0x1c);
          if (iVar1 == 1) {
            if ((*(ushort *)(param_1 + 0x134) & 0x400) == 0) {
              *(undefined4 *)(lVar4 + 0x14) = 2;
            }
            else if ((*(int *)(param_1 + 0xba0) == 0) && (*(int *)(lVar4 + 0x24) != 0)) {
              *(int *)(param_1 + 0xba0) = *(int *)(lVar4 + 0x24);
              *(undefined1 *)(param_1 + 0xb82) = 0;
              bVar14 = PostInBandBuffer(param_1,0);
              if (bVar14) {
                return;
              }
              *(undefined4 *)(param_1 + 0xba0) = 0;
              *(undefined4 *)(lVar4 + 0x14) = 0x10;
            }
            else {
              *(undefined4 *)(lVar4 + 0x14) = 0x81500001;
            }
          }
          else if (iVar1 == 2) {
            uVar8 = UnRegisterInBandInterface(param_1,lVar4);
            if ((char)uVar8 != '\0') goto LAB_1c0006626;
          }
          else {
            if (iVar1 == 4) {
              if ((*(ushort *)(param_1 + 0x134) & 0x400) == 0) {
                *(undefined4 *)(lVar4 + 0x24) = 0;
                *(undefined1 *)(lVar4 + 0x28) = 2;
              }
              else {
                if (*(int *)(param_1 + 0xba0) != 0) {
                  *(undefined2 *)(lVar4 + 0x26) = 0x120;
                  *(undefined1 *)(lVar4 + 0x25) = *(undefined1 *)(param_1 + 0xb98);
                  *(undefined1 *)(lVar4 + 0x24) = *(undefined1 *)(param_1 + 0xb96);
                  *(undefined1 *)(lVar4 + 0x28) = 1;
                  *(undefined4 *)(lVar4 + 0x2c) = *(undefined4 *)(param_1 + 0xba0);
                  goto LAB_1c0006626;
                }
                *(undefined4 *)(lVar4 + 0x24) = 0x1200000;
                *(undefined1 *)(lVar4 + 0x28) = 0;
              }
              *(undefined4 *)(lVar4 + 0x2c) = 0;
              goto LAB_1c0006626;
            }
            if (iVar1 == 8) {
              ReadInBandBuffer(param_1,lVar4);
              goto LAB_1c0006626;
            }
          }
        }
        else if (iVar2 == -0x7f928f97) {
          if ((*(int *)(param_1 + 0x1c0) == 0) &&
             (uVar8 = SendIOCTLMessage(param_1,(ushort *)(lVar4 + 0x1c),param_2),
             (char)uVar8 != '\0')) {
            return;
          }
        }
        else if (iVar2 == -0x7f8d8c8c) {
          bVar11 = 0;
          do {
            if (*(char *)((ulonglong)bVar11 + 4 + lVar4) != (&RST_IOCTLSIG)[bVar11]) {
              *(undefined4 *)((longlong)param_2 + 0x10) = 0;
              break;
            }
            bVar11 = bVar11 + 1;
          } while (bVar11 < 8);
          if (bVar11 != 8) goto LAB_1c0006626;
          uVar3 = *(uint *)(*(longlong *)((longlong)param_2 + 0x18) + 0x1c);
          if ((uVar3 == 0) || (*(int *)(param_1 + 0x1fc) == 0)) {
LAB_1c000637f:
            *(undefined1 *)(param_1 + 0x6a1) = 1;
            StorPortPause(param_1,300);
            puVar6 = *(undefined8 **)(param_1 + 0x188);
            *(undefined4 *)(param_1 + 0x1c0) = 0xb;
            iVar1 = *(int *)(param_1 + 0x58);
            *puVar6 = 0;
            *(undefined4 *)(puVar6 + 1) = 0;
            *(undefined1 *)((longlong)puVar6 + 3) = 7;
            *(undefined1 *)puVar6 = 0;
            **(int **)(param_1 + 0x38) = (int)puVar6 - iVar1;
            LOCK();
            UNLOCK();
            *(undefined1 *)(param_1 + 0x681) = 1;
            StorPortNotification(6,param_1,DelayedDiagResetIoctl,3000000);
            return;
          }
          if ((uVar3 + 4 <= *(uint *)(lVar4 + 0x18)) && (uVar3 <= *(uint *)(param_1 + 0x1f8))) {
            memcpy(*(void **)(param_1 + 0x198),
                   (void *)(*(longlong *)((longlong)param_2 + 0x18) + 0x20),(ulonglong)uVar3);
            *(uint *)(param_1 + 0x1fc) = uVar3;
            goto LAB_1c000637f;
          }
        }
        else {
          if (iVar2 == -0x7f88e6a7) {
            bVar11 = 0;
            do {
              if (*(char *)((ulonglong)bVar11 + 4 + lVar4) != (&CIM_IOCTLVER)[bVar11]) {
                *(undefined4 *)((longlong)param_2 + 0x10) = 0;
                break;
              }
              bVar11 = bVar11 + 1;
            } while (bVar11 < 4);
            if (bVar11 != 4) goto LAB_1c0006626;
            lVar4 = *(longlong *)((longlong)param_2 + 0x18);
            lVar5 = *(longlong *)(param_1 + 0x50);
            uVar3 = *(uint *)(lVar4 + 0x20);
            iVar1 = *(int *)(lVar4 + 0x1c);
            uVar7 = *(undefined4 *)(lVar4 + 0x24);
            sVar13 = (short)lVar5 + (short)uVar3;
            if (iVar1 == 1) {
              if (lVar5 == 0) {
LAB_1c00062f2:
                *(undefined4 *)((longlong)param_2 + 0x10) = 0;
              }
              else {
                uVar7 = in(sVar13);
              }
            }
            else if (iVar1 == 2) {
              if (lVar5 == 0) goto LAB_1c00062f2;
              out(sVar13,uVar7);
            }
            else if (iVar1 == 3) {
              uVar7 = *(undefined4 *)((ulonglong)uVar3 + *(longlong *)(param_1 + 8));
            }
            else {
              if (iVar1 != 4) goto LAB_1c00062f2;
              *(undefined4 *)((ulonglong)uVar3 + *(longlong *)(param_1 + 8)) = uVar7;
              LOCK();
              UNLOCK();
            }
            *(undefined4 *)(lVar4 + 0x24) = uVar7;
            goto LAB_1c0006626;
          }
          *(undefined1 *)((longlong)param_2 + 3) = 6;
        }
      }
      *(undefined4 *)((longlong)param_2 + 0x10) = 0;
      goto LAB_1c0006626;
    }
LAB_1c0006193:
    bVar14 = local_res8[0] == '\0';
  }
  if (bVar14) {
    return;
  }
LAB_1c0006626:
  if ((*(char *)((longlong)param_2 + 3) != '\x03') && (*(char *)((longlong)param_2 + 3) != '\x06'))
  {
    *(undefined1 *)((longlong)param_2 + 4) = 0;
    *(byte *)((longlong)param_2 + 3) = (-(*(int *)((longlong)param_2 + 0x10) != 0) & 0xfdU) + 4;
  }
  StorPortNotification(0,param_1,param_2);
  *(undefined8 *)(param_1 + 0x6a8) = 0;
  return;
}



===== DelayedDiagResetIoctl @ 1c0006670 =====

void DelayedDiagResetIoctl(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x65f) = 1;
  *(undefined1 *)(param_1 + 0x688) = 1;
  KickStart(param_1);
  *(undefined1 *)(param_1 + 0x681) = 0;
                    /* WARNING: Could not recover jumptable at 0x0001c00066ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(6,param_1,WatchdogTimer,1000000);
  return;
}



===== RetrieveHostDriverData @ 1c00066b4 =====

undefined8 RetrieveHostDriverData(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  memcpy((void *)(lVar2 + 0x20),&AdapPageVersion,4);
  iVar1 = *(int *)(lVar2 + 0x1c);
  if (iVar1 == 1) {
    lVar2 = *(longlong *)(param_2 + 0x18);
    if (0x53 < *(uint *)(lVar2 + 0x18)) {
      memcpy((void *)(lVar2 + 0x24),(void *)(param_1 + 0x2e0),0x4c);
      *(undefined4 *)(lVar2 + 0x3c) = 0;
      *(undefined1 *)(param_1 + 0x324) = 0;
      return 0x70;
    }
  }
  else if (iVar1 == 3) {
    if (0x113 < *(uint *)(*(longlong *)(param_2 + 0x18) + 0x18)) {
      memcpy((void *)(*(longlong *)(param_2 + 0x18) + 0x30),(void *)(param_1 + 0xbc0),0x100);
      return 0x130;
    }
  }
  else if (iVar1 == 10) {
    if (0xf < *(uint *)(lVar2 + 0x18)) {
      *(undefined4 *)(lVar2 + 0x24) = 0x32;
      *(undefined4 *)(lVar2 + 0x28) = *(undefined4 *)(param_1 + 0x330);
      return 0x2c;
    }
  }
  else if (iVar1 == 0xb) {
    if (0xb < *(uint *)(lVar2 + 0x18)) {
      *(undefined4 *)(param_1 + 0x330) = *(undefined4 *)(lVar2 + 0x24);
      return 0x28;
    }
  }
  else if ((iVar1 == 0xc) && (0x327 < *(uint *)(lVar2 + 0x18))) {
    memcpy((void *)(lVar2 + 0x24),(void *)(param_1 + 0x338),800);
    return 0x344;
  }
  return 0;
}



===== GetCimData @ 1c00067e0 =====

void GetCimData(longlong param_1,longlong param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x2e4) = 0;
  *(uint *)(param_1 + 0x2e8) = (uint)*(ushort *)(param_2 + 2);
  *(uint *)(param_1 + 0x2ec) = (uint)*(byte *)(param_2 + 8);
  *(uint *)(param_1 + 0x2f0) = (uint)*(ushort *)(param_2 + 0x2e);
  *(uint *)(param_1 + 0x2f4) = (uint)*(ushort *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x2e0) = 0;
  if ((*(ushort *)(param_1 + 0x134) & 0x100) == 0) {
    if ((*(ushort *)(param_1 + 0x134) & 0x200) != 0) {
      uVar1 = 3;
    }
    *(undefined4 *)(param_1 + 0x2e0) = uVar1;
  }
  else {
    *(undefined4 *)(param_1 + 0x2e0) = 1;
  }
  memcpy((void *)(param_1 + 0x304),&driver_version,0x13);
  *(undefined4 *)(param_1 + 0x328) = param_3;
  if ((*(int *)(param_1 + 0x2f4) == 0x1014) && (*(int *)(param_1 + 0x2e0) != 1)) {
    *(undefined1 *)(param_1 + 0x659) = 1;
  }
  return;
}



===== SendIOCTLMessage @ 1c00068a8 =====

ulonglong SendIOCTLMessage(longlong param_1,ushort *param_2,void *param_3)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  byte bVar4;
  bool bVar5;
  undefined8 uVar6;
  void *pvVar7;
  undefined7 extraout_var;
  longlong *plVar8;
  uint uVar9;
  longlong lVar10;
  uint uVar11;
  short sVar12;
  longlong lVar13;
  uint *_Dst;
  int iVar14;
  int local_54;
  
  uVar1 = *(ushort *)(param_1 + 0x12a);
  uVar2 = *param_2;
  lVar3 = *(longlong *)((longlong)param_3 + 0x38);
  local_54 = 0;
  uVar11 = (uint)param_2[1] * 4 + 8;
  if ((uVar2 & 0x8000) == 0) {
    if ((uVar2 & 1) != 0) {
      uVar11 = uVar11 + *(int *)(param_2 + 2);
    }
  }
  else {
    uVar11 = uVar11 + param_2[3];
  }
  uVar9 = (uint)uVar1;
  if ((uVar2 & 0x8000) == 0) {
    if ((uVar2 & 1) == 0) {
      uVar9 = uVar9 + *(int *)(param_2 + 2);
    }
  }
  else {
    uVar9 = uVar9 + (*(uint *)(param_2 + 2) & 0xffff);
  }
  if ((uVar2 & 0x4000) != 0) {
    uVar9 = uVar9 + 0xff;
  }
  plVar8 = *(longlong **)((longlong)param_3 + 0x18);
  if (uVar9 < uVar11) {
    uVar9 = uVar11;
  }
  if ((*(uint *)(plVar8 + 3) < uVar9) ||
     (plVar8 = *(longlong **)(param_1 + 0x158), *(longlong *)(*plVar8 + 8) != 0))
  goto LAB_1c0006968;
  _Dst = (uint *)(lVar3 + 0x138);
  uVar11 = StorPortGetPhysicalAddress(param_1,param_3,_Dst);
  memcpy(_Dst,param_2 + 4,(longlong)(int)((uint)param_2[1] << 2));
  *(undefined4 *)(param_1 + 0x32c) = *(undefined4 *)(lVar3 + 0x140);
  *(undefined4 *)(lVar3 + 0x140) = 0x80ffeed;
  if ((*param_2 & 0x8000) == 0) {
    if ((*param_2 & 0x4000) == 0) goto LAB_1c0006a8c;
    iVar14 = 0xff;
    *(undefined1 *)(lVar3 + 0x13d) = 0xff;
    uVar9 = 0;
    if ((*param_2 & 1) == 0) {
      uVar9 = *(uint *)(param_2 + 2);
    }
    *(uint *)(lVar3 + 0x164) = uVar11 - 0x100;
    *(ulonglong *)(param_1 + 0x700) = (longlong)param_2 + (ulonglong)uVar1 + (ulonglong)uVar9;
    if ((*(ushort *)(param_1 + 0x134) & 0x800) != 0) {
      lVar13 = *(longlong *)(param_1 + 0x178);
      lVar10 = (longlong)(int)((uint)*(ushort *)(param_1 + 0x1ea) * (uint)*(byte *)(lVar3 + 0x139))
               + (ulonglong)*(byte *)_Dst;
      *(undefined1 *)(lVar3 + 0x139) = *(undefined1 *)(lVar13 + 0x10 + lVar10 * 0x18);
      *(undefined1 *)_Dst = *(undefined1 *)(lVar13 + 0x11 + lVar10 * 0x18);
    }
    *param_2 = *param_2 & 0xbfff;
  }
  else {
    iVar14 = 0x54;
    bVar4 = *(byte *)(param_1 + 0x134) & 1;
    if (bVar4 == 0) {
      sVar12 = 2;
    }
    else {
      iVar14 = 0x56;
      sVar12 = 3;
    }
    lVar13 = (longlong)(int)((uint)param_2[1] * 4);
    uVar6 = StorPortGetPhysicalAddress
                      (param_1,param_3,
                       (longlong)param_2 + (longlong)(int)((uint)param_2[1] * 4 + -4) + 0xc);
    *(uint *)(lVar13 + (longlong)_Dst) = iVar14 << 0x18 | (uint)param_2[3];
    *(int *)(lVar13 + 4 + (longlong)_Dst) = (int)uVar6;
    if (bVar4 != 0) {
      *(int *)(lVar13 + 8 + (longlong)_Dst) = (int)((ulonglong)uVar6 >> 0x20);
    }
    param_2[1] = param_2[1] + sVar12;
    param_2[3] = 0;
    *param_2 = 0;
LAB_1c0006a8c:
    iVar14 = 0;
  }
  if ((((*(char *)(lVar3 + 0x13b) == '\x04') && ((*(ushort *)(param_1 + 0x134) & 0x800) != 0)) &&
      (*(char *)(lVar3 + 0x14f) == '\x06')) && ((*(uint *)(lVar3 + 0x150) & 0xf000000) == 0x1000000)
     ) {
    lVar13 = (longlong)
             (int)((*(uint *)(lVar3 + 0x150) >> 8 & 0xff) * (uint)*(ushort *)(param_1 + 0x1ea)) +
             (ulonglong)*(byte *)(lVar3 + 0x150);
    *(uint *)(lVar3 + 0x150) =
         (uint)*(byte *)(*(longlong *)(param_1 + 0x178) + 0x10 + lVar13 * 0x18) * 0x100 + 0x1000000
         + (uint)*(byte *)(*(longlong *)(param_1 + 0x178) + 0x11 + lVar13 * 0x18);
  }
  if (*param_2 == 1) {
    uVar9 = (uint)param_2[1] * 4 + 8;
  }
  else {
    local_54 = *(int *)(param_2 + 2);
    uVar9 = (uint)uVar1;
  }
  if (*(int *)(param_2 + 2) == 0) {
    uVar2 = param_2[1];
    *(undefined4 *)((longlong)(int)((uint)uVar2 << 2) + (longlong)_Dst) = 0xd1000000;
    *(uint *)((longlong)(int)((uint)uVar2 << 2) + 4 + (longlong)_Dst) =
         uVar11 + (uint)param_2[1] * 4;
  }
  else {
    BuildIoctlScatterGather
              (param_1,(longlong)param_3,_Dst,uVar11,(short *)param_2,(int)param_2 + uVar9);
  }
  *(uint *)((longlong)param_3 + 0x10) = local_54 + 0x1c + (uint)uVar1 + iVar14;
  *(void **)(param_1 + 0x6a8) = param_3;
  memcpy((void *)(param_1 + 0x6b8),param_3,0x40);
  *(undefined1 *)(param_1 + 0x6a3) = *(undefined1 *)((longlong)param_3 + 5);
  pvVar7 = memcpy(*(void **)(param_1 + 0x6f8),_Dst,(ulonglong)*(ushort *)(param_1 + 300));
  *(undefined1 *)(param_1 + 0x6a1) = 1;
  if (*(char *)(lVar3 + 0x13b) != '\x01') {
    **(uint **)(param_1 + 0x38) = uVar11;
    LOCK();
    UNLOCK();
LAB_1c0006d18:
    return CONCAT71((int7)((ulonglong)pvVar7 >> 8),1);
  }
  plVar8 = (longlong *)(ulonglong)*(ushort *)(param_1 + 0x134);
  if ((*(ushort *)(param_1 + 0x134) & 0x800) != 0) {
    lVar13 = *(longlong *)(param_1 + 0x178);
    lVar10 = (longlong)(int)((uint)*(ushort *)(param_1 + 0x1ea) * (uint)*(byte *)(lVar3 + 0x139)) +
             (ulonglong)*(byte *)_Dst;
    *(undefined1 *)(lVar3 + 0x139) = *(undefined1 *)(lVar13 + 0x10 + lVar10 * 0x18);
    plVar8 = (longlong *)0x0;
    *(undefined1 *)_Dst = *(undefined1 *)(lVar13 + 0x11 + lVar10 * 0x18);
  }
  if (*(int *)(param_1 + 0x1c0) == 0) {
    StorPortPause(param_1,300);
    *(undefined4 *)(param_1 + 0x1c0) = 5;
    memcpy((void *)(param_1 + 0x240),_Dst,0x34);
    bVar5 = SendMessageViaHandShake(param_1,1,0xd);
    pvVar7 = (void *)CONCAT71(extraout_var,bVar5);
    if (bVar5) goto LAB_1c0006d18;
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    plVar8 = (longlong *)StorPortResume(param_1);
  }
LAB_1c0006968:
  return (ulonglong)plVar8 & 0xffffffffffffff00;
}



===== BuildIoctlScatterGather @ 1c0006d2c =====

void BuildIoctlScatterGather
               (longlong param_1,longlong param_2,uint *param_3,uint param_4,short *param_5,
               int param_6)

{
  undefined1 auVar1 [12];
  undefined1 auVar2 [12];
  byte bVar3;
  ulonglong uVar4;
  uint *puVar5;
  uint *puVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  longlong lVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint local_res20;
  uint local_58;
  int local_54;
  uint *local_50;
  
  iVar20 = 0;
  local_58 = 0;
  local_54 = 0;
  bVar3 = *(byte *)(param_1 + 0x134) & 1;
  uVar19 = 0x10;
  if (*param_5 == 1) {
    uVar19 = 0x14;
  }
  if (bVar3 == 0) {
    lVar14 = 2;
    uVar18 = 8;
  }
  else {
    uVar19 = uVar19 | 2;
    lVar14 = 3;
    uVar18 = 0xc;
  }
  puVar12 = (uint *)((longlong)(int)((uint)(ushort)param_5[1] * 4) + (longlong)param_3);
  auVar1._4_8_ = 0;
  auVar1._0_4_ = uVar18;
  auVar2._8_4_ = 0;
  auVar2._0_8_ = (longlong)(int)((uint)*(ushort *)(param_1 + 300) + (uint)(ushort)param_5[1] * -4) -
                 8;
  uVar4 = SUB128(auVar2 / auVar1,0);
  puVar5 = (uint *)StorPortGetScatterGatherList(param_1,param_2);
  uVar18 = *puVar5;
  uVar17 = param_6 - *(int *)(param_2 + 0x18);
  for (puVar5 = puVar5 + 4; puVar5[2] <= uVar17; puVar5 = puVar5 + 6) {
    uVar17 = uVar17 - puVar5[2];
    uVar18 = uVar18 - 1;
  }
  uVar11 = *(uint *)(param_5 + 2);
  uVar15 = 0;
  puVar6 = puVar5;
  if (uVar18 != 0) {
    do {
      uVar8 = puVar6[2];
      if (puVar6 == puVar5) {
        uVar8 = uVar8 - uVar17;
      }
      if (uVar11 < uVar8) {
        iVar20 = uVar8 - uVar11;
        uVar8 = uVar11;
      }
      uVar11 = uVar11 - uVar8;
      if (uVar11 == 0) break;
      puVar6 = puVar6 + 6;
      uVar15 = uVar15 + 1;
    } while (uVar15 < uVar18);
    local_54 = iVar20;
  }
  uVar15 = uVar15 + 1;
  uVar18 = SUB124(auVar2 / auVar1,0);
  if (uVar15 <= uVar18) {
    uVar18 = uVar15;
  }
  uVar10 = (ulonglong)uVar18;
  puVar6 = (uint *)0x0;
  puVar16 = puVar5;
  local_res20 = param_4;
  local_50 = param_3;
  while( true ) {
    iVar9 = (int)uVar10;
    puVar13 = puVar12;
    iVar20 = 0;
    if (iVar9 != 0) {
      do {
        *puVar12 = puVar16[2] | uVar19 << 0x18;
        puVar12[1] = *puVar16;
        if (bVar3 != 0) {
          puVar12[2] = puVar16[1];
        }
        if ((puVar16 == puVar5) && (uVar17 != 0)) {
          *puVar12 = *puVar12 - uVar17;
          puVar12[1] = puVar12[1] + uVar17;
        }
        puVar12 = puVar12 + lVar14;
        puVar16 = puVar16 + 6;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
      puVar13 = puVar12;
      iVar20 = iVar9;
    }
    local_58 = local_58 + iVar20;
    if (uVar15 <= local_58) break;
    puVar13[-lVar14] = puVar13[-lVar14] | 0x80000000;
    if (local_58 == (uint)uVar4) {
      *(char *)((longlong)param_3 + 2) = (char)((longlong)puVar13 - (longlong)local_50 >> 2);
      uVar4 = (ulonglong)*(ushort *)(param_1 + 0x128);
    }
    if (puVar6 != (uint *)0x0) {
      cVar7 = (char)lVar14 * (char)iVar20;
      *(char *)((longlong)puVar6 + 2) = cVar7;
      *(ushort *)puVar6 = (byte)(cVar7 * '\x04') + 8;
    }
    puVar12 = (uint *)((longlong)local_50 + (ulonglong)*(ushort *)(param_1 + 300));
    local_res20 = local_res20 + *(ushort *)(param_1 + 300);
    *puVar13 = 0x30000000;
    puVar13[1] = local_res20;
    uVar10 = uVar4 & 0xffffffff;
    puVar6 = puVar13;
    local_50 = puVar12;
    if (uVar15 - local_58 <= (uint)uVar4) {
      uVar10 = (ulonglong)(uVar15 - local_58);
    }
  }
  puVar13[-lVar14] = puVar13[-lVar14] | 0xc1000000;
  if (local_54 != 0) {
    puVar13[-lVar14] = puVar13[-lVar14] - local_54;
  }
  if (puVar6 != (uint *)0x0) {
    *(undefined1 *)((longlong)puVar6 + 2) = 0;
    *(ushort *)puVar6 = (ushort)(byte)((char)lVar14 * (char)iVar20 * '\x04');
  }
  return;
}



===== EnableDisableEvents @ 1c0006fa8 =====

ulonglong EnableDisableEvents(longlong param_1,char param_2)

{
  int iVar1;
  undefined8 *puVar2;
  int *piVar3;
  ulonglong uVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0x188);
  iVar1 = *(int *)(param_1 + 0x58);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 1) = 0;
  *(undefined1 *)((longlong)puVar2 + 3) = 7;
  *(bool *)puVar2 = param_2 != '\0';
  piVar3 = *(int **)(param_1 + 0x38);
  *piVar3 = (int)puVar2 - iVar1;
  LOCK();
  UNLOCK();
  if (param_2 != '\0') {
    piVar3 = *(int **)(param_1 + 0x40);
    uVar4 = 2000;
    while (iVar1 = *piVar3, iVar1 == -1) {
      StorPortStallExecution(1000);
      if ((int)uVar4 == 0) {
        return uVar4 & 0xffffffffffffff00;
      }
      uVar4 = (ulonglong)((int)uVar4 - 1);
      piVar3 = *(int **)(param_1 + 0x40);
    }
    if (iVar1 < 0) {
      piVar3 = *(int **)(param_1 + 0x40);
      *piVar3 = iVar1 * 2;
      LOCK();
      UNLOCK();
    }
  }
  return CONCAT71((int7)((ulonglong)piVar3 >> 8),1);
}



===== HandleEventNotification @ 1c0007034 =====

void HandleEventNotification(longlong param_1,short *param_2)

{
  int *piVar1;
  ushort *puVar2;
  uint uVar3;
  char *pcVar4;
  short sVar5;
  bool bVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  char cVar11;
  byte bVar12;
  ushort uVar13;
  undefined8 *puVar14;
  undefined4 *puVar15;
  byte bVar16;
  code *pcVar17;
  undefined8 uVar18;
  
  uVar3 = *(uint *)(param_2 + 10);
  if (uVar3 == 0x21) {
LAB_1c00070c6:
    if (*(char *)(param_1 + 0xe29) != '\0') {
      ScsiPortWmiFireLogicalUnitEvent(param_1);
    }
  }
  else if ((*(uint *)(param_1 + 0x330) >> (uVar3 & 0x1f) & 1) != 0) {
    cVar11 = *(byte *)(param_1 + 0x658) + 1;
    lVar10 = (ulonglong)*(byte *)(param_1 + 0x658) * 0x10;
    *(uint *)(lVar10 + 0x338 + param_1) = uVar3;
    *(int *)(param_1 + 0x334) = *(int *)(param_1 + 0x334) + 1;
    *(undefined4 *)(lVar10 + 0x33c + param_1) = *(undefined4 *)(param_1 + 0x334);
    *(undefined4 *)(lVar10 + 0x340 + param_1) = *(undefined4 *)(param_2 + 0xe);
    *(undefined4 *)(lVar10 + 0x344 + param_1) = *(undefined4 *)(param_2 + 0x10);
    if (cVar11 == '2') {
      cVar11 = '\0';
    }
    *(char *)(param_1 + 0x658) = cVar11;
    goto LAB_1c00070c6;
  }
  if (uVar3 == 1) {
    if (*param_2 != 0) {
      StorPortLogError(param_1,0,0,0,0,3,*(undefined4 *)(param_2 + 0xe));
    }
    goto LAB_1c000776f;
  }
  if (uVar3 < 4) goto LAB_1c000776f;
  if (uVar3 < 6) {
    *(undefined1 *)(param_1 + 0x324) = 1;
    if (*(short *)(param_1 + 0x1b8) != 0) {
      StorPortLogError(param_1,0,0,0,0,6,0xad01000e);
    }
    if (*(uint *)(param_1 + 0xf64) < 0xfffffffe) {
      *(uint *)(param_1 + 0xf64) = *(uint *)(param_1 + 0xf64) + 1;
    }
    goto LAB_1c000776f;
  }
  if (uVar3 == 6) {
LAB_1c00073c8:
    *(undefined1 *)(param_1 + 0x324) = 1;
    if (((*(ushort *)(param_1 + 0x134) & 0x100) != 0) && (*(int *)(param_1 + 0x1c8) == 0)) {
      cVar11 = StorPortPause(param_1,300);
      if (cVar11 == '\0') {
        StorPortLogError(param_1,0,0,0,0,6,0xad010026);
      }
      else {
        if (*(int *)(param_1 + 0x1c0) != 0) {
          *(undefined1 *)(param_1 + 0x683) = 1;
          goto LAB_1c000776f;
        }
        UpdatePersistencyTable(param_1);
        StorPortResume(param_1);
      }
    }
    if ((*(short *)(param_1 + 0x1f0) == 0) && (bVar16 = 0, *(short *)(param_1 + 0x1e4) != 0)) {
      do {
        StorPortNotification(7,param_1,bVar16);
        bVar16 = bVar16 + 1;
      } while ((ushort)bVar16 < *(ushort *)(param_1 + 0x1e4));
    }
    goto LAB_1c000776f;
  }
  if (uVar3 != 7) {
    if (uVar3 != 0xb) {
      if ((uVar3 - 0xf & 0xfffffffd) != 0) {
        if ((uVar3 == 0x17) && (*(char *)((longlong)param_2 + 0x1f) == '\x04')) {
          if ((*(char *)(param_1 + 0x135c) == '\0') && (*(char *)(param_1 + 0x6a1) == '\0')) {
            if (*(int *)(param_1 + 0x1c8) == 0) {
              StorPortPause(param_1,300);
            }
            *(undefined4 *)(param_1 + 0x1c0) = 0xe;
            *(undefined1 *)(param_1 + 0x135c) = 1;
            *(undefined1 *)(param_1 + 0x1362) = 1;
            SasBcAsyncEvent(param_1);
          }
          else {
            *(undefined1 *)(param_1 + 0x135d) = 1;
          }
        }
        goto LAB_1c000776f;
      }
      if ((*(ushort *)(param_1 + 0x134) & 0x200) == 0) goto LAB_1c000776f;
      cVar11 = (char)param_2[0xf];
      if ((cVar11 == '\x06') || (uVar3 == 0x11)) {
        piVar1 = (int *)(param_1 + 0x1354);
        *piVar1 = *piVar1 + 1;
        if (*piVar1 == 0) {
          *(int *)(param_1 + 0x1354) = *(int *)(param_1 + 0x1354) + 1;
        }
        *(undefined1 *)(param_1 + 0x680) = 1;
        if (((*(ushort *)(param_1 + 0x134) & 0x1000) != 0) || (*(short *)(param_1 + 0x1b8) != 0)) {
          StorPortLogError(param_1,0,0,0,0,6,0xad01002d);
        }
        if ((*(ushort *)(param_1 + 0x134) & 0x1000) == 0) {
          puVar14 = *(undefined8 **)(param_1 + 0xd68);
          *puVar14 = 0;
          puVar14[1] = 0;
          puVar14[2] = 0;
          puVar14[3] = 0;
          *(undefined1 *)puVar14 = 1;
          *(undefined1 *)((longlong)puVar14 + 3) = 0x1b;
          *(undefined4 *)(puVar14 + 1) = 0xface;
          **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
          LOCK();
          UNLOCK();
        }
        goto LAB_1c000776f;
      }
      if (cVar11 == '\x05') goto LAB_1c000776f;
      if (cVar11 != '\x04') {
        if (cVar11 == '\x03') {
          if (*(short *)(param_1 + 0x1b8) != 0) {
            StorPortLogError(param_1,0,0,0,0,6,0xad010032);
          }
          piVar1 = (int *)(param_1 + 0x1354);
          *piVar1 = *piVar1 + 1;
          if (*piVar1 == 0) {
            *(int *)(param_1 + 0x1354) = *(int *)(param_1 + 0x1354) + 1;
          }
          uVar8 = 0;
          if (*(uint *)(param_1 + 0x1350) != 0) {
            do {
              puVar15 = (undefined4 *)((ulonglong)uVar8 * 0x10 + *(longlong *)(param_1 + 0x1348));
              if (puVar15[3] == 0) {
                *puVar15 = *(undefined4 *)(param_2 + 0x16);
                puVar15[1] = *(undefined4 *)(param_2 + 0x18);
                *(undefined1 *)(puVar15 + 2) = *(undefined1 *)((longlong)param_2 + 0x1d);
                *(char *)((longlong)puVar15 + 9) = (char)param_2[0xe];
                *(short *)((longlong)puVar15 + 10) = param_2[0x11];
                puVar15[3] = *(uint *)(param_2 + 0x12) & 0xffff;
                break;
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < *(uint *)(param_1 + 0x1350));
          }
        }
        else {
          if ((*(short *)(param_1 + 0x1b8) == 0) || (cVar11 != '\x0e')) goto LAB_1c000776f;
          StorPortLogError(param_1,0,0,0,0,6,0xad010039);
        }
        goto LAB_1c00073c8;
      }
      if (*(short *)(param_1 + 0x1b8) != 0) {
        StorPortLogError(param_1,0,0,0,0,6,0xad010031);
      }
      piVar1 = (int *)(param_1 + 0x1354);
      *piVar1 = *piVar1 + 1;
      if (*piVar1 == 0) {
        *(int *)(param_1 + 0x1354) = *(int *)(param_1 + 0x1354) + 1;
      }
      uVar8 = 0;
      cVar11 = *(char *)((longlong)param_2 + 0x1d);
      sVar5 = param_2[0xe];
      if (*(uint *)(param_1 + 0x1350) != 0) {
        do {
          puVar14 = (undefined8 *)((ulonglong)uVar8 * 0x10 + *(longlong *)(param_1 + 0x1348));
          if (((*(char *)(puVar14 + 1) == cVar11) &&
              (*(char *)((longlong)puVar14 + 9) == (char)sVar5)) &&
             ((*(uint *)((longlong)puVar14 + 0xc) & 0x1fffffff) == *(uint *)(param_2 + 0x12))) {
            if (*(int *)((longlong)puVar14 + 0xc) < 0) {
              pcVar4 = *(char **)(param_1 + 0xd68);
              pcVar4[0] = '\0';
              pcVar4[1] = '\0';
              pcVar4[2] = '\0';
              pcVar4[3] = '\0';
              pcVar4[4] = '\0';
              pcVar4[5] = '\0';
              pcVar4[6] = '\0';
              pcVar4[7] = '\0';
              pcVar4[8] = '\0';
              pcVar4[9] = '\0';
              pcVar4[10] = '\0';
              pcVar4[0xb] = '\0';
              pcVar4[0xc] = '\0';
              pcVar4[0xd] = '\0';
              pcVar4[0xe] = '\0';
              pcVar4[0xf] = '\0';
              pcVar4[0x10] = '\0';
              pcVar4[0x11] = '\0';
              pcVar4[0x12] = '\0';
              pcVar4[0x13] = '\0';
              pcVar4[0x14] = '\0';
              pcVar4[0x15] = '\0';
              pcVar4[0x16] = '\0';
              pcVar4[0x17] = '\0';
              pcVar4[0x18] = '\0';
              pcVar4[0x19] = '\0';
              pcVar4[0x1a] = '\0';
              pcVar4[0x1b] = '\0';
              pcVar4[0x1c] = '\0';
              pcVar4[0x1d] = '\0';
              pcVar4[0x1e] = '\0';
              pcVar4[0x1f] = '\0';
              *pcVar4 = (char)sVar5;
              pcVar4[1] = cVar11;
              pcVar4[3] = '\x18';
              pcVar4[4] = '\0';
              pcVar4[8] = -0x13;
              pcVar4[9] = -2;
              pcVar4[10] = '\0';
              pcVar4[0xb] = '\x10';
              pcVar4[0xc] = -0x80;
              pcVar4[0xd] = '\0';
              pcVar4[0xe] = '\0';
              pcVar4[0xf] = '\0';
              **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
              LOCK();
              UNLOCK();
            }
            if (*(int *)(param_1 + 0x1c0) == 0) {
              *puVar14 = 0;
              puVar14[1] = 0;
            }
            else {
              *(uint *)((longlong)puVar14 + 0xc) = *(uint *)((longlong)puVar14 + 0xc) | 0x20000000;
            }
            break;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(param_1 + 0x1350));
      }
      if (*(int *)(param_1 + 0x1c0) != 0) goto LAB_1c000776f;
      memset((undefined1 *)(param_1 + 0x240),0,0x34);
      *(undefined1 *)(param_1 + 0x240) = (char)param_2[0xe];
      *(undefined1 *)(param_1 + 0x241) = *(undefined1 *)((longlong)param_2 + 0x1d);
      *(undefined1 *)(param_1 + 0x243) = 1;
      *(undefined1 *)(param_1 + 0x245) = 3;
      *(undefined1 *)(param_1 + 0x666) = 1;
      if (*(int *)(param_1 + 0x1c8) == 0) {
        StorPortPause(param_1,0x4b0);
      }
      *(undefined4 *)(param_1 + 0x1c0) = 6;
      bVar6 = SendMessageViaHandShake(param_1,1,0xd);
      if (!bVar6) {
        *(undefined1 *)(param_1 + 0x666) = 0;
        *(undefined4 *)(param_1 + 0x1c0) = 0;
        StorPortResume(param_1);
        goto LAB_1c000776f;
      }
      uVar18 = 15000000;
      pcVar17 = ResetScsiTimer;
LAB_1c0007557:
      *(undefined1 *)(param_1 + 0x681) = 1;
      StorPortNotification(6,param_1,pcVar17,uVar18);
      goto LAB_1c000776f;
    }
    bVar16 = *(byte *)(param_2 + 0xf);
    if ((char)*(ushort *)(param_1 + 0x134) < '\0') {
      if (bVar16 == 9) {
        pcVar17 = DvScsiTimer;
        *(undefined1 *)(param_1 + 0xeb8) = *(undefined1 *)((longlong)param_2 + 0x1f);
        uVar18 = 6000000;
        *(undefined1 *)(param_1 + 0xeb0) = 0x11;
        *(undefined1 *)(param_1 + 0xeae) = 0x12;
        *(undefined1 *)(param_1 + 0xec0) = 1;
        goto LAB_1c0007557;
      }
      if (bVar16 == 8) {
        if (((*(char *)((longlong)param_2 + 0x25) == '\x01') &&
            (lVar10 = *(longlong *)(param_1 + 0xe58), lVar10 != 0)) &&
           (bVar16 = *(byte *)(lVar10 + 4), bVar16 != 0)) {
          pbVar7 = (byte *)(lVar10 + 8);
          bVar12 = 0;
          if (bVar16 != 0) {
            do {
              if ((pbVar7[3] == *(byte *)((longlong)param_2 + 0x1f)) &&
                 (pbVar7[2] == *(byte *)(param_1 + 0xe2a))) {
                bVar16 = *pbVar7;
                goto LAB_1c00075cb;
              }
              pbVar7 = pbVar7 + 4;
              bVar12 = bVar12 + 1;
            } while (bVar12 < bVar16);
          }
          bVar16 = 0xff;
LAB_1c00075cb:
          if (bVar16 != 0xff) {
            puVar2 = (ushort *)(param_1 + 0xe78 + (ulonglong)bVar16 * 2);
            *puVar2 = *puVar2 | 1;
            *(undefined1 *)((ulonglong)bVar16 + 0xe9c + param_1) = 0;
            CheckQASBusStatus(param_1);
          }
        }
        goto LAB_1c000776f;
      }
    }
    uVar13 = *(ushort *)(param_1 + 0x134) & 0x200;
    if (uVar13 != 0) {
      piVar1 = (int *)(param_1 + 0x1354);
      *piVar1 = *piVar1 + 1;
      if (*piVar1 == 0) {
        *(int *)(param_1 + 0x1354) = *(int *)(param_1 + 0x1354) + 1;
      }
      if (bVar16 == 8) {
        if (*(char *)((longlong)param_2 + 0x25) == '\0') {
          AddNewIRDiskToSasTable(param_1,*(char *)((longlong)param_2 + 0x1f));
        }
        goto LAB_1c000776f;
      }
    }
    if (((uVar13 != 0) && (bVar16 < 7)) && ((0x6bU >> (bVar16 & 0x1f) & 1) != 0)) {
      *(undefined1 *)(param_1 + 0x324) = 1;
      if (*(short *)(param_1 + 0x1f0) == 0) {
        StorPortNotification(7,param_1,*(undefined1 *)((longlong)param_2 + 0x1d));
      }
      goto LAB_1c000776f;
    }
  }
  *(undefined1 *)(param_1 + 0xd60) = 1;
LAB_1c000776f:
  if ((char)param_2[3] != '\0') {
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
    *(undefined1 *)((longlong)param_2 + 3) = 8;
    iVar9 = (int)param_2 - *(int *)(param_1 + 0x58);
    *(int *)(param_2 + 4) = iVar9;
    *(uint *)(param_2 + 6) = uVar3;
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_2 + 0xc);
    **(int **)(param_1 + 0x38) = iVar9;
    LOCK();
    UNLOCK();
  }
  return;
}



===== LSImpiAdapterControl @ 1c00077c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 LSImpiAdapterControl(longlong param_1,int param_2,longlong param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 local_d8 [32];
  byte *local_b8;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined1 local_98 [106];
  byte local_2e [22];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_d8;
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 4) = 0x101;
    *(undefined1 *)(param_3 + 6) = 1;
    if (*(char *)(param_1 + 0x668) != '\0') {
      *(undefined1 *)(param_3 + 8) = 1;
    }
  }
  else if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0x665) = 1;
    if (*(char *)(param_1 + 0x664) == '\0') {
      *(undefined1 *)(param_1 + 0x664) = 1;
      **(undefined4 **)(param_1 + 0x30) = 9;
      LOCK();
      UNLOCK();
      if ((*(int *)(param_1 + 0x1fc) != 0) && ((*(uint *)(param_1 + 0x328) & 0xe0) == 0)) {
        uVar1 = 0;
        do {
          if (**(int **)(param_1 + 0x10) == 0) break;
          StorPortStallExecution(1000);
          uVar1 = uVar1 + 1;
        } while (uVar1 < 800);
        if (uVar1 < 800) {
          return 0;
        }
      }
      **(undefined4 **)(param_1 + 0x10) = 0x40000000;
      LOCK();
      UNLOCK();
      SymWaitForResponse(param_1);
      if ((*(int *)(param_1 + 0x1fc) != 0) && ((**(uint **)(param_1 + 0x20) & 0x20) == 0)) {
        **(undefined4 **)(param_1 + 0x10) = 0x41000000;
        LOCK();
        UNLOCK();
        SymWaitForResponse(param_1);
        lVar4 = 600;
        do {
          StorPortStallExecution(1000);
          lVar4 = lVar4 + -1;
        } while (lVar4 != 0);
        KickStart(param_1);
      }
    }
  }
  else if (param_2 == 2) {
    *(undefined1 *)(param_1 + 0x665) = 0;
    *(undefined1 *)(param_1 + 0x688) = 1;
    if (((*(int *)(param_1 + 0x1a8) - 0x56U & 0xfffffffd) == 0) || (**(int **)(param_1 + 0x10) == 0)
       ) {
      ClearResetHistoryBit(param_1);
      KickStart(param_1);
    }
    else {
      **(undefined4 **)(param_1 + 0x10) = 0x40000000;
      LOCK();
      UNLOCK();
      SymWaitForResponse(param_1);
    }
    StorPortPause(param_1,300);
  }
  else if (param_2 == 4) {
    memset(local_98,0,0x80);
    uVar2 = *(uint *)(param_1 + 0x328) & 0xff;
    local_b8 = local_98;
    uVar3 = *(uint *)(param_1 + 0x328) >> 8;
    local_b0 = 0x80;
    uVar1 = StorPortGetBusData(param_1,4,uVar3,uVar2);
    if (0x69 < uVar1) {
      local_2e[0] = local_2e[0] & 0x8f;
      local_b8 = local_2e;
      local_a8 = 2;
      local_b0 = 0x6a;
      StorPortSetBusDataByOffset(param_1,4,uVar3,uVar2);
    }
  }
  return 0;
}



===== ProcessParseArgumentString @ 1c0007a00 =====

ulonglong ProcessParseArgumentString(char *param_1,char *param_2,int *param_3)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char cVar5;
  undefined7 uVar6;
  char *pcVar7;
  uint uVar8;
  
  uVar6 = (undefined7)((ulonglong)param_2 >> 8);
  uVar8 = 0;
  uVar2 = 0;
  cVar5 = *param_1;
  pcVar1 = param_1;
  while (cVar5 != '\0') {
    pcVar1 = pcVar1 + 1;
    uVar2 = uVar2 + 1;
    cVar5 = *pcVar1;
  }
  pcVar1 = param_2;
  if (*param_2 != '\0') {
    do {
      pcVar1 = pcVar1 + 1;
      uVar8 = uVar8 + 1;
    } while (*pcVar1 != '\0');
    if (uVar2 < uVar8) {
LAB_1c0007b87:
      return (ulonglong)pcVar1 & 0xffffffffffffff00;
    }
  }
  do {
    while( true ) {
      cVar5 = *param_1;
      pcVar1 = (char *)CONCAT71((int7)((ulonglong)pcVar1 >> 8),cVar5);
      if ((cVar5 != ' ') && (cVar5 != '\t')) break;
LAB_1c0007abe:
      param_1 = param_1 + 1;
    }
    if (cVar5 == '\0') goto LAB_1c0007b87;
    pcVar4 = param_2;
    pcVar7 = param_1;
    if (cVar5 == *param_2) {
      do {
        param_1 = pcVar7 + 1;
        pcVar4 = pcVar4 + 1;
        if (*pcVar7 == '\0') goto LAB_1c0007b87;
        pcVar1 = (char *)CONCAT71((int7)((ulonglong)pcVar1 >> 8),*pcVar4);
        pcVar7 = param_1;
      } while (*param_1 == *pcVar4);
    }
    if (*pcVar4 == '\0') {
      while( true ) {
        cVar5 = *param_1;
        pcVar1 = (char *)CONCAT71((int7)((ulonglong)pcVar1 >> 8),cVar5);
        if ((cVar5 != ' ') && (cVar5 != '\t')) break;
        param_1 = param_1 + 1;
      }
      if (*param_1 == '=') {
        do {
          do {
            pcVar4 = param_1;
            param_1 = pcVar4 + 1;
            cVar5 = *param_1;
            pcVar1 = (char *)CONCAT71((int7)((ulonglong)pcVar1 >> 8),cVar5);
          } while (cVar5 == ' ');
        } while (cVar5 == '\t');
        if (cVar5 != '\0') {
          if (cVar5 == ';') goto LAB_1c0007abe;
          *param_3 = 0;
          cVar5 = *param_1;
          if ((cVar5 == '0') && (pcVar4[2] == 'x')) {
            cVar5 = pcVar4[3];
            pcVar4 = (char *)0x0;
            goto LAB_1c0007b42;
          }
          pcVar4 = (char *)0x0;
          break;
        }
        goto LAB_1c0007b87;
      }
      do {
        cVar5 = *param_1;
        pcVar1 = (char *)CONCAT71((int7)((ulonglong)pcVar1 >> 8),cVar5);
        if (cVar5 == '\0') goto LAB_1c0007b87;
        param_1 = param_1 + 1;
      } while (cVar5 != ';');
    }
    else {
      do {
        cVar5 = *param_1;
        pcVar1 = (char *)CONCAT71((int7)((ulonglong)pcVar1 >> 8),cVar5);
        if (cVar5 == '\0') goto LAB_1c0007b87;
        param_1 = param_1 + 1;
      } while (cVar5 != ';');
    }
  } while( true );
LAB_1c0007b80:
  if ((((cVar5 == '\0') || (cVar5 == ' ')) || (cVar5 == '\t')) || (cVar5 == ';'))
  goto LAB_1c0007b84;
  uVar2 = (int)CONCAT71(uVar6,cVar5) - 0x30;
  pcVar1 = (char *)(ulonglong)uVar2;
  if (9 < (byte)uVar2) goto LAB_1c0007b87;
  pcVar1 = (char *)(ulonglong)((int)pcVar4 + 1);
  iVar3 = (int)cVar5;
  cVar5 = pcVar1[(longlong)param_1];
  *param_3 = iVar3 + (*param_3 * 5 + -0x18) * 2;
  pcVar4 = pcVar1;
  goto LAB_1c0007b80;
LAB_1c0007b42:
  if (((cVar5 == '\0') || (cVar5 == ' ')) || ((cVar5 == '\t' || (cVar5 == ';')))) {
LAB_1c0007b84:
    return CONCAT71((int7)((ulonglong)pcVar1 >> 8),1);
  }
  if ((byte)(cVar5 - 0x30U) < 10) {
    iVar3 = *param_3 * 0x10 + -0x30;
  }
  else {
    uVar2 = (int)CONCAT71(uVar6,cVar5) - 0x61;
    pcVar1 = (char *)(ulonglong)uVar2;
    if (5 < (byte)uVar2) goto LAB_1c0007b87;
    iVar3 = *param_3 * 0x10 + -0x57;
  }
  pcVar1 = (char *)(ulonglong)((int)pcVar4 + 1);
  *param_3 = iVar3 + cVar5;
  cVar5 = (pcVar1 + 2)[(longlong)param_1];
  pcVar4 = pcVar1;
  goto LAB_1c0007b42;
}



===== CheckMpiIoctlReply @ 1c0007b8c =====

ulonglong CheckMpiIoctlReply(longlong param_1,uint param_2)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  bool bVar5;
  ulonglong in_RAX;
  undefined8 uVar6;
  char *pcVar7;
  ulonglong uVar8;
  char cVar9;
  ushort uVar10;
  int *piVar11;
  longlong lVar12;
  char *pcVar13;
  longlong lVar14;
  uint uVar15;
  longlong lVar16;
  char *pcVar17;
  
  lVar12 = 0;
  pcVar17 = (char *)0x0;
  if ((param_2 & 0xe0000000) == 0) {
    if ((param_2 >> 0x1b & 1) == 0) goto LAB_1c0007bdd;
    bVar5 = true;
  }
  else {
    pcVar17 = (char *)(*(longlong *)(param_1 + 0x58) + (ulonglong)(param_2 & 0x7fffffff) * 2);
    in_RAX = (ulonglong)*(uint *)(pcVar17 + 8);
    if ((*(uint *)(pcVar17 + 8) >> 0x1b & 1) == 0) {
LAB_1c0007bdd:
      return in_RAX & 0xffffffffffffff00;
    }
    bVar5 = false;
  }
  if (*(char *)(param_1 + 0x6a1) == '\0') goto LAB_1c0007fe6;
  if (*(char *)(param_1 + 0x6a2) != '\0') {
    bVar2 = *(byte *)(param_1 + 0x755);
    *(int *)(param_1 + 0x70c) = *(int *)(param_1 + 0x70c) + 1;
    *(undefined1 *)((ulonglong)bVar2 + 0x734 + param_1) =
         *(undefined1 *)(*(longlong *)(param_1 + 0x6f8) + 3);
    cVar9 = bVar2 + 1;
    if (cVar9 == ' ') {
      cVar9 = '\0';
    }
    *(char *)(param_1 + 0x755) = cVar9;
  }
  lVar12 = *(longlong *)(param_1 + 0x6a8);
  piVar11 = (int *)(param_1 + 0x6b8);
  uVar15 = 0;
  lVar16 = lVar12 - (longlong)piVar11;
  lVar14 = 4;
  lVar4 = *(longlong *)(lVar12 + 0x38);
  do {
    iVar3 = *piVar11;
    piVar1 = (int *)(lVar16 + (longlong)piVar11);
    piVar11 = piVar11 + 1;
    if (iVar3 != *piVar1) goto LAB_1c0007fdf;
    uVar15 = uVar15 + 1;
  } while (uVar15 < 0x10);
  piVar11 = *(int **)(param_1 + 0x6f8);
  uVar15 = 0;
  if (*(uint *)(param_1 + 500) != 0) {
    lVar16 = (lVar4 + 0x138) - (longlong)piVar11;
    do {
      iVar3 = *piVar11;
      piVar1 = (int *)(lVar16 + (longlong)piVar11);
      piVar11 = piVar11 + 1;
      if (iVar3 != *piVar1) goto LAB_1c0007fdf;
      uVar15 = uVar15 + 1;
    } while (uVar15 < *(uint *)(param_1 + 500));
  }
  iVar3 = *(int *)(param_1 + 0x32c);
  lVar16 = *(longlong *)(lVar12 + 0x18);
  if (iVar3 == 0xc0ffaf) {
    *(undefined4 *)(lVar16 + 0x78) = 0;
    if (bVar5) {
      *(undefined2 *)(lVar16 + 0x48) = 0;
      *(undefined4 *)(lVar16 + 0x74) = 0;
      goto LAB_1c0007fe6;
    }
    bVar2 = pcVar17[0xd];
    uVar10 = *(ushort *)(pcVar17 + 0xe) & 0x7fff;
    *(char *)(lVar16 + 0x48) = pcVar17[0xc];
    *(int *)(lVar16 + 0x74) = *(int *)(param_1 + 0xf58) - *(int *)(pcVar17 + 0x14);
    if ((((uVar10 == 0) || (uVar10 == 0x40)) || (uVar10 == 0x45)) && ((bVar2 & 0x10) == 0)) {
      if ((bVar2 & 1) != 0) {
        memcpy((void *)(lVar16 + 0x4a),(void *)(lVar4 + 0x38),(ulonglong)*(uint *)(pcVar17 + 0x18));
        *(char *)(lVar16 + 0x49) = pcVar17[0x18];
        goto LAB_1c0007fe6;
      }
    }
    else {
      *(undefined4 *)(lVar16 + 0x14) = 1;
    }
  }
  else {
    if ((iVar3 != -0x3facb2b0) || (bVar5)) {
      if (iVar3 == -0x3facacb0) {
        *(undefined2 *)(lVar16 + 0x6a) = 0;
        if (bVar5) {
          *(undefined4 *)(lVar16 + 0x16c) = *(undefined4 *)(lVar16 + 0x60);
          *(undefined2 *)(lVar16 + 100) = 0x200;
          *(undefined2 *)(lVar16 + 0x68) = 0;
        }
        else {
          bVar2 = pcVar17[0xd];
          uVar10 = *(ushort *)(pcVar17 + 0xe) & 0x7fff;
          *(char *)(lVar16 + 0x69) = pcVar17[0xc];
          *(undefined4 *)(lVar16 + 0x16c) = *(undefined4 *)(pcVar17 + 0x14);
          *(undefined1 *)(lVar16 + 0x65) = 4;
          if ((bVar2 & 1) == 0) {
            if ((bVar2 & 0x10) == 0) {
              if (((uVar10 != 0) && (uVar10 != 0x40)) && (uVar10 != 0x45)) {
                *(undefined4 *)(lVar16 + 0x14) = 1;
                *(undefined1 *)(lVar16 + 0x65) = 3;
              }
            }
            else {
              *(undefined1 *)(lVar16 + 0x68) = 1;
              pcVar7 = pcVar17 + 0x1f;
              *(undefined1 *)(lVar16 + 0x6a) = 4;
              pcVar13 = (char *)(lVar16 + 0x6c);
              do {
                cVar9 = *pcVar7;
                pcVar7 = pcVar7 + -1;
                *pcVar13 = cVar9;
                pcVar13 = pcVar13 + 1;
                lVar14 = lVar14 + -1;
              } while (lVar14 != 0);
            }
          }
          else {
            *(undefined1 *)(lVar16 + 0x68) = 2;
            memcpy((void *)(lVar16 + 0x6c),(void *)(lVar4 + 0x38),
                   (ulonglong)*(uint *)(pcVar17 + 0x18));
            *(char *)(lVar16 + 0x6a) = pcVar17[0x18];
          }
        }
        *(undefined8 *)(param_1 + 0x1310) = 0;
        *(undefined4 *)(param_1 + 0x32c) = 0;
        goto LAB_1c0007fe6;
      }
      if ((iVar3 != -0x3facabb0) || (bVar5)) {
        if ((iVar3 != -0x3fb9a8bc) || (bVar5)) {
          if (*(char *)(param_1 + 0x1323) != '\0') {
            HpSasGetRaidConfig(param_1);
            **(int **)(param_1 + 0x40) = param_2 * 2;
            LOCK();
            UNLOCK();
            return 1;
          }
          *(undefined4 *)(lVar16 + 0x14) = 0;
          if (!bVar5) {
            uVar15 = 0;
            *(undefined4 *)(pcVar17 + 8) = *(undefined4 *)(param_1 + 0x32c);
            if (pcVar17[2] != '\0') {
              do {
                uVar8 = (ulonglong)uVar15;
                uVar15 = uVar15 + 1;
                *(undefined4 *)(lVar16 + 0x1c + uVar8 * 4) = *(undefined4 *)(pcVar17 + uVar8 * 4);
              } while (uVar15 < (byte)pcVar17[2]);
            }
            if ((((byte)pcVar17[3] < 0x20) && ((0x80400001U >> ((byte)pcVar17[3] & 0x1f) & 1) != 0))
               && ((pcVar17[0xd] & 1U) != 0)) {
              memcpy(*(void **)(param_1 + 0x700),(void *)(lVar4 + 0x38),
                     (ulonglong)*(uint *)(pcVar17 + 0x18));
            }
            goto LAB_1c0007fef;
          }
          *(undefined4 *)(lVar16 + 0x1c) = *(undefined4 *)(param_1 + 0x32c);
          goto LAB_1c0007fe6;
        }
        if (*(short *)(pcVar17 + 0xe) == 0) {
          *(undefined2 *)(lVar16 + 0x44) = 0;
          *(undefined4 *)(lVar16 + 0x14) = 0;
        }
        else {
          *(undefined4 *)(lVar16 + 0x44) = 0x30001;
          *(undefined4 *)(lVar16 + 0x14) = 1;
        }
      }
      else {
        if ((*(short *)(pcVar17 + 0xe) != 0) && (*(short *)(pcVar17 + 0xe) != 0x45)) {
          *(undefined4 *)(lVar16 + 0x14) = 1;
        }
        uVar6 = MapMpiSasStatusToCsmi(1,pcVar17[0xd]);
        *(char *)(lVar16 + 0x48) = (char)uVar6;
        memcpy((void *)(lVar16 + 0x4c),pcVar17 + 0x14,0x14);
        memset((void *)(lVar16 + 0x60),0,0x40);
        *(undefined4 *)(lVar16 + 0x60) = *(undefined4 *)(pcVar17 + 0x28);
        *(undefined4 *)(lVar16 + 0xa0) = *(undefined4 *)(pcVar17 + 0x2c);
        *(undefined8 *)(param_1 + 0x1310) = 0;
      }
    }
    else {
      if ((*(short *)(pcVar17 + 0xe) != 0) && (*(short *)(pcVar17 + 0xe) != 0x45)) {
        *(undefined4 *)(lVar16 + 0x14) = 1;
      }
      uVar6 = MapMpiSasStatusToCsmi(1,pcVar17[0xd]);
      *(char *)(lVar16 + 0x428) = (char)uVar6;
      *(uint *)(lVar16 + 0x42c) = (uint)*(ushort *)(pcVar17 + 4);
      *(undefined4 *)(lVar12 + 0x10) = 0x82c;
      if (*pcVar17 < '\0') {
        if (*(ushort *)(pcVar17 + 4) < 0x3fd) {
          memcpy((void *)(lVar16 + 0x430),pcVar17 + 0x18,(ulonglong)*(ushort *)(pcVar17 + 4));
        }
        else {
          *(undefined4 *)(lVar16 + 0x14) = 3;
        }
      }
    }
    *(undefined4 *)(param_1 + 0x32c) = 0;
  }
  goto LAB_1c0007fef;
LAB_1c0007fdf:
  *(undefined1 *)(param_1 + 0x6a1) = 0;
LAB_1c0007fe6:
  if (bVar5) goto LAB_1c0008032;
LAB_1c0007fef:
  if ((pcVar17[3] == '\x01') &&
     (((*(longlong *)(param_1 + 0x170) != 0 || (*(char *)(param_1 + 0x688) != '\0')) ||
      (uVar6 = CheckResetQueue(param_1), (char)uVar6 == '\0')))) {
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    StorPortResume(param_1);
  }
  **(int **)(param_1 + 0x40) = param_2 * 2;
  LOCK();
  UNLOCK();
LAB_1c0008032:
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    CleanUpIoctl(param_1);
  }
  else {
    *(undefined2 *)(lVar12 + 3) = 1;
    StorPortNotification(0,param_1,lVar12);
    *(undefined1 *)(param_1 + 0x6a1) = 0;
    *(undefined8 *)(param_1 + 0x6a8) = 0;
  }
  CheckIoctlQueue(param_1);
  return 1;
}



===== CheckInqFlagReplies @ 1c0008094 =====

ulonglong CheckInqFlagReplies(longlong param_1,uint param_2,uint *param_3)

{
  char cVar1;
  ushort uVar2;
  longlong lVar3;
  int *piVar4;
  bool bVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  int *piVar10;
  longlong lVar11;
  int *piVar12;
  int *piVar13;
  byte bVar14;
  ushort uVar15;
  ulonglong uVar16;
  uint uVar17;
  char *pcVar18;
  bool bVar19;
  bool bVar20;
  undefined1 local_res20;
  uint in_stack_ffffffffffffff88;
  
  piVar10 = (int *)(ulonglong)param_2;
  pcVar18 = (char *)0x0;
  if ((param_2 & 0xe0000000) == 0) {
    if ((param_2 >> 0x19 & 1) == 0) goto LAB_1c00080de;
    bVar5 = true;
    uVar17 = param_2;
  }
  else {
    piVar10 = *(int **)(param_1 + 0x58);
    pcVar18 = (char *)((longlong)piVar10 + (ulonglong)(param_2 & 0x7fffffff) * 2);
    if ((*(uint *)(pcVar18 + 8) >> 0x19 & 1) == 0) goto LAB_1c00080de;
    bVar5 = false;
    uVar17 = *(uint *)(pcVar18 + 8);
  }
  lVar3 = *(longlong *)(param_1 + 0x148);
  uVar17 = uVar17 & 0xfdffffff;
  *param_3 = uVar17;
  lVar3 = *(longlong *)(lVar3 + 8 + (ulonglong)uVar17 * 0x18);
  if (lVar3 == 0) {
    uVar8 = StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff88 & 0xffffff00,6,0xad010024);
    return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  piVar4 = *(int **)(lVar3 + 0x38);
  cVar1 = (char)piVar4[0x54];
  local_res20 = 1;
  puVar9 = (undefined1 *)
           StorPortGetLogicalUnit
                     (param_1,*(undefined1 *)(lVar3 + 5),*(undefined1 *)(lVar3 + 6),
                      *(undefined1 *)(lVar3 + 7));
  uVar2 = *(ushort *)(param_1 + 0x134);
  piVar13 = *(int **)(lVar3 + 0x18);
  uVar15 = uVar2 & 0x2100;
  uVar16 = (ulonglong)uVar15;
  bVar19 = uVar15 == 0x2100;
  if (cVar1 == '\x12') {
    if (puVar9 != (undefined1 *)0x0) {
      if (bVar19) {
        *puVar9 = 0;
      }
      puVar9[1] = 0;
    }
    if (!bVar5) {
      uVar15 = *(ushort *)(pcVar18 + 0xe);
      piVar10 = (int *)(ulonglong)uVar15;
      uVar8 = CONCAT71(0x21,pcVar18[0xc]);
      if (uVar15 == 0x45) {
        uVar6 = (int)uVar8 - 8;
        piVar10 = (int *)(ulonglong)uVar6;
        if (((uVar6 & 0xdf) != 0) &&
           (piVar10 = (int *)(ulonglong)CONCAT31((int3)(uVar6 >> 8),pcVar18[0xd]),
           (pcVar18[0xd] & 1U) == 0)) {
          *(undefined4 *)(lVar3 + 0x10) = *(undefined4 *)(pcVar18 + 0x14);
          local_res20 = 0x12;
          goto LAB_1c0008230;
        }
      }
      else {
        uVar16 = 0xffbf;
        if (((uVar15 & 0xffbf) == 0) && (pcVar18[0xc] == '\0')) goto LAB_1c0008230;
      }
LAB_1c0008431:
      piVar4[0x50] = uVar17;
      *(uint *)(pcVar18 + 8) = uVar17;
LAB_1c00080de:
      return (ulonglong)piVar10 & 0xffffffffffffff00;
    }
    uVar8 = 0;
LAB_1c0008230:
    *(char *)(lVar3 + 4) = (char)uVar8;
    *(undefined1 *)(lVar3 + 3) = local_res20;
    uVar7 = *(undefined4 *)(param_1 + 0x1cc);
    if ((*(ushort *)(param_1 + 0x134) & 0x200) != 0) {
      lVar11 = FindSasAddressTableEntry(param_1,*(char *)(lVar3 + 5),*(char *)(lVar3 + 6),0x80);
      uVar16 = 0;
      if (lVar11 != 0) {
        uVar7 = *(undefined4 *)(param_1 + 0x1d0);
      }
    }
    StorPortSetDeviceQueueDepth
              (param_1,CONCAT71((int7)(uVar16 >> 8),*(undefined1 *)(lVar3 + 5)),
               *(undefined1 *)(lVar3 + 6),*(undefined1 *)(lVar3 + 7),uVar7);
    bVar20 = piVar13 != (int *)0x0;
    piVar10 = piVar13;
    if (puVar9 == (undefined1 *)0x0) {
LAB_1c0008428:
      if (!bVar5) goto LAB_1c0008431;
    }
    else {
      if (bVar20 && (uVar2 & 0x4200) == 0x4200) {
        if (0x10 < *(uint *)(lVar3 + 0x10)) {
          piVar12 = (int *)FindSasAddressTableEntry
                                     (param_1,*(char *)(lVar3 + 5),*(char *)(lVar3 + 6),0x680);
          piVar10 = piVar12;
          if (((piVar12 != (int *)0x0) && ((piVar12[3] & 0x40000000U) == 0)) &&
             ((char)*piVar13 == '\x01')) {
            bVar14 = 0;
            do {
              piVar10 = (int *)CONCAT71(0x1c00171,(&vendorHP)[bVar14]);
              if (*(char *)((ulonglong)bVar14 + 8 + (longlong)piVar13) != (&vendorHP)[bVar14])
              break;
              bVar14 = bVar14 + 1;
            } while (bVar14 < 8);
            if (7 < bVar14) {
              piVar12[3] = piVar12[3] | 0x40000000;
              *(undefined1 *)(piVar4 + 0x4f) = 6;
              piVar4[0x54] = 0;
              piVar4[0x55] = 0;
              piVar4[0x56] = 0;
              piVar4[0x57] = 0;
              piVar4[0x5a] = piVar4[0x5a] & 0xff000000;
              *(undefined2 *)(piVar4 + 0x54) = 0x1c2;
              piVar4[0x58] = 0;
              piVar13 = *(int **)(param_1 + 0x38);
              *piVar13 = *piVar4;
              LOCK();
              UNLOCK();
              *param_3 = 0xffffffff;
              goto LAB_1c00084e0;
            }
          }
          goto LAB_1c0008428;
        }
      }
      else if (!bVar20 || !bVar19) goto LAB_1c0008428;
      if (((bVar20 && bVar19) && (5 < *(uint *)(lVar3 + 0x10))) &&
         ((*(byte *)((longlong)piVar13 + 5) & 1) != 0)) {
        *(undefined1 *)(piVar4 + 0x4f) = 0x10;
        piVar4[0x54] = 0;
        piVar4[0x55] = 0;
        piVar4[0x56] = 0;
        piVar4[0x57] = 0;
        *(undefined2 *)(piVar4 + 0x54) = 0x109e;
        *(undefined1 *)((longlong)piVar4 + 0x15d) = 0xe;
        memcpy(puVar9 + 2,*(void **)(lVar3 + 0x18),0xe);
        piVar4[0x58] = 0xe;
        piVar4[0x5a] = piVar4[0x5a] & 0xff00000eU | 0xe;
        piVar13 = *(int **)(param_1 + 0x38);
        *piVar13 = *piVar4;
        LOCK();
        UNLOCK();
        *param_3 = 0xffffffff;
        goto LAB_1c00084e0;
      }
    }
LAB_1c00084c6:
    piVar13 = (int *)StorPortNotification(0,param_1,lVar3);
LAB_1c00084e0:
    if (bVar5) goto LAB_1c00084f9;
  }
  else {
    if (cVar1 != -0x62) {
      if (cVar1 == -0x3e) {
        if (!bVar5) {
          puVar9[1] = puVar9[1] + '\x01';
          if ((byte)puVar9[1] < 2) goto LAB_1c0008456;
          StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff88 & 0xffffff00,6,0xad010033);
        }
        goto LAB_1c00084c6;
      }
      *param_3 = uVar17;
      goto LAB_1c00084e0;
    }
    if (bVar5) {
      if ((*(byte *)(piVar13 + 3) & 1) != 0) {
        *puVar9 = 1;
      }
LAB_1c0008475:
      memcpy(*(void **)(lVar3 + 0x18),puVar9 + 2,0xe);
      goto LAB_1c00084c6;
    }
    puVar9[1] = puVar9[1] + '\x01';
    if (3 < (byte)puVar9[1]) goto LAB_1c0008475;
LAB_1c0008456:
    **(int **)(param_1 + 0x38) = *piVar4;
    LOCK();
    UNLOCK();
    *param_3 = 0xffffffff;
  }
  piVar13 = *(int **)(param_1 + 0x40);
  *piVar13 = param_2 * 2;
  LOCK();
  UNLOCK();
LAB_1c00084f9:
  return CONCAT71((int7)((ulonglong)piVar13 >> 8),1);
}



===== DelayedIoctlTimeout @ 1c0008520 =====

void DelayedIoctlTimeout(longlong param_1)

{
  *(undefined1 *)(param_1 + 0x688) = 1;
  KickStart(param_1);
  *(undefined1 *)(param_1 + 0x681) = 0;
                    /* WARNING: Could not recover jumptable at 0x0001c0008556. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(6,param_1,WatchdogTimer,1000000);
  return;
}



===== MPIOCompatibility @ 1c0008560 =====

void MPIOCompatibility(longlong param_1)

{
  undefined1 *_Dst;
  int iVar1;
  bool bVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint *puVar7;
  uint uVar8;
  longlong lVar9;
  
  _Dst = (undefined1 *)(param_1 + 0x200);
  if (*(char *)(param_1 + 0x660) == '\x01') {
    uVar8 = 0x5000000;
  }
  else {
    uVar8 = 0;
    if (*(char *)(param_1 + 0x660) == '\x02') {
      uVar8 = 0xd000000;
    }
  }
  memset(_Dst,0,0x28);
  *(undefined8 *)(param_1 + 0x280) = 0;
  *(undefined8 *)(param_1 + 0x288) = 0;
  *(undefined8 *)(param_1 + 0x290) = 0;
  *_Dst = 0;
  *(undefined1 *)(param_1 + 0x203) = 4;
  *(undefined2 *)(param_1 + 0x216) = 0x501;
  *(undefined4 *)(param_1 + 0x21c) = 0xd1000000;
  lVar9 = *(longlong *)(param_1 + 0x188);
  iVar1 = *(int *)(param_1 + 0x58);
  bVar2 = SendMessageViaHandShake(param_1,0,10);
  if (((bVar2) && (lVar4 = ReceiveDataViaHandshake(param_1,0xc), (char)lVar4 != '\0')) &&
     (*(short *)(param_1 + 0x28e) == 0)) {
    *_Dst = 1;
    *(undefined4 *)(param_1 + 0x214) = *(undefined4 *)(param_1 + 0x294);
    *(int *)(param_1 + 0x220) = (int)lVar9 - iVar1;
    *(uint *)(param_1 + 0x21c) = *(uint *)(param_1 + 0x21c) | (uint)*(byte *)(param_1 + 0x215) << 2;
    bVar2 = SendMessageViaHandShake(param_1,0,10);
    if (((bVar2) && (lVar4 = ReceiveDataViaHandshake(param_1,0xc), (char)lVar4 != '\0')) &&
       ((*(short *)(param_1 + 0x28e) == 0 && ((*(uint *)(lVar9 + 4) & 0xd000000) != uVar8)))) {
      uVar3 = ~uVar8 & *(uint *)(lVar9 + 4);
      *(uint *)(lVar9 + 4) = uVar3;
      if (uVar8 != 0) {
        *(uint *)(lVar9 + 4) = uVar3 | uVar8;
      }
      *_Dst = 4;
      *(uint *)(param_1 + 0x21c) = (uint)*(byte *)(param_1 + 0x215) << 2 | 0xd5000000;
      bVar2 = SendMessageViaHandShake(param_1,0,10);
      if (bVar2) {
        ReceiveDataViaHandshake(param_1,0xc);
        *_Dst = 2;
        bVar2 = SendMessageViaHandShake(param_1,0,10);
        if (bVar2) {
          ReceiveDataViaHandshake(param_1,0xc);
          *_Dst = 1;
          *(uint *)(param_1 + 0x21c) = (uint)*(byte *)(param_1 + 0x215) << 2 | 0xd1000000;
          bVar2 = SendMessageViaHandShake(param_1,0,10);
          if (bVar2) {
            ReceiveDataViaHandshake(param_1,0xc);
          }
        }
      }
    }
  }
  if ((**(uint **)(param_1 + 0x10) >> 0x1b & 1) != 0) {
    KickStart(param_1);
  }
  puVar7 = *(uint **)(param_1 + 0x10);
  uVar8 = 0;
  while( true ) {
    uVar3 = *puVar7 & 0xf0000000;
    if (uVar3 == 0x10000000) {
      return;
    }
    if (uVar3 == 0x20000000) {
      **(undefined4 **)(param_1 + 0x10) = 0x40000000;
      LOCK();
      UNLOCK();
      SymWaitForResponse(param_1);
    }
    else if (uVar3 != 0) {
      **(undefined4 **)(param_1 + 0x10) = 0x41000000;
      LOCK();
      UNLOCK();
      uVar5 = SymWaitForResponse(param_1);
      if (((char)uVar5 == '\0') && (uVar6 = KickStart(param_1), (char)uVar6 == '\0')) {
        return;
      }
    }
    lVar9 = 100;
    do {
      StorPortStallExecution(1000);
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    if (100 < uVar8) break;
    puVar7 = *(uint **)(param_1 + 0x10);
    uVar8 = uVar8 + 1;
  }
  StorPortLogError(param_1,0,0,0,0,6,0xad010003);
  return;
}



===== TestFWUploadNeeded @ 1c0008804 =====

void TestFWUploadNeeded(longlong param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1fc);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    IssueIOCFacts(param_1);
    if (*(int *)(param_1 + 0x1fc) != 0) {
      *(ushort *)(param_1 + 0x134) = *(ushort *)(param_1 + 0x134) | 0x40;
    }
    *(int *)(param_1 + 0x1fc) = iVar1;
  }
  return;
}



===== ReadAndSetSASPages @ 1c000884c =====

void ReadAndSetSASPages(longlong param_1)

{
  uint *puVar1;
  undefined8 *puVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined2 uVar6;
  undefined8 uVar7;
  char cVar8;
  ushort uVar9;
  undefined4 *puVar10;
  byte bVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint local_res8 [2];
  uint local_res10;
  undefined8 local_res18;
  longlong local_res20;
  ulonglong in_stack_ffffffffffffff98;
  
  bVar11 = 1;
  local_res20 = 0;
  bVar4 = true;
  local_res18 = 0;
  bVar3 = false;
  uVar14 = local_res10;
  uVar13 = local_res8[0];
  do {
    bVar5 = true;
    if (bVar11 < 0x46) {
      uVar6 = local_res18._6_2_;
      if (bVar11 == 0x45) {
        if (*(longlong *)(param_1 + 0x12e8) == 0) {
          uVar9 = *(short *)(param_1 + 0x12a2) << 2;
          if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
          *(longlong *)(param_1 + 0x12e8) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
        }
        bVar11 = 0x50;
        local_res18._0_6_ = CONCAT42(0xf00,(undefined2)local_res18);
        local_res18._0_7_ = CONCAT16(0x15,(undefined6)local_res18);
LAB_1c0008b97:
        local_res18 = local_res18 & 0xffffffffffffff00;
        cVar8 = '\0';
        in_stack_ffffffffffffff98 = 0;
        pcVar12 = (char *)&local_res18;
        uVar15 = 0;
LAB_1c0008ba9:
        SendExtendedConfigPageMessage(param_1,cVar8,pcVar12,uVar15,(int)in_stack_ffffffffffffff98);
        goto LAB_1c000919e;
      }
      if (bVar11 < 0x11) {
        if (bVar11 == 0x10) {
          bVar11 = 0x11;
          local_res8[0] = 0x1020000;
          *(undefined4 *)(param_1 + 0xde8) = *(undefined4 *)(*(longlong *)(param_1 + 0xd90) + 4);
          *(undefined4 *)(param_1 + 0xdec) = *(undefined4 *)(*(longlong *)(param_1 + 0xd90) + 8);
        }
        else if (bVar11 < 8) {
          if (bVar11 == 7) {
            bVar11 = 8;
            local_res8[0] = 0x20000;
          }
          else {
            if (bVar11 == 1) {
              bVar11 = 2;
LAB_1c0008978:
              bVar4 = true;
              goto LAB_1c000919b;
            }
            if (bVar11 == 2) {
              local_res8[0] = 0x1010000;
              bVar11 = 3;
            }
            else {
              if (bVar11 == 3) {
                bVar11 = 4;
LAB_1c000892d:
                local_res8[0] = *(uint *)(param_1 + 0xd98);
                in_stack_ffffffffffffff98 = *(ulonglong *)(param_1 + 0xd90);
                goto LAB_1c000893d;
              }
              if (bVar11 != 4) {
                if (bVar11 == 5) {
                  bVar11 = 6;
                  goto LAB_1c000892d;
                }
                if (bVar11 != 6) goto LAB_1c0008fd1;
                bVar11 = 7;
                local_res8[0] = *(uint *)(param_1 + 0xd98);
                if (*(char *)(param_1 + 0x679) == '\0') {
                  puVar1 = (uint *)(*(longlong *)(param_1 + 0xd90) + 4);
                  *puVar1 = *puVar1 | 0x20;
                }
                else {
                  puVar1 = (uint *)(*(longlong *)(param_1 + 0xd90) + 4);
                  *puVar1 = *puVar1 & 0xffffffdf;
                }
                in_stack_ffffffffffffff98 = *(ulonglong *)(param_1 + 0xd90);
                cVar8 = '\x02';
                goto LAB_1c00089a5;
              }
              bVar11 = *(byte *)(*(longlong *)(param_1 + 0xd90) + 0xd);
              if (bVar11 == 0xff) {
                *(undefined2 *)(param_1 + 0xf42) = 0xffff;
              }
              else {
                *(ushort *)(param_1 + 0xf42) = (ushort)bVar11;
              }
              if ((*(uint *)(param_1 + 0x67c) & 4) == 0) {
                bVar11 = 7;
                goto LAB_1c0008978;
              }
              bVar11 = 5;
              local_res8[0] = 0x10000;
            }
          }
        }
        else {
          if (bVar11 == 8) {
            bVar11 = 0x60;
            goto LAB_1c000892d;
          }
          if (bVar11 != 9) {
            if (bVar11 == 10) {
              local_res8[0] = *(uint *)(param_1 + 0xd98);
              if (*(longlong *)(param_1 + 0xdc0) == 0) {
                uVar9 = ((ushort)(local_res8[0] >> 8) & 0xff) << 2;
                if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
                *(longlong *)(param_1 + 0xdc0) = *(longlong *)(param_1 + 0xd90);
                *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
                *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
              }
              in_stack_ffffffffffffff98 = *(ulonglong *)(param_1 + 0xdc0);
              bVar11 = 0xb;
            }
            else {
              if (bVar11 == 0xb) {
                if (*(short *)(param_1 + 0xd64) != 0x23) {
                  memcpy((void *)(param_1 + 0x116c),(void *)(*(longlong *)(param_1 + 0xdc0) + 0x3c),
                         0x10);
                }
                bVar11 = 0xc;
                local_res8[0] = 0x9050000;
                goto LAB_1c000899b;
              }
              if (bVar11 != 0xc) goto LAB_1c0008fd1;
              local_res8[0] = *(uint *)(param_1 + 0xd98);
              bVar11 = 0x10;
              in_stack_ffffffffffffff98 = *(ulonglong *)(param_1 + 0xd90);
            }
            cVar8 = '\x06';
            goto LAB_1c00089a5;
          }
          bVar11 = 10;
          local_res8[0] = 0x9000000;
        }
LAB_1c000899b:
        in_stack_ffffffffffffff98 = 0;
        cVar8 = '\0';
LAB_1c00089a5:
        SendConfigPageMessage(param_1,cVar8,local_res8,0,(int)in_stack_ffffffffffffff98);
        goto LAB_1c000919e;
      }
      if (0x22 < bVar11) {
        if (bVar11 != 0x23) {
          if (bVar11 == 0x30) {
            if (*(longlong *)(param_1 + 0x12c8) == 0) {
              uVar9 = *(short *)(param_1 + 0x1282) << 2;
              if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
              *(longlong *)(param_1 + 0x12c8) = *(longlong *)(param_1 + 0xd90);
              *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
              *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
            }
            bVar11 = 0x31;
            local_res18._0_6_ = CONCAT42(0xf00,(undefined2)local_res18);
          }
          else {
            if (bVar11 != 0x31) {
              if (bVar11 == 0x40) {
                if (*(longlong *)(param_1 + 0x12d8) == 0) {
                  uVar9 = *(short *)(param_1 + 0x1292) << 2;
                  if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
                  *(longlong *)(param_1 + 0x12d8) = *(longlong *)(param_1 + 0xd90);
                  *(ulonglong *)(param_1 + 0xd90) =
                       (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
                  *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
                }
                bVar11 = 0x41;
                local_res18._0_6_ = CONCAT42(0xf00,(undefined2)local_res18);
              }
              else {
                if (bVar11 != 0x41) {
LAB_1c0008fd1:
                  bVar11 = 0;
                  bVar4 = false;
                  goto LAB_1c000919e;
                }
                if (*(longlong *)(param_1 + 0x12e0) == 0) {
                  uVar9 = *(short *)(param_1 + 0x129a) << 2;
                  if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
                  *(longlong *)(param_1 + 0x12e0) = *(longlong *)(param_1 + 0xd90);
                  *(ulonglong *)(param_1 + 0xd90) =
                       (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
                  *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
                }
                bVar11 = 0x45;
                local_res18._0_6_ = CONCAT42(0xf01,(undefined2)local_res18);
              }
              local_res18._0_7_ = CONCAT16(0x13,(undefined6)local_res18);
              goto LAB_1c0008b97;
            }
            if (*(longlong *)(param_1 + 0x12d0) == 0) {
              uVar9 = *(short *)(param_1 + 0x128a) << 2;
              if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
              *(longlong *)(param_1 + 0x12d0) = *(longlong *)(param_1 + 0xd90);
              *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
              *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
            }
            bVar11 = 0x40;
            local_res18._0_6_ = CONCAT42(0xf01,(undefined2)local_res18);
          }
          local_res18._0_7_ = CONCAT16(0x12,(undefined6)local_res18);
          goto LAB_1c0008b97;
        }
        if (*(longlong *)(param_1 + 0x12c0) == 0) {
          uVar9 = *(short *)(param_1 + 0x127a) << 2;
          if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
          *(longlong *)(param_1 + 0x12c0) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
        }
        bVar11 = 0x30;
        local_res18._0_6_ = CONCAT42(0xf03,(undefined2)local_res18);
        local_res18 = CONCAT26(uVar6,(undefined6)local_res18);
LAB_1c0008b93:
        local_res18._0_7_ = CONCAT16(0x10,(undefined6)local_res18);
        goto LAB_1c0008b97;
      }
      if (bVar11 != 0x22) {
        if (bVar11 != 0x11) {
          if (bVar11 == 0x12) {
            bVar4 = true;
            bVar5 = false;
            if ((*(uint *)(*(longlong *)(param_1 + 0xe50) + 4) & 0x7f) == 0) {
              bVar11 = 0x20;
            }
            else {
              bVar11 = 0x13;
              *(ushort *)(param_1 + 0x134) = *(ushort *)(param_1 + 0x134) | 0x8000;
            }
            goto LAB_1c000919e;
          }
          if (bVar11 == 0x13) {
            if (*(longlong *)(param_1 + 0x12f8) == 0) {
              uVar9 = (*(byte *)(*(longlong *)(param_1 + 0xe50) + 0xb) + 10) * 4;
              if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
              *(longlong *)(param_1 + 0x12f8) = *(longlong *)(param_1 + 0xd90);
              *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
              *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
            }
            local_res8[0] = 0xa000000;
            bVar11 = 0x14;
            goto LAB_1c000899b;
          }
          if (bVar11 == 0x14) {
            local_res8[0] = *(uint *)(param_1 + 0xd98);
            *(uint *)(param_1 + 0x1261) = local_res8[0];
            if (*(longlong *)(param_1 + 0x1300) == 0) {
              uVar9 = ((ushort)(local_res8[0] >> 8) & 0xff) << 2;
              if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
              *(longlong *)(param_1 + 0x1300) = *(longlong *)(param_1 + 0xd90);
              *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
              *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
            }
            bVar4 = true;
            bVar11 = 0x20;
            goto LAB_1c000919b;
          }
          if (bVar11 == 0x20) {
            bVar11 = 0x21;
            local_res18._0_6_ = CONCAT42(0xf00,(undefined2)local_res18);
            local_res18 = CONCAT26(uVar6,(undefined6)local_res18);
          }
          else {
            if (bVar11 != 0x21) goto LAB_1c0008fd1;
            if (*(longlong *)(param_1 + 0x12b0) == 0) {
              uVar9 = *(short *)(param_1 + 0x126a) << 2;
              if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
              *(longlong *)(param_1 + 0x12b0) = *(longlong *)(param_1 + 0xd90);
              *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
              *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
            }
            bVar11 = 0x22;
            local_res18._0_6_ = CONCAT42(0xf01,(undefined2)local_res18);
            local_res18 = CONCAT26(uVar6,(undefined6)local_res18);
          }
          goto LAB_1c0008b93;
        }
        local_res8[0] = *(uint *)(param_1 + 0xd98);
        if (*(longlong *)(param_1 + 0xe50) == 0) {
          if (*(uint *)(param_1 + 0xd8c) < 0x24) goto LAB_1c0008a6c;
          *(longlong *)(param_1 + 0xe50) = *(longlong *)(param_1 + 0xd90);
          *(longlong *)(param_1 + 0xd90) = *(longlong *)(param_1 + 0xd90) + 0x24;
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - 0x24;
        }
        in_stack_ffffffffffffff98 = *(ulonglong *)(param_1 + 0xe50);
        bVar11 = 0x12;
LAB_1c000893d:
        cVar8 = '\x01';
        goto LAB_1c00089a5;
      }
      if (*(longlong *)(param_1 + 0x12b8) != 0) {
LAB_1c0008d4e:
        bVar11 = 0x23;
        local_res18._0_6_ = CONCAT42(0xf02,(undefined2)local_res18);
        local_res18 = CONCAT26(uVar6,(undefined6)local_res18);
        goto LAB_1c0008b93;
      }
      uVar9 = *(short *)(param_1 + 0x1272) << 2;
      if ((uint)uVar9 <= *(uint *)(param_1 + 0xd8c)) {
        *(longlong *)(param_1 + 0x12b8) = *(longlong *)(param_1 + 0xd90);
        *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
        *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
        goto LAB_1c0008d4e;
      }
LAB_1c0008a6c:
      bVar3 = true;
LAB_1c00091a3:
      bVar4 = false;
      bVar11 = 0;
    }
    else {
      if (bVar11 == 0x50) {
        if (*(longlong *)(param_1 + 0x12f0) == 0) {
          uVar9 = *(short *)(param_1 + 0x12aa) << 2;
          if (*(uint *)(param_1 + 0xd8c) < (uint)uVar9) goto LAB_1c0008a6c;
          *(longlong *)(param_1 + 0x12f0) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar9 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar9;
        }
        uVar14 = 0xffff;
        uVar15 = *(int *)(param_1 + 0x1350) << 4;
        local_res10 = 0xffff;
        uVar13 = 0;
        if (uVar15 != 0) {
          memset(*(void **)(param_1 + 0x1348),0,(ulonglong)uVar15);
        }
LAB_1c0009198:
        bVar11 = 0x51;
LAB_1c000919b:
        bVar5 = false;
      }
      else {
        if (bVar11 == 0x51) {
          in_stack_ffffffffffffff98 = *(ulonglong *)(param_1 + 0x12d0);
          pcVar12 = (char *)(param_1 + 0x1286);
          bVar11 = 0x52;
          cVar8 = '\x01';
          uVar15 = uVar14;
          goto LAB_1c0008ba9;
        }
        if (bVar11 == 0x52) {
          bVar11 = 0x53;
          if (*(short *)(param_1 + 0xd64) == 0x22) {
            bVar11 = 0xf0;
            goto LAB_1c000919b;
          }
          bVar5 = false;
          if (uVar13 == *(uint *)(param_1 + 0x1350)) {
            bVar11 = 0xf0;
          }
          else {
            local_res20 = *(longlong *)(param_1 + 0x12d0);
            puVar10 = (undefined4 *)((ulonglong)uVar13 * 0x10 + *(longlong *)(param_1 + 0x1348));
            uVar13 = uVar13 + 1;
            puVar10[3] = *(uint *)(local_res20 + 0x1c) & 0xffff;
            *(undefined1 *)(puVar10 + 2) = *(undefined1 *)(local_res20 + 0x1b);
            *(undefined1 *)((longlong)puVar10 + 9) = *(undefined1 *)(local_res20 + 0x1a);
            *(undefined2 *)((longlong)puVar10 + 10) = *(undefined2 *)(local_res20 + 0x18);
            *puVar10 = *(undefined4 *)(local_res20 + 0xc);
            puVar10[1] = *(undefined4 *)(local_res20 + 0x10);
          }
        }
        else {
          if (bVar11 == 0x53) {
            uVar14 = (uint)*(ushort *)(local_res20 + 0x18);
            local_res10 = uVar14;
            goto LAB_1c0009198;
          }
          if (bVar11 != 0x60) goto LAB_1c0008fd1;
          bVar11 = 9;
          bVar5 = false;
          *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(*(longlong *)(param_1 + 0xd90) + 8);
          if (*(char *)(param_1 + 0x680) != '\0') {
            if ((*(ushort *)(param_1 + 0x134) & 0x1000) == 0) {
              puVar2 = *(undefined8 **)(param_1 + 0xd68);
              *puVar2 = 0;
              puVar2[1] = 0;
              puVar2[2] = 0;
              puVar2[3] = 0;
              *(undefined1 *)puVar2 = 1;
              *(undefined1 *)((longlong)puVar2 + 3) = 0x1b;
              *(undefined4 *)(puVar2 + 1) = 9;
              **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
              LOCK();
              UNLOCK();
              bVar5 = true;
            }
            else {
              in_stack_ffffffffffffff98 = in_stack_ffffffffffffff98 & 0xffffffffffffff00;
              StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff98,6,0xad01002d);
            }
          }
        }
      }
LAB_1c000919e:
      if (bVar3) goto LAB_1c00091a3;
    }
    *(byte *)(param_1 + 0x6a0) = bVar11;
    if (!bVar4) {
      return;
    }
    if (bVar5) {
      uVar15 = 0;
      do {
        uVar7 = LSImpiMSIIsr(param_1);
        if ((char)uVar7 != '\0') break;
        StorPortStallExecution(500);
        uVar15 = uVar15 + 1;
      } while (uVar15 < 20000);
      uVar14 = local_res10;
      if ((uVar15 == 20000) || (bVar11 == 0)) {
        bVar4 = false;
      }
    }
    if (!bVar4) {
      return;
    }
  } while( true );
}



===== SendConfigPageMessage @ 1c000922c =====

void SendConfigPageMessage
               (longlong param_1,char param_2,undefined4 *param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  char *_Dst;
  uint uVar2;
  int iVar3;
  
  if (param_4 == -0x43514352) {
    _Dst = *(char **)(param_1 + 0xd78);
    param_4 = 0;
    iVar3 = *(int *)(param_1 + 0xd88);
    uVar2 = 0xbcaec;
  }
  else {
    _Dst = *(char **)(param_1 + 0xd68);
    uVar2 = *(byte *)(param_1 + 0xd62) | 0x10000000;
    iVar3 = *(int *)(param_1 + 0xd80);
  }
  memset(_Dst,0,0x28);
  *_Dst = param_2;
  _Dst[3] = '\x04';
  *(uint *)(_Dst + 8) = uVar2;
  uVar1 = *param_3;
  _Dst[0x1c] = '\0';
  _Dst[0x1d] = '\0';
  _Dst[0x1e] = '\0';
  _Dst[0x1f] = -0x2f;
  *(undefined4 *)(_Dst + 0x14) = uVar1;
  *(int *)(_Dst + 0x18) = param_4;
  if (param_2 == '\0') {
    *(int *)(_Dst + 0x20) = iVar3 + 0x28;
  }
  else {
    *(int *)(_Dst + 0x20) = param_5 - *(int *)(param_1 + 0x58);
    uVar2 = (uint)*(byte *)((longlong)param_3 + 1) << 2;
    *(uint *)(_Dst + 0x1c) = uVar2 | 0xd1000000;
    if (param_2 == '\x02') {
      *(uint *)(_Dst + 0x1c) = uVar2 | 0xd5000000;
    }
  }
  **(int **)(param_1 + 0x38) = iVar3;
  LOCK();
  UNLOCK();
  return;
}



===== SendExtendedConfigPageMessage @ 1c0009314 =====

void SendExtendedConfigPageMessage
               (longlong param_1,char param_2,char *param_3,undefined4 param_4,int param_5)

{
  ushort uVar1;
  char *_Dst;
  
  _Dst = *(char **)(param_1 + 0xd68);
  memset(_Dst,0,0x28);
  *_Dst = param_2;
  _Dst[3] = '\x04';
  *(uint *)(_Dst + 8) = *(byte *)(param_1 + 0x6a0) | 0x10000000;
  _Dst[0x14] = *param_3;
  _Dst[0x16] = param_3[2];
  _Dst[0x17] = param_3[3];
  *(undefined2 *)(_Dst + 4) = *(undefined2 *)(param_3 + 4);
  _Dst[6] = param_3[6];
  *(undefined4 *)(_Dst + 0x18) = param_4;
  _Dst[0x1c] = '\0';
  _Dst[0x1d] = '\0';
  _Dst[0x1e] = '\0';
  _Dst[0x1f] = -0x2f;
  if (param_2 == '\0') {
    *(int *)(_Dst + 0x20) = *(int *)(param_1 + 0xd80) + 0x28;
  }
  else {
    *(int *)(_Dst + 0x20) = param_5 - *(int *)(param_1 + 0x58);
    uVar1 = *(ushort *)(param_3 + 4);
    *(uint *)(_Dst + 0x1c) = (uint)uVar1 << 2 | 0xd1000000;
    if (param_2 == '\x02') {
      *(uint *)(_Dst + 0x1c) = (uint)uVar1 << 2 | 0xd5000000;
    }
  }
  **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
  LOCK();
  UNLOCK();
  return;
}



===== ReadFcPortPages @ 1c00093f8 =====

char ReadFcPortPages(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  undefined8 uVar4;
  char cVar5;
  ushort uVar6;
  byte bVar7;
  undefined4 *puVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  char local_res8;
  undefined4 local_res10 [2];
  uint local_res18;
  ulonglong in_stack_ffffffffffffffa8;
  
  bVar7 = 1;
  bVar3 = false;
  local_res8 = '\0';
  uVar11 = 1;
  do {
    bVar10 = (byte)uVar11;
    if (bVar7 < 0x41) {
      if (bVar7 == 0x40) {
        local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
        bVar7 = 0x41;
        in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xd90);
LAB_1c0009658:
        cVar5 = '\x06';
LAB_1c00098ea:
        iVar9 = 0;
      }
      else {
        if (bVar7 == 1) {
          bVar7 = 8;
          local_res10[0] = 0x1010000;
          goto LAB_1c00098e3;
        }
        if (bVar7 == 8) {
          local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
          bVar7 = 9;
          in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xd90);
          goto LAB_1c00094f0;
        }
        if (bVar7 == 9) {
          lVar1 = *(longlong *)(param_1 + 0xd90);
          if (*(byte *)(lVar1 + 0xd) == 0xff) {
            uVar6 = 0xffff;
          }
          else {
            uVar6 = (ushort)*(byte *)(lVar1 + 0xd);
          }
          iVar9 = *(int *)(param_1 + 0x2dc);
          *(ushort *)(param_1 + 0xf42) = uVar6;
          cVar5 = *(char *)(param_1 + 0x2d8);
          if (iVar9 != -1) {
            *(int *)(lVar1 + 8) = iVar9;
          }
          if (cVar5 != -1) {
            *(char *)(lVar1 + 0xc) = cVar5;
          }
          if ((iVar9 == 0) && (cVar5 == '\x01')) {
            *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xfffffffe;
          }
          else {
            *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | 1;
          }
          if ((*(char *)(param_1 + 0x66c) != '\0') && ((*(uint *)(lVar1 + 4) & 0x1000000) != 0)) {
            *(ushort *)(param_1 + 0x134) = *(ushort *)(param_1 + 0x134) | 0x2000;
          }
          local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
          bVar7 = 10;
          cVar5 = '\x02';
          in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xd90);
          goto LAB_1c00098ea;
        }
        if (bVar7 == 10) {
          bVar7 = 0x20;
          local_res10[0] = 0x5000000;
          goto LAB_1c00098e3;
        }
        if (bVar7 == 0x20) {
          local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
          *(undefined4 *)(param_1 + 0xda4) = local_res10[0];
          if (*(longlong *)(param_1 + 0xdb8) == 0) {
            uVar6 = ((ushort)((uint)local_res10[0] >> 8) & 0xff) << 2;
            if (*(uint *)(param_1 + 0xd8c) < (uint)uVar6) goto LAB_1c000954a;
            *(longlong *)(param_1 + 0xdb8) = *(longlong *)(param_1 + 0xd90);
            *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar6 + *(longlong *)(param_1 + 0xd90);
            *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar6;
          }
          in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xdb8);
          bVar7 = 0x21;
LAB_1c00094f0:
          cVar5 = '\x01';
          goto LAB_1c00098ea;
        }
        if (bVar7 != 0x21) {
          if (bVar7 != 0x32) {
            if (bVar7 != 0x33) goto LAB_1c00096a4;
            bVar7 = 0x48;
            local_res10[0] = 0x9000000;
            goto LAB_1c00098e3;
          }
          local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
          *(undefined4 *)(param_1 + 0xda8) = local_res10[0];
          if (*(longlong *)(param_1 + 0xdc8) == 0) {
            uVar6 = ((ushort)((uint)local_res10[0] >> 8) & 0xff) << 2;
            if (*(uint *)(param_1 + 0xd8c) < (uint)uVar6) goto LAB_1c000954a;
            *(longlong *)(param_1 + 0xdc8) = *(longlong *)(param_1 + 0xd90);
            *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar6 + *(longlong *)(param_1 + 0xd90);
            *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar6;
          }
          in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xdc8);
          bVar7 = 0x33;
          goto LAB_1c00094f0;
        }
        bVar7 = 0x32;
        local_res10[0] = 0x5030000;
        in_stack_ffffffffffffffa8 = 0;
        iVar9 = 0x1000000;
        cVar5 = '\0';
      }
      puVar8 = local_res10;
LAB_1c00098f1:
      SendConfigPageMessage(param_1,cVar5,puVar8,iVar9,(int)in_stack_ffffffffffffffa8);
    }
    else {
      if (bVar7 == 0x41) {
        if ((*(byte *)(param_1 + 0x134) & 4) == 0) {
          *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(*(longlong *)(param_1 + 0xd90) + 8);
        }
        bVar7 = 0x80;
        local_res10[0] = 0x5090000;
LAB_1c00098e3:
        cVar5 = '\0';
        in_stack_ffffffffffffffa8 = 0;
        goto LAB_1c00098ea;
      }
      if (bVar7 == 0x48) {
        local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
        if (*(longlong *)(param_1 + 0xdc0) == 0) {
          uVar6 = ((ushort)((uint)local_res10[0] >> 8) & 0xff) << 2;
          if (*(uint *)(param_1 + 0xd8c) < (uint)uVar6) goto LAB_1c000954a;
          *(longlong *)(param_1 + 0xdc0) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar6 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar6;
        }
        bVar7 = 0x49;
        in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xdc0);
        goto LAB_1c0009658;
      }
      if (bVar7 == 0x49) {
        bVar7 = 0x40;
        local_res10[0] = 0x20000;
        goto LAB_1c00098e3;
      }
      if (bVar7 == 0x80) {
        local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
        *(undefined4 *)(param_1 + 0xdb0) = local_res10[0];
        if (*(longlong *)(param_1 + 0xdd8) == 0) {
          uVar6 = ((ushort)((uint)local_res10[0] >> 8) & 0xff) << 2;
          if (*(uint *)(param_1 + 0xd8c) < (uint)uVar6) goto LAB_1c000954a;
          *(longlong *)(param_1 + 0xdd8) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar6 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar6;
        }
        in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xdd8);
        bVar7 = 0x81;
        goto LAB_1c00094f0;
      }
      if (bVar7 == 0x81) {
        lVar1 = *(longlong *)(param_1 + 0xdb8);
        puVar8 = (undefined4 *)(param_1 + 0xdb0);
        lVar2 = *(longlong *)(param_1 + 0xdd8);
        bVar7 = 0x82;
        iVar9 = 0;
        *(undefined8 *)(lVar2 + 8) = *(undefined8 *)(lVar1 + 0x18);
        *(undefined8 *)(lVar2 + 0x10) = *(undefined8 *)(lVar1 + 0x10);
        *(undefined4 *)(lVar2 + 0x18) = 10;
        cVar5 = '\x02';
        *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(lVar1 + 0xc);
        in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xdd8);
        goto LAB_1c00098f1;
      }
      if (bVar7 == 0x82) {
        bVar7 = 0x83;
        local_res10[0] = 0x5060000;
        goto LAB_1c00098e3;
      }
      if (bVar7 == 0x83) {
        local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
        *(undefined4 *)(param_1 + 0xdac) = local_res10[0];
        if (*(longlong *)(param_1 + 0xdd0) == 0) {
          uVar6 = ((ushort)((uint)local_res10[0] >> 8) & 0xff) << 2;
          if (*(uint *)(param_1 + 0xd8c) < (uint)uVar6) {
LAB_1c000954a:
            bVar3 = true;
            goto LAB_1c00098f9;
          }
          *(longlong *)(param_1 + 0xdd0) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar6 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar6;
        }
        bVar7 = 0x84;
        local_res10[0] = 0x6000000;
        goto LAB_1c00098e3;
      }
      if (bVar7 == 0x84) {
        local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
        *(undefined4 *)(param_1 + 0xdb4) = local_res10[0];
        if (*(longlong *)(param_1 + 0xde0) == 0) {
          uVar6 = ((ushort)((uint)local_res10[0] >> 8) & 0xff) << 2;
          if (*(uint *)(param_1 + 0xd8c) < (uint)uVar6) goto LAB_1c000954a;
          *(longlong *)(param_1 + 0xde0) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar6 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar6;
        }
        bVar10 = 0;
        local_res8 = '\x01';
      }
      else {
LAB_1c00096a4:
        bVar10 = 0;
      }
    }
LAB_1c00098f9:
    local_res18 = (uint)bVar10;
    *(byte *)(param_1 + 0xd62) = bVar7;
    if (bVar3) {
      local_res18 = 0;
    }
    if ((char)local_res18 == '\0') break;
    uVar6 = 0;
    do {
      uVar4 = LSImpiMSIIsr(param_1);
      if ((char)uVar4 != '\0') break;
      StorPortStallExecution(500);
      uVar6 = uVar6 + 1;
    } while (uVar6 < 4000);
    bVar7 = *(byte *)(param_1 + 0xd62);
    if ((uVar6 == 4000) || (uVar11 = local_res18, bVar7 == 0xff)) {
      uVar11 = 0;
    }
  } while ((char)uVar11 != '\0');
  if (local_res8 == '\0') {
    *(undefined1 *)(param_1 + 0xd62) = 0xff;
    StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffa8 & 0xffffffffffffff00,6,0xad010020);
  }
  else {
    *(undefined1 *)(param_1 + 0xd62) = 0;
  }
  return local_res8;
}



===== ReadPortPages @ 1c00099c4 =====

char ReadPortPages(longlong param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  short *psVar5;
  undefined8 uVar6;
  longlong lVar7;
  char cVar8;
  short sVar9;
  ushort uVar10;
  byte bVar11;
  byte bVar12;
  uint uVar13;
  char local_res8;
  undefined4 local_res10 [2];
  uint local_res18;
  ulonglong in_stack_ffffffffffffffa8;
  
  local_res8 = '\0';
  bVar11 = 1;
  bVar4 = false;
  uVar13 = 1;
  do {
    bVar12 = (byte)uVar13;
    if (bVar11 < 0x42) {
      if (bVar11 == 0x41) {
        if ((*(byte *)(param_1 + 0x134) & 4) == 0) {
          *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(*(longlong *)(param_1 + 0xd90) + 8);
        }
        bVar11 = 0x48;
        local_res10[0] = 0x9000000;
      }
      else if (bVar11 < 0x13) {
        if (bVar11 == 0x12) {
          bVar11 = 0x20;
          local_res10[0] = 0x3000000;
        }
        else {
          if (bVar11 != 1) {
            if (bVar11 == 8) {
              bVar11 = 9;
LAB_1c0009a7d:
              local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
              in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xd90);
              goto LAB_1c0009fea;
            }
            if (bVar11 == 9) {
              lVar7 = *(longlong *)(param_1 + 0xd90);
              if (*(byte *)(lVar7 + 0xd) == 0xff) {
                uVar10 = 0xffff;
              }
              else {
                uVar10 = (ushort)*(byte *)(lVar7 + 0xd);
              }
              iVar2 = *(int *)(param_1 + 0x2dc);
              *(ushort *)(param_1 + 0xf42) = uVar10;
              cVar8 = *(char *)(param_1 + 0x2d8);
              if (iVar2 != -1) {
                *(int *)(lVar7 + 8) = iVar2;
              }
              if (cVar8 != -1) {
                *(char *)(lVar7 + 0xc) = cVar8;
              }
              if ((iVar2 == 0) && (cVar8 == '\x01')) {
                *(undefined4 *)(lVar7 + 4) = 0;
              }
              else {
                *(undefined4 *)(lVar7 + 4) = 1;
              }
              bVar11 = 10;
            }
            else {
              if (bVar11 == 10) {
                bVar11 = 0x10;
                local_res10[0] = 0x3010000;
                goto LAB_1c0009a9c;
              }
              if (bVar11 == 0x10) {
                bVar11 = 0x11;
                goto LAB_1c0009a7d;
              }
              if (bVar11 != 0x11) goto LAB_1c0009e5c;
              bVar11 = 0x12;
              *(uint *)(*(longlong *)(param_1 + 0xd90) + 4) =
                   (1 << (*(byte *)(param_1 + 0x1ee) + 0x10 & 0x1f)) +
                   (uint)*(byte *)(param_1 + 0x1ee);
            }
            local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
            cVar8 = '\x02';
            in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xd90);
            goto LAB_1c0009ff2;
          }
          bVar11 = 8;
          local_res10[0] = 0x1010000;
        }
      }
      else {
        if (bVar11 == 0x20) {
          local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
          if (*(longlong *)(param_1 + 0xe40) == 0) {
            uVar10 = ((ushort)((uint)local_res10[0] >> 8) & 0xff) << 2;
            if (*(uint *)(param_1 + 0xd8c) < (uint)uVar10) goto LAB_1c0009c6f;
            *(longlong *)(param_1 + 0xe40) = *(longlong *)(param_1 + 0xd90);
            *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0xd90);
            *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar10;
          }
          in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xe40);
          bVar11 = 0x21;
          goto LAB_1c0009fea;
        }
        if (bVar11 == 0x21) {
          bVar11 = 0x30;
          local_res10[0] = 0x3020000;
        }
        else {
          if (bVar11 == 0x30) {
            local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
            if (*(longlong *)(param_1 + 0xe48) == 0) {
              uVar10 = ((ushort)((uint)local_res10[0] >> 8) & 0xff) << 2;
              if (*(uint *)(param_1 + 0xd8c) < (uint)uVar10) goto LAB_1c0009c6f;
              *(longlong *)(param_1 + 0xe48) = *(longlong *)(param_1 + 0xd90);
              *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0xd90);
              *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar10;
            }
            bVar11 = 0x31;
            in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xe48);
            goto LAB_1c0009b58;
          }
          if (bVar11 != 0x31) {
            if (bVar11 != 0x40) goto LAB_1c0009e5c;
            bVar11 = 0x41;
            goto LAB_1c0009b48;
          }
          if ((*(byte *)(param_1 + 0x134) & 4) != 0) {
            lVar7 = *(longlong *)(param_1 + 0xe48);
            sVar9 = 0;
            *(undefined4 *)(lVar7 + 4) = 0;
            *(undefined4 *)(lVar7 + 8) = 0x37;
            uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0xe40) + 4);
            if ((*(uint *)(*(longlong *)(param_1 + 0xe40) + 4) & 0x20000000) == 0) {
              sVar9 = 0x10;
            }
            psVar5 = (short *)(lVar7 + 0xe);
            lVar7 = 0x10;
            do {
              *(undefined1 *)(psVar5 + -1) = 10;
              *(char *)((longlong)psVar5 + -1) = (char)((uint)uVar3 >> 8);
              *psVar5 = sVar9 + 0xf;
              psVar5 = psVar5 + 2;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
          }
          bVar11 = 0x40;
          local_res10[0] = 0x20000;
        }
      }
      goto LAB_1c0009a9c;
    }
    if (bVar11 < 0x62) {
      if (bVar11 == 0x61) {
        bVar11 = 0x70;
        local_res10[0] = 0x1040000;
        goto LAB_1c0009a9c;
      }
      if (bVar11 == 0x48) {
        bVar11 = 0x49;
LAB_1c0009b48:
        local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
        in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xd90);
LAB_1c0009b58:
        cVar8 = '\x06';
      }
      else {
        if (bVar11 == 0x49) {
          if ((*(byte *)(param_1 + 0x134) & 4) == 0) {
            memcpy((void *)(param_1 + 0x116c),(void *)(*(longlong *)(param_1 + 0xd90) + 0x3c),0x10);
          }
          bVar11 = 0x50;
          local_res10[0] = 0x1020000;
          goto LAB_1c0009a9c;
        }
        if (bVar11 == 0x50) {
          local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
          if (*(longlong *)(param_1 + 0xe50) == 0) {
            uVar10 = ((ushort)((uint)local_res10[0] >> 8) & 0xff) << 2;
            if (*(uint *)(param_1 + 0xd8c) < (uint)uVar10) goto LAB_1c0009c6f;
            *(longlong *)(param_1 + 0xe50) = *(longlong *)(param_1 + 0xd90);
            *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0xd90);
            *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar10;
          }
          in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xe50);
          bVar11 = 0x51;
        }
        else {
          if (bVar11 == 0x51) {
            bVar11 = 0x60;
            local_res10[0] = 0x1030000;
            goto LAB_1c0009a9c;
          }
          if (bVar11 != 0x60) goto LAB_1c0009e5c;
          local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
          if (*(longlong *)(param_1 + 0xe58) == 0) {
            uVar10 = (*(byte *)(*(longlong *)(param_1 + 0xe50) + 0xb) + 2) * 4;
            if (*(uint *)(param_1 + 0xd8c) < (uint)uVar10) goto LAB_1c0009c6f;
            *(longlong *)(param_1 + 0xe58) = *(longlong *)(param_1 + 0xd90);
            *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0xd90);
            *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar10;
          }
          in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xe58);
          bVar11 = 0x61;
        }
LAB_1c0009fea:
        cVar8 = '\x01';
      }
LAB_1c0009ff2:
      SendConfigPageMessage(param_1,cVar8,local_res10,0,(int)in_stack_ffffffffffffffa8);
    }
    else {
      if (bVar11 == 0x70) {
        local_res10[0] = *(undefined4 *)(param_1 + 0xd98);
        if (*(longlong *)(param_1 + 0xe60) == 0) {
          uVar10 = ((ushort)((uint)local_res10[0] >> 8) & 0xff) << 2;
          if (*(uint *)(param_1 + 0xd8c) < (uint)uVar10) goto LAB_1c0009c6f;
          *(longlong *)(param_1 + 0xe60) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) - (uint)uVar10;
        }
        in_stack_ffffffffffffffa8 = *(ulonglong *)(param_1 + 0xe60);
        bVar11 = 0x71;
        goto LAB_1c0009fea;
      }
      if (bVar11 == 0x71) {
        bVar11 = 0x8c;
        local_res10[0] = 0x4000000;
LAB_1c0009a9c:
        in_stack_ffffffffffffffa8 = 0;
        cVar8 = '\0';
        goto LAB_1c0009ff2;
      }
      if (bVar11 == 0x8c) {
        if (*(longlong *)(param_1 + 0xe68) == 0) {
          bVar1 = *(byte *)(param_1 + 0xe39);
          if (*(uint *)(param_1 + 0xd8c) < (uint)bVar1 * 4) {
LAB_1c0009c6f:
            bVar4 = true;
            goto LAB_1c000a001;
          }
          *(longlong *)(param_1 + 0xe68) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)bVar1 * 4 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) + (uint)bVar1 * -4;
        }
        bVar11 = 0x8d;
        local_res10[0] = 0x4010000;
        goto LAB_1c0009a9c;
      }
      if (bVar11 == 0x8d) {
        if (*(longlong *)(param_1 + 0xe70) == 0) {
          bVar1 = *(byte *)(param_1 + 0xe3d);
          if (*(uint *)(param_1 + 0xd8c) < (uint)bVar1 * 4) goto LAB_1c0009c6f;
          *(longlong *)(param_1 + 0xe70) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)bVar1 * 4 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) + (uint)bVar1 * -4;
        }
        bVar11 = 0x8e;
        local_res10[0] = 0x4030000;
        goto LAB_1c0009a9c;
      }
      if (bVar11 == 0x8e) {
        if ((*(longlong *)(param_1 + 0x1180) == 0) && (*(short *)(param_1 + 0xd64) == 0)) {
          bVar1 = *(byte *)(param_1 + 0x117d);
          if (*(uint *)(param_1 + 0xd8c) < (uint)bVar1 * 4) goto LAB_1c0009c6f;
          *(longlong *)(param_1 + 0x1180) = *(longlong *)(param_1 + 0xd90);
          *(ulonglong *)(param_1 + 0xd90) = (ulonglong)bVar1 * 4 + *(longlong *)(param_1 + 0xd90);
          *(uint *)(param_1 + 0xd8c) = *(uint *)(param_1 + 0xd8c) + (uint)bVar1 * -4;
        }
        bVar12 = 0;
        local_res8 = '\x01';
      }
      else {
LAB_1c0009e5c:
        bVar12 = 0;
      }
    }
LAB_1c000a001:
    local_res18 = (uint)bVar12;
    *(byte *)(param_1 + 0xd62) = bVar11;
    if (bVar4) {
      local_res18 = 0;
    }
    if ((char)local_res18 == '\0') break;
    uVar10 = 0;
    do {
      uVar6 = LSImpiMSIIsr(param_1);
      if ((char)uVar6 != '\0') break;
      StorPortStallExecution(500);
      uVar10 = uVar10 + 1;
    } while (uVar10 < 4000);
    if (bVar11 == 0x8e) {
      *(undefined1 *)(param_1 + 0xd62) = 0x8e;
    }
    bVar11 = *(byte *)(param_1 + 0xd62);
    if ((uVar10 == 4000) || (uVar13 = local_res18, bVar11 == 0xff)) {
      uVar13 = 0;
    }
  } while ((char)uVar13 != '\0');
  if (local_res8 == '\0') {
    *(undefined1 *)(param_1 + 0xd62) = 0xff;
    StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffa8 & 0xffffffffffffff00,6,0xad010020);
  }
  else {
    *(undefined1 *)(param_1 + 0xd62) = 0;
  }
  return local_res8;
}



===== SendQASPoolMessage @ 1c000a0e8 =====

void SendQASPoolMessage(longlong param_1,undefined8 param_2,undefined4 *param_3,int param_4,
                       int param_5)

{
  byte bVar1;
  int iVar2;
  undefined1 *_Dst;
  
  _Dst = (undefined1 *)((ulonglong)(uint)(param_4 << 6) + *(longlong *)(param_1 + 0xe30));
  iVar2 = *(int *)(param_1 + 0x58);
  memset(_Dst,0,0x28);
  *_Dst = 2;
  _Dst[3] = 4;
  bVar1 = *(byte *)(param_1 + 0xd62);
  *(undefined4 *)(_Dst + 0x1c) = 0xd1000000;
  *(undefined4 *)(_Dst + 0x14) = *param_3;
  *(uint *)(_Dst + 8) = param_4 + 0x10000000 + (uint)bVar1;
  *(int *)(_Dst + 0x18) = param_4;
  *(int *)(_Dst + 0x20) = param_5 - *(int *)(param_1 + 0x58);
  *(uint *)(_Dst + 0x1c) = (uint)*(byte *)((longlong)param_3 + 1) << 2 | 0xd5000000;
  **(uint **)(param_1 + 0x38) = (int)_Dst - iVar2 | 2;
  LOCK();
  UNLOCK();
  return;
}



===== CompaqCsmiIOCTLRequest @ 1c000a198 =====

undefined8 CompaqCsmiIOCTLRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  void *pvVar4;
  byte bVar5;
  ulonglong uVar6;
  
  lVar3 = *(longlong *)(param_2 + 0x18);
  uVar6 = 0;
  do {
    pvVar4 = (void *)CONCAT71(0x1c00171,(&CpqCsmiSig)[uVar6]);
    if (*(char *)(uVar6 + 4 + lVar3) != (&CpqCsmiSig)[uVar6]) {
      return &FW_DIAG_IOCTLSIG;
    }
    bVar5 = (char)uVar6 + 1;
    uVar6 = (ulonglong)bVar5;
  } while (bVar5 < 7);
  *(undefined4 *)(lVar3 + 0x14) = 0;
  iVar1 = *(int *)(lVar3 + 0x10);
  if (iVar1 == 1) {
    if (0xa9 < *(uint *)(lVar3 + 0x18)) {
      memcpy((void *)(lVar3 + 0x1c),drvFileName,0xc);
      memcpy((void *)(lVar3 + 0x6d),drvDesc,0x24);
      pvVar4 = (void *)0x0;
      *(undefined4 *)(lVar3 + 0xbe) = 0x220001;
      *(undefined4 *)(lVar3 + 0xc2) = 0x530003;
      goto LAB_1c000a303;
    }
  }
  else if (iVar1 == 2) {
    if (0xa7 < *(uint *)(lVar3 + 0x18)) {
      *(undefined4 *)(lVar3 + 0x1c) = *(undefined4 *)(param_1 + 0xf48);
      *(undefined4 *)(lVar3 + 0x20) = *(undefined4 *)(param_1 + 0xf4c);
      *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(param_1 + 0xf50);
      *(int *)(lVar3 + 0x28) = *(int *)(param_1 + 0x2f0) * 0x10000 + *(int *)(param_1 + 0x2f4);
      *(undefined2 *)(lVar3 + 0x2c) = *(undefined2 *)(param_1 + 0xf42);
      *(undefined2 *)(lVar3 + 0x2e) = 0x302;
      uVar2 = *(uint *)(param_1 + 0x328);
      *(char *)(lVar3 + 0x30) = (char)(uVar2 >> 8);
      *(byte *)(lVar3 + 0x31) = (byte)uVar2 & 0x1f;
      *(byte *)(lVar3 + 0x32) = (byte)(uVar2 >> 5) & 7;
      pvVar4 = memcpy((void *)(lVar3 + 0x50),(void *)(param_1 + 0x116c),0x10);
      goto LAB_1c000a303;
    }
  }
  else {
    if (iVar1 != 3) {
      *(undefined4 *)(lVar3 + 0x14) = 2;
      goto LAB_1c000a303;
    }
    if (0x23 < *(uint *)(lVar3 + 0x18)) {
      *(undefined4 *)(lVar3 + 0x1c) = *(undefined4 *)(param_1 + 0xf54);
      pvVar4 = (void *)0x0;
      if (*(int *)(param_1 + 0xf54) == 3) {
        *(undefined4 *)(lVar3 + 0x20) = 1;
      }
      goto LAB_1c000a303;
    }
  }
  pvVar4 = (void *)0x0;
  *(undefined4 *)(lVar3 + 0x14) = 3;
LAB_1c000a303:
  return CONCAT71((int7)((ulonglong)pvVar4 >> 8),1);
}



===== CompaqScsiIOCTLRequest @ 1c000a318 =====

undefined8 CompaqScsiIOCTLRequest(longlong param_1,void *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint *in_RAX;
  byte bVar7;
  void *_Dst;
  int iVar8;
  uint *_Dst_00;
  int local_res10 [2];
  longlong local_res18;
  
  lVar4 = *(longlong *)((longlong)param_2 + 0x38);
  lVar5 = *(longlong *)((longlong)param_2 + 0x18);
  bVar7 = 0;
  do {
    if (*(char *)((ulonglong)bVar7 + 4 + lVar5) != (&CpqScsiSig)[bVar7]) {
      return (ulonglong)in_RAX & 0xffffffffffffff00;
    }
    bVar7 = bVar7 + 1;
  } while (bVar7 < 7);
  if (*(int *)(lVar5 + 0x10) == 1) {
    iVar8 = *(int *)(lVar5 + 0x18) + -0x78;
    *(int *)(param_1 + 0xf58) = iVar8;
    *(undefined4 *)(lVar5 + 0x14) = 1;
    in_RAX = *(uint **)(param_1 + 0x158);
    if (*(longlong *)(*(longlong *)in_RAX + 8) == 0) {
      _Dst_00 = (uint *)(lVar4 + 0x138);
      uVar6 = StorPortGetPhysicalAddress(param_1,param_2,_Dst_00,local_res10);
      memset(_Dst_00,0,0x30);
      local_res18 = *(longlong *)((longlong)param_2 + 0x18);
      bVar7 = *(byte *)(local_res18 + 0x1d);
      uVar1 = *(uint *)(local_res18 + 0x30);
      *(undefined1 *)(lVar4 + 0x139) = *(undefined1 *)(local_res18 + 0x1c);
      *(byte *)_Dst_00 = bVar7;
      *(undefined1 *)(lVar4 + 0x145) = *(undefined1 *)(local_res18 + 0x1e);
      *(undefined1 *)(lVar4 + 0x13c) = *(undefined1 *)(local_res18 + 0x1f);
      *(int *)(lVar4 + 0x160) = iVar8;
      if (((*(ushort *)(param_1 + 0x134) & 0x100) == 0) &&
         ((*(ushort *)(param_1 + 0xf44) >> (bVar7 & 0x1f) & 1) == 0)) {
        *(undefined4 *)(lVar4 + 0x14c) = 0x500;
      }
      if ((uVar1 & 8) != 0) {
        *(uint *)(lVar4 + 0x14c) = *(uint *)(lVar4 + 0x14c) | 0x700;
      }
      *(undefined1 *)(lVar4 + 0x13b) = 0;
      *(undefined4 *)(param_1 + 0x32c) = 0xc0ffaf;
      _Dst = (void *)(lVar4 + 0x150);
      *(undefined4 *)(lVar4 + 0x140) = 0x80ffeed;
      memcpy(_Dst,(void *)(local_res18 + 0x20),(ulonglong)*(byte *)(lVar4 + 0x13c));
      *(undefined1 *)(lVar4 + 0x13d) = 0x28;
      *(uint *)(lVar4 + 0x164) = uVar6 - 0x100;
      if (iVar8 == 0) {
        BuildZeroLenSGE(_Dst,(longlong)_Dst_00,uVar6);
      }
      else {
        uVar2 = *(undefined4 *)((longlong)param_2 + 0xc);
        uVar3 = *(undefined4 *)((longlong)param_2 + 0x10);
        uVar1 = *(uint *)(local_res18 + 0x30);
        *(int *)((longlong)param_2 + 0x10) = iVar8;
        *(uint *)((longlong)param_2 + 0xc) = (uVar1 & 3) << 6;
        local_res10[0] =
             BuildScatterGather(param_1,(longlong)param_2,(int)local_res18 + 0x90,_Dst_00,uVar6);
        *(undefined4 *)((longlong)param_2 + 0xc) = uVar2;
        *(undefined4 *)((longlong)param_2 + 0x10) = uVar3;
      }
      *(void **)(param_1 + 0x6a8) = param_2;
      memcpy((void *)(param_1 + 0x6b8),param_2,0x40);
      *(undefined1 *)(param_1 + 0x6a3) = *(undefined1 *)((longlong)param_2 + 5);
      memcpy(*(void **)(param_1 + 0x6f8),_Dst_00,(ulonglong)*(ushort *)(param_1 + 300));
      in_RAX = *(uint **)(param_1 + 0x38);
      *(undefined1 *)(param_1 + 0x6a1) = 1;
      *in_RAX = uVar6;
      LOCK();
      UNLOCK();
      *(undefined4 *)(lVar5 + 0x14) = 0;
    }
  }
  else {
    *(undefined4 *)(lVar5 + 0x14) = 2;
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== CompaqMandPIOCTLRequest @ 1c000a538 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 * CompaqMandPIOCTLRequest(longlong param_1,longlong param_2,undefined1 *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint uVar5;
  longlong *plVar6;
  undefined8 uVar7;
  byte bVar8;
  ulonglong uVar9;
  byte bVar10;
  char cVar11;
  undefined1 *_Dst;
  undefined1 local_a8 [32];
  undefined1 local_78 [8];
  undefined4 local_70 [8];
  char local_50 [8];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_a8;
  lVar2 = *(longlong *)(param_2 + 0x18);
  lVar3 = *(longlong *)(param_2 + 0x38);
  local_50[0] = '\0';
  local_50[1] = '2';
  local_50[2] = '\x19';
  local_50[3] = '\f';
  local_50[4] = '\n';
  local_50[5] = '\t';
  local_50[6] = 8;
  *param_3 = 1;
  local_70[0] = 5000000;
  bVar10 = 0;
  local_70[1] = 5000000;
  local_70[2] = 10000000;
  local_70[3] = 20000000;
  local_70[4] = 4000000;
  local_70[5] = 80000000;
  local_70[6] = 160000000;
  do {
    plVar6 = (longlong *)CONCAT71(0x1c00171,(&CpqSig)[bVar10]);
    if (*(char *)((ulonglong)bVar10 + 4 + lVar2) != (&CpqSig)[bVar10]) {
      return &FW_DIAG_IOCTLSIG;
    }
    bVar10 = bVar10 + 1;
  } while (bVar10 < 7);
  iVar1 = *(int *)(lVar2 + 0x10);
  *(undefined4 *)(lVar2 + 0x14) = 0;
  if (iVar1 == 1) {
    uVar5 = *(uint *)(lVar2 + 0x18);
    plVar6 = (longlong *)(ulonglong)uVar5;
    if (uVar5 < 100) {
      *(undefined4 *)(lVar2 + 0x14) = 4;
      if (3 < uVar5) {
        *(undefined4 *)(lVar2 + 0x1c) = 100;
      }
    }
    else {
      memcpy((void *)(lVar2 + 0x1c),drvFileName,0xc);
      memcpy((void *)(lVar2 + 0x29),drvDesc,0x24);
      *(undefined4 *)(lVar2 + 0x7a) = 0x220001;
      *(undefined1 *)(lVar2 + 0x7e) = 1;
      plVar6 = (longlong *)0x0;
    }
    goto LAB_1c000a82e;
  }
  if (iVar1 == 2) {
    uVar5 = *(uint *)(lVar2 + 0x18);
    plVar6 = (longlong *)(ulonglong)uVar5;
    if (uVar5 < 0x38) {
      *(undefined4 *)(lVar2 + 0x14) = 4;
      if (3 < uVar5) {
        *(undefined4 *)(lVar2 + 0x1c) = 0x38;
      }
    }
    else {
      bVar10 = 0;
      *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(param_1 + 0xf48);
      *(undefined2 *)(lVar2 + 0x20) = 0x3f0;
      *(char *)(lVar2 + 0x22) = (char)((uint)*(undefined4 *)(param_1 + 0x328) >> 8);
      *(byte *)(lVar2 + 0x23) = *(byte *)(param_1 + 0x328) & 0x1f;
      *(byte *)(lVar2 + 0x24) = (byte)(*(uint *)(param_1 + 0x328) >> 5) & 7;
      cVar11 = *(char *)(param_1 + 0x1e4);
      *(char *)(lVar2 + 0x26) = cVar11;
      if (cVar11 != '\0') {
        do {
          uVar9 = (ulonglong)bVar10;
          bVar10 = bVar10 + 1;
          *(undefined1 *)(uVar9 + 0x27 + lVar2) = *(undefined1 *)(param_1 + 0x1ee);
        } while (bVar10 < *(byte *)(lVar2 + 0x26));
      }
      uVar5 = *(uint *)(param_1 + 0x2fc);
      bVar10 = (byte)(uVar5 >> 0x18);
      if (bVar10 < 10) {
        cVar11 = '0';
      }
      else {
        cVar11 = (char)((uVar5 >> 0x18) / 10) + '0';
      }
      *(char *)(lVar2 + 0x2f) = cVar11;
      *(byte *)(lVar2 + 0x30) = bVar10 + (char)((uVar5 >> 0x18) / 10) * -10 + '0';
      bVar10 = (byte)(uVar5 >> 0x10);
      if (bVar10 < 10) {
        cVar11 = '0';
      }
      else {
        cVar11 = bVar10 / 10 + 0x30;
      }
      *(char *)(lVar2 + 0x31) = cVar11;
      *(byte *)(lVar2 + 0x32) = bVar10 + (char)((uVar5 >> 0x10 & 0xff) / 10) * -10 + '0';
      bVar10 = (byte)(uVar5 >> 8);
      if (bVar10 < 10) {
        cVar11 = '0';
      }
      else {
        cVar11 = bVar10 / 10 + 0x30;
      }
      *(char *)(lVar2 + 0x33) = cVar11;
      *(byte *)(lVar2 + 0x34) = bVar10 + (char)((uVar5 >> 8 & 0xff) / 10) * -10 + '0';
      if ((byte)uVar5 < 10) {
        cVar11 = '0';
      }
      else {
        cVar11 = (char)((uVar5 & 0xff) / 10) + '0';
      }
      *(char *)(lVar2 + 0x35) = cVar11;
      *(undefined1 *)(lVar2 + 0x37) = 0;
      *(byte *)(lVar2 + 0x36) = (byte)uVar5 + (char)((uVar5 & 0xff) / 10) * -10 + '0';
      memcpy((void *)(lVar2 + 0x39),(void *)(param_1 + 0x116c),0x10);
      uVar5 = *(int *)(param_1 + 0x2f0) * 0x10000 + *(int *)(param_1 + 0x2f4);
      plVar6 = (longlong *)(ulonglong)uVar5;
      *(uint *)(lVar2 + 0x4c) = uVar5;
      *(undefined2 *)(lVar2 + 0x50) = 0x100;
    }
    goto LAB_1c000a82e;
  }
  if (iVar1 == 3) {
    uVar5 = *(uint *)(lVar2 + 0x18);
    plVar6 = (longlong *)(ulonglong)uVar5;
    if (uVar5 < 0x4c) {
      *(undefined4 *)(lVar2 + 0x14) = 4;
      if (3 < uVar5) {
        *(undefined4 *)(lVar2 + 0x1c) = 0x4c;
      }
      goto LAB_1c000a82e;
    }
    if (*(char *)(lVar2 + 0x1d) == '\x01') {
      *(undefined1 *)(lVar2 + 0x20) = 2;
      *(undefined4 *)(lVar2 + 0x2c) = *(undefined4 *)(param_1 + 0xf60);
      *(undefined4 *)(lVar2 + 0x30) = *(undefined4 *)(param_1 + 0xf64);
      *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_1 + 0xf68);
      plVar6 = *(longlong **)(param_1 + 0x158);
      if (*(longlong *)(*plVar6 + 8) == 0) {
        _Dst = (undefined1 *)(lVar3 + 0x138);
        *(longlong *)(param_1 + 0x1188) = param_2;
        uVar4 = StorPortGetPhysicalAddress(param_1,param_2,_Dst,local_78);
        memset(_Dst,0,0x28);
        *(undefined1 *)(lVar3 + 0x13b) = 0x17;
        *_Dst = 3;
        *(undefined2 *)(lVar3 + 0x14a) = 3;
        *(undefined4 *)(lVar3 + 0x140) = 0xffeed;
        *(undefined1 *)(lVar3 + 0x144) = 1;
        *(undefined1 *)(lVar3 + 0x148) = 1;
        uVar5 = *(uint *)(param_1 + 0x328);
        *(undefined4 *)(lVar3 + 0x154) = 0xd1000003;
        *(byte *)(lVar3 + 0x14c) = (-((uVar5 & 0xe0) != 0) & 2U) + 0xb0;
        uVar7 = StorPortGetPhysicalAddress(param_1,param_2,lVar2 + 0x5a,local_78);
        *(int *)(lVar3 + 0x158) = (int)uVar7;
        if ((*(byte *)(param_1 + 0x134) & 1) != 0) {
          *(uint *)(lVar3 + 0x154) = *(uint *)(lVar3 + 0x154) | 0x2000000;
          *(int *)(lVar3 + 0x15c) = (int)((ulonglong)uVar7 >> 0x20);
        }
        plVar6 = *(longlong **)(param_1 + 0x38);
        *(undefined1 *)(param_1 + 0x6a1) = 1;
        *(undefined4 *)plVar6 = uVar4;
        LOCK();
        UNLOCK();
        *param_3 = 0;
      }
      goto LAB_1c000a82e;
    }
  }
  else {
    if (iVar1 != 4) {
      if (iVar1 != 5) {
        if (iVar1 == 6) goto LAB_1c000a6c7;
        if (iVar1 != 7) {
          *(undefined4 *)(lVar2 + 0x14) = 2;
          goto LAB_1c000a82e;
        }
      }
      uVar5 = *(uint *)(lVar2 + 0x18);
      plVar6 = (longlong *)(ulonglong)uVar5;
      if (uVar5 < 0x24) {
        *(undefined4 *)(lVar2 + 0x14) = 4;
        if (3 < uVar5) {
          *(undefined4 *)(lVar2 + 0x1c) = 0x24;
        }
      }
      else {
        uVar9 = (ulonglong)*(byte *)(lVar2 + 0x22);
        *(undefined4 *)(lVar2 + 0x24) =
             *(undefined4 *)(param_1 + 0xf6c + (ulonglong)*(byte *)(lVar2 + 0x22) * 4);
        *(undefined4 *)(lVar2 + 0x28) = *(undefined4 *)(param_1 + 0xfac + uVar9 * 4);
        *(undefined4 *)(lVar2 + 0x2c) = *(undefined4 *)(param_1 + 0xfec + uVar9 * 4);
        *(undefined4 *)(lVar2 + 0x30) = *(undefined4 *)(param_1 + 0x102c + uVar9 * 4);
        *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_1 + 0x106c + uVar9 * 4);
        uVar5 = *(uint *)(param_1 + 0x10ac + uVar9 * 4);
        plVar6 = (longlong *)(ulonglong)uVar5;
        *(uint *)(lVar2 + 0x38) = uVar5;
        *(undefined4 *)(lVar2 + 0x3c) = 0;
        if (*(int *)(lVar2 + 0x10) == 7) {
          *(undefined4 *)(param_1 + 0xf6c + uVar9 * 4) = 0;
          *(undefined4 *)(param_1 + 0xfac + uVar9 * 4) = 0;
          *(undefined4 *)(param_1 + 0xfec + uVar9 * 4) = 0;
          *(undefined4 *)(param_1 + 0x102c + uVar9 * 4) = 0;
          *(undefined4 *)(param_1 + 0x106c + uVar9 * 4) = 0;
          *(undefined4 *)(param_1 + 0x10ac + uVar9 * 4) = 0;
        }
      }
      goto LAB_1c000a82e;
    }
LAB_1c000a6c7:
    uVar5 = *(uint *)(lVar2 + 0x18);
    plVar6 = (longlong *)(ulonglong)uVar5;
    if (uVar5 < 0x5c) {
      *(undefined4 *)(lVar2 + 0x14) = 4;
      if (3 < uVar5) {
        *(undefined4 *)(lVar2 + 0x1c) = 0x5c;
      }
      goto LAB_1c000a82e;
    }
    bVar10 = *(byte *)(lVar2 + 0x22);
    uVar9 = (ulonglong)bVar10;
    bVar8 = *(byte *)(uVar9 + 0xe9c + param_1);
    plVar6 = (longlong *)(ulonglong)CONCAT31((int3)(uVar5 >> 8),bVar8);
    uVar5 = *(uint *)(param_1 + 0x10ec + uVar9 * 4);
    if ((bVar8 & 8) != 0) {
      *(undefined4 *)(lVar2 + 0x5c) = 5000000;
      bVar8 = 0;
      *(uint *)(lVar2 + 0x58) = uVar5 >> 8 & 0xff;
      do {
        if ((char)(uVar5 >> 8) == local_50[bVar8]) {
          *(undefined4 *)(lVar2 + 0x5c) = local_70[bVar8];
          break;
        }
        bVar8 = bVar8 + 1;
      } while (bVar8 < 7);
      *(uint *)(lVar2 + 0x60) = *(ushort *)(param_1 + 0xf46) >> (bVar10 & 0x1f) & 1 | 2;
      *(uint *)(lVar2 + 100) = (-(uint)((uVar5 & 0x20000000) != 0) & 8) + 8;
      if (*(longlong *)(param_1 + 0x1180) == 0) {
        *(undefined4 *)(lVar2 + 0x48) = 0xffffffff;
        *(undefined4 *)(lVar2 + 0x4c) = 0xffffffff;
        *(undefined4 *)(lVar2 + 0x54) = 0xffffffff;
        uVar5 = *(uint *)(param_1 + 0x112c + uVar9 * 4);
        plVar6 = (longlong *)(ulonglong)uVar5;
        *(uint *)(lVar2 + 0x50) = uVar5;
        if (*(int *)(lVar2 + 0x10) == 6) {
          *(undefined4 *)(param_1 + 0x112c + uVar9 * 4) = 0;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0xd62) = 0xc2;
        *(longlong *)(param_1 + 0x1188) = param_2;
        *(undefined1 *)(param_1 + 0x6a1) = 1;
        plVar6 = (longlong *)
                 SendConfigPageMessage
                           (param_1,'\x01',(undefined4 *)(param_1 + 0x117c),(uint)bVar10,
                            (int)*(longlong *)(param_1 + 0x1180));
        *param_3 = 0;
      }
      goto LAB_1c000a82e;
    }
  }
  *(undefined4 *)(lVar2 + 0x14) = 5;
LAB_1c000a82e:
  return (undefined1 *)CONCAT71((int7)((ulonglong)plVar6 >> 8),1);
}



===== CompaqPSuiteIOCTLRequest @ 1c000ab84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * CompaqPSuiteIOCTLRequest(longlong param_1,longlong param_2,undefined1 *param_3)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  longlong lVar9;
  bool bVar10;
  undefined4 uVar11;
  char *pcVar12;
  longlong lVar13;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  byte bVar14;
  byte bVar15;
  uint uVar16;
  undefined1 auStackY_88 [32];
  undefined1 local_54;
  byte local_53;
  undefined1 local_52;
  undefined1 local_51;
  byte local_50 [8];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar9 = *(longlong *)(param_2 + 0x18);
  local_50[0] = 0;
  local_50[1] = 0x32;
  local_50[2] = 0x19;
  local_50[3] = 0xc;
  local_50[4] = 10;
  local_50[5] = 9;
  local_50[6] = 8;
  bVar14 = 0;
  *param_3 = 1;
  do {
    if (*(char *)((ulonglong)bVar14 + 4 + lVar9) != "PSUITE"[bVar14]) {
      return "FwDiag  ";
    }
    bVar14 = bVar14 + 1;
  } while (bVar14 < 6);
  *(longlong *)(param_1 + 0x1188) = param_2;
  iVar8 = *(int *)(lVar9 + 0x10);
  *(undefined4 *)(lVar9 + 0x14) = 0;
  uVar2 = *(undefined1 *)(lVar9 + 0x1e);
  lVar13 = CONCAT71(0x1c00171,uVar2);
  uVar3 = *(undefined1 *)(lVar9 + 0x1c);
  bVar14 = *(byte *)(lVar9 + 0x1d);
  if ((iVar8 == 0xc) || (iVar8 == 0x20)) {
    if (7 < *(uint *)(lVar9 + 0x18)) goto LAB_1c000ac57;
LAB_1c000ac46:
    *(undefined4 *)(lVar9 + 0x14) = 4;
    pcVar12 = "wDiag  ";
  }
  else {
    if ((iVar8 - 0x21U < 2) && (*(uint *)(lVar9 + 0x18) < 0x14)) {
      *(undefined4 *)(lVar9 + 0x14) = 4;
      return "wDiag  ";
    }
LAB_1c000ac57:
    if (iVar8 == 0xc) {
      pbVar1 = (byte *)(param_1 + 0x240);
      memset(pbVar1,0,0x34);
      *(undefined1 *)(param_1 + 0x245) = 3;
      *(undefined1 *)(param_1 + 0x241) = uVar3;
      *pbVar1 = bVar14;
      bVar10 = SendCompaqTaskMgmtMsg(param_1,(longlong)pbVar1);
      lVar13 = CONCAT71(extraout_var_01,bVar10);
      if (bVar10) {
        *(longlong *)(param_1 + 0x1198) = param_2;
LAB_1c000ae9e:
        *(undefined1 *)(param_1 + 0x6a1) = 1;
LAB_1c000aea5:
        *param_3 = 0;
      }
      else {
        *(undefined4 *)(lVar9 + 0x14) = 7;
      }
    }
    else if (iVar8 == 0xd) {
      if (*(uint *)(lVar9 + 0x18) < 0x10) goto LAB_1c000ac46;
      local_51 = *(undefined1 *)(lVar9 + 0x24);
      local_54 = uVar3;
      local_53 = bVar14;
      local_52 = uVar2;
      lVar13 = StorPortSynchronizeAccess(param_1,FindAbortContext,&local_54);
      if ((char)lVar13 == '\0') {
        *(undefined4 *)(lVar9 + 0x14) = 5;
      }
      else {
        pbVar1 = (byte *)(param_1 + 0x240);
        memset(pbVar1,0,0x34);
        *(undefined1 *)(param_1 + 0x245) = 1;
        *(undefined1 *)(param_1 + 0x241) = uVar3;
        *pbVar1 = bVar14;
        *(undefined1 *)(param_1 + 0x24d) = uVar2;
        *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(param_1 + 0xf5c);
        bVar10 = SendCompaqTaskMgmtMsg(param_1,(longlong)pbVar1);
        lVar13 = CONCAT71(extraout_var_00,bVar10);
        if (bVar10) {
          *(longlong *)(param_1 + 0x1190) = param_2;
          goto LAB_1c000ae9e;
        }
        *(undefined4 *)(lVar9 + 0x14) = 6;
      }
    }
    else if (iVar8 == 0x20) {
      CompaqCheckOutstandingTmRequest(param_1);
      memset((void *)(param_1 + 0x240),0,0x34);
      *(undefined1 *)(param_1 + 0x245) = 4;
      *(undefined1 *)(param_1 + 0x241) = uVar3;
      bVar10 = SendCompaqTaskMgmtMsg(param_1,param_1 + 0x240);
      lVar13 = CONCAT71(extraout_var,bVar10);
      if (bVar10) goto LAB_1c000ae9e;
      *(undefined4 *)(lVar9 + 0x14) = 1;
    }
    else {
      if (iVar8 == 0x21) {
        *(undefined1 *)(param_1 + 0x6a1) = 1;
        *(undefined1 *)(param_1 + 0xd62) = 0xc0;
        lVar13 = SendConfigPageMessage
                           (param_1,'\x01',(undefined4 *)(param_1 + 0xe38),(uint)bVar14,
                            (int)*(undefined8 *)(param_1 + 0xe68));
        goto LAB_1c000aea5;
      }
      if (iVar8 == 0x22) {
        bVar4 = *(byte *)(lVar9 + 0x24);
        bVar15 = 0;
        cVar5 = *(char *)(lVar9 + 0x25);
        bVar6 = *(byte *)(lVar9 + 0x26);
        bVar7 = *(byte *)(lVar9 + 0x28);
        do {
          if (bVar4 == local_50[bVar15]) break;
          bVar15 = bVar15 + 1;
        } while (bVar15 < 7);
        lVar13 = *(longlong *)(param_1 + 0xe40);
        if (*(byte *)(lVar13 + 6) < bVar6 || ((cVar5 - 8U & 0xf7) != 0 || bVar15 == 7)) {
          *(undefined4 *)(lVar9 + 0x14) = 3;
        }
        else {
          lVar13 = *(longlong *)(param_1 + 0xe70);
          *(undefined4 *)(lVar13 + 0xc) = 8;
          uVar16 = (uint)bVar6 * 0x10000 + (uint)bVar4 * 0x100 + (uint)bVar7;
          *(uint *)(lVar13 + 4) = uVar16;
          if (cVar5 == '\x10') {
            *(uint *)(lVar13 + 4) = uVar16 | 0x20000000;
          }
          uVar11 = *(undefined4 *)(lVar13 + 0xc);
          if (*(char *)(lVar9 + 0x29) == '\x02') {
            uVar11 = 0x18;
          }
          *(undefined4 *)(lVar13 + 0xc) = uVar11;
          *(undefined1 *)(param_1 + 0xd62) = 0xc1;
          lVar13 = SendConfigPageMessage
                             (param_1,'\x02',(undefined4 *)(param_1 + 0xe3c),(uint)bVar14,
                              (int)lVar13);
        }
      }
      else if (iVar8 == 0x23) {
        if (*(uint *)(lVar9 + 0x18) < 0xc) goto LAB_1c000ac46;
        lVar13 = CONCAT71(0x1c00171,*(undefined1 *)(param_1 + 0xf41));
        *(undefined1 *)(lVar9 + 0x24) = *(undefined1 *)(param_1 + 0xf41);
      }
      else {
        *(undefined4 *)(lVar9 + 0x14) = 1;
      }
    }
    pcVar12 = (char *)CONCAT71((int7)((ulonglong)lVar13 >> 8),1);
  }
  return pcVar12;
}



===== FindAbortContext @ 1c000aee0 =====

ulonglong FindAbortContext(longlong param_1,uint *param_2)

{
  longlong lVar1;
  ulonglong in_RAX;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(ushort *)(param_1 + 0x1d8) != 0) {
    lVar1 = *(longlong *)(param_1 + 0x148);
    do {
      in_RAX = uVar3;
      if (*(longlong *)(lVar1 + 8 + uVar3 * 0x18) != 0) {
        uVar2 = *param_2;
        in_RAX = (ulonglong)uVar2;
        if (*(uint *)(lVar1 + 0x14 + uVar3 * 0x18) == uVar2) {
          *(undefined4 *)(param_1 + 0xf5c) = *(undefined4 *)(lVar1 + 0x10 + uVar3 * 0x18);
          return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);
        }
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(ushort *)(param_1 + 0x1d8));
  }
  return in_RAX & 0xffffffffffffff00;
}



===== CompaqCheckSenseData @ 1c000af30 =====

void CompaqCheckSenseData(longlong param_1,byte param_2,longlong param_3,byte param_4)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  bool bVar4;
  ulonglong uVar5;
  
  bVar1 = *(byte *)(param_3 + 0xc);
  cVar2 = *(char *)(param_3 + 2);
  uVar5 = (ulonglong)param_2;
  bVar4 = false;
  if ((bVar1 < 0x17) && ((0x5f1008U >> (bVar1 & 0x1f) & 1) != 0)) {
    bVar4 = false;
    if (cVar2 == '\x03') {
      bVar4 = true;
    }
  }
  if ((param_2 < 0x3f) && ((0x4000010000000100U >> (uVar5 & 0x3f) & 1) != 0)) {
    if (bVar4) {
      uVar3 = *(uint *)(param_1 + 0xf6c + (ulonglong)param_4 * 4);
      if (uVar3 < 0xfffffffe) {
        *(uint *)(param_1 + 0xf6c + (ulonglong)param_4 * 4) = uVar3 + 1;
      }
    }
    else if (((cVar2 == '\x01') && (bVar1 != 0x15)) && (bVar1 != 0x18)) {
      uVar3 = *(uint *)(param_1 + 0x102c + (ulonglong)param_4 * 4);
      if (uVar3 < 0xfffffffe) {
        *(uint *)(param_1 + 0x102c + (ulonglong)param_4 * 4) = uVar3 + 1;
      }
    }
  }
  if ((param_2 < 0x40) && ((0x8000040000000400U >> (uVar5 & 0x3f) & 1) != 0)) {
    if (bVar4) {
      uVar3 = *(uint *)(param_1 + 0xfac + (ulonglong)param_4 * 4);
      if (uVar3 < 0xfffffffe) {
        *(uint *)(param_1 + 0xfac + (ulonglong)param_4 * 4) = uVar3 + 1;
      }
      goto LAB_1c000b027;
    }
    if (cVar2 == '\x01') {
      if (bVar1 != 0x15) {
        uVar3 = *(uint *)(param_1 + 0x106c + (ulonglong)param_4 * 4);
        if (uVar3 < 0xfffffffe) {
          *(uint *)(param_1 + 0x106c + (ulonglong)param_4 * 4) = uVar3 + 1;
          goto LAB_1c000b027;
        }
      }
      goto LAB_1c000b02c;
    }
  }
  else {
LAB_1c000b027:
    if (cVar2 == '\x01') {
LAB_1c000b02c:
      if (bVar1 == 0x18) {
        uVar3 = *(uint *)(param_1 + 0xfec + (ulonglong)param_4 * 4);
        if (uVar3 < 0xfffffffe) {
          *(uint *)(param_1 + 0xfec + (ulonglong)param_4 * 4) = uVar3 + 1;
        }
      }
    }
  }
  if ((param_2 < 0x40) && ((0xc000050000000500U >> (uVar5 & 0x3f) & 1) != 0)) {
LAB_1c000b083:
    if (cVar2 == '\x01') goto LAB_1c000b091;
  }
  else if (cVar2 == '\x01') {
    if (bVar1 != 0x17) goto LAB_1c000b091;
    uVar3 = *(uint *)(param_1 + 0x102c + (ulonglong)param_4 * 4);
    if (0xfffffffd < uVar3) {
      return;
    }
    *(uint *)(param_1 + 0x102c + (ulonglong)param_4 * 4) = uVar3 + 1;
    goto LAB_1c000b083;
  }
  if (1 < (byte)(cVar2 - 3U)) {
    return;
  }
LAB_1c000b091:
  if (bVar1 == 0x15) {
    uVar3 = *(uint *)(param_1 + 0x10ac + (ulonglong)param_4 * 4);
    if (uVar3 < 0xfffffffe) {
      *(uint *)(param_1 + 0x10ac + (ulonglong)param_4 * 4) = uVar3 + 1;
    }
  }
  return;
}



===== SendCompaqTaskMgmtMsg @ 1c000b0c0 =====

bool SendCompaqTaskMgmtMsg(longlong param_1,longlong param_2)

{
  bool bVar1;
  
  *(undefined4 *)(param_2 + 8) = 0xc0ffaf;
  *(undefined1 *)(param_2 + 3) = 1;
  *(undefined1 *)(param_1 + 0xf40) = *(undefined1 *)(param_2 + 5);
  if (((*(char *)(param_2 + 5) == '\x04') && ((*(ushort *)(param_1 + 0x134) & 0x100) != 0)) &&
     (*(short *)(param_1 + 0x1b6) == 0)) {
    *(undefined1 *)(param_2 + 7) = 2;
  }
  StorPortPause(param_1,300);
  *(undefined4 *)(param_1 + 0x1c0) = 7;
  bVar1 = SendMessageViaHandShake(param_1,1,0xd);
  if (!bVar1) {
    *(undefined1 *)(param_1 + 0xf40) = 0;
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    StorPortResume(param_1);
  }
  return bVar1;
}



===== CompaqCompleteSDP3Read @ 1c000b158 =====

void CompaqCompleteSDP3Read(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x1188);
  lVar3 = *(longlong *)(lVar2 + 0x18);
  if (*(short *)(param_2 + 0xe) == 0) {
    lVar4 = *(longlong *)(param_1 + 0x1180);
    bVar1 = *(byte *)(lVar3 + 0x22);
    uVar5 = 0xffffffff;
    if (*(ushort *)(lVar4 + 8) == 0xffff) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = (uint)*(ushort *)(lVar4 + 8);
    }
    *(uint *)(lVar3 + 0x48) = uVar6;
    if (*(ushort *)(lVar4 + 6) == 0xffff) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = (uint)*(ushort *)(lVar4 + 6);
    }
    *(uint *)(lVar3 + 0x4c) = uVar6;
    if (*(ushort *)(lVar4 + 4) != 0xffff) {
      uVar5 = (uint)*(ushort *)(lVar4 + 4);
    }
    *(uint *)(lVar3 + 0x54) = uVar5;
    *(undefined4 *)(lVar3 + 0x50) = *(undefined4 *)(param_1 + 0x112c + (ulonglong)bVar1 * 4);
    if (*(int *)(lVar3 + 0x10) == 6) {
      *(undefined4 *)(lVar4 + 6) = 0;
      *(undefined2 *)(lVar4 + 4) = 0;
      *(undefined4 *)(param_1 + 0x112c + (ulonglong)bVar1 * 4) = 0;
      *(undefined1 *)(param_1 + 0xd62) = 0xc3;
      SendConfigPageMessage
                (param_1,'\x02',(undefined4 *)(param_1 + 0x117c),(uint)bVar1,
                 (int)*(undefined8 *)(param_1 + 0x1180));
    }
  }
  else {
    *(undefined4 *)(lVar3 + 0x14) = 1;
  }
  *(undefined2 *)(lVar2 + 3) = 1;
  StorPortNotification(0,param_1,lVar2);
  *(undefined1 *)(param_1 + 0x6a1) = 0;
  return;
}



===== CompaqCheckOutstandingTmRequest @ 1c000b258 =====

void CompaqCheckOutstandingTmRequest(longlong param_1)

{
  bool bVar1;
  longlong lVar2;
  undefined4 local_res8;
  
  if (*(char *)(param_1 + 0x134) < '\0') {
    memset((undefined1 *)(param_1 + 0x200),0,0x28);
    *(undefined8 *)(param_1 + 0x280) = 0;
    *(undefined8 *)(param_1 + 0x288) = 0;
    *(undefined8 *)(param_1 + 0x290) = 0;
    *(undefined1 *)(param_1 + 0x200) = 1;
    *(undefined1 *)(param_1 + 0x203) = 4;
    *(undefined4 *)(param_1 + 0x214) = **(undefined4 **)(param_1 + 0xe40);
    *(uint *)(param_1 + 0x21c) = (uint)*(byte *)(param_1 + 0x215) * 4 + -0x2f000000;
    *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0xe40) - *(int *)(param_1 + 0x58);
    bVar1 = SendMessageViaHandShake(param_1,0,10);
    if (((!bVar1) || (lVar2 = ReceiveDataViaHandshake(param_1,0xc), (char)lVar2 == '\0')) ||
       (*(short *)(param_1 + 0x28e) != 0)) goto LAB_1c000b30d;
    *(undefined1 *)(param_1 + 0xf41) = *(undefined1 *)(*(longlong *)(param_1 + 0xe40) + 0xb);
  }
  else {
LAB_1c000b30d:
    *(undefined1 *)(param_1 + 0xf41) = 0xff;
  }
  lVar2 = 0;
  if (*(longlong *)(param_1 + 0x1190) != 0) {
    local_res8 = 6;
    lVar2 = *(longlong *)(param_1 + 0x1190);
  }
  if (*(longlong *)(param_1 + 0x1198) != 0) {
    if (lVar2 != 0) goto LAB_1c000b34f;
    local_res8 = 7;
    lVar2 = *(longlong *)(param_1 + 0x1198);
  }
  if (lVar2 == 0) {
    return;
  }
LAB_1c000b34f:
  *(undefined2 *)(lVar2 + 3) = 9;
  *(undefined4 *)(*(longlong *)(lVar2 + 0x18) + 0x14) = local_res8;
  StorPortNotification(0,param_1);
  **(undefined4 **)(param_1 + 0x10) = 0x40000000;
  LOCK();
  UNLOCK();
  SymWaitForResponse(param_1);
  SynchronizeOtherChannelRestart(param_1);
  *(undefined8 *)(param_1 + 0x1190) = 0;
  *(undefined8 *)(param_1 + 0x1198) = 0;
  return;
}



===== HpCsmiSASIOCTLRequest @ 1c000b3a8 =====

undefined8 HpCsmiSASIOCTLRequest(longlong param_1,void *param_2,char *param_3)

{
  uint uVar1;
  longlong lVar2;
  ushort uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 uVar10;
  undefined1 uVar9;
  byte bVar11;
  undefined1 *puVar12;
  bool bVar13;
  undefined1 local_res8 [8];
  undefined1 local_res10 [8];
  uint local_res18 [2];
  int local_res20;
  undefined1 local_res27;
  
  lVar2 = *(longlong *)((longlong)param_2 + 0x18);
  uVar10 = 1;
  uVar9 = 1;
  *param_3 = '\x01';
  *(undefined4 *)(lVar2 + 0x14) = 0;
  *(void **)(param_1 + 0x6a8) = param_2;
  memcpy((void *)(param_1 + 0x6b8),param_2,0x40);
  *(undefined1 *)(param_1 + 0x6a3) = *(undefined1 *)((longlong)param_2 + 5);
  uVar1 = *(uint *)(lVar2 + 0x10);
  if (uVar1 < 0x17) {
    if (uVar1 == 0x16) {
      bVar11 = 0;
      do {
        if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
          return 0;
        }
        bVar11 = bVar11 + 1;
      } while (bVar11 < 7);
      if (0x13 < *(uint *)(lVar2 + 0x18)) {
        lVar7 = param_1;
        uVar4 = IsHpIoctlBusy(param_1);
        if ((char)uVar4 != '\0') goto LAB_1c000bc65;
        *(longlong *)(param_1 + 0x1308) = lVar2;
        *(undefined1 *)(param_1 + 0x131f) = 1;
        *(void **)(param_1 + 0x1310) = param_2;
        *(undefined1 *)(param_1 + 0x6a1) = 1;
        uVar4 = HpSasGetLinkErrors(lVar7);
        goto LAB_1c000b49a;
      }
    }
    else if (uVar1 < 0xc) {
      if (uVar1 == 0xb) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMIARY"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0xab < *(uint *)(lVar2 + 0x18)) {
          lVar7 = param_1;
          uVar4 = IsHpIoctlBusy(param_1);
          if ((char)uVar4 != '\0') goto LAB_1c000bc65;
          *(longlong *)(param_1 + 0x1308) = lVar2;
          *(undefined1 *)(param_1 + 0x1323) = 1;
          *(void **)(param_1 + 0x1310) = param_2;
          *(undefined1 *)(param_1 + 0x6a1) = 1;
          uVar4 = HpSasGetRaidConfig(lVar7);
          goto LAB_1c000b49a;
        }
      }
      else if (uVar1 == 1) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMIALL"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0xad < *(uint *)(lVar2 + 0x18)) {
          memcpy((void *)(lVar2 + 0x1c),drvFileName,0xc);
          memcpy((void *)(lVar2 + 0x6d),drvDesc,0x24);
          uVar4 = 0;
          *(undefined4 *)(lVar2 + 0xbe) = 0x220001;
          *(undefined4 *)(lVar2 + 0xc2) = 0x530003;
          *(undefined4 *)(lVar2 + 0xc6) = 0x5a0000;
          uVar9 = uVar10;
          goto LAB_1c000be92;
        }
      }
      else if (uVar1 == 2) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMIALL"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0xb3 < *(uint *)(lVar2 + 0x18)) {
          *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(param_1 + 0xf48);
          *(undefined4 *)(lVar2 + 0x20) = *(undefined4 *)(param_1 + 0xf4c);
          *(undefined4 *)(lVar2 + 0x24) = *(undefined4 *)(param_1 + 0xf50);
          *(int *)(lVar2 + 0x28) = *(int *)(param_1 + 0x2f0) * 0x10000 + *(int *)(param_1 + 0x2f4);
          *(undefined2 *)(lVar2 + 0x2c) = *(undefined2 *)(param_1 + 0xf42);
          *(undefined2 *)(lVar2 + 0x2e) = 0x305;
          *(char *)(lVar2 + 0x30) = (char)((uint)*(undefined4 *)(param_1 + 0x328) >> 8);
          *(byte *)(lVar2 + 0x31) = *(byte *)(param_1 + 0x328) & 0x1f;
          *(byte *)(lVar2 + 0x32) = (byte)(*(uint *)(param_1 + 0x328) >> 5) & 7;
          memcpy((void *)(lVar2 + 0x50),(void *)(param_1 + 0x116c),0x10);
          *(ushort *)(lVar2 + 0xa2) = (ushort)*(byte *)(param_1 + 0x2ff);
          *(ushort *)(lVar2 + 0xa4) = *(ushort *)(param_1 + 0x2fe) & 0xff;
          *(ushort *)(lVar2 + 0xa6) = (ushort)((uint)*(undefined4 *)(param_1 + 0x2fc) >> 8) & 0xff;
          *(ushort *)(lVar2 + 0xa8) = *(ushort *)(param_1 + 0x2fc) & 0xff;
          *(ushort *)(lVar2 + 0xaa) = (ushort)*(byte *)(param_1 + 0x303);
          *(ushort *)(lVar2 + 0xac) = *(ushort *)(param_1 + 0x302) & 0xff;
          *(ushort *)(lVar2 + 0xae) = (ushort)((uint)*(undefined4 *)(param_1 + 0x300) >> 8) & 0xff;
          uVar3 = *(ushort *)(param_1 + 0x300);
          *(undefined4 *)(lVar2 + 0xb4) = 0x20001;
          *(ushort *)(lVar2 + 0xb0) = uVar3 & 0xff;
          uVar3 = *(ushort *)(param_1 + 0x134) & 0x8000;
          uVar4 = (ulonglong)uVar3;
          uVar6 = *(undefined4 *)(lVar2 + 0xb4);
          if (uVar3 != 0) {
            uVar6 = 0x20003;
          }
          *(undefined4 *)(lVar2 + 0xb4) = uVar6;
          *(undefined8 *)(lVar2 + 0xb8) = 0;
          *(undefined8 *)(lVar2 + 0xc0) = 0;
          uVar9 = uVar10;
          goto LAB_1c000be92;
        }
      }
      else if (uVar1 == 3) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMIALL"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        uVar4 = 0;
        if (0x23 < *(uint *)(lVar2 + 0x18)) {
          if (*(int *)(param_1 + 0xf54) == 3) {
            *(undefined4 *)(lVar2 + 0x1c) = 3;
            *(undefined4 *)(lVar2 + 0x20) = 1;
            uVar9 = uVar10;
          }
          else {
            *(undefined4 *)(lVar2 + 0x1c) = 1;
            uVar9 = uVar10;
          }
          goto LAB_1c000be92;
        }
      }
      else if (uVar1 == 4) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMIALL"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0x2b < *(uint *)(lVar2 + 0x18)) {
          *(void **)(param_1 + 0x1310) = param_2;
          *(undefined1 *)(param_1 + 0x6a1) = 1;
          uVar5 = HpSasFirmwareDownload(param_1,(longlong)param_2);
          bVar13 = (char)uVar5 == '\0';
          uVar4 = CONCAT71((int7)((ulonglong)uVar5 >> 8),bVar13);
          *param_3 = bVar13;
          uVar9 = uVar10;
          goto LAB_1c000be92;
        }
      }
      else {
        uVar4 = (ulonglong)(uVar1 - 10);
        if (uVar1 - 10 != 0) goto LAB_1c000bceb;
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMIARY"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (99 < *(uint *)(lVar2 + 0x18)) {
          lVar7 = param_1;
          uVar4 = IsHpIoctlBusy(param_1);
          if ((char)uVar4 != '\0') goto LAB_1c000bc65;
          *(longlong *)(param_1 + 0x1308) = lVar2;
          *(undefined1 *)(param_1 + 0x1322) = 1;
          *(void **)(param_1 + 0x1310) = param_2;
          *(undefined1 *)(param_1 + 0x6a1) = 1;
          uVar4 = HpSasGetRaidInfo(lVar7);
          goto LAB_1c000b49a;
        }
      }
    }
    else if (uVar1 == 0xc) {
      bVar11 = 0;
      do {
        if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMIARY"[bVar11]) {
          return 0;
        }
        bVar11 = bVar11 + 1;
      } while (bVar11 < 7);
      if (0x4a3 < *(uint *)(lVar2 + 0x18)) {
        lVar7 = param_1;
        uVar4 = IsHpIoctlBusy(param_1);
        if ((char)uVar4 != '\0') goto LAB_1c000bc65;
        *(longlong *)(param_1 + 0x1308) = lVar2;
        *(void **)(param_1 + 0x1310) = param_2;
        *(undefined1 *)(param_1 + 0x6a1) = 1;
        uVar4 = HpSasGetRaidFeatures(lVar7);
LAB_1c000b49a:
        *param_3 = '\0';
        uVar9 = uVar10;
        goto LAB_1c000be92;
      }
    }
    else if (uVar1 == 0xd) {
      bVar11 = 0;
      do {
        if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMIARY"[bVar11]) {
          return 0;
        }
        bVar11 = bVar11 + 1;
      } while (bVar11 < 7);
      if (0xcb < *(uint *)(lVar2 + 0x18)) {
        lVar7 = param_1;
        uVar4 = IsHpIoctlBusy(param_1);
        if ((char)uVar4 != '\0') goto LAB_1c000bc65;
        *(longlong *)(param_1 + 0x1308) = lVar2;
        *(void **)(param_1 + 0x1310) = param_2;
        *(undefined1 *)(param_1 + 0x6a1) = 1;
        uVar4 = HpSasSetRaidControl(lVar7);
        goto LAB_1c000b49a;
      }
    }
    else if (uVar1 == 0x14) {
      bVar11 = 0;
      do {
        if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
          return 0;
        }
        bVar11 = bVar11 + 1;
      } while (bVar11 < 7);
      if (0x803 < *(uint *)(lVar2 + 0x18)) {
        lVar7 = param_1;
        uVar4 = IsHpIoctlBusy(param_1);
        if ((char)uVar4 != '\0') goto LAB_1c000bc65;
        *(longlong *)(param_1 + 0x1308) = lVar2;
        *(undefined1 *)(param_1 + 0x131c) = 1;
        *(void **)(param_1 + 0x1310) = param_2;
        *(undefined1 *)(param_1 + 0x6a1) = 1;
        uVar4 = HpSasGetPhyInfo(lVar7);
        goto LAB_1c000b49a;
      }
    }
    else {
      uVar4 = (ulonglong)(uVar1 - 0x15);
      if (uVar1 - 0x15 != 0) goto LAB_1c000bceb;
      bVar11 = 0;
      do {
        if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
          return 0;
        }
        bVar11 = bVar11 + 1;
      } while (bVar11 < 7);
      if (7 < *(uint *)(lVar2 + 0x18)) {
        lVar7 = param_1;
        uVar4 = IsHpIoctlBusy(param_1);
        if ((char)uVar4 != '\0') goto LAB_1c000bc65;
        *(longlong *)(param_1 + 0x1308) = lVar2;
        *(undefined1 *)(param_1 + 0x131e) = 1;
        *(void **)(param_1 + 0x1310) = param_2;
        *(undefined1 *)(param_1 + 0x6a1) = 1;
        uVar4 = HpSasSetPhyInfo(lVar7);
        goto LAB_1c000b49a;
      }
    }
LAB_1c000b6fb:
    uVar4 = 0;
    *(undefined4 *)(lVar2 + 0x14) = 3;
    uVar9 = uVar10;
  }
  else {
    if (0x1c < uVar1) {
      if (uVar1 == 0x1d) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0x127 < *(uint *)(lVar2 + 0x18)) {
          *(undefined1 *)(param_1 + 0x6a1) = 1;
          uVar4 = HpPerformTaskManagement(param_1,(ulonglong)param_2);
          *param_3 = (char)uVar4 == '\0';
          uVar9 = uVar10;
          goto LAB_1c000be92;
        }
      }
      else if (uVar1 == 0x1e) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if ((uint)*(byte *)(*(longlong *)(param_1 + 0x12b0) + 0xc) * 0x24 <= *(uint *)(lVar2 + 0x18)
           ) {
          lVar7 = param_1;
          uVar4 = IsHpIoctlBusy(param_1);
          if ((char)uVar4 != '\0') goto LAB_1c000bc65;
          *(longlong *)(param_1 + 0x1308) = lVar2;
          *(undefined1 *)(param_1 + 0x131d) = 1;
          *(void **)(param_1 + 0x1310) = param_2;
          *(undefined1 *)(param_1 + 0x6a1) = 1;
          uVar4 = HpSasGetConnectorInfo(lVar7);
          goto LAB_1c000b49a;
        }
      }
      else if (uVar1 == 0x1f) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0x67 < *(uint *)(lVar2 + 0x18)) {
          lVar7 = param_1;
          uVar4 = IsHpIoctlBusy(param_1);
          if ((char)uVar4 != '\0') goto LAB_1c000bc65;
          *(longlong *)(param_1 + 0x1308) = lVar2;
          *(undefined1 *)(param_1 + 0x1325) = 1;
          *(void **)(param_1 + 0x1310) = param_2;
          *(undefined1 *)(param_1 + 0x6a1) = 1;
          uVar4 = HpSasGetLocation(lVar7);
          goto LAB_1c000b49a;
        }
      }
      else {
        uVar4 = (ulonglong)(uVar1 - 0x3c);
        if (uVar1 - 0x3c != 0) {
LAB_1c000bceb:
          *(undefined4 *)(lVar2 + 0x14) = 2;
          uVar9 = 0;
          goto LAB_1c000be92;
        }
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMIPHY"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0x3b < *(uint *)(lVar2 + 0x18)) {
          lVar7 = param_1;
          uVar4 = IsHpIoctlBusy(param_1);
          if ((char)uVar4 != '\0') goto LAB_1c000bc65;
          *(longlong *)(param_1 + 0x1308) = lVar2;
          *(undefined1 *)(param_1 + 0x1324) = 1;
          *(void **)(param_1 + 0x1310) = param_2;
          *(undefined1 *)(param_1 + 0x6a1) = 1;
          uVar4 = HpSasPhyControl(lVar7);
          goto LAB_1c000b49a;
        }
      }
      goto LAB_1c000b6fb;
    }
    if (uVar1 != 0x1c) {
      if (uVar1 == 0x17) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0x80f < *(uint *)(lVar2 + 0x18)) {
          *(undefined1 *)(param_1 + 0x6a1) = 1;
          uVar4 = HPSendSMPPassThrough(param_1,param_2);
          if ((char)uVar4 != '\0') goto LAB_1c000bbbd;
          goto LAB_1c000bc65;
        }
      }
      else if (uVar1 == 0x18) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0x47 < *(uint *)(lVar2 + 0x18)) {
          *(undefined1 *)(param_1 + 0x131a) = 1;
          *(void **)(param_1 + 0x1310) = param_2;
          *(undefined1 *)(param_1 + 0x6a1) = 1;
          uVar4 = HpSasSendSspPassThrough(param_1);
LAB_1c000bbbd:
          *param_3 = '\0';
          goto LAB_1c000be9e;
        }
      }
      else if (uVar1 == 0x19) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0x2b < *(uint *)(lVar2 + 0x18)) {
          *(undefined1 *)(param_1 + 0x131b) = 1;
          *(void **)(param_1 + 0x1310) = param_2;
          *(undefined1 *)(param_1 + 0x6a1) = 1;
          uVar4 = HpSasSendStpPassThrough(param_1);
          goto LAB_1c000bbbd;
        }
      }
      else if (uVar1 == 0x1a) {
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0x17 < *(uint *)(lVar2 + 0x18)) {
          lVar7 = param_1;
          uVar4 = IsHpIoctlBusy(param_1);
          if ((char)uVar4 == '\0') {
            *(longlong *)(param_1 + 0x1308) = lVar2;
            *(undefined1 *)(param_1 + 0x1320) = 1;
            *(void **)(param_1 + 0x1310) = param_2;
            *(undefined1 *)(param_1 + 0x6a1) = 1;
            uVar4 = HpSasGetSataSignature(lVar7);
            goto LAB_1c000b49a;
          }
          goto LAB_1c000bc65;
        }
      }
      else {
        uVar4 = (ulonglong)(uVar1 - 0x1b);
        if (uVar1 - 0x1b != 0) goto LAB_1c000bceb;
        bVar11 = 0;
        do {
          if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
            return 0;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 7);
        if (0x13 < *(uint *)(lVar2 + 0x18)) {
          uVar4 = IsHpIoctlBusy(param_1);
          if ((char)uVar4 == '\0') {
            *(longlong *)(param_1 + 0x1308) = lVar2;
            puVar8 = &local_res27;
            *(undefined1 *)(param_1 + 0x6a1) = 1;
            puVar12 = (undefined1 *)(lVar2 + 0x1c);
            lVar7 = 8;
            do {
              uVar9 = *puVar12;
              puVar12 = puVar12 + 1;
              *puVar8 = uVar9;
              puVar8 = puVar8 + -1;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            uVar4 = FindScsiAddressFromSas
                              (param_1,local_res8,local_res10,&local_res20,(int *)local_res18);
            if ((char)uVar4 == '\0') {
              *(undefined4 *)(lVar2 + 0x14) = 0x7dd;
              uVar9 = uVar10;
            }
            else {
              uVar4 = (ulonglong)local_res18[0] & 0xffffffffffffff07;
              if ((char)uVar4 == '\x01') {
                *(undefined1 *)(lVar2 + 0x2d) = local_res8[0];
                *(undefined1 *)(lVar2 + 0x2e) = local_res10[0];
                *(undefined4 *)(lVar2 + 0x14) = 0;
                *(undefined1 *)(lVar2 + 0x2c) = 0xff;
                uVar4 = CONCAT71((int7)(uVar4 >> 8),*(undefined1 *)(lVar2 + 0x25));
                *(undefined1 *)(lVar2 + 0x2f) = *(undefined1 *)(lVar2 + 0x25);
                uVar9 = uVar10;
              }
              else {
                *(undefined4 *)(lVar2 + 0x14) = 0x7dc;
                uVar9 = uVar10;
              }
            }
            goto LAB_1c000be92;
          }
          goto LAB_1c000bc65;
        }
      }
      goto LAB_1c000b6fb;
    }
    bVar11 = 0;
    do {
      if (*(char *)((ulonglong)bVar11 + 4 + lVar2) != "CSMISAS"[bVar11]) {
        return 0;
      }
      bVar11 = bVar11 + 1;
    } while (bVar11 < 7);
    if (*(uint *)(lVar2 + 0x18) < 0x14) goto LAB_1c000b6fb;
    lVar7 = param_1;
    uVar4 = IsHpIoctlBusy(param_1);
    if ((char)uVar4 == '\0') {
      *(longlong *)(param_1 + 0x1308) = lVar2;
      *(undefined1 *)(param_1 + 0x1321) = 1;
      *(void **)(param_1 + 0x1310) = param_2;
      *(undefined1 *)(param_1 + 0x6a1) = 1;
      uVar4 = HpSasGetDeviceAddress(lVar7);
      goto LAB_1c000b49a;
    }
LAB_1c000bc65:
    *(undefined4 *)(lVar2 + 0x14) = 1;
    uVar9 = uVar10;
  }
LAB_1c000be92:
  if (*param_3 != '\0') {
    *(undefined1 *)(param_1 + 0x6a1) = 0;
  }
LAB_1c000be9e:
  return CONCAT71((int7)(uVar4 >> 8),uVar9);
}



===== IsHpIoctlBusy @ 1c000beb4 =====

undefined8 IsHpIoctlBusy(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (((((*(char *)(param_1 + 0x131a) != '\0') || (*(char *)(param_1 + 0x131b) != '\0')) ||
       (*(char *)(param_1 + 0x131c) != '\0')) ||
      ((((*(char *)(param_1 + 0x131e) != '\0' || (*(char *)(param_1 + 0x131f) != '\0')) ||
        ((*(char *)(param_1 + 0x1320) != '\0' ||
         ((*(char *)(param_1 + 0x1321) != '\0' || (*(char *)(param_1 + 0x131d) != '\0')))))) ||
       (*(char *)(param_1 + 0x1322) != '\0')))) ||
     (((*(char *)(param_1 + 0x1323) != '\0' || (*(char *)(param_1 + 0x1324) != '\0')) ||
      (*(char *)(param_1 + 0x1325) != '\0')))) {
    uVar1 = 1;
  }
  return uVar1;
}



===== HPSendSMPPassThrough @ 1c000bf1c =====

ulonglong HPSendSMPPassThrough(longlong param_1,void *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  longlong *plVar6;
  undefined8 uVar7;
  void *pvVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  byte bVar11;
  int iVar12;
  longlong lVar13;
  undefined1 *_Dst;
  undefined4 *puVar14;
  uint *puVar15;
  uint local_res10 [2];
  
  lVar3 = *(longlong *)((longlong)param_2 + 0x18);
  lVar4 = *(longlong *)((longlong)param_2 + 0x38);
  uVar2 = *(uint *)(lVar3 + 0x28);
  local_res10[0] = uVar2 + 0x3fc;
  plVar6 = (longlong *)(ulonglong)local_res10[0];
  if (((local_res10[0] <= *(uint *)(lVar3 + 0x18)) && (uVar2 < 0x10000)) && (local_res10[0] != 0)) {
    if (*(char *)(lVar3 + 0x1d) == -1) {
      *(undefined4 *)(lVar3 + 0x14) = 0x7d5;
    }
    else {
      *(undefined4 *)(lVar3 + 0x14) = 0;
      plVar6 = *(longlong **)(param_1 + 0x158);
      if (*(longlong *)(*plVar6 + 8) == 0) {
        _Dst = (undefined1 *)(lVar4 + 0x138);
        uVar5 = StorPortGetPhysicalAddress(param_1,param_2,_Dst,local_res10);
        memset(_Dst,0,0x2c);
        puVar9 = (undefined1 *)(lVar4 + 0x14f);
        *(undefined1 *)(lVar4 + 0x139) = *(undefined1 *)(lVar3 + 0x1d);
        puVar10 = (undefined1 *)(lVar3 + 0x20);
        *(undefined1 *)(lVar4 + 0x13b) = 0x1a;
        lVar13 = 8;
        *(undefined2 *)(lVar4 + 0x13c) = *(undefined2 *)(lVar3 + 0x28);
        *(undefined1 *)(lVar4 + 0x13e) = *(undefined1 *)(lVar3 + 0x1e);
        *(undefined4 *)(lVar4 + 0x140) = 0x80ffeed;
        *(undefined4 *)(param_1 + 0x32c) = 0xc0534d50;
        do {
          uVar1 = *puVar10;
          puVar10 = puVar10 + 1;
          *puVar9 = uVar1;
          puVar9 = puVar9 + -1;
          lVar13 = lVar13 + -1;
        } while (lVar13 != 0);
        if ((*(ushort *)(param_1 + 300) - 0x38 < uVar2) ||
           (*(ushort *)(param_1 + 0x12a) - 0x20 < 0x3fc)) {
          puVar15 = (uint *)(lVar4 + 0x158);
          if (uVar2 != 0) {
            bVar11 = *(byte *)(param_1 + 0x134) & 1;
            iVar12 = 0x54;
            if (bVar11 != 0) {
              iVar12 = 0x56;
            }
            uVar7 = StorPortGetPhysicalAddress(param_1,param_2,lVar3 + 0x2c,local_res10);
            local_res10[0] = *(uint *)(lVar3 + 0x28) & 0xffff;
            *puVar15 = iVar12 << 0x18 | local_res10[0];
            puVar14 = (undefined4 *)(lVar4 + 0x15c);
            *puVar14 = (int)uVar7;
            if (bVar11 != 0) {
              puVar14 = (undefined4 *)(lVar4 + 0x160);
              *puVar14 = (int)((ulonglong)uVar7 >> 0x20);
            }
            puVar15 = puVar14 + 1;
          }
          bVar11 = *(byte *)(param_1 + 0x134) & 1;
          iVar12 = 0x50;
          if (bVar11 != 0) {
            iVar12 = 0x52;
          }
          uVar7 = StorPortGetPhysicalAddress(param_1,param_2,lVar3 + 0x430,local_res10);
          *puVar15 = iVar12 << 0x18 | local_res10[0];
          puVar15[1] = (uint)uVar7;
          if (bVar11 != 0) {
            puVar15[2] = (uint)((ulonglong)uVar7 >> 0x20);
          }
        }
        else {
          *_Dst = 0x80;
          memcpy((void *)(lVar4 + 0x158),(void *)(lVar3 + 0x2c),(ulonglong)uVar2);
        }
        *(undefined4 *)((longlong)param_2 + 0x10) = 8;
        memcpy((void *)(param_1 + 0x6b8),param_2,0x40);
        pvVar8 = memcpy(*(void **)(param_1 + 0x6f8),_Dst,(ulonglong)*(ushort *)(param_1 + 300));
        **(undefined4 **)(param_1 + 0x38) = uVar5;
        LOCK();
        UNLOCK();
        return CONCAT71((int7)((ulonglong)pvVar8 >> 8),1);
      }
    }
  }
  return (ulonglong)plVar6 & 0xffffffffffffff00;
}



===== HpSasSendSspPassThrough @ 1c000c150 =====

void HpSasSendSspPassThrough(longlong param_1)

{
  undefined1 uVar1;
  uint uVar2;
  void *_Src;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  byte bVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  char cVar10;
  undefined1 *puVar11;
  uint *_Dst;
  longlong lVar12;
  longlong lVar13;
  char local_res10 [8];
  char local_res18 [8];
  char local_res20;
  int iVar14;
  uint local_68;
  int local_64;
  undefined4 local_60;
  undefined1 local_5c [4];
  int local_58;
  undefined1 local_51 [17];
  
  _Src = *(void **)(param_1 + 0x1310);
  bVar4 = false;
  lVar3 = *(longlong *)((longlong)_Src + 0x18);
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x131a) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else {
    do {
      cVar10 = *(char *)(param_1 + 0x131a);
      bVar5 = false;
      if (cVar10 == '\0') {
LAB_1c000c4eb:
        bVar5 = false;
LAB_1c000c4ee:
        if (bVar4) goto LAB_1c000c4f3;
      }
      else {
        if (cVar10 == '\x01') {
          if ((*(char *)(lVar3 + 0x1c) == -1) && (*(char *)(lVar3 + 0x1d) == -1)) {
            *(undefined4 *)(lVar3 + 0x14) = 0x7d5;
          }
          else {
            if (*(int *)(lVar3 + 0x60) + 0x154U <= *(uint *)(lVar3 + 0x18)) {
              if ((*(ushort *)(param_1 + 0x134) & 0x8000) != 0) {
                *(undefined1 *)(param_1 + 0x131a) = 3;
                cVar10 = '\0';
                local_68 = 0x1030000;
                iVar14 = 0;
                goto LAB_1c000c4dc;
              }
              *(undefined1 *)(param_1 + 0x131a) = 4;
              bVar5 = true;
              goto LAB_1c000c4ee;
            }
LAB_1c000c247:
            *(undefined4 *)(lVar3 + 0x14) = 3;
          }
        }
        else {
          if (cVar10 != '\x03') {
            if (cVar10 != '\x04') {
              bVar5 = false;
              if (cVar10 == -0x10) {
                *(undefined1 *)(param_1 + 0x131a) = 0;
                *(undefined2 *)((longlong)_Src + 3) = 1;
                StorPortNotification(0,param_1,_Src);
                *(undefined1 *)(param_1 + 0x6a1) = 0;
                *(undefined8 *)(param_1 + 0x1310) = 0;
                return;
              }
              goto LAB_1c000c4ee;
            }
            puVar9 = local_51;
            lVar12 = 8;
            puVar11 = (undefined1 *)(lVar3 + 0x20);
            do {
              uVar1 = *puVar11;
              puVar11 = puVar11 + 1;
              *puVar9 = uVar1;
              puVar9 = puVar9 + -1;
              lVar12 = lVar12 + -1;
            } while (lVar12 != 0);
            uVar8 = FindScsiAddressFromSas(param_1,local_res18,local_res10,&local_58,&local_64);
            if ((char)uVar8 == '\0') goto LAB_1c000c247;
            if (local_64 == 0) {
              *(undefined4 *)(lVar3 + 0x14) = 3;
            }
            local_res20 = '\0';
            if ((*(ushort *)(param_1 + 0x134) & 0x8000) != 0) {
              lVar12 = *(longlong *)(param_1 + 0xd90);
              if (*(byte *)(lVar12 + 4) != 0) {
                uVar8 = 0;
                do {
                  if ((*(char *)(lVar12 + 8 + uVar8 * 4) == local_res10[0]) &&
                     (*(char *)(lVar12 + 9 + uVar8 * 4) == local_res18[0])) {
                    *(undefined1 *)(param_1 + 0xeb8) = *(undefined1 *)(lVar12 + 0xb + uVar8 * 4);
                    local_res20 = '\x01';
                    break;
                  }
                  bVar6 = (char)uVar8 + 1;
                  uVar8 = (ulonglong)bVar6;
                } while (bVar6 < *(byte *)(lVar12 + 4));
              }
            }
            if (*(longlong *)(**(longlong **)(param_1 + 0x158) + 8) != 0) goto LAB_1c000c24f;
            lVar12 = *(longlong *)((longlong)_Src + 0x38);
            _Dst = (uint *)(lVar12 + 0x138);
            uVar7 = StorPortGetPhysicalAddress(param_1,_Src,_Dst,local_5c);
            if (*(ushort *)(param_1 + 300) != 0) {
              memset(_Dst,0,(ulonglong)*(ushort *)(param_1 + 300));
            }
            *(char *)_Dst = local_res10[0];
            puVar9 = (undefined1 *)(lVar12 + 0x144);
            *(char *)(lVar12 + 0x139) = local_res18[0];
            lVar13 = 8;
            *(undefined1 *)(lVar12 + 0x13b) = 0;
            *(undefined1 *)(lVar12 + 0x13c) = *(undefined1 *)(lVar3 + 0x30);
            do {
              *puVar9 = puVar9[(lVar3 + 0x1c) - (longlong)_Dst];
              puVar9 = puVar9 + 1;
              lVar13 = lVar13 + -1;
            } while (lVar13 != 0);
            uVar2 = *(uint *)(lVar3 + 0x44);
            if ((uVar2 & 1) == 0) {
              if ((uVar2 & 2) == 0) {
                if (((uVar2 & 4) == 0) || (*(int *)(lVar3 + 0x60) != 0)) {
                  *(undefined1 *)(lVar12 + 0x13f) = 4;
                  goto LAB_1c000c35f;
                }
                *(undefined4 *)(lVar12 + 0x14c) = 0;
              }
              else {
                *(undefined4 *)(lVar12 + 0x14c) = 0x1000000;
              }
            }
            else {
LAB_1c000c35f:
              *(undefined4 *)(lVar12 + 0x14c) = 0x2000000;
            }
            *(uint *)(lVar12 + 0x14c) = *(uint *)(lVar12 + 0x14c) | 0x500;
            *(undefined4 *)(lVar12 + 0x140) = 0x80ffeed;
            *(undefined4 *)(param_1 + 0x32c) = 0xc0535350;
            *(undefined1 *)(lVar12 + 0x13d) = 0xff;
            *(uint *)(lVar12 + 0x164) = uVar7 - 0x100;
            memcpy((void *)(lVar12 + 0x150),(void *)(lVar3 + 0x34),
                   (ulonglong)*(byte *)(lVar3 + 0x30));
            *(undefined4 *)(lVar12 + 0x160) = *(undefined4 *)(lVar3 + 0x60);
            local_60 = *(undefined4 *)((longlong)_Src + 0xc);
            *(uint *)((longlong)_Src + 0xc) = (*(uint *)(lVar3 + 0x44) & 3) << 6;
            *(undefined4 *)((longlong)_Src + 0x10) = *(undefined4 *)(lVar3 + 0x60);
            BuildScatterGather(param_1,(longlong)_Src,(int)lVar3 + 0x170,_Dst,uVar7);
            if (local_res20 != '\0') {
              *(undefined1 *)(lVar12 + 0x13b) = 0x16;
              *(undefined1 *)_Dst = *(undefined1 *)(param_1 + 0xeb8);
              *(undefined1 *)(lVar12 + 0x139) = 0;
            }
            *(undefined4 *)((longlong)_Src + 0xc) = local_60;
            *(int *)((longlong)_Src + 0x10) = *(int *)(lVar3 + 0x60) + 0x174;
            memcpy((void *)(param_1 + 0x6b8),_Src,0x40);
            memcpy(*(void **)(param_1 + 0x6f8),_Dst,(ulonglong)*(ushort *)(param_1 + 300));
            *(undefined1 *)(param_1 + 0x131a) = 0;
            **(uint **)(param_1 + 0x38) = uVar7;
            LOCK();
            UNLOCK();
            goto LAB_1c000c4ee;
          }
          *(undefined1 *)(param_1 + 0x131a) = 4;
          local_68 = *(uint *)(param_1 + 0xd98);
          if ((local_68 >> 8 & 0xff) * 4 <= *(uint *)(param_1 + 0xd8c)) {
            iVar14 = (int)*(undefined8 *)(param_1 + 0xd90);
            cVar10 = '\x01';
LAB_1c000c4dc:
            SendConfigPageMessage(param_1,cVar10,&local_68,0,iVar14);
            goto LAB_1c000c4eb;
          }
        }
LAB_1c000c24f:
        bVar4 = true;
LAB_1c000c4f3:
        bVar5 = true;
        if (*(int *)(lVar3 + 0x14) == 0) {
          *(undefined4 *)(lVar3 + 0x14) = 1;
        }
        *(undefined1 *)(param_1 + 0x131a) = 0xf0;
      }
    } while (bVar5);
  }
  return;
}



===== HpSasSendStpPassThrough @ 1c000c518 =====

void HpSasSendStpPassThrough(longlong param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  void *_Src;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  longlong lVar10;
  uint *_Dst;
  undefined1 local_res8 [8];
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined1 local_res20 [8];
  int local_58;
  undefined1 local_51 [17];
  
  _Src = *(void **)(param_1 + 0x1310);
  bVar5 = false;
  lVar4 = *(longlong *)((longlong)_Src + 0x18);
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x131b) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
    return;
  }
  do {
    cVar1 = *(char *)(param_1 + 0x131b);
    if (cVar1 == '\0') {
LAB_1c000c774:
      if (!bVar5) {
        return;
      }
    }
    else {
      if (cVar1 != '\x01') {
        if (cVar1 == -0x10) {
          *(undefined1 *)(param_1 + 0x131b) = 0;
          *(undefined2 *)((longlong)_Src + 3) = 1;
          StorPortNotification(0,param_1,_Src);
          *(undefined1 *)(param_1 + 0x6a1) = 0;
          *(undefined8 *)(param_1 + 0x1310) = 0;
          return;
        }
        goto LAB_1c000c774;
      }
      if ((*(char *)(lVar4 + 0x1c) == -1) && (*(char *)(lVar4 + 0x1d) == -1)) {
        *(undefined4 *)(lVar4 + 0x14) = 0x7d5;
      }
      else {
        if (*(int *)(lVar4 + 0x44) + 0x88U <= *(uint *)(lVar4 + 0x18)) {
          puVar8 = local_51;
          lVar10 = 8;
          puVar9 = (undefined1 *)(lVar4 + 0x20);
          do {
            uVar2 = *puVar9;
            puVar9 = puVar9 + 1;
            *puVar8 = uVar2;
            puVar8 = puVar8 + -1;
            lVar10 = lVar10 + -1;
          } while (lVar10 != 0);
          uVar7 = FindScsiAddressFromSas
                            (param_1,local_res10,local_res8,&local_58,(int *)local_res18);
          if (((char)uVar7 != '\0') && ((local_res18[0] & 0x280) != 0)) {
            if (*(longlong *)(**(longlong **)(param_1 + 0x158) + 8) == 0) {
              lVar10 = *(longlong *)((longlong)_Src + 0x38);
              _Dst = (uint *)(lVar10 + 0x138);
              uVar6 = StorPortGetPhysicalAddress(param_1,_Src,_Dst,local_res20);
              if (*(ushort *)(param_1 + 300) != 0) {
                memset(_Dst,0,(ulonglong)*(ushort *)(param_1 + 300));
              }
              *(undefined1 *)_Dst = local_res8[0];
              *(undefined1 *)(lVar10 + 0x139) = local_res10[0];
              *(undefined1 *)(lVar10 + 0x13b) = 0x1c;
              *(undefined2 *)(lVar10 + 0x13c) = *(undefined2 *)(lVar4 + 0x40);
              *(undefined1 *)(lVar10 + 0x13e) = *(undefined1 *)(lVar4 + 0x1e);
              *(undefined4 *)(lVar10 + 0x140) = 0x80ffeed;
              *(undefined4 *)(param_1 + 0x32c) = 0xc0535450;
              *(undefined4 *)(lVar10 + 0x150) = *(undefined4 *)(lVar4 + 0x44);
              memcpy((void *)(lVar10 + 0x154),(void *)(lVar4 + 0x2c),0x14);
              uVar3 = *(undefined4 *)((longlong)_Src + 0xc);
              *(uint *)((longlong)_Src + 0xc) = (*(ushort *)(lVar10 + 0x13c) & 3) << 6;
              *(undefined4 *)((longlong)_Src + 0x10) = *(undefined4 *)(lVar10 + 0x150);
              BuildScatterGather(param_1,(longlong)_Src,(int)lVar4 + 0xa4,_Dst,uVar6);
              *(undefined4 *)((longlong)_Src + 0xc) = uVar3;
              *(undefined4 *)(lVar10 + 0x14c) = 0;
              *(int *)((longlong)_Src + 0x10) = *(int *)(lVar4 + 0x44) + 0xa8;
              memcpy((void *)(param_1 + 0x6b8),_Src,0x40);
              memcpy(*(void **)(param_1 + 0x6f8),_Dst,(ulonglong)*(ushort *)(param_1 + 300));
              *(undefined1 *)(param_1 + 0x131b) = 0;
              **(uint **)(param_1 + 0x38) = uVar6;
              LOCK();
              UNLOCK();
              goto LAB_1c000c774;
            }
            goto LAB_1c000c5c4;
          }
        }
        *(undefined4 *)(lVar4 + 0x14) = 3;
      }
LAB_1c000c5c4:
      bVar5 = true;
    }
    if (*(int *)(lVar4 + 0x14) == 0) {
      *(undefined4 *)(lVar4 + 0x14) = 1;
    }
    *(undefined1 *)(param_1 + 0x131b) = 0xf0;
  } while( true );
}



===== HpSasFirmwareDownload @ 1c000c798 =====

ulonglong HpSasFirmwareDownload(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  longlong *plVar6;
  void *pvVar7;
  byte bVar8;
  ulonglong uVar9;
  uint *_Dst;
  undefined1 local_res10 [8];
  
  lVar3 = *(longlong *)(param_2 + 0x18);
  lVar4 = *(longlong *)(param_2 + 0x38);
  uVar5 = *(int *)(lVar3 + 0x1c) + 0x2c;
  plVar6 = (longlong *)(ulonglong)uVar5;
  if ((*(uint *)(lVar3 + 0x18) < uVar5) ||
     (plVar6 = (longlong *)(ulonglong)*(uint *)(lVar3 + 0x20), (*(uint *)(lVar3 + 0x20) & 3) != 0))
  {
    *(undefined4 *)(lVar3 + 0x14) = 3;
  }
  else {
    if (((*(int *)(lVar3 + 0x4c) == 0x5aeaa55a) && (*(int *)(lVar3 + 0x50) == -0x5aa5155b)) &&
       (*(int *)(lVar3 + 0x54) == 0x5aa55aea)) {
      if ((*(int *)(param_1 + 0x1fc) == 0) &&
         (plVar6 = *(longlong **)(param_1 + 0x158), *(longlong *)(*plVar6 + 8) == 0)) {
        _Dst = (uint *)(lVar4 + 0x138);
        uVar5 = StorPortGetPhysicalAddress(param_1,param_2,_Dst,local_res10);
        if (*(ushort *)(param_1 + 300) != 0) {
          memset(_Dst,0,(ulonglong)*(ushort *)(param_1 + 300));
        }
        *(undefined1 *)_Dst = 1;
        *(undefined1 *)(lVar4 + 0x13b) = 9;
        *(undefined1 *)(lVar4 + 0x13f) = 1;
        *(undefined4 *)(lVar4 + 0x140) = 0x80ffeed;
        *(undefined1 *)(lVar4 + 0x146) = 0xc;
        *(undefined4 *)(lVar4 + 0x14c) = 0;
        *(undefined4 *)(lVar4 + 0x150) = *(undefined4 *)(lVar3 + 0x1c);
        *(undefined4 *)(param_1 + 0x32c) = 0xc0465744;
        uVar1 = *(undefined4 *)(param_2 + 0xc);
        uVar2 = *(undefined4 *)(param_2 + 0x10);
        *(undefined4 *)(param_2 + 0xc) = 0x80;
        *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(lVar3 + 0x1c);
        BuildScatterGather(param_1,param_2,(int)lVar3 + 0x48,_Dst,uVar5);
        *(undefined4 *)(param_2 + 0x10) = uVar2;
        *(undefined4 *)(param_2 + 0xc) = uVar1;
        *(undefined4 *)(lVar4 + 0x14c) = 0;
        uVar9 = 7;
        if (7 < *(uint *)(param_1 + 500)) {
          do {
            if ((int)uVar9 + 5U < (uint)*(byte *)(param_1 + 500)) {
              _Dst[uVar9] = *(uint *)(lVar4 + 0x14c + uVar9 * 4);
            }
            else {
              _Dst[uVar9] = 0;
            }
            bVar8 = (char)uVar9 + 1;
            uVar9 = (ulonglong)bVar8;
          } while ((uint)bVar8 < *(uint *)(param_1 + 500));
        }
        if (*(char *)(lVar4 + 0x13a) != '\0') {
          *(char *)(lVar4 + 0x13a) = *(char *)(lVar4 + 0x13a) + -5;
        }
        pvVar7 = memcpy(*(void **)(param_1 + 0x6f8),_Dst,(ulonglong)*(ushort *)(param_1 + 300));
        **(uint **)(param_1 + 0x38) = uVar5;
        LOCK();
        UNLOCK();
        return CONCAT71((int7)((ulonglong)pvVar7 >> 8),1);
      }
    }
    else {
      *(undefined2 *)(lVar3 + 0x44) = 3;
    }
    *(undefined4 *)(lVar3 + 0x14) = 1;
  }
  return (ulonglong)plVar6 & 0xffffffffffffff00;
}



===== HpSasGetPhyInfo @ 1c000c968 =====

void HpSasGetPhyInfo(longlong param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  undefined1 *puVar6;
  longlong lVar7;
  undefined1 *puVar8;
  char *pcVar9;
  uint uVar10;
  undefined1 *puVar11;
  longlong lVar12;
  byte bVar13;
  ulonglong uVar14;
  
  lVar3 = *(longlong *)(param_1 + 0x1308);
  puVar6 = (undefined1 *)(lVar3 + 0x1c);
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x131c) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
    return;
  }
LAB_1c000c9b0:
  while( true ) {
    bVar13 = *(byte *)(param_1 + 0x131c);
    if (0xf0 < bVar13) {
      return;
    }
    if (bVar13 == 0xf0) {
      *(undefined1 *)(param_1 + 0x131c) = 0;
      *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
      StorPortNotification(0,param_1);
      *(undefined8 *)(param_1 + 0x1310) = 0;
      *(undefined1 *)(param_1 + 0x6a1) = 0;
      return;
    }
    if (8 < bVar13) break;
    if (bVar13 == 8) {
      *(undefined1 *)(param_1 + 0x131c) = 9;
LAB_1c000cad9:
      *(undefined1 *)(param_1 + 0x1327) = 0;
    }
    else {
      if (bVar13 == 0) {
        return;
      }
      if (bVar13 == 1) {
        *(undefined1 *)(param_1 + 0x131c) = 2;
      }
      else {
        if (bVar13 == 2) {
          *(undefined1 *)(param_1 + 0x131c) = 3;
          pcVar9 = (char *)(param_1 + 0x1266);
          iVar4 = (int)*(undefined8 *)(param_1 + 0x12b0);
          uVar10 = 0;
          goto LAB_1c000cde2;
        }
        if (bVar13 == 3) {
          *(undefined1 *)(param_1 + 0x131c) = 0xc;
          uVar14 = 0;
          lVar5 = *(longlong *)(param_1 + 0x12b0);
          *puVar6 = *(undefined1 *)(lVar5 + 0xc);
          if (*(char *)(lVar5 + 0xc) != '\0') {
            do {
              lVar7 = uVar14 * 0x40;
              uVar10 = *(uint *)(uVar14 * 0x10 + 0x14 + lVar5);
              puVar6[lVar7 + 6] = 0;
              puVar6[lVar7 + 4] = 0x10;
              puVar6[lVar7 + 6] = (uVar10 & 8) != 0;
              if ((uVar10 & 0x10) != 0) {
                puVar6[lVar7 + 6] = puVar6[lVar7 + 6] | 2;
              }
              if ((uVar10 & 0x20) != 0) {
                puVar6[lVar7 + 6] = puVar6[lVar7 + 6] | 4;
              }
              if ((uVar10 & 0x40) != 0) {
                puVar6[lVar7 + 6] = puVar6[lVar7 + 6] | 8;
              }
              puVar6[lVar7 + 7] = 0;
              puVar6[lVar7 + 7] = (uVar10 & 0x80) != 0;
              if ((uVar10 >> 8 & 1) != 0) {
                puVar6[lVar7 + 7] = puVar6[lVar7 + 7] | 2;
              }
              if ((uVar10 >> 9 & 1) != 0) {
                puVar6[lVar7 + 7] = puVar6[lVar7 + 7] | 4;
              }
              if ((uVar10 >> 10 & 1) != 0) {
                puVar6[lVar7 + 7] = puVar6[lVar7 + 7] | 8;
              }
              bVar13 = (char)uVar14 + 1;
              uVar14 = (ulonglong)bVar13;
            } while (bVar13 < *(byte *)(lVar5 + 0xc));
          }
        }
        else {
          if (bVar13 == 4) {
            *(undefined1 *)(param_1 + 0x131c) = 5;
            goto LAB_1c000cad9;
          }
          if (bVar13 == 5) {
            *(undefined1 *)(param_1 + 0x131c) = 6;
            pcVar9 = (char *)(param_1 + 0x1296);
            uVar10 = (uint)*(byte *)(param_1 + 0x1327);
            iVar4 = (int)*(undefined8 *)(param_1 + 0x12e0);
            goto LAB_1c000cde2;
          }
          if (bVar13 == 6) {
            *(undefined1 *)(param_1 + 0x131c) = 7;
            lVar5 = *(longlong *)(param_1 + 0x12e0);
            lVar7 = (ulonglong)*(byte *)(param_1 + 0x1327) * 0x40;
            if (*(short *)(param_1 + 0xd64) != 0x22) {
              puVar6[lVar7 + 0x21] = *(byte *)(lVar5 + 0x20) & 0xf;
              puVar6[lVar7 + 0x22] = *(byte *)(lVar5 + 0x1d) & 0xf | *(char *)(lVar5 + 0x1c) << 4;
              puVar6[lVar7 + 0x23] = *(byte *)(lVar5 + 0x1d) & 0xf0 | *(byte *)(lVar5 + 0x1c) >> 4;
              puVar6[lVar7 + 0x24] = *(undefined1 *)(lVar5 + 0x1e);
              if ((*(uint *)(lVar5 + 0x20) >> 0xc & 1) != 0) {
                puVar6[lVar7 + 0x26] = 1;
              }
              puVar6[lVar7 + 0x3c] = *(undefined1 *)(lVar5 + 0x16);
            }
          }
          else {
            if (bVar13 != 7) {
              return;
            }
            if ((int)(uint)*(byte *)(param_1 + 0x1327) <
                (int)(*(byte *)(*(longlong *)(param_1 + 0x12b0) + 0xc) - 1)) {
              *(byte *)(param_1 + 0x1327) = *(byte *)(param_1 + 0x1327) + 1;
              *(undefined1 *)(param_1 + 0x131c) = 5;
            }
            else {
              *(undefined1 *)(param_1 + 0x131c) = 8;
            }
          }
        }
      }
    }
  }
  if (bVar13 == 9) {
    *(undefined1 *)(param_1 + 0x131c) = 10;
    uVar2 = *(ushort *)
             (*(longlong *)(param_1 + 0x12b0) + 0x18 + (ulonglong)*(byte *)(param_1 + 0x1327) * 0x10
             );
  }
  else {
    if (bVar13 == 10) {
      *(undefined1 *)(param_1 + 0x131c) = 0xb;
      if (*(short *)(param_1 + 0xd64) != 0x22) {
        lVar5 = *(longlong *)(param_1 + 0x12d0);
        lVar7 = (ulonglong)*(byte *)(param_1 + 0x1327) * 0x40;
        uVar10 = *(uint *)(lVar5 + 0x1c);
        bVar13 = (byte)uVar10 & 7;
        if ((uVar10 & 7) == 0) {
          puVar6[lVar7 + 0x28] = 0;
        }
        else if (bVar13 == 1) {
          puVar6[lVar7 + 0x28] = 0x10;
        }
        else if (bVar13 == 2) {
          puVar6[lVar7 + 0x28] = 0x20;
        }
        else if (bVar13 == 3) {
          puVar6[lVar7 + 0x28] = 0x30;
        }
        puVar6[lVar7 + 0x2a] = 0;
        puVar6[lVar7 + 0x2a] = (uVar10 & 8) != 0;
        if ((uVar10 & 0x10) != 0) {
          puVar6[lVar7 + 0x2a] = puVar6[lVar7 + 0x2a] | 2;
        }
        if ((uVar10 & 0x20) != 0) {
          puVar6[lVar7 + 0x2a] = puVar6[lVar7 + 0x2a] | 4;
        }
        if ((uVar10 & 0x40) != 0) {
          puVar6[lVar7 + 0x2a] = puVar6[lVar7 + 0x2a] | 8;
        }
        puVar6[lVar7 + 0x2b] = 0;
        puVar6[lVar7 + 0x2b] = (uVar10 & 0x80) != 0;
        if ((uVar10 >> 8 & 1) != 0) {
          puVar6[lVar7 + 0x2b] = puVar6[lVar7 + 0x2b] | 2;
        }
        if ((uVar10 >> 9 & 1) != 0) {
          puVar6[lVar7 + 0x2b] = puVar6[lVar7 + 0x2b] | 4;
        }
        if ((uVar10 >> 10 & 1) != 0) {
          puVar6[lVar7 + 0x2b] = puVar6[lVar7 + 0x2b] | 8;
        }
        lVar12 = 8;
        puVar11 = puVar6 + lVar7 + 0x34;
        puVar8 = (undefined1 *)(lVar5 + 0x13);
        do {
          uVar1 = *puVar8;
          puVar8 = puVar8 + -1;
          *puVar11 = uVar1;
          puVar11 = puVar11 + 1;
          lVar12 = lVar12 + -1;
        } while (lVar12 != 0);
      }
      goto LAB_1c000c9b0;
    }
    if (bVar13 == 0xb) {
      if ((int)(uint)*(byte *)(param_1 + 0x1327) <
          (int)(*(byte *)(*(longlong *)(param_1 + 0x12b0) + 0xc) - 1)) {
        *(byte *)(param_1 + 0x1327) = *(byte *)(param_1 + 0x1327) + 1;
        *(undefined1 *)(param_1 + 0x131c) = 9;
      }
      else {
        *(undefined1 *)(param_1 + 0x131c) = 0xf0;
      }
      goto LAB_1c000c9b0;
    }
    if (bVar13 == 0xc) {
      *(undefined1 *)(param_1 + 0x131c) = 0xd;
      goto LAB_1c000cad9;
    }
    if (bVar13 != 0xd) {
      if (bVar13 == 0xf) {
        *(undefined1 *)(param_1 + 0x131c) = 0x10;
        lVar5 = (ulonglong)*(byte *)(param_1 + 0x1327) * 0x40;
        if (*(short *)(param_1 + 0xd64) != 0x22) {
          lVar7 = 8;
          puVar8 = (undefined1 *)(lVar3 + 0x2c + lVar5);
          puVar11 = (undefined1 *)(*(longlong *)(param_1 + 0x12d0) + 0x13);
          do {
            uVar1 = *puVar11;
            puVar11 = puVar11 + -1;
            *puVar8 = uVar1;
            puVar8 = puVar8 + 1;
            lVar7 = lVar7 + -1;
          } while (lVar7 != 0);
          puVar6[lVar5 + 0x18] = *(undefined1 *)(param_1 + 0x1327);
        }
      }
      else {
        if (bVar13 != 0x10) {
          return;
        }
        if ((int)(uint)*(byte *)(param_1 + 0x1327) <
            (int)(*(byte *)(*(longlong *)(param_1 + 0x12b0) + 0xc) - 1)) {
          *(byte *)(param_1 + 0x1327) = *(byte *)(param_1 + 0x1327) + 1;
          *(undefined1 *)(param_1 + 0x131c) = 0xd;
        }
        else {
          *(undefined1 *)(param_1 + 0x131c) = 4;
        }
      }
      goto LAB_1c000c9b0;
    }
    *(undefined1 *)(param_1 + 0x131c) = 0xf;
    uVar2 = *(ushort *)
             (*(longlong *)(param_1 + 0x12b0) + 0x1a + (ulonglong)*(byte *)(param_1 + 0x1327) * 0x10
             );
  }
  iVar4 = (int)*(undefined8 *)(param_1 + 0x12d0);
  pcVar9 = (char *)(param_1 + 0x1286);
  uVar10 = uVar2 | 0x20000000;
LAB_1c000cde2:
  SendExtendedConfigPageMessage(param_1,'\x01',pcVar9,uVar10,iVar4);
  return;
}



===== HpSasGetConnectorInfo @ 1c000cea8 =====

void HpSasGetConnectorInfo(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_res8 [2];
  int iVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x1308);
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x131d) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else {
    while (cVar5 = *(char *)(param_1 + 0x131d), cVar5 != '\0') {
      if (cVar5 == '\x01') {
        *(undefined1 *)(param_1 + 0x131d) = 2;
      }
      else {
        if (cVar5 == '\x02') {
          iVar8 = 0;
          cVar5 = '\0';
          *(undefined1 *)(param_1 + 0x131d) = 3;
          local_res8[0] = 0x9070000;
LAB_1c000d011:
          SendConfigPageMessage(param_1,cVar5,local_res8,0,iVar8);
          return;
        }
        if (cVar5 == '\x03') {
          *(undefined1 *)(param_1 + 0x131d) = 4;
          cVar5 = '\x01';
          local_res8[0] = *(undefined4 *)(param_1 + 0xd98);
          iVar8 = (int)*(undefined8 *)(param_1 + 0xd90);
          goto LAB_1c000d011;
        }
        if (cVar5 != '\x04') {
          if (cVar5 == -0x10) {
            *(undefined1 *)(param_1 + 0x131d) = 0;
            *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
            StorPortNotification(0,param_1);
            *(undefined8 *)(param_1 + 0x1310) = 0;
            *(undefined1 *)(param_1 + 0x6a1) = 0;
            return;
          }
          return;
        }
        *(undefined1 *)(param_1 + 0x131d) = 0xf0;
        puVar7 = (undefined4 *)(lVar2 + 0x1c);
        lVar3 = *(longlong *)(param_1 + 0xd90);
        if (lVar3 == 0) {
          bVar1 = *(byte *)(*(longlong *)(param_1 + 0x12b0) + 0xc);
          if (bVar1 != 0) {
            uVar4 = (ulonglong)bVar1;
            do {
              *puVar7 = 1;
              *(undefined1 *)(puVar7 + 5) = 1;
              *(undefined1 *)(puVar7 + 1) = 0;
              puVar7 = puVar7 + 9;
              uVar4 = uVar4 - 1;
            } while (uVar4 != 0);
          }
        }
        else if (*(byte *)(lVar3 + 0x20) != 0) {
          uVar4 = (ulonglong)*(byte *)(lVar3 + 0x20);
          puVar6 = (undefined4 *)(lVar3 + 0x24);
          do {
            memcpy(puVar7 + 1,puVar6 + 1,0x10);
            *puVar7 = *puVar6;
            *(undefined1 *)(puVar7 + 5) = *(undefined1 *)(puVar6 + 5);
            uVar4 = uVar4 - 1;
            puVar6 = puVar6 + 7;
            puVar7 = puVar7 + 9;
          } while (uVar4 != 0);
        }
      }
    }
  }
  return;
}



===== HpSasSetPhyInfo @ 1c000d034 =====

void HpSasSetPhyInfo(longlong param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  ulonglong uVar10;
  char cVar11;
  char *pcVar12;
  uint uVar13;
  byte bVar14;
  byte bVar15;
  
  lVar4 = *(longlong *)(param_1 + 0x1308);
  bVar7 = false;
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x131e) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else {
LAB_1c000d06f:
    do {
      cVar11 = *(char *)(param_1 + 0x131e);
      bVar8 = false;
      if (cVar11 == '\0') {
        bVar8 = false;
LAB_1c000d233:
        if (bVar7) goto LAB_1c000d238;
      }
      else {
        if (cVar11 == '\x01') {
          *(undefined1 *)(param_1 + 0x131e) = 6;
          bVar8 = true;
          goto LAB_1c000d233;
        }
        if (cVar11 == '\x03') {
          *(undefined1 *)(param_1 + 0x131e) = 4;
          pcVar12 = (char *)(param_1 + 0x126e);
          iVar9 = (int)*(undefined8 *)(param_1 + 0x12b8);
          uVar13 = 0;
LAB_1c000d114:
          cVar11 = '\x01';
LAB_1c000d116:
          SendExtendedConfigPageMessage(param_1,cVar11,pcVar12,uVar13,iVar9);
          goto LAB_1c000d233;
        }
        if (cVar11 != '\x04') {
          if (cVar11 != '\x05') {
            if (cVar11 != '\x06') {
              if (cVar11 == -0x10) {
                *(undefined1 *)(param_1 + 0x131e) = 0;
                *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
                StorPortNotification(0,param_1);
                *(undefined8 *)(param_1 + 0x1310) = 0;
                *(undefined1 *)(param_1 + 0x6a1) = 0;
                return;
              }
              goto LAB_1c000d233;
            }
            *(undefined1 *)(param_1 + 0x131e) = 3;
            pcVar12 = (char *)(param_1 + 0x1296);
            uVar13 = (uint)*(byte *)(lVar4 + 0x1c);
            iVar9 = (int)*(undefined8 *)(param_1 + 0x12e0);
            goto LAB_1c000d114;
          }
          *(undefined1 *)(param_1 + 0x131e) = 0xf0;
          pcVar12 = (char *)(param_1 + 0x126e);
          iVar9 = (int)*(undefined8 *)(param_1 + 0x12b8);
          uVar13 = 0;
          cVar11 = '\x02';
          goto LAB_1c000d116;
        }
        *(undefined1 *)(param_1 + 0x131e) = 5;
        lVar5 = *(longlong *)(param_1 + 0x12b8);
        lVar6 = *(longlong *)(param_1 + 0x12e0);
        if (*(byte *)(lVar4 + 0x1c) < *(byte *)(lVar5 + 0x10)) {
          uVar10 = (ulonglong)*(byte *)(lVar4 + 0x1c);
          if (*(char *)(lVar4 + 0x1d) == '\0') {
            pbVar1 = (byte *)(lVar5 + 0x15 + uVar10 * 0xc);
            *pbVar1 = *pbVar1 & 0xfe;
          }
          else if (*(char *)(lVar4 + 0x1d) == '\x01') {
            pbVar1 = (byte *)(lVar5 + 0x16 + uVar10 * 0xc);
            *pbVar1 = *pbVar1 | 4;
          }
          bVar14 = *(byte *)(lVar6 + 0x1d);
          bVar2 = *(byte *)(lVar4 + 0x1e);
          bVar3 = *(byte *)(lVar4 + 0x1f);
          bVar15 = bVar14 & 0xf;
          bVar14 = bVar14 >> 4;
          if (bVar2 != 0) {
            if ((bVar2 < bVar15) || (bVar14 < bVar2)) {
              bVar7 = true;
              *(undefined4 *)(lVar4 + 0x14) = 0x7d1;
            }
            else {
              *(byte *)(lVar5 + 0x17 + uVar10 * 0xc) =
                   (*(byte *)(lVar5 + 0x17 + uVar10 * 0xc) & 0xf0) + bVar2;
            }
          }
          if (bVar3 != 0) {
            if ((bVar14 < bVar3) || (bVar3 < bVar15)) {
              bVar7 = true;
              *(undefined4 *)(lVar4 + 0x14) = 0x7d1;
              goto LAB_1c000d238;
            }
            *(byte *)(lVar5 + 0x17 + uVar10 * 0xc) =
                 (*(byte *)(lVar5 + 0x17 + uVar10 * 0xc) & 0xf) + bVar3 * '\x10';
          }
          if (!bVar7) {
            *(undefined4 *)(lVar4 + 0x14) = 0;
            goto LAB_1c000d06f;
          }
        }
        else {
          *(undefined4 *)(lVar4 + 0x14) = 3;
          bVar7 = true;
        }
LAB_1c000d238:
        bVar8 = true;
        if (*(int *)(lVar4 + 0x14) == 0) {
          *(undefined4 *)(lVar4 + 0x14) = 1;
        }
        *(undefined1 *)(param_1 + 0x131e) = 0xf0;
      }
    } while (bVar8);
  }
  return;
}



===== HpSasGetLinkErrors @ 1c000d260 =====

void HpSasGetLinkErrors(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  undefined4 uVar7;
  undefined8 *puVar8;
  undefined1 local_res8 [8];
  
  lVar2 = *(longlong *)(param_1 + 0x1310);
  lVar3 = *(longlong *)(param_1 + 0x1308);
  bVar5 = false;
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x131f) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else {
    do {
      cVar1 = *(char *)(param_1 + 0x131f);
      bVar6 = false;
      if (cVar1 == '\0') {
LAB_1c000d2ef:
        bVar6 = false;
LAB_1c000d2f2:
        if (bVar5) goto LAB_1c000d2f7;
      }
      else {
        if (cVar1 == '\x01') {
          *(undefined1 *)(param_1 + 0x131f) = 2;
          goto LAB_1c000d425;
        }
        if (cVar1 == '\x02') {
          *(undefined1 *)(param_1 + 0x131f) = 3;
          SendExtendedConfigPageMessage
                    (param_1,'\x01',(char *)(param_1 + 0x129e),(uint)*(byte *)(lVar3 + 0x1c),
                     (int)*(undefined8 *)(param_1 + 0x12e8));
          goto LAB_1c000d2f2;
        }
        if (cVar1 == '\x03') {
          if (*(short *)(param_1 + 0xd64) == 0x22) {
            *(undefined4 *)(lVar3 + 0x14) = 0x7d2;
LAB_1c000d3bf:
            *(undefined1 *)(param_1 + 0x131f) = 0xf0;
          }
          else {
            *(undefined1 *)(param_1 + 0x131f) = 4;
            lVar4 = *(longlong *)(param_1 + 0x12e8);
            *(undefined4 *)(lVar3 + 0x20) = *(undefined4 *)(lVar4 + 0xc);
            *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(lVar4 + 0x10);
            *(undefined4 *)(lVar3 + 0x28) = *(undefined4 *)(lVar4 + 0x14);
            *(undefined4 *)(lVar3 + 0x2c) = *(undefined4 *)(lVar4 + 0x18);
          }
LAB_1c000d425:
          bVar6 = true;
          goto LAB_1c000d2f2;
        }
        if (cVar1 != '\x04') {
          if (cVar1 != '\x05') {
            *(undefined1 *)(param_1 + 0x131f) = 0;
            if (cVar1 == -0x10) {
              *(undefined2 *)(lVar2 + 3) = 1;
              StorPortNotification(0,param_1,lVar2);
              *(undefined8 *)(param_1 + 0x1310) = 0;
              *(undefined1 *)(param_1 + 0x6a1) = 0;
              return;
            }
            goto LAB_1c000d2ef;
          }
          *(undefined1 *)(param_1 + 0x131f) = 0xf0;
          if (*(short *)(param_1 + 0x1318) != 0) {
            *(undefined4 *)(lVar3 + 0x14) = 1;
          }
          goto LAB_1c000d425;
        }
        if (*(char *)(lVar3 + 0x1d) == '\0') goto LAB_1c000d3bf;
        *(undefined1 *)(param_1 + 0x131f) = 5;
        if (*(longlong *)(**(longlong **)(param_1 + 0x158) + 8) == 0) {
          lVar4 = *(longlong *)(lVar2 + 0x38);
          puVar8 = (undefined8 *)(lVar4 + 0x138);
          uVar7 = StorPortGetPhysicalAddress(param_1,lVar2,puVar8,local_res8);
          *puVar8 = 0;
          *(undefined8 *)(lVar4 + 0x140) = 0;
          *(undefined8 *)(lVar4 + 0x148) = 0;
          *(undefined8 *)(lVar4 + 0x150) = 0;
          *(undefined1 *)(lVar4 + 0x13b) = 0x1b;
          *(undefined4 *)(lVar4 + 0x140) = 0xffeed;
          *(undefined1 *)(lVar4 + 0x146) = *(undefined1 *)(lVar3 + 0x1c);
          *(undefined1 *)puVar8 = 8;
          **(undefined4 **)(param_1 + 0x38) = uVar7;
          LOCK();
          UNLOCK();
          goto LAB_1c000d2f2;
        }
        bVar5 = true;
LAB_1c000d2f7:
        bVar6 = true;
        if (*(int *)(lVar3 + 0x14) == 0) {
          *(undefined4 *)(lVar3 + 0x14) = 1;
        }
        *(undefined1 *)(param_1 + 0x131f) = 0xf0;
      }
    } while (bVar6);
  }
  return;
}



===== HpSasGetSataSignature @ 1c000d468 =====

void HpSasGetSataSignature(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x1308);
  bVar3 = false;
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x1320) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else {
    do {
      cVar1 = *(char *)(param_1 + 0x1320);
      bVar4 = false;
      if (cVar1 == '\0') {
LAB_1c000d4ec:
        bVar4 = false;
      }
      else {
        if (cVar1 == '\x01') {
          *(undefined1 *)(param_1 + 0x1320) = 2;
        }
        else {
          if (cVar1 == '\x02') {
            *(undefined1 *)(param_1 + 0x1320) = 3;
            pcVar6 = (char *)(param_1 + 0x1296);
            uVar7 = (uint)*(byte *)(lVar2 + 0x1c);
            iVar5 = (int)*(undefined8 *)(param_1 + 0x12e0);
LAB_1c000d5b2:
            SendExtendedConfigPageMessage(param_1,'\x01',pcVar6,uVar7,iVar5);
            goto LAB_1c000d4ef;
          }
          if (cVar1 == '\x03') {
            *(undefined1 *)(param_1 + 0x1320) = 4;
            if (*(short *)(param_1 + 0xd64) == 0x22) {
              *(undefined4 *)(lVar2 + 0x14) = 0x7d2;
            }
            else {
              if ((char)*(undefined4 *)(*(longlong *)(param_1 + 0x12e0) + 0x18) < '\0')
              goto LAB_1c000d5cd;
              *(undefined4 *)(lVar2 + 0x14) = 0x7d9;
            }
            bVar3 = true;
          }
          else {
            if (cVar1 == '\x04') {
              *(undefined1 *)(param_1 + 0x1320) = 5;
              pcVar6 = (char *)(param_1 + 0x128e);
              iVar5 = (int)*(undefined8 *)(param_1 + 0x12d8);
              uVar7 = *(ushort *)(*(longlong *)(param_1 + 0x12e0) + 0x14) | 0x20000000;
              goto LAB_1c000d5b2;
            }
            if (cVar1 != '\x05') {
              *(undefined1 *)(param_1 + 0x1320) = 0;
              if (cVar1 == -0x10) {
                *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
                StorPortNotification(0,param_1);
                *(undefined8 *)(param_1 + 0x1310) = 0;
                *(undefined1 *)(param_1 + 0x6a1) = 0;
                return;
              }
              goto LAB_1c000d4ec;
            }
            *(undefined1 *)(param_1 + 0x1320) = 0xf0;
            memcpy((void *)(lVar2 + 0x20),(void *)(*(longlong *)(param_1 + 0x12d8) + 0x1c),0x14);
          }
        }
LAB_1c000d5cd:
        bVar4 = true;
      }
LAB_1c000d4ef:
      if (bVar3) {
        bVar4 = true;
        if (*(int *)(lVar2 + 0x14) == 0) {
          *(undefined4 *)(lVar2 + 0x14) = 1;
        }
        *(undefined1 *)(param_1 + 0x1320) = 0xf0;
      }
    } while (bVar4);
  }
  return;
}



===== FindSasAddressFromScsi @ 1c000d614 =====

ulonglong FindSasAddressFromScsi
                    (longlong param_1,char param_2,char param_3,undefined4 *param_4,uint *param_5)

{
  ulonglong in_RAX;
  undefined4 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(uint *)(param_1 + 0x1350) != 0) {
    do {
      puVar1 = (undefined4 *)(uVar3 * 0x10 + *(longlong *)(param_1 + 0x1348));
      if ((*(char *)(puVar1 + 2) == param_2) && (*(char *)((longlong)puVar1 + 9) == param_3)) {
        uVar2 = puVar1[3];
        in_RAX = (ulonglong)uVar2;
        if ((*param_5 & uVar2) != 0) {
          *param_4 = *puVar1;
          param_4[1] = puVar1[1];
          *param_5 = puVar1[3];
          return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);
        }
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(param_1 + 0x1350));
  }
  return in_RAX & 0xffffffffffffff00;
}



===== MapMpiSasStatusToCsmi @ 1c000d684 =====

undefined8 MapMpiSasStatusToCsmi(undefined8 param_1,byte param_2)

{
  if (param_2 < 8) {
    if (param_2 == 7) {
      return 5;
    }
    if (param_2 == 0) {
      return 0;
    }
    if ((param_2 != 0) && (2 < param_2)) {
      if (param_2 == 3) {
        return 1;
      }
      if ((param_2 != 4) && (param_2 == 5)) {
        return 2;
      }
    }
  }
  else {
    if (param_2 == 8) {
      return 0xb;
    }
    if (param_2 == 9) {
      return 0xc;
    }
    if ((9 < param_2) && (0x11 < param_2)) {
      if (param_2 == 0x12) {
        return 10;
      }
      if (param_2 == 0x13) {
        return 4;
      }
      if (param_2 == 0x14) {
        return 3;
      }
    }
  }
  return 9;
}



===== FindScsiAddressFromSas @ 1c000d6f4 =====

ulonglong FindScsiAddressFromSas
                    (longlong param_1,undefined1 *param_2,undefined1 *param_3,int *param_4,
                    int *param_5)

{
  int iVar1;
  ulonglong in_RAX;
  int *piVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar4 = 0;
  if (*(uint *)(param_1 + 0x1350) != 0) {
    do {
      piVar2 = (int *)(uVar4 * 0x10 + *(longlong *)(param_1 + 0x1348));
      if (*piVar2 == *param_4) {
        uVar3 = param_4[1];
        in_RAX = (ulonglong)uVar3;
        if ((piVar2[1] == uVar3) && (piVar2[3] != 0)) {
          *param_2 = (char)piVar2[2];
          iVar1 = piVar2[3];
          *param_3 = *(undefined1 *)((longlong)piVar2 + 9);
          *param_5 = iVar1;
          return CONCAT71((uint7)(uint3)(uVar3 >> 8),1);
        }
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(param_1 + 0x1350));
  }
  return in_RAX & 0xffffffffffffff00;
}



===== AddNewIRDiskToSasTable @ 1c000d768 =====

void AddNewIRDiskToSasTable(longlong param_1,char param_2)

{
  undefined1 *_Dst;
  byte bVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  char cVar9;
  char cVar10;
  uint local_res8 [2];
  undefined4 local_res18 [2];
  
  _Dst = (undefined1 *)(param_1 + 0x200);
  if ((*(ushort *)(param_1 + 0x134) & 0x8000) != 0) {
    memset(_Dst,0,0x28);
    *(undefined8 *)(param_1 + 0x280) = 0;
    *(undefined8 *)(param_1 + 0x288) = 0;
    *(undefined8 *)(param_1 + 0x290) = 0;
    *(undefined1 *)(param_1 + 0x203) = 4;
    *(undefined4 *)(param_1 + 0x21c) = 0xd1000000;
    *_Dst = 0;
    *(undefined2 *)(param_1 + 0x216) = 0x103;
    bVar2 = SendMessageViaHandShake(param_1,0,10);
    if (((bVar2) && (lVar5 = ReceiveDataViaHandshake(param_1,0xc), (char)lVar5 != '\0')) &&
       (*(short *)(param_1 + 0x28e) == 0)) {
      *_Dst = 1;
      *(undefined4 *)(param_1 + 0x214) = *(undefined4 *)(param_1 + 0x294);
      *(uint *)(param_1 + 0x21c) =
           *(uint *)(param_1 + 0x21c) | (uint)*(byte *)(param_1 + 0x215) << 2;
      *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x670) - *(int *)(param_1 + 0x58);
      lVar5 = *(longlong *)(param_1 + 0x670);
      bVar2 = SendMessageViaHandShake(param_1,0,10);
      if ((bVar2) && (lVar6 = ReceiveDataViaHandshake(param_1,0xc), (char)lVar6 != '\0')) {
        bVar1 = *(byte *)(lVar5 + 4);
        cVar9 = -1;
        cVar10 = -1;
        if (bVar1 != 0) {
          bVar3 = 0;
          do {
            uVar7 = (ulonglong)bVar3;
            if (*(char *)(lVar5 + 0xb + uVar7 * 4) == param_2) {
              cVar10 = *(char *)(lVar5 + 9 + uVar7 * 4);
              cVar9 = *(char *)(lVar5 + 8 + uVar7 * 4);
              break;
            }
            bVar3 = bVar3 + 1;
          } while (bVar3 < bVar1);
          if (bVar3 != bVar1) {
            local_res8[0] = 0x680;
            uVar7 = FindSasAddressFromScsi(param_1,cVar10,cVar9,local_res18,local_res8);
            *(undefined1 *)(param_1 + 0x214) = *(undefined1 *)(param_1 + 0x1286);
            *(undefined1 *)(param_1 + 0x216) = *(undefined1 *)(param_1 + 0x1288);
            *(undefined1 *)(param_1 + 0x217) = *(undefined1 *)(param_1 + 0x1289);
            *(ushort *)(param_1 + 0x204) = *(ushort *)(param_1 + 0x128a);
            *(undefined1 *)(param_1 + 0x206) = *(undefined1 *)(param_1 + 0x128c);
            *(uint *)(param_1 + 0x218) = CONCAT11(cVar10,cVar9) | 0x10000000;
            *(uint *)(param_1 + 0x21c) = (uint)*(ushort *)(param_1 + 0x128a) << 2 | 0xd1000000;
            *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x12d0) - *(int *)(param_1 + 0x58);
            bVar2 = SendMessageViaHandShake(param_1,0,10);
            if ((bVar2) && (lVar5 = ReceiveDataViaHandshake(param_1,0xc), (char)lVar5 != '\0')) {
              uVar4 = 0;
              lVar5 = *(longlong *)(param_1 + 0x12d0);
              if (*(uint *)(param_1 + 0x1350) != 0) {
                do {
                  puVar8 = (undefined4 *)((ulonglong)uVar4 * 0x10 + *(longlong *)(param_1 + 0x1348))
                  ;
                  if ((char)uVar7 == '\0') {
                    bVar2 = puVar8[3] == 0;
LAB_1c000d97d:
                    if (bVar2) {
                      *puVar8 = *(undefined4 *)(lVar5 + 0xc);
                      puVar8[1] = *(undefined4 *)(lVar5 + 0x10);
                      *(undefined1 *)(puVar8 + 2) = *(undefined1 *)(lVar5 + 0x1b);
                      *(undefined1 *)((longlong)puVar8 + 9) = *(undefined1 *)(lVar5 + 0x1a);
                      *(undefined2 *)((longlong)puVar8 + 10) = *(undefined2 *)(lVar5 + 0x18);
                      puVar8[3] = *(uint *)(lVar5 + 0x1c) & 0xffff;
                      return;
                    }
                  }
                  else if (*(char *)(puVar8 + 2) == cVar10) {
                    bVar2 = *(char *)((longlong)puVar8 + 9) == cVar9;
                    goto LAB_1c000d97d;
                  }
                  uVar4 = uVar4 + 1;
                } while (uVar4 < *(uint *)(param_1 + 0x1350));
              }
            }
          }
        }
      }
    }
  }
  return;
}



===== HpSasGetDeviceAddress @ 1c000d9c8 =====

void HpSasGetDeviceAddress(longlong param_1)

{
  undefined1 uVar1;
  byte bVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  char cVar10;
  undefined1 *puVar11;
  longlong lVar12;
  uint local_res8 [2];
  int iVar13;
  
  lVar3 = *(longlong *)(param_1 + 0x1308);
  bVar4 = false;
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x1321) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else {
    do {
      cVar10 = *(char *)(param_1 + 0x1321);
      bVar6 = false;
      bVar5 = false;
      if (cVar10 == '\x01') {
        if ((*(ushort *)(param_1 + 0x134) & 0x8000) == 0) {
          *(undefined1 *)(param_1 + 0x1321) = 4;
LAB_1c000dba4:
          bVar5 = true;
        }
        else {
          iVar13 = 0;
          cVar10 = '\0';
          *(undefined1 *)(param_1 + 0x1321) = 2;
          local_res8[0] = 0x1030000;
LAB_1c000dbc0:
          SendConfigPageMessage(param_1,cVar10,local_res8,0,iVar13);
        }
LAB_1c000dbd0:
        if (bVar4) goto LAB_1c000dbd5;
      }
      else {
        if (cVar10 != '\x02') {
          if (cVar10 == '\x03') {
            lVar12 = *(longlong *)(param_1 + 0xd90);
            bVar2 = *(byte *)(lVar12 + 4);
            if ((bVar2 != 0) && (uVar8 = 0, bVar2 != 0)) {
              do {
                if ((*(char *)(lVar12 + 8 + uVar8 * 4) == *(char *)(lVar3 + 0x1e)) &&
                   (*(char *)(lVar12 + 9 + uVar8 * 4) == *(char *)(lVar3 + 0x1d))) {
                  *(undefined4 *)(lVar3 + 0x14) = 0x7de;
                  bVar5 = true;
                  *(undefined1 *)(param_1 + 0x1321) = 0xf0;
                  bVar6 = true;
                  if ((byte)uVar8 < bVar2) goto LAB_1c000dbd0;
                  break;
                }
                bVar7 = (byte)uVar8 + 1;
                uVar8 = (ulonglong)bVar7;
              } while (bVar7 < bVar2);
            }
          }
          else if (cVar10 != '\x04') {
            if (cVar10 == '\x05') {
              *(undefined1 *)(param_1 + 0x1321) = 0xf0;
              if (*(short *)(param_1 + 0xd64) == 0x22) {
                *(undefined4 *)(lVar3 + 0x14) = 0x7de;
              }
              else {
                puVar11 = (undefined1 *)(lVar3 + 0x20);
                puVar9 = (undefined1 *)(*(longlong *)(param_1 + 0x12d0) + 0x13);
                *(undefined1 *)(lVar3 + 0x29) = *(undefined1 *)(lVar3 + 0x1f);
                lVar12 = 8;
                do {
                  uVar1 = *puVar9;
                  puVar9 = puVar9 + -1;
                  *puVar11 = uVar1;
                  puVar11 = puVar11 + 1;
                  lVar12 = lVar12 + -1;
                } while (lVar12 != 0);
              }
              goto LAB_1c000dba4;
            }
            if (cVar10 == -0x10) {
              *(undefined1 *)(param_1 + 0x1321) = 0;
              if (*(longlong *)(param_1 + 0x1310) != 0) {
                *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
                StorPortNotification(0);
              }
              *(undefined8 *)(param_1 + 0x1310) = 0;
              *(undefined1 *)(param_1 + 0x6a1) = 0;
            }
            goto LAB_1c000dbd0;
          }
          bVar5 = bVar6;
          *(undefined1 *)(param_1 + 0x1321) = 5;
          SendExtendedConfigPageMessage
                    (param_1,'\x01',(char *)(param_1 + 0x1286),
                     (*(byte *)(lVar3 + 0x1d) | 0x100000) << 8 | (uint)*(byte *)(lVar3 + 0x1e),
                     (int)*(undefined8 *)(param_1 + 0x12d0));
          goto LAB_1c000dbd0;
        }
        *(undefined1 *)(param_1 + 0x1321) = 3;
        local_res8[0] = *(uint *)(param_1 + 0xd98);
        if ((local_res8[0] >> 8 & 0xff) << 2 <= *(uint *)(param_1 + 0xd8c)) {
          iVar13 = (int)*(undefined8 *)(param_1 + 0xd90);
          cVar10 = '\x01';
          goto LAB_1c000dbc0;
        }
        bVar4 = true;
LAB_1c000dbd5:
        bVar5 = true;
        if (*(int *)(lVar3 + 0x14) == 0) {
          *(undefined4 *)(lVar3 + 0x14) = 1;
        }
        *(undefined1 *)(param_1 + 0x1321) = 0xf0;
      }
    } while (bVar5);
  }
  return;
}



===== HpPerformTaskManagement @ 1c000dc0c =====

ulonglong HpPerformTaskManagement(longlong param_1,ulonglong param_2)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 *_Dst;
  int *piVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  byte bVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  ulonglong *puVar13;
  undefined1 uVar14;
  undefined1 local_res8;
  undefined1 local_res9;
  undefined1 local_resa;
  undefined1 local_resb;
  ulonglong local_res10;
  undefined4 local_res18;
  
  local_res18 = 0;
  lVar3 = *(longlong *)(param_2 + 0x18);
  uVar6 = 0xff;
  uVar9 = 1;
  bVar10 = 7;
  piVar4 = (int *)(ulonglong)*(ushort *)(param_1 + 0x134);
  uVar14 = 0xff;
  uVar11 = 0xff;
  uVar12 = 0xff;
  if ((((*(ushort *)(param_1 + 0x134) & 0x200) != 0) && (*(char *)(param_2 + 2) == '\x02')) &&
     (*(int *)(lVar3 + 0x10) == 0x1d)) {
    uVar2 = *(uint *)(lVar3 + 0x20);
    piVar4 = (int *)0x0;
    if (((byte)uVar2 & 3) == 3) {
LAB_1c000dc75:
      *(undefined4 *)(lVar3 + 0x14) = 3;
      goto LAB_1c000de6f;
    }
    if ((uVar2 & 1) == 0) {
      bVar10 = 7;
      if ((uVar2 & 2) != 0) {
        bVar10 = 3;
      }
    }
    else {
      cVar1 = *(char *)(lVar3 + 0x2c);
      if (cVar1 == '\x01') {
        bVar10 = 1;
      }
      else if (cVar1 == '\x02') {
        bVar10 = 2;
      }
      else if (cVar1 == '\x04') {
        bVar10 = 6;
      }
      else if (cVar1 == '\b') {
        bVar10 = 5;
      }
      else {
        if (cVar1 != -0x80) goto LAB_1c000dc75;
        bVar10 = 7;
      }
    }
    uVar12 = *(undefined1 *)(lVar3 + 0x1d);
    uVar11 = *(undefined1 *)(lVar3 + 0x1e);
    uVar14 = *(undefined1 *)(lVar3 + 0x1f);
    uVar6 = *(undefined1 *)(lVar3 + 0x24);
  }
  *(byte *)(param_1 + 0xf40) = bVar10;
  local_res10 = param_2;
  if (bVar10 == 1) {
LAB_1c000dd00:
    local_res8 = uVar12;
    local_res9 = uVar11;
    local_resa = uVar14;
    local_resb = uVar6;
    piVar4 = (int *)StorPortSynchronizeAccess(param_1,FindAbortContext,&local_res8);
    if ((char)piVar4 == '\0') {
      *(undefined4 *)(lVar3 + 0x14) = 0;
      *(undefined1 *)(lVar3 + 0x39) = 5;
      *(undefined1 *)(lVar3 + 0x3c) = 0;
LAB_1c000de6f:
      return (ulonglong)piVar4 & 0xffffffffffffff00;
    }
    local_res18 = *(undefined4 *)(param_1 + 0xf5c);
  }
  else {
    if (bVar10 < 2) goto LAB_1c000de5e;
    if (3 < bVar10) {
      if (bVar10 < 5) goto LAB_1c000de5e;
      if (6 < bVar10) {
        if (bVar10 != 7) goto LAB_1c000de5e;
        goto LAB_1c000dd00;
      }
    }
  }
  if ((*(ushort *)(param_1 + 0x134) & 0x280) == 0x200) {
    if (*(char *)(param_1 + 0x1260) != '\b') goto LAB_1c000dd7b;
    uVar5 = IssueMessageUnitReset(param_1);
    if ((char)uVar5 != '\0') goto LAB_1c000dd6e;
  }
  else {
LAB_1c000dd6e:
    if (*(char *)(param_1 + 0x1260) != '\b') {
LAB_1c000dd7b:
      uVar8 = 0;
      do {
        if (*(int *)(param_1 + 0x11b4 + uVar8 * 0x18) == 0) {
          puVar13 = (ulonglong *)(param_1 + (uVar8 + 0xbc) * 0x18);
          goto LAB_1c000ddac;
        }
        bVar7 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar7;
      } while (bVar7 < 8);
      puVar13 = (ulonglong *)0x0;
LAB_1c000ddac:
      if (puVar13 != (ulonglong *)0x0) {
        _Dst = (undefined1 *)*puVar13;
        memset(_Dst,0,0x34);
        _Dst[5] = bVar10;
        _Dst[1] = uVar12;
        *_Dst = uVar11;
        _Dst[0xd] = uVar14;
        *(undefined4 *)(_Dst + 0x30) = local_res18;
        *(char *)(param_1 + 0x1260) = *(char *)(param_1 + 0x1260) + '\x01';
        *(uint *)((longlong)puVar13 + 0x14) = *(uint *)((longlong)puVar13 + 0x14) | 1;
        puVar13[1] = local_res10;
        *(int *)(*puVar13 + 8) = (int)puVar13[2];
        piVar4 = (int *)*puVar13;
        *(undefined1 *)((longlong)piVar4 + 3) = 1;
        if (*(char *)(param_1 + 0x678) != '\0') {
          StorPortPause(param_1,300);
          piVar4 = *(int **)(param_1 + 0x48);
          *(undefined4 *)(param_1 + 0x1c0) = 8;
          *piVar4 = (int)*puVar13 - *(int *)(param_1 + 0x58);
          LOCK();
          UNLOCK();
        }
        goto LAB_1c000de5e;
      }
      param_2 = local_res10;
    }
  }
  piVar4 = (int *)(ulonglong)*(ushort *)(param_1 + 0x134);
  if ((((*(ushort *)(param_1 + 0x134) & 0x200) != 0) && (*(char *)(param_2 + 2) == '\x02')) &&
     (*(int *)(lVar3 + 0x10) == 0x1d)) {
    *(undefined4 *)(lVar3 + 0x14) = 1;
    uVar9 = 0;
  }
LAB_1c000de5e:
  return CONCAT71((int7)((ulonglong)piVar4 >> 8),uVar9);
}



===== HpSasGetRaidInfo @ 1c000de88 =====

void HpSasGetRaidInfo(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  char cVar4;
  byte bVar5;
  undefined4 local_res8 [2];
  int iVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x1308);
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x1322) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else {
LAB_1c000dec6:
    while (cVar4 = *(char *)(param_1 + 0x1322), cVar4 == '\x01') {
      *(undefined1 *)(param_1 + 0x1322) = 2;
    }
    if (cVar4 == '\x02') {
      *(undefined1 *)(param_1 + 0x1322) = 3;
      local_res8[0] = 0x1020000;
LAB_1c000e0a5:
      cVar4 = '\0';
      iVar6 = 0;
      goto LAB_1c000e0ac;
    }
    if (cVar4 == '\x03') {
      if ((*(uint *)(*(longlong *)(param_1 + 0xe50) + 4) & 0x7f) == 0) {
        *(undefined1 *)(param_1 + 0x1322) = 7;
        *(undefined4 *)(lVar1 + 0x20) = 8;
      }
      else {
        *(undefined1 *)(param_1 + 0x1322) = 4;
      }
      local_res8[0] = *(undefined4 *)(param_1 + 0xd98);
      iVar6 = (int)*(undefined8 *)(param_1 + 0xe50);
      goto LAB_1c000e045;
    }
    if (cVar4 == '\x04') {
      *(undefined1 *)(param_1 + 0x1322) = 5;
      local_res8[0] = 0x1060000;
      goto LAB_1c000e0a5;
    }
    if (cVar4 != '\x05') {
      if (cVar4 == '\x06') {
        *(undefined1 *)(param_1 + 0x1322) = 7;
        lVar2 = *(longlong *)(param_1 + 0xd90);
        bVar5 = *(byte *)(lVar2 + 8);
        if (*(byte *)(lVar2 + 8) < *(byte *)(lVar2 + 9)) {
          bVar5 = *(byte *)(lVar2 + 9);
        }
        if (bVar5 < *(byte *)(lVar2 + 10)) {
          bVar5 = *(byte *)(lVar2 + 10);
        }
        *(uint *)(lVar1 + 0x20) = (uint)bVar5;
      }
      else {
        if (cVar4 != '\a') {
          if (cVar4 == -0x10) {
            *(undefined1 *)(param_1 + 0x1322) = 0;
            *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
            StorPortNotification(0,param_1);
            *(undefined8 *)(param_1 + 0x1310) = 0;
            *(undefined1 *)(param_1 + 0x6a1) = 0;
            return;
          }
          return;
        }
        *(undefined1 *)(param_1 + 0x1322) = 0xf0;
        cVar4 = '\0';
        lVar2 = *(longlong *)(param_1 + 0xe50);
        *(uint *)(lVar1 + 0x1c) = (uint)*(byte *)(lVar2 + 8);
        *(uint *)(lVar1 + 0x24) = (uint)*(byte *)(lVar2 + 9);
        for (uVar3 = *(uint *)(lVar2 + 4) & 0x7f; uVar3 != 0; uVar3 = uVar3 & uVar3 - 1) {
          cVar4 = cVar4 + '\x01';
        }
        *(char *)(lVar1 + 0x28) = cVar4;
        *(undefined8 *)(lVar1 + 0x30) = 0x800;
        *(undefined4 *)(lVar1 + 0x38) = 0xffffffff;
        *(uint *)(lVar1 + 0x3c) = -(uint)((*(uint *)(lVar2 + 4) & 0x10000000) != 0);
        *(uint *)(lVar1 + 0x40) = (uint)*(byte *)(lVar2 + 0xb);
        *(undefined8 *)(lVar1 + 0x44) = 1;
        *(undefined4 *)(lVar1 + 0x4c) = 0;
        *(undefined4 *)(lVar1 + 0x50) = *(undefined4 *)(param_1 + 0x1354);
      }
      goto LAB_1c000dec6;
    }
    *(undefined1 *)(param_1 + 0x1322) = 6;
    if (*(short *)(param_1 + 0xd64) == 0x22) {
      *(undefined1 *)(param_1 + 0x1322) = 7;
      *(uint *)(lVar1 + 0x20) = (uint)*(byte *)(*(longlong *)(param_1 + 0xe50) + 0xb);
      goto LAB_1c000dec6;
    }
    local_res8[0] = *(undefined4 *)(param_1 + 0xd98);
    iVar6 = (int)*(undefined8 *)(param_1 + 0xd90);
LAB_1c000e045:
    cVar4 = '\x01';
LAB_1c000e0ac:
    SendConfigPageMessage(param_1,cVar4,local_res8,0,iVar6);
  }
  return;
}



===== HpSasGetRaidConfig @ 1c000e0cc =====

void HpSasGetRaidConfig(longlong param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  undefined1 uVar11;
  uint uVar12;
  ulonglong uVar13;
  char cVar14;
  uint uVar15;
  longlong lVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  void *_Src;
  void *_Dst;
  int iVar19;
  longlong lVar20;
  size_t _Size;
  byte bVar21;
  uint *_Dst_00;
  undefined2 local_res18;
  undefined1 local_res1a;
  undefined4 local_res20 [2];
  char local_68;
  char local_67;
  char local_66;
  char local_65;
  uint local_64;
  int local_60;
  int local_5c;
  undefined4 local_58;
  undefined1 local_51 [17];
  
  lVar4 = *(longlong *)(param_1 + 0x1308);
  bVar8 = false;
  bVar9 = false;
  local_res18 = 0x301;
  local_res1a = 2;
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x1323) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else {
    if ((*(int *)(lVar4 + 0x3c) != 0) && (*(int *)(param_1 + 0x1354) != *(int *)(lVar4 + 0x3c))) {
      *(undefined4 *)(lVar4 + 0x14) = 3;
      *(undefined1 *)(param_1 + 0x1323) = 0xf0;
    }
    do {
      cVar14 = '\0';
      bVar21 = *(byte *)(param_1 + 0x1323);
      bVar7 = false;
      bVar10 = false;
      if (bVar21 < 0xf1) {
        if (bVar21 == 0xf0) {
          *(undefined1 *)(param_1 + 0x1323) = 0;
          *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
          StorPortNotification(0,param_1);
          *(undefined8 *)(param_1 + 0x1310) = 0;
          *(undefined1 *)(param_1 + 0x6a1) = 0;
          bVar8 = false;
LAB_1c000e555:
          bVar10 = false;
          bVar9 = bVar8;
          goto LAB_1c000e1a7;
        }
        if (8 < bVar21) {
          if (bVar21 != 9) {
            if (bVar21 == 10) {
              *(undefined1 *)(param_1 + 0x1323) = 0xb;
              *(undefined1 *)(param_1 + 0x1326) = 1;
              HpSasGetHotSpare(param_1);
LAB_1c000e1a4:
              bVar10 = false;
              goto LAB_1c000e1a7;
            }
            if (bVar21 == 0xb) {
              bVar21 = *(byte *)(param_1 + 0x132b);
              if (bVar21 != 0) {
                if ((uint)bVar21 + (uint)*(byte *)(lVar4 + 0x2b) < 0xf1) {
                  *(byte *)(lVar4 + 0x2b) = *(byte *)(lVar4 + 0x2b) + bVar21;
                }
                else {
                  *(undefined1 *)(lVar4 + 0x2b) = 0xf1;
                }
                cVar14 = (-(*(char *)(lVar4 + 0x2c) != '\0') & 0xe4U) + 0xc;
                goto LAB_1c000e653;
              }
            }
            else {
              if (bVar21 != 0xc) {
                if (bVar21 == 0xd) goto LAB_1c000e838;
                if (bVar21 == 0xe) {
                  local_res20[0] = *(undefined4 *)(param_1 + 0xd98);
                  if ((uint)(ushort)(((ushort)((uint)*(undefined4 *)(param_1 + 0xd98) >> 8) & 0xff)
                                    << 2) <= *(uint *)(param_1 + 0xd8c)) {
                    uVar12 = (uint)*(byte *)(*(longlong *)(param_1 + 0x1300) + 7);
                    *(undefined1 *)(param_1 + 0x1323) = 0xf;
                    iVar19 = (int)*(undefined8 *)(param_1 + 0xd90);
                    goto LAB_1c000e590;
                  }
                  goto LAB_1c000e280;
                }
                if (bVar21 == 0xf) {
                  *(undefined1 *)(param_1 + 0x1323) = *(undefined1 *)(param_1 + 0x1358);
                  if ((*(short *)(param_1 + 0xd64) == 0) &&
                     (1 < *(byte *)(*(longlong *)(param_1 + 0xd90) + 4))) {
                    lVar16 = (ulonglong)
                             (byte)(*(char *)(param_1 + 0x132a) + *(char *)(param_1 + 0x1328)) *
                             0x88;
                    uVar11 = 2;
                    if (*(char *)(lVar16 + 0xac + lVar4) == '\x03') {
                      uVar11 = 4;
                    }
                    *(undefined1 *)(lVar16 + 0xac + lVar4) = uVar11;
                  }
                  bVar10 = true;
                  if (*(char *)(param_1 + 0x1358) == '\f') {
                    *(char *)(param_1 + 0x132a) = *(char *)(param_1 + 0x132a) + '\x01';
                  }
                  else {
                    *(char *)(param_1 + 0x1328) = *(char *)(param_1 + 0x1328) + '\x01';
                  }
                  goto LAB_1c000e1a7;
                }
                goto LAB_1c000e1a4;
              }
              if (*(byte *)(param_1 + 0x132a) != *(byte *)(param_1 + 0x132b)) {
                *(undefined1 *)(param_1 + 0x1323) = 0xd;
                local_res20[0] = *(undefined4 *)(param_1 + 0x1261);
                bVar21 = *(byte *)(*(longlong *)(param_1 + 0xd90) + 0xc +
                                  (ulonglong)
                                  *(byte *)((ulonglong)*(byte *)(param_1 + 0x132a) + 0x132d +
                                           param_1) * 4);
                goto LAB_1c000e67f;
              }
            }
            *(undefined1 *)(param_1 + 0x1323) = 0xf0;
            goto LAB_1c000e628;
          }
LAB_1c000e838:
          bVar21 = *(char *)(param_1 + 0x132a) + *(char *)(param_1 + 0x1328);
          lVar16 = *(longlong *)(param_1 + 0x12f8);
          lVar6 = *(longlong *)(param_1 + 0x1300);
          _Dst = (void *)(lVar4 + 0x40 + (ulonglong)bVar21 * 0x88);
          memset(_Dst,0,0x88);
          local_64 = 0x680;
          uVar13 = FindSasAddressFromScsi
                             (param_1,*(char *)(lVar6 + 5),*(char *)(lVar6 + 4),&local_58,&local_64)
          ;
          if ((char)uVar13 != '\0') {
            puVar17 = (undefined1 *)((longlong)_Dst + 0x58);
            lVar20 = 8;
            puVar18 = local_51;
            do {
              uVar11 = *puVar18;
              puVar18 = puVar18 + -1;
              *puVar17 = uVar11;
              puVar17 = puVar17 + 1;
              lVar20 = lVar20 + -1;
            } while (lVar20 != 0);
          }
          if (bVar21 == 0) {
            *(uint *)(param_1 + 0x1330) = local_64 & 0x680;
          }
          memcpy(_Dst,(void *)(lVar6 + 0x28),8);
          memcpy((void *)((longlong)_Dst + 8),(void *)(lVar6 + 0x30),0x10);
          memcpy((void *)((longlong)_Dst + 0x28),(void *)(lVar6 + 0x40),4);
          memcpy(&local_68,(void *)(lVar6 + 0x10),4);
          if ((((local_68 == 'A') && (local_67 == 'T')) && (local_66 == 'A')) && (local_65 == ' '))
          {
            cVar14 = '\x01';
            _Src = (void *)(lVar6 + 0x14);
            _Size = 0x14;
          }
          else {
            _Src = (void *)(lVar6 + 0x18);
            _Size = 0x10;
          }
          memcpy((void *)((longlong)_Dst + 0x30),_Src,_Size);
          if (*(char *)(lVar6 + 0x65) == '\x05') {
            uVar11 = 4;
          }
          else if (*(char *)(lVar6 + 0x65) == '\0') {
            if ((*(char *)(lVar6 + 100) == '\x01') && (*(char *)(param_1 + 0x1323) == '\t')) {
              uVar11 = 1;
            }
            else {
              uVar11 = 0;
              if (*(short *)(lVar6 + 0x74) != 0) {
                uVar11 = 3;
              }
            }
          }
          else {
            uVar11 = 2;
            if ((*(char *)(lVar4 + 0x29) == '\x01') && (*(char *)(param_1 + 0x1323) == '\t')) {
              *(byte *)(lVar4 + 0x2a) = bVar21;
            }
          }
          *(undefined1 *)((longlong)_Dst + 0x68) = uVar11;
          if (*(char *)(param_1 + 0x1323) == '\r') {
            *(undefined1 *)((longlong)_Dst + 0x69) = 2;
            *(undefined1 *)(param_1 + 0x1358) = 0xc;
          }
          else {
            *(undefined1 *)((longlong)_Dst + 0x69) = 1;
            *(undefined1 *)(param_1 + 0x1358) = 8;
          }
          lVar20 = FindSasAddressTableEntry(param_1,*(char *)(lVar6 + 5),*(char *)(lVar6 + 4),0x680)
          ;
          if (lVar20 == 0) {
            bVar21 = (-cVar14 & 2U) + 1;
          }
          else {
            bVar21 = (*(byte *)(lVar20 + 0xc) | 0x40) >> 6;
          }
          *(byte *)((longlong)_Dst + 0x6c) = bVar21;
          *(undefined2 *)((longlong)_Dst + 0x6a) = 0x200;
          *(uint *)((longlong)_Dst + 0x7c) = (uint)*(byte *)(lVar6 + 7);
          cVar14 = *(char *)(lVar16 + 7);
          if (cVar14 == '\x02') {
            uVar12 = *(int *)(lVar16 + 0x10) + 1;
LAB_1c000ea46:
            *(uint *)((longlong)_Dst + 0x80) = uVar12;
          }
          else {
            if (cVar14 == '\0') {
              uVar12 = (*(int *)(lVar16 + 0x10) + 1U) / (uint)*(byte *)(lVar16 + 0x24);
              goto LAB_1c000ea46;
            }
            if (cVar14 == '\x01') {
              uVar12 = ((*(int *)(lVar16 + 0x10) + 1U) / (uint)*(byte *)(lVar16 + 0x24)) * 2;
              goto LAB_1c000ea46;
            }
          }
          *(undefined4 *)((longlong)_Dst + 0x84) = 0;
          *(undefined1 *)(param_1 + 0x1323) = 0xe;
          local_res20[0] = 0xa010000;
          SendConfigPageMessage(param_1,'\0',local_res20,0,0);
          bVar8 = bVar9;
          goto LAB_1c000e555;
        }
        if (bVar21 == 8) {
          if (*(byte *)(param_1 + 0x1328) != *(byte *)(param_1 + 0x1329)) {
            *(char *)(param_1 + 0x1323) = (*(char *)(lVar4 + 0x2c) != '\0') + '\t';
            local_res20[0] = *(undefined4 *)(param_1 + 0x1261);
            bVar21 = *(byte *)(*(longlong *)(param_1 + 0x12f8) + 0x2b +
                              (ulonglong)*(byte *)(param_1 + 0x1328) * 4);
LAB_1c000e67f:
            uVar12 = (uint)bVar21;
            iVar19 = (int)*(undefined8 *)(param_1 + 0x1300);
LAB_1c000e590:
            cVar14 = '\x01';
LAB_1c000e597:
            SendConfigPageMessage(param_1,cVar14,local_res20,uVar12,iVar19);
            goto LAB_1c000e1a4;
          }
          cVar14 = (-(*(char *)(*(longlong *)(param_1 + 0x12f8) + 7) != '\0') & 0x1aU) - 0x10;
LAB_1c000e653:
          *(char *)(param_1 + 0x1323) = cVar14;
LAB_1c000e628:
          bVar10 = true;
          goto LAB_1c000e1a7;
        }
        if (bVar21 == 1) {
          *(undefined1 *)(param_1 + 0x1323) = 2;
          goto LAB_1c000e628;
        }
        if (bVar21 == 2) {
          *(undefined1 *)(param_1 + 0x1323) = 3;
          bVar21 = *(byte *)(lVar4 + 0x1c);
          lVar16 = *(longlong *)(param_1 + 0xe50);
          if (((*(ushort *)(param_1 + 0x134) & 0x8000) != 0) &&
             (bVar21 + 1 <= (uint)*(byte *)(lVar16 + 8))) {
            local_res20[0] = 0x8000000;
            iVar19 = 0;
            uVar12 = (uint)CONCAT11(*(undefined1 *)(lVar16 + 0xd + (ulonglong)bVar21 * 8),
                                    *(undefined1 *)(lVar16 + 0xc + (ulonglong)bVar21 * 8));
            *(uint *)(param_1 + 0x1334) = uVar12;
            cVar14 = '\0';
            goto LAB_1c000e597;
          }
          *(undefined4 *)(lVar4 + 0x14) = 1000;
        }
        else {
          if (bVar21 == 3) {
            *(char *)(param_1 + 0x1323) = (*(char *)(lVar4 + 0x2c) != '\x01') + '\x04';
            local_res20[0] = *(undefined4 *)(param_1 + 0xd98);
            uVar12 = *(uint *)(param_1 + 0x1334);
            iVar19 = (int)*(undefined8 *)(param_1 + 0x12f8);
            goto LAB_1c000e590;
          }
          if (bVar21 == 4) {
            lVar16 = *(longlong *)(param_1 + 0x1310);
            iVar19 = *(int *)(lVar4 + 0x18) + -0xac;
            local_60 = iVar19;
            if (*(longlong *)(**(longlong **)(param_1 + 0x158) + 8) == 0) {
              lVar6 = *(longlong *)(lVar16 + 0x38);
              _Dst_00 = (uint *)(lVar6 + 0x138);
              uVar12 = StorPortGetPhysicalAddress(param_1,lVar16,_Dst_00,&local_5c);
              memset(_Dst_00,0,0x30);
              *(undefined1 *)_Dst_00 = *(undefined1 *)(*(longlong *)(param_1 + 0x12f8) + 4);
              *(undefined1 *)(lVar6 + 0x139) = *(undefined1 *)(*(longlong *)(param_1 + 0x12f8) + 5);
              *(undefined2 *)(lVar6 + 0x13b) = 0x600;
              *(undefined1 *)(lVar6 + 0x145) = *(undefined1 *)(lVar16 + 7);
              *(int *)(lVar6 + 0x160) = iVar19;
              *(undefined4 *)(lVar6 + 0x140) = 0x8000000;
              *(undefined2 *)(lVar6 + 0x150) = 0x112;
              *(undefined1 *)(lVar6 + 0x152) = 0x83;
              *(char *)(lVar6 + 0x154) = (char)iVar19;
              *(char *)(lVar6 + 0x153) = (char)((uint)iVar19 >> 8);
              *(undefined1 *)(lVar6 + 0x13d) = 0x28;
              uVar15 = *(int *)(param_1 + 0x670) - *(int *)(param_1 + 0x58);
              *(uint *)(lVar6 + 0x164) = uVar15;
              if (iVar19 == 0) {
                BuildZeroLenSGE((ulonglong)uVar15,(longlong)_Dst_00,uVar12);
              }
              else {
                uVar2 = *(undefined4 *)(lVar16 + 0xc);
                uVar3 = *(undefined4 *)(lVar16 + 0x10);
                *(undefined4 *)(lVar16 + 0xc) = 0x40;
                *(int *)(lVar16 + 0x10) = local_60;
                local_5c = BuildScatterGather(param_1,lVar16,(int)lVar4 + 0x40,_Dst_00,uVar12);
                *(undefined4 *)(lVar16 + 0xc) = uVar2;
                *(undefined4 *)(lVar16 + 0x10) = uVar3;
              }
              memcpy(*(void **)(param_1 + 0x6f8),_Dst_00,(ulonglong)*(ushort *)(param_1 + 300));
              *(undefined1 *)(param_1 + 0x1323) = 5;
              **(uint **)(param_1 + 0x38) = uVar12;
              LOCK();
              UNLOCK();
              bVar8 = bVar9;
              goto LAB_1c000e555;
            }
          }
          else {
            if (bVar21 == 5) {
              lVar16 = *(longlong *)(param_1 + 0x12f8);
              *(int *)(lVar4 + 0x20) =
                   (int)(((ulonglong)*(uint *)(lVar16 + 0x14) << 0x20) +
                         (ulonglong)*(uint *)(lVar16 + 0x10) + 1 >> 0xb);
              *(uint *)(lVar4 + 0x24) = *(uint *)(lVar16 + 0x18) >> 1;
              *(undefined1 *)(lVar4 + 0x28) =
                   *(undefined1 *)((longlong)local_res20 + ((ulonglong)*(byte *)(lVar16 + 7) - 8));
              if ((*(byte *)(lVar16 + 8) & 8) == 0) {
                if (*(char *)(lVar16 + 9) == '\0') {
                  *(undefined1 *)(lVar4 + 0x29) = 0;
                }
                else if (*(char *)(lVar16 + 9) == '\x02') {
                  *(undefined1 *)(lVar4 + 0x29) = 3;
                }
                else if ((*(byte *)(lVar16 + 8) & 4) == 0) {
                  *(undefined1 *)(lVar4 + 0x29) = 1;
                }
                else {
                  *(undefined1 *)(lVar4 + 0x29) = 2;
                  bVar7 = true;
                }
              }
              else {
                *(undefined1 *)(lVar4 + 0x29) = 4;
              }
              *(undefined1 *)(lVar4 + 0x2a) = 0;
              if (*(char *)(lVar4 + 0x2c) == '\x02') {
                *(undefined1 *)(lVar4 + 0x40) = 0;
                *(undefined1 *)(lVar4 + 0x51) = 0;
                *(undefined2 *)(lVar4 + 0x58) = 0;
                *(undefined1 *)(lVar4 + 0x5a) = 0;
                *(undefined2 *)(lVar4 + 0x5c) = 0x200;
                *(undefined8 *)(lVar4 + 0x6c) = 0;
                iVar19 = *(int *)(lVar16 + 0x10);
                *(undefined4 *)(lVar4 + 0x78) = 0;
                *(int *)(lVar4 + 0x74) = iVar19 + 1;
                *(undefined4 *)(lVar4 + 0x7c) = *(undefined4 *)(lVar16 + 0x18);
                *(undefined4 *)(lVar4 + 0x80) = 0x80;
                *(undefined8 *)(lVar4 + 0x84) = 0xffffffffffffffff;
                *(undefined8 *)(lVar4 + 0x8c) = 0xffffffffffffffff;
                *(undefined4 *)(lVar4 + 0x94) = 0x10;
                *(uint *)(lVar4 + 0x98) =
                     (*(int *)(lVar16 + 0x10) + 1U) / (uint)(*(int *)(lVar4 + 0x80) << 4);
              }
              if (!bVar7) {
                bVar10 = true;
                *(undefined1 *)(param_1 + 0x1323) = 7;
                goto LAB_1c000e1a7;
              }
              *(undefined1 *)(param_1 + 0x1323) = 6;
              uVar11 = *(undefined1 *)(lVar16 + 4);
              uVar1 = *(undefined1 *)(lVar16 + 5);
              puVar5 = *(undefined8 **)(param_1 + 0xd68);
              *puVar5 = 0;
              puVar5[1] = 0;
              puVar5[2] = 0;
              puVar5[3] = 0;
              *(undefined1 *)((longlong)puVar5 + 4) = uVar11;
              *(undefined1 *)puVar5 = 1;
              *(undefined1 *)((longlong)puVar5 + 3) = 0x15;
              *(undefined1 *)((longlong)puVar5 + 5) = uVar1;
              *(undefined1 *)((longlong)puVar5 + 6) = *(undefined1 *)(param_1 + 0xeb8);
              *(uint *)(puVar5 + 1) = *(byte *)(param_1 + 0xeae) | 0x10000000;
              **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
              LOCK();
              UNLOCK();
              goto LAB_1c000e1a4;
            }
            if (bVar21 == 6) {
              *(undefined1 *)(lVar4 + 0x2a) = 0;
              uVar13 = *(ulonglong *)(*(longlong *)(param_1 + 0x1340) + 0x18);
              if (uVar13 != 0) {
                *(char *)(lVar4 + 0x2a) =
                     'd' - (char)((ulonglong)
                                  (*(longlong *)(*(longlong *)(param_1 + 0x1340) + 0x20) * 100) /
                                 uVar13);
              }
              *(undefined1 *)(param_1 + 0x1323) = 7;
            }
            else if (bVar21 != 7) goto LAB_1c000e1a4;
            if (*(char *)(lVar4 + 0x2b) == -0xe) {
              bVar10 = true;
              *(undefined1 *)(param_1 + 0x1323) = 0xf0;
              goto LAB_1c000e1a7;
            }
            uVar11 = *(undefined1 *)(*(longlong *)(param_1 + 0x12f8) + 0x24);
            *(undefined1 *)(lVar4 + 0x2b) = uVar11;
            *(undefined1 *)(param_1 + 0x1329) = uVar11;
            if (*(char *)(lVar4 + 0x2c) == '\0') {
              if (0xf0 < *(byte *)(lVar4 + 0x2b)) {
                *(undefined1 *)(param_1 + 0x1329) = 0xf0;
                *(undefined1 *)(lVar4 + 0x2b) = 0xf1;
              }
            }
            else {
              *(undefined1 *)(param_1 + 0x1329) = 1;
            }
            if ((*(char *)(lVar4 + 0x2c) != '\0') ||
               ((*(byte *)(lVar4 + 0x2b) - 1) * 0x88 + 0xac <= *(uint *)(lVar4 + 0x18))) {
              *(undefined1 *)(param_1 + 0x1328) = 0;
              *(undefined1 *)(param_1 + 0x132a) = 0;
              *(undefined1 *)(param_1 + 0x1323) = 8;
              goto LAB_1c000e628;
            }
          }
        }
LAB_1c000e280:
        bVar8 = true;
        bVar9 = true;
LAB_1c000e1ab:
        bVar10 = true;
        if (*(int *)(lVar4 + 0x14) == 0) {
          *(undefined4 *)(lVar4 + 0x14) = 1;
        }
        *(undefined1 *)(param_1 + 0x1323) = 0xf0;
      }
      else {
LAB_1c000e1a7:
        if (bVar8) goto LAB_1c000e1ab;
      }
    } while (bVar10);
  }
  return;
}



===== HpSasGetRaidFeatures @ 1c000eab8 =====

void HpSasGetRaidFeatures(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x1308);
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else if ((*(int *)(lVar1 + 0x440) == 0) || (*(int *)(lVar1 + 0x440) == *(int *)(param_1 + 0x1354))
          ) {
    *(undefined4 *)(lVar1 + 0x1c) = 0x62;
    *(undefined4 *)(lVar1 + 0x40) = 0;
    *(undefined2 *)(lVar1 + 0x44) = 0;
    *(undefined4 *)(lVar1 + 0x48) = 0;
    *(undefined4 *)(lVar1 + 0x80) = 0x80;
    *(undefined4 *)(lVar1 + 200) = 0x80;
    *(undefined1 *)(lVar1 + 0x78) = 1;
    *(undefined1 *)(lVar1 + 0x9c) = 2;
    *(undefined4 *)(lVar1 + 0xa4) = 0;
    *(undefined1 *)(lVar1 + 0xc0) = 9;
    *(undefined1 *)(lVar1 + 0xe4) = 0xfe;
    *(undefined1 *)(lVar1 + 0x3d8) = 0xff;
    *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0x1310) = 0;
    *(undefined1 *)(param_1 + 0x6a1) = 0;
  }
  else {
    *(undefined4 *)(lVar1 + 0x14) = 3;
    *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
    StorPortNotification(0,param_1);
  }
  return;
}



===== HpSasSetRaidControl @ 1c000eb94 =====

void HpSasSetRaidControl(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x1308);
  bVar2 = false;
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else if ((*(int *)(lVar1 + 0x38) == 0) || (*(int *)(lVar1 + 0x38) == *(int *)(param_1 + 0x1354)))
  {
    lVar3 = 0;
    do {
      if ((&CsmiRaidClrCfgSig + lVar3)[lVar1 + -0x1c0017138] != (&CsmiRaidClrCfgSig)[lVar3]) {
        *(undefined4 *)(lVar1 + 0x14) = 3;
        bVar2 = true;
        *(undefined4 *)(lVar1 + 0x94) = 0x3ed;
      }
      lVar3 = lVar3 + 1;
    } while (lVar3 < 7);
    if (!bVar2) {
      if (*(char *)(lVar1 + 0x1c) == '\0') {
        if (*(byte *)(lVar1 + 0x1d) < 2) {
          if (*(char *)(lVar1 + 0x1e) == '\0') {
            *(undefined1 *)(lVar1 + 0x98) = 0;
          }
          else {
            *(undefined4 *)(lVar1 + 0x14) = 3;
            *(undefined4 *)(lVar1 + 0x94) = 0x3eb;
          }
        }
        else {
          *(undefined4 *)(lVar1 + 0x14) = 3;
          *(undefined4 *)(lVar1 + 0x94) = 0x3ea;
        }
      }
      else {
        *(undefined4 *)(lVar1 + 0x14) = 3;
        *(undefined4 *)(lVar1 + 0x94) = 0x3e9;
      }
    }
    *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0x1310) = 0;
    *(undefined1 *)(param_1 + 0x6a1) = 0;
  }
  else {
    *(undefined4 *)(lVar1 + 0x14) = 3;
    *(undefined4 *)(lVar1 + 0x94) = 0x3f7;
    *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
    StorPortNotification(0,param_1);
  }
  return;
}



===== HpSasPhyControl @ 1c000ecd4 =====

void HpSasPhyControl(longlong param_1)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  char cVar9;
  char *pcVar10;
  
  lVar2 = *(longlong *)(param_1 + 0x1308);
  bVar4 = false;
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x1324) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
    return;
  }
  do {
    cVar9 = *(char *)(param_1 + 0x1324);
    bVar5 = false;
    if (cVar9 == '\x01') {
      iVar7 = *(int *)(lVar2 + 0x1c);
      if (iVar7 == 0) {
        *(undefined1 *)(param_1 + 0x1324) = 0xf0;
LAB_1c000ef6e:
        *(undefined4 *)(lVar2 + 0x14) = 0;
LAB_1c000ef72:
        bVar5 = true;
      }
      else {
        *(undefined4 *)(lVar2 + 0x14) = 3;
        if (((iVar7 != 0x100) && (iVar7 != 3)) ||
           ((*(short *)(lVar2 + 0x22) == 0 && (*(char *)(lVar2 + 0x24) == '\0')))) {
          if (iVar7 != 0x100) {
            *(undefined4 *)(lVar2 + 0x14) = 1;
            pcVar10 = (char *)(param_1 + 0x1266);
            *(undefined1 *)(param_1 + 0x1324) = 2;
            cVar9 = '\x01';
            iVar7 = (int)*(undefined8 *)(param_1 + 0x12b0);
            goto LAB_1c000f006;
          }
          if (0x42b < *(uint *)(lVar2 + 0x18)) {
            *(undefined2 *)(lVar2 + 0x22) = 0xfc;
            *(undefined1 *)(lVar2 + 0x24) = 4;
            *(undefined2 *)(lVar2 + 0x58) = 0x802;
            *(undefined2 *)(lVar2 + 0x154) = 0x902;
            *(undefined2 *)(lVar2 + 0x250) = 0x801;
            *(undefined2 *)(lVar2 + 0x34c) = 0x901;
            *(undefined4 *)(lVar2 + 0x14) = 0;
            *(undefined1 *)(param_1 + 0x1324) = 0xf0;
            goto LAB_1c000ef72;
          }
          bVar4 = true;
          goto LAB_1c000f020;
        }
        bVar4 = true;
      }
LAB_1c000f01b:
      if (bVar4) goto LAB_1c000f020;
    }
    else {
      if (cVar9 != '\x02') {
        if (cVar9 == '\x03') {
          lVar3 = *(longlong *)(param_1 + 0x12b8);
          bVar8 = *(byte *)(lVar2 + 0x20);
          if (*(int *)(lVar2 + 0x1c) == 3) {
            pbVar1 = (byte *)(lVar3 + 0x16 + (ulonglong)bVar8 * 0xc);
            *pbVar1 = *pbVar1 | 4;
          }
          else {
            if (*(char *)(lVar2 + 0x24) != '\0') {
              if (*(char *)(lVar2 + 0x59) == '\b') {
                *(undefined1 *)(lVar3 + 0x17 + (ulonglong)bVar8 * 0xc) = 0x88;
              }
              else {
                *(undefined1 *)(lVar3 + 0x17 + (ulonglong)bVar8 * 0xc) = 0x99;
              }
            }
            pbVar1 = (byte *)(lVar3 + 0x16 + (ulonglong)bVar8 * 0xc);
            *pbVar1 = *pbVar1 & 0xfb;
          }
          *(undefined1 *)(param_1 + 0x1324) = 4;
          pcVar10 = (char *)(param_1 + 0x126e);
          iVar7 = (int)*(undefined8 *)(param_1 + 0x12b8);
          cVar9 = '\x02';
        }
        else {
          if (cVar9 != '\x04') {
            if (cVar9 == '\x05') {
              *(undefined1 *)(param_1 + 0x1324) = 6;
              iVar7 = *(int *)(lVar2 + 0x1c);
              pcVar10 = *(char **)(param_1 + 0xd68);
              pcVar10[0] = '\0';
              pcVar10[1] = '\0';
              pcVar10[2] = '\0';
              pcVar10[3] = '\0';
              pcVar10[4] = '\0';
              pcVar10[5] = '\0';
              pcVar10[6] = '\0';
              pcVar10[7] = '\0';
              pcVar10[8] = '\0';
              pcVar10[9] = '\0';
              pcVar10[10] = '\0';
              pcVar10[0xb] = '\0';
              pcVar10[0xc] = '\0';
              pcVar10[0xd] = '\0';
              pcVar10[0xe] = '\0';
              pcVar10[0xf] = '\0';
              pcVar10[0x10] = '\0';
              pcVar10[0x11] = '\0';
              pcVar10[0x12] = '\0';
              pcVar10[0x13] = '\0';
              pcVar10[0x14] = '\0';
              pcVar10[0x15] = '\0';
              pcVar10[0x16] = '\0';
              pcVar10[0x17] = '\0';
              pcVar10[0x18] = '\0';
              pcVar10[0x19] = '\0';
              pcVar10[0x1a] = '\0';
              pcVar10[0x1b] = '\0';
              pcVar10[0x1c] = '\0';
              pcVar10[0x1d] = '\0';
              pcVar10[0x1e] = '\0';
              pcVar10[0x1f] = '\0';
              *pcVar10 = (iVar7 != 1) + '\x06';
              pcVar10[3] = '\x1b';
              pcVar10[8] = -0x32;
              pcVar10[9] = -6;
              pcVar10[10] = '\0';
              pcVar10[0xb] = '\0';
              pcVar10[0xe] = *(char *)(lVar2 + 0x20);
              **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
              LOCK();
              UNLOCK();
            }
            else {
              if (cVar9 == '\x06') {
                *(undefined1 *)(param_1 + 0x1324) = 0xf0;
                if (*(short *)(param_1 + 0x1318) != 0) goto LAB_1c000ef72;
                goto LAB_1c000ef6e;
              }
              if (cVar9 == -0x10) {
                *(undefined1 *)(param_1 + 0x1324) = 0;
                *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
                StorPortNotification(0,param_1);
                *(undefined8 *)(param_1 + 0x1310) = 0;
                *(undefined1 *)(param_1 + 0x6a1) = 0;
                return;
              }
            }
            goto LAB_1c000f01b;
          }
          *(undefined1 *)(param_1 + 0x1324) = 5;
          pcVar10 = (char *)(param_1 + 0x126e);
          iVar7 = (int)*(undefined8 *)(param_1 + 0x12b8);
          cVar9 = '\x04';
        }
LAB_1c000f006:
        SendExtendedConfigPageMessage(param_1,cVar9,pcVar10,0,iVar7);
        goto LAB_1c000f01b;
      }
      lVar3 = *(longlong *)(param_1 + 0x12b0);
      if (*(byte *)(lVar3 + 0xc) <= *(byte *)(lVar2 + 0x20)) {
        *(undefined4 *)(lVar2 + 0x14) = 0x7d2;
        bVar4 = true;
      }
      bVar8 = *(byte *)(lVar3 + 0x11 + (ulonglong)*(byte *)(lVar2 + 0x20) * 0x10) & 1;
      if ((*(int *)(lVar2 + 0x1c) == 3) && (bVar8 != 0)) {
        bVar4 = true;
      }
      if (*(int *)(lVar2 + 0x1c) - 1U < 2) {
        uVar6 = *(uint *)(lVar2 + 0x2c) & 1;
        if ((uVar6 == 0) || (*(char *)(lVar2 + 0x24) == '\0')) {
          if ((uVar6 != 0) || ((*(short *)(lVar2 + 0x22) != 0 || (*(char *)(lVar2 + 0x24) != '\0')))
             ) {
            *(undefined4 *)(lVar2 + 0x14) = 3;
            goto LAB_1c000ef0d;
          }
        }
        else {
          if (*(short *)(lVar2 + 0x22) != 0xfc) {
            *(undefined2 *)(lVar2 + 0x22) = 0xfc;
            bVar4 = true;
            *(undefined4 *)(lVar2 + 0x14) = 3;
          }
          if (bVar8 != 0) {
LAB_1c000ef0d:
            bVar4 = true;
          }
        }
      }
      if (!bVar4) {
        *(undefined1 *)(param_1 + 0x1324) = 3;
        SendExtendedConfigPageMessage
                  (param_1,'\x01',(char *)(param_1 + 0x126e),0,
                   (int)*(undefined8 *)(param_1 + 0x12b8));
        return;
      }
LAB_1c000f020:
      bVar5 = true;
      if (*(int *)(lVar2 + 0x14) == 0) {
        *(undefined4 *)(lVar2 + 0x14) = 1;
      }
      *(undefined1 *)(param_1 + 0x1324) = 0xf0;
    }
    if (!bVar5) {
      return;
    }
  } while( true );
}



===== HpSasGetHotSpare @ 1c000f044 =====

void HpSasGetHotSpare(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  bool bVar7;
  uint local_res8 [2];
  uint local_res10 [2];
  undefined4 local_res18 [2];
  int iVar8;
  
  bVar4 = false;
  bVar3 = true;
  do {
    cVar5 = *(char *)(param_1 + 0x1326);
    bVar7 = false;
    if (cVar5 == '\x01') {
      *(undefined1 *)(param_1 + 0x132b) = 0;
      *(undefined2 *)(param_1 + 0x132d) = 0xffff;
      *(undefined2 *)(param_1 + 0x1326) = 2;
LAB_1c000f2de:
      bVar7 = true;
LAB_1c000f2e1:
      if (bVar4) goto LAB_1c000f2e6;
    }
    else {
      if (cVar5 == '\x02') {
        *(undefined1 *)(param_1 + 0x1326) = 3;
        local_res8[0] = 0x1060000;
LAB_1c000f2ac:
        iVar8 = 0;
        uVar6 = 0;
        cVar5 = '\0';
LAB_1c000f2b7:
        SendConfigPageMessage(param_1,cVar5,local_res8,uVar6,iVar8);
        goto LAB_1c000f2e1;
      }
      if (cVar5 == '\x03') {
        *(undefined1 *)(param_1 + 0x1326) = 4;
        if (*(short *)(param_1 + 0xd64) == 0x22) {
          bVar3 = false;
          goto LAB_1c000f2de;
        }
        local_res8[0] = *(uint *)(param_1 + 0xd98);
LAB_1c000f28f:
        iVar8 = (int)*(undefined8 *)(param_1 + 0xd90);
        uVar6 = 0;
LAB_1c000f1d7:
        cVar5 = '\x01';
        goto LAB_1c000f2b7;
      }
      if (cVar5 == '\x04') {
        lVar2 = *(longlong *)(param_1 + 0x12f8);
        uVar6 = *(int *)(lVar2 + 0x10) + 1;
        if (*(char *)(lVar2 + 7) == '\x01') {
          uVar6 = (uVar6 / *(byte *)(lVar2 + 0x24)) * 2;
        }
        if (bVar3) {
          *(uint *)(param_1 + 0x1338) =
               (uint)*(byte *)(*(longlong *)(param_1 + 0xd90) + 0x24) * 0x800 + uVar6;
        }
        else {
          *(uint *)(param_1 + 0x1338) = uVar6 + 0x20000;
        }
        *(undefined1 *)(param_1 + 0x1326) = 5;
        local_res8[0] = 0x1050000;
        goto LAB_1c000f2ac;
      }
      if (cVar5 != '\x05') {
        if (cVar5 == '\x06') {
          *(undefined1 *)(param_1 + 0x1326) = 7;
          lVar2 = *(longlong *)(param_1 + 0xd90);
          bVar1 = *(byte *)(param_1 + 0x1327);
          if (bVar1 == *(byte *)(lVar2 + 8)) {
            *(undefined1 *)(param_1 + 0x1326) = 0xf0;
            goto LAB_1c000f2de;
          }
          if ((*(byte *)(lVar2 + 0xf + (ulonglong)bVar1 * 4) & 1) != 0) {
            local_res8[0] = *(uint *)(param_1 + 0x1261);
            uVar6 = (uint)*(byte *)(lVar2 + 0xc + (ulonglong)bVar1 * 4);
            iVar8 = (int)*(undefined8 *)(param_1 + 0x1300);
            goto LAB_1c000f1d7;
          }
          *(byte *)(param_1 + 0x1327) = bVar1 + 1;
LAB_1c000f17a:
          *(undefined1 *)(param_1 + 0x1326) = 6;
          goto LAB_1c000f2de;
        }
        if (cVar5 == '\a') {
          lVar2 = *(longlong *)(param_1 + 0x1300);
          bVar1 = *(byte *)(param_1 + 0x132b);
          local_res10[0] = 0x680;
          FindSasAddressFromScsi
                    (param_1,*(char *)(lVar2 + 5),*(char *)(lVar2 + 4),local_res18,local_res10);
          uVar6 = *(uint *)(param_1 + 0x1330);
          if (*(uint *)(param_1 + 0x1338) <= *(uint *)(lVar2 + 0x68)) {
            if (*(char *)(lVar2 + 0x65) == '\x01') {
              if (uVar6 != (local_res10[0] & 0x680)) {
                if ((((*(char *)(lVar2 + 0x10) == 'A') && (*(char *)(lVar2 + 0x11) == 'T')) &&
                    (*(char *)(lVar2 + 0x12) == 'A')) && (*(char *)(lVar2 + 0x13) == ' ')) {
                  bVar7 = (uVar6 & 0x400) == 0;
                  goto LAB_1c000f155;
                }
                if ((uVar6 >> 10 & 1) == 0) goto LAB_1c000f174;
              }
            }
            else {
              bVar7 = uVar6 == (local_res10[0] & 0x680);
LAB_1c000f155:
              if (!bVar7) goto LAB_1c000f174;
            }
            if (bVar1 < 2) {
              *(undefined1 *)((ulonglong)bVar1 + 0x132d + param_1) =
                   *(undefined1 *)(param_1 + 0x1327);
              *(char *)(param_1 + 0x132b) = *(char *)(param_1 + 0x132b) + '\x01';
            }
          }
LAB_1c000f174:
          *(char *)(param_1 + 0x1327) = *(char *)(param_1 + 0x1327) + '\x01';
          goto LAB_1c000f17a;
        }
        if (cVar5 == -0x10) {
          *(undefined1 *)(param_1 + 0x1326) = 0;
          if (*(char *)(param_1 + 0x1323) != '\0') {
            HpSasGetRaidConfig(param_1);
            return;
          }
          if (*(char *)(param_1 + 0x1325) == '\0') {
            return;
          }
          HpSasGetLocation(param_1);
          return;
        }
        goto LAB_1c000f2e1;
      }
      *(undefined1 *)(param_1 + 0x1326) = 6;
      local_res8[0] = *(uint *)(param_1 + 0xd98);
      if ((local_res8[0] >> 8 & 0xff) * 4 <= *(uint *)(param_1 + 0xd8c)) goto LAB_1c000f28f;
      bVar4 = true;
LAB_1c000f2e6:
      bVar7 = true;
      *(undefined1 *)(param_1 + 0x1326) = 0xf0;
    }
    if (!bVar7) {
      return;
    }
  } while( true );
}



===== HpSasGetLocation @ 1c000f31c =====

void HpSasGetLocation(longlong param_1)

{
  uint *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  byte bVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  char cVar12;
  undefined1 *puVar13;
  longlong lVar14;
  longlong lVar15;
  char *pcVar16;
  uint uVar17;
  int iVar18;
  byte bVar19;
  byte bVar20;
  byte local_res8;
  uint local_res10 [2];
  uint local_res18 [2];
  undefined4 local_res20 [2];
  int iVar21;
  
  lVar3 = *(longlong *)(param_1 + 0x1308);
  uVar17 = 0xff;
  local_res8 = 0xff;
  bVar5 = false;
  bVar20 = 0xff;
  bVar19 = 0xff;
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    *(undefined1 *)(param_1 + 0x1325) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  else {
    do {
      bVar8 = *(byte *)(param_1 + 0x1325);
      bVar6 = false;
      if (bVar8 < 0xf1) {
        if (bVar8 == 0xf0) {
LAB_1c000f91b:
          bVar5 = false;
          *(undefined1 *)(param_1 + 0x1325) = 0;
          *(undefined2 *)(*(longlong *)(param_1 + 0x1310) + 3) = 1;
          StorPortNotification(0);
          *(undefined8 *)(param_1 + 0x1310) = 0;
          *(undefined1 *)(param_1 + 0x6a1) = 0;
LAB_1c000f94c:
          uVar17 = (uint)local_res8;
          goto LAB_1c000f950;
        }
        if (9 < bVar8) {
          if (bVar8 == 10) {
            *(undefined2 *)(param_1 + 0x1325) = 0x10b;
            *(undefined1 *)(param_1 + 0x132a) = 0;
            HpSasGetHotSpare(param_1);
            goto LAB_1c000f94c;
          }
          if (bVar8 == 0xb) {
            bVar6 = true;
            bVar8 = *(char *)(param_1 + 0x1328) - *(char *)(*(longlong *)(param_1 + 0x12f8) + 0x24);
            if (bVar8 == *(byte *)(param_1 + 0x132b)) {
              *(undefined1 *)(param_1 + 0x1325) = 0xf0;
            }
            else {
              local_res8 = *(byte *)(*(longlong *)(param_1 + 0xd90) + 0xc +
                                    (ulonglong)*(byte *)((ulonglong)bVar8 + 0x132d + param_1) * 4);
              uVar17 = (uint)local_res8;
              *(char *)(lVar3 + 0x21) = *(char *)(lVar3 + 0x21) + '\x01';
              *(undefined1 *)(param_1 + 0x1325) = 8;
            }
            goto LAB_1c000f950;
          }
          if (bVar8 == 0xc) {
            lVar4 = *(longlong *)(param_1 + 0x1300);
            if (*(char *)(lVar4 + 0x65) == '\x01') {
              *(char *)(lVar3 + 0x21) = *(char *)(lVar3 + 0x21) + -1;
              *(char *)(param_1 + 0x1329) = *(char *)(param_1 + 0x1329) + '\x01';
              *(undefined1 *)(param_1 + 0x1325) = 0x10;
              goto LAB_1c000f5e4;
            }
            bVar19 = *(byte *)(lVar4 + 5);
            bVar20 = *(byte *)(lVar4 + 4);
            if (*(char *)(param_1 + 0x1328) == '\0') {
              local_res18[0] = 0x680;
              uVar10 = FindSasAddressFromScsi(param_1,bVar19,bVar20,local_res20,local_res18);
              if ((char)uVar10 != '\0') {
                *(uint *)(param_1 + 0x1330) = local_res18[0] & 0x680;
              }
            }
LAB_1c000f886:
            pcVar16 = (char *)(param_1 + 0x1286);
            *(undefined1 *)(param_1 + 0x1325) = 0xe;
            iVar18 = (uint)bVar20 + (uint)bVar19 * 0x100 + 0x10000000;
            iVar21 = (int)*(undefined8 *)(param_1 + 0x12d0);
          }
          else {
            if (bVar8 == 0xd) goto LAB_1c000f886;
            if (bVar8 != 0xe) {
              if (bVar8 == 0xf) {
                if (*(short *)(param_1 + 0xd64) != 0) goto LAB_1c000f4fe;
                lVar4 = *(longlong *)(param_1 + 0x12f0);
                lVar14 = (ulonglong)
                         (byte)(*(char *)(param_1 + 0x1328) - *(char *)(param_1 + 0x1329)) * 0x60;
                puVar1 = (uint *)(lVar14 + 0x24 + lVar3);
                *puVar1 = *puVar1 | 4;
                if ((*(int *)(lVar4 + 0xc) == 0) && (*(int *)(lVar4 + 0x10) == 0)) {
                  memcpy((void *)(lVar3 + 0x38 + lVar14),"Internal",8);
                }
                else {
                  lVar15 = 8;
                  puVar11 = (undefined1 *)(lVar3 + 0x38 + lVar14);
                  puVar13 = (undefined1 *)(lVar4 + 0x13);
                  do {
                    uVar2 = *puVar13;
                    puVar13 = puVar13 + -1;
                    *puVar11 = uVar2;
                    puVar11 = puVar11 + 1;
                    lVar15 = lVar15 + -1;
                  } while (lVar15 != 0);
                }
                puVar1 = (uint *)(lVar14 + 0x24 + lVar3);
                *puVar1 = *puVar1 | 8;
                memcpy((void *)(lVar3 + 0x40 + lVar14),"Not Supported",0xe);
                puVar1 = (uint *)(lVar14 + 0x24 + lVar3);
                *puVar1 = *puVar1 | 0x40;
                uVar17 = (uint)local_res8;
                *(undefined1 *)(lVar14 + 0x81 + lVar3) = 0;
              }
              else if (bVar8 != 0x10) goto LAB_1c000f950;
              if (*(char *)(param_1 + 0x132c) != '\0') {
                *(char *)(param_1 + 0x1328) = *(char *)(param_1 + 0x1328) + '\x01';
                *(undefined1 *)(param_1 + 0x1325) = 9;
                goto LAB_1c000f5e4;
              }
              goto LAB_1c000f91b;
            }
            if (*(short *)(param_1 + 0xd64) != 0) goto LAB_1c000f4fe;
            *(undefined4 *)(lVar3 + 0x14) = 0;
            lVar15 = 8;
            lVar4 = *(longlong *)(param_1 + 0x12d0);
            puVar13 = (undefined1 *)(lVar4 + 0x13);
            lVar14 = (ulonglong)(byte)(*(char *)(param_1 + 0x1328) - *(char *)(param_1 + 0x1329)) *
                     0x60;
            puVar1 = (uint *)(lVar14 + 0x24 + lVar3);
            *puVar1 = *puVar1 | 1;
            puVar11 = (undefined1 *)(lVar3 + 0x28 + lVar14);
            do {
              uVar2 = *puVar13;
              puVar13 = puVar13 + -1;
              *puVar11 = uVar2;
              puVar11 = puVar11 + 1;
              lVar15 = lVar15 + -1;
            } while (lVar15 != 0);
            puVar1 = (uint *)(lVar14 + 0x24 + lVar3);
            *puVar1 = *puVar1 | 2;
            *(undefined8 *)(lVar14 + 0x30 + lVar3) = 0;
            *(undefined1 *)(lVar14 + 0x31 + lVar3) = *(undefined1 *)(lVar3 + 0x1f);
            if (*(short *)(lVar4 + 10) == 0) {
              *(undefined1 *)(param_1 + 0x1325) = 0x10;
              bVar6 = true;
              goto LAB_1c000f94c;
            }
            puVar1 = (uint *)(lVar14 + 0x24 + lVar3);
            *puVar1 = *puVar1 | 0x20;
            pcVar16 = (char *)(param_1 + 0x12a6);
            *(undefined1 *)(lVar14 + 0x80 + lVar3) = *(undefined1 *)(lVar4 + 8);
            *(undefined1 *)(param_1 + 0x1325) = 0xf;
            iVar21 = (int)*(undefined8 *)(param_1 + 0x12f0);
            iVar18 = *(ushort *)(lVar4 + 10) + 0x10000000;
          }
          SendExtendedConfigPageMessage(param_1,'\x01',pcVar16,iVar18,iVar21);
          goto LAB_1c000f94c;
        }
        if (bVar8 == 9) {
          bVar8 = *(byte *)(param_1 + 0x1328);
          lVar4 = *(longlong *)(param_1 + 0x12f8);
          if ((bVar8 == 0) &&
             (*(undefined1 *)(lVar3 + 0x21) = *(undefined1 *)(lVar4 + 0x24),
             *(uint *)(lVar3 + 0x18) < (uint)*(byte *)(lVar4 + 0x24) * 0x60 + 8))
          goto LAB_1c000f4fe;
          bVar7 = *(byte *)(lVar4 + 0x24);
          if (bVar7 <= bVar8) {
            if (bVar8 == bVar7) {
              *(undefined1 *)(param_1 + 0x1325) = 10;
            }
            else {
              if (bVar8 <= bVar7) goto LAB_1c000f3d9;
              *(undefined1 *)(param_1 + 0x1325) = 0xb;
            }
LAB_1c000f5e4:
            bVar6 = true;
            goto LAB_1c000f950;
          }
          local_res8 = *(byte *)(lVar4 + 0x2b + (ulonglong)bVar8 * 4);
          uVar17 = (uint)local_res8;
LAB_1c000f3d9:
          *(undefined1 *)(param_1 + 0x1325) = 0xc;
          local_res10[0] = *(uint *)(param_1 + 0x1261);
          iVar21 = (int)*(undefined8 *)(param_1 + 0x1300);
LAB_1c000f414:
          cVar12 = '\x01';
LAB_1c000f41b:
          SendConfigPageMessage(param_1,cVar12,local_res10,uVar17,iVar21);
          goto LAB_1c000f94c;
        }
        if (bVar8 == 1) {
          *(undefined2 *)(param_1 + 0x1328) = 0;
          *(byte *)(param_1 + 0x1325) =
               (-((*(ushort *)(param_1 + 0x134) & 0x8000) != 0) & 0xfeU) + 4;
          goto LAB_1c000f5e4;
        }
        if (bVar8 == 2) {
          *(undefined1 *)(param_1 + 0x1325) = 3;
          local_res10[0] = 0x1030000;
LAB_1c000f579:
          uVar17 = 0;
LAB_1c000f48c:
          iVar21 = 0;
          cVar12 = '\0';
          goto LAB_1c000f41b;
        }
        if (bVar8 == 3) {
          *(undefined1 *)(param_1 + 0x1325) = 4;
          local_res10[0] = *(uint *)(param_1 + 0xd98);
          if (*(uint *)(param_1 + 0xd8c) < (local_res10[0] >> 8 & 0xff) * 4) goto LAB_1c000f4fe;
          iVar21 = (int)*(undefined8 *)(param_1 + 0xd90);
LAB_1c000f563:
          uVar17 = 0;
          goto LAB_1c000f414;
        }
        if (bVar8 == 4) {
          *(undefined1 *)(param_1 + 0x1325) = 5;
          local_res10[0] = 0x1020000;
          goto LAB_1c000f579;
        }
        if (bVar8 == 5) {
          *(undefined1 *)(param_1 + 0x1325) = 6;
          local_res10[0] = *(uint *)(param_1 + 0xd98);
          iVar21 = (int)*(undefined8 *)(param_1 + 0xe50);
          goto LAB_1c000f563;
        }
        if (bVar8 != 6) {
          if (bVar8 != 7) {
            if (bVar8 != 8) goto LAB_1c000f950;
            goto LAB_1c000f3d9;
          }
          *(undefined1 *)(param_1 + 0x1325) = 9;
          local_res10[0] = *(uint *)(param_1 + 0xd98);
          uVar17 = *(uint *)(param_1 + 0x1334);
          iVar21 = (int)*(undefined8 *)(param_1 + 0x12f8);
          goto LAB_1c000f414;
        }
        lVar4 = *(longlong *)(param_1 + 0xe50);
        *(undefined1 *)(param_1 + 0x132c) = 0;
        bVar8 = *(byte *)(lVar4 + 8);
        if (bVar8 != 0) {
          uVar10 = 0;
          do {
            uVar9 = uVar10;
            bVar7 = (byte)uVar9;
            if (*(char *)(lVar3 + 0x1e) == *(char *)(lVar4 + 0xc + uVar9 * 8)) break;
            bVar7 = bVar7 + 1;
            uVar10 = (ulonglong)bVar7;
          } while (bVar7 < bVar8);
          if (bVar7 < bVar8) {
            *(undefined1 *)(param_1 + 0x132c) = 1;
            *(undefined1 *)(param_1 + 0x1325) = 7;
            uVar17 = (uint)CONCAT11(*(undefined1 *)(lVar4 + 0xd + uVar9 * 8),
                                    *(undefined1 *)(lVar4 + 0xc + uVar9 * 8));
            local_res10[0] = 0x8000000;
            *(uint *)(param_1 + 0x1334) = uVar17;
            goto LAB_1c000f48c;
          }
        }
        bVar19 = *(byte *)(lVar3 + 0x1d);
        bVar20 = *(byte *)(lVar3 + 0x1e);
        if ((*(ushort *)(param_1 + 0x134) & 0x8000) != 0) {
          lVar4 = *(longlong *)(param_1 + 0xd90);
          bVar8 = *(byte *)(lVar4 + 4);
          if (bVar8 != 0) {
            uVar10 = 0;
            do {
              bVar7 = (byte)uVar10;
              if ((*(byte *)(lVar4 + 8 + uVar10 * 4) == bVar20) &&
                 (*(byte *)(lVar4 + 9 + uVar10 * 4) == bVar19)) break;
              bVar7 = bVar7 + 1;
              uVar10 = (ulonglong)bVar7;
            } while (bVar7 < bVar8);
            if (bVar7 < bVar8) {
              *(undefined4 *)(lVar3 + 0x14) = 0x7de;
              *(undefined1 *)(param_1 + 0x1325) = 0xf0;
              goto LAB_1c000f5e4;
            }
          }
        }
        *(undefined4 *)(lVar3 + 0x14) = 3;
        *(undefined4 *)(lVar3 + 0x24) = 0;
        *(undefined1 *)(lVar3 + 0x21) = 1;
        if (0x67 < *(uint *)(lVar3 + 0x18)) {
          local_res18[0] = 0x680;
          uVar10 = FindSasAddressFromScsi(param_1,bVar19,bVar20,local_res20,local_res18);
          uVar17 = (uint)local_res8;
          if ((char)uVar10 != '\0') {
            *(undefined4 *)(lVar3 + 0x14) = 1;
            *(undefined1 *)(param_1 + 0x1325) = 0xd;
            goto LAB_1c000f5e4;
          }
          *(undefined4 *)(lVar3 + 0x14) = 0x7de;
        }
LAB_1c000f4fe:
        bVar5 = true;
LAB_1c000f955:
        bVar6 = true;
        if (*(int *)(lVar3 + 0x14) == 0) {
          *(undefined4 *)(lVar3 + 0x14) = 1;
        }
        *(undefined1 *)(param_1 + 0x1325) = 0xf0;
      }
      else {
LAB_1c000f950:
        if (bVar5) goto LAB_1c000f955;
      }
    } while (bVar6);
  }
  return;
}



===== SasBcAsyncEvent @ 1c000f98c =====

void SasBcAsyncEvent(longlong param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  longlong lVar7;
  undefined1 *_Dst;
  ulonglong uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  longlong lVar11;
  byte bVar12;
  char cVar13;
  ushort uVar14;
  undefined4 local_res8 [2];
  int iVar15;
  ulonglong in_stack_ffffffffffffffb8;
  uint7 uVar16;
  
  if (*(char *)(param_1 + 0x135c) == '\0') {
    *(undefined1 *)(param_1 + 0x1362) = 0;
  }
  else {
LAB_1c000f9c3:
    do {
      cVar13 = *(char *)(param_1 + 0x1362);
      if (cVar13 == '\x01') {
        *(undefined1 *)(param_1 + 0x1362) = 2;
        cVar13 = '\0';
        local_res8[0] = 0x1020000;
        iVar15 = 0;
LAB_1c000fd85:
        SendConfigPageMessage(param_1,cVar13,local_res8,-0x43514352,iVar15);
        return;
      }
      if (cVar13 == '\x02') {
        local_res8[0] = *(undefined4 *)(param_1 + 0xd98);
        cVar13 = '\x01';
        *(undefined1 *)(param_1 + 0x1362) = 3;
        iVar15 = (int)*(undefined8 *)(param_1 + 0xe50);
        goto LAB_1c000fd85;
      }
      if (cVar13 == '\x03') {
        *(undefined2 *)(param_1 + 0x135a) = 0;
        *(undefined1 *)(param_1 + 0x1362) = 5;
        goto LAB_1c000f9c3;
      }
      if (cVar13 == '\x04') {
        *(short *)(param_1 + 0x135a) = *(short *)(param_1 + 0x135a) + 1;
        if (*(short *)(param_1 + 0x135a) == *(short *)(param_1 + 0x1d8)) {
          *(undefined1 *)(param_1 + 0x1362) = 8;
          goto LAB_1c000f9c3;
        }
      }
      else if (cVar13 != '\x05') {
        uVar16 = (uint7)(in_stack_ffffffffffffffb8 >> 8);
        if (cVar13 == '\x06') {
          *(undefined1 *)(param_1 + 0x1362) = 4;
          uVar8 = (ulonglong)*(ushort *)(param_1 + 0x135a);
          lVar7 = *(longlong *)(param_1 + 0x148);
          if (*(longlong *)(lVar7 + 8 + uVar8 * 0x18) != 0) {
            lVar11 = *(longlong *)(param_1 + 0x1340);
            if (*(short *)(lVar11 + 0xe) == 0) {
              cVar13 = *(char *)(lVar11 + 4);
              if ((cVar13 == -0x80) || (cVar13 == '\b')) goto LAB_1c000f9c3;
              if ((*(short *)(lVar11 + 0xe) != 0) || (cVar13 != '\0')) goto LAB_1c000fb34;
            }
            else {
LAB_1c000fb34:
              StorPortLogError(param_1,0,0,0,(ulonglong)uVar16 << 8,6,0xad010037);
            }
            *(undefined1 *)(param_1 + 0x1362) = 7;
            uVar1 = *(undefined1 *)(lVar7 + 0x14 + uVar8 * 0x18);
            *(undefined1 *)(param_1 + 0x135f) = uVar1;
            uVar2 = *(undefined1 *)(lVar7 + 0x15 + uVar8 * 0x18);
            *(undefined1 *)(param_1 + 0x1360) = uVar2;
            uVar3 = *(undefined1 *)(lVar7 + 0x16 + uVar8 * 0x18);
            _Dst = *(undefined1 **)(param_1 + 0xd78);
            *(undefined1 *)(param_1 + 0x1361) = uVar3;
            memset(_Dst,0,0x34);
            *_Dst = uVar2;
            _Dst[1] = uVar1;
            _Dst[3] = 1;
            _Dst[5] = 2;
            *(undefined4 *)(_Dst + 8) = 0xbcaec;
            _Dst[0xd] = uVar3;
            puVar9 = *(undefined4 **)(param_1 + 0x48);
            *(undefined1 *)(param_1 + 0x135e) = 1;
            *(undefined1 *)(param_1 + 0xf40) = 2;
            goto LAB_1c000fbc7;
          }
        }
        else if (cVar13 == '\a') {
          *(undefined1 *)(param_1 + 0x1362) = 4;
          *(undefined1 *)(param_1 + 0x135e) = 0;
          *(undefined1 *)(param_1 + 0xf40) = 0;
          if (*(short *)(*(longlong *)(param_1 + 0x1340) + 0xe) != 0) {
            in_stack_ffffffffffffffb8 = (ulonglong)uVar16 << 8;
            StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8,6,0xad010037);
          }
          uVar8 = 0;
          if (*(ushort *)(param_1 + 0x1d8) != 0) {
            lVar7 = *(longlong *)(param_1 + 0x148);
            do {
              if (((*(longlong *)(lVar7 + 8 + uVar8 * 0x18) != 0) &&
                  (*(char *)(param_1 + 0x135f) == *(char *)(lVar7 + 0x14 + uVar8 * 0x18))) &&
                 ((*(char *)(param_1 + 0x1360) == *(char *)(lVar7 + 0x15 + uVar8 * 0x18) &&
                  (*(char *)(param_1 + 0x1361) == *(char *)(lVar7 + 0x16 + uVar8 * 0x18))))) {
                StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8 & 0xffffffffffffff00,6,
                                 0xad010035);
                *(undefined1 *)(param_1 + 0x688) = 1;
                KickStart(param_1);
                return;
              }
              uVar14 = (short)uVar8 + 1;
              uVar8 = (ulonglong)uVar14;
            } while (uVar14 < *(ushort *)(param_1 + 0x1d8));
          }
        }
        else {
          if (cVar13 != '\b') {
            return;
          }
          if (*(char *)(param_1 + 0x135d) == '\0') {
            *(undefined1 *)(param_1 + 0x135c) = 0;
            *(undefined1 *)(param_1 + 0x1362) = 0;
            StorPortResume(param_1);
            *(undefined4 *)(param_1 + 0x1c0) = 0;
            return;
          }
          *(undefined1 *)(param_1 + 0x135d) = 0;
          *(undefined1 *)(param_1 + 0x1362) = 3;
        }
        goto LAB_1c000f9c3;
      }
      *(undefined1 *)(param_1 + 0x1362) = 4;
      uVar8 = (ulonglong)*(ushort *)(param_1 + 0x135a);
      lVar7 = *(longlong *)(param_1 + 0x148);
      if (*(longlong *)(lVar7 + 8 + uVar8 * 0x18) == 0) goto LAB_1c000f9c3;
      lVar11 = *(longlong *)(param_1 + 0xe50);
      cVar13 = *(char *)(lVar7 + 0x14 + uVar8 * 0x18);
      cVar4 = *(char *)(lVar7 + 0x15 + uVar8 * 0x18);
      cVar5 = *(char *)(lVar7 + 0x16 + uVar8 * 0x18);
      if ((lVar11 != 0) && (bVar6 = *(byte *)(lVar11 + 8), bVar6 != 0)) {
        pcVar10 = (char *)(lVar11 + 0xc);
        bVar12 = 0;
        if (bVar6 != 0) {
          do {
            if (((pcVar10[5] == '\0') && (pcVar10[1] == cVar13)) && (*pcVar10 == cVar4)) break;
            pcVar10 = pcVar10 + 8;
            bVar12 = bVar12 + 1;
          } while (bVar12 < bVar6);
          if (bVar12 < bVar6) goto LAB_1c000f9c3;
        }
      }
      lVar11 = FindSasAddressTableEntry(param_1,cVar13,cVar4,0x400);
    } while (lVar11 == 0);
    *(undefined1 *)(param_1 + 0x1362) = 6;
    pcVar10 = *(char **)(param_1 + 0xd78);
    memset(pcVar10,0,0x34);
    *pcVar10 = cVar4;
    pcVar10[1] = cVar13;
    pcVar10[3] = '\x01';
    pcVar10[5] = '\a';
    pcVar10[8] = -0x14;
    pcVar10[9] = -0x36;
    pcVar10[10] = '\v';
    pcVar10[0xb] = '\0';
    pcVar10[0xd] = cVar5;
    *(undefined4 *)(pcVar10 + 0x30) = *(undefined4 *)(lVar7 + 0x10 + uVar8 * 0x18);
    puVar9 = *(undefined4 **)(param_1 + 0x38);
LAB_1c000fbc7:
    *puVar9 = *(undefined4 *)(param_1 + 0xd88);
    LOCK();
    UNLOCK();
  }
  return;
}



===== CleanUpIoctl @ 1c000fdb8 =====

void CleanUpIoctl(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x6a8) != 0) {
    *(undefined1 *)(*(longlong *)(param_1 + 0x6a8) + 3) = 4;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0x6a8) = 0;
  }
  if (*(longlong *)(param_1 + 0x1310) != 0) {
    *(undefined8 *)(param_1 + 0x131a) = 0;
    *(undefined4 *)(param_1 + 0x1322) = 0;
    *(undefined1 *)(param_1 + 0x1326) = 0;
    *(undefined8 *)(param_1 + 0x1310) = 0;
  }
  return;
}



===== CheckInBandSupport @ 1c000fe1c =====

void CheckInBandSupport(longlong param_1)

{
  bool bVar1;
  longlong lVar2;
  
  memset((undefined1 *)(param_1 + 0x200),0,0x28);
  *(undefined8 *)(param_1 + 0x280) = 0;
  *(undefined8 *)(param_1 + 0x288) = 0;
  *(undefined8 *)(param_1 + 0x290) = 0;
  *(undefined1 *)(param_1 + 0x203) = 4;
  *(undefined1 *)(param_1 + 0x200) = 0;
  *(undefined1 *)(param_1 + 0x217) = 0xb;
  *(undefined4 *)(param_1 + 0x21c) = 0xd1000000;
  bVar1 = SendMessageViaHandShake(param_1,0,10);
  if (bVar1) {
    lVar2 = ReceiveDataViaHandshake(param_1,0xc);
    if (((char)lVar2 != '\0') && (*(short *)(param_1 + 0x28e) == 0)) {
      *(ushort *)(param_1 + 0x134) = *(ushort *)(param_1 + 0x134) | 0x400;
      *(undefined4 *)(param_1 + 0xb90) = *(undefined4 *)(param_1 + 0x294);
    }
  }
  return;
}



===== ContinueRegisterPost @ 1c000fec0 =====

undefined8 ContinueRegisterPost(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 uVar4;
  
  bVar3 = true;
  if (*(short *)(param_1 + 0xb9c) == 0) {
    *(short *)(param_1 + 0xb9a) = *(short *)(param_1 + 0xb9a) + 1;
    if (*(ushort *)(param_1 + 0xb9a) != *(ushort *)(param_1 + 0xb96)) {
      bVar3 = PostInBandBuffer(param_1,*(ushort *)(param_1 + 0xb9a));
      uVar4 = extraout_var;
      if (bVar3) goto LAB_1c000ff4b;
      goto LAB_1c000ff0c;
    }
    *(undefined1 *)(param_1 + 0xb82) = 1;
  }
  else {
LAB_1c000ff0c:
    bVar3 = false;
  }
  lVar1 = *(longlong *)(param_1 + 3000);
  lVar2 = *(longlong *)(lVar1 + 0x18);
  if (bVar3) {
    *(undefined4 *)(lVar2 + 0x14) = 0;
    *(undefined1 *)(lVar1 + 3) = 1;
  }
  else {
    UnRegisterInBandInterface(param_1,lVar2);
    *(undefined4 *)(lVar2 + 0x14) = 0x10;
    *(undefined1 *)(lVar1 + 3) = 4;
  }
  StorPortNotification(0,param_1,lVar1);
  uVar4 = extraout_var_00;
LAB_1c000ff4b:
  return CONCAT71(uVar4,1);
}



===== PostInBandBuffer @ 1c000ff64 =====

bool PostInBandBuffer(longlong param_1,ushort param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined1 local_res10 [8];
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 3000) + 0x38);
  *(ushort *)(param_1 + 0xb9a) = param_2;
  bVar3 = *(longlong *)(**(longlong **)(param_1 + 0x158) + 8) == 0;
  if (bVar3) {
    uVar2 = StorPortGetPhysicalAddress
                      (param_1,*(longlong *)(param_1 + 3000),(void *)(lVar1 + 0x138),local_res10);
    memset((void *)(lVar1 + 0x138),0,0x28);
    *(undefined1 *)(lVar1 + 0x13b) = 0x28;
    *(undefined4 *)(lVar1 + 0x140) = 0xffeed;
    *(undefined1 *)(lVar1 + 0x139) = 1;
    *(undefined1 *)(lVar1 + 0x149) = 4;
    *(undefined1 *)(lVar1 + 0x14b) = 0;
    *(uint *)(lVar1 + 0x14c) = (uint)param_2;
    *(undefined4 *)(lVar1 + 0x150) = 0xd1000120;
    *(uint *)(lVar1 + 0x154) =
         ((uint)param_2 * 0x120 - *(int *)(param_1 + 0x58)) + *(int *)(param_1 + 0xba8);
    **(undefined4 **)(param_1 + 0x38) = uVar2;
    LOCK();
    UNLOCK();
  }
  return bVar3;
}



===== UnRegisterInBandInterface @ 1c0010024 =====

ulonglong UnRegisterInBandInterface(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined1 local_res8 [8];
  
  uVar1 = *(uint *)(param_1 + 0xba0);
  plVar3 = (longlong *)(ulonglong)uVar1;
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 3000) + 0x38);
  if ((uVar1 == 0) || (*(uint *)(param_2 + 0x24) != uVar1)) {
    *(undefined4 *)(param_2 + 0x14) = 0x20;
  }
  else {
    plVar3 = *(longlong **)(param_1 + 0x158);
    if (*(longlong *)(*plVar3 + 8) == 0) {
      uVar4 = StorPortGetPhysicalAddress
                        (param_1,*(longlong *)(param_1 + 3000),(undefined8 *)(lVar2 + 0x138),
                         local_res8);
      *(undefined8 *)(lVar2 + 0x138) = 0;
      *(undefined8 *)(lVar2 + 0x140) = 0;
      *(undefined4 *)(lVar2 + 0x148) = 0;
      *(undefined1 *)(lVar2 + 0x13b) = 0x2b;
      *(undefined4 *)(lVar2 + 0x140) = 0xffeed;
      *(undefined1 *)(lVar2 + 0x139) = 0;
      **(undefined4 **)(param_1 + 0x38) = (int)uVar4;
      LOCK();
      UNLOCK();
      *(undefined4 *)(param_1 + 0xba0) = 0;
      *(undefined4 *)(param_2 + 0x14) = 0;
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
    *(undefined4 *)(param_2 + 0x14) = 0x80;
  }
  return (ulonglong)plVar3 & 0xffffffffffffff00;
}



===== ReadInBandBuffer @ 1c00100d8 =====

longlong ReadInBandBuffer(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined7 extraout_var;
  ushort uVar5;
  
  iVar1 = *(int *)(param_1 + 0xba0);
  if ((iVar1 == 0) || (*(int *)(param_2 + 0x28) != iVar1)) {
    *(undefined4 *)(param_2 + 0x14) = 0x20;
  }
  else {
    if (*(short *)(param_1 + 0xb98) != 0) {
      lVar3 = *(longlong *)(param_1 + 0xbb0);
      uVar5 = *(short *)(param_1 + 0xb98) - 1;
      *(ushort *)(param_1 + 0xb98) = uVar5;
      uVar4 = (ulonglong)uVar5;
      *(char *)(param_2 + 0x25) = (char)uVar5;
      *(undefined1 *)(param_2 + 0x24) = 1;
      uVar2 = *(uint *)(lVar3 + 4 + uVar4 * 0x28);
      *(short *)(param_2 + 0x26) = (short)uVar2;
      memcpy((void *)(param_2 + 0x2c),(void *)(lVar3 + 8 + uVar4 * 0x28),0x10);
      memcpy((void *)(param_2 + 0x3c),(void *)(lVar3 + 0x18 + uVar4 * 0x28),0x10);
      iVar1 = *(int *)(lVar3 + uVar4 * 0x28);
      memcpy((void *)(param_2 + 0x4c),
             (void *)((ulonglong)(uint)(iVar1 * 0x120) + *(longlong *)(param_1 + 0xba8)),
             (ulonglong)uVar2);
      PostInBandBuffer(param_1,(ushort)iVar1);
      return CONCAT71(extraout_var,1);
    }
    *(undefined4 *)(param_2 + 0x14) = 0x30;
  }
  return (ulonglong)(uint3)((uint)iVar1 >> 8) << 8;
}



===== UpdatePersistencyTable @ 1c00101d0 =====

ulonglong UpdatePersistencyTable(longlong param_1)

{
  undefined1 *_Dst;
  undefined1 uVar1;
  byte bVar2;
  int *piVar3;
  bool bVar4;
  byte bVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  ushort uVar13;
  bool bVar14;
  byte local_res8;
  undefined1 local_res18;
  uint local_48;
  int *local_40;
  
  piVar3 = *(int **)(param_1 + 0x178);
  _Dst = (undefined1 *)(param_1 + 0x200);
  uVar1 = *(undefined1 *)(param_1 + 0x1ee);
  bVar14 = *(char *)(param_1 + 0x66a) != '\0';
  if (piVar3 != (int *)0x0) {
    memset(_Dst,0,0x28);
    *(undefined8 *)(param_1 + 0x280) = 0;
    *(undefined8 *)(param_1 + 0x288) = 0;
    *(undefined8 *)(param_1 + 0x290) = 0;
    *(undefined1 *)(param_1 + 0x203) = 4;
    *(undefined4 *)(param_1 + 0x21c) = 0xd1000000;
    if (bVar14) {
      uVar9 = (ulonglong)local_res8;
      local_48 = (uint)local_res8;
    }
    else {
      *_Dst = 0;
      *(undefined1 *)(param_1 + 0x217) = 6;
      bVar4 = SendMessageViaHandShake(param_1,0,10);
      if (((!bVar4) || (lVar6 = ReceiveDataViaHandshake(param_1,0xc), (char)lVar6 == '\0')) ||
         (*(short *)(param_1 + 0x28e) != 0)) goto LAB_1c001057a;
      *(undefined4 *)(param_1 + 0xdb4) = *(undefined4 *)(param_1 + 0x294);
      local_48 = 0xff;
      uVar9 = 0xff;
    }
    lVar6 = *(longlong *)(param_1 + 0x670);
    local_40 = piVar3 + -6;
    *_Dst = 1;
    uVar13 = 0;
    *(undefined4 *)(param_1 + 0x214) = *(undefined4 *)(param_1 + 0xdb4);
    *(uint *)(param_1 + 0x21c) = *(uint *)(param_1 + 0x21c) | (uint)*(byte *)(param_1 + 0x215) << 2;
    *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x670) - *(int *)(param_1 + 0x58);
    if (*(short *)(param_1 + 0x1e0) != 0) {
      piVar12 = piVar3 + 3;
      do {
        local_res8 = 0;
        bVar5 = 0;
        local_res18 = uVar1;
        if (bVar14) {
          if ((piVar12[-3] != 0) || (piVar12[-2] != 0)) {
            *(uint *)(param_1 + 0x218) =
                 (uint)*(byte *)(piVar12 + 1) * 0x100 + *(byte *)((longlong)piVar12 + 5) + 0x1000000
            ;
            bVar4 = SendMessageViaHandShake(param_1,0,10);
            if (!bVar4) goto LAB_1c001057a;
            lVar7 = ReceiveDataViaHandshake(param_1,0xc);
            if ((((char)lVar7 == '\0') || (*(int *)(lVar6 + 0xc) != piVar12[-3])) ||
               ((*(int *)(lVar6 + 0x10) != piVar12[-2] || ((*(byte *)(lVar6 + 0x19) & 1) == 0)))) {
              bVar5 = local_res8;
            }
            else {
              bVar5 = *(undefined1 *)(lVar6 + 0x23);
              local_res18 = *(undefined1 *)(lVar6 + 0x22);
            }
          }
        }
        else {
          piVar12[-3] = 0;
          piVar12[-2] = 0;
          piVar12[-1] = 0;
          piVar12[0] = 0;
          *(undefined2 *)((longlong)piVar12 + 6) = 0;
          piVar12[2] = 0;
        }
        *(byte *)(piVar12 + 1) = bVar5;
        uVar13 = uVar13 + 1;
        *(undefined1 *)((longlong)piVar12 + 5) = local_res18;
        piVar12 = piVar12 + 6;
      } while (uVar13 < *(ushort *)(param_1 + 0x1e0));
    }
    piVar12 = piVar3 + -6;
    *(undefined4 *)(param_1 + 0x218) = 0xffffff;
    while (bVar4 = SendMessageViaHandShake(param_1,0,10), bVar4) {
      lVar7 = ReceiveDataViaHandshake(param_1,0xc);
      if ((char)lVar7 == '\0') {
        if (*(short *)(param_1 + 0x28e) == 0x22) {
          if (!bVar14) {
            if ((byte)uVar9 == 0xff) {
              *(int **)(param_1 + 0x2d0) = piVar3;
            }
            else {
              lVar7 = BumpPersTableEntry(param_1,(byte)uVar9,(char)local_48);
              *(longlong *)(param_1 + 0x2d0) = lVar7;
            }
          }
          return CONCAT71((int7)((ulonglong)lVar7 >> 8),1);
        }
        break;
      }
      if (((*(byte *)(lVar6 + 0x18) & 2) != 0) && ((*(byte *)(lVar6 + 0x19) & 1) != 0)) {
        bVar5 = *(byte *)(lVar6 + 0x23);
        bVar2 = *(byte *)(lVar6 + 0x22);
        if (bVar14) {
          piVar11 = *(int **)(param_1 + 0x2d0);
          if (piVar11 == (int *)0x0) {
            piVar11 = piVar3 + (ulonglong)*(ushort *)(param_1 + 0x1e0) * 6;
          }
          piVar10 = piVar3;
          if (piVar3 < piVar11) {
            do {
              if ((piVar10[1] == *(int *)(lVar6 + 0x10)) && (*piVar10 == *(int *)(lVar6 + 0xc))) {
                *(byte *)(piVar10 + 4) = bVar5;
                *(byte *)((longlong)piVar10 + 0x11) = bVar2;
                break;
              }
              piVar10 = piVar10 + 6;
            } while (piVar10 < piVar11);
          }
          if ((piVar10 != (int *)0x0) && (piVar10 == *(int **)(param_1 + 0x2d0))) {
            piVar10[1] = *(int *)(lVar6 + 0x10);
            *piVar10 = *(int *)(lVar6 + 0xc);
            piVar10[3] = *(int *)(lVar6 + 8);
            piVar10[2] = *(int *)(lVar6 + 4);
            *(byte *)(piVar10 + 4) = bVar5;
            *(byte *)((longlong)piVar10 + 0x11) = bVar2;
            piVar10[5] = *(int *)(lVar6 + 0x14);
            uVar8 = ((longlong)piVar10 - (longlong)piVar3) / 0x18 & 0xffff;
            uVar9 = uVar8 / (ulonglong)(longlong)(int)(uint)*(ushort *)(param_1 + 0x1ea);
            uVar8 = uVar8 % (ulonglong)(longlong)(int)(uint)*(ushort *)(param_1 + 0x1ea);
            local_48 = (uint)uVar8;
            lVar7 = BumpPersTableEntry(param_1,(byte)uVar9,(char)uVar8);
            *(longlong *)(param_1 + 0x2d0) = lVar7;
            piVar12 = local_40;
          }
        }
        else {
          piVar11 = piVar3 + ((longlong)(int)((uint)*(ushort *)(param_1 + 0x1ea) * (uint)bVar5) +
                             (ulonglong)bVar2) * 6;
          piVar11[1] = *(int *)(lVar6 + 0x10);
          *piVar11 = *(int *)(lVar6 + 0xc);
          piVar11[3] = *(int *)(lVar6 + 8);
          piVar11[2] = *(int *)(lVar6 + 4);
          *(byte *)(piVar11 + 4) = bVar5;
          *(byte *)((longlong)piVar11 + 0x11) = bVar2;
          piVar11[5] = *(int *)(lVar6 + 0x14);
          if (piVar12 < piVar11) {
            local_48 = (uint)bVar2;
            uVar9 = (ulonglong)bVar5;
            piVar12 = piVar11;
            local_40 = piVar11;
          }
        }
      }
      *(undefined4 *)(param_1 + 0x218) = *(undefined4 *)(lVar6 + 0x14);
    }
  }
LAB_1c001057a:
  uVar9 = StorPortLogError(param_1,0,0,0,0,6,0xad010026);
  return uVar9 & 0xffffffffffffff00;
}



===== BumpPersTableEntry @ 1c00105f4 =====

longlong BumpPersTableEntry(longlong param_1,byte param_2,char param_3)

{
  byte bVar1;
  
  bVar1 = param_3 + 1;
  while( true ) {
    if (bVar1 == *(byte *)(param_1 + 0x1ee)) {
      bVar1 = bVar1 + 1;
    }
    if ((ushort)bVar1 < *(ushort *)(param_1 + 0x1ea)) break;
    param_2 = param_2 + 1;
    bVar1 = 0;
    if (*(ushort *)(param_1 + 0x1e4) <= (ushort)param_2) {
      StorPortLogError(param_1,0,0,0,0,6,0xad010027);
      return 0;
    }
  }
  return *(longlong *)(param_1 + 0x178) +
         ((longlong)(int)((uint)*(ushort *)(param_1 + 0x1ea) * (uint)param_2) + (ulonglong)bVar1) *
         0x18;
}



===== PerformFwDiagOperation @ 1c0010684 =====

ulonglong PerformFwDiagOperation(longlong param_1,longlong param_2,undefined1 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  void *pvVar4;
  byte bVar5;
  longlong lVar6;
  undefined1 uVar7;
  longlong *plVar8;
  int *piVar9;
  
  *(undefined4 *)(param_2 + 0x14) = 0;
  uVar7 = 1;
  *param_3 = 1;
  memcpy((void *)(param_2 + 0x20),&FwDiagPageVersion,4);
  iVar1 = *(int *)(param_2 + 0x1c);
  if (iVar1 == 1) {
    pvVar4 = (void *)0x0;
    if (0x27 < *(uint *)(param_2 + 0x18)) {
      pvVar4 = (void *)0x0;
      if (*(byte *)(param_2 + 0x25) < 3) {
        bVar5 = 0;
        piVar9 = (int *)(((ulonglong)*(byte *)(param_2 + 0x25) + 0x44) * 0x30 + param_1);
        do {
          pvVar4 = (void *)(ulonglong)bVar5;
          if (*(int *)(param_1 + 0xce8 + (longlong)pvVar4 * 0x30) == *(int *)(param_2 + 0x40))
          goto LAB_1c00109bd;
          bVar5 = bVar5 + 1;
        } while (bVar5 < 3);
        bVar5 = 0xff;
LAB_1c00109bd:
        if (((bVar5 != 0xff) || (piVar9[10] != 0)) || (*(int *)(param_2 + 0x40) == 0))
        goto LAB_1c0010a3e;
        if (((char)piVar9[9] != '\0') && (*(char *)((longlong)piVar9 + 0x27) != '\0')) {
          *(undefined1 *)(piVar9 + 9) = 0;
          pvVar4 = (void *)(ulonglong)*(uint *)(param_2 + 0x40);
          piVar9[10] = *(uint *)(param_2 + 0x40);
          goto LAB_1c0010941;
        }
        if (*(char *)((longlong)piVar9 + 0x25) == '\0') {
          *(undefined4 *)(param_2 + 0x14) = 0x13;
          goto LAB_1c0010a45;
        }
        *(undefined1 *)(piVar9 + 9) = 0;
        *(undefined1 *)((longlong)piVar9 + 0xd) = *(undefined1 *)(param_2 + 0x24);
        memcpy(piVar9 + 5,(void *)(param_2 + 0x2c),0x10);
        piVar9[4] = *(int *)(param_2 + 0x28);
        piVar9[10] = *(int *)(param_2 + 0x40);
        pvVar4 = (void *)PostFwDiagBuffer(param_1,piVar9,'\0');
        if ((char)pvVar4 == '\0') goto LAB_1c00107b7;
        goto LAB_1c0010a36;
      }
    }
  }
  else {
    pvVar4 = (void *)(ulonglong)(iVar1 - 2U);
    if (iVar1 - 2U == 0) {
LAB_1c00108ab:
      if (iVar1 == 2) {
        if (*(uint *)(param_2 + 0x18) < 0xc) goto LAB_1c00106fb;
        bVar5 = 0;
        do {
          if (*(int *)(param_1 + 0xce8 + (ulonglong)bVar5 * 0x30) == *(int *)(param_2 + 0x24))
          goto LAB_1c0010913;
          bVar5 = bVar5 + 1;
        } while (bVar5 < 3);
      }
      else {
        if (*(uint *)(param_2 + 0x18) < 0xc) goto LAB_1c00106fb;
        bVar5 = 0;
        do {
          if (*(int *)(param_1 + 0xce8 + (ulonglong)bVar5 * 0x30) == *(int *)(param_2 + 0x24))
          goto LAB_1c0010913;
          bVar5 = bVar5 + 1;
        } while (bVar5 < 3);
      }
      bVar5 = 0xff;
LAB_1c0010913:
      if (bVar5 == 0xff) {
LAB_1c0010a3e:
        pvVar4 = (void *)0x0;
        *(undefined4 *)(param_2 + 0x14) = 0x11;
        goto LAB_1c0010a45;
      }
      pvVar4 = (void *)((ulonglong)bVar5 + 0x44);
      lVar6 = (longlong)pvVar4 * 0x30 + param_1;
      if (*(char *)(lVar6 + 0x27) == '\0') {
        if (iVar1 != 2) {
          *(undefined4 *)(param_2 + 0x14) = 0x14;
          goto LAB_1c0010a45;
        }
        *(undefined4 *)(lVar6 + 0x28) = 0;
        uVar7 = 1;
LAB_1c001093d:
        *(undefined4 *)(param_2 + 0x14) = 0;
        goto LAB_1c0010941;
      }
      pvVar4 = (void *)ReleaseFwDiagBuffer(param_1,lVar6);
      if ((char)pvVar4 == '\0') {
        *(undefined4 *)(param_2 + 0x14) = 0x12;
        goto LAB_1c0010a45;
      }
LAB_1c0010a36:
      *param_3 = 0;
LAB_1c0010941:
      return CONCAT71((int7)((ulonglong)pvVar4 >> 8),uVar7);
    }
    if (iVar1 == 3) {
      pvVar4 = (void *)0x0;
      if (*(uint *)(param_2 + 0x18) < 0x2c) goto LAB_1c00106fb;
      if (*(int *)(param_2 + 0x44) == 0) {
        bVar5 = *(byte *)(param_2 + 0x25);
        if (2 < bVar5) {
          uVar7 = 0;
          pvVar4 = (void *)0x0;
          goto LAB_1c001093d;
        }
      }
      else {
        bVar5 = 0;
        do {
          if (*(int *)(param_1 + 0xce8 + (ulonglong)bVar5 * 0x30) == *(int *)(param_2 + 0x44))
          goto LAB_1c001080c;
          bVar5 = bVar5 + 1;
        } while (bVar5 < 3);
        bVar5 = 0xff;
LAB_1c001080c:
        if (bVar5 == 0xff) goto LAB_1c0010a3e;
      }
      lVar6 = ((ulonglong)bVar5 + 0x44) * 0x30 + param_1;
      *(undefined1 *)(param_2 + 0x25) = *(undefined1 *)(lVar6 + 0xc);
      *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(lVar6 + 0x10);
      *(undefined1 *)(param_2 + 0x24) = *(undefined1 *)(lVar6 + 0xd);
      memcpy((void *)(param_2 + 0x2c),(void *)(lVar6 + 0x14),0x10);
      *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(lVar6 + 8);
      *(undefined4 *)(param_2 + 0x40) = 0;
      pvVar4 = (void *)(ulonglong)*(uint *)(lVar6 + 0x28);
      *(uint *)(param_2 + 0x44) = *(uint *)(lVar6 + 0x28);
      *(undefined2 *)(param_2 + 0x26) = 0;
      if (*(char *)(lVar6 + 0x24) == '\0') {
        *(undefined2 *)(param_2 + 0x26) = 1;
      }
      else {
        *(undefined2 *)(param_2 + 0x26) = 0;
      }
      if ((*(char *)(lVar6 + 0x26) == '\0') && (*(char *)(lVar6 + 0x27) == '\0')) {
        pvVar4 = (void *)0xfffd;
        *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) & 0xfffd;
      }
      else {
        *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) | 2;
      }
      if (*(char *)(lVar6 + 0x27) == '\0') {
        pvVar4 = (void *)0xfffb;
        *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) & 0xfffb;
      }
      else {
        *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) | 4;
      }
      goto LAB_1c0010941;
    }
    if (iVar1 == 4) {
      uVar2 = *(uint *)(param_2 + 0x2c);
      pvVar4 = (void *)((ulonglong)uVar2 + 0xc);
      if (pvVar4 <= (void *)(ulonglong)*(uint *)(param_2 + 0x18)) {
        bVar5 = 0;
        do {
          if (*(int *)(param_1 + 0xce8 + (ulonglong)bVar5 * 0x30) == *(int *)(param_2 + 0x30))
          goto LAB_1c001073c;
          bVar5 = bVar5 + 1;
        } while (bVar5 < 3);
        bVar5 = 0xff;
LAB_1c001073c:
        if (bVar5 == 0xff) goto LAB_1c0010a3e;
        uVar3 = *(uint *)(param_2 + 0x28) + uVar2;
        pvVar4 = (void *)(ulonglong)uVar3;
        plVar8 = (longlong *)(((ulonglong)bVar5 + 0x44) * 0x30 + param_1);
        if (uVar3 <= *(uint *)(plVar8 + 1)) {
          pvVar4 = memcpy((void *)(param_2 + 0x34),
                          (void *)((ulonglong)*(uint *)(param_2 + 0x28) + *plVar8),(ulonglong)uVar2)
          ;
          if (*(char *)((longlong)plVar8 + 0xe) == '\0') {
            pvVar4 = (void *)0xfffd;
            *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) & 0xfffd;
          }
          else {
            *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) | 2;
          }
          if (((*(char *)((longlong)plVar8 + 0x27) != '\0') ||
              (pvVar4 = (void *)CONCAT71((int7)((ulonglong)pvVar4 >> 8),*(byte *)(param_2 + 0x26)),
              (*(byte *)(param_2 + 0x26) & 1) == 0)) ||
             (pvVar4 = (void *)PostFwDiagBuffer(param_1,(int *)plVar8,'\0'), (char)pvVar4 != '\0'))
          goto LAB_1c0010941;
LAB_1c00107b7:
          *(undefined4 *)(param_2 + 0x14) = 0x10;
          goto LAB_1c0010a45;
        }
      }
    }
    else {
      pvVar4 = (void *)(ulonglong)(iVar1 - 5U);
      if (iVar1 - 5U == 0) goto LAB_1c00108ab;
    }
  }
LAB_1c00106fb:
  *(undefined4 *)(param_2 + 0x14) = 3;
LAB_1c0010a45:
  return (ulonglong)pvVar4 & 0xffffffffffffff00;
}



===== PostFwDiagBuffer @ 1c0010a64 =====

ulonglong PostFwDiagBuffer(longlong param_1,int *param_2,char param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  longlong *in_RAX;
  ulonglong uVar3;
  undefined1 *_Dst;
  undefined1 local_res10 [8];
  
  if ((*(char *)((longlong)param_2 + 0x25) == '\0') ||
     (in_RAX = *(longlong **)(param_1 + 0x158), *(longlong *)(*in_RAX + 8) != 0)) {
    uVar3 = (ulonglong)in_RAX & 0xffffffffffffff00;
  }
  else {
    if (param_3 == '\0') {
      _Dst = (undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0xd50) + 0x38) + 0x138);
      uVar2 = StorPortGetPhysicalAddress(param_1,*(longlong *)(param_1 + 0xd50),_Dst,local_res10);
    }
    else {
      _Dst = *(undefined1 **)(param_1 + 0xd68);
      uVar2 = *(undefined4 *)(param_1 + 0xd80);
    }
    *(undefined1 *)((longlong)param_2 + 0xe) = 0;
    if (*(ushort *)(param_1 + 300) != 0) {
      memset(_Dst,0,(ulonglong)*(ushort *)(param_1 + 300));
    }
    *_Dst = *(undefined1 *)((longlong)param_2 + 0xd);
    _Dst[1] = (char)param_2[3];
    _Dst[3] = 0x1d;
    *(undefined4 *)(_Dst + 8) = 0xffeed;
    *(int *)(_Dst + 0xc) = param_2[4];
    *(int *)(_Dst + 0x10) = param_2[2];
    memcpy(_Dst + 0x14,param_2 + 5,0x10);
    *(int *)(_Dst + 0x28) = *param_2 - *(int *)(param_1 + 0x58);
    puVar1 = *(undefined4 **)(param_1 + 0x38);
    *puVar1 = uVar2;
    LOCK();
    UNLOCK();
    uVar3 = CONCAT71((int7)((ulonglong)puVar1 >> 8),1);
  }
  return uVar3;
}



===== ReleaseFwDiagBuffer @ 1c0010b5c =====

ulonglong ReleaseFwDiagBuffer(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  longlong *in_RAX;
  ulonglong uVar4;
  undefined1 local_res8 [8];
  
  if ((*(char *)(param_2 + 0x25) == '\0') ||
     (in_RAX = *(longlong **)(param_1 + 0x158), *(longlong *)(*in_RAX + 8) != 0)) {
    uVar4 = (ulonglong)in_RAX & 0xffffffffffffff00;
  }
  else {
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xd50) + 0x38);
    uVar3 = StorPortGetPhysicalAddress
                      (param_1,*(longlong *)(param_1 + 0xd50),lVar1 + 0x138,local_res8);
    if (*(ushort *)(param_1 + 300) != 0) {
      memset((void *)(lVar1 + 0x138),0,(ulonglong)*(ushort *)(param_1 + 300));
    }
    *(undefined1 *)(lVar1 + 0x139) = *(undefined1 *)(param_2 + 0xc);
    *(undefined1 *)(lVar1 + 0x13b) = 0x1e;
    *(undefined4 *)(lVar1 + 0x140) = 0xffeed;
    puVar2 = *(undefined4 **)(param_1 + 0x38);
    *puVar2 = uVar3;
    LOCK();
    UNLOCK();
    uVar4 = CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
  }
  return uVar4;
}



===== WatchdogTimer @ 1c0010c10 =====

void WatchdogTimer(longlong param_1)

{
  undefined1 *_Dst;
  uint uVar1;
  code *pcVar2;
  byte bVar3;
  
  bVar3 = 0;
  if (*(char *)(param_1 + 0x688) == '\0') {
    if ((*(char *)(param_1 + 0x664) == '\0') && (*(char *)(param_1 + 0x682) == '\0')) {
      if ((*(char *)(param_1 + 0x6a1) != '\0') && (*(int *)(param_1 + 0x710) != -0x21524111)) {
        uVar1 = *(int *)(param_1 + 0x710) + 1;
        *(uint *)(param_1 + 0x710) = uVar1;
        if ((*(longlong *)(param_1 + 0x6a8) != 0) &&
           (*(int *)(*(longlong *)(param_1 + 0x6a8) + 0x14) + 2U <= uVar1)) {
          StorPortLogError(param_1,0,*(undefined1 *)(param_1 + 0x6a3),0,0,6,0xad010030);
          *(undefined4 *)(param_1 + 0x710) = 0xdeadbeef;
          StorPortPause(param_1,300);
          pcVar2 = HandleIoctlTimeout;
          goto LAB_1c0010c39;
        }
      }
      if ((*(char *)(param_1 + 0x662) != '\0') || (**(uint **)(param_1 + 0x10) == 0xffffffff)) {
        *(undefined1 *)(param_1 + 0x662) = 1;
        CompleteAllSrbs(param_1);
        if (*(short *)(param_1 + 0x1e4) == 0) {
          return;
        }
        do {
          StorPortNotification(7,param_1,bVar3);
          bVar3 = bVar3 + 1;
        } while ((ushort)bVar3 < *(ushort *)(param_1 + 0x1e4));
        return;
      }
      uVar1 = **(uint **)(param_1 + 0x10) & 0xf0000000;
      if (uVar1 == 0x20000000) {
        if ((*(char *)(param_1 + 0x683) != '\0') && (*(int *)(param_1 + 0x1c0) == 0)) {
          *(undefined1 *)(param_1 + 0x683) = 0;
          StorPortSynchronizeAccess(param_1,UpdatePersistencyTable,0);
          StorPortResume(param_1);
          if ((*(short *)(param_1 + 0x1f0) == 0) && (bVar3 = 0, *(short *)(param_1 + 0x1e4) != 0)) {
            do {
              StorPortNotification(7,param_1,bVar3);
              bVar3 = bVar3 + 1;
            } while ((ushort)bVar3 < *(ushort *)(param_1 + 0x1e4));
          }
        }
        if (((*(int *)(param_1 + 0xd58) != 0) && (*(char *)(param_1 + 0xd60) != '\0')) &&
           (*(char *)(param_1 + 0xd61) == '\0')) {
          _Dst = *(undefined1 **)(param_1 + 0xd70);
          *(undefined2 *)(param_1 + 0xd60) = 0x100;
          memset(_Dst,0,0x28);
          *_Dst = 1;
          _Dst[3] = 4;
          *(undefined4 *)(_Dst + 0x14) = *(undefined4 *)(param_1 + 0xda4);
          *(uint *)(_Dst + 0x1c) = (uint)*(byte *)(param_1 + 0xda5) << 2 | 0xd1000000;
          *(int *)(_Dst + 0x20) = *(int *)(param_1 + 0xdb8) - *(int *)(param_1 + 0x58);
          *(undefined4 *)(_Dst + 8) = 0x1000beef;
          **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd84);
          LOCK();
          UNLOCK();
        }
      }
      else {
        if (uVar1 != 0) {
          **(undefined4 **)(param_1 + 0x30) = 9;
          LOCK();
          UNLOCK();
          *(undefined1 *)(param_1 + 0x688) = 1;
          if (uVar1 == 0x40000000) {
            if ((*(short *)(param_1 + 0x1da) == 0) && (*(int *)(param_1 + 0x1c8) == 0)) {
              StorPortPause(param_1,300);
            }
            KickStart(param_1);
          }
          else {
            if ((*(short *)(param_1 + 0x1da) == 0) && (*(int *)(param_1 + 0x1c8) == 0)) {
              StorPortPause(param_1,300);
            }
            if ((**(uint **)(param_1 + 0x20) & 0x20) != 0) {
              ClearResetHistoryBit(param_1);
            }
          }
          *(undefined2 *)(param_1 + 0x686) = 0;
          pcVar2 = SynchronizeRestartRecovery;
          goto LAB_1c0010c39;
        }
        if ((*(short *)(param_1 + 0x1da) == 0) &&
           (*(undefined2 *)(param_1 + 0x1da) = 1, *(int *)(param_1 + 0x1c8) == 0)) {
          StorPortPause(param_1,300);
        }
      }
      if (*(char *)(param_1 + 0x681) != '\0') {
        return;
      }
      if (*(int *)(param_1 + 0x1c4) != 0) {
        *(int *)(param_1 + 0x1c4) = *(int *)(param_1 + 0x1c4) + -1;
      }
      *(undefined1 *)(param_1 + 0x681) = 0;
    }
    else {
      if (*(char *)(param_1 + 0x681) != '\0') {
        return;
      }
      *(undefined1 *)(param_1 + 0x681) = 0;
    }
    StorPortNotification(6,param_1,WatchdogTimer,1000000);
  }
  else {
    pcVar2 = SynchronizeRestartRecovery;
LAB_1c0010c39:
    StorPortSynchronizeAccess(param_1,pcVar2,0);
  }
  return;
}



===== SynchronizeRestartRecovery @ 1c0010f80 =====

undefined8 SynchronizeRestartRecovery(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ushort uVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  code *pcVar9;
  int iVar10;
  undefined2 *puVar11;
  bool bVar12;
  bool bVar13;
  
  bVar7 = *(byte *)(param_1 + 0x688);
  bVar12 = false;
  if ((1 < bVar7) && ((**(uint **)(param_1 + 0x20) & 0x20) != 0)) {
    ClearResetHistoryBit(param_1);
    *(undefined1 *)(param_1 + 0x688) = 1;
    if ((*(char *)(param_1 + 0x664) != '\0') &&
       ((*(longlong *)(param_1 + 0x170) != 0 &&
        (*(char *)(*(longlong *)(param_1 + 0x170) + 2) == '$')))) {
      *(undefined1 *)(param_1 + 0x688) = 0xd;
    }
    bVar7 = *(byte *)(param_1 + 0x688);
  }
  if (bVar7 < 0xb) {
    if (bVar7 < 9) {
      if (bVar7 == 1) {
        uVar6 = **(uint **)(param_1 + 0x10) & 0xf0000000;
        if (uVar6 == 0x10000000) {
          *(undefined1 *)(param_1 + 0x688) = 2;
          goto LAB_1c001125d;
        }
        if (uVar6 == 0xf0000000) goto LAB_1c001178a;
LAB_1c0011227:
        *(short *)(param_1 + 0x686) = *(short *)(param_1 + 0x686) + 1;
        if (300 < *(ushort *)(param_1 + 0x686)) {
LAB_1c0011241:
          KickStart(param_1);
          *(undefined2 *)(param_1 + 0x686) = 0;
        }
      }
      else if (bVar7 == 2) {
LAB_1c001125d:
        **(undefined4 **)(param_1 + 0x30) = 9;
        LOCK();
        UNLOCK();
        CompleteAllSrbs(param_1);
        *(undefined2 *)(param_1 + 0x686) = 0;
        LsiMpiPartitionMemory(param_1);
        if (*(int *)(param_1 + 0x1fc) == 0) {
          *(undefined1 *)(param_1 + 0x688) = 4;
        }
        else {
          *(undefined8 *)(param_1 + 0x200) = 0;
          *(undefined4 *)(param_1 + 0x208) = 0;
          memset((void *)(param_1 + 0x280),0,0x50);
          *(undefined1 *)(param_1 + 0x203) = 3;
          *(undefined4 *)(param_1 + 0x68c) = 3;
          *(undefined4 *)(param_1 + 0x690) = 0x28;
          *(undefined8 **)(param_1 + 0x698) = (undefined8 *)(param_1 + 0x200);
          *(undefined1 *)(param_1 + 0x688) = 0xe;
          *(undefined1 *)(param_1 + 0x68a) = 3;
        }
      }
      else {
        if (bVar7 == 3) {
          if (((*(byte *)(param_1 + 0x297) & 1) != 0) && (*(int *)(param_1 + 0x2b0) != 0)) {
            *(ushort *)(param_1 + 0x134) = *(ushort *)(param_1 + 0x134) | 0x40;
          }
          *(undefined1 *)(param_1 + 0x688) = 4;
        }
        else if (bVar7 != 4) {
          if (bVar7 == 5) {
            uVar6 = **(uint **)(param_1 + 0x10) & 0xf0000000;
            if (uVar6 != 0x20000000) {
              if (uVar6 != 0xf0000000) {
                *(short *)(param_1 + 0x686) = *(short *)(param_1 + 0x686) + 1;
                bVar12 = *(ushort *)(param_1 + 0x686) < 100;
                bVar13 = *(ushort *)(param_1 + 0x686) == 100;
                goto LAB_1c001111f;
              }
              goto LAB_1c001178a;
            }
            *(undefined1 *)(param_1 + 0x682) = 0;
            *(undefined1 *)(param_1 + 0x689) = 0;
          }
          else if (bVar7 != 6) {
            if (bVar7 == 7) {
              *(char *)(param_1 + 0x689) = *(char *)(param_1 + 0x689) + '\x01';
              cVar2 = (-((ushort)*(byte *)(param_1 + 0x689) < *(ushort *)(param_1 + 0x1dc)) & 0xfeU)
                      + 8;
              goto LAB_1c00110e7;
            }
            if (bVar7 == 8) {
              if ((**(uint **)(param_1 + 0x20) & 0x20) != 0) {
                ClearResetHistoryBit(param_1);
              }
              LSImpiHWInitialize(param_1);
              *(undefined1 *)(param_1 + 0x664) = 0;
              if (*(char *)(param_1 + 0x65f) != '\0') {
                if (*(longlong *)(param_1 + 0x6a8) != 0) {
                  *(undefined2 *)(*(longlong *)(param_1 + 0x6a8) + 3) = 1;
                  StorPortNotification(0,param_1);
                }
                *(undefined1 *)(param_1 + 0x65f) = 0;
                *(undefined8 *)(param_1 + 0x6a8) = 0;
              }
              StorPortResume(param_1);
              StorPortReady(param_1);
              goto LAB_1c00110c0;
            }
            goto LAB_1c00117a8;
          }
          *(undefined2 *)(param_1 + 0x686) = 0;
          *(undefined8 *)(param_1 + 0x200) = 0;
          *(undefined4 *)(param_1 + 0x208) = 0;
          memset((void *)(param_1 + 0x280),0,0x50);
          *(undefined1 *)(param_1 + 0x203) = 6;
          *(undefined1 *)(param_1 + 0x206) = *(undefined1 *)(param_1 + 0x689);
          *(undefined4 *)(param_1 + 0x68c) = 3;
          *(undefined4 *)(param_1 + 0x690) = 10;
          *(undefined8 **)(param_1 + 0x698) = (undefined8 *)(param_1 + 0x200);
          *(undefined1 *)(param_1 + 0x688) = 0xe;
          *(undefined1 *)(param_1 + 0x68a) = 7;
          goto LAB_1c00117a8;
        }
        SendIOCInitMessage(param_1);
        *(undefined4 *)(param_1 + 0x68c) = 0xb;
        *(longlong *)(param_1 + 0x698) = param_1 + 0x200;
        *(undefined4 *)(param_1 + 0x690) = 10;
        *(undefined1 *)(param_1 + 0x688) = 0xe;
        *(undefined1 *)(param_1 + 0x68a) = 5;
      }
      goto LAB_1c00117a8;
    }
    if (-1 < **(int **)(param_1 + 0x28)) {
      *(undefined2 *)(param_1 + 0x686) = 0;
      if (bVar7 == 10) {
LAB_1c0011135:
        *(undefined1 *)(param_1 + 0x688) = 1;
      }
      else {
        if ((*(int *)(param_1 + 0x1fc) == 0) || ((**(uint **)(param_1 + 0x20) & 0x20) != 0))
        goto LAB_1c001175a;
        **(undefined4 **)(param_1 + 0x10) = 0x41000000;
        LOCK();
        UNLOCK();
        *(undefined1 *)(param_1 + 0x688) = 0xb;
      }
      goto LAB_1c00117a8;
    }
    if (**(int **)(param_1 + 0x28) == -1) goto LAB_1c001178a;
    *(short *)(param_1 + 0x686) = *(short *)(param_1 + 0x686) + 1;
    if (*(ushort *)(param_1 + 0x686) < 0x12d) goto LAB_1c00117a8;
    KickStart(param_1);
    *(undefined2 *)(param_1 + 0x686) = 0;
    cVar2 = '\x01';
    if (bVar7 == 9) {
      cVar2 = '\r';
    }
LAB_1c00110e7:
    *(char *)(param_1 + 0x688) = cVar2;
  }
  else if (bVar7 == 0xb) {
    if (**(int **)(param_1 + 0x28) < 0) {
      if (**(int **)(param_1 + 0x28) == -1) goto LAB_1c001178a;
      *(short *)(param_1 + 0x686) = *(short *)(param_1 + 0x686) + 1;
      if (300 < *(ushort *)(param_1 + 0x686)) goto LAB_1c001174a;
    }
    else {
      *(undefined1 *)(param_1 + 0x688) = 0xc;
    }
  }
  else if (bVar7 == 0xc) {
LAB_1c001174a:
    KickStart(param_1);
    *(undefined2 *)(param_1 + 0x686) = 0;
LAB_1c001175a:
    *(undefined1 *)(param_1 + 0x688) = 0xd;
  }
  else if (bVar7 == 0xd) {
    uVar6 = **(uint **)(param_1 + 0x10) & 0xf0000000;
    if (uVar6 != 0x10000000) {
      if (uVar6 != 0xf0000000) {
        if ((**(uint **)(param_1 + 0x20) & 0x42) == 0) goto LAB_1c0011227;
        goto LAB_1c0011241;
      }
      goto LAB_1c001178a;
    }
    *(undefined2 *)(*(longlong *)(param_1 + 0x170) + 3) = 1;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0x170) = 0;
LAB_1c00110c0:
    *(undefined1 *)(param_1 + 0x688) = 0;
  }
  else if (bVar7 == 0xe) {
    **(undefined4 **)(param_1 + 0x28) = 0;
    LOCK();
    UNLOCK();
    **(int **)(param_1 + 0x10) = (*(uint *)(param_1 + 0x68c) | 0x4200) << 0x10;
    LOCK();
    UNLOCK();
    *(undefined2 *)(param_1 + 0x686) = 0;
    *(undefined1 *)(param_1 + 0x688) = 0xf;
    uVar6 = 60000;
    if (*(longlong *)(param_1 + 0x698) == param_1 + 0x240) {
      uVar6 = 10000;
    }
    *(short *)(param_1 + 0x684) = (short)((ulonglong)uVar6 / 200);
  }
  else if (bVar7 == 0xf) {
    if (**(uint **)(param_1 + 0x28) == 0xffffffff) {
LAB_1c001178a:
      *(undefined1 *)(param_1 + 0x662) = 1;
      *(undefined1 *)(param_1 + 0x688) = 0;
      *(undefined1 *)(param_1 + 0x682) = 0;
    }
    else if ((**(uint **)(param_1 + 0x28) & 1) == 0) {
      *(short *)(param_1 + 0x686) = *(short *)(param_1 + 0x686) + 1;
      bVar12 = *(ushort *)(param_1 + 0x686) < *(ushort *)(param_1 + 0x684);
      bVar13 = *(ushort *)(param_1 + 0x686) == *(ushort *)(param_1 + 0x684);
LAB_1c001111f:
      if (!bVar12 && !bVar13) {
        KickStart(param_1);
        *(undefined2 *)(param_1 + 0x686) = 0;
        goto LAB_1c0011135;
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x686) = 0;
      if ((**(uint **)(param_1 + 0x10) >> 0x1b & 1) == 0) {
        KickStart(param_1);
        goto LAB_1c0011135;
      }
      **(undefined4 **)(param_1 + 0x28) = 0;
      LOCK();
      UNLOCK();
      *(undefined1 *)(param_1 + 0x688) = 0x10;
    }
  }
  else {
    if (bVar7 == 0x10) {
      if (**(int **)(param_1 + 0x28) == -1) goto LAB_1c001178a;
      if (**(int **)(param_1 + 0x28) < 0) {
        uVar5 = 300;
        goto LAB_1c00113f2;
      }
      uVar6 = 0;
      lVar1 = *(longlong *)(param_1 + 0x698);
      *(undefined2 *)(param_1 + 0x686) = 0;
      if (*(int *)(param_1 + 0x68c) == 0) {
LAB_1c00115be:
        if (*(longlong *)(param_1 + 0x698) == param_1 + 0x240) {
          **(undefined4 **)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x1ac);
          LOCK();
          UNLOCK();
          *(undefined1 *)(param_1 + 0x688) = 0;
          if (*(char *)(param_1 + 0x245) == '\x04') {
            if (*(uint *)(param_1 + 0xf60) < 0xfffffffe) {
              *(uint *)(param_1 + 0xf60) = *(uint *)(param_1 + 0xf60) + 1;
            }
            *(undefined1 *)(param_1 + 0x681) = 1;
            pcVar9 = ResetScsiTimer;
            iVar10 = 15000000;
            goto LAB_1c00117dd;
          }
        }
        else {
          *(undefined1 *)(param_1 + 0x688) = 0x11;
        }
        goto LAB_1c00117a8;
      }
      do {
        if (bVar12) goto LAB_1c00115a9;
        **(undefined4 **)(param_1 + 0x10) = *(undefined4 *)(lVar1 + (ulonglong)uVar6 * 4);
        LOCK();
        UNLOCK();
        uVar3 = SymWaitForResponse(param_1);
        if ((char)uVar3 == '\0') {
          bVar12 = true;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 0x68c));
      if (!bVar12) goto LAB_1c00115be;
LAB_1c00115a9:
      *(undefined1 *)(param_1 + 0x688) = 1;
      uVar6 = **(uint **)(param_1 + 0x20);
    }
    else {
      if (bVar7 != 0x11) goto LAB_1c00117a8;
      if (*(char *)(param_1 + 0x68a) == '\a') {
        uVar5 = (ushort)(*(uint *)(param_1 + 0x1b0) / 200);
      }
      else {
        uVar5 = 300;
      }
      if ((**(uint **)(param_1 + 0x28) & 1) == 0) {
LAB_1c00113f2:
        *(short *)(param_1 + 0x686) = *(short *)(param_1 + 0x686) + 1;
        bVar12 = *(ushort *)(param_1 + 0x686) < uVar5;
        bVar13 = *(ushort *)(param_1 + 0x686) == uVar5;
        goto LAB_1c001111f;
      }
      puVar11 = (undefined2 *)(param_1 + 0x280);
      *(undefined2 *)(param_1 + 0x686) = 0;
      uVar6 = 0;
      do {
        uVar3 = SymWaitForDoorBell(param_1,10000);
        if ((char)uVar3 == '\0') {
          bVar12 = true;
          break;
        }
        *puVar11 = (short)**(undefined4 **)(param_1 + 0x10);
        **(undefined4 **)(param_1 + 0x28) = 0;
        LOCK();
        UNLOCK();
        uVar6 = uVar6 + 1;
        puVar11 = puVar11 + 1;
      } while (uVar6 < 2);
      uVar8 = 2;
      uVar6 = (uint)(byte)*(undefined2 *)(param_1 + 0x282) * 2;
      if (uVar6 < 3) {
LAB_1c00114be:
        if (!bVar12) goto LAB_1c00114c3;
      }
      else {
        puVar11 = (undefined2 *)(param_1 + 0x284);
        do {
          if (bVar12) goto LAB_1c00114e0;
          uVar3 = SymWaitForDoorBell(param_1,10000);
          if ((char)uVar3 == '\0') {
            bVar12 = true;
            goto LAB_1c00114be;
          }
          if (uVar8 < *(uint *)(param_1 + 0x690)) {
            *puVar11 = (short)**(undefined4 **)(param_1 + 0x10);
          }
          **(undefined4 **)(param_1 + 0x28) = 0;
          LOCK();
          UNLOCK();
          uVar8 = uVar8 + 1;
          puVar11 = puVar11 + 1;
        } while (uVar8 < uVar6);
LAB_1c00114c3:
        uVar3 = SymWaitForDoorBell(param_1,10000);
        if ((char)uVar3 == '\0') {
          bVar12 = true;
        }
      }
LAB_1c00114e0:
      **(undefined4 **)(param_1 + 0x28) = 0;
      LOCK();
      UNLOCK();
      if (((uVar8 >> 1 == (uint)*(byte *)(param_1 + 0x282)) &&
          ((*(ushort *)(param_1 + 0x28e) & 0x7fff) == 0)) && (!bVar12)) {
        cVar2 = *(char *)(param_1 + 0x68a);
        goto LAB_1c00110e7;
      }
      *(undefined1 *)(param_1 + 0x688) = 1;
      uVar6 = **(uint **)(param_1 + 0x20);
    }
    if ((uVar6 & 0x20) == 0) {
      KickStart(param_1);
    }
    else {
      ClearResetHistoryBit(param_1);
    }
  }
LAB_1c00117a8:
  pcVar9 = WatchdogTimer;
  *(undefined1 *)(param_1 + 0x681) = 0;
  iVar10 = (-(uint)(*(char *)(param_1 + 0x688) != '\0') & 0xfff24460) + 1000000;
  if (*(char *)(param_1 + 0x688) == '\f') {
    iVar10 = 600000;
  }
LAB_1c00117dd:
  uVar4 = StorPortNotification(6,param_1,pcVar9,iVar10);
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== CheckIoctlQueue @ 1c001180c =====

void CheckIoctlQueue(longlong param_1)

{
  byte bVar1;
  void *pvVar2;
  char cVar3;
  
  if (((*(char *)(param_1 + 0x135c) == '\0') && (*(int *)(param_1 + 0x1c0) == 0)) &&
     (*(char *)(param_1 + 0x688) == '\0')) {
    if (*(char *)(param_1 + 0x135d) == '\0') {
      do {
        bVar1 = *(byte *)(param_1 + 0x859);
        pvVar2 = *(void **)(param_1 + 0x758 + (ulonglong)bVar1 * 8);
        if (pvVar2 == (void *)0x0) {
          return;
        }
        *(undefined8 *)(param_1 + 0x758 + (ulonglong)bVar1 * 8) = 0;
        cVar3 = bVar1 + 1;
        if ((byte)(bVar1 + 1) == ' ') {
          cVar3 = '\0';
        }
        *(char *)(param_1 + 0x859) = cVar3;
        LsiHandleAppRequest(param_1,pvVar2);
      } while (*(char *)(param_1 + 0x6a1) == '\0');
    }
    else {
      *(undefined1 *)(param_1 + 0x135d) = 0;
      if (*(int *)(param_1 + 0x1c8) == 0) {
        StorPortPause(param_1,300);
      }
      *(undefined4 *)(param_1 + 0x1c0) = 0xf;
      *(undefined1 *)(param_1 + 0x135c) = 1;
      *(undefined1 *)(param_1 + 0x1362) = 1;
      SasBcAsyncEvent(param_1);
    }
  }
  return;
}



===== CheckResetQueue @ 1c00118d4 =====

undefined8 CheckResetQueue(longlong param_1)

{
  undefined1 *_Dst;
  longlong *plVar1;
  byte bVar2;
  longlong lVar3;
  char cVar4;
  bool bVar5;
  undefined7 extraout_var;
  void *pvVar6;
  
  bVar2 = *(byte *)(param_1 + 0xb81);
  do {
    plVar1 = (longlong *)(param_1 + 0x860 + (ulonglong)bVar2 * 8);
    lVar3 = *plVar1;
    if (lVar3 == 0) {
      return 0;
    }
    *plVar1 = 0;
    cVar4 = bVar2 + 1;
    if ((byte)(bVar2 + 1) == 'd') {
      cVar4 = '\0';
    }
    *(char *)(param_1 + 0xb81) = cVar4;
    if ((((lVar3 != -1) && (cVar4 = *(char *)(lVar3 + 2), *(longlong *)(lVar3 + 0x38) != 0)) &&
        ((cVar4 == ' ' || (cVar4 == '\x13')))) &&
       ((ushort)*(byte *)(lVar3 + 5) < *(ushort *)(param_1 + 0x1e4))) {
      _Dst = (undefined1 *)(param_1 + 0x240);
      memset(_Dst,0,0x34);
      *_Dst = *(undefined1 *)(lVar3 + 6);
      *(undefined1 *)(param_1 + 0x241) = *(undefined1 *)(lVar3 + 5);
      *(undefined1 *)(param_1 + 0x243) = 1;
      *(undefined1 *)(param_1 + 0x245) = 3;
      if (cVar4 == ' ') {
        *(undefined1 *)(param_1 + 0x245) = 5;
        *(undefined1 *)(param_1 + 0x24d) = *(undefined1 *)(lVar3 + 7);
      }
      *(undefined4 *)(param_1 + 0x1c0) = 0x10;
      *(longlong *)(param_1 + 0x170) = lVar3;
      if (*(char *)(param_1 + 0x678) != '\0') {
        pvVar6 = memcpy(*(void **)(param_1 + 0xd68),_Dst,0x34);
        **(undefined4 **)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0xd80);
        LOCK();
        UNLOCK();
LAB_1c0011a65:
        return CONCAT71((int7)((ulonglong)pvVar6 >> 8),1);
      }
      if (*(int *)(param_1 + 0x1c8) == 0) {
        **(undefined4 **)(param_1 + 0x30) = 9;
        LOCK();
        UNLOCK();
        pvVar6 = (void *)(param_1 + 0x240);
        *(undefined4 *)(param_1 + 0x68c) = 0xd;
        *(void **)(param_1 + 0x698) = pvVar6;
        *(undefined4 *)(param_1 + 0x690) = 10;
        *(undefined1 *)(param_1 + 0x688) = 0xe;
        goto LAB_1c0011a65;
      }
      bVar5 = SendMessageViaHandShake(param_1,1,0xd);
      pvVar6 = (void *)CONCAT71(extraout_var,bVar5);
      if (bVar5) goto LAB_1c0011a65;
      if (*(longlong *)(lVar3 + 0x38) != 0) {
        *(undefined1 *)(lVar3 + 3) = 4;
        StorPortNotification(0,param_1,lVar3);
      }
      *(undefined8 *)(param_1 + 0x170) = 0;
    }
    bVar2 = *(byte *)(param_1 + 0xb81);
  } while( true );
}



===== CompleteAllSrbs @ 1c0011a88 =====

void CompleteAllSrbs(longlong param_1)

{
  short *psVar1;
  uint uVar2;
  undefined1 uVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  
  uVar3 = 0xe;
  uVar7 = 4;
  if (*(char *)(param_1 + 0x662) != '\0') {
    uVar3 = 0x11;
    uVar7 = 0x11;
  }
  uVar2 = 0;
  if (*(short *)(param_1 + 0x1d8) != 0) {
    plVar5 = (longlong *)(*(longlong *)(param_1 + 0x148) + 8);
    do {
      if (*plVar5 != 0) {
        *(undefined1 *)(*plVar5 + 3) = uVar3;
        StorPortNotification(0,param_1);
        *plVar5 = 0;
      }
      plVar5 = plVar5 + 3;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(ushort *)(param_1 + 0x1d8));
  }
  plVar5 = (longlong *)(param_1 + 0x758);
  lVar4 = 0x20;
  do {
    if (*plVar5 != 0) {
      *(undefined1 *)(*plVar5 + 3) = uVar7;
      StorPortNotification(0,param_1);
      *plVar5 = 0;
    }
    plVar5 = plVar5 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  puVar6 = (undefined8 *)(param_1 + 0x860);
  lVar4 = 100;
  do {
    psVar1 = (short *)*puVar6;
    if (psVar1 != (short *)0x0) {
      if (*(short **)(param_1 + 0x170) == psVar1) {
        *(undefined8 *)(param_1 + 0x170) = 0;
      }
      if (((*psVar1 == 0x58) &&
          ((((char)psVar1[1] == ' ' || ((char)psVar1[1] == '\x13')) && (*(int *)(psVar1 + 8) == 0)))
          ) && (*(longlong *)(psVar1 + 0xc) == 0)) {
        *(undefined1 *)((longlong)psVar1 + 3) = uVar7;
        StorPortNotification(0,param_1);
      }
      *puVar6 = 0;
    }
    puVar6 = puVar6 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  psVar1 = *(short **)(param_1 + 0x170);
  if (psVar1 != (short *)0x0) {
    if (((*psVar1 == 0x58) && (((char)psVar1[1] == ' ' || ((char)psVar1[1] == '\x13')))) &&
       ((*(int *)(psVar1 + 8) == 0 && (*(longlong *)(psVar1 + 0xc) == 0)))) {
      *(undefined1 *)((longlong)psVar1 + 3) = uVar7;
      StorPortNotification(0,param_1);
    }
    *(undefined8 *)(param_1 + 0x170) = 0;
  }
  return;
}



===== HandleIoctlTimeout @ 1c0011bf0 =====

undefined8 HandleIoctlTimeout(longlong param_1)

{
  void *_Dst;
  int iVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (((*(char *)(*(longlong *)(param_1 + 0x6f8) + 3) == '\0') && (*(int *)(param_1 + 0x1c0) == 0))
     && (*(char *)(param_1 + 0x681) == '\0')) {
    _Dst = (void *)(param_1 + 0x240);
    memset(_Dst,0,0x34);
    *(undefined1 *)(param_1 + 0x241) = *(undefined1 *)(param_1 + 0x6a3);
    *(undefined1 *)(param_1 + 0x243) = 1;
    *(undefined1 *)(param_1 + 0x245) = 4;
    if (((*(ushort *)(param_1 + 0x134) & 0x100) != 0) && (*(short *)(param_1 + 0x1b6) == 0)) {
      *(undefined1 *)(param_1 + 0x247) = 2;
    }
    *(undefined4 *)(param_1 + 0x1c0) = 1;
    if (*(char *)(param_1 + 0x678) == '\0') {
      **(undefined4 **)(param_1 + 0x30) = 9;
      LOCK();
      UNLOCK();
      *(undefined4 *)(param_1 + 0x68c) = 0xd;
      *(undefined4 *)(param_1 + 0x690) = 10;
      *(void **)(param_1 + 0x698) = _Dst;
      *(undefined1 *)(param_1 + 0x688) = 0xe;
    }
    else {
      memcpy(*(void **)(param_1 + 0xd68),_Dst,0x34);
      **(undefined4 **)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0xd80);
      LOCK();
      UNLOCK();
    }
    uVar4 = 15000000;
    pcVar3 = ResetScsiTimer;
  }
  else {
    puVar2 = *(undefined8 **)(param_1 + 0x188);
    iVar1 = *(int *)(param_1 + 0x58);
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 1) = 0;
    *(undefined1 *)((longlong)puVar2 + 3) = 7;
    *(undefined1 *)puVar2 = 0;
    **(int **)(param_1 + 0x38) = (int)puVar2 - iVar1;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x1c0) = 2;
    pcVar3 = DelayedIoctlTimeout;
    uVar4 = 3000000;
  }
  *(undefined1 *)(param_1 + 0x681) = 1;
  uVar4 = StorPortNotification(6,param_1,pcVar3,uVar4);
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== LSImpiMSIIsr @ 1c0011d50 =====

ulonglong LSImpiMSIIsr(longlong param_1)

{
  byte *pbVar1;
  undefined8 *puVar2;
  short *psVar3;
  longlong *plVar4;
  byte bVar5;
  ushort uVar6;
  short sVar7;
  int iVar8;
  undefined4 uVar9;
  longlong lVar10;
  bool bVar11;
  uint *in_RAX;
  ulonglong uVar12;
  undefined8 uVar13;
  longlong lVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  ulonglong uVar18;
  longlong lVar19;
  char cVar20;
  char cVar21;
  uint uVar22;
  ulonglong uVar23;
  bool bVar24;
  uint local_res18 [2];
  uint local_res20;
  
  bVar11 = false;
  if (*(char *)(param_1 + 0x665) == '\0') {
    cVar21 = '\0';
LAB_1c0011d8a:
    do {
      uVar12 = 0;
      cVar20 = '\x01';
      in_RAX = *(uint **)(param_1 + 0x40);
      uVar16 = *in_RAX;
      uVar23 = (ulonglong)uVar16;
      if (uVar16 != 0xffffffff) {
        cVar21 = cVar21 + '\x01';
        if ((uVar16 & 0xfb000000) == 0) {
          lVar19 = *(longlong *)(param_1 + 0x148) + uVar23 * 0x18;
          lVar14 = *(longlong *)(lVar19 + 8);
          if (lVar14 != 0) {
            *(undefined8 *)(lVar19 + 8) = 0;
            **(longlong **)(param_1 + 0x160) = lVar19;
            *(longlong *)(param_1 + 0x160) = *(longlong *)(param_1 + 0x160) + 8;
            if (*(longlong *)(param_1 + 0x160) == *(longlong *)(param_1 + 0x168)) {
              *(undefined8 *)(param_1 + 0x160) = *(undefined8 *)(param_1 + 0x150);
            }
            if (((((*(ushort *)(param_1 + 0x134) & 0x100) != 0) &&
                 (*(char *)(lVar14 + 0x48) == '\x12')) && ((*(byte *)(lVar14 + 0x49) & 1) == 0)) &&
               (((**(byte **)(lVar14 + 0x18) & 0x1f) == 0 && (7 < *(uint *)(lVar14 + 0x10))))) {
              pbVar1 = *(byte **)(lVar14 + 0x18) + 7;
              *pbVar1 = *pbVar1 | 0x32;
            }
            *(undefined2 *)(lVar14 + 3) = 1;
            StorPortNotification(0);
          }
          goto LAB_1c0011d8a;
        }
        uVar18 = (ulonglong)(uVar16 & 0x7fffffff);
        if ((*(short *)(param_1 + 0x1be) != 0) && ((uVar16 & 0xe0000000) != 0)) {
          if ((int)uVar16 < 0) {
            uVar12 = *(longlong *)(param_1 + 0x58) + uVar18 * 2;
          }
          if ((uVar12 < *(ulonglong *)(param_1 + 0x138)) ||
             (*(ulonglong *)(param_1 + 0x140) <= uVar12)) {
            StorPortLogError(param_1,0,0,0,0,6,uVar16);
            uVar23 = 0x80000000;
          }
        }
        uVar16 = (uint)uVar23;
        if (((int)uVar16 < 0) && (*(char *)(*(longlong *)(param_1 + 0x58) + 3 + uVar18 * 2) == '\b')
           ) {
          **(undefined4 **)(param_1 + 0x40) =
               *(undefined4 *)(*(longlong *)(param_1 + 0x58) + 8 + uVar18 * 2);
          LOCK();
          UNLOCK();
          goto LAB_1c001246d;
        }
        uVar12 = CheckMpiIoctlReply(param_1,uVar16);
        if ((char)uVar12 == '\0') {
          uVar13 = CheckInqFlagReplies(param_1,uVar16,local_res18);
          if ((char)uVar13 != '\0') {
            if (local_res18[0] != 0xffffffff) {
LAB_1c00123e2:
              if (local_res18[0] != 0xffeed) {
                lVar19 = *(longlong *)(param_1 + 0x148) + (ulonglong)local_res18[0] * 0x18;
                *(undefined8 *)(lVar19 + 8) = 0;
                **(longlong **)(param_1 + 0x160) = lVar19;
                *(longlong *)(param_1 + 0x160) = *(longlong *)(param_1 + 0x160) + 8;
                if (*(longlong *)(param_1 + 0x160) == *(longlong *)(param_1 + 0x168)) {
                  *(undefined8 *)(param_1 + 0x160) = *(undefined8 *)(param_1 + 0x150);
                }
              }
            }
            goto LAB_1c0011d8a;
          }
          if ((uVar23 & 0xe0000000) == 0) {
            *(undefined2 *)(param_1 + 0xec8) = 0;
            *(undefined1 *)(param_1 + 0xeb4) = 0;
            DomainValidation(param_1);
            goto LAB_1c0011d8a;
          }
          psVar3 = (short *)(*(longlong *)(param_1 + 0x58) + uVar18 * 2);
          uVar22 = *(uint *)(psVar3 + 8);
          if ((((uVar22 != 0) && ((psVar3[7] & 0x8000U) != 0)) && (uVar22 != 0x30030501)) &&
             (((uVar22 != 0x30030101 && (uVar22 != 0x31180000)) &&
              (((uVar22 & 0xffff0000) != 0x31170000 &&
               ((*(short *)(param_1 + 0x1b8) != 0 ||
                (uVar6 = *(ushort *)(param_1 + 0x1ba), *(ushort *)(param_1 + 0x1ba) = uVar6 + 1,
                uVar6 < 0x14)))))))) {
            StorPortLogError(param_1);
          }
          bVar5 = *(byte *)((longlong)psVar3 + 3);
          uVar22 = *(uint *)(psVar3 + 4);
          if (bVar5 == 7) {
            HandleEventNotification(param_1,psVar3);
            if (*(char *)((longlong)psVar3 + 3) == '\b') goto LAB_1c0011d8a;
          }
          else {
            uVar15 = (uint)bVar5;
            if (((0x1b < bVar5) || ((0x8100002U >> (uVar15 & 0x1f) & 1) == 0)) &&
               (uVar22 != 0xbcaec)) {
              if ((uVar15 == 0x28) || (uVar15 == 0x2b)) {
                sVar7 = psVar3[7];
                bVar24 = (*(byte *)((longlong)psVar3 + 7) & 0x80) == 0;
                if ((bVar5 == 0x28) && (sVar7 != 0x98)) {
                  *(short *)(param_1 + 0xb9c) = sVar7;
                  if ((char)psVar3[1] == '\x05') {
                    if (*(char *)(param_1 + 0xb82) == '\0') {
                      ContinueRegisterPost(param_1);
                    }
                  }
                  else {
                    uVar9 = *(undefined4 *)(psVar3 + 0xc);
                    if ((*(int *)(psVar3 + 10) == 0) || (sVar7 != 0)) {
                      PostInBandBuffer(param_1,(ushort)uVar9);
                    }
                    else {
                      uVar12 = (ulonglong)*(ushort *)(param_1 + 0xb98);
                      lVar19 = *(longlong *)(param_1 + 0xbb0);
                      *(ushort *)(param_1 + 0xb98) = *(ushort *)(param_1 + 0xb98) + 1;
                      *(undefined4 *)(lVar19 + uVar12 * 0x28) = uVar9;
                      *(undefined4 *)(lVar19 + 4 + uVar12 * 0x28) = *(undefined4 *)(psVar3 + 10);
                      memcpy((void *)(lVar19 + 8 + uVar12 * 0x28),psVar3 + 0xe,0x10);
                      memcpy((void *)(lVar19 + (uVar12 * 5 + 3) * 8),psVar3 + 0x16,0x10);
                    }
                  }
                }
                **(int **)(param_1 + 0x40) = uVar16 * 2;
                LOCK();
                UNLOCK();
LAB_1c00123d4:
                if (!bVar24) goto LAB_1c0011d8a;
              }
              else {
                if (bVar5 - 0x1d < 2) {
                  bVar24 = true;
                  if (bVar5 == 0x1d) {
                    lVar19 = ((ulonglong)*(byte *)((longlong)psVar3 + 1) + 0x44) * 0x30 + param_1;
                    bVar24 = -1 < *(char *)((longlong)psVar3 + 7);
                    if (bVar24) {
                      *(undefined2 *)(lVar19 + 0x26) = 1;
                      *(undefined1 *)(lVar19 + 0x24) = 0;
                    }
                    else {
                      *(undefined2 *)(lVar19 + 0x26) = 0x101;
                    }
                    if ((psVar3[7] != 0xa0) && (psVar3[7] != 0)) {
                      *(undefined2 *)(lVar19 + 0x26) = 0;
                      StorPortLogError(param_1);
                    }
                    if (psVar3[7] == 0xa0) {
LAB_1c0012239:
                      bVar24 = false;
                    }
                    else if (*(char *)(lVar19 + 0x24) == '\0') {
                      lVar19 = *(longlong *)(param_1 + 0xd50);
                      if (lVar19 == 0) goto LAB_1c0012239;
                      if (*(int *)(*(longlong *)(lVar19 + 0x18) + 0x10) == -0x7f9b969f) {
                        *(uint *)(*(longlong *)(lVar19 + 0x18) + 0x14) =
                             -(uint)(psVar3[7] != 0) & 0x10;
                        *(undefined2 *)(lVar19 + 3) = 1;
                        StorPortNotification(0);
                        goto LAB_1c00122d0;
                      }
                    }
                  }
                  else if (bVar5 == 0x1e) {
                    lVar19 = *(longlong *)(param_1 + 0xd50);
                    lVar14 = (ulonglong)*(byte *)((longlong)psVar3 + 1) + 0x44;
                    if (lVar19 == 0) goto LAB_1c0012239;
                    lVar10 = *(longlong *)(lVar19 + 0x18);
                    if ((psVar3[7] == 0) && (*(char *)(param_1 + 0x27 + lVar14 * 0x30) == '\0')) {
                      *(undefined4 *)(lVar10 + 0x14) = 0;
                    }
                    else {
                      *(undefined4 *)(lVar10 + 0x14) = 0x12;
                    }
                    if (*(int *)(lVar10 + 0x1c) == 2) {
                      *(undefined4 *)(param_1 + 0x28 + lVar14 * 0x30) = 0;
                    }
                    *(undefined2 *)(lVar19 + 3) = 1;
                    StorPortNotification(0);
                    bVar24 = true;
LAB_1c00122d0:
                    *(undefined8 *)(param_1 + 0xd50) = 0;
                  }
                  **(int **)(param_1 + 0x40) = uVar16 * 2;
                  LOCK();
                  UNLOCK();
                  goto LAB_1c00123d4;
                }
                if ((uVar15 != 4) || ((uVar22 >> 0x18 & 1) == 0)) {
                  local_res18[0] = uVar22 & 0xeeffffff;
                  LsiCompleteIO(param_1,(char *)psVar3,(ulonglong)local_res18[0]);
                  **(int **)(param_1 + 0x40) = uVar16 * 2;
                  LOCK();
                  UNLOCK();
                  if ((uVar22 >> 0x1c & 1) == 0) goto LAB_1c00123e2;
                  goto LAB_1c0011d8a;
                }
                sVar7 = psVar3[7];
                plVar4 = (longlong *)
                         (*(longlong *)(param_1 + 0x148) + ((ulonglong)uVar22 & 0xfeffffff) * 0x18);
                if ((*(uint *)(*plVar4 + 8) >> 0x18 & 1) == 0) {
LAB_1c0012129:
                  bVar24 = true;
                }
                else {
                  lVar19 = plVar4[1];
                  if (lVar19 == 0) {
                    StorPortLogError(param_1,0,0,0,0,6,0xad010024);
                    goto LAB_1c0012129;
                  }
                  lVar14 = *(longlong *)(lVar19 + 0x38);
                  bVar5 = *(byte *)(lVar14 + 0x30);
                  puVar2 = (undefined8 *)(lVar14 + 8);
                  iVar8 = *(int *)(lVar14 + 0x34);
                  *(longlong **)(lVar14 + 0x28) = plVar4;
                  *(short *)(lVar14 + 0x32) = sVar7;
                  if (bVar5 == 8) {
                    puVar17 = (uint *)*puVar2;
                    if (iVar8 == 2) goto LAB_1c00120b5;
                    ProcessSASPortInfo(param_1,(int *)puVar17,lVar19);
                    uVar15 = 0x1730;
                    if (iVar8 == 1) {
                      uVar15 = 8;
                    }
LAB_1c00120f6:
                    ScsiPortWmiPostProcess((longlong)puVar2,cVar20,uVar15);
                    *(undefined4 *)(lVar19 + 0x10) = *(undefined4 *)(lVar14 + 0x24);
                    *(undefined1 *)(lVar19 + 3) = *(undefined1 *)(lVar14 + 0x21);
                    StorPortNotification(0,param_1);
                    goto LAB_1c0012129;
                  }
                  if ((bVar5 < 9) || ((10 < bVar5 && (bVar5 != 0xb)))) {
                    uVar15 = 0;
                    cVar20 = '\x04';
                    goto LAB_1c00120f6;
                  }
                  puVar17 = (uint *)*puVar2;
LAB_1c00120b5:
                  uVar13 = ProcessSASPortAttributes(param_1,puVar17,lVar19);
                  if ((char)uVar13 != '\0') {
                    uVar15 = 0x23c;
                    goto LAB_1c00120f6;
                  }
                  bVar24 = false;
                }
                **(int **)(param_1 + 0x40) = uVar16 * 2;
                LOCK();
                UNLOCK();
                if (!bVar24) goto LAB_1c0011d8a;
                uVar22 = uVar22 & 0xfeffffff;
              }
              local_res18[0] = uVar22;
              goto LAB_1c00123e2;
            }
            NonSCB_Func_handler(param_1,(char *)psVar3);
          }
LAB_1c001246d:
          **(int **)(param_1 + 0x40) = uVar16 * 2;
          LOCK();
          UNLOCK();
        }
        goto LAB_1c0011d8a;
      }
      if (bVar11) {
        in_RAX = (uint *)(ulonglong)local_res20;
        uVar16 = local_res20 - 1;
        bVar24 = local_res20 != 0;
        local_res20 = uVar16;
        if ((bVar24) &&
           (in_RAX = *(uint **)(param_1 + 0x158), *(uint **)(param_1 + 0x160) != in_RAX)) {
          StorPortStallExecution(1000);
          goto LAB_1c0011d8a;
        }
      }
      if (((((cVar21 != '\0') && (*(char *)(param_1 + 0x80) == '\0')) ||
           (*(int *)(param_1 + 0x1ac) != 0)) ||
          ((*(int *)(param_1 + 0x1c8) != 0 || (*(char *)(param_1 + 0x664) != '\0')))) ||
         (in_RAX = (uint *)(ulonglong)**(uint **)(param_1 + 0x28),
         (**(uint **)(param_1 + 0x28) & 1) == 0)) goto LAB_1c00125af;
      in_RAX = *(uint **)(param_1 + 0x10);
      if (*in_RAX == 0xffffffff) break;
      if ((*in_RAX & 0xf0000000) == 0) {
        StorPortPause(param_1,300);
        *(short *)(param_1 + 0x1da) = *(short *)(param_1 + 0x1da) + 1;
        bVar11 = true;
        *(undefined4 *)(param_1 + 0x1c0) = 2;
        local_res20 = 500;
      }
      in_RAX = (uint *)(ulonglong)**(uint **)(param_1 + 0x30);
      if ((**(uint **)(param_1 + 0x30) & 1) == 0) {
        in_RAX = *(uint **)(param_1 + 0x28);
        *in_RAX = 0;
        LOCK();
        UNLOCK();
      }
      cVar21 = cVar21 + '\x01';
      if ((!bVar11) || (in_RAX = *(uint **)(param_1 + 0x158), *(uint **)(param_1 + 0x160) == in_RAX)
         ) goto LAB_1c00125af;
    } while( true );
  }
LAB_1c00125eb:
  return (ulonglong)in_RAX & 0xffffffffffffff00;
LAB_1c00125af:
  if (cVar21 != '\0') {
    if (((*(char *)(param_1 + 0x663) != '\0') &&
        (*(longlong **)(param_1 + 0x160) == *(longlong **)(param_1 + 0x158))) &&
       (*(longlong *)(**(longlong **)(param_1 + 0x160) + 8) == 0)) {
      in_RAX = (uint *)StorPortResume(param_1);
      *(undefined1 *)(param_1 + 0x663) = 0;
    }
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  goto LAB_1c00125eb;
}



===== LsiCompleteIO @ 1c0012608 =====

void LsiCompleteIO(longlong param_1,char *param_2,ulonglong param_3)

{
  byte *pbVar1;
  ushort *puVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  ushort uVar9;
  void *_Src;
  ulonglong uVar10;
  
  uVar9 = *(ushort *)(param_2 + 0xe) & 0x7fff;
  cVar3 = param_2[3];
  if (((cVar3 != '\0') && (cVar3 != '\x1f')) || ((*(uint *)(param_2 + 8) & 0x10000000) != 0)) {
    if ((cVar3 != '\0') && (cVar3 != '\x1f')) {
      NonSCB_Func_handler(param_1,param_2);
      return;
    }
    if (-1 < *(char *)(param_1 + 0x134)) {
      return;
    }
    if (*(int *)(param_1 + 0x1c0) == 0) {
      DvInterpretError(param_1,(longlong)param_2);
      DomainValidation(param_1);
      return;
    }
    return;
  }
  lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x148) + 8 + (param_3 & 0xffffffff) * 0x18);
  if (lVar6 == 0) {
    StorPortLogError(param_1,0,0,0,0,6,0xad010024);
    return;
  }
  bVar4 = *(byte *)(lVar6 + 6);
  if ((((*(ushort *)(param_1 + 0x134) & 0x100) != 0) && (*(char *)(lVar6 + 0x48) == '\x12')) &&
     (((*(byte *)(lVar6 + 0x49) & 1) == 0 &&
      (((**(byte **)(lVar6 + 0x18) & 0x1f) == 0 && (7 < *(uint *)(param_2 + 0x14))))))) {
    pbVar1 = *(byte **)(lVar6 + 0x18) + 7;
    *pbVar1 = *pbVar1 | 0x32;
  }
  cVar3 = param_2[0xc];
  *(char *)(lVar6 + 4) = cVar3;
  if (uVar9 < 0x45) {
    if (uVar9 == 0x44) {
      *(undefined1 *)(lVar6 + 3) = 0x12;
    }
    else if (uVar9 < 8) {
      if (5 < uVar9) goto LAB_1c0012761;
      if (uVar9 == 0) goto LAB_1c001292a;
      if (uVar9 == 1) {
        *(undefined1 *)(lVar6 + 3) = 6;
      }
      else {
        if (uVar9 != 2) goto LAB_1c0012761;
LAB_1c0012971:
        *(undefined2 *)(lVar6 + 3) = 0x805;
        if (((byte)(param_2[0xc] + 0x80U) < 2) && (*(char *)(param_1 + 0x660) == '\x02')) {
          *(undefined2 *)(lVar6 + 3) = 10;
        }
        if (*(int *)(lVar6 + 0x14) == 36000) {
          *(undefined4 *)(lVar6 + 0x14) = 35999;
        }
      }
    }
    else if (uVar9 == 0x40) {
LAB_1c001292a:
      *(undefined1 *)(lVar6 + 3) = 1;
    }
    else if (uVar9 == 0x41) {
      *(undefined1 *)(lVar6 + 3) = 7;
    }
    else if (uVar9 == 0x42) {
      *(undefined1 *)(lVar6 + 3) = 0x21;
    }
    else {
      if (uVar9 != 0x43) goto LAB_1c0012761;
      if (((*(ushort *)(param_1 + 0x134) & 0x100) != 0) && (*(int *)(param_1 + 0x1c4) != 0))
      goto LAB_1c00127a9;
      uVar10 = (ulonglong)bVar4;
      *(undefined1 *)(lVar6 + 3) = 10;
      bVar5 = *(byte *)(param_1 + 0xe9c + uVar10);
      if ((bVar5 != 0) && ((bVar5 & 0x10) == 0)) {
        puVar2 = (ushort *)(param_1 + 0xe78 + uVar10 * 2);
        *puVar2 = *puVar2 | 1;
        *(undefined1 *)(param_1 + 0xe9c + uVar10) = 0;
        CheckQASBusStatus(param_1);
      }
      if (((*(char *)(param_1 + 0x134) < '\0') && (*(char *)(param_1 + 0x659) != '\0')) &&
         (uVar9 = 1 << (bVar4 & 0x1f), (uVar9 & *(ushort *)(param_1 + 0x65a)) != 0)) {
        pbVar1 = *(byte **)(param_1 + 0xd68);
        pbVar1[0] = 0;
        pbVar1[1] = 0;
        pbVar1[2] = 0;
        pbVar1[3] = 0;
        pbVar1[4] = 0;
        pbVar1[5] = 0;
        pbVar1[6] = 0;
        pbVar1[7] = 0;
        pbVar1[0x10] = 0;
        pbVar1[0x11] = 0;
        pbVar1[0x12] = 0;
        pbVar1[0x13] = 0;
        pbVar1[0x14] = 0;
        pbVar1[0x15] = 0;
        pbVar1[0x16] = 0;
        pbVar1[0x17] = 0;
        pbVar1[0x18] = 0;
        pbVar1[0x19] = 0;
        pbVar1[0x1a] = 0;
        pbVar1[0x1b] = 0;
        pbVar1[0x1c] = 0;
        pbVar1[0x1d] = 0;
        pbVar1[0x1e] = 0;
        pbVar1[0x1f] = 0;
        *pbVar1 = bVar4;
        pbVar1[1] = 0;
        pbVar1[3] = 0x18;
        pbVar1[4] = 0;
        pbVar1[8] = 0xed;
        pbVar1[9] = 0xfe;
        pbVar1[10] = 0;
        pbVar1[0xb] = 0x10;
        pbVar1[0xc] = 0;
        pbVar1[0xd] = 0;
        pbVar1[0xe] = 0;
        pbVar1[0xf] = 0;
        **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
        LOCK();
        UNLOCK();
        *(ushort *)(param_1 + 0x65a) = *(ushort *)(param_1 + 0x65a) & ~uVar9;
      }
      if ((*(char *)(param_1 + 0x134) < '\0') &&
         (uVar8 = *(uint *)(param_1 + 0x112c + uVar10 * 4), uVar8 < 0xfffffffe)) {
        *(uint *)(param_1 + 0x112c + uVar10 * 4) = uVar8 + 1;
      }
    }
  }
  else if (uVar9 < 0x4b) {
    if (uVar9 != 0x4a) {
      if (uVar9 == 0x45) {
        if (((cVar3 - 8U & 0xdf) != 0) && ((param_2[0xd] & 1U) == 0)) {
          *(undefined1 *)(lVar6 + 3) = 0x12;
          *(undefined4 *)(lVar6 + 0x10) = *(undefined4 *)(param_2 + 0x14);
        }
        goto LAB_1c0012897;
      }
      if ((0x45 < uVar9) && (0x47 < uVar9)) {
        if (uVar9 == 0x48) {
          cVar3 = *(char *)(param_1 + 0xf40);
          if ((((cVar3 - 3U & 0xfd) != 0) && ((cVar3 - 1U & 0xfa) == 0)) && (cVar3 != '\x05')) {
            *(undefined1 *)(lVar6 + 3) = 2;
            if ((*(char *)(param_1 + 0x135e) != '\0') && (*(int *)(lVar6 + 0x14) == 36000)) {
              *(undefined4 *)(lVar6 + 0x14) = 0x8c96;
            }
            goto LAB_1c0012897;
          }
          goto LAB_1c00127d0;
        }
        if (uVar9 == 0x49) goto LAB_1c0012971;
      }
    }
LAB_1c0012761:
    *(undefined1 *)(lVar6 + 3) = 4;
  }
  else if (uVar9 == 0x4b) {
    if (((*(ushort *)(param_1 + 0x134) & 0x200) != 0) &&
       ((*(ushort *)(param_2 + 0xe) & 0x8000) != 0)) {
      if ((*(uint *)(param_2 + 0x10) & 0xffff0000) == 0x31120000) {
        *(undefined1 *)(lVar6 + 3) = 4;
        *(undefined4 *)(lVar6 + 0x14) = *(undefined4 *)(param_2 + 0x10);
        goto LAB_1c0012897;
      }
      if ((*(uint *)(param_2 + 0x10) & 0xffff0000) == 0x31170000) goto LAB_1c0012adb;
    }
LAB_1c00127a9:
    if ((*(char *)(param_1 + 0x663) == '\0') && (*(int *)(param_1 + 0x1c8) == 0)) {
      StorPortPause(param_1,0x1e);
      *(undefined1 *)(param_1 + 0x663) = 1;
    }
LAB_1c00127d0:
    *(undefined1 *)(lVar6 + 3) = 0xe;
  }
  else if (uVar9 == 0x4c) {
    if ((*(ushort *)(param_1 + 0x134) & 0x100) == 0) goto LAB_1c00127a9;
    if ((*(char *)(param_1 + 0x660) == '\x02') && ((byte)(param_2[0xc] + 0x80U) < 2)) {
      *(undefined2 *)(lVar6 + 3) = 10;
    }
    else {
LAB_1c0012adb:
      *(undefined2 *)(lVar6 + 3) = 0x805;
    }
  }
  else {
    if (2 < uVar9 - 0x4d) goto LAB_1c0012761;
    *(undefined1 *)(lVar6 + 3) = 0xf;
    StorPortLogError(param_1,lVar6,CONCAT71(1,*(undefined1 *)(lVar6 + 5)),bVar4,
                     *(undefined1 *)(lVar6 + 7),1,uVar9);
  }
LAB_1c0012897:
  bVar5 = param_2[0xd];
  if ((bVar5 & 1) == 0) {
    if ((bVar5 & 2) == 0) {
      if ((((bVar5 & 0x10) != 0) && (*(char *)(lVar6 + 3) == '\x01')) &&
         (*(int *)(param_2 + 0x1c) != 0)) {
        *(undefined2 *)(lVar6 + 3) = 4;
      }
      goto LAB_1c0012b21;
    }
  }
  else {
    _Src = (void *)(*(longlong *)(lVar6 + 0x38) + 0x38);
    if ((*(uint *)(lVar6 + 0xc) & 0x20) == 0) {
      *(undefined1 *)(lVar6 + 3) = 0x84;
      bVar5 = param_2[0x18];
      *(byte *)(lVar6 + 0xb) = bVar5;
      memcpy(*(void **)(lVar6 + 0x20),_Src,(ulonglong)bVar5);
      lVar7 = *(longlong *)(lVar6 + 0x20);
      if (*(char *)(param_1 + 0x134) < '\0') {
        CompaqCheckSenseData(param_1,*(byte *)(lVar6 + 0x48),lVar7,bVar4);
      }
      if ((*(char *)(param_1 + 0x659) != '\0') || ((*(ushort *)(param_1 + 0x134) & 0x200) != 0)) {
        CheckSmartInfo(param_1,lVar6,lVar7);
      }
      goto LAB_1c0012b21;
    }
    memcpy(*(void **)(param_1 + 0x670),_Src,0xff);
    *(undefined1 *)(param_1 + 0x66e) = 1;
  }
  *(undefined1 *)(lVar6 + 3) = 4;
LAB_1c0012b21:
  uVar8 = *(byte *)(lVar6 + 4) - 0x18;
  if (((byte)uVar8 < 0x29) && ((0x10000000401U >> ((ulonglong)uVar8 & 0x3f) & 1) != 0)) {
    *(undefined1 *)(lVar6 + 3) = 4;
  }
  else if ((*(byte *)(lVar6 + 4) - 8 & 0xdf) == 0) {
    *(undefined1 *)(lVar6 + 3) = 5;
  }
  StorPortNotification(0,param_1,lVar6);
  return;
}



===== CheckSmartInfo @ 1c0012b7c =====

void CheckSmartInfo(longlong param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  longlong lVar5;
  byte bVar6;
  char cVar7;
  ulonglong uVar8;
  int iVar9;
  undefined2 uVar10;
  
  bVar1 = *(byte *)(param_2 + 5);
  bVar2 = *(byte *)(param_2 + 6);
  uVar10 = 0;
  if (*(char *)(param_3 + 0xc) == ']') {
    lVar5 = *(longlong *)(param_1 + 0xe50);
    if ((lVar5 != 0) && (bVar3 = *(byte *)(lVar5 + 8), bVar3 != 0)) {
      pbVar4 = (byte *)(lVar5 + 0xc);
      bVar6 = 0;
      if (bVar3 != 0) {
        do {
          if ((bVar1 == pbVar4[1]) && (bVar2 == *pbVar4)) {
            return;
          }
          pbVar4 = pbVar4 + 8;
          bVar6 = bVar6 + 1;
        } while (bVar6 < bVar3);
      }
    }
    if (*(char *)(param_1 + 0x134) < '\0') {
      iVar9 = 0xc;
      *(ushort *)(param_1 + 0x65a) = *(ushort *)(param_1 + 0x65a) | 1 << (bVar2 & 0xf);
    }
    else {
      iVar9 = 0xf;
      lVar5 = FindSasAddressTableEntry(param_1,bVar1,bVar2,0x680);
      if ((lVar5 != 0) && (uVar10 = *(undefined2 *)(lVar5 + 10), *(char *)(param_1 + 0x659) != '\0')
         ) {
        *(uint *)(lVar5 + 0xc) = *(uint *)(lVar5 + 0xc) | 0x80000000;
      }
    }
    if ((*(uint *)(param_1 + 0x330) >> iVar9 & 1) != 0) {
      bVar3 = *(byte *)(param_1 + 0x658);
      uVar8 = (ulonglong)bVar3;
      *(int *)(param_1 + 0x338 + uVar8 * 0x10) = iVar9;
      *(int *)(param_1 + 0x334) = *(int *)(param_1 + 0x334) + 1;
      *(undefined4 *)(param_1 + 0x33c + uVar8 * 0x10) = *(undefined4 *)(param_1 + 0x334);
      *(byte *)(param_1 + 0x340 + uVar8 * 0x10) = bVar2;
      *(byte *)(param_1 + 0x341 + uVar8 * 0x10) = bVar1;
      *(undefined1 *)(param_1 + 0x342 + uVar8 * 0x10) = 5;
      *(undefined1 *)(param_1 + 0x344 + uVar8 * 0x10) = 0x5d;
      *(undefined1 *)(param_1 + 0x345 + uVar8 * 0x10) = *(undefined1 *)(param_3 + 0xd);
      if (iVar9 == 0xc) {
        *(undefined1 *)(param_1 + 0x343 + uVar8 * 0x10) = *(undefined1 *)(param_2 + 7);
        *(undefined2 *)(param_1 + 0x346 + uVar8 * 0x10) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x343 + uVar8 * 0x10) = 0;
        *(undefined2 *)(param_1 + 0x346 + uVar8 * 0x10) = uVar10;
      }
      cVar7 = bVar3 + 1;
      if (cVar7 == '2') {
        cVar7 = '\0';
      }
      *(char *)(param_1 + 0x658) = cVar7;
      if (*(char *)(param_1 + 0xe29) != '\0') {
        ScsiPortWmiFireLogicalUnitEvent(param_1);
      }
    }
    if (*(char *)(param_1 + 0x659) != '\0') {
      pbVar4 = *(byte **)(param_1 + 0xd68);
      pbVar4[0] = 0;
      pbVar4[1] = 0;
      pbVar4[2] = 0;
      pbVar4[3] = 0;
      pbVar4[4] = 0;
      pbVar4[5] = 0;
      pbVar4[6] = 0;
      pbVar4[7] = 0;
      pbVar4[8] = 0;
      pbVar4[9] = 0;
      pbVar4[10] = 0;
      pbVar4[0xb] = 0;
      pbVar4[0xc] = 0;
      pbVar4[0xd] = 0;
      pbVar4[0xe] = 0;
      pbVar4[0xf] = 0;
      pbVar4[0x10] = 0;
      pbVar4[0x11] = 0;
      pbVar4[0x12] = 0;
      pbVar4[0x13] = 0;
      pbVar4[0x14] = 0;
      pbVar4[0x15] = 0;
      pbVar4[0x16] = 0;
      pbVar4[0x17] = 0;
      pbVar4[0x18] = 0;
      pbVar4[0x19] = 0;
      pbVar4[0x1a] = 0;
      pbVar4[0x1b] = 0;
      pbVar4[0x1c] = 0;
      pbVar4[0x1d] = 0;
      pbVar4[0x1e] = 0;
      pbVar4[0x1f] = 0;
      *pbVar4 = bVar2;
      pbVar4[1] = bVar1;
      pbVar4[3] = 0x18;
      pbVar4[4] = 0;
      pbVar4[8] = 0xed;
      pbVar4[9] = 0xfe;
      pbVar4[10] = 0;
      pbVar4[0xb] = 0x10;
      pbVar4[0xc] = 0x40;
      pbVar4[0xd] = 0;
      pbVar4[0xe] = 0;
      pbVar4[0xf] = 0;
      **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
      LOCK();
      UNLOCK();
    }
  }
  return;
}



===== FindSasAddressTableEntry @ 1c0012d70 =====

longlong FindSasAddressTableEntry(longlong param_1,char param_2,char param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(uint *)(param_1 + 0x1350) != 0) {
    do {
      lVar1 = uVar3 * 0x10 + *(longlong *)(param_1 + 0x1348);
      if (((*(char *)(lVar1 + 8) == param_2) && (*(char *)(lVar1 + 9) == param_3)) &&
         ((*(uint *)(lVar1 + 0xc) & param_4) != 0)) {
        return lVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(param_1 + 0x1350));
  }
  return 0;
}



===== LSImpiIsr @ 1c0012dc0 =====

void LSImpiIsr(longlong param_1)

{
  LSImpiMSIIsr(param_1);
  return;
}



===== DomainValidation @ 1c0012dc8 =====

undefined8 DomainValidation(longlong param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  ulonglong *puVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  ushort uVar6;
  short sVar7;
  byte bVar8;
  byte bVar9;
  char cVar10;
  byte *in_RAX;
  byte *pbVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  byte bVar15;
  uint uVar16;
  char cVar17;
  byte bVar18;
  int iVar19;
  ushort uVar20;
  int iVar21;
  short sVar22;
  int iVar23;
  ushort uVar24;
  byte bVar25;
  undefined1 *_Dst;
  byte *pbVar26;
  byte local_res10;
  uint local_res18 [2];
  uint local_res20;
  uint local_58;
  
  uVar13 = 0;
  if (*(char *)(param_1 + 0x688) != '\0') {
LAB_1c0012deb:
    return (ulonglong)in_RAX & 0xffffffffffffff00;
  }
  pbVar11 = (byte *)(ulonglong)*(byte *)(param_1 + 0xeb0);
  bVar9 = *(byte *)(param_1 + 0xeae);
  pbVar26 = (byte *)(ulonglong)*(byte *)(param_1 + 0xeb0);
  bVar25 = *(byte *)(param_1 + 0xeb4);
  local_res20 = (uint)*(ushort *)(param_1 + 0xec8);
  uVar24 = *(ushort *)(param_1 + 0xe78 + (longlong)pbVar11 * 2);
  uVar6 = uVar24 & 0x20;
  bVar8 = (byte)uVar24 & 0x20;
  if (*(char *)(param_1 + 0xd62) == -1) {
    in_RAX = pbVar11;
    if (bVar9 == 1) {
LAB_1c0013c44:
      *(undefined2 *)(param_1 + 0xe78 + (longlong)in_RAX * 2) = 8;
      *(char *)(param_1 + 0xec1) = (char)uVar13;
      goto LAB_1c0012deb;
    }
    bVar9 = 0;
    uVar24 = uVar24 | 8;
  }
  else {
    local_58 = *(uint *)(*(longlong *)(param_1 + 0xe48) + 4) & 0x60;
  }
  *(undefined1 *)(param_1 + 0x681) = 0;
  StorPortNotification(6,param_1,WatchdogTimer,1000000);
  uVar13 = 0;
LAB_1c0012e86:
  iVar21 = (int)pbVar11;
  local_res18[0] = *(uint *)(param_1 + 0xe3c);
  bVar15 = (byte)uVar13;
  sVar22 = (short)uVar13;
  iVar23 = (int)uVar13;
  in_RAX = pbVar11;
  local_res10 = bVar15;
  if (bVar9 < 0xf) {
    if (bVar9 == 0xe) {
      if ((uVar24 & 0x80) != 0) {
LAB_1c001344b:
        uVar24 = uVar24 & 0xff7f;
        *(undefined1 *)(param_1 + 0xeb2) = 4;
        goto LAB_1c0013456;
      }
      uVar14 = SyncFallBack(param_1);
      if ((char)uVar14 == '\0') {
        *(undefined4 *)(param_1 + 0xed8 + (longlong)pbVar26 * 4) = *(undefined4 *)(param_1 + 0xed4);
        bVar9 = -(*(char *)(param_1 + 0xeb1) != '\x01') & 0xd;
      }
      else {
        if (*(char *)(param_1 + 0xeb1) == '\x02') {
          pbVar26[param_1 + 0xe9c] = pbVar26[param_1 + 0xe9c] & 0xf9;
          *(undefined1 *)(param_1 + 0xeae) = 7;
          goto LAB_1c00134ae;
        }
        bVar9 = *(byte *)(param_1 + 0xeaf);
      }
      *(byte *)(param_1 + 0xeae) = bVar9;
LAB_1c0013073:
      bVar15 = 1;
      goto LAB_1c001307c;
    }
    if (7 < bVar9) {
      if (bVar9 == 8) {
LAB_1c001303d:
        *(undefined1 *)(param_1 + 0xeae) = 0x24;
        uVar24 = uVar24 | 0x80;
        bVar9 = 0xb;
        goto LAB_1c001304f;
      }
      if (bVar9 == 9) goto LAB_1c0013bbc;
      if (bVar9 == 10) {
LAB_1c0013aec:
        *(undefined1 *)(param_1 + 0xeae) = 0x26;
        SendReserveRelease(param_1,'\x01');
        goto LAB_1c00131d1;
      }
      if (bVar9 == 0xb) goto LAB_1c0013a01;
      if (bVar9 == 0xc) goto LAB_1c0013a0f;
      if (bVar9 == 0xd) {
        if (*(char *)(param_1 + 0xeb3) != '\x04') {
          uVar24 = uVar24 | 8;
        }
        *(byte *)(param_1 + 0xeae) = bVar15;
        bVar15 = 1;
        if ((uVar24 & 0x40) != 0) {
          SendReserveRelease(param_1,'\0');
          uVar13 = 0;
          bVar15 = 0;
          goto LAB_1c001307c;
        }
        goto LAB_1c0013082;
      }
      goto LAB_1c0013c44;
    }
    if (bVar9 != 7) {
      if (bVar9 == 0) {
        if (bVar8 == bVar15) {
          if (*(byte *)(param_1 + 0xebf) == bVar15) {
            uVar24 = uVar24 & 0xfffc;
          }
          else {
            *(byte *)(param_1 + 0xebf) = bVar15;
            uVar24 = uVar24 & 0xfffd;
          }
          if ((uVar24 & 0x100) == 0) {
            *(ushort *)(param_1 + 0xe78 + (longlong)pbVar26 * 2) = uVar24;
            if (*(longlong *)(param_1 + 0xf20) != 0) {
              **(undefined4 **)(param_1 + 0x38) =
                   **(undefined4 **)(*(longlong *)(param_1 + 0xf20) + 0x38);
              LOCK();
              UNLOCK();
              *(ulonglong *)(param_1 + 0xf20) = uVar13;
            }
          }
          else {
            uVar24 = uVar24 & 0xfeff;
          }
          *(byte *)(param_1 + 0xec1) = bVar15;
        }
        else {
LAB_1c0013336:
          *(undefined1 *)(param_1 + 0xeae) = 0x11;
          bVar15 = 1;
        }
        goto LAB_1c0013082;
      }
      if (bVar9 == 1) {
        uVar12 = CheckPhysDisk(param_1,(byte)pbVar11);
        if ((char)uVar12 != '\0') {
          puVar3 = *(ulonglong **)(param_1 + 0xd68);
          *(undefined1 *)(param_1 + 0xeae) = 0x10;
          uVar24 = uVar24 | 0x20;
          *puVar3 = uVar13;
          puVar3[1] = uVar13;
          puVar3[2] = uVar13;
          puVar3[3] = uVar13;
          *(undefined1 *)puVar3 = 6;
          *(undefined2 *)((longlong)puVar3 + 3) = 0x15;
          *(char *)((longlong)puVar3 + 5) = (char)uVar13;
          *(undefined1 *)((longlong)puVar3 + 6) = *(undefined1 *)(param_1 + 0xeb8);
          *(uint *)(puVar3 + 1) = *(byte *)(param_1 + 0xeae) | 0x10000000;
          **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
          LOCK();
          UNLOCK();
          goto LAB_1c001307c;
        }
LAB_1c00132da:
        *(undefined1 *)(param_1 + 0xeb1) = 1;
        *(undefined2 *)(param_1 + 0xeba) = 1;
        *(char *)(param_1 + 0xebe) = (char)uVar13;
        uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0xe48) + 0xc + (longlong)pbVar26 * 4);
        *(undefined4 *)(param_1 + 0xed8 + (longlong)pbVar26 * 4) = uVar1;
        uVar13 = *(ulonglong *)(param_1 + 0xe70);
        *(undefined4 *)(param_1 + 0xed4) = uVar1;
        *(undefined1 *)(param_1 + 0xeae) = 3;
        *(undefined1 *)(param_1 + 0xd62) = 0x91;
        goto LAB_1c0013324;
      }
      if (bVar9 == 2) goto LAB_1c00132da;
      if (bVar9 == 3) {
        uVar13 = *(ulonglong *)(param_1 + 0xe70);
        *(undefined1 *)(param_1 + 0xeae) = 4;
        *(undefined1 *)(param_1 + 0xd62) = 0x92;
        if (*(int *)(param_1 + 0x1c8) == iVar23) {
          *(int *)(uVar13 + 0xc) = iVar23;
          uVar16 = *(uint *)(*(longlong *)(param_1 + 0xe48) + 0xc + (longlong)pbVar26 * 4);
          iVar19 = iVar23;
          if ((char)(uVar16 >> 8) == '\0') {
            iVar19 = 4;
          }
          *(int *)(uVar13 + 0xc) = iVar19;
          if ((uVar16 & 0x100000) != 0) {
            *(uint *)(uVar13 + 0xc) = *(uint *)(uVar13 + 0xc) | 2;
          }
          *(int *)(uVar13 + 4) = iVar23;
        }
        goto LAB_1c0013254;
      }
      if (bVar9 == 4) {
        if (*(int *)(param_1 + 0x1c8) != iVar23) goto LAB_1c0013c20;
        iVar21 = (int)*(undefined8 *)(param_1 + 0xf30);
        bVar9 = 0x3a;
        *(undefined2 *)(param_1 + 0xeae) = 0x321;
LAB_1c00131c9:
        SendInquiry(param_1,bVar9,iVar21);
        goto LAB_1c00131d1;
      }
      if (bVar9 == 5) {
        if ((uVar24 & 0x10) == 0) {
          iVar21 = (int)*(undefined8 *)(param_1 + 0xf38);
          *(undefined1 *)(param_1 + 0xeae) = 0x23;
          goto LAB_1c00131c7;
        }
        goto LAB_1c00131ad;
      }
      if (bVar9 == 6) {
        cVar10 = *(char *)(param_1 + 0xed5);
        uVar16 = *(uint *)(*(longlong *)(param_1 + 0xe68) + 4);
        cVar17 = (char)(uVar16 >> 8);
        *(char *)(param_1 + 0xed5) = cVar17;
        bVar9 = ~((byte)*(ushort *)(param_1 + 0xed6) >> 4) & 1;
        if ((bVar9 != 0) && ((uVar16 >> 0x1d & 1) == 0)) {
          *(ushort *)(param_1 + 0xed6) = *(ushort *)(param_1 + 0xed6) | 0x10;
          bVar9 = bVar15;
        }
        *(byte *)(param_1 + 0xebc) = bVar9;
        if ((uVar16 & 4) != 0) {
          pbVar26[param_1 + 0xe9c] = pbVar26[param_1 + 0xe9c] | 6;
        }
        if ((cVar10 == '\b') && (cVar17 == '\n')) {
          *(undefined1 *)(param_1 + 0xed5) = 8;
          *(undefined1 *)(param_1 + 0xeae) = 0xe;
          goto LAB_1c0012f77;
        }
        if ((((uVar24 & 0x400) != 0) && (cVar17 == '\b')) && ((uVar16 >> 0x1b & 1) == 0)) {
          *(undefined1 *)(param_1 + 0xeae) = 0xe;
          uVar24 = uVar24 & 0xff7f;
          goto LAB_1c0012fa0;
        }
        cVar10 = DataBufCompare(param_1);
        uVar13 = 0;
        if (cVar10 != '\0') {
          *(undefined4 *)(param_1 + 0xed8 + (longlong)pbVar26 * 4) =
               *(undefined4 *)(param_1 + 0xed4);
          *(uint *)(param_1 + 0x10ec + (longlong)pbVar26 * 4) = uVar16;
          if (((pbVar26[param_1 + 0xe9c] & 1) == 0) || (local_58 == 0x20)) goto LAB_1c001306c;
          *(undefined2 *)(param_1 + 0xeb1) = 0x402;
          uVar24 = uVar24 & 0xffbf;
          *(undefined1 *)(param_1 + 0xebb) = 0;
          goto LAB_1c001303d;
        }
        bVar15 = 1;
        if (*(char *)(param_1 + 0xeba) == '\0') {
          *(undefined1 *)(param_1 + 0xeae) = 0xe;
        }
        else {
          *(undefined1 *)(param_1 + 0xeba) = 0;
          bVar25 = 0;
          *(undefined1 *)(param_1 + 0xeae) = 3;
          local_res20 = 0;
        }
        goto LAB_1c0013082;
      }
      goto LAB_1c0013c44;
    }
    *(undefined1 *)(param_1 + 0xeae) = *(undefined1 *)(param_1 + 0xeaf);
    local_res20 = CONCAT22(local_res20._2_2_,sVar22);
    bVar25 = bVar15;
LAB_1c0012fa0:
    bVar15 = 1;
  }
  else {
    sVar7 = (short)local_res20;
    bVar18 = bVar15;
    if (bVar9 < 0x23) {
      if (bVar9 == 0x22) {
        if (((short)local_res20 == sVar22) && (bVar25 == 0)) {
          *(undefined2 *)(param_1 + 0xec2) = *(undefined2 *)(param_1 + 0xecc);
          *(undefined1 *)(param_1 + 0xeae) = 5;
LAB_1c00134ae:
          uVar13 = *(ulonglong *)(param_1 + 0xe70);
          *(undefined1 *)(param_1 + 0xd62) = 0x92;
          BuildScsiDevicePage1(param_1,uVar13,uVar24);
LAB_1c0013254:
          cVar10 = '\x02';
          goto LAB_1c001325a;
        }
      }
      else {
        if (bVar9 != 0x10) {
          if (bVar9 == 0x11) {
            puVar3 = *(ulonglong **)(param_1 + 0xd68);
            *(byte *)(param_1 + 0xeae) = bVar15;
            *puVar3 = uVar13;
            puVar3[1] = uVar13;
            puVar3[2] = uVar13;
            puVar3[3] = uVar13;
            *(undefined1 *)puVar3 = 7;
            *(undefined2 *)((longlong)puVar3 + 3) = 0x15;
            *(byte *)((longlong)puVar3 + 5) = bVar15;
            *(undefined1 *)((longlong)puVar3 + 6) = *(undefined1 *)(param_1 + 0xeb8);
            *(uint *)(puVar3 + 1) = *(byte *)(param_1 + 0xeae) | 0x10000000;
            **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
            LOCK();
            UNLOCK();
            uVar24 = uVar24 & 0xffdf;
            goto LAB_1c0013082;
          }
          if (bVar9 == 0x12) {
            iVar21 = 0;
            *(undefined1 *)(param_1 + 0xec1) = 1;
            cVar10 = '\0';
            local_res18[0] = 0x1030000;
            uVar24 = 0x103;
            *(undefined1 *)(param_1 + 0xeae) = 0x13;
            *(undefined1 *)(param_1 + 0xd62) = 0xa0;
            goto LAB_1c001325a;
          }
          if (bVar9 == 0x13) {
            local_res18[0] = *(uint *)(param_1 + 0xd98);
            iVar21 = 0;
            uVar13 = *(ulonglong *)(param_1 + 0xe58);
            *(undefined1 *)(param_1 + 0xeae) = 0x14;
            *(undefined1 *)(param_1 + 0xd62) = 0xa1;
            goto LAB_1c0013324;
          }
          if (bVar9 == 0x14) {
            in_RAX = *(byte **)(param_1 + 0xe58);
            if ((in_RAX != (byte *)0x0) && (bVar9 = in_RAX[4], bVar9 != 0)) {
              in_RAX = in_RAX + 8;
              uVar14 = uVar13 & 0xff;
              if (bVar9 != 0) {
                do {
                  if ((in_RAX[3] == *(byte *)(param_1 + 0xeb8)) &&
                     (in_RAX[2] == *(byte *)(param_1 + 0xe2a))) {
                    pbVar11 = (byte *)(ulonglong)*in_RAX;
                    goto LAB_1c0013712;
                  }
                  in_RAX = in_RAX + 4;
                  bVar18 = (char)uVar14 + 1;
                  uVar14 = (ulonglong)bVar18;
                } while (bVar18 < bVar9);
              }
              pbVar11 = (byte *)0xff;
LAB_1c0013712:
              if ((char)pbVar11 != -1) {
                uVar24 = *(ushort *)(param_1 + 0xe78 + (longlong)pbVar11 * 2) | 0x103;
                *(undefined1 *)(param_1 + 0xec1) = 1;
                *(ulonglong *)(param_1 + 0xf20) = uVar13;
                *(char *)(param_1 + 0xeb0) = (char)pbVar11;
                *(undefined1 *)(param_1 + 0xeae) = 1;
                pbVar26 = pbVar11;
LAB_1c0012f77:
                bVar15 = 1;
                goto LAB_1c001307c;
              }
            }
            *(byte *)(param_1 + 0xeae) = bVar15;
            goto LAB_1c0012deb;
          }
          if (bVar9 != 0x21) goto LAB_1c0013c44;
          if ((short)local_res20 != 0x43) {
            CheckForSEPDevice(param_1);
            uVar16 = *(uint *)(param_1 + 0xed4);
            uVar13 = 0;
            if (((char)(uVar16 >> 8) != '\0') || ((uVar16 >> 0x10 & 0x10) == 0)) {
              if ((sVar7 == 0) && (bVar25 == 0)) {
                pbVar4 = *(byte **)(param_1 + 0xf30);
                if ((*(uint *)(param_1 + 0xecc) < 0x3a) || ((pbVar4[0x38] & 4) == 0)) {
                  if ((byte)(*(char *)(param_1 + 0xed5) - 8U) < 2) {
                    *(undefined1 *)(param_1 + 0xed5) = 10;
                  }
                }
                else if ((pbVar4[0x38] & 1) == 0) {
                  if (*(char *)(param_1 + 0xed5) == '\b') {
                    *(undefined1 *)(param_1 + 0xed5) = 9;
                  }
                  uVar24 = uVar24 | 0x200;
                }
                pbVar26[param_1 + 0xe9c] = 8;
                if ((*pbVar4 & 0x1f) == 0) {
                  pbVar26[param_1 + 0xe9c] = 9;
                  bVar9 = pbVar26[param_1 + 0xe9c];
                  if (uVar6 != 0) {
                    bVar9 = 0x19;
                  }
                  pbVar26[param_1 + 0xe9c] = bVar9;
                }
                if (((*pbVar4 & 0x1f) == 1) && ((pbVar4[0x38] & 1) != 0)) {
                  uVar24 = uVar24 | 0x400;
                }
                if ((((((*pbVar4 & 0x1f) == 5) && ((pbVar4[0x38] & 1) != 0)) &&
                     (pbVar4[0x2b] == 0x24)) && ((pbVar4[0x2c] == 0x44 && (pbVar4[0x2d] == 0x52))))
                   && ((pbVar4[0x2e] == 0x2d && ((pbVar4[0x2f] == 0x31 && (pbVar4[0x30] == 0x30)))))
                   ) {
                  uVar24 = uVar24 | 0x400;
                }
                uVar20 = 1 << ((byte)pbVar11 & 0x1f);
                if ((pbVar4[7] & 2) == 0) {
                  *(ushort *)(param_1 + 0xf44) = *(ushort *)(param_1 + 0xf44) & ~uVar20;
                }
                else {
                  *(ushort *)(param_1 + 0xf44) = *(ushort *)(param_1 + 0xf44) | uVar20;
                }
                if ((pbVar4[7] & 0x20) == 0) {
                  *(ushort *)(param_1 + 0xf46) = *(ushort *)(param_1 + 0xf46) & ~uVar20;
                }
                else {
                  *(ushort *)(param_1 + 0xf46) = *(ushort *)(param_1 + 0xf46) | uVar20;
                }
                iVar21 = (int)*(undefined8 *)(param_1 + 0xf30);
                *(undefined1 *)(param_1 + 0xeae) = 0x22;
LAB_1c00131c7:
                bVar9 = 0x24;
                goto LAB_1c00131c9;
              }
              goto LAB_1c0013c20;
            }
            *(uint *)(param_1 + 0xed8 + (longlong)pbVar26 * 4) = uVar16;
LAB_1c001306c:
            uVar13 = 0;
            *(undefined1 *)(param_1 + 0xeae) = 0;
            goto LAB_1c0013073;
          }
          if (bVar8 != bVar15) {
            *(undefined1 *)(param_1 + 0xebf) = 1;
            goto LAB_1c0013336;
          }
          local_res10 = 1;
          uVar24 = uVar24 & 0xfffd;
          goto LAB_1c0013082;
        }
        if (((short)local_res20 == sVar22) && (*(short *)(param_1 + 0xeca) == sVar22)) {
          *(undefined1 *)(param_1 + 0xeae) = 2;
        }
        else {
          bVar18 = 1;
        }
LAB_1c0013c15:
        bVar15 = 1;
        if (bVar18 == 0) goto LAB_1c0013082;
      }
LAB_1c0013c20:
      uVar24 = uVar24 | 8;
LAB_1c00131ad:
      *(char *)(param_1 + 0xeae) = (char)uVar13;
      goto LAB_1c0012fa0;
    }
    if (bVar9 == 0x23) {
      if (((short)local_res20 != sVar22) || (bVar25 != 0)) {
        *(undefined1 *)(param_1 + 0xeae) = 0xe;
        *(byte *)(param_1 + 0xeba) = bVar15;
        goto LAB_1c0013c15;
      }
      *(undefined2 *)(param_1 + 0xec4) = *(undefined2 *)(param_1 + 0xecc);
      local_res18[0] = *(uint *)(param_1 + 0xe38);
      uVar13 = *(ulonglong *)(param_1 + 0xe68);
      *(undefined1 *)(param_1 + 0xeae) = 6;
      *(undefined1 *)(param_1 + 0xd62) = 0x90;
LAB_1c0013324:
      cVar10 = '\x01';
LAB_1c001325a:
      SendConfigPageMessage(param_1,cVar10,local_res18,iVar21,(int)uVar13);
LAB_1c00131d1:
      uVar13 = 0;
LAB_1c001307c:
    }
    else {
      if (bVar9 == 0x24) {
        uVar24 = uVar24 & 0xff7f;
        if ((short)local_res20 == sVar22) {
          if (bVar25 == 2) {
            if (*(char *)(param_1 + 0xeb5) == '\x02') {
              if ((*(char *)(param_1 + 0xeb6) != '\x04') || (*(char *)(param_1 + 0xeb7) != '\x01'))
              goto LAB_1c0013b5b;
            }
            else if ((*(char *)(param_1 + 0xeb5) == '\x05') ||
                    (cVar10 = *(char *)(param_1 + 0xeb2), *(char *)(param_1 + 0xeb2) = cVar10 + -1,
                    cVar10 == '\0')) {
LAB_1c0013b5b:
              *(undefined1 *)(param_1 + 0xeae) = 9;
              *(undefined1 *)(param_1 + 0xeb2) = 4;
              goto LAB_1c0012fa0;
            }
            *(undefined1 *)(param_1 + 0xeae) = 8;
            goto LAB_1c0012fa0;
          }
          if (bVar25 == 0) {
            pbVar4 = *(byte **)(param_1 + 0xf30);
            uVar20 = CONCAT11(pbVar4[2],pbVar4[3]);
            if (uVar20 != 0) {
              bVar15 = 1;
              if (0x400 < uVar20) {
                uVar20 = 0x400;
              }
              uVar24 = uVar24 | 0x80;
              *(ushort *)(param_1 + 0xec6) = uVar20;
              *(byte *)(param_1 + 0xeae) = *pbVar4 & 1 | 10;
              goto LAB_1c0013082;
            }
          }
        }
        *(undefined1 *)(param_1 + 0xeb2) = 4;
LAB_1c0013bbc:
        *(undefined1 *)(param_1 + 0xeae) = 0x25;
        bVar9 = 3;
LAB_1c001304f:
        iVar21 = (int)*(undefined8 *)(param_1 + 0xf30);
        uVar20 = 4;
LAB_1c001305c:
        cVar10 = '\x01';
LAB_1c001305f:
        SendReadWriteBuffer(param_1,bVar9,cVar10,iVar21,uVar20);
        goto LAB_1c00131d1;
      }
      if (bVar9 == 0x25) {
        if ((short)local_res20 == sVar22) {
          if (bVar25 == 2) {
            if (*(char *)(param_1 + 0xeb5) == '\x02') {
              if ((*(char *)(param_1 + 0xeb6) != '\x04') || (*(char *)(param_1 + 0xeb7) != '\x01'))
              goto LAB_1c0013a9d;
            }
            else if ((*(char *)(param_1 + 0xeb5) == '\x05') ||
                    (cVar10 = *(char *)(param_1 + 0xeb2), *(char *)(param_1 + 0xeb2) = cVar10 + -1,
                    cVar10 == '\0')) goto LAB_1c0013a9d;
LAB_1c0013456:
            *(undefined1 *)(param_1 + 0xeae) = 9;
            goto LAB_1c0012fa0;
          }
          if (bVar25 == 0) {
            puVar5 = *(undefined4 **)(param_1 + 0xf30);
            uVar16 = (uint)*(byte *)((longlong)puVar5 + 1) * 0x10000 +
                     (uint)*(byte *)((longlong)puVar5 + 2) * 0x100 +
                     (uint)*(byte *)((longlong)puVar5 + 3);
            if (uVar16 != 0) {
              if (0x400 < uVar16) {
                uVar16 = 0x400;
              }
              *(short *)(param_1 + 0xec6) = (short)uVar16;
              *(undefined4 *)(param_1 + 0xed0) = *puVar5;
              if (uVar16 != 0) goto LAB_1c0013aec;
            }
          }
        }
LAB_1c0013a9d:
        uVar24 = uVar24 | 8;
        *(undefined1 *)(param_1 + 0xeae) = 0xd;
        goto LAB_1c0012fa0;
      }
      if (bVar9 == 0x26) {
        if (((short)local_res20 != sVar22) || (bVar25 != 0)) goto LAB_1c0013c20;
        uVar24 = uVar24 | 0x40;
LAB_1c0013a01:
        *(byte *)(param_1 + 0xeb3) = bVar15;
        *(undefined1 *)(param_1 + 0xeaf) = 0xb;
LAB_1c0013a0f:
        FillDvBuffer(param_1,~(*(byte *)(param_1 + 0xed6) >> 4) & 1);
        uVar20 = *(ushort *)(param_1 + 0xec6);
        iVar21 = (int)*(undefined8 *)(param_1 + 0xf30);
        *(undefined1 *)(param_1 + 0xeae) = 0x27;
        bVar9 = (byte)uVar24 >> 4 & 8 | 2;
        cVar10 = '\0';
        goto LAB_1c001305f;
      }
      if (bVar9 == 0x27) {
        if (((short)local_res20 != sVar22) || (bVar25 != 0)) {
          *(undefined1 *)(param_1 + 0xeae) = 0xe;
          if (bVar25 == 2) {
            if (*(char *)(param_1 + 0xeb5) == '\x05') {
              if ((*(char *)(param_1 + 0xeb6) == '$') && ((uVar24 & 0x80) != 0)) goto LAB_1c001344b;
            }
            else if ((*(char *)(param_1 + 0xeb5) == '\x06') && (*(char *)(param_1 + 0xeb2) != '\0'))
            {
              *(undefined1 *)(param_1 + 0xeae) = 0xc;
              *(char *)(param_1 + 0xeb2) = *(char *)(param_1 + 0xeb2) + -1;
            }
          }
          goto LAB_1c0012fa0;
        }
        iVar21 = (int)*(undefined8 *)(param_1 + 0xf38);
        *(undefined2 *)(param_1 + 0xec2) = *(undefined2 *)(param_1 + 0xecc);
        uVar20 = *(ushort *)(param_1 + 0xec6);
        bVar9 = (byte)uVar24 >> 4 & 8 | 2;
        *(undefined1 *)(param_1 + 0xeae) = 0x28;
        goto LAB_1c001305c;
      }
      if (bVar9 != 0x28) goto LAB_1c0013c44;
      bVar15 = 1;
      *(undefined1 *)(param_1 + 0xeae) = 0xe;
      if (((short)local_res20 == sVar22) && (bVar25 == 0)) {
        *(undefined2 *)(param_1 + 0xec4) = *(undefined2 *)(param_1 + 0xecc);
        cVar10 = DataBufCompare(param_1);
        uVar13 = 0;
        if (cVar10 == '\0') {
          if ((uVar24 & 0x80) != 0) {
            *(undefined1 *)(param_1 + 0xeae) = 9;
            uVar24 = uVar24 & 0xff7f;
            *(undefined1 *)(param_1 + 0xeb2) = 4;
            goto LAB_1c0013082;
          }
          if (**(int **)(param_1 + 0xf38) == *(int *)(param_1 + 0xed0)) {
            *(undefined1 *)(param_1 + 0xeae) = 0xd;
          }
        }
        else {
          *(char *)(param_1 + 0xeb3) = *(char *)(param_1 + 0xeb3) + '\x01';
          *(char *)(param_1 + 0xeae) = '\r' - (*(byte *)(param_1 + 0xeb3) < 4);
        }
        goto LAB_1c001307c;
      }
    }
  }
LAB_1c0013082:
  bVar9 = *(byte *)(param_1 + 0xeae);
  if (bVar15 == 0) goto code_r0x0001c0013091;
  goto LAB_1c0012e86;
code_r0x0001c0013091:
  *(ushort *)(param_1 + 0xe78 + (longlong)pbVar11 * 2) = uVar24;
  if ((char)pbVar11 == '\x0f') {
    if ((uVar24 & 2) != 0) goto LAB_1c0013179;
    if (*(char *)(param_1 + 0xebd) == (char)uVar13) {
      pbVar11 = (byte *)0x0;
      *(undefined1 *)(param_1 + 0xebd) = 1;
      if (*(char *)(param_1 + 0xeb9) != '\0') {
        puVar2 = *(uint **)(param_1 + 0xe60);
        *(undefined1 *)(param_1 + 0xd62) = 0x72;
        uVar16 = *puVar2;
        *(char *)(puVar2 + 1) = *(char *)(param_1 + 0xeb9);
        _Dst = *(undefined1 **)(param_1 + 0xd90);
        if (((ulonglong)_Dst & 4) != 0) {
          _Dst = _Dst + 4;
        }
        iVar21 = *(int *)(param_1 + 0x58);
        local_res18[0] = uVar16;
        memset(_Dst,0,0x28);
        *_Dst = 2;
        uVar13 = 0;
        _Dst[3] = 4;
        bVar9 = *(byte *)(param_1 + 0xd62);
        *(undefined4 *)(_Dst + 0x1c) = 0xd1000000;
        *(uint *)(_Dst + 8) = bVar9 | 0x10000000;
        *(uint *)(_Dst + 0x14) = uVar16;
        *(undefined4 *)(_Dst + 0x18) = 0;
        *(int *)(_Dst + 0x20) = (int)puVar2 - *(int *)(param_1 + 0x58);
        *(uint *)(_Dst + 0x1c) = (local_res18[0] >> 8 & 0xff) << 2 | 0xd5000000;
        pbVar11 = *(byte **)(param_1 + 0x38);
        *(int *)pbVar11 = (int)_Dst - iVar21;
        LOCK();
        UNLOCK();
      }
    }
  }
  if (((uVar24 & 2) == 0) && (*(char *)(param_1 + 0xebd) != (char)uVar13)) {
    pbVar11 = (byte *)CheckQASBusStatus(param_1);
  }
LAB_1c0013179:
  if (local_res10 != 0) {
    pbVar11 = (byte *)DvCompleteOrigIo(param_1,10);
    *(undefined1 *)(param_1 + 0xec1) = 0;
  }
  return CONCAT71((int7)((ulonglong)pbVar11 >> 8),1);
}



===== DataBufCompare @ 1c0013c64 =====

undefined1 DataBufCompare(longlong param_1)

{
  char *pcVar1;
  char cVar2;
  ushort uVar3;
  char *pcVar4;
  ushort uVar5;
  longlong lVar6;
  
  uVar3 = *(ushort *)(param_1 + 0xec2);
  pcVar4 = *(char **)(param_1 + 0xf30);
  if (uVar3 != *(ushort *)(param_1 + 0xec4)) {
    return 0;
  }
  uVar5 = 0;
  if (uVar3 != 0) {
    lVar6 = *(longlong *)(param_1 + 0xf38) - (longlong)pcVar4;
    do {
      cVar2 = *pcVar4;
      pcVar1 = pcVar4 + lVar6;
      pcVar4 = pcVar4 + 1;
      if (cVar2 != *pcVar1) {
        return 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar3);
  }
  return 1;
}



===== SendInquiry @ 1c0013cb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SendInquiry(longlong param_1,byte param_2,int param_3)

{
  void *_Dst;
  undefined1 auStack_38 [32];
  undefined4 local_18;
  byte local_14;
  undefined1 local_13;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  _Dst = *(void **)(param_1 + 0xd68);
  local_18 = 0x12;
  local_13 = 0;
  memset(_Dst,0,0x3c);
  local_14 = param_2;
  memcpy((void *)((longlong)_Dst + 0x18),&local_18,6);
  *(undefined4 *)((longlong)_Dst + 0x30) = 0;
  *(undefined1 *)((longlong)_Dst + 4) = 6;
  *(undefined4 *)((longlong)_Dst + 0x14) = 0x2000500;
  SendSCSIMsg(param_1,param_3,(uint)param_2);
  return;
}



===== SendReadWriteBuffer @ 1c0013d5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SendReadWriteBuffer(longlong param_1,undefined1 param_2,char param_3,int param_4,ushort param_5
                        )

{
  void *_Dst;
  undefined1 auStack_58 [32];
  undefined1 local_38;
  undefined1 local_37;
  undefined4 local_36;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  _Dst = *(void **)(param_1 + 0xd68);
  local_38 = 0x3c;
  local_36 = 0;
  local_32 = 0;
  local_2f = 0;
  memset(_Dst,0,0x3c);
  local_30 = (undefined1)param_5;
  local_31 = (undefined1)(param_5 >> 8);
  if (param_3 == '\0') {
    *(undefined4 *)((longlong)_Dst + 0x14) = 0x1000000;
    *(undefined4 *)((longlong)_Dst + 0x30) = 0x4000000;
    local_38 = 0x3b;
  }
  else {
    *(undefined4 *)((longlong)_Dst + 0x30) = 0;
    *(undefined4 *)((longlong)_Dst + 0x14) = 0x2000000;
  }
  local_37 = param_2;
  memcpy((void *)((longlong)_Dst + 0x18),&local_38,10);
  *(uint *)((longlong)_Dst + 0x14) = *(uint *)((longlong)_Dst + 0x14) | 0x500;
  *(undefined1 *)((longlong)_Dst + 4) = 10;
  SendSCSIMsg(param_1,param_4,(uint)param_5);
  return;
}



===== SendReserveRelease @ 1c0013e44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SendReserveRelease(longlong param_1,char param_2)

{
  void *_Dst;
  undefined1 uVar1;
  undefined1 auStack_38 [32];
  undefined4 local_18;
  undefined2 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  _Dst = *(void **)(param_1 + 0xd68);
  local_18 = 0x16;
  local_14 = 0;
  memset(_Dst,0,0x3c);
  uVar1 = (undefined1)local_18;
  if (param_2 == '\0') {
    uVar1 = 0x17;
  }
  local_18 = CONCAT31(local_18._1_3_,uVar1);
  memcpy((void *)((longlong)_Dst + 0x18),&local_18,6);
  *(undefined4 *)((longlong)_Dst + 0x30) = 0;
  *(undefined1 *)((longlong)_Dst + 4) = 6;
  *(undefined4 *)((longlong)_Dst + 0x14) = 0x500;
  SendSCSIMsg(param_1,0,0);
  return;
}



===== SendSCSIMsg @ 1c0013ef0 =====

void SendSCSIMsg(longlong param_1,int param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(param_1 + 0xd68);
  uVar1 = *(ushort *)(param_1 + 0xe78 + (ulonglong)*(byte *)(param_1 + 0xeb0) * 2);
  *pbVar4 = *(byte *)(param_1 + 0xeb0);
  pbVar4[3] = 0;
  *(uint *)(pbVar4 + 8) = *(byte *)(param_1 + 0xeae) | 0x10000000;
  *(uint *)(param_1 + 0xecc) = param_3;
  *(uint *)(pbVar4 + 0x28) = param_3;
  iVar2 = *(int *)(param_1 + 0xf28);
  iVar3 = *(int *)(param_1 + 0x58);
  *(uint *)(pbVar4 + 0x30) = *(uint *)(pbVar4 + 0x30) | 0xd1000000;
  *(int *)(pbVar4 + 0x2c) = iVar2 - iVar3;
  pbVar4[5] = 0x12;
  if (param_3 == 0) {
    *(int *)(pbVar4 + 0x34) = *(int *)(param_1 + 0xd80) + 0x3c;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x58);
    *(uint *)(pbVar4 + 0x30) = *(uint *)(pbVar4 + 0x30) | param_3;
    *(int *)(pbVar4 + 0x34) = param_2 - iVar2;
  }
  if ((uVar1 & 0x20) != 0) {
    pbVar4[3] = 0x16;
    *pbVar4 = *(byte *)(param_1 + 0xeb8);
  }
  **(undefined4 **)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0xd80);
  LOCK();
  UNLOCK();
  if ((uVar1 & 0x100) != 0) {
    *(undefined1 *)(param_1 + 0x681) = 1;
    StorPortNotification(6,param_1,DvScsiTimer,2000000);
  }
  return;
}



===== SyncFallBack @ 1c0013fc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SyncFallBack(longlong param_1)

{
  byte bVar1;
  ulonglong uVar2;
  byte bVar3;
  ushort uVar4;
  byte bVar5;
  byte bStack_19;
  undefined4 local_18;
  undefined2 local_14;
  undefined1 local_12;
  
  uVar2 = __security_cookie ^ (ulonglong)&local_18;
  bVar1 = *(byte *)(param_1 + 0xed5);
  uVar4 = *(ushort *)(param_1 + 0xed6);
  local_18 = 0xc193200;
  local_14 = 0x90a;
  bVar3 = ~((byte)uVar4 >> 4) & 1;
  local_12 = 8;
  if (bVar1 == 0) {
    if (bVar3 == 0) {
      return uVar2 & 0xffffffffffffff00;
    }
LAB_1c001400e:
    uVar4 = uVar4 | 0x10;
  }
  else {
    bVar5 = 6;
    do {
      uVar2 = (ulonglong)bVar5;
      if (*(byte *)((longlong)&local_18 + uVar2) == bVar1) break;
      bVar5 = bVar5 - 1;
    } while (bVar5 != 0);
    if (((9 < bVar1) && (*(char *)(param_1 + 0xeb1) == '\x01')) && (bVar3 != 0)) goto LAB_1c001400e;
    uVar2 = (ulonglong)bVar5;
    *(byte *)(param_1 + 0xed5) = (&bStack_19)[uVar2];
    if (*(char *)(param_1 + 0xebc) == '\0') goto LAB_1c0014068;
    uVar2 = 0xffef;
    uVar4 = uVar4 & 0xffef;
  }
  *(ushort *)(param_1 + 0xed6) = uVar4;
LAB_1c0014068:
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== FillDvBuffer @ 1c001407c =====

void FillDvBuffer(longlong param_1,char param_2)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined1 *puVar7;
  ushort uVar8;
  undefined2 local_res8;
  
  cVar1 = *(char *)(param_1 + 0xeb3);
  puVar7 = *(undefined1 **)(param_1 + 0xf30);
  uVar2 = *(ushort *)(param_1 + 0xec6);
  uVar4 = 0;
  if (cVar1 == '\0') {
    if (uVar2 != 0) {
      do {
        *puVar7 = (char)uVar4;
        uVar4 = uVar4 + 1;
        puVar7 = puVar7 + 1;
      } while (uVar4 < uVar2);
    }
  }
  else {
    if (cVar1 == '\x01') {
      local_res8 = 0;
      uVar6 = 0xffff;
    }
    else {
      if (cVar1 != '\x02') {
        if (cVar1 != '\x03') {
          return;
        }
        uVar3 = 0;
        uVar4 = 1;
        uVar8 = 0;
        if (param_2 != '\0') {
          if (uVar2 >> 1 == 0) {
            return;
          }
          do {
            *(ushort *)(puVar7 + (ulonglong)uVar8 * 2) = uVar3;
            uVar5 = uVar4;
            if (uVar3 == 0) {
              uVar5 = ~uVar4;
            }
            *(ushort *)(puVar7 + (ulonglong)uVar8 * 2 + 2) = uVar5;
            uVar4 = uVar4 * 2;
            if (uVar4 == 0) {
              uVar3 = ~uVar3;
              uVar4 = 1;
            }
            uVar8 = uVar8 + 2;
          } while (uVar8 < uVar2 >> 1);
          return;
        }
        if (uVar2 == 0) {
          return;
        }
        do {
          puVar7[uVar8] = (char)uVar3;
          uVar5 = uVar4;
          if (uVar3 == 0) {
            uVar5 = uVar4 ^ 0xff;
          }
          puVar7[(ulonglong)uVar8 + 1] = (char)uVar5;
          uVar4 = uVar4 * 2;
          if (uVar4 == 0x100) {
            uVar3 = ~uVar3;
            uVar4 = 1;
          }
          uVar8 = uVar8 + 2;
        } while (uVar8 < uVar2);
        return;
      }
      uVar6 = local_res8;
    }
    if (cVar1 == '\x02') {
      local_res8 = 0x5555;
      uVar6 = 0xaaaa;
    }
    if (param_2 == '\0') {
      for (; uVar4 < uVar2; uVar4 = uVar4 + 2) {
        puVar7[uVar4] = (char)local_res8;
        puVar7[(ulonglong)uVar4 + 1] = (char)uVar6;
      }
    }
    else {
      for (; uVar4 < uVar2 >> 1; uVar4 = uVar4 + 2) {
        *(undefined2 *)(puVar7 + (ulonglong)uVar4 * 2) = local_res8;
        *(undefined2 *)(puVar7 + (ulonglong)uVar4 * 2 + 2) = uVar6;
      }
    }
  }
  return;
}



===== DvInterpretError @ 1c00141fc =====

void DvInterpretError(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  undefined2 uVar3;
  ushort uVar4;
  
  bVar1 = *(byte *)(param_2 + 0xd);
  uVar4 = *(ushort *)(param_2 + 0xe) & 0x7fff;
  *(undefined1 *)(param_1 + 0xeb4) = *(undefined1 *)(param_2 + 0xc);
  uVar3 = 0;
  *(undefined4 *)(param_1 + 0xecc) = *(undefined4 *)(param_2 + 0x14);
  if (uVar4 == 0) goto LAB_1c0014271;
  if (uVar4 != 2) {
    if (uVar4 == 0x40) goto LAB_1c0014271;
    if (uVar4 == 0x43) {
      uVar3 = 0x43;
      goto LAB_1c0014271;
    }
    if (uVar4 == 0x45) goto LAB_1c0014271;
    if (uVar4 != 0x49) {
      if (uVar4 - 0x4b < 2) {
        uVar3 = 0x4c;
      }
      else {
        uVar3 = 0x46;
      }
      goto LAB_1c0014271;
    }
  }
  uVar3 = 2;
LAB_1c0014271:
  if ((bVar1 & 0x10) != 0) {
    uVar3 = 0x46;
  }
  if ((bVar1 & 1) != 0) {
    lVar2 = *(longlong *)(param_1 + 0xf28);
    *(undefined1 *)(param_1 + 0xeb5) = *(undefined1 *)(lVar2 + 2);
    *(undefined1 *)(param_1 + 0xeb6) = *(undefined1 *)(lVar2 + 0xc);
    *(undefined1 *)(param_1 + 0xeb7) = *(undefined1 *)(lVar2 + 0xd);
  }
  *(undefined2 *)(param_1 + 0xec8) = uVar3;
  return;
}



===== BuildScsiDevicePage1 @ 1c00142b0 =====

void BuildScsiDevicePage1(longlong param_1,longlong param_2,ushort param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  
  uVar3 = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  bVar4 = *(byte *)(param_1 + 0xed5);
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xe40) + 4);
  if ((*(byte *)(param_1 + 0xed6) & 0x10) == 0) {
    uVar2 = 0;
    if ((uVar1 & 0x20000000) != 0) {
      uVar2 = 0x20000000;
    }
    *(undefined4 *)(param_2 + 4) = uVar2;
  }
  if (bVar4 != 0) {
    bVar5 = (byte)(uVar1 >> 8);
    if (bVar4 < bVar5) {
      bVar4 = bVar5;
    }
  }
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | (uint)bVar4 << 8;
  if (bVar4 == 9) {
    uVar3 = 2;
    if ((((*(ushort *)(param_1 + 0x134) & 8) != 0) && ((param_3 & 0x200) == 0)) &&
       (uVar3 = 3, (*(ushort *)(param_1 + 0x134) & 0x10) != 0)) {
      uVar3 = 7;
    }
  }
  else if (bVar4 == 8) {
    uVar3 = 3;
    if ((*(byte *)(param_1 + 0x134) & 0x20) == 0) {
      uVar3 = 7;
    }
    if ((param_3 & 0x400) != 0) {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 0x8000000;
    }
  }
  *(uint *)(param_2 + 4) =
       *(uint *)(param_2 + 4) | (uVar1 >> 0x10 & 0xff) * 0x10000 + (uVar3 & uVar1);
  return;
}



===== CheckPhysDisk @ 1c00143b4 =====

undefined8 CheckPhysDisk(longlong param_1,char param_2)

{
  byte bVar1;
  longlong lVar2;
  byte bVar3;
  char *pcVar4;
  
  bVar3 = 0;
  lVar2 = *(longlong *)(param_1 + 0xe58);
  if ((lVar2 != 0) && (bVar1 = *(byte *)(lVar2 + 4), bVar1 != 0)) {
    pcVar4 = (char *)(lVar2 + 8);
    if (bVar1 != 0) {
      do {
        if ((*pcVar4 == param_2) && (pcVar4[2] == *(char *)(param_1 + 0xe2a))) {
          *(char *)(param_1 + 0xeb8) = pcVar4[3];
          return 1;
        }
        pcVar4 = pcVar4 + 4;
        bVar3 = bVar3 + 1;
      } while (bVar3 < bVar1);
    }
  }
  return 0;
}



===== CheckForSEPDevice @ 1c0014404 =====

void CheckForSEPDevice(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  byte bVar5;
  byte *pbVar6;
  uint local_res8;
  
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0xe50) + 4);
  bVar5 = **(byte **)(param_1 + 0xf30) & 0x1f;
  if (bVar5 == 0xd) {
    bVar4 = false;
    if ((uVar2 >> 0x1d & 1) != 0) {
      bVar4 = true;
    }
  }
  else {
    if (bVar5 != 3) {
      return;
    }
    pbVar6 = *(byte **)(param_1 + 0xf30) + 0x2c;
    bVar5 = 0;
    do {
      bVar1 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      if (bVar1 != (&SafteStr)[bVar5]) break;
      bVar5 = bVar5 + 1;
    } while (bVar5 < 6);
    if (bVar5 != 6) {
      return;
    }
    bVar4 = false;
    if ((uVar2 & 0x40000000) != 0) {
      bVar4 = true;
    }
  }
  local_res8._0_2_ = (ushort)(byte)*(undefined4 *)(param_1 + 0xed4);
  local_res8 = CONCAT22((short)((uint)*(undefined4 *)(param_1 + 0xed4) >> 0x10),(ushort)local_res8)
               | 0x100000;
  *(uint *)(param_1 + 0xed4) = local_res8;
  if (((*(char *)(param_1 + 0xebd) == '\0') && (*(char *)(param_1 + 0xebe) == '\0')) &&
     (*(undefined1 *)(param_1 + 0xebe) = 1, bVar4)) {
    bVar5 = *(byte *)(param_1 + 0xeb9);
    lVar3 = *(longlong *)(param_1 + 0xe60);
    *(byte *)(param_1 + 0xeb9) = bVar5 + 1;
    if (bVar5 < *(byte *)(lVar3 + 5)) {
      *(undefined1 *)(lVar3 + 9 + (ulonglong)bVar5 * 4) = 0;
      *(undefined1 *)(lVar3 + 8 + (ulonglong)bVar5 * 4) = *(undefined1 *)(param_1 + 0xeb0);
    }
  }
  return;
}



===== DvScsiTimer @ 1c0014500 =====

void DvScsiTimer(longlong param_1)

{
  undefined4 local_res8 [8];
  
  local_res8[0] = 0;
  if (*(char *)(param_1 + 0xec0) == '\0') {
    *(undefined1 *)(param_1 + 0xeae) = 0xe;
    *(undefined1 *)(param_1 + 0xec0) = 1;
    StorPortSynchronizeAccess(param_1,SynchronizeReset,local_res8);
  }
  else {
    *(undefined1 *)(param_1 + 0xec0) = 0;
    DomainValidation(param_1);
  }
  *(undefined1 *)(param_1 + 0x681) = 0;
  StorPortNotification(6,param_1,WatchdogTimer,1000000);
  return;
}



===== CheckQASBusStatus @ 1c0014570 =====

void CheckQASBusStatus(longlong param_1)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  byte *pbVar6;
  void *pvVar7;
  ushort *puVar8;
  void *pvVar9;
  longlong lVar10;
  uint uVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  byte bVar14;
  uint local_res20 [2];
  
  local_res20[0] = *(uint *)(param_1 + 0xe3c);
  if (*(longlong *)(param_1 + 0xe70) != 0) {
    pbVar13 = (byte *)(param_1 + 0xe9c);
    uVar11 = (local_res20[0] >> 8 & 0xff) << 2;
    lVar10 = 0x10;
    bVar5 = false;
    bVar4 = false;
    bVar3 = false;
    bVar2 = false;
    pbVar6 = pbVar13;
    do {
      bVar14 = *pbVar6;
      if ((bVar14 & 1) != 0) {
        bVar2 = bVar3;
        if ((bVar14 & 4) != 0) {
          bVar2 = true;
        }
        if ((bVar14 & 6) == 2) {
          bVar4 = true;
        }
        bVar3 = bVar2;
        if ((bVar14 & 2) == 0) {
          bVar5 = true;
        }
      }
      pbVar6 = pbVar6 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    *(undefined1 *)(param_1 + 0xd62) = 0xf0;
    if ((bVar2) && (bVar5)) {
      puVar12 = (undefined4 *)(param_1 + 0xed8);
      puVar8 = (ushort *)(param_1 + 0xe78);
      bVar14 = 0;
      do {
        if ((*pbVar13 & 5) == 5) {
          *pbVar13 = *pbVar13 & 0xfb;
          *(undefined4 *)(param_1 + 0xed4) = *puVar12;
          uVar1 = *puVar8;
          pvVar9 = (void *)(*(longlong *)(param_1 + 0xe30) + 0x30 +
                           (longlong)(int)((uint)bVar14 << 6));
          memcpy(pvVar9,*(void **)(param_1 + 0xe70),(ulonglong)uVar11);
          pvVar7 = pvVar9;
          BuildScsiDevicePage1(param_1,(longlong)pvVar9,uVar1);
          *(uint *)((longlong)pvVar9 + 4) = *(uint *)((longlong)pvVar9 + 4) & 0xfffffffb;
          SendQASPoolMessage(param_1,pvVar7,local_res20,(uint)bVar14,(int)pvVar9);
        }
        bVar14 = bVar14 + 1;
        puVar12 = puVar12 + 1;
        puVar8 = puVar8 + 1;
        pbVar13 = pbVar13 + 1;
      } while (bVar14 < 0x10);
    }
    pbVar13 = (byte *)(param_1 + 0xe9c);
    bVar14 = 0;
    if ((bVar4) && (!bVar5)) {
      puVar8 = (ushort *)(param_1 + 0xe78);
      puVar12 = (undefined4 *)(param_1 + 0xed8);
      do {
        if ((*pbVar13 & 5) == 1) {
          *pbVar13 = *pbVar13 | 4;
          *(undefined4 *)(param_1 + 0xed4) = *puVar12;
          uVar1 = *puVar8;
          pvVar9 = (void *)(*(longlong *)(param_1 + 0xe30) + 0x30 +
                           (longlong)(int)((uint)bVar14 << 6));
          memcpy(pvVar9,*(void **)(param_1 + 0xe70),(ulonglong)uVar11);
          pvVar7 = pvVar9;
          BuildScsiDevicePage1(param_1,(longlong)pvVar9,uVar1);
          SendQASPoolMessage(param_1,pvVar7,local_res20,(uint)bVar14,(int)pvVar9);
        }
        bVar14 = bVar14 + 1;
        puVar12 = puVar12 + 1;
        puVar8 = puVar8 + 1;
        pbVar13 = pbVar13 + 1;
      } while (bVar14 < 0x10);
    }
  }
  return;
}



===== DvCompleteOrigIo @ 1c00147d4 =====

void DvCompleteOrigIo(longlong param_1,undefined1 param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0xf20);
  if (((lVar2 != 0) && (*(char *)(param_1 + 0xec1) != '\0')) && (*(longlong *)(lVar2 + 0x38) != 0))
  {
    lVar1 = *(longlong *)(param_1 + 0x148) +
            (ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x38) + 0x140) * 0x18;
    *(undefined8 *)(lVar1 + 8) = 0;
    **(longlong **)(param_1 + 0x160) = lVar1;
    *(longlong *)(param_1 + 0x160) = *(longlong *)(param_1 + 0x160) + 8;
    if (*(longlong *)(param_1 + 0x160) == *(longlong *)(param_1 + 0x168)) {
      *(undefined8 *)(param_1 + 0x160) = *(undefined8 *)(param_1 + 0x150);
    }
    *(undefined1 *)(lVar2 + 3) = param_2;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0xf20) = 0;
  }
  return;
}



===== LSImpiWmiSrb @ 1c0014868 =====

undefined8 LSImpiWmiSrb(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined4 uVar2;
  longlong lVar3;
  uint *puVar4;
  longlong *plVar5;
  char cVar6;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 uVar7;
  uint uVar8;
  uint local_res10 [2];
  int local_res18 [2];
  
  lVar3 = *(longlong *)(param_2 + 0x38);
  if ((*(byte *)(param_2 + 9) & 1) == 0) {
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
    *(longlong *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x28) = 0;
    puVar4 = *(uint **)(param_2 + 0x18);
    uVar8 = *(uint *)(param_2 + 0x10);
    plVar5 = *(longlong **)(param_2 + 0x20);
    bVar1 = *(byte *)(param_2 + 4);
    local_res10[0] = 0;
    *(undefined4 *)(lVar3 + 0x24) = 0;
    if (bVar1 < 10) {
      *(uint *)(lVar3 + 0x10) = uVar8;
      *(byte *)(lVar3 + 0x20) = bVar1;
      *(uint **)(lVar3 + 0x18) = puVar4;
      cVar6 = ScsiWmipProcessRequest
                        ((uint *)(param_1 + 0x88),bVar1,param_1,lVar3 + 8,plVar5,uVar8,puVar4,
                         local_res10,local_res18);
      if (local_res18[0] == 1) {
        *(char *)(lVar3 + 0x21) = cVar6;
        uVar8 = local_res10[0];
        if (cVar6 != '\x01') {
          uVar8 = 0;
        }
        *(uint *)(lVar3 + 0x24) = uVar8;
      }
      uVar7 = extraout_var;
      if (cVar6 == '\0') goto LAB_1c001493d;
    }
    else {
      *(undefined1 *)(lVar3 + 0x21) = 4;
    }
    uVar2 = *(undefined4 *)(lVar3 + 0x24);
    *(undefined1 *)(param_2 + 3) = *(undefined1 *)(lVar3 + 0x21);
    *(undefined4 *)(param_2 + 0x10) = uVar2;
  }
  StorPortNotification(0,param_1,param_2);
  uVar7 = extraout_var_00;
LAB_1c001493d:
  return CONCAT71(uVar7,1);
}



===== LSImpiQueryWmiDataBlock @ 1c0014960 =====

char LSImpiQueryWmiDataBlock
               (longlong param_1,longlong *param_2,int param_3,undefined8 param_4,undefined8 param_5
               ,undefined4 *param_6,uint param_7,undefined8 *param_8)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  
  uVar5 = 0;
  lVar1 = *param_2;
  cVar4 = '\x01';
  *(undefined4 *)(*(longlong *)(lVar1 + 0x38) + 0x34) = 0;
  if (param_3 == 0) {
LAB_1c00149bc:
    uVar5 = 4;
    uVar2 = 4;
    if (3 < param_7) {
      *param_6 = 4;
      goto LAB_1c00149d2;
    }
  }
  else {
    if (param_3 != 1) {
      if (param_3 != 2) {
        cVar4 = '\x04';
        goto LAB_1c00149d2;
      }
      goto LAB_1c00149bc;
    }
    uVar5 = 0x1730;
    uVar2 = 0x1730;
    if (0x172f < param_7) {
      *param_6 = 0x1730;
      bVar3 = LSIWmiGetAdapHbaAttributes(param_1,param_8,lVar1);
      if (bVar3) {
        return '\0';
      }
      goto LAB_1c00149d2;
    }
  }
  uVar5 = uVar2;
  cVar4 = '\x12';
LAB_1c00149d2:
  ScsiPortWmiPostProcess((longlong)param_2,cVar4,uVar5);
  return cVar4;
}



===== LSImpiQueryWmiRegInfo @ 1c0014a00 =====

undefined8 LSImpiQueryWmiRegInfo(longlong param_1,undefined8 param_2,ulonglong *param_3)

{
  ulonglong uVar1;
  
  uVar1 = -(ulonglong)((*(ushort *)(param_1 + 0x134) & 0x200) != 0) & 0x1c00167a0;
  *param_3 = uVar1;
  return CONCAT71((int7)(uVar1 >> 8),1);
}



===== LSImpiExecuteWmiMethod @ 1c0014a30 =====

char LSImpiExecuteWmiMethod
               (longlong param_1,longlong *param_2,int param_3,undefined8 param_4,int param_5,
               uint param_6,uint param_7,int *param_8)

{
  longlong lVar1;
  char cVar2;
  undefined8 uVar3;
  char cVar4;
  uint uVar5;
  bool bVar6;
  
  lVar1 = *param_2;
  cVar4 = '\x01';
  *(int *)(*(longlong *)(lVar1 + 0x38) + 0x34) = param_5;
  uVar5 = 0;
  if (param_3 != 2) {
    cVar4 = '\x04';
    goto LAB_1c0014a5e;
  }
  if (param_5 == 1) {
    uVar5 = 8;
    bVar6 = param_7 < 8;
LAB_1c0014ad8:
    if (bVar6) {
LAB_1c0014ada:
      cVar4 = '\x12';
      goto LAB_1c0014a5e;
    }
    uVar3 = LsiWmiGetSASPortInfo(param_1,param_8,lVar1);
    cVar2 = (char)uVar3;
  }
  else {
    if (param_5 == 2) {
      bVar6 = param_7 < 0x23c;
      uVar5 = 0x23c;
      goto LAB_1c0014ad8;
    }
    if (param_5 != 4) {
      if (param_5 != 10) {
        *param_8 = 2;
        uVar5 = param_6;
      }
      goto LAB_1c0014a5e;
    }
    uVar5 = 0x23c;
    if (param_7 < 0x23c) goto LAB_1c0014ada;
    uVar3 = LsiWmiGetSASPortInfoByWWN(param_1,param_8,lVar1);
    cVar2 = (char)uVar3;
  }
  if (cVar2 != '\0') {
    return '\0';
  }
LAB_1c0014a5e:
  ScsiPortWmiPostProcess((longlong)param_2,cVar4,uVar5);
  return cVar4;
}



===== LSImpiFunctionControl @ 1c0014b00 =====

undefined1
LSImpiFunctionControl(longlong param_1,longlong param_2,int param_3,int param_4,char param_5)

{
  if ((param_4 == 0) && (param_3 == 0)) {
    *(bool *)(param_1 + 0xe29) = param_5 != '\0';
  }
  ScsiPortWmiPostProcess(param_2,'\x01',0);
  return 1;
}



===== LSIWmiGetAdapHbaAttributes @ 1c0014b34 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool LSIWmiGetAdapHbaAttributes(longlong param_1,undefined8 *param_2,longlong param_3)

{
  char cVar1;
  short sVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  char *pcVar6;
  byte bVar7;
  byte bVar8;
  ulonglong uVar9;
  undefined1 uVar10;
  undefined1 auStackY_e8 [32];
  char local_b8 [16];
  char local_a8 [16];
  char local_98 [4];
  undefined1 local_94 [76];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  lVar3 = *(longlong *)(param_1 + 0xdc0);
  uVar5 = *(undefined8 *)(param_1 + 0xde8);
  lVar4 = *(longlong *)(param_3 + 0x38);
  VersionToStr(*(uint *)(param_1 + 0x300),local_a8);
  VersionToStr(*(uint *)(param_1 + 0x2fc),local_b8);
  *(undefined4 *)(param_2 + 1) = 0;
  *param_2 = uVar5;
  *(int *)(param_2 + 2) = *(int *)(param_1 + 0x2e8) * 0x10000 + *(int *)(param_1 + 0x2f4);
  *(uint *)((longlong)param_2 + 0xc) = (uint)*(ushort *)(param_1 + 0x1dc);
  AsciiToUnicode("LSI Corporation",(ushort *)((longlong)param_2 + 0x14),0x82);
  AsciiToUnicode((char *)(lVar3 + 0x3c),(ushort *)((longlong)param_2 + 0x96),0x82);
  AsciiToUnicode((char *)(lVar3 + 0x1c),(ushort *)(param_2 + 0x23),0x202);
  uVar9 = 0x10;
  do {
    bVar7 = (byte)uVar9;
    sVar2 = *(short *)((longlong)param_2 + uVar9 * 2 + 0x118);
    if (sVar2 == 0x20) {
      *(undefined2 *)((longlong)param_2 + uVar9 * 2 + 0x118) = 0;
    }
    else if (sVar2 != 0) break;
    bVar8 = bVar7 - 1;
    uVar9 = (ulonglong)bVar8;
    bVar7 = 0;
  } while (bVar8 != 0);
  if ((*(uint *)(param_1 + 0x2e8) == 0x54) && (*(int *)(param_1 + 0x2f4) == 0x1028)) {
    bVar8 = 0;
    do {
      if ((uint)(ushort)(&DellSubSys)[bVar8] == *(uint *)(param_1 + 0x2f0)) {
        pcVar6 = *(char **)(&DellDesc + (ulonglong)bVar8 * 8);
        if (pcVar6 != (char *)0x0) goto LAB_1c0014cd8;
        break;
      }
      bVar8 = bVar8 + 1;
    } while (bVar8 < 5);
    pcVar6 = DellNoDesc;
  }
  else {
    bVar8 = 0;
    do {
      if ((uint)(ushort)(&ChipIds)[bVar8] == *(uint *)(param_1 + 0x2e8)) {
        pcVar6 = (&BoardDesc)[bVar8];
        if (pcVar6 != (char *)0x0) goto LAB_1c0014cd8;
        break;
      }
      bVar8 = bVar8 + 1;
    } while (bVar8 < 5);
    pcVar6 = NoDesc;
  }
LAB_1c0014cd8:
  AsciiToUnicode(pcVar6,(ushort *)((longlong)param_2 + 0x31a),0x202);
  memcpy(local_98,&s_LSI_,4);
  memcpy(local_94,(void *)(lVar3 + 0x1c),(ulonglong)bVar7);
  memcpy(local_98 + (byte)(bVar7 + 4),&s__FV,3);
  memcpy(local_98 + (byte)(bVar7 + 7),local_b8,0xb);
  memcpy(local_98 + (byte)(bVar7 + 0x12),&s__DV,3);
  bVar8 = 0;
  do {
    cVar1 = (&DAT_1c0018030)[bVar8];
    local_98[(ulonglong)bVar8 + (ulonglong)(byte)(bVar7 + 0x15)] = cVar1;
    if (cVar1 == '\0') break;
    bVar8 = bVar8 + 1;
  } while (bVar8 < 0x50);
  AsciiToUnicode(local_98,(ushort *)((longlong)param_2 + 0xf26),0x202);
  AsciiToUnicode((char *)(lVar3 + 0x14),(ushort *)((longlong)param_2 + 0x51c),0x202);
  AsciiToUnicode(&DAT_1c0018030,(ushort *)((longlong)param_2 + 0x71e),0x202);
  AsciiToUnicode(local_a8,(ushort *)(param_2 + 0x124),0x202);
  AsciiToUnicode(local_b8,(ushort *)((longlong)param_2 + 0xb22),0x202);
  AsciiToUnicode("lsi_sas",(ushort *)((longlong)param_2 + 0xd24),0x202);
  AsciiToUnicode("",(ushort *)(param_2 + 0x225),0x202);
  AsciiToUnicode("",(ushort *)((longlong)param_2 + 0x132a),0x202);
  uVar10 = 2;
  AsciiToUnicode(MfgDomain,(ushort *)((longlong)param_2 + 0x152c),0x202);
  *(ushort *)((longlong)param_2 + 0x152c) = 0x10;
  *(undefined1 *)(lVar4 + 0x30) = 8;
  *(undefined8 **)(lVar4 + 8) = param_2;
  uVar5 = SendHbaApiConfigMessage
                    (param_1,param_3,uVar10,(undefined4 *)(param_1 + 0x1266),0,
                     (int)*(undefined8 *)(param_1 + 0x12b0));
  return (char)uVar5 != '\0';
}



===== AsciiToUnicode @ 1c0014ebc =====

void AsciiToUnicode(char *param_1,ushort *param_2,ushort param_3)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_3 != 0) {
    memset(param_2,0,(ulonglong)param_3);
  }
  *param_2 = param_3 - 2;
  if (*param_1 != '\0') {
    uVar1 = 0;
    do {
      if ((ushort)(param_3 - 2) >> 1 <= uVar1) {
        return;
      }
      uVar2 = uVar1 + 1;
      param_2[(ulonglong)uVar1 + 1] = (ushort)(byte)param_1[uVar1];
      uVar1 = uVar2;
    } while (param_1[uVar2] != '\0');
  }
  return;
}



===== VersionToStr @ 1c0014f34 =====

void VersionToStr(uint param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  
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
  if ((byte)param_1 < 10) {
    cVar1 = '0';
  }
  else {
    cVar1 = (char)((param_1 & 0xff) / 10) + '0';
  }
  param_2[9] = cVar1;
  param_2[10] = (byte)param_1 + (char)((param_1 & 0xff) / 10) * -10 + '0';
  param_2[0xb] = '\0';
  return;
}



===== SendHbaApiConfigMessage @ 1c0015094 =====

undefined8
SendHbaApiConfigMessage
          (longlong param_1,longlong param_2,undefined1 param_3,undefined4 *param_4,
          undefined4 param_5,int param_6)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined1 *_Dst;
  undefined1 local_res18 [16];
  
  lVar2 = *(longlong *)(param_2 + 0x38);
  puVar6 = *(undefined8 **)(lVar2 + 0x28);
  if (puVar6 == (undefined8 *)0x0) {
    puVar3 = *(undefined8 **)(param_1 + 0x158);
    puVar6 = (undefined8 *)*puVar3;
    if (puVar6[1] != 0) {
      return (ulonglong)puVar3 & 0xffffffffffffff00;
    }
    *(undefined8 **)(param_1 + 0x158) = puVar3 + 1;
    if (puVar3 + 1 == *(undefined8 **)(param_1 + 0x168)) {
      *(undefined8 *)(param_1 + 0x158) = *(undefined8 *)(param_1 + 0x150);
    }
  }
  puVar6[1] = param_2;
  _Dst = (undefined1 *)(lVar2 + 0x138);
  *puVar6 = _Dst;
  local_res18[0] = param_3;
  memset(_Dst,0,0x28);
  *_Dst = 1;
  *(undefined1 *)(lVar2 + 0x13b) = 4;
  *(uint *)(lVar2 + 0x140) = *(uint *)(puVar6 + 2) | 0x1000000;
  *(undefined4 *)(lVar2 + 0x14c) = *param_4;
  uVar4 = (uint)*(byte *)((longlong)param_4 + 1);
  *(undefined4 *)(lVar2 + 0x150) = param_5;
  if ((*(byte *)(lVar2 + 0x14f) & 0xf) == 0xf) {
    uVar1 = *(ushort *)(param_4 + 1);
    *(ushort *)(lVar2 + 0x13c) = uVar1;
    uVar4 = (uint)uVar1;
    *(undefined1 *)(lVar2 + 0x13e) = *(undefined1 *)((longlong)param_4 + 6);
  }
  uVar5 = StorPortGetPhysicalAddress(param_1,param_2,_Dst,local_res18);
  *(undefined4 *)(lVar2 + 0x154) = 0xd1000000;
  *(int *)(lVar2 + 0x158) = param_6 - *(int *)(param_1 + 0x58);
  *(uint *)(lVar2 + 0x154) = uVar4 << 2 | 0xd1000000;
  **(undefined4 **)(param_1 + 0x38) = (int)uVar5;
  LOCK();
  UNLOCK();
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



===== LsiWmiGetSASPortInfo @ 1c00151a8 =====

ulonglong LsiWmiGetSASPortInfo(longlong param_1,undefined4 *param_2,longlong param_3)

{
  ulonglong uVar1;
  
  uVar1 = *(ulonglong *)(param_3 + 0x38);
  if ((*(int *)(uVar1 + 0x34) == 2) && ((uint)param_2[1] < 0x1c)) {
    *param_2 = 4;
  }
  else {
    *(undefined4 **)(uVar1 + 8) = param_2;
    *(undefined1 *)(uVar1 + 0x30) = 8;
    uVar1 = SendHbaApiConfigMessage
                      (param_1,param_3,(char)param_3,(undefined4 *)(param_1 + 0x1266),0,
                       (int)*(undefined8 *)(param_1 + 0x12b0));
    if ((char)uVar1 != '\0') {
      return CONCAT71((int7)(uVar1 >> 8),1);
    }
    *param_2 = 10;
  }
  return uVar1 & 0xffffffffffffff00;
}



===== LsiWmiGetSASPortInfoByWWN @ 1c0015208 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong LsiWmiGetSASPortInfoByWWN(longlong param_1,int *param_2,longlong param_3)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  undefined1 uVar7;
  char cVar8;
  undefined1 auStackY_68 [32];
  char local_38 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_68;
  lVar2 = *(longlong *)(param_3 + 0x38);
  if ((uint)param_2[4] < 0x1c) {
    *param_2 = 4;
  }
  else {
    uVar7 = 8;
    memcpy(local_38,param_2,8);
    local_38[7] = local_38[7] & 0xf0;
    iVar6 = 0;
    bVar5 = 0;
    do {
      if (local_38[7 - (ulonglong)bVar5] != *(char *)((ulonglong)bVar5 + 0xde8 + param_1)) break;
      bVar5 = bVar5 + 1;
    } while (bVar5 < 8);
    if ((bVar5 == 8) && (*(char *)(*(longlong *)(param_1 + 0x12b0) + 0xc) != '\0')) {
      bVar5 = *(byte *)((longlong)param_2 + 7) & 0xf;
      if (bVar5 != 0) {
        cVar8 = '\0';
        bVar4 = 0;
        do {
          cVar1 = *(char *)(*(longlong *)(param_1 + 0x12b0) + ((ulonglong)bVar4 + 1) * 0x10);
          if (cVar1 != cVar8) {
            iVar6 = iVar6 + 1;
            cVar8 = cVar1;
          }
          bVar4 = bVar4 + 1;
        } while (bVar4 <= bVar5);
      }
      param_2[1] = param_2[4];
      *param_2 = iVar6;
      *(undefined4 *)(lVar2 + 0x34) = 2;
      uVar3 = LsiWmiGetSASPortInfo(param_1,param_2,param_3);
      return uVar3;
    }
    *(undefined1 *)(lVar2 + 0x30) = 0xb;
    *(int **)(lVar2 + 8) = param_2;
    local_30 = SendHbaApiConfigMessage
                         (param_1,param_3,uVar7,(undefined4 *)(param_1 + 0x1286),0xffff,
                          (int)*(undefined8 *)(param_1 + 0x12d0));
    if ((char)local_30 != '\0') {
      return CONCAT71((int7)(local_30 >> 8),1);
    }
    *param_2 = 10;
  }
  return local_30 & 0xffffffffffffff00;
}



===== ProcessSASPortInfo @ 1c0015330 =====

void ProcessSASPortInfo(longlong param_1,int *param_2,longlong param_3)

{
  short sVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  ulonglong uVar10;
  
  pbVar9 = *(byte **)(param_1 + 0x12b0);
  bVar3 = 0;
  uVar7 = 0;
  bVar6 = pbVar9[0xc];
  sVar1 = *(short *)(*(longlong *)(param_3 + 0x38) + 0x32);
  if (*(int *)(*(longlong *)(param_3 + 0x38) + 0x34) == 1) {
    if (sVar1 == 0) {
      pbVar2 = pbVar9 + 0x10;
      iVar8 = 0;
      bVar3 = *pbVar2;
      uVar10 = 0;
      bVar5 = 0;
      if (bVar6 != 0) {
        do {
          bVar5 = (byte)uVar10;
          pbVar2 = pbVar9 + (uVar10 + 1) * 0x10;
          if (*pbVar2 != bVar3) {
            iVar8 = iVar8 + 1;
            bVar3 = *pbVar2;
          }
          if (*param_2 == iVar8) break;
          bVar5 = bVar5 + 1;
          uVar10 = (ulonglong)bVar5;
        } while (bVar5 < bVar6);
      }
      if (bVar5 == bVar6) {
        *param_2 = 6;
      }
      else {
        *param_2 = 0;
        uVar7 = *(uint *)(pbVar2 + 4);
        bVar6 = (byte)uVar7 & 7;
        iVar8 = 3;
        if (bVar6 == 1) {
          if ((uVar7 & 0x660) == 0) {
            if ((uVar7 & 0x88) != 0) {
              iVar8 = 0x1f;
            }
          }
          else {
            iVar8 = 0x1e;
          }
        }
        else if (((byte)(bVar6 - 2) < 2) && (iVar8 = 3, (uVar7 & 0x110) != 0)) {
          iVar8 = 0x20;
        }
        param_2[1] = iVar8;
      }
    }
    else {
      *param_2 = 1;
    }
  }
  else if (sVar1 == 0) {
    if (bVar6 != 0) {
      uVar10 = (ulonglong)bVar6;
      do {
        pbVar9 = pbVar9 + 0x10;
        uVar7 = uVar7 & 0xff | 1 << (*pbVar9 & 0x1f);
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    uVar4 = 0;
    do {
      if (((uVar7 & 0xff) >> (uVar4 & 0x1f) & 1) != 0) {
        bVar3 = bVar3 + 1;
      }
      bVar6 = (char)uVar4 + 1;
      uVar4 = (uint)bVar6;
    } while (bVar6 < 8);
    param_2[3] = (uint)bVar3;
  }
  return;
}



===== ProcessSASPortAttributes @ 1c0015470 =====

undefined8 ProcessSASPortAttributes(longlong param_1,uint *param_2,longlong param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  uint *puVar6;
  char *pcVar7;
  longlong lVar8;
  char cVar9;
  byte bVar10;
  undefined1 *puVar11;
  uint uVar12;
  byte local_res18;
  longlong lVar13;
  
  lVar13 = *(longlong *)(param_3 + 0x38);
  lVar8 = 8;
  bVar10 = *(byte *)(lVar13 + 0x30);
  uVar2 = *(ushort *)(lVar13 + 0x32);
  uVar4 = (ulonglong)uVar2;
  if (bVar10 == 8) {
    lVar8 = *(longlong *)(param_1 + 0x12b0);
    if (uVar2 == 0) {
      pcVar7 = (char *)(lVar8 + 0x10);
      uVar12 = 0;
      cVar9 = *pcVar7;
      puVar11 = (undefined1 *)0x0;
      bVar10 = 0;
      if (*(byte *)(lVar8 + 0xc) != 0) {
        uVar5 = (uint)local_res18;
        do {
          if (*pcVar7 != cVar9) {
            uVar12 = uVar12 + 1;
            cVar9 = *pcVar7;
          }
          if (*param_2 == uVar12) {
            if ((int)puVar11 == 0) {
              uVar5 = (uint)bVar10;
            }
            puVar11 = (undefined1 *)(ulonglong)((int)puVar11 + 1);
          }
          uVar4 = 0;
          bVar10 = bVar10 + 1;
          pcVar7 = pcVar7 + 0x10;
        } while (bVar10 < *(byte *)(lVar8 + 0xc));
        if ((int)puVar11 != 0) {
          lVar8 = ((ulonglong)uVar5 + 1) * 0x10 + lVar8;
          uVar12 = 2;
          if (*(char *)(lVar8 + 3) == '\x01') {
            uVar12 = 6;
          }
          param_2[3] = uVar12;
          FillInPortInfo(param_2 + 2,*(uint *)(lVar8 + 4),(int)puVar11);
          *param_2 = (uint)*(ushort *)(lVar8 + 8);
          uVar5 = uVar5 + 0x20000001;
          *(undefined1 *)(lVar13 + 0x30) = 9;
LAB_1c00155bd:
          bVar10 = (byte)puVar11;
          lVar13 = *(longlong *)(param_1 + 0x12d0);
LAB_1c0015520:
          uVar4 = SendHbaApiConfigMessage
                            (param_1,param_3,bVar10,(undefined4 *)(param_1 + 0x1286),uVar5,
                             (int)lVar13);
          if ((char)uVar4 != '\0') {
            return uVar4 & 0xffffffffffffff00;
          }
          *param_2 = 10;
          goto LAB_1c00156da;
        }
      }
      *param_2 = 6;
      goto LAB_1c00156da;
    }
  }
  else if (8 < bVar10) {
    if (bVar10 < 0xb) {
      lVar3 = *(longlong *)(param_1 + 0x12d0);
      if (bVar10 == 9) {
        if (uVar2 == 0) {
          puVar6 = param_2 + 0x89;
          puVar11 = (undefined1 *)(lVar3 + 0x13);
          do {
            uVar1 = *puVar11;
            puVar11 = puVar11 + -1;
            *(undefined1 *)puVar6 = uVar1;
            puVar6 = (uint *)((longlong)puVar6 + 1);
            lVar8 = lVar8 + -1;
          } while (lVar8 != 0);
          *(undefined1 *)(lVar13 + 0x30) = 10;
          uVar5 = *param_2 + 0x20000000;
          goto LAB_1c00155bd;
        }
      }
      else {
        *param_2 = 0;
        if (uVar2 == 0x22) {
          param_2[0x8b] = 0;
          param_2[0x8c] = 0;
          param_2[0x8d] = 0;
          goto LAB_1c00156da;
        }
        if (uVar2 == 0) {
          puVar6 = param_2 + 0x8b;
          puVar11 = (undefined1 *)(lVar3 + 0x13);
          do {
            uVar1 = *puVar11;
            uVar4 = 0;
            puVar11 = puVar11 + -1;
            *(undefined1 *)puVar6 = uVar1;
            puVar6 = (uint *)((longlong)puVar6 + 1);
            lVar8 = lVar8 + -1;
          } while (lVar8 != 0);
          param_2[0x8d] = 1;
          goto LAB_1c00156da;
        }
      }
    }
    else if (bVar10 == 0xb) {
      lVar13 = *(longlong *)(param_1 + 0x12d0);
      if (uVar2 == 0x22) {
        *param_2 = 5;
        goto LAB_1c00156da;
      }
      if (uVar2 == 0) {
        uVar4 = 0;
        do {
          bVar10 = (byte)uVar4;
          if (*(char *)((lVar13 - uVar4) + 0x13) != *(char *)(uVar4 + (longlong)param_2)) break;
          bVar10 = bVar10 + 1;
          uVar4 = (ulonglong)bVar10;
        } while (bVar10 < 8);
        if (7 < bVar10) {
          memcpy(param_2 + 0x89,param_2,8);
          uVar4 = FillInPortInfo(param_2 + 2,*(uint *)(lVar13 + 0x1c),1);
          param_2[0x8b] = 0;
          param_2[0x8c] = 0;
          param_2[0x8d] = 0;
          *param_2 = 0;
          goto LAB_1c00156da;
        }
        uVar5 = (uint)*(ushort *)(lVar13 + 0x18);
        goto LAB_1c0015520;
      }
    }
  }
  *param_2 = 1;
LAB_1c00156da:
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== FillInPortInfo @ 1c00156fc =====

void FillInPortInfo(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 3;
  bVar1 = (byte)param_2 & 7;
  if (bVar1 == 1) {
    if ((param_2 & 0x660) == 0) {
      if ((param_2 & 0x88) != 0) {
        uVar2 = 0x1f;
      }
    }
    else {
      uVar2 = 0x1e;
    }
  }
  else if (((byte)(bVar1 - 2) < 2) && (uVar2 = 3, (param_2 & 0x110) != 0)) {
    uVar2 = 0x20;
  }
  *param_1 = uVar2;
  param_1[2] = 0x1c;
  AsciiToUnicode("",(ushort *)(param_1 + 3),0x202);
  param_1[0x8c] = param_3;
  uVar3 = (uint)((param_2 & 0x440) != 0);
  if ((param_2 & 0x220) != 0) {
    uVar3 = uVar3 | 2;
  }
  if ((param_2 & 0x110) != 0) {
    uVar3 = uVar3 | 4;
  }
  if ((char)(byte)param_2 < '\0') {
    uVar3 = uVar3 | 8;
  }
  param_1[0x86] = uVar3;
  return;
}



===== __report_gsfailure @ 1c00157d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ScsiPortWmiPostProcess @ 1c00157d8 =====

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
        goto LAB_1c001589b;
      }
      param_2 = '\x12';
    }
LAB_1c0015878:
    if ((param_2 != '\x12') || (uVar2 < 0x38)) goto LAB_1c001589b;
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
        goto LAB_1c001589b;
      }
      goto LAB_1c0015878;
    }
    if (cVar1 != '\t') goto LAB_1c001589b;
    uVar7 = puVar4[0xf] + param_3;
    if (param_2 == '\x01') {
      if (0x47 < uVar2) {
        *puVar4 = uVar7;
        puVar4[0x10] = param_3;
        uVar9 = uVar7;
      }
      goto LAB_1c001589b;
    }
    if ((param_2 != '\x12') || (uVar2 < 0x38)) goto LAB_1c001589b;
    puVar4[0xc] = uVar7;
  }
  *puVar4 = 0x38;
  puVar4[0xb] = 0x20;
  param_2 = '\x01';
  uVar9 = 0x38;
LAB_1c001589b:
  *(uint *)(param_1 + 0x1c) = uVar9;
  *(char *)(param_1 + 0x19) = param_2;
  return;
}



===== ScsiWmipProcessRequest @ 1c0015928 =====

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
          goto LAB_1c00159fb;
          break;
        }
        uVar15 = (int)uVar18 + 1;
        uVar18 = (ulonglong)uVar15;
        plVar8 = plVar8 + 2;
      } while (uVar15 < *param_1);
    }
    *param_8 = 0;
    cVar4 = '\x04';
    goto LAB_1c0015d6d;
  }
LAB_1c00159fb:
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_1c0015a7b;
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
              goto LAB_1c0015d90;
            }
            goto LAB_1c0015da5;
          }
LAB_1c0015a7b:
          cVar4 = '\x04';
          goto LAB_1c0015da8;
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
LAB_1c0015b5e:
      cVar4 = (*pcVar6)(param_3,param_4,uVar18,uVar5,uVar15,puVar13,iVar11,lVar12);
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar19 = 0;
      uVar17 = 0;
      goto LAB_1c0015d95;
    }
  }
  else if (param_2 == 6) {
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar17 = 1;
LAB_1c0015d90:
      uVar19 = 1;
LAB_1c0015d95:
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
            goto LAB_1c0015b5e;
          }
        }
        goto LAB_1c0015a7b;
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
          goto LAB_1c0015d5e;
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
LAB_1c0015d5e:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_1c0015d6d:
      *param_9 = 1;
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar19 = 0;
      uVar17 = 1;
      goto LAB_1c0015d95;
    }
  }
LAB_1c0015da5:
  cVar4 = '\x01';
LAB_1c0015da8:
  *param_9 = 1;
  return cVar4;
}



===== ScsiPortWmiFireLogicalUnitEvent @ 1c0015dcc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScsiPortWmiFireLogicalUnitEvent(undefined8 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *in_stack_00000040;
  
  uVar4 = uRam00000001c0018064;
  uVar3 = uRam00000001c0018060;
  uVar2 = uRam00000001c001805c;
  uVar1 = _MegaSASWmiMpiEventGuid;
  in_stack_00000040[3] = 0;
  in_stack_00000040[0xd] = 0;
  in_stack_00000040[6] = uVar1;
  in_stack_00000040[7] = uVar2;
  in_stack_00000040[8] = uVar3;
  in_stack_00000040[9] = uVar4;
  in_stack_00000040[0xb] = 0x8a;
  in_stack_00000040[0xf] = 0x10;
  in_stack_00000040[0xe] = 0x40;
  *in_stack_00000040 = 0x50;
                    /* WARNING: Could not recover jumptable at 0x0001c0015e15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScsiPortNotification(8,param_1,in_stack_00000040,0xff);
  return;
}



===== __security_check_cookie @ 1c0015e30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 1c0015e50 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0015e60 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0015e80 =====

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



===== _guard_dispatch_icall @ 1c0015f00 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0015f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memcpy @ 1c0015f40 =====

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
        if (uVar12 == 0) goto LAB_1c00160f7;
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
LAB_1c00160f7:
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
      if (uVar12 == 0) goto LAB_1c0015f52;
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
LAB_1c0015f52:
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



===== memset @ 1c0016280 =====

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
      if (uVar5 == 0) goto LAB_1c0016340;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_1c001633d_caseD_2;
      case 3:
        goto switchD_1c001633d_caseD_3;
      case 4:
        goto switchD_1c001633d_caseD_4;
      case 5:
        goto switchD_1c001633d_caseD_5;
      case 6:
        goto switchD_1c001633d_caseD_6;
      case 7:
        goto switchD_1c001633d_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_1c0016340:
        *puVar3 = uVar4;
switchD_1c001633d_caseD_7:
        puVar3[1] = uVar4;
switchD_1c001633d_caseD_6:
        puVar3[2] = uVar4;
switchD_1c001633d_caseD_5:
        puVar3[3] = uVar4;
switchD_1c001633d_caseD_4:
        puVar3[4] = uVar4;
switchD_1c001633d_caseD_3:
        puVar3[5] = uVar4;
switchD_1c001633d_caseD_2:
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



===== entry @ 1c001b000 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_d8;
  undefined4 local_d4;
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
  
  __security_init_cookie();
  memset(&local_d8,0,0xd0);
  local_d8 = 0xd0;
  local_d0 = LSImpiHWInitialize;
  local_80 = 0x1010102;
  local_c8 = LSImpiStartIo;
  local_8c = 2;
  local_c0 = LSImpiIsr;
  local_d4 = 5;
  local_b8 = LSImpiFindAdapter;
  local_7c = 1;
  local_b0 = LSImpiOSReset;
  local_60 = LSImpiAdapterControl;
  local_58 = LSImpiBuildIo;
  local_98 = 0x1368;
  local_90 = 0x238;
  local_94 = 0x10;
  local_20 = 0x20;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== __security_init_cookie @ 1c001b0e4 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  char *pcVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  code *pcVar6;
  byte bVar7;
  uint uVar8;
  uint *puVar9;
  uint7 uVar12;
  longlong *plVar10;
  int *piVar11;
  char cVar13;
  byte *pbVar14;
  char in_DL;
  char in_DH;
  undefined6 in_register_00000012;
  undefined1 unaff_BL;
  char unaff_BH;
  undefined6 unaff_0000001a;
  longlong unaff_RBP;
  byte *unaff_RSI;
  undefined1 *unaff_RDI;
  char in_R8B;
  undefined7 in_register_00000081;
  
  if ((__security_cookie != 0) && (__security_cookie != 0x2b992ddfa232)) {
    ___security_cookie_complement = ~__security_cookie;
    return;
  }
  pbVar14 = (byte *)0x6;
  pcVar6 = (code *)swi(0x29);
  puVar9 = (uint *)(*pcVar6)();
  bVar7 = (byte)puVar9;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  uVar8 = *puVar9;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7 + CARRY1((byte)uVar8,bVar7);
  *(byte *)((longlong)puVar9 + -0x7fffffd7) = *(byte *)((longlong)puVar9 + -0x7fffffd7) + in_DH;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *unaff_RSI = *unaff_RSI >> 1;
  *(byte *)puVar9 = (byte)*puVar9 + bVar7;
  *puVar9 = *puVar9 ^ (uint)puVar9;
  *(byte *)((longlong)puVar9 + -0x7fffffc7) = *(byte *)((longlong)puVar9 + -0x7fffffc7) + bVar7;
  uVar12 = (uint7)((ulonglong)puVar9 >> 8);
  bVar7 = bVar7 + in_DH;
  puVar9 = (uint *)CONCAT71(uVar12,bVar7);
  *(char *)((longlong)puVar9 + -0x3fffffb5) = *(char *)((longlong)puVar9 + -0x3fffffb5) + in_DH;
  cVar3 = *(char *)CONCAT71(in_register_00000081,in_R8B);
  *(char *)CONCAT71(in_register_00000081,in_R8B) =
       *(char *)CONCAT71(in_register_00000081,in_R8B) + in_R8B;
  uVar8 = (uint)puVar9;
  cVar13 = (char)pbVar14;
  if (SCARRY1(cVar3,in_R8B)) {
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *(byte *)puVar9 = (char)*puVar9 + bVar7;
    *puVar9 = *puVar9 + uVar8;
    *puVar9 = *puVar9 + uVar8;
    cVar3 = cRam1080000020800000;
    piVar11 = (int *)CONCAT71(uVar12,cRam1080000020800000);
    *(char *)piVar11 = (char)*piVar11 + cRam1080000020800000;
    *(char *)piVar11 = (char)*piVar11 + unaff_BH;
    *(char *)piVar11 = (char)*piVar11 + cVar3;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11 + cVar3;
    *(char *)piVar11 = (char)*piVar11 + cVar3;
    *(char *)piVar11 = (char)*piVar11 + cVar3;
    *(char *)piVar11 = (char)*piVar11 + cVar3;
    *(char *)piVar11 = (char)*piVar11 + cVar3;
    *piVar11 = *piVar11 + (int)piVar11;
    *(char *)piVar11 = (char)*piVar11 + cVar3;
    piVar11 = (int *)((ulonglong)uVar12 * 0x100);
    *(char *)(piVar11 + -0x1fffffec) = (char)piVar11[-0x1fffffec];
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *piVar11 = *piVar11 + (int)piVar11;
    *piVar11 = *piVar11 + (int)piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *pbVar14 = *pbVar14;
    *pbVar14 = *pbVar14 + cVar13;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *(char *)piVar11 = (char)*piVar11;
    *pbVar14 = *pbVar14;
    *pbVar14 = *pbVar14 + cVar13;
    *(char *)(piVar11 + 0x18000000) = (char)piVar11[0x18000000] + in_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(byte *)puVar9 = (char)*puVar9 + bVar7;
  *unaff_RDI = *unaff_RDI;
  *(byte *)(unaff_RBP + -0x51200000) = *(byte *)(unaff_RBP + -0x51200000) & bVar7;
  *(byte *)puVar9 = (char)*puVar9 + bVar7;
  *pbVar14 = *pbVar14 << 1 | (char)*pbVar14 < '\0';
  uVar5 = *puVar9;
  *puVar9 = *puVar9 + uVar8;
  pbVar14[(longlong)puVar9] = pbVar14[(longlong)puVar9] + cVar13 + CARRY4(uVar5,uVar8);
  pbVar2 = (byte *)((longlong)puVar9 + -0xffffef1);
  bVar4 = *pbVar2;
  *pbVar2 = *pbVar2 + bVar7;
  uVar8 = (uVar8 - *(int *)pbVar14) - (uint)CARRY1(bVar4,bVar7);
  plVar10 = (longlong *)(ulonglong)uVar8;
  *(char *)((longlong)plVar10 + 0x1d) = *(char *)((longlong)plVar10 + 0x1d) + in_DL;
  *(uint *)plVar10 = (int)*plVar10 + uVar8;
  bRam000000020501c054 = bRam000000020501c054 >> 1;
  *(char *)((longlong)plVar10 + 0x49) = *(char *)((longlong)plVar10 + 0x49) + (char)(uVar8 >> 8);
  *(uint *)plVar10 = (int)*plVar10 + uVar8;
  pcVar1 = (char *)(CONCAT62(in_register_00000012,CONCAT11(in_DH,in_DL)) + 1);
  *pcVar1 = *pcVar1 + cVar13;
  *(char *)plVar10 = (char)*plVar10 + in_DH;
  *plVar10 = (longlong)(*plVar10 + (longlong)plVar10);
  pcVar1 = (char *)(CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) + 1);
  *pcVar1 = *pcVar1 + cVar13;
  uVar8 = CONCAT31((int3)(uVar8 >> 8),(char)uVar8 + in_DL);
  piVar11 = (int *)(ulonglong)uVar8;
  *piVar11 = *piVar11 + uVar8;
  *piVar11 = *piVar11 + uVar8;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


