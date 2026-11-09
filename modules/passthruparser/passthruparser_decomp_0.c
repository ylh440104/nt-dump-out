
===== PassthruParserExecuteScsiRequestDisk @ 1c0001010 =====

void PassthruParserExecuteScsiRequestDisk(longlong param_1,ulonglong *param_2)

{
  PassthruParserHandleSRB(param_1,param_2);
  return;
}



===== PassthruParserHandleSRB @ 1c0001030 =====

void PassthruParserHandleSRB(longlong param_1,ulonglong *param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  bool bVar10;
  int iVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined4 uVar15;
  byte *pbVar16;
  ulonglong uVar17;
  ulonglong *puVar18;
  char cVar19;
  bool bVar20;
  bool bVar21;
  
  puVar6 = (undefined8 *)*param_2;
  uVar7 = param_2[1];
  pbVar16 = (byte *)0x0;
  bVar21 = false;
  *puVar6 = 0;
  cVar19 = '\x03';
  puVar6[1] = param_1;
  iVar11 = 0;
  *(undefined1 *)(uVar7 + 3) = 0;
  if ((*(char *)(param_1 + 0x5e) == '\0') || (*(char *)(param_2[1] + 0x10) == -0x7d)) {
    uVar12 = PassthruParserVerifyCdb(param_1,(longlong)param_2);
    iVar11 = (int)uVar12;
  }
  bVar20 = false;
  if (iVar11 < 0) goto LAB_1c000120e;
  cVar1 = *(char *)(uVar7 + 0x10);
  if (cVar1 == '(') {
LAB_1c00010a7:
    uVar14 = (ulonglong)
             CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(uVar7 + 0x12),*(undefined1 *)(uVar7 + 0x13))
                               ,*(undefined1 *)(uVar7 + 0x14)),*(undefined1 *)(uVar7 + 0x15));
    if (((*(byte *)(uVar7 + 0x11) & 8) != 0) || (*(char *)(param_1 + 0x5d) == '\0')) {
      bVar20 = true;
      bVar21 = true;
    }
    pbVar16 = (byte *)(ulonglong)
                      CONCAT11(*(undefined1 *)(uVar7 + 0x17),*(undefined1 *)(uVar7 + 0x18));
  }
  else {
    if (cVar1 == '*') {
      cVar19 = '\x04';
      goto LAB_1c00010a7;
    }
    switch(cVar1) {
    default:
      if ((*(char *)(param_1 + 0x5e) != '\0') && (cVar1 != '\x03')) {
        uVar14 = PassthruParserScsiOperation(param_1,(longlong *)param_2,param_2[1],'\0');
        iVar11 = (int)uVar14;
        goto LAB_1c000120e;
      }
      uVar14 = param_2[2];
      if (uVar14 == 0) {
LAB_1c000143c:
        cVar19 = *(char *)(uVar7 + 0x10);
        if (cVar19 == '\x03') {
          uVar12 = PassthruParserScsiRequestSense(param_1,uVar7,pbVar16);
          iVar11 = (int)uVar12;
        }
        else if (cVar19 == '\x15') {
          cVar19 = '\0';
LAB_1c000149b:
          iVar11 = PassthruParserScsiModeSelect(param_1,uVar7,(longlong)pbVar16,cVar19);
        }
        else if (cVar19 == '\x1a') {
          uVar12 = PassthruParserScsiModeSense(param_1,uVar7,(short *)pbVar16,'\0');
          iVar11 = (int)uVar12;
        }
        else {
          if (cVar19 == 'U') {
            cVar19 = '\x01';
            goto LAB_1c000149b;
          }
          if (cVar19 == 'Z') {
            uVar12 = PassthruParserScsiModeSense(param_1,uVar7,(short *)pbVar16,'\x01');
            iVar11 = (int)uVar12;
          }
          else {
            uVar14 = PassthruParserScsiOperation(param_1,(longlong *)param_2,param_2[1],'\0');
            iVar11 = (int)uVar14;
          }
        }
        goto LAB_1c000120e;
      }
      if ((*(byte *)(uVar14 + 10) & 5) == 0) {
        pbVar16 = (byte *)MmMapLockedPagesSpecifyCache(uVar14,0,1,0,0,0x40000010);
      }
      else {
        pbVar16 = *(byte **)(uVar14 + 0x18);
      }
      if (pbVar16 != (byte *)0x0) goto LAB_1c000143c;
      iVar11 = -0x3fffff66;
      goto LAB_1c000153d;
    case '\n':
      cVar19 = '\x04';
    case '\b':
      uVar14 = (ulonglong)
               ((uint6)CONCAT21(CONCAT11(*(undefined1 *)(uVar7 + 0x11),*(undefined1 *)(uVar7 + 0x12)
                                        ),*(undefined1 *)(uVar7 + 0x13)) & 0x1fffff);
      bVar20 = *(char *)(param_1 + 0x5d) == '\0';
      pbVar16 = (byte *)(ulonglong)*(byte *)(uVar7 + 0x14);
      bVar21 = bVar20;
      goto LAB_1c00010f2;
    case '5':
    case -0x6f:
      puVar18 = (ulonglong *)*param_2;
      cVar19 = '\t';
      uVar14 = 0;
      goto LAB_1c00010ff;
    case -0x76:
      cVar19 = '\x04';
    case -0x78:
      uVar14 = *(ulonglong *)(uVar7 + 0x12);
      uVar4 = *(undefined1 *)(uVar7 + 0x1c);
      uVar5 = *(undefined1 *)(uVar7 + 0x1d);
      uVar2 = *(undefined1 *)(uVar7 + 0x1a);
      uVar14 = ((((((uVar14 >> 8 & 0xff | (uVar14 & 0xff) << 8) << 8 | uVar14 >> 0x10 & 0xff) << 8 |
                  uVar14 >> 0x18 & 0xff) << 8 | uVar14 >> 0x20 & 0xff) << 8 | uVar14 >> 0x28 & 0xff)
                << 8 | uVar14 >> 0x30 & 0xff) << 8 | uVar14 >> 0x38;
      uVar3 = *(undefined1 *)(uVar7 + 0x1b);
      break;
    case -0x56:
      cVar19 = '\x04';
    case -0x58:
      uVar2 = *(undefined1 *)(uVar7 + 0x16);
      uVar3 = *(undefined1 *)(uVar7 + 0x17);
      uVar4 = *(undefined1 *)(uVar7 + 0x18);
      uVar5 = *(undefined1 *)(uVar7 + 0x19);
      uVar14 = (ulonglong)
               CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(uVar7 + 0x12),
                                          *(undefined1 *)(uVar7 + 0x13)),
                                 *(undefined1 *)(uVar7 + 0x14)),*(undefined1 *)(uVar7 + 0x15));
    }
    if (((*(byte *)(uVar7 + 0x11) & 8) != 0) || (*(char *)(param_1 + 0x5d) == '\0')) {
      bVar20 = true;
      bVar21 = true;
    }
    pbVar16 = (byte *)(ulonglong)CONCAT31(CONCAT21(CONCAT11(uVar2,uVar3),uVar4),uVar5);
  }
LAB_1c00010f2:
  puVar18 = (ulonglong *)*param_2;
  if ((cVar19 == '\x04') && ((*(uint *)(param_1 + 0x28) & 0x40000000) == 0)) {
    iVar11 = -0x3ffffff0;
  }
  else {
LAB_1c00010ff:
    uVar13 = CONCAT44(0,*(uint *)(param_1 + 0x2c));
    uVar17 = (longlong)pbVar16 * uVar13;
    if ((uVar17 < 0x100000000) &&
       (auVar8._8_8_ = 0, auVar8._0_8_ = uVar13, auVar9._8_8_ = 0, auVar9._0_8_ = uVar14,
       SUB168(auVar8 * auVar9,8) == 0)) {
      bVar10 = false;
      uVar15 = (undefined4)uVar17;
      *(undefined4 *)(param_2[1] + 0xc) = uVar15;
      uVar14 = param_2[2];
      if (uVar14 != 0) {
        uVar14 = (ulonglong)*(uint *)(uVar14 + 0x2c) + *(longlong *)(uVar14 + 0x20);
        if ((uVar14 & 1) != 0) {
          iVar11 = -0x3ffffff0;
          goto LAB_1c000120e;
        }
        bVar21 = bVar20;
        if ((*(longlong *)(param_1 + 0x68) != 0) &&
           ((uVar14 & *(uint *)(*(longlong *)(param_1 + 0x20) + 0x98)) != 0)) {
          bVar10 = true;
        }
      }
      IoInitializeIrp(puVar18 + 2,*(undefined2 *)(param_1 + 0x30),
                      *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 0x4c));
      uVar14 = *(ulonglong *)(param_1 + 0xa8);
      *(uint *)(puVar18 + 4) = (uint)puVar18[4] | 1;
      puVar18[0x15] = uVar14;
      puVar18[3] = param_2[2];
      uVar14 = puVar18[0x19];
      *(code **)(uVar14 - 0x10) = PassthruParserCompleteReadWriteIo;
      *(ulonglong **)(uVar14 - 8) = param_2;
      *(undefined1 *)(uVar14 - 0x45) = 0xe0;
      uVar14 = puVar18[0x19];
      uVar12 = *(undefined8 *)(param_1 + 0x20);
      *(undefined8 *)(uVar14 - 0x20) = uVar12;
      *(char *)(uVar14 - 0x48) = cVar19;
      if (bVar21) {
        *(byte *)(uVar14 - 0x46) = *(byte *)(uVar14 - 0x46) | 4;
      }
      *(byte *)(uVar14 - 0x46) = *(byte *)(uVar14 - 0x46) | 2;
      *(undefined4 *)(uVar14 - 0x40) = uVar15;
      *(longlong *)(uVar14 - 0x30) = SUB168(auVar8 * auVar9,0);
      if (bVar10) {
        uVar14 = *(ulonglong *)(param_1 + 0x88);
        do {
          *puVar18 = uVar14 & 0xfffffffffffffffe;
          LOCK();
          uVar13 = *(ulonglong *)(param_1 + 0x88);
          if (uVar14 == uVar13) {
            *(ulonglong *)(param_1 + 0x88) = (ulonglong)puVar18;
            uVar13 = uVar14;
          }
          else {
          }
          UNLOCK();
          bVar21 = uVar13 != uVar14;
          uVar14 = uVar13;
        } while (bVar21);
        if (uVar13 == 0) {
          IoQueueWorkItemEx(*(undefined8 *)(param_1 + 0x80),PassthruParserDoubleBufferWorkerRoutine,
                            1,param_1);
        }
      }
      else {
        IofCallDriver(uVar12,puVar18 + 2);
      }
      iVar11 = 0x103;
    }
    else {
      iVar11 = -0x3fffff6b;
    }
  }
