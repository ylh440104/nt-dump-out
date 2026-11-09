
===== DriverEntry @ 00011008 =====

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
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined1 local_7c;
  code *local_60;
  code *local_58;
  
  memset(&local_d8,0,0xd0);
  local_94 = 0;
  local_d0 = CissInitialize;
  local_58 = CissBuildIO;
  local_c8 = CissStartIO;
  local_c0 = CissIsr;
  local_60 = CissAdapterControl;
  local_d8 = 0xd0;
  local_b8 = CissFindAdapter;
  local_98 = 0xa0a8;
  local_90 = 0x1148;
  local_d4 = 5;
  local_8c = 3;
  local_b0 = CissHardwareBusReset;
  local_80 = 0x1010102;
  local_7c = 1;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== CissBuildIO @ 000110e4 =====

undefined8 CissBuildIO(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined8 in_RAX;
  ulonglong uVar2;
  
  if (*(char *)(param_2 + 0x48) == '*') {
    *(byte *)(param_2 + 0x49) = *(byte *)(param_2 + 0x49) & 0xf7;
  }
  if (*(char *)(param_2 + 2) == '\0') {
    if ((*(char *)(param_2 + 5) != '\0') || (3 < *(byte *)(param_2 + 6))) {
      cVar1 = RetrieveScatterGatherList(param_1,param_2);
      if (cVar1 == '\0') {
        *(undefined1 *)(param_2 + 3) = 10;
        in_RAX = StorPortNotification(0,param_1,param_2);
        goto LAB_0001112b;
      }
      in_RAX = BuildCissCommand(param_1,param_2,0);
    }
    if (((*(char *)(param_2 + 5) == '\0') && (*(char *)(param_2 + 6) == '\0')) &&
       (*(char *)(param_2 + 7) == '\0')) {
      uVar2 = FUN_0001124c(param_1,param_2);
      return uVar2 & 0xffffffffffffff00;
    }
  }
LAB_0001112b:
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== RetrieveScatterGatherList @ 00011170 =====

undefined1 RetrieveScatterGatherList(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  uint uVar6;
  short sVar7;
  
  uVar3 = *(uint *)(param_2 + 0x10);
  uVar4 = 1;
  sVar7 = 0;
  uVar2 = *(longlong *)(param_2 + 0x38) + 0x124U & 0xffffffffffffffe0;
  *(ulonglong *)(*(longlong *)(param_2 + 0x38) + 0xa8) = uVar2;
  puVar5 = (undefined8 *)(uVar2 + 0x34);
  if (*(int *)(param_2 + 0x10) != 0) {
    puVar1 = (uint *)StorPortGetScatterGatherList();
    if (puVar1 != (uint *)0x0) {
      uVar6 = 0;
      if (*puVar1 != 0) {
        do {
          sVar7 = sVar7 + 1;
          *puVar5 = *(undefined8 *)(puVar1 + (ulonglong)uVar6 * 6 + 4);
          if (puVar1[(ulonglong)uVar6 * 6 + 6] < uVar3) {
            *(uint *)(puVar5 + 1) = puVar1[(ulonglong)uVar6 * 6 + 6];
          }
          else {
            *(uint *)(puVar5 + 1) = uVar3;
          }
          uVar3 = uVar3 - *(int *)(puVar5 + 1);
          *(undefined4 *)((longlong)puVar5 + 0xc) = 0;
          uVar6 = uVar6 + 1;
          puVar5 = puVar5 + 2;
        } while (uVar6 < *puVar1);
      }
      if (*puVar1 < 0x100) {
        *(char *)(uVar2 + 1) = (char)*puVar1;
      }
      else {
        *(undefined1 *)(uVar2 + 1) = 0xff;
      }
      *(short *)(uVar2 + 2) = sVar7;
      return 1;
    }
    uVar4 = 0;
  }
  *(undefined2 *)(uVar2 + 2) = 0;
  *(undefined1 *)(uVar2 + 1) = 0;
  return uVar4;
}



===== FUN_0001124c @ 0001124c =====

undefined8 FUN_0001124c(undefined8 param_1,longlong param_2)

{
  char cVar1;
  undefined8 *puVar2;
  byte *_Dst;
  undefined8 uVar3;
  undefined4 local_res10;
  
  cVar1 = *(char *)(param_2 + 0x48);
  if (cVar1 != '\0') {
    if (cVar1 == '\x12') {
      _Dst = *(byte **)(param_2 + 0x18);
      memset(_Dst,0,(ulonglong)*(uint *)(param_2 + 0x10));
      *_Dst = *_Dst | 0x1f;
      _Dst[8] = 0x43;
      _Dst[9] = 0x4f;
      _Dst[10] = 0x4d;
      _Dst[0xb] = 0x50;
      _Dst[0xc] = 0x41;
      _Dst[0xd] = 0x51;
      _Dst[0xe] = 0x20;
      _Dst[0xf] = 0x20;
      _Dst[0x20] = 0x43;
      _Dst[0x21] = 0x49;
      _Dst[0x22] = 0x53;
      _Dst[0x23] = 0x32;
      _Dst[0x10] = 'S';
      _Dst[0x11] = 'C';
      _Dst[0x12] = 'S';
      _Dst[0x13] = 'I';
      _Dst[0x14] = ' ';
      _Dst[0x15] = 'C';
      _Dst[0x16] = 'O';
      _Dst[0x17] = 'M';
      _Dst[0x18] = 'M';
      _Dst[0x19] = 'U';
      _Dst[0x1a] = 'N';
      _Dst[0x1b] = 'I';
      _Dst[0x1c] = 'C';
      _Dst[0x1d] = 'A';
      _Dst[0x1e] = 'T';
      _Dst[0x1f] = 'E';
    }
    else if (cVar1 != '/') {
      if (cVar1 != -0x60) {
        *(undefined1 *)(param_2 + 3) = 6;
        goto LAB_00011301;
      }
      local_res10 = CONCAT13(*(undefined1 *)(param_2 + 0x4e),
                             CONCAT12(*(undefined1 *)(param_2 + 0x4f),
                                      CONCAT11(*(undefined1 *)(param_2 + 0x50),
                                               *(undefined1 *)(param_2 + 0x51))));
      if (local_res10 < 0x10) {
        BuildStatus_IllegalRequest(param_1,param_2,0x24);
        goto LAB_00011301;
      }
      puVar2 = *(undefined8 **)(param_2 + 0x18);
      *puVar2 = 0;
      *(undefined1 *)((longlong)puVar2 + 3) = 8;
    }
  }
  *(undefined2 *)(param_2 + 3) = 1;
LAB_00011301:
  uVar3 = StorPortNotification(0,param_1,param_2);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== SynchronizeTimerShutdown @ 00011328 =====

undefined8 SynchronizeTimerShutdown(longlong param_1)

{
  longlong lVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)(param_1 + 0x9f6c);
  for (lVar1 = 5; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(uint *)(param_1 + 0x9398) = *(uint *)(param_1 + 0x9398) | 0x1000;
  return 1;
}



===== FUN_0001135c @ 0001135c =====

int * FUN_0001135c(longlong param_1,longlong param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  int *piVar4;
  longlong lVar5;
  uint uVar6;
  bool bVar7;
  
  if (*(char *)(param_2 + 7) == '\0') {
    uVar6 = (uint)*(byte *)(param_2 + 5) * 0x80 + (uint)*(byte *)(param_2 + 6);
  }
  else {
    uVar6 = 0xffffffff;
  }
  while( true ) {
    LOCK();
    bVar7 = *(int *)(param_1 + 0x9e54) == 0;
    if (bVar7) {
      *(int *)(param_1 + 0x9e54) = 1;
    }
    UNLOCK();
    if (bVar7) break;
    do {
    } while (*(int *)(param_1 + 0x9e54) != 0);
  }
  lVar5 = (longlong)(int)(uVar6 & 7) * 0x40;
  piVar4 = (int *)(*(longlong *)(param_1 + 0x9f80) + lVar5);
  if ((int)(short)piVar4[0xc] == uVar6) {
    LOCK();
    bVar7 = *piVar4 == 0;
    if (bVar7) {
      *piVar4 = 1;
    }
    UNLOCK();
    while (!bVar7) {
      do {
      } while (*(int *)(lVar5 + *(longlong *)(param_1 + 0x9f80)) != 0);
      piVar4 = (int *)(lVar5 + *(longlong *)(param_1 + 0x9f80));
      LOCK();
      bVar7 = *piVar4 == 0;
      if (bVar7) {
        *piVar4 = 1;
      }
      UNLOCK();
    }
    piVar4 = (int *)(*(longlong *)(param_1 + 0x9f80) + lVar5);
  }
  else {
    if ((param_3 != '\0') &&
       (((short)piVar4[0xc] == -1 ||
        ((*(short *)((longlong)piVar4 + 0x36) == 0 && (piVar4[1] == 0)))))) {
      LOCK();
      iVar2 = *piVar4;
      if (iVar2 == 0) {
        *piVar4 = 1;
      }
      UNLOCK();
      if (iVar2 == 0) {
        piVar1 = piVar4 + 2;
        *(short *)(piVar4 + 0xc) = (short)uVar6;
        *(undefined2 *)(piVar4 + 0xe) = 0x402;
        *(undefined1 *)((longlong)piVar4 + 0x3b) = 0x14;
        *(undefined4 *)((longlong)piVar4 + 0x32) = 0;
        *(int **)piVar1 = piVar1;
        *(int **)(piVar4 + 4) = piVar1;
        uVar3 = *(undefined8 *)(param_1 + 0x9de0);
        *(undefined1 *)((longlong)piVar4 + 0x3a) = 0xff;
        *(undefined1 *)((longlong)piVar4 + 0x3d) = 0;
        piVar4[6] = -1;
        piVar4[7] = -1;
        piVar4[8] = -1;
        piVar4[9] = -1;
        *(undefined8 *)(piVar4 + 10) = uVar3;
        goto LAB_00011458;
      }
    }
    piVar4 = (int *)0x0;
  }
LAB_00011458:
  *(undefined4 *)(param_1 + 0x9e54) = 0;
  return piVar4;
}



===== CoalescingFlushLUN @ 0001146c =====

void CoalescingFlushLUN(uint *param_1,longlong param_2,int param_3,byte param_4)

{
  longlong *plVar1;
  short sVar2;
  longlong *plVar3;
  char cVar4;
  byte bVar5;
  
  plVar1 = (longlong *)(param_2 + 8);
  do {
    plVar3 = (longlong *)*plVar1;
    if ((longlong *)*plVar3 == plVar3) {
LAB_0001151b:
      if (param_3 == 1) {
        while ((plVar1 = *(longlong **)(param_2 + 0x10), (longlong *)*plVar1 != plVar1 &&
               (*(short *)((longlong)plVar1 + 0x5c) == 1))) {
          *(longlong *)plVar1[1] = *plVar1;
          *(longlong *)(*plVar1 + 8) = plVar1[1];
          plVar1[1] = (longlong)plVar1;
          *plVar1 = (longlong)plVar1;
          *(short *)(param_2 + 0x36) = *(short *)(param_2 + 0x36) + -1;
          *(undefined1 *)(plVar1[4] + 3) = 5;
          StorPortNotification(0,param_1,plVar1[4]);
        }
      }
LAB_0001156e:
      bVar5 = *(byte *)(param_2 + 0x39);
      if ((uint)*(byte *)(param_2 + 0x39) < *(uint *)(param_2 + 4)) {
        if (0x17 < bVar5) {
          return;
        }
        bVar5 = bVar5 + 2;
      }
      else {
        if (bVar5 < 5) {
          return;
        }
        bVar5 = bVar5 - 2;
      }
      *(byte *)(param_2 + 0x39) = bVar5;
      *(byte *)(param_2 + 0x38) = bVar5 >> 1;
      return;
    }
    if (param_3 != 1) {
      if (param_3 != 0) goto LAB_0001151b;
      if ((*(longlong **)(param_2 + 0x10) == plVar3) && (4 < *(uint *)(param_2 + 4)))
      goto LAB_0001156e;
    }
    sVar2 = *(short *)((longlong)plVar3 + 0x5c);
    *(longlong *)plVar3[1] = *plVar3;
    *(longlong *)(*plVar3 + 8) = plVar3[1];
    plVar3[1] = (longlong)plVar3;
    *plVar3 = (longlong)plVar3;
    cVar4 = SubmitCissCommand(param_1,plVar3[4],(undefined8 *)plVar3[10],(ushort)param_4);
    if (cVar4 == '\0') {
      plVar3[1] = (longlong)plVar1;
      *plVar3 = *plVar1;
      *(longlong **)(*plVar1 + 8) = plVar3;
      *plVar1 = (longlong)plVar3;
      *(undefined1 *)(param_2 + 0x3a) = 0xff;
      goto LAB_0001151b;
    }
    *(short *)(param_2 + 0x36) = *(short *)(param_2 + 0x36) - sVar2;
  } while( true );
}



===== FUN_000115b8 @ 000115b8 =====

ulonglong FUN_000115b8(longlong param_1,longlong param_2,longlong param_3,uint param_4)

{
  char cVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  int iVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  
  uVar7 = (ulonglong)*(uint *)(param_3 + 0x58);
  if (*(uint *)(param_2 + 0x58) + *(uint *)(param_3 + 0x58) <= param_4) {
    lVar3 = *(longlong *)(param_2 + 0x48);
    lVar4 = *(longlong *)(param_3 + 0x48);
    uVar5 = *(ushort *)(param_1 + 0x9f5c) - 1;
    uVar7 = (ulonglong)uVar5;
    if ((int)((uint)*(byte *)(lVar4 + 1) + (uint)*(byte *)(lVar3 + 1)) <= (int)uVar5) {
      uVar5 = *(uint *)(param_2 + 0x58) & 0x1ff;
      if (uVar5 != 0) {
        if ((*(char *)(param_2 + 0x5e) == '*') ||
           (uVar7 = 0x3238, *(short *)(param_1 + 0x92f8) == 0x3238)) goto LAB_000115e1;
        lVar8 = (ulonglong)*(ushort *)(lVar3 + 2) * 0x10;
        iVar10 = 0x200 - uVar5;
        *(undefined8 *)(lVar8 + 0x34 + lVar3) = 0xffffffffffffffff;
        *(int *)(lVar8 + 0x3c + lVar3) = iVar10;
        *(undefined4 *)(lVar8 + 0x40 + lVar3) = 0;
        if (*(char *)(lVar3 + 1) != -1) {
          *(char *)(lVar3 + 1) = *(char *)(lVar3 + 1) + '\x01';
        }
        *(short *)(lVar3 + 2) = *(short *)(lVar3 + 2) + 1;
        *(int *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + iVar10;
      }
      uVar7 = (ulonglong)*(ushort *)(lVar4 + 2);
      if (uVar7 != 0) {
        puVar12 = (undefined8 *)(lVar4 + 0x34);
        do {
          lVar4 = *(longlong *)(param_2 + 0x48);
          uVar11 = (ulonglong)*(ushort *)(lVar4 + 2);
          *(undefined8 *)(lVar4 + 0x34 + uVar11 * 0x10) = *puVar12;
          uVar2 = *(undefined4 *)(puVar12 + 1);
          *(undefined4 *)(lVar4 + 0x40 + uVar11 * 0x10) = 0;
          *(undefined4 *)(lVar4 + 0x3c + uVar11 * 0x10) = uVar2;
          if (*(char *)(lVar4 + 1) != -1) {
            *(char *)(lVar4 + 1) = *(char *)(lVar4 + 1) + '\x01';
          }
          *(short *)(lVar4 + 2) = *(short *)(lVar4 + 2) + 1;
          puVar12 = puVar12 + 2;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      *(short *)(param_2 + 0x5c) = *(short *)(param_2 + 0x5c) + *(short *)(param_3 + 0x5c);
      *(int *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + *(int *)(param_3 + 0x58);
      uVar9 = *(undefined8 *)(param_3 + 0x40);
      *(undefined8 *)(param_2 + 0x40) = uVar9;
      *(undefined2 *)(param_3 + 0x5c) = 0;
      *(undefined4 *)(param_3 + 0x58) = 0;
      cVar1 = *(char *)(param_2 + 0x5e);
      if ((cVar1 == '(') || (cVar1 == '*')) {
        uVar5 = *(uint *)(param_2 + 0x58) >> 9;
        *(char *)(lVar3 + 0x20) = (char)uVar5;
        *(char *)(lVar3 + 0x1f) = (char)(uVar5 >> 8);
      }
      else if ((cVar1 == -0x78) || (cVar1 == -0x76)) {
        uVar5 = *(uint *)(param_2 + 0x58);
        uVar6 = uVar5 >> 9;
        *(char *)(lVar3 + 0x25) = (char)uVar6;
        *(char *)(lVar3 + 0x24) = (char)(uVar6 >> 8);
        *(byte *)(lVar3 + 0x23) = (byte)(uVar5 >> 0x19);
        uVar9 = 0;
        *(undefined1 *)(lVar3 + 0x22) = 0;
      }
      return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
    }
  }
LAB_000115e1:
  return uVar7 & 0xffffffffffffff00;
}



===== CoalescingFlushAllLUNs @ 0001173c =====

void CoalescingFlushAllLUNs(uint *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  longlong lVar4;
  
  uVar2 = param_1[0x27d9];
  lVar4 = 0;
  do {
    piVar3 = (int *)(*(longlong *)(param_1 + 0x27e0) + lVar4);
    if ((short)piVar3[0xc] != -1) {
      while( true ) {
        LOCK();
        iVar1 = *piVar3;
        if (iVar1 == 0) {
          *piVar3 = 1;
        }
        UNLOCK();
        if (iVar1 == 0) break;
        do {
        } while (*piVar3 != 0);
      }
      CoalescingFlushLUN(param_1,(longlong)piVar3,1,(byte)uVar2 >> 5 & 1);
      *piVar3 = 0;
    }
    lVar4 = lVar4 + 0x40;
  } while (lVar4 < 0x200);
  return;
}



===== CissStartIO @ 000117d8 =====

undefined8 CissStartIO(uint *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  char *pcVar3;
  byte bVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined8 uVar7;
  void *_Dst;
  bool bVar8;
  char cVar9;
  ulonglong uVar10;
  int *piVar11;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  ulonglong uVar12;
  longlong lVar13;
  uint *puVar14;
  uint uVar15;
  char *pcVar16;
  byte bVar17;
  longlong *plVar18;
  uint uVar19;
  
  bVar17 = (byte)param_1[0x27d9] >> 5 & 1;
  uVar19 = param_1[0x24e6] & 2;
  if ((uVar19 == 0) || (*(char *)(param_2 + 2) == '\x02')) {
    if (*(char *)(param_2 + 0x48) == '5') {
      if ((*param_1 & 0x10000000) != 0) {
        uVar12 = CissFlushCache(param_1,param_2);
        goto LAB_00011c8e;
      }
LAB_00012042:
      CoalescingFlushAllLUNs(param_1);
      goto LAB_00012047;
    }
    bVar4 = *(byte *)(param_2 + 2);
    if (bVar4 < 0x13) {
      if (bVar4 == 0x12) {
        CoalescingFlushAllLUNs(param_1);
        if ((*param_1 & 0x10000000) == 0) {
          uVar12 = CissResetBus((longlong)param_1,param_2,(uint)*(byte *)(param_2 + 5));
          goto LAB_00011c8e;
        }
      }
      else if (bVar4 < 7) {
        if (bVar4 < 4) {
          if (bVar4 == 0) {
            if ((*(char *)(param_2 + 0x48) == -0x60) &&
               (uVar12 = HandleScsiReportLunCmd((longlong)param_1,param_2), (char)uVar12 != '\0'))
            goto LAB_00011c8e;
            if (*(byte *)(param_2 + 5) < 7) {
              if (*(char *)(param_2 + 7) == '\0') {
                uVar19 = (uint)*(byte *)(param_2 + 5) * 0x80 + (uint)*(byte *)(param_2 + 6);
              }
              else {
                uVar19 = 0xffffffff;
              }
              if (uVar19 != 0xffffffff) {
                uVar10 = (ulonglong)uVar19;
                uVar19 = param_1[uVar10 * 7 + 0x65];
                uVar12 = (ulonglong)uVar19;
                uVar15 = uVar19 >> 7 & 1;
                if ((uVar15 == 0) && ((uVar19 & 0x100) == 0)) {
                  if ((uVar19 >> 0xc & 1) == 0) {
                    if ((uVar19 >> 9 & 1) == 0) {
                      if ((uVar19 >> 10 & 1) == 0) {
                        if ((uVar19 & 0x20) != 0) goto LAB_00011f9e;
                        if (((uVar19 & 0x10) == 0) && ((uVar19 & 0x40) == 0)) goto LAB_00011c8e;
                      }
                      else if (*(char *)(param_2 + 0x48) == '\x12') {
                        StorPortBusy(param_1,0xffffffff);
                        puVar14 = param_1 + 0x81;
                        lVar13 = 0x37c;
                        do {
                          if ((char)*puVar14 < '\0') {
                            *puVar14 = *puVar14 & 0xffffff7f | 0x20;
                          }
                          puVar14 = puVar14 + 7;
                          lVar13 = lVar13 + -1;
                        } while (lVar13 != 0);
                        puVar14 = param_1 + 0x18e7;
                        lVar13 = 0x8c;
                        do {
                          if ((char)*puVar14 < '\0') {
                            *puVar14 = *puVar14 & 0xffffff7f | 0x20;
                          }
                          puVar14 = puVar14 + 7;
                          lVar13 = lVar13 + -1;
                        } while (lVar13 != 0);
                        uVar12 = CissSendReportPhysicalLuns(param_1,param_2);
                        goto LAB_00011c8e;
                      }
                    }
                    else if (*(char *)(param_2 + 0x48) == '\x12') {
                      StorPortBusy(param_1,0xffffffff);
                      puVar14 = param_1 + 0x81;
                      lVar13 = 0x37c;
                      do {
                        if ((*puVar14 & 0x100) != 0) {
                          *puVar14 = *puVar14 & 0xfffffeff | 0x20;
                        }
                        puVar14 = puVar14 + 7;
                        lVar13 = lVar13 + -1;
                      } while (lVar13 != 0);
                      uVar12 = CissSendReportLogicalLuns(param_1,param_2);
                      goto LAB_00011c8e;
                    }
                  }
                  else if (*(char *)(param_2 + 0x48) == '\x12') {
                    uVar12 = CissScanMessage(param_1,param_2);
                    goto LAB_00011c8e;
                  }
                }
                else {
                  if (*(char *)(param_2 + 0x48) != -0x60) {
                    if (((uVar19 & 0x100) == 0) || (-1 < (char)param_1[0x27d9])) {
                      cVar9 = SubmitCissCommand(param_1,param_2,
                                                (undefined8 *)(param_1 + uVar10 * 7 + 0x66),
                                                (ushort)param_1[0x27d9] >> 5 & 1);
                      uVar12 = CONCAT71(extraout_var_00,cVar9);
                      if (cVar9 != '\0') goto LAB_00011c8e;
LAB_00011f9e:
                      *(undefined1 *)(param_2 + 3) = 5;
                      goto LAB_00011fd6;
                    }
                    *(uint **)(*(longlong *)(param_2 + 0x38) + 0xb0) = param_1 + uVar10 * 7 + 0x66;
                    lVar13 = *(longlong *)(param_2 + 0x38);
                    plVar18 = (longlong *)(lVar13 + 0x60);
                    cVar9 = *(char *)(lVar13 + 0xbe);
                    bVar17 = (byte)param_1[0x27d9] >> 5 & 1;
                    piVar11 = FUN_0001135c((longlong)param_1,param_2,'\x01');
                    if (piVar11 == (int *)0x0) {
                      *(undefined1 *)(lVar13 + 0xbf) = 0;
                      cVar9 = SubmitCissCommand(param_1,param_2,*(undefined8 **)(lVar13 + 0xb0),
                                                (ushort)bVar17);
                      uVar12 = CONCAT71(extraout_var,cVar9);
                      if (cVar9 == '\0') {
                        *(undefined1 *)(param_2 + 3) = 5;
                        uVar12 = StorPortNotification(0,param_1,param_2);
                      }
                      goto LAB_00011c8e;
                    }
                    *(int **)(lVar13 + 0x90) = piVar11;
                    *(short *)((longlong)piVar11 + 0x36) = *(short *)((longlong)piVar11 + 0x36) + 1;
                    if (*(char *)(lVar13 + 0xbf) == '\0') {
                      *plVar18 = (longlong)(piVar11 + 2);
                      *(undefined8 *)(lVar13 + 0x68) = *(undefined8 *)(piVar11 + 4);
                      **(undefined8 **)(piVar11 + 4) = plVar18;
                      *(longlong **)(piVar11 + 4) = plVar18;
                      CoalescingFlushLUN(param_1,(longlong)piVar11,1,bVar17);
                      uVar12 = 0xffffffffffffffff;
                      *(undefined1 *)((longlong)piVar11 + 0x3d) = 0;
                      piVar11[8] = -1;
                      piVar11[9] = -1;
                      piVar11[6] = -1;
                      piVar11[7] = -1;
                    }
                    else {
                      bVar4 = 0;
                      if (((*(char *)((longlong)piVar11 + 0x3a) == -1) ||
                          (cVar9 != *(char *)((longlong)piVar11 + 0x3a))) || ((uint)piVar11[1] < 4))
                      {
                        *plVar18 = (longlong)(piVar11 + 2);
                        *(undefined8 *)(lVar13 + 0x68) = *(undefined8 *)(piVar11 + 4);
                        **(undefined8 **)(piVar11 + 4) = plVar18;
                        *(longlong **)(piVar11 + 4) = plVar18;
                        *(char *)((longlong)piVar11 + 0x3a) = cVar9;
                        *(undefined8 *)(piVar11 + 6) = *(undefined8 *)(lVar13 + 0x98);
                        uVar7 = *(undefined8 *)(lVar13 + 0xa0);
                        *(undefined1 *)((longlong)piVar11 + 0x3d) = 0;
                        *(undefined8 *)(piVar11 + 8) = uVar7;
LAB_00011f45:
                        bVar4 = 1;
                      }
                      else if (*(short *)((longlong)piVar11 + 0x36) == 1) {
                        if (*(char *)((longlong)piVar11 + 0x3d) == '\0') {
                          if ((*(longlong *)(piVar11 + 8) == *(longlong *)(lVar13 + 0x98)) ||
                             (*(longlong *)(piVar11 + 6) == *(longlong *)(lVar13 + 0xa0))) {
                            *(undefined1 *)((longlong)piVar11 + 0x3d) = 1;
                            bVar4 = 0;
                          }
                          else {
                            bVar4 = 1;
                          }
                          *(undefined8 *)(piVar11 + 6) = *(undefined8 *)(lVar13 + 0x98);
                          *(undefined8 *)(piVar11 + 8) = *(undefined8 *)(lVar13 + 0xa0);
                          *plVar18 = (longlong)(piVar11 + 2);
                          *(undefined8 *)(lVar13 + 0x68) = *(undefined8 *)(piVar11 + 4);
                          **(undefined8 **)(piVar11 + 4) = plVar18;
                          *(longlong **)(piVar11 + 4) = plVar18;
                        }
                        else {
                          *plVar18 = (longlong)(piVar11 + 2);
                          *(undefined8 *)(lVar13 + 0x68) = *(undefined8 *)(piVar11 + 4);
                          **(undefined8 **)(piVar11 + 4) = plVar18;
                          *(longlong **)(piVar11 + 4) = plVar18;
                          *(char *)((longlong)piVar11 + 0x3a) = cVar9;
                        }
                      }
                      else {
                        plVar1 = (longlong *)(piVar11 + 2);
                        plVar6 = (longlong *)*plVar1;
                        if ((plVar6[7] == *(longlong *)(lVar13 + 0xa0)) &&
                           (plVar6[8] == *(longlong *)(lVar13 + 0x98))) {
LAB_00011dc1:
                          *(undefined1 *)((longlong)piVar11 + 0x3d) = 0;
                          *(undefined8 *)(piVar11 + 6) = *(undefined8 *)(lVar13 + 0x98);
                          *(undefined8 *)(piVar11 + 8) = *(undefined8 *)(lVar13 + 0xa0);
                          *plVar18 = (longlong)plVar1;
                          *(undefined8 *)(lVar13 + 0x68) = *(undefined8 *)(piVar11 + 4);
                          **(undefined8 **)(piVar11 + 4) = plVar18;
                          *(longlong **)(piVar11 + 4) = plVar18;
                          goto LAB_00011f45;
                        }
                        bVar4 = 0;
                        if (plVar6[8] == *(longlong *)(lVar13 + 0x98)) {
                          if (*(char *)((longlong)plVar6 + 0x5f) == '\x01') {
                            uVar19 = param_1[0x2799];
                          }
                          else {
                            uVar19 = param_1[0x279a];
                          }
                          uVar12 = FUN_000115b8((longlong)param_1,(longlong)plVar6,(longlong)plVar18
                                                ,uVar19);
                          if ((char)uVar12 != '\x01') {
LAB_00011efb:
                            *plVar18 = (longlong)plVar1;
                            *(undefined8 *)(lVar13 + 0x68) = *(undefined8 *)(piVar11 + 4);
                            **(undefined8 **)(piVar11 + 4) = plVar18;
                            *(longlong **)(piVar11 + 4) = plVar18;
                            goto LAB_00011f4b;
                          }
                          plVar18 = (longlong *)(lVar13 + 0x70);
                          *plVar18 = (longlong)(plVar6 + 2);
                          *(longlong *)(lVar13 + 0x78) = plVar6[3];
                          *(longlong **)plVar6[3] = plVar18;
                          plVar6[3] = (longlong)plVar18;
                          bVar8 = *(ushort *)((longlong)plVar6 + 0x5c) <
                                  (ushort)*(byte *)(piVar11 + 0xe);
                        }
                        else {
                          if (plVar6[7] != *(longlong *)(lVar13 + 0xa0)) goto LAB_00011dc1;
                          if (*(char *)((longlong)plVar6 + 0x5f) == '\x01') {
                            uVar19 = param_1[0x2799];
                          }
                          else {
                            uVar19 = param_1[0x279a];
                          }
                          uVar12 = FUN_000115b8((longlong)param_1,(longlong)plVar18,(longlong)plVar6
                                                ,uVar19);
                          if ((char)uVar12 != '\x01') goto LAB_00011efb;
                          plVar2 = (longlong *)(lVar13 + 0x70);
                          *(longlong **)plVar6[3] = plVar2;
                          *(longlong *)(*(longlong *)(lVar13 + 0x78) + 8) = plVar6[3];
                          *plVar2 = (longlong)(plVar6 + 2);
                          plVar6[3] = (longlong)plVar2;
                          *plVar18 = (longlong)plVar1;
                          *(undefined8 *)(lVar13 + 0x68) = *(undefined8 *)(piVar11 + 4);
                          **(undefined8 **)(piVar11 + 4) = plVar18;
                          *(longlong **)(piVar11 + 4) = plVar18;
                          *(longlong *)plVar6[1] = *plVar6;
                          *(longlong *)(*plVar6 + 8) = plVar6[1];
                          plVar6[1] = (longlong)plVar6;
                          *plVar6 = (longlong)plVar6;
                          bVar8 = *(ushort *)(lVar13 + 0xbc) < (ushort)*(byte *)(piVar11 + 0xe);
                        }
                        if (!bVar8) {
                          bVar4 = 1;
                        }
                      }
LAB_00011f4b:
                      uVar12 = CoalescingFlushLUN(param_1,(longlong)piVar11,(uint)bVar4,bVar17);
                    }
                    *piVar11 = 0;
                    goto LAB_00011c8e;
                  }
                  puVar5 = *(undefined8 **)(param_2 + 0x20);
                  if ((uVar15 != 0) || ((uVar19 & 0x100) != 0)) {
                    *(undefined2 *)(param_2 + 3) = 0x204;
                    if (*(char *)(param_2 + 0xb) != '\0') {
                      *(undefined1 *)(param_2 + 3) = 0x84;
                      *puVar5 = 0;
                      puVar5[1] = 0;
                      *(undefined2 *)(puVar5 + 2) = 0;
                      *(undefined1 *)puVar5 = 0xf0;
                      *(byte *)((longlong)puVar5 + 2) = *(byte *)((longlong)puVar5 + 2) & 0xf5 | 5;
                    }
                    goto LAB_00011fd6;
                  }
                }
              }
            }
            else {
              bVar17 = *(byte *)(param_2 + 6);
              if (((((0x1b < bVar17) && (99 < bVar17)) && (*(char *)(param_2 + 7) == '\0')) &&
                  ((*(char *)(param_2 + 0x48) == '\x12' && (*(longlong *)(param_1 + 0x2828) != 0))))
                 && (((param_1[0x27d9] & 0x10) == 0 && ((bVar17 == 100 || (bVar17 == 0x65)))))) {
                _Dst = *(void **)(param_2 + 0x38);
                memset(_Dst,0,0x60);
                *(longlong *)((longlong)_Dst + 0x58) = param_2;
              }
            }
            *(undefined1 *)(param_2 + 3) = 10;
            goto LAB_00011fd6;
          }
          if (bVar4 != 1) {
            if (bVar4 == 2) {
              lVar13 = *(longlong *)(param_2 + 0x18);
              pcVar16 = "CPQCSMI";
              do {
                pcVar3 = pcVar16 + lVar13 + -0x1b55c;
                cVar9 = *pcVar16;
                pcVar16 = pcVar16 + 1;
                if (*pcVar3 != cVar9) {
                  pcVar16 = "CPQCISS";
                  goto LAB_000118e3;
                }
              } while (*pcVar3 != '\0');
              CsmiProcessIoctl((longlong)param_1,lVar13);
              goto LAB_00012047;
            }
            if (bVar4 != 3) goto LAB_000120aa;
          }
        }
LAB_00011896:
        *(undefined1 *)(param_2 + 3) = 6;
      }
      else {
        if ((bVar4 == 7) || (bVar4 == 8)) goto LAB_00012042;
        if (bVar4 - 0x10 < 2) goto LAB_00011896;
LAB_000120aa:
        *(undefined1 *)(param_2 + 3) = 0x22;
      }
      goto LAB_00011fd6;
    }
    if (bVar4 == 0x13) {
      piVar11 = FUN_0001135c((longlong)param_1,param_2,'\0');
      if (piVar11 != (int *)0x0) {
        if (*(short *)((longlong)piVar11 + 0x36) != 0) {
          CoalescingFlushLUN(param_1,(longlong)piVar11,1,bVar17);
        }
        *piVar11 = 0;
      }
      uVar12 = CissResetTarget((longlong)param_1,param_2);
      goto LAB_00011c8e;
    }
    if ((bVar4 == 0x14) || (bVar4 == 0x15)) goto LAB_00011896;
    if (bVar4 == 0x17) {
      uVar12 = CissWmiSrb((longlong)param_1,param_2);
      goto LAB_00011c8e;
    }
    if (bVar4 == 0x20) {
      piVar11 = FUN_0001135c((longlong)param_1,param_2,'\0');
      if (piVar11 != (int *)0x0) {
        if (*(short *)((longlong)piVar11 + 0x36) != 0) {
          CoalescingFlushLUN(param_1,(longlong)piVar11,1,bVar17);
        }
        *piVar11 = 0;
      }
      uVar12 = CissResetLogicalUnit(param_1,param_2);
      goto LAB_00011c8e;
    }
    if (bVar4 == 0x24) {
      if (*(int *)(param_2 + 8) - 2U < 3) {
        CoalescingFlushAllLUNs(param_1);
        param_1[0x27de] = 3;
LAB_000120f9:
        StorPortSynchronizeAccess(param_1,SynchronizeTimerShutdown,0);
        StorPortNotification(6,param_1,TimerTick);
        CissCancelNotifyOnEvent(param_1);
        CissFlushCache(param_1,param_2);
        uVar12 = 0xff7f;
        *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] & 0xff7f;
        goto LAB_00011c8e;
      }
    }
    else {
      if (bVar4 != 0x25) goto LAB_000120aa;
      if (((*(int *)(param_2 + 8) - 2U & 0xfffffffd) == 0) && ((param_1[0x24e6] >> 0xc & 1) == 0)) {
        CoalescingFlushAllLUNs(param_1);
        param_1[0x27de] = 2;
        goto LAB_000120f9;
      }
    }
    goto LAB_00012047;
  }
  *(undefined1 *)(param_2 + 3) = 0x11;
  goto LAB_00011fd6;
  while (*pcVar3 != '\0') {
LAB_000118e3:
    pcVar3 = pcVar16 + lVar13 + -0x1b56c;
    cVar9 = *pcVar16;
    pcVar16 = pcVar16 + 1;
    if (*pcVar3 != cVar9) {
      pcVar16 = "CSMIALL";
      goto LAB_00011916;
    }
  }
  uVar12 = CsmiCissProcessIoctl(param_1,param_2);
  goto LAB_00011c8e;
  while (*pcVar3 != '\0') {
LAB_00011916:
    pcVar3 = pcVar16 + lVar13 + -0x1b57c;
    cVar9 = *pcVar16;
    pcVar16 = pcVar16 + 1;
    if (*pcVar3 != cVar9) {
      pcVar16 = "CSMIARY";
      goto LAB_00011949;
    }
  }
  uVar12 = ProcessCsmiAllIoctls((longlong)param_1,param_2);
  goto LAB_00011c8e;
  while (*pcVar3 != '\0') {
LAB_00011949:
    pcVar3 = pcVar16 + lVar13 + -0x1b58c;
    cVar9 = *pcVar16;
    pcVar16 = pcVar16 + 1;
    if (*pcVar3 != cVar9) {
      pcVar16 = "CSMISAS";
      goto LAB_000119bd;
    }
  }
  bVar8 = VerifySecurity((longlong)param_1,'\x04',0,*(uint *)(lVar13 + 0x10));
  if (!bVar8) goto LAB_00011974;
  if (uVar19 == 0) {
    *(undefined4 *)(lVar13 + 0x14) = 2;
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
LAB_0001198b:
    *(undefined1 *)(param_2 + 3) = 0x11;
  }
  goto LAB_00011fd6;
  while (*pcVar3 != '\0') {
LAB_000119bd:
    pcVar3 = pcVar16 + lVar13 + -0x1b59c;
    cVar9 = *pcVar16;
    pcVar16 = pcVar16 + 1;
    if (*pcVar3 != cVar9) {
      pcVar16 = "CSMIPHY";
      goto LAB_000119f0;
    }
  }
  uVar12 = ProcessCsmiSasIoctls(param_1,param_2);
  goto LAB_00011c8e;
  while (*pcVar3 != '\0') {
LAB_000119f0:
    pcVar3 = pcVar16 + lVar13 + -0x1b5ac;
    cVar9 = *pcVar16;
    pcVar16 = pcVar16 + 1;
    if (*pcVar3 != cVar9) goto LAB_00011896;
  }
  bVar8 = VerifySecurity((longlong)param_1,'\x04',0,*(uint *)(lVar13 + 0x10));
  if (bVar8) {
    if (uVar19 != 0) goto LAB_0001198b;
    *(undefined4 *)(lVar13 + 0x14) = 2;
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
LAB_00011974:
    *(undefined4 *)(lVar13 + 0x14) = 4;
LAB_00012047:
    *(undefined1 *)(param_2 + 3) = 1;
  }
LAB_00011fd6:
  uVar12 = StorPortNotification(0,param_1,param_2);
LAB_00011c8e:
  return CONCAT71((int7)(uVar12 >> 8),1);
}



===== BuildStatus_IllegalRequest @ 000121e0 =====

void BuildStatus_IllegalRequest(undefined8 param_1,longlong param_2,undefined1 param_3)

{
  undefined1 *_Dst;
  
  _Dst = *(undefined1 **)(param_2 + 0x20);
  *(undefined2 *)(param_2 + 3) = 0x204;
  if ((_Dst != (undefined1 *)0x0) && (0x11 < *(byte *)(param_2 + 0xb))) {
    memset(_Dst,0,(ulonglong)*(byte *)(param_2 + 0xb));
    *_Dst = 0xf0;
    _Dst[7] = 10;
    _Dst[0xc] = param_3;
    _Dst[2] = _Dst[2] & 0xf5 | 5;
    *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) | 0x80;
    *(undefined1 *)(param_2 + 0xb) = 0x12;
  }
  return;
}



===== SynchronizeSubmit @ 0001224c =====

undefined8 SynchronizeSubmit(uint *param_1,longlong param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  uint uVar6;
  
  puVar2 = *(undefined1 **)(*(longlong *)(param_2 + 8) + 0x48);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 8) + 0x20);
  while( true ) {
    uVar5 = 0;
    LOCK();
    uVar6 = param_1[0x18e5];
    if (uVar6 == 0) {
      param_1[0x18e5] = 1;
    }
    else {
      uVar5 = (ulonglong)uVar6;
    }
    UNLOCK();
    if (uVar6 == 0) break;
    do {
    } while (param_1[0x18e5] != 0);
  }
  puVar4 = *(undefined8 **)(param_1 + 0x250c);
  if (puVar4 == *(undefined8 **)(param_1 + 0x2776)) {
    LOCK();
    param_1[6] = param_1[6] - 1;
    UNLOCK();
    *(undefined1 *)(param_2 + 0x10) = 0;
    param_1[0x18e5] = 0;
  }
  else {
    *(undefined8 *)(param_1 + 0x250c) = *(undefined8 *)(*(longlong *)(param_1 + 0x250c) + 8);
    if ((*param_1 & 0x10000000) == 0) {
      *puVar2 = *(undefined1 *)(*(longlong *)(param_2 + 8) + 0x9c);
    }
    else {
      *puVar2 = 0;
    }
    puVar4[1] = 0;
    uVar6 = (int)((ulonglong)((longlong)puVar4 + (-0x72f0 - (longlong)param_1)) >> 4) * 4 + 4;
    *puVar4 = *(undefined8 *)(param_2 + 8);
    *(uint *)(puVar2 + 4) = uVar6;
    if (((*(char *)(lVar3 + 0x48) == '\'') && (*(char *)(lVar3 + 0x4e) == -0x3e)) &&
       (*(char *)(*(longlong *)(param_1 + 0x24fa) + 0x438) != '\0')) {
      *(uint *)(puVar2 + 4) = uVar6 | 0x10000000;
    }
    lVar3 = *(longlong *)(*(longlong *)(param_2 + 8) + 0x30);
    if (lVar3 != 0) {
      LOCK();
      piVar1 = (int *)(lVar3 + 4);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    uVar5 = (**(code **)(param_1 + 0x56))
                      (param_1,param_2,*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x48));
    param_1[0x18e5] = 0;
    *(undefined1 *)(param_2 + 0x10) = 1;
  }
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== SubmitCissCommand @ 00012380 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 SubmitCissCommand(uint *param_1,longlong param_2,undefined8 *param_3,short param_4)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_78 [32];
  longlong local_58;
  longlong local_50;
  undefined1 local_48;
  undefined8 local_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  lVar1 = *(longlong *)(param_2 + 0x38);
  local_40 = 0x1000000000;
  local_50 = lVar1 + 0x60;
  if (*(int *)(lVar1 + 0xf8) == 0) {
    uVar4 = param_1[0x277b] - 8;
  }
  else {
    uVar4 = param_1[0x277b] - 2;
  }
  if (param_1[6] < uVar4) {
    LOCK();
    param_1[6] = param_1[6] + 1;
    UNLOCK();
    lVar2 = *(longlong *)(lVar1 + 0xa8);
    if (((*(int *)(lVar1 + 0xf8) == 0) &&
        (iVar3 = StorPortExtendedFunction(0xf,param_1,param_2,&local_40), iVar3 == 0)) &&
       ((uint)local_38 < *(byte *)((longlong)param_1 + 2))) {
      *(longlong *)(local_50 + 0x9c) = (longlong)(char)local_38;
    }
    *(undefined8 *)(lVar2 + 0xc) = *param_3;
    local_58 = (*(longlong *)(lVar2 + 0x28) - local_50) + -0x60 + lVar2;
    if (param_4 == 0) {
      StorPortSynchronizeAccess(param_1,SynchronizeSubmit,&local_58);
    }
    else {
      SynchronizeSubmit(param_1,(longlong)&local_58);
    }
  }
  else {
    StorPortBusy(param_1,param_1[0x277b] >> 1);
    local_48 = 0;
  }
  return local_48;
}



===== HandleScsiReportLunCmd @ 000124b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 HandleScsiReportLunCmd(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  ulonglong _Size;
  undefined8 uVar3;
  byte bVar4;
  longlong *plVar5;
  longlong *_Dst;
  ulonglong uVar6;
  undefined1 uVar7;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  longlong local_40 [3];
  
  local_40[2] = __security_cookie ^ (ulonglong)auStack_68;
  bVar4 = *(byte *)(param_2 + 5);
  _Size = CONCAT71((int7)((ulonglong)local_40[2] >> 8),0xff);
  uVar6 = 0;
  if (((bVar4 == 0xff) && (*(char *)(param_2 + 6) == -1)) && (*(char *)(param_2 + 7) == -1))
  goto LAB_000124f0;
  bVar1 = *(byte *)(param_2 + 0x4a);
  plVar5 = (longlong *)CONCAT71((int7)((ulonglong)param_1 >> 8),bVar1);
  if (2 < bVar1) {
    uVar7 = 0x24;
LAB_00012502:
    BuildStatus_IllegalRequest(plVar5,param_2,uVar7);
    goto LAB_0001271d;
  }
  local_48 = CONCAT13(*(undefined1 *)(param_2 + 0x4e),
                      CONCAT12(*(undefined1 *)(param_2 + 0x4f),
                               CONCAT11(*(undefined1 *)(param_2 + 0x50),
                                        *(undefined1 *)(param_2 + 0x51))));
  _Size = (ulonglong)local_48;
  if (local_48 != 0) {
    _Dst = *(longlong **)(param_2 + 0x18);
    if (_Dst == (longlong *)0x0) goto LAB_0001271d;
    local_40[1] = 0;
    if (bVar1 != 1) {
      if (bVar4 < 7) {
        if (*(char *)(param_2 + 7) == '\0') {
          plVar5 = (longlong *)(ulonglong)*(byte *)(param_2 + 6);
          uVar6 = (ulonglong)((uint)bVar4 * 0x80 + (uint)*(byte *)(param_2 + 6));
        }
        else {
          uVar6 = 0xffffffff;
        }
        if ((int)uVar6 == -1) {
          local_40[0] = 0;
          local_40[1] = 0;
          if (local_48 < 0x10) {
            memset(_Dst,0,_Size);
            memcpy(_Dst,local_40,_Size);
            plVar5 = _Dst;
          }
          else {
            *_Dst = 0;
            _Dst[1] = 0;
          }
          uVar7 = 0x25;
          goto LAB_00012502;
        }
      }
      if ((bVar4 == 0) &&
         (((*(char *)(param_2 + 6) == '\0' && (*(char *)(param_2 + 7) == '\0')) ||
          ((*(byte *)(param_2 + 6) < 4 && (*(char *)(param_2 + 7) == '\0')))))) {
LAB_0001261a:
        bVar4 = 8;
LAB_0001261c:
        local_40[0] = (ulonglong)bVar4 << 0x18;
      }
      else {
        if (bVar4 == 7) {
          bVar4 = *(byte *)(param_2 + 6);
          if (bVar4 < 0x80) {
            uVar6 = (ulonglong)((uint)bVar4 * 5 + (uint)*(byte *)(param_2 + 7));
          }
          else {
            uVar6 = 0xffffffff;
          }
          if ((uint)uVar6 == 0xffffffff) {
            local_40[0] = 0;
            local_40[1] = 0;
            if (local_48 < 0x10) goto LAB_00012568;
            *_Dst = 0;
            _Dst[1] = 0;
            goto LAB_0001252e;
          }
          if (((uint)uVar6 < 0x8c) &&
             ((char)*(undefined4 *)(uVar6 * 0x1c + 0x639c + param_1) < '\0')) goto LAB_000124f0;
          if ((byte)(bVar4 + 0x9c) < 2) goto LAB_0001261a;
        }
        else {
          uVar2 = *(uint *)(uVar6 * 0x1c + 0x194 + param_1);
          if ((uVar2 >> 8 & 1) != 0) {
            bVar4 = 8;
            if (*(char *)(param_2 + 0x53) == '\x01') {
              bVar4 = 0;
            }
            goto LAB_0001261c;
          }
          if ((char)uVar2 < '\0') {
LAB_000124f0:
            return _Size & 0xffffffffffffff00;
          }
        }
        local_40[0] = 0;
      }
      local_40[1] = 0;
      *(undefined2 *)(param_2 + 3) = 1;
      if (local_48 < 0x10) {
        memset(_Dst,0,_Size);
        memcpy(_Dst,local_40,_Size);
      }
      else {
        *_Dst = local_40[0];
        _Dst[1] = 0;
      }
      goto LAB_0001271d;
    }
    local_40[0] = 0;
    if (local_48 < 4) {
LAB_00012568:
      local_40[1] = 0;
      local_40[0] = 0;
      memset(_Dst,0,_Size);
      memcpy(_Dst,local_40,_Size);
    }
    else {
      *(undefined4 *)_Dst = 0;
    }
  }
LAB_0001252e:
  *(undefined2 *)(param_2 + 3) = 1;
LAB_0001271d:
  uVar3 = StorPortNotification(0,param_1,param_2);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== CissCompletion @ 00012754 =====

undefined * CissCompletion(uint *param_1,uint param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  ulonglong uVar6;
  bool bVar7;
  ushort uVar8;
  uint uVar9;
  code *pcVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  ulonglong *puVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  uint *puVar17;
  longlong *plVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_58;
  undefined4 local_54;
  longlong *local_50;
  uint *local_48;
  
  pcVar10 = (code *)(ulonglong)param_1[0x24e6];
  bVar7 = false;
  plVar18 = (longlong *)0x0;
  if (((param_1[0x24e6] & 2) == 0) &&
     (((param_2 >> 0x1c & 1) == 0 ||
      (pcVar10 = *(code **)(param_1 + 0x24fa), pcVar10[0x438] != (code)0x0)))) {
    LOCK();
    param_1[6] = param_1[6] - 1;
    UNLOCK();
    uVar12 = (ulonglong)((param_2 >> 2 & 0x3bffffff) - 1);
    puVar13 = (ulonglong *)(param_1 + (uVar12 + 0x72f) * 4);
    plVar4 = (longlong *)*puVar13;
    *puVar13 = uVar12;
    puVar13[1] = 0;
    pbVar1 = (byte *)(plVar4 + 0xc);
    *(ulonglong **)(*(longlong *)(param_1 + 0x2776) + 8) = puVar13;
    *(undefined8 *)(param_1 + 0x2776) = *(undefined8 *)(*(longlong *)(param_1 + 0x2776) + 8);
    local_48 = (uint *)plVar4[6];
    plVar16 = plVar4;
    if ((longlong *)plVar4[2] != plVar4 + 2) {
      plVar18 = (longlong *)plVar4[3];
      plVar16 = plVar18 + -2;
    }
    plVar14 = plVar4;
    uVar19 = 0;
    local_50 = plVar4;
    do {
      uVar20 = 6;
      uVar8 = *(ushort *)((longlong)plVar4 + 0x62);
      pcVar10 = (code *)(ulonglong)uVar8;
      puVar17 = (uint *)plVar16[4];
      iVar3 = (int)plVar16[0x13];
      if (uVar8 == 0) {
        *(undefined2 *)((longlong)puVar17 + 3) = 1;
        uVar20 = uVar19;
LAB_000129bd:
        plVar14 = local_50;
        if ((iVar3 == 0) && ((char)puVar17[0x12] == -0x62)) {
          lVar5 = *(longlong *)(puVar17 + 6);
          uVar8 = (short)param_1[0x24be] + 0xcdd0;
          pcVar10 = (code *)(ulonglong)uVar8;
          if (((uVar8 & 0xfff5) == 0) &&
             (pcVar10 = (code *)0x3232, (short)param_1[0x24be] != 0x3232)) {
            if ((puVar17[4] < 0xf) ||
               (uVar9 = *(byte *)(lVar5 + 0xd) & 0xf, pcVar10 = (code *)(ulonglong)uVar9,
               ((*(byte *)(lVar5 + 0xe) & 0x3f) << 8 | (uint)*(byte *)(lVar5 + 0xf)) <=
               (uint)(1 << (sbyte)uVar9))) goto LAB_00012a50;
            pcVar10 = memset((void *)(lVar5 + 0xc),0,(ulonglong)(puVar17[4] - 0xc));
          }
          plVar14 = local_50;
        }
      }
      else {
        if (uVar8 < 7) {
          if (uVar8 != 6) {
            if (uVar8 == 1) {
              *(undefined1 *)((longlong)puVar17 + 3) = 4;
              pcVar10 = (code *)(ulonglong)*pbVar1;
              *(byte *)(puVar17 + 1) = *pbVar1;
              if ((iVar3 == 0) &&
                 (pcVar10 = (code *)((ulonglong)*(byte *)((longlong)plVar4 + 0x72) &
                                    0xffffffffffffff0f), (char)pcVar10 == '\x03')) {
                if (*(char *)((longlong)puVar17 + 7) == '\0') {
                  uVar9 = (uint)*(byte *)((longlong)puVar17 + 5) * 0x80 +
                          (uint)*(byte *)((longlong)puVar17 + 6);
                }
                else {
                  uVar9 = 0xffffffff;
                }
                pcVar10 = (code *)(ulonglong)param_1[(ulonglong)uVar9 * 7 + 0x65];
                if ((param_1[(ulonglong)uVar9 * 7 + 0x65] >> 8 & 1) != 0) {
                  *(undefined1 *)((longlong)plVar4 + 0x72) = 4;
                }
              }
              uVar20 = uVar19;
              if ((*(void **)(puVar17 + 8) != (void *)0x0) &&
                 (*(char *)((longlong)plVar4 + 0x61) != '\0')) {
                *(byte *)((longlong)puVar17 + 3) = *(byte *)((longlong)puVar17 + 3) | 0x80;
                bVar2 = *(byte *)((longlong)puVar17 + 0xb);
                if (*(byte *)((longlong)plVar4 + 0x61) < bVar2) {
                  bVar2 = *(byte *)((longlong)plVar4 + 0x61);
                }
                pcVar10 = memcpy(*(void **)(puVar17 + 8),plVar4 + 0xe,(ulonglong)bVar2);
LAB_0001292d:
                plVar14 = local_50;
                uVar20 = uVar19;
              }
            }
            else {
              if (uVar8 != 2) {
                if (uVar8 == 3) {
                  *(undefined2 *)((longlong)puVar17 + 3) = 0x12;
                }
                else {
                  if (uVar8 == 4) {
                    pcVar10 = (code *)BuildStatus_IllegalRequest(0,(longlong)puVar17,0x20);
                    goto LAB_0001292d;
                  }
                  if (uVar8 != 5) goto LAB_00012937;
                  *(undefined1 *)((longlong)puVar17 + 3) = 0xe;
                }
                bVar7 = true;
                uVar20 = 5;
                goto LAB_00012983;
              }
              uVar9 = puVar17[4];
              pcVar10 = (code *)(ulonglong)uVar9;
              *(undefined2 *)((longlong)puVar17 + 3) = 0x12;
              if (uVar9 < *(uint *)((longlong)plVar4 + 100)) {
                puVar17[4] = 0;
                uVar20 = uVar19;
              }
              else {
                uVar9 = uVar9 - *(uint *)((longlong)plVar4 + 100);
                pcVar10 = (code *)(ulonglong)uVar9;
                puVar17[4] = uVar9;
                uVar20 = uVar19;
              }
            }
            goto LAB_0001297e;
          }
LAB_00012937:
          *(undefined1 *)((longlong)puVar17 + 3) = 0x11;
LAB_0001293b:
          bVar7 = true;
        }
        else {
          if (uVar8 == 7) {
            *(undefined1 *)((longlong)puVar17 + 3) = 0x13;
            bVar7 = true;
            uVar20 = 2;
          }
          else {
            if (uVar8 != 8) {
              if (uVar8 == 9) {
                *(undefined1 *)((longlong)puVar17 + 3) = 0xe;
                goto LAB_0001293b;
              }
              if (uVar8 != 10) {
                if (uVar8 != 0xb) goto LAB_00012937;
                *(undefined1 *)((longlong)puVar17 + 3) = 0xb;
                bVar7 = true;
                uVar20 = 7;
                goto LAB_00012983;
              }
            }
            *(undefined1 *)((longlong)puVar17 + 3) = 0xe;
            uVar20 = uVar19;
          }
LAB_0001297e:
          if (!bVar7) goto LAB_000129bd;
        }
LAB_00012983:
        if (iVar3 == 0) {
          pcVar10 = (code *)StorPortDebugPrint(0,&s__d__d__d_Error__d__d_,
                                               *(undefined1 *)((longlong)puVar17 + 5),
                                               *(undefined1 *)((longlong)puVar17 + 6),
                                               *(undefined1 *)((longlong)puVar17 + 7),uVar20,
                                               *(undefined2 *)((longlong)plVar4 + 0x62));
          goto LAB_000129bd;
        }
      }
LAB_00012a50:
      plVar15 = (longlong *)0x0;
      puVar13 = (ulonglong *)plVar16[5];
      if (plVar16 == plVar14) {
        plVar16 = plVar15;
      }
      else {
        *(longlong *)plVar18[1] = *plVar18;
        pcVar10 = (code *)plVar18[1];
        *(code **)(*plVar18 + 8) = pcVar10;
        plVar18[1] = (longlong)plVar18;
        *plVar18 = (longlong)plVar18;
        plVar18 = (longlong *)plVar14[3];
        plVar16 = plVar18 + -2;
      }
      if (iVar3 < 0x82) {
        if (0x7f < iVar3) {
          *(undefined1 *)((longlong)puVar17 + 0x5a) = 0;
          bVar2 = *(byte *)((longlong)puVar17 + 5);
          pcVar10 = (code *)CONCAT71((int7)((ulonglong)pcVar10 >> 8),bVar2);
          if (bVar2 != 0xff) {
            if (*(char *)((longlong)puVar17 + 7) == '\0') {
              uVar9 = (uint)bVar2 * 0x80 + (uint)*(byte *)((longlong)puVar17 + 6);
            }
            else {
              uVar9 = 0xffffffff;
            }
            param_1[(ulonglong)uVar9 * 7 + 0x65] = param_1[(ulonglong)uVar9 * 7 + 0x65] & 0xfffdffff
            ;
            pcVar10 = (code *)(ulonglong)CONCAT31((int3)(uVar9 >> 8),(byte)param_1[0x27d9]);
            if (((byte)param_1[0x27d9] & 0x10) == 0) {
              LOCK();
              param_1[0x2826] = param_1[0x2826] + 1;
              UNLOCK();
              local_54 = 0;
              puVar11 = &local_54;
              goto LAB_00012c07;
            }
          }
          goto LAB_00012faa;
        }
        if (iVar3 < 8) {
          if (iVar3 != 7) {
            if (iVar3 == 0) goto LAB_00012f97;
            if (iVar3 == 1) {
              if (puVar13 == (ulonglong *)0x0) {
                pcVar10 = (code *)FUN_000130d8((longlong)param_1);
              }
              else {
                pcVar10 = FUN_000130d8;
                puVar13[0xe] = (ulonglong)puVar17;
                puVar13[0xd] = (ulonglong)FUN_000130d8;
                if ((*(longlong *)(param_1 + 0x2828) == 0) ||
                   (pcVar10 = (code *)CONCAT71(0x130,(byte)param_1[0x27d9]),
                   ((byte)param_1[0x27d9] & 0x10) != 0)) goto LAB_00012faa;
                uVar9 = param_1[0x2515];
                lVar5 = *(longlong *)(param_1 + 0x2512);
                do {
                  uVar6 = *(ulonglong *)(param_1 + 0x250e);
                  *puVar13 = uVar6 & 0xffff;
                  LOCK();
                  uVar12 = *(ulonglong *)(param_1 + 0x250e);
                  if (uVar6 == uVar12) {
                    *(ulonglong *)(param_1 + 0x250e) =
                         (uVar6 & 0xffffffffffff0000) + 0x10000 |
                         (ulonglong)((longlong)puVar13 - lVar5) / (ulonglong)uVar9 & 0xffffffff;
                    uVar12 = uVar6;
                  }
                  else {
                  }
                  UNLOCK();
                } while (uVar6 != uVar12);
                pcVar10 = (code *)CONCAT71((int7)(uVar12 >> 8),(byte)param_1[0x27d9]);
                if (((byte)param_1[0x27d9] & 0x10) == 0) {
                  LOCK();
                  param_1[0x2826] = param_1[0x2826] + 1;
                  UNLOCK();
                  local_res20[0] = 0;
                  puVar11 = local_res20;
LAB_00012c07:
                  pcVar10 = (code *)StorPortNotification
                                              (0x1002,param_1,param_1 + 0x24d4,0,0,puVar11);
                }
              }
            }
            else if (iVar3 == 2) {
              if (puVar13 == (ulonglong *)0x0) {
                pcVar10 = (code *)FUN_000135d4((longlong)param_1);
              }
              else {
                pcVar10 = FUN_000135d4;
                puVar13[0xe] = (ulonglong)puVar17;
                puVar13[0xd] = (ulonglong)FUN_000135d4;
                if ((*(longlong *)(param_1 + 0x2828) == 0) ||
                   (pcVar10 = (code *)CONCAT71(0x135,(byte)param_1[0x27d9]),
                   ((byte)param_1[0x27d9] & 0x10) != 0)) goto LAB_00012faa;
                uVar9 = param_1[0x2515];
                lVar5 = *(longlong *)(param_1 + 0x2512);
                do {
                  uVar6 = *(ulonglong *)(param_1 + 0x250e);
                  *puVar13 = uVar6 & 0xffff;
                  LOCK();
                  uVar12 = *(ulonglong *)(param_1 + 0x250e);
                  if (uVar6 == uVar12) {
                    *(ulonglong *)(param_1 + 0x250e) =
                         (uVar6 & 0xffffffffffff0000) + 0x10000 |
                         (ulonglong)((longlong)puVar13 - lVar5) / (ulonglong)uVar9 & 0xffffffff;
                    uVar12 = uVar6;
                  }
                  else {
                  }
                  UNLOCK();
                } while (uVar6 != uVar12);
                pcVar10 = (code *)CONCAT71((int7)(uVar12 >> 8),(byte)param_1[0x27d9]);
                if (((byte)param_1[0x27d9] & 0x10) == 0) {
                  LOCK();
                  param_1[0x2826] = param_1[0x2826] + 1;
                  UNLOCK();
                  local_res18[0] = 0;
                  puVar11 = local_res18;
                  goto LAB_00012c07;
                }
              }
            }
            else if (iVar3 == 3) {
              pcVar10 = (code *)CompleteCsmiPassThrough
                                          ((longlong)param_1,(undefined1 *)puVar17,pbVar1);
            }
            else if (iVar3 == 4) {
              pcVar10 = *(code **)(param_1 + 0x24fa);
              if (*(code **)(pcVar10 + 0x440) == _guard_dispatch_icall) {
                pcVar10[0x438] = (code)0x0;
              }
              else {
                pcVar10 = (code *)(**(code **)(pcVar10 + 0x440))();
              }
            }
            else {
              if (iVar3 != 5) {
                if (iVar3 == 6) {
                  do {
                    *(undefined1 *)((longlong)plVar15 + *(longlong *)(puVar17 + 0x16) + 3) =
                         *(undefined1 *)((longlong)plVar15 + 3 + (longlong)puVar17);
                    plVar15 = (longlong *)((longlong)plVar15 + 1);
                  } while ((longlong)plVar15 < 2);
                  goto LAB_00012b05;
                }
                goto LAB_00012faa;
              }
              pcVar10 = (code *)CompleteSAS_SspPassThrough
                                          ((longlong)param_1,(longlong)puVar17,pbVar1);
            }
            goto LAB_00012fa5;
          }
          do {
            *(undefined1 *)((longlong)plVar15 + *(longlong *)(puVar17 + 0x16) + 3) =
                 *(undefined1 *)((longlong)plVar15 + 3 + (longlong)puVar17);
            plVar15 = (longlong *)((longlong)plVar15 + 1);
          } while ((longlong)plVar15 < 2);
LAB_00012b05:
          puVar17 = *(uint **)(puVar17 + 0x16);
          goto LAB_00012f97;
        }
        if (iVar3 == 8) {
          do {
            *(undefined1 *)((longlong)plVar15 + *(longlong *)(puVar17 + 0x16) + 3) =
                 *(undefined1 *)((longlong)plVar15 + 3 + (longlong)puVar17);
            plVar15 = (longlong *)((longlong)plVar15 + 1);
          } while ((longlong)plVar15 < 2);
          goto LAB_00012b05;
        }
        if (iVar3 == 9) {
          do {
            *(undefined1 *)((longlong)plVar15 + *(longlong *)(puVar17 + 0x16) + 3) =
                 *(undefined1 *)((longlong)plVar15 + 3 + (longlong)puVar17);
            plVar15 = (longlong *)((longlong)plVar15 + 1);
          } while ((longlong)plVar15 < 2);
          goto LAB_00012b05;
        }
        if (iVar3 == 10) {
          do {
            *(undefined1 *)((longlong)plVar15 + *(longlong *)(puVar17 + 0x16) + 3) =
                 *(undefined1 *)((longlong)plVar15 + 3 + (longlong)puVar17);
            plVar15 = (longlong *)((longlong)plVar15 + 1);
          } while ((longlong)plVar15 < 2);
          goto LAB_00012b05;
        }
        if (iVar3 == 0xb) {
          do {
            *(undefined1 *)((longlong)plVar15 + *(longlong *)(puVar17 + 0x16) + 3) =
                 *(undefined1 *)((longlong)plVar15 + 3 + (longlong)puVar17);
            plVar15 = (longlong *)((longlong)plVar15 + 1);
          } while ((longlong)plVar15 < 2);
          goto LAB_00012b05;
        }
        if (iVar3 == 0xc) {
          pcVar10 = CissBmicCommandCompletionRoutine;
          puVar13[0xe] = (ulonglong)puVar17;
          puVar13[0xd] = (ulonglong)CissBmicCommandCompletionRoutine;
          if ((*(longlong *)(param_1 + 0x2828) != 0) &&
             (pcVar10 = (code *)CONCAT71(0x13b,(byte)param_1[0x27d9]),
             ((byte)param_1[0x27d9] & 0x10) == 0)) {
            uVar9 = param_1[0x2515];
            lVar5 = *(longlong *)(param_1 + 0x2512);
            do {
              uVar6 = *(ulonglong *)(param_1 + 0x250e);
              *puVar13 = uVar6 & 0xffff;
              LOCK();
              uVar12 = *(ulonglong *)(param_1 + 0x250e);
              if (uVar6 == uVar12) {
                *(ulonglong *)(param_1 + 0x250e) =
                     (uVar6 & 0xffffffffffff0000) + 0x10000 |
                     (ulonglong)((longlong)puVar13 - lVar5) / (ulonglong)uVar9 & 0xffffffff;
                uVar12 = uVar6;
              }
              else {
              }
              UNLOCK();
            } while (uVar6 != uVar12);
            pcVar10 = (code *)CONCAT71((int7)(uVar12 >> 8),(byte)param_1[0x27d9]);
            if (((byte)param_1[0x27d9] & 0x10) == 0) {
              LOCK();
              param_1[0x2826] = param_1[0x2826] + 1;
              UNLOCK();
              local_58 = 0;
              puVar11 = &local_58;
              goto LAB_00012c07;
            }
            goto LAB_00012fa5;
          }
          goto LAB_00012faa;
        }
        if (iVar3 != 0xd) goto LAB_00012faa;
        pcVar10 = (code *)CissNoeCompletionRoutine(param_1,puVar17);
LAB_00012fa5:
        plVar14 = local_50;
      }
      else if (iVar3 == 0x82) {
        *(undefined1 *)(*(longlong *)(param_1 + 0x24f8) + 0x230) = 0;
        pcVar10 = *(code **)(param_1 + 0x24f8);
        if (*(longlong *)(pcVar10 + 0x238) != 0) {
          *(undefined1 *)(*(longlong *)(pcVar10 + 0x238) + 3) = 10;
          puVar17 = *(uint **)(*(longlong *)(param_1 + 0x24f8) + 0x238);
LAB_00012f97:
          pcVar10 = (code *)StorPortNotification(0,param_1,puVar17);
          goto LAB_00012fa5;
        }
      }
      else {
        if (iVar3 == 0x83) {
          lVar5 = *(longlong *)(*(longlong *)(puVar17 + 0x16) + 0x18);
          *(undefined1 *)(*(longlong *)(puVar17 + 0x16) + 3) = 1;
          *(undefined1 *)(*(longlong *)(puVar17 + 0x16) + 4) = 0;
          *(undefined4 *)(lVar5 + 0x14) = 0;
          *(undefined2 *)(lVar5 + 0x34) = *(undefined2 *)((longlong)plVar4 + 0x62);
          goto LAB_00012b05;
        }
        if (iVar3 == 0x84) {
          if (*(char *)((longlong)puVar17 + 7) == '\0') {
            uVar9 = (uint)*(byte *)((longlong)puVar17 + 5) * 0x80 +
                    (uint)*(byte *)((longlong)puVar17 + 6);
          }
          else {
            uVar9 = 0xffffffff;
          }
          param_1[(ulonglong)uVar9 * 7 + 0x65] = param_1[(ulonglong)uVar9 * 7 + 0x65] & 0xfffdffff;
          lVar5 = *(longlong *)(puVar17 + 0xe);
          if ((*(char *)(lVar5 + 3) == '\x01') || (*(char *)(lVar5 + 3) == '\x12')) {
            *(undefined1 *)(*(longlong *)(lVar5 + 0x58) + 3) = 1;
          }
          else {
            *(undefined1 *)(*(longlong *)(lVar5 + 0x58) + 3) = 0xe;
          }
          *(undefined1 *)(*(longlong *)(lVar5 + 0x58) + 4) = 0;
          puVar17 = *(uint **)(lVar5 + 0x58);
          goto LAB_00012f97;
        }
      }
LAB_00012faa:
      puVar17 = local_48;
      uVar19 = uVar20;
    } while (plVar16 != (longlong *)0x0);
    if (local_48 != (uint *)0x0) {
      LOCK();
      local_48[1] = local_48[1] - 1;
      UNLOCK();
      pcVar10 = (code *)(ulonglong)local_48[1];
      if ((local_48[1] == 0) && (*(short *)((longlong)local_48 + 0x36) != 0)) {
        LOCK();
        uVar9 = *local_48;
        if (uVar9 == 0) {
          *local_48 = 1;
        }
        else {
          pcVar10 = (code *)(ulonglong)uVar9;
        }
        UNLOCK();
        if (uVar9 == 0) {
          pcVar10 = (code *)CoalescingFlushLUN(param_1,(longlong)local_48,1,1);
          *puVar17 = 0;
        }
      }
    }
  }
  return pcVar10;
}



===== CissIsr @ 00013018 =====

undefined8 CissIsr(uint *param_1)

{
  undefined8 uVar1;
  uint *puVar3;
  uint *puVar2;
  uint uVar4;
  
  uVar1 = (**(code **)(param_1 + 0x52))();
  if ((char)uVar1 != '\0') {
    if ((param_1[0x27d9] & 0xf) != 4) {
      do {
        if ((int)param_1[0x2780] < 0) {
          puVar2 = (uint *)(ulonglong)**(uint **)(param_1 + 0x2e);
          if (**(uint **)(param_1 + 0x2e) == 0xffffffff) goto LAB_00013065;
          puVar2 = *(uint **)(param_1 + 0x30);
        }
        else {
          puVar2 = *(uint **)(param_1 + 0x14);
        }
        if (*puVar2 == 0xffffffff) goto LAB_00013065;
        CissCompletion(param_1,*puVar2);
      } while( true );
    }
    puVar3 = *(uint **)(param_1 + 0x1e);
    while (puVar2 = (uint *)(ulonglong)*puVar3, (*puVar3 & 1) != 0) {
      **(undefined4 **)(param_1 + 0x20) = 1;
      LOCK();
      UNLOCK();
      puVar3 = *(uint **)(param_1 + 0x1e);
    }
    uVar4 = 0;
    if (*(char *)((longlong)param_1 + 2) != '\0') {
      do {
        while( true ) {
          uVar1 = PerformantModeGetCompletedRequest((longlong)param_1,uVar4);
          if ((uint)uVar1 == 0xffffffff) break;
          CissCompletion(param_1,(uint)uVar1);
        }
        puVar2 = (uint *)0x0;
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(byte *)((longlong)param_1 + 2));
    }
LAB_00013065:
    param_1[1] = 0;
    uVar1 = CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
  }
  return uVar1;
}



===== FUN_000130d8 @ 000130d8 =====

void FUN_000130d8(longlong param_1)

{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  undefined8 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  int iVar12;
  longlong lVar13;
  byte bVar14;
  uint uVar15;
  uint *puVar16;
  uint *puVar17;
  uint *puVar18;
  uint *local_res18;
  
  puVar1 = *(uint **)(param_1 + 0x93c8);
  if (*(longlong *)(puVar1 + 0x624) == 0) {
    puVar17 = puVar1;
  }
  else {
    puVar17 = *(uint **)(*(longlong *)(puVar1 + 0x624) + 8);
  }
  puVar18 = puVar17 + 2;
  uVar15 = *puVar17;
  uVar15 = (uVar15 & 0xff00 | uVar15 << 0x10) << 8 | (uVar15 & 0xff0000 | uVar15 >> 0x10) >> 8;
  if (((puVar17[1] & 1) == 0) && ((puVar17[1] & 2) == 0)) {
    bVar3 = false;
    iVar12 = 8;
  }
  else {
    bVar3 = true;
    iVar12 = 0x18;
  }
  if (uVar15 == 0) goto LAB_00013310;
  uVar10 = puVar1[0x682];
  if (bVar3) {
    if ((ulonglong)uVar10 * 0x18 < (ulonglong)uVar15) {
      uVar10 = uVar10 * 3;
      goto LAB_000131a6;
    }
  }
  else if ((ulonglong)uVar10 * 8 < (ulonglong)uVar15) {
LAB_000131a6:
    uVar15 = uVar10 << 3;
  }
  if (uVar15 != 0) {
    local_res18 = puVar18;
LAB_000131bc:
    bVar5 = false;
    bVar4 = false;
    uVar11 = 4;
    puVar17 = (uint *)(param_1 + 0x204);
    do {
      if (bVar3) {
        lVar13 = uVar11 * 0x1c;
        if ((((*(longlong *)(lVar13 + 0x198 + param_1) == *(longlong *)puVar18) &&
             (*(longlong *)(lVar13 + 0x1a0 + param_1) == *(longlong *)(puVar18 + 2))) &&
            (*(longlong *)(lVar13 + 0x1a8 + param_1) == *(longlong *)(puVar18 + 4))) &&
           ((*puVar17 & 0x40) == 0)) {
          *(uint *)(uVar11 * 0x1c + 0x194 + param_1) =
               *(uint *)(uVar11 * 0x1c + 0x194 + param_1) & 0xffffff8f | 0x100;
          goto LAB_00013516;
        }
      }
      else if ((*(longlong *)(uVar11 * 0x1c + 0x198 + param_1) == *(longlong *)local_res18) &&
              ((*puVar17 & 0x40) == 0)) {
        *(uint *)(uVar11 * 0x1c + 0x194 + param_1) =
             *(uint *)(uVar11 * 0x1c + 0x194 + param_1) & 0xffffff8f | 0x100;
        goto LAB_000132fe;
      }
      uVar10 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar10;
      puVar17 = puVar17 + 7;
    } while (uVar10 < 0x380);
    bVar2 = false;
    bVar14 = 0;
LAB_00013256:
    uVar10 = (uint)bVar14 * 0x80 + (uint)(~-(bVar14 != 0) & 4);
    puVar17 = local_res18;
    if (bVar3) {
      puVar17 = puVar18;
    }
    puVar16 = (uint *)(param_1 + 0x194 + (ulonglong)uVar10 * 0x1c);
    uVar9 = *puVar16;
    if ((puVar17[1] & 1) == 0) {
      if ((uVar9 & 1) != 0) {
        uVar8 = uVar10 + 0x80;
        uVar6 = uVar10;
        if (bVar14 == 0) {
          uVar8 = uVar10 + 0x7c;
        }
        for (; uVar11 = (ulonglong)uVar6, uVar6 < uVar8; uVar6 = uVar6 + 1) {
          if ((*puVar16 & 0x10) != 0) goto LAB_00013537;
          puVar16 = puVar16 + 7;
        }
        if (bVar14 == 6) {
          bVar2 = true;
        }
      }
    }
    else if ((uVar9 & 2) != 0) {
      uVar8 = uVar10 + 0x80;
      uVar6 = uVar10;
      if (bVar14 == 0) {
        uVar8 = uVar10 + 0x7c;
      }
      for (; uVar11 = (ulonglong)uVar6, uVar6 < uVar8; uVar6 = uVar6 + 1) {
        if ((*puVar16 & 0x10) != 0) goto LAB_00013537;
        puVar16 = puVar16 + 7;
      }
      if (bVar14 == 6) {
        bVar2 = true;
      }
    }
    if (((uVar9 & 2) != 0) || ((uVar9 & 1) != 0)) goto LAB_000133c9;
    uVar9 = uVar10 + 0x80;
    if (bVar14 == 0) {
      uVar9 = uVar10 + 0x7c;
    }
    if (uVar10 < uVar9) {
      puVar16 = (uint *)(param_1 + 0x194 + (ulonglong)uVar10 * 0x1c);
      uVar11 = (ulonglong)(uVar9 - uVar10);
      do {
        if ((puVar17[1] & 1) == 0) {
          *puVar16 = *puVar16 | 1;
        }
        else {
          *puVar16 = *puVar16 | 2;
        }
        puVar16 = puVar16 + 7;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
    uVar11 = (ulonglong)uVar10;
    goto LAB_00013537;
  }
LAB_00013310:
  puVar17 = (uint *)(param_1 + 0x204);
  lVar13 = 0x37c;
  do {
    if ((*puVar17 & 0x20) != 0) {
      *puVar17 = *puVar17 & 0xffffffdf | 0x40;
    }
    puVar17 = puVar17 + 7;
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  if (*(int *)(param_1 + 0x92f4) == 0x3237103c) {
    uVar15 = 0x80;
    puVar17 = (uint *)(param_1 + 0xf94);
    do {
      if (((*puVar17 & 2) != 0) && ((*puVar17 & 0x100) != 0)) {
        *(undefined4 *)(param_1 + 0x9dec) = 200;
        break;
      }
      uVar15 = uVar15 + 1;
      puVar17 = puVar17 + 7;
    } while (uVar15 < 0x380);
  }
  StorPortReady(param_1);
  *(undefined1 *)((longlong)puVar1 + 0x19f2) = 0;
  if (*(longlong *)(puVar1 + 0x694) != 0) {
    *(undefined1 *)(*(longlong *)(puVar1 + 0x694) + 3) = 10;
    StorPortNotification(0,param_1,*(undefined8 *)(puVar1 + 0x694));
  }
  return;
LAB_000133c9:
  bVar14 = bVar14 + 1;
  if (6 < bVar14) goto LAB_0001342f;
  goto LAB_00013256;
LAB_0001342f:
  if (bVar2) {
    bVar14 = 0;
    do {
      uVar10 = (uint)bVar14 * 0x80 + (uint)(~-(bVar14 != 0) & 4);
      puVar17 = local_res18;
      if (bVar3) {
        puVar17 = puVar18;
      }
      if ((puVar17[1] & 1) == 0) {
        puVar17 = (uint *)(param_1 + 0x194 + (ulonglong)uVar10 * 0x1c);
        if ((*puVar17 & 1) != 0) {
          uVar9 = uVar10 + 0x80;
          if (bVar14 == 0) {
            uVar9 = uVar10 + 0x7c;
          }
          for (; uVar11 = (ulonglong)uVar10, uVar10 < uVar9; uVar10 = uVar10 + 1) {
            if ((*puVar17 & 0x40) != 0) goto LAB_00013507;
            puVar17 = puVar17 + 7;
          }
          bVar4 = bVar5;
          if (bVar14 == 6) {
            bVar4 = true;
            bVar5 = true;
          }
        }
      }
      else {
        puVar17 = (uint *)(param_1 + 0x194 + (ulonglong)uVar10 * 0x1c);
        if ((*puVar17 & 2) != 0) {
          uVar9 = uVar10 + 0x80;
          if (bVar14 == 0) {
            uVar9 = uVar10 + 0x7c;
          }
          for (; uVar11 = (ulonglong)uVar10, uVar10 < uVar9; uVar10 = uVar10 + 1) {
            if ((*puVar17 & 0x40) != 0) goto LAB_00013507;
            puVar17 = puVar17 + 7;
          }
          if (bVar14 == 6) {
            bVar4 = true;
            bVar5 = true;
          }
        }
      }
      bVar14 = bVar14 + 1;
    } while (bVar14 < 7);
LAB_00013507:
    if (bVar4) goto LAB_00013516;
  }
LAB_00013537:
  lVar13 = uVar11 * 0x1c + param_1;
  if (bVar3) {
    uVar7 = *(undefined8 *)(puVar18 + 4);
    *(undefined8 *)(lVar13 + 0x1a0) = *(undefined8 *)(puVar18 + 2);
    *(undefined8 *)(lVar13 + 0x1a8) = uVar7;
    uVar7 = *(undefined8 *)puVar18;
  }
  else {
    uVar7 = *(undefined8 *)local_res18;
  }
  *(undefined8 *)(lVar13 + 0x198) = uVar7;
  *(uint *)(lVar13 + 0x194) = *(uint *)(lVar13 + 0x194) & 0xffffff0f | 0x100;
LAB_00013516:
  if (bVar3) {
    puVar18 = puVar18 + 6;
  }
  else {
LAB_000132fe:
    local_res18 = local_res18 + 2;
  }
  uVar15 = uVar15 - iVar12;
  if (uVar15 == 0) goto LAB_00013310;
  goto LAB_000131bc;
}



===== FUN_000135d4 @ 000135d4 =====

void FUN_000135d4(longlong param_1)

{
  undefined8 *puVar1;
  char cVar2;
  uint *puVar3;
  bool bVar4;
  undefined8 uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  uint *puVar14;
  int iVar15;
  uint uVar16;
  ulonglong uVar17;
  uint uVar18;
  byte bVar19;
  uint *puVar20;
  uint *local_res18;
  
  puVar3 = *(uint **)(param_1 + 0x93c8);
  if (*(longlong *)(puVar3 + 0x624) == 0) {
    puVar14 = puVar3;
  }
  else {
    puVar14 = *(uint **)(*(longlong *)(puVar3 + 0x624) + 8);
  }
  puVar20 = puVar14 + 2;
  uVar18 = *puVar14;
  uVar18 = (uVar18 & 0xff00 | uVar18 << 0x10) << 8 | (uVar18 & 0xff0000 | uVar18 >> 0x10) >> 8;
  if (((puVar14[1] & 1) == 0) && ((puVar14[1] & 2) == 0)) {
    bVar6 = false;
    iVar15 = 8;
  }
  else {
    bVar6 = true;
    iVar15 = 0x18;
  }
  uVar17 = 4;
  if (uVar18 == 0) goto LAB_000139f8;
  uVar11 = puVar3[0x682];
  if (bVar6) {
    if ((ulonglong)uVar11 * 0x18 < (ulonglong)uVar18) {
      uVar11 = uVar11 * 3;
      goto LAB_000136a8;
    }
  }
  else if ((ulonglong)uVar11 * 8 < (ulonglong)uVar18) {
LAB_000136a8:
    uVar18 = uVar11 << 3;
  }
  local_res18 = puVar20;
  if (uVar18 != 0) {
LAB_000136bb:
    bVar9 = false;
    bVar8 = false;
    puVar14 = local_res18;
    if (bVar6) {
      puVar14 = puVar20;
    }
    uVar11 = *puVar14;
    if ((uVar11 & 0xc0000000) == 0) {
      if (((uVar11 & 0x3f000000) == 0) && ((uVar11 & 0xffffff) == 0)) {
        bVar7 = true;
      }
      else {
        bVar7 = false;
      }
      uVar17 = 4;
      do {
        if (bVar6) {
          if ((*(longlong *)(uVar17 * 0x1c + 0x198 + param_1) == *(longlong *)puVar20) &&
             (*(longlong *)(uVar17 * 0x1c + 0x1a0 + param_1) == *(longlong *)(puVar20 + 2))) {
            lVar13 = uVar17 * 0x1c;
            uVar11 = *(uint *)(lVar13 + 0x194 + param_1) & 0xffffff8f | 0x80;
            *(uint *)(lVar13 + 0x194 + param_1) = uVar11;
            bVar19 = *(byte *)(lVar13 + 0x1a8 + param_1);
            if ((bVar19 & 2) != 0) goto LAB_00013ad1;
            if ((bVar19 & 1) == 0) goto LAB_00013ae7;
            goto LAB_00013adc;
          }
        }
        else if (*(longlong *)(uVar17 * 0x1c + 0x198 + param_1) == *(longlong *)local_res18) {
          *(uint *)(uVar17 * 0x1c + 0x194 + param_1) =
               *(uint *)(uVar17 * 0x1c + 0x194 + param_1) & 0xffffff8f | 0x80;
          goto LAB_000139e1;
        }
        uVar11 = (int)uVar17 + 1;
        uVar17 = (ulonglong)uVar11;
      } while (uVar11 < 0x380);
      bVar4 = false;
      bVar19 = 0;
LAB_00013782:
      uVar16 = (uint)bVar19 * 0x80 + (uint)(~-(bVar19 != 0) & 4);
      puVar14 = (uint *)(param_1 + 0x194 + (ulonglong)uVar16 * 0x1c);
      uVar11 = *puVar14;
      if (bVar7) {
        if ((uVar11 & 1) != 0) {
          uVar12 = uVar16 + 0x80;
          uVar10 = uVar16;
          if (bVar19 == 0) {
            uVar12 = uVar16 + 0x7c;
          }
          for (; uVar17 = (ulonglong)uVar10, uVar10 < uVar12; uVar10 = uVar10 + 1) {
            if ((*puVar14 & 0x10) != 0) goto LAB_00013a78;
            puVar14 = puVar14 + 7;
          }
          if (bVar19 == 6) {
            bVar4 = true;
          }
        }
      }
      else if ((uVar11 & 2) != 0) {
        uVar12 = uVar16 + 0x80;
        uVar10 = uVar16;
        if (bVar19 == 0) {
          uVar12 = uVar16 + 0x7c;
        }
        for (; uVar17 = (ulonglong)uVar10, uVar10 < uVar12; uVar10 = uVar10 + 1) {
          if ((*puVar14 & 0x10) != 0) goto LAB_00013a78;
          puVar14 = puVar14 + 7;
        }
        if (bVar19 == 6) {
          bVar4 = true;
        }
      }
      if (((uVar11 & 2) != 0) || ((uVar11 & 1) != 0)) goto LAB_00013858;
      uVar11 = uVar16 + 0x80;
      if (bVar19 == 0) {
        uVar11 = uVar16 + 0x7c;
      }
      if (uVar16 < uVar11) {
        puVar14 = (uint *)(param_1 + 0x194 + (ulonglong)uVar16 * 0x1c);
        uVar17 = (ulonglong)(uVar11 - uVar16);
        do {
          if (bVar7) {
            *puVar14 = *puVar14 | 1;
          }
          else {
            *puVar14 = *puVar14 | 2;
          }
          puVar14 = puVar14 + 7;
          uVar17 = uVar17 - 1;
        } while (uVar17 != 0);
      }
      uVar17 = (ulonglong)uVar16;
    }
    goto LAB_00013a78;
  }
LAB_000139f8:
  puVar14 = (uint *)(param_1 + 0x204);
  lVar13 = 0x37c;
  do {
    if ((*puVar14 & 0x20) != 0) {
      *puVar14 = *puVar14 & 0xffffffdf | 0x40;
    }
    puVar14 = puVar14 + 7;
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  StorPortReady(param_1);
  *(undefined1 *)((longlong)puVar3 + 0x19f2) = 0;
  if (*(longlong *)(puVar3 + 0x694) != 0) {
    *(undefined1 *)(*(longlong *)(puVar3 + 0x694) + 3) = 10;
    StorPortNotification(0,param_1,*(undefined8 *)(puVar3 + 0x694));
  }
  *(undefined2 *)(param_1 + 0x9f70) = 3;
  return;
LAB_00013858:
  bVar19 = bVar19 + 1;
  if (6 < bVar19) goto code_r0x00013865;
  goto LAB_00013782;
code_r0x00013865:
  if (bVar4) {
    bVar19 = 0;
    do {
      uVar11 = (uint)bVar19 * 0x80 + (uint)(~-(bVar19 != 0) & 4);
      puVar14 = local_res18;
      if (bVar6) {
        puVar14 = puVar20;
      }
      uVar16 = *puVar14;
      if ((uVar16 & 0xc0000000) != 0) break;
      if (((uVar16 & 0x3f000000) == 0) && ((uVar16 & 0xffffff) == 0)) {
        puVar14 = (uint *)(param_1 + 0x194 + (ulonglong)uVar11 * 0x1c);
        if ((*puVar14 & 1) != 0) {
          uVar16 = uVar11 + 0x80;
          if (bVar19 == 0) {
            uVar16 = uVar11 + 0x7c;
          }
          for (; uVar17 = (ulonglong)uVar11, uVar11 < uVar16; uVar11 = uVar11 + 1) {
            if ((*puVar14 & 0x40) != 0) goto LAB_000139b4;
            puVar14 = puVar14 + 7;
          }
          bVar8 = bVar9;
          if (bVar19 == 6) {
            bVar8 = true;
            bVar9 = true;
          }
        }
      }
      else {
        puVar14 = (uint *)(param_1 + 0x194 + (ulonglong)uVar11 * 0x1c);
        if ((*puVar14 & 2) != 0) {
          uVar16 = uVar11 + 0x80;
          if (bVar19 == 0) {
            uVar16 = uVar11 + 0x7c;
          }
          while( true ) {
            uVar17 = (ulonglong)uVar11;
            if (uVar16 <= uVar11) break;
            if ((*puVar14 & 0x10) != 0) goto LAB_000139b4;
            puVar14 = puVar14 + 7;
            uVar11 = uVar11 + 1;
          }
        }
      }
      bVar19 = bVar19 + 1;
    } while (bVar19 < 7);
LAB_000139b4:
    if (!bVar8) goto LAB_00013a78;
LAB_00013b33:
    if (bVar6) {
      puVar20 = puVar20 + 6;
      goto LAB_000139ea;
    }
  }
  else {
LAB_00013a78:
    if (bVar6) {
      if ((*puVar20 & 0xc0000000) == 0xc0000000) goto LAB_00013b33;
      uVar5 = *(undefined8 *)(puVar20 + 4);
      lVar13 = uVar17 * 0x1c;
      puVar1 = (undefined8 *)(lVar13 + 0x1a0 + param_1);
      *puVar1 = *(undefined8 *)(puVar20 + 2);
      puVar1[1] = uVar5;
      *(undefined8 *)(lVar13 + 0x198 + param_1) = *(undefined8 *)puVar20;
      uVar11 = *(uint *)(lVar13 + 0x194 + param_1) & 0xfffffe8f | 0x80;
      *(uint *)(lVar13 + 0x194 + param_1) = uVar11;
      cVar2 = *(char *)(lVar13 + 0x1a8 + param_1);
      if (cVar2 == '\x02') {
LAB_00013ad1:
        uVar11 = uVar11 | 0x4000;
LAB_00013ae0:
        *(uint *)(lVar13 + 0x194 + param_1) = uVar11;
      }
      else if (cVar2 == '\x01') {
LAB_00013adc:
        uVar11 = uVar11 | 0x8000;
        goto LAB_00013ae0;
      }
LAB_00013ae7:
      if ((*(byte *)(lVar13 + 0x1a9 + param_1) & 1) == 0) {
        puVar14 = (uint *)(lVar13 + 0x194 + param_1);
        *puVar14 = *puVar14 | 0x10000;
      }
      goto LAB_00013b33;
    }
    if ((*local_res18 & 0xc0000000) != 0xc0000000) {
      lVar13 = uVar17 * 0x1c;
      *(undefined8 *)(lVar13 + 0x198 + param_1) = *(undefined8 *)local_res18;
      *(uint *)(lVar13 + 0x194 + param_1) = *(uint *)(lVar13 + 0x194 + param_1) & 0xfffffe8f | 0x80;
      goto LAB_00013b33;
    }
  }
LAB_000139e1:
  local_res18 = local_res18 + 2;
LAB_000139ea:
  uVar18 = uVar18 - iVar15;
  if (uVar18 == 0) goto LAB_000139f8;
  goto LAB_000136bb;
}



===== CissFlushCacheCompletionRoutine @ 00013b50 =====

void CissFlushCacheCompletionRoutine(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x93e8);
  if ((*(char *)(lVar1 + 0x1db) == '\x01') || (*(char *)(lVar1 + 0x1db) == '\x12')) {
    if (*(longlong *)(lVar1 + 0x230) == 0) goto LAB_00013b9a;
    *(undefined1 *)(*(longlong *)(lVar1 + 0x230) + 3) = 1;
  }
  else {
    if (*(longlong *)(lVar1 + 0x230) == 0) goto LAB_00013b9a;
    *(undefined1 *)(*(longlong *)(lVar1 + 0x230) + 3) = 0xe;
  }
  *(undefined1 *)(*(longlong *)(lVar1 + 0x230) + 4) = 0;
LAB_00013b9a:
  if (*(longlong *)(lVar1 + 0x230) != 0) {
    StorPortNotification(0,param_1);
  }
  *(undefined1 *)(lVar1 + 0x438) = 0;
  return;
}



===== CissBmicCommandCompletionRoutine @ 00013bc4 =====

void CissBmicCommandCompletionRoutine(longlong param_1,longlong param_2)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = *(longlong *)(param_2 + 0x38);
  if ((*(char *)(lVar3 + 3) == '\x01') || (*(char *)(lVar3 + 3) == '\x12')) {
    if (*(char *)(param_2 + 0x4e) == '\x11') {
      lVar4 = *(longlong *)(lVar3 + 0x18);
      iVar2 = *(int *)(param_1 + 0x92f4);
      *(undefined4 *)(param_1 + 0xa01a) = 0;
      *(undefined4 *)(param_1 + 0xa030) = 0;
      *(undefined4 *)(param_1 + 0xa022) = 0;
      if (((iVar2 == 0x3211103c) || (iVar2 == 0x3232103c)) || (iVar2 == 0x3235103c)) {
        *(undefined4 *)(param_1 + 0x93a0) = 0;
      }
      if ((*(int *)(param_1 + 0x93a0) == 0xffff) && (bVar1 = *(byte *)(lVar4 + 0xbd), bVar1 != 0)) {
        *(uint *)(param_1 + 0x93a0) = (uint)bVar1;
      }
    }
    else if (*(char *)(param_2 + 0x4e) == 'f') {
      lVar4 = *(longlong *)(lVar3 + 0x18);
      memcpy((void *)(param_1 + 0x9fc4),(void *)(lVar4 + 0x2c),0x20);
      memcpy((void *)(param_1 + 0x92fb),(void *)(lVar4 + 0x2c),0x20);
    }
  }
  *(undefined1 *)(*(longlong *)(lVar3 + 0x58) + 3) = 10;
                    /* WARNING: Could not recover jumptable at 0x00013ca2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1,*(undefined8 *)(lVar3 + 0x58));
  return;
}



===== CissNoeCompletionRoutine @ 00013cb0 =====

void CissNoeCompletionRoutine(uint *param_1,uint *param_2)

{
  undefined4 *_Dst;
  char cVar1;
  longlong lVar2;
  
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xe) + 3);
  if ((cVar1 == '\x01') || (cVar1 == '\x12')) {
    lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xe) + 0x18);
    if (((param_1[0x27d9] & 0x1000) != 0) && ((char)param_1[0x279b] == '\x01')) {
      _Dst = (undefined4 *)((longlong)param_1 + 0x9e6e);
      memset(_Dst,0,0x48);
      *_Dst = 0x48;
      *(undefined4 *)((longlong)param_1 + 0x9e9a) = 0x2088;
      *(undefined4 *)((longlong)param_1 + 0x9e9e) = 0x2ba5a1f0;
      *(undefined4 *)((longlong)param_1 + 0x9ea2) = 0x4120467e;
      *(undefined4 *)((longlong)param_1 + 0x9ea6) = 0x4434ae97;
      *(undefined4 *)((longlong)param_1 + 0x9eaa) = 0x3bd986dd;
      *(undefined4 *)((longlong)param_1 + 0x9eb2) = 0;
      *(undefined4 *)((longlong)param_1 + 0x9eae) = 0x200;
      *(undefined4 *)((longlong)param_1 + 0x9e86) = 0x2ba5a1f0;
      *(undefined4 *)((longlong)param_1 + 0x9e8a) = 0x4120467e;
      *(undefined4 *)((longlong)param_1 + 0x9e8e) = 0x4434ae97;
      *(undefined4 *)((longlong)param_1 + 0x9e92) = 0x3bd986dd;
      *(undefined1 *)((longlong)param_1 + 0x9e6d) = 0;
      param_2 = param_1;
      StorPortNotification(8,param_1,_Dst,0xff);
    }
    CissCheckEvent(param_1,param_2,lVar2);
    *(undefined1 *)(*(longlong *)(param_1 + 0x24fc) + 0x3d8) = 0;
    if ((*(char *)((longlong)param_1 + 0x9e6d) == '\x01') &&
       (*(char *)(*(longlong *)(param_1 + 0x24fc) + 0x3d8) == '\0')) {
      CissSendNotifyOnEvent(param_1,1);
    }
  }
  else {
    *(undefined1 *)(*(longlong *)(param_1 + 0x24fc) + 0x3d8) = 0;
  }
  return;
}



===== CissImsr @ 00013dc4 =====

undefined8 CissImsr(uint *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(param_1 + 0x54))();
  while ((uint)uVar1 != 0xffffffff) {
    CissCompletion(param_1,(uint)uVar1);
    uVar1 = (**(code **)(param_1 + 0x54))(param_1,param_2);
  }
  param_1[1] = 0;
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== FUN_00013e0c @ 00013e0c =====

void FUN_00013e0c(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  
  while( true ) {
    uVar4 = *(ulonglong *)(param_1 + 0x9438);
    puVar5 = (ulonglong *)
             ((uVar4 & 0xffff) * (ulonglong)*(uint *)(param_1 + 0x9454) +
             *(longlong *)(param_1 + 0x9448));
    if (*puVar5 == 0xffff) break;
    LOCK();
    uVar3 = *(ulonglong *)(param_1 + 0x9438);
    if (uVar4 == uVar3) {
      *(ulonglong *)(param_1 + 0x9438) = (uVar4 & 0xffffffffffff0000) + 0x10000 | *puVar5;
      uVar3 = uVar4;
    }
    else {
    }
    UNLOCK();
    if (uVar4 == uVar3) {
      if ((int)puVar5[5] != 0) {
        StorPortExtendedFunction(10);
      }
      if (puVar5[3] != 0) {
        StorPortExtendedFunction(10,param_1);
        StorPortExtendedFunction(1,param_1,puVar5[3]);
        puVar5[3] = 0;
      }
      if (puVar5[2] != 0) {
        StorPortExtendedFunction(3);
        puVar5[2] = 0;
      }
      if ((code *)puVar5[0xd] != _guard_dispatch_icall) {
        (*(code *)puVar5[0xd])(param_1);
      }
      if (puVar5[1] != 0) {
        StorPortExtendedFunction(1);
        puVar5[1] = 0;
      }
      uVar1 = *(uint *)(param_1 + 0x9dd4);
      lVar2 = *(longlong *)(param_1 + 0x9dc8);
      do {
        uVar3 = *(ulonglong *)(param_1 + 0x9db8);
        *puVar5 = uVar3 & 0xffff;
        LOCK();
        uVar4 = *(ulonglong *)(param_1 + 0x9db8);
        if (uVar3 == uVar4) {
          *(ulonglong *)(param_1 + 0x9db8) =
               (uVar3 & 0xffffffffffff0000) + 0x10000 |
               (ulonglong)((longlong)puVar5 - lVar2) / (ulonglong)uVar1 & 0xffffffff;
          uVar4 = uVar3;
        }
        else {
        }
        UNLOCK();
      } while (uVar3 != uVar4);
    }
  }
  return;
}



===== FUN_00013f68 @ 00013f68 =====

void FUN_00013f68(uint *param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  longlong lVar5;
  ulonglong uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ulonglong *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  int local_res18;
  undefined4 local_54;
  undefined4 local_50 [2];
  ulonglong local_48;
  ulonglong *local_40;
  
  lVar2 = param_2[1];
  puVar10 = (ulonglong *)*param_2;
  uVar11 = *(uint *)(param_2 + 3);
  iVar1 = *(int *)((longlong)param_2 + 0x24);
  uVar8 = *(uint *)(param_2 + 2);
  uVar13 = *(uint *)((longlong)param_2 + 0x14);
  uVar12 = *(uint *)((longlong)param_2 + 0x1c);
  local_res18 = (int)param_2[4];
  local_48 = 0;
  lVar5 = 0;
  if (lVar2 != 0) {
    *(undefined1 *)(lVar2 + 0x1db) = 1;
    if (uVar8 == 0) {
      local_res18 = 0;
      uVar12 = 1;
      uVar8 = 1;
    }
    else if (1 < uVar8) {
      local_48 = puVar10[1];
    }
    uVar6 = 0;
    local_40 = puVar10;
    for (; uVar13 < uVar11; uVar13 = uVar13 + 1) {
      if (uVar8 == 1) {
        *(undefined8 *)(lVar2 + 0x88) = 0;
        bVar14 = uVar12 == 0;
        lVar5 = lVar2;
      }
      else {
        while (uVar9 = (uint)uVar6, uVar9 < uVar8) {
          iVar7 = (int)(uVar6 * 0x24924925 >> 0x20);
          lVar5 = (ulonglong)(uVar9 + ((uVar9 - iVar7 >> 1) + iVar7 >> 2) * -7) * 0x240 + local_48;
          if (*(char *)(lVar5 + 0x231) == '\0') {
            *(ulonglong **)(lVar5 + 0x88) = puVar10;
            break;
          }
          uVar6 = (ulonglong)(uVar9 + 1);
        }
        bVar14 = uVar9 == uVar8;
      }
      if (bVar14) break;
      if (((param_1[(ulonglong)uVar13 * 7 + 0x65] >> 8 & 1) != 0) ||
         ((char)param_1[(ulonglong)uVar13 * 7 + 0x65] < '\0')) {
        *(undefined1 *)(lVar5 + 0x1df) = 0;
        *(undefined2 *)(lVar5 + 0x231) = 0x101;
        *(longlong *)(lVar5 + 0x210) = lVar5;
        uVar9 = uVar12 - 1;
        cVar4 = (char)(uVar13 >> 7);
        *(char *)(lVar5 + 0x1dd) = cVar4;
        *(char *)(lVar5 + 0x1de) = cVar4 * -0x80 + (char)uVar13;
        if ((param_1[(ulonglong)uVar13 * 7 + 0x65] >> 0x11 & 1) == 0) {
          cVar4 = CissSendReset(param_1,(undefined4 *)(lVar5 + 0x1d8),uVar13,iVar1);
          if (cVar4 == '\0') {
            *(undefined2 *)(lVar5 + 0x231) = 0;
            break;
          }
          puVar10 = local_40;
          uVar12 = uVar9;
        }
        else {
          *(undefined1 *)(lVar5 + 0x230) = 1;
          if (iVar1 == 0x80) {
            *(undefined2 *)((longlong)param_1 + 0x9f72) = 1;
            uVar12 = uVar9;
          }
          else {
            *(undefined2 *)(param_1 + 0x27dd) = 1;
            uVar12 = uVar9;
          }
        }
      }
    }
    uVar9 = 0;
    if (uVar8 != 0) {
      do {
        if (uVar8 == 1) {
          lVar5 = lVar2;
        }
        else {
          lVar5 = (ulonglong)(uVar9 % 7) * 0x240 + local_48;
        }
        if ((*(char *)(lVar5 + 0x231) == '\x01') && (*(char *)(lVar5 + 0x232) == '\0')) {
          if (*(char *)(lVar5 + 0x1db) != '\x01') {
            if (*(longlong *)(lVar2 + 0x238) != 0) {
              *(char *)(*(longlong *)(lVar2 + 0x238) + 3) = *(char *)(lVar5 + 0x1db);
            }
            uVar11 = uVar13;
          }
          local_res18 = local_res18 + 1;
          uVar12 = uVar12 + 1;
          *(undefined1 *)(lVar5 + 0x231) = 0;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar8);
    }
    *(uint *)((longlong)param_2 + 0x14) = uVar13;
    *(uint *)(param_2 + 3) = uVar11;
    *(uint *)((longlong)param_2 + 0x1c) = uVar12;
    *(uint *)(param_2 + 2) = uVar8;
    *(int *)(param_2 + 4) = local_res18;
    if (uVar12 == uVar8) {
      if (uVar13 == uVar11) {
        if ((((1 < uVar8) && (local_40 != (ulonglong *)0x0)) &&
            (*(longlong *)(param_1 + 0x2828) != 0)) && ((param_1[0x27d9] & 0x10) == 0)) {
          uVar11 = param_1[0x2515];
          lVar5 = *(longlong *)(param_1 + 0x2512);
          do {
            uVar3 = *(ulonglong *)(param_1 + 0x250e);
            *local_40 = uVar3 & 0xffff;
            LOCK();
            uVar6 = *(ulonglong *)(param_1 + 0x250e);
            if (uVar3 == uVar6) {
              *(ulonglong *)(param_1 + 0x250e) =
                   (uVar3 & 0xffffffffffff0000) + 0x10000 |
                   (ulonglong)((longlong)local_40 - lVar5) / (ulonglong)uVar11 & 0xffffffff;
              uVar6 = uVar3;
            }
            else {
            }
            UNLOCK();
          } while (uVar3 != uVar6);
          if ((param_1[0x27d9] & 0x10) == 0) {
            LOCK();
            param_1[0x2826] = param_1[0x2826] + 1;
            UNLOCK();
            local_54 = 0;
            StorPortNotification(0x1002,param_1,param_1 + 0x24d4,0,0,&local_54);
          }
        }
        param_2[1] = 0;
        *(undefined4 *)(param_2 + 2) = 0;
        lVar5 = *(longlong *)(lVar2 + 0x238);
        *(undefined1 *)(lVar2 + 0x231) = 0;
        if (lVar5 != 0) {
          if ((*(char *)(lVar2 + 0x1db) == '\x01') || (*(char *)(lVar2 + 0x1db) == '\x12')) {
            *(undefined1 *)(lVar5 + 3) = 1;
            *(undefined1 *)(*(longlong *)(lVar2 + 0x238) + 4) = 0;
          }
          else {
            *(undefined1 *)(lVar5 + 3) = 4;
          }
          StorPortNotification(0,param_1,*(undefined8 *)(lVar2 + 0x238));
        }
      }
      else if ((uVar13 < uVar11) && ((param_1[0x27d9] & 0x10) == 0)) {
        LOCK();
        param_1[0x2826] = param_1[0x2826] + 1;
        UNLOCK();
        local_50[0] = 0;
        StorPortNotification(0x1002,param_1,param_1 + 0x24d4,0,0,local_50);
      }
    }
  }
  return;
}



===== FUN_0001438c @ 0001438c =====

void FUN_0001438c(uint *param_1)

{
  FUN_00013f68(param_1,(longlong *)(*(longlong *)(param_1 + 0x24f0) + 0x2968));
  return;
}



===== FUN_000143a8 @ 000143a8 =====

void FUN_000143a8(uint *param_1)

{
  FUN_00013f68(param_1,(longlong *)(*(longlong *)(param_1 + 0x24f0) + 0x2990));
  return;
}



===== CissDpc @ 000143c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CissDpc(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined1 auStack_a8 [32];
  undefined1 *local_88;
  undefined1 local_78 [96];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  local_88 = local_78;
  StorPortNotification(0x1003,param_2,1,param_2 + 0x9350);
  while( true ) {
    LOCK();
    iVar2 = *(int *)(param_2 + 0xa098);
    *(int *)(param_2 + 0xa098) = 0;
    UNLOCK();
    if (iVar2 == 0) break;
    do {
      ppuVar3 = &PTR_FUN_0001c0f8;
      do {
        (*(code *)*ppuVar3)(param_2);
        ppuVar3 = ppuVar3 + 1;
      } while ((longlong)ppuVar3 < 0x1c110);
      iVar2 = iVar2 + -1;
    } while (0 < iVar2);
  }
  uVar1 = StorPortNotification(0x1004,param_2,local_78);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== CissAdapterControl @ 00014480 =====

undefined8 CissAdapterControl(uint *param_1,int param_2,longlong param_3)

{
  char cVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 4) = 0x101;
    *(undefined1 *)(param_3 + 6) = 1;
    *(undefined1 *)(param_3 + 8) = 1;
  }
  else if (param_2 == 1) {
    if ((param_1[0x27d6] == 2) && (uVar2 = 0, *(short *)((longlong)param_1 + 0x9f6a) != 0)) {
      do {
        if ((uint)uVar2 < 4) {
          **(uint **)(param_1 + uVar2 * 2 + 0x34) = **(uint **)(param_1 + uVar2 * 2 + 0x34) | 1;
          LOCK();
          UNLOCK();
        }
        uVar4 = (uint)uVar2 + 1;
        uVar2 = (ulonglong)uVar4;
      } while (uVar4 < *(ushort *)((longlong)param_1 + 0x9f6a));
    }
    (**(code **)(param_1 + 0x50))(param_1);
    *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] | 0x30;
    if ((param_1[0x27de] == 0) && ((param_1[0x24e6] & 2) == 0)) {
      CoalescingFlushAllLUNs(param_1);
      puVar6 = param_1 + 0x27db;
      for (lVar3 = 5; lVar3 != 0; lVar3 = lVar3 + -1) {
        *(undefined2 *)puVar6 = 0;
        puVar6 = (uint *)((longlong)puVar6 + 2);
      }
      param_1[0x24e6] = param_1[0x24e6] | 0x1000;
      CissCancelNotifyOnEvent(param_1);
      uVar2 = CissFlushCache(param_1,0);
      if ((char)uVar2 != '\0') {
        iVar5 = 1200000;
        do {
          StorPortStallExecution(0x32);
          if (param_1[0x27d6] == 0) {
            CissIsr(param_1);
          }
          else {
            CissImsr(param_1,0);
          }
        } while (((*(char *)(*(longlong *)(param_1 + 0x24fa) + 0x438) != '\0') && (iVar5 != 0)) &&
                (iVar5 = iVar5 + -1, iVar5 != 0));
      }
    }
  }
  else if (param_2 == 2) {
    cVar1 = (**(code **)(param_1 + 0x5a))();
    uVar4 = 0;
    while (cVar1 == '\0') {
      if (3599999 < uVar4) {
        return 1;
      }
      StorPortStallExecution(0x32);
      cVar1 = (**(code **)(param_1 + 0x5a))(param_1);
      uVar4 = uVar4 + 1;
    }
    InitializeUncachedExtension(param_1);
    CissInitialize(param_1);
  }
  else if (param_2 != 4) {
    return 1;
  }
  return 0;
}



===== CissFindAdapter @ 00014624 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CissFindAdapter(uint *param_1,undefined8 param_2,undefined8 param_3,void *param_4,
                         uint *param_5,undefined1 *param_6)

{
  uint *puVar1;
  char *pcVar2;
  char cVar3;
  longlong lVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  longlong lVar8;
  void *pvVar9;
  ulonglong uVar10;
  undefined **ppuVar11;
  ushort uVar12;
  ushort uVar13;
  longlong lVar14;
  undefined1 *puVar15;
  uint uVar16;
  char *pcVar17;
  int *piVar18;
  uint uVar19;
  undefined1 auStackY_228 [32];
  uint local_1e8 [2];
  undefined1 local_1e0 [16];
  undefined1 local_1d0 [8];
  int local_1c8 [24];
  undefined1 local_168 [2];
  undefined2 local_166;
  byte local_164;
  undefined2 local_13c;
  undefined2 local_13a;
  undefined1 local_68 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_228;
  pcVar17 = "dump=1;";
  *param_6 = 1;
  uVar12 = (ushort)param_1[0x27d9] & 0xff72;
  uVar13 = uVar12 | 0x22;
  *(ushort *)(param_1 + 0x27d9) = uVar13;
  do {
    pcVar2 = pcVar17 + (longlong)param_4 + -0x1b5e0;
    cVar3 = *pcVar17;
    pcVar17 = pcVar17 + 1;
    if (*pcVar2 != cVar3) {
      *param_1 = *param_1 & 0xefffffff;
      uVar12 = uVar13 & 0xffdf | 0x80;
      goto LAB_000146d7;
    }
  } while (*pcVar2 != '\0');
  *param_1 = *param_1 | 0x10000000;
  uVar12 = uVar12 | 0x22;
LAB_000146d7:
  *(ushort *)(param_1 + 0x27d9) = uVar12;
  memset(local_168,0,0x100);
  memset(local_1c8,0,0x5c);
  uVar16 = param_5[0x19];
  param_1[0x277c] = uVar16;
  iVar6 = StorPortGetBusData(param_1,4,param_5[1],uVar16);
  if (iVar6 == 0) {
LAB_00014733:
    uVar10 = 2;
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x92fa) = 3;
    *(undefined2 *)(param_1 + 0x24be) = local_166;
    param_1[0x24bd] = CONCAT22(local_13a,local_13c);
    *(char *)(param_1 + 0x24bc) = (char)param_5[1];
    *(byte *)((longlong)param_1 + 0x92f2) = (byte)(uVar16 >> 5) & 7;
    *(byte *)((longlong)param_1 + 0x92f1) = (byte)uVar16 & 0x1f;
    if ((local_164 & 2) == 0) {
      uVar10 = 0;
    }
    else {
      uVar16 = param_5[0xd];
      if ((CONCAT22(local_13a,local_13c) + 0xbf63f1ef & 0xfffeffff) == 0) {
        uVar16 = uVar16 - 1;
      }
      if ((local_164 & 1) == 0) {
        uVar16 = uVar16 - 1;
      }
      param_1[8] = 0;
      param_1[9] = 0;
      param_1[10] = 0;
      param_1[0xb] = 0;
      param_1[0xc] = 0;
      param_1[0xd] = 0;
      uVar19 = 0;
      if (uVar16 != 0) {
        lVar14 = 0;
        do {
          lVar4 = *(longlong *)(param_5 + 0xe);
          lVar8 = StorPortGetDeviceBase
                            (param_1,param_5[2],param_5[1],*(undefined8 *)(lVar14 + lVar4));
          if (lVar8 == 0) break;
          if (*(char *)(lVar14 + 0xc + lVar4) == '\0') {
            *(longlong *)(param_1 + 0xc) = lVar8;
            param_1[0x277a] = *(uint *)(lVar14 + lVar4);
          }
          else if (*(longlong *)(param_1 + 8) == 0) {
            *(longlong *)(param_1 + 8) = lVar8;
            *(undefined8 *)(param_1 + 0x2508) = *(undefined8 *)(lVar14 + lVar4);
          }
          else {
            *(longlong *)(param_1 + 10) = lVar8;
            *(undefined8 *)(param_1 + 0x250a) = *(undefined8 *)(lVar14 + lVar4);
          }
          uVar19 = uVar19 + 1;
          lVar14 = lVar14 + 0x10;
        } while (uVar19 < uVar16);
      }
      *(longlong *)(param_1 + 0x24) = *(longlong *)(param_1 + 8) + 0xb0;
      *(code **)(param_1 + 0x5a) = HbaFinishedPost;
      uVar7 = HbaFinishedPost((longlong)param_1);
      uVar16 = 0;
      while ((char)uVar7 == '\0') {
        if (3599999 < uVar16) goto LAB_00014733;
        StorPortStallExecution(0x32);
        uVar7 = (**(code **)(param_1 + 0x5a))(param_1);
        uVar16 = uVar16 + 1;
      }
      lVar14 = *(longlong *)(param_1 + 8);
      *(longlong *)(param_1 + 0x10) = lVar14 + 0xb8;
      *(longlong *)(param_1 + 0xe) = lVar14 + 0xb4;
      *(longlong *)(param_1 + 0x14) = lVar14 + 0x44;
      *(longlong *)(param_1 + 0x16) = lVar14 + 0x20;
      *(longlong *)(param_1 + 0x18) = lVar14 + 0x30;
      *(longlong *)(param_1 + 0x1a) = lVar14 + 0x34;
      *(longlong *)(param_1 + 0x2a) = lVar14 + 0xc4;
      *(longlong *)(param_1 + 0x2c) = lVar14 + 0xc0;
      *(longlong *)(param_1 + 0x2e) = lVar14 + 0xcc;
      *(longlong *)(param_1 + 0x30) = lVar14 + 200;
      *(longlong *)(param_1 + 0x12) = lVar14 + 0x40;
      if (**(uint **)(param_1 + 0x10) == 0) {
        lVar14 = *(longlong *)(param_1 + 10);
      }
      else {
        lVar14 = (ulonglong)**(uint **)(param_1 + 0x10) + *(longlong *)(param_1 + 8);
      }
      *(longlong *)(param_1 + 0x32) = lVar14;
      *(longlong *)(param_1 + 0x1c) = lVar14 + 0x10;
      *(longlong *)(param_1 + 0x22) = lVar14 + 0x14;
      *(longlong *)(param_1 + 0x1e) = *(longlong *)(param_1 + 8) + 0x9c;
      *(longlong *)(param_1 + 0x20) = *(longlong *)(param_1 + 8) + 0xa0;
      *(longlong *)(param_1 + 0x26) = lVar14 + 0x28;
      *(longlong *)(param_1 + 0x28) = lVar14 + 0x40;
      CRTL_sprintf((longlong)param_1 + 0x9f36,0x1b5f0,(ulonglong)(byte)param_1[0x24bc],
                   (ulonglong)*(byte *)((longlong)param_1 + 0x92f1));
      *(code **)(param_1 + 0x58) = SetTransportMethod;
      *(undefined1 **)(param_1 + 0x5c) = &GetHeartBeat;
      *(code **)(param_1 + 0x60) = GetConfigTable;
      *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] & 0xfdff;
      param_1[0x5e] = 0;
      param_1[0x5f] = 0;
      local_1e8[0] = 0x20;
      pvVar9 = (void *)StorPortAllocateRegistryBuffer(param_1,local_1e8);
      if (pvVar9 == (void *)0x0) {
        bVar5 = false;
      }
      else {
        bVar5 = CissReadWriteRegistry(param_1,"DriverParameter",1,local_68,local_1e8,pvVar9);
      }
      if (bVar5 == false) {
        memcpy(local_68,param_4,0x20);
      }
      SetSecurity((longlong)param_1,(longlong)local_68);
      uVar13 = (ushort)param_1[0x27d9] & 0xff72;
      *(ushort *)(param_1 + 0x27d9) = uVar13 | 0x2022;
      if ((*param_1 & 0x10000000) == 0) {
        *(ushort *)(param_1 + 0x27d9) = uVar13 | 0x2022;
        CissAccessRegistry(param_1);
      }
      (**(code **)(param_1 + 0x58))(param_1);
      param_1[0x277d] = **(uint **)(param_1 + 0x1a);
      (**(code **)(param_1 + 0x50))(param_1);
      puVar15 = *(undefined1 **)(param_1 + 0x32);
      piVar18 = local_1c8;
      for (lVar14 = 0x5c; lVar14 != 0; lVar14 = lVar14 + -1) {
        *(undefined1 *)piVar18 = *puVar15;
        puVar15 = puVar15 + 1;
        piVar18 = (int *)((longlong)piVar18 + 1);
      }
      if (local_1c8[0] != 0x53534943) goto LAB_00014733;
      if ((*param_1 & 0x10000000) == 0) {
        uVar16 = param_1[0x2793];
        if (uVar16 == 0) {
          uVar16 = param_1[0x2786];
        }
        uVar19 = 0x200;
        if (uVar16 - 0x10 < 0x1f0) {
          uVar19 = uVar16;
        }
        param_1[0x277b] = uVar19;
      }
      else {
        param_1[0x277b] = 0x10;
      }
      uVar16 = param_1[0x278f];
      if ((uVar16 < 2) || ((param_1[0x27d9] & 0xf) == 2)) {
        uVar16 = 0x1f;
        *(undefined2 *)(param_1 + 0x27d7) = 0x1f;
      }
      else if (uVar16 < 0xff) {
        *(short *)(param_1 + 0x27d7) = (short)uVar16;
      }
      else {
        if (0xff < uVar16) {
          uVar16 = 0xff;
        }
        *(undefined2 *)(param_1 + 0x27d7) = 0xff;
      }
      if (*(ushort *)((longlong)param_1 + 0x9f5e) == 0) {
        *(short *)((longlong)param_1 + 0x9f5e) = (short)uVar16;
      }
      else {
        if (uVar16 < *(ushort *)((longlong)param_1 + 0x9f5e)) {
          *(short *)((longlong)param_1 + 0x9f5e) = (short)uVar16;
        }
        *(undefined2 *)(param_1 + 0x27d7) = *(undefined2 *)((longlong)param_1 + 0x9f5e);
      }
      uVar10 = InitializeCommon(param_1,param_5);
      uVar10 = uVar10 & 0xffffffff;
    }
    if ((int)uVar10 == 1) {
      *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] & 0xffef;
      *(undefined1 *)((longlong)param_5 + 0x93) = 1;
      if ((param_1[0x27d9] & 0x1000) == 0) {
        param_1[0x3c] = 4;
        ppuVar11 = &CissWmiGuidList;
      }
      else {
        param_1[0x3c] = 6;
        ppuVar11 = &CissDiagWmiGuidList;
      }
      *(undefined ***)(param_1 + 0x3e) = ppuVar11;
      param_1[0x44] = 0;
      param_1[0x45] = 0;
      param_1[0x46] = 0;
      param_1[0x47] = 0;
      param_1[0x48] = 0;
      param_1[0x49] = 0;
      puVar1 = param_1 + 0x2828;
      *(undefined1 **)(param_1 + 0x40) = &CissWmiQueryReginfo;
      *(code **)(param_1 + 0x42) = CissWmiQueryDataBlock;
      *(code **)(param_1 + 0x4a) = CissWmiFunctionControl;
      *(undefined1 *)((longlong)param_1 + 2) = 1;
      puVar1[0] = 0;
      puVar1[1] = 0;
      iVar6 = StorPortExtendedFunction(8,param_1,local_1e0,local_1d0);
      if (iVar6 == 0) {
        puVar1[0] = 0xffffffff;
        puVar1[1] = 0xffffffff;
      }
      if (*(longlong *)puVar1 == 0) {
        StorPortNotification(0xf,param_1,puVar1);
      }
      return 1;
    }
  }
  param_1[0x24e6] = param_1[0x24e6] | 2;
  if (*(longlong *)(param_1 + 8) != 0) {
    StorPortFreeDeviceBase(param_1);
  }
  if (*(longlong *)(param_1 + 10) != 0) {
    StorPortFreeDeviceBase(param_1);
  }
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  StorPortLogError(param_1,0,0xff,0xff);
  return uVar10;
}



===== SetSecurity @ 00014d18 =====

void SetSecurity(longlong param_1,longlong param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  
  pcVar3 = "CSMI=Full;";
  do {
    pcVar1 = pcVar3 + param_2 + -0x1b630;
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    if (*pcVar1 != cVar2) {
      pcVar3 = "CSMI=Limited;";
      do {
        pcVar1 = pcVar3 + param_2 + -0x1b640;
        cVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        if (*pcVar1 != cVar2) {
          pcVar3 = "CSMI=Restricted;";
          do {
            pcVar1 = pcVar3 + param_2 + -0x1b650;
            cVar2 = *pcVar3;
            pcVar3 = pcVar3 + 1;
            if (*pcVar1 != cVar2) {
              pcVar3 = "CSMI=None;";
              do {
                pcVar1 = pcVar3 + param_2 + -0x1b670;
                cVar2 = *pcVar3;
                pcVar3 = pcVar3 + 1;
                if (*pcVar1 != cVar2) {
                  return;
                }
              } while (*pcVar1 != '\0');
              *(undefined4 *)(param_1 + 0x9e60) = 0;
              return;
            }
          } while (*pcVar1 != '\0');
          *(undefined4 *)(param_1 + 0x9e60) = 1;
          return;
        }
      } while (*pcVar1 != '\0');
      *(undefined4 *)(param_1 + 0x9e60) = 2;
      return;
    }
  } while (*pcVar1 != '\0');
  *(undefined4 *)(param_1 + 0x9e60) = 3;
  return;
}



===== CissReadWriteRegistry @ 00014dd0 =====

bool CissReadWriteRegistry
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,void *param_4,uint *param_5
               ,void *param_6)

{
  char cVar1;
  
  cVar1 = StorPortRegistryRead(param_1,param_2,1,param_3,param_6,param_5);
  if (cVar1 != '\0') {
    memset(param_4,0,0x20);
    memcpy(param_4,param_6,(ulonglong)*param_5);
  }
  StorPortFreeRegistryBuffer(param_1,param_6);
  return cVar1 != '\0';
}



===== CissAccessRegistry @ 00014e64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000151aa) */

void CissAccessRegistry(uint *param_1)

{
  bool bVar1;
  ushort uVar2;
  void *pvVar3;
  undefined1 auStackY_78 [32];
  uint local_48 [2];
  ushort local_40 [16];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  local_48[0] = 0x20;
  pvVar3 = (void *)StorPortAllocateRegistryBuffer(param_1,local_48);
  if (pvVar3 == (void *)0x0) {
    bVar1 = false;
  }
  else {
    bVar1 = CissReadWriteRegistry(param_1,&s_Tracing,3,local_40,local_48,pvVar3);
  }
  if ((bVar1 != false) && ((char)local_40[0] == '\x01')) {
    *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] | 0x200;
  }
  local_48[0] = 0x20;
  pvVar3 = (void *)StorPortAllocateRegistryBuffer(param_1,local_48);
  if (pvVar3 == (void *)0x0) {
    bVar1 = false;
  }
  else {
    bVar1 = CissReadWriteRegistry(param_1,"TransportMode",3,local_40,local_48,pvVar3);
  }
  if (bVar1 != false) {
    if ((char)local_40[0] == '\0') {
      uVar2 = (ushort)param_1[0x27d9] & 0xfff2 | 2;
    }
    else {
      if ((char)local_40[0] != '\x01') goto LAB_00014f71;
      uVar2 = (ushort)param_1[0x27d9] & 0xfff4 | 4;
    }
    *(ushort *)(param_1 + 0x27d9) = uVar2;
  }
LAB_00014f71:
  local_48[0] = 0x20;
  pvVar3 = (void *)StorPortAllocateRegistryBuffer(param_1,local_48);
  if (pvVar3 == (void *)0x0) {
    bVar1 = false;
  }
  else {
    bVar1 = CissReadWriteRegistry(param_1,"Coalescing",3,local_40,local_48,pvVar3);
  }
  if (bVar1 != false) {
    if ((char)local_40[0] == '\0') {
      uVar2 = (ushort)param_1[0x27d9] & 0xff7f | 0x20;
    }
    else {
      if ((char)local_40[0] != '\x01') goto LAB_00014ff6;
      uVar2 = (ushort)param_1[0x27d9] & 0xffdf | 0x80;
    }
    *(ushort *)(param_1 + 0x27d9) = uVar2;
  }
LAB_00014ff6:
  local_48[0] = 0x20;
  pvVar3 = (void *)StorPortAllocateRegistryBuffer(param_1,local_48);
  if (pvVar3 == (void *)0x0) {
    bVar1 = false;
  }
  else {
    bVar1 = CissReadWriteRegistry(param_1,"ReadLimit",4,local_40,local_48,pvVar3);
  }
  if (bVar1 != false) {
    if (local_40[0] < 0x31) {
      if ((local_40[0] - 8 < 0x29) && ((local_40[0] - 8 & 7) == 0)) {
LAB_00015065:
        param_1[0x2799] = (uint)local_40[0] << 10;
      }
    }
    else if ((((local_40[0] == 0x38) || (local_40[0] == 0x40)) || (local_40[0] == 0x80)) ||
            (local_40[0] == 0x100)) goto LAB_00015065;
  }
  local_48[0] = 0x20;
  pvVar3 = (void *)StorPortAllocateRegistryBuffer(param_1,local_48);
  if (pvVar3 == (void *)0x0) {
    bVar1 = false;
  }
  else {
    bVar1 = CissReadWriteRegistry(param_1,"WriteLimit",4,local_40,local_48,pvVar3);
  }
  if (bVar1 != false) {
    if (local_40[0] < 0x31) {
      if ((0x28 < local_40[0] - 8) || ((local_40[0] - 8 & 7) != 0)) goto LAB_000150ee;
    }
    else if (((local_40[0] != 0x38) && (local_40[0] != 0x40)) &&
            ((local_40[0] != 0x80 && ((local_40[0] != 0x100 && (local_40[0] != 0x1c0))))))
    goto LAB_000150ee;
    param_1[0x279a] = (uint)local_40[0] << 10;
  }
LAB_000150ee:
  *(undefined2 *)(param_1 + 0x27d8) = 0xfe;
  local_48[0] = 0x20;
  pvVar3 = (void *)StorPortAllocateRegistryBuffer(param_1,local_48);
  if (pvVar3 == (void *)0x0) {
    bVar1 = false;
  }
  else {
    bVar1 = CissReadWriteRegistry(param_1,"MaxDeviceQueueDepth",4,local_40,local_48,pvVar3);
  }
  if ((bVar1 != false) && (local_40[0] < 0xfe)) {
    *(ushort *)(param_1 + 0x27d8) = local_40[0];
  }
  *(undefined2 *)(param_1 + 0x27da) = 0;
  local_48[0] = 0x20;
  pvVar3 = (void *)StorPortAllocateRegistryBuffer(param_1,local_48);
  if (pvVar3 == (void *)0x0) {
    bVar1 = false;
  }
  else {
    bVar1 = CissReadWriteRegistry(param_1,"MaxTransfer",4,local_40,local_48,pvVar3);
  }
  if ((bVar1 != false) && ((local_40[0] & 3) == 0)) {
    *(ushort *)(param_1 + 0x27da) = local_40[0];
  }
  *(undefined2 *)((longlong)param_1 + 0x9f66) = 1;
  local_48[0] = 0x20;
  pvVar3 = (void *)StorPortAllocateRegistryBuffer(param_1,local_48);
  if (pvVar3 == (void *)0x0) {
    bVar1 = false;
  }
  else {
    bVar1 = CissReadWriteRegistry(param_1,"EnableNOE",3,local_40,local_48,pvVar3);
  }
  if (bVar1 != false) {
    if ((char)local_40[0] == '\x01') {
      *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] | 0x1000;
    }
    else {
      *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] & 0xefff;
    }
  }
  *param_1 = *param_1 | 0xff00;
  if (*(char *)((longlong)param_1 + 1) == -1) {
    *(undefined1 *)((longlong)param_1 + 1) = 0;
  }
  return;
}



===== FUN_00015268 @ 00015268 =====

undefined8 FUN_00015268(longlong param_1)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if ((**(uint **)(param_1 + 0x58) & 1) == 0) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 1200000);
  StorPortStallExecution(0x32);
  uVar1 = StorPortNotification(0x1001,param_1,param_1 + 0x9350,CissDpc);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== CissInitialize @ 000152c8 =====

undefined8 CissInitialize(uint *param_1)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  longlong lVar11;
  uint *puVar12;
  uint uVar13;
  longlong lVar14;
  ulonglong *puVar15;
  undefined4 local_res8 [2];
  undefined1 local_48 [8];
  undefined4 local_40;
  uint local_3c;
  
  uVar13 = 0;
  param_1[0x27d6] = 0;
  *param_1 = *param_1 & 0xf5ffffff | 0x5000000;
  if (*(char *)((longlong)param_1 + 1) == '\0') {
    sVar1 = (short)param_1[0x24be];
    *(undefined2 *)((longlong)param_1 + 0x9f6a) = 0;
    if ((((sVar1 != 0x46) && (sVar1 != 0x3220)) && (sVar1 != -0x4fa0)) && (sVar1 != -0x4e88)) {
      CissGetMessageInfo(param_1);
    }
    CissSetInterruptMode((longlong)param_1);
    iVar5 = StorPortExtendedFunction(0xe,param_1,1,local_48);
    if (iVar5 == 0) {
      local_40 = 1;
      local_3c = (uint)*(ushort *)((longlong)param_1 + 0x9f66);
      StorPortExtendedFunction(0xe,param_1,0,local_48);
    }
  }
  (**(code **)(param_1 + 0x4c))(param_1);
  uVar2 = (ushort)param_1[0x27d9];
  if ((uVar2 & 0x100) != 0) {
    *(ushort *)(param_1 + 0x27d9) = uVar2 & 0xffef;
    goto LAB_00015438;
  }
  param_1[0x24e8] = 0xffff;
  *(ushort *)(param_1 + 0x27d9) = uVar2 | 0x100;
  if ((*param_1 & 0x10000000) == 0) {
    local_res8[0] = 0;
    StorPortNotification(0x1000,param_1,FUN_00015268,local_res8);
    if ((char)local_res8[0] == '\0') goto LAB_000153ec;
    *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] & 0xffef;
  }
  else {
LAB_000153ec:
    *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] | 0x10;
    uVar6 = 0;
    do {
      if ((**(uint **)(param_1 + 0x16) & 1) == 0) break;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 1200000);
    StorPortStallExecution(0x32);
  }
  InitializeDeviceTable((longlong)param_1);
