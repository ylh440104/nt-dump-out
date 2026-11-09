
===== RxCheckAdapterHealth @ 1c0001000 =====

uint RxCheckAdapterHealth(longlong param_1,uint *param_2)

{
  uint uVar1;
  
  *param_2 = 0;
  uVar1 = RxGetOMRx0(param_1);
  if ((char)uVar1 < '\0') {
    StorPortDebugPrint(0,"OMR value in Check Adapter Health: 0x%x\n",uVar1);
  }
  else if ((uVar1 >> 8 & 1) != 0) {
    *param_2 = uVar1 >> 0x10 & 0xff;
  }
  return uVar1;
}



===== RxCheckSyncCommandComplete @ 1c0001050 =====

undefined8 RxCheckSyncCommandComplete(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  ushort uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  uVar4 = 0;
  lVar1 = *(longlong *)(param_1 + 0x1a8);
  if (*(char *)(param_1 + 0xaad6) == '\0') {
    uVar2 = *(short *)(param_1 + 0x158e) - 0x28b;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 < 3) {
      uVar4 = *(uint *)(lVar1 + 0x9c) >> 0xc;
    }
    else {
      uVar4 = *(uint *)(lVar1 + 0x2c);
    }
    uVar4 = uVar4 & 1;
  }
  else {
    uVar3 = (ulonglong)*(uint *)(lVar1 + 200);
    if ((*(uint *)(lVar1 + 200) >> 0xc & 1) != 0) {
      *(undefined4 *)(param_1 + 0xaad8) = 1;
    }
  }
  if ((uVar4 != 0) || (*(int *)(param_1 + 0xaad8) != 0)) {
    *param_2 = **(undefined4 **)(param_1 + 0x1c0);
    if (*(char *)(param_1 + 0xaad6) == '\0') {
      RxWriteODR(param_1,1,'\x01');
    }
    else if (*(int *)(param_1 + 0xaad8) != 0) {
      RxAccessDeviceRegister(param_1,7);
      *(undefined4 *)(param_1 + 0xaad8) = 0;
    }
    uVar3 = 0x286;
    if (*(short *)(param_1 + 0x158e) == 0x286) {
      *(undefined4 *)(lVar1 + 0x4ec) = 0x10000;
      LOCK();
      UNLOCK();
      *(undefined4 *)(lVar1 + 0x4ec) = 0x1000000;
      LOCK();
      UNLOCK();
    }
    if (*(char *)(param_1 + 0xaad6) == '\0') {
      uVar3 = (ulonglong)*(uint *)(param_1 + 0x814c);
      *(uint *)(lVar1 + 0x34) = *(uint *)(param_1 + 0x814c);
      LOCK();
      UNLOCK();
    }
    uVar5 = 1;
  }
  return CONCAT71((int7)(uVar3 >> 8),uVar5);
}



===== _guard_check_icall @ 1c0001160 =====

void _guard_check_icall(void)

{
  return;
}



===== RxInterruptHandler @ 1c0001170 =====

byte RxInterruptHandler(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  
  lVar1 = *(longlong *)(param_1 + 0x1a8);
  if (*(char *)(param_1 + 0x8084) == '\0') {
    if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
      bVar2 = *(byte *)(lVar1 + 0x30) & 7;
    }
    else {
      bVar2 = ~*(byte *)(lVar1 + 0x34) & *(byte *)(lVar1 + 0x30);
    }
    if (bVar2 == 0) {
      return 0;
    }
    if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
      uVar3 = *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x9c) >> 0xc;
    }
    else {
      uVar3 = *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x2c);
    }
    if ((uVar3 & 4) != 0) {
      RxWriteODR(param_1,4,'\x01');
      ServiceHostResponseNormalQueue(param_1);
      return bVar2;
    }
    if ((uVar3 & 2) != 0) {
      uVar7 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
      uVar5 = 2;
      RxWriteODR(param_1,2,'\x01');
      ServiceHostCommandNormalQueue(param_1,uVar5,uVar7,param_4);
      return bVar2;
    }
    if ((uVar3 & 0x20) == 0) {
      iVar4 = 8;
      if (((uVar3 & 8) == 0) && (iVar4 = 0x10, (uVar3 & 0x10) == 0)) {
        if ((uVar3 & 1) == 0) {
          return bVar2;
        }
        iVar4 = 1;
      }
      RxWriteODR(param_1,iVar4,'\x01');
      return bVar2;
    }
    uVar6 = *(undefined4 *)(*(longlong *)(param_1 + 0x1c0) + 0x14);
    QueuePrintf(param_1,(ushort)uVar6,(short)((uint)uVar6 >> 0x10));
    RxWriteODR(param_1,0x20,'\x01');
    uVar6 = 0x20;
    if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
      uVar6 = 0x4000;
    }
    *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x20) = uVar6;
  }
  else {
    bVar2 = RxNewCommProcessInterrupt(param_1,*(longlong *)(param_1 + 0x1c0),param_3,param_4);
    if (*(int *)(param_1 + 0x8154) == 0) {
      return bVar2;
    }
    if (*(short *)(param_1 + 0x158e) != 0x286) {
      return bVar2;
    }
    *(undefined4 *)(param_1 + 0x8154) = 0;
    *(undefined4 *)(lVar1 + 0x4ec) = 0x1000000;
  }
  LOCK();
  UNLOCK();
  return bVar2;
}



===== NonMSIXInterruptHandler @ 1c0001314 =====

undefined1 NonMSIXInterruptHandler(ulonglong param_1,int param_2,char *param_3,ulonglong param_4)

{
  char *pcVar1;
  uint *puVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  ushort uVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar10;
  uint7 uVar11;
  ulonglong uVar12;
  undefined4 local_res10 [2];
  
  uVar10 = *(uint *)(param_1 + 0x648);
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  if (param_2 == 1) {
    while( true ) {
      uVar12 = (ulonglong)uVar10;
      uVar11 = (uint7)((ulonglong)param_3 >> 8);
      param_3 = (char *)((ulonglong)uVar11 << 8);
      uVar8 = *(uint *)(*(longlong *)(param_1 + 0x640) + uVar12 * 4);
      if ((uVar8 & 0x7fffffff) >> 0x1e == 0) {
        bVar3 = false;
        if ((uVar8 & 0x800000) != 0) {
          bVar3 = true;
        }
      }
      else {
        param_3 = (char *)CONCAT71(uVar11,1);
        bVar3 = false;
      }
      uVar8 = uVar8 & 0xffff;
      if (uVar8 == 0) goto LAB_1c0001556;
      if (0x400 < uVar8) break;
      pcVar1 = *(char **)(param_1 + 0x6050 + (ulonglong)(uVar8 - 1) * 8);
      *(undefined8 *)(param_1 + 0x6050 + (ulonglong)(uVar8 - 1) * 8) = 0;
      if (bVar3) {
        puVar2 = *(uint **)(param_1 + 0x198);
        bVar4 = false;
        if (puVar2 != (uint *)0x0) {
          if ((*puVar2 & 0x200000) == 0) {
            uVar9 = ProcessAif(param_1,puVar2,param_3,param_4);
            bVar5 = bVar6;
            if ((char)uVar9 != '\0') {
              bVar5 = true;
              bVar6 = true;
            }
          }
          else {
            bVar4 = true;
          }
          *(undefined8 *)(param_1 + 0x198) = 0;
        }
      }
      else if (pcVar1 == (char *)0x0) {
        param_3 = "pFibContext=NULL !!\n";
        ArcPrintf(param_1,4,(byte *)"pFibContext=NULL !!\n",param_4);
      }
      else {
        if ((char)param_3 != '\0') {
          *(undefined4 *)(*(longlong *)(pcVar1 + 0x28) + 0x20) = 20000;
          **(uint **)(pcVar1 + 0x28) = **(uint **)(pcVar1 + 0x28) | 0x200;
        }
        param_4 = 0;
        pcVar1[0x78] = '\n';
        pcVar1[0x79] = '\0';
        pcVar1[0x7a] = '\0';
        pcVar1[0x7b] = '\0';
        param_3 = (char *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
        ProcessNormalFib(param_1,pcVar1,'\x01',(undefined2 *)0x0,(ushort *)0x0);
        uVar7 = GetOutstandingIoCnt(param_1);
        if (((*(char *)(param_1 + 0xa925) != '\0') ||
            ((*(char *)(param_1 + 0xa924) != '\0' &&
             (((*(int *)(param_1 + 0xa910) != 0 || (*(int *)(param_1 + 0xa914) != 0)) &&
              ((uint)uVar7 <= *(uint *)(param_1 + 0xa90c))))))) &&
           ((*(char *)(param_1 + 0xa970) == '\0' && (*(char *)(param_1 + 0xa9c1) != '\0')))) {
          local_res10[0] = 0;
          param_3 = (char *)(param_1 + 0xa928);
          param_4 = param_1;
          StorPortNotification(0x1002,param_1,param_3,param_1,param_1,local_res10);
          *(undefined1 *)(param_1 + 0xa970) = 1;
        }
      }
      uVar10 = uVar10 + 1;
      *(undefined4 *)(*(longlong *)(param_1 + 0x640) + uVar12 * 4) = 0;
      if (uVar10 == *(uint *)(param_1 + 0x8078)) {
        uVar10 = 0;
      }
      *(uint *)(param_1 + 0x648) = uVar10;
      if ((bVar3) && (!bVar4)) {
        param_3 = (char *)0x2710;
        param_4 = 2;
        RequestTimer(param_1,0x80,10000,2);
      }
    }
    param_4 = 0x400;
    ArcPrintf(param_1,4,(byte *)"This should not happen. We only have %d free slots\n",0x400);
  }
  else {
    if (param_2 != 0x12) {
      return 0;
    }
    param_4 = 2;
    RequestTimer(param_1,0x80,10000,2);
  }
LAB_1c0001556:
  if (bVar5) {
    if (*(char *)(param_1 + 0xe2e4) == '\0') {
      *(undefined4 *)(param_1 + 0x6044) = 0;
      *(undefined1 *)(param_1 + 0x6048) = 1;
      ArcPrintf(param_1,4,
                (byte *)
                "* Start a timer to update container device info in NonMSIXInterruptHandler\n",
                param_4);
      RequestTimer(param_1,8,500000,2);
    }
    else {
      *(undefined1 *)(param_1 + 0xe2e5) = 1;
    }
  }
  return 1;
}



===== GetOutstandingIoCnt @ 1c00015e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

short GetOutstandingIoCnt(longlong param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = 0;
  if (*(char *)(param_1 + 0xaad6) == '\0') {
    sVar1 = *(short *)(param_1 + 0xba20) - *(short *)(param_1 + 0xba22);
  }
  else {
    uVar2 = 0;
    do {
      sVar1 = sVar1 + (*(short *)(param_1 + 0xb988 + (ulonglong)uVar2 * 2) -
                      *(short *)(param_1 + 0xb9c8 + (ulonglong)uVar2 * 2));
      if (*(ushort *)(param_1 + 0xaad4) <= uVar2) {
        return sVar1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x20);
  }
  return sVar1;
}



===== PMCDpcResponseHandler @ 1c0001660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PMCDpcResponseHandler(undefined8 param_1,longlong param_2,undefined8 param_3,uint *param_4)

{
  short *psVar1;
  char *pcVar2;
  uint *puVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  ushort uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined1 uVar11;
  byte *pbVar12;
  ulonglong uVar13;
  byte bVar14;
  uint uVar15;
  ulonglong uVar16;
  byte bVar17;
  int *piVar18;
  bool bVar19;
  undefined1 auStackY_1f8 [32];
  byte local_1c8;
  byte local_1c6;
  uint local_1c4;
  byte local_1c0;
  ushort local_1bc [2];
  short local_1b8 [4];
  uint local_1b0;
  int local_1ac;
  uint local_1a8;
  ulonglong local_1a0;
  uint local_198;
  undefined4 local_190 [2];
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  byte local_168 [144];
  byte local_d8 [144];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1f8;
  local_188 = 0;
  local_180 = 0;
  local_178 = 0;
  local_1a8 = local_1a8 & 0xffffff00;
  local_198 = *(uint *)(param_2 + 0x8074) / (uint)*(ushort *)(param_2 + 0xaad4);
  bVar19 = false;
  local_190[0] = 0;
  local_d8[0] = 0;
  memset(local_d8 + 1,0,0x81);
  local_1c0 = 0;
  local_168[0] = 0;
  bVar17 = 0;
  memset(local_168 + 1,0,0x81);
  local_1b0 = *param_4;
  uVar10 = (ulonglong)local_1b0;
  local_1c8 = 0;
  local_1a0 = (ulonglong)local_1b0;
  local_1c6 = 0;
  *(undefined1 *)(uVar10 + 0xb968 + param_2) = 3;
  if (*(char *)(param_2 + 0xaad6) != '\0') {
    local_1ac = *(int *)(param_2 + 0xaf68 + uVar10 * 4);
    local_1c4 = *(uint *)(param_2 + 0xaee8 + uVar10 * 4);
    local_1a0 = uVar10;
    if (local_1b0 != 0) {
      uVar10 = (ulonglong)local_1b0;
LAB_1c0001763:
      bVar7 = bVar19;
LAB_1c0001765:
      do {
        bVar19 = bVar7;
        bVar5 = false;
        bVar6 = false;
        uVar16 = (ulonglong)local_1c4;
        uVar15 = *(uint *)(*(longlong *)(param_2 + 0x640) + uVar16 * 4);
        if ((uVar15 & 0x7fffffff) >> 0x1e == 0) {
          bVar5 = false;
          if ((uVar15 & 0x800000) != 0) {
            bVar5 = true;
          }
        }
        else {
          bVar6 = true;
        }
        uVar15 = uVar15 & 0xffff;
        if (uVar15 == 0) {
LAB_1c00019e0:
          bVar19 = *(char *)(param_2 + 0x617) == '\0';
          if (bVar19) {
            uVar16 = 0;
            StorPortNotification(0x1003);
          }
          uVar8 = GetOutstandingIoCnt(param_2);
          uVar10 = (ulonglong)local_1c8;
          if (local_1c8 != 0) {
            pbVar12 = local_168;
            do {
              bVar14 = *pbVar12;
              pbVar12 = pbVar12 + 1;
              psVar1 = (short *)(param_2 + 0xd8dc + (ulonglong)bVar14 * 2);
              *psVar1 = *psVar1 + 1;
              *(short *)(param_2 + 0xba22) = *(short *)(param_2 + 0xba22) + 1;
              uVar10 = uVar10 - 1;
            } while (uVar10 != 0);
          }
          if (local_1c6 != 0) {
            *(short *)(param_2 + 0xba22) = *(short *)(param_2 + 0xba22) + (ushort)local_1c6;
          }
          if (bVar17 != 0) {
            pbVar12 = local_d8;
            uVar10 = (ulonglong)bVar17;
            do {
              bVar17 = *pbVar12;
              pbVar12 = pbVar12 + 1;
              *(undefined4 *)(param_2 + 0xdeac + (ulonglong)bVar17 * 4) = 0;
              uVar10 = uVar10 - 1;
            } while (uVar10 != 0);
          }
          if (((*(char *)(param_2 + 0x805c) != '\0') && ((uint)uVar8 <= *(uint *)(param_2 + 0xba10))
              ) && (*(char *)(param_2 + 0xaad6) != '\0')) {
            uVar15 = 0;
            piVar18 = (int *)(param_2 + 0x19cc);
            do {
              if (*piVar18 == 1) {
                uVar16 = 0;
                StorPortResumeDevice(param_2);
              }
              uVar15 = uVar15 + 1;
              piVar18 = piVar18 + 10;
            } while (uVar15 < 0xfe);
            piVar18 = (int *)(param_2 + 0x417c);
            uVar15 = 0;
            do {
              if (*piVar18 == 1) {
                uVar16 = 0;
                StorPortResumeDevice(param_2);
              }
              uVar15 = uVar15 + 1;
              piVar18 = piVar18 + 4;
            } while (uVar15 < 0xfe);
            goto LAB_1c0001faf;
          }
          goto LAB_1c0001fb9;
        }
        if (0x400 < uVar15) {
          uVar16 = 0x400;
          ArcPrintf(param_2,4,(byte *)"This should not happen. We only have %d free slots\n",0x400);
          goto LAB_1c00019e0;
        }
        pcVar2 = *(char **)(param_2 + 0x6050 + (ulonglong)(uVar15 - 1) * 8);
        if (pcVar2 != (char *)0x0) {
          uVar8 = *(ushort *)(param_2 + 0xb9c8 + (uVar10 & 0xffffffff) * 2);
          if (uVar8 == 0xffffffff) {
            *(undefined2 *)(param_2 + 0xb9c8 + (uVar10 & 0xffffffff) * 2) = 0;
          }
          else {
            *(ushort *)(param_2 + 0xb9c8 + local_1a0 * 2) = uVar8 + 1;
            uVar10 = local_1a0;
          }
        }
        uVar16 = (ulonglong)local_1c4;
        *(undefined8 *)(param_2 + 0x6050 + (ulonglong)(uVar15 - 1) * 8) = 0;
        local_1c4 = local_1c4 + 1;
        *(undefined4 *)(*(longlong *)(param_2 + 0x640) + uVar16 * 4) = 0;
        if (local_1c4 == local_1ac + 1U) {
          local_1c4 = (int)uVar10 * local_198;
        }
        *(uint *)(param_2 + 0xaee8 + (uVar10 & 0xffffffff) * 4) = local_1c4;
        if (!bVar5) {
          bVar7 = bVar19;
          if (pcVar2 == (char *)0x0) {
            ArcPrintf(param_2,4,(byte *)"pFibContext=NULL !!line %d messageid %d handle %d\n",0x2c9)
            ;
            goto LAB_1c0001990;
          }
          pcVar2[0x78] = '\n';
          pcVar2[0x79] = '\0';
          pcVar2[0x7a] = '\0';
          pcVar2[0x7b] = '\0';
          if (bVar6) {
            *(undefined4 *)(*(longlong *)(pcVar2 + 0x28) + 0x20) = 20000;
            **(uint **)(pcVar2 + 0x28) = **(uint **)(pcVar2 + 0x28) | 0x200;
          }
          local_1b8[0] = -1;
          local_1bc[0] = 0xffff;
          ProcessNormalFib(param_2,pcVar2,'\0',local_1b8,local_1bc);
          if (local_1b8[0] == -1) {
            bVar14 = local_1c6 + 1;
            local_1c6 = bVar14;
          }
          else {
            local_168[local_1c8] = (byte)local_1b8[0];
            bVar14 = local_1c8 + 1;
            local_1c8 = bVar14;
          }
          if (0x82 < bVar14) {
            ArcPrintf(param_2,4,
                      (byte *)
                      "This should not happen. We only support %d requests per MSIx vector\n",0x82);
          }
          if (local_1bc[0] != 0xffff) goto code_r0x0001c000193a;
          goto LAB_1c0001763;
        }
        puVar3 = *(uint **)(param_2 + 0x198);
        bVar19 = false;
        bVar7 = false;
        if (puVar3 != (uint *)0x0) {
          if ((*puVar3 >> 0x15 & 1) == 0) {
            uVar9 = ProcessAif(param_2,puVar3,(ulonglong)uVar15,uVar16);
            local_1a8 = local_1a8 & 0xff;
            bVar19 = false;
            if ((char)uVar9 != '\0') {
              local_1a8 = 1;
            }
          }
          else {
            bVar19 = true;
            bVar7 = true;
          }
          *(undefined8 *)(param_2 + 0x198) = 0;
        }
LAB_1c0001990:
      } while ((!bVar5) || (bVar19));
      RequestTimer(param_2,0x80,10000,0);
      bVar19 = bVar7;
      goto LAB_1c0001763;
    }
    bVar7 = false;
    uVar15 = *(uint *)(*(longlong *)(param_2 + 0x1a8) + 200);
    if ((uVar15 >> 0x12 & 1) == 0) {
      if ((uVar15 >> 0xc & 1) != 0) {
        *(undefined4 *)(param_2 + 0xaad8) = 1;
        return;
      }
    }
    else {
      bVar7 = true;
    }
    uVar10 = 0;
    uVar16 = 0;
    while( true ) {
      bVar6 = false;
      bVar5 = false;
      uVar13 = (ulonglong)local_1c4;
      uVar15 = *(uint *)(*(longlong *)(param_2 + 0x640) + uVar13 * 4);
      if ((uVar15 & 0x7fffffff) >> 0x1e == 0) {
        bVar5 = false;
        if ((uVar15 & 0x800000) != 0) {
          bVar5 = true;
        }
      }
      else {
        bVar6 = true;
      }
      uVar15 = uVar15 & 0xffff;
      if (uVar15 == 0) goto LAB_1c0001e69;
      if (0x400 < uVar15) break;
      local_1c4 = local_1c4 + 1;
      pcVar2 = *(char **)(param_2 + 0x6050 + (ulonglong)(uVar15 - 1) * 8);
      *(undefined8 *)(param_2 + 0x6050 + (ulonglong)(uVar15 - 1) * 8) = 0;
      *(undefined4 *)(*(longlong *)(param_2 + 0x640) + uVar13 * 4) = 0;
      if (local_1c4 == local_1ac + 1U) {
        local_1c4 = (int)uVar10 * local_198;
      }
      *(uint *)(param_2 + 0xaee8 + uVar16 * 4) = local_1c4;
      if (bVar5) {
        puVar3 = *(uint **)(param_2 + 0x198);
        bVar19 = false;
        bVar6 = false;
        if (puVar3 != (uint *)0x0) {
          if ((*puVar3 >> 0x15 & 1) == 0) {
            uVar9 = ProcessAif(param_2,puVar3,uVar10,uVar16);
            bVar6 = false;
            uVar11 = (char)local_1a8;
            if ((char)uVar9 != '\0') {
              uVar11 = 1;
            }
            local_1a8 = CONCAT31(local_1a8._1_3_,uVar11);
          }
          else {
            bVar6 = true;
            bVar19 = true;
          }
          *(undefined8 *)(param_2 + 0x198) = 0;
        }
LAB_1c0001dcf:
        uVar10 = (ulonglong)local_1b0;
        uVar16 = (ulonglong)local_1b0;
        if (bVar5) {
          if (!bVar6) {
            RequestTimer(param_2,0x80,10000,0);
          }
          uVar10 = (ulonglong)local_1b0;
          uVar16 = (ulonglong)local_1b0;
          if (bVar7) {
            RxAccessDeviceRegister(param_2,6);
LAB_1c0001e36:
            uVar10 = (ulonglong)local_1b0;
            uVar16 = local_1a0;
          }
        }
      }
      else {
        if (pcVar2 == (char *)0x0) {
          ArcPrintf(param_2,4,(byte *)"pFibContext=NULL !! line %d messageid %d\n",0x3cd);
          bVar6 = bVar19;
          goto LAB_1c0001dcf;
        }
        lVar4 = *(longlong *)(pcVar2 + 0x18);
        pcVar2[0x78] = '\n';
        pcVar2[0x79] = '\0';
        pcVar2[0x7a] = '\0';
        pcVar2[0x7b] = '\0';
        if (lVar4 == 0) {
          ArcPrintf(param_2,4,(byte *)"SHOULD NOT BE HERE !!\n",uVar16);
        }
        else {
          uVar8 = *(ushort *)(param_2 + 0xb9c8 + uVar16 * 2);
          if (uVar8 == 0xffffffff) {
            *(undefined2 *)(param_2 + 0xb9c8 + uVar16 * 2) = 0;
          }
          else {
            *(ushort *)(param_2 + 0xb9c8 + uVar16 * 2) = uVar8 + 1;
          }
          ArcPrintf(param_2,0x80,
                    (byte *)"Handle IOCTL CMD with vector 0. srb->function: 0x%x, cdb[0]: 0x%x\n",
                    (ulonglong)*(byte *)(lVar4 + 2));
        }
        if (bVar6) {
          *(undefined4 *)(*(longlong *)(pcVar2 + 0x28) + 0x20) = 20000;
          **(uint **)(pcVar2 + 0x28) = **(uint **)(pcVar2 + 0x28) | 0x200;
        }
        local_1b8[0] = -1;
        local_1bc[0] = 0xffff;
        ProcessNormalFib(param_2,pcVar2,'\0',local_1b8,local_1bc);
        if (local_1b8[0] == -1) {
          local_1c6 = local_1c6 + 1;
          if (0x82 < local_1c6) {
            ArcPrintf(param_2,4,
                      (byte *)
                      "This should not happen. We only support %d requests per MSIx vector\n",0x82);
          }
        }
        else {
          local_168[local_1c8] = (byte)local_1b8[0];
          local_1c8 = local_1c8 + 1;
          if (0x82 < local_1c8) {
            ArcPrintf(param_2,4,
                      (byte *)
                      "This should not happen. We only support %d requests per MSIx vector\n",0x82);
          }
        }
        uVar10 = (ulonglong)local_1b0;
        uVar16 = (ulonglong)local_1b0;
        if (local_1bc[0] != 0xffff) {
          uVar10 = (ulonglong)local_1b0;
          uVar16 = (ulonglong)local_1b0;
          local_d8[local_1c0] = (byte)local_1bc[0];
          local_1c0 = local_1c0 + 1;
          if (0x82 < local_1c0) {
            ArcPrintf(param_2,4,
                      (byte *)
                      "This should not happen. We only support %d requests per MSIx vector\n",0x82);
            goto LAB_1c0001e36;
          }
        }
      }
    }
    uVar16 = 0x400;
    ArcPrintf(param_2,4,(byte *)"This should not happen. We only have %d free slots\n",0x400);
LAB_1c0001e69:
    if (bVar7) {
      uVar16 = 0;
      RequestTimer(param_2,0x80,10000,0);
      RxAccessDeviceRegister(param_2,6);
    }
    bVar19 = *(char *)(param_2 + 0x617) == '\0';
    if (bVar19) {
      uVar16 = 0;
      StorPortNotification(0x1003);
    }
    uVar8 = GetOutstandingIoCnt(param_2);
    uVar10 = (ulonglong)local_1c8;
    if (local_1c8 != 0) {
      pbVar12 = local_168;
      do {
        bVar17 = *pbVar12;
        pbVar12 = pbVar12 + 1;
        psVar1 = (short *)(param_2 + 0xd8dc + (ulonglong)bVar17 * 2);
        *psVar1 = *psVar1 + 1;
        *(short *)(param_2 + 0xba22) = *(short *)(param_2 + 0xba22) + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    if (local_1c6 != 0) {
      *(short *)(param_2 + 0xba22) = *(short *)(param_2 + 0xba22) + (ushort)local_1c6;
    }
    if (local_1c0 != 0) {
      pbVar12 = local_d8;
      uVar10 = (ulonglong)local_1c0;
      do {
        bVar17 = *pbVar12;
        pbVar12 = pbVar12 + 1;
        *(undefined4 *)(param_2 + 0xdeac + (ulonglong)bVar17 * 4) = 0;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    if (((*(char *)(param_2 + 0x805c) != '\0') && ((uint)uVar8 <= *(uint *)(param_2 + 0xba10))) &&
       (*(char *)(param_2 + 0xaad6) != '\0')) {
      uVar15 = 0;
      piVar18 = (int *)(param_2 + 0x19cc);
      do {
        if (*piVar18 == 1) {
          uVar16 = 0;
          StorPortResumeDevice(param_2);
        }
        uVar15 = uVar15 + 1;
        piVar18 = piVar18 + 10;
      } while (uVar15 < 0xfe);
      piVar18 = (int *)(param_2 + 0x417c);
      uVar15 = 0;
      do {
        if (*piVar18 == 1) {
          uVar16 = 0;
          StorPortResumeDevice(param_2);
        }
        uVar15 = uVar15 + 1;
        piVar18 = piVar18 + 4;
      } while (uVar15 < 0xfe);
LAB_1c0001faf:
      *(undefined1 *)(param_2 + 0x805c) = 0;
    }
LAB_1c0001fb9:
    if (*(int *)(param_2 + 0xba14) != 0) {
      TryDeQueueIoList(param_2);
    }
    if ((*(char *)(param_2 + 0xa925) != '\0') ||
       ((*(char *)(param_2 + 0xa924) != '\0' &&
        (((*(int *)(param_2 + 0xa910) != 0 || (*(int *)(param_2 + 0xa914) != 0)) &&
         ((uint)uVar8 <= *(uint *)(param_2 + 0xa90c))))))) {
      DequeueRawIoReadWriteRequest(param_2,'\0',0);
    }
    if (((uVar8 < 2) && (*(int *)(param_2 + 55000) != 0)) &&
       (uVar10 = DeQueueSortingQueue(param_2,0xffff), (char)uVar10 == '\0')) {
      ArcPrintf(param_2,4,
                (byte *)"We may have problem, FW is idle, but we cannot dequeue sorting queue\n",
                uVar16);
    }
    if (bVar19) {
      StorPortNotification(0x1004,param_2,local_190);
    }
    if ((char)local_1a8 == '\x01') {
      if (*(char *)(param_2 + 0xe2e4) == '\0') {
        *(undefined4 *)(param_2 + 0x6044) = 0;
        *(undefined1 *)(param_2 + 0x6048) = 1;
        ArcPrintf(param_2,4,
                  (byte *)"* Start a timer to update Container info in PCMDpcResponseHandler\n",
                  uVar16);
        RequestTimer(param_2,8,500000,0);
      }
      else {
        *(undefined1 *)(param_2 + 0xe2e5) = 1;
      }
    }
  }
  *(undefined1 *)(local_1a0 + 0xb968 + param_2) = 4;
  return;
code_r0x0001c000193a:
  uVar16 = (ulonglong)bVar17;
  bVar17 = bVar17 + 1;
  local_d8[uVar16] = (byte)local_1bc[0];
  if (0x82 < bVar17) goto code_r0x0001c0001953;
  goto LAB_1c0001765;
code_r0x0001c0001953:
  ArcPrintf(param_2,4,
            (byte *)"This should not happen. We only support %d requests per MSIx vector\n",0x82);
  goto LAB_1c0001763;
}



===== PMCInterruptHandler @ 1c00020e0 =====

undefined1
PMCInterruptHandler(ulonglong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  char *pcVar1;
  uint *puVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  undefined7 uVar11;
  char *pcVar10;
  ulonglong uVar12;
  char cVar13;
  undefined4 uVar14;
  ushort *puVar15;
  undefined4 local_res8 [2];
  
  uVar9 = *(uint *)(param_1 + 0x648);
  puVar15 = (ushort *)0x0;
  bVar4 = false;
  bVar3 = false;
  uVar8 = 0;
  if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
    uVar6 = *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x9c);
  }
  else {
    uVar6 = *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x2c);
  }
  uVar12 = (ulonglong)(uVar6 >> 0xc);
  if (((uVar6 & 2) == 0) && ((uVar6 >> 0xc & 0x40) == 0)) {
    return 0;
  }
  pcVar10 = (char *)0x0;
  if ((uVar6 & 2) == 0) {
    uVar8 = param_1;
    RxWriteODR(param_1,uVar6,'\0');
    if ((uVar12 & 0x40) == 0) {
      return 0;
    }
    param_4 = 2;
    RequestTimer(uVar8,0x80,10000,2);
    uVar14 = 0;
  }
  else {
    RxWriteODR(param_1,2,'\0');
    while( true ) {
      cVar13 = (char)puVar15;
      uVar11 = (undefined7)((ulonglong)pcVar10 >> 8);
      pcVar10 = (char *)CONCAT71(uVar11,cVar13);
      uVar6 = *(uint *)(*(longlong *)(param_1 + 0x640) + (ulonglong)uVar9 * 4);
      if ((uVar6 & 0x7fffffff) >> 0x1e == 0) {
        if ((uVar6 & 0x800000) != 0) {
          cVar13 = '\x01';
        }
      }
      else {
        pcVar10 = (char *)CONCAT71(uVar11,1);
      }
      uVar6 = uVar6 & 0xffff;
      if (uVar6 == 0) goto LAB_1c0002370;
      if (0x400 < uVar6) break;
      pcVar1 = *(char **)(param_1 + 0x6050 + (ulonglong)(uVar6 - 1) * 8);
      *(ushort **)(param_1 + 0x6050 + (ulonglong)(uVar6 - 1) * 8) = puVar15;
      if (cVar13 == '\0') {
        if (pcVar1 == (char *)0x0) {
          pcVar10 = "pFibContext=NULL !!\n";
          ArcPrintf(param_1,4,(byte *)"pFibContext=NULL !!\n",param_4);
        }
        else {
          if ((char)pcVar10 != '\0') {
            *(undefined4 *)(*(longlong *)(pcVar1 + 0x28) + 0x20) = 20000;
            **(uint **)(pcVar1 + 0x28) = **(uint **)(pcVar1 + 0x28) | 0x200;
          }
          param_4 = 0;
          pcVar1[0x78] = '\n';
          pcVar1[0x79] = '\0';
          pcVar1[0x7a] = '\0';
          pcVar1[0x7b] = '\0';
          pcVar10 = (char *)CONCAT71((int7)((ulonglong)pcVar10 >> 8),1);
          ProcessNormalFib(param_1,pcVar1,'\x01',(undefined2 *)0x0,puVar15);
          uVar5 = GetOutstandingIoCnt(param_1);
          puVar15 = (ushort *)0x0;
          if (((*(char *)(param_1 + 0xa925) == '\0') &&
              ((*(char *)(param_1 + 0xa924) == '\0' ||
               (((*(int *)(param_1 + 0xa910) == 0 && (*(int *)(param_1 + 0xa914) == 0)) ||
                (*(uint *)(param_1 + 0xa90c) < (uint)uVar5)))))) ||
             ((*(char *)(param_1 + 0xa970) != '\0' || (*(char *)(param_1 + 0xa9c1) == '\0'))))
          goto LAB_1c0002305;
          local_res8[0] = 0;
          pcVar10 = (char *)(param_1 + 0xa928);
          param_4 = param_1;
          StorPortNotification(0x1002,param_1,pcVar10,param_1,param_1,local_res8);
          *(undefined1 *)(param_1 + 0xa970) = 1;
        }
        puVar15 = (ushort *)0x0;
      }
      else {
        puVar2 = *(uint **)(param_1 + 0x198);
        uVar8 = (ulonglong)puVar15 & 0xff;
        if (puVar2 != (uint *)0x0) {
          if ((*puVar2 & 0x200000) == 0) {
            uVar7 = ProcessAif(param_1,puVar2,pcVar10,param_4);
            puVar15 = (ushort *)0x0;
            bVar3 = bVar4;
            if ((char)uVar7 != '\0') {
              bVar3 = true;
              bVar4 = true;
            }
          }
          else {
            uVar8 = 1;
          }
          *(ushort **)(param_1 + 0x198) = puVar15;
        }
      }
LAB_1c0002305:
      uVar6 = uVar9 + 1;
      *(uint *)(*(longlong *)(param_1 + 0x640) + (ulonglong)uVar9 * 4) = (uint)puVar15;
      uVar9 = uVar6;
      if (uVar6 == *(uint *)(param_1 + 0x8074)) {
        uVar9 = (uint)puVar15;
      }
      *(uint *)(param_1 + 0x648) = uVar9;
      if ((cVar13 != '\0') && ((char)uVar8 == '\0')) {
        pcVar10 = (char *)0x2710;
        param_4 = 2;
        RequestTimer(param_1,0x80,10000,2);
        puVar15 = (ushort *)0x0;
      }
    }
    param_4 = 0x400;
    ArcPrintf(param_1,4,(byte *)"This should not happen. We only have %d free slots\n",0x400);
    puVar15 = (ushort *)0x0;
LAB_1c0002370:
    uVar14 = SUB84(puVar15,0);
  }
  if (bVar3) {
    if (*(char *)(param_1 + 0xe2e4) == (char)uVar14) {
      *(undefined4 *)(param_1 + 0x6044) = uVar14;
      *(undefined1 *)(param_1 + 0x6048) = 1;
      ArcPrintf(param_1,4,
                (byte *)"* Start a timer to update container device info in PMCInterruptHandler\n",
                param_4);
      RequestTimer(param_1,8,500000,2);
    }
    else {
      *(undefined1 *)(param_1 + 0xe2e5) = 1;
    }
  }
  return 1;
}



===== RxNotifyAdapter @ 1c0002410 =====

void RxNotifyAdapter(longlong param_1,undefined8 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 1) {
    uVar1 = 2;
    if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
      uVar1 = 0x400;
    }
    *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x20) = uVar1;
  }
  else {
    if (param_3 != 3) {
      return;
    }
    uVar1 = 4;
    if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
      uVar1 = 0x800;
    }
    *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x20) = uVar1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== RxNewCommProcessInterrupt @ 1c0002484 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
RxNewCommProcessInterrupt(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  longlong lVar2;
  char *pcVar3;
  bool bVar4;
  undefined1 uVar5;
  ushort uVar6;
  undefined8 uVar7;
  longlong lVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined8 uVar12;
  uint *puVar13;
  undefined1 local_278 [32];
  undefined1 local_238 [4];
  short local_234;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_278;
  lVar2 = *(longlong *)(param_1 + 0x1a8);
  uVar12 = 0x200;
  bVar4 = false;
  uVar5 = 1;
  memset(local_238,0,0x200);
  uVar9 = *(uint *)(lVar2 + 0x44);
  if (uVar9 == 0xffffffff) {
    uVar5 = 0;
  }
  else {
    if (*(char *)(param_1 + 0x80e3) == '\0') {
      do {
        if (uVar9 == 0xfffffffe) {
          *(undefined1 *)(param_1 + 0xa925) = 1;
        }
        else if ((uVar9 & 2) == 0) {
          pcVar3 = *(char **)(param_1 + 0x6050 + (ulonglong)(uVar9 >> 2) * 8);
          if (pcVar3 == (char *)0x0) {
            uVar5 = 0;
            break;
          }
          *(undefined8 *)(param_1 + 0x6050 + (ulonglong)(uVar9 >> 2) * 8) = 0;
          if ((uVar9 & 1) != 0) {
            *(undefined4 *)(*(longlong *)(pcVar3 + 0x28) + 0x20) = 20000;
            **(uint **)(pcVar3 + 0x28) = **(uint **)(pcVar3 + 0x28) | 0x200;
          }
          param_4 = 0;
          uVar12 = CONCAT71((int7)((ulonglong)uVar12 >> 8),1);
          ProcessNormalFib(param_1,pcVar3,'\x01',(undefined2 *)0x0,(ushort *)0x0);
        }
        else {
          puVar10 = (undefined1 *)((ulonglong)(uVar9 & 0xfffffffd) + *(longlong *)(param_1 + 0x1c8))
          ;
          puVar11 = local_238;
          for (lVar8 = 0x200; lVar8 != 0; lVar8 = lVar8 + -1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
          *(uint *)(lVar2 + 0x44) = uVar9 & 0xfffffffd;
          LOCK();
          UNLOCK();
          if ((local_234 == 700) &&
             (uVar7 = ProcessAif(param_1,local_238,uVar12,param_4), (char)uVar7 != '\0')) {
            bVar4 = true;
          }
        }
        uVar9 = *(uint *)(lVar2 + 0x44);
      } while (uVar9 != 0xffffffff);
    }
    else {
      puVar13 = *(uint **)(param_1 + 33000);
      do {
        if (*(uint *)(param_1 + 0x8108) < (uVar9 & 0xff)) {
          *(uint *)(param_1 + 0x8108) = uVar9 & 0xff;
        }
        while ((char)uVar9 != '\0') {
          uVar1 = *puVar13;
          while (uVar1 == 0xdeadbeef) {
            StorPortStallExecution(0);
            uVar1 = *puVar13;
          }
          *puVar13 = 0xdeadbeef;
          if (uVar1 == 0xfffffffe) {
            *(undefined1 *)(param_1 + 0xa925) = 1;
          }
          else if ((uVar1 & 2) == 0) {
            pcVar3 = *(char **)(param_1 + 0x6050 + (ulonglong)(uVar1 >> 2) * 8);
            if (pcVar3 == (char *)0x0) {
              uVar5 = 0;
              break;
            }
            *(undefined8 *)(param_1 + 0x6050 + (ulonglong)(uVar1 >> 2) * 8) = 0;
            if ((uVar1 & 1) != 0) {
              *(undefined4 *)(*(longlong *)(pcVar3 + 0x28) + 0x20) = 20000;
              **(uint **)(pcVar3 + 0x28) = **(uint **)(pcVar3 + 0x28) | 0x200;
            }
            param_4 = 0;
            uVar12 = CONCAT71((int7)((ulonglong)uVar12 >> 8),1);
            ProcessNormalFib(param_1,pcVar3,'\x01',(undefined2 *)0x0,(ushort *)0x0);
          }
          else {
            puVar10 = (undefined1 *)
                      ((ulonglong)(uVar1 & 0xfffffffd) + *(longlong *)(param_1 + 0x1c8));
            puVar11 = local_238;
            for (lVar8 = 0x200; lVar8 != 0; lVar8 = lVar8 + -1) {
              *puVar11 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar11 = puVar11 + 1;
            }
            *(uint *)(lVar2 + 0x44) = uVar1 & 0xfffffffd;
            LOCK();
            UNLOCK();
            if ((local_234 == 700) &&
               (uVar7 = ProcessAif(param_1,local_238,uVar12,param_4), (char)uVar7 != '\0')) {
              bVar4 = true;
            }
          }
          uVar9 = (uint)(byte)((char)uVar9 - 1);
          puVar13 = puVar13 + 1;
          if (puVar13 == *(uint **)(param_1 + 0x80f8)) {
            puVar13 = *(uint **)(param_1 + 0x80f0);
          }
        }
        *(uint **)(param_1 + 33000) = puVar13;
        uVar9 = *(uint *)(lVar2 + 0x44);
      } while (uVar9 != 0xffffffff);
    }
    uVar6 = GetOutstandingIoCnt(param_1);
    if (((*(char *)(param_1 + 0xa925) != '\0') ||
        ((*(char *)(param_1 + 0xa924) != '\0' &&
         (((*(int *)(param_1 + 0xa910) != 0 || (*(int *)(param_1 + 0xa914) != 0)) &&
          ((uint)uVar6 <= *(uint *)(param_1 + 0xa90c))))))) &&
       ((*(char *)(param_1 + 0xa970) == '\0' && (*(char *)(param_1 + 0xa9c1) != '\0')))) {
      StorPortNotification(0x1002,param_1,param_1 + 0xa928,param_1);
      *(undefined1 *)(param_1 + 0xa970) = 1;
    }
    if (bVar4) {
      if (*(char *)(param_1 + 0xe2e4) == '\0') {
        *(undefined4 *)(param_1 + 0x6044) = 0;
        *(undefined1 *)(param_1 + 0x6048) = 1;
        RequestTimer(param_1,8,500000,2);
      }
      else {
        *(undefined1 *)(param_1 + 0xe2e5) = 1;
      }
    }
  }
  return uVar5;
}



===== RxPullMessageUnitQueueCompletedFib @ 1c00027f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
RxPullMessageUnitQueueCompletedFib
          (longlong param_1,longlong *param_2,longlong *param_3,ulonglong param_4)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  undefined1 local_268 [32];
  undefined1 local_248 [4];
  short local_244;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_268;
  lVar1 = *(longlong *)(param_1 + 0x1a8);
  uVar8 = 0x200;
  bVar2 = false;
  uVar9 = 0;
  memset(local_248,0,0x200);
  uVar3 = *(uint *)(lVar1 + 0x44);
  if (uVar3 != 0xffffffff) {
    do {
      if (uVar3 == 0xfffffffe) {
        *(undefined1 *)(param_1 + 0xa925) = 1;
      }
      else {
        if ((uVar3 & 2) == 0) {
          lVar1 = *(longlong *)(param_1 + 0x6050 + (ulonglong)(uVar3 >> 2) * 8);
          *param_3 = lVar1;
          *param_2 = *(longlong *)(lVar1 + 0x28);
          *(undefined8 *)(param_1 + 0x6050 + (ulonglong)(uVar3 >> 2) * 8) = 0;
          if ((uVar3 & 1) != 0) {
            *(undefined4 *)(*param_2 + 0x20) = 20000;
            *(uint *)*param_2 = *(uint *)*param_2 | 0x200;
          }
          uVar9 = 1;
          break;
        }
        puVar6 = (undefined1 *)((ulonglong)(uVar3 & 0xfffffffd) + *(longlong *)(param_1 + 0x1c8));
        puVar7 = local_248;
        for (lVar5 = 0x200; lVar5 != 0; lVar5 = lVar5 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        *(uint *)(lVar1 + 0x44) = uVar3 & 0xfffffffd;
        LOCK();
        UNLOCK();
        if ((local_244 == 700) &&
           (uVar4 = ProcessAif(param_1,local_248,uVar8,param_4), (char)uVar4 != '\0')) {
          bVar2 = true;
        }
      }
      uVar3 = *(uint *)(lVar1 + 0x44);
    } while (uVar3 != 0xffffffff);
    if (bVar2) {
      if (*(char *)(param_1 + 0xe2e4) == '\0') {
        *(undefined4 *)(param_1 + 0x6044) = 0;
        *(undefined1 *)(param_1 + 0x6048) = 1;
        RequestTimer(param_1,8,500000,2);
      }
      else {
        *(undefined1 *)(param_1 + 0xe2e5) = 1;
      }
    }
  }
  return uVar9;
}



===== RxPushMessageUnitQueueFib @ 1c0002970 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RxPushMessageUnitQueueFib(longlong param_1,longlong param_2)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  undefined1 uVar8;
  undefined8 local_28;
  ulonglong local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)&local_28;
  lVar2 = *(longlong *)(param_1 + 0x1a8);
  uVar8 = 1;
  local_18 = 0;
  if (*(char *)(param_1 + 0x80e1) == '\0') {
    uVar4 = *(uint *)(lVar2 + 0x40);
    if (uVar4 == 0xffffffff) {
      uVar8 = 0;
      goto LAB_1c0002a36;
    }
    local_28 = *(undefined8 *)(param_2 + 0x10);
    uVar1 = *(ushort *)(*(longlong *)(param_2 + 0x28) + 8);
    local_10 = (ulonglong)uVar1;
    local_20 = (ulonglong)uVar1;
    puVar6 = &local_28;
    puVar7 = (undefined4 *)((ulonglong)uVar4 + *(longlong *)(param_1 + 0x1c8));
    for (lVar5 = 3; lVar5 != 0; lVar5 = lVar5 + -1) {
      *puVar7 = *(undefined4 *)puVar6;
      puVar6 = (undefined8 *)((longlong)puVar6 + 4);
      puVar7 = puVar7 + 1;
    }
    LOCK();
    UNLOCK();
    *(uint *)(lVar2 + 0x40) = uVar4;
  }
  else {
    uVar4 = *(uint *)(param_2 + 0x10);
    uVar1 = *(ushort *)(*(longlong *)(param_2 + 0x28) + 8);
    local_10 = (ulonglong)uVar1;
    if (0x80 < uVar1) {
      uVar3 = (int)((uVar1 - 0x61 & 0xffffffe0) + ((int)(uVar1 - 0x61) >> 0x1f & 0x1fU)) >> 5;
      local_10 = (ulonglong)uVar3;
      if (uVar3 < 0xf) {
        uVar4 = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar4 | 0xf;
      }
    }
    *(uint *)(lVar2 + 0x40) = uVar4;
  }
  LOCK();
  UNLOCK();
LAB_1c0002a36:
  return CONCAT71((int7)(local_10 >> 8),uVar8);
}



===== PMCPushMessageUnitQueueFib @ 1c0002a60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PMCPushMessageUnitQueueFib(longlong param_1,longlong param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  ushort uVar7;
  int iVar8;
  ushort uVar9;
  byte bVar10;
  ushort uVar11;
  uint uVar12;
  undefined1 local_c8 [32];
  undefined4 local_a8;
  uint local_98;
  undefined8 local_90;
  short local_88;
  undefined1 local_86 [62];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_c8;
  uVar2 = *(undefined8 *)(param_2 + 0x10);
  lVar5 = *(longlong *)(param_2 + 0x28);
  local_90 = uVar2;
  if (*(int *)(param_1 + 0x8088) == 2) {
    lVar3 = *(longlong *)(param_2 + 0x18);
    iVar4 = (int)(*(ushort *)(lVar5 + 8) + 0x7f) >> 7;
    if ((*(char *)(param_1 + 0xaad6) == '\0') || (*(short *)(lVar5 + 4) == 700)) {
      *(uint *)(lVar5 + 0x14) = (*(uint *)(lVar5 + 0xc) >> 2) + 1;
      if ((lVar3 != 0) && (*(char *)(lVar3 + 2) == '\x02')) {
        if (*(ushort *)(param_1 + 0xb988) == 0xffffffff) {
          *(undefined2 *)(param_1 + 0xb988) = 0;
        }
        else {
          *(ushort *)(param_1 + 0xb988) = *(ushort *)(param_1 + 0xb988) + 1;
        }
      }
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0xba08);
      if (*(ushort *)(param_1 + 0xaad4) < 3) {
        uVar9 = 1;
        if (uVar1 <= (ushort)(*(short *)(param_1 + 0xb98a) - *(short *)(param_1 + 0xb9ca))) {
          local_a8 = 0x7d4;
LAB_1c0002bc1:
          ArcPrintf(param_1,4,(byte *)"SHOULD NOT BE HERE! (%s) line %d. WE MAY SEE DPC TIME OUT.\n"
                    ,0x1c0015740);
        }
      }
      else {
        uVar9 = (short)((longlong)(ulonglong)*(ushort *)(param_1 + 0xaae0) %
                       (longlong)(int)(*(ushort *)(param_1 + 0xaad4) - 1)) + 1;
        local_98 = CONCAT22(local_98._2_2_,uVar9);
        uVar11 = *(short *)(param_1 + 0xb988 + (ulonglong)uVar9 * 2) -
                 *(short *)(param_1 + 0xb9c8 + (ulonglong)uVar9 * 2);
        uVar7 = uVar9;
        while (uVar1 <= uVar11) {
          if ((uint)uVar9 == *(ushort *)(param_1 + 0xaad4) - 1) {
            uVar9 = 1;
          }
          else {
            uVar9 = uVar9 + 1;
          }
          if (uVar9 == uVar7) {
            local_a8 = 0x7c1;
            goto LAB_1c0002bc1;
          }
          ArcPrintf(param_1,0x10000100,&s_Vector__d_is_full__,(ulonglong)uVar7);
          uVar7 = (ushort)local_98;
          uVar11 = *(short *)(param_1 + 0xb988 + (ulonglong)uVar9 * 2) -
                   *(short *)(param_1 + 0xb9c8 + (ulonglong)uVar9 * 2);
        }
      }
      uVar6 = (ulonglong)uVar9;
      uVar1 = *(ushort *)(param_1 + 0xb988 + uVar6 * 2);
      if (uVar1 == 0xffffffff) {
        *(undefined2 *)(param_1 + 0xb988 + uVar6 * 2) = 0;
      }
      else {
        *(ushort *)(param_1 + 0xb988 + uVar6 * 2) = uVar1 + 1;
      }
      *(uint *)(lVar5 + 0x14) = (*(uint *)(lVar5 + 0xc) >> 2) + 1 + (uint)uVar9 * 0x10000;
      if (*(int *)(param_1 + 0xaae0) == -1) {
        *(undefined4 *)(param_1 + 0xaae0) = 0;
      }
      else {
        *(int *)(param_1 + 0xaae0) = *(int *)(param_1 + 0xaae0) + 1;
      }
    }
    *(int *)(lVar5 + 0xc) = (int)local_90;
    *(undefined1 *)(lVar5 + 6) = 4;
    *(undefined4 *)(lVar5 + 0x10) = 0;
    iVar8 = (int)local_90;
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x18);
    iVar4 = (int)((ulonglong)*(ushort *)(lVar5 + 8) + 0x9f >> 7);
    if ((*(char *)(param_1 + 0xaad6) == '\0') || (*(short *)(lVar5 + 4) == 700)) {
      *(uint *)(lVar5 + -0x14) = (*(uint *)(lVar5 + 0xc) >> 2) + 1;
      if ((lVar3 != 0) && (*(char *)(lVar3 + 2) == '\x02')) {
        if (*(ushort *)(param_1 + 0xb988) == 0xffffffff) {
          *(undefined2 *)(param_1 + 0xb988) = 0;
        }
        else {
          *(ushort *)(param_1 + 0xb988) = *(ushort *)(param_1 + 0xb988) + 1;
        }
      }
      if ((((*(uint *)(param_1 + 0xbad8) & 0x2000) != 0) && (*(short *)(lVar5 + 4) == 700)) &&
         (*(short *)(param_1 + 0x158e) == 0x28b)) {
        return 0x200;
      }
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0xaad4);
      if (uVar1 < 3) {
        uVar12 = 1;
        if (*(ushort *)(param_1 + 0xba08) <=
            (ushort)(*(short *)(param_1 + 0xb98a) - *(short *)(param_1 + 0xb9ca))) {
          local_a8 = 0x854;
          ArcPrintf(param_1,4,(byte *)"SHOULD NOT BE HERE! (%s) line %d. WE MAY SEE DPC TIME OUT.\n"
                    ,0x1c0015740);
        }
      }
      else {
        local_88 = 0;
        memset(local_86,0,0x3c);
        local_98 = 1;
        uVar9 = 0xffff;
        uVar6 = 1;
        if (1 < uVar1) {
          do {
            bVar10 = (char)uVar6 + 1;
            *(short *)(local_86 + uVar6 * 2 + -4) =
                 *(short *)(param_1 + 0xb988 + uVar6 * 2) - *(short *)(param_1 + 0xb9c8 + uVar6 * 2)
            ;
            uVar6 = (ulonglong)bVar10;
          } while (bVar10 < uVar1);
        }
        bVar10 = 1;
        if (1 < uVar1) {
          uVar7 = 1;
          do {
            if (*(ushort *)(local_86 + (ulonglong)bVar10 * 2 + -4) < uVar9) {
              local_98 = (uint)uVar7;
              uVar9 = *(ushort *)(local_86 + (ulonglong)bVar10 * 2 + -4);
            }
            bVar10 = bVar10 + 1;
            uVar7 = (ushort)bVar10;
          } while (bVar10 < uVar1);
        }
        uVar12 = local_98;
      }
      uVar6 = (ulonglong)uVar12;
      uVar1 = *(ushort *)(param_1 + 0xb988 + uVar6 * 2);
      if (uVar1 == 0xffffffff) {
        *(undefined2 *)(param_1 + 0xb988 + uVar6 * 2) = 0;
      }
      else {
        *(ushort *)(param_1 + 0xb988 + uVar6 * 2) = uVar1 + 1;
      }
      *(uint *)(lVar5 + -0x14) = (*(uint *)(lVar5 + 0xc) >> 2) + 1 + uVar12 * 0x10000;
      if (*(int *)(param_1 + 0xaae0) == -1) {
        *(undefined4 *)(param_1 + 0xaae0) = 0;
      }
      else {
        *(int *)(param_1 + 0xaae0) = *(int *)(param_1 + 0xaae0) + 1;
      }
    }
    *(undefined8 *)(lVar5 + -0x20) = uVar2;
    iVar8 = (int)local_90 + -0x20;
    *(uint *)(lVar5 + -0x18) = (uint)*(ushort *)(lVar5 + 8);
  }
  uVar12 = iVar4 - 1;
  if (0x1f < uVar12) {
    uVar12 = 0x1f;
  }
  if ((((*(uint *)(param_1 + 0xbad8) & 0x100) == 0) ||
      (lVar5 = *(longlong *)(param_2 + 0x18), lVar5 == 0)) || (*(char *)(lVar5 + 0x48) != -3)) {
    *(undefined4 *)(param_2 + 0x78) = 9;
    *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0xc4) = local_90._4_4_;
    LOCK();
    UNLOCK();
    lVar5 = *(longlong *)(param_1 + 0x1a8);
    *(uint *)(lVar5 + 0xc0) = iVar8 + uVar12;
    LOCK();
    UNLOCK();
  }
  else {
    *(undefined4 *)(param_2 + 0x78) = 0xb;
  }
  return CONCAT71((int7)((ulonglong)lVar5 >> 8),1);
}



===== SetWaitCount4SendSyncCmd @ 1c0002ef8 =====

int SetWaitCount4SendSyncCmd(longlong param_1,int param_2)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x618) != '\0') {
    return 100000;
  }
  if (*(char *)(param_1 + 0x610) != '\0') {
    return *(int *)(param_1 + 0x5178) * 100000;
  }
  if (((param_2 == 0xc) && (*(short *)(*(longlong *)(param_1 + 0x1d8) + 4) == 500)) &&
     (*(short *)(param_1 + 0x158e) == 0x28b)) {
    if (*(int *)(*(longlong *)(param_1 + 0x1d8) + 0x20) == 0x16) {
      return *(int *)(param_1 + 0x5178) * 110000;
    }
    return 300000;
  }
  uVar1 = *(uint *)(param_1 + 0xbad8);
  if ((uVar1 >> 0xe & 1) != 0) {
    return 290000;
  }
  if ((uVar1 >> 0xd & 1) != 0) {
    return 260000;
  }
  if (((uVar1 >> 0xc & 1) != 0) && ((uVar1 & 0xc00) != 0)) {
    return 50000;
  }
  if ((((byte)uVar1 & 0x90) == 0x90) || ((uVar1 >> 0xb & 1) != 0)) {
    return 120000;
  }
  if ((uVar1 >> 9 & 1) != 0) {
    return 270000;
  }
  if ((uVar1 >> 10 & 1) == 0) {
    return *(int *)(param_1 + 0x5178) * 100000;
  }
  return 280000;
}



===== RxSendSynchCommand @ 1c0002fd0 =====

ulonglong RxSendSynchCommand(longlong param_1,ulonglong param_2,char *param_3,ulonglong param_4,
                            uint param_5,uint param_6,uint *param_7,uint *param_8,uint *param_9,
                            uint *param_10,uint *param_11,char param_12)

{
  ushort uVar1;
  longlong lVar2;
  uint *puVar3;
  uint *puVar4;
  longlong lVar5;
  int iVar6;
  ulonglong uVar7;
  undefined4 extraout_var;
  undefined4 uVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  uint uVar14;
  char cVar15;
  int iVar16;
  undefined8 uVar17;
  undefined1 uVar18;
  uint local_res10;
  
  uVar14 = (uint)param_4;
  uVar12 = (uint)param_3;
  lVar2 = *(longlong *)(param_1 + 0x1a8);
  puVar3 = *(uint **)(param_1 + 0x1c0);
  uVar9 = (uint)param_2;
  uVar11 = 0;
  local_res10 = 0;
  uVar18 = 1;
  if (((*(uint *)(param_1 + 0xbadc) & 1) == 0) || (*(char *)(param_1 + 0xe2d4) != '\0')) {
LAB_1c0003091:
    if (uVar9 == 0xc) goto LAB_1c0003097;
    DAT_1c001d920 = uVar9;
  }
  else {
    if ((uVar9 != 0xc) || (*(short *)(*(longlong *)(param_1 + 0x1d8) + 4) != 500)) {
      param_3 = "* RxSendSynchCommand: mailbox[0] cmd: 0x%x, Fib cmd: %d\n";
      param_4 = param_2 & 0xffffffff;
      param_2 = 4;
      ArcPrintf(param_1,4,(byte *)"* RxSendSynchCommand: mailbox[0] cmd: 0x%x, Fib cmd: %d\n",
                param_4);
      goto LAB_1c0003091;
    }
    param_3 = "* RxSendSynchCommand: mailbox[0] CMD:0x%x, Fib CMD:%d, VM CMD:%d\n";
    param_4 = param_2 & 0xffffffff;
    param_2 = 4;
    ArcPrintf(param_1,4,&s___RxSendSynchCommand__mailbox_0_,param_4);
LAB_1c0003097:
    if (*(char *)(param_1 + 0xe2d4) == '\0') {
      param_2 = 500;
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 0x1d8) + 4);
      if (uVar1 == 500) {
        DAT_1c001d920 = *(uint *)(*(longlong *)(param_1 + 0x1d8) + 0x20);
      }
      else {
        DAT_1c001d920 = (uint)uVar1;
      }
    }
  }
  uVar10 = 0;
  if (((((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) &&
       (puVar4 = *(uint **)(param_1 + 0x1d8), puVar4 != (uint *)0x0)) && (uVar9 == 0xc)) &&
     ((short)puVar4[1] == 0x2c1)) {
    *puVar4 = *puVar4 | 0x100;
    local_res10 = 0x2c1;
  }
  if (*(char *)(param_1 + 0xe2d4) != '\0') {
    GetElapsedSeconds(param_1,param_2,param_3,param_4);
    uVar12 = *(uint *)(param_1 + 0xe2d8);
    if (DAT_1c001d920 != uVar12) {
      uVar7 = ArcPrintf(param_1,4,
                        (byte *)
                        "* RxSendSynchCommand: There is a pending synch cmd: 0x%x(%d). Has been pending %d seconds. Rejecting synch Cmd: 0x%x(%d)\n"
                        ,(ulonglong)uVar12);
      goto LAB_1c0003158;
    }
    ArcPrintf(param_1,4,
              (byte *)
              "* RxSendSynchCommand: synch cmd: 0x%x(%d) has been pending %d seconds. Check again if the response is available\n"
              ,(ulonglong)uVar12);
    if (*(char *)(param_1 + 0xaad6) == '\0') {
      if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
        uVar11 = *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x9c) >> 0xc;
      }
      else {
        uVar11 = *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x2c);
      }
      uVar11 = uVar11 & 1;
    }
    else if ((*(uint *)(*(longlong *)(param_1 + 0x1a8) + 200) >> 0xc & 1) != 0) {
      *(undefined4 *)(param_1 + 0xaad8) = 1;
    }
    if ((uVar11 == 0) && (*(int *)(param_1 + 0xaad8) == 0)) {
      uVar7 = ArcPrintf(param_1,4,
                        (byte *)
                        "* RxSendSynchCommand: Still NO response for the pending synch command 0x%x(%d)\n"
                        ,(ulonglong)*(uint *)(param_1 + 0xe2d8));
      goto LAB_1c0003158;
    }
    StorPortStallExecution(100);
    if (*(char *)(param_1 + 0xaad6) == '\0') {
      RxWriteODR(param_1,1,'\x01');
    }
    else if (*(int *)(param_1 + 0xaad8) != 0) {
      RxAccessDeviceRegister(param_1,7);
    }
    uVar7 = (ulonglong)*(uint *)(param_1 + 0xe2d8);
    *(undefined4 *)(param_1 + 0xaad8) = 0;
    ArcPrintf(param_1,4,
              (byte *)"* RxSendSynchCommand: Got response for the pending synch command 0x%x(%d)\n",
              uVar7);
    cVar15 = '\0';
    if (param_12 == '\0') {
      ArcPrintf(param_1,4,
                (byte *)"* RxSendSynchCommand: Should NOT happend! It should wait for completion\n",
                uVar7);
      cVar15 = '\0';
    }
LAB_1c00035b8:
    *(char *)(param_1 + 0xe2d4) = cVar15;
    uVar18 = 1;
    *(undefined4 *)(param_1 + 0xe2dc) = 0x55;
    *param_11 = *puVar3;
    if (param_7 != (uint *)0x0) {
      *param_7 = puVar3[1];
    }
    if (param_8 != (uint *)0x0) {
      *param_8 = puVar3[2];
    }
    if (param_9 != (uint *)0x0) {
      *param_9 = puVar3[3];
    }
    if (param_10 != (uint *)0x0) {
      *param_10 = puVar3[4];
    }
    if ((uVar9 == 0x26) && ((ushort)(*(short *)(param_1 + 0x158e) - 0x28cU) < 2)) {
      uVar11 = puVar3[5];
      *(uint *)(param_1 + 0x8080) = uVar11;
      ArcPrintf(param_1,4,(byte *)"* pDeviceExtension->MaxMSIXVectorsSupport: 0x%x\n",
                (ulonglong)uVar11);
      cVar15 = '\0';
    }
    if (*(char *)(param_1 + 0xaad6) == cVar15) {
      RxWriteODR(param_1,1,'\x01');
    }
    uVar7 = 0x286;
    if (*(short *)(param_1 + 0x158e) == 0x286) {
      *(undefined4 *)(lVar2 + 0x4ec) = 0x10000;
      LOCK();
      UNLOCK();
      *(undefined4 *)(lVar2 + 0x4ec) = 0x1000000;
      LOCK();
      UNLOCK();
    }
    if (*(char *)(param_1 + 0xaad6) == cVar15) {
      uVar7 = (ulonglong)*(uint *)(param_1 + 0x814c);
      *(uint *)(lVar2 + 0x34) = *(uint *)(param_1 + 0x814c);
      LOCK();
      UNLOCK();
    }
    goto LAB_1c00036f0;
  }
  iVar6 = SetWaitCount4SendSyncCmd(param_1,uVar9);
  if (*(char *)(param_1 + 0xaad6) != (char)uVar10) {
    if (iVar6 != 0) {
      do {
        if ((*(uint *)(*(longlong *)(param_1 + 0x1a8) + 200) >> 0xc & 1) == 0) break;
        StorPortStallExecution(10);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      uVar10 = 0;
      if (iVar6 != 0) goto LAB_1c0003328;
    }
    uVar7 = ArcPrintf(param_1,4,
                      (byte *)
                      " RxSendSynchCommand[MSIX mode] failed before sending cmd, because of flag in 0xC8 has not been cleared #1. REG 0x20(0x%x),REG 0XC8(0x%x),REG 0X34(0x%x),REG 0X10(0x%x)\n"
                      ,(ulonglong)*(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x20));
LAB_1c0003158:
    return uVar7 & 0xffffffffffffff00;
  }
LAB_1c0003328:
  *puVar3 = uVar9;
  LOCK();
  UNLOCK();
  puVar3[1] = uVar12;
  LOCK();
  UNLOCK();
  puVar3[2] = uVar14;
  LOCK();
  UNLOCK();
  puVar3[3] = param_5;
  LOCK();
  UNLOCK();
  puVar3[4] = param_6;
  LOCK();
  UNLOCK();
  uVar17 = 1;
  if (*(char *)(param_1 + 0xaad6) == (char)uVar10) {
    RxWriteODR(param_1,1,'\x01');
  }
  cVar15 = (char)uVar10;
  if (*(char *)(param_1 + 0xaad6) == cVar15) {
    *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_1 + 0x8150);
    LOCK();
    UNLOCK();
  }
  uVar8 = (undefined4)uVar17;
  if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
    uVar8 = 0x200;
  }
  *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x20) = uVar8;
  LOCK();
  UNLOCK();
  uVar7 = (ulonglong)DAT_1c001d920;
  *(uint *)(param_1 + 0xe2d8) = DAT_1c001d920;
  if (param_12 == cVar15) {
    *(undefined4 *)(param_1 + 0x200) = 3000;
  }
  else {
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      iVar16 = (int)uVar10;
      if (((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) && (local_res10 == 0x2c1)) {
LAB_1c00035b3:
        cVar15 = (char)iVar16;
        goto LAB_1c00035b8;
      }
      lVar5 = *(longlong *)(param_1 + 0x1a8);
      if (*(char *)(param_1 + 0xaad6) == (char)uVar10) {
        if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
          uVar11 = *(uint *)(lVar5 + 0x9c) >> 0xc;
        }
        else {
          uVar11 = *(uint *)(lVar5 + 0x2c);
        }
        uVar11 = uVar11 & (uint)uVar17;
      }
      else if ((*(uint *)(lVar5 + 200) >> 0xc & 1) != 0) {
        *(uint *)(param_1 + 0xaad8) = (uint)uVar17;
      }
      if (((byte)((byte)uVar17 & (byte)uVar11) != 0) || (*(int *)(param_1 + 0xaad8) != iVar16)) {
        StorPortStallExecution(100);
        iVar16 = 0;
        if (*(char *)(param_1 + 0xaad6) == '\0') {
          RxWriteODR(param_1,1,'\x01');
        }
        else {
          if ((*(int *)(param_1 + 0xaad8) != 0) &&
             (RxAccessDeviceRegister(param_1,7),
             (*(uint *)(*(longlong *)(param_1 + 0x1a8) + 200) >> 0xc & 1) != 0)) {
            StorPortStallExecution(10);
            if (iVar6 - 1U < 2) {
              *(undefined4 *)(param_1 + 0xaad8) = 0;
              ArcPrintf(param_1,4,
                        (byte *)
                        " RxSendSynchCommand[MSIX mode]: synch cmd finished, but flag in 0xC8 REG has not been cleared #2. REG 0x20(0x%x),REG 0XC8(0x%x),REG 0X34(0x%x),REG 0X10(0x%x)\n"
                        ,(ulonglong)*(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x20));
              iVar16 = 0;
              goto LAB_1c00035b3;
            }
            goto LAB_1c00034f3;
          }
          iVar16 = 0;
        }
        *(int *)(param_1 + 0xaad8) = iVar16;
        goto LAB_1c00035b3;
      }
      StorPortStallExecution(10);
      *(int *)(param_1 + 0xe2d0) = iVar6 + -1;
LAB_1c00034f3:
      uVar17 = 1;
      uVar10 = 0;
      cVar15 = '\0';
    }
    if (*(char *)(param_1 + 0xaad6) == cVar15) {
      *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_1 + 0x814c);
      LOCK();
      UNLOCK();
    }
    pcVar13 = " RxSendSynchCommand Failed %d,wait count %d\n";
    uVar7 = (ulonglong)local_res10;
    uVar10 = 4;
    ArcPrintf(param_1,4,(byte *)" RxSendSynchCommand Failed %d,wait count %d\n",uVar7);
    *(undefined1 *)(param_1 + 0xe2d4) = 1;
    uVar18 = 0;
    uVar11 = GetElapsedSeconds(param_1,uVar10,pcVar13,uVar7);
    uVar7 = CONCAT44(extraout_var,uVar11);
    *(uint *)(param_1 + 0xe2dc) = uVar11;
  }
LAB_1c00036f0:
  return CONCAT71((int7)(uVar7 >> 8),uVar18);
}



===== RxStartAdapter @ 1c0003710 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0003b97) */
/* WARNING: Removing unreachable block (ram,0x0001c0003c5b) */
/* WARNING: Removing unreachable block (ram,0x0001c0003b3a) */

byte RxStartAdapter(longlong param_1,undefined4 param_2,undefined8 param_3,ulonglong param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int *piVar6;
  undefined4 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  int iVar10;
  char *pcVar11;
  longlong lVar12;
  byte bVar13;
  int iVar14;
  undefined1 local_2a8 [32];
  uint *puVar15;
  ushort local_230 [2];
  undefined4 local_22c;
  longlong local_228;
  uint local_218 [3];
  int local_20c;
  undefined4 local_1fc;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_2a8;
  lVar12 = *(longlong *)(param_1 + 0x658);
  uVar3 = 0x1000;
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x1000;
  local_228 = *(longlong *)(param_1 + 0x1a8);
  if (*(int *)(param_1 + 0x8088) == 0) {
    do {
    } while (*(int *)(local_228 + 0x44) != -1);
  }
  bVar13 = 1;
  lVar8 = param_1;
  local_22c = param_2;
  uVar2 = RxGetOMRx0(param_1);
  if (((uVar2 & 4) == 0) && ((uVar2 >> 8 & 1) == 0)) {
    if ((((*(char *)(lVar8 + 0x618) == '\0') &&
         ((*(char *)(lVar8 + 0x610) == '\0' &&
          (uVar2 = *(uint *)(lVar8 + 0xbad8), (uVar2 >> 0xd & 1) == 0)))) &&
        (((uVar3 & uVar2) == 0 || ((uVar2 & 0xc00) == 0)))) &&
       (((((byte)uVar2 & 0x90) != 0x90 && ((uVar2 >> 0xb & 1) == 0)) && ((uVar2 & 0x600) == 0)))) {
      iVar10 = *(int *)(param_1 + 0x5178) * 10000;
    }
    else {
      iVar10 = 10;
    }
    uVar3 = RxGetOMRx0(param_1);
    iVar14 = 0x80;
    while ((uVar3 & 0x80) == 0) {
      if (iVar10 == 0) goto LAB_1c0003cac;
      StorPortStallExecution(100);
      iVar10 = iVar10 + -1;
      *(int *)(param_1 + 0xe2e0) = iVar10;
      uVar3 = RxGetOMRx0(param_1);
    }
    if (iVar10 != 0) {
      do {
        local_230[0] = 0;
        ArcPrintf(param_1,0x10000200,(byte *)"entering IsAdapterReadyForConfigCommand\n",param_4);
        memset(local_218,0,0x20);
        local_218[0] = 2;
        local_218[1] = 0xfd;
        local_1fc = 8;
        if (*(longlong *)(param_1 + 0x188) == 0) {
          puVar15 = local_218;
          param_4 = 0x1d0;
          uVar4 = SendSynchFib(param_1,500,local_218,0x1d0,puVar15,local_230,'\x01');
          if ((((char)uVar4 == '\0') || (local_218[0] != 0)) || (local_218[2] != 0xda)) {
            ArcPrintf(param_1,0x10000200,(byte *)"IsAdapterReadyForConfigCommand: TRUE \n",param_4);
            pcVar11 = "* leaving IsAdapterReadyForConfigCommand aborted: TRUE \n";
            uVar4 = 2;
          }
          else {
            uVar4 = 0x10000200;
            if (local_20c == 0) {
              ArcPrintf(param_1,0x10000200,(byte *)"IsAdapterReadyForConfigCommand: FALSE \n",
                        param_4);
              goto LAB_1c00038e6;
            }
            pcVar11 = "leaving IsAdapterReadyForConfigCommand\n";
          }
          ArcPrintf(param_1,(uint)uVar4,(byte *)pcVar11,param_4);
          if (iVar10 != 0) {
            uVar5 = HandleAdapterConfigIssues(param_1,uVar4,pcVar11,param_4);
            iVar10 = (int)uVar5;
            if (iVar10 == 0) {
              if (*(char *)(param_1 + 0x610) == '\0') {
                lVar8 = *(longlong *)(param_1 + 0x630);
                *(undefined4 *)(lVar8 + 0x30) = local_22c;
                if (*(char *)(param_1 + 0x8084) == '\0') {
                  *(undefined4 *)(lVar8 + 0x2c) = 0xfffff;
                  *(undefined4 *)(param_1 + 0x814c) = 0xfffffffb;
                  *(undefined4 *)(param_1 + 0x8150) = 0xffffffff;
                  **(undefined4 **)(lVar12 + 0x18) = 8;
                  **(undefined4 **)(lVar12 + 0x20) = 8;
                  **(undefined4 **)(lVar12 + 0x78) = 4;
                  **(undefined4 **)(lVar12 + 0x80) = 4;
                  **(undefined4 **)(lVar12 + 0xd8) = 0x200;
                  **(undefined4 **)(lVar12 + 0xe0) = 0x200;
                  **(undefined4 **)(lVar12 + 0x138) = 4;
                  **(undefined4 **)(lVar12 + 0x140) = 4;
                  **(undefined4 **)(lVar12 + 0x48) = 0x200;
                  **(undefined4 **)(lVar12 + 0x50) = 0x200;
                  **(undefined4 **)(lVar12 + 0xa8) = 4;
                  **(undefined4 **)(lVar12 + 0xb0) = 4;
                  **(undefined4 **)(lVar12 + 0x108) = 8;
                  **(undefined4 **)(lVar12 + 0x110) = 8;
                  **(undefined4 **)(lVar12 + 0x168) = 4;
                  **(undefined4 **)(lVar12 + 0x170) = 4;
                }
                else {
                  uVar7 = 0xfffffffb;
                  if (1 < *(int *)(param_1 + 0x8088) - 1U) {
                    uVar7 = 0xfffffff7;
                  }
                  if (*(char *)(param_1 + 0xaad6) != '\0') {
                    uVar7 = 0xfffffffa;
                  }
                  *(undefined4 *)(param_1 + 0x8150) = 0xffffffff;
                  *(undefined4 *)(param_1 + 0x814c) = uVar7;
                }
                *(undefined4 *)(local_228 + 0x34) = *(undefined4 *)(param_1 + 0x8150);
                LOCK();
                UNLOCK();
                lVar12 = local_228;
                RxWriteODR(param_1,-1,'\0');
                *(undefined4 *)(lVar12 + 0x34) = *(undefined4 *)(param_1 + 0x814c);
                LOCK();
                UNLOCK();
                lVar12 = 500;
                do {
                  lVar8 = lVar12;
                  StorPortStallExecution(999);
                  lVar12 = lVar8 + -1;
                } while (lVar12 != 0);
                cVar1 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                                  (param_1,(int)lVar8 + 4,*(undefined4 *)(param_1 + 0x638));
                bVar13 = -(cVar1 != '\0') & 1;
                if (*(char *)(param_1 + 0x80e2) != '\0') {
                  uVar3 = 0;
                  if (*(int *)(param_1 + 0x80e4) != 0) {
                    do {
                      uVar9 = (ulonglong)uVar3;
                      uVar3 = uVar3 + 1;
                      *(undefined4 *)(*(longlong *)(param_1 + 0x80f0) + uVar9 * 4) = 0xdeadbeef;
                    } while (uVar3 < *(uint *)(param_1 + 0x80e4));
                  }
                  (*(code *)**(undefined8 **)(param_1 + 0x1320))
                            (param_1,0x31,*(undefined4 *)(param_1 + 0x8100));
                }
                if (*(char *)(param_1 + 0x80e0) != '\0') {
                  piVar6 = (int *)(param_1 + 0x810c);
                  lVar12 = 0xf;
                  do {
                    lVar8 = lVar12;
                    *piVar6 = iVar14;
                    iVar14 = iVar14 + 0x20;
                    piVar6 = piVar6 + 1;
                    lVar12 = lVar8 + -1;
                  } while (lVar12 != 0);
                  *(undefined4 *)(param_1 + 0x8148) = 0xffffffff;
                  iVar10 = (int)lVar8;
                  memcpy(*(void **)(param_1 + 0x1d8),(int *)(param_1 + 0x810c),
                         (ulonglong)(iVar10 + 0x3f));
                  (*(code *)**(undefined8 **)(param_1 + 0x1320))
                            (param_1,iVar10 + 0x2d,*(undefined4 *)(param_1 + 0x1e0));
                }
              }
              goto LAB_1c0003caf;
            }
            if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) &&
               (*(char *)(param_1 + 0xaad6) != '\0')) {
              ArcLogEventString(param_1,uVar4,iVar10 + -0x1fe60000,iVar10,puVar15,0x60);
            }
            gAdapterAddCount = gAdapterAddCount + -1;
          }
          break;
        }
LAB_1c00038e6:
        StorPortStallExecution(100);
        iVar10 = iVar10 + -1;
        *(int *)(param_1 + 0xe2e0) = iVar10;
      } while (iVar10 != 0);
    }
  }
LAB_1c0003cac:
  bVar13 = 0;
LAB_1c0003caf:
  RequestTimer(param_1,1,1000000,2);
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xffffefff;
  return bVar13;
}



===== RxWaitForAdapterToBoot @ 1c0003d10 =====

undefined8 RxWaitForAdapterToBoot(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_var;
  undefined8 uVar3;
  undefined4 extraout_var_00;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  
  uVar5 = 1;
  lVar4 = param_1;
  uVar1 = RxGetOMRx0(param_1);
  uVar3 = CONCAT44(extraout_var,uVar1);
  if (((uVar1 & 4) == 0) && ((uVar1 >> 8 & 1) == 0)) {
    if ((*(char *)(lVar4 + 0x618) != '\0') ||
       (iVar6 = 3000000, (*(uint *)(lVar4 + 0xbad8) & 4) != 0)) {
      iVar6 = 500;
    }
    while( true ) {
      iVar2 = RxGetOMRx0(lVar4);
      uVar3 = CONCAT44(extraout_var_00,iVar2);
      if (((char)iVar2 < '\0') && (iVar2 != -1)) break;
      if (iVar6 == 0) goto LAB_1c0003d78;
      StorPortStallExecution(100);
      iVar6 = iVar6 + -1;
      lVar4 = param_1;
    }
    if (iVar6 != 0) goto LAB_1c0003d7a;
  }
LAB_1c0003d78:
  uVar5 = 0;
LAB_1c0003d7a:
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),uVar5);
}



===== RxAccessDeviceRegister @ 1c0003d90 =====

uint RxAccessDeviceRegister(longlong param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x1a8);
  uVar3 = 0;
  if (param_2 == 0) {
    *(undefined4 *)(lVar1 + 0x34) = *(undefined4 *)(param_1 + 0x814c);
  }
  else if (param_2 == 1) {
    *(undefined4 *)(lVar1 + 0x34) = *(undefined4 *)(param_1 + 0x8150);
  }
  else {
    if (param_2 == 2) {
      return *(uint *)(lVar1 + 0x44);
    }
    if (param_2 == 3) {
      *(undefined4 *)(lVar1 + 0x38) = 3;
    }
    else {
      if (param_2 == 4) {
        *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x20) = *(uint *)(lVar1 + 0x20) | 0x40;
        LOCK();
        UNLOCK();
        *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x18) = 0x9c00001f;
        LOCK();
        UNLOCK();
        uVar3 = *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x34);
        uVar2 = uVar3 & 0xfffffffa;
      }
      else {
        if (param_2 == 5) {
          uVar3 = *(uint *)(lVar1 + 0x20) & 0xffffffbf;
LAB_1c0003e51:
          *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x20) = uVar3;
          LOCK();
          UNLOCK();
          return *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x20);
        }
        if (param_2 == 6) {
          uVar3 = *(uint *)(lVar1 + 0x20) | 0x20;
          goto LAB_1c0003e51;
        }
        if (param_2 == 7) {
          uVar3 = *(uint *)(lVar1 + 0x20) | 0x10;
          goto LAB_1c0003e51;
        }
        if (param_2 != 8) {
          return 0;
        }
        *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x20) = *(uint *)(lVar1 + 0x20) | 0x80;
        LOCK();
        UNLOCK();
        *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x18) = 0x9c00001f;
        LOCK();
        UNLOCK();
        uVar3 = *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x34);
        uVar2 = uVar3 & 0xfffffffb;
      }
      *(uint *)(*(longlong *)(param_1 + 0x1a8) + 0x34) = uVar2;
    }
  }
  LOCK();
  UNLOCK();
  return uVar3;
}



===== RxMapMailBoxFirmwareBase @ 1c0003ee8 =====

undefined8 RxMapMailBoxFirmwareBase(longlong param_1)

{
  short sVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  sVar1 = *(short *)(param_1 + 0x158e);
  if (sVar1 == 0x288) {
    *(longlong *)(param_1 + 0x1c8) = *(longlong *)(param_1 + 0x1b0);
    uVar2 = *(longlong *)(param_1 + 0x1b0) + 0x50;
    *(ulonglong *)(param_1 + 0x1c0) = uVar2;
    goto LAB_1c0003fb1;
  }
  if (sVar1 == 0x285) {
    lVar3 = *(longlong *)(param_1 + 0x1a8);
    uVar2 = lVar3 + 0x50;
LAB_1c0003f2f:
    *(ulonglong *)(param_1 + 0x1c0) = uVar2;
  }
  else {
    if (sVar1 == 0x286) {
      lVar3 = *(longlong *)(param_1 + 0x1a8);
      uVar2 = lVar3 + 0x1000;
      goto LAB_1c0003f2f;
    }
    if (sVar1 == 0x28b) {
      *(longlong *)(param_1 + 0x1c0) = *(longlong *)(param_1 + 0x1a8) + 0x7fc60;
      uVar2 = *(ulonglong *)(param_1 + 0x1b0);
      *(ulonglong *)(param_1 + 0x1c8) = uVar2;
      goto LAB_1c0003fb1;
    }
    uVar2 = (ulonglong)(ushort)(sVar1 - 0x28cU);
    if (1 < (ushort)(sVar1 - 0x28cU)) goto LAB_1c0003fb1;
    *(longlong *)(param_1 + 0x1c0) = *(longlong *)(param_1 + 0x1a8) + 0x1000;
    lVar3 = *(longlong *)(param_1 + 0x1b0);
  }
  *(longlong *)(param_1 + 0x1c8) = lVar3;
LAB_1c0003fb1:
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== RxGetOMRx0 @ 1c0003fb4 =====

undefined4 RxGetOMRx0(longlong param_1)

{
  if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
    return *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0xbc);
  }
  return *(undefined4 *)(*(longlong *)(param_1 + 0x1a8) + 0x18);
}



===== RxWriteODR @ 1c0003fdc =====

void RxWriteODR(longlong param_1,int param_2,char param_3)

{
  if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3) {
    if (param_3 != '\0') {
      param_2 = param_2 << 0xc;
    }
    *(int *)(*(longlong *)(param_1 + 0x1a8) + 0xa0) = param_2;
  }
  else {
    *(int *)(*(longlong *)(param_1 + 0x1a8) + 0x2c) = param_2;
  }
  LOCK();
  UNLOCK();
  return;
}



===== RevCheckCompatibility @ 1c000401c =====

bool RevCheckCompatibility(undefined8 param_1,int param_2,uint param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  if (0x7d30 < param_3) {
    return true;
  }
  iVar3 = 0;
  piVar2 = &DAT_1c001c004;
  do {
    if (piVar2[-1] == 6) {
      if (*piVar2 == param_2) {
        uVar1 = *(uint *)(&DAT_1c001c008 + (longlong)iVar3 * 0x10);
LAB_1c000405d:
        return uVar1 <= param_3;
      }
    }
    else if ((*piVar2 == 6) && (piVar2[-1] == param_2)) {
      uVar1 = *(uint *)(&DAT_1c001c00c + (longlong)iVar3 * 0x10);
      goto LAB_1c000405d;
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 4;
    if (0xf < iVar3) {
      return false;
    }
  } while( true );
}



===== CompareStrings @ 1c0004090 =====

undefined8 CompareStrings(longlong param_1,char *param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  ulonglong in_RAX;
  longlong lVar3;
  undefined3 uVar4;
  char cVar5;
  int iVar6;
  
  lVar3 = param_1 - (longlong)param_2;
  iVar6 = param_3;
  do {
    cVar5 = param_2[lVar3];
    cVar1 = *param_2;
    uVar4 = (undefined3)((uint)param_3 >> 8);
    param_3 = CONCAT31(uVar4,cVar1);
    param_2 = param_2 + 1;
    if (cVar5 != cVar1) {
      if ((byte)(cVar5 + 0xbfU) < 0x1a) {
        cVar5 = cVar5 + ' ';
      }
      uVar2 = param_3 - 0x41;
      in_RAX = (ulonglong)uVar2;
      if ((byte)uVar2 < 0x1a) {
        param_3 = CONCAT31(uVar4,cVar1 + ' ');
      }
      if (cVar5 != (char)param_3) {
        return (ulonglong)(uint3)(uVar2 >> 8) << 8;
      }
    }
    iVar6 = iVar6 + -1;
    if ((iVar6 == 0) || (cVar5 == '\0')) {
      return CONCAT71((int7)(in_RAX >> 8),1);
    }
  } while( true );
}



===== GetDriverParameter @ 1c00040d4 =====

uint GetDriverParameter(char *param_1,uint param_2,uint param_3,uint param_4,char *param_5)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_5 != (char *)0x0) {
    while (*param_5 != '\0') {
      for (; ((byte)(*param_5 - 9U) < 2 || (*param_5 == ' ')); param_5 = param_5 + 1) {
      }
      cVar3 = *param_5;
      if (cVar3 == '\0') {
        return param_2;
      }
      pcVar5 = param_1;
      do {
        cVar1 = *pcVar5;
        param_2 = CONCAT31((int3)(param_2 >> 8),cVar1);
        if (cVar1 == '\0') goto LAB_1c000417f;
        if (((byte)(cVar3 - 9U) < 2) || (cVar3 == ' ')) break;
        iVar4 = (int)cVar1;
        if ((byte)(cVar1 + 0x9fU) < 0x1a) {
          iVar4 = iVar4 + -0x20;
        }
        iVar2 = (int)cVar3;
        if ((byte)(cVar3 + 0x9fU) < 0x1a) {
          iVar2 = iVar2 + -0x20;
        }
        param_5 = param_5 + 1;
        if (iVar4 != iVar2) break;
        cVar3 = *param_5;
        pcVar5 = pcVar5 + 1;
      } while (cVar3 != '\0');
      if (*pcVar5 == '\0') break;
    }
LAB_1c000417f:
    pcVar5 = param_5 + 1;
    cVar3 = *pcVar5;
    while ((((cVar3 != '\0' && (1 < (byte)(cVar3 - 9U))) && (cVar3 != ' ')) &&
           ((byte)(cVar3 - 0x30U) < 10))) {
      if ((byte)(cVar3 - 0x30U) < 10) {
        pcVar5 = pcVar5 + 1;
      }
      cVar3 = *pcVar5;
    }
  }
  return param_2;
}



===== MatchRegistryString @ 1c00041fc =====

char MatchRegistryString(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  char cVar6;
  
  cVar6 = '\0';
  if (param_1 == (char *)0x0) {
LAB_1c000420c:
    cVar6 = '\0';
  }
  else {
    while ((*param_1 != '\0' && (cVar6 == '\0'))) {
      for (; ((byte)(*param_1 - 9U) < 2 || (*param_1 == ' ')); param_1 = param_1 + 1) {
      }
      cVar3 = *param_1;
      if (cVar3 == '\0') goto LAB_1c000420c;
      pcVar5 = param_2;
      do {
        cVar1 = *pcVar5;
        if (cVar1 == '\0') goto LAB_1c0004279;
        if (((byte)(cVar3 - 9U) < 2) || (cVar3 == ' ')) break;
        iVar4 = (int)cVar1;
        if ((byte)(cVar1 + 0x9fU) < 0x1a) {
          iVar4 = iVar4 + -0x20;
        }
        iVar2 = (int)cVar3;
        if ((byte)(cVar3 + 0x9fU) < 0x1a) {
          iVar2 = iVar2 + -0x20;
        }
        param_1 = param_1 + 1;
        if (iVar4 != iVar2) break;
        cVar3 = *param_1;
        pcVar5 = pcVar5 + 1;
      } while (cVar3 != '\0');
      if (*pcVar5 == '\0') {
LAB_1c0004279:
        cVar6 = '\x01';
      }
    }
  }
  return cVar6;
}



===== LongToAscii @ 1c000428c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * LongToAscii(undefined8 param_1,uint param_2,char *param_3)

{
  ulonglong uVar1;
  code *pcVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  char *pcVar8;
  undefined1 auStack_88 [32];
  char acStack_68 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  if (param_2 == 0) {
    param_3[0] = '0';
    param_3[1] = '\0';
  }
  else {
    uVar6 = 0;
    do {
      uVar1 = (ulonglong)param_2;
      param_2 = param_2 / 0x10;
      cVar4 = (char)(uVar1 % 0x10);
      if ((uint)(uVar1 % 0x10) < 10) {
        cVar4 = cVar4 + '0';
      }
      else {
        cVar4 = cVar4 + '7';
      }
      acStack_68[uVar6] = cVar4;
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while ((uVar5 < 0x4f) && (param_2 != 0));
    if (0x4f < uVar5) {
      __report_rangecheckfailure();
      pcVar2 = (code *)swi(3);
      pcVar8 = (char *)(*pcVar2)();
      return pcVar8;
    }
    uVar7 = 0;
    acStack_68[uVar6] = '\0';
    if (uVar5 != 0) {
      pcVar8 = param_3;
      do {
        iVar3 = uVar5 - uVar7;
        uVar7 = uVar7 + 1;
        *pcVar8 = acStack_68[iVar3 - 1];
        pcVar8 = pcVar8 + 1;
      } while (uVar7 < uVar5);
    }
    param_3[uVar6] = '\0';
  }
  return param_3;
}



===== RealSprintf @ 1c0004338 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RealSprintf(char *param_1,byte *param_2,ulonglong *param_3)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  ushort *puVar7;
  short sVar8;
  short sVar9;
  char *pcVar10;
  ulonglong uVar11;
  ushort uVar12;
  ushort uVar13;
  ushort uVar14;
  ulonglong uVar15;
  char cVar16;
  ushort local_78 [2];
  char local_74 [4];
  char local_70 [4];
  char local_6c [4];
  char local_68 [8];
  char local_60 [32];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)local_78;
  *param_1 = '\0';
  bVar1 = *param_2;
  do {
    if (bVar1 == 0) {
      local_78[0] = 0;
      puVar7 = local_78;
      for (; *param_1 != '\0'; param_1 = param_1 + 1) {
      }
      pcVar10 = param_1 + -1;
      do {
        uVar14 = *puVar7;
        pcVar10 = pcVar10 + 1;
        puVar7 = (ushort *)((longlong)puVar7 + 1);
        *pcVar10 = (char)uVar14;
      } while ((char)uVar14 != '\0');
      return;
    }
    param_2 = param_2 + 1;
    if (bVar1 == 0x25) {
      sVar8 = (short)(char)*param_2;
      bVar3 = false;
      uVar12 = 0;
      local_74[0] = ' ';
      uVar14 = uVar12;
      if (*param_2 == 0x30) {
        local_74[0] = '0';
      }
      while ((param_2 = param_2 + 1, 0x2f < sVar8 && (sVar8 < 0x3a))) {
        uVar14 = (uVar14 * 10 + sVar8) - 0x30;
        sVar8 = (short)(char)*param_2;
      }
      uVar13 = 0x7fff;
      if (sVar8 == 0x2e) {
        while( true ) {
          bVar1 = *param_2;
          sVar8 = (short)(char)bVar1;
          param_2 = param_2 + 1;
          sVar9 = (short)(char)bVar1;
          uVar13 = uVar12;
          if ((sVar9 < 0x30) || (0x39 < sVar9)) break;
          uVar12 = (uVar12 * 10 + sVar9) - 0x30;
        }
      }
      if (sVar8 == 0x50) goto LAB_1c00044b7;
      if (sVar8 != 0x58) {
        if (sVar8 == 99) {
          pcVar10 = local_6c;
          local_6c[0] = (char)*param_3;
          local_6c[1] = 0;
          cVar16 = *param_1;
          pcVar5 = param_1;
          while (cVar16 != '\0') {
            pcVar5 = pcVar5 + 1;
            cVar16 = *pcVar5;
          }
          pcVar5 = pcVar5 + -1;
          do {
            cVar16 = *pcVar10;
            pcVar5 = pcVar5 + 1;
            pcVar10 = pcVar10 + 1;
            *pcVar5 = cVar16;
          } while (cVar16 != '\0');
LAB_1c000456f:
          param_3 = param_3 + 1;
          goto LAB_1c00046ad;
        }
        if (sVar8 != 100) {
          if (sVar8 == 0x6c) {
            sVar8 = (short)(char)*param_2;
            param_2 = param_2 + 1;
          }
          else if (sVar8 != 0x70) {
            if (sVar8 == 0x73) {
              pcVar10 = (char *)*param_3;
              cVar16 = *param_1;
              pcVar5 = param_1;
              while (cVar16 != '\0') {
                pcVar5 = pcVar5 + 1;
                cVar16 = *pcVar5;
              }
              pcVar5 = pcVar5 + -1;
              do {
                pcVar5 = pcVar5 + 1;
                *pcVar5 = *pcVar10;
                cVar16 = *pcVar10;
                pcVar10 = pcVar10 + 1;
              } while (cVar16 != '\0');
              goto LAB_1c000456f;
            }
            if ((sVar8 != 0x75) && (sVar8 != 0x78)) {
              local_68[0] = (char)sVar8;
              pcVar10 = local_68;
              local_68[1] = 0;
              cVar16 = *param_1;
              pcVar5 = param_1;
              while (cVar16 != '\0') {
                pcVar5 = pcVar5 + 1;
                cVar16 = *pcVar5;
              }
              pcVar5 = pcVar5 + -1;
              do {
                cVar16 = *pcVar10;
                pcVar5 = pcVar5 + 1;
                pcVar10 = pcVar10 + 1;
                *pcVar5 = cVar16;
              } while (cVar16 != '\0');
              goto LAB_1c00046ad;
            }
            goto LAB_1c00044d2;
          }
LAB_1c00044b7:
          bVar3 = false;
          if ((sVar8 - 0x50U & 0xffdf) == 0) {
            bVar3 = true;
          }
        }
      }
LAB_1c00044d2:
      pcVar10 = local_60;
      cVar16 = '\n';
      if ((sVar8 - 0x50U & 0xffd7) == 0) {
        cVar16 = '\x10';
      }
      if (0x18 < uVar14) {
        local_74[1] = 0;
        do {
          pcVar5 = local_74;
          cVar2 = *param_1;
          pcVar6 = param_1;
          while (cVar2 != '\0') {
            pcVar6 = pcVar6 + 1;
            cVar2 = *pcVar6;
          }
          pcVar6 = pcVar6 + -1;
          do {
            cVar2 = *pcVar5;
            pcVar6 = pcVar6 + 1;
            pcVar5 = pcVar5 + 1;
            *pcVar6 = cVar2;
          } while (cVar2 != '\0');
          uVar14 = uVar14 - 1;
        } while (0x18 < uVar14);
      }
      if (bVar3) {
        uVar15 = *param_3;
      }
      else {
        uVar15 = (ulonglong)(uint)*param_3;
      }
      param_3 = param_3 + 1;
      sVar8 = 0x19;
      do {
        uVar11 = uVar15 % (ulonglong)(longlong)cVar16;
        cVar2 = (char)uVar11;
        cVar4 = cVar2 + '0';
        if (9 < (ushort)uVar11) {
          cVar4 = cVar2 + '7';
        }
        *pcVar10 = cVar4;
        pcVar10 = pcVar10 + 1;
        sVar8 = sVar8 + -1;
        uVar15 = uVar15 / (ulonglong)(longlong)cVar16;
      } while (sVar8 != 0);
      if (0x18 < uVar13) {
        uVar13 = 0x18;
      }
      pcVar10 = local_60 + (short)uVar13;
      sVar8 = 0x19;
      bVar3 = false;
      if (local_60 <= pcVar10) {
        do {
          if (pcVar10 == local_60) {
            local_74[0] = '0';
          }
          if ((((bVar3) || (*pcVar10 != '0')) || (sVar8 <= (short)uVar14)) || (pcVar10 == local_60))
          {
            local_70[0] = *pcVar10;
            bVar3 = true;
            if (local_70[0] == '0') {
              local_70[0] = local_74[0];
            }
            else {
              local_74[0] = '0';
            }
            pcVar5 = local_70;
            local_70[1] = 0;
            cVar16 = *param_1;
            pcVar6 = param_1;
            while (cVar16 != '\0') {
              pcVar6 = pcVar6 + 1;
              cVar16 = *pcVar6;
            }
            pcVar6 = pcVar6 + -1;
            do {
              cVar16 = *pcVar5;
              pcVar6 = pcVar6 + 1;
              pcVar5 = pcVar5 + 1;
              *pcVar6 = cVar16;
            } while (cVar16 != '\0');
          }
          pcVar10 = pcVar10 + -1;
          sVar8 = sVar8 + -1;
        } while (local_60 <= pcVar10);
      }
    }
    else {
      puVar7 = local_78;
      local_78[0] = (ushort)bVar1;
      cVar16 = *param_1;
      pcVar10 = param_1;
      while (cVar16 != '\0') {
        pcVar10 = pcVar10 + 1;
        cVar16 = *pcVar10;
      }
      pcVar10 = pcVar10 + -1;
      do {
        uVar14 = *puVar7;
        pcVar10 = pcVar10 + 1;
        puVar7 = (ushort *)((longlong)puVar7 + 1);
        *pcVar10 = (char)uVar14;
      } while ((char)uVar14 != '\0');
    }
LAB_1c00046ad:
    bVar1 = *param_2;
  } while( true );
}



===== GetFwDebugBuffer @ 1c0004704 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 GetFwDebugBuffer(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  uint uVar3;
  int local_res8 [4];
  int local_res18 [2];
  int local_res20 [2];
  uint uVar4;
  uint local_38 [3];
  int iStack_2c;
  
  *(undefined8 *)(param_1 + 0x5e10) = 0;
  *(undefined8 *)(param_1 + 0x5e18) = 0;
  *(undefined8 *)(param_1 + 0x5e28) = 0;
  *(undefined8 *)(param_1 + 0x5e38) = 0;
  *(undefined8 *)(param_1 + 0x5e30) = 0;
  *(undefined4 *)(param_1 + 0x5e40) = 0;
  *(undefined4 *)(param_1 + 0x5e20) = 0;
  local_res8[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  uVar4 = 0;
  cVar1 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                    (param_1,0x23,0,0,0,0,local_res8,local_res18,local_res20,local_38,local_38 + 1,1
                    );
  if (cVar1 == '\0') {
    return 0;
  }
  if (local_res20[0] == 0) {
    return 0;
  }
  if ((*(short *)(param_1 + 0x158e) == 0x288) ||
     ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3)) {
    uVar3 = local_res8[0] - *(int *)(param_1 + 0x80c0);
    if ((*(int *)(param_1 + 0x80c4) != local_res18[0]) ||
       (*(uint *)(param_1 + 0x80ac) <= uVar3 + local_res20[0])) goto LAB_1c000484d;
    lVar2 = (ulonglong)uVar3 + *(longlong *)(param_1 + 0x1b0);
  }
  else {
    uVar3 = local_res8[0] - *(int *)(param_1 + 0x80b8);
    if ((*(int *)(param_1 + 0x80bc) == local_res18[0]) &&
       (uVar3 + local_res20[0] < *(uint *)(param_1 + 0x80a8))) {
      lVar2 = (ulonglong)uVar3 + *(longlong *)(param_1 + 0x1a8);
    }
    else {
LAB_1c000484d:
      if (param_2 == 0) goto LAB_1c0004881;
      local_38[2] = local_res8[0];
      iStack_2c = local_res18[0];
      lVar2 = StorPortGetDeviceBase
                        (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),
                         CONCAT44(local_res18[0],local_res8[0]),local_res20[0],uVar4 & 0xffffff00);
    }
  }
  *(longlong *)(param_1 + 0x5e10) = lVar2;
LAB_1c0004881:
  lVar2 = *(longlong *)(param_1 + 0x5e10);
  if (lVar2 == 0) {
    return 0;
  }
  *(longlong *)(param_1 + 0x5e28) = lVar2;
  *(longlong *)(param_1 + 0x5e18) = lVar2 + 4;
  *(longlong *)(param_1 + 0x5e38) = lVar2 + 8;
  *(longlong *)(param_1 + 0x5e30) = lVar2 + 9;
  *(int *)(param_1 + 0x5e40) = local_res20[0];
  *(ulonglong *)(param_1 + 0x5e10) = (ulonglong)local_38[0] + lVar2;
  *(undefined4 *)(param_1 + 0x5e20) = 0;
  return 1;
}



===== ArcPrintf @ 1c00048e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ArcPrintf(longlong param_1,uint param_2,byte *param_3,ulonglong param_4)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong local_res20;
  undefined1 local_268 [32];
  uint local_248;
  uint local_244;
  undefined4 local_238;
  undefined2 local_234;
  char local_232;
  char local_231 [505];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_268;
  local_238 = 0x73637241;
  local_234 = 0x7361;
  pcVar4 = &local_232;
  local_232 = '\0';
  if (param_1 != 0) {
    pcVar4 = local_231;
    local_232 = (*(byte *)(param_1 + 0x670) & 0xf) + 0x30;
  }
  *pcVar4 = ':';
  pcVar4[1] = '\0';
  if ((param_1 != 0) && ((*(uint *)(param_1 + 0x5e08) & param_2 & 0xfffffff) != 0)) {
    local_res20 = param_4;
    RealSprintf(pcVar4 + 1,param_3,&local_res20);
    if (((*(uint *)(param_1 + 0x5e08) & 0x10000000) != 0) && ((param_2 & 0x20000000) == 0)) {
      if (*(char *)(param_1 + 0x614) == '\0') {
        StorPortDebugPrint(0,&s__s,&local_238);
      }
      else {
        StorPortDebugPrint(0x21);
      }
    }
    if (((((*(uint *)(param_1 + 0x5e08) & 0x20000000) != 0) && ((param_2 >> 0x1c & 1) == 0)) &&
        (*(int *)(param_1 + 0x5e40) != 0)) && (-1 < (int)*(uint *)(param_1 + 0x5e08))) {
      pcVar4 = (char *)(param_1 + 0x5e44);
      memcpy(pcVar4,&local_238,0x200);
      uVar6 = 0;
      cVar1 = *pcVar4;
      pcVar2 = pcVar4;
      while (cVar1 != '\0') {
        pcVar2 = pcVar2 + 1;
        uVar6 = uVar6 + 1;
        cVar1 = *pcVar2;
      }
      if (*(uint *)(param_1 + 0x5e40) < uVar6) {
        uVar6 = (uint)*(ushort *)(param_1 + 0x5e40);
      }
      uVar3 = 0;
      do {
        if (**(int **)(param_1 + 0x5e28) == 0) break;
        for (local_248 = 0; local_248 < 0x82; local_248 = local_248 + 1) {
          for (local_244 = 0; local_244 < 2; local_244 = local_244 + 1) {
          }
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 250000);
      if (uVar3 < 250000) {
        pcVar2 = *(char **)(param_1 + 0x5e10);
        for (uVar5 = (ulonglong)uVar6; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar2 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          pcVar2 = pcVar2 + 1;
        }
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0x5e18) = *(undefined4 *)(param_1 + 0x5e20);
        **(uint **)(param_1 + 0x5e28) = uVar6;
      }
      else {
        *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) & 0xdfffffff;
      }
    }
  }
  return;
}



===== CheckingFWAfterPowerStateChange @ 1c0004adc =====

void CheckingFWAfterPowerStateChange(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  char *pcVar4;
  ulonglong uVar5;
  bool bVar6;
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28[0] = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  if ((*(uint *)(param_1 + 0xbad8) & 4) == 0) {
    return;
  }
  uVar5 = 0;
  uVar3 = 3;
  lVar2 = param_1;
  StorPortNotification(0x1003);
  bVar6 = DAT_1c001d330 != '\0';
  *(undefined1 *)(param_1 + 0x617) = 1;
  if (bVar6) {
    DAT_1c001d960 = RxGetOMRx0(param_1);
  }
  if ((DAT_1c001d960 & 0x2000) != 0) {
    if ((DAT_1c001d960 & 0xc000) == 0) {
      *(undefined4 *)(param_1 + 0x1d0) = 4;
      RequestTimer(param_1,0x2000,500000,2);
      StorPortNotification(0x1004,param_1,local_28);
      uVar5 = 0x46;
      pcVar4 = 
      "* set timer AGAIN in CheckingFWAfterPowerStateChange because P2A is undergoing, line #%d\n";
      goto LAB_1c0004d88;
    }
    DAT_1c001d928 = DAT_1c001d928 + 1;
    DAT_1c001d330 = '\0';
    if (DAT_1c001d928 < 0x1e) {
      *(undefined4 *)(param_1 + 0x1d0) = 4;
      RequestTimer(param_1,0x2000,500000,2);
      StorPortNotification(0x1004,param_1,local_28);
      uVar5 = 0x59;
      pcVar4 = 
      "* set timer AGAIN in CheckingFWAfterPowerStateChange because we need 10 seconds delay, line #%d\n"
      ;
      goto LAB_1c0004d88;
    }
    if (DAT_1c001d331 != '\0') {
      CheckMSIxPossibility(param_1,lVar2,uVar3,uVar5);
      if (*(char *)(param_1 + 0xaad6) != '\0') {
        *(undefined1 *)(param_1 + 0xaadc) = 1;
      }
      DAT_1c001d331 = '\0';
    }
  }
  if (DAT_1c001d92c == 0xffffffff) {
    DAT_1c001d92c = 0;
  }
  else {
    DAT_1c001d92c = DAT_1c001d92c + 1;
  }
  if (DAT_1c001d92c + (int)((ulonglong)DAT_1c001d92c / 3) * -3 != 2) {
    *(undefined4 *)(param_1 + 0x1d0) = 4;
    RequestTimer(param_1,0x2000,500000,2);
    StorPortNotification(0x1004,param_1,local_28);
    return;
  }
  cVar1 = InitializeAdapterAfterIOPReset(param_1,(ulonglong)DAT_1c001d92c / 3);
  if (cVar1 != '\0') {
    *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xfffffffb;
    *(undefined1 *)(param_1 + 0x619) = 0;
    *(undefined1 *)(param_1 + 0x617) = 0;
    *(undefined4 *)(param_1 + 0x1d0) = 1;
    *(undefined1 *)(param_1 + 0x5e04) = 0;
    DAT_1c001d331 = 1;
    DAT_1c001d330 = 1;
    DAT_1c001d928 = 0;
    DAT_1c001d92c = 0;
    *(undefined4 *)(param_1 + 0x648) = 0;
    StorPortNotification(0x1004,param_1,local_28);
    ArcPrintf(param_1,4,(byte *)"* FW is back from S3/S4. StorPort miniport driver version %s\n",
              0x1c0015d90);
    if ((*(uint *)(param_1 + 0xbad8) & 8) != 0) {
      *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xfffffff7;
    }
    if ((*(uint *)(param_1 + 0xbad8) & 0x10) != 0) {
      *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xffffffef;
    }
    if ((char)*(uint *)(param_1 + 0xbad8) < '\0') {
      *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xffffff7f;
      return;
    }
    return;
  }
  *(undefined4 *)(param_1 + 0x1d0) = 4;
  RequestTimer(param_1,0x2000,500000,2);
  StorPortNotification(0x1004,param_1,local_28);
  uVar5 = 0xc0;
  pcVar4 = "* set timer AGAIN to check the FW status for S3/S4, line #%d\n";
LAB_1c0004d88:
  ArcPrintf(param_1,4,(byte *)pcVar4,uVar5);
  return;
}



===== ChangeIoLimitAndPrintOutstanding @ 1c0004da8 =====

void ChangeIoLimitAndPrintOutstanding(longlong param_1,ulonglong param_2,ulonglong param_3)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  ulonglong uVar4;
  
  sVar2 = GetOutstandingIoCnt(param_1);
  uVar4 = 0;
  if (sVar2 == 0) {
    uVar3 = *(uint *)(param_1 + 0xbad8);
    param_3 = (ulonglong)uVar3;
    if ((uVar3 & 2) != 0) {
      if (*(char *)(param_1 + 0xaad6) == '\0') {
        uVar1 = *(uint *)(param_1 + 0xbae0);
        *(uint *)(param_1 + 0x8074) = uVar1;
        if ((*(uint *)(param_1 + 0x13a0) & 0x10000) == 0) {
          *(undefined4 *)(param_1 + 0x8060) = 0xfe;
        }
        else {
          *(uint *)(param_1 + 0x8060) = uVar1;
          if (1 < uVar1) {
            *(uint *)(param_1 + 0x8060) = uVar1 - 1;
          }
        }
        *(int *)(param_1 + 0x8054) = *(int *)(param_1 + 0x8060) + -1;
        param_2 = (ulonglong)(uint)(*(int *)(param_1 + 0x8060) * 0x5f) / 100;
        *(int *)(param_1 + 0x8058) = (int)param_2;
      }
      else {
        *(undefined2 *)(param_1 + 0xba08) = *(undefined2 *)(param_1 + 0xbae0);
      }
      param_3 = (ulonglong)(uVar3 & 0xfffffffd);
      *(undefined4 *)(param_1 + 0xbae0) = 0;
      *(uint *)(param_1 + 0xbad8) = uVar3 & 0xfffffffd;
      StorPortResume(param_1);
    }
  }
  uVar3 = GetElapsedSeconds(param_1,param_2,param_3,uVar4);
  if (9 < uVar3 - *(int *)(param_1 + 0xbac0)) {
    *(uint *)(param_1 + 0xbac0) = uVar3;
  }
  RequestTimer(param_1,0x1000,1000000,1);
  return;
}



===== StopTimer @ 1c0004e9c =====

void StopTimer(longlong param_1,uint param_2,undefined8 param_3,int param_4)

{
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28[0] = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  if (param_4 != 2) {
    StorPortNotification(0x1003,param_1,3,0,local_28);
  }
  if ((param_2 & *(uint *)(param_1 + 0xbac4)) != 0) {
    *(uint *)(param_1 + 0xbac4) = ~param_2 & *(uint *)(param_1 + 0xbac4);
  }
  if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0xba30) = 0;
  }
  if (param_4 != 2) {
    StorPortNotification(0x1004,param_1,local_28);
  }
  return;
}



===== RequestTimer @ 1c0004f34 =====

void RequestTimer(longlong param_1,uint param_2,uint param_3,int param_4)

{
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28[0] = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  if (param_4 != 2) {
    StorPortNotification(0x1003,param_1,3,0,local_28);
  }
  if ((param_2 & *(uint *)(param_1 + 0xbac4)) == 0) {
    *(uint *)(param_1 + 0xbac4) = *(uint *)(param_1 + 0xbac4) | param_2;
    if ((*(uint *)(param_1 + 0xbac8) == 0) || (param_3 <= *(uint *)(param_1 + 0xbac8))) {
      StorPortNotification(6,param_1,MainTimeThread,param_3);
      *(uint *)(param_1 + 0xbac8) = param_3;
    }
  }
  if (param_4 != 2) {
    StorPortNotification(0x1004,param_1,local_28);
  }
  return;
}



===== MainTimeThread @ 1c0005000 =====

void MainTimeThread(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  byte bVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  ushort local_res8 [4];
  uint local_res10 [2];
  char local_38 [8];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x400;
  bVar6 = 0;
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_30 = 0;
  pcVar9 = (char *)0x0;
  local_28 = 0;
  local_20 = 0;
  StorPortNotification(0x1003,param_1,3,0,local_38);
  uVar3 = *(uint *)(param_1 + 0xbac4);
  pcVar8 = local_38;
  uVar1 = *(uint *)(param_1 + 0xbacc);
  *(undefined8 *)(param_1 + 0xbac4) = 0;
  *(undefined4 *)(param_1 + 0xbacc) = 0;
  lVar4 = param_1;
  StorPortNotification(0x1004);
  if ((uVar3 & 8) != 0) {
    ConfigureContainersTimer(param_1,lVar4,pcVar8,(ulonglong)pcVar9);
  }
  if ((uVar3 >> 0xf & 1) != 0) {
    VMCloseAllCompletionTimer(param_1,lVar4,pcVar8,(ulonglong)pcVar9);
  }
  if ((uVar3 & 2) != 0) {
    SynchFibCompletionTimer(param_1,lVar4,pcVar8,(ulonglong)pcVar9);
  }
  if ((uVar3 & 0x10) != 0) {
    SynchCommandCompletionTimer(param_1,lVar4,pcVar8,(ulonglong)pcVar9);
  }
  uVar5 = 0x40;
  if ((uVar3 & 0x40) != 0) {
    pcVar9 = (char *)0x1;
    pcVar8 = (char *)0xf4240;
    RequestTimer(param_1,0x40,1000000,1);
  }
  if ((uVar3 & 0x20) != 0) {
    Reset_IOP_CompletionTimer(param_1);
  }
  if ((uVar3 & 4) != 0) {
    RestartAdapterPendingTimer(param_1,uVar5,pcVar8,(ulonglong)pcVar9);
  }
  if ((char)uVar3 < '\0') {
    RequestAif(param_1);
  }
  if ((uVar3 >> 8 & 1) != 0) {
    DequeueSortingQTimer(param_1,uVar5,pcVar8,pcVar9);
  }
  if ((uVar3 >> 9 & 1) != 0) {
    uVar2 = GetElapsedSeconds(param_1,uVar5,pcVar8,(ulonglong)pcVar9);
    if (7 < uVar2 - *(int *)(param_1 + 0xba34)) {
      pcVar8 = "DPC-Timeout may happen in StartIo\n";
      uVar5 = 4;
      ArcPrintf(param_1,4,(byte *)"DPC-Timeout may happen in StartIo\n",(ulonglong)pcVar9);
    }
  }
  if ((uVar3 >> 10 & 1) != 0) {
    uVar2 = GetElapsedSeconds(param_1,uVar5,pcVar8,(ulonglong)pcVar9);
    if (7 < uVar2 - *(int *)(param_1 + 0xba38)) {
      pcVar8 = "DPC-Timeout may happen in Timer Service Routine\n";
      uVar5 = 4;
      ArcPrintf(param_1,4,(byte *)"DPC-Timeout may happen in Timer Service Routine\n",
                (ulonglong)pcVar9);
    }
  }
  if ((uVar3 >> 0xb & 1) != 0) {
    uVar2 = GetElapsedSeconds(param_1,uVar5,pcVar8,(ulonglong)pcVar9);
    if (0x1a < uVar2 - *(int *)(param_1 + 0xba3c)) {
      pcVar8 = "DPC-Timeout may happen in ResetAdapter\n";
      uVar5 = 4;
      ArcPrintf(param_1,4,(byte *)"DPC-Timeout may happen in ResetAdapter\n",(ulonglong)pcVar9);
    }
  }
  if ((uVar3 >> 0xc & 1) != 0) {
    ChangeIoLimitAndPrintOutstanding(param_1,uVar5,(ulonglong)pcVar8);
  }
  if ((uVar3 & 1) != 0) {
    local_res10[0] = 0;
    local_res10[0] = GetElapsedSeconds(param_1,uVar5,pcVar8,(ulonglong)pcVar9);
    if (((local_res10[0] != 0) && (0x707 < local_res10[0] - *(int *)(param_1 + 0xba30))) &&
       (*(longlong *)(param_1 + 0x188) == 0)) {
      ArcPrintf(param_1,4,(byte *)"* current ElapsedTime is %x. Driver version %s \n",
                (ulonglong)local_res10[0]);
      SendSynchFib(param_1,0x2c1,local_res10,4,(void *)0x0,local_res8,'\x01');
      *(uint *)(param_1 + 0xba30) = local_res10[0];
    }
    uVar5 = 1;
    pcVar8 = (char *)0xf4240;
    pcVar9 = (char *)0x1;
    RequestTimer(param_1,1,1000000,1);
  }
  if ((uVar3 >> 0xd & 1) != 0) {
    CheckingFWAfterPowerStateChange(param_1);
  }
  do {
    pcVar7 = (char *)(ulonglong)bVar6;
    if ((uVar1 >> (bVar6 & 0x1f) & 1) != 0) {
      uVar3 = GetElapsedSeconds(param_1,uVar5,pcVar8,(ulonglong)pcVar9);
      if (0x22 < uVar3 - *(int *)(param_1 + 0xba40 + (longlong)pcVar7 * 4)) {
        pcVar8 = "DPC-Timeout may happen in MSIX ISR DPC for message #%d\n";
        uVar5 = 4;
        ArcPrintf(param_1,4,(byte *)"DPC-Timeout may happen in MSIX ISR DPC for message #%d\n",
                  (ulonglong)pcVar7);
        pcVar9 = pcVar7;
      }
    }
    bVar6 = bVar6 + 1;
  } while (bVar6 < 0x20);
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xfffffbff;
  return;
}



===== ConfigureContainersTimer @ 1c00052b0 =====

void ConfigureContainersTimer
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  byte bVar1;
  char local_res8 [8];
  char local_res10 [8];
  
  if (*(char *)(param_1 + 0xe2e4) == '\0') {
    *(undefined1 *)(param_1 + 0xe2e4) = 1;
  }
  if (*(char *)(param_1 + 0x6048) != '\0') {
    if (*(longlong *)(param_1 + 0x188) == 0) {
      local_res8[0] = '\0';
      local_res10[0] = '\0';
      bVar1 = ConfigureContainersRuntime(param_1,local_res8,local_res10,param_4);
      if ((local_res8[0] == '\0') && (local_res10[0] != '\0')) {
        if ((bVar1 != 0) || (*(char *)(param_1 + 0x5e06) != '\0')) {
          ArcPrintf(param_1,4,(byte *)"* Send BusChangeDetected to OS in ConfigureContainersTimer\n"
                    ,param_4);
          StorPortNotification(7,param_1);
          *(undefined1 *)(param_1 + 0x5e06) = 0;
        }
        *(undefined4 *)(param_1 + 0x6044) = 0;
        *(undefined1 *)(param_1 + 0x6048) = 0;
        if (*(char *)(param_1 + 0xe2e5) == '\x01') {
          ArcPrintf(param_1,4,
                    (byte *)
                    "* Start a timer to update Container info in ConfigureContainersTimer because of pending timer flag\n"
                    ,param_4);
          *(undefined4 *)(param_1 + 0x6044) = 0;
          *(undefined1 *)(param_1 + 0x6048) = 1;
          RequestTimer(param_1,8,10000,1);
          *(undefined1 *)(param_1 + 0xe2e5) = 0;
          return;
        }
        *(undefined1 *)(param_1 + 0xe2e4) = 0;
        return;
      }
    }
    RequestTimer(param_1,8,10000,1);
  }
  return;
}



===== RestartAdapterPendingTimer @ 1c00053d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RestartAdapterPendingTimer
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  ushort *puVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 local_res8 [8];
  
  if (*(char *)(param_1 + 0x516c) == '\0') {
    return;
  }
  puVar1 = *(ushort **)(param_1 + 0x1a0);
  uVar3 = GetElapsedSeconds(param_1,param_2,param_3,param_4);
  uVar4 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x28))(param_1,local_res8);
  if ((((char)uVar4 < '\0') &&
      (StorPortDebugPrint(0,"OMR value in Check Adapter Health(AdapterIsAlive): 0x%x\n",uVar4),
      *(longlong *)(param_1 + 0x188) == 0)) &&
     (cVar2 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 8))(param_1,uVar3), cVar2 != '\0')) {
    *(undefined8 *)(param_1 + 0x1a0) = 0;
    *(undefined1 *)(param_1 + 0x516c) = 0;
    *(undefined4 *)(param_1 + 0x1d0) = 1;
    *(undefined1 *)(param_1 + 0x5e04) = 0;
    cVar2 = BuildIo(param_1,(longlong)puVar1);
    if (cVar2 == '\0') {
      *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
    }
    else {
      *(short *)(param_1 + 0xba28) = *(short *)(param_1 + 0xba28) + -1;
      StartIo(param_1,puVar1);
    }
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x5170);
    *(uint *)(param_1 + 0x5170) = uVar3 + 1;
    if (uVar3 < 0x79) {
      RequestTimer(param_1,4,1000000,1);
      return;
    }
  }
  if (*(char *)(param_1 + 0x516c) != '\0') {
    *(undefined1 *)((longlong)puVar1 + 3) = 0x11;
    *(undefined8 *)(param_1 + 0x1a0) = 0;
    *(undefined4 *)(param_1 + 0x1d0) = 2;
    *(undefined8 *)(puVar1 + 0x1c) = *(undefined8 *)(*(longlong *)(puVar1 + 0x1c) + 0xa0);
    StorPortNotification(0,param_1,puVar1);
    *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
  }
  return;
}



===== SynchCommandCompletionTimer @ 1c0005540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynchCommandCompletionTimer
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined1 local_res8 [8];
  
  lVar1 = *(longlong *)(param_1 + 0x188);
  lVar2 = *(longlong *)(param_1 + 0x1d8);
  cVar3 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x20))(param_1,local_res8);
  if (cVar3 == '\0') {
    if (*(int *)(param_1 + 0x200) == 0) {
      *(undefined4 *)(param_1 + 0x200) = 3000;
      ArcPrintf(param_1,4,(byte *)"* SynchCommandCompletionTimer: SyncFib time out occurs!!!\n",
                param_4);
    }
    else {
      *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + -1;
    }
    RequestTimer(param_1,0x10,10000,1);
  }
  else {
    memcpy((void *)((longlong)*(uint **)(lVar1 + 0x18) + (ulonglong)**(uint **)(lVar1 + 0x18) + 0x20
                   ),(void *)(lVar2 + 0x20),(ulonglong)*(ushort *)(lVar2 + 8) - 0x20);
    *(undefined8 *)(param_1 + 0x188) = 0;
    *(undefined1 *)(lVar1 + 3) = 1;
    *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(*(longlong *)(lVar1 + 0x38) + 0xa0);
    StorPortNotification(0,param_1,lVar1);
    *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
  }
  return;
}



===== VMCloseAllCompletionTimer @ 1c000562c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VMCloseAllCompletionTimer
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  char cVar2;
  undefined8 uVar3;
  char *pcVar4;
  ushort local_res8 [4];
  undefined1 local_res10 [8];
  uint local_res18 [4];
  
  if (*(char *)(param_1 + 0x5e04) != '\0') goto LAB_1c0005767;
  if (*(longlong *)(param_1 + 0x188) == 0) {
    *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x2000;
    param_4 = 8;
    local_res18[0] = 5;
    local_res18[1] = 0xfffffffe;
    *(undefined8 *)(param_1 + 0xbaf8) = 0;
    *(undefined4 *)(param_1 + 0xbae8) = 0;
    uVar3 = SendSynchFib(param_1,500,local_res18,8,local_res18,local_res8,'\0');
    if ((char)uVar3 != '\0') {
      *(int *)(param_1 + 0xbae8) = *(int *)(param_1 + 0xbae8) + 1;
      *(undefined1 *)(param_1 + 0x5e04) = 1;
      *(undefined8 *)(param_1 + 0x188) = *(undefined8 *)(param_1 + 400);
      *(undefined1 *)(param_1 + 0xe2d4) = 1;
      if (*(char *)(param_1 + 0x8084) == '\0') {
        *(undefined1 *)(param_1 + 0x616) = *(undefined1 *)(param_1 + 0x610);
        *(undefined1 *)(param_1 + 0x610) = 1;
        *(undefined4 *)(param_1 + 0x1d0) = 0;
      }
      goto LAB_1c0005767;
    }
    if (*(int *)(param_1 + 0x200) == 0) {
      *(undefined4 *)(param_1 + 0x200) = 3000;
      pcVar4 = "* VMCloseAllCompletionTimer: sending VM_CloseAll command. time out occurs!!!\n";
      goto LAB_1c0005746;
    }
    *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + -1;
  }
  else if (*(int *)(param_1 + 0x200) == 0) {
    *(undefined4 *)(param_1 + 0x200) = 3000;
    pcVar4 = 
    "* VMCloseAllCompletionTimer: waiting for outstanding synch command. time out occurs!!!\n";
LAB_1c0005746:
    ArcPrintf(param_1,4,(byte *)pcVar4,param_4);
  }
  else {
    *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + -1;
  }
  param_4 = 2;
  RequestTimer(param_1,0x8000,10000,2);
LAB_1c0005767:
  if (*(char *)(param_1 + 0x5e04) != '\0') {
    cVar2 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x20))(param_1,local_res10);
    if (cVar2 == '\0') {
      if (*(int *)(param_1 + 0x200) == 0) {
        *(undefined4 *)(param_1 + 0x200) = 3000;
        ArcPrintf(param_1,4,
                  (byte *)"* VMCloseAllCompletionTimer: SyncFib VM_CloseAll time out occurs!!!\n",
                  param_4);
      }
      else {
        *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + -1;
      }
      RequestTimer(param_1,0x8000,10000,2);
    }
    else {
      lVar1 = *(longlong *)(param_1 + 0x188);
      *(undefined2 *)(lVar1 + 3) = 1;
      if (*(byte *)(lVar1 + 2) == 0x24) {
        ArcPrintf(param_1,4,(byte *)"* VMCloseAllCompletionTimer: SRB_FUNCTION_POWER SRB returned\n"
                  ,param_4);
      }
      else {
        ArcPrintf(param_1,4,
                  (byte *)"* VMCloseAllCompletionTimer: Should not happen! fun:0x%x, cdb[0]:0x%x\n",
                  (ulonglong)*(byte *)(lVar1 + 2));
      }
      *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(*(longlong *)(lVar1 + 0x38) + 0xa0);
      StorPortNotification(0,param_1,lVar1);
      *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
      *(undefined8 *)(param_1 + 400) = 0;
      *(undefined8 *)(param_1 + 0x188) = 0;
      *(undefined1 *)(param_1 + 0xe2d4) = 0;
      *(undefined4 *)(param_1 + 0xbaf8) = 1;
    }
  }
  return;
}



===== SynchFibCompletionTimer @ 1c0005868 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynchFibCompletionTimer
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  char *_Dst;
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  undefined1 local_res8 [8];
  
  lVar1 = *(longlong *)(param_1 + 0x188);
  lVar2 = *(longlong *)(param_1 + 0x1d8);
  cVar3 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x20))(param_1,local_res8);
  if (cVar3 == '\0') {
    if (*(int *)(param_1 + 0x200) == 0) {
      *(undefined4 *)(param_1 + 0x200) = 3000;
      ArcPrintf(param_1,4,(byte *)"* SynchFibCompletionTimer: SyncFib time out occurs!!!\n",param_4)
      ;
    }
    else {
      *(int *)(param_1 + 0x200) = *(int *)(param_1 + 0x200) + -1;
    }
    RequestTimer(param_1,2,10000,1);
  }
  else {
    _Dst = (char *)(param_1 + 0x17a8);
    uVar4 = *(ushort *)(lVar2 + 8) - 0x20;
    memcpy(_Dst,(void *)(lVar2 + 0x20),(ulonglong)uVar4);
    *(byte *)(lVar1 + 3) = (-(*_Dst != '\0') & 3U) + 1;
    if ((*(char *)(lVar1 + 2) == '\0') && (*(char *)(lVar1 + 5) != '\x04')) {
      PostProcessScsiCommand(param_1,lVar1,(longlong)_Dst,uVar4);
    }
    *(undefined8 *)(param_1 + 0x188) = 0;
    *(undefined8 *)(lVar1 + 0x38) = *(undefined8 *)(*(longlong *)(lVar1 + 0x38) + 0xa0);
    StorPortNotification(0,param_1,lVar1);
    *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
    if (*(char *)(param_1 + 0x610) == '\x01') {
      StorPortResume(param_1);
    }
  }
  return;
}



===== Reset_IOP_CompletionTimer @ 1c0005994 =====

void Reset_IOP_CompletionTimer(longlong param_1)

{
  char cVar1;
  char *pcVar2;
  ulonglong uVar3;
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28[0] = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  if (*(char *)(param_1 + 0x618) != '\0') {
    StorPortNotification(0x1003,param_1,3,0,local_28);
    *(undefined1 *)(param_1 + 0x617) = 1;
    if (DAT_1c001d924 == 0xffffffff) {
      DAT_1c001d924 = 0;
    }
    else {
      DAT_1c001d924 = DAT_1c001d924 + 1;
    }
    if (DAT_1c001d924 + (int)((ulonglong)DAT_1c001d924 / 3) * -3 == 2) {
      cVar1 = InitializeAdapterAfterIOPReset(param_1,(ulonglong)DAT_1c001d924 / 3);
      if (cVar1 != '\0') {
        *(undefined2 *)(param_1 + 0x618) = 0;
        *(undefined1 *)(param_1 + 0x617) = 0;
        *(undefined4 *)(param_1 + 0x1d0) = 1;
        *(undefined4 *)(param_1 + 0x648) = 0;
        StorPortNotification(0x1004,param_1,local_28);
        uVar3 = 0x535;
        ArcPrintf(param_1,4,(byte *)"* leaving Reset_IOP_CompletionTimer Routine, line #%d\n",0x535)
        ;
        ArcPrintf(param_1,0x10000100,(byte *)"leaving Reset_IOP_CompletionTimer\n",uVar3);
        ArcPrintf(param_1,4,(byte *)"* RESET IOP done. StorPort miniport driver version %s\n",
                  0x1c0015d90);
        if ((*(uint *)(param_1 + 0xbad8) & 8) != 0) {
          *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xfffffff7;
        }
        if ((*(uint *)(param_1 + 0xbad8) & 0x10) != 0) {
          *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xffffffef;
        }
        if ((char)*(uint *)(param_1 + 0xbad8) < '\0') {
          *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xffffff7f;
          return;
        }
        return;
      }
      *(undefined4 *)(param_1 + 0x1d0) = 4;
      RequestTimer(param_1,0x20,10000000,2);
      StorPortNotification(0x1004,param_1,local_28);
      ArcPrintf(param_1,4,
                (byte *)"* set timer AGAIN to check the FW status for IOP_RESET, line #%d\n",0x54f);
      uVar3 = 0x550;
      pcVar2 = "* leaving Reset_IOP_CompletionTimer Routine, line #%d\n";
    }
    else {
      *(undefined4 *)(param_1 + 0x1d0) = 4;
      RequestTimer(param_1,0x20,10000000,2);
      StorPortNotification(0x1004,param_1,local_28);
      ArcPrintf(param_1,4,
                (byte *)"* set timer AGAIN to check the FW status for IOP_RESET, line #%d\n",0x51f);
      uVar3 = 0x520;
      pcVar2 = "* leaving Reset_IOP_CompletionTimer Routine(no check this time), line #%d\n";
    }
    ArcPrintf(param_1,4,(byte *)pcVar2,uVar3);
    ArcPrintf(param_1,0x10000100,(byte *)"leaving Reset_IOP_CompletionTimer\n",uVar3);
  }
  return;
}



===== RequestAif @ 1c0005bb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RequestAif(longlong param_1)

{
  longlong lVar1;
  undefined4 *_Dst;
  char cVar2;
  longlong *plVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  lVar1 = *(longlong *)(param_1 + 0x1f0);
  plVar3 = (longlong *)(param_1 + 0x6050);
  uVar7 = 0;
  while (*plVar3 != 0) {
    uVar6 = (uint)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    plVar3 = plVar3 + 1;
    if (0x3ff < uVar6) {
      RequestTimer(param_1,0x80,10000,1);
      return;
    }
  }
  *(longlong *)(param_1 + 0x6050 + uVar7 * 8) = lVar1;
  if (((*(longlong *)(param_1 + 0x198) != 0) || (*(int *)(param_1 + 0x1d0) != 1)) ||
     (*(char *)(param_1 + 0x610) != '\0')) {
    RequestTimer(param_1,0x80,10000,1);
    *(undefined8 *)(param_1 + 0x6050 + uVar7 * 8) = 0;
    return;
  }
  *(longlong *)(lVar1 + 0x40) = param_1;
  uVar4 = *(longlong *)(param_1 + 0x1e8) + 0x3f;
  uVar5 = uVar4 & 0xffffffffffffffe0;
  *(ulonglong *)(lVar1 + 0x28) = uVar5;
  *(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)(param_1 + 0x1f8);
  *(int *)(lVar1 + 0x10) =
       *(int *)(lVar1 + 0x10) + (((uint)uVar4 & 0xffffffe0) - *(int *)(param_1 + 0x1e8));
  *(ulonglong *)(param_1 + 0x198) = uVar5;
  _Dst = *(undefined4 **)(lVar1 + 0x28);
  memset(_Dst,0,0x20);
  *(undefined1 *)((longlong)_Dst + 6) = 1;
  _Dst[2] = 0x2000200;
  *_Dst = 0x8000d;
  **(uint **)(lVar1 + 0x28) = **(uint **)(lVar1 + 0x28) | 0x30a0;
  *(undefined2 *)(*(longlong *)(lVar1 + 0x28) + 4) = 700;
  *(uint *)(*(longlong *)(lVar1 + 0x28) + 0xc) = ((uint)uVar7 | 0x800000) << 2;
  *(undefined8 *)(lVar1 + 0x18) = 0;
  *(undefined4 *)(*(longlong *)(lVar1 + 0x28) + 0x20) = 200;
  if ((*(uint *)(param_1 + 0xbad8) & 0x2000) != 0) {
    return;
  }
  cVar2 = (**(code **)(param_1 + 0x80d0))(lVar1);
  if (cVar2 == '\0') {
    *(undefined8 *)(param_1 + 0x6050 + uVar7 * 8) = 0;
    *(undefined8 *)(param_1 + 0x198) = 0;
    return;
  }
  return;
}



===== DequeueSortingQTimer @ 1c0005d38 =====

void DequeueSortingQTimer(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  int *piVar1;
  longlong lVar2;
  short sVar3;
  ulonglong uVar4;
  int *piVar5;
  ushort uVar6;
  longlong *plVar7;
  
  if (*(int *)(param_1 + 55000) != 0) {
    uVar6 = 0;
    plVar7 = (longlong *)(param_1 + 0xbb10);
    piVar5 = (int *)(param_1 + 0xc300);
    do {
      if ((*piVar5 != 0) &&
         (lVar2 = *plVar7, piVar1 = (int *)(lVar2 + 0x74), *piVar1 = *piVar1 + 1,
         1 < *(uint *)(lVar2 + 0x74))) {
        uVar4 = DeQueueSortingQueue(param_1,uVar6);
        if ((char)uVar4 == '\0') {
          param_4 = "ProcessAgeOfSortingQueue";
          ArcPrintf(param_1,4,(byte *)"Dequeue Sorting Queue failed in function of %s\n",0x1c0016310
                   );
        }
      }
      uVar6 = uVar6 + 1;
      piVar5 = piVar5 + 1;
      plVar7 = plVar7 + 1;
    } while (uVar6 < 0xfe);
  }
  sVar3 = GetOutstandingIoCnt(param_1);
  if (sVar3 == 0) {
    if (*(int *)(param_1 + 55000) != 0) {
      uVar4 = DeQueueSortingQueue(param_1,0xffff);
      if ((char)uVar4 == '\0') {
        ArcPrintf(param_1,4,
                  (byte *)
                  "Dequeue Sorting Queue failed when timer goes off, and outstanding IO is non zero. Trigger timer again. But we may see DPC timeout\n"
                  ,(ulonglong)param_4);
        goto LAB_1c0005dd2;
      }
    }
    *(undefined4 *)(param_1 + 0xd6dc) = 0;
  }
  else {
LAB_1c0005dd2:
    RequestTimer(param_1,0x100,1000000,1);
    *(undefined4 *)(param_1 + 0xd6dc) = 1;
  }
  return;
}



===== AllocateConsumerProducerCommArea @ 1c0005e40 =====

ulonglong AllocateConsumerProducerCommArea
                    (longlong param_1,undefined8 param_2,longlong *param_3,undefined1 *param_4,
                    undefined1 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined8 local_res8;
  
  puVar2 = (undefined4 *)0x0;
  uVar11 = 0x4000;
  uVar10 = 0x1000;
  ArcPrintf(param_1,0x10000200,(byte *)"entering AllocateConsumerProducerCommArea\n",
            (ulonglong)param_4);
  if (*(int *)(param_1 + 0x807c) == 0) {
    uVar5 = 0x10000;
    *(undefined4 *)(param_1 + 0x807c) = 0x80;
  }
  else {
    uVar5 = *(int *)(param_1 + 0x807c) << 9;
  }
  uVar12 = 0x4007;
  if (*(char *)(param_1 + 0x516a) != '\0') {
    uVar11 = 0;
    uVar5 = 0x2000;
    uVar12 = 0;
    uVar10 = 0x200;
  }
  uVar11 = -(uint)((*(byte *)(param_1 + 0x13a0) & 0x40) != 0) & uVar11;
  uVar9 = uVar5 + 0x2404 + uVar12 + uVar11 + uVar10;
  uVar6 = uVar9 + *(int *)(param_1 + 0x8098);
  uVar3 = (ulonglong)uVar6;
  if (uVar9 <= uVar6) {
    do {
      puVar2 = (undefined4 *)StorPortGetUncachedExtension(param_1,param_2,uVar3);
      if (puVar2 != (undefined4 *)0x0) break;
      uVar6 = (int)uVar3 - 0x1000;
      uVar3 = (ulonglong)uVar6;
    } while (uVar9 <= uVar6);
  }
  *(undefined4 **)(param_1 + 0x620) = puVar2;
  *(uint *)(param_1 + 0x809c) = (int)uVar3 - uVar9;
  if (puVar2 != (undefined4 *)0x0) {
    ArcPrintf(param_1,1,(byte *)"* ConsumerProducerCommArea, VAddr = %x\n",(ulonglong)puVar2);
    param_4 = &param_5;
    uVar4 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0x620));
    *(undefined8 *)(param_1 + 0x628) = uVar4;
    iVar8 = (int)uVar4;
    if (iVar8 != 0) {
      if (uVar11 != 0) {
        uVar11 = uVar11 - (uVar11 - 1 & (uint)puVar2);
        puVar2 = (undefined4 *)((longlong)puVar2 + (ulonglong)uVar11);
        iVar8 = iVar8 + uVar11;
      }
      *(int *)(param_1 + 0x638) = iVar8;
      *(undefined4 **)(param_1 + 0x630) = puVar2;
      *puVar2 = 3;
      puVar2[1] = 1;
      puVar2[2] = 1;
      iVar1 = -((uint)(puVar2 + 0x14) & 0xf);
      lVar7 = (longlong)(puVar2 + 0x14) + (ulonglong)(iVar1 + 0x10);
      iVar8 = iVar8 + iVar1 + 0x60;
      puVar2[3] = iVar8;
      iVar8 = iVar8 + 0x2140;
      *param_3 = lVar7;
      lVar7 = (ulonglong)uVar10 + 0x2140 + lVar7;
      puVar2[6] = iVar8 - *(int *)(param_1 + 0x628);
      puVar2[5] = iVar8;
      puVar2[7] = uVar10;
      puVar2[8] = 0x200;
      *(longlong *)(param_1 + 0x690) = lVar7;
      puVar2[9] = iVar8 + uVar10;
      iVar8 = iVar8 + uVar10 + 100;
      puVar2[10] = 0x60;
      local_res8._4_4_ = (undefined4)((ulonglong)uVar4 >> 0x20);
      local_res8 = CONCAT44(local_res8._4_4_,iVar8);
      *(ulonglong *)(param_1 + 0x1e0) = local_res8;
      *(longlong *)(param_1 + 0x19b0) = lVar7 + 0x264;
      *(longlong *)(param_1 + 0x1d8) = lVar7 + 100;
      *(uint *)(param_1 + 0x19ac) = uVar5 >> 9;
      if (uVar12 != 0) {
        *(uint *)(param_1 + 0x210) = uVar12 - 7;
        *(ulonglong *)(param_1 + 0x208) =
             (uVar3 - uVar12) + *(longlong *)(param_1 + 0x620) + 7 & 0xfffffffffffffff8;
      }
      local_res8 = CONCAT44(local_res8._4_4_,uVar5 + 0x200 + iVar8 + uVar12);
      *(ulonglong *)(param_1 + 0x80a0) = local_res8;
      if (((*(uint *)(param_1 + 0x13a0) & 0x40) == 0) &&
         (local_res8 = (ulonglong)(0x7fffffff - (int)uVar3),
         (longlong)local_res8 < *(longlong *)(param_1 + 0x628))) {
        *(undefined1 *)(param_1 + 0x615) = 1;
        ArcPrintf(param_1,1,(byte *)"* Adapter got an invalid host memory window\n",
                  (ulonglong)param_4);
      }
      uVar4 = ArcPrintf(param_1,0x10000200,
                        (byte *)"leaving AllocateConsumerProducerCommArea, rtnval = TRUE\n",
                        (ulonglong)param_4);
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
  }
  uVar3 = ArcPrintf(param_1,0x10000200,
                    (byte *)"leaving AllocateConsumerProducerCommArea, rtnval = FALSE\n",
                    (ulonglong)param_4);
  return uVar3 & 0xffffffffffffff00;
}



===== AllocateMessageUnitQueueCommArea @ 1c0006138 =====

ulonglong AllocateMessageUnitQueueCommArea
                    (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 local_res8 [2];
  undefined8 local_res18;
  
  local_res8[0] = 0;
  uVar10 = 0;
  uVar7 = 0;
  ArcPrintf(param_1,0x10000200,(byte *)"entering AllocateMessageUnitQueueCommArea\n",param_4);
  if (*(int *)(param_1 + 0x807c) == 0) {
    uVar8 = 0x10000;
    *(undefined4 *)(param_1 + 0x807c) = 0x80;
  }
  else {
    uVar8 = *(int *)(param_1 + 0x807c) << 9;
  }
  if (*(int *)(param_1 + 0x210) == 0) {
    uVar11 = 0x4007;
  }
  else {
    uVar11 = *(int *)(param_1 + 0x210) + 7;
    *(undefined4 *)(param_1 + 0x210) = 0;
  }
  if (*(char *)(param_1 + 0x516a) != '\0') {
    uVar8 = 0x2000;
    uVar11 = 0;
  }
  if (*(char *)(param_1 + 0x80e2) != '\0') {
    iVar6 = (uVar8 >> 9) + *(int *)(param_1 + 0x8074) + 1;
    *(int *)(param_1 + 0x80e4) = iVar6;
    uVar10 = iVar6 * 4;
  }
  if (*(int *)(param_1 + 0x8088) - 1U < 2) {
    uVar7 = *(int *)(param_1 + 0x8074) << 2;
  }
  uVar12 = uVar8 + 0x571 + uVar11 + uVar7 + uVar10;
  uVar4 = (ulonglong)uVar12;
  puVar3 = (undefined4 *)StorPortGetUncachedExtension(param_1,param_2,uVar4);
  if (puVar3 == (undefined4 *)0x0) {
    ArcPrintf(param_1,1,
              (byte *)
              "* AllocateMessageUnitQueueCommArea, Fail to allocate normal uncached extension with size = %x\n"
              ,(ulonglong)uVar12);
    uVar4 = (ulonglong)(uVar7 + 0x156e);
    *(undefined1 *)(param_1 + 0x80e2) = 0;
    uVar11 = 0;
    uVar8 = 0x1000;
    puVar3 = (undefined4 *)StorPortGetUncachedExtension(param_1,param_2,uVar4);
  }
  *(undefined4 **)(param_1 + 0x620) = puVar3;
  ArcPrintf(param_1,1,(byte *)"* AllocateMessageUnitQueueCommArea TotalSizeAllocated = %x\n",uVar4);
  puVar9 = (undefined4 *)0x0;
  if (*(ulonglong *)(param_1 + 0x620) != 0) {
    ArcPrintf(param_1,1,(byte *)"* AllocateMessageUnitQueueCommArea, VAddr = %x\n",
              *(ulonglong *)(param_1 + 0x620));
    memset(*(void **)(param_1 + 0x620),0,uVar4);
    puVar9 = local_res8;
    uVar5 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0x620));
    *(undefined8 *)(param_1 + 0x628) = uVar5;
    iVar6 = (int)uVar5;
    if (iVar6 != 0) {
      if (*(char *)(param_1 + 0x80e2) != '\0') {
        lVar2 = *(longlong *)(param_1 + 0x620);
        *(longlong *)(param_1 + 0x80f0) = lVar2;
        *(longlong *)(param_1 + 33000) = lVar2;
        *(undefined8 *)(param_1 + 0x8100) = uVar5;
        *(ulonglong *)(param_1 + 0x80f8) = lVar2 + (ulonglong)*(uint *)(param_1 + 0x80e4) * 4;
        puVar3 = (undefined4 *)((longlong)puVar3 + (ulonglong)uVar10);
        iVar6 = iVar6 + uVar10;
      }
      iVar1 = *(int *)(param_1 + 0x8088);
      if (iVar1 - 1U < 2) {
        *(undefined4 **)(param_1 + 0x640) = puVar3;
        puVar3 = (undefined4 *)((longlong)puVar3 + (ulonglong)uVar7);
        *(int *)(param_1 + 0x650) = iVar6;
        iVar6 = iVar6 + uVar7;
      }
      *(undefined4 **)(param_1 + 0x630) = puVar3;
      *(int *)(param_1 + 0x638) = iVar6;
      if (iVar1 == 1) {
        puVar3[0xd] = puVar3[0xd] | 0x41;
        *puVar3 = 6;
        puVar3[0x12] = *(undefined4 *)(param_1 + 0x650);
        puVar3[0x13] = *(undefined4 *)(param_1 + 0x654);
      }
      else if (iVar1 == 2) {
        puVar3[0xd] = puVar3[0xd] | 0x101;
        *puVar3 = 7;
        puVar3[0x12] = *(undefined4 *)(param_1 + 0x650);
        puVar3[0x13] = *(undefined4 *)(param_1 + 0x654);
        puVar3[1] = 0;
      }
      else {
        *puVar3 = 4;
        if (*(char *)(param_1 + 0x80e0) == '\0') {
          puVar3[0xd] = puVar3[0xd] | 1;
        }
        else {
          puVar3[0xd] = puVar3[0xd] | 3;
        }
      }
      puVar3[0xe] = *(undefined4 *)(param_1 + 0x8074);
      puVar3[0xf] = *(undefined4 *)(param_1 + 0x8064);
      puVar3[0x10] = *(undefined4 *)(param_1 + 0x8068);
      local_res18._4_4_ = (undefined4)((ulonglong)uVar5 >> 0x20);
      local_res18 = CONCAT44(local_res18._4_4_,iVar6 + 0x50);
      puVar3[0x11] = uVar8 >> 9;
      *(undefined4 **)(param_1 + 0x1d8) = puVar3 + 0x14;
      *(undefined8 *)(param_1 + 0x1e0) = local_res18;
      *(longlong *)(param_1 + 0x1e8) = (longlong)puVar3 + 0x28f;
      local_res18 = CONCAT44(local_res18._4_4_,iVar6 + 0x28f);
      *(undefined8 *)(param_1 + 0x1f8) = local_res18;
      *(longlong *)(param_1 + 0x1f0) = (longlong)puVar3 + 0x4ce;
      *(longlong *)(param_1 + 0x19b0) = (longlong)puVar3 + 0x56e;
      *(uint *)(param_1 + 0x19ac) = uVar8 >> 9;
      if (uVar11 != 0) {
        *(uint *)(param_1 + 0x210) = uVar11 - 7;
        *(ulonglong *)(param_1 + 0x208) =
             *(longlong *)(param_1 + 0x620) + 7 + (uVar4 - uVar11) & 0xfffffffffffffff8;
      }
      uVar5 = ArcPrintf(param_1,0x10000200,
                        (byte *)"leaving AllocateMessageUnitQueueCommArea, rtnval = TRUE\n",
                        (ulonglong)puVar9);
      return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
    }
  }
  uVar4 = ArcPrintf(param_1,0x10000200,
                    (byte *)"leaving AllocateMessageUnitQueueCommArea, rtnval = FALSE\n",
                    (ulonglong)puVar9);
  return uVar4 & 0xffffffffffffff00;
}



===== DynamicallyThrottleLunQueueDepth @ 1c00064a8 =====

uint DynamicallyThrottleLunQueueDepth(longlong param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  longlong lVar5;
  undefined7 uVar6;
  uint uVar7;
  undefined1 uVar8;
  ulonglong uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  iVar13 = 0;
  iVar11 = 0;
  iVar12 = 0;
  iVar10 = 0;
  uVar3 = 0xfe;
  if (*(char *)(param_1 + 0xaad6) == '\0') {
    uVar7 = 0xfe;
  }
  else {
    uVar7 = *(int *)(param_1 + 0xba0c) - 1;
  }
  lVar5 = 0xfe;
  if (0xfe < uVar7) {
    uVar7 = 0xfe;
  }
  piVar4 = (int *)(param_1 + 0x19d4);
  do {
    iVar1 = *piVar4;
    if ((iVar1 != 0) && (piVar4[-2] == 1)) {
      if (iVar1 == 8) {
        iVar13 = iVar13 + 1;
      }
      else if (iVar1 == 1) {
        iVar11 = iVar11 + 1;
      }
      else if (iVar1 == 2) {
        iVar10 = iVar10 + 1;
      }
      else {
        iVar12 = iVar12 + 1;
      }
    }
    piVar4 = piVar4 + 10;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar9 = 0;
  do {
    iVar1 = *(int *)(param_1 + 0x19d4 + uVar9 * 0x28);
    if (iVar1 != 0) {
      uVar8 = (undefined1)uVar9;
      if (((iVar13 == 0) || (iVar1 != 8)) && ((iVar11 == 0 || (iVar1 != 1)))) {
        if ((iVar10 == 0) || (iVar1 != 2)) {
          if ((iVar12 != 0) && ((iVar1 != 8 && (1 < iVar1 - 1U)))) {
            if ((param_2 == 0xffff) && (*(char *)(param_1 + 0x19c8 + uVar9 * 0x28) == '\x01')) {
              StorPortSetDeviceQueueDepth(param_1,4,uVar8,0,uVar7);
            }
            uVar3 = uVar7;
          }
        }
        else {
          if ((param_2 == 0xffff) && (*(char *)(param_1 + 0x19c8 + uVar9 * 0x28) == '\x01')) {
            StorPortSetDeviceQueueDepth(param_1,4,uVar8,0,0x40);
          }
          uVar3 = 0x40;
        }
LAB_1c0006706:
        if (param_2 == 0xffff) goto LAB_1c000671c;
      }
      else {
        uVar3 = 0x10;
        if ((iVar13 != 0) || (iVar11 != 0)) {
          uVar2 = *(int *)(param_1 + 0x8074) - 1;
          uVar3 = uVar2 / (uint)(iVar11 + iVar13);
          uVar6 = (undefined7)((ulonglong)uVar2 % (ulonglong)(uint)(iVar11 + iVar13) >> 8);
          if (uVar3 < 0x21) {
            if (1 < uVar3) goto LAB_1c000662c;
            if ((param_2 == 0xffff) && (*(char *)(param_1 + 0x19c8 + uVar9 * 0x28) == '\x01')) {
              StorPortSetDeviceQueueDepth(param_1,CONCAT71(uVar6,4),uVar8,0,2);
            }
            uVar3 = 2;
          }
          else {
            if ((param_2 == 0xffff) && (*(char *)(param_1 + 0x19c8 + uVar9 * 0x28) == '\x01')) {
              StorPortSetDeviceQueueDepth(param_1,CONCAT71(uVar6,4),uVar8,0,0x20);
            }
            uVar3 = 0x20;
          }
          goto LAB_1c0006706;
        }
LAB_1c000662c:
        if (param_2 == 0xffff) {
          if (*(char *)(param_1 + 0x19c8 + uVar9 * 0x28) == '\x01') {
            StorPortSetDeviceQueueDepth(param_1,4,uVar8,0,uVar3);
          }
          goto LAB_1c0006706;
        }
      }
      if (*(int *)(param_1 + 0x19e4 + (ulonglong)param_2 * 0x28) == (int)uVar9) {
        return uVar3;
      }
    }
LAB_1c000671c:
    uVar2 = (int)uVar9 + 1;
    uVar9 = (ulonglong)uVar2;
    if (0xfd < uVar2) {
      return uVar3;
    }
  } while( true );
}



===== ConfigureContainersInit @ 1c0006748 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

byte ConfigureContainersInit
               (longlong param_1,undefined1 *param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  undefined1 *puVar2;
  uint *puVar3;
  int *piVar4;
  longlong lVar5;
  int *piVar6;
  uint *puVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined1 auStackY_2e8 [32];
  byte local_2a8;
  ushort local_2a4 [2];
  int local_2a0;
  uint local_29c;
  uint local_298;
  int local_294;
  uint local_290;
  int local_288 [2];
  uint local_280;
  uint local_258;
  int local_254;
  uint local_24c;
  undefined8 local_248;
  int local_224;
  uint local_218 [3];
  uint local_20c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2e8;
  local_2a0 = 0;
  local_2a8 = 0;
  bVar8 = 0;
  ArcPrintf(param_1,0x10000200,(byte *)"entering ConfigureContainersInit\n",param_4);
  *param_2 = 0;
  if (*(longlong *)(param_1 + 0x188) == 0) {
    if (*(char *)(param_1 + 0x15a7) == '\0') {
      local_298 = (-(uint)(*(char *)(param_1 + 0x15a6) != '\0') & 0x15) + 1;
    }
    else {
      local_298 = 0x1e;
    }
    local_290 = 0;
    local_294 = (-(uint)(*(char *)(param_1 + 0x15a7) != '\0') & 0xfffffffb) + 8;
    uVar1 = SendSynchFib(param_1,500,&local_298,0xc,local_288,local_2a4,'\x01');
    if ((char)uVar1 == '\0') {
      *param_2 = 1;
      return 0;
    }
    puVar2 = (undefined1 *)(param_1 + 0x19c8);
    lVar11 = 0xfe;
    local_29c = local_280;
    lVar5 = 0xfe;
    do {
      if (*(int *)(puVar2 + 4) == 1) {
        *puVar2 = 0;
      }
      puVar2 = puVar2 + 0x28;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    uVar14 = 0;
    uVar10 = local_280;
    iVar13 = 0;
    if (local_280 != 0) {
      do {
        if (*(char *)(param_1 + 0x15a7) == '\0') {
          local_298 = (-(uint)(*(char *)(param_1 + 0x15a6) != '\0') & 0x15) + 1;
        }
        else {
          local_298 = 0x1e;
        }
        local_294 = (-(uint)(*(char *)(param_1 + 0x15a7) != '\0') & 0xfffffffb) + 8;
        local_290 = uVar14;
        uVar1 = SendSynchFib(param_1,500,&local_298,0xc,local_288,local_2a4,'\x01');
        if (((((char)uVar1 != '\0') && (local_288[0] == 0)) && (local_254 != 0)) &&
           ((local_24c & 4) == 0)) {
          if (*(char *)(param_1 + 0x15a7) == '\0') {
            local_248 = 0x200;
          }
          local_218[0] = 2;
          local_218[1] = 0xa5;
          local_218[2] = uVar14;
          uVar1 = SendSynchFib(param_1,500,local_218,0x1d0,local_218,local_2a4,'\x01');
          if ((char)uVar1 != '\0') {
            if ((local_218[2] != 0xda) || (uVar12 = local_20c, local_254 == 8)) {
              uVar12 = uVar14;
            }
            puVar7 = (uint *)(param_1 + 0x19cc);
            uVar9 = 0;
            puVar3 = puVar7;
            do {
              if ((puVar3[5] == uVar12) && ((*puVar3 & 5) != 0)) {
                lVar5 = (longlong)(int)uVar9;
                if (uVar12 != *(uint *)(param_1 + 0x19e0 + lVar5 * 0x28)) {
                  ArcPrintf(param_1,2,
                            (byte *)"ConfigureContainersInit: UID change for container %d!\n",
                            (ulonglong)*(uint *)(param_1 + 0x19e4 + lVar5 * 0x28));
                }
                if (*(uint *)(param_1 + 0x19e4 + lVar5 * 0x28) != uVar14) {
                  *(uint *)(param_1 + 0x19e4 + lVar5 * 0x28) = uVar14;
                  local_2a8 = 1;
                }
                *(uint *)(param_1 + 0x19d0 + lVar5 * 0x28) = local_24c;
                *(int *)(param_1 + 0x19d4 + lVar5 * 0x28) = local_254;
                if (*(char *)(param_1 + 0x15a6) == '\0') {
                  if (*(ulonglong *)(param_1 + 0x19d8 + lVar5 * 0x28) != (ulonglong)local_258) {
                    *(ulonglong *)(param_1 + 0x19d8 + lVar5 * 0x28) = (ulonglong)local_258;
                    goto LAB_1c0006acd;
                  }
                }
                else if ((*(uint *)(param_1 + 0x19d8 + lVar5 * 0x28) != local_258) ||
                        (*(int *)(param_1 + 0x19dc + lVar5 * 0x28) != local_224)) {
                  *(uint *)(param_1 + 0x19d8 + lVar5 * 0x28) = local_258;
                  *(int *)(param_1 + 0x19dc + lVar5 * 0x28) = local_224;
LAB_1c0006acd:
                  local_2a8 = 1;
                }
                *(undefined4 *)(param_1 + 0x19e8 + lVar5 * 0x28) = (undefined4)local_248;
                *(undefined4 *)(param_1 + 0x19ec + lVar5 * 0x28) = local_248._4_4_;
                *(uint *)(param_1 + 0x19e0 + lVar5 * 0x28) = uVar12;
                uVar10 = local_29c;
                goto LAB_1c0006b4e;
              }
              uVar9 = uVar9 + 1;
              puVar3 = puVar3 + 10;
            } while (uVar9 < 0xfe);
            uVar9 = 0;
            puVar3 = puVar7;
            do {
              if (*puVar3 == 0) goto LAB_1c00069cf;
              uVar9 = uVar9 + 1;
              puVar3 = puVar3 + 10;
            } while (uVar9 < 0xfe);
            lVar5 = 0xfe;
            puVar3 = puVar7;
            do {
              if (*puVar3 == 2) {
                *puVar3 = 0;
              }
              puVar3 = puVar3 + 10;
              lVar5 = lVar5 + -1;
            } while (lVar5 != 0);
            uVar9 = 0;
            do {
              if (*puVar7 == 0) goto LAB_1c00069cf;
              uVar9 = uVar9 + 1;
              puVar7 = puVar7 + 10;
            } while (uVar9 < 0xfe);
            uVar9 = 0xffffffff;
LAB_1c00069cf:
            if (uVar9 != 0xffffffff) {
              lVar5 = (longlong)(int)uVar9;
              *(undefined4 *)(param_1 + 0x19cc + lVar5 * 0x28) = 1;
              *(uint *)(param_1 + 0x19e4 + lVar5 * 0x28) = uVar14;
              *(uint *)(param_1 + 0x19d0 + lVar5 * 0x28) = local_24c;
              *(int *)(param_1 + 0x19d4 + lVar5 * 0x28) = local_254;
              if (*(char *)(param_1 + 0x15a6) == '\0') {
                *(ulonglong *)(param_1 + 0x19d8 + lVar5 * 0x28) = (ulonglong)local_258;
              }
              else {
                *(uint *)(param_1 + 0x19d8 + lVar5 * 0x28) = local_258;
                *(int *)(param_1 + 0x19dc + lVar5 * 0x28) = local_224;
              }
              *(undefined4 *)(param_1 + 0x19e8 + lVar5 * 0x28) = (undefined4)local_248;
              *(undefined4 *)(param_1 + 0x19ec + lVar5 * 0x28) = local_248._4_4_;
              *(uint *)(param_1 + 0x19e0 + lVar5 * 0x28) = uVar12;
              local_2a8 = 1;
              ArcPrintf(param_1,4,
                        (byte *)
                        "* Found a new container - tid: %d , ctid: %x , uid %d, capacity: %p\n",
                        (ulonglong)uVar9);
LAB_1c0006b4e:
              if (uVar9 != 0xffffffff) {
                *(undefined1 *)(param_1 + 0x19c8 + lVar5 * 0x28) = 1;
              }
            }
          }
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < uVar10);
      bVar8 = local_2a8;
      iVar13 = local_2a0;
    }
    piVar6 = (int *)(param_1 + 0x19cc);
    lVar5 = 0xfe;
    piVar4 = piVar6;
    do {
      if ((*piVar4 == 1) && ((char)piVar4[-1] == '\0')) {
        *piVar4 = 2;
        bVar8 = 1;
      }
      piVar4 = piVar4 + 10;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    do {
      if (*piVar6 == 1) {
        iVar13 = iVar13 + 1;
      }
      piVar6 = piVar6 + 10;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
    if ((*(char *)(param_1 + 0x613) != '\0') && (*(char *)(param_1 + 0xbad0) == '\x01')) {
      DynamicallyThrottleLunQueueDepth(param_1,0xffff);
    }
    *(int *)(param_1 + 0x51e8) = iVar13;
  }
  ArcPrintf(param_1,0x10000200,(byte *)"leaving ConfigureContainersInit, rtnval = %d\n",
            (ulonglong)bVar8);
  return bVar8;
}



===== ConfigureContainersRuntime @ 1c0006c2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte ConfigureContainersRuntime
               (longlong param_1,undefined1 *param_2,undefined1 *param_3,ulonglong param_4)

{
  byte bVar1;
  undefined8 uVar2;
  uint *puVar3;
  longlong lVar4;
  undefined1 *puVar5;
  uint *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  char *pcVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  int *piVar15;
  undefined1 auStackY_278 [32];
  uint local_238;
  int local_234;
  undefined1 *local_230;
  uint local_228;
  int local_224;
  uint local_220;
  uint local_218 [3];
  uint local_20c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_278;
  uVar8 = 0;
  local_230 = param_3;
  ArcPrintf(param_1,0x10000200,(byte *)"entering ConfigureContainersRuntime\n",param_4);
  *param_2 = 0;
  *param_3 = 0;
  if (DAT_1c001d948 == 0) {
    DAT_1c001d948 = param_1;
  }
  if (DAT_1c001d948 != param_1) goto LAB_1c0006ca0;
  if (*(longlong *)(param_1 + 0x188) == 0) {
    if (*(char *)(param_1 + 0x15a7) == '\0') {
      local_228 = (-(uint)(*(char *)(param_1 + 0x15a6) != '\0') & 0x15) + 1;
    }
    else {
      local_228 = 0x1e;
    }
    local_220 = 0;
    local_224 = (-(uint)(*(char *)(param_1 + 0x15a7) != '\0') & 0xfffffffb) + 8;
    if (DAT_1c001d934 == '\0') {
      uVar2 = SendSynchFib(param_1,500,&local_228,0xc,&DAT_1c001d970,(ushort *)&local_238,'\x01');
      if ((char)uVar2 == '\0') goto LAB_1c0006ca0;
      DAT_1c001d938 = DAT_1c001d978;
      ArcPrintf(param_1,4,
                (byte *)"* ConfigureContainersRuntime: Rescan started. %d RAID volumes reported \n",
                (ulonglong)DAT_1c001d978);
      DAT_1c001d934 = '\x01';
    }
    bVar1 = DAT_1c001d951;
    if (DAT_1c001d951 == 0) {
      puVar5 = (undefined1 *)(param_1 + 0x19c8);
      lVar7 = 0xfe;
      do {
        if (*(int *)(puVar5 + 4) == 1) {
          *puVar5 = 0;
        }
        puVar5 = puVar5 + 0x28;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
    if (bVar1 < DAT_1c001d938) {
      DAT_1c001d951 = bVar1 + 1;
      if (DAT_1c001d93c == 0) {
        memset(&DAT_1c001d970,0,0x68);
        if (*(char *)(param_1 + 0x15a7) == '\0') {
          local_228 = (-(uint)(*(char *)(param_1 + 0x15a6) != '\0') & 0x15) + 1;
        }
        else {
          local_228 = 0x1e;
        }
        local_224 = (-(uint)(*(char *)(param_1 + 0x15a7) != '\0') & 0xfffffffb) + 8;
        local_220 = (uint)bVar1;
        uVar2 = SendSynchFib(param_1,500,&local_228,0xc,&DAT_1c001d970,(ushort *)&local_238,'\x01');
        if ((char)uVar2 != '\0') goto LAB_1c0006e4a;
LAB_1c0006e3f:
        DAT_1c001d951 = DAT_1c001d951 - 1;
LAB_1c0006ca0:
        bVar1 = DAT_1c001d950;
        *param_2 = 1;
        return bVar1;
      }
LAB_1c0006e4a:
      uVar12 = (uint)bVar1;
      if (((DAT_1c001d970 == 0) && (DAT_1c001d9a4 != 0)) && ((DAT_1c001d9ac & 4) == 0)) {
        if (*(char *)(param_1 + 0x15a7) == '\0') {
          _DAT_1c001d9b0 = 0x200;
        }
        local_218[0] = 2;
        local_218[1] = 0xa5;
        uVar11 = (uint)bVar1;
        local_218[2] = uVar11;
        uVar2 = SendSynchFib(param_1,500,local_218,0x1d0,local_218,(ushort *)&local_238,'\x01');
        if ((char)uVar2 == '\0') {
          DAT_1c001d93c = 1;
          goto LAB_1c0006e3f;
        }
        if ((local_218[2] == 0xda) && (DAT_1c001d9a4 != 8)) {
          pcVar9 = "* ConfigureContainersRuntime: Get CtUid (case #1) for disk %d: 0x%x\n";
          local_238 = local_20c;
        }
        else {
          pcVar9 = "* ConfigureContainersRuntime: Get CtUid (case #2) for disk %d: 0x%x\n";
          local_238 = uVar11;
        }
        ArcPrintf(param_1,4,(byte *)pcVar9,(ulonglong)uVar12);
        puVar6 = (uint *)(param_1 + 0x19cc);
        DAT_1c001d93c = 0;
        uVar13 = 0;
        puVar3 = puVar6;
        do {
          if ((puVar3[5] == local_238) && ((*puVar3 & 5) != 0)) {
            lVar7 = (longlong)(int)uVar13;
            if (local_238 != *(uint *)(param_1 + 0x19e0 + lVar7 * 0x28)) {
              ArcPrintf(param_1,2,
                        (byte *)"ConfigureContainersRuntime: UID change for container %d!\n",
                        (ulonglong)*(uint *)(param_1 + 0x19e4 + lVar7 * 0x28));
            }
            if (*(uint *)(param_1 + 0x19e4 + lVar7 * 0x28) != uVar11) {
              *(uint *)(param_1 + 0x19e4 + lVar7 * 0x28) = uVar11;
              DAT_1c001d950 = 1;
            }
            *(uint *)(param_1 + 0x19d0 + lVar7 * 0x28) = DAT_1c001d9ac;
            *(int *)(param_1 + 0x19d4 + lVar7 * 0x28) = DAT_1c001d9a4;
            if (*(char *)(param_1 + 0x15a6) == '\0') {
              if (*(ulonglong *)(param_1 + 0x19d8 + lVar7 * 0x28) != (ulonglong)DAT_1c001d9a0) {
                *(ulonglong *)(param_1 + 0x19d8 + lVar7 * 0x28) = (ulonglong)DAT_1c001d9a0;
                goto LAB_1c00070cd;
              }
            }
            else if ((*(uint *)(param_1 + 0x19d8 + lVar7 * 0x28) != DAT_1c001d9a0) ||
                    (*(int *)(param_1 + 0x19dc + lVar7 * 0x28) != DAT_1c001d9d4)) {
              *(uint *)(param_1 + 0x19d8 + lVar7 * 0x28) = DAT_1c001d9a0;
              *(int *)(param_1 + 0x19dc + lVar7 * 0x28) = DAT_1c001d9d4;
LAB_1c00070cd:
              DAT_1c001d950 = 1;
            }
            *(undefined4 *)(param_1 + 0x19e8 + lVar7 * 0x28) = DAT_1c001d9b0;
            *(undefined4 *)(param_1 + 0x19ec + lVar7 * 0x28) = DAT_1c001d9b4;
            *(uint *)(param_1 + 0x19e0 + lVar7 * 0x28) = local_238;
            lVar7 = (longlong)(int)uVar13;
            goto LAB_1c0007162;
          }
          uVar13 = uVar13 + 1;
          puVar3 = puVar3 + 10;
        } while (uVar13 < 0xfe);
        uVar13 = 0;
        puVar3 = puVar6;
        do {
          if (*puVar3 == 0) goto LAB_1c0006fa7;
          uVar13 = uVar13 + 1;
          puVar3 = puVar3 + 10;
        } while (uVar13 < 0xfe);
        lVar7 = 0xfe;
        puVar3 = puVar6;
        do {
          if (*puVar3 == 2) {
            *puVar3 = 0;
          }
          puVar3 = puVar3 + 10;
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        uVar13 = 0;
        do {
          if (*puVar6 == 0) goto LAB_1c0006fa7;
          uVar13 = uVar13 + 1;
          puVar6 = puVar6 + 10;
        } while (uVar13 < 0xfe);
        uVar13 = 0xffffffff;
        ArcPrintf(param_1,4,
                  (byte *)
                  "* ConfigureContainersRuntime: no free slot found for RAID volume(ctUid=%d)\n",
                  (ulonglong)local_238);
LAB_1c0006fa7:
        if (uVar13 != 0xffffffff) {
          lVar7 = (longlong)(int)uVar13;
          *(undefined4 *)(param_1 + 0x19cc + lVar7 * 0x28) = 1;
          *(uint *)(param_1 + 0x19e4 + lVar7 * 0x28) = uVar12;
          *(uint *)(param_1 + 0x19d0 + lVar7 * 0x28) = DAT_1c001d9ac;
          *(int *)(param_1 + 0x19d4 + lVar7 * 0x28) = DAT_1c001d9a4;
          if (*(char *)(param_1 + 0x15a6) == '\0') {
            *(ulonglong *)(param_1 + 0x19d8 + lVar7 * 0x28) = (ulonglong)DAT_1c001d9a0;
          }
          else {
            *(uint *)(param_1 + 0x19d8 + lVar7 * 0x28) = DAT_1c001d9a0;
            *(int *)(param_1 + 0x19dc + lVar7 * 0x28) = DAT_1c001d9d4;
          }
          *(uint *)(param_1 + 0x19e0 + lVar7 * 0x28) = local_238;
          *(undefined4 *)(param_1 + 0x19e8 + lVar7 * 0x28) = DAT_1c001d9b0;
          *(undefined4 *)(param_1 + 0x19ec + lVar7 * 0x28) = DAT_1c001d9b4;
          DAT_1c001d950 = 1;
          ArcPrintf(param_1,4,
                    (byte *)"* Found a new container - tid: %d , ctid: %x , uid %d, capacity: %p\n",
                    (ulonglong)uVar13);
LAB_1c0007162:
          if (uVar13 != 0xffffffff) {
            *(undefined1 *)(param_1 + (lVar7 + 0xa5) * 0x28) = 1;
            ArcPrintf(param_1,4,(byte *)"* ConfigureContainersRuntime: disk %d found, ctIndex: %d\n"
                      ,(ulonglong)uVar12);
          }
        }
      }
      else {
        ArcPrintf(param_1,4,
                  (byte *)
                  "* ConfigureContainersRuntime: Fall into else statement for %d disk for second VM_NameServe64 command\n"
                  ,(ulonglong)uVar12);
      }
      bVar1 = DAT_1c001d951;
    }
    if (bVar1 == DAT_1c001d938) {
      piVar15 = (int *)(param_1 + 0x19cc);
      uVar12 = 0;
      piVar14 = piVar15;
      do {
        if ((*piVar14 == 1) && ((char)piVar14[-1] == '\0')) {
          *piVar14 = 2;
          ArcPrintf(param_1,4,
                    (byte *)"* ConfigureContainersRuntime: RAID volume 0x%x deleted(lcv %d)\n",
                    (ulonglong)(uint)piVar14[5]);
          DAT_1c001d950 = 1;
        }
        uVar12 = uVar12 + 1;
        piVar14 = piVar14 + 10;
      } while (uVar12 < 0xfe);
      local_234 = 0;
      lVar7 = 0xfe;
      do {
        lVar4 = lVar7;
        if (*piVar15 == 1) {
          local_234 = local_234 + 1;
        }
        piVar15 = piVar15 + 10;
        lVar7 = lVar4 + -1;
      } while (lVar7 != 0);
      if ((*(char *)(param_1 + 0x613) != '\0') && (*(char *)(param_1 + 0xbad0) == '\x01')) {
        DynamicallyThrottleLunQueueDepth(param_1,0xffff);
      }
      uVar10 = (ulonglong)DAT_1c001d951;
      *(int *)(param_1 + 0x51e8) = local_234;
      *local_230 = 1;
      ArcPrintf(param_1,(int)lVar4 + 3,
                (byte *)"* ConfigureContainersRuntime: Disk rescan done, %d disks scaned\n",uVar10);
      bVar1 = DAT_1c001d950;
      DAT_1c001d950 = 0;
      DAT_1c001d948 = 0;
      DAT_1c001d934 = '\0';
      DAT_1c001d951 = 0;
      DAT_1c001d938 = 0;
      DAT_1c001d93c = 0;
      goto LAB_1c00072ef;
    }
    uVar12 = bVar1 - 1;
    pcVar9 = "* ConfigureContainersRuntime: disk %d scaned\n";
  }
  else {
    uVar12 = (uint)DAT_1c001d951;
    pcVar9 = "* ConfigureContainersRuntime: SyncSrb occupied, LoopCount %d\n";
  }
  ArcPrintf(param_1,4,(byte *)pcVar9,(ulonglong)uVar12);
  uVar8 = (ulonglong)DAT_1c001d950;
  bVar1 = DAT_1c001d950;
LAB_1c00072ef:
  ArcPrintf(param_1,0x10000200,(byte *)"leaving ConfigureContainersRuntime, rtnval = %d\n",uVar8);
  return bVar1;
}



===== CheckForVersionMisMatch @ 1c0007334 =====

void CheckForVersionMisMatch
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  uint *_Dst;
  undefined8 uVar1;
  byte bVar2;
  ulonglong uVar3;
  ushort local_res8 [4];
  uint *puVar4;
  undefined8 uVar5;
  
  _Dst = (uint *)(param_1 + 0xa9c2);
  ArcPrintf(param_1,0x10000200,(byte *)"entering CheckForVersionMisMatch\n",param_4);
  *(undefined4 *)(param_1 + 0xaa04) = 3;
  if ((*(uint *)(param_1 + 0x13cc) & 0x10) == 0) {
    *(undefined4 *)(param_1 + 0xaa04) = 3;
    *(undefined1 *)_Dst = 0;
  }
  else {
    memset(_Dst,0,0x40);
    puVar4 = _Dst;
    uVar1 = SendSynchFib(param_1,0x322,_Dst,0x40,_Dst,local_res8,'\x01');
    if (((char)uVar1 == '\0') || (local_res8[0] == 0)) {
      memset(_Dst,0,0x40);
      *(undefined4 *)(param_1 + 0xaa04) = 3;
    }
    else {
      *(undefined4 *)(param_1 + 0xaa04) = 1;
      uVar3 = 0;
      while( true ) {
        if (*(char *)(uVar3 + (longlong)_Dst) != "This is a code stream identifier"[uVar3]) break;
        if ((*(char *)(uVar3 + (longlong)_Dst) == '\0') ||
           (bVar2 = (char)uVar3 + 1, uVar3 = (ulonglong)bVar2, 0x1f < bVar2)) goto LAB_1c0007465;
      }
      uVar1 = 2;
      uVar5 = CONCAT44((int)((ulonglong)puVar4 >> 0x20),*(undefined4 *)(param_1 + 5000));
      ArcPrintf(param_1,2,(byte *)"* Version Mismatch: Bios:%d, Firmware:%d, Driver:%d\n",
                (ulonglong)*(uint *)(param_1 + 0x1370));
      *(undefined4 *)(param_1 + 0xaa04) = 2;
      ArcLogEventString(param_1,uVar1,0xa01a000a,10,uVar5,0xb0);
    }
  }
LAB_1c0007465:
  ArcPrintf(param_1,0x10000200,
            (byte *)"leving CheckForVersionMisMatch with  DriverVersionMatchFlag = %x\n",
            (ulonglong)*(uint *)(param_1 + 0xaa04));
  return;
}



===== FindAdapter @ 1c0007490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
FindAdapter(void *param_1,undefined8 param_2,undefined8 param_3,char *param_4,uint *param_5)

{
  byte bVar1;
  ushort uVar2;
  undefined1 extraout_AL;
  undefined1 extraout_AL_00;
  char cVar3;
  bool bVar4;
  undefined1 uVar5;
  undefined1 extraout_AL_01;
  undefined1 extraout_AL_02;
  int iVar6;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  int extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  undefined4 extraout_EAX_08;
  undefined4 extraout_EAX_09;
  int extraout_EAX_10;
  int extraout_EAX_11;
  undefined8 uVar7;
  short *psVar8;
  undefined8 uVar9;
  undefined4 *puVar10;
  byte bVar11;
  longlong lVar12;
  undefined2 *puVar13;
  uint *puVar14;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined8 *puVar15;
  char *pcVar16;
  char *pcVar17;
  uint *puVar18;
  ulonglong uVar19;
  undefined1 *puVar20;
  ulonglong uVar21;
  uint uVar22;
  undefined4 uVar23;
  uint uVar24;
  uint uVar25;
  undefined1 *puVar26;
  ushort *puVar27;
  byte bVar28;
  undefined1 auStackY_3c8 [32];
  ushort local_358 [2];
  uint local_354;
  uint local_350 [2];
  undefined8 local_348;
  char *local_340;
  uint local_338;
  uint local_334;
  uint local_330;
  uint local_32c;
  uint local_328 [2];
  uint *local_320;
  undefined2 local_318;
  ushort local_316 [2];
  byte local_312;
  short local_2ec;
  short local_2ea;
  byte local_2e4;
  uint local_218 [8];
  undefined4 local_1f8;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_3c8;
  bVar11 = 0;
  local_320 = param_5;
  local_354 = 0;
  local_340 = param_4;
  if (param_1 == (void *)0x0) {
    StorPortDebugPrint(0,"%s: Driver FindAdapter - invalid pDeviceExtension\n",&s_Arcsas);
    return 2;
  }
  pcVar16 = param_4;
  memset(param_1,0,0xe2f0);
  *(undefined4 *)((longlong)param_1 + 0x5e08) = 0x2000000f;
  ArcPrintf((longlong)param_1,0x10000200,(byte *)"entering FindAdapter\n",(ulonglong)pcVar16);
  uVar25 = *param_5;
  uVar21 = (ulonglong)uVar25;
  if (uVar25 < 0xc0) {
    if (0x98 < uVar25) {
      pcVar16 = 
      "***** Size of PORT_CONFIGURATION_INFORMATION: %x, this is not WS03-SP1 nor Vista!!!\n";
      uVar25 = 1;
      goto LAB_1c000757b;
    }
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x614) = 1;
    ArcPrintf((longlong)param_1,0x10000200,(byte *)"entering FindAdapter\n",uVar21);
    uVar21 = (ulonglong)*param_5;
    pcVar16 = "* This is WS03 R2, Vista or Longhorn - size of PORT_CONFIGURATION_INFORMATION: %x\n";
    uVar25 = 4;
LAB_1c000757b:
    ArcPrintf((longlong)param_1,uVar25,(byte *)pcVar16,uVar21);
  }
  *(uint *)((longlong)param_1 + 0x5e08) = *(uint *)((longlong)param_1 + 0x5e08) & 0xdfffffff;
  ArcPrintf((longlong)param_1,1,
            (byte *)"* HwScsiFindAdapter: DeviceExtension=%x, Bus=%d, Device=%d, ArgS=%s\n",
            (ulonglong)param_1);
  local_354 = StorPortGetBusData(param_1,4,param_5[1],param_5[0x19]);
  puVar20 = (undefined1 *)(ulonglong)local_354;
  ArcPrintf((longlong)param_1,1,(byte *)"* Returned PCI bus data length=%d\n",(ulonglong)puVar20);
  if (local_354 == 0xff) {
    pcVar16 = "* 0xFF PCI Bus Data read in\n";
  }
  else {
    puVar20 = (undefined1 *)(ulonglong)param_5[0x19];
    local_354 = StorPortGetBusData(param_1,4,param_5[1]);
    if (local_354 != 0x40) {
      ArcPrintf((longlong)param_1,0x10000200,
                (byte *)"leaving FindAdapter - StorPortGetBusData problem!\n",(ulonglong)puVar20);
      pcVar16 = "* leaving FindAdapter - StorPortGetBusData problem!\n";
      goto LAB_1c0007642;
    }
    pcVar16 = "* 0x40 PCI Bus Data read in\n";
  }
  ArcPrintf((longlong)param_1,1,(byte *)pcVar16,(ulonglong)puVar20);
  bVar28 = 0;
  *(undefined1 *)((longlong)param_1 + 0xaad0) = 0;
  if ((local_312 & 0x10) == 0) {
    ArcPrintf((longlong)param_1,4,(byte *)"* No Support on Capabilties list to check MSI-X\n",
              (ulonglong)puVar20);
  }
  else {
    puVar26 = (undefined1 *)(ulonglong)local_2e4;
    puVar20 = puVar26;
    ArcPrintf((longlong)param_1,4,(byte *)"* Capability_offset = 0x%x ",(ulonglong)puVar26);
    if (local_2e4 != 0) {
      do {
        bVar1 = *(byte *)((longlong)&local_318 + (longlong)puVar26);
        ArcPrintf((longlong)param_1,4,(byte *)" -->capabilty_id = 0x%x\n",(ulonglong)bVar1);
        if (bVar1 == 0x11) {
          uVar2 = *(ushort *)((longlong)local_316 + (longlong)puVar26);
          puVar20 = (undefined1 *)(ulonglong)uVar2;
          ArcPrintf((longlong)param_1,4,(byte *)"* Message_control = 0x%x\n",(ulonglong)puVar20);
          if ((uVar2 & 0x8000) == 0) {
            param_4 = local_340;
          }
          else {
            ArcPrintf((longlong)param_1,4,(byte *)"* HW supports MSI-X\n",(ulonglong)puVar20);
            *(undefined1 *)((longlong)param_1 + 0xaad0) = 1;
            param_4 = local_340;
          }
          goto LAB_1c000770f;
        }
        bVar1 = puVar26[(longlong)&local_318 + 1];
        puVar26 = (undefined1 *)(ulonglong)bVar1;
        puVar20 = puVar26;
        ArcPrintf((longlong)param_1,4,(byte *)"* Capability_offset = 0x%x ",(ulonglong)puVar26);
        bVar28 = bVar28 + 1;
      } while ((bVar28 < 6) && (bVar1 != 0));
      param_4 = local_340;
    }
  }
LAB_1c000770f:
  uVar21 = 1;
  iVar6 = StorPortExtendedFunction(0x12,param_1,local_358);
  if (iVar6 == 0) {
    puVar20 = (undefined1 *)(ulonglong)local_358[0];
    ArcPrintf((longlong)param_1,4,
              (byte *)"* StorPortGetActiveGroupCount returns success, group number is %d\n",
              (ulonglong)puVar20);
  }
  else if (iVar6 == -0x3efffffe) {
    ArcPrintf((longlong)param_1,4,(byte *)"* StorPortGetActiveGroupCount has not been implemented\n"
              ,(ulonglong)puVar20);
  }
  iVar6 = StorPortExtendedFunction(0x11,param_1,&local_348);
  if (iVar6 == 0) {
    puVar20 = (undefined1 *)((ulonglong)local_348 >> 0x10 & 0xff);
    ArcPrintf((longlong)param_1,4,
              (byte *)
              "* StorPortGetCurrentProcessorNumber returns success, processor number is %d in group %d\n"
              ,(ulonglong)puVar20);
    *(byte *)((longlong)param_1 + 0xaae4) = local_348._2_1_;
    if (local_348._2_1_ < 0x11) {
      *(undefined1 *)((longlong)param_1 + 0xaae4) = 0x10;
    }
  }
  else {
    if (iVar6 == -0x3efffffe) {
      pcVar16 = "* StorPortGetCurrentProcessorNumber has not been implemented\n";
    }
    else {
      if (iVar6 != -0x3efffffa) goto LAB_1c0007831;
      pcVar16 = "* StorPortGetCurrentProcessorNumber returns false becasue of invalid parameters\n";
    }
    ArcPrintf((longlong)param_1,4,(byte *)pcVar16,(ulonglong)puVar20);
  }
LAB_1c0007831:
  iVar6 = StorPortExtendedFunction(0x14,param_1,local_350);
  if (iVar6 == 0) {
    ArcPrintf((longlong)param_1,4,
              (byte *)"* StorPortGetActiveNodeCount returns success, node number is %d\n",
              (ulonglong)local_350[0]);
  }
  else {
    if (iVar6 == -0x3efffffe) {
      pcVar16 = "* StorPortGetActiveNodeCount has not been implemented\n";
    }
    else {
      if (iVar6 != -0x3efffffa) goto LAB_1c0007888;
      pcVar16 = "* StorPortGetActiveNodeCount returns false becasue of invalid parameters\n";
    }
    ArcPrintf((longlong)param_1,4,(byte *)pcVar16,(ulonglong)puVar20);
  }
LAB_1c0007888:
  puVar18 = local_328;
  iVar6 = StorPortExtendedFunction(0x13,param_1);
  if (iVar6 == 0) {
    puVar18 = (uint *)(ulonglong)local_328[0];
    ArcPrintf((longlong)param_1,4,
              (byte *)"* StorPortGetGroupAffinity returns success, node number is 0x%x\n",
              (ulonglong)puVar18);
  }
  else {
    if (iVar6 == -0x3effffff) {
      pcVar16 = "* StorPortGetGroupAffinity returns false becasue of STOR_STATUS_UNSUCCESSFUL\n";
    }
    else if (iVar6 == -0x3efffffe) {
      pcVar16 = "* StorPortGetGroupAffinity has not been implemented\n";
    }
    else {
      if (iVar6 != -0x3efffffa) goto LAB_1c00078ef;
      pcVar16 = "* StorPortGetGroupAffinity returns false becasue of invalid parameters\n";
    }
    ArcPrintf((longlong)param_1,4,(byte *)pcVar16,(ulonglong)puVar18);
  }
LAB_1c00078ef:
  iVar6 = StorPortExtendedFunction(0x16);
  if (iVar6 == 0) {
    ArcPrintf((longlong)param_1,4,
              (byte *)"* StorPortGetHighestNodeNumber returns success, Highest node number is %d\n",
              (ulonglong)local_350[0]);
  }
  else {
    if (iVar6 == -0x3efffffe) {
      pcVar16 = "* StorPortGetHighestNodeNumber has not been implemented\n";
    }
    else {
      if (iVar6 != -0x3efffffa) goto LAB_1c0007946;
      pcVar16 = "* StorPortGetHighestNodeNumber returns false becasue of invalid parameters\n";
    }
    ArcPrintf((longlong)param_1,4,(byte *)pcVar16,(ulonglong)puVar18);
  }
LAB_1c0007946:
  *(undefined1 *)((longlong)param_1 + 0xaae4) = 100;
  uVar19 = uVar21;
  GetDriverParameter("dump",0,0,1,param_4);
  if ((((extraout_EAX == 1) ||
       (uVar19 = uVar21, GetDriverParameter("ntldr",0,0,1,param_4), extraout_EAX_00 == 1)) ||
      (uVar19 = uVar21, GetDriverParameter("hiber",0,0,1,param_4), extraout_EAX_01 == 1)) ||
     (gDriverObject == 0)) {
    ArcPrintf((longlong)param_1,1,(byte *)"**** dump | ntldr | hiber is TRUE\n",uVar19);
    *(undefined1 *)((longlong)param_1 + 0x516a) = 1;
    *(undefined1 *)((longlong)param_1 + 0x610) = 1;
    if ((ushort)(local_316[0] - 0x28c) < 2) {
      uVar19 = **(ulonglong **)(param_5 + 0xe);
      uVar7 = StorPortGetDeviceBase(param_1,param_5[2],param_5[1]);
      *(undefined8 *)((longlong)param_1 + 0x1a8) = uVar7;
      RxAccessDeviceRegister((longlong)param_1,8);
      ArcPrintf((longlong)param_1,4,(byte *)"* Switching to INTx mode\n",uVar19);
      *(undefined1 *)((longlong)param_1 + 0xaad6) = 0;
      *(undefined1 *)((longlong)param_1 + 0xaadc) = 0;
    }
  }
  GetDriverParameter("BLEDCheck",1,0,1,param_4);
  *(undefined1 *)((longlong)param_1 + 0x611) = extraout_AL;
  pcVar16 = param_4;
  GetDriverParameter("DPCAllowed",1,0,1,param_4);
  *(undefined1 *)((longlong)param_1 + 0x612) = extraout_AL_00;
  cVar3 = MatchRegistryString(param_4,"CSMI=None");
  if (cVar3 == '\0') {
    cVar3 = MatchRegistryString(param_4,"CSMI=Restricted");
    if (cVar3 == '\0') {
      cVar3 = MatchRegistryString(param_4,"CSMI=Full");
      *(uint *)((longlong)param_1 + 0xaa08) = (cVar3 != '\0') + 3;
    }
    else {
      *(undefined4 *)((longlong)param_1 + 0xaa08) = 2;
    }
  }
  else {
    *(undefined4 *)((longlong)param_1 + 0xaa08) = 1;
  }
  *(undefined4 *)((longlong)param_1 + 0x5174) = 3;
  puVar10 = (undefined4 *)((longlong)param_1 + 0x19cc);
  *(undefined4 *)((longlong)param_1 + 0x5178) = 300;
  lVar12 = 0xfe;
  *(undefined4 *)((longlong)param_1 + 0x1d0) = 0;
  *(undefined4 *)((longlong)param_1 + 0x8074) = 0x400;
  do {
    *puVar10 = 0;
    puVar10 = puVar10 + 10;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  lVar12 = (longlong)param_1 + 0x680;
  *(undefined1 *)((longlong)param_1 + 0x516b) = 0;
  *(longlong *)((longlong)param_1 + 0x688) = lVar12;
  *(longlong *)lVar12 = lVar12;
  uVar25 = 0;
  ArcPrintf((longlong)param_1,0x10000200,(byte *)"entering MatchPciIds\n",uVar21);
  uVar21 = 0;
  puVar27 = &DAT_1c001d01e;
  local_350[0] = 0;
  do {
    uVar24 = (uint)uVar21;
    if (bVar11 != 0) break;
    if ((local_318 == puVar27[-1]) && (local_316[0] == *puVar27)) {
      local_348 = *(short **)(puVar27 + 1);
      bVar11 = 1;
      *(undefined ***)((longlong)param_1 + 0x1320) =
           &PTR_RxSendSynchCommand_1c001d030 + uVar21 * 0x11;
      memcpy((void *)((longlong)param_1 + 0x159c),"Adaptec ",9);
      uVar21 = 0;
      if (*(uint *)(puVar27 + 5) != 0) {
        psVar8 = local_348;
        do {
          if ((local_2ec == *psVar8) && (local_2ea == psVar8[1])) {
            if (uVar25 < 9) {
              memset((void *)((longlong)param_1 + (ulonglong)uVar25 + 0x159c),
                     (int)CONCAT71((uint7)(byte)((ushort)local_2ea >> 8),0x20),
                     (ulonglong)(9 - uVar25));
              uVar25 = uVar25 + (9 - uVar25);
              uVar24 = local_350[0];
            }
            memcpy((void *)((longlong)param_1 + 0x159c),*(void **)(local_348 + uVar21 * 8 + 4),8);
            break;
          }
          uVar22 = (int)uVar21 + 1;
          uVar21 = (ulonglong)uVar22;
          psVar8 = psVar8 + 8;
        } while (uVar22 < *(uint *)(puVar27 + 5));
      }
    }
    local_350[0] = uVar24 + 1;
    uVar21 = (ulonglong)local_350[0];
    puVar27 = puVar27 + 0x44;
  } while (local_350[0] < 6);
  puVar20 = (undefined1 *)(ulonglong)bVar11;
  ArcPrintf((longlong)param_1,0x10000200,(byte *)"leaving MatchPciIds, rtnval = %x\n",
            (ulonglong)puVar20);
  puVar18 = local_320;
  if (bVar11 == 0) {
    ArcPrintf((longlong)param_1,0x10000200,(byte *)"leaving FindAdapter - PCI Id not match!\n",
              (ulonglong)puVar20);
    pcVar16 = "* leaving FindAdapter - PCI Id not match!\n";
    goto LAB_1c0007642;
  }
  pcVar17 = (char *)0x1000;
  *(ushort *)((longlong)param_1 + 0x158c) = local_318;
  uVar24 = gAdapterAddCount + 1;
  puVar20 = (undefined1 *)0x2000;
  *(short *)((longlong)param_1 + 0x1592) = local_2ea;
  *(short *)((longlong)param_1 + 0x1590) = local_2ec;
  *(ushort *)((longlong)param_1 + 0x158e) = local_316[0];
  *(uint *)((longlong)param_1 + 0x1594) = local_320[0x19];
  uVar25 = local_320[1];
  *(undefined4 *)((longlong)param_1 + 0x8150) = 0xffffffff;
  *(uint *)((longlong)param_1 + 0x1598) = uVar25;
  gAdapterAddCount = uVar24;
  *(undefined4 *)((longlong)param_1 + 0x814c) = 0xfffffffb;
  if (local_316[0] == 0x285) {
    *(undefined4 *)((longlong)param_1 + 0x80a8) = 0x1000;
    *(undefined4 *)((longlong)param_1 + 0x80ac) = 0x1000;
    *(undefined4 *)((longlong)param_1 + 0x80b0) = 0x1000;
    pcVar16 = (char *)CONCAT44((int)((ulonglong)pcVar16 >> 0x20),0x1000);
    pcVar17 = "Rx: BAR0 Range 0x%lx MappedSize 0x%lx\n";
    puVar20 = (undefined1 *)(ulonglong)*(uint *)(*(longlong *)(local_320 + 0xe) + 8);
    ArcPrintf((longlong)param_1,4,(byte *)"Rx: BAR0 Range 0x%lx MappedSize 0x%lx\n",
              (ulonglong)puVar20);
  }
  else if (local_316[0] == 0x286) {
    *(undefined4 *)((longlong)param_1 + 0x80a8) = 0x2000;
    *(undefined4 *)((longlong)param_1 + 0x80ac) = 0x2000;
    *(undefined4 *)((longlong)param_1 + 0x80b0) = 0x2000;
  }
  else {
    if (((ushort)(local_316[0] - 0x288) < 6) &&
       ((0x29U >> ((ushort)(local_316[0] - 0x288) & 0x1f) & 1) != 0)) {
      if ((ushort)(local_316[0] - 0x28c) < 2) goto LAB_1c0007dde;
      if (local_316[0] == 0x28b) {
        *(undefined4 *)((longlong)param_1 + 0x80a8) = 0x400000;
        *(undefined4 *)((longlong)param_1 + 0x80ac) = 0x800;
      }
      else {
        *(undefined4 *)((longlong)param_1 + 0x80a8) = 0x1000;
        *(undefined4 *)((longlong)param_1 + 0x80ac) = 0x1000;
      }
      *(undefined4 *)((longlong)param_1 + 0x80b0) = 0x1000;
    }
    else {
      if (local_316[0] != 0x28c) {
        return 0;
      }
LAB_1c0007dde:
      *(undefined4 *)((longlong)param_1 + 0x80a8) = 0x100000;
      *(undefined4 *)((longlong)param_1 + 0x80ac) = 0x400;
      *(undefined4 *)((longlong)param_1 + 0x80b0) = 0x100;
    }
    *(undefined4 *)((longlong)param_1 + 0x80c0) =
         *(undefined4 *)(*(longlong *)(local_320 + 0xe) + 0x10);
    *(undefined4 *)((longlong)param_1 + 0x80c4) =
         *(undefined4 *)(*(longlong *)(local_320 + 0xe) + 0x14);
    *(undefined4 *)((longlong)param_1 + 0x80c8) =
         *(undefined4 *)(*(longlong *)(local_320 + 0xe) + 0x20);
    *(undefined4 *)((longlong)param_1 + 0x80cc) =
         *(undefined4 *)(*(longlong *)(local_320 + 0xe) + 0x24);
  }
  *(undefined4 *)((longlong)param_1 + 0x80b8) = **(undefined4 **)(puVar18 + 0xe);
  *(undefined4 *)((longlong)param_1 + 0x80bc) = *(undefined4 *)(*(longlong *)(puVar18 + 0xe) + 4);
  bVar4 = MapDeviceBase((longlong)param_1,(longlong)puVar18,pcVar17,(ulonglong)puVar20);
  if (!bVar4) {
    ArcPrintf((longlong)param_1,0x10000200,
              (byte *)"leaving FindAdapter - fail mapping the device base!\n",(ulonglong)puVar20);
    pcVar16 = "* leaving FindAdapter - fail mapping the device base!\n";
LAB_1c0007642:
    ArcPrintf((longlong)param_1,1,(byte *)pcVar16,(ulonglong)puVar20);
    return 0;
  }
  if (((ushort)(*(short *)((longlong)param_1 + 0x158e) - 0x28bU) < 3) &&
     (*(int *)((longlong)param_1 + 0x8088) == 0)) {
    ArcPrintf((longlong)param_1,0x10000200,
              (byte *)"leaving FindAdapter - illegal FW comm. interface\n",(ulonglong)puVar20);
    pcVar16 = "* leaving FindAdapter - illegal FW comm. interface!Interface type: %d\n";
    uVar25 = *(uint *)((longlong)param_1 + 0x8088);
    goto LAB_1c0007ec0;
  }
  ArcPrintf((longlong)param_1,4,(byte *)"* pDeviceExtension->NewCommInterfaceType: %d\n",
            (ulonglong)*(uint *)((longlong)param_1 + 0x8088));
  ArcPrintf((longlong)param_1,4,(byte *)"* pDeviceExtension->VendorId: 0x%x\n",
            (ulonglong)*(ushort *)((longlong)param_1 + 0x158c));
  ArcPrintf((longlong)param_1,4,(byte *)"* pDeviceExtension->DeviceId: 0x%x\n",
            (ulonglong)*(ushort *)((longlong)param_1 + 0x158e));
  ArcPrintf((longlong)param_1,4,(byte *)"* pDeviceExtension->SubVendorId: 0x%x\n",
            (ulonglong)*(ushort *)((longlong)param_1 + 0x1590));
  uVar21 = (ulonglong)*(ushort *)((longlong)param_1 + 0x1592);
  ArcPrintf((longlong)param_1,4,(byte *)"* pDeviceExtension->SubSystemId: 0x%x\n",uVar21);
  if (uVar24 < 0x40) {
    *(void **)(&gAdapterTable + (ulonglong)uVar24 * 8) = param_1;
  }
  *(undefined1 *)((longlong)puVar18 + 0x93) = 0;
  *(undefined4 *)(*(longlong *)(puVar18 + 0xe) + 8) = *(undefined4 *)((longlong)param_1 + 0x80a8);
  if ((*(short *)((longlong)param_1 + 0x158e) == 0x288) ||
     ((ushort)(*(short *)((longlong)param_1 + 0x158e) - 0x28bU) < 3)) {
    *(undefined4 *)(*(longlong *)(puVar18 + 0xe) + 0x18) =
         *(undefined4 *)((longlong)param_1 + 0x80ac);
    *(undefined4 *)(*(longlong *)(puVar18 + 0xe) + 0x28) =
         *(undefined4 *)((longlong)param_1 + 0x80b0);
  }
  puVar18[6] = 0x10000;
  *(undefined1 *)(puVar18 + 0x12) = 5;
  puVar18[7] = 0x25;
  puVar18[0xc] = 0;
  *(undefined1 *)((longlong)puVar18 + 0x51) = 1;
  *(undefined1 *)((longlong)puVar18 + 0x53) = 1;
  *(undefined1 *)((longlong)puVar18 + 0x57) = 1;
  *(undefined1 *)((longlong)puVar18 + 0x61) = 0xff;
  puVar18[0x23] = 0x726;
  *(undefined1 *)((longlong)puVar18 + 0x91) = 1;
  puVar18[0x25] = 1;
  *(undefined1 *)((longlong)puVar18 + 0x59) = 2;
  *(undefined4 *)((longlong)puVar18 + 0x49) = 0xfefefefe;
  *(undefined1 *)((longlong)puVar18 + 0x4d) = 0xfe;
  if ((char)puVar18[0x24] == -0x80) {
    if ((*(uint *)((longlong)param_1 + 0x13a0) & 0x400) == 0) {
      *(undefined1 *)(puVar18 + 0x24) = 0;
    }
    else {
      *(undefined1 *)(puVar18 + 0x24) = 1;
      *(undefined1 *)((longlong)param_1 + 0x15a5) = 1;
    }
  }
  if ((*(uint *)((longlong)param_1 + 0x13a0) & 0x40000) != 0) {
    *(undefined1 *)((longlong)param_1 + 0x15a6) = *(undefined1 *)((longlong)param_1 + 0x8084);
  }
  cVar3 = GetFwDebugBuffer((longlong)param_1,(longlong)puVar18);
  if (cVar3 != '\0') {
    *(uint *)((longlong)param_1 + 0x5e08) = *(uint *)((longlong)param_1 + 0x5e08) | 0x20000000;
  }
  uVar25 = *puVar18;
  if (uVar25 < 0xd0) {
    if (uVar25 < 0xc0) {
      if (uVar25 < 0x98) {
        pcVar17 = "* This is 32-bit WS03 SP1 ... \n";
        if (uVar25 < 0x90) {
          pcVar17 = "* This is 32-bit WS03 RTM ... \n";
        }
      }
      else {
        pcVar17 = "* This is 64-bit WS03 SP1 ... \n";
      }
    }
    else {
      pcVar17 = "* This is 32-bit WS03 R2, Vista or Longhorn... \n";
    }
  }
  else {
    pcVar17 = "* This is 64-bit Vista or Longhorn... \n";
  }
  ArcPrintf((longlong)param_1,4,(byte *)pcVar17,uVar21);
  *(undefined4 *)((longlong)param_1 + 0x8068) = 0x200;
  if ((*(char *)((longlong)param_1 + 0x8084) != '\0') ||
     (*(char *)((longlong)param_1 + 0x808d) != '\0')) {
    pcVar16 = (char *)((ulonglong)pcVar16 & 0xffffffff00000000);
    cVar3 = (*(code *)**(undefined8 **)((longlong)param_1 + 0x1320))(param_1,0x26,0);
    if ((cVar3 != '\0') && (local_354 == 1)) {
      *(uint *)((longlong)param_1 + 0x8064) = (local_330 >> 0x10) << 10;
      *(uint *)((longlong)param_1 + 0x8068) = local_330 & 0xffff;
      *(uint *)((longlong)param_1 + 0x806c) = local_32c >> 0x10;
      *(uint *)((longlong)param_1 + 0x8070) = local_32c & 0xffff;
      uVar25 = local_338 & 0xffff;
      uVar23 = (undefined4)((ulonglong)pcVar16 >> 0x20);
      *(uint *)((longlong)param_1 + 0x807c) = local_334 & 0xffff;
      ArcPrintf((longlong)param_1,4,
                (byte *)"* MailBox 1:%x, MailBox 2:%x, MailBox 3:%x, MailBox 4:%x\n",
                (ulonglong)local_330);
      if (local_338 >> 0x10 == 0) {
        pcVar16 = "* Old outstanding number chose:%d\n";
      }
      else {
        pcVar16 = "* New outstanding number chose:%d\n";
        uVar25 = local_338 >> 0x10;
      }
      ArcPrintf((longlong)param_1,4,(byte *)pcVar16,(ulonglong)uVar25);
      if (uVar25 < 0x400) {
        *(uint *)((longlong)param_1 + 0x8074) = uVar25;
      }
      puVar18[7] = *(int *)((longlong)param_1 + 0x806c) - 1;
      puVar18[0x23] = *(int *)((longlong)param_1 + 0x8068) + 0x526;
      puVar18[6] = *(uint *)((longlong)param_1 + 0x8064);
      *(undefined2 *)((longlong)param_1 + 0xaad2) = 7;
      if (*(uint *)((longlong)param_1 + 0x8074) != 0) {
        *(short *)((longlong)param_1 + 0xaad2) = (short)(*(uint *)((longlong)param_1 + 0x8074) >> 5)
        ;
      }
      if (*(char *)((longlong)param_1 + 0x8084) != '\0') {
        *(undefined1 *)((longlong)param_1 + 0x808c) = 1;
      }
      pcVar17 = "* MiniARC Interface -  CommandSize:%x, FibSize:%x, SG:%x, OutStanding:%x\n";
      pcVar16 = (char *)CONCAT44(uVar23,*(undefined4 *)((longlong)param_1 + 0x8068));
      if (*(char *)((longlong)param_1 + 0x808d) == '\0') {
        pcVar17 = "* New Comm Interface -  CommandSize:%x, FibSize:%x, SG:%x, OutStanding:%x\n";
      }
      ArcPrintf((longlong)param_1,4,(byte *)pcVar17,(ulonglong)*(uint *)((longlong)param_1 + 0x8064)
               );
    }
  }
  if ((*(int *)((longlong)param_1 + 0x8088) == 2) && (0x40 < puVar18[7])) {
    puVar18[7] = 0x40;
  }
  *(uint *)((longlong)param_1 + 0x806c) = puVar18[7] + 1;
  puVar20 = (undefined1 *)(ulonglong)puVar18[0x23];
  ArcPrintf((longlong)param_1,4,(byte *)"* SrbExtensionSize:%x\n",(ulonglong)puVar20);
  if (*(char *)((longlong)param_1 + 0x614) != '\0') {
    *(code **)(puVar18 + 0x26) = HandleMSIXInterrupt;
    ArcPrintf((longlong)param_1,4,
              (byte *)"* ConfigInfo->HwMSInterruptRoutine is set to HandleMSIXInterrupt\n",
              (ulonglong)puVar20);
    puVar18[0x28] = 2;
    if (((ushort)(*(short *)((longlong)param_1 + 0x158e) - 0x28cU) < 2) &&
       (*(int *)((longlong)param_1 + 0x8080) == 0)) {
      puVar18[0x28] = 1;
    }
  }
  pcVar17 = local_340;
  puVar14 = puVar18;
  if (*(char *)((longlong)param_1 + 0x8084) == '\0') {
    *(undefined1 *)((longlong)param_1 + 0x610) = *(undefined1 *)((longlong)param_1 + 0x516a);
    *(undefined4 *)((longlong)param_1 + 0x210) = 0;
    *(code **)((longlong)param_1 + 0x80d0) = SendConsumerProducerFib;
    *(undefined4 *)((longlong)param_1 + 0x814c) = 0xfffffffb;
    *(code **)((longlong)param_1 + 0x80d8) = GetConsumerProducerCompletedFib;
    bVar4 = InitializeConsumerProducerNewAdapter(param_1,puVar18,uVar24,puVar20);
    pcVar17 = local_340;
  }
  else {
    puVar20 = (undefined1 *)0x100000;
    uVar23 = 0xfffffffb;
    if (1 < *(int *)((longlong)param_1 + 0x8088) - 1U) {
      uVar23 = 0xfffffff7;
    }
    *(undefined4 *)((longlong)param_1 + 0x814c) = uVar23;
    pcVar16 = local_340;
    GetDriverParameter("ioctlbufsize",0x40000,0x1000,0x100000,local_340);
    *(undefined4 *)((longlong)param_1 + 0x210) = extraout_EAX_02;
    *(code **)((longlong)param_1 + 0x80d0) = SendMessageUnitQueueFib;
    *(code **)((longlong)param_1 + 0x80d8) = GetMessageUnitQueueCompletedFib;
    bVar4 = InitializeMessageUnitQueueNewAdapter(param_1,puVar18,uVar24,(ulonglong)puVar20);
  }
  if (*(char *)((longlong)param_1 + 0x610) != '\0') {
    puVar14 = (uint *)0x4;
    ArcPrintf((longlong)param_1,4,(byte *)"* Adapter is in poll mode\n",(ulonglong)puVar20);
  }
  if (bVar4 == false) {
    gAdapterAddCount = gAdapterAddCount - 1;
    ArcPrintf((longlong)param_1,0x10000200,(byte *)"leaving FindAdapter - fail initialization!\n",
              (ulonglong)puVar20);
    pcVar16 = "* leaving FindAdapter - fail initialization!\n";
    goto LAB_1c0007642;
  }
  if (*(char *)((longlong)param_1 + 0x615) == '\0') {
    if ((*(uint *)((longlong)param_1 + 0x13a0) & 0x40) == 0) {
      uVar5 = 0xa0;
      uVar23 = 0xa01a0005;
      goto LAB_1c0008474;
    }
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x610) = 1;
    puVar14 = (uint *)0x4;
    ArcPrintf((longlong)param_1,4,(byte *)"* Adapter is in poll mode\n",(ulonglong)puVar20);
    uVar5 = 0x60;
    uVar23 = 0xe01a0005;
LAB_1c0008474:
    ArcLogEventString(param_1,puVar14,uVar23,5,pcVar16,uVar5);
  }
  pcVar16 = (char *)((longlong)param_1 + 0x1350);
  memset(pcVar16,0,0x58);
  uVar21 = 0x58;
  uVar7 = 0x2bf;
  SendSynchFib((longlong)param_1,0x2bf,(uint *)pcVar16,0x58,pcVar16,local_358,'\x01');
  if (*(char *)((longlong)param_1 + 0x808d) != '\0') {
    memset(local_218,0,0x1d0);
    local_1d8 = *(undefined4 *)((longlong)param_1 + 0x809c);
    uVar7 = 500;
    pcVar16 = (char *)local_218;
    local_1d0 = *(undefined4 *)((longlong)param_1 + 0x80a4);
    uVar21 = 0x1d0;
    local_1d4 = *(undefined4 *)((longlong)param_1 + 0x80a0);
    local_1f8 = 1;
    local_1dc = 1;
    local_218[0] = 2;
    local_218[1] = 0xec;
    uVar9 = SendSynchFib((longlong)param_1,500,(uint *)pcVar16,0x1d0,local_218,local_358,'\x01');
    if ((char)uVar9 == '\0') {
      pcVar16 = "* fail SynFibCT_SET_MINIARC_HOST_MEMORY_SEGMENTS\n";
      uVar7 = 1;
      ArcPrintf((longlong)param_1,1,(byte *)"* fail SynFibCT_SET_MINIARC_HOST_MEMORY_SEGMENTS\n",
                uVar21);
    }
  }
  if ((*(uint *)((longlong)param_1 + 0x13a0) & 0x10000) != 0) {
    puVar14 = (uint *)((longlong)param_1 + 0x13a8);
    *(undefined1 *)((longlong)param_1 + 0x13d0) = 0xff;
    uVar21 = 0x1e0;
    uVar7 = SendSynchFib((longlong)param_1,0x2c2,puVar14,0x1e0,puVar14,local_358,'\x01');
    if ((char)uVar7 == '\0') {
      uVar7 = 0;
      pcVar16 = (char *)0x1e0;
      memset(puVar14,0,0x1e0);
      *(undefined1 *)((longlong)param_1 + 0x13d0) = 0xff;
    }
    else {
      if ((*(uint *)((longlong)param_1 + 0x13c8) < 3) ||
         (*(char *)((longlong)param_1 + 0x13d0) == -1)) {
        *(undefined1 *)((longlong)param_1 + 0x13d0) = 0xff;
      }
      uVar7 = 1;
      if ((*(uint *)((longlong)param_1 + 0x1438) & 1) == 0) {
        if ((*(uint *)((longlong)param_1 + 0x1438) >> 0xe & 1) == 0) {
          pcVar16 = "* ERROR: FW does not provide which way to do IOP_Reset\n";
          ArcPrintf((longlong)param_1,1,
                    (byte *)"* ERROR: FW does not provide which way to do IOP_Reset\n",uVar21);
        }
        else {
          pcVar16 = "* Use inbound doorbell for IOP_Reset...\n";
          ArcPrintf((longlong)param_1,1,(byte *)"* Use inbound doorbell for IOP_Reset...\n",uVar21);
          *(undefined1 *)((longlong)param_1 + 0x61b) = 1;
        }
      }
      else {
        pcVar16 = "* Use MU Register for IOP_Reset...\n";
        ArcPrintf((longlong)param_1,1,(byte *)"* Use MU Register for IOP_Reset...\n",uVar21);
        *(undefined1 *)((longlong)param_1 + 0x61a) = 1;
      }
      if ((*(uint *)((longlong)param_1 + 0x1438) & 2) != 0) {
        pcVar16 = "* Ignore_IOP_Reset is set ...\n";
        uVar7 = 1;
        ArcPrintf((longlong)param_1,1,(byte *)"* Ignore_IOP_Reset is set ...\n",uVar21);
        *(undefined1 *)((longlong)param_1 + 0x61c) = 1;
      }
      if ((*(uint *)((longlong)param_1 + 0x1438) & 4) != 0) {
        pcVar16 = "* Disk Power Management is supported ...\n";
        uVar7 = 1;
        ArcPrintf((longlong)param_1,1,(byte *)"* Disk Power Management is supported ...\n",uVar21);
        *(undefined1 *)((longlong)param_1 + 0x19c4) = 1;
        puVar14 = (uint *)(*(longlong *)((longlong)param_1 + 0x630) + 0x34);
        *puVar14 = *puVar14 | 0x20;
        puVar14 = (uint *)(*(longlong *)((longlong)param_1 + 0x630) + 0x34);
        *puVar14 = *puVar14 | 0x10;
      }
      if ((*(uint *)((longlong)param_1 + 0x13cc) & 0x8000000) != 0) {
        pcVar16 = "* This firmware supports fast JBOD mode\n";
        uVar7 = 1;
        ArcPrintf((longlong)param_1,1,(byte *)"* This firmware supports fast JBOD mode\n",uVar21);
        *(undefined1 *)((longlong)param_1 + 0x5169) = 1;
        puVar14 = (uint *)(*(longlong *)((longlong)param_1 + 0x630) + 0x34);
        *puVar14 = *puVar14 | 0x80;
      }
      if ((*(uint *)((longlong)param_1 + 0x1438) & 0x40000) != 0) {
        *(undefined1 *)((longlong)param_1 + 0x15a7) = 1;
      }
    }
  }
  if ((*(uint *)((longlong)param_1 + 0x13a0) & 0x1000) == 0) {
    *(undefined1 *)((longlong)param_1 + 0x517c) = 0;
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x517c) = 1;
  }
  CheckForVersionMisMatch((longlong)param_1,uVar7,pcVar16,uVar21);
  ArcPrintf((longlong)param_1,4,(byte *)"* ExposeNonDASD is %x\n",
            (ulonglong)*(byte *)((longlong)param_1 + 0x517c));
  if ((*(uint *)((longlong)param_1 + 0x13a0) & 0x10000) == 0) {
    *(undefined4 *)((longlong)param_1 + 0x8060) = 0xfe;
  }
  else {
    uVar25 = *(uint *)((longlong)param_1 + 0x8074);
    *(uint *)((longlong)param_1 + 0x8060) = uVar25;
    if (1 < uVar25) {
      *(uint *)((longlong)param_1 + 0x8060) = uVar25 - 1;
    }
  }
  lVar12 = 0xfe;
  *(undefined4 *)((longlong)param_1 + 0x8078) = *(undefined4 *)((longlong)param_1 + 0x8074);
  GetDriverParameter("QueueDepthPerLun",0xfe,1,0xfe,pcVar17);
  uVar25 = *(uint *)((longlong)param_1 + 0x8060);
  *(undefined4 *)((longlong)param_1 + 0x8050) = extraout_EAX_03;
  GetDriverParameter("PauseIOLimit",uVar25 - 1,1,uVar25,pcVar17);
  *(int *)((longlong)param_1 + 0x8054) = extraout_EAX_04;
  uVar9 = 0;
  uVar21 = (ulonglong)(extraout_EAX_04 - 1U);
  pcVar16 = pcVar17;
  uVar25 = GetDriverParameter("ResumeIOLimit",(uVar25 * 0x5f) / 100,0,extraout_EAX_04 - 1U,pcVar17);
  uVar7 = CONCAT44(extraout_var,uVar25);
  *(undefined4 *)((longlong)param_1 + 0x8058) = extraout_EAX_05;
  *(undefined1 *)((longlong)param_1 + 0x805c) = 0;
  if (*(char *)((longlong)param_1 + 0x8084) == '\0') {
    *(undefined8 *)((longlong)param_1 + 0xa908) = 0;
    *(undefined4 *)((longlong)param_1 + 0xa91c) = 0;
    *(undefined1 *)((longlong)param_1 + 0xa924) = 0;
    *(undefined1 *)((longlong)param_1 + 0xa926) = 0;
  }
  else {
    if (*(int *)((longlong)param_1 + 0x8088) == 2) {
      GetDriverParameter("ConvertSGList",1,0,1,pcVar17);
      *(undefined1 *)((longlong)param_1 + 0xa926) = extraout_AL_01;
    }
    else {
      *(undefined1 *)((longlong)param_1 + 0xa926) = 0;
    }
    GetDriverParameter("QueueStartThreshold",4,1,500,pcVar17);
    *(undefined4 *)((longlong)param_1 + 0xa908) = extraout_EAX_06;
    GetDriverParameter("QueueDumpThreshold",1,1,500,pcVar17);
    *(undefined4 *)((longlong)param_1 + 0xa90c) = extraout_EAX_07;
    GetDriverParameter("MaxIoSizeQueued",0x2000,0x200,0x10000,pcVar17);
    *(undefined4 *)((longlong)param_1 + 0xa91c) = extraout_EAX_08;
    GetDriverParameter("QueueAllowed",1,0,1,pcVar17);
    *(undefined1 *)((longlong)param_1 + 0xa924) = extraout_AL_02;
    uVar21 = 0x1000;
    uVar9 = 0x20;
    pcVar16 = pcVar17;
    uVar25 = GetDriverParameter("FlushSizeInBlocks",0x100,0x20,0x1000,pcVar17);
    uVar7 = CONCAT44(extraout_var_00,uVar25);
    *(undefined4 *)((longlong)param_1 + 0xa920) = extraout_EAX_09;
  }
  uVar9 = HandleAdapterConfigIssues((longlong)param_1,uVar7,uVar9,uVar21);
  local_354 = (uint)uVar9;
  if (local_354 == 0) {
    uVar25 = puVar18[0x19];
    *(undefined4 *)((longlong)param_1 + 0xaa14) = *(undefined4 *)((longlong)param_1 + 0x80bc);
    *(undefined4 *)((longlong)param_1 + 0xaa10) = *(undefined4 *)((longlong)param_1 + 0x80b8);
    *(undefined4 *)((longlong)param_1 + 0xaa0c) = 0;
    *(ushort *)((longlong)param_1 + 0xaa1c) = (ushort)*(byte *)((longlong)param_1 + 0x13d0);
    *(uint *)((longlong)param_1 + 0xaa18) = CONCAT22(local_2ea,local_2ec);
    *(undefined2 *)((longlong)param_1 + 0xaa1e) = 0x305;
    *(char *)((longlong)param_1 + 0xaa20) = (char)puVar18[1];
    bVar11 = (byte)uVar25 & 0x1f;
    *(byte *)((longlong)param_1 + 0xaa21) = bVar11;
    *(byte *)((longlong)param_1 + 0xaa22) = (byte)(uVar25 >> 5) & 7;
    LongToAscii((ulonglong)bVar11,*(uint *)((longlong)param_1 + 0x1394),
                (char *)((longlong)param_1 + 0xaa40));
    *(undefined4 *)((longlong)param_1 + 0xaaa4) = 8;
    *(undefined2 *)((longlong)param_1 + 0xaa9e) = *(undefined2 *)((longlong)param_1 + 5000);
    *(ushort *)((longlong)param_1 + 0xaa9a) = (ushort)*(byte *)((longlong)param_1 + 4999);
    *(ushort *)((longlong)param_1 + 0xaa9c) = (ushort)*(byte *)((longlong)param_1 + 0x1386);
    *(undefined2 *)((longlong)param_1 + 0xaaa0) = 0;
    *(undefined2 *)((longlong)param_1 + 0xaa96) = *(undefined2 *)((longlong)param_1 + 0x1370);
    *(ushort *)((longlong)param_1 + 0xaa92) = (ushort)*(byte *)((longlong)param_1 + 0x136f);
    *(ushort *)((longlong)param_1 + 0xaa94) = (ushort)*(byte *)((longlong)param_1 + 0x136e);
    *(undefined2 *)((longlong)param_1 + 0xaa98) = 0;
    *(undefined8 *)((longlong)param_1 + 0xaaae) = 0;
    *(undefined2 *)((longlong)param_1 + 0xaab6) = 0;
    *(undefined4 *)((longlong)param_1 + 0xaaaa) = 0;
    *(undefined2 *)((longlong)param_1 + 0xaaa8) = 0;
    GetDriverParameter("EnableWMI",0,0,1,pcVar17);
    if (extraout_EAX_10 == 1) {
      *(undefined1 *)((longlong)param_1 + 0x517d) = 1;
      *(undefined1 *)((longlong)puVar18 + 0x93) = 1;
      InitializeWmiInterface((longlong)param_1);
    }
    *(undefined1 *)((longlong)param_1 + 0x618) = 0;
    puVar13 = (undefined2 *)((longlong)param_1 + 0xd8dc);
    puVar10 = (undefined4 *)((longlong)param_1 + 0xcee8);
    puVar15 = (undefined8 *)((longlong)param_1 + 0xc6f8);
    do {
      puVar15[-0x17d] = 0;
      puVar10[-0x2fa] = 0;
      *puVar15 = 0xdeadbeef;
      puVar15 = puVar15 + 1;
      *puVar10 = 0;
      puVar10[0xfe] = 0;
      puVar10 = puVar10 + 1;
      puVar13[-0xfe] = 0;
      *puVar13 = 0;
      puVar13 = puVar13 + 1;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
    *(undefined8 *)((longlong)param_1 + 55000) = 0;
    ArcPrintf((longlong)param_1,4,(byte *)"* - Driver version %s, adapter number %d, HwDevExt=%x\n",
              0x1c0015d90);
    uVar21 = 0xe2f0;
    ArcPrintf((longlong)param_1,4,(byte *)"* - Size of HwDevExt=0x%x. Size of COMM_REGION=0x%x\n",
              0xe2f0);
    ArcPrintf((longlong)param_1,4,(byte *)"* - Done FindAdapter\n",uVar21);
    uVar21 = (ulonglong)puVar18[6];
    ArcPrintf((longlong)param_1,4,
              (byte *)
              "* - ConfigInfo->MaximumTransferLength (0x%x), pDeviceExtension->QueueAllowed (0x%x)\n"
              ,uVar21);
    ArcPrintf((longlong)param_1,0x10000200,(byte *)"leaving FindAdapter - adapter found!\n",uVar21);
    *(undefined4 *)((longlong)param_1 + 0x180) = 0x53434d50;
    *(undefined4 *)((longlong)param_1 + 0x184) = 0x30383331;
    *(undefined4 *)((longlong)param_1 + 0xe2e8) = 0x55aa55aa;
    *(undefined8 *)((longlong)param_1 + 0xbad4) = 0;
    *(undefined8 *)((longlong)param_1 + 0xbadc) = 0;
    *(undefined8 *)((longlong)param_1 + 0xbaf8) = 0;
    *(undefined8 *)((longlong)param_1 + 0xbae8) = 0;
    *(undefined8 *)((longlong)param_1 + 0xbb00) = 0;
    *(undefined4 *)((longlong)param_1 + 0xbb08) = 0;
    *(undefined4 *)((longlong)param_1 + 0xbaf0) = 0;
    *(undefined4 *)((longlong)param_1 + 57000) = 0;
    memset((void *)((longlong)param_1 + 0xdeac),0,0x3f8);
    uVar21 = 1;
    GetDriverParameter("BreakPointHelper",0,0,1,pcVar17);
    *(int *)((longlong)param_1 + 0xbaf4) = extraout_EAX_11;
    if (extraout_EAX_11 != 0) {
      iVar6 = 1000000;
      do {
        StorPortStallExecution(10);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      ArcPrintf((longlong)param_1,4,(byte *)"* 10 seconds waiting is done\n",uVar21);
    }
    return 1;
  }
  ArcLogEventString(param_1,uVar7,local_354 + 0xe01a0000,local_354,pcVar16,0x60);
  gAdapterAddCount = gAdapterAddCount - 1;
  ArcPrintf((longlong)param_1,0x10000200,
            (byte *)"leaving FindAdapter - fail HandleAdapterConfigIssue, rtnval = \n",
            (ulonglong)local_354);
  pcVar16 = "* leaving FindAdapter - fail HandleAdapterConfigIssue, rtnval = \n";
  uVar25 = local_354;
LAB_1c0007ec0:
  ArcPrintf((longlong)param_1,1,(byte *)pcVar16,(ulonglong)uVar25);
  return 0;
}



===== GetElapsedSeconds @ 1c0008c7c =====

uint GetElapsedSeconds(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  uint uVar2;
  longlong local_res10 [3];
  
  uVar2 = 0;
  local_res10[0] = 0;
  ArcPrintf(param_1,0x10000200,(byte *)"entering GetElapsedSeconds \n",param_4);
  StorPortQuerySystemTime(local_res10);
  lVar1 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(local_res10[0]),8) + local_res10[0];
  lVar1 = (lVar1 >> 0x17) - (lVar1 >> 0x3f);
  if (-1 < lVar1 + -0x2b6109100) {
    uVar2 = (int)lVar1 + 0x49ef6f00;
  }
  ArcPrintf(param_1,0x10000200,(byte *)"leaving GetElapsedSeconds - secondsSince1970 = %x\n",
            (ulonglong)uVar2);
  return uVar2;
}



===== IOPReset @ 1c0008d08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char IOPReset(longlong param_1,char param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  char cVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  ulonglong uVar6;
  longlong *plVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  longlong lVar10;
  uint uVar11;
  int local_res8 [2];
  uint local_res10 [2];
  undefined4 in_stack_ffffffffffffff78;
  undefined4 in_stack_ffffffffffffff7c;
  ulonglong in_stack_ffffffffffffff80;
  uint uVar12;
  
  local_res10[0] = 0;
  ArcPrintf(param_1,0x10000200,(byte *)"entering IOPReset\n",param_4);
  lVar10 = 0x1e;
  if (*(char *)(param_1 + 0x516a) == '\0') {
    lVar10 = 3;
  }
  StorPortPause(param_1);
  uVar11 = *(uint *)(param_1 + 0x5e08);
  *(undefined4 *)(param_1 + 0x1d0) = 4;
  *(undefined8 *)(param_1 + 0x188) = 0;
  *(undefined1 *)(param_1 + 0x617) = 1;
  *(uint *)(param_1 + 0x5e08) = uVar11 & 0xdfffffff;
  if (param_2 == '\0') {
    if (*(char *)(param_1 + 0x61c) == '\0') {
      uVar12 = (uint)(in_stack_ffffffffffffff80 >> 0x20);
      if (*(char *)(param_1 + 0x61b) == '\0') {
        param_4 = 0;
        lVar10 = 0x1000;
        in_stack_ffffffffffffff78 = 0;
        cVar2 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                          (param_1,0x1000,0,0,0,(ulonglong)uVar12 << 0x20,0,0,0,0,local_res10,1);
        if ((((byte)local_res10[0] & 0xf) != 10) && (*(char *)(param_1 + 0x61a) != '\0')) {
          lVar10 = 3;
          (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x50))(param_1);
          cVar2 = '\x01';
          local_res10[0] = 1;
        }
      }
      else {
        iVar5 = *(int *)(param_1 + 0x1588);
        if (iVar5 != 0) goto LAB_1c0008dd4;
        param_4 = 0;
        lVar10 = 0x1001;
        in_stack_ffffffffffffff78 = 0;
        cVar2 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                          (param_1,0x1001,0,0,0,(ulonglong)uVar12 << 0x20,local_res8,0,0,0,
                           local_res10,1);
        if (cVar2 == '\0') goto LAB_1c0008ff3;
        if (local_res10[0] == 1) {
          *(int *)(*(longlong *)(param_1 + 0x1a8) + 0x20) = local_res8[0];
          goto LAB_1c0008f63;
        }
      }
LAB_1c0008fe8:
      if (cVar2 != '\0') goto LAB_1c0008fed;
    }
    else {
      local_res10[0] = 10;
      lVar10 = 1;
      ArcPrintf(param_1,1,
                (byte *)
                "** Fail to iopreset the adapter because the Ignore_IOP_Reset flag is set...\n",
                param_4);
    }
LAB_1c0008ff3:
    if (((byte)local_res10[0] & 0xf) == 10) {
      uVar3 = 0x20;
      uVar9 = 0x13;
      uVar8 = 0xe01a0013;
    }
    else {
      uVar3 = 0x50;
      uVar9 = 0x12;
      uVar8 = 0xe01a0012;
    }
    ArcLogEventString(param_1,lVar10,uVar8,uVar9,
                      CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),uVar3);
    param_4 = (ulonglong)local_res10[0];
    ArcPrintf(param_1,1,(byte *)"** Fail to iopreset the adapter, returnStatus = %x\n",param_4);
    cVar2 = '\0';
    *(uint *)(param_1 + 0x5e08) = uVar11;
    *(undefined1 *)(param_1 + 0x617) = 0;
LAB_1c0009059:
    if (cVar2 == '\0') goto LAB_1c000921d;
  }
  else {
    if (*(char *)(param_1 + 0x61a) == '\0') {
      iVar5 = *(int *)(param_1 + 0x1588);
      if ((iVar5 == 0) || (*(char *)(param_1 + 0x61b) == '\0')) {
        param_4 = 0;
        in_stack_ffffffffffffff80 = in_stack_ffffffffffffff80 & 0xffffffff00000000;
        in_stack_ffffffffffffff78 = 0;
        cVar2 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                          (param_1,0x1001,0,0,0,in_stack_ffffffffffffff80,local_res8,0,0,0,
                           local_res10,1);
        if ((cVar2 == '\0') || (local_res10[0] != 1)) {
          param_4 = 0;
          lVar10 = 0x1000;
          in_stack_ffffffffffffff78 = 0;
          cVar2 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                            (param_1,0x1000,0,0,0,in_stack_ffffffffffffff80 & 0xffffffff00000000,0,0
                             ,0,0,local_res10,1);
        }
        else {
          lVar10 = *(longlong *)(param_1 + 0x1a8);
          *(int *)(lVar10 + 0x20) = local_res8[0];
LAB_1c0008f63:
          LOCK();
          UNLOCK();
        }
        goto LAB_1c0008fe8;
      }
LAB_1c0008dd4:
      cVar2 = '\x01';
      local_res10[0] = 1;
      *(int *)(*(longlong *)(param_1 + 0x1a8) + 0x20) = iVar5;
      LOCK();
      UNLOCK();
      local_res8[0] = iVar5;
LAB_1c0008fed:
      if (local_res10[0] != 1) goto LAB_1c0008ff3;
      goto LAB_1c0009059;
    }
    (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x50))(param_1,3);
    cVar2 = '\x01';
    local_res10[0] = 1;
  }
  uVar11 = 0;
  ArcPrintf(param_1,1,(byte *)"** IOPReset succeeded.\n",param_4);
  ArcPrintf(param_1,1,(byte *)"** Trying to return pending SRB to OS.\n",param_4);
  uVar4 = GetOutstandingIoCnt(param_1);
  ArcPrintf(param_1,4,(byte *)"** outstandingIO before calling CompleteQueuedRequest is %d\n",
            (ulonglong)uVar4);
  if (uVar4 != 0) {
    plVar7 = (longlong *)(param_1 + 0x6050);
    lVar10 = 0x400;
    do {
      lVar1 = *plVar7;
      if (lVar1 != 0) {
        uVar11 = uVar11 + 1;
        if (*(char *)(param_1 + 0xaad6) != '\0') {
          uVar6 = (ulonglong)*(ushort *)(*(longlong *)(lVar1 + 0x28) + 0x16);
          uVar4 = *(ushort *)(param_1 + 0xb9c8 + uVar6 * 2);
          if (uVar4 == 0xffffffff) {
            *(undefined2 *)(param_1 + 0xb9c8 + uVar6 * 2) = 0;
          }
          else {
            *(ushort *)(param_1 + 0xb9c8 + uVar6 * 2) = uVar4 + 1;
          }
        }
        *plVar7 = 0;
        if (*(short *)(*(longlong *)(lVar1 + 0x28) + 4) != 700) {
          CompleteQueuedRequest(param_1,lVar1,0xe);
        }
        *(short *)(param_1 + 0xba22) = *(short *)(param_1 + 0xba22) + 1;
      }
      plVar7 = plVar7 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
  }
  param_4 = (ulonglong)uVar11;
  ArcPrintf(param_1,1,(byte *)"** returned %d SRB to OS.\n",param_4);
  *(undefined1 *)(param_1 + 0xe2d4) = 0;
  *(undefined2 *)(param_1 + 0xe2e4) = 0;
  memset((void *)(param_1 + 0xdeac),0,0x3f8);
  if ((*(int *)(param_1 + 0x8088) - 1U < 2) && (uVar11 = 0, *(int *)(param_1 + 0x8074) != 0)) {
    do {
      if ((*(uint *)(*(longlong *)(param_1 + 0x640) + (ulonglong)uVar11 * 4) & 0xffff) != 0) {
        param_4 = (ulonglong)uVar11;
        ArcPrintf(param_1,4,(byte *)"* Discard HOSTRRQ leftover: index %d, handle %d\n",param_4);
        *(undefined4 *)(*(longlong *)(param_1 + 0x640) + (ulonglong)uVar11 * 4) = 0;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < *(uint *)(param_1 + 0x8074));
  }
  if (((ushort)(*(short *)(param_1 + 0x158e) - 0x28cU) < 2) && (*(char *)(param_1 + 0xaad6) != '\0')
     ) {
    ArcPrintf(param_1,4,(byte *)"Driver should not work under MSIx mode, modify flags\n",param_4);
    *(undefined1 *)(param_1 + 0xaad6) = 0;
    *(undefined4 *)(*(longlong *)(param_1 + 0x630) + 4) = 0;
    ArcPrintf(param_1,4,(byte *)"* Set pInitStruct->NoOfMsiVectors to 0 in IOPReset\n",param_4);
  }
LAB_1c000921d:
  ArcPrintf(param_1,0x10000200,(byte *)"leaving IOPReset\n",param_4);
  return cVar2;
}



===== InitializeAdapterAfterIOPReset @ 1c000924c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0009465) */
/* WARNING: Removing unreachable block (ram,0x0001c0009474) */
/* WARNING: Removing unreachable block (ram,0x0001c000947c) */

char InitializeAdapterAfterIOPReset(longlong param_1,longlong param_2)

{
  ushort uVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  undefined2 *puVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined8 uVar11;
  undefined4 in_stack_ffffffffffffff98;
  undefined4 in_stack_ffffffffffffff9c;
  
  if (*(char *)(param_1 + 0x516a) != '\0') {
    param_2 = 0x1e;
    StorPortPause();
  }
  *(undefined4 *)(param_1 + 0x1d0) = 4;
  *(undefined1 *)(param_1 + 0x617) = 1;
  *(undefined8 *)(param_1 + 0x188) = 0;
  if (*(int *)(param_1 + 0xba14) != 0) {
    param_2 = *(longlong *)(param_1 + 0xba18);
    CompleteBufferedRequest(param_1,param_2);
    *(undefined8 *)(param_1 + 0xba18) = 0;
  }
  if ((*(int *)(param_1 + 0xa910) != 0) || (*(int *)(param_1 + 0xa914) != 0)) {
    DequeueRawIoReadWriteRequest(param_1,*(char *)(param_1 + 0x617),0xe);
    param_2 = 0;
    memset((void *)(param_1 + 0x9138),0,0x7f0);
  }
  sVar4 = GetOutstandingIoCnt(param_1);
  if (sVar4 != 0) {
    plVar10 = (longlong *)(param_1 + 0x6050);
    lVar9 = 0x400;
    do {
      param_2 = *plVar10;
      if (param_2 != 0) {
        if (*(char *)(param_1 + 0xaad6) != '\0') {
          uVar7 = (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x28) + 0x16);
          uVar1 = *(ushort *)(param_1 + 0xb9c8 + uVar7 * 2);
          if (uVar1 == 0xffffffff) {
            *(undefined2 *)(param_1 + 0xb9c8 + uVar7 * 2) = 0;
          }
          else {
            *(ushort *)(param_1 + 0xb9c8 + uVar7 * 2) = uVar1 + 1;
          }
        }
        *plVar10 = 0;
        CompleteQueuedRequest(param_1,param_2,0xe);
        *(short *)(param_1 + 0xba22) = *(short *)(param_1 + 0xba22) + 1;
      }
      plVar10 = plVar10 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
  }
  if (*(int *)(param_1 + 55000) != 0) {
    CompleteAllSortingQueue(param_1);
  }
  *(undefined8 *)(param_1 + 0xba20) = 0;
  puVar5 = (undefined2 *)(param_1 + 0xd8dc);
  *(undefined4 *)(param_1 + 0xba28) = 0;
  *(undefined1 *)(param_1 + 0x80e1) = 0;
  lVar9 = 0xfe;
  do {
    lVar8 = lVar9;
    puVar5[-0xfe] = 0;
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    lVar9 = lVar8 + -1;
  } while (lVar9 != 0);
  if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) && (*(char *)(param_1 + 0xaad6) != '\0')) {
    ArcLogEventString(param_1,param_2,0xe01a0011,(int)lVar8 + 0x10,
                      CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),0x60);
  }
  cVar2 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x30))(param_1);
  if (cVar2 == '\0') {
    cVar2 = '\0';
    ArcLogEventString(param_1,param_2,0xe01a0006,6,
                      CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),0x30);
LAB_1c00094f4:
    if (cVar2 != '\0') goto LAB_1c0009508;
  }
  else {
    uVar7 = 0;
    uVar11 = 0;
    uVar6 = 0x19;
    cVar3 = (*(code *)**(undefined8 **)(param_1 + 0x1320))(param_1);
    *(undefined4 *)(param_1 + 0x13a0) = 0;
    cVar2 = '\0';
    if (cVar3 != '\0') {
      if ((((*(char *)(param_1 + 0xaad6) == '\0') && (*(char *)(param_1 + 0x516a) == '\0')) &&
          ((*(uint *)(param_1 + 0xbad8) & 1) == 0)) &&
         (CheckMSIxPossibility(param_1,uVar6,uVar11,uVar7), *(char *)(param_1 + 0xaad6) != '\0')) {
        *(undefined1 *)(param_1 + 0xaadc) = 1;
      }
      uVar6 = InitializeAdapter(param_1,uVar6,uVar11,uVar7);
      cVar2 = (char)uVar6;
      goto LAB_1c00094f4;
    }
  }
  *(undefined4 *)(param_1 + 0x1d0) = 2;
  if (cVar2 == '\0') {
    return '\0';
  }
LAB_1c0009508:
  if (*(char *)(param_1 + 0x516a) != '\0') {
    StorPortResume(param_1);
  }
  *(undefined1 *)(param_1 + 0x617) = 0;
  if (((*(uint *)(param_1 + 0x5e08) & 0x20000000) == 0) &&
     (cVar3 = GetFwDebugBuffer(param_1,0), cVar3 != '\0')) {
    *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) | 0x20000000;
  }
  if (*(char *)(param_1 + 0x516a) != '\0') {
    StorPortNotification(7,param_1);
  }
  return cVar2;
}



===== CheckMSIxPossibility @ 1c0009578 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CheckMSIxPossibility(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  byte bVar1;
  undefined2 uVar2;
  ulonglong uVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  char *pcVar7;
  
  if (((*(ushort *)(param_1 + 0xaad4) == 0) || (*(char *)(param_1 + 0xaad0) == '\0')) ||
     (uVar4 = *(uint *)(param_1 + 0x8080), uVar4 < 2)) {
    pcVar7 = "* MSIX NOT Enabled\n";
  }
  else {
    bVar1 = *(byte *)(param_1 + 0xaae4);
    if (((ushort)bVar1 < *(ushort *)(param_1 + 0xaad4)) && (bVar1 != 0)) {
      *(ushort *)(param_1 + 0xaad4) = (ushort)bVar1;
    }
    if (uVar4 < *(ushort *)(param_1 + 0xaad4)) {
      *(ushort *)(param_1 + 0xaad4) = (ushort)uVar4 & 0xff;
    }
    if (*(ushort *)(param_1 + 0xaad2) < *(ushort *)(param_1 + 0xaad4)) {
      *(ushort *)(param_1 + 0xaad4) = *(ushort *)(param_1 + 0xaad2);
    }
    if (0x20 < *(ushort *)(param_1 + 0xaad4)) {
      *(undefined2 *)(param_1 + 0xaad4) = 0x20;
    }
    if (7 < *(ushort *)(param_1 + 0xaad4)) {
      *(undefined1 *)(param_1 + 0xaad6) = 1;
      (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x50))();
      uVar2 = (undefined2)(*(uint *)(param_1 + 0x8074) / (uint)*(ushort *)(param_1 + 0xaad4));
      *(undefined4 *)(param_1 + 0xaae0) = 0;
      uVar4 = 0;
      *(undefined2 *)(param_1 + 0xba08) = uVar2;
      *(undefined2 *)(param_1 + 0xba0a) = uVar2;
      *(undefined4 *)(param_1 + 0xba0c) = 0x3e9;
      *(undefined4 *)(param_1 + 0xba10) = 0x3b6;
      if (*(ushort *)(param_1 + 0xaad4) != 0) {
        do {
          uVar3 = (ulonglong)uVar4;
          uVar4 = uVar4 + 1;
          *(undefined2 *)(param_1 + 0xb988 + uVar3 * 2) = 0;
          *(undefined2 *)(param_1 + 0xb9c8 + uVar3 * 2) = 0;
          *(undefined1 *)(uVar3 + 0xb968 + param_1) = 0;
        } while (uVar4 < *(ushort *)(param_1 + 0xaad4));
      }
      if (*(char *)(param_1 + 0x618) == '\0') {
        ArcPrintf(param_1,4,(byte *)"======> Final Vector Number is %d <======\n",
                  (ulonglong)*(ushort *)(param_1 + 0xaad4));
        ArcPrintf(param_1,4,(byte *)"* pDeviceExtension->VectorCapacity: %d\n",
                  (ulonglong)*(ushort *)(param_1 + 0xba08));
        ArcPrintf(param_1,4,(byte *)"* pDeviceExtension->MSIXIoThrottlePauseIOLimit: %d\n",
                  (ulonglong)*(uint *)(param_1 + 0xba0c));
        param_4 = (ulonglong)*(uint *)(param_1 + 0xba10);
        ArcPrintf(param_1,4,(byte *)"* pDeviceExtension->MSIXIoThrottleResumeIOLimit: %d\n",param_4)
        ;
        ArcPrintf(param_1,4,(byte *)"* Switching to MSIx mode\n",param_4);
      }
      ArcPrintf(param_1,4,(byte *)"* MSIx Enabled\n",param_4);
      *(undefined4 *)(param_1 + 0xba14) = 0;
      *(undefined8 *)(param_1 + 0xba18) = 0;
      if (*(char *)(param_1 + 0xaad0) != '\0') {
        if (*(ushort *)(param_1 + 0xaad4) != 0) {
          param_4 = (ulonglong)*(uint *)(param_1 + 0x8074) /
                    (ulonglong)*(ushort *)(param_1 + 0xaad4) & 0xffff;
          uVar5 = 0;
          do {
            uVar6 = uVar5 + 1;
            *(uint *)(param_1 + 0xaee8 + (ulonglong)uVar5 * 4) = (int)param_4 * (uint)uVar5;
            *(uint *)(param_1 + 0xaf68 + (ulonglong)uVar5 * 4) = (uVar5 + 1) * (int)param_4 + -1;
            uVar5 = uVar6;
          } while (uVar6 < *(ushort *)(param_1 + 0xaad4));
        }
      }
      if (((*(char *)(param_1 + 0x614) != '\0') && (*(int *)(param_1 + 0x8080) != 0)) &&
         (*(char *)(param_1 + 0xaad0) != '\0')) {
        uVar5 = *(ushort *)(param_1 + 0xaad4);
        *(uint *)(*(longlong *)(param_1 + 0x630) + 4) = (uint)uVar5;
        if (*(char *)(param_1 + 0x618) == '\0') {
          ArcPrintf(param_1,4,
                    (byte *)"* Set pInitStruct->NoOfMsiVectors to %d in CheckMSIxPossibility\n",
                    (ulonglong)uVar5);
          return;
        }
        return;
      }
      *(undefined4 *)(*(longlong *)(param_1 + 0x630) + 4) = 0;
      if (*(char *)(param_1 + 0x618) != '\0') {
        return;
      }
      pcVar7 = "* Set pInitStruct->NoOfMsiVectors to 0 in CheckMSIxPossibility\n";
      goto LAB_1c0009830;
    }
    pcVar7 = "* MSIX NOT Enabled because MSIX vector number less than 8\n";
  }
  *(undefined1 *)(param_1 + 0xaad6) = 0;
  *(undefined2 *)(param_1 + 0xaad4) = 0;
  *(undefined1 *)(param_1 + 0xaad0) = 0;
LAB_1c0009830:
  ArcPrintf(param_1,4,(byte *)pcVar7,param_4);
  return;
}



===== HandleAdapterConfigIssues @ 1c000984c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
HandleAdapterConfigIssues(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined1 auStackY_248 [32];
  ushort local_208 [8];
  uint local_1f8 [7];
  undefined4 local_1dc;
  int local_1d8;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_248;
  ArcPrintf(param_1,0x10000200,(byte *)"entering HandleAdapterConfigIssues\n",param_4);
  memset(local_1f8,0,0x20);
  local_1f8[1] = 0x93;
  local_1dc = 8;
  uVar2 = 0x1d0;
  local_1f8[0] = 2;
  uVar1 = SendSynchFib(param_1,500,local_1f8,0x1d0,local_1f8,local_208,'\x01');
  if ((((char)uVar1 == '\0') || (local_1f8[0] != 0)) || (local_1f8[2] != 0xda)) {
    ArcPrintf(param_1,0x10000200,
              (byte *)"leaving HandleAdapterConfigIssues aborted: ARCMPE_GET_CONFIG_STATUS \n",uVar2
             );
    ArcPrintf(param_1,2,
              (byte *)"* leaving HandleAdapterConfigIssues aborted: ARCMPE_GET_CONFIG_STATUS \n",
              uVar2);
    uVar1 = 1;
  }
  else if (local_1d8 < 2) {
    memset(local_1f8,0,0x20);
    local_1f8[0] = 2;
    local_1f8[1] = 0x98;
    uVar2 = 0x1d0;
    uVar1 = SendSynchFib(param_1,500,local_1f8,0x1d0,local_1f8,local_208,'\x01');
    if ((((char)uVar1 == '\0') || (local_1f8[0] != 0)) || (local_1f8[2] != 0xda)) {
      ArcPrintf(param_1,0x10000200,
                (byte *)"leaving HandleAdapterConfigIssues aborted: ARCMPE_COMMIT_CONFIG \n",uVar2);
      ArcPrintf(param_1,2,
                (byte *)"* leaving HandleAdapterConfigIssues aborted: ARCMPE_COMMIT_CONFIG \n",uVar2
               );
      uVar1 = 3;
    }
    else {
      ArcPrintf(param_1,0x10000200,(byte *)"leaving HandleAdapterConfigIssues\n",uVar2);
      uVar1 = 0;
    }
  }
  else {
    ArcPrintf(param_1,0x10000200,
              (byte *)"leaving HandleAdapterConfigIssues aborted: ARCMPE_CONFIG_STATUS \n",uVar2);
    ArcPrintf(param_1,2,
              (byte *)"* leaving HandleAdapterConfigIssues aborted: ARCMPE_CONFIG_STATUS \n",uVar2);
    uVar1 = 2;
  }
  return uVar1;
}



===== InitializeAdapter @ 1c0009a28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
InitializeAdapter(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined1 local_res8 [32];
  undefined8 in_stack_ffffffffffffffe8;
  
  pcVar5 = "entering InitializeAdapter\n";
  local_res8[0] = 0;
  uVar4 = 0x10000200;
  ArcPrintf(param_1,0x10000200,(byte *)"entering InitializeAdapter\n",param_4);
  if (*(int *)(param_1 + 0x1d0) != 1) {
    uVar2 = GetElapsedSeconds(param_1,uVar4,pcVar5,param_4);
    uVar3 = (ulonglong)uVar2;
    pcVar5 = *(char **)(*(longlong *)(param_1 + 0x1320) + 8);
    cVar1 = (*(code *)pcVar5)(param_1);
    if (cVar1 == '\0') {
      if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) && (*(char *)(param_1 + 0xaad6) != '\0')) {
        param_4 = 0x26;
        ArcLogEventString(param_1,uVar3,0xe01a0026,0x26,in_stack_ffffffffffffffe8,0xc0);
      }
      ArcPrintf(param_1,0x10000200,(byte *)"leaving InitializeAdapter: fail START_ADAPTER\n",param_4
               );
      uVar3 = ArcPrintf(param_1,1,(byte *)"* leaving InitializeAdapter: fail START_ADAPTER\n",
                        param_4);
      return uVar3 & 0xffffffffffffff00;
    }
    *(undefined4 *)(param_1 + 0x1d0) = 1;
  }
  *(undefined1 *)(param_1 + 0xbad0) = 0;
  ConfigureContainersInit(param_1,local_res8,pcVar5,param_4);
  *(undefined1 *)(param_1 + 0xbad0) = 1;
  uVar4 = ArcPrintf(param_1,0x10000200,(byte *)"leaving InitializeAdapter\n",param_4);
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
}



===== HwInitializeAdapter @ 1c0009b20 =====

undefined1
HwInitializeAdapter(longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  code *pcVar9;
  char *pcVar10;
  undefined4 *puVar11;
  undefined4 local_res8 [2];
  undefined4 in_stack_ffffffffffffffa8;
  undefined4 in_stack_ffffffffffffffac;
  undefined4 local_48;
  undefined1 local_44 [4];
  uint local_40;
  
  local_48 = 0;
  memset(local_44,0,0x24);
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x8000;
  ArcPrintf(param_1,0x10000200,(byte *)"entering HwInitializeAdapter\n",param_4);
  puVar11 = local_res8;
  local_res8[0] = 0;
  pcVar9 = InitializeDPCs;
  lVar5 = param_1;
  StorPortNotification(0x1000);
  uVar7 = 1;
  pcVar10 = (char *)pcVar9;
  if ((char)local_res8[0] == '\0') {
    *(undefined1 *)(param_1 + 0x613) = 0;
    *(undefined1 *)(param_1 + 0xa924) = 0;
    *(undefined1 *)(param_1 + 0x15a6) = 0;
    if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) && (*(char *)(param_1 + 0xaad6) != '\0')) {
      puVar11 = (undefined4 *)0x10;
      pcVar10 = (char *)0xa01a0010;
      ArcLogEventString(param_1,lVar5,0xa01a0010,0x10,
                        CONCAT44(in_stack_ffffffffffffffac,in_stack_ffffffffffffffa8),0xa0);
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x613) = 1;
  }
  if ((*(char *)(param_1 + 0x15a5) != '\0') || (uVar1 = 0, *(char *)(param_1 + 0x15a6) != '\0')) {
    uVar1 = 1;
  }
  *(undefined1 *)(param_1 + 0x15a5) = uVar1;
  if (*(char *)(param_1 + 0x613) != '\0') {
    StorPortExtendedFunction(0xe,param_1,1,&local_48);
    puVar11 = &local_48;
    local_48 = 4;
    local_40 = local_40 & 0xfffffff3 | 1;
    pcVar10 = (char *)0x0;
    lVar5 = param_1;
    StorPortExtendedFunction(0xe);
    if (*(char *)(param_1 + 0x613) != '\0') {
      uVar6 = 0;
      do {
        pcVar10 = (char *)(ulonglong)uVar6;
        puVar11 = (undefined4 *)(param_1 + 0xaae8 + (ulonglong)uVar6 * 0x20);
        lVar5 = param_1;
        iVar3 = StorPortExtendedFunction(0xd);
        if (iVar3 == 0) {
          *(short *)(param_1 + 0xaad4) = *(short *)(param_1 + 0xaad4) + 1;
        }
        else if (uVar6 == 0) {
          puVar11 = (undefined4 *)0x0;
          pcVar10 = "* StorPortGetMSIInfo returned Failed for vector %x with SP status %x \n";
          lVar5 = 4;
          ArcPrintf(param_1,4,
                    (byte *)
                    "* StorPortGetMSIInfo returned Failed for vector %x with SP status %x \n",0);
          if (iVar3 == -0x3efffffe) {
            pcVar10 = "* StorPortGetMSIInfo returned status STOR_STATUS_NOT_IMPLEMENTED\n";
            lVar5 = 4;
            ArcPrintf(param_1,4,
                      (byte *)"* StorPortGetMSIInfo returned status STOR_STATUS_NOT_IMPLEMENTED\n",
                      (ulonglong)puVar11);
          }
          if (iVar3 == -0x3efffffa) {
            pcVar10 = "* StorPortGetMSIInfo returned status STOR_STATUS_INVALID_PARAMETER\n";
            lVar5 = 4;
            ArcPrintf(param_1,4,
                      (byte *)"* StorPortGetMSIInfo returned status STOR_STATUS_INVALID_PARAMETER\n"
                      ,(ulonglong)puVar11);
          }
          if (iVar3 == -0x3efffff9) {
            pcVar10 = "* StorPortGetMSIInfo returned status STOR_STATUS_INVALID_DEVICE_REQUEST\n";
            lVar5 = 4;
            ArcPrintf(param_1,4,
                      (byte *)
                      "* StorPortGetMSIInfo returned status STOR_STATUS_INVALID_DEVICE_REQUEST\n",
                      (ulonglong)puVar11);
          }
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0x20);
    }
  }
  CheckMSIxPossibility(param_1,lVar5,pcVar10,(ulonglong)puVar11);
  if (*(char *)(param_1 + 0x516a) != '\0') {
    lVar5 = 0;
    *(undefined4 *)(param_1 + 0x1d0) = 4;
    *(undefined1 *)(param_1 + 0x619) = 0;
    *(undefined4 *)(param_1 + 0x648) = 0;
    cVar2 = IOPReset(param_1,'\0',pcVar10,(ulonglong)puVar11);
    if (cVar2 != '\0') {
      *(undefined2 *)(param_1 + 0x618) = 1;
      ArcPrintf(param_1,4,&s_____Done_HwInitialize_,(ulonglong)puVar11);
      ArcPrintf(param_1,4,(byte *)"leaving HwInitializeAdapter, line #%d, status = TRUE\n",0x11f8);
      goto LAB_1c0009de4;
    }
    *(undefined4 *)(param_1 + 0x1d0) = 2;
  }
  uVar4 = InitializeAdapter(param_1,lVar5,pcVar10,(ulonglong)puVar11);
  ArcPrintf(param_1,4,&s_____Done_HwInitialize_,(ulonglong)puVar11);
  ArcPrintf(param_1,0x10000200,(byte *)"leaving HwInitializeAdapter\n",(ulonglong)puVar11);
  if (*(int *)(param_1 + 0x8088) - 1U < 2) {
    uVar6 = 0x80;
    uVar8 = 10000;
  }
  else {
    uVar8 = 1000000;
    uVar6 = 1;
  }
  RequestTimer(param_1,uVar6,uVar8,2);
  uVar7 = (undefined1)uVar4;
LAB_1c0009de4:
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xffff7fff;
  return uVar7;
}



===== InitializeDPCs @ 1c0009e10 =====

undefined8 InitializeDPCs(longlong param_1,undefined8 param_2,undefined8 param_3,undefined *param_4)

{
  undefined8 uVar1;
  byte bVar2;
  ulonglong uVar3;
  code *pcVar4;
  
  ArcPrintf(param_1,0x10000200,(byte *)"entering InitializeDPC\n",(ulonglong)param_4);
  uVar3 = 0;
  if (((*(char *)(param_1 + 0x612) != '\0') && (*(char *)(param_1 + 0x613) != '\0')) &&
     (*(char *)(param_1 + 0x8084) != '\0')) {
    if (((ushort)(*(short *)(param_1 + 0x158e) - 0x28cU) < 2) &&
       (*(char *)(param_1 + 0xaad6) != '\0')) {
      if (*(short *)(param_1 + 0xaad4) != 0) {
        do {
          pcVar4 = PMCDpcResponseHandler;
          StorPortNotification(0x1001,param_1,param_1 + (uVar3 * 9 + 0x160d) * 8);
          bVar2 = (char)uVar3 + 1;
          uVar3 = (ulonglong)bVar2;
          param_4 = pcVar4;
        } while ((ushort)bVar2 < *(ushort *)(param_1 + 0xaad4));
      }
      ArcPrintf(param_1,4,(byte *)"* MSIx DPCs initialized\n",(ulonglong)param_4);
      *(undefined1 *)(param_1 + 0xaadc) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0xaadc) = 0;
    }
    pcVar4 = DpcDequeueRawIoReadWriteRequest;
    StorPortNotification(0x1001,param_1,param_1 + 0xa928);
    *(undefined1 *)(param_1 + 0xa9c1) = 1;
    param_4 = pcVar4;
  }
  ArcPrintf(param_1,4,&s_____Done_InitializeDPC_,(ulonglong)param_4);
  uVar1 = ArcPrintf(param_1,0x10000200,(byte *)"leaving InitializeDPC\n",(ulonglong)param_4);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== InitializeConsumerProducerCommRegion @ 1c0009f34 =====

bool InitializeConsumerProducerCommRegion
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  bool bVar3;
  longlong local_res8;
  undefined1 in_stack_ffffffffffffffe8;
  
  lVar1 = *(longlong *)(param_1 + 0x658);
  ArcPrintf(param_1,0x10000200,(byte *)"entering InitializeConsumerProducerCommRegion\n",
            (ulonglong)param_4);
  uVar2 = AllocateConsumerProducerCommArea
                    (param_1,param_2,&local_res8,param_4,in_stack_ffffffffffffffe8);
  bVar3 = (char)uVar2 != '\0';
  if (bVar3) {
    *(longlong *)(lVar1 + 0x18) = local_res8;
    *(longlong *)(lVar1 + 0x20) = local_res8 + 4;
    **(undefined4 **)(lVar1 + 0x18) = 8;
    **(undefined4 **)(lVar1 + 0x20) = 8;
    *(longlong *)(lVar1 + 0x78) = local_res8 + 8;
    *(longlong *)(lVar1 + 0x80) = local_res8 + 0xc;
    *(longlong *)(lVar1 + 8) = local_res8 + 0x40;
    *(undefined4 *)(lVar1 + 0x28) = 8;
    **(undefined4 **)(lVar1 + 0x78) = 4;
    **(undefined4 **)(lVar1 + 0x80) = 4;
    *(longlong *)(lVar1 + 0xd8) = local_res8 + 0x10;
    *(longlong *)(lVar1 + 0xe0) = local_res8 + 0x14;
    *(longlong *)(lVar1 + 0x68) = local_res8 + 0x80;
    *(undefined4 *)(lVar1 + 0x88) = 4;
    **(undefined4 **)(lVar1 + 0xd8) = 0x200;
    **(undefined4 **)(lVar1 + 0xe0) = 0x200;
    *(longlong *)(lVar1 + 0x138) = local_res8 + 0x18;
    *(longlong *)(lVar1 + 0x140) = local_res8 + 0x1c;
    *(longlong *)(lVar1 + 200) = local_res8 + 0xa0;
    *(undefined4 *)(lVar1 + 0xe8) = 0x200;
    **(undefined4 **)(lVar1 + 0x138) = 4;
    **(undefined4 **)(lVar1 + 0x140) = 4;
    *(longlong *)(lVar1 + 0x48) = local_res8 + 0x20;
    *(longlong *)(lVar1 + 0x50) = local_res8 + 0x24;
    *(longlong *)(lVar1 + 0x128) = local_res8 + 0x10a0;
    *(undefined4 *)(lVar1 + 0x148) = 4;
    **(undefined4 **)(lVar1 + 0x48) = 0x200;
    **(undefined4 **)(lVar1 + 0x50) = 0x200;
    *(longlong *)(lVar1 + 0xa8) = local_res8 + 0x28;
    *(longlong *)(lVar1 + 0xb0) = local_res8 + 0x2c;
    *(longlong *)(lVar1 + 0x38) = local_res8 + 0x10c0;
    *(undefined4 *)(lVar1 + 0x58) = 0x200;
    **(undefined4 **)(lVar1 + 0xa8) = 4;
    **(undefined4 **)(lVar1 + 0xb0) = 4;
    *(longlong *)(lVar1 + 0x108) = local_res8 + 0x30;
    *(longlong *)(lVar1 + 0x110) = local_res8 + 0x34;
    *(longlong *)(lVar1 + 0x98) = local_res8 + 0x20c0;
    *(undefined4 *)(lVar1 + 0xb8) = 4;
    **(undefined4 **)(lVar1 + 0x108) = 8;
    **(undefined4 **)(lVar1 + 0x110) = 8;
    *(longlong *)(lVar1 + 0xf8) = local_res8 + 0x20e0;
    *(longlong *)(lVar1 + 0x168) = local_res8 + 0x38;
    *(longlong *)(lVar1 + 0x170) = local_res8 + 0x3c;
    *(undefined4 *)(lVar1 + 0x118) = 8;
    **(undefined4 **)(lVar1 + 0x168) = 4;
    **(undefined4 **)(lVar1 + 0x170) = 4;
    *(longlong *)(lVar1 + 0x158) = local_res8 + 0x2120;
    *(undefined4 *)(lVar1 + 0x178) = 4;
    ArcPrintf(param_1,0x10000200,(byte *)"leaving InitializeConsumerProducerCommRegion\n",0x200);
  }
  else {
    ArcPrintf(param_1,0x10000200,(byte *)"leaving InitializeConsumerProducerCommRegion fails\n",
              (ulonglong)param_4);
    ArcPrintf(param_1,1,(byte *)"leaving InitializeConsumerProducerCommRegion fails\n",
              (ulonglong)param_4);
  }
  return bVar3;
}



===== InitializeConsumerProducerNewAdapter @ 1c000a184 =====

bool InitializeConsumerProducerNewAdapter
               (void *param_1,undefined8 param_2,undefined4 param_3,undefined1 *param_4)

{
  bool bVar1;
  undefined8 uVar2;
  
  ArcPrintf((longlong)param_1,0x10000200,(byte *)"entering InitializeConsumerProducerNewAdapter\n",
            (ulonglong)param_4);
  memset((undefined8 *)((longlong)param_1 + 0x658),0,0x28);
  *(void **)((longlong)param_1 + 0x678) = param_1;
  *(undefined8 *)((longlong)param_1 + 0x660) = *(undefined8 *)((longlong)param_1 + 0x1a8);
  if (*(short *)((longlong)param_1 + 0x158e) == 0x288) {
    uVar2 = *(undefined8 *)((longlong)param_1 + 0x1b0);
  }
  else {
    uVar2 = *(undefined8 *)((longlong)param_1 + 0x1a8);
  }
  *(undefined8 *)((longlong)param_1 + 0x668) = uVar2;
  uVar2 = 0x180;
  *(undefined4 *)((longlong)param_1 + 0x670) = param_3;
  *(undefined8 *)((longlong)param_1 + 0x658) = param_1;
  memset(param_1,0,0x180);
  bVar1 = InitializeConsumerProducerCommRegion((longlong)param_1,param_2,uVar2,param_4);
  if (bVar1) {
    ArcPrintf((longlong)param_1,0x10000200,
              (byte *)"leaving InitializeConsumerProducerNewAdapter: TRUE\n",(ulonglong)param_4);
  }
  else {
    ArcPrintf((longlong)param_1,0x10000200,
              (byte *)"leaving InitializeConsumerProducerNewAdapter: FLASE\n",(ulonglong)param_4);
  }
  return bVar1;
}



===== InitializeMessageUnitQueueNewAdapter @ 1c000a258 =====

bool InitializeMessageUnitQueueNewAdapter
               (void *param_1,undefined8 param_2,undefined4 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  bool bVar2;
  
  ArcPrintf((longlong)param_1,0x10000200,(byte *)"entering InitializeMessageUnitQueueNewAdapter\n",
            param_4);
  memset((undefined8 *)((longlong)param_1 + 0x658),0,0x28);
  *(void **)((longlong)param_1 + 0x678) = param_1;
  uVar1 = 0x180;
  *(undefined8 *)((longlong)param_1 + 0x660) = *(undefined8 *)((longlong)param_1 + 0x1a8);
  *(undefined4 *)((longlong)param_1 + 0x670) = param_3;
  *(undefined8 *)((longlong)param_1 + 0x658) = param_1;
  memset(param_1,0,0x180);
  uVar1 = AllocateMessageUnitQueueCommArea((longlong)param_1,param_2,uVar1,param_4);
  bVar2 = (char)uVar1 != '\0';
  if (bVar2) {
    ArcPrintf((longlong)param_1,0x10000200,
              (byte *)"leaving InitializeMessageUnitQueueNewAdapter: TRUE\n",param_4);
  }
  else {
    ArcPrintf((longlong)param_1,0x10000200,
              (byte *)"leaving InitializeMessageUnitQueueNewAdapter: FALSE\n",param_4);
  }
  return bVar2;
}



===== MapDeviceBase @ 1c000a30c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool MapDeviceBase(longlong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  char *pcVar7;
  ulonglong uVar8;
  bool bVar9;
  uint local_res8 [2];
  int local_res10 [2];
  undefined4 uVar10;
  undefined4 in_stack_ffffffffffffff7c;
  ulonglong in_stack_ffffffffffffff80;
  wchar_t *pwVar11;
  
  local_res8[0] = 0;
  bVar2 = false;
  ArcPrintf(param_1,0x10000200,(byte *)"entering MapDeviceBase\n",param_4);
  uVar10 = *(undefined4 *)(param_1 + 0x80a8);
  uVar6 = (ulonglong)*(uint *)(param_2 + 8);
  uVar8 = **(ulonglong **)(param_2 + 0x38);
  pwVar11 = (wchar_t *)(in_stack_ffffffffffffff80 & 0xffffffffffffff00);
  lVar4 = StorPortGetDeviceBase(param_1,uVar6,*(undefined4 *)(param_2 + 4),uVar8,uVar10,pwVar11);
  *(longlong *)(param_1 + 0x1a8) = lVar4;
  if (lVar4 == 0) {
    ArcPrintf(param_1,1,(byte *)"* StorPortGetDeviceBase failed, can\'t map the device base\n",uVar8
             );
    bVar9 = false;
  }
  else {
    cVar3 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x30))();
    bVar9 = cVar3 != '\0';
    if (!bVar9) {
      pwVar11 = L"Adapter boot time out";
      ArcLogEventString(param_1,uVar6,0xe01a0006,6,CONCAT44(in_stack_ffffffffffffff7c,uVar10),0x30);
      gAdapterAddCount = gAdapterAddCount + -1;
    }
    if ((*(short *)(param_1 + 0x158e) == 0x288) ||
       ((ushort)(*(short *)(param_1 + 0x158e) - 0x28bU) < 3)) {
      pwVar11 = (wchar_t *)((ulonglong)pwVar11 & 0xffffffffffffff00);
      uVar5 = StorPortGetDeviceBase
                        (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),
                         *(undefined8 *)(*(longlong *)(param_2 + 0x38) + 0x10),
                         *(undefined4 *)(param_1 + 0x80ac),pwVar11);
      *(undefined8 *)(param_1 + 0x1b0) = uVar5;
    }
    RxMapMailBoxFirmwareBase(param_1);
    pwVar11 = (wchar_t *)((ulonglong)pwVar11 & 0xffffffff00000000);
    cVar3 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                      (param_1,0x19,0,0,0,pwVar11,(undefined4 *)(param_1 + 0x13a0),local_res8,
                       param_1 + 0x1588,0,local_res10,1);
    if ((cVar3 == '\0') || (local_res10[0] != 1)) {
      *(undefined4 *)(param_1 + 0x13a0) = 0;
      local_res8[0] = 0;
    }
  }
  if (*(short *)(param_1 + 0x158e) == 0x288) {
    if ((bVar9 != false) && (*(uint *)(param_1 + 0x80ac) < local_res8[0])) {
      StorPortFreeDeviceBase(param_1,*(undefined8 *)(param_1 + 0x1b0));
      uVar8 = (ulonglong)pwVar11 & 0xffffffffffffff00;
      lVar4 = StorPortGetDeviceBase
                        (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),
                         *(undefined8 *)(*(longlong *)(param_2 + 0x38) + 0x10),local_res8[0],uVar8);
      *(longlong *)(param_1 + 0x1b0) = lVar4;
      if (lVar4 == 0) {
        uVar6 = *(ulonglong *)(*(longlong *)(param_2 + 0x38) + 0x10);
        uVar8 = uVar8 & 0xffffffffffffff00;
        lVar4 = StorPortGetDeviceBase
                          (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),uVar6,
                           *(undefined4 *)(param_1 + 0x80ac),uVar8);
        *(longlong *)(param_1 + 0x1b0) = lVar4;
        bVar2 = true;
        if (lVar4 == 0) {
          ArcPrintf(param_1,1,
                    (byte *)
                    "* StorPortGetDeviceBaseB1 failed, can\'t map the device base for the new hardware interface\n"
                    ,uVar6);
          bVar9 = false;
        }
      }
      else {
        *(uint *)(param_1 + 0x80ac) = local_res8[0];
        bVar2 = false;
      }
      pwVar11 = (wchar_t *)(uVar8 & 0xffffffffffffff00);
      lVar4 = StorPortGetDeviceBase
                        (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),
                         *(undefined8 *)(*(longlong *)(param_2 + 0x38) + 0x20),0x80000,pwVar11);
      *(longlong *)(param_1 + 0x1b8) = lVar4;
      if (lVar4 != 0) {
        *(undefined4 *)(param_1 + 0x80b0) = 0x80000;
      }
LAB_1c000a640:
      if (bVar2) goto LAB_1c000a743;
    }
LAB_1c000a649:
    uVar1 = *(uint *)(param_1 + 0x13a0);
    if ((uVar1 >> 0x18 & 1) == 0) {
      if ((uVar1 >> 0x11 & 1) != 0) {
        *(undefined1 *)(param_1 + 0x8084) = 1;
      }
      if ((uVar1 >> 0x15 & 1) != 0) {
        *(undefined1 *)(param_1 + 0x80e0) = 1;
      }
      if ((uVar1 >> 0x16 & 1) != 0) {
        *(undefined1 *)(param_1 + 0x80e2) = 1;
      }
      if ((uVar1 >> 0x1c & 1) == 0) {
        if ((uVar1 >> 0x1d & 1) != 0) {
          *(undefined4 *)(param_1 + 0x8088) = 2;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x8088) = 1;
      }
      goto LAB_1c000a743;
    }
    uVar8 = 0;
    cVar3 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                      (param_1,0x33,0,0,0,(ulonglong)pwVar11 & 0xffffffff00000000,param_1 + 0x8090,
                       param_1 + 0x8094,param_1 + 0x8098,0,local_res10,1);
    if ((cVar3 != '\0') && (local_res10[0] == 1)) {
      ArcPrintf(param_1,4,(byte *)"* This is a BEDROC inplementation.\n",uVar8);
      *(undefined1 *)(param_1 + 0x808d) = 1;
      *(undefined2 *)(param_1 + 0x8092) = 0;
      goto LAB_1c000a743;
    }
    pcVar7 = "* GET_MINIARC_PROPERTIES fails, ARBORT we are DONE!!!\n";
  }
  else {
    if ((bVar9 == false) || (local_res8[0] <= *(uint *)(param_1 + 0x80a8))) goto LAB_1c000a649;
    StorPortFreeDeviceBase(param_1,*(undefined8 *)(param_1 + 0x1a8));
    pwVar11 = (wchar_t *)((ulonglong)pwVar11 & 0xffffffffffffff00);
    lVar4 = StorPortGetDeviceBase
                      (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),
                       **(undefined8 **)(param_2 + 0x38),local_res8[0],pwVar11);
    *(longlong *)(param_1 + 0x1a8) = lVar4;
    if (lVar4 != 0) {
      *(uint *)(param_1 + 0x80a8) = local_res8[0];
      goto LAB_1c000a640;
    }
    uVar8 = **(ulonglong **)(param_2 + 0x38);
    lVar4 = StorPortGetDeviceBase
                      (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),uVar8,
                       *(undefined4 *)(param_1 + 0x80a8),(ulonglong)pwVar11 & 0xffffffffffffff00);
    *(longlong *)(param_1 + 0x1a8) = lVar4;
    if (lVar4 != 0) goto LAB_1c000a743;
    pcVar7 = 
    "* StorPortGetDeviceBaseB0 failed, can\'t map the device base for the new hardware interface\n";
  }
  ArcPrintf(param_1,1,(byte *)pcVar7,uVar8);
  bVar9 = false;
LAB_1c000a743:
  RxMapMailBoxFirmwareBase(param_1);
  ArcPrintf(param_1,0x10000200,(byte *)"leaving MapDeviceBase - rtnval = %x\n",(ulonglong)bVar9);
  return bVar9;
}



===== ResetAndInitializeAdapter @ 1c000a780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char ResetAndInitializeAdapter
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  undefined1 uVar2;
  char cVar3;
  undefined2 *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  char cVar9;
  int iVar10;
  longlong *plVar11;
  undefined4 uVar12;
  char *pcVar13;
  undefined4 uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint local_res8;
  uint local_res10 [2];
  undefined4 local_res18 [4];
  undefined4 in_stack_ffffffffffffff78;
  undefined4 in_stack_ffffffffffffff7c;
  undefined8 in_stack_ffffffffffffff80;
  
  uVar15 = (uint)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);
  local_res10[0] = 0;
  ArcPrintf(param_1,0x10000200,(byte *)"entering ResetAndInitializeAdapter\n",param_4);
  uVar1 = *(uint *)(param_1 + 0x5e08);
  *(undefined4 *)(param_1 + 0x1d0) = 4;
  *(undefined8 *)(param_1 + 0x188) = 0;
  *(undefined1 *)(param_1 + 0x617) = 1;
  *(uint *)(param_1 + 0x5e08) = uVar1 & 0xdfffffff;
  if (*(char *)(param_1 + 0x61c) == '\0') {
    uVar16 = 0;
    if (*(char *)(param_1 + 0x61b) == '\0') {
      lVar7 = 0x1000;
      in_stack_ffffffffffffff78 = 0;
      cVar3 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                        (param_1,0x1000,0,0,0,(ulonglong)uVar15 << 0x20,0,0,0,0,local_res10,1);
      if ((((byte)local_res10[0] & 0xf) != 10) && (*(char *)(param_1 + 0x61a) != '\0')) {
        lVar7 = 3;
        (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x50))(param_1);
        iVar10 = 50000;
        do {
          StorPortStallExecution(100);
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        cVar3 = '\x01';
        local_res10[0] = 1;
      }
    }
    else {
      lVar7 = 0x1001;
      in_stack_ffffffffffffff78 = 0;
      cVar3 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                        (param_1,0x1001,0,0,0,(ulonglong)uVar15 << 0x20,local_res18,0,0,0,
                         local_res10,1);
      if (cVar3 == '\0') goto LAB_1c000a802;
      if (local_res10[0] == 1) {
        lVar7 = *(longlong *)(param_1 + 0x1a8);
        *(undefined4 *)(lVar7 + 0x20) = local_res18[0];
        LOCK();
        UNLOCK();
        iVar10 = 50000;
        do {
          StorPortStallExecution(100);
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
    if ((cVar3 == '\0') || (local_res10[0] != 1)) goto LAB_1c000a802;
    ArcPrintf(param_1,1,(byte *)"** IOPReset succeeded.\n",uVar16);
    plVar11 = (longlong *)(param_1 + 0x6050);
    lVar7 = 0x400;
    do {
      lVar8 = *plVar11;
      if (lVar8 != 0) {
        *plVar11 = 0;
        CompleteQueuedRequest(param_1,lVar8,0xe);
      }
      plVar11 = plVar11 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    if ((*(int *)(param_1 + 0xa910) != 0) || (*(int *)(param_1 + 0xa914) != 0)) {
      DequeueRawIoReadWriteRequest(param_1,*(char *)(param_1 + 0x617),0xe);
      lVar8 = 0;
      memset((void *)(param_1 + 0x9138),0,0x7f0);
    }
    *(undefined8 *)(param_1 + 0xba20) = 0;
    puVar4 = (undefined2 *)(param_1 + 0xd8dc);
    *(undefined4 *)(param_1 + 0xba28) = 0;
    *(undefined1 *)(param_1 + 0x80e1) = 0;
    lVar7 = 0xfe;
    do {
      lVar6 = lVar7;
      puVar4[-0xfe] = 0;
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
      lVar7 = lVar6 + -1;
    } while (lVar7 != 0);
    uVar15 = (int)lVar6 + 0x10;
    uVar16 = (ulonglong)uVar15;
    ArcLogEventString(param_1,lVar8,0x601a0011,uVar15,
                      CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),0x60);
    cVar3 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x30))(param_1);
    uVar5 = 1;
    if (cVar3 != '\0') {
      ArcPrintf(param_1,1,(byte *)"** Adapter is running after an IOPReset\n",uVar16);
      cVar3 = GetFwDebugBuffer(param_1,0);
      if (cVar3 != '\0') {
        *(uint *)(param_1 + 0x5e08) = uVar1;
      }
      ArcPrintf(param_1,4,(byte *)"* StorPort miniport driver version %s\n",0x1c0015d90);
      pcVar13 = (char *)0x0;
      uVar5 = 0x19;
      cVar3 = (*(code *)**(undefined8 **)(param_1 + 0x1320))(param_1);
      uVar16 = (ulonglong)local_res10[0];
      if ((cVar3 == '\0') || (local_res10[0] != 1)) {
        pcVar13 = "* IopReset: Can\'t determine adapter properties, status = %x\n";
        uVar5 = 4;
        ArcPrintf(param_1,4,(byte *)"* IopReset: Can\'t determine adapter properties, status = %x\n"
                  ,uVar16);
        *(uint *)(param_1 + 0x13a0) = 0;
      }
      else if ((*(uint *)(param_1 + 0x80a8) < local_res8) &&
              (*(uint *)(param_1 + 0x80ac) < local_res8)) {
        uVar16 = (ulonglong)*(uint *)(param_1 + 0x13a0);
        cVar9 = '\0';
        ArcPrintf(param_1,4,(byte *)"* IopReset: Adapter properties = %x,MapSizeInBytes = %x",uVar16
                 );
        goto LAB_1c000ab9e;
      }
      cVar9 = '\0';
      if (cVar3 == '\0') goto LAB_1c000ab9e;
      uVar5 = InitializeAdapter(param_1,uVar5,pcVar13,uVar16);
      cVar9 = (char)uVar5;
      goto LAB_1c000ab99;
    }
    cVar9 = '\0';
    ArcPrintf(param_1,1,(byte *)"* IopReset: ADAPTER NOT RUNNING!!!\n",uVar16);
    uVar16 = 6;
    ArcLogEventString(param_1,uVar5,0xe01a0006,6,
                      CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),0x30);
  }
  else {
    local_res10[0] = 10;
    lVar7 = 1;
    ArcPrintf(param_1,1,
              (byte *)
              "** Fail to iopreset the adapter because the Ignore_IOP_Reset flag is set...\n",
              param_4);
LAB_1c000a802:
    if (((byte)local_res10[0] & 0xf) == 10) {
      uVar2 = 0x20;
      uVar14 = 0x13;
      uVar12 = 0xa01a0013;
    }
    else {
      uVar2 = 0x50;
      uVar14 = 0x12;
      uVar12 = 0xa01a0012;
    }
    ArcLogEventString(param_1,lVar7,uVar12,uVar14,
                      CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),uVar2);
    uVar16 = (ulonglong)local_res10[0];
    ArcPrintf(param_1,1,(byte *)"** Fail to iopreset the adapter, returnStatus = %x\n",uVar16);
    cVar9 = '\0';
LAB_1c000ab99:
    if (cVar9 != '\0') goto LAB_1c000aba8;
  }
LAB_1c000ab9e:
  *(undefined4 *)(param_1 + 0x1d0) = 2;
LAB_1c000aba8:
  *(undefined1 *)(param_1 + 0x617) = 0;
  ArcPrintf(param_1,0x10000200,(byte *)"leaving ResetAndInitializeAdapter\n",uVar16);
  return cVar9;
}



===== ReturningLocalOutstandingRequestsToOS @ 1c000abd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ReturningLocalOutstandingRequestsToOS(longlong param_1)

{
  ushort uVar1;
  
  if (*(uint *)(param_1 + 0xba14) != 0) {
    ArcPrintf(param_1,4,(byte *)"* Calling CompleteBufferedRequest for %d buffered IO\n",
              (ulonglong)*(uint *)(param_1 + 0xba14));
    CompleteBufferedRequest(param_1,*(longlong *)(param_1 + 0xba18));
    *(undefined8 *)(param_1 + 0xba18) = 0;
  }
  if ((*(uint *)(param_1 + 0xa910) != 0) || (*(int *)(param_1 + 0xa914) != 0)) {
    ArcPrintf(param_1,4,
              (byte *)
              "* Calling DequeueRawIoReadWriteRequest for %d pDeviceExtension->CtQueueCount or %d pDeviceExtension->JBODQueueCount\n"
              ,(ulonglong)*(uint *)(param_1 + 0xa910));
    DequeueRawIoReadWriteRequest(param_1,'\x01',0xe);
    memset((void *)(param_1 + 0x9138),0,0x7f0);
  }
  if (*(uint *)(param_1 + 55000) != 0) {
    ArcPrintf(param_1,4,(byte *)"* Calling CompleteAllSortingQueue for %d IO in Sorting Queue\n",
              (ulonglong)*(uint *)(param_1 + 55000));
    CompleteAllSortingQueue(param_1);
  }
  if (*(char *)(param_1 + 0x8084) == '\0') {
    (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x18))(param_1,param_1 + 0x658,1);
  }
  uVar1 = GetOutstandingIoCnt(param_1);
  ArcPrintf(param_1,4,(byte *)"* %d outstanding IO left after calling %s\n",(ulonglong)uVar1);
  return;
}



===== ResetAdapter @ 1c000acf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool ResetAdapter(longlong param_1,uint param_2,undefined8 param_3,ulonglong param_4)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  uint *puVar8;
  char *pcVar9;
  undefined4 *puVar10;
  ulonglong uVar11;
  uint uVar12;
  bool bVar13;
  undefined1 auStackY_118 [32];
  uint local_d8;
  ushort local_d4 [2];
  undefined4 local_d0 [2];
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  uint local_a8 [24];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c8 = 0;
  bVar13 = false;
  local_c0 = 0;
  local_d0[0] = 0;
  local_b8 = 0;
  uVar12 = param_2 & 0x80000000;
  ArcPrintf(param_1,4,&s__,param_4);
  uVar11 = (ulonglong)param_2;
  pcVar9 = "* ResetAdapter: Entering Routine %x\n";
  uVar7 = 4;
  ArcPrintf(param_1,4,(byte *)"* ResetAdapter: Entering Routine %x\n",uVar11);
  if (*(char *)(param_1 + 0x618) != '\0') {
    ArcPrintf(param_1,4,
              (byte *)
              "* ResetAdapter: FW is processing IOP_RESET, leaving Routine (returning TRUE), line #%d\n"
              ,0x176a);
    return true;
  }
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x4000;
  if (*(char *)(param_1 + 0x516a) == '\0') {
    uVar5 = GetElapsedSeconds(param_1,uVar7,pcVar9,uVar11);
    *(uint *)(param_1 + 0xba3c) = uVar5;
    RequestTimer(param_1,0x800,27000000,1);
  }
  uVar11 = 0;
  puVar10 = local_d0;
  StorPortNotification(0x1003,param_1,3);
  *(undefined1 *)(param_1 + 0x617) = 1;
  if (uVar12 == 0) {
    *(char *)(param_1 + 0x619) = *(char *)(param_1 + 0x619) + '\x01';
  }
  ReturningLocalOutstandingRequestsToOS(param_1);
  sVar4 = GetOutstandingIoCnt(param_1);
  (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x28))(param_1,&local_d8);
  if (((*(char *)(param_1 + 0x611) == '\0') || (uVar11 = (ulonglong)local_d8, local_d8 == 0)) ||
     (uVar12 != 0)) {
    if (*(longlong *)(param_1 + 0x188) != 0) {
LAB_1c000afe0:
      uVar11 = 0;
      puVar8 = (uint *)(param_1 + 0xdeac);
      do {
        if (4 < *puVar8) {
          ArcPrintf(param_1,4,
                    (byte *)
                    "* ResetAdapter: device on path 4 lun %d reset counter reach 5. Will send IOP_RESET to FW\n"
                    ,uVar11);
          *(undefined1 *)(param_1 + 0x619) = 0;
          goto LAB_1c000b09b;
        }
        uVar5 = (int)uVar11 + 1;
        uVar11 = (ulonglong)uVar5;
        puVar8 = puVar8 + 1;
      } while (uVar5 < 0xfe);
      ArcPrintf(param_1,4,(byte *)"* ResetAdapter: NO lun reset counter reaches 5 yet\n",uVar11);
      *(undefined1 *)(param_1 + 0x617) = 0;
      if (uVar12 == 0) {
        bVar13 = true;
        if (sVar4 == 0) goto LAB_1c000b032;
      }
      else {
        bVar13 = sVar4 == 0;
LAB_1c000b032:
        *(undefined1 *)(param_1 + 0x619) = 0;
      }
      StorPortNotification(0x1004,param_1,local_d0);
      pcVar9 = "* ResetAdapter: leaving Routine, returning with status: %x\n";
      ArcPrintf(param_1,4,(byte *)"* ResetAdapter: leaving Routine, returning with status: %x\n",
                (ulonglong)bVar13);
      if (*(char *)(param_1 + 0x516a) == '\0') {
        StopTimer(param_1,0x800,pcVar9,1);
      }
      goto LAB_1c000b176;
    }
    bVar2 = false;
    uVar6 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x28))(param_1,local_d4);
    if (((char)uVar6 < '\0') &&
       (StorPortDebugPrint(0,"OMR value in Check Adapter Health(AdapterIsAlive): 0x%x\n",uVar6),
       *(char *)(param_1 + 0x5e04) == '\0')) {
      uVar11 = 0x58;
      uVar7 = SendSynchFib(param_1,0x2bf,local_a8,0x58,local_a8,local_d4,'\x01');
      cVar3 = (char)uVar7;
      if (cVar3 != '\0') {
        ArcPrintf(param_1,4,
                  (byte *)"* ResetAdapter: synch command RequestAdapterInfo returns successfully\n",
                  uVar11);
        goto LAB_1c000af9a;
      }
      pcVar9 = "* ResetAdapter: SendSynchFib fails, adapter is busy?\n";
      uVar7 = 1;
      ArcPrintf(param_1,1,(byte *)"* ResetAdapter: SendSynchFib fails, adapter is busy?\n",uVar11);
      if (*(char *)(param_1 + 0xe2d4) != '\0') {
        uVar5 = GetElapsedSeconds(param_1,uVar7,pcVar9,uVar11);
        uVar11 = (ulonglong)*(uint *)(param_1 + 0xe2d8);
        iVar1 = *(int *)(param_1 + 0xe2dc);
        ArcPrintf(param_1,4,
                  (byte *)
                  "* ResetAdapter: There is a pending synch cmd: 0x%x(%d). Has been pending %d seconds\n"
                  ,uVar11);
        if ((0x5a < uVar5 - iVar1) && (uVar12 == 0)) {
          bVar2 = true;
          ArcPrintf(param_1,4,
                    (byte *)"* ResetAdapter: set TriggerIOPResetBecauseOfSynchCmdTimeOut to 1\n",
                    uVar11);
        }
      }
    }
    else {
      ArcPrintf(param_1,1,
                (byte *)"* ResetAdapter: AdapterIsAlive return false, adapter might be dead\n",
                uVar11);
      cVar3 = '\0';
LAB_1c000af9a:
      if (cVar3 != '\0') goto LAB_1c000afe0;
    }
    *(undefined1 *)(param_1 + 0x619) = 0;
    if ((uVar12 == 0) && (bVar2)) goto LAB_1c000b09b;
    StorPortNotification(0x1004,param_1,local_d0);
    uVar11 = 0x17e5;
  }
  else {
    uVar7 = 1;
    ArcPrintf(param_1,1,(byte *)"* ResetAdapter: BlinLed Code: 0x%x\n",uVar11);
    uVar12 = local_d8 << 0x10 | 9;
    uVar11 = (ulonglong)uVar12;
    ArcLogEventString(param_1,uVar7,uVar12 + 0xe01a0000,uVar12,puVar10,0x10);
LAB_1c000b09b:
    puVar10 = local_d0;
    *(undefined4 *)(param_1 + 0x1d0) = 4;
    StorPortNotification(0x1004);
    cVar3 = IOPReset(param_1,'\0',puVar10,uVar11);
    if (cVar3 != '\0') {
      *(undefined1 *)(param_1 + 0x618) = 1;
      RequestTimer(param_1,0x20,180000000,1);
      *(undefined1 *)(param_1 + 0x617) = 0;
      ArcPrintf(param_1,4,
                (byte *)"* ResetAdapter: set timer to check the FW status for IOP_RESET, line #%d\n"
                ,0x1898);
      pcVar9 = "* ResetAdapter: leaving Routine (returning TRUE), line #%d\n";
      ArcPrintf(param_1,4,(byte *)"* ResetAdapter: leaving Routine (returning TRUE), line #%d\n",
                0x1899);
      if (*(char *)(param_1 + 0x516a) == '\0') {
        StopTimer(param_1,0x800,pcVar9,1);
      }
      bVar13 = true;
      goto LAB_1c000b176;
    }
    *(undefined4 *)(param_1 + 0x1d0) = 2;
    uVar11 = 0x18a7;
  }
  pcVar9 = "* ResetAdapter: leaving Routine (returning FALSE), line #%d\n";
  *(undefined1 *)(param_1 + 0x617) = 0;
  ArcPrintf(param_1,4,(byte *)"* ResetAdapter: leaving Routine (returning FALSE), line #%d\n",uVar11
           );
  if (*(char *)(param_1 + 0x516a) == '\0') {
    StopTimer(param_1,0x800,pcVar9,1);
  }
LAB_1c000b176:
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xffffbfff;
  return bVar13;
}



===== ArcLogEventString @ 1c000b1a8 =====

void ArcLogEventString(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  undefined4 local_res10 [6];
  undefined4 local_58;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined1 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined1 *local_18;
  
  local_4c = 0;
  local_44 = 0;
  local_3c = 0;
  local_30 = 0;
  local_28 = 0;
  local_18 = &param_6;
  local_res10[0] = 0x95;
  local_58 = 0x100;
  local_54 = 0x48;
  local_20 = 1;
  local_38 = param_3;
  local_34 = param_4;
  StorPortExtendedFunction(0x10,param_1,&local_58,local_res10);
  return;
}



===== CompleteQueuedRequest @ 1c000b214 =====

void CompleteQueuedRequest(longlong param_1,longlong param_2,undefined1 param_3)

{
  short *psVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(param_2 + 0x18);
  if ((*(char *)(lVar4 + 5) == '\x04') && (*(char *)(lVar4 + 2) == '\0')) {
    bVar2 = *(byte *)(lVar4 + 0x48);
    if (((bVar2 < 0x2b) && ((0x50000000500U >> ((ulonglong)bVar2 & 0x3f) & 1) != 0)) ||
       ((bVar2 == 0x88 || (bVar2 == 0x8a)))) {
      psVar1 = (short *)(param_1 + 0xd8dc +
                        (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x28) + 0x2c) * 2);
      *psVar1 = *psVar1 + 1;
    }
  }
  lVar3 = *(longlong *)(param_2 + 0x58);
  *(undefined1 *)(lVar4 + 3) = param_3;
  while( true ) {
    *(undefined8 *)(lVar4 + 0x38) = *(undefined8 *)(*(longlong *)(lVar4 + 0x38) + 0xa0);
    StorPortNotification(0,param_1);
    *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
    *(short *)(param_1 + 0xba26) = *(short *)(param_1 + 0xba26) + 1;
    if (lVar3 == 0) break;
    lVar4 = *(longlong *)(lVar3 + 0x18);
    *(undefined1 *)(lVar4 + 3) = param_3;
    lVar3 = *(longlong *)(lVar3 + 0x58);
  }
  return;
}



===== DequeueRawIoReadWriteRequest @ 1c000b2c4 =====

void DequeueRawIoReadWriteRequest(longlong param_1,char param_2,undefined1 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  longlong *plVar6;
  undefined1 uVar7;
  uint local_res8;
  
  *(int *)(param_1 + 0xe2bc) = *(int *)(param_1 + 0xe2bc) + 1;
  if (*(int *)(param_1 + 0xa914) + *(int *)(param_1 + 0xa910) != 0) {
    if (*(int *)(param_1 + 0xa910) != 0) {
      uVar5 = 0;
      plVar6 = (longlong *)(param_1 + 0x8158);
      do {
        lVar1 = *plVar6;
        *plVar6 = 0;
        while (lVar1 != 0) {
          lVar2 = *(longlong *)(lVar1 + 0x48);
          if (param_2 == '\0') {
            cVar4 = SendFib(0x1f7 - (ushort)(*(int *)(param_1 + 0x8088) != 2),lVar1,'\0');
            if (cVar4 == '\0') {
              uVar7 = 5;
              goto LAB_1c000b35a;
            }
          }
          else {
            uVar7 = param_3;
LAB_1c000b35a:
            CompleteQueuedRequest(param_1,lVar1,uVar7);
          }
          *(int *)(param_1 + 0xa910) = *(int *)(param_1 + 0xa910) + -1;
          lVar1 = lVar2;
        }
        if (*(int *)(param_1 + 0xa910) == 0) break;
        uVar5 = uVar5 + 1;
        plVar6 = plVar6 + 1;
      } while (uVar5 < 0xfe);
    }
    if (*(int *)(param_1 + 0xa914) != 0) {
      plVar6 = (longlong *)(param_1 + 0x8948);
      local_res8 = 0;
      do {
        lVar1 = *plVar6;
        *plVar6 = 0;
        while (lVar1 != 0) {
          lVar2 = *(longlong *)(lVar1 + 0x48);
          if (param_2 == '\0') {
            lVar3 = *(longlong *)(lVar1 + 0x28);
            if (*(char *)(param_1 + 0x15a5) == '\0') {
              *(short *)(lVar3 + 8) = (*(short *)(lVar3 + 0x54) + 0xb) * 8;
            }
            else {
              *(short *)(lVar3 + 8) = (*(short *)(lVar3 + 0x54) + -1) * 0xc + 100;
            }
            cVar4 = SendFib((*(char *)(param_1 + 0x15a5) != '\0') + 600,lVar1,'\0');
            if (cVar4 == '\0') {
              uVar7 = 5;
              goto LAB_1c000b433;
            }
          }
          else {
            uVar7 = param_3;
LAB_1c000b433:
            CompleteQueuedRequest(param_1,lVar1,uVar7);
          }
          *(int *)(param_1 + 0xa914) = *(int *)(param_1 + 0xa914) + -1;
          lVar1 = lVar2;
        }
        if (*(int *)(param_1 + 0xa914) == 0) break;
        local_res8 = local_res8 + 1;
        plVar6 = plVar6 + 1;
      } while (local_res8 < 0xfe);
    }
    *(undefined1 *)(param_1 + 0xa918) = 0;
    *(undefined1 *)(param_1 + 0xa925) = 0;
  }
  return;
}



===== HandleInterrupt @ 1c000b4a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleInterrupt(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x10))();
  return;
}



===== HandleMSIXInterrupt @ 1c000b4c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 HandleMSIXInterrupt(ulonglong param_1,uint param_2,undefined8 param_3,ulonglong param_4)

{
  uint *puVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  undefined4 local_res10 [2];
  
  uVar3 = (ulonglong)param_2;
  uVar2 = 1;
  puVar1 = (uint *)(param_1 + (uVar3 + 0x2bfa) * 4);
  *puVar1 = param_2;
  *(undefined1 *)(uVar3 + 0xb968 + param_1) = 1;
  if (*(char *)(param_1 + 0xaad6) == '\0') {
LAB_1c000b511:
    if (*(char *)(param_1 + 0xaadc) != '\0') {
      local_res10[0] = 0;
      StorPortNotification
                (0x1002,param_1,param_1 + (uVar3 * 9 + 0x160d) * 8,param_1,puVar1,local_res10);
      goto LAB_1c000b582;
    }
  }
  else if (*(char *)(param_1 + 0xaadc) != '\0') {
    if (*(ushort *)(param_1 + 0xaad4) <= param_2) {
      return 0;
    }
    goto LAB_1c000b511;
  }
  if ((ushort)(*(short *)(param_1 + 0x158e) - 0x28cU) < 2) {
    uVar2 = NonMSIXInterruptHandler(param_1,param_2,(char *)0x0,param_4);
  }
  else {
    uVar2 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x10))();
  }
LAB_1c000b582:
  *(undefined1 *)(uVar3 + 0xb968 + param_1) = 2;
  return uVar2;
}



===== PostProcessScsiCommand @ 1c000b5a0 =====

void PostProcessScsiCommand(longlong param_1,longlong param_2,longlong param_3,uint param_4)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_4 < 0x16) {
    if (*(char *)(param_2 + 3) != '\x01') {
      *(undefined1 *)(param_2 + 3) = 10;
    }
    goto LAB_1c000b851;
  }
  if (((((char)*(uint *)(param_3 + 4) < '\0') &&
       (uVar3 = *(uint *)(param_3 + 0x10), uVar3 + 0x16 <= param_4)) &&
      (*(void **)(param_2 + 0x20) != (void *)0x0)) && (uVar3 != 0)) {
    if (*(byte *)(param_2 + 0xb) < uVar3) {
      uVar3 = (uint)*(byte *)(param_2 + 0xb);
    }
    memcpy(*(void **)(param_2 + 0x20),(void *)(param_3 + 0x14),(ulonglong)uVar3);
  }
  else {
    *(uint *)(param_3 + 4) = *(uint *)(param_3 + 4) & 0xffffff7f;
  }
  if (*(char *)(param_2 + 3) != '\x01') goto LAB_1c000b851;
  if (*(int *)(param_3 + 4) != 1) {
    *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_3 + 4);
  }
  if (*(int *)(param_3 + 8) != 0) {
    *(undefined1 *)(param_2 + 4) = *(undefined1 *)(param_3 + 8);
  }
  if (((*(char *)(param_2 + 5) == '\0') && (*(char *)(param_2 + 0x48) == '\x12')) &&
     ((*(char *)(param_2 + 7) == '\0' && (*(int *)(param_3 + 4) == 10)))) {
    *(undefined4 *)((ulonglong)*(byte *)(param_2 + 6) * 0x10 + 0x417c + param_1) = 0;
  }
  if (*(char *)(param_2 + 3) != '\x01') goto LAB_1c000b851;
  if (*(char *)(param_2 + 0x48) == '\x12') {
    pbVar2 = *(byte **)(param_2 + 0x18);
    if (((*(byte *)(param_2 + 5) < 4) && (*(char *)(param_2 + 7) == '\0')) &&
       (pbVar2 != (byte *)0x0)) {
      *(byte *)((ulonglong)*(byte *)(param_2 + 6) + 0x5210 +
               (ulonglong)*(byte *)(param_2 + 5) * 0xff + param_1) = *pbVar2 & 0x1f;
      *(byte *)((ulonglong)*(byte *)(param_2 + 6) + 0x560c +
               param_1 + (ulonglong)*(byte *)(param_2 + 5) * 0xff) = *pbVar2 >> 5;
      if ((*(byte *)(param_2 + 0x49) & 1) == 0) {
        *(byte *)((ulonglong)*(byte *)(param_2 + 6) + 0x5a08 +
                 param_1 + (ulonglong)*(byte *)(param_2 + 5) * 0xff) = pbVar2[1] >> 7;
      }
      if ((*(char *)(param_1 + 0x5169) != '\0') && (*(char *)(param_2 + 5) == '\0')) {
        if (((*pbVar2 & 0xe0) == 0) && (((*pbVar2 & 0x1f) == 0 && (*(int *)(param_3 + 4) != 10)))) {
          *(undefined4 *)((ulonglong)*(byte *)(param_2 + 6) * 0x10 + 0x417c + param_1) = 1;
        }
        else {
          *(undefined4 *)((ulonglong)*(byte *)(param_2 + 6) * 0x10 + 0x417c + param_1) = 0;
        }
      }
    }
    if (((1 < *(uint *)(param_3 + 0xc)) && (pbVar2 != (byte *)0x0)) && (*(byte *)(param_2 + 5) < 4))
    {
      if (((((*pbVar2 & 0x1f) != 0) ||
           (*(char *)((ulonglong)*(byte *)(param_2 + 6) + 0x5a08 +
                     param_1 + (ulonglong)*(byte *)(param_2 + 5) * 0xff) != '\0')) &&
          (*(char *)(param_1 + 0x517c) != '\0')) ||
         ((*(char *)(param_1 + 0x5169) != '\0' && ((*pbVar2 & 0xe0) == 0)))) goto LAB_1c000b797;
    }
    *(undefined1 *)(param_2 + 3) = 10;
  }
LAB_1c000b797:
  if ((*(char *)(param_2 + 3) == '\x01') &&
     ((*(char *)(param_2 + 0x48) == '%' || (*(char *)(param_2 + 0x48) == -0x62)))) {
    if ((*(char *)(param_2 + 5) == '\0') &&
       ((*(int *)((ulonglong)*(byte *)(param_2 + 6) * 0x10 + 0x417c + param_1) == 1 &&
        (*(uint **)(param_2 + 0x18) != (uint *)0x0)))) {
      uVar3 = **(uint **)(param_2 + 0x18);
      *(uint *)(((ulonglong)*(byte *)(param_2 + 6) + 0x418) * 0x10 + param_1) =
           (((uVar3 >> 8 & 0xff | (uVar3 & 0xff) << 8) << 8 | uVar3 >> 0x10 & 0xff) << 8 |
           uVar3 >> 0x18) + 1;
    }
    if (*(char *)(param_1 + 0x613) != '\0') {
      uVar3 = DynamicallyThrottleLunQueueDepth(param_1,(uint)*(byte *)(param_2 + 6));
      StorPortSetDeviceQueueDepth
                (param_1,*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6),
                 *(undefined1 *)(param_2 + 7),uVar3);
    }
  }
LAB_1c000b851:
  if (((*(byte *)(param_2 + 5) < 4) && (bVar1 = *(byte *)(param_2 + 6), bVar1 != 0xff)) &&
     (uVar5 = (ulonglong)*(byte *)(param_2 + 5),
     *(char *)((ulonglong)bVar1 + 0x5210 + uVar5 * 0xff + param_1) == '\x01')) {
    uVar3 = *(uint *)(param_1 + 0xaac0 + uVar5 * 4);
    uVar4 = 1 << (bVar1 & 0x1f);
    if (((uVar4 & uVar3) != 0) && (*(char *)(param_2 + 4) != '\x02')) {
      *(uint *)(param_1 + 0xaac0 + uVar5 * 4) = ~uVar4 & uVar3;
    }
  }
  return;
}



===== ProcessContainerInquiry @ 1c000b8b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined4
ProcessContainerInquiry(longlong param_1,longlong param_2,undefined4 param_3,longlong param_4)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  ulonglong uVar4;
  byte bVar5;
  char cVar6;
  void *pvVar7;
  char *pcVar8;
  undefined8 *_Src;
  uint uVar9;
  byte bVar10;
  undefined4 uVar11;
  size_t sVar12;
  undefined1 auStack_118 [32];
  undefined1 local_f8;
  undefined1 uStack_f7;
  undefined1 uStack_f6;
  undefined1 uStack_f5;
  undefined2 uStack_f4;
  undefined1 local_f2;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined8 local_e0;
  undefined1 local_d8 [8];
  undefined1 local_d0 [16];
  char local_c0 [8];
  byte local_b8;
  byte local_b7;
  undefined1 local_b5;
  uint local_b4;
  undefined1 local_b0;
  undefined2 local_af;
  undefined1 local_ad;
  undefined8 local_a8;
  undefined1 local_a0 [8];
  undefined1 local_98 [16];
  undefined4 local_88;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_118;
  pvVar7 = *(void **)(param_2 + 0x18);
  uVar9 = 0;
  local_f8 = (undefined1)param_3;
  uStack_f7 = (undefined1)((uint)param_3 >> 8);
  uStack_f6 = (undefined1)((uint)param_3 >> 0x10);
  uStack_f5 = (undefined1)((uint)param_3 >> 0x18);
  local_f0 = param_1;
  if (((pvVar7 == (void *)0x0) || (uVar1 = *(uint *)(param_2 + 0x10), uVar1 == 0)) ||
     (bVar5 = *(byte *)(param_2 + 0x49), (bVar5 & 2) != 0)) {
    uVar11 = 6;
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined1 *)(param_2 + 4) = 2;
    if (((*(uint *)(param_2 + 0xc) & 0x20) == 0) && (7 < *(byte *)(param_2 + 0xb))) {
      pbVar3 = *(byte **)(param_2 + 0x20);
      memset(pbVar3,0,(ulonglong)*(byte *)(param_2 + 0xb));
      *pbVar3 = *pbVar3 & 0xf0 | 0x70;
      pbVar3[2] = pbVar3[2] & 0xf5 | 5;
      bVar5 = *(byte *)(param_2 + 0xb);
      if (bVar5 < 0xe) {
        pbVar3[7] = 0;
        *(undefined1 *)(param_2 + 4) = 0;
      }
      else {
        pbVar3[0xc] = 0x24;
        pbVar3[0xd] = 0;
        bVar10 = 6;
        if (0x11 < bVar5) {
          bVar10 = 10;
        }
        pbVar3[7] = bVar10;
        uVar11 = 0x84;
      }
    }
    else {
      *(undefined1 *)(param_2 + 4) = 0;
    }
    return uVar11;
  }
  memset(&local_a8,0,0x60);
  local_a8._0_1_ = 0;
  if ((bVar5 & 1) == 0) {
    if (*(char *)(param_2 + 0x4a) != '\0') {
LAB_1c000ba20:
      *(undefined1 *)(param_2 + 4) = 2;
      *(undefined4 *)(param_2 + 0x10) = 0;
      if (((*(uint *)(param_2 + 0xc) & 0x20) == 0) && (7 < *(byte *)(param_2 + 0xb))) {
        pbVar3 = *(byte **)(param_2 + 0x20);
        memset(pbVar3,0,(ulonglong)*(byte *)(param_2 + 0xb));
        *pbVar3 = *pbVar3 & 0xf0 | 0x70;
        pbVar3[2] = pbVar3[2] & 0xf5 | 5;
        bVar5 = *(byte *)(param_2 + 0xb);
        if (0xd < bVar5) {
          pbVar3[0xc] = 0x20;
          pbVar3[0xd] = 0;
          bVar10 = 6;
          if (0x11 < bVar5) {
            bVar10 = 10;
          }
          pbVar3[7] = bVar10;
          *(undefined1 *)(param_2 + 4) = 2;
          return 0x84;
        }
        pbVar3[7] = 0;
      }
      *(undefined1 *)(param_2 + 4) = 0;
      return 6;
    }
    local_a8._7_1_ = local_a8._7_1_ | 2;
    local_a8._3_1_ = local_a8._3_1_ & 0xf2 | 2;
    pvVar7 = (void *)(local_f0 + 0x159c);
    local_a8._2_1_ = 4;
    local_a8._4_1_ = 0x5b;
    local_a8._1_1_ = 0;
    uVar4 = 0xffffffffffffffff;
    local_88 = 0x302e3156;
    do {
      uVar4 = uVar4 + 1;
    } while (*(char *)((longlong)pvVar7 + uVar4) != '\0');
    sVar12 = 8;
    if (uVar4 < 9) {
      sVar12 = 0xffffffffffffffff;
      do {
        sVar12 = sVar12 + 1;
      } while (*(char *)((longlong)pvVar7 + sVar12) != '\0');
    }
    memcpy(local_a0,pvVar7,sVar12);
    if (CONCAT13(uStack_f5,CONCAT12(uStack_f6,CONCAT11(uStack_f7,local_f8))) == -1) {
      sVar12 = 10;
      pcVar8 = "Management";
    }
    else {
      sVar12 = 0x10;
      pcVar8 = "Array           ";
    }
    memcpy(local_98,pcVar8,sVar12);
    uVar1 = *(uint *)(param_2 + 0x10);
    _Src = &local_a8;
    pvVar7 = *(void **)(param_2 + 0x18);
    sVar12 = 0x60;
    if (0x5f < uVar1) {
LAB_1c000b9f3:
      memcpy(pvVar7,_Src,sVar12);
      *(int *)(param_2 + 0x10) = (int)sVar12;
      return 1;
    }
  }
  else {
    cVar6 = *(char *)(param_2 + 0x4a);
    if (cVar6 == '\0') {
      _Src = (undefined8 *)&local_f8;
      local_f8 = 0;
      uStack_f6 = 0;
      uStack_f5 = 2;
      uStack_f4 = 0x8000;
      local_f2 = 0x83;
      uStack_f7 = 0;
      if (6 < uVar1) {
        memcpy(pvVar7,_Src,7);
        *(undefined4 *)(param_2 + 0x10) = 7;
        return 1;
      }
    }
    else if (cVar6 == -0x80) {
      uVar2 = *(uint *)(param_4 + 0x18);
      pcVar8 = (char *)((longlong)&local_f0 + 4);
      local_e8 = 0;
      local_f0 = 0x8008000;
      do {
        bVar5 = (byte)(uVar2 >> (('\a' - (char)uVar9) * '\x04' & 0x1fU)) & 0xf;
        if (bVar5 < 10) {
          cVar6 = bVar5 + 0x30;
        }
        else {
          cVar6 = bVar5 + 0x37;
        }
        *pcVar8 = cVar6;
        uVar9 = uVar9 + 1;
        pcVar8 = pcVar8 + 1;
      } while (uVar9 < 8);
      sVar12 = 0xc;
      _Src = &local_f0;
      if (0xb < uVar1) goto LAB_1c000b9f3;
    }
    else {
      if (cVar6 != -0x7d) goto LAB_1c000ba20;
      memset(&local_e0,0,0x34);
      local_e0._0_4_ = 0x30008300;
      local_e0._4_1_ = local_e0._4_1_ & 0xf2 | 2;
      local_e0._7_1_ = 0x20;
      local_e0._5_1_ = local_e0._5_1_ & 0xf1 | 1;
      memcpy(local_d8,"ADAPTEC ",8);
      memcpy(local_d0,"ARRAY           ",0x10);
      local_b4 = *(uint *)(param_4 + 0x18);
      pcVar8 = local_c0;
      uVar9 = 0;
      do {
        bVar5 = (byte)(local_b4 >> (('\a' - (char)uVar9) * '\x04' & 0x1fU)) & 0xf;
        if (bVar5 < 10) {
          cVar6 = bVar5 + 0x30;
        }
        else {
          cVar6 = bVar5 + 0x37;
        }
        *pcVar8 = cVar6;
        uVar9 = uVar9 + 1;
        pcVar8 = pcVar8 + 1;
      } while (uVar9 < 8);
      _Src = &local_e0;
      pvVar7 = *(void **)(param_2 + 0x18);
      local_b8 = local_b8 & 0xf1 | 1;
      local_b5 = 8;
      local_af = 0xd0;
      local_b7 = local_b7 & 0xf2 | 2;
      local_ad = 0;
      uVar1 = *(uint *)(param_2 + 0x10);
      local_b0 = 0;
      if (0x33 < uVar1) {
        memcpy(pvVar7,_Src,0x34);
        *(undefined4 *)(param_2 + 0x10) = 0x34;
        return 1;
      }
    }
  }
  memcpy(pvVar7,_Src,(ulonglong)uVar1);
  return 1;
}



===== ProcessScsiCommand @ 1c000bcd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint ProcessScsiCommand(longlong param_1,longlong param_2,longlong param_3)

{
  undefined4 uVar1;
  char *_Dst;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  undefined8 uVar7;
  byte bVar8;
  void *_Dst_00;
  byte *pbVar9;
  longlong lVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ulonglong uVar14;
  size_t _Size;
  undefined1 auStackY_278 [32];
  ushort local_238 [4];
  undefined8 local_230;
  undefined8 local_228;
  undefined2 local_220;
  uint local_218 [3];
  undefined4 local_20c;
  uint local_208;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_278;
  lVar10 = *(longlong *)(param_2 + 0x38);
  bVar8 = *(byte *)(param_2 + 6);
  uVar14 = (ulonglong)bVar8;
  bVar4 = *(byte *)(param_2 + 0x48);
  bVar2 = false;
  if (bVar4 < 0x26) {
    if (bVar4 == 0x25) {
      uVar6 = *(uint *)(param_1 + 0x19e8 + uVar14 * 0x28);
      if ((*(longlong *)(param_2 + 0x18) != 0) && (*(int *)(param_2 + 0x10) != 0)) {
        uVar6 = ((uVar6 >> 8 & 0xff | (uVar6 & 0xff) << 8) << 8 | uVar6 >> 0x10 & 0xff) << 8 |
                uVar6 >> 0x18;
        if ((int)((ulonglong)*(undefined8 *)(param_1 + 0x19d8 + uVar14 * 0x28) >> 0x20) == 0) {
          uVar11 = *(int *)(param_1 + 0x19d8 + uVar14 * 0x28) - 1;
          local_230 = CONCAT44(uVar6,((uVar11 >> 8 & 0xff | (uVar11 & 0xff) << 8) << 8 |
                                     uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18);
          if (*(char *)(param_1 + 0x613) != '\0') {
            DynamicallyThrottleLunQueueDepth(param_1,(uint)bVar8);
            StorPortSetDeviceQueueDepth(param_1,4,bVar8,0);
          }
        }
        else {
          local_230 = CONCAT44(uVar6,-(uint)(*(char *)(param_1 + 0x15a6) != '\0'));
        }
        uVar6 = *(uint *)(param_2 + 0x10);
        _Dst_00 = *(void **)(param_2 + 0x18);
        if (7 < uVar6) {
          memcpy(_Dst_00,&local_230,8);
          *(undefined4 *)(param_2 + 0x10) = 8;
          return 1;
        }
LAB_1c000c151:
        memcpy(_Dst_00,&local_230,(ulonglong)uVar6);
        return 1;
      }
    }
    else if (bVar4 == 3) {
      _Dst_00 = *(void **)(param_2 + 0x18);
      local_220 = 0;
      local_228 = 0;
      local_230 = 0xa00000000000070;
      if ((_Dst_00 != (void *)0x0) && (uVar6 = *(uint *)(param_2 + 0x10), uVar6 != 0)) {
        if (0x11 < uVar6) {
          memcpy(_Dst_00,&local_230,0x12);
          *(undefined4 *)(param_2 + 0x10) = 0x12;
          return 1;
        }
        goto LAB_1c000c151;
      }
    }
    else {
      if (bVar4 == 8) goto LAB_1c000c403;
      if (bVar4 == 0x12) {
        uVar6 = ProcessContainerInquiry
                          (param_1,param_2,(uint)bVar8,param_1 + (uVar14 + 0xa5) * 0x28);
        goto LAB_1c000c54d;
      }
      if (0x15 < bVar4) {
        if (bVar4 < 0x18) {
          if (*(int *)(param_1 + 0x138c) == 0) {
            return 1;
          }
        }
        else if (bVar4 == 0x1a) {
          _Dst = *(char **)(param_2 + 0x18);
          uVar1 = *(undefined4 *)(param_1 + 0x19e8 + uVar14 * 0x28);
          if (((_Dst != (char *)0x0) && (0xb < *(uint *)(param_2 + 0x10))) &&
             (*(int *)(param_1 + 0x19cc + uVar14 * 0x28) == 1)) {
            memset(_Dst,0,(ulonglong)*(uint *)(param_2 + 0x10));
            _Dst[0] = '\x03';
            _Dst[1] = '\0';
            if ((*(uint *)(param_1 + 0x19d0 + (ulonglong)*(byte *)(param_2 + 6) * 0x28) & 2) != 0) {
              _Dst[2] = _Dst[2] | 0x80;
            }
            _Dst[2] = _Dst[2] | 0x10;
            uVar11 = 4;
            if ((*(byte *)(param_2 + 0x49) & 8) == 0) {
              _Dst[4] = '\0';
              _Dst[9] = (char)((uint)uVar1 >> 0x10);
              _Dst[10] = (char)((uint)uVar1 >> 8);
              _Dst[0xb] = (char)uVar1;
              uVar14 = (ulonglong)*(byte *)(param_2 + 6);
              if ((*(char *)(param_1 + 0x19db + uVar14 * 0x28) == '\0') &&
                 (*(char *)(param_1 + 0x19dc + uVar14 * 0x28) == '\0')) {
                _Dst[5] = *(char *)(param_1 + 0x19da + uVar14 * 0x28);
                _Dst[6] = *(char *)(param_1 + 0x19d9 + (ulonglong)*(byte *)(param_2 + 6) * 0x28);
                _Dst[7] = *(char *)(param_1 + 0x19d8 + (ulonglong)*(byte *)(param_2 + 6) * 0x28);
              }
              else {
                _Dst[5] = -1;
                _Dst[6] = -1;
                _Dst[7] = -1;
              }
              *_Dst = *_Dst + '\b';
              uVar11 = 0xc;
              _Dst[3] = '\b';
            }
            else {
              _Dst[3] = '\0';
            }
            uVar14 = (ulonglong)uVar11;
            pbVar9 = (byte *)(*(longlong *)(param_2 + 0x18) + uVar14);
            bVar8 = *(byte *)(param_2 + 0x4a) & 0x3f;
            if ((*(byte *)(param_2 + 0x4a) & 0x3f) == 0) {
LAB_1c000c0bb:
              uVar6 = 1;
              uVar13 = uVar11;
            }
            else {
              uVar13 = uVar11;
              if (bVar8 == 2) {
LAB_1c000bf54:
                if (uVar14 + 0x10 <= (ulonglong)*(uint *)(param_2 + 0x10)) {
                  uVar11 = uVar11 + 0x10;
                  pbVar9[1] = 0xe;
                  uVar6 = 1;
                  *pbVar9 = *pbVar9 & 0xc2 | 2;
                  pbVar9 = pbVar9 + 0x10;
                  *_Dst = *_Dst + '\x10';
                  bVar3 = true;
                  uVar13 = uVar11;
                  if (bVar2) goto LAB_1c000bf8a;
                  goto LAB_1c000c0c0;
                }
              }
              else {
                bVar3 = bVar2;
                if (bVar8 == 3) {
LAB_1c000bf8a:
                  uVar13 = uVar11;
                  if (*(uint *)(param_2 + 0x10) < uVar11 + 0x18) goto LAB_1c000c071;
                  uVar11 = uVar11 + 0x18;
                  pbVar9[1] = 0x16;
                  uVar6 = 1;
                  *pbVar9 = *pbVar9 & 0xc3 | 3;
                  pbVar9[0xb] = 0x80;
                  pbVar9[0xc] = 2;
                  pbVar9[0x14] = pbVar9[0x14] | 0x40;
                  pbVar9 = pbVar9 + 0x18;
                  *_Dst = *_Dst + '\x18';
                  uVar13 = uVar11;
                  if (!bVar3) goto LAB_1c000c0c0;
LAB_1c000bfcd:
                  uVar13 = uVar11;
                  if (uVar11 + 0x18 <= *(uint *)(param_2 + 0x10)) {
                    uVar11 = uVar11 + 0x18;
                    pbVar9[1] = 0x16;
                    pbVar9[2] = 0;
                    pbVar9[3] = 0;
                    pbVar9[4] = 0;
                    pbVar9[5] = 0;
                    *pbVar9 = *pbVar9 & 0x40 | 4;
                    uVar6 = 1;
                    *_Dst = *_Dst + '\x18';
                    pbVar9 = pbVar9 + 0x18;
                    bVar2 = true;
                    uVar13 = uVar11;
                    if (bVar3) {
LAB_1c000c00d:
                      uVar12 = uVar11 + 0x14;
                      uVar13 = uVar11;
                      if (*(uint *)(param_2 + 0x10) < uVar12) goto LAB_1c000c071;
                      pbVar9[2] = pbVar9[2] & 0xfb;
                      pbVar9[1] = 0x12;
                      *pbVar9 = *pbVar9 & 200 | 8;
                      uVar6 = 1;
                      *_Dst = *_Dst + '\x14';
                      pbVar9 = pbVar9 + 0x14;
                      bVar3 = true;
                      uVar13 = uVar12;
                      if (bVar2) goto LAB_1c000c03f;
                    }
                    goto LAB_1c000c0c0;
                  }
                }
                else {
                  if (bVar8 == 4) goto LAB_1c000bfcd;
                  if (bVar8 == 8) goto LAB_1c000c00d;
                  uVar12 = uVar11;
                  if (bVar8 == 10) {
LAB_1c000c03f:
                    uVar11 = uVar12 + 0xc;
                    uVar13 = uVar12;
                    if (*(uint *)(param_2 + 0x10) < uVar11) goto LAB_1c000c071;
                    pbVar9[1] = 10;
                    *pbVar9 = *pbVar9 & 0xca | 10;
                    pbVar9 = pbVar9 + 0xc;
                    *_Dst = *_Dst + '\f';
                    uVar6 = 1;
                    uVar13 = uVar11;
                    if (!bVar3) goto LAB_1c000c0c0;
                  }
                  else if (bVar8 != 0x1c) {
                    if ((bVar8 == 0x3f) && (uVar14 + 0x62 <= (ulonglong)*(uint *)(param_2 + 0x10)))
                    {
                      bVar2 = true;
                      goto LAB_1c000bf54;
                    }
                    goto LAB_1c000c071;
                  }
                  uVar13 = uVar11;
                  if (uVar11 + 0xc <= *(uint *)(param_2 + 0x10)) {
                    uVar11 = uVar11 + 0xc;
                    pbVar9[2] = pbVar9[2] | 0x80;
                    pbVar9[1] = 10;
                    *pbVar9 = *pbVar9 & 0xdc | 0x9c;
                    uVar6 = 1;
                    pbVar9[3] = pbVar9[3] & 0xfc | 0xc;
                    *_Dst = *_Dst + '\f';
                    uVar13 = uVar11;
                    if (bVar3) goto LAB_1c000c0bb;
                    goto LAB_1c000c0c0;
                  }
                }
              }
LAB_1c000c071:
              uVar6 = 6;
              *(undefined1 *)(param_2 + 4) = 2;
            }
LAB_1c000c0c0:
            *(uint *)(param_2 + 0x10) = uVar13;
            goto LAB_1c000c54d;
          }
        }
        else if (bVar4 == 0x1b) {
          local_218[0] = 2;
          local_218[1] = 0xf5;
          local_218[2] = ~(uint)*(byte *)(param_2 + 0x4c) & 1 | 2;
          local_20c = *(undefined4 *)(param_1 + 0x19e4 + uVar14 * 0x28);
          local_208 = *(byte *)(param_2 + 0x49) & 1;
          if (*(char *)(param_1 + 0x19c4) == '\0') {
            return 1;
          }
          if (*(longlong *)(param_1 + 0x188) == 0) {
            SendSynchFib(param_1,500,local_218,0x1d0,local_218,local_238,'\x01');
            return 1;
          }
          return 1;
        }
      }
    }
LAB_1c000c0c9:
    uVar6 = 6;
    *(undefined1 *)(param_2 + 4) = 2;
  }
  else {
    if ((bVar4 != 0x28) && (bVar4 != 0x2a)) {
      if (bVar4 == 0x35) {
        return 1;
      }
      if ((bVar4 != 0x88) && (bVar4 != 0x8a)) {
        if ((bVar4 == 0x9e) &&
           (((*(void **)(param_2 + 0x18) != (void *)0x0 &&
             (uVar6 = *(uint *)(param_2 + 0x10), uVar6 != 0)) &&
            (*(char *)(param_1 + 0x15a6) != '\0')))) {
          uVar11 = *(uint *)(param_1 + 0x19e8 + uVar14 * 0x28);
          local_228 = CONCAT44(local_228._4_4_,
                               ((uVar11 >> 8 & 0xff | (uVar11 & 0xff) << 8) << 8 |
                               uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18);
          uVar14 = *(longlong *)(param_1 + 0x19d8 + uVar14 * 0x28) - 1;
          _Size = (size_t)uVar6;
          local_230 = CONCAT44((((uint)(byte)(uVar14 >> 8) | ((uint)uVar14 & 0xff) << 8) << 8 |
                               (uint)(byte)(uVar14 >> 0x10)) << 8 | (uint)(byte)(uVar14 >> 0x18),
                               (((uint)((uVar14 >> 0x20 & 0xff) << 8) | (uint)(byte)(uVar14 >> 0x28)
                                ) << 8 | (uint)(byte)(uVar14 >> 0x30)) << 8 |
                               (uint)(byte)(uVar14 >> 0x38));
          if (0xb < uVar6) {
            _Size = 0xc;
          }
          memcpy(*(void **)(param_2 + 0x18),&local_230,_Size);
          uVar6 = *(uint *)(param_1 + 0x19ec + (ulonglong)*(byte *)(param_2 + 6) * 0x28);
          if ((uVar6 != 0) && (0xd < *(uint *)(param_2 + 0x10))) {
            bVar4 = 0;
            for (; 1 < uVar6; uVar6 = uVar6 >> 1) {
              bVar4 = bVar4 + 1;
            }
            pbVar9 = (byte *)(*(longlong *)(param_2 + 0x18) + 0xd);
            *pbVar9 = *pbVar9 ^ (bVar4 ^ *(byte *)(*(longlong *)(param_2 + 0x18) + 0xd)) & 0xf;
          }
          if (*(char *)(param_1 + 0x613) == '\0') {
            return 1;
          }
          DynamicallyThrottleLunQueueDepth(param_1,(uint)bVar8);
          StorPortSetDeviceQueueDepth(param_1,4,bVar8,0);
          return 1;
        }
        goto LAB_1c000c0c9;
      }
    }
LAB_1c000c403:
    if (*(char *)(param_1 + 0x610) != '\0') {
      if (*(longlong *)(param_1 + 0x188) != 0) {
        return 5;
      }
      lVar10 = param_2;
      BuildReadWriteFib(param_1,param_2,param_3);
      if (*(char *)(param_2 + 3) == '\x12') {
        return 0x12;
      }
      uVar7 = SendSynchFib(param_1,CONCAT62((int6)((ulonglong)lVar10 >> 0x10),
                                            (*(char *)(param_1 + 0x15a5) != '\0') + 500),
                           (uint *)(param_1 + 0x15a8),(ulonglong)*(ushort *)(param_1 + 0x19a8),
                           (char *)(param_1 + 0x17a8),local_238,*(char *)(param_1 + 0x516a));
      if ((char)uVar7 == '\0') {
        return 9;
      }
      if (*(char *)(param_1 + 0x516a) == '\0') {
        *(longlong *)(param_1 + 0x188) = param_2;
        RequestTimer(param_1,2,10000,1);
        return 0;
      }
      return (-(uint)(*(char *)(param_1 + 0x17a8) != '\0') & 3) + 1;
    }
    if ((*(char *)(param_1 + 0x8084) != '\x01') && (*(char *)(param_1 + 0x808d) == '\0')) {
      cVar5 = SendFib((*(char *)(param_1 + 0x15a5) != '\0') + 500,lVar10,'\0');
      return ~-(uint)(cVar5 != '\0') & 5;
    }
    cVar5 = SendRawIoFib(0x1f7 - (ushort)(*(int *)(param_1 + 0x8088) != 2),lVar10);
    if (cVar5 == '\0') {
      *(undefined4 *)(lVar10 + 0x70) = 0;
      return 5;
    }
    *(uint *)(lVar10 + 0x70) = 2 - (uint)(*(char *)(param_2 + 5) != '\0');
    uVar6 = 0;
LAB_1c000c54d:
    if (uVar6 != 6) {
      return uVar6;
    }
  }
  *(undefined4 *)(param_2 + 0x10) = 0;
  if (((*(uint *)(param_2 + 0xc) & 0x20) == 0) && (7 < *(byte *)(param_2 + 0xb))) {
    pbVar9 = *(byte **)(param_2 + 0x20);
    memset(pbVar9,0,(ulonglong)*(byte *)(param_2 + 0xb));
    *pbVar9 = *pbVar9 & 0xf0 | 0x70;
    pbVar9[2] = pbVar9[2] & 0xf5 | 5;
    bVar8 = *(byte *)(param_2 + 0xb);
    if (0xd < bVar8) {
      pbVar9[0xc] = 0x20;
      pbVar9[0xd] = 0;
      bVar4 = 6;
      if (0x11 < bVar8) {
        bVar4 = 10;
      }
      pbVar9[7] = bVar4;
      *(undefined1 *)(param_2 + 4) = 2;
      return 0x84;
    }
    pbVar9[7] = 0;
  }
  *(undefined1 *)(param_2 + 4) = 0;
  return uVar6;
}



===== QueuePrintf @ 1c000c5e4 =====

void QueuePrintf(longlong param_1,ushort param_2,undefined2 param_3)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = *(ushort *)(param_1 + 0x131a);
  if (param_2 != 0) {
    uVar2 = uVar1 + 1;
    if ((*(ushort *)(param_1 + 0x1318) != uVar2) &&
       ((uVar2 != 0x20 || (*(ushort *)(param_1 + 0x1318) != 0)))) {
      *(undefined1 *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x690)) = 0;
      memcpy((void *)(param_1 + 0x698 + (ulonglong)uVar1 * 0x60),*(void **)(param_1 + 0x690),
             (ulonglong)param_2);
      *(undefined2 *)(param_1 + 0x1298 + (ulonglong)*(ushort *)(param_1 + 0x131a) * 2) = param_3;
      *(ushort *)(param_1 + 0x12d8 + (ulonglong)*(ushort *)(param_1 + 0x131a) * 2) = param_2;
      if (*(short *)(param_1 + 0x131a) == 0x1f) {
        *(undefined2 *)(param_1 + 0x131a) = 0;
      }
      else {
        *(short *)(param_1 + 0x131a) = *(short *)(param_1 + 0x131a) + 1;
      }
    }
  }
  return;
}



===== QueueRawIoReadWriteRequest @ 1c000c6b0 =====

ulonglong QueueRawIoReadWriteRequest(longlong param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  int *piVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  bool bVar15;
  
  *(int *)(param_1 + 0xe2a4) = *(int *)(param_1 + 0xe2a4) + 1;
  if (*(int *)(param_2 + 0x70) != 1) {
    uVar13 = *(ulonglong *)(param_2 + 0x80);
    lVar7 = *(longlong *)(param_2 + 0x28);
    uVar9 = 0x10000;
    if (*(uint *)(param_1 + 0x8064) < 0x10000) {
      uVar9 = *(uint *)(param_1 + 0x8064);
    }
    lVar5 = (uVar13 / *(uint *)(param_1 + 0xa920)) * (ulonglong)*(uint *)(param_1 + 0xa920);
    *(longlong *)(param_2 + 0x90) = lVar5;
    *(ulonglong *)(param_2 + 0x98) = (ulonglong)*(uint *)(param_1 + 0xa920) + lVar5;
    uVar4 = (ulonglong)*(uint *)(lVar7 + 0x28);
    lVar5 = *(longlong *)(param_1 + 0x8948 + uVar4 * 8);
    if (lVar5 == 0) {
      *(longlong *)(param_1 + 0x8948 + uVar4 * 8) = param_2;
      *(undefined8 *)(param_2 + 0x50) = 0;
      *(undefined8 *)(param_2 + 0x48) = 0;
    }
    else {
      uVar4 = *(ulonglong *)(lVar5 + 0x28);
      lVar8 = uVar4 + 0x20;
      if ((uVar13 < *(ulonglong *)(lVar5 + 0x90)) ||
         (uVar4 = *(ulonglong *)(lVar5 + 0x98), uVar4 < *(ulonglong *)(param_2 + 0x88)))
      goto LAB_1c000c9a8;
      uVar12 = *(uint *)(lVar7 + 0x34) & 0xc0;
      if (*(ulonglong *)(lVar5 + 0x80) <= uVar13) {
        lVar10 = lVar8;
        do {
          if (*(char *)(param_1 + 0x15a5) == '\0') {
            if (((uVar13 != *(ulonglong *)(lVar5 + 0x88)) ||
                (uVar14 = *(uint *)(lVar10 + 0x34),
                *(uint *)(param_1 + 0x806c) <= *(int *)(lVar7 + 0x54) + uVar14)) ||
               (uVar9 < (uint)(*(int *)(lVar10 + 0x18) + *(int *)(lVar7 + 0x38))))
            goto LAB_1c000cc9a;
            if (uVar12 == (*(uint *)(lVar10 + 0x14) & 0xc0)) {
              uVar9 = 0;
              if (*(int *)(lVar7 + 0x54) != 0) {
                do {
                  uVar13 = (ulonglong)uVar9;
                  uVar9 = uVar9 + 1;
                  uVar4 = (ulonglong)uVar14;
                  uVar14 = uVar14 + 1;
                  *(undefined4 *)(lVar10 + 0x38 + uVar4 * 8) =
                       *(undefined4 *)(lVar7 + 0x58 + uVar13 * 8);
                  *(undefined4 *)(lVar10 + 0x3c + uVar4 * 8) =
                       *(undefined4 *)(lVar7 + 0x5c + uVar13 * 8);
                  *(int *)(lVar10 + 0x34) = *(int *)(lVar10 + 0x34) + 1;
                } while (uVar9 < *(uint *)(lVar7 + 0x54));
              }
              *(int *)(lVar10 + 0x18) = *(int *)(lVar10 + 0x18) + *(int *)(lVar7 + 0x38);
              *(undefined8 *)(lVar5 + 0x88) = *(undefined8 *)(param_2 + 0x88);
              iVar3 = *(int *)(lVar10 + 0x20);
              if (iVar3 == 6) {
                *(char *)(lVar10 + 0x28) = *(char *)(lVar10 + 0x28) + *(char *)(lVar7 + 0x48);
              }
              else if (iVar3 == 10) {
                *(char *)(lVar10 + 0x2c) = *(char *)(lVar10 + 0x2c) + *(char *)(lVar7 + 0x4c);
              }
              else if (iVar3 == 0xc) {
                *(char *)(lVar10 + 0x2d) = *(char *)(lVar10 + 0x2d) + *(char *)(lVar7 + 0x4d);
              }
              lVar7 = *(longlong *)(lVar5 + 0x58);
              if (lVar7 != 0) {
                for (; *(longlong *)(lVar7 + 0x58) != 0; lVar7 = *(longlong *)(lVar7 + 0x58)) {
                }
                goto LAB_1c000cd96;
              }
              goto LAB_1c000cd84;
            }
            lVar6 = *(longlong *)(lVar5 + 0x48);
            if (lVar6 == 0) break;
            lVar10 = *(longlong *)(lVar6 + 0x28) + 0x20;
          }
          else if (((uVar13 == *(ulonglong *)(lVar5 + 0x88)) &&
                   ((uint)*(ushort *)(lVar7 + 0x54) + (uint)*(ushort *)(lVar8 + 0x34) <
                    *(uint *)(param_1 + 0x806c))) &&
                  ((uint)(*(int *)(lVar8 + 0x18) + *(int *)(lVar7 + 0x38)) <= uVar9)) {
            if (uVar12 == (*(uint *)(lVar8 + 0x14) & 0xc0)) {
              uVar9 = 0;
              uVar13 = (ulonglong)*(ushort *)(lVar8 + 0x34);
              if (*(short *)(lVar7 + 0x54) != 0) {
                do {
                  uVar4 = (ulonglong)uVar9;
                  uVar9 = uVar9 + 1;
                  *(undefined8 *)(lVar8 + 0x38 + uVar13 * 0xc) =
                       *(undefined8 *)(lVar7 + 0x58 + uVar4 * 0xc);
                  *(undefined4 *)(lVar8 + 0x40 + uVar13 * 0xc) =
                       *(undefined4 *)(lVar7 + 0x60 + uVar4 * 0xc);
                  *(short *)(lVar8 + 0x34) = *(short *)(lVar8 + 0x34) + 1;
                  uVar13 = (ulonglong)((int)uVar13 + 1);
                } while (uVar9 < *(ushort *)(lVar7 + 0x54));
              }
              *(int *)(lVar8 + 0x18) = *(int *)(lVar8 + 0x18) + *(int *)(lVar7 + 0x38);
              *(undefined8 *)(lVar5 + 0x88) = *(undefined8 *)(param_2 + 0x88);
              iVar3 = *(int *)(lVar8 + 0x20);
              if (iVar3 == 6) {
                *(char *)(lVar8 + 0x28) = *(char *)(lVar8 + 0x28) + *(char *)(lVar7 + 0x48);
              }
              else if (iVar3 == 10) {
                *(char *)(lVar8 + 0x2c) = *(char *)(lVar8 + 0x2c) + *(char *)(lVar7 + 0x4c);
              }
              else if (iVar3 == 0xc) {
                *(char *)(lVar8 + 0x2d) = *(char *)(lVar8 + 0x2d) + *(char *)(lVar7 + 0x4d);
              }
              lVar7 = *(longlong *)(lVar5 + 0x58);
              if (lVar7 != 0) {
                for (; *(longlong *)(lVar7 + 0x58) != 0; lVar7 = *(longlong *)(lVar7 + 0x58)) {
                }
LAB_1c000cd96:
                *(longlong *)(lVar7 + 0x58) = param_2;
                goto LAB_1c000cd9a;
              }
LAB_1c000cd84:
              *(longlong *)(lVar5 + 0x58) = param_2;
LAB_1c000cd9a:
              return CONCAT71((int7)((ulonglong)lVar7 >> 8),1);
            }
            lVar6 = *(longlong *)(lVar5 + 0x48);
            if (lVar6 == 0) break;
            lVar8 = *(longlong *)(lVar6 + 0x28) + 0x20;
          }
          else {
LAB_1c000cc9a:
            lVar6 = *(longlong *)(lVar5 + 0x48);
            if (lVar6 == 0) break;
            lVar8 = *(longlong *)(lVar6 + 0x28) + 0x20;
            lVar10 = lVar8;
          }
          lVar5 = lVar6;
        } while (*(ulonglong *)(lVar6 + 0x80) <= *(ulonglong *)(param_2 + 0x80));
      }
      if ((*(longlong *)(lVar5 + 0x50) == 0) &&
         (*(ulonglong *)(param_2 + 0x80) < *(ulonglong *)(lVar5 + 0x80))) {
        *(undefined8 *)(param_2 + 0x50) = 0;
        uVar4 = (ulonglong)*(uint *)(lVar7 + 0x28);
        *(longlong *)(param_1 + 0x8948 + uVar4 * 8) = param_2;
      }
      else {
        if ((*(longlong *)(lVar5 + 0x48) == 0) &&
           (uVar4 = *(ulonglong *)(lVar5 + 0x80), uVar4 <= *(ulonglong *)(param_2 + 0x80))) {
          *(undefined8 *)(param_2 + 0x48) = 0;
          *(longlong *)(param_2 + 0x50) = lVar5;
          *(longlong *)(lVar5 + 0x48) = param_2;
          goto LAB_1c000ce8b;
        }
        *(longlong *)(param_2 + 0x50) = *(longlong *)(lVar5 + 0x50);
        uVar4 = *(ulonglong *)(lVar5 + 0x50);
        *(longlong *)(uVar4 + 0x48) = param_2;
      }
      *(longlong *)(param_2 + 0x48) = lVar5;
      *(longlong *)(lVar5 + 0x50) = param_2;
    }
LAB_1c000ce8b:
    *(int *)(param_1 + 0xa914) = *(int *)(param_1 + 0xa914) + 1;
    goto LAB_1c000ce92;
  }
  uVar13 = *(ulonglong *)(param_2 + 0x80);
  lVar7 = (uVar13 / *(uint *)(param_1 + 0xa920)) * (ulonglong)*(uint *)(param_1 + 0xa920);
  *(longlong *)(param_2 + 0x90) = lVar7;
  *(ulonglong *)(param_2 + 0x98) = (ulonglong)*(uint *)(param_1 + 0xa920) + lVar7;
  if (*(int *)(param_1 + 0x8088) == 2) {
    lVar7 = *(longlong *)(param_2 + 0x28);
    uVar4 = (ulonglong)*(ushort *)(lVar7 + 0x2c);
    lVar5 = *(longlong *)(param_1 + 0x8158 + uVar4 * 8);
    if (lVar5 == 0) goto LAB_1c000cb30;
    if ((uVar13 < *(ulonglong *)(lVar5 + 0x90)) ||
       (uVar4 = *(ulonglong *)(lVar5 + 0x98), uVar4 < *(ulonglong *)(param_2 + 0x88))) {
      *(int *)(param_1 + 0xe2ac) = *(int *)(param_1 + 0xe2ac) + 1;
      goto LAB_1c000c9a8;
    }
    uVar2 = *(ushort *)(lVar7 + 0x2e);
    bVar15 = uVar13 < *(ulonglong *)(lVar5 + 0x80);
    while (!bVar15) {
      lVar8 = *(longlong *)(param_2 + 0x80);
      lVar10 = *(longlong *)(lVar5 + 0x88);
      lVar6 = *(longlong *)(lVar5 + 0x28);
      if (lVar8 == lVar10) {
        bVar1 = *(byte *)(lVar6 + 0x38);
        uVar9 = (uint)bVar1;
        if ((*(uint *)(param_1 + 0x806c) <= (uint)*(byte *)(lVar7 + 0x38) + (uint)bVar1) ||
           (*(uint *)(param_1 + 0x8064) < (uint)(*(int *)(lVar6 + 0x28) + *(int *)(lVar7 + 0x28))))
        goto LAB_1c000c7e1;
        if ((uVar2 & 3) == (*(ushort *)(lVar6 + 0x2e) & 3)) {
          uVar12 = 0;
          uVar13 = (ulonglong)bVar1;
          if (*(char *)(lVar7 + 0x38) != '\0') {
            do {
              uVar4 = (ulonglong)uVar12;
              uVar12 = uVar12 + 1;
              uVar9 = (int)uVar13 + 1;
              lVar8 = uVar4 * 0x10;
              *(undefined4 *)((uVar13 + 2) * 0x10 + 0x20 + lVar6) =
                   *(undefined4 *)(lVar7 + 0x20 + (uVar4 + 2) * 0x10);
              *(undefined4 *)(lVar6 + 0x44 + uVar13 * 0x10) = *(undefined4 *)(lVar8 + 0x44 + lVar7);
              *(undefined4 *)(lVar6 + 0x48 + uVar13 * 0x10) = *(undefined4 *)(lVar8 + 0x48 + lVar7);
              *(undefined4 *)(lVar6 + 0x4c + uVar13 * 0x10) = 0;
              *(char *)(lVar6 + 0x38) = *(char *)(lVar6 + 0x38) + '\x01';
              uVar13 = (ulonglong)uVar9;
            } while (uVar12 < *(byte *)(lVar7 + 0x38));
          }
          if ((*(ushort *)(lVar6 + 0x2e) & 0x10) != 0) {
            bVar15 = true;
            if (2 < uVar9) {
              piVar11 = (int *)(lVar6 + 0x68);
              uVar13 = (ulonglong)(uVar9 - 2);
              do {
                iVar3 = *piVar11;
                piVar11 = piVar11 + 4;
                if (iVar3 != *(int *)(lVar6 + 0x58)) {
                  bVar15 = false;
                }
                uVar13 = uVar13 - 1;
              } while (uVar13 != 0);
              if (!bVar15) {
                *(ushort *)(lVar6 + 0x2e) = *(ushort *)(lVar6 + 0x2e) & 0xffef;
              }
            }
            if (((*(byte *)(lVar6 + 0x2e) & 0x10) != 0) && (*(int *)(lVar6 + 0x34) == 0)) {
              *(undefined4 *)(lVar6 + 0x34) = *(undefined4 *)(lVar6 + 0x58);
            }
          }
          *(ushort *)(*(longlong *)(lVar5 + 0x28) + 8) = (*(byte *)(lVar6 + 0x38) + 4) * 0x10;
          *(int *)(lVar6 + 0x28) = *(int *)(lVar6 + 0x28) + *(int *)(lVar7 + 0x28);
          *(undefined8 *)(lVar5 + 0x88) = *(undefined8 *)(param_2 + 0x88);
          uVar4 = *(ulonglong *)(lVar5 + 0x58);
          if (uVar4 == 0) {
            *(longlong *)(lVar5 + 0x58) = param_2;
            goto LAB_1c000ce92;
          }
          for (; *(ulonglong *)(uVar4 + 0x58) != 0; uVar4 = *(ulonglong *)(uVar4 + 0x58)) {
          }
          goto LAB_1c000c92d;
        }
        *(int *)(param_1 + 0xe2b0) = *(int *)(param_1 + 0xe2b0) + 1;
        lVar8 = *(longlong *)(lVar5 + 0x48);
        if (lVar8 != 0) goto LAB_1c000c82b;
        break;
      }
LAB_1c000c7e1:
      if (*(longlong *)(lVar5 + 0x48) == 0) break;
      if (lVar8 == lVar10) {
        if ((uint)*(byte *)(lVar6 + 0x38) + (uint)*(byte *)(lVar7 + 0x38) <
            *(uint *)(param_1 + 0x806c)) {
          if ((lVar8 == lVar10) &&
             (*(uint *)(param_1 + 0x8064) < (uint)(*(int *)(lVar6 + 0x28) + *(int *)(lVar7 + 0x28)))
             ) {
            *(int *)(param_1 + 0xe2b8) = *(int *)(param_1 + 0xe2b8) + 1;
          }
        }
        else {
          *(int *)(param_1 + 0xe2b4) = *(int *)(param_1 + 0xe2b4) + 1;
        }
      }
      lVar8 = *(longlong *)(lVar5 + 0x48);
LAB_1c000c82b:
      lVar5 = lVar8;
      bVar15 = *(ulonglong *)(param_2 + 0x80) < *(ulonglong *)(lVar8 + 0x80);
    }
    if ((*(longlong *)(lVar5 + 0x50) == 0) &&
       (*(ulonglong *)(param_2 + 0x80) < *(ulonglong *)(lVar5 + 0x80))) {
      *(undefined8 *)(param_2 + 0x50) = 0;
      uVar4 = (ulonglong)*(ushort *)(lVar7 + 0x2c);
      *(longlong *)(param_1 + 0x8158 + uVar4 * 8) = param_2;
    }
    else {
      if ((*(longlong *)(lVar5 + 0x48) == 0) &&
         (uVar4 = *(ulonglong *)(lVar5 + 0x80), uVar4 <= *(ulonglong *)(param_2 + 0x80))) {
        *(undefined8 *)(param_2 + 0x48) = 0;
        *(longlong *)(param_2 + 0x50) = lVar5;
        *(longlong *)(lVar5 + 0x48) = param_2;
        goto LAB_1c000cb40;
      }
      *(longlong *)(param_2 + 0x50) = *(longlong *)(lVar5 + 0x50);
      uVar4 = *(ulonglong *)(lVar5 + 0x50);
      *(longlong *)(uVar4 + 0x48) = param_2;
    }
    *(longlong *)(param_2 + 0x48) = lVar5;
    *(longlong *)(lVar5 + 0x50) = param_2;
  }
  else {
    lVar7 = *(longlong *)(param_2 + 0x28);
    uVar4 = (ulonglong)*(ushort *)(lVar7 + 0x2c);
    lVar5 = *(longlong *)(param_1 + 0x8158 + uVar4 * 8);
    if (lVar5 == 0) {
LAB_1c000cb30:
      *(longlong *)(param_1 + 0x8158 + uVar4 * 8) = param_2;
      *(undefined8 *)(param_2 + 0x50) = 0;
      *(undefined8 *)(param_2 + 0x48) = 0;
    }
    else {
      if ((uVar13 < *(ulonglong *)(lVar5 + 0x90)) ||
         (uVar4 = *(ulonglong *)(lVar5 + 0x98), uVar4 < *(ulonglong *)(param_2 + 0x88))) {
LAB_1c000c9a8:
        return uVar4 & 0xffffffffffffff00;
      }
      for (; *(ulonglong *)(lVar5 + 0x80) <= uVar13; lVar5 = *(longlong *)(lVar5 + 0x48)) {
        lVar8 = *(longlong *)(lVar5 + 0x28);
        if ((((uVar13 == *(ulonglong *)(lVar5 + 0x88)) &&
             (uVar9 = *(uint *)(lVar8 + 0x34),
             *(int *)(lVar7 + 0x34) + uVar9 < *(uint *)(param_1 + 0x806c))) &&
            ((uint)(*(int *)(lVar8 + 0x28) + *(int *)(lVar7 + 0x28)) <= *(uint *)(param_1 + 0x8064))
            ) && ((*(ushort *)(lVar7 + 0x2e) & 3) == (*(ushort *)(lVar8 + 0x2e) & 3))) {
          uVar12 = 0;
          if (*(int *)(lVar7 + 0x34) != 0) {
            do {
              uVar13 = (ulonglong)uVar12;
              uVar12 = uVar12 + 1;
              uVar4 = (ulonglong)uVar9;
              uVar9 = uVar9 + 1;
              *(undefined4 *)(lVar8 + 0x40 + uVar4 * 0x18) =
                   *(undefined4 *)(lVar7 + 0x40 + uVar13 * 0x18);
              *(undefined4 *)(lVar8 + 0x44 + uVar4 * 0x18) =
                   *(undefined4 *)(lVar7 + 0x44 + uVar13 * 0x18);
              *(undefined4 *)(lVar8 + 0x48 + uVar4 * 0x18) =
                   *(undefined4 *)(lVar7 + 0x48 + uVar13 * 0x18);
              *(int *)(lVar8 + 0x34) = *(int *)(lVar8 + 0x34) + 1;
            } while (uVar12 < *(uint *)(lVar7 + 0x34));
          }
          *(short *)(*(longlong *)(lVar5 + 0x28) + 8) = *(short *)(lVar8 + 0x34) * 0x18 + 0x38;
          *(int *)(lVar8 + 0x28) = *(int *)(lVar8 + 0x28) + *(int *)(lVar7 + 0x28);
          *(undefined8 *)(lVar5 + 0x88) = *(undefined8 *)(param_2 + 0x88);
          uVar4 = *(ulonglong *)(lVar5 + 0x58);
          if (uVar4 == 0) {
            *(longlong *)(lVar5 + 0x58) = param_2;
          }
          else {
            for (; *(ulonglong *)(uVar4 + 0x58) != 0; uVar4 = *(ulonglong *)(uVar4 + 0x58)) {
            }
LAB_1c000c92d:
            *(longlong *)(uVar4 + 0x58) = param_2;
          }
          goto LAB_1c000ce92;
        }
        if (*(longlong *)(lVar5 + 0x48) == 0) break;
      }
      uVar4 = *(ulonglong *)(lVar5 + 0x50);
      if ((uVar4 == 0) && (uVar13 < *(ulonglong *)(lVar5 + 0x80))) {
        *(undefined8 *)(param_2 + 0x50) = 0;
        uVar4 = (ulonglong)*(ushort *)(lVar7 + 0x2c);
        *(longlong *)(param_1 + 0x8158 + uVar4 * 8) = param_2;
      }
      else {
        if ((*(longlong *)(lVar5 + 0x48) == 0) && (*(ulonglong *)(lVar5 + 0x80) <= uVar13)) {
          *(undefined8 *)(param_2 + 0x48) = 0;
          *(longlong *)(param_2 + 0x50) = lVar5;
          *(longlong *)(lVar5 + 0x48) = param_2;
          goto LAB_1c000cb40;
        }
        *(ulonglong *)(param_2 + 0x50) = uVar4;
        uVar4 = *(ulonglong *)(lVar5 + 0x50);
        *(longlong *)(uVar4 + 0x48) = param_2;
      }
      *(longlong *)(param_2 + 0x48) = lVar5;
      *(longlong *)(lVar5 + 0x50) = param_2;
    }
  }
LAB_1c000cb40:
  *(int *)(param_1 + 0xa910) = *(int *)(param_1 + 0xa910) + 1;
LAB_1c000ce92:
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== SendFib @ 1c000ceb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char SendFib(undefined2 param_1,longlong param_2,char param_3)

{
  short *psVar1;
  byte bVar2;
  longlong lVar3;
  uint *puVar4;
  longlong lVar5;
  bool bVar6;
  char cVar7;
  ushort uVar8;
  int *piVar9;
  uint uVar10;
  ulonglong uVar11;
  bool bVar12;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar3 = *(longlong *)(param_2 + 0x40);
  puVar4 = *(uint **)(param_2 + 0x28);
  uVar11 = 0;
  local_38[0] = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  bVar6 = true;
  if ((*(char *)(lVar3 + 0x805c) != '\0') && (*(char *)(lVar3 + 0xaad6) != '\0')) {
    return '\0';
  }
  if (((*puVar4 & 1) != 0) && ((ushort)puVar4[2] <= *(ushort *)((longlong)puVar4 + 10))) {
    do {
      if (*(longlong *)(lVar3 + 0x6050 + uVar11 * 8) == 0) {
        *(longlong *)(lVar3 + 0x6050 + uVar11 * 8) = param_2;
        puVar4[3] = (int)uVar11 << 2;
        break;
      }
      uVar10 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar10;
    } while (uVar10 < 0x400);
    if ((uint)uVar11 < 0x400) goto LAB_1c000cf55;
  }
  bVar6 = false;
LAB_1c000cf55:
  *(undefined4 *)(param_2 + 0x78) = 4;
  if (bVar6) {
    *puVar4 = *puVar4 | 0x30a0;
    *(undefined2 *)(puVar4 + 1) = param_1;
    if (param_3 == '\0') {
      *(undefined1 *)((longlong)puVar4 + 7) = 0;
    }
    bVar12 = *(char *)(lVar3 + 0xaad6) == '\0';
    if (bVar12) {
      StorPortNotification(0x1003,lVar3,3,0,local_38);
    }
    cVar7 = (**(code **)(lVar3 + 0x80d0))(param_2);
    if (cVar7 == '\0') {
      *(undefined8 *)(lVar3 + 0x6050 + uVar11 * 8) = 0;
      bVar6 = false;
    }
    else {
      *(short *)(lVar3 + 0xba20) = *(short *)(lVar3 + 0xba20) + 1;
      lVar5 = *(longlong *)(param_2 + 0x18);
      if ((*(char *)(lVar5 + 5) == '\x04') && (*(char *)(lVar5 + 2) == '\0')) {
        bVar2 = *(byte *)(lVar5 + 0x48);
        if (((bVar2 < 0x2b) && ((0x50000000500U >> ((ulonglong)bVar2 & 0x3f) & 1) != 0)) ||
           ((bVar2 == 0x88 || (bVar2 == 0x8a)))) {
          psVar1 = (short *)(lVar3 + 0xd6e0 +
                            (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x28) + 0x2c) * 2);
          *psVar1 = *psVar1 + 1;
        }
      }
      uVar8 = GetOutstandingIoCnt(lVar3);
      if ((*(uint *)(lVar3 + 0x8054) <= (uint)uVar8) && (*(char *)(lVar3 + 0xaad6) == '\0')) {
        uVar10 = 0;
        piVar9 = (int *)(lVar3 + 0x19cc);
        do {
          if (*piVar9 == 1) {
            StorPortPauseDevice(lVar3,4,(char)uVar10,0,1);
          }
          uVar10 = uVar10 + 1;
          piVar9 = piVar9 + 10;
        } while (uVar10 < 0xfe);
        uVar10 = 0;
        piVar9 = (int *)(lVar3 + 0x417c);
        do {
          if (*piVar9 == 1) {
            StorPortPauseDevice(lVar3,0,(char)uVar10,0,1);
          }
          uVar10 = uVar10 + 1;
          piVar9 = piVar9 + 4;
        } while (uVar10 < 0xfe);
        *(undefined1 *)(lVar3 + 0x805c) = 1;
      }
      if ((*(uint *)(lVar3 + 0xba0c) <= (uint)uVar8) && (*(char *)(lVar3 + 0xaad6) != '\0')) {
        uVar10 = 0;
        piVar9 = (int *)(lVar3 + 0x19cc);
        do {
          if (*piVar9 == 1) {
            StorPortPauseDevice(lVar3,4,(char)uVar10,0,1);
          }
          uVar10 = uVar10 + 1;
          piVar9 = piVar9 + 10;
        } while (uVar10 < 0xfe);
        uVar10 = 0;
        piVar9 = (int *)(lVar3 + 0x417c);
        do {
          if (*piVar9 == 1) {
            StorPortPauseDevice(lVar3,0,(char)uVar10,0,1);
          }
          uVar10 = uVar10 + 1;
          piVar9 = piVar9 + 4;
        } while (uVar10 < 0xfe);
        *(undefined1 *)(lVar3 + 0x805c) = 1;
      }
    }
    if (bVar12) {
      StorPortNotification(0x1004,lVar3,local_38);
    }
  }
  return bVar6;
}



===== SendRawIoFib @ 1c000d15c =====

char SendRawIoFib(undefined2 param_1,longlong param_2)

{
  int *piVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  char cVar7;
  ushort uVar8;
  short sVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  int iVar13;
  int iVar14;
  
  lVar4 = *(longlong *)(param_2 + 0x40);
  iVar13 = 1;
  cVar6 = '\x01';
  cVar7 = '\x01';
  uVar8 = GetOutstandingIoCnt(lVar4);
  iVar14 = iVar13 + 1;
  lVar5 = *(longlong *)(param_2 + 0x28);
  *(undefined4 *)(param_2 + 0x78) = 3;
  if (*(int *)(param_2 + 0x70) == iVar14) {
    uVar12 = (ulonglong)*(uint *)(lVar5 + 0x28);
    if (*(longlong *)(param_2 + 0x80) == *(longlong *)(lVar4 + 0x9928 + uVar12 * 8)) {
      piVar1 = (int *)(lVar4 + 0xa510 + uVar12 * 4);
      *piVar1 = *piVar1 + iVar13;
    }
    else {
      *(undefined4 *)(lVar4 + 0xa510 + uVar12 * 4) = 0;
      if (*(char *)(lVar4 + 0xa918) != '\0') {
        DequeueRawIoReadWriteRequest(lVar4,'\0',0);
        iVar13 = 1;
      }
    }
    *(undefined8 *)(lVar4 + 0x9928 + (ulonglong)*(uint *)(lVar5 + 0x28) * 8) =
         *(undefined8 *)(param_2 + 0x88);
    if ((*(char *)(lVar4 + 0xa924) == '\0') || ((uint)uVar8 < *(uint *)(lVar4 + 0xa908)))
    goto LAB_1c000d413;
    uVar3 = *(uint *)(lVar4 + 0xa510 + (ulonglong)*(uint *)(lVar5 + 0x28) * 4);
    cVar7 = '\x01';
  }
  else {
    uVar2 = *(ushort *)(lVar5 + 0x2c);
    uVar12 = (ulonglong)uVar2;
    cVar7 = '\x01';
    if (*(longlong *)(param_2 + 0x80) == *(longlong *)(lVar4 + 0x9138 + uVar12 * 8)) {
      piVar1 = (int *)(lVar4 + 0xa118 + uVar12 * 4);
      *piVar1 = *piVar1 + iVar13;
      if (*(int *)(lVar4 + 0xc300 + uVar12 * 4) != 0) {
        uVar10 = DeQueueSortingQueue(lVar4,uVar2);
        cVar6 = (char)uVar10;
        if (cVar6 == '\0') {
          uVar11 = QueueSortingQ(lVar4,param_2);
          if ((char)uVar11 != '\0') {
            *(undefined8 *)(lVar4 + 0x9138 + uVar12 * 8) = *(undefined8 *)(param_2 + 0x88);
            *(short *)(lVar4 + 0xba24) = *(short *)(lVar4 + 0xba24) + 1;
            return '\x01';
          }
          goto LAB_1c000d3a3;
        }
LAB_1c000d3c9:
        iVar13 = 1;
        cVar7 = cVar6;
      }
    }
    else {
      uVar3 = *(uint *)(lVar4 + 0xa118 + uVar12 * 4);
      if ((((100 < uVar3) && (*(int *)(param_2 + 0x70) == iVar13)) &&
          (*(int *)(lVar4 + 0x8088) == iVar14)) &&
         ((*(char *)(lVar4 + 0xaad6) != '\0' &&
          ((ushort)iVar14 <
           (ushort)(*(short *)(lVar4 + 0xd6e0 + uVar12 * 2) -
                   *(short *)(lVar4 + 0xd8dc + uVar12 * 2)))))) {
        *(uint *)(lVar4 + 0xa118 + uVar12 * 4) = uVar3 + 1;
        if (*(longlong *)(lVar4 + 0xc6f8 + uVar12 * 8) == 0xdeadbeef) {
          *(undefined8 *)(lVar4 + 0xc6f8 + uVar12 * 8) =
               *(undefined8 *)(lVar4 + 0x9138 + uVar12 * 8);
        }
        uVar11 = QueueSortingQ(lVar4,param_2);
        if ((char)uVar11 != '\0') {
          *(undefined8 *)(lVar4 + 0x9138 + uVar12 * 8) = *(undefined8 *)(param_2 + 0x88);
          *(short *)(lVar4 + 0xba24) = *(short *)(lVar4 + 0xba24) + 1;
          if (*(int *)(lVar4 + 0xd2e0 + uVar12 * 4) != 0) {
            DeQueueSortingQueue(lVar4,uVar2);
          }
          return '\x01';
        }
        cVar6 = '\x01';
        if (*(int *)(lVar4 + 0xc300 + uVar12 * 4) != 0) {
          uVar10 = DeQueueSortingQueue(lVar4,uVar2);
          cVar6 = (char)uVar10;
        }
        if (*(char *)(lVar4 + 0xa918) != '\0') {
          DequeueRawIoReadWriteRequest(lVar4,'\0',0);
        }
LAB_1c000d3a3:
        *(undefined4 *)(lVar4 + 0xa118 + uVar12 * 4) = 0;
        goto LAB_1c000d3c9;
      }
      *(undefined4 *)(lVar4 + 0xa118 + uVar12 * 4) = 0;
      if (*(char *)(lVar4 + 0xa918) != '\0') {
        DequeueRawIoReadWriteRequest(lVar4,'\0',0);
        goto LAB_1c000d3c9;
      }
    }
    *(undefined8 *)(lVar4 + 0x9138 + uVar12 * 8) = *(undefined8 *)(param_2 + 0x88);
    if ((*(char *)(lVar4 + 0xa924) == '\0') || ((uint)uVar8 < *(uint *)(lVar4 + 0xa908)))
    goto LAB_1c000d413;
    uVar3 = *(uint *)(lVar4 + 0xa118 + uVar12 * 4);
  }
  if ((3 < uVar3) && (*(uint *)(*(longlong *)(param_2 + 0x18) + 0x10) <= *(uint *)(lVar4 + 0xa91c)))
  {
    *(char *)(lVar4 + 0xa918) = (char)iVar13;
  }
LAB_1c000d413:
  *(short *)(lVar4 + 0xba24) = *(short *)(lVar4 + 0xba24) + (short)iVar13;
  if (*(char *)(lVar4 + 0xa918) == '\0') {
    *(int *)(lVar4 + 0xe2c0) = *(int *)(lVar4 + 0xe2c0) + iVar13;
    cVar7 = SendFib(param_1,param_2,'\0');
  }
  else {
    uVar12 = QueueRawIoReadWriteRequest(lVar4,param_2);
    if ((char)uVar12 == '\0') {
      DequeueRawIoReadWriteRequest(lVar4,'\0',0);
      *(undefined1 *)(lVar4 + 0xa918) = 1;
      uVar12 = QueueRawIoReadWriteRequest(lVar4,param_2);
      if ((char)uVar12 == '\0') {
        cVar7 = SendFib(param_1,param_2,'\0');
        *(undefined1 *)(lVar4 + 0xa918) = 0;
      }
    }
    sVar9 = GetOutstandingIoCnt(lVar4);
    if ((((*(int *)(lVar4 + 0xa910) != 0) || (*(int *)(lVar4 + 0xa914) != 0)) && (sVar9 == 0)) &&
       (*(char *)(lVar4 + 0xa970) == '\0')) {
      DequeueRawIoReadWriteRequest(lVar4,'\0',0);
    }
  }
  return cVar7;
}



===== SendSynchFib @ 1c000d4e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SendSynchFib(longlong param_1,undefined8 param_2,uint *param_3,ulonglong param_4,
                      void *param_5,ushort *param_6,char param_7)

{
  short sVar1;
  undefined4 *puVar2;
  uint uVar3;
  void *pvVar4;
  ushort uVar5;
  undefined1 local_res8 [8];
  
  puVar2 = *(undefined4 **)(param_1 + 0x1d8);
  uVar5 = (ushort)param_2;
  if (*(char *)(param_1 + 0xe2d4) == '\0') {
    puVar2[4] = 0;
    *(short *)(puVar2 + 2) = (short)param_4 + 0x20;
    *(undefined2 *)((longlong)puVar2 + 10) = 0x200;
    *(undefined1 *)((longlong)puVar2 + 6) = 1;
    *puVar2 = 0x102d;
    *(ushort *)(puVar2 + 1) = uVar5;
    memcpy(puVar2 + 8,param_3,param_4 & 0xffff);
  }
  else {
    GetElapsedSeconds(param_1,param_2,param_3,param_4);
    if (uVar5 == 500) {
      uVar3 = *param_3;
    }
    else {
      uVar3 = (uint)uVar5;
    }
    if (uVar3 != *(uint *)(param_1 + 0xe2d8)) {
      pvVar4 = (void *)ArcPrintf(param_1,4,
                                 (byte *)
                                 "* SendSynchFib: There is a pending synch FIB cmd: 0x%x(%d). Has been pending %d seconds. Rejecting synch Cmd: 0x%x(%d)\n"
                                 ,(ulonglong)*(uint *)(param_1 + 0xe2d8));
      goto LAB_1c000d562;
    }
  }
  pvVar4 = (void *)(*(code *)**(undefined8 **)(param_1 + 0x1320))
                             (param_1,0xc,*(undefined4 *)(param_1 + 0x1e0),0,0,0,0,0,0,0,local_res8,
                              param_7);
  if ((char)pvVar4 != '\0') {
    if ((param_7 != '\0') && (param_5 != (void *)0x0)) {
      sVar1 = *(short *)(puVar2 + 2);
      pvVar4 = memcpy(param_5,puVar2 + 8,(ulonglong)(ushort)(sVar1 - 0x20U));
      *param_6 = sVar1 - 0x20U;
    }
    return CONCAT71((int7)((ulonglong)pvVar4 >> 8),1);
  }
LAB_1c000d562:
  return (ulonglong)pvVar4 & 0xffffffffffffff00;
}



===== StartIo @ 1c000d650 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 StartIo(longlong param_1,ushort *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *_Dst;
  char cVar4;
  char cVar5;
  bool bVar6;
  uint uVar7;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  int *piVar8;
  undefined4 extraout_var_03;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  ulonglong uVar9;
  longlong lVar10;
  ushort *puVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  char *pcVar14;
  size_t _Size;
  ulonglong uVar15;
  undefined4 *puVar16;
  uint *puVar17;
  byte bVar18;
  undefined1 auStackY_98 [32];
  ushort local_58 [4];
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar10 = *(longlong *)(param_2 + 0x1c);
  bVar1 = *(byte *)((longlong)param_2 + 5);
  bVar2 = (byte)param_2[3];
  uVar13 = (ulonglong)bVar2;
  cVar5 = *(char *)((longlong)param_2 + 7);
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x200;
  puVar11 = param_2;
  if ((*(char *)(param_1 + 0x618) != '\0') && (*(char *)(param_1 + 0x516a) != '\0')) {
    *(undefined1 *)(param_1 + 0x617) = 1;
    cVar4 = InitializeAdapterAfterIOPReset(param_1,(longlong)param_2);
    if (cVar4 == '\0') {
      *(undefined4 *)(param_1 + 0x1d0) = 4;
    }
    else {
      *(undefined2 *)(param_1 + 0x618) = 0;
      *(undefined1 *)(param_1 + 0x617) = 0;
      *(undefined4 *)(param_1 + 0x1d0) = 1;
      *(undefined4 *)(param_1 + 0x648) = 0;
    }
  }
  uVar15 = 0;
  if ((((*(uint *)(param_1 + 0xbad8) & 0x18) != 0) && ((char)*(uint *)(param_1 + 0xbad8) < '\0')) &&
     (*(int *)(param_1 + 0x1d0) == 1)) {
    *(undefined4 *)(param_1 + 0x1d0) = 4;
  }
  *(undefined1 *)((longlong)param_2 + 3) = 6;
  puVar16 = (undefined4 *)(lVar10 + 0x4f7U & 0xffffffffffffffe0);
  pcVar14 = (char *)0x2;
  *(undefined4 *)(lVar10 + 0x78) = 2;
  iVar3 = *(int *)(param_1 + 0x1d0);
  *(short *)(param_1 + 0xba28) = *(short *)(param_1 + 0xba28) + 1;
  if ((((iVar3 - 2U & 0xfffffffd) == 0) || (*(char *)(param_1 + 0x516c) != '\0')) ||
     ((*(uint *)(param_1 + 0xbad8) & 2) != 0)) {
    if (iVar3 == 2) {
      cVar5 = '\b';
      goto LAB_1c000ddcc;
    }
    if ((iVar3 != 4) &&
       (uVar9 = (ulonglong)*(uint *)(param_1 + 0xbad8), (*(uint *)(param_1 + 0xbad8) & 2) == 0)) {
      if (*(longlong *)(param_1 + 0x1a0) == 0) {
        *(ushort **)(param_1 + 0x1a0) = param_2;
        uVar9 = RequestTimer(param_1,4,1000000,1);
        goto LAB_1c000dee5;
      }
      cVar5 = '\x05';
      goto LAB_1c000ddc3;
    }
    *(undefined1 *)((longlong)param_2 + 3) = 5;
    *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)(*(longlong *)(param_2 + 0x1c) + 0xa0);
    uVar9 = StorPortNotification(0,param_1,param_2);
    *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
    if (((*(char *)(param_1 + 0x618) == '\0') &&
        (uVar9 = StorPortPause(param_1,3), *(char *)(param_1 + 0x618) == '\0')) ||
       (*(char *)(param_1 + 0x516a) == '\0')) goto LAB_1c000dee5;
    uVar12 = 0x1e;
  }
  else {
    uVar9 = (ulonglong)*(uint *)(param_1 + 0xbad8);
    if (((*(char *)(param_1 + 0x610) == '\0') &&
        (uVar9 = uVar13, *(int *)(param_1 + 0x19cc + uVar13 * 0x28) == 1)) &&
       ((bVar1 == 4 && ((char)param_2[1] == '\0')))) {
      cVar4 = (char)param_2[0x24];
      uVar9 = 0;
      if ((((cVar4 != '(') && (cVar4 != '*')) && (cVar4 != -0x78)) && (cVar4 != -0x76))
      goto LAB_1c000d82d;
      if ((*(char *)(param_1 + 0x8084) == '\x01') || (*(char *)(param_1 + 0x808d) != '\0')) {
        cVar5 = SendRawIoFib(0x1f7 - (ushort)(*(int *)(param_1 + 0x8088) != 2),lVar10);
        uVar9 = CONCAT71(extraout_var_00,cVar5);
        if (cVar5 != '\0') {
          *(undefined4 *)(lVar10 + 0x70) = 1;
          goto LAB_1c000dee5;
        }
LAB_1c000d81f:
        *(undefined4 *)(lVar10 + 0x70) = 0;
      }
      else {
        cVar5 = SendFib((*(char *)(param_1 + 0x15a5) != '\0') + 500,lVar10,'\0');
        uVar9 = CONCAT71(extraout_var,cVar5);
        if (cVar5 != '\0') goto LAB_1c000dee5;
      }
LAB_1c000d7f3:
      cVar5 = '\x05';
    }
    else {
LAB_1c000d82d:
      bVar18 = (byte)param_2[1];
      uVar9 = CONCAT71((int7)(uVar9 >> 8),bVar18);
      if (bVar18 == 0) {
        if (bVar1 == 4) {
          lVar10 = 0xfe;
          if (bVar2 < 0xfe) {
            if ((char)param_2[0x24] == -0x60) {
              _Size = 0x10;
              if ((bVar2 == 0xfd) && (cVar5 == '\0')) {
                *(undefined1 *)(param_1 + 0x5168) = 0;
                piVar8 = (int *)(param_1 + 0x417c);
                do {
                  if (*piVar8 != 0) {
                    *(char *)(param_1 + 0x5168) = *(char *)(param_1 + 0x5168) + '\x01';
                  }
                  piVar8 = piVar8 + 4;
                  lVar10 = lVar10 + -1;
                } while (lVar10 != 0);
              }
              iVar3 = *(int *)(param_1 + 0x19cc + (ulonglong)(byte)param_2[3] * 0x28);
              if (((iVar3 == 1) || (iVar3 == 4)) && (*(char *)((longlong)param_2 + 7) == '\0')) {
                local_50 = 0x8000000;
                local_48 = 0;
                if ((*(void **)(param_2 + 0xc) == (void *)0x0) ||
                   (uVar7 = *(uint *)(param_2 + 8), uVar7 == 0)) {
                  cVar5 = '\x06';
                  *(undefined1 *)(param_2 + 2) = 2;
                }
                else {
                  if (uVar7 < 0x10) {
                    _Size = (size_t)uVar7;
                  }
                  memcpy(*(void **)(param_2 + 0xc),&local_50,_Size);
                  cVar5 = '\x01';
                }
                goto LAB_1c000ddcc;
              }
            }
            else if (((char)param_2[0x24] != '\x12') ||
                    (((iVar3 = *(int *)(param_1 + 0x19cc + (ulonglong)(byte)param_2[3] * 0x28),
                      iVar3 == 1 || (iVar3 == 4)) && (*(char *)((longlong)param_2 + 7) == '\0')))) {
              uVar7 = ProcessScsiCommand(param_1,(longlong)param_2,(longlong)puVar16);
              uVar9 = CONCAT44(extraout_var_03,uVar7);
              goto LAB_1c000dad4;
            }
          }
LAB_1c000da31:
          cVar5 = '\n';
        }
        else if (*(char *)(param_1 + 0x610) == '\0') {
          if ((((char)param_2[0x24] == '%') &&
              (*(char *)((ulonglong)(byte)param_2[3] + 0x5210 +
                        (ulonglong)*(byte *)((longlong)param_2 + 5) * 0xff + param_1) == '\0')) &&
             (*(char *)(param_1 + 0x613) != '\0')) {
            DynamicallyThrottleLunQueueDepth(param_1,(uint)(byte)param_2[3]);
            StorPortSetDeviceQueueDepth(param_1,*(undefined1 *)((longlong)param_2 + 5));
          }
          if (((*(char *)((longlong)param_2 + 5) == '\0') &&
              (*(int *)((ulonglong)(byte)param_2[3] * 0x10 + 0x417c + param_1) != 0)) &&
             (((cVar5 = (char)param_2[0x24], cVar5 == -0x78 || ((cVar5 == -0x76 || (cVar5 == '('))))
              || (cVar5 == '*')))) {
            cVar5 = SendRawIoFib((*(char *)(param_1 + 0x15a5) != '\0') + 600,lVar10);
            uVar9 = CONCAT71(extraout_var_01,cVar5);
            if (cVar5 != '\0') {
              *(undefined4 *)(lVar10 + 0x70) = 2;
              goto LAB_1c000dee5;
            }
            goto LAB_1c000d81f;
          }
          uVar7 = **(uint **)(lVar10 + 0x28);
          if ((uVar7 >> 0x13 & 1) != 0) {
            **(uint **)(lVar10 + 0x28) = uVar7 & 0xfff7ffff;
          }
          cVar5 = SendFib((*(char *)(param_1 + 0x15a5) != '\0') + 600,lVar10,'\0');
          uVar9 = CONCAT71(extraout_var_02,cVar5);
          if (cVar5 == '\0') goto LAB_1c000d7f3;
          cVar5 = '\0';
LAB_1c000ddc3:
          if (cVar5 == '\0') goto LAB_1c000dee5;
        }
        else if (*(longlong *)(param_1 + 0x188) == 0) {
          puVar17 = puVar16 + 8;
          uVar12 = SendSynchFib(param_1,CONCAT62((int6)((ulonglong)puVar11 >> 0x10),
                                                 (*(char *)(param_1 + 0x15a5) != '\0') + 600),
                                puVar17,(ulonglong)(*(ushort *)(puVar16 + 2) - 0x20),puVar17,
                                local_58,'\x01');
          if ((char)uVar12 != '\0') {
            cVar5 = (-((char)*puVar17 != '\0') & 3U) + 1;
            *(char *)((longlong)param_2 + 3) = cVar5;
            uVar9 = PostProcessScsiCommand
                              (param_1,(longlong)param_2,(longlong)puVar17,(uint)local_58[0]);
            goto LAB_1c000ddc3;
          }
          cVar5 = '\t';
        }
        else {
          cVar5 = '\x05';
        }
      }
      else if (bVar18 == 2) {
        if (*(longlong *)(param_2 + 0xc) != 0) {
          uVar9 = ProcessIoctl(param_1,param_2,puVar16,0);
LAB_1c000dad4:
          cVar5 = (char)uVar9;
          goto LAB_1c000ddc3;
        }
        cVar5 = '\x06';
        *(undefined1 *)(param_2 + 2) = 2;
      }
      else if (bVar18 < 0x12) {
LAB_1c000da38:
        cVar5 = '\x06';
        param_2[8] = 0;
        param_2[9] = 0;
        if (((*(uint *)(param_2 + 6) & 0x20) == 0) && (7 < *(byte *)((longlong)param_2 + 0xb))) {
          _Dst = *(byte **)(param_2 + 0x10);
          memset(_Dst,0,(ulonglong)*(byte *)((longlong)param_2 + 0xb));
          *_Dst = *_Dst & 0xf0 | 0x70;
          _Dst[2] = _Dst[2] & 0xf5 | 5;
          bVar2 = *(byte *)((longlong)param_2 + 0xb);
          if (bVar2 < 0xe) {
            _Dst[7] = 0;
LAB_1c000d8d7:
            *(undefined1 *)(param_2 + 2) = 0;
          }
          else {
            _Dst[0xc] = 0x20;
            _Dst[0xd] = 0;
            bVar18 = 6;
            if (0x11 < bVar2) {
              bVar18 = 10;
            }
            cVar5 = -0x7c;
            _Dst[7] = bVar18;
            *(undefined1 *)(param_2 + 2) = 2;
          }
        }
        else {
          *(undefined1 *)(param_2 + 2) = 0;
        }
      }
      else {
        if (0x13 < bVar18) {
          if (bVar18 == 0x17) {
            if ((*(longlong *)(param_2 + 0xc) == 0) || (*(char *)(param_1 + 0x517d) == '\0')) {
              cVar5 = '\x06';
              *(undefined1 *)(param_2 + 2) = 2;
            }
            else {
              uVar9 = ProcessWmi(param_1,(longlong)param_2);
              cVar5 = (char)uVar9;
            }
            goto LAB_1c000ddc3;
          }
          if (bVar18 != 0x20) {
            if (bVar18 != 0x24) goto LAB_1c000da38;
            uVar13 = (ulonglong)*(uint *)(param_2 + 0x20);
            ArcPrintf(param_1,4,(byte *)"* SRB_FUNCTION_POWER: action: %d\n",uVar13);
            if ((*(int *)(param_2 + 0x20) == 2) && (*(int *)(param_2 + 4) == 4)) {
              *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 8;
              ArcPrintf(param_1,4,(byte *)"* SRB_FUNCTION_POWER: sleep 1\n",uVar13);
            }
            if ((*(int *)(param_2 + 0x20) == 2) && (*(int *)(param_2 + 4) == 1)) {
              *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x80;
              ArcPrintf(param_1,4,
                        (byte *)"* SRB_FUNCTION_POWER: coming back from power state change\n",uVar13
                       );
            }
            else {
              if (*(int *)(param_2 + 0x20) == 3) {
                *(int *)(param_1 + 57000) = *(int *)(param_1 + 57000) + 1;
                *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x10;
                ArcPrintf(param_1,4,(byte *)"* SRB_FUNCTION_POWER: going to S3/S4\n",uVar13);
              }
              if (*(int *)(param_2 + 0x20) == 4) {
                *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x20;
                ArcPrintf(param_1,4,(byte *)"* SRB_FUNCTION_POWER: shutdown\n",uVar13);
              }
              if (*(int *)(param_2 + 0x20) == 6) {
                *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x20;
                ArcPrintf(param_1,4,(byte *)"* SRB_FUNCTION_POWER: shutdownOff\n",uVar13);
              }
              if (*(int *)(param_2 + 0x20) == 5) {
                *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x40;
                ArcPrintf(param_1,4,(byte *)"* SRB_FUNCTION_POWER: reboot\n",uVar13);
              }
              if (*(char *)(param_1 + 0x5e04) == '\0') {
                *(ushort **)(param_1 + 400) = param_2;
                uVar9 = RequestTimer(param_1,0x8000,10000,1);
                goto LAB_1c000dee5;
              }
            }
            cVar5 = '\x01';
            goto LAB_1c000d8d7;
          }
        }
        if (bVar1 != 4) {
          ArcPrintf(param_1,4,(byte *)"* Got path %d target %d reset\n",(ulonglong)bVar1);
          goto LAB_1c000da31;
        }
        if (bVar18 == 0x20) {
          piVar8 = (int *)(param_1 + 0xdeac + uVar13 * 4);
          *piVar8 = *piVar8 + 1;
          pcVar14 = "* path %d target %d reset counter now is %d\n";
          uVar15 = 4;
          ArcPrintf(param_1,4,(byte *)"* path %d target %d reset counter now is %d\n",4);
        }
        bVar6 = ResetAdapter(param_1,0x80000004,pcVar14,uVar15);
        cVar5 = (-bVar6 & 0xf7U) + 10;
      }
    }
LAB_1c000ddcc:
    *(char *)((longlong)param_2 + 3) = cVar5;
    *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)(*(longlong *)(param_2 + 0x1c) + 0xa0);
    uVar9 = StorPortNotification(0,param_1,param_2);
    *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
    if (*(char *)(param_1 + 0x516c) == '\0') {
      if (((*(char *)(param_1 + 0x610) == '\0') || (*(int *)(param_1 + 0x1d0) == 2)) ||
         (*(char *)(param_1 + 0x516a) != '\0')) {
        if (cVar5 != '\x05') goto LAB_1c000dee5;
        if ((((bVar1 & 0xfb) == 0) && ((char)param_2[1] == '\0')) &&
           (((cVar5 = (char)param_2[0x24], cVar5 == '(' || ((cVar5 == '*' || (cVar5 == -0x78)))) ||
            (cVar5 == -0x76)))) {
          uVar9 = StorPortBusy(param_1,(ulonglong)*(uint *)(param_1 + 0x8074) / 10);
          goto LAB_1c000dee5;
        }
      }
      uVar9 = StorPortPauseDevice(param_1,*(undefined1 *)((longlong)param_2 + 5),(char)param_2[3],0)
      ;
      goto LAB_1c000dee5;
    }
    uVar12 = 3;
  }
  uVar9 = StorPortPause(param_1,uVar12);
LAB_1c000dee5:
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xfffffdff;
  return CONCAT71((int7)(uVar9 >> 8),1);
}



===== AdapterControl @ 1c000df20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AdapterControl(longlong param_1,uint param_2,longlong param_3,ulonglong param_4)

{
  char cVar1;
  undefined8 uVar2;
  uint *puVar3;
  int iVar4;
  char *pcVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint local_res8;
  uint local_resc;
  uint local_res10 [2];
  undefined8 in_stack_ffffffffffffffc8;
  
  ArcPrintf(param_1,0x10000200,(byte *)"entering AdapterControl\n",param_4);
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x800;
  if (param_2 == 0) {
    if (*(char *)(param_1 + 0x613) == '\0') {
      ArcPrintf(param_1,4,(byte *)"\n* - AdapterControl: ScsiQuery WITHOUT STOR_SP1\n",param_4);
      *(undefined4 *)(param_3 + 4) = 1;
      *(undefined1 *)(param_3 + 8) = 0;
    }
    else {
      ArcPrintf(param_1,4,(byte *)"\n* - AdapterControl: ScsiQuery with STOR_SP1\n",param_4);
      *(undefined4 *)(param_3 + 4) = 0x1010101;
      *(undefined1 *)(param_3 + 8) = 1;
    }
  }
  else if (param_2 == 1) {
    pcVar5 = "* - AdapterControl: ScsiStopAdapter\n";
    ArcPrintf(param_1,4,(byte *)"* - AdapterControl: ScsiStopAdapter\n",param_4);
    param_4 = 2;
    StopTimer(param_1,1,pcVar5,2);
    if ((*(int *)(param_1 + 0x1d0) == 1) && (*(char *)(param_1 + 0x5e04) == '\0')) {
      *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x2000;
      local_res8 = 5;
      if ((*(uint *)(param_1 + 0xbad8) & 8) == 0) {
        local_resc = (byte)~(byte)*(uint *)(param_1 + 0xbad8) >> 2 | 0xfffffffb;
      }
      else {
        local_resc = 0xfffffffd;
      }
      param_4 = 8;
      uVar2 = SendSynchFib(param_1,500,&local_res8,8,&local_res8,(ushort *)local_res10,'\x01');
      if ((char)uVar2 == '\0') {
        param_4 = (ulonglong)local_resc;
        ArcPrintf(param_1,4,
                  (byte *)
                  "* - AdapterControl: ScsiStopAdapter, VM_CloseALL command Failed with container ID:0x%x!\n"
                  ,param_4);
      }
      else {
        *(undefined1 *)(param_1 + 0x5e04) = 1;
      }
    }
    *(undefined1 *)(param_1 + 0x616) = *(undefined1 *)(param_1 + 0x610);
    *(undefined1 *)(param_1 + 0x610) = 1;
    *(undefined4 *)(param_1 + 0x1d0) = 0;
    *(undefined1 *)(param_1 + 0x5e05) = 0;
    if (((ushort)(*(short *)(param_1 + 0x158e) - 0x28cU) < 2) &&
       (*(char *)(param_1 + 0xaad6) != '\0')) {
      (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x50))(param_1,8);
      ArcPrintf(param_1,4,(byte *)"* Switching to INTx mode\n",param_4);
      *(undefined1 *)(param_1 + 0xaad6) = 0;
      *(undefined1 *)(param_1 + 0xaadc) = 0;
      *(undefined4 *)(*(longlong *)(param_1 + 0x630) + 4) = 0;
      ArcPrintf(param_1,4,(byte *)"* Set pInitStruct->NoOfMsiVectors to 0 in AdapterControl\n",
                param_4);
    }
  }
  else {
    if (param_2 == 2) {
      ArcPrintf(param_1,4,(byte *)"* - AdapterControl: ScsiRestartAdapter\n",param_4);
      if (((*(char *)(param_1 + 0x5e05) == '\x01') || (*(char *)(param_1 + 0x610) != '\0')) ||
         (*(char *)(param_1 + 0x615) != '\0')) goto LAB_1c000e50a;
      *(undefined1 *)(param_1 + 0x516c) = 1;
      iVar4 = 40000;
      *(undefined4 *)(param_1 + 0x5170) = 0;
      do {
        StorPortStallExecution(100);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      param_4 = 300;
      pcVar5 = "* Before checking Adapter Health. line #%d\n";
      ArcPrintf(param_1,4,(byte *)"* Before checking Adapter Health. line #%d\n",300);
      puVar3 = local_res10;
      cVar1 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x28))(param_1);
      if ((*(char *)(param_1 + 0x611) == '\0') ||
         (param_4 = (ulonglong)local_res10[0], local_res10[0] == 0)) {
        if (cVar1 < '\0') {
          CheckMSIxPossibility(param_1,puVar3,pcVar5,param_4);
          if (*(char *)(param_1 + 0xaad6) != '\0') {
            *(undefined1 *)(param_1 + 0xaadc) = 1;
          }
          uVar7 = GetElapsedSeconds(param_1,puVar3,pcVar5,param_4);
          cVar1 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 8))(param_1,uVar7);
          *(undefined1 *)(param_1 + 0x516c) = 0;
          if (cVar1 != '\0') {
            *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) | 0x20000000;
            *(undefined4 *)(param_1 + 0x1d0) = 1;
            *(undefined1 *)(param_1 + 0x5e04) = 0;
            *(undefined4 *)(param_1 + 0x648) = 0;
            ArcPrintf(param_1,4,(byte *)"* - AdapterControl: Reset HostRRQIdx to ZERO\n",param_4);
            if (*(longlong *)(param_1 + 0x198) != 0) {
              *(undefined8 *)(param_1 + 0x198) = 0;
              ArcPrintf(param_1,4,
                        (byte *)"* - Reset AIFSrb to NULL when back from power state change\n",
                        param_4);
            }
            if ((*(uint *)(param_1 + 0xbad8) & 8) != 0) {
              *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xfffffff7;
            }
            if ((*(uint *)(param_1 + 0xbad8) & 0x10) != 0) {
              *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xffffffef;
            }
            if ((char)*(uint *)(param_1 + 0xbad8) < '\0') {
              *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xffffff7f;
            }
            *(undefined8 *)(param_1 + 0xbaf8) = 0;
            *(undefined8 *)(param_1 + 0xbae8) = 0;
            *(undefined8 *)(param_1 + 0xbb00) = 0;
            *(undefined4 *)(param_1 + 0xbb08) = 0;
            *(undefined4 *)(param_1 + 0xbaf0) = 0;
            goto LAB_1c000e50a;
          }
          *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 4;
          *(undefined4 *)(param_1 + 0x1d0) = 4;
          *(undefined1 *)(param_1 + 0x619) = 0;
          RequestTimer(param_1,0x2000,500000,2);
          param_4 = 0x186;
          pcVar5 = 
          "* START_ADAPTER failed, start a timer to check FW status, and leaving AdapterControl Routine, line #%d\n"
          ;
        }
        else {
          *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 4;
          *(undefined4 *)(param_1 + 0x1d0) = 4;
          *(undefined1 *)(param_1 + 0x516c) = 0;
          *(undefined1 *)(param_1 + 0x619) = 0;
          RequestTimer(param_1,0x2000,500000,2);
          param_4 = 0x160;
          pcVar5 = 
          "* CHECK_ADAPTER_HEALTH failed, start a timer to check FW status, and leaving AdapterControl Routine, line #%d\n"
          ;
        }
      }
      else {
        uVar2 = 1;
        ArcPrintf(param_1,1,&s____BlinLed_Code___x_,param_4);
        uVar7 = local_res10[0] << 0x10 | 9;
        uVar8 = (ulonglong)uVar7;
        uVar6 = (ulonglong)(uVar7 + 0xe01a0000);
        if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) && (*(char *)(param_1 + 0xaad6) != '\0'))
        {
          ArcLogEventString(param_1,uVar2,uVar7 + 0xe01a0000,uVar7,in_stack_ffffffffffffffc8,0x10);
        }
        *(undefined4 *)(param_1 + 0x1d0) = 4;
        ReturningLocalOutstandingRequestsToOS(param_1);
        cVar1 = IOPReset(param_1,'\0',uVar6,uVar8);
        if (cVar1 == '\0') {
          *(undefined4 *)(param_1 + 0x1d0) = 2;
          pcVar5 = "* leaving AdapterControl Routine, line #%d\n";
          param_4 = 0x152;
        }
        else {
          *(undefined1 *)(param_1 + 0x5e04) = 0;
          *(undefined1 *)(param_1 + 0x516c) = 0;
          *(undefined2 *)(param_1 + 0x618) = 1;
          RequestTimer(param_1,0x20,500000,2);
          ArcPrintf(param_1,4,(byte *)"* set timer to check the FW status for IOP_RESET, line #%d\n"
                    ,0x14c);
          param_4 = 0x14d;
          pcVar5 = "* leaving AdapterControl Routine, line #%d\n";
        }
      }
    }
    else {
      if (param_2 == 3) {
        ArcPrintf(param_1,4,
                  (byte *)
                  "* - AdapterControl: ScsiSetBootConfig. pDeviceExtension->DebugFlags: 0x%x, pDeviceExtension->VMCloseAllSent:%d\n"
                  ,(ulonglong)*(uint *)(param_1 + 0x5e08));
        ArcPrintf(param_1,4,(byte *)"* - AdapterControl: ScsiSetBootConfig. Driver Version: %s\n",
                  0x1c0015d90);
        param_4 = (ulonglong)*(uint *)(param_1 + 57000);
        ArcPrintf(param_1,4,(byte *)"* - AdapterControl: ScsiSetBootConfig. S3S4Counter: %d\n",
                  param_4);
        if ((*(uint *)(param_1 + 0xbad8) >> 0xd & 1) != 0) {
          *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xffffdfff;
        }
        *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) & 0xdfffffff;
        *(undefined1 *)(param_1 + 0x80e1) = 0;
        *(undefined1 *)(param_1 + 0x80e3) = 0;
        *(undefined2 *)(param_1 + 0xe2e4) = 0;
        goto LAB_1c000e50a;
      }
      if (param_2 == 4) {
        *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) & 0xdfffffff;
        param_4 = (ulonglong)*(uint *)(param_1 + 0x5e08);
        ArcPrintf(param_1,4,
                  (byte *)
                  "* - AdapterControl: ScsiSetRunningConfig. pDeviceExtension->DebugFlags: 0x%x, pDeviceExtension->VMCloseAllSent: %d\n"
                  ,param_4);
        *(undefined1 *)(param_1 + 0x610) = *(undefined1 *)(param_1 + 0x616);
        goto LAB_1c000e50a;
      }
      param_4 = (ulonglong)param_2;
      pcVar5 = "\n* Unsupported AdapterControl code received - %x\n";
    }
    ArcPrintf(param_1,4,(byte *)pcVar5,param_4);
  }
LAB_1c000e50a:
  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xfffff7ff;
  ArcPrintf(param_1,0x10000200,(byte *)"leaving AdapterControl\n",param_4);
  return 0;
}



===== BuildIo @ 1c000e540 =====

undefined1 BuildIo(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte bVar2;
  char cVar3;
  ulonglong uVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  byte *pbVar10;
  byte bVar11;
  byte bVar12;
  char *pcVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined8 local_res8;
  
  bVar12 = *(byte *)(param_2 + 5);
  uVar14 = (ulonglong)bVar12;
  bVar11 = *(byte *)(param_2 + 6);
  uVar15 = (ulonglong)bVar11;
  bVar2 = *(byte *)(param_2 + 0x48);
  if ((bVar2 == 0xa0) || (bVar2 == 0x12)) {
    iVar5 = (uint)*(byte *)(param_2 + 2) * 0x100 + -0x10000;
  }
  else {
    iVar5 = (uint)CONCAT11(bVar12,bVar11) * 0x10000 + (uint)*(byte *)(param_2 + 2) * 0x100;
  }
  bVar6 = 0;
  if (*(byte *)(param_1 + 0xdcb8) != 0) {
    do {
      if (iVar5 + (uint)bVar2 == *(int *)(param_1 + 0xdad8 + (ulonglong)bVar6 * 8)) {
        piVar1 = (int *)(param_1 + 0xdadc + (ulonglong)bVar6 * 8);
        *piVar1 = *piVar1 + 1;
        break;
      }
      bVar6 = bVar6 + 1;
    } while (bVar6 < *(byte *)(param_1 + 0xdcb8));
  }
  if ((bVar6 == *(byte *)(param_1 + 0xdcb8)) && (bVar6 < 0x3c)) {
    *(uint *)(param_1 + 0xdad8 + (ulonglong)*(byte *)(param_1 + 0xdcb8) * 8) = iVar5 + (uint)bVar2;
    piVar1 = (int *)(param_1 + 0xdadc + (ulonglong)*(byte *)(param_1 + 0xdcb8) * 8);
    *piVar1 = *piVar1 + 1;
    *(char *)(param_1 + 0xdcb8) = *(char *)(param_1 + 0xdcb8) + '\x01';
  }
  if (((*(char *)(param_2 + 2) == '\0') &&
      ((((bVar2 = *(byte *)(param_2 + 0x48), bVar2 < 0x2b &&
         ((0x50000000500U >> ((ulonglong)bVar2 & 0x3f) & 1) != 0)) || (bVar2 == 0x88)) ||
       (bVar2 == 0x8a)))) && (*(uint *)(param_1 + 0xdea0) < *(uint *)(param_2 + 0x10))) {
    *(uint *)(param_1 + 0xdea0) = *(uint *)(param_2 + 0x10);
  }
  lVar9 = *(longlong *)(param_2 + 0x38);
  uVar4 = lVar9 + 0xfU & 0xfffffffffffffff0;
  *(ulonglong *)(param_2 + 0x38) = uVar4;
  *(longlong *)(uVar4 + 0xa0) = lVar9;
  uVar4 = uVar4 + 0x4f7 & 0xffffffffffffffe0;
  if (((bVar12 == 4) && (*(char *)(param_2 + 2) == '\0')) &&
     (((bVar2 = *(byte *)(param_2 + 0x48), bVar2 < 0x2b &&
       ((0x50000000500U >> ((ulonglong)bVar2 & 0x3f) & 1) != 0)) ||
      ((bVar2 == 0x88 || (bVar2 == 0x8a)))))) {
    if ((*(char *)(param_1 + 0x15a6) != '\0') || ((bVar2 + 0x78 & 0xfd) != 0)) {
      if (*(char *)(param_1 + 0x610) != '\0') {
        return 1;
      }
      if (*(int *)(param_1 + 0x19cc + (ulonglong)*(byte *)(param_2 + 6) * 0x28) == 4) {
        bVar12 = 4;
        *(undefined1 *)(param_2 + 4) = 0x18;
      }
      else {
        if ((*(char *)(param_1 + 0x8084) == '\0') && (*(char *)(param_1 + 0x808d) == '\0')) {
          BuildReadWriteFib(param_1,param_2,uVar4);
        }
        else {
          BuildRawIoFib(param_1,param_2,uVar4);
        }
        bVar12 = *(byte *)(param_2 + 3);
        if ((bVar12 != 0x12) && ((bVar12 & 4) == 0)) {
          return 1;
        }
      }
      goto LAB_1c000ebcb;
    }
    *(undefined4 *)(param_2 + 0x10) = 0;
    if (((*(uint *)(param_2 + 0xc) & 0x20) == 0) && (7 < *(byte *)(param_2 + 0xb))) {
      pbVar10 = *(byte **)(param_2 + 0x20);
      memset(pbVar10,0,(ulonglong)*(byte *)(param_2 + 0xb));
      *pbVar10 = *pbVar10 & 0xf0 | 0x70;
      pbVar10[2] = pbVar10[2] & 0xf5 | 5;
      bVar12 = *(byte *)(param_2 + 0xb);
      if (0xd < bVar12) {
        pbVar10[0xc] = 0x24;
        pbVar10[0xd] = 0;
        bVar11 = 6;
        if (0x11 < bVar12) {
          bVar11 = 10;
        }
        pbVar10[7] = bVar11;
        goto LAB_1c000e709;
      }
      goto LAB_1c000e717;
    }
  }
  else {
    cVar3 = *(char *)(param_2 + 2);
    if (cVar3 == '\0') {
      if (bVar12 != 4) {
        if ((((*(char *)(param_1 + 0x516b) == '\0') &&
             ((uint)*(byte *)(param_2 + 5) <= *(uint *)(param_1 + 0x5174))) && (bVar11 != 0xff)) &&
           ((cVar3 = *(char *)(param_2 + 0x48), cVar3 == '\x12' ||
            ((((cVar3 == -0x60 ||
               (lVar9 = uVar14 * 0xff + uVar15, *(char *)(lVar9 + 0x5210 + param_1) != '\0')) ||
              ((*(char *)(lVar9 + 0x5a08 + param_1) != '\0' ||
               ((*(int *)(param_1 + 0x417c + uVar15 * 0x10) != 0 && (bVar12 == 0)))))) &&
             (((cVar3 == '\x12' || ((cVar3 == -0x60 || (*(char *)(param_1 + 0x517c) != '\0')))) ||
              ((lVar9 = uVar14 * 0xff + param_1, *(char *)(uVar15 + 0x5210 + lVar9) == '\0' &&
               (*(char *)(uVar15 + 0x5a08 + lVar9) != '\x01')))))))))) {
          if (*(char *)(uVar15 + 0x5210 + uVar14 * 0xff + param_1) == '\x01') {
            uVar8 = 1 << (bVar11 & 0x1f);
            uVar7 = *(uint *)(param_1 + 0xaac0 + uVar14 * 4);
            if ((uVar8 & uVar7) != 0) {
              if (cVar3 == '\x03') {
                uVar7 = ~uVar8 & uVar7;
                *(uint *)(param_1 + 0xaac0 + uVar14 * 4) = uVar7;
              }
              if ((uVar7 & uVar8) != 0) {
                return 1;
              }
            }
            if (((*(uint *)(param_2 + 0xc) & 0x20) != 0) && (*(char *)(param_2 + 0x48) == '\x03')) {
              *(uint *)(param_1 + 0xaac0 + uVar14 * 4) = uVar8 | uVar7;
            }
          }
          BuildSrbFib(param_1,param_2,uVar4);
          return 1;
        }
        bVar12 = 10;
        goto LAB_1c000ebcb;
      }
      bVar11 = *(byte *)(param_2 + 0x48);
      if (((bVar11 != 0x12) && (bVar11 != 0xa0)) &&
         (((iVar5 = *(int *)(param_1 + 0x19cc + (ulonglong)*(byte *)(param_2 + 6) * 0x28),
           iVar5 != 1 && (iVar5 != 4)) || (*(char *)(param_2 + 7) != '\0')))) {
        bVar12 = 8;
        goto LAB_1c000ebcb;
      }
      bVar12 = 6;
      if (bVar11 < 0x26) {
        if (bVar11 == 0x25) {
          return 1;
        }
        if (bVar11 != 0) {
          if (bVar11 == 3) {
            return 1;
          }
          if (bVar11 == 0x12) {
            return 1;
          }
          if (0x15 < bVar11) {
            if (bVar11 < 0x18) {
              return 1;
            }
            if (0x19 < bVar11) {
              if (bVar11 < 0x1c) {
                return 1;
              }
              if (bVar11 == 0x1e) goto LAB_1c000e90a;
            }
          }
LAB_1c000e935:
          *(undefined4 *)(param_2 + 0x10) = 0;
          goto LAB_1c000e813;
        }
      }
      else {
        if (bVar11 != 0x2f) {
          if (bVar11 == 0x35) {
            return 1;
          }
          if (bVar11 != 0x8f) {
            if (bVar11 == 0x9e) {
              return 1;
            }
            if (bVar11 == 0xa0) {
              return 1;
            }
            goto LAB_1c000e935;
          }
        }
        uVar7 = 0;
        local_res8 = 0;
        if (bVar11 == 0x2f) {
          local_res8 = (ulonglong)
                       CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                                  *(undefined1 *)(param_2 + 0x4b)),
                                         *(undefined1 *)(param_2 + 0x4c)),
                                *(undefined1 *)(param_2 + 0x4d));
          uVar7 = (uint)CONCAT11(*(undefined1 *)(param_2 + 0x4f),*(undefined1 *)(param_2 + 0x50));
        }
        if (bVar11 == 0x8f) {
          local_res8 = CONCAT17(*(undefined1 *)(param_2 + 0x4a),
                                CONCAT16(*(undefined1 *)(param_2 + 0x4b),
                                         CONCAT15(*(undefined1 *)(param_2 + 0x4c),
                                                  CONCAT14(*(undefined1 *)(param_2 + 0x4d),
                                                           CONCAT13(*(undefined1 *)(param_2 + 0x4e),
                                                                    CONCAT12(*(undefined1 *)
                                                                              (param_2 + 0x4f),
                                                                             CONCAT11(*(undefined1 *
                                                                                       )(param_2 +
                                                                                        0x50),*(
                                                  undefined1 *)(param_2 + 0x51))))))));
          uVar7 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x52),
                                             *(undefined1 *)(param_2 + 0x53)),
                                    *(undefined1 *)(param_2 + 0x54)),*(undefined1 *)(param_2 + 0x55)
                          );
        }
        if (*(ulonglong *)(param_1 + 0x19d8 + (ulonglong)*(byte *)(param_2 + 6) * 0x28) <
            uVar7 + local_res8) {
          uVar7 = *(uint *)(param_2 + 0xc) & 0x20;
          if ((uVar7 == 0) && (7 < *(byte *)(param_2 + 0xb))) {
            pbVar10 = *(byte **)(param_2 + 0x20);
            memset(pbVar10,0,(ulonglong)*(byte *)(param_2 + 0xb));
            *pbVar10 = *pbVar10 & 0xf0 | 0x70;
            pbVar10[2] = pbVar10[2] & 0xf5 | 5;
            bVar11 = *(byte *)(param_2 + 0xb);
            if (0xd < bVar11) {
              pbVar10[0xc] = 0x21;
              pbVar10[0xd] = 0;
              bVar12 = 6;
              if (0x11 < bVar11) {
                bVar12 = 10;
              }
              pbVar10[7] = bVar12;
              ArcPrintf(param_1,1,(byte *)"* buildio: LBA OUT OF RANGE, sense data sent\n",
                        local_res8);
              bVar12 = 0x84;
              *(undefined2 *)(param_2 + 3) = 0x284;
              goto LAB_1c000ebcb;
            }
            ArcPrintf(param_1,1,
                      (byte *)
                      "* buildio: LBA OUT OF RANGE, sense data NOT sent because autosense buffer is not big enough\n"
                      ,local_res8);
            pbVar10[7] = 0;
          }
          else {
            pcVar13 = 
            "* buildio: LBA OUT OF RANGE, sense data NOT sent because autosense is disabled\n";
            if (uVar7 == 0) {
              pcVar13 = 
              "* buildio: LBA OUT OF RANGE, sense data NOT sent because additional Sense buffer not available\n"
              ;
            }
            ArcPrintf(param_1,1,(byte *)pcVar13,local_res8);
          }
          *(undefined2 *)(param_2 + 3) = 6;
          goto LAB_1c000ebcb;
        }
      }
LAB_1c000e90a:
      bVar12 = 1;
      goto LAB_1c000ebcb;
    }
    if (cVar3 == '\x02') {
      return 1;
    }
    if (cVar3 == '\b') goto LAB_1c000e90a;
    if (cVar3 == '\x10') {
      bVar12 = 3;
      goto LAB_1c000ebcb;
    }
    if (cVar3 == '\x12') {
      return 1;
    }
    if (cVar3 == '\x13') {
      return 1;
    }
    if (cVar3 == '\x17') {
      return 1;
    }
    if (cVar3 == ' ') {
      return 1;
    }
    if (cVar3 == '$') {
      return 1;
    }
    *(undefined4 *)(param_2 + 0x10) = 0;
    if ((cVar3 == '\a') && (DAT_1c001d952 == '\0')) {
      DAT_1c001d952 = '\x01';
    }
LAB_1c000e813:
    if (((*(uint *)(param_2 + 0xc) & 0x20) == 0) && (7 < *(byte *)(param_2 + 0xb))) {
      pbVar10 = *(byte **)(param_2 + 0x20);
      memset(pbVar10,0,(ulonglong)*(byte *)(param_2 + 0xb));
      *pbVar10 = *pbVar10 & 0xf0 | 0x70;
      pbVar10[2] = pbVar10[2] & 0xf5 | 5;
      if (0xd < *(byte *)(param_2 + 0xb)) {
        bVar12 = 6;
        if (0x11 < *(byte *)(param_2 + 0xb)) {
          bVar12 = 10;
        }
        pbVar10[7] = bVar12;
        pbVar10[0xc] = 0x20;
        pbVar10[0xd] = 0;
LAB_1c000e709:
        bVar12 = 0x84;
        *(undefined1 *)(param_2 + 4) = 2;
        goto LAB_1c000ebcb;
      }
LAB_1c000e717:
      pbVar10[7] = 0;
    }
  }
  bVar12 = 6;
  *(undefined1 *)(param_2 + 4) = 0;
LAB_1c000ebcb:
  *(byte *)(param_2 + 3) = bVar12;
  *(undefined8 *)(param_2 + 0x38) = *(undefined8 *)(*(longlong *)(param_2 + 0x38) + 0xa0);
  StorPortNotification(0,param_1,param_2);
  return 0;
}



===== BuildRawIoFib @ 1c000ec0c =====

void BuildRawIoFib(longlong param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  int iVar2;
  undefined1 *_Dst;
  undefined4 *_Dst_00;
  byte *_Dst_01;
  byte bVar3;
  short sVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 *puVar9;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  
  _Dst = *(undefined1 **)(param_2 + 0x38);
  local_res10 = 0;
  local_res8[0] = 0;
  memset(_Dst,0,0xa0);
  *(longlong *)(_Dst + 0x40) = param_1;
  puVar9 = local_res8;
  *(longlong *)(_Dst + 0x20) = param_1 + 0x658;
  *(longlong *)(_Dst + 0x28) = param_3;
  *(longlong *)(_Dst + 0x18) = param_2;
  *_Dst = 0;
  *(undefined8 *)(_Dst + 0x58) = 0;
  uVar5 = StorPortGetPhysicalAddress(param_1,0,param_3);
  _Dst_00 = *(undefined4 **)(_Dst + 0x28);
  *(undefined8 *)(_Dst + 0x10) = uVar5;
  *(undefined4 *)(_Dst + 0x78) = 1;
  memset(_Dst_00,0,0x20);
  *(undefined1 *)((longlong)_Dst_00 + 6) = 1;
  _Dst_00[2] = 0x2000200;
  *_Dst_00 = 0x8000d;
  *(undefined2 *)(param_3 + 10) = *(undefined2 *)(param_1 + 0x8068);
  if ((*(char *)(param_2 + 0x48) + 0x78U & 0xfd) == 0) {
    local_res10._0_4_ =
         CONCAT13(*(undefined1 *)(param_2 + 0x4e),
                  CONCAT12(*(undefined1 *)(param_2 + 0x4f),
                           CONCAT11(*(undefined1 *)(param_2 + 0x50),*(undefined1 *)(param_2 + 0x51))
                          ));
    local_res10 = CONCAT17(*(undefined1 *)(param_2 + 0x4a),
                           CONCAT16(*(undefined1 *)(param_2 + 0x4b),
                                    CONCAT15(*(undefined1 *)(param_2 + 0x4c),
                                             CONCAT14(*(undefined1 *)(param_2 + 0x4d),
                                                      (undefined4)local_res10))));
  }
  else {
    if ((*(char *)(param_2 + 0x48) - 0x28U & 0xfd) == 0) {
      uVar7 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                      *(undefined1 *)(param_2 + 0x4b)),
                             *(undefined1 *)(param_2 + 0x4c));
      bVar1 = *(byte *)(param_2 + 0x4d);
    }
    else {
      uVar7 = (*(byte *)(param_2 + 0x49) & 0x1f) << 8 | (uint)*(byte *)(param_2 + 0x4a);
      bVar1 = *(byte *)(param_2 + 0x4b);
    }
    local_res10 = (ulonglong)(uVar7 << 8) | (ulonglong)bVar1;
  }
  *(ulonglong *)(_Dst + 0x80) = local_res10;
  uVar6 = (ulonglong)*(uint *)(param_2 + 0x10) /
          (ulonglong)*(uint *)(param_1 + 0x19e8 + (ulonglong)*(byte *)(param_2 + 6) * 0x28) +
          local_res10;
  *(ulonglong *)(_Dst + 0x88) = uVar6;
  if (*(ulonglong *)(param_1 + 0x19d8 + (ulonglong)*(byte *)(param_2 + 6) * 0x28) < uVar6) {
    uVar7 = *(uint *)(param_2 + 0xc) & 0x20;
    if ((uVar7 == 0) && (7 < *(byte *)(param_2 + 0xb))) {
      _Dst_01 = *(byte **)(param_2 + 0x20);
      memset(_Dst_01,0,(ulonglong)*(byte *)(param_2 + 0xb));
      *_Dst_01 = *_Dst_01 & 0xf0 | 0x70;
      _Dst_01[2] = _Dst_01[2] & 0xf5 | 5;
      bVar1 = *(byte *)(param_2 + 0xb);
      if (0xd < bVar1) {
        _Dst_01[0xc] = 0x21;
        _Dst_01[0xd] = 0;
        bVar3 = 6;
        if (0x11 < bVar1) {
          bVar3 = 10;
        }
        _Dst_01[7] = bVar3;
        ArcPrintf(param_1,1,(byte *)"* buildio: LBA OUT OF RANGE, sense data sent\n",
                  (ulonglong)puVar9);
        *(undefined2 *)(param_2 + 3) = 0x284;
        return;
      }
      ArcPrintf(param_1,1,
                (byte *)
                "* buildio: LBA OUT OF RANGE, sense data NOT sent because autosense buffer is not big enough\n"
                ,(ulonglong)puVar9);
      _Dst_01[7] = 0;
    }
    else {
      pcVar8 = "* buildio: LBA OUT OF RANGE, sense data NOT sent because autosense is disabled\n";
      if (uVar7 == 0) {
        pcVar8 = 
        "* buildio: LBA OUT OF RANGE, sense data NOT sent because additional Sense buffer not available\n"
        ;
      }
      ArcPrintf(param_1,1,(byte *)pcVar8,(ulonglong)puVar9);
    }
    *(undefined2 *)(param_2 + 3) = 6;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x8088);
    *(undefined4 *)(param_3 + 0x20) = (undefined4)local_res10;
    *(int *)(param_3 + 0x24) = (int)(local_res10 >> 0x20);
    *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)(param_2 + 0x10);
    *(undefined2 *)(param_3 + 0x2c) =
         *(undefined2 *)(param_1 + 0x19e4 + (ulonglong)*(byte *)(param_2 + 6) * 0x28);
    if (iVar2 == 2) {
      if ((*(uint *)(param_2 + 0xc) & 0x40) == 0) {
        *(undefined2 *)(param_3 + 0x2e) = 0;
      }
      else {
        *(undefined2 *)(param_3 + 0x2e) = 1;
      }
      BuildRawIo2ScatterGather(param_1,param_2,param_3 + 0x20);
      sVar4 = (*(byte *)(param_3 + 0x38) + 2) * 0x10;
    }
    else {
      if ((*(uint *)(param_2 + 0xc) & 0x40) == 0) {
        *(undefined2 *)(param_3 + 0x2e) = 0;
      }
      else {
        *(undefined2 *)(param_3 + 0x2e) = 1;
      }
      BuildRawIoScatterGather(param_1,param_2,param_3 + 0x20);
      sVar4 = ((short)*(undefined4 *)(param_3 + 0x34) + 1) * 0x18;
    }
    *(short *)(param_3 + 8) = sVar4 + 0x20;
    *(undefined4 *)(_Dst + 0x70) = 1;
  }
  return;
}



===== BuildRawIoScatterGather @ 1c000eee0 =====

void BuildRawIoScatterGather(longlong param_1,longlong param_2,longlong param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  
  uVar5 = *(uint *)(param_2 + 0x10);
  uVar6 = 0;
  uVar8 = 0;
  lVar3 = StorPortGetScatterGatherList();
  if (*(char *)(param_1 + 0x808d) == '\0') {
    do {
      if (uVar5 == 0) goto LAB_1c000f05d;
      *(undefined4 *)(param_3 + 0x20 + uVar6 * 0x18) = *(undefined4 *)(lVar3 + 0x10 + uVar6 * 0x18);
      *(undefined4 *)(param_3 + 0x24 + uVar6 * 0x18) = *(undefined4 *)(lVar3 + 0x14 + uVar6 * 0x18);
      uVar9 = *(uint *)(lVar3 + 0x18 + uVar6 * 0x18);
      if (uVar5 < uVar9) {
        *(uint *)(param_3 + 0x28 + uVar6 * 0x18) = uVar5;
      }
      else {
        *(uint *)(param_3 + 0x28 + uVar6 * 0x18) = uVar9;
      }
      uVar5 = uVar5 - *(int *)(param_3 + 0x28 + uVar6 * 0x18);
      uVar9 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar9;
      uVar8 = (ulonglong)uVar9;
    } while (uVar9 <= *(uint *)(param_1 + 0x806c));
  }
  else {
    *(ushort *)(param_3 + 0xe) = *(ushort *)(param_3 + 0xe) | 0x1000;
    do {
      if (uVar5 == 0) goto LAB_1c000f05d;
      lVar11 = param_3 + (uVar8 + 2) * 0xc;
      *(undefined4 *)(lVar11 + 0xc) = *(undefined4 *)(lVar3 + 0x10 + uVar6 * 0x18);
      *(undefined4 *)(lVar11 + 0x10) = *(undefined4 *)(lVar3 + 0x14 + uVar6 * 0x18);
      uVar9 = *(uint *)(lVar3 + 0x18 + uVar6 * 0x18);
      while( true ) {
        uVar4 = *(uint *)(lVar11 + 0xc);
        uVar10 = (uVar4 / *(uint *)(param_1 + 0x8094) + 1) * *(uint *)(param_1 + 0x8094);
        if (uVar4 + uVar9 <= uVar10) break;
        uVar4 = uVar10 - uVar4;
        if (uVar5 < uVar4) {
          *(uint *)(param_3 + 0x20 + uVar8 * 0xc) = uVar5;
          uVar5 = 0;
          goto LAB_1c000efe4;
        }
        *(uint *)(lVar11 + 8) = uVar4;
        uVar7 = (int)uVar8 + 1;
        uVar5 = uVar5 - uVar4;
        uVar9 = uVar9 - uVar4;
        uVar2 = *(undefined4 *)(param_3 + 0x28 + uVar8 * 0xc);
        lVar11 = param_3 + ((ulonglong)uVar7 + 2) * 0xc;
        *(uint *)(lVar11 + 0xc) = uVar10;
        *(undefined4 *)(lVar11 + 0x10) = uVar2;
        uVar8 = (ulonglong)uVar7;
      }
      puVar1 = (uint *)(param_3 + uVar8 * 0xc + 0x20);
      if (uVar5 < uVar9) {
        *puVar1 = uVar5;
      }
      else {
        *puVar1 = uVar9;
      }
      uVar5 = uVar5 - *puVar1;
LAB_1c000efe4:
      uVar4 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar4;
      uVar9 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar9;
      if (*(uint *)(param_1 + 0xdea4) < uVar9) {
        *(uint *)(param_1 + 0xdea4) = uVar9;
      }
    } while ((uVar9 <= *(uint *)(param_1 + 0x8070)) && (uVar4 <= *(uint *)(param_1 + 0x8070)));
  }
  *(undefined1 *)(param_2 + 3) = 4;
LAB_1c000f05d:
  *(int *)(param_3 + 0x14) = (int)uVar8;
  return;
}



===== BuildRawIo2ScatterGather @ 1c000f080 =====

void BuildRawIo2ScatterGather(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  bool bVar7;
  longlong lVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  ulonglong uVar15;
  int iVar16;
  ulonglong uVar17;
  uint uVar18;
  
  uVar18 = *(uint *)(param_2 + 0x10);
  uVar17 = 0;
  uVar10 = 0;
  uVar11 = 0;
  bVar7 = true;
  lVar8 = StorPortGetScatterGatherList();
  do {
    if (uVar18 == 0) goto LAB_1c000f156;
    iVar12 = (int)uVar17;
    *(undefined4 *)(param_3 + (uVar17 + 2) * 0x10) = *(undefined4 *)(lVar8 + 0x10 + uVar17 * 0x18);
    *(undefined4 *)(param_3 + 0x24 + uVar17 * 0x10) = *(undefined4 *)(lVar8 + 0x14 + uVar17 * 0x18);
    uVar13 = *(uint *)(lVar8 + 0x18 + uVar17 * 0x18);
    *(undefined4 *)(param_3 + 0x2c + uVar17 * 0x10) = 0;
    if (uVar18 < uVar13) {
      uVar13 = uVar18;
    }
    *(uint *)(param_3 + 0x28 + uVar17 * 0x10) = uVar13;
    if (iVar12 == 0) {
      bVar7 = true;
      *(uint *)(param_3 + 0x10) = uVar13;
      *(undefined4 *)(param_3 + 0x14) = 0;
    }
    else if (iVar12 == 1) {
      *(uint *)(param_3 + 0x14) = uVar13;
      uVar11 = uVar13;
    }
    else if (((uVar13 < uVar18) && (uVar13 != *(uint *)(param_3 + 0x14))) &&
            (bVar7 = false, uVar13 < uVar11)) {
      uVar11 = uVar13;
    }
    uVar10 = iVar12 + 1;
    uVar17 = (ulonglong)uVar10;
    uVar18 = uVar18 - uVar13;
    if (*(uint *)(param_1 + 0xdea4) < uVar10) {
      *(uint *)(param_1 + 0xdea4) = uVar10;
    }
  } while (uVar10 <= *(uint *)(param_1 + 0x806c));
  *(undefined1 *)(param_2 + 3) = 4;
LAB_1c000f156:
  uVar3 = *(ushort *)(param_3 + 0xe);
  *(char *)(param_3 + 0x18) = (char)uVar10;
  *(ushort *)(param_3 + 0xe) = uVar3 | 0x2000;
  if (bVar7) {
    *(ushort *)(param_3 + 0xe) = uVar3 | 0x2010;
  }
  else {
    uVar11 = uVar11 >> 0xc;
    uVar18 = 0;
    iVar12 = (int)uVar17;
    if (uVar11 != 0) {
      uVar10 = uVar11 << 0xc;
      while( true ) {
        uVar18 = 2;
        uVar13 = 1;
        if (iVar12 - 1U < 2) break;
        puVar14 = (uint *)(param_3 + 0x38);
        while (*puVar14 % uVar10 == 0) {
          uVar18 = uVar18 + *puVar14 / uVar10;
          uVar13 = uVar13 + 1;
          puVar14 = puVar14 + 4;
          if (iVar12 - 1U <= uVar13) goto LAB_1c000f1c7;
        }
        uVar11 = uVar11 - 1;
        uVar10 = uVar10 - 0x1000;
        if (uVar11 == 0) break;
      }
    }
LAB_1c000f1c7:
    if (((uVar11 != 0) && (uVar18 <= *(uint *)(param_1 + 0x806c))) &&
       (lVar8 = *(longlong *)(param_2 + 0x38), *(char *)(param_1 + 0xa926) != '\0')) {
      uVar17 = 1;
      if (1 < iVar12 - 1U) {
        puVar14 = (uint *)(param_3 + 0x38);
        uVar10 = uVar11 * 0x1000;
        uVar15 = (ulonglong)(iVar12 - 2);
        do {
          uVar13 = 0;
          if (*puVar14 / uVar10 != 0) {
            iVar16 = 0;
            do {
              uVar4 = puVar14[-2];
              *(uint *)(lVar8 + 0xa8 + uVar17 * 0x10) = uVar4 + iVar16;
              uVar5 = puVar14[-1];
              *(uint *)(lVar8 + 0xac + uVar17 * 0x10) = uVar5;
              if (uVar4 + iVar16 < puVar14[-2]) {
                *(uint *)(lVar8 + 0xac + uVar17 * 0x10) = uVar5 + 1;
              }
              *(undefined4 *)(lVar8 + 0xb4 + uVar17 * 0x10) = 0;
              uVar13 = uVar13 + 1;
              lVar9 = uVar17 + 0xb;
              uVar17 = (ulonglong)((int)uVar17 + 1);
              iVar16 = iVar16 + uVar10;
              *(uint *)(lVar8 + lVar9 * 0x10) = uVar10;
            } while (uVar13 < *puVar14 / uVar10);
          }
          puVar14 = puVar14 + 4;
          uVar15 = uVar15 - 1;
        } while (uVar15 != 0);
      }
      puVar1 = (undefined8 *)(param_3 + ((ulonglong)(iVar12 - 1U) + 2) * 0x10);
      uVar6 = puVar1[1];
      puVar2 = (undefined8 *)(lVar8 + 0xa8 + uVar17 * 0x10);
      *puVar2 = *puVar1;
      puVar2[1] = uVar6;
      memcpy((void *)(param_3 + 0x30),(void *)(lVar8 + 0xb8),(ulonglong)(uVar18 - 1) << 4);
      *(ushort *)(param_3 + 0xe) = *(ushort *)(param_3 + 0xe) | 0x10;
      *(uint *)(param_3 + 0x14) = uVar11 << 0xc;
      *(char *)(param_3 + 0x18) = (char)uVar18;
    }
  }
  return;
}



===== BuildReadWriteFib @ 1c000f2f0 =====

void BuildReadWriteFib(longlong param_1,longlong param_2,longlong param_3)

{
  undefined1 *_Dst;
  longlong lVar1;
  short sVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  undefined2 local_res8;
  undefined4 local_res10 [4];
  undefined8 local_res20;
  
  _Dst = *(undefined1 **)(param_2 + 0x38);
  local_res20 = 0;
  local_res10[0] = 0;
  memset(_Dst,0,0xa0);
  if (*(char *)(param_1 + 0x610) == '\0') {
    *(longlong *)(_Dst + 0x40) = param_1;
    *(longlong *)(_Dst + 0x20) = param_1 + 0x658;
    *(longlong *)(_Dst + 0x28) = param_3;
    *(longlong *)(_Dst + 0x18) = param_2;
    *_Dst = 0;
    *(undefined8 *)(_Dst + 0x58) = 0;
    uVar3 = StorPortGetPhysicalAddress(param_1,0,param_3,local_res10);
    *(undefined4 *)(_Dst + 0x78) = 1;
    *(undefined8 *)(_Dst + 0x10) = uVar3;
    puVar5 = *(undefined4 **)(_Dst + 0x28);
    memset(puVar5,0,0x20);
    *(undefined1 *)((longlong)puVar5 + 6) = 1;
    puVar5[2] = 0x2000200;
    *puVar5 = 0x8000d;
  }
  if ((*(char *)(param_2 + 0x48) + 0x78U & 0xfd) == 0) {
    local_res20._0_4_ =
         CONCAT13(*(undefined1 *)(param_2 + 0x4e),
                  CONCAT12(*(undefined1 *)(param_2 + 0x4f),
                           CONCAT11(*(undefined1 *)(param_2 + 0x50),*(undefined1 *)(param_2 + 0x51))
                          ));
    local_res20 = CONCAT17(*(undefined1 *)(param_2 + 0x4a),
                           CONCAT16(*(undefined1 *)(param_2 + 0x4b),
                                    CONCAT15(*(undefined1 *)(param_2 + 0x4c),
                                             CONCAT14(*(undefined1 *)(param_2 + 0x4d),
                                                      (undefined4)local_res20))));
    local_res8 = CONCAT11(*(undefined1 *)(param_2 + 0x54),*(undefined1 *)(param_2 + 0x55));
  }
  else if ((*(char *)(param_2 + 0x48) - 0x28U & 0xfd) == 0) {
    local_res20 = (ulonglong)
                  CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                             *(undefined1 *)(param_2 + 0x4b)),
                                    *(undefined1 *)(param_2 + 0x4c)),*(undefined1 *)(param_2 + 0x4d)
                          );
    local_res8 = CONCAT11(*(undefined1 *)(param_2 + 0x4f),*(undefined1 *)(param_2 + 0x50));
  }
  else {
    local_res8 = (ushort)*(byte *)(param_2 + 0x4c);
    local_res20 = (ulonglong)
                  (((*(byte *)(param_2 + 0x49) & 0x1f) << 8 | (uint)*(byte *)(param_2 + 0x4a)) << 8)
                  | (ulonglong)*(byte *)(param_2 + 0x4b);
  }
  uVar4 = (ulonglong)*(byte *)(param_2 + 6);
  lVar1 = uVar4 * 5;
  if (*(ulonglong *)(param_1 + 0x19d8 + uVar4 * 0x28) <
      (ulonglong)*(uint *)(param_2 + 0x10) / (ulonglong)*(uint *)(param_1 + 0x19e8 + uVar4 * 0x28) +
      local_res20) {
    *(undefined1 *)(param_2 + 3) = 0x12;
  }
  else {
    puVar5 = (undefined4 *)(param_1 + 0x15a8);
    if (*(char *)(param_1 + 0x15a5) == '\0') {
      if ((*(uint *)(param_2 + 0xc) & 0x40) == 0) {
        if (*(char *)(param_1 + 0x610) == '\0') {
          puVar5 = (undefined4 *)(param_3 + 0x20);
        }
        *puVar5 = 7;
        puVar5[1] = *(undefined4 *)(param_1 + 0x19e4 + (ulonglong)*(byte *)(param_2 + 6) * 0x28);
        puVar5[2] = (undefined4)local_res20;
        puVar5[3] = *(undefined4 *)(param_2 + 0x10);
        BuildScatterGather(param_1,param_2,lVar1,puVar5 + 5);
        sVar2 = (short)puVar5[5] * 8 + 0x18;
      }
      else {
        if (*(char *)(param_1 + 0x610) == '\0') {
          puVar5 = (undefined4 *)(param_3 + 0x20);
        }
        *puVar5 = 6;
        puVar5[1] = *(undefined4 *)(param_1 + 0x19e4 + (ulonglong)*(byte *)(param_2 + 6) * 0x28);
        puVar5[2] = (undefined4)local_res20;
        puVar5[3] = *(undefined4 *)(param_2 + 0x10);
        BuildScatterGather(param_1,param_2,lVar1,puVar5 + 4);
        sVar2 = (short)puVar5[4] * 8 + 0x14;
      }
    }
    else {
      if ((*(uint *)(param_2 + 0xc) & 0x40) == 0) {
        if (*(char *)(param_1 + 0x610) == '\0') {
          puVar5 = (undefined4 *)(param_3 + 0x20);
        }
        *puVar5 = 0x14;
      }
      else {
        if (*(char *)(param_1 + 0x610) == '\0') {
          puVar5 = (undefined4 *)(param_3 + 0x20);
        }
        *puVar5 = 0x13;
      }
      *(undefined2 *)(puVar5 + 1) =
           *(undefined2 *)(param_1 + 0x19e4 + (ulonglong)*(byte *)(param_2 + 6) * 0x28);
      *(ushort *)((longlong)puVar5 + 6) = local_res8;
      puVar5[2] = (undefined4)local_res20;
      *(short *)(puVar5 + 3) = (short)(local_res20 >> 0x20);
      *(undefined2 *)((longlong)puVar5 + 0xe) = 0;
      BuildScatterGather64(param_1,param_2,lVar1,(ushort *)(puVar5 + 4));
      sVar2 = (*(short *)(puVar5 + 4) + -1) * 0xc + 0x20;
    }
    if (*(char *)(param_1 + 0x610) == '\0') {
      *(short *)(param_3 + 8) = sVar2 + 0x20;
    }
    else {
      *(short *)(param_1 + 0x19a8) = sVar2;
    }
  }
  return;
}



===== BuildScatterGather @ 1c000f5dc =====

void BuildScatterGather(longlong param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_2 + 0x10);
  uVar3 = 0;
  lVar1 = StorPortGetScatterGatherList();
  do {
    if (uVar4 == 0) goto LAB_1c000f655;
    param_4[uVar3 * 2 + 1] = *(undefined4 *)(lVar1 + 0x10 + uVar3 * 0x18);
    uVar2 = *(uint *)(lVar1 + 0x18 + uVar3 * 0x18);
    if (uVar4 < uVar2) {
      param_4[uVar3 * 2 + 2] = uVar4;
    }
    else {
      param_4[uVar3 * 2 + 2] = uVar2;
    }
    uVar4 = uVar4 - param_4[uVar3 * 2 + 2];
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulonglong)uVar2;
    if (*(uint *)(param_1 + 0xdea4) < uVar2) {
      *(uint *)(param_1 + 0xdea4) = uVar2;
    }
  } while (uVar2 <= *(uint *)(param_1 + 0x806c));
  *(undefined1 *)(param_2 + 3) = 4;
LAB_1c000f655:
  *param_4 = (int)uVar3;
  return;
}



===== BuildScatterGather64 @ 1c000f674 =====

void BuildScatterGather64(longlong param_1,longlong param_2,undefined8 param_3,ushort *param_4)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_2 + 0x10);
  uVar3 = 0;
  lVar1 = StorPortGetScatterGatherList();
  do {
    if (uVar4 == 0) goto LAB_1c000f6ff;
    *(undefined4 *)(param_4 + uVar3 * 6 + 2) = *(undefined4 *)(lVar1 + 0x10 + uVar3 * 0x18);
    *(undefined4 *)(param_4 + uVar3 * 6 + 4) = *(undefined4 *)(lVar1 + 0x14 + uVar3 * 0x18);
    uVar2 = *(uint *)(lVar1 + 0x18 + uVar3 * 0x18);
    if (uVar4 < uVar2) {
      *(uint *)(param_4 + uVar3 * 6 + 6) = uVar4;
    }
    else {
      *(uint *)(param_4 + uVar3 * 6 + 6) = uVar2;
    }
    uVar4 = uVar4 - *(int *)(param_4 + uVar3 * 6 + 6);
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulonglong)uVar2;
    if (*(uint *)(param_1 + 0xdea4) < uVar2) {
      *(uint *)(param_1 + 0xdea4) = uVar2;
    }
  } while (uVar2 <= *(uint *)(param_1 + 0x806c));
  *(undefined1 *)(param_2 + 3) = 4;
LAB_1c000f6ff:
  *param_4 = (ushort)uVar3 & 0xff;
  return;
}



===== BuildSrbFib @ 1c000f720 =====

void BuildSrbFib(longlong param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined1 *_Dst;
  undefined4 *_Dst_00;
  short sVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 local_res8 [8];
  undefined8 local_res10;
  
  _Dst = *(undefined1 **)(param_2 + 0x38);
  local_res10 = 0;
  memset(_Dst,0,0xa0);
  *(undefined4 *)(_Dst + 0x70) = 0;
  *(undefined8 *)(_Dst + 0x58) = 0;
  *(longlong *)(_Dst + 0x20) = param_1 + 0x658;
  *(longlong *)(_Dst + 0x40) = param_1;
  *(longlong *)(_Dst + 0x28) = param_3;
  *(longlong *)(_Dst + 0x18) = param_2;
  *_Dst = 0;
  uVar5 = StorPortGetPhysicalAddress(param_1,0,param_3,local_res8);
  _Dst_00 = *(undefined4 **)(_Dst + 0x28);
  *(undefined8 *)(_Dst + 0x10) = uVar5;
  *(undefined4 *)(_Dst + 0x78) = 1;
  memset(_Dst_00,0,0x20);
  *(undefined1 *)((longlong)_Dst_00 + 6) = 1;
  _Dst_00[2] = 0x2000200;
  *_Dst_00 = 0x8000d;
  *(undefined2 *)(param_3 + 10) = *(undefined2 *)(param_1 + 0x8068);
  if (((*(char *)(param_2 + 5) == '\0') &&
      (*(int *)(param_1 + 0x417c + (ulonglong)*(byte *)(param_2 + 6) * 0x10) != 0)) &&
     ((cVar1 = *(char *)(param_2 + 0x48), cVar1 == -0x78 ||
      (((cVar1 == -0x76 || (cVar1 == '(')) || (cVar1 == '*')))))) {
    if ((cVar1 + 0x78U & 0xfd) == 0) {
      local_res10 = CONCAT17(*(undefined1 *)(param_2 + 0x4a),
                             CONCAT16(*(undefined1 *)(param_2 + 0x4b),
                                      CONCAT15(*(undefined1 *)(param_2 + 0x4c),
                                               CONCAT14(*(undefined1 *)(param_2 + 0x4d),
                                                        CONCAT13(*(undefined1 *)(param_2 + 0x4e),
                                                                 CONCAT12(*(undefined1 *)
                                                                           (param_2 + 0x4f),
                                                                          CONCAT11(*(undefined1 *)
                                                                                    (param_2 + 0x50)
                                                                                   ,*(undefined1 *)
                                                                                     (param_2 + 0x51
                                                                                     ))))))));
      uVar7 = local_res10;
    }
    else {
      if ((cVar1 - 0x28U & 0xfd) == 0) {
        uVar6 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0x4a),
                                        *(undefined1 *)(param_2 + 0x4b)),
                               *(undefined1 *)(param_2 + 0x4c));
        bVar2 = *(byte *)(param_2 + 0x4d);
      }
      else {
        uVar6 = (*(byte *)(param_2 + 0x49) & 0x1f) << 8 | (uint)*(byte *)(param_2 + 0x4a);
        bVar2 = *(byte *)(param_2 + 0x4b);
      }
      uVar7 = (ulonglong)(uVar6 << 8) | (ulonglong)bVar2;
    }
    *(ulonglong *)(_Dst + 0x80) = uVar7;
    uVar6 = *(uint *)(param_2 + 0x10);
    *(undefined4 *)(_Dst + 0x70) = 2;
    *(ulonglong *)(_Dst + 0x88) = (uVar6 >> 9) + uVar7;
  }
  *(uint *)(param_3 + 0x20) = (uint)*(byte *)(param_2 + 2);
  *(uint *)(param_3 + 0x24) = (uint)*(byte *)(param_2 + 5);
  *(uint *)(param_3 + 0x28) = (uint)*(byte *)(param_2 + 6);
  *(uint *)(param_3 + 0x2c) = (uint)*(byte *)(param_2 + 7);
  *(undefined4 *)(param_3 + 0x30) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(param_3 + 0x34) = *(undefined4 *)(param_2 + 0xc);
  uVar3 = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_3 + 0x3c) = 0;
  *(undefined4 *)(param_3 + 0x38) = uVar3;
  *(uint *)(param_3 + 0x40) = (uint)*(byte *)(param_2 + 10);
  uVar7 = (ulonglong)*(byte *)(param_2 + 10);
  memcpy((void *)(param_3 + 0x44),(void *)(param_2 + 0x48),uVar7);
  if (*(int *)(param_3 + 0x38) == 0) {
    *(undefined4 *)(param_3 + 0x54) = 0;
    sVar4 = 0x60;
  }
  else {
    if (*(char *)(param_1 + 0x15a5) != '\0') {
      BuildScatterGather64(param_1,param_2,uVar7,(ushort *)(param_3 + 0x54));
      *(short *)(param_3 + 8) = (*(short *)(param_3 + 0x54) + -1) * 0xc + 100;
      return;
    }
    BuildScatterGather(param_1,param_2,uVar7,(undefined4 *)(param_3 + 0x54));
    sVar4 = (*(short *)(param_3 + 0x54) + 0xb) * 8;
  }
  *(short *)(param_3 + 8) = sVar4;
  return;
}



===== ProcessIoctl @ 1c000f960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ProcessIoctl(longlong param_1,ushort *param_2,undefined4 *param_3,ulonglong param_4)

{
  longlong *plVar1;
  ushort uVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  char cVar8;
  char cVar9;
  short sVar10;
  ushort uVar11;
  undefined4 uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  undefined7 extraout_var;
  int *piVar15;
  int iVar16;
  byte bVar17;
  short *_Src;
  uint *puVar18;
  longlong lVar19;
  ushort *_Src_00;
  undefined1 *_Dst;
  undefined4 *puVar20;
  uint *puVar21;
  int *piVar22;
  undefined8 uVar23;
  char *pcVar24;
  uint uVar25;
  uint uVar26;
  ushort *puVar27;
  uint uVar28;
  ulonglong uVar29;
  void *_Src_01;
  bool bVar30;
  undefined1 auStackY_218 [32];
  undefined8 in_stack_fffffffffffffe08;
  undefined1 *local_1a0;
  undefined4 *local_198;
  ushort *local_190;
  uint local_188;
  ushort *local_180;
  uint *local_178;
  undefined4 local_170;
  int local_16c;
  uint *local_168;
  ushort *local_160;
  ushort *local_158;
  byte local_150 [8];
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  char local_128 [52];
  int local_f4;
  undefined4 local_f0;
  uint local_ec;
  uint local_e8;
  uint local_e4 [4];
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 local_c8;
  undefined1 local_c7;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 local_b0;
  undefined1 local_af;
  undefined1 local_ae;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  uint local_a0;
  undefined1 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_218;
  puVar21 = *(uint **)(param_2 + 0xc);
  uVar29 = 0;
  _Dst = *(undefined1 **)(param_2 + 0x1c);
  uVar13 = 1;
  local_170 = 0;
  iVar16 = ((uint)*(byte *)((longlong)param_2 + 5) * 0x10 + (uint)(byte)param_2[3]) * 0x1000000 +
           puVar21[4];
  bVar17 = 0;
  if (*(byte *)(param_1 + 0xde9c) != 0) {
    do {
      if (iVar16 == *(int *)(param_1 + 0xdcbc + (ulonglong)bVar17 * 8)) {
        piVar15 = (int *)(param_1 + 0xdcc0 + (ulonglong)bVar17 * 8);
        *piVar15 = *piVar15 + 1;
        break;
      }
      bVar17 = bVar17 + 1;
    } while (bVar17 < *(byte *)(param_1 + 0xde9c));
  }
  if ((bVar17 == *(byte *)(param_1 + 0xde9c)) && (bVar17 < 0x3c)) {
    *(int *)(param_1 + 0xdcbc + (ulonglong)*(byte *)(param_1 + 0xde9c) * 8) = iVar16;
    piVar15 = (int *)(param_1 + 0xdcc0 + (ulonglong)*(byte *)(param_1 + 0xde9c) * 8);
    *piVar15 = *piVar15 + 1;
    *(char *)(param_1 + 0xde9c) = *(char *)(param_1 + 0xde9c) + '\x01';
  }
  uVar25 = puVar21[4];
  if (uVar25 == 0x1b0501) {
    uVar13 = 6;
    goto LAB_1c001187d;
  }
  if (uVar25 == 0x1b0521) goto LAB_1c001187d;
  local_1a0 = _Dst;
  local_198 = param_3;
  local_190 = param_2;
  local_178 = puVar21;
  if ((*(char *)(param_1 + 0x611) != '\0') && (uVar25 != 0x4203f)) {
    piVar15 = &local_16c;
    (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x28))(param_1);
    if (local_16c != 0) {
      uVar25 = local_16c << 0x10 | 9;
      uVar29 = (ulonglong)uVar25;
      uVar13 = (ulonglong)(uVar25 + 0xe01a0000);
      ArcLogEventString(param_1,piVar15,uVar25 + 0xe01a0000,uVar25,in_stack_fffffffffffffe08,0x10);
      *(undefined4 *)(param_1 + 0x1d0) = 4;
      uVar14 = 1;
      (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x50))(param_1);
      cVar8 = ResetAndInitializeAdapter(param_1,uVar14,uVar13,uVar29);
      if (cVar8 == '\0') {
        *(undefined4 *)(param_1 + 0x1d0) = 2;
      }
      else {
        *(undefined1 *)(param_1 + 0x619) = 0;
        *(undefined1 *)(param_1 + 0x617) = 0;
        *(undefined4 *)(param_1 + 0x1d0) = 1;
        *(undefined4 *)(param_1 + 0x648) = 0;
        (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x50))(param_1,0);
      }
      uVar13 = 5;
      goto LAB_1c000fb25;
    }
    param_4 = 0;
  }
  puVar18 = puVar21 + 1;
  uVar13 = 6;
  uVar25 = 6;
  uVar23 = 6;
  puVar27 = local_190;
  uVar14 = CompareStrings((longlong)puVar18,"AACAPI",6);
  if ((char)uVar14 == '\0') {
    uVar14 = CompareStrings((longlong)puVar18,"CSMIALL",7);
    if (((((char)uVar14 != '\0') &&
         (uVar14 = CompareStrings((longlong)puVar18,"CSMIARY",7), (char)uVar14 != '\0')) &&
        (uVar14 = CompareStrings((longlong)puVar18,"CSMISAS",7), (char)uVar14 != '\0')) &&
       (uVar14 = CompareStrings((longlong)puVar18,"CSMIPHY",7), (char)uVar14 != '\0'))
    goto LAB_1c001187d;
    if (puVar21[4] == 0x4203b) {
      if (puVar21[6] == 0) goto LAB_1c000fbc5;
      *(bool *)(param_1 + 0xba2c) = *(char *)((ulonglong)*puVar21 + (longlong)puVar21) == '\0';
    }
    else if (puVar21[4] != 0x42003) {
      if (*(char *)(param_1 + 0xba2c) == '\0') {
        uVar13 = HandleCSMI(param_1,(longlong)puVar27);
        return uVar13;
      }
      goto LAB_1c001187d;
    }
  }
  else {
    uVar26 = puVar21[4];
    if (uVar26 == 0x4203b) {
      if (puVar21[6] == 0) {
LAB_1c000fbc5:
        uVar25 = 0x12;
        goto LAB_1c000fbca;
      }
      *(bool *)(param_1 + 0xba2c) = *(char *)((ulonglong)*puVar21 + (longlong)puVar21) == '\0';
    }
    else if (uVar26 != 0x42003) {
      if (*(char *)(param_1 + 0xba2c) != '\0') goto LAB_1c001187d;
      if (uVar26 < 0x42030) {
        if (uVar26 == 0x4202f) {
          uVar13 = (ulonglong)*puVar21;
          *(undefined4 *)(uVar13 + 0x84 + (longlong)puVar21) = *(undefined4 *)(param_1 + 0xaa04);
          memcpy((void *)((longlong)puVar21 + uVar13 + 200),(void *)(param_1 + 0xa9c2),0x40);
          memcpy((void *)((longlong)puVar21 + uVar13 + 0x88),"This is a code stream identifier",0x21
                );
LAB_1c000ff62:
          uVar25 = 1;
        }
        else {
          if (uVar26 < 0x4201c) {
            if (uVar26 == 0x4201b) goto LAB_1c0010a7b;
            if (uVar26 == 0x42007) goto LAB_1c0010647;
            if (uVar26 == 0x4200b) {
              if (puVar21[5] < 0xff) goto LAB_1c000ff62;
LAB_1c001092b:
              puVar21[5] = uVar25;
              goto LAB_1c000fbcd;
            }
            if (uVar26 == 0x4200f) {
              lVar19 = *(longlong *)(puVar27 + 0xc);
              *(undefined4 **)(_Dst + 0x28) = param_3;
              *(longlong *)(_Dst + 0x20) = param_1 + 0x658;
              *(ushort **)(_Dst + 0x18) = puVar27;
              *_Dst = 1;
              *(void **)(_Dst + 8) = (void *)(lVar19 + 0x1c);
              *(undefined8 *)(_Dst + 0x58) = 0;
              *(longlong *)(_Dst + 0x40) = param_1;
              if (*(ushort *)(param_1 + 0x1318) == *(ushort *)(param_1 + 0x131a)) {
                puVar3 = *(undefined8 **)(param_1 + 0x688);
                plVar1 = (longlong *)(_Dst + 0x30);
                *plVar1 = param_1 + 0x680;
                *(undefined8 **)(_Dst + 0x38) = puVar3;
                *puVar3 = plVar1;
                *(longlong **)(param_1 + 0x688) = plVar1;
                uVar14 = ServiceInternalAifQueue(param_1);
                if ((char)uVar14 == '\0') {
                  *(undefined4 *)(lVar19 + 0x10) = 0;
                  plVar4 = *(longlong **)(_Dst + 0x38);
                  lVar5 = *plVar1;
                  *plVar4 = lVar5;
                  *(longlong **)(lVar5 + 8) = plVar4;
                }
                else {
                  *(undefined4 *)(lVar19 + 0x10) = 2;
                }
              }
              else {
                memcpy((void *)(lVar19 + 0x1c),
                       (void *)((ulonglong)*(ushort *)(param_1 + 0x1318) * 0x60 + 0x698 + param_1),
                       0x60);
                *(uint *)(lVar19 + 0x10) =
                     (uint)*(ushort *)
                            (param_1 + 0x1298 + (ulonglong)*(ushort *)(param_1 + 0x1318) * 2) <<
                     0x10 | 1;
                *(uint *)(lVar19 + 0x18) =
                     (uint)*(ushort *)
                            (param_1 + 0x12d8 + (ulonglong)*(ushort *)(param_1 + 0x1318) * 2);
                if (*(short *)(param_1 + 0x1318) == 0x1f) {
                  *(undefined2 *)(param_1 + 0x1318) = 0;
                }
                else {
                  *(short *)(param_1 + 0x1318) = *(short *)(param_1 + 0x1318) + 1;
                }
              }
              uVar25 = 1;
              *(undefined4 *)(lVar19 + 0x14) = 1;
              goto LAB_1c000fbcd;
            }
            if (uVar26 == 0x42013) {
              _Src = (short *)((ulonglong)*puVar21 + (longlong)puVar21);
              uVar25 = 1;
              uVar13 = (ulonglong)*(uint *)(_Src + 4);
              puVar20 = (undefined4 *)((longlong)_Src + uVar13);
              if ((*_Src == 1) && (_Src[2] == 1)) {
                if (0x28 < *(uint *)(_Src + 4)) {
                  uVar13 = 0x28;
                }
                memcpy((void *)(param_1 + 0x1328),_Src,uVar13);
                *puVar20 = 0x10001;
                puVar20[1] = 0x20;
                *(longlong *)(puVar20 + 2) = param_1;
                *(undefined8 *)(puVar20 + 6) = **(undefined8 **)(param_1 + 0x1320);
                *(undefined8 *)(puVar20 + 4) =
                     *(undefined8 *)(*(longlong *)(param_1 + 0x1320) + 0x18);
              }
              else {
                uVar25 = 6;
              }
              if (((*(char *)(param_1 + 0x516a) == '\0') && (*(char *)(param_1 + 0x615) == '\0')) &&
                 ((*(int *)(param_1 + 0x1d0) != 1 && (*(longlong *)(param_1 + 0x188) == 0)))) {
                uVar25 = GetElapsedSeconds(param_1,_Src,uVar13,param_4);
                cVar8 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 8))(param_1,uVar25);
                if (cVar8 == '\0') goto LAB_1c0010735;
                *(undefined1 *)(param_1 + 0x610) = 0;
                *(undefined4 *)(param_1 + 0x1d0) = 1;
LAB_1c000fe49:
                uVar25 = 1;
              }
            }
            else {
              if (uVar26 != 0x42017) goto LAB_1c001092b;
              uVar25 = 9;
              uVar26 = *(uint *)((ulonglong)*puVar21 + 0xc + (longlong)puVar21);
              if (uVar26 != 0) {
                if (uVar26 < 4) {
                  piVar15 = (int *)(param_1 + 0x19cc);
                  do {
                    if (((*piVar15 == 1) || (*piVar15 == 4)) &&
                       (piVar15[5] == *(int *)((ulonglong)*puVar21 + 8 + (longlong)puVar21))) {
                      if (uVar26 == 1) {
                        *(undefined4 *)(param_1 + 0x19cc + uVar29 * 0x28) = 1;
                      }
                      else {
                        if (uVar26 == 2) {
                          *(undefined4 *)(param_1 + 0x19cc + uVar29 * 0x28) = 4;
                          goto LAB_1c000fe49;
                        }
                        if (uVar26 != 3) goto LAB_1c000fe49;
                        *(undefined4 *)(param_1 + 0x19cc + uVar29 * 0x28) = 2;
                      }
                      StorPortNotification(7,param_1,4);
                      goto LAB_1c000fe49;
                    }
                    uVar28 = (int)uVar29 + 1;
                    uVar29 = (ulonglong)uVar28;
                    piVar15 = piVar15 + 10;
                  } while (uVar28 < 0xfe);
                }
                else if (uVar26 == 4) {
                  uVar25 = 1;
                }
              }
            }
            goto LAB_1c000fbca;
          }
          if (uVar26 != 0x4201f) {
            if (uVar26 == 0x42023) {
              puVar18 = (uint *)((ulonglong)*puVar21 + (longlong)puVar21);
              iVar16 = *(int *)(param_1 + 0x19cc + (ulonglong)*puVar18 * 0x28);
              if ((iVar16 == 1) || (uVar25 = 9, iVar16 == 4)) {
                uVar25 = puVar21[6];
                puVar18[1] = *(uint *)(param_1 + 0x19e4 + (ulonglong)*puVar18 * 0x28);
                if (uVar25 != 8) {
                  puVar18[2] = *(uint *)(param_1 + 0x19e0 + (ulonglong)*puVar18 * 0x28);
                }
                uVar25 = 1;
              }
              goto LAB_1c000fbca;
            }
            if (uVar26 == 0x42027) {
              if (*(longlong *)(param_1 + 0x188) == 0) {
                uVar14 = SendSynchFib(param_1,(ulonglong)
                                              *(ushort *)
                                               ((ulonglong)*puVar21 + 4 + (longlong)puVar21),
                                      (uint *)((longlong)puVar21 + (ulonglong)*puVar21 + 0x20),0x1e0
                                      ,(void *)0x0,(ushort *)0x0,'\x01');
                uVar25 = (-(uint)((char)uVar14 != '\0') & 0xfffffff8) + 9;
              }
              else {
                uVar25 = 5;
              }
              goto LAB_1c000fbcd;
            }
            if (uVar26 != 0x4202b) goto LAB_1c001092b;
            if (puVar21[6] < 0x18) goto LAB_1c000fbc5;
            uVar13 = (ulonglong)*puVar21;
            bVar30 = RevCheckCompatibility
                               (0x4201b,*(int *)(uVar13 + (longlong)puVar21),
                                *(uint *)(uVar13 + 8 + (longlong)puVar21));
            *(int *)(uVar13 + 0xc + (longlong)puVar21) = (int)CONCAT71(extraout_var,bVar30);
            *(undefined4 *)(uVar13 + 0x10 + (longlong)puVar21) = 0x7050400;
            *(undefined4 *)(uVar13 + 0x14 + (longlong)puVar21) = 0x7d30;
            goto LAB_1c000ff62;
          }
          uVar25 = *puVar21;
          bVar30 = true;
          cVar8 = '\x01';
          sVar10 = *(short *)((longlong)puVar21 + (ulonglong)uVar25 + 4);
          puVar20 = (undefined4 *)((longlong)puVar21 + (ulonglong)uVar25 + 0x20);
          if (sVar10 == 0xee) {
            if (*(longlong *)(param_1 + 0x188) == 0) {
              GetElapsedSeconds(param_1,1,uVar23,param_4);
              cVar9 = (**(code **)(*(longlong *)(param_1 + 0x1320) + 8))(param_1);
              if (cVar9 == '\0') goto LAB_1c0010735;
              goto LAB_1c0010134;
            }
          }
          else {
            if (sVar10 == 0x7c) {
              if (*(longlong *)(param_1 + 0x188) != 0) goto LAB_1c0010638;
              cVar8 = (*(code *)**(undefined8 **)(param_1 + 0x1320))(param_1,4,0);
            }
LAB_1c0010134:
            if (*(longlong *)(param_1 + 0x188) == 0) {
              memset(param_3,0,0x20);
              *param_3 = 0x8000d;
              param_3[2] = 0x2000200;
              *(undefined1 *)((longlong)param_3 + 6) = 1;
              *(undefined2 *)(param_3 + 1) =
                   *(undefined2 *)((longlong)puVar21 + (ulonglong)uVar25 + 4);
              *param_3 = 0x8102d;
              memcpy(param_3 + 8,puVar20,
                     (ulonglong)*(ushort *)((longlong)puVar21 + (ulonglong)uVar25 + 8) - 0x20);
              sVar10 = *(short *)(param_3 + 1);
              *(undefined2 *)(param_3 + 2) =
                   *(undefined2 *)((longlong)puVar21 + (ulonglong)uVar25 + 8);
              if (sVar10 == 10) {
                cVar8 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                                  (param_1,10,(int)*(undefined8 *)(param_1 + 0x1e0) + 0x20,*puVar20)
                ;
              }
              else if (sVar10 == 0xb) {
                bVar30 = false;
                cVar8 = (*(code *)**(undefined8 **)(param_1 + 0x1320))
                                  (param_1,0xb,*(longlong *)(param_1 + 0x1e0) + 0x30,*puVar20);
              }
              else if (sVar10 == 0x28) {
                uVar25 = *puVar21;
                *(undefined2 *)(*(longlong *)(param_1 + 0x1d8) + 4) = 0x28;
                puVar20 = (undefined4 *)((ulonglong)uVar25 + (longlong)puVar21);
                cVar8 = (*(code *)**(undefined8 **)(param_1 + 0x1320))(param_1,0x28,0,0);
                if ((int)local_178 == 1) {
                  *puVar20 = local_1a0._0_4_;
                  puVar20[1] = 0xdeadbeef;
                }
                else {
                  *puVar20 = 0xdeadbeef;
                  if ((int)local_178 == 2) {
                    puVar20[1] = local_1a0._0_4_;
                  }
                  else {
                    puVar20[1] = 0xdeadbeef;
                    if ((int)local_178 == 3) {
                      puVar20[2] = local_1a0._0_4_;
                      goto LAB_1c0010361;
                    }
                  }
                }
                puVar20[2] = 0xdeadbeef;
              }
              else {
                puVar21[5] = 9;
              }
LAB_1c0010361:
              if (cVar8 != '\x01') goto LAB_1c0010735;
              if (bVar30) {
                uVar25 = 1;
                puVar21[5] = 1;
                goto LAB_1c000fbcd;
              }
              *(ushort **)(param_1 + 0x188) = local_190;
              RequestTimer(param_1,0x10,10000,1);
              goto LAB_1c001186b;
            }
          }
LAB_1c0010638:
          uVar25 = 5;
        }
        puVar21[5] = uVar25;
      }
      else {
        if (uVar26 < 0x42261) {
          if (uVar26 != 0x42260) {
            if (uVar26 != 0x42033) {
              if (uVar26 == 0x42037) {
LAB_1c0010647:
                lVar19 = *(longlong *)(puVar27 + 0xc);
                *(short *)(lVar19 + 0x24) = *(short *)(lVar19 + 0x24) + 0x20;
                memset(_Dst,0,0x6f8);
                if ((*(ushort *)(lVar19 + 0x26) < 0x201) && (*(ushort *)(lVar19 + 0x24) < 0x201)) {
                  local_198 = *(undefined4 **)(lVar19 + 0x223U & 0xfffffffffffffff8);
                }
                else {
                  local_198 = *(undefined4 **)(lVar19 + 0x1023U & 0xfffffffffffffff8);
                }
                if ((*(uint *)(param_1 + 0x8068) < (uint)*(ushort *)(lVar19 + 0x26)) ||
                   (*(uint *)(param_1 + 0x8068) < (uint)*(ushort *)(lVar19 + 0x24)))
                goto LAB_1c001187d;
                memcpy(param_3,(void *)(lVar19 + 0x1c),(ulonglong)*(ushort *)(lVar19 + 0x24));
                if (*(char *)(param_1 + 0x610) == '\0') {
                  *(longlong *)(_Dst + 0x40) = param_1;
                  *(longlong *)(_Dst + 0x20) = param_1 + 0x658;
                  *(ushort **)(_Dst + 0x18) = local_190;
                  *(undefined4 **)(_Dst + 0x28) = param_3;
                  *_Dst = 1;
                  *(undefined4 **)(_Dst + 8) = local_198;
                  *(undefined8 *)(_Dst + 0x58) = 0;
                  uVar14 = StorPortGetPhysicalAddress(param_1,0,param_3,&local_170);
                  *(undefined8 *)(_Dst + 0x10) = uVar14;
                  if ((*(int *)(_Dst + 0x14) != 0) && (*(char *)(param_1 + 0x8084) == '\0'))
                  goto LAB_1c001187d;
                  sVar10 = *(short *)(lVar19 + 0x20);
                  goto LAB_1c001185b;
                }
                if (*(longlong *)(param_1 + 0x188) == 0) {
                  if (*(ushort *)(param_3 + 2) - 0x20 < 0x1e1) {
                    uVar14 = SendSynchFib(param_1,(ulonglong)*(ushort *)(param_3 + 1),param_3 + 8,
                                          (ulonglong)(*(ushort *)(param_3 + 2) - 0x20 & 0xffff),
                                          param_3 + 8,(ushort *)&local_1a0,'\x01');
                    if ((char)uVar14 != '\0') {
                      *(ushort *)(param_3 + 2) = (ushort)local_1a0 + 0x20;
                      memcpy(local_198,param_3,(ulonglong)(ushort)((ushort)local_1a0 + 0x20));
                      uVar25 = 1;
                      *(undefined1 *)((longlong)local_190 + 3) = 1;
                      puVar21[5] = 1;
                      goto LAB_1c000fbcd;
                    }
                    goto LAB_1c0010735;
                  }
                  goto LAB_1c001092b;
                }
              }
              else {
                if (uVar26 != 0x4203f) {
                  if (uVar26 == 0x42043) {
                    uVar25 = *(uint *)(param_1 + 0x1594);
                    uVar11 = GetOutstandingIoCnt(param_1);
                    puVar27 = (ushort *)(param_1 + 0x158c);
                    builtin_strncpy(local_128,"arcsas.sys",0xb);
                    uVar29 = 1;
                    lVar19 = 4;
                    local_f4 = *(int *)(param_1 + 0x670) + -1;
                    local_f0 = *(undefined4 *)(param_1 + 0x1598);
                    local_ec = uVar25 & 0x1f;
                    local_e8 = uVar25 >> 5 & 7;
                    puVar18 = local_e4;
                    do {
                      uVar2 = *puVar27;
                      puVar27 = puVar27 + 1;
                      *puVar18 = (uint)uVar2;
                      puVar18 = puVar18 + 1;
                      lVar19 = lVar19 + -1;
                    } while (lVar19 != 0);
                    local_d4 = *(undefined4 *)(param_1 + 0x80a8);
                    local_d0 = *(undefined4 *)(param_1 + 0x80bc);
                    local_cc = *(undefined4 *)(param_1 + 0x80b8);
                    uVar25 = 0xd8;
                    if (puVar21[6] < 0xd8) {
                      uVar25 = puVar21[6];
                    }
                    local_c8 = *(undefined1 *)(param_1 + 0x8084);
                    local_c7 = *(undefined1 *)(param_1 + 0x808c);
                    local_c4 = *(undefined4 *)(param_1 + 0x8064);
                    local_c0 = *(undefined4 *)(param_1 + 0x8068);
                    local_bc = *(undefined4 *)(param_1 + 0x806c);
                    local_b8 = *(undefined4 *)(param_1 + 0x8070);
                    local_b4 = *(undefined4 *)(param_1 + 0x8074);
                    local_b0 = *(undefined1 *)(param_1 + 0x516b);
                    local_af = *(undefined1 *)(param_1 + 0x517c);
                    local_ae = *(undefined1 *)(param_1 + 0xa924);
                    local_ac = *(undefined4 *)(param_1 + 0xa908);
                    local_a8 = *(undefined4 *)(param_1 + 0xa90c);
                    local_a4 = *(undefined4 *)(param_1 + 0xa91c);
                    local_a0 = (uint)uVar11;
                    local_9c = *(undefined1 *)(param_1 + 0x611);
                    local_98 = *(undefined4 *)(param_1 + 0x1370);
                    local_94 = *(undefined4 *)(param_1 + 5000);
                    local_8c = *(undefined4 *)(param_1 + 0x1398);
                    local_88 = *(undefined4 *)(param_1 + 0x1394);
                    local_84 = *(undefined4 *)(param_1 + 0x13a0);
                    local_80 = *(undefined4 *)(param_1 + 0x13cc);
                    local_7c = *(undefined4 *)(param_1 + 0x13e0);
                    local_90 = 0x7d30;
                    memcpy((void *)((ulonglong)*puVar21 + (longlong)puVar21),local_128,
                           (ulonglong)uVar25);
                    goto LAB_1c001186b;
                  }
                  if (uVar26 == 0x42047) {
                    piVar15 = (int *)((ulonglong)*puVar21 + (longlong)puVar21);
                    piVar22 = (int *)(param_1 + 0x19cc);
                    do {
                      if ((*piVar15 == piVar22[6]) && ((*piVar22 == 1 || (*piVar22 == 4)))) {
                        piVar15[1] = (int)uVar29;
                        puVar21[5] = 1;
                        goto LAB_1c001046d;
                      }
                      uVar25 = (int)uVar29 + 1;
                      uVar29 = (ulonglong)uVar25;
                      piVar22 = piVar22 + 10;
                    } while (uVar25 < 0xfe);
                    piVar15[1] = -1;
LAB_1c001046d:
                    uVar25 = 1;
                    puVar21[5] = 1;
                    goto LAB_1c000fbcd;
                  }
                  goto LAB_1c001092b;
                }
                ArcPrintf(param_1,0x20,(byte *)"* - IOCTL: FSAMPCTL_RESET_IOP\n",param_4);
              }
              goto LAB_1c0010638;
            }
LAB_1c001095a:
            uVar13 = (ulonglong)*puVar21;
            if (*(uint *)(uVar13 + (longlong)puVar21) == 0) {
              puVar18 = (uint *)(uVar13 + 0x100 + (longlong)puVar21);
              *puVar18 = *puVar18 ^
                         ((uint)*(byte *)(param_1 + 0x15a6) ^
                         *(uint *)(uVar13 + 0x100 + (longlong)puVar21)) & 1;
              uVar25 = (*(int *)(param_1 + 0x210) != 0 | 2) * 2 |
                       *(uint *)(uVar13 + 0x100 + (longlong)puVar21) & 0xfffffffd;
              *(uint *)(uVar13 + 0x100 + (longlong)puVar21) = uVar25;
              *(uint *)(uVar13 + 0x100 + (longlong)puVar21) =
                   ((uint)*(byte *)(param_1 + 0x5169) << 3 ^ uVar25) & 8 ^ uVar25;
            }
            else {
              if ((*(uint *)(uVar13 + (longlong)puVar21) & 1) != 0) {
                puVar18 = (uint *)(uVar13 + 0x100 + (longlong)puVar21);
                *puVar18 = *puVar18 ^
                           ((uint)*(byte *)(param_1 + 0x15a6) ^
                           *(uint *)(uVar13 + 0x100 + (longlong)puVar21)) & 1;
              }
              if ((*(uint *)(uVar13 + (longlong)puVar21) & 8) != 0) {
                puVar18 = (uint *)(uVar13 + 0x100 + (longlong)puVar21);
                *puVar18 = *puVar18 ^
                           ((uint)*(byte *)(param_1 + 0x5169) << 3 ^
                           *(uint *)(uVar13 + 0x100 + (longlong)puVar21)) & 8;
              }
              if ((*(uint *)(uVar13 + (longlong)puVar21) & 2) != 0) {
                puVar18 = (uint *)(uVar13 + 0x100 + (longlong)puVar21);
                *puVar18 = *puVar18 ^
                           ((uint)(*(int *)(param_1 + 0x210) != 0) * 2 ^
                           *(uint *)(uVar13 + 0x100 + (longlong)puVar21)) & 2;
                *(undefined4 *)(uVar13 + 0x104 + (longlong)puVar21) =
                     *(undefined4 *)(param_1 + 0x8068);
                *(undefined4 *)(uVar13 + 0x108 + (longlong)puVar21) =
                     *(undefined4 *)(param_1 + 0x210);
              }
              if ((*(uint *)(uVar13 + (longlong)puVar21) & 4) != 0) {
                puVar18 = (uint *)(uVar13 + 0x100 + (longlong)puVar21);
                *puVar18 = *puVar18 | 4;
                uVar12 = 0x10;
                if (*(char *)(param_1 + 0x516a) == '\0') {
                  uVar12 = *(undefined4 *)(param_1 + 0x807c);
                }
                *(undefined4 *)(uVar13 + 0x104 + (longlong)puVar21) = uVar12;
              }
            }
            uVar25 = 1;
            puVar21[5] = 1;
            goto LAB_1c000fbcd;
          }
          lVar19 = *(longlong *)(puVar27 + 0xc);
          *(short *)(lVar19 + 0x24) = *(short *)(lVar19 + 0x24) + 0x20;
          _Src_01 = (void *)(lVar19 + 0x1c);
          memset(_Dst,0,0x6f8);
          if ((*(uint *)(param_1 + 0x8068) < (uint)*(ushort *)(lVar19 + 0x26)) ||
             (*(uint *)(param_1 + 0x8068) < (uint)*(ushort *)(lVar19 + 0x24))) goto LAB_1c001187d;
          memcpy(param_3,_Src_01,(ulonglong)*(ushort *)(lVar19 + 0x24));
          if (*(char *)(param_1 + 0x610) != '\0') {
            if (*(longlong *)(param_1 + 0x188) == 0) {
              if (*(ushort *)(param_3 + 2) - 0x20 < 0x1e1) {
                uVar25 = 1;
                uVar14 = SendSynchFib(param_1,(ulonglong)*(ushort *)(param_3 + 1),param_3 + 8,
                                      (ulonglong)(*(ushort *)(param_3 + 2) - 0x20 & 0xffff),
                                      param_3 + 8,(ushort *)&local_1a0,'\x01');
                if ((char)uVar14 == '\0') goto LAB_1c0010735;
                *(ushort *)(param_3 + 2) = (ushort)local_1a0 + 0x20;
                memcpy(_Src_01,param_3,(ulonglong)(ushort)((ushort)local_1a0 + 0x20));
                *(undefined1 *)((longlong)local_190 + 3) = 1;
              }
              goto LAB_1c001092b;
            }
            goto LAB_1c0010638;
          }
          *(longlong *)(_Dst + 0x40) = param_1;
          *(longlong *)(_Dst + 0x20) = param_1 + 0x658;
          *(ushort **)(_Dst + 0x18) = local_190;
          *(undefined4 **)(_Dst + 0x28) = param_3;
          *_Dst = 1;
          *(void **)(_Dst + 8) = _Src_01;
          *(undefined8 *)(_Dst + 0x58) = 0;
          uVar14 = StorPortGetPhysicalAddress(param_1,0,param_3,&local_170);
          *(undefined8 *)(_Dst + 0x10) = uVar14;
          if ((*(int *)(_Dst + 0x14) != 0) && (*(char *)(param_1 + 0x8084) == '\0'))
          goto LAB_1c001187d;
          sVar10 = *(short *)(lVar19 + 0x20);
LAB_1c001185b:
          cVar8 = SendFib(sVar10,(longlong)_Dst,'\0');
          if (cVar8 == '\0') goto LAB_1c0010638;
        }
        else {
          if (uVar26 == 0x42264) {
LAB_1c0010a7b:
            puVar27 = (ushort *)((ulonglong)*puVar21 + (longlong)puVar21);
            local_158 = puVar27;
            if (uVar26 == 0x42264) {
              local_180 = *(ushort **)(param_1 + 0x208);
              if (*(char *)(param_1 + 0x214) != '\0') goto LAB_1c0010638;
              *(undefined1 *)(param_1 + 0x214) = 1;
              if (*(uint *)(param_1 + 0x210) < *(uint *)(puVar27 + 8)) goto LAB_1c001092b;
              memcpy(local_180,
                     (void *)((longlong)puVar27 +
                              (ulonglong)*puVar27 + 7 +
                              (ulonglong)*(byte *)((longlong)puVar27 + 0xb) & 0xfffffffffffffff8),
                     (ulonglong)*(uint *)(puVar27 + 8));
            }
            else {
              local_180 = (ushort *)0x0;
            }
            local_150[0] = 0;
            local_150[1] = 0;
            local_150[2] = 0;
            local_150[3] = 0;
            local_148 = 0;
            local_140 = 0;
            local_138 = 0;
            if (((((char)puVar27[0x24] == -1) && (*(char *)((longlong)puVar27 + 0x49) == 'U')) &&
                ((char)puVar27[0x25] == -0x56)) &&
               ((*(char *)((longlong)puVar27 + 0x4b) == 'U' && ((char)puVar27[0x26] == -0x56)))) {
              pcVar24 = "* ProcessIoctl: private cdb\'s here\n";
              ArcPrintf(param_1,0x20,(byte *)"* ProcessIoctl: private cdb\'s here\n",param_4);
              if ((*(byte *)((longlong)puVar27 + 0x57) & 0x10) != 0) {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) | 0x10;
                pcVar24 = "* ProcessIoctl: DBG_IO_TRACE flag set\n";
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_IO_TRACE flag set\n",param_4);
              }
              if ((*(byte *)((longlong)puVar27 + 0x57) & 0x20) != 0) {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) | 0x20;
                pcVar24 = "* ProcessIoctl: DBG_IOCTL_TRACE flag set\n";
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_IOCTL_TRACE flag set\n",param_4);
              }
              if ((*(byte *)((longlong)puVar27 + 0x57) & 0x40) != 0) {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) | 0x40;
                pcVar24 = "* ProcessIoctl: DBG_CLUSTER_TRACE flag set\n";
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_CLUSTER_TRACE flag set\n",param_4);
              }
              if (*(char *)((longlong)puVar27 + 0x57) < '\0') {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) | 0x80;
                pcVar24 = "* ProcessIoctl: DBG_ISR_TRACE flag set\n";
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_ISR_TRACE flag set\n",param_4);
              }
              if ((puVar27[0x2b] & 1) != 0) {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) | 0x10000100;
                pcVar24 = "* ProcessIoctl: DBG_IO_FUNC_ENTRY_TRACE flag set\n";
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_IO_FUNC_ENTRY_TRACE flag set\n",
                          param_4);
              }
              if ((puVar27[0x2b] & 2) != 0) {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) | 0x10000200;
                pcVar24 = "* ProcessIoctl: DBG_INIT_FUNC_ENTRY_TRACE flag set\n";
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_INIT_FUNC_ENTRY_TRACE flag set\n",
                          param_4);
              }
              if ((puVar27[0x2b] & 4) != 0) {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) | 0x10000400;
                pcVar24 = "* ProcessIoctl: DBG_IOCTL_FUNC_ENTRY_TRACE flag set\n";
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_IOCTL_FUNC_ENTRY_TRACE flag set\n",
                          param_4);
              }
              if ((*(byte *)((longlong)puVar27 + 0x55) & 0x10) != 0) {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) & 0xffffffef;
                pcVar24 = "* ProcessIoctl: DBG_IO_TRACE flag removed\n";
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_IO_TRACE flag removed\n",param_4);
              }
              lVar19 = 0x20;
              if ((*(byte *)((longlong)puVar27 + 0x55) & 0x20) != 0) {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) & 0xffffffdf;
                pcVar24 = "* ProcessIoctl: DBG_IOCTL_TRACE flag removed\n";
                lVar19 = 4;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_IOCTL_TRACE flag removed\n",param_4
                         );
              }
              if ((*(byte *)((longlong)puVar27 + 0x55) & 0x40) != 0) {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) & 0xffffffbf;
                pcVar24 = "* ProcessIoctl: DBG_CLUSTER_TRACE flag removed\n";
                lVar19 = 4;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_CLUSTER_TRACE flag removed\n",
                          param_4);
              }
              if (*(char *)((longlong)puVar27 + 0x55) < '\0') {
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) & 0xffffff7f;
                pcVar24 = "* ProcessIoctl: DBG_ISR_TRACE flag removed\n";
                lVar19 = 4;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_ISR_TRACE flag removed\n",param_4);
              }
              if ((puVar27[0x2a] & 1) != 0) {
                pcVar24 = "* ProcessIoctl: DBG_IO_FUNC_ENTRY_TRACE flag removed\n";
                lVar19 = 4;
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) & 0xeffffeff | 0x30000000;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DBG_IO_FUNC_ENTRY_TRACE flag removed\n"
                          ,param_4);
              }
              if ((puVar27[0x2a] & 2) != 0) {
                pcVar24 = "* ProcessIoctl: DBG_INIT_FUNC_ENTRY_TRACE flag removed\n";
                lVar19 = 4;
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) & 0xeffffdff | 0x30000000;
                ArcPrintf(param_1,4,
                          (byte *)"* ProcessIoctl: DBG_INIT_FUNC_ENTRY_TRACE flag removed\n",param_4
                         );
              }
              if ((puVar27[0x2a] & 4) != 0) {
                pcVar24 = "* ProcessIoctl: DBG_IOCTL_FUNC_ENTRY_TRACE flag removed\n";
                lVar19 = 4;
                *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) & 0xeffffbff | 0x30000000;
                ArcPrintf(param_1,4,
                          (byte *)"* ProcessIoctl: DBG_IOCTL_FUNC_ENTRY_TRACE flag removed\n",
                          param_4);
              }
              if ((((char)puVar27[0x2a] != '\0') || (*(char *)((longlong)puVar27 + 0x55) != '\0'))
                 || (((char)puVar27[0x2b] != '\0' || (*(char *)((longlong)puVar27 + 0x57) != '\0')))
                 ) {
                param_4 = (ulonglong)*(uint *)(param_1 + 0x5e08);
                pcVar24 = "* ProcessIoctl: DebugFlags: 0x%x\n";
                lVar19 = 4;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: DebugFlags: 0x%x\n",param_4);
              }
              if (*(char *)((longlong)puVar27 + 0x53) == '\x01') {
                if ((*(char *)(param_1 + 0xaad6) != '\0') &&
                   (sVar10 = GetOutstandingIoCnt(param_1), sVar10 == 0)) {
                  bVar30 = *(char *)(param_1 + 0x617) == '\0';
                  if (bVar30) {
                    param_4 = 0;
                    pcVar24 = (char *)0x3;
                    lVar19 = param_1;
                    StorPortNotification(0x1003);
                  }
                  if (((ushort)(*(short *)(param_1 + 0x158e) - 0x28cU) < 2) &&
                     (*(char *)(param_1 + 0xaad6) != '\0')) {
                    (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x50))(param_1,8);
                    ArcPrintf(param_1,4,(byte *)"* Switching to INTx mode\n",param_4);
                    pcVar24 = "* Set pInitStruct->NoOfMsiVectors to 0 in ProcessIoctl\n";
                    *(undefined1 *)(param_1 + 0xaad6) = 0;
                    lVar19 = 4;
                    *(undefined1 *)(param_1 + 0xaadc) = 0;
                    *(undefined4 *)(*(longlong *)(param_1 + 0x630) + 4) = 0;
                    ArcPrintf(param_1,4,
                              (byte *)"* Set pInitStruct->NoOfMsiVectors to 0 in ProcessIoctl\n",
                              param_4);
                  }
                  if (bVar30) {
                    pcVar24 = (char *)local_150;
                    lVar19 = param_1;
                    StorPortNotification(0x1004);
                  }
                }
              }
              else if (*(char *)((longlong)puVar27 + 0x53) == '\x02') {
                if (*(char *)(param_1 + 0xaad6) != '\0') {
                  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 1;
                }
                if ((*(char *)(param_1 + 0x617) == '\0') && (*(char *)(param_1 + 0x618) == '\0')) {
                  ReturningLocalOutstandingRequestsToOS(param_1);
                  cVar8 = IOPReset(param_1,'\x01',pcVar24,param_4);
                  if (cVar8 == '\0') {
                    if (*(char *)(param_1 + 0xaad6) != '\0') {
                      *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xfffffffe;
                    }
                    *(uint *)(param_1 + 0x5e08) = *(uint *)(param_1 + 0x5e08) | 0x20000000;
                    pcVar24 = "* IOP RESET failed in ProcessIoctl by private CDB, line #%d\n";
                    *(undefined1 *)(param_1 + 0x617) = 0;
                    *(undefined4 *)(param_1 + 0x1d0) = 1;
                    param_4 = 0x4fa;
                  }
                  else {
                    uVar13 = 1;
                    *(undefined1 *)(param_1 + 0x618) = 1;
                    RequestTimer(param_1,0x20,180000000,1);
                    if ((*(uint *)(param_1 + 0xbad8) & 1) != 0) {
                      ArcPrintf(param_1,4,
                                (byte *)"* when back from IOP_RESET, we will be in INTx mode\n",
                                uVar13);
                    }
                    ArcPrintf(param_1,4,
                              (byte *)"* set timer to check the FW status for IOP_RESET, line #%d\n"
                              ,0x4ed);
                    param_4 = 0x4ee;
                    pcVar24 = "* IOP RESET is done in ProcessIoctl by private CDB, line #%d\n";
                  }
                  lVar19 = 4;
                  ArcPrintf(param_1,4,(byte *)pcVar24,param_4);
                }
              }
              if ((*(byte *)((longlong)puVar27 + 0x53) & 4) != 0) {
                pcVar24 = "* ProcessIoctl: coalescing disabled\n";
                *(undefined1 *)(param_1 + 0xa924) = 0;
                lVar19 = 4;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: coalescing disabled\n",param_4);
              }
              if ((*(byte *)((longlong)puVar27 + 0x53) & 8) != 0) {
                pcVar24 = "* ProcessIoctl: coalescing enabled\n";
                lVar19 = 4;
                *(undefined1 *)(param_1 + 0xa924) = 1;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: coalescing enabled\n",param_4);
              }
              if (((*(byte *)((longlong)puVar27 + 0x53) & 0x10) != 0) &&
                 (*(char *)(param_1 + 0xaad6) != '\0')) {
                if (((byte)puVar27[0x29] == 0) ||
                   (*(ushort *)(param_1 + 0xba0a) < (ushort)(byte)puVar27[0x29])) {
                  uVar11 = *(ushort *)(param_1 + 0xba0a);
                  pcVar24 = 
                  "* ProcessIoctl: Get a request for changing outstanding IO limit(MSIX mode). New IO limit is invalid, should be smaller than %d\n"
                  ;
                  uVar25 = (uint)*(ushort *)(param_1 + 0xaad4);
                }
                else {
                  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 2;
                  *(uint *)(param_1 + 0xbae0) = (uint)(byte)puVar27[0x29];
                  uVar25 = GetElapsedSeconds(param_1,lVar19,pcVar24,param_4);
                  *(uint *)(param_1 + 0xbac0) = uVar25;
                  RequestTimer(param_1,0x1000,1000000,1);
                  uVar11 = *(ushort *)(param_1 + 0xaad4);
                  pcVar24 = 
                  "* ProcessIoctl: Get a request for changing outstanding IO limit(MSIX mode). New IO limit would be %d\n"
                  ;
                  uVar25 = (uint)(byte)puVar27[0x29];
                }
                param_4 = (ulonglong)(uVar11 * uVar25);
                lVar19 = 4;
                ArcPrintf(param_1,4,(byte *)pcVar24,param_4);
              }
              if (((*(byte *)((longlong)puVar27 + 0x53) & 0x10) != 0) &&
                 (*(char *)(param_1 + 0xaad6) == '\0')) {
                if (((byte)puVar27[0x29] == 0) ||
                   (*(ushort *)(param_1 + 0x8074) < (ushort)((ushort)(byte)puVar27[0x29] * 10))) {
                  uVar25 = *(uint *)(param_1 + 0x8078);
                  pcVar24 = 
                  "* ProcessIoctl: Get a request for changing outstanding IO limit(INTX mode). New IO limit is invalid, should be smaller than %d\n"
                  ;
                }
                else {
                  *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 2;
                  *(uint *)(param_1 + 0xbae0) = (uint)(byte)puVar27[0x29] * 10;
                  uVar25 = GetElapsedSeconds(param_1,lVar19,pcVar24,param_4);
                  *(uint *)(param_1 + 0xbac0) = uVar25;
                  RequestTimer(param_1,0x1000,1000000,1);
                  pcVar24 = 
                  "* ProcessIoctl: Get a request for changing outstanding IO limit(INTX mode). New IO limit would be %d\n"
                  ;
                  uVar25 = (uint)(byte)puVar27[0x29] * 10;
                }
                param_4 = (ulonglong)uVar25;
                ArcPrintf(param_1,4,(byte *)pcVar24,param_4);
              }
              if ((*(byte *)((longlong)puVar27 + 0x53) & 0x20) != 0) {
                param_4 = 1;
                StopTimer(param_1,0x1000,pcVar24,1);
                ArcPrintf(param_1,4,
                          (byte *)"* ProcessIoctl: TTYPE_CHANGE_IO_LIMIT timer cancelled\n",param_4)
                ;
              }
              if ((*(byte *)((longlong)puVar27 + 0x53) & 0x40) != 0) {
                *(uint *)(param_1 + 0xbadc) = *(uint *)(param_1 + 0xbadc) | 2;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: AIF commands prints enabled\n",param_4)
                ;
              }
              if (*(char *)((longlong)puVar27 + 0x53) < '\0') {
                *(uint *)(param_1 + 0xbadc) = *(uint *)(param_1 + 0xbadc) & 0xfffffffd;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: AIF commands prints disabled\n",param_4
                         );
              }
              if ((*(byte *)((longlong)puVar27 + 0x51) & 1) != 0) {
                *(uint *)(param_1 + 0xbadc) = *(uint *)(param_1 + 0xbadc) | 1;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: synch commands prints enabled\n",
                          param_4);
              }
              if ((*(byte *)((longlong)puVar27 + 0x51) & 2) != 0) {
                *(uint *)(param_1 + 0xbadc) = *(uint *)(param_1 + 0xbadc) & 0xfffffffe;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: synch commands prints disabled\n",
                          param_4);
              }
              if ((*(byte *)((longlong)puVar27 + 0x51) & 4) != 0) {
                *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) | 0x100;
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: RUN_CODE_IN_SPECIFIC flag enabled\n",
                          param_4);
              }
              if ((*(byte *)((longlong)puVar27 + 0x51) & 8) != 0) {
                *(uint *)(param_1 + 0xbad8) = *(uint *)(param_1 + 0xbad8) & 0xfffffeff;
                ArcPrintf(param_1,4,
                          (byte *)
                          "* ProcessIoctl: RUN_CODE_IN_SPECIFIC flag disabled. ReservedForActionOptions:0x%x\n"
                          ,(ulonglong)*(uint *)(param_1 + 0xbae0));
              }
              if ((*(byte *)((longlong)puVar27 + 0x51) & 0x10) != 0) {
                bVar17 = *(byte *)((longlong)puVar27 + 0x4d);
                local_1a0 = (undefined1 *)CONCAT71(local_1a0._1_7_,bVar17);
                if (((bVar17 < 0xff) && ((char)puVar27[0x27] != -1)) &&
                   (*(byte *)((longlong)puVar27 + 0x4f) < 0xff)) {
                  StorPortSetDeviceQueueDepth(param_1,bVar17,(char)puVar27[0x27],0);
                  pcVar24 = "* ProcessIoctl: bus=%d, target=%d, queuedepth set to %d successfully\n"
                  ;
                  bVar17 = (byte)local_1a0;
                }
                else {
                  pcVar24 = 
                  "* ProcessIoctl: wrong parameters of bus/target/QD. Check them again. Bus=%d, targetId=%d, QD=%d\n"
                  ;
                }
                ArcPrintf(param_1,4,(byte *)pcVar24,(ulonglong)bVar17);
              }
              if ((*(byte *)((longlong)puVar27 + 0x51) & 0x20) != 0) {
                bVar17 = 0;
                if (*(char *)(param_1 + 0xdcb8) != '\0') {
                  do {
                    ArcPrintf(param_1,4,
                              (byte *)"* ProcessIoctl: OsCmd %2d: cmd(0x%8x) count(%10d)\n",
                              (ulonglong)bVar17);
                    bVar17 = bVar17 + 1;
                  } while (bVar17 < *(byte *)(param_1 + 0xdcb8));
                  puVar21 = local_178;
                }
                bVar17 = 0;
                if (*(char *)(param_1 + 0xde9c) != '\0') {
                  do {
                    ArcPrintf(param_1,4,
                              (byte *)
                              "* ProcessIoctl: Osioctl %2d: controlCode(0x%8x) count(%10d)\n",
                              (ulonglong)bVar17);
                    bVar17 = bVar17 + 1;
                  } while (bVar17 < *(byte *)(param_1 + 0xde9c));
                  puVar21 = local_178;
                }
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: Max Data Transfer Length: 0x%x\n",
                          (ulonglong)*(uint *)(param_1 + 0xdea0));
                ArcPrintf(param_1,4,(byte *)"* ProcessIoctl: Max SG items: 0x%x\n",
                          (ulonglong)*(uint *)(param_1 + 0xdea4));
              }
              if ((*(byte *)((longlong)puVar27 + 0x51) & 0x40) != 0) {
                uVar11 = GetOutstandingIoCnt(param_1);
                ArcPrintf(param_1,4,(byte *)"* outstanding IO:%d\n",(ulonglong)uVar11);
              }
              if (*(char *)((longlong)puVar27 + 0x51) < '\0') {
                ArcPrintf(param_1,4,(byte *)"* Coalescing Q. CalledCnt:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2a4));
                ArcPrintf(param_1,4,(byte *)"* Coalescing Q. Beyond8kTransferSize:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2a8));
                ArcPrintf(param_1,4,(byte *)"* Coalescing Q. AcrossStripeBoundary:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2ac));
                ArcPrintf(param_1,4,(byte *)"* Coalescing Q. RwCmdTypeMixed:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2b0));
                ArcPrintf(param_1,4,(byte *)"* Coalescing Q. SGcntOverLimit:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2b4));
                ArcPrintf(param_1,4,(byte *)"* Coalescing Q. CmdSizeOverLimit:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2b8));
                ArcPrintf(param_1,4,(byte *)"* Coalescing Q. DequeueCalledCnt:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2bc));
                ArcPrintf(param_1,4,(byte *)"* Coalescing Q. CallSendFibDirectlyCnt:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2c0));
                ArcPrintf(param_1,4,(byte *)"* Sorting Q. CalledCnt:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2c4));
                ArcPrintf(param_1,4,(byte *)"* Sorting Q. OverlapCase1:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2c8));
                ArcPrintf(param_1,4,(byte *)"* Sorting Q. OverlapCase2:%d\n",
                          (ulonglong)*(uint *)(param_1 + 0xe2cc));
              }
              *(undefined1 *)(param_1 + 0x214) = 0;
              uVar25 = 1;
              *(undefined1 *)((longlong)local_190 + 3) = 1;
              puVar21[5] = 1;
              *(undefined2 *)((longlong)puVar27 + 3) = 1;
              goto LAB_1c000fbcd;
            }
            *(ulonglong *)(puVar27 + 0x10) =
                 -(ulonglong)(*(byte *)((longlong)puVar27 + 0xb) != 0) &
                 (ulonglong)*puVar27 + (longlong)puVar27;
            *(ulonglong *)(puVar27 + 0xc) =
                 -(ulonglong)(*(int *)(puVar27 + 8) != 0) &
                 (ulonglong)*(byte *)((longlong)puVar27 + 0xb) + 7 +
                 (ulonglong)*puVar27 + (longlong)puVar27 & 0xfffffffffffffff8;
            *(longlong *)(_Dst + 0x20) = param_1 + 0x658;
            *(ushort **)(_Dst + 0x18) = local_190;
            *(longlong *)(_Dst + 0x40) = param_1;
            *(undefined4 **)(_Dst + 0x28) = local_198;
            *_Dst = 0;
            uVar14 = StorPortGetPhysicalAddress(param_1,0,local_198,&local_170);
            *(undefined8 *)(_Dst + 0x10) = uVar14;
            if ((*(int *)(_Dst + 0x14) != 0) && (*(char *)(param_1 + 0x8084) == '\0')) {
LAB_1c001187d:
              puVar21[5] = (uint)uVar13;
              return uVar13;
            }
            puVar20 = *(undefined4 **)(_Dst + 0x28);
            memset(puVar20,0,0x20);
            puVar6 = local_198;
            _Dst = local_1a0;
            _Src_00 = puVar27 + 0x24;
            *(undefined1 *)((longlong)puVar20 + 6) = 1;
            puVar20[2] = 0x2000200;
            *puVar20 = 0x8000d;
            puVar18 = local_198 + 8;
            **(uint **)(local_1a0 + 0x28) = **(uint **)(local_1a0 + 0x28) & 0xfff7ffff;
            *puVar18 = (uint)(byte)puVar27[1];
            local_198[9] = (uint)*(byte *)((longlong)puVar27 + 5);
            local_198[10] = (uint)(byte)puVar27[3];
            local_198[0xb] = (uint)*(byte *)((longlong)puVar27 + 7);
            local_198[0xc] = *(undefined4 *)(puVar27 + 10);
            local_198[0xd] = *(undefined4 *)(puVar27 + 6);
            local_198[0xe] = *(undefined4 *)(puVar27 + 8);
            local_198[0xf] = 0;
            local_198[0x10] = (uint)(byte)puVar27[5];
            local_168 = puVar18;
            memcpy(local_198 + 0x11,_Src_00,(ulonglong)(byte)puVar27[5]);
            puVar7 = local_180;
            if (puVar6[0xe] == 0) {
              uVar25 = 0x40;
              puVar6[0x15] = 0;
              sVar10 = 0x60;
            }
            else if (*(char *)(param_1 + 0x15a5) == '\0') {
              uVar26 = 0;
              uVar25 = *(uint *)(puVar27 + 8);
              if (local_180 == (ushort *)0x0) {
                _Src_00 = *(ushort **)(puVar27 + 0xc);
                local_180 = _Src_00;
              }
              local_188 = uVar25;
              if (uVar25 != 0) {
                local_160 = local_190;
                if (puVar7 != (ushort *)0x0) {
                  local_160 = (ushort *)0x0;
                }
                puVar27 = local_180;
                uVar13 = 0;
                do {
                  _Src_00 = local_160;
                  uVar12 = StorPortGetPhysicalAddress(param_1,local_160,puVar27,&local_198);
                  puVar6[uVar13 * 2 + 0x16] = uVar12;
                  uVar28 = (uint)local_198;
                  if (uVar25 < (uint)local_198) {
                    uVar28 = uVar25;
                  }
                  uVar26 = (int)uVar13 + 1;
                  puVar27 = (ushort *)((longlong)puVar27 + (ulonglong)uVar28);
                  local_198 = (undefined4 *)CONCAT44(local_198._4_4_,uVar28);
                  puVar6[uVar13 * 2 + 0x17] = uVar28;
                  uVar25 = uVar25 - uVar28;
                  uVar13 = (ulonglong)uVar26;
                } while (uVar25 != 0);
                local_198 = (undefined4 *)CONCAT44(local_198._4_4_,uVar26);
                puVar21 = local_178;
                puVar27 = local_158;
                _Dst = local_1a0;
              }
              puVar18 = puVar6 + 8;
              uVar25 = uVar26 * 8 + 0x38;
              puVar6[0x15] = uVar26;
              sVar10 = (short)(uVar26 * 8) + 0x58;
            }
            else {
              _Src_00 = local_190;
              BuildRawScatterGather64
                        (param_1,local_190,(longlong)puVar27,(longlong)local_180,
                         (ushort *)(puVar6 + 0x15));
              iVar16 = (*(ushort *)(puVar6 + 0x15) - 1) * 0xc;
              uVar25 = iVar16 + 0x44;
              sVar10 = (short)iVar16 + 100;
              puVar18 = local_168;
            }
            *(short *)(puVar6 + 2) = sVar10;
            if (*(char *)(param_1 + 0x610) == '\0') {
              sVar10 = (*(char *)(param_1 + 0x15a5) != '\0') + 600;
              goto LAB_1c001185b;
            }
            if (*(longlong *)(param_1 + 0x188) != 0) goto LAB_1c0010638;
            uVar14 = SendSynchFib(param_1,CONCAT62((int6)((ulonglong)_Src_00 >> 0x10),
                                                   (*(char *)(param_1 + 0x15a5) != '\0') + 600),
                                  puVar18,(ulonglong)(uVar25 & 0xffff),puVar18,(ushort *)&local_1a0,
                                  '\x01');
            puVar18 = local_168;
            if ((char)uVar14 != '\0') {
              uVar25 = 1;
              *(undefined1 *)((longlong)local_190 + 3) = 1;
              puVar21[5] = 1;
              if (0x15 < (ushort)local_1a0) {
                if ((((char)local_168[1] < '\0') &&
                    (uVar26 = local_168[4], uVar26 + 0x16 <= (uint)(ushort)local_1a0)) &&
                   ((*(void **)(puVar27 + 0x10) != (void *)0x0 && (uVar26 != 0)))) {
                  if (*(byte *)((longlong)puVar27 + 0xb) < uVar26) {
                    uVar26 = (uint)*(byte *)((longlong)puVar27 + 0xb);
                  }
                  memcpy(*(void **)(puVar27 + 0x10),local_168 + 5,(ulonglong)uVar26);
                }
                else {
                  local_168[1] = local_168[1] & 0xffffff7f;
                }
                *(char *)((longlong)puVar27 + 3) = (char)puVar18[1];
                *(char *)(puVar27 + 2) = (char)puVar18[2];
                uVar26 = puVar18[3];
                *(uint *)(puVar27 + 8) = uVar26;
                if (puVar21[4] == 0x42264) {
                  uVar28 = puVar18[3];
                  if (uVar26 < puVar18[3]) {
                    uVar28 = uVar26;
                  }
                  memcpy(*(void **)(puVar27 + 0xc),*(void **)(param_1 + 0x208),(ulonglong)uVar28);
                  *(undefined1 *)(param_1 + 0x214) = 0;
                }
              }
              goto LAB_1c000fbcd;
            }
LAB_1c0010735:
            uVar25 = 9;
LAB_1c000fbca:
            puVar21[5] = uVar25;
            goto LAB_1c000fbcd;
          }
          if (uVar26 == 0x42268) goto LAB_1c001095a;
          if (uVar26 != 0x4226c) goto LAB_1c001092b;
          uVar29 = 1;
          ArcPrintf(param_1,1,(byte *)"* - IOCTL MESSAGE: %s \n",
                    (ulonglong)*puVar21 + (longlong)puVar21);
        }
LAB_1c001186b:
        uVar25 = (uint)uVar29;
        puVar21[5] = uVar25;
      }
LAB_1c000fbcd:
      return (ulonglong)uVar25;
    }
  }
  uVar13 = 1;
LAB_1c000fb25:
  puVar21[5] = (uint)uVar13;
  return uVar13;
}



===== BuildRawScatterGather64 @ 1c00118b0 =====

void BuildRawScatterGather64
               (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,
               ushort *param_5)

{
  ushort *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  puVar1 = param_5;
  uVar4 = *(uint *)(param_3 + 0x10);
  uVar5 = 0;
  if (param_4 == 0) {
    lVar3 = *(longlong *)(param_3 + 0x18);
  }
  else {
    lVar3 = param_4;
  }
  param_5[0] = 0;
  param_5[1] = 0;
  if (uVar4 != 0) {
    uVar6 = uVar5;
    if (param_4 != 0) {
      param_2 = 0;
    }
    do {
      uVar2 = StorPortGetPhysicalAddress(param_1,param_2,lVar3,&param_5);
      *(int *)(puVar1 + uVar6 * 6 + 2) = (int)uVar2;
      *(int *)(puVar1 + uVar6 * 6 + 4) = (int)((ulonglong)uVar2 >> 0x20);
      if (uVar4 < (uint)param_5) {
        param_5._0_4_ = uVar4;
      }
      uVar5 = (ulonglong)((int)uVar6 + 1);
      lVar3 = lVar3 + (ulonglong)(uint)param_5;
      *(uint *)(puVar1 + uVar6 * 6 + 6) = (uint)param_5;
      uVar4 = uVar4 - (uint)param_5;
      uVar6 = uVar5;
    } while (uVar4 != 0);
  }
  *puVar1 = (ushort)uVar5 & 0xff;
  return;
}



===== CSMIGetControllerConfig @ 1c0011968 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CSMIGetControllerConfig(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 auStackY_268 [32];
  ushort local_228 [8];
  uint local_218 [14];
  int local_1e0;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_268;
  lVar1 = *(longlong *)(param_2 + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0xb4) {
    *(undefined4 *)(lVar1 + 0x14) = 3;
  }
  else {
    *(undefined4 *)(param_1 + 0xaaa4) = 8;
    if (*(longlong *)(param_1 + 0x188) == 0) {
      local_218[3] = 0;
      *(longlong *)(param_1 + 0x188) = param_2;
      local_218[0] = 3;
      local_218[1] = 9;
      local_218[2] = 1;
      local_218[4] = 0xc;
      uVar2 = SendSynchFib(param_1,500,local_218,0x1e0,local_218,local_228,'\x01');
      if ((char)uVar2 != '\0') {
        if (local_1e0 == 0xb) {
          *(undefined4 *)(param_1 + 0xaaa4) = 8;
        }
        else if (local_1e0 == 0xc) {
          *(undefined4 *)(param_1 + 0xaaa4) = 2;
        }
        else {
          *(undefined1 *)(param_1 + 0xaa1e) = 0;
        }
      }
      *(undefined8 *)(param_1 + 0x188) = 0;
    }
    memcpy((void *)(lVar1 + 0x1c),(void *)(param_1 + 0xaa0c),0xb4);
    *(undefined4 *)(lVar1 + 0x14) = 0;
  }
  return 1;
}



===== CSMIGetRAIDConfig @ 1c0011a90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CSMIGetRAIDConfig(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 auStackY_438 [32];
  ushort local_3f8;
  ushort local_3f4 [2];
  int local_3f0;
  uint local_3e8 [5];
  undefined4 local_3d4;
  int local_3d0;
  undefined1 local_218 [8];
  int local_210;
  uint local_20c;
  undefined4 local_204;
  undefined1 local_1f8 [432];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_438;
  lVar2 = *(longlong *)(param_2 + 0x18);
  local_3f8 = 0;
  local_3f0 = 0;
  uVar4 = 1;
  if (*(longlong *)(param_1 + 0x188) == 0) {
    *(longlong *)(param_1 + 0x188) = param_2;
    if (*(uint *)(param_2 + 0x10) < 0xac) {
      *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x14) = 3;
    }
    else {
      puVar1 = (uint *)(lVar2 + 0x1c);
      if ((*puVar1 < 0xfe) &&
         ((*(uint *)(param_1 + 0x19cc + (ulonglong)*puVar1 * 0x28) & 0xfffffffd) != 0)) {
        local_3e8[0] = 2;
        local_3e8[1] = 0xd7;
        local_3e8[2] = *puVar1;
        uVar3 = SendSynchFib(param_1,500,local_3e8,0x1d0,local_218,local_3f4,'\x01');
        if (((char)uVar3 == '\0') || (local_210 == 199)) {
          *(undefined4 *)(lVar2 + 0x14) = 1;
        }
        else {
          *(undefined4 *)(lVar2 + 0x14) = 0;
          uVar6 = *(uint *)(param_2 + 0x10);
          if (local_20c != 0) {
            uVar5 = local_20c;
            iVar7 = local_3f0;
            do {
              local_3d4 = local_204;
              local_3e8[0] = 2;
              local_3e8[1] = 0x53;
              local_3d0 = iVar7;
              uVar3 = SendSynchFib(param_1,500,local_3e8,0x1d0,local_218,local_3f4,'\x01');
              if (((char)uVar3 == '\0') || (local_210 == 199)) {
                *(undefined4 *)(lVar2 + 0x14) = 1;
                break;
              }
              if (uVar5 < 0x1b0) {
                uVar8 = uVar6;
                if (uVar5 <= uVar6) {
                  uVar8 = uVar5;
                }
                if (uVar8 != 0) {
                  memcpy((void *)((ulonglong)local_3f8 + (longlong)puVar1),local_1f8,
                         (ulonglong)uVar8);
                }
                uVar5 = 0;
              }
              else {
                uVar8 = uVar6;
                if (0x1af < uVar6) {
                  uVar8 = 0x1b0;
                }
                if (uVar8 != 0) {
                  memcpy((void *)((ulonglong)local_3f8 + (longlong)puVar1),local_1f8,
                         (ulonglong)uVar8);
                  local_3f8 = local_3f8 + (short)uVar8;
                }
                iVar7 = local_3f0 + 1;
                uVar5 = uVar5 - 0x1b0;
                uVar6 = uVar6 - uVar8;
                local_3f0 = iVar7;
              }
            } while (uVar5 != 0);
          }
          local_3d4 = local_204;
          local_3e8[0] = 2;
          local_3e8[1] = 0x54;
          SendSynchFib(param_1,500,local_3e8,0x1d0,local_218,local_3f4,'\x01');
        }
      }
      else {
        *(undefined4 *)(lVar2 + 0x14) = 1000;
      }
    }
    *(undefined8 *)(param_1 + 0x188) = 0;
  }
  else {
    uVar4 = 5;
  }
  return uVar4;
}



===== CSMIGetRAIDInfo @ 1c0011d1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CSMIGetRAIDInfo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int *piVar2;
  undefined8 uVar3;
  ushort uVar4;
  longlong lVar5;
  undefined1 auStackY_278 [32];
  ushort local_238 [8];
  uint local_228 [6];
  int local_210;
  int local_20c;
  int local_1f0;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_278;
  lVar1 = *(longlong *)(param_2 + 0x18);
  uVar4 = 0;
  if (*(uint *)(param_2 + 0x10) < 100) {
    *(undefined4 *)(lVar1 + 0x14) = 3;
  }
  else {
    piVar2 = (int *)(param_1 + 0x19cc);
    lVar5 = 0xfe;
    do {
      if (*piVar2 == 1) {
        uVar4 = uVar4 + 1;
      }
      piVar2 = piVar2 + 10;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    *(uint *)(lVar1 + 0x1c) = (uint)uVar4;
    *(undefined4 *)(lVar1 + 0x20) = 0x80;
    if (*(longlong *)(param_1 + 0x188) == 0) {
      *(longlong *)(param_1 + 0x188) = param_2;
      local_228[0] = 3;
      local_228[1] = 9;
      local_228[2] = 1;
      local_228[3] = 0;
      local_228[4] = 0xc;
      uVar3 = SendSynchFib(param_1,500,local_228,0x1e0,local_228,local_238,'\x01');
      if ((char)uVar3 != '\0') {
        if (local_1f0 == 0xb) {
          *(undefined4 *)(lVar1 + 0x20) = *(undefined4 *)(param_1 + 0x13c4);
        }
        else if (local_1f0 == 0xc) {
          *(undefined4 *)(lVar1 + 0x20) = 0x80;
        }
        else {
          *(int *)(lVar1 + 0x20) = local_210 * local_20c;
        }
      }
      *(undefined8 *)(param_1 + 0x188) = 0;
    }
    *(undefined4 *)(lVar1 + 0x14) = 0;
  }
  return 1;
}



===== CSMIGetPhyInfo @ 1c0011e50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CSMIGetPhyInfo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auStackY_278 [32];
  ushort local_238 [8];
  uint local_228 [10];
  undefined1 local_200 [472];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_278;
  lVar1 = *(longlong *)(param_2 + 0x18);
  local_238[0] = 0;
  uVar3 = 1;
  if (*(longlong *)(param_1 + 0x188) == 0) {
    *(longlong *)(param_1 + 0x188) = param_2;
    if (*(uint *)(param_2 + 0x10) < 0xa04) {
      *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x14) = 3;
    }
    else {
      memset(local_228,0,0x200);
      local_228[0] = 3;
      local_228[1] = 9;
      local_228[2] = 1;
      local_228[3] = 0;
      local_228[4] = 0x70;
      uVar2 = SendSynchFib(param_1,500,local_228,0x1e0,local_228,local_238,'\x01');
      if ((char)uVar2 == '\0') {
        *(undefined4 *)(lVar1 + 0x14) = 1;
      }
      else {
        memcpy((void *)(lVar1 + 0x1c),local_200,(ulonglong)local_238[0]);
        *(undefined4 *)(lVar1 + 0x14) = 0;
      }
    }
    *(undefined8 *)(param_1 + 0x188) = 0;
  }
  else {
    uVar3 = 5;
  }
  return uVar3;
}



===== CSMIGetSATASignature @ 1c0011f74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CSMIGetSATASignature(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auStackY_268 [32];
  ushort local_228 [8];
  uint local_218 [7];
  undefined4 local_1fc;
  undefined1 local_1f0 [472];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_268;
  lVar1 = *(longlong *)(param_2 + 0x18);
  uVar3 = 1;
  if (*(longlong *)(param_1 + 0x188) == 0) {
    *(longlong *)(param_1 + 0x188) = param_2;
    if (*(uint *)(param_2 + 0x10) < 0x18) {
      *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x14) = 3;
    }
    else {
      memset(local_218,0,0x200);
      local_218[3] = 0;
      local_218[0] = 3;
      local_218[1] = 9;
      local_218[2] = 1;
      local_218[4] = 0x71;
      uVar2 = SendSynchFib(param_1,500,local_218,0x40,local_218,local_228,'\x01');
      if ((char)uVar2 == '\0') {
        *(undefined4 *)(lVar1 + 0x14) = 1;
      }
      else {
        memcpy((void *)(lVar1 + 0x1c),local_1f0,0x18);
        *(undefined4 *)(lVar1 + 0x14) = local_1fc;
      }
    }
    *(undefined8 *)(param_1 + 0x188) = 0;
  }
  else {
    uVar3 = 5;
  }
  return uVar3;
}



===== CSMIGetSCSIAddress @ 1c001208c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CSMIGetSCSIAddress(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auStackY_278 [32];
  ushort local_238 [8];
  uint local_228 [10];
  undefined4 local_200 [118];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_278;
  lVar1 = *(longlong *)(param_2 + 0x18);
  uVar3 = 1;
  if (*(longlong *)(param_1 + 0x188) == 0) {
    *(longlong *)(param_1 + 0x188) = param_2;
    if (*(uint *)(param_2 + 0x10) < 0x14) {
      *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x14) = 3;
    }
    else {
      memset(local_228,0,0x200);
      memcpy(local_200,(void *)(lVar1 + 0x1c),0x14);
      local_228[3] = 0;
      local_228[0] = 3;
      local_228[1] = 9;
      local_228[2] = 1;
      local_228[4] = 0x72;
      uVar2 = SendSynchFib(param_1,500,local_228,0x44,local_228,local_238,'\x01');
      if ((char)uVar2 == '\0') {
        *(undefined4 *)(lVar1 + 0x14) = 1;
      }
      else {
        memcpy((void *)(lVar1 + 0x1c),local_200,0x14);
        *(undefined1 *)(lVar1 + 0x2c) = *(undefined1 *)(param_1 + 0xaa1c);
        *(undefined4 *)(lVar1 + 0x14) = local_200[0];
      }
    }
    *(undefined8 *)(param_1 + 0x188) = 0;
  }
  else {
    uVar3 = 5;
  }
  return uVar3;
}



===== CSMIGetDeviceAddress @ 1c00121d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CSMIGetDeviceAddress(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auStackY_278 [32];
  ushort local_238 [8];
  uint local_228 [10];
  undefined4 local_200 [118];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_278;
  lVar1 = *(longlong *)(param_2 + 0x18);
  uVar3 = 1;
  if (*(longlong *)(param_1 + 0x188) == 0) {
    *(longlong *)(param_1 + 0x188) = param_2;
    if (*(uint *)(param_2 + 0x10) < 0x14) {
      *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x14) = 3;
    }
    else {
      memset(local_228,0,0x200);
      memcpy(local_200,(void *)(lVar1 + 0x20),0x14);
      local_228[3] = 0;
      local_228[0] = 3;
      local_228[1] = 9;
      local_228[2] = 1;
      local_228[4] = 0x73;
      uVar2 = SendSynchFib(param_1,500,local_228,0x44,local_228,local_238,'\x01');
      if ((char)uVar2 == '\0') {
        *(undefined4 *)(lVar1 + 0x14) = 1;
      }
      else {
        memcpy((void *)(lVar1 + 0x20),local_200,0x14);
        *(undefined4 *)(lVar1 + 0x14) = local_200[0];
      }
    }
    *(undefined8 *)(param_1 + 0x188) = 0;
  }
  else {
    uVar3 = 5;
  }
  return uVar3;
}



===== CSMISTPPassThru @ 1c0012308 =====

undefined8 CSMISTPPassThru(longlong param_1,longlong param_2)

{
  uint *_Dst;
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  ushort local_res8 [4];
  uint local_res10 [2];
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  _Dst = (uint *)(param_1 + 0x15a8);
  uVar4 = 0;
  local_res10[0] = 0;
  if (*(longlong *)(param_1 + 0x188) != 0) {
    return 5;
  }
  *(longlong *)(param_1 + 0x188) = param_2;
  if (*(uint *)(param_2 + 0x10) < 0x8c) {
    *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x14) = 3;
  }
  else {
    if ((*(uint *)(lVar1 + 0x40) & 0xa0) == 0) {
      *(longlong *)(param_1 + 0x188) = param_2;
      memset(_Dst,0,0x44);
      memset((void *)(param_1 + 0x17a8),0,0x24);
      *_Dst = *(uint *)(lVar1 + 0x40) >> 9 & 1;
      *(undefined4 *)(param_1 + 0x15bc) = *(undefined4 *)(param_2 + 0xc);
      *(undefined4 *)(param_1 + 0x15b8) = *(undefined4 *)(param_2 + 0x14);
      *(undefined4 *)(param_1 + 0x15c4) = 0;
      *(undefined4 *)(param_1 + 0x15ac) = 0;
      *(uint *)(param_1 + 0x15b0) = (uint)*(byte *)(lVar1 + 0x1c);
      *(undefined4 *)(param_1 + 0x15b4) = 0;
      *(undefined4 *)(param_1 + 0x15c0) = *(undefined4 *)(lVar1 + 0x44);
      *(undefined1 *)(param_1 + 0x15cc) = *(undefined1 *)(lVar1 + 0x2e);
      *(undefined1 *)(param_1 + 0x15cd) = *(undefined1 *)(lVar1 + 0x2f);
      *(undefined1 *)(param_1 + 0x15ce) = *(undefined1 *)(lVar1 + 0x30);
      *(undefined1 *)(param_1 + 0x15cf) = *(undefined1 *)(lVar1 + 0x31);
      *(undefined1 *)(param_1 + 0x15d0) = *(undefined1 *)(lVar1 + 0x32);
      *(undefined1 *)(param_1 + 0x15d1) = *(undefined1 *)(lVar1 + 0x33);
      *(undefined1 *)(param_1 + 0x15d2) = *(undefined1 *)(lVar1 + 0x34);
      *(undefined1 *)(param_1 + 0x15d3) = *(undefined1 *)(lVar1 + 0x35);
      *(undefined1 *)(param_1 + 0x15d4) = *(undefined1 *)(lVar1 + 0x36);
      *(undefined1 *)(param_1 + 0x15d5) = *(undefined1 *)(lVar1 + 0x37);
      *(undefined1 *)(param_1 + 0x15d6) = *(undefined1 *)(lVar1 + 0x38);
      *(undefined1 *)(param_1 + 0x15d7) = *(undefined1 *)(lVar1 + 0x39);
      *(undefined1 *)(param_1 + 0x15d9) = *(undefined1 *)(lVar1 + 0x3b);
      *(undefined4 *)(param_1 + 0x15c8) = 0xe;
      *(undefined2 *)(param_1 + 0x15de) = 0;
      *(undefined4 *)(param_1 + 0x15bc) = 0;
      uVar5 = *(uint *)(lVar1 + 0x44);
      if (uVar5 != 0) {
        lVar6 = lVar1 + 0xa4;
        do {
          uVar2 = StorPortGetPhysicalAddress(param_1,param_2,lVar6,local_res10);
          uVar3 = (ulonglong)uVar4;
          *(int *)(param_1 + 0x15e0 + uVar3 * 0xc) = (int)uVar2;
          *(int *)(param_1 + 0x15e4 + uVar3 * 0xc) = (int)((ulonglong)uVar2 >> 0x20);
          if (uVar5 < local_res10[0]) {
            local_res10[0] = uVar5;
          }
          uVar4 = uVar4 + 1;
          lVar6 = lVar6 + (ulonglong)local_res10[0];
          *(uint *)(param_1 + 0x15e8 + uVar3 * 0xc) = local_res10[0];
          uVar5 = uVar5 - local_res10[0];
        } while (uVar5 != 0);
        *(short *)(param_1 + 0x15dc) = (short)uVar4;
        *(uint *)(param_1 + 0x15bc) =
             (-(uint)((*(byte *)(lVar1 + 0x40) & 1) != 0) & 0xffffffc0) + 0x80;
      }
      uVar2 = SendSynchFib(param_1,0x25a,_Dst,0x44,(void *)(param_1 + 0x17a8),local_res8,'\x01');
      if ((char)uVar2 != '\0') {
        *(undefined1 *)(lVar1 + 0x48) = 0;
        *(undefined1 *)(lVar1 + 0x4e) = *(undefined1 *)(param_1 + 0x17bc);
        *(undefined4 *)(lVar1 + 0xa0) = *(undefined4 *)(param_1 + 0x17b4);
        *(undefined4 *)(lVar1 + 0x14) = 0;
        goto LAB_1c00124fd;
      }
    }
    *(undefined4 *)(lVar1 + 0x14) = 1;
  }
LAB_1c00124fd:
  *(undefined8 *)(param_1 + 0x188) = 0;
  return 1;
}



===== HandleCSMI @ 1c0012528 =====

undefined8 HandleCSMI(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  uVar1 = *(uint *)(lVar2 + 0x10);
  if (uVar1 < 0x15) {
    if (uVar1 == 0x14) {
      uVar3 = CSMIGetPhyInfo(param_1,param_2);
      return uVar3;
    }
    if (uVar1 == 1) {
      if (*(uint *)(param_2 + 0x10) < 0xb0) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
        return 1;
      }
      memcpy((void *)(lVar2 + 0x1c),"arcsas.sys",6);
      memcpy((void *)(lVar2 + 0x6d),"Adaptec RAID Storport Driver",0x1d);
      *(undefined4 *)(lVar2 + 0xbe) = 0x50007;
      *(undefined4 *)(lVar2 + 0xc2) = 0x7d30;
      *(undefined4 *)(lVar2 + 0xc6) = 0x520000;
      *(undefined4 *)(lVar2 + 0x14) = 0;
      return 1;
    }
    if (uVar1 == 2) {
      uVar3 = CSMIGetControllerConfig(param_1,param_2);
      return uVar3;
    }
    if (uVar1 == 3) {
      if (*(uint *)(param_2 + 0x10) < 0x24) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
        return 1;
      }
      if (*(int *)(param_1 + 0x1d0) == 2) {
        *(undefined4 *)(lVar2 + 0x1c) = 2;
      }
      else if (*(int *)(param_1 + 0x1d0) == 0) {
        *(undefined8 *)(lVar2 + 0x1c) = 3;
      }
      else {
        *(undefined4 *)(lVar2 + 0x1c) = 1;
      }
      *(undefined4 *)(lVar2 + 0x14) = 0;
      return 1;
    }
    if (uVar1 == 10) {
      uVar3 = CSMIGetRAIDInfo(param_1,param_2);
      return uVar3;
    }
    if (uVar1 == 0xb) {
      uVar3 = CSMIGetRAIDConfig(param_1,param_2);
      return uVar3;
    }
  }
  else {
    if (uVar1 == 0x15) {
      *(undefined4 *)(lVar2 + 0x14) = 2000;
      return 1;
    }
    if (uVar1 == 0x19) {
      uVar3 = CSMISTPPassThru(param_1,param_2);
      return uVar3;
    }
    if (uVar1 == 0x1a) {
      uVar3 = CSMIGetSATASignature(param_1,param_2);
      return uVar3;
    }
    if (uVar1 == 0x1b) {
      uVar3 = CSMIGetSCSIAddress(param_1,param_2);
      return uVar3;
    }
    if (uVar1 == 0x1c) {
      uVar3 = CSMIGetDeviceAddress(param_1,param_2);
      return uVar3;
    }
  }
  *(undefined4 *)(lVar2 + 0x14) = 2;
  return 1;
}



===== FreeConsumerProducerAif @ 1c0012690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FreeConsumerProducerAif(longlong param_1,uint *param_2)

{
  ulonglong *puVar1;
  uint uVar2;
  uint *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  char local_res8 [8];
  uint local_res10 [2];
  undefined1 local_a8 [32];
  ulonglong *local_88;
  uint *local_80;
  
  puVar3 = *(uint **)(param_1 + 0x20);
  uVar6 = 0;
  local_res8[0] = '\0';
  if (*puVar3 < *(uint *)(param_1 + 0x28)) {
    *puVar3 = *puVar3 + 1;
  }
  else {
    *puVar3 = 1;
  }
  param_2[8] = 0;
  puVar1 = (ulonglong *)(param_1 + 0x658);
  uVar2 = *param_2;
  uVar5 = (ulonglong)uVar2;
  if (uVar2 != 0) {
    if (((*(char *)((longlong)param_2 + 6) != '\x01') ||
        (*(ushort *)((longlong)param_2 + 10) < 0x24)) || ((uVar2 & 0x40) == 0)) goto LAB_1c001275e;
    *(undefined2 *)(param_2 + 2) = 0x24;
    *param_2 = uVar2 | 0x400;
    local_88 = puVar1;
    local_80 = param_2;
    uVar5 = GetQueueEntry((longlong)local_a8,local_res10,3,local_res8);
    if ((char)uVar5 == '\0') goto LAB_1c001275e;
    uVar5 = *puVar1;
    lVar4 = *(longlong *)(param_1 + 0x678);
    **(int **)(uVar5 + 0x108) = local_res10[0] + 1;
    if (local_res8[0] == '\0') {
      uVar5 = (**(code **)(*(longlong *)(lVar4 + 0x1320) + 0x18))(lVar4,puVar1,3);
    }
  }
  uVar6 = 1;
LAB_1c001275e:
  return CONCAT71((int7)(uVar5 >> 8),uVar6);
}



===== GetConsumerProducerCompletedFib @ 1c0012780 =====

undefined8 GetConsumerProducerCompletedFib(longlong param_1,longlong *param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint *puVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  uVar1 = **(uint **)(param_1 + 0x50);
  puVar4 = *(uint **)(param_1 + 0x48);
  if (*puVar4 != uVar1) {
    puVar4 = *(uint **)(param_1 + 0x38);
    if (*(int *)(param_1 + 0x1d0) != 2) {
      uVar1 = puVar4[(ulonglong)(uVar1 & -(uint)(uVar1 < *(uint *)(param_1 + 0x58))) * 2 + 1];
      uVar3 = uVar1 >> 2;
      lVar2 = *(longlong *)(param_1 + 0x6050 + (ulonglong)uVar3 * 8);
      *param_3 = lVar2;
      *param_2 = *(longlong *)(lVar2 + 0x28);
      *(undefined8 *)(param_1 + 0x6050 + (ulonglong)uVar3 * 8) = 0;
      puVar4 = *(uint **)(param_1 + 0x50);
      uVar3 = *puVar4;
      if (uVar3 < *(uint *)(param_1 + 0x58)) {
        uVar3 = uVar3 + 1;
        *puVar4 = uVar3;
      }
      else {
        *puVar4 = 1;
      }
      puVar4 = (uint *)(ulonglong)uVar3;
      if ((uVar1 & 1) != 0) {
        *(undefined4 *)(*param_2 + 0x20) = 0;
        puVar4 = (uint *)*param_2;
        *puVar4 = *puVar4 | 0x200;
      }
      uVar5 = 1;
    }
  }
  return CONCAT71((int7)((ulonglong)puVar4 >> 8),uVar5);
}



===== GetEntry @ 1c001280c =====

undefined1
GetEntry(longlong param_1,int param_2,longlong *param_3,uint *param_4,undefined1 *param_5)

{
  uint uVar1;
  longlong lVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  lVar2 = **(longlong **)(param_1 + 0x20);
  if (param_2 == 5) {
    uVar5 = **(uint **)(lVar2 + 0xd8);
    puVar3 = *(uint **)(lVar2 + 0xe0);
    uVar4 = -(uint)(uVar5 < 0x200) & uVar5;
    *param_4 = uVar4;
    uVar1 = *puVar3;
    if (uVar4 + 1 != uVar1) {
      *param_3 = *(longlong *)(lVar2 + 200) + (ulonglong)uVar4 * 8;
      if (uVar5 == uVar1) {
        return 1;
      }
      uVar5 = uVar5 - 1;
      if (uVar5 == 0) {
        uVar5 = 0x200;
      }
      if (uVar5 == uVar1) {
        return 1;
      }
      *param_5 = 1;
      return 1;
    }
  }
  else {
    if (param_2 != 3) {
      return 0;
    }
    uVar5 = **(uint **)(lVar2 + 0x108);
    puVar3 = *(uint **)(lVar2 + 0x110);
    uVar4 = -(uint)(uVar5 < 8) & uVar5;
    *param_4 = uVar4;
    uVar1 = *puVar3;
    if (uVar4 + 1 != uVar1) {
      *param_3 = *(longlong *)(lVar2 + 0xf8) + (ulonglong)uVar4 * 8;
      if (uVar5 == uVar1) {
        return 1;
      }
      uVar5 = uVar5 - 1;
      if (uVar5 == 0) {
        uVar5 = 8;
      }
      if (uVar5 == uVar1) {
        return 1;
      }
      *param_5 = 1;
      return 1;
    }
  }
  return 0;
}



===== GetMessageUnitQueueCompletedFib @ 1c00128f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GetMessageUnitQueueCompletedFib(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x40))();
  return;
}



===== GetQueueEntry @ 1c0012904 =====

ulonglong GetQueueEntry(longlong param_1,uint *param_2,int param_3,undefined1 *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  ulonglong in_RAX;
  ulonglong uVar4;
  undefined7 extraout_var;
  uint *local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  uVar2 = 0;
  if (param_3 == 5) {
    do {
      uVar4 = uVar2;
      cVar3 = GetEntry(param_1,5,(longlong *)&local_res8,param_2,param_4);
      if (cVar3 != '\0') {
        *local_res8 = (uint)*(ushort *)(lVar1 + 8);
        in_RAX = (ulonglong)*(uint *)(param_1 + 0x10);
        local_res8[1] = *(uint *)(param_1 + 0x10);
        goto LAB_1c00129d7;
      }
      StorPortStallExecution(100);
      uVar2 = (ulonglong)((uint)uVar4 + 1);
    } while ((uint)uVar4 < 0xb);
  }
  else {
    if (param_3 != 3) {
LAB_1c00129d7:
      return CONCAT71((int7)(in_RAX >> 8),1);
    }
    do {
      uVar4 = uVar2;
      cVar3 = GetEntry(param_1,3,(longlong *)&local_res8,param_2,param_4);
      in_RAX = CONCAT71(extraout_var,cVar3);
      if (cVar3 != '\0') {
        *local_res8 = (uint)*(ushort *)(lVar1 + 8);
        local_res8[1] = *(uint *)(lVar1 + 0xc);
        *(undefined4 *)(lVar1 + 0x10) = *(undefined4 *)(lVar1 + 0xc);
        goto LAB_1c00129d7;
      }
      StorPortStallExecution(100);
      uVar2 = (ulonglong)((uint)uVar4 + 1);
    } while ((uint)uVar4 < 0xb);
  }
  return uVar4 & 0xffffffffffffff00;
}



===== ProcessAif @ 1c00129ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ProcessAif(longlong param_1,void *param_2,undefined8 param_3,ulonglong param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  ulonglong uVar5;
  void *pvVar6;
  undefined1 uVar7;
  short sVar8;
  char *pcVar9;
  undefined1 auStackY_b8 [32];
  undefined4 in_stack_ffffffffffffff68;
  undefined4 in_stack_ffffffffffffff6c;
  wchar_t local_88 [20];
  short sStack_60;
  short sStack_5e;
  short sStack_5c;
  short sStack_5a;
  short sStack_58;
  short sStack_56;
  short sStack_54;
  short sStack_52;
  undefined2 uStack_50;
  undefined4 uStack_4e;
  short sStack_4a;
  ulonglong local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar7 = 0;
  pvVar6 = param_2;
  if ((*(uint *)(param_1 + 0xbadc) & 2) != 0) {
    in_stack_ffffffffffffff68 = *(undefined4 *)((longlong)param_2 + 0x28);
    param_4 = (ulonglong)*(uint *)((longlong)param_2 + 0x20);
    pvVar6 = (void *)0x4;
    ArcPrintf(param_1,4,(byte *)"* ProcessAif: AIF cmd: %d, AIF sub-cmd: %d\n",param_4);
  }
  if (*(char *)(param_1 + 0x6048) == '\0') {
    iVar1 = *(int *)((longlong)param_2 + 0x20);
    if (iVar1 == 1) {
      iVar1 = *(int *)((longlong)param_2 + 0x28);
      if (iVar1 == 0xf) {
        uVar2 = *(uint *)((longlong)param_2 + 0x2c);
        sStack_60 = 0x20;
        sStack_5e = 0x23;
        builtin_wcsncpy(local_88,L"Logical Drive added,",0x14);
        sStack_54 = 0;
        sVar8 = (short)(uVar2 / 10);
        sStack_56 = (short)uVar2 + sVar8 * -10 + 0x30;
        sStack_58 = sVar8 + (short)((uVar2 / 10) / 10) * -10 + 0x30;
        sStack_5a = (short)(uVar2 / 100) + (short)((uVar2 / 100) / 10) * -10 + 0x30;
        uVar5 = (ulonglong)(uVar2 / 1000) / 10;
        sStack_5c = (short)(uVar2 / 1000) + (short)uVar5 * -10 + 0x30;
        if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) && (*(char *)(param_1 + 0xaad6) != '\0'))
        {
          ArcLogEventString(param_1,uVar5,0x601a001a,0x1a,
                            CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),
                            (char)local_88);
        }
        pcVar9 = "AIF EVENT: Container #%d added\n";
      }
      else {
        if (iVar1 != 0x10) {
          if (iVar1 == 0x1e) {
            if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) &&
               (*(char *)(param_1 + 0xaad6) != '\0')) {
              param_4 = 0x16;
              ArcLogEventString(param_1,pvVar6,0x601a0016,0x16,
                                CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),0);
            }
            *(undefined4 *)(param_1 + 0x6044) = 3;
            pcVar9 = "AIF EVENT: a JBOD added\n";
            *(undefined1 *)(param_1 + 0x5e06) = 1;
            uVar7 = 1;
          }
          else if (iVar1 == 0x1f) {
            if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) &&
               (*(char *)(param_1 + 0xaad6) != '\0')) {
              param_4 = 0x17;
              ArcLogEventString(param_1,pvVar6,0xa01a0017,0x17,
                                CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),0x50);
            }
            *(undefined4 *)(param_1 + 0x6044) = 3;
            pcVar9 = "AIF EVENT: a JBOD removed\n";
            *(undefined1 *)(param_1 + 0x5e06) = 1;
            uVar7 = 1;
          }
          else {
            if (iVar1 != 0x2a) goto LAB_1c0013350;
            iVar1 = *(int *)((longlong)param_2 + 0x2c);
            if (iVar1 == 1) {
              if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) &&
                 (*(char *)(param_1 + 0xaad6) != '\0')) {
                param_4 = 0x24;
                ArcLogEventString(param_1,pvVar6,0xe01a0024,0x24,
                                  CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),0x30
                                 );
              }
              pcVar9 = "AIF EVENT: Temperature has crossed recommended operating limit\n";
            }
            else if (iVar1 == 2) {
              if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) &&
                 (*(char *)(param_1 + 0xaad6) != '\0')) {
                param_4 = 0x25;
                ArcLogEventString(param_1,pvVar6,0xa01a0025,0x25,
                                  CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),0xb0
                                 );
              }
              pcVar9 = "AIF EVENT: Temperature is in the warning zone. Attention required\n";
            }
            else if (iVar1 == 3) {
              if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) &&
                 (*(char *)(param_1 + 0xaad6) != '\0')) {
                param_4 = 0x20;
                ArcLogEventString(param_1,pvVar6,0xa01a0020,0x20,
                                  CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),0x90
                                 );
              }
              pcVar9 = "AIF EVENT: Super cap health is low. Recommended to change supercap soon\n";
            }
            else if (iVar1 == 4) {
              if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) &&
                 (*(char *)(param_1 + 0xaad6) != '\0')) {
                param_4 = 0x21;
                ArcLogEventString(param_1,pvVar6,0xe01a0021,0x21,
                                  CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),0x10
                                 );
              }
              pcVar9 = "AIF EVENT: Super cap health is bad. Please change Supercap\n";
            }
            else if (iVar1 == 7) {
              if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) &&
                 (*(char *)(param_1 + 0xaad6) != '\0')) {
                param_4 = 0x1f;
                ArcLogEventString(param_1,pvVar6,0xe01a001f,0x1f,
                                  CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),0);
              }
              pcVar9 = "AIF EVENT: Hardware not present- Backup not ready\n";
            }
            else if (iVar1 == 8) {
              if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) &&
                 (*(char *)(param_1 + 0xaad6) != '\0')) {
                param_4 = 0x23;
                ArcLogEventString(param_1,pvVar6,0x601a0023,0x23,
                                  CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),0xc0
                                 );
              }
              pcVar9 = "AIF EVENT: Temperature Back to Normal\n";
            }
            else {
              if (iVar1 != 10) goto LAB_1c0013350;
              if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) &&
                 (*(char *)(param_1 + 0xaad6) != '\0')) {
                param_4 = 0x22;
                ArcLogEventString(param_1,pvVar6,0xe01a0022,0x22,
                                  CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),0x80
                                 );
              }
              pcVar9 = "AIF EVENT: Cache data loss\n";
            }
          }
          ArcPrintf(param_1,4,(byte *)pcVar9,param_4);
          goto LAB_1c0013350;
        }
        uVar2 = *(uint *)((longlong)param_2 + 0x2c);
        uStack_50 = 0;
        builtin_wcsncpy(local_88,L"Logical Drive delete",0x14);
        sVar8 = (short)(uVar2 / 10);
        sStack_60 = 100;
        sStack_5e = 0x2c;
        sStack_5c = 0x20;
        sStack_5a = 0x23;
        sStack_52 = (short)uVar2 + sVar8 * -10 + 0x30;
        sStack_54 = sVar8 + (short)((uVar2 / 10) / 10) * -10 + 0x30;
        sStack_56 = (short)(uVar2 / 100) + (short)((uVar2 / 100) / 10) * -10 + 0x30;
        uVar5 = (ulonglong)(uVar2 / 1000) / 10;
        sStack_58 = (short)(uVar2 / 1000) + (short)uVar5 * -10 + 0x30;
        if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) && (*(char *)(param_1 + 0xaad6) != '\0'))
        {
          ArcLogEventString(param_1,uVar5,0xa01a001b,0x1b,
                            CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),
                            (char)local_88);
        }
        pcVar9 = "AIF EVENT: Container #%d removed\n";
      }
    }
    else {
      if (iVar1 == 2) {
        if ((*(int *)((longlong)param_2 + 0x2c) == 0x65) &&
           ((*(longlong *)((longlong)param_2 + 0x48) == *(longlong *)((longlong)param_2 + 0x40) ||
            (*(int *)((longlong)param_2 + 0x38) == 1)))) {
          *(undefined4 *)(param_1 + 0x6044) = 4;
        }
        goto LAB_1c0013350;
      }
      if (iVar1 != 4) goto LAB_1c0013350;
      iVar1 = *(int *)((longlong)param_2 + 0x28);
      if (iVar1 == 200) {
        uVar2 = *(uint *)((longlong)param_2 + 0x2c);
        builtin_wcsncpy(local_88,L"Array migration comp",0x14);
        sStack_58 = 100;
        sStack_56 = 0x2c;
        sStack_54 = 0x20;
        sStack_52 = 0x4c;
        uStack_50 = 0x44;
        uStack_4e = 0x230020;
        sStack_60 = 0x6c;
        sStack_5e = 0x65;
        sStack_5c = 0x74;
        sStack_5a = 0x65;
        sVar8 = (short)(uVar2 / 10);
        local_48 = (ulonglong)
                   CONCAT42(CONCAT22((short)uVar2 + sVar8 * -10 + 0x30,
                                     sVar8 + (short)((uVar2 / 10) / 10) * -10 + 0x30),
                            (short)(uVar2 / 100) + (short)((uVar2 / 100) / 10) * -10 + 0x30);
        uVar5 = (ulonglong)(uVar2 / 1000) / 10;
        sStack_4a = (short)(uVar2 / 1000) + (short)uVar5 * -10 + 0x30;
        if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) && (*(char *)(param_1 + 0xaad6) != '\0'))
        {
          ArcLogEventString(param_1,uVar5,0x601a001e,0x1e,
                            CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),
                            (char)local_88);
        }
        ArcPrintf(param_1,4,(byte *)"AIF EVENT: Container #%d Morph complete\n",(ulonglong)uVar2);
        uVar3 = 0;
        puVar4 = (uint *)(param_1 + 0x19e4);
        do {
          if (*puVar4 == uVar2) goto LAB_1c0012e1c;
          uVar3 = uVar3 + 1;
          puVar4 = puVar4 + 10;
        } while (uVar3 < 0xfe);
        goto LAB_1c0013350;
      }
      if (iVar1 == 0xc9) {
        uVar2 = *(uint *)((longlong)param_2 + 0x2c);
        builtin_wcsncpy(local_88,L"Array expansion comp",0x14);
        sStack_58 = 100;
        sStack_56 = 0x2c;
        sStack_54 = 0x20;
        sStack_52 = 0x4c;
        uStack_50 = 0x44;
        uStack_4e = 0x230020;
        sStack_60 = 0x6c;
        sStack_5e = 0x65;
        sStack_5c = 0x74;
        sStack_5a = 0x65;
        sVar8 = (short)(uVar2 / 10);
        local_48 = (ulonglong)
                   CONCAT42(CONCAT22((short)uVar2 + sVar8 * -10 + 0x30,
                                     sVar8 + (short)((uVar2 / 10) / 10) * -10 + 0x30),
                            (short)(uVar2 / 100) + (short)((uVar2 / 100) / 10) * -10 + 0x30);
        uVar5 = (ulonglong)(uVar2 / 1000) / 10;
        sStack_4a = (short)(uVar2 / 1000) + (short)uVar5 * -10 + 0x30;
        if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) && (*(char *)(param_1 + 0xaad6) != '\0'))
        {
          ArcLogEventString(param_1,uVar5,0x601a001d,0x1d,
                            CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),
                            (char)local_88);
        }
        ArcPrintf(param_1,4,(byte *)"AIF EVENT: Container #%d extend complete\n",(ulonglong)uVar2);
        uVar3 = 0;
        puVar4 = (uint *)(param_1 + 0x19e4);
        do {
          if (*puVar4 == uVar2) goto LAB_1c0012e1c;
          uVar3 = uVar3 + 1;
          puVar4 = puVar4 + 10;
        } while (uVar3 < 0xfe);
        goto LAB_1c0013350;
      }
      if (iVar1 != 0xcb) goto LAB_1c0013350;
      uVar2 = *(uint *)((longlong)param_2 + 0x2c);
      sStack_58 = 0;
      builtin_wcsncpy(local_88,L"Raw Drive removed, #",0x14);
      sVar8 = (short)(uVar2 / 10);
      sStack_5a = (short)uVar2 + sVar8 * -10 + 0x30;
      sStack_5c = sVar8 + (short)((uVar2 / 10) / 10) * -10 + 0x30;
      sStack_5e = (short)(uVar2 / 100) + (short)((uVar2 / 100) / 10) * -10 + 0x30;
      uVar5 = (ulonglong)(uVar2 / 1000) / 10;
      sStack_60 = (short)(uVar2 / 1000) + (short)uVar5 * -10 + 0x30;
      if (((*(uint *)(param_1 + 0xbad8) & 0x8800) == 0) && (*(char *)(param_1 + 0xaad6) != '\0')) {
        ArcLogEventString(param_1,uVar5,0xa01a001c,0x1c,
                          CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),
                          (char)local_88);
      }
      *(undefined1 *)(param_1 + 0x5e06) = 1;
      pcVar9 = "AIF EVENT: a RAW device #%d removed\n";
      uVar2 = *(uint *)((longlong)param_2 + 0x2c);
    }
    uVar7 = 1;
    ArcPrintf(param_1,4,(byte *)pcVar9,(ulonglong)uVar2);
  }
LAB_1c0013350:
  uVar2 = *(uint *)(param_1 + 0x19bc) + 1;
  uVar5 = (ulonglong)uVar2;
  if ((*(uint *)(param_1 + 0x19b8) != uVar2) &&
     ((uVar2 != *(uint *)(param_1 + 0x19ac) || (*(uint *)(param_1 + 0x19b8) != 0)))) {
    memcpy((void *)((ulonglong)*(uint *)(param_1 + 0x19bc) * 0x200 + *(longlong *)(param_1 + 0x19b0)
                   ),param_2,0x200);
    uVar3 = *(int *)(param_1 + 0x19bc) + 1;
    uVar2 = *(uint *)(param_1 + 0x19b8);
    if (uVar3 == *(uint *)(param_1 + 0x19ac)) {
      uVar3 = 0;
    }
    *(uint *)(param_1 + 0x19bc) = uVar3;
    if (uVar3 < uVar2) {
      uVar3 = (uVar3 - uVar2) + *(uint *)(param_1 + 0x19ac);
    }
    else {
      uVar3 = uVar3 - uVar2;
    }
    uVar5 = (ulonglong)uVar3;
    if (*(uint *)(param_1 + 0x19c0) < uVar3) {
      *(uint *)(param_1 + 0x19c0) = uVar3;
    }
  }
  return CONCAT71((int7)(uVar5 >> 8),uVar7);
LAB_1c0012e1c:
  uVar7 = 1;
  goto LAB_1c0013350;
}



===== SendConsumerProducerFib @ 1c0013400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SendConsumerProducerFib(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  char local_res10 [8];
  uint local_res18 [4];
  
  uVar4 = 0;
  local_res10[0] = '\0';
  uVar3 = GetQueueEntry(param_1,local_res18,5,local_res10);
  if ((char)uVar3 != '\0') {
    plVar1 = *(longlong **)(param_1 + 0x20);
    lVar2 = plVar1[4];
    **(int **)(*plVar1 + 0xd8) = local_res18[0] + 1;
    if (local_res10[0] == '\0') {
      (**(code **)(*(longlong *)(lVar2 + 0x1320) + 0x18))(lVar2,plVar1,1);
    }
    uVar4 = 1;
  }
  return uVar4;
}



===== SubDeQueueSortingQueue @ 1c0013474 =====

char SubDeQueueSortingQueue(longlong param_1,longlong param_2)

{
  char cVar1;
  short sVar2;
  ulonglong uVar3;
  
  cVar1 = '\x01';
  if (*(char *)(param_1 + 0xa918) == '\0') {
    cVar1 = SendFib(0x1f7 - (ushort)(*(int *)(param_1 + 0x8088) != 2),param_2,'\0');
  }
  else {
    uVar3 = QueueRawIoReadWriteRequest(param_1,param_2);
    if ((char)uVar3 == '\0') {
      DequeueRawIoReadWriteRequest(param_1,'\0',0);
      *(undefined1 *)(param_1 + 0xa918) = 1;
      uVar3 = QueueRawIoReadWriteRequest(param_1,param_2);
      if ((char)uVar3 == '\0') {
        cVar1 = SendFib(0x1f7 - (ushort)(*(int *)(param_1 + 0x8088) != 2),param_2,'\0');
        *(undefined1 *)(param_1 + 0xa918) = 0;
      }
    }
    sVar2 = GetOutstandingIoCnt(param_1);
    if ((((*(int *)(param_1 + 0xa910) != 0) || (*(int *)(param_1 + 0xa914) != 0)) && (sVar2 == 0))
       && (*(char *)(param_1 + 0xa970) == '\0')) {
      DequeueRawIoReadWriteRequest(param_1,'\0',0);
    }
  }
  return cVar1;
}



===== DeQueueSortingQueue @ 1c0013560 =====

ulonglong DeQueueSortingQueue(longlong param_1,ushort param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  byte bVar7;
  ushort uVar8;
  uint7 extraout_var;
  ushort uVar9;
  ulonglong uVar10;
  
  bVar7 = 1;
  uVar8 = GetOutstandingIoCnt(param_1);
  uVar9 = 0;
  do {
    if ((uVar9 == param_2) || (param_2 == 0xffff)) {
      uVar10 = (ulonglong)uVar9;
      lVar3 = *(longlong *)(param_1 + 0xbb10 + uVar10 * 8);
      if (lVar3 != 0) {
        if ((((*(char *)(param_1 + 0xa924) != '\0') && (*(uint *)(param_1 + 0xa908) <= (uint)uVar8))
            && (3 < *(uint *)(param_1 + 0xa118 + uVar10 * 4))) &&
           (*(uint *)(*(longlong *)(lVar3 + 0x18) + 0x10) <= *(uint *)(param_1 + 0xa91c))) {
          *(undefined1 *)(param_1 + 0xa918) = 1;
        }
        iVar2 = *(int *)(param_1 + 0xc300 + uVar10 * 4);
        lVar4 = *(longlong *)(lVar3 + 0x68);
        while (lVar4 != 0) {
          lVar5 = *(longlong *)(lVar3 + 0x68);
          cVar6 = SubDeQueueSortingQueue(param_1,lVar3);
          if (cVar6 == '\0') {
            return (ulonglong)extraout_var << 8;
          }
          piVar1 = (int *)(param_1 + 0xc300 + uVar10 * 4);
          *piVar1 = *piVar1 + -1;
          *(int *)(param_1 + 55000) = *(int *)(param_1 + 55000) + -1;
          *(undefined8 *)(param_1 + 0x9138 + uVar10 * 8) = *(undefined8 *)(lVar3 + 0x88);
          *(longlong *)(param_1 + 0xbb10 + uVar10 * 8) = lVar5;
          lVar3 = lVar5;
          lVar4 = *(longlong *)(lVar5 + 0x68);
        }
        bVar7 = SubDeQueueSortingQueue(param_1,lVar3);
        if (bVar7 != 0) {
          *(undefined8 *)(param_1 + 0xbb10 + uVar10 * 8) = 0;
          piVar1 = (int *)(param_1 + 0xc300 + uVar10 * 4);
          *piVar1 = *piVar1 + -1;
          *(int *)(param_1 + 55000) = *(int *)(param_1 + 55000) + -1;
          *(undefined8 *)(param_1 + 0x9138 + uVar10 * 8) = *(undefined8 *)(lVar3 + 0x88);
          *(undefined4 *)(param_1 + 0xd2e0 + uVar10 * 4) = 0;
          *(undefined8 *)(param_1 + 0xc6f8 + uVar10 * 8) = 0xdeadbeef;
          if (iVar2 == 1) {
            *(undefined4 *)(param_1 + 0xa118 + uVar10 * 4) = 0;
          }
        }
      }
    }
    uVar9 = uVar9 + 1;
  } while (uVar9 < 0xfe);
  return (ulonglong)bVar7;
}



===== CompleteAllSortingQueue @ 1c00136e8 =====

void CompleteAllSortingQueue(longlong param_1)

{
  int *piVar1;
  ushort uVar2;
  longlong lVar3;
  int *piVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  
  if (*(int *)(param_1 + 55000) != 0) {
    plVar6 = (longlong *)(param_1 + 0xbb10);
    lVar7 = 0xfe;
    piVar4 = (int *)(param_1 + 0xc300);
    do {
      if (*piVar4 != 0) {
        lVar3 = *plVar6;
        *plVar6 = 0;
        lVar5 = *(longlong *)(lVar3 + 0x68);
        uVar2 = *(ushort *)(*(longlong *)(lVar3 + 0x28) + 0x2c);
        CompleteQueuedRequest(param_1,lVar3,0xe);
        if (lVar5 == 0) {
          piVar1 = (int *)(param_1 + 0xc300 + (ulonglong)uVar2 * 4);
          *piVar1 = *piVar1 + -1;
          *(int *)(param_1 + 55000) = *(int *)(param_1 + 55000) + -1;
        }
        else {
          while( true ) {
            piVar1 = (int *)(param_1 + 0xc300 + (ulonglong)uVar2 * 4);
            *piVar1 = *piVar1 + -1;
            *(int *)(param_1 + 55000) = *(int *)(param_1 + 55000) + -1;
            if (lVar5 == 0) break;
            lVar3 = *(longlong *)(lVar5 + 0x68);
            CompleteQueuedRequest(param_1,lVar5,0xe);
            lVar5 = lVar3;
          }
        }
        plVar6[-0x53b] = 0;
        plVar6[0x17d] = 0xdeadbeef;
      }
      piVar4 = piVar4 + 1;
      plVar6 = plVar6 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
  }
  return;
}



===== QueueSortingQ @ 1c00137e4 =====

undefined8 QueueSortingQ(longlong param_1,longlong param_2)

{
  int *piVar1;
  ulonglong uVar2;
  ulonglong uVar4;
  ulonglong *puVar3;
  ulonglong *puVar5;
  ulonglong uVar6;
  
  uVar6 = (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x28) + 0x2c);
  *(int *)(param_1 + 0xe2c4) = *(int *)(param_1 + 0xe2c4) + 1;
  *(undefined4 *)(param_2 + 0x74) = 0;
  uVar2 = *(ulonglong *)(param_2 + 0x80);
  puVar5 = (ulonglong *)(param_1 + 0xbb10 + uVar6 * 8);
  if (*(ulonglong *)(param_1 + 0xc6f8 + uVar6 * 8) == uVar2) {
    *(undefined8 *)(param_1 + 0xc6f8 + uVar6 * 8) = 0xdeadbeef;
    *(undefined4 *)(param_1 + 0xd2e0 + uVar6 * 4) = 1;
  }
  uVar4 = *puVar5;
  if (uVar4 == 0) {
    *puVar5 = param_2;
    *(undefined8 *)(param_2 + 0x68) = 0;
  }
  else {
    if (*(ulonglong *)(uVar4 + 0x80) < *(ulonglong *)(param_2 + 0x88)) {
      do {
        puVar3 = (ulonglong *)(uVar4 + 0x68);
        while( true ) {
          if (*puVar3 == 0) {
            *puVar3 = param_2;
            *(undefined8 *)(param_2 + 0x68) = 0;
            uVar2 = *puVar5;
            if (*(ulonglong *)(uVar2 + 0x88) < *(ulonglong *)(param_2 + 0x80)) {
              piVar1 = (int *)(param_1 + 0xcee8 + uVar6 * 4);
              *piVar1 = *piVar1 + 1;
            }
            goto LAB_1c0013904;
          }
          uVar2 = *(ulonglong *)(param_2 + 0x80);
          if (*(ulonglong *)(*puVar5 + 0x88) < uVar2) break;
          if (*(ulonglong *)(*puVar5 + 0x88) != uVar2) {
            *(int *)(param_1 + 0xe2cc) = *(int *)(param_1 + 0xe2cc) + 1;
LAB_1c0013935:
            return uVar2 & 0xffffffffffffff00;
          }
          uVar2 = *puVar3;
          if (*(ulonglong *)(param_2 + 0x88) < *(ulonglong *)(uVar2 + 0x80)) {
            piVar1 = (int *)(param_1 + 0xcee8 + uVar6 * 4);
            *piVar1 = *piVar1 + 1;
          }
          else {
            if (*(ulonglong *)(param_2 + 0x88) != *(ulonglong *)(uVar2 + 0x80)) {
              *(int *)(param_1 + 0xe2c8) = *(int *)(param_1 + 0xe2c8) + 1;
              goto LAB_1c0013935;
            }
            piVar1 = (int *)(param_1 + 0xcee8 + uVar6 * 4);
            *piVar1 = *piVar1 + -1;
          }
          *(ulonglong *)(param_2 + 0x68) = *puVar3;
          *puVar5 = param_2;
        }
        uVar4 = *puVar3;
        puVar5 = puVar3;
      } while( true );
    }
    if (*(ulonglong *)(param_2 + 0x88) < *(ulonglong *)(uVar4 + 0x80)) {
      piVar1 = (int *)(param_1 + 0xcee8 + uVar6 * 4);
      *piVar1 = *piVar1 + 1;
    }
    uVar2 = *puVar5;
    *(ulonglong *)(param_2 + 0x68) = uVar2;
    *puVar5 = param_2;
  }
LAB_1c0013904:
  piVar1 = (int *)(param_1 + 0xc300 + uVar6 * 4);
  *piVar1 = *piVar1 + 1;
  *(int *)(param_1 + 55000) = *(int *)(param_1 + 55000) + 1;
  if (*(uint *)(param_1 + 0xc300 + uVar6 * 4) < 2) {
    if (*(int *)(param_1 + 0xd6dc) == 0) {
      uVar2 = RequestTimer(param_1,0x100,1000000,1);
      *(undefined4 *)(param_1 + 0xd6dc) = 1;
    }
  }
  else {
    *(undefined8 *)(param_1 + 0xc6f8 + uVar6 * 8) = 0xdeadbeef;
    *(undefined4 *)(param_1 + 0xd2e0 + uVar6 * 4) = 1;
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== CompleteBufferedRequest @ 1c001397c =====

void CompleteBufferedRequest(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_2 + 0x60);
  if (lVar2 == 0) {
    *(undefined8 *)
     (param_1 + 0x6050 +
     (ulonglong)(*(uint *)(*(longlong *)(param_2 + 0x28) + 0xc) >> 2 & 0x3ff) * 8) = 0;
    CompleteQueuedRequest(param_1,param_2,0xe);
    *(int *)(param_1 + 0xba14) = *(int *)(param_1 + 0xba14) + -1;
    *(short *)(param_1 + 0xba22) = *(short *)(param_1 + 0xba22) + 1;
  }
  else {
    *(undefined8 *)
     (param_1 + 0x6050 +
     (ulonglong)(*(uint *)(*(longlong *)(param_2 + 0x28) + 0xc) >> 2 & 0x3ff) * 8) = 0;
    while( true ) {
      CompleteQueuedRequest(param_1,param_2,0xe);
      *(int *)(param_1 + 0xba14) = *(int *)(param_1 + 0xba14) + -1;
      *(short *)(param_1 + 0xba22) = *(short *)(param_1 + 0xba22) + 1;
      if (lVar2 == 0) break;
      lVar1 = *(longlong *)(lVar2 + 0x60);
      *(undefined8 *)
       (param_1 + 0x6050 +
       (ulonglong)(*(uint *)(*(longlong *)(lVar2 + 0x28) + 0xc) >> 2 & 0x3ff) * 8) = 0;
      param_2 = lVar2;
      lVar2 = lVar1;
    }
  }
  return;
}



===== TryDeQueueIoList @ 1c0013a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TryDeQueueIoList(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  short sVar3;
  short *psVar4;
  ulonglong uVar5;
  ushort uVar6;
  short sVar7;
  undefined1 auStack_88 [30];
  short asStack_6a [2];
  undefined1 local_66 [62];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  asStack_6a[1] = 0;
  memset(local_66,0,0x3c);
  uVar1 = *(ushort *)(param_1 + 0xaad4);
  uVar6 = 1;
  sVar7 = 0;
  do {
    uVar5 = (ulonglong)uVar6;
    asStack_6a[uVar5] =
         *(short *)(param_1 + 0xb988 + uVar5 * 2) - *(short *)(param_1 + 0xb9c8 + uVar5 * 2);
    if (uVar1 <= uVar6) break;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x1f);
  if (1 < uVar1) {
    psVar4 = asStack_6a;
    uVar5 = (ulonglong)(ushort)(uVar1 - 1);
    do {
      psVar4 = psVar4 + 1;
      sVar7 = sVar7 + *psVar4;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  uVar6 = 0;
  sVar3 = *(short *)(param_1 + 0xba08) * (uVar1 - 1);
  if (sVar3 != sVar7) {
    do {
      lVar2 = *(longlong *)(param_1 + 0xba18);
      if (lVar2 == 0) break;
      *(undefined8 *)(param_1 + 0xba18) = *(undefined8 *)(lVar2 + 0x60);
      *(undefined8 *)(lVar2 + 0x60) = 0;
      *(int *)(param_1 + 0xba14) = *(int *)(param_1 + 0xba14) + -1;
      (**(code **)(*(longlong *)(param_1 + 0x1320) + 0x38))(param_1);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (ushort)(sVar3 - sVar7));
  }
  if (*(int *)(param_1 + 0xba14) == 0) {
    *(undefined8 *)(param_1 + 0xba18) = 0;
  }
  return;
}



===== SendMessageUnitQueueFib @ 1c0013b60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SendMessageUnitQueueFib(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 uVar4;
  longlong *plVar5;
  longlong lVar6;
  ulonglong uVar7;
  ushort uVar8;
  undefined1 auStack_88 [30];
  ushort auStack_6a [2];
  undefined1 local_66 [62];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((*(char *)(lVar2 + 0xaad6) != '\0') && (*(short *)(*(longlong *)(param_1 + 0x28) + 4) != 700))
  {
    auStack_6a[1] = 0;
    bVar3 = true;
    memset(local_66,0,0x3c);
    uVar1 = *(ushort *)(lVar2 + 0xaad4);
    uVar8 = 1;
    do {
      uVar7 = (ulonglong)uVar8;
      auStack_6a[uVar7] =
           *(short *)(lVar2 + 0xb988 + uVar7 * 2) - *(short *)(lVar2 + 0xb9c8 + uVar7 * 2);
      if (uVar1 <= uVar8) break;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x1f);
    uVar8 = 1;
    if (1 < uVar1) {
      do {
        if (auStack_6a[uVar8] < *(ushort *)(lVar2 + 0xba08)) {
          bVar3 = false;
          break;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar1);
    }
    if (*(int *)(lVar2 + 0xba14) != 0) {
      lVar6 = *(longlong *)(lVar2 + 0xba18);
      if (lVar6 == 0) {
        *(longlong *)(lVar2 + 0xba18) = param_1;
      }
      else {
        while (plVar5 = (longlong *)(lVar6 + 0x60), *plVar5 != 0) {
          lVar6 = *plVar5;
        }
        *plVar5 = param_1;
      }
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(int *)(lVar2 + 0xba14) = *(int *)(lVar2 + 0xba14) + 1;
      TryDeQueueIoList(lVar2);
      *(undefined4 *)(param_1 + 0x78) = 5;
      return 1;
    }
    if (bVar3) {
      lVar6 = *(longlong *)(lVar2 + 0xba18);
      if (lVar6 == 0) {
        *(longlong *)(lVar2 + 0xba18) = param_1;
      }
      else {
        while (plVar5 = (longlong *)(lVar6 + 0x60), *plVar5 != 0) {
          lVar6 = *plVar5;
        }
        *plVar5 = param_1;
      }
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(int *)(lVar2 + 0xba14) = *(int *)(lVar2 + 0xba14) + 1;
      *(undefined4 *)(param_1 + 0x78) = 8;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x78) = 6;
  }
  uVar4 = (**(code **)(*(longlong *)(lVar2 + 0x1320) + 0x38))(lVar2,param_1);
  return uVar4;
}



===== ServiceHostCommandNormalQueue @ 1c0013cf0 =====

void ServiceHostCommandNormalQueue
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  undefined8 uVar4;
  uint *puVar5;
  
  bVar3 = false;
  bVar2 = false;
  while (uVar1 = **(uint **)(param_1 + 0x20), **(uint **)(param_1 + 0x18) != uVar1) {
    puVar5 = (uint *)((ulonglong)
                      *(uint *)(*(longlong *)(param_1 + 8) + 4 +
                               (ulonglong)(uVar1 & -(uint)(uVar1 < *(uint *)(param_1 + 0x28))) * 8)
                     + *(longlong *)(param_1 + 0x620));
    if ((short)puVar5[1] == 700) {
      uVar4 = ProcessAif(param_1,puVar5,param_3,param_4);
      bVar2 = bVar3;
      if ((char)uVar4 != '\0') {
        bVar2 = true;
        bVar3 = true;
      }
    }
    FreeConsumerProducerAif(param_1,puVar5);
  }
  if (bVar2) {
    if (*(char *)(param_1 + 0xe2e4) == '\0') {
      *(undefined4 *)(param_1 + 0x6044) = 0;
      *(undefined1 *)(param_1 + 0x6048) = 1;
      RequestTimer(param_1,8,500000,2);
    }
    else {
      *(undefined1 *)(param_1 + 0xe2e5) = 1;
    }
  }
  return;
}



===== ServiceHostResponseNormalQueue @ 1c0013db4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ServiceHostResponseNormalQueue(longlong param_1)

{
  short *psVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  byte *_Dst;
  longlong lVar5;
  void *pvVar6;
  char cVar7;
  byte bVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  char *pcVar13;
  int *piVar14;
  char *local_res8;
  void *local_res10;
  
  cVar7 = (**(code **)(param_1 + 0x80d8))(param_1,&local_res10,&local_res8);
  pcVar13 = local_res8;
  while (cVar7 != '\0') {
    *(short *)(param_1 + 0xba22) = *(short *)(param_1 + 0xba22) + 1;
    lVar12 = *(longlong *)(pcVar13 + 0x18);
    if ((*(char *)(lVar12 + 5) == '\x04') && (*(char *)(lVar12 + 2) == '\0')) {
      bVar2 = *(byte *)(lVar12 + 0x48);
      if (((bVar2 < 0x2b) && ((0x50000000500U >> ((ulonglong)bVar2 & 0x3f) & 1) != 0)) ||
         ((bVar2 == 0x88 || (bVar2 == 0x8a)))) {
        psVar1 = (short *)(param_1 + 0xd8dc +
                          (ulonglong)*(ushort *)(*(longlong *)(pcVar13 + 0x28) + 0x2c) * 2);
        *psVar1 = *psVar1 + 1;
      }
    }
    local_res8 = pcVar13;
    uVar9 = GetOutstandingIoCnt(param_1);
    if ((*(char *)(param_1 + 0xa925) != '\0') ||
       ((*(char *)(param_1 + 0xa924) != '\0' &&
        (((*(int *)(param_1 + 0xa910) != 0 || (*(int *)(param_1 + 0xa914) != 0)) &&
         ((uint)uVar9 <= *(uint *)(param_1 + 0xa90c))))))) {
      DequeueRawIoReadWriteRequest(param_1,*(char *)(param_1 + 0x617),0xe);
      pcVar13 = local_res8;
    }
    lVar12 = *(longlong *)(pcVar13 + 0x18);
    if (*pcVar13 != '\0') {
      memcpy(*(void **)(pcVar13 + 8),local_res10,(ulonglong)*(ushort *)((longlong)local_res10 + 8));
    }
    iVar4 = *(int *)((longlong)local_res10 + 0x20);
    if ((iVar4 == 0) || (*(char *)(lVar12 + 2) == '\x02')) {
      *(undefined1 *)(lVar12 + 3) = 1;
    }
    else if (((iVar4 == 8) && ((*(uint *)(lVar12 + 0xc) & 0x20) == 0)) &&
            (7 < *(byte *)(lVar12 + 0xb))) {
      _Dst = *(byte **)(lVar12 + 0x20);
      *(undefined4 *)(lVar12 + 0x10) = 0;
      *(undefined2 *)(lVar12 + 3) = 0x284;
      memset(_Dst,0,(ulonglong)*(byte *)(lVar12 + 0xb));
      *_Dst = *_Dst & 0xf0 | 0x70;
      _Dst[2] = _Dst[2] & 0xf3 | 3;
      bVar2 = *(byte *)(lVar12 + 0xb);
      if (bVar2 < 0xe) {
        _Dst[7] = 0;
        *(undefined1 *)(lVar12 + 3) = 4;
      }
      else {
        _Dst[0xc] = 0;
        _Dst[0xd] = 0;
        bVar8 = 6;
        if (0x11 < bVar2) {
          bVar8 = 10;
        }
        _Dst[7] = bVar8;
      }
    }
    else {
      *(undefined1 *)(lVar12 + 3) = 4;
    }
    pvVar6 = local_res10;
    if ((*(char *)(lVar12 + 2) == '\0') && (*(char *)(lVar12 + 5) != '\x04')) {
      PostProcessScsiCommand
                (param_1,lVar12,(longlong)local_res10 + 0x20,
                 *(ushort *)((longlong)local_res10 + 8) - 0x20);
    }
    else if (*(char *)(lVar12 + 2) == '\x02') {
      lVar5 = *(longlong *)(lVar12 + 0x18);
      if ((*(int *)(lVar5 + 0x10) == 0x4201b) || (*(int *)(lVar5 + 0x10) == 0x42264)) {
        uVar11 = *(ushort *)((longlong)local_res10 + 8) - 0x20;
        if (uVar11 < 0x16) {
          if (*(char *)(lVar12 + 3) != '\x01') {
            *(undefined1 *)(lVar12 + 3) = 10;
          }
        }
        else {
          if (((((char)*(uint *)((longlong)local_res10 + 0x24) < '\0') &&
               (uVar10 = *(uint *)((longlong)local_res10 + 0x30), uVar10 + 0x16 <= uVar11)) &&
              (*(void **)(lVar5 + 0x3c) != (void *)0x0)) && (uVar10 != 0)) {
            if (*(byte *)(lVar5 + 0x27) < uVar10) {
              uVar10 = (uint)*(byte *)(lVar5 + 0x27);
            }
            memcpy(*(void **)(lVar5 + 0x3c),(void *)((longlong)local_res10 + 0x34),(ulonglong)uVar10
                  );
          }
          else {
            *(uint *)((longlong)local_res10 + 0x24) =
                 *(uint *)((longlong)local_res10 + 0x24) & 0xffffff7f;
          }
          if (*(char *)(lVar12 + 3) == '\x01') {
            *(undefined1 *)(lVar5 + 0x1f) = *(undefined1 *)((longlong)pvVar6 + 0x24);
            *(undefined1 *)(lVar5 + 0x20) = *(undefined1 *)((longlong)pvVar6 + 0x28);
            uVar11 = *(uint *)((longlong)pvVar6 + 0x2c);
            *(uint *)(lVar5 + 0x2c) = uVar11;
            if (*(int *)(lVar5 + 0x10) == 0x42264) {
              uVar10 = *(uint *)((longlong)pvVar6 + 0x2c);
              if (uVar11 < *(uint *)((longlong)pvVar6 + 0x2c)) {
                uVar10 = uVar11;
              }
              memcpy(*(void **)(lVar5 + 0x34),*(void **)(param_1 + 0x208),(ulonglong)uVar10);
              *(undefined1 *)(param_1 + 0x214) = 0;
            }
          }
        }
      }
    }
    if (iVar4 == 0x48) {
      *(undefined1 *)(lVar12 + 3) = 5;
    }
    if ((*(char **)(local_res8 + 0x58) == (char *)0x0) || (*(char *)(lVar12 + 2) != '\0')) {
      if (*(int *)(local_res8 + 0x70) != 0) {
        *(short *)(param_1 + 0xba26) = *(short *)(param_1 + 0xba26) + 1;
      }
      *(undefined8 *)(lVar12 + 0x38) = *(undefined8 *)(*(longlong *)(lVar12 + 0x38) + 0xa0);
      StorPortNotification(0,param_1,lVar12);
      *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
    }
    else {
      uVar3 = *(undefined1 *)(lVar12 + 3);
      local_res8 = *(char **)(local_res8 + 0x58);
      while( true ) {
        *(undefined8 *)(lVar12 + 0x38) = *(undefined8 *)(*(longlong *)(lVar12 + 0x38) + 0xa0);
        StorPortNotification(0,param_1,lVar12);
        *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
        *(short *)(param_1 + 0xba26) = *(short *)(param_1 + 0xba26) + 1;
        if (local_res8 == (char *)0x0) break;
        lVar12 = *(longlong *)(local_res8 + 0x18);
        *(undefined1 *)(lVar12 + 3) = uVar3;
        local_res8 = *(char **)(local_res8 + 0x58);
      }
    }
    if (((*(char *)(param_1 + 0x805c) != '\0') && ((uint)uVar9 <= *(uint *)(param_1 + 0x8058))) &&
       (*(char *)(param_1 + 0xaad6) == '\0')) {
      uVar11 = 0;
      piVar14 = (int *)(param_1 + 0x19cc);
      do {
        if (*piVar14 == 1) {
          StorPortResumeDevice(param_1,4,(char)uVar11,0);
        }
        uVar11 = uVar11 + 1;
        piVar14 = piVar14 + 10;
      } while (uVar11 < 0xfe);
      uVar11 = 0;
      piVar14 = (int *)(param_1 + 0x417c);
      do {
        if (*piVar14 == 1) {
          StorPortResumeDevice(param_1,0,(char)uVar11,0);
        }
        uVar11 = uVar11 + 1;
        piVar14 = piVar14 + 4;
      } while (uVar11 < 0xfe);
      *(undefined1 *)(param_1 + 0x805c) = 0;
    }
    if (*(char *)(lVar12 + 3) == '\x05') {
      StorPortPauseDevice(param_1,*(undefined1 *)(lVar12 + 5),*(undefined1 *)(lVar12 + 6),0,1);
    }
    cVar7 = (**(code **)(param_1 + 0x80d8))(param_1,&local_res10,&local_res8);
    pcVar13 = local_res8;
  }
  return;
}



===== DpcDequeueRawIoReadWriteRequest @ 1c00141d0 =====

void DpcDequeueRawIoReadWriteRequest(undefined8 param_1,longlong param_2)

{
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28[0] = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  *(undefined1 *)(param_2 + 0xa970) = 0;
  StorPortNotification(0x1003);
  DequeueRawIoReadWriteRequest(param_2,'\0',0);
  StorPortNotification(0x1004,param_2,local_28);
  return;
}



===== ProcessNormalFib @ 1c0014234 =====

void ProcessNormalFib(longlong param_1,char *param_2,char param_3,undefined2 *param_4,
                     ushort *param_5)

{
  short *psVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  void *_Src;
  byte *_Dst;
  byte bVar5;
  ushort uVar6;
  undefined2 uVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  ushort uVar13;
  
  _Src = *(void **)(param_2 + 0x28);
  uVar6 = 0;
  if (*(char *)(param_1 + 0xaad6) == '\0') {
    *(short *)(param_1 + 0xba22) = *(short *)(param_1 + 0xba22) + 1;
    lVar12 = *(longlong *)(param_2 + 0x18);
    if ((*(char *)(lVar12 + 5) == '\x04') && (*(char *)(lVar12 + 2) == '\0')) {
      bVar2 = *(byte *)(lVar12 + 0x48);
      if (((bVar2 < 0x2b) && ((0x50000000500U >> ((ulonglong)bVar2 & 0x3f) & 1) != 0)) ||
         ((bVar2 == 0x88 || (bVar2 == 0x8a)))) {
        psVar1 = (short *)(param_1 + 0xd8dc +
                          (ulonglong)*(ushort *)(*(longlong *)(param_2 + 0x28) + 0x2c) * 2);
        *psVar1 = *psVar1 + 1;
      }
    }
    uVar6 = GetOutstandingIoCnt(param_1);
  }
  else {
    lVar12 = *(longlong *)(param_2 + 0x18);
    uVar7 = 0xffff;
    uVar13 = 0xffff;
    if ((*(char *)(lVar12 + 5) == '\x04') && (*(char *)(lVar12 + 2) == '\0')) {
      bVar2 = *(byte *)(lVar12 + 0x48);
      if (((bVar2 < 0x2b) && ((0x50000000500U >> ((ulonglong)bVar2 & 0x3f) & 1) != 0)) ||
         ((bVar2 == 0x88 || (bVar2 == 0x8a)))) {
        uVar7 = *(undefined2 *)((longlong)_Src + 0x2c);
        uVar13 = (ushort)*(byte *)(lVar12 + 6);
      }
    }
    if (param_4 != (undefined2 *)0x0) {
      *param_4 = uVar7;
    }
    if (param_5 != (ushort *)0x0) {
      *param_5 = uVar13;
    }
  }
  lVar12 = *(longlong *)(param_2 + 0x18);
  if (*param_2 != '\0') {
    memcpy(*(void **)(param_2 + 8),_Src,(ulonglong)*(ushort *)((longlong)_Src + 8));
  }
  piVar9 = (int *)((longlong)_Src + 0x20);
  iVar4 = *piVar9;
  if ((iVar4 == 0) || (iVar4 == 20000)) {
    *(undefined1 *)(lVar12 + 3) = 1;
    if (((iVar4 != 20000) && (*(char *)(lVar12 + 5) == '\0')) &&
       (((*(int *)((longlong)_Src + 0x24) != 1 || (*(int *)((longlong)_Src + 0x28) != 0)) &&
        (*(int *)(param_2 + 0x70) == 2)))) {
      PostProcessScsiCommand(param_1,lVar12,(longlong)piVar9,*(ushort *)((longlong)_Src + 8) - 0x20)
      ;
    }
  }
  else if (*(char *)(lVar12 + 2) == '\x02') {
    *(undefined1 *)(lVar12 + 3) = 1;
  }
  else if (((iVar4 == 8) && ((*(uint *)(lVar12 + 0xc) & 0x20) == 0)) &&
          (7 < *(byte *)(lVar12 + 0xb))) {
    _Dst = *(byte **)(lVar12 + 0x20);
    *(undefined4 *)(lVar12 + 0x10) = 0;
    *(undefined2 *)(lVar12 + 3) = 0x284;
    memset(_Dst,0,(ulonglong)*(byte *)(lVar12 + 0xb));
    *_Dst = *_Dst & 0xf0 | 0x70;
    _Dst[2] = _Dst[2] & 0xf3 | 3;
    bVar2 = *(byte *)(lVar12 + 0xb);
    if (bVar2 < 0xe) {
      _Dst[7] = 0;
      *(undefined1 *)(lVar12 + 3) = 4;
    }
    else {
      _Dst[0xc] = 0;
      _Dst[0xd] = 0;
      bVar5 = 6;
      if (0x11 < bVar2) {
        bVar5 = 10;
      }
      _Dst[7] = bVar5;
    }
  }
  else {
    *(undefined1 *)(lVar12 + 3) = 4;
  }
  if (((*(char *)(lVar12 + 2) == '\0') && (*(char *)(lVar12 + 5) != '\x04')) &&
     (*(int *)(param_2 + 0x70) == 0)) {
    PostProcessScsiCommand(param_1,lVar12,(longlong)piVar9,*(ushort *)((longlong)_Src + 8) - 0x20);
  }
  else if (*(char *)(lVar12 + 2) == '\x02') {
    lVar11 = *(longlong *)(lVar12 + 0x18);
    if ((*(int *)(lVar11 + 0x10) == 0x4201b) || (*(int *)(lVar11 + 0x10) == 0x42264)) {
      uVar10 = *(ushort *)((longlong)_Src + 8) - 0x20;
      if (uVar10 < 0x16) {
        if (*(char *)(lVar12 + 3) != '\x01') {
          *(undefined1 *)(lVar12 + 3) = 10;
        }
      }
      else {
        if (((((char)*(uint *)((longlong)_Src + 0x24) < '\0') &&
             (uVar8 = *(uint *)((longlong)_Src + 0x30), uVar8 + 0x16 <= uVar10)) &&
            (*(void **)(lVar11 + 0x3c) != (void *)0x0)) && (uVar8 != 0)) {
          if (*(byte *)(lVar11 + 0x27) < uVar8) {
            uVar8 = (uint)*(byte *)(lVar11 + 0x27);
          }
          memcpy(*(void **)(lVar11 + 0x3c),(void *)((longlong)_Src + 0x34),(ulonglong)uVar8);
        }
        else {
          *(uint *)((longlong)_Src + 0x24) = *(uint *)((longlong)_Src + 0x24) & 0xffffff7f;
        }
        if (*(char *)(lVar12 + 3) == '\x01') {
          *(undefined1 *)(lVar11 + 0x1f) = *(undefined1 *)((longlong)_Src + 0x24);
          *(undefined1 *)(lVar11 + 0x20) = *(undefined1 *)((longlong)_Src + 0x28);
          uVar10 = *(uint *)((longlong)_Src + 0x2c);
          *(uint *)(lVar11 + 0x2c) = uVar10;
          if (*(int *)(lVar11 + 0x10) == 0x42264) {
            if (*(int *)((longlong)_Src + 0x24) == 1) {
              uVar8 = *(uint *)((longlong)_Src + 0x2c);
              if (uVar10 < *(uint *)((longlong)_Src + 0x2c)) {
                uVar8 = uVar10;
              }
              memcpy(*(void **)(lVar11 + 0x34),*(void **)(param_1 + 0x208),(ulonglong)uVar8);
            }
            *(undefined1 *)(param_1 + 0x214) = 0;
          }
        }
      }
    }
  }
  if (iVar4 == 0x48) {
    *(undefined1 *)(lVar12 + 3) = 5;
  }
  if (param_3 != '\0') {
    *(undefined4 *)(param_1 + 0xdeac + (ulonglong)*(byte *)(lVar12 + 6) * 4) = 0;
  }
  lVar11 = *(longlong *)(param_2 + 0x58);
  if ((lVar11 == 0) || (*(char *)(lVar12 + 2) != '\0')) {
    if (*(int *)(param_2 + 0x70) != 0) {
      *(short *)(param_1 + 0xba26) = *(short *)(param_1 + 0xba26) + 1;
    }
    *(undefined8 *)(lVar12 + 0x38) = *(undefined8 *)(*(longlong *)(lVar12 + 0x38) + 0xa0);
    StorPortNotification(0,param_1,lVar12);
    *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
  }
  else {
    uVar3 = *(undefined1 *)(lVar12 + 3);
    while( true ) {
      *(undefined8 *)(lVar12 + 0x38) = *(undefined8 *)(*(longlong *)(lVar12 + 0x38) + 0xa0);
      StorPortNotification(0,param_1,lVar12);
      *(short *)(param_1 + 0xba2a) = *(short *)(param_1 + 0xba2a) + 1;
      *(short *)(param_1 + 0xba26) = *(short *)(param_1 + 0xba26) + 1;
      if (lVar11 == 0) break;
      lVar12 = *(longlong *)(lVar11 + 0x18);
      *(undefined1 *)(lVar12 + 3) = uVar3;
      lVar11 = *(longlong *)(lVar11 + 0x58);
    }
  }
  if (*(char *)(param_1 + 0x805c) != '\0') {
    if (((uint)uVar6 <= *(uint *)(param_1 + 0x8058)) && (*(char *)(param_1 + 0xaad6) == '\0')) {
      uVar10 = 0;
      piVar9 = (int *)(param_1 + 0x19cc);
      do {
        if (*piVar9 == 1) {
          StorPortResumeDevice(param_1,4,(char)uVar10,0);
        }
        uVar10 = uVar10 + 1;
        piVar9 = piVar9 + 10;
      } while (uVar10 < 0xfe);
      uVar10 = 0;
      piVar9 = (int *)(param_1 + 0x417c);
      do {
        if (*piVar9 == 1) {
          StorPortResumeDevice(param_1,0,(char)uVar10,0);
        }
        uVar10 = uVar10 + 1;
        piVar9 = piVar9 + 4;
      } while (uVar10 < 0xfe);
      *(undefined1 *)(param_1 + 0x805c) = 0;
    }
    if (((*(char *)(param_1 + 0x805c) != '\0') && ((uint)uVar6 <= *(uint *)(param_1 + 0xba10))) &&
       (*(char *)(param_1 + 0xaad6) != '\0')) {
      uVar10 = 0;
      piVar9 = (int *)(param_1 + 0x19cc);
      do {
        if (*piVar9 == 1) {
          StorPortResumeDevice(param_1,4,(char)uVar10,0);
        }
        uVar10 = uVar10 + 1;
        piVar9 = piVar9 + 10;
      } while (uVar10 < 0xfe);
      uVar10 = 0;
      piVar9 = (int *)(param_1 + 0x417c);
      do {
        if (*piVar9 == 1) {
          StorPortResumeDevice(param_1,0,(char)uVar10,0);
        }
        uVar10 = uVar10 + 1;
        piVar9 = piVar9 + 4;
      } while (uVar10 < 0xfe);
      *(undefined1 *)(param_1 + 0x805c) = 0;
    }
  }
  if (*(char *)(lVar12 + 3) == '\x05') {
    StorPortPauseDevice(param_1,*(undefined1 *)(lVar12 + 5),*(undefined1 *)(lVar12 + 6),0,1);
  }
  return;
}



===== ServiceInternalAifQueue @ 1c0014740 =====

longlong ServiceInternalAifQueue(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  int iVar6;
  undefined8 in_RAX;
  uint7 uVar8;
  longlong lVar7;
  
  uVar8 = (uint7)((ulonglong)in_RAX >> 8);
  lVar7 = (ulonglong)uVar8 << 8;
  if ((*(int *)(param_1 + 0x1d0) == 2) ||
     (plVar1 = (longlong *)(param_1 + 0x680), (longlong *)*plVar1 == plVar1)) {
    lVar7 = (ulonglong)uVar8 << 8;
  }
  else {
    do {
      uVar2 = *(uint *)(param_1 + 0x19b8);
      if (uVar2 == *(uint *)(param_1 + 0x19bc)) {
        return lVar7;
      }
      plVar3 = (longlong *)*plVar1;
      lVar7 = *(longlong *)(param_1 + 0x19b0);
      plVar4 = (longlong *)plVar3[1];
      lVar5 = *plVar3;
      *plVar4 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar4;
      if ((char)plVar3[-6] != '\0') {
        memcpy((void *)plVar3[-5],(void *)((ulonglong)uVar2 * 0x200 + lVar7),0x200);
      }
      iVar6 = *(int *)(param_1 + 0x19b8) + 1;
      if (iVar6 == *(int *)(param_1 + 0x19ac)) {
        iVar6 = 0;
      }
      *(int *)(param_1 + 0x19b8) = iVar6;
      lVar7 = plVar3[-3];
      *(undefined1 *)(lVar7 + 3) = 1;
      lVar7 = CONCAT71((int7)((ulonglong)lVar7 >> 8),1);
    } while ((longlong *)*plVar1 != plVar1);
  }
  return lVar7;
}



===== ProcessWmi @ 1c00147f4 =====

undefined8 ProcessWmi(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  uint *puVar4;
  longlong *plVar5;
  char cVar6;
  uint local_res8 [2];
  int local_res10 [2];
  
  lVar3 = *(longlong *)(param_2 + 0x38);
  local_res8[0] = 0;
  *(longlong *)(lVar3 + 0x6d8) = param_2;
  puVar4 = *(uint **)(param_2 + 0x18);
  uVar2 = *(uint *)(param_2 + 0x10);
  plVar5 = *(longlong **)(param_2 + 0x20);
  bVar1 = *(byte *)(param_2 + 4);
  *(undefined4 *)(lVar3 + 0x6f4) = 0;
  if (bVar1 < 10) {
    *(uint *)(lVar3 + 0x6e0) = uVar2;
    *(byte *)(lVar3 + 0x6f0) = bVar1;
    *(uint **)(lVar3 + 0x6e8) = puVar4;
    cVar6 = ScsiWmipProcessRequest
                      ((uint *)(param_1 + 0x5180),bVar1,param_1,(longlong *)(lVar3 + 0x6d8),plVar5,
                       uVar2,puVar4,local_res8,local_res10);
    if (local_res10[0] == 1) {
      *(char *)(lVar3 + 0x6f1) = cVar6;
      if (cVar6 != '\x01') {
        local_res8[0] = 0;
      }
      *(uint *)(lVar3 + 0x6f4) = local_res8[0];
    }
    if (cVar6 == '\0') {
      return 0;
    }
  }
  else {
    *(undefined1 *)(lVar3 + 0x6f1) = 4;
  }
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(lVar3 + 0x6f1);
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(lVar3 + 0x6f4);
  return 1;
}



===== InitializeWmiInterface @ 1c00148b8 =====

void InitializeWmiInterface(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x51e8) = 0;
  *(undefined4 *)(param_1 + 0x51f8) = 0;
  *(undefined8 *)(param_1 + 0x51c0) = &gAdapterGuid;
  *(undefined4 *)(param_1 + 0x51cc) = 1;
  *(undefined **)(param_1 + 0x51d0) = &gIoChannelGuid;
  *(undefined **)(param_1 + 0x51e0) = &gDiskArrayGuid;
  *(undefined **)(param_1 + 0x51f0) = &gPhysicalDiskGuid;
  *(undefined4 *)(param_1 + 0x51c8) = 1;
  *(undefined **)(param_1 + 0x5200) = &gAdapterMethodGuid;
  *(undefined4 *)(param_1 + 0x51dc) = 1;
  *(undefined4 *)(param_1 + 0x51d8) = 5;
  *(undefined4 *)(param_1 + 0x51ec) = 1;
  *(undefined4 *)(param_1 + 0x51fc) = 1;
  *(undefined4 *)(param_1 + 0x520c) = 1;
  *(undefined4 *)(param_1 + 21000) = 2;
  *(undefined8 **)(param_1 + 0x5188) = (undefined8 *)(param_1 + 0x51c0);
  *(code **)(param_1 + 0x5190) = HwScsiWmiQueryReginfo;
  *(code **)(param_1 + 0x5198) = HwScsiWmiFunctionControl;
  *(code **)(param_1 + 0x51a0) = HwScsiWmiSetDataItem;
  *(code **)(param_1 + 0x51a8) = HwScsiWmiSetDataItem;
  *(code **)(param_1 + 0x51b0) = HwScsiWmiExecuteMethod;
  *(code **)(param_1 + 0x51b8) = HwScsiWmiFunctionControl;
  *(undefined4 *)(param_1 + 0x5180) = 5;
  return;
}



===== HwScsiWmiExecuteMethod @ 1c00149c0 =====

ulonglong HwScsiWmiExecuteMethod
                    (longlong param_1,ulonglong *param_2,int param_3,undefined8 param_4,int param_5,
                    undefined8 param_6,undefined8 param_7,char *param_8)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = *param_2;
  if (((*(byte *)(uVar2 + 9) & 1) != 0) && (param_3 == 0)) {
    uVar1 = param_5 - 1;
    uVar2 = (ulonglong)uVar1;
    if (uVar1 == 0) {
      param_8[2] = '\x05';
      param_8[3] = '\0';
      param_8[4] = '0';
      param_8[5] = '}';
      *param_8 = '\a';
      *(undefined2 *)(param_8 + 10) = *(undefined2 *)(param_1 + 0x1414);
      param_8[6] = *(char *)(param_1 + 0x1413);
      uVar2 = 0;
      *(ushort *)(param_8 + 8) = (ushort)*(byte *)(param_1 + 0x1412);
    }
    else if (uVar1 == 1) {
      uVar2 = CONCAT71((int7)((ulonglong)param_8 >> 8),*param_8 == '\0');
      *(bool *)(param_1 + 0xba2c) = *param_8 == '\0';
    }
  }
  *(undefined4 *)((longlong)param_2 + 0x1c) = 0;
  *(undefined1 *)((longlong)param_2 + 0x19) = 4;
  return uVar2 & 0xffffffffffffff00;
}



===== HwScsiWmiFunctionControl @ 1c0014a30 =====

undefined1 HwScsiWmiFunctionControl(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(undefined1 *)(param_2 + 0x19) = 4;
  return 0;
}



===== HwScsiWmiQueryReginfo @ 1c0014a40 =====

longlong HwScsiWmiQueryReginfo(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = L"MofResource";
  return 0x1c001b201;
}



===== HwScsiWmiSetDataItem @ 1c0014a50 =====

undefined1 HwScsiWmiSetDataItem(void)

{
  return 0;
}



===== __report_gsfailure @ 1c0014a60 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __report_rangecheckfailure @ 1c0014a68 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ScsiWmipProcessRequest @ 1c0014a70 =====

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
          goto LAB_1c0014b43;
          break;
        }
        uVar15 = (int)uVar18 + 1;
        uVar18 = (ulonglong)uVar15;
        plVar8 = plVar8 + 2;
      } while (uVar15 < *param_1);
    }
    *param_8 = 0;
    cVar4 = '\x04';
    goto LAB_1c0014eb5;
  }
LAB_1c0014b43:
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_1c0014bc3;
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
              goto LAB_1c0014ed8;
            }
            goto LAB_1c0014eed;
          }
LAB_1c0014bc3:
          cVar4 = '\x04';
          goto LAB_1c0014ef0;
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
LAB_1c0014ca6:
      cVar4 = (*pcVar6)(param_3,param_4,uVar18,uVar5,uVar15,puVar13,iVar11,lVar12);
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar19 = 0;
      uVar17 = 0;
      goto LAB_1c0014edd;
    }
  }
  else if (param_2 == 6) {
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar17 = 1;
LAB_1c0014ed8:
      uVar19 = 1;
LAB_1c0014edd:
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
            goto LAB_1c0014ca6;
          }
        }
        goto LAB_1c0014bc3;
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
          goto LAB_1c0014ea6;
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
LAB_1c0014ea6:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_1c0014eb5:
      *param_9 = 1;
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar19 = 0;
      uVar17 = 1;
      goto LAB_1c0014edd;
    }
  }
LAB_1c0014eed:
  cVar4 = '\x01';
LAB_1c0014ef0:
  *param_9 = 1;
  return cVar4;
}



===== __security_check_cookie @ 1c0014f30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __GSHandlerCheck @ 1c0014f50 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0014f70 =====

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



===== _guard_dispatch_icall @ 1c0014ff0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0014ff0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memcpy @ 1c0015000 =====

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
        if (uVar12 == 0) goto LAB_1c00151b7;
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
LAB_1c00151b7:
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
      if (uVar12 == 0) goto LAB_1c0015012;
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
LAB_1c0015012:
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



===== memset @ 1c0015340 =====

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
      if (uVar5 == 0) goto LAB_1c0015400;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_1c00153fd_caseD_2;
      case 3:
        goto switchD_1c00153fd_caseD_3;
      case 4:
        goto switchD_1c00153fd_caseD_4;
      case 5:
        goto switchD_1c00153fd_caseD_5;
      case 6:
        goto switchD_1c00153fd_caseD_6;
      case 7:
        goto switchD_1c00153fd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_1c0015400:
        *puVar3 = uVar4;
switchD_1c00153fd_caseD_7:
        puVar3[1] = uVar4;
switchD_1c00153fd_caseD_6:
        puVar3[2] = uVar4;
switchD_1c00153fd_caseD_5:
        puVar3[3] = uVar4;
switchD_1c00153fd_caseD_4:
        puVar3[4] = uVar4;
switchD_1c00153fd_caseD_3:
        puVar3[5] = uVar4;
switchD_1c00153fd_caseD_2:
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



===== entry @ 1c0020000 =====

undefined4 entry(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
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
  
  __security_init_cookie();
  if (DAT_1c001d940 == '\0') {
    DAT_1c001d940 = '\x01';
    gDriverObject = param_1;
  }
  memset(&local_d8,0,0xd0);
  local_d8 = 0xd0;
  local_d0 = HwInitializeAdapter;
  local_d4 = 5;
  local_c8 = StartIo;
  local_98 = 0xe2f0;
  local_c0 = HandleInterrupt;
  local_90 = 0x726;
  local_b8 = FindAdapter;
  local_8c = 3;
  local_b0 = ResetAdapter;
  local_60 = AdapterControl;
  local_58 = BuildIo;
  local_80 = 0x1010102;
  local_7c = 1;
  uVar1 = StorPortInitialize(param_1,param_2,&local_d8,0);
  StorPortDebugPrint(0,"%s Driver entry rtnval = %x\n",&s_Arcsas,uVar1);
  return uVar1;
}



===== __security_init_cookie @ 1c002010c =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  byte *pbVar4;
  char in_DL;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar2 = (code *)swi(0x29);
    pbVar4 = (byte *)(*pcVar2)(6);
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
    bVar1 = *pbVar4;
    *pbVar4 = *pbVar4 + bVar3;
    *pbVar4 = *pbVar4 + bVar3 + CARRY1(bVar1,bVar3);
    pbVar4[0x10] = pbVar4[0x10] + in_DL;
    *pbVar4 = *pbVar4 + bVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