LAB_1c000120e:
  if (iVar11 != 0x103) {
    if (iVar11 < 0) {
LAB_1c000153d:
      *(undefined4 *)(uVar7 + 0xc) = 0;
    }
    PassthruParserGenerateSenseInfoFromNtStatus(uVar7,iVar11);
    PassthruParserUpdateSenseInfoFromSrb(param_1,uVar7);
    VstorCompleteScsiRequest(param_2);
  }
  return;
}



===== PassthruParserVerifyCdb @ 1c0001570 =====

undefined8 PassthruParserVerifyCdb(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  bool bVar10;
  
  lVar2 = *(longlong *)(param_2 + 8);
  cVar7 = '\x02';
  cVar1 = *(char *)(lVar2 + 0x10);
  if (cVar1 == '*') {
switchD_1c0001688_caseD_28:
    uVar5 = (ulonglong)CONCAT11(*(undefined1 *)(lVar2 + 0x17),*(undefined1 *)(lVar2 + 0x18)) *
            (ulonglong)*(uint *)(param_1 + 0x2c);
    if (0xffffffff < uVar5) {
      return 0x80000005;
    }
    if (*(uint *)(lVar2 + 0xc) < (uint)uVar5) {
      return 0x80000005;
    }
    goto switchD_1c0001688_caseD_0;
  }
  if (cVar1 == '\x04') goto switchD_1c0001688_caseD_0;
  switch(cVar1) {
  case '\0':
  case '\x16':
  case '\x17':
  case '\x1b':
  case '\x1d':
  case '\x1e':
  case '/':
  case '5':
  case 'J':
  case -0x71:
  case -0x6f:
    break;
  default:
    return 0xc0000002;
  case '\x03':
    if (*(uint *)(lVar2 + 0xc) < (uint)*(byte *)(lVar2 + 0x14)) {
      return 0x80000005;
    }
    bVar10 = *(byte *)(lVar2 + 0x14) < 8;
    goto LAB_1c000169d;
  case '\b':
  case '\n':
    uVar5 = (ulonglong)*(byte *)(lVar2 + 0x14);
    goto LAB_1c0001738;
  case '\x12':
    if (*(uint *)(lVar2 + 0xc) < (uint)*(byte *)(lVar2 + 0x14)) {
      return 0x80000005;
    }
    break;
  case '\x15':
  case '\x1a':
    if (*(uint *)(lVar2 + 0xc) < (uint)*(byte *)(lVar2 + 0x14)) {
      return 0x80000005;
    }
    if (*(byte *)(lVar2 + 0x14) < 4) {
      return 0x80000005;
    }
    break;
  case '%':
    bVar10 = *(uint *)(lVar2 + 0xc) < 8;
LAB_1c000169d:
    if (bVar10) {
      return 0x80000005;
    }
    break;
  case '(':
    goto switchD_1c0001688_caseD_28;
  case 'B':
  case 'U':
  case 'Z':
    uVar4 = (uint)CONCAT11(*(undefined1 *)(lVar2 + 0x17),*(undefined1 *)(lVar2 + 0x18));
    if (*(uint *)(lVar2 + 0xc) < uVar4) {
      return 0x80000005;
    }
    if (uVar4 < 8) {
      return 0x80000005;
    }
    break;
  case -0x7d:
    lVar9 = 0;
    uVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar2 + 0x1a),*(undefined1 *)(lVar2 + 0x1b)),
                              *(undefined1 *)(lVar2 + 0x1c)),*(undefined1 *)(lVar2 + 0x1d));
    if (*(uint *)(lVar2 + 0xc) < uVar4) {
      return 0x80000005;
    }
    bVar3 = *(byte *)(lVar2 + 0x11) & 0x1f;
    if ((bVar3 == 0x10) || (bVar3 == 0x11)) {
      lVar9 = *(longlong *)(param_2 + 0x10);
      if (lVar9 == 0) {
        return 0xc000000d;
      }
      if ((*(byte *)(lVar9 + 10) & 5) == 0) {
        lVar9 = MmMapLockedPagesSpecifyCache(lVar9,0,1,0,0,0x40000010);
      }
      else {
        lVar9 = *(longlong *)(lVar9 + 0x18);
      }
      if (lVar9 == 0) {
        return 0xc000009a;
      }
    }
    bVar3 = *(byte *)(lVar2 + 0x11) & 0x1f;
    if (bVar3 == 0x10) {
      bVar10 = uVar4 < 0x20;
    }
    else {
      if (bVar3 != 0x11) {
        if (bVar3 != 0x1c) {
          return 0xc0000002;
        }
        break;
      }
      bVar10 = uVar4 < 0x228;
    }
    cVar7 = '\0';
    if (bVar10) {
      return 0x80000005;
    }
    if ((*(byte *)(lVar9 + 2) & 1) != 0) {
      return 0xc00000bb;
    }
    break;
  case -0x7c:
    uVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar2 + 0x1a),*(undefined1 *)(lVar2 + 0x1b)),
                              *(undefined1 *)(lVar2 + 0x1c)),*(undefined1 *)(lVar2 + 0x1d));
    if (*(uint *)(lVar2 + 0xc) < uVar4) {
      return 0x80000005;
    }
    if ((*(byte *)(lVar2 + 0x11) & 0x1f) != 7) {
      return 0xc0000002;
    }
    if (uVar4 < 0x20) {
      return 0x80000005;
    }
    break;
  case -0x78:
  case -0x76:
    uVar5 = (ulonglong)
            CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar2 + 0x1a),*(undefined1 *)(lVar2 + 0x1b)),
                              *(undefined1 *)(lVar2 + 0x1c)),*(undefined1 *)(lVar2 + 0x1d));
    goto LAB_1c0001738;
  case -0x62:
    if (*(uint *)(lVar2 + 0xc) < 0xc) {
      return 0x80000005;
    }
    break;
  case -0x58:
  case -0x56:
    uVar5 = (ulonglong)
            CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar2 + 0x16),*(undefined1 *)(lVar2 + 0x17)),
                              *(undefined1 *)(lVar2 + 0x18)),*(undefined1 *)(lVar2 + 0x19));
LAB_1c0001738:
    uVar5 = uVar5 * *(uint *)(param_1 + 0x2c);
    if ((0xffffffff < uVar5) || (*(uint *)(lVar2 + 0xc) < (uint)uVar5)) {
      return 0x80000005;
    }
  }
switchD_1c0001688_caseD_0:
  if (*(int *)(lVar2 + 0xc) == 0) {
    return 0;
  }
  if (cVar7 != '\x02') {
    if (*(char *)(lVar2 + 10) == cVar7) {
      return 0;
    }
    goto switchD_1c00018c0_caseD_1;
  }
  iVar6 = 0x80;
  iVar8 = 0x40;
  if (*(char *)(lVar2 + 10) == '\0') {
    iVar8 = 0x80;
  }
  if (*(char *)(lVar2 + 0x10) == '^') {
switchD_1c00018c0_caseD_3:
    iVar6 = 0x40;
    goto switchD_1c00018c0_caseD_a;
  }
  switch(*(char *)(lVar2 + 0x10)) {
  case '\0':
  case '\x04':
  case '\x16':
  case '\x17':
  case '\x1b':
  case '\x1d':
  case '\x1e':
  case '.':
  case '/':
  case '5':
  case -0x7d:
  case -0x71:
  case -0x6f:
    return 0;
  case '\x03':
  case '\b':
  case '\x12':
  case '\x1a':
  case '%':
  case '(':
  case 'C':
  case 'F':
  case 'J':
  case 'Q':
  case 'R':
  case 'Z':
  case '\\':
  case -0x7c:
  case -0x78:
  case -0x62:
  case -0x58:
  case -0x54:
  case -0x53:
  case -0x43:
    goto switchD_1c00018c0_caseD_3;
  case '\n':
  case '\x15':
  case '*':
  case 'A':
  case 'B':
  case 'U':
  case '_':
  case -0x77:
  case -0x76:
  case -0x6d:
  case -0x56:
  case -0x4a:
switchD_1c00018c0_caseD_a:
    if (iVar6 == iVar8) {
      return 0;
    }
  default:
switchD_1c00018c0_caseD_1:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    return 0xc000000d;
  }
}



===== PassthruParserCompleteReadWriteIo @ 1c00018e0 =====

