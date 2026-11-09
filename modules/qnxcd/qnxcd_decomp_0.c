
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

char CrashDumpDoLogin(ushort *param_1,longlong param_2,uint param_3)

{
  undefined2 *puVar1;
  code *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar4 = 0;
  do {
    uVar6 = (ulonglong)*(byte *)(param_2 + 0x97);
    console_print(&s_starting_login_s__d___s__c___d_,uVar4,param_2 + 0x16,uVar6);
    uVar5 = (ulonglong)param_3;
    iscsiSessionStart(param_1,param_2,param_3);
    pcVar2 = iscsiAbortRoutine;
    puVar1 = iscsiAddTimer(*(undefined2 *)(iscsiGlobalsPtr + 0xd80),iscsiAbortRoutine);
    *(undefined1 *)(iscsiGlobalsPtr + 0xd82) = 0;
    while (*(char *)(iscsiGlobalsPtr + 0xd82) == '\0') {
      iscsiProcessLoop(1);
      if (*(char *)(iscsiGlobalsPtr + 0x70) == '\x03') {
        console_print("Login target successfully\n",pcVar2,uVar5,uVar6);
        return '\0';
      }
    }
    if (*(short *)(iscsiGlobalsPtr + 0x2c) == 0x20a) {
      console_print("Login response: 20a, giving 20s\n",pcVar2,uVar5,uVar6);
      StorPortStallExecution(15000000);
    }
    iscsiDelTimer(puVar1);
    iscsiSessionStop((longlong)param_1);
    StorPortStallExecution(5000000);
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar3;
  } while ((int)uVar3 < 4);
  return -((char)param_1[0x34] != '\x03');
}



===== CrashDumpExecuteiSCSICommand @ 140001150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char CrashDumpExecuteiSCSICommand(longlong param_1,longlong param_2)

{
  code *pcVar1;
  char cVar2;
  undefined8 uVar3;
  char cVar4;
  
  cVar2 = *(char *)(param_2 + 0x48);
  cVar4 = '\x06';
  if (cVar2 == '\x03') {
    uVar3 = CrashDumpIscsiDoRequestSense(param_1,param_2);
    cVar4 = (char)uVar3;
  }
  else if (cVar2 == '\b') {
LAB_1400011c4:
    uVar3 = CrashDumpIscsiDoRead(param_1,param_2);
    cVar4 = (char)uVar3;
  }
  else if (cVar2 == '\x12') {
    uVar3 = CrashDumpIscsiDoRead(param_1,param_2);
    cVar4 = (char)uVar3;
  }
  else {
    if (cVar2 == '\x1b') {
      return '\x01';
    }
    if (cVar2 == '%') {
      uVar3 = CrashDumpIscsiDoReadCapacity(param_1,param_2);
      cVar4 = (char)uVar3;
    }
    else {
      if (cVar2 == '(') goto LAB_1400011c4;
      if (cVar2 == '*') {
        uVar3 = CrashDumpIscsiDoWrite(param_1,param_2);
        if ((char)uVar3 == '\x01') {
          _DAT_140081358 = _DAT_140081358 + 1;
          _DAT_14008135c = _DAT_14008135c + *(int *)(param_2 + 0x10);
          return '\x01';
        }
        pcVar1 = (code *)swi(3);
        cVar2 = (*pcVar1)();
        return cVar2;
      }
      if (cVar2 == '/') {
        uVar3 = CrashDumpIscsiDoVerify(param_1,param_2);
        cVar4 = (char)uVar3;
      }
      else {
        if (cVar2 != '5') goto LAB_1400011d9;
        uVar3 = CrashDumpIscsiDoSyncCache(param_1,param_2);
        cVar4 = (char)uVar3;
      }
    }
  }
  if (cVar4 == '\x01') {
    return '\x01';
  }
LAB_1400011d9:
  _DAT_140081370 = 0;
  _DAT_14008136c = 0;
  _DAT_140081368 = (uint)*(byte *)(param_2 + 0x48);
  _DAT_140081364 = 0xc0000002;
  return cVar4;
}



===== CrashDumpExtractiSCSIFromExtIf @ 140001204 =====

void CrashDumpExtractiSCSIFromExtIf(longlong param_1)

{
  uint *puVar1;
  undefined8 uVar2;
  ushort uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  undefined8 uVar12;
  
  lVar6 = (*(ulonglong *)(param_1 + 6) >> 0x10) * 0x10 + (*(ulonglong *)(param_1 + 6) & 0xffff);
  lVar7 = (*(ulonglong *)(param_1 + 0x20) >> 0x10) * 0x10 +
          (*(ulonglong *)(param_1 + 0x20) & 0xffff);
  console_print("EXT_IF @%p, p:%p s:%p\n",param_1,lVar6,lVar7);
  lVar5 = 0;
  lVar10 = 0xda0;
  lVar11 = 2;
  do {
    lVar4 = iscsiGlobalsPtr + 0xdb0 + lVar5;
    lVar5 = lVar5 + 0x520;
    *(longlong *)(lVar10 + iscsiGlobalsPtr) = lVar4;
    lVar10 = lVar10 + 8;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  if (lVar6 != 0) {
    **(undefined1 **)(iscsiGlobalsPtr + 0xda0) = 1;
    *(undefined2 *)(*(longlong *)(iscsiGlobalsPtr + 0xda0) + 0x4c8) =
         *(undefined2 *)(param_1 + 0x1a);
    *(undefined4 *)(*(longlong *)(iscsiGlobalsPtr + 0xda0) + 4) = *(undefined4 *)(param_1 + 2);
    *(undefined2 *)(*(longlong *)(iscsiGlobalsPtr + 0xda0) + 0xe) = *(undefined2 *)(param_1 + 0x2a);
    puVar1 = (uint *)(*(longlong *)(iscsiGlobalsPtr + 0xda0) + 4);
    *puVar1 = *puVar1 | 0x800000;
  }
  if (lVar7 != 0) {
    **(undefined1 **)(iscsiGlobalsPtr + 0xda8) = 1;
    *(undefined2 *)(*(longlong *)(iscsiGlobalsPtr + 0xda8) + 0x4c8) =
         *(undefined2 *)(param_1 + 0x28);
    *(undefined4 *)(*(longlong *)(iscsiGlobalsPtr + 0xda8) + 4) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined2 *)(*(longlong *)(iscsiGlobalsPtr + 0xda8) + 0xe) = *(undefined2 *)(param_1 + 0x2c);
  }
  uVar9 = 0;
  *(undefined8 *)(iscsiGlobalsPtr + 0x17f0) = *(undefined8 *)(param_1 + 0x10);
  *(undefined2 *)(iscsiGlobalsPtr + 0x17f8) = *(undefined2 *)(param_1 + 0x18);
  uVar12 = 0;
  do {
    *(char *)(iscsiGlobalsPtr + 0xd9c) = (char)uVar9;
    if (**(char **)(iscsiGlobalsPtr + 0xda0 + (uVar9 & 0xff) * 8) != '\0') {
      lVar5 = lVar6;
      if ((int)uVar9 != 0) {
        lVar5 = lVar7;
      }
      lVar11 = lVar5;
      console_print(&s_iscsi_config_block__p_,lVar5,lVar10,uVar12);
      if (*(short *)(lVar5 + 2) == 0x200) {
        if (lVar5 != 0) {
          istrcpy(*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                  0x58,(char *)(lVar5 + 8));
          uVar8 = *(uint *)(lVar5 + 4);
          if ((uVar8 & 1) != 0) {
            puVar1 = (uint *)(*(longlong *)
                               (iscsiGlobalsPtr + 0xda0 +
                               (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
            *puVar1 = *puVar1 | 0x10000;
            uVar8 = *(uint *)(lVar5 + 4);
          }
          if ((uVar8 & 2) != 0) {
            puVar1 = (uint *)(*(longlong *)
                               (iscsiGlobalsPtr + 0xda0 +
                               (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
            *puVar1 = *puVar1 | 0x20000;
            uVar8 = *(uint *)(lVar5 + 4);
          }
          if ((uVar8 & 4) != 0) {
            puVar1 = (uint *)(*(longlong *)
                               (iscsiGlobalsPtr + 0xda0 +
                               (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
            *puVar1 = *puVar1 | 0x40000;
            uVar8 = *(uint *)(lVar5 + 4);
          }
          if ((uVar8 & 8) != 0) {
            puVar1 = (uint *)(*(longlong *)
                               (iscsiGlobalsPtr + 0xda0 +
                               (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
            *puVar1 = *puVar1 | 0x80000;
            uVar8 = *(uint *)(lVar5 + 4);
          }
          if ((char)uVar8 < '\0') {
            puVar1 = (uint *)(*(longlong *)
                               (iscsiGlobalsPtr + 0xda0 +
                               (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
            *puVar1 = *puVar1 | 0x100000;
            uVar8 = *(uint *)(lVar5 + 4);
          }
          if ((uVar8 & 0x20) != 0) {
            puVar1 = (uint *)(*(longlong *)
                               (iscsiGlobalsPtr + 0xda0 +
                               (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
            *puVar1 = *puVar1 | 0x200000;
            uVar8 = *(uint *)(lVar5 + 4);
          }
          if ((uVar8 & 0x40) != 0) {
            puVar1 = (uint *)(*(longlong *)
                               (iscsiGlobalsPtr + 0xda0 +
                               (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
            *puVar1 = *puVar1 | 0x400000;
          }
          uVar3 = *(ushort *)(lVar5 + 0x80);
          if ((uVar3 & 1) != 0) {
            puVar1 = (uint *)(*(longlong *)
                               (iscsiGlobalsPtr + 0xda0 +
                               (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
            *puVar1 = *puVar1 | 0x800000;
            uVar3 = *(ushort *)(lVar5 + 0x80);
          }
          if ((uVar3 & 2) != 0) {
            puVar1 = (uint *)(*(longlong *)
                               (iscsiGlobalsPtr + 0xda0 +
                               (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
            *puVar1 = *puVar1 | 0x1000000;
            uVar3 = *(ushort *)(lVar5 + 0x80);
          }
          if ((uVar3 & 4) != 0) {
            puVar1 = (uint *)(*(longlong *)
                               (iscsiGlobalsPtr + 0xda0 +
                               (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
            *puVar1 = *puVar1 | 0x2000000;
          }
          lVar11 = *(longlong *)
                    (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
          if ((*(uint *)(lVar11 + 4) & 0x20000) == 0) {
            uVar2 = *(undefined8 *)(lVar5 + 0xb0);
            *(undefined8 *)(lVar11 + 0x458) = *(undefined8 *)(lVar5 + 0xa8);
            *(undefined8 *)(lVar11 + 0x460) = uVar2;
            uVar2 = *(undefined8 *)(lVar5 + 0xb0);
            lVar11 = *(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
            *(undefined8 *)(lVar11 + 0x488) = *(undefined8 *)(lVar5 + 0xa8);
            *(undefined8 *)(lVar11 + 0x490) = uVar2;
            uVar2 = *(undefined8 *)(lVar5 + 0xc0);
            lVar11 = *(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
            *(undefined8 *)(lVar11 + 0x468) = *(undefined8 *)(lVar5 + 0xb8);
            *(undefined8 *)(lVar11 + 0x470) = uVar2;
            uVar2 = *(undefined8 *)(lVar5 + 0xd0);
            lVar11 = *(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
            *(undefined8 *)(lVar11 + 0x478) = *(undefined8 *)(lVar5 + 200);
            *(undefined8 *)(lVar11 + 0x480) = uVar2;
            uVar2 = *(undefined8 *)(lVar5 + 0xe0);
            lVar11 = *(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
            *(undefined8 *)(lVar11 + 0x4a8) = *(undefined8 *)(lVar5 + 0xd8);
            *(undefined8 *)(lVar11 + 0x4b0) = uVar2;
            uVar2 = *(undefined8 *)(lVar5 + 0xf0);
            lVar11 = *(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
            *(undefined8 *)(lVar11 + 0x4b8) = *(undefined8 *)(lVar5 + 0xe8);
            *(undefined8 *)(lVar11 + 0x4c0) = uVar2;
          }
          istrcpy(*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                  0x3a6,(char *)(lVar5 + 0x179));
          istrcpy(*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                  0x427,(char *)(lVar5 + 0x1fa));
          istrcpy(*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                  0x282,(char *)(lVar5 + 0x2d6));
          istrcpy(*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                  900,(char *)(lVar5 + 0x357));
          istrcpy(*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                  0x303,(char *)(lVar5 + 0x516));
          istrcpy(*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                  0x395,(char *)(lVar5 + 0x597));
          istrcpy(*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                  0x200,(char *)(lVar5 + 0xf8));
          itolowerstr((char *)(*(longlong *)
                                (iscsiGlobalsPtr + 0xda0 +
                                (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x200));
          lVar11 = *(longlong *)
                    (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
          if ((*(uint *)(lVar11 + 4) & 0x40000) == 0) {
            if ((*(byte *)(lVar5 + 0x2c0) & 1) != 0) {
              lVar10 = lVar11 + 900;
              iscsiAddiScsiTargetNvramInfo(lVar5 + 0x2c0,lVar11 + 0x282,lVar10);
            }
            if ((*(byte *)(lVar5 + 0x500) & 1) != 0) {
              lVar11 = *(longlong *)
                        (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8
                        );
              lVar10 = lVar11 + 0x395;
              iscsiAddiScsiTargetNvramInfo(lVar5 + 0x500,lVar11 + 0x303,lVar10);
            }
          }
        }
      }
      else {
        console_print("Invalide config block\n",lVar11,lVar10,uVar12);
      }
    }
    uVar8 = (int)uVar9 + 1;
    uVar9 = (ulonglong)uVar8;
  } while ((int)uVar8 < 2);
  return;
}



===== CrashDumpExtractiSCSIFromNic @ 140001828 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CrashDumpExtractiSCSIFromNic(void)

{
  undefined8 uVar1;
  bool bVar2;
  ushort uVar3;
  int iVar4;
  longlong lVar5;
  ushort *puVar6;
  undefined8 *puVar7;
  char cVar8;
  undefined1 *puVar9;
  undefined4 *_Dst;
  ushort *puVar10;
  undefined *puVar11;
  undefined8 *puVar12;
  undefined1 *puVar13;
  undefined1 auStack_448 [32];
  uint local_428;
  uint local_420;
  int local_418;
  ushort local_414;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_448;
  bVar2 = false;
  iVar4 = (**(code **)(l2_driver_intf + 0x10))(*(undefined8 *)(OurAdapter + 0x61e0),&local_418);
  if (((iVar4 == 0) && (local_418 == 0x6b627369)) && ((ushort)(local_414 - 1) < 0x400)) {
    cVar8 = '\0';
    if ((ulonglong)local_414 != 0) {
      lVar5 = 0;
      do {
        cVar8 = cVar8 + *(char *)((longlong)&local_418 + lVar5);
        lVar5 = lVar5 + 1;
      } while (lVar5 < (longlong)(ulonglong)local_414);
      if (cVar8 != '\0') {
        return;
      }
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0x18);
    if (((puVar6 != (ushort *)0x0) && (puVar6[1] == 1)) && (bVar2 = false, (char)puVar6[2] == '\0'))
    {
      bVar2 = true;
    }
    *(undefined1 *)(iscsiGlobalsPtr + 0xd9d) = *(undefined1 *)(iscsiGlobalsPtr + 0xd9c);
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0x1a);
    if (((puVar6 != (ushort *)0x0) && (puVar6[1] == 1)) && ((char)puVar6[2] == '\0')) {
      *(byte *)(iscsiGlobalsPtr + 0xd9d) = *(byte *)(iscsiGlobalsPtr + 0xd9c) ^ 1;
    }
    puVar13 = &DAT_140082760;
    if (bVar2) {
      puVar13 = &DAT_140082c80;
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,4);
    if (puVar6 != (ushort *)0x0) {
      puVar13[0x7d] = puVar6[1] == 0x10;
      memmove(puVar13 + 0x458,puVar6 + 2,(ulonglong)puVar6[1]);
      *(undefined8 *)(puVar13 + 0x488) = *(undefined8 *)(puVar13 + 0x458);
      *(undefined8 *)(puVar13 + 0x490) = *(undefined8 *)(puVar13 + 0x460);
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,5);
    if (puVar6 != (ushort *)0x0) {
      memmove(puVar13 + 0x468,puVar6 + 2,(ulonglong)puVar6[1]);
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,6);
    if (puVar6 != (ushort *)0x0) {
      memmove(puVar13 + 0x478,puVar6 + 2,(ulonglong)puVar6[1]);
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0xc);
    if (puVar6 != (ushort *)0x0) {
      *(ushort *)(puVar13 + 0x4c8) = puVar6[2];
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,3);
    if (puVar6 != (ushort *)0x0) {
      memmove(puVar13 + 0x200,puVar6 + 2,(ulonglong)puVar6[1]);
      puVar13[(ulonglong)puVar6[1] + 0x200] = 0;
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0);
    if (puVar6 != (ushort *)0x0) {
      memmove(puVar13 + 0x96,puVar6 + 2,(ulonglong)puVar6[1]);
      puVar13[(ulonglong)puVar6[1] + 0x96] = 0;
      puVar13[0x281] = 1;
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,2);
    if (puVar6 != (ushort *)0x0) {
      *(ushort *)(puVar13 + 0x94) = puVar6[2];
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0x19);
    if (puVar6 != (ushort *)0x0) {
      local_420 = (uint)puVar6[5];
      local_428 = (uint)puVar6[4];
      isprintf(puVar13 + 0x117,"%x-%x-%x-%x",(ulonglong)puVar6[2],(ulonglong)puVar6[3]);
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,1);
    if (puVar6 != (ushort *)0x0) {
      memmove(puVar13 + 0x84,puVar6 + 2,(ulonglong)puVar6[1]);
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,7);
    if ((puVar6 != (ushort *)0x0) && (iVar4 = strncmp((char *)(puVar6 + 2),"CHAP",4), iVar4 == 0)) {
      puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,8);
      if (puVar6 != (ushort *)0x0) {
        memmove(puVar13 + 0x3a6,puVar6 + 2,(ulonglong)puVar6[1]);
        puVar13[(ulonglong)puVar6[1] + 0x3a6] = 0;
      }
      puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,9);
      if (puVar6 != (ushort *)0x0) {
        memmove(puVar13 + 0x427,puVar6 + 2,(ulonglong)puVar6[1]);
        puVar13[(ulonglong)puVar6[1] + 0x427] = 0;
      }
      puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,10);
      if (puVar6 != (ushort *)0x0) {
        memmove(puVar13 + 0x282,puVar6 + 2,(ulonglong)puVar6[1]);
        puVar13[(ulonglong)puVar6[1] + 0x282] = 0;
      }
      puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0xb);
      if (puVar6 != (ushort *)0x0) {
        memmove(puVar13 + 900,puVar6 + 2,(ulonglong)puVar6[1]);
        puVar13[(ulonglong)puVar6[1] + 900] = 0;
      }
    }
    puVar9 = &DAT_140082cfd;
    if (bVar2) {
      puVar9 = &DAT_1400827dd;
    }
    *puVar9 = puVar13[0x7d];
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0x10);
    if (puVar6 != (ushort *)0x0) {
      puVar12 = (undefined8 *)&DAT_1400830d8;
      if (bVar2) {
        puVar12 = (undefined8 *)&DAT_140082bb8;
      }
      memmove(puVar12,puVar6 + 2,(ulonglong)puVar6[1]);
      uVar1 = puVar12[1];
      puVar7 = (undefined8 *)&DAT_140083108;
      if (bVar2) {
        puVar7 = (undefined8 *)&DAT_140082be8;
      }
      *puVar7 = *puVar12;
      puVar7[1] = uVar1;
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0x11);
    if (puVar6 != (ushort *)0x0) {
      puVar9 = &DAT_1400830e8;
      if (bVar2) {
        puVar9 = &DAT_140082bc8;
      }
      memmove(puVar9,puVar6 + 2,(ulonglong)puVar6[1]);
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0x12);
    if (puVar6 != (ushort *)0x0) {
      _Dst = (undefined4 *)&DAT_1400830f8;
      if (bVar2) {
        _Dst = &DAT_140082bd8;
      }
      memmove(_Dst,puVar6 + 2,(ulonglong)puVar6[1]);
    }
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0x13);
    if (puVar6 != (ushort *)0x0) {
      puVar10 = &DAT_140083148;
      if (bVar2) {
        puVar10 = &DAT_140082c28;
      }
      *puVar10 = puVar6[2];
    }
    puVar11 = &DAT_140082e80;
    if (bVar2) {
      puVar11 = &DAT_140082960;
    }
    istrcpy((longlong)puVar11,puVar13 + 0x200);
    puVar11 = &DAT_140082d16;
    if (bVar2) {
      puVar11 = &DAT_1400827f6;
    }
    istrcpy((longlong)puVar11,puVar13 + 0x96);
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0x1e);
    puVar10 = &DAT_140082d14;
    if (bVar2) {
      puVar10 = &DAT_1400827f4;
    }
    if (puVar6 == (ushort *)0x0) {
      uVar3 = *(ushort *)(puVar13 + 0x94);
    }
    else {
      uVar3 = puVar6[2];
    }
    *puVar10 = uVar3;
    puVar6 = CrashDumpGetiSCSIInfoEntry((longlong)&local_418,0x1d);
    puVar12 = (undefined8 *)&DAT_140082d04;
    if (bVar2) {
      puVar12 = (undefined8 *)&DAT_1400827e4;
    }
    if (puVar6 == (ushort *)0x0) {
      uVar1 = *(undefined8 *)(puVar13 + 0x8c);
      *puVar12 = *(undefined8 *)(puVar13 + 0x84);
      puVar12[1] = uVar1;
    }
    else {
      memmove(puVar12,puVar6 + 2,(ulonglong)puVar6[1]);
    }
    puVar11 = &DAT_140082d97;
    if (bVar2) {
      puVar11 = &DAT_140082877;
    }
    istrcpy((longlong)puVar11,puVar13 + 0x117);
    puVar11 = &DAT_140083026;
    if (bVar2) {
      puVar11 = &DAT_140082b06;
    }
    istrcpy((longlong)puVar11,puVar13 + 0x3a6);
    puVar11 = &DAT_1400830a7;
    if (bVar2) {
      puVar11 = &DAT_140082b87;
    }
    istrcpy((longlong)puVar11,puVar13 + 0x427);
    puVar11 = &DAT_140082f02;
    if (bVar2) {
      puVar11 = &DAT_1400829e2;
    }
    istrcpy((longlong)puVar11,puVar13 + 0x282);
    puVar11 = &DAT_140083004;
    if (bVar2) {
      puVar11 = &DAT_140082ae4;
    }
    istrcpy((longlong)puVar11,puVar13 + 900);
    puVar9 = &DAT_140082f01;
    if (bVar2) {
      puVar9 = &DAT_1400829e1;
    }
    *puVar9 = puVar13[0x281];
  }
  return;
}



===== CrashDumpExtractiSCSIFromiBFT @ 140001e8c =====

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
      (&DAT_140082760)[lVar12] = 1;
      if (*(ushort *)(lVar15 + 0x46) != 0) {
        memmove(&DAT_140082960 + lVar12,(void *)((ulonglong)*(ushort *)(lVar15 + 0x48) + param_1),
                (ulonglong)*(ushort *)(lVar15 + 0x46));
        (&DAT_140082960)[(ulonglong)*(ushort *)(lVar15 + 0x46) + lVar12] = 0;
      }
      uVar6 = *(ushort *)(param_1 + 0x62 + uVar11);
      if (uVar6 != 0) {
        memmove(&DAT_140082b98 + lVar12,
                (void *)((ulonglong)*(ushort *)(param_1 + 100 + uVar11) + param_1),(ulonglong)uVar6)
        ;
        (&DAT_140082b98)[(ulonglong)*(ushort *)(param_1 + 0x62 + uVar11) + lVar12] = 0;
      }
      if ((*(char *)(param_1 + 0x10 + uVar11) == -1) && (*(char *)(param_1 + 0x11 + uVar11) == -1))
      {
        (&DAT_140082bb8)[lVar17 * 0x148] = *(undefined4 *)(param_1 + 0x12 + uVar11);
        uVar5 = 0;
      }
      else {
        puVar1 = (undefined8 *)(param_1 + 6 + uVar11);
        uVar4 = puVar1[1];
        uVar5 = 1;
        *(undefined8 *)(&DAT_140082bb8 + lVar17 * 0x148) = *puVar1;
        *(undefined8 *)(lVar12 + 0x140082bc0) = uVar4;
      }
      (&DAT_1400827dd)[lVar12] = uVar5;
      cVar2 = (&DAT_1400827dd)[lVar12];
      uVar4 = *(undefined8 *)(lVar12 + 0x140082bc0);
      *(undefined8 *)(&DAT_140082be8 + lVar12) = *(undefined8 *)(&DAT_140082bb8 + lVar17 * 0x148);
      *(undefined8 *)(lVar12 + 0x140082bf0) = uVar4;
      bVar7 = *(byte *)(param_1 + 0x16 + uVar11);
      uVar13 = (ulonglong)bVar7;
      if (cVar2 == '\x01') {
        (&DAT_140082bc8)[lVar12] = bVar7;
        puVar1 = (undefined8 *)(param_1 + 0x18 + uVar11);
        uVar4 = puVar1[1];
        *(undefined8 *)(&DAT_140082bd8 + lVar17 * 0x148) = *puVar1;
        *(undefined8 *)(lVar12 + 0x140082be0) = uVar4;
        puVar1 = (undefined8 *)(param_1 + 0x28 + uVar11);
        uVar4 = puVar1[1];
        *(undefined8 *)(&DAT_140082c08 + lVar17 * 0x148) = *puVar1;
        *(undefined8 *)(lVar12 + 0x140082c10) = uVar4;
        puVar1 = (undefined8 *)(param_1 + 0x38 + uVar11);
        uVar4 = puVar1[1];
        *(undefined8 *)(&DAT_140082c18 + lVar17 * 0x148) = *puVar1;
        *(undefined8 *)(lVar12 + 0x140082c20) = uVar4;
        puVar1 = (undefined8 *)(param_1 + 0x48 + uVar11);
        uVar4 = puVar1[1];
        *(undefined8 *)(&DAT_140082bf8 + lVar17 * 0x148) = *puVar1;
        *(undefined8 *)(lVar12 + 0x140082c00) = uVar4;
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
        *(uint *)(&DAT_140082bc8 + lVar12) =
             uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
        (&DAT_140082bd8)[lVar17 * 0x148] = *(undefined4 *)(param_1 + 0x24 + uVar11);
        (&DAT_140082c08)[lVar17 * 0x148] = *(undefined4 *)(param_1 + 0x34 + uVar11);
        (&DAT_140082c18)[lVar17 * 0x148] = *(undefined4 *)(param_1 + 0x44 + uVar11);
        (&DAT_140082bf8)[lVar17 * 0x148] = *(undefined4 *)(param_1 + 0x54 + uVar11);
      }
      iVar16 = 0;
      (&DAT_140082c28)[lVar17 * 0x290] = *(undefined2 *)(param_1 + 0x58 + uVar11);
      (&DAT_14008276e)[lVar17 * 0x290] = *(undefined2 *)(param_1 + 0x60 + uVar11);
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
            memmove(&DAT_140082b06 + lVar12,(void *)(param_1 + (ulonglong)uVar6),
                    (ulonglong)*(ushort *)(param_1 + 0x26 + uVar11));
            (&DAT_140082b06)[(ulonglong)*(ushort *)(param_1 + 0x26 + uVar11) + lVar12] = 0;
          }
          uVar6 = *(ushort *)(param_1 + 0x2c + uVar11);
          if (uVar6 != 0) {
            memmove(&DAT_140082b87 + lVar12,(void *)(param_1 + (ulonglong)uVar6),
                    (ulonglong)*(ushort *)(param_1 + 0x2a + uVar11));
            (&DAT_140082b87)[(ulonglong)*(ushort *)(param_1 + 0x2a + uVar11) + lVar12] = 0;
          }
          uVar6 = *(ushort *)(param_1 + 0x30 + uVar11);
          if (uVar6 != 0) {
            memmove(&DAT_1400829e2 + (ulonglong)(byte)(&DAT_1400829e1)[lVar12] * 0x81 + lVar12,
                    (void *)(param_1 + (ulonglong)uVar6),
                    (ulonglong)*(ushort *)(param_1 + 0x2e + uVar11));
            (&DAT_1400829e2)
            [(ulonglong)*(ushort *)(param_1 + 0x2e + uVar11) +
             (ulonglong)(byte)(&DAT_1400829e1)[lVar12] * 0x81 + lVar12] = 0;
          }
          uVar6 = *(ushort *)(param_1 + 0x34 + uVar11);
          if (uVar6 != 0) {
            memmove(&DAT_140082ae4 + (ulonglong)(byte)(&DAT_1400829e1)[lVar12] * 0x11 + lVar12,
                    (void *)(param_1 + (ulonglong)uVar6),
                    (ulonglong)*(ushort *)(param_1 + 0x32 + uVar11));
            (&DAT_140082ae4)
            [(ulonglong)*(ushort *)(param_1 + 0x32 + uVar11) +
             (ulonglong)(byte)(&DAT_1400829e1)[lVar12] * 0x11 + lVar12] = 0;
          }
          if (*(char *)(param_1 + 0x20 + uVar11) != '\0') {
            (&DAT_140082764)[lVar17 * 0x148] = (&DAT_140082764)[lVar17 * 0x148] | 0x10000;
          }
          bVar7 = (&DAT_1400829e1)[lVar12];
          lVar9 = (ulonglong)bVar7 * 0xc0 + lVar12;
          pbVar10 = &DAT_1400827e0 + lVar9;
          *pbVar10 = *pbVar10 | 1;
          if ((&DAT_1400827dd)[lVar12] == '\x01') {
            puVar1 = (undefined8 *)(param_1 + 6 + uVar11);
            uVar4 = puVar1[1];
            *(undefined8 *)(&DAT_1400827e4 + lVar9) = *puVar1;
            *(undefined8 *)(lVar9 + 0x1400827ec) = uVar4;
          }
          else {
            *(undefined4 *)(&DAT_1400827e4 + lVar9) = *(undefined4 *)(param_1 + 0x12 + uVar11);
          }
          (&DAT_1400827f4)[lVar17 * 0x290 + (ulonglong)bVar7 * 0x60] =
               *(undefined2 *)(param_1 + 0x16 + uVar11);
          isprintf(&DAT_140082877 + lVar9,"%x-%x-%x-%x",
                   (ulonglong)*(ushort *)(param_1 + 0x18 + uVar11),
                   (ulonglong)*(ushort *)(param_1 + 0x1a + uVar11));
          memmove(&DAT_1400827f6 + lVar9,
                  (void *)((ulonglong)*(ushort *)(param_1 + 0x24 + uVar11) + param_1),
                  (ulonglong)*(ushort *)(param_1 + 0x22 + uVar11));
          pbVar10[(ulonglong)*(ushort *)(param_1 + 0x22 + uVar11) + 0x16] = 0;
          (&DAT_1400829e1)[lVar12] = (&DAT_1400829e1)[lVar12] + '\x01';
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < 2);
    }
    uVar14 = uVar14 + 1;
    lVar17 = lVar17 + 1;
  } while (lVar17 < 2);
  return;
}



===== CrashDumpFindAdapter @ 1400022e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
CrashDumpFindAdapter
          (void *param_1,longlong param_2,undefined8 param_3,undefined8 param_4,undefined4 *param_5)

{
  ushort uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  int iVar10;
  bool bVar11;
  ulonglong local_res8;
  
  OurAdapter = param_1;
  if (CrashDumpDriverInitialized != '\x01') {
    memset(param_1,0,0x6460);
    lVar2 = *(longlong *)(param_5 + 0x10);
    if ((*(int **)(lVar2 + 8) == (int *)0x0) || (**(int **)(lVar2 + 8) != 0x54464269)) {
      *(undefined4 *)((longlong)param_1 + 0x62f0) = 1;
    }
    if ((*(longlong *)(lVar2 + 0x10) == 0) && (*(longlong *)(lVar2 + 0x18) == 0)) {
      return 2;
    }
    *(longlong *)((longlong)param_1 + 0x62c8) = *(longlong *)(lVar2 + 0x10);
    *(undefined8 *)((longlong)param_1 + 0x62e0) = *(undefined8 *)(lVar2 + 0x18);
    *(undefined8 *)((longlong)param_1 + 0x6290) = *(undefined8 *)(lVar2 + 8);
    iVar5 = -0x21524111;
    *(undefined2 *)((longlong)param_1 + 0x62d0) = 0xff;
    iVar10 = -0x21524111;
    *(undefined2 *)((longlong)param_1 + 0x62e8) = 0xff;
    if (*(int **)(lVar2 + 0x10) != (int *)0x0) {
      if (**(int **)(lVar2 + 0x10) == -1) {
        *(undefined1 *)((longlong)param_1 + 0x62d0) = 1;
      }
      else {
        puVar3 = *(undefined4 **)((longlong)param_1 + 0x62c8);
        if (puVar3 == (undefined4 *)0x0) {
          uVar9 = 0xffffffff;
        }
        else {
          uVar9 = *puVar3;
          if ((short)uVar9 != 0x14e4) {
            uVar9 = puVar3[0x800];
          }
        }
        uVar8 = iscsiIsSupportedAdapter((short)uVar9,(short)((uint)uVar9 >> 0x10));
        if ((char)uVar8 != '\0') {
          piVar4 = *(int **)((longlong)param_1 + 0x62c8);
          *(undefined1 *)((longlong)param_1 + 0x62d1) = 1;
          if (piVar4 == (int *)0x0) {
            iVar5 = -1;
          }
          else {
            iVar5 = *piVar4;
            if ((short)iVar5 != 0x14e4) {
              iVar5 = piVar4[0x800];
            }
          }
        }
      }
    }
    if (*(int **)(lVar2 + 0x18) != (int *)0x0) {
      if (**(int **)(lVar2 + 0x18) == -1) {
        *(undefined1 *)((longlong)param_1 + 0x62e8) = 1;
      }
      else {
        puVar3 = *(undefined4 **)((longlong)param_1 + 0x62e0);
        if (puVar3 == (undefined4 *)0x0) {
          uVar9 = 0xffffffff;
        }
        else {
          uVar9 = *puVar3;
          if ((short)uVar9 != 0x14e4) {
            uVar9 = puVar3[0x800];
          }
        }
        uVar8 = iscsiIsSupportedAdapter((short)uVar9,(short)((uint)uVar9 >> 0x10));
        if ((char)uVar8 != '\0') {
          piVar4 = *(int **)((longlong)param_1 + 0x62e0);
          *(undefined1 *)((longlong)param_1 + 0x62e9) = 1;
          if (piVar4 == (int *)0x0) {
            iVar10 = -1;
          }
          else {
            iVar10 = *piVar4;
            if ((short)iVar10 != 0x14e4) {
              iVar10 = piVar4[0x800];
            }
          }
        }
      }
    }
    if ((*(char *)((longlong)param_1 + 0x62d1) != '\0') ||
       (*(char *)((longlong)param_1 + 0x62e9) != '\0')) {
      if (iVar5 != -0x21524111) {
        iVar10 = iVar5;
      }
      if (iVar10 != -0x21524111) {
        bVar11 = DAT_14003a771 != '\0';
        *param_5 = 0xe0;
        param_5[6] = 0x10000;
        param_5[0xc] = 0;
        *(undefined1 *)(param_5 + 0x12) = 1;
        *(undefined2 *)((longlong)param_5 + 0x51) = 0x101;
        *(undefined1 *)((longlong)param_5 + 0x53) = 0;
        *(undefined1 *)((longlong)param_5 + 0x59) = 2;
        *(undefined1 *)((longlong)param_5 + 0x61) = 1;
        *(undefined8 *)(param_5 + 0x21) = 0x6460;
        param_5[0x23] = 0;
        *(undefined2 *)((longlong)param_5 + 0x91) = 0xff01;
        param_5[0x25] = 0;
        *(undefined8 *)(param_5 + 0x26) = 0;
        param_5[0x28] = 0;
        iscsiGlobalsPtr = &DAT_1400819b0;
        if (bVar11) {
          CrashDumpExtractiSCSIFromExtIf(param_2);
        }
        iVar5 = mm_basic_initialize((char *)((longlong)param_1 + 0x61d8),
                                    (short)((uint)iVar10 >> 0x10));
        if (iVar5 == 0) {
          l2_driver_intf = (longlong)OurAdapter + 0x61e0;
          if (*(longlong *)((longlong)param_1 + 0x6298) == 0) {
            if (l2_driver_intf == 0) {
              uVar6 = mm_get_largest_dma_length();
            }
            else {
              uVar6 = (**(code **)((longlong)OurAdapter + 0x6210))();
            }
            lVar7 = StorPortGetUncachedExtension(param_1,param_5,uVar6);
            *(longlong *)((longlong)param_1 + 0x6298) = lVar7;
            if (lVar7 == 0) {
              return 2;
            }
            local_res8 = StorPortGetPhysicalAddress(param_1,0,lVar7,(longlong)param_1 + 0x62a8);
          }
          if ((local_res8 & 0x3f) != 0) {
            *(uint *)((longlong)param_1 + 0x62b0) = (-(int)local_res8 - 1U & 0x3f) + 1;
          }
          *(int *)((longlong)param_1 + 0x62a0) = (int)local_res8;
          *(int *)((longlong)param_1 + 0x62a4) = (int)(local_res8 >> 0x20);
          mm_free_all_resources();
          if ((*(longlong *)(lVar2 + 0x10) != 0) && (*(longlong *)(lVar2 + 0x18) != 0)) {
            lVar7 = *(longlong *)((longlong)param_1 + 0x6290);
            uVar1 = *(ushort *)((ulonglong)*(ushort *)(lVar7 + 0x3a) + 0x60 + lVar7);
            *(uint *)((longlong)param_1 + 0x62c4) = (uint)(uVar1 >> 8);
            *(uint *)((longlong)param_1 + 0x62c0) = uVar1 >> 3 & 0x1f | (uVar1 & 7) << 5;
            uVar1 = *(ushort *)((ulonglong)*(ushort *)(lVar7 + 0x3e) + 0x60 + lVar7);
            *(uint *)((longlong)param_1 + 0x62dc) = (uint)(uVar1 >> 8);
            *(uint *)((longlong)param_1 + 0x62d8) = uVar1 >> 3 & 0x1f | (uVar1 & 7) << 5;
            uVar8 = CrashDump_IsNicMappingCorrect(*(int **)((longlong)param_1 + 0x6290));
            if ((char)uVar8 == '\0') {
              *(undefined8 *)((longlong)param_1 + 0x62e0) = *(undefined8 *)(lVar2 + 0x10);
              *(undefined8 *)((longlong)param_1 + 0x62c8) = *(undefined8 *)(lVar2 + 0x18);
            }
          }
          *(undefined4 *)((longlong)param_1 + 0x6458) = 0x200;
          uVar8 = CrashDumpInitializeAdapter((longlong)param_1);
          if ((char)uVar8 == '\x01') {
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



===== CrashDumpGetiSCSIInfoEntry @ 1400026b0 =====

ushort * CrashDumpGetiSCSIInfoEntry(longlong param_1,byte param_2)

{
  ushort *puVar1;
  uint uVar2;
  
  puVar1 = (ushort *)(param_1 + 8);
  uVar2 = 0;
  while( true ) {
    if (*puVar1 == 0xff) {
      return (ushort *)0x0;
    }
    if (*puVar1 == (ushort)param_2) break;
    uVar2 = uVar2 + 4 + (uint)puVar1[1];
    puVar1 = (ushort *)((longlong)puVar1 + (ulonglong)(puVar1[1] + 3 & 0xfffc) + 4);
    if (0x3ff < uVar2) {
      return (ushort *)0x0;
    }
  }
  return puVar1;
}



===== CrashDumpInitSessionBuffer @ 1400026fc =====

void CrashDumpInitSessionBuffer(longlong param_1)

{
  *(longlong *)(param_1 + 0x130) = OurAdapter + 0x198;
  *(longlong *)(param_1 + 0x160) = OurAdapter + 0x1198;
  *(longlong *)(param_1 + 0x150) = OurAdapter + 0x2198;
  *(longlong *)(param_1 + 0x158) = OurAdapter + 0x4198;
  return;
}



===== CrashDumpInitiSCSIStack @ 140002750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CrashDumpInitiSCSIStack(longlong param_1)

{
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  longlong lVar9;
  char *pcVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined1 auStack_458 [32];
  uint local_438;
  uint local_430;
  uint local_428;
  uint local_420;
  undefined1 local_418 [4];
  uint local_414;
  char local_410 [1016];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_458;
  g_netif = (void *)(param_1 + 0x6308);
  *(void **)(param_1 + 0x62b8) = g_netif;
  memset(g_netif,0,0x150);
  iVar5 = stack_bringup((undefined8 *)(param_1 + 0x61a0));
  iVar6 = (**(code **)(l2_driver_intf + 0x38))(*(undefined8 *)(OurAdapter + 0x61e0),local_418,0x400)
  ;
  if (iVar6 != 1) {
    if ((*(char *)(iscsiGlobalsPtr + 0xdb0) == '\x01') &&
       (*(char *)(iscsiGlobalsPtr + 0x12d0) == '\x01')) {
      *(undefined1 *)(iscsiGlobalsPtr + 0xd9e) = 1;
    }
    if ((local_414 & 2) != 0) {
      puVar1 = (uint *)(*(longlong *)
                         (iscsiGlobalsPtr + 0xda0 +
                         (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
      *puVar1 = *puVar1 | 0x20000;
    }
    istrcpy(*(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x58,
            local_410);
    if (*(char *)(iscsiGlobalsPtr + 0xd9e) == '\x01') {
      bVar3 = *(byte *)(iscsiGlobalsPtr + 0xd9c);
      if (*(byte *)(iscsiGlobalsPtr + 0xd9d) != bVar3) {
        puVar1 = (uint *)(*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)bVar3 * 8) + 4);
        *puVar1 = *puVar1 | *(uint *)((ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9d) * 0x520 + 0xdb4
                                     + iscsiGlobalsPtr) & 0x210000;
        goto LAB_1400028e5;
      }
      if ((local_414 & 0x20) != 0) {
        lVar9 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)bVar3 * 8);
        goto LAB_1400028bc;
      }
    }
    else if ((local_414 & 0x20) != 0) {
      lVar9 = *(longlong *)
               (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
LAB_1400028bc:
      *(uint *)(lVar9 + 4) = *(uint *)(lVar9 + 4) | 0x200000;
    }
    if ((local_414 & 1) != 0) {
      puVar1 = (uint *)(*(longlong *)
                         (iscsiGlobalsPtr + 0xda0 +
                         (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
      *puVar1 = *puVar1 | 0x10000;
    }
  }
LAB_1400028e5:
  if (iVar5 != 0) goto LAB_1400029c6;
  lVar9 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  if (*(int *)(lVar9 + 0x458) == 0) {
    if (*(char *)(lVar9 + 0x7d) == '\0') {
      uVar12 = (ulonglong)*(byte *)(lVar9 + 0x13);
      uVar11 = (ulonglong)*(byte *)(lVar9 + 0x12);
      local_420 = (uint)*(byte *)(lVar9 + 0x17);
      local_428 = (uint)*(byte *)(lVar9 + 0x16);
      local_430 = (uint)*(byte *)(lVar9 + 0x15);
      local_438 = (uint)*(byte *)(lVar9 + 0x14);
      console_print("Bring up IPv4 for i/f: %x, %02x:%02x:%02x:%02x:%02x:%02x\n",
                    (ulonglong)*(ushort *)(lVar9 + 0xe),uVar11,uVar12);
      uVar7 = lm_is_vntag_enabled(*(longlong *)(OurAdapter + 0x61e0));
      pcVar10 = "SHORT";
      if ((char)uVar7 != '\0') {
        pcVar10 = "LONG";
      }
      console_print("Acquiring DHCP address %s DHCP...\n",pcVar10,uVar11,uVar12);
      iscsiDhcpDoDiscovery((char)uVar7);
      lVar9 = *(longlong *)
               (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
      piVar2 = (int *)(lVar9 + 0x458);
      if (*piVar2 == 0) {
        console_print("failed to acquired DHCP...\n",piVar2,lVar9,uVar12);
LAB_1400029c6:
        stack_shutdown(param_1 + 0x61a0);
        return 0xffffffff;
      }
      stack_set_addr(param_1 + 0x61a0);
      lVar9 = *(longlong *)
               (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
      local_438 = (uint)*(byte *)(lVar9 + 0x45b);
      console_print("Acquired DHCP address: %d.%d.%d.%d...\n",
                    (ulonglong)(*(uint *)(lVar9 + 0x458) & 0xff),(ulonglong)*(byte *)(lVar9 + 0x459)
                    ,(ulonglong)*(byte *)(lVar9 + 0x45a));
    }
    else if (((*(int *)(lVar9 + 0x45c) == 0) && (*(int *)(lVar9 + 0x460) == 0)) &&
            (*(int *)(lVar9 + 0x464) == 0)) {
      ipv6_autoconfig();
      uVar7 = *(uint *)(*(longlong *)
                         (iscsiGlobalsPtr + 0xda0 +
                         (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4);
      if ((((uVar7 & 0x60000) == 0) || (uVar4 = ipv6_do_stateful_dhcpv6(uVar7), uVar4 == 0)) ||
         (uVar8 = dhcpv6_do_discovery(uVar4), (int)uVar8 != -2)) {
        ipv6_get_default_router_ip_addrs
                  ((undefined8 *)
                   (*(longlong *)
                     (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                   0x478));
        iVar5 = ipv6_get_source_ip_addrs
                          ((undefined8 *)
                           (*(longlong *)
                             (iscsiGlobalsPtr + 0xda0 +
                             (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x4d0));
        *(int *)(*(longlong *)
                  (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                0x4cc) = iVar5;
        if (*(int *)(*(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                    + 0x4cc) != 0) {
          stack_set_addr(param_1 + 0x61a0);
          return 0;
        }
      }
      goto LAB_1400029c6;
    }
  }
  return 0;
}



===== CrashDumpInitialize @ 140002b70 =====

undefined1 CrashDumpInitialize(undefined8 param_1)

{
  StorPortNotification(3,param_1);
  return 1;
}



===== CrashDumpInitializeAdapter @ 140002b8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CrashDumpInitializeAdapter(longlong param_1)

{
  ushort uVar1;
  char *pcVar2;
  uint *puVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  int iVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong *plVar12;
  longlong lVar13;
  
  lVar7 = 0;
  uVar11 = 0xda0;
  *(undefined2 *)(iscsiGlobalsPtr + 0xd80) = 15000;
  plVar12 = (longlong *)(param_1 + 0x62c8);
  lVar13 = 2;
  *(undefined1 *)(iscsiGlobalsPtr + 0xd85) = 1;
  do {
    *(ulonglong *)(uVar11 + iscsiGlobalsPtr) = iscsiGlobalsPtr + 0xdb0 + lVar7;
    if (*plVar12 != 0) {
      *(undefined1 *)(lVar7 + 0xdb0 + iscsiGlobalsPtr) = 1;
    }
    uVar11 = uVar11 + 8;
    plVar12 = plVar12 + 3;
    lVar7 = lVar7 + 0x520;
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  if (*(longlong *)(param_1 + 0x6290) == 0) {
    CrashDumpExtractiSCSIFromNic();
  }
  else {
    CrashDumpExtractiSCSIFromiBFT(*(longlong *)(param_1 + 0x6290));
  }
  iVar9 = 0;
  do {
    if (*(char *)(iscsiGlobalsPtr + 0xd9d) == '\0') {
      *(byte *)(iscsiGlobalsPtr + 0xd9c) = (byte)iVar9;
    }
    else {
      *(byte *)(iscsiGlobalsPtr + 0xd9c) = (byte)iVar9 ^ 1;
    }
    uVar6 = (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c);
    pcVar2 = *(char **)(iscsiGlobalsPtr + 0xda0 + uVar6 * 8);
    uVar8 = iscsiGlobalsPtr;
    if (*pcVar2 != '\0') {
      uVar1 = *(ushort *)(pcVar2 + 0xe);
      *(uint *)(param_1 + 0x62c4 + uVar6 * 0x18) = (uint)(uVar1 >> 8);
      *(uint *)(param_1 + 0x62c0 + uVar6 * 0x18) = uVar1 >> 3 & 0x1f | (uVar1 & 7) << 5;
      uVar8 = *(longlong *)
               (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0xe;
      iVar4 = (*(code *)l2_driver_intf[0x10])(*(undefined8 *)(OurAdapter + 0x61e0));
      if (iVar4 == 0) {
        if (*(char *)(param_1 + 0x62d0 + (longlong)iVar9 * 0x18) == '\x01') {
          uVar5 = get_device_to_d0_if_necessary
                            (*(ushort *)
                              (*(longlong *)
                                (iscsiGlobalsPtr + 0xda0 +
                                (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0xe),uVar8,
                             uVar11,plVar12);
          if ((int)uVar5 == 0) {
            puVar3 = *(uint **)(param_1 + 0x62c8 + (longlong)iVar9 * 0x18);
            if (puVar3 == (uint *)0x0) {
              uVar10 = 0xffffffff;
            }
            else {
              uVar10 = *puVar3;
              if ((short)uVar10 != 0x14e4) {
                uVar10 = puVar3[0x800];
              }
            }
            uVar8 = (ulonglong)(uVar10 >> 0x10);
            uVar5 = iscsiIsSupportedAdapter((short)uVar10,(short)(uVar10 >> 0x10));
            if ((char)uVar5 != '\0') goto LAB_140002d24;
          }
          uVar8 = console_print(&s_skip_this_device_,uVar8,uVar11,plVar12);
          goto LAB_140002ee9;
        }
      }
      else {
        uVar8 = (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c);
        uVar1 = *(ushort *)(*(longlong *)(iscsiGlobalsPtr + 0xda0 + uVar8 * 8) + 0xe);
        *(uint *)(param_1 + 0x62c4 + uVar8 * 0x18) = (uint)(uVar1 >> 8);
        uVar10 = (uVar1 & 7) << 5;
        uVar11 = (ulonglong)uVar10;
        *(uint *)(param_1 + 0x62c0 + uVar8 * 0x18) = uVar1 >> 3 & 0x1f | uVar10;
      }
LAB_140002d24:
      console_print(&s_Bringing_up_i_f_at_pfn__x_,
                    (ulonglong)
                    *(ushort *)
                     (*(longlong *)
                       (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                     + 0xe),uVar11,plVar12);
      uVar11 = 0x68;
      uVar1 = *(ushort *)
               (*(longlong *)
                 (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0xe
               );
      memset(&g_if_stats,0,0x68);
      _g_if_stats = *(undefined8 *)(OurAdapter + 0x61e0);
      _DAT_140081348 = 0xffffffff;
      _DAT_140081350 = (uint)uVar1;
      uVar5 = CrashDumpInitiSCSIStack(param_1);
      if ((int)uVar5 == 0) {
        _DAT_140081348 = DAT_14008134c;
        DAT_14008134c = 1;
        _DAT_1400813a4 = 0xc;
        uVar8 = CrashDumpLogonTarget();
        if ((char)uVar8 == '\x01') {
          if (DAT_14003a771 != '\0') {
            uVar8 = 0;
            if ((code *)l2_driver_intf[0xf] != (code *)0x0) {
              uVar8 = (*(code *)l2_driver_intf[0xf])(*l2_driver_intf,0x54464942);
            }
          }
          return CONCAT71((int7)(uVar8 >> 8),1);
        }
        _DAT_14008136c = 0;
        _DAT_140081370 = 0;
        _DAT_140081368 =
             (uint)*(ushort *)
                    (*(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                    + 0xe);
        _DAT_140081364 = 0xc0000003;
        stack_shutdown(param_1 + 0x61a0);
      }
      else {
        _DAT_14008136c = 0;
        _DAT_140081370 = 0;
        _DAT_140081364 = 0xc0000001;
        _DAT_140081368 =
             (uint)*(ushort *)
                    (*(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                    + 0xe);
      }
      uVar8 = mm_free_all_resources();
    }
LAB_140002ee9:
    iVar9 = iVar9 + 1;
    if (1 < iVar9) {
      return uVar8 & 0xffffffffffffff00;
    }
  } while( true );
}



===== CrashDumpIscsiDoRead @ 140002f34 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashDumpIscsiDoRead(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  char cVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  iscsiSetupCmd((undefined8 *)&DAT_140081b50,1);
  DAT_140081b51 = DAT_140081b51 & 0xf9 | 0xc1;
  uVar1 = *(uint *)(param_2 + 0x10);
  _DAT_140081b64 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  memmove(&DAT_140081b70,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  iscsiSessionSendIscsiCmd
            (&DAT_140081b50,1,*(longlong *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x10));
  cVar2 = iscsiSessionWaitForCommandDone();
  uVar3 = CONCAT71(extraout_var,-(cVar2 != '\0')) & 0xffffffffffffff03;
  return CONCAT71((int7)(uVar3 >> 8),(char)uVar3 + '\x01');
}



===== CrashDumpIscsiDoReadCapacity @ 140002fa8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashDumpIscsiDoReadCapacity(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  undefined7 extraout_var;
  undefined8 uVar4;
  
  iscsiSetupCmd((undefined8 *)&DAT_140081b50,1);
  DAT_140081b51 = DAT_140081b51 & 0xf9 | 0xc1;
  uVar1 = *(uint *)(param_2 + 0x10);
  _DAT_140081b64 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  memmove(&DAT_140081b70,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  lVar2 = *(longlong *)(param_2 + 0x18);
  iscsiSessionSendIscsiCmd(&DAT_140081b50,1,lVar2,*(undefined4 *)(param_2 + 0x10));
  cVar3 = iscsiSessionWaitForCommandDone();
  if (cVar3 == '\0') {
    uVar1 = *(uint *)(lVar2 + 4);
    uVar4 = CONCAT71(extraout_var,1);
    *(uint *)(param_1 + 0x6458) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  }
  else {
    uVar4 = CONCAT71(extraout_var,4);
  }
  return uVar4;
}



===== CrashDumpIscsiDoRequestSense @ 140003044 =====

undefined8 CrashDumpIscsiDoRequestSense(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  char cVar4;
  undefined7 extraout_var;
  
  puVar1 = *(undefined8 **)(param_2 + 0x20);
  iscsiSessionSendIscsiCmd((byte *)(param_2 + 0x48),1,0,0);
  cVar4 = iscsiSessionWaitForCommandDone();
  puVar3 = DAT_140082740;
  if (cVar4 == '\x02') {
    uVar2 = DAT_140082740[1];
    *puVar1 = *DAT_140082740;
    puVar1[1] = uVar2;
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(puVar3 + 2);
  }
  return CONCAT71(extraout_var,1);
}



===== CrashDumpIscsiDoSyncCache @ 140003088 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashDumpIscsiDoSyncCache(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  char cVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  iscsiSetupCmd((undefined8 *)&DAT_140081b50,1);
  DAT_140081b51 = DAT_140081b51 & 0xf9 | 0x81;
  uVar1 = *(uint *)(param_2 + 0x10);
  _DAT_140081b64 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  memmove(&DAT_140081b70,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  iscsiSessionSendIscsiCmd
            (&DAT_140081b50,1,*(longlong *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x10));
  cVar2 = iscsiSessionWaitForCommandDone();
  uVar3 = CONCAT71(extraout_var,-(cVar2 != '\0')) & 0xffffffffffffff03;
  return CONCAT71((int7)(uVar3 >> 8),(char)uVar3 + '\x01');
}



===== CrashDumpIscsiDoVerify @ 1400030fc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashDumpIscsiDoVerify(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  char cVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  iscsiSetupCmd((undefined8 *)&DAT_140081b50,1);
  DAT_140081b51 = DAT_140081b51 | 0xc0;
  uVar1 = *(uint *)(param_2 + 0x10);
  _DAT_140081b64 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  memmove(&DAT_140081b70,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  iscsiSessionSendIscsiCmd
            (&DAT_140081b50,1,*(longlong *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x10));
  cVar2 = iscsiSessionWaitForCommandDone();
  uVar3 = CONCAT71(extraout_var,-(cVar2 != '\0')) & 0xffffffffffffff03;
  return CONCAT71((int7)(uVar3 >> 8),(char)uVar3 + '\x01');
}



===== CrashDumpIscsiDoWrite @ 140003168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashDumpIscsiDoWrite(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined7 extraout_var;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStack_68 [32];
  undefined1 local_48 [2];
  uint local_46;
  undefined2 local_41;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  memmove(local_48,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  uVar2 = 0;
  uVar4 = ((uint)(ushort)(local_41 << 8) | (uint)local_41._1_1_) * *(int *)(param_1 + 0x6458);
  uVar6 = local_46 >> 0x18 | (local_46 & 0xff0000) >> 8 | (local_46 & 0xff00) << 8 |
          local_46 << 0x18;
  if (*(uint *)(param_2 + 0x10) < uVar4) {
LAB_14000329e:
    uVar3 = CONCAT71((int7)(uVar2 >> 8),4);
  }
  else {
    uVar8 = 0;
    for (uVar5 = uVar4; uVar5 != 0; uVar5 = uVar5 - uVar7) {
      iscsiSetupCmd((undefined8 *)&DAT_140081b50,1);
      DAT_140081b51 = DAT_140081b51 & 0xf9 | 0xa1;
      uVar7 = 0x8000;
      if (uVar5 < 0x8000) {
        uVar7 = uVar5;
      }
      _DAT_140081b64 =
           uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
      uVar2 = (ulonglong)uVar7 / (ulonglong)*(uint *)(param_1 + 0x6458);
      local_41 = (ushort)(uVar2 >> 8) & 0xff | (short)uVar2 << 8;
      memmove(&DAT_140081b70,local_48,(ulonglong)*(byte *)(param_2 + 10));
      iscsiSessionSendWriteData(&DAT_140081b50,2,uVar8 + *(longlong *)(param_2 + 0x18),uVar7);
      cVar1 = iscsiSessionWaitForCommandDone();
      uVar2 = CONCAT71(extraout_var,cVar1);
      if (cVar1 != '\0') goto LAB_14000329e;
      uVar2 = (ulonglong)uVar7 / (ulonglong)*(uint *)(param_1 + 0x6458);
      uVar8 = (ulonglong)((int)uVar8 + uVar7);
      uVar6 = uVar6 + (int)uVar2;
      local_46 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 * 0x1000000
      ;
    }
    *(uint *)(param_2 + 0x10) = uVar4;
    uVar3 = CONCAT71((int7)(uVar2 >> 8),1);
  }
  return uVar3;
}



===== CrashDumpIsr @ 1400032d0 =====

undefined1 CrashDumpIsr(void)

{
  return 0;
}



===== CrashDumpLogonTarget @ 1400032d4 =====

ulonglong CrashDumpLogonTarget(void)

{
  byte bVar1;
  longlong lVar2;
  char cVar3;
  undefined7 extraout_var;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 in_R9;
  
  lVar2 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  lVar5 = lVar2 + 0x282;
  if (lVar5 != 0) {
    *(longlong *)(lVar2 + 0x130) = lVar5;
  }
  lVar2 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  lVar5 = lVar2 + 900;
  if (lVar5 != 0) {
    *(longlong *)(lVar2 + 0x138) = lVar5;
  }
  lVar5 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  bVar1 = *(byte *)(lVar5 + 0x7d);
  uVar4 = (ulonglong)bVar1;
  lVar5 = lVar5 + 0x80;
  cVar3 = CrashDumpDoLogin((ushort *)(iscsiGlobalsPtr + 8),lVar5,(uint)bVar1);
  if (cVar3 == '\0') {
    uVar4 = CONCAT71(extraout_var,1);
  }
  else {
    uVar4 = console_print(&s_Login_failed____,lVar5,uVar4,in_R9);
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  return uVar4;
}



===== CrashDumpResetBus @ 140003370 =====

undefined1 CrashDumpResetBus(undefined8 param_1,undefined8 param_2)

{
  StorPortCompleteRequest(param_1,param_2,0xff,0xff,0xe);
  StorPortNotification(1,param_1);
  return 1;
}



===== CrashDumpShutdownCommand @ 1400033a0 =====

undefined1 CrashDumpShutdownCommand(longlong param_1)

{
  iscsiSessionStop(iscsiGlobalsPtr + 8);
  stack_shutdown(param_1 + 0x61a0);
  return 1;
}



===== CrashDumpStartIo @ 1400033d0 =====

undefined1 CrashDumpStartIo(longlong param_1,longlong param_2)

{
  char cVar1;
  
  cVar1 = '\x06';
  if (*(char *)(param_2 + 2) == '\0') {
    cVar1 = CrashDumpExecuteiSCSICommand(param_1,param_2);
  }
  else if (*(char *)(param_2 + 2) == '\a') {
    cVar1 = CrashDumpShutdownCommand(param_1);
  }
  *(char *)(param_2 + 3) = cVar1;
  StorPortNotification(0,param_1,param_2);
  StorPortNotification(1,param_1);
  return 1;
}



===== CrashDump_IsNicMappingCorrect @ 14000342c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CrashDump_IsNicMappingCorrect(int *param_1)

{
  ulonglong uVar1;
  undefined1 auStack_38 [32];
  undefined1 local_18 [8];
  ulonglong local_10;
  
  uVar1 = __security_cookie ^ (ulonglong)auStack_38;
  if ((((*param_1 == 0x54464269) || (*(short *)((longlong)param_1 + 0x3e) == 0)) ||
      (local_10 = uVar1, uVar1 = (*(code *)l2_driver_intf[8])(*l2_driver_intf,local_18,1),
      (int)uVar1 != 0)) ||
     ((uVar1 = RtlCompareMemory((ulonglong)*(ushort *)((longlong)param_1 + 0x3a) + 0x5a +
                                (longlong)param_1,local_18,6), uVar1 == 6 ||
      (uVar1 = RtlCompareMemory((ulonglong)*(ushort *)((longlong)param_1 + 0x3e) + 0x5a +
                                (longlong)param_1,local_18,6), uVar1 != 6)))) {
    return CONCAT71((int7)(uVar1 >> 8),1);
  }
  return 0;
}



===== console_print @ 1400034d8 =====

void console_print(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  vDbgPrintEx(1,DAT_140031010,param_1,&local_res10);
  return;
}



===== getRandomNumber @ 14000350c =====

uint getRandomNumber(void)

{
  uint uVar1;
  undefined1 local_res8 [32];
  
  uVar1 = KeQueryPerformanceCounter(local_res8);
  return uVar1 ^ 0x80808080;
}



===== get_device_to_d0_if_necessary @ 140003528 =====

undefined8
get_device_to_d0_if_necessary
          (ushort param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined1 uVar6;
  
  uVar2 = 0;
  uVar1 = read_pci_pfn(param_1,4);
  if ((uVar1 >> 0x14 & 1) != 0) {
    uVar1 = read_pci_pfn(param_1,0x34);
    while( true ) {
      uVar5 = uVar1 & 0xff;
      if (uVar5 < 0x40) break;
      uVar1 = read_pci_pfn(param_1,(char)uVar1);
      if ((char)uVar1 == '\x01') {
        param_3 = (ulonglong)uVar5;
        console_print("PCI CAP %02x found at %04x\n",1,param_3,param_4);
        uVar2 = uVar5;
        break;
      }
      uVar1 = uVar1 >> 8;
    }
    if (uVar2 != 0) {
      uVar3 = (ulonglong)(uVar2 + 4);
      console_print("pm_csr at offset %x\n",uVar3,param_3,param_4);
      uVar6 = (undefined1)(uVar2 + 4);
      uVar4 = CONCAT71((int7)(uVar3 >> 8),uVar6);
      uVar2 = read_pci_pfn(param_1,uVar6);
      if ((uVar2 & 3) != 0) {
        console_print("Base function appeared to be powered down, power it up\n",uVar4,param_3,
                      param_4);
        write_pci_pfn(param_1,uVar6,uVar2 & 0xfffffffc);
        StorPortStallExecution(10000);
        uVar2 = read_pci_pfn(param_1,4);
        write_pci_pfn(param_1,4,uVar2 | 0x406);
      }
      return 0;
    }
  }
  return 0xffffffff;
}



===== get_network_stack @ 14000360c =====

longlong get_network_stack(void)

{
  return OurAdapter + 0x61a0;
}



===== iscsiAbortRoutine @ 140003620 =====

void iscsiAbortRoutine(void)

{
  *(undefined1 *)(iscsiGlobalsPtr + 0xd82) = 1;
  return;
}



===== iscsiAddiScsiTargetNvramInfo @ 140003630 =====

undefined8 iscsiAddiScsiTargetNvramInfo(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  byte *pbVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  
  lVar6 = iscsiGlobalsPtr;
  if (param_1 != 0) {
    lVar4 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    if (*(byte *)(lVar4 + 0x281) < 2) {
      lVar7 = (ulonglong)*(byte *)(lVar4 + 0x281) * 0xc0;
      pbVar2 = (byte *)(lVar7 + 0x80 + lVar4);
      *pbVar2 = *pbVar2 | 2;
      uVar5 = *(undefined8 *)(param_1 + 0xc);
      puVar3 = (undefined8 *)(lVar7 + 0x84 + lVar4);
      *puVar3 = *(undefined8 *)(param_1 + 4);
      puVar3[1] = uVar5;
      *(undefined2 *)(lVar7 + 0x94 + lVar4) = *(undefined2 *)(param_1 + 2);
      isprintf((char *)(lVar4 + 0x117 + lVar7),"%X",(ulonglong)*(ushort *)(param_1 + 0x14),lVar6);
      istrcpy(lVar4 + 0x96 + lVar7,(char *)(param_1 + 0xa8));
      *(undefined8 *)(lVar7 + 0x130 + lVar4) = param_2;
      *(undefined8 *)(lVar7 + 0x138 + lVar4) = param_3;
      pcVar1 = (char *)(*(longlong *)
                         (iscsiGlobalsPtr + 0xda0 +
                         (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x281);
      *pcVar1 = *pcVar1 + '\x01';
      return 0;
    }
  }
  return 0xffffffff;
}



===== iscsiGetDhcpBuffer @ 14000372c =====

longlong iscsiGetDhcpBuffer(ushort param_1)

{
  if (param_1 < 0x2001) {
    return OurAdapter + 0x198;
  }
  return 0;
}



===== iscsiGetTicks @ 140003748 =====

longlong iscsiGetTicks(void)

{
  longlong lVar1;
  longlong local_res8 [4];
  
  lVar1 = KeQueryPerformanceCounter(local_res8);
  return lVar1 / (local_res8[0] / 1000);
}



===== iscsiL2GetRxPacket @ 140003788 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void iscsiL2GetRxPacket(undefined8 param_1)

{
  (**(code **)(l2_driver_intf + 0x18))(*(undefined8 *)(OurAdapter + 0x61e0),param_1);
  return;
}



===== iscsiL2Send @ 1400037ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void iscsiL2Send(undefined8 param_1,undefined2 param_2)

{
  (**(code **)(l2_driver_intf + 0x20))(*(undefined8 *)(OurAdapter + 0x61e0),param_1,param_2);
  return;
}



===== iscsiProcessLoop @ 1400037d4 =====

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



===== iscsiServiceTicks @ 140003820 =====

void iscsiServiceTicks(void)

{
  longlong lVar1;
  
  if ((DAT_14003a774 == 0) || (lVar1 = iscsiGetTicks(), (int)lVar1 != DAT_14003a774)) {
    lVar1 = iscsiGetTicks();
    system_ticks = system_ticks + 1;
    DAT_14003a774 = (int)lVar1;
    iscsiTimerTick();
    return;
  }
  return;
}



===== htonl @ 140003858 =====

u_long __stdcall htonl(u_long netlong)

{
  return netlong >> 0x18 | (netlong & 0xff0000) >> 8 | (netlong & 0xff00) << 8 | netlong << 0x18;
}



===== um_block @ 140003860 =====

longlong um_block(void)

{
  return OurAdapter + 0x61d8;
}



===== mm_basic_initialize @ 140003870 =====

undefined4 mm_basic_initialize(char *param_1,short param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  uint uVar3;
  
  uVar2 = iscsiGetDevFamily(param_2);
  param_1[0x11c] = '\0';
  param_1[0x11d] = '\0';
  param_1[0x11e] = '\0';
  param_1[0x11f] = '\0';
  uVar3 = (uint)uVar2 & 0xff;
  *param_1 = (char)uVar2;
  if ((char)uVar2 == '\0') {
    uVar2 = nx1_get_intf((undefined8 *)(param_1 + 8));
    uVar1 = (undefined4)uVar2;
  }
  else {
    if (uVar3 == 1) {
      uVar2 = nx2_get_intf((undefined8 *)(param_1 + 8));
      return (int)uVar2;
    }
    if (uVar3 != 2) {
      return 0xffffffff;
    }
    uVar2 = nx3_get_intf((undefined8 *)(param_1 + 8));
    uVar1 = (undefined4)uVar2;
  }
  param_1[0x11c] = '\x01';
  param_1[0x11d] = '\0';
  param_1[0x11e] = '\0';
  param_1[0x11f] = '\0';
  return uVar1;
}



===== mm_current_device_map @ 1400038dc =====

undefined8 mm_current_device_map(void)

{
  longlong lVar1;
  
  lVar1 = um_block();
  return *(undefined8 *)(lVar1 + ((ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) + 10) * 0x18);
}



===== mm_free_all_resources @ 140003908 =====

undefined8 mm_free_all_resources(void)

{
  longlong lVar1;
  
  lVar1 = um_block();
  *(undefined4 *)(lVar1 + 0xd4) = *(undefined4 *)(lVar1 + 0xd8);
  memset(*(void **)(lVar1 + 0xc0),0,(ulonglong)*(uint *)(lVar1 + 0xd0));
  return 0;
}



===== mm_get_dma_buffer @ 140003940 =====

undefined8 mm_get_dma_buffer(longlong param_1,longlong *param_2,uint *param_3,int param_4)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_4 + 0x3fU & 0xffffffc0;
  if (*(uint *)(param_1 + 0xd0) < *(uint *)(param_1 + 0xd4) + uVar4) {
    return 1;
  }
  *param_2 = (ulonglong)*(uint *)(param_1 + 0xd4) + *(longlong *)(param_1 + 0xc0);
  uVar1 = *(undefined8 *)(param_1 + 200);
  *(undefined8 *)param_3 = uVar1;
  uVar2 = (uint)uVar1;
  uVar3 = *(int *)(param_1 + 0xd4) + uVar2;
  *param_3 = uVar3;
  if (uVar3 < uVar2) {
    param_3[1] = param_3[1] + 1;
  }
  *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + uVar4;
  return 0;
}



===== mm_get_largest_dma_length @ 14000399c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint mm_get_largest_dma_length(void)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 local_b8 [6];
  code *local_88;
  
  uVar2 = nx2_get_intf(local_b8);
  uVar3 = 0;
  if ((int)uVar2 == 0) {
    uVar1 = (*local_88)();
    uVar3 = 0;
    if (uVar1 != 0) {
      uVar3 = uVar1;
    }
  }
  uVar2 = nx3_get_intf(local_b8);
  if ((int)uVar2 == 0) {
    uVar1 = (*local_88)();
    if (uVar3 < uVar1) {
      uVar3 = uVar1;
    }
  }
  return uVar3;
}



===== mm_get_net_if @ 1400039f0 =====

undefined8 mm_get_net_if(void)

{
  longlong lVar1;
  
  lVar1 = um_block();
  return *(undefined8 *)(lVar1 + 0xe0);
}



===== mm_get_um_blk @ 140003a08 =====

longlong mm_get_um_blk(void)

{
  return OurAdapter + 0x61d8;
}



===== mm_stall @ 140003a10 =====

void mm_stall(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000af5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== read_pci_pfn @ 140003a18 =====

undefined4 read_pci_pfn(ushort param_1,undefined1 param_2)

{
  undefined4 local_res10 [6];
  
  HalGetBusDataByOffset
            (4,param_1 >> 8,param_1 >> 3 & 0x1f | (param_1 & 7) << 5,local_res10,param_2,4);
  return local_res10[0];
}



===== storport_mem_read_dword @ 140003a64 =====

undefined4 storport_mem_read_dword(undefined8 param_1,uint param_2)

{
  longlong lVar1;
  
  um_block();
  lVar1 = mm_current_device_map();
  return *(undefined4 *)(lVar1 + (ulonglong)param_2);
}



===== storport_pci_cfg_read_dword @ 140003a90 =====

undefined4 storport_pci_cfg_read_dword(undefined8 param_1,byte param_2)

{
  longlong lVar1;
  undefined4 local_res18 [4];
  
  lVar1 = um_block();
  if (*(int *)(lVar1 + 0x11c) == 0) {
    lVar1 = mm_current_device_map();
    local_res18[0] = *(undefined4 *)(lVar1 + (ulonglong)param_2);
  }
  else {
    HalGetBusDataByOffset
              (4,*(undefined4 *)
                  (lVar1 + 0xec + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 0x18),
               *(undefined4 *)(lVar1 + 0xe8 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 0x18),
               local_res18,param_2,4);
  }
  return local_res18[0];
}



===== storport_pci_cfg_write_dword @ 140003b04 =====

void storport_pci_cfg_write_dword(undefined8 param_1,byte param_2,undefined4 param_3)

{
  longlong lVar1;
  undefined4 local_res18 [4];
  
  local_res18[0] = param_3;
  lVar1 = um_block();
  if (*(int *)(lVar1 + 0x11c) == 0) {
    lVar1 = mm_current_device_map();
    *(undefined4 *)(lVar1 + (ulonglong)param_2) = local_res18[0];
  }
  else {
    HalSetBusDataByOffset
              (4,*(undefined4 *)
                  (lVar1 + 0xec + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 0x18),
               *(undefined4 *)(lVar1 + 0xe8 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 0x18),
               local_res18,param_2,4);
  }
  return;
}



===== storport_pci_cfg_write_word @ 140003b80 =====

void storport_pci_cfg_write_word(undefined8 param_1,byte param_2,undefined2 param_3)

{
  longlong lVar1;
  undefined2 local_res18 [8];
  
  local_res18[0] = param_3;
  lVar1 = um_block();
  if (*(int *)(lVar1 + 0x11c) == 0) {
    lVar1 = mm_current_device_map();
    *(undefined2 *)(lVar1 + (ulonglong)param_2) = local_res18[0];
  }
  else {
    HalSetBusDataByOffset
              (4,*(undefined4 *)
                  (lVar1 + 0xec + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 0x18),
               *(undefined4 *)(lVar1 + 0xe8 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 0x18),
               local_res18,param_2,2);
  }
  return;
}



===== write_pci_pfn @ 140003c00 =====

void write_pci_pfn(ushort param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 local_res18 [4];
  
  local_res18[0] = param_3;
  HalSetBusDataByOffset
            (4,param_1 >> 8,param_1 >> 3 & 0x1f | (param_1 & 7) << 5,local_res18,param_2,4);
  return;
}



===== MD5_CalculateDigest @ 140003c4c =====

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
  uVar20 = (~uVar1 & uVar3 | uVar2 & uVar1) + *param_1 + iVar4 + _DAT_1400316a4;
  uVar21 = (uVar20 * 0x80 | uVar20 >> 0x19) + uVar1;
  uVar20 = (~uVar21 & uVar2 | uVar1 & uVar21) + iVar5 + _DAT_1400316a8 + uVar3;
  iVar6 = param_1[6];
  uVar20 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar21;
  uVar22 = (~uVar20 & uVar1 | uVar20 & uVar21) + iVar6 + _DAT_1400316ac + uVar2;
  iVar7 = param_1[7];
  uVar22 = (uVar22 >> 0xf | uVar22 * 0x20000) + uVar20;
  uVar23 = (~uVar22 & uVar21 | uVar20 & uVar22) + iVar7 + _DAT_1400316b0 + uVar1;
  iVar8 = param_1[8];
  uVar23 = (uVar23 >> 10 | uVar23 * 0x400000) + uVar22;
  iVar9 = param_1[9];
  uVar21 = (~uVar23 & uVar20 | uVar22 & uVar23) + iVar8 + _DAT_1400316b4 + uVar21;
  uVar25 = (uVar21 * 0x80 | uVar21 >> 0x19) + uVar23;
  iVar10 = param_1[0xb];
  iVar11 = param_1[0xe];
  iVar12 = param_1[10];
  uVar20 = (~uVar25 & uVar22 | uVar23 & uVar25) + iVar9 + _DAT_1400316b8 + uVar20;
  uVar21 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar25;
  uVar22 = (~uVar21 & uVar23 | uVar21 & uVar25) + iVar12 + _DAT_1400316bc + uVar22;
  uVar20 = (uVar22 >> 0xf | uVar22 * 0x20000) + uVar21;
  uVar23 = (~uVar20 & uVar25 | uVar21 & uVar20) + iVar10 + _DAT_1400316c0 + uVar23;
  iVar13 = param_1[0xc];
  uVar23 = (uVar23 >> 10 | uVar23 * 0x400000) + uVar20;
  iVar14 = param_1[0xd];
  uVar25 = (~uVar23 & uVar21 | uVar20 & uVar23) + iVar13 + _DAT_1400316c4 + uVar25;
  uVar25 = (uVar25 * 0x80 | uVar25 >> 0x19) + uVar23;
  uVar21 = (~uVar25 & uVar20 | uVar23 & uVar25) + iVar14 + _DAT_1400316c8 + uVar21;
  uVar21 = (uVar21 * 0x1000 | uVar21 >> 0x14) + uVar25;
  uVar20 = (~uVar21 & uVar23 | uVar21 & uVar25) + iVar11 + _DAT_1400316cc + uVar20;
  iVar15 = param_1[0xf];
  uVar22 = (uVar20 >> 0xf | uVar20 * 0x20000) + uVar21;
  uVar23 = (~uVar22 & uVar25 | uVar21 & uVar22) + iVar15 + _DAT_1400316d0 + uVar23;
  iVar16 = param_1[0x10];
  uVar20 = (uVar23 >> 10 | uVar23 * 0x400000) + uVar22;
  iVar17 = param_1[0x11];
  iVar18 = param_1[0x12];
  iVar19 = param_1[0x13];
  uVar25 = (~uVar20 & uVar21 | uVar22 & uVar20) + iVar16 + _DAT_1400316d4 + uVar25;
  uVar25 = (uVar25 * 0x80 | uVar25 >> 0x19) + uVar20;
  uVar21 = (~uVar25 & uVar22 | uVar20 & uVar25) + iVar17 + _DAT_1400316d8 + uVar21;
  uVar23 = (uVar21 * 0x1000 | uVar21 >> 0x14) + uVar25;
  uVar22 = (~uVar23 & uVar20 | uVar23 & uVar25) + iVar18 + _DAT_1400316dc + uVar22;
  uVar21 = (uVar22 >> 0xf | uVar22 * 0x20000) + uVar23;
  uVar20 = (~uVar21 & uVar25 | uVar23 & uVar21) + iVar19 + _DAT_1400316e0 + uVar20;
  uVar20 = (uVar20 >> 10 | uVar20 * 0x400000) + uVar21;
  uVar25 = (~uVar23 & uVar21 | uVar23 & uVar20) + _DAT_1400316e4 + iVar5 + uVar25;
  uVar22 = (uVar25 * 0x20 | uVar25 >> 0x1b) + uVar20;
  uVar23 = (~uVar21 & uVar20 | uVar21 & uVar22) + _DAT_1400316e8 + iVar12 + uVar23;
  uVar25 = (uVar23 * 0x200 | uVar23 >> 0x17) + uVar22;
  uVar21 = (~uVar20 & uVar22 | uVar25 & uVar20) + _DAT_1400316ec + iVar15 + uVar21;
  uVar23 = (uVar21 * 0x4000 | uVar21 >> 0x12) + uVar25;
  uVar20 = (~uVar22 & uVar25 | uVar23 & uVar22) + _DAT_1400316f0 + iVar4 + uVar20;
  uVar21 = (uVar20 >> 0xc | uVar20 * 0x100000) + uVar23;
  uVar22 = (~uVar25 & uVar23 | uVar25 & uVar21) + _DAT_1400316f4 + iVar9 + uVar22;
  uVar20 = (uVar22 * 0x20 | uVar22 >> 0x1b) + uVar21;
  uVar25 = (~uVar23 & uVar21 | uVar23 & uVar20) + _DAT_1400316f8 + iVar11 + uVar25;
  uVar22 = (uVar25 * 0x200 | uVar25 >> 0x17) + uVar20;
  uVar23 = (~uVar21 & uVar20 | uVar22 & uVar21) + iVar19 + _DAT_1400316fc + uVar23;
  uVar25 = (uVar23 * 0x4000 | uVar23 >> 0x12) + uVar22;
  uVar21 = (~uVar20 & uVar22 | uVar25 & uVar20) + _DAT_140031700 + iVar8 + uVar21;
  uVar23 = (uVar21 >> 0xc | uVar21 * 0x100000) + uVar25;
  uVar20 = (~uVar22 & uVar25 | uVar22 & uVar23) + _DAT_140031704 + iVar14 + uVar20;
  uVar21 = (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar23;
  uVar22 = (~uVar25 & uVar23 | uVar25 & uVar21) + iVar18 + _DAT_140031708 + uVar22;
  uVar20 = (uVar22 * 0x200 | uVar22 >> 0x17) + uVar21;
  uVar25 = (~uVar23 & uVar21 | uVar20 & uVar23) + _DAT_14003170c + iVar7 + uVar25;
  uVar25 = (uVar25 * 0x4000 | uVar25 >> 0x12) + uVar20;
  uVar23 = (~uVar21 & uVar20 | uVar25 & uVar21) + _DAT_140031710 + iVar13 + uVar23;
  uVar23 = (uVar23 >> 0xc | uVar23 * 0x100000) + uVar25;
  uVar21 = (~uVar20 & uVar25 | uVar20 & uVar23) + _DAT_140031714 + iVar17 + uVar21;
  uVar22 = (uVar21 * 0x20 | uVar21 >> 0x1b) + uVar23;
  uVar20 = (~uVar25 & uVar23 | uVar25 & uVar22) + _DAT_140031718 + iVar6 + uVar20;
  uVar21 = (uVar20 * 0x200 | uVar20 >> 0x17) + uVar22;
  uVar25 = (~uVar23 & uVar22 | uVar21 & uVar23) + _DAT_14003171c + iVar10 + uVar25;
  uVar25 = (uVar25 * 0x4000 | uVar25 >> 0x12) + uVar21;
  uVar23 = (~uVar22 & uVar21 | uVar25 & uVar22) + _DAT_140031720 + iVar16 + uVar23;
  uVar20 = (uVar23 >> 0xc | uVar23 * 0x100000) + uVar25;
  uVar22 = (uVar21 ^ uVar25 ^ uVar20) + _DAT_140031724 + iVar9 + uVar22;
  uVar22 = (uVar22 * 0x10 | uVar22 >> 0x1c) + uVar20;
  uVar21 = (uVar25 ^ uVar20 ^ uVar22) + _DAT_140031728 + iVar13 + uVar21;
  uVar21 = (uVar21 * 0x800 | uVar21 >> 0x15) + uVar22;
  uVar25 = (uVar21 ^ uVar20 ^ uVar22) + _DAT_14003172c + iVar15 + uVar25;
  uVar23 = (uVar25 * 0x10000 | uVar25 >> 0x10) + uVar21;
  uVar20 = (uVar21 ^ uVar23 ^ uVar22) + _DAT_140031730 + iVar18 + uVar20;
  uVar20 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar23;
  uVar22 = (uVar21 ^ uVar23 ^ uVar20) + _DAT_140031734 + iVar5 + uVar22;
  uVar25 = (uVar22 * 0x10 | uVar22 >> 0x1c) + uVar20;
  uVar21 = (uVar23 ^ uVar20 ^ uVar25) + _DAT_140031738 + iVar8 + uVar21;
  uVar21 = (uVar21 * 0x800 | uVar21 >> 0x15) + uVar25;
  uVar23 = (uVar21 ^ uVar20 ^ uVar25) + _DAT_14003173c + iVar10 + uVar23;
  uVar22 = (uVar23 * 0x10000 | uVar23 >> 0x10) + uVar21;
  uVar20 = (uVar21 ^ uVar22 ^ uVar25) + _DAT_140031740 + iVar11 + uVar20;
  uVar20 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar22;
  uVar25 = (uVar21 ^ uVar22 ^ uVar20) + _DAT_140031744 + iVar17 + uVar25;
  uVar25 = (uVar25 * 0x10 | uVar25 >> 0x1c) + uVar20;
  uVar21 = (uVar22 ^ uVar20 ^ uVar25) + _DAT_140031748 + iVar4 + uVar21;
  uVar21 = (uVar21 * 0x800 | uVar21 >> 0x15) + uVar25;
  uVar22 = (uVar21 ^ uVar20 ^ uVar25) + _DAT_14003174c + iVar7 + uVar22;
  uVar23 = (uVar22 * 0x10000 | uVar22 >> 0x10) + uVar21;
  uVar20 = (uVar21 ^ uVar23 ^ uVar25) + _DAT_140031750 + iVar12 + uVar20;
  uVar20 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar23;
  uVar25 = (uVar21 ^ uVar23 ^ uVar20) + _DAT_140031754 + iVar14 + uVar25;
  uVar22 = (uVar25 * 0x10 | uVar25 >> 0x1c) + uVar20;
  uVar21 = (uVar23 ^ uVar20 ^ uVar22) + _DAT_140031758 + iVar16 + uVar21;
  uVar21 = (uVar21 * 0x800 | uVar21 >> 0x15) + uVar22;
  uVar23 = (uVar21 ^ uVar20 ^ uVar22) + _DAT_14003175c + iVar19 + uVar23;
  uVar23 = (uVar23 * 0x10000 | uVar23 >> 0x10) + uVar21;
  uVar20 = (uVar21 ^ uVar23 ^ uVar22) + _DAT_140031760 + iVar6 + uVar20;
  uVar25 = (uVar20 >> 9 | uVar20 * 0x800000) + uVar23;
  uVar22 = ((~uVar21 | uVar25) ^ uVar23) + _DAT_140031764 + iVar4 + uVar22;
  uVar20 = (uVar22 * 0x40 | uVar22 >> 0x1a) + uVar25;
  uVar21 = ((~uVar23 | uVar20) ^ uVar25) + _DAT_140031768 + iVar10 + uVar21;
  uVar22 = (uVar21 * 0x400 | uVar21 >> 0x16) + uVar20;
  uVar23 = ((~uVar25 | uVar22) ^ uVar20) + _DAT_14003176c + iVar18 + uVar23;
  uVar21 = (uVar23 * 0x8000 | uVar23 >> 0x11) + uVar22;
  uVar25 = ((~uVar20 | uVar21) ^ uVar22) + _DAT_140031770 + iVar9 + uVar25;
  uVar23 = (uVar25 >> 0xb | uVar25 * 0x200000) + uVar21;
  uVar20 = ((~uVar22 | uVar23) ^ uVar21) + _DAT_140031774 + iVar16 + uVar20;
  uVar25 = (uVar20 * 0x40 | uVar20 >> 0x1a) + uVar23;
  uVar22 = ((~uVar21 | uVar25) ^ uVar23) + _DAT_140031778 + iVar7 + uVar22;
  uVar20 = (uVar22 * 0x400 | uVar22 >> 0x16) + uVar25;
  uVar21 = ((~uVar23 | uVar20) ^ uVar25) + _DAT_14003177c + iVar11 + uVar21;
  uVar22 = (uVar21 * 0x8000 | uVar21 >> 0x11) + uVar20;
  uVar23 = ((~uVar25 | uVar22) ^ uVar20) + _DAT_140031780 + iVar5 + uVar23;
  uVar21 = (uVar23 >> 0xb | uVar23 * 0x200000) + uVar22;
  uVar25 = ((~uVar20 | uVar21) ^ uVar22) + _DAT_140031784 + iVar13 + uVar25;
  uVar23 = (uVar25 * 0x40 | uVar25 >> 0x1a) + uVar21;
  uVar20 = ((~uVar22 | uVar23) ^ uVar21) + _DAT_140031788 + iVar19 + uVar20;
  uVar25 = (uVar20 * 0x400 | uVar20 >> 0x16) + uVar23;
  uVar22 = ((~uVar21 | uVar25) ^ uVar23) + _DAT_14003178c + iVar12 + uVar22;
  uVar20 = (uVar22 * 0x8000 | uVar22 >> 0x11) + uVar25;
  uVar21 = ((~uVar23 | uVar20) ^ uVar25) + _DAT_140031790 + iVar17 + uVar21;
  uVar24 = (uVar21 >> 0xb | uVar21 * 0x200000) + uVar20;
  uVar23 = ((~uVar25 | uVar24) ^ uVar20) + _DAT_140031794 + iVar8 + uVar23;
  uVar21 = (uVar23 * 0x40 | uVar23 >> 0x1a) + uVar24;
  uVar25 = ((~uVar20 | uVar21) ^ uVar24) + _DAT_140031798 + iVar15 + uVar25;
  uVar22 = (uVar25 * 0x400 | uVar25 >> 0x16) + uVar21;
  uVar20 = ((~uVar24 | uVar22) ^ uVar21) + _DAT_14003179c + iVar6 + uVar20;
  uVar20 = (uVar20 * 0x8000 | uVar20 >> 0x11) + uVar22;
  uVar24 = ((~uVar21 | uVar20) ^ uVar22) + _DAT_1400317a0 + iVar14 + uVar24;
  *param_1 = *param_1 + uVar21;
  param_1[2] = uVar2 + uVar20;
  param_1[1] = (uVar24 >> 0xb | uVar24 * 0x200000) + uVar1 + uVar20;
  param_1[3] = uVar3 + uVar22;
  return;
}



===== MD5_PadMessage @ 140004554 =====

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



===== MD5_ProcessMessage @ 140004658 =====

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



===== _isprintf @ 14000479c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000494e) */
/* WARNING: Removing unreachable block (ram,0x000140004a88) */
/* WARNING: Removing unreachable block (ram,0x000140004976) */
/* WARNING: Removing unreachable block (ram,0x0001400049ee) */
/* WARNING: Removing unreachable block (ram,0x000140004b68) */
/* WARNING: Removing unreachable block (ram,0x000140004b6c) */

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
LAB_1400047ea:
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
LAB_140004eaa:
    *param_1 = '\0';
    return local_b0;
  }
  local_a8 = local_a8 + 1;
  local_ac = 0;
  uVar13 = 0xffffffff;
  local_bc = 0;
  uVar7 = uVar11;
  cVar6 = cVar18;
LAB_140004873:
  do {
    iVar17 = (int)*local_a8;
    local_a8 = local_a8 + 1;
    while (iVar17 < 100) {
      if (iVar17 == 99) {
        uVar11 = *local_b8;
        local_b8 = local_b8 + 2;
        local_88[0] = (char)uVar11;
        goto LAB_14000498e;
      }
      if (iVar17 == 0x2b) {
        cVar6 = '+';
        goto LAB_140004873;
      }
      if (iVar17 == 0x2d) {
        uVar7 = uVar7 | 4;
        goto LAB_140004873;
      }
      if (iVar17 == 0x2e) {
        uVar13 = 0;
      }
      else {
        if (iVar17 == 0x30) {
          uVar7 = uVar7 | 0x80;
          goto LAB_140004873;
        }
        if (iVar17 < 0x31) goto LAB_1400049c1;
        if (0x39 < iVar17) {
          if (iVar17 == 0x4f) goto LAB_140004a67;
          if (iVar17 == 0x55) goto LAB_140004a00;
          if (iVar17 != 0x58) goto LAB_1400049c1;
          local_a0 = "0123456789ABCDEF";
          goto LAB_1400049d7;
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
      goto LAB_140004ab1;
    }
  } while (iVar17 == 0x6c);
  if (iVar17 == 0x6f) {
LAB_140004a67:
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
      goto LAB_140004ab1;
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
      goto LAB_140004b7a;
    }
    if (iVar17 != 0x75) {
      if (iVar17 == 0x78) {
        local_a0 = "0123456789abcdef";
LAB_1400049d7:
        uVar11 = *local_b8;
        iVar4 = 0x10;
        goto LAB_140004ab1;
      }
LAB_1400049c1:
      if (iVar17 != 0) {
        local_88[0] = (char)iVar17;
LAB_14000498e:
        puVar14 = (ulonglong *)local_88;
        uVar11 = 1;
        goto LAB_140004b7a;
      }
      goto LAB_140004eaa;
    }
LAB_140004a00:
    uVar11 = *local_b8;
    iVar4 = 10;
  }
LAB_140004ab1:
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
LAB_140004b7a:
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
      pcVar5 = param_1 + -0x140031680;
      uVar2 = (uVar1 - 0x11 >> 4) + 1;
      uVar9 = (ulonglong)uVar2;
      uVar1 = uVar1 + uVar2 * -0x10;
      param_1 = param_1 + uVar9 * 0x10;
      do {
        sVar15 = 0x10;
        pcVar8 = s___0000000000000000_14003167f;
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
    pcVar5 = s___0000000000000000_14003167f;
    if ((short)uVar1 != 0) {
      do {
        pcVar5 = pcVar5 + 1;
        (param_1 + -0x140031680)[(longlong)pcVar5] = *pcVar5;
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
      pcVar5 = param_1 + -0x140031690;
      uVar2 = (uVar1 - 0x11 >> 4) + 1;
      uVar9 = (ulonglong)uVar2;
      uVar1 = uVar1 + uVar2 * -0x10;
      param_1 = param_1 + uVar9 * 0x10;
      do {
        sVar15 = 0x10;
        pcVar8 = s___0000000000000000_14003167f + 0x11;
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
    pcVar5 = s___0000000000000000_14003167f + 0x11;
    if ((short)uVar1 != 0) {
      do {
        (param_1 + -0x140031690)[(longlong)pcVar5] = *pcVar5;
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
      pcVar5 = param_1 + -0x140031690;
      uVar1 = (local_ac - 0x11 >> 4) + 1;
      uVar9 = (ulonglong)uVar1;
      local_ac = local_ac + uVar1 * -0x10;
      param_1 = param_1 + uVar9 * 0x10;
      do {
        sVar15 = 0x10;
        pcVar8 = s___0000000000000000_14003167f + 0x11;
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
    pcVar5 = s___0000000000000000_14003167f + 0x11;
    if ((short)local_ac != 0) {
      do {
        (param_1 + -0x140031690)[(longlong)pcVar5] = *pcVar5;
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
      pcVar5 = param_1 + -0x140031680;
      uVar11 = (local_bc - 0x11 >> 4) + 1;
      uVar9 = (ulonglong)uVar11;
      local_bc = local_bc + uVar11 * -0x10;
      param_1 = param_1 + uVar9 * 0x10;
      do {
        sVar15 = 0x10;
        pcVar8 = s___0000000000000000_14003167f;
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
    pcVar5 = s___0000000000000000_14003167f;
    if ((short)local_bc != 0) {
      do {
        pcVar5 = pcVar5 + 1;
        (param_1 + -0x140031680)[(longlong)pcVar5] = *pcVar5;
        uVar12 = (short)uVar11 - 1;
        uVar11 = (uint)uVar12;
      } while (uVar12 != 0);
    }
    param_1 = param_1 + (int)local_bc;
  }
  local_b0 = local_b0 + uVar13;
  goto LAB_1400047ea;
}



===== _isscanf @ 140004ed8 =====

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
LAB_140004f2c:
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
              goto LAB_140005026;
            }
            if (bVar2 != 0x6c) {
              if (bVar2 == 0x6f) goto LAB_140004fe0;
              if (bVar2 == 0x73) {
                iVar8 = 1;
                goto LAB_140005030;
              }
              if (bVar2 != 0x75) {
                if (bVar2 != 0x78) goto LAB_140005007;
                goto LAB_140004fd5;
              }
LAB_140004feb:
              uVar14 = 10;
              bVar7 = bVar5;
              goto LAB_140005026;
            }
            bVar5 = true;
          }
        }
        if (bVar2 == 100) goto LAB_140004feb;
        if (bVar2 == 0x25) goto LAB_140005135;
        if (bVar2 < 0x30) goto LAB_140005007;
        if (bVar2 < 0x3a) {
          lVar12 = (ulonglong)bVar2 + (lVar12 * 5 + -0x18) * 2;
          goto LAB_140004f2c;
        }
        if (bVar2 == 0x44) {
          bVar5 = true;
          goto LAB_140004feb;
        }
      } while (bVar2 == 0x4c);
      if (bVar2 == 0x4f) {
        bVar5 = true;
LAB_140004fe0:
        uVar14 = 8;
        bVar7 = bVar5;
LAB_140005026:
        bVar5 = bVar7;
        iVar8 = 2;
      }
      else {
        if (bVar2 == 0x58) {
          bVar5 = true;
LAB_140004fd5:
          uVar14 = 0x10;
          bVar7 = bVar5;
          goto LAB_140005026;
        }
        if (bVar2 == 0x62) {
          uVar14 = 10;
          bVar6 = true;
          goto LAB_140005026;
        }
        if (bVar2 != 99) {
LAB_140005007:
          uVar14 = 10;
          bVar7 = true;
          if (0x19 < bVar2 - 0x41) {
            bVar7 = bVar5;
          }
          goto LAB_140005026;
        }
        iVar8 = 0;
      }
LAB_140005030:
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
          goto LAB_140005140;
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
LAB_140005135:
      if ((int)(char)*param_1 != uVar13) {
        return iVar11;
      }
      param_1 = param_1 + 1;
    }
LAB_140005140:
    bVar2 = *param_2;
  } while( true );
}



===== char_to_number @ 14000517c =====

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



===== dhcpv6_do_discovery @ 1400051a8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dhcpv6_do_discovery(undefined2 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  int *piVar7;
  int iVar8;
  
  DAT_14003a798 = g_netif + 0x31;
  uip_buf = &iscsiContext;
  piVar7 = &dhcpv6_retry_timeout;
  DAT_14003a794 = *(uint *)(g_netif + 0x33) & 0xffffff;
  DAT_14003a824 = 0;
  _DAT_14003a82c = param_1;
  do {
    uVar4 = iscsiBootCancel();
    if ((int)uVar4 != 0) {
      return 0xfffffffe;
    }
    iVar1 = *piVar7;
    uVar2 = dhcpv6_init_packet((undefined2 *)&iscsiContext,1);
    DAT_14003a828 = 1;
    ipv6_send_udp_packet(0x1400813c0,(ushort)uVar2);
    iVar8 = iVar1 * 1000;
    uVar5 = iscsiGetTicks();
    uVar5 = uVar5 & 0xffffffff;
    while (iVar8 != 0) {
      lVar6 = iscsiGetTicks();
      if ((int)uVar5 != (int)lVar6) {
        uVar5 = iscsiGetTicks();
        uVar5 = uVar5 & 0xffffffff;
        iVar8 = iVar8 + -1;
      }
      iVar3 = iscsiL2GetRxPacket(&DAT_140082144);
      if ((0 < iVar3) && (ipv6_rx_packet((int *)&DAT_140082144,(short)iVar3), DAT_14003a824 == 1)) {
        return 0;
      }
    }
    DAT_14003a820 = DAT_14003a820 + (short)iVar1;
    piVar7 = piVar7 + 1;
    if (0x140031637 < (longlong)piVar7) {
      return 0xffffffff;
    }
  } while( true );
}



===== dhcpv6_handle_advertise @ 1400052c8 =====

void dhcpv6_handle_advertise(undefined2 *param_1,ushort param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  ushort uVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  char *_Str1;
  longlong lVar9;
  int iVar10;
  int iVar11;
  char *local_res18;
  
  lVar9 = 0;
  iVar10 = 0;
  local_res18 = (char *)0x0;
  iVar6 = 0;
  if (DAT_14003a828 == 1) {
    local_res18._0_1_ = '\0';
    iVar11 = 0;
    DAT_14003a828 = 2;
    _Str1 = (char *)0x0;
    cVar7 = (char)local_res18;
    if ((ulonglong)param_2 != 4) {
      uVar4 = 0;
      iVar10 = 0;
      do {
        uVar8 = (uint)(ushort)(*(short *)((longlong)param_1 + uVar4 + 0x44) << 8) |
                (uint)*(byte *)((longlong)param_1 + uVar4 + 0x45);
        uVar5 = *(short *)((longlong)param_1 + uVar4 + 0x42) << 8 |
                (ushort)*(byte *)((longlong)param_1 + uVar4 + 0x43);
        if (uVar5 == 3) {
          if ((DAT_14003a82c & 1) != 0) {
            iVar3 = dhcpv6_process_opt_ia_na((longlong)param_1 + uVar4 + 0x42);
            iVar6 = iVar6 + iVar3;
          }
        }
        else if (uVar5 == 0x10) {
          cVar7 = *(char *)((longlong)param_1 + uVar4 + 0x4b);
          local_res18 = (char *)((longlong)param_1 + uVar4 + 0x4c);
        }
        else if (uVar5 == 0x11) {
          iVar10 = uVar8 - 4;
          lVar9 = (longlong)param_1 + uVar4 + 0x4a;
        }
        else if ((uVar5 == 0x17) && ((DAT_14003a82c & 2) != 0)) {
          if (0xf < uVar8) {
            uVar2 = *(undefined8 *)((longlong)param_1 + uVar4 + 0x4e);
            lVar1 = *(longlong *)
                     (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
            *(undefined8 *)(lVar1 + 0x4a8) = *(undefined8 *)((longlong)param_1 + uVar4 + 0x46);
            *(undefined8 *)(lVar1 + 0x4b0) = uVar2;
          }
          if (0x1f < uVar8) {
            uVar2 = *(undefined8 *)((longlong)param_1 + uVar4 + 0x5e);
            lVar1 = *(longlong *)
                     (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
            *(undefined8 *)(lVar1 + 0x4b8) = *(undefined8 *)((longlong)param_1 + uVar4 + 0x56);
            *(undefined8 *)(lVar1 + 0x4c0) = uVar2;
          }
        }
        iVar11 = iVar11 + 4 +
                 ((uint)(ushort)(*(short *)((longlong)param_1 + uVar4 + 0x44) << 8) |
                 (uint)*(byte *)((longlong)param_1 + uVar4 + 0x45));
        uVar4 = (ulonglong)iVar11;
        _Str1 = local_res18;
      } while (uVar4 < (ulonglong)param_2 - 4);
    }
    if ((((DAT_14003a82c & 2) != 0) && ('\0' < cVar7)) &&
       (iVar11 = strncmp(_Str1,(char *)(*(longlong *)
                                         (iscsiGlobalsPtr + 0xda0 +
                                         (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x58),
                         (longlong)cVar7), iVar11 == 0)) {
      dhcpv6_parse_vendor_option(lVar9,iVar10);
      DAT_14003a824 = 1;
    }
    if (((DAT_14003a82c & 1) != 0) && (0 < iVar6)) {
      uVar8 = dhcpv6_init_packet(param_1,3);
      DAT_14003a828 = 3;
      ipv6_send_udp_packet((longlong)param_1,(ushort)uVar8);
      DAT_14003a824 = 1;
    }
    if (DAT_14003a824 != 0) {
      uVar2 = *(undefined8 *)(param_1 + 0xf);
      lVar9 = *(longlong *)
               (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
      *(undefined8 *)(lVar9 + 0x498) = *(undefined8 *)(param_1 + 0xb);
      *(undefined8 *)(lVar9 + 0x4a0) = uVar2;
    }
  }
  return;
}



===== dhcpv6_init_packet @ 1400054f8 =====

uint dhcpv6_init_packet(undefined2 *param_1,byte param_2)

{
  u_long uVar1;
  uint uVar2;
  ushort uVar3;
  ulonglong uVar5;
  ulonglong uVar4;
  undefined4 *puVar6;
  undefined4 *puVar7;
  ushort uVar8;
  ulonglong uVar9;
  
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
    DAT_14003a794 = DAT_14003a794 + 1;
  }
  *(uint *)(param_1 + 0x1f) = DAT_14003a794 << 8 | *(uint *)(param_1 + 0x1f) & 0xff;
  *(byte *)(param_1 + 0x1f) = param_2;
  puVar7 = DAT_14003a798;
  if (param_2 == 3) {
    uVar2 = (uint)(ushort)((param_1[0x1d] << 8 | (ushort)*(byte *)((longlong)param_1 + 0x3b)) + 0x36
                          );
  }
  else {
    *(undefined4 *)(param_1 + 0x21) = 0xa000100;
    *(undefined4 *)(param_1 + 0x23) = 0x1000300;
    uVar9 = 0x12;
    *(undefined4 *)(param_1 + 0x25) = *puVar7;
    param_1[0x27] = *(undefined2 *)(puVar7 + 1);
    puVar6 = (undefined4 *)(param_1 + 0x28);
    uVar4 = 0xffffffffffffffff;
    do {
      uVar5 = uVar4;
      uVar4 = uVar5 + 1;
    } while (*(char *)(*(longlong *)
                        (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8
                        ) + 0x58 + uVar4) != '\0');
    uVar3 = (ushort)uVar4;
    if (uVar3 != 0) {
      uVar4 = uVar4 & 0xffff;
      *(undefined2 *)puVar6 = 0x1000;
      param_1[0x29] = (ushort)(uVar4 + 6 >> 8) & 0xff | (short)(uVar4 << 8) + 0x600U;
      uVar1 = htonl(0x113d);
      *(u_long *)(param_1 + 0x2a) = uVar1;
      param_1[0x2c] = uVar3 << 8 | uVar3 >> 8;
      memmove(param_1 + 0x2d,
              (void *)(*(longlong *)
                        (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8
                        ) + 0x58),uVar4);
      uVar9 = (ulonglong)((int)uVar5 + 0x1d);
      puVar6 = (undefined4 *)((longlong)param_1 + uVar4 + 0x5a);
      puVar7 = DAT_14003a798;
    }
    uVar8 = (short)uVar9 + 0x20;
    uVar3 = DAT_14003a820 << 8;
    *puVar6 = 0xc000300;
    puVar6[1] = *(undefined4 *)((longlong)puVar7 + 2);
    *(ushort *)(puVar6 + 5) = uVar3 | DAT_14003a820 >> 8;
    *(undefined2 *)((longlong)puVar6 + 0x1e) = 0x1700;
    uVar2 = (int)CONCAT62((int6)(uVar9 >> 0x10),uVar8) + 0x3e;
    *(undefined8 *)(puVar6 + 2) = 0;
    puVar6[4] = 0x2000800;
    *(undefined4 *)((longlong)puVar6 + 0x16) = 0x6000600;
    *(undefined4 *)((longlong)puVar6 + 0x1a) = 0x11001000;
    param_1[0x1d] = (ushort)((ulonglong)uVar8 + 8 >> 8) & 0xff | uVar8 * 0x100 + 0x800;
  }
  return uVar2;
}



===== dhcpv6_parse_vendor_option @ 14000570c =====

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



===== dhcpv6_process_opt_ia_na @ 140005824 =====

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



===== ihexstr_to_int @ 140005900 =====

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



===== iint_to_hexstr @ 1400059fc =====

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



===== ip_chksum @ 140005a50 =====

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



===== ipv6_add_solit_node_address @ 140005abc =====

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



===== ipv6_autoconfig @ 140005b0c =====

void ipv6_autoconfig(void)

{
  uip_buf = &iscsiContext;
  ipv6_discover_address();
  return;
}



===== ipv6_discover_address @ 140005b20 =====

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



===== ipv6_do_stateful_dhcpv6 @ 140005c5c =====

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



===== ipv6_get_default_router_ip_addrs @ 140005c9c =====

undefined8 ipv6_get_default_router_ip_addrs(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(g_netif + 0xd0);
  *param_1 = *(undefined8 *)(g_netif + 200);
  param_1[1] = uVar1;
  return 1;
}



===== ipv6_get_source_ip_addrs @ 140005cb4 =====

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



===== ipv6_icmp_handle_echo_request @ 140005cf4 =====

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



===== ipv6_icmp_handle_nd_adv @ 140005d4c =====

void ipv6_icmp_handle_nd_adv(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = ipv6_is_it_our_address((longlong *)(param_1 + 0x26));
  if ((int)uVar1 == 1) {
    ipv6_update_arp_table((longlong *)(param_1 + 0x3e),(int *)(param_1 + 6));
  }
  return;
}



===== ipv6_icmp_handle_nd_sol @ 140005d78 =====

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



===== ipv6_icmp_handle_router_adv @ 140005e20 =====

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



===== ipv6_icmp_process_prefix @ 140005f18 =====

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



===== ipv6_icmp_rx @ 140005f74 =====

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



===== ipv6_insert_protocol_chksum @ 140005fb8 =====

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



===== ipv6_is_it_our_address @ 140006098 =====

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



===== ipv6_rx_packet @ 1400060cc =====

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



===== ipv6_send @ 140006120 =====

void ipv6_send(longlong param_1,undefined2 param_2)

{
  ipv6_setup_hdrs(param_1);
  iscsiL2Send(param_1,param_2);
  return;
}



===== ipv6_send_udp_packet @ 14000614c =====

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



===== ipv6_setup_hdrs @ 140006188 =====

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



===== ipv6_udp_handle_dhcp @ 1400061ec =====

void ipv6_udp_handle_dhcp(undefined2 *param_1)

{
  uint uVar1;
  
  if ((DAT_14003a824 != 1) && (*(uint *)(param_1 + 0x1f) >> 8 == DAT_14003a794)) {
    uVar1 = *(uint *)(param_1 + 0x1f) & 0xff;
    if (uVar1 == 2) {
      dhcpv6_handle_advertise
                (param_1,(param_1[0x1d] << 8 | (ushort)*(byte *)((longlong)param_1 + 0x3b)) - 8);
    }
    else if ((uVar1 == 7) && (DAT_14003a828 == 3)) {
      DAT_14003a824 = 1;
      return;
    }
  }
  return;
}



===== ipv6_udp_rx @ 140006250 =====

void ipv6_udp_rx(undefined2 *param_1)

{
  if (((*(byte *)(g_netif + 0x3e) & 8) == 0) && (param_1[0x1c] == 0x2202)) {
    ipv6_udp_handle_dhcp(param_1);
  }
  return;
}



===== ipv6_update_arp_table @ 140006278 =====

void ipv6_update_arp_table(longlong *param_1,int *param_2)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  int iVar4;
  longlong *plVar5;
  
  plVar5 = &ipv6_arp_table;
  do {
    if ((((int)*plVar5 != 0) && (*plVar5 == *param_1)) && (plVar5[1] == param_1[1])) {
      *(int *)(plVar5 + 2) = *param_2;
      *(short *)((longlong)plVar5 + 0x14) = (short)param_2[1];
      *(undefined1 *)((longlong)plVar5 + 0x16) = DAT_14003a822;
      return;
    }
    plVar5 = plVar5 + 3;
  } while ((longlong)plVar5 < 0x140081300);
  iVar4 = 0;
  piVar2 = (int *)&ipv6_arp_table;
  do {
    if (*piVar2 == 0) break;
    iVar4 = iVar4 + 1;
    piVar2 = piVar2 + 6;
  } while ((longlong)piVar2 < 0x140081300);
  if (iVar4 != 8) {
    lVar1 = param_1[1];
    lVar3 = (longlong)iVar4;
    (&ipv6_arp_table)[lVar3 * 3] = *param_1;
    (&DAT_140081248)[lVar3 * 3] = lVar1;
    *(int *)(&DAT_140081250 + lVar3 * 0x18) = *param_2;
    *(short *)(&DAT_140081254 + lVar3 * 0x18) = (short)param_2[1];
    (&DAT_140081256)[lVar3 * 0x18] = DAT_14003a822;
  }
  return;
}



===== iscsiAddText @ 140006310 =====

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



===== iscsiAddTimer @ 1400063f0 =====

undefined2 * iscsiAddTimer(undefined2 param_1,undefined8 param_2)

{
  short *psVar1;
  longlong lVar2;
  int iVar3;
  
  iVar3 = 0;
  psVar1 = &DAT_14003a7a0;
  do {
    if (*psVar1 == 0) {
      lVar2 = (longlong)iVar3;
      (&DAT_14003a7a8)[lVar2 * 2] = param_2;
      (&DAT_14003a7a2)[lVar2 * 8] = param_1;
      (&DAT_14003a7a4)[lVar2 * 8] = 0;
      (&DAT_14003a7a0)[lVar2 * 8] = 1;
      return &DAT_14003a7a0 + lVar2 * 8;
    }
    iVar3 = iVar3 + 1;
    psVar1 = psVar1 + 8;
  } while ((longlong)psVar1 < 0x14003a820);
  return (undefined2 *)0x0;
}



===== iscsiConnect @ 14000644c =====

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



===== iscsiDelTimer @ 140006490 =====

undefined8 iscsiDelTimer(undefined2 *param_1)

{
  if (param_1 == (undefined2 *)0x0) {
    return 0xffffffff;
  }
  *param_1 = 0;
  return 0;
}



===== iscsiDhcpDoDiscovery @ 1400064a0 =====

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
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  uint uVar14;
  undefined4 local_res8 [2];
  undefined4 local_res10 [2];
  
  lVar13 = 0;
  uVar8 = 0xffffffff;
  uVar9 = 0;
  dhcp_transaction_id =
       *(undefined4 *)
        (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
        + 0x14);
  ip_id = *(undefined2 *)
           (*(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 0x16);
  rx_buffers = (void *)iscsiGetDhcpBuffer(0x1baa);
  lVar11 = 0;
  option43 = (longlong)rx_buffers + 0x17a8;
  while( true ) {
    iVar2 = (int)lVar13;
    uVar4 = iscsiBootCancel();
    lVar13 = iscsiGlobalsPtr;
    if ((int)uVar4 != 0) {
      uVar8 = 0xfffffffe;
      goto LAB_1400067c7;
    }
    iVar3 = (&dhcp_retry_timeout)[lVar11];
    iVar2 = iscsiInitDhcpPacket((undefined1 *)(iscsiGlobalsPtr + 0x1ca),1,(undefined4 *)0x0,
                                (undefined4 *)0x0);
    iscsiDhcpSendPacket(lVar13 + 0x1a0,(ushort)iVar2);
    iVar2 = iscsiDhcpWaitForResponses(iVar3);
    lVar13 = (longlong)iVar2;
    if (0 < iVar2) break;
    _seconds = _seconds + iVar3;
    lVar11 = lVar11 + 1;
    if ((longlong)((ulonglong)(-(uint)(param_1 != '\0') & 6) + 6) <= lVar11) goto LAB_1400067c7;
  }
  if (((*(uint *)(*(longlong *)
                   (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) + 4
                 ) & 0x40000) != 0) && (uVar14 = 0, 0 < iVar2)) {
    lVar12 = 0;
    lVar11 = lVar13;
    do {
      pvVar1 = rx_buffers;
      lVar5 = iscsiDhcpFindOption((longlong)rx_buffers + lVar12 + 0x2a,
                                  ((uint)(ushort)(*(short *)(lVar12 + 0x26 + (longlong)rx_buffers)
                                                 << 8) |
                                  (uint)*(byte *)(lVar12 + 0x27 + (longlong)rx_buffers)) - 8,'<');
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
                            ((longlong)pvVar1 + lVar12 + 0x2a,
                             ((uint)(ushort)(*(short *)(lVar12 + 0x26 + (longlong)pvVar1) << 8) |
                             (uint)*(byte *)(lVar12 + 0x27 + (longlong)pvVar1)) - 8), 0 < (int)uVar6
         )) {
        uVar9 = uVar9 & 0xffff | 1 << (uVar14 & 0x1f);
      }
      uVar14 = uVar14 + 1;
      lVar12 = lVar12 + 0x5ea;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
  }
  uVar14 = 0;
  uVar10 = 0;
  if (0 < iVar2) {
    lVar12 = 0;
    lVar11 = lVar13;
    do {
      uVar4 = iscsiDhcpRetrieveStandardInfo
                        ((longlong)rx_buffers + lVar12 + 0x2a,
                         ((uint)(ushort)(*(short *)(lVar12 + 0x26 + (longlong)rx_buffers) << 8) |
                         (uint)*(byte *)(lVar12 + 0x27 + (longlong)rx_buffers)) - 8);
      if (0 < (int)uVar4) {
        uVar9 = uVar9 & 0xffff | 1 << (uVar14 & 0x1f);
      }
      uVar14 = uVar14 + 1;
      lVar12 = lVar12 + 0x5ea;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
  }
  if (0 < iVar2) {
    lVar11 = 0;
    do {
      lVar12 = iscsiGlobalsPtr;
      if (((uVar9 & 0xffff) >> (uVar10 & 0x1f) & 1) != 0) {
        lVar5 = (longlong)rx_buffers + lVar11 + 0x2a;
        local_res8[0] = *(undefined4 *)(lVar5 + 0x10);
        lVar5 = iscsiDhcpFindOption(lVar5,((uint)(ushort)(*(short *)(lVar11 + 0x26 +
                                                                    (longlong)rx_buffers) << 8) |
                                          (uint)*(byte *)(lVar11 + 0x27 + (longlong)rx_buffers)) - 8
                                    ,'6');
        local_res10[0] = *(undefined4 *)(lVar5 + 2);
        lVar5 = iscsiGetTicks();
        do {
          lVar7 = iscsiGetTicks();
          if ((int)lVar5 + 2000U < (uint)lVar7) break;
          iVar3 = iscsiInitDhcpPacket((undefined1 *)(lVar12 + 0x1ca),3,local_res10,local_res8);
          iscsiDhcpSendPacket(lVar12 + 0x1a0,(ushort)iVar3);
          iVar3 = iscsiDhcpWaitForResponses(2);
        } while (iVar3 < 1);
      }
      uVar10 = uVar10 + 1;
      lVar11 = lVar11 + 0x5ea;
      lVar13 = lVar13 + -1;
    } while (lVar13 != 0);
  }
  uVar8 = 0;
LAB_1400067c7:
  memset(rx_buffers,0,(longlong)iVar2 * 0x5ea);
  return uVar8;
}



===== iscsiDhcpFindOption @ 1400067f8 =====

longlong iscsiDhcpFindOption(longlong param_1,int param_2,char param_3)

{
  u_long uVar1;
  longlong lVar2;
  
  if (((byte)(param_3 - 1U) < 0xfe) &&
     (uVar1 = htonl(0x63825363), *(u_long *)(param_1 + 0xec) == uVar1)) {
    lVar2 = iscsiDhcpFindRetrieveOption(param_1 + 0xf0,param_2 + -0xf0,param_3);
    return lVar2;
  }
  return 0;
}



===== iscsiDhcpFindRetrieveOption @ 140006854 =====

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



===== iscsiDhcpFindRetrieveVendorOption @ 140006898 =====

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
      if (0x80 < uVar7) goto LAB_140006af5;
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
LAB_140006af5:
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



===== iscsiDhcpRetrieveInfo @ 140006afc =====

undefined8 iscsiDhcpRetrieveInfo(int *param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  int *piVar3;
  uint uVar4;
  longlong lVar5;
  
  memset(param_1,0,0xda);
  *param_1 = *(int *)(param_2 + 0x10);
  lVar1 = iscsiDhcpFindOption(param_2,param_3,'6');
  if ((lVar1 != 0) && (*(char *)(lVar1 + 1) == '\x04')) {
    param_1[1] = *(int *)(lVar1 + 2);
  }
  lVar1 = iscsiDhcpFindOption(param_2,param_3,'\x06');
  if (lVar1 != 0) {
    uVar4 = (uint)*(byte *)(lVar1 + 1);
    piVar3 = param_1 + 4;
    lVar5 = 2;
    do {
      if (3 < (int)uVar4) {
        *piVar3 = *(int *)((lVar1 - (longlong)param_1) + -0xe + (longlong)piVar3);
      }
      uVar4 = uVar4 - 4;
      piVar3 = piVar3 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  lVar1 = iscsiDhcpFindOption(param_2,param_3,'\x03');
  if ((lVar1 != 0) && (3 < *(byte *)(lVar1 + 1))) {
    param_1[3] = *(int *)(lVar1 + 2);
  }
  lVar1 = iscsiDhcpFindOption(param_2,param_3,'\x01');
  if ((lVar1 != 0) && (*(char *)(lVar1 + 1) == '\x04')) {
    param_1[2] = *(int *)(lVar1 + 2);
  }
  *(undefined1 *)(param_1 + 6) = 0;
  lVar1 = iscsiDhcpFindOption(param_2,param_3,'\x11');
  if (lVar1 != 0) {
    uVar4 = (uint)*(byte *)(lVar1 + 1);
    if (0x80 < *(byte *)(lVar1 + 1)) {
      uVar4 = 0x80;
    }
    memmove(param_1 + 6,(void *)(lVar1 + 2),(ulonglong)uVar4);
    *(undefined1 *)((ulonglong)uVar4 + 0x18 + (longlong)param_1) = 0;
  }
  *(undefined1 *)((longlong)param_1 + 0x99) = 0;
  lVar1 = iscsiDhcpFindOption(param_2,param_3,'\f');
  if (lVar1 != 0) {
    uVar4 = (uint)*(byte *)(lVar1 + 1);
    if (0x40 < *(byte *)(lVar1 + 1)) {
      uVar4 = 0x40;
    }
    memmove((undefined1 *)((longlong)param_1 + 0x99),(void *)(lVar1 + 2),(ulonglong)uVar4);
    *(undefined1 *)((ulonglong)uVar4 + 0x99 + (longlong)param_1) = 0;
  }
  if ((*param_1 == 0) || (param_1[2] == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== iscsiDhcpRetrieveStandardInfo @ 140006c7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 iscsiDhcpRetrieveStandardInfo(longlong param_1,int param_2)

{
  char cVar1;
  undefined8 uVar2;
  longlong lVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 auStack_118 [32];
  int local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  char local_e0;
  char local_5f [71];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  uVar2 = iscsiDhcpRetrieveInfo(&local_f8,param_1,param_2);
  if ((int)uVar2 != 0) {
    lVar3 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    if ((*(uint *)(lVar3 + 4) & 0x20000) != 0) {
      *(int *)(lVar3 + 0x458) = local_f8;
      *(int *)(*(longlong *)
                (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
              0x488) = local_f8;
      *(undefined4 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x468) = local_f0;
      *(undefined4 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x478) = local_ec;
      *(undefined4 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x4a8) = local_e8;
      *(undefined4 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x4b8) = local_e4;
      *(undefined4 *)
       (*(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
       0x498) = local_f4;
    }
    lVar3 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    if ((((*(uint *)(lVar3 + 4) & 0x40000) != 0) && (*(char *)(lVar3 + 0x281) == '\0')) &&
       (local_e0 != '\0')) {
      iscsiBootCancel();
    }
    if (local_5f[0] == '\0') {
      lVar3 = 0;
      do {
        cVar1 = "iscsiboot"[lVar3];
        local_5f[lVar3] = cVar1;
        lVar3 = lVar3 + 1;
      } while (cVar1 != '\0');
    }
    else {
      itolowerstr(local_5f);
    }
    pcVar5 = local_5f;
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



===== iscsiDhcpSendPacket @ 140006e4c =====

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



===== iscsiDhcpWaitForResponses @ 140006fa8 =====

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



===== iscsiDisconnect @ 1400070b8 =====

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



===== iscsiExtractRedirectInfo @ 14000710c =====

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



===== iscsiFindKeyValue @ 14000721c =====

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



===== iscsiGetDevFamily @ 14000728c =====

undefined8 iscsiGetDevFamily(short param_1)

{
  short sVar1;
  int7 iVar3;
  undefined8 uVar2;
  longlong lVar4;
  int iVar5;
  
  iVar5 = 0;
  if (supported_device_table != 0) {
    lVar4 = 0;
    sVar1 = supported_device_table;
    do {
      if (sVar1 == param_1) break;
      lVar4 = lVar4 + 1;
      iVar5 = iVar5 + 1;
      sVar1 = (&supported_device_table)[lVar4 * 0xc];
    } while (sVar1 != 0);
  }
  iVar3 = (int7)(int3)((uint)iVar5 >> 8);
  uVar2 = CONCAT71(iVar3,0xfe);
  if ((&supported_device_table)[(longlong)iVar5 * 0xc] != 0) {
    uVar2 = CONCAT71(iVar3,(&DAT_140031030)[(longlong)iVar5 * 0x18]);
  }
  return uVar2;
}



===== iscsiInitDhcpPacket @ 1400072d8 =====

int iscsiInitDhcpPacket(undefined1 *param_1,short param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  u_long *puVar2;
  u_long uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  int iVar7;
  
  puVar2 = (u_long *)(param_1 + 0xec);
  memset(param_1,0,0x4ec);
  *(undefined2 *)(param_1 + 1) = 0x601;
  dhcp_transaction_id = dhcp_transaction_id + 1;
  *(int *)(param_1 + 4) = dhcp_transaction_id;
  lVar6 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(lVar6 + 0x12);
  *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(lVar6 + 0x16);
  dhcp_transaction_id = dhcp_transaction_id + 1;
  *(int *)(param_1 + 4) = dhcp_transaction_id;
  *(ushort *)(param_1 + 8) = seconds << 8 | seconds >> 8;
  uVar3 = htonl(0x63825363);
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
  uVar4 = 7;
  param_1[0xf2] = (char)param_2;
  if (param_2 == 3) {
    *(undefined2 *)(param_1 + 0xf3) = 0x432;
    uVar4 = 0x13;
    *(undefined4 *)(param_1 + 0xf5) = *param_4;
    *(undefined2 *)(param_1 + 0xf9) = 0x436;
    *(undefined4 *)(param_1 + 0xfb) = *param_3;
  }
  lVar6 = -1;
  *(undefined1 *)((ulonglong)uVar4 + (longlong)puVar2) = 0x3c;
  do {
    lVar6 = lVar6 + 1;
  } while (*(char *)(*(longlong *)
                      (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
                     + 0x58 + lVar6) != '\0');
  *(char *)((ulonglong)(uVar4 + 1) + (longlong)puVar2) = (char)lVar6;
  memmove((void *)((ulonglong)(uVar4 + 2) + (longlong)puVar2),
          (void *)(*(longlong *)
                    (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8) +
                  0x58),(longlong)(int)lVar6);
  iVar7 = uVar4 + 2 + (int)lVar6;
  *(undefined1 *)((longlong)iVar7 + (longlong)puVar2) = 0x37;
  *(undefined1 *)((longlong)(iVar7 + 2) + (longlong)puVar2) = 1;
  *(undefined1 *)((longlong)(iVar7 + 3) + (longlong)puVar2) = 3;
  *(undefined1 *)((longlong)(iVar7 + 4) + (longlong)puVar2) = 6;
  iVar5 = iVar7 + 6;
  *(undefined1 *)((longlong)(iVar7 + 5) + (longlong)puVar2) = 0xc;
  *(undefined1 *)((longlong)iVar5 + (longlong)puVar2) = 0xf;
  *(undefined1 *)((longlong)iVar5 + 1 + (longlong)puVar2) = 0x11;
  iVar1 = iVar7 + 10;
  *(undefined1 *)((longlong)(iVar7 + 2) + 6 + (longlong)puVar2) = 0x2b;
  *(undefined1 *)((longlong)(iVar7 + 8) + 1 + (longlong)puVar2) = 0x3c;
  *(char *)((longlong)iVar7 + 1 + (longlong)puVar2) = ((char)iVar1 - ((char)iVar7 + '\x01')) + -1;
  *(undefined1 *)((longlong)(iVar7 + 3) + 7 + (longlong)puVar2) = 0x39;
  *(undefined1 *)((longlong)iVar1 + 1 + (longlong)puVar2) = 2;
  *(undefined2 *)((longlong)iVar1 + 2 + (longlong)puVar2) = 0xec04;
  *(undefined1 *)((longlong)iVar5 + 8 + (longlong)puVar2) = 0xff;
  return iVar7 + 0xfb;
}



===== iscsiIsSupportedAdapter @ 1400074e0 =====

undefined8 iscsiIsSupportedAdapter(short param_1,short param_2)

{
  short sVar1;
  longlong lVar2;
  
  if (((param_1 == 0x14e4) || (param_1 == 0x1077)) && (supported_device_table != 0)) {
    lVar2 = 0;
    sVar1 = supported_device_table;
    do {
      if (sVar1 == param_2) {
        return 1;
      }
      lVar2 = lVar2 + 1;
      sVar1 = (&supported_device_table)[lVar2 * 0xc];
    } while (sVar1 != 0);
  }
  return 0;
}



===== iscsiL2AddMcAddr @ 14000752c =====

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



===== iscsiL2IsOurMcAddr @ 1400075d0 =====

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



===== iscsiParseIPv6AddrString @ 140007630 =====

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



===== iscsiServiceTimer @ 140007804 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void iscsiServiceTimer(void)

{
  ushort *puVar1;
  
  puVar1 = &DAT_14003a7a2;
  do {
    if ((puVar1[-1] == 1) && (*puVar1 <= puVar1[1])) {
      (**(code **)(puVar1 + 3))();
      puVar1[1] = 0;
    }
    puVar1 = puVar1 + 8;
  } while ((longlong)puVar1 < 0x14003a822);
  return;
}



===== iscsiSessionConnStackCallback @ 140007850 =====

void iscsiSessionConnStackCallback(undefined8 param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined4 *)(iscsiGlobalsPtr + 0x174) = 1;
  }
  return;
}



===== iscsiSessionDefaultInit @ 140007868 =====

void iscsiSessionDefaultInit(longlong param_1)

{
  u_long uVar1;
  
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
  uVar1 = htonl(0x4000113d);
  *(u_long *)(param_1 + 0x74) = uVar1;
  *(undefined2 *)(param_1 + 0x78) = 0;
  CrashDumpInitSessionBuffer(param_1);
  *(undefined4 *)(param_1 + 300) = 0xffffffff;
  return;
}



===== iscsiSessionDoRedirect @ 1400078dc =====

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



===== iscsiSessionGetTxHdrBuf @ 140007924 =====

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
    puVar1 = &DAT_140081b50;
  }
  return puVar1;
}



===== iscsiSessionHeartBeat @ 140007980 =====

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
  return;
}



===== iscsiSessionIsTxCompleted @ 140007ad4 =====

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



===== iscsiSessionProcessDelaySendNopOut @ 140007b24 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 iscsiSessionProcessDelaySendNopOut(int param_1)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar1 = 0xffffffff;
  if ((*(int *)(iscsiGlobalsPtr + 0x188) != 0) && (*(char *)(iscsiGlobalsPtr + 0x17fc) == '\0')) {
    *(undefined1 *)(iscsiGlobalsPtr + 0x17fc) = 1;
    uRam0000000140081b58 = 0;
    _DAT_140081b68 = 0;
    _DAT_140081b50 = 0x8000;
    _DAT_140081b70 = 0;
    _DAT_140081b78 = 0;
    _DAT_140081b60 = (ulonglong)*(uint *)(iscsiGlobalsPtr + 0x18c) << 0x20;
    iscsiSessionSendIscsiCmd(&DAT_140081b50,0,0,0);
    uVar2 = param_1 + system_ticks;
    do {
      if (uVar2 <= system_ticks) goto LAB_140007bdd;
      iscsiProcessLoop(1);
    } while (*(int *)(iscsiGlobalsPtr + 0x78c) != 0);
    *(undefined4 *)(iscsiGlobalsPtr + 0x188) = 0;
    uVar1 = 0;
LAB_140007bdd:
    *(undefined1 *)(iscsiGlobalsPtr + 0x17fc) = 0;
  }
  return uVar1;
}



===== iscsiSessionProcessLogin @ 140007bf8 =====

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
                        ((longlong)param_1,(undefined8 *)&DAT_140081b50,*(void **)(param_1 + 0xa8),
                         0x2000);
      if ((int)uVar2 == 0) {
        param_1[1] = 0;
      }
      else {
        *(undefined8 *)(iscsiGlobalsPtr + 0xe8) = *(undefined8 *)(iscsiGlobalsPtr + 0x158);
        *(uint *)(iscsiGlobalsPtr + 0xf0) =
             (uint)CONCAT21(CONCAT11(DAT_140081b55,DAT_140081b56),DAT_140081b57);
        iscsiSessionSendProtocolData(0x140081b50,1);
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



===== iscsiSessionProcessRxIscsiPdu @ 140007d40 =====

undefined4 iscsiSessionProcessRxIscsiPdu(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  u_long uVar5;
  u_long uVar6;
  u_long uVar7;
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
  uVar4 = *(ushort *)(&DAT_140031640 + ((ulonglong)bVar11 & 0xffffffffffffffdf) * 2);
  if ((bVar3 & 0x20) == 0) {
    return 0xffffffff;
  }
  if ((uVar4 & 0x800) != 0) {
    return 0xffffffff;
  }
  if (((uVar4 & 0x400) != 0) && (-1 < (char)param_1[1])) {
    return 0xffffffff;
  }
  uVar5 = htonl(*(u_long *)(param_1 + 0x10));
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
  if ((bVar11 == 0x25) && ((param_1[1] & 1) == 0)) goto LAB_140007e76;
  uVar6 = htonl(*(u_long *)(param_1 + 0x18));
  if ((uVar6 == *(u_long *)(iscsiGlobalsPtr + 0x40)) || (bVar11 != 0x22)) {
LAB_140007e5a:
    if ((bVar11 == 0x31) || ((bVar11 == 0x20 && (*(int *)(param_1 + 0x10) == -1))))
    goto LAB_140007e76;
  }
  else if (0 < (int)(uVar6 - *(u_long *)(iscsiGlobalsPtr + 0x40))) {
    *(u_long *)(iscsiGlobalsPtr + 0x40) = uVar6;
    goto LAB_140007e5a;
  }
  *(int *)(iscsiGlobalsPtr + 0x40) = *(int *)(iscsiGlobalsPtr + 0x40) + 1;
LAB_140007e76:
  uVar6 = *(u_long *)(param_1 + 0x20);
  uVar7 = htonl(*(u_long *)(param_1 + 0x1c));
  uVar6 = htonl(uVar6);
  if (-1 < (int)((uVar6 - uVar7) + 1)) {
    if (0 < (int)(uVar6 - *(int *)(iscsiGlobalsPtr + 0x3c))) {
      *(u_long *)(iscsiGlobalsPtr + 0x3c) = uVar6;
    }
    if ((0 < (int)(uVar7 - *(int *)(iscsiGlobalsPtr + 0x38))) &&
       (-1 < (int)(*(int *)(iscsiGlobalsPtr + 0x34) - uVar7))) {
      *(u_long *)(iscsiGlobalsPtr + 0x38) = uVar7;
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
        if ((pbVar10 + -0x14002d740)[(longlong)pbVar9] != *pbVar9) {
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
      if (*(u_long *)(iscsiGlobalsPtr + 0x30) == uVar5) {
        *(undefined1 *)(iscsiGlobalsPtr + 0x70) = 0xff;
        return 0;
      }
      return 0;
    }
    if (bVar11 == 0x31) {
      uVar5 = htonl(*(u_long *)(param_1 + 0x2c));
      uVar6 = htonl(*(u_long *)(param_1 + 0x28));
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



===== iscsiSessionRxPdu @ 140008164 =====

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



===== iscsiSessionSendDataOutCmd @ 14000836c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 iscsiSessionSendDataOutCmd(longlong param_1,undefined4 param_2,uint param_3)

{
  uRam0000000140081b58 = 0;
  _DAT_140081b68 = 0;
  _DAT_140081b60 = (ulonglong)param_3 << 0x20;
  _DAT_140081b50 =
       CONCAT16((char)((uint)param_2 >> 8),CONCAT15((char)((uint)param_2 >> 0x10),0x8000));
  _DAT_140081b70 = 0;
  _DAT_140081b78 = 0;
  _DAT_140081b50 = CONCAT71(_DAT_140081b50 >> 8,5);
  _DAT_140081b50 = CONCAT17((char)param_2,_DAT_140081b50);
  iscsiSessionSendIscsiCmd(&DAT_140081b50,1,param_1,param_2);
  return 0;
}



===== iscsiSessionSendDataOutWithR2T @ 1400083d8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 iscsiSessionSendDataOutWithR2T(byte *param_1,undefined8 param_2,uint param_3)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  u_long uVar6;
  undefined8 uVar7;
  ushort uVar8;
  uint uVar9;
  u_long netlong;
  ushort uVar10;
  
  lVar3 = iscsiGlobalsPtr;
  iscsiSessionSendIscsiCmd(param_1,2,0,0);
  *(undefined8 *)(lVar3 + 0xe8) = param_2;
  *(uint *)(lVar3 + 0xf0) = param_3;
  *(undefined4 *)(lVar3 + 0x17c) = 0;
  if (param_3 != 0) {
    do {
      *(undefined1 *)(lVar3 + 0xe0) = 0xff;
      *(undefined4 *)(lVar3 + 0x178) = 1;
      lVar4 = iscsiGlobalsPtr;
      uVar9 = system_ticks + 16000;
      do {
        if (uVar9 <= system_ticks) {
          return 0xffffffff;
        }
        iscsiProcessLoop(1);
      } while (*(int *)(iscsiGlobalsPtr + 0x178) != 0);
      uVar8 = *(ushort *)(lVar4 + 0x180);
      netlong = 0;
      lVar2 = *(longlong *)(iscsiGlobalsPtr + 0xe8);
      uVar1 = *(ushort *)(lVar4 + 0x182);
      if (uVar8 != 0) {
        do {
          uRam0000000140081b58 = 0;
          _DAT_140081b50 = 5;
          _DAT_140081b68 = 0;
          _DAT_140081b70 = 0;
          _DAT_140081b78 = 0;
          if ((uint)uVar8 < *(uint *)(lVar4 + 0x50)) {
            uVar10 = uVar8;
          }
          else {
            uVar10 = *(ushort *)(lVar4 + 0x50);
          }
          _DAT_140081b60 = (ulonglong)*(uint *)(lVar4 + 0x184) << 0x20;
          uVar8 = uVar8 - uVar10;
          uVar6 = htonl(netlong * *(int *)(lVar4 + 0x50) + (uint)uVar1);
          _DAT_140081b78 = CONCAT44(DAT_140081b78_4,uVar6);
          bVar5 = DAT_140081b51 & 0x7f;
          _DAT_140081b50 = CONCAT11(~-(uVar8 != 0) & 0x80U | bVar5,DAT_140081b50);
          uVar6 = htonl(netlong);
          _DAT_140081b70 = CONCAT44(uVar6,_DAT_140081b70);
          _DAT_140081b50 = CONCAT17((char)uVar10,CONCAT16((char)(uVar10 >> 8),_DAT_140081b50));
          _DAT_140081b50 = CONCAT26(_DAT_140081b56,_DAT_140081b50) & 0xffff00ffffffffff;
          iscsiSessionSendIscsiCmd
                    (&DAT_140081b50,3,
                     (ulonglong)(netlong * *(int *)(lVar4 + 0x50)) + (ulonglong)uVar1 + lVar2,
                     (uint)uVar10);
          uVar7 = iscsiSessionIsTxCompleted();
          if ((int)uVar7 != 1) {
            return 0xffffffff;
          }
          *(int *)(lVar4 + 0x17c) = *(int *)(lVar4 + 0x17c) + (uint)uVar10;
          netlong = netlong + 1;
        } while (uVar8 != 0);
      }
    } while (*(uint *)(lVar3 + 0x17c) < param_3);
  }
  *(int *)(lVar3 + 0x30) = *(int *)(lVar3 + 0x30) + 1;
  *(int *)(lVar3 + 0x34) = *(int *)(lVar3 + 0x34) + 1;
  return 0;
}



===== iscsiSessionSendIscsiCmd @ 1400085c4 =====

undefined8 iscsiSessionSendIscsiCmd(byte *param_1,short param_2,longlong param_3,undefined4 param_4)

{
  u_long uVar1;
  longlong lVar2;
  
  if (param_2 == 0) {
    param_1[0x10] = 0xff;
    param_1[0x11] = 0xff;
    param_1[0x12] = 0xff;
    param_1[0x13] = 0xff;
    *param_1 = *param_1 | 0x40;
    uVar1 = htonl(*(u_long *)(iscsiGlobalsPtr + 0x34));
    *(u_long *)(param_1 + 0x18) = uVar1;
  }
  else if (param_2 == 1) {
    uVar1 = htonl(*(u_long *)(iscsiGlobalsPtr + 0x34));
    *(u_long *)(param_1 + 0x18) = uVar1;
    if ((*param_1 & 0x40) == 0) {
      *(int *)(iscsiGlobalsPtr + 0x34) = *(int *)(iscsiGlobalsPtr + 0x34) + 1;
    }
    uVar1 = htonl(*(u_long *)(iscsiGlobalsPtr + 0x30));
    *(u_long *)(param_1 + 0x10) = uVar1;
    *(int *)(iscsiGlobalsPtr + 0x30) = *(int *)(iscsiGlobalsPtr + 0x30) + 1;
    if (*(int *)(iscsiGlobalsPtr + 0x30) == -1) {
      *(undefined4 *)(iscsiGlobalsPtr + 0x30) = 0;
    }
  }
  else {
    if (param_2 == 2) {
      uVar1 = htonl(*(u_long *)(iscsiGlobalsPtr + 0x34));
      *(u_long *)(param_1 + 0x18) = uVar1;
    }
    else if (param_2 != 3) goto LAB_140008696;
    uVar1 = htonl(*(u_long *)(iscsiGlobalsPtr + 0x30));
    *(u_long *)(param_1 + 0x10) = uVar1;
  }
LAB_140008696:
  lVar2 = 0xce;
  do {
    *(ushort *)(param_1 + lVar2 + -0xc6) =
         *(short *)(lVar2 + iscsiGlobalsPtr) << 8 | (ushort)*(byte *)(lVar2 + 1 + iscsiGlobalsPtr);
    lVar2 = lVar2 + 2;
  } while (lVar2 < 0xd6);
  uVar1 = htonl(*(u_long *)(iscsiGlobalsPtr + 0x40));
  *(u_long *)(param_1 + 0x1c) = uVar1;
  *(undefined1 *)(iscsiGlobalsPtr + 0xe0) = 0xff;
  *(longlong *)(iscsiGlobalsPtr + 0xe8) = param_3;
  *(undefined4 *)(iscsiGlobalsPtr + 0xf0) = param_4;
  iscsiSessionSendProtocolData((longlong)param_1,(uint)(param_3 != 0));
  return 0;
}



===== iscsiSessionSendProtocolData @ 14000872c =====

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
    if (uVar1 < 0x31) goto LAB_14000884f;
    lVar6 = *(longlong *)(lVar2 + 0xe8);
    uVar5 = *(undefined8 *)(lVar2 + 0x10);
    uVar8 = 1;
    uVar7 = uVar1 - 0x30;
  }
  stack_write_tcp_data(uVar5,lVar6,uVar7,uVar8);
LAB_14000884f:
  stack_flush_tcp_data(*(undefined8 *)(lVar2 + 0x10));
  *(undefined2 *)(iscsiGlobalsPtr + 0xd88) = 1;
  *(uint *)(iscsiGlobalsPtr + 0x790) = (uint)uVar1;
  *(undefined4 *)(iscsiGlobalsPtr + 0x78c) = 0;
  return 0;
}



===== iscsiSessionSendWriteData @ 1400088a0 =====

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
    }
  }
  else {
    *param_1 = *param_1 | 0x40;
    param_1[5] = (byte)(param_4 >> 0x10);
    param_1[6] = (byte)(param_4 >> 8);
    param_1[7] = (byte)param_4;
    iscsiSessionSendIscsiCmd(param_1,2,param_3,param_4);
  }
  return 0;
}



===== iscsiSessionServiceRxIndication @ 140008944 =====

void iscsiSessionServiceRxIndication(char *param_1,uint param_2)

{
  undefined8 *puVar1;
  byte bVar2;
  longlong lVar3;
  ushort *puVar4;
  
  lVar3 = iscsiGlobalsPtr;
  puVar4 = (ushort *)(iscsiGlobalsPtr + 8);
  bVar2 = *(byte *)(iscsiGlobalsPtr + 0xb);
  if (2 < bVar2) {
    if (bVar2 < 5) {
      puVar1 = (undefined8 *)(iscsiGlobalsPtr + 0x160);
      *puVar4 = *puVar4 | 2;
      *(undefined8 *)(lVar3 + 0xe8) = *puVar1;
      iscsiSessionRxPdu((byte *)puVar4,param_1,param_2 & 0xffff);
      if (*(short *)(iscsiGlobalsPtr + 0xd86) == 1) {
        iscsiSessionProcessLogin(puVar4);
      }
    }
    else if (bVar2 == 5) {
      iscsiSessionRxPdu((byte *)puVar4,param_1,param_2 & 0xffff);
      if (*(short *)(iscsiGlobalsPtr + 0xd86) == 1) {
        iscsiSessionProcessRxIscsiPdu((byte *)(iscsiGlobalsPtr + 0x794));
        *(undefined2 *)(iscsiGlobalsPtr + 0xd86) = 0;
        *(undefined4 *)(iscsiGlobalsPtr + 0xd78) = 0;
        *(undefined4 *)(iscsiGlobalsPtr + 0xd7c) = 0;
        return;
      }
    }
    else if (bVar2 == 6) {
      iscsiAbortRoutine();
      return;
    }
  }
  return;
}



===== iscsiSessionStart @ 140008a18 =====

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



===== iscsiSessionStop @ 140008bc8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void iscsiSessionStop(longlong param_1)

{
  u_long uVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 0x68) == '\x03') {
    uRam0000000140081b58 = 0;
    _DAT_140081b50 = 0x8006;
    uVar2 = system_ticks + 1000;
    _DAT_140081b60 = 0;
    _DAT_140081b68 = 0;
    _DAT_140081b70 = 0;
    _DAT_140081b78 = 0;
    uVar1 = htonl(*(u_long *)(param_1 + 0x28));
    _DAT_140081b60 = CONCAT44(_DAT_140081b64,uVar1);
    uVar1 = htonl(*(u_long *)(param_1 + 0x2c));
    _DAT_140081b68 = CONCAT44(_DAT_140081b6c,uVar1);
    uVar1 = htonl(*(u_long *)(param_1 + 0x38));
    _DAT_140081b68 = CONCAT44(uVar1,_DAT_140081b68);
    iscsiSessionSendProtocolData(0x140081b50,0);
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



===== iscsiSessionTxState @ 140008c80 =====

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
      uVar5 = iscsi_make_login_pdu(lVar1,(undefined8 *)&DAT_140081b50,(void *)*puVar2,0x2000);
      if ((int)uVar5 == 0) {
        *(undefined2 *)(lVar4 + 10) = 0x608;
        return;
      }
      *(undefined8 *)(iscsiGlobalsPtr + 0xe8) = *(undefined8 *)(iscsiGlobalsPtr + 0x158);
      *(uint *)(iscsiGlobalsPtr + 0xf0) =
           (uint)CONCAT21(CONCAT11(DAT_140081b55,DAT_140081b56),DAT_140081b57);
      iscsiSessionSendProtocolData(0x140081b50,1);
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



===== iscsiSessionWaitForCommandDone @ 140008dd0 =====

undefined1 iscsiSessionWaitForCommandDone(void)

{
  uint uVar1;
  
  uVar1 = system_ticks + 16000;
  while ((system_ticks < uVar1 && (*(char *)(iscsiGlobalsPtr + 0xe0) == -1))) {
    iscsiProcessLoop(1);
  }
  return *(undefined1 *)(iscsiGlobalsPtr + 0xe0);
}



===== iscsiSetupCmd @ 140008e1c =====

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



===== iscsiTimerTick @ 140008e30 =====

void iscsiTimerTick(void)

{
  bool bVar1;
  ushort *puVar2;
  longlong lVar3;
  
  bVar1 = false;
  puVar2 = &DAT_14003a7a4;
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



===== iscsi_make_login_pdu @ 140008e8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 iscsi_make_login_pdu(longlong param_1,undefined8 *param_2,void *param_3,uint param_4)

{
  char cVar1;
  bool bVar2;
  u_long uVar3;
  uint uVar4;
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
  char *pcVar5;
  char *pcVar6;
  ulonglong uVar7;
  char *pcVar8;
  longlong lVar10;
  longlong lVar9;
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
  uVar3 = htonl(*(u_long *)(param_1 + 0x28));
  *(u_long *)(param_2 + 2) = uVar3;
  uVar3 = htonl(*(u_long *)(param_1 + 0x2c));
  *(undefined2 *)((longlong)param_2 + 2) = 0;
  *(u_long *)(param_2 + 3) = uVar3;
  *(undefined2 *)((longlong)param_2 + 0x14) = 0x100;
  uVar3 = htonl(*(u_long *)(param_1 + 0x38));
  *(u_long *)((longlong)param_2 + 0x1c) = uVar3;
  cVar1 = *(char *)(param_1 + 0x68);
  if (cVar1 == -1) {
    pcVar5 = *(char **)(param_1 + 0xb0);
    if (pcVar5 == (char *)0x0) {
      return 0;
    }
    if (*pcVar5 == '\0') {
      return 0;
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"InitiatorName",pcVar5)
    ;
    if ((int)CONCAT71(extraout_var,bVar2) == 0) {
      return 0;
    }
    pcVar5 = *(char **)(param_1 + 0xb8);
    if (((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) &&
       (bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"InitiatorAlias",
                             pcVar5), (int)CONCAT71(extraout_var_00,bVar2) == 0)) {
      return 0;
    }
    if ((**(char **)(param_1 + 0xa8) != '\0') &&
       (bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"TargetName",
                             *(char **)(param_1 + 0xa8)), (int)CONCAT71(extraout_var_01,bVar2) == 0)
       ) {
      return 0;
    }
    pcVar5 = "Normal";
    if (*(int *)(param_1 + 100) == 1) {
      pcVar5 = "Discovery";
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,&s_SessionType,pcVar5);
    if ((int)CONCAT71(extraout_var_02,bVar2) == 0) {
      return 0;
    }
    pcVar5 = "CHAP";
    if (*(int *)(param_1 + 0x10) == 0) {
      pcVar5 = "None";
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,&s_AuthMethod,pcVar5);
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
      pcVar5 = *(char **)(param_1 + 0x160);
      bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"CHAP_N",
                           *(void **)(param_1 + 0x118));
      if ((int)CONCAT71(extraout_var_18,bVar2) == 0) {
        return 0;
      }
      lVar9 = -1;
      do {
        lVar10 = lVar9;
        lVar9 = lVar10 + 1;
      } while (*(char *)(*(longlong *)(param_1 + 0x120) + lVar9) != '\0');
      *pcVar5 = *(char *)(param_1 + 0x128);
      pcVar8 = *(char **)(param_1 + 0x120);
      pcVar6 = pcVar5;
      do {
        pcVar6 = pcVar6 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        *pcVar6 = cVar1;
      } while (cVar1 != '\0');
      memmove(pcVar5 + ((int)lVar10 + 2),*(void **)(param_1 + 0x130),
              (longlong)*(int *)(param_1 + 300));
      MD5_ProcessMessage((undefined8 *)pcVar5,*(int *)(param_1 + 300) + 1 + (int)lVar9,
                         (int *)local_158);
      iint_to_hexstr(local_158,0x10,(undefined2 *)pcVar5);
      uVar7 = (ulonglong)param_4;
      bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"CHAP_R",pcVar5);
      if ((int)CONCAT71(extraout_var_19,bVar2) == 0) {
        return 0;
      }
      if (((*(char **)(param_1 + 0x108) != (char *)0x0) && (**(char **)(param_1 + 0x108) != '\0'))
         && ((*(char **)(param_1 + 0x110) != (char *)0x0 && (**(char **)(param_1 + 0x110) != '\0')))
         ) {
        uVar4 = getRandomNumber();
        *(char *)(param_1 + 0x128) = (char)uVar4;
        lVar9 = 0;
        do {
          uVar4 = getRandomNumber();
          *(char *)(lVar9 + *(longlong *)(param_1 + 0x130)) = (char)uVar4;
          lVar9 = lVar9 + 1;
        } while (lVar9 < 0x200);
        *(undefined4 *)(param_1 + 300) = 0x200;
        isprintf((char *)local_158,"%d",(ulonglong)*(byte *)(param_1 + 0x128),uVar7);
        bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"CHAP_I",local_158)
        ;
        if ((int)CONCAT71(extraout_var_20,bVar2) == 0) {
          return 0;
        }
        iint_to_hexstr(*(byte **)(param_1 + 0x130),*(int *)(param_1 + 300),(undefined2 *)pcVar5);
        bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"CHAP_C",pcVar5);
        if ((int)CONCAT71(extraout_var_21,bVar2) == 0) {
          return 0;
        }
      }
      *(byte *)((longlong)param_2 + 1) =
           ((*(char *)(param_1 + 0x68) << 2 ^ *(byte *)((longlong)param_2 + 1)) & 0xc ^
           *(byte *)((longlong)param_2 + 1)) & 0xfd | 0x81;
      return 1;
    }
    pcVar8 = "5";
    pcVar5 = "CHAP_A";
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
    pcVar8 = "No";
    pcVar5 = "No";
    if (*(int *)(param_1 + 0x40) != 0) {
      pcVar5 = "Yes";
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,&s_InitialR2T,pcVar5);
    if ((int)CONCAT71(extraout_var_06,bVar2) == 0) {
      return 0;
    }
    uVar7 = (ulonglong)param_4;
    if (*(int *)(param_1 + 0x3c) != 0) {
      pcVar8 = "Yes";
    }
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"ImmediateData",pcVar8)
    ;
    if ((int)CONCAT71(extraout_var_07,bVar2) == 0) {
      return 0;
    }
    isprintf(local_148,"%lu",(ulonglong)*(uint *)(param_1 + 0x44),uVar7);
    uVar7 = (ulonglong)param_4;
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,
                         "MaxRecvDataSegmentLength",local_148);
    if ((int)CONCAT71(extraout_var_08,bVar2) == 0) {
      return 0;
    }
    isprintf(local_148,"%lu",(ulonglong)*(uint *)(param_1 + 0x50),uVar7);
    uVar7 = (ulonglong)param_4;
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"MaxBurstLength",
                         local_148);
    if ((int)CONCAT71(extraout_var_09,bVar2) == 0) {
      return 0;
    }
    isprintf(local_148,"%lu",(ulonglong)*(uint *)(param_1 + 0x4c),uVar7);
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
    uVar7 = (ulonglong)param_4;
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"MaxConnections",&s_1);
    if ((int)CONCAT71(extraout_var_12,bVar2) == 0) {
      return 0;
    }
    isprintf(local_148,"%u",(ulonglong)*(uint *)(param_1 + 0x5c),uVar7);
    uVar7 = (ulonglong)param_4;
    bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,"DefaultTime2Wait",
                         local_148);
    if ((int)CONCAT71(extraout_var_13,bVar2) == 0) {
      return 0;
    }
    isprintf(local_148,"%u",(ulonglong)*(uint *)(param_1 + 0x60),uVar7);
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
    pcVar8 = "Yes";
    pcVar5 = "DataSequenceInOrder";
  }
  bVar2 = iscsiAddText(param_1,(longlong)param_2,(longlong)param_3,param_4,pcVar5,pcVar8);
  if ((int)CONCAT71(extraout_var_17,bVar2) == 0) {
    return 0;
  }
  return 1;
}



===== iscsi_process_login_response @ 1400095d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 iscsi_process_login_response(byte *param_1,longlong param_2,char *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  u_long uVar5;
  undefined8 uVar6;
  ulonglong uVar8;
  ulonglong uVar7;
  byte bVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  bool bVar16;
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
    pcVar15 = param_3 + CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6))
                                 ,*(undefined1 *)(param_2 + 7));
    if (pcVar15 < param_3 + param_4) {
      *pcVar15 = '\0';
joined_r0x00014000969b:
      do {
        pcVar13 = param_3;
        if ((pcVar13 == (char *)0x0) || (uVar7 = 0xffffffffffffffff, pcVar15 <= pcVar13)) {
LAB_140009dfb:
          *(ushort *)(param_1 + 0x7a) =
               *(short *)(param_2 + 0xe) << 8 | (ushort)*(byte *)(param_2 + 0xf);
          uVar5 = htonl(*(u_long *)(param_2 + 0x1c));
          *(u_long *)(param_1 + 0x30) = uVar5;
          uVar5 = htonl(*(u_long *)(param_2 + 0x20));
          *(u_long *)(param_1 + 0x34) = uVar5;
          if (*(char *)(param_2 + 0x24) == '\0') {
            uVar5 = htonl(*(u_long *)(param_2 + 0x18));
            *(u_long *)(param_1 + 0x38) = uVar5 + 1;
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
        } while (pcVar13 < pcVar15);
        if (pcVar15 <= pcVar13) goto LAB_140009dfb;
        if (param_1[0x68] != 0) {
          param_3 = pcVar13;
          if (param_1[0x68] == 1) {
            pcVar14 = pcVar15;
            uVar6 = iscsiFindKeyValue("TargetAlias",pcVar13,pcVar15,(longlong *)&local_e0,&local_e8)
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
                              goto LAB_140009bac;
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
                                        goto LAB_140009dce;
                                      }
                                      iVar2 = istrtol(local_e0,0);
                                      goto LAB_140009c7d;
                                    }
                                    iVar2 = istrtol(local_e0,0);
                                    bVar16 = iVar2 == 1;
                                    goto LAB_140009c7f;
                                  }
                                  if (local_e0 == (byte *)0x0) {
LAB_140009a1b:
                                    uVar3 = 0;
                                  }
                                  else {
                                    iVar2 = istrcmp((char *)local_e0,"Yes");
                                    uVar3 = 1;
                                    if (iVar2 != 0) goto LAB_140009a1b;
                                  }
                                  *(undefined4 *)(param_1 + 0x58) = uVar3;
                                  param_3 = local_e8;
                                }
                                else {
                                  if (local_e0 == (byte *)0x0) {
LAB_1400099cf:
                                    uVar3 = 0;
                                  }
                                  else {
                                    iVar2 = istrcmp((char *)local_e0,"Yes");
                                    uVar3 = 1;
                                    if (iVar2 != 0) goto LAB_1400099cf;
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
LAB_140009810:
                        uVar3 = 0;
                      }
                      else {
                        iVar2 = istrcmp((char *)local_e0,"Yes");
                        uVar3 = 1;
                        if (iVar2 != 0) goto LAB_140009810;
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
          goto joined_r0x00014000969b;
        }
        pcVar14 = pcVar15;
        uVar6 = iscsiFindKeyValue("AuthMethod",pcVar13,pcVar15,(longlong *)&local_e0,&local_e8);
        if ((int)uVar6 == 0) {
          uVar6 = iscsiFindKeyValue("CHAP_A",pcVar13,pcVar14,(longlong *)&local_e0,&local_e8);
          if ((int)uVar6 == 0) {
            uVar6 = iscsiFindKeyValue("CHAP_I",pcVar13,pcVar14,(longlong *)&local_e0,&local_e8);
            if ((int)uVar6 != 0) {
              iVar2 = istrtol(local_e0,0);
              param_1[0x128] = (byte)iVar2;
              param_3 = local_e8;
              goto joined_r0x00014000969b;
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
              goto joined_r0x00014000969b;
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
LAB_140009dce:
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
              goto joined_r0x00014000969b;
            }
            pbVar10 = *(byte **)(param_1 + 0x108);
            pbVar11 = local_e0;
          }
          else {
            pbVar11 = &s_5;
LAB_140009bac:
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
            if (iVar4 == 0) goto joined_r0x00014000969b;
          }
          if (iVar2 != 0) {
            return 4;
          }
          pbVar10 = local_c8;
          pbVar11 = &s_none;
        }
        iVar2 = istrcmp((char *)pbVar10,(char *)pbVar11);
LAB_140009c7d:
        bVar16 = iVar2 == 0;
LAB_140009c7f:
        param_3 = local_e8;
        if (!bVar16) {
          return 4;
        }
      } while( true );
    }
  }
  return 2;
}



===== isprintf @ 140009e88 =====

void isprintf(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  _isprintf(param_1,param_2,(uint *)&local_res18);
  return;
}



===== isscanf @ 140009eac =====

void isscanf(byte *param_1,byte *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  _isscanf(param_1,param_2,&local_res18);
  return;
}



===== istrcmp @ 140009ed0 =====

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



===== istrcpy @ 140009f0c =====

void istrcpy(longlong param_1,char *param_2)

{
  char cVar1;
  longlong lVar2;
  
  lVar2 = param_1 - (longlong)param_2;
  do {
    cVar1 = *param_2;
    param_2[lVar2] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return;
}



===== istrtol @ 140009f1c =====

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
    if (bVar5 != 0x2b) goto LAB_140009f4d;
  }
  bVar1 = bVar2;
  bVar5 = *param_1;
  param_1 = pbVar6 + 2;
LAB_140009f4d:
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



===== itolowerstr @ 140009fec =====

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



===== udp_cksum @ 14000a018 =====

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



===== mem_free @ 14000a0ec =====

void mem_free(undefined *param_1)

{
  uint *puVar1;
  
  if (param_1 != (undefined *)0x0) {
    if ((param_1 < &DAT_14006b450) || (DAT_14006b440 <= param_1)) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("mem_free: legal memory");
    }
    if (((undefined *)((longlong)&DAT_14006b448 + 7U) < param_1) && (param_1 < DAT_14006b440)) {
      puVar1 = (uint *)(param_1 + -0xc);
      if (param_1[-4] == '\0') {
                    /* WARNING: Subroutine does not return */
        DbgPrint("mem_free: mem->used");
      }
      param_1[-4] = 0;
      if (puVar1 < DAT_14006b448) {
        DAT_14006b448 = puVar1;
      }
      plug_holes(puVar1);
    }
  }
  return;
}



===== mem_init @ 14000a180 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_init(void)

{
  memset(&DAT_14006b459,0,0xfff6);
  _DAT_14006b454 = 0;
  DAT_14006b440 = &DAT_14007b44f;
  _DAT_14006b450 = 0xffff;
  DAT_14006b448 = &DAT_14006b450;
  DAT_14006b458 = 0;
  DAT_14007b457 = 1;
  _DAT_14007b44f = 0xffff;
  _DAT_14007b453 = 0xffff;
  DAT_14006b433 = 1;
  return;
}



===== mem_malloc @ 14000a1ec =====

longlong mem_malloc(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  
  puVar3 = DAT_14006b448;
  if (param_1 - 1 < 0xffff) {
    uVar4 = (int)DAT_14006b448 + 0xbff94bb0;
    while (uVar4 < 0xffff) {
      uVar5 = (ulonglong)uVar4;
      puVar1 = (uint *)(&DAT_14006b450 + uVar5);
      if (((&DAT_14006b458)[uVar5] == '\0') && ((ulonglong)param_1 + 0xc <= (*puVar1 - uVar5) - 0xc)
         ) {
        uVar6 = param_1 + 0xc + uVar4;
        puVar2 = (uint *)(&DAT_14006b450 + uVar6);
        *(uint *)(&DAT_14006b454 + uVar6) = uVar4;
        *puVar2 = *puVar1;
        *puVar1 = uVar6;
        if (*puVar2 != 0xffff) {
          *(uint *)(&DAT_14006b454 + *puVar2) = uVar6;
        }
        (&DAT_14006b458)[uVar6] = 0;
        (&DAT_14006b458)[uVar5] = 1;
        if ((puVar1 != puVar3) || ((char)puVar3[2] == '\0')) goto LAB_14000a2d6;
        goto LAB_14000a2a6;
      }
      uVar4 = *puVar1;
    }
  }
  return 0;
  while (uVar4 = *puVar3, puVar3 = (uint *)(&DAT_14006b450 + uVar4), (&DAT_14006b458)[uVar4] != '\0'
        ) {
LAB_14000a2a6:
    if (puVar3 == DAT_14006b440) break;
  }
  DAT_14006b448 = puVar3;
  if ((char)puVar3[2] != '\0') {
                    /* WARNING: Subroutine does not return */
    DbgPrint("mem_malloc: !lfree->used");
  }
LAB_14000a2d6:
  if (DAT_14006b440 < (uint *)((ulonglong)param_1 + 0xc + (longlong)puVar1)) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("mem_malloc: allocated memory not above ram_end.");
  }
  return uVar5 + 0x14006b45c;
}



===== mem_realloc @ 14000a2fc =====

undefined * mem_realloc(undefined *param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 < 0x10000) {
    if ((param_1 < &DAT_14006b450) || (DAT_14006b440 <= param_1)) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("mem_realloc: legal memory");
    }
    if (((undefined *)((longlong)&DAT_14006b448 + 7U) < param_1) && (param_1 < DAT_14006b440)) {
      puVar1 = (uint *)(param_1 + -0xc);
      iVar3 = (int)puVar1 + -0x4006b450;
      if ((ulonglong)param_2 + 0x18 < (ulonglong)((*puVar1 - iVar3) - 0xc)) {
        uVar4 = param_2 + 0xc + iVar3;
        puVar2 = (uint *)(&DAT_14006b450 + uVar4);
        (&DAT_14006b458)[uVar4] = 0;
        *puVar2 = *puVar1;
        *(int *)(&DAT_14006b454 + uVar4) = iVar3;
        *puVar1 = uVar4;
        if (*puVar2 != 0xffff) {
          *(uint *)(&DAT_14006b454 + *puVar2) = uVar4;
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



===== memp_free @ 14000a3b8 =====

void memp_free(int param_1,longlong param_2)

{
  if (param_2 != 0) {
    *(undefined8 *)(param_2 + -8) = (&DAT_14007b460)[param_1];
    (&DAT_14007b460)[param_1] = (undefined8 *)(param_2 + -8);
  }
  return;
}



===== memp_init @ 14000a3d8 =====

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
  
  puVar6 = &DAT_14007b4c0;
  puVar3 = &DAT_14007b460;
  lVar4 = 0;
  lVar8 = 0xb;
  do {
    uVar1 = *(ushort *)((longlong)&DAT_14002f3b8 + lVar4);
    *puVar3 = 0;
    if (uVar1 != 0) {
      uVar2 = *(ushort *)((longlong)&DAT_14002f3a0 + lVar4);
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
  DAT_14006b434 = 1;
  return;
}



===== memp_malloc @ 14000a46c =====

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
  puVar1 = (undefined8 *)(&DAT_14007b460)[param_1];
  if (puVar1 != (undefined8 *)0x0) {
    uVar2 = *puVar1;
    *puVar1 = 0;
    puVar3 = puVar1 + 1;
    (&DAT_14007b460)[param_1] = uVar2;
  }
  return puVar3;
}



===== pbuf_alloc @ 14000a4b0 =====

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
  
  puVar2 = DAT_14006b438;
  uVar7 = (uint)param_2;
  uVar6 = 0;
  if (param_1 == 0) {
    uVar6 = 0x14;
LAB_14000a500:
    uVar6 = uVar6 + 0x28;
LAB_14000a504:
    uVar6 = uVar6 + 0xe;
  }
  else {
    if (param_1 == 1) goto LAB_14000a500;
    if (param_1 == 2) goto LAB_14000a504;
    if (param_1 != 3) {
      pcVar4 = "pbuf_alloc: bad pbuf layer";
      goto LAB_14000a4ee;
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
    goto LAB_14000a6b3;
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
LAB_14000a6b3:
      *(undefined2 *)((longlong)puVar2 + 0x16) = 1;
      return puVar2;
    }
    if (param_3 == 3) {
      if (DAT_14006b430 != '\0') {
        return (undefined8 *)0x0;
      }
      if (DAT_14006b438 != (undefined8 *)0x0) {
        DAT_14006b438 = (undefined8 *)*DAT_14006b438;
      }
      DAT_14006b431 = 0;
      if (puVar2 == (undefined8 *)0x0) {
        DAT_14006b431 = 0;
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
      for (iVar8 = param_2 - uVar7; puVar1 = DAT_14006b438, 0 < iVar8; iVar8 = iVar8 - (uint)uVar6)
      {
        if (DAT_14006b430 != '\0') {
LAB_14000a62f:
          pbuf_free(puVar2);
          return (undefined8 *)0x0;
        }
        if (DAT_14006b438 != (undefined8 *)0x0) {
          DAT_14006b438 = (undefined8 *)*DAT_14006b438;
        }
        DAT_14006b431 = 0;
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000a62f;
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
      goto LAB_14000a6b3;
    }
  }
  pcVar4 = "pbuf_alloc: erroneous flag";
LAB_14000a4ee:
                    /* WARNING: Subroutine does not return */
  DbgPrint(pcVar4);
}



===== pbuf_cat @ 14000a6d8 =====

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



===== pbuf_clen @ 14000a76c =====

char pbuf_clen(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = '\0';
  for (; param_1 != (undefined8 *)0x0; param_1 = (undefined8 *)*param_1) {
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}



===== pbuf_dequeue @ 14000a77c =====

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
  return uVar1;
}



===== pbuf_free @ 14000a7ec =====

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
        *param_1 = DAT_14006b438;
        DAT_14006b438 = param_1;
      }
      else if ((sVar1 == 1) || (sVar1 == 4)) {
        param_1[-1] = DAT_14007b460;
        DAT_14007b460 = param_1 + -1;
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



===== pbuf_header @ 14000a8f4 =====

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
LAB_14000a98d:
        return CONCAT71((int7)(in_RAX >> 8),1);
      }
    }
    else if ((uVar1 == 4) || (uVar1 == 1)) {
      if ((-1 < param_2) ||
         (in_RAX = (ulonglong)*(ushort *)(param_1 + 0x12),
         0 < (int)((int)param_2 - (uint)*(ushort *)(param_1 + 0x12)))) goto LAB_14000a98d;
      *(longlong *)(param_1 + 8) = lVar2 - param_2;
    }
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + param_2;
    *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + param_2;
  }
  return in_RAX & 0xffffffffffffff00;
}



===== pbuf_init @ 14000a994 =====

void pbuf_init(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  lVar3 = 0x80;
  DAT_14006b438 = &DAT_14003a830;
  puVar1 = &DAT_14003a830;
  do {
    puVar2 = puVar1;
    *(undefined4 *)(puVar2 + 2) = 0x6000600;
    puVar2[1] = puVar2 + 3;
    *(undefined2 *)((longlong)puVar2 + 0x14) = 2;
    *puVar2 = puVar2 + 0xc3;
    lVar3 = lVar3 + -1;
    puVar1 = puVar2 + 0xc3;
  } while (lVar3 != 0);
  DAT_14006b432 = 1;
  *puVar2 = 0;
  DAT_14006b431 = 0;
  DAT_14006b430 = 0;
  return;
}



===== pbuf_realloc @ 14000a9f0 =====

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



===== pbuf_ref @ 14000aa98 =====

void pbuf_ref(longlong param_1)

{
  if (param_1 != 0) {
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + 1;
  }
  return;
}



===== pbuf_take @ 14000aaa4 =====

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



===== plug_holes @ 14000aba4 =====

void plug_holes(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  if (param_1 < &DAT_14006b450) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("plug_holes: mem >= ram");
  }
  if (DAT_14006b440 <= param_1) {
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
  puVar1 = (uint *)(&DAT_14006b450 + *param_1);
  puVar2 = DAT_14006b448;
  if (((param_1 != puVar1) && ((&DAT_14006b458)[*param_1] == '\0')) && (puVar1 != DAT_14006b440)) {
    *param_1 = *puVar1;
    if (DAT_14006b448 == puVar1) {
      puVar2 = param_1;
    }
    DAT_14006b448 = puVar2;
    *(int *)(&DAT_14006b454 + *puVar1) = (int)param_1 + -0x4006b450;
  }
  puVar1 = (uint *)(&DAT_14006b450 + param_1[1]);
  if ((puVar1 != param_1) && ((&DAT_14006b458)[param_1[1]] == '\0')) {
    *puVar1 = *param_1;
    DAT_14006b448 = puVar2;
    if (puVar2 == param_1) {
      DAT_14006b448 = puVar1;
    }
    *(int *)(&DAT_14006b454 + *param_1) = (int)puVar1 + -0x4006b450;
  }
  return;
}



===== stack_bringup @ 14000ac84 =====

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
                    /* WARNING: Could not recover jumptable at 0x00014002d030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(param_1);
  return;
}



===== stack_close_connection @ 14000acc8 =====

void stack_close_connection(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = get_network_stack();
                    /* WARNING: Could not recover jumptable at 0x00014002d030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 0x20))(param_1);
  return;
}



===== stack_flush_tcp_data @ 14000acec =====

void stack_flush_tcp_data(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = get_network_stack();
                    /* WARNING: Could not recover jumptable at 0x00014002d030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 0x30))(param_1);
  return;
}



===== stack_poll_device @ 14000ad10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void stack_poll_device(void)

{
  (*(code *)l2_driver_intf[10])(*l2_driver_intf,1);
  return;
}



===== stack_rx_packet @ 14000ad2c =====

void stack_rx_packet(undefined8 param_1,undefined8 param_2,undefined2 param_3)

{
  longlong lVar1;
  
  lVar1 = get_network_stack();
                    /* WARNING: Could not recover jumptable at 0x00014002d030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 0x10))(param_1,param_2,param_3);
  return;
}



===== stack_set_addr @ 14000ad70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void stack_set_addr(longlong param_1)

{
  (**(code **)(param_1 + 8))();
  return;
}



===== stack_setup_connection @ 14000ad84 =====

void stack_setup_connection(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = get_network_stack();
                    /* WARNING: Could not recover jumptable at 0x00014002d030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 0x18))(param_1,param_2,param_3);
  return;
}



===== stack_shutdown @ 14000adc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void stack_shutdown(longlong param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(param_1 + 0x168);
  iscsiDelTimer(*(undefined2 **)(param_1 + 0x158));
  iscsiDelTimer(*(undefined2 **)(param_1 + 0x160));
  netif_set_down((longlong)puVar1);
  (**(code **)(l2_driver_intf + 0x70))(puVar1);
  netif_remove(puVar1);
  mm_free_all_resources();
  return;
}



===== stack_write_tcp_data @ 14000ae30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void stack_write_tcp_data
               (undefined8 param_1,undefined8 param_2,undefined2 param_3,undefined1 param_4)

{
  longlong lVar1;
  
  lVar1 = get_network_stack();
  (**(code **)(lVar1 + 0x28))(param_1,param_2,param_3,param_4);
  return;
}



===== __security_check_cookie @ 14000aea0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 14000aec0 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 14000aed0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== __report_rangecheckfailure @ 14000af00 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  __report_securityfailure(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __report_securityfailure @ 14000af10 =====

void __report_securityfailure(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,param_1,__security_cookie,__security_cookie_complement,1);
}



===== StorPortInitialize @ 14000af40 =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000af40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortGetPhysicalAddress @ 14000af46 =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000af46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortGetUncachedExtension @ 14000af4c =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000af4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortNotification @ 14000af52 =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000af52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== StorPortCompleteRequest @ 14000af58 =====

void StorPortCompleteRequest(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000af58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortCompleteRequest();
  return;
}



===== StorPortStallExecution @ 14000af5e =====

void StorPortStallExecution(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000af5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== __GSHandlerCheck @ 14000af64 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000af84 =====

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



===== memcmp @ 14000b000 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14000b043;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14000b0b4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14000b0b0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000b0b4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000b0ac:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000b0b0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000b0ac;
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
LAB_14000b0b4:
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
LAB_14000b043:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== strncmp @ 14000b0c7 =====

int __cdecl strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000b0c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strncmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== DbgPrint @ 14000b0cd =====

void DbgPrint(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b0cd. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  DbgPrint();
  return;
}



===== HalGetBusDataByOffset @ 14000b0d3 =====

void HalGetBusDataByOffset(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b0d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HalGetBusDataByOffset();
  return;
}



===== HalSetBusDataByOffset @ 14000b0d9 =====

void HalSetBusDataByOffset(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b0d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HalSetBusDataByOffset();
  return;
}



===== MM_GetConfig @ 14000b0e0 =====

undefined8 MM_GetConfig(longlong param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  *(undefined4 *)(param_1 + 0x198) = 2;
  *(undefined4 *)(param_1 + 0x378) = 0x96;
  *(undefined4 *)(param_1 + 0x37c) = 0x96;
  *(undefined1 *)(param_1 + 0x3f1) = 0;
  *(undefined4 *)(param_1 + 0x380) = 1;
  *(undefined4 *)(param_1 + 0x14) = 4;
  *(undefined8 *)(param_1 + 900) = 1;
  *(undefined1 *)(param_1 + 0x3fb) = 1;
  *(undefined4 *)(param_1 + 0x390) = 0;
  if (((*(uint *)(param_1 + 0x452) & 0x20000000) != 0) && (*(short *)(param_1 + 0x456) != 0)) {
    *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) | 4;
  }
  cVar1 = *(char *)(param_1 + 0x3fd);
  if (cVar1 == '\x01') {
    uVar2 = 3;
  }
  else if (cVar1 == '\x02') {
    uVar2 = 4;
  }
  else if (cVar1 == '\x03') {
    uVar2 = 5;
  }
  else if (cVar1 == '\x04') {
    uVar2 = 6;
  }
  else if (cVar1 == '\x05') {
    uVar2 = 7;
  }
  else if (cVar1 == '\x06') {
    uVar2 = 8;
  }
  *(undefined4 *)(param_1 + 0x3db) = uVar2;
  return 0;
}



===== MM_InitializeDeviceResources @ 14000b198 =====

undefined8 MM_InitializeDeviceResources(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = mm_get_um_blk();
  uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x2c),(uint *)(param_1 + 0x34),0x50);
  if (((((int)uVar2 == 0) &&
       (uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x1c),(uint *)(param_1 + 0x24),
                                  (uint)*(ushort *)(param_1 + 0x407) << 5), (int)uVar2 == 0)) &&
      (uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x184),(uint *)(param_1 + 0x18c),
                                 (uint)*(ushort *)(param_1 + 0x405) << 5), (int)uVar2 == 0)) &&
     (uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x300),(uint *)(param_1 + 0x308),
                                (uint)*(ushort *)(param_1 + 0x409) << 4), (int)uVar2 == 0)) {
    return uVar2;
  }
  return 1;
}



===== MM_InitializeUmPackets @ 14000b244 =====

undefined8 MM_InitializeUmPackets(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  
  lVar1 = mm_get_um_blk();
  uVar5 = 0;
  if (*(int *)(param_1 + 0x4c) != 0) {
    uVar4 = *(uint *)(param_1 + 0x54);
    do {
      uVar3 = *(uint *)(param_1 + 0x50);
      if (uVar3 == uVar4) {
        lVar6 = 0;
      }
      else {
        if (uVar3 == 0) {
          uVar3 = *(uint *)(param_1 + 0x58);
        }
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + -1;
        *(uint *)(param_1 + 0x50) = uVar3 - 1;
        lVar6 = *(longlong *)(param_1 + 0x60 + (ulonglong)(uVar3 - 1) * 8);
      }
      uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(lVar6 + 0x12),(uint *)(lVar6 + 0x1a),0x600);
      if ((int)uVar2 != 0) {
        return 1;
      }
      uVar4 = *(uint *)(param_1 + 0x54);
      uVar3 = uVar4;
      if (uVar4 == 0) {
        uVar3 = *(uint *)(param_1 + 0x58);
      }
      uVar3 = uVar3 - 1;
      if (uVar3 != *(uint *)(param_1 + 0x50)) {
        *(longlong *)(param_1 + 0x60 + (ulonglong)uVar3 * 8) = lVar6;
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
        *(uint *)(param_1 + 0x54) = uVar3;
        uVar4 = uVar3;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x4c));
  }
  uVar5 = 0;
  if (*(int *)(param_1 + 0x198) != 0) {
    uVar4 = *(uint *)(param_1 + 0x1a4);
    do {
      uVar3 = *(uint *)(param_1 + 0x1a0);
      if (uVar3 == uVar4) {
        lVar6 = 0;
      }
      else {
        if (uVar3 == 0) {
          uVar3 = *(uint *)(param_1 + 0x1a8);
        }
        *(int *)(param_1 + 0x1ac) = *(int *)(param_1 + 0x1ac) + -1;
        *(uint *)(param_1 + 0x1a0) = uVar3 - 1;
        lVar6 = *(longlong *)(param_1 + 0x1b0 + (ulonglong)(uVar3 - 1) * 8);
      }
      uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(lVar6 + 0x26),(uint *)(lVar6 + 0x2e),0x600);
      if ((int)uVar2 != 0) {
        return 1;
      }
      uVar4 = *(uint *)(param_1 + 0x1a4);
      uVar3 = uVar4;
      if (uVar4 == 0) {
        uVar3 = *(uint *)(param_1 + 0x1a8);
      }
      uVar3 = uVar3 - 1;
      if (uVar3 != *(uint *)(param_1 + 0x1a0)) {
        *(longlong *)(param_1 + 0x1b0 + (ulonglong)uVar3 * 8) = lVar6;
        *(int *)(param_1 + 0x1ac) = *(int *)(param_1 + 0x1ac) + 1;
        *(uint *)(param_1 + 0x1a4) = uVar3;
        uVar4 = uVar3;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x198));
  }
  return 0;
}



===== lm_reg_read_ind @ 14000b3a0 =====

void lm_reg_read_ind(undefined8 param_1,undefined4 param_2)

{
  storport_pci_cfg_write_dword(param_1,0x78,param_2);
  storport_pci_cfg_read_dword(param_1,0x80);
  return;
}



===== lm_reg_wr_ind @ 14000b3c4 =====

void lm_reg_wr_ind(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  storport_pci_cfg_write_dword(param_1,0x78,param_2);
  storport_pci_cfg_write_dword(param_1,0x80,param_3);
  return;
}



===== mm_device_poll @ 14000b400 =====

undefined8 mm_device_poll(longlong param_1,int param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar6;
  uint uVar5;
  
  LM_ServiceInterrupts(param_1);
  iVar3 = *(int *)(param_1 + 0x2a8);
  if (iVar3 != *(int *)(param_1 + 0x2ac)) {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x2b0);
    }
    *(uint *)(param_1 + 0x2a8) = iVar3 - 1U;
    *(int *)(param_1 + 0x2b4) = *(int *)(param_1 + 0x2b4) + -1;
    iVar6 = *(int *)(param_1 + 0x1a4);
    if (iVar6 == 0) {
      iVar6 = *(int *)(param_1 + 0x1a8);
    }
    uVar5 = iVar6 - 1;
    if (uVar5 != *(uint *)(param_1 + 0x1a0)) {
      *(undefined8 *)(param_1 + 0x1b0 + (ulonglong)uVar5 * 8) =
           *(undefined8 *)(param_1 + 0x2b8 + (ulonglong)(iVar3 - 1U) * 8);
      *(int *)(param_1 + 0x1ac) = *(int *)(param_1 + 0x1ac) + 1;
      *(uint *)(param_1 + 0x1a4) = uVar5;
    }
  }
  if ((param_2 != 0) && (iVar3 = *(int *)(param_1 + 0xe8), iVar3 != *(int *)(param_1 + 0xec))) {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0xf0);
    }
    *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + -1;
    *(uint *)(param_1 + 0xe8) = iVar3 - 1U;
    lVar1 = *(longlong *)(param_1 + 0xf8 + (ulonglong)(iVar3 - 1U) * 8);
    uVar2 = *(undefined8 *)(lVar1 + 0x12);
    uVar4 = mm_get_net_if();
    stack_rx_packet(uVar4,uVar2,*(undefined2 *)(lVar1 + 4));
    iVar3 = *(int *)(param_1 + 0x54);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x58);
    }
    uVar5 = iVar3 - 1;
    if (uVar5 != *(uint *)(param_1 + 0x50)) {
      *(longlong *)(param_1 + 0x60 + (ulonglong)uVar5 * 8) = lVar1;
      *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
      *(uint *)(param_1 + 0x54) = uVar5;
    }
    LM_QueueRxPackets(param_1);
  }
  return 0;
}



===== mm_get_dma_buffer_length @ 14000b510 =====

undefined8 mm_get_dma_buffer_length(void)

{
  return 0x3240;
}



===== mm_get_free_pkt_desc @ 14000b518 =====

longlong mm_get_free_pkt_desc(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1a0);
  if (iVar3 != *(int *)(param_1 + 0x1a4)) {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x1a8);
    }
    *(int *)(param_1 + 0x1ac) = *(int *)(param_1 + 0x1ac) + -1;
    *(uint *)(param_1 + 0x1a0) = iVar3 - 1U;
    lVar1 = *(longlong *)(param_1 + 0x1b0 + (ulonglong)(iVar3 - 1U) * 8);
    if (lVar1 != 0) {
      return lVar1;
    }
  }
  iVar3 = 0;
  do {
    lm_reg_wr_ind(param_1,0x3c00,*(uint *)(param_1 + 0x400) | 8);
    LM_ServiceInterrupts(param_1);
    iVar2 = *(int *)(param_1 + 0x2a8);
    if (iVar2 != *(int *)(param_1 + 0x2ac)) {
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0x2b0);
      }
      *(int *)(param_1 + 0x2b4) = *(int *)(param_1 + 0x2b4) + -1;
      *(uint *)(param_1 + 0x2a8) = iVar2 - 1U;
      lVar1 = *(longlong *)(param_1 + 0x2b8 + (ulonglong)(iVar2 - 1U) * 8);
      if (lVar1 != 0) {
        return lVar1;
      }
    }
    iVar3 = iVar3 + 1;
    if (9999 < iVar3) {
      return 0;
    }
  } while( true );
}



===== mm_get_link_status @ 14000b5d0 =====

undefined4 mm_get_link_status(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x3ed);
}



===== mm_get_mac_addr @ 14000b5e0 =====

undefined8 mm_get_mac_addr(longlong param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x3a4);
  *(undefined2 *)(param_2 + 1) = *(undefined2 *)(param_1 + 0x3a8);
  return 0;
}



===== mm_get_rx_packet @ 14000b600 =====

undefined2 mm_get_rx_packet(longlong param_1,void *param_2)

{
  longlong lVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  
  mm_device_poll(param_1,0);
  iVar3 = *(int *)(param_1 + 0xe8);
  if (iVar3 == *(int *)(param_1 + 0xec)) {
    uVar2 = 0;
  }
  else {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0xf0);
    }
    *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + -1;
    *(uint *)(param_1 + 0xe8) = iVar3 - 1U;
    lVar1 = *(longlong *)(param_1 + 0xf8 + (ulonglong)(iVar3 - 1U) * 8);
    memmove(param_2,*(void **)(lVar1 + 0x12),(ulonglong)*(ushort *)(lVar1 + 4));
    iVar3 = *(int *)(param_1 + 0x54);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x58);
    }
    uVar4 = iVar3 - 1;
    if (uVar4 != *(uint *)(param_1 + 0x50)) {
      *(longlong *)(param_1 + 0x60 + (ulonglong)uVar4 * 8) = lVar1;
      *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
      *(uint *)(param_1 + 0x54) = uVar4;
    }
    LM_QueueRxPackets(param_1);
    uVar2 = *(undefined2 *)(lVar1 + 4);
  }
  return uVar2;
}



===== mm_interrupt_control @ 14000b6a0 =====

void mm_interrupt_control(undefined8 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = storport_pci_cfg_read_dword(param_1,4);
  uVar2 = uVar1 & 0xfffffbff;
  if (param_2 == 0) {
    uVar2 = uVar1 | 0x400;
  }
  storport_pci_cfg_write_dword(param_1,4,uVar2);
  return;
}



===== mm_queue_tx_packet @ 14000b6dc =====

void mm_queue_tx_packet(longlong param_1,longlong param_2)

{
  *(uint *)(param_2 + 0x44) = (uint)*(ushort *)(param_2 + 4);
  *(undefined2 *)(param_2 + 6) = 0;
  *(uint *)(param_2 + 0x48) = (uint)*(ushort *)(param_2 + 4);
  *(undefined4 *)(param_2 + 0x12) = 0;
  *(undefined8 *)(param_2 + 0x4c) = *(undefined8 *)(param_2 + 0x2e);
  *(longlong *)(param_2 + 0x36) = param_2 + 0x40;
  *(undefined4 *)(param_2 + 10) = 1;
  if (((*(uint *)(param_1 + 0x452) & 0x20000000) != 0) && (*(short *)(param_1 + 0x456) != 0)) {
    *(ushort *)(param_2 + 6) = *(ushort *)(param_2 + 6) | 1;
    *(undefined2 *)(param_2 + 8) = *(undefined2 *)(param_1 + 0x456);
  }
  LM_SendPacket(param_1,param_2);
  return;
}



===== mm_transmit_packet @ 14000b740 =====

undefined4 mm_transmit_packet(longlong param_1,longlong *param_2)

{
  ushort *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong lVar4;
  int iVar5;
  
  lVar4 = mm_get_free_pkt_desc(param_1);
  if (lVar4 == 0) {
    uVar3 = 1;
  }
  else {
    lVar2 = *(longlong *)(lVar4 + 0x26);
    iVar5 = 0;
    *(short *)(lVar4 + 4) = (short)param_2[2];
    do {
      memmove((void *)(iVar5 + lVar2),(void *)param_2[1],
              (ulonglong)*(ushort *)((longlong)param_2 + 0x12));
      puVar1 = (ushort *)((longlong)param_2 + 0x12);
      param_2 = (longlong *)*param_2;
      iVar5 = iVar5 + (uint)*puVar1;
    } while (param_2 != (longlong *)0x0);
    mm_queue_tx_packet(param_1,lVar4);
    uVar3 = 0;
  }
  return uVar3;
}



===== mm_transmit_packet_raw @ 14000b7d0 =====

bool mm_transmit_packet_raw(longlong param_1,void *param_2,ushort param_3)

{
  longlong lVar1;
  
  lVar1 = mm_get_free_pkt_desc(param_1);
  if (lVar1 != 0) {
    *(ushort *)(lVar1 + 4) = param_3;
    memmove(*(void **)(lVar1 + 0x26),param_2,(ulonglong)param_3);
    mm_queue_tx_packet(param_1,lVar1);
  }
  return lVar1 == 0;
}



===== nx1_get_intf @ 14000b838 =====

undefined8 nx1_get_intf(undefined8 *param_1)

{
  *param_1 = &nx1_device_block;
  param_1[1] = mm_get_dma_buffer;
  param_1[2] = iscsiBootCancel;
  param_1[3] = mm_get_rx_packet;
  param_1[4] = mm_transmit_packet_raw;
  param_1[5] = mm_transmit_packet;
  param_1[6] = mm_get_dma_buffer_length;
  param_1[7] = dir_get_iscsi_block;
  param_1[8] = mm_get_mac_addr;
  param_1[9] = iscsiBootCancel;
  param_1[10] = mm_device_poll;
  param_1[0xb] = mm_get_link_status;
  param_1[0x10] = iscsiBootCancel;
  param_1[0x11] = mm_interrupt_control;
  nx1_get_netif_intf((longlong)param_1);
  return 0;
}



===== LM_Abort @ 14000b8e8 =====

undefined8 LM_Abort(longlong param_1)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  LM_DisableInterrupt(param_1);
  *(undefined4 *)(param_1 + 0x36c) = 0;
  *(undefined4 *)(param_1 + 0x370) = 0;
  lm_reg_wr_ind(param_1,0x468,0);
  lm_reg_wr_ind(param_1,0x45c,0);
  uVar6 = 0;
  do {
    iVar2 = lm_reg_read_ind(param_1,0x468);
    if (iVar2 == 0) break;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 10000);
  uVar6 = 0;
  do {
    iVar2 = lm_reg_read_ind(param_1,0x45c);
    if (iVar2 == 0) break;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 10000);
LAB_14000b99e:
  iVar2 = *(int *)(param_1 + 0x250);
  if (iVar2 != *(int *)(param_1 + 0x254)) {
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 600);
    }
    *(uint *)(param_1 + 0x250) = iVar2 - 1U;
    *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -1;
    puVar1 = *(undefined4 **)(param_1 + 0x260 + (ulonglong)(iVar2 - 1U) * 8);
    if (puVar1 == (undefined4 *)0x0) goto LAB_14000ba04;
    *puVar1 = 8;
    iVar2 = *(int *)(param_1 + 0x2ac);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x2b0);
    }
    uVar6 = iVar2 - 1;
    if (uVar6 != *(uint *)(param_1 + 0x2a8)) {
      *(undefined4 **)(param_1 + 0x2b8 + (ulonglong)uVar6 * 8) = puVar1;
      *(int *)(param_1 + 0x2b4) = *(int *)(param_1 + 0x2b4) + 1;
      *(uint *)(param_1 + 0x2ac) = uVar6;
    }
    goto LAB_14000b99e;
  }
LAB_14000ba04:
  do {
    iVar2 = *(int *)(param_1 + 0x1f8);
    if (iVar2 == *(int *)(param_1 + 0x1fc)) {
LAB_14000ba37:
      iscsiBootCancel();
      LM_ServiceRxInterrupt(param_1);
      iscsiBootCancel();
      uVar6 = (uint)*(ushort *)(*(longlong *)(param_1 + 0x2c) + 10);
      if (uVar6 != *(uint *)(param_1 + 0x18)) {
        do {
          iVar2 = *(int *)(param_1 + 0x54);
          if (iVar2 == 0) {
            iVar2 = *(int *)(param_1 + 0x58);
          }
          uVar5 = iVar2 - 1;
          if (uVar5 != *(uint *)(param_1 + 0x50)) {
            *(ulonglong *)(param_1 + 0x60 + (ulonglong)uVar5 * 8) =
                 (ulonglong)
                 *(uint *)((ulonglong)uVar6 * 0x20 + 0x1c + *(longlong *)(param_1 + 0x1c)) +
                 *(longlong *)(param_1 + 8);
            *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
            *(uint *)(param_1 + 0x54) = uVar5;
          }
          uVar6 = *(ushort *)(param_1 + 0x407) - 1 & uVar6 + 1;
        } while (uVar6 != *(uint *)(param_1 + 0x18));
      }
      lVar3 = LM_IsSawtooth(param_1);
      if (((char)lVar3 != '\0') || (uVar4 = LM_IsLogan(param_1), (char)uVar4 != '\0')) {
        lm_reg_wr_ind(param_1,0x468,0x1700000);
        lm_reg_wr_ind(param_1,0x45c,0x12);
      }
      return 0;
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x200);
    }
    *(uint *)(param_1 + 0x1f8) = iVar2 - 1U;
    *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0x204) + -1;
    puVar1 = *(undefined4 **)(param_1 + 0x208 + (ulonglong)(iVar2 - 1U) * 8);
    if (puVar1 == (undefined4 *)0x0) goto LAB_14000ba37;
    iVar2 = *(int *)(param_1 + 0x2ac);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x2b0);
    }
    uVar6 = iVar2 - 1;
    if (uVar6 != *(uint *)(param_1 + 0x2a8)) {
      *(undefined4 **)(param_1 + 0x2b8 + (ulonglong)uVar6 * 8) = puVar1;
      *(int *)(param_1 + 0x2b4) = *(int *)(param_1 + 0x2b4) + 1;
      *(uint *)(param_1 + 0x2ac) = uVar6;
    }
    *puVar1 = 8;
  } while( true );
}



===== LM_ApeAcquireLock @ 14000baf4 =====

bool LM_ApeAcquireLock(longlong param_1,ushort param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ushort local_res10 [4];
  ushort local_res18 [4];
  ushort local_res20 [4];
  
  local_res10[0] = param_2;
  LM_ApeGetMutexRegisters(param_1,local_res18,local_res20,(short *)local_res10);
  uVar2 = (uint)local_res10[0];
  lm_reg_wr_ind(param_1,local_res18[0] + 0x10000 + uVar2,0x1000);
  iVar4 = 0;
  iVar3 = uVar2 + local_res20[0];
  do {
    iVar1 = lm_reg_read_ind(param_1,iVar3 + 0x10000);
    if (iVar1 == 0x1000) break;
    mm_stall(1000);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 1000);
  if (iVar4 == 1000) {
    lm_reg_wr_ind(param_1,iVar3 + 0x10000,0x1000);
  }
  return iVar4 == 1000;
}



===== LM_ApeDriverStateChange @ 14000bb98 =====

void LM_ApeDriverStateChange(longlong param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (param_2 == 0) {
    uVar4 = 2;
    uVar3 = 0x20510;
  }
  else if (param_2 == 1) {
    lm_reg_wr_ind(param_1,0x14200,0x484f5354);
    lm_reg_wr_ind(param_1,0x14204,0x20);
    iVar1 = lm_reg_read_ind(param_1,0x14208);
    lm_reg_wr_ind(param_1,0x14208,iVar1 + 1);
    uVar2 = iscsiBootCancel();
    lm_reg_wr_ind(param_1,0x1420c,(int)uVar2);
    uVar4 = 1;
    lm_reg_wr_ind(param_1,0x14210,1);
    lm_reg_wr_ind(param_1,0x14214,0);
    uVar3 = 0x10510;
  }
  else {
    if (param_2 != 2) {
      return;
    }
    uVar4 = 4;
    uVar3 = 0x40510;
  }
  lm_reg_wr_ind(param_1,0x1421c,uVar4);
  LM_ApeSendEvent(param_1,uVar3);
  return;
}



===== LM_ApeGetEventStatus @ 14000bc84 =====

undefined4 LM_ApeGetEventStatus(longlong param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined7 extraout_var;
  
  bVar1 = LM_ApeAcquireLock(param_1,4);
  if ((int)CONCAT71(extraout_var,bVar1) == 0) {
    uVar2 = lm_reg_read_ind(param_1,0x14300);
    LM_ApeReleaseLock(param_1,4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== LM_ApeGetMutexRegisters @ 14000bccc =====

void LM_ApeGetMutexRegisters
               (longlong param_1,undefined2 *param_2,undefined2 *param_3,short *param_4)

{
  char cVar1;
  undefined2 uVar2;
  short sVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  uVar4 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if (uVar4 < 0x5717) {
LAB_14000bd2b:
    *param_2 = 0x2c;
    uVar2 = 0x4c;
  }
  else if (uVar4 < 0x5719) {
    *param_2 = 0x5000;
    uVar2 = 0x5020;
  }
  else {
    if (((uVar4 != 0x5719) && (uVar4 != 0x5720)) && (uVar4 != 0x5762)) goto LAB_14000bd2b;
    *param_2 = 0x8400;
    uVar2 = 0x8420;
  }
  *param_3 = uVar2;
  lVar5 = LM_IsSawtooth(param_1);
  if ((char)lVar5 == '\0') {
    uVar6 = LM_IsLogan(param_1);
    if ((char)uVar6 == '\0') goto LAB_14000bd8b;
  }
  if (*param_4 == 0) {
    cVar1 = *(char *)(param_1 + 0x444);
    if (cVar1 == '\0') {
      *param_4 = 0;
    }
    else {
      if (cVar1 == '\x01') {
        sVar3 = 2;
      }
      else if (cVar1 == '\x02') {
        sVar3 = 3;
      }
      else {
        if (cVar1 != '\x03') goto LAB_14000bd8b;
        sVar3 = 5;
      }
      *param_4 = sVar3;
    }
  }
LAB_14000bd8b:
  *param_4 = *param_4 << 2;
  return;
}



===== LM_ApeReleaseLock @ 14000bda8 =====

undefined8 LM_ApeReleaseLock(longlong param_1,ushort param_2)

{
  ushort local_res10 [4];
  ushort local_res18 [4];
  undefined2 local_res20 [4];
  
  local_res10[0] = param_2;
  LM_ApeGetMutexRegisters(param_1,local_res20,local_res18,(short *)local_res10);
  lm_reg_wr_ind(param_1,(uint)local_res18[0] + local_res10[0] + 0x10000,0x1000);
  return 0;
}



===== LM_ApeSendEvent @ 14000bdf0 =====

void LM_ApeSendEvent(longlong param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  undefined7 extraout_var;
  int iVar6;
  
  lVar5 = LM_IsSawtooth(param_1);
  iVar6 = 0;
  if ((((char)lVar5 == '\0') && (iVar2 = lm_reg_read_ind(param_1,0x14000), iVar2 == 0x41504521)) &&
     (uVar3 = lm_reg_read_ind(param_1,0x1400c), (uVar3 & 0xf0000100) == 0x100)) {
    iVar2 = 0;
    do {
      iVar4 = LM_ApeGetEventStatus(param_1);
      if (-1 < iVar4) {
        bVar1 = LM_ApeAcquireLock(param_1,4);
        if ((int)CONCAT71(extraout_var,bVar1) == 0) {
          lm_reg_wr_ind(param_1,0x14300,param_2 | 0x80000000);
          LM_ApeReleaseLock(param_1,4);
        }
        break;
      }
      mm_stall(1000);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 1000);
    lm_reg_wr_ind(param_1,0x1000c,1);
    do {
      iVar2 = LM_ApeGetEventStatus(param_1);
      if (-1 < iVar2) {
        return;
      }
      mm_stall(100);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 1000);
  }
  return;
}



===== LM_AsfSendMbox @ 14000beec =====

void LM_AsfSendMbox(undefined8 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  LM_MemWrInd(param_1,0xb78,param_2);
  uVar1 = lm_reg_read_ind(param_1,0x6810);
  lm_reg_wr_ind(param_1,0x6810,uVar1 | 0x4000);
  iVar2 = 0;
  do {
    uVar1 = lm_reg_read_ind(param_1,0x6810);
    if ((uVar1 >> 0xe & 1) == 0) {
      return;
    }
    mm_stall(1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1000);
  return;
}



===== LM_DisableInterrupt @ 14000bf5c =====

undefined8 LM_DisableInterrupt(longlong param_1)

{
  lm_reg_wr_ind(param_1,0x5804,1);
  storport_pci_cfg_write_dword(param_1,0x68,*(uint *)(param_1 + 0x10) & 0xfffffffd | 1);
  *(undefined1 *)(param_1 + 0x3c0) = 0;
  return 0;
}



===== LM_DoRdmaWorkaround @ 14000bf9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LM_DoRdmaWorkaround(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_38 [32];
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if (*(char *)(param_1 + 0x464) == '\x01') {
    local_18 = lm_reg_read_ind(param_1,0x4be0);
    local_14 = lm_reg_read_ind(param_1,0x4be4);
    uVar1 = lm_reg_read_ind(param_1,0x4910);
    iVar4 = 0;
    lVar2 = 0;
    do {
      if (0x5f2 < *(ushort *)(auStack_38 + lVar2 * 2 + 0x20)) break;
      iVar4 = iVar4 + 1;
      lVar2 = lVar2 + 1;
    } while (lVar2 < 4);
    uVar3 = 0x2000000;
    if ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) != 0x5719000) {
      uVar3 = 0x200000;
    }
    if (iVar4 == 4) {
      *(undefined1 *)(param_1 + 0x464) = 0;
      uVar1 = uVar1 & ~uVar3;
    }
    else {
      uVar1 = uVar1 | uVar3;
    }
    lm_reg_wr_ind(param_1,0x4910,uVar1);
  }
  return;
}



===== LM_EnableInterrupt @ 14000c060 =====

undefined8 LM_EnableInterrupt(longlong param_1)

{
  uint uVar1;
  
  lm_reg_wr_ind(param_1,0x5804,0);
  storport_pci_cfg_write_dword(param_1,0x68,*(uint *)(param_1 + 0x10) & 0xfffffffd);
  if ((**(uint **)(param_1 + 0x2c) & 1) != 0) {
    uVar1 = lm_reg_read_ind(param_1,0x6808);
    lm_reg_wr_ind(param_1,0x6808,uVar1 | 4);
  }
  *(undefined1 *)(param_1 + 0x3c0) = 1;
  return 0;
}



===== LM_EnableMemoryArbitor @ 14000c0c4 =====

void LM_EnableMemoryArbitor(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if ((uVar1 == 5) || (uVar1 - 8 < 2)) {
    uVar1 = lm_reg_read_ind(param_1,0x4000);
  }
  else {
    uVar1 = 0;
  }
  lm_reg_wr_ind(param_1,0x4000,uVar1 | 2);
  return;
}



===== LM_FindPciCapabilityPtr @ 14000c10c =====

ulonglong LM_FindPciCapabilityPtr(undefined8 param_1,char param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 extraout_var;
  ulonglong uVar3;
  undefined4 extraout_var_00;
  
  uVar2 = storport_pci_cfg_read_dword(param_1,0x34);
  uVar3 = CONCAT44(extraout_var,uVar2);
  bVar1 = (byte)uVar2;
  while ((0x3f < bVar1 && (bVar1 = (byte)uVar2, bVar1 != 0xff))) {
    uVar2 = storport_pci_cfg_read_dword(param_1,bVar1);
    if ((char)uVar2 == param_2) {
      return CONCAT71((int7)(CONCAT44(extraout_var_00,uVar2) >> 8),bVar1);
    }
    uVar3 = (ulonglong)(uVar2 >> 8);
    bVar1 = (byte)(uVar2 >> 8);
    uVar2 = (uint)bVar1;
  }
  return uVar3 & 0xffffffffffffff00;
}



===== LM_GetAdapterInfo @ 14000c164 =====

undefined8 LM_GetAdapterInfo(longlong param_1,char param_2)

{
  bool bVar1;
  undefined1 uVar2;
  byte bVar3;
  byte extraout_AH;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  ushort uVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  uint local_res8;
  undefined2 local_resc;
  byte local_res10;
  
  uVar4 = storport_pci_cfg_read_dword(param_1,0);
  *(short *)(param_1 + 0x3b8) = (short)uVar4;
  *(short *)(param_1 + 0x3ba) = (short)((uint)uVar4 >> 0x10);
  iVar5 = storport_pci_cfg_read_dword(param_1,0);
  if ((((((iVar5 == 0x170d14e4) || (iVar5 == 0x170e14e4)) || (iVar5 == 0x164d14e4)) ||
       ((iVar5 == 0x166e14e4 || (iVar5 == 0x167e14e4)))) ||
      ((iVar5 == 0x171214e4 || ((iVar5 == 0x171314e4 || (iVar5 == 0x167f14e4)))))) ||
     ((iVar5 == 0x169414e4 ||
      (((iVar5 == 0x16a014e4 || (iVar5 == 0x16b214e4)) || (uVar2 = 1, iVar5 == 0x16b614e4)))))) {
    uVar2 = 0;
  }
  *(undefined1 *)(param_1 + 0x40c) = uVar2;
  iVar5 = storport_pci_cfg_read_dword(param_1,0x2c);
  if (iVar5 == 0x20031028) {
    uVar6 = LM_GetGPIO2(param_1);
    *(char *)(param_1 + 0x40c) = (char)uVar6;
  }
  uVar4 = storport_pci_cfg_read_dword(param_1,0x3c);
  *(char *)(param_1 + 0x3bd) = (char)uVar4;
  *(char *)(param_1 + 0x3be) = (char)((uint)uVar4 >> 8);
  storport_pci_cfg_write_dword(param_1,0x7c,0);
  *(undefined4 *)(param_1 + 0x10) = 0xbb;
  storport_pci_cfg_write_dword(param_1,0x68,0xbb);
  uVar6 = storport_pci_cfg_read_dword(param_1,0x68);
  *(uint *)(param_1 + 0x3ca) = uVar6 >> 0x10;
  if ((uVar6 >> 0x10 & 0xfffff000) == 0xf000) {
    lVar10 = LM_IsSawtooth(param_1);
    if ((((char)lVar10 == '\0') && (lVar10 = LM_IsAspen(param_1), (char)lVar10 == '\0')) &&
       (uVar11 = LM_IsLogan(param_1), (char)uVar11 == '\0')) {
      uVar4 = storport_pci_cfg_read_dword(param_1,0xbc);
    }
    else {
      uVar4 = lm_reg_read_ind(param_1,0x3658);
    }
    *(undefined4 *)(param_1 + 0x3ca) = uVar4;
  }
  uVar6 = lm_reg_read_ind(param_1,0x6804);
  *(byte *)(param_1 + 0x3bc) = (byte)(uVar6 >> 0xd) & 0xf;
  if ((*(int *)(param_1 + 0x3ca) == 0x5000) && ((uVar6 >> 0xd & 0xb) == 0)) {
    *(undefined4 *)(param_1 + 0x3ca) = 0x6000;
  }
  uVar4 = storport_pci_cfg_read_dword(param_1,0x2c);
  *(short *)(param_1 + 0x3ce) = (short)uVar4;
  *(short *)(param_1 + 0x3d0) = (short)((uint)uVar4 >> 0x10);
  uVar6 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  *(undefined1 *)(param_1 + 0x444) = 0;
  if (((uVar6 < 10) && ((0x324U >> (uVar6 & 0x1f) & 1) != 0)) &&
     (uVar12 = lm_reg_read_ind(param_1,0xb8), (uVar12 & 4) != 0)) {
    *(undefined1 *)(param_1 + 0x444) = 1;
  }
  lVar10 = LM_IsSawtooth(param_1);
  if ((char)lVar10 != '\0') {
    uVar6 = lm_reg_read_ind(param_1,0x362c);
    if (((*(short *)(param_1 + 0x3ba) + 0xe9a9U & 0xfff7) == 0) ||
       (*(int *)(param_1 + 0x3ca) == 0x5717200)) {
      *(byte *)(param_1 + 0x444) = (byte)(uVar6 >> 0x1e);
    }
    else if ((uVar6 >> 0x1d & 1) != 0) {
      *(undefined1 *)(param_1 + 0x444) = 1;
    }
  }
  uVar4 = 2;
  if (1 < (*(uint *)(param_1 + 0x3ca) >> 8) - 0x70) {
    uVar4 = 0x102;
  }
  *(undefined4 *)(param_1 + 0x400) = uVar4;
  *(undefined1 *)(param_1 + 0x443) = 0;
  uVar4 = storport_pci_cfg_read_dword(param_1,8);
  *(char *)(param_1 + 0x3d2) = (char)uVar4;
  *(undefined1 *)(param_1 + 0x443) = 1;
  uVar4 = storport_pci_cfg_read_dword(param_1,0xc);
  *(char *)(param_1 + 0x3bf) = (char)uVar4;
  LM_EnableMemoryArbitor(param_1);
  uVar6 = *(uint *)(param_1 + 0x3ca);
  if ((uVar6 & 0xfffff000) == 0xc000) {
    iVar7 = 0;
  }
  else {
    storport_pci_cfg_write_dword(param_1,0x7c,0xb54);
    iVar7 = storport_pci_cfg_read_dword(param_1,0x84);
    uVar6 = *(uint *)(param_1 + 0x3ca);
  }
  *(undefined1 *)(param_1 + 0x3fc) = 1;
  *(undefined2 *)(param_1 + 0x3fe) = 0;
  if (iVar7 == 0x4b657654) {
    bVar1 = true;
    storport_pci_cfg_write_dword(param_1,0x7c,0xb58);
    uVar6 = storport_pci_cfg_read_dword(param_1,0x84);
    lVar10 = LM_IsSawtooth(param_1);
    if (((char)lVar10 == '\0') || (*(int *)(param_1 + 0x3ca) == 0x5717000)) {
      if ((uVar6 & 0x30) == 0x10) {
        local_res10 = false;
      }
      else {
        local_res10 = (uVar6 & 0x30) == 0x20;
      }
    }
    else {
      lm_reg_read_ind(param_1,0x5b4);
      local_res10 = extraout_AH & 1;
    }
    storport_pci_cfg_write_dword(param_1,0x7c,0xd38);
    uVar8 = storport_pci_cfg_read_dword(param_1,0x84);
    uVar8 = uVar8 & 0x18000;
    if (uVar8 == 0) {
      if ((uVar6 & 0xc) == 4) {
        *(undefined1 *)(param_1 + 0x3fc) = 1;
      }
      else if ((uVar6 & 0xc) == 8) {
        *(undefined1 *)(param_1 + 0x3fc) = 2;
      }
    }
    else if (uVar8 == 0x8000) {
      *(undefined1 *)(param_1 + 0x3fc) = 4;
    }
    else if (uVar8 == 0x10000) {
      *(undefined1 *)(param_1 + 0x3fc) = 3;
    }
    else if (uVar8 == 0x18000) {
      *(undefined1 *)(param_1 + 0x3fc) = 5;
    }
    storport_pci_cfg_write_dword(param_1,0x7c,0xd38);
    uVar8 = storport_pci_cfg_read_dword(param_1,0x84);
    if ((uVar8 >> 0x11 & 1) != 0) {
      *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) | 0x40;
    }
    if ((uVar6 & 0x40) != 0) {
      *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) | 1;
    }
    if ((char)uVar6 < '\0') {
      *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) | 2;
    }
    if ((uVar6 & 0x200080) == 0x200080) {
      *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) & 0xfffd | 8;
    }
    if ((uVar6 >> 0xc & 1) != 0) {
      *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) | 0x10;
    }
    lVar10 = LM_IsSawtooth(param_1);
    if ((char)lVar10 != '\0') {
      storport_pci_cfg_write_dword(param_1,0x7c,0xe0c);
      uVar6 = storport_pci_cfg_read_dword(param_1,0x84);
      if ((uVar6 & 2) != 0) {
        *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) | 0x400;
      }
    }
    storport_pci_cfg_write_dword(param_1,0x7c,0xb74);
    storport_pci_cfg_read_dword(param_1,0x84);
    uVar6 = *(uint *)(param_1 + 0x3ca);
  }
  else {
    bVar1 = false;
  }
  if ((uVar6 & 0xfffff000) == 0xc000) {
    local_res10 = 0;
    bVar1 = true;
    uVar6 = lm_reg_read_ind(param_1,0x5104);
    if ((uVar6 & 1) != 0) {
      *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) | 1;
    }
    uVar8 = uVar6 & 0x30;
    if (uVar8 == 0) {
      *(undefined1 *)(param_1 + 0x3fc) = 1;
    }
    else if (uVar8 == 0x10) {
      *(undefined1 *)(param_1 + 0x3fc) = 2;
    }
    else if (uVar8 == 0x20) {
      *(undefined1 *)(param_1 + 0x3fc) = 4;
    }
    else if (uVar8 == 0x30) {
      *(undefined1 *)(param_1 + 0x3fc) = 3;
    }
    bVar3 = (byte)(uVar6 >> 0xc);
  }
  else {
    storport_pci_cfg_write_dword(param_1,0x7c,0xd3c);
    uVar6 = storport_pci_cfg_read_dword(param_1,0x84);
    bVar3 = (byte)(uVar6 >> 1);
  }
  *(byte *)(param_1 + 0x458) = bVar3 & 1;
  if (*(int *)(param_1 + 0x3ca) == 0x57780000) {
    *(undefined1 *)(param_1 + 0x458) = 0;
  }
  uVar6 = lm_reg_read_ind(param_1,0x70);
  *(byte *)(param_1 + 0x3c1) = ~(byte)(uVar6 >> 2) & 1;
  uVar8 = storport_pci_cfg_read_dword(param_1,4);
  uVar6 = uVar8 & 0xffffffaf;
  if (*(int *)(param_1 + 0x3ca) != 0x5000) {
    uVar6 = uVar8 & 0xffffffef;
  }
  *(uint *)(param_1 + 0x3c2) = uVar6 | 6;
  storport_pci_cfg_write_dword(param_1,4,uVar6 | 6);
  *(undefined4 *)(param_1 + 0x14) = 200;
  *(undefined4 *)(param_1 + 0x198) = 8;
  *(undefined4 *)(param_1 + 0x3db) = 0;
  *(undefined2 *)(param_1 + 0x3a0) = 0x8000;
  *(undefined4 *)(param_1 + 0x378) = 0x4b;
  *(undefined4 *)(param_1 + 0x37c) = 0x4b;
  *(undefined4 *)(param_1 + 0x380) = 0x19;
  *(undefined4 *)(param_1 + 900) = 0x19;
  *(undefined2 *)(param_1 + 0x3df) = 0;
  *(undefined4 *)(param_1 + 0x398) = 0;
  *(undefined4 *)(param_1 + 0x390) = 0;
  *(undefined4 *)(param_1 + 0x388) = 5000;
  LM_NvramInit(param_1);
  *(undefined1 *)(param_1 + 0x463) = 0;
  uVar6 = LM_NvramRead(param_1,0);
  if ((uVar6 != 0x669955aa) &&
     ((*(undefined1 *)(param_1 + 0x463) = 1, (*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x57780000
      || (lVar10 = LM_IsAspen(param_1), (char)lVar10 != '\0')))) {
    *(undefined1 *)(param_1 + 0x463) = 2;
  }
  local_res8 = lm_reg_read_ind(param_1,0x414);
  local_resc = lm_reg_read_ind(param_1,0x410);
  if (((*(uint *)(param_1 + 0x3ca) & 0xfffff000) != 0xc000) && (local_res8 == 0)) {
    uVar8 = -(uint)(*(char *)(param_1 + 0x444) != '\0') & 0x50;
    uVar6 = LM_NvramRead(param_1,uVar8 + 0x7c);
    local_resc = (undefined2)uVar6;
    local_res8 = LM_NvramRead(param_1,uVar8 + 0x80);
  }
  *(undefined1 *)(param_1 + 0x3a5) = (undefined1)local_resc;
  *(char *)(param_1 + 0x3a6) = (char)(local_res8 >> 0x18);
  *(char *)(param_1 + 0x3a7) = (char)(local_res8 >> 0x10);
  *(char *)(param_1 + 0x3a8) = (char)(local_res8 >> 8);
  *(undefined1 *)(param_1 + 0x3a4) = (char)((ushort)local_resc >> 8);
  *(undefined1 *)(param_1 + 0x3a9) = (undefined1)local_res8;
  puVar14 = (undefined1 *)(param_1 + 0x3a4);
  puVar15 = (undefined1 *)(param_1 + 0x3ac);
  for (lVar10 = 6; lVar10 != 0; lVar10 = lVar10 + -1) {
    *puVar15 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar15 = puVar15 + 1;
  }
  if (param_2 == '\x01') {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x3fe) & 2) != 0) {
    LM_HaltCpu(param_1,1);
    LM_HaltCpu(param_1,2);
  }
  *(undefined4 *)(param_1 + 0x3d3) = 1;
  lVar10 = LM_IsSawtooth(param_1);
  uVar6 = 0;
  if ((char)lVar10 != '\0') {
    *(uint *)(param_1 + 0x3d3) = *(byte *)(param_1 + 0x444) + 1;
    if (local_res10 != 0) {
      *(uint *)(param_1 + 0x3d3) = *(byte *)(param_1 + 0x444) + 8;
    }
  }
  uVar8 = LM_ReadPhy(param_1,2);
  *(uint *)(param_1 + 0x3d7) = (uVar8 & 0xffff) << 10;
  uVar8 = LM_ReadPhy(param_1,3);
  uVar8 = (uVar8 & 0xfc00) << 0x10 | uVar8 & 0x3ff | *(uint *)(param_1 + 0x3d7);
  *(uint *)(param_1 + 0x3d7) = uVar8;
  uVar11 = LM_Is5705Family(param_1);
  if ((char)uVar11 != '\0') {
    *(undefined4 *)(param_1 + 0x405) = 0x200020;
    *(undefined2 *)(param_1 + 0x409) = 0x20;
    *(undefined1 *)(param_1 + 0x40b) = 0;
  }
  uVar8 = uVar8 & 0xfffffff0;
  if ((uVar8 != 0x5c0d8920) && (uVar8 != 0x5c0d8a60)) {
    if (uVar8 == 0x60010140) {
      *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) | 0x20;
    }
    else if (uVar8 == 0xbc050c70) {
      *(undefined1 *)(param_1 + 0x40c) = 0;
    }
    else if (((uVar8 != 0xbc050ca0) && (uVar8 != 0xbc050d70)) && (uVar8 != 0xbc050f60)) {
      if ((bVar1) && (local_res10 != 0)) {
        *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) | 0x20;
      }
      if ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) != 0x7000) {
        *(undefined4 *)(param_1 + 0x3d7) = 0x60008110;
      }
    }
  }
  uVar11 = LM_Is5705Family(param_1);
  uVar8 = uVar6;
  if (((char)uVar11 != '\0') && ((*(byte *)(param_1 + 0x3fe) & 0x10) != 0)) {
    uVar8 = 0x400000;
  }
  lm_reg_wr_ind(param_1,0x74,uVar8);
  iVar7 = lm_reg_read_ind(param_1,0x414);
  if ((((((*(ushort *)(param_1 + 0x3fe) & 1) == 0) ||
        ((uVar8 = *(uint *)(param_1 + 0x3ca) >> 0xc, uVar8 != 7 && (uVar8 != 0)))) && (iVar7 != 0))
      && (iVar5 != 0x20031028)) ||
     ((*(char *)(param_1 + 0x404) != '\0' || ((*(ushort *)(param_1 + 0x3fe) & 0x20) != 0)))) {
    uVar8 = LM_ReadPhy(param_1,9);
    if ((uVar8 & 0x300) != 0) {
      if (*(char *)(param_1 + 0x40c) == '\0') {
        uVar13 = 0;
      }
      else if ((*(ushort *)(param_1 + 0x3fe) & 0x400) == 0) {
        uVar13 = 0x300;
      }
      else {
        uVar13 = 0x200;
      }
      LM_WritePhy(param_1,9,uVar13);
      LM_WritePhy(param_1,0,0x1200);
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x404) = 1;
    LM_ResetPhy(param_1);
  }
  if (*(int *)(param_1 + 0x3ca) == 0x5784100) {
    LM_ReadOtpMemory(param_1);
  }
  LM_PhyConfigWorkaround(param_1);
  uVar12 = LM_FindPciCapabilityPtr(param_1,'\x10');
  *(char *)(param_1 + 0x462) = (char)uVar12;
  uVar12 = LM_FindPciCapabilityPtr(param_1,'\x01');
  *(char *)(param_1 + 0x461) = (char)uVar12;
  uVar8 = LM_NvramRead(param_1,0);
  if (uVar8 == 0xffffffff) goto LAB_14000cd1d;
  if ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0xc000) {
    uVar6 = lm_reg_read_ind(param_1,0x5114);
  }
  else {
    if ((uVar8 & 0xff000000) != 0xa5000000) {
      if (uVar8 == 0x669955aa) {
        bVar3 = *(byte *)(param_1 + 0x444);
        uVar6 = LM_NvramRead(param_1,((bVar3 & 1) << 4 | 0xc4) +
                                     (~(((uint)bVar3 - (uint)bVar3) - (uint)(bVar3 < 2)) & 0x18c));
      }
      else {
        storport_pci_cfg_write_dword(param_1,0x7c,0xd34);
        uVar6 = storport_pci_cfg_read_dword(param_1,0x84);
      }
      *(uint *)(param_1 + 0x452) = uVar6;
      *(byte *)(param_1 + 0x3fd) = (byte)(uVar6 >> 2) & 0xf;
      *(byte *)(param_1 + 0x441) = (byte)(uVar6 >> 0x14) & 3;
      if ((uVar6 >> 0x1d & 1) != 0) {
        uVar6 = LM_NvramRead(param_1,(-(uint)(*(byte *)(param_1 + 0x444) < 2) & 0xfffffe74) + 0x228)
        ;
        if ((*(byte *)(param_1 + 0x444) & 1) == 0) {
          uVar6 = uVar6 >> 0x10;
        }
        *(short *)(param_1 + 0x456) = (short)uVar6;
      }
      goto LAB_14000cd1d;
    }
    if ((uVar8 >> 0x10 & 0xffe0) == 0xa520) {
      if (((byte)(uVar8 >> 0x10) & 0x1f) < 2) {
        uVar8 = LM_NvramRead(param_1,0x10);
        if ((uVar8 >> 0x16 & 1) == 0 || (uVar8 & 0x300000) == 0) goto LAB_14000ccd3;
        uVar9 = -(uint)((uVar8 & 0x10000) != 0) & 4;
        uVar6 = uVar9 + 0x24;
        if ((uVar8 >> 0x11 & 1) == 0) {
          uVar6 = uVar9 + 0x14;
        }
        uVar9 = uVar6 + 0x30;
        if ((uVar8 >> 0x12 & 1) == 0) {
          uVar9 = uVar6;
        }
        uVar6 = uVar9 + 0x4c;
        if ((uVar8 & 0x80000) == 0) {
          uVar6 = uVar9;
        }
        uVar8 = LM_NvramRead(param_1,uVar6);
        uVar6 = uVar6 + (((uVar8 >> 0xd & 0x1f) + 1 >> 1) + 2) * 4;
      }
      else {
        uVar6 = (uint)*(byte *)(param_1 + 0x444) * 4 + 0x10;
      }
      uVar6 = LM_NvramRead(param_1,uVar6);
    }
  }
LAB_14000ccd3:
  *(undefined4 *)(param_1 + 0x452) = 0;
  if ((uVar6 & 0x10000) != 0) {
    *(undefined4 *)(param_1 + 0x452) = 0x20000000;
    *(short *)(param_1 + 0x456) = (short)uVar6;
  }
  *(byte *)(param_1 + 0x441) = (byte)(uVar6 >> 0x13) & 3;
  *(byte *)(param_1 + 0x3fd) = (byte)(uVar6 >> 0x1b) & 0xf;
LAB_14000cd1d:
  if (*(char *)(param_1 + 0x3c1) == '\x01') {
    uVar8 = storport_pci_cfg_read_dword(param_1,0x40);
    uVar6 = *(uint *)(param_1 + 0x3ca);
    uVar9 = uVar8 & 0xfffdffff;
    if ((uVar6 >> 0xc < 10) && ((0x324U >> (uVar6 >> 0xc & 0x1f) & 1) != 0)) {
      uVar9 = uVar8 & 0xff89ffff | 0x80000;
    }
    *(uint *)(param_1 + 0x3c6) = uVar9;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x3ca);
  }
  *(undefined4 *)(param_1 + 0x3f3) = 0x8000;
  uVar4 = 0x18000;
  if ((uVar6 & 0xfffff000) == 0x2000) {
    uVar4 = 0x10000;
  }
  *(undefined4 *)(param_1 + 0x3f7) = uVar4;
  *(undefined4 *)(param_1 + 0x3ed) = 5;
  *(undefined1 *)(param_1 + 0x3fb) = 1;
  uVar11 = MM_GetConfig(param_1);
  if ((int)uVar11 != 0) {
    return uVar11;
  }
  if (*(char *)(param_1 + 0x3e0) == '\0') {
    *(char *)(param_1 + 0x3e0) = (*(short *)(param_1 + 0x3ce) == 0x1028) + '\x01';
  }
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x14);
  uVar13 = *(ushort *)(param_1 + 0x3fe) & 0x20;
  if (uVar13 != 0) {
    *(undefined4 *)(param_1 + 0x398) = 0;
    *(undefined1 *)(param_1 + 0x3e0) = 2;
  }
  if ((((*(int *)(param_1 + 0x3ca) == 0x57785100) || (*(int *)(param_1 + 0x3ca) == 0x5717100)) ||
      ((*(short *)(param_1 + 0x3ba) + 0xe9a9U & 0xfff7) == 0)) &&
     ((*(int *)(param_1 + 0x3db) == 0 && (uVar13 == 0)))) {
    storport_pci_cfg_write_dword(param_1,0x7c,0xd38);
    uVar6 = storport_pci_cfg_read_dword(param_1,0x84);
    if ((uVar6 & 0x2000) != 0) {
      uVar13 = *(ushort *)(param_1 + 0x3fe);
      *(ushort *)(param_1 + 0x3fe) = uVar13 | 0x80;
      lVar10 = LM_IsSawtooth(param_1);
      if (((char)lVar10 != '\0') || (uVar11 = LM_IsLogan(param_1), (char)uVar11 != '\0')) {
        *(ushort *)(param_1 + 0x3fe) = uVar13 | 0x180;
      }
    }
  }
  return 0;
}



===== LM_GetGPIO2 @ 14000ce9c =====

uint LM_GetGPIO2(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = lm_reg_read_ind(param_1,0x6808);
  lm_reg_wr_ind(param_1,0x6808,uVar1 & 0xffffdfff);
  uVar1 = lm_reg_read_ind(param_1,0x6808);
  return CONCAT31((uint3)(uVar1 >> 0x12),(char)(uVar1 >> 10)) & 0xffffff01;
}



===== LM_Halt @ 14000cedc =====

undefined8 LM_Halt(longlong param_1,char param_2)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 0x3fe) & 2) != 0) {
    LM_AsfSendMbox(param_1,2);
  }
  if (param_2 != '\0') {
    LM_Abort(param_1);
  }
  LM_ResetChip(param_1,(-(uint)((*(byte *)(param_1 + 0x3fe) & 2) != 0) & 0xfffffffe) + 4);
  storport_pci_cfg_write_dword(param_1,0x7c,0xd38);
  uVar1 = storport_pci_cfg_read_dword(param_1,0x84);
  if (((uVar1 >> 0xd & 1) != 0) && ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x57766000)) {
    uVar1 = lm_reg_read_ind(param_1,14000);
    lm_reg_wr_ind(param_1,14000,uVar1 | 0x80);
  }
  if ((*(byte *)(param_1 + 0x3fe) & 8) != 0) {
    lm_reg_wr_ind(param_1,0x1421c,2);
    LM_ApeSendEvent(param_1,0x20510);
  }
  LM_MemWrInd(param_1,0xd4c,*(undefined4 *)(param_1 + 0x3f3));
  LM_DisableInterrupt(param_1);
  if (*(char *)(param_1 + 0x458) != '\0') {
    lm_reg_wr_ind(param_1,0x7d28,*(undefined4 *)(param_1 + 0x459));
  }
  mm_stall(100);
  return 0;
}



===== LM_HaltCpu @ 14000cff4 =====

bool LM_HaltCpu(longlong param_1,int param_2)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar2 = LM_Is5705Family(param_1);
  if (((char)uVar2 == '\0') || (param_2 == 1)) {
    uVar4 = 0;
    iVar3 = 0x5000;
    if (param_2 != 1) {
      iVar3 = 0x5400;
    }
    do {
      lm_reg_wr_ind(param_1,iVar3 + 4,0xffffffff);
      lm_reg_wr_ind(param_1,iVar3,0x400);
      uVar1 = lm_reg_read_ind(param_1,iVar3);
      if ((uVar1 >> 10 & 1) != 0) break;
      mm_stall(10);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 10000);
    bVar5 = uVar4 == 10000;
  }
  else {
    bVar5 = true;
  }
  return bVar5;
}



===== LM_InitializeAdapter @ 14000d0a4 =====

undefined8 LM_InitializeAdapter(longlong param_1)

{
  undefined8 uVar1;
  int iVar3;
  uint uVar2;
  uint uVar4;
  longlong lVar5;
  
  *(undefined8 *)(param_1 + 0xf0) = 0x11;
  *(undefined8 *)(param_1 + 0xe8) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x1a0) = 0;
  *(undefined8 *)(param_1 + 0x1f8) = 0;
  *(undefined8 *)(param_1 + 0x250) = 0;
  *(undefined8 *)(param_1 + 0x2a8) = 0;
  *(undefined8 *)(param_1 + 0x3c) = 0;
  *(undefined8 *)(param_1 + 0x44) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0x11;
  *(undefined8 *)(param_1 + 0x1a8) = 9;
  *(undefined8 *)(param_1 + 0x200) = 9;
  *(undefined8 *)(param_1 + 600) = 9;
  *(undefined8 *)(param_1 + 0x2b0) = 9;
  uVar1 = MM_InitializeDeviceResources(param_1);
  if ((int)uVar1 == 0) {
    *(undefined4 *)(param_1 + 0x19c) = 0;
    *(undefined1 *)(param_1 + 0x3f1) = 0;
    uVar4 = 0;
    if (*(int *)(param_1 + 0x198) != 0) {
      do {
        lVar5 = (ulonglong)uVar4 * 0x54;
        *(undefined4 *)(&DAT_1400831ee + lVar5) = 0;
        *(undefined2 *)(&DAT_1400831e6 + lVar5) = 0;
        iVar3 = *(int *)(param_1 + 0x1a4);
        if (iVar3 == 0) {
          iVar3 = *(int *)(param_1 + 0x1a8);
        }
        uVar2 = iVar3 - 1;
        if (uVar2 != *(uint *)(param_1 + 0x1a0)) {
          *(undefined **)(param_1 + 0x1b0 + (ulonglong)uVar2 * 8) = &t3_packet_ring + lVar5;
          *(int *)(param_1 + 0x1ac) = *(int *)(param_1 + 0x1ac) + 1;
          *(uint *)(param_1 + 0x1a4) = uVar2;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(param_1 + 0x198));
    }
    if (*(uint *)(param_1 + 0x14) < 0x11) {
      *(undefined **)(param_1 + 8) = &t3_packet_ring;
      uVar4 = 0;
      if (*(uint *)(param_1 + 0x14) != 0) {
        do {
          lVar5 = (ulonglong)(uVar4 + 8) * 0x54;
          *(undefined4 *)(&DAT_1400831ea + lVar5) = 1;
          *(undefined4 *)(&DAT_1400831ee + lVar5) = 0x600;
          iVar3 = *(int *)(param_1 + 0x54);
          if (iVar3 == 0) {
            iVar3 = *(int *)(param_1 + 0x58);
          }
          uVar2 = iVar3 - 1;
          if (uVar2 != *(uint *)(param_1 + 0x50)) {
            *(undefined **)(param_1 + 0x60 + (ulonglong)uVar2 * 8) = &t3_packet_ring + lVar5;
            *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
            *(uint *)(param_1 + 0x54) = uVar2;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(param_1 + 0x14));
      }
      uVar1 = MM_InitializeUmPackets(param_1);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
      *(undefined4 *)(param_1 + 0x38c) = 7;
      lm_reg_wr_ind(param_1,0x7c,0);
      uVar1 = LM_ResetAdapter(param_1);
      if ((int)uVar1 == 0) {
        *(undefined1 *)(param_1 + 0x3f2) = 1;
        return uVar1;
      }
      return uVar1;
    }
  }
  return 1;
}



===== LM_Is5705Family @ 14000d238 =====

undefined8 LM_Is5705Family(longlong param_1)

{
  ulonglong uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if (((((uVar2 < 0xd) && (uVar1 = 0x1f78, (0x1f78U >> (uVar2 & 0x1f) & 1) != 0)) ||
       (uVar1 = (ulonglong)(uVar2 - 0x5784), uVar2 - 0x5784 < 2)) ||
      ((uVar2 == 0x5761 || (uVar2 == 0x57780)))) ||
     ((uVar1 = LM_IsSawtooth(param_1), (char)uVar1 != '\0' ||
      ((uVar1 = LM_IsAspen(param_1), (char)uVar1 != '\0' ||
       (uVar1 = LM_IsLogan(param_1), (char)uVar1 != '\0')))))) {
    return CONCAT71((int7)(uVar1 >> 8),1);
  }
  return uVar1;
}



===== LM_Is575xFamily @ 14000d2a0 =====

undefined8 LM_Is575xFamily(longlong param_1)

{
  ulonglong uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if (((((uVar2 < 0xd) && (uVar1 = 0x1c50, (0x1c50U >> (uVar2 & 0x1f) & 1) != 0)) ||
       (uVar1 = (ulonglong)(uVar2 - 0x5784), uVar2 - 0x5784 < 2)) ||
      ((uVar2 == 0x5761 || (uVar2 == 0x57780)))) ||
     ((uVar1 = LM_IsSawtooth(param_1), (char)uVar1 != '\0' ||
      ((uVar1 = LM_IsAspen(param_1), (char)uVar1 != '\0' ||
       (uVar1 = LM_IsLogan(param_1), (char)uVar1 != '\0')))))) {
    return CONCAT71((int7)(uVar1 >> 8),1);
  }
  return uVar1;
}



===== LM_IsAspen @ 14000d308 =====

longlong LM_IsAspen(longlong param_1)

{
  ushort uVar1;
  uint7 uVar2;
  
  uVar1 = *(short *)(param_1 + 0x3ba) + 0xe97e;
  uVar2 = (uint7)(byte)(uVar1 >> 8);
  if ((uVar1 < 0x36) && ((0x3fc00000000011U >> ((ulonglong)uVar1 & 0x3f) & 1) != 0)) {
    return CONCAT71(uVar2,1);
  }
  return (ulonglong)uVar2 << 8;
}



===== LM_IsLinkStatusUp @ 14000d334 =====

ulonglong LM_IsLinkStatusUp(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 extraout_var;
  
  if (((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x9000) &&
     ((*(byte *)(param_1 + 0x3fe) & 0x20) != 0)) {
    uVar2 = lm_reg_read_ind(param_1,0x460);
    uVar2 = uVar2 & 0xffffffffffffff08;
  }
  else {
    LM_ReadPhy(param_1,1);
    uVar1 = LM_ReadPhy(param_1,1);
    uVar2 = CONCAT71((int7)(CONCAT44(extraout_var,uVar1) >> 8),(char)uVar1) & 0xffffffffffffff04;
  }
  return uVar2;
}



===== LM_IsLogan @ 14000d388 =====

undefined8 LM_IsLogan(longlong param_1)

{
  short sVar1;
  ulonglong uVar2;
  
  sVar1 = *(short *)(param_1 + 0x3ba);
  uVar2 = 0x1687;
  if ((((sVar1 == 0x1687) ||
       (uVar2 = (ulonglong)(ushort)(sVar1 + 0xe9bfU), (ushort)(sVar1 + 0xe9bfU) < 3)) ||
      (uVar2 = 0x1683, sVar1 == 0x1683)) || (uVar2 = 0x16f3, sVar1 == 0x16f3)) {
    return CONCAT71((int7)(uVar2 >> 8),1);
  }
  return 0x1600;
}



===== LM_IsPhy6G @ 14000d3c0 =====

undefined8 LM_IsPhy6G(longlong param_1)

{
  ulonglong uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  uVar1 = (ulonglong)(uVar2 - 10);
  if ((((uVar2 - 10 < 2) || (uVar1 = (ulonglong)(uVar2 - 0x5784), uVar2 - 0x5784 < 2)) ||
      (uVar2 == 0x5761)) ||
     (((uVar2 == 0x57780 || (uVar1 = LM_IsSawtooth(param_1), (char)uVar1 != '\0')) ||
      ((uVar1 = LM_IsAspen(param_1), (char)uVar1 != '\0' ||
       (uVar1 = LM_IsLogan(param_1), (char)uVar1 != '\0')))))) {
    return CONCAT71((int7)(uVar1 >> 8),1);
  }
  return uVar1;
}



===== LM_IsSawtooth @ 14000d420 =====

longlong LM_IsSawtooth(longlong param_1)

{
  ushort uVar1;
  uint7 uVar2;
  
  uVar1 = *(short *)(param_1 + 0x3ba) + 0xe9ab;
  uVar2 = (uint7)(byte)(uVar1 >> 8);
  if ((uVar1 < 0x11) && ((0x10487U >> (uVar1 & 0x1f) & 1) != 0)) {
    return CONCAT71(uVar2,1);
  }
  return (ulonglong)uVar2 << 8;
}



===== LM_MemWrInd @ 14000d448 =====

void LM_MemWrInd(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  storport_pci_cfg_write_dword(param_1,0x7c,param_2);
  storport_pci_cfg_write_dword(param_1,0x84,param_3);
  return;
}



===== LM_NvRamDisableFlashAccess @ 14000d47c =====

void LM_NvRamDisableFlashAccess(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x6000) &&
     (uVar1 = lm_reg_read_ind(param_1,0x7014), (uVar1 >> 0x1b & 1) != 0)) {
    return;
  }
  uVar2 = LM_Is575xFamily(param_1);
  if ((((char)uVar2 != '\0') || (uVar1 = *(uint *)(param_1 + 0x3ca) >> 0xc, uVar1 == 5)) ||
     (uVar1 - 8 < 2)) {
    lm_reg_wr_ind(param_1,0x7024,0);
  }
  return;
}



===== LM_NvRamEnableFlashAccess @ 14000d4e0 =====

void LM_NvRamEnableFlashAccess(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x6000) &&
     (uVar1 = lm_reg_read_ind(param_1,0x7014), (uVar1 >> 0x1b & 1) != 0)) {
    return;
  }
  uVar2 = LM_Is575xFamily(param_1);
  if ((((char)uVar2 != '\0') || (uVar1 = *(uint *)(param_1 + 0x3ca) >> 0xc, uVar1 == 5)) ||
     (uVar1 - 8 < 2)) {
    lm_reg_wr_ind(param_1,0x7024,1);
  }
  return;
}



===== LM_NvramAcquireFlashLock @ 14000d548 =====

void LM_NvramAcquireFlashLock(longlong param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if ((uVar1 != 0) && (uVar1 != 7)) {
    if ((*(uint *)(param_1 + 0x3ca) == 0xa000) &&
       (uVar1 = lm_reg_read_ind(param_1,0x5004), (uVar1 >> 10 & 1) == 0)) {
      LM_MemWrInd(param_1,0xb50,0x55555555);
      iVar3 = 0;
      do {
        storport_pci_cfg_write_dword(param_1,0x7c,0xb50);
        iVar2 = storport_pci_cfg_read_dword(param_1,0x84);
        if (iVar2 == -0x55555556) break;
        mm_stall(100);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 100);
    }
    lm_reg_wr_ind(param_1,0x7020,2);
    do {
      uVar1 = lm_reg_read_ind(param_1,0x7020);
      if ((uVar1 >> 9 & 1) != 0) {
        return;
      }
      mm_stall(10);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 25000);
  }
  return;
}



===== LM_NvramCilaiIntf @ 14000d624 =====

void LM_NvramCilaiIntf(longlong param_1,uint param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  
  uVar3 = lm_reg_read_ind(param_1,0x7038);
  if ((uVar3 & 0x20) == 0) {
    *(undefined1 *)(param_1 + 0x44d) = 1;
    uVar2 = 4;
  }
  else {
    if (((uVar3 & 0x1f0000) - 1 < 0x20000) || (0x70000 < (uVar3 & 0x1f0000))) {
      uVar1 = 2;
    }
    else {
      uVar1 = 0;
    }
    *(undefined1 *)(param_1 + 0x44d) = uVar1;
    uVar3 = param_2 >> 0x1c & 7;
    if (uVar3 == 0) {
      uVar2 = 0x100;
    }
    else if (uVar3 == 1) {
      uVar2 = 0x200;
    }
    else if (uVar3 == 2) {
      uVar2 = 0x400;
    }
    else if (uVar3 == 3) {
      uVar2 = 0x800;
    }
    else if (uVar3 == 4) {
      uVar2 = 0x1000;
    }
    else {
      if (uVar3 != 5) {
        return;
      }
      uVar2 = 0x108;
    }
  }
  *(undefined2 *)(param_1 + 0x44f) = uVar2;
  return;
}



===== LM_NvramInit @ 14000d6d0 =====

void LM_NvramInit(longlong param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar2 = lm_reg_read_ind(param_1,0x6808);
  lm_reg_wr_ind(param_1,0x6808,uVar2 | 0x1000000);
  lm_reg_wr_ind(param_1,0x6848,0);
  *(undefined1 *)(param_1 + 0x44d) = 1;
  *(undefined2 *)(param_1 + 0x44f) = 4;
  uVar2 = lm_reg_read_ind(param_1,0x7014);
  if ((uVar2 >> 0x1b & 1) != 0) {
    *(undefined1 *)(param_1 + 0x44e) = 1;
  }
  uVar5 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if (((uVar5 - 4 & 0xfffffffa) == 0) && (uVar5 != 5)) {
    uVar5 = uVar2 & 0x3000003;
    uVar2 = 0x2000000;
    if (uVar5 != 0x2000000) {
      if (uVar5 != 0x2000003) {
        *(undefined1 *)(param_1 + 0x44d) = 2;
        *(undefined2 *)(param_1 + 0x44f) = 0x100;
        if (uVar5 == 0x1000003) {
          uVar6 = 0x50081;
        }
        else {
          if (uVar5 != 0x3000001) {
            return;
          }
          uVar6 = 0x500db;
        }
        LM_NvramIntf(param_1,0,uVar6,0,0xaf020406,10);
        return;
      }
      uVar1 = 0x108;
LAB_14000d8d4:
      *(undefined2 *)(param_1 + 0x44f) = uVar1;
      *(undefined1 *)(param_1 + 0x44d) = 0;
      return;
    }
    goto LAB_14000d8e6;
  }
  if (uVar5 == 6) {
    if ((uVar2 & 0x3c00003) == 0) {
      uVar2 = 0;
      goto LAB_14000d8e6;
    }
    *(undefined1 *)(param_1 + 0x44d) = 0;
    if ((uVar2 & 0x3c00003) != 0x2000003) {
      uVar1 = 0x100;
      goto LAB_14000d850;
    }
  }
  else {
    if (uVar5 == 0xb) {
      if ((*(char *)(param_1 + 0x3bc) - 4U & 0xfd) == 0) goto LAB_14000d865;
    }
    else {
      if (uVar5 == 10) {
LAB_14000d865:
        LM_NvramStanfordIntf(param_1);
        return;
      }
      if (1 < uVar5 - 0x5784) {
        if ((uVar5 == 0x5761) ||
           ((uVar3 = LM_IsLogan(param_1), (char)uVar3 != '\0' ||
            (lVar4 = LM_IsSawtooth(param_1), (char)lVar4 != '\0')))) {
          uVar1 = 0x100;
          goto LAB_14000d8d4;
        }
        if ((uVar5 - 0x57766 < 0x20) && ((0x84000001U >> (uVar5 - 0x57766 & 0x1f) & 1) != 0)) {
          LM_NvramCilaiIntf(param_1,uVar2);
          return;
        }
        if ((uVar2 & 3) == 0) goto LAB_14000d8e6;
        *(undefined1 *)(param_1 + 0x44d) = 0;
        goto LAB_14000d84b;
      }
    }
    uVar2 = uVar2 & 0x3c00003;
    if (uVar2 + 0xfcfffffe < 2) {
LAB_14000d8e6:
      LM_NvramSeepromIntf(param_1,uVar2);
      return;
    }
    *(undefined1 *)(param_1 + 0x44d) = 0;
    if ((uVar2 != 0x2000003) && (uVar1 = 0x100, 2 < uVar2 + 0xfcc00000)) goto LAB_14000d850;
  }
LAB_14000d84b:
  uVar1 = 0x108;
LAB_14000d850:
  *(undefined2 *)(param_1 + 0x44f) = uVar1;
  return;
}



===== LM_NvramIntf @ 14000d904 =====

void LM_NvramIntf(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,byte param_6)

{
  LM_NvramAcquireFlashLock(param_1);
  LM_NvRamEnableFlashAccess(param_1);
  if ((param_6 & 1) != 0) {
    lm_reg_wr_ind(param_1,0x7014,param_2);
  }
  if ((param_6 & 2) != 0) {
    lm_reg_wr_ind(param_1,0x7018,param_3);
  }
  if ((param_6 & 4) != 0) {
    lm_reg_wr_ind(param_1,0x701c,param_4);
  }
  if ((param_6 & 8) != 0) {
    lm_reg_wr_ind(param_1,0x7028,param_5);
  }
  LM_NvRamDisableFlashAccess(param_1);
  LM_NvramReleaseFlashLock(param_1);
  return;
}



===== LM_NvramRead @ 14000d9b4 =====

uint LM_NvramRead(longlong param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (*(short *)(param_1 + 0x44f) == 0x108) {
    param_2 = param_2 + (param_2 / 0x108) * 0xf8;
  }
  LM_NvramAcquireFlashLock(param_1);
  LM_NvRamEnableFlashAccess(param_1);
  lm_reg_wr_ind(param_1,0x700c,param_2 & 0xffffff);
  lm_reg_wr_ind(param_1,0x7000,0x198);
  uVar2 = 0;
  do {
    mm_stall(1);
    uVar1 = lm_reg_read_ind(param_1,0x7000);
    if ((uVar1 & 8) != 0) {
      mm_stall(10);
      uVar1 = lm_reg_read_ind(param_1,0x7010);
      break;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 1000);
  LM_NvRamDisableFlashAccess(param_1);
  LM_NvramReleaseFlashLock(param_1);
  return uVar1;
}



===== LM_NvramReleaseFlashLock @ 14000da84 =====

void LM_NvramReleaseFlashLock(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if ((uVar1 != 0) && (uVar1 != 7)) {
    lm_reg_wr_ind(param_1,0x7020,0x20);
    if (*(int *)(param_1 + 0x3ca) == 0xa000) {
      lm_reg_read_ind(param_1,0x703c);
      LM_MemWrInd(param_1,0xb50,0);
      mm_stall(0x14);
    }
  }
  return;
}



===== LM_NvramSeepromIntf @ 14000dae8 =====

void LM_NvramSeepromIntf(longlong param_1,uint param_2)

{
  lm_reg_wr_ind(param_1,0x7014,param_2 & 0x7fe007ff | 0x14800);
  *(undefined1 *)(param_1 + 0x44d) = 1;
  *(undefined2 *)(param_1 + 0x44f) = 4;
  return;
}



===== LM_NvramStanfordIntf @ 14000db24 =====

void LM_NvramStanfordIntf(longlong param_1)

{
  undefined2 uVar1;
  ulonglong uVar2;
  
  uVar2 = lm_reg_read_ind(param_1,0x7038);
  *(undefined1 *)(param_1 + 0x44d) = 0;
  if ((uVar2 & 0x70000) == 0) {
    if ((uVar2 & 0xe380000) == 0) {
      *(undefined1 *)(param_1 + 0x44d) = 1;
      uVar1 = 4;
    }
    else {
      uVar1 = 0x100;
    }
  }
  else {
    uVar1 = 0x108;
  }
  *(undefined2 *)(param_1 + 0x44f) = uVar1;
  return;
}



===== LM_PhyCableAttached @ 14000db74 =====

ulonglong LM_PhyCableAttached(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_1 + 0x3ca) & 0xfffff000;
  uVar3 = (ulonglong)uVar1;
  if (uVar1 == 0xc000) {
LAB_14000dbf0:
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  else {
    lVar2 = LM_IsSawtooth(param_1);
    iVar4 = 0;
    if (((char)lVar2 == '\0') || ((*(byte *)(param_1 + 0x3fe) & 0x20) == 0)) {
      LM_WritePhy(param_1,0x1c,0x7c00);
      do {
        uVar1 = LM_ReadPhy(param_1,0x1c);
        uVar3 = CONCAT44(extraout_var_00,uVar1);
        if ((uVar1 & 0x30) != 0) goto LAB_14000dbf0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 5);
    }
    else {
      do {
        uVar1 = LM_ReadPhy(param_1,0x16);
        uVar3 = CONCAT44(extraout_var,uVar1);
        if ((uVar1 & 0x40) != 0) goto LAB_14000dbf0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 5);
    }
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  return uVar3;
}



===== LM_PhyConfigWorkaround @ 14000dc00 =====

void LM_PhyConfigWorkaround(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  ushort local_res10;
  
  uVar2 = LM_IsPhy6G(param_1);
  if ((char)uVar2 == '\x01') {
    if (((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0xa000) &&
       ((*(byte *)(param_1 + 0x3bc) & 4) != 0)) {
      LM_WritePhy(param_1,0x18,0xc00);
      local_res10 = 0x110b;
      uVar5 = 0x15;
      uVar1 = 0x17;
      uVar6 = 0x1e;
      uVar4 = 0x14;
      uVar3 = 10;
    }
    else {
      uVar6 = 0x15;
      uVar4 = 0x10b;
      local_res10 = 10;
      uVar3 = 0xc00;
      uVar1 = 0x18;
      uVar5 = 0x17;
    }
    LM_WritePhy(param_1,uVar1,uVar3);
    LM_WritePhy(param_1,uVar5,local_res10);
    LM_WritePhy(param_1,uVar6,uVar4);
    LM_WritePhy(param_1,0x18,0x400);
    if (*(int *)(param_1 + 0x3ca) != 0x5784100) {
      return;
    }
    LM_WritePhy(param_1,0x1c,0x941f);
    LM_WritePhy(param_1,0x18,0xc00);
    if (*(short *)(param_1 + 0x45d) == 0) {
      LM_WritePhy(param_1,0x17,1);
      LM_WritePhy(param_1,0x15,0x27);
      LM_WritePhy(param_1,0x17,0x1f);
      LM_WritePhy(param_1,0x15,0x300);
      LM_WritePhy(param_1,0x17,0x601f);
      LM_WritePhy(param_1,0x15,2);
      LM_WritePhy(param_1,0x17,0xf75);
      LM_WritePhy(param_1,0x15,0x28);
      LM_WritePhy(param_1,0x17,0xf96);
      LM_WritePhy(param_1,0x15,0x10);
      LM_WritePhy(param_1,0x17,0xf97);
      uVar3 = 0xc0c;
    }
    else {
      LM_WritePhy(param_1,0x17,1);
      uVar1 = LM_ReadPhy(param_1,0x15);
      LM_WritePhy(param_1,0x15,
                  (ushort)((uint)*(undefined4 *)(param_1 + 0x45d) >> 0x11) & 0x70 |
                  (ushort)uVar1 & 0xff8f);
      LM_WritePhy(param_1,0x17,0x1f);
      uVar1 = LM_ReadPhy(param_1,0x15);
      LM_WritePhy(param_1,0x15,
                  (ushort)((uint)*(undefined4 *)(param_1 + 0x45d) >> 0x11) & 0x380 |
                  (ushort)uVar1 & 0xfc7f);
      LM_WritePhy(param_1,0x17,0x601f);
      uVar1 = LM_ReadPhy(param_1,0x15);
      LM_WritePhy(param_1,0x15,
                  (ushort)((uint)*(undefined4 *)(param_1 + 0x45d) >> 0x1b) & 1 |
                  (ushort)uVar1 & 0xfffe);
      LM_WritePhy(param_1,0x17,0xf96);
      uVar1 = LM_ReadPhy(param_1,0x15);
      LM_WritePhy(param_1,0x15,(ushort)(*(byte *)(param_1 + 0x460) & 0xf0) | (ushort)uVar1 & 0xff0f)
      ;
      LM_WritePhy(param_1,0x17,0xf97);
      uVar1 = LM_ReadPhy(param_1,0x15);
      LM_WritePhy(param_1,0x15,*(ushort *)(param_1 + 0x45d) & 0x1c | (ushort)uVar1 & 0xffe3);
      LM_WritePhy(param_1,0x17,0xf97);
      uVar1 = LM_ReadPhy(param_1,0x15);
      LM_WritePhy(param_1,0x15,(*(ushort *)(param_1 + 0x45d) & 0xe0) << 5 | (ushort)uVar1 & 0xe3ff);
      LM_WritePhy(param_1,0x17,0xf75);
      uVar1 = LM_ReadPhy(param_1,0x15);
      uVar3 = (ushort)((uint)*(undefined4 *)(param_1 + 0x45d) >> 8) & 0xff | (ushort)uVar1 & 0xff00;
    }
  }
  else {
    uVar2 = LM_Is5705Family(param_1);
    if ((char)uVar2 == '\0') {
      return;
    }
    if ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0xc000) {
      return;
    }
    LM_WritePhy(param_1,0x18,0xc00);
    LM_WritePhy(param_1,0x17,10);
    LM_WritePhy(param_1,0x15,0x310b);
    LM_WritePhy(param_1,0x17,0x201f);
    LM_WritePhy(param_1,0x15,0x9506);
    LM_WritePhy(param_1,0x17,0x401f);
    uVar3 = 0x14e2;
  }
  LM_WritePhy(param_1,0x15,uVar3);
  LM_WritePhy(param_1,0x18,0x400);
  return;
}



===== LM_QueueRxPackets @ 14000e068 =====

undefined8 LM_QueueRxPackets(longlong param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0x50);
  iVar5 = 0;
  if (iVar1 != *(int *)(param_1 + 0x54)) {
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x58);
    }
    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + -1;
    *(uint *)(param_1 + 0x50) = iVar1 - 1U;
    lVar4 = *(longlong *)(param_1 + 0x60 + (ulonglong)(iVar1 - 1U) * 8);
    if (lVar4 != 0) {
      do {
        iVar5 = iVar5 + 1;
        puVar3 = (undefined4 *)
                 ((ulonglong)*(uint *)(param_1 + 0x18) * 0x20 + *(longlong *)(param_1 + 0x1c));
        *(undefined2 *)(puVar3 + 3) = 4;
        *(undefined2 *)(puVar3 + 2) = 0x5f2;
        puVar3[1] = *(undefined4 *)(lVar4 + 0x1a);
        *puVar3 = *(undefined4 *)(lVar4 + 0x1e);
        puVar3[7] = (int)lVar4 - *(int *)(param_1 + 8);
        uVar2 = *(ushort *)(param_1 + 0x407) - 1 & *(int *)(param_1 + 0x18) + 1U;
        *(uint *)(param_1 + 0x18) = uVar2;
        iVar1 = *(int *)(param_1 + 0x50);
        if (iVar1 == *(int *)(param_1 + 0x54)) break;
        if (iVar1 == 0) {
          iVar1 = *(int *)(param_1 + 0x58);
        }
        *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + -1;
        *(uint *)(param_1 + 0x50) = iVar1 - 1U;
        lVar4 = *(longlong *)(param_1 + 0x60 + (ulonglong)(iVar1 - 1U) * 8);
      } while (lVar4 != 0);
      if (iVar5 != 0) {
        lm_reg_wr_ind(param_1,0x586c,uVar2);
      }
    }
  }
  return 0;
}



===== LM_ReadOtpMemory @ 14000e12c =====

void LM_ReadOtpMemory(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 0x45d) = 0;
  lm_reg_wr_ind(param_1,0x7500,1);
  lm_reg_wr_ind(param_1,0x7504,0x200009);
  lm_reg_wr_ind(param_1,0x7504,0x200008);
  uVar3 = 0;
  do {
    mm_stall(10);
    uVar1 = lm_reg_read_ind(param_1,0x7508);
    if ((uVar1 & 1) != 0) break;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 5000);
  if ((uVar1 & 1) != 0) {
    uVar3 = 0;
    do {
      lm_reg_wr_ind(param_1,0x750c,(-(uint)(uVar3 != 0) & 0xffffffe2) + 0xa0);
      lm_reg_wr_ind(param_1,0x7504,0x200001);
      lm_reg_wr_ind(param_1,0x7504,0x200000);
      uVar1 = 0;
      do {
        mm_stall(10);
        uVar2 = lm_reg_read_ind(param_1,0x7508);
        if ((uVar2 & 1) != 0) break;
        uVar1 = uVar1 + 1;
      } while (uVar1 < 5000);
      if ((uVar2 & 1) == 0) {
        return;
      }
      uVar1 = lm_reg_read_ind(param_1,0x7514);
      if (uVar3 == 0) {
        *(uint *)(param_1 + 0x45d) = uVar1 & 0xffff;
      }
      else {
        *(uint *)(param_1 + 0x45d) = *(uint *)(param_1 + 0x45d) | uVar1 & 0xffe00000;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 2);
  }
  return;
}



===== LM_ReadPhy @ 14000e260 =====

uint LM_ReadPhy(longlong param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  lm_reg_wr_ind(param_1,0x44c,((*(uint *)(param_1 + 0x3d3) | 0x140) << 5 | param_2 & 0x1f) << 0x10);
  uVar4 = 0;
  uVar3 = 0;
  do {
    uVar2 = lm_reg_read_ind(param_1,0x44c);
    if ((uVar2 >> 0x1d & 1) == 0) {
      mm_stall(5);
      uVar1 = lm_reg_read_ind(param_1,0x44c);
      uVar2 = (uint)uVar1;
      break;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 10000);
  if (uVar3 != 10000) {
    uVar4 = uVar2 & 0xffff;
  }
  return uVar4;
}



===== LM_ResetAdapter @ 14000e2f4 =====

undefined8 LM_ResetAdapter(longlong param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  byte bVar8;
  undefined4 uVar9;
  
  storport_pci_cfg_write_dword(param_1,0x68,*(undefined4 *)(param_1 + 0x10));
  if ((*(byte *)(param_1 + 0x3fe) & 2) != 0) {
    LM_AsfSendMbox(param_1,2);
  }
  uVar2 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if ((((uVar2 - 0x5717 < 0xe) && ((0x2207U >> (uVar2 - 0x5717 & 0x1f) & 1) != 0)) ||
      (uVar2 == 0x5762)) || ((uVar2 == 0x57766 || (bVar8 = 0xb4, uVar2 == 0x57785)))) {
    bVar8 = 0x44;
  }
  iVar3 = storport_pci_cfg_read_dword(param_1,bVar8);
  if (iVar3 == 0) {
    storport_pci_cfg_write_dword(param_1,bVar8,0);
  }
  LM_DisableInterrupt(param_1);
  if (*(char *)(param_1 + 0x3f2) != '\0') {
    LM_Abort(param_1);
  }
  LM_ResetChip(param_1,(-(uint)((*(byte *)(param_1 + 0x3fe) & 2) != 0) & 0xfffffffd) + 4);
  if ((*(byte *)(param_1 + 0x3fe) & 8) != 0) {
    LM_ApeDriverStateChange(param_1,1);
  }
  lm_reg_wr_ind(param_1,0x6800,0x12);
  *(undefined4 *)(param_1 + 0x394) = 0;
  *(undefined4 *)(param_1 + 0x39c) = 0;
  lm_reg_wr_ind(param_1,0x7c,0);
  LM_EnableMemoryArbitor(param_1);
  uVar2 = 0xc;
  uVar7 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if ((uVar7 == 0xc) || ((*(uint *)(param_1 + 0x3d7) & 0xfffffff0) == 0xbc050c70)) {
    *(undefined4 *)(param_1 + 0x368) = 4;
    uVar2 = 4;
  }
  else {
    if ((((*(byte *)(param_1 + 0x3fe) & 0x20) != 0) && (uVar7 != 5)) && (1 < uVar7 - 8)) {
      *(undefined4 *)(param_1 + 0x368) = 0xc;
      lVar5 = LM_IsSawtooth(param_1);
      if ((char)lVar5 == '\0') goto LAB_14000e47c;
    }
    *(undefined4 *)(param_1 + 0x368) = 8;
    uVar2 = 8;
  }
LAB_14000e47c:
  if ((((*(byte *)(param_1 + 0x3fe) & 8) != 0) ||
      (lVar5 = LM_IsSawtooth(param_1), (char)lVar5 != '\0')) ||
     (uVar6 = LM_IsLogan(param_1), (char)uVar6 != '\0')) {
    uVar2 = lm_reg_read_ind(param_1,0x400);
    uVar2 = uVar2 | *(uint *)(param_1 + 0x368);
    *(uint *)(param_1 + 0x368) = uVar2;
    if (*(short *)(param_1 + 0x3ba) != 0x1657) {
      uVar2 = uVar2 | 0x18000000;
      *(uint *)(param_1 + 0x368) = uVar2;
    }
  }
  lm_reg_wr_ind(param_1,0x400,uVar2);
  uVar6 = LM_Is5705Family(param_1);
  if ((char)uVar6 == '\0') {
    uVar2 = 0;
    do {
      LM_MemWrInd(param_1,uVar2 + 0xb00,0);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x50);
  }
  **(undefined4 **)(param_1 + 0x2c) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x2c) + 10) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x2c) + 8) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x2c) + 0xc) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x2c) + 0x10) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x2c) + 0x12) = 0;
  lVar5 = LM_IsSawtooth(param_1);
  if ((char)lVar5 == '\0') {
    if (*(char *)(param_1 + 0x3c1) == '\0') {
      uVar6 = LM_Is5705Family(param_1);
      iVar3 = (-(uint)((char)uVar6 != '\0') & 0xfffffff1) + 0x763f000f;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x3ca) >> 0xc;
      if ((uVar2 == 5) || (uVar2 - 8 < 2)) {
        iVar3 = 0x76144000;
      }
      else {
        iVar3 = 0x761b400f;
        if (uVar2 == 2) {
          iVar3 = 0x761f4000;
        }
      }
    }
    lm_reg_wr_ind(param_1,0x6c,iVar3);
  }
  lm_reg_wr_ind(param_1,0x6800,
                (-(uint)(*(char *)(param_1 + 0x3f1) != '\0') & 0x20000000) + 0x4010034);
  lVar5 = LM_IsSawtooth(param_1);
  lm_reg_wr_ind(param_1,0x4410,(-(uint)((char)lVar5 != '\0') & 0xfffffff0) + 0x40);
  if ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0xc000) {
    uVar4 = 0x10;
    iVar3 = 4;
  }
  else {
    uVar4 = 0x60;
    lVar5 = LM_IsSawtooth(param_1);
    iVar3 = (-(uint)((char)lVar5 != '\0') & 0xfffffff0) + 0x20;
  }
  lm_reg_wr_ind(param_1,0x4414,iVar3);
  lm_reg_wr_ind(param_1,0x4418,uVar4);
  lm_reg_wr_ind(param_1,0x4434,5);
  lm_reg_wr_ind(param_1,0x4438,10);
  lVar5 = LM_IsSawtooth(param_1);
  if ((char)lVar5 != '\0') {
    lm_reg_wr_ind(param_1,0x2d00,0x20);
    lm_reg_wr_ind(param_1,0x2d04,0x10);
  }
  if (*(longlong *)(param_1 + 0x445) != 0) {
    uVar6 = LM_Is5705Family(param_1);
    if ((char)uVar6 != '\0') {
      uVar4 = lm_reg_read_ind(param_1,0x4408);
      *(undefined4 *)(param_1 + 0x3f3) = uVar4;
      uVar4 = lm_reg_read_ind(param_1,0x440c);
      *(undefined4 *)(param_1 + 0x3f7) = uVar4;
    }
    LM_MemWrInd(param_1,0xd4c,*(undefined4 *)(param_1 + 0x3f3));
    *(int *)(param_1 + 0x3f3) = *(int *)(param_1 + 0x3f3) + 0x400;
    *(int *)(param_1 + 0x3f7) = *(int *)(param_1 + 0x3f7) + -0x400;
    lm_reg_wr_ind(param_1,0x4408,*(undefined4 *)(param_1 + 0x3f3));
    lm_reg_wr_ind(param_1,0x440c,*(undefined4 *)(param_1 + 0x3f7));
    uVar2 = 0;
    lVar5 = 0;
    do {
      LM_MemWrInd(param_1,*(int *)(param_1 + 0x3f3) + -0x400 + uVar2,
                  *(undefined4 *)(lVar5 + *(longlong *)(param_1 + 0x445)));
      uVar2 = uVar2 + 4;
      lVar5 = lVar5 + 4;
    } while (uVar2 < 0x400);
  }
  lm_reg_wr_ind(param_1,0x4400,6);
  if (*(char *)(param_1 + 0x40b) != '\x01') {
    lm_reg_wr_ind(param_1,0x2450,*(undefined4 *)(param_1 + 0x28));
    lm_reg_wr_ind(param_1,0x2454,*(undefined4 *)(param_1 + 0x24));
    lVar5 = LM_IsSawtooth(param_1);
    if ((((char)lVar5 == '\0') && (lVar5 = LM_IsAspen(param_1), (char)lVar5 == '\0')) &&
       (uVar6 = LM_IsLogan(param_1), (char)uVar6 == '\0')) {
      uVar2 = (uint)*(ushort *)(param_1 + 0x407) << 0x10;
    }
    else {
      uVar2 = (uint)*(ushort *)(param_1 + 0x407) << 0x10 | 0x17c8;
    }
    lm_reg_wr_ind(param_1,0x2458,uVar2);
  }
  lVar5 = LM_IsSawtooth(param_1);
  if ((char)lVar5 == '\0') {
    lm_reg_wr_ind(param_1,0x245c,0x6000);
  }
  lm_reg_wr_ind(param_1,0x2448,2);
  lm_reg_wr_ind(param_1,0x2468,2);
  lm_reg_wr_ind(param_1,0x2c18,*(uint *)(param_1 + 0x14) >> 3);
  LM_MemWrInd(param_1,0x108,2);
  *(undefined8 *)(param_1 + 0x310) = 0;
  lm_reg_wr_ind(param_1,0x5904,0);
  lm_reg_wr_ind(param_1,0x5984,0);
  LM_MemWrInd(param_1,0x100,*(undefined4 *)(param_1 + 0x30c));
  LM_MemWrInd(param_1,0x104,*(undefined4 *)(param_1 + 0x308));
  lVar5 = LM_IsSawtooth(param_1);
  if ((char)lVar5 == '\0') {
    LM_MemWrInd(param_1,0x10c,0x4000);
  }
  LM_MemWrInd(param_1,0x108,(uint)*(ushort *)(param_1 + 0x409) << 0x10);
  *(uint *)(param_1 + 0x318) = *(ushort *)(param_1 + 0x409) - 1;
  *(undefined4 *)(param_1 + 0x194) = 0;
  LM_MemWrInd(param_1,0x200,*(undefined4 *)(param_1 + 400));
  LM_MemWrInd(param_1,0x204,*(undefined4 *)(param_1 + 0x18c));
  LM_MemWrInd(param_1,0x20c,0);
  LM_MemWrInd(param_1,0x208,(uint)*(ushort *)(param_1 + 0x405) << 0x10);
  lm_reg_wr_ind(param_1,0x586c,0);
  lm_reg_wr_ind(param_1,0x5874,0);
  lm_reg_wr_ind(param_1,0x587c,0);
  *(undefined4 *)(param_1 + 0x18) = 0;
  lm_reg_wr_ind(param_1,0x438,
                (uint)*(byte *)(param_1 + 0x3a5) + (uint)*(byte *)(param_1 + 0x3a6) +
                (uint)*(byte *)(param_1 + 0x3a7) + (uint)*(byte *)(param_1 + 0x3a9) +
                (uint)*(byte *)(param_1 + 0x3a8) + (uint)*(byte *)(param_1 + 0x3a4) & 0x3ff);
  lm_reg_wr_ind(param_1,0x43c,0x5f2);
  lm_reg_wr_ind(param_1,0x464,0x2620);
  lm_reg_wr_ind(param_1,0x500,8);
  lm_reg_wr_ind(param_1,0x2010,0x181);
  uVar6 = LM_Is575xFamily(param_1);
  if ((((char)uVar6 == '\0') && (uVar2 = *(uint *)(param_1 + 0x3ca) >> 0xc, uVar2 != 5)) &&
     (1 < uVar2 - 8)) {
    lm_reg_wr_ind(param_1,0x2018,0xffffff);
  }
  lm_reg_wr_ind(param_1,0x2014,1);
  lm_reg_wr_ind(param_1,0xc08,3);
  lm_reg_wr_ind(param_1,0x3c08,*(undefined4 *)(param_1 + 0x378));
  lm_reg_wr_ind(param_1,0x3c0c,*(undefined4 *)(param_1 + 0x37c));
  lm_reg_wr_ind(param_1,0x3c10,*(undefined4 *)(param_1 + 0x380));
  lm_reg_wr_ind(param_1,0x3c14,*(undefined4 *)(param_1 + 900));
  lm_reg_wr_ind(param_1,0x3c28,*(undefined4 *)(param_1 + 0x388));
  lm_reg_wr_ind(param_1,0x3c38,*(undefined4 *)(param_1 + 0x38));
  lm_reg_wr_ind(param_1,0x3c3c,*(undefined4 *)(param_1 + 0x34));
  lm_reg_wr_ind(param_1,0x3c30,*(undefined4 *)(param_1 + 0x48));
  lm_reg_wr_ind(param_1,0x3c34,*(undefined4 *)(param_1 + 0x44));
  lm_reg_wr_ind(param_1,0x3c40,0x300);
  lm_reg_wr_ind(param_1,0x3c44,0xb00);
  lm_reg_wr_ind(param_1,0x3c00,*(undefined4 *)(param_1 + 0x400));
  if (*(char *)(param_1 + 0x40b) != '\x01') {
    lm_reg_wr_ind(param_1,0x3000,6);
  }
  lm_reg_wr_ind(param_1,0x2000,2);
  lm_reg_wr_ind(param_1,0x3400,6);
  uVar2 = *(uint *)(param_1 + 0x368);
  uVar7 = uVar2 | 0xe0d800;
  *(uint *)(param_1 + 0x368) = uVar7;
  if ((*(byte *)(param_1 + 0x3fe) & 0x20) == 0) {
    uVar7 = uVar2 | 0xe0dc00;
    *(uint *)(param_1 + 0x368) = uVar7;
  }
  lm_reg_wr_ind(param_1,0x400,uVar7);
  uVar2 = 0;
  uVar7 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if (((uVar7 == 0x57780) || ((*(uint *)(param_1 + 0x3ca) + 0xa887b000 & 0xfffffeff) == 0)) ||
     ((uVar7 == 0x57766 || (uVar7 == 0x5762)))) {
    uVar2 = lm_reg_read_ind(param_1,0x6808);
    uVar6 = LM_IsLogan(param_1);
    if ((char)uVar6 == '\0') {
      uVar2 = uVar2 | 0x10;
    }
  }
  uVar7 = uVar2 | 8;
  if (((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x9000) &&
     ((*(byte *)(param_1 + 0x3fe) & 0x20) != 0)) {
    uVar7 = uVar2 | 0x18;
  }
  lm_reg_wr_ind(param_1,0x6808,uVar7);
  mm_stall(0x28);
  uVar6 = LM_Is5705Family(param_1);
  if ((char)uVar6 == '\0') {
    lm_reg_wr_ind(param_1,0x6400,2);
  }
  uVar4 = 0x3fe;
  lm_reg_wr_ind(param_1,0x4c00,0x3fe);
  lm_reg_wr_ind(param_1,0x4800,0x3fe);
  lm_reg_wr_ind(param_1,0x2800,6);
  lm_reg_wr_ind(param_1,0x3800,2);
  lm_reg_wr_ind(param_1,0x1000,2);
  lm_reg_wr_ind(param_1,0x1c00,6);
  if (*(char *)(param_1 + 0x40b) == '\0') {
    lm_reg_wr_ind(param_1,0x2c00,6);
    lm_reg_wr_ind(param_1,0x2400,0x12);
  }
  lm_reg_wr_ind(param_1,0xc00,2);
  lm_reg_wr_ind(param_1,0x1800,6);
  lm_reg_wr_ind(param_1,0x1400,6);
  uVar9 = 2;
  *(undefined4 *)(param_1 + 0x370) = 2;
  if ((*(byte *)(param_1 + 0x3a2) & 2) != 0) {
    *(undefined4 *)(param_1 + 0x370) = 0x12;
    uVar9 = 0x12;
  }
  uVar2 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if ((uVar2 == 0x5719) || (uVar2 == 0x5720)) {
    *(undefined1 *)(param_1 + 0x464) = 1;
    LM_DoRdmaWorkaround(param_1);
    uVar9 = *(undefined4 *)(param_1 + 0x370);
  }
  lm_reg_wr_ind(param_1,0x45c,uVar9);
  uVar2 = 2;
  *(undefined4 *)(param_1 + 0x36c) = 2;
  if ((*(byte *)(param_1 + 0x3a2) & 1) != 0) {
    *(undefined4 *)(param_1 + 0x36c) = 6;
    uVar2 = 6;
  }
  lVar5 = LM_IsSawtooth(param_1);
  if (((char)lVar5 != '\0') || (uVar6 = LM_IsLogan(param_1), (char)uVar6 != '\0')) {
    uVar2 = uVar2 | 0x1700000;
    *(uint *)(param_1 + 0x36c) = uVar2;
  }
  lm_reg_wr_ind(param_1,0x468,uVar2);
  lm_reg_wr_ind(param_1,0x450,1);
  cVar1 = *(char *)(param_1 + 0x3fc);
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      uVar4 = 0x1000;
      goto LAB_14000ee03;
    }
    if (cVar1 == '\x03') {
      uVar4 = 0x2000;
      goto LAB_14000ee03;
    }
    if (cVar1 != '\x04') {
      if (cVar1 == '\x05') {
        uVar4 = 0x9800;
      }
      goto LAB_14000ee03;
    }
  }
  uVar4 = 0x800;
LAB_14000ee03:
  lm_reg_wr_ind(param_1,0x40c,uVar4);
  uVar2 = 0x414;
  do {
    lm_reg_wr_ind(param_1,uVar2 - 4,
                  (uint)CONCAT11(*(undefined1 *)(param_1 + 0x3a4),*(undefined1 *)(param_1 + 0x3a5)))
    ;
    lm_reg_wr_ind(param_1,uVar2,
                  CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 0x3a6),
                                             *(undefined1 *)(param_1 + 0x3a7)),
                                    *(undefined1 *)(param_1 + 0x3a8)),
                           *(undefined1 *)(param_1 + 0x3a9)));
    uVar2 = uVar2 + 8;
  } while (uVar2 < 0x434);
  LM_SetReceiveMask(param_1,*(uint *)(param_1 + 0x38c));
  if (((*(byte *)(param_1 + 0x3fe) & 2) != 0) &&
     (((uVar2 = *(uint *)(param_1 + 0x3ca) >> 0xc, uVar2 == 5 || (uVar2 - 8 < 2)) ||
      (uVar6 = LM_Is575xFamily(param_1), (char)uVar6 != '\0')))) {
    LM_MemWrInd(param_1,0xc04,0x80000001);
  }
  if (((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x9000) &&
     ((*(byte *)(param_1 + 0x3fe) & 0x20) != 0)) {
    uVar2 = lm_reg_read_ind(param_1,0x5b0);
    lm_reg_wr_ind(param_1,0x5b0,uVar2 | 0x400);
  }
  LM_SetupPhy(param_1);
  if (*(char *)(param_1 + 0x3fb) != '\0') {
    LM_QueueRxPackets(param_1);
  }
  if (*(char *)(param_1 + 0x3f2) != '\0') {
    LM_EnableInterrupt(param_1);
  }
  if (*(char *)(param_1 + 0x458) != '\0') {
    uVar2 = lm_reg_read_ind(param_1,0x7d28);
    *(uint *)(param_1 + 0x459) = uVar2;
    lm_reg_wr_ind(param_1,0x7d28,uVar2 | 0xff00);
  }
  return 0;
}



===== LM_ResetChip @ 14000ef84 =====

undefined8 LM_ResetChip(longlong param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  ushort uVar7;
  undefined4 uVar8;
  uint local_res8 [2];
  short local_res18 [4];
  undefined2 local_res20 [4];
  
  LM_EnableMemoryArbitor(param_1);
  uVar1 = storport_pci_cfg_read_dword(param_1,0xc);
  LM_NvramAcquireFlashLock(param_1);
  uVar4 = *(uint *)(param_1 + 0x3ca);
  if (uVar4 == 0xa000) {
    lm_reg_read_ind(param_1,0x703c);
    LM_MemWrInd(param_1,0xb50,0);
    mm_stall(0x14);
    uVar4 = *(uint *)(param_1 + 0x3ca);
  }
  if ((uVar4 & 0xfffff000) != 0xc000) {
    LM_MemWrInd(param_1,0xb50,0x4b657654);
  }
  if ((*(char *)(param_1 + 0x443) != '\0') &&
     (iVar2 = lm_reg_read_ind(param_1,0x7e2c), iVar2 == 0x60)) {
    lm_reg_wr_ind(param_1,0x7e2c,0x20);
  }
  uVar4 = *(uint *)(param_1 + 0x3ca);
  if ((uVar4 & 0xfffff000) != 0xc000) {
    LM_MemWrInd(param_1,0xc04,param_2);
    uVar4 = *(uint *)(param_1 + 0x3ca);
  }
  uVar8 = 0x4000001;
  uVar3 = local_res8[0];
  if (*(char *)(param_1 + 0x443) != '\0') {
    if (((uVar4 >> 0xc == 0x5784) || (uVar4 >> 0xc == 0x5761)) &&
       (uVar3 = storport_pci_cfg_read_dword(param_1,0xdc),
       (uVar3 >> 8 & 1) != 0 && ((byte)uVar3 & 3) == 3)) {
      storport_pci_cfg_write_dword(param_1,0xdc,uVar3 & 0xfffffeff);
      mm_stall(10);
    }
    uVar4 = lm_reg_read_ind(param_1,0x6804);
    lm_reg_wr_ind(param_1,0x6804,uVar4 | 0x20000000);
    uVar8 = 0x24000001;
  }
  if ((((*(byte *)(param_1 + 0x3fe) & 8) != 0) &&
      (iVar2 = lm_reg_read_ind(param_1,0x14000), iVar2 == 0x41504521)) &&
     (uVar4 = lm_reg_read_ind(param_1,0x1400c), (uVar4 & 0xf0000100) == 0x100)) {
    LM_ApeGetMutexRegisters(param_1,local_res20,(undefined2 *)local_res8,local_res18);
    uVar7 = 0;
    do {
      lm_reg_wr_ind(param_1,(ushort)local_res8[0] + 0x10000 + (uint)uVar7 * 4,0x1000);
      uVar7 = uVar7 + 1;
    } while (uVar7 < 8);
    LM_ApeAcquireLock(param_1,1);
  }
  if ((*(ushort *)(param_1 + 0x3fe) & 0x100) != 0) {
    LM_ApeAcquireLock(param_1,0);
  }
  lm_reg_wr_ind(param_1,0x6804,uVar8);
  mm_stall(0x28);
  uVar7 = *(ushort *)(param_1 + 0x3fe);
  if ((uVar7 & 0x100) != 0) {
    LM_ApeReleaseLock(param_1,0);
    uVar7 = *(ushort *)(param_1 + 0x3fe);
  }
  if ((uVar7 & 8) != 0) {
    LM_ApeReleaseLock(param_1,1);
  }
  storport_pci_cfg_write_dword(param_1,4,*(undefined4 *)(param_1 + 0x3c2));
  storport_pci_cfg_write_dword(param_1,0x68,*(undefined4 *)(param_1 + 0x10));
  if ((*(byte *)(param_1 + 0x3fe) & 0x10) != 0) {
    storport_pci_cfg_write_dword(param_1,0x74,0x400000);
  }
  LM_EnableMemoryArbitor(param_1);
  storport_pci_cfg_write_dword(param_1,0xc,uVar1);
  if (*(char *)(param_1 + 0x3c1) == '\x01') {
    storport_pci_cfg_write_dword(param_1,0x40,*(undefined4 *)(param_1 + 0x3c6));
  }
  uVar4 = 0;
  if ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0xc000) {
    do {
      uVar5 = lm_reg_read_ind(param_1,0x5100);
      if ((uVar5 >> 0x1a & 1) != 0) break;
      mm_stall(100);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 1000);
  }
  else {
    do {
      storport_pci_cfg_write_dword(param_1,0x7c,0xb50);
      iVar2 = storport_pci_cfg_read_dword(param_1,0x84);
      if (iVar2 == -0x4b657655) break;
      mm_stall(10);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 80000);
    LM_MemWrInd(param_1,0xc04,param_2);
  }
  mm_stall(10000);
  uVar6 = LM_IsLogan(param_1);
  if ((char)uVar6 != '\0') {
    uVar4 = 0;
    do {
      storport_pci_cfg_write_dword(param_1,0x7c,0xc00);
      iVar2 = storport_pci_cfg_read_dword(param_1,0x84);
      if (iVar2 == -0x4b657655) break;
      mm_stall(10);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 80000);
    uVar4 = lm_reg_read_ind(param_1,0x3624);
    lm_reg_wr_ind(param_1,0x3624,uVar4 & 0xffe0ffff);
    uVar4 = lm_reg_read_ind(param_1,0x3628);
    lm_reg_wr_ind(param_1,0x3628,uVar4 | 0x2000);
  }
  if ((*(int *)(param_1 + 0x3ca) == 0x57785000) && (*(char *)(param_1 + 0x463) == '\x02')) {
    uVar4 = lm_reg_read_ind(param_1,0x6800);
    lm_reg_wr_ind(param_1,0x6800,uVar4 | 0x400000);
    uVar5 = lm_reg_read_ind(param_1,0x7c14);
    lm_reg_wr_ind(param_1,0x7c14,uVar5 | 0x80000000);
    lm_reg_wr_ind(param_1,0x6800,uVar4 & 0xffbfffff);
    uVar4 = lm_reg_read_ind(param_1,0x6c);
    lm_reg_wr_ind(param_1,0x6c,uVar4 & 0xfffffc7f);
  }
  uVar6 = LM_Is575xFamily(param_1);
  if ((char)uVar6 != '\0') {
    uVar4 = storport_pci_cfg_read_dword(param_1,0xd8);
    storport_pci_cfg_write_dword(param_1,0xd8,uVar4 & 0xfffff7ef);
  }
  if (*(char *)(param_1 + 0x443) != '\0') {
    uVar4 = *(uint *)(param_1 + 0x3ca);
    if ((uVar4 >> 0xc == 0x5784) || (uVar4 >> 0xc == 0x5761)) {
      storport_pci_cfg_write_dword(param_1,0xdc,uVar3);
      mm_stall(10);
      uVar4 = *(uint *)(param_1 + 0x3ca);
    }
    if (uVar4 != 0x4000) {
      uVar4 = lm_reg_read_ind(param_1,0x7c00);
      lm_reg_wr_ind(param_1,0x7c00,uVar4 | 0x2000000);
    }
  }
  if (*(int *)(param_1 + 0x3ca) == 0x57780000) {
    lm_reg_wr_ind(param_1,0x7d28,0x182fffa);
  }
  if (((*(short *)(param_1 + 0x3ba) + 0xe970U & 0xfff9) == 0) &&
     (*(short *)(param_1 + 0x3ba) != 0x1696)) {
    lm_reg_wr_ind(param_1,0x7d54,0x7080);
  }
  return 0;
}



===== LM_ResetPhy @ 14000f500 =====

undefined8 LM_ResetPhy(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  undefined8 uVar3;
  uint local_res8;
  
  if (*(int *)(param_1 + 0x3ca) == 0x5784100) {
    uVar2 = lm_reg_read_ind(param_1,0x3600);
    local_res8 = uVar2 & 0xfffeffff;
    lm_reg_wr_ind(param_1,0x3600,local_res8);
  }
  LM_WritePhy(param_1,0,0x8000);
  if ((*(uint *)(param_1 + 0x3d7) & 0xfffffff0) == 0xbc050c70) {
    mm_stall(500);
  }
  mm_stall(0x3c);
  if (*(int *)(param_1 + 0x3ca) == 0x5784100) {
    LM_WritePhy(param_1,0x17,0xf08);
    LM_WritePhy(param_1,0x15,0x201);
    lm_reg_wr_ind(param_1,0x3600,local_res8 | 0x10000);
  }
  LM_PhyConfigWorkaround(param_1);
  uVar3 = LM_Is5705Family(param_1);
  if (((char)uVar3 == '\0') || ((*(byte *)(param_1 + 0x3fe) & 0x40) == 0)) {
    bVar1 = LM_RestartAutoNegCheck(param_1);
    if (bVar1 != 1) {
      return 1;
    }
  }
  else {
    LM_WritePhy(param_1,0x18,0x4007);
    uVar2 = LM_ReadPhy(param_1,0x18);
    LM_WritePhy(param_1,0x18,(ushort)uVar2 | 0x400);
  }
  LM_WritePhy(param_1,0,0x1200);
  return 1;
}



===== LM_RestartAutoNegCheck @ 14000f638 =====

byte LM_RestartAutoNegCheck(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  byte bVar3;
  ushort uVar4;
  
  uVar1 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  bVar3 = 0;
  if ((((uVar1 == 5) || (uVar1 - 8 < 2)) || (lVar2 = LM_IsSawtooth(param_1), (char)lVar2 != '\0'))
     && ((*(byte *)(param_1 + 0x3fe) & 0x20) != 0)) {
    uVar1 = LM_ReadPhy(param_1,4);
    if (((byte)uVar1 & 0x60) == 0x60) {
      return 0;
    }
    LM_WritePhy(param_1,4,0x1e0);
    return 1;
  }
  if (*(int *)(param_1 + 0x3db) == 0) {
    uVar1 = LM_ReadPhy(param_1,0);
    bVar3 = ~((byte)(uVar1 >> 8) >> 4) & 1;
    uVar1 = LM_ReadPhy(param_1,4);
    if (((ushort)uVar1 & 0x1e0) != 0x1e0) {
      LM_WritePhy(param_1,4,0x5e1);
      bVar3 = 1;
    }
    if (*(char *)(param_1 + 0x40c) == '\0') {
      uVar1 = LM_ReadPhy(param_1,9);
      if ((short)uVar1 == 0) {
        return bVar3;
      }
      uVar4 = 0;
    }
    else {
      uVar1 = LM_ReadPhy(param_1,9);
      if (((ushort)uVar1 & 0x300) == 0x300) {
        return bVar3;
      }
      uVar4 = ~(*(ushort *)(param_1 + 0x3fe) >> 2) & 0x100 | 0x200;
    }
    LM_WritePhy(param_1,9,uVar4);
    bVar3 = 1;
  }
  return bVar3;
}



===== LM_SendPacket @ 14000f778 =====

undefined8 LM_SendPacket(longlong param_1,longlong param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar2 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if ((uVar2 == 0x5719) || (uVar2 == 0x5720)) {
    LM_DoRdmaWorkaround(param_1);
  }
  uVar3 = *(uint *)(param_1 + 0x1f8);
  uVar2 = *(uint *)(param_1 + 0x1fc);
  if (param_2 != 0) {
    if (uVar3 == uVar2) goto LAB_14000f82f;
    uVar4 = uVar2;
    if (uVar2 == 0) {
      uVar4 = *(uint *)(param_1 + 0x200);
    }
    uVar4 = uVar4 - 1;
    if (uVar4 != uVar3) {
      *(longlong *)(param_1 + 0x208 + (ulonglong)uVar4 * 8) = param_2;
      *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0x204) + 1;
      *(uint *)(param_1 + 0x1fc) = uVar4;
      uVar3 = *(uint *)(param_1 + 0x1f8);
      uVar2 = uVar4;
    }
  }
  if (uVar3 == uVar2) {
    return 0;
  }
  if (uVar3 == 0) {
    uVar3 = *(uint *)(param_1 + 0x200);
  }
  *(uint *)(param_1 + 0x1f8) = uVar3 - 1;
  *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0x204) + -1;
  param_2 = *(longlong *)(param_1 + 0x208 + (ulonglong)(uVar3 - 1) * 8);
LAB_14000f82f:
  while( true ) {
    if (param_2 == 0) {
      return 0;
    }
    if (*(uint *)(param_1 + 0x318) < *(uint *)(param_2 + 10)) break;
    uVar1 = *(ushort *)(param_1 + 0x310);
    *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) - *(uint *)(param_2 + 10);
    if (*(char *)(param_1 + 0x3f1) == '\0') {
      puVar6 = (undefined4 *)((ulonglong)uVar1 * 0x10 + *(longlong *)(param_1 + 0x300));
    }
    else {
      puVar6 = &NicSendBd;
    }
    puVar6[1] = *(undefined4 *)(*(longlong *)(param_2 + 0x36) + 0xc);
    *puVar6 = *(undefined4 *)(*(longlong *)(param_2 + 0x36) + 0x10);
    uVar2 = *(int *)(*(longlong *)(param_2 + 0x36) + 8) << 0x10;
    if ((*(byte *)(param_2 + 6) & 1) != 0) {
      uVar2 = uVar2 | 0x40;
      *(undefined2 *)(puVar6 + 3) = *(undefined2 *)(param_2 + 8);
    }
    puVar6[2] = uVar2 | 4;
    if (*(char *)(param_1 + 0x3f1) != '\0') {
      iVar5 = (uVar1 + 0x400) * 0x10;
      LM_MemWrInd(param_1,iVar5,*puVar6);
      LM_MemWrInd(param_1,iVar5 + 4,puVar6[1]);
      LM_MemWrInd(param_1,iVar5 + 8,puVar6[2]);
      LM_MemWrInd(param_1,iVar5 + 0xc,puVar6[3]);
    }
    uVar2 = (uint)(ushort)(*(short *)(param_1 + 0x409) - 1U & uVar1 + 1);
    *(uint *)(param_1 + 0x310) = uVar2;
    lm_reg_wr_ind(param_1,(-(uint)(*(char *)(param_1 + 0x3f1) != '\0') & 0x80) + 0x5904,uVar2);
    iVar5 = *(int *)(param_1 + 0x254);
    if (iVar5 == 0) {
      iVar5 = *(int *)(param_1 + 600);
    }
    uVar2 = iVar5 - 1;
    if (uVar2 != *(uint *)(param_1 + 0x250)) {
      *(longlong *)(param_1 + 0x260 + (ulonglong)uVar2 * 8) = param_2;
      *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;
      *(uint *)(param_1 + 0x254) = uVar2;
    }
    uVar2 = *(uint *)(param_1 + 0x1fc);
    if (uVar2 == *(uint *)(param_1 + 0x1f8)) {
      return 0;
    }
    *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0x204) + -1;
    *(uint *)(param_1 + 0x1fc) = (uVar2 + 1) % *(uint *)(param_1 + 0x200);
    param_2 = *(longlong *)(param_1 + 0x208 + (ulonglong)uVar2 * 8);
  }
  uVar2 = (*(uint *)(param_1 + 0x1f8) + 1) % *(uint *)(param_1 + 0x200);
  if (uVar2 != *(uint *)(param_1 + 0x1fc)) {
    *(longlong *)(param_1 + 0x208 + (ulonglong)*(uint *)(param_1 + 0x1f8) * 8) = param_2;
    *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0x204) + 1;
    *(uint *)(param_1 + 0x1f8) = uVar2;
  }
  *(int *)(param_1 + 0x358) = *(int *)(param_1 + 0x358) + 1;
  return 0;
}



===== LM_ServiceInterrupts @ 14000f9f4 =====

undefined8 LM_ServiceInterrupts(longlong param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  
  uVar3 = lm_reg_read_ind(param_1,0x404);
  if ((*(byte *)(param_1 + 0x3fe) & 0x20) == 0) {
    uVar5 = LM_Is5705Family(param_1);
    uVar6 = (-(uint)((char)uVar5 != '\0') & 0xff800000) + 0x801000;
  }
  else {
    uVar6 = 0x1000;
  }
  if ((uVar3 & uVar6) != 0) {
    LM_SetupPhy(param_1);
  }
  LM_ServiceRxInterrupt(param_1);
  uVar3 = *(uint *)(param_1 + 0x314);
  if (uVar3 != *(ushort *)(*(longlong *)(param_1 + 0x2c) + 0x12)) {
    do {
      iVar4 = *(int *)(param_1 + 0x250);
      if (iVar4 == *(int *)(param_1 + 0x254)) break;
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 600);
      }
      *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + -1;
      *(uint *)(param_1 + 0x250) = iVar4 - 1U;
      puVar2 = *(undefined4 **)(param_1 + 0x260 + (ulonglong)(iVar4 - 1U) * 8);
      if (puVar2 == (undefined4 *)0x0) break;
      *puVar2 = 0;
      iVar4 = *(int *)(param_1 + 0x2ac);
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x2b0);
      }
      uVar6 = iVar4 - 1;
      if (uVar6 != *(uint *)(param_1 + 0x2a8)) {
        *(undefined4 **)(param_1 + 0x2b8 + (ulonglong)uVar6 * 8) = puVar2;
        *(int *)(param_1 + 0x2b4) = *(int *)(param_1 + 0x2b4) + 1;
        *(uint *)(param_1 + 0x2ac) = uVar6;
      }
      iVar4 = *(int *)((longlong)puVar2 + 10);
      *(int *)(param_1 + 0x318) = *(int *)(param_1 + 0x318) + iVar4;
      uVar3 = *(ushort *)(param_1 + 0x409) - 1 & iVar4 + uVar3;
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x2c) + 0x12);
      *(int *)(param_1 + 0x34c) = *(int *)(param_1 + 0x34c) + 1;
    } while (uVar3 != uVar1);
  }
  *(uint *)(param_1 + 0x314) = uVar3;
  return 0;
}



===== LM_ServiceRxInterrupt @ 14000fb18 =====

void LM_ServiceRxInterrupt(longlong param_1)

{
  int iVar2;
  uint uVar1;
  longlong lVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar4 = *(uint *)(param_1 + 0x194);
  if (uVar4 != *(ushort *)(*(longlong *)(param_1 + 0x2c) + 0x10)) {
    do {
      lVar3 = (ulonglong)uVar4 * 0x20 + *(longlong *)(param_1 + 0x184);
      puVar5 = (undefined4 *)((ulonglong)*(uint *)(lVar3 + 0x1c) + *(longlong *)(param_1 + 8));
      if (*(short *)(lVar3 + 0x16) == 0) {
        *puVar5 = 0;
        *(short *)(puVar5 + 1) = *(short *)(lVar3 + 8) + -4;
        *(int *)(param_1 + 0x31c) = *(int *)(param_1 + 0x31c) + 1;
        *(int *)(param_1 + 800) = *(int *)(param_1 + 800) + (uint)*(ushort *)(puVar5 + 1);
        *(undefined2 *)((longlong)puVar5 + 6) = *(undefined2 *)(lVar3 + 0xc);
        *(undefined2 *)(puVar5 + 2) = *(undefined2 *)(lVar3 + 0x14);
        if (((*(byte *)(param_1 + 0x3fe) & 4) != 0) &&
           (((*(ushort *)(lVar3 + 0xc) & 0x40) == 0 ||
            (*(short *)(lVar3 + 0x14) != *(short *)(param_1 + 0x456))))) goto LAB_14000fbe5;
        iVar2 = *(int *)(param_1 + 0xec);
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_1 + 0xf0);
        }
        uVar1 = iVar2 - 1;
        if (uVar1 != *(uint *)(param_1 + 0xe8)) {
          *(undefined4 **)(param_1 + 0xf8 + (ulonglong)uVar1 * 8) = puVar5;
          *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
          *(uint *)(param_1 + 0xec) = uVar1;
        }
      }
      else {
LAB_14000fbe5:
        iVar2 = *(int *)(param_1 + 0x54);
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_1 + 0x58);
        }
        uVar1 = iVar2 - 1;
        if (uVar1 != *(uint *)(param_1 + 0x50)) {
          *(undefined4 **)(param_1 + 0x60 + (ulonglong)uVar1 * 8) = puVar5;
          *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
          *(uint *)(param_1 + 0x54) = uVar1;
        }
        LM_QueueRxPackets(param_1);
      }
      uVar4 = *(ushort *)(param_1 + 0x405) - 1 & uVar4 + 1;
    } while (uVar4 != *(ushort *)(*(longlong *)(param_1 + 0x2c) + 0x10));
  }
  *(uint *)(param_1 + 0x194) = uVar4;
  lm_reg_wr_ind(param_1,0x5884,uVar4);
  return;
}



===== LM_SetFlowControl @ 14000fc50 =====

undefined8 LM_SetFlowControl(longlong param_1,ushort param_2,ushort param_3)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  ushort uVar5;
  
  uVar1 = *(ushort *)(param_1 + 0x3a0);
  uVar5 = 0;
  if ((short)uVar1 < 0) {
    if ((param_2 & 0x400) == 0) {
      if (((param_2 & 0x800) != 0) && ((param_3 & 0xc00) == 0xc00)) {
        uVar5 = 2;
      }
    }
    else {
      if ((param_2 & 0x800) == 0) {
        if ((param_3 & 0x400) == 0) goto LAB_14000fce7;
      }
      else if ((param_3 & 0x400) == 0) {
        if ((param_3 & 0x800) != 0) {
          uVar5 = 1;
        }
        goto LAB_14000fce7;
      }
      uVar5 = 3;
    }
  }
  else {
    uVar5 = uVar1;
  }
LAB_14000fce7:
  uVar2 = *(uint *)(param_1 + 0x36c) & 0xfffffffb;
  *(uint *)(param_1 + 0x36c) = uVar2;
  if (((uVar5 & 1) != 0) && ((uVar1 == 0x8000 || ((uVar1 & 1) != 0)))) {
    *(ushort *)(param_1 + 0x3a2) = *(ushort *)(param_1 + 0x3a2) | 1;
    uVar2 = uVar2 | 4;
    *(uint *)(param_1 + 0x36c) = uVar2;
  }
  lVar3 = LM_IsSawtooth(param_1);
  if (((char)lVar3 != '\0') || (uVar4 = LM_IsLogan(param_1), (char)uVar4 != '\0')) {
    uVar2 = uVar2 | 0x1700000;
    *(uint *)(param_1 + 0x36c) = uVar2;
  }
  lm_reg_wr_ind(param_1,0x468,uVar2);
  uVar2 = *(uint *)(param_1 + 0x370) & 0xffffffef;
  *(uint *)(param_1 + 0x370) = uVar2;
  if (((uVar5 & 2) != 0) &&
     ((*(ushort *)(param_1 + 0x3a0) == 0x8000 || ((*(ushort *)(param_1 + 0x3a0) & 2) != 0)))) {
    *(ushort *)(param_1 + 0x3a2) = *(ushort *)(param_1 + 0x3a2) | 2;
    uVar2 = uVar2 | 0x10;
    *(uint *)(param_1 + 0x370) = uVar2;
  }
  lm_reg_wr_ind(param_1,0x45c,uVar2);
  return 0;
}



===== LM_SetReceiveMask @ 14000fdbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 LM_SetReceiveMask(longlong param_1,uint param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined1 auStack_48 [32];
  uint local_28 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar5 = 0;
  uVar6 = param_2 & 0xfffffffe;
  if ((param_2 & 1) == 0) {
    uVar6 = param_2;
  }
  uVar3 = uVar6 & 0xfffffffd;
  if ((uVar6 & 2) == 0) {
    uVar3 = uVar6;
  }
  uVar6 = uVar3 & 0xfffffffb;
  if ((uVar3 & 4) == 0) {
    uVar6 = uVar3;
  }
  uVar8 = *(uint *)(param_1 + 0x36c) & 0xfffffeff;
  uVar3 = uVar6 & 0xfffeffff;
  if ((uVar6 & 0x10000) == 0) {
    uVar3 = uVar6;
  }
  uVar4 = uVar8 | 0x100;
  if ((uVar6 & 0x10000) == 0) {
    uVar4 = uVar8;
  }
  uVar6 = uVar4 & 0xffffff9f | 0x60;
  if ((uVar3 & 8) == 0) {
    uVar6 = uVar4 & 0xffffff9f;
  }
  uVar8 = uVar3 & 0xfffffff7;
  if ((uVar3 & 8) == 0) {
    uVar8 = uVar3;
  }
  if (uVar8 != 0) {
    return 1;
  }
  lVar1 = LM_IsSawtooth(param_1);
  if (((char)lVar1 != '\0') || (uVar2 = LM_IsLogan(param_1), (char)uVar2 != '\0')) {
    uVar6 = uVar6 | 0x1700000;
  }
  *(uint *)(param_1 + 0x36c) = uVar6;
  lm_reg_wr_ind(param_1,0x468,uVar6);
  *(uint *)(param_1 + 0x38c) = param_2;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  if (0 < (int)*(uint *)(param_1 + 0x40d)) {
    lVar1 = param_1 + 0x411;
    uVar11 = (ulonglong)*(uint *)(param_1 + 0x40d);
    do {
      uVar6 = 0xffffffff;
      lVar9 = 0;
      do {
        lVar10 = 8;
        uVar6 = uVar6 ^ *(byte *)(lVar1 + lVar9);
        do {
          uVar8 = uVar6 >> 1;
          uVar3 = uVar6 & 1;
          uVar6 = uVar8 ^ 0xedb88320;
          if (uVar3 == 0) {
            uVar6 = uVar8;
          }
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
        lVar9 = lVar9 + 1;
      } while (lVar9 < 6);
      lVar1 = lVar1 + 6;
      local_28[(uVar6 & 0xff) >> 5 & 3] =
           local_28[(uVar6 & 0xff) >> 5 & 3] | 1 << ((byte)uVar6 & 0x1f);
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  iVar7 = 0x470;
  do {
    lm_reg_wr_ind(param_1,iVar7,local_28[lVar5]);
    iVar7 = iVar7 + 4;
    lVar5 = lVar5 + 1;
  } while (lVar5 < 4);
  return 0;
}



===== LM_SetupExternalPhy @ 14000ff60 =====

undefined8 LM_SetupExternalPhy(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  char cVar5;
  ushort uVar6;
  uint uVar7;
  
  storport_pci_cfg_write_dword(param_1,0x7c,0xd60);
  uVar1 = storport_pci_cfg_read_dword(param_1,0x84);
  uVar2 = lm_reg_read_ind(param_1,0x5a0);
  uVar3 = uVar2 | 1;
  if ((uVar1 & 1) != 0) {
    uVar3 = uVar2 & 0xfffffffe;
  }
  lm_reg_wr_ind(param_1,0x5a0,uVar3);
  uVar3 = *(uint *)(param_1 + 0x3d7) & 0xfffffff0;
  if (uVar3 != 0x5c0d8a60) {
    if (uVar3 == 0xbc050c70) {
      uVar3 = LM_ReadPhy(param_1,0x1f);
      LM_WritePhy(param_1,0x1f,(ushort)uVar3 | 0x80);
      LM_WritePhy(param_1,0x1a,0x3001);
      uVar3 = LM_ReadPhy(param_1,0x10);
      LM_WritePhy(param_1,0x10,(ushort)uVar3 | 0x4000);
      uVar3 = LM_ReadPhy(param_1,0x1b);
      LM_WritePhy(param_1,0x1b,(ushort)uVar3 | 0x20);
      uVar3 = LM_ReadPhy(param_1,0x1f);
      LM_WritePhy(param_1,0x1f,(ushort)uVar3 & 0xff7f);
      lm_reg_wr_ind(param_1,0x5a4,0x33ff66c0);
      uVar7 = 0x18;
      uVar3 = LM_ReadPhy(param_1,0x18);
      uVar6 = (ushort)uVar3 & 0xfbff | 0x30;
      goto LAB_14001036b;
    }
    if (uVar3 != 0xbc050ca0) {
      return 0;
    }
  }
  LM_WritePhy(param_1,0x18,0x7007);
  uVar3 = LM_ReadPhy(param_1,0x18);
  cVar5 = (char)(uVar1 & 1);
  uVar6 = (ushort)uVar3 | 0x81c7;
  if (cVar5 != '\0') {
    uVar6 = (ushort)uVar3 & 0xfe3f | 0x8007;
  }
  uVar3 = LM_ReadPhy(param_1,0);
  uVar4 = uVar6 & 0xfdff;
  if ((uVar3 & 0x1000) == 0) {
    uVar4 = uVar6 | 0x200;
  }
  LM_WritePhy(param_1,0x18,uVar4);
  LM_WritePhy(param_1,0x1c,0xc00);
  uVar3 = LM_ReadPhy(param_1,0x1c);
  uVar6 = (ushort)uVar3 | 0x8e00;
  if (cVar5 != '\0') {
    uVar6 = (ushort)uVar3 & 0xfdff | 0x8c00;
  }
  LM_WritePhy(param_1,0x1c,uVar6);
  if (cVar5 == '\0') {
    uVar2 = lm_reg_read_ind(param_1,0x5a4);
    uVar3 = uVar2 & 0xfffffffe;
    if ((uVar1 & 4) == 0) {
      uVar3 = uVar2 | 1;
    }
    lm_reg_wr_ind(param_1,0x5a4,uVar3);
    LM_WritePhy(param_1,0x18,0x7007);
    uVar3 = LM_ReadPhy(param_1,0x18);
    uVar6 = (ushort)uVar3 | 0x20;
    if ((uVar1 & 4) == 0) {
      uVar6 = (ushort)uVar3 & 0xffdf;
    }
    LM_WritePhy(param_1,0x18,uVar6 | 0x8000);
  }
  uVar2 = uVar1 & 0xc;
  uVar3 = lm_reg_read_ind(param_1,0x5a0);
  if (uVar2 == 8) {
    lm_reg_wr_ind(param_1,0x5a0,uVar3 | 0x2000000);
    uVar3 = lm_reg_read_ind(param_1,0x5a8);
    uVar3 = uVar3 | 0xf00;
  }
  else {
    lm_reg_wr_ind(param_1,0x5a0,uVar3 & 0xfdffffff);
    uVar3 = lm_reg_read_ind(param_1,0x5a8);
    uVar3 = uVar3 & 0xfffff0ff;
  }
  lm_reg_wr_ind(param_1,0x5a8,uVar3);
  uVar7 = 0x17;
  LM_WritePhy(param_1,0x17,0xff0);
  uVar3 = LM_ReadPhy(param_1,0x15);
  uVar6 = (ushort)uVar3 | 0x8000;
  if (uVar2 != 8) {
    uVar6 = (ushort)uVar3 & 0x7fff;
  }
  LM_WritePhy(param_1,0x15,uVar6);
  LM_WritePhy(param_1,0x17,0);
  uVar3 = lm_reg_read_ind(param_1,0x5a0);
  if (((byte)uVar1 & 0x14) == 0x10) {
    lm_reg_wr_ind(param_1,0x5a0,uVar3 | 0x4000000);
    uVar3 = lm_reg_read_ind(param_1,0x5a8);
    uVar3 = uVar3 | 7;
  }
  else {
    lm_reg_wr_ind(param_1,0x5a0,uVar3 & 0xfbffffff);
    uVar3 = lm_reg_read_ind(param_1,0x5a8);
    uVar3 = uVar3 & 0xfffffffa;
  }
  lm_reg_wr_ind(param_1,0x5a8,uVar3);
  LM_WritePhy(param_1,0x17,0xff0);
  uVar3 = LM_ReadPhy(param_1,0x15);
  uVar6 = (ushort)uVar3 | 0x4000;
  if (uVar2 != 8) {
    uVar6 = (ushort)uVar3 & 0xbfff;
  }
  LM_WritePhy(param_1,0x15,uVar6);
  uVar6 = 0;
LAB_14001036b:
  LM_WritePhy(param_1,uVar7,uVar6);
  return 0;
}



===== LM_SetupFiberPhy @ 140010398 =====

undefined8 LM_SetupFiberPhy(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ushort uVar6;
  int iVar7;
  ushort uVar8;
  int iVar9;
  ushort uVar10;
  
  iVar7 = 0;
  uVar2 = *(uint *)(param_1 + 0x3ca) >> 0xc;
  if (((uVar2 == 5) || (uVar2 - 8 < 2)) || (lVar4 = LM_IsSawtooth(param_1), (char)lVar4 != '\0')) {
    bVar1 = LM_RestartAutoNegCheck(param_1);
    if (bVar1 == 1) {
      LM_WritePhy(param_1,0,0x1200);
    }
    *(undefined4 *)(param_1 + 0x3ed) = 5;
    uVar5 = LM_PhyCableAttached(param_1);
    if ((char)uVar5 == '\x01') {
      iVar7 = 0;
      do {
        iVar9 = 0;
        do {
          uVar5 = LM_IsLinkStatusUp(param_1);
          if ((char)uVar5 != '\0') break;
          mm_stall(1000);
          iVar9 = iVar9 + 1;
        } while (iVar9 < 500);
        if (iVar9 == 500) {
          LM_WritePhy(param_1,0x17,0xf01);
          LM_ReadPhy(param_1,0x15);
          uVar2 = LM_ReadPhy(param_1,0x15);
          if ((uVar2 & 0x20) == 0) {
            LM_WritePhy(param_1,0,0x140);
            LM_WritePhy(param_1,0x17,0xf02);
            uVar2 = LM_ReadPhy(param_1,0x15);
            LM_WritePhy(param_1,0x15,(ushort)uVar2 & 0xffdf);
            goto LAB_140010529;
          }
          iVar9 = *(int *)(param_1 + 0x3ed);
        }
        else {
LAB_140010529:
          iVar9 = 4;
          *(undefined4 *)(param_1 + 0x3ed) = 4;
        }
      } while ((iVar9 != 4) && (iVar7 = iVar7 + 1, iVar7 < 0x10));
    }
    if (*(int *)(param_1 + 0x3ed) == 4) {
      uVar2 = LM_ReadPhy(param_1,4);
      uVar8 = ((ushort)uVar2 & 0x80) << 3;
      uVar3 = LM_ReadPhy(param_1,5);
      uVar6 = ((ushort)uVar3 & 0x80) << 3;
      uVar10 = uVar6 | 0x800;
      if ((uVar3 & 0x100) == 0) {
        uVar10 = uVar6;
      }
      uVar6 = uVar8 | 0x800;
      if ((uVar2 & 0x100) == 0) {
        uVar6 = uVar8;
      }
      LM_SetFlowControl(param_1,uVar6,uVar10);
    }
    lm_reg_wr_ind(param_1,0x408,0x801000);
    lm_reg_wr_ind(param_1,0x404,0x1000);
  }
  else {
    *(undefined4 *)(param_1 + 0x3ed) = 5;
    uVar5 = lm_reg_read_ind(param_1,0x404);
    if ((uVar5 & 3) != 0) {
      do {
        storport_pci_cfg_write_dword(param_1,0x7c,0xc1c);
        uVar2 = storport_pci_cfg_read_dword(param_1,0x84);
        if ((uVar2 & 0xffff0001) == 0x736b0001) {
          *(undefined4 *)(param_1 + 0x3ed) = 4;
          return 0;
        }
        mm_stall(1000);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 8000);
    }
  }
  return 0;
}



===== LM_SetupPhy @ 140010600 =====

undefined8 LM_SetupPhy(longlong param_1)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  char cVar10;
  ushort uVar11;
  int iVar12;
  longlong lVar13;
  longlong lVar14;
  int iVar15;
  byte bVar16;
  uint uVar17;
  uint uVar18;
  undefined4 uVar19;
  ushort uVar20;
  bool bVar21;
  ushort local_res8;
  
  iVar15 = 1;
  bVar16 = 0;
  cVar10 = (char)*(ushort *)(param_1 + 0x3fe);
  if ((*(ushort *)(param_1 + 0x3fe) & 0x20) != 0) {
    uVar8 = LM_SetupFiberPhy(param_1);
    return uVar8;
  }
  if ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x5785000) {
    LM_SetupExternalPhy(param_1);
    cVar10 = (char)*(undefined2 *)(param_1 + 0x3fe);
  }
  if (cVar10 < '\0') {
    LM_SetupPhyEee(param_1);
  }
  if (*(char *)(param_1 + 0x3fc) == '\x04') {
    LM_WritePhy(param_1,0x1c,42000);
  }
  iVar4 = storport_pci_cfg_read_dword(param_1,0x2c);
  if (iVar4 == 0x20031028) {
    uVar5 = LM_GetGPIO2(param_1);
    bVar16 = *(byte *)(param_1 + 0x40c) ^ (byte)uVar5;
    *(byte *)(param_1 + 0x40c) = (byte)uVar5;
  }
  iVar4 = *(int *)(param_1 + 0x3db);
  uVar11 = 0;
  uVar20 = 0x2000;
  if (iVar4 == 3) {
    uVar3 = 0;
    local_res8 = 0x21;
LAB_140010745:
    if (iVar4 != 0) goto LAB_140010749;
    bVar2 = LM_RestartAutoNegCheck(param_1);
    if ((((*(ushort *)(param_1 + 0x3fe) & 8) == 0) || (bVar2 != 0)) &&
       ((bVar16 == 1 || ((bVar2 == 1 || ((char)*(ushort *)(param_1 + 0x3fe) < '\0')))))) {
      uVar5 = 0;
      uVar11 = 0x1200;
      goto LAB_1400107a1;
    }
  }
  else {
    if (iVar4 == 4) {
      uVar3 = 0x100;
      local_res8 = 0x41;
    }
    else if (iVar4 == 5) {
      uVar3 = 0x2000;
      local_res8 = 0x81;
    }
    else if (iVar4 == 6) {
      uVar3 = 0x2100;
      local_res8 = 0x101;
    }
    else if (iVar4 == 7) {
      uVar3 = 0x40;
      local_res8 = 1;
      uVar11 = 0x100;
    }
    else {
      if (iVar4 != 8) {
        uVar3 = local_res8;
        goto LAB_140010745;
      }
      uVar3 = 0x140;
      local_res8 = 1;
      uVar11 = 0x200;
    }
LAB_140010749:
    LM_WritePhy(param_1,0,uVar3);
    LM_WritePhy(param_1,4,local_res8);
    uVar5 = 9;
LAB_1400107a1:
    LM_WritePhy(param_1,uVar5,uVar11);
  }
  LM_ReadPhy(param_1,0x1a);
  LM_ReadPhy(param_1,0x1a);
  uVar5 = 0x18;
  if ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0xc000) {
    uVar5 = LM_ReadPhy(param_1,0x1a);
    LM_WritePhy(param_1,0x1a,(ushort)uVar5 & 0xfcff);
    uVar5 = 0x1f;
    LM_WritePhy(param_1,0x1f,0x80);
    LM_WritePhy(param_1,0x10,0x4000);
    uVar11 = 0;
LAB_140010868:
    LM_WritePhy(param_1,uVar5,uVar11);
  }
  else if ((*(uint *)(param_1 + 0x3d7) & 0xfffffff0) != 0xbc050c70) {
    LM_WritePhy(param_1,0x1b,0xfffd);
    LM_WritePhy(param_1,0x18,0x7007);
    uVar18 = LM_ReadPhy(param_1,0x18);
    uVar11 = (ushort)uVar18 | 0x8200;
    goto LAB_140010868;
  }
  uVar5 = *(uint *)(param_1 + 0x3ca);
  bVar21 = false;
  if ((uVar5 >> 0xc != 0xc) && (uVar5 >> 0xc != 0x5785)) {
    iVar15 = 5;
    LM_WritePhy(param_1,0x18,0x7007);
    uVar5 = LM_ReadPhy(param_1,0x18);
    LM_WritePhy(param_1,0x18,(ushort)uVar5 | 0x8010);
    uVar5 = *(uint *)(param_1 + 0x3ca);
  }
  bVar1 = true;
  uVar8 = LM_Is575xFamily(param_1);
  if ((((char)uVar8 != '\0') || (uVar5 >> 0xc == 5)) || ((uVar5 >> 0xc) - 8 < 2)) {
    uVar9 = LM_PhyCableAttached(param_1);
    bVar1 = true;
    if ((char)uVar9 != '\x01') {
      bVar1 = false;
    }
  }
  *(undefined4 *)(param_1 + 0x3ed) = 5;
  if (bVar1) {
    iVar4 = 0;
    do {
      iVar12 = 0;
      do {
        uVar5 = LM_ReadPhy(param_1,1);
        if ((uVar5 & 4) != 0) {
          bVar21 = true;
          break;
        }
        mm_stall(10000);
        iVar12 = iVar12 + 1;
      } while (iVar12 < 800);
      if ((*(int *)(param_1 + 0x3db) != 0) ||
         (uVar5 = LM_ReadPhy(param_1,0x19), (short)uVar5 == 0x1000)) {
        bVar21 = true;
      }
    } while ((!bVar21) && (iVar4 = iVar4 + 1, iVar4 < iVar15));
    if (iVar12 < 800) {
      *(undefined4 *)(param_1 + 0x3ed) = 4;
    }
  }
  LM_ReadPhy(param_1,0x19);
  uVar5 = *(uint *)(param_1 + 0x368);
  uVar17 = uVar5 & 0xfffffff0;
  uVar18 = uVar17 | 0x400;
  *(undefined4 *)(param_1 + 0x3e9) = 2;
  iVar15 = 0;
  do {
    uVar6 = LM_ReadPhy(param_1,0x19);
    mm_stall(10);
    uVar7 = LM_ReadPhy(param_1,0x19);
    if ((ushort)uVar6 == (ushort)uVar7) break;
    iVar15 = iVar15 + 1;
  } while (iVar15 < 10);
  uVar11 = (ushort)uVar6 >> 8 & 7;
  if ((((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0xc000) ||
      ((*(uint *)(param_1 + 0x3d7) & 0xfffffff0) == 0xbc050c70)) && (uVar11 == 0)) {
    uVar6 = LM_ReadPhy(param_1,0x19);
    uVar11 = (ushort)uVar6 & 1;
    if ((uVar6 & 8) == 0) {
      uVar11 = uVar11 + 1;
    }
    else {
      uVar11 = uVar11 * 2 + 3;
    }
  }
  if (uVar11 == 0) {
LAB_140010af7:
    if (((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x7000) &&
       (*(char *)(param_1 + 0x3fc) != '\x02')) {
      uVar18 = uVar5 & 0xfffffbf0;
    }
    uVar5 = uVar18 | 8;
    *(undefined4 *)(param_1 + 0x3e5) = 1000000000;
    if (uVar11 == 6) {
      uVar5 = uVar18 | 10;
      *(undefined4 *)(param_1 + 0x3e9) = 1;
    }
  }
  else {
    if (uVar11 < 3) {
      uVar5 = uVar17 | 0x404;
      *(undefined4 *)(param_1 + 0x3e5) = 10000000;
      if ((*(char *)(param_1 + 0x463) == '\x02') && (*(int *)(param_1 + 0x3ca) == 0x57785000)) {
        lm_reg_wr_ind(param_1,0x3604,0x130000);
      }
      if (uVar11 == 1) {
        uVar5 = uVar17 | 0x406;
        *(undefined4 *)(param_1 + 0x3e9) = 1;
      }
      uVar19 = 3;
    }
    else {
      if (5 < uVar11) goto LAB_140010af7;
      if (((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x7000) &&
         (*(char *)(param_1 + 0x3fc) != '\x02')) {
        uVar18 = uVar5 & 0xfffffbf0;
      }
      uVar5 = uVar18 | 4;
      *(undefined4 *)(param_1 + 0x3e5) = 100000000;
      if (uVar11 == 3) {
        uVar5 = uVar18 | 6;
        *(undefined4 *)(param_1 + 0x3e9) = 1;
      }
      uVar19 = 1;
    }
    lm_reg_wr_ind(param_1,0x450,uVar19);
  }
  uVar18 = uVar5 & 0xfffffbff;
  if ((*(uint *)(param_1 + 0x3d7) & 0xfffffff0) != 0xbc050c70) {
    uVar18 = uVar5;
  }
  *(uint *)(param_1 + 0x368) = uVar18;
  lm_reg_wr_ind(param_1,0x400,uVar18);
  lm_reg_wr_ind(param_1,0x408,0x801000);
  uVar8 = LM_Is5705Family(param_1);
  lm_reg_wr_ind(param_1,0x404,(-(uint)((char)uVar8 != '\0') & 0xfe8) + 0x18);
  if (*(int *)(param_1 + 0x3ed) != 4) goto LAB_140010de5;
  if (*(char *)(param_1 + 0x3fe) < '\0') {
    if ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) != 0x57766000) {
      lVar14 = 100;
      do {
        lVar13 = lVar14;
        mm_stall(10000);
        lVar14 = lVar13 + -1;
      } while (lVar13 + -1 != 0);
      LM_WritePhy(param_1,0x18,0xc00);
      LM_WritePhy(param_1,(int)lVar13 + 0x16,(short)lVar13 + 0x19);
      LM_WritePhy(param_1,(int)lVar13 + 0x14,(short)lVar13 + 2);
      LM_WritePhy(param_1,0x18,0x400);
    }
    if ((*(int *)(param_1 + 0x3e5) == 10000000) || (*(int *)(param_1 + 0x3e9) != 2)) {
      uVar5 = lm_reg_read_ind(param_1,14000);
      lm_reg_wr_ind(param_1,14000,uVar5 & 0xffffff7f);
      LM_WritePhy(param_1,0x18,0xc00);
      LM_WritePhy(param_1,0x17,0x1a);
      LM_WritePhy(param_1,0x15,7);
      LM_WritePhy(param_1,0x18,0x400);
      *(ushort *)(param_1 + 0x3fe) = *(ushort *)(param_1 + 0x3fe) & 0xff7f;
    }
    else {
      uVar5 = lm_reg_read_ind(param_1,0x36d0);
      if (*(int *)(param_1 + 0x3e5) == 1000000000) {
        uVar5 = uVar5 | 0x19d;
LAB_140010c63:
        lm_reg_wr_ind(param_1,0x36d0,uVar5);
      }
      else if (*(int *)(param_1 + 0x3e5) == 100000000) {
        uVar5 = uVar5 | 900;
        goto LAB_140010c63;
      }
      lVar14 = 0x96;
      do {
        mm_stall(10000);
        lVar14 = lVar14 + -1;
      } while (lVar14 != 0);
      LM_WritePhy(param_1,0xd,7);
      LM_WritePhy(param_1,0xe,0x803e);
      LM_WritePhy(param_1,0xd,0x4007);
      uVar5 = LM_ReadPhy(param_1,0xe);
      if ((((uVar5 & 0xffff) - 2 & 0xfffffffd) == 0) &&
         ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) != 0x57766000)) {
        uVar5 = lm_reg_read_ind(param_1,14000);
        lm_reg_wr_ind(param_1,14000,uVar5 | 0x80);
      }
    }
  }
  uVar11 = 0;
  if ((*(char *)(param_1 + 0x3df) == '\0') || ((*(uint *)(param_1 + 0x3db) & 0xfffffffd) == 0)) {
    uVar3 = *(ushort *)(param_1 + 0x3a0);
    if ((uVar3 == 0x8000) || (((byte)uVar3 & 3) == 3)) {
      uVar11 = 0x400;
    }
    else if ((uVar3 & 2) == 0) {
      if ((uVar3 & 1) != 0) {
        uVar11 = 0xc00;
      }
    }
    else {
      uVar11 = 0x800;
    }
  }
  uVar5 = LM_ReadPhy(param_1,5);
  LM_SetFlowControl(param_1,uVar11,(ushort)uVar5);
LAB_140010de5:
  if (((*(uint *)(param_1 + 0x3ca) & 0xfffff000) == 0x5785000) &&
     ((*(uint *)(param_1 + 0x3d7) & 0xfffffff0) == 0x5c0d8a60)) {
    LM_WritePhy(param_1,0x18,0xc00);
    LM_WritePhy(param_1,0x17,0xfff);
    LM_WritePhy(param_1,0x15,0x4000);
    LM_WritePhy(param_1,0x17,0x21);
    LM_WritePhy(param_1,0x15,0x4600);
    LM_WritePhy(param_1,0x18,0x400);
    if (*(int *)(param_1 + 0x3ed) == 4) {
      iVar15 = *(int *)(param_1 + 0x3e5);
      LM_WritePhy(param_1,0x18,0xc00);
      LM_WritePhy(param_1,0x17,0xff0);
      if (iVar15 != 10000000) {
        uVar20 = 0;
      }
      LM_WritePhy(param_1,0x15,uVar20);
      LM_WritePhy(param_1,0x18,0x400);
      if (*(int *)(param_1 + 0x3e5) == 1000000000) {
        bVar21 = *(int *)(param_1 + 0x3db) == 0;
        if (bVar21) {
          LM_WritePhy(param_1,0xd,7);
          LM_WritePhy(param_1,0xe,0x3c);
          LM_WritePhy(param_1,0xd,0x4007);
          LM_WritePhy(param_1,0xe,6);
          LM_WritePhy(param_1,0x18,0xc00);
          LM_WritePhy(param_1,0x17,0xd40);
        }
        else {
          LM_WritePhy(param_1,0xd,7);
          LM_WritePhy(param_1,0xe,0x3c);
          LM_WritePhy(param_1,0xd,0x4007);
          LM_WritePhy(param_1,0xe,0);
          LM_WritePhy(param_1,0x18,0xc00);
          LM_WritePhy(param_1,0x17,0xd40);
        }
        LM_WritePhy(param_1,0x15,(ushort)bVar21);
        LM_WritePhy(param_1,0x18,0x400);
      }
    }
  }
  return 0;
}



===== LM_SetupPhyEee @ 140010fe8 =====

void LM_SetupPhyEee(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  
  lm_reg_wr_ind(param_1,14000,0x308);
  uVar1 = lm_reg_read_ind(param_1,14000);
  lm_reg_wr_ind(param_1,14000,uVar1 & 0xffffff7f);
  if (*(short *)(param_1 + 0x3ba) != 0x165f) {
    LM_WritePhy(param_1,0x18,0xc00);
    LM_WritePhy(param_1,0x17,0x1a);
    LM_WritePhy(param_1,0x15,7);
    LM_WritePhy(param_1,0x18,0x400);
  }
  LM_WritePhy(param_1,0x18,0xc00);
  LM_WritePhy(param_1,0x17,0x4022);
  LM_WritePhy(param_1,0x15,0x1ff);
  LM_WritePhy(param_1,0x18,0x400);
  LM_WritePhy(param_1,0xd,7);
  LM_WritePhy(param_1,0xe,0x3c);
  LM_WritePhy(param_1,0xd,0x4007);
  LM_WritePhy(param_1,0xe,6);
  LM_ReadPhy(param_1,0xe);
  uVar1 = lm_reg_read_ind(param_1,0x36bc);
  lm_reg_wr_ind(param_1,0x36bc,uVar1 | 0x1000004);
  uVar1 = lm_reg_read_ind(param_1,0x36d0);
  lm_reg_wr_ind(param_1,0x36d0,uVar1 | 0x1f8);
  uVar1 = lm_reg_read_ind(param_1,14000);
  uVar2 = 0x100348;
  if ((*(uint *)(param_1 + 0x3ca) & 0xfffff000) != 0x5785000) {
    uVar2 = 0x100308;
  }
  lm_reg_wr_ind(param_1,14000,uVar2 | uVar1);
  uVar1 = lm_reg_read_ind(param_1,0x36b4);
  lm_reg_wr_ind(param_1,0x36b4,uVar1 | 0x7ff07ff);
  uVar1 = lm_reg_read_ind(param_1,0x36b8);
  lm_reg_wr_ind(param_1,0x36b8,uVar1 | 0x7ff07ff);
  return;
}



===== LM_WritePhy @ 1400111d4 =====

void LM_WritePhy(longlong param_1,uint param_2,ushort param_3)

{
  uint uVar1;
  uint uVar2;
  
  lm_reg_wr_ind(param_1,0x44c,
                ((*(uint *)(param_1 + 0x3d3) | 0x120) << 5 | param_2 & 0x1f) << 0x10 | (uint)param_3
               );
  uVar2 = 0;
  do {
    uVar1 = lm_reg_read_ind(param_1,0x44c);
    if ((uVar1 >> 0x1d & 1) == 0) {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 10000);
  return;
}



===== bnx1_ethernetif_bringup @ 140011240 =====

ulonglong bnx1_ethernetif_bringup(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x28);
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0xe8)) {
    puVar4 = (undefined4 *)(lVar2 + 0x411);
    do {
      iVar5 = iVar5 + 1;
      *puVar4 = *(undefined4 *)((param_1 - lVar2) + -0x325 + (longlong)puVar4);
      *(undefined2 *)(puVar4 + 1) = *(undefined2 *)((param_1 - lVar2) + -0x321 + (longlong)puVar4);
      puVar4 = (undefined4 *)((longlong)puVar4 + 6);
      iVar1 = *(int *)(param_1 + 0xe8);
    } while (iVar5 < iVar1);
    *(int *)(lVar2 + 0x40d) = iVar1;
  }
  uVar3 = LM_SetReceiveMask(lVar2,5);
  return uVar3 & 0xffffffffffffff00;
}



===== bnx1_ethernetif_init @ 1400112a0 =====

undefined8 bnx1_ethernetif_init(longlong param_1)

{
  void *_Dst;
  undefined8 uVar1;
  
  _Dst = *(void **)(param_1 + 0x28);
  memset(_Dst,0,0x465);
  uVar1 = LM_GetAdapterInfo((longlong)_Dst,'\0');
  if (((int)uVar1 == 0) && (uVar1 = LM_InitializeAdapter((longlong)_Dst), (int)uVar1 == 0)) {
    LM_SetReceiveMask((longlong)_Dst,5);
    LM_EnableInterrupt((longlong)_Dst);
    *(undefined2 *)(param_1 + 0x3b) = 0x316e;
    *(code **)(param_1 + 0x18) = bnx1_protocol_transmit;
    *(code **)(param_1 + 0x20) = bnx1_transmit;
    return 0x140011300;
  }
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),0xf5);
}



===== bnx1_ethernetif_shutdown @ 140011320 =====

ulonglong bnx1_ethernetif_shutdown(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  LM_DisableInterrupt(lVar1);
  uVar2 = LM_Halt(lVar1,'\x01');
  return uVar2 & 0xffffffffffffff00;
}



===== bnx1_protocol_transmit @ 140011350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong bnx1_protocol_transmit(longlong param_1,longlong *param_2,uint *param_3)

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



===== bnx1_transmit @ 140011370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong bnx1_transmit(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = (**(code **)(l2_driver_intf + 0x28))(*(undefined8 *)(param_1 + 0x28));
  return uVar1 & 0xffffffffffffff00;
}



===== nx1_get_netif_intf @ 140011390 =====

void nx1_get_netif_intf(longlong param_1)

{
  *(code **)(param_1 + 0x60) = bnx1_ethernetif_init;
  *(code **)(param_1 + 0x70) = bnx1_ethernetif_shutdown;
  *(code **)(param_1 + 0x68) = bnx1_ethernetif_bringup;
  return;
}



===== LM_NvramReadBlock @ 1400113b4 =====

undefined8 LM_NvramReadBlock(longlong param_1,int param_2,longlong param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (param_4 != 0) {
    do {
      uVar1 = LM_NvramRead(param_1,uVar2 + param_2);
      uVar3 = uVar2 + 4;
      *(uint *)(param_3 + (ulonglong)(uVar2 >> 2) * 4) = uVar1;
      uVar2 = uVar3;
    } while (uVar3 < param_4);
  }
  return 0;
}



===== dir_get_dir_entry @ 14001141c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 dir_get_dir_entry(longlong param_1,uint param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  byte *pbVar2;
  longlong lVar3;
  int iVar4;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  undefined4 local_80 [22];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  if ((char)param_2 < '\0') {
    uVar1 = dir_get_dir_entry(param_1,0x10,param_3);
    iVar4 = 0;
    if ((int)uVar1 == 0) {
      do {
        LM_NvramReadBlock(param_1,*(int *)(param_3 + 1) + iVar4,(longlong)&local_88,0xc);
        if (local_88._7_1_ == param_2) {
          uVar1 = CONCAT17(local_88._7_1_,(undefined7)local_88);
LAB_1400114b7:
          *param_3 = uVar1;
          *(undefined4 *)(param_3 + 1) = local_80[0];
          return 0;
        }
        iVar4 = iVar4 + 0xc;
      } while (iVar4 < 0xc0);
    }
  }
  else {
    LM_NvramReadBlock(param_1,0x14,(longlong)&local_88,0x60);
    iVar4 = 0;
    pbVar2 = (byte *)((longlong)&local_88 + 7);
    lVar3 = 0;
    do {
      if (((*(uint *)(pbVar2 + -3) & 0x3fffff) != 0) && (*pbVar2 == param_2)) {
        uVar1 = *(undefined8 *)(auStack_a8 + (longlong)iVar4 * 0xc + 0x20);
        local_80[0] = local_80[(longlong)iVar4 * 3];
        goto LAB_1400114b7;
      }
      iVar4 = iVar4 + 1;
      lVar3 = lVar3 + 1;
      pbVar2 = pbVar2 + 0xc;
    } while (lVar3 < 8);
  }
  return 1;
}



===== dir_get_iscsi_block @ 140011520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 dir_get_iscsi_block(longlong param_1,u_long *param_2,uint param_3)

{
  u_long uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  int local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  LM_GetAdapterInfo(param_1,'\x01');
  uVar2 = dir_get_dir_entry(param_1,*(uint *)(&DAT_1400317c0 +
                                             (ulonglong)*(byte *)(param_1 + 0x444) * 4),&local_28);
  if ((int)uVar2 != 1) {
    LM_NvramReadBlock(param_1,local_20,(longlong)param_2,param_3);
    uVar3 = (ulonglong)(param_3 >> 2);
    if (param_3 >> 2 != 0) {
      do {
        uVar1 = htonl(*param_2);
        *param_2 = uVar1;
        param_2 = param_2 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== mm_device_poll @ 1400115c0 =====

undefined8 mm_device_poll(int *param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar6;
  uint uVar5;
  
  lm_service_intr(param_1);
  iVar3 = param_1[0xc2];
  if (iVar3 != param_1[0xc3]) {
    if (iVar3 == 0) {
      iVar3 = param_1[0xc4];
    }
    param_1[0xc2] = iVar3 - 1U;
    param_1[0xc5] = param_1[0xc5] + -1;
    iVar6 = param_1[0x7b];
    if (iVar6 == 0) {
      iVar6 = param_1[0x7c];
    }
    uVar5 = iVar6 - 1;
    if (uVar5 != param_1[0x7a]) {
      *(undefined8 *)(param_1 + (ulonglong)uVar5 * 2 + 0x7e) =
           *(undefined8 *)(param_1 + (ulonglong)(iVar3 - 1U) * 2 + 0xc6);
      param_1[0x7d] = param_1[0x7d] + 1;
      param_1[0x7b] = uVar5;
    }
  }
  if ((param_2 != 0) && (iVar3 = param_1[0x142], iVar3 != param_1[0x143])) {
    if (iVar3 == 0) {
      iVar3 = param_1[0x144];
    }
    param_1[0x142] = iVar3 - 1U;
    param_1[0x145] = param_1[0x145] + -1;
    lVar1 = *(longlong *)(param_1 + (ulonglong)(iVar3 - 1U) * 2 + 0x146);
    lVar2 = *(longlong *)(lVar1 + 0x38);
    uVar4 = mm_get_net_if();
    stack_rx_packet(uVar4,lVar2 + 0x12,*(undefined2 *)(lVar1 + 0x24));
    iVar3 = param_1[0xfb];
    if (iVar3 == 0) {
      iVar3 = param_1[0xfc];
    }
    uVar5 = iVar3 - 1;
    if (uVar5 != param_1[0xfa]) {
      *(longlong *)(param_1 + (ulonglong)uVar5 * 2 + 0xfe) = lVar1;
      param_1[0xfd] = param_1[0xfd] + 1;
      param_1[0xfb] = uVar5;
    }
    lm_post_buffers((longlong)param_1);
  }
  return 0;
}



===== mm_get_dma_buffer_length @ 1400116e0 =====

undefined8 mm_get_dma_buffer_length(void)

{
  return 0x2a28;
}



===== mm_get_free_pkt_desc @ 1400116e8 =====

longlong mm_get_free_pkt_desc(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1[0x7a];
  if (iVar3 != param_1[0x7b]) {
    if (iVar3 == 0) {
      iVar3 = param_1[0x7c];
    }
    param_1[0x7d] = param_1[0x7d] + -1;
    param_1[0x7a] = iVar3 - 1U;
    if (*(longlong *)(param_1 + (ulonglong)(iVar3 - 1U) * 2 + 0x7e) != 0) {
      return *(longlong *)(param_1 + (ulonglong)(iVar3 - 1U) * 2 + 0x7e);
    }
  }
  iVar3 = 0;
  do {
    uVar1 = lm_reg_read_ind(param_1,0x6800);
    lm_reg_wr_ind(param_1,0x6800,uVar1 | 0x20000);
    lm_service_intr(param_1);
    iVar2 = param_1[0xc2];
    if (iVar2 != param_1[0xc3]) {
      if (iVar2 == 0) {
        iVar2 = param_1[0xc4];
      }
      param_1[0xc5] = param_1[0xc5] + -1;
      param_1[0xc2] = iVar2 - 1U;
      if (*(longlong *)(param_1 + (ulonglong)(iVar2 - 1U) * 2 + 0xc6) != 0) {
        return *(longlong *)(param_1 + (ulonglong)(iVar2 - 1U) * 2 + 0xc6);
      }
    }
    mm_stall(1);
    iVar3 = iVar3 + 1;
    if (9999 < iVar3) {
      return 0;
    }
  } while( true );
}



===== mm_get_iscsi_block @ 1400117c0 =====

undefined8 mm_get_iscsi_block(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = lm_reg_read_ind(param_1,uVar2 + 0xa0000);
    uVar2 = uVar2 + 4;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  } while (uVar2 < 0x400);
  return 0;
}



===== mm_get_link_status @ 140011810 =====

undefined4 mm_get_link_status(undefined4 *param_1)

{
  return *param_1;
}



===== mm_get_mac_addr @ 140011820 =====

undefined8 mm_get_mac_addr(longlong param_1,undefined4 *param_2,int param_3)

{
  undefined2 uVar1;
  
  if (*(short *)(param_1 + 0x58) == 0) {
    lm_get_dev_info(param_1);
  }
  if (param_3 == 0) {
    *param_2 = *(undefined4 *)(param_1 + 100);
    uVar1 = *(undefined2 *)(param_1 + 0x68);
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x6a);
    uVar1 = *(undefined2 *)(param_1 + 0x6e);
  }
  *(undefined2 *)(param_2 + 1) = uVar1;
  return 0;
}



===== mm_get_rx_desc @ 140011880 =====

undefined * mm_get_rx_desc(int param_1)

{
  return &dev_rx_packet_ring + (longlong)param_1 * 0xf0;
}



===== mm_get_rx_packet @ 1400118a0 =====

undefined2 mm_get_rx_packet(int *param_1,void *param_2)

{
  longlong lVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  
  mm_device_poll(param_1,0);
  iVar3 = param_1[0x142];
  if (iVar3 == param_1[0x143]) {
    uVar2 = 0;
  }
  else {
    if (iVar3 == 0) {
      iVar3 = param_1[0x144];
    }
    param_1[0x142] = iVar3 - 1U;
    param_1[0x145] = param_1[0x145] + -1;
    lVar1 = *(longlong *)(param_1 + (ulonglong)(iVar3 - 1U) * 2 + 0x146);
    memmove(param_2,(void *)(*(longlong *)(lVar1 + 0x38) + 0x12),
            (ulonglong)*(ushort *)(lVar1 + 0x24));
    iVar3 = param_1[0xfb];
    if (iVar3 == 0) {
      iVar3 = param_1[0xfc];
    }
    uVar4 = iVar3 - 1;
    if (uVar4 != param_1[0xfa]) {
      *(longlong *)(param_1 + (ulonglong)uVar4 * 2 + 0xfe) = lVar1;
      param_1[0xfd] = param_1[0xfd] + 1;
      param_1[0xfb] = uVar4;
    }
    lm_post_buffers((longlong)param_1);
    uVar2 = *(undefined2 *)(lVar1 + 0x24);
  }
  return uVar2;
}



===== mm_get_tx_desc @ 140011950 =====

undefined * mm_get_tx_desc(int param_1)

{
  return &dev_tx_packet_ring + (longlong)param_1 * 0xf0;
}



===== mm_get_user_config @ 140011968 =====

undefined8 mm_get_user_config(longlong param_1)

{
  undefined2 uVar1;
  
  uVar1 = 8000;
  if ((char)*(undefined4 *)(param_1 + 0x9c) != '\x03') {
    uVar1 = 40000;
  }
  *(undefined2 *)(param_1 + 0x50) = uVar1;
  *(undefined4 *)(param_1 + 0x92) = 0x40002;
  *(undefined4 *)(param_1 + 0x98) = 0x80000000;
  *(undefined1 *)(param_1 + 0xa0) = 0;
  return 0;
}



===== mm_initialize_device_resources @ 1400119a4 =====

undefined8 mm_initialize_device_resources(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = mm_get_um_blk();
  uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x1b0),(uint *)(param_1 + 0x1b8),0x100);
  if ((((int)uVar2 == 0) &&
      (uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x3b0),(uint *)(param_1 + 0x3b8),0x100
                                ), (int)uVar2 == 0)) &&
     (uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x18),(uint *)(param_1 + 0x28),0x38),
     (int)uVar2 == 0)) {
    return uVar2;
  }
  return 0xffffffff;
}



===== mm_initialize_packets @ 140011a20 =====

undefined8 mm_initialize_packets(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  
  lVar1 = mm_get_um_blk();
  iVar5 = 0;
  if (*(short *)(param_1 + 0x94) != 0) {
    uVar4 = *(uint *)(param_1 + 0x3ec);
    do {
      uVar3 = *(uint *)(param_1 + 1000);
      if (uVar3 == uVar4) {
        lVar6 = 0;
      }
      else {
        if (uVar3 == 0) {
          uVar3 = *(uint *)(param_1 + 0x3f0);
        }
        *(int *)(param_1 + 0x3f4) = *(int *)(param_1 + 0x3f4) + -1;
        *(uint *)(param_1 + 1000) = uVar3 - 1;
        lVar6 = *(longlong *)(param_1 + 0x3f8 + (ulonglong)(uVar3 - 1) * 8);
      }
      uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(lVar6 + 0x38),(uint *)(lVar6 + 0x40),0x600);
      if ((int)uVar2 != 0) {
        return 1;
      }
      uVar4 = *(uint *)(param_1 + 0x3ec);
      uVar3 = uVar4;
      if (uVar4 == 0) {
        uVar3 = *(uint *)(param_1 + 0x3f0);
      }
      uVar3 = uVar3 - 1;
      if (uVar3 != *(uint *)(param_1 + 1000)) {
        *(longlong *)(param_1 + 0x3f8 + (ulonglong)uVar3 * 8) = lVar6;
        *(int *)(param_1 + 0x3f4) = *(int *)(param_1 + 0x3f4) + 1;
        *(uint *)(param_1 + 0x3ec) = uVar3;
        uVar4 = uVar3;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(ushort *)(param_1 + 0x94));
  }
  iVar5 = 0;
  if (*(short *)(param_1 + 0x92) != 0) {
    uVar4 = *(uint *)(param_1 + 0x1ec);
    do {
      uVar3 = *(uint *)(param_1 + 0x1e8);
      if (uVar3 == uVar4) {
        lVar6 = 0;
      }
      else {
        if (uVar3 == 0) {
          uVar3 = *(uint *)(param_1 + 0x1f0);
        }
        *(int *)(param_1 + 500) = *(int *)(param_1 + 500) + -1;
        *(uint *)(param_1 + 0x1e8) = uVar3 - 1;
        lVar6 = *(longlong *)(param_1 + 0x1f8 + (ulonglong)(uVar3 - 1) * 8);
      }
      uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(lVar6 + 0x38),(uint *)(lVar6 + 0x40),0x600);
      if ((int)uVar2 != 0) {
        return 1;
      }
      uVar4 = *(uint *)(param_1 + 0x1ec);
      uVar3 = uVar4;
      if (uVar4 == 0) {
        uVar3 = *(uint *)(param_1 + 0x1f0);
      }
      uVar3 = uVar3 - 1;
      if (uVar3 != *(uint *)(param_1 + 0x1e8)) {
        *(longlong *)(param_1 + 0x1f8 + (ulonglong)uVar3 * 8) = lVar6;
        *(int *)(param_1 + 500) = *(int *)(param_1 + 500) + 1;
        *(uint *)(param_1 + 0x1ec) = uVar3;
        uVar4 = uVar3;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(ushort *)(param_1 + 0x92));
  }
  return 0;
}



===== mm_set_mac_addr @ 140011bc0 =====

undefined8 mm_set_mac_addr(undefined8 param_1,undefined1 *param_2)

{
  lm_reg_wr_ind(param_1,0x1410,(uint)CONCAT11(*param_2,param_2[1]));
  lm_reg_wr_ind(param_1,0x1414,
                CONCAT31(CONCAT21(CONCAT11(param_2[2],param_2[3]),param_2[4]),param_2[5]));
  return 0;
}



===== mm_transmit_packet @ 140011bd0 =====

undefined4 mm_transmit_packet(int *param_1,longlong *param_2)

{
  ushort *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  longlong lVar4;
  int iVar5;
  
  lVar4 = mm_get_free_pkt_desc(param_1);
  if (lVar4 == 0) {
    uVar3 = 1;
  }
  else {
    lVar2 = *(longlong *)(lVar4 + 0x38);
    iVar5 = 0;
    *(short *)(lVar4 + 0x24) = (short)param_2[2];
    do {
      memmove((void *)(iVar5 + lVar2),(void *)param_2[1],
              (ulonglong)*(ushort *)((longlong)param_2 + 0x12));
      puVar1 = (ushort *)((longlong)param_2 + 0x12);
      param_2 = (longlong *)*param_2;
      iVar5 = iVar5 + (uint)*puVar1;
    } while (param_2 != (longlong *)0x0);
    *(undefined2 *)(lVar4 + 0x2a) = 0;
    *(byte *)(lVar4 + 0x48) = 1;
    *(undefined8 *)(lVar4 + 0x50) = *(undefined8 *)(lVar4 + 0x40);
    *(undefined2 *)(lVar4 + 0x4a) = *(undefined2 *)(lVar4 + 0x24);
    *(undefined2 *)(lVar4 + 0x58) = *(undefined2 *)(lVar4 + 0x24);
    if ((short)param_1[0xe] != 0) {
      *(ushort *)(lVar4 + 0x2a) = *(ushort *)(lVar4 + 0x2a) | 1;
      *(short *)(lVar4 + 0x2c) = (short)param_1[0xe];
    }
    lm_send_packet((longlong)param_1,lVar4,(byte *)(lVar4 + 0x48));
    uVar3 = 0;
  }
  return uVar3;
}



===== mm_transmit_packet_raw @ 140011c90 =====

undefined4 mm_transmit_packet_raw(int *param_1,void *param_2,ushort param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  
  lVar2 = mm_get_free_pkt_desc(param_1);
  if (lVar2 == 0) {
    uVar1 = 1;
  }
  else {
    *(ushort *)(lVar2 + 0x24) = param_3;
    memmove(*(void **)(lVar2 + 0x38),param_2,(ulonglong)param_3);
    *(undefined2 *)(lVar2 + 0x2a) = 0;
    *(byte *)(lVar2 + 0x48) = 1;
    *(undefined8 *)(lVar2 + 0x50) = *(undefined8 *)(lVar2 + 0x40);
    *(undefined2 *)(lVar2 + 0x4a) = *(undefined2 *)(lVar2 + 0x24);
    *(undefined2 *)(lVar2 + 0x58) = *(undefined2 *)(lVar2 + 0x24);
    if ((short)param_1[0xe] != 0) {
      *(ushort *)(lVar2 + 0x2a) = *(ushort *)(lVar2 + 0x2a) | 1;
      *(short *)(lVar2 + 0x2c) = (short)param_1[0xe];
    }
    lm_send_packet((longlong)param_1,lVar2,(byte *)(lVar2 + 0x48));
    uVar1 = 0;
  }
  return uVar1;
}



===== nx2_get_intf @ 140011d3c =====

undefined8 nx2_get_intf(undefined8 *param_1)

{
  *param_1 = &DAT_14007e260;
  param_1[1] = mm_get_dma_buffer;
  param_1[2] = mm_get_iscsi_block;
  param_1[3] = mm_get_rx_packet;
  param_1[4] = mm_transmit_packet_raw;
  param_1[5] = mm_transmit_packet;
  param_1[6] = mm_get_dma_buffer_length;
  param_1[7] = bnx2_dir_get_iscsi_block;
  param_1[8] = mm_get_mac_addr;
  param_1[9] = mm_set_mac_addr;
  param_1[10] = mm_device_poll;
  param_1[0xb] = mm_get_link_status;
  param_1[0x10] = iscsiBootCancel;
  param_1[0x11] = mm_interrupt_control;
  nx2_get_netif_intf((longlong)param_1);
  return 0;
}



===== lm_ctx_wr @ 140011dec =====

void lm_ctx_wr(undefined8 param_1,int param_2,int param_3,undefined4 param_4)

{
  lm_reg_wr_ind(param_1,0x1010,param_3 + param_2);
  lm_reg_wr_ind(param_1,0x1014,param_4);
  return;
}



===== lm_get_dev_info @ 140011e24 =====

undefined8 lm_get_dev_info(longlong param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = storport_pci_cfg_read_dword(param_1,0);
  *(short *)(param_1 + 0x58) = (short)uVar2;
  *(short *)(param_1 + 0x5a) = (short)((uint)uVar2 >> 0x10);
  uVar2 = storport_pci_cfg_read_dword(param_1,0x2c);
  *(short *)(param_1 + 0x5e) = (short)uVar2;
  *(short *)(param_1 + 0x5c) = (short)((uint)uVar2 >> 0x10);
  uVar2 = storport_pci_cfg_read_dword(param_1,0x3c);
  *(char *)(param_1 + 0x60) = (char)uVar2;
  *(char *)(param_1 + 0x61) = (char)((uint)uVar2 >> 8);
  uVar2 = storport_pci_cfg_read_dword(param_1,0xc);
  *(char *)(param_1 + 0x62) = (char)uVar2;
  uVar2 = storport_pci_cfg_read_dword(param_1,8);
  *(char *)(param_1 + 99) = (char)uVar2;
  storport_pci_cfg_write_dword(param_1,0x68,0x88);
  storport_pci_cfg_write_dword(param_1,0x78,0x808);
  uVar2 = storport_pci_cfg_read_dword(param_1,0x80);
  *(undefined4 *)(param_1 + 0x74) = uVar2;
  uVar3 = storport_pci_cfg_read_dword(param_1,0x6c);
  if ((uVar3 & 8) == 0) {
    *(undefined1 *)(param_1 + 0x78) = 0;
    uVar1 = 0x42;
    if ((uVar3 & 4) == 0) goto LAB_140011f1e;
  }
  else {
    *(undefined1 *)(param_1 + 0x78) = 1;
    uVar4 = storport_pci_cfg_read_dword(param_1,0x70);
    uVar4 = uVar4 & 0xf;
    if (uVar4 < 2) {
LAB_140011f1e:
      uVar1 = 0x21;
    }
    else if (uVar4 < 4) {
      uVar1 = 0x32;
    }
    else if (uVar4 < 6) {
      uVar1 = 0x42;
    }
    else if (uVar4 == 6) {
      uVar1 = 100;
    }
    else {
      if (uVar4 != 7) goto LAB_140011f1e;
      uVar1 = 0x85;
    }
  }
  *(undefined2 *)(param_1 + 0x7a) = uVar1;
  *(byte *)(param_1 + 0x79) = (-((uVar3 & 2) != 0) & 0xe0U) + 0x40;
  uVar3 = storport_pci_cfg_read_dword(param_1,4);
  if (((*(uint *)(param_1 + 0x74) & 0xfffffff0) == 0x57060010) &&
     (*(char *)(param_1 + 0x78) == '\0')) {
    uVar3 = uVar3 & 0xfffffebf;
  }
  storport_pci_cfg_write_dword(param_1,4,uVar3 | 4);
  *(undefined1 *)(param_1 + 0x81) = 0;
  if ((*(uint *)(param_1 + 0x74) & 0xffff0000) == 0x57090000) {
    storport_pci_cfg_write_dword(param_1,0x78,0x1400a0);
    iVar5 = storport_pci_cfg_read_dword(param_1,0x80);
    if (iVar5 < 0) {
      *(undefined1 *)(param_1 + 0x81) = 1;
    }
  }
  storport_pci_cfg_write_dword(param_1,0x78,0x160000);
  uVar3 = storport_pci_cfg_read_dword(param_1,0x80);
  if ((uVar3 & 0xffff0000) == 0x53530000) {
    storport_pci_cfg_write_dword(param_1,0x78,(uint)*(byte *)(param_1 + 0x81) * 4 + 0x160004);
    iVar5 = storport_pci_cfg_read_dword(param_1,0x80);
  }
  else {
    iVar5 = 0x167c00;
  }
  *(int *)(param_1 + 0x48) = iVar5;
  storport_pci_cfg_write_dword(param_1,0x78,iVar5 + 0x20);
  uVar3 = storport_pci_cfg_read_dword(param_1,0x80);
  if ((uVar3 & 0xffffff00) != 0x44564900) {
    return 1;
  }
  lm_nvram_init(param_1);
  storport_pci_cfg_write_dword(param_1,0x78,*(int *)(param_1 + 0x48) + 0x50);
  uVar2 = storport_pci_cfg_read_dword(param_1,0x80);
  *(char *)(param_1 + 0x65) = (char)uVar2;
  *(char *)(param_1 + 100) = (char)((uint)uVar2 >> 8);
  storport_pci_cfg_write_dword(param_1,0x78,*(int *)(param_1 + 0x48) + 0x54);
  uVar2 = storport_pci_cfg_read_dword(param_1,0x80);
  *(char *)(param_1 + 0x69) = (char)uVar2;
  *(char *)(param_1 + 0x66) = (char)((uint)uVar2 >> 0x18);
  *(char *)(param_1 + 0x67) = (char)((uint)uVar2 >> 0x10);
  *(char *)(param_1 + 0x68) = (char)((uint)uVar2 >> 8);
  storport_pci_cfg_write_dword(param_1,0x78,*(int *)(param_1 + 0x48) + 0x78);
  uVar2 = storport_pci_cfg_read_dword(param_1,0x80);
  *(char *)(param_1 + 0x6b) = (char)uVar2;
  *(char *)(param_1 + 0x6a) = (char)((uint)uVar2 >> 8);
  storport_pci_cfg_write_dword(param_1,0x78,*(int *)(param_1 + 0x48) + 0x7c);
  uVar2 = storport_pci_cfg_read_dword(param_1,0x80);
  *(char *)(param_1 + 0x6f) = (char)uVar2;
  *(char *)(param_1 + 0x6c) = (char)((uint)uVar2 >> 0x18);
  *(char *)(param_1 + 0x6d) = (char)((uint)uVar2 >> 0x10);
  *(undefined1 *)(param_1 + 0x8a) = *(undefined1 *)(param_1 + 100);
  *(undefined1 *)(param_1 + 0x8b) = *(undefined1 *)(param_1 + 0x65);
  *(undefined1 *)(param_1 + 0x8c) = *(undefined1 *)(param_1 + 0x66);
  *(undefined1 *)(param_1 + 0x8d) = *(undefined1 *)(param_1 + 0x67);
  *(undefined1 *)(param_1 + 0x8e) = *(undefined1 *)(param_1 + 0x68);
  *(char *)(param_1 + 0x6e) = (char)((uint)uVar2 >> 8);
  *(undefined1 *)(param_1 + 0x8f) = *(undefined1 *)(param_1 + 0x69);
  *(undefined4 *)(param_1 + 0x92) = 0x100010;
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined2 *)(param_1 + 0xa1) = 0x202;
  *(undefined2 *)(param_1 + 0x4e) = 0;
  lm_get_phy_info(param_1);
  mm_get_user_config(param_1);
  if ((char)*(undefined4 *)(param_1 + 0x9c) == '\x03') {
    storport_pci_cfg_write_dword(param_1,0x78,*(int *)(param_1 + 0x48) + 0x58);
    uVar3 = storport_pci_cfg_read_dword(param_1,0x80);
    if ((uVar3 & 0x1f0000) == 0x30000) {
      *(undefined1 *)(param_1 + 0x9d) = 3;
    }
    else {
      if ((uVar3 & 0x1f0000) != 0x40000) goto LAB_14001219e;
      *(undefined1 *)(param_1 + 0x9d) = 4;
    }
    *(undefined1 *)(param_1 + 0xa0) = 0;
  }
LAB_14001219e:
  *(undefined2 *)(param_1 + 0x88) = 0x5ea;
  return 0;
}



===== lm_get_phy_info @ 1400121bc =====

void lm_get_phy_info(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  storport_pci_cfg_write_dword(param_1,0x78,*(int *)(param_1 + 0x48) + 0x368);
  uVar1 = storport_pci_cfg_read_dword(param_1,0x80);
  if (((uVar1 & 0xffff0000) == 0xaa550000) && ((uVar1 & 1) != 0)) {
    *(undefined1 *)(param_1 + 0x80) = 5;
    goto switchD_1400122a3_caseD_3;
  }
  uVar1 = *(uint *)(param_1 + 0x74) & 0xffff0000;
  if (uVar1 != 0x57090000) {
    if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
      *(undefined1 *)(param_1 + 0x80) = 0;
    }
    else {
      *(char *)(param_1 + 0x80) = (uVar1 == 0x57080000) + '\x01';
    }
    goto switchD_1400122a3_caseD_3;
  }
  storport_pci_cfg_write_dword(param_1,0x78,0x8ec);
  uVar1 = storport_pci_cfg_read_dword(param_1,0x80);
  uVar2 = uVar1 & 0xff;
  if (uVar2 == 3) {
switchD_1400122a3_caseD_0:
    *(undefined1 *)(param_1 + 0x80) = 3;
  }
  else {
    if ((uVar2 != 0xc) && (uVar2 != 9)) {
      uVar2 = uVar1 >> 0x15;
      if ((uVar1 & 0x2000000) == 0) {
        uVar2 = uVar1 >> 8;
      }
      uVar3 = uVar2 & 7 | 8;
      if ((uVar1 & 0x1000000) == 0) {
        uVar3 = uVar2 & 7;
      }
      uVar1 = uVar3 | 0x10;
      if (*(char *)(param_1 + 0x81) == '\0') {
        uVar1 = uVar3;
      }
      switch(uVar1) {
      case 0:
      case 1:
      case 2:
      case 8:
      case 9:
      case 10:
      case 0x10:
      case 0x15:
      case 0x16:
      case 0x18:
      case 0x1d:
      case 0x1e:
        goto switchD_1400122a3_caseD_0;
      default:
        goto switchD_1400122a3_caseD_3;
      case 4:
      case 5:
      case 6:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0x11:
      case 0x12:
      case 0x14:
      case 0x19:
      case 0x1a:
      case 0x1c:
        break;
      }
    }
    *(undefined1 *)(param_1 + 0x80) = 4;
  }
switchD_1400122a3_caseD_3:
  *(undefined2 *)(param_1 + 0x70) = 1;
  *(undefined1 *)(param_1 + 0x9c) = 2;
  if ((((byte)(*(char *)(param_1 + 0x80) - 1U) < 2) || ((byte)(*(char *)(param_1 + 0x80) - 4U) < 2))
     && (*(undefined1 *)(param_1 + 0x9c) = 3,
        ((*(uint *)(param_1 + 0x74) & 0xffff0000) + 0xa8f80000 & 0xfffeffff) == 0)) {
    *(undefined2 *)(param_1 + 0x70) = 2;
  }
  return;
}



===== lm_init_resc @ 140012354 =====

undefined8 lm_init_resc(longlong param_1)

{
  undefined8 *puVar1;
  int iVar3;
  uint uVar2;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x598) = 1;
  *(undefined8 *)(param_1 + 1000) = 0;
  *(undefined8 *)(param_1 + 0x478) = 0;
  *(undefined8 *)(param_1 + 0x508) = 0;
  *(undefined8 *)(param_1 + 0x1e8) = 0;
  *(undefined8 *)(param_1 + 0x278) = 0;
  *(undefined8 *)(param_1 + 0x308) = 0;
  *(undefined8 *)(param_1 + 0x3f0) = 0x10;
  *(undefined8 *)(param_1 + 0x480) = 0x10;
  *(undefined8 *)(param_1 + 0x510) = 0x10;
  *(undefined4 *)(param_1 + 0x398) = 1;
  *(undefined8 *)(param_1 + 0x1f0) = 0x10;
  *(undefined8 *)(param_1 + 0x280) = 0x10;
  *(undefined8 *)(param_1 + 0x310) = 0x10;
  mm_initialize_device_resources(param_1);
  iVar4 = 0;
  if (*(short *)(param_1 + 0x92) != 0) {
    do {
      puVar1 = (undefined8 *)mm_get_tx_desc(iVar4);
      *(undefined4 *)(puVar1 + 1) = 0x7450324c;
      *puVar1 = 0;
      *(undefined1 *)((longlong)puVar1 + 0xc) = 0;
      puVar1[2] = param_1;
      puVar1[3] = param_1 + 0x1a8;
      *(undefined1 *)(puVar1 + 5) = 0;
      iVar3 = *(int *)(param_1 + 0x1ec);
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_1 + 0x1f0);
      }
      uVar2 = iVar3 - 1;
      if (uVar2 != *(uint *)(param_1 + 0x1e8)) {
        *(undefined8 **)(param_1 + 0x1f8 + (ulonglong)uVar2 * 8) = puVar1;
        *(int *)(param_1 + 500) = *(int *)(param_1 + 500) + 1;
        *(uint *)(param_1 + 0x1ec) = uVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)*(ushort *)(param_1 + 0x92));
  }
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  iVar4 = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0x800;
  *(longlong *)(param_1 + 0x1d8) = *(longlong *)(param_1 + 0x18) + 10;
  if (*(short *)(param_1 + 0x94) != 0) {
    do {
      puVar1 = (undefined8 *)mm_get_rx_desc(iVar4);
      *(undefined4 *)(puVar1 + 1) = 0x7250324c;
      *puVar1 = 0;
      *(undefined1 *)((longlong)puVar1 + 0xc) = 1;
      puVar1[2] = param_1;
      puVar1[3] = param_1 + 0x3a8;
      *(undefined1 *)(puVar1 + 5) = 0;
      *(undefined2 *)(puVar1 + 9) = 0x600;
      iVar3 = *(int *)(param_1 + 0x3ec);
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_1 + 0x3f0);
      }
      uVar2 = iVar3 - 1;
      if (uVar2 != *(uint *)(param_1 + 1000)) {
        *(undefined8 **)(param_1 + 0x3f8 + (ulonglong)uVar2 * 8) = puVar1;
        *(int *)(param_1 + 0x3f4) = *(int *)(param_1 + 0x3f4) + 1;
        *(uint *)(param_1 + 0x3ec) = uVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)*(ushort *)(param_1 + 0x94));
  }
  mm_initialize_packets(param_1);
  *(longlong *)(param_1 + 0x3d8) = *(longlong *)(param_1 + 0x18) + 0x12;
  *(undefined4 *)(param_1 + 0x3a8) = 0;
  *(undefined4 *)(param_1 + 0x3c0) = 0;
  return 0;
}



===== lm_post_buffers @ 140012534 =====

int lm_post_buffers(longlong param_1)

{
  undefined4 *puVar1;
  ushort uVar2;
  longlong lVar3;
  int iVar5;
  uint uVar4;
  int iVar6;
  int iVar7;
  ushort uVar8;
  undefined4 *puVar9;
  
  iVar6 = *(int *)(param_1 + 1000);
  iVar7 = 0;
  if (iVar6 == *(int *)(param_1 + 0x3ec)) {
    lVar3 = 0;
  }
  else {
    if (iVar6 == 0) {
      iVar6 = *(int *)(param_1 + 0x3f0);
    }
    *(int *)(param_1 + 0x3f4) = *(int *)(param_1 + 0x3f4) + -1;
    *(uint *)(param_1 + 1000) = iVar6 - 1U;
    lVar3 = *(longlong *)(param_1 + 0x3f8 + (ulonglong)(iVar6 - 1U) * 8);
  }
  uVar8 = *(ushort *)(param_1 + 0x3c4);
  iVar6 = *(int *)(param_1 + 0x3d0);
  puVar1 = *(undefined4 **)(param_1 + 0x3c8);
  while (puVar9 = puVar1, lVar3 != 0) {
    iVar6 = iVar6 + (uint)*(ushort *)(lVar3 + 0x48);
    puVar9 = puVar1 + 4;
    uVar2 = uVar8 + 1;
    if (((byte)(uVar8 + 1) & 0xf) == 0xf) {
      puVar9 = *(undefined4 **)(puVar1 + 6);
      uVar2 = uVar8 + 2;
    }
    uVar8 = uVar2;
    *(ushort *)(lVar3 + 0x36) = uVar8;
    puVar1[1] = *(undefined4 *)(lVar3 + 0x40);
    *puVar1 = *(undefined4 *)(lVar3 + 0x44);
    puVar1[2] = (uint)*(ushort *)(lVar3 + 0x48);
    *(undefined2 *)(puVar1 + 3) = 0xc;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + -1;
    iVar5 = *(int *)(param_1 + 0x47c);
    if (iVar5 == 0) {
      iVar5 = *(int *)(param_1 + 0x480);
    }
    uVar4 = iVar5 - 1;
    if (uVar4 != *(uint *)(param_1 + 0x478)) {
      *(longlong *)(param_1 + 0x488 + (ulonglong)uVar4 * 8) = lVar3;
      *(int *)(param_1 + 0x484) = *(int *)(param_1 + 0x484) + 1;
      *(uint *)(param_1 + 0x47c) = uVar4;
    }
    iVar7 = iVar7 + 1;
    if ((*(int *)(param_1 + 0x3e0) == 0) ||
       (iVar5 = *(int *)(param_1 + 1000), iVar5 == *(int *)(param_1 + 0x3ec))) break;
    if (iVar5 == 0) {
      iVar5 = *(int *)(param_1 + 0x3f0);
    }
    *(int *)(param_1 + 0x3f4) = *(int *)(param_1 + 0x3f4) + -1;
    *(uint *)(param_1 + 1000) = iVar5 - 1U;
    puVar1 = puVar9;
    lVar3 = *(longlong *)(param_1 + 0x3f8 + (ulonglong)(iVar5 - 1U) * 8);
  }
  *(ushort *)(param_1 + 0x3c4) = uVar8;
  *(undefined4 **)(param_1 + 0x3c8) = puVar9;
  *(int *)(param_1 + 0x3d0) = iVar6;
  if (iVar7 != 0) {
    lm_wr_mbx16(param_1,(*(uint *)(param_1 + 0x3c0) & 0xffffff80) * 2 + 0x10004,uVar8);
    lm_wr_mbx32(param_1,(*(uint *)(param_1 + 0x3c0) & 0xffffff80) * 2 + 0x10008,iVar6);
  }
  return iVar7;
}



===== lm_set_mac_addr @ 1400126c0 =====

undefined8 lm_set_mac_addr(undefined8 param_1,undefined1 *param_2)

{
  lm_reg_wr_ind(param_1,0x1410,(uint)CONCAT11(*param_2,param_2[1]));
  lm_reg_wr_ind(param_1,0x1414,
                CONCAT31(CONCAT21(CONCAT11(param_2[2],param_2[3]),param_2[4]),param_2[5]));
  return 0;
}



===== lm_set_rx_mask @ 14001272c =====

undefined8 lm_set_rx_mask(longlong param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = param_2 | *(uint *)(param_1 + 0x59c);
  storport_pci_cfg_write_dword(param_1,0x78,0x14c8);
  uVar4 = uVar6 & 0xfffffffe;
  if ((uVar6 & 1) == 0) {
    uVar4 = uVar6;
  }
  uVar3 = uVar4 & 0xfffffffd;
  if ((uVar4 & 2) == 0) {
    uVar3 = uVar4;
  }
  uVar4 = uVar3 & 0xfffffffb;
  if ((uVar3 & 4) == 0) {
    uVar4 = uVar3;
  }
  uVar1 = storport_pci_cfg_read_dword(param_1,0x80);
  uVar3 = uVar4 & 0xfffffff7;
  if ((uVar4 & 8) == 0) {
    uVar3 = uVar4;
  }
  uVar7 = uVar1 & 0xfffff7ff;
  if ((uVar4 & 8) == 0) {
    uVar7 = uVar1 & 0xfffff7ff | 0x800;
  }
  uVar4 = uVar3 & 0xffffffef;
  if ((uVar3 & 0x10) == 0) {
    uVar4 = uVar3;
  }
  uVar1 = uVar7 & 0xffffff9f | 0x260;
  if ((uVar3 & 0x10) == 0) {
    uVar1 = uVar7 & 0xffffff9f;
  }
  uVar3 = uVar1 & 0xfffffeff | 0x100;
  if ((uVar4 & 0x10000) == 0) {
    uVar3 = uVar1 & 0xfffffeff;
  }
  uVar1 = uVar4 & 0xfffeffff;
  if ((uVar4 & 0x10000) == 0) {
    uVar1 = uVar4;
  }
  if (uVar1 == 0) {
    if ((uVar6 & 4) == 0) {
      if ((uVar6 & 2) == 0) {
        bVar5 = 0;
        do {
          lm_reg_wr_ind(param_1,(uint)bVar5 * 4 + 0x14d0,0);
          bVar5 = bVar5 + 1;
        } while (bVar5 < 8);
      }
      else {
        set_mc_hash_reg(param_1,(byte *)(param_1 + 0xa4));
      }
    }
    else {
      bVar5 = 0;
      do {
        lm_reg_wr_ind(param_1,(uint)bVar5 * 4 + 0x14d0,0xffffffff);
        bVar5 = bVar5 + 1;
      } while (bVar5 < 8);
    }
    *(uint *)(param_1 + 0x59c) = param_2;
    lm_reg_wr_ind(param_1,0x14c8,uVar3 | 0x1000);
    uVar4 = param_2 & 1 | 0x40000;
    if ((param_2 & 2) == 0) {
      uVar4 = param_2 & 1;
    }
    uVar6 = uVar4 | 0x20000;
    if ((param_2 & 4) == 0) {
      uVar6 = uVar4;
    }
    uVar4 = uVar6 | 0x10000;
    if ((param_2 & 8) == 0) {
      uVar4 = uVar6;
    }
    uVar6 = uVar4 | 0x80000;
    if ((param_2 & 0x10000) == 0) {
      uVar6 = uVar4;
    }
    if (*(ushort *)(param_1 + 0x38) != 0) {
      uVar6 = uVar6 | 0xf00000;
      lm_reg_wr_ind(param_1,0x1810,(uint)*(ushort *)(param_1 + 0x38));
    }
    lm_reg_wr_ind(param_1,0x1820,0);
    lm_reg_wr_ind(param_1,0x1820,uVar6);
    lm_reg_wr_ind(param_1,0x1820,uVar6 | 0x80000000);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== lm_update_shmem_link_status @ 140012928 =====

void lm_update_shmem_link_status(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_1[1];
  uVar3 = (uint)(*param_1 == 4);
  uVar2 = uVar1 & 0xff00;
  if (uVar2 == 0x100) {
    if ((uVar1 >> 0x10 & 1) == 0) {
      uVar3 = uVar3 | 4;
    }
    else {
      uVar3 = uVar3 | 2;
    }
  }
  else {
    if (uVar2 == 0x200) {
      uVar1 = (-(uint)((uVar1 & 0x10000) != 0) & 0xfffffffc) + 10;
    }
    else {
      if (uVar2 != 0x300) {
        if (uVar2 == 0x400) {
          if ((uVar1 >> 0x10 & 1) == 0) {
            uVar3 = uVar3 | 0x12;
          }
          else {
            uVar3 = uVar3 | 0x10;
          }
        }
        goto LAB_1400129a0;
      }
      uVar1 = ~(uVar1 >> 0xf) & 2 | 0xc;
    }
    uVar3 = uVar3 | uVar1;
  }
LAB_1400129a0:
  lm_reg_wr_ind(param_1,param_1[0x12] + 0xc,uVar3);
  return;
}



===== lm_wr_mbx16 @ 1400129ac =====

void lm_wr_mbx16(longlong param_1,uint param_2,ushort param_3)

{
  byte bVar1;
  
  if ((*(uint *)(param_1 + 0x74) & 0xfffffff0) == 0x57090000) {
    if ((param_2 & 4) == 0) {
      param_2 = param_2 | 4;
    }
    else {
      param_2 = param_2 & 0xfffffffb;
    }
  }
  storport_pci_cfg_write_dword(param_1,0x90,param_2);
  bVar1 = ((byte)param_2 & 3) + 0x94;
  if ((*(uint *)(param_1 + 0x74) & 0xffff0000) == 0x57090000) {
    storport_pci_cfg_write_dword(param_1,bVar1,(uint)param_3);
  }
  else {
    storport_pci_cfg_write_word(param_1,bVar1,param_3);
  }
  return;
}



===== lm_wr_mbx32 @ 140012a28 =====

void lm_wr_mbx32(longlong param_1,uint param_2,undefined4 param_3)

{
  if ((*(uint *)(param_1 + 0x74) & 0xfffffff0) == 0x57090000) {
    if ((param_2 & 4) == 0) {
      param_2 = param_2 | 4;
    }
    else {
      param_2 = param_2 & 0xfffffffb;
    }
  }
  storport_pci_cfg_write_dword(param_1,0x90,param_2);
  storport_pci_cfg_write_dword(param_1,0x94,param_3);
  return;
}



===== set_mc_hash_reg @ 140012a74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void set_mc_hash_reg(undefined8 param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  uint *puVar8;
  uint uVar9;
  byte *pbVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined1 auStack_58 [32];
  uint local_38 [8];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  uVar5 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  if (*param_2 != 0) {
    pbVar10 = param_2 + 2;
    uVar12 = (ulonglong)*param_2;
    do {
      uVar9 = 0xffffffff;
      lVar11 = 6;
      pbVar3 = pbVar10;
      do {
        uVar9 = uVar9 ^ *pbVar3;
        lVar7 = 8;
        do {
          lVar6 = lVar7;
          uVar2 = uVar9 >> 1;
          uVar1 = uVar9 & 1;
          uVar9 = uVar2 ^ 0xedb88320;
          if (uVar1 == 0) {
            uVar9 = uVar2;
          }
          lVar7 = lVar6 + -1;
        } while (lVar7 != 0);
        pbVar3 = pbVar3 + 1;
        lVar11 = lVar11 + -1;
      } while (lVar11 != 0);
      pbVar10 = pbVar10 + 8;
      local_38[uVar9 >> 5 & 7] = local_38[uVar9 >> 5 & 7] | (int)lVar6 << ((byte)uVar9 & 0x1f);
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
  }
  puVar8 = local_38;
  do {
    lm_reg_wr_ind(param_1,uVar5 * 4 + 0x14d0,*puVar8);
    bVar4 = (char)uVar5 + 1;
    uVar5 = (uint)bVar4;
    puVar8 = puVar8 + 1;
  } while (bVar4 < 8);
  return;
}



===== lm_send_packet @ 140012b58 =====

undefined8 lm_send_packet(longlong param_1,longlong param_2,byte *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  ushort uVar7;
  ushort uVar8;
  byte *pbVar9;
  int iVar10;
  
  iVar10 = 0;
  piVar1 = (int *)((ulonglong)*(uint *)(param_1 + 0x1a8) * 0x1f0 + 0x1e0 + param_1);
  *piVar1 = *piVar1 - (uint)*param_3;
  puVar2 = *(undefined4 **)(param_1 + 0x1c8);
  uVar7 = *(ushort *)(param_1 + 0x1c4);
  uVar8 = (*(ushort *)(param_2 + 0x2a) & 1) << 3;
  puVar5 = puVar2;
  puVar6 = puVar2;
  pbVar9 = param_3 + 8;
  if (*param_3 != 0) {
    do {
      puVar6 = puVar5;
      puVar6[1] = *(undefined4 *)pbVar9;
      *puVar6 = *(undefined4 *)(pbVar9 + 4);
      *(undefined2 *)(puVar6 + 2) = *(undefined2 *)(pbVar9 + 8);
      *(undefined2 *)((longlong)puVar6 + 0xe) = *(undefined2 *)(param_2 + 0x2c);
      *(ushort *)(puVar6 + 3) = uVar8;
      puVar5 = puVar6 + 4;
      uVar3 = uVar7 + 1;
      if (((byte)(uVar7 + 1) & 0xf) == 0xf) {
        puVar5 = *(undefined4 **)(puVar6 + 6);
        uVar3 = uVar7 + 2;
      }
      uVar7 = uVar3;
      iVar10 = iVar10 + 1;
      pbVar9 = pbVar9 + 0x10;
    } while (iVar10 < (int)(uint)*param_3);
  }
  *(ushort *)(puVar6 + 3) = *(ushort *)(puVar6 + 3) | uVar8 | 0x40;
  *(ushort *)(puVar2 + 3) = *(ushort *)(puVar2 + 3) | 0x80;
  *(ushort *)(param_2 + 0x30) = (ushort)*param_3;
  *(ushort *)(param_2 + 0x2e) = uVar7;
  *(undefined4 **)(param_1 + 0x1c8) = puVar5;
  *(ushort *)(param_1 + 0x1c4) = uVar7;
  *(int *)(param_1 + 0x1d0) = *(int *)(param_1 + 0x1d0) + (uint)*(ushort *)(param_2 + 0x24);
  iVar10 = *(int *)(param_1 + 0x27c);
  if (iVar10 == 0) {
    iVar10 = *(int *)(param_1 + 0x280);
  }
  uVar4 = iVar10 - 1;
  if (uVar4 != *(uint *)(param_1 + 0x278)) {
    *(longlong *)(param_1 + 0x288 + (ulonglong)uVar4 * 8) = param_2;
    *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + 1;
    *(uint *)(param_1 + 0x27c) = uVar4;
  }
  lm_wr_mbx16(param_1,(*(uint *)(param_1 + 0x1c0) & 0xffffff80) * 2 + 0x10088,uVar7);
  lm_wr_mbx32(param_1,(*(uint *)(param_1 + 0x1c0) & 0xffffff80) * 2 + 0x10090,
              *(undefined4 *)(param_1 + 0x1d0));
  return 0;
}



===== lm_ack_intr @ 140012cd0 =====

void lm_ack_intr(longlong param_1)

{
  uint uVar1;
  
  uVar1 = 0x50000;
  if (*(char *)(param_1 + 0x30) != '\x01') {
    uVar1 = 0x10000;
  }
  uVar1 = uVar1 | *(ushort *)(param_1 + 0x20);
  storport_pci_cfg_write_dword(param_1,0x84,uVar1 | 0x40000);
  storport_pci_cfg_write_dword(param_1,0x84,uVar1);
  return;
}



===== lm_disable_intr @ 140012d1c =====

void lm_disable_intr(longlong param_1)

{
  uint uVar1;
  
  uVar1 = storport_pci_cfg_read_dword(param_1,0x84);
  *(undefined1 *)(param_1 + 0x30) = 1;
  storport_pci_cfg_write_dword(param_1,0x84,uVar1 | 0x40000);
  return;
}



===== lm_enable_intr @ 140012d48 =====

void lm_enable_intr(longlong param_1)

{
  uint uVar1;
  
  uVar1 = storport_pci_cfg_read_dword(param_1,0x84);
  *(undefined1 *)(param_1 + 0x30) = 0;
  storport_pci_cfg_write_dword(param_1,0x84,uVar1 & 0xfffbffff);
  return;
}



===== lm_get_interrupt_status @ 140012d74 =====

uint lm_get_interrupt_status(longlong param_1)

{
  short sVar1;
  uint uVar2;
  bool bVar3;
  
  bVar3 = (((*(uint **)(param_1 + 0x18))[1] ^ **(uint **)(param_1 + 0x18)) & 0x1000001) != 0;
  uVar2 = (uint)bVar3;
  if (*(short *)(param_1 + 0x1c6) != **(short **)(param_1 + 0x1d8)) {
    uVar2 = bVar3 | 0x100;
  }
  if (*(short *)(param_1 + 0x3c6) != **(short **)(param_1 + 0x3d8)) {
    uVar2 = uVar2 | 0x10000;
  }
  if ((uVar2 == 0) &&
     (sVar1 = *(short *)(*(longlong *)(param_1 + 0x18) + 0x36), *(short *)(param_1 + 0x20) != sVar1)
     ) {
    *(short *)(param_1 + 0x20) = sVar1;
    lm_ack_intr(param_1);
  }
  return uVar2;
}



===== lm_service_intr @ 140012df0 =====

void lm_service_intr(int *param_1)

{
  uint uVar1;
  
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(*(longlong *)(param_1 + 6) + 0x36);
  uVar1 = lm_get_interrupt_status((longlong)param_1);
  if ((uVar1 >> 0x10 & 1) != 0) {
    lm_service_rx_intr((longlong)param_1);
    if (param_1[0xfa] != param_1[0xfb]) {
      lm_post_buffers((longlong)param_1);
    }
  }
  if ((uVar1 >> 8 & 1) != 0) {
    lm_service_tx_intr((longlong)param_1);
  }
  if ((uVar1 & 1) != 0) {
    lm_service_phy_intr(param_1,'\0');
  }
  lm_ack_intr((longlong)param_1);
  return;
}



===== lm_service_phy_intr @ 140012e64 =====

void lm_service_phy_intr(int *param_1,char param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = **(uint **)(param_1 + 6);
  uVar4 = (*(uint **)(param_1 + 6))[1] ^ uVar1;
  uVar3 = ~uVar1 & uVar4 & 0x1000001;
  uVar1 = uVar4 & uVar1 & 0x1000001;
  if (uVar1 == 0) {
    if (uVar3 == 0) {
      if (param_2 == '\0') {
        return;
      }
      goto LAB_140012eaf;
    }
    bVar2 = 0x8c;
  }
  else {
    bVar2 = 0x88;
    uVar3 = uVar1;
  }
  storport_pci_cfg_write_dword(param_1,bVar2,uVar3);
LAB_140012eaf:
  lm_init_mac_link(param_1);
  return;
}



===== lm_service_rx_intr @ 140012ec0 =====

void lm_service_rx_intr(longlong param_1)

{
  longlong lVar1;
  byte *pbVar2;
  bool bVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  short sVar7;
  
  sVar5 = **(short **)(param_1 + 0x3d8);
  if (((byte)sVar5 & 0xf) == 0xf) {
    sVar5 = sVar5 + 1;
  }
  sVar7 = *(short *)(param_1 + 0x3c6);
  if (sVar7 != sVar5) {
    do {
      iVar4 = *(int *)(param_1 + 0x478);
      if (iVar4 == *(int *)(param_1 + 0x47c)) break;
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x480);
      }
      *(int *)(param_1 + 0x484) = *(int *)(param_1 + 0x484) + -1;
      *(uint *)(param_1 + 0x478) = iVar4 - 1U;
      lVar1 = *(longlong *)(param_1 + 0x488 + (ulonglong)(iVar4 - 1U) * 8);
      if (lVar1 == 0) break;
      *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 1;
      bVar3 = false;
      pbVar2 = *(byte **)(lVar1 + 0x38);
      sVar7 = *(short *)(lVar1 + 0x36);
      *(undefined4 *)(lVar1 + 0x20) = 0;
      sVar5 = *(short *)(pbVar2 + 10);
      *(undefined4 *)(lVar1 + 0x2c) = 0;
      *(short *)(lVar1 + 0x24) = sVar5 + -4;
      if ((*(ushort *)(param_1 + 0x38) != 0) &&
         (((*pbVar2 & 0x40) == 0 ||
          ((*(ushort *)(pbVar2 + 8) & 0xfff) != *(ushort *)(param_1 + 0x38))))) {
        bVar3 = true;
      }
      if ((pbVar2[2] & 0x3e) != 0) {
        *(int *)(param_1 + 0x5a4) = *(int *)(param_1 + 0x5a4) + 1;
        bVar3 = true;
      }
      sVar5 = **(short **)(param_1 + 0x3d8);
      if (((byte)sVar5 & 0xf) == 0xf) {
        sVar5 = sVar5 + 1;
      }
      if (bVar3) {
        iVar4 = *(int *)(param_1 + 0x3ec);
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x3f0);
        }
        uVar6 = iVar4 - 1;
        if (uVar6 != *(uint *)(param_1 + 1000)) {
          *(longlong *)(param_1 + 0x3f8 + (ulonglong)uVar6 * 8) = lVar1;
          *(int *)(param_1 + 0x3f4) = *(int *)(param_1 + 0x3f4) + 1;
          *(uint *)(param_1 + 0x3ec) = uVar6;
        }
        lm_post_buffers(param_1);
      }
      else {
        iVar4 = *(int *)(param_1 + 0x50c);
        if (iVar4 == 0) {
          iVar4 = *(int *)(param_1 + 0x510);
        }
        uVar6 = iVar4 - 1;
        if (uVar6 != *(uint *)(param_1 + 0x508)) {
          *(longlong *)(param_1 + 0x518 + (ulonglong)uVar6 * 8) = lVar1;
          *(int *)(param_1 + 0x514) = *(int *)(param_1 + 0x514) + 1;
          *(uint *)(param_1 + 0x50c) = uVar6;
        }
      }
    } while (sVar7 != sVar5);
  }
  *(short *)(param_1 + 0x3c6) = sVar7;
  return;
}



===== lm_service_tx_intr @ 14001304c =====

void lm_service_tx_intr(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  short sVar6;
  
  sVar4 = **(short **)(param_1 + 0x1d8);
  if (((byte)sVar4 & 0xf) == 0xf) {
    sVar4 = sVar4 + 1;
  }
  sVar6 = *(short *)(param_1 + 0x1c6);
  if (sVar6 != sVar4) {
    do {
      iVar3 = *(int *)(param_1 + 0x278);
      if (iVar3 == *(int *)(param_1 + 0x27c)) break;
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_1 + 0x280);
      }
      *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + -1;
      *(uint *)(param_1 + 0x278) = iVar3 - 1U;
      lVar2 = *(longlong *)(param_1 + 0x288 + (ulonglong)(iVar3 - 1U) * 8);
      if (lVar2 == 0) break;
      *(undefined4 *)(lVar2 + 0x20) = 0;
      sVar6 = *(short *)(lVar2 + 0x2e);
      piVar1 = (int *)((ulonglong)*(uint *)(param_1 + 0x1a8) * 0x1f0 + 0x1e0 + param_1);
      *piVar1 = *piVar1 + (uint)*(ushort *)(lVar2 + 0x30);
      sVar4 = **(short **)(param_1 + 0x1d8);
      if (((byte)sVar4 & 0xf) == 0xf) {
        sVar4 = sVar4 + 1;
      }
      iVar3 = *(int *)(param_1 + 0x30c);
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_1 + 0x310);
      }
      uVar5 = iVar3 - 1;
      if (uVar5 != *(uint *)(param_1 + 0x308)) {
        *(longlong *)(param_1 + 0x318 + (ulonglong)uVar5 * 8) = lVar2;
        *(int *)(param_1 + 0x314) = *(int *)(param_1 + 0x314) + 1;
        *(uint *)(param_1 + 0x30c) = uVar5;
      }
    } while (sVar6 != sVar4);
  }
  *(short *)(param_1 + 0x1c6) = sVar6;
  return;
}



===== bnx2_ethernetif_bringup @ 140013140 =====

ulonglong bnx2_ethernetif_bringup(longlong param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x28);
  iVar5 = 0;
  uVar4 = 9;
  if (0 < *(int *)(param_1 + 0xe8)) {
    uVar4 = 0xb;
    puVar7 = (undefined4 *)(param_1 + 0xec);
    puVar6 = (undefined4 *)(lVar2 + 0xa6);
    do {
      iVar5 = iVar5 + 1;
      *puVar6 = *puVar7;
      puVar1 = puVar7 + 1;
      puVar7 = (undefined4 *)((longlong)puVar7 + 6);
      *(undefined2 *)(puVar6 + 1) = *(undefined2 *)puVar1;
      puVar6 = puVar6 + 2;
    } while (iVar5 < *(int *)(param_1 + 0xe8));
    *(undefined1 *)(lVar2 + 0xa4) = *(undefined1 *)(param_1 + 0xe8);
  }
  lm_set_rx_mask(lVar2,uVar4);
  uVar3 = lm_enable_intr(lVar2);
  return uVar3 & 0xffffffffffffff00;
}



===== bnx2_ethernetif_init @ 1400131c0 =====

undefined8 bnx2_ethernetif_init(longlong param_1)

{
  int *_Dst;
  uint uVar1;
  undefined8 uVar2;
  
  _Dst = *(int **)(param_1 + 0x28);
  memset(_Dst + 0x6a,0,0x408);
  memset(_Dst,0,0x58);
  uVar2 = lm_get_dev_info((longlong)_Dst);
  if (((int)uVar2 == 0) && (uVar2 = lm_init_resc((longlong)_Dst), (int)uVar2 == 0)) {
    *(undefined1 *)((longlong)_Dst + 0x3a) = 1;
    uVar1 = storport_pci_cfg_read_dword(_Dst,4);
    storport_pci_cfg_write_dword(_Dst,4,uVar1 | 0x400);
    lm_reset_setup((longlong)_Dst);
    lm_init_phy(_Dst,_Dst[0x27],(ulonglong)(uint)_Dst[0x26],(char)_Dst[0x28]);
    lm_reset_run(_Dst);
    lm_disable_intr((longlong)_Dst);
    *(undefined2 *)(param_1 + 0x3b) = 0x6e62;
    *(code **)(param_1 + 0x18) = bnx1_protocol_transmit;
    *(code **)(param_1 + 0x20) = bnx1_transmit;
    return 0x140011300;
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),0xf5);
}



===== bnx2_ethernetif_shutdown @ 140013290 =====

undefined1 bnx2_ethernetif_shutdown(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  lm_disable_intr(lVar1);
  lm_abort(lVar1,1);
  return 0;
}



===== nx2_get_netif_intf @ 1400132b8 =====

void nx2_get_netif_intf(longlong param_1)

{
  *(code **)(param_1 + 0x60) = bnx2_ethernetif_init;
  *(code **)(param_1 + 0x70) = bnx2_ethernetif_shutdown;
  *(code **)(param_1 + 0x68) = bnx2_ethernetif_bringup;
  return;
}



===== bnx2_dir_get_iscsi_block @ 1400132e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 bnx2_dir_get_iscsi_block(longlong param_1,longlong param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  undefined1 auStack_148 [32];
  undefined1 local_128 [8];
  int local_120;
  undefined1 local_118 [4];
  uint local_114 [59];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_148;
  lm_get_dev_info(param_1);
  cVar1 = *(char *)(param_1 + 0x81);
  lm_nvram_read_block(param_1,0x14,(longlong)local_118,0xec);
  iVar2 = 0;
  puVar3 = local_114;
  while (((*puVar3 & 0xfffffc) == 0 ||
         ((*puVar3 & 0xf0000001) != (-(uint)(cVar1 != '\0') & 0x20000000) + 0xc0000000))) {
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 3;
    if (0xf < iVar2) {
      return 1;
    }
  }
  lm_nvram_read_block(param_1,iVar2 * 0xc + 0x14,(longlong)local_128,0xc);
  lm_nvram_read_block(param_1,local_120,param_2,param_3);
  return 0;
}



===== lm_nvram_init @ 1400133bc =====

void lm_nvram_init(longlong param_1)

{
  bool bVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  *(undefined1 *)(param_1 + 0x82) = 1;
  *(undefined2 *)(param_1 + 0x84) = 0x100;
  bVar1 = false;
  if ((*(uint *)(param_1 + 0x74) & 0xffff0000) != 0x57090000) {
    uVar2 = lm_reg_read_ind(param_1,0x6414);
    uVar4 = 0x3c000000;
    if ((uVar2 >> 0x1e & 1) == 0) {
      bVar1 = true;
      uVar4 = 0x3c000000;
      if ((uVar2 >> 0x17 & 1) == 0) {
        uVar4 = 0x3000003;
      }
    }
    uVar5 = 0;
    puVar6 = &nvm_cfg_table;
    do {
      if ((*puVar6 & uVar4) == (uVar4 & uVar2)) {
        lVar3 = (longlong)(int)uVar5;
        *(undefined *)(param_1 + 0x82) = (&DAT_1400317e6)[lVar3 * 0x18];
        *(undefined2 *)(param_1 + 0x84) = *(undefined2 *)(&DAT_1400317e4 + lVar3 * 0x18);
        if (bVar1) {
          lm_reg_wr_ind(param_1,0x6414,*(undefined4 *)(&DAT_1400317d4 + lVar3 * 0x18));
          lm_reg_wr_ind(param_1,0x6418,*(undefined4 *)(&DAT_1400317d8 + lVar3 * 0x18));
          lm_reg_wr_ind(param_1,0x641c,*(undefined4 *)(&DAT_1400317dc + lVar3 * 0x18));
          lm_reg_wr_ind(param_1,0x6428,*(undefined4 *)(&DAT_1400317e0 + lVar3 * 0x18));
          return;
        }
        return;
      }
      uVar5 = uVar5 + 1;
      puVar6 = puVar6 + 6;
    } while (uVar5 < 0x10);
  }
  return;
}



===== lm_nvram_read_block @ 1400134c8 =====

undefined8 lm_nvram_read_block(longlong param_1,int param_2,longlong param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (param_4 != 0) {
    do {
      uVar1 = lm_nvram_read_dword(param_1,uVar2 + param_2);
      uVar3 = uVar2 + 4;
      *(undefined4 *)(param_3 + (ulonglong)(uVar2 >> 2) * 4) = uVar1;
      uVar2 = uVar3;
    } while (uVar3 < param_4);
  }
  return 0;
}



===== lm_nvram_read_dword @ 140013530 =====

undefined4 lm_nvram_read_dword(longlong param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if ((*(char *)(param_1 + 0x82) == '\x01') && (*(short *)(param_1 + 0x84) == 0x108)) {
    param_2 = param_2 + (param_2 / 0x108) * 0xf8;
  }
  lm_reg_wr_ind(param_1,0x6420,2);
  uVar5 = 0;
  uVar4 = 0;
  do {
    uVar1 = lm_reg_read_ind(param_1,0x6420);
    if ((uVar1 >> 9 & 1) != 0) break;
    mm_stall(500);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 10000);
  lm_reg_wr_ind(param_1,0x6424,3);
  lm_reg_wr_ind(param_1,0x640c,param_2);
  lm_reg_wr_ind(param_1,0x6400,0x198);
  iVar6 = 0;
  do {
    uVar3 = lm_reg_read_ind(param_1,0x6400);
    if ((uVar3 & 8) != 0) break;
    mm_stall(5);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 10000);
  uVar2 = lm_reg_read_ind(param_1,0x6410);
  lm_reg_wr_ind(param_1,0x6424,0);
  lm_reg_wr_ind(param_1,0x6420,0x20);
  do {
    uVar4 = lm_reg_read_ind(param_1,0x6420);
    if ((uVar4 >> 9 & 1) == 0) {
      return uVar2;
    }
    mm_stall(5);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 1000);
  return uVar2;
}



===== get_5706_serdes_link @ 14001367c =====

undefined8 get_5706_serdes_link(longlong param_1,uint *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  *param_2 = 3;
  lm_mwrite(param_1,0x1c,0x7000);
  uVar1 = lm_mread(param_1,0x1c);
  lm_get_mii_link_status(param_1);
  uVar2 = lm_get_mii_link_status(param_1);
  uVar3 = 4;
  if ((uVar2 & 4) == 0) {
    uVar3 = 5;
  }
  else {
    *param_2 = *param_2 | 0x300;
  }
  if ((uVar1 & 8) == 0) {
    *param_2 = *param_2 | 0x10000;
  }
  return uVar3;
}



===== get_5709_serdes_link @ 1400136f8 =====

undefined8 get_5709_serdes_link(longlong param_1,uint *param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  
  *param_2 = 3;
  lm_mwrite(param_1,0x1f,0x8120);
  lm_mread(param_1,0x1b);
  uVar1 = lm_mread(param_1,0x1b);
  if ((uVar1 & 4) == 0) {
    uVar2 = 5;
  }
  else {
    if (*(char *)(param_1 + 0xa0) == '\x01') {
      uVar4 = 0x400;
      if ((uVar1 & 0x1f00) != 0x300) {
        uVar4 = 0x300;
      }
      uVar3 = (uint)uVar1 << 0xd;
    }
    else {
      lm_mwrite(param_1,0x1f,0xffe0);
      uVar1 = lm_mread(param_1,0x10);
      uVar4 = 0x400;
      uVar3 = (uint)uVar1 << 8;
      if ((uVar1 & 0x20) == 0) {
        uVar4 = 0x300;
      }
    }
    uVar2 = 4;
    *param_2 = ~uVar3 & 0x10000 | uVar4 | 3;
  }
  return uVar2;
}



===== get_copper_link @ 1400137c8 =====

undefined8 get_copper_link(longlong param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  lm_mread(param_1,1);
  uVar1 = lm_mread(param_1,1);
  uVar4 = 4;
  if ((uVar1 & 4) == 0) {
    uVar4 = 5;
LAB_14001386f:
    uVar3 = 0;
    uVar2 = 0;
  }
  else {
    uVar1 = lm_mread(param_1,0x19);
    uVar3 = uVar1 & 0x700;
    if ((uVar3 - 0x100 & 0xfffffeff) == 0) {
      uVar2 = 0x100;
      bVar5 = uVar3 == 0x100;
    }
    else if ((uVar3 - 0x300 & 0xfffffdff) == 0) {
      uVar2 = 0x200;
      bVar5 = uVar3 == 0x300;
    }
    else {
      if ((uVar3 - 0x600 & 0xfffffeff) != 0) goto LAB_14001386f;
      uVar2 = 0x300;
      bVar5 = uVar3 == 0x600;
    }
    uVar3 = 0;
    if (bVar5) {
      uVar3 = 0x10000;
    }
  }
  *param_2 = uVar2 | uVar3 | 2;
  return uVar4;
}



===== init_5708_serdes @ 14001388c =====

undefined8 init_5708_serdes(undefined4 *param_1,char param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  undefined8 uVar4;
  ushort uVar5;
  int iVar6;
  
  if ((param_1[0x1d] & 0xffff0000) == 0x57090000) {
    return 0;
  }
  iVar6 = 0;
  uVar5 = 0;
  lm_mwrite((longlong)param_1,0x1f,2);
  lm_mwrite((longlong)param_1,0x10,1);
  if ((((param_1[0x1d] & 0xfffffff0) + 0xa8f80000 & 0xffffefef) == 0) &&
     ((param_1[0x1d] & 0xfffffff0) != 0x57080010)) {
    lm_mwrite((longlong)param_1,0x1f,5);
    uVar1 = lm_mread((longlong)param_1,0x15);
    lm_mwrite((longlong)param_1,0x15,uVar1 & 0xffcf);
  }
  if (((param_1[0x1f] & 0x40) != 0) &&
     (uVar1 = lm_reg_read_ind(param_1,param_1[0x12] + 0x58), uVar1 != 0)) {
    lm_mwrite((longlong)param_1,0x1f,5);
    lm_mwrite((longlong)param_1,0x17,uVar1);
  }
  lm_mwrite((longlong)param_1,0x1f,0);
  uVar2 = lm_mread((longlong)param_1,0x10);
  uVar1 = uVar2 & 0xfffb | 0x11;
  if ((param_1[0x1f] & 0x40) == 0) {
    uVar1 = uVar2 | 0x15;
  }
  lm_mwrite((longlong)param_1,0x10,uVar1);
  uVar1 = lm_mread((longlong)param_1,0x11);
  lm_mwrite((longlong)param_1,0x11,uVar1 | 1);
  uVar1 = lm_mread((longlong)param_1,0xb);
  uVar2 = uVar1 & 1;
  if ((param_1[0x1f] & 0x20) == 0) {
    if (uVar2 != 0) {
      uVar5 = 1;
      uVar1 = uVar1 & 0xfffe;
    }
  }
  else {
    if (uVar2 == 0) {
      uVar1 = uVar1 | 1;
    }
    uVar5 = uVar2 ^ 1;
  }
  lm_mwrite((longlong)param_1,0xb,uVar1);
  uVar1 = 0xc60;
  if (param_2 == '\x03') {
    uVar1 = 0x1e0;
  }
  uVar2 = lm_mread((longlong)param_1,4);
  if (((uVar2 & 0xf00f) != 0) || ((uVar2 & uVar1) != uVar1)) {
    lm_mwrite((longlong)param_1,4,uVar1);
    uVar5 = 1;
  }
  if ((param_1[0x27] & 0xff00) == 0x300) {
    uVar5 = 0x140;
  }
  else if ((param_1[0x27] & 0xff00) == 0x400) {
    uVar5 = 0x120;
  }
  else {
    if (uVar5 == 0) goto LAB_140013ab2;
    uVar5 = 0x1200;
  }
  lm_mwrite((longlong)param_1,0,uVar5);
LAB_140013ab2:
  uVar3 = lm_reg_read_ind(param_1,0x1400);
  lm_reg_wr_ind(param_1,0x1400,uVar3 & 0xfffff7ef);
  param_1[1] = param_1[1] & 0xfffe00ff | param_1[0x27] & 0xff00;
  do {
    uVar4 = lm_phy_cable_attached((longlong)param_1);
    if ((int)uVar4 == 1) break;
    mm_stall(100);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2000);
  uVar4 = lm_poll_link_status((longlong)param_1);
  *param_1 = (int)uVar4;
  return 0;
}



===== init_5709_serdes @ 140013b38 =====

undefined8 init_5709_serdes(undefined4 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = lm_reg_read_ind(param_1,0x1400);
  lm_reg_wr_ind(param_1,0x1400,uVar1 & 0xfffff7ef);
  param_1[1] = param_1[0x27] & 0xff00 | param_1[1] & 0xfffe00ff;
  uVar2 = lm_poll_link_status((longlong)param_1);
  *param_1 = (int)uVar2;
  return 0;
}



===== lm_get_link @ 140013b8c =====

int lm_get_link(longlong param_1,uint *param_2)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  int local_res8;
  
  cVar1 = *(char *)(param_1 + 0x80);
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      uVar5 = get_5706_serdes_link(param_1,param_2);
      iVar4 = (int)uVar5;
      if (iVar4 == 4) {
        return 4;
      }
      if (*(short *)(param_1 + 0x5e) == 0x103c) {
        return iVar4;
      }
      uVar5 = lm_serdes_fallback(param_1);
      if ((int)uVar5 == 1) {
        uVar5 = get_5706_serdes_link(param_1,param_2);
        return (int)uVar5;
      }
      return iVar4;
    }
    if (cVar1 == '\x02') {
      lm_mread(param_1,1);
      uVar2 = lm_mread(param_1,1);
      if ((uVar2 & 4) == 0) {
        iVar4 = 5;
        uVar3 = 3;
      }
      else {
        lm_mread(param_1,0);
        lm_mwrite(param_1,0x1f,0);
        uVar2 = lm_mread(param_1,0x14);
        uVar2 = uVar2 & 0x18;
        if (uVar2 == 8) {
          uVar3 = 0x203;
        }
        else if (uVar2 == 0x10) {
          uVar3 = 0x303;
        }
        else {
          uVar3 = 0x403;
          if (uVar2 != 0x18) {
            uVar3 = 0x103;
          }
        }
        iVar4 = 4;
      }
      *param_2 = uVar3;
      return iVar4;
    }
    if (cVar1 != '\x03') {
      if (cVar1 == '\x04') {
        uVar5 = get_5709_serdes_link(param_1,param_2);
        return (int)uVar5;
      }
      if (cVar1 == '\x05') {
        uVar5 = lm_get_remote_phy_link(param_1,param_2);
        return (int)uVar5;
      }
      return local_res8;
    }
  }
  uVar5 = get_copper_link(param_1,param_2);
  return (int)uVar5;
}



===== lm_get_mii_link_status @ 140013cc4 =====

ushort lm_get_mii_link_status(longlong param_1)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  cVar1 = *(char *)(param_1 + 0x80);
  uVar2 = 0;
  if (cVar1 == '\x01') {
    uVar4 = lm_reg_read_ind(param_1,0x1404);
    if ((uVar4 >> 0xb & 1) != 0) {
      lm_mwrite(param_1,0x1c,0x6800);
      uVar3 = lm_mread(param_1,0x1c);
      if ((uVar3 & 2) == 0) {
        uVar2 = 4;
      }
    }
  }
  else if (cVar1 == '\x04') {
    uVar4 = lm_reg_read_ind(param_1,0x1404);
    uVar2 = (ushort)(uVar4 >> 9) & 4;
  }
  else if (cVar1 == '\x05') {
    uVar5 = lm_get_remote_phy_link(param_1,(uint *)0x0);
    if ((int)uVar5 == 4) {
      uVar2 = 4;
    }
  }
  else {
    uVar2 = lm_mread(param_1,1);
  }
  return uVar2;
}



===== lm_get_remote_phy_link @ 140013d6c =====

undefined8 lm_get_remote_phy_link(longlong param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  uVar1 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x48) + 0xc);
  if ((uVar1 & 1) == 0) {
    uVar2 = 0;
    uVar3 = 0;
    uVar4 = 5;
  }
  else {
    uVar2 = uVar1 & 0x1e;
    uVar4 = 4;
    if ((uVar2 - 2 & 0xfffffffd) == 0) {
      uVar3 = 0x100;
      bVar5 = uVar2 == 2;
    }
    else if ((uVar2 - 6 & 0xfffffffb) == 0) {
      uVar3 = 0x200;
      bVar5 = uVar2 == 6;
    }
    else if ((uVar2 - 0xc & 0xfffffffd) == 0) {
      uVar3 = 0x300;
      bVar5 = uVar2 == 0xc;
    }
    else {
      if ((uVar2 - 0x10 & 0xfffffffd) != 0) {
        uVar3 = 0;
        uVar2 = 0;
        goto LAB_140013e06;
      }
      uVar3 = 0x400;
      bVar5 = uVar2 == 0x10;
    }
    uVar2 = 0;
    if (bVar5) {
      uVar2 = 0x10000;
    }
  }
LAB_140013e06:
  if (param_2 != (uint *)0x0) {
    *param_2 = ((uVar1 & 0x100000) != 0) + 2 | uVar3 | uVar2;
  }
  return uVar4;
}



===== lm_init_mac_link @ 140013e2c =====

undefined8 lm_init_mac_link(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint local_res8 [2];
  
  lm_reg_wr_ind(param_1,0x1408,0);
  if (((char)param_1[0x20] == '\x01') &&
     (uVar1 = lm_reg_read_ind(param_1,0x1404), (uVar1 >> 0x17 & 1) != 0)) {
    lm_phy_do_parallel_detect((longlong)param_1);
  }
  iVar2 = lm_get_link((longlong)param_1,local_res8);
  if ((*(byte *)((longlong)param_1 + 0x4e) & 1) != 0) {
    if (((iVar2 == 5) && (*param_1 == 4)) && (uVar4 = 0, (short)param_1[0x14] != 0)) {
      do {
        iVar3 = lm_get_link((longlong)param_1,local_res8);
        if (iVar3 == 4) {
          iVar2 = 4;
          break;
        }
        mm_stall(1000);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(ushort *)(param_1 + 0x14));
    }
    *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) & 0xfffe;
  }
  lm_reg_wr_ind(param_1,0x14c4,0x2620);
  if (iVar2 == 4) {
    if (((local_res8[0] & 0xff00) == 0x300) && ((local_res8[0] >> 0x10 & 1) != 0)) {
      lm_reg_wr_ind(param_1,0x14c4,0x26ff);
    }
    uVar1 = set_flow_control((longlong)param_1,param_1[0x26]);
    param_1[4] = uVar1;
  }
  uVar1 = lm_reg_read_ind(param_1,0x1400);
  if (iVar2 == 4) {
    uVar6 = local_res8[0] & 0xff00;
    if (uVar6 == 0x100) {
      uVar5 = 4;
      if ((param_1[0x1d] & 0xffff0000U) != 0x57060000) {
        uVar5 = 0xc;
      }
    }
    else {
      uVar5 = 8;
      if (uVar6 == 0x200) {
        uVar5 = 4;
      }
    }
    uVar5 = uVar5 | uVar1 & 0xfffff7f3;
    uVar1 = uVar5 | 0x20;
    if (uVar6 != 0x400) {
      uVar1 = uVar5;
    }
  }
  else {
    uVar1 = uVar1 & 0xfffff7f3 | 8;
  }
  uVar6 = uVar1 & 0xfffffffd | 2;
  if ((local_res8[0] & 0x10000) == 0) {
    uVar6 = uVar1 & 0xfffffffd;
  }
  lm_reg_wr_ind(param_1,0x1400,uVar6);
  lm_reg_wr_ind(param_1,0x1404,0x1000);
  uVar6 = lm_reg_read_ind(param_1,0x680c);
  uVar1 = uVar6 & 0xfefffffe | 0x1000001;
  if (*(char *)((longlong)param_1 + 0xa2) != '\x02') {
    uVar1 = uVar6 & 0xfefffffe;
  }
  lm_reg_wr_ind(param_1,0x680c,uVar1);
  param_1[1] = local_res8[0];
  *param_1 = iVar2;
  if ((char)param_1[0x20] != '\x05') {
    lm_update_shmem_link_status(param_1);
  }
  return 0;
}



===== lm_init_phy @ 140014028 =====

ulonglong lm_init_phy(undefined4 *param_1,uint param_2,undefined8 param_3,char param_4)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  if (*(char *)((longlong)param_1 + 0x3a) == '\0') {
    lm_mwrite((longlong)param_1,0,0x8000);
    iVar8 = 0;
    do {
      uVar2 = lm_mread((longlong)param_1,0);
      if ((uVar2 & 0x8000) == 0) break;
      mm_stall(5);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 1000);
  }
  uVar11 = param_2 & 0xff;
  if (uVar11 == 3) {
    cVar1 = *(char *)(param_1 + 0x20);
    if (cVar1 == '\x01') {
      lm_reg_wr_ind(param_1,0x8bc,0x300);
    }
    else {
      if (cVar1 == '\x02') {
        uVar4 = init_5708_serdes(param_1,(char)param_2);
        return uVar4;
      }
      if (cVar1 == '\x04') {
        uVar4 = init_5709_serdes(param_1);
        return uVar4;
      }
      if (cVar1 == '\x05') {
        uVar4 = lm_init_remote_phy(param_1,param_2);
        return uVar4;
      }
    }
  }
  else {
    lm_mwrite((longlong)param_1,0x18,0x7007);
    uVar2 = lm_mread((longlong)param_1,0x18);
    lm_mwrite((longlong)param_1,0x18,uVar2 | 0x8010);
    lm_phy_config_5464((longlong)param_1);
    if (((param_1[0x1d] & 0xfffffff0) + 0xa8f70000 & 0xffffefef) == 0) {
      lm_mwrite((longlong)param_1,0x17,0xf08);
      uVar2 = lm_mread((longlong)param_1,0x15);
      lm_mwrite((longlong)param_1,0x15,uVar2 & 0xfeff);
    }
  }
  bVar13 = false;
  uVar12 = param_2 & 0xff00;
  uVar10 = param_2 & 0x10000;
  uVar2 = 0x100;
  if (uVar12 == 0x100) {
    lm_mwrite((longlong)param_1,9,0);
    uVar2 = 0xc21;
    if (uVar11 == 3) {
      uVar2 = 0x1a1;
    }
    uVar6 = uVar2 | 0x40;
    if (uVar10 != 0) {
      uVar6 = uVar2;
    }
    lm_mwrite((longlong)param_1,4,uVar6);
    if (param_4 != '\0') {
LAB_14001437d:
      uVar9 = 0;
      bVar13 = true;
      goto LAB_14001439a;
    }
    if (uVar10 == 0) {
      uVar2 = 0x100;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if (uVar12 != 0x200) {
      if (uVar12 == 0x300) {
        if (uVar11 == 3) {
          uVar7 = 0;
          uVar6 = (-(ushort)(uVar10 != 0) & 0xffe0) + 0x1e0;
        }
        else {
          uVar7 = 9;
          uVar2 = (-(ushort)(uVar10 != 0) & 0xfe00) + 0x300;
          uVar6 = 0xde1;
        }
        lm_mwrite((longlong)param_1,4,uVar6);
        lm_mwrite((longlong)param_1,uVar7,uVar2);
        uVar9 = ~-(uint)(param_4 != '\0') & 3;
        bVar13 = param_4 != '\0';
      }
      else {
        uVar2 = lm_mread((longlong)param_1,4);
        if (uVar11 == 3) {
          bVar13 = false;
          if ((uVar2 & 0x1e0) != 0x1e0) {
            lm_mwrite((longlong)param_1,4,0x1e0);
            bVar13 = true;
          }
        }
        else {
          bVar13 = (uVar2 & 0xde1) != 0xde1;
          if (bVar13) {
            lm_mwrite((longlong)param_1,4,0xde1);
          }
          uVar2 = lm_mread((longlong)param_1,9);
          if ((uVar2 & 0x300) != 0x300) {
            lm_mwrite((longlong)param_1,9,0x300);
            bVar13 = true;
          }
        }
        uVar9 = 0;
        uVar12 = 0;
      }
      goto LAB_14001439a;
    }
    lm_mwrite((longlong)param_1,9,0);
    uVar2 = 0xce1;
    if (uVar11 == 3) {
      uVar2 = 0x1e1;
    }
    uVar6 = uVar2 | 0x100;
    if (uVar10 != 0) {
      uVar6 = uVar2;
    }
    lm_mwrite((longlong)param_1,4,uVar6);
    if (param_4 != '\0') goto LAB_14001437d;
    if (uVar10 == 0) {
      uVar2 = 0x2100;
    }
    else {
      uVar2 = 0x2000;
    }
  }
  uVar9 = 0;
  lm_mwrite((longlong)param_1,0,uVar2);
LAB_14001439a:
  uVar3 = lm_reg_read_ind(param_1,0x1400);
  lm_reg_wr_ind(param_1,0x1400,uVar3 & 0xffffffef);
  if (bVar13) {
    lm_mwrite((longlong)param_1,0,0x1200);
  }
  uVar6 = 0x1c;
  uVar2 = 0xec85;
  if (uVar11 != 3) {
    uVar2 = 0;
    uVar6 = 0x10;
  }
  lm_mwrite((longlong)param_1,uVar6,uVar2);
  lm_mwrite((longlong)param_1,0x18,0x400);
  param_1[1] = param_1[1] & 0xfffe00ff | uVar12 | uVar10;
  uVar5 = lm_poll_link_status((longlong)param_1);
  *param_1 = (int)uVar5;
  return (ulonglong)uVar9;
}



===== lm_init_remote_phy @ 140014450 =====

undefined8 lm_init_remote_phy(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  uint local_res10;
  
  lm_reg_wr_ind(param_1,param_1[0x12] + 0x364,0x35450001);
  bVar8 = false;
  uVar6 = param_2 & 0xff00;
  uVar5 = param_2 & 0x10000;
  uVar1 = lm_reg_read_ind(param_1,param_1[0x12] + 0xc);
  uVar7 = uVar1 & 0x100000;
  if (uVar7 == 0) {
    uVar3 = lm_reg_read_ind(param_1,param_1[0x12] + 0x378);
    if (uVar6 == 0) {
      bVar8 = (uVar3 & 0x142f) != 0x142f;
      if (bVar8) {
        local_res10 = 0x142f;
      }
    }
    else {
      bVar8 = true;
      if (uVar6 == 0x100) {
        local_res10 = 2 - (uVar5 != 0);
      }
      else if (uVar6 == 0x200) {
        local_res10 = (-(uint)(uVar5 != 0) & 0xfffffffc) + 8;
      }
    }
    uVar3 = local_res10 | 0x7000;
  }
  else {
    uVar2 = lm_reg_read_ind(param_1,param_1[0x12] + 0x374);
    uVar3 = 0x14e0;
    if ((uVar6 == 0) && ((uVar2 & 0x14e0) == 0x14e0)) {
      uVar3 = local_res10;
    }
    else {
      bVar8 = true;
    }
  }
  if (bVar8) {
    uVar2 = uVar3 | 0x800;
    if (uVar7 != 0) {
      uVar2 = uVar3;
    }
    lm_reg_wr_ind(param_1,(-(uint)(uVar7 != 0) & 0xfffffffc) + 0x378 + param_1[0x12],uVar2);
    lm_reg_wr_ind(param_1,param_1[0x12] + 0x14,uVar2);
    lm_reg_wr_ind(param_1,param_1[0x12] + 0xc,uVar1 & 0xfffffffe);
    fw_cmd_sync((longlong)param_1,0x10000000);
  }
  uVar1 = lm_reg_read_ind(param_1,0x1400);
  lm_reg_wr_ind(param_1,0x1400,uVar1 & 0xffffffef);
  param_1[1] = param_1[1] & 0xfffe00ff | uVar6 | uVar5;
  uVar4 = lm_poll_link_status((longlong)param_1);
  *param_1 = (int)uVar4;
  return 0;
}



===== lm_mread @ 1400145f0 =====

undefined2 lm_mread(longlong param_1,ushort param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  
  lm_reg_wr_ind(param_1,0x14ac,((*(ushort *)(param_1 + 0x70) | 0x340) << 5 | (uint)param_2) << 0x10)
  ;
  iVar4 = 0;
  do {
    mm_stall(10);
    uVar2 = lm_reg_read_ind(param_1,0x14ac);
    if ((uVar2 >> 0x1d & 1) == 0) {
      mm_stall(5);
      uVar1 = lm_reg_read_ind(param_1,0x14ac);
      uVar2 = (uint)uVar1;
      break;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 50000);
  uVar3 = 0;
  if ((uVar2 >> 0x1d & 1) == 0) {
    uVar3 = (short)uVar2;
  }
  return uVar3;
}



===== lm_mwrite @ 140014688 =====

bool lm_mwrite(longlong param_1,ushort param_2,ushort param_3)

{
  uint uVar1;
  uint uVar2;
  
  lm_reg_wr_ind(param_1,0x14ac,
                (uint)param_3 | ((*(ushort *)(param_1 + 0x70) | 800) << 5 | (uint)param_2) << 0x10);
  uVar2 = 0;
  do {
    mm_stall(10);
    uVar1 = lm_reg_read_ind(param_1,0x14ac);
    if ((uVar1 & 0x20000000) == 0) {
      mm_stall(5);
      break;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 50000);
  return (uVar1 & 0x20000000) != 0;
}



===== lm_phy_cable_attached @ 140014724 =====

undefined8 lm_phy_cable_attached(longlong param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x80);
  if (cVar1 == '\x02') {
    lm_mwrite(param_1,0x1f,0);
    iVar3 = 0;
    do {
      uVar2 = lm_mread(param_1,0x16);
      if ((uVar2 & 0x200) != 0) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 5);
  }
  else {
    if ((cVar1 == '\x04') || (cVar1 == '\x05')) {
      return 1;
    }
    lm_mwrite(param_1,0x1c,0x7c00);
    iVar3 = 0;
    do {
      uVar2 = lm_mread(param_1,0x1c);
      if ((uVar2 & 0x30) != 0) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 5);
  }
  return 0;
}



===== lm_phy_config_5464 @ 1400147b4 =====

void lm_phy_config_5464(longlong param_1)

{
  if (*(byte *)(param_1 + 0x80) < 2) {
    lm_mwrite(param_1,0x18,0xc00);
    lm_mwrite(param_1,0x17,10);
    lm_mwrite(param_1,0x15,0x310b);
    lm_mwrite(param_1,0x17,0x201f);
    lm_mwrite(param_1,0x15,0x9506);
    lm_mwrite(param_1,0x17,0x401f);
    lm_mwrite(param_1,0x15,0x14e2);
    lm_mwrite(param_1,0x18,0x400);
  }
  return;
}



===== lm_phy_do_parallel_detect @ 140014864 =====

void lm_phy_do_parallel_detect(longlong param_1)

{
  ushort uVar1;
  
  if (*(short *)(param_1 + 0x14) != 0) {
    lm_mwrite(param_1,0x17,0xf01);
    lm_mread(param_1,0x15);
    uVar1 = lm_mread(param_1,0x15);
    if ((uVar1 & 0x20) != 0) {
      lm_mwrite(param_1,0,0x1200);
      lm_mwrite(param_1,0x17,0xf02);
      uVar1 = lm_mread(param_1,0x15);
      lm_mwrite(param_1,0x15,uVar1 | 0x20);
      *(undefined2 *)(param_1 + 0x14) = 0;
    }
  }
  return;
}



===== lm_poll_link_status @ 1400148f0 =====

undefined8 lm_poll_link_status(longlong param_1)

{
  ushort uVar1;
  undefined8 uVar2;
  ushort uVar3;
  
  uVar2 = lm_phy_cable_attached(param_1);
  if ((int)uVar2 == 1) {
    for (uVar3 = 0; uVar3 < *(ushort *)(param_1 + 0x50); uVar3 = uVar3 + 1) {
      uVar1 = lm_get_mii_link_status(param_1);
      if ((uVar1 & 4) != 0) {
        return 4;
      }
      mm_stall(1000);
      if ((*(char *)(param_1 + 0x80) == '\x01') && (500 < *(ushort *)(param_1 + 0x50))) {
        lm_mwrite(param_1,0x17,0xf01);
        lm_mread(param_1,0x15);
        uVar1 = lm_mread(param_1,0x15);
        if ((uVar1 & 0x20) == 0) {
          return 5;
        }
      }
    }
  }
  return 5;
}



===== lm_serdes_fallback @ 1400149a0 =====

undefined8 lm_serdes_fallback(longlong param_1)

{
  ushort uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (((*(short *)(param_1 + 0x14) == 0) &&
      (uVar3 = lm_phy_cable_attached(param_1), (int)uVar3 != 0)) &&
     ((*(uint *)(param_1 + 0x9c) & 0xff00) == 0)) {
    lm_mwrite(param_1,0x17,0xf01);
    lm_mread(param_1,0x15);
    uVar1 = lm_mread(param_1,0x15);
    if ((uVar1 & 0x20) == 0) {
      lm_mwrite(param_1,0,0x140);
      lm_mwrite(param_1,0x17,0xf02);
      uVar1 = lm_mread(param_1,0x15);
      lm_mwrite(param_1,0x15,uVar1 & 0xffdf);
      uVar2 = lm_reg_read_ind(param_1,0x1408);
      lm_reg_wr_ind(param_1,0x1408,uVar2 | 0x800000);
      *(undefined2 *)(param_1 + 0x14) = 1;
      return 1;
    }
  }
  return 0;
}



===== set_flow_control @ 140014a7c =====

uint set_flow_control(longlong param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  
  uVar4 = 0x80;
  uVar5 = 0x100;
  if ((*(uint *)(param_1 + 0x9c) & 0xff) != 3) {
    uVar4 = 0x400;
    uVar5 = 0x800;
  }
  uVar1 = lm_mread(param_1,4);
  uVar2 = lm_mread(param_1,5);
  uVar6 = 0;
  if ((int)param_2 < 0) {
    param_2 = uVar6;
    if ((uVar1 & uVar4) == 0) {
      if (((uVar5 & uVar1) != 0) && ((uVar2 & uVar5) != 0 && (uVar2 & uVar4) != 0)) {
        param_2 = 2;
      }
    }
    else {
      if ((uVar5 & uVar1) == 0) {
        if ((uVar4 & uVar2) == 0) goto LAB_140014b40;
      }
      else if ((uVar4 & uVar2) == 0) {
        if ((uVar2 & uVar5) != 0) {
          param_2 = 1;
        }
        goto LAB_140014b40;
      }
      param_2 = 3;
    }
  }
LAB_140014b40:
  uVar3 = lm_reg_read_ind(param_1,0x14c8);
  uVar6 = uVar3 & 0xfffffffb | 4;
  if ((param_2 & 1) == 0) {
    uVar6 = uVar3 & 0xfffffffb;
  }
  lm_reg_wr_ind(param_1,0x14c8,uVar6);
  uVar3 = lm_reg_read_ind(param_1,0x14bc);
  uVar6 = uVar3 & 0xffffffef | 0x10;
  if ((param_2 & 2) == 0) {
    uVar6 = uVar3 & 0xffffffef;
  }
  lm_reg_wr_ind(param_1,0x14bc,uVar6);
  return param_2;
}



===== fw_cmd_sync @ 140014bbc =====

ulonglong fw_cmd_sync(longlong param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0;
  if (*(char *)(param_1 + 0x36) == '\0') {
    *(short *)(param_1 + 0x32) = *(short *)(param_1 + 0x32) + 1;
    uVar1 = (uint)*(ushort *)(param_1 + 0x32);
    lm_reg_wr_ind(param_1,*(int *)(param_1 + 0x48) + 4,param_2 | uVar1);
    uVar6 = param_2 & 0xffff | uVar1;
    do {
      mm_stall(5);
      uVar2 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x48) + 8);
      uVar4 = (uint)uVar2 & 0xffff;
      if (uVar4 == uVar6) goto LAB_140014c5d;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 10000);
    if (uVar4 == uVar6) {
LAB_140014c5d:
      uVar2 = uVar2 & 0xffffffffffffff00;
    }
    else {
      uVar3 = lm_reg_wr_ind(param_1,*(int *)(param_1 + 0x48) + 4,
                            param_2 & 0xffffff | uVar1 | 0x5000000);
      uVar2 = CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
      *(undefined1 *)(param_1 + 0x36) = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== lm_abort @ 140014c7c =====

void lm_abort(longlong param_1,int param_2)

{
  lm_chip_core_reset(param_1,param_2);
  lm_reg_wr_ind(param_1,0xa0000,0);
  return;
}



===== lm_chip_core_reset @ 140014ca0 =====

void lm_chip_core_reset(longlong param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  longlong lVar4;
  
  lm_reg_wr_ind(param_1,0x814,0x4020010);
  mm_stall(5);
  lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 0x48),0x47495352);
  *(undefined1 *)(param_1 + 0x36) = 0;
  uVar3 = 0x1010000;
  if (param_2 == 1) {
    uVar3 = 0x3010000;
  }
  fw_cmd_sync(param_1,uVar3);
  lm_reg_read_ind(param_1,0x408);
  if ((*(uint *)(param_1 + 0x74) & 0xffff0000) == 0x57090000) {
    lm_reg_wr_ind(param_1,0x800,0x10);
    lm_reg_read_ind(param_1,0x800);
    mm_stall(5);
    uVar2 = 0x88;
  }
  else {
    uVar2 = 0x188;
  }
  storport_pci_cfg_write_dword(param_1,0x68,uVar2);
  if ((*(uint *)(param_1 + 0x74) & 0xfffffff0) == 0x57060010) {
    lVar4 = 1000;
    do {
      mm_stall(0x1e);
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  else {
    mm_stall(100);
  }
  uVar3 = 0x1020000;
  if (param_2 == 1) {
    uVar3 = 0x3020000;
  }
  fw_cmd_sync(param_1,uVar3);
  uVar3 = 0x1030000;
  if (param_2 == 1) {
    uVar3 = 0x3030000;
  }
  fw_cmd_sync(param_1,uVar3);
  *(short *)(param_1 + 0x34) = *(short *)(param_1 + 0x34) + 1;
  lm_reg_wr_ind(param_1,*(int *)(param_1 + 0x48) + 0x10,*(ushort *)(param_1 + 0x34) | 0x8000);
  uVar3 = 0;
  do {
    uVar1 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x48) + 0x20);
    if ((uVar1 & 0xffffff01) == 0x44564901) break;
    mm_stall(100);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8000);
  if (7999 < uVar3) {
    return;
  }
  uVar3 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x48) + 0xe0);
  uVar1 = *(uint *)(param_1 + 0x9c) & 0xfffeffff;
  *(uint *)(param_1 + 0x44) = uVar3;
  uVar3 = uVar3 & 0x3c;
  *(uint *)(param_1 + 0x9c) = uVar1;
  if (uVar3 == 4) {
    *(uint *)(param_1 + 0x9c) = uVar1 | 0x10000;
  }
  else if (uVar3 != 8) {
    if (uVar3 == 0xc) {
      *(uint *)(param_1 + 0x9c) = uVar1 | 0x10000;
    }
    else if (uVar3 != 0x10) {
      if (uVar3 == 0x14) {
        *(uint *)(param_1 + 0x9c) = uVar1 | 0x10000;
      }
      else if (uVar3 != 0x18) {
        *(undefined1 *)(param_1 + 0x9d) = 0;
        goto LAB_140014e91;
      }
      *(undefined1 *)(param_1 + 0x9d) = 3;
      goto LAB_140014e91;
    }
    *(undefined1 *)(param_1 + 0x9d) = 2;
    goto LAB_140014e91;
  }
  *(undefined1 *)(param_1 + 0x9d) = 1;
LAB_140014e91:
  uVar3 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x48) + 0xe8);
  if ((uVar3 & 0x10000) != 0) {
    *(short *)(param_1 + 0x38) = (short)uVar3;
  }
  uVar2 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x48) + 0xd8);
  *(undefined4 *)(param_1 + 0x3c) = uVar2;
  uVar2 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x48) + 0x3c);
  *(undefined4 *)(param_1 + 0x7c) = uVar2;
  return;
}



===== lm_chip_reset @ 140014ee4 =====

void lm_chip_reset(longlong param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  
  lm_chip_core_reset(param_1,param_2);
  *(undefined1 *)(param_1 + 0x36) = 0;
  if (*(char *)(param_1 + 0x78) == '\x01') {
    uVar1 = storport_pci_cfg_read_dword(param_1,0x42);
    storport_pci_cfg_write_dword(param_1,0x42,uVar1 & 0xfffffffd);
  }
  lVar3 = 0;
  lVar4 = 0xe;
  do {
    *(undefined4 *)(lVar3 + *(longlong *)(param_1 + 0x18)) = 0;
    lVar3 = lVar3 + 4;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  storport_pci_cfg_write_dword(param_1,0x84,0x40000);
  uVar1 = 0x235823;
  if ((*(char *)(param_1 + 0x78) == '\x01') &&
     (uVar1 = 0x235823, *(short *)(param_1 + 0x7a) == 0x85)) {
    uVar1 = 0xa35823;
  }
  uVar2 = uVar1 | 0x400;
  if (*(char *)(param_1 + 0x78) != '\0') {
    uVar2 = uVar1;
  }
  lm_reg_wr_ind(param_1,0xc08,uVar2);
  lm_reg_wr_ind(param_1,0x810,0x288000);
  if ((*(uint *)(param_1 + 0x74) & 0xfffffff0) == 0x57090010) {
    uVar1 = lm_reg_read_ind(param_1,0x8c8);
    lm_reg_wr_ind(param_1,0x8c8,uVar1 | 0x10000);
  }
  iVar5 = 0x3000;
  do {
    iVar5 = iVar5 + -0x40;
    lm_reg_wr_ind(param_1,0x1008,0);
    lm_reg_wr_ind(param_1,0x100c,iVar5);
    uVar1 = 0;
    do {
      lm_ctx_wr(param_1,0,uVar1,0);
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x40);
    lm_reg_wr_ind(param_1,0x1008,iVar5);
    lm_reg_wr_ind(param_1,0x100c,iVar5);
  } while (iVar5 != 0);
  lm_init_cpus(param_1);
  lm_set_mac_addr(param_1,(byte *)(param_1 + 0x8a));
  uVar2 = lm_reg_read_ind(param_1,0x3c08);
  uVar1 = uVar2 & 0xffffff8f | 2;
  if ((*(uint *)(param_1 + 0x74) & 0xffff0000) != 0x57090000) {
    uVar1 = uVar2 & 0xffffff8f;
  }
  lm_reg_wr_ind(param_1,0x3c08,uVar1);
  lm_reg_wr_ind(param_1,0x3c1c,0x410000);
  lm_reg_wr_ind(param_1,0x3c20,0x410000);
  uVar1 = lm_reg_read_ind(param_1,0x2808);
  lm_reg_wr_ind(param_1,0x2808,uVar1 & 0xf0fffffc);
  uVar1 = lm_reg_read_ind(param_1,0x5008);
  lm_reg_wr_ind(param_1,0x5008,uVar1 & 0xf0ffffff | 0x40);
  lm_reg_wr_ind(param_1,0x1498,
                ((uint)*(byte *)(param_1 + 0x8f) + (uint)*(byte *)(param_1 + 0x8c)) * 0x10000 +
                (uint)*(byte *)(param_1 + 0x8e) * 0x100 + (uint)*(byte *)(param_1 + 0x8b) * 0x100 +
                (uint)*(byte *)(param_1 + 0x8d) + (uint)*(byte *)(param_1 + 0x8a));
  lm_reg_wr_ind(param_1,0x149c,*(ushort *)(param_1 + 0x88) + 4);
  lm_set_rx_mask(param_1,*(uint *)(param_1 + 0x59c));
  return;
}



===== lm_reset_run @ 140015164 =====

undefined8 lm_reset_run(int *param_1)

{
  uint uVar1;
  longlong lVar2;
  
  lm_reg_wr_ind(param_1,0x810,0x5ffffff);
  lVar2 = 1000;
  do {
    mm_stall(10);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  lm_post_buffers((longlong)param_1);
  uVar1 = lm_reg_read_ind(param_1,0x6800);
  lm_reg_wr_ind(param_1,0x6800,uVar1 | 0x20000);
  mm_stall(0x14);
  lm_service_phy_intr(param_1,'\x01');
  lm_reg_wr_ind(param_1,0x6800,uVar1 | 0x20000);
  return 0;
}



===== lm_reset_setup @ 1400151f4 =====

undefined8 lm_reset_setup(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  
  lm_chip_reset(param_1,0);
  lVar1 = *(longlong *)(param_1 + 0x1b0);
  *(undefined4 *)(lVar1 + 0xf0) = *(undefined4 *)(param_1 + 0x1bc);
  *(undefined4 *)(lVar1 + 0xf4) = *(undefined4 *)(param_1 + 0x1b8);
  *(longlong *)(lVar1 + 0xf8) = lVar1;
  lVar1 = *(longlong *)(param_1 + 0x3b0);
  *(undefined8 *)(param_1 + 0x1c8) = *(undefined8 *)(param_1 + 0x1b0);
  *(undefined4 *)(param_1 + 0x1e0) = 0xf;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(lVar1 + 0xf0) = *(undefined4 *)(param_1 + 0x3bc);
  *(undefined4 *)(lVar1 + 0xf4) = *(undefined4 *)(param_1 + 0x3b8);
  *(longlong *)(lVar1 + 0xf8) = lVar1;
  *(undefined4 *)(param_1 + 0x3e0) = 0xf;
  *(undefined8 *)(param_1 + 0x3c8) = *(undefined8 *)(param_1 + 0x3b0);
  *(undefined4 *)(param_1 + 0x3c4) = 0;
  *(undefined4 *)(param_1 + 0x3d0) = 0;
  lm_reg_wr_ind(param_1,0x1408,0x800);
  lm_reg_wr_ind(param_1,0x6810,*(undefined4 *)(param_1 + 0x28));
  lm_reg_wr_ind(param_1,0x6814,*(undefined4 *)(param_1 + 0x2c));
  lm_reg_wr_ind(param_1,0x6820,1);
  lm_reg_wr_ind(param_1,0x6828,1);
  lm_reg_wr_ind(param_1,0x6830,200);
  lm_reg_wr_ind(param_1,0x682c,1);
  lm_reg_wr_ind(param_1,0x6824,0);
  lm_reg_wr_ind(param_1,0x6834,0);
  lm_reg_wr_ind(param_1,0x6838,0);
  lm_reg_wr_ind(param_1,0x6844,0);
  uVar2 = *(uint *)(param_1 + 0x74);
  if ((uVar2 & 0xffff0000) == 0x57090000) {
    uVar2 = 0;
    do {
      lm_ctx_wr(param_1,*(int *)(param_1 + 0x1c0),uVar2,0);
      lm_ctx_wr(param_1,*(int *)(param_1 + 0x3c0),uVar2,0);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x2c0);
    uVar2 = *(uint *)(param_1 + 0x74);
  }
  iVar3 = 0;
  if ((uVar2 & 0xffff0000) == 0x57090000) {
    iVar3 = 0x80;
  }
  lm_ctx_wr(param_1,*(int *)(param_1 + 0x1c0),iVar3,0x10080000);
  iVar3 = 0x88;
  if ((*(uint *)(param_1 + 0x74) & 0xffff0000) == 0x57090000) {
    iVar3 = 0x240;
  }
  lm_ctx_wr(param_1,*(int *)(param_1 + 0x1c0),iVar3,0x80000);
  lm_ctx_wr(param_1,*(int *)(param_1 + 0x1c0),iVar3 + 0x18,*(undefined4 *)(param_1 + 0x1bc));
  lm_ctx_wr(param_1,*(int *)(param_1 + 0x1c0),iVar3 + 0x1c,*(undefined4 *)(param_1 + 0x1b8));
  lm_ctx_wr(param_1,*(int *)(param_1 + 0x3c0),0,0x10011000);
  lm_ctx_wr(param_1,*(int *)(param_1 + 0x3c0),0x10,*(undefined4 *)(param_1 + 0x3bc));
  lm_ctx_wr(param_1,*(int *)(param_1 + 0x3c0),0x14,*(undefined4 *)(param_1 + 0x3b8));
  lm_reg_wr_ind(param_1,0x1400,0x408);
  return 0;
}



===== lm_init_cpus @ 1400154a4 =====

void lm_init_cpus(undefined8 param_1)

{
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_18;
  
  lm_init_rv2ps(param_1);
  local_98 = RXP_b06FwReleaseMajor;
  local_94 = RXP_b06FwReleaseMinor;
  local_90 = RXP_b06FwReleaseFix;
  local_8c = RXP_b06FwStartAddr;
  local_88 = RXP_b06FwTextAddr;
  local_84 = RXP_b06FwTextLen;
  local_78 = &RXP_b06FwText;
  local_70 = RXP_b06FwDataAddr;
  local_6c = RXP_b06FwDataLen;
  local_58 = RXP_b06FwSbssAddr;
  local_54 = RXP_b06FwSbssLen;
  local_40 = RXP_b06FwBssAddr;
  local_80 = 0;
  local_68 = 0;
  local_60 = 0;
  local_50 = 0;
  local_48 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_3c = RXP_b06FwBssLen;
  local_c8 = 0xc5000;
  local_c4 = 0x400;
  local_c0 = 2;
  local_bc = 0xc5004;
  local_b8 = 0xffffff;
  local_b4 = 0xc5200;
  local_b0 = 0xc5008;
  local_ac = 0xc501c;
  local_a8 = 0xc5020;
  local_a4 = 0xc5034;
  local_a0 = 0xe0000;
  local_9c = 0x8000000;
  load_fw(param_1,&local_c8,(longlong)&local_98);
  local_98 = TXP_b06FwReleaseMajor;
  local_94 = TXP_b06FwReleaseMinor;
  local_90 = TXP_b06FwReleaseFix;
  local_8c = TXP_b06FwStartAddr;
  local_88 = TXP_b06FwTextAddr;
  local_84 = TXP_b06FwTextLen;
  local_78 = &TXP_b06FwText;
  local_70 = TXP_b06FwDataAddr;
  local_6c = TXP_b06FwDataLen;
  local_c8 = 0x45000;
  local_bc = 0x45004;
  local_b4 = 0x45200;
  local_b0 = 0x45008;
  local_ac = 0x4501c;
  local_a8 = 0x45020;
  local_a4 = 0x45034;
  local_a0 = 0x60000;
  local_58 = TXP_b06FwSbssAddr;
  local_54 = TXP_b06FwSbssLen;
  local_40 = TXP_b06FwBssAddr;
  local_3c = TXP_b06FwBssLen;
  load_fw(param_1,&local_c8,(longlong)&local_98);
  local_98 = TPAT_b06FwReleaseMajor;
  local_94 = TPAT_b06FwReleaseMinor;
  local_90 = TPAT_b06FwReleaseFix;
  local_8c = TPAT_b06FwStartAddr;
  local_88 = TPAT_b06FwTextAddr;
  local_84 = TPAT_b06FwTextLen;
  local_78 = &TPAT_b06FwText;
  local_70 = TPAT_b06FwDataAddr;
  local_6c = TPAT_b06FwDataLen;
  local_58 = TPAT_b06FwSbssAddr;
  local_54 = TPAT_b06FwSbssLen;
  local_40 = TPAT_b06FwBssAddr;
  local_3c = TPAT_b06FwBssLen;
  local_c8 = 0x85000;
  local_bc = 0x85004;
  local_b4 = 0x85200;
  local_b0 = 0x85008;
  local_ac = 0x8501c;
  local_a8 = 0x85020;
  local_a4 = 0x85034;
  local_a0 = 0xa0000;
  load_fw(param_1,&local_c8,(longlong)&local_98);
  local_98 = COM_b06FwReleaseMajor;
  local_94 = COM_b06FwReleaseMinor;
  local_90 = COM_b06FwReleaseFix;
  local_8c = COM_b06FwStartAddr;
  local_88 = COM_b06FwTextAddr;
  local_84 = COM_b06FwTextLen;
  local_78 = &COM_b06FwText;
  local_70 = COM_b06FwDataAddr;
  local_6c = COM_b06FwDataLen;
  local_58 = COM_b06FwSbssAddr;
  local_54 = COM_b06FwSbssLen;
  local_c8 = 0x105000;
  local_bc = 0x105004;
  local_b4 = 0x105200;
  local_b0 = 0x105008;
  local_ac = 0x10501c;
  local_a8 = 0x105020;
  local_a4 = 0x105034;
  local_a0 = 0x120000;
  local_40 = COM_b06FwBssAddr;
  local_3c = COM_b06FwBssLen;
  load_fw(param_1,&local_c8,(longlong)&local_98);
  return;
}



===== lm_init_rv2ps @ 14001580c =====

void lm_init_rv2ps(undefined8 param_1)

{
  load_rv2p_fw(param_1,(undefined4 *)&rv2p_proc1,0x248,'\0');
  load_rv2p_fw(param_1,(undefined4 *)&rv2p_proc2,0x430,'\x01');
  return;
}



===== load_fw @ 140015848 =====

void load_fw(undefined8 param_1,undefined4 *param_2,longlong param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  int iVar6;
  ulonglong uVar7;
  
  uVar1 = lm_reg_read_ind(param_1,*param_2);
  lm_reg_wr_ind(param_1,*param_2,param_2[1] | uVar1);
  lm_reg_wr_ind(param_1,param_2[3],param_2[4]);
  uVar5 = 0;
  iVar3 = param_2[0xb];
  iVar4 = param_2[10];
  iVar6 = (*(int *)(param_3 + 0x10) - iVar3) + iVar4;
  if ((*(longlong *)(param_3 + 0x20) != 0) &&
     (uVar1 = 0, (*(uint *)(param_3 + 0x14) & 0xfffffffc) != 0)) {
    do {
      lm_reg_wr_ind(param_1,iVar6,
                    *(undefined4 *)(*(longlong *)(param_3 + 0x20) + (ulonglong)uVar1 * 4));
      iVar6 = iVar6 + 4;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_3 + 0x14) >> 2);
    iVar4 = param_2[10];
    iVar3 = param_2[0xb];
  }
  iVar6 = (*(int *)(param_3 + 0x28) - iVar3) + iVar4;
  if ((*(longlong *)(param_3 + 0x38) != 0) &&
     (uVar7 = 0, (*(uint *)(param_3 + 0x2c) & 0xfffffffc) != 0)) {
    do {
      lm_reg_wr_ind(param_1,iVar6,*(undefined4 *)(*(longlong *)(param_3 + 0x38) + uVar7 * 4));
      iVar6 = iVar6 + 4;
      uVar1 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar1;
    } while (uVar1 < *(uint *)(param_3 + 0x2c) >> 2);
    iVar3 = param_2[0xb];
    iVar4 = param_2[10];
  }
  iVar6 = (*(int *)(param_3 + 0x40) - iVar3) + iVar4;
  if ((*(longlong *)(param_3 + 0x50) != 0) &&
     (uVar7 = 0, (*(uint *)(param_3 + 0x44) & 0xfffffffc) != 0)) {
    do {
      lm_reg_wr_ind(param_1,iVar6,*(undefined4 *)(*(longlong *)(param_3 + 0x50) + uVar7 * 4));
      iVar6 = iVar6 + 4;
      uVar1 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar1;
    } while (uVar1 < *(uint *)(param_3 + 0x44) >> 2);
    iVar3 = param_2[0xb];
    iVar4 = param_2[10];
  }
  iVar6 = (*(int *)(param_3 + 0x58) - iVar3) + iVar4;
  if ((*(longlong *)(param_3 + 0x68) != 0) &&
     (uVar7 = 0, (*(uint *)(param_3 + 0x5c) & 0xfffffffc) != 0)) {
    do {
      lm_reg_wr_ind(param_1,iVar6,*(undefined4 *)(*(longlong *)(param_3 + 0x68) + uVar7 * 4));
      iVar6 = iVar6 + 4;
      uVar1 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar1;
    } while (uVar1 < *(uint *)(param_3 + 0x5c) >> 2);
    iVar3 = param_2[0xb];
    iVar4 = param_2[10];
  }
  iVar4 = (*(int *)(param_3 + 0x70) - iVar3) + iVar4;
  if ((*(longlong *)(param_3 + 0x80) != 0) && ((*(uint *)(param_3 + 0x74) & 0xfffffffc) != 0)) {
    do {
      lm_reg_wr_ind(param_1,iVar4,*(undefined4 *)(*(longlong *)(param_3 + 0x80) + uVar5 * 4));
      iVar4 = iVar4 + 4;
      uVar1 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar1;
    } while (uVar1 < *(uint *)(param_3 + 0x74) >> 2);
  }
  lm_reg_wr_ind(param_1,param_2[8],0);
  lm_reg_wr_ind(param_1,param_2[7],*(undefined4 *)(param_3 + 0xc));
  uVar2 = lm_reg_read_ind(param_1,*param_2);
  uVar1 = param_2[1];
  lm_reg_wr_ind(param_1,param_2[3],param_2[4]);
  lm_reg_wr_ind(param_1,*param_2,uVar2 & ~uVar1);
  return;
}



===== load_rv2p_fw @ 140015a54 =====

void load_rv2p_fw(undefined8 param_1,undefined4 *param_2,uint param_3,char param_4)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    if (param_4 == '\0') {
      do {
        lm_reg_wr_ind(param_1,0x2830,*param_2);
        lm_reg_wr_ind(param_1,0x2834,param_2[1]);
        param_2 = param_2 + 2;
        lm_reg_wr_ind(param_1,0x2838,uVar1 >> 3 | 0x80000000);
        uVar1 = uVar1 + 8;
      } while (uVar1 < param_3);
    }
    else {
      do {
        lm_reg_wr_ind(param_1,0x2830,*param_2);
        lm_reg_wr_ind(param_1,0x2834,param_2[1]);
        param_2 = param_2 + 2;
        lm_reg_wr_ind(param_1,0x283c,uVar1 >> 3 | 0x80000000);
        uVar1 = uVar1 + 8;
      } while (uVar1 < param_3);
    }
  }
  lm_reg_wr_ind(param_1,0x2800,(-(uint)(param_4 != '\0') & 0x10000) + 0x10000);
  return;
}



===== ev_lm_disable_intr @ 140015b50 =====

void ev_lm_disable_intr(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 == 0) {
    iVar3 = (-(uint)(*(char *)(param_1 + 0x138) != '\0') & 4) + 0x108000;
    uVar1 = lm_reg_read_ind(param_1,iVar3);
    uVar1 = uVar1 & 0xffffffe7;
  }
  else {
    iVar3 = 0x130154;
    uVar1 = lm_reg_read_ind(param_1,0x130154);
    uVar1 = uVar1 & 0xfffffffb;
  }
  lm_reg_wr_ind(param_1,iVar3,uVar1);
  return;
}



===== ev_lm_enable_intr @ 140015bb4 =====

void ev_lm_enable_intr(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 == 0) {
    iVar3 = (-(uint)(*(char *)(param_1 + 0x138) != '\0') & 4) + 0x108000;
    uVar1 = lm_reg_read_ind(param_1,iVar3);
    uVar1 = uVar1 | 8;
  }
  else {
    iVar3 = 0x130154;
    uVar1 = lm_reg_read_ind(param_1,0x130154);
    uVar1 = uVar1 | 4;
  }
  lm_reg_wr_ind(param_1,iVar3,uVar1);
  return;
}



===== ev_lm_get_dev_info @ 140015c18 =====

undefined8 ev_lm_get_dev_info(undefined1 *param_1)

{
  byte bVar1;
  bool bVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined7 extraout_var;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined7 extraout_var_00;
  ushort uVar9;
  uint uVar10;
  longlong lVar11;
  undefined2 *puVar12;
  undefined4 local_58;
  undefined1 local_54 [8];
  undefined1 local_4c [8];
  undefined1 local_44 [28];
  
  bVar2 = lm_get_basic_hw_info((longlong)param_1);
  if ((((int)CONCAT71(extraout_var,bVar2) == 1) ||
      (uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + (uint)(byte)param_1[0x138] * 4),
      (uVar4 & 0x600000) != 0x600000)) || ((uVar4 & 0xff000000) != 0x41000000)) {
    uVar8 = 1;
  }
  else {
    uVar3 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x684 +
                                    (uint)(byte)param_1[0x13b] * 0x2c);
    *(undefined2 *)(param_1 + 0x32) = uVar3;
    uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1c);
    *(undefined4 *)(param_1 + 0x44) = uVar5;
    uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x360 +
                                    ((byte)param_1[0x13d] >> 1 & 1) * 0x74);
    bVar1 = param_1[0x13c];
    *(undefined4 *)(param_1 + 0x48) = uVar5;
    local_54._0_2_ = local_54._1_2_;
    local_4c._0_2_ = local_4c._1_2_;
    local_44._0_2_ = local_44._1_2_;
    lm_get_mac_addresses((longlong)param_1,&local_58);
    param_1[0x110] = local_54[1];
    param_1[0x111] = local_54[0];
    param_1[0x112] = (char)((uint)local_58 >> 0x18);
    param_1[0x113] = (char)((uint)local_58 >> 0x10);
    param_1[0x114] = (char)((uint)local_58 >> 8);
    param_1[0x115] = (char)local_58;
    param_1[0x116] = local_4c[1];
    param_1[0x117] = local_4c[0];
    param_1[0x118] = local_54[7];
    param_1[0x119] = local_54[6];
    param_1[0x11a] = local_54[5];
    param_1[0x11b] = local_54[4];
    param_1[0x11c] = local_44[1];
    param_1[0x11d] = local_44[0];
    param_1[0x11e] = local_4c[7];
    param_1[0x11f] = local_4c[6];
    param_1[0x120] = local_4c[5];
    param_1[0x121] = local_4c[4];
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x368 +
                                    ((byte)param_1[0x13d] >> 1 & 1) * 0x74);
    if ((uVar4 >> 0x10 & 1) != 0) {
      *(uint *)(param_1 + 0x34) = uVar4;
    }
    uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1b0 +
                                    (uint)(byte)param_1[0x138] * 400);
    *(undefined4 *)(param_1 + 0x134) = uVar5;
    uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x378 +
                                    (uint)(byte)param_1[0x138] * 0x74);
    *(undefined4 *)(param_1 + 0x144) = uVar5;
    uVar5 = lm_reg_read_ind(param_1,((byte)param_1[0x138] + 1) * 400 + *(int *)(param_1 + 0x4c));
    *(undefined4 *)(param_1 + 0x148) = uVar5;
    uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x30);
    *(undefined4 *)(param_1 + 0x168) = uVar5;
    uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x70 +
                                    (uint)(byte)param_1[0x138] * 400);
    uVar9 = (ushort)uVar5 & 0xff;
    *(ushort *)(param_1 + 0x15e) = uVar9;
    *(ushort *)(param_1 + 0x162) = uVar9;
    *(ushort *)(param_1 + 0x164) = (ushort)((uint)uVar5 >> 0x10) & 0xff;
    *(ushort *)(param_1 + 0x160) = (ushort)(byte)((uint)uVar5 >> 0x18);
    uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x74 +
                                    (uint)(byte)param_1[0x138] * 400);
    *(ushort *)(param_1 + 0x15a) = (ushort)((uint)uVar5 >> 8) & 0xff;
    *(ushort *)(param_1 + 0x15c) = (ushort)((uint)uVar5 >> 0x10) & 0xff;
    iVar6 = lm_reg_read_ind(param_1,0x10394);
    if (iVar6 != 0) {
      *(ushort *)(param_1 + 0x14e) = *(ushort *)(param_1 + 0x14e) | 1;
    }
    iVar6 = 0;
    lVar11 = 2;
    puVar12 = (undefined2 *)(param_1 + 0x9e);
    do {
      uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xa0 +
                                      ((uint)(byte)param_1[0x138] * 100 + iVar6) * 4);
      puVar12[-1] = (short)uVar5;
      *puVar12 = (short)((uint)uVar5 >> 0x10);
      uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xa8 +
                                      ((uint)(byte)param_1[0x138] * 100 + iVar6) * 4);
      puVar12[3] = (short)uVar5;
      iVar6 = iVar6 + 1;
      puVar12[4] = (short)((uint)uVar5 >> 0x10);
      lVar11 = lVar11 + -1;
      puVar12 = puVar12 + 2;
    } while (lVar11 != 0);
    uVar7 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354);
    if ((uVar7 & 2) != 0) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 2;
    }
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x358 +
                                    (uint)(byte)param_1[0x138] * 0x74);
    if ((uVar4 >> 0x1a & 1) != 0) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 4;
    }
    if ((uVar4 >> 0x18 & 1) != 0) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x20;
    }
    if ((uVar4 & 0x100) != 0) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 8;
    }
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354);
    if ((uVar4 & 0x700) == 0x400) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x204;
    }
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354);
    if ((uVar4 & 0x700) == 0x600) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 4;
    }
    uVar8 = lm_is_mf_device((longlong)param_1);
    if (((int)uVar8 != 0) &&
       (bVar2 = lm_is_mf_cfg((longlong)param_1), (int)CONCAT71(extraout_var_00,bVar2) != 0)) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x40;
      uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354);
      if ((uVar4 & 0x700) == 0) {
        uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x24 + (uint)bVar1 * 0x18);
        if ((uVar4 & 6) == 0) {
          uVar7 = 8;
        }
        else {
          uVar7 = 4;
          if ((uVar4 & 6) != 6) {
            uVar7 = 0;
          }
        }
      }
      else {
        uVar7 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0xe4 + (uint)bVar1 * 0x28);
      }
      if ((uVar7 & 4) != 0) {
        *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x80;
      }
      if ((uVar7 & 8) != 0) {
        *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x100;
      }
    }
    uVar7 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x358 +
                                    (uint)(byte)param_1[0x138] * 0x74);
    if ((uVar7 & 0xc00) != 0) {
      uVar4 = *(uint *)(param_1 + 0x58);
      uVar10 = uVar4 | 0x800;
      *(uint *)(param_1 + 0x58) = uVar10;
      if ((uVar7 & 0x800) != 0) {
        uVar10 = uVar4 | 0x1800;
        *(uint *)(param_1 + 0x58) = uVar10;
      }
      if ((uVar7 & 0x400) != 0) {
        *(uint *)(param_1 + 0x58) = uVar10 | 0x2000;
      }
    }
    param_1[0x172] = param_1[0x110];
    param_1[0x173] = param_1[0x111];
    param_1[0x174] = param_1[0x112];
    param_1[0x175] = param_1[0x113];
    param_1[0x176] = param_1[0x114];
    param_1[0x177] = param_1[0x115];
    *(undefined4 *)(param_1 + 0x17a) = 0x100010;
    *(undefined4 *)(param_1 + 0x180) = 0;
    *(undefined4 *)(param_1 + 0x18c) = 0;
    *(undefined2 *)(param_1 + 0x185) = 0x202;
    *param_1 = 0;
    *(undefined8 *)(param_1 + 0xb4) = 0;
    lm_get_phy_info((longlong)param_1,0);
    ev_mm_get_user_config((longlong)param_1);
    *(undefined2 *)(param_1 + 0x170) = 0x5ea;
    uVar8 = 0;
  }
  return uVar8;
}



===== ev_lm_get_interrupt_status @ 140016178 =====

undefined2 ev_lm_get_interrupt_status(longlong param_1)

{
  undefined2 uVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  if (*(short *)(lVar2 + 0x28) != *(short *)(param_1 + 100)) {
    uVar1 = *(undefined2 *)(lVar2 + 0x28);
    *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 4;
    *(undefined2 *)(param_1 + 100) = uVar1;
  }
  if (*(short *)(lVar2 + 0x18) != *(short *)(param_1 + 0x66)) {
    uVar1 = *(undefined2 *)(lVar2 + 0x18);
    *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 2;
    *(undefined2 *)(param_1 + 0x66) = uVar1;
  }
  if (*(short *)(lVar2 + 0x38) != *(short *)(param_1 + 0x68)) {
    uVar1 = *(undefined2 *)(lVar2 + 0x38);
    *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 8;
    *(undefined2 *)(param_1 + 0x68) = uVar1;
  }
  if (*(short *)(lVar2 + 0x48) != *(short *)(param_1 + 0x6a)) {
    uVar1 = *(undefined2 *)(lVar2 + 0x48);
    *(ushort *)(param_1 + 0x6c) = *(ushort *)(param_1 + 0x6c) | 0x10;
    *(undefined2 *)(param_1 + 0x6a) = uVar1;
  }
  return *(undefined2 *)(param_1 + 0x6c);
}



===== ev_lm_init_phy @ 1400161e0 =====

undefined8 ev_lm_init_phy(longlong param_1,byte param_2)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  int iVar7;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  *(undefined1 *)(param_1 + 0x18c) = 6;
  if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
    uVar5 = lm_is_e3(param_1);
    if ((int)uVar5 != 0) goto LAB_140016235;
    iVar7 = (uint)bVar1 * 0x18 + 0x10340;
  }
  else {
    iVar7 = 0xa9cc;
  }
  uVar2 = lm_reg_read_ind(param_1,iVar7);
  *(undefined2 *)(param_1 + 0x122) = uVar2;
LAB_140016235:
  if ((*(uint *)(param_1 + 0x58) & 0x10000) == 0) {
    uVar3 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x664 + (uint)bVar1 * 0x10);
    *(uint *)(param_1 + 4) = (~uVar3 & 1) + 4;
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 1;
    uVar4 = lm_get_link_speed(param_1);
    *(undefined4 *)(param_1 + 0xc) = uVar4;
  }
  else {
    *(byte *)(param_1 + 0x14c) = (byte)(*(uint *)(param_1 + 0x134) >> 0xe) & 3;
    *(char *)(param_1 + 0x13f) = (char)(*(uint *)(param_1 + 0x134) >> 8);
    *(undefined1 *)(param_1 + 0x140) = *(undefined1 *)(param_1 + 0x134);
    everest_init_nig_mdio(param_1);
    lm_reg_wr_ind(param_1,0xa5a4,0x1f0 << ((*(byte *)(param_1 + 0x138) & 1) << 4));
    mm_stall(500);
    if (((param_2 - 0xf7 & 0xfffffff9) == 0) && (param_2 != 0xf9)) {
      uVar3 = *(uint *)(param_1 + 0x18c) & 0xffffff00 | (uint)param_2;
      *(uint *)(param_1 + 0x18c) = uVar3;
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x18c);
    }
    lm_phy_initialize_link(param_1,uVar3);
    if (*(int *)(param_1 + 4) == 4) {
      iVar7 = 0;
      do {
        uVar6 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x24 +
                                        (uint)*(byte *)(param_1 + 0x13c) * 0x18);
        if ((uVar6 & 8) == 0) break;
        mm_stall(1000000);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0x1e);
      if ((uVar6 & 8) != 0) {
        *(undefined4 *)(param_1 + 4) = 5;
      }
    }
  }
  return 0;
}



===== ev_lm_init_resc @ 140016360 =====

undefined8 ev_lm_init_resc(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar5;
  uint uVar4;
  int iVar6;
  
  mm_alloc_dma_buffer(param_1);
  mm_alloc_statusblock(param_1);
  *(undefined4 *)(param_1 + 0x488) = 1;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(undefined8 *)(param_1 + 0x368) = 0;
  *(undefined8 *)(param_1 + 0x3f8) = 0;
  *(undefined8 *)(param_1 + 0x2e0) = 0x10;
  *(undefined8 *)(param_1 + 0x370) = 0x10;
  *(undefined8 *)(param_1 + 0x400) = 0x10;
  mm_alloc_tx_ring(param_1);
  *(undefined4 *)(param_1 + 700) = 0;
  lVar2 = *(longlong *)(param_1 + 0x2a8);
  *(longlong *)(param_1 + 0x2c0) = lVar2;
  *(undefined4 *)(param_1 + 0x2d0) = 0xf;
  *(longlong *)(param_1 + 0x2c8) = *(longlong *)(param_1 + 0x18) + 0x20;
  lm_setup_bd_chain_ring(lVar2,(uint *)(param_1 + 0x2b0),1);
  *(undefined4 *)(param_1 + 0x6c0) = 1;
  *(undefined8 *)(param_1 + 0x4d0) = 0;
  *(undefined8 *)(param_1 + 0x4d8) = 0x10;
  *(undefined8 *)(param_1 + 0x560) = 0;
  *(undefined8 *)(param_1 + 0x568) = 0x10;
  *(undefined8 *)(param_1 + 0x5f0) = 0;
  *(undefined8 *)(param_1 + 0x5f8) = 0x10;
  mm_alloc_rx_ring(param_1);
  plVar1 = (longlong *)(param_1 + 0x4a0);
  lm_setup_bd_chain_ring(*plVar1,(uint *)(param_1 + 0x4a8),1);
  *(longlong *)(param_1 + 0x4b8) = *plVar1;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x4c8) = 0xf;
  mm_alloc_rcq_ring(param_1);
  lm_setup_bd_chain_ring(*(longlong *)(param_1 + 0x688),(uint *)(param_1 + 0x690),1);
  *(undefined2 *)(param_1 + 0x6b8) = 0xf;
  *(longlong *)(param_1 + 0x6b0) = *(longlong *)(param_1 + 0x18) + 0x10;
  *(undefined8 *)(param_1 + 0x6a0) = *(undefined8 *)(param_1 + 0x688);
  iVar6 = 0;
  *(undefined8 *)(param_1 + 0x6a8) = *(undefined8 *)(param_1 + 0x688);
  *(undefined4 *)(param_1 + 0x698) = 1;
  if (*(short *)(param_1 + 0x17a) != 0) {
    do {
      puVar3 = (undefined8 *)ev_mm_get_tx_desc(param_1,iVar6);
      *(undefined4 *)(puVar3 + 1) = 0x7450324c;
      *puVar3 = 0;
      *(undefined1 *)((longlong)puVar3 + 0xc) = 0;
      puVar3[2] = param_1;
      puVar3[3] = (longlong *)(param_1 + 0x2a8);
      *(undefined1 *)(puVar3 + 5) = 0;
      iVar5 = *(int *)(param_1 + 0x2dc);
      if (iVar5 == 0) {
        iVar5 = *(int *)(param_1 + 0x2e0);
      }
      uVar4 = iVar5 - 1;
      if (uVar4 != *(uint *)(param_1 + 0x2d8)) {
        *(undefined8 **)(param_1 + 0x2e8 + (ulonglong)uVar4 * 8) = puVar3;
        *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + 1;
        *(uint *)(param_1 + 0x2dc) = uVar4;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x17a));
  }
  iVar6 = 0;
  if (*(short *)(param_1 + 0x17c) != 0) {
    do {
      puVar3 = (undefined8 *)ev_mm_get_rx_desc(param_1,iVar6);
      *(undefined4 *)(puVar3 + 1) = 0x7250324c;
      *puVar3 = 0;
      *(undefined1 *)((longlong)puVar3 + 0xc) = 1;
      puVar3[2] = param_1;
      puVar3[3] = plVar1;
      *(undefined1 *)(puVar3 + 5) = 0;
      *(undefined2 *)(puVar3 + 9) = 0x600;
      iVar5 = *(int *)(param_1 + 0x4d4);
      if (iVar5 == 0) {
        iVar5 = *(int *)(param_1 + 0x4d8);
      }
      uVar4 = iVar5 - 1;
      if (uVar4 != *(uint *)(param_1 + 0x4d0)) {
        *(undefined8 **)(param_1 + 0x4e0 + (ulonglong)uVar4 * 8) = puVar3;
        *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
        *(uint *)(param_1 + 0x4d4) = uVar4;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 0x17c));
  }
  ev_mm_initialize_packets(param_1);
  return 0;
}



===== ev_lm_post_buffers @ 1400165e0 =====

int ev_lm_post_buffers(longlong param_1)

{
  undefined4 *puVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  longlong lVar7;
  short sVar8;
  undefined4 *puVar9;
  
  iVar3 = *(int *)(param_1 + 0x4d0);
  iVar5 = 0;
  if (iVar3 == *(int *)(param_1 + 0x4d4)) {
    lVar7 = 0;
  }
  else {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x4d8);
    }
    *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + -1;
    *(uint *)(param_1 + 0x4d0) = iVar3 - 1U;
    lVar7 = *(longlong *)(param_1 + 0x4e0 + (ulonglong)(iVar3 - 1U) * 8);
  }
  sVar6 = *(short *)(param_1 + 0x4b4);
  sVar8 = *(short *)(param_1 + 0x698);
  puVar1 = *(undefined4 **)(param_1 + 0x4b8);
  while (puVar9 = puVar1, lVar7 != 0) {
    puVar9 = puVar1 + 4;
    sVar2 = sVar6 + 1;
    if (((byte)(sVar6 + 1) & 0xf) == 0xf) {
      puVar9 = *(undefined4 **)(puVar1 + 6);
      sVar2 = sVar6 + 2;
    }
    sVar6 = sVar2;
    *(short *)(lVar7 + 0x36) = sVar6;
    puVar1[1] = *(undefined4 *)(lVar7 + 0x44);
    *puVar1 = *(undefined4 *)(lVar7 + 0x40);
    *(int *)(param_1 + 0x4c8) = *(int *)(param_1 + 0x4c8) + -1;
    *(short *)(param_1 + 0x6b8) = *(short *)(param_1 + 0x6b8) + -1;
    iVar3 = *(int *)(param_1 + 0x564);
    sVar8 = (((char)sVar8 + 1U & 0xf) == 0xf) + 1 + sVar8;
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x568);
    }
    uVar4 = iVar3 - 1;
    if (uVar4 != *(uint *)(param_1 + 0x560)) {
      *(longlong *)(param_1 + 0x570 + (ulonglong)uVar4 * 8) = lVar7;
      *(int *)(param_1 + 0x56c) = *(int *)(param_1 + 0x56c) + 1;
      *(uint *)(param_1 + 0x564) = uVar4;
    }
    iVar5 = iVar5 + 1;
    if ((*(int *)(param_1 + 0x4c8) == 0) ||
       (iVar3 = *(int *)(param_1 + 0x4d0), iVar3 == *(int *)(param_1 + 0x4d4))) break;
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x4d8);
    }
    *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + -1;
    *(uint *)(param_1 + 0x4d0) = iVar3 - 1U;
    puVar1 = puVar9;
    lVar7 = *(longlong *)(param_1 + 0x4e0 + (ulonglong)(iVar3 - 1U) * 8);
  }
  *(short *)(param_1 + 0x4b4) = sVar6;
  *(undefined4 **)(param_1 + 0x4b8) = puVar9;
  *(short *)(param_1 + 0x698) = sVar8;
  if (iVar5 != 0) {
    lm_update_tstorm_rx_indices(param_1,sVar8,sVar6);
  }
  return iVar5;
}



===== ev_lm_send_packet @ 140016768 =====

undefined8 ev_lm_send_packet(longlong param_1,longlong param_2,byte *param_3)

{
  undefined4 *puVar1;
  short sVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  short sVar14;
  undefined4 local_res8;
  
  *(int *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) - (uint)*param_3;
  puVar1 = *(undefined4 **)(param_1 + 0x2c0);
  sVar14 = *(short *)(param_1 + 700);
  bVar6 = 0;
  iVar4 = 0;
  puVar10 = puVar1;
  pbVar12 = param_3 + 8;
  puVar13 = puVar1;
  bVar7 = 0;
  if (*param_3 != 0) {
    do {
      puVar10 = puVar13;
      *puVar10 = *(undefined4 *)pbVar12;
      puVar10[1] = *(undefined4 *)(pbVar12 + 4);
      bVar6 = bVar7 + 1;
      *(undefined2 *)((longlong)puVar10 + 10) = *(undefined2 *)(pbVar12 + 8);
      *(undefined1 *)((longlong)puVar10 + 0xe) = 0;
      puVar13 = puVar10 + 4;
      sVar2 = sVar14 + 1;
      if (((byte)(sVar14 + 1) & 0xf) == 0xf) {
        puVar13 = *(undefined4 **)(puVar10 + 6);
        bVar6 = bVar7 + 2;
        sVar2 = sVar14 + 2;
      }
      sVar14 = sVar2;
      iVar4 = iVar4 + 1;
      pbVar12 = pbVar12 + 0x10;
      bVar7 = bVar6;
    } while (iVar4 < (int)(uint)*param_3);
  }
  bVar7 = *(byte *)((longlong)puVar1 + 0xe);
  *(byte *)((longlong)puVar1 + 0xe) = bVar7 | 2;
  *(ushort *)(puVar1 + 2) = (ushort)*param_3;
  if (*(short *)(param_1 + 0x38) != 0) {
    *(byte *)((longlong)puVar1 + 0xe) = bVar7 | 3;
    *(undefined2 *)(puVar1 + 3) = *(undefined2 *)(param_1 + 0x38);
    if (*(short *)(param_1 + 0xec) == 0x500) {
      *(byte *)((longlong)puVar1 + 0xe) = bVar7 | 0xb;
    }
  }
  *(byte *)((longlong)puVar10 + 0xe) = *(byte *)((longlong)puVar10 + 0xe) | 4;
  *(ushort *)(param_2 + 0x30) = (ushort)*param_3;
  *(short *)(param_2 + 0x2e) = sVar14;
  *(undefined4 **)(param_1 + 0x2c0) = puVar13;
  *(short *)(param_1 + 700) = sVar14;
  iVar4 = *(int *)(param_1 + 0x36c);
  if (iVar4 == 0) {
    iVar4 = *(int *)(param_1 + 0x370);
  }
  uVar5 = iVar4 - 1;
  if (uVar5 != *(uint *)(param_1 + 0x368)) {
    *(longlong *)(param_1 + 0x378 + (ulonglong)uVar5 * 8) = param_2;
    *(int *)(param_1 + 0x374) = *(int *)(param_1 + 0x374) + 1;
    *(uint *)(param_1 + 0x36c) = uVar5;
  }
  local_res8 = CONCAT22(1,(ushort)bVar6 << 8);
  if ((*(uint *)(param_1 + 0x124) & 0xffff0000) == 0x164e0000) {
    uVar5 = -(uint)(*(char *)(param_1 + 0x138) != '\0') & 0x80000000;
  }
  else {
    uVar5 = (*(byte *)(param_1 + 0x13e) & 1 | (uint)*(byte *)(param_1 + 0x13b) * 2) << 0x1d;
  }
  uVar11 = *(uint *)(param_1 + 0x58) & 0x20000;
  if (uVar11 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = (uint)*(byte *)(param_1 + 0x13e);
  }
  uVar3 = lm_is_e3(param_1);
  if (((int)uVar3 == 0) || (*(char *)(param_1 + 0x138) == '\0')) {
    if ((uVar11 == 0) && (*(byte *)(param_1 + 0x13d) < 2)) {
      storport_pci_cfg_write_dword(param_1,0x90,uVar5);
      storport_pci_cfg_write_dword(param_1,0x94,local_res8);
      return 0;
    }
    if (*(char *)(param_1 + 0x138) == '\0') {
      lm_reg_wr_ind(param_1,0x17008c,uVar5);
      uVar3 = lm_is_dual_core(param_1);
      if ((int)uVar3 != 0) {
        lm_reg_wr_ind(param_1,0x1701b0,uVar9);
      }
      uVar8 = 0x170208;
      goto LAB_1400169a3;
    }
  }
  lm_reg_wr_ind(param_1,0x170090,uVar5);
  uVar3 = lm_is_dual_core(param_1);
  if ((int)uVar3 != 0) {
    lm_reg_wr_ind(param_1,0x1701b4,uVar9);
  }
  uVar8 = 0x17020c;
LAB_1400169a3:
  lm_reg_wr_ind(param_1,uVar8,local_res8);
  return 0;
}



===== ev_lm_service_intr @ 1400169cc =====

void ev_lm_service_intr(longlong param_1)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  undefined6 extraout_var;
  undefined8 uVar4;
  
  uVar1 = ev_lm_get_interrupt_status(param_1);
  if ((int)CONCAT62(extraout_var,uVar1) != 0) {
    *(undefined2 *)(param_1 + 0x5c) = 1;
    if ((uVar1 & 2) != 0) {
      if ((*(short **)(param_1 + 0x6b0) != (short *)0x0) &&
         (**(short **)(param_1 + 0x6b0) != *(short *)(param_1 + 0x69a))) {
        ev_lm_service_rx_intr(param_1);
      }
      if (*(int *)(param_1 + 0x4d0) != *(int *)(param_1 + 0x4d4)) {
        ev_lm_post_buffers(param_1);
      }
    }
    if (((((*(uint *)(param_1 + 0x58) & 0x10000) != 0) && (*(int *)(param_1 + 4) == 4)) &&
        ((*(byte *)(param_1 + 0x14e) & 0x20) != 0)) && (*(int *)(param_1 + 0x6c8) == 0)) {
      uVar4 = lm_acquire_mdio_hw_lock(param_1,0);
      if ((int)uVar4 == 0) {
        lm_phy_set_aer_mmd(param_1);
        sVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x83ea);
        if (sVar2 != 0) {
          uVar3 = lm_get_link_speed(param_1);
          if ((uVar3 & 0xff00) == 0x600) {
            *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
            if (20000 < *(int *)(param_1 + 0xf0)) {
              *(undefined4 *)(param_1 + 0xf0) = 0;
              lm_enable_xmac(param_1,0);
            }
            mm_stall(1);
          }
        }
        lm_release_mdio_hw_lock(param_1);
      }
    }
    if ((((uVar1 & 4) != 0) && (*(short **)(param_1 + 0x2c8) != (short *)0x0)) &&
       (**(short **)(param_1 + 0x2c8) != *(short *)(param_1 + 0x2be))) {
      ev_lm_service_tx_intr(param_1);
    }
  }
  return;
}



===== ev_lm_service_rx_intr @ 140016b28 =====

void ev_lm_service_rx_intr(longlong param_1)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  short sVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  short sVar10;
  short sVar11;
  longlong lVar12;
  undefined2 uVar13;
  
  if (*(int *)(param_1 + 0xb4) == 0) {
    *(undefined4 *)(param_1 + 0xb4) = 1;
    sVar11 = **(short **)(param_1 + 0x6b0);
    if (((byte)sVar11 & 0xf) == 0xf) {
      sVar11 = sVar11 + 1;
    }
    uVar13 = *(undefined2 *)(param_1 + 0x4b6);
    sVar10 = *(short *)(param_1 + 0x69a);
    while (sVar10 != sVar11) {
      pcVar3 = *(char **)(param_1 + 0x6a8);
      *(char **)(param_1 + 0x6a8) = pcVar3 + 0x10;
      sVar5 = sVar10 + 1;
      if (((byte)(sVar10 + 1) & 0xf) == 0xf) {
        *(undefined8 *)(param_1 + 0x6a8) = *(undefined8 *)(pcVar3 + 0x18);
        sVar5 = sVar10 + 2;
      }
      sVar10 = sVar5;
      if (*pcVar3 == '\x01') {
        cVar1 = pcVar3[7];
        *(undefined1 *)(param_1 + 0x6d8) = 0;
        if ((pcVar3[8] & 1U) == 0) {
          *(char *)(param_1 + 0x6e) = cVar1;
        }
        *(short *)(param_1 + 0x698) = *(short *)(param_1 + 0x698) + 1;
        if (((byte)*(short *)(param_1 + 0x698) & 0xf) == 0xf) {
          *(short *)(param_1 + 0x698) = *(short *)(param_1 + 0x698) + 1;
        }
      }
      else {
        iVar7 = *(int *)(param_1 + 0x560);
        if (iVar7 == *(int *)(param_1 + 0x564)) break;
        if (iVar7 == 0) {
          iVar7 = *(int *)(param_1 + 0x568);
        }
        *(int *)(param_1 + 0x56c) = *(int *)(param_1 + 0x56c) + -1;
        *(uint *)(param_1 + 0x560) = iVar7 - 1U;
        lVar12 = *(longlong *)(param_1 + 0x570 + (ulonglong)(iVar7 - 1U) * 8);
        if (lVar12 == 0) break;
        *(int *)(param_1 + 0x4c8) = *(int *)(param_1 + 0x4c8) + 1;
        uVar13 = *(undefined2 *)(lVar12 + 0x36);
        *(undefined4 *)(lVar12 + 0x20) = 0;
        *(undefined2 *)(lVar12 + 0x24) = *(undefined2 *)(pcVar3 + 6);
        *(undefined4 *)(lVar12 + 0x2c) = 0;
        *(int *)(param_1 + 0x6c8) = *(int *)(param_1 + 0x6c8) + 1;
        if ((*(uint *)(param_1 + 0x58) & 0x200000) == 0) {
          pbVar4 = *(byte **)(lVar12 + 0x38);
          iVar7 = 1;
          bVar6 = *pbVar4;
          if (bVar6 == 0xff) {
            iVar7 = 3;
LAB_140016cf5:
            bVar6 = lm_validate_vntag_vlan_hdr(param_1,lVar12,iVar7);
          }
          else {
            if (((bVar6 & 1) == 0) && ((bVar6 != 0x33 || (pbVar4[1] != 0x33)))) goto LAB_140016cf5;
            bVar2 = *(byte *)(param_1 + 0x1a4);
            iVar7 = 2;
            uVar8 = 0;
            if (bVar2 != 0) {
              pbVar9 = (byte *)(param_1 + 0x1a7);
              do {
                if (((((pbVar9[-1] == bVar6) && (*pbVar9 == pbVar4[1])) && (pbVar9[1] == pbVar4[2]))
                    && ((pbVar9[2] == pbVar4[3] && (pbVar9[3] == pbVar4[4])))) &&
                   (pbVar9[4] == pbVar4[5])) break;
                uVar8 = uVar8 + 1;
                pbVar9 = pbVar9 + 8;
              } while ((int)uVar8 < (int)(uint)bVar2);
            }
            if (bVar2 != uVar8) goto LAB_140016cf5;
            bVar6 = 1;
          }
          if ((*(ushort *)(param_1 + 0x38) != 0) &&
             (((*(ushort *)(param_1 + 0x38) ^ *(ushort *)(pcVar3 + 4)) & 0xfff) != 0)) {
            bVar6 = 1;
          }
        }
        else {
          bVar6 = 1;
        }
        if (pcVar3[1] != '\0') {
          *(int *)(param_1 + 0x6cc) = *(int *)(param_1 + 0x6cc) + 1;
          bVar6 = 1;
        }
        sVar11 = **(short **)(param_1 + 0x6b0);
        if (((byte)sVar11 & 0xf) == 0xf) {
          sVar11 = sVar11 + 1;
        }
        if (bVar6 == 0) {
          iVar7 = *(int *)(param_1 + 0x5f4);
          if (iVar7 == 0) {
            iVar7 = *(int *)(param_1 + 0x5f8);
          }
          uVar8 = iVar7 - 1;
          if (uVar8 != *(uint *)(param_1 + 0x5f0)) {
            *(longlong *)(param_1 + 0x600 + (ulonglong)uVar8 * 8) = lVar12;
            *(int *)(param_1 + 0x5fc) = *(int *)(param_1 + 0x5fc) + 1;
            *(uint *)(param_1 + 0x5f4) = uVar8;
          }
        }
        else {
          iVar7 = *(int *)(param_1 + 0x4d4);
          if (iVar7 == 0) {
            iVar7 = *(int *)(param_1 + 0x4d8);
          }
          uVar8 = iVar7 - 1;
          if (uVar8 != *(uint *)(param_1 + 0x4d0)) {
            *(longlong *)(param_1 + 0x4e0 + (ulonglong)uVar8 * 8) = lVar12;
            *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
            *(uint *)(param_1 + 0x4d4) = uVar8;
          }
        }
      }
      *(short *)(param_1 + 0x6b8) = *(short *)(param_1 + 0x6b8) + 1;
      *(undefined2 *)(param_1 + 0x4b6) = uVar13;
      *(short *)(param_1 + 0x69a) = sVar10;
      lm_update_tstorm_rx_indices
                (param_1,*(undefined2 *)(param_1 + 0x698),*(undefined2 *)(param_1 + 0x4b4));
    }
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  return;
}



===== ev_lm_service_tx_intr @ 140016e0c =====

void ev_lm_service_tx_intr(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  
  if (*(int *)(param_1 + 0xb8) == 0) {
    *(undefined4 *)(param_1 + 0xb8) = 1;
    sVar5 = *(short *)(param_1 + 0x2be);
    if (sVar5 != **(short **)(param_1 + 0x2c8)) {
      do {
        iVar3 = *(int *)(param_1 + 0x368);
        if (iVar3 == *(int *)(param_1 + 0x36c)) break;
        if (iVar3 == 0) {
          iVar3 = *(int *)(param_1 + 0x370);
        }
        *(int *)(param_1 + 0x374) = *(int *)(param_1 + 0x374) + -1;
        *(uint *)(param_1 + 0x368) = iVar3 - 1U;
        lVar2 = *(longlong *)(param_1 + 0x378 + (ulonglong)(iVar3 - 1U) * 8);
        if (lVar2 == 0) break;
        *(undefined4 *)(lVar2 + 0x20) = 0;
        *(int *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) + (uint)*(ushort *)(lVar2 + 0x30);
        sVar1 = **(short **)(param_1 + 0x2c8);
        iVar3 = *(int *)(param_1 + 0x3fc);
        if (iVar3 == 0) {
          iVar3 = *(int *)(param_1 + 0x400);
        }
        uVar4 = iVar3 - 1;
        if (uVar4 != *(uint *)(param_1 + 0x3f8)) {
          *(longlong *)(param_1 + 0x408 + (ulonglong)uVar4 * 8) = lVar2;
          *(int *)(param_1 + 0x404) = *(int *)(param_1 + 0x404) + 1;
          *(uint *)(param_1 + 0x3fc) = uVar4;
        }
        sVar5 = sVar5 + 1;
      } while (sVar5 != sVar1);
    }
    *(short *)(param_1 + 0x2be) = sVar5;
    *(undefined4 *)(param_1 + 0xb8) = 0;
  }
  return;
}



===== ev_lm_set_rx_mask @ 140016ee8 =====

undefined8 ev_lm_set_rx_mask(longlong param_1,uint param_2)

{
  undefined8 uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined8 local_res8;
  
  *(uint *)(param_1 + 0x6c4) = param_2;
  uVar3 = 0x1b8;
  if (param_2 != 0) {
    uVar3 = 0x138;
    if ((*(char *)(param_1 + 0x1a4) != '\0') || ((param_2 & 4) != 0)) {
      uVar3 = 0x118;
    }
    if ((param_2 >> 0x10 & 1) != 0) {
      uVar3 = uVar3 & 0xffcf;
    }
  }
  uVar1 = lm_is_e3(param_1);
  uVar2 = uVar3 & 0xffcf;
  if ((int)uVar1 == 0) {
    uVar2 = uVar3;
  }
  local_res8._0_4_ = (uint)uVar2 << 0x10;
  local_res8 = CONCAT44(0x5fc,(int)local_res8);
  lm_set_mac_addrs(param_1);
  if (*(short *)(param_1 + 0x38) == 0) {
    local_res8 = (ulonglong)local_res8._1_7_ << 8;
  }
  else {
    local_res8 = (ulonglong)local_res8._1_7_ << 8 | 1;
  }
  lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 200),(int)local_res8);
  lm_reg_wr_ind(param_1,*(int *)(param_1 + 200) + 4,local_res8._4_4_);
  return 0;
}



===== everest_init_ccm_common @ 140016fb4 =====

void everest_init_ccm_common(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  lm_reg_wr_ind(param_1,0xd0044,0x32);
  lm_reg_wr_ind(param_1,0xd008c,0x2150020);
  lm_reg_wr_ind(param_1,0xd0090,0x2150020);
  lm_reg_wr_ind(param_1,0xd0094,0x8100000);
  lm_reg_wr_ind(param_1,0xd0098,0x33);
  lm_reg_wr_ind(param_1,0xd00c0,1);
  lm_reg_wr_ind(param_1,0xd00c8,2);
  lm_reg_wr_ind(param_1,0xd00cc,2);
  lm_reg_wr_ind(param_1,0xd0108,1);
  lm_reg_wr_ind(param_1,0xd015c,1);
  lm_reg_wr_ind(param_1,0xd0164,1);
  lm_reg_wr_ind(param_1,0xd0168,2);
  lm_reg_wr_ind(param_1,0xd0204,1);
  lm_reg_wr_ind(param_1,0xd020c,0x20);
  lm_reg_wr_ind(param_1,0xd0210,0x40);
  lm_reg_wr_ind(param_1,0xd0214,0x40);
  uVar2 = 0xd0280;
  do {
    lm_reg_wr_ind(param_1,uVar2,0);
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0xd02c8);
  uVar3 = 0;
  uVar2 = 0xd0300;
  iVar1 = 0;
  do {
    if (uVar3 < 0x18) {
      iVar4 = ((uVar3 + 1) % 0x18) * 0x2000 + iVar1;
    }
    else {
      iVar4 = 0;
    }
    lm_reg_wr_ind(param_1,uVar2,iVar4);
    uVar3 = uVar3 + 1;
    iVar1 = iVar1 + 0xc0;
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0xd0390);
  lm_reg_wr_ind(param_1,0xd0220,3);
  lm_reg_wr_ind(param_1,0xd0224,0x18);
  lm_reg_wr_ind(param_1,0xd004c,1);
  lm_reg_wr_ind(param_1,0xd00c4,4);
  lm_reg_wr_ind(param_1,0xd0118,0x28);
  lm_reg_wr_ind(param_1,0xd0004,1);
  lm_reg_wr_ind(param_1,0xd0008,1);
  lm_reg_wr_ind(param_1,0xd000c,1);
  lm_reg_wr_ind(param_1,0xd0010,1);
  lm_reg_wr_ind(param_1,0xd0014,1);
  lm_reg_wr_ind(param_1,0xd0018,1);
  lm_reg_wr_ind(param_1,0xd001c,1);
  lm_reg_wr_ind(param_1,0xd0020,1);
  lm_reg_wr_ind(param_1,0xd0024,1);
  lm_reg_wr_ind(param_1,0xd0028,1);
  lm_reg_wr_ind(param_1,0xd002c,1);
  lm_reg_wr_ind(param_1,0xd0030,1);
  lm_reg_wr_ind(param_1,0xd0034,1);
  lm_reg_wr_ind(param_1,0xd0038,1);
  lm_reg_wr_ind(param_1,0xd003c,1);
  return;
}



===== everest_init_csem_common @ 1400172c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_csem_common(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined1 auStack_58 [32];
  ushort local_38 [12];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  uVar1 = 0;
  local_38[0] = 0;
  local_38[1] = 6;
  local_38[2] = 3;
  local_38[3] = 7;
  local_38[4] = 0x32;
  local_38[5] = 8;
  iVar2 = 0x200400;
  local_38[6] = 0x33;
  local_38[7] = 9;
  local_38[8] = 0x34;
  local_38[9] = 10;
  do {
    lm_reg_wr_ind(param_1,iVar2,0x7ff8);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x200800);
  puVar3 = local_38;
  do {
    lm_reg_wr_ind(param_1,(uint)*puVar3 * 4 + 0x200400,(uint)puVar3[1]);
    uVar1 = uVar1 + 1;
    puVar3 = puVar3 + 2;
  } while (uVar1 < 5);
  iVar2 = 0x202000;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x204000);
  lm_reg_wr_ind(param_1,0x200020,1);
  lm_reg_wr_ind(param_1,0x200024,2);
  lm_reg_wr_ind(param_1,0x200028,3);
  lm_reg_wr_ind(param_1,0x20002c,0);
  lm_reg_wr_ind(param_1,0x200030,4);
  lm_reg_wr_ind(param_1,0x200034,0x12);
  lm_reg_wr_ind(param_1,0x200038,0);
  lm_reg_wr_ind(param_1,0x20003c,1);
  lm_reg_wr_ind(param_1,0x200040,4);
  lm_reg_wr_ind(param_1,0x200044,0);
  lm_reg_wr_ind(param_1,0x200048,1);
  lm_reg_wr_ind(param_1,0x20004c,3);
  lm_reg_wr_ind(param_1,0x200050,0);
  lm_reg_wr_ind(param_1,0x200054,1);
  lm_reg_wr_ind(param_1,0x200058,4);
  lm_reg_wr_ind(param_1,0x20005c,0);
  lm_reg_wr_ind(param_1,0x200060,1);
  lm_reg_wr_ind(param_1,0x200064,3);
  lm_reg_wr_ind(param_1,0x200068,0);
  lm_reg_wr_ind(param_1,0x20006c,1);
  lm_reg_wr_ind(param_1,0x200070,4);
  lm_reg_wr_ind(param_1,0x200074,0);
  lm_reg_wr_ind(param_1,0x200078,4);
  lm_reg_wr_ind(param_1,0x20007c,3);
  lm_reg_wr_ind(param_1,0x200080,0);
  lm_reg_wr_ind(param_1,0x200084,0);
  lm_reg_wr_ind(param_1,0x2000a4,0x3fff);
  lm_reg_wr_ind(param_1,0x2000a8,0x3ff);
  lm_reg_wr_ind(param_1,0x200224,0);
  lm_reg_wr_ind(param_1,0x200234,0);
  lm_reg_wr_ind(param_1,0x20024c,0);
  lm_reg_wr_ind(param_1,0x2002e4,0xffff);
  lm_reg_write_block(param_1,0x238bc0,(undefined4 *)&DAT_14002f504,1);
  lm_reg_write_block(param_1,0x238000,(undefined4 *)&DAT_14002f510,1);
  lm_reg_write_block(param_1,0x238040,(undefined4 *)&DAT_14002f514,1);
  lm_reg_write_block(param_1,0x238080,(undefined4 *)&DAT_14002f518,1);
  lm_reg_write_block(param_1,0x2380c0,(undefined4 *)&DAT_14002f51c,1);
  iVar2 = 0x225000;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x225108);
  iVar2 = 0x221020;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x221340);
  lm_reg_write_block(param_1,0x221000,(undefined4 *)&DAT_14002f520,2);
  return;
}



===== everest_init_nig_mac_addr @ 14001767c =====

void everest_init_nig_mac_addr(longlong param_1,int param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  
  cVar2 = *(char *)(param_1 + 0x138);
  uVar4 = 0;
  iVar1 = (-(uint)(cVar2 != '\0') & 0x40) + 0x16180 + param_2 * 8;
  if (param_4 == 0) {
    uVar3 = 0;
  }
  else {
    uVar4 = CONCAT31(CONCAT21(CONCAT11(param_3[2],param_3[3]),param_3[4]),param_3[5]);
    uVar3 = (uint)CONCAT11(*param_3,param_3[1]);
  }
  lm_reg_wr_ind(param_1,iVar1,uVar4);
  lm_reg_wr_ind(param_1,iVar1 + 4,uVar3);
  lm_reg_wr_ind(param_1,(-(uint)(cVar2 != '\0') & 0x20) + 0x16140 + param_2 * 4,param_4);
  return;
}



===== everest_init_nig_mdio @ 140017748 =====

void everest_init_nig_mdio(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  uVar1 = lm_is_e3(param_1);
  if ((int)uVar1 == 0) {
    if (*(char *)(param_1 + 0x138) == '\0') {
      lm_reg_wr_ind(param_1,0x10338,0);
      uVar2 = 0x1033c;
    }
    else {
      lm_reg_wr_ind(param_1,0x10350,0);
      uVar2 = 0x10354;
    }
    lm_reg_wr_ind(param_1,uVar2,3);
  }
  return;
}



===== everest_init_nig_port @ 1400177a0 =====

void everest_init_nig_port(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_res8;
  undefined4 local_res10;
  
  everest_init_nig_mdio(param_1);
  uVar1 = lm_is_e3(param_1);
  if (*(char *)(param_1 + 0x138) == '\0') {
    if ((int)uVar1 == 0) {
      lm_reg_wr_ind(param_1,0x100e8,1);
    }
    uVar4 = 0x100f8;
    local_res10 = 0x10084;
    uVar8 = 0x10330;
    local_res8 = 0x1007c;
    uVar3 = 0x100cc;
    uVar2 = 0x10060;
    uVar7 = 0x100c4;
    uVar5 = 0x10328;
    uVar6 = 0x1008c;
  }
  else {
    if ((int)uVar1 == 0) {
      lm_reg_wr_ind(param_1,0x100ec,1);
    }
    uVar4 = 0x100fc;
    local_res10 = 0x10088;
    uVar8 = 0x10334;
    local_res8 = 0x10080;
    uVar3 = 0x100d0;
    uVar2 = 0x10064;
    uVar7 = 0x100c8;
    uVar5 = 0x1032c;
    uVar6 = 0x10090;
  }
  lm_reg_wr_ind(param_1,uVar2,0);
  lm_reg_wr_ind(param_1,local_res8,0);
  lm_reg_wr_ind(param_1,local_res10,0);
  lm_reg_wr_ind(param_1,uVar6,0);
  lm_reg_wr_ind(param_1,uVar5,0);
  lm_reg_wr_ind(param_1,uVar8,0x3c0001);
  lm_reg_wr_ind(param_1,uVar7,1);
  lm_reg_wr_ind(param_1,uVar3,1);
  lm_reg_wr_ind(param_1,uVar4,1);
  if (*(char *)(param_1 + 0x138) == '\0') {
    lm_reg_wr_ind(param_1,0x185b0,1);
    if ((*(uint *)(param_1 + 0x58) & 0x20000) == 0) {
      return;
    }
    lm_reg_wr_ind(param_1,0x16024,1);
    lm_reg_wr_ind(param_1,0x160fc,1);
    if ((*(uint *)(param_1 + 0x58) & 0x4000) != 0) {
      lm_reg_wr_ind(param_1,0x16080,1);
      lm_reg_wr_ind(param_1,0x18038,7);
      uVar2 = 0x16100;
LAB_14001794f:
      lm_reg_wr_ind(param_1,uVar2,(uint)*(ushort *)(param_1 + 0x38));
      if (*(short *)(param_1 + 0xec) != 0x500) {
        return;
      }
      lm_reg_wr_ind(param_1,0x401a8,0x88a8);
      lm_reg_wr_ind(param_1,0x15c06c,0x88a8);
      uVar3 = 0x88a8;
      uVar2 = 0x16028;
      goto LAB_140017a31;
    }
    lm_reg_wr_ind(param_1,0x16080,2);
    uVar2 = 0x18038;
  }
  else {
    lm_reg_wr_ind(param_1,0x185c4,1);
    if ((*(uint *)(param_1 + 0x58) & 0x20000) == 0) {
      return;
    }
    lm_reg_wr_ind(param_1,0x18614,1);
    lm_reg_wr_ind(param_1,0x16104,1);
    if ((*(uint *)(param_1 + 0x58) & 0x4000) != 0) {
      lm_reg_wr_ind(param_1,0x16084,1);
      lm_reg_wr_ind(param_1,0x1818c,7);
      uVar2 = 0x16108;
      goto LAB_14001794f;
    }
    lm_reg_wr_ind(param_1,0x16084,2);
    uVar2 = 0x1818c;
  }
  uVar3 = 6;
LAB_140017a31:
  lm_reg_wr_ind(param_1,uVar2,uVar3);
  return;
}



===== everest_init_pbf_common @ 140017a50 =====

void everest_init_pbf_common(longlong param_1)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  
  lm_reg_wr_ind(param_1,0x140000,1);
  uVar1 = lm_is_e3(param_1);
  if (((int)uVar1 == 0) || ((*(uint *)(param_1 + 0x124) & 0xf000) == 0)) {
    iVar3 = 0x140004;
    lVar4 = 3;
  }
  else {
    iVar3 = 0x15c160;
    lm_reg_wr_ind(param_1,0x15c1f8,3);
    lm_reg_wr_ind(param_1,0x140030,1);
    lm_reg_wr_ind(param_1,0x14003c,1);
    lVar4 = 7;
  }
  lVar6 = lVar4;
  iVar2 = iVar3;
  do {
    lVar5 = lVar6;
    lm_reg_wr_ind(param_1,iVar2,1);
    iVar2 = iVar2 + 4;
    lVar6 = lVar5 + -1;
  } while (lVar6 != 0);
  lm_reg_wr_ind(param_1,0x140040,(int)lVar5);
  lm_reg_wr_ind(param_1,0x140044,0xfffff);
  lm_reg_wr_ind(param_1,0x14006c,0);
  lm_reg_wr_ind(param_1,0x140000,0);
  do {
    lm_reg_wr_ind(param_1,iVar3,0);
    iVar3 = iVar3 + 4;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}



===== everest_init_pxp2_common @ 140017b78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_pxp2_common(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined1 auStack_68 [32];
  ushort local_48 [16];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  local_48[0] = 0x5130;
  local_48[1] = 0x5148;
  local_48[2] = 0x5190;
  local_48[3] = 0x51a8;
  local_48[4] = 0x51c0;
  local_48[5] = 0x51d8;
  local_48[6] = 0x51f0;
  local_48[7] = 21000;
  local_48[8] = 0x1508;
  local_48[9] = 0x1518;
  local_48[10] = 0x1848;
  local_48[0xb] = 0x1858;
  local_48[0xc] = 0x1868;
  local_48[0xd] = 0x1878;
  local_48[0xe] = 0x1888;
  local_48[0xf] = 0x1898;
  lm_reg_wr_ind(param_1,0x120514,0x1410);
  iVar1 = 0x12049c;
  iVar3 = 0x1204b4;
  do {
    lm_reg_wr_ind(param_1,iVar1,0xffffffff);
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x1204b4);
  iVar1 = 0x1204d4;
  do {
    lm_reg_wr_ind(param_1,iVar3,0xffffffff);
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x1204d4);
  iVar3 = 0x1204dc;
  iVar4 = 0x1204f4;
  do {
    lm_reg_wr_ind(param_1,iVar3,0xffffffff);
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x1204f4);
  do {
    lm_reg_wr_ind(param_1,iVar4,0xffffffff);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x120514);
  lVar5 = 0;
  lVar2 = lVar5;
  do {
    lm_reg_wr_ind(param_1,iVar1,local_48[lVar2] | 0xffff0000);
    iVar1 = iVar1 + 4;
    lVar2 = lVar2 + 1;
  } while (lVar2 < 8);
  iVar1 = 0x120494;
  do {
    lm_reg_wr_ind(param_1,iVar1,local_48[lVar5 + 8] | 0xfff80000);
    iVar1 = iVar1 + 4;
    lVar5 = lVar5 + 1;
  } while (lVar5 < 8);
  lm_reg_wr_ind(param_1,0x120390,8);
  lm_reg_wr_ind(param_1,0x12039c,8);
  lm_reg_wr_ind(param_1,0x1203a0,8);
  lm_reg_wr_ind(param_1,0x1203a4,2);
  lm_reg_wr_ind(param_1,0x1203bc,4);
  lm_reg_wr_ind(param_1,0x1203c0,5);
  lm_reg_wr_ind(param_1,0x1203c4,4);
  lm_reg_wr_ind(param_1,0x1203d0,0);
  lm_reg_wr_ind(param_1,0x12036c,1);
  lm_reg_wr_ind(param_1,0x1201b0,1);
  iVar1 = 0x122000;
  do {
    lm_reg_wr_ind(param_1,iVar1,0);
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x124000);
  lm_reg_wr_ind(param_1,0x942c,1);
  return;
}



===== everest_init_qm_common @ 140017db4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_qm_common(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 auStack_58 [32];
  undefined4 local_38 [4];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  lm_reg_wr_ind(param_1,0x168040,6);
  lm_reg_wr_ind(param_1,0x168044,5);
  lm_reg_wr_ind(param_1,0x168048,6);
  lm_reg_wr_ind(param_1,0x16804c,5);
  iVar3 = 0x1680cc;
  do {
    lm_reg_wr_ind(param_1,iVar3,4);
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0x1680ec);
  lm_reg_wr_ind(param_1,0x168804,4);
  lm_reg_wr_ind(param_1,0x168030,0x7c);
  lm_reg_wr_ind(param_1,0x168034,0x3d);
  lm_reg_wr_ind(param_1,0x168038,0x3f);
  lm_reg_wr_ind(param_1,0x16803c,0x9c);
  lm_reg_wr_ind(param_1,0x168240,0xfefffeff);
  lm_reg_wr_ind(param_1,0x168244,0xfefffefe);
  uVar1 = lm_is_e3(param_1);
  iVar3 = 0;
  if (((int)uVar1 == 0) || ((*(uint *)(param_1 + 0x124) & 0xf000) == 0)) {
    uVar2 = 0x16824c;
    uVar7 = 1;
  }
  else {
    uVar2 = 0x16825c;
    uVar7 = 0x10001;
  }
  lm_reg_wr_ind(param_1,uVar2,uVar7);
  lm_reg_wr_ind(param_1,0x168268,0x1000100);
  lm_reg_wr_ind(param_1,0x16826c,0x1000100);
  lm_reg_wr_ind(param_1,0x1680f4,0);
  lm_reg_wr_ind(param_1,0x168134,0);
  lm_reg_wr_ind(param_1,0x168114,5);
  lm_reg_wr_ind(param_1,0x168154,5);
  lm_reg_wr_ind(param_1,0x168194,5);
  lm_reg_wr_ind(param_1,0x1681d4,5);
  uVar1 = lm_is_e3(param_1);
  uVar2 = 3;
  if (((int)uVar1 == 0) || ((*(uint *)(param_1 + 0x124) & 0xf000) == 0)) {
    uVar2 = 1;
  }
  else {
    lm_reg_wr_ind(param_1,0x16e7c0,3);
  }
  lm_reg_wr_ind(param_1,0x168174,uVar2);
  lm_reg_wr_ind(param_1,0x1681b4,uVar2);
  lm_reg_wr_ind(param_1,0x1682a0,0);
  lm_reg_wr_ind(param_1,0x1682a4,1);
  lm_reg_wr_ind(param_1,0x1682b4,0);
  uVar1 = lm_is_e3(param_1);
  if (((int)uVar1 == 0) || ((*(uint *)(param_1 + 0x124) & 0xf000) == 0)) {
    uVar2 = 0x17;
    uVar7 = 0xc08;
  }
  else {
    uVar2 = 0x1f;
    uVar7 = 0xc00;
  }
  lm_reg_wr_ind(param_1,0x1681f4,uVar7);
  lm_reg_wr_ind(param_1,0x168204,uVar2);
  lm_reg_wr_ind(param_1,0x168200,0x20);
  lm_reg_wr_ind(param_1,0x168060,0x140);
  lm_reg_wr_ind(param_1,0x168064,0x140);
  lm_reg_wr_ind(param_1,0x16806c,0x140);
  lm_reg_wr_ind(param_1,0x168074,0);
  lm_reg_wr_ind(param_1,0x16809c,0x40);
  lm_reg_wr_ind(param_1,0x1680a0,0x40);
  lm_reg_wr_ind(param_1,0x1680a8,0x40);
  lm_reg_wr_ind(param_1,0x1680b0,0);
  lm_reg_wr_ind(param_1,0x168238,0x8000);
  lm_reg_wr_ind(param_1,0x168234,0x2400);
  lm_reg_wr_ind(param_1,0x168220,1);
  lm_reg_wr_ind(param_1,0x16821c,1);
  lm_reg_wr_ind(param_1,0x168228,0);
  lm_reg_wr_ind(param_1,0x168224,0xffffffff);
  lm_reg_wr_ind(param_1,0x168230,0);
  lm_reg_wr_ind(param_1,0x16822c,0xffffffff);
  local_38[0] = 0;
  iVar5 = 2;
  local_38[1] = 2;
  local_38[2] = 1;
  local_38[3] = 3;
  lm_reg_wr_ind(param_1,0x16e794,0);
  lm_reg_wr_ind(param_1,0x16e6f0,1);
  lm_reg_wr_ind(param_1,0x16e6f4,1);
  lm_reg_wr_ind(param_1,0x16e6f8,4);
  lm_reg_wr_ind(param_1,0x168220,0x10001);
  lm_reg_wr_ind(param_1,0x16821c,0x10001);
  if ((1 < (ushort)(*(short *)(param_1 + 0xfa) + 0xe9c3U)) &&
     ((*(short *)(param_1 + 0xfc) + 0x1c0fU & 0xfffd) != 0)) {
    iVar5 = 1;
  }
  uVar6 = 0;
  do {
    iVar4 = (uint)*(byte *)(param_1 + 0x13d) * 4 + 0x120674;
    lm_reg_wr_ind(param_1,iVar4,uVar6 & 0xff);
    lm_reg_read_ind(param_1,iVar4);
    lm_reg_wr_ind(param_1,0x16e70c,1);
    uVar6 = uVar6 + iVar5;
  } while ((int)uVar6 < 8);
  iVar5 = (uint)*(byte *)(param_1 + 0x13d) * 4 + 0x120674;
  lm_reg_wr_ind(param_1,iVar5,(uint)*(byte *)(param_1 + 0x13d));
  lm_reg_read_ind(param_1,iVar5);
  iVar5 = 0x16e6bc;
  do {
    lm_reg_wr_ind(param_1,iVar5,local_38[iVar3]);
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0x16e6cc);
  lm_reg_wr_ind(param_1,0x1680ec,0xff);
  return;
}



===== everest_init_qm_port @ 1400182e4 =====

void everest_init_qm_port(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0x168a80;
  if (*(char *)(param_1 + 0x138) == '\0') {
    iVar3 = 0;
    iVar4 = 0x168a00;
    do {
      lm_reg_wr_ind(param_1,iVar4 + -0x100,iVar3);
      lm_reg_wr_ind(param_1,iVar4,0);
      iVar3 = iVar3 + 0x1000;
      iVar4 = iVar4 + 4;
    } while (iVar4 < 0x168a80);
    uVar2 = 0x168020;
  }
  else {
    do {
      lm_reg_wr_ind(param_1,iVar3 + -0x100,0x1000);
      lm_reg_wr_ind(param_1,iVar3,0);
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x168b00);
    uVar2 = 0x168024;
  }
  lm_reg_wr_ind(param_1,uVar2,0x3f);
  uVar1 = lm_is_dual_core(param_1);
  if ((int)uVar1 != 0) {
    lm_reg_wr_ind(param_1,0x16e70c,1);
  }
  return;
}



===== everest_init_tcm_common @ 1400183b4 =====

void everest_init_tcm_common(longlong param_1)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  
  lm_reg_wr_ind(param_1,0x50048,0x32);
  lm_reg_wr_ind(param_1,0x50090,0x2150020);
  lm_reg_wr_ind(param_1,0x50094,0x2150020);
  lm_reg_wr_ind(param_1,0x50098,0x30);
  lm_reg_wr_ind(param_1,0x5009c,0x8100000);
  lm_reg_wr_ind(param_1,0x500a0,0x33);
  lm_reg_wr_ind(param_1,0x500a4,0x30);
  lm_reg_wr_ind(param_1,0x500a8,0x31);
  lm_reg_wr_ind(param_1,0x500d4,1);
  lm_reg_wr_ind(param_1,0x50204,1);
  lm_reg_wr_ind(param_1,0x5020c,0x40);
  lm_reg_wr_ind(param_1,0x50210,0x40);
  uVar6 = 0x20;
  lm_reg_wr_ind(param_1,0x5021c,0x20);
  lm_reg_wr_ind(param_1,0x50224,0x10);
  lm_reg_wr_ind(param_1,0x50044,0x20);
  uVar3 = 0x50240;
  do {
    lm_reg_wr_ind(param_1,uVar3,0);
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x50268);
  uVar1 = lm_is_e3(param_1);
  uVar3 = 0;
  if ((int)uVar1 == 0) {
    iVar4 = (-(uint)(((*(uint *)(param_1 + 0x124) & 0xffff0000) + 0xe99e0000 & 0xfffeffff) != 0) &
            0xfffffff7) + 0x1c;
  }
  else {
    iVar4 = 0x1e;
    uVar6 = 0x1d;
  }
  iVar2 = 0;
  iVar5 = 0x50280;
  do {
    uVar3 = uVar3 + 1;
    lm_reg_wr_ind(param_1,iVar5,((int)((ulonglong)uVar3 % uVar6) * 0x400 + iVar2) * 0x40);
    iVar2 = iVar2 + iVar4;
    iVar5 = iVar5 + 4;
  } while (uVar3 < (uint)uVar6);
  lm_reg_wr_ind(param_1,0x50050,5);
  lm_reg_wr_ind(param_1,0x50220,iVar4);
  lm_reg_wr_ind(param_1,0x50004,1);
  lm_reg_wr_ind(param_1,0x50008,1);
  lm_reg_wr_ind(param_1,0x5000c,1);
  lm_reg_wr_ind(param_1,0x50010,1);
  lm_reg_wr_ind(param_1,0x50014,1);
  lm_reg_wr_ind(param_1,0x50018,1);
  lm_reg_wr_ind(param_1,0x5001c,1);
  lm_reg_wr_ind(param_1,0x50020,1);
  lm_reg_wr_ind(param_1,0x50024,1);
  lm_reg_wr_ind(param_1,0x50028,1);
  lm_reg_wr_ind(param_1,0x5002c,1);
  lm_reg_wr_ind(param_1,0x50030,1);
  lm_reg_wr_ind(param_1,0x50034,1);
  lm_reg_wr_ind(param_1,0x50038,1);
  lm_reg_wr_ind(param_1,0x5003c,1);
  lm_reg_wr_ind(param_1,0x50040,1);
  return;
}



===== everest_init_tsem_common @ 1400186ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_tsem_common(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined1 auStack_98 [32];
  ushort local_78 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_98;
  local_78[0] = 3;
  local_78[1] = 9;
  local_78[2] = 4;
  local_78[3] = 6;
  local_78[4] = 5;
  local_78[5] = 7;
  iVar2 = 0x180400;
  local_78[6] = 6;
  local_78[7] = 8;
  local_78[8] = 7;
  local_78[9] = 0xf;
  local_78[10] = 8;
  local_78[0xb] = 0x10;
  local_78[0xc] = 9;
  local_78[0xd] = 0x11;
  local_78[0xe] = 10;
  local_78[0xf] = 0x12;
  local_78[0x10] = 0xb;
  local_78[0x11] = 0x13;
  local_78[0x12] = 0xc;
  local_78[0x13] = 0x14;
  local_78[0x14] = 0x30;
  local_78[0x15] = 10;
  local_78[0x16] = 0x31;
  local_78[0x17] = 0xb;
  local_78[0x18] = 0x32;
  local_78[0x19] = 0xc;
  local_78[0x1a] = 0x33;
  local_78[0x1b] = 0xd;
  local_78[0x1c] = 0x34;
  local_78[0x1d] = 0xe;
  do {
    lm_reg_wr_ind(param_1,iVar2,0x7ff8);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x180800);
  uVar1 = 0;
  puVar3 = local_78;
  do {
    lm_reg_wr_ind(param_1,(uint)*puVar3 * 4 + 0x180400,(uint)puVar3[1]);
    uVar1 = uVar1 + 1;
    puVar3 = puVar3 + 2;
  } while (uVar1 < 0xf);
  iVar2 = 0x181000;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x183000);
  lm_reg_wr_ind(param_1,0x180020,1);
  lm_reg_wr_ind(param_1,0x180024,2);
  lm_reg_wr_ind(param_1,0x180028,3);
  lm_reg_wr_ind(param_1,0x18002c,0);
  lm_reg_wr_ind(param_1,0x180030,4);
  lm_reg_wr_ind(param_1,0x180034,0x12);
  lm_reg_wr_ind(param_1,0x180038,0);
  lm_reg_wr_ind(param_1,0x18003c,1);
  lm_reg_wr_ind(param_1,0x180040,4);
  lm_reg_wr_ind(param_1,0x180044,0);
  lm_reg_wr_ind(param_1,0x180048,1);
  lm_reg_wr_ind(param_1,0x18004c,3);
  lm_reg_wr_ind(param_1,0x180050,0);
  lm_reg_wr_ind(param_1,0x180054,1);
  lm_reg_wr_ind(param_1,0x180058,4);
  lm_reg_wr_ind(param_1,0x18005c,0);
  lm_reg_wr_ind(param_1,0x180060,1);
  lm_reg_wr_ind(param_1,0x180064,3);
  lm_reg_wr_ind(param_1,0x180068,0);
  lm_reg_wr_ind(param_1,0x18006c,1);
  lm_reg_wr_ind(param_1,0x180070,4);
  lm_reg_wr_ind(param_1,0x180074,0);
  lm_reg_wr_ind(param_1,0x180078,4);
  lm_reg_wr_ind(param_1,0x18007c,3);
  lm_reg_wr_ind(param_1,0x180080,0);
  lm_reg_wr_ind(param_1,0x180084,0);
  lm_reg_wr_ind(param_1,0x1800a4,0x3fff);
  lm_reg_wr_ind(param_1,0x1800a8,0x3ff);
  lm_reg_wr_ind(param_1,0x180224,0);
  lm_reg_wr_ind(param_1,0x180234,0);
  lm_reg_wr_ind(param_1,0x18024c,0);
  lm_reg_wr_ind(param_1,0x1802e4,0xff);
  lm_reg_wr_ind(param_1,0x1b8bc0,1);
  lm_reg_wr_ind(param_1,0x1b8000,0x34);
  lm_reg_wr_ind(param_1,0x1b8040,0x18);
  lm_reg_wr_ind(param_1,0x1b8080,0xc);
  lm_reg_wr_ind(param_1,0x1b80c0,0x20);
  iVar2 = 0x1a2000;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x1a22c8);
  iVar2 = 0x1a1530;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x1a1830);
  iVar2 = 0x1a1020;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x1a1340);
  lm_reg_wr_ind(param_1,0x1a1000,0);
  lm_reg_wr_ind(param_1,0x1a1004,0);
  return;
}



===== everest_init_ucm_common @ 140018ac4 =====

void everest_init_ucm_common(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  lm_reg_wr_ind(param_1,0xe004c,0x32);
  lm_reg_wr_ind(param_1,0xe0094,0x2150020);
  lm_reg_wr_ind(param_1,0xe0098,0x2150020);
  lm_reg_wr_ind(param_1,0xe009c,0x30);
  lm_reg_wr_ind(param_1,0xe00a0,0x8100000);
  lm_reg_wr_ind(param_1,0xe00a4,0x33);
  lm_reg_wr_ind(param_1,0xe00a8,0x30);
  lm_reg_wr_ind(param_1,0xe00ac,0x31);
  lm_reg_wr_ind(param_1,0xe00d8,1);
  lm_reg_wr_ind(param_1,0xe00e4,1);
  lm_reg_wr_ind(param_1,0xe0144,1);
  lm_reg_wr_ind(param_1,0xe014c,1);
  lm_reg_wr_ind(param_1,0xe0150,2);
  lm_reg_wr_ind(param_1,0xe0204,1);
  lm_reg_wr_ind(param_1,0xe020c,0x40);
  lm_reg_wr_ind(param_1,0xe0210,0x40);
  lm_reg_wr_ind(param_1,0xe021c,4);
  lm_reg_wr_ind(param_1,0xe0220,0x20);
  uVar1 = 0xe0300;
  do {
    lm_reg_wr_ind(param_1,uVar1,0);
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0xe0348);
  uVar3 = 0;
  uVar1 = 0xe0280;
  iVar2 = 0;
  do {
    if (uVar3 < 0x1b) {
      iVar4 = ((uVar3 + 1) % 0x1b) * 0x8000 + iVar2;
    }
    else {
      iVar4 = 0;
    }
    lm_reg_wr_ind(param_1,uVar1,iVar4);
    uVar3 = uVar3 + 1;
    iVar2 = iVar2 + 0x380;
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0xe0300);
  lm_reg_wr_ind(param_1,0xe0224,0xc);
  lm_reg_wr_ind(param_1,0xe0228,0x1b);
  lm_reg_wr_ind(param_1,0xe0054,10);
  lm_reg_wr_ind(param_1,0xe0004,1);
  lm_reg_wr_ind(param_1,0xe0008,1);
  lm_reg_wr_ind(param_1,0xe000c,1);
  lm_reg_wr_ind(param_1,0xe0010,1);
  lm_reg_wr_ind(param_1,0xe0014,1);
  lm_reg_wr_ind(param_1,0xe0018,1);
  lm_reg_wr_ind(param_1,0xe001c,1);
  lm_reg_wr_ind(param_1,0xe0020,1);
  lm_reg_wr_ind(param_1,0xe0024,1);
  lm_reg_wr_ind(param_1,0xe0028,1);
  lm_reg_wr_ind(param_1,0xe002c,1);
  lm_reg_wr_ind(param_1,0xe0030,1);
  lm_reg_wr_ind(param_1,0xe0034,1);
  lm_reg_wr_ind(param_1,0xe0038,1);
  lm_reg_wr_ind(param_1,0xe003c,1);
  lm_reg_wr_ind(param_1,0xe0040,1);
  lm_reg_wr_ind(param_1,0xe0044,1);
  return;
}



===== everest_init_usem_common @ 140018df0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_usem_common(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined1 auStack_78 [32];
  ushort local_58 [20];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[0] = 3;
  local_58[1] = 6;
  local_58[2] = 4;
  local_58[3] = 7;
  local_58[4] = 5;
  local_58[5] = 8;
  iVar2 = 0x300400;
  local_58[6] = 0x10;
  local_58[7] = 0xe;
  local_58[8] = 0x30;
  local_58[9] = 9;
  local_58[10] = 0x31;
  local_58[0xb] = 10;
  local_58[0xc] = 0x32;
  local_58[0xd] = 0xb;
  local_58[0xe] = 0x33;
  local_58[0xf] = 0xc;
  local_58[0x10] = 0x34;
  local_58[0x11] = 0xd;
  do {
    lm_reg_wr_ind(param_1,iVar2,0x7ff8);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x300800);
  uVar1 = 0;
  puVar3 = local_58;
  do {
    lm_reg_wr_ind(param_1,(uint)*puVar3 * 4 + 0x300400,(uint)puVar3[1]);
    uVar1 = uVar1 + 1;
    puVar3 = puVar3 + 2;
  } while (uVar1 < 9);
  iVar2 = 0x302000;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x304000);
  lm_reg_wr_ind(param_1,0x300020,1);
  lm_reg_wr_ind(param_1,0x300024,2);
  lm_reg_wr_ind(param_1,0x300028,3);
  lm_reg_wr_ind(param_1,0x30002c,0);
  lm_reg_wr_ind(param_1,0x300030,4);
  lm_reg_wr_ind(param_1,0x300034,0x12);
  lm_reg_wr_ind(param_1,0x300038,0);
  lm_reg_wr_ind(param_1,0x30003c,1);
  lm_reg_wr_ind(param_1,0x300040,4);
  lm_reg_wr_ind(param_1,0x300044,0);
  lm_reg_wr_ind(param_1,0x300048,1);
  lm_reg_wr_ind(param_1,0x30004c,3);
  lm_reg_wr_ind(param_1,0x300050,0);
  lm_reg_wr_ind(param_1,0x300054,1);
  lm_reg_wr_ind(param_1,0x300058,4);
  lm_reg_wr_ind(param_1,0x30005c,0);
  lm_reg_wr_ind(param_1,0x300060,1);
  lm_reg_wr_ind(param_1,0x300064,3);
  lm_reg_wr_ind(param_1,0x300068,0);
  lm_reg_wr_ind(param_1,0x30006c,1);
  lm_reg_wr_ind(param_1,0x300070,4);
  lm_reg_wr_ind(param_1,0x300074,0);
  lm_reg_wr_ind(param_1,0x300078,4);
  lm_reg_wr_ind(param_1,0x30007c,3);
  lm_reg_wr_ind(param_1,0x300080,0);
  lm_reg_wr_ind(param_1,0x300084,0);
  lm_reg_wr_ind(param_1,0x3000a4,0x3fff);
  lm_reg_wr_ind(param_1,0x3000a8,0x3ff);
  lm_reg_wr_ind(param_1,0x300224,0);
  lm_reg_wr_ind(param_1,0x300234,0);
  lm_reg_wr_ind(param_1,0x30024c,0);
  lm_reg_wr_ind(param_1,0x3002e4,0xffff);
  lm_reg_write_block(param_1,0x338bc0,(undefined4 *)&DAT_14002f4f0,1);
  lm_reg_write_block(param_1,0x338000,(undefined4 *)&DAT_14002f4f4,1);
  lm_reg_write_block(param_1,0x338040,(undefined4 *)&DAT_14002f4f8,1);
  lm_reg_write_block(param_1,0x338080,(undefined4 *)&DAT_14002f4fc,1);
  lm_reg_write_block(param_1,0x3380c0,(undefined4 *)&DAT_14002f500,1);
  iVar2 = 0x325000;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x325308);
  iVar2 = 0x321020;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x321340);
  lm_reg_write_block(param_1,0x321000,(undefined4 *)&DAT_14002f508,2);
  return;
}



===== everest_init_xcm_common @ 1400191d4 =====

void everest_init_xcm_common(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  lm_reg_wr_ind(param_1,0x20058,0x32);
  lm_reg_wr_ind(param_1,0x200a0,0x3150020);
  lm_reg_wr_ind(param_1,0x200a4,0x3150020);
  lm_reg_wr_ind(param_1,0x200a8,0x1000030);
  lm_reg_wr_ind(param_1,0x200ac,0x8100000);
  lm_reg_wr_ind(param_1,0x200b0,0x33);
  lm_reg_wr_ind(param_1,0x200b4,0x30);
  lm_reg_wr_ind(param_1,0x200b8,0x31);
  lm_reg_wr_ind(param_1,0x200f0,1);
  lm_reg_wr_ind(param_1,0x200fc,6);
  lm_reg_wr_ind(param_1,0x20120,0);
  lm_reg_wr_ind(param_1,0x20134,2);
  lm_reg_wr_ind(param_1,0x201b0,1);
  lm_reg_wr_ind(param_1,0x2020c,1);
  lm_reg_wr_ind(param_1,0x20214,1);
  lm_reg_wr_ind(param_1,0x20218,2);
  lm_reg_wr_ind(param_1,0x20404,1);
  lm_reg_wr_ind(param_1,0x2040c,0x40);
  lm_reg_wr_ind(param_1,0x20410,0x40);
  lm_reg_wr_ind(param_1,0x2041c,4);
  lm_reg_wr_ind(param_1,0x20428,0x1f);
  uVar2 = 0x20500;
  do {
    lm_reg_wr_ind(param_1,uVar2,0);
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x20548);
  uVar3 = 0;
  uVar1 = 0x20480;
  uVar2 = uVar3;
  do {
    uVar3 = uVar3 + 1;
    lm_reg_wr_ind(param_1,uVar1,(uVar3 & 0x1f) * 0x1000 + uVar2);
    uVar2 = uVar2 + 0x80;
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x20500);
  lm_reg_wr_ind(param_1,0x20420,2);
  lm_reg_wr_ind(param_1,0x20424,2);
  lm_reg_wr_ind(param_1,0x20060,0xf);
  lm_reg_wr_ind(param_1,0x200f4,4);
  lm_reg_wr_ind(param_1,0x20004,1);
  lm_reg_wr_ind(param_1,0x20008,1);
  lm_reg_wr_ind(param_1,0x2000c,1);
  lm_reg_wr_ind(param_1,0x20010,1);
  lm_reg_wr_ind(param_1,0x20014,1);
  lm_reg_wr_ind(param_1,0x20018,1);
  lm_reg_wr_ind(param_1,0x2001c,1);
  lm_reg_wr_ind(param_1,0x20020,1);
  lm_reg_wr_ind(param_1,0x20024,1);
  lm_reg_wr_ind(param_1,0x20028,1);
  lm_reg_wr_ind(param_1,0x2002c,1);
  lm_reg_wr_ind(param_1,0x20030,1);
  lm_reg_wr_ind(param_1,0x20034,1);
  lm_reg_wr_ind(param_1,0x20038,1);
  lm_reg_wr_ind(param_1,0x2003c,1);
  lm_reg_wr_ind(param_1,0x20040,1);
  lm_reg_wr_ind(param_1,0x20044,1);
  lm_reg_wr_ind(param_1,0x20048,1);
  lm_reg_wr_ind(param_1,0x2004c,1);
  lm_reg_wr_ind(param_1,0x20050,1);
  return;
}



===== everest_init_xcm_port @ 140019558 =====

void everest_init_xcm_port(longlong param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x138);
  lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x20108,200);
  lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x20118,2);
  lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x201c4,0);
  lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x201cc,1);
  lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x201d4,2);
  lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x201dc,2);
  lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x201ec,1);
  return;
}



===== everest_init_xsem_common @ 140019638 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void everest_init_xsem_common(longlong param_1)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  undefined1 auStack_88 [32];
  ushort local_68 [24];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  uVar1 = 0;
  local_68[0] = 0;
  local_68[1] = 9;
  local_68[2] = 4;
  local_68[3] = 10;
  local_68[4] = 5;
  local_68[5] = 0xb;
  iVar2 = 0x280400;
  local_68[6] = 0x10;
  local_68[7] = 6;
  local_68[8] = 0x11;
  local_68[9] = 7;
  local_68[10] = 0x12;
  local_68[0xb] = 8;
  local_68[0xc] = 0x30;
  local_68[0xd] = 0xc;
  local_68[0xe] = 0x31;
  local_68[0xf] = 0xd;
  local_68[0x10] = 0x32;
  local_68[0x11] = 0xe;
  local_68[0x12] = 0x33;
  local_68[0x13] = 0xf;
  local_68[0x14] = 0x34;
  local_68[0x15] = 0x10;
  do {
    lm_reg_wr_ind(param_1,iVar2,0x7ff8);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x280800);
  puVar3 = local_68;
  do {
    lm_reg_wr_ind(param_1,(uint)*puVar3 * 4 + 0x280400,(uint)puVar3[1]);
    uVar1 = uVar1 + 1;
    puVar3 = puVar3 + 2;
  } while (uVar1 < 0xb);
  iVar2 = 0x282000;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x284000);
  lm_reg_wr_ind(param_1,0x280020,1);
  lm_reg_wr_ind(param_1,0x280024,2);
  lm_reg_wr_ind(param_1,0x280028,3);
  lm_reg_wr_ind(param_1,0x28002c,0);
  lm_reg_wr_ind(param_1,0x280030,4);
  lm_reg_wr_ind(param_1,0x280034,0x12);
  lm_reg_wr_ind(param_1,0x280038,0);
  lm_reg_wr_ind(param_1,0x28003c,1);
  lm_reg_wr_ind(param_1,0x280040,4);
  lm_reg_wr_ind(param_1,0x280044,0);
  lm_reg_wr_ind(param_1,0x280048,1);
  lm_reg_wr_ind(param_1,0x28004c,3);
  lm_reg_wr_ind(param_1,0x280050,0);
  lm_reg_wr_ind(param_1,0x280054,1);
  lm_reg_wr_ind(param_1,0x280058,4);
  lm_reg_wr_ind(param_1,0x28005c,0);
  lm_reg_wr_ind(param_1,0x280060,1);
  lm_reg_wr_ind(param_1,0x280064,3);
  lm_reg_wr_ind(param_1,0x280068,0);
  lm_reg_wr_ind(param_1,0x28006c,1);
  lm_reg_wr_ind(param_1,0x280070,4);
  lm_reg_wr_ind(param_1,0x280074,0);
  lm_reg_wr_ind(param_1,0x280078,4);
  lm_reg_wr_ind(param_1,0x28007c,3);
  lm_reg_wr_ind(param_1,0x280080,0);
  lm_reg_wr_ind(param_1,0x280084,0);
  lm_reg_wr_ind(param_1,0x2800a4,0x3fff);
  lm_reg_wr_ind(param_1,0x2800a8,0x3ff);
  lm_reg_wr_ind(param_1,0x280224,0);
  lm_reg_wr_ind(param_1,0x280234,0);
  lm_reg_wr_ind(param_1,0x28024c,0);
  lm_reg_wr_ind(param_1,0x2802e4,0xffff);
  lm_reg_wr_ind(param_1,0x2b8bc0,1);
  lm_reg_wr_ind(param_1,0x2b8000,0);
  lm_reg_wr_ind(param_1,0x2b8040,0x18);
  lm_reg_wr_ind(param_1,0x2b8080,0xc);
  lm_reg_wr_ind(param_1,0x2b80c0,0x66);
  iVar2 = 0x2a5000;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2a5120);
  lm_reg_wr_ind(param_1,0x2a5120,0x402400);
  lm_reg_wr_ind(param_1,0x2a5124,0x1402400);
  iVar2 = 0x2a1020;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2a1340);
  iVar2 = 0x2a1000;
  do {
    lm_reg_wr_ind(param_1,iVar2,0);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2a1008);
  iVar2 = 0x2a5178;
  do {
    lm_reg_wr_ind(param_1,iVar2,0xffffffff);
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x2a5180);
  if ((*(uint *)(param_1 + 0x58) & 0x20000) != 0) {
    lm_reg_wr_ind(param_1,0x2a516c,1);
  }
  return;
}



===== lm_ack_enable_intr @ 140019a6c =====

void lm_ack_enable_intr(longlong param_1)

{
  ushort uVar1;
  undefined8 uVar2;
  
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 == 0) {
    uVar1 = *(ushort *)(param_1 + 0x6c);
    if ((uVar1 & 0x10) != 0) {
      lm_intr_ack_sb(param_1,*(byte *)(param_1 + 0xb0),3,*(ushort *)(param_1 + 0x6a),0,1);
      uVar1 = *(ushort *)(param_1 + 0x6c);
    }
    if ((uVar1 & 8) != 0) {
      lm_intr_ack_sb(param_1,*(byte *)(param_1 + 0xb0),2,*(ushort *)(param_1 + 0x68),0,1);
    }
  }
  uVar1 = *(ushort *)(param_1 + 0x6c);
  if ((uVar1 & 2) != 0) {
    lm_intr_ack_sb(param_1,*(byte *)(param_1 + 0xb0),0,*(ushort *)(param_1 + 0x66),0,1);
    uVar1 = *(ushort *)(param_1 + 0x6c);
  }
  if ((uVar1 & 4) != 0) {
    lm_intr_ack_sb(param_1,*(byte *)(param_1 + 0xb0),1,*(ushort *)(param_1 + 100),0,1);
  }
  *(undefined2 *)(param_1 + 0x6c) = 0;
  return;
}



===== lm_acquire_mdio_hw_lock @ 140019b34 =====

undefined8 lm_acquire_mdio_hw_lock(longlong param_1,int param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x74);
  if (iVar1 == 0) {
    uVar4 = -(uint)(param_2 != 0) & 10000;
    iVar1 = (uint)*(byte *)(param_1 + 0x13a) * 8;
    do {
      lm_reg_wr_ind(param_1,iVar1 + 0xa514,1);
      uVar2 = lm_reg_read_ind(param_1,iVar1 + 0xa510);
      if ((uVar2 & 1) != 0) {
        iVar1 = *(int *)(param_1 + 0x74);
        goto LAB_140019ba4;
      }
      if (0 < (int)uVar4) {
        mm_stall(1000);
      }
      uVar4 = uVar4 - 1;
    } while (-1 < (int)uVar4);
    uVar3 = 0xffffffff;
  }
  else {
LAB_140019ba4:
    *(int *)(param_1 + 0x74) = iVar1 + 1;
    uVar3 = 0;
  }
  return uVar3;
}



===== lm_bcm8073_external_rom_boot @ 140019bc0 =====

void lm_bcm8073_external_rom_boot(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  
  mm_stall(100000);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,1);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x8c);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca85,1);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x18a);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x188);
  mm_stall(100000);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca85,0);
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca02);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca02,uVar1 | 0x400)
  ;
  lVar2 = 1000;
  do {
    mm_stall(1000);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca02,uVar1 & 0xfbff
             );
  mm_stall(200000);
  return;
}



===== lm_bcm8073_load_spi_rom @ 140019da8 =====

void lm_bcm8073_load_spi_rom(longlong param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  longlong lVar4;
  int iVar5;
  byte local_res8 [8];
  ushort local_res10 [4];
  
  bVar1 = *(byte *)(param_1 + 0x138);
  uVar2 = *(ushort *)(param_1 + 300);
  local_res10[1] = *(ushort *)(param_1 + 0x12e);
  iVar5 = 0;
  if (local_res10[1] < uVar2) {
    local_res8[0] = bVar1;
    local_res10[0] = uVar2;
    local_res8[1] = bVar1 ^ 1;
  }
  else {
    local_res8[0] = bVar1 ^ 1;
    local_res10[0] = local_res10[1];
    local_res8[1] = bVar1;
    local_res10[1] = uVar2;
  }
  lVar4 = 0;
  do {
    *(byte *)(param_1 + 0x138) = local_res8[lVar4];
    *(ushort *)(param_1 + 300) = local_res10[lVar4];
    lm_reset_ext_phy(param_1);
    sVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca19);
    if (sVar3 == 0x4321) {
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0,0x8000);
      mm_stall(100);
      lm_bcm8073_external_rom_boot(param_1);
      iVar5 = iVar5 + 1;
    }
    lVar4 = lVar4 + 1;
  } while (lVar4 < 2);
  *(byte *)(param_1 + 0x138) = bVar1;
  *(ushort *)(param_1 + 300) = uVar2;
  if ((iVar5 != 0) && (*(short *)(param_1 + 0x130) == 0x900)) {
    mm_stall(1000000);
  }
  return;
}



===== lm_bcm8726_set_limiting_mode @ 140019ee8 =====

void lm_bcm8726_set_limiting_mode(longlong param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar2 = lm_phy_872x_read_sfp_module_eeprom(param_1,0x40);
  uVar4 = *(ushort *)(param_1 + 300);
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xca1a;
    uVar1 = 0x44;
  }
  else {
    uVar3 = 0xca3f;
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),uVar4,1,0xca3f,0);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca1a,0x123);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca23,0x4008);
    uVar4 = *(ushort *)(param_1 + 300);
    uVar1 = 0xaaaa;
  }
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),uVar4,1,uVar3,uVar1);
  return;
}



===== lm_bcm8727_set_edc_mode @ 140019fd4 =====

void lm_bcm8727_set_edc_mode(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ushort uVar5;
  
  uVar5 = 0x44;
  uVar3 = lm_phy_872x_read_sfp_module_eeprom(param_1,2);
  if ((char)uVar3 != '\a') {
    if ((char)uVar3 != '!') goto LAB_14001a034;
    uVar4 = lm_phy_872x_read_sfp_module_eeprom(param_1,8);
    if ((uVar4 & 4) != 0) {
      uVar5 = 0x55;
      goto LAB_14001a034;
    }
  }
  uVar4 = lm_phy_872x_read_sfp_module_eeprom(param_1,0x40);
  if ((uVar4 & 1) != 0) {
    uVar5 = 0x22;
  }
LAB_14001a034:
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800,uVar1 & 0xfdff
             );
  uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca1a);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca1a,
              uVar2 & 0xff00 | uVar5);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800,
              uVar1 & 0xfdff | 0x200);
  mm_stall(2000000);
  return;
}



===== lm_chip_init @ 14001a12c =====

undefined8 lm_chip_init(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined7 extraout_var;
  undefined8 local_res8;
  
  bVar1 = param_1[0x13b];
  lm_retrieve_phy_info((longlong)param_1);
  uVar3 = lm_issue_fw_command((longlong)param_1,0x10000000);
  lm_reg_wr_ind(param_1,*(int *)(param_1 + 0x4c) + (uint)bVar1 * 0x2c + 0x694,0x8000);
  if ((*(uint *)(param_1 + 0x58) & 0x200) != 0) {
    lm_reg_wr_ind(param_1,*(int *)(param_1 + 0x50) + 0x74,0x9001);
  }
  lm_init_fw_offsets((longlong)param_1);
  uVar4 = *(uint *)(param_1 + 0x58);
  if (((uVar4 >> 0x11 & 1) == 0) || (uVar3 != 0x10120000)) {
    uVar4 = uVar4 | 0x10000;
  }
  else {
    uVar4 = uVar4 & 0xfffeffff;
  }
  *(uint *)(param_1 + 0x58) = uVar4 | 0x10;
  uVar5 = lm_init_common_part((longlong)param_1);
  if ((int)uVar5 == 1) {
    lm_shutdown(param_1);
  }
  else {
    lm_init_function_part((longlong)param_1);
    lm_init_status_blocks((longlong)param_1);
    param_1[0x6d8] = 0;
    param_1[0x6e8] = 0;
    param_1[0x6e9] = 0;
    mm_alloc_sp_ring((longlong)param_1);
    lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 0xbc),*(undefined4 *)(param_1 + 0x6f0));
    lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xbc) + 4,*(undefined4 *)(param_1 + 0x6f4));
    if (*(short *)(param_1 + 0x38) == 0) {
      local_res8 = 0x5fc01b80000;
    }
    else {
      local_res8 = 0x5fc01b80001;
    }
    lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 200),(undefined4)local_res8);
    lm_reg_wr_ind(param_1,*(int *)(param_1 + 200) + 4,local_res8._4_4_);
    lm_reg_wr_ind(param_1,0x325308,*(undefined4 *)(param_1 + 0x90));
    lm_reg_wr_ind(param_1,0x32530c,*(undefined4 *)(param_1 + 0x94));
    ev_lm_post_buffers((longlong)param_1);
    bVar2 = lm_sp_post_and_wait((longlong)param_1,0x50,0,0,0);
    if (((int)CONCAT71(extraout_var,bVar2) != 1) &&
       (uVar3 = lm_issue_fw_command((longlong)param_1,0x11000000), uVar3 == 0x11100000)) {
      lm_set_mac_addrs((longlong)param_1);
      bVar1 = param_1[0x138];
      uVar4 = -(uint)(bVar1 != 0) & 4;
      uVar3 = lm_reg_read_ind(param_1,uVar4 + 0x16050);
      lm_reg_wr_ind(param_1,uVar4 + 0x16050,uVar3 | 4);
      lm_reg_wr_ind(param_1,(-(uint)(bVar1 != 0) & 4) + 0x10244,0x1f);
      lm_reg_wr_ind(param_1,(-(uint)(bVar1 != 0) & 0x80) + 0x1025c,1);
      lm_reg_wr_ind(param_1,0xa45c,0xffffffff);
      return 0;
    }
  }
  return 1;
}



===== lm_chip_reset_all_blocks @ 14001a380 =====

void lm_chip_reset_all_blocks(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = lm_reg_read_ind(param_1,0x10394);
  uVar2 = lm_reg_read_ind(param_1,0x10398);
  uVar4 = *(uint *)(param_1 + 0x58) & 0xc;
  if (uVar4 == 0) {
    lm_shutdown_mgmt_to_mcp(param_1);
  }
  lm_reg_wr_ind(param_1,0xa588,(-(uint)(uVar4 != 0) & 0xffffff80) + 0xd3ffffff);
  lm_reg_wr_ind(param_1,0xa598,0x1403);
  mm_stall(100);
  lm_reg_wr_ind(param_1,0xa584,0xffffffff);
  lm_reg_wr_ind(param_1,0xa594,0xfffc);
  iVar3 = 0x1025c;
  iVar5 = 0x10244;
  do {
    lm_reg_wr_ind(param_1,iVar5,0);
    lm_reg_wr_ind(param_1,iVar3,0);
    iVar5 = iVar5 + 4;
    iVar3 = iVar3 + 0x80;
  } while (iVar5 < 0x1024c);
  if ((*(uint *)(param_1 + 0x58) & 0xc) == 0) {
    lm_reg_wr_ind(param_1,0xa584,0x80);
  }
  lm_reg_wr_ind(param_1,0x10394,uVar1);
  lm_reg_wr_ind(param_1,0x10398,uVar2);
  return;
}



===== lm_ctrl_epio @ 14001a4ac =====

void lm_ctrl_epio(undefined8 param_1,byte param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 1 << (param_2 & 0x1f);
  uVar1 = lm_reg_read_ind(param_1,0x800c4);
  if (param_3 == 0) {
    uVar1 = uVar1 & ~uVar2;
  }
  else {
    uVar1 = uVar1 | uVar2;
  }
  lm_reg_wr_ind(param_1,0x800c4,uVar1);
  uVar1 = lm_reg_read_ind(param_1,0x800c8);
  lm_reg_wr_ind(param_1,0x800c8,uVar1 | uVar2);
  return;
}



===== lm_ctrl_pin_cfg @ 14001a524 =====

void lm_ctrl_pin_cfg(undefined8 param_1,ushort param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  
  if (param_2 != 0) {
    cVar2 = (char)param_2;
    if (8 < param_2) {
      lm_ctrl_epio(param_1,cVar2 - 9,param_3);
      return;
    }
    bVar1 = 3 < (ushort)(param_2 - 1);
    if (bVar1) {
      cVar2 = cVar2 + -5;
    }
    else {
      cVar2 = cVar2 + -1;
    }
    lm_gpio_write(param_1,bVar1,cVar2,(char)param_3);
  }
  return;
}



===== lm_disable_mac @ 14001a570 =====

void lm_disable_mac(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = lm_is_e3(param_1);
  if ((int)uVar2 == 0) {
    uVar1 = (uint)*(byte *)(param_1 + 0x138);
    lm_reg_wr_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 4 + 0x100ac,0);
    lm_reg_wr_ind(param_1,uVar1 * 4 + 0x100e0,0);
    lm_reg_wr_ind(param_1,uVar1 * 4 + 0x1003c,0);
    lm_reg_wr_ind(param_1,uVar1 * 4 + 0x100a4,0);
    lm_reg_wr_ind(param_1,uVar1 * 4 + 0x10120,0);
  }
  lm_set_xumac_nig(param_1,0,0);
  return;
}



===== lm_e3_imc_done @ 14001a600 =====

bool lm_e3_imc_done(undefined8 param_1,ulonglong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = (uint)((param_2 & 0xffffffff) / 10);
  if (uVar3 != 0) {
    do {
      uVar1 = lm_reg_read_ind(param_1,0x85900);
      if ((uVar1 & 0x30000) == 0x10000) break;
      mm_stall(10);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  return uVar2 < uVar3;
}



===== lm_enable_bmac @ 14001a664 =====

void lm_enable_bmac(longlong param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  bVar2 = *(byte *)(param_1 + 0x138);
  uVar3 = lm_is_dual_core(param_1);
  if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
    uVar6 = (uint)bVar2;
    lm_reg_wr_ind(param_1,0xa594,1 << (bVar2 & 0x1f));
    uVar4 = lm_is_e3(param_1);
    if ((int)uVar4 == 0) {
      lm_reg_wr_ind(param_1,(uint)bVar2 * 4 + 0x100e8,1);
      uVar7 = -(uint)(bVar2 != 0) & 0x400;
      iVar5 = uVar7 + 0x10c00;
      lm_reg_wr_ind(param_1,iVar5,0);
      iVar1 = uVar7 + 0x10c04;
      lm_reg_wr_ind(param_1,iVar1,0);
      lm_reg_wr_ind(param_1,uVar7 + 0x10c08,0x3c);
      lm_reg_wr_ind(param_1,uVar7 + 0x10c0c,0);
      if ((int)uVar3 == 0) {
        uVar8 = 0x8000c0;
        if (*(int *)(param_1 + 0x10) != 2) {
          uVar8 = 0xc0;
        }
        lm_reg_wr_ind(param_1,uVar7 + 0x10c38,uVar8);
        lm_reg_wr_ind(param_1,uVar7 + 0x10c3c,0);
        lm_reg_wr_ind(param_1,iVar5,(-(uint)(param_2 != 0) & 4) + 3);
        lm_reg_wr_ind(param_1,iVar1,0);
        lm_reg_wr_ind(param_1,uVar7 + 0x10d18,0x600);
        lm_reg_wr_ind(param_1,uVar7 + 0x10d1c,0);
        uVar8 = 0x34;
        if (*(int *)(param_1 + 0x10) != 1) {
          uVar8 = 0x14;
        }
        lm_reg_wr_ind(param_1,uVar7 + 0x10d08,uVar8);
        lm_reg_wr_ind(param_1,uVar7 + 0x10d0c,0);
        lm_reg_wr_ind(param_1,uVar7 + 0x10c48,0x600);
        lm_reg_wr_ind(param_1,uVar7 + 0x10c4c,0);
        lm_reg_wr_ind(param_1,uVar7 + 0x10c28,0x600);
        iVar5 = uVar7 + 0x10c2c;
      }
      else {
        uVar8 = 0x8000c0;
        if (*(int *)(param_1 + 0x10) != 2) {
          uVar8 = 0xc0;
        }
        lm_reg_wr_ind(param_1,uVar7 + 0x10ce0,uVar8);
        lm_reg_wr_ind(param_1,uVar7 + 0x10ce4,0);
        lm_reg_wr_ind(param_1,iVar5,(-(uint)(param_2 != 0) & 4) + 3);
        lm_reg_wr_ind(param_1,iVar1,0);
        lm_reg_wr_ind(param_1,uVar7 + 0x10de0,0x600);
        lm_reg_wr_ind(param_1,uVar7 + 0x10de4,0);
        lm_reg_wr_ind(param_1,uVar7 + 0x10cf0,0x600);
        iVar5 = uVar7 + 0x10cf4;
      }
      lm_reg_wr_ind(param_1,iVar5,0);
    }
    lm_reg_wr_ind(param_1,uVar6 * 4 + 0x10058,0);
    uVar3 = lm_is_e3(param_1);
    if ((int)uVar3 == 0) {
      lm_reg_wr_ind(param_1,uVar6 * 4 + 0x102e8,0);
      lm_reg_wr_ind(param_1,uVar6 * 4 + 0x102e0,1);
      lm_reg_wr_ind(param_1,uVar6 * 4 + 0x10120,0);
      lm_reg_wr_ind(param_1,uVar6 * 4 + 0x10110,1);
      lm_reg_wr_ind(param_1,uVar6 * 4 + 0x100a4,0);
      lm_reg_wr_ind(param_1,uVar6 * 4 + 0x100ac,1);
      lm_reg_wr_ind(param_1,uVar6 * 4 + 0x100e0,1);
      lm_reg_wr_ind(param_1,uVar6 * 4 + 0x10118,0);
    }
    lm_reg_wr_ind(param_1,uVar6 * 4 + 0x100f0,0);
  }
  else {
    lm_enable_xmac(param_1,param_2);
  }
  return;
}



===== lm_enable_emac @ 14001a9b8 =====

void lm_enable_emac(longlong param_1)

{
  byte bVar1;
  undefined8 uVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  uVar2 = lm_is_e3(param_1);
  if ((int)uVar2 != 0) {
    iVar3 = 0x100000 << (bVar1 & 0x1f);
    lm_reg_wr_ind(param_1,0xa598,iVar3);
    mm_stall(1000);
    lm_reg_wr_ind(param_1,0xa594,iVar3);
    lm_reg_bits_en(param_1,0xa000,0x590,0x1000000 << (bVar1 & 0x1f));
  }
  lm_reg_bits_en(param_1,0xa000,0x590,0x4000 << (bVar1 & 0x1f));
  mm_stall(1000);
  lm_reg_wr_ind(param_1,(-(uint)(bVar1 != 0) & 0x400) + 0x80c8,0x500);
  uVar2 = lm_is_e3(param_1);
  if ((int)uVar2 == 0) {
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x102e8,0);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x102e0,1);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x1003c,1);
  }
  lm_reg_wr_ind(param_1,(-(uint)(bVar1 != 0) & 0x400) + 0x809c,0x600);
  lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10058,1);
  uVar2 = lm_is_e3(param_1);
  if ((int)uVar2 == 0) {
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10044,1);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x100ac,0);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x100e0,0);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10110,0);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x100a4,1);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10118,1);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10120,1);
  }
  lm_set_xumac_nig(param_1,1,1);
  return;
}



===== lm_enable_xmac @ 14001ab94 =====

void lm_enable_xmac(longlong param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  uVar5 = -(uint)(bVar1 != 0) & 0x800;
  uVar6 = -(uint)(bVar1 != 0) & 0xfffff800;
  uVar2 = lm_reg_read_ind(param_1,uVar6 + 0x163800);
  if ((uVar2 & 0x40) == 0) {
    iVar3 = lm_reg_read_ind(param_1,uVar6 + 0x163840);
    iVar4 = lm_reg_read_ind(param_1,uVar6 + 0x163820);
  }
  else {
    iVar3 = param_2;
    iVar4 = param_2;
  }
  lm_reg_wr_ind(param_1,0xa594,0x1000000 << (*(byte *)(param_1 + 0x138) & 0x1f));
  lm_reg_wr_ind(param_1,0xa598,0x400000);
  mm_stall(1000);
  lm_reg_wr_ind(param_1,0xa594,0x400000);
  if (*(char *)(param_1 + 0x158) == '\0') {
    lm_reg_wr_ind(param_1,0xa964,1);
    uVar7 = 3;
  }
  else {
    lm_reg_wr_ind(param_1,0xa964,0);
    uVar7 = 3;
    if ((*(uint *)(param_1 + 0xc) & 0xff00) == 0x700) {
      uVar7 = 1;
    }
  }
  lm_reg_wr_ind(param_1,0xa960,uVar7);
  lm_reg_wr_ind(param_1,0xa598,0x800000);
  mm_stall(1000);
  lm_reg_wr_ind(param_1,0xa594,0x800000);
  if ((uVar2 & 0x40) == 0) {
    lm_reg_wr_ind(param_1,uVar6 + 0x163840,iVar3);
    lm_reg_wr_ind(param_1,uVar6 + 0x163820,iVar4);
    lm_reg_wr_ind(param_1,uVar6 + 0x163800,uVar2);
  }
  lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10058,0);
  lm_reg_wr_ind(param_1,uVar5 + 0x163040,0x600);
  lm_reg_wr_ind(param_1,uVar5 + 0x163020,0xc800);
  uVar6 = (-(uint)(param_2 != 0) & 4) + 3;
  uVar2 = uVar6 | 0x80;
  if ((*(uint *)(param_1 + 0xc) & 0xff00) != 0x700) {
    uVar2 = uVar6;
  }
  lm_reg_wr_ind(param_1,uVar5 + 0x163000,uVar2);
  lm_set_xumac_nig(param_1,1,1);
  return;
}



===== lm_extract_vntag_info @ 14001adac =====

void lm_extract_vntag_info(longlong param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if ((*(uint *)(param_1 + 0x58) & 0x200) != 0) {
    bVar1 = *(byte *)(param_1 + 0x13c);
    *(undefined2 *)(param_1 + 0x38) = 0;
    bVar2 = false;
    iVar5 = 0;
    do {
      uVar3 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + (bVar1 + 2) * 0x18);
      *(short *)(param_1 + 0x3c) = (short)uVar3;
      uVar4 = lm_reg_read_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 0x2c +
                                      *(int *)(param_1 + 0x4c) + 0x6a4);
      if ((uVar4 >> 0x17 & 1) != 0) {
        lm_issue_fw_command(param_1,0xd4000000);
        bVar2 = true;
      }
      if ((uVar4 >> 0x15 & 1) != 0) {
        lm_issue_fw_command(param_1,0xd2000000);
      }
      if (((10000 < iVar5) && (*(short *)(param_1 + 0x3c) != -1)) && (bVar2)) break;
      mm_stall(1000);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 20000);
    *(short *)(param_1 + 0x3e) = (short)(uVar3 >> 0x10);
    if (*(int *)(param_1 + 0x34) == 0) {
      *(uint *)(param_1 + 0x34) = uVar3 >> 0x10;
    }
  }
  return;
}



===== lm_flush_rx_buffers @ 14001aebc =====

uint lm_flush_rx_buffers(longlong param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar4;
  uint uVar3;
  uint uVar5;
  
  uVar5 = 0;
  uVar1 = ev_lm_get_interrupt_status(param_1);
  if ((((uVar1 & 2) != 0) && (*(short **)(param_1 + 0x6b0) != (short *)0x0)) &&
     (**(short **)(param_1 + 0x6b0) != *(short *)(param_1 + 0x69a))) {
    do {
      ev_lm_service_rx_intr(param_1);
      iVar2 = *(int *)(param_1 + 0x5f0);
      if (iVar2 == *(int *)(param_1 + 0x5f4)) break;
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0x5f8);
      }
      *(uint *)(param_1 + 0x5f0) = iVar2 - 1U;
      *(int *)(param_1 + 0x5fc) = *(int *)(param_1 + 0x5fc) + -1;
      iVar4 = *(int *)(param_1 + 0x4d4);
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x4d8);
      }
      uVar3 = iVar4 - 1;
      if (uVar3 != *(uint *)(param_1 + 0x4d0)) {
        *(undefined8 *)(param_1 + 0x4e0 + (ulonglong)uVar3 * 8) =
             *(undefined8 *)(param_1 + 0x600 + (ulonglong)(iVar2 - 1U) * 8);
        *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
        *(uint *)(param_1 + 0x4d4) = uVar3;
      }
      ev_lm_post_buffers(param_1);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 0x1e);
  }
  return uVar5 & 0xffff;
}



===== lm_get_basic_hw_info @ 14001af74 =====

bool lm_get_basic_hw_info(longlong param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  short sVar11;
  int iVar12;
  char cVar13;
  
  uVar3 = storport_pci_cfg_read_dword(param_1,0);
  *(short *)(param_1 + 0xf8) = (short)uVar3;
  *(short *)(param_1 + 0xfa) = (short)((uint)uVar3 >> 0x10);
  uVar3 = storport_pci_cfg_read_dword(param_1,0x2c);
  *(short *)(param_1 + 0xfe) = (short)uVar3;
  *(short *)(param_1 + 0xfc) = (short)((uint)uVar3 >> 0x10);
  uVar3 = storport_pci_cfg_read_dword(param_1,0x3c);
  *(char *)(param_1 + 0x100) = (char)uVar3;
  *(char *)(param_1 + 0x101) = (char)((uint)uVar3 >> 8);
  uVar3 = storport_pci_cfg_read_dword(param_1,0xc);
  *(char *)(param_1 + 0x102) = (char)uVar3;
  uVar3 = storport_pci_cfg_read_dword(param_1,8);
  *(char *)(param_1 + 0x103) = (char)uVar3;
  uVar3 = storport_pci_cfg_read_dword(param_1,0x10);
  *(undefined4 *)(param_1 + 0x108) = uVar3;
  uVar3 = storport_pci_cfg_read_dword(param_1,0x14);
  *(undefined4 *)(param_1 + 0x10c) = uVar3;
  iVar4 = lm_reg_read_ind(param_1,0xa408);
  uVar5 = lm_reg_read_ind(param_1,0xa40c);
  uVar6 = lm_reg_read_ind(param_1,0xa404);
  lm_reg_read_ind(param_1,0xa400);
  *(uint *)(param_1 + 0x124) =
       (uVar6 & 0xff) << 4 | uVar6 & 0xf | iVar4 << 0x10 | (uVar5 & 0xf) << 0xc;
  uVar5 = storport_pci_cfg_read_dword(param_1,4);
  storport_pci_cfg_write_dword(param_1,4,uVar5 | 4);
  iVar4 = storport_pci_cfg_read_dword(param_1,0x98);
  if (iVar4 == -1) {
    iVar4 = 1;
  }
  uVar7 = lm_is_dual_core(param_1);
  iVar8 = 0;
  bVar9 = (byte)((uint)iVar4 >> 0x10);
  if ((int)uVar7 == 0) {
    bVar10 = (byte)iVar4;
  }
  else {
    bVar10 = bVar9;
  }
  *(byte *)(param_1 + 0x13d) = bVar10 & 7;
  bVar9 = bVar9 & 1;
  bVar10 = (byte)iVar4 & 1;
  *(byte *)(param_1 + 0x139) = bVar9;
  *(byte *)(param_1 + 0x138) = bVar10;
  *(undefined1 *)(param_1 + 0x158) = 2;
  cVar13 = '\x02';
  uVar7 = lm_is_dual_core(param_1);
  if ((int)uVar7 != 0) {
    uVar5 = lm_reg_read_ind(param_1,0xa720);
    if ((uVar5 & 1) == 0) {
      uVar5 = lm_reg_read_ind(param_1,0xa750);
    }
    else {
      uVar5 = uVar5 >> 1 & 1;
    }
    bVar9 = *(byte *)(param_1 + 0x139);
    cVar13 = uVar5 == 0;
    bVar10 = *(byte *)(param_1 + 0x138);
    *(char *)(param_1 + 0x158) = cVar13;
  }
  if (cVar13 == '\0') {
    bVar1 = *(byte *)(param_1 + 0x13d) >> 1;
    *(byte *)(param_1 + 0x13e) = bVar1;
    bVar10 = bVar10 * '\x02';
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x13d) & 6;
    *(byte *)(param_1 + 0x13e) = bVar1;
    bVar1 = bVar1 >> 1;
  }
  *(byte *)(param_1 + 0x13a) = bVar9 | bVar10;
  *(byte *)(param_1 + 0x13b) = bVar1;
  uVar3 = lm_reg_read_ind(param_1,0xa2b4);
  *(undefined4 *)(param_1 + 0x4c) = uVar3;
  if ((*(uint *)(param_1 + 0x124) & 0xffff0000) != 0x164e0000) {
    uVar3 = 0xa460;
    if (*(char *)(param_1 + 0x139) != '\0') {
      uVar3 = 0xa464;
    }
    uVar3 = lm_reg_read_ind(param_1,uVar3);
    *(undefined4 *)(param_1 + 0x50) = uVar3;
  }
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x4c) + 0x7e4;
  if (((*(int *)(param_1 + 0x50) != 0) &&
      (uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x50)), 0xb < uVar5)) &&
     (iVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x50) + 0x10), iVar4 != 0)) {
    *(int *)(param_1 + 0x54) = iVar4;
  }
  bVar9 = *(byte *)(param_1 + 0x13d);
  *(byte *)(param_1 + 0x13c) = bVar9;
  uVar2 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354);
  *(ushort *)(param_1 + 0xec) = uVar2 & 0x700;
  if (((uVar2 & 0x700) - 0x500 & 0xfdff) == 0) {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x20000;
  }
  uVar7 = lm_is_mf_device(param_1);
  if (((int)uVar7 != 0) &&
     ((uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x368 +
                                       (*(byte *)(param_1 + 0x13d) >> 1 & 1) * 0x74),
      *(short *)(param_1 + 0xec) != 0x600 || ((uVar5 & 0x700000) != 0x100000)))) {
    iVar12 = (bVar9 + 2) * 0x18;
    iVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + iVar12);
    sVar11 = (short)iVar4;
    if ((*(short *)(param_1 + 0xec) == 0x500) && ((sVar11 == -1 || (iVar4 == 0)))) {
      do {
        iVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + iVar12);
        sVar11 = (short)iVar4;
        if ((sVar11 != -1) && (iVar4 != 0)) break;
        mm_stall(1000000);
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0x3c);
    }
    if (sVar11 != -1) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x24000;
      *(short *)(param_1 + 0x38) = sVar11;
    }
  }
  uVar5 = *(uint *)(param_1 + 0x58);
  if ((uVar5 >> 0x11 & 1) != 0) {
    if (1 < (*(byte *)(param_1 + 0x16c) & 7)) {
      uVar5 = uVar5 | 0x400;
      *(uint *)(param_1 + 0x58) = uVar5;
      *(byte *)(param_1 + 0x13c) = *(byte *)(param_1 + 0x16c) & 7;
    }
    if (1 < *(byte *)(param_1 + 0x13d)) {
      *(uint *)(param_1 + 0x58) = uVar5 | 0x8000;
    }
  }
  return *(int *)(param_1 + 0x4c) == 0;
}



===== lm_get_emac_base @ 14001b338 =====

int lm_get_emac_base(longlong param_1,short param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0x300) {
    uVar1 = lm_is_dual_core(param_1);
    if ((int)uVar1 == 0) {
      return (-(uint)(*(char *)(param_1 + 0x138) != '\0') & 0xfffffc00) + 0x8400;
    }
  }
  else {
    if ((param_2 != 0x600) && (param_2 != 0x900)) {
      return (-(uint)(*(char *)(param_1 + 0x138) != '\0') & 0x400) + 0x8000;
    }
    uVar1 = lm_is_dual_core(param_1);
    if ((int)uVar1 == 0) {
      return ((byte)~*(byte *)(param_1 + 0x14e) & 1 | 0x20) << 10;
    }
  }
  return 0x8000;
}



===== lm_get_link_speed @ 14001b3c0 =====

undefined4 lm_get_link_speed(longlong param_1)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  bool bVar6;
  
  sVar1 = *(short *)(param_1 + 0x130);
  if (sVar1 == 0) {
    uVar4 = lm_phy_get_gp_status(param_1);
    uVar4 = uVar4 & 0x3f00;
    if ((uVar4 == 0x200) || (uVar4 == 0xd00)) {
      return 0x300;
    }
    uVar3 = 0x700;
    if (uVar4 != 0x3900) {
      uVar3 = 0x600;
    }
    return uVar3;
  }
  if (sVar1 == 0x300) {
LAB_14001b52d:
    uVar2 = lm_mread45(param_1,sVar1,*(ushort *)(param_1 + 300),1,0xc820);
    if ((uVar2 & 0x8004) == 4) {
      return 0x600;
    }
    if ((uVar2 & 0x4002) == 2) {
      return 0x400;
    }
    if ((uVar2 & 0x2001) == 1) {
      return 0x300;
    }
    return 0;
  }
  if (sVar1 == 0x700) {
    uVar2 = lm_mread45(param_1,0x700,*(ushort *)(param_1 + 300),1,0xa811);
    if ((uVar2 & 0x800) != 0) {
      return 0x600;
    }
    lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xfff9);
    uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xfff9);
    uVar4 = uVar2 & 0x700;
    if ((uVar4 - 0x100 & 0xfffffeff) != 0) {
      if ((uVar4 - 0x300 & 0xfffffdff) != 0) {
        if ((uVar4 - 0x600 & 0xfffffeff) == 0) {
          return 0x300;
        }
        return 0;
      }
LAB_14001b45d:
      uVar5 = 0x200;
      uVar3 = 0x10200;
      bVar6 = uVar4 == 0x300;
      goto LAB_14001b525;
    }
  }
  else {
    if (sVar1 == 0x900) goto LAB_14001b52d;
    if (sVar1 != 0xe00) {
      return 0x600;
    }
    uVar2 = lm_mread22_ext(param_1,0x19);
    uVar4 = uVar2 & 0x700;
    if ((uVar4 - 0x100 & 0xfffffeff) != 0) {
      if ((uVar4 - 0x300 & 0xfffffdff) != 0) {
        return 0x300;
      }
      goto LAB_14001b45d;
    }
  }
  uVar5 = 0x100;
  uVar3 = 0x10100;
  bVar6 = uVar4 == 0x100;
LAB_14001b525:
  if (bVar6) {
    return uVar3;
  }
  return uVar5;
}



===== lm_get_mac_addresses @ 14001b5dc =====

void lm_get_mac_addresses(longlong param_1,undefined4 *param_2)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  int iVar9;
  int iVar10;
  
  bVar1 = *(byte *)(param_1 + 0x13c);
  uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x44 +
                                  (uint)*(byte *)(param_1 + 0x138) * 400);
  uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x48 +
                                  (uint)*(byte *)(param_1 + 0x138) * 400);
  bVar2 = lm_is_mf_cfg(param_1);
  if ((int)CONCAT71(extraout_var,bVar2) != 0) {
    iVar9 = (uint)bVar1 * 0x18;
    uVar6 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x24 + iVar9);
    if (((uVar6 & 6) - 2 & 0xfffffffd) == 0) {
      uVar7 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x28 + iVar9);
      if ((short)uVar7 != -1) {
        uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x2c + iVar9);
        uVar4 = uVar7;
      }
    }
  }
  param_2[1] = uVar4;
  *param_2 = uVar5;
  iVar9 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x4c +
                                  (uint)*(byte *)(param_1 + 0x138) * 400);
  uVar4 = lm_reg_read_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 400 +
                                  *(int *)(param_1 + 0x4c) + 0x50);
  bVar2 = lm_is_mf_cfg(param_1);
  if ((int)CONCAT71(extraout_var_00,bVar2) == 0) goto LAB_14001b780;
  if ((*(short *)(param_1 + 0xec) - 0x300U & 0xfbff) == 0) {
    iVar10 = (uint)bVar1 * 0x28;
    iVar8 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0xe8 + iVar10);
    if ((iVar8 == 0) || (iVar8 == 0xffff)) goto LAB_14001b780;
    iVar9 = *(int *)(param_1 + 0x54) + 0xec;
  }
  else {
    iVar10 = (uint)bVar1 * 0x18;
    bVar3 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x24 + iVar10);
    if ((bVar3 & 6) != 6) goto LAB_14001b780;
    iVar8 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x28 + iVar10);
    if ((short)iVar8 == -1) goto LAB_14001b780;
    iVar9 = *(int *)(param_1 + 0x54) + 0x2c;
  }
  uVar4 = lm_reg_read_ind(param_1,iVar9 + iVar10);
  iVar9 = iVar8;
LAB_14001b780:
  param_2[3] = iVar9;
  param_2[2] = uVar4;
  bVar2 = lm_is_mf_cfg(param_1);
  if ((int)CONCAT71(extraout_var_01,bVar2) == 0) {
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xb0 +
                                    (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[5] = uVar4;
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xb4 +
                                    (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[4] = uVar4;
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xb8 +
                                    (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[7] = uVar4;
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xbc +
                                    (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[6] = uVar4;
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xc0 +
                                    (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[9] = uVar4;
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0xc4 +
                                    (uint)*(byte *)(param_1 + 0x138) * 400);
    param_2[8] = uVar4;
  }
  else {
    iVar9 = (uint)bVar1 * 0x28;
    if (*(short *)(param_1 + 0xec) == 0x500) {
      uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x28 + (uint)bVar1 * 0x18);
      param_2[5] = uVar4;
      iVar8 = *(int *)(param_1 + 0x54) + 0x2c + (uint)bVar1 * 0x18;
    }
    else {
      uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0xf0 + iVar9);
      param_2[5] = uVar4;
      iVar8 = *(int *)(param_1 + 0x54) + 0xf4 + iVar9;
    }
    uVar4 = lm_reg_read_ind(param_1,iVar8);
    param_2[4] = uVar4;
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x100 + iVar9);
    param_2[9] = uVar4;
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x104 + iVar9);
    param_2[8] = uVar4;
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0xf8 + iVar9);
    param_2[7] = uVar4;
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0xfc + iVar9);
    param_2[6] = uVar4;
  }
  return;
}



===== lm_get_phy_info @ 14001b940 =====

void lm_get_phy_info(longlong param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined8 uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  iVar7 = (-(uint)(param_2 != 0) & 0xffffffe8) + 0x1b4;
  uVar2 = lm_reg_read_ind(param_1,(uint)bVar1 * 400 + *(int *)(param_1 + 0x4c) + iVar7);
  uVar6 = *(ushort *)(param_1 + 0x14e);
  uVar4 = uVar2 & 0xff00;
  *(ushort *)(param_1 + 300) = uVar2 & 0xff;
  *(ushort *)(param_1 + 0x130) = uVar4;
  uVar5 = uVar6 | 0x100;
  *(ushort *)(param_1 + 0x14e) = uVar5;
  if (uVar4 == 0xa00) {
    uVar5 = uVar6 | 0x102;
    *(undefined2 *)(param_1 + 0x130) = 0x900;
    *(ushort *)(param_1 + 0x14e) = uVar5;
    uVar4 = 0x900;
  }
  if (uVar4 == 0xb00) {
    uVar5 = uVar5 | 8;
    *(undefined2 *)(param_1 + 0x130) = 0x700;
    *(ushort *)(param_1 + 0x14e) = uVar5;
    uVar4 = 0x700;
  }
  if (uVar4 == 0xd00) {
    uVar5 = uVar5 | 0x10;
    *(undefined2 *)(param_1 + 0x130) = 0x700;
    *(ushort *)(param_1 + 0x14e) = uVar5;
    uVar4 = 0x700;
  }
  if (uVar4 == 0x1100) {
    *(undefined2 *)(param_1 + 0x130) = 0x700;
    uVar5 = uVar5 | 0x400;
    uVar4 = 0x700;
    *(ushort *)(param_1 + 0x14e) = uVar5;
  }
  if (uVar4 == 0xf00) {
    *(undefined2 *)(param_1 + 0x130) = 0x900;
    uVar5 = uVar5 | 0x80;
    uVar4 = 0x900;
    *(ushort *)(param_1 + 0x14e) = uVar5;
  }
  if (uVar4 == 0x1000) {
    uVar4 = 0xe00;
    uVar5 = uVar5 | 0x200;
    *(undefined2 *)(param_1 + 0x130) = 0xe00;
    *(ushort *)(param_1 + 0x14e) = uVar5;
  }
  if (uVar4 == 0x1200) {
    *(undefined2 *)(param_1 + 0x130) = 0x700;
    uVar5 = uVar5 | 0x800;
    *(ushort *)(param_1 + 0x14e) = uVar5;
  }
  uVar3 = lm_is_e3(param_1);
  if (((int)uVar3 != 0) &&
     (*(ushort *)(param_1 + 0x14e) = uVar5 | 0x20,
     ((*(uint *)(param_1 + 0x148) & 0xf000000) + 0xfc000000 & 0xfeffffff) == 0)) {
    *(ushort *)(param_1 + 0x14e) = uVar5 | 0x60;
  }
  uVar3 = lm_is_dual_core(param_1);
  if ((int)uVar3 == 0) {
    uVar6 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + (bVar1 ^ 1) * 400 + iVar7);
    uVar6 = uVar6 & 0xff;
  }
  else {
    uVar6 = uVar2 & 0xff ^ 1;
  }
  *(ushort *)(param_1 + 0x12e) = uVar6;
  return;
}



===== lm_gpio_write @ 14001bb48 =====

void lm_gpio_write(undefined8 param_1,char param_2,char param_3,char param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  
  iVar2 = lm_reg_read_ind(param_1,0x10394);
  cVar5 = '\0';
  if (iVar2 != 0) {
    iVar2 = lm_reg_read_ind(param_1,0x10398);
    if (iVar2 != 0) {
      cVar5 = '\x01';
    }
  }
  bVar1 = (-(cVar5 != param_2) & 4U) + param_3;
  uVar3 = lm_reg_read_ind(param_1,0xa490);
  uVar6 = 0x10000 << (bVar1 & 0x1f);
  uVar3 = uVar3 & ~(0x1000000 << (bVar1 & 0x1f));
  uVar4 = 0x100 << (bVar1 & 0x1f);
  if (param_4 == '\x01') {
    uVar6 = ~uVar6 & uVar3;
  }
  else {
    uVar4 = ~uVar4 & uVar3;
  }
  lm_reg_wr_ind(param_1,0xa490,uVar6 | uVar4);
  return;
}



===== lm_init_common_part @ 14001bc04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 lm_init_common_part(longlong param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined1 auStack_68 [32];
  int local_48 [4];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  lm_chip_reset_all_blocks(param_1);
  lm_reg_wr_ind(param_1,0xa280,1);
  lm_reg_wr_ind(param_1,0xa294,0x71d2911);
  lm_reg_wr_ind(param_1,0xa298,0);
  lm_reg_wr_ind(param_1,0xa29c,0x9c0424);
  lm_reg_wr_ind(param_1,0xa2a0,0);
  lm_reg_wr_ind(param_1,0xa2a8,0x100);
  mm_stall(0x1e);
  lm_reg_wr_ind(param_1,0xa2a8,0);
  iVar4 = 0x103800;
  do {
    lm_reg_wr_ind(param_1,iVar4,0xcccccccc);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x104000);
  iVar4 = 0x103c10;
  do {
    lm_reg_wr_ind(param_1,iVar4,0x1002000);
    iVar4 = iVar4 + 0x20;
  } while (iVar4 < 0x103d10);
  iVar8 = 0;
  iVar4 = 0x103e10;
  do {
    lm_reg_wr_ind(param_1,iVar4,iVar8 * 0x1000000 + 0x1000000U | 0x2000);
    iVar8 = iVar8 + 1;
    iVar4 = iVar4 + 0x20;
  } while (iVar4 < 0x103f10);
  lm_reg_wr_ind(param_1,0x103e10,0x1002000);
  lm_reg_wr_ind(param_1,0x103e30,0x2002000);
  everest_init_pxp2_common(param_1);
  everest_init_tcm_common(param_1);
  everest_init_ucm_common(param_1);
  everest_init_ccm_common(param_1);
  everest_init_xcm_common(param_1);
  everest_init_qm_common(param_1);
  lm_reg_wr_ind(param_1,0x168428,1);
  lm_reg_wr_ind(param_1,0x168428,0);
  lm_reg_wr_ind(param_1,0x16401c,250000);
  lm_reg_wr_ind(param_1,0x170008,1);
  lm_reg_wr_ind(param_1,0x17002c,7);
  lm_reg_wr_ind(param_1,0x17003c,4);
  lm_reg_wr_ind(param_1,0x170048,2);
  lm_reg_wr_ind(param_1,0x17004c,0x90);
  lm_reg_wr_ind(param_1,0x170050,0x90);
  lm_reg_wr_ind(param_1,0x170054,0x800090);
  lm_reg_wr_ind(param_1,0x170058,0x8140000);
  uVar2 = lm_is_dual_core(param_1);
  uVar5 = -(uint)((int)uVar2 != 0) & 0x3a0;
  lm_reg_wr_ind(param_1,uVar5 + 0x170060,10);
  lm_reg_wr_ind(param_1,uVar5 + 0x170064,10);
  lm_reg_wr_ind(param_1,uVar5 + 0x170068,0x10);
  lm_reg_wr_ind(param_1,uVar5 + 0x17006c,0x10);
  lm_reg_wr_ind(param_1,0x170070,6);
  lm_reg_wr_ind(param_1,0x170038,0x7c1004);
  lm_reg_wr_ind(param_1,0x170004,0xf);
  lm_reg_wr_ind(param_1,0x170030,7);
  uVar5 = 0;
  iVar4 = 0x61000;
  do {
    uVar5 = uVar5 + 0x2000;
    lm_reg_wr_ind(param_1,iVar4,uVar5);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x617fc);
  lm_reg_wr_ind(param_1,0x617fc,uVar5 | 1);
  lm_reg_wr_ind(param_1,0x600dc,1);
  lm_reg_wr_ind(param_1,0x60200,0);
  lm_reg_wr_ind(param_1,0x60204,0x1ff);
  lm_reg_wr_ind(param_1,0x60208,0x200);
  lm_reg_wr_ind(param_1,0x600dc,0);
  lm_reg_wr_ind(param_1,0x40048,10);
  lm_reg_wr_ind(param_1,0x40070,4);
  lm_reg_wr_ind(param_1,0x400b8,0x160000);
  lm_reg_wr_ind(param_1,0x400bc,0x100000);
  lm_reg_wr_ind(param_1,0x400dc,0x160000);
  lm_reg_wr_ind(param_1,0x40004,0xff);
  lm_reg_wr_ind(param_1,0x40138,1);
  if ((*(uint *)(param_1 + 0x58) >> 0x11 & 1) != 0) {
    uVar5 = *(uint *)(param_1 + 0x58) & 0x4000;
    uVar6 = (uVar5 | 0x18000) >> 0xe;
    if (uVar5 != 0) {
      lm_reg_wr_ind(param_1,0x401c8,1);
      lm_reg_wr_ind(param_1,0x40254,1);
      lm_reg_wr_ind(param_1,0x4028c,1);
      lm_reg_wr_ind(param_1,0x402ac,1);
    }
    lm_reg_wr_ind(param_1,0x40238,uVar6);
    lm_reg_wr_ind(param_1,0x40270,uVar6);
    lm_reg_wr_ind(param_1,0x40290,uVar6);
  }
  lm_reg_wr_ind(param_1,0x42008,0x411);
  lm_reg_wr_ind(param_1,0x4200c,0x400);
  lm_reg_wr_ind(param_1,0x42010,0x404);
  lm_reg_wr_ind(param_1,0x42014,0x419);
  iVar4 = 0x4201c;
  do {
    lm_reg_wr_ind(param_1,iVar4,0xffff);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x4202c);
  lm_reg_wr_ind(param_1,0x42038,0x34);
  iVar8 = 0;
  iVar4 = 0x4203c;
  do {
    lm_reg_wr_ind(param_1,iVar4,iVar8 + 5);
    iVar8 = iVar8 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x4205c);
  lm_reg_wr_ind(param_1,0x421b8,0);
  iVar8 = 0x421bc;
  iVar4 = 0x421dc;
  do {
    lm_reg_wr_ind(param_1,iVar8,1);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x421dc);
  do {
    lm_reg_wr_ind(param_1,iVar4 + -0x180,0);
    lm_reg_wr_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x42238);
  iVar4 = 0x42138;
  do {
    lm_reg_wr_ind(param_1,iVar4 + -0x80,0);
    lm_reg_wr_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x421b8);
  lm_reg_wr_ind(param_1,0x42238,0x7ffffff);
  lm_reg_wr_ind(param_1,0x4223c,0x3f);
  lm_reg_wr_ind(param_1,0x42240,0x7ffffff);
  lm_reg_wr_ind(param_1,0x42244,0xf);
  lm_reg_wr_ind(param_1,0x42000,1000);
  lm_reg_wr_ind(param_1,0xc2008,0xa11);
  lm_reg_wr_ind(param_1,0xc200c,0xa00);
  lm_reg_wr_ind(param_1,0xc2010,0xa04);
  iVar4 = 0xc201c;
  do {
    lm_reg_wr_ind(param_1,iVar4,0xffff);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xc202c);
  lm_reg_wr_ind(param_1,0xc2038,0x34);
  iVar4 = 0xc203c;
  do {
    lm_reg_wr_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xc20b8);
  iVar4 = 0xc2138;
  do {
    lm_reg_wr_ind(param_1,iVar4 + -0x80,0);
    lm_reg_wr_ind(param_1,iVar4,0);
    lm_reg_wr_ind(param_1,iVar4 + 0x80,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xc21b8);
  lm_reg_wr_ind(param_1,0xc2238,0x7ffffff);
  lm_reg_wr_ind(param_1,0xc223c,0x3f);
  lm_reg_wr_ind(param_1,0xc2240,0x7ffffff);
  lm_reg_wr_ind(param_1,0xc2244,0xf);
  lm_reg_wr_ind(param_1,0xc2000,1000);
  lm_reg_wr_ind(param_1,0xc4008,0xa11);
  lm_reg_wr_ind(param_1,0xc400c,0xa00);
  lm_reg_wr_ind(param_1,0xc4010,0xa04);
  lm_reg_wr_ind(param_1,0xc4014,0xa21);
  iVar4 = 0xc401c;
  do {
    lm_reg_wr_ind(param_1,iVar4,0xffff);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xc402c);
  lm_reg_wr_ind(param_1,0xc4038,0x34);
  iVar4 = 0;
  do {
    if (iVar4 == 0) {
      iVar8 = 0xc4038;
      uVar10 = 0x34;
    }
    else {
      iVar8 = iVar4 * 4 + 0xc4038;
      uVar10 = 0;
    }
    lm_reg_wr_ind(param_1,iVar8,uVar10);
    lm_reg_wr_ind(param_1,iVar4 * 4 + 0xc40b8,0);
    lm_reg_wr_ind(param_1,iVar4 * 4 + 0xc4138,0);
    lm_reg_wr_ind(param_1,iVar4 * 4 + 0xc41b8,0);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x20);
  lm_reg_wr_ind(param_1,0xc4238,0x7ffffff);
  lm_reg_wr_ind(param_1,0xc423c,0x3f);
  lm_reg_wr_ind(param_1,0xc4240,0x7ffffff);
  lm_reg_wr_ind(param_1,0xc4244,0xf);
  lm_reg_wr_ind(param_1,0xc4000,1000);
  lm_reg_wr_ind(param_1,0x166008,0xa14);
  lm_reg_wr_ind(param_1,0x16600c,0xa00);
  lm_reg_wr_ind(param_1,0x166010,0xa04);
  iVar4 = 0x16601c;
  do {
    lm_reg_wr_ind(param_1,iVar4,0xffff);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x16602c);
  lm_reg_wr_ind(param_1,0x166038,0x34);
  lm_reg_wr_ind(param_1,0x16603c,0x10);
  lm_reg_wr_ind(param_1,0x166040,0x10);
  iVar4 = 0x166044;
  do {
    lm_reg_wr_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x1660b8);
  iVar4 = 0x166138;
  iVar8 = 0x1661b8;
  do {
    lm_reg_wr_ind(param_1,iVar4 + -0x80,0);
    lm_reg_wr_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x1661b8);
  iVar4 = 0;
  do {
    lm_reg_wr_ind(param_1,iVar8,(uint)(iVar4 == 1));
    iVar4 = iVar4 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x166238);
  lm_reg_wr_ind(param_1,0x166238,0x7ffffff);
  lm_reg_wr_ind(param_1,0x16623c,0x3f);
  lm_reg_wr_ind(param_1,0x166240,0x7ffffff);
  lm_reg_wr_ind(param_1,0x166244,0xf);
  lm_reg_wr_ind(param_1,0x166000,1000);
  local_48[0] = 0x1a0000;
  piVar9 = local_48;
  local_48[1] = 0x220000;
  lVar7 = 4;
  local_48[2] = 0x2a0000;
  local_48[3] = 0x320000;
  do {
    iVar4 = *piVar9;
    uVar5 = 0;
    do {
      lm_reg_wr_ind(param_1,iVar4 + uVar5,0);
      uVar5 = uVar5 + 4;
    } while (uVar5 < 0x5800);
    piVar9 = piVar9 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  uVar5 = 0;
  if (l2fw_tstorm_len != 0) {
    do {
      lm_reg_wr_ind(param_1,uVar5 + 0x1c0000,(&l2fw_tstorm)[uVar5 >> 2]);
      uVar5 = uVar5 + 4;
    } while (uVar5 < l2fw_tstorm_len);
  }
  uVar5 = 0;
  if (l2fw_cstorm_len != 0) {
    do {
      lm_reg_wr_ind(param_1,uVar5 + 0x240000,(&l2fw_cstorm)[uVar5 >> 2]);
      uVar5 = uVar5 + 4;
    } while (uVar5 < l2fw_cstorm_len);
  }
  uVar5 = 0;
  if (l2fw_xstorm_len != 0) {
    do {
      lm_reg_wr_ind(param_1,uVar5 + 0x2c0000,(&l2fw_xstorm)[uVar5 >> 2]);
      uVar5 = uVar5 + 4;
    } while (uVar5 < l2fw_xstorm_len);
  }
  uVar5 = 0;
  if (l2fw_ustorm_len != 0) {
    do {
      lm_reg_wr_ind(param_1,uVar5 + 0x340000,(&l2fw_ustorm)[uVar5 >> 2]);
      uVar5 = uVar5 + 4;
    } while (uVar5 < l2fw_ustorm_len);
  }
  everest_init_tsem_common(param_1);
  everest_init_usem_common(param_1);
  everest_init_csem_common(param_1);
  everest_init_xsem_common(param_1);
  lm_reg_wr_ind(param_1,0xa588,0x80000000);
  lm_reg_wr_ind(param_1,0xa584,0x80000000);
  lm_reg_wr_ind(param_1,0xc1000,0x20);
  lm_reg_wr_ind(param_1,0x161000,0x20);
  everest_init_pbf_common(param_1);
  lm_reg_wr_ind(param_1,0x101020,0x4000400);
  lm_reg_wr_ind(param_1,0x101000,0);
  lm_reg_wr_ind(param_1,0x101008,9);
  lm_reg_write_block(param_1,0x101800,(undefined4 *)&DAT_14002f3d0,0x40);
  lm_reg_write_block(param_1,0x101100,(undefined4 *)&DAT_14002f4d0,8);
  if ((*(uint *)(param_1 + 0x58) & 0x20000) != 0) {
    lm_reg_wr_ind(param_1,0x101050,1);
  }
  lm_reg_wr_ind(param_1,0x10404c,0x7ff);
  lm_reg_wr_ind(param_1,0x104028,0x10);
  lm_reg_wr_ind(param_1,0x104044,0x3fff);
  lm_reg_wr_ind(param_1,0x104084,0x84924a);
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 == 0) {
    lm_reg_wr_ind(param_1,0x108068,0x288);
    lm_reg_wr_ind(param_1,0x10806c,0x288);
    lm_reg_wr_ind(param_1,0x108070,0x288);
    lm_reg_wr_ind(param_1,0x108074,0x288);
  }
  iVar4 = 0xa000;
  do {
    lm_reg_wr_ind(param_1,iVar4,0);
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xa058);
  lm_reg_wr_ind(param_1,0x10104,1);
  lm_reg_wr_ind(param_1,0x100b4,1);
  lm_reg_wr_ind(param_1,0x100b8,1);
  lm_reg_wr_ind(param_1,0x10100,1);
  lm_reg_wr_ind(param_1,0x120330,0);
  lm_reg_wr_ind(param_1,0x120374,0);
  lm_reg_wr_ind(param_1,0x104050,0);
  if (((*(short *)(param_1 + 0x130) == 0x600) || (*(short *)(param_1 + 0x130) == 0x900)) &&
     ((*(byte *)(param_1 + 1) & 1) == 0)) {
    uVar1 = *(undefined1 *)(param_1 + 0x13a);
    bVar3 = ~*(byte *)(param_1 + 0x14e) & 1;
    *(byte *)(param_1 + 0x13a) = bVar3;
    lm_gpio_write(param_1,bVar3,'\x01','\x01');
    mm_stall(100000);
    *(undefined1 *)(param_1 + 0x13a) = uVar1;
  }
  return 0;
}



===== lm_init_connection_context @ 14001c95c =====

void lm_init_connection_context(longlong param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  mm_init_context(param_1);
  lVar1 = *(longlong *)(param_1 + 0x78);
  lVar2 = (ulonglong)param_2 * 0x1e0;
  *(undefined4 *)(lVar1 + 0x204) = *(undefined4 *)(lVar2 + 0x2b4 + param_1);
  *(undefined4 *)(lVar1 + 0x200) = *(undefined4 *)(lVar2 + 0x2b0 + param_1);
  *(undefined4 *)(lVar1 + 0xc) = *(undefined4 *)(lVar2 + 0x4ac + param_1);
  *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(lVar2 + 0x4a8 + param_1);
  *(undefined1 *)(lVar1 + 2) = 0;
  *(undefined4 *)(lVar1 + 0x14) = *(undefined4 *)((ulonglong)param_2 * 0x40 + 0x694 + param_1);
  *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)((ulonglong)param_2 * 0x40 + 0x690 + param_1);
  *(undefined1 *)(lVar1 + 0x2f0) = 0;
  return;
}



===== lm_init_ext_phy @ 14001c9e4 =====

void lm_init_ext_phy(longlong param_1)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  bool bVar4;
  
  uVar3 = 0;
  do {
    uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0);
    if ((uVar1 & 0x8000) == 0) break;
    mm_stall(1000);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 1000);
  sVar2 = *(short *)(param_1 + 0x130);
  if (sVar2 == 0x300) {
    lm_mwrite45(param_1,0x300,*(ushort *)(param_1 + 300),1,0x9000,4);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x9002,4);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x11,0xa0);
    uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x8329);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x8329,uVar3 | 1);
    uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x12);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x12,uVar3 | 0x8000
               );
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0,0x1200);
    mm_stall(500000);
  }
  else if (sVar2 == 0x600) {
    sVar2 = lm_mread45(param_1,0x600,*(ushort *)(param_1 + 300),1,0xca1c);
    if (sVar2 != -1) {
      mm_stall(100000);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca85,1);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x188);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca1e,0x73a0);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x18a);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca10,0x188);
      mm_stall(100000);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca85,0);
      mm_stall(200000);
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 4;
    }
    uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800,
                uVar3 & 0x7fff);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x9002,1);
  }
  else if (sVar2 == 0x700) {
    sVar2 = 0x700;
    if ((*(uint *)(param_1 + 0x148) & 0x200000) == 0) {
      uVar3 = lm_mread45(param_1,0x700,*(ushort *)(param_1 + 300),0x1e,0x4005);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4005,
                  uVar3 & 0xff7f);
      sVar2 = *(short *)(param_1 + 0x130);
    }
    uVar3 = lm_mread45(param_1,sVar2,*(ushort *)(param_1 + 300),7,0xffe9);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe9,
                uVar3 | 0x300);
    uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe4);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe4,
                uVar3 | 0xde0);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe0,0x1200);
    mm_stall(500000);
    if ((*(ushort *)(param_1 + 0x14e) & 0x418) != 0) {
      lm_phy_848xx_prg_leds(param_1);
    }
  }
  else if (sVar2 == 0x900) {
    uVar3 = 0xd;
    bVar4 = (*(uint *)(param_1 + 0x18c) & 0xff00) != 0x300;
    if (bVar4) {
      uVar3 = 8;
    }
    uVar1 = 0x40;
    if (bVar4) {
      uVar1 = 0x2040;
    }
    lm_mwrite45(param_1,0x900,*(ushort *)(param_1 + 300),1,0,uVar1);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,7,uVar3);
    lm_bcm8727_set_edc_mode(param_1);
    lm_phy_8727_ctrl_optical_output(param_1,1);
  }
  else if (sVar2 == 0xe00) {
    uVar3 = lm_mread22_ext(param_1,4);
    lm_mwrite22_ext(param_1,4,uVar3 | 0xde0);
    uVar3 = lm_mread22_ext(param_1,9);
    lm_mwrite22_ext(param_1,9,uVar3 | 0x300);
    lm_mwrite22_ext(param_1,0,0x1200);
  }
  return;
}



===== lm_init_function_part @ 14001cff8 =====

undefined8 lm_init_function_part(longlong param_1)

{
  char cVar1;
  bool bVar2;
  undefined7 extraout_var;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  cVar1 = *(char *)(param_1 + 0x138);
  lm_init_connection_context(param_1,0);
  lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x10330,0);
  if ((*(uint *)(param_1 + 0x124) & 0xffff0000) == 0x164e0000) {
    cVar1 = *(char *)(param_1 + 0x138);
    lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 4) + 0x120000,-(uint)(cVar1 != '\0') & 0x60180);
    uVar6 = -(uint)(cVar1 != '\0') & 0xc00;
  }
  else {
    lm_reg_wr_ind(param_1,0x12061c,(uint)*(byte *)(param_1 + 0x13d));
    lm_reg_wr_ind(param_1,0x120620,(uint)*(byte *)(param_1 + 0x13d));
    lm_reg_wr_ind(param_1,(-(uint)(*(char *)(param_1 + 0x138) != '\0') & 4) + 0x120000,
                  (uint)*(byte *)(param_1 + 0x13d) << 10 | (uint)*(byte *)(param_1 + 0x13d));
    uVar6 = (uint)*(byte *)(param_1 + 0x13d) << 3;
  }
  lm_reg_wr_ind(param_1,uVar6 + 0x122000,
                *(int *)(param_1 + 0x84) << 0x14 | *(uint *)(param_1 + 0x80) >> 0xc);
  lm_reg_wr_ind(param_1,uVar6 + 0x122004,*(uint *)(param_1 + 0x84) >> 0xc | 0x100000);
  if (*(byte *)(param_1 + 0x13d) < 2) {
    mm_pcicfg_map(param_1,1);
  }
  iVar7 = 0;
  *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x80) >> 0xc;
  if ((*(uint *)(param_1 + 0x58) & 0x10000) != 0) {
    everest_init_xcm_port(param_1);
    everest_init_qm_port(param_1);
    lm_reg_wr_ind(param_1,(-(uint)(*(char *)(param_1 + 0x138) != '\0') & 4) + 0x400fc,
                  -(uint)(*(char *)(param_1 + 0x138) != '\0') & 0x800000);
    uVar6 = lm_reg_read_ind(param_1,0x40134);
    lm_reg_wr_ind(param_1,0x40134,uVar6 | 5);
    if (*(char *)(param_1 + 0x138) == '\0') {
      lm_reg_wr_ind(param_1,0x140030,1);
      uVar4 = 0x14005c;
    }
    else {
      lm_reg_wr_ind(param_1,0x140034,1);
      uVar4 = 0x140060;
    }
    lm_reg_wr_ind(param_1,uVar4,0);
  }
  iVar8 = iVar7;
  do {
    lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xe4) + iVar8,0);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x18);
  iVar8 = iVar7;
  do {
    lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xbc) + iVar8,0);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x18);
  iVar8 = iVar7;
  do {
    lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xcc) + iVar8,0);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x18);
  iVar9 = 0;
  iVar8 = iVar7;
  do {
    lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xd4) + iVar8,0);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x18);
  iVar8 = iVar7;
  do {
    lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xc4) + -8 + iVar8,0);
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x10);
  lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 200),0);
  lm_reg_wr_ind(param_1,*(int *)(param_1 + 200) + 4,0);
  bVar2 = lm_is_mf_cfg(param_1);
  if ((int)CONCAT71(extraout_var,bVar2) != 0) {
    iVar9 = (*(short *)(param_1 + 0xec) == 0x700) + 1;
  }
  lm_reg_wr_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 8 + 0x431944,iVar9);
  uVar3 = lm_is_dual_core(param_1);
  if ((int)uVar3 == 0) {
    if (*(char *)(param_1 + 0x138) == '\0') {
      uVar4 = 0x108000;
      lm_reg_wr_ind(param_1,0x108000,0x1080);
      lm_reg_wr_ind(param_1,0x108028,0x2860286);
      lm_reg_wr_ind(param_1,0x10802c,0x2860286);
      lm_reg_wr_ind(param_1,0x108050,0);
      lm_reg_wr_ind(param_1,0x108008,0x2b5);
      lm_reg_wr_ind(param_1,0x108010,0);
      iVar7 = 0x108200;
      do {
        lm_reg_wr_ind(param_1,iVar7,0);
        iVar7 = iVar7 + 4;
      } while (iVar7 < 0x108328);
      uVar5 = 0x108108;
    }
    else {
      uVar4 = 0x108004;
      lm_reg_wr_ind(param_1,0x108004,0x1080);
      lm_reg_wr_ind(param_1,0x108030,0x2870287);
      lm_reg_wr_ind(param_1,0x108034,0x2870287);
      lm_reg_wr_ind(param_1,0x108054,0);
      lm_reg_wr_ind(param_1,0x10800c,0x2b5);
      lm_reg_wr_ind(param_1,0x108014,0);
      iVar7 = 0x108400;
      do {
        lm_reg_wr_ind(param_1,iVar7,0);
        iVar7 = iVar7 + 4;
      } while (iVar7 < 0x108528);
      uVar5 = 0x10810c;
    }
    iVar7 = 0x1ffff;
  }
  else {
    uVar6 = lm_reg_read_ind(param_1,0x130154);
    lm_reg_wr_ind(param_1,0x130154,uVar6 & 0xfffffff5 | 0x31);
    lm_reg_wr_ind(param_1,0x13015c,0);
    lm_reg_wr_ind(param_1,0x130160,0);
    uVar4 = 0x130168;
    uVar5 = 0x130164;
  }
  lm_reg_wr_ind(param_1,uVar5,iVar7);
  lm_reg_wr_ind(param_1,uVar4,0);
  lm_reg_wr_ind(param_1,0xd0114,8);
  everest_init_nig_port(param_1);
  lm_reg_read_ind(param_1,0x282000);
  lm_reg_read_ind(param_1,0x282004);
  lm_reg_read_ind(param_1,0x282008);
  lm_reg_read_ind(param_1,0x202000);
  lm_reg_read_ind(param_1,0x202004);
  lm_reg_read_ind(param_1,0x202008);
  lm_reg_read_ind(param_1,0x181000);
  lm_reg_read_ind(param_1,0x181004);
  lm_reg_read_ind(param_1,0x181008);
  lm_reg_read_ind(param_1,0x302000);
  lm_reg_read_ind(param_1,0x302004);
  lm_reg_read_ind(param_1,0x302008);
  return 0;
}



===== lm_init_fw_offsets @ 14001d534 =====

void lm_init_fw_offsets(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
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
  
  if ((*(uint *)(param_1 + 0x58) & 0x8000) == 0) {
    bVar1 = *(byte *)(param_1 + 0x138);
    iVar10 = (uint)bVar1 * 0x10 + 0x431508;
    uVar2 = (uint)bVar1;
    iVar7 = uVar2 * 0x18 + 0x401408;
    iVar12 = (bVar1 + 0x2ab80) * 0x18;
    iVar5 = (bVar1 + 0x2b62b) * 0x18;
    iVar8 = (bVar1 + 0x2cb80) * 0x18;
    iVar13 = (uint)bVar1 * 8 + 0x431520;
    iVar4 = (bVar1 + 0x2c362) * 0x18;
    iVar6 = uVar2 * 0x18 + 0x411400;
    iVar14 = uVar2 * 0x18 + 0x431408;
    iVar11 = uVar2 * 0x18 + 0x421408;
    iVar9 = uVar2 * 0x18 + 0x421400;
    iVar3 = uVar2 * 0x18 + 0x425128;
  }
  else {
    iVar9 = *(byte *)(param_1 + 0x13e) - 2;
    iVar3 = iVar9 * 0x18;
    iVar13 = iVar9 * 8 + 0x4318a0;
    iVar10 = iVar9 * 0x10 + 0x431848;
    iVar9 = iVar3 + 0x421448;
    iVar7 = iVar3 + 0x401450;
    iVar12 = iVar3 + 0x401448;
    iVar5 = iVar3 + 0x411450;
    iVar6 = iVar3 + 0x411448;
    iVar14 = iVar3 + 0x431450;
    iVar8 = iVar3 + 0x431448;
    iVar4 = iVar3 + 0x425190;
    iVar3 = iVar3 + 0x425188;
    iVar11 = iVar9;
  }
  *(int *)(param_1 + 0xbc) = iVar3;
  *(int *)(param_1 + 0xc0) = iVar4;
  *(int *)(param_1 + 0xc4) = iVar10;
  *(int *)(param_1 + 200) = iVar13;
  *(int *)(param_1 + 0xcc) = iVar9;
  *(int *)(param_1 + 0xd0) = iVar11;
  *(int *)(param_1 + 0xd4) = iVar8;
  *(int *)(param_1 + 0xd8) = iVar14;
  *(int *)(param_1 + 0xdc) = iVar6;
  *(int *)(param_1 + 0xe0) = iVar5;
  *(int *)(param_1 + 0xe4) = iVar12;
  *(int *)(param_1 + 0xe8) = iVar7;
  return;
}



===== lm_init_status_blocks @ 14001d6b0 =====

void lm_init_status_blocks(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  ushort uVar6;
  undefined4 *puVar7;
  int iVar8;
  
  uVar4 = lm_is_dual_core(param_1);
  uVar5 = 0;
  if ((int)uVar4 != 0) {
    uVar6 = 0;
    do {
      uVar3 = lm_reg_read_ind(param_1,(uint)uVar6 * 4 + 0x131000);
      if ((((uVar3 & 0x2001) == 0x2001) && (((byte)(uVar3 >> 7) & 7) == *(byte *)(param_1 + 0x13e)))
         && ((uVar3 & 0x7e) == 0)) goto LAB_14001d72b;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x88);
  }
  uVar6 = 0x10;
LAB_14001d72b:
  *(ushort *)(param_1 + 0xb0) = uVar6;
  *(undefined8 *)(param_1 + 100) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x18) + 0x28) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x18) + 0x38) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x18) + 0x18) = 0;
  *(undefined2 *)(*(longlong *)(param_1 + 0x18) + 0x48) = 0;
  cVar1 = *(char *)(param_1 + 0x138);
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar4 = lm_is_dual_core(param_1);
  if ((int)uVar4 != 0) {
    *(undefined1 *)(lVar2 + 0x1a) = 1;
    puVar7 = (undefined4 *)(lVar2 + 0x10);
    *(undefined1 *)(lVar2 + 0x2a) = 3;
    uVar3 = 0;
    iVar8 = 0;
    *(undefined1 *)(lVar2 + 0x2b) = *(undefined1 *)(param_1 + 0xb0);
    *(undefined1 *)(lVar2 + 0x1b) = *(undefined1 *)(param_1 + 0xb0);
    do {
      lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xe8) + iVar8,*puVar7);
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + 4;
    } while (uVar3 < 4);
    iVar8 = 0;
    puVar7 = (undefined4 *)(lVar2 + 0x20);
    do {
      lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xe0) + iVar8,*puVar7);
      uVar5 = uVar5 + 1;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + 4;
    } while (uVar5 < 4);
  }
  lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 0xe4),*(int *)(param_1 + 0x28) + 0x10);
  lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xe4) + 4,*(undefined4 *)(param_1 + 0x2c));
  lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 0xdc),*(int *)(param_1 + 0x28) + 0x20);
  lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xdc) + 4,*(undefined4 *)(param_1 + 0x2c));
  lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 0xcc),*(int *)(param_1 + 0x28) + 0x30);
  lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xcc) + 4,*(undefined4 *)(param_1 + 0x2c));
  lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 0xd4),*(int *)(param_1 + 0x28) + 0x40);
  lm_reg_wr_ind(param_1,*(int *)(param_1 + 0xd4) + 4,*(undefined4 *)(param_1 + 0x2c));
  uVar5 = -(uint)(cVar1 != '\0') & 8;
  lm_reg_wr_ind(param_1,uVar5 + 0x108018,*(undefined4 *)(param_1 + 0x28));
  lm_reg_wr_ind(param_1,uVar5 + 0x10801c,*(undefined4 *)(param_1 + 0x2c));
  return;
}



===== lm_insert_vntag_vlan_hdr @ 14001d8d4 =====

void lm_insert_vntag_vlan_hdr(longlong param_1,longlong param_2)

{
  byte bVar1;
  short sVar2;
  longlong lVar3;
  uint uVar4;
  
  *(undefined4 *)(param_2 + 0x28) = 0;
  if ((*(uint *)(param_1 + 0x58) & 0x200) != 0) {
    lVar3 = *(longlong *)(param_2 + 0x38);
    *(undefined4 *)(lVar3 + 0xc) = 0x2689;
    sVar2 = *(short *)(param_1 + 0x3c);
    bVar1 = *(byte *)(param_1 + 0x3d);
    *(undefined2 *)(lVar3 + 0x12) = 0x81;
    *(ushort *)(lVar3 + 0x10) = sVar2 << 8 | (ushort)bVar1;
    uVar4 = *(uint *)(param_1 + 0x34);
    if ((uVar4 & 0xfff) == 0) {
      uVar4 = *(ushort *)(param_1 + 0x3e) & 0xfff | uVar4;
      *(uint *)(param_1 + 0x34) = uVar4;
    }
    *(ushort *)(lVar3 + 0x14) = (ushort)(uVar4 >> 8) & 0xff | *(short *)(param_1 + 0x34) << 8;
    *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 10;
    return;
  }
  uVar4 = *(uint *)(param_1 + 0x34);
  if (*(short *)(param_1 + 0xec) == 0x500) {
    uVar4 = uVar4 & 0xfff;
  }
  if (uVar4 != 0) {
    *(undefined2 *)(*(longlong *)(param_2 + 0x38) + 0xc) = 0x81;
    *(ushort *)(*(longlong *)(param_2 + 0x38) + 0xe) =
         (ushort)((uint)*(undefined4 *)(param_1 + 0x34) >> 8) & 0xff |
         *(short *)(param_1 + 0x34) << 8;
    *(int *)(param_2 + 0x28) = *(int *)(param_2 + 0x28) + 4;
  }
  return;
}



===== lm_intr_ack_sb @ 14001d9a8 =====

void lm_intr_ack_sb(longlong param_1,byte param_2,byte param_3,ushort param_4,byte param_5,
                   byte param_6)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = lm_is_dual_core(param_1);
  if ((int)uVar1 == 0) {
    uVar3 = ((uint)(ushort)((((ushort)param_5 * 2 | (ushort)param_6) << 3 | (ushort)param_3) << 5) |
            (uint)param_2) << 0x10 | (uint)param_4;
    uVar1 = lm_is_e3(param_1);
    if (((((int)uVar1 == 0) || (*(char *)(param_1 + 0x138) == '\0')) &&
        ((*(uint *)(param_1 + 0x58) & 0x20000) == 0)) && (*(byte *)(param_1 + 0x13d) < 2))
    goto LAB_14001da70;
    iVar2 = (uint)*(byte *)(param_1 + 0x138) * 0x2000 + 0x441000;
  }
  else {
    uVar3 = (((uint)param_5 * 2 | (uint)param_6) << 3 | (uint)param_3) << 0x15 | (uint)param_4;
    uVar1 = lm_is_e3(param_1);
    if ((((int)uVar1 == 0) || (*(char *)(param_1 + 0x138) == '\0')) &&
       (((*(uint *)(param_1 + 0x58) & 0x20000) == 0 && (*(byte *)(param_1 + 0x13d) < 2)))) {
LAB_14001da70:
      storport_pci_cfg_write_dword(param_1,0x88,uVar3);
      return;
    }
    iVar2 = (uint)*(ushort *)(param_1 + 0xb0) * 8 + 0x442000;
  }
  lm_reg_wr_ind(param_1,iVar2,uVar3);
  return;
}



===== lm_is_dual_core @ 14001dab8 =====

undefined8 lm_is_dual_core(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x124) & 0xffff0000;
  if (((uVar1 + 0xe9b20000 & 0xfffcffff) == 0) && (uVar1 != 0x16510000)) {
    return 0;
  }
  return 1;
}



===== lm_is_e3 @ 14001dae4 =====

undefined8 lm_is_e3(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x124) & 0xffff0000;
  if (((uVar1 == 0x168a0000) || (uVar1 == 0x168e0000)) || (uVar1 == 0x168d0000)) {
    return 1;
  }
  return 0;
}



===== lm_is_mf_cfg @ 14001db10 =====

bool lm_is_mf_cfg(longlong param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  undefined8 uVar6;
  byte bVar7;
  byte bVar8;
  
  bVar8 = *(byte *)(param_1 + 0x13a);
  bVar7 = 0;
  uVar6 = lm_is_mf_device(param_1);
  if (((int)uVar6 == 0) ||
     (uVar5 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x354), (uVar5 & 0x700) == 0x100))
  {
    return false;
  }
  sVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x30);
  if (sVar4 != -1) {
    return true;
  }
  cVar1 = *(char *)(param_1 + 0x158);
  for (; bVar8 < 8; bVar8 = bVar8 + (-(cVar1 != '\0') & 0xfeU) + 4) {
    bVar3 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x54) + 0x24 + (uint)bVar8 * 0x18);
    bVar2 = bVar7 + 1;
    if ((bVar3 & 1) != 0) {
      bVar2 = bVar7;
    }
    bVar7 = bVar2;
  }
  return 1 < bVar7;
}



===== lm_is_mf_device @ 14001dbec =====

undefined8 lm_is_mf_device(longlong param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x124) & 0xffff0000;
  if ((((uVar1 == 0x16500000) || (uVar1 == 0x16620000)) || (uVar1 == 0x16630000)) ||
     (((uVar1 == 0x168a0000 || (uVar1 == 0x168e0000)) || (uVar1 == 0x168d0000)))) {
    return 1;
  }
  return 0;
}



===== lm_is_phy_link_up @ 14001dc2c =====

undefined4 lm_is_phy_link_up(longlong param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  undefined7 extraout_var;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined7 extraout_var_00;
  ushort uVar7;
  int iVar8;
  undefined4 uVar9;
  ushort uVar10;
  int iVar11;
  
  uVar9 = 0;
  uVar10 = 0;
  if (param_2 == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = lm_phy_get_sigdet(param_1);
  }
  if (((*(byte *)(param_1 + 0x14e) & 0x20) == 0) || (param_2 == 0)) {
LAB_14001dc9c:
    if (uVar4 == 0) goto LAB_14001e0aa;
  }
  else if (uVar4 == 0) {
    uVar10 = 0;
    do {
      bVar2 = lm_phy_wc_get_sigdet(param_1);
      if ((int)CONCAT71(extraout_var,bVar2) != 0) goto LAB_14001dca4;
      uVar10 = uVar10 + 1;
      uVar4 = 0;
    } while (uVar10 < 0x28);
    goto LAB_14001dc9c;
  }
LAB_14001dca4:
  sVar1 = *(short *)(param_1 + 0x130);
  if (sVar1 == 0) {
    iVar11 = 0;
    uVar10 = 0;
    if (*(short *)(param_1 + 0x5e) != 0) {
      do {
        iVar8 = 0;
        uVar3 = lm_phy_get_gp_status(param_1);
        uVar7 = *(ushort *)(param_1 + 0x14e) & 0x20;
        if ((uVar3 & 4) == 0) {
          if ((((uVar7 != 0) && ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x3000000)) &&
              (uVar10 != 0)) && ((uint)uVar10 == (uVar10 / 10000) * 10000)) {
            lm_mwrite45_int2(param_1,0x8345,0xc000);
            lm_mwrite45_int2(param_1,0x8345,0);
          }
          iVar11 = iVar8;
LAB_14001e08d:
          mm_stall(1000);
        }
        else {
          iVar11 = iVar11 + 1;
          if (uVar7 == 0) {
            do {
              uVar6 = lm_phy_get_gp_status(param_1);
              if ((uVar6 & 4) == 0) break;
              mm_stall(1000);
              iVar8 = iVar8 + 1;
            } while (iVar8 < 100);
            if (iVar8 < 100) {
              if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
                bVar2 = lm_phy_cx4_get_sigdet(param_1);
                if ((((int)CONCAT71(extraout_var_00,bVar2) != 0) &&
                    (uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8371),
                    (uVar3 & 0x500) == 0x500)) &&
                   (uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8330),
                   (uVar3 & 0x610) == 0x610)) {
                  lm_mwrite45_int2(param_1,0,0);
                  lm_mwrite45_int2(param_1,0xffe0,0x800);
                  mm_stall(300000);
                  lm_mwrite45_int2(param_1,0xffe0,0x1200);
                }
              }
              else {
              }
              goto LAB_14001e08d;
            }
            uVar9 = 1;
            break;
          }
          uVar9 = 1;
          if (((*(uint *)(param_1 + 0x148) & 0xf000000) != 0x3000000) || (999 < iVar11)) break;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(ushort *)(param_1 + 0x5e));
    }
    goto LAB_14001e0aa;
  }
  if (sVar1 == 0x300) {
LAB_14001de71:
    uVar10 = 0;
    if (*(short *)(param_1 + 0x5e) != 0) {
      do {
        uVar5 = lm_phy_get_pma_link_status(param_1,1);
        if (((int)uVar5 != 0) &&
           (uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,
                               0xc820), (uVar3 & 0xa000) != 0xa000)) goto LAB_14001de69;
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(ushort *)(param_1 + 0x5e));
    }
  }
  else {
    if (((sVar1 - 0x400U & 0xfcff) != 0) || (sVar1 == 0x700)) {
      if (sVar1 == 0x700) {
        uVar10 = 0;
        if (*(short *)(param_1 + 0x5e) != 0) {
          do {
            uVar5 = lm_phy_get_mii_link_status(param_1,1);
            if ((int)uVar5 != 0) goto LAB_14001de69;
            if ((((*(ushort *)(param_1 + 0x14e) & 0x410) != 0) &&
                ((uint)uVar10 == (uVar10 / 2000) * 2000)) &&
               (uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,
                                   0x20), (uVar3 & 0x1000) == 0)) {
              lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x20,
                          uVar3 | 0x1000);
              lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe0,
                          0x1200);
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < *(ushort *)(param_1 + 0x5e));
        }
        goto LAB_14001e0aa;
      }
      if (sVar1 != 0x800) {
        if (sVar1 != 0x900) {
          if ((sVar1 == 0xe00) && (uVar10 = 0, *(short *)(param_1 + 0x5e) != 0)) {
            do {
              uVar5 = lm_phy_get_ieee_link_status(param_1,1);
              if ((int)uVar5 != 0) goto LAB_14001de69;
              uVar10 = uVar10 + 1;
            } while (uVar10 < *(ushort *)(param_1 + 0x5e));
          }
          goto LAB_14001e0aa;
        }
        goto LAB_14001de71;
      }
    }
    uVar10 = 0;
    if (*(short *)(param_1 + 0x5e) != 0) {
      do {
        uVar5 = lm_phy_get_pma_link_status(param_1,1);
        if ((int)uVar5 != 0) goto LAB_14001de69;
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(ushort *)(param_1 + 0x5e));
    }
  }
LAB_14001e0aa:
  if (*(ushort *)(param_1 + 0x70) < uVar10) {
    *(ushort *)(param_1 + 0x70) = uVar10;
  }
  return uVar9;
LAB_14001de69:
  uVar9 = 1;
  goto LAB_14001e0aa;
}



===== lm_is_vntag_enabled @ 14001e0d4 =====

uint lm_is_vntag_enabled(longlong param_1)

{
  return CONCAT31((uint3)(*(uint *)(param_1 + 0x58) >> 0x11),(char)(*(uint *)(param_1 + 0x58) >> 9))
         & 0xffffff01;
}



===== lm_issue_fw_command @ 14001e0e0 =====

uint lm_issue_fw_command(longlong param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar5 = 0;
  *(short *)(param_1 + 0x32) = *(short *)(param_1 + 0x32) + 1;
  uVar1 = *(ushort *)(param_1 + 0x32);
  if (param_2 == 0x21000000) {
    if ((*(byte *)(param_1 + 1) & 0x40) != 0) {
      uVar5 = 2;
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xbf;
      if ((*(short *)(param_1 + 0xfc) == 0x2231) || (*(short *)(param_1 + 0xfc) == -0x7ef9)) {
        uVar5 = 1;
      }
      goto LAB_14001e166;
    }
    uVar5 = 1;
  }
  if (param_2 == 0x10000000) {
    uVar5 = 0x100a;
  }
LAB_14001e166:
  iVar6 = (uint)*(byte *)(param_1 + 0x13b) * 0x2c;
  lm_reg_wr_ind(param_1,*(int *)(param_1 + 0x4c) + 0x688 + iVar6,uVar5);
  lm_reg_wr_ind(param_1,*(int *)(param_1 + 0x4c) + 0x684 + iVar6,uVar1 | param_2);
  iVar3 = 0;
  do {
    uVar2 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x68c + iVar6);
    if ((uint)uVar1 == (uVar2 & 0xffff)) {
      uVar2 = uVar2 & 0xffff0000;
      break;
    }
    mm_stall(1000);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5000);
  uVar4 = 0;
  if (iVar3 != 5000) {
    uVar4 = uVar2;
  }
  return uVar4;
}



===== lm_link_update @ 14001e200 =====

undefined8 lm_link_update(longlong param_1)

{
  byte bVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  iVar6 = 0;
  do {
    mm_stall(1000);
    uVar3 = lm_phy_get_gp_status(param_1);
    if ((uVar3 & 4) != 0) break;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 500);
  bVar2 = false;
  if (0x300 < (uVar3 & 0x3f00)) {
    bVar2 = false;
    if ((uVar3 & 0x3f00) != 0xd00) {
      bVar2 = true;
    }
  }
  if ((uVar3 & 4) != 0) {
    iVar6 = lm_is_phy_link_up(param_1,1);
    if (iVar6 != 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      bVar9 = (char)uVar3 < '\0';
      if (bVar9) {
        *(undefined4 *)(param_1 + 0x10) = 1;
      }
      if ((uVar3 & 0x40) != 0) {
        *(uint *)(param_1 + 0x10) = bVar9 | 2;
      }
      lm_phy_up_init_ext_phy(param_1);
      lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10060,0);
      if (bVar2) {
        lm_enable_bmac(param_1,0);
      }
      else {
        lm_enable_emac(param_1);
        iVar6 = (*(byte *)(param_1 + 0x138) + 0x20) * 0x400;
        uVar7 = *(uint *)(param_1 + 0xc) & 0xff00;
        uVar4 = lm_reg_read_ind(param_1,iVar6);
        uVar8 = uVar4 & 0xffffffd1 | 2;
        if ((*(uint *)(param_1 + 0xc) & 0x10000) == 0) {
          uVar8 = uVar4 & 0xffffffd1;
        }
        if (uVar7 == 0x100) {
          uVar8 = uVar8 | 0xc;
        }
        else if (uVar7 == 0x200) {
          uVar8 = uVar8 | 4;
        }
        else if (uVar7 == 0x300) {
          uVar8 = uVar8 | 8;
        }
        else if (uVar7 == 0x400) {
          uVar8 = uVar8 | 0x28;
        }
        lm_reg_wr_ind(param_1,iVar6,uVar8);
        uVar5 = lm_is_e3(param_1);
        if ((int)uVar5 != 0) {
          lm_program_umac(param_1,uVar7);
        }
      }
      lm_set_link_up(param_1);
      goto LAB_14001e38a;
    }
  }
  lm_set_link_down(param_1);
LAB_14001e38a:
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x100000;
  lm_update_link_mng(param_1);
  if ((uVar3 & 4) != 0) {
    lm_extract_vntag_info(param_1);
  }
  return 0;
}



===== lm_mread22_ext @ 14001e3c8 =====

void lm_mread22_ext(longlong param_1,ushort param_2)

{
  lm_write_mdio_cmd(param_1,((uint)param_2 | (*(ushort *)(param_1 + 300) | 0x140) << 5) << 0x10,
                    *(short *)(param_1 + 0x130),0);
  return;
}



===== lm_mread45 @ 14001e3f4 =====

void lm_mread45(longlong param_1,short param_2,ushort param_3,ushort param_4,ushort param_5)

{
  lm_write_mdio_cmd(param_1,((param_3 | 0x100) << 5 | (uint)param_4) << 0x10 | (uint)param_5,param_2
                    ,1);
  lm_write_mdio_cmd(param_1,((param_3 | 0x160) << 5 | (uint)param_4) << 0x10,param_2,1);
  return;
}



===== lm_mwrite22_ext @ 14001e470 =====

void lm_mwrite22_ext(longlong param_1,ushort param_2,ushort param_3)

{
  lm_write_mdio_cmd(param_1,((uint)param_2 | (*(ushort *)(param_1 + 300) | 0x120) << 5) << 0x10 |
                            (uint)param_3,*(short *)(param_1 + 0x130),0);
  return;
}



===== lm_mwrite45 @ 14001e4a4 =====

void lm_mwrite45(longlong param_1,short param_2,ushort param_3,ushort param_4,ushort param_5,
                ushort param_6)

{
  lm_write_mdio_cmd(param_1,((param_3 | 0x100) << 5 | (uint)param_4) << 0x10 | (uint)param_5,param_2
                    ,1);
  lm_write_mdio_cmd(param_1,(uint)param_6 | ((param_3 | 0x120) << 5 | (uint)param_4) << 0x10,param_2
                    ,1);
  return;
}



===== lm_mwrite45_int2 @ 14001e528 =====

void lm_mwrite45_int2(longlong param_1,ushort param_2,ushort param_3)

{
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,param_2,param_3);
  return;
}



===== lm_phy_8481_get_sigdet @ 14001e554 =====

bool lm_phy_8481_get_sigdet(longlong param_1)

{
  ulonglong uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xfffc,0x7c00);
    uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xfffc);
    if ((uVar1 & 0x20) != 0) break;
    mm_stall(10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return iVar2 != 5;
}



===== lm_phy_84833_cmd_hdlr @ 14001e5fc =====

void lm_phy_84833_cmd_hdlr(longlong param_1,ushort param_2,ushort *param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037,0xa5a5);
  iVar2 = 0;
  iVar3 = 0;
  do {
    sVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037);
    if (sVar1 == 0x10) break;
    mm_stall(1000);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 300);
  if (iVar3 < 300) {
    iVar3 = 0;
    do {
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,
                  (short)iVar3 + 0x4038,*param_3);
      iVar3 = iVar3 + 1;
      param_3 = param_3 + 1;
    } while (iVar3 < 5);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4005,param_2);
    do {
      sVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037)
      ;
      if ((sVar1 - 4U & 0xfffb) == 0) break;
      mm_stall(1000);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 300);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037,0x80);
  }
  return;
}



===== lm_phy_84858_cmd_hdlr @ 14001e790 =====

void lm_phy_84858_cmd_hdlr(longlong param_1,ushort param_2,ushort *param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    sVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037);
    if ((sVar1 != 2) && (sVar1 != -0x4445)) break;
    mm_stall(1000);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 300);
  if (iVar2 < 300) {
    iVar2 = 0;
    do {
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,
                  (short)iVar2 + 0x4038,*param_3);
      iVar2 = iVar2 + 1;
      param_3 = param_3 + 1;
    } while (iVar2 < 5);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4005,param_2);
    do {
      sVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x4037)
      ;
      if ((sVar1 - 4U & 0xfffb) == 0) {
        return;
      }
      mm_stall(1000);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 300);
  }
  return;
}



===== lm_phy_848xx_pre_init @ 14001e8e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lm_phy_848xx_pre_init(longlong param_1,int param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined1 auStackY_58 [32];
  ushort local_28;
  ushort local_26;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  if (param_2 != 0) {
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0,0x8000);
    iVar3 = 0;
    do {
      uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0);
      if ((uVar1 & 0x8000) == 0) break;
      mm_stall(1000);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 500);
    mm_stall(3000000);
  }
  if ((*(ushort *)(param_1 + 0x14e) & 0xc10) == 0) goto LAB_14001ea6b;
  uVar1 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x18c +
                                  (uint)*(byte *)(param_1 + 0x138) * 400);
  uVar1 = uVar1 & 0xff;
  if (uVar1 != 0) {
    local_26 = uVar1;
    if (*(short *)(param_1 + 0x130) != 0x1200) {
      uVar2 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x50) +
                                      (*(byte *)(param_1 + 0x13a) + 0x55) * 4);
      if ((uVar2 & 2) == 0) {
        lm_phy_84833_cmd_hdlr(param_1,0x8001,&local_28);
        goto LAB_14001ea16;
      }
    }
    lm_phy_84858_cmd_hdlr(param_1,0x8001,&local_28);
  }
LAB_14001ea16:
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x401a);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),0x1e,0x401a,
              uVar1 & 0x7fff);
LAB_14001ea6b:
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x20);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x20,uVar1 | 0x1000);
  return;
}



===== lm_phy_848xx_prg_leds @ 14001eae4 =====

void lm_phy_848xx_prg_leds(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa83b);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa83b,
              uVar1 & 0xfe52 | 0x52);
  if ((*(uint *)(param_1 + 0x44) & 0xf0000) == 0xe0000) {
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa82c,0x10);
    uVar2 = 0xa82f;
    uVar1 = 0x80;
  }
  else {
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa82c,0x80);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa82f,0x18);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa832,6);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa834,0);
    uVar2 = 0xa8ec;
    uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xa8ec);
    uVar1 = uVar1 | 0x80;
  }
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,uVar2,uVar1);
  return;
}



===== lm_phy_8727_ctrl_optical_output @ 14001ec90 =====

void lm_phy_8727_ctrl_optical_output(longlong param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800);
  uVar2 = uVar1 & 0x7fff;
  if (param_2 == 0) {
    uVar2 = uVar1 | 0x8000;
  }
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800,uVar2);
  return;
}



===== lm_phy_872x_read_sfp_module_eeprom @ 14001ed18 =====

undefined8 lm_phy_872x_read_sfp_module_eeprom(longlong param_1,ushort param_2)

{
  byte bVar1;
  undefined8 uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  
  sVar3 = *(short *)(param_1 + 0x130);
  if (sVar3 == 0x900) {
    uVar4 = 0x8007;
    uVar5 = 2;
    uVar6 = 0x8002;
    lm_mwrite45(param_1,0x900,*(ushort *)(param_1 + 300),1,0x8004,0x8007);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x8005,0xa101);
    sVar3 = *(short *)(param_1 + 0x130);
  }
  else {
    uVar5 = 0xa001;
    uVar6 = 0x2c0f;
    uVar4 = 0xc820;
  }
  lm_mwrite45(param_1,sVar3,*(ushort *)(param_1 + 300),1,0x8002,uVar5);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x8003,param_2);
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x8000,uVar6);
  uVar6 = 0;
  do {
    bVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0x8000);
    if ((bVar1 & 0xc) == 4) break;
    mm_stall(100);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 100);
  if (uVar6 < 100) {
    uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,uVar4);
  }
  else {
    uVar2 = 0xffff;
  }
  return uVar2;
}



===== lm_phy_check_sigdet @ 14001eec4 =====

bool lm_phy_check_sigdet(longlong param_1)

{
  short sVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined7 extraout_var;
  int iVar4;
  bool bVar5;
  
  bVar5 = false;
  uVar2 = lm_acquire_mdio_hw_lock(param_1,1);
  if ((int)uVar2 == 0) {
    sVar1 = *(short *)(param_1 + 0x130);
    if (sVar1 == 0x700) {
      iVar4 = 0;
      do {
        bVar5 = lm_phy_8481_get_sigdet(param_1);
        if ((int)CONCAT71(extraout_var,bVar5) != 0) break;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 100);
      bVar5 = false;
      if (iVar4 != 100) {
        bVar5 = true;
      }
    }
    else if (sVar1 == 0x900) {
      iVar4 = 0;
      do {
        uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca40);
        if ((uVar3 & 4) == 0) break;
        mm_stall(1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 5);
      bVar5 = iVar4 != 5;
    }
    else if ((sVar1 != 0xe00) || (uVar2 = lm_phy_ieee_get_sigdet(param_1), (int)uVar2 != 0)) {
      bVar5 = true;
    }
    lm_release_mdio_hw_lock(param_1);
  }
  else {
    bVar5 = false;
  }
  return bVar5;
}



===== lm_phy_cx4_get_sigdet @ 14001efa4 =====

bool lm_phy_cx4_get_sigdet(longlong param_1)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x80b0);
    if ((uVar1 & 0x8000) != 0) break;
    mm_stall(100);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1000);
  return iVar2 != 1000;
}



===== lm_phy_force_unicore_speed @ 14001f014 =====

void lm_phy_force_unicore_speed(longlong param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  
  if (((*(byte *)(param_1 + 0x14e) & 0x20) != 0) &&
     ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x1000000)) {
    lm_mwrite45_int2(param_1,0x8345,0xc000);
    lm_warpcore_clear_configs(param_1);
    if ((param_2 & 0xff00) == 0x600) {
      lm_phy_warpcore_set_10G_XFI(param_1,1);
    }
    else {
      lm_phy_warpcore_set_sgmii(param_1,1);
    }
    lm_mwrite45_int2(param_1,0x8345,0);
    if ((param_2 & 0xff00) == 0x600) {
      return;
    }
    uVar3 = 0xffe0;
    uVar1 = 0x1200;
    goto LAB_14001f185;
  }
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8308);
  uVar1 = uVar1 & 0xffe0;
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300);
  uVar4 = param_2 & 0xff00;
  uVar3 = uVar2 | 1;
  if (uVar4 == 0x100) {
    uVar3 = 0;
LAB_14001f15c:
    lm_mwrite45_int2(param_1,0xffe0,uVar3);
    uVar3 = uVar2 & 0xfffe;
  }
  else {
    if (uVar4 == 0x200) {
      uVar3 = 0x2000;
      goto LAB_14001f15c;
    }
    if (uVar4 == 0x300) {
      uVar3 = 0x40;
      goto LAB_14001f15c;
    }
    if (uVar4 == 0x400) {
      uVar1 = uVar1 | 0x10;
    }
    else if (uVar4 == 0x600) {
      uVar1 = uVar1 | 0x14;
    }
  }
  lm_mwrite45_int2(param_1,0x8300,uVar3);
  uVar3 = 0x8308;
LAB_14001f185:
  lm_mwrite45_int2(param_1,uVar3,uVar1);
  return;
}



===== lm_phy_get_gp_status @ 14001f1ac =====

void lm_phy_get_gp_status(longlong param_1)

{
  if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
    lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x812b);
    return;
  }
  lm_phy_warpcore_get_gp_status(param_1);
  return;
}



===== lm_phy_get_ieee_link_status @ 14001f1e4 =====

undefined8 lm_phy_get_ieee_link_status(longlong param_1,ushort param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  
  lm_mread22_ext(param_1,1);
  uVar2 = 0;
  while( true ) {
    if (param_2 <= uVar2) {
      return 0;
    }
    mm_stall(1000);
    uVar1 = lm_mread22_ext(param_1,1);
    if ((uVar1 & 4) != 0) break;
    uVar2 = uVar2 + 1;
  }
  return 1;
}



===== lm_phy_get_mii_link_status @ 14001f24c =====

undefined8 lm_phy_get_mii_link_status(longlong param_1,ushort param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      mm_stall(1000);
      uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe1);
      if ((uVar1 & 4) != 0) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return 0;
}



===== lm_phy_get_pma_link_status @ 14001f2c8 =====

undefined8 lm_phy_get_pma_link_status(longlong param_1,ushort param_2)

{
  ulonglong uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      mm_stall(1000);
      uVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,1);
      if ((uVar1 & 4) != 0) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return 0;
}



===== lm_phy_get_shmem_link_status @ 14001f33c =====

uint lm_phy_get_shmem_link_status(longlong param_1)

{
  uint uVar1;
  
  uVar1 = lm_reg_read_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 0x10 +
                                  *(int *)(param_1 + 0x4c) + 0x664);
  return uVar1 & 1;
}



===== lm_phy_get_sigdet @ 14001f364 =====

uint lm_phy_get_sigdet(longlong param_1)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  int iVar6;
  
  uVar4 = 0;
  uVar5 = lm_acquire_mdio_hw_lock(param_1,1);
  if ((int)uVar5 != 0) {
    return 0;
  }
  sVar1 = *(short *)(param_1 + 0x130);
  if (sVar1 == 0) {
    if ((*(byte *)(param_1 + 0x14e) & 0x20) != 0) {
      if ((((*(byte *)(param_1 + 1) & 1) == 0) &&
          (uVar4 = *(uint *)(param_1 + 0x148) & 0xf000000, (uVar4 - 0x1000000 & 0xfcffffff) == 0))
         && (uVar4 != 0x4000000)) {
        if (((*(uint *)(param_1 + 0x58) & 0x24) == 0) ||
           (uVar4 = lm_phy_get_shmem_link_status(param_1), uVar4 == 0)) {
          ev_lm_init_phy(param_1,(byte)*(undefined4 *)(param_1 + 0x18c));
          *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe;
          uVar3 = lm_phy_warpcore_get_gp_status(param_1);
          uVar4 = (uint)uVar3;
        }
      }
      else {
        bVar2 = lm_phy_wc_get_sigdet(param_1);
        uVar4 = (uint)CONCAT71(extraout_var_00,bVar2);
      }
    }
    goto LAB_14001f56a;
  }
  if (((sVar1 != 0x300) && (sVar1 != 0x400)) && (sVar1 != 0x500)) {
    if (sVar1 == 0x600) {
      iVar6 = 0;
      do {
        uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc804);
        if ((uVar3 & 0x6060) == 0x60) break;
        mm_stall(10);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 10);
      uVar4 = (uint)(iVar6 != 10);
      goto LAB_14001f56a;
    }
    if (sVar1 == 0x700) {
      if (((*(uint *)(param_1 + 0x58) & 0x24) == 0) ||
         (uVar4 = lm_phy_get_shmem_link_status(param_1), uVar4 == 0)) {
        if ((*(byte *)(param_1 + 1) & 1) == 0) {
          ev_lm_init_phy(param_1,(byte)*(undefined4 *)(param_1 + 0x18c));
          *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe;
        }
        bVar2 = lm_phy_8481_get_sigdet(param_1);
        uVar4 = (uint)CONCAT71(extraout_var,bVar2);
      }
      goto LAB_14001f56a;
    }
    if (((sVar1 != 0x800) && (sVar1 != 0x900)) && (sVar1 == 0xe00)) {
      if (((*(uint *)(param_1 + 0x58) & 0x24) == 0) ||
         (uVar4 = lm_phy_get_shmem_link_status(param_1), uVar4 == 0)) {
        if ((*(byte *)(param_1 + 1) & 1) == 0) {
          ev_lm_init_phy(param_1,(byte)*(undefined4 *)(param_1 + 0x18c));
          *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe;
        }
        uVar5 = lm_phy_ieee_get_sigdet(param_1);
        uVar4 = (uint)uVar5;
      }
      goto LAB_14001f56a;
    }
  }
  uVar4 = 1;
LAB_14001f56a:
  lm_release_mdio_hw_lock(param_1);
  return uVar4;
}



===== lm_phy_get_warpcore_lane @ 14001f590 =====

char lm_phy_get_warpcore_lane(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  
  bVar3 = *(byte *)(param_1 + 0x139);
  bVar5 = *(byte *)(param_1 + 0x138);
  if (*(char *)(param_1 + 0x158) == '\0') {
    uVar2 = lm_reg_read_ind(param_1,0xa738);
    if ((uVar2 & 1) == 0) {
      uVar1 = lm_reg_read_ind(param_1,0xa75c);
    }
    else {
      uVar1 = lm_reg_read_ind(param_1,0xa738);
      uVar1 = uVar1 & 2;
    }
    bVar6 = bVar3 ^ 1;
    if (uVar1 == 0) {
      bVar6 = bVar3;
    }
    uVar2 = lm_reg_read_ind(param_1,0xa734);
    if ((uVar2 & 1) == 0) {
      uVar1 = lm_reg_read_ind(param_1,0xa754);
    }
    else {
      uVar1 = lm_reg_read_ind(param_1,0xa734);
      uVar1 = uVar1 & 2;
    }
    bVar3 = bVar5 ^ 1;
    if (uVar1 == 0) {
      bVar3 = bVar5;
    }
    cVar4 = bVar3 * '\x02' + bVar6;
  }
  else {
    uVar2 = lm_reg_read_ind(param_1,0xa72c);
    if ((uVar2 & 1) == 0) {
      uVar1 = lm_reg_read_ind(param_1,0xa758);
    }
    else {
      uVar1 = lm_reg_read_ind(param_1,0xa72c);
      uVar1 = uVar1 & 2;
    }
    bVar5 = bVar3 ^ 1;
    if (uVar1 == 0) {
      bVar5 = bVar3;
    }
    cVar4 = bVar5 * '\x02';
  }
  return cVar4;
}



===== lm_phy_ieee_get_sigdet @ 14001f690 =====

undefined8 lm_phy_ieee_get_sigdet(longlong param_1)

{
  ulonglong uVar1;
  int iVar2;
  
  lm_mwrite22_ext(param_1,0x1c,0x7c00);
  iVar2 = 0;
  do {
    uVar1 = lm_mread22_ext(param_1,0x1c);
    if ((uVar1 & 0x20) != 0) {
      return 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return 0;
}



===== lm_phy_init_link_part2 @ 14001f6dc =====

void lm_phy_init_link_part2(longlong param_1)

{
  uint uVar1;
  
  uVar1 = lm_get_link_speed(param_1);
  *(uint *)(param_1 + 0xc) = uVar1;
  if (*(short *)(param_1 + 0x130) != 0) {
    lm_phy_force_unicore_speed(param_1,uVar1);
  }
  lm_link_update(param_1);
  return;
}



===== lm_phy_initialize_link @ 14001f710 =====

void lm_phy_initialize_link(longlong param_1,uint param_2)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  byte bVar8;
  
  bVar8 = *(byte *)(param_1 + 0x138);
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffefffff;
  bVar2 = false;
  *(undefined4 *)(param_1 + 4) = 5;
  lm_update_link_mng(param_1);
  if (((*(ushort *)(param_1 + 0x14e) & 0x100) != 0) &&
     (uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1b4 + (uint)bVar8 * 400),
     (uVar4 & 0xff00) == 0xfd00)) {
    return;
  }
  if ((param_2 & 0xff) == 0xfb) {
    lm_enable_bmac(param_1,1);
    lm_reg_wr_ind(param_1,(uint)bVar8 * 4 + 0x10060,0);
  }
  else {
    uVar6 = lm_acquire_mdio_hw_lock(param_1,1);
    if ((int)uVar6 == 0) {
      if ((((*(short *)(param_1 + 0x130) == 0x300) || (*(short *)(param_1 + 0x130) == 0x900)) &&
          (lm_bcm8073_load_spi_rom(param_1), *(short *)(param_1 + 0x130) == 0x300)) &&
         ((*(uint *)(param_1 + 0x134) & 0x10000) != 0)) {
        uVar3 = lm_mread45(param_1,0x300,*(ushort *)(param_1 + 300),1,0xcd08);
        lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xcd08,
                    uVar3 | 0x600);
      }
      if (((*(uint *)(param_1 + 0x148) & 0x100000) != 0) && (*(short *)(param_1 + 0x130) == 0x300))
      {
        uVar3 = lm_mread45(param_1,0x300,*(ushort *)(param_1 + 300),7,0x8350);
        lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x8350,
                    uVar3 | 3);
      }
      iVar5 = lm_phy_reinit_required(param_1);
      *(uint *)(param_1 + 8) = (iVar5 != 0) + 4;
      if (iVar5 != 0) {
        lm_reset_ext_phy(param_1);
      }
      if (((*(byte *)(param_1 + 0x14e) & 0x20) != 0) &&
         ((iVar5 != 0 || (*(short *)(param_1 + 0x130) != 0)))) {
        lm_phy_warpcore_config_init(param_1);
      }
      lm_phy_unicore_config_init(param_1,param_2);
      if (iVar5 == 0) {
        bVar8 = *(byte *)(param_1 + 1);
        if ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x5000000) {
          bVar8 = bVar8 | 0x40;
          *(byte *)(param_1 + 1) = bVar8;
        }
        sVar1 = *(short *)(param_1 + 0x130);
        if (sVar1 == 0x600) {
          *(byte *)(param_1 + 1) = bVar8 | 4;
        }
        else if ((sVar1 == 0x700) || (sVar1 == 0xe00)) {
          *(byte *)(param_1 + 1) = bVar8 | 1;
        }
      }
      if (((((*(byte *)(param_1 + 1) & 1) == 0) || (iVar5 != 0)) || ((param_2 & 0xff) == 0xf7)) &&
         (*(short *)(param_1 + 0x130) != 0)) {
        lm_init_ext_phy(param_1);
      }
      if (((*(byte *)(param_1 + 0x14e) & 0x20) != 0) && (iVar5 != 0)) {
        lm_phy_warpcore_config_runtime(param_1);
        uVar7 = lm_phy_get_gp_status(param_1);
        if (((uVar7 & 4) == 0) && ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x5000000)) {
          uVar6 = lm_phy_warpcore_check_KR2_wa(param_1);
          if ((short)uVar6 != 0) {
            lm_phy_warpcore_reset_KR2_cfg(param_1);
          }
          lm_phy_warpcore_config_runtime(param_1);
        }
      }
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 1;
      if ((*(byte *)(param_1 + 1) & 2) == 0) {
        iVar5 = 1;
        while (((iVar5 = lm_is_phy_link_up(param_1,iVar5), iVar5 != 0 &&
                (lm_phy_init_link_part2(param_1), !bVar2)) && (*(int *)(param_1 + 4) != 4))) {
          bVar2 = true;
          iVar5 = 0;
        }
      }
      lm_release_mdio_hw_lock(param_1);
    }
  }
  return;
}



===== lm_phy_program_serdes @ 14001fa2c =====

void lm_phy_program_serdes(longlong param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0xffe0);
  uVar2 = uVar1 & 0xeeff | 0x100;
  if ((param_2 & 0x10000) != 0) {
    uVar2 = uVar1 & 0xeeff;
  }
  lm_mwrite45_int2(param_1,0xffe0,uVar2);
  if (0x300 < (param_2 & 0xff00)) {
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8308);
    uVar2 = uVar1 & 0xfff0 | 0x6014;
    if ((param_2 & 0xff00) != 0x600) {
      uVar2 = uVar1 & 0xfff0 | 0x6010;
    }
    lm_mwrite45_int2(param_1,0x8308,uVar2);
  }
  return;
}



===== lm_phy_reinit_required @ 14001fafc =====

undefined4 lm_phy_reinit_required(longlong param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  
  uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,2);
  uVar3 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,3);
  sVar4 = *(short *)(param_1 + 0x130);
  uVar7 = uVar3 & 0xfff0 | (uint)uVar2 << 0x10;
  if (sVar4 == 0) {
    if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
      return 1;
    }
    if ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x3000000) {
      uVar3 = 0xa0;
      uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),7,0x11);
      if (*(short *)(param_1 + 0xfc) == -0x7ef9) {
        uVar7 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1b8 +
                                        (uint)*(byte *)(param_1 + 0x138) * 400);
        uVar3 = (ushort)(uVar7 >> 0xf) & 0xfffe;
      }
      if ((uVar2 & 0xa0) != uVar3) {
        return 1;
      }
    }
    uVar6 = lm_phy_get_gp_status(param_1);
    if ((uVar6 & 4) == 0) {
      return 1;
    }
    if (((*(uint *)(param_1 + 0x148) & 0xf000000) + 0xfd000000 & 0xfdffffff) != 0) {
      return 0;
    }
    uVar7 = lm_get_link_speed(param_1);
    if ((uVar7 & 0xff00) == 0x300) {
      return 1;
    }
    return 0;
  }
  if (sVar4 == 0x300) {
    bVar1 = lm_mread45(param_1,0x300,*(ushort *)(param_1 + 300),7,0x11);
    if ((bVar1 & 0x80 | 0x20) != 0xa0) {
      return 1;
    }
    bVar1 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0x8329);
    if ((bVar1 & 1) == 0) {
      return 1;
    }
  }
  else {
    if (((sVar4 - 0x400U & 0xfcff) == 0) && (sVar4 != 0x700)) {
      return 1;
    }
    if (sVar4 == 0x700) {
      if (((uVar7 != 0x205c60) && (uVar7 != 0x3625cb0)) && (uVar7 != 0x3625c30)) {
        return 1;
      }
      uVar2 = lm_mread45(param_1,0x700,*(ushort *)(param_1 + 300),1,0);
      if ((uVar2 & 0x8000) != 0) {
        return 1;
      }
      uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe9);
      if ((uVar2 & 0x200) == 0) {
        return 1;
      }
      uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe4);
      if ((uVar2 & 0x140) != 0x140) {
        return 1;
      }
      sVar4 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),7,0xffe0);
      if (sVar4 == 0) {
        return 1;
      }
      iVar8 = 0;
      do {
        uVar5 = lm_phy_get_mii_link_status(param_1,10);
        if ((int)uVar5 == 0) break;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 5);
      goto LAB_14001fe70;
    }
    if (sVar4 != 0x900) {
      if (sVar4 != 0xe00) {
        return 1;
      }
      uVar2 = lm_mread22_ext(param_1,2);
      uVar7 = lm_mread22_ext(param_1,3);
      if ((uVar7 & 0xfff0 | (uint)uVar2 << 0x10) != 0x3625d10) {
        return 1;
      }
      uVar2 = lm_mread22_ext(param_1,0);
      if ((uVar2 & 0x1000) == 0) {
        return 1;
      }
      uVar2 = lm_mread22_ext(param_1,4);
      if ((uVar2 & 0x1e0) != 0x1e0) {
        return 1;
      }
      uVar2 = lm_mread22_ext(param_1,9);
      if ((uVar2 & 0x300) != 0x300) {
        return 1;
      }
      uVar5 = lm_phy_get_ieee_link_status(param_1,5);
      if ((int)uVar5 == 0) {
        return 1;
      }
      return 0;
    }
    uVar2 = 0xd;
    bVar9 = (*(uint *)(param_1 + 0x18c) & 0xff00) != 0x300;
    if (bVar9) {
      uVar2 = 8;
    }
    uVar3 = 0x40;
    if (bVar9) {
      uVar3 = 0x2040;
    }
    lm_mwrite45(param_1,0x900,*(ushort *)(param_1 + 300),1,0,uVar3);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,7,uVar2);
  }
  iVar8 = 0;
  do {
    uVar5 = lm_phy_get_pma_link_status(param_1,400);
    if ((int)uVar5 == 0) break;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 5);
LAB_14001fe70:
  if (iVar8 == 5) {
    return 0;
  }
  return 1;
}



===== lm_phy_set_aer_mmd @ 14001ff6c =====

void lm_phy_set_aer_mmd(longlong param_1)

{
  byte bVar1;
  undefined8 uVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  
  sVar3 = (ushort)*(byte *)(param_1 + 0x14c) + *(short *)(param_1 + 0x122);
  if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
    uVar2 = lm_is_dual_core(param_1);
    sVar5 = sVar3 + -1;
    if ((int)uVar2 == 0) {
      sVar5 = sVar3;
    }
    uVar4 = sVar5 + 0x3800;
  }
  else {
    bVar1 = lm_phy_get_warpcore_lane(param_1);
    uVar4 = (ushort)bVar1;
    if ((*(byte *)(param_1 + 0x14e) & 0x40) != 0) {
      uVar4 = (ushort)(bVar1 | 0x400) >> 1;
    }
  }
  lm_mwrite45_int2(param_1,0xffde,uVar4);
  return;
}



===== lm_phy_set_autoneg @ 14001ffe4 =====

void lm_phy_set_autoneg(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar3 = *(uint *)(param_1 + 0x18c) & 0xff00;
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0xffe0);
  uVar4 = 0x1000;
  if (*(short *)(param_1 + 0x130) != 0) {
    uVar3 = 0x600;
  }
  uVar2 = uVar1 | 0x1000;
  if (uVar3 != 0) {
    uVar2 = uVar1 & 0xedff;
  }
  lm_mwrite45_int2(param_1,0xffe0,uVar2);
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300);
  uVar1 = uVar2 & 0xfffb | 0x10;
  if (uVar3 != 0) {
    uVar1 = uVar2 & 0xffeb;
  }
  lm_mwrite45_int2(param_1,0x8300,uVar1);
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8350);
  uVar1 = uVar2 | 3;
  if (uVar3 != 0) {
    uVar1 = uVar2 & 0xfffc;
  }
  lm_mwrite45_int2(param_1,0x8350,uVar1);
  if (*(short *)(param_1 + 0x130) == 0) {
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8370);
    lm_mwrite45_int2(param_1,0x8370,uVar1 | 2);
    lm_mwrite45_int2(param_1,0x8372,0xe000);
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x11);
    lm_mwrite45_int2(param_1,0x11,uVar1 | 0x60);
  }
  else {
    uVar4 = 0;
  }
  lm_mwrite45_int2(param_1,0,uVar4);
  return;
}



===== lm_phy_set_master_ln @ 1400201a0 =====

void lm_phy_set_master_ln(longlong param_1)

{
  ushort uVar1;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8105);
  lm_mwrite45_int2(param_1,0x8105,*(byte *)(param_1 + 0x14c) | uVar1);
  return;
}



===== lm_phy_unicore_config_init @ 1400201ec =====

void lm_phy_unicore_config_init(longlong param_1,uint param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  ushort *puVar4;
  
  if ((*(byte *)(param_1 + 0x14e) & 0x20) == 0) {
    lm_phy_set_aer_mmd(param_1);
    lm_phy_set_master_ln(param_1);
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0xffe0);
    lm_mwrite45_int2(param_1,0xffe0,uVar1 | 0x8000);
    iVar3 = 0;
    do {
      mm_stall(500);
      uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0xffe0);
      if ((uVar1 & 0x8000) == 0) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 1000);
    lm_phy_set_aer_mmd(param_1);
    lm_phy_set_master_ln(param_1);
    if (*(byte *)(param_1 + 0x13f) == 0x1b) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(byte *)(param_1 + 0x13f) | 0xc000;
    }
    lm_mwrite45_int2(param_1,0x8100,uVar1);
    if (*(byte *)(param_1 + 0x140) == 0x1b) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(byte *)(param_1 + 0x140) | 0x8000;
    }
    lm_mwrite45_int2(param_1,0x8101,uVar1);
    if (((*(uint *)(param_1 + 0x58) & 2) != 0) && (*(short *)(param_1 + 0x130) == 0)) {
      iVar3 = 0;
      puVar4 = (ushort *)(param_1 + 0xa4);
      do {
        sVar2 = (short)iVar3 * 0x10;
        lm_mwrite45_int2(param_1,sVar2 + 0x80bc,puVar4[-4]);
        lm_mwrite45_int2(param_1,sVar2 + 0x8067,*puVar4);
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar3 < 4);
    }
    if (*(short *)(param_1 + 0x130) == 0) {
      uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8301);
      lm_mwrite45_int2(param_1,0x8301,uVar1 | 1);
      lm_mwrite45_int2(param_1,0x8133,0x16e2);
      uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8131);
      lm_mwrite45_int2(param_1,0x8131,uVar1 | 1);
      lm_mwrite45_int2(param_1,0x8104,0x11);
      if ((*(short *)(param_1 + 0x130) == 0) && ((*(uint *)(param_1 + 0x18c) & 0xff00) == 0)) {
        lm_mwrite45_int2(param_1,0x8329,0x11);
        lm_mwrite45_int2(param_1,0xffe4,0x1a0);
        lm_phy_set_autoneg(param_1);
        uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0);
        lm_mwrite45_int2(param_1,0,uVar1 | 0x1200);
        return;
      }
    }
    lm_phy_set_autoneg(param_1);
    lm_phy_program_serdes(param_1,param_2);
  }
  return;
}



===== lm_phy_up_init_ext_phy @ 14002049c =====

void lm_phy_up_init_ext_phy(longlong param_1)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  sVar1 = *(short *)(param_1 + 0x130);
  if (sVar1 == 0x300) {
    if ((*(uint *)(param_1 + 0x134) & 0x10000) == 0) {
      return;
    }
    uVar2 = 4;
    uVar3 = lm_mread45(param_1,0x300,*(ushort *)(param_1 + 300),4,0x80fa);
    uVar4 = uVar3 | 8;
    if ((*(uint *)(param_1 + 0xc) & 0xff00) != 0x300) {
      uVar4 = uVar3 & 0xfff7;
    }
    uVar3 = 0x80fa;
  }
  else if ((sVar1 - 0x400U & 0xfeff) == 0) {
    lm_mwrite45(param_1,sVar1,*(ushort *)(param_1 + 300),1,0xca0a,0x8288);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc800,0x7fbf);
    lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xca09,0x100);
    uVar4 = 1;
    uVar3 = 0x9002;
    uVar2 = 2;
  }
  else {
    if (sVar1 == 0x600) {
      lm_bcm8726_set_limiting_mode(param_1);
      return;
    }
    if (sVar1 != 0x800) {
      if (sVar1 == 0x900) {
        lm_phy_8727_ctrl_optical_output(param_1,1);
        return;
      }
      return;
    }
    uVar2 = 1;
    lm_mwrite45(param_1,0x800,*(ushort *)(param_1 + 300),1,0x9002,1);
    uVar4 = 8;
    uVar3 = 0xc007;
  }
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),uVar2,uVar3,uVar4);
  return;
}



===== lm_phy_warpcore_KR2_supp @ 140020684 =====

void lm_phy_warpcore_KR2_supp(longlong param_1)

{
  ushort uVar1;
  
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,
              (ushort)*(byte *)(param_1 + 0x159) * 0x10 + 0x8077,0x2690);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8368);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8368,uVar1 & 0xff3f);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8436,0xa157);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8438,0xcbe2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8437,0x7537);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8439,0xa157);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x843b,0xcbe2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x843a,0x7537);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8370,10);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8372,0x6400);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8374,0x620);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x837b,0x157);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8453,0x6464);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8454,0x3150);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8455,0x3150);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8456,0x157);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8457,0x620);
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 0x20;
  return;
}



===== lm_phy_warpcore_check_KR2_wa @ 14002098c =====

undefined8 lm_phy_warpcore_check_KR2_wa(longlong param_1)

{
  short sVar1;
  short sVar2;
  undefined8 uVar3;
  int iVar4;
  
  uVar3 = 0;
  iVar4 = 0;
  do {
    sVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),7,0x13);
    sVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),7,0x14);
    if ((sVar1 != 0) || (sVar2 != 0)) break;
    mm_stall(200000);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  if ((-1 < sVar1) || (((byte)sVar2 & 0xe0) == 0x20)) {
    uVar3 = 1;
  }
  return uVar3;
}



===== lm_phy_warpcore_config_init @ 140020a44 =====

void lm_phy_warpcore_config_init(longlong param_1)

{
  char cVar1;
  bool bVar2;
  ushort uVar3;
  ushort uVar4;
  ulonglong uVar5;
  undefined7 extraout_var;
  byte bVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  short sVar10;
  
  cVar1 = lm_phy_get_warpcore_lane(param_1);
  *(char *)(param_1 + 0x159) = cVar1;
  lm_reg_wr_ind(param_1,0xa9a0,1);
  uVar8 = *(uint *)(param_1 + 0x148);
  lm_phy_set_aer_mmd(param_1);
  lm_mwrite45_int2(param_1,0x8345,0xc000);
  uVar8 = uVar8 & 0xf000000;
  if (uVar8 == 0) {
    lm_phy_warpcore_set_sgmii(param_1,0);
  }
  else if (uVar8 == 0x1000000) {
    lm_phy_warpcore_set_10G_XFI(param_1,1);
  }
  else if (uVar8 == 0x2000000) {
    uVar5 = lm_phy_warpcore_read_sfp_module_eeprom(param_1,6);
    if ((uVar5 & 8) != 0) {
      if ((*(short *)(param_1 + 0x130) == 0) && ((*(byte *)(param_1 + 0x14e) & 0x20) != 0)) {
        lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x160),1);
      }
      mm_stall(100000);
      if ((*(short *)(param_1 + 0x130) == 0) && ((*(byte *)(param_1 + 0x14e) & 0x20) != 0)) {
        lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x160),0);
      }
      mm_stall(40000);
      *(undefined1 *)(param_1 + 0x18d) = 3;
    }
    if ((*(uint *)(param_1 + 0x18c) & 0xff00) == 0x300) {
      lm_warpcore_clear_configs(param_1);
      lm_phy_warpcore_set_sgmii(param_1,1);
    }
    else {
      lm_phy_warpcore_set_10G_XFI(param_1,0);
    }
    iVar9 = 2;
    uVar5 = lm_phy_warpcore_read_sfp_module_eeprom(param_1,2);
    if ((uVar5 & 0x21) != 0) {
      uVar5 = lm_phy_warpcore_read_sfp_module_eeprom(param_1,8);
      iVar9 = 2;
      if ((uVar5 & 4) != 0) {
        iVar9 = 3;
      }
    }
    bVar6 = *(char *)(param_1 + 0x159) << 2;
    uVar4 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x81f2);
    sVar10 = 0;
    if (iVar9 == 3) {
      sVar10 = 2;
    }
    lm_mwrite45_int2(param_1,0x81f2,sVar10 << (bVar6 & 0x1f) | uVar4 & ~(0xf << (bVar6 & 0x1f)));
    lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x81f2);
    if ((*(short *)(param_1 + 0x130) == 0) && ((*(byte *)(param_1 + 0x14e) & 0x20) != 0)) {
      lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x160),0);
    }
    lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x15e),0);
  }
  else {
    if (uVar8 == 0x3000000) {
      cVar1 = '\0';
    }
    else {
      if (uVar8 != 0x5000000) goto LAB_140020c87;
      cVar1 = '\x01';
    }
    lm_phy_warpcore_set_KR(param_1,cVar1);
  }
LAB_140020c87:
  if ((*(byte *)(param_1 + 0x14e) & 0x20) != 0) {
    iVar9 = 0;
    do {
      uVar7 = (short)iVar9 * 0x10 + 0x80ba;
      uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,uVar7);
      uVar4 = uVar3 | 0xc;
      if ((0x100000 << ((byte)iVar9 & 0x1f) & *(uint *)(param_1 + 0x168)) == 0) {
        uVar4 = uVar3 & 0xfff3;
      }
      lm_mwrite45_int2(param_1,uVar7,uVar4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
    iVar9 = 0;
    do {
      uVar7 = (short)iVar9 * 0x10 + 0x8061;
      uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,uVar7);
      uVar4 = uVar3 | 0x20;
      if ((0x10000 << ((byte)iVar9 & 0x1f) & *(uint *)(param_1 + 0x168)) == 0) {
        uVar4 = uVar3 & 0xffdf;
      }
      lm_mwrite45_int2(param_1,uVar7,uVar4);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
  }
  uVar4 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x833e);
  lm_mwrite45_int2(param_1,0x833e,uVar4 | 8);
  lm_mwrite45_int2(param_1,0x8345,0);
  bVar2 = lm_phy_wc_get_sigdet(param_1);
  if ((int)CONCAT71(extraout_var,bVar2) != 0) {
    if (*(short *)(param_1 + 0x60) != 0) {
      *(short *)(param_1 + 0x5e) = *(short *)(param_1 + 0x60);
    }
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 8;
  }
  return;
}



===== lm_phy_warpcore_config_runtime @ 140020dd4 =====

void lm_phy_warpcore_config_runtime(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  
  if (((*(uint *)(param_1 + 0x148) & 0xf000000) + 0xfd000000 & 0xfdffffff) == 0) {
    iVar3 = 0;
    do {
      if ((*(byte *)(param_1 + 0x14e) & 0x40) != 0) {
        lm_mwrite45_int2(param_1,0xffde,(ushort)*(byte *)(param_1 + 0x159));
      }
      lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),7,0,0x1200);
      mm_stall(500000);
      uVar2 = lm_phy_get_gp_status(param_1);
      if ((uVar2 & 4) == 0) {
        lm_mwrite45_int2(param_1,0x8345,0xc000);
        lm_mwrite45_int2(param_1,0x8345,0);
      }
      else {
        uVar1 = lm_get_link_speed(param_1);
        if (((uVar1 & 0xff00) != 0x300) || ((*(byte *)(param_1 + 1) & 0x20) == 0)) break;
        lm_phy_warpcore_reset_KR2_cfg(param_1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    if ((*(byte *)(param_1 + 0x14e) & 0x40) != 0) {
      lm_phy_set_aer_mmd(param_1);
    }
  }
  return;
}



===== lm_phy_warpcore_get_gp_status @ 140020ed0 =====

ushort lm_phy_warpcore_get_gp_status(longlong param_1)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar4 = 0;
  cVar1 = lm_phy_get_warpcore_lane(param_1);
  *(char *)(param_1 + 0x159) = cVar1;
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x81d1);
  if (*(short *)(param_1 + 0x130) == 0) {
    uVar2 = uVar2 | (uVar2 & 0xff00) << 4;
  }
  mm_stall(5000);
  uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,
                     (*(byte *)(param_1 + 0x159) >> 1) + 0x81d2);
  if ((*(byte *)(param_1 + 0x159) & 1) == 0) {
    uVar3 = uVar3 << 8;
  }
  if ((uVar3 & 0x3f00) == 0x3900) {
    uVar2 = uVar2 | uVar2 << 0xc;
  }
  if ((((*(uint *)(param_1 + 0x148) & 0xf000000) + 0xfd000000 & 0xfdffffff) == 0) &&
     ((uVar2 >> (*(byte *)(param_1 + 0x159) & 0x1f) & 1) == 0)) {
    uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x81d4);
    uVar2 = uVar2 & 0xf00f;
  }
  if ((*(short *)(param_1 + 0x130) != 0) ||
     ((uVar2 >> ((byte)(*(char *)(param_1 + 0x159) + 0xc) & 0x1f) & 1) != 0)) {
    uVar4 = uVar3 & 0x3f00 | 4;
  }
  return uVar4;
}



===== lm_phy_warpcore_read_sfp_module_eeprom @ 140021020 =====

longlong lm_phy_warpcore_read_sfp_module_eeprom(longlong param_1,byte param_2)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  uint7 extraout_var;
  uint7 extraout_var_00;
  longlong lVar4;
  uint7 uVar5;
  
  uVar2 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x2c);
  uVar3 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x74 +
                                  (uint)*(byte *)(param_1 + 0x138) * 400);
  lm_ctrl_pin_cfg(param_1,(ushort)uVar2 & 0x3f,(uint)((uVar3 & 0x1000000) != 0));
  lm_ctrl_pin_cfg(param_1,(ushort)(uVar2 >> 6) & 0x3f,(uint)((uVar3 & 0x2000000) != 0));
  lm_reg_wr_ind(param_1,0x85900,0x80000000);
  lm_reg_wr_ind(param_1,0x85904,param_2 | 0xa00000);
  lm_reg_wr_ind(param_1,0x85900,0xa0000000);
  bVar1 = lm_e3_imc_done(param_1,10000);
  uVar5 = extraout_var;
  if (bVar1) {
    lm_reg_wr_ind(param_1,0x85900,0x90000001);
    bVar1 = lm_e3_imc_done(param_1,10000);
    uVar5 = extraout_var_00;
    if (bVar1) {
      lVar4 = lm_reg_read_ind(param_1,0x85920);
      return lVar4;
    }
  }
  return (ulonglong)uVar5 << 8;
}



===== lm_phy_warpcore_reset_KR2_cfg @ 140021148 =====

void lm_phy_warpcore_reset_KR2_cfg(longlong param_1)

{
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8436,0x7690);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8438,0xe647);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8437,0xc4f0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8439,0x7690);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x843b,0xe647);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x843a,0xc4f0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8370,0xc);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8372,0x6000);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8374,0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x837b,2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8453,0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8454,0xaf7);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8455,0xaf7);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8456,2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8457,0);
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xdf;
  return;
}



===== lm_phy_warpcore_set_10G_XFI @ 1400213c4 =====

void lm_phy_warpcore_set_10G_XFI(longlong param_1,int param_2)

{
  ushort uVar1;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x821e);
  lm_mwrite45_int2(param_1,0x821e,uVar1 | 0x8000);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8302);
  lm_mwrite45_int2(param_1,0x8302,uVar1 | 1);
  lm_mwrite45_int2(param_1,0,0);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8400);
  lm_mwrite45_int2(param_1,0x8400,uVar1 & 0xfffa);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8402);
  lm_mwrite45_int2(param_1,0x8402,uVar1 | 0x80);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x833c);
  lm_mwrite45_int2(param_1,0x833c,uVar1 & 0xff7f);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300);
  lm_mwrite45_int2(param_1,0x8300,uVar1 & 0xffee);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8301);
  lm_mwrite45_int2(param_1,0x8301,uVar1 & 0xfffe | 6);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8308);
  lm_mwrite45_int2(param_1,0x8308,uVar1 & 0xffe0 | (-(ushort)(param_2 != 0) & 0xfffc) + 9);
  lm_mwrite45_int2(param_1,0x82e2,(-(ushort)(param_2 != 0) & 0xe4be) + 0x3eb2 | 0x8000);
  lm_mwrite45_int2(param_1,(ushort)*(byte *)(param_1 + 0x159) * 0x10 + 0x8067,
                   (-(ushort)(param_2 != 0) & 0xcfd0) + 0x3260);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300);
  lm_mwrite45_int2(param_1,0x8300,uVar1 | 1);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x833c);
  lm_mwrite45_int2(param_1,0x833c,uVar1 | 0x8080);
  lm_mwrite45_int2(param_1,0,0x100);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8302);
  lm_mwrite45_int2(param_1,0x8302,uVar1 & 0xfffe);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x821e);
  lm_mwrite45_int2(param_1,0x821e,uVar1 & 0x7fff);
  return;
}



===== lm_phy_warpcore_set_KR @ 1400216e8 =====

void lm_phy_warpcore_set_KR(longlong param_1,char param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x83c0,0x7415);
  if (*(short *)(param_1 + 0xfc) == -0x7ef9) {
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1b8 +
                                    (uint)*(byte *)(param_1 + 0x138) * 400);
    uVar2 = (ushort)(uVar4 >> 0xf) & 0xfffe;
  }
  else {
    uVar2 = 0xa0;
  }
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),7,0x11,uVar2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),7,0x12,0xc000);
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8349);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8349,uVar2 | 0x100);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8329,0x1f);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,
              (ushort)*(byte *)(param_1 + 0x159) * 0x10 + 0x8067,0x2690);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x82e6,0x3f0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x82e8,0x3f0);
  uVar2 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8349);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8349,uVar2 | 0x100);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8329,0x1f);
  if (param_2 == '\0') {
    lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300,0x10);
    lm_mwrite45_int2(param_1,0xffde,0);
    bVar1 = lm_phy_get_warpcore_lane(param_1);
    uVar5 = (ushort)bVar1 * 0x10 + 0x80ba;
    uVar3 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,uVar5);
    uVar2 = uVar3 | 0x80c;
    if ((0x100000 << (bVar1 & 0x1f) & *(uint *)(param_1 + 0x168)) == 0) {
      uVar2 = uVar3 & 0xfff3 | 0x800;
    }
    lm_mwrite45_int2(param_1,uVar5,uVar2);
    lm_phy_set_aer_mmd(param_1);
    lm_phy_warpcore_reset_KR2_cfg(param_1);
  }
  else {
    lm_phy_warpcore_KR2_supp(param_1);
  }
  return;
}



===== lm_phy_warpcore_set_sgmii @ 140021a0c =====

void lm_phy_warpcore_set_sgmii(longlong param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x83c0);
  lm_mwrite45_int2(param_1,0x83c0,uVar1 & 0x9fff);
  lm_mwrite45_int2(param_1,0xffe0,0x140);
  uVar2 = (-(ushort)(param_2 != 0) & 0xfef1) + 0x110;
  lm_mwrite45_int2(param_1,0x8300,uVar2);
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8301);
  lm_mwrite45_int2(param_1,0x8301,uVar1 & 0xfffb);
  lm_mwrite45_int2(param_1,0x8301,uVar1 | 4);
  lm_mwrite45_int2(param_1,0x8300,uVar2 | 0x10);
  return;
}



===== lm_phy_wc_get_sigdet @ 140021afc =====

bool lm_phy_wc_get_sigdet(longlong param_1)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x81d0);
    if ((uVar1 >> ((byte)(*(char *)(param_1 + 0x159) + 8) & 0x1f) & 1) != 0) break;
    mm_stall(100);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1000);
  return iVar2 != 1000;
}



===== lm_program_umac @ 140021b78 =====

void lm_program_umac(longlong param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (uint)*(byte *)(param_1 + 0x138) * 0x400;
  uVar3 = (*(uint *)(param_1 + 0xc) & 0x10000 | 0x40080c00) >> 6;
  if (param_2 == 0x200) {
    uVar3 = uVar3 | 4;
  }
  else if (param_2 == 0x300) {
    uVar3 = uVar3 | 8;
  }
  else if (param_2 == 0x400) {
    uVar3 = uVar3 | 0xc;
  }
  iVar2 = iVar1 + 0x160008;
  lm_reg_wr_ind(param_1,iVar2,uVar3);
  mm_stall(0x32);
  lm_reg_wr_ind(param_1,iVar2,uVar3 & 0xffffffdf | 3);
  mm_stall(0x32);
  lm_reg_wr_ind(param_1,iVar2,uVar3 & 0xffffdfdf | 3);
  lm_reg_wr_ind(param_1,iVar1 + 0x160014,0x600);
  return;
}



===== lm_reg_bits_dis @ 140021c40 =====

void lm_reg_bits_dis(undefined8 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = lm_reg_read_ind(param_1,param_2 + param_3);
  lm_reg_wr_ind(param_1,param_2 + param_3,uVar1 & ~param_4);
  return;
}



===== lm_reg_bits_en @ 140021c80 =====

void lm_reg_bits_en(undefined8 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = lm_reg_read_ind(param_1,param_2 + param_3);
  lm_reg_wr_ind(param_1,param_2 + param_3,uVar1 | param_4);
  return;
}



===== lm_release_mdio_hw_lock @ 140021cc0 =====

void lm_release_mdio_hw_lock(longlong param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x74);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    lm_reg_wr_ind(param_1,(uint)*(byte *)(param_1 + 0x13a) * 8 + 0xa510,1);
  }
  return;
}



===== lm_reset_all_devices @ 140021ce8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lm_reset_all_devices(longlong param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  undefined1 auStack_78 [32];
  undefined1 local_58;
  uint local_54;
  int local_50;
  longlong local_48;
  uint local_40 [4];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = *(undefined1 *)(param_1 + 0x13b);
  local_40[0] = 0x10000000;
  local_40[1] = 0x11000000;
  local_40[2] = 0x20010000;
  local_40[3] = 0x21000000;
  uVar8 = lm_is_dual_core(param_1);
  if ((int)uVar8 == 0) {
    uVar12 = (-(uint)(((*(uint *)(param_1 + 0x124) & 0xffff0000) + 0xe9b10000 & 0xfffeffff) != 0) &
             0xfffffffa) + 8;
  }
  else {
    uVar12 = 4;
  }
  local_48 = 0;
  local_54 = uVar12;
  do {
    uVar11 = 0;
    local_50 = 0;
    iVar10 = 0;
    lVar13 = local_48;
    do {
      iVar9 = local_50;
      iVar2 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x684 + iVar10);
      if (uVar12 == 2) {
        iVar3 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x44 + iVar9);
        iVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x48 + iVar9);
        if ((iVar3 == -1) && (iVar4 == -1)) {
          iVar2 = 0;
        }
      }
      uVar1 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x684 + iVar10);
      *(undefined2 *)(param_1 + 0x32) = uVar1;
      *(char *)(param_1 + 0x13b) = (char)uVar11;
      if (iVar2 != 0) {
        lm_issue_fw_command(param_1,local_40[lVar13 * 2]);
      }
      uVar11 = uVar11 + 1;
      if ((uVar12 == uVar11) && (local_40[lVar13 * 2] == 0x10000000)) {
        iVar9 = 0x10244;
        uVar12 = 0x1025c;
        do {
          lm_reg_wr_ind(param_1,iVar9 + 0xf7dbc,0x1000);
          lm_reg_wr_ind(param_1,iVar9,0);
          lm_reg_wr_ind(param_1,uVar12,0);
          lm_reg_wr_ind(param_1,iVar9 + -0x61e4,0);
          uVar5 = lm_reg_read_ind(param_1,0x108000);
          lm_reg_wr_ind(param_1,0x108000,uVar5 & 0xffffffe7);
          uVar5 = lm_reg_read_ind(param_1,0x108004);
          lm_reg_wr_ind(param_1,0x108004,uVar5 & 0xffffffe7);
          lm_shutdown_mgmt_to_mcp(param_1);
          lm_reg_wr_ind(param_1,0xa588,0xd3ffffff);
          lm_reg_wr_ind(param_1,0xa598,0x1403);
          uVar6 = lm_reg_read_ind(param_1,0x10394);
          uVar7 = lm_reg_read_ind(param_1,0x10398);
          lm_reg_wr_ind(param_1,0xa584,0x80);
          lm_reg_wr_ind(param_1,0x10394,uVar6);
          lm_reg_wr_ind(param_1,0x10398,uVar7);
          uVar12 = uVar12 + 0x80;
          iVar9 = iVar9 + 4;
        } while (uVar12 < 0x1035c);
        lVar13 = local_48;
        uVar12 = local_54;
        iVar9 = local_50;
      }
      if (iVar2 != 0) {
        lm_issue_fw_command(param_1,local_40[lVar13 * 2 + 1]);
      }
      local_50 = iVar9 + 400;
      iVar10 = iVar10 + 0x2c;
    } while (uVar11 < uVar12);
    local_48 = lVar13 + 1;
  } while (local_48 < 2);
  *(undefined1 *)(param_1 + 0x13b) = local_58;
  return;
}



===== lm_reset_ext_phy @ 140021fc0 =====

undefined8 lm_reset_ext_phy(longlong param_1)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  
  sVar3 = *(short *)(param_1 + 0x130);
  bVar1 = false;
  if (sVar3 == 0x300) goto LAB_1400220fc;
  if ((sVar3 - 0x400U & 0xfeff) == 0) {
LAB_140022136:
    lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\x02','\x01');
    lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\x01','\0');
    mm_stall(1000);
LAB_1400221ae:
    lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\x01','\x01');
  }
  else if (sVar3 == 0x600) {
    sVar3 = lm_mread45(param_1,0x600,*(ushort *)(param_1 + 300),1,0xca1c);
    if (sVar3 != -1) {
      bVar1 = true;
    }
LAB_1400220fc:
    if ((*(ushort *)(param_1 + 0x14e) & 0xc1c) == 0) {
      lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\x02','\x01');
      goto LAB_1400221ae;
    }
    if (*(ushort *)(param_1 + 0x15a) == 0) {
      lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\x03','\x01');
    }
    else if ((*(ushort *)(param_1 + 0x14e) & 0x410) == 0) {
      lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x15a),1);
    }
    else {
      lm_reg_read_ind(param_1,0xa490);
    }
    lm_phy_848xx_pre_init(param_1,1);
  }
  else {
    if (sVar3 == 0x700) goto LAB_1400220fc;
    if (sVar3 == 0x800) goto LAB_140022136;
    if (sVar3 != 0xe00) goto LAB_14002225b;
    if (*(ushort *)(param_1 + 0x15a) != 0) {
      lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x15a),1);
      mm_stall(50000);
    }
    lm_mwrite22_ext(param_1,0,0x8000);
    iVar4 = 0;
    do {
      uVar2 = lm_mread22_ext(param_1,0);
      if ((uVar2 & 0x8000) == 0) break;
      mm_stall(100);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 1000);
    if (*(ushort *)(param_1 + 0x15c) != 0) {
      lm_ctrl_pin_cfg(param_1,*(ushort *)(param_1 + 0x15c),0);
      mm_stall(50000);
    }
  }
  if (!bVar1) {
    uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0);
    if ((uVar2 & 0x8000) == 0) goto LAB_14002225b;
  }
  lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0,0x8000);
  iVar4 = 0;
  do {
    uVar2 = lm_mread45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0);
    if ((uVar2 & 0x8000) == 0) break;
    mm_stall(100);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10000);
  mm_stall(100000);
LAB_14002225b:
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x100000;
  lm_update_link_mng(param_1);
  return 0;
}



===== lm_retrieve_phy_info @ 140022284 =====

void lm_retrieve_phy_info(longlong param_1)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  uVar5 = 0;
  lm_reg_read_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 400 + *(int *)(param_1 + 0x4c) + 0x1b4)
  ;
  uVar2 = lm_reg_read_ind(param_1,(uint)*(byte *)(param_1 + 0x138) * 400 +
                                  *(int *)(param_1 + 0x4c) + 0x19c);
  uVar3 = uVar2 & 0xff00;
  if (((uVar3 == 0) || (uVar3 == 0xfd00)) || (uVar3 == 0xff00)) goto LAB_140022404;
  *(ushort *)(param_1 + 0x14e) = *(ushort *)(param_1 + 0x14e) | 4;
  uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x198 +
                                  (uint)*(byte *)(param_1 + 0x138) * 400);
  do {
    lm_get_phy_info(param_1,uVar6);
    if (*(short *)(param_1 + 0x130) == 0x700) {
      lm_reset_ext_phy(param_1);
      uVar5 = uVar6;
      break;
    }
    uVar6 = uVar6 + 1;
    uVar5 = uVar6;
  } while ((int)uVar6 < 2);
  uVar4 = uVar4 & 7;
  if (uVar4 == 0) {
    uVar2 = lm_mread45(param_1,0x700,uVar2 & 0xff,0x1e,0x401a);
    uVar4 = 4 - ((uVar2 & 0x100) != 0);
  }
  if (uVar4 == 1) {
LAB_1400223e1:
    uVar5 = 0;
  }
  else if (uVar4 == 2) {
LAB_14002245d:
    uVar5 = 1;
  }
  else if (uVar4 == 3) {
    uVar5 = 0;
    lm_get_phy_info(param_1,0);
    if (*(short *)(param_1 + 0x130) != 0x700) {
      lm_reset_ext_phy(param_1);
    }
    lm_init_ext_phy(param_1);
    bVar1 = lm_phy_check_sigdet(param_1);
    if ((int)CONCAT71(extraout_var_00,bVar1) == 0) goto LAB_14002245d;
  }
  else if (uVar4 == 4) {
    lm_get_phy_info(param_1,1);
    if (*(short *)(param_1 + 0x130) != 0x700) {
      lm_reset_ext_phy(param_1);
    }
    lm_init_ext_phy(param_1);
    bVar1 = lm_phy_check_sigdet(param_1);
    uVar5 = 1;
    if ((int)CONCAT71(extraout_var,bVar1) == 0) goto LAB_1400223e1;
  }
  if (*(short *)(param_1 + 0x130) == 0x700) {
    lm_get_phy_info(param_1,uVar5 ^ 1);
    lm_phy_8727_ctrl_optical_output(param_1,0);
  }
LAB_140022404:
  lm_get_phy_info(param_1,uVar5);
  ev_mm_get_user_config(param_1);
  return;
}



===== lm_set_link_down @ 140022468 =====

void lm_set_link_down(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  if ((*(uint *)(param_1 + 0x58) & 0x10000) != 0) {
    lm_reg_bits_dis(param_1,0xa000,0x590,1 << (bVar1 & 0x1f));
    uVar3 = -(uint)(bVar1 != 0) & 0x400;
    uVar2 = lm_reg_read_ind(param_1,uVar3 + 0x800c);
    lm_reg_wr_ind(param_1,uVar3 + 0x800c,uVar2 | 1);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x102f0,0);
    if (*(short *)(param_1 + 0x130) == 0) {
      lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10320,0);
    }
  }
  *(undefined4 *)(param_1 + 4) = 5;
  *(undefined1 *)(param_1 + 0xd) = 0;
  return;
}



===== lm_set_link_up @ 140022520 =====

void lm_set_link_up(longlong param_1)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = *(byte *)(param_1 + 0x138);
  *(undefined4 *)(param_1 + 4) = 4;
  if ((*(uint *)(param_1 + 0x58) & 0x10000) == 0) {
    uVar4 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x664 + (uint)bVar1 * 0x10);
    uVar4 = uVar4 & 0x1e;
    if (uVar4 == 0xe) {
      *(undefined1 *)(param_1 + 0xd) = 3;
    }
    else if (uVar4 == 0x14) {
      *(undefined1 *)(param_1 + 0xd) = 6;
    }
    else if (uVar4 == 0x16) {
      *(undefined1 *)(param_1 + 0xd) = 7;
    }
  }
  else {
    iVar6 = (uint)bVar1 * 4 + 0x102f0;
    lm_reg_wr_ind(param_1,iVar6,*(ushort *)(param_1 + 0x46) & 0xf);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x102f8,0);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10310,0x1e0);
    lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10318,1);
    uVar5 = -(uint)(bVar1 != 0) & 0x400;
    uVar4 = lm_reg_read_ind(param_1,uVar5 + 0x800c);
    lm_reg_wr_ind(param_1,uVar5 + 0x800c,uVar4 & 0xfffffffe);
    sVar2 = *(short *)(param_1 + 0x130);
    if (sVar2 == 0) {
      uVar3 = lm_phy_get_gp_status(param_1);
      if ((uVar3 & 0x3f00) == 0xe00) {
        lm_reg_wr_ind(param_1,iVar6,0);
        lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10320,1);
      }
    }
    else if (sVar2 == 0x600) {
      lm_gpio_write(param_1,*(char *)(param_1 + 0x13a),'\0','\0');
    }
    else if (sVar2 == 0x700) {
      lm_phy_848xx_prg_leds(param_1);
    }
    else if (sVar2 == 0x900) {
      uVar3 = lm_mread45(param_1,0x900,*(ushort *)(param_1 + 300),1,0xc808);
      lm_mwrite45(param_1,*(short *)(param_1 + 0x130),*(ushort *)(param_1 + 300),1,0xc808,
                  uVar3 | 0x60);
    }
    uVar4 = lm_get_link_speed(param_1);
    *(uint *)(param_1 + 0xc) = uVar4 | *(uint *)(param_1 + 0xc) & 0xffff00ff;
  }
  return;
}



===== lm_set_mac_addrs @ 140022710 =====

undefined8 lm_set_mac_addrs(longlong param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  byte bVar7;
  int iVar8;
  undefined4 local_res8;
  
  pcVar4 = *(char **)(param_1 + 0x88);
  pcVar4[2] = '\0';
  pcVar4[3] = '\0';
  pcVar1 = (char *)(param_1 + 0x192);
  pcVar4[1] = *(char *)(param_1 + 0x13d) << 3;
  pcVar2 = (char *)(param_1 + 0x193);
  uVar5 = *(uint *)(param_1 + 0x172);
  *(uint *)(pcVar4 + 4) =
       (uVar5 & 0xff0000 | uVar5 >> 0x10) >> 8 | (uVar5 & 0xff00 | uVar5 << 0x10) << 8;
  bVar7 = 1;
  *(ushort *)(pcVar4 + 8) = *(ushort *)(param_1 + 0x176) << 8 | *(ushort *)(param_1 + 0x176) >> 8;
  *(ushort *)(pcVar4 + 10) = (ushort)*(byte *)(param_1 + 0x13d);
  pcVar4[0xc] = '\0';
  pcVar4[0xd] = '\0';
  pcVar4[0xe] = '\0';
  pcVar4[0xf] = '\0';
  pcVar4[0x10] = '\0';
  pcVar4[0x11] = '\0';
  pcVar4[0x12] = '\0';
  pcVar4[0x13] = '\0';
  if ((*pcVar1 != '\0') || (*pcVar2 != '\0')) {
    local_res8._0_3_ = CONCAT12(*(undefined1 *)(param_1 + 0x194),CONCAT11(*pcVar2,*pcVar1));
    local_res8 = CONCAT13(*(undefined1 *)(param_1 + 0x195),(uint3)local_res8);
    *(uint *)(pcVar4 + 0x14) =
         ((uint3)local_res8 & 0xff0000 | local_res8 >> 0x10) >> 8 |
         ((uint3)local_res8 & 0xff00 | local_res8 << 0x10) << 8;
    bVar7 = 2;
    *(ushort *)(pcVar4 + 0x18) =
         *(ushort *)(param_1 + 0x196) << 8 | *(ushort *)(param_1 + 0x196) >> 8;
    *(ushort *)(pcVar4 + 0x1a) = (ushort)*(byte *)(param_1 + 0x13d);
    pcVar4[0x1c] = '\0';
    pcVar4[0x1d] = '\0';
    pcVar4[0x1e] = '\0';
    pcVar4[0x1f] = '\0';
    pcVar4[0x20] = '\0';
    pcVar4[0x21] = '\0';
    pcVar4[0x22] = '\0';
    pcVar4[0x23] = '\0';
  }
  uVar6 = (ulonglong)bVar7;
  pcVar3 = pcVar4 + uVar6 * 0x10 + 4;
  pcVar3[0] = -1;
  pcVar3[1] = -1;
  pcVar3[2] = -1;
  pcVar3[3] = -1;
  (pcVar4 + uVar6 * 0x10 + 8)[0] = -1;
  (pcVar4 + uVar6 * 0x10 + 8)[1] = -1;
  *(ushort *)(pcVar4 + uVar6 * 0x10 + 10) = (ushort)*(byte *)(param_1 + 0x13d);
  pcVar3 = pcVar4 + uVar6 * 0x10 + 0xc;
  pcVar3[0] = '\x01';
  pcVar3[1] = '\0';
  pcVar3[2] = '\0';
  pcVar3[3] = '\0';
  pcVar3[4] = '\0';
  pcVar3[5] = '\0';
  pcVar3[6] = '\0';
  pcVar3[7] = '\0';
  *pcVar4 = bVar7 + 1;
  lm_sp_post_and_wait(param_1,0x5f,0,*(uint *)(param_1 + 0x94),*(uint *)(param_1 + 0x90));
  if (((*(uint *)(param_1 + 0x58) & 0x20000) != 0) &&
     ((*(short *)(param_1 + 0xec) - 0x500U & 0xfdff) == 0)) {
    iVar8 = 0;
    do {
      everest_init_nig_mac_addr(param_1,iVar8,(undefined1 *)0x0,0);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
    everest_init_nig_mac_addr(param_1,0,(undefined1 *)(param_1 + 0x172),1);
    if ((*(char *)(param_1 + 0x116) != '\0') || (iVar8 = 1, *(char *)(param_1 + 0x117) != '\0')) {
      everest_init_nig_mac_addr(param_1,1,(char *)(param_1 + 0x116),1);
      iVar8 = 2;
    }
    if ((*pcVar1 != '\0') || (*pcVar2 != '\0')) {
      everest_init_nig_mac_addr(param_1,iVar8,pcVar1,1);
    }
  }
  return 0;
}



===== lm_set_xumac_nig @ 14002296c =====

void lm_set_xumac_nig(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = *(char *)(param_1 + 0x138);
  uVar2 = lm_is_e3(param_1);
  if ((int)uVar2 != 0) {
    lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 0x14) + 0x185ac,param_3);
    lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 0x14) + 0x185b0,param_3);
    lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 0x14) + 0x185b4,param_2);
  }
  return;
}



===== lm_setup_bd_chain_ring @ 1400229fc =====

void lm_setup_bd_chain_ring(longlong param_1,uint *param_2,ushort param_3)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = param_2[1];
  uVar3 = 0;
  uVar7 = *param_2;
  lVar5 = param_1;
  if (0 < (int)(param_3 - 1)) {
    lVar4 = param_1;
    uVar1 = uVar7;
    do {
      uVar1 = uVar1 + 0x100;
      uVar2 = uVar6 + 1;
      if (uVar7 <= uVar1) {
        uVar2 = uVar6;
      }
      uVar6 = uVar2;
      uVar7 = uVar7 + 0x100;
      *(uint *)(lVar4 + 0xf4) = uVar6;
      lVar5 = lVar4 + 0x100;
      *(uint *)(lVar4 + 0xf0) = uVar7;
      *(longlong *)(lVar4 + 0xf8) = lVar5;
      uVar3 = uVar3 + 1;
      lVar4 = lVar5;
    } while ((int)(uint)uVar3 < (int)(param_3 - 1));
    uVar6 = param_2[1];
  }
  *(uint *)(lVar5 + 0xf4) = uVar6;
  *(uint *)(lVar5 + 0xf0) = *param_2;
  *(longlong *)(lVar5 + 0xf8) = param_1;
  return;
}



===== lm_shutdown @ 140022a90 =====

undefined8 lm_shutdown(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  longlong lVar6;
  
  bVar1 = param_1[0x138];
  if ((*param_1 & 2) == 0) {
    *param_1 = *param_1 | 2;
    if ((*(uint *)(param_1 + 0x58) & 0x20000) == 0) {
      lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10244,0);
      if ((*(uint *)(param_1 + 0x58) & 0xc) == 0) {
        lm_reg_wr_ind(param_1,(uint)bVar1 * 0x80 + 0x1025c,0);
      }
      lm_disable_mac((longlong)param_1);
    }
    else {
      lm_reg_wr_ind(param_1,0x160fc,0);
      lm_reg_wr_ind(param_1,0x16100,0);
      iVar5 = 0;
      do {
        everest_init_nig_mac_addr((longlong)param_1,iVar5,(undefined1 *)0x0,0);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      lVar6 = 10;
      do {
        lm_flush_rx_buffers((longlong)param_1);
        mm_stall(1000);
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
    }
    ev_lm_disable_intr((longlong)param_1);
    lm_sp_post_and_wait((longlong)param_1,0x5a,0,0,0);
    lm_sp_post_and_wait((longlong)param_1,100,0,0,0);
    uVar2 = lm_issue_fw_command((longlong)param_1,
                                (-(uint)((*(uint *)(param_1 + 0x58) & 0x20) != 0) & 0x10000) +
                                0x20010000);
    if (uVar2 != 0x20120000) {
      bVar1 = param_1[0x138];
      lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x10330,0);
      lm_disable_mac((longlong)param_1);
      lm_reg_wr_ind(param_1,0xa5a8,0x1f0 << ((bVar1 & 1) << 4));
      lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0x108000,0x1000);
      lm_reg_wr_ind(param_1,(uint)bVar1 * 4 + 0xa060,0);
      if ((uVar2 == 0x20100000) || ((*(uint *)(param_1 + 0x58) & 1) != 0)) {
        uVar3 = lm_reg_read_ind(param_1,0x10394);
        uVar4 = lm_reg_read_ind(param_1,0x10398);
        uVar2 = *(uint *)(param_1 + 0x58);
        if ((uVar2 & 0xc) == 0) {
          lm_shutdown_mgmt_to_mcp((longlong)param_1);
        }
        lm_reg_wr_ind(param_1,0xa588,(-(uint)((uVar2 & 0xc) != 0) & 0xffffff80) + 0xd3ffffff);
        lm_reg_wr_ind(param_1,0xa598,0x1403);
        if ((*(uint *)(param_1 + 0x58) & 0xc) == 0) {
          lm_reg_wr_ind(param_1,0xa584,0x80);
        }
        lm_reg_wr_ind(param_1,0x10394,uVar3);
        lm_reg_wr_ind(param_1,0x10398,uVar4);
      }
    }
    lm_issue_fw_command((longlong)param_1,0x21000000);
    mm_stall(1000);
    lm_reg_wr_ind(param_1,0xa45c,0xffffffff);
    iVar5 = lm_reg_read_ind(param_1,0x907c);
    if (iVar5 != 0) {
      lm_reg_wr_ind(param_1,38000,iVar5);
    }
    if (param_1[0x13d] < 2) {
      mm_pcicfg_map((longlong)param_1,0);
    }
    storport_pci_cfg_write_dword(param_1,0x78,0);
  }
  return 0;
}



===== lm_shutdown_mgmt_to_mcp @ 140022d44 =====

void lm_shutdown_mgmt_to_mcp(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = lm_is_e3(param_1);
  if ((int)uVar1 == 0) {
    lm_reg_wr_ind(param_1,0x100a4,0);
    lm_reg_wr_ind(param_1,0x100a8,0);
    uVar3 = 0x100b0;
    uVar2 = 0x100ac;
  }
  else {
    uVar3 = 0x185c0;
    uVar2 = 0x185ac;
  }
  lm_reg_wr_ind(param_1,uVar2,0);
  lm_reg_wr_ind(param_1,uVar3,0);
  mm_stall(200000);
  return;
}



===== lm_sp_post_and_wait @ 140022db8 =====

bool lm_sp_post_and_wait(longlong param_1,uint param_2,byte param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined1 *)(param_1 + 0x6e) = 0;
  if (*(char *)(param_1 + 0x6d8) == '\0') {
    puVar1 = *(uint **)(param_1 + 0x6e0);
    *(undefined1 *)(param_1 + 0x6d8) = 1;
    uVar2 = (uint)*(byte *)(param_1 + 0x138) << 0x17 | (uint)param_3;
    if ((*(uint *)(param_1 + 0x58) & 0x20000) != 0) {
      uVar2 = uVar2 | (uint)*(byte *)(param_1 + 0x13b) << 0x11;
    }
    *puVar1 = param_2 << 0x18 | uVar2;
    puVar1[1] = (uint)(param_2 == 100);
    puVar1[2] = param_5;
    puVar1[3] = param_4;
    *(short *)(param_1 + 0x6e8) = *(short *)(param_1 + 0x6e8) + 1;
    lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 0xc0),(uint)*(ushort *)(param_1 + 0x6e8));
  }
  iVar3 = 0;
  do {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x200000;
    ev_lm_service_intr(param_1);
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffdfffff;
    if (*(char *)(param_1 + 0x6d8) == '\0') break;
    mm_stall(100);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 1000);
  lm_ack_enable_intr(param_1);
  return param_2 != *(byte *)(param_1 + 0x6e);
}



===== lm_strip_vntag_vlan_hdr @ 140022ebc =====

longlong lm_strip_vntag_vlan_hdr(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ushort uVar4;
  longlong lVar5;
  
  lVar1 = *(longlong *)(param_2 + 0x38);
  uVar4 = *(ushort *)(lVar1 + 0xc) << 8 | *(ushort *)(lVar1 + 0xc) >> 8;
  if (uVar4 == 0x8100) {
    lVar5 = 4;
  }
  else {
    if (uVar4 != 0x8926) {
      return 0;
    }
    lVar5 = 10;
  }
  lVar3 = 0xc;
  lVar2 = lVar5;
  do {
    *(undefined1 *)(lVar2 + 0xb + lVar1) = *(undefined1 *)((lVar1 - lVar5) + 0xc + lVar2 + -1);
    lVar3 = lVar3 + -1;
    lVar2 = lVar2 + -1;
  } while (lVar3 != 0);
  return lVar5;
}



===== lm_update_link_mng @ 140022f18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void lm_update_link_mng(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  ushort local_54;
  ushort local_52;
  undefined2 local_50;
  undefined2 local_4e;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  uVar4 = 0;
  uVar1 = lm_reg_read_ind(param_1,*(undefined4 *)(param_1 + 0x50));
  if ((0x13c < uVar1) &&
     (iVar2 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x50) +
                                      (*(byte *)(param_1 + 0x138) + 0x4f) * 4), iVar2 != 0)) {
    local_58 = 0x10001;
    if ((*(uint *)(param_1 + 0x18c) >> 0x10 & 1) != 0) {
      local_58 = 0x20002;
    }
    uVar1 = *(uint *)(param_1 + 0x18c) & 0xff00;
    local_54 = *(ushort *)(param_1 + 0x144) & 0x700;
    local_44 = 0x300;
    if (uVar1 == 0x300) {
      local_50 = 1000;
    }
    else if (uVar1 == 0x600) {
      local_50 = 10000;
    }
    else {
      local_50 = 0;
    }
    local_52 = local_54;
    local_4e = local_50;
    uVar1 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x1b8 +
                                    (uint)*(byte *)(param_1 + 0x138) * 400);
    local_48 = uVar1 & 0xffff0000;
    local_4c = uVar1 & 0xffff0000;
    if ((*(byte *)(param_1 + 0x14e) & 4) == 0) {
      local_52 = 0;
      local_4e = 0;
      local_48 = 0;
    }
    puVar3 = &local_58;
    lVar5 = 6;
    do {
      lm_reg_wr_ind(param_1,iVar2,*puVar3);
      iVar2 = iVar2 + 4;
      puVar3 = puVar3 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  if ((*(uint *)(param_1 + 0x58) & 0x100000) != 0) {
    if (*(int *)(param_1 + 4) == 4) {
      uVar1 = *(uint *)(param_1 + 0xc) & 0xff00;
      if (uVar1 == 0x300) {
        uVar4 = 0xf;
      }
      else {
        uVar4 = 0x17;
        if (uVar1 != 0x700) {
          uVar4 = 0x15;
        }
      }
    }
    uVar1 = lm_reg_read_ind(param_1,*(int *)(param_1 + 0x4c) + 0x664 +
                                    (uint)*(byte *)(param_1 + 0x138) * 0x10);
    if (((uVar1 ^ uVar4) & 1) != 0) {
      lm_reg_wr_ind(param_1,*(int *)(param_1 + 0x4c) + 0x664 +
                            (uint)*(byte *)(param_1 + 0x138) * 0x10,uVar4);
      lm_issue_fw_command(param_1,0x1000000);
    }
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffefffff;
  }
  return;
}



===== lm_update_tstorm_rx_indices @ 140023108 =====

void lm_update_tstorm_rx_indices(longlong param_1,undefined2 param_2,undefined2 param_3)

{
  undefined8 uVar1;
  undefined4 local_res10;
  
  local_res10 = CONCAT22(param_3,param_2);
  uVar1 = lm_is_e3(param_1);
  if (((((int)uVar1 == 0) || (*(char *)(param_1 + 0x138) == '\0')) &&
      ((*(uint *)(param_1 + 0x58) & 0x20000) == 0)) && (*(byte *)(param_1 + 0x13d) < 2)) {
    storport_pci_cfg_write_dword(param_1,0x8c,local_res10);
    return;
  }
  lm_reg_wr_ind(param_1,*(undefined4 *)(param_1 + 0xc4),local_res10);
  return;
}



===== lm_validate_vntag_vlan_hdr @ 14002316c =====

byte lm_validate_vntag_vlan_hdr(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  byte bVar2;
  
  if ((*(uint *)(param_1 + 0x58) & 0x200) == 0) {
    bVar2 = 0;
    if ((*(uint *)(param_1 + 0x34) & 0xfff) != 0) {
      lVar1 = *(longlong *)(param_2 + 0x38);
      bVar2 = 1;
      if (*(short *)(lVar1 + 0xc) == 0x81) {
        bVar2 = -((((*(short *)(lVar1 + 0xe) << 8 | (ushort)*(byte *)(lVar1 + 0xf)) ^
                   *(ushort *)(param_1 + 0x34)) & 0xfff) != 0) & 1;
      }
    }
  }
  else {
    lVar1 = *(longlong *)(param_2 + 0x38);
    bVar2 = 1;
    if (((*(short *)(lVar1 + 0xc) == 0x2689) &&
        (((((*(char *)(param_1 + 0x172) != *(char *)(lVar1 + 6) ||
            (*(char *)(param_1 + 0x173) != *(char *)(lVar1 + 7))) ||
           (*(char *)(param_1 + 0x174) != *(char *)(lVar1 + 8))) ||
          ((*(char *)(param_1 + 0x175) != *(char *)(lVar1 + 9) ||
           (*(char *)(param_1 + 0x176) != *(char *)(lVar1 + 10))))) ||
         (*(char *)(param_1 + 0x177) != *(char *)(lVar1 + 0xb))))) &&
       ((param_3 - 2U < 2 ||
        ((*(ushort *)(param_1 + 0x3c) ==
          (ushort)((*(ushort *)(lVar1 + 0xe) & 0x3f) << 8 | (ushort)*(byte *)(lVar1 + 0xf)) &&
         (*(short *)(lVar1 + 0x12) == 0x81)))))) {
      bVar2 = 0;
    }
  }
  return bVar2;
}



===== lm_warpcore_clear_configs @ 140023254 =====

void lm_warpcore_clear_configs(longlong param_1)

{
  ushort uVar1;
  
  uVar1 = lm_mread45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x83c0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x83c0,uVar1 | 0x6000);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),7,0,0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8400,0x14a);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8402,0x800);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x833c,0x8008);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8300,0x195);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8301,7);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8302,2);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x8308,0x6000);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0x82e2,0);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,
              (ushort)*(byte *)(param_1 + 0x159) * 0x10 + 0x8067,0x990);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0,0x2040);
  lm_mwrite45(param_1,0,*(ushort *)(param_1 + 0x122),3,0xffe0,0x140);
  return;
}



===== lm_write_mdio_cmd @ 1400234b4 =====

uint lm_write_mdio_cmd(longlong param_1,undefined4 param_2,short param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  int iVar7;
  
  bVar2 = false;
  iVar4 = lm_get_emac_base(param_1,param_3);
  uVar6 = lm_is_e3(param_1);
  if (((int)uVar6 != 0) && ((*(uint *)(param_1 + 0x124) & 0xf000) != 0)) {
    bVar2 = true;
    lm_reg_bits_en(param_1,iVar4,0xb0,2);
  }
  lm_reg_wr_ind(param_1,iVar4 + 0xb4,(-(uint)(param_4 != 0) & 0x80000000) + 0x310000);
  iVar1 = iVar4 + 0xac;
  lm_reg_wr_ind(param_1,iVar1,param_2);
  iVar7 = 0;
  do {
    mm_stall(10);
    uVar5 = lm_reg_read_ind(param_1,iVar1);
    if ((uVar5 >> 0x1d & 1) == 0) {
      mm_stall(5);
      uVar3 = lm_reg_read_ind(param_1,iVar1);
      uVar5 = (uint)uVar3;
      break;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 50000);
  if (bVar2) {
    lm_reg_bits_dis(param_1,iVar4,0xb0,2);
  }
  return uVar5 & 0xffff;
}



===== ev_mm_get_rx_desc @ 1400235c4 =====

undefined * ev_mm_get_rx_desc(undefined8 param_1,int param_2)

{
  return &dev_rx_packet_ring + (longlong)param_2 * 0x60;
}



===== ev_mm_get_tx_desc @ 1400235dc =====

undefined * ev_mm_get_tx_desc(undefined8 param_1,int param_2)

{
  return &dev_tx_packet_ring + (longlong)param_2 * 0x60;
}



===== ev_mm_get_user_config @ 1400235f4 =====

undefined8 ev_mm_get_user_config(longlong param_1)

{
  short sVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  
  sVar1 = *(short *)(param_1 + 0x130);
  if (sVar1 == 0) {
    *(undefined2 *)(param_1 + 0x5e) = 10000;
    if (((*(byte *)(param_1 + 0x14e) & 0x20) != 0) &&
       ((*(uint *)(param_1 + 0x148) & 0xf000000) == 0x3000000)) {
      *(undefined4 *)(param_1 + 0x5e) = 0xfa003a98;
    }
  }
  else {
    if (sVar1 == 0x300) {
      uVar2 = 15000;
    }
    else if (sVar1 == 0x700) {
      uVar2 = 40000;
    }
    else if (sVar1 == 0x800) {
      uVar2 = 13000;
    }
    else if ((sVar1 == 0x900) || (sVar1 == 0xe00)) {
      if (((*(uint *)(param_1 + 0x58) & 0x200) == 0) || (uVar2 = 0xffff, sVar1 != 0x900)) {
        uVar2 = 10000;
      }
    }
    else {
      uVar2 = 2000;
    }
    *(undefined2 *)(param_1 + 0x5e) = uVar2;
  }
  *(uint *)(param_1 + 0x18c) = *(uint *)(param_1 + 0x18c) & 0xfffeffff;
  *(undefined4 *)(param_1 + 0x17a) = 0x100010;
  *(undefined4 *)(param_1 + 0x180) = 0x80000000;
  *(undefined1 *)(param_1 + 0x184) = 0;
  if (sVar1 == 0) {
    *(undefined1 *)(param_1 + 0x18d) = 0;
    if (((*(byte *)(param_1 + 0x14e) & 0x20) == 0) ||
       (((*(uint *)(param_1 + 0x148) & 0xf000000) - 0x1000000 & 0xfeffffff) != 0))
    goto LAB_14002375f;
    uVar3 = 6;
    if ((*(uint *)(param_1 + 0x48) & 0x3c000000) == 0x14000000) {
      uVar3 = 3;
    }
  }
  else {
    if ((sVar1 - 0x300U & 0xfbff) == 0) {
      *(undefined1 *)(param_1 + 0x18d) = 0;
      goto LAB_14002375f;
    }
    uVar3 = 6;
    if (sVar1 == 0x900) {
      uVar3 = 3;
      if ((*(uint *)(param_1 + 0x48) & 0x3c000000) != 0x14000000) {
        uVar3 = 6;
      }
      *(undefined1 *)(param_1 + 0x18d) = uVar3;
      goto LAB_14002375f;
    }
  }
  *(undefined1 *)(param_1 + 0x18d) = uVar3;
LAB_14002375f:
  *(undefined1 *)(param_1 + 0x188) = 1;
  return 0;
}



===== ev_mm_initialize_packets @ 140023770 =====

undefined8 ev_mm_initialize_packets(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  
  lVar1 = mm_get_um_blk();
  iVar5 = 0;
  if (*(short *)(param_1 + 0x17c) != 0) {
    uVar4 = *(uint *)(param_1 + 0x4d4);
    do {
      uVar3 = *(uint *)(param_1 + 0x4d0);
      if (uVar3 == uVar4) {
        lVar6 = 0;
      }
      else {
        if (uVar3 == 0) {
          uVar3 = *(uint *)(param_1 + 0x4d8);
        }
        *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + -1;
        *(uint *)(param_1 + 0x4d0) = uVar3 - 1;
        lVar6 = *(longlong *)(param_1 + 0x4e0 + (ulonglong)(uVar3 - 1) * 8);
      }
      uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(lVar6 + 0x38),(uint *)(lVar6 + 0x40),0x600);
      if ((int)uVar2 != 0) {
        return 1;
      }
      uVar4 = *(uint *)(param_1 + 0x4d4);
      uVar3 = uVar4;
      if (uVar4 == 0) {
        uVar3 = *(uint *)(param_1 + 0x4d8);
      }
      uVar3 = uVar3 - 1;
      if (uVar3 != *(uint *)(param_1 + 0x4d0)) {
        *(longlong *)(param_1 + 0x4e0 + (ulonglong)uVar3 * 8) = lVar6;
        *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
        *(uint *)(param_1 + 0x4d4) = uVar3;
        uVar4 = uVar3;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(ushort *)(param_1 + 0x17c));
  }
  iVar5 = 0;
  if (*(short *)(param_1 + 0x17a) != 0) {
    uVar4 = *(uint *)(param_1 + 0x2dc);
    do {
      uVar3 = *(uint *)(param_1 + 0x2d8);
      if (uVar3 == uVar4) {
        lVar6 = 0;
      }
      else {
        if (uVar3 == 0) {
          uVar3 = *(uint *)(param_1 + 0x2e0);
        }
        *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + -1;
        *(uint *)(param_1 + 0x2d8) = uVar3 - 1;
        lVar6 = *(longlong *)(param_1 + 0x2e8 + (ulonglong)(uVar3 - 1) * 8);
      }
      uVar2 = mm_get_dma_buffer(lVar1,(longlong *)(lVar6 + 0x38),(uint *)(lVar6 + 0x40),0x600);
      if ((int)uVar2 != 0) {
        return 1;
      }
      uVar4 = *(uint *)(param_1 + 0x2dc);
      uVar3 = uVar4;
      if (uVar4 == 0) {
        uVar3 = *(uint *)(param_1 + 0x2e0);
      }
      uVar3 = uVar3 - 1;
      if (uVar3 != *(uint *)(param_1 + 0x2d8)) {
        *(longlong *)(param_1 + 0x2e8 + (ulonglong)uVar3 * 8) = lVar6;
        *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + 1;
        *(uint *)(param_1 + 0x2dc) = uVar3;
        uVar4 = uVar3;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(ushort *)(param_1 + 0x17a));
  }
  return 0;
}



===== lm_reg_write_block @ 14002390c =====

void lm_reg_write_block(undefined8 param_1,int param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  
  if (param_4 != 0) {
    uVar1 = (ulonglong)param_4;
    do {
      lm_reg_wr_ind(param_1,param_2,*param_3);
      param_2 = param_2 + 4;
      param_3 = param_3 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}



===== mm_alloc_dma_buffer @ 140023960 =====

void mm_alloc_dma_buffer(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x88),(uint *)(param_1 + 0x90),0x104);
  return;
}



===== mm_alloc_rcq_ring @ 140023990 =====

void mm_alloc_rcq_ring(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x688),(uint *)(param_1 + 0x690),0x100);
  return;
}



===== mm_alloc_rx_ring @ 1400239c0 =====

void mm_alloc_rx_ring(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x4a0),(uint *)(param_1 + 0x4a8),0x100);
  return;
}



===== mm_alloc_sp_ring @ 1400239f0 =====

void mm_alloc_sp_ring(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x6e0),(uint *)(param_1 + 0x6f0),0x10);
  return;
}



===== mm_alloc_statusblock @ 140023a20 =====

void mm_alloc_statusblock(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x18),(uint *)(param_1 + 0x28),0x50);
  return;
}



===== mm_alloc_tx_ring @ 140023a4c =====

void mm_alloc_tx_ring(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = mm_get_um_blk();
  mm_get_dma_buffer(lVar1,(longlong *)(param_1 + 0x2a8),(uint *)(param_1 + 0x2b0),0x100);
  return;
}



===== mm_check_for_rx_hang_up @ 140023a80 =====

void mm_check_for_rx_hang_up(longlong param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  longlong lVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  longlong lVar9;
  longlong lVar10;
  
  uVar7 = -(uint)(*(char *)(param_1 + 0x138) != '\0') & 0x800;
  storport_pci_cfg_write_dword(param_1,0x78,uVar7 + 0x162250);
  storport_pci_cfg_read_dword(param_1,0x80);
  iVar6 = 0;
  do {
    storport_pci_cfg_write_dword(param_1,0x78,uVar7 + 0x162250);
    iVar3 = storport_pci_cfg_read_dword(param_1,0x80);
    if (iVar3 != 0) break;
    mm_stall(1000);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3000);
  if (iVar6 == 3000) {
    lVar4 = mm_get_free_pkt_desc(param_1);
    if (lVar4 != 0) {
      puVar2 = *(undefined1 **)(lVar4 + 0x38);
      puVar8 = puVar2 + 6;
      puVar5 = puVar2;
      lVar10 = 6;
      do {
        lVar9 = lVar10;
        uVar1 = puVar5[(param_1 - (longlong)puVar2) + 0x110];
        *puVar8 = uVar1;
        puVar8 = puVar8 + 1;
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
        lVar10 = lVar9 + -1;
      } while (lVar10 != 0);
      *(undefined2 *)(puVar2 + 0xc) = 0xadde;
      *(short *)(lVar4 + 0x24) = (short)lVar9 + 0x3f;
      iVar6 = (-(uint)(*(char *)(param_1 + 0x138) != '\0') & 0x800) + 0x163000;
      storport_pci_cfg_write_dword(param_1,0x78,iVar6);
      uVar7 = storport_pci_cfg_read_dword(param_1,0x80);
      lm_reg_wr_ind(param_1,iVar6,uVar7 | 8);
      mm_queue_tx_packet(param_1,lVar4);
      lm_reg_wr_ind(param_1,iVar6,uVar7);
    }
  }
  mm_stall(1000);
  do {
    lm_flush_rx_buffers(param_1);
    lm_reg_wr_ind(param_1,*(int *)(param_1 + 0x4c) + 0x69c,*(uint *)(param_1 + 0x6c8) | 0xfe000000);
  } while( true );
}



===== mm_device_poll @ 140023be0 =====

undefined8 mm_device_poll(longlong param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar6;
  uint uVar5;
  longlong lVar7;
  undefined8 uVar8;
  
  uVar8 = 0;
  ev_lm_service_intr(param_1);
  iVar2 = *(int *)(param_1 + 0x3f8);
  if (iVar2 != *(int *)(param_1 + 0x3fc)) {
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x400);
    }
    *(uint *)(param_1 + 0x3f8) = iVar2 - 1U;
    *(int *)(param_1 + 0x404) = *(int *)(param_1 + 0x404) + -1;
    iVar6 = *(int *)(param_1 + 0x2dc);
    if (iVar6 == 0) {
      iVar6 = *(int *)(param_1 + 0x2e0);
    }
    uVar5 = iVar6 - 1;
    if (uVar5 != *(uint *)(param_1 + 0x2d8)) {
      *(undefined8 *)(param_1 + 0x2e8 + (ulonglong)uVar5 * 8) =
           *(undefined8 *)(param_1 + 0x408 + (ulonglong)(iVar2 - 1U) * 8);
      *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + 1;
      *(uint *)(param_1 + 0x2dc) = uVar5;
    }
    uVar8 = 1;
  }
  if ((param_2 != 0) && (iVar2 = *(int *)(param_1 + 0x5f0), iVar2 != *(int *)(param_1 + 0x5f4))) {
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x5f8);
    }
    *(uint *)(param_1 + 0x5f0) = iVar2 - 1U;
    *(int *)(param_1 + 0x5fc) = *(int *)(param_1 + 0x5fc) + -1;
    lVar1 = *(longlong *)(param_1 + 0x600 + (ulonglong)(iVar2 - 1U) * 8);
    lVar7 = *(longlong *)(lVar1 + 0x38);
    if ((*(int *)(param_1 + 0x34) != 0) || ((*(uint *)(param_1 + 0x58) & 0x200) != 0)) {
      lVar3 = lm_strip_vntag_vlan_hdr(param_1,lVar1);
      lVar7 = lVar7 + (int)lVar3;
      *(short *)(lVar1 + 0x24) = *(short *)(lVar1 + 0x24) - (short)lVar3;
    }
    uVar4 = mm_get_net_if();
    stack_rx_packet(uVar4,lVar7,*(undefined2 *)(lVar1 + 0x24));
    iVar2 = *(int *)(param_1 + 0x4d4);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x4d8);
    }
    uVar5 = iVar2 - 1;
    if (uVar5 != *(uint *)(param_1 + 0x4d0)) {
      *(longlong *)(param_1 + 0x4e0 + (ulonglong)uVar5 * 8) = lVar1;
      *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
      *(uint *)(param_1 + 0x4d4) = uVar5;
    }
    ev_lm_post_buffers(param_1);
  }
  return uVar8;
}



===== mm_flush_rx_buffers_ctrl_on_pf @ 140023d40 =====

void mm_flush_rx_buffers_ctrl_on_pf(longlong param_1,int param_2)

{
  uint uVar1;
  
  if (1 < *(byte *)(param_1 + 0x13d)) {
    storport_pci_cfg_write_dword(param_1,0x78,0x431520);
    uVar1 = storport_pci_cfg_read_dword(param_1,0x80);
    if ((uVar1 & 2) == 0) {
      lm_reg_wr_ind(param_1,0x43150c,(uint)(param_2 != 0));
    }
  }
  return;
}



===== mm_get_dma_buffer_length @ 140023da0 =====

undefined8 mm_get_dma_buffer_length(void)

{
  return 0xdb53;
}



===== mm_get_free_pkt_desc @ 140023da8 =====

longlong mm_get_free_pkt_desc(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x2d8);
  if (iVar3 != *(int *)(param_1 + 0x2dc)) {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x2e0);
    }
    *(int *)(param_1 + 0x2e4) = *(int *)(param_1 + 0x2e4) + -1;
    *(uint *)(param_1 + 0x2d8) = iVar3 - 1U;
    lVar1 = *(longlong *)(param_1 + 0x2e8 + (ulonglong)(iVar3 - 1U) * 8);
    if (lVar1 != 0) {
      return lVar1;
    }
  }
  iVar3 = 0;
  do {
    ev_lm_service_intr(param_1);
    iVar2 = *(int *)(param_1 + 0x3f8);
    if (iVar2 != *(int *)(param_1 + 0x3fc)) {
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0x400);
      }
      *(int *)(param_1 + 0x404) = *(int *)(param_1 + 0x404) + -1;
      *(uint *)(param_1 + 0x3f8) = iVar2 - 1U;
      lVar1 = *(longlong *)(param_1 + 0x408 + (ulonglong)(iVar2 - 1U) * 8);
      if (lVar1 != 0) {
        return lVar1;
      }
    }
    iVar3 = iVar3 + 1;
    if (9999 < iVar3) {
      return 0;
    }
  } while( true );
}



===== mm_get_link_status @ 140023e40 =====

undefined4 mm_get_link_status(longlong param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



===== mm_get_mac_addr @ 140023e50 =====

undefined8 mm_get_mac_addr(undefined1 *param_1,undefined4 *param_2,int param_3)

{
  undefined2 uVar1;
  
  ev_lm_get_dev_info(param_1);
  if (param_3 == 0) {
    *param_2 = *(undefined4 *)(param_1 + 0x110);
    uVar1 = *(undefined2 *)(param_1 + 0x114);
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x116);
    uVar1 = *(undefined2 *)(param_1 + 0x11a);
  }
  *(undefined2 *)(param_2 + 1) = uVar1;
  return 0;
}



===== mm_get_rx_packet @ 140023eb0 =====

undefined2 mm_get_rx_packet(longlong param_1,void *param_2)

{
  longlong lVar1;
  undefined2 uVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  void *_Src;
  
  mm_device_poll(param_1,0);
  iVar3 = *(int *)(param_1 + 0x5f0);
  if (iVar3 == *(int *)(param_1 + 0x5f4)) {
    uVar2 = 0;
  }
  else {
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x5f8);
    }
    *(uint *)(param_1 + 0x5f0) = iVar3 - 1U;
    *(int *)(param_1 + 0x5fc) = *(int *)(param_1 + 0x5fc) + -1;
    lVar1 = *(longlong *)(param_1 + 0x600 + (ulonglong)(iVar3 - 1U) * 8);
    _Src = *(void **)(lVar1 + 0x38);
    if ((*(int *)(param_1 + 0x34) != 0) || ((*(uint *)(param_1 + 0x58) & 0x200) != 0)) {
      lVar4 = lm_strip_vntag_vlan_hdr(param_1,lVar1);
      _Src = (void *)((longlong)_Src + (longlong)(int)lVar4);
      *(short *)(lVar1 + 0x24) = *(short *)(lVar1 + 0x24) - (short)lVar4;
    }
    memmove(param_2,_Src,(ulonglong)*(ushort *)(lVar1 + 0x24));
    iVar3 = *(int *)(param_1 + 0x4d4);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x4d8);
    }
    uVar5 = iVar3 - 1;
    if (uVar5 != *(uint *)(param_1 + 0x4d0)) {
      *(longlong *)(param_1 + 0x4e0 + (ulonglong)uVar5 * 8) = lVar1;
      *(int *)(param_1 + 0x4dc) = *(int *)(param_1 + 0x4dc) + 1;
      *(uint *)(param_1 + 0x4d4) = uVar5;
    }
    ev_lm_post_buffers(param_1);
    uVar2 = *(undefined2 *)(lVar1 + 0x24);
  }
  return uVar2;
}



===== mm_get_timer_in_ms @ 140023fa0 =====

ulonglong mm_get_timer_in_ms(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = lm_is_e3(param_1);
  if (*(int *)(param_1 + 0x10c) == 0) {
    uVar1 = storport_mem_read_dword(param_1,0xa5dc);
  }
  else {
    storport_pci_cfg_write_dword(param_1,0x78,0xa5dc);
    uVar1 = storport_pci_cfg_read_dword(param_1,0x80);
  }
  return (ulonglong)~uVar1 / (ulonglong)((-(uint)((int)uVar2 != 0) & 0x32) + 100);
}



===== mm_init_context @ 140023ffc =====

void mm_init_context(longlong param_1)

{
  longlong *plVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  lVar5 = mm_get_um_blk();
  puVar2 = (uint *)(param_1 + 0x80);
  plVar1 = (longlong *)(param_1 + 0x78);
  uVar6 = mm_get_dma_buffer(lVar5,plVar1,puVar2,0x12ff);
  if ((int)uVar6 == 0) {
    uVar4 = *puVar2;
    uVar3 = uVar4 + (-uVar4 & 0xfff);
    *puVar2 = uVar3;
    if (uVar3 < uVar4) {
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    }
    *plVar1 = *plVar1 + (ulonglong)(-uVar4 & 0xfff);
    memset((void *)*plVar1,0,0x300);
  }
  return;
}



===== mm_pcicfg_map @ 140024078 =====

void mm_pcicfg_map(longlong param_1,int param_2)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lVar5;
  
  cVar1 = *(char *)(param_1 + 0x138);
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 == 0) {
    *(uint *)(&pxp2_pci_registers_map + (ulonglong)*(byte *)(param_1 + 0x138) * 0x10) =
         (uint)*(byte *)(param_1 + 0x138) * 0x2000 + 0x441000;
  }
  else {
    *(uint *)(&pxp2_pci_registers_map + (ulonglong)*(byte *)(param_1 + 0x138) * 0x10) =
         (uint)*(ushort *)(param_1 + 0xb0) * 8 + 0x442000;
  }
  lVar5 = 0;
  iVar3 = 0;
  do {
    if (param_2 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)
               (&pxp2_pci_registers_map + (lVar5 + (ulonglong)*(byte *)(param_1 + 0x138) * 4) * 4);
    }
    lm_reg_wr_ind(param_1,(-(uint)(cVar1 != '\0') & 0x10) + 0x120534 + iVar3,uVar4);
    iVar3 = iVar3 + 4;
    lVar5 = lVar5 + 1;
  } while (lVar5 < 4);
  return;
}



===== mm_queue_tx_packet @ 14002413c =====

void mm_queue_tx_packet(longlong param_1,longlong param_2)

{
  *(byte *)(param_2 + 0x48) = 1;
  *(undefined2 *)(param_2 + 0x2a) = 0;
  *(undefined8 *)(param_2 + 0x50) = *(undefined8 *)(param_2 + 0x40);
  *(undefined2 *)(param_2 + 0x4a) = *(undefined2 *)(param_2 + 0x24);
  *(undefined2 *)(param_2 + 0x58) = *(undefined2 *)(param_2 + 0x24);
  if (*(int *)(param_1 + 0x34) != 0) {
    *(ushort *)(param_2 + 0x2a) = *(ushort *)(param_2 + 0x2a) | 1;
    *(undefined2 *)(param_2 + 0x2c) = *(undefined2 *)(param_1 + 0x34);
  }
  ev_lm_send_packet(param_1,param_2,(byte *)(param_2 + 0x48));
  return;
}



===== mm_set_boot_signature @ 140024180 =====

void mm_set_boot_signature(longlong param_1,undefined4 param_2)

{
  undefined8 uVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + 0x13c);
  uVar1 = lm_is_dual_core(param_1);
  if ((int)uVar1 != 0) {
    bVar2 = 1 < bVar2;
  }
  lm_reg_wr_ind(param_1,(uint)bVar2 * 0x2c + *(int *)(param_1 + 0x4c) + 0x69c,param_2);
  return;
}



===== mm_set_ibft_address @ 1400241e0 =====

void mm_set_ibft_address(longlong param_1,undefined4 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = lm_is_dual_core(param_1);
  if ((int)uVar2 != 0) {
    storport_pci_cfg_write_dword(param_1,0x78,*(undefined4 *)(param_1 + 0x50));
    uVar1 = storport_pci_cfg_read_dword(param_1,0x80);
    if (0x10c < uVar1) {
      lm_reg_wr_ind(param_1,*(int *)(param_1 + 0x50) + 0x10c,param_2);
    }
  }
  return;
}



===== mm_set_mac_addr @ 140024240 =====

void mm_set_mac_addr(longlong param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x172) = *param_2;
  *(undefined2 *)(param_1 + 0x176) = *(undefined2 *)(param_2 + 1);
  ev_lm_set_rx_mask(param_1,*(uint *)(param_1 + 0x6c4));
  return;
}



===== mm_transmit_packet @ 140024260 =====

undefined4 mm_transmit_packet(longlong param_1,longlong *param_2)

{
  ushort *puVar1;
  byte bVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  longlong lVar6;
  int iVar7;
  
  lVar4 = mm_get_free_pkt_desc(param_1);
  if (lVar4 == 0) {
    uVar3 = 1;
  }
  else {
    lm_insert_vntag_vlan_hdr(param_1,lVar4);
    bVar2 = *(byte *)(lVar4 + 0x28);
    lVar6 = *(longlong *)(lVar4 + 0x38);
    *(short *)(lVar4 + 0x24) = (short)param_2[2];
    if (bVar2 != 0) {
      lVar6 = lVar6 + (ulonglong)bVar2;
    }
    iVar7 = 0;
    do {
      memmove((void *)(iVar7 + lVar6),(void *)param_2[1],
              (ulonglong)*(ushort *)((longlong)param_2 + 0x12));
      puVar1 = (ushort *)((longlong)param_2 + 0x12);
      param_2 = (longlong *)*param_2;
      iVar7 = iVar7 + (uint)*puVar1;
    } while (param_2 != (longlong *)0x0);
    if (bVar2 != 0) {
      puVar5 = *(undefined1 **)(lVar4 + 0x38);
      lVar6 = 0xc;
      do {
        *puVar5 = puVar5[bVar2];
        puVar5 = puVar5 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      lm_insert_vntag_vlan_hdr(param_1,lVar4);
      *(short *)(lVar4 + 0x24) = *(short *)(lVar4 + 0x24) + (ushort)bVar2;
    }
    mm_queue_tx_packet(param_1,lVar4);
    uVar3 = 0;
  }
  return uVar3;
}



===== mm_transmit_packet_raw @ 140024330 =====

undefined4 mm_transmit_packet_raw(longlong param_1,void *param_2,ushort param_3)

{
  byte bVar1;
  undefined4 uVar2;
  longlong lVar3;
  void *_Dst;
  undefined1 *puVar4;
  longlong lVar5;
  
  lVar3 = mm_get_free_pkt_desc(param_1);
  if (lVar3 == 0) {
    uVar2 = 1;
  }
  else {
    lm_insert_vntag_vlan_hdr(param_1,lVar3);
    bVar1 = *(byte *)(lVar3 + 0x28);
    _Dst = *(void **)(lVar3 + 0x38);
    *(ushort *)(lVar3 + 0x24) = param_3;
    if (*(int *)(param_1 + 0x34) != 0) {
      _Dst = (void *)((longlong)_Dst + (ulonglong)bVar1);
    }
    memmove(_Dst,param_2,(ulonglong)param_3);
    if (bVar1 != 0) {
      puVar4 = *(undefined1 **)(lVar3 + 0x38);
      lVar5 = 0xc;
      do {
        *puVar4 = puVar4[bVar1];
        puVar4 = puVar4 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      lm_insert_vntag_vlan_hdr(param_1,lVar3);
      *(short *)(lVar3 + 0x24) = *(short *)(lVar3 + 0x24) + (ushort)bVar1;
    }
    mm_queue_tx_packet(param_1,lVar3);
    uVar2 = 0;
  }
  return uVar2;
}



===== nx3_get_intf @ 1400243e4 =====

undefined8 nx3_get_intf(undefined8 *param_1)

{
  *param_1 = &DAT_14007ea00;
  param_1[1] = mm_get_dma_buffer;
  param_1[2] = iscsiBootCancel;
  param_1[3] = mm_get_rx_packet;
  param_1[4] = mm_transmit_packet_raw;
  param_1[5] = mm_transmit_packet;
  param_1[6] = mm_get_dma_buffer_length;
  param_1[7] = ev_dir_get_iscsi_block;
  param_1[8] = mm_get_mac_addr;
  param_1[9] = mm_set_mac_addr;
  param_1[10] = mm_device_poll;
  param_1[0xb] = mm_get_link_status;
  param_1[0xf] = mm_set_boot_signature;
  param_1[0x10] = iscsiBootCancel;
  param_1[0x11] = mm_interrupt_control;
  param_1[0x12] = mm_get_timer_in_ms;
  param_1[0x13] = mm_flush_rx_buffers_ctrl_on_pf;
  param_1[0x14] = mm_check_for_rx_hang_up;
  param_1[0x15] = mm_set_ibft_address;
  nx3_get_netif_intf((longlong)param_1);
  return 0;
}



===== ev_ethernetif_bringup @ 1400244e0 =====

ulonglong ev_ethernetif_bringup(longlong param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x28);
  iVar5 = 0;
  uVar4 = 9;
  if (0 < *(int *)(param_1 + 0xe8)) {
    uVar4 = 0xb;
    puVar7 = (undefined4 *)(param_1 + 0xec);
    puVar6 = (undefined4 *)(lVar2 + 0x1a6);
    do {
      iVar5 = iVar5 + 1;
      *puVar6 = *puVar7;
      puVar1 = puVar7 + 1;
      puVar7 = (undefined4 *)((longlong)puVar7 + 6);
      *(undefined2 *)(puVar6 + 1) = *(undefined2 *)puVar1;
      puVar6 = puVar6 + 2;
    } while (iVar5 < *(int *)(param_1 + 0xe8));
    *(undefined1 *)(lVar2 + 0x1a4) = *(undefined1 *)(param_1 + 0xe8);
  }
  ev_lm_set_rx_mask(lVar2,uVar4);
  uVar3 = ev_lm_enable_intr(lVar2);
  return uVar3 & 0xffffffffffffff00;
}



===== ev_ethernetif_init @ 140024560 =====

undefined8 ev_ethernetif_init(longlong param_1)

{
  byte *_Dst;
  undefined8 uVar1;
  
  _Dst = *(byte **)(param_1 + 0x28);
  memset(_Dst + 0x2a8,0,0x430);
  memset(_Dst,0,0xf8);
  uVar1 = ev_lm_get_dev_info(_Dst);
  if (((int)uVar1 == 0) && (uVar1 = ev_lm_init_resc((longlong)_Dst), (int)uVar1 == 0)) {
    lm_reset_all_devices((longlong)_Dst);
    uVar1 = lm_chip_init(_Dst);
    if ((int)uVar1 == 0) {
      ev_lm_init_phy((longlong)_Dst,(byte)*(undefined4 *)(_Dst + 0x18c));
      *(undefined2 *)(param_1 + 0x3b) = 0x7665;
      *(code **)(param_1 + 0x18) = bnx1_protocol_transmit;
      *(code **)(param_1 + 0x20) = bnx1_transmit;
      return 0x140011300;
    }
  }
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),0xf5);
}



===== ev_ethernetif_shutdown @ 140024610 =====

ulonglong ev_ethernetif_shutdown(longlong param_1)

{
  byte *pbVar1;
  ulonglong uVar2;
  
  pbVar1 = *(byte **)(param_1 + 0x28);
  ev_lm_disable_intr((longlong)pbVar1);
  uVar2 = lm_shutdown(pbVar1);
  return uVar2 & 0xffffffffffffff00;
}



===== nx3_get_netif_intf @ 140024638 =====

void nx3_get_netif_intf(longlong param_1)

{
  *(code **)(param_1 + 0x60) = ev_ethernetif_init;
  *(code **)(param_1 + 0x70) = ev_ethernetif_shutdown;
  *(code **)(param_1 + 0x68) = ev_ethernetif_bringup;
  return;
}



===== dir_get_dir_entry @ 14002465c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8 dir_get_dir_entry(undefined8 param_1,uint param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_448 [32];
  undefined8 local_428;
  undefined4 auStack_420 [58];
  uint local_338 [4];
  undefined4 auStack_328 [192];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_448;
  if ((param_2 & 3) == 0) {
    ev_lm_nvram_read_block(param_1,0x14,(longlong)&local_428,0xec);
    iVar5 = 0;
    puVar3 = (uint *)((longlong)&local_428 + 4);
    do {
      if (((*puVar3 & 0x7ffffc) != 0) && ((*puVar3 & 0xf0800003) == param_2)) {
        uVar2 = *(undefined8 *)(auStack_448 + (longlong)iVar5 * 0xc + 0x20);
        uVar1 = auStack_420[(longlong)iVar5 * 3];
        goto LAB_140024721;
      }
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 3;
    } while (iVar5 < 0x10);
  }
  else {
    uVar2 = dir_get_dir_entry(param_1,0xe0000000,param_3);
    uVar4 = 0;
    if (((int)uVar2 == 0) &&
       (ev_lm_nvram_read_block(param_1,*(int *)(param_3 + 1),(longlong)local_338,0x308),
       local_338[0] != 0)) {
      puVar3 = local_338;
      do {
        puVar3 = puVar3 + 3;
        if ((*puVar3 & 0xf0800003) == param_2) {
          uVar2 = *(undefined8 *)(local_338 + (longlong)(int)uVar4 * 3 + 2);
          uVar1 = auStack_328[(longlong)(int)uVar4 * 3];
LAB_140024721:
          *param_3 = uVar2;
          *(undefined4 *)(param_3 + 1) = uVar1;
          return 0;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < local_338[0]);
    }
  }
  return 1;
}



===== ev_dir_get_iscsi_block @ 140024780 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ev_dir_get_iscsi_block(undefined1 *param_1,longlong param_2,uint param_3)

{
  undefined8 uVar1;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  int local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  ev_lm_get_dev_info(param_1);
  uVar1 = dir_get_dir_entry(param_1,*(uint *)(&iscsi_block_dir + (ulonglong)(byte)param_1[0x13c] * 4
                                             ),&local_38);
  if ((int)uVar1 != 1) {
    ev_lm_nvram_read_block(param_1,local_30,param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}



===== ev_lm_nvram_read_block @ 1400247f4 =====

undefined8 ev_lm_nvram_read_block(undefined8 param_1,int param_2,longlong param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (param_4 != 0) {
    do {
      uVar1 = ev_lm_nvram_read_dword(param_1,uVar2 + param_2);
      uVar3 = uVar2 + 4;
      *(undefined4 *)(param_3 + (ulonglong)(uVar2 >> 2) * 4) = uVar1;
      uVar2 = uVar3;
    } while (uVar3 < param_4);
  }
  return 0;
}



===== ev_lm_nvram_read_dword @ 14002485c =====

undefined4 ev_lm_nvram_read_dword(undefined8 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  lm_reg_wr_ind(param_1,0x86420,2);
  uVar6 = 0;
  uVar4 = 0;
  do {
    uVar1 = lm_reg_read_ind(param_1,0x86420);
    if ((uVar1 >> 9 & 1) != 0) break;
    mm_stall(500);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 10000);
  lm_reg_wr_ind(param_1,0x86424,3);
  lm_reg_wr_ind(param_1,0x8640c,param_2);
  lm_reg_wr_ind(param_1,0x86400,0x198);
  iVar5 = 0;
  do {
    uVar3 = lm_reg_read_ind(param_1,0x86400);
    if ((uVar3 & 8) != 0) break;
    mm_stall(5);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 10000);
  uVar2 = lm_reg_read_ind(param_1,0x86410);
  lm_reg_wr_ind(param_1,0x86424,0);
  lm_reg_wr_ind(param_1,0x86420,0x20);
  do {
    uVar4 = lm_reg_read_ind(param_1,0x86420);
    if ((uVar4 >> 9 & 1) == 0) {
      return uVar2;
    }
    mm_stall(5);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 1000);
  return uVar2;
}



===== crashdump_icmp4_input @ 14002497c =====

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



===== crashdump_ip4_input @ 140024aa0 =====

longlong crashdump_ip4_input(longlong *param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  ushort *puVar3;
  char cVar4;
  ulonglong uVar5;
  uint7 extraout_var;
  uint7 uVar6;
  uint7 extraout_var_00;
  uint7 extraout_var_01;
  ushort uVar7;
  longlong *plVar8;
  
  puVar3 = (ushort *)param_1[1];
  if (((*puVar3 & 0xf0) == 0x40) &&
     (uVar7 = (*puVar3 & 0xf) * 4, uVar7 <= *(ushort *)((longlong)param_1 + 0x12))) {
    uVar7 = lwip_standard_chksum((byte *)puVar3,uVar7);
    if (uVar7 == 0xffff) {
      pbuf_realloc(param_1,puVar3[1] << 8 | puVar3[1] >> 8);
      if (netif_list != (longlong *)0x0) {
        puVar1 = (uint *)(puVar3 + 8);
        plVar8 = netif_list;
        do {
          if ((((*(byte *)((longlong)plVar8 + 0x3a) & 1) != 0) &&
              ((uint *)(plVar8 + 0x24) != (uint *)0x0)) &&
             (uVar2 = *(uint *)(plVar8 + 0x24), uVar2 != 0)) {
            if (*puVar1 == uVar2) break;
            uVar5 = ip_addr_isbroadcast(puVar1,(longlong)plVar8);
            if ((char)uVar5 != '\0') break;
          }
          plVar8 = (longlong *)*plVar8;
        } while (plVar8 != (longlong *)0x0);
        if ((plVar8 != (longlong *)0x0) && ((puVar3[3] & 0xff3f) == 0)) {
          cVar4 = (char)(puVar3[4] >> 8);
          if (cVar4 == '\x01') {
            crashdump_icmp4_input(param_1,param_2);
            uVar6 = extraout_var_01;
            goto LAB_140024bc0;
          }
          if (cVar4 == '\x06') {
            crashdump_tcp4_input(param_1);
            uVar6 = extraout_var_00;
            goto LAB_140024bc0;
          }
          uVar5 = ip_addr_isbroadcast(puVar1,param_2);
          if (((char)uVar5 == '\0') && (((byte)*puVar1 & 0xf0) != 0xe0)) {
            param_1[1] = (longlong)puVar3;
            icmp_dest_unreach((longlong)param_1,2);
          }
        }
      }
    }
  }
  pbuf_free(param_1);
  uVar6 = extraout_var;
LAB_140024bc0:
  return (ulonglong)uVar6 << 8;
}



===== crashdump_ip4_output @ 140024bf0 =====

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



===== crashdump_tcp4_close @ 140024c5c =====

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
LAB_140024d47:
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
        goto LAB_140024d47;
      }
      tcp_pcb_remove(&tcp_active_pcbs,param_1);
      iVar4 = 3;
    }
    cVar2 = '\0';
    memp_free(iVar4,(longlong)param_1);
  }
  return cVar2;
}



===== crashdump_tcp4_input @ 140024d6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crashdump_tcp4_input(longlong *param_1)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  ushort *puVar5;
  longlong lVar6;
  int *piVar7;
  char cVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  uint *puVar12;
  ushort uVar13;
  uint uVar14;
  int *piVar15;
  int *piVar16;
  uint uVar17;
  uint local_res8 [2];
  
  DAT_14007f158 = param_1[1];
  DAT_14007f150 = (ushort *)(DAT_14007f158 + 0x14);
  uVar10 = pbuf_header((longlong)param_1,-0x14);
  if ((((char)uVar10 == '\0') && (0x13 < *(ushort *)(param_1 + 2))) &&
     (uVar9 = inet_chksum_pseudo(param_1,(uint *)(DAT_14007f158 + 0xc),
                                 (uint *)(DAT_14007f158 + 0x10),6,*(ushort *)(param_1 + 2)),
     (short)uVar9 == 0)) {
    pbuf_header((longlong)param_1,((DAT_14007f150[6] & 0xff) >> 4) * -4);
    lVar6 = DAT_14007f158;
    puVar5 = DAT_14007f150;
    uVar14 = *(uint *)(DAT_14007f150 + 2);
    uVar2 = *(uint *)(DAT_14007f150 + 4);
    bVar1 = *(byte *)((longlong)DAT_14007f150 + 0xd);
    DAT_14007f123 = bVar1 & 0x3f;
    *DAT_14007f150 = *DAT_14007f150 << 8 | *DAT_14007f150 >> 8;
    puVar5[1] = puVar5[1] << 8 | puVar5[1] >> 8;
    puVar5[7] = puVar5[7] << 8 | puVar5[7] >> 8;
    uVar17 = uVar14 >> 0x18 | (uVar14 & 0xff0000) >> 8 | (uVar14 & 0xff00) << 8 | uVar14 << 0x18;
    uVar14 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    *(uint *)(puVar5 + 2) = uVar17;
    *(uint *)(puVar5 + 4) = uVar14;
    uVar13 = (ushort)((bVar1 & 3) != 0) + (short)param_1[2];
    puVar3 = (uint *)0x0;
    for (puVar4 = tcp_active_pcbs; puVar12 = tcp_tw_pcbs, DAT_14007f124 = uVar17,
        DAT_14007f160 = uVar14, DAT_14007f164 = uVar13, puVar4 != (uint *)0x0;
        puVar4 = *(uint **)(puVar4 + 4)) {
      uVar2 = puVar4[6];
      if (uVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("tcp_input: active pcb->state != CLOSED");
      }
      if (uVar2 == 10) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("tcp_input: active pcb->state != TIME-WAIT");
      }
      if (uVar2 == 1) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("tcp_input: active pcb->state != LISTEN");
      }
      if (((*(ushort *)((longlong)puVar4 + 0x2a) == *puVar5) && ((ushort)puVar4[10] == puVar5[1]))
         && (*puVar4 == *(uint *)(lVar6 + 0x10))) {
        puVar12 = *(uint **)(puVar4 + 4);
        if (puVar12 == puVar4) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_input: pcb->next != pcb (before cache)");
        }
        if (puVar3 != (uint *)0x0) {
          *(uint **)(puVar3 + 4) = puVar12;
          *(uint **)(puVar4 + 4) = tcp_active_pcbs;
          puVar12 = *(uint **)(puVar4 + 4);
          tcp_active_pcbs = puVar4;
        }
        if (puVar12 == puVar4) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_input: pcb->next != pcb (after cache)");
        }
        _DAT_14007f128 = 0;
        DAT_14007f140 = (undefined2)param_1[2];
        _DAT_14007f138 = param_1[1];
        DAT_14007f148 = puVar5;
        DAT_14007f168 = (undefined8 *)0x0;
        DAT_14007f166 = 0;
        DAT_14007f130 = param_1;
        tcp_input_pcb = puVar4;
        uVar11 = tcp_process(puVar4);
        tcp_input_pcb = (uint *)0x0;
        if ((char)uVar11 != -3) {
          if ((DAT_14007f166 & 8) == 0) {
            if ((DAT_14007f166 & 0x10) == 0) {
              cVar8 = '\0';
              if (((short)puVar4[0x1e] != 0) && (*(code **)(puVar4 + 0x26) != (code *)0x0)) {
                cVar8 = (**(code **)(puVar4 + 0x26))(*(undefined8 *)(puVar4 + 8),puVar4);
              }
              if (DAT_14007f168 != (undefined8 *)0x0) {
                if (*(code **)(puVar4 + 0x28) == (code *)0x0) {
                  pbuf_free(DAT_14007f168);
                }
                else {
                  cVar8 = (**(code **)(puVar4 + 0x28))
                                    (*(undefined8 *)(puVar4 + 8),puVar4,DAT_14007f168,0);
                }
              }
              if (((DAT_14007f166 & 0x20) != 0) && (*(code **)(puVar4 + 0x28) != (code *)0x0)) {
                cVar8 = (**(code **)(puVar4 + 0x28))(*(undefined8 *)(puVar4 + 8),puVar4,0,0);
              }
              if (cVar8 == '\0') {
                crashdump_tcp4_output(puVar4);
              }
              goto LAB_140025348;
            }
          }
          else if (*(code **)(puVar4 + 0x30) != (code *)0x0) {
            (**(code **)(puVar4 + 0x30))(*(undefined8 *)(puVar4 + 8),0xfc);
          }
          tcp_pcb_remove((longlong *)&tcp_active_pcbs,puVar4);
          memp_free(3,(longlong)puVar4);
        }
LAB_140025348:
        if (DAT_14007f130 != (longlong *)0x0) {
          pbuf_free(DAT_14007f130);
          DAT_14007f130 = (longlong *)0x0;
        }
        goto LAB_14002539f;
      }
      puVar3 = puVar4;
    }
    for (; puVar12 != (uint *)0x0; puVar12 = *(uint **)(puVar12 + 4)) {
      if (puVar12[6] != 10) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("tcp_input: TIME-WAIT pcb->state == TIME-WAIT");
      }
      if ((((*(ushort *)((longlong)puVar12 + 0x2a) == *puVar5) && ((ushort)puVar12[10] == puVar5[1])
           ) && (puVar12[1] == *(uint *)(lVar6 + 0xc))) && (*puVar12 == *(uint *)(lVar6 + 0x10))) {
        if (0 < (int)(((uint)uVar13 - puVar12[0xc]) + uVar17)) {
          puVar12[0xc] = uVar13 + uVar17;
        }
        if (uVar13 != 0) {
          *(byte *)(puVar12 + 0xb) = (byte)puVar12[0xb] | 2;
          crashdump_tcp4_output(puVar12);
        }
        goto LAB_14002527a;
      }
    }
    piVar7 = tcp_listen_pcbs;
    piVar16 = (int *)0x0;
    while (piVar15 = piVar7, piVar15 != (int *)0x0) {
      if (((*piVar15 == 0) || (*piVar15 == *(int *)(lVar6 + 0x10))) &&
         (*(ushort *)(piVar15 + 10) == puVar5[1])) {
        if (piVar16 != (int *)0x0) {
          *(undefined8 *)(piVar16 + 4) = *(undefined8 *)(piVar15 + 4);
          *(int **)(piVar15 + 4) = tcp_listen_pcbs;
          tcp_listen_pcbs = piVar15;
        }
        if ((bVar1 & 0x10) == 0) {
          if (((bVar1 & 2) != 0) &&
             (puVar12 = (uint *)tcp_alloc(*(byte *)(piVar15 + 7)), lVar6 = DAT_14007f158,
             puVar12 != (uint *)0x0)) {
            if ((uint *)(DAT_14007f158 + 0x10) == (uint *)0x0) {
              uVar14 = 0;
            }
            else {
              uVar14 = *(uint *)(DAT_14007f158 + 0x10);
            }
            *puVar12 = uVar14;
            *(short *)(puVar12 + 10) = (short)piVar15[10];
            puVar5 = DAT_14007f150;
            uVar2 = DAT_14007f124;
            uVar14 = 0;
            if ((uint *)(lVar6 + 0xc) != (uint *)0x0) {
              uVar14 = *(uint *)(lVar6 + 0xc);
            }
            puVar12[1] = uVar14;
            *(ushort *)((longlong)puVar12 + 0x2a) = *puVar5;
            puVar12[0xc] = uVar2 + 1;
            puVar12[6] = 3;
            uVar13 = puVar5[7];
            puVar12[0x1a] = (uint)uVar13;
            *(ushort *)(puVar12 + 0x17) = uVar13;
            puVar12[0x1b] = uVar2 - 1;
            *(undefined8 *)(puVar12 + 8) = *(undefined8 *)(piVar15 + 8);
            *(undefined8 *)(puVar12 + 0x2c) = *(undefined8 *)(piVar15 + 0xc);
            *(ushort *)(puVar12 + 2) = *(ushort *)(piVar15 + 2) & 0x199;
            *(uint **)(puVar12 + 4) = tcp_active_pcbs;
            tcp_active_pcbs = puVar12;
            tcp_parseopt((longlong)puVar12);
            local_res8[0] =
                 ((ushort)puVar12[0x10] & 0xff00) << 8 | 0x402 | (uint)(ushort)puVar12[0x10] << 0x18
            ;
            tcp_enqueue((longlong)puVar12,(void *)0x0,0,0x12,'\0',local_res8,4);
LAB_14002527a:
            crashdump_tcp4_output(puVar12);
          }
        }
        else {
          tcp_rst(uVar14 + 1,uVar13 + uVar17,(uint *)(lVar6 + 0x10),(uint *)(lVar6 + 0xc),puVar5[1],
                  *puVar5);
        }
        goto LAB_14002516e;
      }
      piVar16 = piVar15;
      piVar7 = *(int **)(piVar15 + 4);
    }
    if ((puVar5[6] >> 8 & 4) == 0) {
      tcp_rst(uVar14,uVar13 + uVar17,(uint *)(lVar6 + 0x10),(uint *)(lVar6 + 0xc),puVar5[1],*puVar5)
      ;
    }
    pbuf_free(param_1);
LAB_14002539f:
    uVar11 = tcp_pcbs_sane();
    if ((short)uVar11 == 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_input: tcp_pcbs_sane()");
    }
  }
  else {
LAB_14002516e:
    pbuf_free(param_1);
  }
  return;
}



===== crashdump_tcp4_output @ 1400253c0 =====

ulonglong crashdump_tcp4_output(uint *param_1)

{
  short *psVar1;
  ushort uVar2;
  uint uVar3;
  longlong *plVar4;
  ushort *puVar5;
  undefined4 uVar6;
  uint uVar7;
  longlong *in_RAX;
  longlong *plVar8;
  uint7 extraout_var;
  longlong *plVar9;
  uint7 extraout_var_00;
  short sVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  
  if (tcp_input_pcb == param_1) goto LAB_14002577d;
  uVar2 = *(ushort *)((longlong)param_1 + 0x5a);
  in_RAX = (longlong *)(ulonglong)uVar2;
  plVar8 = *(longlong **)(param_1 + 0x22);
  plVar4 = *(longlong **)(param_1 + 0x20);
  uVar13 = param_1[0x1a];
  if ((uint)uVar2 <= param_1[0x1a]) {
    uVar13 = (uint)uVar2;
  }
  if (plVar8 != (longlong *)0x0) {
    plVar9 = (longlong *)*plVar8;
    while (plVar9 != (longlong *)0x0) {
      in_RAX = (longlong *)*plVar9;
      plVar8 = plVar9;
      plVar9 = in_RAX;
    }
  }
  if ((param_1[0xb] & 2) == 0) {
joined_r0x000140025541:
    while (plVar4 != (longlong *)0x0) {
      uVar12 = *(uint *)(plVar4[4] + 4);
      in_RAX = (longlong *)(ulonglong)((uint)*(ushort *)(plVar4 + 3) - param_1[0x15]);
      if (uVar13 < (uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 |
                   uVar12 << 0x18) + ((uint)*(ushort *)(plVar4 + 3) - param_1[0x15])) break;
      *(longlong *)(param_1 + 0x20) = *plVar4;
      if (param_1[6] != 2) {
        uVar2 = *(ushort *)(plVar4[4] + 0xc);
        *(ushort *)(plVar4[4] + 0xc) = uVar2 & 0xff00 | 0x1000 | uVar2 & 0xff;
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] & 0xfc;
      }
      uVar12 = param_1[0xc];
      *(uint *)(plVar4[4] + 8) =
           uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18;
      uVar2 = (ushort)param_1[0xd];
      if (uVar2 < (ushort)param_1[0x10]) {
        *(undefined2 *)(plVar4[4] + 0xe) = 0;
      }
      else {
        *(ushort *)(plVar4[4] + 0xe) = uVar2 << 8 | uVar2 >> 8;
      }
      if (*param_1 == 0) {
        plVar9 = ip_route(param_1 + 1);
        if (plVar9 != (longlong *)0x0) {
          if ((uint *)(plVar9 + 0x24) == (uint *)0x0) {
            uVar12 = 0;
          }
          else {
            uVar12 = *(uint *)(plVar9 + 0x24);
          }
          *param_1 = uVar12;
          goto LAB_1400255f4;
        }
      }
      else {
LAB_1400255f4:
        *(undefined2 *)((longlong)param_1 + 0x3e) = 0;
        if (param_1[0x11] == 0) {
          param_1[0x11] = tcp_ticks;
          uVar12 = *(uint *)(plVar4[4] + 4);
          param_1[0x12] =
               uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18;
        }
        sVar10 = (short)plVar4[4] - *(short *)(plVar4[1] + 8);
        psVar1 = (short *)(plVar4[1] + 0x12);
        *psVar1 = *psVar1 - sVar10;
        *(short *)(plVar4[1] + 0x10) = *(short *)(plVar4[1] + 0x10) - sVar10;
        *(longlong *)(plVar4[1] + 8) = plVar4[4];
        *(undefined2 *)(plVar4[4] + 0x10) = 0;
        uVar6 = inet_chksum_pseudo((longlong *)plVar4[1],param_1,param_1 + 1,6,
                                   *(ushort *)((longlong *)plVar4[1] + 2));
        *(short *)(plVar4[4] + 0x10) = (short)uVar6;
        crashdump_ip4_output
                  (plVar4[1],(int *)param_1,param_1 + 1,*(undefined1 *)((longlong)param_1 + 0xb),
                   *(byte *)((longlong)param_1 + 10),6);
      }
      uVar2 = *(ushort *)(plVar4[4] + 0xc) >> 8;
      if (((uVar2 & 1) != 0) || (iVar11 = 0, (uVar2 & 2) != 0)) {
        iVar11 = 1;
      }
      uVar12 = *(uint *)(plVar4[4] + 4);
      uVar12 = iVar11 + (uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 |
                        uVar12 << 0x18) + (uint)*(ushort *)(plVar4 + 3);
      param_1[0x18] = uVar12;
      if ((int)(param_1[0x19] - uVar12) < 0) {
        param_1[0x19] = uVar12;
      }
      uVar2 = *(ushort *)(plVar4[4] + 0xc) >> 8;
      if (((uVar2 & 1) != 0) || (iVar11 = 0, (uVar2 & 2) != 0)) {
        iVar11 = 1;
      }
      in_RAX = (longlong *)(ulonglong)((uint)*(ushort *)(plVar4 + 3) + iVar11);
      if ((uint)*(ushort *)(plVar4 + 3) + iVar11 == 0) {
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
          uVar3 = *(uint *)(plVar8[4] + 4);
          uVar7 = (uVar12 << 0x10 | uVar12 & 0xff00) << 8;
          in_RAX = (longlong *)(ulonglong)uVar7;
          if ((int)(((uVar12 & 0xff0000 | uVar12 >> 0x10) >> 8 | uVar7) -
                   ((uVar3 & 0xff0000 | uVar3 >> 0x10) >> 8 | (uVar3 << 0x10 | uVar3 & 0xff00) << 8)
                   ) < 0) {
            *plVar4 = *(longlong *)(param_1 + 0x22);
            *(longlong **)(param_1 + 0x22) = plVar4;
            goto LAB_14002576d;
          }
          *plVar8 = (longlong)plVar4;
        }
        plVar8 = plVar4;
      }
LAB_14002576d:
      plVar4 = *(longlong **)(param_1 + 0x20);
    }
  }
  else {
    if (plVar4 != (longlong *)0x0) {
      uVar12 = *(uint *)(plVar4[4] + 4);
      in_RAX = (longlong *)(ulonglong)((uint)*(ushort *)(plVar4 + 3) - param_1[0x15]);
      if ((uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18) +
          ((uint)*(ushort *)(plVar4 + 3) - param_1[0x15]) <= uVar13) goto joined_r0x000140025541;
    }
    plVar8 = pbuf_alloc(1,0x14,0);
    if (plVar8 == (longlong *)0x0) {
      return 0xfe;
    }
    *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] & 0xfc;
    puVar5 = (ushort *)plVar8[1];
    *puVar5 = (ushort)param_1[10] << 8 | (ushort)param_1[10] >> 8;
    puVar5[1] = *(ushort *)((longlong)param_1 + 0x2a) << 8 |
                *(ushort *)((longlong)param_1 + 0x2a) >> 8;
    uVar13 = param_1[0x18];
    *(uint *)(puVar5 + 2) =
         uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 | uVar13 << 0x18;
    uVar13 = param_1[0xc];
    *(uint *)(puVar5 + 4) =
         uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 | uVar13 << 0x18;
    puVar5[6] = puVar5[6] & 0xd000 | 0x1000 | puVar5[6] & 0xff;
    puVar5[7] = (ushort)param_1[0xd] << 8 | (ushort)param_1[0xd] >> 8;
    puVar5[8] = 0;
    puVar5[9] = 0;
    puVar5[6] = 0x1050;
    uVar6 = inet_chksum_pseudo(plVar8,param_1,param_1 + 1,6,*(ushort *)(plVar8 + 2));
    puVar5[8] = (ushort)uVar6;
    crashdump_ip4_output
              ((longlong)plVar8,(int *)param_1,param_1 + 1,*(undefined1 *)((longlong)param_1 + 0xb),
               *(byte *)((longlong)param_1 + 10),6);
    pbuf_free(plVar8);
    in_RAX = (longlong *)((ulonglong)extraout_var << 8);
  }
LAB_14002577d:
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== crashdump_tcp4_recved @ 14002579c =====

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



===== etharp_arp_input @ 1400257fc =====

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



===== etharp_init @ 140025954 =====

void etharp_init(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = &DAT_140080e60;
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



===== etharp_output @ 14002597c =====

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
      puVar8 = (undefined2 *)&DAT_14002f540;
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
    uVar4 = (**(code **)(param_1 + 0x20))(param_1,param_3);
  }
  else {
    uVar4 = CONCAT71((int7)(uVar4 >> 8),0xfe);
  }
  return uVar4;
}



===== etharp_query @ 140025a98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong etharp_query(longlong param_1,uint *param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined7 extraout_var;
  longlong *plVar6;
  longlong *plVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  byte bVar11;
  
  uVar3 = 0xff;
  uVar4 = ip_addr_isbroadcast(param_2,param_1);
  if ((char)uVar4 != '\0') {
LAB_140025bf5:
    return CONCAT71((int7)(uVar4 >> 8),0xf8);
  }
  uVar4 = 0;
  if ((((byte)*param_2 & 0xf0) == 0xe0) || (*param_2 == 0)) goto LAB_140025bf5;
  uVar4 = find_entry((int *)param_2,1);
  if ((char)uVar4 < '\0') {
    return uVar4;
  }
  lVar5 = (longlong)(char)uVar4;
  iVar8 = (&DAT_140080e74)[lVar5 * 10];
  if (iVar8 == 0) {
    iVar8 = 1;
    (&DAT_140080e74)[lVar5 * 10] = 1;
  }
  if ((iVar8 != 1) && (iVar8 != 2)) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("arp_table[i].state == PENDING or STABLE");
  }
  if ((iVar8 == 1) || (param_3 == (longlong *)0x0)) {
    uVar3 = etharp_request(param_1,param_2);
    plVar7 = (longlong *)CONCAT71(extraout_var,uVar3);
    if (param_3 == (longlong *)0x0) goto LAB_140025bf0;
  }
  uVar1 = (&DAT_140080e74)[lVar5 * 10];
  if (uVar1 == 2) {
    uVar4 = (ulonglong)*(byte *)(param_1 + 0x30);
    lVar2 = param_3[1];
    if (*(byte *)(param_1 + 0x30) != 0) {
      puVar9 = (undefined1 *)(lVar2 + uVar4);
      do {
        puVar10 = puVar9 + -1;
        *puVar10 = puVar9[(lVar5 * 0x28 - lVar2) + 0x140080e6b];
        puVar9[5] = puVar10[(param_1 + 0x31) - lVar2];
        bVar11 = (char)uVar4 - 1;
        uVar4 = (ulonglong)bVar11;
        puVar9 = puVar10;
      } while (bVar11 != 0);
    }
    *(undefined2 *)(lVar2 + 0xc) = 8;
    plVar7 = (longlong *)(**(code **)(param_1 + 0x20))(param_1,param_3);
    uVar3 = SUB81(plVar7,0);
  }
  else {
    plVar7 = (longlong *)(ulonglong)uVar1;
    if ((uVar1 == 1) && (plVar6 = pbuf_take(param_3), plVar7 = plVar6, plVar6 != (longlong *)0x0)) {
      if ((&DAT_140080e60)[lVar5 * 5] == 0) {
        plVar7 = (longlong *)pbuf_ref((longlong)plVar6);
        (&DAT_140080e60)[lVar5 * 5] = plVar6;
      }
      uVar3 = 0;
    }
  }
LAB_140025bf0:
  return CONCAT71((int7)((ulonglong)plVar7 >> 8),uVar3);
}



===== etharp_request @ 140025c18 =====

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



===== etharp_tmr @ 140025d50 =====

void etharp_tmr(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  
  piVar3 = &DAT_140080e74;
  lVar4 = 10;
  do {
    iVar2 = *piVar3;
    bVar1 = (char)piVar3[1] + 1;
    *(byte *)(piVar3 + 1) = bVar1;
    if (iVar2 == 2) {
      if (bVar1 < 0xf0) goto LAB_140025d91;
      *piVar3 = 3;
LAB_140025d96:
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
LAB_140025d91:
      if (iVar2 == 3) goto LAB_140025d96;
    }
    piVar3 = piVar3 + 10;
    lVar4 = lVar4 + -1;
    if (lVar4 == 0) {
      return;
    }
  } while( true );
}



===== find_entry @ 140025dc4 =====

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
    if ((bVar11 == 10) && (puVar5 = (undefined8 *)(uVar6 * 5), (&DAT_140080e74)[uVar6 * 10] == 0)) {
      bVar11 = bVar12;
    }
    else {
      uVar2 = (&DAT_140080e74)[uVar6 * 10];
      puVar5 = (undefined8 *)(ulonglong)uVar2;
      if (uVar2 == 1) {
        if ((param_1 != (int *)0x0) && (iVar3 = (&DAT_140080e68)[uVar6 * 10], *param_1 == iVar3)) {
LAB_140025ee9:
          return (ulonglong)CONCAT31((int3)((uint)iVar3 >> 8),bVar12);
        }
        bVar1 = (&DAT_140080e78)[uVar6 * 0x28];
        puVar5 = &DAT_140080e60;
        if ((&DAT_140080e60)[uVar6 * 5] == 0) {
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
        if ((param_1 != (int *)0x0) && (iVar3 = (&DAT_140080e68)[uVar6 * 10], *param_1 == iVar3))
        goto LAB_140025ee9;
        puVar5 = (undefined8 *)(uVar6 * 5);
        if (bVar13 <= (byte)(&DAT_140080e78)[uVar6 * 0x28]) {
          bVar7 = bVar12;
          bVar13 = (&DAT_140080e78)[uVar6 * 0x28];
        }
      }
    }
    bVar12 = bVar12 + 1;
  } while (bVar12 < 10);
  if (bVar11 == 10) {
    if ((param_2 & 1) == 0) goto LAB_140025e90;
  }
  else if ((char)bVar11 < '\n') goto LAB_140025f1c;
  if ((char)bVar7 < '\n') {
    bVar11 = bVar7;
    if ((&DAT_140080e60)[(ulonglong)bVar7 * 5] != 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("arp_table[i].p == NULL");
    }
  }
  else if ((char)bVar9 < '\n') {
    bVar11 = bVar9;
  }
  else {
    if ('\t' < (char)bVar8) {
LAB_140025e90:
      return CONCAT71((int7)((ulonglong)puVar5 >> 8),0xff);
    }
    pbuf_free((undefined8 *)(&DAT_140080e60)[(ulonglong)bVar8 * 5]);
    (&DAT_140080e60)[(ulonglong)bVar8 * 5] = 0;
    bVar11 = bVar8;
  }
LAB_140025f1c:
  if (9 < bVar11) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("i < ARP_TABLE_SIZE");
  }
  uVar6 = (ulonglong)bVar11;
  (&DAT_140080e74)[uVar6 * 10] = 0;
  if (param_1 != (int *)0x0) {
    (&DAT_140080e68)[uVar6 * 10] = *param_1;
  }
  (&DAT_140080e78)[uVar6 * 0x28] = 0;
  return (ulonglong)bVar11;
}



===== ntohs @ 140025f90 =====

u_short __stdcall ntohs(u_short netshort)

{
  return netshort >> 8 | netshort << 8;
}



===== icmp_dest_unreach @ 140025fa0 =====

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



===== inet_chksum_pbuf @ 140026074 =====

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



===== inet_chksum_pseudo @ 140026114 =====

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



===== ip_addr_isbroadcast @ 140026214 =====

ulonglong ip_addr_isbroadcast(uint *param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = *param_1;
  uVar4 = (ulonglong)~uVar3;
  if ((~uVar3 == 0) || (uVar3 == 0)) {
LAB_140026257:
    return CONCAT71((int7)(uVar4 >> 8),1);
  }
  if ((*(byte *)(param_2 + 0x3a) & 2) != 0) {
    uVar1 = *(uint *)(param_2 + 0x120);
    uVar4 = (ulonglong)uVar1;
    if (uVar3 != uVar1) {
      uVar2 = *(uint *)(param_2 + 0x124);
      uVar4 = (ulonglong)(uVar2 & uVar3);
      if (((uVar2 & uVar3) == (uVar2 & uVar1)) &&
         (uVar3 = ~uVar2 & uVar3, uVar4 = (ulonglong)uVar3, uVar3 == ~uVar2)) goto LAB_140026257;
    }
  }
  return uVar4 & 0xffffffffffffff00;
}



===== ip_output_if @ 14002625c =====

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
    uVar3 = DAT_14007f170;
    if ((char)uVar5 != '\0') {
      return CONCAT71((int7)(uVar5 >> 8),0xfe);
    }
    puVar1 = *(ushort **)(param_1 + 8);
    puVar1[4] = CONCAT11(param_6,param_4);
    *(undefined4 *)(puVar1 + 8) = *param_3;
    *puVar1 = (ushort)param_5 << 8 | 0x45;
    puVar1[1] = *(ushort *)(param_1 + 0x10) << 8 | *(ushort *)(param_1 + 0x10) >> 8;
    puVar1[3] = 0x40;
    uVar2 = DAT_14007f170 >> 8;
    DAT_14007f170 = uVar3 + 1;
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



===== ip_route @ 1400263a4 =====

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



===== lwip_standard_chksum @ 1400263e0 =====

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



===== netif_add @ 140026468 =====

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
  *(char *)((longlong)param_1 + 0x3d) = (char)DAT_14007f120;
  DAT_14007f120 = DAT_14007f120 + 1;
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



===== netif_remove @ 1400264f0 =====

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



===== netif_set_addr @ 14002653c =====

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



===== netif_set_down @ 140026588 =====

void netif_set_down(longlong param_1)

{
  *(byte *)(param_1 + 0x3a) = *(byte *)(param_1 + 0x3a) & 0xfe;
  return;
}



===== netif_set_ipaddr @ 140026590 =====

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



===== stack_ipv4_bringup @ 140026610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 stack_ipv4_bringup(longlong param_1)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined2 *puVar6;
  
  puVar2 = (undefined8 *)(param_1 + 0x168);
  mem_init();
  memp_init();
  pbuf_init();
  netif_default = (undefined8 *)0x0;
  netif_list = 0;
  tcp_listen_pcbs = 0;
  tcp_active_pcbs = 0;
  tcp_tw_pcbs = 0;
  _tcp_tmp_pcb = 0;
  tcp_ticks = 0;
  DAT_14007f122 = 0;
  lVar3 = *(longlong *)(iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8)
  ;
  puVar5 = netif_add(puVar2,(int *)(lVar3 + 0x458),(undefined4 *)(lVar3 + 0x468),
                     (undefined4 *)(lVar3 + 0x478),*l2_driver_intf,(undefined *)l2_driver_intf[0xc],
                     l2_driver_intf[0xd],crashdump_ip4_input);
  if (puVar5 != (undefined8 *)0x0) {
    puVar1 = (undefined4 *)(param_1 + 0x199);
    netif_default = puVar2;
    *(undefined1 *)(param_1 + 0x1a2) = 2;
    *(undefined2 *)(param_1 + 0x1a0) = 0x5dc;
    *(undefined1 *)(param_1 + 0x198) = 6;
    (*(code *)l2_driver_intf[8])(*l2_driver_intf,puVar1,*(undefined4 *)(param_1 + 0x150));
    (*(code *)l2_driver_intf[9])(*l2_driver_intf,puVar1);
    lVar3 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    *(undefined4 *)(lVar3 + 0x12) = *puVar1;
    *(undefined2 *)(lVar3 + 0x16) = *(undefined2 *)(param_1 + 0x19d);
    etharp_init();
    puVar6 = iscsiAddTimer(5000,etharp_tmr);
    *(undefined2 **)(param_1 + 0x158) = puVar6;
    puVar6 = iscsiAddTimer(0xfa,tcp_tmr);
    *(undefined2 **)(param_1 + 0x160) = puVar6;
    iVar4 = (*(code *)l2_driver_intf[0xb])(*l2_driver_intf);
    if (iVar4 == 4) {
      *(byte *)(param_1 + 0x1a2) = *(byte *)(param_1 + 0x1a2) | 1;
      (**(code **)(param_1 + 0x170))(puVar2);
      return 0;
    }
  }
  return 0xffffffff;
}



===== stack_ipv4_close_connection @ 1400267d0 =====

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
LAB_140024d47:
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
        goto LAB_140024d47;
      }
      tcp_pcb_remove(&tcp_active_pcbs,param_1);
      iVar4 = 3;
    }
    cVar2 = '\0';
    memp_free(iVar4,(longlong)param_1);
  }
  return cVar2;
}



===== stack_ipv4_connected_callback @ 1400267e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong stack_ipv4_connected_callback(undefined *param_1,undefined8 param_2,char param_3)

{
  ulonglong uVar1;
  
  uVar1 = (*(code *)param_1)(param_2,param_3 == '\0');
  return uVar1 & 0xffffffffffffff00;
}



===== stack_ipv4_flush_tcp_data @ 140026810 =====

int stack_ipv4_flush_tcp_data(uint *param_1)

{
  undefined8 uVar1;
  
  uVar1 = crashdump_tcp4_output(param_1);
  return -(uint)((char)uVar1 != '\0');
}



===== stack_ipv4_init @ 140026824 =====

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



===== stack_ipv4_rx_packet @ 140026880 =====

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



===== stack_ipv4_rx_tcp_data @ 140026960 =====

undefined1 * stack_ipv4_rx_tcp_data(undefined8 param_1,uint *param_2,longlong *param_3)

{
  uint7 extraout_var;
  longlong *plVar1;
  ushort uVar2;
  
  if (param_3 != (longlong *)0x0) {
    uVar2 = 0;
    plVar1 = param_3;
    do {
      uVar2 = uVar2 + *(ushort *)((longlong)plVar1 + 0x12);
      iscsiSessionServiceRxIndication((char *)plVar1[1],(uint)*(ushort *)((longlong)plVar1 + 0x12));
      plVar1 = (longlong *)*plVar1;
    } while (plVar1 != (longlong *)0x0);
    crashdump_tcp4_recved(param_2,uVar2);
    pbuf_free(param_3);
    register0x00000020 = (BADSPACEBASE *)((ulonglong)extraout_var << 8);
  }
  return (undefined1 *)register0x00000020;
}



===== stack_ipv4_set_addr @ 1400269e0 =====

void stack_ipv4_set_addr(longlong param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  netif_set_addr(param_1 + 0x168,param_2,param_3,param_4);
  return;
}



===== stack_ipv4_setup_connection @ 1400269f0 =====

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



===== stack_ipv4_write_tcp_data @ 140026a70 =====

int stack_ipv4_write_tcp_data(longlong param_1,void *param_2,ushort param_3,char param_4)

{
  undefined8 uVar1;
  
  uVar1 = tcp_write(param_1,param_2,param_3,param_4);
  return -(uint)((char)uVar1 != '\0');
}



===== tcp_abort @ 140026a84 =====

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



===== tcp_alloc @ 140026b8c =====

undefined8 * tcp_alloc(byte param_1)

{
  byte bVar1;
  uint uVar2;
  undefined8 *_Dst;
  uint *puVar3;
  uint *puVar4;
  byte bVar5;
  uint uVar6;
  
  _Dst = memp_malloc(3);
  if (_Dst == (undefined8 *)0x0) {
    uVar6 = 0;
    puVar4 = (uint *)0x0;
    puVar3 = tcp_tw_pcbs;
    if (tcp_tw_pcbs != (uint *)0x0) {
      do {
        uVar2 = tcp_ticks - puVar3[0xe];
        if (uVar6 <= uVar2) {
          puVar4 = puVar3;
        }
        puVar3 = *(uint **)(puVar3 + 4);
        if (uVar2 < uVar6) {
          uVar2 = uVar6;
        }
        uVar6 = uVar2;
      } while (puVar3 != (uint *)0x0);
      if (puVar4 != (uint *)0x0) {
        tcp_abort(puVar4);
      }
    }
    _Dst = memp_malloc(3);
    if (_Dst == (undefined8 *)0x0) {
      bVar5 = 0x7f;
      uVar6 = 0;
      puVar4 = (uint *)0x0;
      puVar3 = tcp_active_pcbs;
      if (tcp_active_pcbs != (uint *)0x0) {
        do {
          bVar1 = (byte)puVar3[7];
          if (((bVar1 <= param_1) && (bVar1 <= bVar5)) && (uVar6 <= tcp_ticks - puVar3[0xe])) {
            puVar4 = puVar3;
            bVar5 = bVar1;
            uVar6 = tcp_ticks - puVar3[0xe];
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
  DAT_14003a744 = DAT_14003a744 + tcp_ticks;
  *(int *)(_Dst + 0xe) = DAT_14003a744;
  *(int *)(_Dst + 0xc) = DAT_14003a744;
  *(int *)((longlong)_Dst + 100) = DAT_14003a744;
  *(int *)((longlong)_Dst + 0x54) = DAT_14003a744;
  *(int *)((longlong)_Dst + 0x74) = DAT_14003a744;
  *(int *)(_Dst + 7) = tcp_ticks;
  _Dst[0x14] = tcp_recv_null;
  *(undefined1 *)((longlong)_Dst + 0x3c) = 0;
  *(undefined4 *)(_Dst + 0x19) = 7200000;
  *(undefined1 *)((longlong)_Dst + 0xcc) = 0;
  return _Dst;
}



===== tcp_connect @ 140026d14 =====

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
  uint local_res10 [2];
  
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
    DAT_14003a744 = tcp_ticks + DAT_14003a744;
    param_1[0x18] = DAT_14003a744;
    uVar3 = DAT_14003a744 - 1;
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
    local_res10[0] =
         ((ushort)param_1[0x10] & 0xff00) << 8 | 0x402 | (uint)(ushort)param_1[0x10] << 0x18;
    tcp_active_pcbs = param_1;
    uVar4 = tcp_enqueue((longlong)param_1,(void *)0x0,0,2,'\0',local_res10,4);
    cVar1 = (char)uVar4;
    if (cVar1 == '\0') {
      uVar4 = crashdump_tcp4_output(param_1);
    }
    uVar5 = CONCAT71((int7)((ulonglong)uVar4 >> 8),cVar1);
  }
  return uVar5;
}



===== tcp_enqueue @ 140026e00 =====

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
          goto LAB_140026ec5;
        }
      }
      else if ((*(longlong *)(param_1 + 0x88) == 0) && (*(longlong *)(param_1 + 0x80) == 0)) {
        pcVar9 = "tcp_enqueue: pbufs on queue => at least one queue non-empty";
LAB_140026ec5:
                    /* WARNING: Subroutine does not return */
        DbgPrint(pcVar9);
      }
      local_res8 = (undefined8 *)0x0;
      _Size = 0;
      local_58 = param_2;
LAB_140026edd:
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
      if (puVar5 == (undefined8 *)0x0) goto LAB_1400272b4;
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
            goto LAB_140026fcd;
          }
          goto LAB_1400272b4;
        }
        puVar6 = pbuf_alloc(0,uVar4,1);
        in_RAX = 0;
        if (puVar6 == (undefined8 *)0x0) goto LAB_1400272b4;
        puVar6[1] = local_58;
        puVar5[2] = local_58;
        plVar7 = pbuf_alloc(0,0,0);
        puVar5[1] = plVar7;
        if (plVar7 == (longlong *)0x0) {
          pbuf_free(puVar6);
          in_RAX = (ulonglong)extraout_var << 8;
LAB_1400272b4:
          if (puVar11 != (undefined8 *)0x0) {
            tcp_segs_free(puVar11);
            in_RAX = (ulonglong)extraout_var_00 << 8;
          }
          if (((*(char *)(param_1 + 0x7c) != '\0') && (*(longlong *)(param_1 + 0x88) == 0)) &&
             (*(longlong *)(param_1 + 0x80) == 0)) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_enqueue: valid queue length");
          }
          goto LAB_1400272e9;
        }
        bVar10 = bVar10 + 2;
        in_RAX = pbuf_cat(plVar7,(longlong)puVar6);
      }
      else {
        puVar6 = pbuf_alloc(0,(ushort)param_7,0);
        puVar5[1] = puVar6;
        in_RAX = 0;
        if (puVar6 == (undefined8 *)0x0) goto LAB_1400272b4;
LAB_140026fcd:
        bVar10 = bVar10 + 1;
        in_RAX = puVar6[1];
        puVar5[2] = in_RAX;
      }
      if (0xb3 < bVar10) goto LAB_1400272b4;
      *(ushort *)(puVar5 + 3) = uVar4;
      in_RAX = pbuf_header(puVar5[1],0x14);
      if ((char)in_RAX != '\0') goto LAB_1400272b4;
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
      goto LAB_140026edd;
    }
  }
LAB_1400272e9:
  return CONCAT71((int7)(in_RAX >> 8),0xff);
}



===== tcp_fasttmr @ 1400272fc =====

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



===== tcp_keepalive @ 140027334 =====

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
         uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
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



===== tcp_new_port @ 140027424 =====

void tcp_new_port(void)

{
  longlong lVar1;
  
LAB_14002742b:
  do {
    DAT_14003a740 = DAT_14003a740 + 1;
    if (0x7fff < DAT_14003a740) {
      DAT_14003a740 = 0x1000;
    }
    for (lVar1 = tcp_active_pcbs; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x10)) {
      if (*(ushort *)(lVar1 + 0x28) == DAT_14003a740) goto LAB_14002742b;
    }
    for (lVar1 = tcp_tw_pcbs; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x10)) {
      if (*(ushort *)(lVar1 + 0x28) == DAT_14003a740) goto LAB_14002742b;
    }
    lVar1 = tcp_listen_pcbs;
    while( true ) {
      if (lVar1 == 0) {
        return;
      }
      if (*(ushort *)(lVar1 + 0x28) == DAT_14003a740) break;
      lVar1 = *(longlong *)(lVar1 + 0x10);
    }
  } while( true );
}



===== tcp_parseopt @ 140027494 =====

void tcp_parseopt(longlong param_1)

{
  char cVar1;
  ulonglong uVar2;
  ushort uVar3;
  int iVar4;
  byte bVar5;
  
  if (0x5000 < (ushort)((*(ushort *)(DAT_14007f150 + 0xc) & 0xf0) << 8)) {
    bVar5 = 0;
    iVar4 = ((*(ushort *)(DAT_14007f150 + 0xc) & 0xff) >> 2 & 0xfffffffc) - 0x14;
    if (0 < iVar4) {
      do {
        uVar2 = (ulonglong)bVar5;
        cVar1 = *(char *)(uVar2 + 0x14 + DAT_14007f150);
        if (cVar1 == '\0') {
          return;
        }
        if (cVar1 == '\x01') {
          cVar1 = '\x01';
        }
        else {
          if ((cVar1 == '\x02') && (*(char *)(uVar2 + 0x15 + DAT_14007f150) == '\x04')) {
            uVar3 = CONCAT11(*(undefined1 *)(uVar2 + 0x16 + DAT_14007f150),
                             *(undefined1 *)(uVar2 + 0x17 + DAT_14007f150));
            if (0x5b4 < uVar3) {
              uVar3 = 0x5b4;
            }
            *(ushort *)(param_1 + 0x40) = uVar3;
            return;
          }
          cVar1 = *(char *)(uVar2 + 0x15 + DAT_14007f150);
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



===== tcp_pcb_purge @ 140027530 =====

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



===== tcp_pcb_remove @ 140027588 =====

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



===== tcp_pcbs_sane @ 14002762c =====

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



===== tcp_process @ 1400276c0 =====

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
  
  uVar4 = tcp_ticks;
  bVar1 = DAT_14007f123;
  if ((DAT_14007f123 & 4) == 0) {
    in_RAX = (uint *)(ulonglong)tcp_ticks;
    param_1[0xe] = tcp_ticks;
    *(undefined1 *)(param_1 + 0x33) = 0;
    uVar7 = DAT_14007f160;
    iVar6 = DAT_14007f124;
    uVar3 = param_1[6];
    if (uVar3 == 2) {
      in_RAX = (uint *)((ulonglong)CONCAT31((int3)(uVar4 >> 8),bVar1) & 0xffffffffffffff12);
      if ((char)in_RAX == '\x12') {
        puVar5 = *(undefined8 **)(param_1 + 0x22);
        in_RAX = (uint *)puVar5[4];
        uVar4 = in_RAX[1];
        if (DAT_14007f160 ==
            (uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18) + 1) {
          *(short *)((longlong)param_1 + 0x7a) = *(short *)((longlong)param_1 + 0x7a) + 1;
          param_1[0x15] = uVar7;
          param_1[0xc] = iVar6 + 1;
          uVar2 = DAT_14007f150[7];
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
          goto LAB_140027b56;
        }
      }
      if ((bVar1 & 0x10) != 0) {
LAB_140027b1b:
        in_RAX = (uint *)tcp_rst(DAT_14007f160,(uint)DAT_14007f164 + DAT_14007f124,
                                 (uint *)(DAT_14007f158 + 0x10),(uint *)(DAT_14007f158 + 0xc),
                                 DAT_14007f150[1],*DAT_14007f150);
      }
    }
    else if (uVar3 == 3) {
      if ((bVar1 & 0x14) == 0x10) {
        if (((int)(DAT_14007f160 - param_1[0x15]) < 1) || (0 < (int)(DAT_14007f160 - param_1[0x18]))
           ) goto LAB_140027b1b;
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
LAB_140027988:
      cVar8 = tcp_receive(param_1);
      in_RAX = (uint *)CONCAT71(extraout_var_03,cVar8);
      if (((DAT_14007f123 & 1) != 0) && (cVar8 != '\0')) {
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
        in_RAX = (uint *)crashdump_tcp4_output(param_1);
        param_1[6] = 7;
      }
    }
    else if (uVar3 == 5) {
      tcp_receive(param_1);
      in_RAX = (uint *)CONCAT71(extraout_var_02,DAT_14007f123);
      if ((DAT_14007f123 & 1) == 0) {
        if (((DAT_14007f123 & 0x10) != 0) &&
           (in_RAX = (uint *)(ulonglong)param_1[0x18], DAT_14007f160 == param_1[0x18])) {
          param_1[6] = 6;
        }
      }
      else {
        if (((DAT_14007f123 & 0x10) != 0) && (DAT_14007f160 == param_1[0x18])) {
          *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
          crashdump_tcp4_output(param_1);
          tcp_pcb_purge((longlong)param_1);
          puVar11 = tcp_active_pcbs;
          if (tcp_active_pcbs == param_1) goto LAB_140027874;
          while (_tcp_tmp_pcb = puVar11, puVar11 != (uint *)0x0) {
            puVar11 = *(uint **)(puVar11 + 4);
            if ((puVar11 != (uint *)0x0) && (puVar11 == param_1)) goto LAB_1400278aa;
          }
          goto LAB_1400278b2;
        }
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
        in_RAX = (uint *)crashdump_tcp4_output(param_1);
        param_1[6] = 8;
      }
    }
    else if (uVar3 == 6) {
      tcp_receive(param_1);
      in_RAX = (uint *)((ulonglong)extraout_var_01 << 8);
      if ((DAT_14007f123 & 1) != 0) {
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
        crashdump_tcp4_output(param_1);
        tcp_pcb_purge((longlong)param_1);
        puVar11 = tcp_active_pcbs;
        if (tcp_active_pcbs == param_1) {
LAB_140027874:
          tcp_active_pcbs = *(uint **)(tcp_active_pcbs + 4);
        }
        else {
          while (_tcp_tmp_pcb = puVar11, puVar11 != (uint *)0x0) {
            puVar11 = *(uint **)(puVar11 + 4);
            if ((puVar11 != (uint *)0x0) && (puVar11 == param_1)) goto LAB_1400278aa;
          }
        }
LAB_1400278b2:
        param_1[4] = 0;
        param_1[5] = 0;
        param_1[6] = 10;
        *(uint **)(param_1 + 4) = tcp_tw_pcbs;
        in_RAX = tcp_tw_pcbs;
        tcp_tw_pcbs = param_1;
      }
    }
    else {
      if (uVar3 == 7) goto LAB_140027988;
      if (uVar3 == 8) {
        tcp_receive(param_1);
        in_RAX = (uint *)((ulonglong)extraout_var_00 << 8);
        if (((DAT_14007f123 & 0x10) != 0) &&
           (in_RAX = (uint *)(ulonglong)param_1[0x18], DAT_14007f160 == param_1[0x18])) {
          *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
          crashdump_tcp4_output(param_1);
          tcp_pcb_purge((longlong)param_1);
          puVar11 = tcp_active_pcbs;
          if (tcp_active_pcbs == param_1) goto LAB_140027874;
          while (_tcp_tmp_pcb = puVar11, puVar11 != (uint *)0x0) {
            puVar11 = *(uint **)(puVar11 + 4);
            if ((puVar11 != (uint *)0x0) && (puVar11 == param_1)) goto LAB_1400278aa;
          }
          goto LAB_1400278b2;
        }
      }
      else if (uVar3 == 9) {
        tcp_receive(param_1);
        in_RAX = (uint *)((ulonglong)extraout_var << 8);
        if (((DAT_14007f123 & 0x10) != 0) &&
           (in_RAX = (uint *)(ulonglong)param_1[0x18], DAT_14007f160 == param_1[0x18])) {
          param_1[6] = 0;
          DAT_14007f166 = 0x10;
        }
      }
    }
LAB_140027b56:
    uVar9 = (ulonglong)in_RAX & 0xffffffffffffff00;
  }
  else {
    if (param_1[6] == 2) {
      in_RAX = (uint *)(ulonglong)param_1[0x18];
      if (DAT_14007f160 != param_1[0x18]) goto LAB_140027b56;
    }
    else {
      if (((int)(DAT_14007f124 - param_1[0xc]) < 0) ||
         (in_RAX = (uint *)(ulonglong)(ushort)param_1[0xd],
         0 < (int)((DAT_14007f124 - (uint)(ushort)param_1[0xd]) - param_1[0xc])))
      goto LAB_140027b56;
      if (param_1[6] == 0) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("tcp_input: pcb->state != CLOSED");
      }
    }
    *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] & 0xfe;
    uVar9 = CONCAT71((int7)((ulonglong)in_RAX >> 8),0xfc);
    DAT_14007f166 = 8;
  }
  return uVar9;
LAB_1400278aa:
  *(undefined8 *)(_tcp_tmp_pcb + 4) = *(undefined8 *)(param_1 + 4);
  goto LAB_1400278b2;
}



===== tcp_receive @ 140027b64 =====

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
  
  uVar16 = DAT_14007f160;
  uVar18 = DAT_14007f124;
  uVar11 = 0;
  if ((DAT_14007f123 & 0x10) != 0) {
    uVar10 = param_1[0x1b];
    uVar8 = param_1[0x1a];
    iVar13 = uVar8 + uVar10;
    if ((((int)(uVar10 - DAT_14007f124) < 0) ||
        ((uVar10 == DAT_14007f124 && ((int)(param_1[0x1c] - DAT_14007f160) < 0)))) ||
       ((param_1[0x1c] == DAT_14007f160 && (uVar8 < *(ushort *)(DAT_14007f150 + 0xe))))) {
      uVar8 = (uint)*(ushort *)(DAT_14007f150 + 0xe);
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
          uVar16 = DAT_14007f160;
          uVar18 = DAT_14007f124;
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
          if (0 < (int)(((((uVar18 & 0xff0000 | uVar18 >> 0x10) >> 8 |
                          (uVar18 & 0xff00 | uVar18 << 0x10) << 8) + (uint)*(ushort *)(puVar4 + 3))
                        - uVar16) + iVar13)) break;
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
          uVar16 = DAT_14007f160;
        } while (puVar4 != (undefined8 *)0x0);
        uVar18 = DAT_14007f124;
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
           (0 < (int)(uVar16 - param_1[0x19]))) goto LAB_140027ecb;
        *(undefined8 *)(param_1 + 0x20) = *puVar4;
        cVar3 = pbuf_clen((undefined8 *)puVar4[1]);
        *(char *)(param_1 + 0x1f) = (char)param_1[0x1f] - cVar3;
        crashdump_ip6_tcp_seg_free((longlong)puVar4);
        if (((char)param_1[0x1f] == '\0') || (*(longlong *)(param_1 + 0x22) != 0)) {
          puVar4 = *(undefined8 **)(param_1 + 0x20);
          if (puVar4 == (undefined8 *)0x0) goto LAB_140027ec4;
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
             uVar18 >> 0x18 | (uVar18 & 0xff0000) >> 8 | (uVar18 & 0xff00) << 8 | uVar18 << 0x18;
        if (puVar4 == (undefined8 *)0x0) goto LAB_140027ec4;
        uVar16 = DAT_14007f160;
      } while( true );
    }
    goto LAB_140027ed2;
  }
  goto LAB_140027f3c;
LAB_140027ec4:
  uVar16 = DAT_14007f160;
LAB_140027ecb:
  uVar18 = DAT_14007f124;
LAB_140027ed2:
  if ((param_1[0x11] != 0) && ((int)(param_1[0x12] - uVar16) < 0)) {
    sVar15 = ((short)tcp_ticks - ((short)param_1[0x13] >> 3)) - (short)param_1[0x11];
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
LAB_140027f3c:
  uVar16 = param_1[0xc];
  if (DAT_14007f164 == 0) {
    if (-1 < (int)(uVar18 - uVar16)) {
      iVar13 = (uVar18 - (ushort)param_1[0xd]) - uVar16;
      goto LAB_140028450;
    }
  }
  else {
    iVar13 = uVar16 - uVar18;
    if ((iVar13 < 1) || (-1 < (int)((uVar16 - DAT_14007f164) - uVar18))) {
      if ((int)(uVar18 - uVar16) < 0) {
        *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
        crashdump_tcp4_output(param_1);
        uVar18 = DAT_14007f124;
      }
    }
    else {
      if (DAT_14007f130 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("inseg.p != NULL");
      }
      plVar12 = DAT_14007f130;
      if ((int)(uint)*(ushort *)((longlong)DAT_14007f130 + 0x12) < iVar13) {
        lVar2 = DAT_14007f130[2];
        uVar7 = *(ushort *)((longlong)DAT_14007f130 + 0x12);
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
      _DAT_14007f138 = plVar12[1];
      DAT_14007f140 = DAT_14007f140 + ((short)DAT_14007f124 - (short)param_1[0xc]);
      uVar18 = param_1[0xc];
      DAT_14007f124 = uVar18;
      *(uint *)(DAT_14007f148 + 4) = uVar18;
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
            puVar4 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_14007f128);
LAB_140028287:
            *(undefined8 **)(param_1 + 0x24) = puVar4;
            return 0;
          }
          plVar12 = (longlong *)0x0;
          plVar14 = *(longlong **)(param_1 + 0x24);
          do {
            uVar18 = *(uint *)(plVar14[4] + 4);
            if (DAT_14007f124 == uVar18) {
              if (DAT_14007f140 <= *(ushort *)(plVar14 + 3)) {
                return 0;
              }
              plVar5 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_14007f128);
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
              if ((int)(DAT_14007f124 - uVar18) < 0) {
                if (0 < (int)((DAT_14007f140 - uVar18) + DAT_14007f124)) {
                  DAT_14007f140 = (short)uVar18 - (short)DAT_14007f124;
                  pbuf_realloc(DAT_14007f130,DAT_14007f140);
                }
                puVar4 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_14007f128);
                if (puVar4 == (undefined8 *)0x0) {
                  return 0;
                }
                *puVar4 = plVar14;
                goto LAB_140028287;
              }
            }
            else if ((0 < (int)(DAT_14007f124 - *(int *)(plVar12[4] + 4))) &&
                    ((int)((DAT_14007f124 - uVar18) + 1) < 1)) {
              if (0 < (int)((DAT_14007f140 - uVar18) + DAT_14007f124)) {
                DAT_14007f140 = (short)uVar18 - (short)DAT_14007f124;
                pbuf_realloc(DAT_14007f130,DAT_14007f140);
              }
              puVar4 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_14007f128);
              uVar18 = DAT_14007f124;
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
              goto LAB_1400283b1;
            }
            plVar5 = (longlong *)*plVar14;
            if ((plVar5 == (longlong *)0x0) && (0 < (int)(DAT_14007f124 - uVar18))) {
              puVar4 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_14007f128);
              *plVar14 = (longlong)puVar4;
              if (puVar4 == (undefined8 *)0x0) {
                return 0;
              }
              if ((int)((*(ushort *)(plVar14 + 3) - DAT_14007f124) + *(int *)(plVar14[4] + 4)) < 1)
              {
                return 0;
              }
              uVar7 = (short)DAT_14007f124 - *(short *)(plVar14[4] + 4);
              *(ushort *)(plVar14 + 3) = uVar7;
              puVar4 = (undefined8 *)plVar14[1];
LAB_1400283b1:
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
           (int)((*(int *)(lVar2 + 4) - (uint)DAT_14007f140) - uVar18) < 1)) {
          DAT_14007f140 = *(short *)(lVar2 + 4) - (short)uVar18;
          pbuf_realloc(DAT_14007f130,DAT_14007f140);
          uVar7 = (ushort)param_1[0xd];
        }
        uVar6 = *(ushort *)(DAT_14007f148 + 0xc) >> 8;
        if (((uVar6 & 1) == 0) && ((uVar6 & 2) == 0)) {
          sVar9 = 0;
        }
        else {
          sVar9 = 1;
        }
        uVar6 = sVar9 + DAT_14007f140;
        DAT_14007f164 = uVar6;
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
        if ((short)DAT_14007f130[2] != 0) {
          DAT_14007f168 = DAT_14007f130;
          DAT_14007f130 = (longlong *)0x0;
        }
        puVar4 = *(undefined8 **)(param_1 + 0x24);
        if ((*(ushort *)(DAT_14007f148 + 0xc) >> 8 & 1) != 0) {
          DAT_14007f166 = 0x20;
        }
        if (puVar4 != (undefined8 *)0x0) {
          do {
            plVar12 = DAT_14007f168;
            uVar18 = *(uint *)(puVar4[4] + 4);
            if (uVar18 != param_1[0xc]) break;
            uVar7 = *(ushort *)(puVar4[4] + 0xc) >> 8;
            if (((uVar7 & 1) != 0) || (iVar13 = 0, (uVar7 & 2) != 0)) {
              iVar13 = 1;
            }
            DAT_14007f124 = uVar18;
            param_1[0xc] = (uint)*(ushort *)(puVar4 + 3) + param_1[0xc] + iVar13;
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
              sVar9 = ((ushort)param_1[0xd] - *(ushort *)(puVar4 + 3)) - sVar9;
            }
            *(short *)(param_1 + 0xd) = sVar9;
            plVar14 = (longlong *)puVar4[1];
            if ((short)plVar14[2] != 0) {
              if (plVar12 == (longlong *)0x0) {
                DAT_14007f168 = plVar14;
              }
              else {
                pbuf_cat(plVar12,(longlong)plVar14);
              }
              puVar4[1] = 0;
            }
            if (((*(ushort *)(puVar4[4] + 0xc) >> 8 & 1) != 0) &&
               (DAT_14007f166 = 0x20, param_1[6] == 4)) {
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
        goto LAB_140028456;
      }
LAB_140028450:
      if (iVar13 + 1 < 1) {
        return 0;
      }
    }
  }
  *(byte *)(param_1 + 0xb) = (byte)param_1[0xb] | 2;
LAB_140028456:
  crashdump_tcp4_output(param_1);
  return uVar11;
}



===== tcp_recv_null @ 140028480 =====

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



===== tcp_rexmit @ 1400284ac =====

void tcp_rexmit(uint *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0x22);
  if (puVar2 != (undefined8 *)0x0) {
    uVar3 = *puVar2;
    *puVar2 = *(undefined8 *)(param_1 + 0x20);
    lVar4 = *(longlong *)(param_1 + 0x22);
    *(longlong *)(param_1 + 0x20) = lVar4;
    *(undefined8 *)(param_1 + 0x22) = uVar3;
    uVar1 = *(uint *)(*(longlong *)(lVar4 + 0x20) + 4);
    *(char *)((longlong)param_1 + 0x52) = *(char *)((longlong)param_1 + 0x52) + '\x01';
    param_1[0x11] = 0;
    param_1[0x18] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    crashdump_tcp4_output(param_1);
  }
  return;
}



===== tcp_rexmit_rto @ 140028504 =====

void tcp_rexmit_rto(uint *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0x22);
  if (puVar2 != (undefined8 *)0x0) {
    for (puVar4 = (undefined8 *)*puVar2; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)*puVar4
        ) {
      puVar2 = puVar4;
    }
    *puVar2 = *(undefined8 *)(param_1 + 0x20);
    lVar3 = *(longlong *)(param_1 + 0x22);
    param_1[0x22] = 0;
    param_1[0x23] = 0;
    *(longlong *)(param_1 + 0x20) = lVar3;
    uVar1 = *(uint *)(*(longlong *)(lVar3 + 0x20) + 4);
    *(char *)((longlong)param_1 + 0x52) = *(char *)((longlong)param_1 + 0x52) + '\x01';
    param_1[0x11] = 0;
    param_1[0x18] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    crashdump_tcp4_output(param_1);
  }
  return;
}



===== tcp_rst @ 140028570 =====

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



===== crashdump_ip6_tcp_seg_copy @ 14002868c =====

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



===== crashdump_ip6_tcp_seg_free @ 1400286dc =====

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



===== tcp_segs_free @ 14002871c =====

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



===== tcp_slowtmr @ 140028750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

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
  
  tcp_ticks = tcp_ticks + 1;
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
        if ((uint)(tcp_ticks - *(int *)(lVar11 + 0x38)) < 0xf1) {
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
      if ((uVar5 == 6) && (0x28 < tcp_ticks - puVar10[0xe])) {
        cVar7 = cVar7 + '\x01';
      }
    }
    if (((puVar10[2] & 8) != 0) && ((uVar5 == 4 || (uVar5 == 7)))) {
      if ((puVar10[0x32] + 0xa4cb8) / 500 < tcp_ticks - puVar10[0xe]) {
        tcp_abort(puVar10);
      }
      else if (((uint)(byte)puVar10[0x33] * 75000 + puVar10[0x32]) / 500 < tcp_ticks - puVar10[0xe])
      {
        tcp_keepalive(puVar10);
        *(char *)(puVar10 + 0x33) = (char)puVar10[0x33] + '\x01';
      }
    }
    if ((*(undefined8 **)(puVar10 + 0x24) != (undefined8 *)0x0) &&
       ((uint)(ushort)puVar10[0x14] * 6 <= tcp_ticks - puVar10[0xe])) {
      tcp_segs_free(*(undefined8 **)(puVar10 + 0x24));
      puVar10[0x24] = 0;
      puVar10[0x25] = 0;
    }
    if (puVar10[6] == 3) {
      if (0x28 < tcp_ticks - puVar10[0xe]) {
        cVar7 = cVar7 + '\x01';
        goto LAB_140028937;
      }
    }
    else {
LAB_140028937:
      if ((puVar10[6] == 9) && (0xf0 < tcp_ticks - puVar10[0xe])) {
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



===== tcp_tmr @ 140028ae0 =====

void tcp_tmr(void)

{
  tcp_fasttmr();
  DAT_14007f122 = DAT_14007f122 + 1;
  if ((DAT_14007f122 & 1) != 0) {
    tcp_slowtmr();
  }
  return;
}



===== tcp_write @ 140028b08 =====

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



===== update_arp_entry @ 140028b4c =====

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
  byte bVar8;
  undefined1 *puVar10;
  undefined1 *puVar9;
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
  (&DAT_140080e74)[(longlong)puVar4 * 10] = 2;
  (&DAT_140080e80)[(longlong)puVar4 * 5] = param_1;
  uVar3 = (ulonglong)*(byte *)(param_1 + 0x30);
  puVar5 = puVar4;
  if (*(byte *)(param_1 + 0x30) != 0) {
    puVar5 = &DAT_140080e6c + (longlong)puVar4 * 0x28;
    puVar7 = puVar5 + uVar3;
    lVar11 = param_3 - (longlong)puVar5;
    do {
      puVar7 = puVar7 + -1;
      puVar5 = (undefined *)CONCAT71((int7)((ulonglong)puVar5 >> 8),puVar7[lVar11]);
      *puVar7 = puVar7[lVar11];
      bVar8 = (char)uVar3 - 1;
      uVar3 = (ulonglong)bVar8;
    } while (bVar8 != 0);
  }
  (&DAT_140080e78)[(longlong)puVar4 * 0x28] = 0;
  while (puVar2 = (undefined8 *)(&DAT_140080e60)[(longlong)puVar4 * 5], puVar2 != (undefined8 *)0x0)
  {
    lVar11 = puVar2[1];
    uVar6 = pbuf_dequeue(puVar2);
    (&DAT_140080e60)[(longlong)puVar4 * 5] = uVar6;
    uVar3 = (ulonglong)*(byte *)(param_1 + 0x30);
    if (*(byte *)(param_1 + 0x30) != 0) {
      puVar10 = (undefined1 *)(uVar3 + lVar11);
      do {
        puVar9 = puVar10 + -1;
        *puVar9 = puVar9[param_3 - lVar11];
        puVar10[5] = puVar9[(param_1 - lVar11) + 0x31];
        bVar8 = (char)uVar3 - 1;
        uVar3 = (ulonglong)bVar8;
        puVar10 = puVar9;
      } while (bVar8 != 0);
    }
    *(undefined2 *)(lVar11 + 0xc) = 8;
    (**(code **)(param_1 + 0x20))(param_1,puVar2);
    pbuf_free(puVar2);
    puVar5 = (undefined *)((ulonglong)extraout_var << 8);
  }
  return (ulonglong)puVar5 & 0xffffffffffffff00;
}



===== chksum @ 140028ca4 =====

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



===== crashdump_icmp6_input @ 140028d38 =====

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
    if (cVar1 == -0x7a) goto LAB_140028de5;
    if (cVar1 == -0x79) {
      uVar5 = icmp_handle_nd_sol((longlong)param_1,param_2);
      local_res8 = (int)uVar5;
    }
    else {
      if (cVar1 != -0x78) goto LAB_140028de5;
      uVar4 = pbuf_header((longlong)param_1,0x28);
      if ((char)uVar4 == '\0') {
        lVar2 = param_1[1];
        uVar4 = pbuf_header((longlong)param_1,0xe);
        if ((char)uVar4 != '\0') goto LAB_140028de5;
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
LAB_140028de5:
  pbuf_free(param_1);
  return;
}



===== crashdump_ip6_inet_chksum_pseudo @ 140028e00 =====

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



===== crashdump_ip6_input @ 140028eb0 =====

void crashdump_ip6_input(undefined8 *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  u_short uVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  
  pbVar1 = (byte *)param_1[1];
  if ((((*pbVar1 & 0xf0) == 0x60) && (pbVar1[0x18] != 0xff)) &&
     (plVar3 = DAT_140081000, DAT_140081000 != (longlong *)0x0)) {
    do {
      for (puVar4 = (undefined8 *)plVar3[0x18]; puVar4 != (undefined8 *)0x0;
          puVar4 = (undefined8 *)*puVar4) {
        if ((puVar4[1] == *(longlong *)(pbVar1 + 0x18)) &&
           (puVar4[2] == *(longlong *)(pbVar1 + 0x20))) goto LAB_140028f10;
      }
      plVar3 = (longlong *)*plVar3;
    } while (plVar3 != (longlong *)0x0);
LAB_140028f10:
    if (plVar3 != (longlong *)0x0) {
      uVar2 = ntohs(*(u_short *)(pbVar1 + 4));
      pbuf_realloc(param_1,uVar2 + 0x28);
      if (pbVar1[6] == 6) {
        crashdump_tcp6_input(param_1,param_2,param_3,param_4);
        return;
      }
      if (pbVar1[6] == 0x3a) {
        crashdump_icmp6_input(param_1,param_2);
        return;
      }
    }
  }
  pbuf_free(param_1);
  return;
}



===== crashdump_ip6_output @ 140028f64 =====

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



===== crashdump_ip6_output_if @ 140028fc4 =====

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
    uVar5 = (**(code **)(param_6 + 0x18))(param_6,param_1,param_3);
  }
  else {
    uVar5 = CONCAT71((int7)(uVar3 >> 8),0xfe);
  }
  return uVar5;
}



===== crashdump_ip6_route @ 1400290c0 =====

undefined8 * crashdump_ip6_route(uint *param_1)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  
  puVar2 = DAT_140081000;
  while( true ) {
    if (puVar2 == (undefined8 *)0x0) {
      return DAT_140081008;
    }
    uVar1 = ip_addr_netcmp(param_1,(uint *)(puVar2 + 0x24),(uint *)(puVar2 + 0x26));
    if ((char)uVar1 != '\0') break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return puVar2;
}



===== crashdump_ip6_tcp_abort @ 140029110 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void crashdump_ip6_tcp_abort(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  u_short uVar1;
  u_short uVar2;
  u_long uVar3;
  u_long uVar4;
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



===== crashdump_ip6_tcp_alloc @ 140029234 =====

undefined8 * crashdump_ip6_tcp_alloc(byte param_1)

{
  byte bVar1;
  uint uVar2;
  undefined8 *_Dst;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  
  _Dst = memp_malloc(3);
  if (_Dst == (undefined8 *)0x0) {
    uVar6 = 0;
    piVar3 = (int *)0x0;
    piVar5 = (int *)0x0;
    piVar4 = tcp_tw_pcbs;
    if (tcp_tw_pcbs != (int *)0x0) {
      do {
        uVar7 = uVar6;
        uVar2 = tcp_ticks - piVar4[0x14];
        if ((uint)uVar7 <= uVar2) {
          piVar3 = piVar4;
        }
        piVar5 = *(int **)(piVar4 + 10);
        uVar6 = (ulonglong)uVar2;
        if (uVar2 < (uint)uVar7) {
          uVar6 = uVar7;
        }
        piVar4 = piVar5;
      } while (piVar5 != (int *)0x0);
      if (piVar3 != (int *)0x0) {
        crashdump_ip6_tcp_abort(piVar3,uVar7,0,uVar6);
      }
    }
    _Dst = memp_malloc(3);
    if (_Dst == (undefined8 *)0x0) {
      uVar8 = CONCAT71((int7)(uVar6 >> 8),0x7f);
      uVar2 = 0;
      piVar4 = (int *)0x0;
      piVar3 = tcp_active_pcbs;
      if (tcp_active_pcbs != (int *)0x0) {
        do {
          bVar1 = *(byte *)(piVar3 + 0xd);
          piVar5 = (int *)CONCAT71((int7)((ulonglong)piVar5 >> 8),bVar1);
          if (((bVar1 <= param_1) && (bVar1 <= (byte)uVar8)) &&
             (uVar2 <= (uint)(tcp_ticks - piVar3[0x14]))) {
            uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),bVar1);
            piVar4 = piVar3;
            uVar2 = tcp_ticks - piVar3[0x14];
          }
          piVar3 = *(int **)(piVar3 + 10);
        } while (piVar3 != (int *)0x0);
        if (piVar4 != (int *)0x0) {
          crashdump_ip6_tcp_abort(piVar4,piVar4,piVar5,uVar8);
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
  DAT_14003a74c = DAT_14003a74c + tcp_ticks;
  *(int *)(_Dst + 0x11) = DAT_14003a74c;
  *(int *)(_Dst + 0xf) = DAT_14003a74c;
  *(int *)((longlong)_Dst + 0x7c) = DAT_14003a74c;
  *(int *)((longlong)_Dst + 0x6c) = DAT_14003a74c;
  *(int *)((longlong)_Dst + 0x8c) = DAT_14003a74c;
  *(int *)(_Dst + 10) = tcp_ticks;
  _Dst[0x17] = tcp_recv_null;
  *(undefined1 *)((longlong)_Dst + 0x54) = 0;
  *(undefined4 *)(_Dst + 0x1c) = 7200000;
  *(undefined1 *)((longlong)_Dst + 0xe4) = 0;
  return _Dst;
}



===== crashdump_ip6_tcp_connect @ 1400293c4 =====

ulonglong crashdump_ip6_tcp_connect
                    (int *param_1,uint *param_2,undefined2 param_3,undefined8 param_4)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined8 in_RAX;
  undefined8 *puVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  undefined7 uVar10;
  u_long local_res10 [2];
  
  uVar10 = (undefined7)((ulonglong)param_4 >> 8);
  if (param_2 == (uint *)0x0) {
    uVar6 = CONCAT71((int7)((ulonglong)in_RAX >> 8),0xf9);
  }
  else {
    uVar5 = *(undefined8 *)param_2;
    uVar7 = *(undefined8 *)(param_2 + 2);
    *(undefined2 *)((longlong)param_1 + 0x42) = param_3;
    *(undefined8 *)(param_1 + 4) = uVar5;
    *(undefined8 *)(param_1 + 6) = uVar7;
    if ((short)param_1[0x10] == 0) {
      uVar2 = tcp_new_port();
      *(undefined2 *)(param_1 + 0x10) = uVar2;
    }
    iVar3 = tcp_ticks + DAT_14003a74c;
    DAT_14003a74c = iVar3;
    param_1[0x1e] = iVar3;
    param_1[0x1b] = iVar3 + -1;
    param_1[0x23] = iVar3 + -1;
    *(undefined2 *)(param_1 + 0x13) = 0xffff;
    param_1[0x20] = 0xffff;
    *(undefined2 *)(param_1 + 0x16) = 0x5a0;
    param_1[0x12] = 0;
    puVar4 = ip_find_src_addr(param_2);
    uVar5 = *puVar4;
    uVar7 = puVar4[1];
    *(undefined4 *)((longlong)param_1 + 0x72) = 0x38400001;
    param_1[0xc] = 2;
    *(undefined8 *)param_1 = uVar5;
    *(undefined8 *)(param_1 + 2) = uVar7;
    *(undefined8 *)(param_1 + 0x30) = param_4;
    *(int **)(param_1 + 10) = tcp_active_pcbs;
    tcp_active_pcbs = param_1;
    local_res10[0] = htonl(*(ushort *)(param_1 + 0x16) | 0x2040000);
    uVar8 = 0;
    uVar9 = 2;
    uVar7 = 0;
    uVar5 = crashdump_ip6_tcp_enqueue((longlong)param_1,(void *)0x0,0,2,'\0',local_res10,4);
    cVar1 = (char)uVar5;
    if (cVar1 == '\0') {
      uVar5 = crashdump_tcp6_output(param_1,uVar7,uVar8,CONCAT71(uVar10,uVar9));
    }
    uVar6 = CONCAT71((int7)((ulonglong)uVar5 >> 8),cVar1);
  }
  return uVar6;
}



===== crashdump_ip6_tcp_enqueue @ 1400294d0 =====

undefined8
crashdump_ip6_tcp_enqueue
          (longlong param_1,void *param_2,ushort param_3,byte param_4,char param_5,void *param_6,
          byte param_7)

{
  u_short uVar1;
  ushort uVar2;
  u_long uVar3;
  ulonglong in_RAX;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined6 extraout_var_01;
  ulonglong uVar7;
  uint7 extraout_var;
  uint7 extraout_var_00;
  char *pcVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  undefined8 *puVar12;
  ulonglong _Size;
  undefined8 *local_res8;
  u_long local_res18;
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
    bVar9 = *(byte *)(param_1 + 0x94);
    uVar10 = (uint)param_3;
    local_res18 = *(uint *)(param_1 + 0x8c);
    in_RAX = (ulonglong)local_res18;
    if (bVar9 < 0xb3) {
      if (bVar9 == 0) {
        if ((*(longlong *)(param_1 + 0xa0) != 0) || (*(longlong *)(param_1 + 0x98) != 0)) {
          pcVar8 = "tcp_enqueue: no pbufs on queue => both queues empty";
          goto LAB_14002959f;
        }
      }
      else if ((*(longlong *)(param_1 + 0xa0) == 0) && (*(longlong *)(param_1 + 0x98) == 0)) {
        pcVar8 = "tcp_enqueue: pbufs on queue => at least one queue non-empty";
LAB_14002959f:
                    /* WARNING: Subroutine does not return */
        DbgPrint(pcVar8);
      }
      local_res8 = (undefined8 *)0x0;
      puVar12 = (undefined8 *)0x0;
      local_58 = param_2;
LAB_1400295b3:
      if ((puVar12 != (undefined8 *)0x0) && (uVar10 == 0)) {
        puVar4 = *(undefined8 **)(param_1 + 0x98);
        iVar11 = 0;
        if (puVar4 == (undefined8 *)0x0) {
          *(undefined8 **)(param_1 + 0x98) = puVar12;
        }
        else {
          for (puVar5 = (undefined8 *)*puVar4; puVar5 != (undefined8 *)0x0;
              puVar5 = (undefined8 *)*puVar5) {
            puVar4 = puVar5;
          }
          uVar1 = ntohs(*(u_short *)(puVar4[4] + 0xc));
          if (((uVar1 & 1) != 0) || (uVar1 = ntohs(*(u_short *)(puVar4[4] + 0xc)), (uVar1 & 2) != 0)
             ) {
            iVar11 = 1;
          }
          if (((((uint)*(ushort *)(puVar4 + 3) + iVar11 == 0) ||
               (uVar1 = ntohs(*(u_short *)(puVar4[4] + 0xc)), (uVar1 & 3) != 0)) ||
              ((param_4 & 3) != 0)) ||
             ((uint)*(ushort *)(param_1 + 0x58) <
              (uint)*(ushort *)(puVar4 + 3) + (uint)*(ushort *)(puVar12 + 3))) {
            *puVar4 = puVar12;
          }
          else {
            pbuf_header(puVar12[1],-0x14);
            pbuf_cat((longlong *)puVar4[1],puVar12[1]);
            *(short *)(puVar4 + 3) = *(short *)(puVar4 + 3) + *(short *)(puVar12 + 3);
            *puVar4 = *puVar12;
            memp_free(5,(longlong)puVar12);
            puVar4 = (undefined8 *)0x0;
            if (local_res8 != puVar12) {
              puVar4 = local_res8;
            }
            local_res8 = puVar4;
          }
        }
        *(byte *)(param_1 + 0x94) = bVar9;
        uVar2 = param_3 + 1;
        if ((param_4 & 3) == 0) {
          uVar2 = param_3;
        }
        uVar7 = (ulonglong)uVar2;
        *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + (uint)uVar2;
        *(short *)(param_1 + 0x92) = *(short *)(param_1 + 0x92) - uVar2;
        if (((bVar9 != 0) && (*(longlong *)(param_1 + 0xa0) == 0)) &&
           (*(longlong *)(param_1 + 0x98) == 0)) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_enqueue: valid queue length");
        }
        if ((local_res8 != (undefined8 *)0x0) && ((short)_Size != 0)) {
          uVar7 = 0;
          if (local_res8[4] != 0) {
            uVar1 = ntohs(*(u_short *)(local_res8[4] + 0xc));
            uVar1 = ntohs(uVar1 | 8);
            uVar7 = CONCAT62(extraout_var_01,uVar1);
            *(u_short *)(local_res8[4] + 0xc) = uVar1;
          }
        }
        return uVar7 & 0xffffffffffffff00;
      }
      uVar2 = *(ushort *)(param_1 + 0x58);
      if (uVar10 <= *(ushort *)(param_1 + 0x58)) {
        uVar2 = (ushort)uVar10;
      }
      _Size = (ulonglong)uVar2;
      puVar4 = memp_malloc(5);
      in_RAX = 0;
      if (puVar4 == (undefined8 *)0x0) goto LAB_1400299b8;
      *puVar4 = 0;
      puVar4[1] = 0;
      if (puVar12 == (undefined8 *)0x0) {
        puVar12 = puVar4;
      }
      else {
        if (local_res8 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("useg != NULL");
        }
        *local_res8 = puVar4;
      }
      if (param_6 == (void *)0x0) {
        if (param_5 != '\0') {
          puVar5 = pbuf_alloc(0,uVar2,0);
          puVar4[1] = puVar5;
          in_RAX = 0;
          if (puVar5 != (undefined8 *)0x0) {
            if (param_2 != (void *)0x0) {
              memmove((void *)puVar5[1],local_58,_Size);
              puVar5 = (undefined8 *)puVar4[1];
            }
            goto LAB_14002969f;
          }
          goto LAB_1400299b8;
        }
        puVar5 = pbuf_alloc(0,uVar2,1);
        in_RAX = 0;
        if (puVar5 == (undefined8 *)0x0) goto LAB_1400299b8;
        puVar5[1] = local_58;
        puVar4[2] = local_58;
        plVar6 = pbuf_alloc(0,0,0);
        puVar4[1] = plVar6;
        if (plVar6 == (longlong *)0x0) {
          pbuf_free(puVar5);
          in_RAX = (ulonglong)extraout_var << 8;
LAB_1400299b8:
          if (puVar12 != (undefined8 *)0x0) {
            tcp_segs_free(puVar12);
            in_RAX = (ulonglong)extraout_var_00 << 8;
          }
          if (((*(char *)(param_1 + 0x94) != '\0') && (*(longlong *)(param_1 + 0xa0) == 0)) &&
             (*(longlong *)(param_1 + 0x98) == 0)) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_enqueue: valid queue length");
          }
          goto LAB_1400299ee;
        }
        bVar9 = bVar9 + 2;
        in_RAX = pbuf_cat(plVar6,(longlong)puVar5);
      }
      else {
        puVar5 = pbuf_alloc(0,(ushort)param_7,0);
        puVar4[1] = puVar5;
        in_RAX = 0;
        if (puVar5 == (undefined8 *)0x0) goto LAB_1400299b8;
LAB_14002969f:
        bVar9 = bVar9 + 1;
        in_RAX = puVar5[1];
        puVar4[2] = in_RAX;
      }
      if (0xb3 < bVar9) goto LAB_1400299b8;
      *(ushort *)(puVar4 + 3) = uVar2;
      in_RAX = pbuf_header(puVar4[1],0x14);
      if ((char)in_RAX != '\0') goto LAB_1400299b8;
      puVar4[4] = *(undefined8 *)(puVar4[1] + 8);
      uVar1 = ntohs(*(u_short *)(param_1 + 0x40));
      *(u_short *)puVar4[4] = uVar1;
      uVar1 = ntohs(*(u_short *)(param_1 + 0x42));
      *(u_short *)(puVar4[4] + 2) = uVar1;
      uVar3 = htonl(local_res18);
      *(u_long *)(puVar4[4] + 4) = uVar3;
      *(undefined2 *)(puVar4[4] + 0x12) = 0;
      uVar1 = ntohs(*(u_short *)(puVar4[4] + 0xc));
      uVar1 = ntohs(uVar1 & 0xffc0 | (ushort)param_4);
      *(u_short *)(puVar4[4] + 0xc) = uVar1;
      if (param_6 == (void *)0x0) {
        uVar1 = ntohs(*(u_short *)(puVar4[4] + 0xc));
        uVar1 = ntohs(uVar1 & 0x3f | 0x5000);
        *(u_short *)(puVar4[4] + 0xc) = uVar1;
      }
      else {
        uVar1 = ntohs(*(u_short *)(puVar4[4] + 0xc));
        uVar1 = ntohs(uVar1 & 0x3f | ((param_7 & 0xfffc) + 0x14) * 0x400);
        *(u_short *)(puVar4[4] + 0xc) = uVar1;
        memmove((void *)puVar4[2],param_6,(ulonglong)param_7);
      }
      local_res18 = local_res18 + uVar2;
      uVar10 = uVar10 - uVar2;
      local_58 = (void *)((longlong)local_58 + _Size);
      local_res8 = puVar4;
      goto LAB_1400295b3;
    }
  }
LAB_1400299ee:
  return CONCAT71((int7)(in_RAX >> 8),0xff);
}



===== crashdump_ip6_tcp_fasttmr @ 140029a04 =====

void crashdump_ip6_tcp_fasttmr
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  
  for (piVar1 = tcp_active_pcbs; piVar1 != (int *)0x0; piVar1 = *(int **)(piVar1 + 10)) {
    if ((*(byte *)(piVar1 + 0x11) & 1) != 0) {
      *(byte *)(piVar1 + 0x11) = *(byte *)(piVar1 + 0x11) | 2;
      crashdump_tcp6_output(piVar1,param_2,param_3,param_4);
      *(byte *)(piVar1 + 0x11) = *(byte *)(piVar1 + 0x11) & 0xfc;
    }
  }
  return;
}



===== crashdump_ip6_tcp_keepalive @ 140029a3c =====

void crashdump_ip6_tcp_keepalive
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  u_short *puVar1;
  u_short uVar2;
  u_long uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined7 uVar6;
  undefined4 in_stack_ffffffffffffffec;
  
  uVar6 = (undefined7)((ulonglong)param_4 >> 8);
  puVar5 = pbuf_alloc(1,0x14,0);
  if (puVar5 != (undefined8 *)0x0) {
    puVar1 = (u_short *)puVar5[1];
    uVar2 = ntohs(*(u_short *)(param_1 + 8));
    *puVar1 = uVar2;
    uVar2 = ntohs(*(u_short *)((longlong)param_1 + 0x42));
    puVar1[1] = uVar2;
    uVar3 = htonl(*(int *)(param_1 + 0xf) - 1);
    *(u_long *)(puVar1 + 2) = uVar3;
    uVar3 = htonl(*(u_long *)(param_1 + 9));
    *(u_long *)(puVar1 + 4) = uVar3;
    uVar2 = ntohs(*(u_short *)((longlong)param_1 + 0x4c));
    puVar1[7] = uVar2;
    puVar1[9] = 0;
    uVar2 = ntohs(puVar1[6]);
    uVar2 = ntohs(uVar2 & 0x3f | 0x5000);
    puVar1[6] = uVar2;
    puVar1[8] = 0;
    uVar4 = (uint)*(ushort *)(puVar5 + 2);
    uVar2 = crashdump_ip6_inet_chksum_pseudo
                      (puVar5,(longlong)param_1,(u_short *)(param_1 + 2),6,uVar4);
    puVar1[8] = uVar2;
    crashdump_ip6_output
              ((longlong)puVar5,param_1,(uint *)(param_1 + 2),
               CONCAT71(uVar6,*(undefined1 *)((longlong)param_1 + 0x23)),
               CONCAT44(in_stack_ffffffffffffffec,uVar4) & 0xffffffffffffff00,6);
    pbuf_free(puVar5);
  }
  return;
}



===== crashdump_ip6_tcp_pcb_purge @ 140029b40 =====

void crashdump_ip6_tcp_pcb_purge(longlong param_1)

{
  if ((1 < *(uint *)(param_1 + 0x30)) && (*(uint *)(param_1 + 0x30) != 10)) {
    tcp_segs_free(*(undefined8 **)(param_1 + 0xa8));
    *(undefined8 *)(param_1 + 0xa8) = 0;
    tcp_segs_free(*(undefined8 **)(param_1 + 0x98));
    tcp_segs_free(*(undefined8 **)(param_1 + 0xa0));
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  return;
}



===== crashdump_ip6_tcp_pcb_remove @ 140029b98 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crashdump_ip6_tcp_pcb_remove
               (longlong *param_1,int *param_2,undefined8 param_3,undefined8 param_4)

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



===== crashdump_ip6_tcp_pcbs_sane @ 140029c3c =====

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



===== crashdump_ip6_tcp_rexmit @ 140029cd0 =====

void crashdump_ip6_tcp_rexmit(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  u_long uVar3;
  undefined8 uVar4;
  
  puVar1 = *(undefined8 **)(param_1 + 0x28);
  if (puVar1 != (undefined8 *)0x0) {
    uVar4 = *puVar1;
    *puVar1 = *(undefined8 *)(param_1 + 0x26);
    lVar2 = *(longlong *)(param_1 + 0x28);
    *(longlong *)(param_1 + 0x26) = lVar2;
    *(undefined8 *)(param_1 + 0x28) = uVar4;
    uVar3 = htonl(*(u_long *)(*(longlong *)(lVar2 + 0x20) + 4));
    *(char *)((longlong)param_1 + 0x6a) = *(char *)((longlong)param_1 + 0x6a) + '\x01';
    param_1[0x17] = 0;
    param_1[0x1e] = uVar3;
    crashdump_tcp6_output(param_1,uVar4,param_3,param_4);
  }
  return;
}



===== crashdump_ip6_tcp_rexmit_rto @ 140029d2c =====

void crashdump_ip6_tcp_rexmit_rto
               (int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  u_long uVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x28);
  if (puVar4 != (undefined8 *)0x0) {
    for (puVar2 = (undefined8 *)*puVar4; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)*puVar2
        ) {
      puVar4 = puVar2;
    }
    *puVar4 = *(undefined8 *)(param_1 + 0x26);
    lVar1 = *(longlong *)(param_1 + 0x28);
    param_1[0x28] = 0;
    param_1[0x29] = 0;
    *(longlong *)(param_1 + 0x26) = lVar1;
    uVar3 = htonl(*(u_long *)(*(longlong *)(lVar1 + 0x20) + 4));
    *(char *)((longlong)param_1 + 0x6a) = *(char *)((longlong)param_1 + 0x6a) + '\x01';
    param_1[0x17] = 0;
    param_1[0x1e] = uVar3;
    crashdump_tcp6_output(param_1,puVar4,param_3,param_4);
  }
  return;
}



===== crashdump_ip6_tcp_rst @ 140029d9c =====

void crashdump_ip6_tcp_rst
               (u_long param_1,u_long param_2,undefined8 *param_3,uint *param_4,u_short param_5,
               u_short param_6)

{
  u_short *puVar1;
  u_short uVar2;
  u_long uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined7 uVar6;
  undefined4 in_stack_ffffffffffffffcc;
  
  uVar6 = (undefined7)((ulonglong)param_4 >> 8);
  puVar5 = pbuf_alloc(1,0x14,0);
  if (puVar5 != (undefined8 *)0x0) {
    puVar1 = (u_short *)puVar5[1];
    uVar2 = ntohs(param_5);
    *puVar1 = uVar2;
    uVar2 = ntohs(param_6);
    puVar1[1] = uVar2;
    uVar3 = htonl(param_1);
    *(u_long *)(puVar1 + 2) = uVar3;
    uVar3 = htonl(param_2);
    *(u_long *)(puVar1 + 4) = uVar3;
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
    uVar4 = (uint)*(ushort *)(puVar5 + 2);
    uVar2 = crashdump_ip6_inet_chksum_pseudo(puVar5,(longlong)param_3,(u_short *)param_4,6,uVar4);
    puVar1[8] = uVar2;
    crashdump_ip6_output
              ((longlong)puVar5,param_3,param_4,CONCAT71(uVar6,0x40),
               CONCAT44(in_stack_ffffffffffffffcc,uVar4) & 0xffffffffffffff00,6);
    pbuf_free(puVar5);
  }
  return;
}



===== crashdump_ip6_tcp_slowtmr @ 140029ed4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void crashdump_ip6_tcp_slowtmr(undefined8 param_1,int *param_2,ulonglong param_3,ulonglong param_4)

{
  int *piVar1;
  longlong lVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  int *piVar8;
  char cVar9;
  int *piVar10;
  longlong lVar11;
  longlong lVar12;
  uint uVar13;
  
  tcp_ticks = tcp_ticks + 1;
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
        if ((uint)(tcp_ticks - *(int *)(lVar12 + 0x50)) < 0xf1) {
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
    iVar6 = piVar8[0xc];
    if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: active pcb->state != CLOSED\n");
    }
    if (iVar6 == 1) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: active pcb->state != LISTEN\n");
    }
    if (iVar6 == 10) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_slowtmr: active pcb->state != TIME-WAIT\n");
    }
    cVar9 = '\0';
    if ((iVar6 == 2) && (*(char *)((longlong)piVar8 + 0x6a) == '\x06')) {
      cVar9 = '\x01';
    }
    else {
      param_3 = (ulonglong)*(byte *)((longlong)piVar8 + 0x6a);
      if (*(byte *)((longlong)piVar8 + 0x6a) == 0xc) {
        cVar9 = '\x01';
      }
      else {
        uVar7 = *(short *)((longlong)piVar8 + 0x56) + 1;
        param_2 = (int *)(ulonglong)uVar7;
        *(ushort *)((longlong)piVar8 + 0x56) = uVar7;
        if ((*(longlong *)(piVar8 + 0x28) != 0) && (*(ushort *)(piVar8 + 0x1a) <= uVar7)) {
          if (iVar6 != 2) {
            *(short *)(piVar8 + 0x1a) =
                 ((short)piVar8[0x19] >> 3) + *(short *)((longlong)piVar8 + 0x66) <<
                 ((&crashdump_tcp6_backoff)[param_3] & 0x1f);
          }
          uVar7 = *(ushort *)(piVar8 + 0x16);
          param_2 = (int *)(ulonglong)uVar7;
          uVar5 = (uint)*(ushort *)((longlong)piVar8 + 0x72);
          if ((uint)piVar8[0x20] <= (uint)*(ushort *)((longlong)piVar8 + 0x72)) {
            uVar5 = piVar8[0x20];
          }
          uVar4 = (ushort)(uVar5 >> 1);
          *(ushort *)(piVar8 + 0x1d) = uVar4;
          if (uVar4 < uVar7) {
            *(ushort *)(piVar8 + 0x1d) = uVar7 * 2;
          }
          *(ushort *)((longlong)piVar8 + 0x72) = uVar7;
          crashdump_ip6_tcp_rexmit_rto(piVar8,param_2,param_3,param_4);
          iVar6 = piVar8[0xc];
        }
      }
      if ((iVar6 == 6) && (0x28 < (uint)(tcp_ticks - piVar8[0x14]))) {
        cVar9 = cVar9 + '\x01';
      }
    }
    if (((*(byte *)(piVar8 + 8) & 8) != 0) && ((iVar6 == 4 || (iVar6 == 7)))) {
      uVar5 = piVar8[0x38];
      param_4 = (ulonglong)uVar5;
      uVar13 = tcp_ticks - piVar8[0x14];
      param_3 = (ulonglong)uVar13;
      param_2 = (int *)((ulonglong)(uVar5 + 0xa4cb8) / 500);
      if ((uint)param_2 < uVar13) {
        crashdump_ip6_tcp_abort(piVar8,param_2,param_3,param_4);
      }
      else {
        param_2 = (int *)((ulonglong)((uint)*(byte *)(piVar8 + 0x39) * 75000 + uVar5) / 500);
        if ((uint)param_2 < uVar13) {
          crashdump_ip6_tcp_keepalive((undefined8 *)piVar8,param_2,param_3,param_4);
          *(char *)(piVar8 + 0x39) = (char)piVar8[0x39] + '\x01';
        }
      }
    }
    if (*(undefined8 **)(piVar8 + 0x2a) != (undefined8 *)0x0) {
      param_3 = (ulonglong)(uint)(tcp_ticks - piVar8[0x14]);
      param_2 = (int *)(ulonglong)((uint)*(ushort *)(piVar8 + 0x1a) * 6);
      if ((uint)*(ushort *)(piVar8 + 0x1a) * 6 <= (uint)(tcp_ticks - piVar8[0x14])) {
        tcp_segs_free(*(undefined8 **)(piVar8 + 0x2a));
        piVar8[0x2a] = 0;
        piVar8[0x2b] = 0;
      }
    }
    if (piVar8[0xc] == 3) {
      if (0x28 < (uint)(tcp_ticks - piVar8[0x14])) {
        cVar9 = cVar9 + '\x01';
        goto LAB_14002a0be;
      }
    }
    else {
LAB_14002a0be:
      if ((piVar8[0xc] == 9) && (0xf0 < (uint)(tcp_ticks - piVar8[0x14]))) {
        cVar9 = cVar9 + '\x01';
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



===== crashdump_ip6_tcp_tmr @ 14002a260 =====

void crashdump_ip6_tcp_tmr(undefined8 param_1,int *param_2,ulonglong param_3,ulonglong param_4)

{
  crashdump_ip6_tcp_fasttmr(param_1,param_2,param_3,param_4);
  DAT_140080ffa = DAT_140080ffa + 1;
  if ((DAT_140080ffa & 1) != 0) {
    crashdump_ip6_tcp_slowtmr(param_1,param_2,param_3,param_4);
  }
  return;
}



===== crashdump_ip6_tcp_write @ 14002a288 =====

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



===== crashdump_tcp6_close @ 14002a2cc =====

char crashdump_tcp6_close(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
LAB_14002a3b7:
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
        goto LAB_14002a3b7;
      }
      crashdump_ip6_tcp_pcb_remove(&tcp_active_pcbs,param_1,param_3,param_4);
      iVar3 = 3;
    }
    cVar1 = '\0';
    memp_free(iVar3,(longlong)param_1);
  }
  return cVar1;
}



===== crashdump_tcp6_input @ 14002a3dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crashdump_tcp6_input
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
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
  ulonglong uVar16;
  undefined8 *puVar17;
  u_long local_res8 [2];
  
  DAT_140081040 = param_1[1];
  DAT_140081038 = (u_short *)(DAT_140081040 + 0x28);
  ntohs(*(u_short *)(DAT_140081040 + 0x34));
  uVar10 = pbuf_header((longlong)param_1,-0x28);
  if (((char)uVar10 != '\0') || (*(ushort *)(param_1 + 2) < 0x14)) {
LAB_14002a881:
    pbuf_free(param_1);
    return;
  }
  uVar10 = CONCAT71((int7)((ulonglong)param_4 >> 8),6);
  sVar8 = crashdump_ip6_inet_chksum_pseudo
                    (param_1,DAT_140081040 + 8,(u_short *)(DAT_140081040 + 0x18),6,
                     (uint)*(ushort *)(param_1 + 2));
  if (sVar8 != 0) goto LAB_14002a881;
  uVar9 = ntohs(DAT_140081038[6]);
  pbuf_header((longlong)param_1,(uVar9 >> 0xc) * -4);
  uVar9 = ntohs(*DAT_140081038);
  puVar6 = DAT_140081038;
  *DAT_140081038 = uVar9;
  uVar9 = ntohs(puVar6[1]);
  puVar6 = DAT_140081038;
  DAT_140081038[1] = uVar9;
  DAT_140081048 = htonl(*(u_long *)(puVar6 + 2));
  puVar6 = DAT_140081038;
  *(uint *)(DAT_140081038 + 2) = DAT_140081048;
  DAT_14008104c = htonl(*(u_long *)(puVar6 + 4));
  puVar6 = DAT_140081038;
  *(u_long *)(DAT_140081038 + 4) = DAT_14008104c;
  uVar9 = ntohs(puVar6[7]);
  puVar6 = DAT_140081038;
  DAT_140081038[7] = uVar9;
  uVar9 = ntohs(puVar6[6]);
  uVar16 = DAT_140081040;
  puVar6 = DAT_140081038;
  piVar14 = (int *)((ulonglong)uVar9 & 0xffffffffffffff3f);
  DAT_140080ffb = SUB81(piVar14,0);
  uVar13 = (ushort)((uVar9 & 3) != 0) + *(short *)(param_1 + 2);
  piVar3 = (int *)0x0;
  for (piVar15 = tcp_active_pcbs; piVar12 = tcp_tw_pcbs, DAT_140081050 = uVar13,
      piVar15 != (int *)0x0; piVar15 = *(int **)(piVar15 + 10)) {
    iVar1 = piVar15[0xc];
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_input: active pcb->state != CLOSED");
    }
    if (iVar1 == 10) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_input: active pcb->state != TIME-WAIT");
    }
    if (iVar1 == 1) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_input: active pcb->state != LISTEN");
    }
    if (((((*(u_short *)((longlong)piVar15 + 0x42) == *DAT_140081038) &&
          (*(u_short *)(piVar15 + 0x10) == DAT_140081038[1])) &&
         (*piVar15 == *(int *)(DAT_140081040 + 0x18))) &&
        ((piVar15[1] == *(int *)(DAT_140081040 + 0x1c) &&
         (piVar15[2] == *(int *)(DAT_140081040 + 0x20))))) &&
       (piVar15[3] == *(int *)(DAT_140081040 + 0x24))) {
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
      goto LAB_14002a6ec;
    }
    piVar3 = piVar15;
  }
  for (; piVar12 != (int *)0x0; piVar12 = *(int **)(piVar12 + 10)) {
    if (piVar12[0xc] != 10) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("tcp_input: TIME-WAIT pcb->state == TIME-WAIT");
    }
    if ((((*(u_short *)((longlong)piVar12 + 0x42) == *DAT_140081038) &&
         (*(u_short *)(piVar12 + 0x10) == DAT_140081038[1])) &&
        ((piVar12[4] == *(int *)(DAT_140081040 + 8) &&
         (((piVar12[5] == *(int *)(DAT_140081040 + 0xc) &&
           (piVar12[6] == *(int *)(DAT_140081040 + 0x10))) &&
          (piVar12[7] == *(int *)(DAT_140081040 + 0x14))))))) &&
       (((*piVar12 == *(int *)(DAT_140081040 + 0x18) &&
         (piVar12[1] == *(int *)(DAT_140081040 + 0x1c))) &&
        ((piVar12[2] == *(int *)(DAT_140081040 + 0x20) &&
         (piVar12[3] == *(int *)(DAT_140081040 + 0x24))))))) {
      uVar16 = (ulonglong)DAT_140081048;
      if (0 < (int)(((uint)uVar13 - piVar12[0x12]) + DAT_140081048)) {
        piVar12[0x12] = uVar13 + DAT_140081048;
      }
      if (uVar13 != 0) {
        *(byte *)(piVar12 + 0x11) = *(byte *)(piVar12 + 0x11) | 2;
        crashdump_tcp6_output(piVar12,piVar14,uVar16,uVar10);
      }
      goto LAB_14002a983;
    }
  }
  piVar15 = (int *)0x0;
  puVar4 = (uint *)0x0;
  for (puVar5 = tcp_listen_pcbs; puVar5 != (uint *)0x0; puVar5 = *(uint **)(puVar5 + 10)) {
    uVar2 = *puVar5;
    uVar10 = (ulonglong)uVar2;
    if (((((uVar2 == 0 && puVar5[1] == 0) && puVar5[2] == 0) && puVar5[3] == 0) ||
        (((uVar2 == *(uint *)(DAT_140081040 + 0x18) &&
          (puVar5[1] == *(uint *)(DAT_140081040 + 0x1c))) &&
         ((puVar5[2] == *(uint *)(DAT_140081040 + 0x20) &&
          (puVar5[3] == *(uint *)(DAT_140081040 + 0x24))))))) &&
       ((u_short)puVar5[0x10] == DAT_140081038[1])) {
      if (puVar4 != (uint *)0x0) {
        *(undefined8 *)(puVar4 + 10) = *(undefined8 *)(puVar5 + 10);
        *(uint **)(puVar5 + 10) = tcp_listen_pcbs;
        tcp_listen_pcbs = puVar5;
      }
      if ((uVar9 & 0x10) == 0) {
        if (((uVar9 & 2) != 0) &&
           (piVar12 = (int *)crashdump_ip6_tcp_alloc((byte)puVar5[0xd]), uVar16 = DAT_140081040,
           piVar12 != (int *)0x0)) {
          uVar11 = *(undefined8 *)(DAT_140081040 + 0x20);
          *(undefined8 *)piVar12 = *(undefined8 *)(DAT_140081040 + 0x18);
          *(undefined8 *)(piVar12 + 2) = uVar11;
          *(short *)(piVar12 + 0x10) = (short)puVar5[0x10];
          puVar6 = DAT_140081038;
          uVar11 = *(undefined8 *)(uVar16 + 0x10);
          *(undefined8 *)(piVar12 + 4) = *(undefined8 *)(uVar16 + 8);
          *(undefined8 *)(piVar12 + 6) = uVar11;
          *(u_short *)((longlong)piVar12 + 0x42) = *puVar6;
          uVar2 = DAT_140081048;
          piVar12[0xc] = 3;
          piVar12[0x12] = uVar2 + 1;
          uVar13 = puVar6[7];
          piVar12[0x20] = (uint)uVar13;
          *(ushort *)(piVar12 + 0x1d) = uVar13;
          piVar12[0x21] = uVar2 - 1;
          *(undefined8 *)(piVar12 + 0xe) = *(undefined8 *)(puVar5 + 0xe);
          *(undefined8 *)(piVar12 + 0x32) = *(undefined8 *)(puVar5 + 0x12);
          *(ushort *)(piVar12 + 8) = (ushort)puVar5[8] & 0x199;
          *(int **)(piVar12 + 10) = tcp_active_pcbs;
          tcp_active_pcbs = piVar12;
          tcp_parseopt((longlong)piVar12);
          local_res8[0] = htonl(*(ushort *)(piVar12 + 0x16) | 0x2040000);
          uVar16 = 0;
          uVar10 = CONCAT71((int7)(uVar10 >> 8),0x12);
          piVar14 = (int *)0x0;
          crashdump_ip6_tcp_enqueue((longlong)piVar12,(void *)0x0,0,0x12,'\0',local_res8,4);
LAB_14002a983:
          crashdump_tcp6_output(piVar12,piVar14,uVar16,uVar10);
        }
      }
      else {
        crashdump_ip6_tcp_rst
                  (DAT_14008104c + 1,DAT_140081050 + DAT_140081048,(undefined8 *)(uVar16 + 0x18),
                   (uint *)(uVar16 + 8),puVar6[1],*DAT_140081038);
      }
      goto LAB_14002a881;
    }
    puVar4 = puVar5;
  }
LAB_14002a6ec:
  ntohs(DAT_140081038[6]);
  if (piVar15 == (int *)0x0) {
    uVar9 = ntohs(DAT_140081038[6]);
    if ((uVar9 & 4) == 0) {
      crashdump_ip6_tcp_rst
                (DAT_14008104c,DAT_140081050 + DAT_140081048,(undefined8 *)(DAT_140081040 + 0x18),
                 (uint *)(DAT_140081040 + 8),DAT_140081038[1],*DAT_140081038);
    }
    pbuf_free(param_1);
    goto LAB_14002aac9;
  }
  _DAT_140081010 = 0;
  DAT_140081028 = *(undefined2 *)(param_1 + 2);
  _DAT_140081020 = param_1[1];
  DAT_140081030 = DAT_140081038;
  DAT_140081058 = (undefined8 *)0x0;
  DAT_140080ffe = 0;
  DAT_140081018 = param_1;
  tcp_input_pcb = piVar15;
  uVar11 = tcp_process(piVar15,piVar14,uVar16,uVar10);
  tcp_input_pcb = (int *)0x0;
  if ((char)uVar11 != -3) {
    if ((DAT_140080ffe & 8) == 0) {
      if ((DAT_140080ffe & 0x10) == 0) {
        puVar17 = (undefined8 *)(ulonglong)*(ushort *)(piVar15 + 0x24);
        cVar7 = '\0';
        if ((*(ushort *)(piVar15 + 0x24) != 0) && (*(code **)(piVar15 + 0x2c) != (code *)0x0)) {
          piVar14 = piVar15;
          cVar7 = (**(code **)(piVar15 + 0x2c))(*(undefined8 *)(piVar15 + 0xe));
        }
        if (DAT_140081058 != (undefined8 *)0x0) {
          if (*(code **)(piVar15 + 0x2e) == (code *)0x0) {
            pbuf_free(DAT_140081058);
          }
          else {
            uVar10 = 0;
            piVar14 = piVar15;
            puVar17 = DAT_140081058;
            cVar7 = (**(code **)(piVar15 + 0x2e))(*(undefined8 *)(piVar15 + 0xe));
          }
        }
        if (((DAT_140080ffe & 0x20) != 0) && (*(code **)(piVar15 + 0x2e) != (code *)0x0)) {
          uVar10 = 0;
          puVar17 = (undefined8 *)0x0;
          piVar14 = piVar15;
          cVar7 = (**(code **)(piVar15 + 0x2e))(*(undefined8 *)(piVar15 + 0xe));
        }
        if (cVar7 == '\0') {
          crashdump_tcp6_output(piVar15,piVar14,puVar17,uVar10);
        }
        goto LAB_14002aa54;
      }
    }
    else if (*(code **)(piVar15 + 0x36) != (code *)0x0) {
      (**(code **)(piVar15 + 0x36))(*(undefined8 *)(piVar15 + 0xe),0xfc);
    }
    crashdump_ip6_tcp_pcb_remove((longlong *)&tcp_active_pcbs,piVar15,uVar16,uVar10);
    memp_free(3,(longlong)piVar15);
  }
LAB_14002aa54:
  if (DAT_140081018 != (undefined8 *)0x0) {
    pbuf_free(DAT_140081018);
    DAT_140081018 = (undefined8 *)0x0;
  }
LAB_14002aac9:
  uVar11 = crashdump_ip6_tcp_pcbs_sane();
  if ((short)uVar11 == 0) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("tcp_input: tcp_pcbs_sane()");
  }
  return;
}



===== crashdump_tcp6_output @ 14002aaec =====

ulonglong crashdump_tcp6_output
                    (int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  short *psVar1;
  ushort uVar2;
  undefined8 *puVar3;
  u_short *puVar4;
  undefined8 uVar5;
  u_short uVar6;
  undefined2 uVar7;
  u_long uVar8;
  uint uVar9;
  uint uVar10;
  u_long uVar11;
  undefined8 *puVar12;
  uint7 extraout_var;
  undefined8 *puVar13;
  undefined4 extraout_var_01;
  uint7 extraout_var_00;
  short sVar14;
  int iVar15;
  undefined7 uVar16;
  undefined4 in_stack_ffffffffffffffdc;
  
  uVar16 = (undefined7)((ulonglong)param_4 >> 8);
  if (tcp_input_pcb == param_1) goto LAB_14002aea3;
  uVar2 = *(ushort *)((longlong)param_1 + 0x72);
  register0x00000020 = (BADSPACEBASE *)(ulonglong)uVar2;
  puVar12 = *(undefined8 **)(param_1 + 0x28);
  puVar3 = *(undefined8 **)(param_1 + 0x26);
  uVar10 = param_1[0x20];
  if ((uint)uVar2 <= (uint)param_1[0x20]) {
    uVar10 = (uint)uVar2;
  }
  if (puVar12 != (undefined8 *)0x0) {
    puVar13 = (undefined8 *)*puVar12;
    while (puVar13 != (undefined8 *)0x0) {
      register0x00000020 = (BADSPACEBASE *)*puVar13;
      puVar12 = puVar13;
      puVar13 = (undefined8 *)register0x00000020;
    }
  }
  if ((*(byte *)(param_1 + 0x11) & 2) == 0) {
joined_r0x00014002ac7a:
    while (puVar3 != (undefined8 *)0x0) {
      uVar8 = htonl(*(u_long *)(puVar3[4] + 4));
      uVar9 = uVar8 + ((uint)*(ushort *)(puVar3 + 3) - param_1[0x1b]);
      register0x00000020 = (BADSPACEBASE *)(ulonglong)uVar9;
      if (uVar10 < uVar9) break;
      *(undefined8 *)(param_1 + 0x26) = *puVar3;
      if (param_1[0xc] != 2) {
        uVar6 = ntohs(*(u_short *)(puVar3[4] + 0xc));
        uVar6 = ntohs(uVar6 | 0x10);
        *(u_short *)(puVar3[4] + 0xc) = uVar6;
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfc;
      }
      uVar8 = htonl(param_1[0x12]);
      *(u_long *)(puVar3[4] + 8) = uVar8;
      if (*(ushort *)(param_1 + 0x13) < *(ushort *)(param_1 + 0x16)) {
        *(undefined2 *)(puVar3[4] + 0xe) = 0;
      }
      else {
        uVar6 = ntohs(*(ushort *)(param_1 + 0x13));
        *(u_short *)(puVar3[4] + 0xe) = uVar6;
      }
      if (((param_1[3] == 0 && param_1[2] == 0) && param_1[1] == 0) && *param_1 == 0) {
        puVar13 = crashdump_ip6_route((uint *)(param_1 + 4));
        if (puVar13 != (undefined8 *)0x0) {
          uVar5 = puVar13[0x25];
          *(undefined8 *)param_1 = puVar13[0x24];
          *(undefined8 *)(param_1 + 2) = uVar5;
          goto LAB_14002ad33;
        }
      }
      else {
LAB_14002ad33:
        *(undefined2 *)((longlong)param_1 + 0x56) = 0;
        if (param_1[0x17] == 0) {
          param_1[0x17] = tcp_ticks;
          uVar8 = htonl(*(u_long *)(puVar3[4] + 4));
          param_1[0x18] = uVar8;
        }
        sVar14 = *(short *)(puVar3 + 4) - *(short *)(puVar3[1] + 8);
        psVar1 = (short *)(puVar3[1] + 0x12);
        *psVar1 = *psVar1 - sVar14;
        *(short *)(puVar3[1] + 0x10) = *(short *)(puVar3[1] + 0x10) - sVar14;
        *(undefined8 *)(puVar3[1] + 8) = puVar3[4];
        *(undefined2 *)(puVar3[4] + 0x10) = 0;
        uVar9 = (uint)*(ushort *)((undefined8 *)puVar3[1] + 2);
        uVar7 = crashdump_ip6_inet_chksum_pseudo
                          ((undefined8 *)puVar3[1],(longlong)param_1,(u_short *)(param_1 + 4),6,
                           uVar9);
        *(undefined2 *)(puVar3[4] + 0x10) = uVar7;
        crashdump_ip6_output
                  (puVar3[1],(undefined8 *)param_1,(uint *)(param_1 + 4),
                   CONCAT71(uVar16,*(undefined1 *)((longlong)param_1 + 0x23)),
                   CONCAT44(in_stack_ffffffffffffffdc,
                            CONCAT31((int3)(uVar9 >> 8),*(undefined1 *)((longlong)param_1 + 0x22))),
                   6);
      }
      uVar6 = ntohs(*(u_short *)(puVar3[4] + 0xc));
      if ((uVar6 & 1) == 0) {
        uVar6 = ntohs(*(u_short *)(puVar3[4] + 0xc));
        iVar15 = 0;
        if ((uVar6 & 2) != 0) goto LAB_14002adec;
      }
      else {
LAB_14002adec:
        iVar15 = 1;
      }
      uVar8 = htonl(*(u_long *)(puVar3[4] + 4));
      iVar15 = (uint)*(ushort *)(puVar3 + 3) + uVar8 + iVar15;
      param_1[0x1e] = iVar15;
      if (param_1[0x1f] - iVar15 < 0) {
        param_1[0x1f] = iVar15;
      }
      uVar6 = ntohs(*(u_short *)(puVar3[4] + 0xc));
      if ((uVar6 & 1) == 0) {
        uVar6 = ntohs(*(u_short *)(puVar3[4] + 0xc));
        iVar15 = 0;
        if ((uVar6 & 2) != 0) goto LAB_14002ae33;
      }
      else {
LAB_14002ae33:
        iVar15 = 1;
      }
      register0x00000020 = (BADSPACEBASE *)(ulonglong)((uint)*(ushort *)(puVar3 + 3) + iVar15);
      if ((uint)*(ushort *)(puVar3 + 3) + iVar15 == 0) {
        crashdump_ip6_tcp_seg_free((longlong)puVar3);
        register0x00000020 = (BADSPACEBASE *)((ulonglong)extraout_var_00 << 8);
      }
      else {
        *puVar3 = 0;
        if (*(longlong *)(param_1 + 0x28) == 0) {
          *(undefined8 **)(param_1 + 0x28) = puVar3;
        }
        else {
          uVar8 = htonl(*(u_long *)(puVar12[4] + 4));
          uVar11 = htonl(*(u_long *)(puVar3[4] + 4));
          register0x00000020 = (BADSPACEBASE *)CONCAT44(extraout_var_01,uVar11);
          if ((int)(uVar11 - uVar8) < 0) {
            register0x00000020 = *(BADSPACEBASE **)(param_1 + 0x28);
            *puVar3 = register0x00000020;
            *(undefined8 **)(param_1 + 0x28) = puVar3;
            goto LAB_14002ae93;
          }
          *puVar12 = puVar3;
        }
        puVar12 = puVar3;
      }
LAB_14002ae93:
      puVar3 = *(undefined8 **)(param_1 + 0x26);
    }
  }
  else {
    if (puVar3 != (undefined8 *)0x0) {
      uVar8 = htonl(*(u_long *)(puVar3[4] + 4));
      uVar9 = uVar8 + ((uint)*(ushort *)(puVar3 + 3) - param_1[0x1b]);
      register0x00000020 = (BADSPACEBASE *)(ulonglong)uVar9;
      if (uVar9 <= uVar10) goto joined_r0x00014002ac7a;
    }
    puVar12 = pbuf_alloc(1,0x14,0);
    if (puVar12 == (undefined8 *)0x0) {
      return 0xfe;
    }
    *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfc;
    puVar4 = (u_short *)puVar12[1];
    uVar6 = ntohs(*(u_short *)(param_1 + 0x10));
    *puVar4 = uVar6;
    uVar6 = ntohs(*(u_short *)((longlong)param_1 + 0x42));
    puVar4[1] = uVar6;
    uVar8 = htonl(param_1[0x1e]);
    *(u_long *)(puVar4 + 2) = uVar8;
    uVar8 = htonl(param_1[0x12]);
    *(u_long *)(puVar4 + 4) = uVar8;
    uVar6 = ntohs(puVar4[6]);
    uVar6 = ntohs(uVar6 & 0xffd0 | 0x10);
    puVar4[6] = uVar6;
    uVar6 = ntohs(*(u_short *)(param_1 + 0x13));
    puVar4[7] = uVar6;
    puVar4[9] = 0;
    uVar6 = ntohs(puVar4[6]);
    uVar6 = ntohs(uVar6 & 0x3f | 0x5000);
    puVar4[6] = uVar6;
    puVar4[8] = 0;
    uVar10 = (uint)*(ushort *)(puVar12 + 2);
    uVar6 = crashdump_ip6_inet_chksum_pseudo
                      (puVar12,(longlong)param_1,(u_short *)(param_1 + 4),6,uVar10);
    puVar4[8] = uVar6;
    crashdump_ip6_output
              ((longlong)puVar12,(undefined8 *)param_1,(uint *)(param_1 + 4),
               CONCAT71(uVar16,*(undefined1 *)((longlong)param_1 + 0x23)),
               CONCAT44(in_stack_ffffffffffffffdc,
                        CONCAT31((int3)(uVar10 >> 8),*(undefined1 *)((longlong)param_1 + 0x22))),6);
    pbuf_free(puVar12);
    register0x00000020 = (BADSPACEBASE *)((ulonglong)extraout_var << 8);
  }
LAB_14002aea3:
  return (ulonglong)register0x00000020 & 0xffffffffffffff00;
}



===== crashdump_tcp6_recved @ 14002aec4 =====

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



===== ethnd_init @ 14002af24 =====

void ethnd_init(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = &DAT_140081060;
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



===== ethnd_output @ 14002af4c =====

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



===== ethnd_query @ 14002aff8 =====

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
      iVar7 = (&DAT_140081080)[lVar4 * 0xc];
      if (iVar7 == 0) {
        iVar7 = 1;
        (&DAT_140081080)[lVar4 * 0xc] = 1;
      }
      if ((iVar7 != 1) && (iVar7 != 2)) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("arp_table[i].state == PENDING or STABLE");
      }
      if (((iVar7 != 1) && (param_3 != (longlong *)0x0)) ||
         (plVar5 = (longlong *)icmp6_send_nd_solicited_packet(param_1,param_2),
         param_3 != (longlong *)0x0)) {
        uVar1 = (&DAT_140081080)[lVar4 * 0xc];
        if (uVar1 == 2) {
          _Dst = (void *)param_3[1];
          memmove(_Dst,&DAT_140081078 + lVar4 * 0x30,(ulonglong)*(byte *)(param_1 + 0x30));
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
            if ((&DAT_140081060)[lVar4 * 6] == 0) {
              plVar5 = (longlong *)pbuf_ref((longlong)plVar6);
              (&DAT_140081060)[lVar4 * 6] = plVar6;
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



===== ethnd_tmr @ 14002b150 =====

void ethnd_tmr(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  
  piVar3 = &DAT_140081080;
  lVar4 = 10;
  do {
    iVar2 = *piVar3;
    bVar1 = (char)piVar3[1] + 1;
    *(byte *)(piVar3 + 1) = bVar1;
    if (iVar2 == 2) {
      if (bVar1 < 0xf0) goto LAB_14002b191;
      *piVar3 = 3;
LAB_14002b196:
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
LAB_14002b191:
      if (iVar2 == 3) goto LAB_14002b196;
    }
    piVar3 = piVar3 + 0xc;
    lVar4 = lVar4 + -1;
    if (lVar4 == 0) {
      return;
    }
  } while( true );
}



===== ethnd_update_entry @ 14002b1c4 =====

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
      (&DAT_140081080)[lVar4 * 0xc] = 2;
      (&DAT_140081088)[lVar4 * 6] = param_1;
      pvVar5 = memmove(&DAT_140081078 + lVar4 * 0x30,param_3,(ulonglong)*(byte *)(param_1 + 0x30));
      (&DAT_140081084)[lVar4 * 0x30] = 0;
      while ((&DAT_140081060)[lVar4 * 6] != 0) {
        puVar1 = (undefined8 *)(&DAT_140081060)[lVar4 * 6];
        pvVar5 = (void *)puVar1[1];
        uVar6 = pbuf_dequeue(puVar1);
        (&DAT_140081060)[lVar4 * 6] = uVar6;
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



===== find_entry @ 14002b2d0 =====

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
    if ((bVar10 == 10) && (uVar5 = uVar6 * 6, (&DAT_140081080)[uVar6 * 0xc] == 0)) {
      bVar10 = bVar11;
    }
    else {
      uVar2 = (&DAT_140081080)[uVar6 * 0xc];
      uVar5 = (ulonglong)uVar2;
      if (uVar2 == 1) {
        if (((param_1 != (uint *)0x0) &&
            (uVar5 = (ulonglong)*(uint *)(&DAT_140081068 + uVar6 * 0x30),
            *param_1 == *(uint *)(&DAT_140081068 + uVar6 * 0x30))) &&
           ((uVar2 = *(uint *)(uVar6 * 0x30 + 0x14008106c), uVar5 = (ulonglong)uVar2,
            param_1[1] == uVar2 &&
            ((uVar2 = *(uint *)(uVar6 * 0x30 + 0x140081070), uVar5 = (ulonglong)uVar2,
             param_1[2] == uVar2 &&
             (uVar2 = *(uint *)(uVar6 * 0x30 + 0x140081074), uVar5 = (ulonglong)uVar2,
             param_1[3] == uVar2)))))) {
LAB_14002b435:
          return CONCAT71((int7)(uVar5 >> 8),bVar11);
        }
        bVar1 = (&DAT_140081084)[uVar6 * 0x30];
        if ((&DAT_140081060)[uVar6 * 6] == 0) {
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
             (lVar7 = uVar6 * 0x30, *param_1 == *(uint *)(&DAT_140081068 + lVar7))) &&
            (param_1[1] == *(uint *)(lVar7 + 0x14008106c))) &&
           ((param_1[2] == *(uint *)(lVar7 + 0x140081070) &&
            (uVar5 = (ulonglong)*(uint *)(lVar7 + 0x140081074),
            param_1[3] == *(uint *)(lVar7 + 0x140081074))))) goto LAB_14002b435;
        uVar5 = uVar6 * 6;
        if (bVar9 <= (byte)(&DAT_140081084)[uVar6 * 0x30]) {
          bVar12 = bVar11;
          bVar9 = (&DAT_140081084)[uVar6 * 0x30];
        }
      }
    }
    bVar11 = bVar11 + 1;
  } while (bVar11 < 10);
  if (bVar10 == 10) {
    if ((param_2 & 1) == 0) goto LAB_14002b414;
  }
  else if ((char)bVar10 < '\n') goto LAB_14002b496;
  if ((char)bVar12 < '\n') {
    bVar10 = bVar12;
    if ((&DAT_140081060)[(ulonglong)bVar12 * 6] != 0) {
                    /* WARNING: Subroutine does not return */
      DbgPrint("arp_table[i].p == NULL");
    }
  }
  else if ((char)bVar14 < '\n') {
    bVar10 = bVar14;
  }
  else {
    if ('\t' < (char)bVar13) {
LAB_14002b414:
      return CONCAT71((int7)(uVar5 >> 8),0xff);
    }
    pbuf_free((undefined8 *)(&DAT_140081060)[(ulonglong)bVar13 * 6]);
    (&DAT_140081060)[(ulonglong)bVar13 * 6] = 0;
    bVar10 = bVar13;
  }
LAB_14002b496:
  if (9 < bVar10) {
                    /* WARNING: Subroutine does not return */
    DbgPrint("i < ARP_TABLE_SIZE");
  }
  uVar6 = (ulonglong)bVar10;
  (&DAT_140081080)[uVar6 * 0xc] = 0;
  if (param_1 != (uint *)0x0) {
    uVar3 = *(undefined8 *)(param_1 + 2);
    *(undefined8 *)(&DAT_140081068 + uVar6 * 0x30) = *(undefined8 *)param_1;
    *(undefined8 *)(uVar6 * 0x30 + 0x140081070) = uVar3;
  }
  (&DAT_140081084)[uVar6 * 0x30] = 0;
  return (ulonglong)bVar10;
}



===== icmp6_send_nd_solicited_packet @ 14002b4d8 =====

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



===== icmp_handle_echo_request @ 14002b5e4 =====

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



===== icmp_handle_nd_sol @ 14002b69c =====

undefined8 icmp_handle_nd_sol(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  undefined8 *puVar7;
  
  lVar2 = *(longlong *)(param_1 + 8);
  pbuf_header(param_1,0x28);
  lVar3 = *(longlong *)(param_1 + 8);
  puVar7 = pbuf_alloc(1,0x20,0);
  if (puVar7 != (undefined8 *)0x0) {
    puVar4 = (undefined8 *)puVar7[1];
    puVar1 = (undefined8 *)(lVar2 + 8);
    *puVar4 = 0x88;
    *(undefined1 *)((longlong)puVar4 + 4) = 0x60;
    uVar5 = *(undefined8 *)(lVar2 + 0x10);
    puVar4[1] = *puVar1;
    puVar4[2] = uVar5;
    *(undefined2 *)(puVar4 + 3) = 0x102;
    *(undefined4 *)((longlong)puVar4 + 0x1a) = *(undefined4 *)(param_2 + 0x31);
    *(undefined2 *)((longlong)puVar4 + 0x1e) = *(undefined2 *)(param_2 + 0x35);
    uVar6 = crashdump_ip6_inet_chksum_pseudo
                      (puVar7,(longlong)puVar1,(u_short *)(lVar3 + 8),0x3a,
                       (uint)*(ushort *)(puVar7 + 2));
    *(undefined2 *)((longlong)puVar4 + 2) = uVar6;
    crashdump_ip6_output_if((longlong)puVar7,puVar1,(int *)(lVar3 + 8),0xff,0x3a,param_2);
    pbuf_free(puVar7);
  }
  return 1;
}



===== ip_addr_netcmp @ 14002b778 =====

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



===== ip_find_onlink_addr @ 14002b7e0 =====

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



===== ip_find_src_addr @ 14002b828 =====

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



===== netif6_add @ 14002b92c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 *
netif6_add(undefined8 *param_1,undefined8 param_2,undefined *param_3,undefined8 param_4,
          undefined8 param_5)

{
  char cVar1;
  
  *(undefined4 *)(param_1 + 0x1d) = 0;
  *(char *)((longlong)param_1 + 0x3d) = (char)DAT_140080ffc;
  DAT_140080ffc = DAT_140080ffc + 1;
  param_1[2] = param_5;
  *(undefined1 *)((longlong)param_1 + 0x3a) = 0x20;
  param_1[5] = param_2;
  cVar1 = (*(code *)param_3)();
  if (cVar1 == '\0') {
    *param_1 = DAT_140081000;
    param_1[1] = param_4;
    DAT_140081000 = param_1;
  }
  else {
    param_1 = (undefined8 *)0x0;
  }
  return param_1;
}



===== netif6_add_addr @ 14002b99c =====

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
       (uVar1 = *(ulonglong *)(lVar2 + 0x50 + param_1), uVar1 == param_2[1])) goto LAB_14002ba56;
    lVar2 = lVar2 + 0x20;
  } while (lVar2 < 0x80);
  lVar2 = 0;
  do {
    puVar3 = (undefined8 *)(param_1 + 0x40 + lVar2);
    if (*(char *)(puVar3 + 3) == '\0') goto LAB_14002ba07;
    lVar2 = lVar2 + 0x20;
  } while (lVar2 < 0x80);
  if (*(char *)(puVar3 + 3) == '\0') {
LAB_14002ba07:
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
LAB_14002ba56:
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar1 = CONCAT71((int7)((ulonglong)lVar2 >> 8),0xf9);
  }
  return uVar1;
}



===== netif6_add_l2_mc_addr @ 14002ba6c =====

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
         uVar1 == *(ushort *)(param_2 + 1))) goto LAB_14002bad1;
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
LAB_14002bad1:
  return in_RAX & 0xffffffffffffff00;
}



===== netif6_set_up @ 14002bad4 =====

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



===== stack_ipv6_bringup @ 14002bbe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 stack_ipv6_bringup(longlong param_1)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 *puVar8;
  undefined2 *puVar9;
  
  puVar2 = (undefined8 *)(param_1 + 0x168);
  mem_init();
  memp_init();
  pbuf_init();
  tcp_listen_pcbs = 0;
  tcp_active_pcbs = 0;
  tcp_tw_pcbs = 0;
  _tcp_tmp_pcb = 0;
  tcp_ticks = 0;
  DAT_140081008 = (undefined8 *)0x0;
  DAT_140081000 = 0;
  DAT_140080ffa = 0;
  puVar8 = netif6_add(puVar2,*l2_driver_intf,(undefined *)l2_driver_intf[0xc],l2_driver_intf[0xd],
                      crashdump_ip6_input);
  if (puVar8 != (undefined8 *)0x0) {
    lVar3 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    if ((*(int *)(lVar3 + 0x458) != 0) ||
       ((((*(int *)(lVar3 + 0x45c) != 0 || (*(int *)(lVar3 + 0x460) != 0)) ||
         (*(int *)(lVar3 + 0x464) != 0)) &&
        (((*(int *)(lVar3 + 0x45c) != 0 || (*(int *)(lVar3 + 0x460) != 0)) ||
         (*(int *)(lVar3 + 0x464) != 1)))))) {
      netif6_add_addr((longlong)puVar2,(longlong *)(lVar3 + 0x458),0x40);
    }
    puVar1 = (undefined4 *)(param_1 + 0x199);
    lVar3 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    uVar4 = *(undefined4 *)(lVar3 + 0x47c);
    uVar5 = *(undefined4 *)(lVar3 + 0x480);
    uVar6 = *(undefined4 *)(lVar3 + 0x484);
    DAT_140081008 = puVar2;
    *(undefined4 *)(param_1 + 0x230) = *(undefined4 *)(lVar3 + 0x478);
    *(undefined4 *)(param_1 + 0x234) = uVar4;
    *(undefined4 *)(param_1 + 0x238) = uVar5;
    *(undefined4 *)(param_1 + 0x23c) = uVar6;
    *(undefined2 *)(param_1 + 0x1a0) = 0x5dc;
    *(undefined1 *)(param_1 + 0x1a2) = 2;
    *(undefined1 *)(param_1 + 0x198) = 6;
    (*(code *)l2_driver_intf[8])(*l2_driver_intf,puVar1,*(undefined4 *)(param_1 + 0x150));
    (*(code *)l2_driver_intf[9])(*l2_driver_intf,puVar1);
    lVar3 = *(longlong *)
             (iscsiGlobalsPtr + 0xda0 + (ulonglong)*(byte *)(iscsiGlobalsPtr + 0xd9c) * 8);
    *(undefined4 *)(lVar3 + 0x12) = *puVar1;
    *(undefined2 *)(lVar3 + 0x16) = *(undefined2 *)(param_1 + 0x19d);
    ethnd_init();
    puVar9 = iscsiAddTimer(5000,ethnd_tmr);
    *(undefined2 **)(param_1 + 0x158) = puVar9;
    puVar9 = iscsiAddTimer(0xfa,crashdump_ip6_tcp_tmr);
    *(undefined2 **)(param_1 + 0x160) = puVar9;
    iVar7 = (*(code *)l2_driver_intf[0xb])(*l2_driver_intf);
    if (iVar7 == 4) {
      netif6_set_up((longlong)puVar2);
      return 0;
    }
  }
  return 0xffffffff;
}



===== stack_ipv6_close_connection @ 14002bde0 =====

char stack_ipv6_close_connection
               (int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
LAB_14002a3b7:
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
        goto LAB_14002a3b7;
      }
      crashdump_ip6_tcp_pcb_remove(&tcp_active_pcbs,param_1,param_3,param_4);
      iVar3 = 3;
    }
    cVar1 = '\0';
    memp_free(iVar3,(longlong)param_1);
  }
  return cVar1;
}



===== stack_ipv6_flush_tcp_data @ 14002bdf0 =====

int stack_ipv6_flush_tcp_data(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  uVar1 = crashdump_tcp6_output(param_1,param_2,param_3,param_4);
  return -(uint)((char)uVar1 != '\0');
}



===== stack_ipv6_init @ 14002be04 =====

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



===== stack_ipv6_rx_packet @ 14002be60 =====

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



===== stack_ipv6_rx_tcp_data @ 14002bf10 =====

undefined1 * stack_ipv6_rx_tcp_data(undefined8 param_1,int *param_2,longlong *param_3)

{
  uint7 extraout_var;
  longlong *plVar1;
  ushort uVar2;
  
  if (param_3 != (longlong *)0x0) {
    uVar2 = 0;
    plVar1 = param_3;
    do {
      uVar2 = uVar2 + *(ushort *)((longlong)plVar1 + 0x12);
      iscsiSessionServiceRxIndication((char *)plVar1[1],(uint)*(ushort *)((longlong)plVar1 + 0x12));
      plVar1 = (longlong *)*plVar1;
    } while (plVar1 != (longlong *)0x0);
    crashdump_tcp6_recved(param_2,(ulonglong)uVar2);
    pbuf_free(param_3);
    register0x00000020 = (BADSPACEBASE *)((ulonglong)extraout_var << 8);
  }
  return (undefined1 *)register0x00000020;
}



===== stack_ipv6_set_addr @ 14002bf90 =====

void stack_ipv6_set_addr(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  
  netif6_add_addr(param_1 + 0x168,param_2,0x40);
  uVar1 = param_4[1];
  *(undefined8 *)(param_1 + 0x230) = *param_4;
  *(undefined8 *)(param_1 + 0x238) = uVar1;
  return;
}



===== stack_ipv6_setup_connection @ 14002bfd0 =====

int * stack_ipv6_setup_connection(uint *param_1,undefined2 param_2,undefined8 param_3)

{
  int *piVar1;
  
  piVar1 = (int *)crashdump_ip6_tcp_alloc(0x40);
  *(code **)(piVar1 + 0x2e) = stack_ipv6_rx_tcp_data;
  *(code **)(piVar1 + 0x2c) = CrashDumpIsr;
  *(undefined8 *)(piVar1 + 0xe) = param_3;
  crashdump_ip6_tcp_connect(piVar1,param_1,param_2,stack_ipv4_connected_callback);
  return piVar1;
}



===== stack_ipv6_write_tcp_data @ 14002c050 =====

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



===== tcp_new_port @ 14002c068 =====

void tcp_new_port(void)

{
  longlong lVar1;
  
LAB_14002c06f:
  do {
    DAT_14003a748 = DAT_14003a748 + 1;
    if (0x7fff < DAT_14003a748) {
      DAT_14003a748 = 0x1000;
    }
    for (lVar1 = tcp_active_pcbs; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x28)) {
      if (*(ushort *)(lVar1 + 0x40) == DAT_14003a748) goto LAB_14002c06f;
    }
    for (lVar1 = tcp_tw_pcbs; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x28)) {
      if (*(ushort *)(lVar1 + 0x40) == DAT_14003a748) goto LAB_14002c06f;
    }
    lVar1 = tcp_listen_pcbs;
    while( true ) {
      if (lVar1 == 0) {
        return;
      }
      if (*(ushort *)(lVar1 + 0x40) == DAT_14003a748) break;
      lVar1 = *(longlong *)(lVar1 + 0x28);
    }
  } while( true );
}



===== tcp_parseopt @ 14002c0d8 =====

void tcp_parseopt(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  u_short uVar3;
  ushort uVar4;
  byte bVar5;
  ulonglong uVar6;
  
  lVar1 = DAT_140081038;
  uVar3 = ntohs(*(u_short *)(DAT_140081038 + 0xc));
  if (0x5000 < (uVar3 & 0xf000)) {
    uVar6 = 0;
    uVar3 = ntohs(*(u_short *)(DAT_140081038 + 0xc));
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
        uVar3 = ntohs(*(u_short *)(DAT_140081038 + 0xc));
      } while ((int)(uint)bVar5 < (int)((uVar3 >> 10 & 0xfffffffc) - 0x14));
    }
  }
  return;
}



===== tcp_process @ 14002c1c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong tcp_process(int *param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  undefined8 *puVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  u_long uVar8;
  int *in_RAX;
  ulonglong uVar9;
  uint7 extraout_var;
  uint7 extraout_var_00;
  uint7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 extraout_var_03;
  undefined8 uVar10;
  int *piVar11;
  
  uVar5 = tcp_ticks;
  bVar1 = DAT_140080ffb;
  uVar9 = CONCAT71((int7)((ulonglong)param_2 >> 8),DAT_140080ffb);
  if ((DAT_140080ffb & 4) == 0) {
    in_RAX = (int *)(ulonglong)tcp_ticks;
    param_1[0x14] = tcp_ticks;
    *(undefined1 *)(param_1 + 0x39) = 0;
    iVar3 = param_1[0xc];
    if (iVar3 == 2) {
      in_RAX = (int *)((ulonglong)CONCAT31((int3)(uVar5 >> 8),bVar1) & 0xffffffffffffff12);
      if ((char)in_RAX == '\x12') {
        uVar8 = htonl(*(u_long *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20) + 4));
        uVar6 = DAT_14008104c;
        uVar5 = DAT_140081048;
        in_RAX = (int *)(ulonglong)(uVar8 + 1);
        if (DAT_14008104c == uVar8 + 1) {
          piVar11 = (int *)(ulonglong)DAT_140081048;
          *(short *)((longlong)param_1 + 0x92) = *(short *)((longlong)param_1 + 0x92) + 1;
          param_1[0x1b] = uVar6;
          param_1[0x12] = uVar5 + 1;
          uVar2 = DAT_140081038[7];
          *(char *)(param_1 + 0x25) = (char)param_1[0x25] + -1;
          param_1[0x20] = (uint)uVar2;
          puVar4 = *(undefined8 **)(param_1 + 0x28);
          param_1[0x21] = uVar5 - 1;
          param_1[0xc] = 4;
          *(short *)((longlong)param_1 + 0x72) = (short)param_1[0x16];
          *(undefined8 *)(param_1 + 0x28) = *puVar4;
          crashdump_ip6_tcp_seg_free((longlong)puVar4);
          tcp_parseopt((longlong)param_1);
          uVar10 = 0;
          if (*(code **)(param_1 + 0x30) != (code *)0x0) {
            param_3 = 0;
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
            in_RAX = (int *)crashdump_tcp6_output(param_1,piVar11,param_3,param_4);
          }
          goto LAB_14002c66e;
        }
        uVar9 = (ulonglong)DAT_140080ffb;
      }
      if ((uVar9 & 0x10) != 0) {
LAB_14002c633:
        in_RAX = (int *)crashdump_ip6_tcp_rst
                                  (DAT_14008104c,DAT_140081050 + DAT_140081048,
                                   (undefined8 *)(DAT_140081040 + 0x18),(uint *)(DAT_140081040 + 8),
                                   DAT_140081038[1],*DAT_140081038);
      }
    }
    else if (iVar3 == 3) {
      if ((bVar1 & 0x14) == 0x10) {
        if (((int)(DAT_14008104c - param_1[0x1b]) < 1) || (0 < (int)(DAT_14008104c - param_1[0x1e]))
           ) goto LAB_14002c633;
        param_1[0xc] = 4;
        if (*(code **)(param_1 + 0x32) == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("pcb->accept != NULL");
        }
        uVar9 = 0;
        piVar11 = param_1;
        cVar7 = (**(code **)(param_1 + 0x32))(*(undefined8 *)(param_1 + 0xe));
        if (cVar7 != '\0') {
          uVar10 = crashdump_ip6_tcp_abort(param_1,piVar11,uVar9,param_4);
          return CONCAT71((int7)((ulonglong)uVar10 >> 8),0xfd);
        }
        tcp_receive(param_1,piVar11,uVar9,param_4);
        in_RAX = (int *)(ulonglong)*(ushort *)(param_1 + 0x16);
        *(ushort *)((longlong)param_1 + 0x72) = *(ushort *)(param_1 + 0x16);
      }
    }
    else if (iVar3 == 4) {
LAB_14002c482:
      cVar7 = tcp_receive(param_1,uVar9,param_3,param_4);
      in_RAX = (int *)CONCAT71(extraout_var_03,cVar7);
      if (((DAT_140080ffb & 1) != 0) && (cVar7 != '\0')) {
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
        in_RAX = (int *)crashdump_tcp6_output(param_1,uVar9,param_3,param_4);
        param_1[0xc] = 7;
      }
    }
    else if (iVar3 == 5) {
      tcp_receive(param_1,uVar9,param_3,param_4);
      in_RAX = (int *)CONCAT71(extraout_var_02,DAT_140080ffb);
      if ((DAT_140080ffb & 1) == 0) {
        if (((DAT_140080ffb & 0x10) != 0) &&
           (in_RAX = (int *)(ulonglong)(uint)param_1[0x1e], DAT_14008104c == param_1[0x1e])) {
          param_1[0xc] = 6;
        }
      }
      else {
        if (((DAT_140080ffb & 0x10) != 0) && (DAT_14008104c == param_1[0x1e])) {
          *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
          crashdump_tcp6_output(param_1,uVar9,param_3,param_4);
          crashdump_ip6_tcp_pcb_purge((longlong)param_1);
          piVar11 = tcp_active_pcbs;
          if (tcp_active_pcbs == param_1) goto LAB_14002c36e;
          while (_tcp_tmp_pcb = piVar11, piVar11 != (int *)0x0) {
            piVar11 = *(int **)(piVar11 + 10);
            if ((piVar11 != (int *)0x0) && (piVar11 == param_1)) goto LAB_14002c3a4;
          }
          goto LAB_14002c3ac;
        }
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
        in_RAX = (int *)crashdump_tcp6_output(param_1,uVar9,param_3,param_4);
        param_1[0xc] = 8;
      }
    }
    else if (iVar3 == 6) {
      tcp_receive(param_1,uVar9,param_3,param_4);
      in_RAX = (int *)((ulonglong)extraout_var_01 << 8);
      if ((DAT_140080ffb & 1) != 0) {
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
        crashdump_tcp6_output(param_1,uVar9,param_3,param_4);
        crashdump_ip6_tcp_pcb_purge((longlong)param_1);
        piVar11 = tcp_active_pcbs;
        if (tcp_active_pcbs == param_1) {
LAB_14002c36e:
          tcp_active_pcbs = *(int **)(tcp_active_pcbs + 10);
        }
        else {
          while (_tcp_tmp_pcb = piVar11, piVar11 != (int *)0x0) {
            piVar11 = *(int **)(piVar11 + 10);
            if ((piVar11 != (int *)0x0) && (piVar11 == param_1)) goto LAB_14002c3a4;
          }
        }
LAB_14002c3ac:
        param_1[10] = 0;
        param_1[0xb] = 0;
        param_1[0xc] = 10;
        *(int **)(param_1 + 10) = tcp_tw_pcbs;
        in_RAX = tcp_tw_pcbs;
        tcp_tw_pcbs = param_1;
      }
    }
    else {
      if (iVar3 == 7) goto LAB_14002c482;
      if (iVar3 == 8) {
        tcp_receive(param_1,uVar9,param_3,param_4);
        in_RAX = (int *)((ulonglong)extraout_var_00 << 8);
        if (((DAT_140080ffb & 0x10) != 0) &&
           (in_RAX = (int *)(ulonglong)(uint)param_1[0x1e], DAT_14008104c == param_1[0x1e])) {
          *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
          crashdump_tcp6_output(param_1,uVar9,param_3,param_4);
          crashdump_ip6_tcp_pcb_purge((longlong)param_1);
          piVar11 = tcp_active_pcbs;
          if (tcp_active_pcbs == param_1) goto LAB_14002c36e;
          while (_tcp_tmp_pcb = piVar11, piVar11 != (int *)0x0) {
            piVar11 = *(int **)(piVar11 + 10);
            if ((piVar11 != (int *)0x0) && (piVar11 == param_1)) goto LAB_14002c3a4;
          }
          goto LAB_14002c3ac;
        }
      }
      else if (iVar3 == 9) {
        tcp_receive(param_1,uVar9,param_3,param_4);
        in_RAX = (int *)((ulonglong)extraout_var << 8);
        if (((DAT_140080ffb & 0x10) != 0) &&
           (in_RAX = (int *)(ulonglong)(uint)param_1[0x1e], DAT_14008104c == param_1[0x1e])) {
          param_1[0xc] = 0;
          DAT_140080ffe = 0x10;
        }
      }
    }
LAB_14002c66e:
    uVar9 = (ulonglong)in_RAX & 0xffffffffffffff00;
  }
  else {
    if (param_1[0xc] == 2) {
      in_RAX = (int *)(ulonglong)(uint)param_1[0x1e];
      if (DAT_14008104c != param_1[0x1e]) goto LAB_14002c66e;
    }
    else {
      if (((int)(DAT_140081048 - param_1[0x12]) < 0) ||
         (in_RAX = (int *)(ulonglong)*(ushort *)(param_1 + 0x13),
         0 < (int)((DAT_140081048 - *(ushort *)(param_1 + 0x13)) - param_1[0x12])))
      goto LAB_14002c66e;
      if (param_1[0xc] == 0) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("tcp_input: pcb->state != CLOSED");
      }
    }
    *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfe;
    uVar9 = CONCAT71((int7)((ulonglong)in_RAX >> 8),0xfc);
    DAT_140080ffe = 8;
  }
  return uVar9;
LAB_14002c3a4:
  *(undefined8 *)(_tcp_tmp_pcb + 10) = *(undefined8 *)(param_1 + 10);
  goto LAB_14002c3ac;
}



===== tcp_receive @ 14002c67c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 tcp_receive(int *param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  u_short uVar6;
  u_long uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  uint uVar11;
  short sVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined1 uVar15;
  int iVar16;
  ushort uVar17;
  short sVar18;
  ushort uVar19;
  uint uVar20;
  
  uVar4 = DAT_14008104c;
  uVar20 = DAT_140081048;
  uVar15 = 0;
  if ((DAT_140080ffb & 0x10) != 0) {
    uVar2 = param_1[0x21];
    uVar11 = param_1[0x20];
    param_3 = (ulonglong)DAT_14008104c;
    iVar16 = uVar11 + uVar2;
    if ((((int)(uVar2 - DAT_140081048) < 0) ||
        ((uVar2 == DAT_140081048 && ((int)(param_1[0x22] - DAT_14008104c) < 0)))) ||
       ((param_1[0x22] == DAT_14008104c && (uVar11 < *(ushort *)(DAT_140081038 + 0xe))))) {
      uVar11 = (uint)*(ushort *)(DAT_140081038 + 0xe);
      param_1[0x20] = (uint)*(ushort *)(DAT_140081038 + 0xe);
      param_1[0x21] = uVar20;
      param_1[0x22] = uVar4;
      uVar2 = uVar20;
    }
    uVar3 = param_1[0x1b];
    param_4 = (ulonglong)uVar3;
    if (uVar3 == uVar4) {
      *(undefined2 *)(param_1 + 0x24) = 0;
      if (((uVar2 + uVar11 == iVar16) &&
          (*(char *)(param_1 + 0x1c) = (char)param_1[0x1c] + '\x01', 2 < *(byte *)(param_1 + 0x1c)))
         && (*(longlong *)(param_1 + 0x28) != 0)) {
        if ((*(byte *)(param_1 + 0x11) & 4) == 0) {
          crashdump_ip6_tcp_rexmit(param_1,(ulonglong)uVar2,param_3,param_4);
          if ((uint)param_1[0x20] < (uint)*(ushort *)((longlong)param_1 + 0x72)) {
            uVar19 = (ushort)((uint)param_1[0x20] >> 1);
          }
          else {
            uVar19 = *(ushort *)((longlong)param_1 + 0x72) >> 1;
          }
          *(ushort *)(param_1 + 0x1d) = uVar19;
          uVar20 = DAT_140081048;
          param_3 = (ulonglong)DAT_14008104c;
          *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 4;
          *(ushort *)((longlong)param_1 + 0x72) = (short)param_1[0x16] * 3 + uVar19;
        }
        else {
          uVar19 = (short)param_1[0x16] + *(ushort *)((longlong)param_1 + 0x72);
          if (*(ushort *)((longlong)param_1 + 0x72) < uVar19) {
            *(ushort *)((longlong)param_1 + 0x72) = uVar19;
          }
        }
      }
    }
    else if ((0 < (int)(uVar4 - uVar3)) && ((int)(uVar4 - param_1[0x1f]) < 1)) {
      if ((*(byte *)(param_1 + 0x11) & 4) != 0) {
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xfb;
        *(short *)((longlong)param_1 + 0x72) = (short)param_1[0x1d];
      }
      *(short *)(param_1 + 0x1a) =
           ((short)param_1[0x19] >> 3) + *(short *)((longlong)param_1 + 0x66);
      sVar18 = (short)uVar4 - (short)param_1[0x1b];
      *(short *)((longlong)param_1 + 0x92) = *(short *)((longlong)param_1 + 0x92) + sVar18;
      *(undefined1 *)((longlong)param_1 + 0x6a) = 0;
      *(short *)(param_1 + 0x24) = sVar18;
      *(undefined1 *)(param_1 + 0x1c) = 0;
      param_1[0x1b] = uVar4;
      if (3 < param_1[0xc]) {
        uVar19 = *(ushort *)((longlong)param_1 + 0x72);
        param_4 = (ulonglong)uVar19;
        uVar17 = *(ushort *)(param_1 + 0x16);
        if (*(ushort *)(param_1 + 0x1d) <= uVar19) {
          uVar17 = (ushort)((int)((uint)uVar17 * (uint)uVar17) / (int)(uint)uVar19);
        }
        if (uVar19 < (ushort)(uVar17 + uVar19)) {
          *(ushort *)((longlong)param_1 + 0x72) = uVar17 + uVar19;
        }
      }
      lVar8 = *(longlong *)(param_1 + 0x28);
      if (lVar8 != 0) {
        do {
          uVar6 = ntohs(*(u_short *)(*(longlong *)(lVar8 + 0x20) + 0xc));
          if ((uVar6 & 1) == 0) {
            uVar6 = ntohs(*(u_short *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20) + 0xc));
            iVar16 = 0;
            if ((uVar6 & 2) != 0) goto LAB_14002c895;
          }
          else {
LAB_14002c895:
            iVar16 = 1;
          }
          puVar9 = *(undefined8 **)(param_1 + 0x28);
          uVar7 = htonl(*(u_long *)(puVar9[4] + 4));
          if (0 < (int)((*(ushort *)(puVar9 + 3) - DAT_14008104c) + uVar7 + iVar16)) break;
          *(undefined8 *)(param_1 + 0x28) = *puVar9;
          cVar5 = pbuf_clen((undefined8 *)puVar9[1]);
          *(char *)(param_1 + 0x25) = (char)param_1[0x25] - cVar5;
          crashdump_ip6_tcp_seg_free((longlong)puVar9);
          if ((((char)param_1[0x25] != '\0') && (*(longlong *)(param_1 + 0x28) == 0)) &&
             (*(longlong *)(param_1 + 0x26) == 0)) {
                    /* WARNING: Subroutine does not return */
            DbgPrint("tcp_receive: valid queue length");
          }
          lVar8 = *(longlong *)(param_1 + 0x28);
        } while (lVar8 != 0);
        param_3 = (ulonglong)DAT_14008104c;
        uVar20 = DAT_140081048;
      }
      *(undefined1 *)(param_1 + 0x15) = 0;
    }
    lVar8 = *(longlong *)(param_1 + 0x26);
    if (lVar8 != 0) {
      do {
        uVar6 = ntohs(*(u_short *)(*(longlong *)(lVar8 + 0x20) + 0xc));
        if ((uVar6 & 1) == 0) {
          uVar6 = ntohs(*(u_short *)(*(longlong *)(*(longlong *)(param_1 + 0x26) + 0x20) + 0xc));
          iVar16 = 0;
          if ((uVar6 & 2) != 0) goto LAB_14002c96c;
        }
        else {
LAB_14002c96c:
          iVar16 = 1;
        }
        puVar9 = *(undefined8 **)(param_1 + 0x26);
        uVar7 = htonl(*(u_long *)(puVar9[4] + 4));
        param_3 = (ulonglong)DAT_14008104c;
        if (((int)(((DAT_14008104c - *(ushort *)(puVar9 + 3)) - iVar16) - uVar7) < 0) ||
           (0 < (int)(DAT_14008104c - param_1[0x1f]))) goto LAB_14002ca26;
        *(undefined8 *)(param_1 + 0x26) = *puVar9;
        cVar5 = pbuf_clen((undefined8 *)puVar9[1]);
        *(char *)(param_1 + 0x25) = (char)param_1[0x25] - cVar5;
        crashdump_ip6_tcp_seg_free((longlong)puVar9);
        if (((char)param_1[0x25] != '\0') &&
           ((*(longlong *)(param_1 + 0x28) == 0 && (*(longlong *)(param_1 + 0x26) == 0)))) {
                    /* WARNING: Subroutine does not return */
          DbgPrint("tcp_receive: valid queue length");
        }
        if (*(longlong *)(param_1 + 0x26) == 0) break;
        uVar7 = htonl(*(u_long *)(*(longlong *)(*(longlong *)(param_1 + 0x26) + 0x20) + 4));
        param_1[0x1e] = uVar7;
        lVar8 = *(longlong *)(param_1 + 0x26);
      } while (lVar8 != 0);
      param_3 = (ulonglong)DAT_14008104c;
LAB_14002ca26:
      uVar20 = DAT_140081048;
    }
    if ((param_1[0x17] != 0) && (param_1[0x18] - (int)param_3 < 0)) {
      uVar17 = ((short)tcp_ticks - ((short)param_1[0x19] >> 3)) - (short)param_1[0x17];
      param_3 = (ulonglong)uVar17;
      sVar18 = (short)param_1[0x19] + uVar17;
      param_1[0x17] = 0;
      *(short *)(param_1 + 0x19) = sVar18;
      uVar19 = -uVar17;
      if (-1 < (short)uVar17) {
        uVar19 = uVar17;
      }
      sVar12 = (uVar19 - (*(short *)((longlong)param_1 + 0x66) >> 2)) +
               *(short *)((longlong)param_1 + 0x66);
      uVar19 = (sVar18 >> 3) + sVar12;
      param_4 = (ulonglong)uVar19;
      *(short *)((longlong)param_1 + 0x66) = sVar12;
      *(ushort *)(param_1 + 0x1a) = uVar19;
    }
  }
  uVar4 = param_1[0x12];
  plVar13 = (longlong *)(ulonglong)uVar4;
  if (DAT_140081050 == 0) {
    if (-1 < (int)(uVar20 - uVar4)) {
      iVar16 = (uVar20 - *(ushort *)(param_1 + 0x13)) - uVar4;
      goto LAB_14002cfc4;
    }
  }
  else {
    iVar16 = uVar4 - uVar20;
    if ((iVar16 < 1) || (-1 < (int)((uVar4 - DAT_140081050) - uVar20))) {
      if ((int)(uVar20 - uVar4) < 0) {
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
        crashdump_tcp6_output(param_1,plVar13,param_3,param_4);
        uVar20 = DAT_140081048;
      }
    }
    else {
      if (DAT_140081018 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        DbgPrint("inseg.p != NULL");
      }
      plVar13 = DAT_140081018;
      if ((int)(uint)*(ushort *)((longlong)DAT_140081018 + 0x12) < iVar16) {
        lVar8 = DAT_140081018[2];
        uVar19 = *(ushort *)((longlong)DAT_140081018 + 0x12);
        sVar18 = (short)iVar16;
        if ((int)(uint)uVar19 < iVar16) {
          do {
            *(short *)(plVar13 + 2) = (short)lVar8 - sVar18;
            iVar16 = iVar16 - (uint)uVar19;
            *(undefined2 *)((longlong)plVar13 + 0x12) = 0;
            plVar13 = (longlong *)*plVar13;
            uVar19 = *(ushort *)((longlong)plVar13 + 0x12);
          } while ((int)(uint)uVar19 < iVar16);
        }
      }
      pbuf_header((longlong)plVar13,-(short)iVar16);
      _DAT_140081020 = plVar13[1];
      DAT_140081028 = DAT_140081028 + ((short)DAT_140081048 - (short)param_1[0x12]);
      uVar20 = param_1[0x12];
      DAT_140081048 = uVar20;
      *(uint *)(DAT_140081030 + 4) = uVar20;
    }
    uVar4 = param_1[0x12];
    plVar13 = (longlong *)(ulonglong)uVar4;
    if (-1 < (int)(uVar20 - uVar4)) {
      iVar16 = (uVar20 - *(ushort *)(param_1 + 0x13)) - uVar4;
      if (iVar16 < 0) {
        if (uVar4 != uVar20) {
          *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
          crashdump_tcp6_output(param_1,plVar13,param_3,param_4);
          if (*(longlong **)(param_1 + 0x2a) == (longlong *)0x0) {
            puVar9 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140081010);
LAB_14002cdfa:
            *(undefined8 **)(param_1 + 0x2a) = puVar9;
            return 0;
          }
          plVar13 = (longlong *)0x0;
          plVar14 = *(longlong **)(param_1 + 0x2a);
          do {
            uVar20 = *(uint *)(plVar14[4] + 4);
            if (DAT_140081048 == uVar20) {
              if (DAT_140081028 <= *(ushort *)(plVar14 + 3)) {
                return 0;
              }
              plVar10 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140081010);
              if (plVar10 == (longlong *)0x0) {
                return 0;
              }
              *plVar10 = *plVar14;
              if (plVar13 == (longlong *)0x0) {
                *(longlong **)(param_1 + 0x2a) = plVar10;
                return 0;
              }
              *plVar13 = (longlong)plVar10;
              return 0;
            }
            if (plVar13 == (longlong *)0x0) {
              if ((int)(DAT_140081048 - uVar20) < 0) {
                if (0 < (int)((DAT_140081028 - uVar20) + DAT_140081048)) {
                  DAT_140081028 = (short)uVar20 - (short)DAT_140081048;
                  pbuf_realloc(DAT_140081018,DAT_140081028);
                }
                puVar9 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140081010);
                if (puVar9 == (undefined8 *)0x0) {
                  return 0;
                }
                *puVar9 = plVar14;
                goto LAB_14002cdfa;
              }
            }
            else if ((0 < (int)(DAT_140081048 - *(int *)(plVar13[4] + 4))) &&
                    ((int)((DAT_140081048 - uVar20) + 1) < 1)) {
              if (0 < (int)((DAT_140081028 - uVar20) + DAT_140081048)) {
                DAT_140081028 = (short)uVar20 - (short)DAT_140081048;
                pbuf_realloc(DAT_140081018,DAT_140081028);
              }
              puVar9 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140081010);
              uVar20 = DAT_140081048;
              if (puVar9 == (undefined8 *)0x0) {
                return 0;
              }
              *puVar9 = plVar14;
              *plVar13 = (longlong)puVar9;
              if ((int)((*(ushort *)(plVar13 + 3) - uVar20) + *(int *)(plVar13[4] + 4)) < 1) {
                return 0;
              }
              uVar19 = (short)uVar20 - *(short *)(plVar13[4] + 4);
              *(ushort *)(plVar13 + 3) = uVar19;
              puVar9 = (undefined8 *)plVar13[1];
              goto LAB_14002cf24;
            }
            plVar10 = (longlong *)*plVar14;
            if ((plVar10 == (longlong *)0x0) && (0 < (int)(DAT_140081048 - uVar20))) {
              puVar9 = crashdump_ip6_tcp_seg_copy((undefined8 *)&DAT_140081010);
              *plVar14 = (longlong)puVar9;
              if (puVar9 == (undefined8 *)0x0) {
                return 0;
              }
              if ((int)((*(ushort *)(plVar14 + 3) - DAT_140081048) + *(int *)(plVar14[4] + 4)) < 1)
              {
                return 0;
              }
              uVar19 = (short)DAT_140081048 - *(short *)(plVar14[4] + 4);
              *(ushort *)(plVar14 + 3) = uVar19;
              puVar9 = (undefined8 *)plVar14[1];
LAB_14002cf24:
              pbuf_realloc(puVar9,uVar19);
              return 0;
            }
            plVar13 = plVar14;
            plVar14 = plVar10;
            if (plVar10 == (longlong *)0x0) {
              return 0;
            }
          } while( true );
        }
        uVar15 = 1;
        if ((*(longlong *)(param_1 + 0x2a) != 0) &&
           (plVar13 = *(longlong **)(*(longlong *)(param_1 + 0x2a) + 0x20),
           (int)((*(int *)((longlong)plVar13 + 4) - (uint)DAT_140081028) - uVar20) < 1)) {
          DAT_140081028 = *(short *)((longlong)plVar13 + 4) - (short)uVar20;
          plVar13 = (longlong *)(ulonglong)DAT_140081028;
          pbuf_realloc(DAT_140081018,DAT_140081028);
        }
        uVar6 = ntohs(*(u_short *)(DAT_140081030 + 0xc));
        if (((uVar6 & 1) == 0) &&
           (uVar6 = ntohs(*(u_short *)(DAT_140081030 + 0xc)), (uVar6 & 2) == 0)) {
          sVar18 = 0;
        }
        else {
          sVar18 = 1;
        }
        uVar19 = sVar18 + DAT_140081028;
        DAT_140081050 = uVar19;
        if (param_1[0xc] != 7) {
          param_1[0x12] = param_1[0x12] + (uint)uVar19;
        }
        if (*(ushort *)(param_1 + 0x13) < uVar19) {
          sVar18 = 0;
        }
        else {
          sVar18 = *(ushort *)(param_1 + 0x13) - uVar19;
        }
        *(short *)(param_1 + 0x13) = sVar18;
        if ((short)DAT_140081018[2] != 0) {
          DAT_140081058 = DAT_140081018;
          DAT_140081018 = (longlong *)0x0;
        }
        uVar6 = ntohs(*(u_short *)(DAT_140081030 + 0xc));
        if ((uVar6 & 1) != 0) {
          DAT_140080ffe = 0x20;
        }
        while (puVar9 = *(undefined8 **)(param_1 + 0x2a), puVar9 != (undefined8 *)0x0) {
          uVar20 = *(uint *)(puVar9[4] + 4);
          if (uVar20 != param_1[0x12]) break;
          DAT_140081048 = uVar20;
          uVar6 = ntohs(*(u_short *)(puVar9[4] + 0xc));
          if ((uVar6 & 1) == 0) {
            uVar6 = ntohs(*(u_short *)(puVar9[4] + 0xc));
            iVar16 = 0;
            if ((uVar6 & 2) != 0) goto LAB_14002ccbf;
          }
          else {
LAB_14002ccbf:
            iVar16 = 1;
          }
          param_1[0x12] = param_1[0x12] + (uint)*(ushort *)(puVar9 + 3) + iVar16;
          uVar6 = ntohs(*(u_short *)(puVar9[4] + 0xc));
          if ((uVar6 & 1) == 0) {
            uVar6 = ntohs(*(u_short *)(puVar9[4] + 0xc));
            iVar16 = 0;
            if ((uVar6 & 2) != 0) goto LAB_14002ccf1;
          }
          else {
LAB_14002ccf1:
            iVar16 = 1;
          }
          if ((uint)*(ushort *)(param_1 + 0x13) < (uint)*(ushort *)(puVar9 + 3) + iVar16) {
            sVar18 = 0;
          }
          else {
            uVar6 = ntohs(*(u_short *)(puVar9[4] + 0xc));
            if (((uVar6 & 1) == 0) &&
               (uVar6 = ntohs(*(u_short *)(puVar9[4] + 0xc)), (uVar6 & 2) == 0)) {
              plVar13 = (longlong *)0x0;
            }
            else {
              plVar13 = (longlong *)0x1;
            }
            sVar18 = ((short)param_1[0x13] - *(short *)(puVar9 + 3)) - (short)plVar13;
          }
          *(short *)(param_1 + 0x13) = sVar18;
          plVar14 = (longlong *)puVar9[1];
          if ((short)plVar14[2] != 0) {
            if (DAT_140081058 == (longlong *)0x0) {
              DAT_140081058 = plVar14;
            }
            else {
              pbuf_cat(DAT_140081058,(longlong)plVar14);
              plVar13 = plVar14;
            }
            puVar9[1] = 0;
          }
          uVar6 = ntohs(*(u_short *)(puVar9[4] + 0xc));
          if (((uVar6 & 1) != 0) && (DAT_140080ffe = 0x20, param_1[0xc] == 4)) {
            param_1[0xc] = 7;
          }
          *(undefined8 *)(param_1 + 0x2a) = *puVar9;
          crashdump_ip6_tcp_seg_free((longlong)puVar9);
        }
        bVar1 = *(byte *)(param_1 + 0x11);
        if ((bVar1 & 1) == 0) {
          *(byte *)(param_1 + 0x11) = bVar1 | 1;
          return 1;
        }
        *(byte *)(param_1 + 0x11) = bVar1 & 0xfe | 2;
        goto LAB_14002cfca;
      }
LAB_14002cfc4:
      if (iVar16 + 1 < 1) {
        return 0;
      }
    }
  }
  *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 2;
LAB_14002cfca:
  crashdump_tcp6_output(param_1,plVar13,param_3,param_4);
  return uVar15;
}



===== tcp_recv_null @ 14002cff0 =====

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



===== _guard_dispatch_icall @ 14002d030 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014002d030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memmove @ 14002d040 =====

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
        if (uVar12 == 0) goto LAB_14002d1f7;
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
LAB_14002d1f7:
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
      if (uVar12 == 0) goto LAB_14002d052;
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
LAB_14002d052:
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



===== memset @ 14002d380 =====

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



===== DriverEntry @ 140088000 =====

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
    DAT_14003a771 = 1;
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
  local_98 = 0x6460;
  local_80 = 0x1010101;
  local_7c = 0x101;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== entry @ 140088110 =====

void entry(longlong param_1,longlong param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14008813c =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x1400317a8) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}