LAB_00015438:
  lVar11 = 0;
  puVar7 = param_1 + 0x1cbe;
  puVar12 = param_1 + 0x1cc0;
  lVar14 = 0x200;
  do {
    *(longlong *)(puVar7 + -2) = lVar11;
    *(uint **)puVar7 = puVar12;
    lVar11 = lVar11 + 1;
    puVar12 = puVar12 + 4;
    puVar7 = puVar7 + 4;
    lVar14 = lVar14 + -1;
  } while (lVar14 != 0);
  *(uint **)(param_1 + 0x250c) = param_1 + 0x1cbc;
  *(uint **)(param_1 + 0x2776) = param_1 + 0x24b8;
  *(undefined8 *)(*(longlong *)(param_1 + 0x2776) + 8) = 0;
  if ((param_1[0x27d9] & 0xf) == 2) {
    do {
      if ((int)param_1[0x2780] < 0) {
        if (**(int **)(param_1 + 0x2e) == -1) break;
        piVar8 = *(int **)(param_1 + 0x30);
      }
      else {
        piVar8 = *(int **)(param_1 + 0x14);
      }
    } while (*piVar8 != -1);
  }
  if ((*param_1 & 0x10000000) == 0) {
    *(undefined1 *)(*(longlong *)(param_1 + 0x24f4) + 0x231) = 0;
    *(undefined1 *)(*(longlong *)(param_1 + 0x24f6) + 0x231) = 0;
  }
  *(undefined1 *)(*(longlong *)(param_1 + 0x24fa) + 0x438) = 0;
  *(undefined1 *)(*(longlong *)(param_1 + 0x24f2) + 0x19f2) = 0;
  *(undefined1 *)(*(longlong *)(param_1 + 0x24f8) + 0x230) = 0;
  *(undefined1 *)(*(longlong *)(param_1 + 0x24fc) + 0x3d8) = 0;
  *(undefined1 *)(*(longlong *)(param_1 + 0x24fe) + 0x1d8) = 0;
  param_1[0x27de] = 0;
  param_1[0x277d] = 0;
  uVar6 = (**(code **)(param_1 + 0x5c))(param_1);
  param_1[0x18e6] = 0;
  param_1[0x24e6] = 0;
  param_1[1] = uVar6;
  param_1[0x2826] = 0;
  param_1[100] = 0;
  param_1[0x2795] = 0;
  param_1[0x18e5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)((longlong)param_1 + 0x9f35) = 0;
  *(undefined2 *)(param_1 + 0x279b) = 0x100;
  puVar7 = param_1 + 0x2516;
  uVar6 = 1;
  param_1[0x2775] = 0x78;
  *(uint **)(param_1 + 0x2772) = puVar7;
  param_1[0x2774] = 0x13;
  param_1[0x2770] = 0;
  param_1[0x2771] = 0;
  param_1[0x276e] = 0;
  param_1[0x276f] = 0;
  puVar7[0] = 0xffff;
  puVar7[1] = 0;
  do {
    uVar3 = param_1[0x2775];
    lVar11 = *(longlong *)(param_1 + 0x2772);
    puVar15 = (ulonglong *)((ulonglong)(uVar3 * uVar6) + lVar11);
    do {
      uVar4 = *(ulonglong *)(param_1 + 0x276e);
      *puVar15 = uVar4 & 0xffff;
      LOCK();
      uVar9 = *(ulonglong *)(param_1 + 0x276e);
      if (uVar4 == uVar9) {
        *(ulonglong *)(param_1 + 0x276e) =
             (uVar4 & 0xffffffffffff0000) + 0x10000 |
             (ulonglong)((longlong)puVar15 - lVar11) / (ulonglong)uVar3 & 0xffffffff;
        uVar9 = uVar4;
      }
      else {
      }
      UNLOCK();
    } while (uVar4 != uVar9);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x13);
  param_1[0x2515] = 0x78;
  param_1[0x2514] = 0x13;
  param_1[0x2510] = 0x13;
  param_1[0x2511] = 0;
  *(uint **)(param_1 + 0x2512) = puVar7;
  param_1[0x250e] = 0x13;
  param_1[0x250f] = 0;
  *(undefined8 *)((ulonglong)(param_1[0x2515] * 0x13) + (longlong)puVar7) = 0xffff;
  StorPortPause(param_1);
  uVar6 = param_1[0x27d9];
  *(ushort *)(param_1 + 0x27d9) = (ushort)uVar6 | 0x20;
  if ((*param_1 & 0x10000000) != 0) {
    uVar9 = CissSendReportLogicalLuns(param_1,0);
    if ((char)uVar9 == '\x01') {
      do {
        StorPortStallExecution(0x32);
        if (param_1[0x27d6] == 0) {
          CissIsr(param_1);
        }
        else {
          CissImsr(param_1,0);
        }
        uVar13 = uVar13 + 1;
      } while ((*(char *)(*(longlong *)(param_1 + 0x24f2) + 0x19f2) == '\x01') && (uVar13 < 400000))
      ;
    }
    uVar9 = CissSendReportPhysicalLuns(param_1,0);
    if ((char)uVar9 == '\x01') {
      uVar13 = 0;
      do {
        StorPortStallExecution(0x32);
        if (param_1[0x27d6] == 0) {
          CissIsr(param_1);
        }
        else {
          CissImsr(param_1,0);
        }
        uVar13 = uVar13 + 1;
      } while ((*(char *)(*(longlong *)(param_1 + 0x24f2) + 0x19f2) == '\x01') && (uVar13 < 400000))
      ;
    }
  }
  *(ushort *)(param_1 + 0x27d9) =
       (ushort)param_1[0x27d9] ^ (((ushort)uVar6 >> 5 & 1) << 5 ^ (ushort)param_1[0x27d9]) & 0x20;
  StorPortResume(param_1);
  if ((param_1[0x27d6] == 2) && (uVar13 = 0, *(short *)((longlong)param_1 + 0x9f6a) != 0)) {
    do {
      if (uVar13 < 4) {
        **(uint **)(param_1 + (ulonglong)uVar13 * 2 + 0x34) =
             **(uint **)(param_1 + (ulonglong)uVar13 * 2 + 0x34) & 0xfffffffe;
        LOCK();
        UNLOCK();
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < *(ushort *)((longlong)param_1 + 0x9f6a));
  }
  (**(code **)(param_1 + 0x4e))(param_1);
  puVar7 = param_1 + 0x27db;
  for (lVar11 = 5; lVar11 != 0; lVar11 = lVar11 + -1) {
    *(undefined2 *)puVar7 = 0;
    puVar7 = (uint *)((longlong)puVar7 + 2);
  }
  *(undefined2 *)(param_1 + 0x27db) = 1;
  uVar10 = StorPortNotification(6,param_1,TimerTick,1000000);
  return CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
}