undefined8 PassthruParserCompleteReadWriteIo(undefined8 param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  undefined1 uVar5;
  size_t _Size;
  
  lVar2 = param_3[1];
  iVar1 = *(int *)(param_2 + 0x30);
  lVar3 = *(longlong *)(*param_3 + 8);
  if (-1 < iVar1) {
    *(undefined2 *)(lVar2 + 2) = 1;
    goto LAB_1c0001913;
  }
  *(undefined8 *)(lVar2 + 0x10) = 0;
  *(undefined8 *)(lVar2 + 0x18) = 0;
  *(undefined2 *)(lVar2 + 0x20) = 0;
  bVar4 = *(byte *)(lVar2 + 0x12) & 0xf0;
  *(byte *)(lVar2 + 0x12) = bVar4;
  if (iVar1 < -0x3fffffef) {
    if (iVar1 == -0x3ffffff0) {
LAB_1c0001995:
      *(undefined2 *)(lVar2 + 2) = 0x286;
      bVar4 = bVar4 | 5;
      *(undefined1 *)(lVar2 + 0x1c) = 0x20;
      goto LAB_1c0001a2d;
    }
    if (iVar1 != -0x7ffffffb) {
      if (iVar1 == -0x7fffffe4) {
        *(undefined2 *)(lVar2 + 2) = 0x284;
        bVar4 = bVar4 | 6;
        *(undefined1 *)(lVar2 + 0x1c) = 0x28;
        goto LAB_1c0001a2d;
      }
      if (iVar1 != -0x3ffffffe) goto LAB_1c00019d0;
      goto LAB_1c0001995;
    }
LAB_1c0001a0c:
    *(undefined2 *)(lVar2 + 2) = 0x292;
    bVar4 = bVar4 | 0x20;
    *(undefined4 *)(lVar2 + 0x13) = 0xffffffff;
  }
  else {
    if (iVar1 != -0x3fffffed) {
      if (iVar1 != -0x3fffffeb) {
        if (iVar1 != -0x3fffffdd) {
LAB_1c00019d0:
          *(undefined2 *)(lVar2 + 2) = 0x204;
          *(undefined1 *)(lVar2 + 0x10) = 0x70;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          goto LAB_1c0001913;
        }
        goto LAB_1c0001a0c;
      }
      goto LAB_1c0001995;
    }
    *(undefined2 *)(lVar2 + 2) = 0x284;
    bVar4 = bVar4 | 2;
    *(undefined1 *)(lVar2 + 0x1c) = 0x3a;
LAB_1c0001a2d:
    *(undefined1 *)(lVar2 + 0x17) = 7;
  }
  *(byte *)(lVar2 + 0x12) = bVar4;
  *(undefined1 *)(lVar2 + 0x10) = 0x70;
LAB_1c0001913:
  lVar2 = param_3[1];
  if (*(char *)(lVar2 + 3) == '\0') {
    *(undefined1 *)(lVar3 + 0x5c) = 0;
  }
  else {
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x40);
    _Size = (size_t)*(byte *)(lVar2 + 9);
    if (0x13 < *(byte *)(lVar2 + 9)) {
      _Size = 0x14;
    }
    memcpy((void *)(lVar3 + 0x48),(void *)(lVar2 + 0x10),_Size);
    *(undefined1 *)(lVar3 + 0x5c) = 1;
    KeReleaseSpinLock(lVar3 + 0x40,uVar5);
  }
  if (*(int *)(param_2 + 0x30) < 0) {
    *(undefined4 *)(param_3[1] + 0xc) = 0;
  }
  VstorCompleteScsiRequest(param_3);
  return 0xc0000016;
}



===== PassthruParserCheckMdlAlignment @ 1c0001ac0 =====

undefined8 PassthruParserCheckMdlAlignment(longlong param_1,longlong param_2,undefined1 *param_3)

{
  ulonglong uVar1;
  
  *param_3 = 0;
  if (param_2 != 0) {
    uVar1 = (ulonglong)*(uint *)(param_2 + 0x2c) + *(longlong *)(param_2 + 0x20);
    if ((uVar1 & 1) != 0) {
      return 0xc0000010;
    }
    if ((*(longlong *)(param_1 + 0x68) != 0) &&
       ((uVar1 & *(uint *)(*(longlong *)(param_1 + 0x20) + 0x98)) != 0)) {
      *param_3 = 1;
    }
  }
  return 0;
}



===== PassthruParserUpdateSenseInfoFromSrb @ 1c0001b10 =====

void PassthruParserUpdateSenseInfoFromSrb(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  size_t _Size;
  
  if (*(char *)(param_2 + 3) == '\0') {
    *(undefined1 *)(param_1 + 0x5c) = 0;
  }
  else {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
    _Size = (size_t)*(byte *)(param_2 + 9);
    if (0x13 < *(byte *)(param_2 + 9)) {
      _Size = 0x14;
    }
    memcpy((void *)(param_1 + 0x48),(void *)(param_2 + 0x10),_Size);
    *(undefined1 *)(param_1 + 0x5c) = 1;
    KeReleaseSpinLock(param_1 + 0x40,uVar1);
  }
  return;
}



===== DvScsiValidateDataTransferDirection @ 1c0001ba0 =====

undefined8 DvScsiValidateDataTransferDirection(char param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == '^') {
switchD_1c0001bd1_caseD_3:
    uVar1 = 0x40;
  }
  else {
    switch(param_1) {
    case '\0':
    case '\x04':
    case '\x16':
    case '\x17':
    case '\x1b':
    case '\x1d':
    case '\x1e':
    case '.':
    case '/':
    case '5':
    case -0x7d:
    case -0x71:
    case -0x6f:
      goto switchD_1c0001bd1_caseD_0;
    default:
      goto switchD_1c0001bd1_caseD_1;
    case '\x03':
    case '\b':
    case '\x12':
    case '\x1a':
    case '%':
    case '(':
    case 'C':
    case 'F':
    case 'J':
    case 'Q':
    case 'R':
    case 'Z':
    case '\\':
    case -0x7c:
    case -0x78:
    case -0x62:
    case -0x58:
    case -0x54:
    case -0x53:
    case -0x43:
      goto switchD_1c0001bd1_caseD_3;
    case '\n':
    case '\x15':
    case '*':
    case 'A':
    case 'B':
    case 'U':
    case '_':
    case -0x77:
    case -0x76:
    case -0x6d:
    case -0x56:
    case -0x4a:
      uVar1 = 0x80;
    }
  }
  if (uVar1 == (param_2 & 0xc0)) {
switchD_1c0001bd1_caseD_0:
    return 1;
  }
switchD_1c0001bd1_caseD_1:
  return 0;
}



===== PassthruParserGenerateSenseInfoFromNtStatus @ 1c0001c00 =====

void PassthruParserGenerateSenseInfoFromNtStatus(longlong param_1,int param_2)

{
  byte bVar1;
  
  if (-1 < param_2) {
    *(undefined2 *)(param_1 + 2) = 1;
    return;
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined2 *)(param_1 + 0x20) = 0;
  bVar1 = *(byte *)(param_1 + 0x12) & 0xf0;
  *(byte *)(param_1 + 0x12) = bVar1;
  if (param_2 < -0x3fffffef) {
    if (param_2 != -0x3ffffff0) {
      if (param_2 == -0x7ffffffb) {
LAB_1c0001cc7:
        *(undefined2 *)(param_1 + 2) = 0x292;
        bVar1 = bVar1 | 0x20;
        *(undefined4 *)(param_1 + 0x13) = 0xffffffff;
        goto LAB_1c0001cec;
      }
      if (param_2 == -0x7fffffe4) {
        *(undefined2 *)(param_1 + 2) = 0x284;
        bVar1 = bVar1 | 6;
        *(undefined1 *)(param_1 + 0x1c) = 0x28;
        goto LAB_1c0001ce8;
      }
      if (param_2 != -0x3ffffffe) goto LAB_1c0001c8b;
    }
LAB_1c0001c50:
    *(undefined2 *)(param_1 + 2) = 0x286;
    bVar1 = bVar1 | 5;
    *(undefined1 *)(param_1 + 0x1c) = 0x20;
  }
  else {
    if (param_2 != -0x3fffffed) {
      if (param_2 != -0x3fffffeb) {
        if (param_2 != -0x3fffffdd) {
LAB_1c0001c8b:
          *(undefined2 *)(param_1 + 2) = 0x204;
          *(undefined1 *)(param_1 + 0x10) = 0x70;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return;
          }
          WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          return;
        }
        goto LAB_1c0001cc7;
      }
      goto LAB_1c0001c50;
    }
    *(undefined2 *)(param_1 + 2) = 0x284;
    bVar1 = bVar1 | 2;
    *(undefined1 *)(param_1 + 0x1c) = 0x3a;
  }
LAB_1c0001ce8:
  *(undefined1 *)(param_1 + 0x17) = 7;
LAB_1c0001cec:
  *(byte *)(param_1 + 0x12) = bVar1;
  *(undefined1 *)(param_1 + 0x10) = 0x70;
  return;
}



===== PassthruParserSupportsDataTransferDirectionValidation @ 1c0001d00 =====

bool PassthruParserSupportsDataTransferDirectionValidation(longlong param_1)

{
  return *(char *)(param_1 + 0x5e) == '\0';
}



===== PassthruParserIsDoubleBufferingRequired @ 1c0001d10 =====

undefined4 PassthruParserIsDoubleBufferingRequired(uint param_1,longlong param_2)

{
  return CONCAT31((int3)(*(uint *)(param_2 + 0x98) >> 8),(param_1 & *(uint *)(param_2 + 0x98)) != 0)
  ;
}



===== __report_gsfailure @ 1c0001d30 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ContextListAdd @ 1c0001d40 =====

