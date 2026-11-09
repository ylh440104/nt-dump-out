
===== iscsiBootCancel @ 140001000 =====

undefined8 iscsiBootCancel(void)

{
  return 0;
}



===== CrashDumpBuildIo @ 140001010 =====

undefined1 CrashDumpBuildIo(void)

{
  return 1;
}



===== CrashDumpDoLogin @ 140001014 =====

char CrashDumpDoLogin(ushort *param_1,longlong param_2,int param_3)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iscsiSessionStart(param_1,param_2,param_3);
    puVar1 = iscsiAddTimer(*(undefined2 *)(iscsiGlobalsPtr + 0xd80),iscsiAbortRoutine);
    *(undefined1 *)(iscsiGlobalsPtr + 0xd82) = 0;
    while (*(char *)(iscsiGlobalsPtr + 0xd82) == '\0') {
      iscsiProcessLoop(1);
      if (*(char *)(iscsiGlobalsPtr + 0x70) == '\x03') {
        return '\0';
      }
    }
    if (*(short *)(iscsiGlobalsPtr + 0x2c) == 0x20a) {
      StorPortStallExecution(15000000);
    }
    iscsiDelTimer(puVar1);
    iscsiSessionStop((longlong)param_1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return -((char)param_1[0x34] != '\x03');
}



===== CrashDumpExecuteiSCSICommand @ 1400010f4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char CrashDumpExecuteiSCSICommand
               (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  char cVar4;
  char cVar5;
  undefined8 uVar6;
  
  cVar4 = '\x06';
  iscsiGetTicks();
  cVar5 = *(char *)(param_2 + 0x48);
  if (cVar5 == '\x03') {
    uVar6 = CrashDumpIscsiDoRequestSense(param_1,param_2,param_3,param_4);
    cVar4 = (char)uVar6;
  }
  else if (cVar5 == '\b') {
LAB_1400011f3:
    uVar6 = CrashDumpIscsiDoRead(param_1,param_2);
    cVar4 = (char)uVar6;
  }
  else if (cVar5 == '\x12') {
    uVar6 = CrashDumpIscsiDoRead(param_1,param_2);
    cVar4 = (char)uVar6;
  }
  else {
    if (cVar5 == '\x1b') {
      return '\x01';
    }
    if (cVar5 == '%') {
      uVar6 = CrashDumpIscsiDoReadCapacity(param_1,param_2);
      cVar4 = (char)uVar6;
    }
    else {
      if (cVar5 == '(') goto LAB_1400011f3;
      if (cVar5 == '*') {
        uVar6 = CrashDumpIscsiDoWrite(param_1,param_2);
        puVar3 = DAT_140075a40;
        cVar4 = (char)uVar6;
        if (cVar4 == '\x01') {
          _DAT_140074658 = _DAT_140074658 + 1;
          _DAT_14007465c = _DAT_14007465c + *(int *)(param_2 + 0x10);
          return '\x01';
        }
        if (*(char *)(param_2 + 4) != '\x02') {
          pcVar2 = (code *)swi(3);
          cVar5 = (*pcVar2)();
          return cVar5;
        }
        if ((*(longlong *)(iscsiGlobalsPtr + 0xd90) != 0) &&
           (puVar1 = *(undefined8 **)(param_2 + 0x20), puVar1 != (undefined8 *)0x0)) {
          uVar6 = DAT_140075a40[1];
          *puVar1 = *DAT_140075a40;
          puVar1[1] = uVar6;
          *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(puVar3 + 2);
        }
      }
      else if (cVar5 == '/') {
        uVar6 = CrashDumpIscsiDoVerify(param_1,param_2);
        cVar4 = (char)uVar6;
      }
      else {
        if (cVar5 != '5') goto LAB_140001214;
        uVar6 = CrashDumpIscsiDoSyncCache(param_1,param_2);
        cVar4 = (char)uVar6;
      }
    }
  }
  if (cVar4 == '\x01') {
    return '\x01';
  }
LAB_140001214:
  _DAT_140074670 = 0;
  _DAT_14007466c = 0;
  _DAT_140074668 = (uint)*(byte *)(param_2 + 0x48);
  _DAT_140074664 = 0xc0000002;
  return cVar4;
}



===== CrashDumpExtractiSCSIFromDumpPoint @ 14000124c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CrashDumpExtractiSCSIFromDumpPoint(longlong param_1)

{
  char *pcVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  byte *pbVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x6c70);
  DAT_140075a60 = 1;
  pcVar1 = (char *)(lVar2 + 0x98);
  iVar5 = istrlen(pcVar1);
  memmove(&DAT_140075c60,pcVar1,(longlong)iVar5);
  iVar5 = istrlen(pcVar1);
  (&DAT_140075c60)[iVar5] = 0;
  if (*(char *)(lVar2 + 0x94) == '\0') {
    _DAT_140075eb8 = *(undefined8 *)(lVar2 + 0x34);
    uRam0000000140075ec0 = *(undefined8 *)(lVar2 + 0x3c);
    DAT_140075add = '\x01';
    _DAT_140075ee8 = _DAT_140075eb8;
    uRam0000000140075ef0 = uRam0000000140075ec0;
    cVar4 = getPrefixlen(lVar2 + 0x44);
    _DAT_140075ec8 = CONCAT31(DAT_140075ec8_1,cVar4);
    _DAT_140075ed8 = *(undefined8 *)(lVar2 + 0x54);
    uRam0000000140075ee0 = *(undefined8 *)(lVar2 + 0x5c);
    _DAT_140075f08 = *(undefined8 *)(lVar2 + 100);
    uRam0000000140075f10 = *(undefined8 *)(lVar2 + 0x6c);
    _DAT_140075f18 = *(undefined8 *)(lVar2 + 0x74);
    uRam0000000140075f20 = *(undefined8 *)(lVar2 + 0x7c);
    _DAT_140075ef8 = *(undefined8 *)(lVar2 + 0x84);
    uRam0000000140075f00 = *(undefined8 *)(lVar2 + 0x8c);
  }
  else {
    _DAT_140075eb8 = CONCAT44(DAT_140075eb8_4,*(undefined4 *)(lVar2 + 0x1c));
    DAT_140075add = '\0';
    _DAT_140075ee8 = _DAT_140075eb8;
    uRam0000000140075ef0 = uRam0000000140075ec0;
    _DAT_140075ec8 = *(undefined4 *)(lVar2 + 0x20);
    _DAT_140075ed8 = CONCAT44(DAT_140075ed8_4,*(undefined4 *)(lVar2 + 0x24));
    _DAT_140075f08 = CONCAT44(DAT_140075f08_4,*(undefined4 *)(lVar2 + 0x28));
    _DAT_140075f18 = CONCAT44(DAT_140075f18_4,*(undefined4 *)(lVar2 + 0x2c));
    _DAT_140075ef8 = CONCAT44(DAT_140075ef8_4,*(undefined4 *)(lVar2 + 0x30));
  }
  DAT_140075f28 = *(undefined2 *)(lVar2 + 0x96);
  DAT_140075a6e = *(undefined2 *)(lVar2 + 0x14);
  if (*(char *)(lVar2 + 0x309) != '\0') {
    DAT_140075a64 = DAT_140075a64 | 0x10000;
    pcVar1 = (char *)(lVar2 + 0x3ea);
    iVar5 = istrlen(pcVar1);
    memmove(&DAT_140075e06,pcVar1,(longlong)iVar5);
    iVar5 = istrlen(pcVar1);
    (&DAT_140075e06)[iVar5] = 0;
    _DAT_140075e87 = *(undefined8 *)(lVar2 + 0x4ea);
    uRam0000000140075e8f = *(undefined8 *)(lVar2 + 0x4f2);
    DAT_140075e97 = 0;
    if (*(char *)(lVar2 + 0x309) == '\x02') {
      pcVar1 = (char *)(lVar2 + 0x177);
      iVar5 = istrlen(pcVar1);
      memmove(&DAT_140075ce2 + (ulonglong)DAT_140075ce1 * 0x81,pcVar1,(longlong)iVar5);
      iVar5 = istrlen(pcVar1);
      (&DAT_140075ce2)[(ulonglong)DAT_140075ce1 * 0x81 + (longlong)iVar5] = 0;
      uVar6 = (ulonglong)DAT_140075ce1;
      uVar3 = *(undefined8 *)(lVar2 + 0x27f);
      *(undefined8 *)(&DAT_140075de4 + uVar6 * 0x11) = *(undefined8 *)(lVar2 + 0x277);
      *(undefined8 *)(uVar6 * 0x11 + 0x140075dec) = uVar3;
      (&DAT_140075df4)[(ulonglong)DAT_140075ce1 * 0x11] = 0;
    }
  }
  lVar7 = (ulonglong)DAT_140075ce1 * 0xc0;
  pbVar8 = &DAT_140075ae0 + lVar7;
  *pbVar8 = *pbVar8 | 1;
  if (DAT_140075add == '\x01') {
    uVar3 = *(undefined8 *)(lVar2 + 0x2a7);
    *(undefined8 *)(&DAT_140075ae4 + lVar7) = *(undefined8 *)(lVar2 + 0x29f);
    *(undefined8 *)(lVar7 + 0x140075aec) = uVar3;
  }
  else {
    *(undefined4 *)(&DAT_140075ae4 + lVar7) = *(undefined4 *)(lVar2 + 0x287);
  }
  *(ushort *)(&DAT_140075af4 + lVar7) =
       *(short *)(lVar2 + 0x307) << 8 | (ushort)*(byte *)(lVar2 + 0x308);
  isprintf((char *)(lVar7 + 0x140075b77),"%x-%x-%x-%x",(ulonglong)*(ushort *)(lVar2 + 0x2ff),
           (ulonglong)*(ushort *)(lVar2 + 0x301));
  pcVar1 = (char *)(lVar2 + 0x30b);
  iVar5 = istrlen(pcVar1);
  memmove((void *)(lVar7 + 0x140075af6),pcVar1,(longlong)iVar5);
  iVar5 = istrlen(pcVar1);
  pbVar8[(longlong)iVar5 + 0x16] = 0;
  DAT_140075ce1 = DAT_140075ce1 + 1;
  DAT_140075f80 = 0;
  return;
}



===== CrashDumpExtractiSCSIFromiBFT @ 14000153c =====

void CrashDumpExtractiSCSIFromiBFT(longlong param_1)

{
  undefined8 *puVar1;
  char cVar2;
  byte bVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  ushort uVar6;
  byte bVar7;
  uint uVar8;
  longlong lVar9;
  byte *pbVar10;
  ulonglong uVar11;
  longlong lVar12;
  ulonglong uVar13;
  uint uVar14;
  longlong lVar15;
  int iVar16;
  longlong lVar17;
  
  lVar15 = (ulonglong)*(ushort *)(param_1 + 0x38) + param_1;
  uVar14 = 0;
  lVar17 = 0;
  do {
    if (lVar17 == 0) {
      uVar6 = *(ushort *)(param_1 + 0x3a);
    }
    else {
      uVar6 = *(ushort *)(param_1 + 0x3e);
    }
    if (uVar6 != 0) {
      lVar12 = lVar17 * 0x520;
      uVar11 = (ulonglong)uVar6;
      (&DAT_140075a60)[lVar12] = 1;
      if (*(ushort *)(lVar15 + 0x46) != 0) {
        memmove(&DAT_140075c60 + lVar12,(void *)((ulonglong)*(ushort *)(lVar15 + 0x48) + param_1),
                (ulonglong)*(ushort *)(lVar15 + 0x46));
        (&DAT_140075c60)[(ulonglong)*(ushort *)(lVar15 + 0x46) + lVar12] = 0;
      }
      uVar6 = *(ushort *)(param_1 + 0x62 + uVar11);
      if (uVar6 != 0) {
        memmove(&DAT_140075e98 + lVar12,
                (void *)((ulonglong)*(ushort *)(param_1 + 100 + uVar11) + param_1),(ulonglong)uVar6)
        ;
        (&DAT_140075e98)[(ulonglong)*(ushort *)(param_1 + 0x62 + uVar11) + lVar12] = 0;
      }
      if ((*(char *)(param_1 + 0x10 + uVar11) == -1) && (*(char *)(param_1 + 0x11 + uVar11) == -1))
      {
        (&DAT_140075eb8)[lVar17 * 0x148] = *(undefined4 *)(param_1 + 0x12 + uVar11);
        uVar5 = 0;
      }
      else {
        puVar1 = (undefined8 *)(param_1 + 6 + uVar11);
        uVar4 = puVar1[1];
        uVar5 = 1;
        *(undefined8 *)(&DAT_140075eb8 + lVar17 * 0x148) = *puVar1;
        *(undefined8 *)(lVar12 + 0x140075ec0) = uVar4;
      }
      (&DAT_140075add)[lVar12] = uVar5;
      cVar2 = (&DAT_140075add)[lVar12];
      uVar4 = *(undefined8 *)(lVar12 + 0x140075ec0);
      *(undefined8 *)(&DAT_140075ee8 + lVar12) = *(undefined8 *)(&DAT_140075eb8 + lVar17 * 0x148);
      *(undefined8 *)(lVar12 + 0x140075ef0) = uVar4;
      bVar7 = *(byte *)(param_1 + 0x16 + uVar11);
      uVar13 = (ulonglong)bVar7;
      if (cVar2 == '\x01') {
        (&DAT_140075ec8)[lVar12] = bVar7;
        puVar1 = (undefined8 *)(param_1 + 0x18 + uVar11);
        uVar4 = puVar1[1];
        *(undefined8 *)(&DAT_140075ed8 + lVar17 * 0x148) = *puVar1;
        *(undefined8 *)(lVar12 + 0x140075ee0) = uVar4;
        puVar1 = (undefined8 *)(param_1 + 0x28 + uVar11);
        uVar4 = puVar1[1];
        *(undefined8 *)(&DAT_140075f08 + lVar17 * 0x148) = *puVar1;
        *(undefined8 *)(lVar12 + 0x140075f10) = uVar4;
        puVar1 = (undefined8 *)(param_1 + 0x38 + uVar11);
        uVar4 = puVar1[1];
        *(undefined8 *)(&DAT_140075f18 + lVar17 * 0x148) = *puVar1;
        *(undefined8 *)(lVar12 + 0x140075f20) = uVar4;
        puVar1 = (undefined8 *)(param_1 + 0x48 + uVar11);
        uVar4 = puVar1[1];
        *(undefined8 *)(&DAT_140075ef8 + lVar17 * 0x148) = *puVar1;
        *(undefined8 *)(lVar12 + 0x140075f00) = uVar4;
      }
      else {
        uVar8 = 0;
        if (bVar7 != 0) {
          bVar7 = 0x1f;
          uVar8 = 0;
          do {
            bVar3 = bVar7 & 0x1f;
            bVar7 = bVar7 - 1;
            uVar8 = uVar8 | 1 << bVar3;
            uVar13 = uVar13 - 1;
          } while (uVar13 != 0);
        }
        *(uint *)(&DAT_140075ec8 + lVar12) =
             uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
        (&DAT_140075ed8)[lVar17 * 0x148] = *(undefined4 *)(param_1 + 0x24 + uVar11);
        (&DAT_140075f08)[lVar17 * 0x148] = *(undefined4 *)(param_1 + 0x34 + uVar11);
        (&DAT_140075f18)[lVar17 * 0x148] = *(undefined4 *)(param_1 + 0x44 + uVar11);
        (&DAT_140075ef8)[lVar17 * 0x148] = *(undefined4 *)(param_1 + 0x54 + uVar11);
      }
      iVar16 = 0;
      (&DAT_140075f28)[lVar17 * 0x290] = *(undefined2 *)(param_1 + 0x58 + uVar11);
      (&DAT_140075a6e)[lVar17 * 0x290] = *(undefined2 *)(param_1 + 0x60 + uVar11);
      do {
        if (iVar16 == 0) {
          uVar6 = *(ushort *)(param_1 + 0x3c);
        }
        else {
          uVar6 = *(ushort *)(param_1 + 0x40);
        }
        if (((uVar6 != 0) &&
            (uVar11 = (ulonglong)uVar6, *(byte *)(param_1 + 0x21 + uVar11) == uVar14)) &&
           (((*(short *)(param_1 + 0x3a) != 0 && (*(short *)(param_1 + 0x3e) != 0)) ||
            ((*(byte *)(param_1 + 5 + uVar11) & 2) != 0)))) {
          uVar6 = *(ushort *)(param_1 + 0x28 + uVar11);
          if (uVar6 != 0) {
            memmove(&DAT_140075e06 + lVar12,(void *)(param_1 + (ulonglong)uVar6),
                    (ulonglong)*(ushort *)(param_1 + 0x26 + uVar11));
            (&DAT_140075e06)[(ulonglong)*(ushort *)(param_1 + 0x26 + uVar11) + lVar12] = 0;
          }
          uVar6 = *(ushort *)(param_1 + 0x2c + uVar11);
          if (uVar6 != 0) {
            memmove(&DAT_140075e87 + lVar12,(void *)(param_1 + (ulonglong)uVar6),
                    (ulonglong)*(ushort *)(param_1 + 0x2a + uVar11));
            (&DAT_140075e87)[(ulonglong)*(ushort *)(param_1 + 0x2a + uVar11) + lVar12] = 0;
          }
          uVar6 = *(ushort *)(param_1 + 0x30 + uVar11);
          if (uVar6 != 0) {
            memmove(&DAT_140075ce2 + (ulonglong)(byte)(&DAT_140075ce1)[lVar12] * 0x81 + lVar12,
                    (void *)(param_1 + (ulonglong)uVar6),
                    (ulonglong)*(ushort *)(param_1 + 0x2e + uVar11));
            (&DAT_140075ce2)
            [(ulonglong)*(ushort *)(param_1 + 0x2e + uVar11) +
             (ulonglong)(byte)(&DAT_140075ce1)[lVar12] * 0x81 + lVar12] = 0;
          }
          uVar6 = *(ushort *)(param_1 + 0x34 + uVar11);
          if (uVar6 != 0) {
            memmove(&DAT_140075de4 + (ulonglong)(byte)(&DAT_140075ce1)[lVar12] * 0x11 + lVar12,
                    (void *)(param_1 + (ulonglong)uVar6),
                    (ulonglong)*(ushort *)(param_1 + 0x32 + uVar11));
            (&DAT_140075de4)
            [(ulonglong)*(ushort *)(param_1 + 0x32 + uVar11) +
             (ulonglong)(byte)(&DAT_140075ce1)[lVar12] * 0x11 + lVar12] = 0;
          }
          if (*(char *)(param_1 + 0x20 + uVar11) != '\0') {
            (&DAT_140075a64)[lVar17 * 0x148] = (&DAT_140075a64)[lVar17 * 0x148] | 0x10000;
          }
          lVar9 = (ulonglong)(byte)(&DAT_140075ce1)[lVar12] * 0xc0 + lVar12;
          pbVar10 = &DAT_140075ae0 + lVar9;
          *pbVar10 = *pbVar10 | 1;
          if ((&DAT_140075add)[lVar12] == '\x01') {
            puVar1 = (undefined8 *)(param_1 + 6 + uVar11);
            uVar4 = puVar1[1];
            *(undefined8 *)(&DAT_140075ae4 + lVar9) = *puVar1;
            *(undefined8 *)(lVar9 + 0x140075aec) = uVar4;
          }
          else {
            *(undefined4 *)(&DAT_140075ae4 + lVar9) = *(undefined4 *)(param_1 + 0x12 + uVar11);
          }
          *(undefined2 *)(&DAT_140075af4 + lVar9) = *(undefined2 *)(param_1 + 0x16 + uVar11);
          isprintf((char *)(lVar9 + 0x140075b77),"%x-%x-%x-%x",
                   (ulonglong)*(ushort *)(param_1 + 0x18 + uVar11),
                   (ulonglong)*(ushort *)(param_1 + 0x1a + uVar11));
          memmove((void *)(lVar9 + 0x140075af6),
                  (void *)((ulonglong)*(ushort *)(param_1 + 0x24 + uVar11) + param_1),
                  (ulonglong)*(ushort *)(param_1 + 0x22 + uVar11));
          pbVar10[(ulonglong)*(ushort *)(param_1 + 0x22 + uVar11) + 0x16] = 0;
          (&DAT_140075ce1)[lVar12] = (&DAT_140075ce1)[lVar12] + '\x01';
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < 2);
    }
    uVar14 = uVar14 + 1;
    lVar17 = lVar17 + 1;
  } while (lVar17 < 2);
  return;
}



===== CrashDumpFindAdapter @ 140001990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CrashDumpFindAdapter(longlong param_1)

{
  short sVar1;
  ushort uVar2;
  short *psVar3;
  uint *puVar4;
  uint *puVar5;
  int *piVar6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  longlong lVar10;
  ulonglong uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *in_stack_00000028;
  undefined1 auStack_58 [32];
  undefined1 local_38 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_58;
  uVar11 = 0;
  psVar3 = *(short **)(in_stack_00000028 + 0x10);
  sVar1 = *psVar3;
  OurAdapter = param_1;
  if (CrashDumpDriverInitialized != '\x01') {
    *(undefined2 *)(param_1 + 0x6d70) = 0xff;
    *(undefined2 *)(param_1 + 0x6d90) = 0xff;
    uVar13 = 0xdeadbeef;
    uVar12 = 0xdeadbeef;
    if (sVar1 == 2) {
      *(short **)(param_1 + 0x6c70) = psVar3;
      *(undefined8 *)(param_1 + 0x6f48) = *(undefined8 *)(psVar3 + 2);
      *(undefined8 *)(param_1 + 0x6f58) = 0;
      *(undefined8 *)(param_1 + 0x6f50) = *(undefined8 *)(psVar3 + 6);
      *(undefined8 *)(param_1 + 0x6f60) = 0;
      puVar4 = *(uint **)(psVar3 + 2);
      *(uint **)(param_1 + 28000) = puVar4;
      *(undefined8 *)(param_1 + 0x6d80) = 0;
      *(undefined8 *)(param_1 + 0x6d68) = *(undefined8 *)(psVar3 + 6);
      *(undefined8 *)(param_1 + 0x6d88) = 0;
      *(undefined1 *)(param_1 + 0x7074) = 0;
      if (**(int **)(psVar3 + 2) == -1) {
        *(undefined1 *)(param_1 + 0x6d70) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0x6d71) = 1;
        if (puVar4 == (uint *)0x0) {
          uVar13 = 0xffffffff;
        }
        else {
          uVar13 = *puVar4;
          if ((uVar13 & 0xffff) != 0x1077) {
            uVar13 = puVar4[0x800];
          }
        }
      }
      *(undefined2 *)(param_1 + 0x6d90) = 1;
    }
    else {
      *(undefined8 *)(param_1 + 0x6f08) = *(undefined8 *)(psVar3 + 4);
      *(undefined8 *)(param_1 + 0x6f48) = *(undefined8 *)(psVar3 + 8);
      *(undefined8 *)(param_1 + 0x6f58) = *(undefined8 *)(psVar3 + 0xc);
      puVar4 = *(uint **)(psVar3 + 8);
      *(uint **)(param_1 + 28000) = puVar4;
      puVar5 = *(uint **)(psVar3 + 0xc);
      *(uint **)(param_1 + 0x6d80) = puVar5;
      *(undefined8 *)(param_1 + 0x6d30) = *(undefined8 *)(psVar3 + 4);
      *(undefined1 *)(param_1 + 0x7074) = 1;
      if (*(int **)(psVar3 + 8) != (int *)0x0) {
        if (**(int **)(psVar3 + 8) == -1) {
          *(undefined1 *)(param_1 + 0x6d70) = 1;
        }
        else {
          *(undefined1 *)(param_1 + 0x6d71) = 1;
          if (puVar4 == (uint *)0x0) {
            uVar13 = 0xffffffff;
          }
          else {
            uVar13 = *puVar4;
            if ((uVar13 & 0xffff) != 0x1077) {
              uVar13 = puVar4[0x800];
            }
          }
        }
      }
      if (*(int **)(psVar3 + 0xc) != (int *)0x0) {
        if (**(int **)(psVar3 + 0xc) == -1) {
          *(undefined1 *)(param_1 + 0x6d90) = 1;
        }
        else {
          *(undefined1 *)(param_1 + 0x6d91) = 1;
          if (puVar5 == (uint *)0x0) {
            uVar12 = 0xffffffff;
          }
          else {
            uVar12 = *puVar5;
            if ((uVar12 & 0xffff) != 0x1077) {
              uVar12 = puVar5[0x800];
            }
          }
        }
      }
    }
    if ((*(char *)(param_1 + 0x6d71) != '\0') || (*(char *)(param_1 + 0x6d91) != '\0')) {
      if (uVar13 != 0xdeadbeef) {
        uVar12 = uVar13;
      }
      if (uVar12 != 0xdeadbeef) {
        *in_stack_00000028 = 0xe0;
        in_stack_00000028[6] = 0x10000;
        in_stack_00000028[0xc] = 0;
        *(undefined1 *)(in_stack_00000028 + 0x12) = 1;
        *(undefined2 *)((longlong)in_stack_00000028 + 0x51) = 0x101;
        *(undefined1 *)((longlong)in_stack_00000028 + 0x53) = 0;
        *(undefined1 *)((longlong)in_stack_00000028 + 0x59) = 2;
        *(undefined1 *)((longlong)in_stack_00000028 + 0x61) = 1;
        *(undefined8 *)(in_stack_00000028 + 0x21) = 0x7078;
        in_stack_00000028[0x23] = 0;
        *(undefined2 *)((longlong)in_stack_00000028 + 0x91) = 0xff01;
        in_stack_00000028[0x25] = 0;
        *(undefined8 *)(in_stack_00000028 + 0x26) = 0;
        in_stack_00000028[0x28] = 0;
        iscsiGlobalsPtr = &DAT_140074cb0;
        iVar8 = mm_basic_initialize(param_1,(undefined1 *)(param_1 + 0x6cb0));
        if (iVar8 == 0) {
          l2_driver_intf = (undefined8 *)(OurAdapter + 0x6cb8);
          lVar10 = *(longlong *)(param_1 + 0x6d38);
          if (lVar10 == 0) {
            iVar8 = mm_GetPagesRequired();
            *(int *)(param_1 + 0x6f3c) = iVar8;
            uVar9 = mm_GetDmaBufferLength();
            iVar8 = (int)uVar9 + 0x400;
            *(int *)(param_1 + 0x6f40) = iVar8;
            lVar10 = StorPortGetUncachedExtension
                               (param_1,in_stack_00000028,
                                *(int *)(param_1 + 0x6f3c) + 0x1000 + iVar8);
            *(longlong *)(param_1 + 0x6d38) = lVar10;
            if (lVar10 == 0) {
              pcVar7 = (code *)swi(3);
              uVar9 = (*pcVar7)();
              return uVar9;
            }
            uVar11 = StorPortGetPhysicalAddress(param_1,0,lVar10,param_1 + 0x6d40);
            lVar10 = *(longlong *)(param_1 + 0x6d38);
          }
          if ((uVar11 & 0xfff) == 0) {
            uVar13 = *(uint *)(param_1 + 0x6d48);
          }
          else {
            uVar13 = (-(int)uVar11 - 1U & 0xfff) + 1;
            *(uint *)(param_1 + 0x6d48) = uVar13;
          }
          *(undefined4 *)(param_1 + 0x6f20) = *(undefined4 *)(param_1 + 0x6d40);
          *(longlong *)(param_1 + 0x6f10) = lVar10;
          *(ulonglong *)(param_1 + 0x6f18) = uVar11;
          *(uint *)(param_1 + 0x6f24) = uVar13;
          *(undefined4 *)(param_1 + 0x6f38) = 0;
          *(undefined4 *)(param_1 + 0x6f28) = 0;
          *(ulonglong *)(param_1 + 0x6f30) =
               (ulonglong)uVar13 + (ulonglong)*(uint *)(param_1 + 0x6f3c) + lVar10;
          mm_free_all_resources();
          if (sVar1 == 2) {
            uVar2 = *(ushort *)(*(longlong *)(param_1 + 0x6c70) + 0x14);
            *(uint *)(param_1 + 0x6d5c) = (uint)(uVar2 >> 8);
            *(uint *)(param_1 + 0x6d58) = (uVar2 & 7) << 5 | uVar2 >> 3 & 0x1f;
          }
          else {
            lVar10 = *(longlong *)(param_1 + 0x6d30);
            if (*(longlong *)(psVar3 + 8) != 0) {
              uVar2 = *(ushort *)((ulonglong)*(ushort *)(lVar10 + 0x3a) + 0x60 + lVar10);
              *(uint *)(param_1 + 0x6d5c) = (uint)(uVar2 >> 8);
              *(uint *)(param_1 + 0x6d58) = (uVar2 & 7) << 5 | uVar2 >> 3 & 0x1f;
            }
            if (*(longlong *)(psVar3 + 0xc) != 0) {
              uVar2 = *(ushort *)((ulonglong)*(ushort *)(lVar10 + 0x3e) + 0x60 + lVar10);
              *(uint *)(param_1 + 0x6d7c) = (uint)(uVar2 >> 8);
              *(uint *)(param_1 + 0x6d78) = uVar2 >> 3 & 0x1f | (uVar2 & 7) << 5;
            }
            piVar6 = *(int **)(param_1 + 0x6d30);
            if ((*piVar6 != 0x54464269) && (*(short *)((longlong)piVar6 + 0x3e) != 0)) {
              (*(code *)l2_driver_intf[6])(*l2_driver_intf,local_38);
              lVar10 = RtlCompareMemory((ulonglong)*(ushort *)((longlong)piVar6 + 0x3a) + 0x5a +
                                        (longlong)piVar6,local_38,6);
              if ((lVar10 != 6) &&
                 (lVar10 = RtlCompareMemory((ulonglong)*(ushort *)((longlong)piVar6 + 0x3e) + 0x5a +
                                            (longlong)piVar6,local_38,6), lVar10 == 6)) {
                *(undefined8 *)(param_1 + 0x6d80) = *(undefined8 *)(psVar3 + 8);
                *(undefined8 *)(param_1 + 28000) = *(undefined8 *)(psVar3 + 0xc);
              }
            }
          }
          *(undefined4 *)(param_1 + 0x6f00) = 0x200;
          uVar9 = CrashDumpInitializeAdapter(param_1);
          if ((char)uVar9 == '\x01') {
            CrashDumpDriverInitialized = '\x01';
            return 1;
          }
          return 2;
        }
      }
    }
  }
  return 0;
}



===== CrashDumpInitSessionBuffer @ 140001ea4 =====

void CrashDumpInitSessionBuffer(longlong param_1)

{
  *(longlong *)(param_1 + 0x130) = OurAdapter + 0xc70;
  *(longlong *)(param_1 + 0x160) = OurAdapter + 0x1c70;
  *(longlong *)(param_1 + 0x150) = OurAdapter + 0x2c70;
  *(longlong *)(param_1 + 0x158) = OurAdapter + 0x4c70;
  return;
}



===== CrashDumpInitiSCSIStack @ 140001ef8 =====

undefined8 CrashDumpInitiSCSIStack(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  ushort uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  
  g_netif = (void *)(param_1 + 0x6db0);
  *(void **)(param_1 + 0x6d50) = g_netif;
  memset(g_netif,0,0x150);
  puVar6 = (undefined8 *)(param_1 + 0x6c78);
  iVar4 = stack_bringup(puVar6);
  if (iVar4 != 0) {
LAB_1400020ac:
    stack_shutdown((longlong)puVar6);
    return 0xffffffff;
  }
  lVar2 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  if (*(int *)(lVar2 + 0x458) == 0) {
    if (*(char *)(lVar2 + 0x7d) == '\0') {
      iscsiDhcpDoDiscovery('\0');
      iVar4 = *(int *)(*(longlong *)
                        (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8
                        ) + 0x458);
    }
    else {
      if (*(int *)(lVar2 + 0x45c) != 0) {
        return 0;
      }
      if (*(int *)(lVar2 + 0x460) != 0) {
        return 0;
      }
      if (*(int *)(lVar2 + 0x464) != 0) {
        return 0;
      }
      ipv6_autoconfig();
      uVar1 = *(uint *)(*(longlong *)
                         (iscsiGlobalsPtr + 0xda0 +
                         (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
      if ((((uVar1 & 0x60000) != 0) && (uVar3 = ipv6_do_stateful_dhcpv6(uVar1), uVar3 != 0)) &&
         (uVar5 = dhcpv6_do_discovery(uVar3), (int)uVar5 == -2)) goto LAB_1400020ac;
      ipv6_get_default_router_ip_addrs
                ((undefined8 *)
                 (*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                 0x478));
      iVar4 = ipv6_get_source_ip_addrs
                        ((undefined8 *)
                         (*(longlong *)
                           (iscsiGlobalsPtr + 0xda0 +
                           (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x4d0));
      *(int *)(*(longlong *)
                (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
              0x4cc) = iVar4;
      iVar4 = *(int *)(*(longlong *)
                        (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8
                        ) + 0x4cc);
    }
    if (iVar4 == 0) goto LAB_1400020ac;
    stack_set_addr((longlong)puVar6);
  }
  return 0;
}



===== CrashDumpInitialize @ 1400020d0 =====

undefined1 CrashDumpInitialize(undefined8 param_1)

{
  StorPortNotification(3,param_1);
  return 1;
}



===== CrashDumpInitializeAdapter @ 1400020ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CrashDumpInitializeAdapter(longlong param_1)

{
  ushort uVar1;
  char *pcVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  
  lVar5 = 0;
  lVar7 = 0xda0;
  *(undefined2 *)(iscsiGlobalsPtr + 0xd80) = 15000;
  plVar8 = (longlong *)(param_1 + 28000);
  lVar9 = 2;
  *(undefined1 *)(iscsiGlobalsPtr + 0xd85) = 1;
  do {
    *(longlong *)(lVar7 + iscsiGlobalsPtr) = iscsiGlobalsPtr + 0xdb0 + lVar5;
    if (*plVar8 != 0) {
      *(undefined1 *)(lVar5 + 0xdb0 + iscsiGlobalsPtr) = 1;
    }
    lVar7 = lVar7 + 8;
    plVar8 = plVar8 + 4;
    lVar5 = lVar5 + 0x520;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  if (*(longlong *)(param_1 + 0x6d30) == 0) {
    CrashDumpExtractiSCSIFromDumpPoint(param_1);
  }
  else {
    CrashDumpExtractiSCSIFromiBFT(*(longlong *)(param_1 + 0x6d30));
  }
  iVar6 = 0;
  do {
    if (*(char *)(iscsiGlobalsPtr + 0xd9d) == '\0') {
      *(byte *)(iscsiGlobalsPtr + 0xd9c) = (byte)iVar6;
    }
    else {
      *(byte *)(iscsiGlobalsPtr + 0xd9c) = (byte)iVar6 ^ 1;
    }
    uVar4 = (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c);
    pcVar2 = *(char **)(iscsiGlobalsPtr + 0xda0 + uVar4 * 8);
    if (*pcVar2 != '\0') {
      uVar1 = *(ushort *)(pcVar2 + 0xe);
      memset(&g_if_stats,0,0x68);
      _g_if_stats = *(undefined8 *)(OurAdapter + 0x6cb8);
      _DAT_140074648 = 0xffffffff;
      _DAT_140074650 = (uint)uVar1;
      uVar3 = CrashDumpInitiSCSIStack(param_1);
      if ((int)uVar3 == 0) {
        _DAT_140074648 = DAT_14007464c;
        DAT_14007464c = 1;
        _DAT_1400746a4 = 0xc;
        uVar3 = CrashDumpLogonTarget();
        if ((char)uVar3 == '\x01') {
          if (DAT_14002d911 != '\0') {
            uVar3 = 0;
            if (*(code **)(l2_driver_intf + 0x68) != (code *)0x0) {
              uVar3 = (**(code **)(l2_driver_intf + 0x68))(param_1,0x54464942);
            }
          }
          return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
        }
        _DAT_14007466c = 0;
        _DAT_140074670 = 0;
        _DAT_140074668 =
             (uint)*(ushort *)
                    (*(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                    + 0xe);
        _DAT_140074664 = 0xc0000003;
        stack_shutdown(param_1 + 0x6c78);
      }
      else {
        _DAT_14007466c = 0;
        _DAT_140074670 = 0;
        _DAT_140074664 = 0xc0000001;
        _DAT_140074668 =
             (uint)*(ushort *)
                    (*(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                    + 0xe);
      }
      uVar4 = mm_free_all_resources();
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  return uVar4 & 0xffffffffffffff00;
}



===== CrashDumpIscsiDoRead @ 140002320 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashDumpIscsiDoRead(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  char cVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  iscsiSetupCmd((undefined8 *)&DAT_140074e50,1);
  DAT_140074e51 = DAT_140074e51 & 0xf9 | 0xc1;
  uVar1 = *(uint *)(param_2 + 0x10);
  _DAT_140074e64 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  memmove(&DAT_140074e70,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  iscsiSessionSendIscsiCmd
            (&DAT_140074e50,1,*(longlong *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x10));
  cVar2 = iscsiSessionWaitForCommandDone();
  uVar3 = CONCAT71(extraout_var,-(cVar2 != '\0')) & 0xffffffffffffff03;
  return CONCAT71((int7)(uVar3 >> 8),(char)uVar3 + '\x01');
}



===== CrashDumpIscsiDoReadCapacity @ 140002394 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashDumpIscsiDoReadCapacity(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  undefined7 extraout_var;
  ulonglong uVar4;
  undefined1 uVar5;
  
  uVar5 = 1;
  iscsiSetupCmd((undefined8 *)&DAT_140074e50,1);
  DAT_140074e51 = DAT_140074e51 & 0xf9 | 0xc1;
  uVar3 = *(uint *)(param_2 + 0x10);
  _DAT_140074e64 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  memmove(&DAT_140074e70,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  lVar1 = *(longlong *)(param_2 + 0x18);
  iscsiSessionSendIscsiCmd(&DAT_140074e50,1,lVar1,*(undefined4 *)(param_2 + 0x10));
  cVar2 = iscsiSessionWaitForCommandDone();
  uVar4 = CONCAT71(extraout_var,cVar2);
  if (cVar2 == '\0') {
    uVar3 = *(uint *)(lVar1 + 4);
    uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar4 = (ulonglong)uVar3;
    *(uint *)(param_1 + 0x6f00) = uVar3;
  }
  else {
    uVar5 = 4;
  }
  return CONCAT71((int7)(uVar4 >> 8),uVar5);
}



===== CrashDumpIscsiDoRequestSense @ 14000243c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
CrashDumpIscsiDoRequestSense
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  byte bVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  mm_printk("CrashDumpDoRequestSense:\n",param_2,param_3,param_4);
  iscsiSetupCmd((undefined8 *)&DAT_140074e50,1);
  DAT_140074e51 = DAT_140074e51 & 0xf9 | 0xc1;
  uVar1 = *(uint *)(param_2 + 0x10);
  _DAT_140074e64 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  memmove(&DAT_140074e70,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  uVar4 = (ulonglong)*(uint *)(param_2 + 0x10);
  lVar5 = *(longlong *)(param_2 + 0x18);
  iscsiSessionSendIscsiCmd(&DAT_140074e50,1,lVar5,*(uint *)(param_2 + 0x10));
  bVar2 = iscsiSessionWaitForCommandDone();
  uVar3 = mm_printk("CrashDumpDoRequestSense(): %x\n",(ulonglong)bVar2,lVar5,uVar4);
  uVar4 = CONCAT71((int7)((ulonglong)uVar3 >> 8),-(bVar2 != 0)) & 0xffffffffffffff03;
  return CONCAT71((int7)(uVar4 >> 8),(char)uVar4 + '\x01');
}



===== CrashDumpIscsiDoSyncCache @ 1400024cc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashDumpIscsiDoSyncCache(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  char cVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  iscsiSetupCmd((undefined8 *)&DAT_140074e50,1);
  DAT_140074e51 = DAT_140074e51 & 0xf9 | 0x81;
  uVar1 = *(uint *)(param_2 + 0x10);
  _DAT_140074e64 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  memmove(&DAT_140074e70,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  iscsiSessionSendIscsiCmd
            (&DAT_140074e50,1,*(longlong *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x10));
  cVar2 = iscsiSessionWaitForCommandDone();
  uVar3 = CONCAT71(extraout_var,-(cVar2 != '\0')) & 0xffffffffffffff03;
  return CONCAT71((int7)(uVar3 >> 8),(char)uVar3 + '\x01');
}



===== CrashDumpIscsiDoVerify @ 140002540 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashDumpIscsiDoVerify(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  char cVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  iscsiSetupCmd((undefined8 *)&DAT_140074e50,1);
  DAT_140074e51 = DAT_140074e51 | 0xc0;
  uVar1 = *(uint *)(param_2 + 0x10);
  _DAT_140074e64 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  memmove(&DAT_140074e70,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  iscsiSessionSendIscsiCmd
            (&DAT_140074e50,1,*(longlong *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x10));
  cVar2 = iscsiSessionWaitForCommandDone();
  uVar3 = CONCAT71(extraout_var,-(cVar2 != '\0')) & 0xffffffffffffff03;
  return CONCAT71((int7)(uVar3 >> 8),(char)uVar3 + '\x01');
}



===== CrashDumpIscsiDoWrite @ 1400025ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashDumpIscsiDoWrite(longlong param_1,longlong param_2)

{
  char cVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStack_78 [32];
  undefined1 local_58 [2];
  uint local_56;
  undefined2 local_51;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_78;
  memmove(local_58,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  uVar2 = 0;
  uVar4 = ((uint)(ushort)(local_51 << 8) | (uint)local_51._1_1_) * *(int *)(param_1 + 0x6f00);
  uVar6 = local_56 >> 0x18 | (local_56 & 0xff0000) >> 8 | (local_56 & 0xff00) << 8 |
          local_56 << 0x18;
  if (*(uint *)(param_2 + 0x10) < uVar4) {
LAB_1400026f7:
    uVar3 = CONCAT71((int7)(uVar2 >> 8),4);
  }
  else {
    uVar8 = 0;
    for (uVar5 = uVar4; uVar5 != 0; uVar5 = uVar5 - uVar7) {
      iscsiSetupCmd((undefined8 *)&DAT_140074e50,1);
      DAT_140074e51 = DAT_140074e51 & 0xf9 | 0xa1;
      uVar7 = 0x8000;
      if (uVar5 < 0x8000) {
        uVar7 = uVar5;
      }
      _DAT_140074e64 =
           uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
      uVar2 = (ulonglong)uVar7 / (ulonglong)*(uint *)(param_1 + 0x6f00);
      local_51 = (ushort)(uVar2 >> 8) & 0xff | (short)uVar2 << 8;
      memmove(&DAT_140074e70,local_58,(ulonglong)*(byte *)(param_2 + 10));
      iscsiSessionSendWriteData(&DAT_140074e50,2,uVar8 + *(longlong *)(param_2 + 0x18),uVar7);
      cVar1 = iscsiSessionWaitForCommandDone();
      uVar2 = iscsiGlobalsPtr;
      if (cVar1 != '\0') {
        if (*(char *)(iscsiGlobalsPtr + 0xe0) != -1) {
          *(char *)(param_2 + 4) = *(char *)(iscsiGlobalsPtr + 0xe0);
        }
        goto LAB_1400026f7;
      }
      uVar8 = (ulonglong)((int)uVar8 + uVar7);
      uVar6 = uVar6 + uVar7 / *(uint *)(param_1 + 0x6f00);
      local_56 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 * 0x1000000
      ;
      uVar2 = (ulonglong)local_56;
    }
    *(uint *)(param_2 + 0x10) = uVar4;
    uVar3 = CONCAT71((int7)(uVar2 >> 8),1);
  }
  return uVar3;
}



===== CrashDumpIsr @ 140002720 =====

undefined1 CrashDumpIsr(void)

{
  return 0;
}



===== CrashDumpLogonTarget @ 140002724 =====

undefined8 CrashDumpLogonTarget(void)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  char cVar4;
  undefined7 extraout_var;
  undefined8 uVar5;
  
  lVar2 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  lVar1 = lVar2 + 0x282;
  if (lVar1 != 0) {
    *(longlong *)(lVar2 + 0x130) = lVar1;
  }
  lVar2 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  lVar1 = lVar2 + 900;
  if (lVar1 != 0) {
    *(longlong *)(lVar2 + 0x138) = lVar1;
  }
  lVar1 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  cVar4 = CrashDumpDoLogin((ushort *)(iscsiGlobalsPtr + 8),lVar1 + 0x80,
                           (uint)*(byte *)(lVar1 + 0x7d));
  if (cVar4 == '\0') {
    return CONCAT71(extraout_var,1);
  }
  pcVar3 = (code *)swi(3);
  uVar5 = (*pcVar3)();
  return uVar5;
}



===== CrashDumpPrintTimeStamp @ 1400027b4 =====

void CrashDumpPrintTimeStamp(void)

{
  undefined1 local_res8 [32];
  
  KeQueryPerformanceCounter(local_res8);
  return;
}



===== CrashDumpResetBus @ 1400027d0 =====

undefined1 CrashDumpResetBus(undefined8 param_1,undefined8 param_2)

{
  StorPortCompleteRequest(param_1,param_2,0xff,0xff,0xe);
  StorPortNotification(1,param_1);
  return 1;
}



===== CrashDumpShutdownCommand @ 140002800 =====

undefined1 CrashDumpShutdownCommand(longlong param_1)

{
  iscsiSessionStop(iscsiGlobalsPtr + 8);
  stack_shutdown(param_1 + 0x6c78);
  return 1;
}



===== CrashDumpStartIo @ 140002830 =====

undefined1 CrashDumpStartIo(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  
  cVar1 = '\x06';
  if (*(char *)(param_2 + 2) == '\0') {
    cVar1 = CrashDumpExecuteiSCSICommand(param_1,param_2,param_3,param_4);
  }
  else if (*(char *)(param_2 + 2) == '\a') {
    cVar1 = CrashDumpShutdownCommand(param_1);
  }
  *(char *)(param_2 + 3) = cVar1;
  StorPortNotification(0,param_1,param_2);
  StorPortNotification(1,param_1);
  return 1;
}



===== getPrefixlen @ 14000288c =====

char getPrefixlen(longlong param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  
  cVar2 = '\0';
  bVar4 = 0;
  do {
    cVar3 = *(char *)((ulonglong)bVar4 + param_1);
    if (cVar3 == -1) {
      cVar2 = cVar2 + '\b';
    }
    else {
      if (cVar3 == '\0') {
        return cVar2;
      }
      bVar1 = 0;
      do {
        if (-1 < cVar3) break;
        cVar2 = cVar2 + '\x01';
        cVar3 = cVar3 * '\x02';
        bVar1 = bVar1 + 1;
      } while (bVar1 < 8);
    }
    bVar4 = bVar4 + 1;
    if (0xf < bVar4) {
      return cVar2;
    }
  } while( true );
}



===== getRandomNumber @ 1400028cc =====

uint getRandomNumber(void)

{
  uint uVar1;
  undefined1 local_res8 [32];
  
  uVar1 = KeQueryPerformanceCounter(local_res8);
  return uVar1 ^ 0x80808080;
}



===== get_network_stack @ 1400028e8 =====

longlong get_network_stack(void)

{
  return OurAdapter + 0x6c78;
}



===== iscsiAbortRoutine @ 140002900 =====

void iscsiAbortRoutine(void)

{
  *(undefined1 *)(iscsiGlobalsPtr + 0xd82) = 1;
  return;
}



===== iscsiGetDhcpBuffer @ 140002910 =====

longlong iscsiGetDhcpBuffer(ushort param_1)

{
  if (param_1 < 0x2001) {
    return OurAdapter + 0xc70;
  }
  return 0;
}



===== iscsiGetTicks @ 14000292c =====

longlong iscsiGetTicks(void)

{
  longlong lVar1;
  longlong local_res8 [4];
  
  lVar1 = KeQueryPerformanceCounter(local_res8);
  return lVar1 / (local_res8[0] / 1000);
}



===== iscsiL2GetRxPacket @ 14000296c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void iscsiL2GetRxPacket(undefined8 param_1)

{
  (**(code **)(l2_driver_intf + 0x10))(*(undefined8 *)(OurAdapter + 0x6cb8),param_1);
  return;
}



===== iscsiL2Send @ 140002990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void iscsiL2Send(undefined8 param_1,undefined2 param_2)

{
  (**(code **)(l2_driver_intf + 0x18))(*(undefined8 *)(OurAdapter + 0x6cb8),param_1,param_2);
  return;
}



===== iscsiProcessLoop @ 1400029b8 =====

void iscsiProcessLoop(ushort param_1)

{
  iscsiServiceTicks();
  if ((param_1 & 2) != 0) {
    *(undefined2 *)(iscsiGlobalsPtr + 0xd88) = 1;
  }
  if ((param_1 & 1) != 0) {
    stack_poll_device();
  }
  iscsiSessionTxState();
  iscsiServiceTimer();
  return;
}



===== iscsiServiceTicks @ 140002a04 =====

void iscsiServiceTicks(void)

{
  longlong lVar1;
  
  if ((DAT_14002d914 == 0) || (lVar1 = iscsiGetTicks(), (int)lVar1 != DAT_14002d914)) {
    lVar1 = iscsiGetTicks();
    system_ticks = system_ticks + 1;
    DAT_14002d914 = (int)lVar1;
    iscsiTimerTick();
    return;
  }
  return;
}



===== swap_dword @ 140002a3c =====

uint swap_dword(uint param_1)

{
  return param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
}



===== um_block @ 140002a44 =====

longlong um_block(void)

{
  return OurAdapter + 0x6cb0;
}



===== mm_GetDmaBufferLength @ 140002a54 =====

undefined8 mm_GetDmaBufferLength(void)

{
  return 0x45d8;
}



===== mm_GetPagesRequired @ 140002a5c =====

int mm_GetPagesRequired(void)

{
  undefined8 uVar1;
  
  uVar1 = lm_get_required_pages();
  return (int)uVar1 << 0xc;
}



===== mm_alloc_pool @ 140002a70 =====

longlong mm_alloc_pool(longlong param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  longlong local_res8;
  
  local_res8 = 0;
  iVar2 = StorPortExtendedFunction(0,param_1,param_2,0x44434951,&local_res8);
  if (iVar2 != 0) {
    uVar1 = *(uint *)(param_1 + 0x7070);
    uVar3 = (param_2 + 3U & 0xfffffffc) + uVar1;
    if (uVar3 < 0x101) {
      *(uint *)(param_1 + 0x7070) = uVar3;
      local_res8 = param_1 + 0x6f70 + (ulonglong)uVar1;
    }
    else {
      local_res8 = 0;
    }
  }
  return local_res8;
}



===== mm_delay @ 140002ae4 =====

ulonglong mm_delay(uint param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if (param_1 < 1000) {
    uVar1 = StorPortStallExecution();
    return uVar1;
  }
  uVar2 = (ulonglong)param_1 * 0x10624dd3 & 0xffffffff;
  uVar1 = (ulonglong)param_1 / 1000;
  if ((int)uVar1 != 0) {
    do {
      uVar2 = StorPortStallExecution(0x3de);
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return uVar2;
}



===== mm_device_poll @ 140002b30 =====

int mm_device_poll(longlong param_1,int param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  int iVar7;
  uint uVar6;
  int iVar8;
  
  iVar8 = 0;
  lm_service_intr(param_1);
  do {
    iVar7 = *(int *)(param_1 + 0xa70);
    if (iVar7 == *(int *)(param_1 + 0xa74)) {
      iVar4 = iVar7;
      if (iVar7 == 0) {
        iVar4 = *(int *)(param_1 + 0xa78);
      }
      if (*(longlong *)(param_1 + 0xa80 + (ulonglong)(iVar4 - 1) * 8) == 0) break;
    }
    if (iVar7 == 0) {
      iVar7 = *(int *)(param_1 + 0xa78);
    }
    uVar6 = iVar7 - 1;
    *(uint *)(param_1 + 0xa70) = uVar6;
    *(int *)(param_1 + 0xa7c) = *(int *)(param_1 + 0xa7c) + -1;
    uVar5 = *(undefined8 *)(param_1 + 0xa80 + (ulonglong)uVar6 * 8);
    *(undefined8 *)(param_1 + 0xa80 + (ulonglong)uVar6 * 8) = 0;
    iVar7 = *(int *)(param_1 + 0xa14);
    if (iVar7 == 0) {
      iVar7 = *(int *)(param_1 + 0xa18);
    }
    *(undefined8 *)(param_1 + 0xa20 + (ulonglong)(iVar7 - 1U) * 8) = uVar5;
    *(int *)(param_1 + 0xa1c) = *(int *)(param_1 + 0xa1c) + 1;
    *(uint *)(param_1 + 0xa14) = iVar7 - 1U;
    *(int *)(param_1 + 0x6f6c) = *(int *)(param_1 + 0x6f6c) + -1;
    iVar8 = iVar8 + 1;
  } while( true );
  if (param_2 != 0) {
    iVar7 = *(int *)(param_1 + 0x908);
    if (iVar7 == *(int *)(param_1 + 0x90c)) {
      iVar4 = iVar7;
      if (iVar7 == 0) {
        iVar4 = *(int *)(param_1 + 0x910);
      }
      if (*(longlong *)(param_1 + 0x918 + (ulonglong)(iVar4 - 1) * 8) == 0) goto LAB_140002c89;
    }
    if (iVar7 == 0) {
      iVar7 = *(int *)(param_1 + 0x910);
    }
    uVar6 = iVar7 - 1;
    *(uint *)(param_1 + 0x908) = uVar6;
    *(int *)(param_1 + 0x914) = *(int *)(param_1 + 0x914) + -1;
    lVar2 = *(longlong *)(param_1 + 0x918 + (ulonglong)uVar6 * 8);
    *(undefined8 *)(param_1 + 0x918 + (ulonglong)uVar6 * 8) = 0;
    bVar1 = *(byte *)(lVar2 + 0x10);
    lVar3 = *(longlong *)(lVar2 + 0x18);
    uVar5 = mm_get_net_if();
    stack_rx_packet(uVar5,(ulonglong)bVar1 + lVar3,*(undefined2 *)(lVar2 + 0xe));
    iVar7 = *(int *)(param_1 + 0x8ac);
    if (iVar7 == 0) {
      iVar7 = *(int *)(param_1 + 0x8b0);
    }
    *(longlong *)(param_1 + 0x8b8 + (ulonglong)(iVar7 - 1U) * 8) = lVar2;
    *(int *)(param_1 + 0x8b4) = *(int *)(param_1 + 0x8b4) + 1;
    *(uint *)(param_1 + 0x8ac) = iVar7 - 1U;
    lm_post_buffers(param_1);
  }
LAB_140002c89:
  lm_ack_enable_intr(param_1,1,1);
  return iVar8;
}



===== mm_dma_alloc @ 140002cb8 =====

undefined8 mm_dma_alloc(longlong param_1,longlong *param_2,longlong *param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_4 + 0x3fU & 0xffffffc0;
  if (*(uint *)(param_1 + 0x6f40) < *(uint *)(param_1 + 0x6f38) + uVar1) {
    return 1;
  }
  *param_2 = (ulonglong)*(uint *)(param_1 + 0x6f38) + *(longlong *)(param_1 + 0x6f30);
  *param_3 = (ulonglong)*(uint *)(param_1 + 0x6f3c) + (ulonglong)*(uint *)(param_1 + 0x6f24) +
             *(longlong *)(param_1 + 0x6f18) + (ulonglong)*(uint *)(param_1 + 0x6f38);
  *(int *)(param_1 + 0x6f38) = *(int *)(param_1 + 0x6f38) + uVar1;
  return 0;
}



===== mm_get_drv_type @ 140002d18 =====

undefined8 mm_get_drv_type(void)

{
  return 4;
}



===== mm_get_drv_version_dword @ 140002d20 =====

undefined8 mm_get_drv_version_dword(void)

{
  return 0x82a0164;
}



===== mm_get_free_pkt_desc @ 140002d28 =====

longlong mm_get_free_pkt_desc(longlong param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  
  lm_service_intr(param_1);
  iVar5 = *(int *)(param_1 + 0xa10);
  if (iVar5 == 0) {
    iVar5 = *(int *)(param_1 + 0xa18);
  }
  *(int *)(param_1 + 0xa1c) = *(int *)(param_1 + 0xa1c) + -1;
  uVar2 = iVar5 - 1;
  *(uint *)(param_1 + 0xa10) = uVar2;
  lVar4 = *(longlong *)(param_1 + 0xa20 + (ulonglong)uVar2 * 8);
  *(undefined8 *)(param_1 + 0xa20 + (ulonglong)uVar2 * 8) = 0;
  if (lVar4 == 0) {
    iVar5 = 10000;
    while( true ) {
      lm_service_intr(param_1);
      iVar3 = *(int *)(param_1 + 0xa70);
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_1 + 0xa78);
      }
      *(int *)(param_1 + 0xa7c) = *(int *)(param_1 + 0xa7c) + -1;
      uVar2 = iVar3 - 1;
      *(uint *)(param_1 + 0xa70) = uVar2;
      lVar4 = *(longlong *)(param_1 + 0xa80 + (ulonglong)uVar2 * 8);
      *(undefined8 *)(param_1 + 0xa80 + (ulonglong)uVar2 * 8) = 0;
      if (lVar4 != 0) break;
      iVar5 = iVar5 + -1;
      if (iVar5 < 1) {
        pcVar1 = (code *)swi(3);
        lVar4 = (*pcVar1)();
        return lVar4;
      }
    }
    *(int *)(param_1 + 0x6f6c) = *(int *)(param_1 + 0x6f6c) + -1;
  }
  lm_ack_enable_intr(param_1,1,1);
  return lVar4;
}



===== mm_get_link_status @ 140002df0 =====

bool mm_get_link_status(longlong param_1)

{
  lm_mcp_handle_link_change(param_1);
  return *(char *)(param_1 + 0x280) != '\0';
}



===== mm_get_mac_addr @ 140002e10 =====

void mm_get_mac_addr(longlong param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0xb4);
  *(undefined2 *)(param_2 + 1) = *(undefined2 *)(param_1 + 0xb8);
  return;
}



===== mm_get_rx_packet @ 140002e30 =====

undefined2 mm_get_rx_packet(longlong param_1,void *param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar4;
  uint uVar3;
  
  mm_device_poll(param_1,0);
  iVar4 = *(int *)(param_1 + 0x908);
  if (iVar4 == *(int *)(param_1 + 0x90c)) {
    iVar2 = iVar4;
    if (iVar4 == 0) {
      iVar2 = *(int *)(param_1 + 0x910);
    }
    if (*(longlong *)(param_1 + 0x918 + (ulonglong)(iVar2 - 1) * 8) == 0) {
      return 0;
    }
  }
  if (iVar4 == 0) {
    iVar4 = *(int *)(param_1 + 0x910);
  }
  uVar3 = iVar4 - 1;
  *(uint *)(param_1 + 0x908) = uVar3;
  *(int *)(param_1 + 0x914) = *(int *)(param_1 + 0x914) + -1;
  lVar1 = *(longlong *)(param_1 + 0x918 + (ulonglong)uVar3 * 8);
  *(undefined8 *)(param_1 + 0x918 + (ulonglong)uVar3 * 8) = 0;
  memmove(param_2,(void *)((ulonglong)*(byte *)(lVar1 + 0x10) + *(longlong *)(lVar1 + 0x18)),
          (ulonglong)*(ushort *)(lVar1 + 0xe));
  iVar4 = *(int *)(param_1 + 0x8ac);
  if (iVar4 == 0) {
    iVar4 = *(int *)(param_1 + 0x8b0);
  }
  *(longlong *)(param_1 + 0x8b8 + (ulonglong)(iVar4 - 1U) * 8) = lVar1;
  *(int *)(param_1 + 0x8b4) = *(int *)(param_1 + 0x8b4) + 1;
  *(uint *)(param_1 + 0x8ac) = iVar4 - 1U;
  lm_post_buffers(param_1);
  return *(undefined2 *)(lVar1 + 0xe);
}



===== mm_memcpy @ 140002f00 =====

void * __cdecl mm_memcpy(void *_Dst,void *_Src,size_t _Size)

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
          puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 0x10));
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
          *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
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
            puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x30));
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)((longlong)puVar9 + uVar11);
            uVar6 = ((undefined8 *)((longlong)puVar9 + uVar11))[1];
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
        if (uVar12 == 0) goto LAB_140018277;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
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
LAB_140018277:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 8));
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((longlong)puVar9 + (uVar11 - 1));
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
        *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)((longlong)_Dst + uVar11))[1];
        *(undefined8 *)_Dst = *(undefined8 *)((longlong)_Dst + uVar11);
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
          uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
          puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x20);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x30);
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
      if (uVar12 == 0) goto LAB_1400180d2;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
      puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_1400180d2:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)((longlong)puVar9 + uVar11);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== mm_memset @ 140002f08 =====

void mm_memset(void *param_1,uint param_2,undefined1 param_3)

{
  if ((short)param_2 != 0) {
    memset(param_1,CONCAT31((int3)(param_2 >> 8),param_3),(ulonglong)(param_2 & 0xffff));
  }
  return;
}



===== mm_page_alloc @ 140002f24 =====

undefined8
mm_page_alloc(longlong param_1,longlong *param_2,longlong *param_3,int param_4,undefined8 *param_5)

{
  *param_5 = 0;
  if (*(uint *)(param_1 + 0x6f3c) < *(uint *)(param_1 + 0x6f28) + param_4 * 0x1000) {
    return 1;
  }
  *param_2 = *(longlong *)(param_1 + 0x6f10) + (ulonglong)*(uint *)(param_1 + 0x6f24) +
             (ulonglong)*(uint *)(param_1 + 0x6f28);
  *param_3 = *(longlong *)(param_1 + 0x6f18) + (ulonglong)*(uint *)(param_1 + 0x6f24) +
             (ulonglong)*(uint *)(param_1 + 0x6f28);
  *(int *)(param_1 + 0x6f28) = *(int *)(param_1 + 0x6f28) + param_4 * 0x1000;
  return 0;
}



===== mm_pci_cfg_read @ 140002f8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 mm_pci_cfg_read(longlong param_1,uint param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined1 auStack_148 [32];
  undefined4 *local_128;
  undefined4 local_120;
  undefined4 local_118 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_148;
  memset(local_118,0,0x100);
  lVar2 = (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 0x20;
  if (param_2 < 0x100) {
    local_128 = local_118;
    local_120 = 0x100;
    uVar1 = StorPortGetBusData(param_1,4,*(undefined4 *)(lVar2 + 0x6d5c + param_1),
                               (char)*(undefined4 *)(lVar2 + 0x6d58 + param_1));
    if ((uVar1 & 0xfffffffd) != 0) {
      return *(undefined4 *)((longlong)local_118 + (ulonglong)param_2);
    }
  }
  return 0xffffffff;
}



===== mm_pci_cfg_write @ 140003044 =====

void mm_pci_cfg_write(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 0x20;
  HalSetBusDataByOffset
            (4,*(undefined4 *)(lVar1 + 0x6d5c + param_1),*(uint *)(lVar1 + 0x6d58 + param_1) & 0xff,
             param_3,param_2,4);
  return;
}



===== mm_pci_mem_read @ 14000308c =====

undefined4 mm_pci_mem_read(longlong param_1,uint param_2)

{
  return *(undefined4 *)
          ((ulonglong)param_2 +
          *(longlong *)(param_1 + 0x6f48 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 0x10));
}



===== mm_pci_mem_write @ 1400030bc =====

void mm_pci_mem_write(longlong param_1,byte param_2,uint param_3,undefined4 *param_4)

{
  if ((param_2 == 0) || ((param_2 == 1 && (*(char *)(param_1 + 0x7074) == '\0')))) {
    *(undefined4 *)
     ((ulonglong)param_3 +
     *(longlong *)
      (param_1 + 0x6f48 +
      ((ulonglong)param_2 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 2) * 8)) = *param_4;
    LOCK();
    UNLOCK();
    return;
  }
  mm_pci_cfg_write(param_1,param_3,param_4);
  return;
}



===== mm_printk @ 140003128 =====

void mm_printk(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  vDbgPrintEx(DAT_14002d014,DAT_14002d018,param_1,&local_res10);
  return;
}



===== _guard_check_icall @ 140003160 =====

void _guard_check_icall(void)

{
  return;
}



===== mm_transmit_packet @ 140003170 =====

undefined4 mm_transmit_packet(longlong param_1,longlong *param_2)

{
  ushort *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  
  lVar5 = mm_get_free_pkt_desc(param_1);
  if (lVar5 == 0) {
    uVar3 = 1;
  }
  else {
    lVar2 = *(longlong *)(lVar5 + 0x10);
    iVar6 = 0;
    *(short *)(lVar5 + 0x22) = (short)param_2[2];
    do {
      memmove((void *)(iVar6 + lVar2),(void *)param_2[1],
              (ulonglong)*(ushort *)((longlong)param_2 + 0x12));
      puVar1 = (ushort *)((longlong)param_2 + 0x12);
      param_2 = (longlong *)*param_2;
      iVar6 = iVar6 + (uint)*puVar1;
    } while (param_2 != (longlong *)0x0);
    *(int *)(param_1 + 0x6f6c) = *(int *)(param_1 + 0x6f6c) + 1;
    lm_send_packet(param_1,lVar5);
    CrashDumpPrintTimeStamp();
    iVar6 = 200000;
    do {
      if ((*(int *)(param_1 + 0x6f6c) == 0) || (iVar4 = mm_device_poll(param_1,0), iVar4 != 0))
      goto LAB_140003219;
      StorPortStallExecution(0x14);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    CrashDumpPrintTimeStamp();
LAB_140003219:
    CrashDumpPrintTimeStamp();
    uVar3 = 0;
  }
  return uVar3;
}



===== mm_transmit_packet_raw @ 140003240 =====

undefined4 mm_transmit_packet_raw(longlong param_1,void *param_2,ushort param_3)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  
  lVar3 = mm_get_free_pkt_desc(param_1);
  if (lVar3 == 0) {
    uVar1 = 1;
  }
  else {
    *(ushort *)(lVar3 + 0x22) = param_3;
    memmove(*(void **)(lVar3 + 0x10),param_2,(ulonglong)param_3);
    *(int *)(param_1 + 0x6f6c) = *(int *)(param_1 + 0x6f6c) + 1;
    lm_send_packet(param_1,lVar3);
    CrashDumpPrintTimeStamp();
    iVar4 = 2000;
    do {
      if ((*(int *)(param_1 + 0x6f6c) == 0) || (iVar2 = mm_device_poll(param_1,0), iVar2 != 0))
      goto LAB_1400032cc;
      mm_delay(2000);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    CrashDumpPrintTimeStamp();
LAB_1400032cc:
    CrashDumpPrintTimeStamp();
    uVar1 = 0;
  }
  return uVar1;
}



===== nx4_get_intf @ 1400032e8 =====

undefined8 nx4_get_intf(undefined8 param_1,undefined8 *param_2)

{
  param_2[5] = 0;
  param_2[1] = iscsiBootCancel;
  param_2[2] = mm_get_rx_packet;
  param_2[3] = mm_transmit_packet_raw;
  param_2[4] = mm_transmit_packet;
  param_2[6] = mm_get_mac_addr;
  param_2[7] = iscsiBootCancel;
  param_2[8] = mm_device_poll;
  param_2[9] = mm_get_link_status;
  param_2[0xd] = _guard_check_icall;
  *param_2 = param_1;
  param_2[0xe] = iscsiBootCancel;
  nx4_get_netif_intf((longlong)param_2);
  return 0;
}



===== mm_basic_initialize @ 140003374 =====

void mm_basic_initialize(undefined8 param_1,undefined1 *param_2)

{
  *(undefined4 *)(param_2 + 0xec) = 0;
  *param_2 = 4;
  nx4_get_intf(param_1,(undefined8 *)(param_2 + 8));
  return;
}



===== mm_free_all_resources @ 140003388 =====

undefined8 mm_free_all_resources(void)

{
  longlong lVar1;
  
  lVar1 = um_block();
  *(undefined4 *)(lVar1 + 0x94) = *(undefined4 *)(lVar1 + 0x98);
  memset(*(void **)(lVar1 + 0x88),0,(ulonglong)*(uint *)(lVar1 + 0x90));
  return 0;
}



===== mm_get_net_if @ 1400033bc =====

undefined8 mm_get_net_if(void)

{
  longlong lVar1;
  
  lVar1 = um_block();
  return *(undefined8 *)(lVar1 + 0xa0);
}



===== MD5_CalculateDigest @ 1400033d4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MD5_CalculateDigest(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  iVar4 = param_1[4];
  iVar5 = param_1[5];
  uVar20 = (~uVar1 & uVar3 | uVar2 & uVar1) + *param_1 + iVar4 + _DAT_14002d174;
  uVar21 = (uVar20 * 0x80 | uVar20 >> 0x19) + uVar1;
  uVar20 = (~uVar21 & uVar2 | uVar1 & uVar21) + iVar5 + _DAT_14002d178 + uVar3;
  iVar6 = param_1[6];
  uVar20 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar21;
  uVar22 = (~uVar20 & uVar1 | uVar20 & uVar21) + iVar6 + _DAT_14002d17c + uVar2;
  iVar7 = param_1[7];
  uVar22 = (uVar22 >> 0xf | uVar22 * 0x20000) + uVar20;
  uVar23 = (~uVar22 & uVar21 | uVar20 & uVar22) + iVar7 + _DAT_14002d180 + uVar1;
  iVar8 = param_1[8];
  uVar23 = (uVar23 >> 10 | uVar23 * 0x400000) + uVar22;
  iVar9 = param_1[9];
  uVar21 = (~uVar23 & uVar20 | uVar22 & uVar23) + iVar8 + _DAT_14002d184 + uVar21;
  uVar25 = (uVar21 * 0x80 | uVar21 >> 0x19) + uVar23;
  iVar10 = param_1[0xb];
  iVar11 = param_1[0xe];
  iVar12 = param_1[10];
  uVar20 = (~uVar25 & uVar22 | uVar23 & uVar25) + iVar9 + _DAT_14002d188 + uVar20;
  uVar21 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar25;
  uVar22 = (~uVar21 & uVar23 | uVar21 & uVar25) + iVar12 + _DAT_14002d18c + uVar22;
  uVar20 = (uVar22 >> 0xf | uVar22 * 0x20000) + uVar21;
  uVar23 = (~uVar20 & uVar25 | uVar21 & uVar20) + iVar10 + _DAT_14002d190 + uVar23;
  iVar13 = param_1[0xc];
  uVar23 = (uVar23 >> 10 | uVar23 * 0x400000) + uVar20;
  iVar14 = param_1[0xd];
  uVar25 = (~uVar23 & uVar21 | uVar20 & uVar23) + iVar13 + _DAT_14002d194 + uVar25;
  uVar25 = (uVar25 * 0x80 | uVar25 >> 0x19) + uVar23;
  uVar21 = (~uVar25 & uVar20 | uVar23 & uVar25) + iVar14 + _DAT_14002d198 + uVar21;
  uVar21 = (uVar21 * 0x1000 | uVar21 >> 0x14) + uVar25;
  uVar20 = (~uVar21 & uVar23 | uVar21 & uVar25) + iVar11 + _DAT_14002d19c + uVar20;
  iVar15 = param_1[0xf];
  uVar22 = (uVar20 >> 0xf | uVar20 * 0x20000) + uVar21;
  uVar23 = (~uVar22 & uVar25 | uVar21 & uVar22) + iVar15 + _DAT_14002d1a0 + uVar23;
  iVar16 = param_1[0x10];
  uVar20 = (uVar23 >> 10 | uVar23 * 0x400000) + uVar22;
  iVar17 = param_1[0x11];
  iVar18 = param_1[0x12];
  iVar19 = param_1[0x13];
  uVar25 = (~uVar20 & uVar21 | uVar22 & uVar20) + iVar16 + _DAT_14002d1a4 + uVar25;
  uVar25 = (uVar25 * 0x80 | uVar25 >> 0x19) + uVar20;
  uVar21 = (~uVar25 & uVar22 | uVar20 & uVar25) + iVar17 + _DAT_14002d1a8 + uVar21;
  uVar23 = (uVar21 * 0x1000 | uVar21 >> 0x14) + uVar25;
  uVar22 = (~uVar23 & uVar20 | uVar23 & uVar25) + iVar18 + _DAT_14002d1ac + uVar22;
  uVar21 = (uVar22 >> 0xf | uVar22 * 0x20000) + uVar23;
  uVar20 = (~uVar21 & uVar25 | uVar23 & uVar21) + iVar19 + _DAT_14002d1b0 + uVar20;
  uVar20 = (uVar20 >> 10 | uVar20 * 0x400000) + uVar21;
  uVar25 = (~uVar23 & uVar21 | uVar23 & uVar20) + _DAT_14002d1b4 + iVar5 + uVar25;
  uVar22 = (uVar25 * 0x20 | uVar25 >> 0x1b) + uVar20;
  uVar23 = (~uVar21 & uVar20 | uVar21 & uVar22) + _DAT_14002d1b8 + iVar12 + uVar23;
  uVar25 = (uVar23 * 0x200 | uVar23 >> 0x17) + uVar22;
  uVar21 = (~uVar20 & uVar22 | uVar25 & uVar20) + _DAT_14002d1bc + iVar15 + uVar21;
  uVar23 = (uVar21 * 0x4000 | uVar21 >> 0x12) + uVar25;
  uVar20 = (~uVar22 & uVar25 | uVar23 & uVar22) + _DAT_14002d1c0 + iVar4 + uVar20;
  uVar21 = (uVar20 >> 0xc | uVar20 * 0x100000) + uVar23;
  uVar22 = (~uVar25 & uVar23 | uVar25 & uVar21) + _DAT_14002d1c4 + iVar9 + uVar22;
  uVar20 = (uVar22 * 0x20 | uVar22 >> 0x1b) + uVar21;
  uVar25 = (~uVar23 & uVar21 | uVar23 & uVar20) + _DAT_14002d1c8 + iVar11 + uVar25;
  uVar22 = (uVar25 * 0x200 | uVar25 >> 0x17) + uVar20;
  uVar23 = (~uVar21 & uVar20 | uVar22 & uVar21) + iVar19 + _DAT_14002d1cc + uVar23;
  uVar25 = (uVar23 * 0x4000 | uVar23 >> 0x12) + uVar22;
  uVar21 = (~uVar20 & uVar22 | uVar25 & uVar20) + _DAT_14002d1d0 + iVar8 + uVar21;
  uVar23 = (uVar21 >> 0xc | uVar21 * 0x100000) + uVar25;
  uVar20 = (~uVar22 & uVar25 | uVar22 & uVar23) + _DAT_14002d1d4 + iVar14 + uVar20;
  uVar21 = (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar23;
  uVar22 = (~uVar25 & uVar23 | uVar25 & uVar21) + iVar18 + _DAT_14002d1d8 + uVar22;
  uVar20 = (uVar22 * 0x200 | uVar22 >> 0x17) + uVar21;
  uVar25 = (~uVar23 & uVar21 | uVar20 & uVar23) + _DAT_14002d1dc + iVar7 + uVar25;
  uVar25 = (uVar25 * 0x4000 | uVar25 >> 0x12) + uVar20;
  uVar23 = (~uVar21 & uVar20 | uVar25 & uVar21) + _DAT_14002d1e0 + iVar13 + uVar23;
  uVar23 = (uVar23 >> 0xc | uVar23 * 0x100000) + uVar25;
  uVar21 = (~uVar20 & uVar25 | uVar20 & uVar23) + _DAT_14002d1e4 + iVar17 + uVar21;
  uVar22 = (uVar21 * 0x20 | uVar21 >> 0x1b) + uVar23;
  uVar20 = (~uVar25 & uVar23 | uVar25 & uVar22) + _DAT_14002d1e8 + iVar6 + uVar20;
  uVar21 = (uVar20 * 0x200 | uVar20 >> 0x17) + uVar22;
  uVar25 = (~uVar23 & uVar22 | uVar21 & uVar23) + _DAT_14002d1ec + iVar10 + uVar25;
  uVar25 = (uVar25 * 0x4000 | uVar25 >> 0x12) + uVar21;
  uVar23 = (~uVar22 & uVar21 | uVar25 & uVar22) + _DAT_14002d1f0 + iVar16 + uVar23;
  uVar20 = (uVar23 >> 0xc | uVar23 * 0x100000) + uVar25;
  uVar22 = (uVar21 ^ uVar25 ^ uVar20) + _DAT_14002d1f4 + iVar9 + uVar22;
  uVar22 = (uVar22 * 0x10 | uVar22 >> 0x1c) + uVar20;
  uVar21 = (uVar25 ^ uVar20 ^ uVar22) + _DAT_14002d1f8 + iVar13 + uVar21;
  uVar21 = (uVar21 * 0x800 | uVar21 >> 0x15) + uVar22;
  uVar25 = (uVar21 ^ uVar20 ^ uVar22) + _DAT_14002d1fc + iVar15 + uVar25;
  uVar23 = (uVar25 * 0x10000 | uVar25 >> 0x10) + uVar21;
  uVar20 = (uVar21 ^ uVar23 ^ uVar22) + _DAT_14002d200 + iVar18 + uVar20;
  uVar20 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar23;
  uVar22 = (uVar21 ^ uVar23 ^ uVar20) + _DAT_14002d204 + iVar5 + uVar22;
  uVar25 = (uVar22 * 0x10 | uVar22 >> 0x1c) + uVar20;
  uVar21 = (uVar23 ^ uVar20 ^ uVar25) + _DAT_14002d208 + iVar8 + uVar21;
  uVar21 = (uVar21 * 0x800 | uVar21 >> 0x15) + uVar25;
  uVar23 = (uVar21 ^ uVar20 ^ uVar25) + _DAT_14002d20c + iVar10 + uVar23;
  uVar22 = (uVar23 * 0x10000 | uVar23 >> 0x10) + uVar21;
  uVar20 = (uVar21 ^ uVar22 ^ uVar25) + _DAT_14002d210 + iVar11 + uVar20;
  uVar20 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar22;
  uVar25 = (uVar21 ^ uVar22 ^ uVar20) + _DAT_14002d214 + iVar17 + uVar25;
  uVar25 = (uVar25 * 0x10 | uVar25 >> 0x1c) + uVar20;
  uVar21 = (uVar22 ^ uVar20 ^ uVar25) + _DAT_14002d218 + iVar4 + uVar21;
  uVar21 = (uVar21 * 0x800 | uVar21 >> 0x15) + uVar25;
  uVar22 = (uVar21 ^ uVar20 ^ uVar25) + _DAT_14002d21c + iVar7 + uVar22;
  uVar23 = (uVar22 * 0x10000 | uVar22 >> 0x10) + uVar21;
  uVar20 = (uVar21 ^ uVar23 ^ uVar25) + _DAT_14002d220 + iVar12 + uVar20;
  uVar20 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar23;
  uVar25 = (uVar21 ^ uVar23 ^ uVar20) + _DAT_14002d224 + iVar14 + uVar25;
  uVar22 = (uVar25 * 0x10 | uVar25 >> 0x1c) + uVar20;
  uVar21 = (uVar23 ^ uVar20 ^ uVar22) + _DAT_14002d228 + iVar16 + uVar21;
  uVar21 = (uVar21 * 0x800 | uVar21 >> 0x15) + uVar22;
  uVar23 = (uVar21 ^ uVar20 ^ uVar22) + _DAT_14002d22c + iVar19 + uVar23;
  uVar23 = (uVar23 * 0x10000 | uVar23 >> 0x10) + uVar21;
  uVar20 = (uVar21 ^ uVar23 ^ uVar22) + _DAT_14002d230 + iVar6 + uVar20;
  uVar25 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar23;
  uVar22 = ((~uVar21 | uVar25) ^ uVar23) + _DAT_14002d234 + iVar4 + uVar22;
  uVar20 = (uVar22 * 0x40 | uVar22 >> 0x1a) + uVar25;
  uVar21 = ((~uVar23 | uVar20) ^ uVar25) + _DAT_14002d238 + iVar10 + uVar21;
  uVar22 = (uVar21 * 0x400 | uVar21 >> 0x16) + uVar20;
  uVar23 = ((~uVar25 | uVar22) ^ uVar20) + _DAT_14002d23c + iVar18 + uVar23;
  uVar21 = (uVar23 * 0x8000 | uVar23 >> 0x11) + uVar22;
  uVar25 = ((~uVar20 | uVar21) ^ uVar22) + _DAT_14002d240 + iVar9 + uVar25;
  uVar23 = (uVar25 >> 0xb | uVar25 * 0x200000) + uVar21;
  uVar20 = ((~uVar22 | uVar23) ^ uVar21) + _DAT_14002d244 + iVar16 + uVar20;
  uVar25 = (uVar20 * 0x40 | uVar20 >> 0x1a) + uVar23;
  uVar22 = ((~uVar21 | uVar25) ^ uVar23) + _DAT_14002d248 + iVar7 + uVar22;
  uVar20 = (uVar22 * 0x400 | uVar22 >> 0x16) + uVar25;
  uVar21 = ((~uVar23 | uVar20) ^ uVar25) + _DAT_14002d24c + iVar11 + uVar21;
  uVar22 = (uVar21 * 0x8000 | uVar21 >> 0x11) + uVar20;
  uVar23 = ((~uVar25 | uVar22) ^ uVar20) + _DAT_14002d250 + iVar5 + uVar23;
  uVar21 = (uVar23 >> 0xb | uVar23 * 0x200000) + uVar22;
  uVar25 = ((~uVar20 | uVar21) ^ uVar22) + _DAT_14002d254 + iVar13 + uVar25;
  uVar23 = (uVar25 * 0x40 | uVar25 >> 0x1a) + uVar21;
  uVar20 = ((~uVar22 | uVar23) ^ uVar21) + _DAT_14002d258 + iVar19 + uVar20;
  uVar25 = (uVar20 * 0x400 | uVar20 >> 0x16) + uVar23;
  uVar22 = ((~uVar21 | uVar25) ^ uVar23) + _DAT_14002d25c + iVar12 + uVar22;
  uVar20 = (uVar22 * 0x8000 | uVar22 >> 0x11) + uVar25;
  uVar21 = ((~uVar23 | uVar20) ^ uVar25) + _DAT_14002d260 + iVar17 + uVar21;
  uVar24 = (uVar21 >> 0xb | uVar21 * 0x200000) + uVar20;
  uVar23 = ((~uVar25 | uVar24) ^ uVar20) + _DAT_14002d264 + iVar8 + uVar23;
  uVar21 = (uVar23 * 0x40 | uVar23 >> 0x1a) + uVar24;
  uVar25 = ((~uVar20 | uVar21) ^ uVar24) + _DAT_14002d268 + iVar15 + uVar25;
  uVar22 = (uVar25 * 0x400 | uVar25 >> 0x16) + uVar21;
  uVar20 = ((~uVar24 | uVar22) ^ uVar21) + _DAT_14002d26c + iVar6 + uVar20;
  uVar20 = (uVar20 * 0x8000 | uVar20 >> 0x11) + uVar22;
  uVar24 = ((~uVar21 | uVar20) ^ uVar22) + _DAT_14002d270 + iVar14 + uVar24;
  *param_1 = *param_1 + uVar21;
  param_1[2] = uVar2 + uVar20;
  param_1[1] = (uVar24 >> 0xb | uVar24 * 0x200000) + uVar1 + uVar20;
  param_1[3] = uVar3 + uVar22;
  return;
}



===== MD5_PadMessage @ 140003cdc =====

void MD5_PadMessage(int *param_1,uint param_2,undefined8 *param_3,int param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  
  if (param_2 != 0x40) {
    *(undefined1 *)((ulonglong)param_2 + (longlong)param_3) = 0x80;
    uVar1 = param_2 + 1;
    if (uVar1 < 0x39) {
      if (uVar1 < 0x38) {
        memset((void *)((ulonglong)uVar1 + (longlong)param_3),0,(ulonglong)(0x38 - uVar1));
      }
      *(undefined4 *)((longlong)param_3 + 0x3c) = 0;
      lVar3 = 0x10;
      *(int *)(param_3 + 7) = param_4 << 3;
      puVar2 = param_3;
      do {
        *(undefined4 *)((longlong)puVar2 + (longlong)param_1 + (0x10 - (longlong)param_3)) =
             *(undefined4 *)puVar2;
        puVar2 = (undefined8 *)((longlong)puVar2 + 4);
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
    }
    else {
      if (uVar1 < 0x40) {
        memset((void *)((ulonglong)uVar1 + (longlong)param_3),0,(ulonglong)(0x40 - uVar1));
      }
      lVar4 = 0x10;
      lVar3 = 0x10;
      puVar2 = param_3;
      do {
        *(undefined4 *)((longlong)puVar2 + (longlong)param_1 + (0x10 - (longlong)param_3)) =
             *(undefined4 *)puVar2;
        puVar2 = (undefined8 *)((longlong)puVar2 + 4);
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
      MD5_CalculateDigest(param_1);
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      param_3[4] = 0;
      param_3[5] = 0;
      param_3[6] = 0;
      *(undefined4 *)((longlong)param_3 + 0x3c) = 0;
      *(int *)(param_3 + 7) = param_4 << 3;
      puVar2 = param_3;
      do {
        *(undefined4 *)((longlong)puVar2 + (longlong)param_1 + (0x10 - (longlong)param_3)) =
             *(undefined4 *)puVar2;
        puVar2 = (undefined8 *)((longlong)puVar2 + 4);
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
  }
  return;
}



===== MD5_ProcessMessage @ 140003de0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void MD5_ProcessMessage(undefined8 *param_1,uint param_2,int *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 auStack_e8 [32];
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  undefined1 local_b8 [64];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  if ((param_1 != (undefined8 *)0x0) &&
     (local_38 = __security_cookie ^ (ulonglong)auStack_e8, param_3 != (int *)0x0)) {
    param_3[0] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    memset(&local_c8,0,0x50);
    local_c8 = 0x67452301;
    local_c4 = -0x10325477;
    local_c0 = -0x67452302;
    local_bc = 0x10325476;
    uVar1 = param_2;
    if (0x3f < param_2) {
      uVar2 = (ulonglong)(param_2 >> 6);
      do {
        local_78 = *param_1;
        uStack_70 = param_1[1];
        local_68 = param_1[2];
        uStack_60 = param_1[3];
        local_58 = param_1[4];
        uStack_50 = param_1[5];
        local_48 = param_1[6];
        uStack_40 = param_1[7];
        memmove(local_b8,&local_78,0x40);
        MD5_CalculateDigest(&local_c8);
        param_1 = param_1 + 8;
        uVar1 = uVar1 - 0x40;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    memset(&local_78,0,0x40);
    if (uVar1 != 0) {
      memmove(&local_78,param_1,(ulonglong)(uVar1 & 0xffff));
    }
    MD5_PadMessage(&local_c8,uVar1,&local_78,param_2);
    MD5_CalculateDigest(&local_c8);
    *param_3 = local_c8;
    param_3[1] = local_c4;
    param_3[2] = local_c0;
    param_3[3] = local_bc;
  }
  return;
}



===== _isprintf @ 140003f24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400040d6) */
/* WARNING: Removing unreachable block (ram,0x000140004210) */
/* WARNING: Removing unreachable block (ram,0x0001400040fe) */
/* WARNING: Removing unreachable block (ram,0x000140004176) */
/* WARNING: Removing unreachable block (ram,0x0001400042f0) */
/* WARNING: Removing unreachable block (ram,0x0001400042f4) */

int _isprintf(char *param_1,char *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong *puVar3;
  int iVar4;
  char *pcVar5;
  char cVar6;
  uint uVar7;
  char *pcVar8;
  ulonglong uVar9;
  byte bVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  ulonglong *puVar14;
  short sVar15;
  longlong lVar16;
  int iVar17;
  char cVar18;
  undefined2 local_c8;
  uint local_c4;
  uint local_bc;
  uint *local_b8;
  int local_b0;
  uint local_ac;
  char *local_a8;
  char *local_a0;
  undefined1 local_88 [63];
  undefined1 local_49;
  ulonglong local_48 [2];
  
  local_48[0] = __security_cookie ^ (ulonglong)&local_c8;
  local_a0 = (char *)0x0;
  local_b0 = 0;
  local_b8 = param_3;
  local_a8 = param_2;
LAB_140003f72:
  pcVar5 = local_a8;
  uVar11 = 0;
  cVar6 = *local_a8;
  if (cVar6 != '\0') {
    do {
      if (cVar6 == '%') break;
      local_a8 = local_a8 + 1;
      cVar6 = *local_a8;
    } while (cVar6 != '\0');
  }
  uVar7 = (int)local_a8 - (int)pcVar5;
  if (uVar7 != 0) {
    uVar13 = uVar7 & 0xffff;
    if ((short)uVar7 != 0) {
      lVar16 = (longlong)param_1 - (longlong)pcVar5;
      do {
        pcVar5[lVar16] = *pcVar5;
        pcVar5 = pcVar5 + 1;
        uVar12 = (short)uVar13 - 1;
        uVar13 = (uint)uVar12;
      } while (uVar12 != 0);
    }
    param_1 = param_1 + (int)uVar7;
    local_b0 = local_b0 + uVar7;
  }
  cVar18 = '\0';
  if (cVar6 == '\0') {
LAB_140004632:
    *param_1 = '\0';
    return local_b0;
  }
  local_a8 = local_a8 + 1;
  local_ac = 0;
  uVar13 = 0xffffffff;
  local_bc = 0;
  uVar7 = uVar11;
  cVar6 = cVar18;
LAB_140003ffb:
  do {
    iVar17 = (int)*local_a8;
    local_a8 = local_a8 + 1;
    while (iVar17 < 100) {
      if (iVar17 == 99) {
        uVar11 = *local_b8;
        local_b8 = local_b8 + 2;
        local_88[0] = (char)uVar11;
        goto LAB_140004116;
      }
      if (iVar17 == 0x2b) {
        cVar6 = '+';
        goto LAB_140003ffb;
      }
      if (iVar17 == 0x2d) {
        uVar7 = uVar7 | 4;
        goto LAB_140003ffb;
      }
      if (iVar17 == 0x2e) {
        uVar13 = 0;
      }
      else {
        if (iVar17 == 0x30) {
          uVar7 = uVar7 | 0x80;
          goto LAB_140003ffb;
        }
        if (iVar17 < 0x31) goto LAB_140004149;
        if (0x39 < iVar17) {
          if (iVar17 == 0x4f) goto LAB_1400041ef;
          if (iVar17 == 0x55) goto LAB_140004188;
          if (iVar17 != 0x58) goto LAB_140004149;
          local_a0 = "0123456789ABCDEF";
          goto LAB_14000415f;
        }
        local_bc = uVar11;
        do {
          local_bc = iVar17 + local_bc * 10 + -0x30;
          iVar17 = (int)*local_a8;
          local_a8 = local_a8 + 1;
        } while (iVar17 - 0x30U < 10);
      }
    }
    if ((iVar17 == 100) || (iVar17 == 0x69)) {
      uVar11 = *local_b8;
      cVar18 = cVar6;
      if ((int)uVar11 < 0) {
        cVar18 = '-';
      }
      iVar4 = 10;
      uVar11 = (uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f);
      goto LAB_140004239;
    }
  } while (iVar17 == 0x6c);
  if (iVar17 == 0x6f) {
LAB_1400041ef:
    uVar11 = *local_b8;
    iVar4 = 8;
  }
  else {
    if (iVar17 == 0x70) {
      uVar11 = *local_b8;
      local_a0 = "0123456789abcdef";
      iVar4 = 0x10;
      uVar7 = uVar7 | 2;
      iVar17 = 0x78;
      goto LAB_140004239;
    }
    if (iVar17 == 0x73) {
      puVar3 = *(ulonglong **)local_b8;
      local_b8 = local_b8 + 2;
      puVar14 = (ulonglong *)&s__NULL_;
      if (puVar3 != (ulonglong *)0x0) {
        puVar14 = puVar3;
      }
      bVar10 = (byte)*puVar14;
      puVar3 = puVar14;
      while (bVar10 != 0) {
        puVar3 = (ulonglong *)((longlong)puVar3 + 1);
        uVar11 = uVar11 + 1;
        bVar10 = *(byte *)puVar3;
      }
      goto LAB_140004302;
    }
    if (iVar17 != 0x75) {
      if (iVar17 == 0x78) {
        local_a0 = "0123456789abcdef";
LAB_14000415f:
        uVar11 = *local_b8;
        iVar4 = 0x10;
        goto LAB_140004239;
      }
LAB_140004149:
      if (iVar17 != 0) {
        local_88[0] = (char)iVar17;
LAB_140004116:
        puVar14 = (ulonglong *)local_88;
        uVar11 = 1;
        goto LAB_140004302;
      }
      goto LAB_140004632;
    }
LAB_140004188:
    uVar11 = *local_b8;
    iVar4 = 10;
  }
LAB_140004239:
  local_b8 = local_b8 + 2;
  puVar14 = local_48;
  uVar1 = uVar7 & 0xffffff7f;
  if ((int)uVar13 < 0) {
    uVar1 = uVar7;
  }
  uVar7 = uVar1;
  if ((uVar11 != 0) || (uVar13 != 0)) {
    puVar14 = local_48;
    if (iVar4 == 8) {
      do {
        bVar10 = (byte)uVar11;
        puVar14 = (ulonglong *)((longlong)puVar14 + -1);
        uVar11 = uVar11 >> 3;
        *(byte *)puVar14 = bVar10 & 7 | 0x30;
      } while (uVar11 != 0);
    }
    else if (iVar4 == 10) {
      if (uVar11 < 10) {
        puVar14 = (ulonglong *)&local_49;
        local_49 = (byte)uVar11 | 0x30;
      }
      else {
        do {
          puVar14 = (ulonglong *)((longlong)puVar14 + -1);
          uVar1 = (int)uVar11 / 10;
          *(byte *)puVar14 = (char)uVar11 + (char)uVar1 * -10 | 0x30;
          uVar11 = uVar1;
        } while (uVar1 != 0);
      }
    }
    else if (iVar4 == 0x10) {
      do {
        puVar14 = (ulonglong *)((longlong)puVar14 + -1);
        uVar1 = uVar11 & 0xf;
        uVar11 = uVar11 >> 4;
        *(char *)puVar14 = local_a0[uVar1];
      } while (uVar11 != 0);
    }
  }
  uVar11 = (int)local_48 - (int)puVar14;
  local_ac = uVar13;
LAB_140004302:
  local_c4 = uVar11;
  if ((int)uVar11 < (int)local_ac) {
    local_c4 = local_ac;
  }
  if (cVar18 == '\0') {
    if ((uVar7 & 2) != 0) {
      local_c4 = local_c4 + 2;
    }
  }
  else {
    local_c4 = local_c4 + 1;
  }
  uVar13 = local_c4;
  if ((int)local_c4 < (int)local_bc) {
    uVar13 = local_bc;
  }
  if (((uVar7 & 0x84) == 0) && (uVar1 = local_bc - local_c4, 0 < (int)uVar1)) {
    if (0x10 < (int)uVar1) {
      pcVar5 = param_1 + -0x14002d150;
      uVar2 = (uVar1 - 0x11 >> 4) + 1;
      uVar9 = (ulonglong)uVar2;
      uVar1 = uVar1 + uVar2 * -0x10;
      param_1 = param_1 + uVar9 * 0x10;
      do {
        sVar15 = 0x10;
        pcVar8 = s___0000000000000000_14002d14f;
        do {
          pcVar8 = pcVar8 + 1;
          pcVar5[(longlong)pcVar8] = *pcVar8;
          sVar15 = sVar15 + -1;
        } while (sVar15 != 0);
        pcVar5 = pcVar5 + 0x10;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    uVar2 = uVar1 & 0xffff;
    pcVar5 = s___0000000000000000_14002d14f;
    if ((short)uVar1 != 0) {
      do {
        pcVar5 = pcVar5 + 1;
        (param_1 + -0x14002d150)[(longlong)pcVar5] = *pcVar5;
        uVar12 = (short)uVar2 - 1;
        uVar2 = (uint)uVar12;
      } while (uVar12 != 0);
    }
    param_1 = param_1 + (int)uVar1;
  }
  if (cVar18 == '\0') {
    if ((uVar7 & 2) != 0) {
      local_c8 = CONCAT11((char)iVar17,0x30);
      *(undefined2 *)param_1 = local_c8;
      param_1 = param_1 + 2;
    }
  }
  else {
    *param_1 = cVar18;
    param_1 = param_1 + 1;
  }
  if (((uVar7 & 0x84) == 0x80) && (uVar1 = local_bc - local_c4, 0 < (int)uVar1)) {
    if (0x10 < (int)uVar1) {
      pcVar5 = param_1 + -0x14002d160;
      uVar2 = (uVar1 - 0x11 >> 4) + 1;
      uVar9 = (ulonglong)uVar2;
      uVar1 = uVar1 + uVar2 * -0x10;
      param_1 = param_1 + uVar9 * 0x10;
      do {
        sVar15 = 0x10;
        pcVar8 = s___0000000000000000_14002d14f + 0x11;
        do {
          pcVar5[(longlong)pcVar8] = *pcVar8;
          pcVar8 = pcVar8 + 1;
          sVar15 = sVar15 + -1;
        } while (sVar15 != 0);
        pcVar5 = pcVar5 + 0x10;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    uVar2 = uVar1 & 0xffff;
    pcVar5 = s___0000000000000000_14002d14f + 0x11;
    if ((short)uVar1 != 0) {
      do {
        (param_1 + -0x14002d160)[(longlong)pcVar5] = *pcVar5;
        pcVar5 = pcVar5 + 1;
        uVar12 = (short)uVar2 - 1;
        uVar2 = (uint)uVar12;
      } while (uVar12 != 0);
    }
    param_1 = param_1 + (int)uVar1;
  }
  local_ac = local_ac - uVar11;
  if (0 < (int)local_ac) {
    if (0x10 < (int)local_ac) {
      pcVar5 = param_1 + -0x14002d160;
      uVar1 = (local_ac - 0x11 >> 4) + 1;
      uVar9 = (ulonglong)uVar1;
      local_ac = local_ac + uVar1 * -0x10;
      param_1 = param_1 + uVar9 * 0x10;
      do {
        sVar15 = 0x10;
        pcVar8 = s___0000000000000000_14002d14f + 0x11;
        do {
          pcVar5[(longlong)pcVar8] = *pcVar8;
          pcVar8 = pcVar8 + 1;
          sVar15 = sVar15 + -1;
        } while (sVar15 != 0);
        pcVar5 = pcVar5 + 0x10;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    uVar1 = local_ac & 0xffff;
    pcVar5 = s___0000000000000000_14002d14f + 0x11;
    if ((short)local_ac != 0) {
      do {
        (param_1 + -0x14002d160)[(longlong)pcVar5] = *pcVar5;
        pcVar5 = pcVar5 + 1;
        uVar12 = (short)uVar1 - 1;
        uVar1 = (uint)uVar12;
      } while (uVar12 != 0);
    }
    param_1 = param_1 + (int)local_ac;
  }
  uVar1 = uVar11 & 0xffff;
  if ((short)uVar11 != 0) {
    lVar16 = (longlong)param_1 - (longlong)puVar14;
    do {
      *(byte *)((longlong)puVar14 + lVar16) = (byte)*puVar14;
      puVar14 = (ulonglong *)((longlong)puVar14 + 1);
      uVar12 = (short)uVar1 - 1;
      uVar1 = (uint)uVar12;
    } while (uVar12 != 0);
  }
  param_1 = param_1 + (int)uVar11;
  if (((uVar7 & 4) != 0) && (local_bc = local_bc - local_c4, 0 < (int)local_bc)) {
    if (0x10 < (int)local_bc) {
      pcVar5 = param_1 + -0x14002d150;
      uVar11 = (local_bc - 0x11 >> 4) + 1;
      uVar9 = (ulonglong)uVar11;
      local_bc = local_bc + uVar11 * -0x10;
      param_1 = param_1 + uVar9 * 0x10;
      do {
        sVar15 = 0x10;
        pcVar8 = s___0000000000000000_14002d14f;
        do {
          pcVar8 = pcVar8 + 1;
          pcVar5[(longlong)pcVar8] = *pcVar8;
          sVar15 = sVar15 + -1;
        } while (sVar15 != 0);
        pcVar5 = pcVar5 + 0x10;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    uVar11 = local_bc & 0xffff;
    pcVar5 = s___0000000000000000_14002d14f;
    if ((short)local_bc != 0) {
      do {
        pcVar5 = pcVar5 + 1;
        (param_1 + -0x14002d150)[(longlong)pcVar5] = *pcVar5;
        uVar12 = (short)uVar11 - 1;
        uVar11 = (uint)uVar12;
      } while (uVar12 != 0);
    }
    param_1 = param_1 + (int)local_bc;
  }
  local_b0 = local_b0 + uVar13;
  goto LAB_140003f72;
}



===== _isscanf @ 140004660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int _isscanf(byte *param_1,byte *param_2,undefined8 *param_3)

{
  byte *pbVar1;
  byte bVar2;
  int *piVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  byte *pbVar9;
  undefined8 *puVar10;
  int iVar11;
  longlong lVar12;
  uint uVar13;
  uint uVar14;
  undefined1 auStack_88 [32];
  byte local_68;
  byte local_67;
  byte local_66 [62];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  bVar2 = *param_2;
  iVar11 = 0;
  uVar14 = 0;
  do {
    uVar13 = (uint)bVar2;
    param_2 = param_2 + 1;
    if (uVar13 == 0) {
      return iVar11;
    }
    if (uVar13 == 0x20) {
      for (; *param_1 == 0x20; param_1 = param_1 + 1) {
      }
    }
    else if (uVar13 == 0x25) {
      lVar12 = 0;
      bVar6 = false;
      bVar5 = false;
      bVar4 = false;
LAB_1400046b4:
      do {
        while( true ) {
          bVar2 = *param_2;
          uVar13 = (uint)bVar2;
          param_2 = param_2 + 1;
          bVar7 = bVar5;
          if (bVar2 < 0x65) break;
          if (bVar2 == 0x68) {
            bVar4 = true;
          }
          else {
            if (bVar2 == 0x69) {
              uVar14 = 0;
              goto LAB_1400047ae;
            }
            if (bVar2 != 0x6c) {
              if (bVar2 == 0x6f) goto LAB_140004768;
              if (bVar2 == 0x73) {
                iVar8 = 1;
                goto LAB_1400047b8;
              }
              if (bVar2 != 0x75) {
                if (bVar2 != 0x78) goto LAB_14000478f;
                goto LAB_14000475d;
              }
LAB_140004773:
              uVar14 = 10;
              bVar7 = bVar5;
              goto LAB_1400047ae;
            }
            bVar5 = true;
          }
        }
        if (bVar2 == 100) goto LAB_140004773;
        if (bVar2 == 0x25) goto LAB_1400048bd;
        if (bVar2 < 0x30) goto LAB_14000478f;
        if (bVar2 < 0x3a) {
          lVar12 = (ulonglong)bVar2 + (lVar12 * 5 + -0x18) * 2;
          goto LAB_1400046b4;
        }
        if (bVar2 == 0x44) {
          bVar5 = true;
          goto LAB_140004773;
        }
      } while (bVar2 == 0x4c);
      if (bVar2 == 0x4f) {
        bVar5 = true;
LAB_140004768:
        uVar14 = 8;
        bVar7 = bVar5;
LAB_1400047ae:
        bVar5 = bVar7;
        iVar8 = 2;
      }
      else {
        if (bVar2 == 0x58) {
          bVar5 = true;
LAB_14000475d:
          uVar14 = 0x10;
          bVar7 = bVar5;
          goto LAB_1400047ae;
        }
        if (bVar2 == 0x62) {
          uVar14 = 10;
          bVar6 = true;
          goto LAB_1400047ae;
        }
        if (bVar2 != 99) {
LAB_14000478f:
          uVar14 = 10;
          bVar7 = true;
          if (0x19 < bVar2 - 0x41) {
            bVar7 = bVar5;
          }
          goto LAB_1400047ae;
        }
        iVar8 = 0;
      }
LAB_1400047b8:
      for (; *param_1 == 0x20; param_1 = param_1 + 1) {
      }
      if (iVar8 == 0) {
        bVar2 = *param_1;
        param_1 = param_1 + 1;
        *(byte *)*param_3 = bVar2;
      }
      else {
        if (iVar8 != 1) {
          if (iVar8 == 2) {
            pbVar9 = &local_68;
            if (0x3e < lVar12 - 1U) {
              lVar12 = 0x3f;
            }
            if ((uVar14 == 0x10) && (*param_1 == 0x30)) {
              pbVar1 = param_1 + 1;
              if ((*pbVar1 + 0xa8 & 0xdf) == 0) {
                local_68 = 0x30;
                pbVar9 = local_66;
                param_1 = param_1 + 2;
                local_67 = *pbVar1;
              }
            }
            for (; lVar12 != 0; lVar12 = lVar12 + -1) {
              bVar2 = *param_1;
              if (((0x1b < (byte)(bVar2 - 0x2b)) || ((0xfc07fe1U >> (bVar2 - 0x2b & 0x1f) & 1) == 0)
                  ) && (5 < (byte)(bVar2 + 0x9f))) break;
              *pbVar9 = bVar2;
              param_1 = param_1 + 1;
              pbVar9 = pbVar9 + 1;
            }
            *pbVar9 = 0;
            iVar11 = iVar11 + 1;
            iVar8 = istrtol(&local_68,uVar14);
            puVar10 = param_3 + 1;
            piVar3 = (int *)*param_3;
            param_3 = puVar10;
            if (bVar4) {
              *(short *)piVar3 = (short)iVar8;
            }
            else if ((bVar5) || (!bVar6)) {
              *piVar3 = iVar8;
            }
            else {
              *(char *)piVar3 = (char)iVar8;
            }
          }
          goto LAB_1400048c8;
        }
        pbVar9 = (byte *)*param_3;
        for (; ((bVar2 = *param_1, bVar2 != 0 && (bVar2 != 0x20)) &&
               ((int)(char)bVar2 != (uint)*param_2)); param_1 = param_1 + 1) {
          *pbVar9 = bVar2;
          pbVar9 = pbVar9 + 1;
        }
        *pbVar9 = 0;
      }
      param_3 = param_3 + 1;
      iVar11 = iVar11 + 1;
    }
    else {
LAB_1400048bd:
      if ((int)(char)*param_1 != uVar13) {
        return iVar11;
      }
      param_1 = param_1 + 1;
    }
LAB_1400048c8:
    bVar2 = *param_2;
  } while( true );
}



===== char_to_number @ 140004904 =====

undefined8 char_to_number(int param_1)

{
  ulonglong uVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = (char)param_1;
  cVar3 = '\0';
  uVar1 = (ulonglong)((int)cVar2 - 0x30U);
  if ((int)cVar2 - 0x30U < 10) {
    cVar3 = cVar2 + -0x30;
  }
  else {
    uVar1 = (ulonglong)(param_1 - 0x41U);
    if ((byte)(param_1 - 0x41U) < 6) {
      cVar3 = cVar2 + -0x37;
    }
    else {
      uVar1 = (ulonglong)(param_1 - 0x61U);
      if ((byte)(param_1 - 0x61U) < 6) {
        cVar3 = cVar2 + -0x57;
      }
    }
  }
  return CONCAT71((int7)(uVar1 >> 8),cVar3);
}



===== dhcpv6_do_discovery @ 140004930 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dhcpv6_do_discovery(undefined2 param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined8 uVar3;
  int *piVar4;
  
  uip_buf = (undefined2 *)&iscsiContext;
  memset(&iscsiContext,0,0x5ea);
  puVar2 = uip_buf;
  DAT_14002d938 = g_netif + 0x31;
  piVar4 = &dhcpv6_retry_timeout;
  DAT_14002d934 = *(uint *)(g_netif + 0x33) & 0xffffff;
  DAT_14002d9c4 = 0;
  _DAT_14002d9cc = param_1;
  while( true ) {
    uVar3 = iscsiBootCancel();
    if ((int)uVar3 != 0) {
      return 0xfffffffe;
    }
    iVar1 = *piVar4;
    dhcpv6_send_solicit_packet(puVar2);
    uVar3 = dhcpv6_wait_for_dhcp_done((int *)&DAT_140075444,iVar1);
    if ((int)uVar3 == 0) break;
    DAT_14002d9c0 = DAT_14002d9c0 + (short)iVar1;
    piVar4 = piVar4 + 1;
    if (0x14002d10f < (longlong)piVar4) {
      return 0xffffffff;
    }
  }
  return 0;
}



===== dhcpv6_handle_advertise @ 140004a00 =====

void dhcpv6_handle_advertise(undefined2 *param_1,ushort param_2)

{
  undefined1 uVar1;
  int iVar2;
  ulonglong uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  int iVar6;
  char cVar7;
  undefined2 *puVar8;
  short sVar9;
  char *_Str1;
  int iVar10;
  int iVar11;
  longlong lVar12;
  char *local_res18;
  
  cVar7 = '\0';
  lVar12 = 0;
  local_res18 = (char *)0x0;
  iVar10 = 0;
  iVar6 = 0;
  if (DAT_14002d9c8 == 1) {
    iVar11 = 0;
    DAT_14002d9c8 = 2;
    _Str1 = (char *)0x0;
    if ((ulonglong)param_2 != 4) {
      uVar3 = 0;
      iVar10 = 0;
      do {
        uVar4 = *(short *)((longlong)param_1 + uVar3 + 0x42) << 8 |
                (ushort)*(byte *)((longlong)param_1 + uVar3 + 0x43);
        if (uVar4 == 3) {
          if ((DAT_14002d9cc & 1) != 0) {
            iVar2 = dhcpv6_process_opt_ia_na((longlong)param_1 + uVar3 + 0x42);
            iVar6 = iVar6 + iVar2;
          }
        }
        else if (uVar4 == 0x10) {
          cVar7 = *(char *)((longlong)param_1 + uVar3 + 0x4b);
          local_res18 = (char *)((longlong)param_1 + uVar3 + 0x4c);
        }
        else if (uVar4 == 0x11) {
          iVar10 = ((uint)(ushort)(*(short *)((longlong)param_1 + uVar3 + 0x44) << 8) |
                   (uint)*(byte *)((longlong)param_1 + uVar3 + 0x45)) - 4;
          lVar12 = (longlong)param_1 + uVar3 + 0x4a;
        }
        else if ((uVar4 == 0x17) && ((DAT_14002d9cc & 2) != 0)) {
          dhcpv6_process_opt_dns_servers((longlong)param_1 + uVar3 + 0x42);
        }
        iVar11 = iVar11 + 4 +
                 ((uint)(ushort)(*(short *)((longlong)param_1 + uVar3 + 0x44) << 8) |
                 (uint)*(byte *)((longlong)param_1 + uVar3 + 0x45));
        uVar3 = (ulonglong)iVar11;
        _Str1 = local_res18;
      } while (uVar3 < (ulonglong)param_2 - 4);
    }
    if ((((DAT_14002d9cc & 2) != 0) && ('\0' < cVar7)) &&
       (iVar11 = strncmp(_Str1,(char *)(*(longlong *)
                                         (iscsiGlobalsPtr + 0xda0 +
                                         (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x58),
                         (longlong)cVar7), iVar11 == 0)) {
      dhcpv6_parse_vendor_option(lVar12,iVar10);
      DAT_14002d9c4 = 1;
    }
    if (((DAT_14002d9cc & 1) != 0) && (0 < iVar6)) {
      dhcpv6_send_request_packet(param_1);
      DAT_14002d9c4 = 1;
    }
    if (DAT_14002d9c4 != 0) {
      puVar8 = param_1 + 0xb;
      sVar9 = 0x10;
      puVar5 = (undefined1 *)
               (*(longlong *)
                 (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
               0x498);
      do {
        uVar1 = *(undefined1 *)puVar8;
        puVar8 = (undefined2 *)((longlong)puVar8 + 1);
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
        sVar9 = sVar9 + -1;
      } while (sVar9 != 0);
    }
  }
  return;
}



===== dhcpv6_init_packet @ 140004bd8 =====

uint dhcpv6_init_packet(undefined2 *param_1,byte param_2)

{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  ulonglong uVar7;
  ulonglong uVar6;
  undefined4 *puVar8;
  ushort uVar9;
  short sVar10;
  ushort uVar11;
  ulonglong uVar12;
  
  *(undefined8 *)(param_1 + 0x13) = 0;
  *(undefined8 *)(param_1 + 0x17) = 0;
  param_1[0x13] = 0x2ff;
  *(undefined1 *)((longlong)param_1 + 0x33) = 1;
  *(undefined1 *)((longlong)param_1 + 0x35) = 2;
  *param_1 = 0x3333;
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_1 + 0x19);
  *(undefined1 *)((longlong)param_1 + 3) = *(undefined1 *)((longlong)param_1 + 0x33);
  *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_1 + 0x1a);
  *(undefined1 *)((longlong)param_1 + 5) = *(undefined1 *)((longlong)param_1 + 0x35);
  *(undefined4 *)(param_1 + 0x1b) = 0x23022202;
  if ((*(uint *)(param_1 + 0x1f) & 0xff) != (uint)param_2) {
    DAT_14002d934 = DAT_14002d934 + 1;
  }
  *(uint *)(param_1 + 0x1f) = DAT_14002d934 << 8 | *(uint *)(param_1 + 0x1f) & 0xff;
  *(byte *)(param_1 + 0x1f) = param_2;
  puVar5 = DAT_14002d938;
  if (param_2 == 3) {
    uVar2 = (uint)(ushort)((param_1[0x1d] << 8 | (ushort)*(byte *)((longlong)param_1 + 0x3b)) + 0x36
                          );
  }
  else {
    *(undefined4 *)(param_1 + 0x21) = 0xa000100;
    *(undefined4 *)(param_1 + 0x23) = 0x1000300;
    sVar10 = 6;
    puVar3 = puVar5;
    do {
      puVar3[(longlong)(param_1 + 0x21) + (8 - (longlong)puVar5)] = *puVar3;
      puVar3 = puVar3 + 1;
      sVar10 = sVar10 + -1;
    } while (sVar10 != 0);
    puVar8 = (undefined4 *)(param_1 + 0x28);
    uVar12 = 0x12;
    uVar6 = 0xffffffffffffffff;
    do {
      uVar7 = uVar6;
      uVar6 = uVar7 + 1;
    } while (*(char *)(*(longlong *)
                        (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8
                        ) + 0x58 + uVar6) != '\0');
    uVar9 = (ushort)uVar6;
    if (uVar9 != 0) {
      uVar6 = uVar6 & 0xffff;
      *(undefined2 *)puVar8 = 0x1000;
      param_1[0x29] = (ushort)(uVar6 + 6 >> 8) & 0xff | (short)(uVar6 << 8) + 0x600U;
      uVar2 = swap_dword(0x113d);
      *(uint *)(param_1 + 0x2a) = uVar2;
      param_1[0x2c] = uVar9 << 8 | uVar9 >> 8;
      puVar4 = param_1 + 0x2d;
      puVar5 = (undefined1 *)
               (*(longlong *)
                 (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
               0x58);
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *(undefined1 *)puVar4 = uVar1;
        puVar4 = (undefined2 *)((longlong)puVar4 + 1);
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
      uVar12 = (ulonglong)((int)uVar7 + 0x1d);
      puVar8 = (undefined4 *)((longlong)param_1 + uVar6 + 0x5a);
      puVar5 = DAT_14002d938;
    }
    uVar11 = (short)uVar12 + 0x20;
    uVar9 = DAT_14002d9c0 << 8;
    *puVar8 = 0xc000300;
    puVar8[1] = *(undefined4 *)(puVar5 + 2);
    *(ushort *)(puVar8 + 5) = uVar9 | DAT_14002d9c0 >> 8;
    *(undefined2 *)((longlong)puVar8 + 0x1e) = 0x1700;
    uVar2 = (int)CONCAT62((int6)(uVar12 >> 0x10),uVar11) + 0x3e;
    *(undefined8 *)(puVar8 + 2) = 0;
    puVar8[4] = 0x2000800;
    *(undefined4 *)((longlong)puVar8 + 0x16) = 0x6000600;
    *(undefined4 *)((longlong)puVar8 + 0x1a) = 0x11001000;
    param_1[0x1d] = (ushort)((ulonglong)uVar11 + 8 >> 8) & 0xff | uVar11 * 0x100 + 0x800;
  }
  return uVar2;
}



===== dhcpv6_parse_vendor_option @ 140004e14 =====

void dhcpv6_parse_vendor_option(longlong param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  longlong lVar6;
  char *pcVar7;
  int iVar8;
  short *psVar9;
  short *psVar10;
  
  if (0 < param_2) {
    iVar8 = 0;
    do {
      psVar10 = (short *)(iVar8 + param_1);
      sVar2 = psVar10[1];
      psVar9 = psVar10 + 2;
      bVar1 = *(byte *)((longlong)psVar10 + 3);
      lVar6 = -1;
      do {
        lVar6 = lVar6 + 1;
      } while (*(char *)((longlong)psVar9 + lVar6) != '\0');
      uVar4 = *psVar10 << 8 | (ushort)*(byte *)((longlong)psVar10 + 1);
      if ((uVar4 == 0xc9) || (uVar4 == 0xca)) {
        iscsiBootCancel();
      }
      else if (uVar4 == 0xcb) {
        iVar5 = (int)lVar6;
        if (0x80 < iVar5) {
          iVar5 = 0x80;
        }
        *(undefined1 *)((longlong)iVar5 + 4 + (longlong)psVar10) = 0;
        pcVar7 = (char *)(*(longlong *)
                           (iscsiGlobalsPtr + 0xda0 +
                           (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x200);
        do {
          sVar3 = *psVar9;
          psVar9 = (short *)((longlong)psVar9 + 1);
          *pcVar7 = (char)sVar3;
          pcVar7 = pcVar7 + 1;
        } while ((char)sVar3 != '\0');
        itolowerstr((char *)(*(longlong *)
                              (iscsiGlobalsPtr + 0xda0 +
                              (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x200));
      }
      iVar8 = iVar8 + 4 + ((uint)(ushort)(sVar2 << 8) | (uint)bVar1);
    } while (iVar8 < param_2);
  }
  return;
}



===== dhcpv6_process_opt_dns_servers @ 140004f2c =====

void dhcpv6_process_opt_dns_servers(longlong param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  short sVar3;
  undefined1 *puVar4;
  short sVar5;
  undefined1 *puVar6;
  
  sVar5 = 0x10;
  uVar2 = *(short *)(param_1 + 2) << 8 | (ushort)*(byte *)(param_1 + 3);
  if (0xf < uVar2) {
    puVar6 = (undefined1 *)(param_1 + 4);
    sVar3 = 0x10;
    puVar4 = (undefined1 *)
             (*(longlong *)
               (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x4a8
             );
    do {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 1;
      sVar3 = sVar3 + -1;
    } while (sVar3 != 0);
  }
  if (0x1f < uVar2) {
    puVar6 = (undefined1 *)(param_1 + 0x14);
    puVar4 = (undefined1 *)
             (*(longlong *)
               (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x4b8
             );
    do {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 1;
      sVar5 = sVar5 + -1;
    } while (sVar5 != 0);
  }
  return;
}



===== dhcpv6_process_opt_ia_na @ 140004fd4 =====

int dhcpv6_process_opt_ia_na(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = ((uint)(ushort)(*(short *)(param_1 + 2) << 8) | (uint)*(byte *)(param_1 + 3)) - 0xc;
  if (0 < iVar3) {
    do {
      lVar1 = (longlong)iVar2;
      uVar5 = (uint)(ushort)(*(short *)(lVar1 + 0x12 + param_1) << 8) |
              (uint)*(byte *)(lVar1 + 0x13 + param_1);
      if (((ushort)((ushort)*(byte *)(lVar1 + 0x11 + param_1) |
                   *(short *)(lVar1 + 0x10 + param_1) << 8) == 5) &&
         (((uVar5 < 0x1d || (*(short *)(lVar1 + 0x2c + param_1) != 0xd00)) ||
          (*(short *)(lVar1 + 0x30 + param_1) == 0)))) {
        netif6_add_addr(g_netif,(longlong *)(lVar1 + param_1 + 0x14),0x40);
        ipv6_add_solit_node_address(lVar1 + param_1 + 0x14);
        iVar4 = iVar4 + 1;
      }
      iVar2 = iVar2 + 4 + uVar5;
    } while (iVar2 < iVar3);
  }
  return iVar4;
}



===== dhcpv6_send_request_packet @ 1400050b0 =====

uint dhcpv6_send_request_packet(undefined2 *param_1)

{
  uint uVar1;
  
  uVar1 = dhcpv6_init_packet(param_1,3);
  DAT_14002d9c8 = 3;
  ipv6_send_udp_packet((longlong)param_1,(ushort)uVar1);
  return uVar1 & 0xffff;
}



===== dhcpv6_send_solicit_packet @ 1400050ec =====

uint dhcpv6_send_solicit_packet(undefined2 *param_1)

{
  uint uVar1;
  
  uVar1 = dhcpv6_init_packet(param_1,1);
  DAT_14002d9c8 = 1;
  ipv6_send_udp_packet((longlong)param_1,(ushort)uVar1);
  return uVar1 & 0xffff;
}



===== dhcpv6_wait_for_dhcp_done @ 140005128 =====

undefined8 dhcpv6_wait_for_dhcp_done(int *param_1,int param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  int iVar4;
  
  iVar4 = param_2 * 1000;
  uVar2 = iscsiGetTicks();
  uVar2 = uVar2 & 0xffffffff;
  do {
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    lVar3 = iscsiGetTicks();
    if ((int)uVar2 != (int)lVar3) {
      uVar2 = iscsiGetTicks();
      uVar2 = uVar2 & 0xffffffff;
      iVar4 = iVar4 + -1;
    }
    iVar1 = iscsiL2GetRxPacket(param_1);
  } while ((iVar1 < 1) || (ipv6_rx_packet(param_1,(short)iVar1), DAT_14002d9c4 != 1));
  return 0;
}



===== ihexstr_to_int @ 140005194 =====

void ihexstr_to_int(char *param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  byte *pbVar9;
  char *pcVar10;
  
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    cVar1 = *param_1;
    if ((cVar1 == '0') && ((param_1[1] == 'x' || (param_1[1] == 'X')))) {
      param_1 = param_1 + 2;
      cVar1 = *param_1;
    }
    iVar7 = 0;
    pcVar5 = param_1;
    while (cVar1 != '\0') {
      pcVar5 = pcVar5 + 1;
      iVar7 = iVar7 + 1;
      cVar1 = *pcVar5;
    }
    if (iVar7 != 0) {
      iVar6 = (iVar7 + -1) / 2 + 1;
      lVar2 = (longlong)iVar7;
      if (1 < lVar2) {
        pcVar5 = (char *)(longlong)iVar6;
        lVar8 = (lVar2 - 2U >> 1) + 1;
        pcVar10 = param_1 + lVar2 + -1;
        pbVar9 = (byte *)(pcVar5 + param_2 + -1);
        iVar7 = iVar7 + (int)lVar8 * -2;
        iVar6 = iVar6 - (int)lVar8;
        do {
          uVar4 = CONCAT71((int7)((ulonglong)pcVar5 >> 8),pcVar10[-1]);
          uVar3 = char_to_number((int)uVar4);
          pcVar5 = (char *)CONCAT71((int7)((ulonglong)uVar4 >> 8),*pcVar10);
          uVar4 = char_to_number((int)pcVar5);
          pcVar10 = pcVar10 + -2;
          *pbVar9 = (char)uVar3 << 4 | (byte)uVar4;
          pbVar9 = pbVar9 + -1;
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
      }
      if (iVar7 == 1) {
        uVar3 = char_to_number((int)CONCAT71((int7)((ulonglong)pcVar5 >> 8),*param_1));
        *(char *)((longlong)iVar6 + -1 + param_2) = (char)uVar3;
      }
    }
  }
  return;
}



===== iint_to_hexstr @ 140005290 =====

void iint_to_hexstr(byte *param_1,int param_2,undefined2 *param_3)

{
  byte bVar1;
  char *pcVar2;
  longlong lVar3;
  
  if (((param_1 != (byte *)0x0) && (param_3 != (undefined2 *)0x0)) && (param_2 != 0)) {
    *param_3 = 0x7830;
    pcVar2 = (char *)(param_3 + 1);
    lVar3 = (longlong)param_2;
    if (0 < param_2) {
      do {
        *pcVar2 = "0123456789abcdef"[*param_1 >> 4];
        bVar1 = *param_1;
        param_1 = param_1 + 1;
        pcVar2[1] = "0123456789abcdef"[bVar1 & 0xf];
        pcVar2 = pcVar2 + 2;
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
    }
    *pcVar2 = '\0';
  }
  return;
}



===== ip_chksum @ 1400052e4 =====

void ip_chksum(byte *param_1)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar4 = 0;
  *(ushort *)(param_1 + 10) = 0;
  if ((*param_1 & 0xf) != 0) {
    uVar5 = (ulonglong)((*param_1 & 0xf) * 2);
    pbVar3 = param_1;
    do {
      uVar4 = uVar4 + ((uint)(ushort)(*(short *)pbVar3 << 8) | (uint)pbVar3[1]);
      uVar5 = uVar5 - 1;
      pbVar3 = pbVar3 + 2;
    } while (uVar5 != 0);
  }
  iVar2 = (uVar4 >> 0x10) + (uVar4 & 0xffff);
  uVar1 = (short)((uint)iVar2 >> 0x10) + (short)iVar2;
  *(ushort *)(param_1 + 10) = ~(uVar1 >> 8) & 0xff | ~uVar1 << 8;
  return;
}



===== ipv6_add_solit_node_address @ 140005350 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ipv6_add_solit_node_address(longlong param_1)

{
  undefined1 auStack_38 [32];
  undefined2 local_18;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_15 = *(undefined1 *)(param_1 + 0xd);
  local_14 = *(undefined1 *)(param_1 + 0xe);
  local_13 = *(undefined1 *)(param_1 + 0xf);
  local_18 = 0x3333;
  local_16 = 0xff;
  iscsiL2AddMcAddr((int *)&local_18);
  return;
}



===== ipv6_autoconfig @ 1400053a0 =====

void ipv6_autoconfig(void)

{
  uip_buf = &iscsiContext;
  ipv6_discover_address();
  return;
}



===== ipv6_discover_address @ 1400053b4 =====

undefined8 ipv6_discover_address(void)

{
  undefined8 uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  int *piVar5;
  ulonglong uVar6;
  longlong lVar7;
  int iVar8;
  int iVar9;
  
  puVar2 = uip_buf;
  piVar5 = (int *)iscsiGetDhcpBuffer(0x5ea);
  *(undefined8 *)(puVar2 + 0x13) = 0;
  *(undefined8 *)(puVar2 + 0x17) = 0;
  puVar2[0x13] = 0x2ff;
  *(undefined1 *)((longlong)puVar2 + 0x35) = 2;
  iVar9 = 0;
  puVar2[10] = 0xff3a;
  *puVar2 = 0x3333;
  *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(puVar2 + 0x19);
  *(undefined1 *)((longlong)puVar2 + 3) = *(undefined1 *)((longlong)puVar2 + 0x33);
  *(undefined1 *)(puVar2 + 2) = *(undefined1 *)(puVar2 + 0x1a);
  *(undefined1 *)((longlong)puVar2 + 5) = *(undefined1 *)((longlong)puVar2 + 0x35);
  puVar3 = uip_buf;
  *(undefined8 *)(uip_buf + 0x1b) = 0x85;
  puVar3[0x1f] = 0x101;
  lVar7 = g_netif;
  *(undefined4 *)(puVar3 + 0x20) = *(undefined4 *)(g_netif + 0x31);
  puVar3[0x22] = *(undefined2 *)(lVar7 + 0x35);
  puVar2[9] = 0x1000;
  uVar1 = *(undefined8 *)(g_netif + 0xe0);
  *(undefined8 *)(puVar2 + 0xb) = *(undefined8 *)(g_netif + 0xd8);
  *(undefined8 *)(puVar2 + 0xf) = uVar1;
  do {
    puVar3[0x1c] = 0;
    ipv6_send((longlong)puVar2,0x46);
    iVar8 = 4000;
    uVar6 = iscsiGetTicks();
    uVar6 = uVar6 & 0xffffffff;
    do {
      lVar7 = iscsiGetTicks();
      if ((int)uVar6 != (int)lVar7) {
        uVar6 = iscsiGetTicks();
        uVar6 = uVar6 & 0xffffffff;
        iVar8 = iVar8 + -1;
      }
      iVar4 = iscsiL2GetRxPacket(piVar5);
      if ((0 < iVar4) && (ipv6_rx_packet(piVar5,(short)iVar4), (*(byte *)(g_netif + 0x3e) & 4) != 0)
         ) {
        return 0;
      }
    } while (iVar8 != 0);
    iVar9 = iVar9 + 1;
    if (2 < iVar9) {
      return 0xffffffff;
    }
  } while( true );
}



===== ipv6_do_stateful_dhcpv6 @ 1400054f0 =====

ushort ipv6_do_stateful_dhcpv6(uint param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  uVar1 = 3;
  if ((*(ushort *)(g_netif + 0x3e) & 4) != 0) {
    uVar1 = *(ushort *)(g_netif + 0x3e);
  }
  if (((param_1 >> 0x11 & 1) != 0) && ((uVar1 & 1) != 0)) {
    uVar2 = 1;
  }
  if (((param_1 >> 0x12 & 1) != 0) && ((uVar1 & 2) != 0)) {
    uVar2 = uVar2 | 2;
  }
  return uVar2;
}



===== ipv6_get_default_router_ip_addrs @ 140005530 =====

undefined8 ipv6_get_default_router_ip_addrs(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(g_netif + 0xd0);
  *param_1 = *(undefined8 *)(g_netif + 200);
  param_1[1] = uVar1;
  return 1;
}



===== ipv6_get_source_ip_addrs @ 140005548 =====

int ipv6_get_source_ip_addrs(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = *(undefined8 **)(g_netif + 0xc0);
  while( true ) {
    if (puVar2 == (undefined8 *)0x0) {
      return iVar3;
    }
    uVar1 = puVar2[2];
    iVar3 = iVar3 + 1;
    *param_1 = puVar2[1];
    param_1[1] = uVar1;
    *(char *)(param_1 + 2) = *(char *)(puVar2 + 3) << 3;
    if (3 < iVar3) break;
    puVar2 = (undefined8 *)*puVar2;
    param_1 = (undefined8 *)((longlong)param_1 + 0x14);
  }
  return iVar3;
}



===== ipv6_icmp_handle_echo_request @ 140005588 =====

void ipv6_icmp_handle_echo_request(undefined4 *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = *(undefined8 *)((longlong)param_1 + 0x26);
  uVar2 = *(undefined8 *)((longlong)param_1 + 0x2e);
  *param_1 = *(undefined4 *)((longlong)param_1 + 6);
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)((longlong)param_1 + 10);
  *(undefined8 *)((longlong)param_1 + 0x26) = *(undefined8 *)((longlong)param_1 + 0x16);
  *(undefined8 *)((longlong)param_1 + 0x2e) = *(undefined8 *)((longlong)param_1 + 0x1e);
  *(undefined8 *)((longlong)param_1 + 0x16) = uVar1;
  *(undefined8 *)((longlong)param_1 + 0x1e) = uVar2;
  *(undefined1 *)((longlong)param_1 + 0x15) = *(undefined1 *)(g_netif + 0x11c);
  *(undefined4 *)((longlong)param_1 + 0x36) = 0x81;
  ipv6_send((longlong)param_1,
            (*(short *)((longlong)param_1 + 0x12) << 8 | (ushort)*(byte *)((longlong)param_1 + 0x13)
            ) + 0x36);
  return;
}



===== ipv6_icmp_handle_nd_adv @ 1400055e0 =====

void ipv6_icmp_handle_nd_adv(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = ipv6_is_it_our_address((longlong *)(param_1 + 0x26));
  if ((int)uVar1 == 1) {
    ipv6_update_arp_table((longlong *)(param_1 + 0x3e),(int *)(param_1 + 6));
  }
  return;
}



===== ipv6_icmp_handle_nd_sol @ 14000560c =====

void ipv6_icmp_handle_nd_sol(int *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if (((*(int *)(g_netif + 0x31) == *param_1) && (*(short *)(g_netif + 0x35) == (short)param_1[1]))
     || (uVar3 = iscsiL2IsOurMcAddr(param_1), (int)uVar3 != 0)) {
    *param_1 = *(int *)((longlong)param_1 + 6);
    *(undefined2 *)(param_1 + 1) = *(undefined2 *)((longlong)param_1 + 10);
    *(undefined8 *)((longlong)param_1 + 0x26) = *(undefined8 *)((longlong)param_1 + 0x16);
    *(undefined8 *)((longlong)param_1 + 0x2e) = *(undefined8 *)((longlong)param_1 + 0x1e);
    uVar3 = *(undefined8 *)(g_netif + 0xd8);
    uVar1 = *(undefined8 *)(g_netif + 0xe0);
    *(undefined1 *)((longlong)param_1 + 0x15) = 0xff;
    *(undefined8 *)((longlong)param_1 + 0x16) = uVar3;
    *(undefined8 *)((longlong)param_1 + 0x1e) = uVar1;
    *(undefined8 *)((longlong)param_1 + 0x36) = 0x88;
    *(undefined1 *)((longlong)param_1 + 0x3a) = 0x60;
    *(undefined2 *)((longlong)param_1 + 0x4e) = 0x102;
    lVar2 = g_netif;
    param_1[0x14] = *(int *)(g_netif + 0x31);
    *(undefined2 *)(param_1 + 0x15) = *(undefined2 *)(lVar2 + 0x35);
    *(undefined2 *)((longlong)param_1 + 0x12) = 0x2000;
    ipv6_send((longlong)param_1,0x56);
    return;
  }
  return;
}



===== ipv6_icmp_handle_router_adv @ 1400056b4 =====

void ipv6_icmp_handle_router_adv(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ushort uVar4;
  ushort uVar5;
  
  if ((*(byte *)(g_netif + 0x3e) & 4) == 0) {
    uVar4 = 0;
    uVar5 = *(short *)(param_1 + 0x12) << 8 | (ushort)*(byte *)(param_1 + 0x13);
    if (uVar5 != 0x10) {
      do {
        uVar3 = (ulonglong)uVar4;
        if (*(char *)(uVar3 + 0x46 + param_1) == '\x03') {
          ipv6_icmp_process_prefix(param_1 + 0x46 + uVar3);
          *(ushort *)(g_netif + 0x3e) = *(ushort *)(g_netif + 0x3e) | 4;
        }
        uVar4 = uVar4 + (ushort)*(byte *)(uVar3 + 0x47 + param_1) * 8;
      } while (uVar4 < (ushort)(uVar5 - 0x10));
    }
    if ((*(byte *)(g_netif + 0x3e) & 4) != 0) {
      if (*(char *)(param_1 + 0x3a) != '\0') {
        *(char *)(g_netif + 0x11c) = *(char *)(param_1 + 0x3a);
      }
      if ((*(char *)(param_1 + 0x3b) < '\0') &&
         (*(ushort *)(g_netif + 0x3e) = *(ushort *)(g_netif + 0x3e) | 1,
         *(char *)(param_1 + 0x3b) < '\0')) {
        *(ushort *)(g_netif + 0x3e) = *(ushort *)(g_netif + 0x3e) | 2;
      }
      lVar2 = g_netif;
      if (*(short *)(param_1 + 0x3c) != 0) {
        uVar1 = *(undefined8 *)(param_1 + 0x1e);
        *(undefined8 *)(g_netif + 200) = *(undefined8 *)(param_1 + 0x16);
        *(undefined8 *)(lVar2 + 0xd0) = uVar1;
      }
    }
  }
  return;
}



===== ipv6_icmp_process_prefix @ 1400057ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ipv6_icmp_process_prefix(longlong param_1)

{
  undefined1 auStack_48 [32];
  longlong local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  if ((*(char *)(param_1 + 3) < '\0') && (*(char *)(param_1 + 2) == '@')) {
    local_28 = *(longlong *)(param_1 + 0x10);
    local_20 = *(undefined8 *)(g_netif + 0xe0);
    netif6_add_addr(g_netif,&local_28,0x40);
  }
  return;
}



===== ipv6_icmp_rx @ 140005808 =====

void ipv6_icmp_rx(int *param_1)

{
  char cVar1;
  
  cVar1 = *(char *)((longlong)param_1 + 0x36);
  if (cVar1 == -0x80) {
    ipv6_icmp_handle_echo_request(param_1);
  }
  else {
    if (cVar1 == -0x7a) {
      ipv6_icmp_handle_router_adv((longlong)param_1);
      return;
    }
    if (cVar1 == -0x79) {
      ipv6_icmp_handle_nd_sol(param_1);
      return;
    }
    if (cVar1 == -0x78) {
      ipv6_icmp_handle_nd_adv((longlong)param_1);
      return;
    }
  }
  return;
}



===== ipv6_insert_protocol_chksum @ 14000584c =====

void ipv6_insert_protocol_chksum(longlong param_1)

{
  char cVar1;
  ushort uVar2;
  ulonglong uVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  uint uVar7;
  
  iVar4 = 0;
  uVar7 = 0;
  psVar6 = (short *)(param_1 + 0x16);
  do {
    psVar5 = psVar6;
    uVar7 = uVar7 + 1;
    iVar4 = iVar4 + ((uint)(ushort)(*psVar5 << 8) | (uint)*(byte *)((longlong)psVar5 + 1));
    psVar6 = psVar5 + 1;
  } while (uVar7 < 0x10);
  uVar2 = *(short *)(param_1 + 0x12) << 8 | (ushort)*(byte *)(param_1 + 0x13);
  uVar7 = (uint)uVar2 + iVar4 + (uint)*(byte *)(param_1 + 0x14);
  if ((*(byte *)(param_1 + 0x13) & 1) != 0) {
    uVar3 = (ulonglong)uVar2;
    uVar2 = uVar2 + 1;
    *(undefined1 *)(uVar3 + 2 + (longlong)psVar5) = 0;
  }
  if (uVar2 >> 1 != 0) {
    uVar3 = (ulonglong)(uint)(uVar2 >> 1);
    do {
      uVar7 = uVar7 + ((uint)(ushort)(*psVar6 << 8) | (uint)*(byte *)((longlong)psVar6 + 1));
      uVar3 = uVar3 - 1;
      psVar6 = psVar6 + 1;
    } while (uVar3 != 0);
  }
  iVar4 = (uVar7 >> 0x10) + (uVar7 & 0xffff);
  cVar1 = *(char *)(param_1 + 0x14);
  uVar2 = ~((short)((uint)iVar4 >> 0x10) + (short)iVar4);
  uVar2 = uVar2 << 8 | uVar2 >> 8;
  if (cVar1 == '\x06') {
    psVar5[9] = uVar2;
  }
  else if (cVar1 == '\x11') {
    psVar5[4] = uVar2;
  }
  else if (cVar1 == ':') {
    psVar5[2] = uVar2;
  }
  return;
}



===== ipv6_is_it_our_address @ 14000592c =====

undefined8 ipv6_is_it_our_address(longlong *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(g_netif + 0xc0);
  while( true ) {
    if (puVar1 == (undefined8 *)0x0) {
      return 0;
    }
    if ((puVar1[1] == *param_1) && (puVar1[2] == param_1[1])) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return 1;
}



===== ipv6_rx_packet @ 140005960 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ipv6_rx_packet(int *param_1,undefined2 param_2)

{
  _uip_len = param_2;
  if ((*(byte *)((longlong)param_1 + 0xe) & 0xf0) == 0x60) {
    if (*(char *)((longlong)param_1 + 0x26) != -1) {
      ipv6_update_arp_table((longlong *)((longlong)param_1 + 0x16),(int *)((longlong)param_1 + 6));
    }
    if ((char)param_1[5] == '\x11') {
      ipv6_udp_rx((undefined2 *)param_1);
    }
    else if ((char)param_1[5] == ':') {
      ipv6_icmp_rx(param_1);
      return;
    }
  }
  return;
}



===== ipv6_send @ 1400059b4 =====

void ipv6_send(longlong param_1,undefined2 param_2)

{
  ipv6_setup_hdrs(param_1);
  iscsiL2Send(param_1,param_2);
  return;
}



===== ipv6_send_udp_packet @ 1400059e0 =====

void ipv6_send_udp_packet(longlong param_1,ushort param_2)

{
  *(undefined2 *)(param_1 + 0x14) = 0x111;
  *(ushort *)(param_1 + 0x12) =
       (ushort)((ulonglong)param_2 - 0x36 >> 8) & 0xff | (short)((ulonglong)param_2 - 0x36) * 0x100;
  *(undefined2 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x16) = 0;
  ipv6_send(param_1,param_2);
  return;
}



===== ipv6_setup_hdrs @ 140005a1c =====

void ipv6_setup_hdrs(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  *(undefined2 *)(param_1 + 0xc) = 0xdd86;
  lVar2 = g_netif;
  *(undefined4 *)(param_1 + 6) = *(undefined4 *)(g_netif + 0x31);
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(lVar2 + 0x35);
  *(undefined1 *)(param_1 + 0xe) = 0x60;
  if (*(char *)(param_1 + 0x15) == '\0') {
    *(undefined1 *)(param_1 + 0x15) = *(undefined1 *)(g_netif + 0x11c);
  }
  if (*(int *)(param_1 + 0x16) == 0) {
    if ((undefined8 *)(g_netif + 0xd8) != (undefined8 *)0x0) {
      uVar1 = *(undefined8 *)(g_netif + 0xe0);
      *(undefined8 *)(param_1 + 0x16) = *(undefined8 *)(g_netif + 0xd8);
      *(undefined8 *)(param_1 + 0x1e) = uVar1;
    }
  }
  ipv6_insert_protocol_chksum(param_1);
  return;
}



===== ipv6_udp_handle_dhcp @ 140005a80 =====

void ipv6_udp_handle_dhcp(undefined2 *param_1)

{
  uint uVar1;
  
  if ((DAT_14002d9c4 != 1) && (*(uint *)(param_1 + 0x1f) >> 8 == DAT_14002d934)) {
    uVar1 = *(uint *)(param_1 + 0x1f) & 0xff;
    if (uVar1 == 2) {
      dhcpv6_handle_advertise
                (param_1,(param_1[0x1d] << 8 | (ushort)*(byte *)((longlong)param_1 + 0x3b)) - 8);
    }
    else if ((uVar1 == 7) && (DAT_14002d9c8 == 3)) {
      DAT_14002d9c4 = 1;
      return;
    }
  }
  return;
}



===== ipv6_udp_rx @ 140005ae4 =====

void ipv6_udp_rx(undefined2 *param_1)

{
  if (((*(byte *)(g_netif + 0x3e) & 8) == 0) && (param_1[0x1c] == 0x2202)) {
    ipv6_udp_handle_dhcp(param_1);
  }
  return;
}



===== ipv6_update_arp_table @ 140005b0c =====

void ipv6_update_arp_table(longlong *param_1,int *param_2)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  int iVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)&ipv6_arp_table;
  do {
    if ((((int)*plVar5 != 0) && (*plVar5 == *param_1)) && (plVar5[1] == param_1[1])) {
      *(int *)(plVar5 + 2) = *param_2;
      *(short *)((longlong)plVar5 + 0x14) = (short)param_2[1];
      *(undefined1 *)((longlong)plVar5 + 0x16) = DAT_14002d9c2;
      return;
    }
    plVar5 = plVar5 + 3;
  } while ((longlong)plVar5 < 0x140074620);
  iVar4 = 0;
  piVar2 = &ipv6_arp_table;
  do {
    if (*piVar2 == 0) break;
    iVar4 = iVar4 + 1;
    piVar2 = piVar2 + 6;
  } while ((longlong)piVar2 < 0x140074620);
  if (iVar4 != 8) {
    lVar1 = param_1[1];
    lVar3 = (longlong)iVar4;
    *(longlong *)(&ipv6_arp_table + lVar3 * 6) = *param_1;
    (&DAT_140074568)[lVar3 * 3] = lVar1;
    *(int *)(&DAT_140074570 + lVar3 * 0x18) = *param_2;
    *(short *)(&DAT_140074574 + lVar3 * 0x18) = (short)param_2[1];
    (&DAT_140074576)[lVar3 * 0x18] = DAT_14002d9c2;
  }
  return;
}



===== iscsiAddText @ 140005ba4 =====

bool iscsiAddText(undefined8 param_1,longlong param_2,longlong param_3,int param_4,void *param_5,
                 void *param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  void *_Dst;
  undefined1 *puVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar8;
  longlong lVar7;
  bool bVar9;
  
  lVar6 = -1;
  lVar7 = -1;
  do {
    lVar8 = lVar7;
    lVar7 = lVar8 + 1;
  } while (*(char *)((longlong)param_5 + lVar7) != '\0');
  do {
    lVar6 = lVar6 + 1;
  } while (*(char *)((longlong)param_6 + lVar6) != '\0');
  iVar5 = (int)lVar6;
  iVar1 = (int)lVar8 + 3 + iVar5;
  uVar2 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6)),
                         *(undefined1 *)(param_2 + 7));
  iVar3 = uVar2 + iVar1;
  _Dst = (void *)((ulonglong)uVar2 + param_3);
  bVar9 = (ulonglong)((longlong)iVar1 + (longlong)_Dst) < (ulonglong)(param_4 + param_3);
  if (bVar9) {
    memmove(_Dst,param_5,(longlong)(int)lVar7);
    puVar4 = (undefined1 *)((longlong)_Dst + (longlong)(int)lVar7);
    *puVar4 = 0x3d;
    memmove(puVar4 + 1,param_6,(longlong)iVar5);
    puVar4[(longlong)iVar5 + 1] = 0;
    *(char *)(param_2 + 5) = (char)((uint)iVar3 >> 0x10);
    *(char *)(param_2 + 6) = (char)((uint)iVar3 >> 8);
    *(char *)(param_2 + 7) = (char)iVar3;
  }
  return bVar9;
}



===== iscsiAddTimer @ 140005c84 =====

undefined2 * iscsiAddTimer(undefined2 param_1,undefined8 param_2)

{
  short *psVar1;
  longlong lVar2;
  int iVar3;
  
  iVar3 = 0;
  psVar1 = &DAT_14002d940;
  do {
    if (*psVar1 == 0) {
      lVar2 = (longlong)iVar3;
      (&DAT_14002d948)[lVar2 * 2] = param_2;
      (&DAT_14002d942)[lVar2 * 8] = param_1;
      (&DAT_14002d944)[lVar2 * 8] = 0;
      (&DAT_14002d940)[lVar2 * 8] = 1;
      return &DAT_14002d940 + lVar2 * 8;
    }
    iVar3 = iVar3 + 1;
    psVar1 = psVar1 + 8;
  } while ((longlong)psVar1 < 0x14002d9c0);
  return (undefined2 *)0x0;
}



===== iscsiCheckPendingNopIn @ 140005ce0 =====

void iscsiCheckPendingNopIn(void)

{
  if (((*(char *)(iscsiGlobalsPtr + 0x70) == '\x03') && (*(int *)(iscsiGlobalsPtr + 0x188) != 0)) &&
     (*(int *)(iscsiGlobalsPtr + 0x78c) == 0)) {
    iscsiSessionProcessDelaySendNopOut(300);
    *(undefined4 *)(iscsiGlobalsPtr + 0x188) = 0;
  }
  return;
}



===== iscsiConnect @ 140005d20 =====

void iscsiConnect(longlong param_1)

{
  longlong lVar1;
  
  *(undefined2 *)(param_1 + 0x24) = 0xffff;
  lVar1 = stack_setup_connection
                    (param_1 + 0x98,*(undefined2 *)(param_1 + 0x86),iscsiSessionConnStackCallback);
  *(longlong *)(param_1 + 8) = lVar1;
  if (lVar1 != 0) {
    *(undefined2 *)(param_1 + 2) = 0x202;
  }
  return;
}



===== iscsiDelTimer @ 140005d64 =====

undefined8 iscsiDelTimer(undefined2 *param_1)

{
  if (param_1 == (undefined2 *)0x0) {
    return 0xffffffff;
  }
  *param_1 = 0;
  return 0;
}



===== iscsiDhcpDoDiscovery @ 140005d74 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 iscsiDhcpDoDiscovery(char param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined4 uVar10;
  uint uVar11;
  longlong lVar12;
  uint uVar13;
  
  lVar12 = 0;
  uVar10 = 0xffffffff;
  uVar11 = 0;
  dhcp_transaction_id =
       *(undefined4 *)
        (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
        + 0x14);
  ip_id = *(undefined2 *)
           (*(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x16);
  rx_buffers = (void *)iscsiGetDhcpBuffer(0x1baa);
  option43 = (longlong)rx_buffers + 0x17a8;
  lVar8 = 0;
  while( true ) {
    iVar2 = (int)lVar12;
    uVar4 = iscsiBootCancel();
    if ((int)uVar4 != 0) {
      uVar10 = 0xfffffffe;
      goto LAB_140005fd7;
    }
    iVar3 = (&dhcp_retry_timeout)[lVar8];
    iscsiDhcpSendDiscovery();
    iVar2 = iscsiDhcpWaitForResponses(iVar3);
    lVar12 = (longlong)iVar2;
    if (0 < iVar2) break;
    _seconds = _seconds + iVar3;
    lVar8 = lVar8 + 1;
    if ((longlong)((ulonglong)(-(uint)(param_1 != '\0') & 6) + 6) <= lVar8) goto LAB_140005fd7;
  }
  if (((*(uint *)(*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4
                 ) & 0x40000) != 0) && (uVar13 = 0, 0 < iVar2)) {
    lVar9 = 0;
    lVar8 = lVar12;
    do {
      pvVar1 = rx_buffers;
      lVar5 = iscsiDhcpFindOption((longlong)rx_buffers + lVar9 + 0x2a,
                                  ((uint)(ushort)(*(short *)(lVar9 + 0x26 + (longlong)rx_buffers) <<
                                                 8) |
                                  (uint)*(byte *)(lVar9 + 0x27 + (longlong)rx_buffers)) - 8,'<');
      lVar7 = -1;
      do {
        lVar7 = lVar7 + 1;
      } while (*(char *)(*(longlong *)
                          (iscsiGlobalsPtr + 0xda0 +
                          (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x58 + lVar7) != '\0'
              );
      if ((((lVar5 != 0) && ((int)lVar7 <= (int)(uint)*(byte *)(lVar5 + 1))) &&
          (iVar3 = strncmp((char *)(lVar5 + 2),
                           (char *)(*(longlong *)
                                     (iscsiGlobalsPtr + 0xda0 +
                                     (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x58),
                           (longlong)(int)lVar7), iVar3 == 0)) &&
         (uVar6 = iscsiDhcpFindRetrieveVendorOption
                            ((longlong)pvVar1 + lVar9 + 0x2a,
                             ((uint)(ushort)(*(short *)(lVar9 + 0x26 + (longlong)pvVar1) << 8) |
                             (uint)*(byte *)(lVar9 + 0x27 + (longlong)pvVar1)) - 8), 0 < (int)uVar6)
         ) {
        uVar11 = uVar11 & 0xffff | 1 << (uVar13 & 0x1f);
      }
      uVar13 = uVar13 + 1;
      lVar9 = lVar9 + 0x5ea;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
  }
  lVar8 = 0;
  uVar13 = 0;
  if (0 < iVar2) {
    lVar9 = lVar8;
    do {
      uVar4 = iscsiDhcpRetrieveStandardInfo
                        ((longlong)rx_buffers + lVar9 + 0x2a,
                         ((uint)(ushort)(*(short *)(lVar9 + 0x26 + (longlong)rx_buffers) << 8) |
                         (uint)*(byte *)(lVar9 + 0x27 + (longlong)rx_buffers)) - 8);
      if (0 < (int)uVar4) {
        uVar11 = uVar11 & 0xffff | 1 << (uVar13 & 0x1f);
      }
      uVar13 = uVar13 + 1;
      lVar9 = lVar9 + 0x5ea;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
  }
  uVar13 = 0;
  do {
    if (((uVar11 & 0xffff) >> (uVar13 & 0x1f) & 1) != 0) {
      iscsiDhcpSendRequest((longlong)rx_buffers + lVar8,2);
    }
    uVar13 = uVar13 + 1;
    lVar8 = lVar8 + 0x5ea;
  } while ((int)uVar13 < iVar2);
  uVar10 = 0;
LAB_140005fd7:
  memset(rx_buffers,0,(longlong)iVar2 * 0x5ea);
  return uVar10;
}



===== iscsiDhcpFindOption @ 140006010 =====

longlong iscsiDhcpFindOption(longlong param_1,int param_2,char param_3)

{
  uint uVar1;
  longlong lVar2;
  
  if (((byte)(param_3 - 1U) < 0xfe) &&
     (uVar1 = swap_dword(0x63825363), *(uint *)(param_1 + 0xec) == uVar1)) {
    lVar2 = iscsiDhcpFindRetrieveOption(param_1 + 0xf0,param_2 + -0xf0,param_3);
    return lVar2;
  }
  return 0;
}



===== iscsiDhcpFindRetrieveOption @ 14000606c =====

longlong iscsiDhcpFindRetrieveOption(longlong param_1,int param_2,char param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_2) {
    do {
      cVar1 = *(char *)(iVar2 + param_1);
      if (cVar1 == '\0') {
        iVar2 = iVar2 + 1;
      }
      else {
        if (cVar1 == -1) {
          return 0;
        }
        if (cVar1 == param_3) break;
        iVar2 = iVar2 + 2 + (uint)*(byte *)((longlong)iVar2 + 1 + param_1);
      }
    } while (iVar2 < param_2);
    if (iVar2 < param_2) {
      return iVar2 + param_1;
    }
  }
  return 0;
}



===== iscsiDhcpFindRetrieveVendorOption @ 1400060b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong iscsiDhcpFindRetrieveVendorOption(longlong param_1,int param_2)

{
  char cVar1;
  code *pcVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 auStack_d8 [32];
  char local_b8 [144];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar3 = param_1 + 0xf0;
  uVar6 = 0;
  iVar4 = 0;
  *option43 = 0;
  if (0 < param_2 + -0xf0) {
    do {
      lVar5 = (longlong)iVar4;
      cVar1 = *(char *)(lVar5 + lVar3);
      if (cVar1 == '\0') {
        iVar4 = iVar4 + 1;
      }
      else {
        if (cVar1 == -1) break;
        if (cVar1 == '+') {
          memmove((void *)((longlong)option43 + (ulonglong)*option43 + 2),
                  (void *)((iVar4 + 2) + lVar3),(ulonglong)*(byte *)(lVar5 + 1 + lVar3));
          *option43 = *option43 + (ushort)*(byte *)(lVar5 + 1 + lVar3);
        }
        iVar4 = iVar4 + 2 + (uint)*(byte *)(lVar5 + 1 + lVar3);
      }
    } while (iVar4 < param_2 + -0xf0);
  }
  if (*option43 == 0) {
    uVar7 = 0;
  }
  else {
    lVar3 = iscsiDhcpFindRetrieveOption((longlong)(option43 + 1),(uint)*option43,-0x37);
    if (lVar3 != 0) {
      uVar7 = (ulonglong)*(byte *)(lVar3 + 1);
      if (0x80 < *(byte *)(lVar3 + 1)) {
        uVar7 = 0x80;
      }
      memmove(local_b8,(void *)(lVar3 + 2),uVar7);
      if (0x80 < uVar7) goto LAB_14000630d;
      local_b8[uVar7] = '\0';
      itolowerstr(local_b8);
      iscsiBootCancel();
      uVar6 = 1;
    }
    lVar3 = iscsiDhcpFindRetrieveOption((longlong)(option43 + 1),(uint)*option43,-0x36);
    if (lVar3 != 0) {
      uVar7 = (ulonglong)*(byte *)(lVar3 + 1);
      if (0x80 < *(byte *)(lVar3 + 1)) {
        uVar7 = 0x80;
      }
      memmove(local_b8,(void *)(lVar3 + 2),uVar7);
      if (0x80 < uVar7) {
LAB_14000630d:
        __report_rangecheckfailure();
        pcVar2 = (code *)swi(3);
        uVar7 = (*pcVar2)();
        return uVar7;
      }
      local_b8[uVar7] = '\0';
      itolowerstr(local_b8);
      iscsiBootCancel();
      uVar6 = uVar6 + 1;
    }
    lVar3 = iscsiDhcpFindRetrieveOption((longlong)(option43 + 1),(uint)*option43,-0x35);
    if (lVar3 != 0) {
      uVar7 = (ulonglong)*(byte *)(lVar3 + 1);
      if (0x80 < *(byte *)(lVar3 + 1)) {
        uVar7 = 0x80;
      }
      memmove((void *)(*(longlong *)
                        (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8
                        ) + 0x200),(void *)(lVar3 + 2),uVar7);
      *(undefined1 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
        0x200 + uVar7) = 0;
      itolowerstr((char *)(*(longlong *)
                            (iscsiGlobalsPtr + 0xda0 +
                            (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x200));
      uVar6 = uVar6 + 1;
    }
    uVar7 = (ulonglong)uVar6;
  }
  return uVar7;
}



===== iscsiDhcpRetrieveInfo @ 140006314 =====

/* WARNING: Removing unreachable block (ram,0x000140006409) */
/* WARNING: Removing unreachable block (ram,0x000140006447) */

undefined8 iscsiDhcpRetrieveInfo(int *param_1,longlong param_2,int param_3)

{
  byte bVar1;
  longlong lVar2;
  undefined8 uVar3;
  int *piVar4;
  uint uVar5;
  longlong lVar6;
  
  memset(param_1,0,0x218);
  *param_1 = *(int *)(param_2 + 0x10);
  lVar2 = iscsiDhcpFindOption(param_2,param_3,'6');
  if ((lVar2 != 0) && (*(char *)(lVar2 + 1) == '\x04')) {
    param_1[1] = *(int *)(lVar2 + 2);
  }
  lVar2 = iscsiDhcpFindOption(param_2,param_3,'\x06');
  if (lVar2 != 0) {
    uVar5 = (uint)*(byte *)(lVar2 + 1);
    piVar4 = param_1 + 4;
    lVar6 = 2;
    do {
      if (3 < (int)uVar5) {
        *piVar4 = *(int *)((lVar2 - (longlong)param_1) + -0xe + (longlong)piVar4);
      }
      uVar5 = uVar5 - 4;
      piVar4 = piVar4 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  lVar2 = iscsiDhcpFindOption(param_2,param_3,'\x03');
  if ((lVar2 != 0) && (3 < *(byte *)(lVar2 + 1))) {
    param_1[3] = *(int *)(lVar2 + 2);
  }
  lVar2 = iscsiDhcpFindOption(param_2,param_3,'\x01');
  if ((lVar2 != 0) && (*(char *)(lVar2 + 1) == '\x04')) {
    param_1[2] = *(int *)(lVar2 + 2);
  }
  *(undefined1 *)(param_1 + 6) = 0;
  lVar2 = iscsiDhcpFindOption(param_2,param_3,'\x11');
  if (lVar2 != 0) {
    bVar1 = *(byte *)(lVar2 + 1);
    memmove(param_1 + 6,(void *)(lVar2 + 2),(ulonglong)(uint)bVar1);
    *(undefined1 *)((ulonglong)(uint)bVar1 + 0x18 + (longlong)param_1) = 0;
  }
  *(undefined1 *)(param_1 + 0x46) = 0;
  lVar2 = iscsiDhcpFindOption(param_2,param_3,'\f');
  if (lVar2 != 0) {
    bVar1 = *(byte *)(lVar2 + 1);
    memmove(param_1 + 0x46,(void *)(lVar2 + 2),(ulonglong)(uint)bVar1);
    *(undefined1 *)((ulonglong)(uint)bVar1 + 0x118 + (longlong)param_1) = 0;
  }
  if ((*param_1 == 0) || (param_1[2] == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



===== iscsiDhcpRetrieveStandardInfo @ 140006490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 iscsiDhcpRetrieveStandardInfo(longlong param_1,int param_2)

{
  char cVar1;
  undefined8 uVar2;
  longlong lVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 auStack_258 [32];
  int local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  char local_220;
  char local_120 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_258;
  uVar2 = iscsiDhcpRetrieveInfo(&local_238,param_1,param_2);
  if ((int)uVar2 != 0) {
    lVar3 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    if ((*(uint *)(lVar3 + 4) & 0x20000) != 0) {
      *(int *)(lVar3 + 0x458) = local_238;
      *(int *)(*(longlong *)
                (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
              0x488) = local_238;
      *(undefined4 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x468) = local_230;
      *(undefined4 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x478) = local_22c;
      *(undefined4 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x4a8) = local_228;
      *(undefined4 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x4b8) = local_224;
      *(undefined4 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x498) = local_234;
    }
    lVar3 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    if ((((*(uint *)(lVar3 + 4) & 0x40000) != 0) && (*(char *)(lVar3 + 0x281) == '\0')) &&
       (local_220 != '\0')) {
      iscsiBootCancel();
    }
    if (local_120[0] == '\0') {
      lVar3 = 0;
      do {
        cVar1 = "iscsiboot"[lVar3];
        local_120[lVar3] = cVar1;
        lVar3 = lVar3 + 1;
      } while (cVar1 != '\0');
    }
    else {
      itolowerstr(local_120);
    }
    pcVar5 = local_120;
    pcVar4 = (char *)(*(longlong *)
                       (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                     + 0x438);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar2 = 1;
  }
  return uVar2;
}



===== iscsiDhcpSendDiscovery @ 140006668 =====

void iscsiDhcpSendDiscovery(void)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = iscsiGlobalsPtr;
  iVar2 = iscsiInitDhcpPacket((undefined1 *)(iscsiGlobalsPtr + 0x1ca),1,(undefined4 *)0x0,
                              (undefined4 *)0x0);
  iscsiDhcpSendPacket(lVar1 + 0x1a0,(ushort)iVar2);
  return;
}



===== iscsiDhcpSendPacket @ 1400066a0 =====

void iscsiDhcpSendPacket(longlong param_1,ushort param_2)

{
  byte *pbVar1;
  ushort uVar2;
  ushort uVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  puVar4 = (undefined1 *)(param_1 + 6);
  uVar5 = 0;
  do {
    puVar4[-6] = 0xff;
    uVar5 = uVar5 + 1;
    *puVar4 = puVar4[(*(longlong *)
                       (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                     - param_1) + 0xc];
    puVar4 = puVar4 + 1;
  } while (uVar5 < 6);
  pbVar1 = (byte *)(param_1 + 0xe);
  *(undefined2 *)(param_1 + 0xc) = 8;
  pbVar1[0] = 0x45;
  pbVar1[1] = 0;
  *(ushort *)(param_1 + 0x10) =
       (ushort)((ulonglong)param_2 + 0x1c >> 8) & 0xff | param_2 * 0x100 + 0x1c00;
  *(ushort *)(param_1 + 0x12) = ip_id << 8 | ip_id >> 8;
  ip_id = ip_id + 1;
  *(undefined4 *)(param_1 + 0x14) = 0x11200000;
  ip_chksum(pbVar1);
  uVar5 = 0;
  puVar4 = (undefined1 *)(param_1 + 0x1e);
  do {
    puVar4[-4] = 0;
    uVar5 = uVar5 + 1;
    *puVar4 = 0xff;
    puVar4 = puVar4 + 1;
  } while (uVar5 < 4);
  *(undefined4 *)(param_1 + 0x22) = 0x43004400;
  *(undefined2 *)(param_1 + 0x28) = 0;
  *(ushort *)(param_1 + 0x26) =
       (ushort)((ulonglong)param_2 + 8 >> 8) & 0xff | param_2 * 0x100 + 0x800;
  uVar2 = udp_cksum(pbVar1);
  uVar3 = udp_cksum(pbVar1);
  *(ushort *)(param_1 + 0x28) = uVar3 << 8 | uVar2 >> 8;
  iscsiL2Send(param_1,param_2 + 0x2a);
  return;
}



===== iscsiDhcpSendRequest @ 1400067fc =====

void iscsiDhcpSendRequest(longlong param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 local_res8 [2];
  undefined4 local_res10 [2];
  
  lVar1 = iscsiGlobalsPtr;
  local_res10[0] = *(undefined4 *)(param_1 + 0x3a);
  lVar4 = iscsiDhcpFindOption(param_1 + 0x2a,
                              ((uint)(ushort)(*(short *)(param_1 + 0x26) << 8) |
                              (uint)*(byte *)(param_1 + 0x27)) - 8,'6');
  local_res8[0] = *(undefined4 *)(lVar4 + 2);
  lVar4 = iscsiGetTicks();
  lVar5 = iscsiGetTicks();
  uVar2 = (uint)lVar5;
  while( true ) {
    if ((uint)(param_2 * 1000 + (int)lVar4) < uVar2) {
      return;
    }
    iVar3 = iscsiInitDhcpPacket((undefined1 *)(lVar1 + 0x1ca),3,local_res8,local_res10);
    iscsiDhcpSendPacket(lVar1 + 0x1a0,(ushort)iVar3);
    iVar3 = iscsiDhcpWaitForResponses(param_2);
    if (0 < iVar3) break;
    lVar5 = iscsiGetTicks();
    uVar2 = (uint)lVar5;
  }
  return;
}



===== iscsiDhcpWaitForResponses @ 1400068a4 =====

int iscsiDhcpWaitForResponses(int param_1)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  iVar6 = param_1 * 1000;
  uVar3 = iscsiGetTicks();
  uVar3 = uVar3 & 0xffffffff;
  if (iVar6 != 0) {
    lVar5 = 0;
    do {
      lVar4 = iscsiGetTicks();
      if ((int)uVar3 != (int)lVar4) {
        uVar3 = iscsiGetTicks();
        uVar3 = uVar3 & 0xffffffff;
        iVar6 = iVar6 + -1;
      }
      iVar2 = iscsiL2GetRxPacket((longlong)iVar7 * 0x5ea + rx_buffers);
      lVar4 = rx_buffers;
      if ((((0 < iVar2) && (*(short *)(lVar5 + 0xc + rx_buffers) == 8)) &&
          (*(char *)(lVar5 + 0x17 + rx_buffers) == '\x11')) &&
         (((uVar1 = udp_cksum((byte *)(rx_buffers + 0xe + lVar5)), (uVar1 + 1 & 0xfffe) == 0 &&
           (*(short *)(lVar5 + 0x24 + lVar4) == 0x4400)) &&
          ((*(int *)(lVar5 + 0x3a + lVar4) != 0 &&
           (iVar2 = strncmp((char *)(lVar4 + 0x46 + lVar5),
                            (char *)(*(longlong *)
                                      (iscsiGlobalsPtr + 0xda0 +
                                      (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x12),6),
           iVar2 == 0)))))) {
        iVar7 = iVar7 + 1;
        lVar5 = lVar5 + 0x5ea;
        if (iVar7 == 4) {
          return 4;
        }
      }
    } while (iVar6 != 0);
  }
  return iVar7;
}



===== iscsiDisconnect @ 1400069b4 =====

void iscsiDisconnect(longlong param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x16c) != 0) {
    stack_close_connection(*(undefined8 *)(param_1 + 8));
    uVar1 = system_ticks + 1000;
    while (system_ticks < uVar1) {
      iscsiProcessLoop(3);
    }
  }
  *(undefined8 *)(param_1 + 8) = 0;
  return;
}



===== iscsiExtractRedirectInfo @ 140006a08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void iscsiExtractRedirectInfo(byte *param_1,byte *param_2)

{
  longlong lVar1;
  longlong lVar3;
  longlong lVar2;
  int *piVar4;
  undefined1 auStack_a8 [32];
  byte *local_88;
  byte *local_80;
  byte *local_78;
  byte *local_70;
  int local_68;
  int local_64 [3];
  byte local_58 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  local_68 = -1;
  local_64[0] = -1;
  if ((*param_1 & 4) == 0) {
    local_70 = param_1 + 0x14a;
    local_78 = param_1 + 0x148;
    local_80 = param_1 + 0x13b;
    local_88 = param_1 + 0x13a;
    isscanf(param_2,&s__d__d__d__d__d__d_,param_1 + 0x138,param_1 + 0x139);
  }
  else {
    local_88 = (byte *)local_64;
    piVar4 = &local_68;
    isscanf(param_2,&s___s___d__d,local_58,piVar4);
    lVar3 = -1;
    do {
      lVar2 = lVar3 + 1;
      lVar1 = lVar3 + 1;
      lVar3 = lVar2;
    } while (local_58[lVar1] != 0);
    iscsiParseIPv6AddrString(local_58,(ushort *)(param_1 + 0x138),(int)lVar2,(longlong)piVar4);
    if (0 < local_68) {
      *(short *)(param_1 + 0x148) = (short)local_68;
    }
    if (0 < local_64[0]) {
      *(short *)(param_1 + 0x14a) = (short)local_64[0];
    }
  }
  return;
}



===== iscsiFindKeyValue @ 140006b18 =====

undefined8
iscsiFindKeyValue(char *param_1,char *param_2,char *param_3,longlong *param_4,undefined8 *param_5)

{
  char *pcVar1;
  longlong lVar2;
  
  if (param_4 != (longlong *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined8 *)0x0) {
    *param_5 = 0;
  }
  if (*param_1 != '\0') {
    lVar2 = (longlong)param_1 - (longlong)param_2;
    do {
      if (param_3 <= param_2) {
        return 0;
      }
      if (*param_2 == '\0') {
        return 0;
      }
      if (param_2[lVar2] != *param_2) {
        return 0;
      }
      param_2 = param_2 + 1;
    } while (param_2[lVar2] != '\0');
  }
  if ((param_3 <= param_2) || (*param_2 != '=')) {
    return 0;
  }
  pcVar1 = param_2 + 1;
  do {
    if (*param_2 == '\0') break;
    param_2 = param_2 + 1;
  } while (param_2 < param_3);
  if (param_4 != (longlong *)0x0) {
    *param_4 = (longlong)pcVar1;
  }
  if (param_5 != (undefined8 *)0x0) {
    *param_5 = param_2;
  }
  return 1;
}



===== iscsiGetChallengeId @ 140006b88 =====

void iscsiGetChallengeId(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  
  uVar1 = getRandomNumber();
  *(char *)(param_1 + 0x128) = (char)uVar1;
  lVar2 = 0;
  do {
    uVar1 = getRandomNumber();
    *(char *)(lVar2 + *(longlong *)(param_1 + 0x130)) = (char)uVar1;
    lVar2 = lVar2 + 1;
  } while (lVar2 < 0x200);
  *(undefined4 *)(param_1 + 300) = 0x200;
  return;
}



===== iscsiGetPduLen @ 140006bd4 =====

short iscsiGetPduLen(longlong param_1)

{
  ushort uVar1;
  short sVar2;
  
  if (*(int *)(iscsiGlobalsPtr + 0xd78) == 0) {
    uVar1 = CONCAT11(*(undefined1 *)(param_1 + 6),*(undefined1 *)(param_1 + 7)) + 0x30;
    sVar2 = uVar1 + (-(ushort)((uVar1 & 3) != 0) & 4 - (uVar1 & 3));
  }
  else {
    sVar2 = *(short *)(iscsiGlobalsPtr + 0xd7c);
  }
  return sVar2;
}



===== iscsiInitDhcpPacket @ 140006c20 =====

int iscsiInitDhcpPacket(undefined1 *param_1,short param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  
  puVar2 = (uint *)(param_1 + 0xec);
  memset(param_1,0,0x4ec);
  *(undefined2 *)(param_1 + 1) = 0x601;
  dhcp_transaction_id = dhcp_transaction_id + 1;
  *(int *)(param_1 + 4) = dhcp_transaction_id;
  lVar5 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(lVar5 + 0x12);
  *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(lVar5 + 0x16);
  dhcp_transaction_id = dhcp_transaction_id + 1;
  *(int *)(param_1 + 4) = dhcp_transaction_id;
  *(ushort *)(param_1 + 8) = seconds << 8 | seconds >> 8;
  uVar3 = swap_dword(0x63825363);
  *puVar2 = uVar3;
  if ((param_2 == 1) || (param_2 == 3)) {
    *param_1 = 1;
    *(undefined2 *)(param_1 + 10) = 0x80;
  }
  else if (param_2 == 5) {
    *param_1 = 2;
    *(undefined4 *)(param_1 + 0xc) = *param_4;
  }
  *(undefined2 *)(param_1 + 0xf0) = 0x135;
  uVar3 = 7;
  param_1[0xf2] = (char)param_2;
  if (param_2 == 3) {
    *(undefined2 *)(param_1 + 0xf3) = 0x432;
    uVar3 = 0x13;
    *(undefined4 *)(param_1 + 0xf5) = *param_4;
    *(undefined2 *)(param_1 + 0xf9) = 0x436;
    *(undefined4 *)(param_1 + 0xfb) = *param_3;
  }
  lVar5 = -1;
  *(undefined1 *)((ulonglong)uVar3 + (longlong)puVar2) = 0x3c;
  do {
    lVar5 = lVar5 + 1;
  } while (*(char *)(*(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                     + 0x58 + lVar5) != '\0');
  *(char *)((ulonglong)(uVar3 + 1) + (longlong)puVar2) = (char)lVar5;
  memmove((void *)((ulonglong)(uVar3 + 2) + (longlong)puVar2),
          (void *)(*(longlong *)
                    (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                  0x58),(longlong)(int)lVar5);
  iVar6 = uVar3 + 2 + (int)lVar5;
  *(undefined1 *)((longlong)iVar6 + (longlong)puVar2) = 0x37;
  *(undefined1 *)((longlong)(iVar6 + 2) + (longlong)puVar2) = 1;
  *(undefined1 *)((longlong)(iVar6 + 3) + (longlong)puVar2) = 3;
  *(undefined1 *)((longlong)(iVar6 + 4) + (longlong)puVar2) = 6;
  iVar4 = iVar6 + 6;
  *(undefined1 *)((longlong)(iVar6 + 5) + (longlong)puVar2) = 0xc;
  *(undefined1 *)((longlong)iVar4 + (longlong)puVar2) = 0xf;
  *(undefined1 *)((longlong)iVar4 + 1 + (longlong)puVar2) = 0x11;
  iVar1 = iVar6 + 10;
  *(undefined1 *)((longlong)(iVar6 + 2) + 6 + (longlong)puVar2) = 0x2b;
  *(undefined1 *)((longlong)(iVar6 + 8) + 1 + (longlong)puVar2) = 0x3c;
  *(char *)((longlong)iVar6 + 1 + (longlong)puVar2) = ((char)iVar1 - ((char)iVar6 + '\x01')) + -1;
  *(undefined1 *)((longlong)(iVar6 + 3) + 7 + (longlong)puVar2) = 0x39;
  *(undefined1 *)((longlong)iVar1 + 1 + (longlong)puVar2) = 2;
  *(undefined2 *)((longlong)iVar1 + 2 + (longlong)puVar2) = 0xec04;
  *(undefined1 *)((longlong)iVar4 + 8 + (longlong)puVar2) = 0xff;
  return iVar6 + 0xfb;
}



===== iscsiL2AddMcAddr @ 140006e28 =====

undefined8 iscsiL2AddMcAddr(int *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  
  iVar4 = 0;
  lVar3 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  iVar2 = *(int *)(lVar3 + 0x24);
  if (0 < iVar2) {
    do {
      if ((*(int *)(lVar3 + 0x28 + (longlong)iVar4 * 6) == *param_1) &&
         (*(short *)(lVar3 + 0x2c + (longlong)iVar4 * 6) == (short)param_1[1])) {
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  if (iVar2 < 8) {
    *(int *)(lVar3 + 0x28 + (longlong)iVar2 * 6) = *param_1;
    *(short *)(lVar3 + 0x2c + (longlong)iVar2 * 6) = (short)param_1[1];
    piVar1 = (int *)(*(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                    + 0x24);
    *piVar1 = *piVar1 + 1;
    *(undefined4 *)
     (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
     0x1c) = 1;
    return 0;
  }
  return 0xffffffff;
}



===== iscsiL2IsOurMcAddr @ 140006ecc =====

undefined8 iscsiL2IsOurMcAddr(int *param_1)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = 0;
  lVar1 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  if (0 < *(int *)(lVar1 + 0x24)) {
    do {
      if ((*(int *)(lVar1 + 0x28 + (longlong)iVar2 * 6) == *param_1) &&
         (*(short *)(lVar1 + 0x2c + (longlong)iVar2 * 6) == (short)param_1[1])) {
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(lVar1 + 0x24));
  }
  return 0;
}



===== iscsiParseIPv6AddrString @ 140006f2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 iscsiParseIPv6AddrString(byte *param_1,ushort *param_2,int param_3,longlong param_4)

{
  code *pcVar1;
  byte bVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ushort uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  int iVar12;
  int *piVar13;
  bool bVar14;
  undefined1 auStack_78 [4];
  int aiStack_74 [7];
  int local_58 [8];
  byte local_38 [8];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[4] = 0xffffffff;
  local_58[5] = 0xffffffff;
  iVar10 = -1;
  local_58[6] = 0xffffffff;
  iVar12 = 0;
  iVar9 = 0;
  local_58[0] = -1;
  local_58[1] = 0xffffffff;
  local_58[2] = 0xffffffff;
  local_58[3] = 0xffffffff;
  if (0 < param_3) {
    lVar3 = 0;
    pbVar8 = param_1;
    do {
      if (*pbVar8 == 0x3a) {
        iVar12 = iVar12 + 1;
        if (lVar3 < 7) {
          local_58[lVar3] = iVar9;
        }
        lVar3 = lVar3 + 1;
      }
      iVar9 = iVar9 + 1;
      pbVar8 = pbVar8 + 1;
    } while (iVar9 < param_3);
    if (iVar12 - 2U < 6) {
      if (iVar12 < 7) {
        piVar13 = local_58;
        iVar7 = 0;
        lVar3 = 6;
        iVar9 = local_58[0];
        do {
          piVar13 = piVar13 + 1;
          if ((iVar9 == *piVar13 + -1) && (bVar14 = iVar10 == -1, iVar10 = -2, bVar14)) {
            iVar10 = iVar7;
          }
          iVar7 = iVar7 + 1;
          iVar9 = *piVar13;
        } while (iVar7 < 6);
        if (iVar10 + 2U < 2) {
          return 0xffffffff;
        }
        param_4 = (longlong)iVar12;
        do {
          iVar12 = iVar12 + -1;
          if (iVar12 == iVar10) break;
          local_58[lVar3] = aiStack_74[param_4 + lVar3];
          aiStack_74[param_4 + lVar3] = -1;
          lVar3 = lVar3 + -1;
        } while (-1 < lVar3);
      }
      iVar10 = 0;
      piVar13 = local_58;
      puVar11 = param_2;
      do {
        uVar4 = 0;
        bVar14 = true;
        do {
          if (!bVar14) {
            __report_rangecheckfailure();
            pcVar1 = (code *)swi(3);
            uVar5 = (*pcVar1)();
            return uVar5;
          }
          local_38[uVar4] = 0;
          uVar4 = uVar4 + 1;
          bVar14 = uVar4 < 5;
        } while ((longlong)uVar4 < 5);
        if ((iVar10 < 7) && (*piVar13 + 1U < 2)) {
          uVar6 = 0;
        }
        else {
          bVar2 = *param_1;
          iVar9 = 0;
          lVar3 = 0;
          if (bVar2 != 0x3a) {
            do {
              if ((bVar2 == 0) || (4 < lVar3)) break;
              param_1 = param_1 + 1;
              local_38[lVar3] = bVar2;
              iVar9 = iVar9 + 1;
              lVar3 = lVar3 + 1;
              bVar2 = *param_1;
            } while (bVar2 != 0x3a);
            if (4 < iVar9) {
              return 0xffffffff;
            }
          }
          if (*param_1 != 0) {
            param_1 = param_1 + 1;
          }
          isscanf(local_38,&s__x,param_2 + iVar10,param_4);
          uVar6 = (ushort)*(byte *)((longlong)puVar11 + 1) | *puVar11 << 8;
        }
        *puVar11 = uVar6;
        iVar10 = iVar10 + 1;
        puVar11 = puVar11 + 1;
        piVar13 = piVar13 + 1;
        if (7 < iVar10) {
          return 0;
        }
      } while( true );
    }
  }
  return 0xffffffff;
}



===== iscsiServiceTimer @ 140007100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void iscsiServiceTimer(void)

{
  ushort *puVar1;
  
  puVar1 = &DAT_14002d942;
  do {
    if ((puVar1[-1] == 1) && (*puVar1 <= puVar1[1])) {
      (**(code **)(puVar1 + 3))();
      puVar1[1] = 0;
    }
    puVar1 = puVar1 + 8;
  } while ((longlong)puVar1 < 0x14002d9c2);
  return;
}



===== iscsiSessionConnStackCallback @ 140007150 =====

void iscsiSessionConnStackCallback(undefined8 param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined4 *)(iscsiGlobalsPtr + 0x174) = 1;
  }
  return;
}



===== iscsiSessionDefaultInit @ 140007168 =====

void iscsiSessionDefaultInit(longlong param_1)

{
  uint uVar1;
  
  *(undefined1 *)(param_1 + 0x68) = 0xff;
  *(undefined4 *)(param_1 + 0x2c) = 1;
  *(undefined4 *)(param_1 + 0x30) = 1;
  *(undefined4 *)(param_1 + 0x34) = 1;
  *(undefined4 *)(param_1 + 0x38) = 1;
  *(undefined4 *)(param_1 + 0x28) = 1;
  *(undefined4 *)(param_1 + 0x3c) = 1;
  *(undefined4 *)(param_1 + 0x40) = 1;
  *(undefined4 *)(param_1 + 0x44) = 0x10000;
  *(undefined4 *)(param_1 + 0x48) = 0x10000;
  *(undefined4 *)(param_1 + 0x4c) = 0x10000;
  *(undefined4 *)(param_1 + 0x50) = 0x10000;
  *(undefined4 *)(param_1 + 0x5c) = 2;
  *(undefined4 *)(param_1 + 0x60) = 0x14;
  iscsiGetTicks();
  uVar1 = swap_dword(0x4000113d);
  *(uint *)(param_1 + 0x74) = uVar1;
  *(undefined2 *)(param_1 + 0x78) = 0;
  CrashDumpInitSessionBuffer(param_1);
  *(undefined4 *)(param_1 + 300) = 0xffffffff;
  return;
}



===== iscsiSessionDoRedirect @ 1400071dc =====

void iscsiSessionDoRedirect(longlong param_1)

{
  if (*(short *)(param_1 + 0x24) == 7) {
    iscsiDisconnect(param_1);
    iscsiSessionDefaultInit(param_1);
    *(undefined2 *)(param_1 + 0x86) = *(undefined2 *)(param_1 + 0x148);
    *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0xa0) = *(undefined8 *)(param_1 + 0x140);
    iscsiConnect(param_1);
  }
  return;
}



===== iscsiSessionGetTxHdrBuf @ 140007224 =====

undefined * iscsiSessionGetTxHdrBuf(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if ((*(int *)(*(longlong *)
                 (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
               0x20) == 0) && (*(char *)(iscsiGlobalsPtr + 0x17fc) == '\0')) {
    if (*(int *)(iscsiGlobalsPtr + 0x188) != 0) {
      iscsiSessionProcessDelaySendNopOut(300);
    }
    *(undefined1 *)(iscsiGlobalsPtr + 0x17fc) = 1;
    puVar1 = &DAT_140074e50;
  }
  return puVar1;
}



===== iscsiSessionHeartBeat @ 140007280 =====

void iscsiSessionHeartBeat(void)

{
  byte *pbVar1;
  
  *(short *)(iscsiGlobalsPtr + 0x108) = *(short *)(iscsiGlobalsPtr + 0x108) + 1;
  if (*(char *)(iscsiGlobalsPtr + 0x70) == '\x03') {
    if ((*(int *)(iscsiGlobalsPtr + 0x194) != *(int *)(iscsiGlobalsPtr + 0x198)) &&
       (*(char *)(iscsiGlobalsPtr + 0xd85) != '\0')) {
      *(undefined1 *)(iscsiGlobalsPtr + 0xd85) = 0;
      do {
        iscsiProcessLoop(1);
      } while (*(char *)(iscsiGlobalsPtr + 0xd83) != '\0');
      *(undefined1 *)(iscsiGlobalsPtr + 0xd85) = 1;
    }
    if ((*(short *)(iscsiGlobalsPtr + 0x180) == 0) && (*(int *)(iscsiGlobalsPtr + 0x178) == 0)) {
      if ((*(int *)(iscsiGlobalsPtr + 0x188) != 0) && (*(int *)(iscsiGlobalsPtr + 0x78c) == 0)) {
        iscsiSessionProcessDelaySendNopOut(0);
        *(undefined4 *)(iscsiGlobalsPtr + 0x188) = 0;
      }
      if ((0x28 < *(ushort *)(iscsiGlobalsPtr + 0x108)) &&
         (*(int *)(iscsiGlobalsPtr + 0x194) == *(int *)(iscsiGlobalsPtr + 0x198))) {
        *(undefined2 *)(iscsiGlobalsPtr + 0x108) = 0;
        pbVar1 = iscsiSessionGetTxHdrBuf();
        if (pbVar1 != (byte *)0x0) {
          pbVar1[0] = 0;
          pbVar1[1] = 0;
          pbVar1[2] = 0;
          pbVar1[3] = 0;
          pbVar1[4] = 0;
          pbVar1[5] = 0;
          pbVar1[6] = 0;
          pbVar1[7] = 0;
          pbVar1[8] = 0;
          pbVar1[9] = 0;
          pbVar1[10] = 0;
          pbVar1[0xb] = 0;
          pbVar1[0xc] = 0;
          pbVar1[0xd] = 0;
          pbVar1[0xe] = 0;
          pbVar1[0xf] = 0;
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
          pbVar1[0x20] = 0;
          pbVar1[0x21] = 0;
          pbVar1[0x22] = 0;
          pbVar1[0x23] = 0;
          pbVar1[0x24] = 0;
          pbVar1[0x25] = 0;
          pbVar1[0x26] = 0;
          pbVar1[0x27] = 0;
          pbVar1[0x28] = 0;
          pbVar1[0x29] = 0;
          pbVar1[0x2a] = 0;
          pbVar1[0x2b] = 0;
          pbVar1[0x2c] = 0;
          pbVar1[0x2d] = 0;
          pbVar1[0x2e] = 0;
          pbVar1[0x2f] = 0;
          pbVar1[1] = pbVar1[1] | 0x80;
          pbVar1[7] = 4;
          pbVar1[0x30] = 0x6b;
          pbVar1[0x31] = 0x65;
          pbVar1[0x32] = 0x76;
          pbVar1[0x33] = 0x54;
          pbVar1[0x14] = 0xff;
          pbVar1[0x15] = 0xff;
          pbVar1[0x16] = 0xff;
          pbVar1[0x17] = 0xff;
          iscsiSessionSendIscsiCmd(pbVar1,1,0,0);
          *(undefined1 *)(iscsiGlobalsPtr + 0x17fc) = 0;
        }
        *(int *)(iscsiGlobalsPtr + 0x194) = *(int *)(iscsiGlobalsPtr + 0x194) + 1;
        if (*(char *)(iscsiGlobalsPtr + 0xd85) != '\0') {
          *(undefined1 *)(iscsiGlobalsPtr + 0xd85) = 0;
          do {
            iscsiProcessLoop(1);
          } while (*(char *)(iscsiGlobalsPtr + 0xd83) != '\0');
          *(undefined1 *)(iscsiGlobalsPtr + 0xd85) = 1;
        }
      }
    }
  }
  return;
}



===== iscsiSessionIsTxCompleted @ 1400073f0 =====

undefined8 iscsiSessionIsTxCompleted(void)

{
  uint uVar1;
  
  uVar1 = system_ticks + 16000;
  do {
    if (uVar1 <= system_ticks) {
      return 0;
    }
    iscsiProcessLoop(1);
  } while (*(int *)(iscsiGlobalsPtr + 0x78c) != 0);
  return 1;
}



===== iscsiSessionProcessDelaySendNopOut @ 140007440 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 iscsiSessionProcessDelaySendNopOut(int param_1)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar1 = 0xffffffff;
  if ((*(int *)(iscsiGlobalsPtr + 0x188) != 0) && (*(char *)(iscsiGlobalsPtr + 0x17fc) == '\0')) {
    *(undefined1 *)(iscsiGlobalsPtr + 0x17fc) = 1;
    uRam0000000140074e58 = 0;
    _DAT_140074e68 = 0;
    _DAT_140074e50 = 0x8000;
    _DAT_140074e70 = 0;
    _DAT_140074e78 = 0;
    _DAT_140074e60 = (ulonglong)*(uint *)(iscsiGlobalsPtr + 0x18c) << 0x20;
    iscsiSessionSendIscsiCmd(&DAT_140074e50,0,0,0);
    uVar2 = param_1 + system_ticks;
    do {
      if (uVar2 <= system_ticks) goto LAB_1400074f9;
      iscsiProcessLoop(1);
    } while (*(int *)(iscsiGlobalsPtr + 0x78c) != 0);
    *(undefined4 *)(iscsiGlobalsPtr + 0x188) = 0;
    uVar1 = 0;
LAB_1400074f9:
    *(undefined1 *)(iscsiGlobalsPtr + 0x17fc) = 0;
  }
  return uVar1;
}



===== iscsiSessionProcessLogin @ 140007514 =====

void iscsiSessionProcessLogin(ushort *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = iscsi_process_login_response
                    ((byte *)param_1,iscsiGlobalsPtr + 0x794,*(char **)(param_1 + 0x70),0x2000);
  *(undefined2 *)(iscsiGlobalsPtr + 0xd86) = 0;
  *(undefined4 *)(iscsiGlobalsPtr + 0xd78) = 0;
  *(undefined4 *)(iscsiGlobalsPtr + 0xd7c) = 0;
  if (iVar1 == 7) {
    param_1[0x12] = 7;
    iscsiSessionDoRedirect((longlong)param_1);
  }
  else if (iVar1 == 0) {
    if (*(char *)(iscsiGlobalsPtr + 0x70) == '\0') {
      uVar2 = iscsi_make_login_pdu
                        ((longlong)param_1,(undefined8 *)&DAT_140074e50,*(void **)(param_1 + 0xa8),
                         0x2000);
      if ((int)uVar2 == 0) {
        param_1[1] = 0;
      }
      else {
        *(undefined8 *)(iscsiGlobalsPtr + 0xe8) = *(undefined8 *)(iscsiGlobalsPtr + 0x158);
        *(uint *)(iscsiGlobalsPtr + 0xf0) =
             (uint)CONCAT21(CONCAT11(DAT_140074e55,DAT_140074e56),DAT_140074e57);
        iscsiSessionSendProtocolData(0x140074e50,1);
        *(undefined1 *)(param_1 + 1) = 5;
      }
    }
    else if (*(char *)(iscsiGlobalsPtr + 0x70) == '\x03') {
      param_1[0x70] = 0;
      param_1[0x71] = 0;
      param_1[0x72] = 0;
      param_1[0x73] = 0;
      *param_1 = *param_1 & 0xfffd;
      param_1[1] = 0x507;
    }
    else {
      param_1[1] = 4;
    }
  }
  else {
    if (iVar1 == 4) {
      param_1[0x12] = 0xfffe;
    }
    param_1[1] = 0x608;
  }
  return;
}



===== iscsiSessionProcessRxIscsiPdu @ 14000765c =====

undefined4 iscsiSessionProcessRxIscsiPdu(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte bVar11;
  short sVar12;
  undefined4 local_res8;
  
  bVar1 = param_1[7];
  bVar2 = param_1[6];
  bVar3 = *param_1;
  if (((*(byte *)(iscsiGlobalsPtr + 8) & 1) != 0) &&
     (uVar8 = iscsiBootCancel(), (int)uVar8 != *(int *)(param_1 + 0x30))) {
    return 0xffffffff;
  }
  bVar11 = bVar3 & 0x3f;
  uVar4 = *(ushort *)(&DAT_14002d110 + ((ulonglong)bVar11 & 0xffffffffffffffdf) * 2);
  if ((bVar3 & 0x20) == 0) {
    return 0xffffffff;
  }
  if ((uVar4 & 0x800) != 0) {
    return 0xffffffff;
  }
  if (((uVar4 & 0x400) != 0) && (-1 < (char)param_1[1])) {
    return 0xffffffff;
  }
  uVar5 = swap_dword(*(uint *)(param_1 + 0x10));
  if ((uVar4 & 0x2000) != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      return 0xffffffff;
    }
  }
  if (CONCAT11(bVar2,bVar1) != 0) {
    if ((uVar4 & 0x1000) != 0) {
      return 0xffffffff;
    }
    if (*(uint *)(iscsiGlobalsPtr + 0x4c) < (uint)CONCAT11(bVar2,bVar1)) {
      return 0xffffffff;
    }
  }
  if ((bVar11 == 0x25) && ((param_1[1] & 1) == 0)) goto LAB_140007792;
  uVar6 = swap_dword(*(uint *)(param_1 + 0x18));
  if ((uVar6 == *(uint *)(iscsiGlobalsPtr + 0x40)) || (bVar11 != 0x22)) {
LAB_140007776:
    if ((bVar11 == 0x31) || ((bVar11 == 0x20 && (*(int *)(param_1 + 0x10) == -1))))
    goto LAB_140007792;
  }
  else if (0 < (int)(uVar6 - *(uint *)(iscsiGlobalsPtr + 0x40))) {
    *(uint *)(iscsiGlobalsPtr + 0x40) = uVar6;
    goto LAB_140007776;
  }
  *(int *)(iscsiGlobalsPtr + 0x40) = *(int *)(iscsiGlobalsPtr + 0x40) + 1;
LAB_140007792:
  uVar6 = *(uint *)(param_1 + 0x20);
  uVar7 = swap_dword(*(uint *)(param_1 + 0x1c));
  uVar6 = swap_dword(uVar6);
  if (-1 < (int)((uVar6 - uVar7) + 1)) {
    if (0 < (int)(uVar6 - *(int *)(iscsiGlobalsPtr + 0x3c))) {
      *(uint *)(iscsiGlobalsPtr + 0x3c) = uVar6;
    }
    if ((0 < (int)(uVar7 - *(int *)(iscsiGlobalsPtr + 0x38))) &&
       (-1 < (int)(*(int *)(iscsiGlobalsPtr + 0x34) - uVar7))) {
      *(uint *)(iscsiGlobalsPtr + 0x38) = uVar7;
    }
  }
  if (bVar11 < 0x26) {
    if (bVar11 == 0x25) {
      bVar1 = param_1[7];
      bVar2 = param_1[6];
      *(undefined8 *)(iscsiGlobalsPtr + 0xd90) = 0;
      if ((((param_1[1] & 1) != 0) &&
          (*(byte *)(iscsiGlobalsPtr + 0xe0) = param_1[3], param_1[3] == 2)) &&
         (CONCAT11(bVar2,bVar1) != 0)) {
        *(byte **)(iscsiGlobalsPtr + 0xd90) = param_1 + 0x30;
      }
      if (*(longlong *)(iscsiGlobalsPtr + 0xd90) != 0) {
        return 0;
      }
      if ((*(byte *)(iscsiGlobalsPtr + 8) & 2) == 0) {
        memmove(*(void **)(iscsiGlobalsPtr + 0xe8),param_1 + 0x30,(ulonglong)CONCAT11(bVar2,bVar1));
        return 0;
      }
      return 0;
    }
    if (bVar11 == 0x20) {
      if ((*(int *)(param_1 + 0x14) != -1) || (*(int *)(param_1 + 0x10) == -1)) {
        *(undefined4 *)(iscsiGlobalsPtr + 0x188) = 1;
        *(undefined4 *)(iscsiGlobalsPtr + 0x18c) = *(undefined4 *)(param_1 + 0x14);
        return 0;
      }
      sVar12 = 4;
      pbVar10 = (byte *)0x0;
      if (CONCAT21(CONCAT11(param_1[5],param_1[6]),param_1[7]) == 4) {
        pbVar10 = param_1 + 0x30;
      }
      if (pbVar10 == (byte *)0x0) {
        return 0;
      }
      pbVar9 = &s_kevT;
      do {
        sVar12 = sVar12 + -1;
        if ((pbVar10 + -0x1400185c0)[(longlong)pbVar9] != *pbVar9) {
          return 0;
        }
        pbVar9 = pbVar9 + 1;
      } while (sVar12 != 0);
      *(int *)(iscsiGlobalsPtr + 0x198) = *(int *)(iscsiGlobalsPtr + 0x198) + 1;
      return 0;
    }
    if (bVar11 == 0x21) {
      bVar1 = param_1[6];
      bVar2 = param_1[5];
      bVar3 = param_1[7];
      *(byte *)(iscsiGlobalsPtr + 0xe0) = param_1[3];
      if ((param_1[3] == 2) && (CONCAT21(CONCAT11(bVar2,bVar1),bVar3) != 0)) {
        *(byte **)(iscsiGlobalsPtr + 0xd90) = param_1 + 0x30;
        return 0;
      }
      *(undefined8 *)(iscsiGlobalsPtr + 0xd90) = 0;
      return 0;
    }
    if (bVar11 == 0x22) {
      return 0;
    }
    if (bVar11 == 0x23) {
      return 0xffffffff;
    }
    if (bVar11 == 0x24) {
      return 0;
    }
  }
  else {
    if (bVar11 == 0x26) {
      if (*(uint *)(iscsiGlobalsPtr + 0x30) == uVar5) {
        *(undefined1 *)(iscsiGlobalsPtr + 0x70) = 0xff;
        return 0;
      }
      return 0;
    }
    if (bVar11 == 0x31) {
      uVar5 = swap_dword(*(uint *)(param_1 + 0x2c));
      uVar6 = swap_dword(*(uint *)(param_1 + 0x28));
      if (*(int *)(iscsiGlobalsPtr + 0x48) == 0) {
        return 0;
      }
      if (*(char *)(iscsiGlobalsPtr + 0xe0) != -1) {
        return 0;
      }
      if (*(int *)(iscsiGlobalsPtr + 0x178) == 0) {
        iscsiSessionSendDataOutCmd
                  ((ulonglong)(uVar6 & 0xffff) + *(longlong *)(iscsiGlobalsPtr + 0xe8),
                   uVar5 & 0xffff,*(uint *)(param_1 + 0x14));
        return 0;
      }
      *(short *)(iscsiGlobalsPtr + 0x180) = (short)uVar5;
      *(short *)(iscsiGlobalsPtr + 0x182) = (short)uVar6;
      *(undefined4 *)(iscsiGlobalsPtr + 0x184) = *(undefined4 *)(param_1 + 0x14);
      *(undefined4 *)(iscsiGlobalsPtr + 0x178) = 0;
      return 0;
    }
    if (bVar11 == 0x32) {
      return 0;
    }
    if (bVar11 == 0x3f) {
      return 0;
    }
  }
  return local_res8;
}



===== iscsiSessionRxPdu @ 140007a80 =====

void iscsiSessionRxPdu(byte *param_1,char *param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  
  lVar5 = iscsiGlobalsPtr;
  if ((*param_1 & 2) == 0) {
    if (*(uint *)(iscsiGlobalsPtr + 0xd78) + param_3 < 0x5e4) {
      memmove((void *)(iscsiGlobalsPtr + 0x794 + (ulonglong)*(uint *)(iscsiGlobalsPtr + 0xd78)),
              param_2,(longlong)(int)param_3);
    }
  }
  else {
    uVar6 = *(uint *)(param_1 + 0xec);
    lVar3 = *(longlong *)(param_1 + 0xe0);
    if (*(int *)(iscsiGlobalsPtr + 0xd78) == 0) {
      uVar4 = *(undefined8 *)(param_2 + 8);
      cVar1 = param_2[6];
      uVar8 = param_3 - 0x30;
      cVar2 = param_2[7];
      *(undefined8 *)(iscsiGlobalsPtr + 0x794) = *(undefined8 *)param_2;
      *(undefined8 *)(lVar5 + 0x79c) = uVar4;
      uVar4 = *(undefined8 *)(param_2 + 0x18);
      *(undefined8 *)(lVar5 + 0x7a4) = *(undefined8 *)(param_2 + 0x10);
      *(undefined8 *)(lVar5 + 0x7ac) = uVar4;
      uVar4 = *(undefined8 *)(param_2 + 0x28);
      *(undefined8 *)(lVar5 + 0x7b4) = *(undefined8 *)(param_2 + 0x20);
      *(undefined8 *)(lVar5 + 0x7bc) = uVar4;
      if ((param_1[0x68] == 3) && (*(uint *)(iscsiGlobalsPtr + 0xf0) < uVar8)) {
        uVar8 = *(uint *)(iscsiGlobalsPtr + 0xf0);
      }
      if (0 < (int)uVar8) {
        memmove((void *)((ulonglong)uVar6 + lVar3),param_2 + 0x30,(longlong)(int)uVar8);
      }
      if (((*param_2 == '%') && ((int)(CONCAT11(cVar1,cVar2) + 0x60) <= (int)param_3)) &&
         (uVar7 = (ulonglong)CONCAT11(cVar1,cVar2), param_2[uVar7 + 0x30] == '!')) {
        param_2[1] = param_2[1] | 1;
        param_2[3] = param_2[uVar7 + 0x33];
      }
      *(uint *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + (uVar8 & 0xffff);
    }
    else {
      uVar8 = param_3;
      if (*(uint *)(iscsiGlobalsPtr + 0xf0) < uVar6 + param_3) {
        uVar8 = *(uint *)(iscsiGlobalsPtr + 0xf0) - uVar6;
      }
      if (0 < (int)uVar8) {
        memmove((void *)((ulonglong)uVar6 + lVar3),param_2,(longlong)(int)uVar8);
        uVar6 = *(uint *)(param_1 + 0xec);
      }
      *(uint *)(param_1 + 0xec) = (uVar8 & 0xffff) + uVar6;
    }
  }
  if (*(int *)(iscsiGlobalsPtr + 0xd78) == 0) {
    uVar6 = CONCAT11(*(undefined1 *)(iscsiGlobalsPtr + 0x79a),
                     *(undefined1 *)(iscsiGlobalsPtr + 0x79b)) + 0x30;
    uVar8 = uVar6 & 3;
    *(uint *)(iscsiGlobalsPtr + 0xd7c) = (-(uint)(uVar8 != 0) & 4 - uVar8) + (uVar6 & 0xffff);
  }
  *(int *)(iscsiGlobalsPtr + 0xd78) = *(int *)(iscsiGlobalsPtr + 0xd78) + (param_3 & 0xffff);
  *(int *)(iscsiGlobalsPtr + 0xd7c) = *(int *)(iscsiGlobalsPtr + 0xd7c) - (param_3 & 0xffff);
  if (((*(int *)(iscsiGlobalsPtr + 0xd7c) == 0) &&
      (*(undefined2 *)(iscsiGlobalsPtr + 0xd86) = 1, (*param_1 & 2) != 0)) &&
     (*(uint *)(param_1 + 0xe8) <= *(uint *)(param_1 + 0xec))) {
    param_1[0xec] = 0;
    param_1[0xed] = 0;
    param_1[0xee] = 0;
    param_1[0xef] = 0;
  }
  return;
}



===== iscsiSessionRxPduUnsol @ 140007c88 =====

uint iscsiSessionRxPduUnsol(undefined8 param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (*(int *)(iscsiGlobalsPtr + 0xd78) == 0) {
    uVar1 = CONCAT11(*(undefined1 *)((longlong)param_2 + 6),*(undefined1 *)((longlong)param_2 + 7))
            + 0x30;
    uVar2 = uVar1 & 3;
    *(uint *)(iscsiGlobalsPtr + 0xd7c) = (-(uint)(uVar2 != 0) & 4 - uVar2) + (uVar1 & 0xffff);
  }
  uVar3 = (ulonglong)param_3;
  if (*(uint *)(iscsiGlobalsPtr + 0xd7c) < param_3) {
    uVar3 = (ulonglong)*(uint *)(iscsiGlobalsPtr + 0xd7c);
  }
  uVar1 = (uint)uVar3;
  if (*(uint *)(iscsiGlobalsPtr + 0xd78) + uVar1 < 0x5e4) {
    memmove((void *)(iscsiGlobalsPtr + 0x794 + (ulonglong)*(uint *)(iscsiGlobalsPtr + 0xd78)),
            param_2,(longlong)(int)uVar1);
    if ((int)uVar1 < (int)param_3) {
      mm_printk("iscsiSessionRxPduUnsol: copy_len %d [%x], data_len %d [%x]\n",uVar3,
                (ulonglong)*(byte *)(iscsiGlobalsPtr + 0x794),(ulonglong)param_3);
    }
    *(int *)(iscsiGlobalsPtr + 0xd78) = *(int *)(iscsiGlobalsPtr + 0xd78) + (uVar1 & 0xffff);
    *(int *)(iscsiGlobalsPtr + 0xd7c) = *(int *)(iscsiGlobalsPtr + 0xd7c) - (uVar1 & 0xffff);
    if (*(int *)(iscsiGlobalsPtr + 0xd7c) == 0) {
      *(undefined2 *)(iscsiGlobalsPtr + 0xd86) = 1;
    }
    param_3 = uVar1;
  }
  return param_3;
}



===== iscsiSessionSendDataOutCmd @ 140007da4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 iscsiSessionSendDataOutCmd(longlong param_1,undefined4 param_2,uint param_3)

{
  uRam0000000140074e58 = 0;
  _DAT_140074e68 = 0;
  _DAT_140074e60 = (ulonglong)param_3 << 0x20;
  _DAT_140074e50 =
       CONCAT16((char)((uint)param_2 >> 8),CONCAT15((char)((uint)param_2 >> 0x10),0x8000));
  _DAT_140074e70 = 0;
  _DAT_140074e78 = 0;
  _DAT_140074e50 = CONCAT71(_DAT_140074e50 >> 8,5);
  _DAT_140074e50 = CONCAT17((char)param_2,_DAT_140074e50);
  iscsiSessionSendIscsiCmd(&DAT_140074e50,1,param_1,param_2);
  return 0;
}



===== iscsiSessionSendDataOutWithR2T @ 140007e10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 iscsiSessionSendDataOutWithR2T(byte *param_1,undefined8 param_2,uint param_3)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  uint uVar6;
  undefined8 uVar7;
  ushort uVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint uVar11;
  ushort uVar12;
  
  lVar3 = iscsiGlobalsPtr;
  lVar9 = 0;
  uVar10 = 0;
  iscsiSessionSendIscsiCmd(param_1,2,0,0);
  *(undefined8 *)(lVar3 + 0xe8) = param_2;
  *(uint *)(lVar3 + 0xf0) = param_3;
  *(undefined4 *)(lVar3 + 0x17c) = 0;
  if (param_3 == 0) {
LAB_14000800f:
    *(int *)(lVar3 + 0x34) = *(int *)(lVar3 + 0x34) + 1;
    *(int *)(lVar3 + 0x30) = *(int *)(lVar3 + 0x30) + 1;
    iscsiCheckPendingNopIn();
    return 0;
  }
LAB_140007e60:
  *(undefined1 *)(lVar3 + 0xe0) = 0xff;
  *(undefined4 *)(lVar3 + 0x178) = 1;
  *(undefined8 *)(lVar3 + 0xe8) = param_2;
  lVar4 = iscsiGlobalsPtr;
  uVar11 = system_ticks + 16000;
  do {
    if (uVar11 <= system_ticks) goto LAB_140007ff3;
    iscsiProcessLoop(1);
    if (*(int *)(iscsiGlobalsPtr + 0x178) == 0) {
      uVar8 = *(ushort *)(lVar4 + 0x180);
      uVar11 = 0;
      lVar2 = *(longlong *)(iscsiGlobalsPtr + 0xe8);
      uVar1 = *(ushort *)(lVar4 + 0x182);
      if (uVar8 == 0) goto LAB_140008003;
      goto LAB_140007f05;
    }
  } while (*(byte *)(iscsiGlobalsPtr + 0xe0) == 0xff);
  mm_printk("iscsiSessionIsReadyTransferReceived: skip R2T wait by %x\n",
            (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xe0),lVar9,uVar10);
LAB_140007ff3:
  if (*(char *)(iscsiGlobalsPtr + 0xe0) == '\x02') {
    *(int *)(lVar3 + 0x34) = *(int *)(lVar3 + 0x34) + 1;
    *(int *)(lVar3 + 0x30) = *(int *)(lVar3 + 0x30) + 1;
    return 0xffffffff;
  }
  goto LAB_140008003;
  while( true ) {
    *(int *)(lVar4 + 0x17c) = *(int *)(lVar4 + 0x17c) + (uint)uVar12;
    uVar11 = uVar11 + 1;
    if (uVar8 == 0) break;
LAB_140007f05:
    uRam0000000140074e58 = 0;
    _DAT_140074e50 = 5;
    _DAT_140074e68 = 0;
    _DAT_140074e70 = 0;
    _DAT_140074e78 = 0;
    if ((uint)uVar8 < *(uint *)(lVar4 + 0x50)) {
      uVar12 = uVar8;
    }
    else {
      uVar12 = *(ushort *)(lVar4 + 0x50);
    }
    uVar8 = uVar8 - uVar12;
    _DAT_140074e60 = (ulonglong)*(uint *)(lVar4 + 0x184) << 0x20;
    uVar6 = swap_dword(*(int *)(lVar4 + 0x50) * uVar11 + (uint)uVar1);
    _DAT_140074e78 = CONCAT44(DAT_140074e78_4,uVar6);
    bVar5 = DAT_140074e51 & 0x7f;
    _DAT_140074e50 = CONCAT11(~-(uVar8 != 0) & 0x80U | bVar5,DAT_140074e50);
    uVar6 = swap_dword(uVar11);
    _DAT_140074e70 = CONCAT44(uVar6,_DAT_140074e70);
    _DAT_140074e50 = CONCAT17((char)uVar12,CONCAT16((char)(uVar12 >> 8),_DAT_140074e50));
    _DAT_140074e50 = CONCAT26(_DAT_140074e56,_DAT_140074e50) & 0xffff00ffffffffff;
    uVar10 = (ulonglong)uVar12;
    lVar9 = (ulonglong)(*(int *)(lVar4 + 0x50) * uVar11) + (ulonglong)uVar1 + lVar2;
    iscsiSessionSendIscsiCmd(&DAT_140074e50,3,lVar9,(uint)uVar12);
    uVar7 = iscsiSessionIsTxCompleted();
    if ((int)uVar7 != 1) goto LAB_140007ff3;
  }
LAB_140008003:
  if (param_3 <= *(uint *)(lVar3 + 0x17c)) goto LAB_14000800f;
  goto LAB_140007e60;
}



===== iscsiSessionSendIscsiCmd @ 14000803c =====

undefined8 iscsiSessionSendIscsiCmd(byte *param_1,short param_2,longlong param_3,undefined4 param_4)

{
  uint uVar1;
  longlong lVar2;
  
  if (param_2 == 0) {
    param_1[0x10] = 0xff;
    param_1[0x11] = 0xff;
    param_1[0x12] = 0xff;
    param_1[0x13] = 0xff;
    *param_1 = *param_1 | 0x40;
    uVar1 = swap_dword(*(uint *)(iscsiGlobalsPtr + 0x34));
    *(uint *)(param_1 + 0x18) = uVar1;
  }
  else if (param_2 == 1) {
    uVar1 = swap_dword(*(uint *)(iscsiGlobalsPtr + 0x34));
    *(uint *)(param_1 + 0x18) = uVar1;
    if ((*param_1 & 0x40) == 0) {
      *(int *)(iscsiGlobalsPtr + 0x34) = *(int *)(iscsiGlobalsPtr + 0x34) + 1;
    }
    uVar1 = swap_dword(*(uint *)(iscsiGlobalsPtr + 0x30));
    *(uint *)(param_1 + 0x10) = uVar1;
    *(int *)(iscsiGlobalsPtr + 0x30) = *(int *)(iscsiGlobalsPtr + 0x30) + 1;
    if (*(int *)(iscsiGlobalsPtr + 0x30) == -1) {
      *(undefined4 *)(iscsiGlobalsPtr + 0x30) = 0;
    }
  }
  else {
    if (param_2 == 2) {
      uVar1 = swap_dword(*(uint *)(iscsiGlobalsPtr + 0x34));
      *(uint *)(param_1 + 0x18) = uVar1;
    }
    else if (param_2 != 3) goto LAB_14000810e;
    uVar1 = swap_dword(*(uint *)(iscsiGlobalsPtr + 0x30));
    *(uint *)(param_1 + 0x10) = uVar1;
  }
LAB_14000810e:
  lVar2 = 0xce;
  do {
    *(undefined2 *)(param_1 + lVar2 + -0xc6) = *(undefined2 *)(lVar2 + iscsiGlobalsPtr);
    lVar2 = lVar2 + 2;
  } while (lVar2 < 0xd6);
  uVar1 = swap_dword(*(uint *)(iscsiGlobalsPtr + 0x40));
  *(uint *)(param_1 + 0x1c) = uVar1;
  *(undefined1 *)(iscsiGlobalsPtr + 0xe0) = 0xff;
  *(longlong *)(iscsiGlobalsPtr + 0xe8) = param_3;
  *(undefined4 *)(iscsiGlobalsPtr + 0xf0) = param_4;
  iscsiSessionSendProtocolData((longlong)param_1,(uint)(param_3 != 0));
  return 0;
}



===== iscsiSessionSendProtocolData @ 140008198 =====

undefined8 iscsiSessionSendProtocolData(longlong param_1,int param_2)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  ushort uVar7;
  undefined1 uVar8;
  
  *(undefined2 *)(iscsiGlobalsPtr + 0x108) = 0;
  if (param_2 == 0) {
    *(ushort *)(iscsiGlobalsPtr + 8) = *(ushort *)(iscsiGlobalsPtr + 8) & 0xfffd;
  }
  else {
    *(ushort *)(iscsiGlobalsPtr + 8) = *(ushort *)(iscsiGlobalsPtr + 8) | 2;
  }
  *(undefined4 *)(iscsiGlobalsPtr + 0xf4) = 0;
  iVar4 = CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 5),*(undefined1 *)(param_1 + 6)),
                   *(undefined1 *)(param_1 + 7)) + 0x30;
  *(int *)(iscsiGlobalsPtr + 0x784) = iVar4;
  *(int *)(iscsiGlobalsPtr + 0x78c) = iVar4;
  *(undefined4 *)(iscsiGlobalsPtr + 0x788) = 0;
  *(undefined4 *)(iscsiGlobalsPtr + 0x790) = 0;
  uVar3 = *(uint *)(iscsiGlobalsPtr + 0x784) & 3;
  *(int *)(iscsiGlobalsPtr + 0x78c) =
       *(int *)(iscsiGlobalsPtr + 0x78c) + (-(uint)(uVar3 != 0) & 4 - uVar3);
  lVar2 = iscsiGlobalsPtr;
  lVar6 = iscsiGlobalsPtr + 0x1a0;
  uVar1 = *(ushort *)(iscsiGlobalsPtr + 0x78c);
  uVar5 = *(undefined8 *)(iscsiGlobalsPtr + 0x10);
  if ((*(byte *)(iscsiGlobalsPtr + 8) & 2) == 0) {
    uVar8 = 0;
    uVar7 = uVar1;
  }
  else {
    stack_write_tcp_data(uVar5,lVar6,0x30,1);
    if (uVar1 < 0x31) goto LAB_1400082bb;
    lVar6 = *(longlong *)(lVar2 + 0xe8);
    uVar5 = *(undefined8 *)(lVar2 + 0x10);
    uVar8 = 1;
    uVar7 = uVar1 - 0x30;
  }
  stack_write_tcp_data(uVar5,lVar6,uVar7,uVar8);
LAB_1400082bb:
  stack_flush_tcp_data(*(undefined8 *)(lVar2 + 0x10));
  *(undefined2 *)(iscsiGlobalsPtr + 0xd88) = 1;
  *(uint *)(iscsiGlobalsPtr + 0x790) = (uint)uVar1;
  *(undefined4 *)(iscsiGlobalsPtr + 0x78c) = 0;
  return 0;
}



===== iscsiSessionSendWriteData @ 14000830c =====

undefined8 iscsiSessionSendWriteData(byte *param_1,undefined8 param_2,longlong param_3,uint param_4)

{
  undefined8 uVar1;
  
  *(undefined4 *)(iscsiGlobalsPtr + 0x178) = 0;
  if ((*(int *)(iscsiGlobalsPtr + 0x44) == 0) || (*(uint *)(iscsiGlobalsPtr + 0x54) < param_4)) {
    if (*(int *)(iscsiGlobalsPtr + 0x48) == 0) {
      param_1[1] = param_1[1] & 0x7f;
      iscsiSessionSendIscsiCmd(param_1,2,0,0);
      uVar1 = iscsiSessionIsTxCompleted();
      if ((int)uVar1 != 1) {
        return 0xffffffff;
      }
      iscsiSessionSendDataOutCmd(param_3,param_4,0xffffffff);
    }
    else {
      iscsiSessionSendDataOutWithR2T(param_1,param_3,param_4);
      *(undefined2 *)(iscsiGlobalsPtr + 0x180) = 0;
    }
  }
  else {
    *param_1 = *param_1 | 0x40;
    param_1[7] = (byte)param_4;
    param_1[5] = (byte)(param_4 >> 0x10);
    param_1[6] = (byte)(param_4 >> 8);
    iscsiSessionSendIscsiCmd(param_1,2,param_3,param_4);
  }
  return 0;
}



===== iscsiSessionServiceRxIndication @ 1400083c4 =====

void iscsiSessionServiceRxIndication
               (char *param_1,ushort param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  byte bVar2;
  longlong lVar3;
  ushort uVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort *puVar7;
  
  lVar3 = iscsiGlobalsPtr;
  puVar7 = (ushort *)(iscsiGlobalsPtr + 8);
  uVar6 = (ulonglong)param_2;
  bVar2 = *(byte *)(iscsiGlobalsPtr + 0xb);
  if (2 < bVar2) {
    if (bVar2 < 5) {
      puVar1 = (undefined8 *)(iscsiGlobalsPtr + 0x160);
      *puVar7 = *puVar7 | 2;
      *(undefined8 *)(lVar3 + 0xe8) = *puVar1;
      iscsiSessionRxPdu((byte *)puVar7,param_1,(uint)param_2);
      if (*(short *)(iscsiGlobalsPtr + 0xd86) == 1) {
        iscsiSessionProcessLogin(puVar7);
      }
    }
    else if (bVar2 == 5) {
      uVar4 = iscsiGetPduLen((longlong)param_1);
      if (uVar4 < param_2) {
        mm_printk("iscsiSessionRxPduUnsol: pdu_len %d, data_len %d\n",(ulonglong)uVar4,uVar6,param_4
                 );
        while (uVar4 = (ushort)uVar6, uVar4 != 0) {
          uVar5 = iscsiSessionRxPduUnsol(puVar7,param_1,(uint)uVar6);
          if (*(short *)(iscsiGlobalsPtr + 0xd86) == 1) {
            iscsiSessionProcessRxIscsiPdu((byte *)(iscsiGlobalsPtr + 0x794));
            *(undefined2 *)(iscsiGlobalsPtr + 0xd86) = 0;
            *(undefined4 *)(iscsiGlobalsPtr + 0xd78) = 0;
            *(undefined4 *)(iscsiGlobalsPtr + 0xd7c) = 0;
          }
          if (uVar4 < (ushort)uVar5) {
            uVar6 = 0;
          }
          else {
            uVar6 = (ulonglong)(ushort)(uVar4 - (ushort)uVar5);
            param_1 = param_1 + (uVar5 & 0xffff);
          }
        }
      }
      else {
        iscsiSessionRxPdu((byte *)puVar7,param_1,(uint)param_2);
        if (*(short *)(iscsiGlobalsPtr + 0xd86) == 1) {
          iscsiSessionProcessRxIscsiPdu((byte *)(iscsiGlobalsPtr + 0x794));
          *(undefined2 *)(iscsiGlobalsPtr + 0xd86) = 0;
          *(undefined4 *)(iscsiGlobalsPtr + 0xd78) = 0;
          *(undefined4 *)(iscsiGlobalsPtr + 0xd7c) = 0;
        }
      }
    }
    else if (bVar2 == 6) {
      iscsiAbortRoutine();
    }
  }
  return;
}



===== iscsiSessionStart @ 14000855c =====

void iscsiSessionStart(ushort *param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined2 *puVar3;
  
  memset(param_1,0,0x198);
  iscsiSessionDefaultInit((longlong)param_1);
  puVar3 = iscsiAddTimer(0x6e,iscsiSessionHeartBeat);
  *(undefined2 **)(param_1 + 0x7c) = puVar3;
  *(longlong *)(param_1 + 0x58) =
       *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x200;
  lVar1 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  *(longlong *)(param_1 + 0x54) = param_2 + 0x16;
  *(longlong *)(param_1 + 0x5c) = lVar1 + 0x438;
  param_1[0x43] = *(ushort *)(param_2 + 0x14);
  uVar2 = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_1 + 0x4c) = *(undefined8 *)(param_2 + 4);
  *(undefined8 *)(param_1 + 0x50) = uVar2;
  uVar2 = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_1 + 0x44) = *(undefined8 *)(param_2 + 4);
  *(undefined8 *)(param_1 + 0x48) = uVar2;
  param_1[0x42] = *(ushort *)(param_2 + 0x14);
  isscanf((byte *)(param_2 + 0x97),(byte *)"%x-%x-%x-%x",param_1 + 99,param_1 + 100);
  if (param_3 != 0) {
    *param_1 = *param_1 | 4;
  }
  if ((*(uint *)(*(longlong *)
                  (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4)
      & 0x10000) == 0) {
    param_1[8] = 0;
    param_1[9] = 0;
  }
  else {
    param_1[8] = 1;
    param_1[9] = 0;
    *(longlong *)(param_1 + 0x8c) =
         *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
         + 0x3a6;
    *(longlong *)(param_1 + 0x90) =
         *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
         + 0x427;
    *(undefined8 *)(param_1 + 0x84) = *(undefined8 *)(param_2 + 0xb0);
    *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(param_2 + 0xb8);
  }
  iscsiConnect((longlong)param_1);
  return;
}



===== iscsiSessionStop @ 14000870c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void iscsiSessionStop(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 0x68) == '\x03') {
    uRam0000000140074e58 = 0;
    _DAT_140074e50 = 0x8006;
    uVar2 = system_ticks + 1000;
    _DAT_140074e60 = 0;
    _DAT_140074e68 = 0;
    _DAT_140074e70 = 0;
    _DAT_140074e78 = 0;
    uVar1 = swap_dword(*(uint *)(param_1 + 0x28));
    _DAT_140074e60 = CONCAT44(_DAT_140074e64,uVar1);
    uVar1 = swap_dword(*(uint *)(param_1 + 0x2c));
    _DAT_140074e68 = CONCAT44(_DAT_140074e6c,uVar1);
    uVar1 = swap_dword(*(uint *)(param_1 + 0x38));
    _DAT_140074e68 = CONCAT44(uVar1,_DAT_140074e68);
    iscsiSessionSendProtocolData(0x140074e50,0);
    do {
      if (uVar2 <= system_ticks) break;
      iscsiProcessLoop(3);
    } while (*(char *)(param_1 + 0x68) == '\x03');
  }
  if (*(undefined2 **)(param_1 + 0xf8) != (undefined2 *)0x0) {
    **(undefined2 **)(param_1 + 0xf8) = 0;
  }
  iscsiDisconnect(param_1);
  return;
}



===== iscsiSessionTxState @ 1400087c4 =====

void iscsiSessionTxState(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  byte bVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar4 = iscsiGlobalsPtr;
  lVar1 = iscsiGlobalsPtr + 8;
  bVar3 = *(byte *)(iscsiGlobalsPtr + 10);
  if (bVar3 == 2) {
    if (*(int *)(iscsiGlobalsPtr + 0x174) != 0) {
      *(undefined4 *)(iscsiGlobalsPtr + 0x78c) = 0;
      *(undefined4 *)(iscsiGlobalsPtr + 0x788) = 0;
      *(undefined4 *)(iscsiGlobalsPtr + 0x790) = 0;
      *(undefined2 *)(lVar4 + 10) = 3;
    }
  }
  else if (2 < bVar3) {
    if (bVar3 < 5) {
      puVar2 = (undefined8 *)(iscsiGlobalsPtr + 0x158);
      *(undefined2 *)(iscsiGlobalsPtr + 0x2c) = 0x203;
      uVar5 = iscsi_make_login_pdu(lVar1,(undefined8 *)&DAT_140074e50,(void *)*puVar2,0x2000);
      if ((int)uVar5 == 0) {
        *(undefined2 *)(lVar4 + 10) = 0x608;
        return;
      }
      *(undefined8 *)(iscsiGlobalsPtr + 0xe8) = *(undefined8 *)(iscsiGlobalsPtr + 0x158);
      *(uint *)(iscsiGlobalsPtr + 0xf0) =
           (uint)CONCAT21(CONCAT11(DAT_140074e55,DAT_140074e56),DAT_140074e57);
      iscsiSessionSendProtocolData(0x140074e50,1);
      *(undefined1 *)(lVar4 + 10) = 5;
    }
    else {
      if (bVar3 != 5) {
        if (bVar3 == 8) {
          iscsiAbortRoutine();
          return;
        }
        return;
      }
      if (*(int *)(iscsiGlobalsPtr + 0x78c) != 0) {
        return;
      }
    }
    *(undefined4 *)(iscsiGlobalsPtr + 0xd78) = 0;
    *(undefined4 *)(iscsiGlobalsPtr + 0xd7c) = 0;
    memset((void *)(iscsiGlobalsPtr + 0x794),0,0x5e4);
    *(undefined2 *)(lVar4 + 10) = 0x306;
  }
  return;
}



===== iscsiSessionWaitForCommandDone @ 140008914 =====

undefined1 iscsiSessionWaitForCommandDone(void)

{
  uint uVar1;
  
  uVar1 = system_ticks + 16000;
  while ((system_ticks < uVar1 && (*(char *)(iscsiGlobalsPtr + 0xe0) == -1))) {
    iscsiProcessLoop(1);
  }
  return *(undefined1 *)(iscsiGlobalsPtr + 0xe0);
}



===== iscsiSetupCmd @ 140008960 =====

void iscsiSetupCmd(undefined8 *param_1,undefined1 param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined1 *)param_1 = param_2;
  return;
}



===== iscsiTimerTick @ 140008974 =====

void iscsiTimerTick(void)

{
  bool bVar1;
  ushort *puVar2;
  longlong lVar3;
  
  bVar1 = false;
  puVar2 = &DAT_14002d944;
  system_ticks = system_ticks + 1;
  lVar3 = 8;
  do {
    if ((puVar2[-2] == 1) && (*puVar2 = *puVar2 + 1, puVar2[-1] <= *puVar2)) {
      bVar1 = true;
    }
    puVar2 = puVar2 + 8;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if ((*(char *)(iscsiGlobalsPtr + 0xd85) != '\0') && (bVar1)) {
    iscsiServiceTimer();
  }
  return;
}



===== iscsi_make_login_pdu @ 1400089d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 iscsi_make_login_pdu(longlong param_1,undefined8 *param_2,void *param_3,uint param_4)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 extraout_var_03;
  undefined7 extraout_var_04;
  undefined7 extraout_var_05;
  undefined7 extraout_var_06;
  undefined7 extraout_var_07;
  undefined7 extraout_var_08;
  undefined7 extraout_var_09;
  undefined7 extraout_var_10;
  undefined7 extraout_var_11;
  undefined7 extraout_var_12;
  undefined7 extraout_var_13;
  undefined7 extraout_var_14;
  undefined7 extraout_var_15;
  undefined7 extraout_var_16;
  undefined7 extraout_var_17;
  undefined7 extraout_var_18;
  undefined7 extraout_var_19;
  undefined7 extraout_var_20;
  undefined7 extraout_var_21;
  char *pcVar4;
  char *pcVar5;
  ulonglong uVar6;
  longlong lVar8;
  longlong lVar7;
  char *pcVar9;
  undefined1 auStackY_188 [32];
  byte local_158 [16];
  char local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  memset(param_3,0,(longlong)(int)param_4);
  *(undefined1 *)param_2 = 0x43;
  *(undefined4 *)(param_2 + 1) = *(undefined4 *)(param_1 + 0x74);
  *(undefined2 *)((longlong)param_2 + 0xc) = *(undefined2 *)(param_1 + 0x78);
  uVar3 = swap_dword(*(uint *)(param_1 + 0x28));
  *(uint *)(param_2 + 2) = uVar3;
  uVar3 = swap_dword(*(uint *)(param_1 + 0x2c));
  *(undefined2 *)((longlong)param_2 + 2) = 0;
  *(uint *)(param_2 + 3) = uVar3;
  *(undefined2 *)((longlong)param_2 + 0x14) = 0x100;
  uVar3 = swap_dword(*(uint *)(param_1 + 0x38));
  *(uint *)((longlong)param_2 + 0x1c) = uVar3;
  cVar1 = *(char *)(param_1 + 0x68);
  if (cVar1 == -1) {
    pcVar4 = *(char **)(param_1 + 0xb0);
    if (pcVar4 == (char *)0x0) {
      return 0;
    }
    if (*pcVar4 == '\0') {
      return 0;
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"InitiatorName",pcVar4)
    ;
    if ((int)CONCAT71(extraout_var,bVar2) == 0) {
      return 0;
    }
    pcVar4 = *(char **)(param_1 + 0xb8);
    if (((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) &&
       (bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"InitiatorAlias",
                             pcVar4), (int)CONCAT71(extraout_var_00,bVar2) == 0)) {
      return 0;
    }
    if ((**(char **)(param_1 + 0xa8) != '\0') &&
       (bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"TargetName",
                             *(char **)(param_1 + 0xa8)), (int)CONCAT71(extraout_var_01,bVar2) == 0)
       ) {
      return 0;
    }
    pcVar4 = "Normal";
    if (*(int *)(param_1 + 100) == 1) {
      pcVar4 = "Discovery";
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,&s_SessionType,pcVar4);
    if ((int)CONCAT71(extraout_var_02,bVar2) == 0) {
      return 0;
    }
    pcVar4 = "CHAP";
    if (*(int *)(param_1 + 0x10) == 0) {
      pcVar4 = "None";
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,&s_AuthMethod,pcVar4);
    if ((int)CONCAT71(extraout_var_03,bVar2) == 0) {
      return 0;
    }
    *(undefined1 *)(param_1 + 0x68) = 0;
    *(byte *)((longlong)param_2 + 1) = *(byte *)((longlong)param_2 + 1) & 0xf3;
    *(undefined4 *)(param_1 + 0x6c) = 1;
    *(byte *)((longlong)param_2 + 1) = *(byte *)((longlong)param_2 + 1) & 0xfd | 0x81;
    return 1;
  }
  if (cVar1 == '\0') {
    if (*(int *)(param_1 + 0x10) != 1) {
      return 1;
    }
    if (-1 < *(int *)(param_1 + 300)) {
      pcVar4 = *(char **)(param_1 + 0x160);
      bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"CHAP_N",
                           *(void **)(param_1 + 0x118));
      if ((int)CONCAT71(extraout_var_18,bVar2) == 0) {
        return 0;
      }
      lVar7 = -1;
      do {
        lVar8 = lVar7;
        lVar7 = lVar8 + 1;
      } while (*(char *)(*(longlong *)(param_1 + 0x120) + lVar7) != '\0');
      *pcVar4 = *(char *)(param_1 + 0x128);
      pcVar9 = *(char **)(param_1 + 0x120);
      pcVar5 = pcVar4;
      do {
        pcVar5 = pcVar5 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        *pcVar5 = cVar1;
      } while (cVar1 != '\0');
      memmove(pcVar4 + ((int)lVar8 + 2),*(void **)(param_1 + 0x130),
              (longlong)*(int *)(param_1 + 300));
      MD5_ProcessMessage((undefined8 *)pcVar4,*(int *)(param_1 + 300) + 1 + (int)lVar7,
                         (int *)local_158);
      iint_to_hexstr(local_158,0x10,(undefined2 *)pcVar4);
      uVar6 = (ulonglong)param_4;
      bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"CHAP_R",pcVar4);
      if ((int)CONCAT71(extraout_var_19,bVar2) == 0) {
        return 0;
      }
      if (((*(char **)(param_1 + 0x108) != (char *)0x0) && (**(char **)(param_1 + 0x108) != '\0'))
         && ((*(char **)(param_1 + 0x110) != (char *)0x0 && (**(char **)(param_1 + 0x110) != '\0')))
         ) {
        iscsiGetChallengeId(param_1);
        isprintf((char *)local_158,"%d",(ulonglong)*(byte *)(param_1 + 0x128),uVar6);
        bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"CHAP_I",local_158)
        ;
        if ((int)CONCAT71(extraout_var_20,bVar2) == 0) {
          return 0;
        }
        iint_to_hexstr(*(byte **)(param_1 + 0x130),*(int *)(param_1 + 300),(undefined2 *)pcVar4);
        bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"CHAP_C",pcVar4);
        if ((int)CONCAT71(extraout_var_21,bVar2) == 0) {
          return 0;
        }
      }
      *(byte *)((longlong)param_2 + 1) =
           ((*(char *)(param_1 + 0x68) << 2 ^ *(byte *)((longlong)param_2 + 1)) & 0xc ^
           *(byte *)((longlong)param_2 + 1)) & 0xfd | 0x81;
      return 1;
    }
    pcVar9 = "5";
    pcVar4 = "CHAP_A";
  }
  else {
    if (cVar1 != '\x01') {
      return 0;
    }
    *(undefined1 *)(param_1 + 0x68) = 1;
    *(byte *)((longlong)param_2 + 1) = *(byte *)((longlong)param_2 + 1) & 0xf7 | 4;
    *(undefined4 *)(param_1 + 0x6c) = 3;
    *(byte *)((longlong)param_2 + 1) = *(byte *)((longlong)param_2 + 1) | 0x83;
    if (*(int *)(param_1 + 100) == 1) {
      return 1;
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"HeaderDigest",&s_None)
    ;
    if ((int)CONCAT71(extraout_var_04,bVar2) == 0) {
      return 0;
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"DataDigest",&s_None);
    if ((int)CONCAT71(extraout_var_05,bVar2) == 0) {
      return 0;
    }
    pcVar9 = "No";
    pcVar4 = "No";
    if (*(int *)(param_1 + 0x40) != 0) {
      pcVar4 = "Yes";
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,&s_InitialR2T,pcVar4);
    if ((int)CONCAT71(extraout_var_06,bVar2) == 0) {
      return 0;
    }
    uVar6 = (ulonglong)param_4;
    if (*(int *)(param_1 + 0x3c) != 0) {
      pcVar9 = "Yes";
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"ImmediateData",pcVar9)
    ;
    if ((int)CONCAT71(extraout_var_07,bVar2) == 0) {
      return 0;
    }
    isprintf(local_148,"%lu",(ulonglong)*(uint *)(param_1 + 0x44),uVar6);
    uVar6 = (ulonglong)param_4;
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,
                         "MaxRecvDataSegmentLength",local_148);
    if ((int)CONCAT71(extraout_var_08,bVar2) == 0) {
      return 0;
    }
    isprintf(local_148,"%lu",(ulonglong)*(uint *)(param_1 + 0x50),uVar6);
    uVar6 = (ulonglong)param_4;
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"MaxBurstLength",
                         local_148);
    if ((int)CONCAT71(extraout_var_09,bVar2) == 0) {
      return 0;
    }
    isprintf(local_148,"%lu",(ulonglong)*(uint *)(param_1 + 0x4c),uVar6);
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"FirstBurstLength",
                         local_148);
    if ((int)CONCAT71(extraout_var_10,bVar2) == 0) {
      return 0;
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"MaxOutstandingR2T",
                         &s_1);
    if ((int)CONCAT71(extraout_var_11,bVar2) == 0) {
      return 0;
    }
    uVar6 = (ulonglong)param_4;
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"MaxConnections",&s_1);
    if ((int)CONCAT71(extraout_var_12,bVar2) == 0) {
      return 0;
    }
    isprintf(local_148,"%u",(ulonglong)*(uint *)(param_1 + 0x5c),uVar6);
    uVar6 = (ulonglong)param_4;
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"DefaultTime2Wait",
                         local_148);
    if ((int)CONCAT71(extraout_var_13,bVar2) == 0) {
      return 0;
    }
    isprintf(local_148,"%u",(ulonglong)*(uint *)(param_1 + 0x60),uVar6);
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"DefaultTime2Retain",
                         local_148);
    if ((int)CONCAT71(extraout_var_14,bVar2) == 0) {
      return 0;
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"ErrorRecoveryLevel",
                         &s_0);
    if ((int)CONCAT71(extraout_var_15,bVar2) == 0) {
      return 0;
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"DataPDUInOrder","Yes")
    ;
    if ((int)CONCAT71(extraout_var_16,bVar2) == 0) {
      return 0;
    }
    pcVar9 = "Yes";
    pcVar4 = "DataSequenceInOrder";
  }
  bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,pcVar4,pcVar9);
  if ((int)CONCAT71(extraout_var_17,bVar2) == 0) {
    return 0;
  }
  return 1;
}



===== iscsi_process_login_response @ 1400090ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 iscsi_process_login_response(byte *param_1,longlong param_2,char *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar8;
  ulonglong uVar7;
  byte bVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  char *pcVar13;
  char *pcVar14;
  bool bVar15;
  undefined1 auStackY_118 [32];
  char *local_e8;
  byte *local_e0;
  byte local_d8 [16];
  byte local_c8 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  *(ushort *)(param_1 + 0x24) =
       CONCAT11(*(undefined1 *)(param_2 + 0x24),*(undefined1 *)(param_2 + 0x25));
  if (*(byte *)(param_2 + 0x24) < 2) {
    if (*(char *)(param_2 + 3) != '\0') {
      param_1[0x24] = 5;
      param_1[0x25] = 2;
      return 3;
    }
    if (((char)*(byte *)(param_2 + 1) < '\0') && ((*(byte *)(param_2 + 1) & 3) <= param_1[0x68])) {
      param_1[0x24] = 0;
      param_1[0x25] = 3;
      return 8;
    }
    pcVar14 = param_3 + CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6))
                                 ,*(undefined1 *)(param_2 + 7));
    if (pcVar14 < param_3 + param_4) {
      *pcVar14 = '\0';
joined_r0x0001400091b3:
      do {
        pcVar13 = param_3;
        if ((pcVar13 == (char *)0x0) || (uVar7 = 0xffffffffffffffff, pcVar14 <= pcVar13)) {
LAB_140009958:
          *(ushort *)(param_1 + 0x7a) =
               *(short *)(param_2 + 0xe) << 8 | (ushort)*(byte *)(param_2 + 0xf);
          uVar5 = swap_dword(*(uint *)(param_2 + 0x1c));
          *(uint *)(param_1 + 0x30) = uVar5;
          uVar5 = swap_dword(*(uint *)(param_2 + 0x20));
          *(uint *)(param_1 + 0x34) = uVar5;
          if (*(char *)(param_2 + 0x24) == '\0') {
            uVar5 = swap_dword(*(uint *)(param_2 + 0x18));
            *(uint *)(param_1 + 0x38) = uVar5 + 1;
          }
          if ((char)*(byte *)(param_2 + 1) < '\0') {
            param_1[0x68] = *(byte *)(param_2 + 1) & 3;
          }
          uVar3 = 0;
          if (*(char *)(param_2 + 0x24) == '\x01') {
            uVar3 = 7;
          }
          return uVar3;
        }
        local_e0 = (byte *)0x0;
        local_e8 = (char *)0x0;
        do {
          if (*pcVar13 != '\0') break;
          pcVar13 = pcVar13 + 1;
        } while (pcVar13 < pcVar14);
        if (pcVar14 <= pcVar13) goto LAB_140009958;
        if (param_1[0x68] != 0) {
          param_3 = pcVar13;
          if (param_1[0x68] == 1) {
            uVar6 = iscsiFindKeyValue("TargetAlias",pcVar13,pcVar14,(longlong *)&local_e0,&local_e8)
            ;
            param_3 = local_e8;
            if ((int)uVar6 == 0) {
              uVar6 = iscsiFindKeyValue("TargetName",pcVar13,pcVar14,(longlong *)&local_e0,&local_e8
                                       );
              param_3 = local_e8;
              if ((int)uVar6 == 0) {
                uVar6 = iscsiFindKeyValue("TargetPortalGroupTag",pcVar13,pcVar14,
                                          (longlong *)&local_e0,&local_e8);
                if ((int)uVar6 == 0) {
                  uVar6 = iscsiFindKeyValue("InitialR2T",pcVar13,pcVar14,(longlong *)&local_e0,
                                            &local_e8);
                  if ((int)uVar6 == 0) {
                    uVar6 = iscsiFindKeyValue("ImmediateData",pcVar13,pcVar14,(longlong *)&local_e0,
                                              &local_e8);
                    if ((int)uVar6 == 0) {
                      uVar6 = iscsiFindKeyValue("MaxRecvDataSegmentLength",pcVar13,pcVar14,
                                                (longlong *)&local_e0,&local_e8);
                      if ((int)uVar6 == 0) {
                        uVar6 = iscsiFindKeyValue("FirstBurstLength",pcVar13,pcVar14,
                                                  (longlong *)&local_e0,&local_e8);
                        if ((int)uVar6 == 0) {
                          uVar6 = iscsiFindKeyValue("MaxBurstLength",pcVar13,pcVar14,
                                                    (longlong *)&local_e0,&local_e8);
                          if ((int)uVar6 == 0) {
                            uVar6 = iscsiFindKeyValue("HeaderDigest",pcVar13,pcVar14,
                                                      (longlong *)&local_e0,&local_e8);
                            if (((int)uVar6 != 0) ||
                               (uVar6 = iscsiFindKeyValue("DataDigest",pcVar13,pcVar14,
                                                          (longlong *)&local_e0,&local_e8),
                               (int)uVar6 != 0)) {
                              pbVar11 = &s_None;
                              goto LAB_1400096fa;
                            }
                            uVar6 = iscsiFindKeyValue("DefaultTime2Wait",pcVar13,pcVar14,
                                                      (longlong *)&local_e0,&local_e8);
                            if ((int)uVar6 == 0) {
                              uVar6 = iscsiFindKeyValue("DefaultTime2Retain",pcVar13,pcVar14,
                                                        (longlong *)&local_e0,&local_e8);
                              if ((int)uVar6 == 0) {
                                uVar6 = iscsiFindKeyValue("DataPDUInOrder",pcVar13,pcVar14,
                                                          (longlong *)&local_e0,&local_e8);
                                if ((int)uVar6 == 0) {
                                  uVar6 = iscsiFindKeyValue("DataSequenceInOrder",pcVar13,pcVar14,
                                                            (longlong *)&local_e0,&local_e8);
                                  if ((int)uVar6 == 0) {
                                    uVar6 = iscsiFindKeyValue("MaxOutstandingR2T",pcVar13,pcVar14,
                                                              (longlong *)&local_e0,&local_e8);
                                    if (((int)uVar6 == 0) &&
                                       (uVar6 = iscsiFindKeyValue("MaxConnections",pcVar13,pcVar14,
                                                                  (longlong *)&local_e0,&local_e8),
                                       (int)uVar6 == 0)) {
                                      uVar6 = iscsiFindKeyValue("ErrorRecoveryLevel",pcVar13,pcVar14
                                                                ,(longlong *)&local_e0,&local_e8);
                                      if ((int)uVar6 == 0) {
                                        uVar6 = iscsiFindKeyValue("TargetAddress",pcVar13,pcVar14,
                                                                  (longlong *)&local_e0,&local_e8);
                                        if ((int)uVar6 == 0) {
                                          return 4;
                                        }
                                        pbVar11 = local_e0;
                                        do {
                                          bVar1 = *pbVar11;
                                          pbVar11[(longlong)(local_c8 + -(longlong)local_e0)] =
                                               bVar1;
                                          pbVar11 = pbVar11 + 1;
                                        } while (bVar1 != 0);
                                        goto LAB_14000992b;
                                      }
                                      iVar2 = istrtol(local_e0,0);
                                      goto LAB_1400097d4;
                                    }
                                    iVar2 = istrtol(local_e0,0);
                                    bVar15 = iVar2 == 1;
                                    goto LAB_1400097d6;
                                  }
                                  if (local_e0 == (byte *)0x0) {
LAB_14000955a:
                                    uVar3 = 0;
                                  }
                                  else {
                                    iVar2 = istrcmp((char *)local_e0,"Yes");
                                    uVar3 = 1;
                                    if (iVar2 != 0) goto LAB_14000955a;
                                  }
                                  *(undefined4 *)(param_1 + 0x58) = uVar3;
                                  param_3 = local_e8;
                                }
                                else {
                                  if (local_e0 == (byte *)0x0) {
LAB_14000950b:
                                    uVar3 = 0;
                                  }
                                  else {
                                    iVar2 = istrcmp((char *)local_e0,"Yes");
                                    uVar3 = 1;
                                    if (iVar2 != 0) goto LAB_14000950b;
                                  }
                                  *(undefined4 *)(param_1 + 0x54) = uVar3;
                                  param_3 = local_e8;
                                }
                              }
                              else {
                                iVar2 = istrtol(local_e0,0);
                                *(int *)(param_1 + 0x60) = iVar2;
                                param_3 = local_e8;
                              }
                            }
                            else {
                              iVar2 = istrtol(local_e0,0);
                              *(int *)(param_1 + 0x5c) = iVar2;
                              param_3 = local_e8;
                            }
                          }
                          else {
                            iVar2 = istrtol(local_e0,0);
                            *(int *)(param_1 + 0x50) = iVar2;
                            param_3 = local_e8;
                          }
                        }
                        else {
                          iVar2 = istrtol(local_e0,0);
                          *(int *)(param_1 + 0x4c) = iVar2;
                          param_3 = local_e8;
                        }
                      }
                      else {
                        iVar2 = istrtol(local_e0,0);
                        *(int *)(param_1 + 0x48) = iVar2;
                        param_3 = local_e8;
                      }
                    }
                    else {
                      if ((*(int *)(param_1 + 0x3c) == 0) || (local_e0 == (byte *)0x0)) {
LAB_140009334:
                        uVar3 = 0;
                      }
                      else {
                        iVar2 = istrcmp((char *)local_e0,"Yes");
                        uVar3 = 1;
                        if (iVar2 != 0) goto LAB_140009334;
                      }
                      *(undefined4 *)(param_1 + 0x3c) = uVar3;
                      param_3 = local_e8;
                    }
                  }
                  else {
                    param_3 = local_e8;
                    if ((*(int *)(param_1 + 0x40) == 0) &&
                       (param_3 = local_e8, local_e0 != (byte *)0x0)) {
                      iVar2 = istrcmp((char *)local_e0,"Yes");
                      param_3 = local_e8;
                      if (iVar2 == 0) {
                        param_1[0x40] = 1;
                        param_1[0x41] = 0;
                        param_1[0x42] = 0;
                        param_1[0x43] = 0;
                        param_3 = local_e8;
                      }
                    }
                  }
                }
                else {
                  iVar2 = istrtol(local_e0,0);
                  *(int *)(param_1 + 0x70) = iVar2;
                  param_3 = local_e8;
                }
              }
            }
          }
          goto joined_r0x0001400091b3;
        }
        uVar6 = iscsiFindKeyValue("AuthMethod",pcVar13,pcVar14,(longlong *)&local_e0,&local_e8);
        if ((int)uVar6 == 0) {
          uVar6 = iscsiFindKeyValue("CHAP_A",pcVar13,pcVar14,(longlong *)&local_e0,&local_e8);
          if ((int)uVar6 == 0) {
            uVar6 = iscsiFindKeyValue("CHAP_I",pcVar13,pcVar14,(longlong *)&local_e0,&local_e8);
            if ((int)uVar6 != 0) {
              iVar2 = istrtol(local_e0,0);
              param_1[0x128] = (byte)iVar2;
              param_3 = local_e8;
              goto joined_r0x0001400091b3;
            }
            uVar6 = iscsiFindKeyValue("CHAP_C",pcVar13,pcVar14,(longlong *)&local_e0,&local_e8);
            pbVar11 = local_e0;
            if ((int)uVar6 != 0) {
              ihexstr_to_int((char *)local_e0,*(longlong *)(param_1 + 0x130));
              do {
                uVar8 = uVar7;
                uVar7 = uVar8 + 1;
              } while (pbVar11[uVar7] != 0);
              *(int *)(param_1 + 300) = (int)(uVar8 >> 1);
              param_3 = local_e8;
              goto joined_r0x0001400091b3;
            }
            uVar6 = iscsiFindKeyValue("CHAP_N",pcVar13,pcVar14,(longlong *)&local_e0,&local_e8);
            if ((int)uVar6 == 0) {
              uVar6 = iscsiFindKeyValue("CHAP_R",pcVar13,pcVar14,(longlong *)&local_e0,&local_e8);
              if ((int)uVar6 == 0) {
                uVar6 = iscsiFindKeyValue("TargetAddress",pcVar13,pcVar14,(longlong *)&local_e0,
                                          &local_e8);
                if ((int)uVar6 == 0) {
                  do {
                    uVar7 = uVar7 + 1;
                  } while (pcVar13[uVar7] != '\0');
                  param_3 = pcVar13 + uVar7;
                }
                else {
                  pbVar11 = local_e0;
                  do {
                    bVar1 = *pbVar11;
                    pbVar11[(longlong)(local_c8 + -(longlong)local_e0)] = bVar1;
                    pbVar11 = pbVar11 + 1;
                  } while (bVar1 != 0);
LAB_14000992b:
                  iscsiExtractRedirectInfo(param_1,local_c8);
                  param_3 = local_e8;
                }
              }
              else {
                pbVar11 = *(byte **)(param_1 + 0x160);
                *pbVar11 = param_1[0x128];
                pbVar10 = *(byte **)(param_1 + 0x110);
                pbVar12 = pbVar11;
                do {
                  pbVar12 = pbVar12 + 1;
                  bVar1 = *pbVar10;
                  pbVar10 = pbVar10 + 1;
                  *pbVar12 = bVar1;
                } while (bVar1 != 0);
                do {
                  uVar8 = uVar7;
                  uVar7 = uVar8 + 1;
                } while (*(char *)(*(longlong *)(param_1 + 0x110) + uVar7) != '\0');
                memmove(pbVar11 + ((int)uVar8 + 2),*(void **)(param_1 + 0x130),
                        (longlong)*(int *)(param_1 + 300));
                MD5_ProcessMessage((undefined8 *)pbVar11,*(int *)(param_1 + 300) + 1 + (int)uVar7,
                                   (int *)local_d8);
                iint_to_hexstr(local_d8,0x10,(undefined2 *)pbVar11);
                pbVar11 = pbVar11 + 2;
                pbVar10 = local_e0;
                if ((*local_e0 == 0x30) && ((local_e0[1] + 0xa8 & 0xdf) == 0)) {
                  pbVar10 = local_e0 + 2;
                }
                while( true ) {
                  bVar1 = *pbVar10;
                  param_3 = local_e8;
                  if (bVar1 == 0) break;
                  bVar9 = bVar1 + 0x20;
                  if (0x19 < (byte)(bVar1 + 0xbf)) {
                    bVar9 = bVar1;
                  }
                  if ((uint)*pbVar11 != (int)(char)bVar9) {
                    return 4;
                  }
                  pbVar11 = pbVar11 + 1;
                  pbVar10 = pbVar10 + 1;
                }
              }
              goto joined_r0x0001400091b3;
            }
            pbVar10 = *(byte **)(param_1 + 0x108);
            pbVar11 = local_e0;
          }
          else {
            pbVar11 = &s_5;
LAB_1400096fa:
            pbVar10 = local_e0;
          }
        }
        else {
          pbVar11 = local_e0;
          do {
            bVar1 = *pbVar11;
            pbVar11[(longlong)(local_c8 + -(longlong)local_e0)] = bVar1;
            pbVar11 = pbVar11 + 1;
          } while (bVar1 != 0);
          itolowerstr((char *)local_c8);
          iVar2 = *(int *)(param_1 + 0x10);
          if (iVar2 == 1) {
            iVar4 = istrcmp((char *)local_c8,"chap");
            param_3 = local_e8;
            if (iVar4 == 0) goto joined_r0x0001400091b3;
          }
          if (iVar2 != 0) {
            return 4;
          }
          pbVar10 = local_c8;
          pbVar11 = &s_none;
        }
        iVar2 = istrcmp((char *)pbVar10,(char *)pbVar11);
LAB_1400097d4:
        bVar15 = iVar2 == 0;
LAB_1400097d6:
        param_3 = local_e8;
        if (!bVar15) {
          return 4;
        }
      } while( true );
    }
  }
  return 2;
}



===== isprintf @ 1400099e4 =====

void isprintf(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  _isprintf(param_1,param_2,(uint *)&local_res18);
  return;
}



===== isscanf @ 140009a08 =====

void isscanf(byte *param_1,byte *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  _isscanf(param_1,param_2,&local_res18);
  return;
}



===== istrcmp @ 140009a2c =====

int istrcmp(char *param_1,char *param_2)

{
  char cVar1;
  
  if (param_1 == (char *)0x0) {
    return -(uint)(param_2 != (char *)0x0);
  }
  if (param_2 == (char *)0x0) {
    return 1;
  }
  cVar1 = *param_1;
  while( true ) {
    if ((int)cVar1 - (int)*param_2 != 0) {
      return (int)cVar1 - (int)*param_2;
    }
    param_1 = param_1 + 1;
    if (cVar1 == '\0') break;
    cVar1 = *param_1;
    param_2 = param_2 + 1;
  }
  return 0;
}



===== istrlen @ 140009a68 =====

int istrlen(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
    cVar1 = *param_1;
  }
  return iVar2;
}



===== istrtol @ 140009a7c =====

int istrtol(byte *param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char cVar4;
  byte bVar5;
  byte *pbVar6;
  int iVar7;
  
  bVar1 = false;
  do {
    pbVar6 = param_1;
    bVar5 = *pbVar6;
    param_1 = pbVar6 + 1;
  } while (bVar5 == 0x20);
  if (bVar5 == 0x2d) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (bVar5 != 0x2b) goto LAB_140009aad;
  }
  bVar1 = bVar2;
  bVar5 = *param_1;
  param_1 = pbVar6 + 2;
LAB_140009aad:
  if ((((param_2 & 0xffffffef) == 0) && (bVar5 == 0x30)) && ((*param_1 + 0xa8 & 0xdf) == 0)) {
    bVar5 = param_1[1];
    param_2 = 0x10;
    param_1 = param_1 + 2;
  }
  if ((param_2 == 0) && (param_2 = 10, bVar5 == 0x30)) {
    param_2 = 8;
  }
  iVar7 = 0;
  while (-1 < (char)bVar5) {
    if (bVar5 - 0x30 < 10) {
      bVar5 = bVar5 - 0x30;
    }
    else {
      if ((5 < (byte)(bVar5 + 0xbf)) && (5 < (byte)(bVar5 + 0x9f))) break;
      cVar4 = '7';
      if (0x19 < (byte)(bVar5 + 0xbf)) {
        cVar4 = 'W';
      }
      bVar5 = bVar5 - cVar4;
    }
    if ((int)param_2 <= (int)(uint)bVar5) break;
    iVar7 = iVar7 * param_2 + (uint)bVar5;
    bVar5 = *param_1;
    param_1 = param_1 + 1;
  }
  iVar3 = -iVar7;
  if (!bVar1) {
    iVar3 = iVar7;
  }
  return iVar3;
}



===== itolowerstr @ 140009b4c =====

void itolowerstr(char *param_1)

{
  char cVar1;
  char cVar2;
  
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    cVar1 = cVar2 + ' ';
    if (0x19 < (byte)(cVar2 + 0xbfU)) {
      cVar1 = cVar2;
    }
    *param_1 = cVar1;
    param_1 = param_1 + 1;
    cVar2 = *param_1;
  }
  return;
}



===== udp_cksum @ 140009b78 =====

ushort udp_cksum(byte *param_1)

{
  uint uVar1;
  byte *pbVar2;
  ulonglong uVar3;
  longlong lVar4;
  ushort uVar5;
  byte *pbVar6;
  int iVar7;
  
  iVar7 = 0;
  pbVar6 = param_1 + (ulonglong)(*param_1 & 0xf) * 4;
  lVar4 = 4;
  uVar5 = *(short *)(pbVar6 + 4) << 8 | (ushort)pbVar6[5];
  pbVar2 = param_1 + 0xc;
  do {
    iVar7 = iVar7 + ((uint)(ushort)(*(short *)pbVar2 << 8) | (uint)pbVar2[1]);
    lVar4 = lVar4 + -1;
    pbVar2 = pbVar2 + 2;
  } while (lVar4 != 0);
  uVar1 = (uint)uVar5 + iVar7 + (uint)param_1[9];
  uVar1 = (uVar1 >> 0x10) + (uVar1 & 0xffff);
  uVar1 = uVar1 + (uVar1 >> 0x10);
  if ((pbVar6[5] & 1) != 0) {
    uVar3 = (ulonglong)uVar5;
    uVar5 = uVar5 + 1;
    pbVar6[uVar3] = 0;
  }
  if (uVar5 >> 1 != 0) {
    uVar3 = (ulonglong)(uint)(uVar5 >> 1);
    do {
      uVar1 = uVar1 + ((uint)(ushort)(*(short *)pbVar6 << 8) | (uint)pbVar6[1]);
      uVar3 = uVar3 - 1;
      pbVar6 = pbVar6 + 2;
    } while (uVar3 != 0);
  }
  iVar7 = (uVar1 >> 0x10) + (uVar1 & 0xffff);
  return ~((short)((uint)iVar7 >> 0x10) + (short)iVar7);
}



===== mem_free @ 140009c4c =====

void mem_free(undefined *param_1)

{
  uint *puVar1;
  
  if (param_1 != (undefined *)0x0) {
    if ((param_1 < &DAT_14005e5f0) || (DAT_14005e5e0 <= param_1)) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("mem_free: legal memory");
    }
    if (((undefined *)((longlong)&DAT_14005e5e8 + 7U) < param_1) && (param_1 < DAT_14005e5e0)) {
      puVar1 = (uint *)(param_1 + -0xc);
      if (param_1[-4] == '\0') {
                    /* WARNING: Subroutine does not return */
        DbgPrint("mem_free: mem->used");
      }
      param_1[-4] = 0;
      if (puVar1 < DAT_14005e5e8) {
        DAT_14005e5e8 = puVar1;
      }
      plug_holes(puVar1);
    }
  }
  return;
}



===== mem_init @ 140009ce0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_init(void)

{
  memset(&DAT_14005e5f9,0,0xfff6);
  _DAT_14005e5f4 = 0;
  DAT_14005e5e0 = &DAT_14006e5ef;
  _DAT_14005e5f0 = 0xffff;
  DAT_14005e5e8 = &DAT_14005e5f0;
  DAT_14005e5f8 = 0;
  DAT_14006e5f7 = 1;
  _DAT_14006e5ef = 0xffff;
  _DAT_14006e5f3 = 0xffff;
  DAT_14005e5d3 = 1;
  return;
}



===== mem_malloc @ 140009d4c =====

longlong mem_malloc(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  
  puVar3 = DAT_14005e5e8;
  if (param_1 - 1 < 0xffff) {
    uVar4 = (int)DAT_14005e5e8 + 0xbffa1a10;
    while (uVar4 < 0xffff) {
      uVar5 = (ulonglong)uVar4;
      puVar1 = (uint *)(&DAT_14005e5f0 + uVar5);
      if (((&DAT_14005e5f8)[uVar5] == '\0') && ((ulonglong)param_1 + 0xc <= (*puVar1 - uVar5) - 0xc)
         ) {
        uVar6 = param_1 + 0xc + uVar4;
        puVar2 = (uint *)(&DAT_14005e5f0 + uVar6);
        *(uint *)(&DAT_14005e5f4 + uVar6) = uVar4;
        *puVar2 = *puVar1;
        *puVar1 = uVar6;
        if (*puVar2 != 0xffff) {
          *(uint *)(&DAT_14005e5f4 + *puVar2) = uVar6;
        }
        (&DAT_14005e5f8)[uVar6] = 0;
        (&DAT_14005e5f8)[uVar5] = 1;
        if ((puVar1 != puVar3) || ((char)puVar3[2] == '\0')) goto LAB_140009e36;
        goto LAB_140009e06;
      }
      uVar4 = *puVar1;
    }
  }
  return 0;
  while (uVar4 = *puVar3, puVar3 = (uint *)(&DAT_14005e5f0 + uVar4), (&DAT_14005e5f8)[uVar4] != '\0'
        ) {
LAB_140009e06:
    if (puVar3 == DAT_14005e5e0) break;
  }
  DAT_14005e5e8 = puVar3;
  if ((char)puVar3[2] != '\0') {
                    /* WARNING: Subroutine does not return */
    DbgPrint("mem_malloc: !lfree->used");
  }
LAB_140009e36:
  if (DAT_14005e5e0 < (uint *)((ulonglong)param_1 + 0xc + (longlong)puVar1)) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("mem_malloc: allocated memory not above ram_end.");
  }
  return uVar5 + 0x14005e5fc;
}



===== mem_realloc @ 140009e5c =====

undefined * mem_realloc(undefined *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 < 0x10000) {
    if ((param_1 < &DAT_14005e5f0) || (DAT_14005e5e0 <= param_1)) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("mem_realloc: legal memory");
    }
    if (((undefined *)((longlong)&DAT_14005e5e8 + 7U) < param_1) && (param_1 < DAT_14005e5e0)) {
      puVar1 = (uint *)(param_1 + -0xc);
      iVar3 = (int)puVar1 + -0x4005e5f0;
      if ((ulonglong)param_2 + 0x18 < (ulonglong)((*puVar1 - iVar3) - 0xc)) {
        uVar4 = param_2 + 0xc + iVar3;
        puVar2 = (uint *)(&DAT_14005e5f0 + uVar4);
        (&DAT_14005e5f8)[uVar4] = 0;
        *puVar2 = *puVar1;
        *(int *)(&DAT_14005e5f4 + uVar4) = iVar3;
        *puVar1 = uVar4;
        if (*puVar2 != 0xffff) {
          *(uint *)(&DAT_14005e5f4 + *puVar2) = uVar4;
        }
        plug_holes(puVar2);
      }
    }
  }
  else {
    param_1 = (undefined *)0x0;
  }
  return param_1;
}



===== memp_free @ 140009f18 =====

void memp_free(int param_1,longlong param_2)

{
  if (param_2 != 0) {
    *(undefined8 *)(param_2 + -8) = (&DAT_14006e600)[param_1];
    (&DAT_14006e600)[param_1] = (undefined8 *)(param_2 + -8);
  }
  return;
}



===== memp_init @ 140009f38 =====

void memp_init(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  
  puVar6 = &DAT_14006e660;
  puVar3 = &DAT_14006e600;
  lVar4 = 0;
  lVar8 = 0xb;
  do {
    uVar1 = *(ushort *)((longlong)&DAT_14001a1b8 + lVar4);
    *puVar3 = 0;
    if (uVar1 != 0) {
      uVar2 = *(ushort *)((longlong)&DAT_14001a1a0 + lVar4);
      uVar9 = (ulonglong)uVar1;
      puVar5 = (undefined8 *)0x0;
      do {
        puVar7 = puVar6;
        *puVar7 = puVar5;
        puVar6 = (undefined8 *)((longlong)puVar7 + (ulonglong)uVar2 + 8);
        uVar9 = uVar9 - 1;
        puVar5 = puVar7;
      } while (uVar9 != 0);
      *puVar3 = puVar7;
    }
    lVar4 = lVar4 + 2;
    puVar3 = puVar3 + 1;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  DAT_14005e5d4 = 1;
  return;
}



===== memp_malloc @ 140009fcc =====

undefined8 * memp_malloc(int param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  if (10 < param_1) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("memp_malloc: type < MEMP_MAX");
  }
  puVar3 = (undefined8 *)0x0;
  puVar1 = (undefined8 *)(&DAT_14006e600)[param_1];
  if (puVar1 != (undefined8 *)0x0) {
    uVar2 = *puVar1;
    *puVar1 = 0;
    puVar3 = puVar1 + 1;
    (&DAT_14006e600)[param_1] = uVar2;
  }
  return puVar3;
}



===== pbuf_alloc @ 14000a010 =====

undefined8 * pbuf_alloc(int param_1,ushort param_2,int param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined2 uVar3;
  char *pcVar4;
  undefined8 *puVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  
  puVar2 = DAT_14005e5d8;
  uVar7 = (uint)param_2;
  uVar6 = 0;
  if (param_1 == 0) {
    uVar6 = 0x14;
LAB_14000a060:
    uVar6 = uVar6 + 0x28;
LAB_14000a064:
    uVar6 = uVar6 + 0xe;
  }
  else {
    if (param_1 == 1) goto LAB_14000a060;
    if (param_1 == 2) goto LAB_14000a064;
    if (param_1 != 3) {
      pcVar4 = "pbuf_alloc: bad pbuf layer";
      goto LAB_14000a04e;
    }
  }
  if (param_3 == 0) {
    puVar2 = (undefined8 *)mem_malloc((uint)uVar6 + uVar7 + 0x18);
    if (puVar2 == (undefined8 *)0x0) {
      return (undefined8 *)0x0;
    }
    *(ushort *)(puVar2 + 2) = param_2;
    puVar2[1] = (longlong)puVar2 + (ulonglong)uVar6 + 0x18;
    *(ushort *)((longlong)puVar2 + 0x12) = param_2;
    *puVar2 = 0;
    *(undefined2 *)((longlong)puVar2 + 0x14) = 0;
    goto LAB_14000a213;
  }
  if (0 < param_3) {
    if (param_3 < 3) {
      puVar2 = memp_malloc(0);
      if (puVar2 == (undefined8 *)0x0) {
        return (undefined8 *)0x0;
      }
      puVar2[1] = 0;
      uVar3 = 4;
      *(ushort *)(puVar2 + 2) = param_2;
      if (param_3 == 1) {
        uVar3 = 1;
      }
      *(ushort *)((longlong)puVar2 + 0x12) = param_2;
      *(undefined2 *)((longlong)puVar2 + 0x14) = uVar3;
      *puVar2 = 0;
LAB_14000a213:
      *(undefined2 *)((longlong)puVar2 + 0x16) = 1;
      return puVar2;
    }
    if (param_3 == 3) {
      if (DAT_14005e5d0 != '\0') {
        return (undefined8 *)0x0;
      }
      if (DAT_14005e5d8 != (undefined8 *)0x0) {
        DAT_14005e5d8 = (undefined8 *)*DAT_14005e5d8;
      }
      DAT_14005e5d1 = 0;
      if (puVar2 == (undefined8 *)0x0) {
        DAT_14005e5d1 = 0;
        return (undefined8 *)0x0;
      }
      *(ushort *)(puVar2 + 2) = param_2;
      puVar2[1] = (longlong)puVar2 + (ulonglong)uVar6 + 0x18;
      *puVar2 = 0;
      *(undefined2 *)((longlong)puVar2 + 0x16) = 1;
      if ((int)(0x600 - (uint)uVar6) < (int)(uint)param_2) {
        uVar7 = (uint)(ushort)(0x600 - uVar6);
      }
      *(short *)((longlong)puVar2 + 0x12) = (short)uVar7;
      puVar5 = puVar2;
      for (iVar8 = param_2 - uVar7; puVar1 = DAT_14005e5d8, 0 < iVar8; iVar8 = iVar8 - (uint)uVar6)
      {
        if (DAT_14005e5d0 != '\0') {
LAB_14000a18f:
          pbuf_free(puVar2);
          return (undefined8 *)0x0;
        }
        if (DAT_14005e5d8 != (undefined8 *)0x0) {
          DAT_14005e5d8 = (undefined8 *)*DAT_14005e5d8;
        }
        DAT_14005e5d1 = 0;
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000a18f;
        uVar6 = (ushort)iVar8;
        *puVar1 = 0;
        *puVar5 = puVar1;
        *(ushort *)(puVar1 + 2) = uVar6;
        if (0x600 < iVar8) {
          uVar6 = 0x600;
        }
        *(undefined2 *)((longlong)puVar1 + 0x16) = 1;
        *(ushort *)((longlong)puVar1 + 0x12) = uVar6;
        puVar1[1] = puVar1 + 3;
        puVar5 = puVar1;
      }
      goto LAB_14000a213;
    }
  }
  pcVar4 = "pbuf_alloc: erroneous flag";
LAB_14000a04e:
                    /* WARNING: Subroutine does not return */
  DbgPrint(pcVar4);
}



===== pbuf_cat @ 14000a238 =====

void pbuf_cat(longlong *param_1,longlong param_2)

{
  if (param_1 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("h != NULL (programmer violates API)");
  }
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("t != NULL (programmer violates API)");
  }
  if ((param_1 != (longlong *)0x0) && (param_2 != 0)) {
    for (; *param_1 != 0; param_1 = (longlong *)*param_1) {
      *(short *)(param_1 + 2) = (short)param_1[2] + *(short *)(param_2 + 0x10);
    }
    if ((short)param_1[2] != *(short *)((longlong)param_1 + 0x12)) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("p->tot_len == p->len (of last pbuf in chain)");
    }
    if (*param_1 != 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("p->next == NULL");
    }
    *(short *)(param_1 + 2) = (short)param_1[2] + *(short *)(param_2 + 0x10);
    *param_1 = param_2;
  }
  return;
}



===== pbuf_clen @ 14000a2cc =====

char pbuf_clen(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = '\0';
  for (; param_1 != (undefined8 *)0x0; param_1 = (undefined8 *)*param_1) {
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}



===== pbuf_dequeue @ 14000a2dc =====

undefined8 pbuf_dequeue(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (param_1 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("p != NULL");
  }
  if (*(short *)(param_1 + 2) != *(short *)((longlong)param_1 + 0x12)) {
    do {
      if (*(ushort *)(param_1 + 2) <= *(ushort *)((longlong)param_1 + 0x12)) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("p->len < p->tot_len");
      }
      param_1 = (undefined8 *)*param_1;
      if (param_1 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("p->next != NULL");
      }
    } while (*(short *)(param_1 + 2) != *(short *)((longlong)param_1 + 0x12));
  }
  uVar1 = *param_1;
  *param_1 = 0;
  lwip_printk();
  return uVar1;
}



===== pbuf_free @ 14000a368 =====

char pbuf_free(undefined8 *param_1)

{
  short sVar1;
  undefined8 *puVar2;
  char cVar3;
  
  if (param_1 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("p != NULL");
  }
  if ((*(ushort *)((longlong)param_1 + 0x14) == 3) || (4 < *(ushort *)((longlong)param_1 + 0x14))) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("pbuf_free: sane flags");
  }
  cVar3 = '\0';
  do {
    if (*(short *)((longlong)param_1 + 0x16) == 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("pbuf_free: p->ref > 0");
    }
    sVar1 = *(short *)((longlong)param_1 + 0x16) + -1;
    *(short *)((longlong)param_1 + 0x16) = sVar1;
    if (sVar1 == 0) {
      sVar1 = *(short *)((longlong)param_1 + 0x14);
      puVar2 = (undefined8 *)*param_1;
      if (sVar1 == 2) {
        *(undefined4 *)(param_1 + 2) = 0x6000600;
        param_1[1] = param_1 + 3;
        *param_1 = DAT_14005e5d8;
        DAT_14005e5d8 = param_1;
      }
      else if ((sVar1 == 1) || (sVar1 == 4)) {
        param_1[-1] = DAT_14006e600;
        DAT_14006e600 = param_1 + -1;
      }
      else {
        mem_free((undefined *)param_1);
      }
      cVar3 = cVar3 + '\x01';
    }
    else {
      puVar2 = (undefined8 *)0x0;
    }
    param_1 = puVar2;
  } while (puVar2 != (undefined8 *)0x0);
  return cVar3;
}



===== pbuf_header @ 14000a470 =====

ulonglong pbuf_header(longlong param_1,short param_2)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("p != NULL");
  }
  if ((param_2 != 0) && (param_1 != 0)) {
    uVar1 = *(ushort *)(param_1 + 0x14);
    in_RAX = (ulonglong)uVar1;
    lVar2 = *(longlong *)(param_1 + 8);
    if ((uVar1 & 0xfffd) == 0) {
      in_RAX = param_1 + 0x18;
      uVar3 = lVar2 - param_2;
      *(ulonglong *)(param_1 + 8) = uVar3;
      if (uVar3 < in_RAX) {
        *(longlong *)(param_1 + 8) = lVar2;
LAB_14000a509:
        return CONCAT71((int7)(in_RAX >> 8),1);
      }
    }
    else if ((uVar1 == 4) || (uVar1 == 1)) {
      if ((-1 < param_2) ||
         (in_RAX = (ulonglong)*(ushort *)(param_1 + 0x12),
         0 < (int)((int)param_2 - (uint)*(ushort *)(param_1 + 0x12)))) goto LAB_14000a509;
      *(longlong *)(param_1 + 8) = lVar2 - param_2;
    }
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + param_2;
    *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + param_2;
  }
  return in_RAX & 0xffffffffffffff00;
}



===== pbuf_init @ 14000a510 =====

void pbuf_init(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  lVar3 = 0x80;
  DAT_14005e5d8 = &DAT_14002d9d0;
  puVar1 = &DAT_14002d9d0;
  do {
    puVar2 = puVar1;
    *(undefined4 *)(puVar2 + 2) = 0x6000600;
    puVar2[1] = puVar2 + 3;
    *(undefined2 *)((longlong)puVar2 + 0x14) = 2;
    *puVar2 = puVar2 + 0xc3;
    lVar3 = lVar3 + -1;
    puVar1 = puVar2 + 0xc3;
  } while (lVar3 != 0);
  DAT_14005e5d2 = 1;
  *puVar2 = 0;
  DAT_14005e5d1 = 0;
  DAT_14005e5d0 = 0;
  return;
}



===== pbuf_realloc @ 14000a56c =====

void pbuf_realloc(undefined8 *param_1,ushort param_2)

{
  ushort uVar1;
  short sVar2;
  
  if ((*(ushort *)((longlong)param_1 + 0x14) == 3) || (4 < *(ushort *)((longlong)param_1 + 0x14))) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("pbuf_realloc: sane p->flags");
  }
  if (param_2 < *(ushort *)(param_1 + 2)) {
    sVar2 = param_2 - *(ushort *)(param_1 + 2);
    uVar1 = *(ushort *)((longlong)param_1 + 0x12);
    while (uVar1 < param_2) {
      param_2 = param_2 - uVar1;
      *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + sVar2;
      uVar1 = *(ushort *)((longlong)*param_1 + 0x12);
      param_1 = (undefined8 *)*param_1;
    }
    if ((*(short *)((longlong)param_1 + 0x14) == 0) &&
       (param_2 != *(ushort *)((longlong)param_1 + 0x12))) {
      mem_realloc((undefined *)param_1,(*(int *)(param_1 + 1) - (int)param_1) + (uint)param_2);
    }
    *(ushort *)((longlong)param_1 + 0x12) = param_2;
    *(ushort *)(param_1 + 2) = param_2;
    if ((undefined8 *)*param_1 != (undefined8 *)0x0) {
      pbuf_free((undefined8 *)*param_1);
    }
    *param_1 = 0;
  }
  return;
}



===== pbuf_ref @ 14000a614 =====

void pbuf_ref(longlong param_1)

{
  if (param_1 != 0) {
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + 1;
  }
  return;
}



===== pbuf_take @ 14000a620 =====

longlong * pbuf_take(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  if (param_1 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("pbuf_take: p != NULL\n");
  }
  plVar2 = param_1;
  plVar3 = (longlong *)0x0;
  do {
    plVar1 = param_1;
    if (*(short *)((longlong)param_1 + 0x14) == 4) {
      if (*(ushort *)((longlong)param_1 + 0x12) < 0x601) {
        plVar1 = pbuf_alloc(3,*(ushort *)((longlong)param_1 + 0x12),3);
      }
      else {
        plVar1 = (longlong *)0x0;
      }
      if ((plVar1 == (longlong *)0x0) &&
         (plVar1 = pbuf_alloc(3,*(ushort *)((longlong)param_1 + 0x12),0), plVar1 == (longlong *)0x0)
         ) {
        pbuf_free(plVar2);
        return (longlong *)0x0;
      }
      *plVar1 = *param_1;
      *param_1 = 0;
      if (plVar3 == (longlong *)0x0) {
        plVar2 = plVar1;
      }
      else {
        if ((longlong *)*plVar3 != param_1) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("prev->next == p");
        }
        *plVar3 = (longlong)plVar1;
      }
      memmove((void *)plVar1[1],(void *)param_1[1],(ulonglong)*(ushort *)((longlong)param_1 + 0x12))
      ;
      *(short *)(plVar1 + 2) = (short)param_1[2];
      *(undefined2 *)((longlong)plVar1 + 0x12) = *(undefined2 *)((longlong)param_1 + 0x12);
      pbuf_free(param_1);
    }
    param_1 = (longlong *)*plVar1;
    plVar3 = plVar1;
    if (param_1 == (longlong *)0x0) {
      return plVar2;
    }
  } while( true );
}



===== plug_holes @ 14000a720 =====

void plug_holes(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  if (param_1 < &DAT_14005e5f0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("plug_holes: mem >= ram");
  }
  if (DAT_14005e5e0 <= param_1) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("plug_holes: mem < ram_end");
  }
  if ((char)param_1[2] != '\0') {
                    /* WARNING: Subroutine does not return */
    DbgPrint(&s_plug_holes__mem_>used____0);
  }
  if (0xffff < *param_1) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("plug_holes: mem->next <= MEM_SIZE");
  }
  puVar1 = (uint *)(&DAT_14005e5f0 + *param_1);
  puVar2 = DAT_14005e5e8;
  if (((param_1 != puVar1) && ((&DAT_14005e5f8)[*param_1] == '\0')) && (puVar1 != DAT_14005e5e0)) {
    *param_1 = *puVar1;
    if (DAT_14005e5e8 == puVar1) {
      puVar2 = param_1;
    }
    DAT_14005e5e8 = puVar2;
    *(int *)(&DAT_14005e5f4 + *puVar1) = (int)param_1 + -0x4005e5f0;
  }
  puVar1 = (uint *)(&DAT_14005e5f0 + param_1[1]);
  if ((puVar1 != param_1) && ((&DAT_14005e5f8)[param_1[1]] == '\0')) {
    *puVar1 = *param_1;
    DAT_14005e5e8 = puVar2;
    if (puVar2 == param_1) {
      DAT_14005e5e8 = puVar1;
    }
    *(int *)(&DAT_14005e5f4 + *param_1) = (int)puVar1 + -0x4005e5f0;
  }
  return;
}



===== stack_bringup @ 14000a800 =====

void stack_bringup(undefined8 *param_1)

{
  if (*(char *)(*(longlong *)
                 (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
               0x7d) == '\0') {
    stack_ipv4_init(param_1);
  }
  else {
    stack_ipv6_init(param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x000140018080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(param_1);
  return;
}



===== stack_close_connection @ 14000a844 =====

void stack_close_connection(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = get_network_stack();
                    /* WARNING: Could not recover jumptable at 0x000140018080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 0x20))(param_1);
  return;
}



===== stack_flush_tcp_data @ 14000a868 =====

void stack_flush_tcp_data(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = get_network_stack();
                    /* WARNING: Could not recover jumptable at 0x000140018080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 0x30))(param_1);
  return;
}



===== stack_poll_device @ 14000a88c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void stack_poll_device(void)

{
  (*(code *)l2_driver_intf[8])(*l2_driver_intf,1);
  return;
}



===== stack_rx_packet @ 14000a8a8 =====

void stack_rx_packet(undefined8 param_1,undefined8 param_2,undefined2 param_3)

{
  longlong lVar1;
  
  lVar1 = get_network_stack();
                    /* WARNING: Could not recover jumptable at 0x000140018080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 0x10))(param_1,param_2,param_3);
  return;
}



===== stack_set_addr @ 14000a8ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void stack_set_addr(longlong param_1)

{
  (**(code **)(param_1 + 8))();
  return;
}



===== stack_setup_connection @ 14000a900 =====

void stack_setup_connection(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = get_network_stack();
                    /* WARNING: Could not recover jumptable at 0x000140018080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 0x18))(param_1,param_2,param_3);
  return;
}



===== stack_shutdown @ 14000a940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void stack_shutdown(longlong param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(param_1 + 0x138);
  iscsiDelTimer(*(undefined2 **)(param_1 + 0x128));
  iscsiDelTimer(*(undefined2 **)(param_1 + 0x130));
  netif_set_down((longlong)puVar1);
  (**(code **)(l2_driver_intf + 0x60))(puVar1);
  netif_remove(puVar1);
  mm_free_all_resources();
  return;
}



===== stack_write_tcp_data @ 14000a9ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void stack_write_tcp_data
               (undefined8 param_1,undefined8 param_2,undefined2 param_3,undefined1 param_4)

{
  longlong lVar1;
  
  lVar1 = get_network_stack();
  (**(code **)(lVar1 + 0x28))(param_1,param_2,param_3,param_4);
  return;
}



===== e4_ethernetif_bringup @ 14000aa00 =====

ulonglong e4_ethernetif_bringup(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  lm_set_rx_mask(lVar1,0xf);
  uVar2 = lm_enable_intr(lVar1);
  return uVar2 & 0xffffffffffffff00;
}



===== e4_ethernetif_init @ 14000aa30 =====

/* WARNING: Removing unreachable block (ram,0x00014000aac5) */

undefined8 e4_ethernetif_init(longlong param_1)

{
  uint *puVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  puVar1 = *(uint **)(param_1 + 0x28);
  uVar4 = lm_get_dev_id((longlong)puVar1);
  if (((int)uVar4 != 0) || (uVar5 = lm_get_dev_info(puVar1), (int)uVar5 != 0)) {
    pcVar2 = (code *)swi(3);
    uVar4 = (*pcVar2)();
    return uVar4;
  }
  if ((char)puVar1[0x1c1d] != (char)uVar5) {
    lm_pci_cfg_map_db_regs((longlong)puVar1);
  }
  iVar3 = lm_init_resc((longlong)puVar1);
  if (iVar3 == 0) {
    uVar5 = lm_chip_init((longlong)puVar1);
    if (((int)uVar5 == 0) && (iVar3 = lm_mcp_cfg_link((longlong)puVar1,1), iVar3 == 0)) {
      lm_mcp_ov_update_drv_state((longlong)puVar1,2);
      *(undefined2 *)(param_1 + 0x3b) = 0x3465;
      *(code **)(param_1 + 0x18) = e4_protocol_transmit;
      *(code **)(param_1 + 0x20) = e4_transmit;
      return 0x14000ab00;
    }
  }
  pcVar2 = (code *)swi(3);
  uVar4 = (*pcVar2)();
  return uVar4;
}



===== e4_ethernetif_shutdown @ 14000aae0 =====

ulonglong e4_ethernetif_shutdown(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  lm_disable_intr(lVar1);
  uVar2 = lm_shutdown(lVar1);
  return uVar2 & 0xffffffffffffff00;
}



===== e4_protocol_transmit @ 14000ab10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong e4_protocol_transmit(longlong param_1,longlong *param_2,uint *param_3)

{
  undefined2 *puVar1;
  u_short uVar2;
  ulonglong uVar3;
  
  if ((*(byte *)(param_1 + 0x3a) & 0x20) == 0) {
    uVar3 = etharp_output(param_1,param_3,param_2);
    return uVar3;
  }
  uVar3 = pbuf_header((longlong)param_2,0xe);
  if ((char)uVar3 == '\0') {
    if ((char)*param_3 == -1) {
      puVar1 = (undefined2 *)param_2[1];
      uVar2 = ntohs(0x86dd);
      puVar1[6] = uVar2;
      *puVar1 = 0x3333;
      *(undefined1 *)(puVar1 + 1) = 0xff;
      *(undefined1 *)((longlong)puVar1 + 3) = *(undefined1 *)((longlong)param_3 + 0xd);
      *(undefined1 *)(puVar1 + 2) = *(undefined1 *)((longlong)param_3 + 0xe);
      *(undefined1 *)((longlong)puVar1 + 5) = *(undefined1 *)((longlong)param_3 + 0xf);
      memmove(puVar1 + 3,(void *)(param_1 + 0x31),(ulonglong)*(byte *)(param_1 + 0x30));
      uVar3 = (**(code **)(param_1 + 0x20))(param_1,param_2);
    }
    else {
      uVar3 = ethnd_query(param_1,param_3,param_2);
    }
  }
  else {
    uVar3 = CONCAT71((int7)(uVar3 >> 8),0xfe);
  }
  return uVar3;
}



===== e4_transmit @ 14000ab30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong e4_transmit(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = (**(code **)(l2_driver_intf + 0x20))(*(undefined8 *)(param_1 + 0x28));
  return uVar1 & 0xffffffffffffff00;
}



===== nx4_get_netif_intf @ 14000ab50 =====

void nx4_get_netif_intf(longlong param_1)

{
  *(code **)(param_1 + 0x50) = e4_ethernetif_init;
  *(code **)(param_1 + 0x60) = e4_ethernetif_shutdown;
  *(code **)(param_1 + 0x58) = e4_ethernetif_bringup;
  return;
}



===== __security_check_cookie @ 14000ab90 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __report_gsfailure @ 14000abb0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== __report_rangecheckfailure @ 14000abe0 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  __report_securityfailure(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __report_securityfailure @ 14000abf0 =====

void __report_securityfailure(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,param_1,__security_cookie,__security_cookie_complement,1);
}



===== StorPortInitialize @ 14000ac20 =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ac20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortGetPhysicalAddress @ 14000ac26 =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ac26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortGetUncachedExtension @ 14000ac2c =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ac2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortNotification @ 14000ac32 =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ac32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== StorPortCompleteRequest @ 14000ac38 =====

void StorPortCompleteRequest(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ac38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortCompleteRequest();
  return;
}



===== StorPortStallExecution @ 14000ac3e =====

void StorPortStallExecution(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000ac3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== __GSHandlerCheck @ 14000ac44 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000ac64 =====

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



===== StorPortGetBusData @ 14000acd0 =====

void StorPortGetBusData(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000acd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetBusData();
  return;
}



===== StorPortExtendedFunction @ 14000acd6 =====

void StorPortExtendedFunction(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000acd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortExtendedFunction();
  return;
}



===== memcmp @ 14000acf0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14000ad33;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14000ada4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14000ada0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000ada4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000ad9c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000ada0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000ad9c;
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
LAB_14000ada4:
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
LAB_14000ad33:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== strncmp @ 14000adb7 =====

int __cdecl strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000adb7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strncmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== DbgPrint @ 14000adbd =====

void DbgPrint(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000adbd. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  DbgPrint();
  return;
}



===== HalSetBusDataByOffset @ 14000adc3 =====

void HalSetBusDataByOffset(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000adc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HalSetBusDataByOffset();
  return;
}



===== elite_cdu_init_common @ 14000adcc =====

void elite_cdu_init_common(longlong param_1)

{
  uint uVar1;
  
  uVar1 = 1 << ((char)*(undefined4 *)(param_1 + 0x238) + 0xcU & 0x1f);
  elite_init_store_rt_reg(param_1,0x9a,uVar1 % 0x270 << 0xc | uVar1 / 0x270 << 0x18 | 0x270);
  return;
}



===== elite_chip_init_common @ 14000ae2c =====

void elite_chip_init_common(longlong param_1,byte *param_2,uint param_3)

{
  elite_gtt_init(param_1);
  elite_cdu_init_common(param_1);
  elite_init_run(param_1,param_2,0,0xffff,param_3);
  return;
}



===== elite_cxt_hw_init_pf @ 14000ae7c =====

void elite_cxt_hw_init_pf(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  undefined4 local_res8;
  uint local_resc;
  
  elite_doorbell_init_pf(param_1);
  puVar3 = (ulonglong *)(param_1 + 0x1f0);
  elite_init_store_rt_reg(param_1,0xd,*(undefined4 *)(param_1 + 0x234));
  elite_init_store_rt_reg(param_1,0xe,*(undefined4 *)(param_1 + 0x230));
  elite_init_store_rt_reg(param_1,0xc,*(undefined4 *)(param_1 + 0x238));
  uVar2 = 0;
  lVar1 = 2;
  do {
    mm_memset(&local_res8,8,0);
    local_res8 = (undefined4)(*puVar3 >> 0xc);
    local_resc = (uint)(*puVar3 >> 0x2c) | local_resc & 0xfff00000 | 0x100000;
    elite_init_store_rt_agg(param_1,(ulonglong)((int)(uVar2 >> 2) + 0xf),(longlong)&local_res8,8);
    uVar2 = uVar2 + 8;
    puVar3 = puVar3 + 3;
    lVar1 = lVar1 + -1;
  } while (lVar1 != 0);
  return;
}



===== elite_dmae_cmd @ 14000af58 =====

undefined8 elite_dmae_cmd(longlong param_1,byte *param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  uint local_res18 [2];
  
  local_res18[0] = (uint)param_3;
  uVar1 = elite_set_ptt(param_1,param_2,0x2aa16c);
  mm_pci_mem_write(param_1,0,uVar1,local_res18);
  uVar1 = 0;
  do {
    uVar2 = elite_set_ptt(param_1,param_2,0x2aa16c);
    uVar2 = mm_pci_mem_read(param_1,uVar2);
    if (uVar2 == param_3) {
      return 0;
    }
    mm_delay(0x32);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 20000);
  return 1;
}



===== elite_doorbell_init_pf @ 14000afec =====

void elite_doorbell_init_pf(longlong param_1)

{
  elite_init_store_rt_reg(param_1,0,1);
  elite_init_store_rt_reg(param_1,1,1);
  elite_init_store_rt_reg(param_1,2,1);
  elite_init_store_rt_reg(param_1,3,1);
  elite_init_store_rt_reg(param_1,4,1);
  elite_init_store_rt_reg(param_1,5,1);
  return;
}



===== elite_function_start @ 14000b058 =====

ulonglong elite_function_start(longlong param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined7 extraout_var;
  ulonglong uVar4;
  undefined4 extraout_var_00;
  undefined4 local_res18 [4];
  
  bVar1 = elite_rx_start(param_1);
  uVar4 = CONCAT71(extraout_var,bVar1);
  if ((int)uVar4 == 0) {
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) | 8;
    iVar2 = elite_tx_start(param_1);
    uVar4 = CONCAT44(extraout_var_00,iVar2);
    if (iVar2 == 0) {
      local_res18[0] = 0;
      uVar3 = elite_set_ptt(param_1,param_2,0x5011f4);
      mm_pci_mem_write(param_1,0,uVar3,local_res18);
      *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) | 0x10;
      uVar4 = 0;
    }
  }
  return uVar4;
}



===== elite_get_chip_info @ 14000b0c0 =====

undefined8 elite_get_chip_info(longlong param_1,byte *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar1 = mm_pci_cfg_read(param_1,0);
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  uVar2 = elite_set_ptt(param_1,param_2,0x976c);
  uVar1 = mm_pci_mem_read(param_1,uVar2);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar2 = elite_set_ptt(param_1,param_2,0x9770);
  uVar2 = mm_pci_mem_read(param_1,uVar2);
  *(uint *)(param_1 + 0x20) = uVar2 & 0xf;
  *(uint *)(param_1 + 0x10) = (uint)((*(ushort *)(param_1 + 0x16) & 0xff00) == 0x8000);
  uVar2 = elite_set_ptt(param_1,param_2,0x971c);
  uVar2 = mm_pci_mem_read(param_1,uVar2);
  *(char *)(param_1 + 0x91) = ((uVar2 >> (*(uint *)(param_1 + 0x30) & 0x1f) & 1) != 0) + '\x01';
  uVar2 = elite_set_ptt(param_1,param_2,0x9778);
  uVar2 = mm_pci_mem_read(param_1,uVar2);
  *(uint *)(param_1 + 0x3c) = uVar2 >> 4 & 0xf;
  uVar2 = elite_set_ptt(param_1,param_2,0x9774);
  uVar2 = mm_pci_mem_read(param_1,uVar2);
  *(uint *)(param_1 + 0x40) = uVar2 & 0xff;
  if ((*(int *)(param_1 + 0x10) == 0) && (*(int *)(param_1 + 0x20) == 0)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== elite_get_dev_port_id @ 14000b1c8 =====

undefined4 elite_get_dev_port_id(longlong param_1,byte *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  uVar4 = uVar5;
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar2 = elite_set_ptt(param_1,param_2,0x218200);
    uVar2 = mm_pci_mem_read(param_1,uVar2);
    uVar3 = 2;
    if ((2 < uVar2) && (uVar3 = 2, uVar2 < 6)) {
      uVar3 = 4;
    }
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x2c) % uVar3;
    if (uVar2 < 3) {
      *(undefined1 *)(param_1 + 0x44) = 1;
    }
    else if (uVar2 < 6) {
      *(undefined1 *)(param_1 + 0x44) = 2;
    }
    else {
      uVar4 = 0xe;
    }
  }
  else {
    uVar4 = 1;
    if (*(int *)(param_1 + 0x10) == 1) {
      *(undefined1 *)(param_1 + 0x44) = 0;
      uVar2 = 0x218200;
      do {
        uVar3 = elite_set_ptt(param_1,param_2,uVar2);
        uVar3 = mm_pci_mem_read(param_1,uVar3);
        cVar1 = *(char *)(param_1 + 0x44);
        if ((uVar3 & 1) != 0) {
          cVar1 = cVar1 + '\x01';
          *(char *)(param_1 + 0x44) = cVar1;
        }
        uVar2 = uVar2 + 4;
      } while ((int)uVar2 < 0x218210);
      if (cVar1 == '\0') {
        uVar4 = 0xe;
      }
      else {
        *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x34);
        uVar4 = uVar5;
      }
    }
  }
  return uVar4;
}



===== elite_get_fid @ 14000b2b8 =====

void elite_get_fid(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = mm_pci_mem_read(param_1,0x1fc);
  *(uint *)(param_1 + 0x28) = uVar1;
  uVar2 = uVar1 & 0xf;
  *(uint *)(param_1 + 0x2c) = uVar1 >> 0x10 & 0xf;
  *(uint *)(param_1 + 0x30) = uVar2;
  *(uint *)(param_1 + 0x34) = uVar1 >> 4 & 3;
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar2 = (uVar1 >> 0x10 & 1) << 3 | uVar2;
  }
  *(char *)(param_1 + 0x90) = (char)uVar2;
  return;
}



===== elite_get_init_hw_mode @ 14000b308 =====

undefined8 elite_get_init_hw_mode(longlong param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  *param_2 = 0;
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = 3;
    if (*(int *)(param_1 + 0x10) == 1) {
      iVar4 = 1;
    }
  }
  if (iVar4 == 0) {
    uVar2 = 0x2002;
    uVar3 = 0x802;
    uVar5 = 0x1002;
  }
  else {
    if (iVar4 != 1) {
      return 0xe;
    }
    uVar2 = 0x2004;
    uVar3 = 0x804;
    uVar5 = 0x1004;
  }
  cVar1 = *(char *)(param_1 + 0x44);
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      uVar3 = uVar5;
    }
    else {
      uVar3 = uVar2;
      if (cVar1 != '\x04') {
        return 0xe;
      }
    }
  }
  if (*(int *)(param_1 + 0x27c) == 1) {
    uVar3 = uVar3 | 0x208;
  }
  else {
    uVar3 = uVar3 | 0x408;
  }
  *param_2 = uVar3;
  return 0;
}



===== elite_init_function @ 14000b3a0 =====

void elite_init_function(longlong param_1,byte *param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  elite_cxt_hw_init_pf(param_1);
  elite_intr_enable_rt(param_1);
  elite_init_mf_mode_rt(param_1);
  iVar1 = elite_init_run(param_1,param_2,2,*(uint *)(param_1 + 0x30),param_3);
  if (iVar1 == 0) {
    iVar1 = elite_init_run(param_1,param_2,4,*(uint *)(param_1 + 0x30),param_3);
    if (iVar1 == 0) {
      uVar2 = elite_config_sb(param_1);
      if ((int)uVar2 == 0) {
        elite_function_start(param_1,param_2);
      }
    }
  }
  return;
}



===== elite_init_mf_mode_rt @ 14000b42c =====

void elite_init_mf_mode_rt(longlong param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x27c) == 1) {
    elite_init_store_rt_reg(param_1,0x92,1);
    elite_init_store_rt_reg(param_1,0x96,(uint)*(ushort *)(param_1 + 0x14a));
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x27c) != 2) {
      return;
    }
    uVar1 = 1;
  }
  elite_init_store_rt_reg(param_1,0x91,uVar1);
  return;
}



===== elite_l2_filter_cmd @ 14000b488 =====

void elite_l2_filter_cmd(longlong param_1,undefined8 param_2)

{
  undefined4 local_res8;
  uint local_28;
  undefined1 local_24;
  undefined8 local_20;
  undefined4 local_18;
  
  local_24 = 5;
  local_res8 = CONCAT22(*(undefined2 *)(param_1 + 0x24),1);
  local_18 = local_res8;
  local_28 = 0x20;
  local_20 = param_2;
  elite_sp_post(param_1,&local_28);
  return;
}



===== elite_l2b_context_host_alloc @ 14000b4c8 =====

undefined8 elite_l2b_context_host_alloc(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int iVar4;
  
  puVar3 = (undefined8 *)(param_1 + 0x200);
  iVar4 = 0;
  do {
    plVar1 = (longlong *)(param_1 + (longlong)iVar4 * 0x18 + 0x1f0);
    uVar2 = mm_page_alloc(param_1,plVar1 + 1,plVar1,1,
                          (undefined8 *)(param_1 + ((longlong)iVar4 + 0x44) * 8));
    if ((int)uVar2 != 0) {
      return 1;
    }
    *puVar3 = 0x1000;
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 3;
  } while (iVar4 < 2);
  *(undefined4 *)(param_1 + 0x234) = 0;
  *(undefined4 *)(param_1 + 0x230) = 1;
  *(undefined4 *)(param_1 + 0x238) = 3;
  return uVar2;
}



===== elite_ptt_set_win @ 14000b558 =====

void elite_ptt_set_win(longlong param_1,byte *param_2,uint param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_2 + 4);
  if (param_3 != *puVar1 * 4) {
    *puVar1 = param_3 >> 2;
    mm_pci_mem_write(param_1,0,(uint)*param_2 << 3,puVar1);
  }
  return;
}



===== elite_rd @ 14000b588 =====

void elite_rd(longlong param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = elite_set_ptt(param_1,param_2,param_3);
  mm_pci_mem_read(param_1,uVar1);
  return;
}



===== elite_read_igu_cam @ 14000b5a8 =====

undefined8 elite_read_igu_cam(longlong param_1,byte *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  
  *(undefined4 *)(param_1 + 0x4c) = 0xffff;
  uVar5 = 0;
  uVar4 = 0;
  uVar3 = 0xff;
  do {
    uVar1 = elite_set_ptt(param_1,param_2,uVar4 * 4 + 0x184000);
    uVar1 = mm_pci_mem_read(param_1,uVar1);
    if (((uVar1 & 1) == 0) && ((uVar1 >> 0x11 & 1) != 0)) break;
    if (((uVar1 >> 0x11 & 1) != 0) && ((uVar1 >> 9 & 0xff) == *(uint *)(param_1 + 0x30))) {
      if (*(short *)(param_1 + 0x4c) == -1) {
        *(short *)(param_1 + 0x4e) = *(short *)(param_1 + 0x4e) + 1;
        *(ushort *)(param_1 + 0x4c) = uVar5;
        break;
      }
      if ((uint)uVar3 != uVar4 - 1) break;
      *(short *)(param_1 + 0x4e) = *(short *)(param_1 + 0x4e) + 1;
      uVar3 = uVar5;
    }
    uVar5 = uVar5 + 1;
    uVar4 = (uint)uVar5;
  } while (uVar4 < (-(uint)(*(int *)(param_1 + 0x10) != 0) & 0x50) + 0x120);
  if ((*(short *)(param_1 + 0x4c) == -1) || (*(short *)(param_1 + 0x4e) == 0)) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== elite_set_ptt @ 14000b694 =====

int elite_set_ptt(longlong param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_3 + *(int *)(param_2 + 4) * -4;
  if ((param_3 < (uint)(*(int *)(param_2 + 4) * 4)) || (0xfff < uVar1)) {
    elite_ptt_set_win(param_1,param_2,param_3);
    uVar1 = 0;
  }
  return (*param_2 + 1) * 0x1000 + uVar1;
}



===== elite_sp_post @ 14000b6d0 =====

undefined4 elite_sp_post(longlong param_1,uint *param_2)

{
  longlong lVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x798);
  puVar2 = (uint *)(param_1 + 0x7b8);
  if (*param_2 < 0x41) {
    mm_memset(*(void **)(param_1 + 0x7a8),(uint)(ushort)*param_2,0);
    mm_memset(*(void **)(param_1 + 0x798),8,0);
    mm_memset(puVar2,0x20,0);
    *(undefined4 *)(param_1 + 0x7c8) = *(undefined4 *)(param_1 + 0x7b0);
    *(int *)(param_1 + 0x7cc) = (int)((ulonglong)*(undefined8 *)(param_1 + 0x7b0) >> 0x20);
    *(undefined4 *)(param_1 + 0x7c0) = *(undefined4 *)(param_1 + 0x7a0);
    *(int *)(param_1 + 0x7c4) = (int)((ulonglong)*(undefined8 *)(param_1 + 0x7a0) >> 0x20);
    *puVar2 = param_2[4];
    *(char *)(param_1 + 0x7bc) = (char)param_2[1];
    *(undefined2 *)(param_1 + 0x7be) = 0x55;
    if (*(void **)(param_2 + 2) != (void *)0x0) {
      mm_memcpy(*(void **)(param_1 + 0x7a8),*(void **)(param_2 + 2),(ulonglong)*param_2);
    }
    local_res8[0] = 0;
    uVar4 = **(int **)(param_1 + 0x788) + 0x16000 +
            (uint)*(ushort *)(*(int **)(param_1 + 0x788) + 1) * *(int *)(param_1 + 0x30);
    do {
      mm_pci_mem_write(param_1,0,uVar4,puVar2);
      puVar2 = puVar2 + 1;
      local_res8[0] = local_res8[0] + 1;
      uVar4 = uVar4 + 4;
    } while (local_res8[0] < 8);
    local_res8[0] = 1;
    mm_pci_mem_write(param_1,0,
                     *(int *)(*(longlong *)(param_1 + 0x788) + 0xc) + 0x16000 +
                     (uint)*(ushort *)(*(longlong *)(param_1 + 0x788) + 0x10) *
                     *(int *)(param_1 + 0x30),local_res8);
    mm_delay(10000);
    local_res8[0] = 0;
    do {
      if (((*(char *)(lVar1 + 7) == '\0') && (*(short *)(lVar1 + 4) == 0x55)) &&
         (*(char *)(lVar1 + 6) == (char)param_2[1])) break;
      local_res8[0] = local_res8[0] + 1;
      mm_delay(1000);
    } while (local_res8[0] < 15000);
    uVar3 = 0;
    if (14999 < local_res8[0]) {
      uVar3 = 3;
    }
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}



===== elite_spe_alloc @ 14000b880 =====

ulonglong elite_spe_alloc(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  plVar1 = (longlong *)(param_1 + 0x7a0);
  mm_dma_alloc(param_1,(longlong *)(param_1 + 0x798),plVar1,8);
  *(undefined4 *)(param_1 + 0x7c0) = *(undefined4 *)plVar1;
  plVar2 = (longlong *)(param_1 + 0x7b0);
  *(int *)(param_1 + 0x7c4) = (int)((ulonglong)*plVar1 >> 0x20);
  uVar3 = mm_dma_alloc(param_1,(longlong *)(param_1 + 0x7a8),plVar2,0x40);
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 != 0) {
    uVar4 = 1;
  }
  *(undefined4 *)(param_1 + 0x7c8) = *(undefined4 *)plVar2;
  *(int *)(param_1 + 0x7cc) = (int)((ulonglong)*plVar2 >> 0x20);
  return uVar4;
}



===== elite_wr @ 14000b908 =====

undefined8 elite_wr(longlong param_1,byte *param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  uVar1 = elite_set_ptt(param_1,param_2,param_3);
  mm_pci_mem_write(param_1,0,uVar1,local_res20);
  return 0;
}



===== elite_wr_indirect @ 14000b938 =====

void elite_wr_indirect(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_res10 [2];
  undefined4 local_res18 [4];
  
  local_res10[0] = param_2;
  local_res18[0] = param_3;
  mm_pci_cfg_write(param_1,*(undefined4 *)(param_1 + 0x94),local_res10);
  mm_pci_cfg_write(param_1,*(undefined4 *)(param_1 + 0x98),local_res18);
  return;
}



===== lm_ack_enable_intr @ 14000b974 =====

void lm_ack_enable_intr(longlong param_1,int param_2,byte param_3)

{
  ulonglong local_res8 [4];
  
  local_res8[0] = (ulonglong)((param_2 * 2 | (uint)param_3) << 0x18 | *(uint *)(param_1 + 0xab8));
  mm_pci_mem_write(param_1,0,(uint)*(ushort *)(param_1 + 0xabc) * 8 + 0xf000,
                   (undefined4 *)local_res8);
  return;
}



===== lm_chip_init @ 14000b9b4 =====

ulonglong lm_chip_init(longlong param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  ulonglong uVar5;
  undefined4 uVar6;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  uint local_res18 [2];
  
  local_res8[0] = 0;
  pbVar1 = (byte *)(param_1 + 0x284);
  local_res10[0] = 0;
  uVar4 = elite_dmae_cmd(param_1,pbVar1,1);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) | 1;
  uVar4 = elite_get_init_hw_mode(param_1,local_res18);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  if (*(int *)(param_1 + 0x27c) == 1) {
    if ((*(uint *)(param_1 + 0x278) & 4) == 0) {
      if ((*(uint *)(param_1 + 0x278) & 8) == 0) goto LAB_14000ba56;
      uVar6 = 0x88a8;
    }
    else {
      uVar6 = 0x8100;
    }
    elite_init_store_rt_reg(param_1,0xb,uVar6);
    elite_init_store_rt_reg(param_1,0x8f,uVar6);
    elite_init_store_rt_reg(param_1,0x9b,uVar6);
  }
LAB_14000ba56:
  uVar4 = elite_mcp_load_req(param_1,pbVar1,local_res8);
  if ((int)uVar4 != 0) {
    return uVar4;
  }
  elite_mcp_set_capab(param_1,pbVar1);
  if (local_res8[0] == 0x10100000) {
    uVar2 = elite_chip_init_common(param_1,pbVar1,local_res18[0]);
    uVar4 = (ulonglong)uVar2;
    if (uVar2 != 0) goto LAB_14000bae6;
LAB_14000bab7:
    uVar2 = elite_init_run(param_1,pbVar1,1,*(uint *)(param_1 + 0x34),local_res18[0]);
    uVar4 = (ulonglong)uVar2;
    if (uVar2 != 0) goto LAB_14000bae6;
  }
  else {
    if (local_res8[0] == 0x10110000) goto LAB_14000bab7;
    if (local_res8[0] != 0x10120000) {
      return 1;
    }
  }
  uVar2 = elite_init_function(param_1,pbVar1,local_res18[0]);
  uVar4 = (ulonglong)uVar2;
LAB_14000bae6:
  iVar3 = elite_issue_mcp_cmd(param_1,pbVar1,0x11000000,0,local_res8,local_res10);
  uVar5 = CONCAT44(extraout_var,iVar3);
  if (iVar3 == 0) {
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) | 4;
    *(byte *)(param_1 + 0xaca) = *(byte *)(param_1 + 0xaca) | 1;
    elite_issue_mcp_cmd(param_1,pbVar1,0x29000000,0x8210100,local_res8,local_res10);
    lm_mcp_ov_update_drv_state(param_1,1);
    if (*(int *)(param_1 + 0x2c) == 0) {
      lm_mcp_ov_update_bus_num(param_1);
    }
    lm_mcp_ov_get_oem_update(param_1);
    uVar5 = uVar4;
  }
  return uVar5;
}



===== lm_disable_intr @ 14000bb80 =====

void lm_disable_intr(longlong param_1)

{
  if (*(char *)(param_1 + 0xac9) != '\0') {
    elite_intr_disable_igu(param_1);
  }
  return;
}



===== lm_enable_intr @ 14000bb98 =====

void lm_enable_intr(longlong param_1)

{
  if (*(char *)(param_1 + 0xac9) == '\0') {
    elite_intr_enable_igu(param_1);
  }
  return;
}



===== lm_get_dev_id @ 14000bbb0 =====

undefined8 lm_get_dev_id(longlong param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  iVar1 = mm_pci_mem_read(param_1,0x1f8);
  *(int *)(param_1 + 0x24) = iVar1;
  if (iVar1 == -1) {
    uVar3 = 0xd;
  }
  else {
    uVar2 = mm_pci_mem_read(param_1,0x1fc);
    *(uint *)(param_1 + 0x28) = uVar2;
    *(uint *)(param_1 + 0x2c) = uVar2 >> 0x10 & 0xf;
    *(uint *)(param_1 + 0x30) = uVar2 & 0xf;
    *(uint *)(param_1 + 0x34) = uVar2 >> 4 & 3;
    uVar3 = 0;
  }
  return uVar3;
}



===== lm_get_dev_info @ 14000bc08 =====

ulonglong lm_get_dev_info(uint *param_1)

{
  uint *puVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 extraout_var_00;
  undefined7 extraout_var;
  int local_res8 [2];
  
  puVar1 = param_1 + 0xa1;
  uVar3 = mm_pci_cfg_read((longlong)param_1,8);
  *(char *)(param_1 + 6) = (char)uVar3;
  if ((char)uVar3 == -1) {
    uVar7 = 1;
  }
  else {
    param_1[0x9e] = 0;
    uVar4 = mm_pci_mem_read((longlong)param_1,0x1f8);
    param_1[9] = uVar4;
    if (uVar4 == 0xffffffff) {
      uVar7 = 0xd;
    }
    else {
      param_1[0xa2] = 0xffffffff;
      param_1[0xa5] = 0xffffffff;
      param_1[0xa8] = 0xffffffff;
      *(byte *)puVar1 = 0;
      *(undefined1 *)(param_1 + 0xa4) = 1;
      *(undefined1 *)(param_1 + 0xa7) = 2;
      uVar7 = elite_get_chip_info((longlong)param_1,(byte *)puVar1);
      if ((int)uVar7 == 0) {
        elite_get_fid((longlong)param_1);
        local_res8[0] = 1 << ((byte)param_1[0xb] & 0x1f);
        uVar4 = elite_set_ptt((longlong)param_1,(byte *)puVar1,0x2aa138);
        mm_pci_mem_write((longlong)param_1,0,uVar4,local_res8);
        local_res8[0] = 1;
        uVar4 = elite_set_ptt((longlong)param_1,(byte *)puVar1,0x2aa174);
        mm_pci_mem_write((longlong)param_1,0,uVar4,local_res8);
        iVar5 = elite_get_dev_port_id((longlong)param_1,(byte *)puVar1);
        uVar7 = CONCAT44(extraout_var_00,iVar5);
        if (iVar5 == 0) {
          uVar7 = elite_cfg_mcp_cmd_interface((longlong)param_1);
          if ((int)uVar7 == 0) {
            elite_get_mfw_version((longlong)param_1);
            bVar2 = elite_get_scratch_nvm_cfg_addr((longlong)param_1);
            uVar7 = CONCAT71(extraout_var,bVar2);
            if ((int)uVar7 == 0) {
              uVar7 = elite_get_dev_info_nvm(param_1);
              if ((int)uVar7 == 0) {
                uVar7 = elite_mcp_get_capab((longlong)param_1,(byte *)puVar1);
                if ((int)uVar7 == 0) {
                  uVar7 = elite_read_igu_cam((longlong)param_1,(byte *)puVar1);
                  if ((int)uVar7 == 0) {
                    *(undefined **)(param_1 + 0x1e2) = &DAT_14001a1d0;
                    uVar4 = 0xe4;
                    if (param_1[4] != 1) {
                      uVar4 = 0x80;
                    }
                    uVar6 = 0xe0;
                    if (param_1[4] != 1) {
                      uVar6 = 0x78;
                    }
                    param_1[0x25] = uVar6;
                    param_1[0x26] = uVar4;
                    param_1[0x28] = 0;
                    param_1[0x27] = 0x20;
                    uVar4 = elite_set_ptt((longlong)param_1,(byte *)puVar1,0x9760);
                    mm_pci_mem_read((longlong)param_1,uVar4);
                    uVar4 = elite_set_ptt((longlong)param_1,(byte *)puVar1,0x9760);
                    uVar3 = mm_pci_mem_read((longlong)param_1,uVar4);
                    *(byte *)(param_1 + 0x29) = (byte)uVar3 & 1;
                    uVar7 = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar7;
}



===== lm_get_required_dma_mem @ 14000be00 =====

undefined8 lm_get_required_dma_mem(void)

{
  return 0x45d8;
}



===== lm_get_required_pages @ 14000be08 =====

undefined8 lm_get_required_pages(void)

{
  return 2;
}



===== lm_init_resc @ 14000be10 =====

void lm_init_resc(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = elite_alloc_status_block(param_1);
  if ((int)uVar1 == 0) {
    uVar1 = elite_setup_rx_chain(param_1);
    if ((int)uVar1 == 0) {
      uVar1 = elite_setup_tx_chain(param_1);
      if ((int)uVar1 == 0) {
        uVar1 = elite_l2b_context_host_alloc(param_1);
        if ((int)uVar1 == 0) {
          uVar1 = elite_dma_info_alloc(param_1);
          if ((int)uVar1 == 0) {
            elite_spe_alloc(param_1);
          }
        }
      }
    }
  }
  return;
}



===== lm_mcp_cfg_link @ 14000be60 =====

int lm_mcp_cfg_link(longlong param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 1;
  if ((*(byte *)(param_1 + 0xaca) & 1) != 0) {
    iVar2 = elite_set_link_mcp(param_1,(byte *)(param_1 + 0x284),(char)param_2);
    if (iVar2 == 0) {
      if (param_2 == 0) {
        *(undefined1 *)(param_1 + 0x280) = 0;
        bVar1 = *(byte *)(param_1 + 0xaca) & 0xfd;
      }
      else {
        bVar1 = *(byte *)(param_1 + 0xaca) | 2;
      }
      *(byte *)(param_1 + 0xaca) = bVar1;
      if ((param_2 != 0) && (*(int *)(param_1 + 0x2c) == *(int *)(param_1 + 0x38))) {
        elite_wait_for_stable_link(param_1,(byte *)(param_1 + 0x284));
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}



===== lm_mcp_handle_link_change @ 14000bee0 =====

ulonglong lm_mcp_handle_link_change(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = elite_mcp_link_handler(param_1,(byte *)(param_1 + 0x290),'\0');
  return uVar1 & 0xff;
}



===== lm_pci_cfg_map_db_regs @ 14000befc =====

void lm_pci_cfg_map_db_regs(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  
  bVar5 = *(int *)(param_1 + 0x10) != 1;
  uVar4 = 0xf0;
  if (bVar5) {
    uVar4 = 0x90;
  }
  uVar2 = 0x2aafa0;
  if (bVar5) {
    uVar2 = 0x2aa40c;
  }
  uVar3 = 0x2aafa4;
  if (bVar5) {
    uVar3 = 0x2aa410;
  }
  uVar1 = 0xf4;
  if (bVar5) {
    uVar1 = 0x94;
  }
  *(undefined4 *)(param_1 + 0x9c) = uVar1;
  *(undefined4 *)(param_1 + 0xa0) = uVar4;
  elite_wr_indirect(param_1,uVar2,0x40000000);
  elite_wr_indirect(param_1,uVar3,0x40000020);
  return;
}



===== lm_post_buffers @ 14000bf74 =====

ulonglong lm_post_buffers(longlong param_1)

{
  short sVar1;
  undefined6 extraout_var;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  sVar1 = elite_replenish_bd_chain((longlong *)(param_1 + 0x7d8));
  if ((int)CONCAT62(extraout_var,sVar1) != 0) {
    local_res8[0] =
         CONCAT22(*(undefined2 *)(param_1 + 0x7ec),(short)local_res8[0]) & 0xffffff30 | 0x46;
    mm_pci_mem_write(param_1,1,*(uint *)(param_1 + 0x9c),local_res8);
  }
  return CONCAT62(extraout_var,sVar1) & 0xffffffff;
}



===== lm_send_packet @ 14000bfe0 =====

void lm_send_packet(longlong param_1,longlong param_2)

{
  if ((*(uint *)(param_1 + 0x278) & 1) == 0) {
    elite_send_packet(param_1,param_2);
  }
  return;
}



===== lm_service_intr @ 14000c000 =====

undefined4 lm_service_intr(longlong param_1)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  uint uVar5;
  
  sVar1 = 0;
  sVar2 = 0;
  if ((*(uint *)(param_1 + 0x278) & 1) == 0) {
    uVar4 = elite_has_tx_work(param_1);
    if ((char)uVar4 != '\0') {
      sVar1 = elite_process_tx_completions(param_1);
    }
    uVar4 = elite_has_rx_work(param_1);
    if ((char)uVar4 != '\0') {
      sVar2 = elite_process_rx_pkt(param_1);
    }
    uVar4 = elite_has_tx_work(param_1);
    if ((char)uVar4 == '\0') {
      elite_has_rx_work(param_1);
    }
    if (((sVar1 != 0) || (sVar2 != 0)) &&
       (uVar5 = *(uint *)(*(longlong *)(param_1 + 0xaa8) + 0x1c) & 0xffffff,
       *(uint *)(param_1 + 0xab8) != uVar5)) {
      *(uint *)(param_1 + 0xab8) = uVar5;
    }
    uVar3 = CONCAT22(sVar1,sVar2);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== lm_set_rx_mask @ 14000c0b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 lm_set_rx_mask(longlong param_1,undefined1 param_2)

{
  undefined8 uVar1;
  undefined1 auStack_58 [32];
  undefined1 local_38 [2];
  undefined1 local_36;
  undefined1 local_2c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  if ((*(byte *)(param_1 + 0xac8) & 8) == 0) {
    uVar1 = 1;
  }
  else {
    mm_memset(local_38,0x20,0);
    *(undefined1 *)(param_1 + 0x131) = param_2;
    local_36 = 1;
    local_2c = param_2;
    uVar1 = elite_l2_filter_cmd(param_1,local_38);
  }
  return uVar1;
}



===== lm_shutdown @ 14000c12c =====

ulonglong lm_shutdown(longlong param_1)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 local_res18 [4];
  
  uVar6 = 0;
  pbVar1 = (byte *)(param_1 + 0x284);
  if (*(char *)(param_1 + 0xac9) != '\0') {
    elite_intr_disable_igu(param_1);
    local_res10[0] = 0;
    uVar3 = elite_set_ptt(param_1,pbVar1,0x18082c);
    mm_pci_mem_write(param_1,0,uVar3,local_res10);
    local_res10[0] = 0;
    uVar3 = elite_set_ptt(param_1,pbVar1,0x180830);
    mm_pci_mem_write(param_1,0,uVar3,local_res10);
  }
  local_res10[0] = 1;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x5011f4);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  bVar2 = *(byte *)(param_1 + 0xac8);
  if ((bVar2 & 8) != 0) {
    elite_rx_stop(param_1);
    elite_cfc_delete(param_1,1);
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) & 0xf7;
    bVar2 = *(byte *)(param_1 + 0xac8);
  }
  if ((bVar2 & 0x10) != 0) {
    elite_tx_stop(param_1);
    elite_cfc_delete(param_1,0);
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) & 0xef;
  }
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x2c043c);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x2c0444);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  uVar3 = 0;
  do {
    uVar4 = elite_set_ptt(param_1,pbVar1,0x2c04fc);
    iVar5 = mm_pci_mem_read(param_1,uVar4);
    if (iVar5 == 0) {
      uVar4 = elite_set_ptt(param_1,pbVar1,0x2c0500);
      iVar5 = mm_pci_mem_read(param_1,uVar4);
      if (iVar5 == 0) break;
    }
    mm_delay(1000);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 10);
  if ((*(byte *)(param_1 + 0xac8) & 1) != 0) {
    uVar6 = elite_dmae_cmd(param_1,pbVar1,0);
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) & 0xfe;
    uVar6 = uVar6 & 0xffffffff;
  }
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x100508);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x2f2ea4);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x2d0708);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  local_res10[0] = 0;
  uVar3 = elite_set_ptt(param_1,pbVar1,0x2e0708);
  mm_pci_mem_write(param_1,0,uVar3,local_res10);
  if ((*(byte *)(param_1 + 0xac8) & 4) != 0) {
    iVar5 = elite_issue_mcp_cmd(param_1,pbVar1,0x20000000,1,local_res8,local_res18);
    if (iVar5 != 0) {
      local_res8[0] = 0x20110000;
    }
    uVar3 = elite_issue_mcp_cmd(param_1,pbVar1,0x21000000,0,local_res8,local_res18);
    *(byte *)(param_1 + 0xac8) = *(byte *)(param_1 + 0xac8) & 0xf9;
    uVar6 = (ulonglong)uVar3;
  }
  *(byte *)(param_1 + 0xaca) = *(byte *)(param_1 + 0xaca) & 0xfe;
  lm_mcp_ov_update_drv_state(param_1,0);
  return uVar6;
}



===== lm_mcp_ov_bw_update_ack @ 14000c3fc =====

bool lm_mcp_ov_bw_update_ack(longlong param_1)

{
  int iVar1;
  undefined4 local_res8 [2];
  uint local_res10 [6];
  
  iVar1 = elite_issue_mcp_cmd(param_1,(byte *)(param_1 + 0x284),0x32000000,0,local_res10,local_res8)
  ;
  return iVar1 != 0;
}



===== lm_mcp_ov_get_oem_update @ 14000c438 =====

int lm_mcp_ov_get_oem_update(longlong param_1)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  undefined7 extraout_var;
  uint local_res8 [2];
  int local_res10 [2];
  uint local_res18 [2];
  undefined4 local_res20 [2];
  
  pbVar1 = (byte *)(param_1 + 0x284);
  iVar3 = elite_issue_mcp_cmd(param_1,pbVar1,0x41000000,0,local_res8,local_res10);
  if (iVar3 == 0) {
    if (local_res8[0] == 0x41000000) {
      if (local_res10[0] == 1) {
        elite_mcp_update_bw(param_1,pbVar1);
        bVar2 = lm_mcp_ov_bw_update_ack(param_1);
        iVar3 = (int)CONCAT71(extraout_var,bVar2);
      }
      else {
        if (local_res10[0] != 2) {
          return 0;
        }
        elite_mcp_update_stag(param_1,pbVar1);
        iVar3 = elite_issue_mcp_cmd(param_1,pbVar1,0x3b000000,0,local_res18,local_res20);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = 0;
        if (local_res18[0] != 0x3b000000) {
          iVar3 = 3;
        }
      }
    }
    else {
      iVar3 = 3;
    }
  }
  return iVar3;
}



===== lm_mcp_ov_update_bus_num @ 14000c4f8 =====

void lm_mcp_ov_update_bus_num(longlong param_1)

{
  undefined8 uVar1;
  undefined4 local_res8 [2];
  uint local_res10 [6];
  
  uVar1 = iscsiBootCancel();
  elite_issue_mcp_cmd(param_1,(byte *)(param_1 + 0x284),0x27000000,(uint)uVar1 & 0xff,local_res10,
                      local_res8);
  return;
}



===== lm_mcp_ov_update_drv_state @ 14000c53c =====

int lm_mcp_ov_update_drv_state(longlong param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res8 [2];
  uint local_res10 [6];
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  if (param_2 == 0) {
    uVar2 = 2;
  }
  else if (param_2 == 1) {
    uVar2 = 4;
  }
  else {
    if (param_2 != 2) {
      return 3;
    }
    uVar2 = 5;
  }
  iVar1 = elite_issue_mcp_cmd(param_1,(byte *)(param_1 + 0x284),0x31000000,uVar2,local_res10,
                              local_res8);
  if ((iVar1 == 0) && (local_res10[0] != 0x31000000)) {
    iVar1 = 3;
  }
  return iVar1;
}



===== elite_cfg_mcp_cmd_interface @ 14000c5b4 =====

undefined8 elite_cfg_mcp_cmd_interface(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  elite_get_mcp_public_offsets(param_1,(byte *)(param_1 + 0x284));
  lVar1 = mm_alloc_pool(param_1,((int)(*(ushort *)(param_1 + 0x178) - 1) >> 2) * 4 + 4);
  *(longlong *)(param_1 + 0x168) = lVar1;
  lVar1 = mm_alloc_pool(param_1,((int)(*(ushort *)(param_1 + 0x178) - 1) >> 2) * 4 + 4);
  *(longlong *)(param_1 + 0x170) = lVar1;
  if ((*(longlong *)(param_1 + 0x168) == 0) || (lVar1 == 0)) {
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== elite_get_dev_info_nvm @ 14000c62c =====

undefined8 elite_get_dev_info_nvm(uint *param_1)

{
  uint *puVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  
  puVar1 = param_1 + 0xa1;
  uVar4 = elite_rd((longlong)param_1,(byte *)puVar1,param_1[0x6b] + 0xe20000);
  uVar6 = uVar4 >> 4 & 0xff;
  if ((char)(uVar4 >> 4) == '\0') {
LAB_14000c688:
    param_1[0x9f] = 1;
  }
  else {
    if ((uVar6 != 1) && (uVar6 != 3)) {
      if (uVar6 == 6) {
        param_1[0x9e] = param_1[0x9e] | 8;
      }
      else {
        if (uVar6 != 7) goto LAB_14000c6c9;
        param_1[0x9e] = param_1[0x9e] | 4;
      }
      goto LAB_14000c688;
    }
LAB_14000c6c9:
    param_1[0x9f] = 2;
  }
  uVar4 = param_1[0x6b];
  uVar3 = elite_rd((longlong)param_1,(byte *)puVar1,uVar4 + 0xe20050);
  *param_1 = (uint)uVar3;
  uVar6 = param_1[0xc];
  if (param_1[4] == 0) {
    uVar6 = (param_1[0xb] & 1) << 3 | uVar6;
  }
  uVar6 = elite_rd((longlong)param_1,(byte *)puVar1,uVar4 + 0xe20b94 + uVar6 * 0x50);
  param_1[0x2a] = uVar6;
  uVar6 = param_1[0xc];
  if (param_1[4] == 0) {
    uVar6 = (param_1[0xb] & 1) << 3 | uVar6;
  }
  uVar6 = elite_rd((longlong)param_1,(byte *)puVar1,uVar4 + 0xe20b90 + uVar6 * 0x50);
  param_1[0x2b] = uVar6;
  uVar6 = param_1[0xc];
  if (param_1[4] == 0) {
    uVar6 = (param_1[0xb] & 1) << 3 | uVar6;
  }
  uVar3 = elite_rd((longlong)param_1,(byte *)puVar1,uVar4 + 0xe20ba0 + uVar6 * 0x50);
  param_1[1] = (uint)uVar3;
  iVar7 = (param_1[0xb] %
          (((((uint)uVar3 - (uint)uVar3) - (uint)(param_1[4] != 0)) + 2) * (uint)(byte)param_1[0x11]
          )) * 600 + param_1[0x6b];
  uVar3 = elite_rd((longlong)param_1,(byte *)puVar1,iVar7 + 0xe20244);
  param_1[0x70] = (uint)uVar3;
  param_1[0x7a] = (uint)uVar3;
  uVar4 = elite_rd((longlong)param_1,(byte *)puVar1,iVar7 + 0xe20248);
  uVar6 = uVar4 & 0xf;
  if (uVar6 == 0) {
    *(undefined1 *)(param_1 + 0x6f) = 1;
  }
  else if (uVar6 == 1) {
    param_1[0x71] = 1000;
  }
  else if (uVar6 == 2) {
    param_1[0x71] = 10000;
  }
  else if (uVar6 == 3) {
    param_1[0x71] = 20000;
  }
  else if (uVar6 == 4) {
    param_1[0x71] = 25000;
  }
  else if (uVar6 == 5) {
    param_1[0x71] = 40000;
  }
  else if (uVar6 == 6) {
    param_1[0x71] = 50000;
  }
  else {
    if (uVar6 != 7) {
      return 1;
    }
    param_1[0x71] = 100000;
  }
  param_1[0x73] = 0;
  uVar4 = uVar4 >> 4 & 7;
  *(byte *)(param_1 + 0x72) = (byte)uVar4 & 1;
  *(char *)((longlong)param_1 + 0x1ca) = (char)(uVar4 >> 2);
  *(byte *)((longlong)param_1 + 0x1c9) = (byte)(uVar4 >> 1) & 1;
  uVar4 = elite_rd((longlong)param_1,(byte *)puVar1,iVar7 + 0xe2025c);
  param_1[0x6d] = uVar4 >> 0x11 & 0xff;
  uVar5 = elite_mcp_read_core_config((longlong)param_1,(byte *)puVar1);
  if ((int)uVar5 != 0) {
    return 1;
  }
  iVar7 = elite_mcp_read_func_info((longlong)param_1,(byte *)puVar1);
  if (iVar7 != 0) {
    return 1;
  }
  bVar2 = elite_rd((longlong)param_1,(byte *)puVar1,param_1[0x6b] + 0xe2002c);
  if (bVar2 < 0xd) {
    if ((bVar2 == 0xc) || (bVar2 < 2)) goto LAB_14000c91b;
    if (bVar2 != 2) {
      if (2 < bVar2) {
        if (bVar2 < 6) goto LAB_14000c924;
        if (bVar2 == 0xb) goto LAB_14000c8e5;
      }
LAB_14000c8fd:
      *(undefined1 *)((longlong)param_1 + 0x93) = 0;
      return 1;
    }
  }
  else if (bVar2 != 0xd) {
    if (bVar2 == 0xe) {
LAB_14000c924:
      *(undefined1 *)((longlong)param_1 + 0x93) = 4;
      return 0;
    }
    if (bVar2 != 0xf) goto LAB_14000c8fd;
LAB_14000c91b:
    *(undefined1 *)((longlong)param_1 + 0x93) = 2;
    return 0;
  }
LAB_14000c8e5:
  *(undefined1 *)((longlong)param_1 + 0x93) = 1;
  return 0;
}



===== elite_get_mcp_public_offsets @ 14000c930 =====

bool elite_get_mcp_public_offsets(longlong param_1,byte *param_2)

{
  int iVar1;
  undefined2 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = *(uint *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar6 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | uVar6;
  }
  uVar4 = elite_rd(param_1,param_2,0x8c20);
  *(uint *)(param_1 + 0x150) = uVar4;
  if (uVar4 != 0) {
    uVar7 = uVar4 | 0xe00000;
    *(uint *)(param_1 + 0x150) = uVar7;
    uVar5 = elite_rd(param_1,param_2,uVar7 + 4);
    *(uint *)(param_1 + 0x154) = (uVar5 >> 0xe & 0x3fffc) * uVar6 + (uVar5 & 0xffff) * 4 + 0xe20000;
    uVar5 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x150) + 8);
    uVar5 = (uVar5 >> 0xe & 0x3fffc) * uVar6 + ((uVar5 & 0xffff) + 0x388000) * 4;
    *(uint *)(param_1 + 0x158) = uVar5;
    uVar2 = elite_rd(param_1,param_2,uVar5);
    *(undefined2 *)(param_1 + 0x178) = uVar2;
    uVar2 = elite_rd(param_1,param_2,*(uint *)(param_1 + 0x154));
    *(undefined2 *)(param_1 + 0x160) = uVar2;
    uVar3 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x154) + 0x10);
    *(ushort *)(param_1 + 0x162) = uVar3 & 0x7fff;
    uVar2 = elite_rd(param_1,param_2,0x96d4);
    *(undefined2 *)(param_1 + 0x198) = uVar2;
    uVar5 = elite_rd(param_1,param_2,uVar7 + 0xc);
    *(uint *)(param_1 + 0x184) = (uVar5 >> 0xe & 0x3fffc) * uVar6 + (uVar5 & 0xffff) * 4 + 0xe20000;
    uVar5 = elite_rd(param_1,param_2,uVar7 + 0x10);
    *(uint *)(param_1 + 0x188) = (uVar5 >> 0xe & 0x3fffc) * uVar6 + (uVar5 & 0xffff) * 4 + 0xe20000;
    uVar5 = elite_rd(param_1,param_2,uVar7 + 0x14);
    uVar8 = uVar5 >> 0xe & 0x3fffc;
    iVar1 = (uVar5 & 0xffff) * 4 + 0xe20000;
    *(uint *)(param_1 + 0x18c) = uVar8 * uVar6 + iVar1;
    *(uint *)(param_1 + 0x15c) =
         (*(uint *)(param_1 + 0x2c) %
         ((2 - (uint)(*(int *)(param_1 + 0x10) != 0)) * (uint)*(byte *)(param_1 + 0x44))) * uVar8 +
         iVar1;
    uVar5 = elite_rd(param_1,param_2,uVar7 + 0x18);
    *(uint *)(param_1 + 400) = (uVar5 >> 0xe & 0x3fffc) * uVar6 + (uVar5 & 0xffff) * 4 + 0xe20000;
  }
  return uVar4 == 0;
}



===== elite_get_mfw_version @ 14000cb5c =====

void elite_get_mfw_version(longlong param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = elite_rd(param_1,(byte *)(param_1 + 0x284),*(int *)(param_1 + 0x150) + 0xc);
  uVar2 = elite_rd(param_1,(byte *)(param_1 + 0x284),(uVar1 & 0xffff) * 4 + 0xe20018);
  *(undefined4 *)(param_1 + 0x194) = uVar2;
  return;
}



===== elite_get_scratch_nvm_cfg_addr @ 14000cbac =====

bool elite_get_scratch_nvm_cfg_addr(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = elite_rd(param_1,(byte *)(param_1 + 0x284),0x8c80);
  *(int *)(param_1 + 0x1a8) = iVar1;
  if (iVar1 != 0) {
    uVar2 = elite_rd(param_1,(byte *)(param_1 + 0x284),iVar1 + 4);
    *(undefined4 *)(param_1 + 0x1ac) = uVar2;
  }
  return iVar1 == 0;
}



===== elite_issue_mcp_cmd @ 14000cc04 =====

undefined4
elite_issue_mcp_cmd(longlong param_1,byte *param_2,uint param_3,undefined4 param_4,uint *param_5,
                   undefined4 *param_6)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  
  uVar5 = 0;
  if (*(char *)(param_1 + 0x1a0) == '\0') {
    *(undefined1 *)(param_1 + 0x1a0) = 1;
    if (*(int *)(param_1 + 0x150) == 0) {
      uVar5 = 1;
    }
    else {
      uVar2 = elite_rd(param_1,param_2,0x96d4);
      if (*(ushort *)(param_1 + 0x198) != uVar2) {
        elite_get_mcp_public_offsets(param_1,param_2);
      }
      *(short *)(param_1 + 0x160) = *(short *)(param_1 + 0x160) + 1;
      uVar1 = *(ushort *)(param_1 + 0x160);
      elite_wr(param_1,param_2,*(int *)(param_1 + 0x154) + 4,param_4);
      elite_wr(param_1,param_2,*(uint *)(param_1 + 0x154),uVar1 | param_3);
      uVar2 = 1;
      do {
        mm_delay(10);
        uVar3 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x154) + 8);
        *param_5 = uVar3;
        if ((uint)uVar1 == (uVar3 & 0xffff)) {
          *(undefined2 *)param_5 = 0;
          uVar4 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x154) + 0xc);
          *param_6 = uVar4;
          goto LAB_14000cd2e;
        }
        bVar6 = uVar2 < 5000000;
        uVar2 = uVar2 + 1;
      } while (bVar6);
      *param_5 = 0;
      uVar5 = 1;
LAB_14000cd2e:
      *(undefined1 *)(param_1 + 0x1a0) = 0;
    }
  }
  else {
    uVar5 = 0x19;
  }
  return uVar5;
}



===== elite_mcp_do_load_req @ 14000cd54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void elite_mcp_do_load_req(longlong param_1,byte *param_2,uint *param_3,int param_4,uint param_5)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 auStackY_88 [32];
  undefined4 local_58 [2];
  uint local_50 [4];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_88;
  if (0x10000 < (param_5 & 0xff0000)) {
    mm_memset(local_50,0x10,0);
    uVar2 = mm_get_drv_version_dword();
    local_50[0] = (uint)uVar2;
    uVar2 = mm_get_drv_type();
    iVar1 = *(int *)(param_1 + 0x154);
    local_50[1] = (int)uVar2;
    local_50[3] = param_4 << 0x10 | 1;
    uVar3 = 0;
    lVar4 = 0;
    local_50[2] = 0x8210100;
    do {
      elite_wr(param_1,param_2,uVar3 + iVar1 + 0x18,*(undefined4 *)((longlong)local_50 + lVar4));
      uVar3 = uVar3 + 4;
      lVar4 = lVar4 + 4;
    } while (uVar3 < 0x10);
  }
  elite_issue_mcp_cmd(param_1,param_2,0x10000000,param_5 | 0x4002108,param_3,local_58);
  return;
}



===== elite_mcp_get_capab @ 14000ce44 =====

void elite_mcp_get_capab(longlong param_1,byte *param_2)

{
  uint local_res8 [8];
  
  elite_issue_mcp_cmd(param_1,param_2,0x310000,0,local_res8,(undefined4 *)(param_1 + 0x19c));
  return;
}



===== elite_mcp_link_handler @ 14000ce74 =====

ulonglong elite_mcp_link_handler(longlong param_1,byte *param_2,char param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte bVar5;
  
  if ((*(byte *)(param_1 + 0xaca) & 2) == 0) goto LAB_14000cffb;
  register0x00000020 = (BADSPACEBASE *)mm_memset((byte *)(param_1 + 0x1d0),0x18,0);
  if (param_3 != '\0') goto LAB_14000cffb;
  uVar2 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x15c) + 4);
  bVar5 = (byte)uVar2 & 1;
  *(undefined1 *)(param_1 + 0x1d8) = 1;
  *(byte *)(param_1 + 0x1d0) = bVar5;
  uVar4 = uVar2 & 0x1e;
  if (uVar4 == 2) {
    *(undefined1 *)(param_1 + 0x1d8) = 0;
LAB_14000cf5a:
    *(undefined4 *)(param_1 + 0x1d4) = 1000;
  }
  else {
    if (uVar4 == 4) goto LAB_14000cf5a;
    if (uVar4 == 6) {
      *(undefined4 *)(param_1 + 0x1d4) = 10000;
    }
    else if (uVar4 == 8) {
      *(undefined4 *)(param_1 + 0x1d4) = 20000;
    }
    else if (uVar4 == 10) {
      *(undefined4 *)(param_1 + 0x1d4) = 40000;
    }
    else if (uVar4 == 0xc) {
      *(undefined4 *)(param_1 + 0x1d4) = 50000;
    }
    else if (uVar4 == 0xe) {
      *(undefined4 *)(param_1 + 0x1d4) = 100000;
    }
    else {
      uVar3 = 25000;
      if (uVar4 != 0x10) {
        uVar3 = 0;
      }
      *(undefined4 *)(param_1 + 0x1d4) = uVar3;
    }
  }
  *(byte *)(param_1 + 0x1d9) = (byte)(uVar2 >> 5) & 1;
  *(byte *)(param_1 + 0x1da) = (byte)(uVar2 >> 6) & 1;
  *(byte *)(param_1 + 0x1db) = (byte)(uVar2 >> 7) & 1;
  *(byte *)(param_1 + 0x1dc) = (byte)(uVar2 >> 8) & 1;
  *(uint *)(param_1 + 0x1e0) =
       *(uint *)(param_1 + 0x1e0) | uVar2 >> 10 & 1 | uVar2 >> 9 & 0x7c | uVar2 >> 8 & 2;
  *(byte *)(param_1 + 0x1e4) = (byte)(uVar2 >> 0x15) & 1;
  *(byte *)(param_1 + 0x1e5) = (byte)(uVar2 >> 0x16) & 1;
  uVar4 = uVar2 & 0xc0000;
  if (uVar4 == 0x40000) {
    *(undefined1 *)(param_1 + 0x1e6) = 1;
    uVar4 = 0x40000;
  }
  else {
    cVar1 = (uVar4 != 0x80000) + '\x02';
    uVar4 = CONCAT31((int3)(uVar4 >> 8),cVar1);
    *(char *)(param_1 + 0x1e6) = cVar1;
  }
  register0x00000020 = (BADSPACEBASE *)(ulonglong)uVar4;
  *(byte *)(param_1 + 0x1e7) = (byte)(uVar2 >> 0x14) & 1;
  *(byte *)(param_1 + 0x280) = bVar5;
LAB_14000cffb:
  return (ulonglong)register0x00000020 & 0xffffffffffffff00;
}



===== elite_mcp_load_req @ 14000d018 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 elite_mcp_load_req(longlong param_1,byte *param_2,uint *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  undefined1 auStackY_88 [32];
  undefined4 local_58 [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar3 = 0x20000;
  uVar2 = elite_mcp_do_load_req(param_1,param_2,param_3,0,0x20000);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  if (*param_3 == 0x10210000) {
    iVar5 = 0;
    uVar3 = 0x10000;
  }
  else {
    if (*param_3 != 0x10300000) goto LAB_14000d0d5;
    mm_memset(local_58,0x10,0);
    iVar5 = *(int *)(param_1 + 0x154);
    uVar4 = 0;
    lVar6 = 0;
    do {
      uVar1 = elite_rd(param_1,param_2,uVar4 + iVar5 + 0x18);
      uVar4 = uVar4 + 4;
      *(undefined4 *)((longlong)local_58 + lVar6) = uVar1;
      lVar6 = lVar6 + 4;
    } while (uVar4 < 0x10);
    iVar5 = 2;
  }
  uVar2 = elite_mcp_do_load_req(param_1,param_2,param_3,iVar5,uVar3);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
LAB_14000d0d5:
  uVar3 = *param_3;
  if ((((uVar3 == 0x11100000) || (uVar3 == 0x10100000)) || (uVar3 == 0x10110000)) ||
     (uVar3 == 0x10120000)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== elite_mcp_read_boot_protocol @ 14000d118 =====

uint elite_mcp_read_boot_protocol(longlong param_1,byte *param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar1 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | *(uint *)(param_1 + 0x30);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x30);
  }
  uVar1 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x1ac) + 0xe20ba4 + uVar1 * 0x50);
  return uVar1 & 7;
}



===== elite_mcp_read_core_config @ 14000d158 =====

undefined8 elite_mcp_read_core_config(longlong param_1,byte *param_2)

{
  byte bVar1;
  
  bVar1 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x1ac) + 0xe2002c);
  if (bVar1 < 6) {
    if (bVar1 != 5) {
      if (bVar1 == 0) {
        *(undefined4 *)(param_1 + 0x48) = 0;
        return 0;
      }
      if (bVar1 == 1) {
        *(undefined4 *)(param_1 + 0x48) = 1;
        return 0;
      }
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 0x48) = 2;
        return 0;
      }
      if (bVar1 == 3) {
        *(undefined4 *)(param_1 + 0x48) = 3;
        return 0;
      }
      if (bVar1 == 4) {
        *(undefined4 *)(param_1 + 0x48) = 4;
        return 0;
      }
      return 1;
    }
  }
  else {
    if (bVar1 == 0xb) {
      *(undefined4 *)(param_1 + 0x48) = 6;
      return 0;
    }
    if ((bVar1 != 0xc) && (bVar1 != 0xd)) {
      if (bVar1 == 0xe) {
        *(undefined4 *)(param_1 + 0x48) = 9;
        return 0;
      }
      if (bVar1 == 0xf) {
        *(undefined4 *)(param_1 + 0x48) = 10;
        return 0;
      }
      return 1;
    }
  }
  *(undefined4 *)(param_1 + 0x48) = 5;
  return 0;
}



===== elite_mcp_read_func_info @ 14000d20c =====

int elite_mcp_read_func_info(longlong param_1,byte *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint local_res8 [2];
  undefined4 local_res18 [4];
  
  uVar2 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x150) + 0x18);
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar8 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | *(uint *)(param_1 + 0x30);
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x30);
  }
  iVar7 = (uVar2 >> 0xe & 0x3fffc) * uVar8 + (uVar2 & 0xffff) * 4;
  uVar2 = elite_rd(param_1,param_2,iVar7 + 0xe20028);
  *(byte *)(param_1 + 0xb0) = (byte)(uVar2 >> 1) & 1;
  uVar8 = uVar2 & 0xf0;
  if (uVar8 == 0) {
    *(undefined1 *)(param_1 + 0xb1) = 1;
  }
  else if (uVar8 == 0x10) {
    *(undefined1 *)(param_1 + 0xb1) = 4;
  }
  else if (uVar8 == 0x20) {
    *(undefined1 *)(param_1 + 0xb1) = 8;
  }
  else {
    if (uVar8 != 0x30) {
      return 3;
    }
    *(undefined1 *)(param_1 + 0xb1) = 2;
  }
  *(char *)(param_1 + 0xb3) = (char)(uVar2 >> 0x10);
  *(char *)(param_1 + 0xb2) = (char)(uVar2 >> 8);
  iVar3 = elite_rd(param_1,param_2,iVar7 + 0xe20030);
  iVar4 = elite_rd(param_1,param_2,iVar7 + 0xe20034);
  if ((iVar3 == 0) && (iVar4 == 0)) {
    return 3;
  }
  *(char *)(param_1 + 0xb9) = (char)iVar4;
  *(char *)(param_1 + 0xb4) = (char)((uint)iVar3 >> 8);
  *(char *)(param_1 + 0xb5) = (char)iVar3;
  *(char *)(param_1 + 0xb6) = (char)((uint)iVar4 >> 0x18);
  *(char *)(param_1 + 0xb7) = (char)((uint)iVar4 >> 0x10);
  *(char *)(param_1 + 0xb8) = (char)((uint)iVar4 >> 8);
  uVar5 = elite_rd(param_1,param_2,iVar7 + 0xe20038);
  uVar6 = elite_rd(param_1,param_2,iVar7 + 0xe2003c);
  *(undefined4 *)(param_1 + 0x138) = uVar5;
  *(undefined4 *)(param_1 + 0x134) = uVar6;
  uVar5 = elite_rd(param_1,param_2,iVar7 + 0xe20040);
  uVar6 = elite_rd(param_1,param_2,iVar7 + 0xe20044);
  *(undefined4 *)(param_1 + 0x140) = uVar5;
  *(undefined4 *)(param_1 + 0x13c) = uVar6;
  uVar1 = elite_rd(param_1,param_2,iVar7 + 0xe20048);
  *(undefined2 *)(param_1 + 0x14a) = uVar1;
  uVar5 = elite_rd(param_1,param_2,iVar7 + 0xe20008);
  *(undefined4 *)(param_1 + 0x144) = uVar5;
  *(undefined1 *)(param_1 + 0x148) = 0;
  if (*(int *)(param_1 + 0x150) != 0) {
    iVar7 = elite_issue_mcp_cmd(param_1,param_2,0x2e0000,0,local_res8,local_res18);
    if (iVar7 != 0) {
      return iVar7;
    }
    if (local_res8[0] == 0x800000) {
      *(undefined1 *)(param_1 + 0x148) = 1;
    }
  }
  *(undefined1 *)(param_1 + 0x149) = 0;
  return 0;
}



===== elite_mcp_read_vlan_setting @ 14000d434 =====

undefined8 elite_mcp_read_vlan_setting(longlong param_1,byte *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar1 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | *(uint *)(param_1 + 0x30);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x30);
  }
  uVar1 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x1ac) + 0xe20bbc + uVar1 * 0x50);
  if (((uVar1 >> 0x10 & 1) == 0) || (0xffd < (uVar1 & 0xffff) - 1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== elite_mcp_set_capab @ 14000d494 =====

void elite_mcp_set_capab(longlong param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_res8 [4];
  uint local_res18 [4];
  
  uVar1 = *(uint *)(param_1 + 0x19c) & 1;
  uVar2 = uVar1 | 2;
  if ((*(uint *)(param_1 + 0x19c) & 2) == 0) {
    uVar2 = uVar1;
  }
  elite_issue_mcp_cmd(param_1,param_2,0x300000,uVar2,local_res18,local_res8);
  return;
}



===== elite_mcp_update_bw @ 14000d4d8 =====

void elite_mcp_update_bw(longlong param_1,byte *param_2)

{
  undefined2 extraout_var;
  uint uVar1;
  uint uVar2;
  uint local_res8 [2];
  undefined4 local_res18 [4];
  
  local_res8[0] = 0;
  uVar1 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x150) + 0x18);
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar2 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | *(uint *)(param_1 + 0x30);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x30);
  }
  elite_rd(param_1,param_2,(uVar1 >> 0xe & 0x3fffc) * uVar2 + ((uVar1 & 0xffff) + 0x38800a) * 4);
  *(char *)(param_1 + 0xb3) = (char)((ushort)extraout_var >> 8);
  *(char *)(param_1 + 0xb2) = (char)extraout_var;
  elite_issue_mcp_cmd(param_1,param_2,0x32000000,0,local_res8,local_res18);
  return;
}



===== elite_mcp_update_stag @ 14000d580 =====

void elite_mcp_update_stag(longlong param_1,byte *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint local_res8 [2];
  undefined4 local_res18 [4];
  
  local_res8[0] = 0;
  uVar2 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x150) + 0x18);
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar3 = (*(uint *)(param_1 + 0x2c) & 1) << 3 | *(uint *)(param_1 + 0x30);
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x30);
  }
  uVar1 = elite_rd(param_1,param_2,
                   (uVar2 >> 0xe & 0x3fffc) * uVar3 + ((uVar2 & 0xffff) + 0x388012) * 4);
  *(undefined2 *)(param_1 + 0x14a) = uVar1;
  elite_issue_mcp_cmd(param_1,param_2,0x3b000000,0,local_res8,local_res18);
  return;
}



===== elite_set_link_mcp @ 14000d61c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 elite_set_link_mcp(longlong param_1,byte *param_2,char param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 auStackY_78 [32];
  uint local_48;
  undefined4 local_44;
  uint local_40 [8];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar2 = 0;
  local_48 = 0;
  if (*(int *)(param_1 + 0x150) == 0) {
    uVar1 = 1;
  }
  else {
    mm_memset(local_40,0x20,0);
    if (*(char *)(param_1 + 0x1bc) == '\0') {
      local_40[0] = *(uint *)(param_1 + 0x1c4);
    }
    local_40[1] = local_40[1] |
                  -(uint)(*(char *)(param_1 + 0x1ca) != '\0') & 4 |
                  -(uint)(*(char *)(param_1 + 0x1c9) != '\0') & 2 |
                  (uint)(*(char *)(param_1 + 0x1c8) != '\0');
    local_40[2] = *(undefined4 *)(param_1 + 0x1c0);
    local_40[3] = *(undefined4 *)(param_1 + 0x1cc);
    do {
      elite_wr(param_1,param_2,*(int *)(param_1 + 0x154) + 0x18 + uVar2,
               local_40[(longlong)(int)uVar2 >> 2]);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x20);
    uVar1 = elite_issue_mcp_cmd(param_1,param_2,(-(uint)(param_3 != '\0') & 0xff000000) + 0x23000000
                                ,0,&local_48,&local_44);
  }
  return uVar1;
}



===== elite_wait_for_stable_link @ 14000d73c =====

void elite_wait_for_stable_link(longlong param_1,byte *param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = *(int *)(param_1 + 0x1b4) * 1000;
  uVar6 = 0;
  iVar4 = 0;
  if (*(char *)(param_1 + 0x280) != '\x01') {
    uVar8 = 0;
    if ((*(uint *)(param_1 + 0x19c) & 8) != 0) {
      do {
        uVar3 = elite_rd(param_1,param_2,*(int *)(param_1 + 0x15c) + 8);
        uVar3 = uVar3 & 3;
        if (1 < uVar3) break;
        uVar5 = uVar6;
        if ((uVar8 != 1) && (uVar3 == 1)) {
          uVar5 = 0;
        }
        mm_delay(1000);
        uVar6 = uVar5 + 1;
        uVar8 = uVar3;
      } while (uVar5 < 3000);
      if (uVar3 == 3) {
        return;
      }
    }
    bVar1 = false;
    uVar6 = 0;
    if (uVar7 == 0) {
      uVar7 = 12000;
    }
    do {
      elite_mcp_link_handler(param_1,param_2,'\0');
      uVar8 = uVar6;
      bVar2 = bVar1;
      if (*(char *)(param_1 + 0x280) == '\x01') {
        if (bVar1) {
          if (4999 < iVar4 + 1U) {
            return;
          }
        }
        else {
          uVar8 = 0;
          bVar2 = true;
        }
        if (bVar1) {
          iVar4 = iVar4 + 1;
        }
      }
      else {
        iVar4 = 0;
      }
      bVar1 = bVar2;
      mm_delay(1000);
      uVar6 = uVar8 + 1;
    } while (uVar8 < uVar7);
  }
  return;
}



===== comp_and @ 14000d860 =====

bool comp_and(uint param_1,uint param_2)

{
  return (param_1 & param_2) == param_2;
}



===== comp_eq @ 14000d870 =====

bool comp_eq(int param_1,int param_2)

{
  return param_1 == param_2;
}



===== comp_or @ 14000d880 =====

bool comp_or(int param_1,int param_2)

{
  return param_1 != 0 || param_2 != 0;
}



===== elite_gtt_init @ 14000d888 =====

void elite_gtt_init(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  int *piVar3;
  
  piVar3 = &DAT_14002d290;
  uVar2 = 0;
  uVar1 = 0x200;
  do {
    if (*piVar3 != 0) {
      mm_pci_mem_write(param_1,0,uVar1,&DAT_14002d290 + uVar2);
    }
    uVar2 = (ulonglong)((int)uVar2 + 1);
    uVar1 = uVar1 + 4;
    piVar3 = piVar3 + 1;
  } while (uVar1 < 0x24c);
  return;
}



===== elite_init_array_dmae @ 14000d8f8 =====

undefined4
elite_init_array_dmae
          (longlong param_1,byte *param_2,uint param_3,ulonglong param_4,uint param_5,
          longlong param_6,char param_7,char param_8)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  
  uVar2 = (ulonglong)param_5;
  uVar1 = 0;
  if ((param_8 == '\0') || ((param_7 == '\0' && (param_5 < 0x10)))) {
    puVar3 = (undefined4 *)(param_6 + (param_4 & 0xffffffff) * 4);
    if (param_5 != 0) {
      do {
        elite_wr(param_1,param_2,param_3,*puVar3);
        param_3 = param_3 + 4;
        puVar3 = puVar3 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
  }
  else {
    uVar1 = elite_dmae_host2grc(param_1,param_2,(void *)(param_6 + (param_4 & 0xffffffff) * 4),
                                param_3,param_5,0);
  }
  return uVar1;
}



===== elite_init_cmd_array @ 14000d9ac =====

int elite_init_cmd_array(longlong param_1,byte *param_2,uint *param_3,char param_4,char param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = param_3[1];
  iVar3 = 0;
  uVar6 = *param_3 >> 7 & 0x1fffffc;
  uVar2 = *(uint *)(&DAT_14001daa0 + (ulonglong)uVar1 * 4);
  if ((uVar2 & 0xf) == 0) {
    iVar3 = elite_init_array_dmae
                      (param_1,param_2,uVar6,(ulonglong)(uVar1 + 1),uVar2 >> 4,0x14001daa0,param_4,
                       param_5);
  }
  else if ((uVar2 & 0xf) == 2) {
    uVar5 = 0;
    uVar4 = uVar2 >> 4 & 0xf;
    if (uVar2 >> 8 != 0) {
      do {
        iVar3 = elite_init_array_dmae
                          (param_1,param_2,uVar6,(ulonglong)(uVar1 + 1),uVar4,0x14001daa0,param_4,
                           param_5);
        if (iVar3 != 0) {
          return iVar3;
        }
        uVar6 = uVar6 + uVar4 * 4;
        uVar5 = uVar5 + 1;
        iVar3 = 0;
      } while (uVar5 < uVar2 >> 8);
    }
  }
  return iVar3;
}



===== elite_init_cmd_mode_match @ 14000dab0 =====

byte elite_init_cmd_mode_match(undefined8 param_1,ushort *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = (&DAT_14002bd00)[*param_2];
  *param_2 = *param_2 + 1;
  if (bVar2 == 0) {
    bVar2 = elite_init_cmd_mode_match(param_1,param_2,param_3);
    bVar2 = bVar2 ^ 1;
  }
  else if (bVar2 == 1) {
    bVar1 = elite_init_cmd_mode_match(param_1,param_2,param_3);
    bVar2 = elite_init_cmd_mode_match(param_1,param_2,param_3);
    bVar2 = bVar2 | bVar1;
  }
  else if (bVar2 == 2) {
    bVar1 = elite_init_cmd_mode_match(param_1,param_2,param_3);
    bVar2 = elite_init_cmd_mode_match(param_1,param_2,param_3);
    bVar2 = bVar2 & bVar1;
  }
  else {
    bVar2 = (param_3 >> (bVar2 - 3 & 0x1f) & 1) != 0;
  }
  return bVar2;
}



===== elite_init_cmd_rd @ 14000db5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void elite_init_cmd_rd(longlong param_1,byte *param_2,uint *param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = *param_3;
  uVar5 = uVar3 >> 7 & 0x1fffffc;
  uVar2 = elite_rd(param_1,param_2,uVar5);
  uVar3 = uVar3 >> 4 & 0xf;
  if (uVar3 != 0) {
    if (uVar3 == 1) {
      pcVar4 = comp_eq;
    }
    else if (uVar3 == 2) {
      pcVar4 = comp_or;
    }
    else {
      if (uVar3 != 3) {
        return;
      }
      pcVar4 = comp_and;
    }
    uVar3 = param_3[1];
    iVar6 = 0;
    do {
      cVar1 = (*pcVar4)(uVar2,uVar3);
      if (cVar1 != '\0') {
        return;
      }
      mm_delay(500);
      uVar2 = elite_rd(param_1,param_2,uVar5);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 100);
  }
  return;
}



===== elite_init_cmd_wr @ 14000dc14 =====

int elite_init_cmd_wr(longlong param_1,byte *param_2,uint *param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  byte bVar6;
  
  uVar1 = *param_3;
  iVar3 = 0;
  uVar5 = uVar1 >> 7 & 0x1fffffc;
  bVar6 = (byte)(uVar1 >> 8);
  if (((uVar1 & 0x100) != 0) && (param_4 == '\0')) {
    return 0;
  }
  uVar2 = uVar1 >> 4 & 7;
  if (uVar2 == 0) {
    elite_wr(param_1,param_2,uVar5,param_3[1]);
  }
  else if (uVar2 == 1) {
    uVar2 = param_3[1];
    uVar4 = (ulonglong)uVar2;
    if (((uVar1 & 0x100) == 0) && ((param_4 == '\0' || (uVar2 < 0x40)))) {
      if (uVar2 == 0) {
        return 0;
      }
      do {
        elite_wr(param_1,param_2,uVar5,0);
        uVar5 = uVar5 + 4;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      return 0;
    }
    mm_memset(&DAT_140071400,0x1000,0);
    iVar3 = elite_dmae_host2grc(param_1,param_2,&DAT_140071400,uVar5,uVar2,1);
  }
  else {
    if (uVar2 != 2) {
      if (uVar2 == 3) {
        elite_init_rt(param_1,param_2,uVar5,*(ushort *)((longlong)param_3 + 6),(ushort)param_3[1],
                      bVar6 & 1);
        return 0;
      }
      return 0;
    }
    iVar3 = elite_init_cmd_array(param_1,param_2,param_3,bVar6 & 1,param_4);
  }
  return iVar3;
}



===== elite_init_rt @ 14000dd40 =====

undefined8
elite_init_rt(longlong param_1,byte *param_2,int param_3,ushort param_4,ushort param_5,char param_6)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  ushort uVar6;
  ushort uVar7;
  longlong lVar8;
  
  uVar6 = 0;
  lVar8 = (ulonglong)param_4 * 4 + param_1;
  lVar1 = param_1 + 0x2a8 + (ulonglong)param_4 * 4;
  if (param_5 != 0) {
    do {
      uVar5 = (ulonglong)uVar6;
      if (*(int *)(lVar8 + 0x518 + uVar5 * 4) != 0) {
        uVar4 = (uint)uVar6;
        if (param_6 == '\0') {
          elite_wr(param_1,param_2,param_3 + uVar4 * 4,*(undefined4 *)(lVar1 + uVar5 * 4));
        }
        else {
          uVar2 = uVar4 + 1;
          uVar7 = 1;
          while ((uVar2 < param_5 && (*(int *)(lVar8 + 0x518 + (ulonglong)uVar2 * 4) != 0))) {
            uVar7 = uVar7 + 1;
            uVar2 = uVar7 + uVar4;
          }
          uVar3 = elite_dmae_host2grc(param_1,param_2,(void *)(uVar5 * 4 + lVar1),
                                      param_3 + uVar4 * 4,(uint)uVar7,0);
          if ((int)uVar3 != 0) {
            return uVar3;
          }
          uVar6 = uVar6 + uVar7;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_5);
  }
  return 0;
}



===== elite_init_run @ 14000de5c =====

int elite_init_run(longlong param_1,byte *param_2,uint param_3,uint param_4,uint param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  byte bVar5;
  uint *puVar6;
  ushort local_28 [8];
  
  iVar3 = 0;
  bVar5 = 0;
  uVar4 = 0;
  do {
    puVar6 = &DAT_14001a220 + uVar4 * 2;
    uVar2 = *puVar6 & 0xf;
    if (uVar2 == 0) {
      elite_init_cmd_rd(param_1,param_2,puVar6);
LAB_14000df51:
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    else {
      if (uVar2 == 1) {
        iVar3 = elite_init_cmd_wr(param_1,param_2,puVar6,bVar5);
        goto LAB_14000df51;
      }
      if (uVar2 == 2) {
        local_28[0] = *(ushort *)((longlong)&DAT_14001a224 + uVar4 * 8 + 2);
        bVar1 = elite_init_cmd_mode_match(param_1,local_28,param_5);
        if (bVar1 == 0) {
          uVar2 = (uint)*(ushort *)((longlong)puVar6 + 2);
        }
        else {
          uVar2 = 0;
        }
        uVar4 = (ulonglong)((int)uVar4 + uVar2);
      }
      else if (uVar2 == 3) {
        if ((((&DAT_14001a224)[uVar4 * 2] & 0xff) == param_3) &&
           ((uVar2 = (uint)(&DAT_14001a224)[uVar4 * 2] >> 0x10, uVar2 == 0xffff ||
            (uVar2 == param_4)))) {
          uVar2 = 0;
        }
        else {
          uVar2 = (uint)*(ushort *)((longlong)&DAT_14001a220 + uVar4 * 8 + 2);
        }
        uVar4 = (ulonglong)((int)uVar4 + uVar2);
        bVar5 = (byte)(*puVar6 >> 4) & 1;
      }
      else if (uVar2 == 4) {
        mm_delay((&DAT_14001a224)[uVar4 * 2]);
      }
    }
    uVar2 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar2;
    if (0x70e < uVar2) {
      return iVar3;
    }
  } while( true );
}



===== elite_init_store_rt_agg @ 14000df84 =====

void elite_init_store_rt_agg(longlong param_1,ulonglong param_2,longlong param_3,ulonglong param_4)

{
  longlong lVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  
  uVar3 = param_4 >> 2;
  if (uVar3 != 0) {
    lVar1 = (param_2 & 0xffffffff) * 4 + 0x518;
    puVar2 = (undefined4 *)(lVar1 + param_1);
    do {
      puVar2[-0x9c] = *(undefined4 *)(((param_3 - lVar1) - param_1) + (longlong)puVar2);
      *puVar2 = 1;
      puVar2 = puVar2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}



===== elite_init_store_rt_reg @ 14000dfbc =====

void elite_init_store_rt_reg(longlong param_1,uint param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x2a8 + (ulonglong)param_2 * 4) = param_3;
  *(undefined4 *)(param_1 + 0x518 + (ulonglong)param_2 * 4) = 1;
  return;
}



===== elite_dma_info_alloc @ 14000dfd4 =====

undefined8 elite_dma_info_alloc(longlong param_1)

{
  mm_dma_alloc(param_1,(longlong *)(param_1 + 0x250),(longlong *)(param_1 + 0x248),8);
  if (((*(longlong *)(param_1 + 0x250) == 0) ||
      (mm_dma_alloc(param_1,(longlong *)(param_1 + 0x270),(longlong *)(param_1 + 0x268),0x38),
      *(longlong *)(param_1 + 0x270) == 0)) ||
     (mm_dma_alloc(param_1,(longlong *)(param_1 + 0x260),(longlong *)(param_1 + 600),0x1000),
     *(longlong *)(param_1 + 0x260) == 0)) {
    return 1;
  }
  *(undefined1 *)(param_1 + 0x240) = *(undefined1 *)(param_1 + 0x30);
  return 0;
}



===== elite_dmae_execute_command @ 14000e080 =====

ulonglong elite_dmae_execute_command
                    (longlong param_1,byte *param_2,void *param_3,int param_4,char param_5,
                    char param_6,uint param_7,uint *param_8)

{
  uint *puVar1;
  undefined8 uVar2;
  ushort uVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  void *pvVar7;
  ushort uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  puVar1 = *(uint **)(param_1 + 0x270);
  uVar8 = 0;
  uVar2 = *(undefined8 *)(param_1 + 0x248);
  *puVar1 = 0;
  *(undefined2 *)((longlong)puVar1 + 0x16) = 0;
  uVar10 = 0;
  *puVar1 = *puVar1 | (uint)(param_5 == '\x02');
  uVar6 = 2;
  if (param_6 == '\x02') {
    uVar6 = 4;
  }
  uVar6 = (*(uint *)(param_1 + 0x30) & 0xf) << 0x14 | uVar6 | *puVar1;
  *puVar1 = uVar6;
  uVar6 = (*(uint *)(param_1 + 0x30) & 0xf) << 0x18 | uVar6;
  uVar9 = uVar6 | 0x120;
  *puVar1 = uVar9;
  if ((*param_8 & 8) != 0) {
    uVar9 = uVar6 | 0x1a0;
  }
  *puVar1 = uVar9 | 0x8000;
  uVar6 = *(int *)(param_1 + 0x34) << 0x12 | uVar9 | 0x8000;
  *puVar1 = uVar6 | 0x40;
  if ((*param_8 & 2) == 0) {
    uVar3 = 0xff;
  }
  else {
    *puVar1 = uVar6 | 0x10000040;
    uVar3 = (ushort)(byte)param_8[1];
  }
  *(ushort *)((longlong)puVar1 + 0x16) = *(ushort *)((longlong)puVar1 + 0x16) | uVar3;
  if ((*param_8 & 4) == 0) {
    *(ushort *)((longlong)puVar1 + 0x16) = *(ushort *)((longlong)puVar1 + 0x16) | 0xff00;
  }
  else {
    *puVar1 = *puVar1 | 0x20000000;
    *(ushort *)((longlong)puVar1 + 0x16) =
         *(ushort *)((longlong)puVar1 + 0x16) | (ushort)*(byte *)((longlong)param_8 + 5) << 8;
  }
  puVar1[6] = (uint)uVar2;
  puVar1[7] = (uint)((ulonglong)uVar2 >> 0x20);
  puVar1[8] = 0xd1ae;
  uVar6 = 0;
  pvVar7 = param_3;
  do {
    uVar9 = uVar6 << 10;
    if ((*param_8 & 1) == 0) {
      if (param_5 != '\x02') {
        uVar9 = uVar6 << 0xc;
      }
      pvVar7 = (void *)((ulonglong)uVar9 + (longlong)param_3);
    }
    iVar4 = 0x1000;
    if (param_6 == '\x02') {
      iVar4 = 0x400;
    }
    uVar3 = 0x400;
    if (param_7 >> 10 == uVar6) {
      uVar3 = (ushort)param_7 & 0x3ff;
    }
    if (uVar3 != 0) {
      uVar5 = elite_dmae_execute_sub_operation
                        (param_1,param_2,pvVar7,(void *)(ulonglong)(param_4 + iVar4 * uVar6),param_5
                         ,param_6,(uint)uVar3);
      uVar10 = uVar5 & 0xffffffff;
      if ((int)uVar5 != 0) {
        return uVar10;
      }
    }
    uVar8 = uVar8 + 1;
    uVar6 = (uint)uVar8;
  } while (uVar6 <= param_7 >> 10);
  return uVar10;
}



===== elite_dmae_execute_sub_operation @ 14000e278 =====

undefined8
elite_dmae_execute_sub_operation
          (longlong param_1,byte *param_2,void *param_3,void *param_4,char param_5,char param_6,
          uint param_7)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  pvVar4 = *(void **)(param_1 + 600);
  lVar1 = *(longlong *)(param_1 + 0x270);
  uVar3 = SUB84(pvVar4,0);
  if (param_5 == '\0') {
    *(undefined4 *)(lVar1 + 4) = uVar3;
    *(int *)(lVar1 + 8) = (int)((ulonglong)pvVar4 >> 0x20);
    mm_memcpy(*(void **)(param_1 + 0x260),param_3,(ulonglong)param_7 << 2);
LAB_14000e301:
    if (param_6 != '\0') {
      if (1 < (byte)(param_6 - 1U)) goto LAB_14000e379;
      uVar3 = SUB84(param_4,0);
      pvVar4 = param_4;
    }
    *(int *)(lVar1 + 0x10) = (int)((ulonglong)pvVar4 >> 0x20);
    *(undefined4 *)(lVar1 + 0xc) = uVar3;
    *(short *)(lVar1 + 0x14) = (short)param_7;
    elite_dmae_post_command(param_1,param_2);
    uVar2 = elite_dmae_operation_wait(param_1);
    if ((int)uVar2 == 0) {
      if (param_6 == '\0') {
        mm_memcpy(param_4,*(void **)(param_1 + 0x260),(ulonglong)param_7 << 2);
      }
      uVar2 = 0;
    }
  }
  else {
    if ((byte)(param_5 - 1U) < 2) {
      *(void **)(lVar1 + 4) = param_3;
      goto LAB_14000e301;
    }
LAB_14000e379:
    uVar2 = 1;
  }
  return uVar2;
}



===== elite_dmae_host2grc @ 14000e380 =====

void elite_dmae_host2grc(longlong param_1,byte *param_2,void *param_3,uint param_4,uint param_5,
                        uint param_6)

{
  uint local_18 [4];
  
  mm_memset(local_18,8,0);
  local_18[0] = param_6;
  elite_dmae_execute_command(param_1,param_2,param_3,param_4 >> 2,'\0','\x02',param_5,local_18);
  return;
}



===== elite_dmae_operation_wait @ 14000e404 =====

undefined8 elite_dmae_operation_wait(longlong param_1)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = *(int **)(param_1 + 0x250);
  uVar2 = 0;
  while( true ) {
    if (*piVar1 == 0xd1ae) {
      *piVar1 = 0;
      return 0;
    }
    mm_delay(2);
    uVar2 = uVar2 + 1;
    if (10000 < uVar2) break;
    piVar1 = *(int **)(param_1 + 0x250);
  }
  return 1;
}



===== elite_dmae_post_command @ 14000e464 =====

undefined8 elite_dmae_post_command(longlong param_1,byte *param_2)

{
  byte bVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 uVar5;
  
  puVar3 = *(undefined4 **)(param_1 + 0x270);
  bVar1 = *(byte *)(param_1 + 0x240);
  if (((puVar3[3] == 0) && (puVar3[4] == 0)) || ((puVar3[1] == 0 && (puVar3[2] == 0)))) {
    uVar2 = 1;
  }
  else {
    bVar4 = 0;
    do {
      if (bVar4 < 9) {
        uVar5 = *puVar3;
      }
      else {
        uVar5 = 0;
      }
      elite_wr(param_1,param_2,((uint)bVar4 + (uint)bVar1 * 0xe) * 4 + 0xc800,uVar5);
      bVar4 = bVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (bVar4 < 0xe);
    elite_wr(param_1,param_2,(uint)bVar1 * 4 + 0xc048,1);
    uVar2 = 0;
  }
  return uVar2;
}



===== elite_alloc_status_block @ 14000e524 =====

undefined8 elite_alloc_status_block(longlong param_1)

{
  undefined8 uVar1;
  longlong local_res8;
  longlong local_res10 [3];
  
  local_res8 = 0;
  uVar1 = mm_dma_alloc(param_1,&local_res8,local_res10,0x20);
  if ((int)uVar1 == 0) {
    *(longlong *)(param_1 + 0xaa8) = local_res8;
    *(longlong *)(param_1 + 0xab0) = local_res10[0];
    uVar1 = 0;
  }
  return uVar1;
}



===== elite_cfc_delete @ 14000e56c =====

void elite_cfc_delete(longlong param_1,undefined2 param_2)

{
  undefined4 local_res8 [2];
  undefined4 local_res10;
  uint local_28;
  undefined1 local_24;
  undefined4 *local_20;
  undefined4 local_18;
  
  mm_memset(local_res8,8,0);
  local_20 = local_res8;
  local_res10 = CONCAT22(*(undefined2 *)(param_1 + 0x24),param_2);
  local_18 = local_res10;
  local_res8[0] = local_res10;
  local_24 = 6;
  local_28 = 8;
  elite_sp_post(param_1,&local_28);
  return;
}



===== elite_config_cau_sb @ 14000e5d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 elite_config_cau_sb(longlong param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  uint local_44;
  undefined4 local_40 [12];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  pbVar1 = (byte *)(param_1 + 0x284);
  mm_memset(&local_48,8,0);
  local_44 = *(int *)(param_1 + 0x30) << 0x1b | local_44 & 0x8003ffff;
  iVar2 = (uint)*(ushort *)(param_1 + 0xabc) * 8;
  elite_wr(param_1,pbVar1,iVar2 + 0x1c8000,*(undefined4 *)(param_1 + 0xab0));
  elite_wr(param_1,pbVar1,iVar2 + 0x1c8004,
           (int)((ulonglong)*(undefined8 *)(param_1 + 0xab0) >> 0x20));
  iVar2 = (uint)*(ushort *)(param_1 + 0xabc) * 8;
  elite_wr(param_1,pbVar1,iVar2 + 0x1c6000,local_48);
  elite_wr(param_1,pbVar1,iVar2 + 0x1c6004,local_44);
  mm_memset(local_40,0x30,0);
  bVar3 = 0;
  puVar4 = local_40;
  do {
    elite_wr(param_1,pbVar1,((uint)bVar3 + (uint)*(ushort *)(param_1 + 0xabc) * 0xc) * 4 + 0x1d0000,
             *puVar4);
    bVar3 = bVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (bVar3 < 0xc);
  return 0;
}



===== elite_config_sb @ 14000e714 =====

undefined8 elite_config_sb(longlong param_1)

{
  *(ushort *)(param_1 + 0xabc) = *(ushort *)(param_1 + 0x4c);
  *(uint *)(param_1 + 0xac0) = (uint)*(ushort *)(param_1 + 0x4c) * 8 + 0xf000;
  mm_memset(*(void **)(param_1 + 0xaa8),0x20,0);
  elite_config_cau_sb(param_1);
  return 0;
}



===== elite_has_rx_work @ 14000e75c =====

undefined8 elite_has_rx_work(longlong param_1)

{
  return CONCAT71((int7)((ulonglong)*(short **)(param_1 + 0x7f8) >> 8),
                  **(short **)(param_1 + 0x7f8) != *(short *)(param_1 + 0x7ee));
}



===== elite_has_tx_work @ 14000e774 =====

undefined8 elite_has_tx_work(longlong param_1)

{
  return CONCAT71((int7)((ulonglong)*(short **)(param_1 + 0x960) >> 8),
                  **(short **)(param_1 + 0x960) != *(short *)(param_1 + 0x956));
}



===== elite_process_rx_pkt @ 14000e78c =====

short elite_process_rx_pkt(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  short sVar7;
  
  sVar7 = 0;
  sVar1 = **(short **)(param_1 + 0x7f8);
  sVar6 = *(short *)(param_1 + 0x7ee);
  while ((sVar1 != sVar6 && (*(int *)(param_1 + 0x800) != 0))) {
    iVar4 = *(int *)(param_1 + 0x8d8);
    if (iVar4 == 0) {
      iVar4 = *(int *)(param_1 + 0x8e0);
    }
    *(int *)(param_1 + 0x8e4) = *(int *)(param_1 + 0x8e4) + -1;
    uVar5 = iVar4 - 1;
    *(uint *)(param_1 + 0x8d8) = uVar5;
    lVar2 = *(longlong *)(param_1 + 0x8e8 + (ulonglong)uVar5 * 8);
    *(undefined8 *)(param_1 + 0x8e8 + (ulonglong)uVar5 * 8) = 0;
    if (lVar2 == 0) break;
    *(int *)(param_1 + 0x800) = *(int *)(param_1 + 0x800) + -1;
    pcVar3 = *(char **)(lVar2 + 0x18);
    if (*pcVar3 == '\x01') {
      *(char *)(lVar2 + 0x10) = pcVar3[1];
      *(undefined2 *)(lVar2 + 0xe) = *(undefined2 *)(pcVar3 + 2);
      iVar4 = *(int *)(param_1 + 0x90c);
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x910);
      }
      *(longlong *)(param_1 + 0x918 + (ulonglong)(iVar4 - 1U) * 8) = lVar2;
      *(int *)(param_1 + 0x914) = *(int *)(param_1 + 0x914) + 1;
      *(uint *)(param_1 + 0x90c) = iVar4 - 1U;
    }
    sVar6 = sVar6 + 1;
    sVar7 = sVar7 + 1;
  }
  *(short *)(param_1 + 0x7ee) = sVar6;
  return sVar7;
}



===== elite_process_tx_completions @ 14000e870 =====

short elite_process_tx_completions(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  short sVar6;
  
  sVar6 = 0;
  sVar1 = **(short **)(param_1 + 0x960);
  sVar5 = *(short *)(param_1 + 0x956);
  while (sVar5 != sVar1) {
    iVar3 = *(int *)(param_1 + 0xa40);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0xa48);
    }
    *(int *)(param_1 + 0xa4c) = *(int *)(param_1 + 0xa4c) + -1;
    uVar4 = iVar3 - 1;
    *(uint *)(param_1 + 0xa40) = uVar4;
    lVar2 = *(longlong *)(param_1 + 0xa50 + (ulonglong)uVar4 * 8);
    *(undefined8 *)(param_1 + 0xa50 + (ulonglong)uVar4 * 8) = 0;
    if (lVar2 == 0) break;
    *(int *)(param_1 + 0x968) = *(int *)(param_1 + 0x968) + 1;
    sVar5 = sVar5 + 1;
    iVar3 = *(int *)(param_1 + 0xa74);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0xa78);
    }
    sVar6 = sVar6 + 1;
    *(longlong *)(param_1 + 0xa80 + (ulonglong)(iVar3 - 1U) * 8) = lVar2;
    *(int *)(param_1 + 0xa7c) = *(int *)(param_1 + 0xa7c) + 1;
    *(uint *)(param_1 + 0xa74) = iVar3 - 1U;
  }
  *(short *)(param_1 + 0x956) = sVar5;
  return sVar6;
}



===== elite_replenish_bd_chain @ 14000e920 =====

short elite_replenish_bd_chain(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  short sVar7;
  
  uVar6 = *(ushort *)((longlong)param_1 + 0x14);
  sVar7 = 0;
  do {
    iVar4 = (int)param_1[0x1a];
    if (iVar4 == *(int *)((longlong)param_1 + 0xd4)) {
      iVar3 = iVar4;
      if (iVar4 == 0) {
        iVar3 = (int)param_1[0x1b];
      }
      if (param_1[(ulonglong)(iVar3 - 1) + 0x1c] == 0) {
LAB_14000e9f1:
        *(ushort *)((longlong)param_1 + 0x14) = uVar6;
        return sVar7;
      }
    }
    lVar1 = *param_1;
    if (iVar4 == 0) {
      iVar4 = (int)param_1[0x1b];
    }
    *(int *)((longlong)param_1 + 0xdc) = *(int *)((longlong)param_1 + 0xdc) + -1;
    uVar5 = iVar4 - 1;
    *(uint *)(param_1 + 0x1a) = uVar5;
    lVar2 = param_1[(ulonglong)uVar5 + 0x1c];
    param_1[(ulonglong)uVar5 + 0x1c] = 0;
    if (lVar2 == 0) goto LAB_14000e9f1;
    *(undefined4 *)(lVar1 + (ulonglong)(uVar6 & 3) * 8) = *(undefined4 *)(lVar2 + 0x20);
    *(int *)(lVar1 + 4 + (ulonglong)(uVar6 & 3) * 8) =
         (int)((ulonglong)*(undefined8 *)(lVar2 + 0x20) >> 0x20);
    iVar4 = *(int *)((longlong)param_1 + 0x104);
    if (iVar4 == 0) {
      iVar4 = (int)param_1[0x21];
    }
    uVar6 = uVar6 + 1;
    param_1[(ulonglong)(iVar4 - 1U) + 0x22] = lVar2;
    *(int *)((longlong)param_1 + 0x10c) = *(int *)((longlong)param_1 + 0x10c) + 1;
    *(uint *)((longlong)param_1 + 0x104) = iVar4 - 1U;
    *(int *)(param_1 + 5) = (int)param_1[5] + 1;
    sVar7 = sVar7 + 1;
  } while( true );
}



===== elite_rx_start @ 14000ea08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool elite_rx_start(longlong param_1)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 auStack_a8 [32];
  byte local_88 [2];
  undefined2 local_86;
  undefined4 local_84;
  uint local_80;
  undefined1 local_7c;
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_68;
  undefined2 local_64;
  undefined2 local_62;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_40;
  undefined1 local_3e;
  undefined2 local_3d;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_36;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  pvVar1 = *(void **)(param_1 + 0x210);
  mm_memset(pvVar1,0x270,0);
  *(undefined2 *)((longlong)pvVar1 + 0x1e2) = 4;
  mm_memset(local_88,4,0);
  mm_memset(&local_68,0x40,0);
  local_60 = *(undefined4 *)(param_1 + 0x7e0);
  local_5c = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 0x7e0) >> 0x20);
  local_64 = 0x5ea;
  local_62 = *(undefined2 *)(param_1 + 0xabc);
  local_68 = 0x40004;
  local_3d = 0x101;
  local_40 = 4;
  local_3b = 0;
  uVar2 = elite_mcp_read_boot_protocol(param_1,(byte *)(param_1 + 0x284));
  if (uVar2 == 0) {
    uVar4 = elite_mcp_read_vlan_setting(param_1,(byte *)(param_1 + 0x284));
    if ((int)uVar4 != 0) goto LAB_14000ebcd;
  }
  else if (uVar2 == 3) {
LAB_14000ebcd:
    local_3a = 1;
    goto LAB_14000eae3;
  }
  local_3a = 0;
LAB_14000eae3:
  local_39 = *(undefined1 *)(param_1 + 0x27c);
  *(undefined1 *)(param_1 + 0x131) = local_3e;
  local_78 = &local_68;
  local_84 = CONCAT22(*(undefined2 *)(param_1 + 0x24),1);
  *(undefined4 *)(param_1 + 0x7e8) = local_84;
  local_70 = local_84;
  local_36 = 1;
  local_7c = 1;
  local_80 = 0x40;
  iVar3 = elite_sp_post(param_1,&local_80);
  local_86 = 4;
  local_88[0] = local_88[0] & 0x30 | 0x46;
  mm_pci_mem_write(param_1,1,*(uint *)(param_1 + 0x9c),(undefined4 *)local_88);
  *(undefined2 *)(param_1 + 0x12e) = 0xffff;
  *(longlong *)(param_1 + 0x7f8) = *(longlong *)(param_1 + 0xaa8) + 2;
  *(undefined2 *)(param_1 + 0x7ec) = 4;
  *(undefined2 *)(param_1 + 0xba) = 0x808;
  *(undefined2 *)(param_1 + 0xf4) = 0x808;
  return iVar3 != 0;
}



===== elite_rx_stop @ 14000ebd8 =====

void elite_rx_stop(longlong param_1)

{
  undefined4 local_res8;
  uint local_28;
  undefined1 local_24;
  undefined8 local_20;
  undefined4 local_18;
  
  local_20 = 0;
  local_28 = 0;
  local_res8 = CONCAT22(*(undefined2 *)(param_1 + 0x24),1);
  local_18 = local_res8;
  local_24 = 3;
  elite_sp_post(param_1,&local_28);
  return;
}



===== elite_send_packet @ 14000ec18 =====

undefined4 elite_send_packet(longlong param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *puVar5;
  byte bVar6;
  undefined4 uVar7;
  short sVar8;
  undefined2 local_res8;
  short sStackX_a;
  
  uVar7 = 0;
  if (*(int *)(param_1 + 0x968) == 0) {
    uVar7 = 2;
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0x954);
    puVar5 = (undefined4 *)((ulonglong)(uVar2 & 3) * 0x10 + *(longlong *)(param_1 + 0x940));
    if (puVar5 == (undefined4 *)0x0) {
      uVar7 = 2;
    }
    else {
      bVar1 = *(byte *)((longlong)puVar5 + 0xd);
      bVar6 = bVar1 | 4;
      *(undefined1 *)(puVar5 + 3) = 1;
      *(byte *)((longlong)puVar5 + 0xd) = bVar6;
      if ((*(byte *)(param_1 + 0x131) & 0x20) != 0) {
        bVar6 = bVar1 | 5;
        *(byte *)((longlong)puVar5 + 0xd) = bVar6;
      }
      if (*(int *)(param_2 + 4) == 1) {
        *(byte *)((longlong)puVar5 + 0xd) = bVar6 & 0xfd | 2;
        uVar3 = *(undefined2 *)(param_2 + 8);
      }
      else {
        *(byte *)((longlong)puVar5 + 0xd) = bVar6 & 0xfd;
        uVar3 = 0;
      }
      *(undefined2 *)((longlong)puVar5 + 10) = uVar3;
      sVar8 = uVar2 + 1;
      *(byte *)((longlong)puVar5 + 0xd) = *(byte *)((longlong)puVar5 + 0xd) & 0x47;
      *(undefined2 *)((longlong)puVar5 + 0xe) = 0;
      *puVar5 = *(undefined4 *)(param_2 + 0x18);
      puVar5[1] = (int)((ulonglong)*(undefined8 *)(param_2 + 0x18) >> 0x20);
      *(undefined2 *)(puVar5 + 2) = *(undefined2 *)(param_2 + 0x22);
      *(int *)(param_1 + 0x968) = *(int *)(param_1 + 0x968) + -1;
      iVar4 = *(int *)(param_1 + 0xa44);
      _local_res8 = CONCAT22(sVar8,0x1084);
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0xa48);
      }
      *(longlong *)(param_1 + 0xa50 + (ulonglong)(iVar4 - 1U) * 8) = param_2;
      *(int *)(param_1 + 0xa4c) = *(int *)(param_1 + 0xa4c) + 1;
      *(uint *)(param_1 + 0xa44) = iVar4 - 1U;
      *(short *)(param_1 + 0x954) = sVar8;
      mm_pci_mem_write(param_1,1,*(uint *)(param_1 + 0xa0),(undefined4 *)&local_res8);
    }
  }
  return uVar7;
}



===== elite_setup_rx_chain @ 14000ed38 =====

undefined8 elite_setup_rx_chain(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong local_res8;
  longlong local_res10;
  
  plVar1 = (longlong *)(param_1 + 0x7d8);
  *(undefined8 *)(param_1 + 0x8b0) = 4;
  lVar6 = param_1 + 0x808;
  *(undefined8 *)(param_1 + 0x8a8) = 0;
  mm_memset((void *)(param_1 + 0x8b8),0x20,0);
  *(undefined8 *)(param_1 + 0x8d8) = 0;
  *(undefined8 *)(param_1 + 0x8e0) = 4;
  mm_memset((void *)(param_1 + 0x8e8),0x20,0);
  *(undefined8 *)(param_1 + 0x908) = 0;
  *(undefined8 *)(param_1 + 0x910) = 4;
  mm_memset((void *)(param_1 + 0x918),0x20,0);
  uVar3 = mm_dma_alloc(param_1,plVar1,(longlong *)(param_1 + 0x7e0),0x20);
  if ((int)uVar3 == 0) {
    uVar5 = 0;
    *(longlong *)(param_1 + 0x7f0) = *plVar1;
    lVar7 = 0;
    *(undefined4 *)(param_1 + 0x7ec) = 0;
    *(undefined4 *)(param_1 + 0x800) = 4;
    do {
      uVar3 = mm_dma_alloc(param_1,&local_res10,&local_res8,0x620);
      if ((int)uVar3 != 0) goto LAB_14000ee74;
      *(longlong *)(lVar6 + 0x18) = local_res10;
      *(longlong *)(lVar6 + 0x20) = local_res8;
      iVar4 = *(int *)(param_1 + 0x8dc);
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x8e0);
      }
      uVar5 = uVar5 + 1;
      *(longlong *)(param_1 + 0x8e8 + (ulonglong)(iVar4 - 1U) * 8) = lVar6;
      lVar6 = lVar6 + 0x28;
      *(int *)(param_1 + 0x8e4) = *(int *)(param_1 + 0x8e4) + 1;
      *(uint *)(param_1 + 0x8dc) = iVar4 - 1U;
      lVar2 = *plVar1;
      *(int *)(lVar7 + lVar2) = (int)local_res8;
      *(int *)(lVar7 + 4 + lVar2) = (int)((ulonglong)local_res8 >> 0x20);
      lVar7 = lVar7 + 8;
    } while (uVar5 < 4);
    uVar3 = 0;
  }
  else {
LAB_14000ee74:
    uVar3 = 2;
  }
  return uVar3;
}



===== elite_setup_tx_chain @ 14000ee8c =====

undefined8 elite_setup_tx_chain(longlong param_1)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong local_res8;
  longlong local_res10;
  
  *(undefined8 *)(param_1 + 0xa18) = 4;
  lVar4 = param_1 + 0x970;
  *(undefined8 *)(param_1 + 0xa10) = 0;
  mm_memset((void *)(param_1 + 0xa20),0x20,0);
  *(undefined8 *)(param_1 + 0xa40) = 0;
  *(undefined8 *)(param_1 + 0xa48) = 4;
  mm_memset((void *)(param_1 + 0xa50),0x20,0);
  *(undefined8 *)(param_1 + 0xa70) = 0;
  *(undefined8 *)(param_1 + 0xa78) = 4;
  mm_memset((void *)(param_1 + 0xa80),0x20,0);
  uVar1 = mm_dma_alloc(param_1,(longlong *)(param_1 + 0x940),(longlong *)(param_1 + 0x948),0x40);
  if ((int)uVar1 == 0) {
    uVar3 = 0;
    *(longlong *)(param_1 + 0x958) = *(longlong *)(param_1 + 0x940);
    *(undefined4 *)(param_1 + 0x954) = 0;
    *(undefined4 *)(param_1 + 0x968) = 4;
    do {
      uVar1 = mm_dma_alloc(param_1,&local_res8,&local_res10,0x600);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
      *(longlong *)(lVar4 + 0x10) = local_res8;
      *(longlong *)(lVar4 + 0x18) = local_res10;
      *(undefined2 *)(lVar4 + 0x20) = 0x600;
      iVar2 = *(int *)(param_1 + 0xa14);
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0xa18);
      }
      uVar3 = uVar3 + 1;
      *(longlong *)(param_1 + 0xa20 + (ulonglong)(iVar2 - 1U) * 8) = lVar4;
      lVar4 = lVar4 + 0x28;
      *(int *)(param_1 + 0xa1c) = *(int *)(param_1 + 0xa1c) + 1;
      *(uint *)(param_1 + 0xa14) = iVar2 - 1U;
    } while (uVar3 < 4);
    uVar1 = 0;
  }
  return uVar1;
}



===== elite_tx_start @ 14000efc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int elite_tx_start(longlong param_1)

{
  int iVar1;
  undefined1 auStack_88 [32];
  int local_68;
  uint local_60;
  undefined1 local_5c;
  undefined4 *local_58;
  int local_50;
  undefined4 local_48;
  undefined2 local_44;
  short local_42;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_20;
  undefined2 local_1e;
  char local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  mm_memset(*(void **)(param_1 + 0x1f8),0x270,0);
  mm_memset(&local_48,0x38,0);
  local_40 = *(undefined4 *)(param_1 + 0x948);
  local_3c = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 0x948) >> 0x20);
  local_44 = 0x5ea;
  local_20 = *(undefined2 *)(param_1 + 0xabc);
  local_1c = *(char *)(param_1 + 0x27c);
  local_48 = 0x40004;
  local_1e = 0x100;
  if ((local_1c != '\x01') || (local_42 = *(short *)(param_1 + 0x14a), local_42 == -1)) {
    local_42 = 0;
  }
  local_58 = &local_48;
  local_68 = (uint)*(ushort *)(param_1 + 0x24) << 0x10;
  local_50 = local_68;
  *(int *)(param_1 + 0x950) = local_68;
  local_5c = 2;
  local_60 = 0x38;
  iVar1 = elite_sp_post(param_1,&local_60);
  if (iVar1 == 0) {
    *(undefined8 *)(param_1 + 0x960) = *(undefined8 *)(param_1 + 0xaa8);
    iVar1 = 0;
  }
  return iVar1;
}



===== elite_tx_stop @ 14000f0d8 =====

void elite_tx_stop(longlong param_1)

{
  int local_res8;
  uint local_28;
  undefined1 local_24;
  undefined8 local_20;
  int local_18;
  
  local_24 = 4;
  local_20 = 0;
  local_28 = 0;
  local_res8 = (uint)*(ushort *)(param_1 + 0x24) << 0x10;
  local_18 = local_res8;
  elite_sp_post(param_1,&local_28);
  return;
}



===== elite_intr_disable_igu @ 14000f114 =====

void elite_intr_disable_igu(longlong param_1)

{
  *(undefined1 *)(param_1 + 0xac9) = 0;
  elite_wr(param_1,(byte *)(param_1 + 0x284),0x180800,0);
  return;
}



===== elite_intr_enable_igu @ 14000f130 =====

void elite_intr_enable_igu(longlong param_1)

{
  *(undefined1 *)(param_1 + 0xac9) = 1;
  elite_wr(param_1,(byte *)(param_1 + 0x284),0x180800,0x1d);
  return;
}



===== elite_intr_enable_rt @ 14000f150 =====

void elite_intr_enable_rt(longlong param_1)

{
  elite_init_store_rt_reg(param_1,8,1);
  return;
}



===== crashdump_icmp4_input @ 14000f160 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void crashdump_icmp4_input(longlong *param_1,longlong param_2)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  short *psVar5;
  ushort uVar6;
  ulonglong uVar7;
  
  puVar4 = (ushort *)param_1[1];
  uVar2 = *puVar4;
  uVar7 = pbuf_header((longlong)param_1,(uVar2 & 0xf) * -4);
  if ((((char)uVar7 == '\0') && (uVar6 = *(ushort *)(param_1 + 2), 3 < uVar6)) &&
     (psVar5 = (short *)param_1[1], (char)*psVar5 == '\b')) {
    puVar1 = (uint *)(puVar4 + 8);
    uVar7 = ip_addr_isbroadcast(puVar1,param_2);
    if ((((char)uVar7 == '\0') && (uVar3 = *puVar1, ((byte)uVar3 & 0xf0) != 0xe0)) && (7 < uVar6)) {
      uVar6 = inet_chksum_pbuf(param_1);
      if (uVar6 == 0) {
        *puVar1 = *(uint *)(puVar4 + 6);
        *(uint *)(puVar4 + 6) = uVar3;
        *psVar5 = (ushort)*(byte *)((longlong)psVar5 + 1) << 8;
        psVar5[1] = (psVar5[1] + 9U) - (ushort)((ushort)psVar5[1] < 0xfff7);
        pbuf_header((longlong)param_1,(uVar2 & 0xf) * 4);
        (**(code **)(param_2 + 0x18))(param_2,param_1,param_1[1] + 0x10);
      }
    }
  }
  pbuf_free(param_1);
  return;
}



===== crashdump_ip4_input @ 14000f280 =====

/* WARNING: Removing unreachable block (ram,0x00014000f2f9) */

longlong crashdump_ip4_input(longlong *param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  ushort *puVar3;
  char cVar4;
  ushort uVar5;
  uint7 extraout_var;
  uint7 uVar7;
  ulonglong uVar6;
  uint7 extraout_var_00;
  uint7 extraout_var_01;
  ushort uVar8;
  longlong *plVar9;
  
  puVar3 = (ushort *)param_1[1];
  if (((*puVar3 & 0xf0) == 0x40) &&
     (uVar8 = (*puVar3 & 0xf) * 4, uVar8 <= *(ushort *)((longlong)param_1 + 0x12))) {
    uVar5 = lwip_standard_chksum((byte *)puVar3,uVar8);
    if (uVar5 == 0xffff) {
      pbuf_realloc(param_1,puVar3[1] << 8 | puVar3[1] >> 8);
      if (netif_list != (longlong *)0x0) {
        puVar1 = (uint *)(puVar3 + 8);
        plVar9 = netif_list;
        do {
          if (((((*(byte *)((longlong)plVar9 + 0x3a) & 1) != 0) &&
               ((uint *)(plVar9 + 0x24) != (uint *)0x0)) &&
              (uVar2 = *(uint *)(plVar9 + 0x24), uVar2 != 0)) &&
             ((*puVar1 == uVar2 ||
              (uVar6 = ip_addr_isbroadcast(puVar1,(longlong)plVar9), (char)uVar6 != '\0')))) break;
          plVar9 = (longlong *)*plVar9;
        } while (plVar9 != (longlong *)0x0);
        if ((plVar9 != (longlong *)0x0) && ((puVar3[3] & 0xff3f) == 0)) {
          cVar4 = (char)(puVar3[4] >> 8);
          if (cVar4 == '\x01') {
            crashdump_icmp4_input(param_1,param_2);
            uVar7 = extraout_var_01;
            goto LAB_14000f30f;
          }
          if (cVar4 == '\x06') {
            crashdump_tcp4_input(param_1);
            uVar7 = extraout_var_00;
            goto LAB_14000f30f;
          }
          uVar6 = ip_addr_isbroadcast(puVar1,param_2);
          if (((char)uVar6 == '\0') && (((byte)*puVar1 & 0xf0) != 0xe0)) {
            param_1[1] = (longlong)puVar3;
            icmp_dest_unreach((longlong)param_1,2);
          }
        }
      }
    }
    else {
      lwip_standard_chksum((byte *)puVar3,uVar8);
    }
  }
  pbuf_free(param_1);
  uVar7 = extraout_var;
LAB_14000f30f:
  return (ulonglong)uVar7 << 8;
}



===== crashdump_ip4_output @ 14000f3fc =====

undefined8
crashdump_ip4_output
          (longlong param_1,int *param_2,uint *param_3,undefined1 param_4,byte param_5,
          undefined1 param_6)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  plVar1 = ip_route(param_3);
  if (plVar1 == (longlong *)0x0) {
    uVar2 = 0xf7;
  }
  else {
    uVar2 = ip_output_if(param_1,param_2,param_3,param_4,param_5,param_6,(longlong)plVar1);
  }
  return uVar2;
}



===== crashdump_tcp4_close @ 14000f468 =====

char crashdump_tcp4_close(uint *param_1)

{
  uint uVar1;
  char cVar2;
  undefined8 uVar3;
  int iVar4;
  
  uVar1 = param_1[6];
  if (uVar1 == 0) {
    cVar2 = '\0';
    memp_free(3,(longlong)param_1);
    param_1 = (uint *)0x0;
LAB_14000f553:
    if ((param_1 != (uint *)0x0) && (cVar2 == '\0')) {
      uVar3 = crashdump_tcp4_output(param_1);
      cVar2 = (char)uVar3;
    }
  }
  else {
    if (uVar1 == 1) {
      tcp_pcb_remove(&tcp_listen_pcbs,param_1);
      iVar4 = 4;
    }
    else {
      if (uVar1 != 2) {
        if ((uVar1 == 3) || (uVar1 == 4)) {
          uVar3 = tcp_enqueue((longlong)param_1,(void *)0x0,0,1,'\x01',(void *)0x0,0);
          cVar2 = (char)uVar3;
          if (cVar2 == '\0') {
            param_1[6] = 5;
          }
        }
        else {
          if (uVar1 != 7) {
            return '\0';
          }
          uVar3 = tcp_enqueue((longlong)param_1,(void *)0x0,0,1,'\x01',(void *)0x0,0);
          cVar2 = (char)uVar3;
          if (cVar2 == '\0') {
            param_1[6] = 9;
          }
        }
        goto LAB_14000f553;
      }
      tcp_pcb_remove(&tcp_active_pcbs,param_1);
      iVar4 = 3;
    }
    cVar2 = '\0';
    memp_free(iVar4,(longlong)param_1);
  }
  return cVar2;
}



===== crashdump_tcp4_input @ 14000f578 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crashdump_tcp4_input(longlong *param_1)

{
  byte bVar1;
  ushort *puVar2;
  longlong lVar3;
  int *piVar4;
  char cVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  uint *puVar9;
  ushort uVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  int *piVar14;
  int *piVar15;
  uint uVar16;
  uint local_res8 [2];
  
  DAT_140072458 = param_1[1];
  DAT_140072450 = (ushort *)(DAT_140072458 + 0x14);
  uVar7 = pbuf_header((longlong)param_1,-0x14);
  if ((((char)uVar7 == '\0') && (0x13 < *(ushort *)(param_1 + 2))) &&
     (uVar6 = inet_chksum_pseudo(param_1,(uint *)(DAT_140072458 + 0xc),
                                 (uint *)(DAT_140072458 + 0x10),6,*(ushort *)(param_1 + 2)),
     (short)uVar6 == 0)) {
    pbuf_header((longlong)param_1,((DAT_140072450[6] & 0xff) >> 4) * -4);
    lVar3 = DAT_140072458;
    puVar2 = DAT_140072450;
    uVar16 = *(uint *)(DAT_140072450 + 2);
    *DAT_140072450 = *DAT_140072450 << 8 | *DAT_140072450 >> 8;
    puVar2[1] = puVar2[1] << 8 | puVar2[1] >> 8;
    uVar12 = *(uint *)(puVar2 + 4);
    uVar16 = (uVar16 << 0x10 | uVar16 & 0xff00) << 8 | uVar16 >> 8 & 0xff00 |
             (uint)*(byte *)((longlong)puVar2 + 7);
    *(uint *)(puVar2 + 2) = uVar16;
    bVar1 = *(byte *)((longlong)puVar2 + 0xd);
    uVar12 = (uVar12 << 0x10 | uVar12 & 0xff00) << 8 | uVar12 >> 8 & 0xff00 |
             (uint)*(byte *)((longlong)puVar2 + 0xb);
    DAT_140072423 = bVar1 & 0x3f;
    DAT_140072424 = uVar16;
    *(uint *)(puVar2 + 4) = uVar12;
    puVar2[7] = puVar2[7] << 8 | puVar2[7] >> 8;
    uVar10 = (ushort)((bVar1 & 3) != 0) + (short)param_1[2];
    puVar9 = tcp_active_pcbs;
    puVar13 = (uint *)0x0;
    DAT_140072460 = uVar12;
    DAT_140072464 = uVar10;
    if (tcp_active_pcbs != (uint *)0x0) {
      do {
        puVar11 = puVar9;
        uVar16 = puVar11[6];
        if (uVar16 == 0) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_input: active pcb->state != CLOSED");
        }
        if (uVar16 == 10) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_input: active pcb->state != TIME-WAIT");
        }
        if (uVar16 == 1) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_input: active pcb->state != LISTEN");
        }
        if (((*(ushort *)((longlong)puVar11 + 0x2a) == *puVar2) &&
            ((ushort)puVar11[10] == puVar2[1])) && (*puVar11 == *(uint *)(lVar3 + 0x10))) {
          puVar9 = *(uint **)(puVar11 + 4);
          if (puVar9 == puVar11) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_input: pcb->next != pcb (before cache)");
          }
          if (puVar13 != (uint *)0x0) {
            *(uint **)(puVar13 + 4) = puVar9;
            *(uint **)(puVar11 + 4) = tcp_active_pcbs;
            puVar9 = *(uint **)(puVar11 + 4);
            tcp_active_pcbs = puVar11;
          }
          if (puVar9 == puVar11) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_input: pcb->next != pcb (after cache)");
          }
          _DAT_140072428 = 0;
          DAT_140072440 = (undefined2)param_1[2];
          _DAT_140072438 = param_1[1];
          DAT_140072448 = puVar2;
          DAT_140072468 = (undefined8 *)0x0;
          DAT_140072466 = 0;
          DAT_140072430 = param_1;
          tcp_input_pcb = puVar11;
          uVar8 = tcp_process(puVar11);
          tcp_input_pcb = (uint *)0x0;
          if ((char)uVar8 != -3) {
            if ((DAT_140072466 & 8) == 0) {
              if ((DAT_140072466 & 0x10) == 0) {
                cVar5 = '\0';
                if (((short)puVar11[0x1e] != 0) && (*(code **)(puVar11 + 0x26) != (code *)0x0)) {
                  cVar5 = (**(code **)(puVar11 + 0x26))(*(undefined8 *)(puVar11 + 8),puVar11);
                }
                if (DAT_140072468 != (undefined8 *)0x0) {
                  if (*(code **)(puVar11 + 0x28) == (code *)0x0) {
                    pbuf_free(DAT_140072468);
                  }
                  else {
                    cVar5 = (**(code **)(puVar11 + 0x28))
                                      (*(undefined8 *)(puVar11 + 8),puVar11,DAT_140072468,0);
                  }
                }
                if (((DAT_140072466 & 0x20) != 0) && (*(code **)(puVar11 + 0x28) != (code *)0x0)) {
                  cVar5 = (**(code **)(puVar11 + 0x28))(*(undefined8 *)(puVar11 + 8),puVar11,0,0);
                }
                if (cVar5 == '\0') {
                  crashdump_tcp4_output(puVar11);
                }
                goto LAB_14000fba3;
              }
            }
            else if (*(code **)(puVar11 + 0x30) != (code *)0x0) {
              (**(code **)(puVar11 + 0x30))(*(undefined8 *)(puVar11 + 8),0xfc);
            }
            tcp_pcb_remove((longlong *)&tcp_active_pcbs,puVar11);
            memp_free(3,(longlong)puVar11);
          }
LAB_14000fba3:
          if (DAT_140072430 != (longlong *)0x0) {
            pbuf_free(DAT_140072430);
            DAT_140072430 = (longlong *)0x0;
          }
          goto LAB_14000fbfa;
        }
        puVar9 = *(uint **)(puVar11 + 4);
        puVar13 = puVar11;
      } while (*(uint **)(puVar11 + 4) != (uint *)0x0);
      uVar16 = DAT_140072424;
    }
    puVar9 = tcp_tw_pcbs;
    if (tcp_tw_pcbs != (uint *)0x0) {
      do {
        if (puVar9[6] != 10) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_input: TIME-WAIT pcb->state == TIME-WAIT");
        }
        if ((((*(ushort *)((longlong)puVar9 + 0x2a) == *puVar2) && ((ushort)puVar9[10] == puVar2[1])
             ) && (puVar9[1] == *(uint *)(lVar3 + 0xc))) && (*puVar9 == *(uint *)(lVar3 + 0x10))) {
          if (0 < (int)(((uint)uVar10 - puVar9[0xc]) + DAT_140072424)) {
            puVar9[0xc] = uVar10 + DAT_140072424;
          }
          if (uVar10 != 0) {
            *(byte *)(puVar9 + 0xb) = (byte)puVar9[0xb] | 2;
            crashdump_tcp4_output(puVar9);
          }
          goto LAB_14000fad5;
        }
        puVar9 = *(uint **)(puVar9 + 4);
      } while (puVar9 != (uint *)0x0);
      uVar16 = DAT_140072424;
    }
    piVar4 = tcp_listen_pcbs;
    piVar15 = (int *)0x0;
    while (piVar14 = piVar4, piVar14 != (int *)0x0) {
      if (((*piVar14 == 0) || (*piVar14 == *(int *)(lVar3 + 0x10))) &&
         (*(ushort *)(piVar14 + 10) == puVar2[1])) {
        if (piVar15 != (int *)0x0) {
          *(undefined8 *)(piVar15 + 4) = *(undefined8 *)(piVar14 + 4);
          *(int **)(piVar14 + 4) = tcp_listen_pcbs;
          tcp_listen_pcbs = piVar14;
        }
        if ((bVar1 & 0x10) == 0) {
          if (((bVar1 & 2) != 0) &&
             (puVar9 = (uint *)tcp_alloc(*(byte *)(piVar14 + 7)), lVar3 = DAT_140072458,
             puVar9 != (uint *)0x0)) {
            if ((uint *)(DAT_140072458 + 0x10) == (uint *)0x0) {
              uVar16 = 0;
            }
            else {
              uVar16 = *(uint *)(DAT_140072458 + 0x10);
            }
            *puVar9 = uVar16;
            *(short *)(puVar9 + 10) = (short)piVar14[10];
            puVar2 = DAT_140072450;
            uVar16 = DAT_140072424;
            if ((uint *)(lVar3 + 0xc) == (uint *)0x0) {
              uVar12 = 0;
            }
            else {
              uVar12 = *(uint *)(lVar3 + 0xc);
            }
            puVar9[1] = uVar12;
            *(ushort *)((longlong)puVar9 + 0x2a) = *puVar2;
            puVar9[0xc] = uVar16 + 1;
            puVar9[6] = 3;
            uVar10 = puVar2[7];
            puVar9[0x1a] = (uint)uVar10;
            *(ushort *)(puVar9 + 0x17) = uVar10;
            puVar9[0x1b] = uVar16 - 1;
            *(undefined8 *)(puVar9 + 8) = *(undefined8 *)(piVar14 + 8);
            *(undefined8 *)(puVar9 + 0x2c) = *(undefined8 *)(piVar14 + 0xc);
            *(ushort *)(puVar9 + 2) = *(ushort *)(piVar14 + 2) & 0x199;
            *(uint **)(puVar9 + 4) = tcp_active_pcbs;
            tcp_active_pcbs = puVar9;
            tcp_parseopt((longlong)puVar9);
            local_res8[0] =
                 ((uint)(ushort)puVar9[0x10] << 0x10 | (ushort)puVar9[0x10] & 0xff00) << 8 | 0x402;
            tcp_enqueue((longlong)puVar9,(void *)0x0,0,0x12,'\0',local_res8,4);
LAB_14000fad5:
            crashdump_tcp4_output(puVar9);
          }
        }
        else {
          tcp_rst(uVar12 + 1,uVar10 + uVar16,(uint *)(lVar3 + 0x10),(uint *)(lVar3 + 0xc),puVar2[1],
                  *puVar2);
        }
        goto LAB_14000f9bb;
      }
      piVar15 = piVar14;
      piVar4 = *(int **)(piVar14 + 4);
    }
    if ((puVar2[6] >> 8 & 4) == 0) {
      tcp_rst(uVar12,uVar10 + uVar16,(uint *)(lVar3 + 0x10),(uint *)(lVar3 + 0xc),puVar2[1],*puVar2)
      ;
    }
    pbuf_free(param_1);
LAB_14000fbfa:
    uVar8 = tcp_pcbs_sane();
    if ((short)uVar8 == 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_input: tcp_pcbs_sane()");
    }
  }
  else {
LAB_14000f9bb:
    pbuf_free(param_1);
  }
  return;
}



===== crashdump_tcp4_output @ 14000fc1c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong crashdump_tcp4_output(uint *param_1)

{
  short *psVar1;
  ushort uVar2;
  uint uVar3;
  longlong *plVar4;
  ushort *puVar5;
  longlong lVar6;
  undefined4 uVar7;
  uint uVar8;
  longlong *in_RAX;
  longlong *plVar9;
  uint7 extraout_var;
  longlong *plVar10;
  uint7 extraout_var_00;
  short sVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  
  if (tcp_input_pcb == param_1) goto LAB_1400100a7;
  uVar2 = *(ushort *)((longlong)param_1 + 0x5a);
  in_RAX = (longlong *)(ulonglong)uVar2;
  plVar9 = *(longlong **)(param_1 + 0x22);
  plVar4 = *(longlong **)(param_1 + 0x20);
  uVar14 = param_1[0x1a];
  if ((uint)uVar2 <= param_1[0x1a]) {
    uVar14 = (uint)uVar2;
  }
  if (plVar9 != (longlong *)0x0) {
    plVar10 = (longlong *)*plVar9;
    while (plVar10 != (longlong *)0x0) {
      in_RAX = (longlong *)*plVar10;
      plVar9 = plVar10;
      plVar10 = in_RAX;
    }
  }
  if ((param_1[0xb] & 2) == 0) {
joined_r0x00014000fdf5:
    while (plVar4 != (longlong *)0x0) {
      uVar12 = *(uint *)(plVar4[4] + 4);
      in_RAX = (longlong *)(ulonglong)*(ushort *)(plVar4 + 3);
      if (uVar14 < (((uVar12 << 0x10 | uVar12 & 0xff00) << 8 | uVar12 >> 8 & 0xff00 |
                    (uint)*(byte *)(plVar4[4] + 7)) - param_1[0x15]) + (uint)*(ushort *)(plVar4 + 3)
         ) break;
      *(longlong *)(param_1 + 0x20) = *plVar4;
      if (param_1[6] != 2) {
        uVar2 = *(ushort *)(plVar4[4] + 0xc);
        *(ushort *)(plVar4[4] + 0xc) = uVar2 & 0xff00 | 0x1000 | uVar2 & 0xff;
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] & 0xfc;
      }
      uVar12 = param_1[0xc];
      *(uint *)(plVar4[4] + 8) =
           (uVar12 << 0x10 | uVar12 & 0xff00) << 8 | uVar12 >> 8 & 0xff00 |
           (uint)*(byte *)((longlong)param_1 + 0x33);
      uVar2 = (ushort)param_1[0xd];
      if (uVar2 < (ushort)param_1[0x10]) {
        *(undefined2 *)(plVar4[4] + 0xe) = 0;
      }
      else {
        *(ushort *)(plVar4[4] + 0xe) = uVar2 << 8 | uVar2 >> 8;
      }
      if (*param_1 == 0) {
        plVar10 = ip_route(param_1 + 1);
        if (plVar10 != (longlong *)0x0) {
          if ((uint *)(plVar10 + 0x24) == (uint *)0x0) {
            uVar12 = 0;
          }
          else {
            uVar12 = *(uint *)(plVar10 + 0x24);
          }
          *param_1 = uVar12;
          goto LAB_14000fee2;
        }
      }
      else {
LAB_14000fee2:
        *(undefined2 *)((longlong)param_1 + 0x3e) = 0;
        if (param_1[0x11] == 0) {
          param_1[0x11] = _tcp_ticks;
          uVar12 = *(uint *)(plVar4[4] + 4);
          param_1[0x12] =
               (uVar12 << 0x10 | uVar12 & 0xff00) << 8 | uVar12 >> 8 & 0xff00 |
               (uint)*(byte *)(plVar4[4] + 7);
        }
        sVar11 = (short)plVar4[4] - *(short *)(plVar4[1] + 8);
        psVar1 = (short *)(plVar4[1] + 0x12);
        *psVar1 = *psVar1 - sVar11;
        *(short *)(plVar4[1] + 0x10) = *(short *)(plVar4[1] + 0x10) - sVar11;
        *(longlong *)(plVar4[1] + 8) = plVar4[4];
        *(undefined2 *)(plVar4[4] + 0x10) = 0;
        uVar7 = inet_chksum_pseudo((longlong *)plVar4[1],param_1,param_1 + 1,6,
                                   *(ushort *)((longlong *)plVar4[1] + 2));
        *(short *)(plVar4[4] + 0x10) = (short)uVar7;
        crashdump_ip4_output
                  (plVar4[1],(int *)param_1,param_1 + 1,*(undefined1 *)((longlong)param_1 + 0xb),
                   *(byte *)((longlong)param_1 + 10),6);
      }
      lVar6 = plVar4[4];
      uVar2 = *(ushort *)(lVar6 + 0xc) >> 8;
      if (((uVar2 & 1) != 0) || (iVar13 = 0, (uVar2 & 2) != 0)) {
        iVar13 = 1;
      }
      uVar12 = *(uint *)(lVar6 + 4);
      uVar12 = ((uVar12 << 0x10 | uVar12 & 0xff00) << 8 | uVar12 >> 8 & 0xff00 |
               (uint)*(byte *)(lVar6 + 7)) + iVar13 + (uint)*(ushort *)(plVar4 + 3);
      param_1[0x18] = uVar12;
      if ((int)(param_1[0x19] - uVar12) < 0) {
        param_1[0x19] = uVar12;
      }
      uVar2 = *(ushort *)(plVar4[4] + 0xc) >> 8;
      if (((uVar2 & 1) != 0) || (iVar13 = 0, (uVar2 & 2) != 0)) {
        iVar13 = 1;
      }
      in_RAX = (longlong *)(ulonglong)((uint)*(ushort *)(plVar4 + 3) + iVar13);
      if ((uint)*(ushort *)(plVar4 + 3) + iVar13 == 0) {
        crashdump_ip6_tcp_seg_free((longlong)plVar4);
        in_RAX = (longlong *)((ulonglong)extraout_var_00 << 8);
      }
      else {
        *plVar4 = 0;
        if (*(longlong *)(param_1 + 0x22) == 0) {
          *(longlong **)(param_1 + 0x22) = plVar4;
        }
        else {
          uVar12 = *(uint *)(plVar4[4] + 4);
          uVar3 = *(uint *)(plVar9[4] + 4);
          uVar8 = (uVar3 << 0x10 | uVar3 & 0xff00) << 8;
          in_RAX = (longlong *)(ulonglong)uVar8;
          if ((int)(((uVar12 & 0xff0000 | uVar12 >> 0x10) >> 8 |
                    (uVar12 << 0x10 | uVar12 & 0xff00) << 8) -
                   ((uVar3 & 0xff0000 | uVar3 >> 0x10) >> 8 | uVar8)) < 0) {
            *plVar4 = *(longlong *)(param_1 + 0x22);
            *(longlong **)(param_1 + 0x22) = plVar4;
            goto LAB_140010097;
          }
          *plVar9 = (longlong)plVar4;
        }
        plVar9 = plVar4;
      }
LAB_140010097:
      plVar4 = *(longlong **)(param_1 + 0x20);
    }
  }
  else {
    if (plVar4 != (longlong *)0x0) {
      uVar12 = *(uint *)(plVar4[4] + 4);
      in_RAX = (longlong *)(ulonglong)*(ushort *)(plVar4 + 3);
      if ((((uVar12 << 0x10 | uVar12 & 0xff00) << 8 | (uint)*(byte *)(plVar4[4] + 7) |
           uVar12 >> 8 & 0xff00) - param_1[0x15]) + (uint)*(ushort *)(plVar4 + 3) <= uVar14)
      goto joined_r0x00014000fdf5;
    }
    plVar9 = pbuf_alloc(1,0x14,0);
    if (plVar9 == (longlong *)0x0) {
      return 0xfe;
    }
    *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] & 0xfc;
    puVar5 = (ushort *)plVar9[1];
    *puVar5 = (ushort)param_1[10] << 8 | (ushort)param_1[10] >> 8;
    puVar5[1] = *(ushort *)((longlong)param_1 + 0x2a) << 8 |
                *(ushort *)((longlong)param_1 + 0x2a) >> 8;
    uVar14 = param_1[0x18];
    *(uint *)(puVar5 + 2) =
         (uVar14 << 0x10 | uVar14 & 0xff00) << 8 | uVar14 >> 8 & 0xff00 |
         (uint)*(byte *)((longlong)param_1 + 99);
    uVar14 = param_1[0xc];
    *(uint *)(puVar5 + 4) =
         (uVar14 << 0x10 | uVar14 & 0xff00) << 8 | uVar14 >> 8 & 0xff00 |
         (uint)*(byte *)((longlong)param_1 + 0x33);
    puVar5[6] = puVar5[6] & 0xd000 | 0x1000 | puVar5[6] & 0xff;
    puVar5[7] = (ushort)param_1[0xd] << 8 | (ushort)param_1[0xd] >> 8;
    puVar5[8] = 0;
    puVar5[9] = 0;
    puVar5[6] = 0x1050;
    uVar7 = inet_chksum_pseudo(plVar9,param_1,param_1 + 1,6,*(ushort *)(plVar9 + 2));
    puVar5[8] = (ushort)uVar7;
    crashdump_ip4_output
              ((longlong)plVar9,(int *)param_1,param_1 + 1,*(undefined1 *)((longlong)param_1 + 0xb),
               *(byte *)((longlong)param_1 + 10),6);
    pbuf_free(plVar9);
    in_RAX = (longlong *)((ulonglong)extraout_var << 8);
  }
LAB_1400100a7:
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== crashdump_tcp4_recved @ 1400100c8 =====

void crashdump_tcp4_recved(uint *param_1,ushort param_2)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = 0xffff;
  if ((uint)param_2 + (uint)(ushort)param_1[0xd] < 0x10000) {
    uVar2 = param_2 + (ushort)param_1[0xd];
  }
  *(ushort *)(param_1 + 0xd) = uVar2;
  bVar1 = (byte)param_1[0xb];
  if ((bVar1 & 3) == 0) {
    if ((bVar1 & 1) == 0) {
      *(byte *)(param_1 + 0xb) = bVar1 | 1;
      return;
    }
    bVar1 = bVar1 & 0xfe;
  }
  else {
    if ((bVar1 & 1) == 0) {
      return;
    }
    if (uVar2 < 0x7fff) {
      return;
    }
  }
  *(byte *)(param_1 + 0xb) = bVar1 | 2;
  crashdump_tcp4_output(param_1);
  return;
}



===== etharp_arp_input @ 140010128 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void etharp_arp_input(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  undefined1 *puVar5;
  undefined1 *puVar4;
  byte bVar6;
  ulonglong uVar7;
  bool bVar8;
  uint local_res8 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("netif != NULL");
  }
  if (0x29 < *(ushort *)(param_3 + 2)) {
    lVar3 = param_3[1];
    local_res8[0] = *(uint *)(lVar3 + 0x1c);
    if (*(int *)(param_1 + 0x120) == 0) {
      bVar8 = false;
    }
    else {
      bVar8 = *(int *)(lVar3 + 0x26) == *(int *)(param_1 + 0x120);
    }
    lVar1 = lVar3 + 0x16;
    update_arp_entry(param_1,local_res8,lVar1,bVar8);
    if (((ushort)(*(ushort *)(lVar3 + 0x14) << 8 | *(ushort *)(lVar3 + 0x14) >> 8) == 1) &&
       (bVar8 != false)) {
      *(undefined2 *)(lVar3 + 0x14) = 0x200;
      *(undefined4 *)(lVar3 + 0x26) = *(undefined4 *)(lVar3 + 0x1c);
      *(undefined4 *)(lVar3 + 0x1c) = *(undefined4 *)(param_1 + 0x120);
      uVar7 = (ulonglong)*(byte *)(param_1 + 0x30);
      if (*(byte *)(param_1 + 0x30) != 0) {
        puVar5 = (undefined1 *)(lVar1 + uVar7);
        do {
          puVar4 = puVar5 + -1;
          uVar2 = *puVar4;
          puVar5[9] = uVar2;
          *puVar4 = puVar4[param_2 - lVar1];
          puVar4[lVar3 - lVar1] = uVar2;
          puVar5[-0x11] = puVar4[param_2 - lVar1];
          bVar6 = (char)uVar7 - 1;
          uVar7 = (ulonglong)bVar6;
          puVar5 = puVar4;
        } while (bVar6 != 0);
      }
      *(undefined2 *)(lVar3 + 0xe) = 0x100;
      bVar6 = *(byte *)(param_1 + 0x30);
      *(undefined2 *)(lVar3 + 0x10) = 8;
      *(undefined2 *)(lVar3 + 0xc) = 0x608;
      *(ushort *)(lVar3 + 0x12) = bVar6 | 0x400;
      (**(code **)(param_1 + 0x20))(param_1,param_3);
    }
  }
  pbuf_free(param_3);
  return;
}



===== etharp_init @ 140010280 =====

void etharp_init(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = &DAT_140074160;
  lVar2 = 10;
  do {
    *(undefined4 *)((longlong)puVar1 + 0x14) = 0;
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
    puVar1[4] = 0;
    puVar1 = puVar1 + 5;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



===== etharp_output @ 1400102a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong etharp_output(longlong param_1,uint *param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 *puVar6;
  undefined1 *puVar5;
  byte bVar7;
  undefined2 *puVar8;
  undefined1 auStack_48 [32];
  undefined2 local_28;
  undefined1 local_26;
  byte local_25;
  undefined1 local_24;
  undefined1 local_23;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  uVar4 = pbuf_header((longlong)param_3,0xe);
  if ((char)uVar4 == '\0') {
    uVar4 = ip_addr_isbroadcast(param_2,param_1);
    if ((char)uVar4 == '\0') {
      uVar1 = *param_2;
      if (((byte)uVar1 & 0xf0) != 0xe0) {
        uVar3 = *(uint *)(param_1 + 0x120) & *(uint *)(param_1 + 0x124);
        if (((*(uint *)(param_1 + 0x124) & uVar1) == uVar3) ||
           (param_2 = (uint *)(param_1 + 0x128), *param_2 != 0)) {
          uVar4 = etharp_query(param_1,param_2,param_3);
          return uVar4;
        }
        return CONCAT71((uint7)(uint3)(uVar3 >> 8),0xf7);
      }
      local_28 = 1;
      puVar8 = &local_28;
      local_26 = 0x5e;
      local_25 = (byte)(uVar1 >> 8) & 0x7f;
      local_23 = (char)(uVar1 >> 0x18);
      local_24 = (char)(uVar1 >> 0x10);
    }
    else {
      puVar8 = (undefined2 *)&DAT_14002be18;
    }
    uVar4 = (ulonglong)*(byte *)(param_1 + 0x30);
    lVar2 = param_3[1];
    if (*(byte *)(param_1 + 0x30) != 0) {
      puVar6 = (undefined1 *)(lVar2 + uVar4);
      do {
        puVar5 = puVar6 + -1;
        *puVar5 = puVar5[(longlong)puVar8 - lVar2];
        puVar6[5] = puVar5[(param_1 + 0x31) - lVar2];
        bVar7 = (char)uVar4 - 1;
        uVar4 = (ulonglong)bVar7;
        puVar6 = puVar5;
      } while (bVar7 != 0);
    }
    *(undefined2 *)(lVar2 + 0xc) = 8;
    lwip_printk();
    uVar4 = (**(code **)(param_1 + 0x20))(param_1,param_3);
  }
  else {
    uVar4 = CONCAT71((int7)(uVar4 >> 8),0xfe);
  }
  return uVar4;
}



===== etharp_query @ 1400103d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong etharp_query(longlong param_1,uint *param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  undefined7 extraout_var;
  longlong *plVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  byte bVar9;
  longlong lVar10;
  
  uVar3 = 0xff;
  uVar4 = ip_addr_isbroadcast(param_2,param_1);
  if ((char)uVar4 != '\0') {
LAB_14001056e:
    return CONCAT71((int7)(uVar4 >> 8),0xf8);
  }
  uVar4 = 0;
  if ((((byte)*param_2 & 0xf0) == 0xe0) || (*param_2 == 0)) goto LAB_14001056e;
  uVar4 = find_entry((int *)param_2,1);
  lVar10 = (longlong)(char)uVar4;
  if ((char)uVar4 < '\0') {
    return uVar4;
  }
  iVar6 = (&DAT_140074174)[lVar10 * 10];
  if (iVar6 == 0) {
    iVar6 = 1;
    (&DAT_140074174)[lVar10 * 10] = 1;
  }
  if ((iVar6 != 1) && (iVar6 != 2)) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("arp_table[i].state == PENDING or STABLE");
  }
  if ((iVar6 == 1) || (param_3 == (longlong *)0x0)) {
    uVar3 = etharp_request(param_1,param_2);
    uVar4 = CONCAT71(extraout_var,uVar3);
    if (param_3 == (longlong *)0x0) goto LAB_140010569;
  }
  uVar1 = (&DAT_140074174)[lVar10 * 10];
  uVar4 = (ulonglong)uVar1;
  if (uVar1 == 2) {
    uVar4 = (ulonglong)*(byte *)(param_1 + 0x30);
    lVar2 = param_3[1];
    if (*(byte *)(param_1 + 0x30) != 0) {
      puVar7 = (undefined1 *)(lVar2 + uVar4);
      do {
        puVar8 = puVar7 + -1;
        *puVar8 = puVar7[(lVar10 * 0x28 - lVar2) + 0x14007416b];
        puVar7[5] = puVar8[(param_1 + 0x31) - lVar2];
        bVar9 = (char)uVar4 - 1;
        uVar4 = (ulonglong)bVar9;
        puVar7 = puVar8;
      } while (bVar9 != 0);
    }
    *(undefined2 *)(lVar2 + 0xc) = 8;
    uVar4 = (**(code **)(param_1 + 0x20))(param_1,param_3);
    uVar3 = (undefined1)uVar4;
  }
  else if (uVar1 == 1) {
    plVar5 = pbuf_take(param_3);
    if (plVar5 == (longlong *)0x0) {
      uVar4 = lwip_printk();
    }
    else {
      if ((&DAT_140074160)[lVar10 * 5] == 0) {
        pbuf_ref((longlong)plVar5);
        (&DAT_140074160)[lVar10 * 5] = plVar5;
      }
      uVar4 = lwip_printk();
      uVar3 = 0;
    }
  }
LAB_140010569:
  return CONCAT71((int7)(uVar4 >> 8),uVar3);
}



===== etharp_request @ 140010590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 etharp_request(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte bVar7;
  ulonglong uVar8;
  
  lVar1 = param_1 + 0x31;
  puVar4 = pbuf_alloc(2,0x2a,0);
  if (puVar4 == (undefined8 *)0x0) {
    uVar3 = 0xff;
  }
  else {
    lVar2 = puVar4[1];
    *(undefined2 *)(lVar2 + 0x14) = 0x100;
    uVar8 = (ulonglong)*(byte *)(param_1 + 0x30);
    if (*(byte *)(param_1 + 0x30) != 0) {
      puVar6 = (undefined1 *)(lVar2 + 0x16 + uVar8);
      do {
        puVar5 = puVar6 + -1;
        *puVar5 = puVar5[lVar1 - (lVar2 + 0x16)];
        puVar6[9] = 0;
        bVar7 = (char)uVar8 - 1;
        uVar8 = (ulonglong)bVar7;
        puVar6 = puVar5;
      } while (bVar7 != 0);
    }
    *(undefined4 *)(lVar2 + 0x26) = *param_2;
    *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(param_1 + 0x120);
    *(undefined2 *)(lVar2 + 0xe) = 0x100;
    bVar7 = *(byte *)(param_1 + 0x30);
    *(undefined2 *)(lVar2 + 0x10) = 8;
    *(ushort *)(lVar2 + 0x12) = bVar7 | 0x400;
    uVar8 = (ulonglong)*(byte *)(param_1 + 0x30);
    if (*(byte *)(param_1 + 0x30) != 0) {
      puVar6 = (undefined1 *)(lVar1 + uVar8);
      do {
        puVar6 = puVar6 + -1;
        puVar6[lVar2 - lVar1] = 0xff;
        puVar6[(lVar2 - lVar1) + 6] = *puVar6;
        bVar7 = (char)uVar8 - 1;
        uVar8 = (ulonglong)bVar7;
      } while (bVar7 != 0);
    }
    *(undefined2 *)(lVar2 + 0xc) = 0x608;
    uVar3 = (**(code **)(param_1 + 0x20))(param_1,puVar4);
    pbuf_free(puVar4);
  }
  return uVar3;
}



===== etharp_tmr @ 1400106c0 =====

void etharp_tmr(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  
  piVar3 = &DAT_140074174;
  lVar4 = 10;
  do {
    iVar2 = *piVar3;
    bVar1 = (char)piVar3[1] + 1;
    *(byte *)(piVar3 + 1) = bVar1;
    if (iVar2 == 2) {
      if (bVar1 < 0xf0) goto LAB_140010701;
      *piVar3 = 3;
LAB_140010706:
      if (*(undefined8 **)(piVar3 + -5) != (undefined8 *)0x0) {
        pbuf_free(*(undefined8 **)(piVar3 + -5));
        piVar3[-5] = 0;
        piVar3[-4] = 0;
      }
      *piVar3 = 0;
    }
    else {
      if ((iVar2 == 1) && (1 < bVar1)) {
        iVar2 = 3;
        *piVar3 = 3;
      }
LAB_140010701:
      if (iVar2 == 3) goto LAB_140010706;
    }
    piVar3 = piVar3 + 10;
    lVar4 = lVar4 + -1;
    if (lVar4 == 0) {
      return;
    }
  } while( true );
}



===== find_entry @ 140010734 =====

ulonglong find_entry(int *param_1,byte param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  
  bVar9 = 10;
  bVar10 = 0;
  bVar13 = 0;
  bVar14 = 0;
  bVar7 = 10;
  bVar11 = 10;
  bVar8 = 10;
  bVar12 = 0;
  do {
    uVar6 = (ulonglong)bVar12;
    if ((bVar11 == 10) && (puVar5 = (undefined8 *)(uVar6 * 5), (&DAT_140074174)[uVar6 * 10] == 0)) {
      bVar11 = bVar12;
    }
    else {
      uVar2 = (&DAT_140074174)[uVar6 * 10];
      puVar5 = (undefined8 *)(ulonglong)uVar2;
      if (uVar2 == 1) {
        if ((param_1 != (int *)0x0) && (iVar3 = (&DAT_140074168)[uVar6 * 10], *param_1 == iVar3)) {
LAB_140010859:
          return (ulonglong)CONCAT31((int3)((uint)iVar3 >> 8),bVar12);
        }
        bVar1 = (&DAT_140074178)[uVar6 * 0x28];
        puVar5 = &DAT_140074160;
        if ((&DAT_140074160)[uVar6 * 5] == 0) {
          if (bVar10 <= bVar1) {
            bVar10 = bVar1;
            bVar9 = bVar12;
          }
        }
        else {
          bVar4 = bVar12;
          if (bVar1 < bVar14) {
            bVar4 = bVar8;
          }
          bVar8 = bVar4;
          puVar5 = (undefined8 *)0x0;
          if (bVar1 < bVar14) {
            bVar1 = bVar14;
          }
          bVar14 = bVar1;
        }
      }
      else if (uVar2 == 2) {
        if ((param_1 != (int *)0x0) && (iVar3 = (&DAT_140074168)[uVar6 * 10], *param_1 == iVar3))
        goto LAB_140010859;
        puVar5 = (undefined8 *)(uVar6 * 5);
        if (bVar13 <= (byte)(&DAT_140074178)[uVar6 * 0x28]) {
          bVar7 = bVar12;
          bVar13 = (&DAT_140074178)[uVar6 * 0x28];
        }
      }
    }
    bVar12 = bVar12 + 1;
  } while (bVar12 < 10);
  if (bVar11 == 10) {
    if ((param_2 & 1) == 0) goto LAB_140010800;
  }
  else if ((char)bVar11 < '\n') goto LAB_14001088c;
  if ((char)bVar7 < '\n') {
    bVar11 = bVar7;
    if ((&DAT_140074160)[(ulonglong)bVar7 * 5] != 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("arp_table[i].p == NULL");
    }
  }
  else if ((char)bVar9 < '\n') {
    bVar11 = bVar9;
  }
  else {
    if ('\t' < (char)bVar8) {
LAB_140010800:
      return CONCAT71((int7)((ulonglong)puVar5 >> 8),0xff);
    }
    pbuf_free((undefined8 *)(&DAT_140074160)[(ulonglong)bVar8 * 5]);
    (&DAT_140074160)[(ulonglong)bVar8 * 5] = 0;
    bVar11 = bVar8;
  }
LAB_14001088c:
  if (9 < bVar11) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("i < ARP_TABLE_SIZE");
  }
  uVar6 = (ulonglong)bVar11;
  (&DAT_140074174)[uVar6 * 10] = 0;
  if (param_1 != (int *)0x0) {
    (&DAT_140074168)[uVar6 * 10] = *param_1;
  }
  (&DAT_140074178)[uVar6 * 0x28] = 0;
  return (ulonglong)bVar11;
}



===== ntohs @ 140010900 =====

u_short __stdcall ntohs(u_short netshort)

{
  return netshort >> 8 | netshort << 8;
}



===== icmp_dest_unreach @ 140010910 =====

void icmp_dest_unreach(longlong param_1,ushort param_2)

{
  longlong lVar1;
  ushort *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  ushort uVar6;
  undefined8 *puVar7;
  
  puVar7 = pbuf_alloc(1,0x24,0);
  lVar1 = *(longlong *)(param_1 + 8);
  puVar2 = (ushort *)puVar7[1];
  *puVar2 = param_2 << 8 | (param_2 | 0x300) >> 8;
  puVar3 = *(undefined8 **)(param_1 + 8);
  lVar4 = puVar7[1];
  uVar5 = puVar3[1];
  *(undefined8 *)(lVar4 + 8) = *puVar3;
  *(undefined8 *)(lVar4 + 0x10) = uVar5;
  *(undefined8 *)(lVar4 + 0x18) = puVar3[2];
  *(undefined4 *)(lVar4 + 0x20) = *(undefined4 *)(puVar3 + 3);
  puVar2[1] = 0;
  uVar6 = lwip_standard_chksum((byte *)puVar2,*(ushort *)((longlong)puVar7 + 0x12));
  puVar2[1] = ~uVar6;
  crashdump_ip4_output((longlong)puVar7,(int *)0x0,(uint *)(lVar1 + 0xc),0x40,0,1);
  pbuf_free(puVar7);
  return;
}



===== inet_chksum_pbuf @ 1400109e4 =====

ushort inet_chksum_pbuf(longlong *param_1)

{
  ushort uVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = 0;
  cVar5 = '\0';
  if (param_1 != (longlong *)0x0) {
    do {
      uVar1 = *(ushort *)((longlong)param_1 + 0x12);
      uVar3 = lwip_standard_chksum((byte *)param_1[1],uVar1);
      uVar4 = (uint)uVar3;
      while( true ) {
        uVar6 = uVar7 + uVar4;
        uVar4 = uVar6 >> 0x10;
        if (uVar4 == 0) break;
        uVar7 = uVar6 & 0xffff;
      }
      param_1 = (longlong *)*param_1;
      cVar2 = '\x01' - cVar5;
      if ((uVar1 & 1) == 0) {
        cVar2 = cVar5;
      }
      cVar5 = cVar2;
      uVar7 = uVar6 & 0xffff;
      if ((uVar1 & 1) == 0) {
        uVar7 = uVar6;
      }
    } while (param_1 != (longlong *)0x0);
    if (cVar5 != '\0') {
      uVar7 = (uVar7 & 0xff) << 8 | uVar7 >> 8 & 0xff;
    }
  }
  return ~(ushort)uVar7;
}



===== inet_chksum_pseudo @ 140010a84 =====

undefined4
inet_chksum_pseudo(longlong *param_1,uint *param_2,uint *param_3,byte param_4,ushort param_5)

{
  ushort uVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  cVar2 = '\0';
  if (param_1 != (longlong *)0x0) {
    do {
      uVar1 = *(ushort *)((longlong)param_1 + 0x12);
      uVar3 = lwip_standard_chksum((byte *)param_1[1],uVar1);
      uVar4 = (uint)uVar3;
      while( true ) {
        uVar5 = uVar5 + uVar4;
        uVar4 = uVar5 >> 0x10;
        if (uVar4 == 0) break;
        uVar5 = uVar5 & 0xffff;
      }
      if ((uVar1 & 1) != 0) {
        cVar2 = '\x01' - cVar2;
        uVar5 = (uVar5 & 0xff) << 8 | uVar5 >> 8 & 0xff;
      }
      param_1 = (longlong *)*param_1;
    } while (param_1 != (longlong *)0x0);
    if (cVar2 != '\0') {
      uVar5 = (uVar5 & 0xff) << 8 | uVar5 >> 8 & 0xff;
    }
  }
  uVar5 = (*param_3 & 0xffff) + uVar5 +
          (uint)param_4 * 0x100 + (uint)(ushort)(param_5 << 8 | param_5 >> 8) +
          (uint)*(ushort *)((longlong)param_2 + 2) + (uint)*(ushort *)((longlong)param_3 + 2) +
          (*param_2 & 0xffff);
  while( true ) {
    if (uVar5 >> 0x10 == 0) break;
    uVar5 = (uVar5 & 0xffff) + (uVar5 >> 0x10);
  }
  return CONCAT22((short)(uVar5 >> 0x10),~(ushort)uVar5);
}



===== ip_addr_isbroadcast @ 140010b84 =====

ulonglong ip_addr_isbroadcast(uint *param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = *param_1;
  uVar4 = (ulonglong)~uVar3;
  if ((~uVar3 == 0) || (uVar3 == 0)) {
LAB_140010bc7:
    return CONCAT71((int7)(uVar4 >> 8),1);
  }
  if ((*(byte *)(param_2 + 0x3a) & 2) != 0) {
    uVar1 = *(uint *)(param_2 + 0x120);
    uVar4 = (ulonglong)uVar1;
    if (uVar3 != uVar1) {
      uVar2 = *(uint *)(param_2 + 0x124);
      uVar4 = (ulonglong)(uVar2 & uVar3);
      if (((uVar2 & uVar3) == (uVar2 & uVar1)) &&
         (uVar3 = ~uVar2 & uVar3, uVar4 = (ulonglong)uVar3, uVar3 == ~uVar2)) goto LAB_140010bc7;
    }
  }
  return uVar4 & 0xffffffffffffff00;
}



===== ip_output_if @ 140010bcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
ip_output_if(longlong param_1,int *param_2,undefined4 *param_3,undefined1 param_4,byte param_5,
            undefined1 param_6,longlong param_7)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  
  if (param_3 == (undefined4 *)0x0) {
    param_3 = (undefined4 *)(*(longlong *)(param_1 + 8) + 0x10);
  }
  else {
    uVar5 = pbuf_header(param_1,0x14);
    uVar3 = DAT_140072470;
    if ((char)uVar5 != '\0') {
      return CONCAT71((int7)(uVar5 >> 8),0xfe);
    }
    puVar1 = *(ushort **)(param_1 + 8);
    puVar1[4] = CONCAT11(param_6,param_4);
    *(undefined4 *)(puVar1 + 8) = *param_3;
    *puVar1 = (ushort)param_5 << 8 | 0x45;
    puVar1[1] = *(ushort *)(param_1 + 0x10) << 8 | *(ushort *)(param_1 + 0x10) >> 8;
    puVar1[3] = 0x40;
    uVar2 = DAT_140072470 >> 8;
    DAT_140072470 = uVar3 + 1;
    puVar1[2] = uVar3 << 8 | uVar2;
    if ((param_2 == (int *)0x0) || (iVar4 = *param_2, iVar4 == 0)) {
      if ((int *)(param_7 + 0x120) == (int *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(param_7 + 0x120);
      }
    }
    *(int *)(puVar1 + 6) = iVar4;
    puVar1[5] = 0;
    uVar3 = lwip_standard_chksum((byte *)puVar1,0x14);
    puVar1[5] = ~uVar3;
  }
  uVar6 = (**(code **)(param_7 + 0x18))(param_7,param_1,param_3);
  return uVar6;
}



===== ip_route @ 140010d14 =====

longlong * ip_route(uint *param_1)

{
  longlong *plVar1;
  
  if (netif_list != (longlong *)0x0) {
    plVar1 = netif_list;
    do {
      if ((*param_1 & *(uint *)((longlong)plVar1 + 0x124)) ==
          (*(uint *)(plVar1 + 0x24) & *(uint *)((longlong)plVar1 + 0x124))) {
        return plVar1;
      }
      plVar1 = (longlong *)*plVar1;
    } while (plVar1 != (longlong *)0x0);
  }
  return netif_default;
}



===== lwip_printk @ 140010d50 =====

void lwip_printk(void)

{
  return;
}



===== lwip_standard_chksum @ 140010d60 =====

ushort lwip_standard_chksum(byte *param_1,ushort param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  ulonglong uVar4;
  
  uVar2 = 0;
  if (1 < param_2) {
    uVar4 = (ulonglong)(ushort)(((ushort)(param_2 - 2) >> 1) + 1);
    do {
      bVar1 = *param_1;
      pbVar3 = param_1 + 1;
      param_1 = param_1 + 2;
      param_2 = param_2 - 2;
      uVar2 = uVar2 + CONCAT11(bVar1,*pbVar3);
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (param_2 != 0) {
    uVar2 = uVar2 + (uint)*param_1 * 0x100;
  }
  uVar2 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  if ((uVar2 & 0xffff0000) != 0) {
    uVar2 = uVar2 + (uVar2 >> 0x10);
  }
  return (ushort)(uVar2 >> 8) & 0xff | (short)uVar2 << 8;
}



===== netif_add @ 140010de8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 *
netif_add(undefined8 *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
         undefined8 param_5,undefined *param_6,undefined8 param_7,undefined8 param_8)

{
  char cVar1;
  
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)((longlong)param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x25) = 0;
  param_1[5] = param_5;
  *(char *)((longlong)param_1 + 0x3d) = (char)DAT_140072420;
  DAT_140072420 = DAT_140072420 + 1;
  param_1[2] = param_8;
  *(undefined1 *)((longlong)param_1 + 0x3a) = 0;
  netif_set_addr((longlong)param_1,param_2,param_3,param_4);
  cVar1 = (*(code *)param_6)(param_1);
  if (cVar1 == '\0') {
    param_1[1] = param_7;
    *param_1 = netif_list;
    netif_list = param_1;
  }
  else {
    param_1 = (undefined8 *)0x0;
  }
  return param_1;
}



===== netif_remove @ 140010e70 =====

void netif_remove(undefined8 *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    if (netif_list == param_1) {
      netif_list = (longlong *)*param_1;
    }
    else {
      plVar2 = netif_list;
      if (netif_list == (longlong *)0x0) {
        return;
      }
      while (plVar1 = (longlong *)*plVar2, plVar1 != param_1) {
        plVar2 = plVar1;
        if (plVar1 == (longlong *)0x0) {
          return;
        }
      }
      *plVar2 = *param_1;
    }
    if (netif_default == param_1) {
      netif_default = (undefined8 *)0x0;
    }
  }
  return;
}



===== netif_set_addr @ 140010ebc =====

void netif_set_addr(longlong param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  netif_set_ipaddr(param_1,param_2);
  uVar1 = 0;
  uVar2 = 0;
  if (param_3 != (undefined4 *)0x0) {
    uVar2 = *param_3;
  }
  *(undefined4 *)(param_1 + 0x124) = uVar2;
  if (param_4 != (undefined4 *)0x0) {
    uVar1 = *param_4;
  }
  *(undefined4 *)(param_1 + 0x128) = uVar1;
  return;
}



===== netif_set_down @ 140010f08 =====

void netif_set_down(longlong param_1)

{
  *(byte *)(param_1 + 0x3a) = *(byte *)(param_1 + 0x3a) & 0xfe;
  return;
}



===== netif_set_ipaddr @ 140010f10 =====

void netif_set_ipaddr(longlong param_1,int *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int *piVar3;
  
  piVar3 = tcp_listen_pcbs;
  puVar1 = tcp_active_pcbs;
  if (*param_2 != *(int *)(param_1 + 0x120)) {
    while( true ) {
      puVar2 = puVar1;
      tcp_listen_pcbs = piVar3;
      if (puVar2 == (uint *)0x0) break;
      puVar1 = *(uint **)(puVar2 + 4);
      if (*puVar2 == *(uint *)(param_1 + 0x120)) {
        tcp_abort(puVar2);
        piVar3 = tcp_listen_pcbs;
      }
    }
    for (; piVar3 != (int *)0x0; piVar3 = *(int **)(piVar3 + 4)) {
      if (*piVar3 == *(int *)(param_1 + 0x120)) {
        *piVar3 = *param_2;
      }
    }
  }
  *(int *)(param_1 + 0x120) = *param_2;
  return;
}



===== stack_ipv4_bringup @ 140010f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 stack_ipv4_bringup(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  
  puVar1 = (undefined8 *)(param_1 + 0x138);
  iVar3 = 0;
  mem_init();
  memp_init();
  pbuf_init();
  netif_default = (undefined8 *)0x0;
  netif_list = 0;
  lVar2 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  puVar4 = netif_add(puVar1,(int *)(lVar2 + 0x458),(undefined4 *)(lVar2 + 0x468),
                     (undefined4 *)(lVar2 + 0x478),*l2_driver_intf,(undefined *)l2_driver_intf[10],
                     l2_driver_intf[0xb],crashdump_ip4_input);
  if (puVar4 != (undefined8 *)0x0) {
    netif_default = puVar1;
    *(undefined1 *)(param_1 + 0x172) = 2;
    *(undefined2 *)(param_1 + 0x170) = 0x5dc;
    *(undefined1 *)(param_1 + 0x168) = 6;
    (*(code *)l2_driver_intf[6])(*l2_driver_intf,param_1 + 0x169);
    etharp_init();
    puVar5 = iscsiAddTimer(5000,etharp_tmr);
    *(undefined2 **)(param_1 + 0x128) = puVar5;
    puVar5 = iscsiAddTimer(0xfa,tcp_tmr);
    *(undefined2 **)(param_1 + 0x130) = puVar5;
    iVar6 = 0;
    do {
      if (iVar6 == 60000) break;
      mm_delay(1000);
      iVar3 = (*(code *)l2_driver_intf[9])(*l2_driver_intf);
      iVar6 = iVar6 + 1;
    } while (iVar3 != 1);
    if (iVar3 == 1) {
      *(byte *)(param_1 + 0x172) = *(byte *)(param_1 + 0x172) | 1;
      (**(code **)(param_1 + 0x140))(puVar1);
      return 0;
    }
  }
  return 0xffffffff;
}



===== stack_ipv4_close_connection @ 140011100 =====

char stack_ipv4_close_connection(uint *param_1)

{
  uint uVar1;
  char cVar2;
  undefined8 uVar3;
  int iVar4;
  
  uVar1 = param_1[6];
  if (uVar1 == 0) {
    cVar2 = '\0';
    memp_free(3,(longlong)param_1);
    param_1 = (uint *)0x0;
LAB_14000f553:
    if ((param_1 != (uint *)0x0) && (cVar2 == '\0')) {
      uVar3 = crashdump_tcp4_output(param_1);
      cVar2 = (char)uVar3;
    }
  }
  else {
    if (uVar1 == 1) {
      tcp_pcb_remove(&tcp_listen_pcbs,param_1);
      iVar4 = 4;
    }
    else {
      if (uVar1 != 2) {
        if ((uVar1 == 3) || (uVar1 == 4)) {
          uVar3 = tcp_enqueue((longlong)param_1,(void *)0x0,0,1,'\x01',(void *)0x0,0);
          cVar2 = (char)uVar3;
          if (cVar2 == '\0') {
            param_1[6] = 5;
          }
        }
        else {
          if (uVar1 != 7) {
            return '\0';
          }
          uVar3 = tcp_enqueue((longlong)param_1,(void *)0x0,0,1,'\x01',(void *)0x0,0);
          cVar2 = (char)uVar3;
          if (cVar2 == '\0') {
            param_1[6] = 9;
          }
        }
        goto LAB_14000f553;
      }
      tcp_pcb_remove(&tcp_active_pcbs,param_1);
      iVar4 = 3;
    }
    cVar2 = '\0';
    memp_free(iVar4,(longlong)param_1);
  }
  return cVar2;
}



===== stack_ipv4_connected_callback @ 140011110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong stack_ipv4_connected_callback(undefined *param_1,undefined8 param_2,char param_3)

{
  ulonglong uVar1;
  
  uVar1 = (*(code *)param_1)(param_2,param_3 == '\0');
  return uVar1 & 0xffffffffffffff00;
}



===== stack_ipv4_flush_tcp_data @ 140011140 =====

int stack_ipv4_flush_tcp_data(uint *param_1)

{
  undefined8 uVar1;
  
  uVar1 = crashdump_tcp4_output(param_1);
  return -(uint)((char)uVar1 != '\0');
}



===== stack_ipv4_init @ 140011154 =====

void stack_ipv4_init(undefined8 *param_1)

{
  *param_1 = stack_ipv4_bringup;
  param_1[1] = stack_ipv4_set_addr;
  param_1[2] = stack_ipv4_rx_packet;
  param_1[3] = stack_ipv4_setup_connection;
  param_1[4] = stack_ipv4_close_connection;
  param_1[5] = stack_ipv4_write_tcp_data;
  param_1[6] = stack_ipv4_flush_tcp_data;
  return;
}



===== stack_ipv4_rx_packet @ 1400111b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void stack_ipv4_rx_packet(longlong param_1,longlong param_2,ushort param_3)

{
  ushort *puVar1;
  longlong *plVar2;
  ushort uVar3;
  int iVar4;
  longlong *plVar5;
  
  plVar2 = pbuf_alloc(3,param_3,3);
  if (plVar2 != (longlong *)0x0) {
    iVar4 = 0;
    plVar5 = plVar2;
    do {
      memmove((void *)plVar5[1],(void *)(iVar4 + param_2),
              (ulonglong)*(ushort *)((longlong)plVar5 + 0x12));
      puVar1 = (ushort *)((longlong)plVar5 + 0x12);
      plVar5 = (longlong *)*plVar5;
      iVar4 = iVar4 + (uint)*puVar1;
    } while (plVar5 != (longlong *)0x0);
    *(ushort *)(plVar2 + 2) = param_3;
    uVar3 = *(ushort *)(plVar2[1] + 0xc) << 8 | *(ushort *)(plVar2[1] + 0xc) >> 8;
    if (uVar3 == 0x800) {
      pbuf_header((longlong)plVar2,-0xe);
      (**(code **)(param_1 + 0x10))(plVar2,param_1);
    }
    else if (uVar3 == 0x806) {
      etharp_arp_input(param_1,param_1 + 0x31,plVar2);
    }
    else {
      pbuf_free(plVar2);
    }
  }
  return;
}



===== stack_ipv4_rx_tcp_data @ 140011290 =====

undefined1 *
stack_ipv4_rx_tcp_data(undefined8 param_1,uint *param_2,longlong *param_3,undefined8 param_4)

{
  uint7 extraout_var;
  longlong *plVar1;
  ushort uVar2;
  longlong *plVar3;
  
  if (param_3 != (longlong *)0x0) {
    uVar2 = 0;
    plVar1 = param_3;
    plVar3 = param_3;
    do {
      uVar2 = uVar2 + *(ushort *)((longlong)plVar1 + 0x12);
      iscsiSessionServiceRxIndication
                ((char *)plVar1[1],*(ushort *)((longlong)plVar1 + 0x12),plVar3,param_4);
      plVar1 = (longlong *)*plVar1;
    } while (plVar1 != (longlong *)0x0);
    crashdump_tcp4_recved(param_2,uVar2);
    pbuf_free(param_3);
    register0x00000020 = (BADSPACEBASE *)((ulonglong)extraout_var << 8);
  }
  return (undefined1 *)register0x00000020;
}



===== stack_ipv4_set_addr @ 140011310 =====

void stack_ipv4_set_addr(longlong param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  netif_set_addr(param_1 + 0x138,param_2,param_3,param_4);
  return;
}



===== stack_ipv4_setup_connection @ 140011320 =====

uint * stack_ipv4_setup_connection(uint *param_1,undefined2 param_2,undefined8 param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)tcp_alloc(0x40);
  *(code **)(puVar1 + 0x28) = stack_ipv4_rx_tcp_data;
  *(code **)(puVar1 + 0x26) = CrashDumpIsr;
  *(undefined8 *)(puVar1 + 8) = param_3;
  tcp_connect(puVar1,param_1,param_2,stack_ipv4_connected_callback);
  return puVar1;
}



===== stack_ipv4_write_tcp_data @ 1400113a0 =====

int stack_ipv4_write_tcp_data(longlong param_1,void *param_2,ushort param_3,char param_4)

{
  undefined8 uVar1;
  
  uVar1 = tcp_write(param_1,param_2,param_3,param_4);
  return -(uint)((char)uVar1 != '\0');
}



===== tcp_abort @ 1400113b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void tcp_abort(uint *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  undefined8 uVar5;
  uint uVar6;
  uint local_res8 [2];
  uint local_res10 [2];
  
  if (param_1[6] == 10) {
    tcp_pcb_remove(&tcp_tw_pcbs,param_1);
    memp_free(3,(longlong)param_1);
  }
  else {
    local_res10[0] = *param_1;
    uVar2 = param_1[0x18];
    uVar3 = param_1[0xc];
    local_res8[0] = 0;
    if (param_1 + 1 != (uint *)0x0) {
      local_res8[0] = param_1[1];
    }
    uVar6 = param_1[10];
    uVar1 = *(ushort *)((longlong)param_1 + 0x2a);
    pcVar4 = *(code **)(param_1 + 0x30);
    uVar5 = *(undefined8 *)(param_1 + 8);
    tcp_pcb_remove(&tcp_active_pcbs,param_1);
    if (*(undefined8 **)(param_1 + 0x22) != (undefined8 *)0x0) {
      tcp_segs_free(*(undefined8 **)(param_1 + 0x22));
    }
    if (*(undefined8 **)(param_1 + 0x20) != (undefined8 *)0x0) {
      tcp_segs_free(*(undefined8 **)(param_1 + 0x20));
    }
    if (*(undefined8 **)(param_1 + 0x24) != (undefined8 *)0x0) {
      tcp_segs_free(*(undefined8 **)(param_1 + 0x24));
    }
    memp_free(3,(longlong)param_1);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(uVar5,0xfd);
    }
    tcp_rst(uVar2,uVar3,local_res10,local_res8,(ushort)uVar6,uVar1);
  }
  return;
}



===== tcp_alloc @ 1400114bc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * tcp_alloc(byte param_1)

{
  byte bVar1;
  uint uVar2;
  undefined8 *_Dst;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  byte bVar6;
  
  _Dst = memp_malloc(3);
  if (_Dst == (undefined8 *)0x0) {
    uVar5 = 0;
    puVar4 = (uint *)0x0;
    puVar3 = tcp_tw_pcbs;
    if (tcp_tw_pcbs != (uint *)0x0) {
      do {
        uVar2 = _tcp_ticks - puVar3[0xe];
        if (uVar5 <= uVar2) {
          puVar4 = puVar3;
        }
        puVar3 = *(uint **)(puVar3 + 4);
        if (uVar2 < uVar5) {
          uVar2 = uVar5;
        }
        uVar5 = uVar2;
      } while (puVar3 != (uint *)0x0);
      if (puVar4 != (uint *)0x0) {
        lwip_printk();
        tcp_abort(puVar4);
      }
    }
    _Dst = memp_malloc(3);
    if (_Dst == (undefined8 *)0x0) {
      bVar6 = 0x7f;
      uVar5 = 0;
      puVar4 = (uint *)0x0;
      puVar3 = tcp_active_pcbs;
      if (tcp_active_pcbs != (uint *)0x0) {
        do {
          bVar1 = (byte)puVar3[7];
          if (((bVar1 <= param_1) && (bVar1 <= bVar6)) && (uVar5 <= _tcp_ticks - puVar3[0xe])) {
            puVar4 = puVar3;
            bVar6 = bVar1;
            uVar5 = _tcp_ticks - puVar3[0xe];
          }
          puVar3 = *(uint **)(puVar3 + 4);
        } while (puVar3 != (uint *)0x0);
        if (puVar4 != (uint *)0x0) {
          tcp_abort(puVar4);
        }
      }
      _Dst = memp_malloc(3);
      if (_Dst == (undefined8 *)0x0) {
        return (undefined8 *)0x0;
      }
    }
  }
  memset(_Dst,0,0xd0);
  *(undefined2 *)((longlong)_Dst + 0x7a) = 0xffff;
  *(undefined2 *)((longlong)_Dst + 0x34) = 0xffff;
  *(undefined2 *)((longlong)_Dst + 0x5a) = 1;
  *(undefined1 *)((longlong)_Dst + 0x1c) = 0x40;
  *(undefined2 *)((longlong)_Dst + 10) = 0x4000;
  *(undefined4 *)((longlong)_Dst + 0x3e) = 0x5b40000;
  *(undefined4 *)((longlong)_Dst + 0x4e) = 0x60006;
  *(undefined2 *)((longlong)_Dst + 0x4c) = 0;
  DAT_14002d8e4 = DAT_14002d8e4 + _tcp_ticks;
  *(int *)(_Dst + 0xe) = DAT_14002d8e4;
  *(int *)(_Dst + 0xc) = DAT_14002d8e4;
  *(int *)((longlong)_Dst + 100) = DAT_14002d8e4;
  *(int *)((longlong)_Dst + 0x54) = DAT_14002d8e4;
  *(int *)((longlong)_Dst + 0x74) = DAT_14002d8e4;
  *(int *)(_Dst + 7) = _tcp_ticks;
  _Dst[0x14] = tcp_recv_null;
  *(undefined1 *)((longlong)_Dst + 0x3c) = 0;
  *(undefined4 *)(_Dst + 0x19) = 7200000;
  *(undefined1 *)((longlong)_Dst + 0xcc) = 0;
  return _Dst;
}



===== tcp_connect @ 140011654 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong tcp_connect(uint *param_1,uint *param_2,undefined2 param_3,undefined8 param_4)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined8 in_RAX;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  undefined7 uVar7;
  uint local_res18 [4];
  
  uVar6 = (undefined1)param_4;
  uVar7 = (undefined7)((ulonglong)param_4 >> 8);
  if (param_2 == (uint *)0x0) {
    uVar5 = CONCAT71((int7)((ulonglong)in_RAX >> 8),0xf9);
  }
  else {
    param_1[1] = *param_2;
    *(undefined2 *)((longlong)param_1 + 0x2a) = param_3;
    if ((short)param_1[10] == 0) {
      uVar2 = tcp_new_port();
      *(undefined2 *)(param_1 + 10) = uVar2;
    }
    DAT_14002d8e4 = _tcp_ticks + DAT_14002d8e4;
    param_1[0x18] = DAT_14002d8e4;
    uVar3 = DAT_14002d8e4 - 1;
    param_1[0x15] = uVar3;
    param_1[0x1d] = uVar3;
    *(undefined2 *)(param_1 + 0xd) = 0xffff;
    param_1[0x1a] = 0xffff;
    *(undefined2 *)(param_1 + 0x10) = 0x5b4;
    *(ulonglong *)(param_1 + 0x2a) = CONCAT71(uVar7,uVar6);
    param_1[0xc] = 0;
    *(undefined4 *)((longlong)param_1 + 0x5a) = 0x39080001;
    param_1[6] = 2;
    *(uint **)(param_1 + 4) = tcp_active_pcbs;
    local_res18[0] =
         ((uint)(ushort)param_1[0x10] << 0x10 | (ushort)param_1[0x10] & 0xff00) << 8 | 0x402;
    tcp_active_pcbs = param_1;
    uVar4 = tcp_enqueue((longlong)param_1,(void *)0x0,0,2,'\0',local_res18,4);
    cVar1 = (char)uVar4;
    if (cVar1 == '\0') {
      uVar4 = crashdump_tcp4_output(param_1);
    }
    uVar5 = CONCAT71((int7)((ulonglong)uVar4 >> 8),cVar1);
  }
  return uVar5;
}



===== tcp_enqueue @ 140011750 =====

undefined8
tcp_enqueue(longlong param_1,void *param_2,ushort param_3,byte param_4,char param_5,void *param_6,
           byte param_7)

{
  ushort *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ushort uVar4;
  ulonglong in_RAX;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  ulonglong uVar8;
  uint7 extraout_var;
  uint7 extraout_var_00;
  char *pcVar9;
  byte bVar10;
  undefined8 *puVar11;
  ushort uVar12;
  int iVar13;
  uint uVar14;
  ulonglong _Size;
  undefined8 *local_res8;
  uint local_res18;
  void *local_58;
  
  puVar11 = (undefined8 *)0x0;
  if ((param_3 != 0) && (param_7 != 0)) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("tcp_enqueue: len == 0 || optlen == 0 (programmer violates API)");
  }
  if ((param_2 != (void *)0x0) && (param_6 != (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("tcp_enqueue: arg == NULL || optdata == NULL (programmer violates API)");
  }
  if (param_3 <= *(ushort *)(param_1 + 0x7a)) {
    bVar10 = *(byte *)(param_1 + 0x7c);
    uVar14 = (uint)param_3;
    local_res18 = *(uint *)(param_1 + 0x74);
    in_RAX = (ulonglong)local_res18;
    if (bVar10 < 0xb3) {
      if (bVar10 == 0) {
        if ((*(longlong *)(param_1 + 0x88) != 0) || (*(longlong *)(param_1 + 0x80) != 0)) {
          pcVar9 = "tcp_enqueue: no pbufs on queue => both queues empty";
          goto LAB_140011815;
        }
      }
      else if ((*(longlong *)(param_1 + 0x88) == 0) && (*(longlong *)(param_1 + 0x80) == 0)) {
        pcVar9 = "tcp_enqueue: pbufs on queue => at least one queue non-empty";
LAB_140011815:
                    /* WARNING: Subroutine does not return */
        DbgPrint(pcVar9);
      }
      local_res8 = (undefined8 *)0x0;
      _Size = 0;
      local_58 = param_2;
LAB_14001182d:
      iVar13 = 0;
      if ((puVar11 != (undefined8 *)0x0) && (uVar14 == 0)) {
        puVar5 = *(undefined8 **)(param_1 + 0x80);
        puVar6 = local_res8;
        if (puVar5 == (undefined8 *)0x0) {
          *(undefined8 **)(param_1 + 0x80) = puVar11;
        }
        else {
          for (puVar3 = (undefined8 *)*puVar5; puVar3 != (undefined8 *)0x0;
              puVar3 = (undefined8 *)*puVar3) {
            puVar5 = puVar3;
          }
          uVar4 = *(ushort *)(puVar5[4] + 0xc) >> 8;
          if (((uVar4 & 1) != 0) || ((uVar4 & 2) != 0)) {
            iVar13 = 1;
          }
          if ((((iVar13 + (uint)*(ushort *)(puVar5 + 3) == 0) || ((uVar4 & 3) != 0)) ||
              ((param_4 & 3) != 0)) ||
             ((uint)*(ushort *)(param_1 + 0x40) <
              (uint)*(ushort *)(puVar11 + 3) + (uint)*(ushort *)(puVar5 + 3))) {
            *puVar5 = puVar11;
          }
          else {
            pbuf_header(puVar11[1],-0x14);
            pbuf_cat((longlong *)puVar5[1],puVar11[1]);
            *(short *)(puVar5 + 3) = *(short *)(puVar5 + 3) + *(short *)(puVar11 + 3);
            *puVar5 = *puVar11;
            memp_free(5,(longlong)puVar11);
            puVar6 = (undefined8 *)0x0;
            if (local_res8 != puVar11) {
              puVar6 = local_res8;
            }
          }
        }
        *(byte *)(param_1 + 0x7c) = bVar10;
        uVar4 = param_3 + 1;
        if ((param_4 & 3) == 0) {
          uVar4 = param_3;
        }
        uVar8 = (ulonglong)uVar4;
        *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + (uint)uVar4;
        *(short *)(param_1 + 0x7a) = *(short *)(param_1 + 0x7a) - uVar4;
        if (((bVar10 != 0) && (*(longlong *)(param_1 + 0x88) == 0)) &&
           (*(longlong *)(param_1 + 0x80) == 0)) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_enqueue: valid queue length");
        }
        if (((puVar6 != (undefined8 *)0x0) && ((short)_Size != 0)) &&
           (lVar2 = puVar6[4], lVar2 != 0)) {
          uVar4 = *(ushort *)(lVar2 + 0xc);
          uVar8 = (ulonglong)(ushort)(uVar4 << 8);
          *(ushort *)(lVar2 + 0xc) = uVar4 & 0xff00 | 0x800 | uVar4 & 0xff;
        }
        return uVar8 & 0xffffffffffffff00;
      }
      uVar4 = *(ushort *)(param_1 + 0x40);
      if (uVar14 <= *(ushort *)(param_1 + 0x40)) {
        uVar4 = (ushort)uVar14;
      }
      _Size = (ulonglong)uVar4;
      puVar5 = memp_malloc(5);
      in_RAX = 0;
      if (puVar5 == (undefined8 *)0x0) goto LAB_140011c04;
      *puVar5 = 0;
      puVar5[1] = 0;
      if (puVar11 == (undefined8 *)0x0) {
        puVar11 = puVar5;
      }
      else {
        if (local_res8 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("useg != NULL");
        }
        *local_res8 = puVar5;
      }
      if (param_6 == (void *)0x0) {
        if (param_5 != '\0') {
          puVar6 = pbuf_alloc(0,uVar4,0);
          puVar5[1] = puVar6;
          in_RAX = 0;
          if (puVar6 != (undefined8 *)0x0) {
            if (param_2 != (void *)0x0) {
              memmove((void *)puVar6[1],local_58,_Size);
              puVar6 = (undefined8 *)puVar5[1];
            }
            goto LAB_14001191d;
          }
          goto LAB_140011c04;
        }
        puVar6 = pbuf_alloc(0,uVar4,1);
        in_RAX = 0;
        if (puVar6 == (undefined8 *)0x0) goto LAB_140011c04;
        puVar6[1] = local_58;
        puVar5[2] = local_58;
        plVar7 = pbuf_alloc(0,0,0);
        puVar5[1] = plVar7;
        if (plVar7 == (longlong *)0x0) {
          pbuf_free(puVar6);
          in_RAX = (ulonglong)extraout_var << 8;
LAB_140011c04:
          if (puVar11 != (undefined8 *)0x0) {
            tcp_segs_free(puVar11);
            in_RAX = (ulonglong)extraout_var_00 << 8;
          }
          if (((*(char *)(param_1 + 0x7c) != '\0') && (*(longlong *)(param_1 + 0x88) == 0)) &&
             (*(longlong *)(param_1 + 0x80) == 0)) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_enqueue: valid queue length");
          }
          goto LAB_140011c39;
        }
        bVar10 = bVar10 + 2;
        in_RAX = pbuf_cat(plVar7,(longlong)puVar6);
      }
      else {
        puVar6 = pbuf_alloc(0,(ushort)param_7,0);
        puVar5[1] = puVar6;
        in_RAX = 0;
        if (puVar6 == (undefined8 *)0x0) goto LAB_140011c04;
LAB_14001191d:
        bVar10 = bVar10 + 1;
        in_RAX = puVar6[1];
        puVar5[2] = in_RAX;
      }
      if (0xb3 < bVar10) goto LAB_140011c04;
      *(ushort *)(puVar5 + 3) = uVar4;
      in_RAX = pbuf_header(puVar5[1],0x14);
      if ((char)in_RAX != '\0') goto LAB_140011c04;
      puVar1 = *(ushort **)(puVar5[1] + 8);
      puVar5[4] = puVar1;
      *puVar1 = *(ushort *)(param_1 + 0x28) << 8 | *(ushort *)(param_1 + 0x28) >> 8;
      *(ushort *)(puVar5[4] + 2) =
           *(ushort *)(param_1 + 0x2a) << 8 | *(ushort *)(param_1 + 0x2a) >> 8;
      *(uint *)(puVar5[4] + 4) =
           local_res18 >> 0x18 | (local_res18 & 0xff0000) >> 8 | (local_res18 & 0xff00) << 8 |
           local_res18 << 0x18;
      *(undefined2 *)(puVar5[4] + 0x12) = 0;
      uVar12 = *(ushort *)(puVar5[4] + 0xc);
      *(ushort *)(puVar5[4] + 0xc) = (uVar12 >> 8 & 0xc0 | (ushort)param_4) << 8 | uVar12 & 0xff;
      lVar2 = puVar5[4];
      uVar12 = (ushort)(*(byte *)(lVar2 + 0xd) & 0x3f);
      if (param_6 == (void *)0x0) {
        *(ushort *)(lVar2 + 0xc) = uVar12 << 8 | 0x50;
      }
      else {
        *(ushort *)(lVar2 + 0xc) = uVar12 << 8 | ((param_7 & 0xfffc) + 0x14 & 0x3f) << 2;
        memmove((void *)puVar5[2],param_6,(ulonglong)param_7);
      }
      local_res18 = local_res18 + uVar4;
      uVar14 = uVar14 - uVar4;
      local_58 = (void *)((longlong)local_58 + _Size);
      local_res8 = puVar5;
      goto LAB_14001182d;
    }
  }
LAB_140011c39:
  return CONCAT71((int7)(in_RAX >> 8),0xff);
}



===== tcp_fasttmr @ 140011c4c =====

void tcp_fasttmr(void)

{
  uint *puVar1;
  
  for (puVar1 = tcp_active_pcbs; puVar1 != (uint *)0x0; puVar1 = *(uint **)(puVar1 + 4)) {
    if (((byte)puVar1[0xb] & 1) != 0) {
      *(byte *)(puVar1 + 0xb) = (byte)puVar1[0xb] | 2;
      crashdump_tcp4_output(puVar1);
      *(byte *)(puVar1 + 0xb) = (byte)puVar1[0xb] & 0xfc;
    }
  }
  return;
}



===== tcp_keepalive @ 140011c84 =====

void tcp_keepalive(uint *param_1)

{
  ushort *puVar1;
  undefined4 uVar2;
  longlong *plVar3;
  uint uVar4;
  
  plVar3 = pbuf_alloc(1,0x14,0);
  if (plVar3 != (longlong *)0x0) {
    puVar1 = (ushort *)plVar3[1];
    *puVar1 = (ushort)param_1[10] << 8 | (ushort)param_1[10] >> 8;
    puVar1[1] = *(ushort *)((longlong)param_1 + 0x2a) << 8 |
                *(ushort *)((longlong)param_1 + 0x2a) >> 8;
    uVar4 = param_1[0x18] - 1;
    *(uint *)(puVar1 + 2) =
         uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 * 0x1000000;
    uVar4 = param_1[0xc];
    *(uint *)(puVar1 + 4) =
         (uVar4 << 0x10 | uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 |
         (uint)*(byte *)((longlong)param_1 + 0x33);
    puVar1[7] = (ushort)param_1[0xd] << 8 | (ushort)param_1[0xd] >> 8;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[6] = (ushort)(*(byte *)((longlong)puVar1 + 0xd) & 0x3f) << 8 | 0x50;
    uVar2 = inet_chksum_pseudo(plVar3,param_1,param_1 + 1,6,*(ushort *)(plVar3 + 2));
    puVar1[8] = (ushort)uVar2;
    crashdump_ip4_output
              ((longlong)plVar3,(int *)param_1,param_1 + 1,*(undefined1 *)((longlong)param_1 + 0xb),
               0,6);
    pbuf_free(plVar3);
  }
  return;
}



===== tcp_new_port @ 140011d94 =====

void tcp_new_port(void)

{
  longlong lVar1;
  
LAB_140011d9b:
  do {
    DAT_14002d8e0 = DAT_14002d8e0 + 1;
    if (0x7fff < DAT_14002d8e0) {
      DAT_14002d8e0 = 0x1000;
    }
    for (lVar1 = tcp_active_pcbs; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x10)) {
      if (*(ushort *)(lVar1 + 0x28) == DAT_14002d8e0) goto LAB_140011d9b;
    }
    for (lVar1 = tcp_tw_pcbs; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x10)) {
      if (*(ushort *)(lVar1 + 0x28) == DAT_14002d8e0) goto LAB_140011d9b;
    }
    lVar1 = tcp_listen_pcbs;
    while( true ) {
      if (lVar1 == 0) {
        return;
      }
      if (*(ushort *)(lVar1 + 0x28) == DAT_14002d8e0) break;
      lVar1 = *(longlong *)(lVar1 + 0x10);
    }
  } while( true );
}



===== tcp_parseopt @ 140011e04 =====

void tcp_parseopt(longlong param_1)

{
  char cVar1;
  ulonglong uVar2;
  ushort uVar3;
  int iVar4;
  byte bVar5;
  
  if (0x5000 < (ushort)((*(ushort *)(DAT_140072450 + 0xc) & 0xf0) << 8)) {
    bVar5 = 0;
    iVar4 = ((*(ushort *)(DAT_140072450 + 0xc) & 0xff) >> 2 & 0xfffffffc) - 0x14;
    if (0 < iVar4) {
      do {
        uVar2 = (ulonglong)bVar5;
        cVar1 = *(char *)(uVar2 + 0x14 + DAT_140072450);
        if (cVar1 == '\0') {
          return;
        }
        if (cVar1 == '\x01') {
          cVar1 = '\x01';
        }
        else {
          if ((cVar1 == '\x02') && (*(char *)(uVar2 + 0x15 + DAT_140072450) == '\x04')) {
            uVar3 = CONCAT11(*(undefined1 *)(uVar2 + 0x16 + DAT_140072450),
                             *(undefined1 *)(uVar2 + 0x17 + DAT_140072450));
            if (0x5b4 < uVar3) {
              uVar3 = 0x5b4;
            }
            *(ushort *)(param_1 + 0x40) = uVar3;
            return;
          }
          cVar1 = *(char *)(uVar2 + 0x15 + DAT_140072450);
          if (cVar1 == '\0') {
            return;
          }
        }
        bVar5 = bVar5 + cVar1;
      } while ((int)(uint)bVar5 < iVar4);
    }
  }
  return;
}



===== tcp_pcb_purge @ 140011ea0 =====

void tcp_pcb_purge(longlong param_1)

{
  if ((1 < *(uint *)(param_1 + 0x18)) && (*(uint *)(param_1 + 0x18) != 10)) {
    tcp_segs_free(*(undefined8 **)(param_1 + 0x90));
    *(undefined8 *)(param_1 + 0x90) = 0;
    tcp_segs_free(*(undefined8 **)(param_1 + 0x80));
    tcp_segs_free(*(undefined8 **)(param_1 + 0x88));
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x88) = 0;
  }
  return;
}



===== tcp_pcb_remove @ 140011ef8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tcp_pcb_remove(longlong *param_1,uint *param_2)

{
  uint *puVar1;
  undefined8 uVar2;
  
  puVar1 = (uint *)*param_1;
  if (puVar1 == param_2) {
    *param_1 = *(longlong *)(puVar1 + 4);
  }
  else {
    _tcp_tmp_pcb = puVar1;
    while (_tcp_tmp_pcb != (uint *)0x0) {
      puVar1 = *(uint **)(_tcp_tmp_pcb + 4);
      if ((puVar1 != (uint *)0x0) && (puVar1 == param_2)) {
        *(undefined8 *)(_tcp_tmp_pcb + 4) = *(undefined8 *)(param_2 + 4);
        break;
      }
      _tcp_tmp_pcb = puVar1;
    }
  }
  param_2[4] = 0;
  param_2[5] = 0;
  tcp_pcb_purge((longlong)param_2);
  if (((param_2[6] != 10) && (param_2[6] != 1)) && (((byte)param_2[0xb] & 1) != 0)) {
    *(byte *)(param_2 + 0xb) = (byte)param_2[0xb] | 2;
    crashdump_tcp4_output(param_2);
  }
  param_2[6] = 0;
  uVar2 = tcp_pcbs_sane();
  if ((short)uVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("tcp_pcb_remove: tcp_pcbs_sane()");
  }
  return;
}



===== tcp_pcbs_sane @ 140011f9c =====

undefined8 tcp_pcbs_sane(void)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = tcp_active_pcbs;
  while( true ) {
    if (lVar2 == 0) {
      lVar2 = tcp_tw_pcbs;
      while( true ) {
        if (lVar2 == 0) {
          return 1;
        }
        if (*(int *)(lVar2 + 0x18) != 10) break;
        lVar2 = *(longlong *)(lVar2 + 0x10);
      }
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_pcbs_sane: tw pcb->state == TIME-WAIT");
    }
    iVar1 = *(int *)(lVar2 + 0x18);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_pcbs_sane: active pcb->state != CLOSED");
    }
    if (iVar1 == 1) break;
    if (iVar1 == 10) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_pcbs_sane: active pcb->state != TIME-WAIT");
    }
    lVar2 = *(longlong *)(lVar2 + 0x10);
  }
                    /* WARNING: Subroutine does not return */
  DbgPrint("tcp_pcbs_sane: active pcb->state != LISTEN");
}



===== tcp_process @ 140012030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong tcp_process(uint *param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  uint *in_RAX;
  ulonglong uVar9;
  uint7 extraout_var;
  uint7 extraout_var_00;
  uint7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 extraout_var_03;
  undefined8 uVar10;
  uint *puVar11;
  
  uVar4 = _tcp_ticks;
  bVar1 = DAT_140072423;
  if ((DAT_140072423 & 4) == 0) {
    in_RAX = (uint *)(ulonglong)_tcp_ticks;
    param_1[0xe] = _tcp_ticks;
    *(undefined1 *)(param_1 + 0x33) = 0;
    uVar7 = DAT_140072460;
    iVar6 = DAT_140072424;
    uVar3 = param_1[6];
    if (uVar3 == 2) {
      in_RAX = (uint *)((ulonglong)CONCAT31((int3)(uVar4 >> 8),bVar1) & 0xffffffffffffff12);
      if ((char)in_RAX == '\x12') {
        puVar5 = *(undefined8 **)(param_1 + 0x22);
        uVar4 = *(uint *)(puVar5[4] + 4);
        in_RAX = (uint *)0x0;
        if (DAT_140072460 ==
            ((uVar4 << 0x10 | uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 |
            (uint)*(byte *)(puVar5[4] + 7)) + 1) {
          *(short *)((longlong)param_1 + 0x7a) = *(short *)((longlong)param_1 + 0x7a) + 1;
          param_1[0x15] = uVar7;
          param_1[0xc] = iVar6 + 1;
          uVar2 = DAT_140072450[7];
          *(char *)(param_1 + 0x1f) = (char)param_1[0x1f] + -1;
          param_1[0x1b] = iVar6 - 1;
          *(short *)((longlong)param_1 + 0x5a) = (short)param_1[0x10];
          param_1[0x1a] = (uint)uVar2;
          param_1[6] = 4;
          *(undefined8 *)(param_1 + 0x22) = *puVar5;
          crashdump_ip6_tcp_seg_free((longlong)puVar5);
          tcp_parseopt((longlong)param_1);
          uVar10 = 0;
          if (*(code **)(param_1 + 0x2a) != (code *)0x0) {
            uVar10 = (**(code **)(param_1 + 0x2a))(*(undefined8 *)(param_1 + 8),param_1,0);
          }
          bVar1 = (byte)param_1[0xb];
          if ((bVar1 & 1) == 0) {
            in_RAX = (uint *)CONCAT71((int7)((ulonglong)uVar10 >> 8),bVar1);
            *(byte *)(param_1 + 0xb) = bVar1 | 1;
          }
          else {
            *(byte *)(param_1 + 0xb) = bVar1 & 0xfe | 2;
            in_RAX = (uint *)crashdump_tcp4_output(param_1);
          }
          goto LAB_1400124f1;
        }
      }
      if ((bVar1 & 0x10) != 0) {
LAB_1400124b6:
        in_RAX = (uint *)tcp_rst(DAT_140072460,(uint)DAT_140072464 + DAT_140072424,
                                 (uint *)(DAT_140072458 + 0x10),(uint *)(DAT_140072458 + 0xc),
                                 DAT_140072450[1],*DAT_140072450);
      }
    }
    else if (uVar3 == 3) {
      if ((bVar1 & 0x14) == 0x10) {
        if (((int)(DAT_140072460 - param_1[0x15]) < 1) || (0 < (int)(DAT_140072460 - param_1[0x18]))
           ) goto LAB_1400124b6;
        param_1[6] = 4;
        if (*(code **)(param_1 + 0x2c) == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("pcb->accept != NULL");
        }
        cVar8 = (**(code **)(param_1 + 0x2c))(*(undefined8 *)(param_1 + 8),param_1,0);
        if (cVar8 != '\0') {
          uVar10 = tcp_abort(param_1);
          return CONCAT71((int7)((ulonglong)uVar10 >> 8),0xfd);
        }
        tcp_receive(param_1);
        in_RAX = (uint *)(ulonglong)(ushort)param_1[0x10];
        *(ushort *)((longlong)param_1 + 0x5a) = (ushort)param_1[0x10];
      }
    }
    else if (uVar3 == 4) {
LAB_1400122f4:
      cVar8 = tcp_receive(param_1);
      in_RAX = (uint *)CONCAT71(extraout_var_03,cVar8);
      if (((DAT_140072423 & 1) != 0) && (cVar8 != '\0')) {
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
        in_RAX = (uint *)crashdump_tcp4_output(param_1);
        param_1[6] = 7;
      }
    }
    else if (uVar3 == 5) {
      tcp_receive(param_1);
      in_RAX = (uint *)CONCAT71(extraout_var_02,DAT_140072423);
      if ((DAT_140072423 & 1) == 0) {
        if (((DAT_140072423 & 0x10) != 0) &&
           (in_RAX = (uint *)(ulonglong)param_1[0x18], DAT_140072460 == param_1[0x18])) {
          param_1[6] = 6;
        }
      }
      else {
        if (((DAT_140072423 & 0x10) != 0) && (DAT_140072460 == param_1[0x18])) {
          *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
          crashdump_tcp4_output(param_1);
          tcp_pcb_purge((longlong)param_1);
          puVar11 = tcp_active_pcbs;
          if (tcp_active_pcbs == param_1) goto LAB_1400121e0;
          while (_tcp_tmp_pcb = puVar11, puVar11 != (uint *)0x0) {
            puVar11 = *(uint **)(puVar11 + 4);
            if ((puVar11 != (uint *)0x0) && (puVar11 == param_1)) goto LAB_140012216;
          }
          goto LAB_14001221e;
        }
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
        in_RAX = (uint *)crashdump_tcp4_output(param_1);
        param_1[6] = 8;
      }
    }
    else if (uVar3 == 6) {
      tcp_receive(param_1);
      in_RAX = (uint *)((ulonglong)extraout_var_01 << 8);
      if ((DAT_140072423 & 1) != 0) {
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
        crashdump_tcp4_output(param_1);
        tcp_pcb_purge((longlong)param_1);
        puVar11 = tcp_active_pcbs;
        if (tcp_active_pcbs == param_1) {
LAB_1400121e0:
          tcp_active_pcbs = *(uint **)(tcp_active_pcbs + 4);
        }
        else {
          while (_tcp_tmp_pcb = puVar11, puVar11 != (uint *)0x0) {
            puVar11 = *(uint **)(puVar11 + 4);
            if ((puVar11 != (uint *)0x0) && (puVar11 == param_1)) goto LAB_140012216;
          }
        }
LAB_14001221e:
        param_1[4] = 0;
        param_1[5] = 0;
        param_1[6] = 10;
        *(uint **)(param_1 + 4) = tcp_tw_pcbs;
        in_RAX = tcp_tw_pcbs;
        tcp_tw_pcbs = param_1;
      }
    }
    else {
      if (uVar3 == 7) goto LAB_1400122f4;
      if (uVar3 == 8) {
        tcp_receive(param_1);
        in_RAX = (uint *)((ulonglong)extraout_var_00 << 8);
        if (((DAT_140072423 & 0x10) != 0) &&
           (in_RAX = (uint *)(ulonglong)param_1[0x18], DAT_140072460 == param_1[0x18])) {
          *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
          crashdump_tcp4_output(param_1);
          tcp_pcb_purge((longlong)param_1);
          puVar11 = tcp_active_pcbs;
          if (tcp_active_pcbs == param_1) goto LAB_1400121e0;
          while (_tcp_tmp_pcb = puVar11, puVar11 != (uint *)0x0) {
            puVar11 = *(uint **)(puVar11 + 4);
            if ((puVar11 != (uint *)0x0) && (puVar11 == param_1)) goto LAB_140012216;
          }
          goto LAB_14001221e;
        }
      }
      else if (uVar3 == 9) {
        tcp_receive(param_1);
        in_RAX = (uint *)((ulonglong)extraout_var << 8);
        if (((DAT_140072423 & 0x10) != 0) &&
           (in_RAX = (uint *)(ulonglong)param_1[0x18], DAT_140072460 == param_1[0x18])) {
          param_1[6] = 0;
          DAT_140072466 = 0x10;
        }
      }
    }
LAB_1400124f1:
    uVar9 = (ulonglong)in_RAX & 0xffffffffffffff00;
  }
  else {
    if (param_1[6] == 2) {
      in_RAX = (uint *)(ulonglong)param_1[0x18];
      if (DAT_140072460 != param_1[0x18]) goto LAB_1400124f1;
    }
    else {
      if (((int)(DAT_140072424 - param_1[0xc]) < 0) ||
         (in_RAX = (uint *)(ulonglong)(ushort)param_1[0xd],
         0 < (int)((DAT_140072424 - (uint)(ushort)param_1[0xd]) - param_1[0xc])))
      goto LAB_1400124f1;
      if (param_1[6] == 0) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("tcp_input: pcb->state != CLOSED");
      }
    }
    *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] & 0xfe;
    uVar9 = CONCAT71((int7)((ulonglong)in_RAX >> 8),0xfc);
    DAT_140072466 = 8;
  }
  return uVar9;
LAB_140012216:
  *(undefined8 *)(_tcp_tmp_pcb + 4) = *(undefined8 *)(param_1 + 4);
  goto LAB_14001221e;
}



===== tcp_receive @ 140012500 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 tcp_receive(uint *param_1)

{
  byte bVar1;
  longlong lVar2;
  char cVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  ushort uVar6;
  ushort uVar7;
  uint uVar8;
  short sVar9;
  uint uVar10;
  undefined1 uVar11;
  longlong *plVar12;
  int iVar13;
  longlong *plVar14;
  short sVar15;
  uint uVar16;
  short sVar17;
  uint uVar18;
  
  uVar16 = DAT_140072460;
  uVar18 = DAT_140072424;
  uVar11 = 0;
  if ((DAT_140072423 & 0x10) != 0) {
    uVar10 = param_1[0x1b];
    uVar8 = param_1[0x1a];
    iVar13 = uVar8 + uVar10;
    if ((((int)(uVar10 - DAT_140072424) < 0) ||
        ((uVar10 == DAT_140072424 && ((int)(param_1[0x1c] - DAT_140072460) < 0)))) ||
       ((param_1[0x1c] == DAT_140072460 && (uVar8 < *(ushort *)(DAT_140072450 + 0xe))))) {
      uVar8 = (uint)*(ushort *)(DAT_140072450 + 0xe);
      param_1[0x1a] = uVar8;
      param_1[0x1b] = uVar18;
      param_1[0x1c] = uVar16;
      uVar10 = uVar18;
    }
    if (param_1[0x15] == uVar16) {
      *(undefined2 *)(param_1 + 0x1e) = 0;
      if (((uVar10 + uVar8 == iVar13) &&
          (*(char *)(param_1 + 0x16) = (char)param_1[0x16] + '\x01', 2 < (byte)param_1[0x16])) &&
         (*(longlong *)(param_1 + 0x22) != 0)) {
        if ((param_1[0xb] & 4) == 0) {
          tcp_rexmit(param_1);
          if (param_1[0x1a] < (uint)*(ushort *)((longlong)param_1 + 0x5a)) {
            uVar7 = (ushort)(param_1[0x1a] >> 1);
          }
          else {
            uVar7 = *(ushort *)((longlong)param_1 + 0x5a) >> 1;
          }
          *(ushort *)(param_1 + 0x17) = uVar7;
          uVar16 = DAT_140072460;
          uVar18 = DAT_140072424;
          *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 4;
          *(ushort *)((longlong)param_1 + 0x5a) = (short)param_1[0x10] * 3 + uVar7;
        }
        else {
          uVar7 = (short)param_1[0x10] + *(ushort *)((longlong)param_1 + 0x5a);
          if (*(ushort *)((longlong)param_1 + 0x5a) < uVar7) {
            *(ushort *)((longlong)param_1 + 0x5a) = uVar7;
          }
        }
      }
    }
    else if ((0 < (int)(uVar16 - param_1[0x15])) && ((int)(uVar16 - param_1[0x19]) < 1)) {
      if (((byte)param_1[0xb] & 4) != 0) {
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] & 0xfb;
        *(short *)((longlong)param_1 + 0x5a) = (short)param_1[0x17];
      }
      *(short *)(param_1 + 0x14) =
           ((short)param_1[0x13] >> 3) + *(short *)((longlong)param_1 + 0x4e);
      sVar9 = (short)uVar16 - (short)param_1[0x15];
      *(short *)((longlong)param_1 + 0x7a) = *(short *)((longlong)param_1 + 0x7a) + sVar9;
      *(undefined1 *)((longlong)param_1 + 0x52) = 0;
      *(short *)(param_1 + 0x1e) = sVar9;
      *(undefined1 *)(param_1 + 0x16) = 0;
      param_1[0x15] = uVar16;
      if (3 < (int)param_1[6]) {
        uVar7 = *(ushort *)((longlong)param_1 + 0x5a);
        uVar6 = (ushort)param_1[0x10];
        if ((ushort)param_1[0x17] <= uVar7) {
          uVar6 = (ushort)((int)((uint)uVar6 * (uint)uVar6) / (int)(uint)uVar7);
        }
        if (uVar7 < (ushort)(uVar6 + uVar7)) {
          *(ushort *)((longlong)param_1 + 0x5a) = uVar6 + uVar7;
        }
      }
      puVar4 = *(undefined8 **)(param_1 + 0x22);
      if (puVar4 != (undefined8 *)0x0) {
        do {
          uVar7 = *(ushort *)(puVar4[4] + 0xc) >> 8;
          if (((uVar7 & 1) != 0) || (iVar13 = 0, (uVar7 & 2) != 0)) {
            iVar13 = 1;
          }
          uVar18 = *(uint *)(puVar4[4] + 4);
          if (0 < (int)(((((uVar18 << 0x10 | uVar18 & 0xff00) << 8 |
                          (uVar18 & 0xff0000 | uVar18 >> 0x10) >> 8) + (uint)*(ushort *)(puVar4 + 3)
                         ) - uVar16) + iVar13)) break;
          *(undefined8 *)(param_1 + 0x22) = *puVar4;
          cVar3 = pbuf_clen((undefined8 *)puVar4[1]);
          *(char *)(param_1 + 0x1f) = (char)param_1[0x1f] - cVar3;
          crashdump_ip6_tcp_seg_free((longlong)puVar4);
          if ((((char)param_1[0x1f] != '\0') && (*(longlong *)(param_1 + 0x22) == 0)) &&
             (*(longlong *)(param_1 + 0x20) == 0)) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_receive: valid queue length");
          }
          puVar4 = *(undefined8 **)(param_1 + 0x22);
          uVar16 = DAT_140072460;
        } while (puVar4 != (undefined8 *)0x0);
        uVar18 = DAT_140072424;
      }
      *(undefined1 *)(param_1 + 0xf) = 0;
    }
    puVar4 = *(undefined8 **)(param_1 + 0x20);
    if (puVar4 != (undefined8 *)0x0) {
      do {
        uVar7 = *(ushort *)(puVar4[4] + 0xc) >> 8;
        if (((uVar7 & 1) != 0) || (iVar13 = 0, (uVar7 & 2) != 0)) {
          iVar13 = 1;
        }
        uVar18 = *(uint *)(puVar4[4] + 4);
        if (((int)(((uVar16 - ((uVar18 & 0xff0000 | uVar18 >> 0x10) >> 8 |
                              (uVar18 << 0x10 | uVar18 & 0xff00) << 8)) -
                   (uint)*(ushort *)(puVar4 + 3)) - iVar13) < 0) ||
           (0 < (int)(uVar16 - param_1[0x19]))) goto LAB_14001288b;
        *(undefined8 *)(param_1 + 0x20) = *puVar4;
        cVar3 = pbuf_clen((undefined8 *)puVar4[1]);
        *(char *)(param_1 + 0x1f) = (char)param_1[0x1f] - cVar3;
        crashdump_ip6_tcp_seg_free((longlong)puVar4);
        if (((char)param_1[0x1f] == '\0') || (*(longlong *)(param_1 + 0x22) != 0)) {
          puVar4 = *(undefined8 **)(param_1 + 0x20);
          if (puVar4 == (undefined8 *)0x0) goto LAB_140012884;
        }
        else {
          puVar4 = *(undefined8 **)(param_1 + 0x20);
          if (puVar4 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_receive: valid queue length");
          }
        }
        uVar18 = *(uint *)(puVar4[4] + 4);
        param_1[0x18] =
             (uVar18 << 0x10 | uVar18 & 0xff00) << 8 | uVar18 >> 8 & 0xff00 |
             (uint)*(byte *)(puVar4[4] + 7);
        if (puVar4 == (undefined8 *)0x0) goto LAB_140012884;
        uVar16 = DAT_140072460;
      } while( true );
    }
    goto LAB_140012892;
  }
  goto LAB_1400128fc;
LAB_140012884:
  uVar16 = DAT_140072460;
LAB_14001288b:
  uVar18 = DAT_140072424;
LAB_140012892:
  if ((param_1[0x11] != 0) && ((int)(param_1[0x12] - uVar16) < 0)) {
    sVar15 = (tcp_ticks - ((short)param_1[0x13] >> 3)) - (short)param_1[0x11];
    sVar17 = (short)param_1[0x13] + sVar15;
    param_1[0x11] = 0;
    *(short *)(param_1 + 0x13) = sVar17;
    sVar9 = -sVar15;
    if (-1 < sVar15) {
      sVar9 = sVar15;
    }
    sVar9 = (sVar9 - (*(short *)((longlong)param_1 + 0x4e) >> 2)) +
            *(short *)((longlong)param_1 + 0x4e);
    *(short *)((longlong)param_1 + 0x4e) = sVar9;
    *(short *)(param_1 + 0x14) = (sVar17 >> 3) + sVar9;
  }
LAB_1400128fc:
  uVar16 = param_1[0xc];
  if (DAT_140072464 == 0) {
    if (-1 < (int)(uVar18 - uVar16)) {
      iVar13 = (uVar18 - (ushort)param_1[0xd]) - uVar16;
      goto LAB_140012e10;
    }
  }
  else {
    iVar13 = uVar16 - uVar18;
    if ((iVar13 < 1) || (-1 < (int)((uVar16 - DAT_140072464) - uVar18))) {
      if ((int)(uVar18 - uVar16) < 0) {
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
        crashdump_tcp4_output(param_1);
        uVar18 = DAT_140072424;
      }
    }
    else {
      if (DAT_140072430 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("inseg.p != NULL");
      }
      plVar12 = DAT_140072430;
      if ((int)(uint)*(ushort *)((longlong)DAT_140072430 + 0x12) < iVar13) {
        lVar2 = DAT_140072430[2];
        uVar7 = *(ushort *)((longlong)DAT_140072430 + 0x12);
        sVar9 = (short)iVar13;
        if ((int)(uint)uVar7 < iVar13) {
          do {
            *(short *)(plVar12 + 2) = (short)lVar2 - sVar9;
            iVar13 = iVar13 - (uint)uVar7;
            *(undefined2 *)((longlong)plVar12 + 0x12) = 0;
            plVar12 = (longlong *)*plVar12;
            uVar7 = *(ushort *)((longlong)plVar12 + 0x12);
          } while ((int)(uint)uVar7 < iVar13);
        }
      }
      pbuf_header((longlong)plVar12,-(short)iVar13);
      _DAT_140072438 = plVar12[1];
      DAT_140072440 = DAT_140072440 + ((short)DAT_140072424 - (short)param_1[0xc]);
      uVar18 = param_1[0xc];
      DAT_140072424 = uVar18;
      *(uint *)(DAT_140072448 + 4) = uVar18;
    }
    uVar16 = param_1[0xc];
    if (-1 < (int)(uVar18 - uVar16)) {
      uVar7 = (ushort)param_1[0xd];
      iVar13 = (uVar18 - uVar7) - uVar16;
      if (iVar13 < 0) {
        if (uVar16 != uVar18) {
          *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
          crashdump_tcp4_output(param_1);
          if (*(longlong **)(param_1 + 0x24) == (longlong *)0x0) {
            puVar4 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140072428);
LAB_140012c47:
            *(undefined8 **)(param_1 + 0x24) = puVar4;
            return 0;
          }
          plVar12 = (longlong *)0x0;
          plVar14 = *(longlong **)(param_1 + 0x24);
          do {
            uVar18 = *(uint *)(plVar14[4] + 4);
            if (DAT_140072424 == uVar18) {
              if (DAT_140072440 <= *(ushort *)(plVar14 + 3)) {
                return 0;
              }
              plVar5 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140072428);
              if (plVar5 == (longlong *)0x0) {
                return 0;
              }
              *plVar5 = *plVar14;
              if (plVar12 == (longlong *)0x0) {
                *(longlong **)(param_1 + 0x24) = plVar5;
                return 0;
              }
              *plVar12 = (longlong)plVar5;
              return 0;
            }
            if (plVar12 == (longlong *)0x0) {
              if ((int)(DAT_140072424 - uVar18) < 0) {
                if (0 < (int)((DAT_140072440 - uVar18) + DAT_140072424)) {
                  DAT_140072440 = (short)uVar18 - (short)DAT_140072424;
                  pbuf_realloc(DAT_140072430,DAT_140072440);
                }
                puVar4 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140072428);
                if (puVar4 == (undefined8 *)0x0) {
                  return 0;
                }
                *puVar4 = plVar14;
                goto LAB_140012c47;
              }
            }
            else if ((0 < (int)(DAT_140072424 - *(int *)(plVar12[4] + 4))) &&
                    ((int)((DAT_140072424 - uVar18) + 1) < 1)) {
              if (0 < (int)((DAT_140072440 - uVar18) + DAT_140072424)) {
                DAT_140072440 = (short)uVar18 - (short)DAT_140072424;
                pbuf_realloc(DAT_140072430,DAT_140072440);
              }
              puVar4 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140072428);
              uVar18 = DAT_140072424;
              if (puVar4 == (undefined8 *)0x0) {
                return 0;
              }
              *puVar4 = plVar14;
              *plVar12 = (longlong)puVar4;
              if ((int)((*(ushort *)(plVar12 + 3) - uVar18) + *(int *)(plVar12[4] + 4)) < 1) {
                return 0;
              }
              uVar7 = (short)uVar18 - *(short *)(plVar12[4] + 4);
              *(ushort *)(plVar12 + 3) = uVar7;
              puVar4 = (undefined8 *)plVar12[1];
              goto LAB_140012d71;
            }
            plVar5 = (longlong *)*plVar14;
            if ((plVar5 == (longlong *)0x0) && (0 < (int)(DAT_140072424 - uVar18))) {
              puVar4 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140072428);
              *plVar14 = (longlong)puVar4;
              if (puVar4 == (undefined8 *)0x0) {
                return 0;
              }
              if ((int)((*(ushort *)(plVar14 + 3) - DAT_140072424) + *(int *)(plVar14[4] + 4)) < 1)
              {
                return 0;
              }
              uVar7 = (short)DAT_140072424 - *(short *)(plVar14[4] + 4);
              *(ushort *)(plVar14 + 3) = uVar7;
              puVar4 = (undefined8 *)plVar14[1];
LAB_140012d71:
              pbuf_realloc(puVar4,uVar7);
              return 0;
            }
            plVar12 = plVar14;
            plVar14 = plVar5;
            if (plVar5 == (longlong *)0x0) {
              return 0;
            }
          } while( true );
        }
        uVar11 = 1;
        if ((*(longlong *)(param_1 + 0x24) != 0) &&
           (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x24) + 0x20),
           (int)((*(int *)(lVar2 + 4) - (uint)DAT_140072440) - uVar18) < 1)) {
          DAT_140072440 = *(short *)(lVar2 + 4) - (short)uVar18;
          pbuf_realloc(DAT_140072430,DAT_140072440);
          uVar7 = (ushort)param_1[0xd];
        }
        uVar6 = *(ushort *)(DAT_140072448 + 0xc) >> 8;
        if (((uVar6 & 1) == 0) && ((uVar6 & 2) == 0)) {
          sVar9 = 0;
        }
        else {
          sVar9 = 1;
        }
        uVar6 = sVar9 + DAT_140072440;
        DAT_140072464 = uVar6;
        if (param_1[6] != 7) {
          param_1[0xc] = param_1[0xc] + (uint)uVar6;
        }
        if (uVar7 < uVar6) {
          sVar9 = 0;
        }
        else {
          sVar9 = uVar7 - uVar6;
        }
        *(short *)(param_1 + 0xd) = sVar9;
        if ((short)DAT_140072430[2] != 0) {
          DAT_140072468 = DAT_140072430;
          DAT_140072430 = (longlong *)0x0;
        }
        puVar4 = *(undefined8 **)(param_1 + 0x24);
        if ((*(ushort *)(DAT_140072448 + 0xc) >> 8 & 1) != 0) {
          DAT_140072466 = 0x20;
        }
        if (puVar4 != (undefined8 *)0x0) {
          do {
            plVar12 = DAT_140072468;
            uVar18 = *(uint *)(puVar4[4] + 4);
            if (uVar18 != param_1[0xc]) break;
            uVar7 = *(ushort *)(puVar4[4] + 0xc) >> 8;
            if (((uVar7 & 1) != 0) || (iVar13 = 0, (uVar7 & 2) != 0)) {
              iVar13 = 1;
            }
            DAT_140072424 = uVar18;
            param_1[0xc] = (uint)*(ushort *)(puVar4 + 3) + iVar13 + param_1[0xc];
            uVar7 = *(ushort *)(puVar4[4] + 0xc) >> 8;
            if (((uVar7 & 1) == 0) && ((uVar7 & 2) == 0)) {
              iVar13 = 0;
              uVar6 = 0;
            }
            else {
              uVar6 = uVar7 & 2;
              iVar13 = 1;
            }
            if ((uint)(ushort)param_1[0xd] < iVar13 + (uint)*(ushort *)(puVar4 + 3)) {
              sVar9 = 0;
            }
            else {
              if (((uVar7 & 1) == 0) && (uVar6 == 0)) {
                sVar9 = 0;
              }
              else {
                sVar9 = 1;
              }
              sVar9 = ((ushort)param_1[0xd] - sVar9) - *(ushort *)(puVar4 + 3);
            }
            *(short *)(param_1 + 0xd) = sVar9;
            plVar14 = (longlong *)puVar4[1];
            if ((short)plVar14[2] != 0) {
              if (plVar12 == (longlong *)0x0) {
                DAT_140072468 = plVar14;
              }
              else {
                pbuf_cat(plVar12,(longlong)plVar14);
              }
              puVar4[1] = 0;
            }
            if (((*(ushort *)(puVar4[4] + 0xc) >> 8 & 1) != 0) &&
               (DAT_140072466 = 0x20, param_1[6] == 4)) {
              param_1[6] = 7;
            }
            *(undefined8 *)(param_1 + 0x24) = *puVar4;
            crashdump_ip6_tcp_seg_free((longlong)puVar4);
            puVar4 = *(undefined8 **)(param_1 + 0x24);
          } while (puVar4 != (undefined8 *)0x0);
        }
        bVar1 = (byte)param_1[0xb];
        if ((bVar1 & 1) == 0) {
          *(byte *)(param_1 + 0xb) = bVar1 | 1;
          return 1;
        }
        *(byte *)(param_1 + 0xb) = bVar1 & 0xfe | 2;
        goto LAB_140012e16;
      }
LAB_140012e10:
      if (iVar13 + 1 < 1) {
        return 0;
      }
    }
  }
  *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
LAB_140012e16:
  crashdump_tcp4_output(param_1);
  return uVar11;
}



===== tcp_recv_null @ 140012e40 =====

char tcp_recv_null(undefined8 param_1,uint *param_2,undefined8 *param_3,char param_4)

{
  char cVar1;
  
  if (param_3 == (undefined8 *)0x0) {
    if (param_4 == '\0') {
      cVar1 = crashdump_tcp4_close(param_2);
      return cVar1;
    }
  }
  else {
    pbuf_free(param_3);
  }
  return '\0';
}



===== tcp_rexmit @ 140012e6c =====

void tcp_rexmit(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  puVar3 = *(undefined8 **)(param_1 + 0x22);
  if (puVar3 != (undefined8 *)0x0) {
    uVar4 = *puVar3;
    *puVar3 = *(undefined8 *)(param_1 + 0x20);
    lVar5 = *(longlong *)(param_1 + 0x22);
    *(longlong *)(param_1 + 0x20) = lVar5;
    *(undefined8 *)(param_1 + 0x22) = uVar4;
    lVar5 = *(longlong *)(lVar5 + 0x20);
    uVar2 = *(uint *)(lVar5 + 4);
    bVar1 = *(byte *)(lVar5 + 7);
    *(char *)((longlong)param_1 + 0x52) = *(char *)((longlong)param_1 + 0x52) + '\x01';
    param_1[0x11] = 0;
    param_1[0x18] = (uVar2 << 0x10 | uVar2 & 0xff00) << 8 | (uint)bVar1 | uVar2 >> 8 & 0xff00;
    crashdump_tcp4_output(param_1);
  }
  return;
}



===== tcp_rexmit_rto @ 140012eec =====

void tcp_rexmit_rto(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  
  puVar3 = *(undefined8 **)(param_1 + 0x22);
  if (puVar3 != (undefined8 *)0x0) {
    for (puVar5 = (undefined8 *)*puVar3; puVar5 != (undefined8 *)0x0; puVar5 = (undefined8 *)*puVar5
        ) {
      puVar3 = puVar5;
    }
    *puVar3 = *(undefined8 *)(param_1 + 0x20);
    lVar4 = *(longlong *)(param_1 + 0x22);
    param_1[0x22] = 0;
    param_1[0x23] = 0;
    *(longlong *)(param_1 + 0x20) = lVar4;
    lVar4 = *(longlong *)(lVar4 + 0x20);
    uVar2 = *(uint *)(lVar4 + 4);
    bVar1 = *(byte *)(lVar4 + 7);
    *(char *)((longlong)param_1 + 0x52) = *(char *)((longlong)param_1 + 0x52) + '\x01';
    param_1[0x11] = 0;
    param_1[0x18] = (uVar2 << 0x10 | uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | (uint)bVar1;
    crashdump_tcp4_output(param_1);
  }
  return;
}



===== tcp_rst @ 140012f80 =====

void tcp_rst(uint param_1,uint param_2,uint *param_3,uint *param_4,ushort param_5,ushort param_6)

{
  ushort *puVar1;
  undefined4 uVar2;
  longlong *plVar3;
  
  plVar3 = pbuf_alloc(1,0x14,0);
  if (plVar3 != (longlong *)0x0) {
    puVar1 = (ushort *)plVar3[1];
    puVar1[1] = param_6 << 8 | param_6 >> 8;
    *puVar1 = param_5 << 8 | param_5 >> 8;
    puVar1[7] = 0xffff;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[6] = 0x1450;
    *(uint *)(puVar1 + 2) =
         param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
    *(uint *)(puVar1 + 4) =
         param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 | param_2 << 0x18;
    uVar2 = inet_chksum_pseudo(plVar3,param_3,param_4,6,*(ushort *)(plVar3 + 2));
    puVar1[8] = (ushort)uVar2;
    crashdump_ip4_output((longlong)plVar3,(int *)param_3,param_4,0x40,0,6);
    pbuf_free(plVar3);
  }
  return;
}



===== crashdump_ip6_tcp_seg_copy @ 14001309c =====

undefined8 * crashdump_ip6_tcp_seg_copy(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = memp_malloc(5);
  if (puVar2 != (undefined8 *)0x0) {
    uVar1 = param_1[1];
    *puVar2 = *param_1;
    puVar2[1] = uVar1;
    uVar1 = param_1[3];
    puVar2[2] = param_1[2];
    puVar2[3] = uVar1;
    puVar2[4] = param_1[4];
    pbuf_ref(puVar2[1]);
  }
  return puVar2;
}



===== crashdump_ip6_tcp_seg_free @ 1400130ec =====

char crashdump_ip6_tcp_seg_free(longlong param_1)

{
  char cVar1;
  
  cVar1 = '\0';
  if (param_1 != 0) {
    if (*(undefined8 **)(param_1 + 8) != (undefined8 *)0x0) {
      cVar1 = pbuf_free(*(undefined8 **)(param_1 + 8));
    }
    memp_free(5,param_1);
  }
  return cVar1;
}



===== tcp_segs_free @ 14001312c =====

char tcp_segs_free(undefined8 *param_1)

{
  undefined8 *puVar1;
  char cVar2;
  char cVar3;
  
  cVar3 = '\0';
  while (param_1 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*param_1;
    cVar2 = crashdump_ip6_tcp_seg_free((longlong)param_1);
    cVar3 = cVar3 + cVar2;
    param_1 = puVar1;
  }
  return cVar3;
}



===== tcp_slowtmr @ 140013160 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tcp_slowtmr(void)

{
  uint *puVar1;
  longlong lVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  ushort uVar6;
  char cVar7;
  uint *puVar8;
  longlong lVar9;
  uint *puVar10;
  longlong lVar11;
  
  _tcp_ticks = _tcp_ticks + 1;
  cVar3 = '\0';
  puVar8 = (uint *)0x0;
  puVar10 = tcp_active_pcbs;
  do {
    if (puVar10 == (uint *)0x0) {
      lVar9 = 0;
      lVar11 = tcp_tw_pcbs;
      while( true ) {
        if (lVar11 == 0) {
          return;
        }
        if (*(int *)(lVar11 + 0x18) != 10) break;
        if ((uint)(_tcp_ticks - *(int *)(lVar11 + 0x38)) < 0xf1) {
          lVar9 = lVar11;
          lVar11 = *(longlong *)(lVar11 + 0x10);
        }
        else {
          tcp_pcb_purge(lVar11);
          if (lVar9 == 0) {
            if (tcp_tw_pcbs != lVar11) {
                    /* WARNING: Subroutine does not return */
              DbgPrint("tcp_slowtmr: first pcb == tcp_tw_pcbs");
            }
            tcp_tw_pcbs = *(longlong *)(lVar11 + 0x10);
          }
          else {
            if (lVar11 == tcp_tw_pcbs) {
                    /* WARNING: Subroutine does not return */
              DbgPrint("tcp_slowtmr: middle tcp != tcp_tw_pcbs");
            }
            *(undefined8 *)(lVar9 + 0x10) = *(undefined8 *)(lVar11 + 0x10);
          }
          lVar2 = *(longlong *)(lVar11 + 0x10);
          memp_free(3,lVar11);
          lVar11 = lVar2;
        }
      }
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: TIME-WAIT pcb->state == TIME-WAIT");
    }
    uVar5 = puVar10[6];
    if (uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: active pcb->state != CLOSED\n");
    }
    if (uVar5 == 1) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: active pcb->state != LISTEN\n");
    }
    if (uVar5 == 10) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: active pcb->state != TIME-WAIT\n");
    }
    cVar7 = '\0';
    if ((uVar5 == 2) && (*(char *)((longlong)puVar10 + 0x52) == '\x06')) {
      cVar7 = '\x01';
    }
    else {
      if (*(byte *)((longlong)puVar10 + 0x52) == 0xc) {
        cVar7 = '\x01';
      }
      else {
        uVar6 = *(short *)((longlong)puVar10 + 0x3e) + 1;
        *(ushort *)((longlong)puVar10 + 0x3e) = uVar6;
        if ((*(longlong *)(puVar10 + 0x22) != 0) && ((ushort)puVar10[0x14] <= uVar6)) {
          if (uVar5 != 2) {
            *(short *)(puVar10 + 0x14) =
                 ((short)puVar10[0x13] >> 3) + *(short *)((longlong)puVar10 + 0x4e) <<
                 ((&crashdump_tcp4_backoff)[*(byte *)((longlong)puVar10 + 0x52)] & 0x1f);
          }
          uVar6 = (ushort)puVar10[0x10];
          uVar5 = (uint)*(ushort *)((longlong)puVar10 + 0x5a);
          if (puVar10[0x1a] <= (uint)*(ushort *)((longlong)puVar10 + 0x5a)) {
            uVar5 = puVar10[0x1a];
          }
          uVar4 = (ushort)(uVar5 >> 1);
          *(ushort *)(puVar10 + 0x17) = uVar4;
          if (uVar4 < uVar6) {
            *(ushort *)(puVar10 + 0x17) = uVar6 * 2;
          }
          *(ushort *)((longlong)puVar10 + 0x5a) = uVar6;
          tcp_rexmit_rto(puVar10);
          uVar5 = puVar10[6];
        }
      }
      if ((uVar5 == 6) && (0x28 < _tcp_ticks - puVar10[0xe])) {
        cVar7 = cVar7 + '\x01';
      }
    }
    if (((puVar10[2] & 8) != 0) && ((uVar5 == 4 || (uVar5 == 7)))) {
      if ((puVar10[0x32] + 0xa4cb8) / 500 < _tcp_ticks - puVar10[0xe]) {
        tcp_abort(puVar10);
      }
      else if (((uint)(byte)puVar10[0x33] * 75000 + puVar10[0x32]) / 500 < _tcp_ticks - puVar10[0xe]
              ) {
        tcp_keepalive(puVar10);
        *(char *)(puVar10 + 0x33) = (char)puVar10[0x33] + '\x01';
      }
    }
    if ((*(undefined8 **)(puVar10 + 0x24) != (undefined8 *)0x0) &&
       ((uint)(ushort)puVar10[0x14] * 6 <= _tcp_ticks - puVar10[0xe])) {
      tcp_segs_free(*(undefined8 **)(puVar10 + 0x24));
      puVar10[0x24] = 0;
      puVar10[0x25] = 0;
    }
    if (puVar10[6] == 3) {
      if (0x28 < _tcp_ticks - puVar10[0xe]) {
        cVar7 = cVar7 + '\x01';
        goto LAB_140013347;
      }
    }
    else {
LAB_140013347:
      if ((puVar10[6] == 9) && (0xf0 < _tcp_ticks - puVar10[0xe])) {
        cVar7 = cVar7 + '\x01';
      }
    }
    if (cVar7 == '\0') {
      *(char *)(puVar10 + 0xf) = (char)puVar10[0xf] + '\x01';
      if (*(byte *)((longlong)puVar10 + 0x3d) <= (byte)puVar10[0xf]) {
        *(undefined1 *)(puVar10 + 0xf) = 0;
        if (*(code **)(puVar10 + 0x2e) != (code *)0x0) {
          cVar3 = (**(code **)(puVar10 + 0x2e))(*(undefined8 *)(puVar10 + 8),puVar10);
        }
        if (cVar3 == '\0') {
          crashdump_tcp4_output(puVar10);
        }
      }
      puVar8 = puVar10;
      puVar10 = *(uint **)(puVar10 + 4);
    }
    else {
      tcp_pcb_purge((longlong)puVar10);
      if (puVar8 == (uint *)0x0) {
        if (tcp_active_pcbs != puVar10) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_slowtmr: first pcb == tcp_active_pcbs");
        }
        tcp_active_pcbs = *(uint **)(puVar10 + 4);
      }
      else {
        if (puVar10 == tcp_active_pcbs) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_slowtmr: middle tcp != tcp_active_pcbs");
        }
        *(undefined8 *)(puVar8 + 4) = *(undefined8 *)(puVar10 + 4);
      }
      if (*(code **)(puVar10 + 0x30) != (code *)0x0) {
        (**(code **)(puVar10 + 0x30))(*(undefined8 *)(puVar10 + 8),0xfd);
      }
      puVar1 = *(uint **)(puVar10 + 4);
      memp_free(3,(longlong)puVar10);
      puVar10 = puVar1;
    }
  } while( true );
}



===== tcp_tmr @ 1400134f0 =====

void tcp_tmr(void)

{
  tcp_fasttmr();
  DAT_140072422 = DAT_140072422 + 1;
  if ((DAT_140072422 & 1) != 0) {
    tcp_slowtmr();
  }
  return;
}



===== tcp_write @ 140013518 =====

undefined8 tcp_write(longlong param_1,void *param_2,ushort param_3,char param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(int *)(param_1 + 0x18) - 2;
  if ((uVar1 < 3) || (*(int *)(param_1 + 0x18) == 7)) {
    uVar2 = 0;
    if (param_3 != 0) {
      uVar2 = tcp_enqueue(param_1,param_2,param_3,0,param_4,(void *)0x0,0);
    }
  }
  else {
    uVar2 = CONCAT71((uint7)(uint3)(uVar1 >> 8),0xfa);
  }
  return uVar2;
}



===== update_arp_entry @ 14001355c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong update_arp_entry(longlong param_1,uint *param_2,longlong param_3,byte param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined8 uVar6;
  uint7 extraout_var;
  undefined *puVar7;
  undefined1 *puVar9;
  undefined1 *puVar8;
  byte bVar10;
  longlong lVar11;
  
  if (*(char *)(param_1 + 0x30) == '\0') {
                    /* WARNING: Subroutine does not return */
    DbgPrint("netif->hwaddr_len != 0");
  }
  if ((((param_2 == (uint *)0x0) || (uVar1 = *param_2, uVar1 == 0)) ||
      (in_RAX = ip_addr_isbroadcast(param_2,param_1), (char)in_RAX != '\0')) ||
     (((byte)uVar1 & 0xf0) == 0xe0)) {
    return CONCAT71((int7)(in_RAX >> 8),0xf8);
  }
  uVar3 = find_entry((int *)param_2,param_4);
  if ((char)uVar3 < '\0') {
    return uVar3;
  }
  puVar4 = (undefined *)(longlong)(char)uVar3;
  (&DAT_140074174)[(longlong)puVar4 * 10] = 2;
  (&DAT_140074180)[(longlong)puVar4 * 5] = param_1;
  uVar3 = (ulonglong)*(byte *)(param_1 + 0x30);
  puVar5 = puVar4;
  if (*(byte *)(param_1 + 0x30) != 0) {
    puVar5 = &DAT_14007416c + (longlong)puVar4 * 0x28;
    puVar7 = puVar5 + uVar3;
    lVar11 = param_3 - (longlong)puVar5;
    do {
      puVar7 = puVar7 + -1;
      puVar5 = (undefined *)CONCAT71((int7)((ulonglong)puVar5 >> 8),puVar7[lVar11]);
      *puVar7 = puVar7[lVar11];
      bVar10 = (char)uVar3 - 1;
      uVar3 = (ulonglong)bVar10;
    } while (bVar10 != 0);
  }
  (&DAT_140074178)[(longlong)puVar4 * 0x28] = 0;
  while (puVar2 = (undefined8 *)(&DAT_140074160)[(longlong)puVar4 * 5], puVar2 != (undefined8 *)0x0)
  {
    lVar11 = puVar2[1];
    uVar6 = pbuf_dequeue(puVar2);
    (&DAT_140074160)[(longlong)puVar4 * 5] = uVar6;
    uVar3 = (ulonglong)*(byte *)(param_1 + 0x30);
    if (*(byte *)(param_1 + 0x30) != 0) {
      puVar9 = (undefined1 *)(uVar3 + lVar11);
      do {
        puVar8 = puVar9 + -1;
        *puVar8 = puVar8[param_3 - lVar11];
        puVar9[5] = puVar8[(param_1 - lVar11) + 0x31];
        bVar10 = (char)uVar3 - 1;
        uVar3 = (ulonglong)bVar10;
        puVar9 = puVar8;
      } while (bVar10 != 0);
    }
    *(undefined2 *)(lVar11 + 0xc) = 8;
    lwip_printk();
    (**(code **)(param_1 + 0x20))(param_1,puVar2);
    pbuf_free(puVar2);
    puVar5 = (undefined *)((ulonglong)extraout_var << 8);
  }
  return (ulonglong)puVar5 & 0xffffffffffffff00;
}



===== chksum @ 1400136c4 =====

int chksum(u_short *param_1,ushort param_2)

{
  u_short uVar1;
  int iVar2;
  ulonglong uVar3;
  u_short *puVar4;
  
  iVar2 = 0;
  if (1 < param_2) {
    uVar3 = (ulonglong)(ushort)(((ushort)(param_2 - 2) >> 1) + 1);
    puVar4 = param_1;
    do {
      uVar1 = ntohs(*puVar4);
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + (uint)uVar1;
      param_2 = param_2 - 2;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  if (param_2 == 1) {
    iVar2 = iVar2 + (uint)(byte)*param_1;
  }
  return iVar2;
}



===== crashdump_icmp6_input @ 140013758 =====

void crashdump_icmp6_input(undefined8 *param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined7 extraout_var;
  int local_res8;
  
  pbuf_header((longlong)param_1,-0x28);
  cVar1 = *(char *)param_1[1];
  if (cVar1 == -0x80) {
    bVar3 = icmp_handle_echo_request(param_1,param_2);
    local_res8 = (int)CONCAT71(extraout_var,bVar3);
  }
  else {
    if (cVar1 == -0x7a) goto LAB_140013805;
    if (cVar1 == -0x79) {
      uVar5 = icmp_handle_nd_sol((longlong)param_1,param_2);
      local_res8 = (int)uVar5;
    }
    else {
      if (cVar1 != -0x78) goto LAB_140013805;
      uVar4 = pbuf_header((longlong)param_1,0x28);
      if ((char)uVar4 == '\0') {
        lVar2 = param_1[1];
        uVar4 = pbuf_header((longlong)param_1,0xe);
        if ((char)uVar4 != '\0') goto LAB_140013805;
        if (*(char *)(lVar2 + 0x18) != -1) {
          ethnd_update_entry(param_2,(uint *)(lVar2 + 0x30),(void *)(param_1[1] + 6),0);
        }
        local_res8 = 1;
      }
    }
  }
  if (local_res8 == 0) {
    return;
  }
LAB_140013805:
  pbuf_free(param_1);
  return;
}



===== crashdump_ip6_inet_chksum_pseudo @ 140013820 =====

void crashdump_ip6_inet_chksum_pseudo
               (undefined8 *param_1,longlong param_2,u_short *param_3,byte param_4,int param_5)

{
  u_short uVar1;
  u_short uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  
  iVar4 = 0;
  for (; param_1 != (undefined8 *)0x0; param_1 = (undefined8 *)*param_1) {
    iVar3 = chksum((u_short *)param_1[1],*(ushort *)((longlong)param_1 + 0x12));
    iVar4 = iVar4 + iVar3;
  }
  lVar7 = param_2 - (longlong)param_3;
  lVar6 = 8;
  do {
    uVar1 = ntohs(*(u_short *)(lVar7 + (longlong)param_3));
    uVar2 = ntohs(*param_3);
    param_3 = param_3 + 1;
    iVar4 = iVar4 + (uint)uVar1 + (uint)uVar2;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  uVar5 = iVar4 + (uint)param_4 + param_5;
  iVar4 = (uVar5 >> 0x10) + (uVar5 & 0xffff);
  ntohs(~((short)iVar4 + (short)((uint)iVar4 >> 0x10)));
  return;
}



===== crashdump_ip6_input @ 1400138d0 =====

void crashdump_ip6_input(undefined8 *param_1,longlong param_2)

{
  byte bVar1;
  byte *pbVar2;
  u_short uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  
  pbVar2 = (byte *)param_1[1];
  if ((*pbVar2 & 0xf0) != 0x60) goto LAB_14001396c;
  bVar1 = pbVar2[0x18];
  if (bVar1 != 0xff) {
    plVar5 = DAT_140074300;
    if (DAT_140074300 != (longlong *)0x0) {
      do {
        uVar4 = ip_is_our_addr((longlong)plVar5,(longlong *)(pbVar2 + 0x18));
        if ((int)uVar4 != 0) break;
        plVar5 = (longlong *)*plVar5;
      } while (plVar5 != (longlong *)0x0);
      if (plVar5 != (longlong *)0x0) goto LAB_140013933;
    }
    if (bVar1 != 0xff) goto LAB_14001396c;
  }
LAB_140013933:
  uVar3 = ntohs(*(u_short *)(pbVar2 + 4));
  pbuf_realloc(param_1,uVar3 + 0x28);
  if (pbVar2[6] == 6) {
    crashdump_tcp6_input(param_1);
    return;
  }
  if (pbVar2[6] == 0x3a) {
    crashdump_icmp6_input(param_1,param_2);
    return;
  }
LAB_14001396c:
  pbuf_free(param_1);
  return;
}



===== crashdump_ip6_output @ 14001398c =====

undefined8
crashdump_ip6_output
          (longlong param_1,undefined8 *param_2,uint *param_3,undefined8 param_4,undefined8 param_5,
          undefined1 param_6)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = crashdump_ip6_route(param_3);
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xf7;
  }
  else {
    uVar2 = crashdump_ip6_output_if
                      (param_1,param_2,(int *)param_3,*(undefined1 *)((longlong)puVar1 + 0x11c),
                       param_6,(longlong)puVar1);
  }
  return uVar2;
}



===== crashdump_ip6_output_if @ 1400139ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
crashdump_ip6_output_if
          (longlong param_1,undefined8 *param_2,int *param_3,undefined1 param_4,undefined1 param_5,
          longlong param_6)

{
  undefined1 *puVar1;
  u_short uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar3 = pbuf_header(param_1,0x28);
  if ((char)uVar3 == '\0') {
    puVar1 = *(undefined1 **)(param_1 + 8);
    if (param_3 == (int *)0x0) {
      param_3 = (int *)(puVar1 + 0x18);
    }
    else {
      *puVar1 = 0x60;
      uVar2 = ntohs(*(short *)(param_1 + 0x10) - 0x28);
      *(u_short *)(puVar1 + 4) = uVar2;
      puVar1[6] = param_5;
      puVar1[7] = param_4;
      uVar5 = *(undefined8 *)(param_3 + 2);
      *(undefined8 *)(puVar1 + 0x18) = *(undefined8 *)param_3;
      *(undefined8 *)(puVar1 + 0x20) = uVar5;
      uVar5 = param_2[1];
      *(undefined8 *)(puVar1 + 8) = *param_2;
      *(undefined8 *)(puVar1 + 0x10) = uVar5;
    }
    if ((char)*param_3 != -1) {
      puVar4 = ip_find_onlink_addr(param_6,param_3);
      if ((puVar4 == (undefined8 *)0x0) &&
         ((((*(int *)(param_6 + 200) != 0 || (*(int *)(param_6 + 0xcc) != 0)) ||
           (*(int *)(param_6 + 0xd0) != 0)) || (*(int *)(param_6 + 0xd4) != 0)))) {
        param_3 = (int *)(param_6 + 200);
      }
    }
    *(byte *)(param_6 + 0x3a) = *(byte *)(param_6 + 0x3a) | 0x20;
    lwip_printk();
    uVar5 = (**(code **)(param_6 + 0x18))(param_6,param_1,param_3);
  }
  else {
    uVar5 = CONCAT71((int7)(uVar3 >> 8),0xfe);
  }
  return uVar5;
}



===== crashdump_ip6_route @ 140013af4 =====

undefined8 * crashdump_ip6_route(uint *param_1)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  
  puVar2 = DAT_140074300;
  while( true ) {
    if (puVar2 == (undefined8 *)0x0) {
      return DAT_140074308;
    }
    uVar1 = ip_addr_netcmp(param_1,(uint *)(puVar2 + 0x24),(uint *)(puVar2 + 0x26));
    if ((char)uVar1 != '\0') break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return puVar2;
}



===== crashdump_ip6_tcp_abort @ 140013b44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void crashdump_ip6_tcp_abort(int *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  u_short uVar1;
  u_short uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined1 auStackY_88 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  if (param_1[0xc] == 10) {
    crashdump_ip6_tcp_pcb_remove(&tcp_tw_pcbs,param_1,param_3,param_4);
    memp_free(3,(longlong)param_1);
  }
  else {
    local_48 = *(undefined8 *)param_1;
    uStack_40 = *(undefined8 *)(param_1 + 2);
    uVar3 = param_1[0x1e];
    local_58 = *(undefined8 *)(param_1 + 4);
    uStack_50 = *(undefined8 *)(param_1 + 6);
    uVar4 = param_1[0x12];
    uVar1 = *(u_short *)(param_1 + 0x10);
    uVar2 = *(u_short *)((longlong)param_1 + 0x42);
    pcVar5 = *(code **)(param_1 + 0x36);
    uVar6 = *(undefined8 *)(param_1 + 0xe);
    crashdump_ip6_tcp_pcb_remove(&tcp_active_pcbs,param_1,param_3,param_4);
    if (*(undefined8 **)(param_1 + 0x28) != (undefined8 *)0x0) {
      tcp_segs_free(*(undefined8 **)(param_1 + 0x28));
    }
    if (*(undefined8 **)(param_1 + 0x26) != (undefined8 *)0x0) {
      tcp_segs_free(*(undefined8 **)(param_1 + 0x26));
    }
    if (*(undefined8 **)(param_1 + 0x2a) != (undefined8 *)0x0) {
      tcp_segs_free(*(undefined8 **)(param_1 + 0x2a));
    }
    memp_free(3,(longlong)param_1);
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)(uVar6,0xfd);
    }
    crashdump_ip6_tcp_rst(uVar3,uVar4,&local_48,(uint *)&local_58,uVar1,uVar2);
  }
  return;
}



===== crashdump_ip6_tcp_alloc @ 140013c68 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
crashdump_ip6_tcp_alloc(byte param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  uint uVar2;
  undefined8 *_Dst;
  int *piVar3;
  int *piVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 uVar7;
  byte bVar8;
  undefined7 uVar9;
  
  uVar7 = (undefined1)param_4;
  uVar9 = (undefined7)((ulonglong)param_4 >> 8);
  _Dst = memp_malloc(3);
  if (_Dst == (undefined8 *)0x0) {
    lwip_printk();
    uVar6 = 0;
    piVar4 = (int *)0x0;
    piVar3 = tcp_tw_pcbs;
    uVar5 = uVar6;
    if (tcp_tw_pcbs != (int *)0x0) {
      do {
        uVar2 = _tcp_ticks - piVar3[0x14];
        if ((uint)uVar5 <= uVar2) {
          piVar4 = piVar3;
        }
        piVar3 = *(int **)(piVar3 + 10);
        uVar6 = (ulonglong)uVar2;
        if (uVar2 < (uint)uVar5) {
          uVar6 = uVar5;
        }
        uVar5 = uVar6;
      } while (piVar3 != (int *)0x0);
      if (piVar4 != (int *)0x0) {
        piVar3 = piVar4;
        lwip_printk();
        crashdump_ip6_tcp_abort(piVar4,piVar3,uVar6,CONCAT71(uVar9,uVar7));
      }
    }
    _Dst = memp_malloc(3);
    if (_Dst == (undefined8 *)0x0) {
      bVar8 = 0x7f;
      uVar2 = 0;
      piVar4 = (int *)0x0;
      piVar3 = tcp_active_pcbs;
      if (tcp_active_pcbs != (int *)0x0) {
        do {
          bVar1 = *(byte *)(piVar3 + 0xd);
          uVar6 = CONCAT71((int7)(uVar6 >> 8),bVar1);
          if (((bVar1 <= param_1) && (bVar1 <= bVar8)) &&
             (uVar2 <= (uint)(_tcp_ticks - piVar3[0x14]))) {
            piVar4 = piVar3;
            bVar8 = bVar1;
            uVar2 = _tcp_ticks - piVar3[0x14];
          }
          piVar3 = *(int **)(piVar3 + 10);
        } while (piVar3 != (int *)0x0);
        if (piVar4 != (int *)0x0) {
          crashdump_ip6_tcp_abort(piVar4,piVar4,uVar6,CONCAT71(uVar9,bVar8));
        }
      }
      _Dst = memp_malloc(3);
      if (_Dst == (undefined8 *)0x0) {
        return (undefined8 *)0x0;
      }
    }
  }
  memset(_Dst,0,0xe8);
  *(undefined2 *)((longlong)_Dst + 0x92) = 0xffff;
  *(undefined2 *)((longlong)_Dst + 0x4c) = 0xffff;
  *(undefined2 *)((longlong)_Dst + 0x72) = 1;
  *(undefined1 *)((longlong)_Dst + 0x34) = 0x40;
  *(undefined2 *)((longlong)_Dst + 0x22) = 0x4000;
  *(undefined4 *)((longlong)_Dst + 0x56) = 0x5b40000;
  *(undefined4 *)((longlong)_Dst + 0x66) = 0x60006;
  *(undefined2 *)((longlong)_Dst + 100) = 0;
  DAT_14002d8ec = DAT_14002d8ec + _tcp_ticks;
  *(int *)(_Dst + 0x11) = DAT_14002d8ec;
  *(int *)(_Dst + 0xf) = DAT_14002d8ec;
  *(int *)((longlong)_Dst + 0x7c) = DAT_14002d8ec;
  *(int *)((longlong)_Dst + 0x6c) = DAT_14002d8ec;
  *(int *)((longlong)_Dst + 0x8c) = DAT_14002d8ec;
  *(int *)(_Dst + 10) = _tcp_ticks;
  _Dst[0x17] = tcp_recv_null;
  *(undefined1 *)((longlong)_Dst + 0x54) = 0;
  *(undefined4 *)(_Dst + 0x1c) = 7200000;
  *(undefined1 *)((longlong)_Dst + 0xe4) = 0;
  return _Dst;
}



===== crashdump_ip6_tcp_connect @ 140013e14 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong crashdump_ip6_tcp_connect
                    (int *param_1,uint *param_2,undefined2 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 uVar10;
  undefined7 uVar11;
  uint local_res18 [4];
  
  uVar11 = (undefined7)((ulonglong)param_4 >> 8);
  lwip_printk();
  if (param_2 == (uint *)0x0) {
    uVar6 = lwip_printk();
    uVar7 = CONCAT71((int7)((ulonglong)uVar6 >> 8),0xf9);
  }
  else {
    uVar6 = *(undefined8 *)param_2;
    uVar1 = *(undefined8 *)(param_2 + 2);
    *(undefined2 *)((longlong)param_1 + 0x42) = param_3;
    *(undefined8 *)(param_1 + 4) = uVar6;
    *(undefined8 *)(param_1 + 6) = uVar1;
    if ((short)param_1[0x10] == 0) {
      uVar3 = tcp_new_port();
      *(undefined2 *)(param_1 + 0x10) = uVar3;
    }
    iVar4 = _tcp_ticks + DAT_14002d8ec;
    DAT_14002d8ec = iVar4;
    param_1[0x1e] = iVar4;
    param_1[0x1b] = iVar4 + -1;
    param_1[0x23] = iVar4 + -1;
    *(undefined2 *)(param_1 + 0x13) = 0xffff;
    param_1[0x20] = 0xffff;
    *(undefined2 *)(param_1 + 0x16) = 0x5a0;
    param_1[0x12] = 0;
    puVar5 = ip_find_src_addr(param_2);
    uVar9 = 0;
    uVar10 = 2;
    uVar8 = 0;
    uVar6 = *puVar5;
    uVar1 = puVar5[1];
    *(undefined4 *)((longlong)param_1 + 0x72) = 0x38400001;
    param_1[0xc] = 2;
    *(undefined8 *)param_1 = uVar6;
    *(undefined8 *)(param_1 + 2) = uVar1;
    *(undefined8 *)(param_1 + 0x30) = param_4;
    *(int **)(param_1 + 10) = tcp_active_pcbs;
    local_res18[0] =
         ((uint)*(ushort *)(param_1 + 0x16) << 0x10 | *(ushort *)(param_1 + 0x16) & 0xff00) << 8 |
         0x402;
    tcp_active_pcbs = param_1;
    uVar6 = crashdump_ip6_tcp_enqueue((longlong)param_1,(void *)0x0,0,2,'\0',local_res18,4);
    cVar2 = (char)uVar6;
    if (cVar2 == '\0') {
      uVar6 = crashdump_tcp6_output(param_1,uVar8,uVar9,CONCAT71(uVar11,uVar10));
    }
    uVar7 = CONCAT71((int7)((ulonglong)uVar6 >> 8),cVar2);
  }
  return uVar7;
}



===== crashdump_ip6_tcp_debug_print @ 140013f54 =====

void crashdump_ip6_tcp_debug_print(u_short *param_1)

{
  u_short uVar1;
  
  lwip_printk();
  lwip_printk();
  ntohs(param_1[1]);
  ntohs(*param_1);
  lwip_printk();
  lwip_printk();
  lwip_printk();
  lwip_printk();
  lwip_printk();
  lwip_printk();
  ntohs(param_1[7]);
  ntohs(param_1[6]);
  ntohs(param_1[6]);
  ntohs(param_1[6]);
  ntohs(param_1[6]);
  ntohs(param_1[6]);
  ntohs(param_1[6]);
  ntohs(param_1[6]);
  lwip_printk();
  uVar1 = ntohs(param_1[6]);
  crashdump_ip6_tcp_debug_print_flags((byte)uVar1 & 0x3f);
  lwip_printk();
  lwip_printk();
  ntohs(param_1[9]);
  ntohs(param_1[8]);
  lwip_printk();
  lwip_printk();
  return;
}



===== crashdump_ip6_tcp_debug_print_flags @ 140014164 =====

void crashdump_ip6_tcp_debug_print_flags(byte param_1)

{
  if ((param_1 & 1) != 0) {
    lwip_printk();
  }
  if ((param_1 & 2) != 0) {
    lwip_printk();
  }
  if ((param_1 & 4) != 0) {
    lwip_printk();
  }
  if ((param_1 & 8) != 0) {
    lwip_printk();
  }
  if ((param_1 & 0x10) != 0) {
    lwip_printk();
  }
  if ((param_1 & 0x20) != 0) {
    lwip_printk();
  }
  if ((param_1 & 0x40) != 0) {
    lwip_printk();
  }
  if ((char)param_1 < '\0') {
    lwip_printk();
  }
  return;
}



===== crashdump_ip6_tcp_enqueue @ 1400141fc =====

undefined8
crashdump_ip6_tcp_enqueue
          (longlong param_1,void *param_2,ushort param_3,byte param_4,char param_5,void *param_6,
          byte param_7)

{
  u_short uVar1;
  ushort uVar2;
  ulonglong in_RAX;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined6 extraout_var_01;
  ulonglong uVar6;
  uint7 extraout_var;
  uint7 extraout_var_00;
  char *pcVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  undefined8 *puVar11;
  ulonglong _Size;
  undefined8 *local_res8;
  uint local_res18;
  void *local_58;
  
  _Size = 0;
  if ((param_3 != 0) && (param_7 != 0)) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("tcp_enqueue: len == 0 || optlen == 0 (programmer violates API)");
  }
  if ((param_2 != (void *)0x0) && (param_6 != (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("tcp_enqueue: arg == NULL || optdata == NULL (programmer violates API)");
  }
  if (param_3 <= *(ushort *)(param_1 + 0x92)) {
    bVar8 = *(byte *)(param_1 + 0x94);
    uVar9 = (uint)param_3;
    local_res18 = *(uint *)(param_1 + 0x8c);
    in_RAX = (ulonglong)local_res18;
    if (bVar8 < 0xb3) {
      if (bVar8 == 0) {
        if ((*(longlong *)(param_1 + 0xa0) != 0) || (*(longlong *)(param_1 + 0x98) != 0)) {
          pcVar7 = "tcp_enqueue: no pbufs on queue => both queues empty";
          goto LAB_1400142cb;
        }
      }
      else if ((*(longlong *)(param_1 + 0xa0) == 0) && (*(longlong *)(param_1 + 0x98) == 0)) {
        pcVar7 = "tcp_enqueue: pbufs on queue => at least one queue non-empty";
LAB_1400142cb:
                    /* WARNING: Subroutine does not return */
        DbgPrint(pcVar7);
      }
      local_res8 = (undefined8 *)0x0;
      puVar11 = (undefined8 *)0x0;
      local_58 = param_2;
LAB_1400142df:
      if ((puVar11 != (undefined8 *)0x0) && (uVar9 == 0)) {
        puVar3 = *(undefined8 **)(param_1 + 0x98);
        iVar10 = 0;
        if (puVar3 == (undefined8 *)0x0) {
          *(undefined8 **)(param_1 + 0x98) = puVar11;
        }
        else {
          for (puVar4 = (undefined8 *)*puVar3; puVar4 != (undefined8 *)0x0;
              puVar4 = (undefined8 *)*puVar4) {
            puVar3 = puVar4;
          }
          uVar1 = ntohs(*(u_short *)(puVar3[4] + 0xc));
          if (((uVar1 & 1) != 0) || (uVar1 = ntohs(*(u_short *)(puVar3[4] + 0xc)), (uVar1 & 2) != 0)
             ) {
            iVar10 = 1;
          }
          if (((((uint)*(ushort *)(puVar3 + 3) + iVar10 == 0) ||
               (uVar1 = ntohs(*(u_short *)(puVar3[4] + 0xc)), (uVar1 & 3) != 0)) ||
              ((param_4 & 3) != 0)) ||
             ((uint)*(ushort *)(param_1 + 0x58) <
              (uint)*(ushort *)(puVar11 + 3) + (uint)*(ushort *)(puVar3 + 3))) {
            *puVar3 = puVar11;
          }
          else {
            pbuf_header(puVar11[1],-0x14);
            pbuf_cat((longlong *)puVar3[1],puVar11[1]);
            *(short *)(puVar3 + 3) = *(short *)(puVar3 + 3) + *(short *)(puVar11 + 3);
            *puVar3 = *puVar11;
            memp_free(5,(longlong)puVar11);
            puVar3 = (undefined8 *)0x0;
            if (local_res8 != puVar11) {
              puVar3 = local_res8;
            }
            local_res8 = puVar3;
          }
        }
        *(byte *)(param_1 + 0x94) = bVar8;
        uVar2 = param_3 + 1;
        if ((param_4 & 3) == 0) {
          uVar2 = param_3;
        }
        uVar6 = (ulonglong)uVar2;
        *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + (uint)uVar2;
        *(short *)(param_1 + 0x92) = *(short *)(param_1 + 0x92) - uVar2;
        if (((bVar8 != 0) && (*(longlong *)(param_1 + 0xa0) == 0)) &&
           (*(longlong *)(param_1 + 0x98) == 0)) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_enqueue: valid queue length");
        }
        if ((local_res8 != (undefined8 *)0x0) && ((short)_Size != 0)) {
          uVar6 = 0;
          if (local_res8[4] != 0) {
            uVar1 = ntohs(*(u_short *)(local_res8[4] + 0xc));
            uVar1 = ntohs(uVar1 | 8);
            uVar6 = CONCAT62(extraout_var_01,uVar1);
            *(u_short *)(local_res8[4] + 0xc) = uVar1;
          }
        }
        return uVar6 & 0xffffffffffffff00;
      }
      uVar2 = *(ushort *)(param_1 + 0x58);
      if (uVar9 <= *(ushort *)(param_1 + 0x58)) {
        uVar2 = (ushort)uVar9;
      }
      _Size = (ulonglong)uVar2;
      puVar3 = memp_malloc(5);
      in_RAX = 0;
      if (puVar3 == (undefined8 *)0x0) goto LAB_1400146e1;
      *puVar3 = 0;
      puVar3[1] = 0;
      if (puVar11 == (undefined8 *)0x0) {
        puVar11 = puVar3;
      }
      else {
        if (local_res8 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("useg != NULL");
        }
        *local_res8 = puVar3;
      }
      if (param_6 == (void *)0x0) {
        if (param_5 != '\0') {
          puVar4 = pbuf_alloc(0,uVar2,0);
          puVar3[1] = puVar4;
          in_RAX = 0;
          if (puVar4 != (undefined8 *)0x0) {
            if (param_2 != (void *)0x0) {
              memmove((void *)puVar4[1],local_58,_Size);
              puVar4 = (undefined8 *)puVar3[1];
            }
            goto LAB_1400143cb;
          }
          goto LAB_1400146e1;
        }
        puVar4 = pbuf_alloc(0,uVar2,1);
        in_RAX = 0;
        if (puVar4 == (undefined8 *)0x0) goto LAB_1400146e1;
        puVar4[1] = local_58;
        puVar3[2] = local_58;
        plVar5 = pbuf_alloc(0,0,0);
        puVar3[1] = plVar5;
        if (plVar5 == (longlong *)0x0) {
          pbuf_free(puVar4);
          in_RAX = (ulonglong)extraout_var << 8;
LAB_1400146e1:
          if (puVar11 != (undefined8 *)0x0) {
            tcp_segs_free(puVar11);
            in_RAX = (ulonglong)extraout_var_00 << 8;
          }
          if (((*(char *)(param_1 + 0x94) != '\0') && (*(longlong *)(param_1 + 0xa0) == 0)) &&
             (*(longlong *)(param_1 + 0x98) == 0)) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_enqueue: valid queue length");
          }
          goto LAB_140014717;
        }
        bVar8 = bVar8 + 2;
        in_RAX = pbuf_cat(plVar5,(longlong)puVar4);
      }
      else {
        puVar4 = pbuf_alloc(0,(ushort)param_7,0);
        puVar3[1] = puVar4;
        in_RAX = 0;
        if (puVar4 == (undefined8 *)0x0) goto LAB_1400146e1;
LAB_1400143cb:
        bVar8 = bVar8 + 1;
        in_RAX = puVar4[1];
        puVar3[2] = in_RAX;
      }
      if (0xb3 < bVar8) goto LAB_1400146e1;
      *(ushort *)(puVar3 + 3) = uVar2;
      in_RAX = pbuf_header(puVar3[1],0x14);
      if ((char)in_RAX != '\0') goto LAB_1400146e1;
      puVar3[4] = *(undefined8 *)(puVar3[1] + 8);
      uVar1 = ntohs(*(u_short *)(param_1 + 0x40));
      *(u_short *)puVar3[4] = uVar1;
      uVar1 = ntohs(*(u_short *)(param_1 + 0x42));
      *(u_short *)(puVar3[4] + 2) = uVar1;
      *(uint *)(puVar3[4] + 4) =
           local_res18 >> 0x18 | (local_res18 & 0xff0000) >> 8 | (local_res18 & 0xff00) << 8 |
           local_res18 << 0x18;
      *(undefined2 *)(puVar3[4] + 0x12) = 0;
      uVar1 = ntohs(*(u_short *)(puVar3[4] + 0xc));
      uVar1 = ntohs(uVar1 & 0xffc0 | (ushort)param_4);
      *(u_short *)(puVar3[4] + 0xc) = uVar1;
      if (param_6 == (void *)0x0) {
        uVar1 = ntohs(*(u_short *)(puVar3[4] + 0xc));
        uVar1 = ntohs(uVar1 & 0x3f | 0x5000);
        *(u_short *)(puVar3[4] + 0xc) = uVar1;
      }
      else {
        uVar1 = ntohs(*(u_short *)(puVar3[4] + 0xc));
        uVar1 = ntohs(uVar1 & 0x3f | ((param_7 & 0xfffc) + 0x14) * 0x400);
        *(u_short *)(puVar3[4] + 0xc) = uVar1;
        memmove((void *)puVar3[2],param_6,(ulonglong)param_7);
      }
      local_res18 = local_res18 + uVar2;
      uVar9 = uVar9 - uVar2;
      local_58 = (void *)((longlong)local_58 + _Size);
      local_res8 = puVar3;
      goto LAB_1400142df;
    }
  }
LAB_140014717:
  return CONCAT71((int7)(in_RAX >> 8),0xff);
}



===== crashdump_ip6_tcp_fasttmr @ 14001472c =====

void crashdump_ip6_tcp_fasttmr
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  int *piVar1;
  
  for (piVar1 = tcp_active_pcbs; piVar1 != (int *)0x0; piVar1 = *(int **)(piVar1 + 10)) {
    if ((*(byte *)(piVar1 + 0x11) & 1) != 0) {
      lwip_printk();
      *(byte *)(piVar1 + 0x11) = *(byte *)(piVar1 + 0x11) | 2;
      crashdump_tcp6_output(piVar1,param_2,param_3,param_4);
      *(byte *)(piVar1 + 0x11) = *(byte *)(piVar1 + 0x11) & 0xfc;
    }
  }
  return;
}



===== crashdump_ip6_tcp_keepalive @ 14001476c =====

void crashdump_ip6_tcp_keepalive
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  u_short *puVar1;
  u_short uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined7 uVar5;
  undefined4 in_stack_ffffffffffffffec;
  
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  puVar3 = pbuf_alloc(1,0x14,0);
  if (puVar3 != (undefined8 *)0x0) {
    puVar1 = (u_short *)puVar3[1];
    uVar2 = ntohs(*(u_short *)(param_1 + 8));
    *puVar1 = uVar2;
    uVar2 = ntohs(*(u_short *)((longlong)param_1 + 0x42));
    puVar1[1] = uVar2;
    uVar4 = *(int *)(param_1 + 0xf) - 1;
    *(uint *)(puVar1 + 2) =
         uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 * 0x1000000;
    uVar4 = *(uint *)(param_1 + 9);
    *(uint *)(puVar1 + 4) =
         (uVar4 << 0x10 | uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 |
         (uint)*(byte *)((longlong)param_1 + 0x4b);
    uVar2 = ntohs(*(u_short *)((longlong)param_1 + 0x4c));
    puVar1[7] = uVar2;
    puVar1[9] = 0;
    uVar2 = ntohs(puVar1[6]);
    uVar2 = ntohs(uVar2 & 0x3f | 0x5000);
    puVar1[6] = uVar2;
    puVar1[8] = 0;
    uVar4 = (uint)*(ushort *)(puVar3 + 2);
    uVar2 = crashdump_ip6_inet_chksum_pseudo
                      (puVar3,(longlong)param_1,(u_short *)(param_1 + 2),6,uVar4);
    puVar1[8] = uVar2;
    crashdump_ip6_output
              ((longlong)puVar3,param_1,(uint *)(param_1 + 2),
               CONCAT71(uVar5,*(undefined1 *)((longlong)param_1 + 0x23)),
               CONCAT44(in_stack_ffffffffffffffec,uVar4) & 0xffffffffffffff00,6);
    pbuf_free(puVar3);
  }
  return;
}



===== crashdump_ip6_tcp_pcb_purge @ 14001488c =====

void crashdump_ip6_tcp_pcb_purge(longlong param_1)

{
  undefined8 *puVar1;
  
  if ((1 < *(uint *)(param_1 + 0x30)) && (*(uint *)(param_1 + 0x30) != 10)) {
    if (*(longlong *)(param_1 + 0x98) != 0) {
      lwip_printk();
    }
    if (*(longlong *)(param_1 + 0xa0) != 0) {
      lwip_printk();
    }
    puVar1 = (undefined8 *)0x0;
    if (*(longlong *)(param_1 + 0xa8) != 0) {
      lwip_printk();
      puVar1 = *(undefined8 **)(param_1 + 0xa8);
    }
    tcp_segs_free(puVar1);
    *(undefined8 *)(param_1 + 0xa8) = 0;
    tcp_segs_free(*(undefined8 **)(param_1 + 0x98));
    tcp_segs_free(*(undefined8 **)(param_1 + 0xa0));
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  return;
}



===== crashdump_ip6_tcp_pcb_remove @ 140014930 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crashdump_ip6_tcp_pcb_remove
               (longlong *param_1,int *param_2,undefined8 param_3,longlong param_4)

{
  undefined8 uVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  if (piVar3 == param_2) {
    *param_1 = *(longlong *)(piVar3 + 10);
  }
  else {
    _tcp_tmp_pcb = piVar3;
    while (piVar3 = _tcp_tmp_pcb, _tcp_tmp_pcb != (int *)0x0) {
      piVar2 = *(int **)(_tcp_tmp_pcb + 10);
      if ((piVar2 != (int *)0x0) && (piVar2 == param_2)) {
        *(undefined8 *)(_tcp_tmp_pcb + 10) = *(undefined8 *)(param_2 + 10);
        break;
      }
      _tcp_tmp_pcb = piVar2;
    }
  }
  param_2[10] = 0;
  param_2[0xb] = 0;
  piVar2 = param_2;
  crashdump_ip6_tcp_pcb_purge((longlong)param_2);
  if (((param_2[0xc] != 10) && (param_2[0xc] != 1)) && ((*(byte *)(param_2 + 0x11) & 1) != 0)) {
    *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) | 2;
    crashdump_tcp6_output(param_2,piVar2,piVar3,param_4);
  }
  param_2[0xc] = 0;
  uVar1 = crashdump_ip6_tcp_pcbs_sane();
  if ((short)uVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("tcp_pcb_remove: tcp_pcbs_sane()");
  }
  return;
}



===== crashdump_ip6_tcp_pcbs_sane @ 1400149d4 =====

undefined8 crashdump_ip6_tcp_pcbs_sane(void)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = tcp_active_pcbs;
  while( true ) {
    if (lVar2 == 0) {
      lVar2 = tcp_tw_pcbs;
      while( true ) {
        if (lVar2 == 0) {
          return 1;
        }
        if (*(int *)(lVar2 + 0x30) != 10) break;
        lVar2 = *(longlong *)(lVar2 + 0x28);
      }
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_pcbs_sane: tw pcb->state == TIME-WAIT");
    }
    iVar1 = *(int *)(lVar2 + 0x30);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_pcbs_sane: active pcb->state != CLOSED");
    }
    if (iVar1 == 1) break;
    if (iVar1 == 10) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_pcbs_sane: active pcb->state != TIME-WAIT");
    }
    lVar2 = *(longlong *)(lVar2 + 0x28);
  }
                    /* WARNING: Subroutine does not return */
  DbgPrint("tcp_pcbs_sane: active pcb->state != LISTEN");
}



===== crashdump_ip6_tcp_rexmit @ 140014a68 =====

void crashdump_ip6_tcp_rexmit(int *param_1)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  
  puVar2 = *(undefined8 **)(param_1 + 0x28);
  if (puVar2 != (undefined8 *)0x0) {
    uVar3 = *puVar2;
    *puVar2 = *(undefined8 *)(param_1 + 0x26);
    lVar4 = *(longlong *)(param_1 + 0x28);
    *(longlong *)(param_1 + 0x26) = lVar4;
    *(undefined8 *)(param_1 + 0x28) = uVar3;
    lVar4 = *(longlong *)(lVar4 + 0x20);
    uVar6 = *(uint *)(lVar4 + 4);
    uVar5 = uVar6 >> 8 & 0xff00;
    bVar1 = *(byte *)(lVar4 + 7);
    *(char *)((longlong)param_1 + 0x6a) = *(char *)((longlong)param_1 + 0x6a) + '\x01';
    param_1[0x17] = 0;
    uVar6 = (uVar6 << 0x10 | uVar6 & 0xff00) << 8 | (uint)bVar1 | uVar5;
    param_1[0x1e] = uVar6;
    crashdump_tcp6_output(param_1,(ulonglong)uVar5,(ulonglong)uVar6,(longlong)param_1);
  }
  return;
}



===== crashdump_ip6_tcp_rexmit_rto @ 140014ae8 =====

void crashdump_ip6_tcp_rexmit_rto(int *param_1)

{
  byte bVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  uint uVar5;
  
  puVar2 = *(undefined8 **)(param_1 + 0x28);
  if (puVar2 != (undefined8 *)0x0) {
    for (puVar4 = (undefined8 *)*puVar2; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)*puVar4
        ) {
      puVar2 = puVar4;
    }
    *puVar2 = *(undefined8 *)(param_1 + 0x26);
    lVar3 = *(longlong *)(param_1 + 0x28);
    param_1[0x28] = 0;
    param_1[0x29] = 0;
    *(longlong *)(param_1 + 0x26) = lVar3;
    lVar3 = *(longlong *)(lVar3 + 0x20);
    uVar5 = *(uint *)(lVar3 + 4);
    bVar1 = *(byte *)(lVar3 + 7);
    *(char *)((longlong)param_1 + 0x6a) = *(char *)((longlong)param_1 + 0x6a) + '\x01';
    param_1[0x17] = 0;
    uVar5 = (uVar5 << 0x10 | uVar5 & 0xff00) << 8 | uVar5 >> 8 & 0xff00 | (uint)bVar1;
    param_1[0x1e] = uVar5;
    crashdump_tcp6_output(param_1,lVar3,(ulonglong)uVar5,(longlong)param_1);
  }
  return;
}



===== crashdump_ip6_tcp_rst @ 140014b7c =====

void crashdump_ip6_tcp_rst
               (uint param_1,uint param_2,undefined8 *param_3,uint *param_4,u_short param_5,
               u_short param_6)

{
  u_short *puVar1;
  u_short uVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined7 uVar5;
  undefined4 in_stack_ffffffffffffffcc;
  
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  puVar4 = pbuf_alloc(1,0x14,0);
  if (puVar4 != (undefined8 *)0x0) {
    puVar1 = (u_short *)puVar4[1];
    uVar2 = ntohs(param_5);
    *puVar1 = uVar2;
    uVar2 = ntohs(param_6);
    *(uint *)(puVar1 + 2) =
         param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
    *(uint *)(puVar1 + 4) =
         param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 | param_2 << 0x18;
    puVar1[1] = uVar2;
    uVar2 = ntohs(puVar1[6]);
    uVar2 = ntohs(uVar2 & 0xffd4 | 0x14);
    puVar1[6] = uVar2;
    uVar2 = ntohs(0xffff);
    puVar1[7] = uVar2;
    puVar1[9] = 0;
    uVar2 = ntohs(puVar1[6]);
    uVar2 = ntohs(uVar2 & 0x3f | 0x5000);
    puVar1[6] = uVar2;
    puVar1[8] = 0;
    uVar3 = (uint)*(ushort *)(puVar4 + 2);
    uVar2 = crashdump_ip6_inet_chksum_pseudo(puVar4,(longlong)param_3,(u_short *)param_4,6,uVar3);
    puVar1[8] = uVar2;
    crashdump_ip6_output
              ((longlong)puVar4,param_3,param_4,CONCAT71(uVar5,0x40),
               CONCAT44(in_stack_ffffffffffffffcc,uVar3) & 0xffffffffffffff00,6);
    pbuf_free(puVar4);
  }
  return;
}



===== crashdump_ip6_tcp_slowtmr @ 140014ca8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crashdump_ip6_tcp_slowtmr(undefined8 param_1,int *param_2,ulonglong param_3,ulonglong param_4)

{
  int *piVar1;
  longlong lVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  int *piVar8;
  char cVar9;
  int *piVar10;
  longlong lVar11;
  longlong lVar12;
  uint uVar13;
  
  _tcp_ticks = _tcp_ticks + 1;
  cVar3 = '\0';
  piVar10 = (int *)0x0;
  piVar8 = tcp_active_pcbs;
  do {
    if (piVar8 == (int *)0x0) {
      lVar11 = 0;
      lVar12 = tcp_tw_pcbs;
      while( true ) {
        if (lVar12 == 0) {
          return;
        }
        if (*(int *)(lVar12 + 0x30) != 10) break;
        if ((uint)(_tcp_ticks - *(int *)(lVar12 + 0x50)) < 0xf1) {
          lVar11 = lVar12;
          lVar12 = *(longlong *)(lVar12 + 0x28);
        }
        else {
          crashdump_ip6_tcp_pcb_purge(lVar12);
          if (lVar11 == 0) {
            if (tcp_tw_pcbs != lVar12) {
                    /* WARNING: Subroutine does not return */
              DbgPrint("tcp_slowtmr: first pcb == tcp_tw_pcbs");
            }
            tcp_tw_pcbs = *(longlong *)(lVar12 + 0x28);
          }
          else {
            if (lVar12 == tcp_tw_pcbs) {
                    /* WARNING: Subroutine does not return */
              DbgPrint("tcp_slowtmr: middle tcp != tcp_tw_pcbs");
            }
            *(undefined8 *)(lVar11 + 0x28) = *(undefined8 *)(lVar12 + 0x28);
          }
          lVar2 = *(longlong *)(lVar12 + 0x28);
          memp_free(3,lVar12);
          lVar12 = lVar2;
        }
      }
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: TIME-WAIT pcb->state == TIME-WAIT");
    }
    iVar5 = piVar8[0xc];
    if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: active pcb->state != CLOSED\n");
    }
    if (iVar5 == 1) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: active pcb->state != LISTEN\n");
    }
    if (iVar5 == 10) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: active pcb->state != TIME-WAIT\n");
    }
    cVar9 = '\0';
    if (((iVar5 == 2) && (*(char *)((longlong)piVar8 + 0x6a) == '\x06')) ||
       (*(char *)((longlong)piVar8 + 0x6a) == '\f')) {
      cVar9 = '\x01';
      lwip_printk();
    }
    else {
      uVar4 = *(short *)((longlong)piVar8 + 0x56) + 1;
      *(ushort *)((longlong)piVar8 + 0x56) = uVar4;
      if ((*(longlong *)(piVar8 + 0x28) != 0) && (*(ushort *)(piVar8 + 0x1a) <= uVar4)) {
        param_3 = (ulonglong)*(ushort *)(piVar8 + 0x1a);
        lwip_printk();
        if (piVar8[0xc] != 2) {
          *(short *)(piVar8 + 0x1a) =
               ((short)piVar8[0x19] >> 3) + *(short *)((longlong)piVar8 + 0x66) <<
               ((&crashdump_tcp6_backoff)[*(byte *)((longlong)piVar8 + 0x6a)] & 0x1f);
        }
        uVar4 = *(ushort *)(piVar8 + 0x16);
        param_2 = (int *)(ulonglong)uVar4;
        uVar7 = (uint)*(ushort *)((longlong)piVar8 + 0x72);
        if ((uint)piVar8[0x20] <= (uint)*(ushort *)((longlong)piVar8 + 0x72)) {
          uVar7 = piVar8[0x20];
        }
        uVar6 = (ushort)(uVar7 >> 1);
        *(ushort *)(piVar8 + 0x1d) = uVar6;
        if (uVar6 < uVar4) {
          *(ushort *)(piVar8 + 0x1d) = uVar4 * 2;
        }
        *(ushort *)((longlong)piVar8 + 0x72) = uVar4;
        crashdump_ip6_tcp_rexmit_rto(piVar8);
      }
    }
    iVar5 = piVar8[0xc];
    if ((iVar5 == 6) && (0x28 < (uint)(_tcp_ticks - piVar8[0x14]))) {
      cVar9 = cVar9 + '\x01';
    }
    if (((*(byte *)(piVar8 + 8) & 8) != 0) && ((iVar5 == 4 || (iVar5 == 7)))) {
      uVar7 = piVar8[0x38];
      param_4 = (ulonglong)uVar7;
      uVar13 = _tcp_ticks - piVar8[0x14];
      param_3 = (ulonglong)uVar13;
      param_2 = (int *)((ulonglong)(uVar7 + 0xa4cb8) / 500);
      if ((uint)param_2 < uVar13) {
        lwip_printk();
        crashdump_ip6_tcp_abort(piVar8,param_2,param_3,param_4);
      }
      else {
        param_2 = (int *)((ulonglong)((uint)*(byte *)(piVar8 + 0x39) * 75000 + uVar7) / 500);
        if ((uint)param_2 < uVar13) {
          crashdump_ip6_tcp_keepalive((undefined8 *)piVar8,param_2,param_3,param_4);
          *(char *)(piVar8 + 0x39) = (char)piVar8[0x39] + '\x01';
        }
      }
    }
    if (*(undefined8 **)(piVar8 + 0x2a) != (undefined8 *)0x0) {
      param_3 = (ulonglong)(uint)(_tcp_ticks - piVar8[0x14]);
      param_2 = (int *)(ulonglong)((uint)*(ushort *)(piVar8 + 0x1a) * 6);
      if ((uint)*(ushort *)(piVar8 + 0x1a) * 6 <= (uint)(_tcp_ticks - piVar8[0x14])) {
        tcp_segs_free(*(undefined8 **)(piVar8 + 0x2a));
        piVar8[0x2a] = 0;
        piVar8[0x2b] = 0;
      }
    }
    iVar5 = piVar8[0xc];
    if (iVar5 == 3) {
      if (0x28 < (uint)(_tcp_ticks - piVar8[0x14])) {
        cVar9 = cVar9 + '\x01';
        lwip_printk();
        iVar5 = piVar8[0xc];
        goto LAB_140014ecd;
      }
    }
    else {
LAB_140014ecd:
      if ((iVar5 == 9) && (0xf0 < (uint)(_tcp_ticks - piVar8[0x14]))) {
        cVar9 = cVar9 + '\x01';
        lwip_printk();
      }
    }
    if (cVar9 == '\0') {
      *(char *)(piVar8 + 0x15) = (char)piVar8[0x15] + '\x01';
      if (*(byte *)((longlong)piVar8 + 0x55) <= *(byte *)(piVar8 + 0x15)) {
        *(undefined1 *)(piVar8 + 0x15) = 0;
        if (*(code **)(piVar8 + 0x34) != (code *)0x0) {
          param_2 = piVar8;
          cVar3 = (**(code **)(piVar8 + 0x34))(*(undefined8 *)(piVar8 + 0xe));
        }
        if (cVar3 == '\0') {
          crashdump_tcp6_output(piVar8,param_2,param_3,param_4);
        }
      }
      piVar10 = piVar8;
      piVar8 = *(int **)(piVar8 + 10);
    }
    else {
      crashdump_ip6_tcp_pcb_purge((longlong)piVar8);
      if (piVar10 == (int *)0x0) {
        if (tcp_active_pcbs != piVar8) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_slowtmr: first pcb == tcp_active_pcbs");
        }
        tcp_active_pcbs = *(int **)(piVar8 + 10);
      }
      else {
        if (piVar8 == tcp_active_pcbs) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_slowtmr: middle tcp != tcp_active_pcbs");
        }
        *(undefined8 *)(piVar10 + 10) = *(undefined8 *)(piVar8 + 10);
      }
      if (*(code **)(piVar8 + 0x36) != (code *)0x0) {
        (**(code **)(piVar8 + 0x36))(*(undefined8 *)(piVar8 + 0xe),0xfd);
      }
      piVar1 = *(int **)(piVar8 + 10);
      memp_free(3,(longlong)piVar8);
      param_2 = piVar8;
      piVar8 = piVar1;
    }
  } while( true );
}



===== crashdump_ip6_tcp_tmr @ 140015080 =====

void crashdump_ip6_tcp_tmr(undefined8 param_1,int *param_2,ulonglong param_3,ulonglong param_4)

{
  crashdump_ip6_tcp_fasttmr(param_1,param_2,param_3,param_4);
  DAT_1400742fa = DAT_1400742fa + 1;
  if ((DAT_1400742fa & 1) != 0) {
    crashdump_ip6_tcp_slowtmr(param_1,param_2,param_3,param_4);
  }
  return;
}



===== crashdump_ip6_tcp_write @ 1400150a8 =====

undefined8 crashdump_ip6_tcp_write(longlong param_1,void *param_2,ushort param_3,char param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(int *)(param_1 + 0x30) - 2;
  if ((uVar1 < 3) || (*(int *)(param_1 + 0x30) == 7)) {
    uVar2 = 0;
    if (param_3 != 0) {
      uVar2 = crashdump_ip6_tcp_enqueue(param_1,param_2,param_3,0,param_4,(void *)0x0,0);
    }
  }
  else {
    uVar2 = CONCAT71((uint7)(uint3)(uVar1 >> 8),0xfa);
  }
  return uVar2;
}



===== crashdump_tcp6_close @ 1400150ec =====

char crashdump_tcp6_close(int *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined1 uVar6;
  undefined7 uVar7;
  
  uVar6 = (undefined1)param_4;
  uVar7 = (undefined7)((ulonglong)param_4 >> 8);
  iVar3 = param_1[0xc];
  if (iVar3 == 0) {
    cVar1 = '\0';
    memp_free(3,(longlong)param_1);
    piVar5 = (int *)0x0;
    piVar4 = param_1;
LAB_1400151d7:
    if ((piVar5 != (int *)0x0) && (cVar1 == '\0')) {
      uVar2 = crashdump_tcp6_output(piVar5,piVar4,param_3,CONCAT71(uVar7,uVar6));
      cVar1 = (char)uVar2;
    }
  }
  else {
    if (iVar3 == 1) {
      crashdump_ip6_tcp_pcb_remove(&tcp_listen_pcbs,param_1,param_3,param_4);
      iVar3 = 4;
    }
    else {
      if (iVar3 != 2) {
        piVar5 = param_1;
        if ((iVar3 == 3) || (iVar3 == 4)) {
          param_3 = 0;
          uVar6 = 1;
          piVar4 = (int *)0x0;
          uVar2 = crashdump_ip6_tcp_enqueue((longlong)param_1,(void *)0x0,0,1,'\x01',(void *)0x0,0);
          cVar1 = (char)uVar2;
          if (cVar1 == '\0') {
            param_1[0xc] = 5;
          }
        }
        else {
          if (iVar3 != 7) {
            return '\0';
          }
          param_3 = 0;
          uVar6 = 1;
          piVar4 = (int *)0x0;
          uVar2 = crashdump_ip6_tcp_enqueue((longlong)param_1,(void *)0x0,0,1,'\x01',(void *)0x0,0);
          cVar1 = (char)uVar2;
          if (cVar1 == '\0') {
            param_1[0xc] = 9;
          }
        }
        goto LAB_1400151d7;
      }
      crashdump_ip6_tcp_pcb_remove(&tcp_active_pcbs,param_1,param_3,param_4);
      iVar3 = 3;
    }
    cVar1 = '\0';
    memp_free(iVar3,(longlong)param_1);
  }
  return cVar1;
}



===== crashdump_tcp6_input @ 1400151fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crashdump_tcp6_input(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint *puVar5;
  u_short *puVar6;
  char cVar7;
  short sVar8;
  u_short uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  int *piVar12;
  ushort uVar13;
  int *piVar14;
  int *piVar15;
  undefined8 *puVar16;
  u_short *puVar17;
  uint local_res8 [2];
  
  DAT_140074340 = param_1[1];
  DAT_140074338 = (u_short *)(DAT_140074340 + 0x28);
  crashdump_ip6_tcp_debug_print(DAT_140074338);
  uVar10 = pbuf_header((longlong)param_1,-0x28);
  if ((((char)uVar10 != '\0') || (*(ushort *)(param_1 + 2) < 0x14)) ||
     (sVar8 = crashdump_ip6_inet_chksum_pseudo
                        (param_1,DAT_140074340 + 8,(u_short *)(DAT_140074340 + 0x18),6,
                         (uint)*(ushort *)(param_1 + 2)), sVar8 != 0)) {
LAB_1400156db:
    pbuf_free(param_1);
    return;
  }
  uVar9 = ntohs(DAT_140074338[6]);
  pbuf_header((longlong)param_1,(uVar9 >> 0xc) * -4);
  uVar9 = ntohs(*DAT_140074338);
  puVar17 = DAT_140074338;
  *DAT_140074338 = uVar9;
  uVar9 = ntohs(puVar17[1]);
  puVar17 = DAT_140074338;
  uVar1 = *(uint *)(DAT_140074338 + 2);
  DAT_140074338[1] = uVar9;
  DAT_140074348 =
       (uVar1 << 0x10 | uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 |
       (uint)*(byte *)((longlong)puVar17 + 7);
  *(uint *)(puVar17 + 2) = DAT_140074348;
  uVar1 = *(uint *)(puVar17 + 4);
  DAT_14007434c =
       (uVar1 << 0x10 | uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 |
       (uint)*(byte *)((longlong)puVar17 + 0xb);
  *(uint *)(puVar17 + 4) = DAT_14007434c;
  uVar9 = ntohs(puVar17[7]);
  puVar6 = DAT_140074338;
  DAT_140074338[7] = uVar9;
  uVar9 = ntohs(puVar6[6]);
  uVar10 = DAT_140074340;
  puVar6 = DAT_140074338;
  piVar14 = (int *)((ulonglong)uVar9 & 0xffffffffffffff3f);
  DAT_1400742fb = SUB81(piVar14,0);
  uVar13 = (ushort)((uVar9 & 3) != 0) + *(short *)(param_1 + 2);
  piVar3 = (int *)0x0;
  for (piVar15 = tcp_active_pcbs; piVar12 = tcp_tw_pcbs, DAT_140074350 = uVar13,
      piVar15 != (int *)0x0; piVar15 = *(int **)(piVar15 + 10)) {
    iVar2 = piVar15[0xc];
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_input: active pcb->state != CLOSED");
    }
    if (iVar2 == 10) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_input: active pcb->state != TIME-WAIT");
    }
    if (iVar2 == 1) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_input: active pcb->state != LISTEN");
    }
    if ((((*(u_short *)((longlong)piVar15 + 0x42) == *DAT_140074338) &&
         (*(u_short *)(piVar15 + 0x10) == DAT_140074338[1])) &&
        ((*piVar15 == *(int *)(DAT_140074340 + 0x18) &&
         ((piVar15[1] == *(int *)(DAT_140074340 + 0x1c) &&
          (piVar15[2] == *(int *)(DAT_140074340 + 0x20))))))) &&
       (piVar15[3] == *(int *)(DAT_140074340 + 0x24))) {
      piVar12 = *(int **)(piVar15 + 10);
      if (piVar12 == piVar15) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("tcp_input: pcb->next != pcb (before cache)");
      }
      if (piVar3 != (int *)0x0) {
        *(int **)(piVar3 + 10) = piVar12;
        *(int **)(piVar15 + 10) = tcp_active_pcbs;
        piVar12 = *(int **)(piVar15 + 10);
        tcp_active_pcbs = piVar15;
      }
      if (piVar12 == piVar15) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("tcp_input: pcb->next != pcb (after cache)");
      }
      goto LAB_14001553e;
    }
    piVar3 = piVar15;
  }
  for (; piVar12 != (int *)0x0; piVar12 = *(int **)(piVar12 + 10)) {
    if (piVar12[0xc] != 10) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_input: TIME-WAIT pcb->state == TIME-WAIT");
    }
    if ((((((*(u_short *)((longlong)piVar12 + 0x42) == *DAT_140074338) &&
           (*(u_short *)(piVar12 + 0x10) == DAT_140074338[1])) &&
          (piVar12[4] == *(int *)(DAT_140074340 + 8))) &&
         ((piVar12[5] == *(int *)(DAT_140074340 + 0xc) &&
          (piVar12[6] == *(int *)(DAT_140074340 + 0x10))))) &&
        ((piVar12[7] == *(int *)(DAT_140074340 + 0x14) &&
         ((*piVar12 == *(int *)(DAT_140074340 + 0x18) &&
          (piVar12[1] == *(int *)(DAT_140074340 + 0x1c))))))) &&
       ((piVar12[2] == *(int *)(DAT_140074340 + 0x20) &&
        (piVar12[3] == *(int *)(DAT_140074340 + 0x24))))) {
      uVar10 = (ulonglong)DAT_140074348;
      if (0 < (int)((DAT_140074348 - piVar12[0x12]) + (uint)uVar13)) {
        piVar12[0x12] = DAT_140074348 + uVar13;
      }
      if (uVar13 != 0) {
        *(byte *)(piVar12 + 0x11) = *(byte *)(piVar12 + 0x11) | 2;
        crashdump_tcp6_output(piVar12,piVar14,uVar10,(longlong)puVar17);
      }
      goto LAB_1400157e5;
    }
  }
  piVar15 = (int *)0x0;
  puVar4 = (uint *)0x0;
  for (puVar5 = tcp_listen_pcbs; puVar5 != (uint *)0x0; puVar5 = *(uint **)(puVar5 + 10)) {
    uVar1 = *puVar5;
    puVar17 = (u_short *)(ulonglong)uVar1;
    if (((((uVar1 == 0 && puVar5[1] == 0) && puVar5[2] == 0) && puVar5[3] == 0) ||
        ((((uVar1 == *(uint *)(DAT_140074340 + 0x18) &&
           (puVar5[1] == *(uint *)(DAT_140074340 + 0x1c))) &&
          (puVar5[2] == *(uint *)(DAT_140074340 + 0x20))) &&
         (puVar5[3] == *(uint *)(DAT_140074340 + 0x24))))) &&
       ((u_short)puVar5[0x10] == DAT_140074338[1])) {
      if (puVar4 != (uint *)0x0) {
        *(undefined8 *)(puVar4 + 10) = *(undefined8 *)(puVar5 + 10);
        *(uint **)(puVar5 + 10) = tcp_listen_pcbs;
        tcp_listen_pcbs = puVar5;
      }
      if ((uVar9 & 0x10) == 0) {
        if (((uVar9 & 2) != 0) &&
           (piVar12 = (int *)crashdump_ip6_tcp_alloc((byte)puVar5[0xd],piVar14,uVar10,puVar17),
           uVar10 = DAT_140074340, piVar12 != (int *)0x0)) {
          uVar11 = *(undefined8 *)(DAT_140074340 + 0x20);
          *(undefined8 *)piVar12 = *(undefined8 *)(DAT_140074340 + 0x18);
          *(undefined8 *)(piVar12 + 2) = uVar11;
          *(short *)(piVar12 + 0x10) = (short)puVar5[0x10];
          puVar6 = DAT_140074338;
          uVar11 = *(undefined8 *)(uVar10 + 0x10);
          *(undefined8 *)(piVar12 + 4) = *(undefined8 *)(uVar10 + 8);
          *(undefined8 *)(piVar12 + 6) = uVar11;
          *(u_short *)((longlong)piVar12 + 0x42) = *puVar6;
          uVar1 = DAT_140074348;
          piVar12[0xc] = 3;
          piVar12[0x12] = uVar1 + 1;
          uVar13 = puVar6[7];
          piVar12[0x20] = (uint)uVar13;
          *(ushort *)(piVar12 + 0x1d) = uVar13;
          piVar12[0x21] = uVar1 - 1;
          *(undefined8 *)(piVar12 + 0xe) = *(undefined8 *)(puVar5 + 0xe);
          *(undefined8 *)(piVar12 + 0x32) = *(undefined8 *)(puVar5 + 0x12);
          *(ushort *)(piVar12 + 8) = (ushort)puVar5[8] & 0x199;
          *(int **)(piVar12 + 10) = tcp_active_pcbs;
          tcp_active_pcbs = piVar12;
          tcp_parseopt((longlong)piVar12);
          uVar10 = 0;
          puVar17 = (u_short *)CONCAT71((int7)((ulonglong)puVar17 >> 8),0x12);
          local_res8[0] =
               ((uint)*(ushort *)(piVar12 + 0x16) << 0x10 | *(ushort *)(piVar12 + 0x16) & 0xff00) <<
               8 | 0x402;
          piVar14 = (int *)0x0;
          crashdump_ip6_tcp_enqueue((longlong)piVar12,(void *)0x0,0,0x12,'\0',local_res8,4);
LAB_1400157e5:
          crashdump_tcp6_output(piVar12,piVar14,uVar10,(longlong)puVar17);
        }
      }
      else {
        crashdump_ip6_tcp_rst
                  (DAT_14007434c + 1,DAT_140074350 + DAT_140074348,(undefined8 *)(uVar10 + 0x18),
                   (uint *)(uVar10 + 8),puVar6[1],*DAT_140074338);
      }
      goto LAB_1400156db;
    }
    puVar4 = puVar5;
  }
LAB_14001553e:
  uVar9 = ntohs(DAT_140074338[6]);
  crashdump_ip6_tcp_debug_print_flags((byte)uVar9 & 0x3f);
  if (piVar15 == (int *)0x0) {
    uVar9 = ntohs(DAT_140074338[6]);
    if ((uVar9 & 4) == 0) {
      crashdump_ip6_tcp_rst
                (DAT_14007434c,DAT_140074350 + DAT_140074348,(undefined8 *)(DAT_140074340 + 0x18),
                 (uint *)(DAT_140074340 + 8),DAT_140074338[1],*DAT_140074338);
    }
    pbuf_free(param_1);
    goto LAB_14001592b;
  }
  _DAT_140074310 = 0;
  DAT_140074328 = *(undefined2 *)(param_1 + 2);
  _DAT_140074320 = param_1[1];
  DAT_140074330 = DAT_140074338;
  DAT_140074358 = (undefined8 *)0x0;
  DAT_1400742fe = 0;
  DAT_140074318 = param_1;
  tcp_input_pcb = piVar15;
  uVar11 = tcp_process(piVar15,piVar14,uVar10,puVar17);
  tcp_input_pcb = (int *)0x0;
  if ((char)uVar11 != -3) {
    if ((DAT_1400742fe & 8) == 0) {
      if ((DAT_1400742fe & 0x10) == 0) {
        puVar16 = (undefined8 *)(ulonglong)*(ushort *)(piVar15 + 0x24);
        cVar7 = '\0';
        if ((*(ushort *)(piVar15 + 0x24) != 0) && (*(code **)(piVar15 + 0x2c) != (code *)0x0)) {
          piVar14 = piVar15;
          cVar7 = (**(code **)(piVar15 + 0x2c))(*(undefined8 *)(piVar15 + 0xe));
        }
        if (DAT_140074358 != (undefined8 *)0x0) {
          if (*(code **)(piVar15 + 0x2e) == (code *)0x0) {
            pbuf_free(DAT_140074358);
          }
          else {
            puVar17 = (u_short *)0x0;
            piVar14 = piVar15;
            puVar16 = DAT_140074358;
            cVar7 = (**(code **)(piVar15 + 0x2e))(*(undefined8 *)(piVar15 + 0xe));
          }
        }
        if (((DAT_1400742fe & 0x20) != 0) && (*(code **)(piVar15 + 0x2e) != (code *)0x0)) {
          puVar17 = (u_short *)0x0;
          puVar16 = (undefined8 *)0x0;
          piVar14 = piVar15;
          cVar7 = (**(code **)(piVar15 + 0x2e))(*(undefined8 *)(piVar15 + 0xe));
        }
        if (cVar7 == '\0') {
          crashdump_tcp6_output(piVar15,piVar14,puVar16,(longlong)puVar17);
        }
        goto LAB_1400158b6;
      }
    }
    else if (*(code **)(piVar15 + 0x36) != (code *)0x0) {
      (**(code **)(piVar15 + 0x36))(*(undefined8 *)(piVar15 + 0xe),0xfc);
    }
    crashdump_ip6_tcp_pcb_remove((longlong *)&tcp_active_pcbs,piVar15,uVar10,(longlong)puVar17);
    memp_free(3,(longlong)piVar15);
  }
LAB_1400158b6:
  if (DAT_140074318 != (undefined8 *)0x0) {
    pbuf_free(DAT_140074318);
    DAT_140074318 = (undefined8 *)0x0;
  }
LAB_14001592b:
  uVar11 = crashdump_ip6_tcp_pcbs_sane();
  if ((short)uVar11 == 0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("tcp_input: tcp_pcbs_sane()");
  }
  return;
}



===== crashdump_tcp6_output @ 14001594c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong crashdump_tcp6_output(int *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  short *psVar1;
  ushort uVar2;
  uint uVar3;
  longlong *plVar4;
  u_short *puVar5;
  longlong *plVar6;
  u_short uVar7;
  undefined2 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  longlong *in_RAX;
  undefined8 *puVar12;
  undefined8 uVar13;
  uint7 extraout_var;
  uint7 extraout_var_00;
  short sVar14;
  int iVar15;
  undefined7 uVar16;
  longlong *plVar17;
  undefined4 in_stack_ffffffffffffffcc;
  
  if (tcp_input_pcb == param_1) goto LAB_140015e23;
  uVar2 = *(ushort *)((longlong)param_1 + 0x72);
  in_RAX = (longlong *)(ulonglong)uVar2;
  plVar17 = *(longlong **)(param_1 + 0x28);
  plVar4 = *(longlong **)(param_1 + 0x26);
  uVar9 = param_1[0x20];
  if ((uint)uVar2 <= (uint)param_1[0x20]) {
    uVar9 = (uint)uVar2;
  }
  if (plVar17 != (longlong *)0x0) {
    plVar6 = (longlong *)*plVar17;
    while (plVar6 != (longlong *)0x0) {
      in_RAX = (longlong *)*plVar6;
      plVar17 = plVar6;
      plVar6 = in_RAX;
    }
  }
  if ((*(byte *)(param_1 + 0x11) & 2) == 0) {
joined_r0x000140015b4a:
    while (plVar4 != (longlong *)0x0) {
      uVar10 = *(uint *)(plVar4[4] + 4);
      in_RAX = (longlong *)(ulonglong)*(ushort *)(plVar4 + 3);
      if (uVar9 < (((uVar10 << 0x10 | uVar10 & 0xff00) << 8 | (uint)*(byte *)(plVar4[4] + 7) |
                   uVar10 >> 8 & 0xff00) - param_1[0x1b]) + (uint)*(ushort *)(plVar4 + 3)) break;
      *(longlong *)(param_1 + 0x26) = *plVar4;
      if (param_1[0xc] != 2) {
        uVar7 = ntohs(*(u_short *)(plVar4[4] + 0xc));
        uVar7 = ntohs(uVar7 | 0x10);
        *(u_short *)(plVar4[4] + 0xc) = uVar7;
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfc;
      }
      uVar10 = param_1[0x12];
      *(uint *)(plVar4[4] + 8) =
           (uVar10 << 0x10 | uVar10 & 0xff00) << 8 | uVar10 >> 8 & 0xff00 |
           (uint)*(byte *)((longlong)param_1 + 0x4b);
      if (*(ushort *)(param_1 + 0x13) < *(ushort *)(param_1 + 0x16)) {
        *(undefined2 *)(plVar4[4] + 0xe) = 0;
      }
      else {
        uVar7 = ntohs(*(ushort *)(param_1 + 0x13));
        *(u_short *)(plVar4[4] + 0xe) = uVar7;
      }
      if (((param_1[3] == 0 && param_1[2] == 0) && param_1[1] == 0) && *param_1 == 0) {
        puVar12 = crashdump_ip6_route((uint *)(param_1 + 4));
        if (puVar12 != (undefined8 *)0x0) {
          uVar13 = puVar12[0x25];
          *(undefined8 *)param_1 = puVar12[0x24];
          *(undefined8 *)(param_1 + 2) = uVar13;
          goto LAB_140015c3b;
        }
      }
      else {
LAB_140015c3b:
        *(undefined2 *)((longlong)param_1 + 0x56) = 0;
        if (param_1[0x17] == 0) {
          param_1[0x17] = _tcp_ticks;
          uVar10 = *(uint *)(plVar4[4] + 4);
          param_1[0x18] =
               (uVar10 << 0x10 | uVar10 & 0xff00) << 8 | (uint)*(byte *)(plVar4[4] + 7) |
               uVar10 >> 8 & 0xff00;
        }
        uVar16 = (undefined7)((ulonglong)param_4 >> 8);
        sVar14 = (short)plVar4[4] - *(short *)(plVar4[1] + 8);
        psVar1 = (short *)(plVar4[1] + 0x12);
        *psVar1 = *psVar1 - sVar14;
        *(short *)(plVar4[1] + 0x10) = *(short *)(plVar4[1] + 0x10) - sVar14;
        *(longlong *)(plVar4[1] + 8) = plVar4[4];
        *(undefined2 *)(plVar4[4] + 0x10) = 0;
        uVar10 = (uint)*(ushort *)((undefined8 *)plVar4[1] + 2);
        uVar8 = crashdump_ip6_inet_chksum_pseudo
                          ((undefined8 *)plVar4[1],(longlong)param_1,(u_short *)(param_1 + 4),6,
                           uVar10);
        *(undefined2 *)(plVar4[4] + 0x10) = uVar8;
        crashdump_ip6_output
                  (plVar4[1],(undefined8 *)param_1,(uint *)(param_1 + 4),
                   CONCAT71(uVar16,*(undefined1 *)((longlong)param_1 + 0x23)),
                   CONCAT44(in_stack_ffffffffffffffcc,
                            CONCAT31((int3)(uVar10 >> 8),*(undefined1 *)((longlong)param_1 + 0x22)))
                   ,6);
      }
      uVar7 = ntohs(*(u_short *)(plVar4[4] + 0xc));
      if ((uVar7 & 1) == 0) {
        uVar7 = ntohs(*(u_short *)(plVar4[4] + 0xc));
        param_4 = 0;
        if ((uVar7 & 2) != 0) goto LAB_140015d13;
      }
      else {
LAB_140015d13:
        param_4 = 1;
      }
      uVar10 = *(uint *)(plVar4[4] + 4);
      iVar15 = (uint)*(ushort *)(plVar4 + 3) +
               ((uint)*(byte *)(plVar4[4] + 7) | (uVar10 << 0x10 | uVar10 & 0xff00) << 8 |
               uVar10 >> 8 & 0xff00) + (int)param_4;
      param_1[0x1e] = iVar15;
      if (param_1[0x1f] - iVar15 < 0) {
        param_1[0x1f] = iVar15;
      }
      uVar7 = ntohs(*(u_short *)(plVar4[4] + 0xc));
      if ((uVar7 & 1) == 0) {
        uVar7 = ntohs(*(u_short *)(plVar4[4] + 0xc));
        iVar15 = 0;
        if ((uVar7 & 2) != 0) goto LAB_140015d79;
      }
      else {
LAB_140015d79:
        iVar15 = 1;
      }
      in_RAX = (longlong *)(ulonglong)((uint)*(ushort *)(plVar4 + 3) + iVar15);
      if ((uint)*(ushort *)(plVar4 + 3) + iVar15 == 0) {
        crashdump_ip6_tcp_seg_free((longlong)plVar4);
        in_RAX = (longlong *)((ulonglong)extraout_var_00 << 8);
      }
      else {
        *plVar4 = 0;
        param_4 = *(longlong *)(param_1 + 0x28);
        if (param_4 == 0) {
          *(longlong **)(param_1 + 0x28) = plVar4;
        }
        else {
          uVar10 = *(uint *)(plVar17[4] + 4);
          uVar3 = *(uint *)(plVar4[4] + 4);
          uVar11 = (uVar10 & 0xff0000 | uVar10 >> 0x10) >> 8;
          in_RAX = (longlong *)(ulonglong)uVar11;
          if ((int)(((uVar3 << 0x10 | uVar3 & 0xff00) << 8 | (uVar3 & 0xff0000 | uVar3 >> 0x10) >> 8
                    ) - ((uVar10 << 0x10 | uVar10 & 0xff00) << 8 | uVar11)) < 0) {
            *plVar4 = param_4;
            *(longlong **)(param_1 + 0x28) = plVar4;
            goto LAB_140015e13;
          }
          *plVar17 = (longlong)plVar4;
        }
        plVar17 = plVar4;
      }
LAB_140015e13:
      plVar4 = *(longlong **)(param_1 + 0x26);
    }
  }
  else {
    if (plVar4 != (longlong *)0x0) {
      uVar10 = *(uint *)(plVar4[4] + 4);
      in_RAX = (longlong *)(ulonglong)*(ushort *)(plVar4 + 3);
      if ((((uVar10 << 0x10 | uVar10 & 0xff00) << 8 | (uint)*(byte *)(plVar4[4] + 7) |
           uVar10 >> 8 & 0xff00) - param_1[0x1b]) + (uint)*(ushort *)(plVar4 + 3) <= uVar9)
      goto joined_r0x000140015b4a;
    }
    puVar12 = pbuf_alloc(1,0x14,0);
    if (puVar12 == (undefined8 *)0x0) {
      uVar13 = lwip_printk();
      return CONCAT71((int7)((ulonglong)uVar13 >> 8),0xfe);
    }
    lwip_printk();
    *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfc;
    puVar5 = (u_short *)puVar12[1];
    uVar7 = ntohs(*(u_short *)(param_1 + 0x10));
    *puVar5 = uVar7;
    uVar7 = ntohs(*(u_short *)((longlong)param_1 + 0x42));
    puVar5[1] = uVar7;
    uVar9 = param_1[0x1e];
    *(uint *)(puVar5 + 2) =
         (uVar9 << 0x10 | uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 |
         (uint)*(byte *)((longlong)param_1 + 0x7b);
    uVar9 = param_1[0x12];
    *(uint *)(puVar5 + 4) =
         (uVar9 << 0x10 | uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 |
         (uint)*(byte *)((longlong)param_1 + 0x4b);
    uVar7 = ntohs(puVar5[6]);
    uVar7 = ntohs(uVar7 & 0xffd0 | 0x10);
    puVar5[6] = uVar7;
    uVar7 = ntohs(*(u_short *)(param_1 + 0x13));
    puVar5[7] = uVar7;
    puVar5[9] = 0;
    uVar7 = ntohs(puVar5[6]);
    uVar7 = ntohs(uVar7 & 0x3f | 0x5000);
    puVar5[6] = uVar7;
    puVar5[8] = 0;
    uVar16 = (undefined7)((ulonglong)param_4 >> 8);
    uVar9 = (uint)*(ushort *)(puVar12 + 2);
    uVar7 = crashdump_ip6_inet_chksum_pseudo
                      (puVar12,(longlong)param_1,(u_short *)(param_1 + 4),6,uVar9);
    puVar5[8] = uVar7;
    crashdump_ip6_output
              ((longlong)puVar12,(undefined8 *)param_1,(uint *)(param_1 + 4),
               CONCAT71(uVar16,*(undefined1 *)((longlong)param_1 + 0x23)),
               CONCAT44(in_stack_ffffffffffffffcc,
                        CONCAT31((int3)(uVar9 >> 8),*(undefined1 *)((longlong)param_1 + 0x22))),6);
    pbuf_free(puVar12);
    in_RAX = (longlong *)((ulonglong)extraout_var << 8);
  }
LAB_140015e23:
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== crashdump_tcp6_recved @ 140015e44 =====

void crashdump_tcp6_recved(int *param_1,undefined8 param_2)

{
  ushort uVar1;
  byte bVar2;
  ulonglong uVar3;
  uint uVar4;
  ushort uVar5;
  
  uVar1 = *(ushort *)(param_1 + 0x13);
  uVar5 = 0xffff;
  uVar4 = ((uint)param_2 & 0xffff) + (uint)uVar1;
  if (uVar4 < 0x10000) {
    uVar5 = (short)param_2 + uVar1;
  }
  *(ushort *)(param_1 + 0x13) = uVar5;
  bVar2 = *(byte *)(param_1 + 0x11);
  uVar3 = CONCAT71((int7)((ulonglong)param_2 >> 8),bVar2) & 0xffffffffffffff01;
  if ((bVar2 & 3) == 0) {
    if ((char)uVar3 == '\0') {
      *(byte *)(param_1 + 0x11) = bVar2 | 1;
      return;
    }
    bVar2 = bVar2 & 0xfe;
  }
  else {
    if ((char)uVar3 == '\0') {
      return;
    }
    uVar3 = 0x7fff;
    if (uVar5 < 0x7fff) {
      return;
    }
  }
  *(byte *)(param_1 + 0x11) = bVar2 | 2;
  crashdump_tcp6_output(param_1,uVar3,(ulonglong)uVar4,(ulonglong)uVar1);
  return;
}



===== ethnd_init @ 140015ea4 =====

void ethnd_init(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = &DAT_140074360;
  lVar2 = 10;
  do {
    *(undefined4 *)(puVar1 + 4) = 0;
    *puVar1 = 0;
    *(undefined1 *)((longlong)puVar1 + 0x24) = 0;
    puVar1[5] = 0;
    puVar1 = puVar1 + 6;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



===== ethnd_output @ 140015ecc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ethnd_output(longlong param_1,uint *param_2,longlong *param_3)

{
  undefined2 *puVar1;
  u_short uVar2;
  ulonglong uVar3;
  
  uVar3 = pbuf_header((longlong)param_3,0xe);
  if ((char)uVar3 == '\0') {
    if ((char)*param_2 == -1) {
      puVar1 = (undefined2 *)param_3[1];
      uVar2 = ntohs(0x86dd);
      puVar1[6] = uVar2;
      *puVar1 = 0x3333;
      *(undefined1 *)(puVar1 + 1) = 0xff;
      *(undefined1 *)((longlong)puVar1 + 3) = *(undefined1 *)((longlong)param_2 + 0xd);
      *(undefined1 *)(puVar1 + 2) = *(undefined1 *)((longlong)param_2 + 0xe);
      *(undefined1 *)((longlong)puVar1 + 5) = *(undefined1 *)((longlong)param_2 + 0xf);
      memmove(puVar1 + 3,(void *)(param_1 + 0x31),(ulonglong)*(byte *)(param_1 + 0x30));
      uVar3 = (**(code **)(param_1 + 0x20))(param_1,param_3);
    }
    else {
      uVar3 = ethnd_query(param_1,param_2,param_3);
    }
  }
  else {
    uVar3 = CONCAT71((int7)(uVar3 >> 8),0xfe);
  }
  return uVar3;
}



===== ethnd_query @ 140015f78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ethnd_query(longlong param_1,uint *param_2,longlong *param_3)

{
  uint uVar1;
  void *_Dst;
  u_short uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  int iVar7;
  undefined1 uVar8;
  undefined1 uStack0000000000000000;
  
  uVar8 = 0xff;
  if ((char)*param_2 == -1) {
    uVar3 = CONCAT71((int7)((ulonglong)&uStack0000000000000000 >> 8),0xf8);
  }
  else {
    uVar3 = find_entry(param_2,1);
    if (-1 < (char)uVar3) {
      lVar4 = (longlong)(char)uVar3;
      iVar7 = (&DAT_140074380)[lVar4 * 0xc];
      if (iVar7 == 0) {
        iVar7 = 1;
        (&DAT_140074380)[lVar4 * 0xc] = 1;
      }
      if ((iVar7 != 1) && (iVar7 != 2)) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("arp_table[i].state == PENDING or STABLE");
      }
      if (((iVar7 != 1) && (param_3 != (longlong *)0x0)) ||
         (plVar5 = (longlong *)icmp6_send_nd_solicited_packet(param_1,param_2),
         param_3 != (longlong *)0x0)) {
        uVar1 = (&DAT_140074380)[lVar4 * 0xc];
        if (uVar1 == 2) {
          _Dst = (void *)param_3[1];
          memmove(_Dst,&DAT_140074378 + lVar4 * 0x30,(ulonglong)*(byte *)(param_1 + 0x30));
          memmove((void *)((longlong)_Dst + 6),(void *)(param_1 + 0x31),
                  (ulonglong)*(byte *)(param_1 + 0x30));
          uVar2 = ntohs(0x86dd);
          *(u_short *)((longlong)_Dst + 0xc) = uVar2;
          plVar5 = (longlong *)(**(code **)(param_1 + 0x20))(param_1,param_3);
          uVar8 = SUB81(plVar5,0);
        }
        else {
          plVar5 = (longlong *)(ulonglong)uVar1;
          if ((uVar1 == 1) &&
             (plVar6 = pbuf_take(param_3), plVar5 = plVar6, plVar6 != (longlong *)0x0)) {
            if ((&DAT_140074360)[lVar4 * 6] == 0) {
              plVar5 = (longlong *)pbuf_ref((longlong)plVar6);
              (&DAT_140074360)[lVar4 * 6] = plVar6;
            }
            uVar8 = 0;
          }
        }
      }
      uVar3 = CONCAT71((int7)((ulonglong)plVar5 >> 8),uVar8);
    }
  }
  return uVar3;
}



===== ethnd_tmr @ 1400160d0 =====

void ethnd_tmr(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  
  piVar3 = &DAT_140074380;
  lVar4 = 10;
  do {
    iVar2 = *piVar3;
    bVar1 = (char)piVar3[1] + 1;
    *(byte *)(piVar3 + 1) = bVar1;
    if (iVar2 == 2) {
      if (bVar1 < 0xf0) goto LAB_140016111;
      *piVar3 = 3;
LAB_140016116:
      if (*(undefined8 **)(piVar3 + -8) != (undefined8 *)0x0) {
        pbuf_free(*(undefined8 **)(piVar3 + -8));
        piVar3[-8] = 0;
        piVar3[-7] = 0;
      }
      *piVar3 = 0;
    }
    else {
      if ((iVar2 == 1) && (1 < bVar1)) {
        iVar2 = 3;
        *piVar3 = 3;
      }
LAB_140016111:
      if (iVar2 == 3) goto LAB_140016116;
    }
    piVar3 = piVar3 + 0xc;
    lVar4 = lVar4 + -1;
    if (lVar4 == 0) {
      return;
    }
  } while( true );
}



===== ethnd_update_entry @ 140016144 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ethnd_update_entry(longlong param_1,uint *param_2,void *param_3,byte param_4)

{
  undefined8 *puVar1;
  u_short uVar2;
  ulonglong uVar3;
  longlong lVar4;
  void *pvVar5;
  undefined8 uVar6;
  uint7 extraout_var;
  
  if ((char)*param_2 == -1) {
    uVar3 = CONCAT71((int7)((ulonglong)param_2 >> 8),0xf8);
  }
  else {
    uVar3 = find_entry(param_2,param_4);
    if (-1 < (char)uVar3) {
      lVar4 = (longlong)(char)uVar3;
      (&DAT_140074380)[lVar4 * 0xc] = 2;
      (&DAT_140074388)[lVar4 * 6] = param_1;
      pvVar5 = memmove(&DAT_140074378 + lVar4 * 0x30,param_3,(ulonglong)*(byte *)(param_1 + 0x30));
      (&DAT_140074384)[lVar4 * 0x30] = 0;
      while ((&DAT_140074360)[lVar4 * 6] != 0) {
        puVar1 = (undefined8 *)(&DAT_140074360)[lVar4 * 6];
        pvVar5 = (void *)puVar1[1];
        uVar6 = pbuf_dequeue(puVar1);
        (&DAT_140074360)[lVar4 * 6] = uVar6;
        memmove(pvVar5,param_3,(ulonglong)*(byte *)(param_1 + 0x30));
        memmove((void *)((longlong)pvVar5 + 6),(void *)(param_1 + 0x31),
                (ulonglong)*(byte *)(param_1 + 0x30));
        uVar2 = ntohs(0x86dd);
        *(u_short *)((longlong)pvVar5 + 0xc) = uVar2;
        (**(code **)(param_1 + 0x20))(param_1,puVar1);
        pbuf_free(puVar1);
        pvVar5 = (void *)((ulonglong)extraout_var << 8);
      }
      uVar3 = (ulonglong)pvVar5 & 0xffffffffffffff00;
    }
  }
  return uVar3;
}



===== find_entry @ 140016250 =====

ulonglong find_entry(uint *param_1,byte param_2)

{
  byte bVar1;
  uint uVar2;
  undefined8 uVar3;
  byte bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  
  bVar14 = 10;
  bVar8 = 0;
  bVar9 = 0;
  bVar15 = 0;
  bVar12 = 10;
  bVar10 = 10;
  bVar13 = 10;
  bVar11 = 0;
  do {
    uVar6 = (ulonglong)bVar11;
    if ((bVar10 == 10) && (uVar5 = uVar6 * 6, (&DAT_140074380)[uVar6 * 0xc] == 0)) {
      bVar10 = bVar11;
    }
    else {
      uVar2 = (&DAT_140074380)[uVar6 * 0xc];
      uVar5 = (ulonglong)uVar2;
      if (uVar2 == 1) {
        if (((param_1 != (uint *)0x0) &&
            (uVar5 = (ulonglong)*(uint *)(&DAT_140074368 + uVar6 * 0x30),
            *param_1 == *(uint *)(&DAT_140074368 + uVar6 * 0x30))) &&
           ((uVar2 = *(uint *)(uVar6 * 0x30 + 0x14007436c), uVar5 = (ulonglong)uVar2,
            param_1[1] == uVar2 &&
            ((uVar2 = *(uint *)(uVar6 * 0x30 + 0x140074370), uVar5 = (ulonglong)uVar2,
             param_1[2] == uVar2 &&
             (uVar2 = *(uint *)(uVar6 * 0x30 + 0x140074374), uVar5 = (ulonglong)uVar2,
             param_1[3] == uVar2)))))) {
LAB_1400163b5:
          return CONCAT71((int7)(uVar5 >> 8),bVar11);
        }
        bVar1 = (&DAT_140074384)[uVar6 * 0x30];
        if ((&DAT_140074360)[uVar6 * 6] == 0) {
          if (bVar8 <= bVar1) {
            bVar14 = bVar11;
            bVar8 = bVar1;
          }
        }
        else {
          bVar4 = bVar11;
          if (bVar1 < bVar15) {
            bVar4 = bVar13;
          }
          bVar13 = bVar4;
          uVar5 = 0;
          if (bVar1 < bVar15) {
            bVar1 = bVar15;
          }
          bVar15 = bVar1;
        }
      }
      else if (uVar2 == 2) {
        if ((((param_1 != (uint *)0x0) &&
             (lVar7 = uVar6 * 0x30, *param_1 == *(uint *)(&DAT_140074368 + lVar7))) &&
            (param_1[1] == *(uint *)(lVar7 + 0x14007436c))) &&
           ((param_1[2] == *(uint *)(lVar7 + 0x140074370) &&
            (uVar5 = (ulonglong)*(uint *)(lVar7 + 0x140074374),
            param_1[3] == *(uint *)(lVar7 + 0x140074374))))) goto LAB_1400163b5;
        uVar5 = uVar6 * 6;
        if (bVar9 <= (byte)(&DAT_140074384)[uVar6 * 0x30]) {
          bVar12 = bVar11;
          bVar9 = (&DAT_140074384)[uVar6 * 0x30];
        }
      }
    }
    bVar11 = bVar11 + 1;
  } while (bVar11 < 10);
  if (bVar10 == 10) {
    if ((param_2 & 1) == 0) goto LAB_140016394;
  }
  else if ((char)bVar10 < '\n') goto LAB_140016416;
  if ((char)bVar12 < '\n') {
    bVar10 = bVar12;
    if ((&DAT_140074360)[(ulonglong)bVar12 * 6] != 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("arp_table[i].p == NULL");
    }
  }
  else if ((char)bVar14 < '\n') {
    bVar10 = bVar14;
  }
  else {
    if ('\t' < (char)bVar13) {
LAB_140016394:
      return CONCAT71((int7)(uVar5 >> 8),0xff);
    }
    pbuf_free((undefined8 *)(&DAT_140074360)[(ulonglong)bVar13 * 6]);
    (&DAT_140074360)[(ulonglong)bVar13 * 6] = 0;
    bVar10 = bVar13;
  }
LAB_140016416:
  if (9 < bVar10) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("i < ARP_TABLE_SIZE");
  }
  uVar6 = (ulonglong)bVar10;
  (&DAT_140074380)[uVar6 * 0xc] = 0;
  if (param_1 != (uint *)0x0) {
    uVar3 = *(undefined8 *)(param_1 + 2);
    *(undefined8 *)(&DAT_140074368 + uVar6 * 0x30) = *(undefined8 *)param_1;
    *(undefined8 *)(uVar6 * 0x30 + 0x140074370) = uVar3;
  }
  (&DAT_140074384)[uVar6 * 0x30] = 0;
  return (ulonglong)bVar10;
}



===== icmp6_send_nd_solicited_packet @ 140016458 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void icmp6_send_nd_solicited_packet(longlong param_1,uint *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 auStackY_68 [32];
  u_short local_38 [4];
  undefined5 uStack_30;
  undefined3 uStack_2b;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_68;
  puVar4 = pbuf_alloc(1,0x20,0);
  if (puVar4 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)puVar4[1];
    *puVar1 = 0x87;
    uVar2 = *(undefined8 *)(param_2 + 2);
    puVar1[1] = *(undefined8 *)param_2;
    puVar1[2] = uVar2;
    *(undefined2 *)(puVar1 + 3) = 0x101;
    *(undefined4 *)((longlong)puVar1 + 0x1a) = *(undefined4 *)(param_1 + 0x31);
    *(undefined2 *)((longlong)puVar1 + 0x1e) = *(undefined2 *)(param_1 + 0x35);
    puVar5 = ip_find_src_addr(param_2);
    local_38[0] = 0x2ff;
    local_38[1] = 0;
    local_38[2] = 0;
    local_38[3] = 0;
    _uStack_30 = CONCAT35(*(undefined3 *)((longlong)param_2 + 0xd),0xff01000000);
    uVar3 = crashdump_ip6_inet_chksum_pseudo
                      (puVar4,(longlong)puVar5,local_38,0x3a,(uint)*(ushort *)(puVar4 + 2));
    *(undefined2 *)((longlong)puVar1 + 2) = uVar3;
    crashdump_ip6_output_if((longlong)puVar4,puVar5,(int *)local_38,0xff,0x3a,param_1);
    pbuf_free(puVar4);
  }
  return;
}



===== icmp_handle_echo_request @ 140016564 =====

bool icmp_handle_echo_request(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  u_short *puVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined8 uVar7;
  
  puVar3 = (undefined4 *)param_1[1];
  pbuf_header((longlong)param_1,0x28);
  lVar4 = param_1[1];
  *puVar3 = 0x81;
  puVar1 = (undefined8 *)(lVar4 + 8);
  puVar2 = (u_short *)(lVar4 + 0x18);
  uVar7 = *(undefined8 *)puVar2;
  uVar5 = *(undefined8 *)(lVar4 + 0x20);
  *(undefined8 *)puVar2 = *puVar1;
  *(undefined8 *)(lVar4 + 0x20) = *(undefined8 *)(lVar4 + 0x10);
  *puVar1 = uVar7;
  *(undefined8 *)(lVar4 + 0x10) = uVar5;
  pbuf_header((longlong)param_1,-0x28);
  uVar6 = crashdump_ip6_inet_chksum_pseudo
                    (param_1,(longlong)puVar1,puVar2,0x3a,(uint)*(ushort *)(param_1 + 2));
  *(undefined2 *)((longlong)puVar3 + 2) = uVar6;
  uVar7 = crashdump_ip6_output_if
                    ((longlong)param_1,puVar1,(int *)puVar2,*(undefined1 *)(param_2 + 0x11c),0x3a,
                     param_2);
  return (char)uVar7 == -2;
}



===== icmp_handle_nd_sol @ 14001661c =====

undefined8 icmp_handle_nd_sol(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  longlong *plVar7;
  
  lVar1 = *(longlong *)(param_1 + 8);
  pbuf_header(param_1,0x28);
  lVar2 = *(longlong *)(param_1 + 8);
  puVar5 = pbuf_alloc(1,0x20,0);
  if (puVar5 != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)puVar5[1];
    plVar7 = (longlong *)(lVar1 + 8);
    uVar6 = ip_is_our_addr(param_2,plVar7);
    if ((int)uVar6 != 0) {
      *puVar3 = 0x88;
      *(undefined1 *)((longlong)puVar3 + 4) = 0x60;
      uVar6 = *(undefined8 *)(lVar1 + 0x10);
      puVar3[1] = *plVar7;
      puVar3[2] = uVar6;
      *(undefined2 *)(puVar3 + 3) = 0x102;
      *(undefined4 *)((longlong)puVar3 + 0x1a) = *(undefined4 *)(param_2 + 0x31);
      *(undefined2 *)((longlong)puVar3 + 0x1e) = *(undefined2 *)(param_2 + 0x35);
      uVar4 = crashdump_ip6_inet_chksum_pseudo
                        (puVar5,(longlong)plVar7,(u_short *)(lVar2 + 8),0x3a,
                         (uint)*(ushort *)(puVar5 + 2));
      *(undefined2 *)((longlong)puVar3 + 2) = uVar4;
      crashdump_ip6_output_if((longlong)puVar5,plVar7,(int *)(lVar2 + 8),0xff,0x3a,param_2);
    }
    pbuf_free(puVar5);
  }
  return 1;
}



===== ip_addr_netcmp @ 14001670c =====

ulonglong ip_addr_netcmp(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar1 = *param_2 & *param_3;
  uVar2 = (ulonglong)uVar1;
  if ((((*param_1 & *param_3) == uVar1) &&
      (uVar1 = param_2[1] & param_3[1], uVar2 = (ulonglong)uVar1, (param_1[1] & param_3[1]) == uVar1
      )) && (uVar1 = param_2[2] & param_3[2], uVar2 = (ulonglong)uVar1,
            (param_1[2] & param_3[2]) == uVar1)) {
    uVar1 = param_2[3] & param_3[3];
    uVar2 = (ulonglong)uVar1;
    if ((param_1[3] & param_3[3]) == uVar1) {
      return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
    }
  }
  return uVar2 & 0xffffffffffffff00;
}



===== ip_find_onlink_addr @ 140016774 =====

undefined8 * ip_find_onlink_addr(longlong param_1,void *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0xc0);
  while( true ) {
    if (puVar2 == (undefined8 *)0x0) {
      return (undefined8 *)0x0;
    }
    iVar1 = memcmp(puVar2 + 1,param_2,(ulonglong)*(byte *)(puVar2 + 3));
    if (iVar1 == 0) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return puVar2 + 1;
}



===== ip_find_src_addr @ 1400167bc =====

undefined8 * ip_find_src_addr(uint *param_1)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  
  puVar3 = (undefined8 *)0x0;
  puVar2 = crashdump_ip6_route(param_1);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = ip_find_onlink_addr((longlong)puVar2,param_1);
    if (puVar3 == (undefined8 *)0x0) {
      piVar1 = (int *)(puVar2 + 0x19);
      if ((((*piVar1 == 0) && (*(int *)((longlong)puVar2 + 0xcc) == 0)) &&
          (*(int *)(puVar2 + 0x1a) == 0)) && (*(int *)((longlong)puVar2 + 0xd4) == 0)) {
        puVar3 = puVar2 + 0x1b;
      }
      else if (((char)*piVar1 == -2) && ((*(byte *)((longlong)puVar2 + 0xc9) & 0xc0) == 0x80)) {
        puVar4 = (undefined8 *)0x0;
        iVar7 = -1;
        for (puVar3 = (undefined8 *)puVar2[0x18]; puVar3 != (undefined8 *)0x0;
            puVar3 = (undefined8 *)*puVar3) {
          if ((*(char *)(puVar3 + 1) != -2) || ((*(byte *)((longlong)puVar3 + 9) & 0xc0) != 0x80)) {
            iVar5 = 0;
            puVar6 = param_1;
            do {
              if (*(char *)((longlong)puVar3 + (8 - (longlong)param_1) + (longlong)puVar6) !=
                  (char)*puVar6) break;
              puVar6 = (uint *)((longlong)puVar6 + 1);
              iVar5 = iVar5 + 1;
            } while ((longlong)puVar6 - (longlong)param_1 < 0x10);
            if (iVar7 < iVar5) {
              puVar4 = puVar3;
              iVar7 = iVar5;
            }
          }
        }
        puVar3 = (undefined8 *)(-(ulonglong)(puVar4 != (undefined8 *)0x0) & (ulonglong)(puVar4 + 1))
        ;
      }
      else {
        puVar3 = ip_find_onlink_addr((longlong)puVar2,piVar1);
      }
    }
  }
  return puVar3;
}



===== ip_is_our_addr @ 1400168c0 =====

undefined8 ip_is_our_addr(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xc0);
  while( true ) {
    if (puVar1 == (undefined8 *)0x0) {
      return 0;
    }
    if ((puVar1[1] == *param_2) && (puVar1[2] == param_2[1])) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return 1;
}



===== netif6_add @ 1400168f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 *
netif6_add(undefined8 *param_1,undefined8 param_2,undefined *param_3,undefined8 param_4,
          undefined8 param_5)

{
  char cVar1;
  
  *(undefined4 *)(param_1 + 0x1d) = 0;
  *(char *)((longlong)param_1 + 0x3d) = (char)DAT_1400742fc;
  DAT_1400742fc = DAT_1400742fc + 1;
  param_1[2] = param_5;
  *(undefined1 *)((longlong)param_1 + 0x3a) = 0x20;
  param_1[5] = param_2;
  cVar1 = (*(code *)param_3)();
  if (cVar1 == '\0') {
    *param_1 = DAT_140074300;
    param_1[1] = param_4;
    DAT_140074300 = param_1;
  }
  else {
    param_1 = (undefined8 *)0x0;
  }
  return param_1;
}



===== netif6_add_addr @ 140016960 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong netif6_add_addr(longlong param_1,longlong *param_2,byte param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 auStack_38 [32];
  undefined2 local_18;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  lVar2 = 0;
  do {
    if (((*(char *)(lVar2 + 0x58 + param_1) != '\0') &&
        (*(longlong *)(lVar2 + 0x48 + param_1) == *param_2)) &&
       (uVar1 = *(ulonglong *)(lVar2 + 0x50 + param_1), uVar1 == param_2[1])) goto LAB_140016a1a;
    lVar2 = lVar2 + 0x20;
  } while (lVar2 < 0x80);
  lVar2 = 0;
  do {
    puVar3 = (undefined8 *)(param_1 + 0x40 + lVar2);
    if (*(char *)(puVar3 + 3) == '\0') goto LAB_1400169cb;
    lVar2 = lVar2 + 0x20;
  } while (lVar2 < 0x80);
  if (*(char *)(puVar3 + 3) == '\0') {
LAB_1400169cb:
    *(byte *)(puVar3 + 3) = param_3 >> 3;
    lVar2 = param_2[1];
    puVar3[1] = *param_2;
    puVar3[2] = lVar2;
    *puVar3 = *(undefined8 *)(param_1 + 0xc0);
    *(undefined8 **)(param_1 + 0xc0) = puVar3;
    local_15 = *(undefined1 *)((longlong)param_2 + 0xd);
    local_14 = *(undefined1 *)((longlong)param_2 + 0xe);
    local_13 = *(undefined1 *)((longlong)param_2 + 0xf);
    local_18 = 0x3333;
    local_16 = 0xff;
    uVar1 = netif6_add_l2_mc_addr(param_1,(int *)&local_18);
LAB_140016a1a:
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar1 = CONCAT71((int7)((ulonglong)lVar2 >> 8),0xf9);
  }
  return uVar1;
}



===== netif6_add_l2_mc_addr @ 140016a30 =====

undefined8 netif6_add_l2_mc_addr(longlong param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ulonglong in_RAX;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = *(int *)(param_1 + 0xe8);
  if (0 < iVar2) {
    do {
      uVar3 = *(uint *)(param_1 + 0xec + (longlong)iVar4 * 6);
      in_RAX = (ulonglong)uVar3;
      if ((uVar3 == *param_2) &&
         (uVar1 = *(ushort *)(param_1 + 0xf0 + (longlong)iVar4 * 6), in_RAX = (ulonglong)uVar1,
         uVar1 == *(ushort *)(param_2 + 1))) goto LAB_140016a95;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  if (7 < iVar2) {
    return CONCAT71((int7)(in_RAX >> 8),0xff);
  }
  *(int *)(param_1 + 0xec + (longlong)iVar2 * 6) = *param_2;
  in_RAX = (ulonglong)*(ushort *)(param_2 + 1);
  *(ushort *)(param_1 + 0xf0 + (longlong)iVar2 * 6) = *(ushort *)(param_2 + 1);
  *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + 1;
LAB_140016a95:
  return in_RAX & 0xffffffffffffff00;
}



===== netif6_set_up @ 140016a98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void netif6_set_up(longlong param_1)

{
  int iVar1;
  undefined1 auStack_38 [32];
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  *(undefined1 *)(param_1 + 0xd8) = 0xfe;
  *(byte *)(param_1 + 0xe0) = *(byte *)(param_1 + 0x31) | 2;
  *(undefined1 *)(param_1 + 0xe1) = *(undefined1 *)(param_1 + 0x32);
  *(undefined1 *)(param_1 + 0xe2) = *(undefined1 *)(param_1 + 0x33);
  *(undefined1 *)(param_1 + 0xe5) = *(undefined1 *)(param_1 + 0x34);
  *(undefined1 *)(param_1 + 0xe6) = *(undefined1 *)(param_1 + 0x35);
  *(undefined1 *)(param_1 + 0xe7) = *(undefined1 *)(param_1 + 0x36);
  *(undefined1 *)(param_1 + 0xd9) = 0x80;
  *(undefined2 *)(param_1 + 0xe3) = 0xfeff;
  netif6_add_addr(param_1,(longlong *)(param_1 + 0xd8),0x40);
  iVar1 = 0;
  do {
    local_18 = 0x3333;
    local_14 = 0;
    if (iVar1 == 0) {
      local_13 = 1;
    }
    else if (iVar1 == 1) {
      local_13 = 3;
    }
    else if (iVar1 == 2) {
      local_14 = *(undefined1 *)(param_1 + 0x35);
      local_13 = *(undefined1 *)(param_1 + 0x36);
      local_18 = CONCAT13(*(undefined1 *)(param_1 + 0x34),0xff3333);
    }
    netif6_add_l2_mc_addr(param_1,&local_18);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  *(undefined1 *)(param_1 + 0x11c) = 0x80;
  (**(code **)(param_1 + 8))(param_1);
  *(byte *)(param_1 + 0x3a) = *(byte *)(param_1 + 0x3a) | 1;
  return;
}



===== stack_ipv6_bringup @ 140016ba0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 stack_ipv6_bringup(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined2 *puVar8;
  int iVar9;
  
  puVar1 = (undefined8 *)(param_1 + 0x138);
  iVar6 = 0;
  mem_init();
  memp_init();
  pbuf_init();
  tcp_listen_pcbs = 0;
  tcp_active_pcbs = 0;
  tcp_tw_pcbs = 0;
  _tcp_tmp_pcb = 0;
  _tcp_ticks = 0;
  DAT_140074308 = (undefined8 *)0x0;
  DAT_140074300 = 0;
  DAT_1400742fa = 0;
  puVar7 = netif6_add(puVar1,*l2_driver_intf,(undefined *)l2_driver_intf[10],l2_driver_intf[0xb],
                      crashdump_ip6_input);
  if (puVar7 != (undefined8 *)0x0) {
    lVar2 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    if ((*(int *)(lVar2 + 0x458) != 0) ||
       ((((*(int *)(lVar2 + 0x45c) != 0 || (*(int *)(lVar2 + 0x460) != 0)) ||
         (*(int *)(lVar2 + 0x464) != 0)) &&
        (((*(int *)(lVar2 + 0x45c) != 0 || (*(int *)(lVar2 + 0x460) != 0)) ||
         (*(int *)(lVar2 + 0x464) != 1)))))) {
      netif6_add_addr((longlong)puVar1,(longlong *)(lVar2 + 0x458),0x40);
    }
    lVar2 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    uVar3 = *(undefined4 *)(lVar2 + 0x47c);
    uVar4 = *(undefined4 *)(lVar2 + 0x480);
    uVar5 = *(undefined4 *)(lVar2 + 0x484);
    DAT_140074308 = puVar1;
    *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(lVar2 + 0x478);
    *(undefined4 *)(param_1 + 0x204) = uVar3;
    *(undefined4 *)(param_1 + 0x208) = uVar4;
    *(undefined4 *)(param_1 + 0x20c) = uVar5;
    *(undefined2 *)(param_1 + 0x170) = 0x5dc;
    *(undefined1 *)(param_1 + 0x172) = 2;
    *(undefined1 *)(param_1 + 0x168) = 6;
    (*(code *)l2_driver_intf[6])(*l2_driver_intf,param_1 + 0x169);
    lVar2 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    *(undefined4 *)(lVar2 + 0x12) = *(undefined4 *)(param_1 + 0x169);
    *(undefined2 *)(lVar2 + 0x16) = *(undefined2 *)(param_1 + 0x16d);
    ethnd_init();
    puVar8 = iscsiAddTimer(5000,ethnd_tmr);
    *(undefined2 **)(param_1 + 0x128) = puVar8;
    puVar8 = iscsiAddTimer(0xfa,crashdump_ip6_tcp_tmr);
    *(undefined2 **)(param_1 + 0x130) = puVar8;
    iVar9 = 0;
    do {
      if (iVar9 == 60000) break;
      mm_delay(1000);
      iVar6 = (*(code *)l2_driver_intf[9])(*l2_driver_intf);
      iVar9 = iVar9 + 1;
    } while (iVar6 != 1);
    if (iVar6 == 1) {
      netif6_set_up((longlong)puVar1);
      return 0;
    }
  }
  return 0xffffffff;
}



===== stack_ipv6_close_connection @ 140016dc0 =====

char stack_ipv6_close_connection
               (int *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined1 uVar6;
  undefined7 uVar7;
  
  uVar6 = (undefined1)param_4;
  uVar7 = (undefined7)((ulonglong)param_4 >> 8);
  iVar3 = param_1[0xc];
  if (iVar3 == 0) {
    cVar1 = '\0';
    memp_free(3,(longlong)param_1);
    piVar5 = (int *)0x0;
    piVar4 = param_1;
LAB_1400151d7:
    if ((piVar5 != (int *)0x0) && (cVar1 == '\0')) {
      uVar2 = crashdump_tcp6_output(piVar5,piVar4,param_3,CONCAT71(uVar7,uVar6));
      cVar1 = (char)uVar2;
    }
  }
  else {
    if (iVar3 == 1) {
      crashdump_ip6_tcp_pcb_remove(&tcp_listen_pcbs,param_1,param_3,param_4);
      iVar3 = 4;
    }
    else {
      if (iVar3 != 2) {
        piVar5 = param_1;
        if ((iVar3 == 3) || (iVar3 == 4)) {
          param_3 = 0;
          uVar6 = 1;
          piVar4 = (int *)0x0;
          uVar2 = crashdump_ip6_tcp_enqueue((longlong)param_1,(void *)0x0,0,1,'\x01',(void *)0x0,0);
          cVar1 = (char)uVar2;
          if (cVar1 == '\0') {
            param_1[0xc] = 5;
          }
        }
        else {
          if (iVar3 != 7) {
            return '\0';
          }
          param_3 = 0;
          uVar6 = 1;
          piVar4 = (int *)0x0;
          uVar2 = crashdump_ip6_tcp_enqueue((longlong)param_1,(void *)0x0,0,1,'\x01',(void *)0x0,0);
          cVar1 = (char)uVar2;
          if (cVar1 == '\0') {
            param_1[0xc] = 9;
          }
        }
        goto LAB_1400151d7;
      }
      crashdump_ip6_tcp_pcb_remove(&tcp_active_pcbs,param_1,param_3,param_4);
      iVar3 = 3;
    }
    cVar1 = '\0';
    memp_free(iVar3,(longlong)param_1);
  }
  return cVar1;
}



===== stack_ipv6_flush_tcp_data @ 140016dd0 =====

int stack_ipv6_flush_tcp_data(int *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  undefined8 uVar1;
  
  uVar1 = crashdump_tcp6_output(param_1,param_2,param_3,param_4);
  return -(uint)((char)uVar1 != '\0');
}



===== stack_ipv6_init @ 140016de4 =====

void stack_ipv6_init(undefined8 *param_1)

{
  *param_1 = stack_ipv6_bringup;
  param_1[1] = stack_ipv6_set_addr;
  param_1[2] = stack_ipv6_rx_packet;
  param_1[3] = stack_ipv6_setup_connection;
  param_1[4] = stack_ipv6_close_connection;
  param_1[5] = stack_ipv6_write_tcp_data;
  param_1[6] = stack_ipv6_flush_tcp_data;
  return;
}



===== stack_ipv6_rx_packet @ 140016e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void stack_ipv6_rx_packet(longlong param_1,longlong param_2,ushort param_3)

{
  ushort *puVar1;
  u_short uVar2;
  longlong *plVar3;
  int iVar4;
  longlong *plVar5;
  
  uVar2 = ntohs(*(u_short *)(param_2 + 0xc));
  if (uVar2 == 0x86dd) {
    plVar3 = pbuf_alloc(3,param_3,3);
    if (plVar3 != (longlong *)0x0) {
      iVar4 = 0;
      plVar5 = plVar3;
      do {
        memmove((void *)plVar5[1],(void *)(iVar4 + param_2),
                (ulonglong)*(ushort *)((longlong)plVar5 + 0x12));
        puVar1 = (ushort *)((longlong)plVar5 + 0x12);
        plVar5 = (longlong *)*plVar5;
        iVar4 = iVar4 + (uint)*puVar1;
      } while (plVar5 != (longlong *)0x0);
      *(ushort *)(plVar3 + 2) = param_3;
      pbuf_header((longlong)plVar3,-0xe);
      (**(code **)(param_1 + 0x10))(plVar3,param_1);
    }
  }
  return;
}



===== stack_ipv6_rx_tcp_data @ 140016ef0 =====

undefined1 *
stack_ipv6_rx_tcp_data(undefined8 param_1,int *param_2,longlong *param_3,undefined8 param_4)

{
  uint7 extraout_var;
  longlong *plVar1;
  ushort uVar2;
  longlong *plVar3;
  
  if (param_3 != (longlong *)0x0) {
    uVar2 = 0;
    plVar1 = param_3;
    plVar3 = param_3;
    do {
      uVar2 = uVar2 + *(ushort *)((longlong)plVar1 + 0x12);
      iscsiSessionServiceRxIndication
                ((char *)plVar1[1],*(ushort *)((longlong)plVar1 + 0x12),plVar3,param_4);
      plVar1 = (longlong *)*plVar1;
    } while (plVar1 != (longlong *)0x0);
    crashdump_tcp6_recved(param_2,(ulonglong)uVar2);
    pbuf_free(param_3);
    register0x00000020 = (BADSPACEBASE *)((ulonglong)extraout_var << 8);
  }
  return (undefined1 *)register0x00000020;
}



===== stack_ipv6_set_addr @ 140016f70 =====

void stack_ipv6_set_addr(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  
  netif6_add_addr(param_1 + 0x138,param_2,0x40);
  uVar1 = param_4[1];
  *(undefined8 *)(param_1 + 0x200) = *param_4;
  *(undefined8 *)(param_1 + 0x208) = uVar1;
  return;
}



===== stack_ipv6_setup_connection @ 140016fb0 =====

int * stack_ipv6_setup_connection
                (uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  
  piVar1 = (int *)crashdump_ip6_tcp_alloc(0x40,param_2,param_3,param_4);
  *(code **)(piVar1 + 0x2e) = stack_ipv6_rx_tcp_data;
  *(code **)(piVar1 + 0x2c) = CrashDumpIsr;
  *(undefined8 *)(piVar1 + 0xe) = param_3;
  crashdump_ip6_tcp_connect(piVar1,param_1,(short)param_2,stack_ipv4_connected_callback);
  return piVar1;
}



===== stack_ipv6_write_tcp_data @ 140017030 =====

undefined8 stack_ipv6_write_tcp_data(longlong param_1,void *param_2,ushort param_3,char param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = crashdump_ip6_tcp_write(param_1,param_2,param_3,param_4);
  if ((char)uVar2 == '\0') {
    return 0;
  }
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



===== tcp_new_port @ 140017048 =====

void tcp_new_port(void)

{
  longlong lVar1;
  
LAB_14001704f:
  do {
    DAT_14002d8e8 = DAT_14002d8e8 + 1;
    if (0x7fff < DAT_14002d8e8) {
      DAT_14002d8e8 = 0x1000;
    }
    for (lVar1 = tcp_active_pcbs; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x28)) {
      if (*(ushort *)(lVar1 + 0x40) == DAT_14002d8e8) goto LAB_14001704f;
    }
    for (lVar1 = tcp_tw_pcbs; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x28)) {
      if (*(ushort *)(lVar1 + 0x40) == DAT_14002d8e8) goto LAB_14001704f;
    }
    lVar1 = tcp_listen_pcbs;
    while( true ) {
      if (lVar1 == 0) {
        return;
      }
      if (*(ushort *)(lVar1 + 0x40) == DAT_14002d8e8) break;
      lVar1 = *(longlong *)(lVar1 + 0x28);
    }
  } while( true );
}



===== tcp_parseopt @ 1400170b8 =====

void tcp_parseopt(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  u_short uVar3;
  ushort uVar4;
  byte bVar5;
  ulonglong uVar6;
  
  lVar1 = DAT_140074338;
  uVar3 = ntohs(*(u_short *)(DAT_140074338 + 0xc));
  if (0x5000 < (uVar3 & 0xf000)) {
    uVar6 = 0;
    uVar3 = ntohs(*(u_short *)(DAT_140074338 + 0xc));
    if (0 < (int)((uVar3 >> 10 & 0xfffffffc) - 0x14)) {
      do {
        cVar2 = *(char *)(uVar6 + 0x14 + lVar1);
        if (cVar2 == '\0') {
          return;
        }
        if (cVar2 == '\x01') {
          cVar2 = '\x01';
        }
        else {
          if ((cVar2 == '\x02') && (*(char *)(uVar6 + 0x15 + lVar1) == '\x04')) {
            uVar4 = CONCAT11(*(undefined1 *)(uVar6 + 0x16 + lVar1),
                             *(undefined1 *)(uVar6 + 0x17 + lVar1));
            if (0x5b4 < uVar4) {
              uVar4 = 0x5b4;
            }
            *(ushort *)(param_1 + 0x58) = uVar4;
            return;
          }
          cVar2 = *(char *)(uVar6 + 0x15 + lVar1);
          if (cVar2 == '\0') {
            return;
          }
        }
        bVar5 = (char)uVar6 + cVar2;
        uVar6 = (ulonglong)bVar5;
        uVar3 = ntohs(*(u_short *)(DAT_140074338 + 0xc));
      } while ((int)(uint)bVar5 < (int)((uVar3 >> 10 & 0xfffffffc) - 0x14));
    }
  }
  return;
}



===== tcp_process @ 1400171a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong tcp_process(int *param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  int *in_RAX;
  ulonglong uVar9;
  uint7 extraout_var;
  uint7 extraout_var_00;
  uint7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 extraout_var_03;
  undefined8 uVar10;
  int *piVar11;
  ulonglong uVar12;
  undefined7 uVar13;
  
  uVar4 = _tcp_ticks;
  bVar1 = DAT_1400742fb;
  uVar13 = (undefined7)((ulonglong)param_4 >> 8);
  uVar9 = CONCAT71(uVar13,DAT_1400742fb);
  if ((DAT_1400742fb & 4) == 0) {
    in_RAX = (int *)(ulonglong)_tcp_ticks;
    param_1[0x14] = _tcp_ticks;
    *(undefined1 *)(param_1 + 0x39) = 0;
    uVar7 = DAT_14007434c;
    uVar6 = DAT_140074348;
    iVar3 = param_1[0xc];
    if (iVar3 == 2) {
      in_RAX = (int *)((ulonglong)CONCAT31((int3)(uVar4 >> 8),bVar1) & 0xffffffffffffff12);
      if ((char)in_RAX == '\x12') {
        puVar5 = *(undefined8 **)(param_1 + 0x28);
        uVar4 = *(uint *)(puVar5[4] + 4);
        in_RAX = (int *)0x0;
        if (DAT_14007434c ==
            ((uVar4 << 0x10 | uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 |
            (uint)*(byte *)(puVar5[4] + 7)) + 1) {
          uVar12 = (ulonglong)DAT_140074348;
          *(short *)((longlong)param_1 + 0x92) = *(short *)((longlong)param_1 + 0x92) + 1;
          param_1[0x1b] = uVar7;
          param_1[0x12] = uVar6 + 1;
          uVar2 = DAT_140074338[7];
          piVar11 = (int *)(ulonglong)uVar2;
          *(char *)(param_1 + 0x25) = (char)param_1[0x25] + -1;
          param_1[0x21] = uVar6 - 1;
          *(short *)((longlong)param_1 + 0x72) = (short)param_1[0x16];
          param_1[0x20] = (uint)uVar2;
          param_1[0xc] = 4;
          *(undefined8 *)(param_1 + 0x28) = *puVar5;
          crashdump_ip6_tcp_seg_free((longlong)puVar5);
          tcp_parseopt((longlong)param_1);
          uVar10 = 0;
          if (*(code **)(param_1 + 0x30) != (code *)0x0) {
            uVar12 = 0;
            piVar11 = param_1;
            uVar10 = (**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0xe));
          }
          bVar1 = *(byte *)(param_1 + 0x11);
          if ((bVar1 & 1) == 0) {
            in_RAX = (int *)CONCAT71((int7)((ulonglong)uVar10 >> 8),bVar1);
            *(byte *)(param_1 + 0x11) = bVar1 | 1;
          }
          else {
            *(byte *)(param_1 + 0x11) = bVar1 & 0xfe | 2;
            in_RAX = (int *)crashdump_tcp6_output(param_1,piVar11,uVar12,uVar9);
          }
          goto LAB_14001766d;
        }
      }
      if ((bVar1 & 0x10) != 0) {
LAB_140017632:
        in_RAX = (int *)crashdump_ip6_tcp_rst
                                  (DAT_14007434c,DAT_140074350 + DAT_140074348,
                                   (undefined8 *)(DAT_140074340 + 0x18),(uint *)(DAT_140074340 + 8),
                                   DAT_140074338[1],*DAT_140074338);
      }
    }
    else if (iVar3 == 3) {
      uVar9 = CONCAT71(uVar13,bVar1) & 0xffffffffffffff14;
      if ((char)uVar9 == '\x10') {
        if (((int)(DAT_14007434c - param_1[0x1b]) < 1) || (0 < (int)(DAT_14007434c - param_1[0x1e]))
           ) goto LAB_140017632;
        param_1[0xc] = 4;
        if (*(code **)(param_1 + 0x32) == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("pcb->accept != NULL");
        }
        uVar12 = 0;
        piVar11 = param_1;
        cVar8 = (**(code **)(param_1 + 0x32))(*(undefined8 *)(param_1 + 0xe));
        if (cVar8 != '\0') {
          uVar10 = crashdump_ip6_tcp_abort(param_1,piVar11,uVar12,uVar9);
          return CONCAT71((int7)((ulonglong)uVar10 >> 8),0xfd);
        }
        tcp_receive(param_1,piVar11,uVar12,uVar9);
        in_RAX = (int *)(ulonglong)*(ushort *)(param_1 + 0x16);
        *(ushort *)((longlong)param_1 + 0x72) = *(ushort *)(param_1 + 0x16);
      }
    }
    else if (iVar3 == 4) {
LAB_140017464:
      cVar8 = tcp_receive(param_1,param_2,param_3,uVar9);
      in_RAX = (int *)CONCAT71(extraout_var_03,cVar8);
      if (((DAT_1400742fb & 1) != 0) && (cVar8 != '\0')) {
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
        in_RAX = (int *)crashdump_tcp6_output(param_1,param_2,param_3,uVar9);
        param_1[0xc] = 7;
      }
    }
    else if (iVar3 == 5) {
      tcp_receive(param_1,param_2,param_3,uVar9);
      in_RAX = (int *)CONCAT71(extraout_var_02,DAT_1400742fb);
      if ((DAT_1400742fb & 1) == 0) {
        if (((DAT_1400742fb & 0x10) != 0) &&
           (in_RAX = (int *)(ulonglong)(uint)param_1[0x1e], DAT_14007434c == param_1[0x1e])) {
          param_1[0xc] = 6;
        }
      }
      else {
        if (((DAT_1400742fb & 0x10) != 0) && (DAT_14007434c == param_1[0x1e])) {
          *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
          crashdump_tcp6_output(param_1,param_2,param_3,uVar9);
          crashdump_ip6_tcp_pcb_purge((longlong)param_1);
          piVar11 = tcp_active_pcbs;
          if (tcp_active_pcbs == param_1) goto LAB_140017350;
          while (_tcp_tmp_pcb = piVar11, piVar11 != (int *)0x0) {
            piVar11 = *(int **)(piVar11 + 10);
            if ((piVar11 != (int *)0x0) && (piVar11 == param_1)) goto LAB_140017386;
          }
          goto LAB_14001738e;
        }
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
        in_RAX = (int *)crashdump_tcp6_output(param_1,param_2,param_3,uVar9);
        param_1[0xc] = 8;
      }
    }
    else if (iVar3 == 6) {
      tcp_receive(param_1,param_2,param_3,uVar9);
      in_RAX = (int *)((ulonglong)extraout_var_01 << 8);
      if ((DAT_1400742fb & 1) != 0) {
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
        crashdump_tcp6_output(param_1,param_2,param_3,uVar9);
        crashdump_ip6_tcp_pcb_purge((longlong)param_1);
        piVar11 = tcp_active_pcbs;
        if (tcp_active_pcbs == param_1) {
LAB_140017350:
          tcp_active_pcbs = *(int **)(tcp_active_pcbs + 10);
        }
        else {
          while (_tcp_tmp_pcb = piVar11, piVar11 != (int *)0x0) {
            piVar11 = *(int **)(piVar11 + 10);
            if ((piVar11 != (int *)0x0) && (piVar11 == param_1)) goto LAB_140017386;
          }
        }
LAB_14001738e:
        param_1[10] = 0;
        param_1[0xb] = 0;
        param_1[0xc] = 10;
        *(int **)(param_1 + 10) = tcp_tw_pcbs;
        in_RAX = tcp_tw_pcbs;
        tcp_tw_pcbs = param_1;
      }
    }
    else {
      if (iVar3 == 7) goto LAB_140017464;
      if (iVar3 == 8) {
        tcp_receive(param_1,param_2,param_3,uVar9);
        in_RAX = (int *)((ulonglong)extraout_var_00 << 8);
        if (((DAT_1400742fb & 0x10) != 0) &&
           (in_RAX = (int *)(ulonglong)(uint)param_1[0x1e], DAT_14007434c == param_1[0x1e])) {
          *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
          crashdump_tcp6_output(param_1,param_2,param_3,uVar9);
          crashdump_ip6_tcp_pcb_purge((longlong)param_1);
          piVar11 = tcp_active_pcbs;
          if (tcp_active_pcbs == param_1) goto LAB_140017350;
          while (_tcp_tmp_pcb = piVar11, piVar11 != (int *)0x0) {
            piVar11 = *(int **)(piVar11 + 10);
            if ((piVar11 != (int *)0x0) && (piVar11 == param_1)) goto LAB_140017386;
          }
          goto LAB_14001738e;
        }
      }
      else if (iVar3 == 9) {
        tcp_receive(param_1,param_2,param_3,uVar9);
        in_RAX = (int *)((ulonglong)extraout_var << 8);
        if (((DAT_1400742fb & 0x10) != 0) &&
           (in_RAX = (int *)(ulonglong)(uint)param_1[0x1e], DAT_14007434c == param_1[0x1e])) {
          param_1[0xc] = 0;
          DAT_1400742fe = 0x10;
        }
      }
    }
LAB_14001766d:
    uVar9 = (ulonglong)in_RAX & 0xffffffffffffff00;
  }
  else {
    if (param_1[0xc] == 2) {
      in_RAX = (int *)(ulonglong)(uint)param_1[0x1e];
      if (DAT_14007434c != param_1[0x1e]) goto LAB_14001766d;
    }
    else {
      if (((int)(DAT_140074348 - param_1[0x12]) < 0) ||
         (in_RAX = (int *)(ulonglong)*(ushort *)(param_1 + 0x13),
         0 < (int)((DAT_140074348 - *(ushort *)(param_1 + 0x13)) - param_1[0x12])))
      goto LAB_14001766d;
      if (param_1[0xc] == 0) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("tcp_input: pcb->state != CLOSED");
      }
    }
    *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfe;
    uVar9 = CONCAT71((int7)((ulonglong)in_RAX >> 8),0xfc);
    DAT_1400742fe = 8;
  }
  return uVar9;
LAB_140017386:
  *(undefined8 *)(_tcp_tmp_pcb + 10) = *(undefined8 *)(param_1 + 10);
  goto LAB_14001738e;
}



===== tcp_receive @ 14001767c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 tcp_receive(int *param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  u_short uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  uint uVar8;
  short sVar9;
  uint uVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined1 uVar13;
  int iVar14;
  ushort uVar15;
  short sVar16;
  ushort uVar17;
  uint uVar18;
  
  uVar2 = DAT_14007434c;
  uVar18 = DAT_140074348;
  uVar13 = 0;
  if ((DAT_1400742fb & 0x10) != 0) {
    uVar10 = param_1[0x21];
    uVar8 = param_1[0x20];
    param_3 = (ulonglong)DAT_14007434c;
    iVar14 = uVar8 + uVar10;
    if ((((int)(uVar10 - DAT_140074348) < 0) ||
        ((uVar10 == DAT_140074348 && ((int)(param_1[0x22] - DAT_14007434c) < 0)))) ||
       ((param_1[0x22] == DAT_14007434c && (uVar8 < *(ushort *)(DAT_140074338 + 0xe))))) {
      uVar8 = (uint)*(ushort *)(DAT_140074338 + 0xe);
      param_1[0x20] = uVar8;
      param_1[0x21] = uVar18;
      param_1[0x22] = uVar2;
      uVar10 = uVar18;
    }
    if (param_1[0x1b] == uVar2) {
      *(undefined2 *)(param_1 + 0x24) = 0;
      if (((uVar8 + uVar10 == iVar14) &&
          (*(char *)(param_1 + 0x1c) = (char)param_1[0x1c] + '\x01', 2 < *(byte *)(param_1 + 0x1c)))
         && (*(longlong *)(param_1 + 0x28) != 0)) {
        if ((*(byte *)(param_1 + 0x11) & 4) == 0) {
          crashdump_ip6_tcp_rexmit(param_1);
          if ((uint)param_1[0x20] < (uint)*(ushort *)((longlong)param_1 + 0x72)) {
            uVar17 = (ushort)((uint)param_1[0x20] >> 1);
          }
          else {
            uVar17 = *(ushort *)((longlong)param_1 + 0x72) >> 1;
          }
          *(ushort *)(param_1 + 0x1d) = uVar17;
          uVar18 = DAT_140074348;
          param_3 = (ulonglong)DAT_14007434c;
          *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 4;
          *(ushort *)((longlong)param_1 + 0x72) = (short)param_1[0x16] * 3 + uVar17;
        }
        else {
          uVar17 = (short)param_1[0x16] + *(ushort *)((longlong)param_1 + 0x72);
          if (*(ushort *)((longlong)param_1 + 0x72) < uVar17) {
            *(ushort *)((longlong)param_1 + 0x72) = uVar17;
          }
        }
      }
    }
    else if ((0 < (int)(uVar2 - param_1[0x1b])) && ((int)(uVar2 - param_1[0x1f]) < 1)) {
      if ((*(byte *)(param_1 + 0x11) & 4) != 0) {
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfb;
        *(short *)((longlong)param_1 + 0x72) = (short)param_1[0x1d];
      }
      *(short *)(param_1 + 0x1a) =
           ((short)param_1[0x19] >> 3) + *(short *)((longlong)param_1 + 0x66);
      sVar16 = (short)uVar2 - (short)param_1[0x1b];
      *(short *)((longlong)param_1 + 0x92) = *(short *)((longlong)param_1 + 0x92) + sVar16;
      *(undefined1 *)((longlong)param_1 + 0x6a) = 0;
      *(short *)(param_1 + 0x24) = sVar16;
      *(undefined1 *)(param_1 + 0x1c) = 0;
      param_1[0x1b] = uVar2;
      if (3 < param_1[0xc]) {
        uVar17 = *(ushort *)((longlong)param_1 + 0x72);
        uVar15 = *(ushort *)(param_1 + 0x16);
        if (*(ushort *)(param_1 + 0x1d) <= uVar17) {
          uVar15 = (ushort)((int)((uint)uVar15 * (uint)uVar15) / (int)(uint)uVar17);
        }
        if (uVar17 < (ushort)(uVar15 + uVar17)) {
          *(ushort *)((longlong)param_1 + 0x72) = uVar15 + uVar17;
        }
      }
      lVar5 = *(longlong *)(param_1 + 0x28);
      if (lVar5 != 0) {
        do {
          uVar4 = ntohs(*(u_short *)(*(longlong *)(lVar5 + 0x20) + 0xc));
          if ((uVar4 & 1) == 0) {
            uVar4 = ntohs(*(u_short *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20) + 0xc));
            iVar14 = 0;
            if ((uVar4 & 2) != 0) goto LAB_14001789a;
          }
          else {
LAB_14001789a:
            iVar14 = 1;
          }
          puVar6 = *(undefined8 **)(param_1 + 0x28);
          uVar18 = *(uint *)(puVar6[4] + 4);
          if (0 < (int)(((((uVar18 & 0xff0000 | uVar18 >> 0x10) >> 8 |
                          (uVar18 << 0x10 | uVar18 & 0xff00) << 8) + (uint)*(ushort *)(puVar6 + 3))
                        - DAT_14007434c) + iVar14)) break;
          *(undefined8 *)(param_1 + 0x28) = *puVar6;
          cVar3 = pbuf_clen((undefined8 *)puVar6[1]);
          *(char *)(param_1 + 0x25) = (char)param_1[0x25] - cVar3;
          crashdump_ip6_tcp_seg_free((longlong)puVar6);
          if ((((char)param_1[0x25] != '\0') && (*(longlong *)(param_1 + 0x28) == 0)) &&
             (*(longlong *)(param_1 + 0x26) == 0)) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_receive: valid queue length");
          }
          lVar5 = *(longlong *)(param_1 + 0x28);
        } while (lVar5 != 0);
        param_3 = (ulonglong)DAT_14007434c;
        uVar18 = DAT_140074348;
      }
      *(undefined1 *)(param_1 + 0x15) = 0;
    }
    lVar5 = *(longlong *)(param_1 + 0x26);
    param_4 = 0;
    if (lVar5 != 0) {
      do {
        uVar4 = ntohs(*(u_short *)(*(longlong *)(lVar5 + 0x20) + 0xc));
        if ((uVar4 & 1) == 0) {
          uVar4 = ntohs(*(u_short *)(*(longlong *)(*(longlong *)(param_1 + 0x26) + 0x20) + 0xc));
          param_4 = 0;
          if ((uVar4 & 2) != 0) goto LAB_14001798a;
        }
        else {
LAB_14001798a:
          param_4 = 1;
        }
        puVar6 = *(undefined8 **)(param_1 + 0x26);
        param_3 = (ulonglong)DAT_14007434c;
        uVar18 = *(uint *)(puVar6[4] + 4);
        if (((int)(((DAT_14007434c -
                    ((uVar18 << 0x10 | uVar18 & 0xff00) << 8 |
                    (uVar18 & 0xff0000 | uVar18 >> 0x10) >> 8)) - (uint)*(ushort *)(puVar6 + 3)) -
                  (int)param_4) < 0) || (0 < (int)(DAT_14007434c - param_1[0x1f])))
        goto LAB_140017a77;
        *(undefined8 *)(param_1 + 0x26) = *puVar6;
        cVar3 = pbuf_clen((undefined8 *)puVar6[1]);
        *(char *)(param_1 + 0x25) = (char)param_1[0x25] - cVar3;
        crashdump_ip6_tcp_seg_free((longlong)puVar6);
        if (((char)param_1[0x25] == '\0') || (*(longlong *)(param_1 + 0x28) != 0)) {
          lVar5 = *(longlong *)(param_1 + 0x26);
          if (lVar5 == 0) break;
        }
        else {
          lVar5 = *(longlong *)(param_1 + 0x26);
          if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_receive: valid queue length");
          }
        }
        uVar18 = *(uint *)(*(longlong *)(lVar5 + 0x20) + 4);
        param_1[0x1e] =
             (uVar18 << 0x10 | uVar18 & 0xff00) << 8 | uVar18 >> 8 & 0xff00 |
             (uint)*(byte *)(*(longlong *)(lVar5 + 0x20) + 7);
      } while (lVar5 != 0);
      param_4 = 0;
      param_3 = (ulonglong)DAT_14007434c;
LAB_140017a77:
      uVar18 = DAT_140074348;
    }
    if ((param_1[0x17] != 0) && (param_1[0x18] - (int)param_3 < 0)) {
      uVar15 = (tcp_ticks - ((short)param_1[0x19] >> 3)) - (short)param_1[0x17];
      param_3 = (ulonglong)uVar15;
      sVar16 = (short)param_1[0x19] + uVar15;
      param_1[0x17] = 0;
      *(short *)(param_1 + 0x19) = sVar16;
      uVar17 = -uVar15;
      if (-1 < (short)uVar15) {
        uVar17 = uVar15;
      }
      sVar9 = (uVar17 - (*(short *)((longlong)param_1 + 0x66) >> 2)) +
              *(short *)((longlong)param_1 + 0x66);
      uVar17 = (sVar16 >> 3) + sVar9;
      param_4 = (ulonglong)uVar17;
      *(short *)((longlong)param_1 + 0x66) = sVar9;
      *(ushort *)(param_1 + 0x1a) = uVar17;
    }
  }
  uVar2 = param_1[0x12];
  plVar11 = (longlong *)(ulonglong)uVar2;
  if (DAT_140074350 == 0) {
    if (-1 < (int)(uVar18 - uVar2)) {
      iVar14 = (uVar18 - *(ushort *)(param_1 + 0x13)) - uVar2;
      goto LAB_140018015;
    }
  }
  else {
    iVar14 = uVar2 - uVar18;
    if ((iVar14 < 1) || (-1 < (int)((uVar2 - DAT_140074350) - uVar18))) {
      if ((int)(uVar18 - uVar2) < 0) {
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
        crashdump_tcp6_output(param_1,plVar11,param_3,param_4);
        uVar18 = DAT_140074348;
      }
    }
    else {
      if (DAT_140074318 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("inseg.p != NULL");
      }
      plVar11 = DAT_140074318;
      if ((int)(uint)*(ushort *)((longlong)DAT_140074318 + 0x12) < iVar14) {
        lVar5 = DAT_140074318[2];
        uVar17 = *(ushort *)((longlong)DAT_140074318 + 0x12);
        sVar16 = (short)iVar14;
        if ((int)(uint)uVar17 < iVar14) {
          do {
            *(short *)(plVar11 + 2) = (short)lVar5 - sVar16;
            iVar14 = iVar14 - (uint)uVar17;
            *(undefined2 *)((longlong)plVar11 + 0x12) = 0;
            plVar11 = (longlong *)*plVar11;
            uVar17 = *(ushort *)((longlong)plVar11 + 0x12);
          } while ((int)(uint)uVar17 < iVar14);
        }
      }
      pbuf_header((longlong)plVar11,-(short)iVar14);
      _DAT_140074320 = plVar11[1];
      DAT_140074328 = DAT_140074328 + ((short)DAT_140074348 - (short)param_1[0x12]);
      uVar18 = param_1[0x12];
      DAT_140074348 = uVar18;
      *(uint *)(DAT_140074330 + 4) = uVar18;
    }
    uVar2 = param_1[0x12];
    plVar11 = (longlong *)(ulonglong)uVar2;
    if (-1 < (int)(uVar18 - uVar2)) {
      iVar14 = (uVar18 - *(ushort *)(param_1 + 0x13)) - uVar2;
      if (iVar14 < 0) {
        if (uVar2 != uVar18) {
          *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
          crashdump_tcp6_output(param_1,plVar11,param_3,param_4);
          if (*(longlong **)(param_1 + 0x2a) == (longlong *)0x0) {
            puVar6 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140074310);
LAB_140017e4b:
            *(undefined8 **)(param_1 + 0x2a) = puVar6;
            return 0;
          }
          plVar11 = (longlong *)0x0;
          plVar12 = *(longlong **)(param_1 + 0x2a);
          do {
            uVar18 = *(uint *)(plVar12[4] + 4);
            if (DAT_140074348 == uVar18) {
              if (DAT_140074328 <= *(ushort *)(plVar12 + 3)) {
                return 0;
              }
              plVar7 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140074310);
              if (plVar7 == (longlong *)0x0) {
                return 0;
              }
              *plVar7 = *plVar12;
              if (plVar11 == (longlong *)0x0) {
                *(longlong **)(param_1 + 0x2a) = plVar7;
                return 0;
              }
              *plVar11 = (longlong)plVar7;
              return 0;
            }
            if (plVar11 == (longlong *)0x0) {
              if ((int)(DAT_140074348 - uVar18) < 0) {
                if (0 < (int)((DAT_140074328 - uVar18) + DAT_140074348)) {
                  DAT_140074328 = (short)uVar18 - (short)DAT_140074348;
                  pbuf_realloc(DAT_140074318,DAT_140074328);
                }
                puVar6 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140074310);
                if (puVar6 == (undefined8 *)0x0) {
                  return 0;
                }
                *puVar6 = plVar12;
                goto LAB_140017e4b;
              }
            }
            else if ((0 < (int)(DAT_140074348 - *(int *)(plVar11[4] + 4))) &&
                    ((int)((DAT_140074348 - uVar18) + 1) < 1)) {
              if (0 < (int)((DAT_140074328 - uVar18) + DAT_140074348)) {
                DAT_140074328 = (short)uVar18 - (short)DAT_140074348;
                pbuf_realloc(DAT_140074318,DAT_140074328);
              }
              puVar6 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140074310);
              uVar18 = DAT_140074348;
              if (puVar6 == (undefined8 *)0x0) {
                return 0;
              }
              *puVar6 = plVar12;
              *plVar11 = (longlong)puVar6;
              if ((int)((*(ushort *)(plVar11 + 3) - uVar18) + *(int *)(plVar11[4] + 4)) < 1) {
                return 0;
              }
              uVar17 = (short)uVar18 - *(short *)(plVar11[4] + 4);
              *(ushort *)(plVar11 + 3) = uVar17;
              puVar6 = (undefined8 *)plVar11[1];
              goto LAB_140017f75;
            }
            plVar7 = (longlong *)*plVar12;
            if ((plVar7 == (longlong *)0x0) && (0 < (int)(DAT_140074348 - uVar18))) {
              puVar6 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140074310);
              *plVar12 = (longlong)puVar6;
              if (puVar6 == (undefined8 *)0x0) {
                return 0;
              }
              if ((int)((*(ushort *)(plVar12 + 3) - DAT_140074348) + *(int *)(plVar12[4] + 4)) < 1)
              {
                return 0;
              }
              uVar17 = (short)DAT_140074348 - *(short *)(plVar12[4] + 4);
              *(ushort *)(plVar12 + 3) = uVar17;
              puVar6 = (undefined8 *)plVar12[1];
LAB_140017f75:
              pbuf_realloc(puVar6,uVar17);
              return 0;
            }
            plVar11 = plVar12;
            plVar12 = plVar7;
            if (plVar7 == (longlong *)0x0) {
              return 0;
            }
          } while( true );
        }
        uVar13 = 1;
        if ((*(longlong *)(param_1 + 0x2a) != 0) &&
           (plVar11 = *(longlong **)(*(longlong *)(param_1 + 0x2a) + 0x20),
           (int)((*(int *)((longlong)plVar11 + 4) - (uint)DAT_140074328) - uVar18) < 1)) {
          DAT_140074328 = *(short *)((longlong)plVar11 + 4) - (short)uVar18;
          plVar11 = (longlong *)(ulonglong)DAT_140074328;
          pbuf_realloc(DAT_140074318,DAT_140074328);
        }
        uVar4 = ntohs(*(u_short *)(DAT_140074330 + 0xc));
        if (((uVar4 & 1) == 0) &&
           (uVar4 = ntohs(*(u_short *)(DAT_140074330 + 0xc)), (uVar4 & 2) == 0)) {
          sVar16 = 0;
        }
        else {
          sVar16 = 1;
        }
        uVar17 = sVar16 + DAT_140074328;
        DAT_140074350 = uVar17;
        if (param_1[0xc] != 7) {
          param_1[0x12] = param_1[0x12] + (uint)uVar17;
        }
        if (*(ushort *)(param_1 + 0x13) < uVar17) {
          sVar16 = 0;
        }
        else {
          sVar16 = *(ushort *)(param_1 + 0x13) - uVar17;
        }
        *(short *)(param_1 + 0x13) = sVar16;
        if ((short)DAT_140074318[2] != 0) {
          DAT_140074358 = DAT_140074318;
          DAT_140074318 = (longlong *)0x0;
        }
        uVar4 = ntohs(*(u_short *)(DAT_140074330 + 0xc));
        if ((uVar4 & 1) != 0) {
          DAT_1400742fe = 0x20;
        }
        while (puVar6 = *(undefined8 **)(param_1 + 0x2a), puVar6 != (undefined8 *)0x0) {
          uVar18 = *(uint *)(puVar6[4] + 4);
          if (uVar18 != param_1[0x12]) break;
          DAT_140074348 = uVar18;
          uVar4 = ntohs(*(u_short *)(puVar6[4] + 0xc));
          if ((uVar4 & 1) == 0) {
            uVar4 = ntohs(*(u_short *)(puVar6[4] + 0xc));
            iVar14 = 0;
            if ((uVar4 & 2) != 0) goto LAB_140017d10;
          }
          else {
LAB_140017d10:
            iVar14 = 1;
          }
          param_1[0x12] = param_1[0x12] + (uint)*(ushort *)(puVar6 + 3) + iVar14;
          uVar4 = ntohs(*(u_short *)(puVar6[4] + 0xc));
          if ((uVar4 & 1) == 0) {
            uVar4 = ntohs(*(u_short *)(puVar6[4] + 0xc));
            iVar14 = 0;
            if ((uVar4 & 2) != 0) goto LAB_140017d42;
          }
          else {
LAB_140017d42:
            iVar14 = 1;
          }
          if ((uint)*(ushort *)(param_1 + 0x13) < (uint)*(ushort *)(puVar6 + 3) + iVar14) {
            sVar16 = 0;
          }
          else {
            uVar4 = ntohs(*(u_short *)(puVar6[4] + 0xc));
            if (((uVar4 & 1) == 0) &&
               (uVar4 = ntohs(*(u_short *)(puVar6[4] + 0xc)), (uVar4 & 2) == 0)) {
              sVar16 = 0;
            }
            else {
              sVar16 = 1;
            }
            sVar16 = ((short)param_1[0x13] - sVar16) - *(short *)(puVar6 + 3);
          }
          *(short *)(param_1 + 0x13) = sVar16;
          plVar12 = (longlong *)puVar6[1];
          if ((short)plVar12[2] != 0) {
            if (DAT_140074358 == (longlong *)0x0) {
              DAT_140074358 = plVar12;
            }
            else {
              pbuf_cat(DAT_140074358,(longlong)plVar12);
              plVar11 = plVar12;
            }
            puVar6[1] = 0;
          }
          uVar4 = ntohs(*(u_short *)(puVar6[4] + 0xc));
          if (((uVar4 & 1) != 0) && (DAT_1400742fe = 0x20, param_1[0xc] == 4)) {
            param_1[0xc] = 7;
          }
          *(undefined8 *)(param_1 + 0x2a) = *puVar6;
          crashdump_ip6_tcp_seg_free((longlong)puVar6);
        }
        bVar1 = *(byte *)(param_1 + 0x11);
        if ((bVar1 & 1) == 0) {
          *(byte *)(param_1 + 0x11) = bVar1 | 1;
          return 1;
        }
        *(byte *)(param_1 + 0x11) = bVar1 & 0xfe | 2;
        goto LAB_14001801b;
      }
LAB_140018015:
      if (iVar14 + 1 < 1) {
        return 0;
      }
    }
  }
  *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
LAB_14001801b:
  crashdump_tcp6_output(param_1,plVar11,param_3,param_4);
  return uVar13;
}



===== tcp_recv_null @ 140018040 =====

char tcp_recv_null(undefined8 param_1,int *param_2,undefined8 *param_3,ulonglong param_4)

{
  char cVar1;
  
  if (param_3 == (undefined8 *)0x0) {
    if ((char)param_4 == '\0') {
      cVar1 = crashdump_tcp6_close(param_2,param_2,0,param_4);
      return cVar1;
    }
  }
  else {
    pbuf_free(param_3);
  }
  return '\0';
}



===== _guard_dispatch_icall @ 140018080 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140018080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memmove @ 1400180c0 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

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
          puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 0x10));
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
          *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
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
            puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x30));
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)((longlong)puVar9 + uVar11);
            uVar6 = ((undefined8 *)((longlong)puVar9 + uVar11))[1];
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
        if (uVar12 == 0) goto LAB_140018277;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
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
LAB_140018277:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 8));
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((longlong)puVar9 + (uVar11 - 1));
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
        *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)((longlong)_Dst + uVar11))[1];
        *(undefined8 *)_Dst = *(undefined8 *)((longlong)_Dst + uVar11);
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
          uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
          puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x20);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x30);
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
      if (uVar12 == 0) goto LAB_1400180d2;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
      puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_1400180d2:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)((longlong)puVar9 + uVar11);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== memset @ 140018400 =====

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



===== DriverEntry @ 140078000 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DriverEntry(longlong param_1,longlong param_2)

{
  undefined8 local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined2 local_6e;
  undefined8 local_68;
  code *local_60;
  code *local_58;
  
  memset(&local_d8,0,0xd0);
  _iScsiCrashDumpDebugFlags = 0;
  _iscsi_debug = 0;
  if ((param_1 == 0) && (param_2 == 0xdeadbeef)) {
    DAT_14002d911 = 1;
  }
  local_a8 = 0;
  local_d0 = CrashDumpInitialize;
  local_a0 = 0;
  local_c8 = CrashDumpStartIo;
  local_90 = 0;
  local_c0 = CrashDumpIsr;
  local_78 = 0;
  local_b8 = CrashDumpFindAdapter;
  local_b0 = CrashDumpResetBus;
  local_60 = iscsiBootCancel;
  local_6e = 0;
  local_68 = 0;
  local_58 = CrashDumpBuildIo;
  local_d8 = 0x88;
  local_98 = 0x7078;
  local_80 = 0x1010101;
  local_7c = 0x101;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== entry @ 140078110 =====

void entry(longlong param_1,longlong param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14007813c =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x14002d278) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}