===== InitializeCommon @ 000157e8 =====

undefined8 InitializeCommon(uint *param_1,uint *param_2)

{
  short sVar1;
  ushort uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  uVar4 = 1;
  if (param_2 == (uint *)0x0) {
    uVar4 = 0;
    StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x266);
  }
  else {
    if ((short)param_1[0x27da] == 0) {
      uVar2 = 0x8000;
      do {
        if (uVar2 <= *(ushort *)((longlong)param_1 + 0x9f5e)) break;
        uVar2 = uVar2 >> 1;
      } while (uVar2 != 0);
      *(ushort *)(param_1 + 0x27da) = uVar2 << 2;
    }
    param_2[6] = (uint)(ushort)param_1[0x27da] << 10;
    uVar2 = *(ushort *)((longlong)param_1 + 0x9f5e);
    *(undefined1 *)(param_2 + 0x12) = 8;
    *(undefined1 *)((longlong)param_2 + 0x61) = 0x80;
    *(undefined1 *)((longlong)param_2 + 0x92) = 5;
    param_2[0xc] = 3;
    param_2[7] = (uint)uVar2;
    *(undefined2 *)((longlong)param_2 + 0x53) = 1;
    *(undefined1 *)((longlong)param_2 + 0x51) = 1;
    *(undefined1 *)((longlong)param_2 + 0x59) = 2;
    param_2[0x25] = 1;
    if ((char)param_2[0x24] == -0x80) {
      *(undefined1 *)(param_2 + 0x24) = 1;
    }
    *(undefined1 *)((longlong)param_2 + 0x91) = 1;
    sVar1 = (short)param_1[0x24be];
    if ((((sVar1 != 0x46) && (sVar1 != 0x3220)) && (sVar1 != -0x4fa0)) &&
       ((sVar1 != -0x4e88 && (0xa7 < *param_2)))) {
      param_2[0x28] = 1;
      *(code **)(param_2 + 0x26) = CissImsr;
    }
  }
  lVar3 = StorPortGetUncachedExtension
                    (param_1,param_2,(-(uint)((*param_1 & 0x10000000) != 0) & 0xffffe5c0) + 0x40f0);
  *(longlong *)(param_1 + 0x24f0) = lVar3;
  if (lVar3 == 0) {
    uVar4 = 0;
    StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x29c);
  }
  else {
    InitializeUncachedExtension(param_1);
  }
  return uVar4;
}