undefined8 ContextListAdd(undefined8 *param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar5 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(&ContextListSpinLock,&local_28);
  puVar4 = auStack_48;
  puVar3 = &ContextListHead;
  puVar2 = ContextListHead;
  do {
    if ((undefined8 **)puVar2 == &ContextListHead) {
      if ((undefined8 **)ContextListHead[1] != &ContextListHead) {
        pcVar1 = (code *)swi(0x29);
        ContextListHead = (undefined8 *)(*pcVar1)(3);
        puVar4 = auStack_40;
      }
      *param_1 = ContextListHead;
      param_1[1] = puVar3;
      ContextListHead[1] = param_1;
      ContextListHead = param_1;
LAB_1c0001dc5:
      *(undefined8 *)(puVar4 + -8) = 0x1c0001dd1;
      KeReleaseInStackQueuedSpinLock(puVar4 + 0x20);
      return uVar5;
    }
    if (puVar2[4] == param_1[4]) {
      uVar5 = 0xc0000043;
      puVar4 = auStack_48;
      goto LAB_1c0001dc5;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== ContextListRemove @ 1c0001dec =====

void ContextListRemove(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((*param_1 != 0) && (param_1[1] != 0)) {
    KeAcquireInStackQueuedSpinLock(&ContextListSpinLock,&local_28);
    lVar1 = *param_1;
    if ((*(longlong **)(lVar1 + 8) != param_1) ||
       (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    *param_1 = 0;
    param_1[1] = 0;
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  return;
}



===== PassthruParserSetBehaviorDisk @ 1c0001e70 =====

int PassthruParserSetBehaviorDisk(longlong param_1,int param_2,char *param_3,int param_4)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  if (param_2 == 1) {
    if (param_4 == 0) {
      return -0x3ffffff3;
    }
    cVar1 = *param_3;
    iVar3 = PassthruParserSetWriteCache(param_1,(ulonglong)(cVar1 != '\0'));
    if (iVar3 < 0) {
      return iVar3;
    }
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
    *(bool *)(param_1 + 0x5d) = cVar1 != '\0';
  }
  else {
    if (param_2 != 0x40000001) {
      return -0x3ffffff0;
    }
    if (param_4 == 0) {
      return -0x3ffffff3;
    }
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
    *(char *)(param_1 + 0x5e) = *param_3;
  }
  KeReleaseSpinLock(param_1 + 0x40,uVar2);
  return 0;
}



===== PassthruParserSyncIo @ 1c0001f18 =====

undefined4
PassthruParserSyncIo
          (longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
          undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0xb8,0);
  lVar2 = *(longlong *)(param_1 + 0xb0);
  IoReuseIrp(lVar2,0x103);
  uVar3 = *(undefined8 *)(param_1 + 0xa8);
  *(uint *)(lVar2 + 0x10) = *(uint *)(lVar2 + 0x10) | 1;
  lVar4 = *(longlong *)(lVar2 + 0xb8);
  *(undefined8 *)(lVar2 + 0x98) = uVar3;
  *(undefined8 *)(lVar4 + -0x18) = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(lVar4 + -0x20) = *(undefined8 *)(param_1 + 0x20);
  *(undefined4 *)(lVar4 + -0x40) = param_6;
  *(undefined4 *)(lVar4 + -0x38) = param_5;
  *(undefined1 *)(lVar4 + -0x48) = 0xe;
  *(undefined4 *)(lVar4 + -0x30) = param_3;
  *(undefined8 *)(lVar2 + 0x18) = param_4;
  IoSynchronousCallDriver(*(undefined8 *)(lVar4 + -0x20),lVar2);
  uVar1 = *(undefined4 *)(lVar2 + 0x30);
  ExReleasePushLockExclusiveEx(param_1 + 0xb8,0);
  KeLeaveCriticalRegion();
  return uVar1;
}



===== WPP_RECORDER_SF_ @ 1c0002014 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ba75710c351a3ce3bfdb948128598e04_Traceguids,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_ba75710c351a3ce3bfdb948128598e04_Traceguids,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 1c00020a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0002190 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      *(undefined8 *)(param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
      *(undefined8 *)(param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== PassthruParserCallDriverDoubleBuffered @ 1c00021ec =====

void PassthruParserCallDriverDoubleBuffered(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong lVar10;
  uint uVar11;
  
  lVar1 = *(longlong *)(param_1 + 0x78);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  ExAcquirePushLockExclusiveEx(param_1 + 0x90,0);
  uVar8 = 0;
  lVar10 = 0;
  for (uVar9 = *(uint *)(lVar2 + -0x40); uVar9 != 0; uVar9 = uVar9 - uVar11) {
    lVar3 = *(longlong *)(param_2 + 0xb8);
    lVar4 = *(longlong *)(param_1 + 0x78);
    uVar11 = 0x10000;
    if (uVar9 < 0x10000) {
      uVar11 = uVar9;
    }
    *(uint *)(lVar4 + 0x10) = *(uint *)(lVar4 + 0x10) | 1;
    lVar5 = *(longlong *)(lVar4 + 0xb8);
    *(undefined8 *)(lVar4 + 8) = *(undefined8 *)(param_1 + 0x70);
    *(undefined8 *)(lVar4 + 0x98) = *(undefined8 *)(param_1 + 0xa8);
    uVar6 = *(undefined8 *)(lVar3 + -0x40);
    *(undefined8 *)(lVar5 + -0x48) = *(undefined8 *)(lVar3 + -0x48);
    *(undefined8 *)(lVar5 + -0x40) = uVar6;
    uVar6 = *(undefined8 *)(lVar3 + -0x30);
    *(undefined8 *)(lVar5 + -0x38) = *(undefined8 *)(lVar3 + -0x38);
    *(undefined8 *)(lVar5 + -0x30) = uVar6;
    uVar6 = *(undefined8 *)(lVar3 + -0x20);
    *(undefined8 *)(lVar5 + -0x28) = *(undefined8 *)(lVar3 + -0x28);
    *(undefined8 *)(lVar5 + -0x20) = uVar6;
    uVar6 = *(undefined8 *)(lVar3 + -0x10);
    *(undefined8 *)(lVar5 + -0x18) = *(undefined8 *)(lVar3 + -0x18);
    *(undefined8 *)(lVar5 + -0x10) = uVar6;
    *(undefined8 *)(lVar5 + -8) = *(undefined8 *)(lVar3 + -8);
    *(longlong *)(lVar5 + -0x30) = *(longlong *)(lVar5 + -0x30) + lVar10;
    *(uint *)(lVar5 + -0x40) = uVar11;
    if (*(char *)(lVar2 + -0x48) == '\x04') {
      PassthruParserDoubleBufferData
                (param_1,*(longlong *)(param_2 + 8),lVar10,(ulonglong)uVar11,'\x01');
    }
    IoSynchronousCallDriver(*(undefined8 *)(lVar2 + -0x20),lVar1);
    if (*(char *)(lVar2 + -0x48) == '\x03') {
      PassthruParserDoubleBufferData
                (param_1,*(longlong *)(param_2 + 8),lVar10,(ulonglong)uVar11,'\0');
    }
    iVar7 = *(int *)(lVar1 + 0x30);
    IoReuseIrp(lVar1,0);
    if (iVar7 < 0) goto LAB_1c0002334;
    lVar10 = lVar10 + (ulonglong)uVar11;
  }
  iVar7 = 0;
  uVar8 = (ulonglong)*(uint *)(lVar2 + -0x40);
LAB_1c0002334:
  *(ulonglong *)(param_2 + 0x38) = uVar8;
  ExReleasePushLockExclusiveEx(param_1 + 0x90,0);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + -1;
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
  *(int *)(param_2 + 0x30) = iVar7;
  IofCompleteRequest(param_2,0);
  return;
}



===== PassthruParserDoubleBufferData @ 1c000238c =====

void PassthruParserDoubleBufferData
               (longlong param_1,longlong param_2,longlong param_3,ulonglong param_4,char param_5)

{
  undefined8 *puVar1;
  longlong lVar2;
  void *pvVar3;
  void *_Dst;
  void *_Src;
  ulonglong uVar4;
  
  puVar1 = *(undefined8 **)(param_1 + 0x98);
  uVar4 = (ulonglong)*(uint *)(param_2 + 0x2c) + *(longlong *)(param_2 + 0x20) + param_3;
  *puVar1 = 0;
  *(undefined2 *)((longlong)puVar1 + 10) = 0;
  *(int *)(puVar1 + 5) = (int)param_4;
  *(uint *)((longlong)puVar1 + 0x2c) = (uint)uVar4 & 0xfff;
  *(short *)(puVar1 + 1) =
       ((short)((param_4 & 0xffffffff) + 0xfff + (uVar4 & 0xfff) >> 0xc) + 6) * 8;
  puVar1[4] = uVar4 & 0xfffffffffffff000;
  IoBuildPartialMdl(param_2,*(undefined8 *)(param_1 + 0x98),uVar4,param_4 & 0xffffffff);
  pvVar3 = (void *)MmMapLockedPagesWithReservedMapping
                             (*(undefined8 *)(param_1 + 0xa0),0x73725056,
                              *(undefined8 *)(param_1 + 0x98),1);
  _Src = *(void **)(param_1 + 0x68);
  if (param_5 == '\0') {
    _Dst = pvVar3;
  }
  else {
    _Dst = _Src;
    _Src = pvVar3;
  }
  memcpy(_Dst,_Src,param_4 & 0xffffffff);
  MmUnmapReservedMapping(pvVar3,0x73725056,*(undefined8 *)(param_1 + 0x98));
  lVar2 = *(longlong *)(param_1 + 0x98);
  if ((*(byte *)(lVar2 + 10) & 0x20) != 0) {
    MmUnmapLockedPages(*(undefined8 *)(lVar2 + 0x18),lVar2);
  }
  return;
}



===== PassthruParserDoubleBufferWorkerRoutine @ 1c00024d0 =====

void PassthruParserDoubleBufferWorkerRoutine(undefined8 param_1,longlong param_2)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  bool bVar7;
  
  puVar1 = (ulonglong *)(param_2 + 0x88);
  do {
    uVar3 = *puVar1;
    do {
      if ((uVar3 & 2) != 0) {
        puVar6 = (undefined8 *)DvpRemoveWorkQueueRunningDown((longlong *)puVar1);
        break;
      }
      puVar6 = (undefined8 *)(uVar3 & 0xfffffffffffffffe);
      LOCK();
      if (uVar3 == *puVar1) {
        *puVar1 = (ulonglong)(puVar6 != (undefined8 *)0x0);
        uVar4 = uVar3;
      }
      else {
        uVar4 = *puVar1;
      }
      UNLOCK();
      bVar7 = uVar4 != uVar3;
      uVar3 = uVar4;
    } while (bVar7);
    puVar5 = (undefined8 *)0x0;
    while (puVar6 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)*puVar6;
      *puVar6 = puVar5;
      puVar5 = puVar6;
      puVar6 = puVar2;
    }
    if (puVar5 == (undefined8 *)0x0) {
      return;
    }
    do {
      puVar6 = (undefined8 *)*puVar5;
      PassthruParserCallDriverDoubleBuffered(param_2,(longlong)(puVar5 + 2));
      puVar5 = puVar6;
    } while (puVar6 != (undefined8 *)0x0);
  } while( true );
}



===== PassthruParserGetWriteCache @ 1c000256c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PassthruParserGetWriteCache(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined1 auStackY_68 [32];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_20 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_28 = 0;
  local_38 = 4;
  iVar1 = PassthruParserSyncIo(param_1,param_2,0x2d1400,&local_38,0xc,0x1c);
  if (-1 < iVar1) {
    *param_2 = CONCAT44(uStack_34,local_38);
    param_2[1] = uStack_30;
    param_2[2] = uStack_28;
    *(undefined4 *)(param_2 + 3) = local_20;
    iVar1 = 0;
  }
  return iVar1;
}



===== PassthruParserScsiModeSelect @ 1c00025fc =====

int PassthruParserScsiModeSelect(longlong param_1,longlong param_2,longlong param_3,char param_4)

{
  undefined1 uVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  byte bVar6;
  uint uVar7;
  
  uVar7 = -(uint)(param_4 != '\0') & 4;
  if (param_4 == '\0') {
    uVar4 = (uint)*(byte *)(param_2 + 0x14);
  }
  else {
    uVar4 = (uint)(byte)*(ushort *)(param_2 + 0x17) << 8 | (uint)(*(ushort *)(param_2 + 0x17) >> 8);
  }
  if (((uVar7 + 0x10 <= uVar4) && (uVar4 == *(uint *)(param_2 + 0xc))) &&
     ((*(byte *)(param_2 + 0x11) & 1) == 0)) {
    if (param_4 == '\0') {
      uVar5 = (ulonglong)*(byte *)(param_3 + 3);
    }
    else {
      uVar5 = (ulonglong)
              ((uint)(byte)*(ushort *)(param_3 + 6) << 8 | (uint)(*(ushort *)(param_3 + 6) >> 8));
    }
    uVar7 = uVar7 + 4 + (int)uVar5;
    uVar3 = (ulonglong)uVar7;
    if (((uVar7 + 0xc <= uVar4) && ((*(byte *)(uVar3 + param_3) & 0x3f) == 8)) &&
       (9 < *(byte *)(uVar3 + 1 + param_3))) {
      bVar6 = *(byte *)(uVar3 + 2 + param_3) >> 2;
      iVar2 = PassthruParserSetWriteCache
                        (param_1,CONCAT71((int7)(uVar5 >> 8),bVar6) & 0xffffffffffffff01);
      if (iVar2 < 0) {
        return iVar2;
      }
      uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
      *(byte *)(param_1 + 0x5d) = bVar6 & 1;
      KeReleaseSpinLock(param_1 + 0x40,uVar1);
      return iVar2;
    }
  }
  return -0x3ffffff3;
}



===== PassthruParserScsiModeSense @ 1c0002714 =====

undefined8
PassthruParserScsiModeSense(longlong param_1,longlong param_2,short *param_3,char param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  void *_Dst;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  byte bVar10;
  byte bVar11;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  
  local_58 = 0;
  uStack_50 = 0;
  uVar7 = -(uint)(param_4 != '\0') & 4;
  uVar8 = uVar7 + 4;
  local_48 = 0;
  local_40 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),10,2,10,
                      &WPP_2923d26a91ab319f5e3d90e6d03b35b5_Traceguids,
                      *(byte *)(param_2 + 0x12) & 0x3f);
  }
  if (param_4 == '\0') {
    uVar6 = (uint)*(byte *)(param_2 + 0x14);
  }
  else {
    uVar6 = (uint)(byte)*(ushort *)(param_2 + 0x17) << 8 | (uint)(*(ushort *)(param_2 + 0x17) >> 8);
  }
  bVar1 = *(byte *)(param_2 + 0x12);
  bVar5 = bVar1 & 0x3f;
  if ((*(uint *)(param_2 + 0xc) < uVar6) || (uVar6 < 4)) {
    uVar9 = 0xc000000d;
  }
  else {
    memset(param_3,0,(ulonglong)*(uint *)(param_2 + 0xc));
    _Dst = (void *)((ulonglong)uVar8 + (longlong)param_3);
    *(uint *)(param_2 + 0xc) = uVar8;
    uVar2 = uVar8;
    if (uVar6 < uVar8) {
      uVar2 = uVar6;
    }
    iVar3 = PassthruParserGetWriteCache(param_1,&local_58);
    bVar11 = 0;
    if (-1 < iVar3) {
      bVar11 = 0;
      if (local_48._4_4_ == 2) {
        bVar11 = 0x10;
      }
    }
    bVar10 = bVar11 | 0x80;
    if (*(char *)(param_1 + 0x3b) == '\0') {
      bVar10 = bVar11;
    }
    if (param_4 == '\0') {
      *(byte *)(param_3 + 1) = bVar10;
    }
    else {
      *(byte *)((longlong)param_3 + 3) = bVar10;
    }
    if ((bVar1 & 0xc0) != 0xc0) {
      if ((bVar5 == 8) || (bVar5 == 0x3f)) {
        uVar4 = 0xc;
        if (uVar6 - uVar2 < 0xc) {
          uVar4 = uVar6 - uVar2;
        }
        memcpy(_Dst,&ModePageCaching,(ulonglong)uVar4);
        uVar4 = *(int *)(param_2 + 0xc) + uVar4;
        *(uint *)(param_2 + 0xc) = uVar4;
        if (uVar7 + 7 <= uVar4) {
          *(bool *)(param_1 + 0x5d) = uStack_50._4_4_ != 1;
          *(byte *)((longlong)_Dst + 2) =
               (uStack_50._4_4_ != 1) << 2 | *(byte *)((longlong)_Dst + 2) & 0xfb;
        }
        if (param_4 == '\0') {
          *(undefined1 *)param_3 = 0xf;
          return 0;
        }
        *param_3 = ((short)uVar8 + 10) * 0x100;
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)bVar11,2,0xb,
                          &WPP_2923d26a91ab319f5e3d90e6d03b35b5_Traceguids,bVar5);
      }
    }
    uVar9 = 0xc0000002;
  }
  return uVar9;
}



===== PassthruParserScsiOperation @ 1c0002954 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PassthruParserScsiOperation
                    (longlong param_1,longlong *param_2,longlong param_3,char param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  size_t _Size;
  char cVar6;
  undefined1 auStack_d8 [32];
  char local_a8;
  char local_a7;
  undefined2 local_98;
  byte local_96;
  undefined2 local_95;
  undefined1 local_93;
  byte local_92;
  undefined1 local_91;
  undefined1 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  longlong local_80;
  undefined4 local_78;
  undefined1 local_74 [20];
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_d8;
  local_a7 = param_4;
  memset(&local_98,0,0x50);
  lVar1 = *param_2;
  local_a8 = '\0';
  uVar5 = PassthruParserCheckMdlAlignment(param_1,param_2[2],&local_a8);
  cVar6 = local_a8;
  if ((int)uVar5 < 0) {
    return uVar5 & 0xffffffff;
  }
  if ((local_a8 == '\0') ||
     (ExAcquirePushLockExclusiveEx(param_1 + 0x90,0), *(uint *)(param_3 + 0xc) < 0x10001)) {
    IoInitializeIrp(lVar1 + 0x10,*(undefined2 *)(param_1 + 0x30),
                    CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x20) >> 8),
                             *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 0x4c)));
    uVar2 = *(undefined8 *)(param_1 + 0xa8);
    *(uint *)(lVar1 + 0x20) = *(uint *)(lVar1 + 0x20) | 1;
    lVar3 = *(longlong *)(lVar1 + 200);
    *(undefined8 *)(lVar1 + 0xa8) = uVar2;
    *(undefined8 *)(lVar3 + -0x20) = *(undefined8 *)(param_1 + 0x20);
    *(undefined1 *)(lVar3 + -0x48) = 0xe;
    if (local_a7 != '\0') {
      *(byte *)(lVar3 + -0x46) = *(byte *)(lVar3 + -0x46) | 4;
    }
    local_92 = *(byte *)(param_3 + 8);
    local_95 = 0xffff;
    _Size = 0x10;
    local_98 = 0x38;
    local_78 = 0x38;
    local_90 = *(undefined1 *)(param_3 + 10);
    local_8c = *(undefined4 *)(param_3 + 0xc);
    local_93 = 0xff;
    local_91 = 0x14;
    local_88 = 0x28;
    if (local_92 < 0x10) {
      _Size = (size_t)local_92;
    }
    memcpy(local_74,(void *)(param_3 + 0x10),_Size);
    *(undefined4 *)(lVar3 + -0x30) = 0x4d014;
    *(undefined4 *)(lVar3 + -0x38) = 0x50;
    *(undefined4 *)(lVar3 + -0x40) = 0x50;
    if (cVar6 == '\0') {
      lVar4 = param_2[2];
      *(longlong *)(lVar1 + 0x18) = lVar4;
      if (param_2[2] != 0) {
        if ((*(byte *)(lVar4 + 10) & 5) == 0) {
          local_80 = MmMapLockedPagesSpecifyCache(lVar4,0);
        }
        else {
          local_80 = *(longlong *)(lVar4 + 0x18);
        }
        if (local_80 == 0) {
          return 0xc000009a;
        }
      }
    }
    else {
      *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(param_1 + 0x70);
      local_80 = *(longlong *)(param_1 + 0x68);
    }
    *(undefined2 **)(lVar1 + 0x28) = &local_98;
    *(byte *)(lVar3 + -0x46) = *(byte *)(lVar3 + -0x46) | 2;
    if ((cVar6 != '\0') && (*(char *)(param_3 + 10) == '\0')) {
      PassthruParserDoubleBufferData
                (param_1,param_2[2],0,(ulonglong)*(uint *)(param_3 + 0xc),'\x01');
    }
    IoSynchronousCallDriver(*(undefined8 *)(lVar3 + -0x20),lVar1 + 0x10);
    uVar5 = (ulonglong)*(uint *)(lVar1 + 0x40);
    if ((int)*(uint *)(lVar1 + 0x40) < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      *(undefined4 *)(param_3 + 0xc) = 0;
    }
    else {
      if ((cVar6 != '\0') && (*(char *)(param_3 + 10) == '\x01')) {
        PassthruParserDoubleBufferData
                  (param_1,param_2[2],0,(ulonglong)*(uint *)(param_3 + 0xc),'\0');
      }
      *(byte *)(param_3 + 3) = local_96;
      *(byte *)(param_3 + 2) = (-(local_96 != 0) & 3U) + 1;
      *(undefined4 *)(param_3 + 0x10) = local_60;
      *(undefined4 *)(param_3 + 0x14) = uStack_5c;
      *(undefined4 *)(param_3 + 0x18) = uStack_58;
      *(undefined4 *)(param_3 + 0x1c) = uStack_54;
      *(undefined4 *)(param_3 + 0x20) = local_50;
      if ((byte)(((byte)local_60 & 0x7f) + 0x8e) < 2) {
        local_60._2_1_ = local_60._1_1_;
      }
      if ((local_60._2_1_ & 0xf) != 0) {
        *(undefined1 *)(param_3 + 2) = 0x84;
        *(byte *)(param_3 + 3) = local_96 | 2;
      }
      if (cVar6 != '\0') {
        ExReleasePushLockExclusiveEx(param_1 + 0x90,0);
        cVar6 = '\0';
      }
      *(undefined4 *)(param_3 + 0xc) = local_8c;
      PassthruParserUpdateSenseInfoFromSrb(param_1,param_3);
      VstorCompleteScsiRequest(param_2);
      uVar5 = 0x103;
    }
  }
  else {
    uVar5 = 0xc0000010;
  }
  if (cVar6 != '\0') {
    ExReleasePushLockExclusiveEx(param_1 + 0x90,0);
  }
  return uVar5;
}