===== InitializeUncachedExtension @ 00015974 =====

void InitializeUncachedExtension(uint *param_1)

{
  void *_Dst;
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  _Dst = *(void **)(param_1 + 0x24f0);
  *(void **)(param_1 + 0x24f2) = _Dst;
  *(longlong *)(param_1 + 0x24f8) = (longlong)_Dst + 0x1a58;
  *(longlong *)(param_1 + 0x24fa) = (longlong)_Dst + 0x1c98;
  *(longlong *)(param_1 + 0x24fc) = (longlong)_Dst + 0x20e0;
  *(longlong *)(param_1 + 0x24fe) = (longlong)_Dst + 0x24c8;
  if ((*param_1 & 0x10000000) == 0) {
    memset(_Dst,0,0x40f0);
    *(longlong *)(param_1 + 0x2502) = (longlong)_Dst + 0x3e68;
    *(longlong *)(param_1 + 0x2504) = (longlong)_Dst + 0x3ee8;
    *(longlong *)(param_1 + 0x2500) = (longlong)_Dst + 0x26b0;
    lVar3 = 8;
    *(ulonglong *)(param_1 + 0x27e0) = (longlong)_Dst + 0x26f0U & 0xffffffffffffffc0;
    lVar1 = 0;
    lVar2 = 0;
    do {
      lVar1 = lVar1 + 0x40;
      *(undefined2 *)(*(longlong *)(param_1 + 0x27e0) + -0x10 + lVar1) = 0xffff;
      *(undefined4 *)(lVar2 + *(longlong *)(param_1 + 0x27e0)) = 0;
      lVar2 = lVar2 + 0x40;
      *(undefined4 *)(*(longlong *)(param_1 + 0x27e0) + -0x3c + lVar2) = 0;
      *(undefined2 *)(*(longlong *)(param_1 + 0x27e0) + -10 + lVar1) = 0;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    *(longlong *)(param_1 + 0x24f4) = (longlong)_Dst + 0x29b8;
    *(longlong *)(param_1 + 0x24f6) = (longlong)_Dst + 0x2bf8;
    *(longlong **)(param_1 + 0x27e2) = (longlong *)((longlong)_Dst + 0x2e38);
    *(longlong *)((longlong)_Dst + 0x2e38) = (longlong)_Dst + 0x2e48;
    **(longlong **)(param_1 + 0x27e2) = **(longlong **)(param_1 + 0x27e2) + 0x20;
    **(ulonglong **)(param_1 + 0x27e2) = **(ulonglong **)(param_1 + 0x27e2) & 0xffffffffffffffe0;
  }
  else {
    memset(_Dst,0,0x26b0);
  }
  return;
}



===== InitializeDeviceTable @ 00015ad4 =====

void InitializeDeviceTable(longlong param_1)

{
  uint *_Dst;
  uint *puVar1;
  longlong lVar2;
  
  _Dst = (uint *)(param_1 + 0x194);
  memset(_Dst,0,0x6200);
  lVar2 = 0x380;
  puVar1 = _Dst;
  do {
    *puVar1 = *puVar1 | 0x10;
    puVar1 = puVar1 + 7;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  puVar1 = (uint *)(param_1 + 0x639c);
  memset(puVar1,0,0xf50);
  lVar2 = 0x8c;
  do {
    *puVar1 = *puVar1 | 0x10;
    puVar1 = puVar1 + 7;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  lVar2 = 0x80;
  puVar1 = _Dst;
  do {
    *puVar1 = *puVar1 | 1;
    puVar1 = puVar1 + 7;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  *(uint *)(param_1 + 0x1b0) = *(uint *)(param_1 + 0x1b0) & 0xffffffef | 0x1000;
  *(uint *)(param_1 + 0x1cc) = *(uint *)(param_1 + 0x1cc) & 0xffffffef | 0x200;
  *(uint *)(param_1 + 0x1e8) = *(uint *)(param_1 + 0x1e8) & 0xffffffef | 0x400;
  *_Dst = *_Dst & 0xffffffef | 0x800;
  return;
}



===== CissGetMessageInfo @ 00015ba8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CissGetMessageInfo(uint *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_58 [32];
  undefined1 local_38 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  if (*(longlong *)(param_1 + 0x2828) != 0) {
    uVar2 = 0;
    do {
      memset(local_38,0,0x20);
      iVar1 = StorPortExtendedFunction(0xd,param_1,uVar2,local_38);
      if (iVar1 == 0) {
        *param_1 = *param_1 & 0xf6ffffff | 0x6000000;
        memcpy((void *)((ulonglong)uVar2 * 0x20 + *(longlong *)(param_1 + 0x2502)),local_38,0x20);
        *(short *)((longlong)param_1 + 0x9f6a) = *(short *)((longlong)param_1 + 0x9f6a) + 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
  }
  return;
}



===== CissSetInterruptMode @ 00015c60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CissSetInterruptMode(longlong param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  longlong lVar3;
  int iVar4;
  byte bVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined1 auStack_168 [32];
  char *local_148;
  uint local_140;
  undefined4 local_138;
  char local_128 [2];
  ushort uStack_126;
  uint auStack_124 [12];
  byte local_f4;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_168;
  pcVar6 = (char *)0x0;
  memset(local_128,0,0x100);
  if (*(short *)(param_1 + 0x9f6a) == 0) {
    return;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x9df0);
  local_148 = local_128;
  local_140 = 0x100;
  iVar4 = StorPortGetBusData(param_1,4,*(undefined1 *)(param_1 + 0x92f0),uVar2);
  if (iVar4 == 0) {
    return;
  }
  bVar5 = local_f4;
  do {
    uVar9 = (ulonglong)bVar5;
    if ((local_128[uVar9] == '\x11') && ((*(ushort *)(local_128 + uVar9 + 2) & 0x8000) != 0)) {
      *(undefined4 *)(param_1 + 0x9f58) = 2;
      break;
    }
    bVar5 = local_128[uVar9 + 1];
  } while (bVar5 != 0);
  if (*(int *)(param_1 + 0x9f58) != 2) {
    bVar5 = local_f4;
    do {
      pcVar6 = local_128 + bVar5;
      if ((*pcVar6 == '\x05') && ((local_128[(ulonglong)bVar5 + 2] & 1U) != 0)) {
        *(undefined4 *)(param_1 + 0x9f58) = 1;
        break;
      }
      bVar5 = local_128[(ulonglong)bVar5 + 1];
    } while (bVar5 != 0);
    if (*(int *)(param_1 + 0x9f58) != 2) goto LAB_00015dbd;
  }
  uVar8 = *(uint *)((longlong)auStack_124 + uVar9);
  uVar7 = 0;
  lVar3 = *(longlong *)(param_1 + 0x20);
  if ((*(ushort *)(local_128 + uVar9 + 2) & 0x7ff) != 0xffffffff) {
    uVar10 = 0;
    do {
      if (uVar7 < 4) {
        *(ulonglong *)(param_1 + 0xd0 + (ulonglong)uVar7 * 8) =
             (ulonglong)uVar10 + 0xc + ((ulonglong)uVar8 & 0xfffffff8) + lVar3;
      }
      uVar7 = uVar7 + 1;
      uVar10 = uVar10 + 0x10;
    } while (uVar7 < (*(ushort *)(local_128 + uVar9 + 2) & 0x7ff) + 1);
  }
LAB_00015dbd:
  if (((*(int *)(param_1 + 0x9f58) == 1) && (uVar1 = *(ushort *)(pcVar6 + 2), (char)uVar1 < '\0'))
     && ((uVar1 & 0x100) != 0)) {
    uVar8 = 1 << ((byte)(uVar1 >> 1) & 7);
    if (uVar8 != 0) {
      uVar7 = *(uint *)(pcVar6 + 0xe);
      uVar9 = (ulonglong)uVar8;
      uVar8 = 1;
      do {
        uVar7 = uVar7 & ~uVar8;
        uVar9 = uVar9 - 1;
        uVar8 = uVar8 * 2;
      } while (uVar9 != 0);
      *(uint *)(pcVar6 + 0xe) = uVar7;
    }
    local_148 = pcVar6 + 0xe;
    local_138 = 4;
    local_140 = (uint)bVar5;
    StorPortSetBusDataByOffset(param_1,4,*(undefined1 *)(param_1 + 0x92f0),uVar2);
  }
  return;
}



===== atol @ 00015e60 =====

long __cdecl atol(char *_Str)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  long lVar4;
  
  for (; (*_Str == 0x20 || (*_Str == 9)); _Str = _Str + 1) {
  }
  bVar1 = *_Str;
  pbVar3 = (byte *)(_Str + 1);
  bVar2 = bVar1;
  if ((bVar1 - 0x2b & 0xfffffffd) == 0) {
    bVar2 = *pbVar3;
    pbVar3 = (byte *)(_Str + 2);
  }
  lVar4 = 0;
  while ((0x2f < bVar2 && (bVar2 < 0x3a))) {
    lVar4 = (uint)bVar2 + (lVar4 * 5 + -0x18) * 2;
    bVar2 = *pbVar3;
    pbVar3 = pbVar3 + 1;
  }
  if (bVar1 == 0x2d) {
    lVar4 = -lVar4;
  }
  return lVar4;
}



===== FUN_00015ec0 @ 00015ec0 =====

ulonglong FUN_00015ec0(long *param_1,longlong param_2,int param_3,int param_4)

{
  char cVar1;
  long lVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  ulonglong uVar7;
  
  uVar7 = (ulonglong)param_3;
  for (pcVar5 = (char *)(param_2 + uVar7); *pcVar5 < '!'; pcVar5 = pcVar5 + 1) {
    uVar7 = (ulonglong)((int)uVar7 + 1);
  }
  pcVar5 = (char *)(param_2 + (int)uVar7);
  if (param_4 == 0) {
    if ('/' < *pcVar5) {
      cVar1 = *pcVar5;
      pcVar4 = pcVar5;
      do {
        if ('9' < cVar1) break;
        pcVar4 = pcVar4 + 1;
        uVar7 = (ulonglong)((int)uVar7 + 1);
        cVar1 = *pcVar4;
      } while ('/' < cVar1);
    }
    lVar2 = atol(pcVar5);
    *param_1 = lVar2;
  }
  else {
    if (' ' < *pcVar5) {
      pcVar4 = pcVar5;
      do {
        pcVar4 = pcVar4 + 1;
        uVar7 = (ulonglong)((int)uVar7 + 1);
      } while (' ' < *pcVar4);
    }
    iVar6 = 0;
    for (; cVar1 = *pcVar5, cVar1 != '\0'; pcVar5 = pcVar5 + 1) {
      uVar3 = (int)cVar1 - 0x30;
      if (9 < (int)uVar3) {
        uVar3 = (int)cVar1 - 0x37;
      }
      iVar6 = iVar6 * 0x10 + (uVar3 & 0xf);
    }
    *param_1 = iVar6;
  }
  return uVar7 & 0xffffffff;
}



===== FUN_00015f58 @ 00015f58 =====

int FUN_00015f58(ulonglong param_1,longlong param_2,int param_3,uint param_4)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = 10;
  iVar7 = 1000000000;
  iVar5 = 1000000000;
  do {
    if (param_1 / (ulonglong)(longlong)iVar5 != 0) break;
    iVar3 = iVar3 + -1;
    iVar5 = iVar5 / 10;
  } while (9 < iVar5);
  uVar6 = param_4 & 0xffff;
  if (((param_4 & 0x90000) == 0x10000) && (iVar3 < (int)(param_4 & 0xffff))) {
    pcVar2 = (char *)(param_3 + param_2);
    uVar4 = (ulonglong)(uVar6 - iVar3);
    param_3 = param_3 + (uVar6 - iVar3);
    do {
      *pcVar2 = (-((param_4 & 0x20000) != 0) & 0x10U) + 0x20;
      pcVar2 = pcVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  bVar1 = false;
  pcVar2 = (char *)(param_3 + param_2);
  do {
    uVar4 = (ulonglong)iVar7;
    iVar7 = iVar7 / 10;
    uVar4 = (param_1 % uVar4) / (ulonglong)(longlong)iVar7;
    if (uVar4 != 0) {
      bVar1 = true;
    }
    if (bVar1) {
      param_3 = param_3 + 1;
      *pcVar2 = "0123456789ABCDEF"[uVar4];
      pcVar2 = pcVar2 + 1;
    }
  } while (99 < iVar7);
  iVar5 = param_3 + 1;
  *(char *)(param_3 + param_2) = "0123456789ABCDEF"[param_1 % 10];
  if (((param_4 & 0x90000) == 0x90000) && (iVar3 < (int)uVar6)) {
    pcVar2 = (char *)(iVar5 + param_2);
    iVar5 = iVar5 + (uVar6 - iVar3);
    uVar4 = (ulonglong)(uVar6 - iVar3);
    do {
      *pcVar2 = (-((param_4 & 0x20000) != 0) & 0x10U) + 0x20;
      pcVar2 = pcVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return iVar5;
}



===== FUN_000160fc @ 000160fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00016392) */
/* WARNING: Removing unreachable block (ram,0x0001639a) */
/* WARNING: Removing unreachable block (ram,0x000163a2) */
/* WARNING: Removing unreachable block (ram,0x000163ae) */
/* WARNING: Removing unreachable block (ram,0x000163b6) */
/* WARNING: Removing unreachable block (ram,0x000161cb) */
/* WARNING: Removing unreachable block (ram,0x000161d1) */
/* WARNING: Removing unreachable block (ram,0x00016261) */
/* WARNING: Removing unreachable block (ram,0x000161d4) */

ulonglong FUN_000160fc(undefined8 param_1,char *param_2,longlong param_3,ulonglong *param_4)

{
  char cVar1;
  code *pcVar2;
  bool bVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  byte bVar8;
  int iVar9;
  char *pcVar10;
  byte bVar11;
  int iVar12;
  uint uVar13;
  ulonglong uVar14;
  char *pcVar15;
  uint uVar16;
  int iVar17;
  ulonglong uVar18;
  undefined1 auStack_98 [32];
  byte local_78;
  uint local_74;
  ulonglong *local_70;
  char *local_68;
  longlong local_60;
  ulonglong local_58;
  uint local_50 [2];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_98;
  bVar11 = 0;
  uVar14 = 0;
  uVar16 = 0;
  uVar6 = 0;
  local_78 = 0;
  local_74 = 0;
  uVar18 = 0xffffffffffffffff;
  do {
    uVar18 = uVar18 + 1;
  } while (*(char *)(param_3 + uVar18) != '\0');
  local_50[0] = 0;
  if (uVar18 == 0) {
    return 0;
  }
  uVar7 = 0;
  local_68 = param_2;
  local_60 = param_3;
  local_58 = uVar18;
  do {
    uVar13 = local_50[0];
    cVar1 = *(char *)(uVar7 + param_3);
    iVar12 = (int)uVar6;
    if (cVar1 == '%') {
      if ((local_50[0] == 0) || (*(char *)((uVar7 - 1) + param_3) != '%')) {
        uVar14 = 0;
        local_78 = bVar11 | 1;
        uVar16 = 0;
        local_74 = 0;
        uVar7 = uVar6;
      }
      else {
        local_68[uVar6] = '%';
LAB_0001650d:
        local_78 = bVar11 & 0xfe;
        uVar7 = (ulonglong)(iVar12 + 1);
      }
LAB_00016512:
      uVar6 = uVar7;
      uVar5 = uVar16;
      bVar11 = local_78;
    }
    else {
      param_2 = (char *)(CONCAT71((int7)((ulonglong)param_2 >> 8),bVar11) & 0xffffffffffffff01);
      if (((bVar11 & 1) != 0) && ((cVar1 == 'd' || (cVar1 == 'i')))) {
        uVar5 = (uint)*param_4;
        if ((int)uVar5 < 0) {
          lVar4 = (longlong)iVar12;
          iVar12 = iVar12 + 1;
          local_68[lVar4] = '-';
          uVar5 = ~uVar5 + 1;
        }
        uVar6 = (ulonglong)(int)uVar5;
LAB_000161f6:
        local_70 = param_4 + 1;
        pcVar10 = local_68;
        uVar5 = FUN_00015f58(uVar6,(longlong)local_68,iVar12,uVar16);
        uVar7 = (ulonglong)uVar5;
        local_50[0] = uVar13;
        local_78 = bVar11;
LAB_00016200:
        uVar14 = (ulonglong)local_74;
        local_78 = local_78 & 0xfe;
        param_2 = pcVar10;
        param_4 = local_70;
        param_3 = local_60;
        uVar13 = local_50[0];
        goto LAB_00016512;
      }
      bVar8 = (byte)param_2;
      if ((bVar11 & 1 & bVar8) == 0) {
LAB_00016507:
        local_68[uVar6] = cVar1;
        goto LAB_0001650d;
      }
      if (cVar1 == 'u') {
        uVar6 = *param_4;
        goto LAB_000161f6;
      }
      if (bVar8 == 0) goto LAB_00016507;
      if ((cVar1 + 0xa8U & 0xdf) == 0) {
        uVar14 = *param_4;
        local_70 = param_4 + 1;
        iVar9 = 0x24;
        uVar7 = 0xffffffff;
        do {
          if ((uVar14 & ~uVar7) != 0) break;
          iVar9 = iVar9 + -1;
          uVar7 = uVar7 >> 1;
        } while (uVar7 != 0);
        uVar5 = iVar9 >> 2;
        pcVar10 = (char *)(ulonglong)uVar5;
        if (((uVar16 & 0x90000) == 0x10000) && ((int)uVar5 < 0)) {
          pcVar15 = local_68 + iVar12;
          uVar7 = (ulonglong)-uVar5;
          uVar6 = (ulonglong)(iVar12 + -uVar5);
          do {
            *pcVar15 = (-((uVar16 & 0x20000) != 0) & 0x10U) + 0x20;
            pcVar15 = pcVar15 + 1;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        bVar3 = false;
        iVar12 = 0x1c;
        pcVar15 = local_68 + (int)uVar6;
        do {
          uVar7 = uVar14 >> ((byte)iVar12 & 0x3f);
          if ((uVar7 & 0xf) == 0) {
            if ((bVar3) || (iVar12 == 0)) goto LAB_00016311;
          }
          else {
            bVar3 = true;
LAB_00016311:
            uVar6 = (ulonglong)((int)uVar6 + 1);
            *pcVar15 = "0123456789ABCDEF"[(uint)uVar7 & 0xf];
            pcVar15 = pcVar15 + 1;
          }
          iVar12 = iVar12 + -4;
        } while (-1 < iVar12);
        uVar7 = uVar6;
        local_50[0] = uVar13;
        local_78 = bVar11;
        if ((uVar16 & 0x90000) == 0x90000) {
          if ((int)uVar5 < 0) {
            pcVar15 = local_68 + (int)uVar6;
            uVar7 = (ulonglong)((int)uVar6 + -uVar5);
            uVar6 = (ulonglong)-uVar5;
            do {
              *pcVar15 = (-((uVar16 & 0x20000) != 0) & 0x10U) + 0x20;
              pcVar15 = pcVar15 + 1;
              uVar6 = uVar6 - 1;
              pcVar10 = (char *)0x0;
            } while (uVar6 != 0);
          }
        }
        goto LAB_00016200;
      }
      if (bVar8 == 0) goto LAB_00016507;
      if (cVar1 == 's') {
        pcVar10 = (char *)*param_4;
        local_70 = param_4 + 1;
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (pcVar10[lVar4] != '\0');
        iVar9 = (int)lVar4;
        if (((uVar16 & 0xd0000) == 0x10000) && (iVar9 < 0)) {
          memset(local_68 + iVar12,(int)CONCAT71((int7)((ulonglong)param_2 >> 8),0x20),
                 (ulonglong)(uint)-iVar9);
          iVar12 = iVar12 + -iVar9;
        }
        iVar17 = iVar9;
        if ((((uVar16 >> 0x10 & 1) != 0) && ((uVar16 >> 0x12 & 1) != 0)) && (0 < iVar9)) {
          iVar17 = 0;
        }
        memcpy(local_68 + iVar12,pcVar10,(longlong)iVar17);
        uVar13 = iVar12 + iVar17;
        uVar7 = (ulonglong)uVar13;
        if (((uVar16 & 0xd0000) == 0x90000) && (iVar9 < 0)) {
          pcVar10 = (char *)CONCAT71((int7)((ulonglong)pcVar10 >> 8),0x20);
          memset(local_68 + (int)uVar13,(int)pcVar10,(ulonglong)(uint)-iVar9);
          uVar7 = (ulonglong)(uVar13 + -iVar9);
        }
        uVar18 = local_58;
        goto LAB_00016200;
      }
      if (bVar8 == 0) goto LAB_00016507;
      if (cVar1 == 'c') {
        pcVar10 = (char *)*param_4;
        param_4 = param_4 + 1;
        uVar7 = (ulonglong)(iVar12 + 1);
        local_78 = bVar11 & 0xfe;
        local_68[uVar6] = *pcVar10;
        goto LAB_00016512;
      }
      if (bVar8 == 0) goto LAB_00016507;
      if ((byte)(cVar1 - 0x30U) < 10) {
        local_74 = (int)uVar14 + 1;
        uVar7 = (ulonglong)local_74;
        *(char *)((longlong)local_50 + uVar14) = cVar1;
        if (4 < local_74) {
          __report_rangecheckfailure();
          pcVar2 = (code *)swi(3);
          uVar6 = (*pcVar2)();
          return uVar6;
        }
        *(undefined1 *)((longlong)local_50 + uVar7) = 0;
        uVar14 = uVar7;
        uVar5 = uVar16 | 0x10000;
        if (cVar1 == '0') {
          uVar5 = uVar16 | 0x30000;
        }
      }
      else {
        if ((bVar8 == 0) || (((1 < (byte)(cVar1 - 0x2dU) && (cVar1 != ' ')) && (cVar1 != 'l'))))
        goto LAB_00016507;
        if (cVar1 == '.') {
          uVar16 = uVar16 | 0x40000;
        }
        uVar5 = uVar16;
        if (cVar1 == '-') {
          uVar5 = uVar16 | 0x80000;
        }
      }
    }
    uVar16 = uVar5;
    local_50[0] = uVar13 + 1;
    uVar7 = (ulonglong)local_50[0];
    if (uVar18 <= uVar7) {
      return uVar6;
    }
  } while( true );
}



===== CRTL_sprintf @ 00016564 =====

void CRTL_sprintf(longlong param_1,longlong param_2,ulonglong param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  uVar1 = FUN_000160fc(param_1,(char *)param_1,param_2,&local_res18);
  *(undefined1 *)((int)uVar1 + param_1) = 0;
  return;
}



===== CsmiProcessIoctl @ 000165a0 =====

void CsmiProcessIoctl(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  iVar2 = *(int *)(param_2 + 0x10);
  if (iVar2 == 1) {
    if (*(uint *)(param_2 + 0x18) < 0xaa) goto LAB_000166a5;
    pcVar4 = "HpSAMD.sys";
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar4[param_2 + -0x1b6f5] = cVar1;
    } while (cVar1 != '\0');
    pcVar4 = "Smart Array SAS/SATA Controller Media Driver";
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar4[param_2 + -0x1b6b4] = cVar1;
    } while (cVar1 != '\0');
    *(undefined4 *)(param_2 + 0xbe) = 8;
    *(undefined4 *)(param_2 + 0xc2) = 4;
  }
  else if (iVar2 == 2) {
    if (*(uint *)(param_2 + 0x18) < 0xa8) goto LAB_000166a5;
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x9de8);
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x9420);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x9424);
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x92f4);
    *(undefined2 *)(param_2 + 0x2c) = *(undefined2 *)(param_1 + 0x93a0);
    *(undefined1 *)(param_2 + 0x2e) = 4;
    *(undefined1 *)(param_2 + 0x2f) = *(undefined1 *)(param_1 + 0x92fa);
    *(undefined1 *)(param_2 + 0x30) = *(undefined1 *)(param_1 + 0x92f0);
    *(undefined1 *)(param_2 + 0x31) = *(undefined1 *)(param_1 + 0x92f1);
    *(undefined1 *)(param_2 + 0x32) = *(undefined1 *)(param_1 + 0x92f2);
    memcpy((void *)(param_2 + 0x50),(void *)(param_1 + 0x92fb),0x20);
  }
  else {
    if (iVar2 != 3) {
      *(undefined4 *)(param_2 + 0x14) = 2;
      return;
    }
    if (*(uint *)(param_2 + 0x18) < 0x24) {
LAB_000166a5:
      *(undefined4 *)(param_2 + 0x14) = 3;
      return;
    }
    uVar3 = *(uint *)(param_1 + 0x9398);
    if ((uVar3 & 0x2401107) == 0) {
      *(undefined4 *)(param_2 + 0x1c) = 1;
    }
    else if ((uVar3 >> 0xc & 1) == 0) {
      if ((uVar3 & 2) == 0) {
        *(undefined8 *)(param_2 + 0x1c) = 3;
      }
      else {
        *(undefined8 *)(param_2 + 0x1c) = 2;
      }
    }
    else {
      *(undefined8 *)(param_2 + 0x1c) = 4;
    }
  }
  *(undefined4 *)(param_2 + 0x14) = 0;
  return;
}



===== CsmiCissProcessIoctl @ 0001670c =====

void CsmiCissProcessIoctl(uint *param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  byte bVar6;
  
  lVar3 = *(longlong *)(param_2 + 0x18);
  if ((param_1[0x24e6] & 2) != 0) {
    *(undefined1 *)(param_2 + 3) = 0x11;
    goto LAB_000167c6;
  }
  iVar1 = *(int *)(lVar3 + 0x10);
  if (iVar1 == 1) {
    if (0xb < *(uint *)(lVar3 + 0x18)) {
      if (((*(byte *)(lVar3 + 0x1c) < 7) && (*(byte *)(lVar3 + 0x1d) < 0x80)) &&
         (*(char *)(lVar3 + 0x1e) == '\0')) {
        uVar4 = (ulonglong)((uint)*(byte *)(lVar3 + 0x1d) + (uint)*(byte *)(lVar3 + 0x1c) * 0x80);
        uVar2 = param_1[uVar4 * 7 + 0x65];
        if ((((uVar2 >> 8 & 1) != 0) || ((char)uVar2 < '\0')) || ((uVar2 >> 0xb & 1) != 0)) {
          *(undefined8 *)(lVar3 + 0x1f) = *(undefined8 *)(param_1 + uVar4 * 7 + 0x66);
LAB_00016848:
          *(undefined4 *)(lVar3 + 0x14) = 0;
          goto LAB_000167bc;
        }
      }
    }
LAB_000167b4:
    *(undefined4 *)(lVar3 + 0x14) = 3;
  }
  else {
    if (iVar1 == 2) {
      FUN_00016858(param_1,param_2);
      return;
    }
    if (iVar1 == 3) {
      if (0xb < *(uint *)(lVar3 + 0x18)) {
        bVar5 = 0;
        do {
          bVar6 = 0;
          do {
            uVar4 = (ulonglong)((uint)bVar6 + (uint)bVar5 * 0x80);
            if ((((param_1[uVar4 * 7 + 0x65] >> 8 & 1) != 0) ||
                ((char)param_1[uVar4 * 7 + 0x65] < '\0')) &&
               (*(longlong *)(lVar3 + 0x1c) == *(longlong *)(param_1 + uVar4 * 7 + 0x66))) {
              *(byte *)(lVar3 + 0x24) = bVar5;
              *(byte *)(lVar3 + 0x25) = bVar6;
              *(undefined1 *)(lVar3 + 0x26) = 0;
              goto LAB_00016848;
            }
            bVar6 = bVar6 + 1;
          } while (bVar6 < 0x80);
          bVar5 = bVar5 + 1;
        } while (bVar5 < 7);
      }
      goto LAB_000167b4;
    }
    if (iVar1 == 4) {
      FUN_00016a54(param_1,param_2);
      return;
    }
    *(undefined4 *)(lVar3 + 0x14) = 2;
  }
LAB_000167bc:
  *(undefined1 *)(param_2 + 3) = 1;
LAB_000167c6:
                    /* WARNING: Could not recover jumptable at 0x000167cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1,param_2);
  return;
}



===== FUN_00016858 @ 00016858 =====

void FUN_00016858(uint *param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  uint uVar8;
  
  lVar3 = *(longlong *)(param_2 + 0x18);
  lVar4 = *(longlong *)(param_2 + 0x38);
  uVar8 = 0x80000;
  if (*(uint *)(lVar3 + 0x18) < 0x7c) {
    *(undefined4 *)(lVar3 + 0x14) = 3;
  }
  else {
    if ((param_1[0x24e6] & 0x2401107) != 0) {
      *(undefined4 *)(lVar3 + 0x14) = 1;
      *(char *)(param_2 + 3) = (char)param_1[0x24ee];
      goto LAB_00016a20;
    }
    if (((param_1[0x27d9] & 0x1000) == 0) ||
       (((*(char *)(lVar3 + 0x28) != -0x40 && (*(char *)(lVar3 + 0x28) != '&')) ||
        (*(char *)(lVar3 + 0x29) != -0x30)))) {
      if ((ushort)param_1[0x27da] < 0x200) {
        uVar8 = (uint)(ushort)param_1[0x27da] << 10;
      }
      if (*(uint *)(lVar3 + 0x18) < uVar8) {
        *(undefined2 *)(lVar4 + 5) = 0xffff;
        *(undefined1 *)(lVar4 + 7) = 0xff;
        *(undefined1 *)(lVar4 + 10) = *(undefined1 *)(lVar3 + 0x26);
        *(undefined1 *)(lVar4 + 0xb) = 0x28;
        iVar2 = *(int *)(lVar3 + 0x38);
        if (iVar2 == 1) {
          *(undefined4 *)(lVar4 + 0xc) = 0x40;
        }
        else if (iVar2 == 2) {
          *(undefined4 *)(lVar4 + 0xc) = 0x80;
        }
        else {
          uVar6 = 0;
          if (iVar2 == 3) {
            uVar6 = 3;
          }
          *(undefined4 *)(lVar4 + 0xc) = uVar6;
        }
        *(int *)(lVar4 + 0x10) = *(int *)(lVar3 + 0x18) + -0x78;
        uVar1 = *(ushort *)(lVar3 + 0x24);
        *(longlong *)(lVar4 + 0x38) = lVar4;
        *(uint *)(lVar4 + 0x14) = (uint)uVar1;
        *(longlong *)(lVar4 + 0x18) = lVar3 + 0x94;
        *(longlong *)(lVar4 + 0x20) = lVar3 + 0x5c;
        memcpy((void *)(lVar4 + 0x48),(void *)(lVar3 + 0x28),(ulonglong)*(byte *)(lVar3 + 0x26));
        *(longlong *)(lVar4 + 0x58) = param_2;
        uVar7 = MakeScatterGatherList((longlong)param_1,lVar4,param_2);
        if ((char)uVar7 != '\0') {
          BuildCissCommand((longlong)param_1,lVar4,3);
          if ((*(char *)(lVar3 + 0x28) == '\'') && (*(char *)(lVar3 + 0x2e) == -9)) {
            param_1[0x2796] = param_1[0x2796] + 1;
            param_1[99] = 0;
            param_1[0x2797] = 0;
          }
          cVar5 = SubmitCissCommand(param_1,lVar4,(undefined8 *)(lVar3 + 0x1c),
                                    (ushort)param_1[0x27d9] >> 5 & 1);
          if (cVar5 != '\0') {
            return;
          }
          *(undefined1 *)(param_2 + 3) = 5;
          goto LAB_00016a20;
        }
        *(undefined4 *)(lVar3 + 0x14) = 5;
      }
      else {
        *(undefined4 *)(lVar3 + 0x14) = 3;
      }
    }
    else {
      *(undefined4 *)(lVar3 + 0x14) = 4;
    }
  }
  *(undefined1 *)(param_2 + 3) = 1;
LAB_00016a20:
  StorPortNotification(0,param_1,param_2);
  return;
}



===== FUN_00016a54 @ 00016a54 =====

void FUN_00016a54(uint *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  lVar2 = *(longlong *)(param_2 + 0x38);
  if (lVar1 == 0) {
    *(undefined1 *)(param_2 + 3) = 6;
  }
  else if (*(uint *)(lVar1 + 0x18) < 0xc) {
    *(undefined4 *)(lVar1 + 0x14) = 3;
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else if ((param_1[0x24e6] & 0x2401107) == 0) {
    *(undefined4 *)(lVar2 + 0xc) = 0;
    *(undefined4 *)(lVar2 + 0x10) = 0;
    *(undefined8 *)(lVar2 + 0x18) = 0;
    *(undefined8 *)(lVar2 + 0x20) = 0;
    *(undefined2 *)(lVar2 + 5) = 0xffff;
    *(undefined1 *)(lVar2 + 7) = 0xff;
    *(undefined2 *)(lVar2 + 10) = 0x10;
    *(undefined4 *)(lVar2 + 0x14) = 10;
    *(longlong *)(lVar2 + 0x38) = lVar2;
    *(undefined8 *)(lVar2 + 0x48) = *(undefined8 *)(lVar1 + 0x24);
    *(undefined8 *)(lVar2 + 0x50) = *(undefined8 *)(lVar1 + 0x2c);
    *(longlong *)(lVar2 + 0x58) = param_2;
    uVar4 = MakeScatterGatherList((longlong)param_1,lVar2,param_2);
    if ((char)uVar4 == '\0') {
      *(undefined4 *)(lVar1 + 0x14) = 3;
      *(undefined1 *)(param_2 + 3) = 1;
    }
    else {
      BuildCissCommand((longlong)param_1,lVar2,0x83);
      cVar3 = SubmitCissCommand(param_1,lVar2,(undefined8 *)(lVar1 + 0x1c),
                                (ushort)param_1[0x27d9] >> 5 & 1);
      if (cVar3 != '\0') {
        return;
      }
      *(undefined1 *)(param_2 + 3) = 5;
    }
  }
  else {
    *(char *)(param_2 + 3) = (char)param_1[0x24ee];
  }
  StorPortNotification(0,param_1,param_2);
  return;
}



===== CompleteCsmiPassThrough @ 00016b74 =====

void CompleteCsmiPassThrough(longlong param_1,undefined1 *param_2,undefined1 *param_3)

{
  byte bVar1;
  ushort uVar2;
  longlong lVar3;
  undefined1 *_Src;
  uint uVar4;
  
  uVar4 = 0;
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x58) + 0x18);
  *(undefined1 *)(*(longlong *)(param_2 + 0x58) + 3) = 1;
  *(undefined1 *)(*(longlong *)(param_2 + 0x58) + 4) = 0;
  *(undefined4 *)(lVar3 + 0x14) = 0;
  if ((*(char *)(lVar3 + 0x28) == '\'') && (*(char *)(lVar3 + 0x2e) == -9)) {
    *(int *)(param_1 + 0x9e58) = *(int *)(param_1 + 0x9e58) + -1;
  }
  *(undefined2 *)(lVar3 + 0x4e) = *(undefined2 *)(param_3 + 2);
  _Src = param_2;
  if (*(short *)(param_3 + 2) == 0) goto LAB_00016c22;
  *(undefined8 *)(lVar3 + 0x54) = *(undefined8 *)(param_3 + 8);
  uVar2 = *(ushort *)(param_3 + 2);
  if (uVar2 != 1) {
    if (uVar2 < 2) goto LAB_00016c22;
    if (uVar2 < 4) {
      *(undefined4 *)(lVar3 + 0x50) = *(undefined4 *)(param_3 + 4);
      goto LAB_00016c22;
    }
    if (uVar2 != 4) goto LAB_00016c22;
  }
  *(undefined1 *)(lVar3 + 0x4c) = *param_3;
  bVar1 = param_3[1];
  if (bVar1 != 0) {
    uVar4 = 0x28;
    if (bVar1 < 0x28) {
      uVar4 = (uint)bVar1;
    }
    _Src = param_3 + 0x10;
    memcpy((void *)(lVar3 + 0x5c),_Src,(ulonglong)uVar4);
  }
  *(char *)(lVar3 + 0x4d) = (char)uVar4;
LAB_00016c22:
  if ((((*(ushort *)(param_3 + 2) & 0xfffd) == 0) && (*(char *)(lVar3 + 0x28) == -0x40)) &&
     (*(char *)(lVar3 + 0x29) == -0x30)) {
    CissCheckEvent(param_1,_Src,*(longlong *)(param_2 + 0x18));
  }
                    /* WARNING: Could not recover jumptable at 0x00016c68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1,*(undefined8 *)(param_2 + 0x58));
  return;
}



===== ProcessCsmiAllIoctls @ 00016c80 =====

void ProcessCsmiAllIoctls(longlong param_1,longlong param_2)

{
  undefined4 *_Dst;
  char cVar1;
  longlong lVar2;
  bool bVar3;
  char *pcVar4;
  uint uVar5;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  uVar5 = *(uint *)(lVar2 + 0x10);
  bVar3 = VerifySecurity(param_1,'\x04',0,uVar5);
  if (bVar3) {
    if (uVar5 == 1) {
      if (*(uint *)(lVar2 + 0x18) < 0x92) {
LAB_00016d82:
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        pcVar4 = "HpSAMD.sys";
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          pcVar4[lVar2 + -0x1b6f5] = cVar1;
        } while (cVar1 != '\0');
        pcVar4 = "Smart Array SAS/SATA Controller Media Driver";
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          pcVar4[lVar2 + -0x1b6b4] = cVar1;
        } while (cVar1 != '\0');
        *(undefined4 *)(lVar2 + 0xbe) = 8;
        *(undefined4 *)(lVar2 + 0xc2) = 4;
        *(undefined4 *)(lVar2 + 0xc6) = 0x520000;
LAB_00016dda:
        *(undefined4 *)(lVar2 + 0x14) = 0;
      }
    }
    else if (uVar5 == 2) {
      FUN_00016f2c(param_1,lVar2);
    }
    else {
      if (uVar5 == 3) {
        if (*(uint *)(lVar2 + 0x18) < 8) goto LAB_00016d82;
        _Dst = (undefined4 *)(lVar2 + 0x1c);
        memset(_Dst,0,0x24);
        uVar5 = *(uint *)(param_1 + 0x9398);
        if ((uVar5 & 0x2401107) == 0) {
          *_Dst = 1;
        }
        else {
          if ((uVar5 >> 0xc & 1) == 0) {
            if ((uVar5 & 2) == 0) {
              *_Dst = 3;
            }
            else {
              *_Dst = 2;
            }
          }
          else {
            *_Dst = 4;
          }
          *(undefined4 *)(lVar2 + 0x20) = 0;
        }
        goto LAB_00016dda;
      }
      if (uVar5 == 4) {
        if ((*(uint *)(param_1 + 0x9398) & 2) != 0) {
          *(undefined1 *)(param_2 + 3) = 0x11;
          goto LAB_00016de9;
        }
        *(undefined4 *)(lVar2 + 0x14) = 2;
      }
      else {
        *(undefined4 *)(lVar2 + 0x14) = 2;
      }
    }
  }
  else {
    *(undefined4 *)(lVar2 + 0x14) = 4;
  }
  *(undefined1 *)(param_2 + 3) = 1;
LAB_00016de9:
                    /* WARNING: Could not recover jumptable at 0x00016e01. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1,param_2);
  return;
}



===== ProcessCsmiSasIoctls @ 00016e10 =====

void ProcessCsmiSasIoctls(uint *param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  uVar3 = *(uint *)(lVar1 + 0x10);
  bVar2 = VerifySecurity((longlong)param_1,'\x04',0,uVar3);
  if (bVar2) {
    if ((param_1[0x24e6] & 2) != 0) {
      *(undefined1 *)(param_2 + 3) = 0x11;
      goto LAB_00016ec6;
    }
    if (uVar3 < 0x1a) {
      if (uVar3 != 0x19) {
        if (uVar3 == 0x14) {
          FUN_00017248(param_1,param_2);
          return;
        }
        if (uVar3 == 0x15) {
          FUN_00017388(param_1,param_2);
          return;
        }
        if (uVar3 == 0x16) {
          FUN_000174a4(param_1,param_2);
          return;
        }
        if (uVar3 == 0x17) {
          FUN_00017708(param_1,param_2);
          return;
        }
        if (uVar3 == 0x18) {
          FUN_00017880(param_1,param_2);
          return;
        }
      }
    }
    else {
      if (uVar3 == 0x1a) {
        FUN_000175e0(param_1,param_2);
        return;
      }
      if (uVar3 == 0x1b) {
        FUN_000170c8((longlong)param_1,param_2);
        return;
      }
      if (uVar3 == 0x1c) {
        FUN_00017188((longlong)param_1,param_2);
        return;
      }
    }
    *(undefined4 *)(lVar1 + 0x14) = 2;
  }
  else {
    *(undefined4 *)(lVar1 + 0x14) = 4;
  }
  *(undefined1 *)(param_2 + 3) = 1;
LAB_00016ec6:
  StorPortNotification(0,param_1,param_2);
  return;
}



===== FUN_00016f2c @ 00016f2c =====

void FUN_00016f2c(longlong param_1,longlong param_2)

{
  undefined2 uVar1;
  short sVar2;
  
  if (*(uint *)(param_2 + 0x18) < 0x8c) {
    *(undefined4 *)(param_2 + 0x14) = 3;
  }
  else {
    memset((void *)(param_2 + 0x1c),0,0xb4);
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x9de8);
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x9420);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x9424);
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x92f4);
    uVar1 = *(undefined2 *)(param_1 + 0x93a0);
    *(undefined2 *)(param_2 + 0x2e) = 0x305;
    *(undefined2 *)(param_2 + 0x2c) = uVar1;
    *(undefined1 *)(param_2 + 0x30) = *(undefined1 *)(param_1 + 0x92f0);
    *(undefined1 *)(param_2 + 0x31) = *(undefined1 *)(param_1 + 0x92f1);
    *(undefined1 *)(param_2 + 0x32) = *(undefined1 *)(param_1 + 0x92f2);
    memcpy((void *)(param_2 + 0x50),(void *)(param_1 + 0x92fb),0x20);
    *(undefined2 *)(param_2 + 0xa2) = *(undefined2 *)(param_1 + 0xa016);
    *(undefined2 *)(param_2 + 0xa4) = *(undefined2 *)(param_1 + 0xa018);
    *(undefined2 *)(param_2 + 0xa6) = *(undefined2 *)(param_1 + 0xa01a);
    *(undefined2 *)(param_2 + 0xa8) = *(undefined2 *)(param_1 + 0xa01c);
    *(undefined2 *)(param_2 + 0xaa) = *(undefined2 *)(param_1 + 0xa01e);
    *(undefined2 *)(param_2 + 0xac) = *(undefined2 *)(param_1 + 0xa020);
    *(undefined2 *)(param_2 + 0xae) = *(undefined2 *)(param_1 + 0xa022);
    *(undefined2 *)(param_2 + 0xb0) = *(undefined2 *)(param_1 + 0xa024);
    sVar2 = *(short *)(param_1 + 0x92f8);
    if ((sVar2 == 0x3220) || (sVar2 == 0x3230)) {
      *(uint *)(param_2 + 0xb4) = *(uint *)(param_2 + 0xb4) | 2;
    }
    else if (sVar2 == 0x3238) {
      *(uint *)(param_2 + 0xb4) = *(uint *)(param_2 + 0xb4) | 8;
    }
    else {
      *(undefined4 *)(param_2 + 0xb4) = 0;
    }
    *(undefined2 *)(param_2 + 0xb8) = *(undefined2 *)(param_1 + 0xa02c);
    *(undefined2 *)(param_2 + 0xba) = *(undefined2 *)(param_1 + 0xa02e);
    *(undefined2 *)(param_2 + 0xbc) = *(undefined2 *)(param_1 + 0xa030);
    uVar1 = *(undefined2 *)(param_1 + 0xa032);
    *(undefined8 *)(param_2 + 0xc0) = 0;
    *(undefined2 *)(param_2 + 0xbe) = uVar1;
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  return;
}



===== FUN_000170c8 @ 000170c8 =====

void FUN_000170c8(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  longlong lVar6;
  bool bVar7;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  if (*(uint *)(lVar2 + 0x18) < 0x14) {
    *(undefined4 *)(lVar2 + 0x14) = 3;
  }
  else {
    bVar3 = 0;
    do {
      uVar5 = 0;
      do {
        lVar6 = (ulonglong)(uVar5 + (uint)bVar3 * 0x80) * 0x1c;
        uVar1 = *(uint *)(lVar6 + 0x194 + param_1);
        if ((char)uVar1 < '\0') {
          if (*(longlong *)(lVar2 + 0x1c) == *(longlong *)(lVar6 + 0x1a0 + param_1)) {
            bVar7 = *(char *)(lVar2 + 0x2b) ==
                    (char)((ulonglong)*(undefined8 *)(lVar6 + 0x198 + param_1) >> 0x30);
LAB_0001713a:
            if (bVar7) {
              *(undefined4 *)(lVar2 + 0x14) = 0;
              *(byte *)(lVar2 + 0x2d) = bVar3;
              *(char *)(lVar2 + 0x2e) = (char)uVar5;
              *(undefined1 *)(lVar2 + 0x2f) = 0;
              goto LAB_00017152;
            }
          }
        }
        else if ((uVar1 >> 8 & 1) != 0) {
          bVar7 = *(longlong *)(lVar2 + 0x1c) == *(longlong *)(lVar6 + 0x198 + param_1);
          goto LAB_0001713a;
        }
        bVar4 = (char)uVar5 + 1;
        uVar5 = (uint)bVar4;
      } while (bVar4 < 0x80);
      bVar3 = bVar3 + 1;
    } while (bVar3 < 7);
    *(undefined4 *)(lVar2 + 0x14) = 0x7dd;
  }
LAB_00017152:
  *(undefined1 *)(param_2 + 3) = 1;
                    /* WARNING: Could not recover jumptable at 0x00017164. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1,param_2);
  return;
}



===== FUN_00017188 @ 00017188 =====

void FUN_00017188(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  if (0xb < *(uint *)(lVar2 + 0x18)) {
    if (((*(byte *)(lVar2 + 0x1d) < 7) && (*(byte *)(lVar2 + 0x1e) < 0x80)) &&
       (*(char *)(lVar2 + 0x1f) == '\0')) {
      lVar3 = (ulonglong)((uint)*(byte *)(lVar2 + 0x1e) + (uint)*(byte *)(lVar2 + 0x1d) * 0x80) *
              0x1c;
      uVar1 = *(uint *)(lVar3 + 0x194 + param_1);
      uVar4 = uVar1 >> 8 & 1;
      if (((uVar4 == 0) && ((uVar1 & 0x80) == 0)) && ((uVar1 >> 0xb & 1) == 0)) {
        *(undefined4 *)(lVar2 + 0x14) = 0x7de;
      }
      else {
        if (uVar4 == 0) {
          if ((uVar1 & 0x80) != 0) {
            *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(lVar3 + 0x1a0 + param_1);
            *(undefined1 *)(lVar2 + 0x2f) = *(undefined1 *)(lVar3 + 0x19e + param_1);
          }
        }
        else {
          *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(lVar3 + 0x198 + param_1);
        }
        *(undefined4 *)(lVar2 + 0x14) = 0;
      }
      goto LAB_00017230;
    }
  }
  *(undefined4 *)(lVar2 + 0x14) = 3;
LAB_00017230:
  *(undefined1 *)(param_2 + 3) = 1;
                    /* WARNING: Could not recover jumptable at 0x0001723a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1,param_2);
  return;
}



===== FUN_00017248 @ 00017248 =====

void FUN_00017248(uint *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  undefined8 local_res10;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  lVar2 = *(longlong *)(param_2 + 0x38);
  if (*(uint *)(lVar1 + 0x18) < 0x804) {
    *(undefined4 *)(lVar1 + 0x14) = 3;
    uVar3 = 1;
  }
  else {
    if ((param_1[0x24e6] & 0x2401107) == 0) {
      *(undefined2 *)(lVar2 + 5) = 0xffff;
      *(undefined1 *)(lVar2 + 7) = 0xff;
      *(undefined4 *)(lVar2 + 0xc) = 0x40;
      *(undefined1 *)(lVar2 + 9) = 0;
      *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)(lVar1 + 0xc);
      memset((void *)(lVar1 + 0x1c),0,0x804);
      *(undefined8 *)(lVar2 + 0x20) = 0;
      *(undefined4 *)(lVar2 + 0x10) = 0x820;
      *(longlong *)(lVar2 + 0x18) = lVar1;
      *(undefined2 *)(lVar2 + 10) = 0x10;
      *(longlong *)(lVar2 + 0x38) = lVar2;
      *(undefined8 *)(lVar2 + 0x48) = 0;
      *(undefined8 *)(lVar2 + 0x50) = 0;
      *(undefined4 *)(lVar2 + 0x48) = 0x27;
      *(undefined4 *)(lVar2 + 0x4c) = 0x8681400;
      *(undefined1 *)(lVar2 + 0x50) = 0x20;
      *(longlong *)(lVar2 + 0x58) = param_2;
      MakeScatterGatherList((longlong)param_1,lVar2,param_2);
      BuildCissCommand((longlong)param_1,lVar2,8);
      local_res10 = 0;
      cVar4 = SubmitCissCommand(param_1,lVar2,&local_res10,(ushort)param_1[0x27d9] >> 5 & 1);
      if (cVar4 != '\0') {
        return;
      }
      *(undefined1 *)(param_2 + 3) = 5;
      goto LAB_00017362;
    }
    *(undefined4 *)(lVar1 + 0x14) = 1;
    uVar3 = (undefined1)param_1[0x24ee];
  }
  *(undefined1 *)(param_2 + 3) = uVar3;
LAB_00017362:
  StorPortNotification(0,param_1,param_2);
  return;
}



===== FUN_00017388 @ 00017388 =====

void FUN_00017388(uint *param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  undefined8 local_res10;
  
  lVar2 = *(longlong *)(param_2 + 0x38);
  lVar3 = *(longlong *)(param_2 + 0x18);
  if (*(uint *)(lVar3 + 0x18) < 8) {
    *(undefined4 *)(lVar3 + 0x14) = 3;
    uVar4 = 1;
  }
  else {
    if ((param_1[0x24e6] & 0x2401107) == 0) {
      *(undefined2 *)(lVar2 + 5) = 0xffff;
      *(undefined1 *)(lVar2 + 7) = 0xff;
      *(undefined4 *)(lVar2 + 0xc) = 0x80;
      *(undefined1 *)(lVar2 + 9) = 0;
      uVar1 = *(undefined4 *)(lVar3 + 0xc);
      *(undefined8 *)(lVar2 + 0x20) = 0;
      *(undefined4 *)(lVar2 + 0x14) = uVar1;
      *(longlong *)(lVar2 + 0x18) = lVar3;
      *(undefined4 *)(lVar2 + 0x10) = 0x24;
      *(undefined2 *)(lVar2 + 10) = 0x10;
      *(longlong *)(lVar2 + 0x38) = lVar2;
      *(undefined8 *)(lVar2 + 0x48) = 0;
      *(undefined8 *)(lVar2 + 0x50) = 0;
      *(undefined4 *)(lVar2 + 0x48) = 0x27;
      *(undefined4 *)(lVar2 + 0x4c) = 0x681500;
      *(undefined1 *)(lVar2 + 0x50) = 0x24;
      *(longlong *)(lVar2 + 0x58) = param_2;
      MakeScatterGatherList((longlong)param_1,lVar2,param_2);
      BuildCissCommand((longlong)param_1,lVar2,9);
      local_res10 = 0;
      cVar5 = SubmitCissCommand(param_1,lVar2,&local_res10,(ushort)param_1[0x27d9] >> 5 & 1);
      if (cVar5 != '\0') {
        return;
      }
      *(undefined1 *)(param_2 + 3) = 5;
      goto LAB_00017483;
    }
    *(undefined4 *)(lVar3 + 0x14) = 1;
    uVar4 = (undefined1)param_1[0x24ee];
  }
  *(undefined1 *)(param_2 + 3) = uVar4;
LAB_00017483:
  StorPortNotification(0,param_1,param_2);
  return;
}



===== FUN_000174a4 @ 000174a4 =====

void FUN_000174a4(uint *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  undefined8 local_res10;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  lVar2 = *(longlong *)(param_2 + 0x38);
  if (*(uint *)(lVar1 + 0x18) < 0x14) {
    *(undefined4 *)(lVar1 + 0x14) = 3;
    uVar3 = 1;
  }
  else {
    if ((param_1[0x24e6] & 0x2401107) == 0) {
      *(undefined2 *)(lVar2 + 5) = 0xffff;
      *(undefined1 *)(lVar2 + 7) = 0xff;
      *(undefined4 *)(lVar2 + 0xc) = 0x40;
      *(undefined1 *)(lVar2 + 9) = 0;
      *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)(lVar1 + 0xc);
      memset((void *)(lVar1 + 0x1c),0,0x14);
      *(undefined8 *)(lVar2 + 0x20) = 0;
      *(undefined4 *)(lVar2 + 0x10) = 0x30;
      *(longlong *)(lVar2 + 0x18) = lVar1;
      *(undefined2 *)(lVar2 + 10) = 0x10;
      *(longlong *)(lVar2 + 0x38) = lVar2;
      *(undefined8 *)(lVar2 + 0x48) = 0;
      *(undefined8 *)(lVar2 + 0x50) = 0;
      *(undefined4 *)(lVar2 + 0x48) = 0x27;
      *(undefined4 *)(lVar2 + 0x4c) = 0x681600;
      *(undefined1 *)(lVar2 + 0x50) = 0x30;
      *(longlong *)(lVar2 + 0x58) = param_2;
      MakeScatterGatherList((longlong)param_1,lVar2,param_2);
      BuildCissCommand((longlong)param_1,lVar2,10);
      local_res10 = 0;
      cVar4 = SubmitCissCommand(param_1,lVar2,&local_res10,(ushort)param_1[0x27d9] >> 5 & 1);
      if (cVar4 != '\0') {
        return;
      }
      *(undefined1 *)(param_2 + 3) = 5;
      goto LAB_000175bd;
    }
    *(undefined4 *)(lVar1 + 0x14) = 1;
    uVar3 = (undefined1)param_1[0x24ee];
  }
  *(undefined1 *)(param_2 + 3) = uVar3;
LAB_000175bd:
  StorPortNotification(0,param_1,param_2);
  return;
}



===== FUN_000175e0 @ 000175e0 =====

void FUN_000175e0(uint *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  undefined8 local_res10;
  
  lVar1 = *(longlong *)(param_2 + 0x38);
  lVar2 = *(longlong *)(param_2 + 0x18);
  if (*(uint *)(lVar2 + 0x18) < 0x18) {
    *(undefined4 *)(lVar2 + 0x14) = 3;
    uVar3 = 1;
  }
  else {
    if ((param_1[0x24e6] & 0x2401107) == 0) {
      *(undefined2 *)(lVar1 + 5) = 0xffff;
      *(undefined1 *)(lVar1 + 7) = 0xff;
      *(undefined4 *)(lVar1 + 0xc) = 0x40;
      *(undefined1 *)(lVar1 + 9) = 0;
      *(undefined4 *)(lVar1 + 0x14) = *(undefined4 *)(lVar2 + 0xc);
      *(undefined8 *)(lVar2 + 0x1c) = 0;
      *(undefined8 *)(lVar2 + 0x24) = 0;
      *(undefined8 *)(lVar2 + 0x2c) = 0;
      *(undefined8 *)(lVar1 + 0x20) = 0;
      *(longlong *)(lVar1 + 0x18) = lVar2;
      *(undefined4 *)(lVar1 + 0x10) = 0x34;
      *(undefined2 *)(lVar1 + 10) = 0x10;
      *(longlong *)(lVar1 + 0x38) = lVar1;
      *(undefined8 *)(lVar1 + 0x48) = 0;
      *(undefined8 *)(lVar1 + 0x50) = 0;
      *(undefined4 *)(lVar1 + 0x48) = 0x27;
      *(undefined4 *)(lVar1 + 0x4c) = 0x681a00;
      *(undefined1 *)(lVar1 + 0x50) = 0x34;
      *(longlong *)(lVar1 + 0x58) = param_2;
      MakeScatterGatherList((longlong)param_1,lVar1,param_2);
      BuildCissCommand((longlong)param_1,lVar1,0xb);
      local_res10 = 0;
      cVar4 = SubmitCissCommand(param_1,lVar1,&local_res10,(ushort)param_1[0x27d9] >> 5 & 1);
      if (cVar4 != '\0') {
        return;
      }
      *(undefined1 *)(param_2 + 3) = 5;
      goto LAB_000176e6;
    }
    *(undefined4 *)(lVar2 + 0x14) = 1;
    uVar3 = (undefined1)param_1[0x24ee];
  }
  *(undefined1 *)(param_2 + 3) = uVar3;
LAB_000176e6:
  StorPortNotification(0,param_1,param_2);
  return;
}



===== FUN_00017708 @ 00017708 =====

void FUN_00017708(uint *param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  char cVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined8 local_res10;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  lVar3 = *(longlong *)(param_2 + 0x38);
  uVar7 = 0;
  bVar4 = VerifySecurity((longlong)param_1,'\x01',*(byte *)(lVar2 + 0x2d),0);
  if (bVar4) {
    if (0x80f < *(uint *)(lVar2 + 0x18)) {
      if ((param_1[0x24e6] & 0x2401107) != 0) {
        *(undefined4 *)(lVar2 + 0x14) = 1;
        *(char *)(param_2 + 3) = (char)param_1[0x24ee];
        goto LAB_0001785a;
      }
      if (*(char *)(lVar2 + 0x1c) == -1) {
        *(undefined4 *)(lVar2 + 0x14) = 0x7d2;
        goto LAB_00017853;
      }
      if (*(char *)(lVar2 + 0x1d) == -1) {
        *(undefined4 *)(lVar2 + 0x14) = 0x7d6;
        *(undefined1 *)(param_2 + 3) = 1;
        goto LAB_0001785a;
      }
      *(undefined2 *)(lVar3 + 5) = 0xffff;
      *(undefined1 *)(lVar3 + 7) = 0xff;
      *(undefined4 *)(lVar3 + 0xc) = 0xc0;
      *(char *)(lVar3 + 9) = (char)uVar7;
      uVar1 = *(undefined4 *)(lVar2 + 0xc);
      *(ulonglong *)(lVar3 + 0x20) = *(ulonglong *)(lVar3 + 0x20) & uVar7;
      *(undefined4 *)(lVar3 + 0x14) = uVar1;
      *(undefined4 *)(lVar3 + 0x10) = 0x82c;
      *(longlong *)(lVar3 + 0x18) = lVar2;
      *(undefined2 *)(lVar3 + 10) = 0x10;
      *(longlong *)(lVar3 + 0x38) = lVar3;
      *(undefined8 *)(lVar3 + 0x48) = 0;
      *(undefined8 *)(lVar3 + 0x50) = 0;
      *(undefined4 *)(lVar3 + 0x48) = 0x27;
      *(undefined4 *)(lVar3 + 0x4c) = 0x8681700;
      *(undefined1 *)(lVar3 + 0x50) = 0x2c;
      *(longlong *)(lVar3 + 0x58) = param_2;
      uVar6 = MakeScatterGatherList((longlong)param_1,lVar3,param_2);
      if ((char)uVar6 != '\0') {
        BuildCissCommand((longlong)param_1,lVar3,6);
        local_res10 = 0;
        cVar5 = SubmitCissCommand(param_1,lVar3,&local_res10,(ushort)param_1[0x27d9] >> 5 & 1);
        if (cVar5 != '\0') {
          return;
        }
        *(undefined1 *)(param_2 + 3) = 5;
        goto LAB_0001785a;
      }
    }
    *(undefined4 *)(lVar2 + 0x14) = 3;
  }
  else {
    *(undefined4 *)(lVar2 + 0x14) = 4;
  }
LAB_00017853:
  *(undefined1 *)(param_2 + 3) = 1;
LAB_0001785a:
  StorPortNotification(0,param_1,param_2);
  return;
}



===== FUN_00017880 @ 00017880 =====

void FUN_00017880(uint *param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  char cVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined8 local_res10;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  lVar3 = *(longlong *)(param_2 + 0x38);
  uVar8 = 0x80000;
  bVar4 = VerifySecurity((longlong)param_1,'\x02',*(byte *)(param_2 + 0x48),0);
  if (!bVar4) {
    *(undefined4 *)(lVar2 + 0x14) = 4;
    goto LAB_00017a99;
  }
  if (*(uint *)(lVar2 + 0x18) < 0x158) goto LAB_000178d4;
  if ((param_1[0x24e6] & 0x2401107) != 0) {
    *(undefined4 *)(lVar2 + 0x14) = 1;
    *(char *)(param_2 + 3) = (char)param_1[0x24ee];
    goto LAB_00017a9d;
  }
  if (((param_1[0x27d9] & 0x1000) == 0) ||
     (((*(char *)(lVar2 + 0x34) != -0x40 && (*(char *)(lVar2 + 0x34) != '&')) ||
      (*(char *)(lVar2 + 0x35) != -0x30)))) {
    if ((ushort)param_1[0x27da] < 0x200) {
      uVar8 = (uint)(ushort)param_1[0x27da] << 10;
    }
    if (uVar8 <= *(uint *)(lVar2 + 0x18)) goto LAB_000178d4;
    if (*(char *)(lVar2 + 0x1c) == -1) {
      *(undefined4 *)(lVar2 + 0x14) = 0x7d2;
    }
    else if (*(char *)(lVar2 + 0x1d) == -1) {
      *(undefined4 *)(lVar2 + 0x14) = 0x7d6;
    }
    else {
      *(undefined2 *)(lVar3 + 5) = 0xffff;
      *(undefined1 *)(lVar3 + 7) = 0xff;
      *(undefined1 *)(lVar3 + 10) = *(undefined1 *)(lVar2 + 0x30);
      iVar1 = *(int *)(lVar2 + 0x44);
      if (iVar1 == 1) {
        *(undefined4 *)(lVar3 + 0xc) = 0x40;
      }
      else if (iVar1 == 2) {
        *(undefined4 *)(lVar3 + 0xc) = 0x80;
      }
      else {
        uVar6 = 0;
        if (iVar1 == 3) {
          uVar6 = 3;
        }
        *(undefined4 *)(lVar3 + 0xc) = uVar6;
      }
      uVar8 = *(uint *)(lVar2 + 0x44);
      if (uVar8 == 0) {
LAB_000179b2:
        *(undefined1 *)(lVar3 + 9) = 4;
      }
      else if ((uVar8 & 0x10) == 0) {
        *(byte *)(lVar3 + 9) = -((uVar8 & 0x20) != 0) & 6;
      }
      else {
        *(undefined1 *)(lVar3 + 9) = 5;
        if ((*(uint *)(lVar2 + 0x44) & 0x20) != 0) goto LAB_000179b2;
      }
      *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)(lVar2 + 0xc);
      iVar1 = *(int *)(lVar2 + 0x18);
      *(undefined1 *)(lVar3 + 0xb) = 0x28;
      *(longlong *)(lVar3 + 0x38) = lVar3;
      *(int *)(lVar3 + 0x10) = iVar1 + -0x154;
      *(longlong *)(lVar3 + 0x18) = lVar2 + 0x170;
      *(longlong *)(lVar3 + 0x20) = lVar2 + 0x6c;
      memcpy((void *)(lVar3 + 0x48),(void *)(lVar2 + 0x34),(ulonglong)*(byte *)(lVar2 + 0x30));
      *(longlong *)(lVar3 + 0x58) = param_2;
      uVar7 = MakeScatterGatherList((longlong)param_1,lVar3,param_2);
      if ((char)uVar7 != '\0') {
        BuildCissCommand((longlong)param_1,lVar3,5);
        if ((*(char *)(lVar2 + 0x34) == '\'') && (*(char *)(lVar2 + 0x3a) == -9)) {
          param_1[0x2796] = param_1[0x2796] + 1;
          param_1[99] = 0;
          param_1[0x2797] = 0;
        }
        local_res10 = 0;
        cVar5 = SubmitCissCommand(param_1,lVar3,&local_res10,(ushort)param_1[0x27d9] >> 5 & 1);
        if (cVar5 != '\0') {
          return;
        }
        *(undefined1 *)(param_2 + 3) = 5;
        goto LAB_00017a9d;
      }
      *(undefined4 *)(lVar2 + 0x14) = 1;
    }
  }
  else {
LAB_000178d4:
    *(undefined4 *)(lVar2 + 0x14) = 3;
  }
LAB_00017a99:
  *(undefined1 *)(param_2 + 3) = 1;
LAB_00017a9d:
  StorPortNotification(0,param_1,param_2);
  return;
}



===== CompleteSAS_SspPassThrough @ 00017acc =====

void CompleteSAS_SspPassThrough(longlong param_1,longlong param_2,undefined1 *param_3)

{
  byte bVar1;
  short sVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x58) + 0x18);
  *(undefined1 *)(*(longlong *)(param_2 + 0x58) + 3) = 1;
  *(undefined1 *)(*(longlong *)(param_2 + 0x58) + 4) = 0;
  *(undefined4 *)(lVar3 + 0x14) = 0;
  uVar4 = 0;
  if ((*(char *)(lVar3 + 0x34) == '\'') && (*(char *)(lVar3 + 0x3a) == -9)) {
    *(int *)(param_1 + 0x9e58) = *(int *)(param_1 + 0x9e58) + -1;
  }
  *(undefined1 *)(lVar3 + 100) = 0;
  *(byte *)(lVar3 + 0x68) = -(param_3[1] != '\0') & 2;
  sVar2 = *(short *)(param_3 + 2);
  if (sVar2 == 0) goto LAB_00017b99;
  if (sVar2 != 1) {
    if (sVar2 == 2) {
      *(int *)(lVar3 + 0x16c) = *(int *)(lVar3 + 0x60) - *(int *)(param_3 + 4);
      goto LAB_00017b99;
    }
    if (sVar2 == 3) {
      *(undefined4 *)(lVar3 + 0x16c) = *(undefined4 *)(lVar3 + 0x60);
      goto LAB_00017b99;
    }
    if (sVar2 != 4) goto LAB_00017b99;
  }
  *(undefined1 *)(lVar3 + 0x69) = *param_3;
  bVar1 = param_3[1];
  if (bVar1 != 0) {
    uVar4 = 0x28;
    if (bVar1 < 0x28) {
      uVar4 = (uint)bVar1;
    }
    memset((void *)(lVar3 + 0x6c),0,0x100);
    memcpy((void *)(lVar3 + 0x6c),param_3 + 0x10,(ulonglong)uVar4);
  }
  *(char *)(lVar3 + 0x6b) = (char)uVar4;
LAB_00017b99:
  if (*(int *)(param_3 + 4) == 0) {
    *(undefined4 *)(lVar3 + 0x16c) = *(undefined4 *)(lVar3 + 0x60);
  }
                    /* WARNING: Could not recover jumptable at 0x00017bcf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1,*(undefined8 *)(param_2 + 0x58));
  return;
}



===== GetSspSecurityLev @ 00017bf8 =====

undefined4 GetSspSecurityLev(undefined8 param_1,byte param_2)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  int iVar4;
  bool bVar5;
  
  uVar1 = (uint)param_2;
  if (0xa8 < param_2) {
    if (uVar1 == 0xaa) {
      return 3;
    }
    if (uVar1 == 0xb7) {
      return 1;
    }
    return 3;
  }
  if (param_2 == 0xa8) {
    return 1;
  }
  uVar2 = (uint)param_2;
  uVar3 = (uint)param_2;
  if (uVar1 == 0x26 || param_2 < 0x26) {
    if (uVar1 == 0x26) {
      return 3;
    }
    if (param_2 < 0x13) {
      if (uVar2 == 0x12) {
        return 1;
      }
      if (uVar2 != 7 && 6 < param_2) {
        if (uVar2 == 8) {
          return 1;
        }
        if (uVar2 == 10) {
          return 3;
        }
        if (uVar2 == 0xb) {
          return 1;
        }
        if (uVar2 == 0xf) {
          return 1;
        }
        if (uVar2 == 0x10) {
          return 3;
        }
        if (uVar2 == 0x11) {
          return 0;
        }
        return 3;
      }
      if (uVar2 == 7) {
        return 3;
      }
      if (param_2 == 0) {
        return 1;
      }
      if (uVar2 == 1) {
        return 1;
      }
      if (uVar2 == 2) {
        return 1;
      }
      iVar4 = uVar2 - 3;
      if (iVar4 == 0) {
        return 1;
      }
    }
    else {
      if (0x19 < param_2) {
        if (uVar3 == 0x1a) {
          return 1;
        }
        if (uVar3 == 0x1b) {
          return 3;
        }
        if (uVar3 == 0x1c) {
          return 3;
        }
        if (uVar3 == 0x1d) {
          return 3;
        }
        if (uVar3 == 0x1e) {
          return 1;
        }
        iVar4 = uVar3 - 0x25;
        goto LAB_00017c45;
      }
      if (uVar3 == 0x19) {
        return 3;
      }
      if (uVar2 == 0x13) {
        return 1;
      }
      if (uVar2 == 0x14) {
        return 0;
      }
      if (uVar2 == 0x15) {
        return 3;
      }
      iVar4 = uVar2 - 0x16;
      if (iVar4 == 0) {
        return 3;
      }
    }
    iVar4 = iVar4 + -1;
    bVar5 = iVar4 == 0;
  }
  else {
    if (0xa0 < uVar2) {
      return 3;
    }
    if (uVar2 == 0xa0) {
      return 1;
    }
    if (uVar2 == 0x3c || param_2 < 0x3c) {
      if (uVar2 == 0x3c) {
        return 1;
      }
      if (uVar3 != 0x34 && 0x33 < param_2) {
        if (uVar3 == 0x35) {
          return 3;
        }
        if (uVar3 == 0x37) {
          return 1;
        }
        if (uVar3 == 0x38) {
          return 3;
        }
        if (uVar3 == 0x39) {
          return 1;
        }
        if (uVar3 == 0x3a) {
          return 1;
        }
        if (uVar3 == 0x3b) {
          return 2;
        }
        return 3;
      }
      if (uVar3 == 0x34) {
        return 1;
      }
      if (uVar2 == 0x27) {
        return 3;
      }
      if (uVar2 == 0x28) {
        return 1;
      }
      if (uVar2 == 0x2a) {
        return 3;
      }
      if (uVar2 == 0x2b) {
        return 1;
      }
      iVar4 = uVar2 - 0x2e;
      bVar5 = iVar4 == 0;
    }
    else {
      if (uVar2 != 0x55 && 0x54 < param_2) {
        if (uVar1 == 0x56) {
          return 3;
        }
        if (uVar1 == 0x57) {
          return 3;
        }
        if (uVar1 == 0x5a) {
          return 1;
        }
        return 3;
      }
      if (uVar2 == 0x55) {
        return 3;
      }
      if (uVar1 == 0x3e) {
        return 1;
      }
      if (uVar1 == 0x3f) {
        return 3;
      }
      if (uVar1 == 0x40) {
        return 3;
      }
      if (uVar1 == 0x41) {
        return 3;
      }
      iVar4 = uVar1 - 0x4c;
      bVar5 = iVar4 == 0;
    }
  }
  if (bVar5) {
    return 3;
  }
  iVar4 = iVar4 + -1;
LAB_00017c45:
  if (iVar4 == 0) {
    return 1;
  }
  return 3;
}



===== GetStpSecurityLev @ 00017dbc =====

undefined8 GetStpSecurityLev(undefined8 param_1,byte param_2)

{
  uint uVar2;
  uint uVar1;
  int iVar3;
  
  uVar1 = (uint)param_2;
  uVar2 = (uint)param_2;
  if (param_2 < 0xc5) {
    if (param_2 == 0xc4) {
      return 1;
    }
    if (0x39 < param_2) {
      if (uVar1 < 0x91) {
        if (uVar1 == 0x90) {
          return 1;
        }
        if (uVar1 == 0x3d) {
          return 3;
        }
        if (uVar1 == 0x3e) {
          return 3;
        }
        if (uVar1 == 0x3f) {
          return 3;
        }
        if (uVar1 == 0x40) {
          return 1;
        }
        if (uVar1 == 0x42) {
          return 1;
        }
        iVar3 = uVar1 - 0x70;
      }
      else {
        if (uVar1 == 0x92) {
          return 2;
        }
        if (uVar1 == 0xa0) {
          return 3;
        }
        if (uVar1 == 0xa1) {
          return 1;
        }
        if (uVar1 == 0xa2) {
          return 3;
        }
        iVar3 = uVar1 - 0xb0;
      }
      goto joined_r0x00017f47;
    }
    if (uVar1 == 0x39) {
      return 3;
    }
    if (0x29 < param_2) {
      if (uVar2 == 0x2f) {
        return 1;
      }
      return 3;
    }
    if (uVar1 == 0x29) {
      return 1;
    }
    if (param_2 == 0) {
      return 1;
    }
    if (uVar2 == 8) {
      return 3;
    }
    if (uVar2 == 0x20) {
      return 1;
    }
    if (uVar2 == 0x24) {
      return 1;
    }
    iVar3 = uVar2 - 0x25;
    if (iVar3 == 0) {
      return 1;
    }
  }
  else {
    if (0xe6 < uVar2) {
      if (uVar2 < 0xf3) {
        if (uVar2 == 0xf2) {
          return 3;
        }
        if (uVar1 == 0xe7) {
          return 1;
        }
        if (uVar1 == 0xe8) {
          return 2;
        }
        if (uVar1 == 0xea) {
          return 1;
        }
        if (uVar1 == 0xec) {
          return 1;
        }
        return 3;
      }
      if (uVar1 == 0xf3) {
        return 3;
      }
      if (uVar1 == 0xf4) {
        return 3;
      }
      if (uVar1 == 0xf5) {
        return 3;
      }
      if (uVar1 == 0xf6) {
        return 3;
      }
      iVar3 = uVar1 - 0xf8;
      goto joined_r0x00017f47;
    }
    if (uVar2 == 0xe6) {
      return 3;
    }
    if (uVar1 < 0xcf) {
      if (uVar1 == 0xce) {
        return 3;
      }
      if (uVar1 == 0xc5) {
        return 3;
      }
      if (uVar1 == 0xc6) {
        return 3;
      }
      if (uVar1 == 199) {
        return 1;
      }
      if (uVar1 == 200) {
        return 1;
      }
      return 3;
    }
    if (uVar1 == 0xe0) {
      return 3;
    }
    if (uVar1 == 0xe1) {
      return 3;
    }
    if (uVar1 == 0xe2) {
      return 3;
    }
    iVar3 = uVar1 - 0xe3;
    if (iVar3 == 0) {
      return 3;
    }
  }
  if (iVar3 == 1) {
    return 1;
  }
  iVar3 = iVar3 + -2;
joined_r0x00017f47:
  if (iVar3 == 0) {
    return 1;
  }
  return 3;
}



===== VerifySecurity @ 00017f5c =====

bool VerifySecurity(longlong param_1,char param_2,byte param_3,uint param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_2 == '\x01') {
    if (((((param_3 == 0) || (param_3 == 1)) || (param_3 == 0x10)) ||
        ((param_3 == 0x11 || (param_3 == 0x12)))) || (param_3 == 0x13)) {
      uVar1 = 1;
      goto LAB_00018022;
    }
    goto LAB_00018019;
  }
  if (param_2 == '\x02') {
    uVar1 = GetSspSecurityLev(param_1,param_3);
    goto LAB_00018022;
  }
  if (param_2 == '\x03') {
    uVar2 = GetStpSecurityLev(param_1,param_3);
    uVar1 = (uint)uVar2;
    goto LAB_00018022;
  }
  if (param_2 == '\x04') {
    if (param_4 < 0x17) {
      if (param_4 == 0x16) goto LAB_00017fd7;
      if (param_4 != 0) {
        if (param_4 < 5) goto LAB_00017fd7;
        if (9 < param_4) {
          if ((param_4 < 0xc) || (param_4 == 0x14)) goto LAB_00017fd7;
          if (param_4 == 0x15) goto LAB_00018019;
        }
      }
    }
    else if (0x19 < param_4) {
      if (0x1c < param_4) {
        if (param_4 != 0x1d) {
          if (param_4 == 0x1e) goto LAB_00017fd7;
          if (param_4 != 0x3c) goto LAB_00017fb3;
        }
LAB_00018019:
        uVar1 = 3;
        goto LAB_00018022;
      }
LAB_00017fd7:
      uVar1 = 2;
      goto LAB_00018022;
    }
  }
LAB_00017fb3:
  uVar1 = 0;
LAB_00018022:
  return *(uint *)(param_1 + 0x9e60) <= uVar1;
}



===== CissSendReportLogicalLuns @ 000180a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CissSendReportLogicalLuns(uint *param_1,longlong param_2)

{
  undefined4 uVar1;
  uint uVar2;
  void *_Dst;
  ulonglong *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  char cVar6;
  ulonglong in_RAX;
  undefined7 extraout_var;
  ulonglong uVar7;
  undefined4 local_res8 [2];
  undefined8 local_res20;
  
  _Dst = *(void **)(param_1 + 0x24f2);
  if (*(char *)((longlong)_Dst + 0x19f2) == '\0') {
    *(longlong *)((longlong)_Dst + 0x1a18) = (longlong)_Dst + 0x19e0;
    *(undefined1 *)((longlong)_Dst + 0x19f2) = 1;
    *(undefined2 *)((longlong)_Dst + 0x19fd) = 0xffff;
    *(longlong *)((longlong)_Dst + 0x1a30) = (longlong)_Dst + 0x1808;
    *(undefined1 *)((longlong)_Dst + 0x19ff) = 0xff;
    *(undefined2 *)((longlong)_Dst + 0x1a02) = 0x120c;
    *(undefined4 *)((longlong)_Dst + 0x1a04) = 0x40;
    *(undefined4 *)((longlong)_Dst + 0x1a0c) = 10;
    *(undefined4 *)((longlong)_Dst + 0x1a08) = 0x1808;
    *(void **)((longlong)_Dst + 0x1a10) = _Dst;
    memset(_Dst,0,0x1808);
    *(undefined8 *)((longlong)_Dst + 0x1890) = 0;
    *(undefined8 *)((longlong)_Dst + 0x1a40) = 0;
    *(undefined8 *)((longlong)_Dst + 0x1a48) = 0;
    *(undefined2 *)((longlong)_Dst + 0x1a40) = 0x1c2;
    uVar1 = *(undefined4 *)((longlong)_Dst + 0x1a08);
    *(char *)((longlong)_Dst + 0x1a46) = (char)((uint)uVar1 >> 0x18);
    *(char *)((longlong)_Dst + 0x1a47) = (char)((uint)uVar1 >> 0x10);
    *(char *)((longlong)_Dst + 0x1a49) = (char)uVar1;
    *(char *)((longlong)_Dst + 0x1a48) = (char)((uint)uVar1 >> 8);
    *(longlong *)((longlong)_Dst + 0x1a50) = param_2;
    local_res20 = 0;
    if (*(longlong *)((longlong)_Dst + 0x1890) == 0) {
      MakeScatterGatherList((longlong)param_1,(longlong)_Dst + 0x19f8,0);
    }
    else {
      *(ulonglong *)((longlong)_Dst + 0x18b0) = (longlong)_Dst + 0x192cU & 0xffffffffffffffe0;
      StorPortExtendedFunction
                (9,param_1,_DAT_00000010,_DAT_00000008,0x7000,&LAB_00018040,(longlong)_Dst + 0x1868,
                 0,_DAT_00000018,0x1000);
    }
    BuildCissCommand((longlong)param_1,(longlong)_Dst + 0x19f8,1);
    if ((*(longlong *)((longlong)_Dst + 0x1890) != 0) &&
       (1 < *(ushort *)(*(longlong *)((longlong)_Dst + 0x18b0) + 2))) {
      *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] | 0x2000;
    }
    cVar6 = SubmitCissCommand(param_1,(longlong)_Dst + 0x19f8,&local_res20,
                              (ushort)param_1[0x27d9] >> 5 & 1);
    in_RAX = CONCAT71(extraout_var,cVar6);
    if (cVar6 != '\0') {
      return CONCAT71(extraout_var,1);
    }
    puVar3 = *(ulonglong **)((longlong)_Dst + 0x1890);
    if (((puVar3 != (ulonglong *)0x0) && (*(longlong *)(param_1 + 0x2828) != 0)) &&
       (in_RAX = CONCAT71(extraout_var,(byte)param_1[0x27d9]), ((byte)param_1[0x27d9] & 0x10) == 0))
    {
      uVar2 = param_1[0x2515];
      lVar4 = *(longlong *)(param_1 + 0x2512);
      do {
        uVar5 = *(ulonglong *)(param_1 + 0x250e);
        *puVar3 = uVar5 & 0xffff;
        LOCK();
        uVar7 = *(ulonglong *)(param_1 + 0x250e);
        if (uVar5 == uVar7) {
          *(ulonglong *)(param_1 + 0x250e) =
               (uVar5 & 0xffffffffffff0000) + 0x10000 |
               (ulonglong)((longlong)puVar3 - lVar4) / (ulonglong)uVar2 & 0xffffffff;
          uVar7 = uVar5;
        }
        else {
        }
        UNLOCK();
      } while (uVar5 != uVar7);
      in_RAX = CONCAT71((int7)(uVar7 >> 8),(byte)param_1[0x27d9]);
      if (((byte)param_1[0x27d9] & 0x10) == 0) {
        LOCK();
        param_1[0x2826] = param_1[0x2826] + 1;
        UNLOCK();
        local_res8[0] = 0;
        in_RAX = StorPortNotification(0x1002,param_1,param_1 + 0x24d4,0,0,local_res8);
      }
    }
    if (param_2 != 0) {
      *(undefined1 *)(param_2 + 3) = 5;
      in_RAX = StorPortNotification(0,param_1,param_2);
    }
    *(undefined1 *)((longlong)_Dst + 0x19f2) = 0;
  }
  else if (param_2 != 0) {
    *(undefined1 *)(param_2 + 3) = 0xe;
    StorPortNotification(0,param_1,param_2);
    in_RAX = StorPortNotification(3,param_1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== CissSendReportPhysicalLuns @ 000183cc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CissSendReportPhysicalLuns(uint *param_1,longlong param_2)

{
  undefined4 uVar1;
  uint uVar2;
  void *_Dst;
  ulonglong *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  char cVar6;
  ulonglong in_RAX;
  undefined7 extraout_var;
  ulonglong uVar7;
  undefined4 local_res8 [2];
  undefined8 local_res20;
  
  _Dst = *(void **)(param_1 + 0x24f2);
  if (*(char *)((longlong)_Dst + 0x19f2) == '\0') {
    *(longlong *)((longlong)_Dst + 0x1a18) = (longlong)_Dst + 0x19e0;
    *(undefined1 *)((longlong)_Dst + 0x19f2) = 1;
    *(longlong *)((longlong)_Dst + 0x1a30) = (longlong)_Dst + 0x1808;
    *(undefined2 *)((longlong)_Dst + 0x19fd) = 0xffff;
    *(undefined1 *)((longlong)_Dst + 0x19ff) = 0xff;
    *(undefined2 *)((longlong)_Dst + 0x1a02) = 0x120c;
    *(undefined4 *)((longlong)_Dst + 0x1a04) = 0x40;
    *(undefined4 *)((longlong)_Dst + 0x1a0c) = 10;
    *(undefined4 *)((longlong)_Dst + 0x1a08) = 0x1808;
    *(void **)((longlong)_Dst + 0x1a10) = _Dst;
    memset(_Dst,0,0x1808);
    *(undefined8 *)((longlong)_Dst + 0x1890) = 0;
    *(undefined8 *)((longlong)_Dst + 0x1a40) = 0;
    *(undefined8 *)((longlong)_Dst + 0x1a48) = 0;
    *(undefined2 *)((longlong)_Dst + 0x1a40) = 0x2c3;
    memset(*(void **)((longlong)_Dst + 0x1a10),0,0x1808);
    uVar1 = *(undefined4 *)((longlong)_Dst + 0x1a08);
    *(char *)((longlong)_Dst + 0x1a46) = (char)((uint)uVar1 >> 0x18);
    *(char *)((longlong)_Dst + 0x1a47) = (char)((uint)uVar1 >> 0x10);
    *(char *)((longlong)_Dst + 0x1a49) = (char)uVar1;
    *(char *)((longlong)_Dst + 0x1a48) = (char)((uint)uVar1 >> 8);
    *(longlong *)((longlong)_Dst + 0x1a50) = param_2;
    local_res20 = 0;
    if (*(longlong *)((longlong)_Dst + 0x1890) == 0) {
      MakeScatterGatherList((longlong)param_1,(longlong)_Dst + 0x19f8,0);
    }
    else {
      *(ulonglong *)((longlong)_Dst + 0x18b0) = (longlong)_Dst + 0x192cU & 0xffffffffffffffe0;
      StorPortExtendedFunction
                (9,param_1,_DAT_00000010,_DAT_00000008,0x7000,&LAB_00018040,(longlong)_Dst + 0x1868,
                 0,_DAT_00000018,0x1000);
    }
    BuildCissCommand((longlong)param_1,(longlong)_Dst + 0x19f8,2);
    if ((*(longlong *)((longlong)_Dst + 0x1890) != 0) &&
       (1 < *(ushort *)(*(longlong *)((longlong)_Dst + 0x18b0) + 2))) {
      *(ushort *)(param_1 + 0x27d9) = (ushort)param_1[0x27d9] | 0x2000;
    }
    cVar6 = SubmitCissCommand(param_1,(longlong)_Dst + 0x19f8,&local_res20,
                              (ushort)param_1[0x27d9] >> 5 & 1);
    in_RAX = CONCAT71(extraout_var,cVar6);
    if (cVar6 != '\0') {
      return CONCAT71(extraout_var,1);
    }
    puVar3 = *(ulonglong **)((longlong)_Dst + 0x1890);
    if (((puVar3 != (ulonglong *)0x0) && (*(longlong *)(param_1 + 0x2828) != 0)) &&
       (in_RAX = CONCAT71(extraout_var,(byte)param_1[0x27d9]), ((byte)param_1[0x27d9] & 0x10) == 0))
    {
      uVar2 = param_1[0x2515];
      lVar4 = *(longlong *)(param_1 + 0x2512);
      do {
        uVar5 = *(ulonglong *)(param_1 + 0x250e);
        *puVar3 = uVar5 & 0xffff;
        LOCK();
        uVar7 = *(ulonglong *)(param_1 + 0x250e);
        if (uVar5 == uVar7) {
          *(ulonglong *)(param_1 + 0x250e) =
               (uVar5 & 0xffffffffffff0000) + 0x10000 |
               (ulonglong)((longlong)puVar3 - lVar4) / (ulonglong)uVar2 & 0xffffffff;
          uVar7 = uVar5;
        }
        else {
        }
        UNLOCK();
      } while (uVar5 != uVar7);
      in_RAX = CONCAT71((int7)(uVar7 >> 8),(byte)param_1[0x27d9]);
      if (((byte)param_1[0x27d9] & 0x10) == 0) {
        LOCK();
        param_1[0x2826] = param_1[0x2826] + 1;
        UNLOCK();
        local_res8[0] = 0;
        in_RAX = StorPortNotification(0x1002,param_1,param_1 + 0x24d4,0,0,local_res8);
      }
    }
    if (param_2 != 0) {
      *(undefined1 *)(param_2 + 3) = 5;
      in_RAX = StorPortNotification(0,param_1,param_2);
    }
    *(undefined1 *)((longlong)_Dst + 0x19f2) = 0;
  }
  else if (param_2 != 0) {
    *(undefined1 *)(param_2 + 3) = 0xe;
    StorPortNotification(0,param_1,param_2);
    in_RAX = StorPortNotification(3,param_1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== CissFlushCache @ 0001870c =====

ulonglong CissFlushCache(uint *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  ulonglong in_RAX;
  undefined7 extraout_var;
  undefined8 local_res8;
  
  lVar2 = *(longlong *)(param_1 + 0x24fa);
  if (*(char *)(lVar2 + 0x438) == '\0') {
    *(undefined8 *)(lVar2 + 0x1f8) = 0;
    *(undefined1 *)(lVar2 + 0x438) = 1;
    *(undefined2 *)(lVar2 + 0x1dd) = 0xffff;
    *(undefined1 *)(lVar2 + 0x1df) = 0xff;
    *(undefined2 *)(lVar2 + 0x1e2) = 0x10;
    *(undefined4 *)(lVar2 + 0x1e4) = 0x80;
    *(undefined4 *)(lVar2 + 0x1ec) = 0x78;
    *(longlong *)(lVar2 + 0x210) = lVar2;
    *(longlong *)(lVar2 + 0x1f0) = lVar2 + 0x238;
    *(undefined4 *)(lVar2 + 0x1e8) = 0x200;
    *(undefined8 *)(lVar2 + 0x220) = 0;
    *(undefined8 *)(lVar2 + 0x228) = 0;
    *(undefined1 *)(lVar2 + 0x220) = 0x27;
    *(undefined1 *)(lVar2 + 0x226) = 0xc2;
    *(undefined2 *)(lVar2 + 0x227) = 0x20;
    memset(*(void **)(lVar2 + 0x1f0),0,0x200);
    lVar1 = lVar2 + 0x1d8;
    *(code **)(lVar2 + 0x440) = CissFlushCacheCompletionRoutine;
    *(longlong *)(lVar2 + 0x230) = param_2;
    local_res8 = 0;
    MakeScatterGatherList((longlong)param_1,lVar1,0);
    BuildCissCommand((longlong)param_1,lVar1,4);
    cVar3 = SubmitCissCommand(param_1,lVar1,&local_res8,(ushort)param_1[0x27d9] >> 5 & 1);
    if ((cVar3 != '\0') || (param_2 == 0)) {
      return CONCAT71(extraout_var,1);
    }
    *(undefined1 *)(param_2 + 3) = 5;
    in_RAX = StorPortNotification(0,param_1,param_2);
    *(undefined1 *)(lVar2 + 0x438) = 0;
  }
  else if (param_2 != 0) {
    *(undefined1 *)(param_2 + 3) = 0xe;
    StorPortNotification(0,param_1,param_2);
    in_RAX = StorPortNotification(3,param_1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== CissScanMessage @ 000188a0 =====

undefined8 CissScanMessage(uint *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined8 in_RAX;
  undefined7 extraout_var;
  undefined8 local_res8;
  
  lVar2 = *(longlong *)(param_1 + 0x24f8);
  if (*(char *)(lVar2 + 0x230) == '\0') {
    *(undefined4 *)(lVar2 + 0x1e4) = 0;
    *(undefined4 *)(lVar2 + 0x1e8) = 0;
    *(undefined8 *)(lVar2 + 0x1f0) = 0;
    *(undefined8 *)(lVar2 + 0x1f8) = 0;
    *(undefined1 *)(lVar2 + 0x230) = 1;
    *(undefined2 *)(lVar2 + 0x1dd) = 0xffff;
    *(undefined1 *)(lVar2 + 0x1df) = 0xff;
    *(undefined2 *)(lVar2 + 0x1e2) = 0x10;
    *(undefined4 *)(lVar2 + 0x1ec) = 10;
    *(longlong *)(lVar2 + 0x210) = lVar2;
    *(undefined8 *)(lVar2 + 0x220) = 0;
    *(undefined8 *)(lVar2 + 0x228) = 0;
    *(undefined2 *)(lVar2 + 0x220) = 2;
    *(longlong *)(lVar2 + 0x238) = param_2;
    lVar1 = lVar2 + 0x1d8;
    local_res8 = 0;
    MakeScatterGatherList((longlong)param_1,lVar1,0);
    BuildCissCommand((longlong)param_1,lVar1,0x82);
    cVar3 = SubmitCissCommand(param_1,lVar1,&local_res8,(ushort)param_1[0x27d9] >> 5 & 1);
    in_RAX = CONCAT71(extraout_var,cVar3);
    if ((cVar3 == '\0') && (param_2 != 0)) {
      *(undefined1 *)(param_2 + 3) = 5;
      in_RAX = StorPortNotification(0,param_1,param_2);
      *(undefined1 *)(lVar2 + 0x230) = 0;
    }
  }
  else if (param_2 != 0) {
    *(undefined1 *)(param_2 + 3) = 0xe;
    StorPortNotification(0,param_1,param_2);
    in_RAX = StorPortNotification(3,param_1);
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== CissHardwareBusReset @ 000189f0 =====

ulonglong CissHardwareBusReset(uint *param_1,uint param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  uVar2 = (ulonglong)param_1[0x24e6];
  lVar1 = *(longlong *)(param_1 + 0x24f4);
  if ((param_1[0x24e6] & 2) == 0) {
    uVar2 = (ulonglong)*param_1;
    if ((*param_1 >> 0x1c & 1) == 0) {
      CoalescingFlushAllLUNs(param_1);
      if ((param_1[0x278e] & 0x20) != 0) {
        uVar3 = CissResetBus((longlong)param_1,0,param_2);
        return uVar3;
      }
      *(undefined1 *)(lVar1 + 0x231) = 1;
      *(longlong *)(lVar1 + 0x210) = lVar1;
      *(undefined2 *)(lVar1 + 0x1dd) = 0xffff;
      *(undefined1 *)(lVar1 + 0x1df) = 0xff;
      uVar2 = CissSendReset(param_1,(undefined4 *)(lVar1 + 0x1d8),0xffffffff,0x80);
      if ((char)uVar2 == '\0') {
        *(undefined1 *)(lVar1 + 0x231) = 0;
        goto LAB_00018a15;
      }
      do {
        uVar2 = StorPortStallExecution(0x32);
      } while (*(char *)(lVar1 + 0x231) != '\0');
      *(undefined1 *)(lVar1 + 0x231) = 0;
    }
    uVar2 = CONCAT71((int7)(uVar2 >> 8),1);
  }
  else {
LAB_00018a15:
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  return uVar2;
}



===== CissSendReset @ 00018ab4 =====

void CissSendReset(uint *param_1,undefined4 *param_2,uint param_3,int param_4)

{
  ulonglong uVar1;
  char cVar2;
  int iVar3;
  undefined8 local_res8;
  undefined8 local_res10;
  
  local_res8 = 0;
  *(undefined2 *)((longlong)param_2 + 10) = 0x10;
  param_2[5] = 0x14;
  *param_2 = 0;
  *(undefined1 *)(param_2 + 1) = 0;
  *(undefined8 *)(param_2 + 3) = 0;
  *(undefined8 *)(param_2 + 6) = 0;
  *(undefined8 *)(param_2 + 8) = 0;
  *(undefined8 *)(param_2 + 0x12) = 0;
  uVar1 = (ulonglong)param_3;
  *(undefined8 *)(param_2 + 0x14) = 0;
  if (param_3 == 0xffffffff) {
    *(undefined2 *)(param_2 + 0x12) = 0x101;
  }
  else if ((param_1[uVar1 * 7 + 0x65] & 0x100) == 0) {
    *(undefined2 *)(param_2 + 0x12) = 0x301;
    local_res10 = *(undefined8 *)(param_1 + uVar1 * 7 + 0x66);
    iVar3 = (((byte)((ulonglong)local_res10 >> 0x38) & 0x3f) - 1) * 0x100 +
            (uint)(byte)((ulonglong)local_res10 >> 0x30);
    *(char *)(param_2 + 0x13) = (char)iVar3;
    *(char *)((longlong)param_2 + 0x4d) = (char)((uint)iVar3 >> 8);
    *(char *)((longlong)param_2 + 0x4f) = (char)((uint)iVar3 >> 0x18);
    *(char *)((longlong)param_2 + 0x4e) = (char)((uint)iVar3 >> 0x10);
    local_res8 = 0;
  }
  else {
    *(undefined2 *)(param_2 + 0x12) = 0x401;
    *(undefined1 *)(param_2 + 0x13) = 0;
    local_res8 = *(undefined8 *)(param_1 + uVar1 * 7 + 0x66);
  }
  MakeScatterGatherList((longlong)param_1,(longlong)param_2,0);
  BuildCissCommand((longlong)param_1,(longlong)param_2,param_4);
  if (param_3 != 0xffffffff) {
    param_1[uVar1 * 7 + 0x65] = param_1[uVar1 * 7 + 0x65] | 0x20000;
  }
  cVar2 = SubmitCissCommand(param_1,(longlong)param_2,&local_res8,(ushort)param_1[0x27d9] >> 5 & 1);
  if ((cVar2 == '\0') && (param_3 != 0xffffffff)) {
    param_1[uVar1 * 7 + 0x65] = param_1[uVar1 * 7 + 0x65] & 0xfffdffff;
  }
  return;
}



===== CissResetBus @ 00018bfc =====

ulonglong CissResetBus(longlong param_1,longlong param_2,uint param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  undefined4 local_res8 [2];
  
  lVar2 = *(longlong *)(param_1 + 0x93c0);
  uVar4 = *(ulonglong *)(param_1 + 0x93e8);
  lVar3 = *(longlong *)(param_1 + 0x93d0);
  iVar7 = 0;
  if ((*(char *)(uVar4 + 0x438) == '\0') &&
     (uVar4 = *(ulonglong *)(param_1 + 0x93c8), *(char *)(uVar4 + 0x19f2) == '\0')) {
    if (*(char *)(lVar3 + 0x231) == '\0') {
      uVar4 = CONCAT71((int7)(uVar4 >> 8),*(byte *)(param_1 + 0x9e38));
      if ((*(byte *)(param_1 + 0x9e38) & 0x20) != 0) {
        *(undefined1 *)(lVar3 + 0x231) = 1;
        uVar4 = (ulonglong)(byte)~-(param_3 != 0) & 4;
        uVar9 = (param_3 & 0xff) * 0x80 + (int)uVar4;
        uVar6 = uVar9 + 0x80;
        if (param_3 == 0) {
          uVar6 = uVar9 + 0x7c;
        }
        if (uVar9 < uVar6) {
          puVar5 = (uint *)((ulonglong)uVar9 * 0x1c + 0x194 + param_1);
          uVar8 = (ulonglong)(uVar6 - uVar9);
          do {
            uVar1 = *puVar5;
            uVar4 = (ulonglong)uVar1;
            if (((uVar1 >> 8 & 1) != 0) || ((char)uVar1 < '\0')) {
              iVar7 = iVar7 + 1;
            }
            puVar5 = puVar5 + 7;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
          if (iVar7 != 0) {
            *(longlong *)(lVar3 + 0x238) = param_2;
            *(undefined4 *)(lVar2 + 0x2988) = 0;
            *(longlong *)(lVar2 + 0x2970) = lVar3;
            *(undefined4 *)(lVar2 + 0x298c) = 0x80;
            *(uint *)(lVar2 + 0x297c) = uVar9;
            *(uint *)(lVar2 + 0x2980) = uVar6;
            uVar4 = (ulonglong)CONCAT31((int3)(uVar1 >> 8),*(byte *)(param_1 + 0x9f64));
            if ((*(byte *)(param_1 + 0x9f64) & 0x10) == 0) {
              LOCK();
              *(int *)(param_1 + 0xa098) = *(int *)(param_1 + 0xa098) + 1;
              UNLOCK();
              local_res8[0] = 0;
              uVar4 = StorPortNotification(0x1002,param_1,param_1 + 0x9350,0,0,local_res8);
            }
            goto LAB_00018d84;
          }
        }
        *(undefined1 *)(lVar3 + 0x231) = 0;
        if (param_2 != 0) {
          *(undefined1 *)(param_2 + 3) = 1;
          goto LAB_00018d7c;
        }
        goto LAB_00018d84;
      }
      if (param_2 != 0) {
        *(undefined1 *)(param_2 + 3) = 4;
        goto LAB_00018c72;
      }
    }
    else if (param_2 != 0) {
      *(undefined1 *)(param_2 + 3) = 0xe;
LAB_00018c72:
      uVar4 = StorPortNotification(0,param_1,param_2);
    }
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  else {
    if (param_2 != 0) {
      *(undefined1 *)(param_2 + 3) = 0xe;
LAB_00018d7c:
      uVar4 = StorPortNotification(0,param_1,param_2);
    }
LAB_00018d84:
    uVar4 = CONCAT71((int7)(uVar4 >> 8),1);
  }
  return uVar4;
}



===== CissResetTarget @ 00018d9c =====

void CissResetTarget(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 local_res8 [8];
  
  lVar2 = *(longlong *)(param_1 + 0x93c0);
  lVar3 = *(longlong *)(param_1 + 0x93d8);
  if (*(char *)(*(longlong *)(param_1 + 0x93e8) + 0x438) != '\0') {
    *(undefined1 *)(param_2 + 3) = 0xe;
    StorPortNotification(0,param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x00018de5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    StorPortNotification(3,param_1);
    return;
  }
  if ((*(byte *)(param_1 + 0x9e38) & 0x20) == 0) {
    *(undefined1 *)(param_2 + 3) = 4;
  }
  else if (*(char *)(lVar3 + 0x231) == '\0') {
    if (*(char *)(param_2 + 7) == '\0') {
      uVar4 = (uint)*(byte *)(param_2 + 5) * 0x80 + (uint)*(byte *)(param_2 + 6);
    }
    else {
      uVar4 = 0xffffffff;
    }
    if ((uVar4 != 0xffffffff) &&
       ((uVar1 = *(uint *)((ulonglong)uVar4 * 0x1c + 0x194 + param_1), (uVar1 >> 8 & 1) != 0 ||
        ((char)uVar1 < '\0')))) {
      *(longlong *)(lVar3 + 0x238) = param_2;
      *(undefined1 *)(lVar3 + 0x231) = 1;
      *(longlong *)(lVar2 + 0x2998) = lVar3;
      *(undefined4 *)(lVar2 + 0x29b4) = 0x81;
      *(uint *)(lVar2 + 0x29a4) = uVar4;
      *(uint *)(lVar2 + 0x29a8) = uVar4 + 1;
      *(undefined4 *)(lVar2 + 0x29b0) = 0;
      if ((*(byte *)(param_1 + 0x9f64) & 0x10) == 0) {
        LOCK();
        *(int *)(param_1 + 0xa098) = *(int *)(param_1 + 0xa098) + 1;
        UNLOCK();
        local_res8[0] = 0;
        StorPortNotification(0x1002,param_1,param_1 + 0x9350,0,0,local_res8);
      }
      return;
    }
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 0xe;
  }
                    /* WARNING: Could not recover jumptable at 0x00018e5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1,param_2);
  return;
}



===== CissResetLogicalUnit @ 00018ee8 =====

void CissResetLogicalUnit(uint *param_1,longlong param_2)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  
  puVar1 = *(undefined4 **)(param_2 + 0x38);
  if (*(char *)(*(longlong *)(param_1 + 0x24fa) + 0x438) != '\0') {
    *(undefined1 *)(param_2 + 3) = 0xe;
    StorPortNotification(0,param_1,param_2);
    StorPortNotification(3,param_1);
    return;
  }
  if ((param_1[0x278e] & 0x20) == 0) {
    *(undefined1 *)(param_2 + 3) = 4;
  }
  else {
    *(longlong *)(puVar1 + 0x16) = param_2;
    *(undefined4 **)(puVar1 + 0xe) = puVar1;
    if (*(char *)(param_2 + 7) == '\0') {
      uVar3 = (uint)*(byte *)(param_2 + 5) * 0x80 + (uint)*(byte *)(param_2 + 6);
    }
    else {
      uVar3 = 0xffffffff;
    }
    if (uVar3 != 0xffffffff) {
      if (((param_1[(ulonglong)uVar3 * 7 + 0x65] >> 8 & 1) != 0) ||
         ((char)param_1[(ulonglong)uVar3 * 7 + 0x65] < '\0')) {
        if ((param_1[(ulonglong)uVar3 * 7 + 0x65] >> 0x11 & 1) == 0) {
          *(undefined1 *)((longlong)puVar1 + 7) = 0;
          cVar2 = (char)(uVar3 >> 7);
          *(char *)((longlong)puVar1 + 5) = cVar2;
          *(char *)((longlong)puVar1 + 6) = cVar2 * -0x80 + (char)uVar3;
          cVar2 = CissSendReset(param_1,puVar1,uVar3,0x84);
          if (cVar2 != '\0') {
            return;
          }
        }
        *(undefined1 *)(param_2 + 3) = 5;
        goto LAB_00018fcb;
      }
    }
    *(undefined1 *)(param_2 + 3) = 1;
  }
LAB_00018fcb:
  StorPortNotification(0,param_1,param_2);
  return;
}



===== MakeScatterGatherList @ 00018fe8 =====

undefined8 MakeScatterGatherList(longlong param_1,longlong param_2,undefined8 param_3)

{
  uint *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  uint local_res10 [2];
  
  uVar3 = *(ulonglong *)(param_2 + 0x38);
  uVar5 = *(uint *)(param_2 + 0x10);
  lVar8 = *(longlong *)(param_2 + 0x18);
  uVar4 = uVar3 + 0x124 & 0xffffffffffffffe0;
  uVar6 = 0;
  *(ulonglong *)(uVar3 + 0xa8) = uVar4;
  puVar7 = (undefined8 *)(uVar4 + 0x34);
  if (*(int *)(param_2 + 0x10) == 0) {
    *(undefined1 *)(uVar4 + 1) = 0;
    *(undefined2 *)(uVar4 + 2) = 0;
  }
  else {
    do {
      local_res10[0] = 0;
      uVar2 = StorPortGetPhysicalAddress(param_1,param_3,lVar8,local_res10);
      *(undefined4 *)((longlong)puVar7 + 0xc) = 0;
      *puVar7 = uVar2;
      if (local_res10[0] < uVar5) {
        *(uint *)(puVar7 + 1) = local_res10[0];
      }
      else {
        *(uint *)(puVar7 + 1) = uVar5;
      }
      puVar1 = (uint *)(puVar7 + 1);
      uVar3 = (ulonglong)*puVar1;
      puVar7 = puVar7 + 2;
      uVar6 = uVar6 + 1;
      lVar8 = lVar8 + uVar3;
      uVar5 = uVar5 - *puVar1;
    } while ((uVar5 != 0) &&
            (uVar3 = (ulonglong)*(ushort *)(param_1 + 0x9f5e), uVar6 < *(ushort *)(param_1 + 0x9f5e)
            ));
    *(char *)(uVar4 + 1) = (char)uVar6;
    *(short *)(uVar4 + 2) = (short)uVar6;
  }
  return CONCAT71((int7)(uVar3 >> 8),uVar5 == 0);
}



===== BuildCissCommand @ 000190c0 =====

void BuildCissCommand(longlong param_1,longlong param_2,int param_3)

{
  undefined8 *_Dst;
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined1 *puVar4;
  char cVar5;
  byte bVar6;
  short sVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  longlong lVar11;
  uint uVar12;
  undefined4 local_res18 [2];
  
  lVar2 = *(longlong *)(param_2 + 0x38);
  lVar11 = lVar2 + 0x60;
  plVar3 = *(longlong **)(lVar2 + 0x88);
  puVar4 = *(undefined1 **)(lVar2 + 0xa8);
  lVar8 = lVar2 + 0x70;
  *(longlong *)lVar8 = lVar8;
  *(undefined8 *)(lVar2 + 0xfc) = 0;
  *(longlong *)(lVar2 + 0x78) = lVar8;
  *(longlong *)(lVar2 + 0x68) = lVar11;
  *(longlong *)lVar11 = lVar11;
  *(int *)(lVar2 + 0xf8) = param_3;
  if ((char)param_3 < '\0') {
    puVar4[0x15] = puVar4[0x15] & 0xf9 | 1;
  }
  else {
    puVar4[0x15] = puVar4[0x15] & 0xf8;
  }
  *puVar4 = 0;
  *(longlong *)(lVar2 + 0x80) = param_2;
  *(undefined4 *)(puVar4 + 8) = 0;
  puVar4[0x14] = *(undefined1 *)(param_2 + 10);
  sVar7 = *(short *)(param_2 + 0x14);
  if (1 < *(uint *)(param_2 + 0x14)) {
    sVar7 = sVar7 + -1;
  }
  *(short *)(puVar4 + 0x16) = sVar7;
  _Dst = (undefined8 *)(puVar4 + 0x18);
  *_Dst = 0;
  *(undefined8 *)(puVar4 + 0x20) = 0;
  memcpy(_Dst,(void *)(param_2 + 0x48),(ulonglong)*(byte *)(param_2 + 10));
  uVar9 = *(uint *)(param_2 + 0xc) & 0x40;
  cVar5 = (char)*(uint *)(param_2 + 0xc);
  if ((uVar9 == 0) || (-1 < cVar5)) {
    if (uVar9 == 0) {
      if (-1 < cVar5) {
        puVar4[0x15] = puVar4[0x15] & 0x3f;
        goto LAB_000191a3;
      }
      bVar6 = puVar4[0x15] & 0x3f | 0x40;
    }
    else {
      bVar6 = puVar4[0x15] & 0x3f | 0x80;
    }
    puVar4[0x15] = bVar6;
  }
  else {
    puVar4[0x15] = puVar4[0x15] | 0xc0;
  }
LAB_000191a3:
  if ((*(uint *)(param_2 + 0xc) & 2) == 0) {
    puVar4[0x15] = puVar4[0x15] & 199;
  }
  else {
    cVar5 = *(char *)(param_2 + 9);
    if (cVar5 == ' ') {
      bVar6 = puVar4[0x15] & 0xe7 | 0x20;
    }
    else if (cVar5 == '!') {
      bVar6 = puVar4[0x15] & 0xef | 0x28;
    }
    else {
      if (cVar5 != '\"') goto LAB_000191db;
      bVar6 = puVar4[0x15] & 0xf7 | 0x30;
    }
    puVar4[0x15] = bVar6;
  }
LAB_000191db:
  local_res18[0] = 0x39;
  *(undefined8 *)(lVar2 + 0x90) = 0;
  *(undefined2 *)(lVar2 + 0xbc) = 1;
  *(undefined1 *)(lVar2 + 0xbf) = 0;
  if (-1 < *(char *)(param_1 + 0x9f64)) goto LAB_00019340;
  cVar5 = puVar4[0x14];
  lVar8 = *(longlong *)(param_2 + 0x38);
  *(undefined1 *)(lVar8 + 0xbe) = *(undefined1 *)_Dst;
  if (cVar5 == '\n') {
    *(ulonglong *)(lVar8 + 0x98) = (ulonglong)*(uint *)(param_2 + 0x40);
  }
  cVar1 = *(char *)(lVar8 + 0xbe);
  if (cVar1 == '(') {
LAB_00019259:
    if (*(uint *)(param_1 + 0x9e64) <= *(uint *)(lVar8 + 0xb8)) goto LAB_00019268;
    *(undefined1 *)(lVar8 + 0xbf) = 1;
  }
  else {
    if (cVar1 == '*') {
LAB_00019241:
      if (*(uint *)(lVar8 + 0xb8) < *(uint *)(param_1 + 0x9e68)) {
        *(undefined1 *)(lVar8 + 0xbf) = 2;
        goto LAB_00019278;
      }
    }
    else {
      if (cVar1 == -0x78) goto LAB_00019259;
      if (cVar1 == -0x76) goto LAB_00019241;
    }
LAB_00019268:
    *(undefined1 *)(lVar8 + 0xbf) = 0;
  }
LAB_00019278:
  if ((*(byte *)(*(longlong *)(lVar8 + 0xa8) + 0x15) >> 3 & 3) != 0) {
    *(undefined1 *)(lVar8 + 0xbf) = 0;
  }
  uVar9 = *(uint *)(param_2 + 0x10);
  *(uint *)(lVar8 + 0xb8) = uVar9;
  if (*(char *)(lVar8 + 0xbf) != '\0') {
    uVar12 = uVar9 >> 9;
    if ((uVar9 & 0x1ff) != 0) {
      uVar12 = uVar12 + 1;
    }
    if (cVar5 == '\n') {
      lVar11 = (ulonglong)uVar12 + *(longlong *)(lVar8 + 0x98);
    }
    else {
      if (cVar5 != '\x10') goto LAB_00019340;
      lVar10 = CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(puVar4[0x1a],
                                                                              puVar4[0x1b]),
                                                                     puVar4[0x1c]),puVar4[0x1d]),
                                                   puVar4[0x1e]),puVar4[0x1f]),puVar4[0x20]),
                        puVar4[0x21]);
      lVar11 = (ulonglong)uVar12 + lVar10;
      *(longlong *)(lVar8 + 0x98) = lVar10;
    }
    *(longlong *)(lVar8 + 0xa0) = lVar11;
  }
LAB_00019340:
  memset((void *)(lVar2 + 0xc0),0,0x38);
  lVar8 = 0;
  if (param_3 == 0) {
    lVar8 = param_2;
  }
  if ((plVar3 == (longlong *)0x0) || (param_3 != 0x80)) {
    lVar8 = StorPortGetPhysicalAddress(param_1,lVar8,lVar2 + 0xc0,local_res18);
  }
  else {
    lVar8 = lVar2 + 0xc0 + (*plVar3 - plVar3[1]);
  }
  *(longlong *)(puVar4 + 0x28) = lVar8;
  *(undefined4 *)(puVar4 + 0x30) = 0x38;
  return;
}



===== CissSendNotifyOnEvent @ 000193bc =====

ulonglong CissSendNotifyOnEvent(uint *param_1,byte param_2)

{
  void *_Dst;
  longlong lVar1;
  char cVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  undefined8 local_res8;
  
  uVar3 = (ulonglong)(ushort)param_1[0x27d9];
  _Dst = *(void **)(param_1 + 0x24fc);
  if (((ushort)param_1[0x27d9] & 0x1000) != 0) {
    if (*(char *)((longlong)_Dst + 0x3d8) == '\x01') {
LAB_000193f6:
      return uVar3 & 0xffffffffffffff00;
    }
    uVar3 = (ulonglong)param_1[0x24e6];
    if ((param_1[0x24e6] & 0x2401107) == 0) {
      *(undefined1 *)((longlong)_Dst + 0x3d8) = 1;
      memset((void *)(*(longlong *)(param_1 + 0x24fc) + 0x1d8),0,0x200);
      memset(_Dst,0,0x60);
      *(undefined8 *)((longlong)_Dst + 0x58) = 0;
      *(undefined2 *)((longlong)_Dst + 5) = 0xffff;
      *(undefined1 *)((longlong)_Dst + 7) = 0xff;
      *(undefined2 *)((longlong)_Dst + 10) = 0x1210;
      *(undefined4 *)((longlong)_Dst + 0xc) = 0x40;
      *(undefined4 *)((longlong)_Dst + 0x10) = 0x200;
      *(longlong *)((longlong)_Dst + 0x20) = (longlong)_Dst + 0xd0;
      lVar1 = *(longlong *)(param_1 + 0x24fc);
      *(undefined4 *)((longlong)_Dst + 0x14) = 0x708;
      *(void **)((longlong)_Dst + 0x38) = _Dst;
      *(longlong *)((longlong)_Dst + 0x18) = lVar1 + 0x1d8;
      *(undefined8 *)((longlong)_Dst + 0x48) = 0;
      *(undefined8 *)((longlong)_Dst + 0x50) = 0;
      *(byte *)((longlong)_Dst + 0x4e) = *(byte *)((longlong)_Dst + 0x4e) | 0x80;
      *(byte *)((longlong)_Dst + 0x4f) = *(byte *)((longlong)_Dst + 0x4f) & 0xfe;
      *(undefined2 *)((longlong)_Dst + 0x48) = 0xd0c0;
      *(undefined4 *)((longlong)_Dst + 0x52) = 0x20000;
      MakeScatterGatherList((longlong)param_1,(longlong)_Dst,0);
      BuildCissCommand((longlong)param_1,(longlong)_Dst,0xd);
      local_res8 = 0;
      cVar2 = SubmitCissCommand(param_1,(longlong)_Dst,&local_res8,(ushort)param_2);
      uVar3 = CONCAT71(extraout_var,cVar2);
      if (cVar2 == '\0') {
        uVar3 = *(ulonglong *)(param_1 + 0x24fc);
        *(undefined1 *)(uVar3 + 0x3d8) = 0;
        goto LAB_000193f6;
      }
    }
  }
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== CissCancelNotifyOnEvent @ 00019510 =====

ulonglong CissCancelNotifyOnEvent(uint *param_1)

{
  void *_Dst;
  char cVar1;
  ulonglong uVar2;
  undefined7 extraout_var;
  undefined8 local_res8;
  
  uVar2 = (ulonglong)(ushort)param_1[0x27d9];
  _Dst = *(void **)(param_1 + 0x24fe);
  if (((ushort)param_1[0x27d9] & 0x1000) == 0) {
LAB_0001960b:
    uVar2 = CONCAT71((int7)(uVar2 >> 8),1);
  }
  else {
    if (*(char *)((longlong)_Dst + 0x1d8) != '\x01') {
      *(undefined1 *)((longlong)_Dst + 0x1d8) = 1;
      memset(_Dst,0,0x60);
      *(undefined8 *)((longlong)_Dst + 0x58) = 0;
      *(undefined4 *)((longlong)_Dst + 0x10) = 0;
      *(undefined8 *)((longlong)_Dst + 0x18) = 0;
      *(undefined2 *)((longlong)_Dst + 5) = 0xffff;
      *(undefined1 *)((longlong)_Dst + 7) = 0xff;
      *(undefined2 *)((longlong)_Dst + 10) = 0x1210;
      *(undefined4 *)((longlong)_Dst + 0xc) = 0x40;
      *(undefined4 *)((longlong)_Dst + 0x14) = 10;
      *(void **)((longlong)_Dst + 0x38) = _Dst;
      *(longlong *)((longlong)_Dst + 0x20) = (longlong)_Dst + 0xd0;
      *(undefined8 *)((longlong)_Dst + 0x48) = 0;
      *(undefined8 *)((longlong)_Dst + 0x50) = 0;
      *(undefined4 *)((longlong)_Dst + 0x52) = 0;
      *(undefined2 *)((longlong)_Dst + 0x48) = 0xd1c0;
      MakeScatterGatherList((longlong)param_1,(longlong)_Dst,0);
      BuildCissCommand((longlong)param_1,(longlong)_Dst,0xe);
      local_res8 = 0;
      cVar1 = SubmitCissCommand(param_1,(longlong)_Dst,&local_res8,(ushort)param_1[0x27d9] >> 5 & 1)
      ;
      uVar2 = CONCAT71(extraout_var,cVar1);
      if (cVar1 != '\0') goto LAB_0001960b;
      uVar2 = *(ulonglong *)(param_1 + 0x24fe);
      *(undefined1 *)(uVar2 + 0x1d8) = 0;
    }
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  return uVar2;
}



===== CissCheckEvent @ 00019620 =====

void CissCheckEvent(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  short sVar1;
  byte bVar2;
  
  sVar1 = *(short *)(param_3 + 4);
  bVar2 = 0;
  if (((sVar1 != 2) ||
      (((*(short *)(param_3 + 6) != 4 || (*(short *)(param_3 + 8) != 0)) &&
       ((*(short *)(param_3 + 6) != 4 || (*(short *)(param_3 + 8) != 1)))))) &&
     ((((sVar1 != 5 || (*(short *)(param_3 + 6) != 0)) || (*(short *)(param_3 + 8) != 0)) &&
      (sVar1 == 8)))) {
    if ((*(short *)(param_3 + 6) == 1) && (*(short *)(param_3 + 8) == 0)) {
      do {
        StorPortNotification(7,param_1,bVar2);
        bVar2 = bVar2 + 1;
      } while (bVar2 < 9);
    }
    else if ((*(short *)(param_3 + 6) == 1) && (*(short *)(param_3 + 8) == 1)) {
      do {
        StorPortNotification(7,param_1,bVar2);
        bVar2 = bVar2 + 1;
      } while (bVar2 < 9);
    }
    else if (((*(short *)(param_3 + 6) != 1) || (*(short *)(param_3 + 8) != 2)) &&
            ((*(short *)(param_3 + 6) == 3 && (*(short *)(param_3 + 8) == 0)))) {
      do {
        StorPortNotification(7,param_1,bVar2);
        bVar2 = bVar2 + 1;
      } while (bVar2 < 9);
    }
  }
  return;
}



===== CissWmiSrb @ 0001973c =====

undefined8 CissWmiSrb(longlong param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  undefined8 uVar3;
  uint local_res10 [2];
  int local_res18 [4];
  undefined1 local_38 [8];
  uint local_30;
  uint *local_28;
  byte local_20;
  char local_1f;
  uint local_1c;
  
  if ((*(byte *)(param_2 + 9) & 1) == 0) {
    *(undefined1 *)(param_2 + 3) = 1;
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  else {
    memset(local_38,0,0x20);
    bVar1 = *(byte *)(param_2 + 4);
    local_res10[0] = 0;
    local_1c = 0;
    if (bVar1 < 10) {
      local_30 = *(uint *)(param_2 + 0x10);
      local_28 = *(uint **)(param_2 + 0x18);
      local_20 = bVar1;
      cVar2 = ScsiWmipProcessRequest
                        ((uint *)(param_1 + 0xf0),bVar1,param_1,local_38,
                         *(longlong **)(param_2 + 0x20),*(uint *)(param_2 + 0x10),
                         *(uint **)(param_2 + 0x18),local_res10,(short *)local_res18);
      if (local_res18[0] == 1) {
        local_1c = local_res10[0];
        if (cVar2 != '\x01') {
          local_1c = 0;
        }
        local_1f = cVar2;
      }
      if (cVar2 == '\0') {
        *(uint *)(param_2 + 0x10) = local_1c;
        *(char *)(param_2 + 3) = local_1f;
      }
    }
    else {
      local_1f = '\x04';
    }
  }
  uVar3 = StorPortNotification(0,param_1,param_2);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== CissWmiQueryDataBlock @ 0001983c =====

ulonglong CissWmiQueryDataBlock
                    (uint *param_1,longlong param_2,int param_3,int param_4,int param_5,
                    undefined4 *param_6,uint param_7,uint *param_8)

{
  ulonglong uVar1;
  char cVar2;
  uint uVar3;
  uint local_res8 [2];
  char local_res20 [8];
  
  cVar2 = '\x01';
  local_res20[0] = '\x01';
  local_res8[0] = 0;
  if ((param_4 == 0) && (param_5 == 1)) {
    if (param_3 == 0) {
      uVar3 = 0x10;
      if (param_7 < 0x10) {
        cVar2 = '\x12';
      }
      else {
        *param_6 = 0x10;
        memset(param_8,0,0x10);
        *param_8 = param_1[6];
        param_8[1] = param_1[0x2799];
        param_8[2] = param_1[0x279a];
        cVar2 = '\x01';
      }
    }
    else {
      if (param_3 == 1) {
        CissWmiGetDriverInfo((longlong)param_1,param_6,param_7,local_res8,local_res20,param_8);
      }
      else {
        if (param_3 == 2) {
          if (param_7 < 8) {
            cVar2 = '\x12';
          }
          else {
            *param_6 = 8;
            param_8[0] = 0;
            param_8[1] = 0;
            uVar3 = param_1[0x24e6];
            if ((uVar3 & 0x2401107) == 0) {
              *param_8 = 1;
            }
            else if ((uVar3 >> 0xc & 1) == 0) {
              if ((uVar3 & 2) == 0) {
                param_8[0] = 3;
                param_8[1] = 0;
              }
              else {
                param_8[0] = 2;
                param_8[1] = 0;
              }
            }
            else {
              param_8[0] = 4;
              param_8[1] = 0;
            }
            cVar2 = '\x01';
          }
          uVar3 = 8;
          goto LAB_000199ff;
        }
        if (param_3 != 3) {
          if (param_3 == 4) {
            if ((param_8 == (uint *)0x0) || (param_7 < 0x208)) {
              cVar2 = '\x12';
              uVar3 = 0x208;
            }
            else {
              if (((ulonglong)param_8 & 7) != 0) {
                param_8 = (uint *)((ulonglong)(param_8 + 2) & 0xfffffffffffffff8);
              }
              uVar3 = 0x200;
              memcpy(param_8,(void *)(*(longlong *)(param_1 + 0x24fc) + 0x1d8),0x200);
              *(undefined1 *)((longlong)param_1 + 0x9e6d) = 1;
            }
            CissSendNotifyOnEvent(param_1,(byte)param_1[0x27d9] >> 5 & 1);
          }
          else {
            cVar2 = '\x04';
            uVar3 = 0;
          }
          goto LAB_000199ff;
        }
        FUN_00019c08((longlong)param_1,param_6,param_7,local_res8,local_res20,param_8);
      }
      cVar2 = local_res20[0];
      uVar3 = local_res8[0];
    }
  }
  else {
    uVar3 = 0;
    cVar2 = '\x04';
  }
LAB_000199ff:
  uVar1 = ScsiPortWmiPostProcess(param_2,cVar2,uVar3);
  return uVar1 & 0xffffffffffffff00;
}



===== CissWmiFunctionControl @ 00019a24 =====

undefined1
CissWmiFunctionControl
          (longlong param_1,longlong param_2,int param_3,undefined8 param_4,undefined1 param_5)

{
  char cVar1;
  
  cVar1 = '\x01';
  if (param_3 == 4) {
    *(undefined1 *)(param_1 + 0x9e6c) = param_5;
  }
  else {
    cVar1 = '\x04';
  }
  ScsiPortWmiPostProcess(param_2,cVar1,0);
  return 0;
}



===== CissWmiGetDriverInfo @ 00019a5c =====

void CissWmiGetDriverInfo
               (longlong param_1,undefined4 *param_2,uint param_3,undefined4 *param_4,
               undefined1 *param_5,undefined4 *param_6)

{
  byte bVar1;
  undefined2 uVar2;
  
  if (param_3 < 0x1a8) {
    *param_5 = 0x12;
    goto LAB_00019bec;
  }
  *param_2 = 0x1a8;
  memset(param_6,0,0x1a8);
  *param_6 = 8;
  param_6[1] = 4;
  *(undefined2 *)(param_6 + 5) = 200;
  builtin_wcsncpy((wchar_t *)((longlong)param_6 + 0x16),L"HpSA",4);
  builtin_wcsncpy((wchar_t *)((longlong)param_6 + 0x1e),L"MD.s",4);
  *(undefined4 *)((longlong)param_6 + 0x26) = 0x730079;
  *(undefined2 *)((longlong)param_6 + 0x2a) = 0;
  *(undefined2 *)((longlong)param_6 + 0xde) = 200;
  builtin_wcsncpy((wchar_t *)(param_6 + 0x38),L"Smar",4);
  builtin_wcsncpy((wchar_t *)(param_6 + 0x3a),L"t Ar",4);
  builtin_wcsncpy((wchar_t *)(param_6 + 0x3c),L"ray ",4);
  builtin_wcsncpy((wchar_t *)(param_6 + 0x3e),L"SAS/",4);
  builtin_wcsncpy((wchar_t *)(param_6 + 0x40),L"SATA",4);
  builtin_wcsncpy((wchar_t *)(param_6 + 0x42),L" Con",4);
  builtin_wcsncpy((wchar_t *)(param_6 + 0x44),L"trol",4);
  builtin_wcsncpy((wchar_t *)(param_6 + 0x46),L"ler ",4);
  builtin_wcsncpy((wchar_t *)(param_6 + 0x48),L"Medi",4);
  builtin_wcsncpy((wchar_t *)(param_6 + 0x4a),L"a Dr",4);
  builtin_wcsncpy((wchar_t *)(param_6 + 0x4c),L"iver",4);
  *(undefined2 *)(param_6 + 0x4e) = 0;
  param_6[2] = *(undefined4 *)(param_1 + 0x9dec);
  *(undefined2 *)((longlong)param_6 + 0xe) = *(undefined2 *)(param_1 + 0x9f60);
  *(undefined2 *)(param_6 + 3) = *(undefined2 *)(param_1 + 0x9f5e);
  bVar1 = (byte)*(undefined2 *)(param_1 + 0x9f64);
  if ((char)bVar1 < '\0') {
    uVar2 = 3;
LAB_00019bc6:
    *(undefined2 *)(param_6 + 4) = uVar2;
  }
  else {
    if ((bVar1 & 0xf) == 4) {
      uVar2 = 2;
      goto LAB_00019bc6;
    }
    *(undefined2 *)(param_6 + 4) = 1;
  }
  *(undefined2 *)((longlong)param_6 + 0x12) = *(undefined2 *)(param_1 + 0x9f68);
  *param_5 = 1;
LAB_00019bec:
  *param_4 = 0x1a8;
  return;
}



===== FUN_00019c08 @ 00019c08 =====

void FUN_00019c08(longlong param_1,undefined4 *param_2,uint param_3,undefined4 *param_4,
                 undefined1 *param_5,undefined4 *param_6)

{
  byte bVar1;
  
  if (param_3 < 0x1b8) {
    *param_5 = 0x12;
  }
  else {
    *param_2 = 0x1b8;
    memset(param_6,0,0x1b8);
    *param_6 = *(undefined4 *)(param_1 + 0x9de8);
    param_6[1] = *(undefined4 *)(param_1 + 0x9420);
    param_6[2] = *(undefined4 *)(param_1 + 0x9424);
    param_6[3] = *(undefined4 *)(param_1 + 0x9428);
    param_6[4] = *(undefined4 *)(param_1 + 0x942c);
    param_6[5] = *(undefined4 *)(param_1 + 0x92f4);
    bVar1 = *(byte *)(param_1 + 1);
    *(undefined1 *)(param_6 + 7) = 4;
    *(ushort *)(param_6 + 6) = (ushort)bVar1;
    *(undefined2 *)((longlong)param_6 + 0x1a) = 0xffff;
    *(undefined1 *)((longlong)param_6 + 0x1d) = *(undefined1 *)(param_1 + 0x92fa);
    *(undefined1 *)((longlong)param_6 + 0x1e) = *(undefined1 *)(param_1 + 0x92f0);
    *(undefined1 *)((longlong)param_6 + 0x1f) = *(undefined1 *)(param_1 + 0x92f1);
    *(undefined1 *)(param_6 + 8) = *(undefined1 *)(param_1 + 0x92f2);
    *(undefined2 *)((longlong)param_6 + 0x22) = 200;
    builtin_wcsncpy((wchar_t *)(param_6 + 9),L"0000",4);
    *(undefined2 *)(param_6 + 0xb) = 0x30;
    *param_5 = 1;
  }
  *param_4 = 0x1b8;
  return;
}



===== FUN_00019d00 @ 00019d00 =====

void FUN_00019d00(uint *param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  uint *puVar4;
  longlong lVar5;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  StorPortSynchronizeAccess(param_1,CissCheckHeartBeat,local_res8);
  uVar2 = param_1[1];
  if (local_res8[0] == uVar2) {
LAB_00019d62:
    if (uVar2 != 0) {
      if ((param_1[0x24e6] & 0x2401107) == 0) {
        param_1[99] = param_1[99] + 1;
        param_1[0x2797] = 0;
        uVar2 = 0x1e;
        if (0 < (int)param_1[0x2796]) {
          uVar2 = 0xf0;
        }
        if (uVar2 < param_1[99]) {
          param_1[0x24e6] = param_1[0x24e6] | 2;
          StorPortLogError(param_1,0,0,0,0,6,0x80000001);
          lVar5 = 0;
          puVar4 = param_1 + 0x1cbc;
          lVar3 = 0x200;
          do {
            lVar1 = *(longlong *)puVar4;
            if (((lVar1 != lVar5) && (((byte)lVar1 & 0xf) != 0xf)) && (*(int *)(lVar1 + 0x98) == 0))
            {
              *(undefined1 *)(*(longlong *)(lVar1 + 0x20) + 3) = 0x11;
              StorPortNotification(0,param_1,*(undefined8 *)(lVar1 + 0x20));
            }
            lVar5 = lVar5 + 1;
            puVar4 = puVar4 + 4;
            lVar3 = lVar3 + -1;
          } while (lVar3 != 0);
        }
      }
      goto LAB_00019e33;
    }
  }
  else {
    param_1[0x2797] = param_1[0x2797] + 1;
    if (0x77 < param_1[0x2797]) {
      param_1[0x2796] = 0;
      param_1[0x2797] = 0;
    }
    if (local_res8[0] == uVar2) goto LAB_00019d62;
  }
  param_1[99] = 0;
  param_1[1] = local_res8[0];
LAB_00019e33:
  if ((param_1[0x24e6] & 0x2401107) == 0) {
    if (*(byte *)((longlong)param_1 + 0x9f35) < 0x79) {
      *(byte *)((longlong)param_1 + 0x9f35) = *(byte *)((longlong)param_1 + 0x9f35) + 1;
    }
    if (((0x77 < *(byte *)((longlong)param_1 + 0x9f35)) || ((char)param_1[0x279b] == '\x01')) &&
       ((*(char *)(*(longlong *)(param_1 + 0x24fe) + 0x1d8) == '\0' &&
        (*(char *)((longlong)param_1 + 0x9e6d) == '\x01')))) {
      CissSendNotifyOnEvent(param_1,(byte)param_1[0x27d9] >> 5 & 1);
    }
    *(undefined2 *)(param_1 + 0x27db) = 1;
  }
  return;
}



===== CissCheckHeartBeat @ 00019eb4 =====

undefined4 CissCheckHeartBeat(longlong param_1,undefined4 *param_2)

{
  undefined4 in_EAX;
  
  if ((*(uint *)(param_1 + 0x9398) & 0x2401107) == 0) {
    in_EAX = (**(code **)(param_1 + 0x170))();
    *param_2 = in_EAX;
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}



===== TimerReleaseWait @ 00019ee0 =====

void TimerReleaseWait(longlong param_1)

{
  *(ushort *)(param_1 + 0x9f64) = *(ushort *)(param_1 + 0x9f64) & 0xf7ff;
  return;
}



===== FUN_00019ef4 @ 00019ef4 =====

void FUN_00019ef4(uint *param_1)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if ((*param_1 & 0x10000000) == 0) {
    uVar3 = 4;
    do {
      if ((param_1[uVar3 * 7 + 0x65] & 0x100) != 0) {
        uVar2 = param_1[0x277b];
        if ((uint)(ushort)param_1[0x27d8] < param_1[0x277b]) {
          uVar2 = (uint)(ushort)param_1[0x27d8];
        }
        cVar1 = StorPortSetDeviceQueueDepth
                          (param_1,uVar3 >> 7,(char)(uVar3 >> 7) * -0x80 + (char)uVar3,0,uVar2 - 8);
        if ((cVar1 == '\0') && (*(ushort *)((longlong)param_1 + 0x9f62) < 3)) {
          *(short *)((longlong)param_1 + 0x9f62) = *(short *)((longlong)param_1 + 0x9f62) + 1;
          *(undefined2 *)(param_1 + 0x27dc) = 3;
          return;
        }
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < 0x380);
    *(undefined2 *)((longlong)param_1 + 0x9f62) = 0;
  }
  return;
}



===== FUN_00019fc0 @ 00019fc0 =====

undefined1 FUN_00019fc0(longlong param_1,longlong *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined4 local_res10 [2];
  
  uVar1 = *(uint *)(param_2 + 2);
  lVar2 = param_2[1];
  lVar3 = *param_2;
  uVar7 = 0;
  uVar6 = 1;
  if (uVar1 != 0) {
    do {
      if (uVar1 == 1) {
        lVar5 = lVar2;
      }
      else {
        lVar5 = (ulonglong)(uVar7 % 7) * 0x240 + *(longlong *)(lVar3 + 8);
      }
      if (*(char *)(lVar5 + 0x230) == '\x01') {
        if (*(char *)(lVar5 + 0x1df) == '\0') {
          uVar4 = (ulonglong)
                  ((uint)*(byte *)(lVar5 + 0x1dd) * 0x80 + (uint)*(byte *)(lVar5 + 0x1de));
        }
        else {
          uVar4 = 0xffffffff;
        }
        if (((int)uVar4 == -1) || ((*(uint *)(uVar4 * 0x1c + 0x194 + param_1) >> 0x11 & 1) != 0)) {
          uVar6 = 0;
        }
        else {
          *(undefined1 *)(lVar5 + 0x232) = 0;
          *(undefined1 *)(lVar5 + 0x230) = 0;
          if ((*(byte *)(param_1 + 0x9f64) & 0x10) == 0) {
            LOCK();
            *(int *)(param_1 + 0xa098) = *(int *)(param_1 + 0xa098) + 1;
            UNLOCK();
            local_res10[0] = 0;
            StorPortNotification(0x1002,param_1,param_1 + 0x9350,0,0,local_res10);
          }
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar1);
  }
  return uVar6;
}



===== FUN_0001a0e4 @ 0001a0e4 =====

void FUN_0001a0e4(longlong param_1)

{
  char cVar1;
  
  cVar1 = FUN_00019fc0(param_1,(longlong *)(*(longlong *)(param_1 + 0x93c0) + 0x2968));
  if (cVar1 == '\0') {
    *(undefined2 *)(param_1 + 0x9f72) = 1;
  }
  return;
}



===== FUN_0001a11c @ 0001a11c =====

void FUN_0001a11c(longlong param_1)

{
  char cVar1;
  
  cVar1 = FUN_00019fc0(param_1,(longlong *)(*(longlong *)(param_1 + 0x93c0) + 0x2990));
  if (cVar1 == '\0') {
    *(undefined2 *)(param_1 + 0x9f74) = 1;
  }
  return;
}



===== TimerTick @ 0001a154 =====

void TimerTick(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  undefined **ppuVar4;
  short *psVar5;
  
  ppuVar4 = &PTR_FUN_0001c128;
  psVar5 = (short *)(param_1 + 0x9f6c);
  lVar3 = 5;
  do {
    lVar2 = lVar3;
    if ((*psVar5 != 0) && (sVar1 = *psVar5 + -1, *psVar5 = sVar1, sVar1 == 0)) {
      (*(code *)*ppuVar4)(param_1);
    }
    psVar5 = psVar5 + 1;
    ppuVar4 = ppuVar4 + 1;
    lVar3 = lVar2 + -1;
  } while (lVar3 != 0);
  StorPortQuerySystemTime(param_1 + 0x9de0);
  if ((*(uint *)(param_1 + 0x9398) & 0x2401107) == 0) {
    StorPortNotification((int)lVar2 + 5,param_1,TimerTick,1000000);
  }
  return;
}



===== SetTransportMethod @ 0001a200 =====

void SetTransportMethod(longlong param_1)

{
  short sVar1;
  undefined1 *puVar2;
  
  (**(code **)(param_1 + 0x180))();
  if (((*(byte *)(param_1 + 0x9e00) & 4) == 0) || ((*(byte *)(param_1 + 0x9f64) & 0xf) != 4)) {
    *(ushort *)(param_1 + 0x9f64) = *(ushort *)(param_1 + 0x9f64) & 0xfff2 | 2;
    if (*(short *)(param_1 + 0x92f8) == -0x4e88) {
      *(undefined1 **)(param_1 + 0x138) = &V100_PerformantModeEnableInterrupts;
      *(undefined1 **)(param_1 + 0x140) = &V100_PerformantModeDisableInterrupts;
      puVar2 = &V100_PerformantModeInterruptActive;
    }
    else {
      *(undefined1 **)(param_1 + 0x138) = &Default_SimpleModeEnableInterrupts;
      *(undefined1 **)(param_1 + 0x140) = &Default_SimpleModeDisableInterrupts;
      puVar2 = &Default_SimpleModeInterruptActive;
    }
    *(undefined1 **)(param_1 + 0x148) = puVar2;
    *(code **)(param_1 + 0x130) = SimpleModeInitialize;
    *(undefined1 **)(param_1 + 0x158) = &SimpleModeSubmitRequest;
  }
  else {
    sVar1 = *(short *)(param_1 + 0x92f8);
    if (((sVar1 == 0x46) || (sVar1 == 0x3238)) || (sVar1 == -0x4fa0)) {
      *(undefined1 **)(param_1 + 0x138) = &V100_PerformantModeEnableInterrupts;
      *(undefined1 **)(param_1 + 0x140) = &V100_PerformantModeDisableInterrupts;
      puVar2 = &V100_PerformantModeInterruptActive;
    }
    else if (sVar1 == -0x4e88) {
      *(undefined1 **)(param_1 + 0x138) = &Default_SimpleModeEnableInterrupts;
      *(undefined1 **)(param_1 + 0x140) = &Default_SimpleModeDisableInterrupts;
      puVar2 = &Default_SimpleModeInterruptActive;
    }
    else {
      *(undefined1 **)(param_1 + 0x138) = &Default_PerformantModeEnableInterrupts;
      *(undefined1 **)(param_1 + 0x140) = &Default_PerformantModeDisableInterrupts;
      puVar2 = &Default_PerformantModeInterruptActive;
    }
    *(undefined1 **)(param_1 + 0x148) = puVar2;
    if (*(int *)(param_1 + 0x9e64) == 0) {
      *(undefined4 *)(param_1 + 0x9e64) = 0x4000;
    }
    if (*(int *)(param_1 + 0x9e68) == 0) {
      *(undefined4 *)(param_1 + 0x9e68) = 0x4000;
    }
    *(undefined1 **)(param_1 + 0x158) = &PerformantModeSubmitRequest;
    *(code **)(param_1 + 0x130) = PerformantModeInitialize;
  }
  return;
}



===== GetConfigTable @ 0001a3a8 =====

void GetConfigTable(longlong param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 200);
  puVar3 = (undefined4 *)(param_1 + 0x9df8);
  for (lVar1 = 0x17; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}



===== HbaFinishedPost @ 0001a3d8 =====

undefined4 HbaFinishedPost(longlong param_1)

{
  return CONCAT31((int3)((uint)**(int **)(param_1 + 0x90) >> 8),
                  **(int **)(param_1 + 0x90) == -0x10000);
}



===== SimpleModeInitialize @ 0001a404 =====

undefined8 SimpleModeInitialize(longlong param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 local_res8 [8];
  
  local_res8[0] = 0;
  *(undefined1 **)(param_1 + 0x150) = &SimpleModeGetCompletedRequest;
  **(undefined4 **)(param_1 + 0x70) = 2;
  LOCK();
  UNLOCK();
  uVar2 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0x93c0),local_res8);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  *(undefined4 *)(param_1 + 0x188) = uVar1;
  **(undefined4 **)(param_1 + 0x88) = uVar1;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x58) = 1;
  LOCK();
  UNLOCK();
  return CONCAT71((uint7)((ulonglong)uVar2 >> 0x28),1);
}



===== PerformantModeInitialize @ 0001a4f4 =====

undefined8 PerformantModeInitialize(longlong param_1)

{
  undefined4 extraout_var;
  undefined8 uVar1;
  undefined4 local_res8 [8];
  
  local_res8[0] = 0;
  *(undefined4 *)(param_1 + 0x9e08) = 4;
  if ((*(uint *)(param_1 + 0x9e00) & 0x20000000) != 0) {
    *(undefined4 *)(param_1 + 0x9e08) = 0x20000004;
  }
  StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0x93c0),local_res8);
  *(undefined4 *)(param_1 + 0x188) = extraout_var;
  *(undefined4 *)(param_1 + 0x9e0c) = extraout_var;
  **(undefined4 **)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x9e08);
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x9e0c);
  LOCK();
  UNLOCK();
  uVar1 = PerformantInitializeTransportMethod(param_1);
  **(undefined4 **)(param_1 + 0x58) = 1;
  LOCK();
  UNLOCK();
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== PerformantModeGetCompletedRequest @ 0001a658 =====

undefined8 PerformantModeGetCompletedRequest(longlong param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  ulonglong uVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x9f88);
  uVar5 = (ulonglong)param_2;
  iVar4 = *(int *)(lVar2 + 8 + uVar5 * 0x10);
  uVar1 = *(uint *)(lVar2 + 0xc + uVar5 * 0x10);
  uVar3 = *(undefined8 *)(*(longlong *)(lVar2 + uVar5 * 0x10) + (longlong)iVar4 * 8);
  if (((uint)uVar3 & 1) != uVar1) {
    return 0xffffffff;
  }
  iVar4 = iVar4 + 1;
  if (iVar4 == 0x200) {
    iVar4 = 0;
    *(uint *)(lVar2 + 0xc + uVar5 * 0x10) = uVar1 ^ 1;
  }
  *(int *)(*(longlong *)(param_1 + 0x9f88) + 8 + uVar5 * 0x10) = iVar4;
  return uVar3;
}



===== PerformantInitializeTransportMethod @ 0001a6b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PerformantInitializeTransportMethod(longlong param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 extraout_var;
  longlong lVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  ulonglong uVar7;
  undefined1 local_98 [32];
  undefined4 local_78;
  undefined4 uStack_74;
  uint local_70 [12];
  undefined4 auStack_40 [2];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_98;
  *(code **)(param_1 + 0x150) = PerformantModeGetCompletedRequest;
  local_78 = 0;
  memset(local_70,0,0x38);
  uVar2 = local_78;
  local_70[0] = 5;
  if (*(int *)(param_1 + 0x9e50) == 0x44) {
    local_70[1] = 6;
    local_70[2] = 7;
    local_70[3] = 8;
    local_70[4] = 0xc;
    local_70[5] = 0x14;
    local_70[6] = 0x24;
    local_70[7] = 0x44;
  }
  else {
    local_70[1] = 7;
    local_70[2] = 9;
    local_70[3] = 0xd;
    local_70[4] = 0xf;
    local_70[5] = 0x13;
    local_70[6] = 0x15;
    local_70[7] = 0x24;
  }
  if (*(ushort *)(param_1 + 0x9f6a) == 0) {
    local_70[9] = 1;
  }
  else {
    local_70[9] = (uint)*(ushort *)(param_1 + 0x9f6a);
  }
  local_70[8] = 0x200;
  uVar4 = 0;
  if (local_70[9] != 0) {
    uVar1 = CONCAT44(uStack_74,local_78);
    do {
      uVar7 = (ulonglong)uVar4;
      *(undefined4 *)(*(longlong *)(param_1 + 0x9f88) + 0xc + uVar7 * 0x10) = 1;
      *(undefined4 *)(*(longlong *)(param_1 + 0x9f88) + 8 + uVar7 * 0x10) = 0;
      if (uVar4 == 0) {
        auStack_40[0] =
             StorPortGetPhysicalAddress(param_1,0,**(undefined8 **)(param_1 + 0x9f88),&local_78);
        StorPortGetPhysicalAddress(param_1,0,**(undefined8 **)(param_1 + 0x9f88),&local_78);
        auStack_40[1] = extraout_var;
      }
      else {
        lVar3 = *(longlong *)(param_1 + 0x9f88);
        auStack_40[(ulonglong)uVar4 * 2] = uVar2;
        auStack_40[(ulonglong)uVar4 * 2 + 1] = uStack_74;
        *(undefined8 *)(lVar3 + uVar7 * 0x10) = uVar1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < local_70[9]);
  }
  puVar5 = local_70;
  puVar6 = (uint *)((ulonglong)*(uint *)(param_1 + 0x9e20) + *(longlong *)(param_1 + 200));
  for (lVar3 = 0xe; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== ScsiPortWmiPostProcess @ 0001a9bc =====

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
  uVar2 = *(uint *)(param_1 + 8);
  puVar4 = *(uint **)(param_1 + 0x10);
  uVar9 = 0;
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
        goto LAB_0001aa7e;
      }
      param_2 = '\x12';
    }
LAB_0001aa5b:
    if ((param_2 != '\x12') || (uVar2 < 0x38)) goto LAB_0001aa7e;
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
        goto LAB_0001aa7e;
      }
      goto LAB_0001aa5b;
    }
    if (cVar1 != '\t') goto LAB_0001aa7e;
    uVar7 = puVar4[0xf] + param_3;
    if (param_2 == '\x01') {
      if (0x47 < uVar2) {
        *puVar4 = uVar7;
        puVar4[0x10] = param_3;
        uVar9 = uVar7;
      }
      goto LAB_0001aa7e;
    }
    if ((param_2 != '\x12') || (uVar2 < 0x38)) goto LAB_0001aa7e;
    puVar4[0xc] = uVar7;
  }
  *puVar4 = 0x38;
  puVar4[0xb] = 0x20;
  param_2 = '\x01';
  uVar9 = 0x38;
LAB_0001aa7e:
  *(uint *)(param_1 + 0x1c) = uVar9;
  *(char *)(param_1 + 0x19) = param_2;
  return;
}



===== ScsiWmipProcessRequest @ 0001ab10 =====

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
          goto LAB_0001abe0;
          break;
        }
        uVar16 = (int)uVar19 + 1;
        uVar19 = (ulonglong)uVar16;
        plVar9 = plVar9 + 2;
      } while (uVar16 < *param_1);
    }
    *param_8 = 0;
    cVar5 = '\x04';
    goto LAB_0001af12;
  }
LAB_0001abe0:
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
          goto LAB_0001ad2d;
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
LAB_0001ad2d:
          cVar5 = (**(code **)(param_1 + 6))
                            (param_3,param_4,uVar19,uVar6,uVar16,puVar14,iVar12,lVar13);
          return cVar5;
        }
        if (param_2 == 2) {
          if (*(code **)(param_1 + 8) != _guard_dispatch_icall) {
            cVar5 = (**(code **)(param_1 + 8))
                              (param_3,param_4,uVar19,uVar6,param_7[0xf],
                               (ulonglong)param_7[0xe] + (longlong)param_7);
            return cVar5;
          }
        }
        else if (param_2 == 3) {
          if (*(code **)(param_1 + 10) != _guard_dispatch_icall) {
            cVar5 = (**(code **)(param_1 + 10))
                              (param_3,param_4,uVar19,uVar6,param_7[0xe],param_7[0x10],
                               (ulonglong)param_7[0xf] + (longlong)param_7);
            return cVar5;
          }
        }
        else if (param_2 == 4) {
          pcVar7 = *(code **)(param_1 + 0xe);
          if (pcVar7 != _guard_dispatch_icall) {
            uVar18 = 0;
            goto LAB_0001af35;
          }
          goto LAB_0001af46;
        }
      }
LAB_0001ac55:
      cVar5 = '\x04';
      goto LAB_0001af49;
    }
    pcVar7 = *(code **)(param_1 + 0xe);
    if (pcVar7 != _guard_dispatch_icall) {
      uVar20 = 0;
      uVar18 = 0;
      goto LAB_0001af3a;
    }
  }
  else if (param_2 == 6) {
    pcVar7 = *(code **)(param_1 + 0xe);
    if (pcVar7 != _guard_dispatch_icall) {
      uVar18 = 1;
LAB_0001af35:
      uVar20 = 1;
LAB_0001af3a:
      cVar5 = (*pcVar7)(param_3,param_4,uVar19,uVar18,uVar20);
      return cVar5;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (((param_2 == 9) && (*(code **)(param_1 + 0xc) != _guard_dispatch_icall)) &&
           (0x47 < param_6)) {
          uVar16 = param_7[0xf];
          if (uVar16 <= param_6) {
            cVar5 = (**(code **)(param_1 + 0xc))
                              (param_3,param_4,uVar19,uVar6,param_7[0xe],param_7[0x10],
                               param_6 - uVar16,(longlong)param_7 + (ulonglong)uVar16);
            return cVar5;
          }
        }
        goto LAB_0001ac55;
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
          goto LAB_0001af03;
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
LAB_0001af03:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_0001af12:
      psVar4[0] = 1;
      psVar4[1] = 0;
      return cVar5;
    }
    pcVar7 = *(code **)(param_1 + 0xe);
    if (pcVar7 != _guard_dispatch_icall) {
      uVar20 = 0;
      uVar18 = 1;
      goto LAB_0001af3a;
    }
  }
LAB_0001af46:
  cVar5 = '\x01';
LAB_0001af49:
  psVar4[0] = 1;
  psVar4[1] = 0;
  return cVar5;
}



===== entry @ 0001af74 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_check_cookie @ 0001afb0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  if ((_StackCookie == __security_cookie) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __report_rangecheckfailure @ 0001afe4 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 0001aff8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 0001b01c =====

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



===== _guard_check_icall @ 0001b088 =====

void _guard_check_icall(void)

{
  return;
}



===== memcpy @ 0001b100 =====

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
        if (uVar12 == 0) goto LAB_0001b2b7;
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
LAB_0001b2b7:
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
      if (uVar12 == 0) goto LAB_0001b112;
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
LAB_0001b112:
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



===== memset @ 0001b440 =====

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
      if (uVar5 == 0) goto LAB_0001b500;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_0001b4fd_caseD_2;
      case 3:
        goto switchD_0001b4fd_caseD_3;
      case 4:
        goto switchD_0001b4fd_caseD_4;
      case 5:
        goto switchD_0001b4fd_caseD_5;
      case 6:
        goto switchD_0001b4fd_caseD_6;
      case 7:
        goto switchD_0001b4fd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_0001b500:
        *puVar3 = uVar4;
switchD_0001b4fd_caseD_7:
        puVar3[1] = uVar4;
switchD_0001b4fd_caseD_6:
        puVar3[2] = uVar4;
switchD_0001b4fd_caseD_5:
        puVar3[3] = uVar4;
switchD_0001b4fd_caseD_4:
        puVar3[4] = uVar4;
switchD_0001b4fd_caseD_3:
        puVar3[5] = uVar4;
switchD_0001b4fd_caseD_2:
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



===== __security_init_cookie @ 0001f008 =====

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