===== PassthruParserScsiRequestSense @ 1c0002c80 =====

undefined8 PassthruParserScsiRequestSense(longlong param_1,longlong param_2,byte *param_3)

{
  byte *_Src;
  byte bVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  size_t _Size;
  
  bVar1 = *(byte *)(param_2 + 0x14);
  bVar4 = 0;
  if ((*(uint *)(param_2 + 0xc) < (uint)bVar1) || (bVar1 < 8)) {
    return 0xc000000d;
  }
  memset(param_3,0,(ulonglong)bVar1);
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x40);
  if ((*(char *)(param_1 + 0x5c) != '\0') && (_Src = (byte *)(param_1 + 0x48), _Src != (byte *)0x0))
  {
    bVar2 = false;
    if ((byte)((*_Src & 0x7f) + 0x8e) < 2) {
      if (param_1 + 0x50U <= param_1 + 0x5cU) {
        bVar4 = *(byte *)(param_1 + 0x49);
        goto LAB_1c0002d18;
      }
    }
    else if (param_1 + 0x50U <= param_1 + 0x5cU) {
      bVar4 = *(byte *)(param_1 + 0x4a);
LAB_1c0002d18:
      bVar2 = true;
      bVar4 = bVar4 & 0xf;
    }
    if ((bVar2) && (bVar4 != 0)) {
      _Size = 0x14;
      if (*(byte *)(param_2 + 0x14) < 0x15) {
        _Size = (size_t)*(byte *)(param_2 + 0x14);
      }
      memcpy(param_3,_Src,_Size);
      goto LAB_1c0002d55;
    }
  }
  param_3[7] = 10;
  param_3[2] = param_3[2] & 0xf0;
  *param_3 = *param_3 & 0xf0 | 0x70;
LAB_1c0002d55:
  KeReleaseSpinLock(param_1 + 0x40,uVar3);
  *(uint *)(param_2 + 0xc) = (uint)*(byte *)(param_2 + 0x14);
  return 0;
}



===== PassthruParserSetWriteCache @ 1c0002da0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PassthruParserSetWriteCache(longlong param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  undefined7 uVar5;
  bool bVar6;
  undefined1 auStackY_68 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  cVar3 = (char)param_2;
  uVar5 = (undefined7)((ulonglong)param_2 >> 8);
  local_20 = __security_cookie ^ (ulonglong)auStackY_68;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  cVar4 = cVar3;
  iVar1 = PassthruParserSyncIo(param_1,param_2,0x740d4,&local_38,0,0x18);
  if (iVar1 < 0) {
    iVar2 = 0;
    if (cVar3 == '\0') {
      iVar2 = iVar1;
    }
  }
  else {
    bVar6 = local_38._2_1_ != '\0';
    if (bVar6 == (cVar3 != '\0')) {
      iVar2 = 0;
    }
    else {
      local_38._0_3_ = CONCAT12(cVar3 != '\0',(undefined2)local_38);
      iVar2 = PassthruParserSyncIo(param_1,CONCAT71(uVar5,cVar4),0x7c0d8,&local_38,0x18,0);
      if (((iVar2 < 0) && (!bVar6)) && (cVar3 != '\0')) {
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}



===== WPP_RECORDER_SF_DD @ 1c0002e74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2923d26a91ab319f5e3d90e6d03b35b5_Traceguids,0xe,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_2923d26a91ab319f5e3d90e6d03b35b5_Traceguids,0xe,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_Dq @ 1c0002f44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2923d26a91ab319f5e3d90e6d03b35b5_Traceguids,0xd,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2923d26a91ab319f5e3d90e6d03b35b5_Traceguids,0xd,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1c0003018 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2923d26a91ab319f5e3d90e6d03b35b5_Traceguids,0xc,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_2923d26a91ab319f5e3d90e6d03b35b5_Traceguids,0xc,
                  &uStack0000000000000030,4,0);
  return;
}



===== DvInitializeWorkQueue @ 1c00030c0 =====

void DvInitializeWorkQueue(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}



===== DvpRemoveWorkQueueRunningDown @ 1c00030cc =====

longlong DvpRemoveWorkQueueRunningDown(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *param_1;
  lVar2 = *(longlong *)(lVar1 + 0x16);
  *(undefined8 *)(lVar1 + 0x16) = 0;
  if (lVar2 == 0) {
    *param_1 = 0;
    KeSetEvent(lVar1 + -2,0,0);
  }
  return lVar2;
}



===== _guard_check_icall @ 1c0003120 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0003138 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000315c =====

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



===== __cpu_features_init @ 1c00031d0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000323a) */
/* WARNING: Removing unreachable block (ram,0x0001c00031e9) */
/* WARNING: Removing unreachable block (ram,0x0001c00031da) */

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



===== __security_check_cookie @ 1c00032a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00032e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0003310 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0003310. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003340 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c00033c0 =====

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



===== memset @ 1c00036c0 =====

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



===== __memset_repmovs @ 1c0003800 =====

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



===== __memset_query @ 1c0003880 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0003900 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003a40 =====

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



===== __memset_spec_plain @ 1c0003ac0 =====

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



===== PassthruParserAlterDeviceOwnership @ 1c0009008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PassthruParserAlterDeviceOwnership(longlong param_1,undefined8 param_2)

{
  int iVar1;
  char cVar2;
  undefined1 auStackY_68 [32];
  undefined4 local_38;
  undefined1 local_34;
  undefined1 local_33;
  undefined8 local_32;
  undefined8 uStack_2a;
  undefined2 local_22;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  cVar2 = (char)param_2;
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  if ((*(char *)(param_1 + 0x3c) == '\0') &&
     ((cVar2 != '\0') != (*(char *)(param_1 + 0x38) != '\0'))) {
    local_34 = 0;
    local_32 = 0;
    uStack_2a = 0;
    local_33 = cVar2 == '\0';
    local_22 = 0;
    local_38 = 0x28;
    local_20 = 0x4d965694ad57a459;
    uStack_18 = 0x840334b5efb66d89;
    iVar1 = PassthruParserSyncIo(param_1,param_2,0x7c0f4,&local_38,0x28,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    *(char *)(param_1 + 0x38) = cVar2;
  }
  return 0;
}



===== PassthruParserCloseDisk @ 1c00090d0 =====

void PassthruParserCloseDisk(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x11);
  }
  PassthruParserAlterDeviceOwnership((longlong)param_1,0);
  ContextListRemove(param_1);
  DvRundownWorkQueue((ulonglong *)(param_1 + 0x11));
  if (param_1[0x14] != 0) {
    MmFreeMappingAddress(param_1[0x14],0x73725056);
    param_1[0x14] = 0;
  }
  if (param_1[0x13] != 0) {
    ExFreePoolWithTag(param_1[0x13],0x73725056);
    param_1[0x13] = 0;
  }
  if (param_1[0x10] != 0) {
    IoFreeWorkItem();
    param_1[0x10] = 0;
  }
  if (param_1[0xf] != 0) {
    IoFreeIrp();
    param_1[0xf] = 0;
  }
  if (param_1[0xe] != 0) {
    IoFreeMdl();
    param_1[0xe] = 0;
  }
  if (param_1[0xd] != 0) {
    ExFreePoolWithTag(param_1[0xd],0x73725056);
    param_1[0xd] = 0;
  }
  if (param_1[0x16] != 0) {
    IoFreeIrp();
    param_1[0x16] = 0;
  }
  if (param_1[3] != 0) {
    ObfDereferenceObject();
    param_1[3] = 0;
  }
  if (param_1[4] != 0) {
    ObfDereferenceObject();
    param_1[4] = 0;
  }
  if (param_1[2] != 0) {
    ZwClose();
    param_1[2] = 0;
  }
  if (param_1[0x15] != 0) {
    ObfDereferenceObject();
    param_1[0x15] = 0;
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PassthruParserDismountDisk @ 1c0009290 =====

void PassthruParserDismountDisk(longlong param_1)

{
  PassthruParserAlterDeviceOwnership(param_1,0);
  *(undefined1 *)(param_1 + 0x39) = 0;
  return;
}



===== PassthruParserMountDisk @ 1c00092c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PassthruParserMountDisk(longlong param_1,ulonglong param_2,undefined8 param_3,int *param_4)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 0;
  uStack_20 = 0;
  uVar3 = param_2;
  iVar2 = PassthruParserSyncIo(param_1,param_2,0x700f0,&local_28,0,0x10);
  if (-1 < iVar2) {
    if ((uStack_20 & 1) == 0) {
      iVar2 = -0x3fffffde;
    }
    else if (((param_2 & 1) == 0) || ((*(uint *)(param_1 + 0x28) & 0x40000000) == 0)) {
      iVar2 = PassthruParserAlterDeviceOwnership
                        (param_1,CONCAT44((int)(uVar3 >> 0x20),CONCAT31((int3)(uVar3 >> 8),1)));
      if (-1 < iVar2) {
        uVar1 = *(ushort *)(param_1 + 0x30);
        *(undefined1 *)(param_4 + 1) = 1;
        *param_4 = uVar1 + 0x10;
        iVar2 = 0;
        *(undefined1 *)(param_1 + 0x39) = 1;
      }
    }
    else {
      iVar2 = -0x3ffffff3;
    }
  }
  return iVar2;
}



===== PassthruParserOpenDisk @ 1c0009380 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PassthruParserOpenDisk
                    (undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 *param_5)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  ulonglong uVar7;
  short sVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  undefined2 uVar12;
  uint uVar13;
  longlong lVar14;
  bool bVar15;
  undefined1 auStackY_148 [32];
  undefined1 local_d8 [8];
  longlong local_d0;
  longlong local_c8;
  undefined8 *local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_148;
  local_c0 = param_5;
  local_a8 = 0;
  local_a0 = 0;
  local_94 = 0;
  local_7c = 0;
  lVar14 = 0;
  local_68 = 0;
  uStack_60 = 0;
  plVar6 = (longlong *)0x0;
  local_d0 = 0;
  local_d8[0] = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0xd);
  }
  puVar11 = &local_98;
  *param_5 = 0;
  bVar15 = true;
  local_98 = 0x30;
  local_90 = 0;
  uVar13 = ~(param_2 << 0x1c) & 0xc0000000 | 0x80000000;
  local_80 = 0x240;
  puVar9 = (undefined8 *)(ulonglong)uVar13;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = param_1;
  uVar2 = IoCreateFile(&local_d0,puVar9,puVar11,&local_68);
  uVar10 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000986e;
    uVar12 = 0xe;
  }
  else {
    puVar9 = (undefined8 *)0x0;
    local_c8 = 0;
    puVar11 = *(undefined4 **)IoFileObjectType_exref;
    uVar2 = ObReferenceObjectByHandle(local_d0,0,puVar11,0);
    lVar14 = local_c8;
    uVar10 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      lVar5 = IoGetAttachedDeviceReference(*(undefined8 *)(local_c8 + 8));
      if (*(int *)(lVar5 + 0x48) != 7) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          puVar11 = (undefined4 *)0x1;
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar9,1,0x10,
                            &WPP_ba75710c351a3ce3bfdb948128598e04_Traceguids,
                            (char)*(int *)(lVar5 + 0x48));
        }
        uVar10 = 0xc000000d;
        goto LAB_1c000986e;
      }
      puVar9 = (undefined8 *)0xc0;
      puVar11 = (undefined4 *)0x73725056;
      plVar6 = (longlong *)ExAllocatePool2(0x40);
      if (plVar6 != (longlong *)0x0) {
        plVar6[2] = local_d0;
        plVar6[3] = lVar14;
        plVar6[4] = lVar5;
        *(undefined4 *)((longlong)plVar6 + 0x34) = *(undefined4 *)(*(longlong *)(lVar14 + 8) + 0x48)
        ;
        *(uint *)(plVar6 + 5) = uVar13;
        *(undefined4 *)(plVar6 + 0xc) = 3;
        plVar6[0x15] = (longlong)SystemReserved1[0xf];
        ObfReferenceObject();
        local_d0 = 0;
        lVar14 = 0;
        KeInitializeSpinLock(plVar6 + 8);
        plVar6[0x12] = 0;
        DvInitializeWorkQueue(plVar6 + 0x11);
        puVar11 = (undefined4 *)plVar6[4];
        puVar9 = (undefined8 *)0x0;
        cVar1 = *(char *)(puVar11 + 0x13);
        sVar8 = cVar1 * 0x48 + 0xd0;
        *(short *)(plVar6 + 6) = sVar8;
        lVar5 = IoAllocateIrp(CONCAT31((int3)(CONCAT22((short)((uint)(int)cVar1 >> 0x10),sVar8) >> 8
                                             ),*(undefined1 *)(puVar11 + 0x13)));
        plVar6[0x16] = lVar5;
        if (lVar5 != 0) {
          puVar9 = (undefined8 *)plVar6[4];
          plVar6[0x17] = 0;
          uVar3 = PassthruParserIsDoubleBufferingRequired(0xfffffffe,(longlong)puVar9);
          if ((char)uVar3 == '\0') {
LAB_1c00097a2:
            if ((param_2 & 1) != 0) {
LAB_1c00098bd:
              *local_c0 = plVar6;
              return uVar10;
            }
            puVar11 = (undefined4 *)0x700f8;
            uVar2 = PassthruParserSyncIo((longlong)plVar6,puVar9,0x700f8,local_d8,0,1);
            uVar10 = (ulonglong)uVar2;
            if (-1 < (int)uVar2) {
              *(undefined1 *)((longlong)plVar6 + 0x3c) = local_d8[0];
              puVar11 = (undefined4 *)0x700a0;
              local_38 = 0;
              local_58 = 0;
              uStack_50 = 0;
              local_48 = 0;
              uStack_40 = 0;
              uVar2 = PassthruParserSyncIo((longlong)plVar6,puVar9,0x700a0,&local_58,0,0x28);
              uVar10 = (ulonglong)uVar2;
              if (-1 < (int)uVar2) {
                *(int *)((longlong)plVar6 + 0x2c) = local_48._4_4_;
                if (local_48._4_4_ == 0) {
                  uVar10 = 0xc00000e5;
                }
                else {
                  puVar11 = (undefined4 *)0x70024;
                  iVar4 = PassthruParserSyncIo((longlong)plVar6,puVar9,0x70024,0,0,0);
                  if (iVar4 == -0x3fffff5e) {
                    *(undefined1 *)((longlong)plVar6 + 0x3b) = 1;
                  }
                  puVar9 = &local_b8;
                  iVar4 = PassthruParserGetWriteCache((longlong)plVar6,puVar9);
                  if (-1 < iVar4) {
                    bVar15 = uStack_b0._4_4_ != 1;
                  }
                  *(bool *)((longlong)plVar6 + 0x5d) = bVar15;
                  uVar7 = ContextListAdd(plVar6);
                  uVar10 = uVar7 & 0xffffffff;
                  if (-1 < (int)uVar7) goto LAB_1c00098bd;
                }
              }
            }
            goto LAB_1c000986e;
          }
          puVar11 = (undefined4 *)0x73725056;
          puVar9 = (undefined8 *)0x10000;
          lVar5 = ExAllocatePool2(0x40);
          plVar6[0xd] = lVar5;
          if (lVar5 != 0) {
            puVar11 = (undefined4 *)0x0;
            puVar9 = (undefined8 *)0x10000;
            lVar5 = IoAllocateMdl(lVar5,0x10000,0,0);
            plVar6[0xe] = lVar5;
            if (lVar5 != 0) {
              MmBuildMdlForNonPagedPool(lVar5);
              puVar9 = (undefined8 *)0x0;
              lVar5 = IoAllocateIrp(CONCAT71((int7)((ulonglong)plVar6[4] >> 8),
                                             *(undefined1 *)(plVar6[4] + 0x4c)));
              plVar6[0xf] = lVar5;
              if (lVar5 != 0) {
                uVar2 = MmSizeOfMdl(0xfff,0x800000);
                puVar9 = (undefined8 *)(ulonglong)uVar2;
                puVar11 = (undefined4 *)0x73725056;
                lVar5 = ExAllocatePool2(0x40);
                plVar6[0x13] = lVar5;
                if (lVar5 != 0) {
                  puVar9 = (undefined8 *)0x73725056;
                  lVar5 = MmAllocateMappingAddress(0x11000);
                  plVar6[0x14] = lVar5;
                  if (lVar5 != 0) {
                    lVar5 = IoAllocateWorkItem(ParserDriverObject);
                    plVar6[0x10] = lVar5;
                    if (lVar5 != 0) goto LAB_1c00097a2;
                  }
                }
              }
            }
          }
        }
      }
      uVar10 = 0xc000009a;
      goto LAB_1c000986e;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000986e;
    uVar12 = 0xf;
  }
  puVar9 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar9 >> 8),2);
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar11,uVar12);
LAB_1c000986e:
  if (local_d0 != 0) {
    ZwClose();
  }
  if (lVar14 != 0) {
    ObfDereferenceObject(lVar14);
  }
  if (plVar6 != (longlong *)0x0) {
    PassthruParserCloseDisk(plVar6,puVar9,puVar11);
  }
  if (((int)uVar10 == -0x3fffffcc) || ((int)uVar10 == -0x3fffffc6)) {
    uVar10 = 0xe03a0019;
  }
  return uVar10;
}



===== PassthruParserQueryBehaviorDisk @ 1c0009900 =====

undefined8
PassthruParserQueryBehaviorDisk
          (longlong param_1,int param_2,undefined1 *param_3,int param_4,undefined4 *param_5)

{
  if (param_2 != 1) {
    return 0xc0000010;
  }
  if (param_4 == 0) {
    return 0xc000000d;
  }
  *param_3 = 0;
  *param_3 = *(undefined1 *)(param_1 + 0x5d);
  *param_5 = 1;
  return 0;
}



===== PassthruParserQueryInformationDisk @ 1c0009940 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PassthruParserQueryInformationDisk
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5,uint *param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStackY_88 [32];
  undefined4 local_58;
  undefined4 local_54;
  ulonglong local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  if ((int)param_2 == 1) {
    local_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    local_50 = 0;
    uStack_48 = 0;
    if (*param_6 < 0x10) {
      iVar1 = -0x3fffffdd;
    }
    else {
      *param_5 = 0;
      param_5[1] = 0;
      iVar1 = PassthruParserSyncIo(param_1,param_2,0x700a0,&local_38,0,0x28);
      if (-1 < iVar1) {
        local_50 = local_50 & 0xffffffff00000000;
        local_54 = 0;
        *(undefined4 *)(param_5 + 1) = local_28._4_4_;
        *param_5 = uStack_20;
        local_58 = 6;
        iVar1 = PassthruParserSyncIo(param_1,param_2,0x2d1400,&local_58,0xc,0x1c);
        uVar2 = 0;
        if (-1 < iVar1) {
          uVar2 = uStack_48._4_4_;
        }
        iVar1 = 0;
        *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
        *param_6 = 0x10;
      }
    }
  }
  else {
    iVar1 = -0x3ffffff0;
  }
  return iVar1;
}



===== PassthruParserQueryMountStatusDisk @ 1c0009a50 =====

undefined8 PassthruParserQueryMountStatusDisk(void)

{
  return 0;
}



===== PassthruParserQuerySaveVersionDisk @ 1c0009a60 =====

undefined8 PassthruParserQuerySaveVersionDisk(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 3;
  return 0;
}



===== PassthruParserRestoreDisk @ 1c0009a70 =====

int PassthruParserRestoreDisk(longlong param_1,undefined8 param_2,undefined8 *param_3,int param_4)

{
  undefined8 uVar1;
  int iVar2;
  
  if ((int)param_2 == 3) {
    if (param_4 == 0x17) {
      iVar2 = PassthruParserSetWriteCache
                        (param_1,CONCAT44((int)((ulonglong)param_2 >> 0x20),
                                          CONCAT31((int3)((ulonglong)param_2 >> 8),
                                                   *(undefined1 *)((longlong)param_3 + 0x15))));
      if (-1 < iVar2) {
        uVar1 = param_3[1];
        *(undefined8 *)(param_1 + 0x48) = *param_3;
        *(undefined8 *)(param_1 + 0x50) = uVar1;
        *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_3 + 2);
        *(undefined2 *)(param_1 + 0x5c) = *(undefined2 *)((longlong)param_3 + 0x14);
        *(undefined1 *)(param_1 + 0x5e) = *(undefined1 *)((longlong)param_3 + 0x16);
        iVar2 = 0;
      }
    }
    else {
      iVar2 = -0x3ffffdfa;
    }
  }
  else {
    iVar2 = -0x3ffffff3;
  }
  return iVar2;
}



===== PassthruParserSaveDisk @ 1c0009ae0 =====

undefined8
PassthruParserSaveDisk(longlong param_1,undefined8 *param_2,uint param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  
  if (param_3 < 0x17) {
    return 0xc0000023;
  }
  uVar1 = *(undefined8 *)(param_1 + 0x50);
  *param_2 = *(undefined8 *)(param_1 + 0x48);
  param_2[1] = uVar1;
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)(param_1 + 0x58);
  *(undefined2 *)((longlong)param_2 + 0x14) = *(undefined2 *)(param_1 + 0x5c);
  *(undefined1 *)((longlong)param_2 + 0x16) = *(undefined1 *)(param_1 + 0x5e);
  *param_4 = 0x17;
  return 0;
}



===== PassthruParserUnload @ 1c0009b20 =====

void PassthruParserUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0xc);
  }
  WppCleanupKm(param_1);
  return;
}



===== WppCleanupKm @ 1c0009b68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0x10)) {
        if (*(longlong *)(puVar1 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar1 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 1c0009c18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar2 + 0x38) = 0;
        (*pcVar1)(*(undefined8 *)(puVar2 + 8),0,WppClassicProviderCallback,puVar2,puVar2 + 0x38);
        puVar2 = *(undefined **)(puVar2 + 0x10);
      } while (puVar2 != (undefined *)0x0);
    }
    else if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 1c0009cf4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"PsGetVersion");
  pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(&local_18);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 1c0009e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  uint *puVar1;
  undefined8 uVar2;
  ushort *puVar3;
  undefined8 uVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined4 local_res8 [2];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar1 = param_6;
  *param_6 = 0;
  if (param_1 < 6) {
    if ((param_1 == 5) ||
       ((((param_1 != 0 && (param_1 != 1)) && (param_1 != 2)) && ((param_1 != 3 && (param_1 == 4))))
       )) {
      local_res8[0] = 0;
      param_6._0_4_ = 0;
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          puVar1 = *(uint **)(param_5 + 8);
          if (((*puVar1 == param_4[6]) && (puVar1[1] == param_4[7])) &&
             ((puVar1[2] == param_4[8] && (puVar1[3] == param_4[9])))) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
            *(undefined1 *)(param_5 + 0x29) = 0;
            return 0;
          }
          bVar13 = WPPTraceSuite != 2;
          uVar2 = *(undefined8 *)(param_4 + 2);
          *(undefined8 *)(param_5 + 0x18) = uVar2;
          if (bVar13) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)(param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
            *(undefined1 *)(param_5 + 0x29) = uStack_36;
            return 0;
          }
          iVar5 = (*pfnWppQueryTraceInformation)(3,local_res8,4,&param_6,param_4);
          if (iVar5 == 0) {
            *(undefined1 *)(param_5 + 0x29) = (undefined1)local_res8[0];
          }
          uVar6 = (*pfnWppQueryTraceInformation)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar6;
        }
      }
      return 0xc0000295;
    }
  }
  else {
    if (param_1 == 6) {
      return 0;
    }
    if (param_1 == 7) {
      return 0;
    }
    if (param_1 == 8) {
      uVar10 = 0;
      puVar3 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar10 = uVar10 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar10) {
        return 0xc000000d;
      }
      uVar11 = uVar10 * 0x20 + 0x18;
      if (puVar3 == (ushort *)0x0) {
        uVar12 = uVar11;
        uVar11 = 0;
      }
      else {
        uVar12 = *puVar3 + 2 + uVar11;
      }
      if (param_3 < uVar12) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar12;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar12;
      param_4[2] = uVar11;
      param_4[4] = uVar10;
      if (puVar3 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar11 + (longlong)param_4) = *puVar3;
        memcpy((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
               (ulonglong)*puVar3);
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar9 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar4 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar9 = 0x81000;
          *(undefined8 *)(puVar9 + -4) = uVar2;
          *(undefined8 *)(puVar9 + -2) = uVar4;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 8;
        } while (uVar8 != 0);
      }
      *puVar1 = uVar12;
      return 0;
    }
  }
  return 0xc0000010;
}



===== DvRundownWorkQueue @ 1c000a0c8 =====

void DvRundownWorkQueue(ulonglong *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  bool bVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  uVar2 = *param_1;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (uVar2 != 0) {
    KeInitializeEvent(&local_28,0,0);
    do {
      if (uVar2 == 0) {
        return;
      }
      uStack_10 = uVar2 & 0xfffffffffffffffe;
      LOCK();
      if (uVar2 == *param_1) {
        *param_1 = (longlong)&local_28 + 2;
        uVar1 = uVar2;
      }
      else {
        uVar1 = *param_1;
      }
      UNLOCK();
      bVar3 = uVar1 != uVar2;
      uVar2 = uVar1;
    } while (bVar3);
    KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  return;
}



===== entry @ 1c000b010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000b044 =====

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



===== DriverEntry @ 1c000b078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_1a8 [48];
  short *local_178 [2];
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  longlong local_150;
  code *local_148;
  code *local_140;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e8;
  code *local_48;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1a8;
  memset(&local_168,0,0x140);
  _DAT_1c0006148 = 1;
  local_178[0] = (short *)0x0;
  DAT_1c0006128 = &WPP_ThisDir_CTLGUID_PassthruparserTraceGuid;
  _WPP_MAIN_CB = 0;
  DAT_1c0006130 = 0;
  _DAT_1c0006140 = 0;
  _DAT_1c0006160 = 0;
  _DAT_1c0006168 = 0;
  WppLoadTracingSupport();
  _DAT_1c0006140 = 0;
  WppInitKm(param_1,param_2);
  uVar2 = 0;
  *(code **)(param_1 + 0x68) = PassthruParserUnload;
  iVar1 = IoGetDeviceInterfaces(&GUID_STORVSP,0,0,local_178);
  if (iVar1 < 0) {
LAB_1c000b27f:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar2,10);
      if (-1 < iVar1) goto LAB_1c000b2b3;
    }
  }
  else {
    if (*local_178[0] == 0) {
      iVar1 = -0x3ffffddb;
      goto LAB_1c000b27f;
    }
    ParserDriverObject = param_1;
    KeInitializeSpinLock(&ContextListSpinLock);
    local_168 = 0x140;
    _DAT_1c00060d8 = &ContextListHead;
    ContextListHead = &ContextListHead;
    local_148 = PassthruParserOpenDisk;
    local_130 = PassthruParserMountDisk;
    local_128 = PassthruParserDismountDisk;
    local_140 = PassthruParserCloseDisk;
    local_120 = PassthruParserQueryMountStatusDisk;
    local_118 = PassthruParserExecuteScsiRequestDisk;
    local_110 = PassthruParserQueryInformationDisk;
    local_e8 = PassthruParserQueryBehaviorDisk;
    local_f0 = PassthruParserSetBehaviorDisk;
    local_108 = PassthruParserQuerySaveVersionDisk;
    local_100 = PassthruParserSaveDisk;
    local_f8 = PassthruParserRestoreDisk;
    local_48 = PassthruParserSupportsDataTransferDirectionValidation;
    local_164 = 6;
    local_160 = 0x5c8717a1;
    uStack_15c = 0x4f6ffd1c;
    uStack_158 = 0xbed68e9a;
    uStack_154 = 0xb7526920;
    local_150 = param_1;
    iVar1 = VstorRegisterParser(&local_168);
    if (-1 < iVar1) goto LAB_1c000b2b3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar2,0xb);
    }
  }
  WppCleanupKm(param_1);
LAB_1c000b2b3:
  if (local_178[0] != (short *)0x0) {
    ExFreePoolWithTag(local_178[0],0);
  }
  return iVar1;
}


